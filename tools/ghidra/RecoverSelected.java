// Seed exact direct-call targets, then export selected decompiler+instruction evidence.
// @category Recovery
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.Address;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.io.*;
public class RecoverSelected extends GhidraScript {
    public void run() throws Exception {
        String[] a=getScriptArgs(); boolean seed=a[0].equals("seed");
        Path out=Paths.get(a[1]); if(!seed)Files.createDirectories(out);
        DecompInterface dec=null;
        if(!seed) {dec=new DecompInterface();dec.setOptions(new DecompileOptions());dec.toggleCCode(true);dec.openProgram(currentProgram);}
        try {
            for(int i=2;i<a.length;i++) {
                Address addr=toAddr(a[i]); Function f=getFunctionAt(addr);
                if(seed) {
                    if(f==null && getFunctionContaining(addr)==null){disassemble(addr);f=createFunction(addr,null);}
                    println("SEED "+addr+" "+(f==null ? "unresolved" : f.getName()));continue;
                }
                if(f==null){println("UNRESOLVED "+addr);continue;}
                DecompileResults r=dec.decompileFunction(f,120,monitor);
                if(r.decompileCompleted() && r.getDecompiledFunction()!=null) Files.writeString(out.resolve(addr+".cpp"),"// Original PE SHA256 "+currentProgram.getExecutableSHA256()+"\n// Entry "+addr+"\n"+r.getDecompiledFunction().getC(),StandardCharsets.UTF_8);
                else Files.writeString(out.resolve(addr+".error.txt"),r.getErrorMessage());
                try(BufferedWriter w=Files.newBufferedWriter(out.resolve(addr+".asm"),StandardCharsets.UTF_8)) {
                    InstructionIterator instructions=currentProgram.getListing().getInstructions(f.getBody(),true);
                    while(instructions.hasNext()){Instruction x=instructions.next();w.write(x.getAddress()+"  "+x.toString()+"\n");}
                }
                println("EXPORTED "+addr+" "+f.getBody().getNumAddresses()+" bytes");
            }
        } finally {if(dec!=null)dec.dispose();}
    }
}
