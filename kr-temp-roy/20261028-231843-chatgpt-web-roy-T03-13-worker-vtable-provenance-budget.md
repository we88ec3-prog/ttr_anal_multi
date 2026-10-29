# T03-13 — KR receive worker vtable provenance boundary and scheduling budget (BIN-first)

- Researcher: chatgpt-web roy
- Date: 2026-10-28 23:18:43 Asia/Taipei
- Scope: T03 only. No client execution, binary patch, invented protocol opcode, or server fixture used.
- Target: `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` verified in this analysis.
- Section mapping from `objdump -h`: `.text` VA `0x401000`, raw `0x400` (raw = VA − `0x400C00`); `.rdata` VA `0xBD2000`, raw `0x7D0600`.
- Prior authoritative branch document: `kr-temp-roy/20261028-231458-chatgpt-web-roy-T03-12-worker-poll-recycle-lifecycle.md`; read alongside `03-PROJECT-T03-INSTRUCTIONS.md` and common `02-PROJECT-SHARED-INSTRUCTIONS.md`.
- Status: bounded original-machine-code observations. **Neither concrete worker virtual-method implementation nor command 0x42 server reply is verified.**

## 1. Scope and main new observations

The receive-loop callback site `0x80486D` is **not reached with a freshly constructed worker from inside `0x804740`**. The function takes its worker via `[ebp+8]`, performs local state/time-window setup, then looks up bucket-specific received records and dispatches via its first DWORD. The only verified direct caller `0x49198A` passes `parent+0x140`. In the observed parent initialization `0x48C0E0 → 0x804650`, there is **no store to the first DWORD of that embedded object**. Instead the latter sets `worker+0x8C`, allocates a distinct 0x5C-byte transport instance, installs **that** transport instance's `0xC51748` vtable and stores it globally to `0xFBA854`. Thus `0xC51748` is not evidence for `worker vtable+0`.

New precise worker scheduling: `0x8047B2..0x8047BD` copies 11 DWORDs (44 bytes) from `worker+0x30` to `worker+4`, then zeroes the 11-DWORD region `worker+0x30`. After timing setup, `worker+0x84` is compared with elapsed time; if elapsed exceeds `worker+0x84−4`, this iteration's time allowance becomes 4 and `worker+0x58=1`. After bucket indexes 0..5, `0x8049EF..0x8049F5` sets `worker+0x59` to the unsigned comparison of iteration duration against that allowance. These are scheduling/backpressure observations, **not proof of a role-selection callback**.

## 2. Round 1 — Native object source and non-conflation

Source `objdump -D -M intel --section=.text --start-address=0x491900 --stop-address=0x491a10`:
```asm
49197f: 8b 7c 24 20           mov edi,[esp+0x20]
491983: 8d 9f 40 01 00 00     lea ebx,[edi+0x140]
491989: 53                    push ebx
49198a: e8 b1 2d 37 00        call 0x804740
```
Observe that this parent is the caller-local `EDI` value. No class identity has been established.

Source parent initialization:
```asm
48c0e0: 8d bb 40 01 00 00     lea edi,[ebx+0x140]
48c0e6: e8 65 85 37 00        call 0x804650
```
This pair proves the offset correspondence, not that `0x804650` writes the embedded vtable.

Source `0x804650`:
```asm
80467b: c7 87 8c 00 00 00 00 00 00 00  mov dword ptr [edi+0x8c],0
8046d7: 6a 5c                 push 0x5c
8046d9: e8 8a cb 08 00        call 0x891268
8046f1: 56                    push esi
8046f2: e8 69 f6 ff ff        call 0x803d60
8046f7: c7 06 48 17 c5 00     mov dword ptr [esi],0xc51748
80470f: 89 0d 54 a8 fb 00     mov [0xfba854],ecx
80471f: 89 47 60              mov [edi+0x60],eax
804724: 89 47 34              mov [edi+0x34],eax
```
Here `ESI` is allocated transport object; `EDI` is embedded worker pointer. `0xC51748` belongs to `ESI` — **do not use it to resolve `0x80486D`**.

