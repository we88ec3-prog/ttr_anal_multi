# T08 088 — Quaternion transform and max aggregate (GitHub evidence summary)
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
Original full local note retained with same filename.

Transform record 0x2C bytes: +0x00..08 translation float3, +0x0C..18 quaternion float4, +0x1C..24 scale float3, +0x28 marker. 0x0077E910 composes transforms with 0x0077E800 quaternion vector rotation and 0x0077E880 Hamilton product. Handedness and parent-child order pending.

    007BE56E fld dword ptr [esp+2Ch]
    007BE572 fld dword ptr [esp+30h]
    007BE576 fcom st(1)
    007BE578 fnstsw ax
    007BE57C test ah,41h
    007BE57F jne 007BE587
    007BE581 fstp dword ptr [esp+2Ch]
    007BE5A4 fstp dword ptr [ebx+20h]

For finite ordered floats this is maximum aggregation to pooled resource +0x20; candidate from binding+0x70, descriptor+0x64 and descriptor+0x40. Real semantic interpretation and division-by-zero handling unknown.
