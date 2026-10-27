# KR T10-5 — Mapping callers and evidence

Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91; x86 PE .text VA 0x401000/raw 0x400. Read-only objdump and E8 rel32 scanning, no executable launched.

T10-4 had identified 0x6D4DC0 as a mapping lookup. Direct call site scan finds related calls at 0x594672, 0x5946CB, 0x59471B, 0x5CD68A, 0x650E96 and 0x650F48, amongst others. Unaligned byte matches and indirect calls remain limitations.

At 0x594664 PUSH 2 and 0x594666 PUSH EDI lead to CALL 0x6D4DC0 at 0x594672. Within this function, calls at 0x5946CB and 0x59471B pass explicit index values 0xD and 0xE with group 2. At 0x5CD67A PUSH 2, 0x5CD67C PUSH 0x10, and 0x5CD68A CALL 0x6D4DC0 are followed by begin/end vector inspection and WORD string comparison. At 0x650E86 PUSH 2, 0x650E88 PUSH 0x2904 and CALL 0x6D4DC0 at 0x650E96; a second query passes 0x2906 at 0x650F48. These use cases imply a generic mapping-value provider, not a Z key-down callback.

Observed raw assembly:
    594664 6a 02             push 2
    594666 57                push edi
    594672 e8 49 07 14 00    call 0x6d4dc0
    5946bb 6a 02             push 2
    5946bd 6a 0d             push 0xd
    5946cb e8 f0 06 14 00    call 0x6d4dc0
    5cd67a 6a 02             push 2
    5cd67c 6a 10             push 0x10
    5cd68a e8 31 77 10 00    call 0x6d4dc0

Provisional C++: Vector32 mapped; lookupMappedValues(&mapped, group, mappingIndex); consumer(mapped). The function name, group/index semantics and Z association are not established. No direct link to the controller's held-state machine has been proven.

Evidence categories: confirmed call instructions and local argument values; hypothesized generic mapping lookup; unverified Z physical key mapping, runtime pressed/held writer, full indirect caller set. T10-6 next investigates 0x6D43F0 and 0x6D1DA0.