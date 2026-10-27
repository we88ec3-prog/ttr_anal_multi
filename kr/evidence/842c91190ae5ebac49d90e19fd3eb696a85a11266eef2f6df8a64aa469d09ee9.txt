# T08-092: wrapper update and resource-child virtual dispatch

BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
Author: chatgpt-web roy.

Evidence from direct original-PE objdump disassembly.

## 0x007BDF40: conditional child dispatch
```asm
007BDF49 mov edi,[ebx+08h]
007BDF4C sub edi,[ebx+04h]
007BDF51 sar edi,02h
007BDF60 mov eax,[ebx+04h]
007BDF63 mov eax,[eax+esi*4]
007BDF66 mov ecx,[eax+08h]
007BDF69 test ecx,ecx
007BDF6D cmp byte ptr [eax],00h
007BDF72 cmp dword ptr [ecx+80h],00h
007BDF7D mov edx,[eax]
007BDF7F mov eax,[edx+18h]
007BDF82 call eax
```
It scans DWORD child pointers in [resource+0x04,+0x08). Only when binding +0x08 nonnull, first child byte zero and binding+0x80 zero does it call binding vtable+0x18. It does not read pooled resource+0x20 in this path.

## Wrapper entry 0x007FF8E0
```asm
007FF8E0 mov eax,[ecx+2Ch]
007FF8E3 push eax
007FF8E4 call 007BDF40
007FF8E9 ret
```
wrapper+0x2C is passed as resource argument.

## 0x007BD8D0 resource update
```asm
007FF8B8 mov esi,ecx
007FF8BA mov edi,[esi+2Ch]
007FF8C1 call 007BD8D0
007FF8C6 mov eax,[esi+2Ch]
007FF8C9 cmp dword ptr [eax+6Ch],00h
007FF8D1 call 007BE5B0
007BD8DC fld dword ptr [ebp+08h]
007BD8E0 fmul dword ptr [edi+24h]
007BD8EB fadd dword ptr [edi+1Ch]
007BD8FE fstp dword ptr [edi+1Ch]
007BD9BE fld dword ptr [edi+34h]
007BD9C4 call 00790DC0
007BD9D0 call 00790E90
007BD9DC call 00790F60
007BD9E5 call 00780890
007BDACF fld dword ptr [edi+50h]
007BDAD5 call 00790DC0
007BDAE1 call 00790E90
007BDAED call 00790F60
007BDAF6 call 00780890
```
resource+0x1C is increased by external float argument scaled by resource+0x24. It then constructs numeric/transform intermediary state. Exact semantic name (time/phase/animation progress) unverified; dirty+0x6C handling and full function tail require tracing.

## Unknowns
Actual pooled resource+0x20 reader remains unlocated. Need wrapper virtual callsite, bound child method vtable+0x18 resolution, 0x007BD8D0 trailing branches and field +0x6C semantics. Full on-disk note available with same filename.
