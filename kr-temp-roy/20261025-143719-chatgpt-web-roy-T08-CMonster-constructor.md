# KR T08 — CMonster constructor partial static verification

- Recorder: `chatgpt-web roy`
- Recorded at (Asia/Taipei, UTC+08:00): `2026-10-25 14:37:19 +08:00`
- Scope: `Tartaros.bin` VA `0x004D1710–0x004D18CF` (PE32 x86); local `objdump -d -Mintel` static disassembly
- Target SHA-256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- Summary: Verified the constructor calls `0x004C7070`, allocates three structures (`0x3C`, `0x38`, `0x3C` bytes) and stores their pointers in an indexed table at `object + 0xF4 + index*4`.

## Direct machine-code observations

| VA | Evidence / interpretation |
| --- | --- |
| `0x004D173A` | `call 0x004C7070` with object pointer pushed immediately before |
| `0x004D1747`, `0x004D1773` | `push 0x3c; call 0x00891268` (allocation) |
| `0x004D1788–0x004D1798` | passes `ecx = 3` and object via `eax` to `0x004CB230`, writes vtable-like `0x00C077CC` |
| `0x004D17C1` | writes structure pointer to `[edi + ebx*4 + 0xf4]`, `ebx` loaded from `[esi + 8]` |
| `0x004D17D7–0x004D17D9` | `push 0x38; call 0x00891268` |
| `0x004D17E6–0x004D17FE` | passes `ecx = 2` to `0x004CB230`, writes vtable-like `0x00C077B4` |
| `0x004D182F` | second indexed table write |
| `0x004D1845–0x004D1847` | `push 0x3c; call 0x00891268` |
| `0x004D185E–0x004D186F` | passes `ecx = 5` to `0x004CB230`, writes vtable-like `0x00C077FC` |
| `0x004D189A` | third indexed table write |
| `0x004D18B2` | writes `1` to `[edi + 0x39c]` |
| `0x004D17B4`, `0x004D1822`, `0x004D188D` | if slot nonzero, calls `0x006EDB60` before writing pointer (semantics unconfirmed) |

## Interpretation limits

- `CMonster` naming comes from prior KR documentation; the binary inspection independently verifies the instructions but not class names.
- The meanings of component IDs `3`, `2`, `5`, the vtables, and field `+0x39C` remain unknown.
- No runtime execution, full decompilation, or exhaustive comparison to existing KR/T08 records was done. Do not treat this as a new game mechanic without checking earlier evidence.
- No additional game files were loaded, and the original binaries were not modified.

## Suggested follow-up

Inspect `0x004CB230` and the use of `[esi + 8]` to determine the slot index mapping. Compare with earlier KR T08 evidence before merging into authoritative findings.
