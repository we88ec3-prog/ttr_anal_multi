# T08 087 — Name registry and transform bindings (GitHub evidence summary)
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
Original full local note retained with same filename.

0x007DC3D0 initializes dynamic registry 0x00FE173C, while 0x00FE1740 has separate tree sentinel 0x00FE1744 and vector 0x00FE1750..1758. 0x007DC480 walks first registry and destroys node+0x24 linked objects.

0x007BE150 writes actual transformed values to bound child, not merely local temporaries.

    007BE45A mov eax,[esi+08h]
    007BE465 mov eax,[eax+78h]
    007BE478 mov [eax],ecx
    007BE47E mov [eax+08h],ecx
    007BE4BF mov dword ptr [eax+28h],1
    007BE4F3 call 0077E910

Composed transform also written to storage through +0x74. resource+0x20 calculated via per-child aggregation. Exact meaning unresolved at this stage.
