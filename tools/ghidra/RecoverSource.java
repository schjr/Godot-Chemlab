// Exports static decompiler output and instruction fallback. Does not execute target.
// @category Recovery
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.io.*;

public class RecoverSource extends GhidraScript {
    private String clean(String s) { return s.replace("\t", " ").replace("\r", " ").replace("\n", " "); }
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path dir = Paths.get(args[0]); Files.createDirectories(dir);
        DecompInterface dec = new DecompInterface();
        dec.setOptions(new DecompileOptions());
        dec.toggleCCode(true); dec.toggleSyntaxTree(false);
        dec.setSimplificationStyle("decompile");
        if (!dec.openProgram(currentProgram)) throw new IOException(dec.getLastMessage());
        int total=0, success=0, failed=0, external=0, thunks=0;
        try (BufferedWriter index = Files.newBufferedWriter(dir.resolve("functions.tsv"), StandardCharsets.UTF_8);
             BufferedWriter code = Files.newBufferedWriter(dir.resolve("decompiled.cpp"), StandardCharsets.UTF_8);
             BufferedWriter asm = Files.newBufferedWriter(dir.resolve("fallback.asm"), StandardCharsets.UTF_8)) {
            index.write("address\tname\tbody_bytes\texternal\tthunk\tstatus\tmessage\n");
            code.write("/* RECOVERED GHIDRA PSEUDOCODE, NOT ORIGINAL OR BUILDABLE SOURCE.\n" +
                "Input: " + currentProgram.getName() + "\n" +
                "SHA256: " + currentProgram.getExecutableSHA256() + "\n" +
                "Language: " + currentProgram.getLanguageID() + "\n" +
                "No target execution or behavioral equivalence validation. */\n\n");
            FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
            while (it.hasNext() && !monitor.isCancelled()) {
                Function f=it.next(); total++;
                String status, msg="";
                if(f.isExternal()) { status="external"; external++; }
                else {
                    if(f.isThunk()) thunks++;
                    DecompileResults r=dec.decompileFunction(f,60,monitor);
                    if(r.decompileCompleted() && r.getDecompiledFunction()!=null) {
                        status="decompiled"; success++;
                        code.write("// Entry " + f.getEntryPoint() + ", recovered name " + clean(f.getName(true)) + "\n");
                        code.write(r.getDecompiledFunction().getC()); code.write("\n\n");
                    } else {
                        status="failed"; failed++; msg=clean(r.getErrorMessage());
                        asm.write("; " + f.getEntryPoint()+" "+clean(f.getName(true))+" "+msg+"\n");
                        InstructionIterator ins=currentProgram.getListing().getInstructions(f.getBody(),true);
                        while(ins.hasNext()) { Instruction i=ins.next(); asm.write(i.getAddress()+"  "+i.toString()+"\n"); }
                    }
                }
                index.write(f.getEntryPoint()+"\t"+clean(f.getName(true))+"\t"+f.getBody().getNumAddresses()+"\t"+f.isExternal()+"\t"+f.isThunk()+"\t"+status+"\t"+msg+"\n");
                if(total%100==0) { index.flush(); code.flush(); println("RECOVERY "+currentProgram.getName()+" functions="+total+" decompiled="+success+" failed="+failed); }
            }
        } finally { dec.dispose(); }
        try(BufferedWriter syms=Files.newBufferedWriter(dir.resolve("symbols.tsv"),StandardCharsets.UTF_8)) {
            syms.write("address\ttype\tsource\tname\n");
            SymbolIterator it=currentProgram.getSymbolTable().getAllSymbols(true);
            while(it.hasNext()) { Symbol s=it.next(); syms.write(s.getAddress()+"\t"+s.getSymbolType()+"\t"+s.getSource()+"\t"+clean(s.getName(true))+"\n"); }
        }
        String summary="{\"input\":\""+currentProgram.getName()+"\",\"sha256\":\""+currentProgram.getExecutableSHA256()+"\",\"functions\":"+total+",\"decompiled\":"+success+",\"failed\":"+failed+",\"external\":"+external+",\"thunks\":"+thunks+",\"cancelled\":"+monitor.isCancelled()+",\"scope\":\"Ghidra discovered functions only; unidentified code remains unknown\"}\n";
        Files.writeString(dir.resolve("coverage.json"),summary,StandardCharsets.UTF_8);
        println("RECOVERY COMPLETE "+summary);
    }
}
