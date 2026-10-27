# T08 089 — Resource aggregate reader audit
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91; original machine code from Tartaros.bin.

## Writer confirmed
    007BE56E fld dword ptr [esp+2Ch]
    007BE572 fld dword ptr [esp+30h]
    007BE576 fcom st(1)
    007BE578 fnstsw ax
    007BE57C test ah,41h
    007BE581 fstp dword ptr [esp+2Ch]
    007BE598 jne 007BE390
    007BE5A4 fstp dword ptr [ebx+20h]

## Important false positive separation
    007BEBDF mov eax,[ebx+0Ch]
    007BEBE8 mov eax,[eax+20h]
    007BEC0D call 0077F030

This accesses a field of an object from [ebx+0x0C], not proven to be 0x7C pooled resource.

    007BEE49 push 40h
    007BEE4B call 00891268
    007BEE70 fst dword ptr [eax+20h]
    007BEE98 mov [esi+0Ch],eax

The latter is definitely a different 0x40-byte allocation: same offset does not establish pooled-resource reader.

## Positive trace anchor
    007B826B call 007B8180
    007B8270 test eax,eax
    007B8272 je 007B82A3
    007B8274 push eax
    007B8275 call 007DCFB0
    007B827A mov esi,eax

A second direct 0x007DCFB0 call is at 0x007F6FDC. The real pooled resource+0x20 reader still cannot be reliably identified. Continue alias and stored pointer tracking. No radius/duration label established. Scene vtable+0x20 caller still unresolved.