## 3. Round 2 — vtable call correctness and byte-level xref bounds

Source worker entry `0x804740`:
```asm
804768: 8b 5d 08              mov ebx,[ebp+8]
8047b2: 8d 7b 04              lea edi,[ebx+4]
8047b5: b9 0b 00 00 00        mov ecx,0xb
8047ba: 8d 73 30              lea esi,[ebx+0x30]
8047bd: f3 a5                 rep movs dword ptr es:[edi],dword ptr [esi]
8047de: b9 0b 00 00 00        mov ecx,0xb
8047e3: 8d 75 a8              lea esi,[ebp-0x58]
8047e6: 8d 7b 30              lea edi,[ebx+0x30]
8047e9: f3 a5                 rep movs dword ptr es:[edi],dword ptr [esi]
8047f3: 8b 8b 84 00 00 00     mov ecx,[ebx+0x84]
8047fc: 2b 43 10              sub eax,[ebx+0x10]
8047ff: 8d 51 fc              lea edx,[ecx-4]
804802: 3b c2                 cmp eax,edx
804804: 76 0d                 jbe 0x804813
804806: c7 45 ec 04 00 00 00  mov [ebp-0x14],4
80480d: c6 43 58 01           mov byte ptr [ebx+0x58],1
804813: 89 4d ec              mov [ebp-0x14],ecx
```
At `0x804813` note the branch from `0x804811` jumps to `0x804816`; the full path has `0x804813` only for the normal case. This distinction is necessary for the budget rule.

Callback target remains unresolved:
```asm
804852: 8b 75 f0              mov esi,[ebp-0x10]
804858: 8b 13                 mov edx,[ebx]
80485a: 8b 12                 mov edx,[edx]
80485f: 8b 46 04              mov eax,[esi+4]
804862: 51                    push ecx
804863: 50                    push eax
804864: 8d 46 08              lea eax,[esi+8]
804867: 50                    push eax
804868: 8b 06                 mov eax,[esi]
80486a: 50                    push eax
80486b: 8b cb                 mov ecx,ebx
80486d: ff d2                 call edx
80487c: 8b 03                 mov eax,[ebx]
80487e: 8b 50 0c              mov edx,[eax+0xc]
804886: ff d2                 call edx
804890: 8b 03                 mov eax,[ebx]
804898: 8b 40 08              mov eax,[eax+8]
8048a1: ff d0                 call eax
```
These prove virtual offsets 0, +0xC and +0x8, not the pointed-to functions.

Byte scan of raw `.text`: exact direct `lea edi,[ebx+0x140]` pattern `8D BB 40 01 00 00` found only once, at VA `0x48C0E0`. Exact `mov [ebx+0x140],eax` pattern `89 83 40 01 00 00` found at `0x435D6F`, `0x644E53`, but both occur in other objects and are not reliable worker vtable writers:
```asm
435d60: 83 c8 ff              or eax,0xffffffff
435d63: 89 83 38 01 00 00     mov [ebx+0x138],eax
435d69: 89 83 3c 01 00 00     mov [ebx+0x13c],eax
435d6f: 89 83 40 01 00 00     mov [ebx+0x140],eax
644e47: 89 83 38 01 00 00     mov [ebx+0x138],eax
644e4d: 89 83 3c 01 00 00     mov [ebx+0x13c],eax
644e53: 89 83 40 01 00 00     mov [ebx+0x140],eax
```
The first is an -1 field reset, and the second is one of many consecutive field writes. They are not proven related to the `0x491983` parent. This search is only for exact x86 byte forms; other register/memory/indirect initialization forms remain open.

## 4. Round 3 — completion, reclaimed record and outbound-transport separation

