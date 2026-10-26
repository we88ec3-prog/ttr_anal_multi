# KR T08 — Upstream key source for 0x0079D8E0

- Recorder: `chatgpt-web roy`
- Timestamp (Asia/Taipei): `2026-10-26 11:59:41 +08:00`
- File: `Tartaros.bin` (SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`)
- Scope: original PE32 x86 static disassembly, `0x00541130–0x0054124F` and `0x0079D8E0–0x0079D9BE`; no game execution.
- Summary: caller obtains a key from an upstream node's `+0x0C` field and passes it to the shared global structure at `0x00FC0E90`. Callee conditionally locates/creates a container entry and updates its pointer/control-block payload.

## Primary bytes/disassembly evidence

```asm
005411BE  mov ecx, [ebp-0x138]
005411C4  mov edx, [ecx+0x0c]
005411C7  push edx
005411C8  mov esi, 0x00FC0E90
005411D1  call 0x0079D8E0
```

- `[ebp-0x138]` is an upstream node pointer. `[node+0x0c]` is the immediate source of the integer/key argument.
- The preceding `0x0054115E` pushes `0x00FC0E90` to `0x0079D610`. `0x00541134–0x0054115A` initializes this global on first use if its flag is unset.
- `0x0079D8E0` receives the global object in ESI and handles another group of stack arguments (ends in `ret 0x20`). A single `push edx` near the call is **not** the complete eight-dword argument setup; prior stack-built temporary objects also matter.

## Callee observations

| VA | Observed behavior |
|---|---|
| `0x0079D915` | calls `0x007D0110` with structure at `[esi+0x10]` |
| `0x0079D941` | compares candidate with `[esi+0x14]` sentinel |
| `0x0079D958` | failed match returns `AL=0` |
| `0x0079D976` | calls `0x00515790` for lookup in ESI container |
| `0x0079D98A` | calls `0x007A0C70`, an earlier inspected conditional tree insertion helper |
| `0x0079D993` | calls `0x007A0DA0` with target from `[edi+0x28]` |
| `0x0079D9AA` | successful branch returns `AL=1` |

The `[edi+0x28]` source for the update is from the candidate node found by earlier lookup. **Do not claim that the updated pointer is newly constructed at this call site.** Its creation and data provenance are still to be traced.

## Limitations / next steps

- Class names, game semantics, the upstream node's origin, and why two lookup trees are involved are not verified.
- Review the full enclosing function around `0x00540Fxx–0x005413xx`, especially how local `[ebp-0x138]` is initialized and advanced, to establish the traversal and provenance.
- This is supplemental evidence, not an assertion of unique or novel KR information. Compare to canonical KR/T08 notes before promoting.
