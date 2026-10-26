# T08 — global/scene command dispatch and composite record identifier

- Recorder: **chatgpt-web roy**
- Timestamp: **2026-10-26 21:18:52 +08:00** (Asia/Taipei)
- Target: `Tartaros.bin` SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- Evidence: direct x86 disassembly (`objdump -d -Mintel`), not runtime trace.
- Scope: `0x004B7DC0`, `0x004B7EC0`, `0x004ADD50`, `0x004C4670`, `0x004FDA30`, `0x004AE4D0–0x004AE5DD`.

## Dispatch table layout and bounds

`0x004B7DC0` initializes a **global table**, first entry at `0x00FD2CFC`, stride eight, stop address `0x00FD8BA8`, for **(0xFD8BA8 - 0xFD2CFC) / 8 = 3029** entries. Default handler is `0x004B7EC0`; the second dword is set from `0x00BF2375` (shared diagnostic-name pointer).

`0x004ADD50` initializes a **scene-relative table**, 3029 entries of eight bytes, starting at offset `object+0x04` relative to the table base supplied in EAX. The scene dispatcher `0x004C4670` indexes at `scene+0x5EAC+8*index`. The initializer installs `0x004AE4D0` at table-relative `+0x3C`, equivalent to **index 7**.

The *same capacity* does not by itself prove that all message IDs have the same semantics between global and scene tables.

## Confirmed three-argument forwarding

`0x004B7EC0`:
```asm
004B7EC3 cmp DWORD PTR [ecx+0x5EAC],0
004B7ECA je 0x004B7EDA
004B7ECC mov ecx,[ecx+0x5EAC]
004B7ED2 mov eax,[ecx]
004B7ED4 mov eax,[eax+0x04]
004B7ED7 pop ebp
004B7ED8 jmp eax
```
When a scene is present, this function uses tail-jump dispatch and does *not* reconstruct the three incoming stack arguments. The scene's `0x004C4670` then reads `[ebp+0x08]` (data), `[ebp+0x0C]` (length), and `[ebp+0x10]` (command), and pushes them again, calling the indexed handler via `call ebx` at `0x004C46C5`.

Absent a scene, `0x004B7EC0` reports `Received packet from invalid scene. Command #%d` and returns zero.

`0x004FDA30` is an additional table-based fallback dispatcher, also accessing a function and a diagnostic-name pointer at eight-byte stride.

**Limit:** the actual top-level transport/socket receive parser, mapping raw bytes into `data/length/command`, was not established by this step. In particular the first two bytes passed to `0x004AE4D0` cannot yet be conclusively called a network header or command field.

## Batch records and derived composite ID

`0x004AE4D0` reads `buffer` from `[ebp+8]` and `length` from `[ebp+0x0C]`. It computes `floor((length-2)/26)` when length >=2, and starts its EBX cursor at `buffer+6`. Thus current record starts at `EBX-4 = buffer+2+26*i`.

It checks existence with a 16-bit key from `WORD PTR [ebx-4]` (`record+0`) and returns to next record if already found. It also constructs a separate composite identifier:
```asm
004AE5B8 movzx eax,BYTE PTR [ebx-4]  ; record[0] type
004AE5BC movzx edi,BYTE PTR [ebx-2]  ; record[2]
004AE5C0 movzx ecx,WORD PTR [ebx]    ; record[4..5]
004AE5C3 dec edi
004AE5C4 mov edx,eax
004AE5C6 shl edx,8
004AE5C9 or edi,edx
004AE5CB shl edi,16
004AE5CE or edi,ecx
004AE5D0 mov [esp+0x1C],edi
```
Equivalent:
```cpp
uint32_t compositeId = (((uint32_t(record[2]) - 1u) |
                         (uint32_t(record[0]) << 8)) << 16)
                        | ReadUInt16LE(record + 4);
```
Care: the `record[2] - 1` is computed as a full 32-bit operation; if this byte is zero, `dec edi` underflows and the `or`/shift semantics differ from naive 8-bit field packing. Do not silently narrow without confirming valid domain. The composite value is stored to a local stack slot at `[esp+0x1C]`; its ultimate use requires a follow-on dataflow trace.

## Open questions

1. Identify the *global* dispatcher reading the `0x00FD2CFC` table, then the transport's actual decoder and validation boundaries.
2. Decode the semantics of the first two bytes in the command-7 data buffer; confirmed only that the batch record count excludes them.
3. Check record[2] valid range / whether zero is allowed before writing a formal protocol specification.
4. Avoid treating a signed 16-bit scene command index as a security vulnerability without establishing upstream sanitization.

No changes to canonical `kr/`, other tasks, or the original PE.
