#!/usr/bin/env python3
"""Recover Delphi binary form resources without changing originals (stdlib only)."""
from pathlib import Path
import argparse, hashlib, json, struct, math


def sha(b): return hashlib.sha256(b).hexdigest()
def decode(b):
    try: return b.decode('gbk')
    except UnicodeDecodeError: return b.decode('cp1252')

class Reader:
    def __init__(self,b): self.b=b; self.p=0
    def take(self,n):
        if n<0 or self.p+n>len(self.b): raise ValueError(f'truncated at {self.p}, requesting {n}')
        b=self.b[self.p:self.p+n];self.p+=n;return b
    def num(self,fmt): return struct.unpack('<'+fmt,self.take(struct.calcsize('<'+fmt)))[0]
    def short(self): return decode(self.take(self.num('B')))
    def props(self):
        props=[]
        while True:
            name=self.short()
            if not name:return props
            props.append({'name':name,'value':self.value()})
    def value(self):
        start=self.p;t=self.num('B'); v={'type':t}
        if t==0: v['value']=None
        elif t==1:
            a=[]
            while self.b[self.p]!=0:a.append(self.value())
            self.p+=1;v['value']=a
        elif t in (2,3,4,19):v['value']=self.num({2:'b',3:'h',4:'i',19:'q'}[t])
        elif t==5:
            raw=self.take(10);mant,exp=struct.unpack('<QH',raw);e=exp&0x7fff
            val=math.ldexp(mant/2**63,e-16383) if 0<e<32767 else (0.0 if not mant else float('nan'))
            v.update(value=-val if exp&0x8000 else val,raw_hex=raw.hex())
        elif t in (6,7):v['value']=self.short()
        elif t in (8,9):v['value']=t==9
        elif t==10:
            raw=self.take(self.num('I'));v.update(value=raw.hex().upper(),size=len(raw),sha256=sha(raw))
        elif t==11:
            a=[]
            while True:
                s=self.short()
                if not s:break
                a.append(s)
            v['value']=a
        elif t in (12,20):
            raw=self.take(self.num('I'));v['value']=raw.decode('utf8') if t==20 else decode(raw)
        elif t==13:v['value']=None
        elif t==14:
            a=[]
            while self.b[self.p]!=0:
                item={}
                if self.b[self.p] in (2,3,4): item['order']=self.value()['value']
                if self.num('B')!=1:raise ValueError(f'collection item tag at {self.p-1}')
                item['properties']=self.props();a.append(item)
            self.p+=1;v['value']=a
        elif t in (15,17,21):v['value']=self.num('f' if t==15 else 'd')
        elif t==16:v['value']=self.num('q')/10000
        elif t==18:v['value']=self.take(self.num('I')*2).decode('utf-16le')
        else:raise ValueError(f'unknown value tag {t} at {start}')
        v['offset']=start;return v
    def obj(self):
        start=self.p;flags=0;childpos=None
        if self.b[self.p]&0xf0==0xf0:
            flags=self.num('B')&15
            if flags&2:childpos=self.value()['value']
        cls=self.short();name=self.short()
        o={'class':cls,'name':name,'flags':flags,'offset':start,'properties':self.props(),'children':[]}
        if childpos is not None:o['child_position']=childpos
        while self.b[self.p]!=0:o['children'].append(self.obj())
        self.p+=1;return o


def quoted(s):
    # ASCII-safe Delphi literals retain decoded Chinese using #codepoint notation.
    chunks=[];buf=''
    for c in s:
        if 32<=ord(c)<=126:buf+=c.replace("'","''")
        else:
            if buf:chunks.append("'"+buf+"'");buf=''
            chunks.append('#'+str(ord(c)))
    if buf:chunks.append("'"+buf+"'")
    return ''.join(chunks) or "''"
def valtext(v,indent):
    t=v['type'];x=v['value']
    if t in (6,12,18,20):return quoted(x)
    if t==7:return x
    if t in (8,9):return str(x)
    if t in (0,13):return 'nil'
    if t==11:return '['+', '.join(x)+']'
    if t==10:
        return '{\n'+'\n'.join(indent+'  '+x[i:i+64] for i in range(0,len(x),64))+'}'
    if t==1:return '(\n'+'\n'.join(indent+'  '+valtext(y,indent+'  ') for y in x)+'\n'+indent+')'
    if t==14:
        lines=['<']
        for item in x:
            lines.append(indent+'  item')
            for p in item['properties']:lines.append(indent+'    '+p['name']+' = '+valtext(p['value'],indent+'    '))
            lines.append(indent+'  end')
        lines[-1]+='>' if x else ''
        if not x:return '<>'
        return '\n'.join(lines)
    return repr(x)
