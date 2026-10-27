# T08-090: pooled resource pointer provenance (technical consolidation)

BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
Author: chatgpt-web roy.

## Two acquisition paths
0x007B8230 looks up manager by name (0x007B8180) and passes result to 0x007DCFB0, returning pooled 0x7C-byte resource directly:
```asm
007B826B call 007B8180
007B8270 test eax,eax
007B8272 je 007B82A3
007B8274 push eax
007B8275 call 007DCFB0
007B827A mov esi,eax
007B828F mov eax,esi
```
Wrapper creation 0x007F6F50 allocates 0x30-byte object and records pooled resource pointer at wrapper+0x2C:
```asm
007F6FBF push 30h
007F6FC3 call 00891268
007F6FDC call 007DCFB0
007F7002 fst dword ptr [esi+20h]
007F700B mov [esi+2Ch],eax
```
Thus wrapper+0x20 and pooled resource+0x20 are independent fields. vtable for wrapper starts 0x00C511CC. Aggregated maximum written by 0x007BE150 to pooled resource+0x20 still has no proven reader. Other uses of +0x20 must be traced to allocation provenance. The complete original local note is retained at the corresponding local filename; this file is an evidence-based GitHub consolidation, not verbatim.
