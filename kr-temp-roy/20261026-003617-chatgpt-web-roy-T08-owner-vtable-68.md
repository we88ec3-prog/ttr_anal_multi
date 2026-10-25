# KR T08 — CMonster owner virtual call +0x68 verified

- Recorder: **chatgpt-web roy**
- Timestamp (Asia/Taipei): **2026-10-26 00:36:17 +08:00**
- Task: **KR / T08**
- File: `Tartaros.bin`, SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- Method: independent static PE32 x86 disassembly and section-aware virtual-address-to-file-offset reads; no execution
- Summary: connected the prior component callback `0x004CB2C0` to CMonster vtable slot `+0x68` → `0x004C8DA0`, and verified the target stores the integer argument in owner field `+0x38C`, optionally invoking `0x007A6970`.

## Vtable resolution

At `0x004D1749`, CMonster constructor writes vtable pointer `0x00C0C9DC` at `[edi]` (its main-object vptr).

`0x00C0C9DC` is in `.rdata` (VMA `0x00BD2000`, file offset `0x007D0600`). Slot at vtable `+0x68` (file offset `0x0080B044`) contains `0x004C8DA0` little-endian.

The constructor also sets the different vtable `0x00C0CA64` at object `+0xF0`; its own slot `+0x68` points to `0x004D2820`, **not** `0x004C8DA0`. The call site in `0x004CB2C0` uses `owner = [component+4]` and `vptr = [owner]`, so for the constructed CMonster it resolves through the **primary** vtable. Virtual calls may resolve differently for other runtime object types.

## Target function 0x004C8DA0–0x004C8DCF

| VA | Instruction | Direct observation |
|---|---|---|
| `0x004C8DA3` | `mov eax,[ebp+8]` | loads first integer argument |
| `0x004C8DA7` | `mov edi,[ecx+0x15c]` | loads owner field `+0x15C` |
| `0x004C8DAD` | `mov [ecx+0x38c],eax` | writes the argument to `owner+0x38C` |
| `0x004C8DB3–0x004C8DBE` | tests `edi` and `[ecx+0x370]` | gates downstream call on both being nonzero |
| `0x004C8DC0` | `fld [ebp+0xc]` | loads second argument as 32-bit float |
| `0x004C8DC3–0x004C8DC8` | pushes float and integer; `call 0x007A6970` | forwards two values to another routine when gate passes |
| `0x004C8DCF` | `ret 8` | callee pops 8 bytes of arguments |

The earlier caller `0x004CB2C0` obtains `owner+0x38C` at `0x004CB2D2` and can invoke vtable `+0x68` with a small integer code and `1.0f` (e.g. `0x004CB305–0x004CB315`). This supports a **state-code setter with conditional forwarding** description. Whether these codes are actions, animation states, AI modes, etc. is not established by this trace.

## Limits / follow-up

- Only CMonster's *primary* vtable target is resolved here; other subclasses or stages may have different vptr values.
- No semantic names are claimed for codes, owner `+0x15C` / `+0x370`, or callee `0x007A6970`.
- Existing KR evidence has not been exhaustively compared; treat as independent supplemental verification, not necessarily a novel finding.
- Suggested next narrow target: inspect `0x007A6970` inputs and immediate effects, and see whether existing KR T08 notes already cover this path.