def render(o,level=0):
    ind='  '*level;kind='inherited' if o['flags']&1 else 'inline' if o['flags']&4 else 'object'
    s=[f"{ind}{kind} {o['name']}: {o['class']}"]
    for p in o['properties']:s.append(ind+'  '+p['name']+' = '+valtext(p['value'],ind+'  '))
    for c in o['children']:s.extend(render(c,level+1))
    s.append(ind+'end');return s

def resources(b):
    pe=struct.unpack_from('<I',b,0x3c)[0];n=struct.unpack_from('<H',b,pe+6)[0];os=struct.unpack_from('<H',b,pe+20)[0];op=pe+24
    magic=struct.unpack_from('<H',b,op)[0];dd=op+(96 if magic==0x10b else 112)
    rrva,rsize=struct.unpack_from('<II',b,dd+16);sections=[]
    for i in range(n):
        q=op+os+i*40;vs,va,rs,rp=struct.unpack_from('<IIII',b,q+8);sections.append((va,max(vs,rs),rp))
    def off(rva):
        for va,size,rp in sections:
            if va<=rva<va+size:return rp+rva-va
        raise ValueError(f'RVA outside sections {rva:x}')
    root=off(rrva)
    def walk(rel,path):
        q=root+rel;ns,ni=struct.unpack_from('<HH',b,q+12)
        for i in range(ns+ni):
            ident,dest=struct.unpack_from('<II',b,q+16+i*8)
            if ident&0x80000000:
                p=root+(ident&0x7fffffff);size=struct.unpack_from('<H',b,p)[0];name=b[p+2:p+2+size*2].decode('utf16')
            else:name=ident
            if dest&0x80000000:yield from walk(dest&0x7fffffff,path+[name])
            else:
                rva,size,cp,res=struct.unpack_from('<IIII',b,root+dest);p=off(rva)
                yield path+[name],p,b[p:p+size]
    yield from walk(0,[])

def components(o):
    yield o
    for c in o['children']:yield from components(c)
def code_ranges(b):
    pe=struct.unpack_from('<I',b,0x3c)[0];n=struct.unpack_from('<H',b,pe+6)[0];os=struct.unpack_from('<H',b,pe+20)[0];op=pe+24
    base=struct.unpack_from('<I',b,op+28)[0];sections=[]
    for i in range(n):
        q=op+os+i*40;vs,va,rs,rp=struct.unpack_from('<IIII',b,q+8);flags=struct.unpack_from('<I',b,q+36)[0]
        if flags&0x20000000:sections.append((base+va,base+va+rs,rp))
    return sections

def published_methods(b,handlers):
    result=[];ranges=code_ranges(b)
    for name in sorted(set(h['handler'] for h in handlers)):
        raw=name.encode('ascii');pos=0
        while True:
            pos=b.find(raw,pos)
            if pos<0:break
            if pos>=7 and b[pos-1]==len(raw):
                size=struct.unpack_from('<H',b,pos-7)[0];address=struct.unpack_from('<I',b,pos-5)[0]
                for lo,hi,start in ranges:
                    if size==7+len(raw) and lo<=address<hi:
                        result.append({'handler':name,'entry_file_offset':pos-7,'entry_size':size,'code_va':f'0x{address:08X}','code_file_offset':start+address-lo,'association':'method-name match; class ownership unresolved'})
            pos+=1
    return result

def project_skeleton(o,handlers,evidence,module):
    # DFM does not carry C++ method signatures, inheritance, or original unit names.
    project=Path('recovered/project')/module;project.mkdir(parents=True,exist_ok=True)
    cs=[c for c in components(o) if c is not o]
    lines=['// Recovered declaration skeleton, NOT the original source unit.',
           '// Exact class, component and event names come from the binary DFM.',
           '// Base class, signatures, field layout and method bodies are unknown.',
           '// This incomplete class is an inventory; it is not a buildable VCL form.',
           '// Source resource: '+evidence['binary'], '#pragma once', '']
    for cls in sorted(set(c['class'] for c in cs)):lines.append('class '+cls+';')
    lines.extend(['', 'class '+o['class']+' {', 'public:'])
    seen=set()
    for c in cs:
        if c['name'] and c['name'] not in seen:
            lines.append('    '+c['class']+' *'+c['name']+';');seen.add(c['name'])
    lines.append('    // Recorded event bindings; signatures must be recovered from code:')
    for h in handlers:lines.append('    // '+h['component']+'.'+h['event']+' -> '+h['handler'])
    lines.extend(['};',''])
    target=project/(o['class']+'.hpp');target.write_text('\n'.join(lines),encoding='utf8')
    return str(target)

