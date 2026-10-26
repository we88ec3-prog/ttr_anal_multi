# KR T08 — 0x00716740 string-indexed related-data lookup

- Recorder: **chatgpt-web roy**
- Recorded: **2026-10-26 17:52:19 +08:00** (Asia/Taipei)
- Source: **Tartaros.bin**, SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- Scope: static x86 PE disassembly at `0x00716740–0x0071682A`, caller `0x0054105C–0x00541070`
- Summary: this is a **string-keyed lookup and forwarding** routine, not direct Actor creation or direct global registry insertion.

## Caller / parameter evidence

```asm
0054105C push esi
0054105D mov ecx,0x00C0F570
00541062 mov edx,0x00FE1DFC
00541067 call 0x00716740
0054106C mov esi,eax
0054106E cmp esi,ebx
00541070 jne 0x005410AE
```

The caller supplies a fixed string pointer in ECX, a container/lookup object pointer in EDX, and an additional stack argument. The meaning of the constant string has not been confirmed here.

## Disassembly-backed observations

| Address | Observation |
|---|---|
| `0x00716784–0x00716795` | measures the null-terminated ECX string then calls `0x00402A70` to prepare a temporary string |
| `0x0071679A–0x007167A3` | passes that temporary string to `0x007B6F30` with the EDX-supplied lookup context |
| `0x007167AB` | compares returned node with the sentinel at `[esi+0x04]` |
| `0x007167B0–0x007167BB` | compares candidate node key using `0x0049AE30` |
| `0x007167F5–0x007167FC` | if sentinel/no match, returns NULL |
| `0x007167FE` | obtains pointer `[edi+0x28]` from matching node |
| `0x00716804–0x00716808` | adds `0x3C` to that pointer and calls `0x007197E0` with another argument |
| `0x00716828–0x0071682A` | returns using `ret 4` |

## Cautions

- `0x00716740` does not directly return `[node+0x28]`: it calls `0x007197E0` on an adjusted pointer.
- Neither the returned pointer's original C++ type nor the key string's game-specific meaning is yet established.
- The existing `kr-bulk-roy` contains Ghidra 12.1.4 batch JSON and some C pseudocode; this particular target was **not verified as available in that batch**. This note's instructions were verified against the original BIN using `objdump -d -Mintel`.
- Compare to canonical KR analyses before claiming the finding is new.

## Next focused targets

Decode string at `0x00C0F570` and inspect `0x007197E0`; confirm whether the lookup locates a model/resource object or another table entry, before assigning game semantics.
