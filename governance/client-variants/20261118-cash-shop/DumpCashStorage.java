import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Instruction;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.charset.StandardCharsets;

public class DumpCashStorage extends GhidraScript {
    public void run() throws Exception {
        long[][] ranges = {
            {0x4e1590L, 0x4e17a0L},
            {0x4e1da0L, 0x4e23e0L},
            {0x4e2b30L, 0x4e2c80L},
            {0x4e3bc0L, 0x4e3c50L},
            {0x4e3fb0L, 0x4e4000L},
            {0x50ac70L, 0x50aef0L},
            {0x50b070L, 0x50b180L},
            {0x698a30L, 0x698d40L},
            {0x511e40L, 0x512a50L},
            {0x52ef90L, 0x52f0f0L},
            {0x5b9180L, 0x5b91d0L},
            {0x413860L, 0x4138c0L}
        };
        StringBuilder result = new StringBuilder();
        for (long[] range : ranges) {
            Address start = toAddr(range[0]);
            Address end = toAddr(range[1] - 1);
            new DisassembleCommand(start, new AddressSet(start, end), true).applyTo(currentProgram, monitor);
            Address cursor = start;
            while (cursor.compareTo(end) <= 0) {
                Instruction item = currentProgram.getListing().getInstructionAt(cursor);
                if (item == null) {
                    new DisassembleCommand(cursor, new AddressSet(cursor, end), false).applyTo(currentProgram, monitor);
                    item = currentProgram.getListing().getInstructionAt(cursor);
                }
                cursor = cursor.add(item == null ? 1 : item.getLength());
            }
            result.append("\nRANGE ").append(start).append(" ").append(end).append("\n");
            for (Instruction instruction : currentProgram.getListing().getInstructions(new AddressSet(start, end), true)) {
                result.append(instruction.getAddress()).append(" ");
                for (byte value : instruction.getBytes()) {
                    result.append(String.format("%02x", value & 255));
                }
                result.append(" ").append(instruction.toString()).append("\n");
            }
        }
        Files.writeString(Path.of(getScriptArgs()[0]), result.toString(), StandardCharsets.UTF_8);
        println("CASH_STORAGE_INSTRUCTIONS_WRITTEN " + result.length());
    }
}