def write_method_maps(report):
    out=Path('recovered/project/method_maps');out.mkdir(parents=True,exist_ok=True)
    alias={'_main':'main','_ency':'encyclopedia','_mol':'molecule','avi':'avi','gif':'gif'}
    for r in report:
        if 'forms' not in r:continue
        module=alias.get(Path(r['input']).stem,'resource_'+r['sha256'][:8]);pairs={}
        for f in r['forms']:
            for h in f.get('published_method_candidates',[]):
                pairs.setdefault(h['code_va'],{}).setdefault(h['handler'],[]).append({'resource_path':f['resource_path'],'root_class':f['root_class'],'entry_file_offset':h['entry_file_offset'],'entry_size':h['entry_size'],'code_file_offset':h['code_file_offset']})
        rows=[];proof=[]
        for addr,names in sorted(pairs.items(),key=lambda x:int(x[0],16)):
            if len(names)!=1:continue
            handler=next(iter(names));rows.append(addr+'\tPublished_'+handler)
            proof.append({'address':addr,'name':'Published_'+handler,'method_name':handler,'evidence':names[handler],'class_ownership':'unresolved; Published prefix is synthetic'})
        (out/(module+'.tsv')).write_text('address\tname\n'+'\n'.join(rows)+'\n')
        (out/(module+'.json')).write_text(json.dumps({'binary':r['input'],'sha256':r['sha256'],'entries':proof},ensure_ascii=False,indent=2)+'\n')

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--input',default='artifacts/ChemLab');ap.add_argument('--output',default='recovered/forms');args=ap.parse_args()
    out=Path(args.output);out.mkdir(parents=True,exist_ok=True);report=[];seen={}
    for exe in sorted(p for p in Path(args.input).rglob('*') if p.is_file() and p.suffix.lower() in ('.exe', '.dll', '.obj') and p.read_bytes()[:2] == b'MZ'):
        b=exe.read_bytes();digest=sha(b)
        if digest in seen:
            report.append({'input':str(exe),'sha256':digest,'duplicate_of':seen[digest]});continue
        seen[digest]=str(exe);forms=[]
        for path,offset,raw in resources(b):
            if not raw.startswith(b'TPF0'):continue
            name=str(path[1]);base=out/str(exe.relative_to(Path(args.input)).with_suffix(''))/name;base.parent.mkdir(parents=True,exist_ok=True)
            base.with_suffix('.dfm.bin').write_bytes(raw);r=Reader(raw);r.p=4
            evidence={'resource_path':path,'file_offset':offset,'resource_size':len(raw),'sha256':sha(raw),'binary':str(base.with_suffix('.dfm.bin'))}
            try:
                o=r.obj();evidence.update(parsed_size=r.p,trailing_bytes=len(raw)-r.p,root_class=o['class'],root_name=o['name'],component_count=sum(1 for _ in components(o)))
                handlers=[{'component':c['name'],'class':c['class'],'event':p['name'],'handler':p['value']['value']} for c in components(o) for p in c['properties'] if p['name'].startswith('On') and p['value']['type']==7]
                evidence['event_handlers']=handlers
                evidence['published_method_candidates']=published_methods(b,handlers)
                evidence['declaration_skeleton']=project_skeleton(o,handlers,evidence,str(exe.relative_to(Path(args.input)).with_suffix('')))
                base.with_suffix('.dfm').write_text('\n'.join(render(o))+'\n',encoding='utf8')
                base.with_suffix('.json').write_text(json.dumps({'evidence':evidence,'form':o},ensure_ascii=False,indent=2,allow_nan=False)+'\n',encoding='utf8')
            except Exception as e:evidence['parse_error']=str(e)
            forms.append(evidence)
        report.append({'input':str(exe),'sha256':digest,'forms':forms})
    (out/'manifest.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    write_method_maps(report)
    print(json.dumps([{'input':r['input'],'forms':len(r.get('forms',[])),'errors':[f for f in r.get('forms',[]) if 'parse_error' in f],'duplicate_of':r.get('duplicate_of')} for r in report],ensure_ascii=False,indent=2))
if __name__=='__main__':main()
