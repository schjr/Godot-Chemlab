// Recovers published event entry points omitted by default function discovery.
// @category Recovery
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.io.*;
import java.util.*;

public class RecoverPublished extends GhidraScript {
    private String clean(String s) { return s==null ? "" : s.replace("\t"," ").replace("\r"," ").replace("\n"," "); }
    public void run() throws Exception {
        String[] args=getScriptArgs(); Path out=Paths.get(args[1]); Files.createDirectories(out);
        List<String> lines=Files.readAllLines(Paths.get(args[0]),StandardCharsets.UTF_8);
        ArrayList<Function> functions=new ArrayList<>(); ArrayList<String[]> records=new ArrayList<>();
        for(String line:lines.subList(1,lines.size())) {
            String[] row=line.split("\t"); Address address=toAddr(row[0]);
            Function f=getFunctionAt(address); String discovery="existing";
            if(f==null) {
                Function containing=getFunctionContaining(address);
                if(containing!=null) discovery="interior-of-"+containing.getEntryPoint();
                else { disassemble(address); f=createFunction(address,null); discovery="metadata-seeded"; }
            }
            if(f!=null) f.setName(row[1]+"_"+address.toString(),SourceType.USER_DEFINED);
            functions.add(f); records.add(new String[]{row[0],row[1],discovery});
        }
        DecompInterface dec=new DecompInterface(); dec.setOptions(new DecompileOptions());
        dec.toggleCCode(true); dec.toggleSyntaxTree(false); dec.setSimplificationStyle("decompile");
        if(!dec.openProgram(currentProgram)) throw new IOException(dec.getLastMessage());
        int ok=0,failed=0;
        try(BufferedWriter code=Files.newBufferedWriter(out.resolve("published_recovered.cpp"),StandardCharsets.UTF_8);
            BufferedWriter index=Files.newBufferedWriter(out.resolve("published_recovery.tsv"),StandardCharsets.UTF_8);
            BufferedWriter asm=Files.newBufferedWriter(out.resolve("published_fallback.asm"),StandardCharsets.UTF_8)) {
            code.write("/* GHIDRA PSEUDOCODE FOR PUBLISHED METHOD ENTRIES; NOT ORIGINAL/BUILDABLE SOURCE.\n"
                +"Metadata-seeded entries supplement default analysis. Names preserve published names\n"
                +"with synthetic prefix and address suffix; original class ownership/signatures unknown.\n"
                +"SHA256: "+currentProgram.getExecutableSHA256()+" */\n\n");
            index.write("address\tpublished_name\tdiscovery\tstatus\tmessage\n");
            for(int i=0;i<functions.size();i++) {
                Function f=functions.get(i); String[] row=records.get(i); String status,msg="";
                if(f==null) { status="unresolved"; failed++; msg="No exact function entry after conservative disassembly"; }
                else {
                    DecompileResults result=dec.decompileFunction(f,60,monitor);
                    if(result.decompileCompleted() && result.getDecompiledFunction()!=null) {
                        status="decompiled"; ok++;
                        code.write("// Entry "+f.getEntryPoint()+", recovered name "+f.getName()+"\n");
                        code.write(result.getDecompiledFunction().getC()+"\n\n");
                    } else {
                        status="failed"; failed++; msg=clean(result.getErrorMessage());
                        asm.write("; "+row[0]+" "+row[1]+" "+msg+"\n");
                        InstructionIterator ins=currentProgram.getListing().getInstructions(f.getBody(),true);
                        while(ins.hasNext()) { Instruction in=ins.next(); asm.write(in.getAddress()+"  "+in+"\n"); }
                    }
                }
                index.write(row[0]+"\t"+row[1]+"\t"+row[2]+"\t"+status+"\t"+msg+"\n");
                if(i%25==0) {index.flush();code.flush();println("PUBLISHED "+currentProgram.getName()+" "+i+"/"+functions.size());}
            }
        } finally { dec.dispose(); }
        Files.writeString(out.resolve("published_coverage.json"),"{\"sha256\":\""+currentProgram.getExecutableSHA256()+"\",\"total\":"+functions.size()+",\"decompiled\":"+ok+",\"unresolved_or_failed\":"+failed+"}\n");
        println("PUBLISHED COMPLETE "+currentProgram.getName()+" "+ok+"/"+functions.size());
    }
}
