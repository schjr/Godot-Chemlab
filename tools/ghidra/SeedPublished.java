// Seed independently evidenced entry points before automatic analysis.
// @category Recovery
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
public class SeedPublished extends GhidraScript {
    public void run() throws Exception {
        for(String line:Files.readAllLines(Paths.get(getScriptArgs()[0]),StandardCharsets.UTF_8)) {
            if(line.startsWith("address\t") || line.isBlank()) continue;
            String[] row=line.split("\t"); Address addr=toAddr(row[0]);
            Function f=getFunctionAt(addr);
            if(f==null && getFunctionContaining(addr)==null) {disassemble(addr);f=createFunction(addr,null);}
            if(f!=null) f.setName(row[1]+"_"+addr.toString(),SourceType.USER_DEFINED);
        }
    }
}
