# T08-091: wrapper virtual methods and pooled resource

BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
Author: chatgpt-web roy.

The wrapper vtable starts at 0x00C511CC. Confirmed entries: +0x00 0x007FF760 (destructor); +0x08 0x007FF8E0; +0x10 0x007FF7D0; +0x14 0x007FF810; +0x18 0x007FF850; +0x1C 0x007FF880; +0x20 0x007FF8B0. Further neighboring entries require RTTI boundary check.

## Ownership
```asm
007F700B mov [esi+2Ch],eax
007FF790 lea esi,[edi+2Ch]
007FF79A call 007BE5F0
```
Constructor places pooled resource in wrapper+0x2C. Destructor passes the slot to detach/release routine 0x007BE5F0, which can return the resource to reuse pool.

## Resource setters
```asm
007FF7E9 mov ecx,[ecx+2Ch]
007FF7EC mov [ecx+28h],edx
007FF7F2 mov [ecx+2Ch],edx
007FF7F8 mov [ecx+30h],eax
007FF7FB mov dword ptr [ecx+70h],1
```
0x007FF810 likewise sets resource+0x34/38/3C; 0x007FF850 updates resource+0x18 and wrapper fields; 0x007FF880 modifies resource+0x1C. Setter paths mark resource+0x70 dirty. 0x007FF8B0 calls 0x007BD8D0 and optionally reset 0x007BE5B0. 0x007FF8E0 forwards resource pointer to 0x007BDF40. None of the checked reads yet proves actual consumption of pooled resource+0x20. Full original local note remains a separate artifact; this upload is technical consolidation.
