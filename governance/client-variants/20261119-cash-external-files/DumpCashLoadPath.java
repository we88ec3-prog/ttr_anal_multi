import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Instruction;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.charset.StandardCharsets;

/** Bounded static read only. No program execution or analysis-database save. */
public class DumpCashLoadPath extends GhidraScript {
    public void run() throws Exception {
        long[][] ranges = {
            {0x4146b0L,0x414720L}, {0x415f70L,0x416020L}, {0x416020L,0x416520L},
            {0x511ca0L,0x511e40L}, {0x511e40L,0x511f50L},
            {0x72f110L,0x72f260L}, {0x72f260L,0x72f620L},
            {0x714770L,0x714890L}, {0x713910L,0x713bb0L},
            {0x714c50L,0x714e40L}, {0x714030L,0x714270L},
            {0x713cc0L,0x713e80L}, {0x717b60L,0x717bc0L}
        };
        if(getScriptArgs().length>1 && getScriptArgs()[1].equals("integrity")) ranges=new long[][] {
            {0x48b2e0L,0x48b380L}, {0x48b380L,0x48b730L}, {0x48b730L,0x48b8c0L},
            {0x48b9c0L,0x48bb60L}, {0x48bd30L,0x48be60L}, {0x713cc0L,0x713e80L}
        };
        StringBuilder result=new StringBuilder();
        for(long[] range:ranges){
            Address start=toAddr(range[0]),end=toAddr(range[1]-1);
            new DisassembleCommand(start,new AddressSet(start,end),true).applyTo(currentProgram,monitor);
            result.append("\nRANGE ").append(start).append(" ").append(end).append("\n");
            for(Instruction instruction:currentProgram.getListing().getInstructions(new AddressSet(start,end),true)){
                result.append(instruction.getAddress()).append(" ");
                for(byte value:instruction.getBytes())result.append(String.format("%02x",value&255));
                result.append(" ").append(instruction).append("\n");
            }
        }
        Files.writeString(Path.of(getScriptArgs()[0]),result.toString(),StandardCharsets.UTF_8);
        println("CASH_LOAD_PATH_WRITTEN "+result.length());
    }
}
