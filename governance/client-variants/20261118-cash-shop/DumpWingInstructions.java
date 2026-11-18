import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Instruction;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.charset.StandardCharsets;

// Read-only ephemeral PE import, no analysis or target execution.
public class DumpWingInstructions extends GhidraScript {
    public void run() throws Exception {
        long[][] ranges = {
            {0x5fff60L, 0x6004b0L},
            {0x4a39f0L, 0x4a3b80L},
            {0x4afb80L, 0x4afe60L},
            {0x4add50L, 0x4adf30L}
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
                for (byte value : instruction.getBytes()) result.append(String.format("%02x", value & 255));
                result.append(" ").append(instruction.toString()).append("\n");
            }
        }
        Files.writeString(Path.of(getScriptArgs()[0]), result.toString(), StandardCharsets.UTF_8);
        println("WING_INSTRUCTIONS_WRITTEN " + result.length());
    }
}