Worker post-callback and recycling:
```asm
8048d3: c7 06 00 00 00 00     mov dword ptr [esi],0
8048d9: c7 46 04 00 00 00 00  mov dword ptr [esi+4],0
804942: 6a 10                 push 0x10
804944: e8 1f c9 08 00        call 0x891268
804973: 89 30                 mov [eax],esi
804980: 01 35 a4 33 fe 00     add [0xfe33a4],esi
804986: 29 35 ac 33 fe 00     sub [0xfe33ac],esi
804993: 01 73 50              add [ebx+0x50],esi
8049a5: 8b 45 08              mov eax,[ebp+8]
8049b2: e8 49 f7 ff ff        call 0x804100
8049da: 46                    inc esi
8049de: 83 fe 06              cmp esi,6
8049e1: 0f 8c 3f fe ff ff     jl 0x804826
8049ec: 2b 43 38              sub eax,[ebx+0x38]
8049ef: 3b 45 ec              cmp eax,[ebp-0x14]
8049f2: 0f 97 c1              seta cl
8049f5: 88 4b 59              mov [ebx+0x59],cl
```
**Caveat:** `0x804980`, `0x804986` in this excerpt are located after `mov esi,1` at `0x80497B`: those updates are increments/decrements of **one**, not the original record pointer; `0x804973` stores the record pointer before this reassignment. This prevents an erroneous 'add pointer-valued count' reading. The code also branches on allocation failure `0x80494E→0x804A0C`; no blanket unconditional recycling claim.

The outbound lane is separate: prior T03-11 proves `0x491FDD→0x804A40→0x8061A0`. That evidence cannot be used to assign the inbound worker's `vtable+0`.

## 5. Player scenario and evidence matrix

| Scenario | Client local state | C→S | S→C | UI/world result | Status |
|---|---|---|---|---|---|
| Player selects available role | T03-3 verified role `+0x5C` gate | command `42 00 XX YY` builder, queue / transport as T03-4..6 | actual response opcode and handler unproven | no validated acceptance / refusal / world entry | partial |
| Receive framed bytes in worker bucket | receive frame → FC10D0 queue via T03-7..9 | not applicable | virtual callback `[worker.vtable+0]` receives record, but target unknown | callback result/timing/recycling, game state unknown | bounded native |
| Worker over budget | `worker+0x84`, elapsed, `worker+0x58` and `+0x59` | no new opcode shown | no new opcode shown | scheduling/backpressure flag only | native confirmed |
| Send queue scheduling | T03-11 outbound scheduler | `0x804A40→0x8061A0` | not identified | no asserted game acceptance | prior native |

## 6. Findings, limitations, and follow-up

**Native confirmed in this pass:** parent+0x140 argument provenance, distinct transport vtable installation, worker loop state copy/reset, time-budget flags, indirect callback offsets and conditional recycle counters.

**Unknown:** actual vtable object stored at `parent+0x140`; virtual target at `0x80486D`; business opcode classification; exact Server reply to command 0x42; acceptance/rejection; switch into T05 world; actual wire capture. No runtime trace and no original server.

**Three-round disclosure:** Round 1 inspected parent object creation and `0x804650`; Round 2 examined worker byte-level code and exact-form parent-offset xrefs; Round 3 checked callback post-processing/recycling and distinguished the separate outbound scheduler. The primary requested target remains unresolved. The independently verified new bound is the previously missing scheduling/backpressure state and correction of potential false vtable and pointer/count interpretations. This is research progress, **not completion of the T03 server-response chain**.

**Recommended T03-14:** find parent object's complete constructor/copy/derivation paths, including possible nonstandard worker-vtable initialization; identify the actual table used by `0x80486D`, then inspect callback's protocol domain. Validate against T02 receive dispatcher and T05 transition only after locating native consumer. Do not use local fixture `42→43/69` as proof.

**Git policy:** commit only under `t03/roy/chatgpt-web`; no other task source or owner modified.
