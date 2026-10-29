using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Globalization;
using System.Runtime.InteropServices;
using System.Threading;

// Own initialized Win32 objects only. Source addresses are dictionary identities;
// no caller-provided integer can become the pointer passed to a Win32 primitive.
public sealed class OriginalOwnedCriticalSections : IDisposable {
 [StructLayout(LayoutKind.Sequential)] struct NativeCriticalSection {
  public IntPtr DebugInfo; public int LockCount,RecursionCount;
  public IntPtr OwningThread,LockSemaphore,SpinCount;
 }
 [DllImport("kernel32.dll")] static extern void InitializeCriticalSection(IntPtr p);
 [DllImport("kernel32.dll")] static extern void EnterCriticalSection(IntPtr p);
 [DllImport("kernel32.dll")] static extern void LeaveCriticalSection(IntPtr p);
 [DllImport("kernel32.dll")] static extern void DeleteCriticalSection(IntPtr p);
 [DllImport("kernel32.dll")] static extern uint GetCurrentThreadId();
 [DllImport("kernel32.dll")] static extern bool TryEnterCriticalSection(IntPtr p);
 sealed class Binding {
  public readonly object Gate=new object(); public IntPtr Pointer;
  public string Key,Instance,Source,Scope; public uint Owner; public int Depth,InFlight;
  public bool Deleted,Faulted;
 }
 sealed class Ticket {
  public long Id; public string Api,Actor; public Binding Binding;
  public readonly ManualResetEventSlim Started=new ManualResetEventSlim(false),Done=new ManualResetEventSlim(false);
  public Dictionary<string,object> Result;
 }
 sealed class Actor {
  public readonly BlockingCollection<Ticket> Queue=new BlockingCollection<Ticket>();
  public Thread Thread;
 }
 readonly object gate=new object();
 readonly Dictionary<string,Binding> bindings=new Dictionary<string,Binding>();
 readonly Dictionary<string,Actor> actors=new Dictionary<string,Actor>();
 readonly Dictionary<long,Ticket> tickets=new Dictionary<long,Ticket>();
 long sequence; bool disposed;
 static Dictionary<string,object> D(params object[] pairs) {
  var d=new Dictionary<string,object>();for(int i=0;i<pairs.Length;i+=2)d[(string)pairs[i]]=pairs[i+1];return d;
 }
 static string Identity(string source) {
  if(source==null || source.Length!=10 || !source.StartsWith("0x",StringComparison.Ordinal))throw new ArgumentException("Explicit 32-bit source identity required");
  uint value=UInt32.Parse(source.Substring(2),NumberStyles.HexNumber,CultureInfo.InvariantCulture);
  if(value==0)throw new ArgumentException("Null source identity is not a lock");
  return "0x"+value.ToString("x8");
 }
 static void Name(string s) {if(String.IsNullOrWhiteSpace(s)||s.Length>128)throw new ArgumentException("Explicit bounded scope/actor is required");}
 Binding Get(string key) {
  Binding b;if(disposed || !bindings.TryGetValue(key,out b) || b.Deleted || b.Faulted)throw new InvalidOperationException("Unknown/deleted/faulted own lock binding");return b;
 }
 public Dictionary<string,object> Create(string scope,string source) {
  Name(scope);source=Identity(source);string key=scope+":"+source;
  lock(gate) {
   if(disposed || bindings.ContainsKey(key))throw new InvalidOperationException("Binding already exists; explicit new lifetime scope required for reused source addresses");
   var b=new Binding();b.Scope=scope;b.Source=source;b.Key=key;b.Instance=Guid.NewGuid().ToString("N");
   b.Pointer=Marshal.AllocHGlobal(Marshal.SizeOf(typeof(NativeCriticalSection)));
   try {InitializeCriticalSection(b.Pointer);}catch {Marshal.FreeHGlobal(b.Pointer);throw;}
   bindings.Add(key,b);
   return D("ok",true,"key",key,"instance",b.Instance,"source_identity",source,"scope",scope,"own_initialized",true,"pointer_size",IntPtr.Size,"structure_size",Marshal.SizeOf(typeof(NativeCriticalSection)),"native_vcl_verified",false);
  }
 }
 public long Begin(string key,string actorName,string api) {
  Name(actorName);if(api!="EnterCriticalSection" && api!="LeaveCriticalSection")throw new ArgumentException("Unported own-lock operation");
  lock(gate) {
   Binding b=Get(key);Actor actor;
   if(!actors.TryGetValue(actorName,out actor)) {
    if(actors.Count>=32)throw new InvalidOperationException("Actor bound exceeded");
    actor=new Actor();Actor captured=actor;
    actor.Thread=new Thread(()=>Work(captured));actor.Thread.IsBackground=true;actor.Thread.Name="Own-CS-"+actorName;actors.Add(actorName,actor);actor.Thread.Start();
   }
   var t=new Ticket();t.Id=++sequence;t.Api=api;t.Actor=actorName;t.Binding=b;
   lock(b.Gate) {if(b.Deleted || b.Faulted)throw new InvalidOperationException("Own lock unavailable");b.InFlight++;}
   tickets.Add(t.Id,t);actor.Queue.Add(t);return t.Id;
  }
 }
 void Work(Actor actor) {
  foreach(Ticket t in actor.Queue.GetConsumingEnumerable()) {
   Binding b=t.Binding;uint thread=GetCurrentThreadId();t.Started.Set();
   try {
    if(t.Api=="EnterCriticalSection") {
     EnterCriticalSection(b.Pointer); // Actual potentially blocking, recursive Win32 call.
     lock(b.Gate) {
      if(b.Owner!=0 && b.Owner!=thread)throw new InvalidOperationException("Native mutual exclusion violated tracked ownership");
      b.Owner=thread;b.Depth++;t.Result=D("ok",true,"api",t.Api,"key",b.Key,"instance",b.Instance,"actor",t.Actor,"worker_thread",thread,"depth",b.Depth,"primitive_executed",true);
     }
    }else {
     lock(b.Gate) {
      if(b.Owner!=thread || b.Depth<=0)throw new InvalidOperationException("Rejected wrong-thread/unbalanced leave before any Win32 operation");
      LeaveCriticalSection(b.Pointer);b.Depth--;if(b.Depth==0)b.Owner=0;
      t.Result=D("ok",true,"api",t.Api,"key",b.Key,"instance",b.Instance,"actor",t.Actor,"worker_thread",thread,"depth",b.Depth,"primitive_executed",true);
     }
    }
   }catch(Exception e) {
    // No inferred success, silent repair or replay after an actual native failure.
    if(!(e is InvalidOperationException))lock(b.Gate) {b.Faulted=true;}
    t.Result=D("ok",false,"error",e.Message,"api",t.Api,"key",b.Key,"native_vcl_verified",false);
   }finally {lock(b.Gate) {b.InFlight--;}t.Done.Set();}
  }
 }
 public Dictionary<string,object> Poll(long id,int waitMilliseconds) {
  if(waitMilliseconds<0 || waitMilliseconds>5000)throw new ArgumentException("Wait must be bounded to 0..5000 ms");
  Ticket t;lock(gate) {if(!tickets.TryGetValue(id,out t))throw new ArgumentException("Unknown own-lock ticket");}
  bool done=t.Done.Wait(waitMilliseconds);
  return D("ok",true,"ticket",id,"started",t.Started.IsSet,"complete",done,"result",done?t.Result:null,"native_vcl_verified",false);
 }
 public Dictionary<string,object> Delete(string key) {
  lock(gate) {Binding b=Get(key);lock(b.Gate) {
   if(b.Depth!=0 || b.InFlight!=0)throw new InvalidOperationException("Cannot delete a held, queued or waiting own critical section");
   DeleteCriticalSection(b.Pointer);Marshal.FreeHGlobal(b.Pointer);b.Pointer=IntPtr.Zero;b.Deleted=true;
   return D("ok",true,"key",key,"instance",b.Instance,"primitive_executed",true,"native_vcl_verified",false);
  }}
 }
 public void Dispose() {
  lock(gate) {
   if(disposed)return;
   foreach(Binding b in bindings.Values)lock(b.Gate) {if(!b.Deleted && (b.Depth!=0 || b.InFlight!=0 || b.Faulted))throw new InvalidOperationException("Explicit drain/release required; own held or faulted locks cannot be silently deleted");}
   foreach(Binding b in bindings.Values)if(!b.Deleted){DeleteCriticalSection(b.Pointer);Marshal.FreeHGlobal(b.Pointer);b.Pointer=IntPtr.Zero;b.Deleted=true;}
   foreach(Actor a in actors.Values)a.Queue.CompleteAdding();disposed=true;
  }
  foreach(Actor a in actors.Values) {if(!a.Thread.Join(5000))throw new InvalidOperationException("Own actor shutdown remains unresolved");a.Queue.Dispose();}
  foreach(Ticket t in tickets.Values){t.Started.Dispose();t.Done.Dispose();}
 }
 static Dictionary<string,object> Await(OriginalOwnedCriticalSections h,long id) {
  var p=h.Poll(id,5000);if(!(bool)p["complete"])throw new Exception("Verifier timed out; no result inferred");return (Dictionary<string,object>)p["result"];
 }
 static void Require(bool ok,string message) {if(!ok)throw new Exception(message);}
 // Independent direct Win32 recursion/exclusion reference on a fresh own object.
 static Dictionary<string,object> DirectReference() {
  IntPtr p=Marshal.AllocHGlobal(Marshal.SizeOf(typeof(NativeCriticalSection)));InitializeCriticalSection(p);int depth=0;
  try {
   EnterCriticalSection(p);depth++;EnterCriticalSection(p);depth++;
   bool? first=null,second=null,third=null;Action<int> attempt=(which)=> {
    bool result=false;Thread t=new Thread(()=>{result=TryEnterCriticalSection(p);if(result)LeaveCriticalSection(p);});t.Start();if(!t.Join(5000))throw new Exception("Direct native contender timed out");
    if(which==0)first=result;else if(which==1)second=result;else third=result;
   };
   attempt(0);LeaveCriticalSection(p);depth--;attempt(1);LeaveCriticalSection(p);depth--;attempt(2);
   Require(first==false && second==false && third==true,"Direct Win32 recursive mutual exclusion failed");
   return D("recursive_depth",2,"contender_while_twice_owned",first,"contender_after_one_leave",second,"contender_after_final_leave",third);
  }finally {while(depth-->0)LeaveCriticalSection(p);DeleteCriticalSection(p);Marshal.FreeHGlobal(p);}
 }
 public static Dictionary<string,object> Verify() {
  var direct=DirectReference();var h=new OriginalOwnedCriticalSections();string key=(string)h.Create("verifier-lifetime-1","0x0d9911ec")["key"];
  var observations=new List<object>();
  var a1=Await(h,h.Begin(key,"source-ui","EnterCriticalSection"));var a2=Await(h,h.Begin(key,"source-ui","EnterCriticalSection"));observations.Add(a1);observations.Add(a2);
  Require((bool)a1["ok"] && (bool)a2["ok"] && (int)a2["depth"]==2 && a1["worker_thread"].Equals(a2["worker_thread"]),"Backend recursion/OS-thread identity failed");
  // A wrong actor may not cause native undefined behavior by leaving this lock.
  var bad=Await(h,h.Begin(key,"other-thread","LeaveCriticalSection"));Require(!(bool)bad["ok"],"Wrong-thread leave not rejected");observations.Add(bad);
  long pending=h.Begin(key,"other-thread","EnterCriticalSection");
  DateTime limit=DateTime.UtcNow.AddSeconds(5);Dictionary<string,object> waiting;
  do {waiting=h.Poll(pending,1);}while(!(bool)waiting["started"] && DateTime.UtcNow<limit);
  Require((bool)waiting["started"] && !(bool)waiting["complete"],"Native contender was not observed waiting");
  bool deleteHeldRejected=false;try{h.Delete(key);}catch(InvalidOperationException){deleteHeldRejected=true;}Require(deleteHeldRejected,"Held/waiting lock deletion accepted");
  observations.Add(Await(h,h.Begin(key,"source-ui","LeaveCriticalSection")));Require(!(bool)h.Poll(pending,20)["complete"],"Contender entered before recursive debt was released");
  observations.Add(Await(h,h.Begin(key,"source-ui","LeaveCriticalSection")));var entered=Await(h,pending);Require((bool)entered["ok"],"Native waiter did not acquire after release");observations.Add(entered);
  observations.Add(Await(h,h.Begin(key,"other-thread","LeaveCriticalSection")));observations.Add(h.Delete(key));
  bool reusedRejected=false;try{h.Create("verifier-lifetime-1","0x0d9911ec");}catch(InvalidOperationException){reusedRejected=true;}Require(reusedRejected,"Stale source lifetime silently rebound");
  string next=(string)h.Create("verifier-lifetime-2","0x0d9911ec")["key"];observations.Add(h.Delete(next));h.Dispose();
  return D("ok",true,"format","chemlab-owned-win32-critical-sections-verification-v1","direct_native_reference",direct,"operations",observations,"blocked_contender_observed",true,"held_delete_rejected",deleteHeldRejected,"stale_lifetime_rebind_rejected",reusedRejected,"target_calls",false,"target_writes",false,"native_vcl_verified",false,"scope","Fresh owned Win32 objects and explicit worker-thread scenarios only; not captured target-lock state");
 }
}
