import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Instruction;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.charset.StandardCharsets;

public class DumpCashInstructions extends GhidraScript {
    public void run() throws Exception {
        long[][] ranges = {
            {0x698d40L, 0x698f40L},
            {0x699000L, 0x6990b0L},
            {0x699260L, 0x6995c0L},
            {0x69c490L, 0x69c550L},
            {0x69c550L, 0x69ca20L},
            {0x4e1da0L, 0x4e23e0L},
            {0x4e2670L, 0x4e26b0L},
            {0x4e3c50L, 0x4e3d30L},
            {0x50a560L, 0x50a890L}
        };
        StringBuilder result = new StringBuilder();
        for (long[] range : ranges) {
            Address start = toAddr(range[0]);
            Address end = toAddr(range[1] - 1);
            DisassembleCommand command = new DisassembleCommand(start, new AddressSet(start, end), true);
            command.applyTo(currentProgram, monitor);
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
        println("CASH_INSTRUCTIONS_WRITTEN " + result.length());
    }
}
