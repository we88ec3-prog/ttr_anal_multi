## F-49AF60 VA 0x49af60..0x49aff9 raw 0x9a360 len 153 SHA256 3c372ebc8ff7aedc7be280b89599dbab56f4fcf7be4db2ff3e68eb5eb2876258
0x49af60: 55                               push   ebp
0x49af61: 8bec                             mov    ebp,esp
0x49af63: 6aff                             push   0xffffffff
0x49af65: 68d10a9100                       push   0x910ad1
0x49af6a: 64a100000000                     mov    eax,fs:0x0
0x49af70: 50                               push   eax
0x49af71: 51                               push   ecx
0x49af72: a1201fd600                       mov    eax,ds:0xd61f20
0x49af77: 33c5                             xor    eax,ebp
0x49af79: 50                               push   eax
0x49af7a: 8d45f4                           lea    eax,[ebp-0xc]
0x49af7d: 64a300000000                     mov    fs:0x0,eax
0x49af83: f6050012fc0001                   test   BYTE PTR ds:0xfc1200,0x1
0x49af8a: 7525                             jne    0x49afb1
0x49af8c: 830d0012fc0001                   or     DWORD PTR ds:0xfc1200,0x1
0x49af93: 680812fc00                       push   0xfc1208
0x49af98: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x49af9f: e8bca43600                       call   0x805460
0x49afa4: 6870e6bc00                       push   0xbce670
0x49afa9: e86c733f00                       call   0x89231a
0x49afae: 83c404                           add    esp,0x4
0x49afb1: c70558a8fb000812fc00             mov    DWORD PTR ds:0xfba858,0xfc1208
0x49afbb: c745f00812fc00                   mov    DWORD PTR [ebp-0x10],0xfc1208
0x49afc2: 680812fc00                       push   0xfc1208
0x49afc7: c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0x49afce: e88da43600                       call   0x805460
0x49afd3: 6850af4900                       push   0x49af50
0x49afd8: e83d733f00                       call   0x89231a
0x49afdd: 83c404                           add    esp,0x4
0x49afe0: c7055ca8fb0000000000             mov    DWORD PTR ds:0xfba85c,0x0
0x49afea: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x49afed: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x49aff4: 59                               pop    ecx
0x49aff5: 8be5                             mov    esp,ebp
0x49aff7: 5d                               pop    ebp
0x49aff8: c3                               ret

## F-49B000 VA 0x49b000..0x49b06c raw 0x9a400 len 108 SHA256 69cb1b524aef3b29a5ee056caf336e37a917af1f3fcddf2486ff4bb797f117b2
0x49b000: 55                               push   ebp
0x49b001: 8bec                             mov    ebp,esp
0x49b003: 6aff                             push   0xffffffff
0x49b005: 68fedb9000                       push   0x90dbfe
0x49b00a: 64a100000000                     mov    eax,fs:0x0
0x49b010: 50                               push   eax
0x49b011: a1201fd600                       mov    eax,ds:0xd61f20
0x49b016: 33c5                             xor    eax,ebp
0x49b018: 50                               push   eax
0x49b019: 8d45f4                           lea    eax,[ebp-0xc]
0x49b01c: 64a300000000                     mov    fs:0x0,eax
0x49b022: b801000000                       mov    eax,0x1
0x49b027: 84050012fc00                     test   BYTE PTR ds:0xfc1200,al
0x49b02d: 7524                             jne    0x49b053
0x49b02f: 09050012fc00                     or     DWORD PTR ds:0xfc1200,eax
0x49b035: 680812fc00                       push   0xfc1208
0x49b03a: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x49b041: e81aa43600                       call   0x805460
0x49b046: 6870e6bc00                       push   0xbce670
0x49b04b: e8ca723f00                       call   0x89231a
0x49b050: 83c404                           add    esp,0x4
0x49b053: c70558a8fb000812fc00             mov    DWORD PTR ds:0xfba858,0xfc1208
0x49b05d: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x49b060: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x49b067: 59                               pop    ecx
0x49b068: 8be5                             mov    esp,ebp
0x49b06a: 5d                               pop    ebp
0x49b06b: c3                               ret

## F-804A40 VA 0x804a40..0x804c70 raw 0x403e40 len 560 SHA256 305179cf6c3dacf44de732f344f8cb2e1bd9a2cda3e16af2ad66836aadcbb066
0x804a40: 55                               push   ebp
0x804a41: 8bec                             mov    ebp,esp
0x804a43: 83ec18                           sub    esp,0x18
0x804a46: 53                               push   ebx
0x804a47: 8b1da025bd00                     mov    ebx,DWORD PTR ds:0xbd25a0
0x804a4d: 56                               push   esi
0x804a4e: 57                               push   edi
0x804a4f: ffd3                             call   ebx
0x804a51: 833d58a8fb0000                   cmp    DWORD PTR ds:0xfba858,0x0
0x804a58: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x804a5b: 894748                           mov    DWORD PTR [edi+0x48],eax
0x804a5e: 7515                             jne    0x804a75
0x804a60: 833d5ca8fb0000                   cmp    DWORD PTR ds:0xfba85c,0x0
0x804a67: 7407                             je     0x804a70
0x804a69: e8f264c9ff                       call   0x49af60
0x804a6e: eb05                             jmp    0x804a75
0x804a70: e88b65c9ff                       call   0x49b000
0x804a75: 8b3558a8fb00                     mov    esi,DWORD PTR ds:0xfba858
0x804a7b: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x804a7e: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x804a85: ffd3                             call   ebx
0x804a87: 8b8f88000000                     mov    ecx,DWORD PTR [edi+0x88]
0x804a8d: 2bc8                             sub    ecx,eax
0x804a8f: bb01000000                       mov    ebx,0x1
0x804a94: 83f921                           cmp    ecx,0x21
0x804a97: 7609                             jbe    0x804aa2
0x804a99: 898788000000                     mov    DWORD PTR [edi+0x88],eax
0x804a9f: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x804aa2: 8b7e04                           mov    edi,DWORD PTR [esi+0x4]
0x804aa5: 2b3e                             sub    edi,DWORD PTR [esi]
0x804aa7: 33c0                             xor    eax,eax
0x804aa9: c1ff02                           sar    edi,0x2
0x804aac: 897df8                           mov    DWORD PTR [ebp-0x8],edi
0x804aaf: 8945f4                           mov    DWORD PTR [ebp-0xc],eax
0x804ab2: 85ff                             test   edi,edi
0x804ab4: 0f84a1010000                     je     0x804c5b
0x804aba: eb07                             jmp    0x804ac3
0x804abc: 8d642400                         lea    esp,[esp+0x0]
0x804ac0: 8b75f0                           mov    esi,DWORD PTR [ebp-0x10]
0x804ac3: 8b16                             mov    edx,DWORD PTR [esi]
0x804ac5: 8b3482                           mov    esi,DWORD PTR [edx+eax*4]
0x804ac8: 83beaca0000000                   cmp    DWORD PTR [esi+0xa0ac],0x0
0x804acf: 0f8476010000                     je     0x804c4b
0x804ad5: 56                               push   esi
0x804ad6: e8c5160000                       call   0x8061a0
0x804adb: 85c0                             test   eax,eax
0x804add: 7428                             je     0x804b07
0x804adf: 8b86a4a00000                     mov    eax,DWORD PTR [esi+0xa0a4]
0x804ae5: 019e94a00000                     add    DWORD PTR [esi+0xa094],ebx
0x804aeb: 83f805                           cmp    eax,0x5
0x804aee: 730c                             jae    0x804afc
0x804af0: c786a4a0000000000000             mov    DWORD PTR [esi+0xa0a4],0x0
0x804afa: eb1e                             jmp    0x804b1a
0x804afc: 83c0fb                           add    eax,0xfffffffb
0x804aff: 8986a4a00000                     mov    DWORD PTR [esi+0xa0a4],eax
0x804b05: eb13                             jmp    0x804b1a
0x804b07: 837dfc00                         cmp    DWORD PTR [ebp-0x4],0x0
0x804b0b: 740d                             je     0x804b1a
0x804b0d: 019e84a00000                     add    DWORD PTR [esi+0xa084],ebx
0x804b13: 8386a4a0000005                   add    DWORD PTR [esi+0xa0a4],0x5
0x804b1a: c745ec00000000                   mov    DWORD PTR [ebp-0x14],0x0
0x804b21: 83be28a0000000                   cmp    DWORD PTR [esi+0xa028],0x0
0x804b28: 0f841d010000                     je     0x804c4b
0x804b2e: 8b86b8a00000                     mov    eax,DWORD PTR [esi+0xa0b8]
0x804b34: 85c0                             test   eax,eax
0x804b36: 0f8f0f010000                     jg     0x804c4b
0x804b3c: 8b8628a00000                     mov    eax,DWORD PTR [esi+0xa028]
0x804b42: 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x804b48: 8b11                             mov    edx,DWORD PTR [ecx]
0x804b4a: 8b520c                           mov    edx,DWORD PTR [edx+0xc]
0x804b4d: 8d7dec                           lea    edi,[ebp-0x14]
0x804b50: 57                               push   edi
0x804b51: 50                               push   eax
0x804b52: 8d8620500000                     lea    eax,[esi+0x5020]
0x804b58: 50                               push   eax
0x804b59: 56                               push   esi
0x804b5a: ffd2                             call   edx
0x804b5c: 85c0                             test   eax,eax
0x804b5e: 751c                             jne    0x804b7c
0x804b60: 56                               push   esi
0x804b61: e87a180000                       call   0x8063e0
0x804b66: 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x804b6c: 8b01                             mov    eax,DWORD PTR [ecx]
0x804b6e: 8b5024                           mov    edx,DWORD PTR [eax+0x24]
0x804b71: 6a00                             push   0x0
0x804b73: 56                               push   esi
0x804b74: ffd2                             call   edx
0x804b76: 899ea8a00000                     mov    DWORD PTR [esi+0xa0a8],ebx
0x804b7c: 83beb0a0000000                   cmp    DWORD PTR [esi+0xa0b0],0x0
0x804b83: 7416                             je     0x804b9b
0x804b85: 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x804b8b: 8b01                             mov    eax,DWORD PTR [ecx]
0x804b8d: 8b5024                           mov    edx,DWORD PTR [eax+0x24]
0x804b90: 6a00                             push   0x0
0x804b92: 56                               push   esi
0x804b93: ffd2                             call   edx
0x804b95: 899ea8a00000                     mov    DWORD PTR [esi+0xa0a8],ebx
0x804b9b: 81bea4a000002c010000             cmp    DWORD PTR [esi+0xa0a4],0x12c
0x804ba5: 0f8e9d000000                     jle    0x804c48
0x804bab: 83bea8a0000000                   cmp    DWORD PTR [esi+0xa0a8],0x0
0x804bb2: 0f8590000000                     jne    0x804c48
0x804bb8: 56                               push   esi
0x804bb9: e822180000                       call   0x8063e0
0x804bbe: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x804bc1: 8bb88c000000                     mov    edi,DWORD PTR [eax+0x8c]
0x804bc7: 85ff                             test   edi,edi
0x804bc9: 7451                             je     0x804c1c
0x804bcb: 8b8ea0a00000                     mov    ecx,DWORD PTR [esi+0xa0a0]
0x804bd1: 8b9690a00000                     mov    edx,DWORD PTR [esi+0xa090]
0x804bd7: 8b869ca00000                     mov    eax,DWORD PTR [esi+0xa09c]
0x804bdd: 51                               push   ecx
0x804bde: 8b8e8ca00000                     mov    ecx,DWORD PTR [esi+0xa08c]
0x804be4: 52                               push   edx
0x804be5: 8b9698a00000                     mov    edx,DWORD PTR [esi+0xa098]
0x804beb: 50                               push   eax
0x804bec: 8b8688a00000                     mov    eax,DWORD PTR [esi+0xa088]
0x804bf2: 51                               push   ecx
0x804bf3: 8b8e94a00000                     mov    ecx,DWORD PTR [esi+0xa094]
0x804bf9: 52                               push   edx
0x804bfa: 8b9684a00000                     mov    edx,DWORD PTR [esi+0xa084]
0x804c00: 50                               push   eax
0x804c01: 8b86a4a00000                     mov    eax,DWORD PTR [esi+0xa0a4]
0x804c07: 51                               push   ecx
0x804c08: 8b0e                             mov    ecx,DWORD PTR [esi]
0x804c0a: 52                               push   edx
0x804c0b: 50                               push   eax
0x804c0c: 51                               push   ecx
0x804c0d: 683814c500                       push   0xc51438
0x804c12: 6a02                             push   0x2
0x804c14: e8e7b7eeff                       call   0x6f0400
0x804c19: 83c430                           add    esp,0x30
0x804c1c: 83beb4a0000002                   cmp    DWORD PTR [esi+0xa0b4],0x2
0x804c23: 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x804c29: 8b11                             mov    edx,DWORD PTR [ecx]
0x804c2b: 750d                             jne    0x804c3a
0x804c2d: 8b421c                           mov    eax,DWORD PTR [edx+0x1c]
0x804c30: 56                               push   esi
0x804c31: ffd0                             call   eax
0x804c33: e8d8130000                       call   0x806010
0x804c38: eb08                             jmp    0x804c42
0x804c3a: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x804c3d: 6a00                             push   0x0
0x804c3f: 56                               push   esi
0x804c40: ffd0                             call   eax
0x804c42: 899ea8a00000                     mov    DWORD PTR [esi+0xa0a8],ebx
0x804c48: 8b7df8                           mov    edi,DWORD PTR [ebp-0x8]
0x804c4b: 8b45f4                           mov    eax,DWORD PTR [ebp-0xc]
0x804c4e: 03c3                             add    eax,ebx
0x804c50: 8945f4                           mov    DWORD PTR [ebp-0xc],eax
0x804c53: 3bc7                             cmp    eax,edi
0x804c55: 0f8265feffff                     jb     0x804ac0
0x804c5b: ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x804c61: 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x804c64: 5f                               pop    edi
0x804c65: 5e                               pop    esi
0x804c66: 89414c                           mov    DWORD PTR [ecx+0x4c],eax
0x804c69: 5b                               pop    ebx
0x804c6a: 8be5                             mov    esp,ebp
0x804c6c: 5d                               pop    ebp
0x804c6d: c20400                           ret    0x4

## F-804FC0 VA 0x804fc0..0x805187 raw 0x4043c0 len 455 SHA256 2c670dc75cd0583e9511ac39db285f10dc03a6284308d0d598fac4df5e62ae9f
0x804fc0: 55                               push   ebp
0x804fc1: 8bec                             mov    ebp,esp
0x804fc3: 83ec40                           sub    esp,0x40
0x804fc6: 53                               push   ebx
0x804fc7: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x804fca: 8b4b44                           mov    ecx,DWORD PTR [ebx+0x44]
0x804fcd: 2b4b40                           sub    ecx,DWORD PTR [ebx+0x40]
0x804fd0: 8b534c                           mov    edx,DWORD PTR [ebx+0x4c]
0x804fd3: 014b68                           add    DWORD PTR [ebx+0x68],ecx
0x804fd6: 8b4b50                           mov    ecx,DWORD PTR [ebx+0x50]
0x804fd9: 014b74                           add    DWORD PTR [ebx+0x74],ecx
0x804fdc: ff435c                           inc    DWORD PTR [ebx+0x5c]
0x804fdf: 56                               push   esi
0x804fe0: 8b733c                           mov    esi,DWORD PTR [ebx+0x3c]
0x804fe3: 8bc6                             mov    eax,esi
0x804fe5: 2b4338                           sub    eax,DWORD PTR [ebx+0x38]
0x804fe8: 33c9                             xor    ecx,ecx
0x804fea: 014364                           add    DWORD PTR [ebx+0x64],eax
0x804fed: 8b4348                           mov    eax,DWORD PTR [ebx+0x48]
0x804ff0: 2bd0                             sub    edx,eax
0x804ff2: 01536c                           add    DWORD PTR [ebx+0x6c],edx
0x804ff5: 8b5354                           mov    edx,DWORD PTR [ebx+0x54]
0x804ff8: 015378                           add    DWORD PTR [ebx+0x78],edx
0x804ffb: 384b59                           cmp    BYTE PTR [ebx+0x59],cl
0x804ffe: 57                               push   edi
0x804fff: 0f95c1                           setne  cl
0x805002: 33d2                             xor    edx,edx
0x805004: 014b7c                           add    DWORD PTR [ebx+0x7c],ecx
0x805007: 385358                           cmp    BYTE PTR [ebx+0x58],dl
0x80500a: 0f95c2                           setne  dl
0x80500d: 2bc6                             sub    eax,esi
0x80500f: 014370                           add    DWORD PTR [ebx+0x70],eax
0x805012: 019380000000                     add    DWORD PTR [ebx+0x80],edx
0x805018: ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x80501e: 8bc8                             mov    ecx,eax
0x805020: 2b4b60                           sub    ecx,DWORD PTR [ebx+0x60]
0x805023: 8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x805026: 81f930750000                     cmp    ecx,0x7530
0x80502c: 0f864c010000                     jbe    0x80517e
0x805032: 8b535c                           mov    edx,DWORD PTR [ebx+0x5c]
0x805035: 33f6                             xor    esi,esi
0x805037: 3bd6                             cmp    edx,esi
0x805039: 0f8611010000                     jbe    0x805150
0x80503f: 8bfa                             mov    edi,edx
0x805041: 897d08                           mov    DWORD PTR [ebp+0x8],edi
0x805044: db4508                           fild   DWORD PTR [ebp+0x8]
0x805047: 85ff                             test   edi,edi
0x805049: 7906                             jns    0x805051
0x80504b: d8058056c500                     fadd   DWORD PTR ds:0xc55680
0x805051: 8b7b64                           mov    edi,DWORD PTR [ebx+0x64]
0x805054: d95d08                           fstp   DWORD PTR [ebp+0x8]
0x805057: db4364                           fild   DWORD PTR [ebx+0x64]
0x80505a: 85ff                             test   edi,edi
0x80505c: 7906                             jns    0x805064
0x80505e: d8058056c500                     fadd   DWORD PTR ds:0xc55680
0x805064: d94508                           fld    DWORD PTR [ebp+0x8]
0x805067: 8b7b68                           mov    edi,DWORD PTR [ebx+0x68]
0x80506a: d9c0                             fld    st(0)
0x80506c: defa                             fdivp  st(2),st
0x80506e: d9c9                             fxch   st(1)
0x805070: d95df4                           fstp   DWORD PTR [ebp-0xc]
0x805073: db4368                           fild   DWORD PTR [ebx+0x68]
0x805076: 85ff                             test   edi,edi
0x805078: 7906                             jns    0x805080
0x80507a: d8058056c500                     fadd   DWORD PTR ds:0xc55680
0x805080: d8f1                             fdiv   st,st(1)
0x805082: 8b7b6c                           mov    edi,DWORD PTR [ebx+0x6c]
0x805085: d95df8                           fstp   DWORD PTR [ebp-0x8]
0x805088: db436c                           fild   DWORD PTR [ebx+0x6c]
0x80508b: 85ff                             test   edi,edi
0x80508d: 7906                             jns    0x805095
0x80508f: d8058056c500                     fadd   DWORD PTR ds:0xc55680
0x805095: d8f1                             fdiv   st,st(1)
0x805097: 8b7b70                           mov    edi,DWORD PTR [ebx+0x70]
0x80509a: d95d08                           fstp   DWORD PTR [ebp+0x8]
0x80509d: db4370                           fild   DWORD PTR [ebx+0x70]
0x8050a0: 85ff                             test   edi,edi
0x8050a2: 7906                             jns    0x8050aa
0x8050a4: d8058056c500                     fadd   DWORD PTR ds:0xc55680
0x8050aa: def1                             fdivrp st(1),st
0x8050ac: 8bbb8c000000                     mov    edi,DWORD PTR [ebx+0x8c]
0x8050b2: d95df0                           fstp   DWORD PTR [ebp-0x10]
0x8050b5: 3bfe                             cmp    edi,esi
0x8050b7: 0f8493000000                     je     0x805150
0x8050bd: 52                               push   edx
0x8050be: 51                               push   ecx
0x8050bf: 50                               push   eax
0x8050c0: 68bc14c500                       push   0xc514bc
0x8050c5: 56                               push   esi
0x8050c6: e835b3eeff                       call   0x6f0400
0x8050cb: 8b8380000000                     mov    eax,DWORD PTR [ebx+0x80]
0x8050d1: 8b4b7c                           mov    ecx,DWORD PTR [ebx+0x7c]
0x8050d4: 8b5368                           mov    edx,DWORD PTR [ebx+0x68]
0x8050d7: 8bbb8c000000                     mov    edi,DWORD PTR [ebx+0x8c]
0x8050dd: 83c414                           add    esp,0x14
0x8050e0: 50                               push   eax
0x8050e1: 8b4378                           mov    eax,DWORD PTR [ebx+0x78]
0x8050e4: 51                               push   ecx
0x8050e5: 8b4b64                           mov    ecx,DWORD PTR [ebx+0x64]
0x8050e8: 52                               push   edx
0x8050e9: 8b5374                           mov    edx,DWORD PTR [ebx+0x74]
0x8050ec: 50                               push   eax
0x8050ed: 51                               push   ecx
0x8050ee: 52                               push   edx
0x8050ef: 68e814c500                       push   0xc514e8
0x8050f4: 6a00                             push   0x0
0x8050f6: e805b3eeff                       call   0x6f0400
0x8050fb: d94508                           fld    DWORD PTR [ebp+0x8]
0x8050fe: 8bbb8c000000                     mov    edi,DWORD PTR [ebx+0x8c]
0x805104: dd5c2418                         fstp   QWORD PTR [esp+0x18]
0x805108: d945f8                           fld    DWORD PTR [ebp-0x8]
0x80510b: 83c408                           add    esp,0x8
0x80510e: dd5c2408                         fstp   QWORD PTR [esp+0x8]
0x805112: d945f4                           fld    DWORD PTR [ebp-0xc]
0x805115: dd1c24                           fstp   QWORD PTR [esp]
0x805118: 685015c500                       push   0xc51550
0x80511d: 6a00                             push   0x0
0x80511f: e8dcb2eeff                       call   0x6f0400
0x805124: d945f0                           fld    DWORD PTR [ebp-0x10]
0x805127: 8b4370                           mov    eax,DWORD PTR [ebx+0x70]
0x80512a: dd5c2418                         fstp   QWORD PTR [esp+0x18]
0x80512e: 8b4b6c                           mov    ecx,DWORD PTR [ebx+0x6c]
0x805131: 8bbb8c000000                     mov    edi,DWORD PTR [ebx+0x8c]
0x805137: 83c418                           add    esp,0x18
0x80513a: 50                               push   eax
0x80513b: 51                               push   ecx
0x80513c: 68ac15c500                       push   0xc515ac
0x805141: 6a00                             push   0x0
0x805143: e8b8b2eeff                       call   0x6f0400
0x805148: 8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
0x80514b: 83c418                           add    esp,0x18
0x80514e: 33f6                             xor    esi,esi
0x805150: 8975c4                           mov    DWORD PTR [ebp-0x3c],esi
0x805153: 8975c8                           mov    DWORD PTR [ebp-0x38],esi
0x805156: 8975cc                           mov    DWORD PTR [ebp-0x34],esi
0x805159: 8975d0                           mov    DWORD PTR [ebp-0x30],esi
0x80515c: 8975d4                           mov    DWORD PTR [ebp-0x2c],esi
0x80515f: 8975d8                           mov    DWORD PTR [ebp-0x28],esi
0x805162: 8975dc                           mov    DWORD PTR [ebp-0x24],esi
0x805165: 8975e0                           mov    DWORD PTR [ebp-0x20],esi
0x805168: 8975e4                           mov    DWORD PTR [ebp-0x1c],esi
0x80516b: 8975e8                           mov    DWORD PTR [ebp-0x18],esi
0x80516e: b90a000000                       mov    ecx,0xa
0x805173: 8d75c4                           lea    esi,[ebp-0x3c]
0x805176: 8d7b5c                           lea    edi,[ebx+0x5c]
0x805179: f3a5                             rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x80517b: 894360                           mov    DWORD PTR [ebx+0x60],eax
0x80517e: 5f                               pop    edi
0x80517f: 5e                               pop    esi
0x805180: 5b                               pop    ebx
0x805181: 8be5                             mov    esp,ebp
0x805183: 5d                               pop    ebp
0x805184: c20400                           ret    0x4

## F-805460 VA 0x805460..0x8055bf raw 0x404860 len 351 SHA256 5b1a07c2b21122a0e74faaaa1bf97dd38e5bd0e8111e72223b51d5f1e396d0f4
0x805460: 55                               push   ebp
0x805461: 8bec                             mov    ebp,esp
0x805463: 6aff                             push   0xffffffff
0x805465: 685e529000                       push   0x90525e
0x80546a: 64a100000000                     mov    eax,fs:0x0
0x805470: 50                               push   eax
0x805471: 83ec20                           sub    esp,0x20
0x805474: 53                               push   ebx
0x805475: 56                               push   esi
0x805476: 57                               push   edi
0x805477: a1201fd600                       mov    eax,ds:0xd61f20
0x80547c: 33c5                             xor    eax,ebp
0x80547e: 50                               push   eax
0x80547f: 8d45f4                           lea    eax,[ebp-0xc]
0x805482: 64a300000000                     mov    fs:0x0,eax
0x805488: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x80548b: 33db                             xor    ebx,ebx
0x80548d: 891e                             mov    DWORD PTR [esi],ebx
0x80548f: 895e04                           mov    DWORD PTR [esi+0x4],ebx
0x805492: 895e08                           mov    DWORD PTR [esi+0x8],ebx
0x805495: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x805498: 8d7e10                           lea    edi,[esi+0x10]
0x80549b: 6a08                             push   0x8
0x80549d: 891f                             mov    DWORD PTR [edi],ebx
0x80549f: e8c4bd0800                       call   0x891268
0x8054a4: 83c404                           add    esp,0x4
0x8054a7: 3bc3                             cmp    eax,ebx
0x8054a9: 0f84ec000000                     je     0x80559b
0x8054af: 8907                             mov    DWORD PTR [edi],eax
0x8054b1: 33c9                             xor    ecx,ecx
0x8054b3: 8908                             mov    DWORD PTR [eax],ecx
0x8054b5: 33d2                             xor    edx,edx
0x8054b7: 895004                           mov    DWORD PTR [eax+0x4],edx
0x8054ba: 8b07                             mov    eax,DWORD PTR [edi]
0x8054bc: 8938                             mov    DWORD PTR [eax],edi
0x8054be: 895f04                           mov    DWORD PTR [edi+0x4],ebx
0x8054c1: 895f08                           mov    DWORD PTR [edi+0x8],ebx
0x8054c4: 895f0c                           mov    DWORD PTR [edi+0xc],ebx
0x8054c7: 895f10                           mov    DWORD PTR [edi+0x10],ebx
0x8054ca: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x8054ce: 6a0c                             push   0xc
0x8054d0: 895e2c                           mov    DWORD PTR [esi+0x2c],ebx
0x8054d3: e890bd0800                       call   0x891268
0x8054d8: 83c404                           add    esp,0x4
0x8054db: 3bc3                             cmp    eax,ebx
0x8054dd: 0f8494000000                     je     0x805577
0x8054e3: 894628                           mov    DWORD PTR [esi+0x28],eax
0x8054e6: 8900                             mov    DWORD PTR [eax],eax
0x8054e8: 8b4628                           mov    eax,DWORD PTR [esi+0x28]
0x8054eb: 894004                           mov    DWORD PTR [eax+0x4],eax
0x8054ee: 6a18                             push   0x18
0x8054f0: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x8054f4: e86fbd0800                       call   0x891268
0x8054f9: 8bf8                             mov    edi,eax
0x8054fb: 83c404                           add    esp,0x4
0x8054fe: 3bfb                             cmp    edi,ebx
0x805500: 740e                             je     0x805510
0x805502: 68a00f0000                       push   0xfa0
0x805507: 57                               push   edi
0x805508: ff152c22bd00                     call   DWORD PTR ds:0xbd222c
0x80550e: eb02                             jmp    0x805512
0x805510: 33ff                             xor    edi,edi
0x805512: 897e34                           mov    DWORD PTR [esi+0x34],edi
0x805515: 895e38                           mov    DWORD PTR [esi+0x38],ebx
0x805518: 895e3c                           mov    DWORD PTR [esi+0x3c],ebx
0x80551b: 895e40                           mov    DWORD PTR [esi+0x40],ebx
0x80551e: 895e44                           mov    DWORD PTR [esi+0x44],ebx
0x805521: 6a0c                             push   0xc
0x805523: 895e4c                           mov    DWORD PTR [esi+0x4c],ebx
0x805526: e83dbd0800                       call   0x891268
0x80552b: 83c404                           add    esp,0x4
0x80552e: 3bc3                             cmp    eax,ebx
0x805530: 7421                             je     0x805553
0x805532: 894648                           mov    DWORD PTR [esi+0x48],eax
0x805535: 8900                             mov    DWORD PTR [eax],eax
0x805537: 8b4648                           mov    eax,DWORD PTR [esi+0x48]
0x80553a: 894004                           mov    DWORD PTR [eax+0x4],eax
0x80553d: 8bc6                             mov    eax,esi
0x80553f: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x805542: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x805549: 59                               pop    ecx
0x80554a: 5f                               pop    edi
0x80554b: 5e                               pop    esi
0x80554c: 5b                               pop    ebx
0x80554d: 8be5                             mov    esp,ebp
0x80554f: 5d                               pop    ebp
0x805550: c20400                           ret    0x4
0x805553: 8d4df0                           lea    ecx,[ebp-0x10]
0x805556: 51                               push   ecx
0x805557: 8d4de0                           lea    ecx,[ebp-0x20]
0x80555a: 895df0                           mov    DWORD PTR [ebp-0x10],ebx
0x80555d: e847bb0800                       call   0x8910a9
0x805562: 68a857c800                       push   0xc857a8
0x805567: 8d55e0                           lea    edx,[ebp-0x20]
0x80556a: 52                               push   edx
0x80556b: c745e0a42cbd00                   mov    DWORD PTR [ebp-0x20],0xbd2ca4
0x805572: e879740900                       call   0x89c9f0
0x805577: 8d45ec                           lea    eax,[ebp-0x14]
0x80557a: 50                               push   eax
0x80557b: 8d4dd4                           lea    ecx,[ebp-0x2c]
0x80557e: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x805581: e823bb0800                       call   0x8910a9
0x805586: 68a857c800                       push   0xc857a8
0x80558b: 8d4dd4                           lea    ecx,[ebp-0x2c]
0x80558e: 51                               push   ecx
0x80558f: c745d4a42cbd00                   mov    DWORD PTR [ebp-0x2c],0xbd2ca4
0x805596: e855740900                       call   0x89c9f0
0x80559b: 8d55f0                           lea    edx,[ebp-0x10]
0x80559e: 52                               push   edx
0x80559f: 8d4de0                           lea    ecx,[ebp-0x20]
0x8055a2: 895df0                           mov    DWORD PTR [ebp-0x10],ebx
0x8055a5: e8ffba0800                       call   0x8910a9
0x8055aa: 68a857c800                       push   0xc857a8
0x8055af: 8d45e0                           lea    eax,[ebp-0x20]
0x8055b2: 50                               push   eax
0x8055b3: c745e0a42cbd00                   mov    DWORD PTR [ebp-0x20],0xbd2ca4
0x8055ba: e831740900                       call   0x89c9f0

## F-587480 VA 0x587480..0x58771d raw 0x186880 len 669 SHA256 4eaa6696af50a0a3deaedca898541cd92500622f50f1fad110dbc74a356b7583
0x587480: 55                               push   ebp
0x587481: 8bec                             mov    ebp,esp
0x587483: 6aff                             push   0xffffffff
0x587485: 68d3199200                       push   0x9219d3
0x58748a: 64a100000000                     mov    eax,fs:0x0
0x587490: 50                               push   eax
0x587491: 83ec60                           sub    esp,0x60
0x587494: a1201fd600                       mov    eax,ds:0xd61f20
0x587499: 33c5                             xor    eax,ebp
0x58749b: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x58749e: 53                               push   ebx
0x58749f: 56                               push   esi
0x5874a0: 50                               push   eax
0x5874a1: 8d45f4                           lea    eax,[ebp-0xc]
0x5874a4: 64a300000000                     mov    fs:0x0,eax
0x5874aa: 33db                             xor    ebx,ebx
0x5874ac: c74598d8adfa00                   mov    DWORD PTR [ebp-0x68],0xfaadd8
0x5874b3: 891ddcadfa00                     mov    DWORD PTR ds:0xfaaddc,ebx
0x5874b9: 891de0adfa00                     mov    DWORD PTR ds:0xfaade0,ebx
0x5874bf: 891de4adfa00                     mov    DWORD PTR ds:0xfaade4,ebx
0x5874c5: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x5874c8: 6800010000                       push   0x100
0x5874cd: 83ceff                           or     esi,0xffffffff
0x5874d0: 53                               push   ebx
0x5874d1: 6814aefa00                       push   0xfaae14
0x5874d6: 8935ecadfa00                     mov    DWORD PTR ds:0xfaadec,esi
0x5874dc: 8935f0adfa00                     mov    DWORD PTR ds:0xfaadf0,esi
0x5874e2: 891df4adfa00                     mov    DWORD PTR ds:0xfaadf4,ebx
0x5874e8: 66891df8adfa00                   mov    WORD PTR ds:0xfaadf8,bx
0x5874ef: 881dfaadfa00                     mov    BYTE PTR ds:0xfaadfa,bl
0x5874f5: e866733100                       call   0x89e860
0x5874fa: 83c40c                           add    esp,0xc
0x5874fd: f6059069fe0001                   test   BYTE PTR ds:0xfe6990,0x1
0x587504: 893530affa00                     mov    DWORD PTR ds:0xfaaf30,esi
0x58750a: 891d1caffa00                     mov    DWORD PTR ds:0xfaaf1c,ebx
0x587510: 891d18affa00                     mov    DWORD PTR ds:0xfaaf18,ebx
0x587516: 891d14affa00                     mov    DWORD PTR ds:0xfaaf14,ebx
0x58751c: 66891d20affa00                   mov    WORD PTR ds:0xfaaf20,bx
0x587523: 881d22affa00                     mov    BYTE PTR ds:0xfaaf22,bl
0x587529: 66891d23affa00                   mov    WORD PTR ds:0xfaaf23,bx
0x587530: 881d25affa00                     mov    BYTE PTR ds:0xfaaf25,bl
0x587536: c60528affa00ff                   mov    BYTE PTR ds:0xfaaf28,0xff
0x58753d: 8d7301                           lea    esi,[ebx+0x1]
0x587540: 7510                             jne    0x587552
0x587542: 09359069fe00                     or     DWORD PTR ds:0xfe6990,esi
0x587548: c7054035fe00b095c100             mov    DWORD PTR ds:0xfe3540,0xc195b0
0x587552: f6059028fe0001                   test   BYTE PTR ds:0xfe2890,0x1
0x587559: 751f                             jne    0x58757a
0x58755b: 09359028fe00                     or     DWORD PTR ds:0xfe2890,esi
0x587561: f605e837fe0001                   test   BYTE PTR ds:0xfe37e8,0x1
0x587568: 7510                             jne    0x58757a
0x58756a: 0935e837fe00                     or     DWORD PTR ds:0xfe37e8,esi
0x587570: c705e437fe0038d9c400             mov    DWORD PTR ds:0xfe37e4,0xc4d938
0x58757a: f605d0adfa0001                   test   BYTE PTR ds:0xfaadd0,0x1
0x587581: c7059428fe004035fe00             mov    DWORD PTR ds:0xfe2894,0xfe3540
0x58758b: 751f                             jne    0x5875ac
0x58758d: 0935d0adfa00                     or     DWORD PTR ds:0xfaadd0,esi
0x587593: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x587597: e8f4631c00                       call   0x74d990
0x58759c: 6870ccbc00                       push   0xbccc70
0x5875a1: e874ad3000                       call   0x89231a
0x5875a6: 83c404                           add    esp,0x4
0x5875a9: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x5875ac: c705fcadfa001048f900             mov    DWORD PTR ds:0xfaadfc,0xf94810
0x5875b6: e8257ee9ff                       call   0x41f3e0
0x5875bb: 6a14                             push   0x14
0x5875bd: a30caefa00                       mov    ds:0xfaae0c,eax
0x5875c2: e8a19c3000                       call   0x891268
0x5875c7: 83c404                           add    esp,0x4
0x5875ca: 89459c                           mov    DWORD PTR [ebp-0x64],eax
0x5875cd: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x5875d1: 3bc3                             cmp    eax,ebx
0x5875d3: 7408                             je     0x5875dd
0x5875d5: 50                               push   eax
0x5875d6: e8058c1e00                       call   0x7701e0
0x5875db: eb02                             jmp    0x5875df
0x5875dd: 33c0                             xor    eax,eax
0x5875df: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x5875e2: 6a2c                             push   0x2c
0x5875e4: a304aefa00                       mov    ds:0xfaae04,eax
0x5875e9: e87a9c3000                       call   0x891268
0x5875ee: 83c404                           add    esp,0x4
0x5875f1: 89459c                           mov    DWORD PTR [ebp-0x64],eax
0x5875f4: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x5875f8: 3bc3                             cmp    eax,ebx
0x5875fa: 7408                             je     0x587604
0x5875fc: 50                               push   eax
0x5875fd: e8ee8d1e00                       call   0x7703f0
0x587602: eb02                             jmp    0x587606
0x587604: 33c0                             xor    eax,eax
0x587606: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x587609: 6a14                             push   0x14
0x58760b: a308aefa00                       mov    ds:0xfaae08,eax
0x587610: e8539c3000                       call   0x891268
0x587615: 83c404                           add    esp,0x4
0x587618: 89459c                           mov    DWORD PTR [ebp-0x64],eax
0x58761b: c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x58761f: 3bc3                             cmp    eax,ebx
0x587621: 7408                             je     0x58762b
0x587623: 50                               push   eax
0x587624: e877971e00                       call   0x770da0
0x587629: eb02                             jmp    0x58762d
0x58762b: 33c0                             xor    eax,eax
0x58762d: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x587630: 6a58                             push   0x58
0x587632: a300aefa00                       mov    ds:0xfaae00,eax
0x587637: e82c9c3000                       call   0x891268
0x58763c: 83c404                           add    esp,0x4
0x58763f: 89459c                           mov    DWORD PTR [ebp-0x64],eax
0x587642: c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x587646: 3bc3                             cmp    eax,ebx
0x587648: 7408                             je     0x587652
0x58764a: 50                               push   eax
0x58764b: e8f0320400                       call   0x5ca940
0x587650: eb02                             jmp    0x587654
0x587652: 33c0                             xor    eax,eax
0x587654: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x587657: 8b0dfcadfa00                     mov    ecx,DWORD PTR ds:0xfaadfc
0x58765d: a310aefa00                       mov    ds:0xfaae10,eax
0x587662: 8981b4650100                     mov    DWORD PTR [ecx+0x165b4],eax
0x587668: 8b15fcadfa00                     mov    edx,DWORD PTR ds:0xfaadfc
0x58766e: c682b865010001                   mov    BYTE PTR [edx+0x165b8],0x1
0x587675: a1fcadfa00                       mov    eax,ds:0xfaadfc
0x58767a: 6a40                             push   0x40
0x58767c: 8d4da0                           lea    ecx,[ebp-0x60]
0x58767f: 53                               push   ebx
0x587680: c780bc65010005000000             mov    DWORD PTR [eax+0x165bc],0x5
0x58768a: 51                               push   ecx
0x58768b: 895de0                           mov    DWORD PTR [ebp-0x20],ebx
0x58768e: e8cd713100                       call   0x89e860
0x587693: 8b1548a2d600                     mov    edx,DWORD PTR ds:0xd6a248
0x587699: 83c40c                           add    esp,0xc
0x58769c: 52                               push   edx
0x58769d: 8d45a0                           lea    eax,[ebp-0x60]
0x5876a0: 6a20                             push   0x20
0x5876a2: 50                               push   eax
0x5876a3: c745e40e000000                   mov    DWORD PTR [ebp-0x1c],0xe
0x5876aa: c745e804000000                   mov    DWORD PTR [ebp-0x18],0x4
0x5876b1: 8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x5876b4: e894b73000                       call   0x892e4d
0x5876b9: 83c40c                           add    esp,0xc
0x5876bc: f605c87bfb0001                   test   BYTE PTR ds:0xfb7bc8,0x1
0x5876c3: 751f                             jne    0x5876e4
0x5876c5: 0935c87bfb00                     or     DWORD PTR ds:0xfb7bc8,esi
0x5876cb: c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
0x5876cf: e81cd81a00                       call   0x734ef0
0x5876d4: 68f0d4bc00                       push   0xbcd4f0
0x5876d9: e83cac3000                       call   0x89231a
0x5876de: 83c404                           add    esp,0x4
0x5876e1: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x5876e4: 8d4d9c                           lea    ecx,[ebp-0x64]
0x5876e7: 51                               push   ecx
0x5876e8: 68707bfb00                       push   0xfb7b70
0x5876ed: 8d45a0                           lea    eax,[ebp-0x60]
0x5876f0: e85be11a00                       call   0x735850
0x5876f5: 8b10                             mov    edx,DWORD PTR [eax]
0x5876f7: 891530affa00                     mov    DWORD PTR ds:0xfaaf30,edx
0x5876fd: b8d8adfa00                       mov    eax,0xfaadd8
0x587702: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x587705: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x58770c: 59                               pop    ecx
0x58770d: 5e                               pop    esi
0x58770e: 5b                               pop    ebx
0x58770f: 8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x587712: 33cd                             xor    ecx,ebp
0x587714: e8e8983000                       call   0x891001
0x587719: 8be5                             mov    esp,ebp
0x58771b: 5d                               pop    ebp
0x58771c: c3                               ret

## F-74D990 VA 0x74d990..0x74e077 raw 0x34cd90 len 1767 SHA256 1d2dfebb111cfed1d2fe695df85ad72f20a46d5895c4bc19e0f5f7817548a5f2
0x74d990: 55                               push   ebp
0x74d991: 8bec                             mov    ebp,esp
0x74d993: 6aff                             push   0xffffffff
0x74d995: 68a9ef9000                       push   0x90efa9
0x74d99a: 64a100000000                     mov    eax,fs:0x0
0x74d9a0: 50                               push   eax
0x74d9a1: 83ec28                           sub    esp,0x28
0x74d9a4: 53                               push   ebx
0x74d9a5: 56                               push   esi
0x74d9a6: a1201fd600                       mov    eax,ds:0xd61f20
0x74d9ab: 33c5                             xor    eax,ebp
0x74d9ad: 50                               push   eax
0x74d9ae: 8d45f4                           lea    eax,[ebp-0xc]
0x74d9b1: 64a300000000                     mov    fs:0x0,eax
0x74d9b7: b8b848f900                       mov    eax,0xf948b8
0x74d9bc: c745e81048f900                   mov    DWORD PTR [ebp-0x18],0xf94810
0x74d9c3: c7051048f9000c79c400             mov    DWORD PTR ds:0xf94810,0xc4790c
0x74d9cd: e8fefeffff                       call   0x74d8d0
0x74d9d2: be3c49f900                       mov    esi,0xf9493c
0x74d9d7: e884fdffff                       call   0x74d760
0x74d9dc: 33db                             xor    ebx,ebx
0x74d9de: 6a18                             push   0x18
0x74d9e0: 891d145cf900                     mov    DWORD PTR ds:0xf95c14,ebx
0x74d9e6: 891d105cf900                     mov    DWORD PTR ds:0xf95c10,ebx
0x74d9ec: 891d0c5cf900                     mov    DWORD PTR ds:0xf95c0c,ebx
0x74d9f2: 891d085cf900                     mov    DWORD PTR ds:0xf95c08,ebx
0x74d9f8: 891d285cf900                     mov    DWORD PTR ds:0xf95c28,ebx
0x74d9fe: e865381400                       call   0x891268
0x74da03: 83c404                           add    esp,0x4
0x74da06: 3bc3                             cmp    eax,ebx
0x74da08: 0f84d9050000                     je     0x74dfe7
0x74da0e: a3245cf900                       mov    ds:0xf95c24,eax
0x74da13: 8900                             mov    DWORD PTR [eax],eax
0x74da15: a1245cf900                       mov    eax,ds:0xf95c24
0x74da1a: 894004                           mov    DWORD PTR [eax+0x4],eax
0x74da1d: a1245cf900                       mov    eax,ds:0xf95c24
0x74da22: 894008                           mov    DWORD PTR [eax+0x8],eax
0x74da25: a1245cf900                       mov    eax,ds:0xf95c24
0x74da2a: c6401401                         mov    BYTE PTR [eax+0x14],0x1
0x74da2e: 8b0d245cf900                     mov    ecx,DWORD PTR ds:0xf95c24
0x74da34: c6411501                         mov    BYTE PTR [ecx+0x15],0x1
0x74da38: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x74da3b: 6a0c                             push   0xc
0x74da3d: 891d345cf900                     mov    DWORD PTR ds:0xf95c34,ebx
0x74da43: e820381400                       call   0x891268
0x74da48: 83c404                           add    esp,0x4
0x74da4b: 3bc3                             cmp    eax,ebx
0x74da4d: 0f8470050000                     je     0x74dfc3
0x74da53: a3305cf900                       mov    ds:0xf95c30,eax
0x74da58: 8900                             mov    DWORD PTR [eax],eax
0x74da5a: a1305cf900                       mov    eax,ds:0xf95c30
0x74da5f: 894004                           mov    DWORD PTR [eax+0x4],eax
0x74da62: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x74da66: 6a0c                             push   0xc
0x74da68: 891d405cf900                     mov    DWORD PTR ds:0xf95c40,ebx
0x74da6e: e8f5371400                       call   0x891268
0x74da73: 83c404                           add    esp,0x4
0x74da76: 3bc3                             cmp    eax,ebx
0x74da78: 0f84d5050000                     je     0x74e053
0x74da7e: a33c5cf900                       mov    ds:0xf95c3c,eax
0x74da83: 8900                             mov    DWORD PTR [eax],eax
0x74da85: a13c5cf900                       mov    eax,ds:0xf95c3c
0x74da8a: 894004                           mov    DWORD PTR [eax+0x4],eax
0x74da8d: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x74da91: 6a0c                             push   0xc
0x74da93: 891d4c5cf900                     mov    DWORD PTR ds:0xf95c4c,ebx
0x74da99: e8ca371400                       call   0x891268
0x74da9e: 83c404                           add    esp,0x4
0x74daa1: 3bc3                             cmp    eax,ebx
0x74daa3: 0f8486050000                     je     0x74e02f
0x74daa9: a3485cf900                       mov    ds:0xf95c48,eax
0x74daae: 8900                             mov    DWORD PTR [eax],eax
0x74dab0: a1485cf900                       mov    eax,ds:0xf95c48
0x74dab5: 894004                           mov    DWORD PTR [eax+0x4],eax
0x74dab8: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x74dabc: 6a08                             push   0x8
0x74dabe: 891d545cf900                     mov    DWORD PTR ds:0xf95c54,ebx
0x74dac4: e89f371400                       call   0x891268
0x74dac9: 83c404                           add    esp,0x4
0x74dacc: 3bc3                             cmp    eax,ebx
0x74dace: 0f8437050000                     je     0x74e00b
0x74dad4: a3545cf900                       mov    ds:0xf95c54,eax
0x74dad9: 895804                           mov    DWORD PTR [eax+0x4],ebx
0x74dadc: 33c9                             xor    ecx,ecx
0x74dade: 8908                             mov    DWORD PTR [eax],ecx
0x74dae0: 8b15545cf900                     mov    edx,DWORD PTR ds:0xf95c54
0x74dae6: c702545cf900                     mov    DWORD PTR [edx],0xf95c54
0x74daec: 891d585cf900                     mov    DWORD PTR ds:0xf95c58,ebx
0x74daf2: 891d5c5cf900                     mov    DWORD PTR ds:0xf95c5c,ebx
0x74daf8: 891d605cf900                     mov    DWORD PTR ds:0xf95c60,ebx
0x74dafe: 891d645cf900                     mov    DWORD PTR ds:0xf95c64,ebx
0x74db04: c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x74db08: 6a08                             push   0x8
0x74db0a: 891d6c5cf900                     mov    DWORD PTR ds:0xf95c6c,ebx
0x74db10: e853371400                       call   0x891268
0x74db15: 83c404                           add    esp,0x4
0x74db18: 3bc3                             cmp    eax,ebx
0x74db1a: 0f847f040000                     je     0x74df9f
0x74db20: a36c5cf900                       mov    ds:0xf95c6c,eax
0x74db25: 895804                           mov    DWORD PTR [eax+0x4],ebx
0x74db28: 33c9                             xor    ecx,ecx
0x74db2a: 8908                             mov    DWORD PTR [eax],ecx
0x74db2c: a16c5cf900                       mov    eax,ds:0xf95c6c
0x74db31: c7006c5cf900                     mov    DWORD PTR [eax],0xf95c6c
0x74db37: 891d705cf900                     mov    DWORD PTR ds:0xf95c70,ebx
0x74db3d: 891d745cf900                     mov    DWORD PTR ds:0xf95c74,ebx
0x74db43: 891d785cf900                     mov    DWORD PTR ds:0xf95c78,ebx
0x74db49: 891d7c5cf900                     mov    DWORD PTR ds:0xf95c7c,ebx
0x74db4f: c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x74db53: 6a18                             push   0x18
0x74db55: 891d885cf900                     mov    DWORD PTR ds:0xf95c88,ebx
0x74db5b: e808371400                       call   0x891268
0x74db60: 83c404                           add    esp,0x4
0x74db63: 3bc3                             cmp    eax,ebx
0x74db65: 0f847c040000                     je     0x74dfe7
0x74db6b: a3845cf900                       mov    ds:0xf95c84,eax
0x74db70: 8900                             mov    DWORD PTR [eax],eax
0x74db72: a1845cf900                       mov    eax,ds:0xf95c84
0x74db77: 894004                           mov    DWORD PTR [eax+0x4],eax
0x74db7a: c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
0x74db7e: 6a0c                             push   0xc
0x74db80: 891d945cf900                     mov    DWORD PTR ds:0xf95c94,ebx
0x74db86: e8dd361400                       call   0x891268
0x74db8b: 83c404                           add    esp,0x4
0x74db8e: 3bc3                             cmp    eax,ebx
0x74db90: 0f842d040000                     je     0x74dfc3
0x74db96: a3905cf900                       mov    ds:0xf95c90,eax
0x74db9b: 8900                             mov    DWORD PTR [eax],eax
0x74db9d: a1905cf900                       mov    eax,ds:0xf95c90
0x74dba2: 894004                           mov    DWORD PTR [eax+0x4],eax
0x74dba5: 891d9c5cf900                     mov    DWORD PTR ds:0xf95c9c,ebx
0x74dbab: 891da05cf900                     mov    DWORD PTR ds:0xf95ca0,ebx
0x74dbb1: 891da45cf900                     mov    DWORD PTR ds:0xf95ca4,ebx
0x74dbb7: 891dac5cf900                     mov    DWORD PTR ds:0xf95cac,ebx
0x74dbbd: 891db05cf900                     mov    DWORD PTR ds:0xf95cb0,ebx
0x74dbc3: 891db45cf900                     mov    DWORD PTR ds:0xf95cb4,ebx
0x74dbc9: c645fc09                         mov    BYTE PTR [ebp-0x4],0x9
0x74dbcd: 6a0c                             push   0xc
0x74dbcf: 891ddc5cf900                     mov    DWORD PTR ds:0xf95cdc,ebx
0x74dbd5: e88e361400                       call   0x891268
0x74dbda: 83c404                           add    esp,0x4
0x74dbdd: 3bc3                             cmp    eax,ebx
0x74dbdf: 0f84ba030000                     je     0x74df9f
0x74dbe5: a3d85cf900                       mov    ds:0xf95cd8,eax
0x74dbea: 8900                             mov    DWORD PTR [eax],eax
0x74dbec: a1d85cf900                       mov    eax,ds:0xf95cd8
0x74dbf1: 894004                           mov    DWORD PTR [eax+0x4],eax
0x74dbf4: 68105d5f00                       push   0x5f5d10
0x74dbf9: 6850d97400                       push   0x74d950
0x74dbfe: 6a04                             push   0x4
0x74dc00: 6a14                             push   0x14
0x74dc02: 68e45cf900                       push   0xf95ce4
0x74dc07: c645fc0a                         mov    BYTE PTR [ebp-0x4],0xa
0x74dc0b: e8f3431400                       call   0x892003
0x74dc10: 68105d5f00                       push   0x5f5d10
0x74dc15: 6870d97400                       push   0x74d970
0x74dc1a: 6a04                             push   0x4
0x74dc1c: 6a1c                             push   0x1c
0x74dc1e: 68345df900                       push   0xf95d34
0x74dc23: c645fc0b                         mov    BYTE PTR [ebp-0x4],0xb
0x74dc27: e8d7431400                       call   0x892003
0x74dc2c: 68105d5f00                       push   0x5f5d10
0x74dc31: 6870d97400                       push   0x74d970
0x74dc36: 68000c0000                       push   0xc00
0x74dc3b: 6a1c                             push   0x1c
0x74dc3d: 68ac5df900                       push   0xf95dac
0x74dc42: c645fc0c                         mov    BYTE PTR [ebp-0x4],0xc
0x74dc46: e8b8431400                       call   0x892003
0x74dc4b: d9ee                             fldz
0x74dc4d: d9156848f900                     fst    DWORD PTR ds:0xf94868
0x74dc53: 891dd45cf900                     mov    DWORD PTR ds:0xf95cd4,ebx
0x74dc59: d9156448f900                     fst    DWORD PTR ds:0xf94864
0x74dc5f: 891dacadfa00                     mov    DWORD PTR ds:0xfaadac,ebx
0x74dc65: d9156048f900                     fst    DWORD PTR ds:0xf94860
0x74dc6b: 891d185cf900                     mov    DWORD PTR ds:0xf95c18,ebx
0x74dc71: d9155c48f900                     fst    DWORD PTR ds:0xf9485c
0x74dc77: 891d2048f900                     mov    DWORD PTR ds:0xf94820,ebx
0x74dc7d: d9155448f900                     fst    DWORD PTR ds:0xf94854
0x74dc83: 891d2448f900                     mov    DWORD PTR ds:0xf94824,ebx
0x74dc89: d9155048f900                     fst    DWORD PTR ds:0xf94850
0x74dc8f: 891d1848f900                     mov    DWORD PTR ds:0xf94818,ebx
0x74dc95: d9154c48f900                     fst    DWORD PTR ds:0xf9484c
0x74dc9b: 891d1c48f900                     mov    DWORD PTR ds:0xf9481c,ebx
0x74dca1: d9154848f900                     fst    DWORD PTR ds:0xf94848
0x74dca7: 891da45df900                     mov    DWORD PTR ds:0xf95da4,ebx
0x74dcad: d9154048f900                     fst    DWORD PTR ds:0xf94840
0x74dcb3: 891da85df900                     mov    DWORD PTR ds:0xf95da8,ebx
0x74dcb9: d9153c48f900                     fst    DWORD PTR ds:0xf9483c
0x74dcbf: 891d2848f900                     mov    DWORD PTR ds:0xf94828,ebx
0x74dcc5: d9153848f900                     fst    DWORD PTR ds:0xf94838
0x74dccb: 891d2c48f900                     mov    DWORD PTR ds:0xf9482c,ebx
0x74dcd1: d9153448f900                     fst    DWORD PTR ds:0xf94834
0x74dcd7: 891db048f900                     mov    DWORD PTR ds:0xf948b0,ebx
0x74dcdd: d9e8                             fld1
0x74dcdf: 891db448f900                     mov    DWORD PTR ds:0xf948b4,ebx
0x74dce5: d9156c48f900                     fst    DWORD PTR ds:0xf9486c
0x74dceb: 891d1448f900                     mov    DWORD PTR ds:0xf94814,ebx
0x74dcf1: d9155848f900                     fst    DWORD PTR ds:0xf94858
0x74dcf7: d9154448f900                     fst    DWORD PTR ds:0xf94844
0x74dcfd: d9153048f900                     fst    DWORD PTR ds:0xf94830
0x74dd03: d915ac48f900                     fst    DWORD PTR ds:0xf948ac
0x74dd09: d9159848f900                     fst    DWORD PTR ds:0xf94898
0x74dd0f: d9158448f900                     fst    DWORD PTR ds:0xf94884
0x74dd15: d9157048f900                     fst    DWORD PTR ds:0xf94870
0x74dd1b: d9c9                             fxch   st(1)
0x74dd1d: d915a848f900                     fst    DWORD PTR ds:0xf948a8
0x74dd23: d915a448f900                     fst    DWORD PTR ds:0xf948a4
0x74dd29: d915a048f900                     fst    DWORD PTR ds:0xf948a0
0x74dd2f: d9159c48f900                     fst    DWORD PTR ds:0xf9489c
0x74dd35: d9159448f900                     fst    DWORD PTR ds:0xf94894
0x74dd3b: d9159048f900                     fst    DWORD PTR ds:0xf94890
0x74dd41: d9158c48f900                     fst    DWORD PTR ds:0xf9488c
0x74dd47: d9158848f900                     fst    DWORD PTR ds:0xf94888
0x74dd4d: d9158048f900                     fst    DWORD PTR ds:0xf94880
0x74dd53: d9157c48f900                     fst    DWORD PTR ds:0xf9487c
0x74dd59: d9157848f900                     fst    DWORD PTR ds:0xf94878
0x74dd5f: d9157448f900                     fst    DWORD PTR ds:0xf94874
0x74dd65: d9c9                             fxch   st(1)
0x74dd67: d955e4                           fst    DWORD PTR [ebp-0x1c]
0x74dd6a: d955e8                           fst    DWORD PTR [ebp-0x18]
0x74dd6d: 8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
0x74dd70: 8b55e8                           mov    edx,DWORD PTR [ebp-0x18]
0x74dd73: d955e4                           fst    DWORD PTR [ebp-0x1c]
0x74dd76: 8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
0x74dd79: d955e8                           fst    DWORD PTR [ebp-0x18]
0x74dd7c: d955e4                           fst    DWORD PTR [ebp-0x1c]
0x74dd7f: 890dbc5bf900                     mov    DWORD PTR ds:0xf95bbc,ecx
0x74dd85: 8b4de8                           mov    ecx,DWORD PTR [ebp-0x18]
0x74dd88: d955e8                           fst    DWORD PTR [ebp-0x18]
0x74dd8b: 8915c05bf900                     mov    DWORD PTR ds:0xf95bc0,edx
0x74dd91: 8b55e4                           mov    edx,DWORD PTR [ebp-0x1c]
0x74dd94: d955e4                           fst    DWORD PTR [ebp-0x1c]
0x74dd97: a3c45bf900                       mov    ds:0xf95bc4,eax
0x74dd9c: 8b45e8                           mov    eax,DWORD PTR [ebp-0x18]
0x74dd9f: d955e8                           fst    DWORD PTR [ebp-0x18]
0x74dda2: 890dc85bf900                     mov    DWORD PTR ds:0xf95bc8,ecx
0x74dda8: 8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
0x74ddab: d955e4                           fst    DWORD PTR [ebp-0x1c]
0x74ddae: 89159c5bf900                     mov    DWORD PTR ds:0xf95b9c,edx
0x74ddb4: 8b55e8                           mov    edx,DWORD PTR [ebp-0x18]
0x74ddb7: d955e8                           fst    DWORD PTR [ebp-0x18]
0x74ddba: a3a05bf900                       mov    ds:0xf95ba0,eax
0x74ddbf: 8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
0x74ddc2: d955e4                           fst    DWORD PTR [ebp-0x1c]
0x74ddc5: 890da45bf900                     mov    DWORD PTR ds:0xf95ba4,ecx
0x74ddcb: 8b4de8                           mov    ecx,DWORD PTR [ebp-0x18]
0x74ddce: d95de8                           fstp   DWORD PTR [ebp-0x18]
0x74ddd1: 8915a85bf900                     mov    DWORD PTR ds:0xf95ba8,edx
0x74ddd7: 8b55e4                           mov    edx,DWORD PTR [ebp-0x1c]
0x74ddda: d9153c5bf900                     fst    DWORD PTR ds:0xf95b3c
0x74dde0: a3ac5bf900                       mov    ds:0xf95bac,eax
0x74dde5: d91d405bf900                     fstp   DWORD PTR ds:0xf95b40
0x74ddeb: 8b45e8                           mov    eax,DWORD PTR [ebp-0x18]
0x74ddee: 890db05bf900                     mov    DWORD PTR ds:0xf95bb0,ecx
0x74ddf4: 8915b45bf900                     mov    DWORD PTR ds:0xf95bb4,edx
0x74ddfa: a3b85bf900                       mov    ds:0xf95bb8,eax
0x74ddff: 891dcc5bf900                     mov    DWORD PTR ds:0xf95bcc,ebx
0x74de05: 891dd05bf900                     mov    DWORD PTR ds:0xf95bd0,ebx
0x74de0b: 891dd45bf900                     mov    DWORD PTR ds:0xf95bd4,ebx
0x74de11: 891dd85bf900                     mov    DWORD PTR ds:0xf95bd8,ebx
0x74de17: 891df05bf900                     mov    DWORD PTR ds:0xf95bf0,ebx
0x74de1d: 891df45bf900                     mov    DWORD PTR ds:0xf95bf4,ebx
0x74de23: 891ddc5bf900                     mov    DWORD PTR ds:0xf95bdc,ebx
0x74de29: 891de05bf900                     mov    DWORD PTR ds:0xf95be0,ebx
0x74de2f: 891de45bf900                     mov    DWORD PTR ds:0xf95be4,ebx
0x74de35: 891df85bf900                     mov    DWORD PTR ds:0xf95bf8,ebx
0x74de3b: 891dec5bf900                     mov    DWORD PTR ds:0xf95bec,ebx
0x74de41: 66891de85bf900                   mov    WORD PTR ds:0xf95be8,bx
0x74de48: 891dfc5bf900                     mov    DWORD PTR ds:0xf95bfc,ebx
0x74de4e: 891d005cf900                     mov    DWORD PTR ds:0xf95c00,ebx
0x74de54: 881d045cf900                     mov    BYTE PTR ds:0xf95c04,bl
0x74de5a: 891dbc5cf900                     mov    DWORD PTR ds:0xf95cbc,ebx
0x74de60: 891dc05cf900                     mov    DWORD PTR ds:0xf95cc0,ebx
0x74de66: 66891d445bf900                   mov    WORD PTR ds:0xf95b44,bx
0x74de6d: 881d465bf900                     mov    BYTE PTR ds:0xf95b46,bl
0x74de73: 891d485bf900                     mov    DWORD PTR ds:0xf95b48,ebx
0x74de79: c7054c5bf90001000000             mov    DWORD PTR ds:0xf95b4c,0x1
0x74de83: c705505bf90002000000             mov    DWORD PTR ds:0xf95b50,0x2
0x74de8d: c705545bf90064000000             mov    DWORD PTR ds:0xf95b54,0x64
0x74de97: c705585bf90066000000             mov    DWORD PTR ds:0xf95b58,0x66
0x74dea1: c7055c5bf90068000000             mov    DWORD PTR ds:0xf95b5c,0x68
0x74deab: c705605bf90065000000             mov    DWORD PTR ds:0xf95b60,0x65
0x74deb5: c705645bf90067000000             mov    DWORD PTR ds:0xf95b64,0x67
0x74debf: c705685bf90069000000             mov    DWORD PTR ds:0xf95b68,0x69
0x74dec9: c7056c5bf90078000000             mov    DWORD PTR ds:0xf95b6c,0x78
0x74ded3: c705705bf9007a000000             mov    DWORD PTR ds:0xf95b70,0x7a
0x74dedd: c705745bf9007c000000             mov    DWORD PTR ds:0xf95b74,0x7c
0x74dee7: c705785bf90079000000             mov    DWORD PTR ds:0xf95b78,0x79
0x74def1: c7057c5bf9007b000000             mov    DWORD PTR ds:0xf95b7c,0x7b
0x74defb: c705805bf9007d000000             mov    DWORD PTR ds:0xf95b80,0x7d
0x74df05: c705845bf9008c000000             mov    DWORD PTR ds:0xf95b84,0x8c
0x74df0f: c705885bf9008e000000             mov    DWORD PTR ds:0xf95b88,0x8e
0x74df19: c7058c5bf90090000000             mov    DWORD PTR ds:0xf95b8c,0x90
0x74df23: c705905bf9008d000000             mov    DWORD PTR ds:0xf95b90,0x8d
0x74df2d: c705945bf9008f000000             mov    DWORD PTR ds:0xf95b94,0x8f
0x74df37: c705985bf90091000000             mov    DWORD PTR ds:0xf95b98,0x91
0x74df41: 881dcc5cf900                     mov    BYTE PTR ds:0xf95ccc,bl
0x74df47: 891db0adfa00                     mov    DWORD PTR ds:0xfaadb0,ebx
0x74df4d: c705b4adfa0000020000             mov    DWORD PTR ds:0xfaadb4,0x200
0x74df57: 891db8adfa00                     mov    DWORD PTR ds:0xfaadb8,ebx
0x74df5d: 891dbcadfa00                     mov    DWORD PTR ds:0xfaadbc,ebx
0x74df63: c705c0adfa00a8000000             mov    DWORD PTR ds:0xfaadc0,0xa8
0x74df6d: 891dc4adfa00                     mov    DWORD PTR ds:0xfaadc4,ebx
0x74df73: 881dc8adfa00                     mov    BYTE PTR ds:0xfaadc8,bl
0x74df79: c705ccadfa0003000000             mov    DWORD PTR ds:0xfaadcc,0x3
0x74df83: 881d1c5cf900                     mov    BYTE PTR ds:0xf95c1c,bl
0x74df89: b81048f900                       mov    eax,0xf94810
0x74df8e: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x74df91: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x74df98: 59                               pop    ecx
0x74df99: 5e                               pop    esi
0x74df9a: 5b                               pop    ebx
0x74df9b: 8be5                             mov    esp,ebp
0x74df9d: 5d                               pop    ebp
0x74df9e: c3                               ret
0x74df9f: 8d4df0                           lea    ecx,[ebp-0x10]
0x74dfa2: 51                               push   ecx
0x74dfa3: 8d4dd8                           lea    ecx,[ebp-0x28]
0x74dfa6: 895df0                           mov    DWORD PTR [ebp-0x10],ebx
0x74dfa9: e8fb301400                       call   0x8910a9
0x74dfae: 68a857c800                       push   0xc857a8
0x74dfb3: 8d55d8                           lea    edx,[ebp-0x28]
0x74dfb6: 52                               push   edx
0x74dfb7: c745d8a42cbd00                   mov    DWORD PTR [ebp-0x28],0xbd2ca4
0x74dfbe: e82dea1400                       call   0x89c9f0
0x74dfc3: 8d45f0                           lea    eax,[ebp-0x10]
0x74dfc6: 50                               push   eax
0x74dfc7: 8d4dd8                           lea    ecx,[ebp-0x28]
0x74dfca: 895df0                           mov    DWORD PTR [ebp-0x10],ebx
0x74dfcd: e8d7301400                       call   0x8910a9
0x74dfd2: 68a857c800                       push   0xc857a8
0x74dfd7: 8d4dd8                           lea    ecx,[ebp-0x28]
0x74dfda: 51                               push   ecx
0x74dfdb: c745d8a42cbd00                   mov    DWORD PTR [ebp-0x28],0xbd2ca4
0x74dfe2: e809ea1400                       call   0x89c9f0
0x74dfe7: 8d55ec                           lea    edx,[ebp-0x14]
0x74dfea: 52                               push   edx
0x74dfeb: 8d4dcc                           lea    ecx,[ebp-0x34]
0x74dfee: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x74dff1: e8b3301400                       call   0x8910a9
0x74dff6: 68a857c800                       push   0xc857a8
0x74dffb: 8d45cc                           lea    eax,[ebp-0x34]
0x74dffe: 50                               push   eax
0x74dfff: c745cca42cbd00                   mov    DWORD PTR [ebp-0x34],0xbd2ca4
0x74e006: e8e5e91400                       call   0x89c9f0
0x74e00b: 8d45ec                           lea    eax,[ebp-0x14]
0x74e00e: 50                               push   eax
0x74e00f: 8d4dcc                           lea    ecx,[ebp-0x34]
0x74e012: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x74e015: e88f301400                       call   0x8910a9
0x74e01a: 68a857c800                       push   0xc857a8
0x74e01f: 8d4dcc                           lea    ecx,[ebp-0x34]
0x74e022: 51                               push   ecx
0x74e023: c745cca42cbd00                   mov    DWORD PTR [ebp-0x34],0xbd2ca4
0x74e02a: e8c1e91400                       call   0x89c9f0
0x74e02f: 8d55f0                           lea    edx,[ebp-0x10]
0x74e032: 52                               push   edx
0x74e033: 8d4dd8                           lea    ecx,[ebp-0x28]
0x74e036: 895df0                           mov    DWORD PTR [ebp-0x10],ebx
0x74e039: e86b301400                       call   0x8910a9
0x74e03e: 68a857c800                       push   0xc857a8
0x74e043: 8d45d8                           lea    eax,[ebp-0x28]
0x74e046: 50                               push   eax
0x74e047: c745d8a42cbd00                   mov    DWORD PTR [ebp-0x28],0xbd2ca4
0x74e04e: e89de91400                       call   0x89c9f0
0x74e053: 8d4dec                           lea    ecx,[ebp-0x14]
0x74e056: 51                               push   ecx
0x74e057: 8d4dcc                           lea    ecx,[ebp-0x34]
0x74e05a: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x74e05d: e847301400                       call   0x8910a9
0x74e062: 68a857c800                       push   0xc857a8
0x74e067: 8d55cc                           lea    edx,[ebp-0x34]
0x74e06a: 52                               push   edx
0x74e06b: c745cca42cbd00                   mov    DWORD PTR [ebp-0x34],0xbd2ca4
0x74e072: e879e91400                       call   0x89c9f0

## F-74D8D0 VA 0x74d8d0..0x74d98f raw 0x34ccd0 len 191 SHA256 cbfc154778046ca436ab792f68362cdd0585aab76c95f9492160c8898d409fb8
0x74d8d0: 33c9                             xor    ecx,ecx
0x74d8d2: c74024ffffffff                   mov    DWORD PTR [eax+0x24],0xffffffff
0x74d8d9: 894804                           mov    DWORD PTR [eax+0x4],ecx
0x74d8dc: 8908                             mov    DWORD PTR [eax],ecx
0x74d8de: 89481c                           mov    DWORD PTR [eax+0x1c],ecx
0x74d8e1: 894820                           mov    DWORD PTR [eax+0x20],ecx
0x74d8e4: 894818                           mov    DWORD PTR [eax+0x18],ecx
0x74d8e7: 894814                           mov    DWORD PTR [eax+0x14],ecx
0x74d8ea: 894810                           mov    DWORD PTR [eax+0x10],ecx
0x74d8ed: 89480c                           mov    DWORD PTR [eax+0xc],ecx
0x74d8f0: 894808                           mov    DWORD PTR [eax+0x8],ecx
0x74d8f3: 894834                           mov    DWORD PTR [eax+0x34],ecx
0x74d8f6: 894830                           mov    DWORD PTR [eax+0x30],ecx
0x74d8f9: 89482c                           mov    DWORD PTR [eax+0x2c],ecx
0x74d8fc: 894828                           mov    DWORD PTR [eax+0x28],ecx
0x74d8ff: 89483c                           mov    DWORD PTR [eax+0x3c],ecx
0x74d902: 894838                           mov    DWORD PTR [eax+0x38],ecx
0x74d905: 66894843                         mov    WORD PTR [eax+0x43],cx
0x74d909: 884845                           mov    BYTE PTR [eax+0x45],cl
0x74d90c: 66894840                         mov    WORD PTR [eax+0x40],cx
0x74d910: 884842                           mov    BYTE PTR [eax+0x42],cl
0x74d913: 894848                           mov    DWORD PTR [eax+0x48],ecx
0x74d916: 89484c                           mov    DWORD PTR [eax+0x4c],ecx
0x74d919: 894850                           mov    DWORD PTR [eax+0x50],ecx
0x74d91c: 894854                           mov    DWORD PTR [eax+0x54],ecx
0x74d91f: 894858                           mov    DWORD PTR [eax+0x58],ecx
0x74d922: 89485c                           mov    DWORD PTR [eax+0x5c],ecx
0x74d925: 894860                           mov    DWORD PTR [eax+0x60],ecx
0x74d928: 894864                           mov    DWORD PTR [eax+0x64],ecx
0x74d92b: 894868                           mov    DWORD PTR [eax+0x68],ecx
0x74d92e: 89486c                           mov    DWORD PTR [eax+0x6c],ecx
0x74d931: 894870                           mov    DWORD PTR [eax+0x70],ecx
0x74d934: 894874                           mov    DWORD PTR [eax+0x74],ecx
0x74d937: 894878                           mov    DWORD PTR [eax+0x78],ecx
0x74d93a: 89487c                           mov    DWORD PTR [eax+0x7c],ecx
0x74d93d: 898880000000                     mov    DWORD PTR [eax+0x80],ecx
0x74d943: c3                               ret
0x74d944: cc                               int3
0x74d945: cc                               int3
0x74d946: cc                               int3
0x74d947: cc                               int3
0x74d948: cc                               int3
0x74d949: cc                               int3
0x74d94a: cc                               int3
0x74d94b: cc                               int3
0x74d94c: cc                               int3
0x74d94d: cc                               int3
0x74d94e: cc                               int3
0x74d94f: cc                               int3
0x74d950: d9ee                             fldz
0x74d952: 8bc1                             mov    eax,ecx
0x74d954: d910                             fst    DWORD PTR [eax]
0x74d956: c74010ffffffff                   mov    DWORD PTR [eax+0x10],0xffffffff
0x74d95d: d95004                           fst    DWORD PTR [eax+0x4]
0x74d960: d95808                           fstp   DWORD PTR [eax+0x8]
0x74d963: d9e8                             fld1
0x74d965: d9580c                           fstp   DWORD PTR [eax+0xc]
0x74d968: c3                               ret
0x74d969: cc                               int3
0x74d96a: cc                               int3
0x74d96b: cc                               int3
0x74d96c: cc                               int3
0x74d96d: cc                               int3
0x74d96e: cc                               int3
0x74d96f: cc                               int3
0x74d970: d9ee                             fldz
0x74d972: 8bc1                             mov    eax,ecx
0x74d974: d910                             fst    DWORD PTR [eax]
0x74d976: c74010ffffffff                   mov    DWORD PTR [eax+0x10],0xffffffff
0x74d97d: d95004                           fst    DWORD PTR [eax+0x4]
0x74d980: d95008                           fst    DWORD PTR [eax+0x8]
0x74d983: d9e8                             fld1
0x74d985: d9580c                           fstp   DWORD PTR [eax+0xc]
0x74d988: d95014                           fst    DWORD PTR [eax+0x14]
0x74d98b: d95818                           fstp   DWORD PTR [eax+0x18]
0x74d98e: c3                               ret

## F-74D760 VA 0x74d760..0x74d7d2 raw 0x34cb60 len 114 SHA256 080e4c98d9233ac4a01cd0d48c46e5bb141de885227fe2433df45e332d8cdae4
0x74d760: 6800010000                       push   0x100
0x74d765: 6a00                             push   0x0
0x74d767: 56                               push   esi
0x74d768: e8f3101500                       call   0x89e860
0x74d76d: 6800010000                       push   0x100
0x74d772: 8d8600010000                     lea    eax,[esi+0x100]
0x74d778: 6a00                             push   0x0
0x74d77a: 50                               push   eax
0x74d77b: e8e0101500                       call   0x89e860
0x74d780: 6800040000                       push   0x400
0x74d785: 8d8e00020000                     lea    ecx,[esi+0x200]
0x74d78b: 6a00                             push   0x0
0x74d78d: 51                               push   ecx
0x74d78e: e8cd101500                       call   0x89e860
0x74d793: 6800040000                       push   0x400
0x74d798: 8d9600060000                     lea    edx,[esi+0x600]
0x74d79e: 6a00                             push   0x0
0x74d7a0: 52                               push   edx
0x74d7a1: e8ba101500                       call   0x89e860
0x74d7a6: 6800040000                       push   0x400
0x74d7ab: 8d86000a0000                     lea    eax,[esi+0xa00]
0x74d7b1: 6a00                             push   0x0
0x74d7b3: 50                               push   eax
0x74d7b4: e8a7101500                       call   0x89e860
0x74d7b9: 6800040000                       push   0x400
0x74d7be: 8d8e000e0000                     lea    ecx,[esi+0xe00]
0x74d7c4: 6a00                             push   0x0
0x74d7c6: 51                               push   ecx
0x74d7c7: e894101500                       call   0x89e860
0x74d7cc: 83c448                           add    esp,0x48
0x74d7cf: 8bc6                             mov    eax,esi
0x74d7d1: c3                               ret

## F-74D950 VA 0x74d950..0x74d98f raw 0x34cd50 len 63 SHA256 d0fd5b29bb0dd6f8fbfe1a5fcf4a4a13b7a1f2aa255191411ae590a8d25b38aa
0x74d950: d9ee                             fldz
0x74d952: 8bc1                             mov    eax,ecx
0x74d954: d910                             fst    DWORD PTR [eax]
0x74d956: c74010ffffffff                   mov    DWORD PTR [eax+0x10],0xffffffff
0x74d95d: d95004                           fst    DWORD PTR [eax+0x4]
0x74d960: d95808                           fstp   DWORD PTR [eax+0x8]
0x74d963: d9e8                             fld1
0x74d965: d9580c                           fstp   DWORD PTR [eax+0xc]
0x74d968: c3                               ret
0x74d969: cc                               int3
0x74d96a: cc                               int3
0x74d96b: cc                               int3
0x74d96c: cc                               int3
0x74d96d: cc                               int3
0x74d96e: cc                               int3
0x74d96f: cc                               int3
0x74d970: d9ee                             fldz
0x74d972: 8bc1                             mov    eax,ecx
0x74d974: d910                             fst    DWORD PTR [eax]
0x74d976: c74010ffffffff                   mov    DWORD PTR [eax+0x10],0xffffffff
0x74d97d: d95004                           fst    DWORD PTR [eax+0x4]
0x74d980: d95008                           fst    DWORD PTR [eax+0x8]
0x74d983: d9e8                             fld1
0x74d985: d9580c                           fstp   DWORD PTR [eax+0xc]
0x74d988: d95014                           fst    DWORD PTR [eax+0x14]
0x74d98b: d95818                           fstp   DWORD PTR [eax+0x18]
0x74d98e: c3                               ret

## F-74D970 VA 0x74d970..0x74d98f raw 0x34cd70 len 31 SHA256 8bc08be78320891a60eab58f3ad3f832cb3c333b7f708ed2c200368832da59f4
0x74d970: d9ee                             fldz
0x74d972: 8bc1                             mov    eax,ecx
0x74d974: d910                             fst    DWORD PTR [eax]
0x74d976: c74010ffffffff                   mov    DWORD PTR [eax+0x10],0xffffffff
0x74d97d: d95004                           fst    DWORD PTR [eax+0x4]
0x74d980: d95008                           fst    DWORD PTR [eax+0x8]
0x74d983: d9e8                             fld1
0x74d985: d9580c                           fstp   DWORD PTR [eax+0xc]
0x74d988: d95014                           fst    DWORD PTR [eax+0x14]
0x74d98b: d95818                           fstp   DWORD PTR [eax+0x18]
0x74d98e: c3                               ret

## F-75F1D0 VA 0x75f1d0..0x75f28c raw 0x35e5d0 len 188 SHA256 607292196b67bd27bb96de8b21f7c1d75e3bd52a5547ca92ce2de74432145ceb
0x75f1d0: 55                               push   ebp
0x75f1d1: 8bec                             mov    ebp,esp
0x75f1d3: 6aff                             push   0xffffffff
0x75f1d5: 6828ed9000                       push   0x90ed28
0x75f1da: 64a100000000                     mov    eax,fs:0x0
0x75f1e0: 50                               push   eax
0x75f1e1: 83ec14                           sub    esp,0x14
0x75f1e4: a1201fd600                       mov    eax,ds:0xd61f20
0x75f1e9: 33c5                             xor    eax,ebp
0x75f1eb: 50                               push   eax
0x75f1ec: 8d45f4                           lea    eax,[ebp-0xc]
0x75f1ef: 64a300000000                     mov    fs:0x0,eax
0x75f1f5: c745ecfc72fb00                   mov    DWORD PTR [ebp-0x14],0xfb72fc
0x75f1fc: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x75f203: 6a18                             push   0x18
0x75f205: c705fc72fb00d89ec400             mov    DWORD PTR ds:0xfb72fc,0xc49ed8
0x75f20f: c7050873fb0000000000             mov    DWORD PTR ds:0xfb7308,0x0
0x75f219: e84a201300                       call   0x891268
0x75f21e: 83c404                           add    esp,0x4
0x75f221: 85c0                             test   eax,eax
0x75f223: 743f                             je     0x75f264
0x75f225: a30473fb00                       mov    ds:0xfb7304,eax
0x75f22a: 8900                             mov    DWORD PTR [eax],eax
0x75f22c: a10473fb00                       mov    eax,ds:0xfb7304
0x75f231: 894004                           mov    DWORD PTR [eax+0x4],eax
0x75f234: a10473fb00                       mov    eax,ds:0xfb7304
0x75f239: 894008                           mov    DWORD PTR [eax+0x8],eax
0x75f23c: 8b0d0473fb00                     mov    ecx,DWORD PTR ds:0xfb7304
0x75f242: b001                             mov    al,0x1
0x75f244: 884114                           mov    BYTE PTR [ecx+0x14],al
0x75f247: 8b150473fb00                     mov    edx,DWORD PTR ds:0xfb7304
0x75f24d: 884215                           mov    BYTE PTR [edx+0x15],al
0x75f250: b8fc72fb00                       mov    eax,0xfb72fc
0x75f255: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x75f258: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x75f25f: 59                               pop    ecx
0x75f260: 8be5                             mov    esp,ebp
0x75f262: 5d                               pop    ebp
0x75f263: c3                               ret
0x75f264: 8d45f0                           lea    eax,[ebp-0x10]
0x75f267: 50                               push   eax
0x75f268: 8d4de0                           lea    ecx,[ebp-0x20]
0x75f26b: c745f000000000                   mov    DWORD PTR [ebp-0x10],0x0
0x75f272: e8321e1300                       call   0x8910a9
0x75f277: 68a857c800                       push   0xc857a8
0x75f27c: 8d4de0                           lea    ecx,[ebp-0x20]
0x75f27f: 51                               push   ecx
0x75f280: c745e0a42cbd00                   mov    DWORD PTR [ebp-0x20],0xbd2ca4
0x75f287: e864d71300                       call   0x89c9f0

## F-41F3E0 VA 0x41f3e0..0x41f460 raw 0x1e7e0 len 128 SHA256 ce80fb3c90b08dcee195b4972d1173bb7b88731499203a8961ede0c74bf87b5b
0x41f3e0: 55                               push   ebp
0x41f3e1: 8bec                             mov    ebp,esp
0x41f3e3: 6aff                             push   0xffffffff
0x41f3e5: 68feb89000                       push   0x90b8fe
0x41f3ea: 64a100000000                     mov    eax,fs:0x0
0x41f3f0: 50                               push   eax
0x41f3f1: a1201fd600                       mov    eax,ds:0xd61f20
0x41f3f6: 33c5                             xor    eax,ebp
0x41f3f8: 50                               push   eax
0x41f3f9: 8d45f4                           lea    eax,[ebp-0xc]
0x41f3fc: 64a300000000                     mov    fs:0x0,eax
0x41f402: b801000000                       mov    eax,0x1
0x41f407: 84051873fb00                     test   BYTE PTR ds:0xfb7318,al
0x41f40d: 753d                             jne    0x41f44c
0x41f40f: 09051873fb00                     or     DWORD PTR ds:0xfb7318,eax
0x41f415: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x41f41c: e8affd3300                       call   0x75f1d0
0x41f421: 6860d0bc00                       push   0xbcd060
0x41f426: c705fc72fb00809ec400             mov    DWORD PTR ds:0xfb72fc,0xc49e80
0x41f430: c7051073fb0000000000             mov    DWORD PTR ds:0xfb7310,0x0
0x41f43a: c7051473fb0000000000             mov    DWORD PTR ds:0xfb7314,0x0
0x41f444: e8d12e4700                       call   0x89231a
0x41f449: 83c404                           add    esp,0x4
0x41f44c: b8fc72fb00                       mov    eax,0xfb72fc
0x41f451: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x41f454: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x41f45b: 59                               pop    ecx
0x41f45c: 8be5                             mov    esp,ebp
0x41f45e: 5d                               pop    ebp
0x41f45f: c3                               ret

## F-7701E0 VA 0x7701e0..0x77028c raw 0x36f5e0 len 172 SHA256 ae1f2d64d50088cebcfef11113fe8eee114836ca844219e4542ba3b6554ad246
0x7701e0: 55                               push   ebp
0x7701e1: 8bec                             mov    ebp,esp
0x7701e3: 6aff                             push   0xffffffff
0x7701e5: 6858589000                       push   0x905858
0x7701ea: 64a100000000                     mov    eax,fs:0x0
0x7701f0: 50                               push   eax
0x7701f1: 83ec10                           sub    esp,0x10
0x7701f4: 56                               push   esi
0x7701f5: a1201fd600                       mov    eax,ds:0xd61f20
0x7701fa: 33c5                             xor    eax,ebp
0x7701fc: 50                               push   eax
0x7701fd: 8d45f4                           lea    eax,[ebp-0xc]
0x770200: 64a300000000                     mov    fs:0x0,eax
0x770206: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x770209: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x770210: c70694d9c400                     mov    DWORD PTR [esi],0xc4d994
0x770216: 6a18                             push   0x18
0x770218: c7460c00000000                   mov    DWORD PTR [esi+0xc],0x0
0x77021f: e844101200                       call   0x891268
0x770224: 83c404                           add    esp,0x4
0x770227: 85c0                             test   eax,eax
0x770229: 7439                             je     0x770264
0x77022b: 894608                           mov    DWORD PTR [esi+0x8],eax
0x77022e: 8900                             mov    DWORD PTR [eax],eax
0x770230: 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x770233: 894004                           mov    DWORD PTR [eax+0x4],eax
0x770236: 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x770239: 894008                           mov    DWORD PTR [eax+0x8],eax
0x77023c: 8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
0x77023f: b001                             mov    al,0x1
0x770241: 884114                           mov    BYTE PTR [ecx+0x14],al
0x770244: 8b5608                           mov    edx,DWORD PTR [esi+0x8]
0x770247: 884215                           mov    BYTE PTR [edx+0x15],al
0x77024a: c70664d9c400                     mov    DWORD PTR [esi],0xc4d964
0x770250: 8bc6                             mov    eax,esi
0x770252: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x770255: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x77025c: 59                               pop    ecx
0x77025d: 5e                               pop    esi
0x77025e: 8be5                             mov    esp,ebp
0x770260: 5d                               pop    ebp
0x770261: c20400                           ret    0x4
0x770264: 8d45f0                           lea    eax,[ebp-0x10]
0x770267: 50                               push   eax
0x770268: 8d4de4                           lea    ecx,[ebp-0x1c]
0x77026b: c745f000000000                   mov    DWORD PTR [ebp-0x10],0x0
0x770272: e8320e1200                       call   0x8910a9
0x770277: 68a857c800                       push   0xc857a8
0x77027c: 8d4de4                           lea    ecx,[ebp-0x1c]
0x77027f: 51                               push   ecx
0x770280: c745e4a42cbd00                   mov    DWORD PTR [ebp-0x1c],0xbd2ca4
0x770287: e864c71200                       call   0x89c9f0

## F-7703F0 VA 0x7703f0..0x7704f8 raw 0x36f7f0 len 264 SHA256 63761b2a88b009e8de55712c1001e7bb5c78a19ad946faba48f46bbecff20026
0x7703f0: 55                               push   ebp
0x7703f1: 8bec                             mov    ebp,esp
0x7703f3: 6aff                             push   0xffffffff
0x7703f5: 6830589000                       push   0x905830
0x7703fa: 64a100000000                     mov    eax,fs:0x0
0x770400: 50                               push   eax
0x770401: 83ec20                           sub    esp,0x20
0x770404: 53                               push   ebx
0x770405: 56                               push   esi
0x770406: 57                               push   edi
0x770407: a1201fd600                       mov    eax,ds:0xd61f20
0x77040c: 33c5                             xor    eax,ebp
0x77040e: 50                               push   eax
0x77040f: 8d45f4                           lea    eax,[ebp-0xc]
0x770412: 64a300000000                     mov    fs:0x0,eax
0x770418: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x77041b: 33ff                             xor    edi,edi
0x77041d: 897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x770420: c70620dac400                     mov    DWORD PTR [esi],0xc4da20
0x770426: 6a18                             push   0x18
0x770428: 897e0c                           mov    DWORD PTR [esi+0xc],edi
0x77042b: e8380e1200                       call   0x891268
0x770430: 83c404                           add    esp,0x4
0x770433: 3bc7                             cmp    eax,edi
0x770435: 0f8499000000                     je     0x7704d4
0x77043b: 894608                           mov    DWORD PTR [esi+0x8],eax
0x77043e: 8900                             mov    DWORD PTR [eax],eax
0x770440: 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x770443: 894004                           mov    DWORD PTR [eax+0x4],eax
0x770446: 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x770449: 894008                           mov    DWORD PTR [eax+0x8],eax
0x77044c: 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x77044f: bb01000000                       mov    ebx,0x1
0x770454: 885814                           mov    BYTE PTR [eax+0x14],bl
0x770457: 8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
0x77045a: 885915                           mov    BYTE PTR [ecx+0x15],bl
0x77045d: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x770460: c706f0d9c400                     mov    DWORD PTR [esi],0xc4d9f0
0x770466: 6a18                             push   0x18
0x770468: 897e24                           mov    DWORD PTR [esi+0x24],edi
0x77046b: e8f80d1200                       call   0x891268
0x770470: 83c404                           add    esp,0x4
0x770473: 3bc7                             cmp    eax,edi
0x770475: 7439                             je     0x7704b0
0x770477: 894620                           mov    DWORD PTR [esi+0x20],eax
0x77047a: 8900                             mov    DWORD PTR [eax],eax
0x77047c: 8b4620                           mov    eax,DWORD PTR [esi+0x20]
0x77047f: 894004                           mov    DWORD PTR [eax+0x4],eax
0x770482: 8b4620                           mov    eax,DWORD PTR [esi+0x20]
0x770485: 894008                           mov    DWORD PTR [eax+0x8],eax
0x770488: 8b5620                           mov    edx,DWORD PTR [esi+0x20]
0x77048b: 885a14                           mov    BYTE PTR [edx+0x14],bl
0x77048e: 8b4620                           mov    eax,DWORD PTR [esi+0x20]
0x770491: 885815                           mov    BYTE PTR [eax+0x15],bl
0x770494: 897e14                           mov    DWORD PTR [esi+0x14],edi
0x770497: 897e18                           mov    DWORD PTR [esi+0x18],edi
0x77049a: 8bc6                             mov    eax,esi
0x77049c: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x77049f: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7704a6: 59                               pop    ecx
0x7704a7: 5f                               pop    edi
0x7704a8: 5e                               pop    esi
0x7704a9: 5b                               pop    ebx
0x7704aa: 8be5                             mov    esp,ebp
0x7704ac: 5d                               pop    ebp
0x7704ad: c20400                           ret    0x4
0x7704b0: 8d4df0                           lea    ecx,[ebp-0x10]
0x7704b3: 51                               push   ecx
0x7704b4: 8d4de0                           lea    ecx,[ebp-0x20]
0x7704b7: 897df0                           mov    DWORD PTR [ebp-0x10],edi
0x7704ba: e8ea0b1200                       call   0x8910a9
0x7704bf: 68a857c800                       push   0xc857a8
0x7704c4: 8d55e0                           lea    edx,[ebp-0x20]
0x7704c7: 52                               push   edx
0x7704c8: c745e0a42cbd00                   mov    DWORD PTR [ebp-0x20],0xbd2ca4
0x7704cf: e81cc51200                       call   0x89c9f0
0x7704d4: 8d45ec                           lea    eax,[ebp-0x14]
0x7704d7: 50                               push   eax
0x7704d8: 8d4dd4                           lea    ecx,[ebp-0x2c]
0x7704db: 897dec                           mov    DWORD PTR [ebp-0x14],edi
0x7704de: e8c60b1200                       call   0x8910a9
0x7704e3: 68a857c800                       push   0xc857a8
0x7704e8: 8d4dd4                           lea    ecx,[ebp-0x2c]
0x7704eb: 51                               push   ecx
0x7704ec: c745d4a42cbd00                   mov    DWORD PTR [ebp-0x2c],0xbd2ca4
0x7704f3: e8f8c41200                       call   0x89c9f0

## F-770DA0 VA 0x770da0..0x770e4c raw 0x3701a0 len 172 SHA256 d0ffdf91cb4e873b6c8d16fce9cb63538a21545de1a9efb9749805e364fcfe71
0x770da0: 55                               push   ebp
0x770da1: 8bec                             mov    ebp,esp
0x770da3: 6aff                             push   0xffffffff
0x770da5: 6858589000                       push   0x905858
0x770daa: 64a100000000                     mov    eax,fs:0x0
0x770db0: 50                               push   eax
0x770db1: 83ec10                           sub    esp,0x10
0x770db4: 56                               push   esi
0x770db5: a1201fd600                       mov    eax,ds:0xd61f20
0x770dba: 33c5                             xor    eax,ebp
0x770dbc: 50                               push   eax
0x770dbd: 8d45f4                           lea    eax,[ebp-0xc]
0x770dc0: 64a300000000                     mov    fs:0x0,eax
0x770dc6: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x770dc9: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x770dd0: c706bcdac400                     mov    DWORD PTR [esi],0xc4dabc
0x770dd6: 6a18                             push   0x18
0x770dd8: c7460c00000000                   mov    DWORD PTR [esi+0xc],0x0
0x770ddf: e884041200                       call   0x891268
0x770de4: 83c404                           add    esp,0x4
0x770de7: 85c0                             test   eax,eax
0x770de9: 7439                             je     0x770e24
0x770deb: 894608                           mov    DWORD PTR [esi+0x8],eax
0x770dee: 8900                             mov    DWORD PTR [eax],eax
0x770df0: 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x770df3: 894004                           mov    DWORD PTR [eax+0x4],eax
0x770df6: 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x770df9: 894008                           mov    DWORD PTR [eax+0x8],eax
0x770dfc: 8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
0x770dff: b001                             mov    al,0x1
0x770e01: 884114                           mov    BYTE PTR [ecx+0x14],al
0x770e04: 8b5608                           mov    edx,DWORD PTR [esi+0x8]
0x770e07: 884215                           mov    BYTE PTR [edx+0x15],al
0x770e0a: c7068cdac400                     mov    DWORD PTR [esi],0xc4da8c
0x770e10: 8bc6                             mov    eax,esi
0x770e12: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x770e15: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x770e1c: 59                               pop    ecx
0x770e1d: 5e                               pop    esi
0x770e1e: 8be5                             mov    esp,ebp
0x770e20: 5d                               pop    ebp
0x770e21: c20400                           ret    0x4
0x770e24: 8d45f0                           lea    eax,[ebp-0x10]
0x770e27: 50                               push   eax
0x770e28: 8d4de4                           lea    ecx,[ebp-0x1c]
0x770e2b: c745f000000000                   mov    DWORD PTR [ebp-0x10],0x0
0x770e32: e872021200                       call   0x8910a9
0x770e37: 68a857c800                       push   0xc857a8
0x770e3c: 8d4de4                           lea    ecx,[ebp-0x1c]
0x770e3f: 51                               push   ecx
0x770e40: c745e4a42cbd00                   mov    DWORD PTR [ebp-0x1c],0xbd2ca4
0x770e47: e8a4bb1200                       call   0x89c9f0

## F-5CA940 VA 0x5ca940..0x5caad6 raw 0x1c9d40 len 406 SHA256 31260de40c6bd9ad175f9ed8b75365665a4433b9f853a569b0abbd7dd3995289
0x5ca940: 55                               push   ebp
0x5ca941: 8bec                             mov    ebp,esp
0x5ca943: 6aff                             push   0xffffffff
0x5ca945: 68d6cd9000                       push   0x90cdd6
0x5ca94a: 64a100000000                     mov    eax,fs:0x0
0x5ca950: 50                               push   eax
0x5ca951: 83ec14                           sub    esp,0x14
0x5ca954: 53                               push   ebx
0x5ca955: 56                               push   esi
0x5ca956: 57                               push   edi
0x5ca957: a1201fd600                       mov    eax,ds:0xd61f20
0x5ca95c: 33c5                             xor    eax,ebp
0x5ca95e: 50                               push   eax
0x5ca95f: 8d45f4                           lea    eax,[ebp-0xc]
0x5ca962: 64a300000000                     mov    fs:0x0,eax
0x5ca968: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x5ca96b: f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x5ca973: 33db                             xor    ebx,ebx
0x5ca975: f30f114704                       movss  DWORD PTR [edi+0x4],xmm0
0x5ca97a: f30f11470c                       movss  DWORD PTR [edi+0xc],xmm0
0x5ca97f: f30f114708                       movss  DWORD PTR [edi+0x8],xmm0
0x5ca984: f30f114710                       movss  DWORD PTR [edi+0x10],xmm0
0x5ca989: 895f14                           mov    DWORD PTR [edi+0x14],ebx
0x5ca98c: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x5ca98f: c707ecffc100                     mov    DWORD PTR [edi],0xc1ffec
0x5ca995: 895f18                           mov    DWORD PTR [edi+0x18],ebx
0x5ca998: 895f24                           mov    DWORD PTR [edi+0x24],ebx
0x5ca99b: 895f28                           mov    DWORD PTR [edi+0x28],ebx
0x5ca99e: 895f2c                           mov    DWORD PTR [edi+0x2c],ebx
0x5ca9a1: c7473004000000                   mov    DWORD PTR [edi+0x30],0x4
0x5ca9a8: 895f34                           mov    DWORD PTR [edi+0x34],ebx
0x5ca9ab: 895f38                           mov    DWORD PTR [edi+0x38],ebx
0x5ca9ae: 6a18                             push   0x18
0x5ca9b0: 895f50                           mov    DWORD PTR [edi+0x50],ebx
0x5ca9b3: e8b0682c00                       call   0x891268
0x5ca9b8: 83c404                           add    esp,0x4
0x5ca9bb: 3bc3                             cmp    eax,ebx
0x5ca9bd: 0f84ef000000                     je     0x5caab2
0x5ca9c3: 89474c                           mov    DWORD PTR [edi+0x4c],eax
0x5ca9c6: 8900                             mov    DWORD PTR [eax],eax
0x5ca9c8: 8b474c                           mov    eax,DWORD PTR [edi+0x4c]
0x5ca9cb: 894004                           mov    DWORD PTR [eax+0x4],eax
0x5ca9ce: 8b474c                           mov    eax,DWORD PTR [edi+0x4c]
0x5ca9d1: 894008                           mov    DWORD PTR [eax+0x8],eax
0x5ca9d4: 8b474c                           mov    eax,DWORD PTR [edi+0x4c]
0x5ca9d7: c6401401                         mov    BYTE PTR [eax+0x14],0x1
0x5ca9db: 8b4f4c                           mov    ecx,DWORD PTR [edi+0x4c]
0x5ca9de: c6411501                         mov    BYTE PTR [ecx+0x15],0x1
0x5ca9e2: 6880000000                       push   0x80
0x5ca9e7: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x5ca9eb: e878682c00                       call   0x891268
0x5ca9f0: 8bf0                             mov    esi,eax
0x5ca9f2: 83c404                           add    esp,0x4
0x5ca9f5: 8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x5ca9f8: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x5ca9fc: 3bf3                             cmp    esi,ebx
0x5ca9fe: 7422                             je     0x5caa22
0x5caa00: 68105d5f00                       push   0x5f5d10
0x5caa05: 6850d97400                       push   0x74d950
0x5caa0a: 6a06                             push   0x6
0x5caa0c: 6a14                             push   0x14
0x5caa0e: 8d5604                           lea    edx,[esi+0x4]
0x5caa11: 52                               push   edx
0x5caa12: c70660e2c400                     mov    DWORD PTR [esi],0xc4e260
0x5caa18: e8e6752c00                       call   0x892003
0x5caa1d: 895e7c                           mov    DWORD PTR [esi+0x7c],ebx
0x5caa20: eb02                             jmp    0x5caa24
0x5caa22: 33f6                             xor    esi,esi
0x5caa24: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x5caa28: 688c000000                       push   0x8c
0x5caa2d: 897744                           mov    DWORD PTR [edi+0x44],esi
0x5caa30: e833682c00                       call   0x891268
0x5caa35: 83c404                           add    esp,0x4
0x5caa38: 8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x5caa3b: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x5caa3f: 3bc3                             cmp    eax,ebx
0x5caa41: 740b                             je     0x5caa4e
0x5caa43: 6a03                             push   0x3
0x5caa45: 8bf0                             mov    esi,eax
0x5caa47: e864aa1a00                       call   0x7754b0
0x5caa4c: eb02                             jmp    0x5caa50
0x5caa4e: 33c0                             xor    eax,eax
0x5caa50: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x5caa54: 688c000000                       push   0x8c
0x5caa59: 89473c                           mov    DWORD PTR [edi+0x3c],eax
0x5caa5c: e807682c00                       call   0x891268
0x5caa61: 83c404                           add    esp,0x4
0x5caa64: 8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x5caa67: c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x5caa6b: 3bc3                             cmp    eax,ebx
0x5caa6d: 740a                             je     0x5caa79
0x5caa6f: 53                               push   ebx
0x5caa70: 8bf0                             mov    esi,eax
0x5caa72: e839aa1a00                       call   0x7754b0
0x5caa77: eb02                             jmp    0x5caa7b
0x5caa79: 33c0                             xor    eax,eax
0x5caa7b: f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x5caa83: 894740                           mov    DWORD PTR [edi+0x40],eax
0x5caa86: 8b473c                           mov    eax,DWORD PTR [edi+0x3c]
0x5caa89: f30f118088000000                 movss  DWORD PTR [eax+0x88],xmm0
0x5caa91: 8b4f40                           mov    ecx,DWORD PTR [edi+0x40]
0x5caa94: f30f118188000000                 movss  DWORD PTR [ecx+0x88],xmm0
0x5caa9c: 8bc7                             mov    eax,edi
0x5caa9e: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5caaa1: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5caaa8: 59                               pop    ecx
0x5caaa9: 5f                               pop    edi
0x5caaaa: 5e                               pop    esi
0x5caaab: 5b                               pop    ebx
0x5caaac: 8be5                             mov    esp,ebp
0x5caaae: 5d                               pop    ebp
0x5caaaf: c20400                           ret    0x4
0x5caab2: 8d55f0                           lea    edx,[ebp-0x10]
0x5caab5: 52                               push   edx
0x5caab6: 8d4de0                           lea    ecx,[ebp-0x20]
0x5caab9: 895df0                           mov    DWORD PTR [ebp-0x10],ebx
0x5caabc: e8e8652c00                       call   0x8910a9
0x5caac1: 68a857c800                       push   0xc857a8
0x5caac6: 8d45e0                           lea    eax,[ebp-0x20]
0x5caac9: 50                               push   eax
0x5caaca: c745e0a42cbd00                   mov    DWORD PTR [ebp-0x20],0xbd2ca4
0x5caad1: e81a1f2d00                       call   0x89c9f0

## F-734EF0 VA 0x734ef0..0x735120 raw 0x3342f0 len 560 SHA256 138361d943ad5db2ee732abf13f90dd872635c081e3d82b9cbbcc63113a85878
0x734ef0: 55                               push   ebp
0x734ef1: 8bec                             mov    ebp,esp
0x734ef3: 6aff                             push   0xffffffff
0x734ef5: 68000c9200                       push   0x920c00
0x734efa: 64a100000000                     mov    eax,fs:0x0
0x734f00: 50                               push   eax
0x734f01: 83ec7c                           sub    esp,0x7c
0x734f04: a1201fd600                       mov    eax,ds:0xd61f20
0x734f09: 33c5                             xor    eax,ebp
0x734f0b: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x734f0e: 53                               push   ebx
0x734f0f: 56                               push   esi
0x734f10: 57                               push   edi
0x734f11: 50                               push   eax
0x734f12: 8d45f4                           lea    eax,[ebp-0xc]
0x734f15: 64a300000000                     mov    fs:0x0,eax
0x734f1b: 33ff                             xor    edi,edi
0x734f1d: 6a64                             push   0x64
0x734f1f: c78578ffffff707bfb00             mov    DWORD PTR [ebp-0x88],0xfb7b70
0x734f29: 893d707bfb00                     mov    DWORD PTR ds:0xfb7b70,edi
0x734f2f: 893d747bfb00                     mov    DWORD PTR ds:0xfb7b74,edi
0x734f35: 893d847bfb00                     mov    DWORD PTR ds:0xfb7b84,edi
0x734f3b: e828c31500                       call   0x891268
0x734f40: 83c404                           add    esp,0x4
0x734f43: 3bc7                             cmp    eax,edi
0x734f45: 0f84b1010000                     je     0x7350fc
0x734f4b: a3807bfb00                       mov    ds:0xfb7b80,eax
0x734f50: 8900                             mov    DWORD PTR [eax],eax
0x734f52: a1807bfb00                       mov    eax,ds:0xfb7b80
0x734f57: 894004                           mov    DWORD PTR [eax+0x4],eax
0x734f5a: a1807bfb00                       mov    eax,ds:0xfb7b80
0x734f5f: 894008                           mov    DWORD PTR [eax+0x8],eax
0x734f62: a1807bfb00                       mov    eax,ds:0xfb7b80
0x734f67: bb01000000                       mov    ebx,0x1
0x734f6c: 885860                           mov    BYTE PTR [eax+0x60],bl
0x734f6f: 8b0d807bfb00                     mov    ecx,DWORD PTR ds:0xfb7b80
0x734f75: 885961                           mov    BYTE PTR [ecx+0x61],bl
0x734f78: 897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x734f7b: 83c8ff                           or     eax,0xffffffff
0x734f7e: 6a14                             push   0x14
0x734f80: a38c7bfb00                       mov    ds:0xfb7b8c,eax
0x734f85: a3907bfb00                       mov    ds:0xfb7b90,eax
0x734f8a: 893d9c7bfb00                     mov    DWORD PTR ds:0xfb7b9c,edi
0x734f90: e8d3c21500                       call   0x891268
0x734f95: 83c404                           add    esp,0x4
0x734f98: 3bc7                             cmp    eax,edi
0x734f9a: 0f842f010000                     je     0x7350cf
0x734fa0: a3987bfb00                       mov    ds:0xfb7b98,eax
0x734fa5: 8900                             mov    DWORD PTR [eax],eax
0x734fa7: a1987bfb00                       mov    eax,ds:0xfb7b98
0x734fac: 894004                           mov    DWORD PTR [eax+0x4],eax
0x734faf: a1987bfb00                       mov    eax,ds:0xfb7b98
0x734fb4: 894008                           mov    DWORD PTR [eax+0x8],eax
0x734fb7: 8b15987bfb00                     mov    edx,DWORD PTR ds:0xfb7b98
0x734fbd: 885a10                           mov    BYTE PTR [edx+0x10],bl
0x734fc0: a1987bfb00                       mov    eax,ds:0xfb7b98
0x734fc5: 885811                           mov    BYTE PTR [eax+0x11],bl
0x734fc8: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x734fcb: 6818090000                       push   0x918
0x734fd0: 893dac7bfb00                     mov    DWORD PTR ds:0xfb7bac,edi
0x734fd6: 891db07bfb00                     mov    DWORD PTR ds:0xfb7bb0,ebx
0x734fdc: 891dc47bfb00                     mov    DWORD PTR ds:0xfb7bc4,ebx
0x734fe2: 893db47bfb00                     mov    DWORD PTR ds:0xfb7bb4,edi
0x734fe8: e87bc21500                       call   0x891268
0x734fed: 83c404                           add    esp,0x4
0x734ff0: 3bc7                             cmp    eax,edi
0x734ff2: 7409                             je     0x734ffd
0x734ff4: 8bf0                             mov    esi,eax
0x734ff6: e8b5f9ffff                       call   0x7349b0
0x734ffb: eb02                             jmp    0x734fff
0x734ffd: 33c0                             xor    eax,eax
0x734fff: a3a87bfb00                       mov    ds:0xfb7ba8,eax
0x735004: e8477f0000                       call   0x73cf50
0x735009: a3787bfb00                       mov    ds:0xfb7b78,eax
0x73500e: a1a87bfb00                       mov    eax,ds:0xfb7ba8
0x735013: c705b87bfb0003000000             mov    DWORD PTR ds:0xfb7bb8,0x3
0x73501d: c705bc7bfb003c000000             mov    DWORD PTR ds:0xfb7bbc,0x3c
0x735027: c705c07bfb00100e0000             mov    DWORD PTR ds:0xfb7bc0,0xe10
0x735031: c7401000080000                   mov    DWORD PTR [eax+0x10],0x800
0x735038: c7401400040000                   mov    DWORD PTR [eax+0x14],0x400
0x73503f: c7400820000000                   mov    DWORD PTR [eax+0x8],0x20
0x735046: c7400c33000000                   mov    DWORD PTR [eax+0xc],0x33
0x73504d: c70040000000                     mov    DWORD PTR [eax],0x40
0x735053: c7400414000000                   mov    DWORD PTR [eax+0x4],0x14
0x73505a: e8a1f9ffff                       call   0x734a00
0x73505f: 6a40                             push   0x40
0x735061: 8d4da0                           lea    ecx,[ebp-0x60]
0x735064: 57                               push   edi
0x735065: 51                               push   ecx
0x735066: 897de0                           mov    DWORD PTR [ebp-0x20],edi
0x735069: e8f2971600                       call   0x89e860
0x73506e: 83c40c                           add    esp,0xc
0x735071: 689813c100                       push   0xc11398
0x735076: 8d55a0                           lea    edx,[ebp-0x60]
0x735079: 6a20                             push   0x20
0x73507b: 52                               push   edx
0x73507c: c745e40c000000                   mov    DWORD PTR [ebp-0x1c],0xc
0x735083: c745e804000000                   mov    DWORD PTR [ebp-0x18],0x4
0x73508a: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x73508d: e8bbdd1500                       call   0x892e4d
0x735092: 83c40c                           add    esp,0xc
0x735095: 8d4594                           lea    eax,[ebp-0x6c]
0x735098: 50                               push   eax
0x735099: 68707bfb00                       push   0xfb7b70
0x73509e: 8d45a0                           lea    eax,[ebp-0x60]
0x7350a1: e8aa070000                       call   0x735850
0x7350a6: 8b08                             mov    ecx,DWORD PTR [eax]
0x7350a8: 890d8c7bfb00                     mov    DWORD PTR ds:0xfb7b8c,ecx
0x7350ae: b8707bfb00                       mov    eax,0xfb7b70
0x7350b3: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7350b6: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7350bd: 59                               pop    ecx
0x7350be: 5f                               pop    edi
0x7350bf: 5e                               pop    esi
0x7350c0: 5b                               pop    ebx
0x7350c1: 8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x7350c4: 33cd                             xor    ecx,ebp
0x7350c6: e836bf1500                       call   0x891001
0x7350cb: 8be5                             mov    esp,ebp
0x7350cd: 5d                               pop    ebp
0x7350ce: c3                               ret
0x7350cf: 8d5598                           lea    edx,[ebp-0x68]
0x7350d2: 52                               push   edx
0x7350d3: 8d8d7cffffff                     lea    ecx,[ebp-0x84]
0x7350d9: 897d98                           mov    DWORD PTR [ebp-0x68],edi
0x7350dc: e8c8bf1500                       call   0x8910a9
0x7350e1: 68a857c800                       push   0xc857a8
0x7350e6: 8d857cffffff                     lea    eax,[ebp-0x84]
0x7350ec: 50                               push   eax
0x7350ed: c7857cffffffa42cbd00             mov    DWORD PTR [ebp-0x84],0xbd2ca4
0x7350f7: e8f4781600                       call   0x89c9f0
0x7350fc: 8d4d9c                           lea    ecx,[ebp-0x64]
0x7350ff: 51                               push   ecx
0x735100: 8d4d88                           lea    ecx,[ebp-0x78]
0x735103: 897d9c                           mov    DWORD PTR [ebp-0x64],edi
0x735106: e89ebf1500                       call   0x8910a9
0x73510b: 68a857c800                       push   0xc857a8
0x735110: 8d5588                           lea    edx,[ebp-0x78]
0x735113: 52                               push   edx
0x735114: c74588a42cbd00                   mov    DWORD PTR [ebp-0x78],0xbd2ca4
0x73511b: e8d0781600                       call   0x89c9f0

## F-735850 VA 0x735850..0x7358a8 raw 0x334c50 len 88 SHA256 4651cc6676eb8e166ae9b3d3c622eaf2481f949f6fbb9d3564857d2b616bac26
0x735850: 55                               push   ebp
0x735851: 8bec                             mov    ebp,esp
0x735853: 83e4f8                           and    esp,0xfffffff8
0x735856: 83ec64                           sub    esp,0x64
0x735859: 53                               push   ebx
0x73585a: 8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
0x73585d: 56                               push   esi
0x73585e: 8bf0                             mov    esi,eax
0x735860: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x735863: 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x735866: 8b11                             mov    edx,DWORD PTR [ecx]
0x735868: 8b4228                           mov    eax,DWORD PTR [edx+0x28]
0x73586b: 57                               push   edi
0x73586c: 56                               push   esi
0x73586d: 53                               push   ebx
0x73586e: ffd0                             call   eax
0x735870: 8b0b                             mov    ecx,DWORD PTR [ebx]
0x735872: 894c2418                         mov    DWORD PTR [esp+0x18],ecx
0x735876: b914000000                       mov    ecx,0x14
0x73587b: 8d7c241c                         lea    edi,[esp+0x1c]
0x73587f: f3a5                             rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x735881: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x735884: 83c60c                           add    esi,0xc
0x735887: 8d442418                         lea    eax,[esp+0x18]
0x73588b: 8bce                             mov    ecx,esi
0x73588d: e86e0f0000                       call   0x736800
0x735892: 50                               push   eax
0x735893: 56                               push   esi
0x735894: 8d742418                         lea    esi,[esp+0x18]
0x735898: e8c30c0000                       call   0x736560
0x73589d: 5f                               pop    edi
0x73589e: 5e                               pop    esi
0x73589f: 8bc3                             mov    eax,ebx
0x7358a1: 5b                               pop    ebx
0x7358a2: 8be5                             mov    esp,ebp
0x7358a4: 5d                               pop    ebp
0x7358a5: c20800                           ret    0x8

## F-735190 VA 0x735190..0x735275 raw 0x334590 len 229 SHA256 9f6492262bea5a95290c4677a65abc8a5f8823339a5c210e698056d2f5119ea1
0x735190: 55                               push   ebp
0x735191: 8bec                             mov    ebp,esp
0x735193: 6aff                             push   0xffffffff
0x735195: 68baca9000                       push   0x90caba
0x73519a: 64a100000000                     mov    eax,fs:0x0
0x7351a0: 50                               push   eax
0x7351a1: 83ec0c                           sub    esp,0xc
0x7351a4: 56                               push   esi
0x7351a5: a1201fd600                       mov    eax,ds:0xd61f20
0x7351aa: 33c5                             xor    eax,ebp
0x7351ac: 50                               push   eax
0x7351ad: 8d45f4                           lea    eax,[ebp-0xc]
0x7351b0: 64a300000000                     mov    fs:0x0,eax
0x7351b6: c745f0707bfb00                   mov    DWORD PTR [ebp-0x10],0xfb7b70
0x7351bd: 68947bfb00                       push   0xfb7b94
0x7351c2: c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0x7351c9: e8b2120000                       call   0x736480
0x7351ce: 8b0d787bfb00                     mov    ecx,DWORD PTR ds:0xfb7b78
0x7351d4: 33f6                             xor    esi,esi
0x7351d6: 83c404                           add    esp,0x4
0x7351d9: 3bce                             cmp    ecx,esi
0x7351db: 740e                             je     0x7351eb
0x7351dd: 8b01                             mov    eax,DWORD PTR [ecx]
0x7351df: 8b10                             mov    edx,DWORD PTR [eax]
0x7351e1: 6a01                             push   0x1
0x7351e3: ffd2                             call   edx
0x7351e5: 8935787bfb00                     mov    DWORD PTR ds:0xfb7b78,esi
0x7351eb: a1a87bfb00                       mov    eax,ds:0xfb7ba8
0x7351f0: 3bc6                             cmp    eax,esi
0x7351f2: 740f                             je     0x735203
0x7351f4: 50                               push   eax
0x7351f5: e812c01500                       call   0x89120c
0x7351fa: 83c404                           add    esp,0x4
0x7351fd: 8935a87bfb00                     mov    DWORD PTR ds:0xfb7ba8,esi
0x735203: c745ec947bfb00                   mov    DWORD PTR [ebp-0x14],0xfb7b94
0x73520a: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x73520e: a1987bfb00                       mov    eax,ds:0xfb7b98
0x735213: 8b08                             mov    ecx,DWORD PTR [eax]
0x735215: 50                               push   eax
0x735216: 51                               push   ecx
0x735217: 8d75e8                           lea    esi,[ebp-0x18]
0x73521a: b8947bfb00                       mov    eax,0xfb7b94
0x73521f: e83c4fd9ff                       call   0x4ca160
0x735224: a1987bfb00                       mov    eax,ds:0xfb7b98
0x735229: 50                               push   eax
0x73522a: e8ddbf1500                       call   0x89120c
0x73522f: 83c404                           add    esp,0x4
0x735232: c745e87c7bfb00                   mov    DWORD PTR [ebp-0x18],0xfb7b7c
0x735239: c745fc03000000                   mov    DWORD PTR [ebp-0x4],0x3
0x735240: a1807bfb00                       mov    eax,ds:0xfb7b80
0x735245: 8b08                             mov    ecx,DWORD PTR [eax]
0x735247: 50                               push   eax
0x735248: 51                               push   ecx
0x735249: 8d75ec                           lea    esi,[ebp-0x14]
0x73524c: b87c7bfb00                       mov    eax,0xfb7b7c
0x735251: e8ba100000                       call   0x736310
0x735256: 8b0d807bfb00                     mov    ecx,DWORD PTR ds:0xfb7b80
0x73525c: 51                               push   ecx
0x73525d: e8aabf1500                       call   0x89120c
0x735262: 83c404                           add    esp,0x4
0x735265: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x735268: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x73526f: 59                               pop    ecx
0x735270: 5e                               pop    esi
0x735271: 8be5                             mov    esp,ebp
0x735273: 5d                               pop    ebp
0x735274: c3                               ret

## F-73CF50 VA 0x73cf50..0x73cff6 raw 0x33c350 len 166 SHA256 46875446ca097907c34f0e91c01d67f7e248aad22f8e7b2ab667d59012d7af4e
0x73cf50: 55                               push   ebp
0x73cf51: 8bec                             mov    ebp,esp
0x73cf53: 6aff                             push   0xffffffff
0x73cf55: 68dbc09100                       push   0x91c0db
0x73cf5a: 64a100000000                     mov    eax,fs:0x0
0x73cf60: 50                               push   eax
0x73cf61: 83ec08                           sub    esp,0x8
0x73cf64: a1201fd600                       mov    eax,ds:0xd61f20
0x73cf69: 33c5                             xor    eax,ebp
0x73cf6b: 50                               push   eax
0x73cf6c: 8d45f4                           lea    eax,[ebp-0xc]
0x73cf6f: 64a300000000                     mov    fs:0x0,eax
0x73cf75: a120a8fb00                       mov    eax,ds:0xfba820
0x73cf7a: 48                               dec    eax
0x73cf7b: 743d                             je     0x73cfba
0x73cf7d: 6a28                             push   0x28
0x73cf7f: e8e4421500                       call   0x891268
0x73cf84: 33c9                             xor    ecx,ecx
0x73cf86: 83c404                           add    esp,0x4
0x73cf89: 3bc1                             cmp    eax,ecx
0x73cf8b: 7458                             je     0x73cfe5
0x73cf8d: 894804                           mov    DWORD PTR [eax+0x4],ecx
0x73cf90: 894808                           mov    DWORD PTR [eax+0x8],ecx
0x73cf93: c700945fc400                     mov    DWORD PTR [eax],0xc45f94
0x73cf99: 894818                           mov    DWORD PTR [eax+0x18],ecx
0x73cf9c: 89481c                           mov    DWORD PTR [eax+0x1c],ecx
0x73cf9f: 894820                           mov    DWORD PTR [eax+0x20],ecx
0x73cfa2: 89480c                           mov    DWORD PTR [eax+0xc],ecx
0x73cfa5: 894810                           mov    DWORD PTR [eax+0x10],ecx
0x73cfa8: 894814                           mov    DWORD PTR [eax+0x14],ecx
0x73cfab: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x73cfae: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x73cfb5: 59                               pop    ecx
0x73cfb6: 8be5                             mov    esp,ebp
0x73cfb8: 5d                               pop    ebp
0x73cfb9: c3                               ret
0x73cfba: 6a54                             push   0x54
0x73cfbc: e8a7421500                       call   0x891268
0x73cfc1: 83c404                           add    esp,0x4
0x73cfc4: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x73cfc7: 33c9                             xor    ecx,ecx
0x73cfc9: 894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0x73cfcc: 3bc1                             cmp    eax,ecx
0x73cfce: 7415                             je     0x73cfe5
0x73cfd0: 50                               push   eax
0x73cfd1: e87af4ffff                       call   0x73c450
0x73cfd6: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x73cfd9: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x73cfe0: 59                               pop    ecx
0x73cfe1: 8be5                             mov    esp,ebp
0x73cfe3: 5d                               pop    ebp
0x73cfe4: c3                               ret
0x73cfe5: 33c0                             xor    eax,eax
0x73cfe7: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x73cfea: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x73cff1: 59                               pop    ecx
0x73cff2: 8be5                             mov    esp,ebp
0x73cff4: 5d                               pop    ebp
0x73cff5: c3                               ret

## F-73C450 VA 0x73c450..0x73c5ab raw 0x33b850 len 347 SHA256 27541b24b8ec7d557ea25d257475c997b85eb4d247608797dc82f0da2cfa51c6
0x73c450: 55                               push   ebp
0x73c451: 8bec                             mov    ebp,esp
0x73c453: 6aff                             push   0xffffffff
0x73c455: 6855f39100                       push   0x91f355
0x73c45a: 64a100000000                     mov    eax,fs:0x0
0x73c460: 50                               push   eax
0x73c461: 53                               push   ebx
0x73c462: 56                               push   esi
0x73c463: 57                               push   edi
0x73c464: a1201fd600                       mov    eax,ds:0xd61f20
0x73c469: 33c5                             xor    eax,ebp
0x73c46b: 50                               push   eax
0x73c46c: 8d45f4                           lea    eax,[ebp-0xc]
0x73c46f: 64a300000000                     mov    fs:0x0,eax
0x73c475: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x73c478: 33c0                             xor    eax,eax
0x73c47a: 894304                           mov    DWORD PTR [ebx+0x4],eax
0x73c47d: 894308                           mov    DWORD PTR [ebx+0x8],eax
0x73c480: 8d730c                           lea    esi,[ebx+0xc]
0x73c483: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x73c486: 56                               push   esi
0x73c487: c703ec5fc400                     mov    DWORD PTR [ebx],0xc45fec
0x73c48d: e86e0b0000                       call   0x73d000
0x73c492: 6a01                             push   0x1
0x73c494: 8d7b14                           lea    edi,[ebx+0x14]
0x73c497: 57                               push   edi
0x73c498: b9585cc400                       mov    ecx,0xc45c58
0x73c49d: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x73c4a1: e8da420000                       call   0x740780
0x73c4a6: 6a01                             push   0x1
0x73c4a8: 57                               push   edi
0x73c4a9: b96c5cc400                       mov    ecx,0xc45c6c
0x73c4ae: e8cd420000                       call   0x740780
0x73c4b3: 6a01                             push   0x1
0x73c4b5: 57                               push   edi
0x73c4b6: b9845cc400                       mov    ecx,0xc45c84
0x73c4bb: e8c0420000                       call   0x740780
0x73c4c0: 6a01                             push   0x1
0x73c4c2: 57                               push   edi
0x73c4c3: b99c5cc400                       mov    ecx,0xc45c9c
0x73c4c8: e8b3420000                       call   0x740780
0x73c4cd: 6a01                             push   0x1
0x73c4cf: 57                               push   edi
0x73c4d0: b9b85cc400                       mov    ecx,0xc45cb8
0x73c4d5: e8a6420000                       call   0x740780
0x73c4da: 6a01                             push   0x1
0x73c4dc: 57                               push   edi
0x73c4dd: b9d05cc400                       mov    ecx,0xc45cd0
0x73c4e2: e899420000                       call   0x740780
0x73c4e7: 6a01                             push   0x1
0x73c4e9: 57                               push   edi
0x73c4ea: b9e85cc400                       mov    ecx,0xc45ce8
0x73c4ef: e88c420000                       call   0x740780
0x73c4f4: 6a01                             push   0x1
0x73c4f6: 57                               push   edi
0x73c4f7: b9005dc400                       mov    ecx,0xc45d00
0x73c4fc: e87f420000                       call   0x740780
0x73c501: 6a00                             push   0x0
0x73c503: 57                               push   edi
0x73c504: b91c5dc400                       mov    ecx,0xc45d1c
0x73c509: e872420000                       call   0x740780
0x73c50e: 6a00                             push   0x0
0x73c510: 57                               push   edi
0x73c511: b94c5dc400                       mov    ecx,0xc45d4c
0x73c516: e865420000                       call   0x740780
0x73c51b: 6a00                             push   0x0
0x73c51d: 57                               push   edi
0x73c51e: b9845dc400                       mov    ecx,0xc45d84
0x73c523: e858420000                       call   0x740780
0x73c528: 6a00                             push   0x0
0x73c52a: 57                               push   edi
0x73c52b: b9b45dc400                       mov    ecx,0xc45db4
0x73c530: e84b420000                       call   0x740780
0x73c535: 6a00                             push   0x0
0x73c537: 57                               push   edi
0x73c538: b9e05dc400                       mov    ecx,0xc45de0
0x73c53d: e83e420000                       call   0x740780
0x73c542: 6a00                             push   0x0
0x73c544: 57                               push   edi
0x73c545: b9145ec400                       mov    ecx,0xc45e14
0x73c54a: e831420000                       call   0x740780
0x73c54f: 6a00                             push   0x0
0x73c551: 57                               push   edi
0x73c552: b9445ec400                       mov    ecx,0xc45e44
0x73c557: e824420000                       call   0x740780
0x73c55c: 6a00                             push   0x0
0x73c55e: 57                               push   edi
0x73c55f: b9705ec400                       mov    ecx,0xc45e70
0x73c564: e817420000                       call   0x740780
0x73c569: 6a00                             push   0x0
0x73c56b: 57                               push   edi
0x73c56c: b99c5ec400                       mov    ecx,0xc45e9c
0x73c571: e80a420000                       call   0x740780
0x73c576: 6a00                             push   0x0
0x73c578: 57                               push   edi
0x73c579: b9c05ec400                       mov    ecx,0xc45ec0
0x73c57e: e8fd410000                       call   0x740780
0x73c583: 6a00                             push   0x0
0x73c585: 57                               push   edi
0x73c586: b9e85ec400                       mov    ecx,0xc45ee8
0x73c58b: e8f0410000                       call   0x740780
0x73c590: e8db0b0000                       call   0x73d170
0x73c595: 8bc3                             mov    eax,ebx
0x73c597: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x73c59a: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x73c5a1: 59                               pop    ecx
0x73c5a2: 5f                               pop    edi
0x73c5a3: 5e                               pop    esi
0x73c5a4: 5b                               pop    ebx
0x73c5a5: 8be5                             mov    esp,ebp
0x73c5a7: 5d                               pop    ebp
0x73c5a8: c20400                           ret    0x4

## F-73BB50 VA 0x73bb50..0x73bc8f raw 0x33af50 len 319 SHA256 2658ffcda5fe412b40d628a321b290759cbc994e5e0cd28d2e743c3fe5522aa1
0x73bb50: 55                               push   ebp
0x73bb51: 8bec                             mov    ebp,esp
0x73bb53: 83ec6c                           sub    esp,0x6c
0x73bb56: a1201fd600                       mov    eax,ds:0xd61f20
0x73bb5b: 33c5                             xor    eax,ebp
0x73bb5d: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x73bb60: 53                               push   ebx
0x73bb61: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x73bb64: 56                               push   esi
0x73bb65: 8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0x73bb68: 57                               push   edi
0x73bb69: 56                               push   esi
0x73bb6a: 8bf9                             mov    edi,ecx
0x73bb6c: 894d9c                           mov    DWORD PTR [ebp-0x64],ecx
0x73bb6f: e84cffffff                       call   0x73bac0
0x73bb74: 85c0                             test   eax,eax
0x73bb76: 781c                             js     0x73bb94
0x73bb78: 8bcf                             mov    ecx,edi
0x73bb7a: 8b5118                           mov    edx,DWORD PTR [ecx+0x18]
0x73bb7d: 8b0c82                           mov    ecx,DWORD PTR [edx+eax*4]
0x73bb80: ff81b0000000                     inc    DWORD PTR [ecx+0xb0]
0x73bb86: 8bc8                             mov    ecx,eax
0x73bb88: 8bc3                             mov    eax,ebx
0x73bb8a: e8215ee3ff                       call   0x5719b0
0x73bb8f: e9e6000000                       jmp    0x73bc7a
0x73bb94: 6a5c                             push   0x5c
0x73bb96: 8d45a0                           lea    eax,[ebp-0x60]
0x73bb99: 6a00                             push   0x0
0x73bb9b: 50                               push   eax
0x73bb9c: e8bf2c1600                       call   0x89e860
0x73bba1: 6a1f                             push   0x1f
0x73bba3: 56                               push   esi
0x73bba4: 8d4dbc                           lea    ecx,[ebp-0x44]
0x73bba7: 6a20                             push   0x20
0x73bba9: 51                               push   ecx
0x73bbaa: e84f841500                       call   0x893ffe
0x73bbaf: 8b4644                           mov    eax,DWORD PTR [esi+0x44]
0x73bbb2: 8b5640                           mov    edx,DWORD PTR [esi+0x40]
0x73bbb5: 8945a0                           mov    DWORD PTR [ebp-0x60],eax
0x73bbb8: 8b4648                           mov    eax,DWORD PTR [esi+0x48]
0x73bbbb: 83c41c                           add    esp,0x1c
0x73bbbe: 8955a4                           mov    DWORD PTR [ebp-0x5c],edx
0x73bbc1: e88afeffff                       call   0x73ba50
0x73bbc6: 8945b0                           mov    DWORD PTR [ebp-0x50],eax
0x73bbc9: 8b464c                           mov    eax,DWORD PTR [esi+0x4c]
0x73bbcc: 83e800                           sub    eax,0x0
0x73bbcf: 7408                             je     0x73bbd9
0x73bbd1: 48                               dec    eax
0x73bbd2: b804000000                       mov    eax,0x4
0x73bbd7: eb05                             jmp    0x73bbde
0x73bbd9: b803000000                       mov    eax,0x3
0x73bbde: 8d4da0                           lea    ecx,[ebp-0x60]
0x73bbe1: 51                               push   ecx
0x73bbe2: 8845ba                           mov    BYTE PTR [ebp-0x46],al
0x73bbe5: ff156420bd00                     call   DWORD PTR ds:0xbd2064
0x73bbeb: 894598                           mov    DWORD PTR [ebp-0x68],eax
0x73bbee: 85c0                             test   eax,eax
0x73bbf0: 7514                             jne    0x73bc06
0x73bbf2: ff150023bd00                     call   DWORD PTR ds:0xbd2300
0x73bbf8: 50                               push   eax
0x73bbf9: 68385cc400                       push   0xc45c38
0x73bbfe: e8ba741500                       call   0x8930bd
0x73bc03: 83c408                           add    esp,0x8
0x73bc06: 68b4000000                       push   0xb4
0x73bc0b: e858561500                       call   0x891268
0x73bc10: 8bf8                             mov    edi,eax
0x73bc12: 33c0                             xor    eax,eax
0x73bc14: 83c404                           add    esp,0x4
0x73bc17: 3bf8                             cmp    edi,eax
0x73bc19: 741a                             je     0x73bc35
0x73bc1b: 6a40                             push   0x40
0x73bc1d: 50                               push   eax
0x73bc1e: 57                               push   edi
0x73bc1f: 894740                           mov    DWORD PTR [edi+0x40],eax
0x73bc22: 894744                           mov    DWORD PTR [edi+0x44],eax
0x73bc25: 894748                           mov    DWORD PTR [edi+0x48],eax
0x73bc28: 89474c                           mov    DWORD PTR [edi+0x4c],eax
0x73bc2b: e8302c1600                       call   0x89e860
0x73bc30: 83c40c                           add    esp,0xc
0x73bc33: 8bc7                             mov    eax,edi
0x73bc35: 8b5598                           mov    edx,DWORD PTR [ebp-0x68]
0x73bc38: 8bf8                             mov    edi,eax
0x73bc3a: b914000000                       mov    ecx,0x14
0x73bc3f: f3a5                             rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x73bc41: 8d7850                           lea    edi,[eax+0x50]
0x73bc44: b917000000                       mov    ecx,0x17
0x73bc49: 8d75a0                           lea    esi,[ebp-0x60]
0x73bc4c: f3a5                             rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x73bc4e: 8b7d9c                           mov    edi,DWORD PTR [ebp-0x64]
0x73bc51: 8990ac000000                     mov    DWORD PTR [eax+0xac],edx
0x73bc57: 894594                           mov    DWORD PTR [ebp-0x6c],eax
0x73bc5a: c780b000000001000000             mov    DWORD PTR [eax+0xb0],0x1
0x73bc64: 83c718                           add    edi,0x18
0x73bc67: 8d4594                           lea    eax,[ebp-0x6c]
0x73bc6a: e8e1f60700                       call   0x7bb350
0x73bc6f: 8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x73bc72: 2b07                             sub    eax,DWORD PTR [edi]
0x73bc74: c1f802                           sar    eax,0x2
0x73bc77: 48                               dec    eax
0x73bc78: 8903                             mov    DWORD PTR [ebx],eax
0x73bc7a: 8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0x73bc7d: 5f                               pop    edi
0x73bc7e: 5e                               pop    esi
0x73bc7f: 8bc3                             mov    eax,ebx
0x73bc81: 33cd                             xor    ecx,ebp
0x73bc83: 5b                               pop    ebx
0x73bc84: e878531500                       call   0x891001
0x73bc89: 8be5                             mov    esp,ebp
0x73bc8b: 5d                               pop    ebp
0x73bc8c: c20800                           ret    0x8

## F-73C5B0 VA 0x73c5b0..0x73c790 raw 0x33b9b0 len 480 SHA256 8624beae56ae05d94f46548e1daeb8cbdc5d8bce9dba50acb5332ba644df7385
0x73c5b0: 55                               push   ebp
0x73c5b1: 8bec                             mov    ebp,esp
0x73c5b3: 6aff                             push   0xffffffff
0x73c5b5: 6813f39100                       push   0x91f313
0x73c5ba: 64a100000000                     mov    eax,fs:0x0
0x73c5c0: 50                               push   eax
0x73c5c1: 81ec80000000                     sub    esp,0x80
0x73c5c7: a1201fd600                       mov    eax,ds:0xd61f20
0x73c5cc: 33c5                             xor    eax,ebp
0x73c5ce: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x73c5d1: 53                               push   ebx
0x73c5d2: 56                               push   esi
0x73c5d3: 57                               push   edi
0x73c5d4: 50                               push   eax
0x73c5d5: 8d45f4                           lea    eax,[ebp-0xc]
0x73c5d8: 64a300000000                     mov    fs:0x0,eax
0x73c5de: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x73c5e1: 8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0x73c5e4: 33db                             xor    ebx,ebx
0x73c5e6: bf0f000000                       mov    edi,0xf
0x73c5eb: 898d78ffffff                     mov    DWORD PTR [ebp-0x88],ecx
0x73c5f1: 898574ffffff                     mov    DWORD PTR [ebp-0x8c],eax
0x73c5f7: 897dc8                           mov    DWORD PTR [ebp-0x38],edi
0x73c5fa: 895dc4                           mov    DWORD PTR [ebp-0x3c],ebx
0x73c5fd: 885db4                           mov    BYTE PTR [ebp-0x4c],bl
0x73c600: 895dd0                           mov    DWORD PTR [ebp-0x30],ebx
0x73c603: 895dd4                           mov    DWORD PTR [ebp-0x2c],ebx
0x73c606: 895dd8                           mov    DWORD PTR [ebp-0x28],ebx
0x73c609: 895ddc                           mov    DWORD PTR [ebp-0x24],ebx
0x73c60c: 895de0                           mov    DWORD PTR [ebp-0x20],ebx
0x73c60f: 885de4                           mov    BYTE PTR [ebp-0x1c],bl
0x73c612: 895de8                           mov    DWORD PTR [ebp-0x18],ebx
0x73c615: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x73c618: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x73c61b: 33c9                             xor    ecx,ecx
0x73c61d: 8bc6                             mov    eax,esi
0x73c61f: c7459007000000                   mov    DWORD PTR [ebp-0x70],0x7
0x73c626: 895d8c                           mov    DWORD PTR [ebp-0x74],ebx
0x73c629: 66898d7cffffff                   mov    WORD PTR [ebp-0x84],cx
0x73c630: 8d5002                           lea    edx,[eax+0x2]
0x73c633: 668b08                           mov    cx,WORD PTR [eax]
0x73c636: 83c002                           add    eax,0x2
0x73c639: 663bcb                           cmp    cx,bx
0x73c63c: 75f5                             jne    0x73c633
0x73c63e: 2bc2                             sub    eax,edx
0x73c640: d1f8                             sar    eax,1
0x73c642: 50                               push   eax
0x73c643: 56                               push   esi
0x73c644: 8d8d7cffffff                     lea    ecx,[ebp-0x84]
0x73c64a: e8115bccff                       call   0x402160
0x73c64f: 897dac                           mov    DWORD PTR [ebp-0x54],edi
0x73c652: 895da8                           mov    DWORD PTR [ebp-0x58],ebx
0x73c655: 885d98                           mov    BYTE PTR [ebp-0x68],bl
0x73c658: 8d857cffffff                     lea    eax,[ebp-0x84]
0x73c65e: 8d4d98                           lea    ecx,[ebp-0x68]
0x73c661: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x73c665: e8a6d0ceff                       call   0x429710
0x73c66a: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x73c66e: 837dac10                         cmp    DWORD PTR [ebp-0x54],0x10
0x73c672: 8b5598                           mov    edx,DWORD PTR [ebp-0x68]
0x73c675: 7303                             jae    0x73c67a
0x73c677: 8d5598                           lea    edx,[ebp-0x68]
0x73c67a: 8bc2                             mov    eax,edx
0x73c67c: 8d7801                           lea    edi,[eax+0x1]
0x73c67f: 90                               nop
0x73c680: 8a08                             mov    cl,BYTE PTR [eax]
0x73c682: 40                               inc    eax
0x73c683: 3acb                             cmp    cl,bl
0x73c685: 75f9                             jne    0x73c680
0x73c687: 2bc7                             sub    eax,edi
0x73c689: 50                               push   eax
0x73c68a: 52                               push   edx
0x73c68b: 8d4db4                           lea    ecx,[ebp-0x4c]
0x73c68e: e8dd63ccff                       call   0x402a70
0x73c693: 837dac10                         cmp    DWORD PTR [ebp-0x54],0x10
0x73c697: 720c                             jb     0x73c6a5
0x73c699: 8b5598                           mov    edx,DWORD PTR [ebp-0x68]
0x73c69c: 52                               push   edx
0x73c69d: e86a4b1500                       call   0x89120c
0x73c6a2: 83c404                           add    esp,0x4
0x73c6a5: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x73c6a8: 837d9008                         cmp    DWORD PTR [ebp-0x70],0x8
0x73c6ac: c745ac0f000000                   mov    DWORD PTR [ebp-0x54],0xf
0x73c6b3: 895da8                           mov    DWORD PTR [ebp-0x58],ebx
0x73c6b6: 885d98                           mov    BYTE PTR [ebp-0x68],bl
0x73c6b9: 720f                             jb     0x73c6ca
0x73c6bb: 8b857cffffff                     mov    eax,DWORD PTR [ebp-0x84]
0x73c6c1: 50                               push   eax
0x73c6c2: e8454b1500                       call   0x89120c
0x73c6c7: 83c404                           add    esp,0x4
0x73c6ca: 8b4648                           mov    eax,DWORD PTR [esi+0x48]
0x73c6cd: 8b4e40                           mov    ecx,DWORD PTR [esi+0x40]
0x73c6d0: 8b5644                           mov    edx,DWORD PTR [esi+0x44]
0x73c6d3: 894dd0                           mov    DWORD PTR [ebp-0x30],ecx
0x73c6d6: 8955d4                           mov    DWORD PTR [ebp-0x2c],edx
0x73c6d9: bf02000000                       mov    edi,0x2
0x73c6de: 83f808                           cmp    eax,0x8
0x73c6e1: 7c05                             jl     0x73c6e8
0x73c6e3: 897dec                           mov    DWORD PTR [ebp-0x14],edi
0x73c6e6: eb0b                             jmp    0x73c6f3
0x73c6e8: 33c9                             xor    ecx,ecx
0x73c6ea: 83f807                           cmp    eax,0x7
0x73c6ed: 0f9dc1                           setge  cl
0x73c6f0: 894dec                           mov    DWORD PTR [ebp-0x14],ecx
0x73c6f3: 68285fc400                       push   0xc45f28
0x73c6f8: 56                               push   esi
0x73c6f9: e8daa91500                       call   0x8970d8
0x73c6fe: 83c408                           add    esp,0x8
0x73c701: 85c0                             test   eax,eax
0x73c703: 7510                             jne    0x73c715
0x73c705: b801000000                       mov    eax,0x1
0x73c70a: 8945d8                           mov    DWORD PTR [ebp-0x28],eax
0x73c70d: 897de8                           mov    DWORD PTR [ebp-0x18],edi
0x73c710: 8845e4                           mov    BYTE PTR [ebp-0x1c],al
0x73c713: eb28                             jmp    0x73c73d
0x73c715: 8b45d4                           mov    eax,DWORD PTR [ebp-0x2c]
0x73c718: 99                               cdq
0x73c719: 8bc8                             mov    ecx,eax
0x73c71b: 33ca                             xor    ecx,edx
0x73c71d: 2bca                             sub    ecx,edx
0x73c71f: b801000000                       mov    eax,0x1
0x73c724: 83f90c                           cmp    ecx,0xc
0x73c727: 7f08                             jg     0x73c731
0x73c729: 897dd8                           mov    DWORD PTR [ebp-0x28],edi
0x73c72c: 895de0                           mov    DWORD PTR [ebp-0x20],ebx
0x73c72f: eb06                             jmp    0x73c737
0x73c731: 895dd8                           mov    DWORD PTR [ebp-0x28],ebx
0x73c734: 8945e0                           mov    DWORD PTR [ebp-0x20],eax
0x73c737: 8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x73c73a: 885de4                           mov    BYTE PTR [ebp-0x1c],bl
0x73c73d: 8b9578ffffff                     mov    edx,DWORD PTR [ebp-0x88]
0x73c743: 83c20c                           add    edx,0xc
0x73c746: 52                               push   edx
0x73c747: 8d45b4                           lea    eax,[ebp-0x4c]
0x73c74a: e8e10d0000                       call   0x73d530
0x73c74f: 8bb574ffffff                     mov    esi,DWORD PTR [ebp-0x8c]
0x73c755: 8bc8                             mov    ecx,eax
0x73c757: 8bc6                             mov    eax,esi
0x73c759: e85252e3ff                       call   0x5719b0
0x73c75e: 837dc810                         cmp    DWORD PTR [ebp-0x38],0x10
0x73c762: 720c                             jb     0x73c770
0x73c764: 8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
0x73c767: 50                               push   eax
0x73c768: e89f4a1500                       call   0x89120c
0x73c76d: 83c404                           add    esp,0x4
0x73c770: 8bc6                             mov    eax,esi
0x73c772: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x73c775: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x73c77c: 59                               pop    ecx
0x73c77d: 5f                               pop    edi
0x73c77e: 5e                               pop    esi
0x73c77f: 5b                               pop    ebx
0x73c780: 8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x73c783: 33cd                             xor    ecx,ebp
0x73c785: e877481500                       call   0x891001
0x73c78a: 8be5                             mov    esp,ebp
0x73c78c: 5d                               pop    ebp
0x73c78d: c20800                           ret    0x8

## F-4DEC90 VA 0x4dec90..0x4defc2 raw 0xde090 len 818 SHA256 59b5c7022ba975f45335eac24e972bbb3a7ba8c532893148cf82b6f23b69c570
0x4dec90: 55                               push   ebp
0x4dec91: 8bec                             mov    ebp,esp
0x4dec93: 6aff                             push   0xffffffff
0x4dec95: 68db3d9300                       push   0x933ddb
0x4dec9a: 64a100000000                     mov    eax,fs:0x0
0x4deca0: 50                               push   eax
0x4deca1: 83ec24                           sub    esp,0x24
0x4deca4: 53                               push   ebx
0x4deca5: 56                               push   esi
0x4deca6: 57                               push   edi
0x4deca7: a1201fd600                       mov    eax,ds:0xd61f20
0x4decac: 33c5                             xor    eax,ebp
0x4decae: 50                               push   eax
0x4decaf: 8d45f4                           lea    eax,[ebp-0xc]
0x4decb2: 64a300000000                     mov    fs:0x0,eax
0x4decb8: 68245f0000                       push   0x5f24
0x4decbd: c745e830b1fa00                   mov    DWORD PTR [ebp-0x18],0xfab130
0x4decc4: e89f253b00                       call   0x891268
0x4decc9: 33f6                             xor    esi,esi
0x4deccb: 83c404                           add    esp,0x4
0x4decce: 3bc6                             cmp    eax,esi
0x4decd0: 7409                             je     0x4decdb
0x4decd2: 8bc8                             mov    ecx,eax
0x4decd4: e827eaffff                       call   0x4dd700
0x4decd9: eb02                             jmp    0x4decdd
0x4decdb: 33c0                             xor    eax,eax
0x4decdd: 6a40                             push   0x40
0x4decdf: a330b1fa00                       mov    ds:0xfab130,eax
0x4dece4: e87f253b00                       call   0x891268
0x4dece9: 83c404                           add    esp,0x4
0x4decec: 3bc6                             cmp    eax,esi
0x4decee: 742a                             je     0x4ded1a
0x4decf0: 8930                             mov    DWORD PTR [eax],esi
0x4decf2: 897004                           mov    DWORD PTR [eax+0x4],esi
0x4decf5: 897008                           mov    DWORD PTR [eax+0x8],esi
0x4decf8: 897010                           mov    DWORD PTR [eax+0x10],esi
0x4decfb: 897014                           mov    DWORD PTR [eax+0x14],esi
0x4decfe: 897018                           mov    DWORD PTR [eax+0x18],esi
0x4ded01: 33c9                             xor    ecx,ecx
0x4ded03: 897020                           mov    DWORD PTR [eax+0x20],esi
0x4ded06: 897024                           mov    DWORD PTR [eax+0x24],esi
0x4ded09: 897028                           mov    DWORD PTR [eax+0x28],esi
0x4ded0c: 894830                           mov    DWORD PTR [eax+0x30],ecx
0x4ded0f: b938000000                       mov    ecx,0x38
0x4ded14: 66894834                         mov    WORD PTR [eax+0x34],cx
0x4ded18: eb02                             jmp    0x4ded1c
0x4ded1a: 33c0                             xor    eax,eax
0x4ded1c: 6a18                             push   0x18
0x4ded1e: a334b1fa00                       mov    ds:0xfab134,eax
0x4ded23: 893540b1fa00                     mov    DWORD PTR ds:0xfab140,esi
0x4ded29: e83a253b00                       call   0x891268
0x4ded2e: 83c404                           add    esp,0x4
0x4ded31: 3bc6                             cmp    eax,esi
0x4ded33: 0f8465020000                     je     0x4def9e
0x4ded39: a33cb1fa00                       mov    ds:0xfab13c,eax
0x4ded3e: 8900                             mov    DWORD PTR [eax],eax
0x4ded40: a13cb1fa00                       mov    eax,ds:0xfab13c
0x4ded45: 894004                           mov    DWORD PTR [eax+0x4],eax
0x4ded48: a13cb1fa00                       mov    eax,ds:0xfab13c
0x4ded4d: 894008                           mov    DWORD PTR [eax+0x8],eax
0x4ded50: 8b153cb1fa00                     mov    edx,DWORD PTR ds:0xfab13c
0x4ded56: bb01000000                       mov    ebx,0x1
0x4ded5b: 885a14                           mov    BYTE PTR [edx+0x14],bl
0x4ded5e: a13cb1fa00                       mov    eax,ds:0xfab13c
0x4ded63: 885815                           mov    BYTE PTR [eax+0x15],bl
0x4ded66: 8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x4ded69: 6a18                             push   0x18
0x4ded6b: 893550b1fa00                     mov    DWORD PTR ds:0xfab150,esi
0x4ded71: e8f2243b00                       call   0x891268
0x4ded76: 83c404                           add    esp,0x4
0x4ded79: 3bc6                             cmp    eax,esi
0x4ded7b: 0f84f9010000                     je     0x4def7a
0x4ded81: a34cb1fa00                       mov    ds:0xfab14c,eax
0x4ded86: 8900                             mov    DWORD PTR [eax],eax
0x4ded88: a14cb1fa00                       mov    eax,ds:0xfab14c
0x4ded8d: 894004                           mov    DWORD PTR [eax+0x4],eax
0x4ded90: a14cb1fa00                       mov    eax,ds:0xfab14c
0x4ded95: 894008                           mov    DWORD PTR [eax+0x8],eax
0x4ded98: 8b0d4cb1fa00                     mov    ecx,DWORD PTR ds:0xfab14c
0x4ded9e: 885914                           mov    BYTE PTR [ecx+0x14],bl
0x4deda1: 8b154cb1fa00                     mov    edx,DWORD PTR ds:0xfab14c
0x4deda7: 885a15                           mov    BYTE PTR [edx+0x15],bl
0x4dedaa: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x4dedad: 6a18                             push   0x18
0x4dedaf: 893560b1fa00                     mov    DWORD PTR ds:0xfab160,esi
0x4dedb5: e8ae243b00                       call   0x891268
0x4dedba: 83c404                           add    esp,0x4
0x4dedbd: 3bc6                             cmp    eax,esi
0x4dedbf: 0f8491010000                     je     0x4def56
0x4dedc5: a35cb1fa00                       mov    ds:0xfab15c,eax
0x4dedca: 8900                             mov    DWORD PTR [eax],eax
0x4dedcc: a15cb1fa00                       mov    eax,ds:0xfab15c
0x4dedd1: 894004                           mov    DWORD PTR [eax+0x4],eax
0x4dedd4: a15cb1fa00                       mov    eax,ds:0xfab15c
0x4dedd9: 894008                           mov    DWORD PTR [eax+0x8],eax
0x4deddc: a15cb1fa00                       mov    eax,ds:0xfab15c
0x4dede1: 885814                           mov    BYTE PTR [eax+0x14],bl
0x4dede4: 8b0d5cb1fa00                     mov    ecx,DWORD PTR ds:0xfab15c
0x4dedea: 885915                           mov    BYTE PTR [ecx+0x15],bl
0x4deded: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x4dedf1: 6a18                             push   0x18
0x4dedf3: 893570b1fa00                     mov    DWORD PTR ds:0xfab170,esi
0x4dedf9: e86a243b00                       call   0x891268
0x4dedfe: 83c404                           add    esp,0x4
0x4dee01: 3bc6                             cmp    eax,esi
0x4dee03: 0f8429010000                     je     0x4def32
0x4dee09: a36cb1fa00                       mov    ds:0xfab16c,eax
0x4dee0e: 8900                             mov    DWORD PTR [eax],eax
0x4dee10: a16cb1fa00                       mov    eax,ds:0xfab16c
0x4dee15: 894004                           mov    DWORD PTR [eax+0x4],eax
0x4dee18: a16cb1fa00                       mov    eax,ds:0xfab16c
0x4dee1d: 894008                           mov    DWORD PTR [eax+0x8],eax
0x4dee20: 8b156cb1fa00                     mov    edx,DWORD PTR ds:0xfab16c
0x4dee26: 885a14                           mov    BYTE PTR [edx+0x14],bl
0x4dee29: a16cb1fa00                       mov    eax,ds:0xfab16c
0x4dee2e: 885815                           mov    BYTE PTR [eax+0x15],bl
0x4dee31: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x4dee35: 83c8ff                           or     eax,0xffffffff
0x4dee38: 56                               push   esi
0x4dee39: 68c8b1fa00                       push   0xfab1c8
0x4dee3e: a378b1fa00                       mov    ds:0xfab178,eax
0x4dee43: a3bcb1fa00                       mov    ds:0xfab1bc,eax
0x4dee48: a3c0b1fa00                       mov    ds:0xfab1c0,eax
0x4dee4d: a3c4b1fa00                       mov    ds:0xfab1c4,eax
0x4dee52: 8935c8b1fa00                     mov    DWORD PTR ds:0xfab1c8,esi
0x4dee58: 8935ccb1fa00                     mov    DWORD PTR ds:0xfab1cc,esi
0x4dee5e: e8cd220000                       call   0x4e1130
0x4dee63: c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x4dee67: 0f57c0                           xorps  xmm0,xmm0
0x4dee6a: 6800b2fa00                       push   0xfab200
0x4dee6f: 8935d0b1fa00                     mov    DWORD PTR ds:0xfab1d0,esi
0x4dee75: 8935d4b1fa00                     mov    DWORD PTR ds:0xfab1d4,esi
0x4dee7b: 8935d8b1fa00                     mov    DWORD PTR ds:0xfab1d8,esi
0x4dee81: f30f1105dcb1fa00                 movss  DWORD PTR ds:0xfab1dc,xmm0
0x4dee89: 8935e0b1fa00                     mov    DWORD PTR ds:0xfab1e0,esi
0x4dee8f: 8935e4b1fa00                     mov    DWORD PTR ds:0xfab1e4,esi
0x4dee95: e8467d1f00                       call   0x6d6be0
0x4dee9a: c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x4dee9e: 33c9                             xor    ecx,ecx
0x4deea0: 66890d20b2fa00                   mov    WORD PTR ds:0xfab220,cx
0x4deea7: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4deead: 893524b2fa00                     mov    DWORD PTR ds:0xfab224,esi
0x4deeb3: 893528b2fa00                     mov    DWORD PTR ds:0xfab228,esi
0x4deeb9: 3bce                             cmp    ecx,esi
0x4deebb: 7429                             je     0x4deee6
0x4deebd: 3935aca7fb00                     cmp    DWORD PTR ds:0xfba7ac,esi
0x4deec3: 7509                             jne    0x4deece
0x4deec5: 8bf9                             mov    edi,ecx
0x4deec7: e884600600                       call   0x544f50
0x4deecc: eb4d                             jmp    0x4def1b
0x4deece: 8b11                             mov    edx,DWORD PTR [ecx]
0x4deed0: 8b4228                           mov    eax,DWORD PTR [edx+0x28]
0x4deed3: ffd0                             call   eax
0x4deed5: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4deedb: 3bce                             cmp    ecx,esi
0x4deedd: 7407                             je     0x4deee6
0x4deedf: 8b11                             mov    edx,DWORD PTR [ecx]
0x4deee1: 8b02                             mov    eax,DWORD PTR [edx]
0x4deee3: 53                               push   ebx
0x4deee4: ffd0                             call   eax
0x4deee6: 68b4000000                       push   0xb4
0x4deeeb: e878233b00                       call   0x891268
0x4deef0: 83c404                           add    esp,0x4
0x4deef3: 8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4deef6: c645fc09                         mov    BYTE PTR [ebp-0x4],0x9
0x4deefa: 3bc6                             cmp    eax,esi
0x4deefc: 7409                             je     0x4def07
0x4deefe: 8bf0                             mov    esi,eax
0x4def00: e8db820600                       call   0x5471e0
0x4def05: eb02                             jmp    0x4def09
0x4def07: 33c0                             xor    eax,eax
0x4def09: c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x4def0d: 8b10                             mov    edx,DWORD PTR [eax]
0x4def0f: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4def14: 8bc8                             mov    ecx,eax
0x4def16: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4def19: ffd0                             call   eax
0x4def1b: b830b1fa00                       mov    eax,0xfab130
0x4def20: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4def23: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4def2a: 59                               pop    ecx
0x4def2b: 5f                               pop    edi
0x4def2c: 5e                               pop    esi
0x4def2d: 5b                               pop    ebx
0x4def2e: 8be5                             mov    esp,ebp
0x4def30: 5d                               pop    ebp
0x4def31: c3                               ret
0x4def32: 8d4df0                           lea    ecx,[ebp-0x10]
0x4def35: 51                               push   ecx
0x4def36: 8d4ddc                           lea    ecx,[ebp-0x24]
0x4def39: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4def3c: e868213b00                       call   0x8910a9
0x4def41: 68a857c800                       push   0xc857a8
0x4def46: 8d55dc                           lea    edx,[ebp-0x24]
0x4def49: 52                               push   edx
0x4def4a: c745dca42cbd00                   mov    DWORD PTR [ebp-0x24],0xbd2ca4
0x4def51: e89ada3b00                       call   0x89c9f0
0x4def56: 8d45ec                           lea    eax,[ebp-0x14]
0x4def59: 50                               push   eax
0x4def5a: 8d4dd0                           lea    ecx,[ebp-0x30]
0x4def5d: 8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x4def60: e844213b00                       call   0x8910a9
0x4def65: 68a857c800                       push   0xc857a8
0x4def6a: 8d4dd0                           lea    ecx,[ebp-0x30]
0x4def6d: 51                               push   ecx
0x4def6e: c745d0a42cbd00                   mov    DWORD PTR [ebp-0x30],0xbd2ca4
0x4def75: e876da3b00                       call   0x89c9f0
0x4def7a: 8d55f0                           lea    edx,[ebp-0x10]
0x4def7d: 52                               push   edx
0x4def7e: 8d4ddc                           lea    ecx,[ebp-0x24]
0x4def81: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4def84: e820213b00                       call   0x8910a9
0x4def89: 68a857c800                       push   0xc857a8
0x4def8e: 8d45dc                           lea    eax,[ebp-0x24]
0x4def91: 50                               push   eax
0x4def92: c745dca42cbd00                   mov    DWORD PTR [ebp-0x24],0xbd2ca4
0x4def99: e852da3b00                       call   0x89c9f0
0x4def9e: 8d4dec                           lea    ecx,[ebp-0x14]
0x4defa1: 51                               push   ecx
0x4defa2: 8d4dd0                           lea    ecx,[ebp-0x30]
0x4defa5: 8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x4defa8: e8fc203b00                       call   0x8910a9
0x4defad: 68a857c800                       push   0xc857a8
0x4defb2: 8d55d0                           lea    edx,[ebp-0x30]
0x4defb5: 52                               push   edx
0x4defb6: c745d0a42cbd00                   mov    DWORD PTR [ebp-0x30],0xbd2ca4
0x4defbd: e82eda3b00                       call   0x89c9f0

## F-4DD700 VA 0x4dd700..0x4dd7a9 raw 0xdcb00 len 169 SHA256 976ea33eb22752f4fc55b404a74219ebcef77c2342afcbdf80233696d53e35b4
0x4dd700: 33c0                             xor    eax,eax
0x4dd702: c701a0cec000                     mov    DWORD PTR [ecx],0xc0cea0
0x4dd708: 8981ac5e0000                     mov    DWORD PTR [ecx+0x5eac],eax
0x4dd70e: 8981b05e0000                     mov    DWORD PTR [ecx+0x5eb0],eax
0x4dd714: 33d2                             xor    edx,edx
0x4dd716: 668991b45e0000                   mov    WORD PTR [ecx+0x5eb4],dx
0x4dd71d: 8981b85e0000                     mov    DWORD PTR [ecx+0x5eb8],eax
0x4dd723: 8981bc5e0000                     mov    DWORD PTR [ecx+0x5ebc],eax
0x4dd729: 8981c05e0000                     mov    DWORD PTR [ecx+0x5ec0],eax
0x4dd72f: 8981c85e0000                     mov    DWORD PTR [ecx+0x5ec8],eax
0x4dd735: 8981cc5e0000                     mov    DWORD PTR [ecx+0x5ecc],eax
0x4dd73b: 8981d05e0000                     mov    DWORD PTR [ecx+0x5ed0],eax
0x4dd741: 8981d85e0000                     mov    DWORD PTR [ecx+0x5ed8],eax
0x4dd747: 8981dc5e0000                     mov    DWORD PTR [ecx+0x5edc],eax
0x4dd74d: 8981e05e0000                     mov    DWORD PTR [ecx+0x5ee0],eax
0x4dd753: 8981e85e0000                     mov    DWORD PTR [ecx+0x5ee8],eax
0x4dd759: 8981ec5e0000                     mov    DWORD PTR [ecx+0x5eec],eax
0x4dd75f: 8981f05e0000                     mov    DWORD PTR [ecx+0x5ef0],eax
0x4dd765: 8981f85e0000                     mov    DWORD PTR [ecx+0x5ef8],eax
0x4dd76b: 8981fc5e0000                     mov    DWORD PTR [ecx+0x5efc],eax
0x4dd771: 8981005f0000                     mov    DWORD PTR [ecx+0x5f00],eax
0x4dd777: 8981045f0000                     mov    DWORD PTR [ecx+0x5f04],eax
0x4dd77d: 89810c5f0000                     mov    DWORD PTR [ecx+0x5f0c],eax
0x4dd783: 8981105f0000                     mov    DWORD PTR [ecx+0x5f10],eax
0x4dd789: 8981145f0000                     mov    DWORD PTR [ecx+0x5f14],eax
0x4dd78f: 8981185f0000                     mov    DWORD PTR [ecx+0x5f18],eax
0x4dd795: 89811c5f0000                     mov    DWORD PTR [ecx+0x5f1c],eax
0x4dd79b: 8981205f0000                     mov    DWORD PTR [ecx+0x5f20],eax
0x4dd7a1: e84a010000                       call   0x4dd8f0
0x4dd7a6: 8bc1                             mov    eax,ecx
0x4dd7a8: c3                               ret

## F-4DD8F0 VA 0x4dd8f0..0x4dd9a1 raw 0xdccf0 len 177 SHA256 9fba711dd1737f9333b68f72cd4583a47275aea64ff67554e54cbe3473b1dffa
0x4dd8f0: 56                               push   esi
0x4dd8f1: 8d4108                           lea    eax,[ecx+0x8]
0x4dd8f4: bad50b0000                       mov    edx,0xbd5
0x4dd8f9: be7523bf00                       mov    esi,0xbf2375
0x4dd8fe: 8bff                             mov    edi,edi
0x4dd900: c740fc407d4b00                   mov    DWORD PTR [eax-0x4],0x4b7d40
0x4dd907: 8930                             mov    DWORD PTR [eax],esi
0x4dd909: 83c008                           add    eax,0x8
0x4dd90c: 4a                               dec    edx
0x4dd90d: 75f1                             jne    0x4dd900
0x4dd90f: 89b1d8040000                     mov    DWORD PTR [ecx+0x4d8],esi
0x4dd915: 89b140050000                     mov    DWORD PTR [ecx+0x540],esi
0x4dd91b: 89b1d0030000                     mov    DWORD PTR [ecx+0x3d0],esi
0x4dd921: 89b138010000                     mov    DWORD PTR [ecx+0x138],esi
0x4dd927: 89b1f0080000                     mov    DWORD PTR [ecx+0x8f0],esi
0x4dd92d: 89b150050000                     mov    DWORD PTR [ecx+0x550],esi
0x4dd933: 89b160050000                     mov    DWORD PTR [ecx+0x560],esi
0x4dd939: 89b190080000                     mov    DWORD PTR [ecx+0x890],esi
0x4dd93f: 89b180080000                     mov    DWORD PTR [ecx+0x880],esi
0x4dd945: c781d4040000d0db4d00             mov    DWORD PTR [ecx+0x4d4],0x4ddbd0
0x4dd94f: c7813c050000f0db4d00             mov    DWORD PTR [ecx+0x53c],0x4ddbf0
0x4dd959: c781cc030000d0de4d00             mov    DWORD PTR [ecx+0x3cc],0x4dded0
0x4dd963: c7813401000020e04d00             mov    DWORD PTR [ecx+0x134],0x4de020
0x4dd96d: c781ec08000000e14d00             mov    DWORD PTR [ecx+0x8ec],0x4de100
0x4dd977: c7814c050000d0e14d00             mov    DWORD PTR [ecx+0x54c],0x4de1d0
0x4dd981: c7815c05000070e34d00             mov    DWORD PTR [ecx+0x55c],0x4de370
0x4dd98b: c7818c080000f0e34d00             mov    DWORD PTR [ecx+0x88c],0x4de3f0
0x4dd995: c7817c08000040e54d00             mov    DWORD PTR [ecx+0x87c],0x4de540
0x4dd99f: 5e                               pop    esi
0x4dd9a0: c3                               ret

## F-4E1130 VA 0x4e1130..0x4e11a7 raw 0xe0530 len 119 SHA256 753bcd78f4ca80bbf985564b7cd8d617c6d30b0a909448a58e9aa880838b20f8
0x4e1130: 55                               push   ebp
0x4e1131: 8bec                             mov    ebp,esp
0x4e1133: 6aff                             push   0xffffffff
0x4e1135: 68c0b49000                       push   0x90b4c0
0x4e113a: 64a100000000                     mov    eax,fs:0x0
0x4e1140: 50                               push   eax
0x4e1141: 51                               push   ecx
0x4e1142: 53                               push   ebx
0x4e1143: 56                               push   esi
0x4e1144: 57                               push   edi
0x4e1145: a1201fd600                       mov    eax,ds:0xd61f20
0x4e114a: 33c5                             xor    eax,ebp
0x4e114c: 50                               push   eax
0x4e114d: 8d45f4                           lea    eax,[ebp-0xc]
0x4e1150: 64a300000000                     mov    fs:0x0,eax
0x4e1156: 8965f0                           mov    DWORD PTR [ebp-0x10],esp
0x4e1159: 8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0x4e115c: 6a10                             push   0x10
0x4e115e: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4e1165: e8fe003b00                       call   0x891268
0x4e116a: 83c404                           add    esp,0x4
0x4e116d: 85c0                             test   eax,eax
0x4e116f: 7416                             je     0x4e1187
0x4e1171: b901000000                       mov    ecx,0x1
0x4e1176: 894804                           mov    DWORD PTR [eax+0x4],ecx
0x4e1179: 894808                           mov    DWORD PTR [eax+0x8],ecx
0x4e117c: c70034cfc000                     mov    DWORD PTR [eax],0xc0cf34
0x4e1182: 89700c                           mov    DWORD PTR [eax+0xc],esi
0x4e1185: eb02                             jmp    0x4e1189
0x4e1187: 33c0                             xor    eax,eax
0x4e1189: 50                               push   eax
0x4e118a: 56                               push   esi
0x4e118b: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x4e118e: e82d202c00                       call   0x7a31c0
0x4e1193: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4e1196: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4e119d: 59                               pop    ecx
0x4e119e: 5f                               pop    edi
0x4e119f: 5e                               pop    esi
0x4e11a0: 5b                               pop    ebx
0x4e11a1: 8be5                             mov    esp,ebp
0x4e11a3: 5d                               pop    ebp
0x4e11a4: c20800                           ret    0x8

## F-7A31C0 VA 0x7a31c0..0x7a3222 raw 0x3a25c0 len 98 SHA256 2a2a146a8d4491f6e1c12d254983136d93c91ebd17289816cdc3019e7b39b2a0
0x7a31c0: 55                               push   ebp
0x7a31c1: 8bec                             mov    ebp,esp
0x7a31c3: 53                               push   ebx
0x7a31c4: 8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
0x7a31c7: 57                               push   edi
0x7a31c8: 8b7e04                           mov    edi,DWORD PTR [esi+0x4]
0x7a31cb: 85ff                             test   edi,edi
0x7a31cd: 7429                             je     0x7a31f8
0x7a31cf: 8d4704                           lea    eax,[edi+0x4]
0x7a31d2: 83c9ff                           or     ecx,0xffffffff
0x7a31d5: f00fc108                         lock xadd DWORD PTR [eax],ecx
0x7a31d9: 7539                             jne    0x7a3214
0x7a31db: 8b17                             mov    edx,DWORD PTR [edi]
0x7a31dd: 8b02                             mov    eax,DWORD PTR [edx]
0x7a31df: 8bcf                             mov    ecx,edi
0x7a31e1: ffd0                             call   eax
0x7a31e3: 8d4f08                           lea    ecx,[edi+0x8]
0x7a31e6: 83caff                           or     edx,0xffffffff
0x7a31e9: f00fc111                         lock xadd DWORD PTR [ecx],edx
0x7a31ed: 7517                             jne    0x7a3206
0x7a31ef: 8b07                             mov    eax,DWORD PTR [edi]
0x7a31f1: 8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a31f4: 8bcf                             mov    ecx,edi
0x7a31f6: ffd2                             call   edx
0x7a31f8: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x7a31fb: 5f                               pop    edi
0x7a31fc: 895e04                           mov    DWORD PTR [esi+0x4],ebx
0x7a31ff: 8906                             mov    DWORD PTR [esi],eax
0x7a3201: 5b                               pop    ebx
0x7a3202: 5d                               pop    ebp
0x7a3203: c20800                           ret    0x8
0x7a3206: 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x7a3209: 5f                               pop    edi
0x7a320a: 895e04                           mov    DWORD PTR [esi+0x4],ebx
0x7a320d: 890e                             mov    DWORD PTR [esi],ecx
0x7a320f: 5b                               pop    ebx
0x7a3210: 5d                               pop    ebp
0x7a3211: c20800                           ret    0x8
0x7a3214: 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x7a3217: 5f                               pop    edi
0x7a3218: 895e04                           mov    DWORD PTR [esi+0x4],ebx
0x7a321b: 8916                             mov    DWORD PTR [esi],edx
0x7a321d: 5b                               pop    ebx
0x7a321e: 5d                               pop    ebp
0x7a321f: c20800                           ret    0x8

## F-6D6BE0 VA 0x6d6be0..0x6d6cd0 raw 0x2d5fe0 len 240 SHA256 4110b183872cb5ec45d37c596b644efead416e99c814190ce367842b7a0eede8
0x6d6be0: 55                               push   ebp
0x6d6be1: 8bec                             mov    ebp,esp
0x6d6be3: 6aff                             push   0xffffffff
0x6d6be5: 680a819000                       push   0x90810a
0x6d6bea: 64a100000000                     mov    eax,fs:0x0
0x6d6bf0: 50                               push   eax
0x6d6bf1: 83ec20                           sub    esp,0x20
0x6d6bf4: 53                               push   ebx
0x6d6bf5: 56                               push   esi
0x6d6bf6: 57                               push   edi
0x6d6bf7: a1201fd600                       mov    eax,ds:0xd61f20
0x6d6bfc: 33c5                             xor    eax,ebp
0x6d6bfe: 50                               push   eax
0x6d6bff: 8d45f4                           lea    eax,[ebp-0xc]
0x6d6c02: 64a300000000                     mov    fs:0x0,eax
0x6d6c08: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x6d6c0b: 33ff                             xor    edi,edi
0x6d6c0d: 6a28                             push   0x28
0x6d6c0f: 897e08                           mov    DWORD PTR [esi+0x8],edi
0x6d6c12: e851a61b00                       call   0x891268
0x6d6c17: 83c404                           add    esp,0x4
0x6d6c1a: 3bc7                             cmp    eax,edi
0x6d6c1c: 0f848a000000                     je     0x6d6cac
0x6d6c22: 894604                           mov    DWORD PTR [esi+0x4],eax
0x6d6c25: 8900                             mov    DWORD PTR [eax],eax
0x6d6c27: 8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x6d6c2a: 894004                           mov    DWORD PTR [eax+0x4],eax
0x6d6c2d: 8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x6d6c30: 894008                           mov    DWORD PTR [eax+0x8],eax
0x6d6c33: 8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x6d6c36: b301                             mov    bl,0x1
0x6d6c38: 885820                           mov    BYTE PTR [eax+0x20],bl
0x6d6c3b: 8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x6d6c3e: 885921                           mov    BYTE PTR [ecx+0x21],bl
0x6d6c41: 897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x6d6c44: 6a20                             push   0x20
0x6d6c46: 897e18                           mov    DWORD PTR [esi+0x18],edi
0x6d6c49: e81aa61b00                       call   0x891268
0x6d6c4e: 83c404                           add    esp,0x4
0x6d6c51: 3bc7                             cmp    eax,edi
0x6d6c53: 7433                             je     0x6d6c88
0x6d6c55: 894614                           mov    DWORD PTR [esi+0x14],eax
0x6d6c58: 8900                             mov    DWORD PTR [eax],eax
0x6d6c5a: 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x6d6c5d: 894004                           mov    DWORD PTR [eax+0x4],eax
0x6d6c60: 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x6d6c63: 894008                           mov    DWORD PTR [eax+0x8],eax
0x6d6c66: 8b5614                           mov    edx,DWORD PTR [esi+0x14]
0x6d6c69: 885a18                           mov    BYTE PTR [edx+0x18],bl
0x6d6c6c: 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x6d6c6f: 885819                           mov    BYTE PTR [eax+0x19],bl
0x6d6c72: 8bc6                             mov    eax,esi
0x6d6c74: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x6d6c77: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x6d6c7e: 59                               pop    ecx
0x6d6c7f: 5f                               pop    edi
0x6d6c80: 5e                               pop    esi
0x6d6c81: 5b                               pop    ebx
0x6d6c82: 8be5                             mov    esp,ebp
0x6d6c84: 5d                               pop    ebp
0x6d6c85: c20400                           ret    0x4
0x6d6c88: 8d4df0                           lea    ecx,[ebp-0x10]
0x6d6c8b: 51                               push   ecx
0x6d6c8c: 8d4de0                           lea    ecx,[ebp-0x20]
0x6d6c8f: 897df0                           mov    DWORD PTR [ebp-0x10],edi
0x6d6c92: e812a41b00                       call   0x8910a9
0x6d6c97: 68a857c800                       push   0xc857a8
0x6d6c9c: 8d55e0                           lea    edx,[ebp-0x20]
0x6d6c9f: 52                               push   edx
0x6d6ca0: c745e0a42cbd00                   mov    DWORD PTR [ebp-0x20],0xbd2ca4
0x6d6ca7: e8445d1c00                       call   0x89c9f0
0x6d6cac: 8d45ec                           lea    eax,[ebp-0x14]
0x6d6caf: 50                               push   eax
0x6d6cb0: 8d4dd4                           lea    ecx,[ebp-0x2c]
0x6d6cb3: 897dec                           mov    DWORD PTR [ebp-0x14],edi
0x6d6cb6: e8eea31b00                       call   0x8910a9
0x6d6cbb: 68a857c800                       push   0xc857a8
0x6d6cc0: 8d4dd4                           lea    ecx,[ebp-0x2c]
0x6d6cc3: 51                               push   ecx
0x6d6cc4: c745d4a42cbd00                   mov    DWORD PTR [ebp-0x2c],0xbd2ca4
0x6d6ccb: e8205d1c00                       call   0x89c9f0

## F-544C40 VA 0x544c40..0x544e40 raw 0x144040 len 512 SHA256 4e0d54d4bfdb7608167877652d5883ace14e584009a3b2116e8b5320529488a5
0x544c40: 55                               push   ebp
0x544c41: 8bec                             mov    ebp,esp
0x544c43: 6aff                             push   0xffffffff
0x544c45: 6855f09200                       push   0x92f055
0x544c4a: 64a100000000                     mov    eax,fs:0x0
0x544c50: 50                               push   eax
0x544c51: 83ec10                           sub    esp,0x10
0x544c54: 53                               push   ebx
0x544c55: 56                               push   esi
0x544c56: 57                               push   edi
0x544c57: a1201fd600                       mov    eax,ds:0xd61f20
0x544c5c: 33c5                             xor    eax,ebp
0x544c5e: 50                               push   eax
0x544c5f: 8d45f4                           lea    eax,[ebp-0xc]
0x544c62: 64a300000000                     mov    fs:0x0,eax
0x544c68: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x544c6b: c70744f9c000                     mov    DWORD PTR [edi],0xc0f944
0x544c71: 33db                             xor    ebx,ebx
0x544c73: 895f04                           mov    DWORD PTR [edi+0x4],ebx
0x544c76: 895f0c                           mov    DWORD PTR [edi+0xc],ebx
0x544c79: 895f10                           mov    DWORD PTR [edi+0x10],ebx
0x544c7c: c6471401                         mov    BYTE PTR [edi+0x14],0x1
0x544c80: 895f18                           mov    DWORD PTR [edi+0x18],ebx
0x544c83: 895f1c                           mov    DWORD PTR [edi+0x1c],ebx
0x544c86: c6472001                         mov    BYTE PTR [edi+0x20],0x1
0x544c8a: 895f24                           mov    DWORD PTR [edi+0x24],ebx
0x544c8d: 895f28                           mov    DWORD PTR [edi+0x28],ebx
0x544c90: c6472c01                         mov    BYTE PTR [edi+0x2c],0x1
0x544c94: 895f30                           mov    DWORD PTR [edi+0x30],ebx
0x544c97: 895f34                           mov    DWORD PTR [edi+0x34],ebx
0x544c9a: 895f38                           mov    DWORD PTR [edi+0x38],ebx
0x544c9d: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x544ca0: 895f40                           mov    DWORD PTR [edi+0x40],ebx
0x544ca3: 895f44                           mov    DWORD PTR [edi+0x44],ebx
0x544ca6: 6a18                             push   0x18
0x544ca8: 895f50                           mov    DWORD PTR [edi+0x50],ebx
0x544cab: e8b8c53400                       call   0x891268
0x544cb0: 83c404                           add    esp,0x4
0x544cb3: 3bc3                             cmp    eax,ebx
0x544cb5: 0f8461010000                     je     0x544e1c
0x544cbb: 89474c                           mov    DWORD PTR [edi+0x4c],eax
0x544cbe: 8900                             mov    DWORD PTR [eax],eax
0x544cc0: 8b474c                           mov    eax,DWORD PTR [edi+0x4c]
0x544cc3: 894004                           mov    DWORD PTR [eax+0x4],eax
0x544cc6: 8b474c                           mov    eax,DWORD PTR [edi+0x4c]
0x544cc9: 894008                           mov    DWORD PTR [eax+0x8],eax
0x544ccc: 8b474c                           mov    eax,DWORD PTR [edi+0x4c]
0x544ccf: c6401401                         mov    BYTE PTR [eax+0x14],0x1
0x544cd3: 8b4f4c                           mov    ecx,DWORD PTR [edi+0x4c]
0x544cd6: c6411501                         mov    BYTE PTR [ecx+0x15],0x1
0x544cda: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x544cde: 33d2                             xor    edx,edx
0x544ce0: 895f58                           mov    DWORD PTR [edi+0x58],ebx
0x544ce3: 89575c                           mov    DWORD PTR [edi+0x5c],edx
0x544ce6: 895f60                           mov    DWORD PTR [edi+0x60],ebx
0x544ce9: ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x544cef: f30f10056856c500                 movss  xmm0,DWORD PTR ds:0xc55668
0x544cf7: 33c9                             xor    ecx,ecx
0x544cf9: 894764                           mov    DWORD PTR [edi+0x64],eax
0x544cfc: 66894f68                         mov    WORD PTR [edi+0x68],cx
0x544d00: 8db788000000                     lea    esi,[edi+0x88]
0x544d06: 895f70                           mov    DWORD PTR [edi+0x70],ebx
0x544d09: 895f74                           mov    DWORD PTR [edi+0x74],ebx
0x544d0c: 895f78                           mov    DWORD PTR [edi+0x78],ebx
0x544d0f: 895f7c                           mov    DWORD PTR [edi+0x7c],ebx
0x544d12: 899f80000000                     mov    DWORD PTR [edi+0x80],ebx
0x544d18: f30f118784000000                 movss  DWORD PTR [edi+0x84],xmm0
0x544d20: e85b77f5ff                       call   0x49c480
0x544d25: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x544d29: f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x544d30: 895f0c                           mov    DWORD PTR [edi+0xc],ebx
0x544d33: 895f10                           mov    DWORD PTR [edi+0x10],ebx
0x544d36: c6471401                         mov    BYTE PTR [edi+0x14],0x1
0x544d3a: 895f18                           mov    DWORD PTR [edi+0x18],ebx
0x544d3d: 895f1c                           mov    DWORD PTR [edi+0x1c],ebx
0x544d40: c6472001                         mov    BYTE PTR [edi+0x20],0x1
0x544d44: 895f24                           mov    DWORD PTR [edi+0x24],ebx
0x544d47: 895f28                           mov    DWORD PTR [edi+0x28],ebx
0x544d4a: c6472c01                         mov    BYTE PTR [edi+0x2c],0x1
0x544d4e: 891d34abfb00                     mov    DWORD PTR ds:0xfbab34,ebx
0x544d54: 891d38abfb00                     mov    DWORD PTR ds:0xfbab38,ebx
0x544d5a: 751d                             jne    0x544d79
0x544d5c: 830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
0x544d63: c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
0x544d67: e874402500                       call   0x798de0
0x544d6c: 68e0d2bc00                       push   0xbcd2e0
0x544d71: e8a4d53400                       call   0x89231a
0x544d76: 83c404                           add    esp,0x4
0x544d79: a1e876fb00                       mov    eax,ds:0xfb76e8
0x544d7e: d980d4000000                     fld    DWORD PTR [eax+0xd4]
0x544d84: 8b352422bd00                     mov    esi,DWORD PTR ds:0xbd2224
0x544d8a: 6884f8c000                       push   0xc0f884
0x544d8f: d998d8000000                     fstp   DWORD PTR [eax+0xd8]
0x544d95: 6a64                             push   0x64
0x544d97: c780b000000001000000             mov    DWORD PTR [eax+0xb0],0x1
0x544da1: 68a0f8c000                       push   0xc0f8a0
0x544da6: 895f68                           mov    DWORD PTR [edi+0x68],ebx
0x544da9: 68b8f8c000                       push   0xc0f8b8
0x544dae: 885f6c                           mov    BYTE PTR [edi+0x6c],bl
0x544db1: ffd6                             call   esi
0x544db3: 6884f8c000                       push   0xc0f884
0x544db8: 6a78                             push   0x78
0x544dba: 68c8f8c000                       push   0xc0f8c8
0x544dbf: 68b8f8c000                       push   0xc0f8b8
0x544dc4: a32ca6d600                       mov    ds:0xd6a62c,eax
0x544dc9: ffd6                             call   esi
0x544dcb: 6884f8c000                       push   0xc0f884
0x544dd0: 68b4000000                       push   0xb4
0x544dd5: 68e0f8c000                       push   0xc0f8e0
0x544dda: 68b8f8c000                       push   0xc0f8b8
0x544ddf: a330a6d600                       mov    ds:0xd6a630,eax
0x544de4: ffd6                             call   esi
0x544de6: 6884f8c000                       push   0xc0f884
0x544deb: 682c010000                       push   0x12c
0x544df0: 68fcf8c000                       push   0xc0f8fc
0x544df5: 68b8f8c000                       push   0xc0f8b8
0x544dfa: a334a6d600                       mov    ds:0xd6a634,eax
0x544dff: ffd6                             call   esi
0x544e01: a338a6d600                       mov    ds:0xd6a638,eax
0x544e06: 8bc7                             mov    eax,edi
0x544e08: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x544e0b: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x544e12: 59                               pop    ecx
0x544e13: 5f                               pop    edi
0x544e14: 5e                               pop    esi
0x544e15: 5b                               pop    ebx
0x544e16: 8be5                             mov    esp,ebp
0x544e18: 5d                               pop    ebp
0x544e19: c20400                           ret    0x4
0x544e1c: 8d55f0                           lea    edx,[ebp-0x10]
0x544e1f: 52                               push   edx
0x544e20: 8d4de4                           lea    ecx,[ebp-0x1c]
0x544e23: 895df0                           mov    DWORD PTR [ebp-0x10],ebx
0x544e26: e87ec23400                       call   0x8910a9
0x544e2b: 68a857c800                       push   0xc857a8
0x544e30: 8d45e4                           lea    eax,[ebp-0x1c]
0x544e33: 50                               push   eax
0x544e34: c745e4a42cbd00                   mov    DWORD PTR [ebp-0x1c],0xbd2ca4
0x544e3b: e8b07b3500                       call   0x89c9f0

## F-5471E0 VA 0x5471e0..0x5471fb raw 0x1465e0 len 27 SHA256 369f8f910b1149c92743daf28fe4494fe923a2b4bb88ced84e5f0e728bd7074f
0x5471e0: 51                               push   ecx
0x5471e1: 56                               push   esi
0x5471e2: e859daffff                       call   0x544c40
0x5471e7: c7069cf9c000                     mov    DWORD PTR [esi],0xc0f99c
0x5471ed: c705aca7fb0000000000             mov    DWORD PTR ds:0xfba7ac,0x0
0x5471f7: 8bc6                             mov    eax,esi
0x5471f9: 59                               pop    ecx
0x5471fa: c3                               ret

## F-444210 VA 0x444210..0x4442c5 raw 0x43610 len 181 SHA256 8621e2a7e70a9fe287036e8caaf6c98d309cace74316c907c693215304c6e4ff
0x444210: 55                               push   ebp
0x444211: 8bec                             mov    ebp,esp
0x444213: 6aff                             push   0xffffffff
0x444215: 685e1b9300                       push   0x931b5e
0x44421a: 64a100000000                     mov    eax,fs:0x0
0x444220: 50                               push   eax
0x444221: 51                               push   ecx
0x444222: 56                               push   esi
0x444223: 57                               push   edi
0x444224: a1201fd600                       mov    eax,ds:0xd61f20
0x444229: 33c5                             xor    eax,ebp
0x44422b: 50                               push   eax
0x44422c: 8d45f4                           lea    eax,[ebp-0xc]
0x44422f: 64a300000000                     mov    fs:0x0,eax
0x444235: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x444238: 56                               push   esi
0x444239: e8020a1000                       call   0x544c40
0x44423e: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x444245: 6a18                             push   0x18
0x444247: c706a4b5bf00                     mov    DWORD PTR [esi],0xbfb5a4
0x44424d: e816d04400                       call   0x891268
0x444252: 83c404                           add    esp,0x4
0x444255: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x444258: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x44425c: 85c0                             test   eax,eax
0x44425e: 7409                             je     0x444269
0x444260: 8bf8                             mov    edi,eax
0x444262: e849833500                       call   0x79c5b0
0x444267: eb02                             jmp    0x44426b
0x444269: 33c0                             xor    eax,eax
0x44426b: c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x44426f: 6a40                             push   0x40
0x444271: 8986b4000000                     mov    DWORD PTR [esi+0xb4],eax
0x444277: e8eccf4400                       call   0x891268
0x44427c: 83c404                           add    esp,0x4
0x44427f: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x444282: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x444286: 85c0                             test   eax,eax
0x444288: 740a                             je     0x444294
0x44428a: 6a00                             push   0x0
0x44428c: 50                               push   eax
0x44428d: e81e883500                       call   0x79cab0
0x444292: eb02                             jmp    0x444296
0x444294: 33c0                             xor    eax,eax
0x444296: 8986b8000000                     mov    DWORD PTR [esi+0xb8],eax
0x44429c: c786bc00000000000000             mov    DWORD PTR [esi+0xbc],0x0
0x4442a6: c705aca7fb0006000000             mov    DWORD PTR ds:0xfba7ac,0x6
0x4442b0: 8bc6                             mov    eax,esi
0x4442b2: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4442b5: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4442bc: 59                               pop    ecx
0x4442bd: 5f                               pop    edi
0x4442be: 5e                               pop    esi
0x4442bf: 8be5                             mov    esp,ebp
0x4442c1: 5d                               pop    ebp
0x4442c2: c20400                           ret    0x4

## F-547390 VA 0x547390..0x5475c9 raw 0x146790 len 569 SHA256 362127573657c8106be92b41dfc19a5e14ce174cbadd5532bad8c674cbdcef94
0x547390: 55                               push   ebp
0x547391: 8bec                             mov    ebp,esp
0x547393: 6aff                             push   0xffffffff
0x547395: 68183b9300                       push   0x933b18
0x54739a: 64a100000000                     mov    eax,fs:0x0
0x5473a0: 50                               push   eax
0x5473a1: 83ec08                           sub    esp,0x8
0x5473a4: 53                               push   ebx
0x5473a5: 56                               push   esi
0x5473a6: 57                               push   edi
0x5473a7: a1201fd600                       mov    eax,ds:0xd61f20
0x5473ac: 33c5                             xor    eax,ebp
0x5473ae: 50                               push   eax
0x5473af: 8d45f4                           lea    eax,[ebp-0xc]
0x5473b2: 64a300000000                     mov    fs:0x0,eax
0x5473b8: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x5473bb: 53                               push   ebx
0x5473bc: e87fd8ffff                       call   0x544c40
0x5473c1: 33f6                             xor    esi,esi
0x5473c3: 8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x5473c6: f605207afb0001                   test   BYTE PTR ds:0xfb7a20,0x1
0x5473cd: c70314fac000                     mov    DWORD PTR [ebx],0xc0fa14
0x5473d3: 89b3b4000000                     mov    DWORD PTR [ebx+0xb4],esi
0x5473d9: 7521                             jne    0x5473fc
0x5473db: 830d207afb0001                   or     DWORD PTR ds:0xfb7a20,0x1
0x5473e2: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x5473e6: e8b5190000                       call   0x548da0
0x5473eb: 6870d3bc00                       push   0xbcd370
0x5473f0: e825af3400                       call   0x89231a
0x5473f5: 83c404                           add    esp,0x4
0x5473f8: c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x5473fc: 8b83b4000000                     mov    eax,DWORD PTR [ebx+0xb4]
0x547402: 6a18                             push   0x18
0x547404: a3947afb00                       mov    ds:0xfb7a94,eax
0x547409: 89352c7afb00                     mov    DWORD PTR ds:0xfb7a2c,esi
0x54740f: 8935307afb00                     mov    DWORD PTR ds:0xfb7a30,esi
0x547415: 8935347afb00                     mov    DWORD PTR ds:0xfb7a34,esi
0x54741b: c705aca7fb0003000000             mov    DWORD PTR ds:0xfba7ac,0x3
0x547425: e83e9e3400                       call   0x891268
0x54742a: 83c404                           add    esp,0x4
0x54742d: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x547430: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x547434: 3bc6                             cmp    eax,esi
0x547436: 7409                             je     0x547441
0x547438: 8bf8                             mov    edi,eax
0x54743a: e871512500                       call   0x79c5b0
0x54743f: eb02                             jmp    0x547443
0x547441: 33c0                             xor    eax,eax
0x547443: c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x547447: 6a40                             push   0x40
0x547449: 8983b8000000                     mov    DWORD PTR [ebx+0xb8],eax
0x54744f: e8149e3400                       call   0x891268
0x547454: 83c404                           add    esp,0x4
0x547457: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x54745a: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x54745e: 3bc6                             cmp    eax,esi
0x547460: 7409                             je     0x54746b
0x547462: 56                               push   esi
0x547463: 50                               push   eax
0x547464: e847562500                       call   0x79cab0
0x547469: eb02                             jmp    0x54746d
0x54746b: 33c0                             xor    eax,eax
0x54746d: c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x547471: 6a40                             push   0x40
0x547473: 8983bc000000                     mov    DWORD PTR [ebx+0xbc],eax
0x547479: e8ea9d3400                       call   0x891268
0x54747e: 8bf0                             mov    esi,eax
0x547480: 83c404                           add    esp,0x4
0x547483: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x547486: 33c0                             xor    eax,eax
0x547488: c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x54748c: 0f57c0                           xorps  xmm0,xmm0
0x54748f: 3bf0                             cmp    esi,eax
0x547491: 7476                             je     0x547509
0x547493: f30f100d7059c500                 movss  xmm1,DWORD PTR ds:0xc55970
0x54749b: c7067cf4c400                     mov    DWORD PTR [esi],0xc4f47c
0x5474a1: 894604                           mov    DWORD PTR [esi+0x4],eax
0x5474a4: f30f114608                       movss  DWORD PTR [esi+0x8],xmm0
0x5474a9: f30f11460c                       movss  DWORD PTR [esi+0xc],xmm0
0x5474ae: f30f114610                       movss  DWORD PTR [esi+0x10],xmm0
0x5474b3: f30f114e14                       movss  DWORD PTR [esi+0x14],xmm1
0x5474b8: f30f114618                       movss  DWORD PTR [esi+0x18],xmm0
0x5474bd: 6a0a                             push   0xa
0x5474bf: c746300f000000                   mov    DWORD PTR [esi+0x30],0xf
0x5474c6: 89462c                           mov    DWORD PTR [esi+0x2c],eax
0x5474c9: 6824f4c400                       push   0xc4f424
0x5474ce: 8d4e1c                           lea    ecx,[esi+0x1c]
0x5474d1: 88461c                           mov    BYTE PTR [esi+0x1c],al
0x5474d4: e897b5ebff                       call   0x402a70
0x5474d9: c7463868f4c400                   mov    DWORD PTR [esi+0x38],0xc4f468
0x5474e0: c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
0x5474e4: 6a0e                             push   0xe
0x5474e6: 6854f4c400                       push   0xc4f454
0x5474eb: 8d4e1c                           lea    ecx,[esi+0x1c]
0x5474ee: c70694f4c400                     mov    DWORD PTR [esi],0xc4f494
0x5474f4: c74638acf4c400                   mov    DWORD PTR [esi+0x38],0xc4f4ac
0x5474fb: c7463c01000000                   mov    DWORD PTR [esi+0x3c],0x1
0x547502: e869b5ebff                       call   0x402a70
0x547507: eb02                             jmp    0x54750b
0x547509: 33f6                             xor    esi,esi
0x54750b: c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x54750f: 6a40                             push   0x40
0x547511: 89b3c0000000                     mov    DWORD PTR [ebx+0xc0],esi
0x547517: e84c9d3400                       call   0x891268
0x54751c: 8bf0                             mov    esi,eax
0x54751e: 83c404                           add    esp,0x4
0x547521: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x547524: 33c0                             xor    eax,eax
0x547526: c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
0x54752a: 3bf0                             cmp    esi,eax
0x54752c: 747f                             je     0x5475ad
0x54752e: 0f57c0                           xorps  xmm0,xmm0
0x547531: f30f100d7059c500                 movss  xmm1,DWORD PTR ds:0xc55970
0x547539: c7067cf4c400                     mov    DWORD PTR [esi],0xc4f47c
0x54753f: 894604                           mov    DWORD PTR [esi+0x4],eax
0x547542: f30f114608                       movss  DWORD PTR [esi+0x8],xmm0
0x547547: f30f11460c                       movss  DWORD PTR [esi+0xc],xmm0
0x54754c: f30f114610                       movss  DWORD PTR [esi+0x10],xmm0
0x547551: f30f114e14                       movss  DWORD PTR [esi+0x14],xmm1
0x547556: f30f114618                       movss  DWORD PTR [esi+0x18],xmm0
0x54755b: 6a0a                             push   0xa
0x54755d: c746300f000000                   mov    DWORD PTR [esi+0x30],0xf
0x547564: 89462c                           mov    DWORD PTR [esi+0x2c],eax
0x547567: 6824f4c400                       push   0xc4f424
0x54756c: 8d4e1c                           lea    ecx,[esi+0x1c]
0x54756f: 88461c                           mov    BYTE PTR [esi+0x1c],al
0x547572: e8f9b4ebff                       call   0x402a70
0x547577: c7463868f4c400                   mov    DWORD PTR [esi+0x38],0xc4f468
0x54757e: c645fc09                         mov    BYTE PTR [ebp-0x4],0x9
0x547582: 6a0e                             push   0xe
0x547584: 6854f4c400                       push   0xc4f454
0x547589: 8d4e1c                           lea    ecx,[esi+0x1c]
0x54758c: c70694f4c400                     mov    DWORD PTR [esi],0xc4f494
0x547592: c74638acf4c400                   mov    DWORD PTR [esi+0x38],0xc4f4ac
0x547599: c7463c01000000                   mov    DWORD PTR [esi+0x3c],0x1
0x5475a0: e8cbb4ebff                       call   0x402a70
0x5475a5: 89b3c4000000                     mov    DWORD PTR [ebx+0xc4],esi
0x5475ab: eb06                             jmp    0x5475b3
0x5475ad: 8983c4000000                     mov    DWORD PTR [ebx+0xc4],eax
0x5475b3: 8bc3                             mov    eax,ebx
0x5475b5: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5475b8: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5475bf: 59                               pop    ecx
0x5475c0: 5f                               pop    edi
0x5475c1: 5e                               pop    esi
0x5475c2: 5b                               pop    ebx
0x5475c3: 8be5                             mov    esp,ebp
0x5475c5: 5d                               pop    ebp
0x5475c6: c20400                           ret    0x4

## F-548540 VA 0x548540..0x5485f5 raw 0x147940 len 181 SHA256 2c4ca5aff26a5011de9ee825341792cccd0d34d4b5bdc9c336286549a48464be
0x548540: 55                               push   ebp
0x548541: 8bec                             mov    ebp,esp
0x548543: 6aff                             push   0xffffffff
0x548545: 688e3a9300                       push   0x933a8e
0x54854a: 64a100000000                     mov    eax,fs:0x0
0x548550: 50                               push   eax
0x548551: 51                               push   ecx
0x548552: 56                               push   esi
0x548553: 57                               push   edi
0x548554: a1201fd600                       mov    eax,ds:0xd61f20
0x548559: 33c5                             xor    eax,ebp
0x54855b: 50                               push   eax
0x54855c: 8d45f4                           lea    eax,[ebp-0xc]
0x54855f: 64a300000000                     mov    fs:0x0,eax
0x548565: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x548568: 56                               push   esi
0x548569: e8d2c6ffff                       call   0x544c40
0x54856e: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x548575: 6a18                             push   0x18
0x548577: c706c4fac000                     mov    DWORD PTR [esi],0xc0fac4
0x54857d: e8e68c3400                       call   0x891268
0x548582: 83c404                           add    esp,0x4
0x548585: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x548588: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x54858c: 85c0                             test   eax,eax
0x54858e: 7409                             je     0x548599
0x548590: 8bf8                             mov    edi,eax
0x548592: e819402500                       call   0x79c5b0
0x548597: eb02                             jmp    0x54859b
0x548599: 33c0                             xor    eax,eax
0x54859b: c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x54859f: 6a40                             push   0x40
0x5485a1: 8986b4000000                     mov    DWORD PTR [esi+0xb4],eax
0x5485a7: e8bc8c3400                       call   0x891268
0x5485ac: 83c404                           add    esp,0x4
0x5485af: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x5485b2: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x5485b6: 85c0                             test   eax,eax
0x5485b8: 740a                             je     0x5485c4
0x5485ba: 6a00                             push   0x0
0x5485bc: 50                               push   eax
0x5485bd: e8ee442500                       call   0x79cab0
0x5485c2: eb02                             jmp    0x5485c6
0x5485c4: 33c0                             xor    eax,eax
0x5485c6: 8986b8000000                     mov    DWORD PTR [esi+0xb8],eax
0x5485cc: c786bc00000000000000             mov    DWORD PTR [esi+0xbc],0x0
0x5485d6: c705aca7fb0002000000             mov    DWORD PTR ds:0xfba7ac,0x2
0x5485e0: 8bc6                             mov    eax,esi
0x5485e2: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5485e5: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5485ec: 59                               pop    ecx
0x5485ed: 5f                               pop    edi
0x5485ee: 5e                               pop    esi
0x5485ef: 8be5                             mov    esp,ebp
0x5485f1: 5d                               pop    ebp
0x5485f2: c20400                           ret    0x4

## F-548B90 VA 0x548b90..0x548c73 raw 0x147f90 len 227 SHA256 56829ff4c89883b2c8182059d8d3d2411902bfc9f31d2878cba8b3bcca6c6685
0x548b90: 51                               push   ecx
0x548b91: 56                               push   esi
0x548b92: e8a9c0ffff                       call   0x544c40
0x548b97: 33c0                             xor    eax,eax
0x548b99: 898634010000                     mov    DWORD PTR [esi+0x134],eax
0x548b9f: c7061cfbc000                     mov    DWORD PTR [esi],0xc0fb1c
0x548ba5: 8986b4000000                     mov    DWORD PTR [esi+0xb4],eax
0x548bab: 8986b8000000                     mov    DWORD PTR [esi+0xb8],eax
0x548bb1: 8986bc000000                     mov    DWORD PTR [esi+0xbc],eax
0x548bb7: 8986c0000000                     mov    DWORD PTR [esi+0xc0],eax
0x548bbd: 8986c4000000                     mov    DWORD PTR [esi+0xc4],eax
0x548bc3: 8986c8000000                     mov    DWORD PTR [esi+0xc8],eax
0x548bc9: 8986cc000000                     mov    DWORD PTR [esi+0xcc],eax
0x548bcf: 8986d0000000                     mov    DWORD PTR [esi+0xd0],eax
0x548bd5: 8986d4000000                     mov    DWORD PTR [esi+0xd4],eax
0x548bdb: 8986d8000000                     mov    DWORD PTR [esi+0xd8],eax
0x548be1: 8986dc000000                     mov    DWORD PTR [esi+0xdc],eax
0x548be7: 8986e0000000                     mov    DWORD PTR [esi+0xe0],eax
0x548bed: 8986e4000000                     mov    DWORD PTR [esi+0xe4],eax
0x548bf3: 8986e8000000                     mov    DWORD PTR [esi+0xe8],eax
0x548bf9: 8986ec000000                     mov    DWORD PTR [esi+0xec],eax
0x548bff: 8986f0000000                     mov    DWORD PTR [esi+0xf0],eax
0x548c05: 8986f4000000                     mov    DWORD PTR [esi+0xf4],eax
0x548c0b: 8986f8000000                     mov    DWORD PTR [esi+0xf8],eax
0x548c11: 8986fc000000                     mov    DWORD PTR [esi+0xfc],eax
0x548c17: 898600010000                     mov    DWORD PTR [esi+0x100],eax
0x548c1d: 898604010000                     mov    DWORD PTR [esi+0x104],eax
0x548c23: 898608010000                     mov    DWORD PTR [esi+0x108],eax
0x548c29: 89860c010000                     mov    DWORD PTR [esi+0x10c],eax
0x548c2f: 898610010000                     mov    DWORD PTR [esi+0x110],eax
0x548c35: 898614010000                     mov    DWORD PTR [esi+0x114],eax
0x548c3b: 898618010000                     mov    DWORD PTR [esi+0x118],eax
0x548c41: 89861c010000                     mov    DWORD PTR [esi+0x11c],eax
0x548c47: 898620010000                     mov    DWORD PTR [esi+0x120],eax
0x548c4d: 898624010000                     mov    DWORD PTR [esi+0x124],eax
0x548c53: 898628010000                     mov    DWORD PTR [esi+0x128],eax
0x548c59: 89862c010000                     mov    DWORD PTR [esi+0x12c],eax
0x548c5f: 898630010000                     mov    DWORD PTR [esi+0x130],eax
0x548c65: c705aca7fb0004000000             mov    DWORD PTR ds:0xfba7ac,0x4
0x548c6f: 8bc6                             mov    eax,esi
0x548c71: 59                               pop    ecx
0x548c72: c3                               ret

## F-544E50 VA 0x544e50..0x544e71 raw 0x144250 len 33 SHA256 d5104f042432c0d410d4da001bba8629239303841a114a19b33453c47514b04b
0x544e50: 55                               push   ebp
0x544e51: 8bec                             mov    ebp,esp
0x544e53: 56                               push   esi
0x544e54: 8bf1                             mov    esi,ecx
0x544e56: e825000000                       call   0x544e80
0x544e5b: f6450801                         test   BYTE PTR [ebp+0x8],0x1
0x544e5f: 7409                             je     0x544e6a
0x544e61: 56                               push   esi
0x544e62: e8a5c33400                       call   0x89120c
0x544e67: 83c404                           add    esp,0x4
0x544e6a: 8bc6                             mov    eax,esi
0x544e6c: 5e                               pop    esi
0x544e6d: 5d                               pop    ebp
0x544e6e: c20400                           ret    0x4

## F-544E80 VA 0x544e80..0x544f42 raw 0x144280 len 194 SHA256 bf30fcb9bfcdf85f9d03e1a69f6fc727af39e66710e1a1f43373c6f36c8d0d8a
0x544e80: 55                               push   ebp
0x544e81: 8bec                             mov    ebp,esp
0x544e83: 6aff                             push   0xffffffff
0x544e85: 6812af9000                       push   0x90af12
0x544e8a: 64a100000000                     mov    eax,fs:0x0
0x544e90: 50                               push   eax
0x544e91: 83ec0c                           sub    esp,0xc
0x544e94: 53                               push   ebx
0x544e95: 56                               push   esi
0x544e96: 57                               push   edi
0x544e97: a1201fd600                       mov    eax,ds:0xd61f20
0x544e9c: 33c5                             xor    eax,ebp
0x544e9e: 50                               push   eax
0x544e9f: 8d45f4                           lea    eax,[ebp-0xc]
0x544ea2: 64a300000000                     mov    fs:0x0,eax
0x544ea8: 8bf9                             mov    edi,ecx
0x544eaa: 897df0                           mov    DWORD PTR [ebp-0x10],edi
0x544ead: c70744f9c000                     mov    DWORD PTR [edi],0xc0f944
0x544eb3: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x544eba: 8d9f88000000                     lea    ebx,[edi+0x88]
0x544ec0: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x544ec3: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x544ec7: 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x544eca: 8b08                             mov    ecx,DWORD PTR [eax]
0x544ecc: 50                               push   eax
0x544ecd: 51                               push   ecx
0x544ece: 8d75e8                           lea    esi,[ebp-0x18]
0x544ed1: 8bc3                             mov    eax,ebx
0x544ed3: e8e8f10000                       call   0x5540c0
0x544ed8: 8b5b04                           mov    ebx,DWORD PTR [ebx+0x4]
0x544edb: 53                               push   ebx
0x544edc: e82bc33400                       call   0x89120c
0x544ee1: 8d5f48                           lea    ebx,[edi+0x48]
0x544ee4: 895de8                           mov    DWORD PTR [ebp-0x18],ebx
0x544ee7: 53                               push   ebx
0x544ee8: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x544eec: e87fa60000                       call   0x54f570
0x544ef1: 83c408                           add    esp,0x8
0x544ef4: c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x544ef8: 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x544efb: 8b08                             mov    ecx,DWORD PTR [eax]
0x544efd: 50                               push   eax
0x544efe: 51                               push   ecx
0x544eff: 8d75ec                           lea    esi,[ebp-0x14]
0x544f02: 8bc3                             mov    eax,ebx
0x544f04: e8b7f10000                       call   0x5540c0
0x544f09: 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x544f0c: 50                               push   eax
0x544f0d: e8fac23400                       call   0x89120c
0x544f12: 8b4730                           mov    eax,DWORD PTR [edi+0x30]
0x544f15: 33f6                             xor    esi,esi
0x544f17: 83c404                           add    esp,0x4
0x544f1a: 3bc6                             cmp    eax,esi
0x544f1c: 7409                             je     0x544f27
0x544f1e: 50                               push   eax
0x544f1f: e8e8c23400                       call   0x89120c
0x544f24: 83c404                           add    esp,0x4
0x544f27: 897730                           mov    DWORD PTR [edi+0x30],esi
0x544f2a: 897734                           mov    DWORD PTR [edi+0x34],esi
0x544f2d: 897738                           mov    DWORD PTR [edi+0x38],esi
0x544f30: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x544f33: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x544f3a: 59                               pop    ecx
0x544f3b: 5f                               pop    edi
0x544f3c: 5e                               pop    esi
0x544f3d: 5b                               pop    ebx
0x544f3e: 8be5                             mov    esp,ebp
0x544f40: 5d                               pop    ebp
0x544f41: c3                               ret

## F-547200 VA 0x547200..0x547227 raw 0x146600 len 39 SHA256 a634ef2d835ae8b8b3e82fe38333a212482d01ee6dacb6c05516f183e7e4c522
0x547200: 55                               push   ebp
0x547201: 8bec                             mov    ebp,esp
0x547203: 56                               push   esi
0x547204: 8bf1                             mov    esi,ecx
0x547206: c7069cf9c000                     mov    DWORD PTR [esi],0xc0f99c
0x54720c: e86fdcffff                       call   0x544e80
0x547211: f6450801                         test   BYTE PTR [ebp+0x8],0x1
0x547215: 7409                             je     0x547220
0x547217: 56                               push   esi
0x547218: e8ef9f3400                       call   0x89120c
0x54721d: 83c404                           add    esp,0x4
0x547220: 8bc6                             mov    eax,esi
0x547222: 5e                               pop    esi
0x547223: 5d                               pop    ebp
0x547224: c20400                           ret    0x4

## F-4442D0 VA 0x4442d0..0x4442f2 raw 0x436d0 len 34 SHA256 0e355600f9e062a250380cdc9d08a15a09a935fc74351bda0bcb81d4e74b9dfc
0x4442d0: 55                               push   ebp
0x4442d1: 8bec                             mov    ebp,esp
0x4442d3: 56                               push   esi
0x4442d4: 8bf1                             mov    esi,ecx
0x4442d6: 56                               push   esi
0x4442d7: e824000000                       call   0x444300
0x4442dc: f6450801                         test   BYTE PTR [ebp+0x8],0x1
0x4442e0: 7409                             je     0x4442eb
0x4442e2: 56                               push   esi
0x4442e3: e824cf4400                       call   0x89120c
0x4442e8: 83c404                           add    esp,0x4
0x4442eb: 8bc6                             mov    eax,esi
0x4442ed: 5e                               pop    esi
0x4442ee: 5d                               pop    ebp
0x4442ef: c20400                           ret    0x4

## F-444300 VA 0x444300..0x4443a2 raw 0x43700 len 162 SHA256 3f63a9359d1d4d42e442e3b5c85c0b0dd7f6f8966d7e1f6f387502d1e1e85325
0x444300: 55                               push   ebp
0x444301: 8bec                             mov    ebp,esp
0x444303: 6aff                             push   0xffffffff
0x444305: 6878cf9000                       push   0x90cf78
0x44430a: 64a100000000                     mov    eax,fs:0x0
0x444310: 50                               push   eax
0x444311: 56                               push   esi
0x444312: 57                               push   edi
0x444313: a1201fd600                       mov    eax,ds:0xd61f20
0x444318: 33c5                             xor    eax,ebp
0x44431a: 50                               push   eax
0x44431b: 8d45f4                           lea    eax,[ebp-0xc]
0x44431e: 64a300000000                     mov    fs:0x0,eax
0x444324: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x444327: c707a4b5bf00                     mov    DWORD PTR [edi],0xbfb5a4
0x44432d: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x444334: 8b8fb8000000                     mov    ecx,DWORD PTR [edi+0xb8]
0x44433a: 85c9                             test   ecx,ecx
0x44433c: 7412                             je     0x444350
0x44433e: 8b01                             mov    eax,DWORD PTR [ecx]
0x444340: 8b10                             mov    edx,DWORD PTR [eax]
0x444342: 6a01                             push   0x1
0x444344: ffd2                             call   edx
0x444346: c787b800000000000000             mov    DWORD PTR [edi+0xb8],0x0
0x444350: 8bb7b4000000                     mov    esi,DWORD PTR [edi+0xb4]
0x444356: 85f6                             test   esi,esi
0x444358: 7427                             je     0x444381
0x44435a: 8b0e                             mov    ecx,DWORD PTR [esi]
0x44435c: 85c9                             test   ecx,ecx
0x44435e: 740e                             je     0x44436e
0x444360: 8b01                             mov    eax,DWORD PTR [ecx]
0x444362: 8b10                             mov    edx,DWORD PTR [eax]
0x444364: 6a01                             push   0x1
0x444366: ffd2                             call   edx
0x444368: c70600000000                     mov    DWORD PTR [esi],0x0
0x44436e: 56                               push   esi
0x44436f: e898ce4400                       call   0x89120c
0x444374: 83c404                           add    esp,0x4
0x444377: c787b400000000000000             mov    DWORD PTR [edi+0xb4],0x0
0x444381: 8bcf                             mov    ecx,edi
0x444383: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x44438a: e8f10a1000                       call   0x544e80
0x44438f: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x444392: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x444399: 59                               pop    ecx
0x44439a: 5f                               pop    edi
0x44439b: 5e                               pop    esi
0x44439c: 8be5                             mov    esp,ebp
0x44439e: 5d                               pop    ebp
0x44439f: c20400                           ret    0x4

## F-5475D0 VA 0x5475d0..0x5475f2 raw 0x1469d0 len 34 SHA256 1c40d608f4329e1f2f996d1a6d09f1e31337d2ea83720256cc3ab3ab7baf2717
0x5475d0: 55                               push   ebp
0x5475d1: 8bec                             mov    ebp,esp
0x5475d3: 56                               push   esi
0x5475d4: 8bf1                             mov    esi,ecx
0x5475d6: 56                               push   esi
0x5475d7: e824000000                       call   0x547600
0x5475dc: f6450801                         test   BYTE PTR [ebp+0x8],0x1
0x5475e0: 7409                             je     0x5475eb
0x5475e2: 56                               push   esi
0x5475e3: e8249c3400                       call   0x89120c
0x5475e8: 83c404                           add    esp,0x4
0x5475eb: 8bc6                             mov    eax,esi
0x5475ed: 5e                               pop    esi
0x5475ee: 5d                               pop    ebp
0x5475ef: c20400                           ret    0x4

## F-547600 VA 0x547600..0x5476c6 raw 0x146a00 len 198 SHA256 6c7e985589ece756945984bf019edd808a301d2f9ae51244238d1bc9d428d738
0x547600: 55                               push   ebp
0x547601: 8bec                             mov    ebp,esp
0x547603: 6aff                             push   0xffffffff
0x547605: 68a8cf9000                       push   0x90cfa8
0x54760a: 64a100000000                     mov    eax,fs:0x0
0x547610: 50                               push   eax
0x547611: 53                               push   ebx
0x547612: 56                               push   esi
0x547613: 57                               push   edi
0x547614: a1201fd600                       mov    eax,ds:0xd61f20
0x547619: 33c5                             xor    eax,ebp
0x54761b: 50                               push   eax
0x54761c: 8d45f4                           lea    eax,[ebp-0xc]
0x54761f: 64a300000000                     mov    fs:0x0,eax
0x547625: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x547628: c70614fac000                     mov    DWORD PTR [esi],0xc0fa14
0x54762e: 33db                             xor    ebx,ebx
0x547630: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x547633: 8bbeb8000000                     mov    edi,DWORD PTR [esi+0xb8]
0x547639: 3bfb                             cmp    edi,ebx
0x54763b: 741f                             je     0x54765c
0x54763d: 8b0f                             mov    ecx,DWORD PTR [edi]
0x54763f: 3bcb                             cmp    ecx,ebx
0x547641: 740a                             je     0x54764d
0x547643: 8b01                             mov    eax,DWORD PTR [ecx]
0x547645: 8b10                             mov    edx,DWORD PTR [eax]
0x547647: 6a01                             push   0x1
0x547649: ffd2                             call   edx
0x54764b: 891f                             mov    DWORD PTR [edi],ebx
0x54764d: 57                               push   edi
0x54764e: e8b99b3400                       call   0x89120c
0x547653: 83c404                           add    esp,0x4
0x547656: 899eb8000000                     mov    DWORD PTR [esi+0xb8],ebx
0x54765c: 8b8ebc000000                     mov    ecx,DWORD PTR [esi+0xbc]
0x547662: 3bcb                             cmp    ecx,ebx
0x547664: 740e                             je     0x547674
0x547666: 8b01                             mov    eax,DWORD PTR [ecx]
0x547668: 8b10                             mov    edx,DWORD PTR [eax]
0x54766a: 6a01                             push   0x1
0x54766c: ffd2                             call   edx
0x54766e: 899ebc000000                     mov    DWORD PTR [esi+0xbc],ebx
0x547674: 8b8ec0000000                     mov    ecx,DWORD PTR [esi+0xc0]
0x54767a: 3bcb                             cmp    ecx,ebx
0x54767c: 740e                             je     0x54768c
0x54767e: 8b01                             mov    eax,DWORD PTR [ecx]
0x547680: 8b10                             mov    edx,DWORD PTR [eax]
0x547682: 6a01                             push   0x1
0x547684: ffd2                             call   edx
0x547686: 899ec0000000                     mov    DWORD PTR [esi+0xc0],ebx
0x54768c: 8b8ec4000000                     mov    ecx,DWORD PTR [esi+0xc4]
0x547692: 3bcb                             cmp    ecx,ebx
0x547694: 740e                             je     0x5476a4
0x547696: 8b01                             mov    eax,DWORD PTR [ecx]
0x547698: 8b10                             mov    edx,DWORD PTR [eax]
0x54769a: 6a01                             push   0x1
0x54769c: ffd2                             call   edx
0x54769e: 899ec4000000                     mov    DWORD PTR [esi+0xc4],ebx
0x5476a4: 8bce                             mov    ecx,esi
0x5476a6: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5476ad: e8ced7ffff                       call   0x544e80
0x5476b2: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5476b5: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5476bc: 59                               pop    ecx
0x5476bd: 5f                               pop    edi
0x5476be: 5e                               pop    esi
0x5476bf: 5b                               pop    ebx
0x5476c0: 8be5                             mov    esp,ebp
0x5476c2: 5d                               pop    ebp
0x5476c3: c20400                           ret    0x4

## F-548600 VA 0x548600..0x548622 raw 0x147a00 len 34 SHA256 14b52b6023d3ac3bb7f966a27b1a4546eea0dbc1edf34adbce63fe708992a621
0x548600: 55                               push   ebp
0x548601: 8bec                             mov    ebp,esp
0x548603: 56                               push   esi
0x548604: 8bf1                             mov    esi,ecx
0x548606: 56                               push   esi
0x548607: e824000000                       call   0x548630
0x54860c: f6450801                         test   BYTE PTR [ebp+0x8],0x1
0x548610: 7409                             je     0x54861b
0x548612: 56                               push   esi
0x548613: e8f48b3400                       call   0x89120c
0x548618: 83c404                           add    esp,0x4
0x54861b: 8bc6                             mov    eax,esi
0x54861d: 5e                               pop    esi
0x54861e: 5d                               pop    ebp
0x54861f: c20400                           ret    0x4

## F-548630 VA 0x548630..0x5486d2 raw 0x147a30 len 162 SHA256 5873c1697585c7e983fa58cb71ded12660a5b61b49a9263f4f36bdd43227b4e0
0x548630: 55                               push   ebp
0x548631: 8bec                             mov    ebp,esp
0x548633: 6aff                             push   0xffffffff
0x548635: 6878cf9000                       push   0x90cf78
0x54863a: 64a100000000                     mov    eax,fs:0x0
0x548640: 50                               push   eax
0x548641: 56                               push   esi
0x548642: 57                               push   edi
0x548643: a1201fd600                       mov    eax,ds:0xd61f20
0x548648: 33c5                             xor    eax,ebp
0x54864a: 50                               push   eax
0x54864b: 8d45f4                           lea    eax,[ebp-0xc]
0x54864e: 64a300000000                     mov    fs:0x0,eax
0x548654: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x548657: c707c4fac000                     mov    DWORD PTR [edi],0xc0fac4
0x54865d: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x548664: 8b8fb8000000                     mov    ecx,DWORD PTR [edi+0xb8]
0x54866a: 85c9                             test   ecx,ecx
0x54866c: 7412                             je     0x548680
0x54866e: 8b01                             mov    eax,DWORD PTR [ecx]
0x548670: 8b10                             mov    edx,DWORD PTR [eax]
0x548672: 6a01                             push   0x1
0x548674: ffd2                             call   edx
0x548676: c787b800000000000000             mov    DWORD PTR [edi+0xb8],0x0
0x548680: 8bb7b4000000                     mov    esi,DWORD PTR [edi+0xb4]
0x548686: 85f6                             test   esi,esi
0x548688: 7427                             je     0x5486b1
0x54868a: 8b0e                             mov    ecx,DWORD PTR [esi]
0x54868c: 85c9                             test   ecx,ecx
0x54868e: 740e                             je     0x54869e
0x548690: 8b01                             mov    eax,DWORD PTR [ecx]
0x548692: 8b10                             mov    edx,DWORD PTR [eax]
0x548694: 6a01                             push   0x1
0x548696: ffd2                             call   edx
0x548698: c70600000000                     mov    DWORD PTR [esi],0x0
0x54869e: 56                               push   esi
0x54869f: e8688b3400                       call   0x89120c
0x5486a4: 83c404                           add    esp,0x4
0x5486a7: c787b400000000000000             mov    DWORD PTR [edi+0xb4],0x0
0x5486b1: 8bcf                             mov    ecx,edi
0x5486b3: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5486ba: e8c1c7ffff                       call   0x544e80
0x5486bf: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5486c2: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5486c9: 59                               pop    ecx
0x5486ca: 5f                               pop    edi
0x5486cb: 5e                               pop    esi
0x5486cc: 8be5                             mov    esp,ebp
0x5486ce: 5d                               pop    ebp
0x5486cf: c20400                           ret    0x4

## F-548C80 VA 0x548c80..0x548ca7 raw 0x148080 len 39 SHA256 930214af23056316b0352e6f0d8d81f18feacdc6148af321272e3f9d78bb2595
0x548c80: 55                               push   ebp
0x548c81: 8bec                             mov    ebp,esp
0x548c83: 56                               push   esi
0x548c84: 8bf1                             mov    esi,ecx
0x548c86: c7061cfbc000                     mov    DWORD PTR [esi],0xc0fb1c
0x548c8c: e8efc1ffff                       call   0x544e80
0x548c91: f6450801                         test   BYTE PTR [ebp+0x8],0x1
0x548c95: 7409                             je     0x548ca0
0x548c97: 56                               push   esi
0x548c98: e86f853400                       call   0x89120c
0x548c9d: 83c404                           add    esp,0x4
0x548ca0: 8bc6                             mov    eax,esi
0x548ca2: 5e                               pop    esi
0x548ca3: 5d                               pop    ebp
0x548ca4: c20400                           ret    0x4

## F-547C80 VA 0x547c80..0x547cea raw 0x147080 len 106 SHA256 c46d6e2f95ca6cc7ca86a006fbfc6487c85969fe00d8f3de3cb0c5bfe1bcc51d
0x547c80: 56                               push   esi
0x547c81: 57                               push   edi
0x547c82: 8bf9                             mov    edi,ecx
0x547c84: 8b87b8000000                     mov    eax,DWORD PTR [edi+0xb8]
0x547c8a: 8b30                             mov    esi,DWORD PTR [eax]
0x547c8c: e84f6e2700                       call   0x7beae0
0x547c91: 8bb7bc000000                     mov    esi,DWORD PTR [edi+0xbc]
0x547c97: 8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x547c9a: 85c9                             test   ecx,ecx
0x547c9c: 740f                             je     0x547cad
0x547c9e: 8b11                             mov    edx,DWORD PTR [ecx]
0x547ca0: 8b02                             mov    eax,DWORD PTR [edx]
0x547ca2: 6a01                             push   0x1
0x547ca4: ffd0                             call   eax
0x547ca6: c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x547cad: 8bb7c0000000                     mov    esi,DWORD PTR [edi+0xc0]
0x547cb3: 8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x547cb6: 85c9                             test   ecx,ecx
0x547cb8: 740f                             je     0x547cc9
0x547cba: 8b11                             mov    edx,DWORD PTR [ecx]
0x547cbc: 8b02                             mov    eax,DWORD PTR [edx]
0x547cbe: 6a01                             push   0x1
0x547cc0: ffd0                             call   eax
0x547cc2: c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x547cc9: 8bbfc4000000                     mov    edi,DWORD PTR [edi+0xc4]
0x547ccf: 8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0x547cd2: 85c9                             test   ecx,ecx
0x547cd4: 740f                             je     0x547ce5
0x547cd6: 8b11                             mov    edx,DWORD PTR [ecx]
0x547cd8: 8b02                             mov    eax,DWORD PTR [edx]
0x547cda: 6a01                             push   0x1
0x547cdc: ffd0                             call   eax
0x547cde: c7470400000000                   mov    DWORD PTR [edi+0x4],0x0
0x547ce5: 5f                               pop    edi
0x547ce6: 33c0                             xor    eax,eax
0x547ce8: 5e                               pop    esi
0x547ce9: c3                               ret

## F-5486E0 VA 0x5486e0..0x54872e raw 0x147ae0 len 78 SHA256 5eec57412393a6795a338ff0887394705776df4463a13da381171c4d9efe828f
0x5486e0: 57                               push   edi
0x5486e1: 8bf9                             mov    edi,ecx
0x5486e3: 8b8fa0000000                     mov    ecx,DWORD PTR [edi+0xa0]
0x5486e9: 85c9                             test   ecx,ecx
0x5486eb: 7412                             je     0x5486ff
0x5486ed: 8b01                             mov    eax,DWORD PTR [ecx]
0x5486ef: 8b10                             mov    edx,DWORD PTR [eax]
0x5486f1: 6a01                             push   0x1
0x5486f3: ffd2                             call   edx
0x5486f5: c787a000000000000000             mov    DWORD PTR [edi+0xa0],0x0
0x5486ff: 8b87b4000000                     mov    eax,DWORD PTR [edi+0xb4]
0x548705: 56                               push   esi
0x548706: 8b30                             mov    esi,DWORD PTR [eax]
0x548708: e8d3632700                       call   0x7beae0
0x54870d: 8bbfb8000000                     mov    edi,DWORD PTR [edi+0xb8]
0x548713: 8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0x548716: 5e                               pop    esi
0x548717: 85c9                             test   ecx,ecx
0x548719: 740f                             je     0x54872a
0x54871b: 8b11                             mov    edx,DWORD PTR [ecx]
0x54871d: 8b02                             mov    eax,DWORD PTR [edx]
0x54871f: 6a01                             push   0x1
0x548721: ffd0                             call   eax
0x548723: c7470400000000                   mov    DWORD PTR [edi+0x4],0x0
0x54872a: 33c0                             xor    eax,eax
0x54872c: 5f                               pop    edi
0x54872d: c3                               ret

## F-8DC2F0 VA 0x8dc2f0..0x8dc2f3 raw 0x4db6f0 len 3 SHA256 4bc724f3b1d0caf4fe369c18cba3102e6c4ea057f63fe1587e3973134a7f755e
0x8dc2f0: 33c0                             xor    eax,eax
0x8dc2f2: c3                               ret

## F-4A4240 VA 0x4a4240..0x4a4291 raw 0xa3640 len 81 SHA256 a8f966b7e7e8438b3f0648ce627fe2f6eaa50eb3d4602dcb752182295e3f192e
0x4a4240: 55                               push   ebp
0x4a4241: 8bec                             mov    ebp,esp
0x4a4243: 83ec14                           sub    esp,0x14
0x4a4246: 668b4d08                         mov    cx,WORD PTR [ebp+0x8]
0x4a424a: b8c6000000                       mov    eax,0xc6
0x4a424f: 33d2                             xor    edx,edx
0x4a4251: 668945ec                         mov    WORD PTR [ebp-0x14],ax
0x4a4255: b801000000                       mov    eax,0x1
0x4a425a: 66894dee                         mov    WORD PTR [ebp-0x12],cx
0x4a425e: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4a4261: 668955f4                         mov    WORD PTR [ebp-0xc],dx
0x4a4265: 8945f6                           mov    DWORD PTR [ebp-0xa],eax
0x4a4268: 66c745fa0101                     mov    WORD PTR [ebp-0x6],0x101
0x4a426e: 391598a7fb00                     cmp    DWORD PTR ds:0xfba798,edx
0x4a4274: 7515                             jne    0x4a428b
0x4a4276: 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x4a427c: 8b01                             mov    eax,DWORD PTR [ecx]
0x4a427e: 8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4a4281: 6a10                             push   0x10
0x4a4283: 8d55ec                           lea    edx,[ebp-0x14]
0x4a4286: 52                               push   edx
0x4a4287: 6a00                             push   0x0
0x4a4289: ffd0                             call   eax
0x4a428b: 8be5                             mov    esp,ebp
0x4a428d: 5d                               pop    ebp
0x4a428e: c20400                           ret    0x4

## F-803EC0 VA 0x803ec0..0x803fe2 raw 0x4032c0 len 290 SHA256 3b38183b4712162e8e8f864d492a55a3a0ae5ea4439f48906d66ca601ceb8418
0x803ec0: 55                               push   ebp
0x803ec1: 8bec                             mov    ebp,esp
0x803ec3: 6aff                             push   0xffffffff
0x803ec5: 68e59a9000                       push   0x909ae5
0x803eca: 64a100000000                     mov    eax,fs:0x0
0x803ed0: 50                               push   eax
0x803ed1: 83ec0c                           sub    esp,0xc
0x803ed4: 53                               push   ebx
0x803ed5: 56                               push   esi
0x803ed6: 57                               push   edi
0x803ed7: a1201fd600                       mov    eax,ds:0xd61f20
0x803edc: 33c5                             xor    eax,ebp
0x803ede: 50                               push   eax
0x803edf: 8d45f4                           lea    eax,[ebp-0xc]
0x803ee2: 64a300000000                     mov    fs:0x0,eax
0x803ee8: 8bf9                             mov    edi,ecx
0x803eea: 897df0                           mov    DWORD PTR [ebp-0x10],edi
0x803eed: c7070814c500                     mov    DWORD PTR [edi],0xc51408
0x803ef3: 33db                             xor    ebx,ebx
0x803ef5: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x803ef8: 8b470c                           mov    eax,DWORD PTR [edi+0xc]
0x803efb: 8b30                             mov    esi,DWORD PTR [eax]
0x803efd: 3bf0                             cmp    esi,eax
0x803eff: 7458                             je     0x803f59
0x803f01: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x803f04: 8b08                             mov    ecx,DWORD PTR [eax]
0x803f06: 51                               push   ecx
0x803f07: ff15d425bd00                     call   DWORD PTR ds:0xbd25d4
0x803f0d: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x803f10: 50                               push   eax
0x803f11: e8f6d20800                       call   0x89120c
0x803f16: 83c404                           add    esp,0x4
0x803f19: 385e15                           cmp    BYTE PTR [esi+0x15],bl
0x803f1c: 7536                             jne    0x803f54
0x803f1e: 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x803f21: 385815                           cmp    BYTE PTR [eax+0x15],bl
0x803f24: 7515                             jne    0x803f3b
0x803f26: 8bf0                             mov    esi,eax
0x803f28: 8b06                             mov    eax,DWORD PTR [esi]
0x803f2a: 385815                           cmp    BYTE PTR [eax+0x15],bl
0x803f2d: 7525                             jne    0x803f54
0x803f2f: 90                               nop
0x803f30: 8bf0                             mov    esi,eax
0x803f32: 8b06                             mov    eax,DWORD PTR [esi]
0x803f34: 385815                           cmp    BYTE PTR [eax+0x15],bl
0x803f37: 74f7                             je     0x803f30
0x803f39: eb19                             jmp    0x803f54
0x803f3b: 8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x803f3e: 385815                           cmp    BYTE PTR [eax+0x15],bl
0x803f41: 750f                             jne    0x803f52
0x803f43: 3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x803f46: 750a                             jne    0x803f52
0x803f48: 8bf0                             mov    esi,eax
0x803f4a: 8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x803f4d: 385815                           cmp    BYTE PTR [eax+0x15],bl
0x803f50: 74f1                             je     0x803f43
0x803f52: 8bf0                             mov    esi,eax
0x803f54: 3b770c                           cmp    esi,DWORD PTR [edi+0xc]
0x803f57: 75a8                             jne    0x803f01
0x803f59: 8b5750                           mov    edx,DWORD PTR [edi+0x50]
0x803f5c: 6aff                             push   0xffffffff
0x803f5e: 52                               push   edx
0x803f5f: c7474c01000000                   mov    DWORD PTR [edi+0x4c],0x1
0x803f66: ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
0x803f6c: 8b4750                           mov    eax,DWORD PTR [edi+0x50]
0x803f6f: 50                               push   eax
0x803f70: ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
0x803f76: 891d54a8fb00                     mov    DWORD PTR ds:0xfba854,ebx
0x803f7c: 8d5f18                           lea    ebx,[edi+0x18]
0x803f7f: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x803f82: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x803f86: 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x803f89: 8b08                             mov    ecx,DWORD PTR [eax]
0x803f8b: 50                               push   eax
0x803f8c: 51                               push   ecx
0x803f8d: 8d75e8                           lea    esi,[ebp-0x18]
0x803f90: 8bc3                             mov    eax,ebx
0x803f92: e82901d5ff                       call   0x5540c0
0x803f97: 8b5b04                           mov    ebx,DWORD PTR [ebx+0x4]
0x803f9a: 53                               push   ebx
0x803f9b: e86cd20800                       call   0x89120c
0x803fa0: 8d5f08                           lea    ebx,[edi+0x8]
0x803fa3: 83c404                           add    esp,0x4
0x803fa6: 895de8                           mov    DWORD PTR [ebp-0x18],ebx
0x803fa9: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x803fad: 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x803fb0: 8b08                             mov    ecx,DWORD PTR [eax]
0x803fb2: 50                               push   eax
0x803fb3: 51                               push   ecx
0x803fb4: 8d75ec                           lea    esi,[ebp-0x14]
0x803fb7: 8bc3                             mov    eax,ebx
0x803fb9: e80201d5ff                       call   0x5540c0
0x803fbe: 8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0x803fc1: 51                               push   ecx
0x803fc2: e845d20800                       call   0x89120c
0x803fc7: 83c404                           add    esp,0x4
0x803fca: c707fc13c500                     mov    DWORD PTR [edi],0xc513fc
0x803fd0: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x803fd3: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x803fda: 59                               pop    ecx
0x803fdb: 5f                               pop    edi
0x803fdc: 5e                               pop    esi
0x803fdd: 5b                               pop    ebx
0x803fde: 8be5                             mov    esp,ebp
0x803fe0: 5d                               pop    ebp
0x803fe1: c3                               ret

## F-804460 VA 0x804460..0x804650 raw 0x403860 len 496 SHA256 91949d40d1d089cf0e1e478a8fd7ddfe8155330046a6e848422129d88b60b0d6
0x804460: 55                               push   ebp
0x804461: 8bec                             mov    ebp,esp
0x804463: 6aff                             push   0xffffffff
0x804465: 689c529000                       push   0x90529c
0x80446a: 64a100000000                     mov    eax,fs:0x0
0x804470: 50                               push   eax
0x804471: 51                               push   ecx
0x804472: 53                               push   ebx
0x804473: 56                               push   esi
0x804474: 57                               push   edi
0x804475: a1201fd600                       mov    eax,ds:0xd61f20
0x80447a: 33c5                             xor    eax,ebp
0x80447c: 50                               push   eax
0x80447d: 8d45f4                           lea    eax,[ebp-0xc]
0x804480: 64a300000000                     mov    fs:0x0,eax
0x804486: 8bf1                             mov    esi,ecx
0x804488: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x80448b: c706ec15c500                     mov    DWORD PTR [esi],0xc515ec
0x804491: 33db                             xor    ebx,ebx
0x804493: c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0x80449a: 399ea4000000                     cmp    DWORD PTR [esi+0xa4],ebx
0x8044a0: 0f8436010000                     je     0x8045dc
0x8044a6: 899ea4000000                     mov    DWORD PTR [esi+0xa4],ebx
0x8044ac: 8b8698000000                     mov    eax,DWORD PTR [esi+0x98]
0x8044b2: 2b8694000000                     sub    eax,DWORD PTR [esi+0x94]
0x8044b8: 33ff                             xor    edi,edi
0x8044ba: c1f802                           sar    eax,0x2
0x8044bd: 85c0                             test   eax,eax
0x8044bf: 7434                             je     0x8044f5
0x8044c1: 8b1dd020bd00                     mov    ebx,DWORD PTR ds:0xbd20d0
0x8044c7: eb07                             jmp    0x8044d0
0x8044c9: 8da42400000000                   lea    esp,[esp+0x0]
0x8044d0: 8b8e94000000                     mov    ecx,DWORD PTR [esi+0x94]
0x8044d6: 8b14b9                           mov    edx,DWORD PTR [ecx+edi*4]
0x8044d9: 8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x8044dc: 50                               push   eax
0x8044dd: ffd3                             call   ebx
0x8044df: 8b8e98000000                     mov    ecx,DWORD PTR [esi+0x98]
0x8044e5: 2b8e94000000                     sub    ecx,DWORD PTR [esi+0x94]
0x8044eb: 47                               inc    edi
0x8044ec: c1f902                           sar    ecx,0x2
0x8044ef: 3bf9                             cmp    edi,ecx
0x8044f1: 72dd                             jb     0x8044d0
0x8044f3: 33db                             xor    ebx,ebx
0x8044f5: 8b96a8000000                     mov    edx,DWORD PTR [esi+0xa8]
0x8044fb: 8b86a4000000                     mov    eax,DWORD PTR [esi+0xa4]
0x804501: 6aff                             push   0xffffffff
0x804503: 6a01                             push   0x1
0x804505: 52                               push   edx
0x804506: 50                               push   eax
0x804507: ff15b422bd00                     call   DWORD PTR ds:0xbd22b4
0x80450d: 8b8e98000000                     mov    ecx,DWORD PTR [esi+0x98]
0x804513: 2b8e94000000                     sub    ecx,DWORD PTR [esi+0x94]
0x804519: 33ff                             xor    edi,edi
0x80451b: c1f902                           sar    ecx,0x2
0x80451e: 85c9                             test   ecx,ecx
0x804520: 7454                             je     0x804576
0x804522: 8b1dc821bd00                     mov    ebx,DWORD PTR ds:0xbd21c8
0x804528: eb06                             jmp    0x804530
0x80452a: 8d9b00000000                     lea    ebx,[ebx+0x0]
0x804530: 8b9694000000                     mov    edx,DWORD PTR [esi+0x94]
0x804536: 8b04ba                           mov    eax,DWORD PTR [edx+edi*4]
0x804539: 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x80453c: 51                               push   ecx
0x80453d: ffd3                             call   ebx
0x80453f: 8b9694000000                     mov    edx,DWORD PTR [esi+0x94]
0x804545: 8b04ba                           mov    eax,DWORD PTR [edx+edi*4]
0x804548: 8b480c                           mov    ecx,DWORD PTR [eax+0xc]
0x80454b: 51                               push   ecx
0x80454c: ffd3                             call   ebx
0x80454e: 8b9694000000                     mov    edx,DWORD PTR [esi+0x94]
0x804554: 8b04ba                           mov    eax,DWORD PTR [edx+edi*4]
0x804557: 50                               push   eax
0x804558: e8afcc0800                       call   0x89120c
0x80455d: 8b8e98000000                     mov    ecx,DWORD PTR [esi+0x98]
0x804563: 2b8e94000000                     sub    ecx,DWORD PTR [esi+0x94]
0x804569: 47                               inc    edi
0x80456a: c1f902                           sar    ecx,0x2
0x80456d: 83c404                           add    esp,0x4
0x804570: 3bf9                             cmp    edi,ecx
0x804572: 72bc                             jb     0x804530
0x804574: 33db                             xor    ebx,ebx
0x804576: 8b8e98000000                     mov    ecx,DWORD PTR [esi+0x98]
0x80457c: 8bbe94000000                     mov    edi,DWORD PTR [esi+0x94]
0x804582: 3bf9                             cmp    edi,ecx
0x804584: 7423                             je     0x8045a9
0x804586: 8bc1                             mov    eax,ecx
0x804588: 2bc1                             sub    eax,ecx
0x80458a: c1f802                           sar    eax,0x2
0x80458d: 8d1c8500000000                   lea    ebx,[eax*4+0x0]
0x804594: 53                               push   ebx
0x804595: 51                               push   ecx
0x804596: 57                               push   edi
0x804597: e854cd0800                       call   0x8912f0
0x80459c: 03df                             add    ebx,edi
0x80459e: 83c40c                           add    esp,0xc
0x8045a1: 899e98000000                     mov    DWORD PTR [esi+0x98],ebx
0x8045a7: 33db                             xor    ebx,ebx
0x8045a9: 8b8eac000000                     mov    ecx,DWORD PTR [esi+0xac]
0x8045af: 8bbea8000000                     mov    edi,DWORD PTR [esi+0xa8]
0x8045b5: 3bf9                             cmp    edi,ecx
0x8045b7: 7423                             je     0x8045dc
0x8045b9: 8bc1                             mov    eax,ecx
0x8045bb: 2bc1                             sub    eax,ecx
0x8045bd: c1f802                           sar    eax,0x2
0x8045c0: 8d1c8500000000                   lea    ebx,[eax*4+0x0]
0x8045c7: 53                               push   ebx
0x8045c8: 51                               push   ecx
0x8045c9: 57                               push   edi
0x8045ca: e821cd0800                       call   0x8912f0
0x8045cf: 03df                             add    ebx,edi
0x8045d1: 83c40c                           add    esp,0xc
0x8045d4: 899eac000000                     mov    DWORD PTR [esi+0xac],ebx
0x8045da: 33db                             xor    ebx,ebx
0x8045dc: 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x8045e2: 3bcb                             cmp    ecx,ebx
0x8045e4: 740e                             je     0x8045f4
0x8045e6: 8b11                             mov    edx,DWORD PTR [ecx]
0x8045e8: 8b02                             mov    eax,DWORD PTR [edx]
0x8045ea: 6a01                             push   0x1
0x8045ec: ffd0                             call   eax
0x8045ee: 891d54a8fb00                     mov    DWORD PTR ds:0xfba854,ebx
0x8045f4: 8b86a8000000                     mov    eax,DWORD PTR [esi+0xa8]
0x8045fa: 3bc3                             cmp    eax,ebx
0x8045fc: 7409                             je     0x804607
0x8045fe: 50                               push   eax
0x8045ff: e808cc0800                       call   0x89120c
0x804604: 83c404                           add    esp,0x4
0x804607: 899ea8000000                     mov    DWORD PTR [esi+0xa8],ebx
0x80460d: 899eac000000                     mov    DWORD PTR [esi+0xac],ebx
0x804613: 899eb0000000                     mov    DWORD PTR [esi+0xb0],ebx
0x804619: 8b8694000000                     mov    eax,DWORD PTR [esi+0x94]
0x80461f: 3bc3                             cmp    eax,ebx
0x804621: 7409                             je     0x80462c
0x804623: 50                               push   eax
0x804624: e8e3cb0800                       call   0x89120c
0x804629: 83c404                           add    esp,0x4
0x80462c: 899e94000000                     mov    DWORD PTR [esi+0x94],ebx
0x804632: 899e98000000                     mov    DWORD PTR [esi+0x98],ebx
0x804638: 899e9c000000                     mov    DWORD PTR [esi+0x9c],ebx
0x80463e: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x804641: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x804648: 59                               pop    ecx
0x804649: 5f                               pop    edi
0x80464a: 5e                               pop    esi
0x80464b: 5b                               pop    ebx
0x80464c: 8be5                             mov    esp,ebp
0x80464e: 5d                               pop    ebp
0x80464f: c3                               ret

## F-8069A0 VA 0x8069a0..0x8069f6 raw 0x405da0 len 86 SHA256 15bfdafb9caef08f72626dffb2508c7568a9f251e13013959d0b965c1c16d3f1
0x8069a0: 55                               push   ebp
0x8069a1: 8bec                             mov    ebp,esp
0x8069a3: 51                               push   ecx
0x8069a4: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x8069a7: 56                               push   esi
0x8069a8: 8bf1                             mov    esi,ecx
0x8069aa: 8d4d08                           lea    ecx,[ebp+0x8]
0x8069ad: 894508                           mov    DWORD PTR [ebp+0x8],eax
0x8069b0: 51                               push   ecx
0x8069b1: 8d4e18                           lea    ecx,[esi+0x18]
0x8069b4: 8d45fc                           lea    eax,[ebp-0x4]
0x8069b7: e804cf0300                       call   0x8438c0
0x8069bc: 8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x8069bf: 3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
0x8069c2: 5e                               pop    esi
0x8069c3: 7407                             je     0x8069cc
0x8069c5: 8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0x8069c8: 85c9                             test   ecx,ecx
0x8069ca: 7508                             jne    0x8069d4
0x8069cc: 33c0                             xor    eax,eax
0x8069ce: 8be5                             mov    esp,ebp
0x8069d0: 5d                               pop    ebp
0x8069d1: c20c00                           ret    0xc
0x8069d4: 8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x8069d7: 85c0                             test   eax,eax
0x8069d9: 750b                             jne    0x8069e6
0x8069db: b801000000                       mov    eax,0x1
0x8069e0: 8be5                             mov    esp,ebp
0x8069e2: 5d                               pop    ebp
0x8069e3: c20c00                           ret    0xc
0x8069e6: 8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x8069e9: 50                               push   eax
0x8069ea: 52                               push   edx
0x8069eb: e8e0f6ffff                       call   0x8060d0
0x8069f0: 8be5                             mov    esp,ebp
0x8069f2: 5d                               pop    ebp
0x8069f3: c20c00                           ret    0xc

## F-8438C0 VA 0x8438c0..0x843927 raw 0x442cc0 len 103 SHA256 cf664342d0503cf1b31348885f934ede877330a746a88eec42170e09080173b6
0x8438c0: 55                               push   ebp
0x8438c1: 8bec                             mov    ebp,esp
0x8438c3: 51                               push   ecx
0x8438c4: 53                               push   ebx
0x8438c5: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x8438c8: 56                               push   esi
0x8438c9: 8bf1                             mov    esi,ecx
0x8438cb: 8b5604                           mov    edx,DWORD PTR [esi+0x4]
0x8438ce: 8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0x8438d1: 80791500                         cmp    BYTE PTR [ecx+0x15],0x0
0x8438d5: 751e                             jne    0x8438f5
0x8438d7: 57                               push   edi
0x8438d8: 8b3b                             mov    edi,DWORD PTR [ebx]
0x8438da: 8d9b00000000                     lea    ebx,[ebx+0x0]
0x8438e0: 39790c                           cmp    DWORD PTR [ecx+0xc],edi
0x8438e3: 7d05                             jge    0x8438ea
0x8438e5: 8b4908                           mov    ecx,DWORD PTR [ecx+0x8]
0x8438e8: eb04                             jmp    0x8438ee
0x8438ea: 8bd1                             mov    edx,ecx
0x8438ec: 8b09                             mov    ecx,DWORD PTR [ecx]
0x8438ee: 80791500                         cmp    BYTE PTR [ecx+0x15],0x0
0x8438f2: 74ec                             je     0x8438e0
0x8438f4: 5f                               pop    edi
0x8438f5: 8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x8438f8: 895508                           mov    DWORD PTR [ebp+0x8],edx
0x8438fb: 3bd1                             cmp    edx,ecx
0x8438fd: 7416                             je     0x843915
0x8438ff: 8b33                             mov    esi,DWORD PTR [ebx]
0x843901: 3b720c                           cmp    esi,DWORD PTR [edx+0xc]
0x843904: 7c0f                             jl     0x843915
0x843906: 8d4d08                           lea    ecx,[ebp+0x8]
0x843909: 8b09                             mov    ecx,DWORD PTR [ecx]
0x84390b: 5e                               pop    esi
0x84390c: 8908                             mov    DWORD PTR [eax],ecx
0x84390e: 5b                               pop    ebx
0x84390f: 8be5                             mov    esp,ebp
0x843911: 5d                               pop    ebp
0x843912: c20400                           ret    0x4
0x843915: 894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0x843918: 8d4dfc                           lea    ecx,[ebp-0x4]
0x84391b: 8b09                             mov    ecx,DWORD PTR [ecx]
0x84391d: 5e                               pop    esi
0x84391e: 8908                             mov    DWORD PTR [eax],ecx
0x843920: 5b                               pop    ebx
0x843921: 8be5                             mov    esp,ebp
0x843923: 5d                               pop    ebp
0x843924: c20400                           ret    0x4

## F-8060D0 VA 0x8060d0..0x806191 raw 0x4054d0 len 193 SHA256 b8a91d2db14f1edac4a7b379250ed8a006d4e5518958e978678a71f079df4509
0x8060d0: 55                               push   ebp
0x8060d1: 8bec                             mov    ebp,esp
0x8060d3: 6aff                             push   0xffffffff
0x8060d5: 685e999000                       push   0x90995e
0x8060da: 64a100000000                     mov    eax,fs:0x0
0x8060e0: 50                               push   eax
0x8060e1: 53                               push   ebx
0x8060e2: 56                               push   esi
0x8060e3: 57                               push   edi
0x8060e4: a1201fd600                       mov    eax,ds:0xd61f20
0x8060e9: 33c5                             xor    eax,ebp
0x8060eb: 50                               push   eax
0x8060ec: 8d45f4                           lea    eax,[ebp-0xc]
0x8060ef: 64a300000000                     mov    fs:0x0,eax
0x8060f5: 8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
0x8060f8: 8bf1                             mov    esi,ecx
0x8060fa: 81bea4a000002c010000             cmp    DWORD PTR [esi+0xa0a4],0x12c
0x806104: 7e16                             jle    0x80611c
0x806106: 33c0                             xor    eax,eax
0x806108: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x80610b: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x806112: 59                               pop    ecx
0x806113: 5f                               pop    edi
0x806114: 5e                               pop    esi
0x806115: 5b                               pop    ebx
0x806116: 8be5                             mov    esp,ebp
0x806118: 5d                               pop    ebp
0x806119: c20800                           ret    0x8
0x80611c: b801000000                       mov    eax,0x1
0x806121: 84055433fe00                     test   BYTE PTR ds:0xfe3354,al
0x806127: 7526                             jne    0x80614f
0x806129: 09055433fe00                     or     DWORD PTR ds:0xfe3354,eax
0x80612f: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x806136: e8e50f0000                       call   0x807120
0x80613b: 68900bbd00                       push   0xbd0b90
0x806140: e8d5c10800                       call   0x89231a
0x806145: 83c404                           add    esp,0x4
0x806148: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x80614f: bf5833fe00                       mov    edi,0xfe3358
0x806154: e817130000                       call   0x807470
0x806159: 8bf8                             mov    edi,eax
0x80615b: 81fb00100000                     cmp    ebx,0x1000
0x806161: 7714                             ja     0x806177
0x806163: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x806166: 53                               push   ebx
0x806167: 50                               push   eax
0x806168: 8d4f08                           lea    ecx,[edi+0x8]
0x80616b: 51                               push   ecx
0x80616c: e85f7a0900                       call   0x89dbd0
0x806171: 83c40c                           add    esp,0xc
0x806174: 895f04                           mov    DWORD PTR [edi+0x4],ebx
0x806177: 57                               push   edi
0x806178: e8e3feffff                       call   0x806060
0x80617d: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x806180: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x806187: 59                               pop    ecx
0x806188: 5f                               pop    edi
0x806189: 5e                               pop    esi
0x80618a: 5b                               pop    ebx
0x80618b: 8be5                             mov    esp,ebp
0x80618d: 5d                               pop    ebp
0x80618e: c20800                           ret    0x8

## F-807120 VA 0x807120..0x80733e raw 0x406520 len 542 SHA256 e14c3152ffc95dd5626ec43985bc0efda4c3b65cbd91efb22c2e046b2ac79e4f
0x807120: 55                               push   ebp
0x807121: 8bec                             mov    ebp,esp
0x807123: 6aff                             push   0xffffffff
0x807125: 6899749000                       push   0x907499
0x80712a: 64a100000000                     mov    eax,fs:0x0
0x807130: 50                               push   eax
0x807131: 83ec24                           sub    esp,0x24
0x807134: 53                               push   ebx
0x807135: 56                               push   esi
0x807136: 57                               push   edi
0x807137: a1201fd600                       mov    eax,ds:0xd61f20
0x80713c: 33c5                             xor    eax,ebp
0x80713e: 50                               push   eax
0x80713f: 8d45f4                           lea    eax,[ebp-0xc]
0x807142: 64a300000000                     mov    fs:0x0,eax
0x807148: 33f6                             xor    esi,esi
0x80714a: 6a0c                             push   0xc
0x80714c: c745e85833fe00                   mov    DWORD PTR [ebp-0x18],0xfe3358
0x807153: 89355c33fe00                     mov    DWORD PTR ds:0xfe335c,esi
0x807159: e80aa10800                       call   0x891268
0x80715e: 83c404                           add    esp,0x4
0x807161: 3bc6                             cmp    eax,esi
0x807163: 0f84b1010000                     je     0x80731a
0x807169: a35833fe00                       mov    ds:0xfe3358,eax
0x80716e: 8900                             mov    DWORD PTR [eax],eax
0x807170: a15833fe00                       mov    eax,ds:0xfe3358
0x807175: 894004                           mov    DWORD PTR [eax+0x4],eax
0x807178: 8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x80717b: 6a08                             push   0x8
0x80717d: 89356433fe00                     mov    DWORD PTR ds:0xfe3364,esi
0x807183: e8e0a00800                       call   0x891268
0x807188: 83c404                           add    esp,0x4
0x80718b: 3bc6                             cmp    eax,esi
0x80718d: 0f8463010000                     je     0x8072f6
0x807193: a36433fe00                       mov    ds:0xfe3364,eax
0x807198: 33c9                             xor    ecx,ecx
0x80719a: 8908                             mov    DWORD PTR [eax],ecx
0x80719c: 33d2                             xor    edx,edx
0x80719e: 895004                           mov    DWORD PTR [eax+0x4],edx
0x8071a1: a16433fe00                       mov    eax,ds:0xfe3364
0x8071a6: c7006433fe00                     mov    DWORD PTR [eax],0xfe3364
0x8071ac: 89356833fe00                     mov    DWORD PTR ds:0xfe3368,esi
0x8071b2: 89356c33fe00                     mov    DWORD PTR ds:0xfe336c,esi
0x8071b8: 89357033fe00                     mov    DWORD PTR ds:0xfe3370,esi
0x8071be: 89357433fe00                     mov    DWORD PTR ds:0xfe3374,esi
0x8071c4: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x8071c8: 6a18                             push   0x18
0x8071ca: 89357c33fe00                     mov    DWORD PTR ds:0xfe337c,esi
0x8071d0: e893a00800                       call   0x891268
0x8071d5: 8b1d2c22bd00                     mov    ebx,DWORD PTR ds:0xbd222c
0x8071db: 8bf8                             mov    edi,eax
0x8071dd: 83c404                           add    esp,0x4
0x8071e0: 3bfe                             cmp    edi,esi
0x8071e2: 740a                             je     0x8071ee
0x8071e4: 68a00f0000                       push   0xfa0
0x8071e9: 57                               push   edi
0x8071ea: ffd3                             call   ebx
0x8071ec: eb02                             jmp    0x8071f0
0x8071ee: 33ff                             xor    edi,edi
0x8071f0: 6a0c                             push   0xc
0x8071f2: 893d8033fe00                     mov    DWORD PTR ds:0xfe3380,edi
0x8071f8: 89358433fe00                     mov    DWORD PTR ds:0xfe3384,esi
0x8071fe: 89358c33fe00                     mov    DWORD PTR ds:0xfe338c,esi
0x807204: e85fa00800                       call   0x891268
0x807209: 83c404                           add    esp,0x4
0x80720c: 3bc6                             cmp    eax,esi
0x80720e: 0f84be000000                     je     0x8072d2
0x807214: a38833fe00                       mov    ds:0xfe3388,eax
0x807219: 8900                             mov    DWORD PTR [eax],eax
0x80721b: a18833fe00                       mov    eax,ds:0xfe3388
0x807220: 894004                           mov    DWORD PTR [eax+0x4],eax
0x807223: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x807227: 6a08                             push   0x8
0x807229: 89359433fe00                     mov    DWORD PTR ds:0xfe3394,esi
0x80722f: e834a00800                       call   0x891268
0x807234: 83c404                           add    esp,0x4
0x807237: 3bc6                             cmp    eax,esi
0x807239: 7473                             je     0x8072ae
0x80723b: a39433fe00                       mov    ds:0xfe3394,eax
0x807240: 33c9                             xor    ecx,ecx
0x807242: 8908                             mov    DWORD PTR [eax],ecx
0x807244: 33d2                             xor    edx,edx
0x807246: 895004                           mov    DWORD PTR [eax+0x4],edx
0x807249: 8b0d9433fe00                     mov    ecx,DWORD PTR ds:0xfe3394
0x80724f: c7019433fe00                     mov    DWORD PTR [ecx],0xfe3394
0x807255: 89359833fe00                     mov    DWORD PTR ds:0xfe3398,esi
0x80725b: 89359c33fe00                     mov    DWORD PTR ds:0xfe339c,esi
0x807261: 8935a033fe00                     mov    DWORD PTR ds:0xfe33a0,esi
0x807267: 8935a433fe00                     mov    DWORD PTR ds:0xfe33a4,esi
0x80726d: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x807271: 6a18                             push   0x18
0x807273: 8935ac33fe00                     mov    DWORD PTR ds:0xfe33ac,esi
0x807279: e8ea9f0800                       call   0x891268
0x80727e: 8bf8                             mov    edi,eax
0x807280: 83c404                           add    esp,0x4
0x807283: 3bfe                             cmp    edi,esi
0x807285: 740a                             je     0x807291
0x807287: 68a00f0000                       push   0xfa0
0x80728c: 57                               push   edi
0x80728d: ffd3                             call   ebx
0x80728f: 8bf7                             mov    esi,edi
0x807291: 8935b033fe00                     mov    DWORD PTR ds:0xfe33b0,esi
0x807297: b85833fe00                       mov    eax,0xfe3358
0x80729c: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x80729f: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x8072a6: 59                               pop    ecx
0x8072a7: 5f                               pop    edi
0x8072a8: 5e                               pop    esi
0x8072a9: 5b                               pop    ebx
0x8072aa: 8be5                             mov    esp,ebp
0x8072ac: 5d                               pop    ebp
0x8072ad: c3                               ret
0x8072ae: 8d55f0                           lea    edx,[ebp-0x10]
0x8072b1: 52                               push   edx
0x8072b2: 8d4ddc                           lea    ecx,[ebp-0x24]
0x8072b5: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x8072b8: e8ec9d0800                       call   0x8910a9
0x8072bd: 68a857c800                       push   0xc857a8
0x8072c2: 8d45dc                           lea    eax,[ebp-0x24]
0x8072c5: 50                               push   eax
0x8072c6: c745dca42cbd00                   mov    DWORD PTR [ebp-0x24],0xbd2ca4
0x8072cd: e81e570900                       call   0x89c9f0
0x8072d2: 8d4dec                           lea    ecx,[ebp-0x14]
0x8072d5: 51                               push   ecx
0x8072d6: 8d4dd0                           lea    ecx,[ebp-0x30]
0x8072d9: 8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x8072dc: e8c89d0800                       call   0x8910a9
0x8072e1: 68a857c800                       push   0xc857a8
0x8072e6: 8d55d0                           lea    edx,[ebp-0x30]
0x8072e9: 52                               push   edx
0x8072ea: c745d0a42cbd00                   mov    DWORD PTR [ebp-0x30],0xbd2ca4
0x8072f1: e8fa560900                       call   0x89c9f0
0x8072f6: 8d45f0                           lea    eax,[ebp-0x10]
0x8072f9: 50                               push   eax
0x8072fa: 8d4ddc                           lea    ecx,[ebp-0x24]
0x8072fd: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x807300: e8a49d0800                       call   0x8910a9
0x807305: 68a857c800                       push   0xc857a8
0x80730a: 8d4ddc                           lea    ecx,[ebp-0x24]
0x80730d: 51                               push   ecx
0x80730e: c745dca42cbd00                   mov    DWORD PTR [ebp-0x24],0xbd2ca4
0x807315: e8d6560900                       call   0x89c9f0
0x80731a: 8d55ec                           lea    edx,[ebp-0x14]
0x80731d: 52                               push   edx
0x80731e: 8d4dd0                           lea    ecx,[ebp-0x30]
0x807321: 8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x807324: e8809d0800                       call   0x8910a9
0x807329: 68a857c800                       push   0xc857a8
0x80732e: 8d45d0                           lea    eax,[ebp-0x30]
0x807331: 50                               push   eax
0x807332: c745d0a42cbd00                   mov    DWORD PTR [ebp-0x30],0xbd2ca4
0x807339: e8b2560900                       call   0x89c9f0

## F-402A70 VA 0x402a70..0x402b65 raw 0x1e70 len 245 SHA256 bc46338969aaa8231f4cc88ebba53847ade071972dab891ec1f61c1ba237b4a3
0x402a70: 55                               push   ebp
0x402a71: 8bec                             mov    ebp,esp
0x402a73: 53                               push   ebx
0x402a74: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x402a77: 56                               push   esi
0x402a78: 8bf1                             mov    esi,ecx
0x402a7a: 85db                             test   ebx,ebx
0x402a7c: 7459                             je     0x402ad7
0x402a7e: 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x402a81: 83f910                           cmp    ecx,0x10
0x402a84: 7204                             jb     0x402a8a
0x402a86: 8b06                             mov    eax,DWORD PTR [esi]
0x402a88: eb02                             jmp    0x402a8c
0x402a8a: 8bc6                             mov    eax,esi
0x402a8c: 3bd8                             cmp    ebx,eax
0x402a8e: 7247                             jb     0x402ad7
0x402a90: 83f910                           cmp    ecx,0x10
0x402a93: 7204                             jb     0x402a99
0x402a95: 8b06                             mov    eax,DWORD PTR [esi]
0x402a97: eb02                             jmp    0x402a9b
0x402a99: 8bc6                             mov    eax,esi
0x402a9b: 8b5610                           mov    edx,DWORD PTR [esi+0x10]
0x402a9e: 03d0                             add    edx,eax
0x402aa0: 3bd3                             cmp    edx,ebx
0x402aa2: 7633                             jbe    0x402ad7
0x402aa4: 83f910                           cmp    ecx,0x10
0x402aa7: 7217                             jb     0x402ac0
0x402aa9: 8b06                             mov    eax,DWORD PTR [esi]
0x402aab: 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x402aae: 51                               push   ecx
0x402aaf: 2bd8                             sub    ebx,eax
0x402ab1: 53                               push   ebx
0x402ab2: 56                               push   esi
0x402ab3: 8bce                             mov    ecx,esi
0x402ab5: e886050000                       call   0x403040
0x402aba: 5e                               pop    esi
0x402abb: 5b                               pop    ebx
0x402abc: 5d                               pop    ebp
0x402abd: c20800                           ret    0x8
0x402ac0: 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x402ac3: 8bc6                             mov    eax,esi
0x402ac5: 51                               push   ecx
0x402ac6: 2bd8                             sub    ebx,eax
0x402ac8: 53                               push   ebx
0x402ac9: 56                               push   esi
0x402aca: 8bce                             mov    ecx,esi
0x402acc: e86f050000                       call   0x403040
0x402ad1: 5e                               pop    esi
0x402ad2: 5b                               pop    ebx
0x402ad3: 5d                               pop    ebp
0x402ad4: c20800                           ret    0x8
0x402ad7: 57                               push   edi
0x402ad8: 8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
0x402adb: 83fffe                           cmp    edi,0xfffffffe
0x402ade: 760a                             jbe    0x402aea
0x402ae0: 6800d2be00                       push   0xbed200
0x402ae5: e846b04700                       call   0x87db30
0x402aea: 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x402aed: 3bc7                             cmp    eax,edi
0x402aef: 731a                             jae    0x402b0b
0x402af1: 8b5610                           mov    edx,DWORD PTR [esi+0x10]
0x402af4: 52                               push   edx
0x402af5: 57                               push   edi
0x402af6: 8bce                             mov    ecx,esi
0x402af8: e8c3020000                       call   0x402dc0
0x402afd: 85ff                             test   edi,edi
0x402aff: 745b                             je     0x402b5c
0x402b01: 837e1410                         cmp    DWORD PTR [esi+0x14],0x10
0x402b05: 722a                             jb     0x402b31
0x402b07: 8b06                             mov    eax,DWORD PTR [esi]
0x402b09: eb28                             jmp    0x402b33
0x402b0b: 85ff                             test   edi,edi
0x402b0d: 75f2                             jne    0x402b01
0x402b0f: 897e10                           mov    DWORD PTR [esi+0x10],edi
0x402b12: 83f810                           cmp    eax,0x10
0x402b15: 720e                             jb     0x402b25
0x402b17: 8b06                             mov    eax,DWORD PTR [esi]
0x402b19: 5f                               pop    edi
0x402b1a: c60000                           mov    BYTE PTR [eax],0x0
0x402b1d: 8bc6                             mov    eax,esi
0x402b1f: 5e                               pop    esi
0x402b20: 5b                               pop    ebx
0x402b21: 5d                               pop    ebp
0x402b22: c20800                           ret    0x8
0x402b25: 5f                               pop    edi
0x402b26: 8bc6                             mov    eax,esi
0x402b28: 5e                               pop    esi
0x402b29: c60000                           mov    BYTE PTR [eax],0x0
0x402b2c: 5b                               pop    ebx
0x402b2d: 5d                               pop    ebp
0x402b2e: c20800                           ret    0x8
0x402b31: 8bc6                             mov    eax,esi
0x402b33: 57                               push   edi
0x402b34: 53                               push   ebx
0x402b35: 50                               push   eax
0x402b36: e895b04900                       call   0x89dbd0
0x402b3b: 83c40c                           add    esp,0xc
0x402b3e: 837e1410                         cmp    DWORD PTR [esi+0x14],0x10
0x402b42: 897e10                           mov    DWORD PTR [esi+0x10],edi
0x402b45: 720f                             jb     0x402b56
0x402b47: 8b06                             mov    eax,DWORD PTR [esi]
0x402b49: c6043800                         mov    BYTE PTR [eax+edi*1],0x0
0x402b4d: 5f                               pop    edi
0x402b4e: 8bc6                             mov    eax,esi
0x402b50: 5e                               pop    esi
0x402b51: 5b                               pop    ebx
0x402b52: 5d                               pop    ebp
0x402b53: c20800                           ret    0x8
0x402b56: 8bc6                             mov    eax,esi
0x402b58: c6043800                         mov    BYTE PTR [eax+edi*1],0x0
0x402b5c: 5f                               pop    edi
0x402b5d: 8bc6                             mov    eax,esi
0x402b5f: 5e                               pop    esi
0x402b60: 5b                               pop    ebx
0x402b61: 5d                               pop    ebp
0x402b62: c20800                           ret    0x8

## F-403040 VA 0x403040..0x403126 raw 0x2440 len 230 SHA256 1622245483c6c33ece97d67ba382df15945876187d4e9e51e5c364390fd05325
0x403040: 55                               push   ebp
0x403041: 8bec                             mov    ebp,esp
0x403043: 53                               push   ebx
0x403044: 8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
0x403047: 56                               push   esi
0x403048: 8bf1                             mov    esi,ecx
0x40304a: 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x40304d: 57                               push   edi
0x40304e: 8b7910                           mov    edi,DWORD PTR [ecx+0x10]
0x403051: 3bfb                             cmp    edi,ebx
0x403053: 730a                             jae    0x40305f
0x403055: 6810d2be00                       push   0xbed210
0x40305a: e81eab4700                       call   0x87db7d
0x40305f: 8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x403062: 2bfb                             sub    edi,ebx
0x403064: 3bc7                             cmp    eax,edi
0x403066: 0f42f8                           cmovb  edi,eax
0x403069: 3bf1                             cmp    esi,ecx
0x40306b: 751f                             jne    0x40308c
0x40306d: 6aff                             push   0xffffffff
0x40306f: 03fb                             add    edi,ebx
0x403071: 57                               push   edi
0x403072: 8bce                             mov    ecx,esi
0x403074: e807fcffff                       call   0x402c80
0x403079: 53                               push   ebx
0x40307a: 6a00                             push   0x0
0x40307c: 8bce                             mov    ecx,esi
0x40307e: e8fdfbffff                       call   0x402c80
0x403083: 5f                               pop    edi
0x403084: 8bc6                             mov    eax,esi
0x403086: 5e                               pop    esi
0x403087: 5b                               pop    ebx
0x403088: 5d                               pop    ebp
0x403089: c20c00                           ret    0xc
0x40308c: 83fffe                           cmp    edi,0xfffffffe
0x40308f: 760a                             jbe    0x40309b
0x403091: 6800d2be00                       push   0xbed200
0x403096: e895aa4700                       call   0x87db30
0x40309b: 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x40309e: 3bc7                             cmp    eax,edi
0x4030a0: 7328                             jae    0x4030ca
0x4030a2: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x4030a5: 50                               push   eax
0x4030a6: 57                               push   edi
0x4030a7: 8bce                             mov    ecx,esi
0x4030a9: e812fdffff                       call   0x402dc0
0x4030ae: 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4030b1: 85ff                             test   edi,edi
0x4030b3: 7468                             je     0x40311d
0x4030b5: b810000000                       mov    eax,0x10
0x4030ba: 394114                           cmp    DWORD PTR [ecx+0x14],eax
0x4030bd: 7202                             jb     0x4030c1
0x4030bf: 8b09                             mov    ecx,DWORD PTR [ecx]
0x4030c1: 394614                           cmp    DWORD PTR [esi+0x14],eax
0x4030c4: 722a                             jb     0x4030f0
0x4030c6: 8b06                             mov    eax,DWORD PTR [esi]
0x4030c8: eb28                             jmp    0x4030f2
0x4030ca: 85ff                             test   edi,edi
0x4030cc: 75e7                             jne    0x4030b5
0x4030ce: 897e10                           mov    DWORD PTR [esi+0x10],edi
0x4030d1: 83f810                           cmp    eax,0x10
0x4030d4: 720e                             jb     0x4030e4
0x4030d6: 8b06                             mov    eax,DWORD PTR [esi]
0x4030d8: 5f                               pop    edi
0x4030d9: c60000                           mov    BYTE PTR [eax],0x0
0x4030dc: 8bc6                             mov    eax,esi
0x4030de: 5e                               pop    esi
0x4030df: 5b                               pop    ebx
0x4030e0: 5d                               pop    ebp
0x4030e1: c20c00                           ret    0xc
0x4030e4: 5f                               pop    edi
0x4030e5: 8bc6                             mov    eax,esi
0x4030e7: 5e                               pop    esi
0x4030e8: c60000                           mov    BYTE PTR [eax],0x0
0x4030eb: 5b                               pop    ebx
0x4030ec: 5d                               pop    ebp
0x4030ed: c20c00                           ret    0xc
0x4030f0: 8bc6                             mov    eax,esi
0x4030f2: 57                               push   edi
0x4030f3: 03cb                             add    ecx,ebx
0x4030f5: 51                               push   ecx
0x4030f6: 50                               push   eax
0x4030f7: e8d4aa4900                       call   0x89dbd0
0x4030fc: 83c40c                           add    esp,0xc
0x4030ff: 837e1410                         cmp    DWORD PTR [esi+0x14],0x10
0x403103: 897e10                           mov    DWORD PTR [esi+0x10],edi
0x403106: 720f                             jb     0x403117
0x403108: 8b06                             mov    eax,DWORD PTR [esi]
0x40310a: c6043800                         mov    BYTE PTR [eax+edi*1],0x0
0x40310e: 5f                               pop    edi
0x40310f: 8bc6                             mov    eax,esi
0x403111: 5e                               pop    esi
0x403112: 5b                               pop    ebx
0x403113: 5d                               pop    ebp
0x403114: c20c00                           ret    0xc
0x403117: 8bc6                             mov    eax,esi
0x403119: c6043800                         mov    BYTE PTR [eax+edi*1],0x0
0x40311d: 5f                               pop    edi
0x40311e: 8bc6                             mov    eax,esi
0x403120: 5e                               pop    esi
0x403121: 5b                               pop    ebx
0x403122: 5d                               pop    ebp
0x403123: c20c00                           ret    0xc

## F-54F850 VA 0x54f850..0x55022d raw 0x14ec50 len 2525 SHA256 1cedb3489c741044a8ef0e58394586b9145555b545688d479f8a5566308ed334
0x54f850: 55                               push   ebp
0x54f851: 8bec                             mov    ebp,esp
0x54f853: 6aff                             push   0xffffffff
0x54f855: 68bf629000                       push   0x9062bf
0x54f85a: 64a100000000                     mov    eax,fs:0x0
0x54f860: 50                               push   eax
0x54f861: 83ec08                           sub    esp,0x8
0x54f864: 53                               push   ebx
0x54f865: 56                               push   esi
0x54f866: 57                               push   edi
0x54f867: a1201fd600                       mov    eax,ds:0xd61f20
0x54f86c: 33c5                             xor    eax,ebp
0x54f86e: 50                               push   eax
0x54f86f: 8d45f4                           lea    eax,[ebp-0xc]
0x54f872: 64a300000000                     mov    fs:0x0,eax
0x54f878: 33db                             xor    ebx,ebx
0x54f87a: c745ec5090fb00                   mov    DWORD PTR [ebp-0x14],0xfb9050
0x54f881: 891d5490fb00                     mov    DWORD PTR ds:0xfb9054,ebx
0x54f887: 891d5890fb00                     mov    DWORD PTR ds:0xfb9058,ebx
0x54f88d: 891d5c90fb00                     mov    DWORD PTR ds:0xfb905c,ebx
0x54f893: 891d6090fb00                     mov    DWORD PTR ds:0xfb9060,ebx
0x54f899: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x54f89c: b9b0fdc000                       mov    ecx,0xc0fdb0
0x54f8a1: c7055090fb00d0fdc000             mov    DWORD PTR ds:0xfb9050,0xc0fdd0
0x54f8ab: 890d6890fb00                     mov    DWORD PTR ds:0xfb9068,ecx
0x54f8b1: 891d6c90fb00                     mov    DWORD PTR ds:0xfb906c,ebx
0x54f8b7: f30f1005207dc000                 movss  xmm0,DWORD PTR ds:0xc07d20
0x54f8bf: b8c0fdc000                       mov    eax,0xc0fdc0
0x54f8c4: a37090fb00                       mov    ds:0xfb9070,eax
0x54f8c9: f30f11057490fb00                 movss  DWORD PTR ds:0xfb9074,xmm0
0x54f8d1: f30f1005405ac500                 movss  xmm0,DWORD PTR ds:0xc55a40
0x54f8d9: a37890fb00                       mov    ds:0xfb9078,eax
0x54f8de: f30f11057c90fb00                 movss  DWORD PTR ds:0xfb907c,xmm0
0x54f8e6: f30f10053c5ac500                 movss  xmm0,DWORD PTR ds:0xc55a3c
0x54f8ee: a38090fb00                       mov    ds:0xfb9080,eax
0x54f8f3: f30f11058490fb00                 movss  DWORD PTR ds:0xfb9084,xmm0
0x54f8fb: f30f101d0c7dc000                 movss  xmm3,DWORD PTR ds:0xc07d0c
0x54f903: a38890fb00                       mov    ds:0xfb9088,eax
0x54f908: f30f111d8c90fb00                 movss  DWORD PTR ds:0xfb908c,xmm3
0x54f910: f30f1005385ac500                 movss  xmm0,DWORD PTR ds:0xc55a38
0x54f918: a39090fb00                       mov    ds:0xfb9090,eax
0x54f91d: f30f11059490fb00                 movss  DWORD PTR ds:0xfb9094,xmm0
0x54f925: f30f1005f8c7c000                 movss  xmm0,DWORD PTR ds:0xc0c7f8
0x54f92d: a39890fb00                       mov    ds:0xfb9098,eax
0x54f932: f30f11059c90fb00                 movss  DWORD PTR ds:0xfb909c,xmm0
0x54f93a: f30f1005345ac500                 movss  xmm0,DWORD PTR ds:0xc55a34
0x54f942: a3a090fb00                       mov    ds:0xfb90a0,eax
0x54f947: f30f1105a490fb00                 movss  DWORD PTR ds:0xfb90a4,xmm0
0x54f94f: f30f1005d058c500                 movss  xmm0,DWORD PTR ds:0xc558d0
0x54f957: a3a890fb00                       mov    ds:0xfb90a8,eax
0x54f95c: f30f1105ac90fb00                 movss  DWORD PTR ds:0xfb90ac,xmm0
0x54f964: f30f1005305ac500                 movss  xmm0,DWORD PTR ds:0xc55a30
0x54f96c: a3b090fb00                       mov    ds:0xfb90b0,eax
0x54f971: f30f1105b490fb00                 movss  DWORD PTR ds:0xfb90b4,xmm0
0x54f979: f30f100510c8c000                 movss  xmm0,DWORD PTR ds:0xc0c810
0x54f981: a3b890fb00                       mov    ds:0xfb90b8,eax
0x54f986: f30f1105bc90fb00                 movss  DWORD PTR ds:0xfb90bc,xmm0
0x54f98e: 890dc090fb00                     mov    DWORD PTR ds:0xfb90c0,ecx
0x54f994: c705c490fb0000020000             mov    DWORD PTR ds:0xfb90c4,0x200
0x54f99e: b9a0fdc000                       mov    ecx,0xc0fda0
0x54f9a3: 890dc890fb00                     mov    DWORD PTR ds:0xfb90c8,ecx
0x54f9a9: c705cc90fb00e8030000             mov    DWORD PTR ds:0xfb90cc,0x3e8
0x54f9b3: c705d090fb00000000ff             mov    DWORD PTR ds:0xfb90d0,0xff000000
0x54f9bd: b801000000                       mov    eax,0x1
0x54f9c2: 890dd490fb00                     mov    DWORD PTR ds:0xfb90d4,ecx
0x54f9c8: a3d890fb00                       mov    ds:0xfb90d8,eax
0x54f9cd: 8d5302                           lea    edx,[ebx+0x2]
0x54f9d0: c705dc90fb0000000002             mov    DWORD PTR ds:0xfb90dc,0x2000000
0x54f9da: bed6060000                       mov    esi,0x6d6
0x54f9df: 668935e890fb00                   mov    WORD PTR ds:0xfb90e8,si
0x54f9e6: 668935ea90fb00                   mov    WORD PTR ds:0xfb90ea,si
0x54f9ed: 33f6                             xor    esi,esi
0x54f9ef: 668935ec90fb00                   mov    WORD PTR ds:0xfb90ec,si
0x54f9f6: be581b0000                       mov    esi,0x1b58
0x54f9fb: c705e090fb0090fdc000             mov    DWORD PTR ds:0xfb90e0,0xc0fd90
0x54fa05: a3e490fb00                       mov    ds:0xfb90e4,eax
0x54fa0a: 668935ee90fb00                   mov    WORD PTR ds:0xfb90ee,si
0x54fa11: 890df090fb00                     mov    DWORD PTR ds:0xfb90f0,ecx
0x54fa17: a3f490fb00                       mov    ds:0xfb90f4,eax
0x54fa1c: c705f890fb0000000001             mov    DWORD PTR ds:0xfb90f8,0x1000000
0x54fa26: 890dfc90fb00                     mov    DWORD PTR ds:0xfb90fc,ecx
0x54fa2c: a30091fb00                       mov    ds:0xfb9100,eax
0x54fa31: c7050491fb0000000001             mov    DWORD PTR ds:0xfb9104,0x1000000
0x54fa3b: 890d0891fb00                     mov    DWORD PTR ds:0xfb9108,ecx
0x54fa41: a30c91fb00                       mov    ds:0xfb910c,eax
0x54fa46: c7051091fb0000000001             mov    DWORD PTR ds:0xfb9110,0x1000000
0x54fa50: 890d1491fb00                     mov    DWORD PTR ds:0xfb9114,ecx
0x54fa56: 89151891fb00                     mov    DWORD PTR ds:0xfb9118,edx
0x54fa5c: c7051c91fb0001010001             mov    DWORD PTR ds:0xfb911c,0x1000101
0x54fa66: 890d2091fb00                     mov    DWORD PTR ds:0xfb9120,ecx
0x54fa6c: 89152491fb00                     mov    DWORD PTR ds:0xfb9124,edx
0x54fa72: c7052891fb0000000001             mov    DWORD PTR ds:0xfb9128,0x1000000
0x54fa7c: 890d2c91fb00                     mov    DWORD PTR ds:0xfb912c,ecx
0x54fa82: 89153091fb00                     mov    DWORD PTR ds:0xfb9130,edx
0x54fa88: c7053491fb0000000001             mov    DWORD PTR ds:0xfb9134,0x1000000
0x54fa92: bf1e000000                       mov    edi,0x1e
0x54fa97: c7053891fb0070fdc000             mov    DWORD PTR ds:0xfb9138,0xc0fd70
0x54faa1: 89153c91fb00                     mov    DWORD PTR ds:0xfb913c,edx
0x54faa7: 893d4091fb00                     mov    DWORD PTR ds:0xfb9140,edi
0x54faad: 893d4491fb00                     mov    DWORD PTR ds:0xfb9144,edi
0x54fab3: 891d4891fb00                     mov    DWORD PTR ds:0xfb9148,ebx
0x54fab9: c7054c91fb005a000000             mov    DWORD PTR ds:0xfb914c,0x5a
0x54fac3: f30f10152c5ac500                 movss  xmm2,DWORD PTR ds:0xc55a2c
0x54facb: f30f10057059c500                 movss  xmm0,DWORD PTR ds:0xc55970
0x54fad3: f30f100d7457c500                 movss  xmm1,DWORD PTR ds:0xc55774
0x54fadb: be80fdc000                       mov    esi,0xc0fd80
0x54fae0: 89355091fb00                     mov    DWORD PTR ds:0xfb9150,esi
0x54fae6: 89155491fb00                     mov    DWORD PTR ds:0xfb9154,edx
0x54faec: f30f11155891fb00                 movss  DWORD PTR ds:0xfb9158,xmm2
0x54faf4: f30f11155c91fb00                 movss  DWORD PTR ds:0xfb915c,xmm2
0x54fafc: f30f11056091fb00                 movss  DWORD PTR ds:0xfb9160,xmm0
0x54fb04: f30f110d6491fb00                 movss  DWORD PTR ds:0xfb9164,xmm1
0x54fb0c: f30f1025285ac500                 movss  xmm4,DWORD PTR ds:0xc55a28
0x54fb14: 0f57c9                           xorps  xmm1,xmm1
0x54fb17: 89356891fb00                     mov    DWORD PTR ds:0xfb9168,esi
0x54fb1d: 89156c91fb00                     mov    DWORD PTR ds:0xfb916c,edx
0x54fb23: f30f11257091fb00                 movss  DWORD PTR ds:0xfb9170,xmm4
0x54fb2b: f30f11257491fb00                 movss  DWORD PTR ds:0xfb9174,xmm4
0x54fb33: f30f110d7891fb00                 movss  DWORD PTR ds:0xfb9178,xmm1
0x54fb3b: f30f11057c91fb00                 movss  DWORD PTR ds:0xfb917c,xmm0
0x54fb43: c7058091fb0070fdc000             mov    DWORD PTR ds:0xfb9180,0xc0fd70
0x54fb4d: 89158491fb00                     mov    DWORD PTR ds:0xfb9184,edx
0x54fb53: 893d8891fb00                     mov    DWORD PTR ds:0xfb9188,edi
0x54fb59: 893d8c91fb00                     mov    DWORD PTR ds:0xfb918c,edi
0x54fb5f: 891d9091fb00                     mov    DWORD PTR ds:0xfb9190,ebx
0x54fb65: c7059491fb005a000000             mov    DWORD PTR ds:0xfb9194,0x5a
0x54fb6f: f30f10059059c500                 movss  xmm0,DWORD PTR ds:0xc55990
0x54fb77: f30f1105a891fb00                 movss  DWORD PTR ds:0xfb91a8,xmm0
0x54fb7f: f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x54fb87: 89359891fb00                     mov    DWORD PTR ds:0xfb9198,esi
0x54fb8d: 89159c91fb00                     mov    DWORD PTR ds:0xfb919c,edx
0x54fb93: f30f1115a091fb00                 movss  DWORD PTR ds:0xfb91a0,xmm2
0x54fb9b: f30f1115a491fb00                 movss  DWORD PTR ds:0xfb91a4,xmm2
0x54fba3: f30f1105ac91fb00                 movss  DWORD PTR ds:0xfb91ac,xmm0
0x54fbab: f30f1125b891fb00                 movss  DWORD PTR ds:0xfb91b8,xmm4
0x54fbb3: f30f1125bc91fb00                 movss  DWORD PTR ds:0xfb91bc,xmm4
0x54fbbb: f30f1025245ac500                 movss  xmm4,DWORD PTR ds:0xc55a24
0x54fbc3: 8935b091fb00                     mov    DWORD PTR ds:0xfb91b0,esi
0x54fbc9: 8915b491fb00                     mov    DWORD PTR ds:0xfb91b4,edx
0x54fbcf: f30f110dc091fb00                 movss  DWORD PTR ds:0xfb91c0,xmm1
0x54fbd7: f30f1125c491fb00                 movss  DWORD PTR ds:0xfb91c4,xmm4
0x54fbdf: 890dc891fb00                     mov    DWORD PTR ds:0xfb91c8,ecx
0x54fbe5: 8915cc91fb00                     mov    DWORD PTR ds:0xfb91cc,edx
0x54fbeb: c705d091fb0000000001             mov    DWORD PTR ds:0xfb91d0,0x1000000
0x54fbf5: 890dd491fb00                     mov    DWORD PTR ds:0xfb91d4,ecx
0x54fbfb: 8915d891fb00                     mov    DWORD PTR ds:0xfb91d8,edx
0x54fc01: c705dc91fb0000000001             mov    DWORD PTR ds:0xfb91dc,0x1000000
0x54fc0b: bf03000000                       mov    edi,0x3
0x54fc10: 890de091fb00                     mov    DWORD PTR ds:0xfb91e0,ecx
0x54fc16: 893de491fb00                     mov    DWORD PTR ds:0xfb91e4,edi
0x54fc1c: c705e891fb0000000002             mov    DWORD PTR ds:0xfb91e8,0x2000000
0x54fc26: 8935ec91fb00                     mov    DWORD PTR ds:0xfb91ec,esi
0x54fc2c: 893df091fb00                     mov    DWORD PTR ds:0xfb91f0,edi
0x54fc32: f30f1115f491fb00                 movss  DWORD PTR ds:0xfb91f4,xmm2
0x54fc3a: f30f1115f891fb00                 movss  DWORD PTR ds:0xfb91f8,xmm2
0x54fc42: f30f110dfc91fb00                 movss  DWORD PTR ds:0xfb91fc,xmm1
0x54fc4a: f30f11050092fb00                 movss  DWORD PTR ds:0xfb9200,xmm0
0x54fc52: 89350492fb00                     mov    DWORD PTR ds:0xfb9204,esi
0x54fc58: 893d0892fb00                     mov    DWORD PTR ds:0xfb9208,edi
0x54fc5e: f30f111d0c92fb00                 movss  DWORD PTR ds:0xfb920c,xmm3
0x54fc66: f30f111d1092fb00                 movss  DWORD PTR ds:0xfb9210,xmm3
0x54fc6e: f30f110d1492fb00                 movss  DWORD PTR ds:0xfb9214,xmm1
0x54fc76: f30f11051892fb00                 movss  DWORD PTR ds:0xfb9218,xmm0
0x54fc7e: 890d1c92fb00                     mov    DWORD PTR ds:0xfb921c,ecx
0x54fc84: c7052092fb0004000000             mov    DWORD PTR ds:0xfb9220,0x4
0x54fc8e: c7052492fb0000000001             mov    DWORD PTR ds:0xfb9224,0x1000000
0x54fc98: bf05000000                       mov    edi,0x5
0x54fc9d: 89352892fb00                     mov    DWORD PTR ds:0xfb9228,esi
0x54fca3: 893d2c92fb00                     mov    DWORD PTR ds:0xfb922c,edi
0x54fca9: f30f11153092fb00                 movss  DWORD PTR ds:0xfb9230,xmm2
0x54fcb1: f30f11153492fb00                 movss  DWORD PTR ds:0xfb9234,xmm2
0x54fcb9: f30f110d3892fb00                 movss  DWORD PTR ds:0xfb9238,xmm1
0x54fcc1: f30f11053c92fb00                 movss  DWORD PTR ds:0xfb923c,xmm0
0x54fcc9: 89354092fb00                     mov    DWORD PTR ds:0xfb9240,esi
0x54fccf: 893d4492fb00                     mov    DWORD PTR ds:0xfb9244,edi
0x54fcd5: f30f111d4892fb00                 movss  DWORD PTR ds:0xfb9248,xmm3
0x54fcdd: f30f111d4c92fb00                 movss  DWORD PTR ds:0xfb924c,xmm3
0x54fce5: f30f110d5092fb00                 movss  DWORD PTR ds:0xfb9250,xmm1
0x54fced: f30f11055492fb00                 movss  DWORD PTR ds:0xfb9254,xmm0
0x54fcf5: f30f1015205ac500                 movss  xmm2,DWORD PTR ds:0xc55a20
0x54fcfd: 89355892fb00                     mov    DWORD PTR ds:0xfb9258,esi
0x54fd03: 893d5c92fb00                     mov    DWORD PTR ds:0xfb925c,edi
0x54fd09: f30f11156092fb00                 movss  DWORD PTR ds:0xfb9260,xmm2
0x54fd11: f30f11156492fb00                 movss  DWORD PTR ds:0xfb9264,xmm2
0x54fd19: f30f110d6892fb00                 movss  DWORD PTR ds:0xfb9268,xmm1
0x54fd21: f30f11056c92fb00                 movss  DWORD PTR ds:0xfb926c,xmm0
0x54fd29: 89357092fb00                     mov    DWORD PTR ds:0xfb9270,esi
0x54fd2f: 893d7492fb00                     mov    DWORD PTR ds:0xfb9274,edi
0x54fd35: f30f111d7892fb00                 movss  DWORD PTR ds:0xfb9278,xmm3
0x54fd3d: f30f111d7c92fb00                 movss  DWORD PTR ds:0xfb927c,xmm3
0x54fd45: f30f110d8092fb00                 movss  DWORD PTR ds:0xfb9280,xmm1
0x54fd4d: f30f11058492fb00                 movss  DWORD PTR ds:0xfb9284,xmm0
0x54fd55: bfff3c0800                       mov    edi,0x83cff
0x54fd5a: c7058892fb0070fdc000             mov    DWORD PTR ds:0xfb9288,0xc0fd70
0x54fd64: c7058c92fb0006000000             mov    DWORD PTR ds:0xfb928c,0x6
0x54fd6e: 893d9092fb00                     mov    DWORD PTR ds:0xfb9290,edi
0x54fd74: 893d9492fb00                     mov    DWORD PTR ds:0xfb9294,edi
0x54fd7a: c7059892fb0000000080             mov    DWORD PTR ds:0xfb9298,0x80000000
0x54fd84: c7059c92fb00ffffff7f             mov    DWORD PTR ds:0xfb929c,0x7fffffff
0x54fd8e: 83cfff                           or     edi,0xffffffff
0x54fd91: 66893da892fb00                   mov    WORD PTR ds:0xfb92a8,di
0x54fd98: 0bff                             or     edi,edi
0x54fd9a: 66893daa92fb00                   mov    WORD PTR ds:0xfb92aa,di
0x54fda1: 83cfff                           or     edi,0xffffffff
0x54fda4: 66893dac92fb00                   mov    WORD PTR ds:0xfb92ac,di
0x54fdab: bfff7f0000                       mov    edi,0x7fff
0x54fdb0: c705a092fb0090fdc000             mov    DWORD PTR ds:0xfb92a0,0xc0fd90
0x54fdba: c705a492fb0006000000             mov    DWORD PTR ds:0xfb92a4,0x6
0x54fdc4: 66893dae92fb00                   mov    WORD PTR ds:0xfb92ae,di
0x54fdcb: 83cfff                           or     edi,0xffffffff
0x54fdce: 66893db892fb00                   mov    WORD PTR ds:0xfb92b8,di
0x54fdd5: 0bff                             or     edi,edi
0x54fdd7: 66893dba92fb00                   mov    WORD PTR ds:0xfb92ba,di
0x54fdde: 83cfff                           or     edi,0xffffffff
0x54fde1: 66893dbc92fb00                   mov    WORD PTR ds:0xfb92bc,di
0x54fde8: c705b092fb0090fdc000             mov    DWORD PTR ds:0xfb92b0,0xc0fd90
0x54fdf2: c705b492fb0006000000             mov    DWORD PTR ds:0xfb92b4,0x6
0x54fdfc: bfff7f0000                       mov    edi,0x7fff
0x54fe01: 66893dbe92fb00                   mov    WORD PTR ds:0xfb92be,di
0x54fe08: bf06000000                       mov    edi,0x6
0x54fe0d: 890dc092fb00                     mov    DWORD PTR ds:0xfb92c0,ecx
0x54fe13: 893dc492fb00                     mov    DWORD PTR ds:0xfb92c4,edi
0x54fe19: c705c892fb0020201020             mov    DWORD PTR ds:0xfb92c8,0x20102020
0x54fe23: 893dd092fb00                     mov    DWORD PTR ds:0xfb92d0,edi
0x54fe29: bfb80b0000                       mov    edi,0xbb8
0x54fe2e: 66893dd492fb00                   mov    WORD PTR ds:0xfb92d4,di
0x54fe35: 66893dd692fb00                   mov    WORD PTR ds:0xfb92d6,di
0x54fe3c: 33ff                             xor    edi,edi
0x54fe3e: 66893dd892fb00                   mov    WORD PTR ds:0xfb92d8,di
0x54fe45: bf581b0000                       mov    edi,0x1b58
0x54fe4a: c705cc92fb0090fdc000             mov    DWORD PTR ds:0xfb92cc,0xc0fd90
0x54fe54: 66893dda92fb00                   mov    WORD PTR ds:0xfb92da,di
0x54fe5b: 890ddc92fb00                     mov    DWORD PTR ds:0xfb92dc,ecx
0x54fe61: c705e092fb0007000000             mov    DWORD PTR ds:0xfb92e0,0x7
0x54fe6b: c705e492fb00030300ff             mov    DWORD PTR ds:0xfb92e4,0xff000303
0x54fe75: 890de892fb00                     mov    DWORD PTR ds:0xfb92e8,ecx
0x54fe7b: c705ec92fb0008000000             mov    DWORD PTR ds:0xfb92ec,0x8
0x54fe85: c705f092fb0000000001             mov    DWORD PTR ds:0xfb92f0,0x1000000
0x54fe8f: 890df492fb00                     mov    DWORD PTR ds:0xfb92f4,ecx
0x54fe95: c705f892fb0009000000             mov    DWORD PTR ds:0xfb92f8,0x9
0x54fe9f: c705fc92fb0000000001             mov    DWORD PTR ds:0xfb92fc,0x1000000
0x54fea9: 890d0093fb00                     mov    DWORD PTR ds:0xfb9300,ecx
0x54feaf: c7050493fb000a000000             mov    DWORD PTR ds:0xfb9304,0xa
0x54feb9: c7050893fb0000000002             mov    DWORD PTR ds:0xfb9308,0x2000000
0x54fec3: 33ff                             xor    edi,edi
0x54fec5: 66893d1493fb00                   mov    WORD PTR ds:0xfb9314,di
0x54fecc: 66893d1693fb00                   mov    WORD PTR ds:0xfb9316,di
0x54fed3: bf0080ffff                       mov    edi,0xffff8000
0x54fed8: 66893d1893fb00                   mov    WORD PTR ds:0xfb9318,di
0x54fedf: ba0b000000                       mov    edx,0xb
0x54fee4: bfff7f0000                       mov    edi,0x7fff
0x54fee9: c7050c93fb0090fdc000             mov    DWORD PTR ds:0xfb930c,0xc0fd90
0x54fef3: 89151093fb00                     mov    DWORD PTR ds:0xfb9310,edx
0x54fef9: 66893d1a93fb00                   mov    WORD PTR ds:0xfb931a,di
0x54ff00: 89152093fb00                     mov    DWORD PTR ds:0xfb9320,edx
0x54ff06: 33d2                             xor    edx,edx
0x54ff08: 6689152493fb00                   mov    WORD PTR ds:0xfb9324,dx
0x54ff0f: 6689152693fb00                   mov    WORD PTR ds:0xfb9326,dx
0x54ff16: ba0080ffff                       mov    edx,0xffff8000
0x54ff1b: 6689152893fb00                   mov    WORD PTR ds:0xfb9328,dx
0x54ff22: 8bd7                             mov    edx,edi
0x54ff24: c7051c93fb0090fdc000             mov    DWORD PTR ds:0xfb931c,0xc0fd90
0x54ff2e: 6689152a93fb00                   mov    WORD PTR ds:0xfb932a,dx
0x54ff35: ba0c000000                       mov    edx,0xc
0x54ff3a: 890d2c93fb00                     mov    DWORD PTR ds:0xfb932c,ecx
0x54ff40: 89153093fb00                     mov    DWORD PTR ds:0xfb9330,edx
0x54ff46: c7053493fb0001010001             mov    DWORD PTR ds:0xfb9334,0x1000101
0x54ff50: 890d3893fb00                     mov    DWORD PTR ds:0xfb9338,ecx
0x54ff56: 89153c93fb00                     mov    DWORD PTR ds:0xfb933c,edx
0x54ff5c: c7054093fb0001010001             mov    DWORD PTR ds:0xfb9340,0x1000101
0x54ff66: 890d4493fb00                     mov    DWORD PTR ds:0xfb9344,ecx
0x54ff6c: 89154893fb00                     mov    DWORD PTR ds:0xfb9348,edx
0x54ff72: c7054c93fb0001010001             mov    DWORD PTR ds:0xfb934c,0x1000101
0x54ff7c: 89355093fb00                     mov    DWORD PTR ds:0xfb9350,esi
0x54ff82: 89155493fb00                     mov    DWORD PTR ds:0xfb9354,edx
0x54ff88: f30f11055893fb00                 movss  DWORD PTR ds:0xfb9358,xmm0
0x54ff90: f30f11055c93fb00                 movss  DWORD PTR ds:0xfb935c,xmm0
0x54ff98: f30f110d6093fb00                 movss  DWORD PTR ds:0xfb9360,xmm1
0x54ffa0: f30f11056493fb00                 movss  DWORD PTR ds:0xfb9364,xmm0
0x54ffa8: c645fc34                         mov    BYTE PTR [ebp-0x4],0x34
0x54ffac: 8d45f0                           lea    eax,[ebp-0x10]
0x54ffaf: bf5890fb00                       mov    edi,0xfb9058
0x54ffb4: c745f0d490fb00                   mov    DWORD PTR [ebp-0x10],0xfb90d4
0x54ffbb: e8503defff                       call   0x443d10
0x54ffc0: c745f0e090fb00                   mov    DWORD PTR [ebp-0x10],0xfb90e0
0x54ffc7: 8d45f0                           lea    eax,[ebp-0x10]
0x54ffca: e8413defff                       call   0x443d10
0x54ffcf: 8d45f0                           lea    eax,[ebp-0x10]
0x54ffd2: c745f0f090fb00                   mov    DWORD PTR [ebp-0x10],0xfb90f0
0x54ffd9: e8323defff                       call   0x443d10
0x54ffde: 8d45f0                           lea    eax,[ebp-0x10]
0x54ffe1: c745f0fc90fb00                   mov    DWORD PTR [ebp-0x10],0xfb90fc
0x54ffe8: e8233defff                       call   0x443d10
0x54ffed: 8d45f0                           lea    eax,[ebp-0x10]
0x54fff0: c745f00891fb00                   mov    DWORD PTR [ebp-0x10],0xfb9108
0x54fff7: e8143defff                       call   0x443d10
0x54fffc: 8d45f0                           lea    eax,[ebp-0x10]
0x54ffff: c745f01491fb00                   mov    DWORD PTR [ebp-0x10],0xfb9114
0x550006: e8053defff                       call   0x443d10
0x55000b: 8d45f0                           lea    eax,[ebp-0x10]
0x55000e: c745f02091fb00                   mov    DWORD PTR [ebp-0x10],0xfb9120
0x550015: e8f63cefff                       call   0x443d10
0x55001a: 8d45f0                           lea    eax,[ebp-0x10]
0x55001d: c745f02c91fb00                   mov    DWORD PTR [ebp-0x10],0xfb912c
0x550024: e8e73cefff                       call   0x443d10
0x550029: 8d45f0                           lea    eax,[ebp-0x10]
0x55002c: c745f03891fb00                   mov    DWORD PTR [ebp-0x10],0xfb9138
0x550033: e8d83cefff                       call   0x443d10
0x550038: 8d45f0                           lea    eax,[ebp-0x10]
0x55003b: c745f05091fb00                   mov    DWORD PTR [ebp-0x10],0xfb9150
0x550042: e8c93cefff                       call   0x443d10
0x550047: 8d45f0                           lea    eax,[ebp-0x10]
0x55004a: c745f06891fb00                   mov    DWORD PTR [ebp-0x10],0xfb9168
0x550051: e8ba3cefff                       call   0x443d10
0x550056: 8d45f0                           lea    eax,[ebp-0x10]
0x550059: c745f08091fb00                   mov    DWORD PTR [ebp-0x10],0xfb9180
0x550060: e8ab3cefff                       call   0x443d10
0x550065: 8d45f0                           lea    eax,[ebp-0x10]
0x550068: c745f09891fb00                   mov    DWORD PTR [ebp-0x10],0xfb9198
0x55006f: e89c3cefff                       call   0x443d10
0x550074: 8d45f0                           lea    eax,[ebp-0x10]
0x550077: c745f0b091fb00                   mov    DWORD PTR [ebp-0x10],0xfb91b0
0x55007e: e88d3cefff                       call   0x443d10
0x550083: 8d45f0                           lea    eax,[ebp-0x10]
0x550086: c745f0c891fb00                   mov    DWORD PTR [ebp-0x10],0xfb91c8
0x55008d: e87e3cefff                       call   0x443d10
0x550092: 8d45f0                           lea    eax,[ebp-0x10]
0x550095: c745f0d491fb00                   mov    DWORD PTR [ebp-0x10],0xfb91d4
0x55009c: e86f3cefff                       call   0x443d10
0x5500a1: 8d45f0                           lea    eax,[ebp-0x10]
0x5500a4: c745f0e091fb00                   mov    DWORD PTR [ebp-0x10],0xfb91e0
0x5500ab: e8603cefff                       call   0x443d10
0x5500b0: 8d45f0                           lea    eax,[ebp-0x10]
0x5500b3: c745f0ec91fb00                   mov    DWORD PTR [ebp-0x10],0xfb91ec
0x5500ba: e8513cefff                       call   0x443d10
0x5500bf: 8d45f0                           lea    eax,[ebp-0x10]
0x5500c2: c745f00492fb00                   mov    DWORD PTR [ebp-0x10],0xfb9204
0x5500c9: e8423cefff                       call   0x443d10
0x5500ce: 8d45f0                           lea    eax,[ebp-0x10]
0x5500d1: c745f01c92fb00                   mov    DWORD PTR [ebp-0x10],0xfb921c
0x5500d8: e8333cefff                       call   0x443d10
0x5500dd: 8d45f0                           lea    eax,[ebp-0x10]
0x5500e0: c745f02892fb00                   mov    DWORD PTR [ebp-0x10],0xfb9228
0x5500e7: e8243cefff                       call   0x443d10
0x5500ec: 8d45f0                           lea    eax,[ebp-0x10]
0x5500ef: c745f04092fb00                   mov    DWORD PTR [ebp-0x10],0xfb9240
0x5500f6: e8153cefff                       call   0x443d10
0x5500fb: 8d45f0                           lea    eax,[ebp-0x10]
0x5500fe: c745f05892fb00                   mov    DWORD PTR [ebp-0x10],0xfb9258
0x550105: e8063cefff                       call   0x443d10
0x55010a: 8d45f0                           lea    eax,[ebp-0x10]
0x55010d: c745f07092fb00                   mov    DWORD PTR [ebp-0x10],0xfb9270
0x550114: e8f73befff                       call   0x443d10
0x550119: 8d45f0                           lea    eax,[ebp-0x10]
0x55011c: c745f08892fb00                   mov    DWORD PTR [ebp-0x10],0xfb9288
0x550123: e8e83befff                       call   0x443d10
0x550128: 8d45f0                           lea    eax,[ebp-0x10]
0x55012b: c745f0a092fb00                   mov    DWORD PTR [ebp-0x10],0xfb92a0
0x550132: e8d93befff                       call   0x443d10
0x550137: 8d45f0                           lea    eax,[ebp-0x10]
0x55013a: c745f0b092fb00                   mov    DWORD PTR [ebp-0x10],0xfb92b0
0x550141: e8ca3befff                       call   0x443d10
0x550146: 8d45f0                           lea    eax,[ebp-0x10]
0x550149: c745f0c092fb00                   mov    DWORD PTR [ebp-0x10],0xfb92c0
0x550150: e8bb3befff                       call   0x443d10
0x550155: c745f0cc92fb00                   mov    DWORD PTR [ebp-0x10],0xfb92cc
0x55015c: 8d45f0                           lea    eax,[ebp-0x10]
0x55015f: e8ac3befff                       call   0x443d10
0x550164: 8d45f0                           lea    eax,[ebp-0x10]
0x550167: c745f0dc92fb00                   mov    DWORD PTR [ebp-0x10],0xfb92dc
0x55016e: e89d3befff                       call   0x443d10
0x550173: 8d45f0                           lea    eax,[ebp-0x10]
0x550176: c745f0e892fb00                   mov    DWORD PTR [ebp-0x10],0xfb92e8
0x55017d: e88e3befff                       call   0x443d10
0x550182: 8d45f0                           lea    eax,[ebp-0x10]
0x550185: c745f0f492fb00                   mov    DWORD PTR [ebp-0x10],0xfb92f4
0x55018c: e87f3befff                       call   0x443d10
0x550191: 8d45f0                           lea    eax,[ebp-0x10]
0x550194: c745f00093fb00                   mov    DWORD PTR [ebp-0x10],0xfb9300
0x55019b: e8703befff                       call   0x443d10
0x5501a0: 8d45f0                           lea    eax,[ebp-0x10]
0x5501a3: c745f00c93fb00                   mov    DWORD PTR [ebp-0x10],0xfb930c
0x5501aa: e8613befff                       call   0x443d10
0x5501af: 8d45f0                           lea    eax,[ebp-0x10]
0x5501b2: c745f01c93fb00                   mov    DWORD PTR [ebp-0x10],0xfb931c
0x5501b9: e8523befff                       call   0x443d10
0x5501be: 8d45f0                           lea    eax,[ebp-0x10]
0x5501c1: c745f02c93fb00                   mov    DWORD PTR [ebp-0x10],0xfb932c
0x5501c8: e8433befff                       call   0x443d10
0x5501cd: 8d45f0                           lea    eax,[ebp-0x10]
0x5501d0: c745f03893fb00                   mov    DWORD PTR [ebp-0x10],0xfb9338
0x5501d7: e8343befff                       call   0x443d10
0x5501dc: 8d45f0                           lea    eax,[ebp-0x10]
0x5501df: c745f04493fb00                   mov    DWORD PTR [ebp-0x10],0xfb9344
0x5501e6: e8253befff                       call   0x443d10
0x5501eb: 8d45f0                           lea    eax,[ebp-0x10]
0x5501ee: c745f05093fb00                   mov    DWORD PTR [ebp-0x10],0xfb9350
0x5501f5: e8163befff                       call   0x443d10
0x5501fa: 68e0d1be00                       push   0xbed1e0
0x5501ff: 683057c000                       push   0xc05730
0x550204: e872163400                       call   0x89187b
0x550209: 83c408                           add    esp,0x8
0x55020c: 3bc3                             cmp    eax,ebx
0x55020e: 7406                             je     0x550216
0x550210: 50                               push   eax
0x550211: e8bae01900                       call   0x6ee2d0
0x550216: b85090fb00                       mov    eax,0xfb9050
0x55021b: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x55021e: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x550225: 59                               pop    ecx
0x550226: 5f                               pop    edi
0x550227: 5e                               pop    esi
0x550228: 5b                               pop    ebx
0x550229: 8be5                             mov    esp,ebp
0x55022b: 5d                               pop    ebp
0x55022c: c3                               ret

## F-6D8E50 VA 0x6d8e50..0x6d9169 raw 0x2d8250 len 793 SHA256 0c2f7b0bdd76ffad3665b395d961b99e9f985a9e57730c46e556b5ec822a64ea
0x6d8e50: 55                               push   ebp
0x6d8e51: 8bec                             mov    ebp,esp
0x6d8e53: 6aff                             push   0xffffffff
0x6d8e55: 683d609100                       push   0x91603d
0x6d8e5a: 64a100000000                     mov    eax,fs:0x0
0x6d8e60: 50                               push   eax
0x6d8e61: 83ec50                           sub    esp,0x50
0x6d8e64: a1201fd600                       mov    eax,ds:0xd61f20
0x6d8e69: 33c5                             xor    eax,ebp
0x6d8e6b: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x6d8e6e: 53                               push   ebx
0x6d8e6f: 56                               push   esi
0x6d8e70: 50                               push   eax
0x6d8e71: 8d45f4                           lea    eax,[ebp-0xc]
0x6d8e74: 64a300000000                     mov    fs:0x0,eax
0x6d8e7a: 33db                             xor    ebx,ebx
0x6d8e7c: be0f000000                       mov    esi,0xf
0x6d8e81: c745a4c80ffc00                   mov    DWORD PTR [ebp-0x5c],0xfc0fc8
0x6d8e88: 8935dc0ffc00                     mov    DWORD PTR ds:0xfc0fdc,esi
0x6d8e8e: 891dd80ffc00                     mov    DWORD PTR ds:0xfc0fd8,ebx
0x6d8e94: 881dc80ffc00                     mov    BYTE PTR ds:0xfc0fc8,bl
0x6d8e9a: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x6d8e9d: 6a40                             push   0x40
0x6d8e9f: 891de40ffc00                     mov    DWORD PTR ds:0xfc0fe4,ebx
0x6d8ea5: 891de80ffc00                     mov    DWORD PTR ds:0xfc0fe8,ebx
0x6d8eab: 66891dec0ffc00                   mov    WORD PTR ds:0xfc0fec,bx
0x6d8eb2: 891df40ffc00                     mov    DWORD PTR ds:0xfc0ff4,ebx
0x6d8eb8: e8ab831b00                       call   0x891268
0x6d8ebd: 83c404                           add    esp,0x4
0x6d8ec0: 3bc3                             cmp    eax,ebx
0x6d8ec2: 0f847d020000                     je     0x6d9145
0x6d8ec8: a3f00ffc00                       mov    ds:0xfc0ff0,eax
0x6d8ecd: 8900                             mov    DWORD PTR [eax],eax
0x6d8ecf: a1f00ffc00                       mov    eax,ds:0xfc0ff0
0x6d8ed4: 894004                           mov    DWORD PTR [eax+0x4],eax
0x6d8ed7: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x6d8edb: 53                               push   ebx
0x6d8edc: 687523bf00                       push   0xbf2375
0x6d8ee1: 8d4dd4                           lea    ecx,[ebp-0x2c]
0x6d8ee4: 8975e8                           mov    DWORD PTR [ebp-0x18],esi
0x6d8ee7: 895de4                           mov    DWORD PTR [ebp-0x1c],ebx
0x6d8eea: 885dd4                           mov    BYTE PTR [ebp-0x2c],bl
0x6d8eed: e87e9bd2ff                       call   0x402a70
0x6d8ef2: 6aff                             push   0xffffffff
0x6d8ef4: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x6d8ef8: 53                               push   ebx
0x6d8ef9: 8d45d4                           lea    eax,[ebp-0x2c]
0x6d8efc: 50                               push   eax
0x6d8efd: b90010fc00                       mov    ecx,0xfc1000
0x6d8f02: 891dfc0ffc00                     mov    DWORD PTR ds:0xfc0ffc,ebx
0x6d8f08: 89351410fc00                     mov    DWORD PTR ds:0xfc1014,esi
0x6d8f0e: 891d1010fc00                     mov    DWORD PTR ds:0xfc1010,ebx
0x6d8f14: 881d0010fc00                     mov    BYTE PTR ds:0xfc1000,bl
0x6d8f1a: e821a1d2ff                       call   0x403040
0x6d8f1f: f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x6d8f27: f30f11052810fc00                 movss  DWORD PTR ds:0xfc1028,xmm0
0x6d8f2f: f30f1005f4c7c000                 movss  xmm0,DWORD PTR ds:0xc0c7f4
0x6d8f37: b910270000                       mov    ecx,0x2710
0x6d8f3c: f30f11052c10fc00                 movss  DWORD PTR ds:0xfc102c,xmm0
0x6d8f44: 0f57c0                           xorps  xmm0,xmm0
0x6d8f47: c7051c10fc0001000000             mov    DWORD PTR ds:0xfc101c,0x1
0x6d8f51: 66890d2010fc00                   mov    WORD PTR ds:0xfc1020,cx
0x6d8f58: 891d2410fc00                     mov    DWORD PTR ds:0xfc1024,ebx
0x6d8f5e: f30f11053010fc00                 movss  DWORD PTR ds:0xfc1030,xmm0
0x6d8f66: c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x6d8f6a: 837de810                         cmp    DWORD PTR [ebp-0x18],0x10
0x6d8f6e: 720c                             jb     0x6d8f7c
0x6d8f70: 8b55d4                           mov    edx,DWORD PTR [ebp-0x2c]
0x6d8f73: 52                               push   edx
0x6d8f74: e893821b00                       call   0x89120c
0x6d8f79: 83c404                           add    esp,0x4
0x6d8f7c: 53                               push   ebx
0x6d8f7d: 687523bf00                       push   0xbf2375
0x6d8f82: 8d4db8                           lea    ecx,[ebp-0x48]
0x6d8f85: 8975e8                           mov    DWORD PTR [ebp-0x18],esi
0x6d8f88: 895de4                           mov    DWORD PTR [ebp-0x1c],ebx
0x6d8f8b: 885dd4                           mov    BYTE PTR [ebp-0x2c],bl
0x6d8f8e: 8975cc                           mov    DWORD PTR [ebp-0x34],esi
0x6d8f91: 895dc8                           mov    DWORD PTR [ebp-0x38],ebx
0x6d8f94: 885db8                           mov    BYTE PTR [ebp-0x48],bl
0x6d8f97: e8d49ad2ff                       call   0x402a70
0x6d8f9c: 6aff                             push   0xffffffff
0x6d8f9e: c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x6d8fa2: 53                               push   ebx
0x6d8fa3: 8d45b8                           lea    eax,[ebp-0x48]
0x6d8fa6: 50                               push   eax
0x6d8fa7: b93810fc00                       mov    ecx,0xfc1038
0x6d8fac: 891d3410fc00                     mov    DWORD PTR ds:0xfc1034,ebx
0x6d8fb2: 89354c10fc00                     mov    DWORD PTR ds:0xfc104c,esi
0x6d8fb8: 891d4810fc00                     mov    DWORD PTR ds:0xfc1048,ebx
0x6d8fbe: 881d3810fc00                     mov    BYTE PTR ds:0xfc1038,bl
0x6d8fc4: e877a0d2ff                       call   0x403040
0x6d8fc9: f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x6d8fd1: f30f11056010fc00                 movss  DWORD PTR ds:0xfc1060,xmm0
0x6d8fd9: f30f1005f4c7c000                 movss  xmm0,DWORD PTR ds:0xc0c7f4
0x6d8fe1: b910270000                       mov    ecx,0x2710
0x6d8fe6: f30f11056410fc00                 movss  DWORD PTR ds:0xfc1064,xmm0
0x6d8fee: 0f57c0                           xorps  xmm0,xmm0
0x6d8ff1: c7055410fc0001000000             mov    DWORD PTR ds:0xfc1054,0x1
0x6d8ffb: 66890d5810fc00                   mov    WORD PTR ds:0xfc1058,cx
0x6d9002: 891d5c10fc00                     mov    DWORD PTR ds:0xfc105c,ebx
0x6d9008: f30f11056810fc00                 movss  DWORD PTR ds:0xfc1068,xmm0
0x6d9010: 837dcc10                         cmp    DWORD PTR [ebp-0x34],0x10
0x6d9014: 720c                             jb     0x6d9022
0x6d9016: 8b55b8                           mov    edx,DWORD PTR [ebp-0x48]
0x6d9019: 52                               push   edx
0x6d901a: e8ed811b00                       call   0x89120c
0x6d901f: 83c404                           add    esp,0x4
0x6d9022: 68a00f0000                       push   0xfa0
0x6d9027: 687c10fc00                       push   0xfc107c
0x6d902c: 891d6c10fc00                     mov    DWORD PTR ds:0xfc106c,ebx
0x6d9032: 891d7010fc00                     mov    DWORD PTR ds:0xfc1070,ebx
0x6d9038: ff152c22bd00                     call   DWORD PTR ds:0xbd222c
0x6d903e: 6a18                             push   0x18
0x6d9040: c645fc08                         mov    BYTE PTR [ebp-0x4],0x8
0x6d9044: e81f821b00                       call   0x891268
0x6d9049: 8bf0                             mov    esi,eax
0x6d904b: 83c404                           add    esp,0x4
0x6d904e: 8975b4                           mov    DWORD PTR [ebp-0x4c],esi
0x6d9051: c645fc09                         mov    BYTE PTR [ebp-0x4],0x9
0x6d9055: 3bf3                             cmp    esi,ebx
0x6d9057: 7432                             je     0x6d908b
0x6d9059: 6a0c                             push   0xc
0x6d905b: e808821b00                       call   0x891268
0x6d9060: 83c404                           add    esp,0x4
0x6d9063: 3bc3                             cmp    eax,ebx
0x6d9065: 741b                             je     0x6d9082
0x6d9067: c700ec0fc400                     mov    DWORD PTR [eax],0xc40fec
0x6d906d: c74004c80ffc00                   mov    DWORD PTR [eax+0x4],0xfc0fc8
0x6d9074: c7400870986d00                   mov    DWORD PTR [eax+0x8],0x6d9870
0x6d907b: e8a0fcffff                       call   0x6d8d20
0x6d9080: eb0b                             jmp    0x6d908d
0x6d9082: 33c0                             xor    eax,eax
0x6d9084: e897fcffff                       call   0x6d8d20
0x6d9089: eb02                             jmp    0x6d908d
0x6d908b: 33c0                             xor    eax,eax
0x6d908d: c645fc08                         mov    BYTE PTR [ebp-0x4],0x8
0x6d9091: 833ddc0ffc0010                   cmp    DWORD PTR ds:0xfc0fdc,0x10
0x6d9098: a37410fc00                       mov    ds:0xfc1074,eax
0x6d909d: a1c80ffc00                       mov    eax,ds:0xfc0fc8
0x6d90a2: 7305                             jae    0x6d90a9
0x6d90a4: b8c80ffc00                       mov    eax,0xfc0fc8
0x6d90a9: f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x6d90b0: 8818                             mov    BYTE PTR [eax],bl
0x6d90b2: 7521                             jne    0x6d90d5
0x6d90b4: 830d2888fb0001                   or     DWORD PTR ds:0xfb8828,0x1
0x6d90bb: c645fc0a                         mov    BYTE PTR [ebp-0x4],0xa
0x6d90bf: e88c67e7ff                       call   0x54f850
0x6d90c4: 6880d5bc00                       push   0xbcd580
0x6d90c9: e84c921b00                       call   0x89231a
0x6d90ce: 83c404                           add    esp,0x4
0x6d90d1: c645fc08                         mov    BYTE PTR [ebp-0x4],0x8
0x6d90d5: f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x6d90dc: 668b35ea90fb00                   mov    si,WORD PTR ds:0xfb90ea
0x6d90e3: 751d                             jne    0x6d9102
0x6d90e5: 830d2888fb0001                   or     DWORD PTR ds:0xfb8828,0x1
0x6d90ec: c645fc0b                         mov    BYTE PTR [ebp-0x4],0xb
0x6d90f0: e85b67e7ff                       call   0x54f850
0x6d90f5: 6880d5bc00                       push   0xbcd580
0x6d90fa: e81b921b00                       call   0x89231a
0x6d90ff: 83c404                           add    esp,0x4
0x6d9102: 0fbfc6                           movsx  eax,si
0x6d9105: 8945b4                           mov    DWORD PTR [ebp-0x4c],eax
0x6d9108: db45b4                           fild   DWORD PTR [ebp-0x4c]
0x6d910b: d80d5c93fb00                     fmul   DWORD PTR ds:0xfb935c
0x6d9111: e8fa5b2200                       call   0x8fed10
0x6d9116: e855190000                       call   0x6daa70
0x6d911b: e8f05b2200                       call   0x8fed10
0x6d9120: a36c10fc00                       mov    ds:0xfc106c,eax
0x6d9125: b8c80ffc00                       mov    eax,0xfc0fc8
0x6d912a: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x6d912d: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x6d9134: 59                               pop    ecx
0x6d9135: 5e                               pop    esi
0x6d9136: 5b                               pop    ebx
0x6d9137: 8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x6d913a: 33cd                             xor    ecx,ebp
0x6d913c: e8c07e1b00                       call   0x891001
0x6d9141: 8be5                             mov    esp,ebp
0x6d9143: 5d                               pop    ebp
0x6d9144: c3                               ret
0x6d9145: 8d4db4                           lea    ecx,[ebp-0x4c]
0x6d9148: 51                               push   ecx
0x6d9149: 8d4da8                           lea    ecx,[ebp-0x58]
0x6d914c: 895db4                           mov    DWORD PTR [ebp-0x4c],ebx
0x6d914f: e8557f1b00                       call   0x8910a9
0x6d9154: 68a857c800                       push   0xc857a8
0x6d9159: 8d55a8                           lea    edx,[ebp-0x58]
0x6d915c: 52                               push   edx
0x6d915d: c745a8a42cbd00                   mov    DWORD PTR [ebp-0x58],0xbd2ca4
0x6d9164: e887381c00                       call   0x89c9f0

## F-6D8D20 VA 0x6d8d20..0x6d8d94 raw 0x2d8120 len 116 SHA256 789eaf8d929cea6f12a2ba3a052e90e46002af14906741964cbfc92289a2e972
0x6d8d20: 57                               push   edi
0x6d8d21: 33ff                             xor    edi,edi
0x6d8d23: 57                               push   edi
0x6d8d24: 57                               push   edi
0x6d8d25: 57                               push   edi
0x6d8d26: 57                               push   edi
0x6d8d27: c706d40fc400                     mov    DWORD PTR [esi],0xc40fd4
0x6d8d2d: 897e04                           mov    DWORD PTR [esi+0x4],edi
0x6d8d30: 897e08                           mov    DWORD PTR [esi+0x8],edi
0x6d8d33: c7460cffffffff                   mov    DWORD PTR [esi+0xc],0xffffffff
0x6d8d3a: 897e10                           mov    DWORD PTR [esi+0x10],edi
0x6d8d3d: 894614                           mov    DWORD PTR [esi+0x14],eax
0x6d8d40: ff15cc20bd00                     call   DWORD PTR ds:0xbd20cc
0x6d8d46: 6a0c                             push   0xc
0x6d8d48: 89460c                           mov    DWORD PTR [esi+0xc],eax
0x6d8d4b: c7460801000000                   mov    DWORD PTR [esi+0x8],0x1
0x6d8d52: e811851b00                       call   0x891268
0x6d8d57: 83c404                           add    esp,0x4
0x6d8d5a: 3bc7                             cmp    eax,edi
0x6d8d5c: 7412                             je     0x6d8d70
0x6d8d5e: c700dc0fc400                     mov    DWORD PTR [eax],0xc40fdc
0x6d8d64: 897004                           mov    DWORD PTR [eax+0x4],esi
0x6d8d67: c74008a08d6d00                   mov    DWORD PTR [eax+0x8],0x6d8da0
0x6d8d6e: eb02                             jmp    0x6d8d72
0x6d8d70: 33c0                             xor    eax,eax
0x6d8d72: 8bf8                             mov    edi,eax
0x6d8d74: e8f729e2ff                       call   0x4fb770
0x6d8d79: 894604                           mov    DWORD PTR [esi+0x4],eax
0x6d8d7c: 8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0x6d8d7f: 51                               push   ecx
0x6d8d80: 83c9ff                           or     ecx,0xffffffff
0x6d8d83: bac00fc400                       mov    edx,0xc40fc0
0x6d8d88: e8b3feffff                       call   0x6d8c40
0x6d8d8d: 83c404                           add    esp,0x4
0x6d8d90: 8bc6                             mov    eax,esi
0x6d8d92: 5f                               pop    edi
0x6d8d93: c3                               ret

## F-6D9280 VA 0x6d9280..0x6d9422 raw 0x2d8680 len 418 SHA256 9c2e510a34cfd4fec84c5af3dc52194c00af1aa5618933f345fd88f70c436d7f
0x6d9280: 55                               push   ebp
0x6d9281: 8bec                             mov    ebp,esp
0x6d9283: 83e4f8                           and    esp,0xfffffff8
0x6d9286: 6aff                             push   0xffffffff
0x6d9288: 68a85f9100                       push   0x915fa8
0x6d928d: 64a100000000                     mov    eax,fs:0x0
0x6d9293: 50                               push   eax
0x6d9294: 83ec68                           sub    esp,0x68
0x6d9297: a1201fd600                       mov    eax,ds:0xd61f20
0x6d929c: 33c4                             xor    eax,esp
0x6d929e: 89442460                         mov    DWORD PTR [esp+0x60],eax
0x6d92a2: 53                               push   ebx
0x6d92a3: 56                               push   esi
0x6d92a4: 57                               push   edi
0x6d92a5: a1201fd600                       mov    eax,ds:0xd61f20
0x6d92aa: 33c4                             xor    eax,esp
0x6d92ac: 50                               push   eax
0x6d92ad: 8d442478                         lea    eax,[esp+0x78]
0x6d92b1: 64a300000000                     mov    fs:0x0,eax
0x6d92b7: 8bf1                             mov    esi,ecx
0x6d92b9: 8d86b4000000                     lea    eax,[esi+0xb4]
0x6d92bf: 8bfa                             mov    edi,edx
0x6d92c1: 50                               push   eax
0x6d92c2: 897c241c                         mov    DWORD PTR [esp+0x1c],edi
0x6d92c6: 89442418                         mov    DWORD PTR [esp+0x18],eax
0x6d92ca: ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x6d92d0: 33db                             xor    ebx,ebx
0x6d92d2: 899c2480000000                   mov    DWORD PTR [esp+0x80],ebx
0x6d92d9: 53                               push   ebx
0x6d92da: 687523bf00                       push   0xbf2375
0x6d92df: 8d4c245c                         lea    ecx,[esp+0x5c]
0x6d92e3: c74424700f000000                 mov    DWORD PTR [esp+0x70],0xf
0x6d92eb: 895c246c                         mov    DWORD PTR [esp+0x6c],ebx
0x6d92ef: 885c245c                         mov    BYTE PTR [esp+0x5c],bl
0x6d92f3: e87897d2ff                       call   0x402a70
0x6d92f8: c684248000000001                 mov    BYTE PTR [esp+0x80],0x1
0x6d9300: 8b07                             mov    eax,DWORD PTR [edi]
0x6d9302: 6aff                             push   0xffffffff
0x6d9304: 53                               push   ebx
0x6d9305: 8d4c245c                         lea    ecx,[esp+0x5c]
0x6d9309: 51                               push   ecx
0x6d930a: 8d4c242c                         lea    ecx,[esp+0x2c]
0x6d930e: 89442428                         mov    DWORD PTR [esp+0x28],eax
0x6d9312: c74424400f000000                 mov    DWORD PTR [esp+0x40],0xf
0x6d931a: 895c243c                         mov    DWORD PTR [esp+0x3c],ebx
0x6d931e: 885c242c                         mov    BYTE PTR [esp+0x2c],bl
0x6d9322: e8199dd2ff                       call   0x403040
0x6d9327: f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x6d932f: f30f11442448                     movss  DWORD PTR [esp+0x48],xmm0
0x6d9335: f30f104508                       movss  xmm0,DWORD PTR [ebp+0x8]
0x6d933a: b801000000                       mov    eax,0x1
0x6d933f: ba10270000                       mov    edx,0x2710
0x6d9344: f30f1144244c                     movss  DWORD PTR [esp+0x4c],xmm0
0x6d934a: 0f57c0                           xorps  xmm0,xmm0
0x6d934d: 8944243c                         mov    DWORD PTR [esp+0x3c],eax
0x6d9351: 6689542440                       mov    WORD PTR [esp+0x40],dx
0x6d9356: 89442444                         mov    DWORD PTR [esp+0x44],eax
0x6d935a: f30f11442450                     movss  DWORD PTR [esp+0x50],xmm0
0x6d9360: c684248000000002                 mov    BYTE PTR [esp+0x80],0x2
0x6d9368: 8b7e28                           mov    edi,DWORD PTR [esi+0x28]
0x6d936b: 8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0x6d936e: 8d44241c                         lea    eax,[esp+0x1c]
0x6d9372: 50                               push   eax
0x6d9373: 51                               push   ecx
0x6d9374: 57                               push   edi
0x6d9375: e826180000                       call   0x6daba0
0x6d937a: 8b4e2c                           mov    ecx,DWORD PTR [esi+0x2c]
0x6d937d: ba23499204                       mov    edx,0x4924923
0x6d9382: 2bd1                             sub    edx,ecx
0x6d9384: 83fa01                           cmp    edx,0x1
0x6d9387: 730a                             jae    0x6d9393
0x6d9389: 683420bf00                       push   0xbf2034
0x6d938e: e89d471a00                       call   0x87db30
0x6d9393: 41                               inc    ecx
0x6d9394: 894e2c                           mov    DWORD PTR [esi+0x2c],ecx
0x6d9397: 894704                           mov    DWORD PTR [edi+0x4],eax
0x6d939a: 8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0x6d939d: bf10000000                       mov    edi,0x10
0x6d93a2: 8901                             mov    DWORD PTR [ecx],eax
0x6d93a4: 397c2434                         cmp    DWORD PTR [esp+0x34],edi
0x6d93a8: 720d                             jb     0x6d93b7
0x6d93aa: 8b542420                         mov    edx,DWORD PTR [esp+0x20]
0x6d93ae: 52                               push   edx
0x6d93af: e8587e1b00                       call   0x89120c
0x6d93b4: 83c404                           add    esp,0x4
0x6d93b7: c74424340f000000                 mov    DWORD PTR [esp+0x34],0xf
0x6d93bf: 895c2430                         mov    DWORD PTR [esp+0x30],ebx
0x6d93c3: 885c2420                         mov    BYTE PTR [esp+0x20],bl
0x6d93c7: 397c2468                         cmp    DWORD PTR [esp+0x68],edi
0x6d93cb: 720d                             jb     0x6d93da
0x6d93cd: 8b442454                         mov    eax,DWORD PTR [esp+0x54]
0x6d93d1: 50                               push   eax
0x6d93d2: e8357e1b00                       call   0x89120c
0x6d93d7: 83c404                           add    esp,0x4
0x6d93da: 8b4c2418                         mov    ecx,DWORD PTR [esp+0x18]
0x6d93de: 8919                             mov    DWORD PTR [ecx],ebx
0x6d93e0: 8bb6ac000000                     mov    esi,DWORD PTR [esi+0xac]
0x6d93e6: 8b560c                           mov    edx,DWORD PTR [esi+0xc]
0x6d93e9: 52                               push   edx
0x6d93ea: c7461001000000                   mov    DWORD PTR [esi+0x10],0x1
0x6d93f1: ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0x6d93f7: 8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x6d93fb: 50                               push   eax
0x6d93fc: ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x6d9402: 8b4c2478                         mov    ecx,DWORD PTR [esp+0x78]
0x6d9406: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x6d940d: 59                               pop    ecx
0x6d940e: 5f                               pop    edi
0x6d940f: 5e                               pop    esi
0x6d9410: 5b                               pop    ebx
0x6d9411: 8b4c2460                         mov    ecx,DWORD PTR [esp+0x60]
0x6d9415: 33cc                             xor    ecx,esp
0x6d9417: e8e57b1b00                       call   0x891001
0x6d941c: 8be5                             mov    esp,ebp
0x6d941e: 5d                               pop    ebp
0x6d941f: c20400                           ret    0x4

## F-6DAA70 VA 0x6daa70..0x6dab0e raw 0x2d9e70 len 158 SHA256 a2e7e950038202d386cc721929561ede70ec17502661527f78aeea4b214dae12
0x6daa70: 55                               push   ebp
0x6daa71: 8bec                             mov    ebp,esp
0x6daa73: 83ec08                           sub    esp,0x8
0x6daa76: 98                               cwde
0x6daa77: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x6daa7a: f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x6daa82: db45fc                           fild   DWORD PTR [ebp-0x4]
0x6daa85: dc357857c500                     fdiv   QWORD PTR ds:0xc55778
0x6daa8b: d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x6daa8e: d9ee                             fldz
0x6daa90: d945fc                           fld    DWORD PTR [ebp-0x4]
0x6daa93: dff1                             fcomip st,st(1)
0x6daa95: ddd8                             fstp   st(0)
0x6daa97: 7608                             jbe    0x6daaa1
0x6daa99: 0f2f45fc                         comiss xmm0,DWORD PTR [ebp-0x4]
0x6daa9d: 7605                             jbe    0x6daaa4
0x6daa9f: eb08                             jmp    0x6daaa9
0x6daaa1: 0f57c0                           xorps  xmm0,xmm0
0x6daaa4: f30f1145fc                       movss  DWORD PTR [ebp-0x4],xmm0
0x6daaa9: d9057457c500                     fld    DWORD PTR ds:0xc55774
0x6daaaf: 83ec08                           sub    esp,0x8
0x6daab2: d95c2404                         fstp   DWORD PTR [esp+0x4]
0x6daab6: d945fc                           fld    DWORD PTR [ebp-0x4]
0x6daab9: d91c24                           fstp   DWORD PTR [esp]
0x6daabc: e8ef010000                       call   0x6dacb0
0x6daac1: d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x6daac4: 83c408                           add    esp,0x8
0x6daac7: d9ee                             fldz
0x6daac9: d945fc                           fld    DWORD PTR [ebp-0x4]
0x6daacc: dff1                             fcomip st,st(1)
0x6daace: ddd8                             fstp   st(0)
0x6daad0: 7621                             jbe    0x6daaf3
0x6daad2: f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x6daada: 0f2f45fc                         comiss xmm0,DWORD PTR [ebp-0x4]
0x6daade: 7616                             jbe    0x6daaf6
0x6daae0: d945fc                           fld    DWORD PTR [ebp-0x4]
0x6daae3: dc0d7857c500                     fmul   QWORD PTR ds:0xc55778
0x6daae9: d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x6daaec: d945fc                           fld    DWORD PTR [ebp-0x4]
0x6daaef: 8be5                             mov    esp,ebp
0x6daaf1: 5d                               pop    ebp
0x6daaf2: c3                               ret
0x6daaf3: 0f57c0                           xorps  xmm0,xmm0
0x6daaf6: f30f1145fc                       movss  DWORD PTR [ebp-0x4],xmm0
0x6daafb: d945fc                           fld    DWORD PTR [ebp-0x4]
0x6daafe: dc0d7857c500                     fmul   QWORD PTR ds:0xc55778
0x6dab04: d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x6dab07: d945fc                           fld    DWORD PTR [ebp-0x4]
0x6dab0a: 8be5                             mov    esp,ebp
0x6dab0c: 5d                               pop    ebp
0x6dab0d: c3                               ret

## F-6DACB0 VA 0x6dacb0..0x6dacd0 raw 0x2da0b0 len 32 SHA256 d7f618d87e648946437da778354350c318bc7d757662483060eca53ddb820396
0x6dacb0: 55                               push   ebp
0x6dacb1: 8bec                             mov    ebp,esp
0x6dacb3: 83e4f8                           and    esp,0xfffffff8
0x6dacb6: 83ec08                           sub    esp,0x8
0x6dacb9: d94508                           fld    DWORD PTR [ebp+0x8]
0x6dacbc: d9450c                           fld    DWORD PTR [ebp+0xc]
0x6dacbf: e8dc482200                       call   0x8ff5a0
0x6dacc4: d95c2404                         fstp   DWORD PTR [esp+0x4]
0x6dacc8: d9442404                         fld    DWORD PTR [esp+0x4]
0x6daccc: 8be5                             mov    esp,ebp
0x6dacce: 5d                               pop    ebp
0x6daccf: c3                               ret

## F-6D9B30 VA 0x6d9b30..0x6d9cb3 raw 0x2d8f30 len 387 SHA256 4286d815e3b2d8dc26926d7570409ec9604a956d5db134fa24e23fb369c094a0
0x6d9b30: 55                               push   ebp
0x6d9b31: 8bec                             mov    ebp,esp
0x6d9b33: 6aff                             push   0xffffffff
0x6d9b35: 689e9a9100                       push   0x919a9e
0x6d9b3a: 64a100000000                     mov    eax,fs:0x0
0x6d9b40: 50                               push   eax
0x6d9b41: 53                               push   ebx
0x6d9b42: 56                               push   esi
0x6d9b43: 57                               push   edi
0x6d9b44: a1201fd600                       mov    eax,ds:0xd61f20
0x6d9b49: 33c5                             xor    eax,ebp
0x6d9b4b: 50                               push   eax
0x6d9b4c: 8d45f4                           lea    eax,[ebp-0xc]
0x6d9b4f: 64a300000000                     mov    fs:0x0,eax
0x6d9b55: 8bf1                             mov    esi,ecx
0x6d9b57: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x6d9b5a: 837e1810                         cmp    DWORD PTR [esi+0x18],0x10
0x6d9b5e: 7205                             jb     0x6d9b65
0x6d9b60: 8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x6d9b63: eb03                             jmp    0x6d9b68
0x6d9b65: 8d4604                           lea    eax,[esi+0x4]
0x6d9b68: 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x6d9b6b: 51                               push   ecx
0x6d9b6c: 50                               push   eax
0x6d9b6d: e83fa11b00                       call   0x893cb1
0x6d9b72: 83c408                           add    esp,0x8
0x6d9b75: 85c0                             test   eax,eax
0x6d9b77: 0f8422010000                     je     0x6d9c9f
0x6d9b7d: 833e00                           cmp    DWORD PTR [esi],0x0
0x6d9b80: 746c                             je     0x6d9bee
0x6d9b82: f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x6d9b89: 7527                             jne    0x6d9bb2
0x6d9b8b: 830d2888fb0001                   or     DWORD PTR ds:0xfb8828,0x1
0x6d9b92: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x6d9b99: e8b25ce7ff                       call   0x54f850
0x6d9b9e: 6880d5bc00                       push   0xbcd580
0x6d9ba3: e872871b00                       call   0x89231a
0x6d9ba8: 83c404                           add    esp,0x4
0x6d9bab: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x6d9bb2: 803d3593fb0000                   cmp    BYTE PTR ds:0xfb9335,0x0
0x6d9bb9: 7415                             je     0x6d9bd0
0x6d9bbb: d905f4c7c000                     fld    DWORD PTR ds:0xc0c7f4
0x6d9bc1: 51                               push   ecx
0x6d9bc2: 8bd6                             mov    edx,esi
0x6d9bc4: d91c24                           fstp   DWORD PTR [esp]
0x6d9bc7: 8bcb                             mov    ecx,ebx
0x6d9bc9: e8b2f6ffff                       call   0x6d9280
0x6d9bce: eb09                             jmp    0x6d9bd9
0x6d9bd0: 8b0e                             mov    ecx,DWORD PTR [esi]
0x6d9bd2: 8b11                             mov    edx,DWORD PTR [ecx]
0x6d9bd4: 8b422c                           mov    eax,DWORD PTR [edx+0x2c]
0x6d9bd7: ffd0                             call   eax
0x6d9bd9: 6a00                             push   0x0
0x6d9bdb: 687523bf00                       push   0xbf2375
0x6d9be0: 8d4e04                           lea    ecx,[esi+0x4]
0x6d9be3: e8888ed2ff                       call   0x402a70
0x6d9be8: c70600000000                     mov    DWORD PTR [esi],0x0
0x6d9bee: 668b5514                         mov    dx,WORD PTR [ebp+0x14]
0x6d9bf2: 8b4d10                           mov    ecx,DWORD PTR [ebp+0x10]
0x6d9bf5: 8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x6d9bf8: 66895624                         mov    WORD PTR [esi+0x24],dx
0x6d9bfc: 894e20                           mov    DWORD PTR [esi+0x20],ecx
0x6d9bff: 8d5001                           lea    edx,[eax+0x1]
0x6d9c02: 8a08                             mov    cl,BYTE PTR [eax]
0x6d9c04: 40                               inc    eax
0x6d9c05: 84c9                             test   cl,cl
0x6d9c07: 75f9                             jne    0x6d9c02
0x6d9c09: 2bc2                             sub    eax,edx
0x6d9c0b: 50                               push   eax
0x6d9c0c: 8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x6d9c0f: 50                               push   eax
0x6d9c10: 8d4e04                           lea    ecx,[esi+0x4]
0x6d9c13: e8588ed2ff                       call   0x402a70
0x6d9c18: c70600000000                     mov    DWORD PTR [esi],0x0
0x6d9c1e: 32c9                             xor    cl,cl
0x6d9c20: 837b2c00                         cmp    DWORD PTR [ebx+0x2c],0x0
0x6d9c24: 743a                             je     0x6d9c60
0x6d9c26: 8b5328                           mov    edx,DWORD PTR [ebx+0x28]
0x6d9c29: 8b02                             mov    eax,DWORD PTR [edx]
0x6d9c2b: 3bc2                             cmp    eax,edx
0x6d9c2d: 7431                             je     0x6d9c60
0x6d9c2f: f30f1005c85bc500                 movss  xmm0,DWORD PTR ds:0xc55bc8
0x6d9c37: eb07                             jmp    0x6d9c40
0x6d9c39: 8da42400000000                   lea    esp,[esp+0x0]
0x6d9c40: f30f104834                       movss  xmm1,DWORD PTR [eax+0x34]
0x6d9c45: 0f2fc8                           comiss xmm1,xmm0
0x6d9c48: 7602                             jbe    0x6d9c4c
0x6d9c4a: b101                             mov    cl,0x1
0x6d9c4c: 8b00                             mov    eax,DWORD PTR [eax]
0x6d9c4e: 3bc2                             cmp    eax,edx
0x6d9c50: 75ee                             jne    0x6d9c40
0x6d9c52: 84c9                             test   cl,cl
0x6d9c54: 740a                             je     0x6d9c60
0x6d9c56: f30f1005f8c7c000                 movss  xmm0,DWORD PTR ds:0xc0c7f8
0x6d9c5e: eb08                             jmp    0x6d9c68
0x6d9c60: f30f1005c058c500                 movss  xmm0,DWORD PTR ds:0xc558c0
0x6d9c68: f30f114634                       movss  DWORD PTR [esi+0x34],xmm0
0x6d9c6d: 8db3b4000000                     lea    esi,[ebx+0xb4]
0x6d9c73: 56                               push   esi
0x6d9c74: ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x6d9c7a: bf01000000                       mov    edi,0x1
0x6d9c7f: 56                               push   esi
0x6d9c80: 89bba8000000                     mov    DWORD PTR [ebx+0xa8],edi
0x6d9c86: ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x6d9c8c: 8b83ac000000                     mov    eax,DWORD PTR [ebx+0xac]
0x6d9c92: 8b480c                           mov    ecx,DWORD PTR [eax+0xc]
0x6d9c95: 51                               push   ecx
0x6d9c96: 897810                           mov    DWORD PTR [eax+0x10],edi
0x6d9c99: ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0x6d9c9f: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x6d9ca2: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x6d9ca9: 59                               pop    ecx
0x6d9caa: 5f                               pop    edi
0x6d9cab: 5e                               pop    esi
0x6d9cac: 5b                               pop    ebx
0x6d9cad: 8be5                             mov    esp,ebp
0x6d9caf: 5d                               pop    ebp
0x6d9cb0: c21000                           ret    0x10

## F-6D8DA0 VA 0x6d8da0..0x6d8de6 raw 0x2d81a0 len 70 SHA256 77db1d299b377415cddd1cf33eb3c7ecab98a7788c7dd1b2b9504ed529750838
0x6d8da0: 56                               push   esi
0x6d8da1: 8bf1                             mov    esi,ecx
0x6d8da3: 837e0800                         cmp    DWORD PTR [esi+0x8],0x0
0x6d8da7: 743b                             je     0x6d8de4
0x6d8da9: 57                               push   edi
0x6d8daa: 8b3dfc20bd00                     mov    edi,DWORD PTR ds:0xbd20fc
0x6d8db0: 8b460c                           mov    eax,DWORD PTR [esi+0xc]
0x6d8db3: 68e8030000                       push   0x3e8
0x6d8db8: 50                               push   eax
0x6d8db9: ffd7                             call   edi
0x6d8dbb: 85c0                             test   eax,eax
0x6d8dbd: 751e                             jne    0x6d8ddd
0x6d8dbf: 394608                           cmp    DWORD PTR [esi+0x8],eax
0x6d8dc2: 741f                             je     0x6d8de3
0x6d8dc4: 837e1000                         cmp    DWORD PTR [esi+0x10],0x0
0x6d8dc8: 7413                             je     0x6d8ddd
0x6d8dca: 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x6d8dcd: 8b11                             mov    edx,DWORD PTR [ecx]
0x6d8dcf: 8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x6d8dd2: ffd0                             call   eax
0x6d8dd4: 837e0800                         cmp    DWORD PTR [esi+0x8],0x0
0x6d8dd8: 75ea                             jne    0x6d8dc4
0x6d8dda: 5f                               pop    edi
0x6d8ddb: 5e                               pop    esi
0x6d8ddc: c3                               ret
0x6d8ddd: 837e0800                         cmp    DWORD PTR [esi+0x8],0x0
0x6d8de1: 75cd                             jne    0x6d8db0
0x6d8de3: 5f                               pop    edi
0x6d8de4: 5e                               pop    esi
0x6d8de5: c3                               ret

## F-4FACD0 VA 0x4facd0..0x4facda raw 0xfa0d0 len 10 SHA256 3e450d1bc183b3f5cca4ce5e2649698aeb93207a26d57ba939e786da9c9311a5
0x4facd0: 8bc1                             mov    eax,ecx
0x4facd2: 8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0x4facd5: 8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4facd8: ffe0                             jmp    eax

## F-6D9870 VA 0x6d9870..0x6d9970 raw 0x2d8c70 len 256 SHA256 8f707ec35c736960bdfe2e9d443fbd31726b417b88442926f10eb6a05e1fdcb4
0x6d9870: 55                               push   ebp
0x6d9871: 8bec                             mov    ebp,esp
0x6d9873: 6aff                             push   0xffffffff
0x6d9875: 68685f9100                       push   0x915f68
0x6d987a: 64a100000000                     mov    eax,fs:0x0
0x6d9880: 50                               push   eax
0x6d9881: 51                               push   ecx
0x6d9882: 53                               push   ebx
0x6d9883: 56                               push   esi
0x6d9884: 57                               push   edi
0x6d9885: a1201fd600                       mov    eax,ds:0xd61f20
0x6d988a: 33c5                             xor    eax,ebp
0x6d988c: 50                               push   eax
0x6d988d: 8d45f4                           lea    eax,[ebp-0xc]
0x6d9890: 64a300000000                     mov    fs:0x0,eax
0x6d9896: 8bf9                             mov    edi,ecx
0x6d9898: 8d87b4000000                     lea    eax,[edi+0xb4]
0x6d989e: 50                               push   eax
0x6d989f: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x6d98a2: ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x6d98a8: 33c0                             xor    eax,eax
0x6d98aa: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x6d98ad: 3987a8000000                     cmp    DWORD PTR [edi+0xa8],eax
0x6d98b3: 750e                             jne    0x6d98c3
0x6d98b5: 39472c                           cmp    DWORD PTR [edi+0x2c],eax
0x6d98b8: 7509                             jne    0x6d98c3
0x6d98ba: 8b8fac000000                     mov    ecx,DWORD PTR [edi+0xac]
0x6d98c0: 894110                           mov    DWORD PTR [ecx+0x10],eax
0x6d98c3: 8987a8000000                     mov    DWORD PTR [edi+0xa8],eax
0x6d98c9: 8d7734                           lea    esi,[edi+0x34]
0x6d98cc: 8bc6                             mov    eax,esi
0x6d98ce: e89d000000                       call   0x6d9970
0x6d98d3: 8d476c                           lea    eax,[edi+0x6c]
0x6d98d6: e895000000                       call   0x6d9970
0x6d98db: e830010000                       call   0x6d9a10
0x6d98e0: 8d776c                           lea    esi,[edi+0x6c]
0x6d98e3: e828010000                       call   0x6d9a10
0x6d98e8: 8b4728                           mov    eax,DWORD PTR [edi+0x28]
0x6d98eb: 8b18                             mov    ebx,DWORD PTR [eax]
0x6d98ed: 3bd8                             cmp    ebx,eax
0x6d98ef: 745b                             je     0x6d994c
0x6d98f1: 8d7308                           lea    esi,[ebx+0x8]
0x6d98f4: e817010000                       call   0x6d9a10
0x6d98f9: 85c0                             test   eax,eax
0x6d98fb: 7448                             je     0x6d9945
0x6d98fd: 8b33                             mov    esi,DWORD PTR [ebx]
0x6d98ff: 3b5f28                           cmp    ebx,DWORD PTR [edi+0x28]
0x6d9902: 743d                             je     0x6d9941
0x6d9904: 8b5304                           mov    edx,DWORD PTR [ebx+0x4]
0x6d9907: 8932                             mov    DWORD PTR [edx],esi
0x6d9909: 8b03                             mov    eax,DWORD PTR [ebx]
0x6d990b: 8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0x6d990e: 894804                           mov    DWORD PTR [eax+0x4],ecx
0x6d9911: 837b2010                         cmp    DWORD PTR [ebx+0x20],0x10
0x6d9915: 720c                             jb     0x6d9923
0x6d9917: 8b530c                           mov    edx,DWORD PTR [ebx+0xc]
0x6d991a: 52                               push   edx
0x6d991b: e8ec781b00                       call   0x89120c
0x6d9920: 83c404                           add    esp,0x4
0x6d9923: c743200f000000                   mov    DWORD PTR [ebx+0x20],0xf
0x6d992a: c7431c00000000                   mov    DWORD PTR [ebx+0x1c],0x0
0x6d9931: 53                               push   ebx
0x6d9932: c6430c00                         mov    BYTE PTR [ebx+0xc],0x0
0x6d9936: e8d1781b00                       call   0x89120c
0x6d993b: 83c404                           add    esp,0x4
0x6d993e: ff4f2c                           dec    DWORD PTR [edi+0x2c]
0x6d9941: 8bde                             mov    ebx,esi
0x6d9943: eb02                             jmp    0x6d9947
0x6d9945: 8b1b                             mov    ebx,DWORD PTR [ebx]
0x6d9947: 3b5f28                           cmp    ebx,DWORD PTR [edi+0x28]
0x6d994a: 75a5                             jne    0x6d98f1
0x6d994c: 8b45f0                           mov    eax,DWORD PTR [ebp-0x10]
0x6d994f: 50                               push   eax
0x6d9950: ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x6d9956: 6a21                             push   0x21
0x6d9958: ff150423bd00                     call   DWORD PTR ds:0xbd2304
0x6d995e: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x6d9961: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x6d9968: 59                               pop    ecx
0x6d9969: 5f                               pop    edi
0x6d996a: 5e                               pop    esi
0x6d996b: 5b                               pop    ebx
0x6d996c: 8be5                             mov    esp,ebp
0x6d996e: 5d                               pop    ebp
0x6d996f: c3                               ret

## F-6D9970 VA 0x6d9970..0x6d9a08 raw 0x2d8d70 len 152 SHA256 f9996a5de9a66da2c66bb30504159539756eecf53c2992b8ba4768dcc1eefbc1
0x6d9970: 55                               push   ebp
0x6d9971: 8bec                             mov    ebp,esp
0x6d9973: 51                               push   ecx
0x6d9974: 56                               push   esi
0x6d9975: 8bf0                             mov    esi,eax
0x6d9977: f30f104634                       movss  xmm0,DWORD PTR [esi+0x34]
0x6d997c: 0f2f056c56c500                   comiss xmm0,DWORD PTR ds:0xc5566c
0x6d9983: 767e                             jbe    0x6d9a03
0x6d9985: a1cca7fb00                       mov    eax,ds:0xfba7cc
0x6d998a: 85c0                             test   eax,eax
0x6d998c: 751f                             jne    0x6d99ad
0x6d998e: 6880130000                       push   0x1380
0x6d9993: e8d0781b00                       call   0x891268
0x6d9998: 83c404                           add    esp,0x4
0x6d999b: 85c0                             test   eax,eax
0x6d999d: 7407                             je     0x6d99a6
0x6d999f: e82c5a0000                       call   0x6df3d0
0x6d99a4: eb02                             jmp    0x6d99a8
0x6d99a6: 33c0                             xor    eax,eax
0x6d99a8: a3cca7fb00                       mov    ds:0xfba7cc,eax
0x6d99ad: d94634                           fld    DWORD PTR [esi+0x34]
0x6d99b0: db8060130000                     fild   DWORD PTR [eax+0x1360]
0x6d99b6: d9e8                             fld1
0x6d99b8: def1                             fdivrp st(1),st
0x6d99ba: d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x6d99bd: d865fc                           fsub   DWORD PTR [ebp-0x4]
0x6d99c0: d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x6d99c3: d945fc                           fld    DWORD PTR [ebp-0x4]
0x6d99c6: d95634                           fst    DWORD PTR [esi+0x34]
0x6d99c9: d9ee                             fldz
0x6d99cb: dff1                             fcomip st,st(1)
0x6d99cd: ddd8                             fstp   st(0)
0x6d99cf: 7214                             jb     0x6d99e5
0x6d99d1: 0f57c0                           xorps  xmm0,xmm0
0x6d99d4: 56                               push   esi
0x6d99d5: 57                               push   edi
0x6d99d6: f30f114634                       movss  DWORD PTR [esi+0x34],xmm0
0x6d99db: e830040000                       call   0x6d9e10
0x6d99e0: 5e                               pop    esi
0x6d99e1: 8be5                             mov    esp,ebp
0x6d99e3: 5d                               pop    ebp
0x6d99e4: c3                               ret
0x6d99e5: 8db7b4000000                     lea    esi,[edi+0xb4]
0x6d99eb: 56                               push   esi
0x6d99ec: ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x6d99f2: 56                               push   esi
0x6d99f3: c787a800000001000000             mov    DWORD PTR [edi+0xa8],0x1
0x6d99fd: ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x6d9a03: 5e                               pop    esi
0x6d9a04: 8be5                             mov    esp,ebp
0x6d9a06: 5d                               pop    ebp
0x6d9a07: c3                               ret

## F-6D9E10 VA 0x6d9e10..0x6d9efa raw 0x2d9210 len 234 SHA256 4e80a27c17e3c5a5f285a9ca2104ca94b534300dc3802ea43eaa894995841037
0x6d9e10: 55                               push   ebp
0x6d9e11: 8bec                             mov    ebp,esp
0x6d9e13: f6059816fc0001                   test   BYTE PTR ds:0xfc1698,0x1
0x6d9e1a: 53                               push   ebx
0x6d9e1b: 8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
0x6d9e1e: 56                               push   esi
0x6d9e1f: 7519                             jne    0x6d9e3a
0x6d9e21: 830d9816fc0001                   or     DWORD PTR ds:0xfc1698,0x1
0x6d9e28: e8732a1300                       call   0x80c8a0
0x6d9e2d: 6820e3bc00                       push   0xbce320
0x6d9e32: e8e3841b00                       call   0x89231a
0x6d9e37: 83c404                           add    esp,0x4
0x6d9e3a: 33f6                             xor    esi,esi
0x6d9e3c: 8d642400                         lea    esp,[esp+0x0]
0x6d9e40: 8b0cb5a016fc00                   mov    ecx,DWORD PTR [esi*4+0xfc16a0]
0x6d9e47: 85c9                             test   ecx,ecx
0x6d9e49: 740b                             je     0x6d9e56
0x6d9e4b: 8b01                             mov    eax,DWORD PTR [ecx]
0x6d9e4d: 8b5030                           mov    edx,DWORD PTR [eax+0x30]
0x6d9e50: ffd2                             call   edx
0x6d9e52: 85c0                             test   eax,eax
0x6d9e54: 740c                             je     0x6d9e62
0x6d9e56: 46                               inc    esi
0x6d9e57: 83fe10                           cmp    esi,0x10
0x6d9e5a: 7ce4                             jl     0x6d9e40
0x6d9e5c: 5e                               pop    esi
0x6d9e5d: 5b                               pop    ebx
0x6d9e5e: 5d                               pop    ebp
0x6d9e5f: c20800                           ret    0x8
0x6d9e62: 8b34b5a016fc00                   mov    esi,DWORD PTR [esi*4+0xfc16a0]
0x6d9e69: 85f6                             test   esi,esi
0x6d9e6b: 0f8483000000                     je     0x6d9ef4
0x6d9e71: 837b1810                         cmp    DWORD PTR [ebx+0x18],0x10
0x6d9e75: 57                               push   edi
0x6d9e76: 7205                             jb     0x6d9e7d
0x6d9e78: 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x6d9e7b: eb03                             jmp    0x6d9e80
0x6d9e7d: 8d4304                           lea    eax,[ebx+0x4]
0x6d9e80: 8b4b20                           mov    ecx,DWORD PTR [ebx+0x20]
0x6d9e83: 8b16                             mov    edx,DWORD PTR [esi]
0x6d9e85: 8b5214                           mov    edx,DWORD PTR [edx+0x14]
0x6d9e88: 51                               push   ecx
0x6d9e89: 50                               push   eax
0x6d9e8a: 8bce                             mov    ecx,esi
0x6d9e8c: ffd2                             call   edx
0x6d9e8e: 85c0                             test   eax,eax
0x6d9e90: 784c                             js     0x6d9ede
0x6d9e92: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x6d9e95: 80782500                         cmp    BYTE PTR [eax+0x25],0x0
0x6d9e99: 7412                             je     0x6d9ead
0x6d9e9b: 0fbf4b24                         movsx  ecx,WORD PTR [ebx+0x24]
0x6d9e9f: 894d0c                           mov    DWORD PTR [ebp+0xc],ecx
0x6d9ea2: db450c                           fild   DWORD PTR [ebp+0xc]
0x6d9ea5: dc0d7056c500                     fmul   QWORD PTR ds:0xc55670
0x6d9eab: eb0a                             jmp    0x6d9eb7
0x6d9ead: 0fbf5324                         movsx  edx,WORD PTR [ebx+0x24]
0x6d9eb1: 89550c                           mov    DWORD PTR [ebp+0xc],edx
0x6d9eb4: db450c                           fild   DWORD PTR [ebp+0xc]
0x6d9eb7: 8b3e                             mov    edi,DWORD PTR [esi]
0x6d9eb9: e8524e2200                       call   0x8fed10
0x6d9ebe: 50                               push   eax
0x6d9ebf: 8b4748                           mov    eax,DWORD PTR [edi+0x48]
0x6d9ec2: 8bce                             mov    ecx,esi
0x6d9ec4: ffd0                             call   eax
0x6d9ec6: d9e8                             fld1
0x6d9ec8: 8b16                             mov    edx,DWORD PTR [esi]
0x6d9eca: 8b424c                           mov    eax,DWORD PTR [edx+0x4c]
0x6d9ecd: 51                               push   ecx
0x6d9ece: 8bce                             mov    ecx,esi
0x6d9ed0: d91c24                           fstp   DWORD PTR [esp]
0x6d9ed3: ffd0                             call   eax
0x6d9ed5: 5f                               pop    edi
0x6d9ed6: 8933                             mov    DWORD PTR [ebx],esi
0x6d9ed8: 5e                               pop    esi
0x6d9ed9: 5b                               pop    ebx
0x6d9eda: 5d                               pop    ebp
0x6d9edb: c20800                           ret    0x8
0x6d9ede: 6a00                             push   0x0
0x6d9ee0: 687523bf00                       push   0xbf2375
0x6d9ee5: 8d4b04                           lea    ecx,[ebx+0x4]
0x6d9ee8: e8838bd2ff                       call   0x402a70
0x6d9eed: c70300000000                     mov    DWORD PTR [ebx],0x0
0x6d9ef3: 5f                               pop    edi
0x6d9ef4: 5e                               pop    esi
0x6d9ef5: 5b                               pop    ebx
0x6d9ef6: 5d                               pop    ebp
0x6d9ef7: c20800                           ret    0x8

## F-80C8A0 VA 0x80c8a0..0x80c949 raw 0x40bca0 len 169 SHA256 a3dee818abacf16063bc4ac7c98c8af5f5c5341871f4a9fcaced63574a26c289
0x80c8a0: 33c0                             xor    eax,eax
0x80c8a2: a3e016fc00                       mov    ds:0xfc16e0,eax
0x80c8a7: a3a016fc00                       mov    ds:0xfc16a0,eax
0x80c8ac: a3a416fc00                       mov    ds:0xfc16a4,eax
0x80c8b1: a3a816fc00                       mov    ds:0xfc16a8,eax
0x80c8b6: a3ac16fc00                       mov    ds:0xfc16ac,eax
0x80c8bb: a3b016fc00                       mov    ds:0xfc16b0,eax
0x80c8c0: a3b416fc00                       mov    ds:0xfc16b4,eax
0x80c8c5: a3b816fc00                       mov    ds:0xfc16b8,eax
0x80c8ca: a3bc16fc00                       mov    ds:0xfc16bc,eax
0x80c8cf: a3c016fc00                       mov    ds:0xfc16c0,eax
0x80c8d4: a3c416fc00                       mov    ds:0xfc16c4,eax
0x80c8d9: a3c816fc00                       mov    ds:0xfc16c8,eax
0x80c8de: a3cc16fc00                       mov    ds:0xfc16cc,eax
0x80c8e3: a3d016fc00                       mov    ds:0xfc16d0,eax
0x80c8e8: a3d416fc00                       mov    ds:0xfc16d4,eax
0x80c8ed: a3d816fc00                       mov    ds:0xfc16d8,eax
0x80c8f2: a3dc16fc00                       mov    ds:0xfc16dc,eax
0x80c8f7: a3e416fc00                       mov    ds:0xfc16e4,eax
0x80c8fc: b8a016fc00                       mov    eax,0xfc16a0
0x80c901: c3                               ret
0x80c902: cc                               int3
0x80c903: cc                               int3
0x80c904: cc                               int3
0x80c905: cc                               int3
0x80c906: cc                               int3
0x80c907: cc                               int3
0x80c908: cc                               int3
0x80c909: cc                               int3
0x80c90a: cc                               int3
0x80c90b: cc                               int3
0x80c90c: cc                               int3
0x80c90d: cc                               int3
0x80c90e: cc                               int3
0x80c90f: cc                               int3
0x80c910: 56                               push   esi
0x80c911: 686819c500                       push   0xc51968
0x80c916: 688419c500                       push   0xc51984
0x80c91b: e89d670800                       call   0x8930bd
0x80c920: 83c408                           add    esp,0x8
0x80c923: bea016fc00                       mov    esi,0xfc16a0
0x80c928: 8b0e                             mov    ecx,DWORD PTR [esi]
0x80c92a: 85c9                             test   ecx,ecx
0x80c92c: 740e                             je     0x80c93c
0x80c92e: 8b01                             mov    eax,DWORD PTR [ecx]
0x80c930: 8b10                             mov    edx,DWORD PTR [eax]
0x80c932: 6a01                             push   0x1
0x80c934: ffd2                             call   edx
0x80c936: c70600000000                     mov    DWORD PTR [esi],0x0
0x80c93c: 83c604                           add    esi,0x4
0x80c93f: 81fee016fc00                     cmp    esi,0xfc16e0
0x80c945: 7ce1                             jl     0x80c928
0x80c947: 5e                               pop    esi
0x80c948: c3                               ret

## F-80C950 VA 0x80c950..0x80ca05 raw 0x40bd50 len 181 SHA256 8e67438c4682e771eec3f786e71a53811ce747420ff1e6e76ef18b901843ca68
0x80c950: 55                               push   ebp
0x80c951: 8bec                             mov    ebp,esp
0x80c953: 51                               push   ecx
0x80c954: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x80c957: 57                               push   edi
0x80c958: 33ff                             xor    edi,edi
0x80c95a: 397844                           cmp    DWORD PTR [eax+0x44],edi
0x80c95d: 0f8596000000                     jne    0x80c9f9
0x80c963: 53                               push   ebx
0x80c964: 56                               push   esi
0x80c965: 33db                             xor    ebx,ebx
0x80c967: 897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x80c96a: 8d9b00000000                     lea    ebx,[ebx+0x0]
0x80c970: 6a40                             push   0x40
0x80c972: e8f1480800                       call   0x891268
0x80c977: 8bf0                             mov    esi,eax
0x80c979: 83c404                           add    esp,0x4
0x80c97c: 3bf7                             cmp    esi,edi
0x80c97e: 7436                             je     0x80c9b6
0x80c980: d9e8                             fld1
0x80c982: 68a00f0000                       push   0xfa0
0x80c987: 8d4e28                           lea    ecx,[esi+0x28]
0x80c98a: d95e24                           fstp   DWORD PTR [esi+0x24]
0x80c98d: 51                               push   ecx
0x80c98e: c706f41bc500                     mov    DWORD PTR [esi],0xc51bf4
0x80c994: 897e04                           mov    DWORD PTR [esi+0x4],edi
0x80c997: 897e08                           mov    DWORD PTR [esi+0x8],edi
0x80c99a: 897e0c                           mov    DWORD PTR [esi+0xc],edi
0x80c99d: 897e10                           mov    DWORD PTR [esi+0x10],edi
0x80c9a0: 897e14                           mov    DWORD PTR [esi+0x14],edi
0x80c9a3: 897e18                           mov    DWORD PTR [esi+0x18],edi
0x80c9a6: 897e1c                           mov    DWORD PTR [esi+0x1c],edi
0x80c9a9: 897e20                           mov    DWORD PTR [esi+0x20],edi
0x80c9ac: ff152c22bd00                     call   DWORD PTR ds:0xbd222c
0x80c9b2: 8bce                             mov    ecx,esi
0x80c9b4: eb02                             jmp    0x80c9b8
0x80c9b6: 33c9                             xor    ecx,ecx
0x80c9b8: 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x80c9bb: 8b75fc                           mov    esi,DWORD PTR [ebp-0x4]
0x80c9be: 890cb2                           mov    DWORD PTR [edx+esi*4],ecx
0x80c9c1: 3bdf                             cmp    ebx,edi
0x80c9c3: 7c13                             jl     0x80c9d8
0x80c9c5: 8b01                             mov    eax,DWORD PTR [ecx]
0x80c9c7: 8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x80c9ca: 8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x80c9cd: 52                               push   edx
0x80c9ce: ffd0                             call   eax
0x80c9d0: 85c0                             test   eax,eax
0x80c9d2: 7804                             js     0x80c9d8
0x80c9d4: 33db                             xor    ebx,ebx
0x80c9d6: eb05                             jmp    0x80c9dd
0x80c9d8: bb05400080                       mov    ebx,0x80004005
0x80c9dd: 46                               inc    esi
0x80c9de: 8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x80c9e1: 83fe10                           cmp    esi,0x10
0x80c9e4: 7c8a                             jl     0x80c970
0x80c9e6: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x80c9e9: 8b08                             mov    ecx,DWORD PTR [eax]
0x80c9eb: 5e                               pop    esi
0x80c9ec: 894844                           mov    DWORD PTR [eax+0x44],ecx
0x80c9ef: 8bc3                             mov    eax,ebx
0x80c9f1: 5b                               pop    ebx
0x80c9f2: 5f                               pop    edi
0x80c9f3: 8be5                             mov    esp,ebp
0x80c9f5: 5d                               pop    ebp
0x80c9f6: c20800                           ret    0x8
0x80c9f9: b805400080                       mov    eax,0x80004005
0x80c9fe: 5f                               pop    edi
0x80c9ff: 8be5                             mov    esp,ebp
0x80ca01: 5d                               pop    ebp
0x80ca02: c20800                           ret    0x8

## F-80EB30 VA 0x80eb30..0x80eb8b raw 0x40df30 len 91 SHA256 36a04fb710767747e92344df94aff52b2dc5d42a76001832143d49f63cc7f25f
0x80eb30: 56                               push   esi
0x80eb31: 8bf1                             mov    esi,ecx
0x80eb33: 837e0800                         cmp    DWORD PTR [esi+0x8],0x0
0x80eb37: c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x80eb3e: 7412                             je     0x80eb52
0x80eb40: 57                               push   edi
0x80eb41: 8b3d0423bd00                     mov    edi,DWORD PTR ds:0xbd2304
0x80eb47: 6a0a                             push   0xa
0x80eb49: ffd7                             call   edi
0x80eb4b: 837e0800                         cmp    DWORD PTR [esi+0x8],0x0
0x80eb4f: 75f6                             jne    0x80eb47
0x80eb51: 5f                               pop    edi
0x80eb52: 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x80eb55: c7461800000000                   mov    DWORD PTR [esi+0x18],0x0
0x80eb5c: 8b01                             mov    eax,DWORD PTR [ecx]
0x80eb5e: 8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x80eb61: ffd2                             call   edx
0x80eb63: 8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
0x80eb66: 85c9                             test   ecx,ecx
0x80eb68: 741d                             je     0x80eb87
0x80eb6a: 8b01                             mov    eax,DWORD PTR [ecx]
0x80eb6c: 8b10                             mov    edx,DWORD PTR [eax]
0x80eb6e: ffd2                             call   edx
0x80eb70: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x80eb73: 85c0                             test   eax,eax
0x80eb75: 7410                             je     0x80eb87
0x80eb77: 50                               push   eax
0x80eb78: e88f260800                       call   0x89120c
0x80eb7d: 83c404                           add    esp,0x4
0x80eb80: c7461000000000                   mov    DWORD PTR [esi+0x10],0x0
0x80eb87: 33c0                             xor    eax,eax
0x80eb89: 5e                               pop    esi
0x80eb8a: c3                               ret

## F-80E750 VA 0x80e750..0x80e7a0 raw 0x40db50 len 80 SHA256 2ef78eff49146ad7f9d44794fd4da54dc7bac06d8717fe056b02c6f0ac4b67e4
0x80e750: 56                               push   esi
0x80e751: 682c000200                       push   0x2002c
0x80e756: 8bf1                             mov    esi,ecx
0x80e758: e80b2b0800                       call   0x891268
0x80e75d: 33c9                             xor    ecx,ecx
0x80e75f: 83c404                           add    esp,0x4
0x80e762: 3bc1                             cmp    eax,ecx
0x80e764: 7431                             je     0x80e797
0x80e766: c700ec1ec500                     mov    DWORD PTR [eax],0xc51eec
0x80e76c: 894804                           mov    DWORD PTR [eax+0x4],ecx
0x80e76f: 894810                           mov    DWORD PTR [eax+0x10],ecx
0x80e772: c7801800020000000200             mov    DWORD PTR [eax+0x20018],0x20000
0x80e77c: 89881c000200                     mov    DWORD PTR [eax+0x2001c],ecx
0x80e782: 898824000200                     mov    DWORD PTR [eax+0x20024],ecx
0x80e788: 898828000200                     mov    DWORD PTR [eax+0x20028],ecx
0x80e78e: 894614                           mov    DWORD PTR [esi+0x14],eax
0x80e791: 33c0                             xor    eax,eax
0x80e793: 5e                               pop    esi
0x80e794: c20400                           ret    0x4
0x80e797: 894e14                           mov    DWORD PTR [esi+0x14],ecx
0x80e79a: 33c0                             xor    eax,eax
0x80e79c: 5e                               pop    esi
0x80e79d: c20400                           ret    0x4

## F-80E940 VA 0x80e940..0x80ea1e raw 0x40dd40 len 222 SHA256 1d48573b53dbabb6829c2dd82310fd43cf7d5ce05ea2957cc5bc768ddcc35e7f
0x80e940: 55                               push   ebp
0x80e941: 8bec                             mov    ebp,esp
0x80e943: 53                               push   ebx
0x80e944: 33db                             xor    ebx,ebx
0x80e946: 56                               push   esi
0x80e947: 8bf1                             mov    esi,ecx
0x80e949: 395d08                           cmp    DWORD PTR [ebp+0x8],ebx
0x80e94c: 750b                             jne    0x80e959
0x80e94e: 5e                               pop    esi
0x80e94f: b857000780                       mov    eax,0x80070057
0x80e954: 5b                               pop    ebx
0x80e955: 5d                               pop    ebp
0x80e956: c20800                           ret    0x8
0x80e959: 395e14                           cmp    DWORD PTR [esi+0x14],ebx
0x80e95c: 750b                             jne    0x80e969
0x80e95e: 5e                               pop    esi
0x80e95f: b801400080                       mov    eax,0x80004001
0x80e964: 5b                               pop    ebx
0x80e965: 5d                               pop    ebp
0x80e966: c20800                           ret    0x8
0x80e969: 8b06                             mov    eax,DWORD PTR [esi]
0x80e96b: 8b502c                           mov    edx,DWORD PTR [eax+0x2c]
0x80e96e: 57                               push   edi
0x80e96f: ffd2                             call   edx
0x80e971: 8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x80e974: 6a20                             push   0x20
0x80e976: 89461c                           mov    DWORD PTR [esi+0x1c],eax
0x80e979: e8ea280800                       call   0x891268
0x80e97e: 83c404                           add    esp,0x4
0x80e981: 3bc3                             cmp    eax,ebx
0x80e983: 7416                             je     0x80e99b
0x80e985: c700401fc500                     mov    DWORD PTR [eax],0xc51f40
0x80e98b: 895810                           mov    DWORD PTR [eax+0x10],ebx
0x80e98e: 895814                           mov    DWORD PTR [eax+0x14],ebx
0x80e991: 895818                           mov    DWORD PTR [eax+0x18],ebx
0x80e994: 89581c                           mov    DWORD PTR [eax+0x1c],ebx
0x80e997: 8bf8                             mov    edi,eax
0x80e999: eb02                             jmp    0x80e99d
0x80e99b: 33ff                             xor    edi,edi
0x80e99d: 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x80e9a0: 8bcf                             mov    ecx,edi
0x80e9a2: e8691d0000                       call   0x810710
0x80e9a7: 85c0                             test   eax,eax
0x80e9a9: 751f                             jne    0x80e9ca
0x80e9ab: 3bfb                             cmp    edi,ebx
0x80e9ad: 740f                             je     0x80e9be
0x80e9af: 57                               push   edi
0x80e9b0: c707401fc500                     mov    DWORD PTR [edi],0xc51f40
0x80e9b6: e851280800                       call   0x89120c
0x80e9bb: 83c404                           add    esp,0x4
0x80e9be: 5f                               pop    edi
0x80e9bf: 5e                               pop    esi
0x80e9c0: b857000780                       mov    eax,0x80070057
0x80e9c5: 5b                               pop    ebx
0x80e9c6: 5d                               pop    ebp
0x80e9c7: c20800                           ret    0x8
0x80e9ca: 8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x80e9cd: 897e10                           mov    DWORD PTR [esi+0x10],edi
0x80e9d0: 8b17                             mov    edx,DWORD PTR [edi]
0x80e9d2: 8b5208                           mov    edx,DWORD PTR [edx+0x8]
0x80e9d5: 50                               push   eax
0x80e9d6: 8bcf                             mov    ecx,edi
0x80e9d8: ffd2                             call   edx
0x80e9da: 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x80e9dd: 8b01                             mov    eax,DWORD PTR [ecx]
0x80e9df: 8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x80e9e2: 57                               push   edi
0x80e9e3: ffd2                             call   edx
0x80e9e5: 85c0                             test   eax,eax
0x80e9e7: 7429                             je     0x80ea12
0x80e9e9: 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x80e9ec: 8b01                             mov    eax,DWORD PTR [ecx]
0x80e9ee: 8b500c                           mov    edx,DWORD PTR [eax+0xc]
0x80e9f1: ffd2                             call   edx
0x80e9f3: 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x80e9f6: 8b01                             mov    eax,DWORD PTR [ecx]
0x80e9f8: 8b5010                           mov    edx,DWORD PTR [eax+0x10]
0x80e9fb: ffd2                             call   edx
0x80e9fd: c7461801000000                   mov    DWORD PTR [esi+0x18],0x1
0x80ea04: e8c7feffff                       call   0x80e8d0
0x80ea09: 5f                               pop    edi
0x80ea0a: 5e                               pop    esi
0x80ea0b: 33c0                             xor    eax,eax
0x80ea0d: 5b                               pop    ebx
0x80ea0e: 5d                               pop    ebp
0x80ea0f: c20800                           ret    0x8
0x80ea12: 5f                               pop    edi
0x80ea13: 5e                               pop    esi
0x80ea14: b805400080                       mov    eax,0x80004005
0x80ea19: 5b                               pop    ebx
0x80ea1a: 5d                               pop    ebp
0x80ea1b: c20800                           ret    0x8

## F-80FED0 VA 0x80fed0..0x80ff3e raw 0x40f2d0 len 110 SHA256 6ca91115eb4454b4bfef2b4d7b467acbbc32a3f16984628b44d70142c609f2a9
0x80fed0: 56                               push   esi
0x80fed1: 8bf1                             mov    esi,ecx
0x80fed3: 837e0400                         cmp    DWORD PTR [esi+0x4],0x0
0x80fed7: 7463                             je     0x80ff3c
0x80fed9: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x80fedc: 57                               push   edi
0x80fedd: 8d7e10                           lea    edi,[esi+0x10]
0x80fee0: 50                               push   eax
0x80fee1: ff15b023bd00                     call   DWORD PTR ds:0xbd23b0
0x80fee7: 83c404                           add    esp,0x4
0x80feea: e891010000                       call   0x810080
0x80feef: 56                               push   esi
0x80fef0: e8bb000000                       call   0x80ffb0
0x80fef5: 57                               push   edi
0x80fef6: 6a01                             push   0x1
0x80fef8: ff15b423bd00                     call   DWORD PTR ds:0xbd23b4
0x80fefe: 83c408                           add    esp,0x8
0x80ff01: e87a010000                       call   0x810080
0x80ff06: 8d4e08                           lea    ecx,[esi+0x8]
0x80ff09: 51                               push   ecx
0x80ff0a: 6a02                             push   0x2
0x80ff0c: ff15b823bd00                     call   DWORD PTR ds:0xbd23b8
0x80ff12: 83c408                           add    esp,0x8
0x80ff15: e866010000                       call   0x810080
0x80ff1a: c70700000000                     mov    DWORD PTR [edi],0x0
0x80ff20: c7862400020000000000             mov    DWORD PTR [esi+0x20024],0x0
0x80ff2a: c7862800020000000000             mov    DWORD PTR [esi+0x20028],0x0
0x80ff34: c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x80ff3b: 5f                               pop    edi
0x80ff3c: 5e                               pop    esi
0x80ff3d: c3                               ret

## F-8109A0 VA 0x8109a0..0x8109c2 raw 0x40fda0 len 34 SHA256 afcf46147071a176d1cd6329bc4a5c36b31852b25d3dde88144a7cd40065e84f
0x8109a0: 56                               push   esi
0x8109a1: 8bf1                             mov    esi,ecx
0x8109a3: 8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x8109a6: 50                               push   eax
0x8109a7: ff15c026bd00                     call   DWORD PTR ds:0xbd26c0
0x8109ad: 8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x8109b0: 51                               push   ecx
0x8109b1: e856080800                       call   0x89120c
0x8109b6: 83c408                           add    esp,0x8
0x8109b9: c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x8109c0: 5e                               pop    esi
0x8109c1: c3                               ret

## F-89231A VA 0x89231a..0x892331 raw 0x49171a len 23 SHA256 402145936f1b92f6ca01a0d3a60e9f163d31a62016b1f9742a22ffaf7610f9c6
0x89231a: 8bff                             mov    edi,edi
0x89231c: 55                               push   ebp
0x89231d: 8bec                             mov    ebp,esp
0x89231f: ff7508                           push   DWORD PTR [ebp+0x8]
0x892322: e8b7ffffff                       call   0x8922de
0x892327: f7d8                             neg    eax
0x892329: 1bc0                             sbb    eax,eax
0x89232b: f7d8                             neg    eax
0x89232d: 59                               pop    ecx
0x89232e: 48                               dec    eax
0x89232f: 5d                               pop    ebp
0x892330: c3                               ret

## F-8922DE VA 0x8922de..0x892314 raw 0x4916de len 54 SHA256 107dbf985d4e540f2f04f0f968c7f581195df34039543b310085424a77bf58f0
0x8922de: 6a0c                             push   0xc
0x8922e0: 68f04cc800                       push   0xc84cf0
0x8922e5: e846e80000                       call   0x8a0b30
0x8922ea: e884140000                       call   0x893773
0x8922ef: 8365fc00                         and    DWORD PTR [ebp-0x4],0x0
0x8922f3: ff7508                           push   DWORD PTR [ebp+0x8]
0x8922f6: e8fcfeffff                       call   0x8921f7
0x8922fb: 59                               pop    ecx
0x8922fc: 8945e4                           mov    DWORD PTR [ebp-0x1c],eax
0x8922ff: c745fcfeffffff                   mov    DWORD PTR [ebp-0x4],0xfffffffe
0x892306: e809000000                       call   0x892314
0x89230b: 8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
0x89230e: e862e80000                       call   0x8a0b75
0x892313: c3                               ret

## F-8921F7 VA 0x8921f7..0x8922de raw 0x4915f7 len 231 SHA256 87a7bcb14fdfb58035fc6e0922596f7e68b55ba6962c5b1949f9f25357711376
0x8921f7: 8bff                             mov    edi,edi
0x8921f9: 55                               push   ebp
0x8921fa: 8bec                             mov    ebp,esp
0x8921fc: 51                               push   ecx
0x8921fd: 53                               push   ebx
0x8921fe: 56                               push   esi
0x8921ff: 8b355822bd00                     mov    esi,DWORD PTR ds:0xbd2258
0x892205: 57                               push   edi
0x892206: ff35cc83fe00                     push   DWORD PTR ds:0xfe83cc
0x89220c: ffd6                             call   esi
0x89220e: ff35c883fe00                     push   DWORD PTR ds:0xfe83c8
0x892214: 8bd8                             mov    ebx,eax
0x892216: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x892219: ffd6                             call   esi
0x89221b: 8bf0                             mov    esi,eax
0x89221d: 3bf3                             cmp    esi,ebx
0x89221f: 0f8281000000                     jb     0x8922a6
0x892225: 8bfe                             mov    edi,esi
0x892227: 2bfb                             sub    edi,ebx
0x892229: 8d4704                           lea    eax,[edi+0x4]
0x89222c: 83f804                           cmp    eax,0x4
0x89222f: 7275                             jb     0x8922a6
0x892231: 53                               push   ebx
0x892232: e8191a0100                       call   0x8a3c50
0x892237: 8bd8                             mov    ebx,eax
0x892239: 8d4704                           lea    eax,[edi+0x4]
0x89223c: 59                               pop    ecx
0x89223d: 3bd8                             cmp    ebx,eax
0x89223f: 7348                             jae    0x892289
0x892241: b800080000                       mov    eax,0x800
0x892246: 3bd8                             cmp    ebx,eax
0x892248: 7302                             jae    0x89224c
0x89224a: 8bc3                             mov    eax,ebx
0x89224c: 03c3                             add    eax,ebx
0x89224e: 3bc3                             cmp    eax,ebx
0x892250: 720f                             jb     0x892261
0x892252: 50                               push   eax
0x892253: ff75fc                           push   DWORD PTR [ebp-0x4]
0x892256: e801be0000                       call   0x89e05c
0x89225b: 59                               pop    ecx
0x89225c: 59                               pop    ecx
0x89225d: 85c0                             test   eax,eax
0x89225f: 7516                             jne    0x892277
0x892261: 8d4310                           lea    eax,[ebx+0x10]
0x892264: 3bc3                             cmp    eax,ebx
0x892266: 723e                             jb     0x8922a6
0x892268: 50                               push   eax
0x892269: ff75fc                           push   DWORD PTR [ebp-0x4]
0x89226c: e8ebbd0000                       call   0x89e05c
0x892271: 59                               pop    ecx
0x892272: 59                               pop    ecx
0x892273: 85c0                             test   eax,eax
0x892275: 742f                             je     0x8922a6
0x892277: c1ff02                           sar    edi,0x2
0x89227a: 50                               push   eax
0x89227b: 8d34b8                           lea    esi,[eax+edi*4]
0x89227e: ff155c22bd00                     call   DWORD PTR ds:0xbd225c
0x892284: a3cc83fe00                       mov    ds:0xfe83cc,eax
0x892289: ff7508                           push   DWORD PTR [ebp+0x8]
0x89228c: 8b3d5c22bd00                     mov    edi,DWORD PTR ds:0xbd225c
0x892292: ffd7                             call   edi
0x892294: 8906                             mov    DWORD PTR [esi],eax
0x892296: 83c604                           add    esi,0x4
0x892299: 56                               push   esi
0x89229a: ffd7                             call   edi
0x89229c: a3c883fe00                       mov    ds:0xfe83c8,eax
0x8922a1: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x8922a4: eb02                             jmp    0x8922a8
0x8922a6: 33c0                             xor    eax,eax
0x8922a8: 5f                               pop    edi
0x8922a9: 5e                               pop    esi
0x8922aa: 5b                               pop    ebx
0x8922ab: c9                               leave
0x8922ac: c3                               ret
0x8922ad: 8bff                             mov    edi,edi
0x8922af: 56                               push   esi
0x8922b0: 6a04                             push   0x4
0x8922b2: 6a20                             push   0x20
0x8922b4: e857bd0000                       call   0x89e010
0x8922b9: 59                               pop    ecx
0x8922ba: 59                               pop    ecx
0x8922bb: 8bf0                             mov    esi,eax
0x8922bd: 56                               push   esi
0x8922be: ff155c22bd00                     call   DWORD PTR ds:0xbd225c
0x8922c4: a3cc83fe00                       mov    ds:0xfe83cc,eax
0x8922c9: a3c883fe00                       mov    ds:0xfe83c8,eax
0x8922ce: 85f6                             test   esi,esi
0x8922d0: 7505                             jne    0x8922d7
0x8922d2: 6a18                             push   0x18
0x8922d4: 58                               pop    eax
0x8922d5: 5e                               pop    esi
0x8922d6: c3                               ret
0x8922d7: 832600                           and    DWORD PTR [esi],0x0
0x8922da: 33c0                             xor    eax,eax
0x8922dc: 5e                               pop    esi
0x8922dd: c3                               ret

## F-892314 VA 0x892314..0x89231a raw 0x491714 len 6 SHA256 eff24491f6bb91d05782a7a953ffcda96043da56ec4ec5dfe6e23ae7bd716bd4
0x892314: e863140000                       call   0x89377c
0x892319: c3                               ret

## F-893773 VA 0x893773..0x89377c raw 0x492b73 len 9 SHA256 1c371a1cc748929d0175e0efef0ad39a7891c028d5150962855b3a7d4ce00036
0x893773: 6a08                             push   0x8
0x893775: e8dd3a0100                       call   0x8a7257
0x89377a: 59                               pop    ecx
0x89377b: c3                               ret

## F-89377C VA 0x89377c..0x893785 raw 0x492b7c len 9 SHA256 75a815dd4ae137456801fc76c0d1868e01a1bc07bdd9e2ae2f2bd724f36b5a4d
0x89377c: 6a08                             push   0x8
0x89377e: e8fb390100                       call   0x8a717e
0x893783: 59                               pop    ecx
0x893784: c3                               ret

## F-8A7257 VA 0x8a7257..0x8a728a raw 0x4a6657 len 51 SHA256 499f7fd07ab7f5629e93b687b51bc99bce3d73a18593e1ec4c9b5892aac5bd3f
0x8a7257: 8bff                             mov    edi,edi
0x8a7259: 55                               push   ebp
0x8a725a: 8bec                             mov    ebp,esp
0x8a725c: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x8a725f: 56                               push   esi
0x8a7260: 8d34c58828d600                   lea    esi,[eax*8+0xd62888]
0x8a7267: 833e00                           cmp    DWORD PTR [esi],0x0
0x8a726a: 7513                             jne    0x8a727f
0x8a726c: 50                               push   eax
0x8a726d: e823ffffff                       call   0x8a7195
0x8a7272: 59                               pop    ecx
0x8a7273: 85c0                             test   eax,eax
0x8a7275: 7508                             jne    0x8a727f
0x8a7277: 6a11                             push   0x11
0x8a7279: e87fc7feff                       call   0x8939fd
0x8a727e: 59                               pop    ecx
0x8a727f: ff36                             push   DWORD PTR [esi]
0x8a7281: ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x8a7287: 5e                               pop    esi
0x8a7288: 5d                               pop    ebp
0x8a7289: c3                               ret

## F-8A7195 VA 0x8a7195..0x8a724e raw 0x4a6595 len 185 SHA256 1809312b96c97fb5c42c515af4c75d49183b6fc340555922cf4e52516bc2efb9
0x8a7195: 6a0c                             push   0xc
0x8a7197: 685855c800                       push   0xc85558
0x8a719c: e88f99ffff                       call   0x8a0b30
0x8a71a1: 33ff                             xor    edi,edi
0x8a71a3: 47                               inc    edi
0x8a71a4: 897de4                           mov    DWORD PTR [ebp-0x1c],edi
0x8a71a7: 33db                             xor    ebx,ebx
0x8a71a9: 391ddcd4f800                     cmp    DWORD PTR ds:0xf8d4dc,ebx
0x8a71af: 7518                             jne    0x8a71c9
0x8a71b1: e8f3c7ffff                       call   0x8a39a9
0x8a71b6: 6a1e                             push   0x1e
0x8a71b8: e83dc6ffff                       call   0x8a37fa
0x8a71bd: 68ff000000                       push   0xff
0x8a71c2: e894c5feff                       call   0x89375b
0x8a71c7: 59                               pop    ecx
0x8a71c8: 59                               pop    ecx
0x8a71c9: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x8a71cc: 8d34f58828d600                   lea    esi,[esi*8+0xd62888]
0x8a71d3: 391e                             cmp    DWORD PTR [esi],ebx
0x8a71d5: 7404                             je     0x8a71db
0x8a71d7: 8bc7                             mov    eax,edi
0x8a71d9: eb6d                             jmp    0x8a7248
0x8a71db: 6a18                             push   0x18
0x8a71dd: e8e96dffff                       call   0x89dfcb
0x8a71e2: 59                               pop    ecx
0x8a71e3: 8bf8                             mov    edi,eax
0x8a71e5: 3bfb                             cmp    edi,ebx
0x8a71e7: 750f                             jne    0x8a71f8
0x8a71e9: e8fa14ffff                       call   0x8986e8
0x8a71ee: c7000c000000                     mov    DWORD PTR [eax],0xc
0x8a71f4: 33c0                             xor    eax,eax
0x8a71f6: eb50                             jmp    0x8a7248
0x8a71f8: 6a0a                             push   0xa
0x8a71fa: e858000000                       call   0x8a7257
0x8a71ff: 59                               pop    ecx
0x8a7200: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x8a7203: 391e                             cmp    DWORD PTR [esi],ebx
0x8a7205: 752b                             jne    0x8a7232
0x8a7207: 68a00f0000                       push   0xfa0
0x8a720c: 57                               push   edi
0x8a720d: ff152c22bd00                     call   DWORD PTR ds:0xbd222c
0x8a7213: 85c0                             test   eax,eax
0x8a7215: 7517                             jne    0x8a722e
0x8a7217: 57                               push   edi
0x8a7218: e8dfaefeff                       call   0x8920fc
0x8a721d: 59                               pop    ecx
0x8a721e: e8c514ffff                       call   0x8986e8
0x8a7223: c7000c000000                     mov    DWORD PTR [eax],0xc
0x8a7229: 895de4                           mov    DWORD PTR [ebp-0x1c],ebx
0x8a722c: eb0b                             jmp    0x8a7239
0x8a722e: 893e                             mov    DWORD PTR [esi],edi
0x8a7230: eb07                             jmp    0x8a7239
0x8a7232: 57                               push   edi
0x8a7233: e8c4aefeff                       call   0x8920fc
0x8a7238: 59                               pop    ecx
0x8a7239: c745fcfeffffff                   mov    DWORD PTR [ebp-0x4],0xfffffffe
0x8a7240: e809000000                       call   0x8a724e
0x8a7245: 8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
0x8a7248: e82899ffff                       call   0x8a0b75
0x8a724d: c3                               ret

## F-8A717E VA 0x8a717e..0x8a7195 raw 0x4a657e len 23 SHA256 32cf27fb26e4e9d24357a28a3c7d17026f2232e0f410d2f6f3125dbd1a4ee654
0x8a717e: 8bff                             mov    edi,edi
0x8a7180: 55                               push   ebp
0x8a7181: 8bec                             mov    ebp,esp
0x8a7183: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x8a7186: ff34c58828d600                   push   DWORD PTR [eax*8+0xd62888]
0x8a718d: ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x8a7193: 5d                               pop    ebp
0x8a7194: c3                               ret

## F-8A0B30 VA 0x8a0b30..0x8a0b75 raw 0x49ff30 len 69 SHA256 263a35019eaadef49b3cb93e10674d8e219c47e5b4cdb3c8c738f726e53938e4
0x8a0b30: 6820038a00                       push   0x8a0320
0x8a0b35: 64ff3500000000                   push   DWORD PTR fs:0x0
0x8a0b3c: 8b442410                         mov    eax,DWORD PTR [esp+0x10]
0x8a0b40: 896c2410                         mov    DWORD PTR [esp+0x10],ebp
0x8a0b44: 8d6c2410                         lea    ebp,[esp+0x10]
0x8a0b48: 2be0                             sub    esp,eax
0x8a0b4a: 53                               push   ebx
0x8a0b4b: 56                               push   esi
0x8a0b4c: 57                               push   edi
0x8a0b4d: a1201fd600                       mov    eax,ds:0xd61f20
0x8a0b52: 3145fc                           xor    DWORD PTR [ebp-0x4],eax
0x8a0b55: 33c5                             xor    eax,ebp
0x8a0b57: 50                               push   eax
0x8a0b58: 8965e8                           mov    DWORD PTR [ebp-0x18],esp
0x8a0b5b: ff75f8                           push   DWORD PTR [ebp-0x8]
0x8a0b5e: 8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x8a0b61: c745fcfeffffff                   mov    DWORD PTR [ebp-0x4],0xfffffffe
0x8a0b68: 8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x8a0b6b: 8d45f0                           lea    eax,[ebp-0x10]
0x8a0b6e: 64a300000000                     mov    fs:0x0,eax
0x8a0b74: c3                               ret

## F-8A0B75 VA 0x8a0b75..0x8a0b89 raw 0x49ff75 len 20 SHA256 39142b8d79823b8b3c0dd534ee99caf6c8cce4347b7608cfc004a14c873f7411
0x8a0b75: 8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x8a0b78: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x8a0b7f: 59                               pop    ecx
0x8a0b80: 5f                               pop    edi
0x8a0b81: 5f                               pop    edi
0x8a0b82: 5e                               pop    esi
0x8a0b83: 5b                               pop    ebx
0x8a0b84: 8be5                             mov    esp,ebp
0x8a0b86: 5d                               pop    ebp
0x8a0b87: 51                               push   ecx
0x8a0b88: c3                               ret

## F-892003 VA 0x892003..0x892050 raw 0x491403 len 77 SHA256 445ff1635d5a64b10c64c5e251d8ed4f8fb3b081c6f97657f81913fd13354220
0x892003: 6a10                             push   0x10
0x892005: 68904cc800                       push   0xc84c90
0x89200a: e821eb0000                       call   0x8a0b30
0x89200f: 33c0                             xor    eax,eax
0x892011: 8945e0                           mov    DWORD PTR [ebp-0x20],eax
0x892014: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x892017: 8945e4                           mov    DWORD PTR [ebp-0x1c],eax
0x89201a: 8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
0x89201d: 3b4510                           cmp    eax,DWORD PTR [ebp+0x10]
0x892020: 7d13                             jge    0x892035
0x892022: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x892025: 8bce                             mov    ecx,esi
0x892027: ff5514                           call   DWORD PTR [ebp+0x14]
0x89202a: 03750c                           add    esi,DWORD PTR [ebp+0xc]
0x89202d: 897508                           mov    DWORD PTR [ebp+0x8],esi
0x892030: ff45e4                           inc    DWORD PTR [ebp-0x1c]
0x892033: ebe5                             jmp    0x89201a
0x892035: c745e001000000                   mov    DWORD PTR [ebp-0x20],0x1
0x89203c: c745fcfeffffff                   mov    DWORD PTR [ebp-0x4],0xfffffffe
0x892043: e808000000                       call   0x892050
0x892048: e828eb0000                       call   0x8a0b75
0x89204d: c21400                           ret    0x14

## F-892050 VA 0x892050..0x892068 raw 0x491450 len 24 SHA256 1ae3bcd793b4c4eb46d280be0797e4cfcafae96ee47b1f8c1634b921339adc4d
0x892050: 837de000                         cmp    DWORD PTR [ebp-0x20],0x0
0x892054: 7511                             jne    0x892067
0x892056: ff7518                           push   DWORD PTR [ebp+0x18]
0x892059: ff75e4                           push   DWORD PTR [ebp-0x1c]
0x89205c: ff750c                           push   DWORD PTR [ebp+0xc]
0x89205f: ff7508                           push   DWORD PTR [ebp+0x8]
0x892062: e8cf000000                       call   0x892136
0x892067: c3                               ret

## F-891268 VA 0x891268..0x8912e7 raw 0x490668 len 127 SHA256 7e9119e2e9a55da358073e806cc8a1e598fad0ac642df17f3baa0d751f41a65d
0x891268: 8bff                             mov    edi,edi
0x89126a: 55                               push   ebp
0x89126b: 8bec                             mov    ebp,esp
0x89126d: 83ec10                           sub    esp,0x10
0x891270: eb0d                             jmp    0x89127f
0x891272: ff7508                           push   DWORD PTR [ebp+0x8]
0x891275: e8fdd60000                       call   0x89e977
0x89127a: 59                               pop    ecx
0x89127b: 85c0                             test   eax,eax
0x89127d: 740f                             je     0x89128e
0x89127f: ff7508                           push   DWORD PTR [ebp+0x8]
0x891282: e8e10d0000                       call   0x892068
0x891287: 59                               pop    ecx
0x891288: 85c0                             test   eax,eax
0x89128a: 74e6                             je     0x891272
0x89128c: c9                               leave
0x89128d: c3                               ret
0x89128e: f605c0caf80001                   test   BYTE PTR ds:0xf8cac0,0x1
0x891295: bfb4caf800                       mov    edi,0xf8cab4
0x89129a: bea42cbd00                       mov    esi,0xbd2ca4
0x89129f: 752c                             jne    0x8912cd
0x8912a1: 830dc0caf80001                   or     DWORD PTR ds:0xf8cac0,0x1
0x8912a8: 6a01                             push   0x1
0x8912aa: 8d45fc                           lea    eax,[ebp-0x4]
0x8912ad: 50                               push   eax
0x8912ae: 8bcf                             mov    ecx,edi
0x8912b0: c745fcb011c400                   mov    DWORD PTR [ebp-0x4],0xc411b0
0x8912b7: e865fdffff                       call   0x891021
0x8912bc: 68dc11bd00                       push   0xbd11dc
0x8912c1: 8935b4caf800                     mov    DWORD PTR ds:0xf8cab4,esi
0x8912c7: e84e100000                       call   0x89231a
0x8912cc: 59                               pop    ecx
0x8912cd: 57                               push   edi
0x8912ce: 8d4df0                           lea    ecx,[ebp-0x10]
0x8912d1: e893feffff                       call   0x891169
0x8912d6: 68a857c800                       push   0xc857a8
0x8912db: 8d45f0                           lea    eax,[ebp-0x10]
0x8912de: 50                               push   eax
0x8912df: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x8912e2: e809b70000                       call   0x89c9f0

## F-892068 VA 0x892068..0x8920fc raw 0x491468 len 148 SHA256 e73b67a8ad3e73d4b8d74f38ea60efbc19a1636e5b324c47d3d4f741463ee6b3
0x892068: 8bff                             mov    edi,edi
0x89206a: 55                               push   ebp
0x89206b: 8bec                             mov    ebp,esp
0x89206d: 53                               push   ebx
0x89206e: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x892071: 83fbe0                           cmp    ebx,0xffffffe0
0x892074: 776f                             ja     0x8920e5
0x892076: 56                               push   esi
0x892077: 57                               push   edi
0x892078: 833ddcd4f80000                   cmp    DWORD PTR ds:0xf8d4dc,0x0
0x89207f: 7518                             jne    0x892099
0x892081: e823190100                       call   0x8a39a9
0x892086: 6a1e                             push   0x1e
0x892088: e86d170100                       call   0x8a37fa
0x89208d: 68ff000000                       push   0xff
0x892092: e8c4160000                       call   0x89375b
0x892097: 59                               pop    ecx
0x892098: 59                               pop    ecx
0x892099: 85db                             test   ebx,ebx
0x89209b: 7404                             je     0x8920a1
0x89209d: 8bc3                             mov    eax,ebx
0x89209f: eb03                             jmp    0x8920a4
0x8920a1: 33c0                             xor    eax,eax
0x8920a3: 40                               inc    eax
0x8920a4: 50                               push   eax
0x8920a5: 6a00                             push   0x0
0x8920a7: ff35dcd4f800                     push   DWORD PTR ds:0xf8d4dc
0x8920ad: ff151422bd00                     call   DWORD PTR ds:0xbd2214
0x8920b3: 8bf8                             mov    edi,eax
0x8920b5: 85ff                             test   edi,edi
0x8920b7: 7526                             jne    0x8920df
0x8920b9: 6a0c                             push   0xc
0x8920bb: 5e                               pop    esi
0x8920bc: 3905e0d4f800                     cmp    DWORD PTR ds:0xf8d4e0,eax
0x8920c2: 740d                             je     0x8920d1
0x8920c4: 53                               push   ebx
0x8920c5: e8adc80000                       call   0x89e977
0x8920ca: 59                               pop    ecx
0x8920cb: 85c0                             test   eax,eax
0x8920cd: 75a9                             jne    0x892078
0x8920cf: eb07                             jmp    0x8920d8
0x8920d1: e812660000                       call   0x8986e8
0x8920d6: 8930                             mov    DWORD PTR [eax],esi
0x8920d8: e80b660000                       call   0x8986e8
0x8920dd: 8930                             mov    DWORD PTR [eax],esi
0x8920df: 8bc7                             mov    eax,edi
0x8920e1: 5f                               pop    edi
0x8920e2: 5e                               pop    esi
0x8920e3: eb14                             jmp    0x8920f9
0x8920e5: 53                               push   ebx
0x8920e6: e88cc80000                       call   0x89e977
0x8920eb: 59                               pop    ecx
0x8920ec: e8f7650000                       call   0x8986e8
0x8920f1: c7000c000000                     mov    DWORD PTR [eax],0xc
0x8920f7: 33c0                             xor    eax,eax
0x8920f9: 5b                               pop    ebx
0x8920fa: 5d                               pop    ebp
0x8920fb: c3                               ret

## F-89E977 VA 0x89e977..0x89e99f raw 0x49dd77 len 40 SHA256 b875b62d3c63979996d876a54f0d05fcb9e5d894f21bee19e51b4dc547ce1d9a
0x89e977: 8bff                             mov    edi,edi
0x89e979: 55                               push   ebp
0x89e97a: 8bec                             mov    ebp,esp
0x89e97c: ff3578cbf800                     push   DWORD PTR ds:0xf8cb78
0x89e982: ff155822bd00                     call   DWORD PTR ds:0xbd2258
0x89e988: 85c0                             test   eax,eax
0x89e98a: 740f                             je     0x89e99b
0x89e98c: ff7508                           push   DWORD PTR [ebp+0x8]
0x89e98f: ffd0                             call   eax
0x89e991: 59                               pop    ecx
0x89e992: 85c0                             test   eax,eax
0x89e994: 7405                             je     0x89e99b
0x89e996: 33c0                             xor    eax,eax
0x89e998: 40                               inc    eax
0x89e999: 5d                               pop    ebp
0x89e99a: c3                               ret
0x89e99b: 33c0                             xor    eax,eax
0x89e99d: 5d                               pop    ebp
0x89e99e: c3                               ret

## F-89120C VA 0x89120c..0x891217 raw 0x49060c len 11 SHA256 7711cccaa13779fb085299bfe7ee4e5937c3a6ef8286ffc5c31cf2acc38cd336
0x89120c: 8bff                             mov    edi,edi
0x89120e: 55                               push   ebp
0x89120f: 8bec                             mov    ebp,esp
0x891211: 5d                               pop    ebp
0x891212: e9e50e0000                       jmp    0x8920fc

## F-8920FC VA 0x8920fc..0x892136 raw 0x4914fc len 58 SHA256 532702be83b03b38c441a516b09516b9b658bfc3d055e8ff8e90a2ea199b9aa4
0x8920fc: 8bff                             mov    edi,edi
0x8920fe: 55                               push   ebp
0x8920ff: 8bec                             mov    ebp,esp
0x892101: 837d0800                         cmp    DWORD PTR [ebp+0x8],0x0
0x892105: 742d                             je     0x892134
0x892107: ff7508                           push   DWORD PTR [ebp+0x8]
0x89210a: 6a00                             push   0x0
0x89210c: ff35dcd4f800                     push   DWORD PTR ds:0xf8d4dc
0x892112: ff151022bd00                     call   DWORD PTR ds:0xbd2210
0x892118: 85c0                             test   eax,eax
0x89211a: 7518                             jne    0x892134
0x89211c: 56                               push   esi
0x89211d: e8c6650000                       call   0x8986e8
0x892122: 8bf0                             mov    esi,eax
0x892124: ff150023bd00                     call   DWORD PTR ds:0xbd2300
0x89212a: 50                               push   eax
0x89212b: e876650000                       call   0x8986a6
0x892130: 59                               pop    ecx
0x892131: 8906                             mov    DWORD PTR [esi],eax
0x892133: 5e                               pop    esi
0x892134: 5d                               pop    ebp
0x892135: c3                               ret

## F-89E860 VA 0x89e860..0x89e8da raw 0x49dc60 len 122 SHA256 298e89ab34a95ab4ff602b823d146200122d26c74fa2515e82f54bb8d732c7cb
0x89e860: 8b54240c                         mov    edx,DWORD PTR [esp+0xc]
0x89e864: 8b4c2404                         mov    ecx,DWORD PTR [esp+0x4]
0x89e868: 85d2                             test   edx,edx
0x89e86a: 7469                             je     0x89e8d5
0x89e86c: 33c0                             xor    eax,eax
0x89e86e: 8a442408                         mov    al,BYTE PTR [esp+0x8]
0x89e872: 84c0                             test   al,al
0x89e874: 7516                             jne    0x89e88c
0x89e876: 81fa80000000                     cmp    edx,0x80
0x89e87c: 720e                             jb     0x89e88c
0x89e87e: 833da073fe0000                   cmp    DWORD PTR ds:0xfe73a0,0x0
0x89e885: 7405                             je     0x89e88c
0x89e887: e947330100                       jmp    0x8b1bd3
0x89e88c: 57                               push   edi
0x89e88d: 8bf9                             mov    edi,ecx
0x89e88f: 83fa04                           cmp    edx,0x4
0x89e892: 7231                             jb     0x89e8c5
0x89e894: f7d9                             neg    ecx
0x89e896: 83e103                           and    ecx,0x3
0x89e899: 740c                             je     0x89e8a7
0x89e89b: 2bd1                             sub    edx,ecx
0x89e89d: 8807                             mov    BYTE PTR [edi],al
0x89e89f: 83c701                           add    edi,0x1
0x89e8a2: 83e901                           sub    ecx,0x1
0x89e8a5: 75f6                             jne    0x89e89d
0x89e8a7: 8bc8                             mov    ecx,eax
0x89e8a9: c1e008                           shl    eax,0x8
0x89e8ac: 03c1                             add    eax,ecx
0x89e8ae: 8bc8                             mov    ecx,eax
0x89e8b0: c1e010                           shl    eax,0x10
0x89e8b3: 03c1                             add    eax,ecx
0x89e8b5: 8bca                             mov    ecx,edx
0x89e8b7: 83e203                           and    edx,0x3
0x89e8ba: c1e902                           shr    ecx,0x2
0x89e8bd: 7406                             je     0x89e8c5
0x89e8bf: f3ab                             rep stos DWORD PTR es:[edi],eax
0x89e8c1: 85d2                             test   edx,edx
0x89e8c3: 740a                             je     0x89e8cf
0x89e8c5: 8807                             mov    BYTE PTR [edi],al
0x89e8c7: 83c701                           add    edi,0x1
0x89e8ca: 83ea01                           sub    edx,0x1
0x89e8cd: 75f6                             jne    0x89e8c5
0x89e8cf: 8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x89e8d3: 5f                               pop    edi
0x89e8d4: c3                               ret
0x89e8d5: 8b442404                         mov    eax,DWORD PTR [esp+0x4]
0x89e8d9: c3                               ret

## F-8B1BD3 VA 0x8b1bd3..0x8b1c8d raw 0x4b0fd3 len 186 SHA256 cadbee47357a0cc79ef660415bd83d57b210cfd3f93c2aa9c09cfddd1a641745
0x8b1bd3: 660fefc0                         pxor   xmm0,xmm0
0x8b1bd7: 51                               push   ecx
0x8b1bd8: 53                               push   ebx
0x8b1bd9: 8bc1                             mov    eax,ecx
0x8b1bdb: 83e00f                           and    eax,0xf
0x8b1bde: 85c0                             test   eax,eax
0x8b1be0: 757f                             jne    0x8b1c61
0x8b1be2: 8bc2                             mov    eax,edx
0x8b1be4: 83e27f                           and    edx,0x7f
0x8b1be7: c1e807                           shr    eax,0x7
0x8b1bea: 7437                             je     0x8b1c23
0x8b1bec: 8da42400000000                   lea    esp,[esp+0x0]
0x8b1bf3: 660f7f01                         movdqa XMMWORD PTR [ecx],xmm0
0x8b1bf7: 660f7f4110                       movdqa XMMWORD PTR [ecx+0x10],xmm0
0x8b1bfc: 660f7f4120                       movdqa XMMWORD PTR [ecx+0x20],xmm0
0x8b1c01: 660f7f4130                       movdqa XMMWORD PTR [ecx+0x30],xmm0
0x8b1c06: 660f7f4140                       movdqa XMMWORD PTR [ecx+0x40],xmm0
0x8b1c0b: 660f7f4150                       movdqa XMMWORD PTR [ecx+0x50],xmm0
0x8b1c10: 660f7f4160                       movdqa XMMWORD PTR [ecx+0x60],xmm0
0x8b1c15: 660f7f4170                       movdqa XMMWORD PTR [ecx+0x70],xmm0
0x8b1c1a: 8d8980000000                     lea    ecx,[ecx+0x80]
0x8b1c20: 48                               dec    eax
0x8b1c21: 75d0                             jne    0x8b1bf3
0x8b1c23: 85d2                             test   edx,edx
0x8b1c25: 7437                             je     0x8b1c5e
0x8b1c27: 8bc2                             mov    eax,edx
0x8b1c29: c1e804                           shr    eax,0x4
0x8b1c2c: 740f                             je     0x8b1c3d
0x8b1c2e: eb03                             jmp    0x8b1c33
0x8b1c30: 8d4900                           lea    ecx,[ecx+0x0]
0x8b1c33: 660f7f01                         movdqa XMMWORD PTR [ecx],xmm0
0x8b1c37: 8d4910                           lea    ecx,[ecx+0x10]
0x8b1c3a: 48                               dec    eax
0x8b1c3b: 75f6                             jne    0x8b1c33
0x8b1c3d: 83e20f                           and    edx,0xf
0x8b1c40: 741c                             je     0x8b1c5e
0x8b1c42: 8bc2                             mov    eax,edx
0x8b1c44: 33db                             xor    ebx,ebx
0x8b1c46: c1ea02                           shr    edx,0x2
0x8b1c49: 7408                             je     0x8b1c53
0x8b1c4b: 8919                             mov    DWORD PTR [ecx],ebx
0x8b1c4d: 8d4904                           lea    ecx,[ecx+0x4]
0x8b1c50: 4a                               dec    edx
0x8b1c51: 75f8                             jne    0x8b1c4b
0x8b1c53: 83e003                           and    eax,0x3
0x8b1c56: 7406                             je     0x8b1c5e
0x8b1c58: 8819                             mov    BYTE PTR [ecx],bl
0x8b1c5a: 41                               inc    ecx
0x8b1c5b: 48                               dec    eax
0x8b1c5c: 75fa                             jne    0x8b1c58
0x8b1c5e: 5b                               pop    ebx
0x8b1c5f: 58                               pop    eax
0x8b1c60: c3                               ret
0x8b1c61: 8bd8                             mov    ebx,eax
0x8b1c63: f7db                             neg    ebx
0x8b1c65: 83c310                           add    ebx,0x10
0x8b1c68: 2bd3                             sub    edx,ebx
0x8b1c6a: 33c0                             xor    eax,eax
0x8b1c6c: 52                               push   edx
0x8b1c6d: 8bd3                             mov    edx,ebx
0x8b1c6f: 83e203                           and    edx,0x3
0x8b1c72: 7406                             je     0x8b1c7a
0x8b1c74: 8801                             mov    BYTE PTR [ecx],al
0x8b1c76: 41                               inc    ecx
0x8b1c77: 4a                               dec    edx
0x8b1c78: 75fa                             jne    0x8b1c74
0x8b1c7a: c1eb02                           shr    ebx,0x2
0x8b1c7d: 7408                             je     0x8b1c87
0x8b1c7f: 8901                             mov    DWORD PTR [ecx],eax
0x8b1c81: 8d4904                           lea    ecx,[ecx+0x4]
0x8b1c84: 4b                               dec    ebx
0x8b1c85: 75f8                             jne    0x8b1c7f
0x8b1c87: 5a                               pop    edx
0x8b1c88: e955ffffff                       jmp    0x8b1be2

## F-892E4D VA 0x892e4d..0x892eb0 raw 0x49224d len 99 SHA256 2bc9750b1881d9f7465aa946d715b24c5cb45fb576163e0dad8aa00bbd779b7c
0x892e4d: 8bff                             mov    edi,edi
0x892e4f: 55                               push   ebp
0x892e50: 8bec                             mov    ebp,esp
0x892e52: 56                               push   esi
0x892e53: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x892e56: 57                               push   edi
0x892e57: 85f6                             test   esi,esi
0x892e59: 7407                             je     0x892e62
0x892e5b: 8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
0x892e5e: 85ff                             test   edi,edi
0x892e60: 7515                             jne    0x892e77
0x892e62: e881580000                       call   0x8986e8
0x892e67: 6a16                             push   0x16
0x892e69: 5e                               pop    esi
0x892e6a: 8930                             mov    DWORD PTR [eax],esi
0x892e6c: e8d2040000                       call   0x893343
0x892e71: 8bc6                             mov    eax,esi
0x892e73: 5f                               pop    edi
0x892e74: 5e                               pop    esi
0x892e75: 5d                               pop    ebp
0x892e76: c3                               ret
0x892e77: 8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x892e7a: 85c0                             test   eax,eax
0x892e7c: 7505                             jne    0x892e83
0x892e7e: 668906                           mov    WORD PTR [esi],ax
0x892e81: ebdf                             jmp    0x892e62
0x892e83: 8bd6                             mov    edx,esi
0x892e85: 2bd0                             sub    edx,eax
0x892e87: 0fb708                           movzx  ecx,WORD PTR [eax]
0x892e8a: 66890c02                         mov    WORD PTR [edx+eax*1],cx
0x892e8e: 83c002                           add    eax,0x2
0x892e91: 6685c9                           test   cx,cx
0x892e94: 7403                             je     0x892e99
0x892e96: 4f                               dec    edi
0x892e97: 75ee                             jne    0x892e87
0x892e99: 33c0                             xor    eax,eax
0x892e9b: 85ff                             test   edi,edi
0x892e9d: 75d4                             jne    0x892e73
0x892e9f: 668906                           mov    WORD PTR [esi],ax
0x892ea2: e841580000                       call   0x8986e8
0x892ea7: 6a22                             push   0x22
0x892ea9: 59                               pop    ecx
0x892eaa: 8908                             mov    DWORD PTR [eax],ecx
0x892eac: 8bf1                             mov    esi,ecx
0x892eae: ebbc                             jmp    0x892e6c

## F-893CB1 VA 0x893cb1..0x893cf8 raw 0x4930b1 len 71 SHA256 5121b93e902bd4dac7ae9abcd101ca9e9e71cb234c654300cd86bc063c6c2639
0x893cb1: 8bff                             mov    edi,edi
0x893cb3: 55                               push   ebp
0x893cb4: 8bec                             mov    ebp,esp
0x893cb6: 33c0                             xor    eax,eax
0x893cb8: 390510cbf800                     cmp    DWORD PTR ds:0xf8cb10,eax
0x893cbe: 7527                             jne    0x893ce7
0x893cc0: 394508                           cmp    DWORD PTR [ebp+0x8],eax
0x893cc3: 7517                             jne    0x893cdc
0x893cc5: e81e4a0000                       call   0x8986e8
0x893cca: c70016000000                     mov    DWORD PTR [eax],0x16
0x893cd0: e86ef6ffff                       call   0x893343
0x893cd5: b8ffffff7f                       mov    eax,0x7fffffff
0x893cda: 5d                               pop    ebp
0x893cdb: c3                               ret
0x893cdc: 39450c                           cmp    DWORD PTR [ebp+0xc],eax
0x893cdf: 74e4                             je     0x893cc5
0x893ce1: 5d                               pop    ebp
0x893ce2: e9d1feffff                       jmp    0x893bb8
0x893ce7: 50                               push   eax
0x893ce8: ff750c                           push   DWORD PTR [ebp+0xc]
0x893ceb: ff7508                           push   DWORD PTR [ebp+0x8]
0x893cee: e8fefeffff                       call   0x893bf1
0x893cf3: 83c40c                           add    esp,0xc
0x893cf6: 5d                               pop    ebp
0x893cf7: c3                               ret

## F-893BB8 VA 0x893bb8..0x893bf1 raw 0x492fb8 len 57 SHA256 8cdaf97900da5fec4a09a393fa15fe6c4c997156779efea27d23dda8fcdde8cd
0x893bb8: 8bff                             mov    edi,edi
0x893bba: 55                               push   ebp
0x893bbb: 8bec                             mov    ebp,esp
0x893bbd: 8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x893bc0: 56                               push   esi
0x893bc1: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x893bc4: 57                               push   edi
0x893bc5: 0fb606                           movzx  eax,BYTE PTR [esi]
0x893bc8: 8d48bf                           lea    ecx,[eax-0x41]
0x893bcb: 46                               inc    esi
0x893bcc: 83f919                           cmp    ecx,0x19
0x893bcf: 7703                             ja     0x893bd4
0x893bd1: 83c020                           add    eax,0x20
0x893bd4: 0fb60a                           movzx  ecx,BYTE PTR [edx]
0x893bd7: 8d79bf                           lea    edi,[ecx-0x41]
0x893bda: 42                               inc    edx
0x893bdb: 83ff19                           cmp    edi,0x19
0x893bde: 7703                             ja     0x893be3
0x893be0: 83c120                           add    ecx,0x20
0x893be3: 85c0                             test   eax,eax
0x893be5: 7404                             je     0x893beb
0x893be7: 3bc1                             cmp    eax,ecx
0x893be9: 74da                             je     0x893bc5
0x893beb: 5f                               pop    edi
0x893bec: 2bc1                             sub    eax,ecx
0x893bee: 5e                               pop    esi
0x893bef: 5d                               pop    ebp
0x893bf0: c3                               ret

## F-891001 VA 0x891001..0x891010 raw 0x490401 len 15 SHA256 0b21da915bbe8e3662aec7b0ea6c232071cc5315e8ef40693f9cfb5720a8bfa9
0x891001: 3b0d201fd600                     cmp    ecx,DWORD PTR ds:0xd61f20
0x891007: 7502                             jne    0x89100b
0x891009: f3c3                             repz ret
0x89100b: e9ccf40000                       jmp    0x8a04dc

## F-8FED10 VA 0x8fed10..0x8fed46 raw 0x4fe110 len 54 SHA256 7acc368e348b5cde44b3b0a675cddbf55c11f0638b250cedc13c9274cdf0a0dc
0x8fed10: 833da073fe0000                   cmp    DWORD PTR ds:0xfe73a0,0x0
0x8fed17: 742d                             je     0x8fed46
0x8fed19: 55                               push   ebp
0x8fed1a: 8bec                             mov    ebp,esp
0x8fed1c: 83ec08                           sub    esp,0x8
0x8fed1f: 83e4f8                           and    esp,0xfffffff8
0x8fed22: dd1c24                           fstp   QWORD PTR [esp]
0x8fed25: f20f2c0424                       cvttsd2si eax,QWORD PTR [esp]
0x8fed2a: c9                               leave
0x8fed2b: c3                               ret
0x8fed2c: 833da073fe0000                   cmp    DWORD PTR ds:0xfe73a0,0x0
0x8fed33: 7411                             je     0x8fed46
0x8fed35: 83ec04                           sub    esp,0x4
0x8fed38: d93c24                           fnstcw WORD PTR [esp]
0x8fed3b: 58                               pop    eax
0x8fed3c: 6683e07f                         and    ax,0x7f
0x8fed40: 6683f87f                         cmp    ax,0x7f
0x8fed44: 74d3                             je     0x8fed19

## F-8FED46 VA 0x8fed46..0x8fedca raw 0x4fe146 len 132 SHA256 db8b8bfe45988ab499e1a0a900cb7dad4692ce89f942dac54cbbe53fbbd1d170
0x8fed46: 55                               push   ebp
0x8fed47: 8bec                             mov    ebp,esp
0x8fed49: 83ec20                           sub    esp,0x20
0x8fed4c: 83e4f0                           and    esp,0xfffffff0
0x8fed4f: d9c0                             fld    st(0)
0x8fed51: d9542418                         fst    DWORD PTR [esp+0x18]
0x8fed55: df7c2410                         fistp  QWORD PTR [esp+0x10]
0x8fed59: df6c2410                         fild   QWORD PTR [esp+0x10]
0x8fed5d: 8b542418                         mov    edx,DWORD PTR [esp+0x18]
0x8fed61: 8b442410                         mov    eax,DWORD PTR [esp+0x10]
0x8fed65: 85c0                             test   eax,eax
0x8fed67: 743c                             je     0x8feda5
0x8fed69: dee9                             fsubp  st(1),st
0x8fed6b: 85d2                             test   edx,edx
0x8fed6d: 791e                             jns    0x8fed8d
0x8fed6f: d91c24                           fstp   DWORD PTR [esp]
0x8fed72: 8b0c24                           mov    ecx,DWORD PTR [esp]
0x8fed75: 81f100000080                     xor    ecx,0x80000000
0x8fed7b: 81c1ffffff7f                     add    ecx,0x7fffffff
0x8fed81: 83d000                           adc    eax,0x0
0x8fed84: 8b542414                         mov    edx,DWORD PTR [esp+0x14]
0x8fed88: 83d200                           adc    edx,0x0
0x8fed8b: eb2c                             jmp    0x8fedb9
0x8fed8d: d91c24                           fstp   DWORD PTR [esp]
0x8fed90: 8b0c24                           mov    ecx,DWORD PTR [esp]
0x8fed93: 81c1ffffff7f                     add    ecx,0x7fffffff
0x8fed99: 83d800                           sbb    eax,0x0
0x8fed9c: 8b542414                         mov    edx,DWORD PTR [esp+0x14]
0x8feda0: 83da00                           sbb    edx,0x0
0x8feda3: eb14                             jmp    0x8fedb9
0x8feda5: 8b542414                         mov    edx,DWORD PTR [esp+0x14]
0x8feda9: f7c2ffffff7f                     test   edx,0x7fffffff
0x8fedaf: 75b8                             jne    0x8fed69
0x8fedb1: d95c2418                         fstp   DWORD PTR [esp+0x18]
0x8fedb5: d95c2418                         fstp   DWORD PTR [esp+0x18]
0x8fedb9: c9                               leave
0x8fedba: c3                               ret
0x8fedbb: cc                               int3
0x8fedbc: cc                               int3
0x8fedbd: cc                               int3
0x8fedbe: cc                               int3
0x8fedbf: cc                               int3
0x8fedc0: ba905fc500                       mov    edx,0xc55f90
0x8fedc5: e921150000                       jmp    0x9002eb

## F-8FF5A0 VA 0x8ff5a0..0x8ff5fd raw 0x4fe9a0 len 93 SHA256 11ffa105b3ce39f180fe8e9ac00352f9bad15434742ebc90095ac01ef2b7a171
0x8ff5a0: 833d8c72fe0000                   cmp    DWORD PTR ds:0xfe728c,0x0
0x8ff5a7: 7432                             je     0x8ff5db
0x8ff5a9: 83ec08                           sub    esp,0x8
0x8ff5ac: 0fae5c2404                       stmxcsr DWORD PTR [esp+0x4]
0x8ff5b1: 8b442404                         mov    eax,DWORD PTR [esp+0x4]
0x8ff5b5: 25807f0000                       and    eax,0x7f80
0x8ff5ba: 3d801f0000                       cmp    eax,0x1f80
0x8ff5bf: 750f                             jne    0x8ff5d0
0x8ff5c1: d93c24                           fnstcw WORD PTR [esp]
0x8ff5c4: 668b0424                         mov    ax,WORD PTR [esp]
0x8ff5c8: 6683e07f                         and    ax,0x7f
0x8ff5cc: 6683f87f                         cmp    ax,0x7f
0x8ff5d0: 8d642408                         lea    esp,[esp+0x8]
0x8ff5d4: 7505                             jne    0x8ff5db
0x8ff5d6: e975260000                       jmp    0x901c50
0x8ff5db: 83ec14                           sub    esp,0x14
0x8ff5de: d9c9                             fxch   st(1)
0x8ff5e0: dd1c24                           fstp   QWORD PTR [esp]
0x8ff5e3: dd542408                         fst    QWORD PTR [esp+0x8]
0x8ff5e7: 8b44240c                         mov    eax,DWORD PTR [esp+0xc]
0x8ff5eb: e80d000000                       call   0x8ff5fd
0x8ff5f0: 83c414                           add    esp,0x14
0x8ff5f3: c3                               ret
0x8ff5f4: 8d54240c                         lea    edx,[esp+0xc]
0x8ff5f8: e8e8160000                       call   0x900ce5

## F-8FF5FD VA 0x8ff5fd..0x8ff865 raw 0x4fe9fd len 616 SHA256 2ff2f28353319d60936bda4aaf1916de4ea5fb587b4498105ad6698339a490a4
0x8ff5fd: 8bc8                             mov    ecx,eax
0x8ff5ff: 50                               push   eax
0x8ff600: 9bd93c24                         fstcw  WORD PTR [esp]
0x8ff604: 66813c247f02                     cmp    WORD PTR [esp],0x27f
0x8ff60a: 7405                             je     0x8ff611
0x8ff60c: e8a4160000                       call   0x900cb5
0x8ff611: 81e10000f07f                     and    ecx,0x7ff00000
0x8ff617: 8d542408                         lea    edx,[esp+0x8]
0x8ff61b: 81f90000f07f                     cmp    ecx,0x7ff00000
0x8ff621: 0f849d000000                     je     0x8ff6c4
0x8ff627: e8b9160000                       call   0x900ce5
0x8ff62c: 0f848e000000                     je     0x8ff6c0
0x8ff632: a90000f07f                       test   eax,0x7ff00000
0x8ff637: 0f84f6000000                     je     0x8ff733
0x8ff63d: 8a4c240f                         mov    cl,BYTE PTR [esp+0xf]
0x8ff641: 80e180                           and    cl,0x80
0x8ff644: 0f8553010000                     jne    0x8ff79d
0x8ff64a: d9f1                             fyl2x
0x8ff64c: e84f160000                       call   0x900ca0
0x8ff651: 80f901                           cmp    cl,0x1
0x8ff654: 7502                             jne    0x8ff658
0x8ff656: d9e0                             fchs
0x8ff658: 833d74cbf80000                   cmp    DWORD PTR ds:0xf8cb74,0x0
0x8ff65f: 0f85d9160000                     jne    0x900d3e
0x8ff665: 8d0d48c7f800                     lea    ecx,ds:0xf8c748
0x8ff66b: ba1d000000                       mov    edx,0x1d
0x8ff670: e914170000                       jmp    0x900d89
0x8ff675: 833d74cbf80000                   cmp    DWORD PTR ds:0xf8cb74,0x0
0x8ff67c: 0f85bc160000                     jne    0x900d3e
0x8ff682: 8d0d48c7f800                     lea    ecx,ds:0xf8c748
0x8ff688: ba1d000000                       mov    edx,0x1d
0x8ff68d: e8ae150000                       call   0x900c40
0x8ff692: 5a                               pop    edx
0x8ff693: c3                               ret
0x8ff694: 8d542408                         lea    edx,[esp+0x8]
0x8ff698: e848160000                       call   0x900ce5
0x8ff69d: f644241608                       test   BYTE PTR [esp+0x16],0x8
0x8ff6a2: 7503                             jne    0x8ff6a7
0x8ff6a4: 41                               inc    ecx
0x8ff6a5: eb33                             jmp    0x8ff6da
0x8ff6a7: dec1                             faddp  st(1),st
0x8ff6a9: b801000000                       mov    eax,0x1
0x8ff6ae: ebc5                             jmp    0x8ff675
0x8ff6b0: f644240e08                       test   BYTE PTR [esp+0xe],0x8
0x8ff6b5: 75f0                             jne    0x8ff6a7
0x8ff6b7: dec1                             faddp  st(1),st
0x8ff6b9: b807000000                       mov    eax,0x7
0x8ff6be: ebb5                             jmp    0x8ff675
0x8ff6c0: 33c9                             xor    ecx,ecx
0x8ff6c2: eb16                             jmp    0x8ff6da
0x8ff6c4: 33c9                             xor    ecx,ecx
0x8ff6c6: 25ffff0f00                       and    eax,0xfffff
0x8ff6cb: 0b442410                         or     eax,DWORD PTR [esp+0x10]
0x8ff6cf: 75c3                             jne    0x8ff694
0x8ff6d1: 8d542408                         lea    edx,[esp+0x8]
0x8ff6d5: e80b160000                       call   0x900ce5
0x8ff6da: 8b44240c                         mov    eax,DWORD PTR [esp+0xc]
0x8ff6de: 8bd0                             mov    edx,eax
0x8ff6e0: 250000f07f                       and    eax,0x7ff00000
0x8ff6e5: 81e2ffff0f00                     and    edx,0xfffff
0x8ff6eb: 3d0000f07f                       cmp    eax,0x7ff00000
0x8ff6f0: 7506                             jne    0x8ff6f8
0x8ff6f2: 0b542408                         or     edx,DWORD PTR [esp+0x8]
0x8ff6f6: 75b8                             jne    0x8ff6b0
0x8ff6f8: 85c9                             test   ecx,ecx
0x8ff6fa: 75bb                             jne    0x8ff6b7
0x8ff6fc: 83ec74                           sub    esp,0x74
0x8ff6ff: 8bcc                             mov    ecx,esp
0x8ff701: 51                               push   ecx
0x8ff702: 83ec10                           sub    esp,0x10
0x8ff705: dd1c24                           fstp   QWORD PTR [esp]
0x8ff708: dd5c2408                         fstp   QWORD PTR [esp+0x8]
0x8ff70c: 9bdd7108                         fsave  [ecx+0x8]
0x8ff710: e805310000                       call   0x90281a
0x8ff715: 83c410                           add    esp,0x10
0x8ff718: 59                               pop    ecx
0x8ff719: dd6108                           frstor [ecx+0x8]
0x8ff71c: dd01                             fld    QWORD PTR [ecx]
0x8ff71e: 83c474                           add    esp,0x74
0x8ff721: 85c0                             test   eax,eax
0x8ff723: 0f8415160000                     je     0x900d3e
0x8ff729: b801000000                       mov    eax,0x1
0x8ff72e: e942ffffff                       jmp    0x8ff675
0x8ff733: 8b44240c                         mov    eax,DWORD PTR [esp+0xc]
0x8ff737: 25ffff0f00                       and    eax,0xfffff
0x8ff73c: 0b442408                         or     eax,DWORD PTR [esp+0x8]
0x8ff740: 0f85f7feffff                     jne    0x8ff63d
0x8ff746: ddd8                             fstp   st(0)
0x8ff748: 8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x8ff74c: 25ffffff7f                       and    eax,0x7fffffff
0x8ff751: 0b442410                         or     eax,DWORD PTR [esp+0x10]
0x8ff755: 743d                             je     0x8ff794
0x8ff757: e866000000                       call   0x8ff7c2
0x8ff75c: 8a6c240f                         mov    ch,BYTE PTR [esp+0xf]
0x8ff760: c0ed07                           shr    ch,0x7
0x8ff763: f744241780000000                 test   DWORD PTR [esp+0x17],0x80
0x8ff76b: 7416                             je     0x8ff783
0x8ff76d: db2de0aac500                     fld    TBYTE PTR ds:0xc5aae0
0x8ff773: 84cd                             test   ch,cl
0x8ff775: 7402                             je     0x8ff779
0x8ff777: d9e0                             fchs
0x8ff779: b802000000                       mov    eax,0x2
0x8ff77e: e9f2feffff                       jmp    0x8ff675
0x8ff783: d9ee                             fldz
0x8ff785: 84cd                             test   ch,cl
0x8ff787: 0f84b1150000                     je     0x900d3e
0x8ff78d: d9e0                             fchs
0x8ff78f: e9aa150000                       jmp    0x900d3e
0x8ff794: ddd8                             fstp   st(0)
0x8ff796: d9e8                             fld1
0x8ff798: e9a1150000                       jmp    0x900d3e
0x8ff79d: d9c1                             fld    st(1)
0x8ff79f: e81e000000                       call   0x8ff7c2
0x8ff7a4: d9e0                             fchs
0x8ff7a6: 84c9                             test   cl,cl
0x8ff7a8: 0f859cfeffff                     jne    0x8ff64a
0x8ff7ae: ddd8                             fstp   st(0)
0x8ff7b0: ddd8                             fstp   st(0)
0x8ff7b2: db2df077c500                     fld    TBYTE PTR ds:0xc577f0
0x8ff7b8: b801000000                       mov    eax,0x1
0x8ff7bd: e9b3feffff                       jmp    0x8ff675
0x8ff7c2: d9c0                             fld    st(0)
0x8ff7c4: d9fc                             frndint
0x8ff7c6: d8d9                             fcomp  st(1)
0x8ff7c8: b100                             mov    cl,0x0
0x8ff7ca: 9bdfe0                           fstsw  ax
0x8ff7cd: 9e                               sahf
0x8ff7ce: 7517                             jne    0x8ff7e7
0x8ff7d0: dc0d40c7f800                     fmul   QWORD PTR ds:0xf8c740
0x8ff7d6: fec1                             inc    cl
0x8ff7d8: d9c0                             fld    st(0)
0x8ff7da: d9fc                             frndint
0x8ff7dc: ded9                             fcompp
0x8ff7de: 9bdfe0                           fstsw  ax
0x8ff7e1: 9e                               sahf
0x8ff7e2: 7502                             jne    0x8ff7e6
0x8ff7e4: fec1                             inc    cl
0x8ff7e6: c3                               ret
0x8ff7e7: ddd8                             fstp   st(0)
0x8ff7e9: c3                               ret
0x8ff7ea: cc                               int3
0x8ff7eb: cc                               int3
0x8ff7ec: cc                               int3
0x8ff7ed: cc                               int3
0x8ff7ee: cc                               int3
0x8ff7ef: cc                               int3
0x8ff7f0: 53                               push   ebx
0x8ff7f1: 8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x8ff7f5: 0bc0                             or     eax,eax
0x8ff7f7: 7518                             jne    0x8ff811
0x8ff7f9: 8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x8ff7fd: 8b44240c                         mov    eax,DWORD PTR [esp+0xc]
0x8ff801: 33d2                             xor    edx,edx
0x8ff803: f7f1                             div    ecx
0x8ff805: 8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x8ff809: f7f1                             div    ecx
0x8ff80b: 8bc2                             mov    eax,edx
0x8ff80d: 33d2                             xor    edx,edx
0x8ff80f: eb50                             jmp    0x8ff861
0x8ff811: 8bc8                             mov    ecx,eax
0x8ff813: 8b5c2410                         mov    ebx,DWORD PTR [esp+0x10]
0x8ff817: 8b54240c                         mov    edx,DWORD PTR [esp+0xc]
0x8ff81b: 8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x8ff81f: d1e9                             shr    ecx,1
0x8ff821: d1db                             rcr    ebx,1
0x8ff823: d1ea                             shr    edx,1
0x8ff825: d1d8                             rcr    eax,1
0x8ff827: 0bc9                             or     ecx,ecx
0x8ff829: 75f4                             jne    0x8ff81f
0x8ff82b: f7f3                             div    ebx
0x8ff82d: 8bc8                             mov    ecx,eax
0x8ff82f: f7642414                         mul    DWORD PTR [esp+0x14]
0x8ff833: 91                               xchg   ecx,eax
0x8ff834: f7642410                         mul    DWORD PTR [esp+0x10]
0x8ff838: 03d1                             add    edx,ecx
0x8ff83a: 720e                             jb     0x8ff84a
0x8ff83c: 3b54240c                         cmp    edx,DWORD PTR [esp+0xc]
0x8ff840: 7708                             ja     0x8ff84a
0x8ff842: 720e                             jb     0x8ff852
0x8ff844: 3b442408                         cmp    eax,DWORD PTR [esp+0x8]
0x8ff848: 7608                             jbe    0x8ff852
0x8ff84a: 2b442410                         sub    eax,DWORD PTR [esp+0x10]
0x8ff84e: 1b542414                         sbb    edx,DWORD PTR [esp+0x14]
0x8ff852: 2b442408                         sub    eax,DWORD PTR [esp+0x8]
0x8ff856: 1b54240c                         sbb    edx,DWORD PTR [esp+0xc]
0x8ff85a: f7da                             neg    edx
0x8ff85c: f7d8                             neg    eax
0x8ff85e: 83da00                           sbb    edx,0x0
0x8ff861: 5b                               pop    ebx
0x8ff862: c21000                           ret    0x10

## F-901C50 VA 0x901c50..0x901c69 raw 0x501050 len 25 SHA256 e4a6378ddfeae050ac73aedab430795bad2103d132257fa2e3c6477c01f71a4d
0x901c50: 55                               push   ebp
0x901c51: 8bec                             mov    ebp,esp
0x901c53: 83ec10                           sub    esp,0x10
0x901c56: 83e4f0                           and    esp,0xfffffff0
0x901c59: d9c9                             fxch   st(1)
0x901c5b: dd1c24                           fstp   QWORD PTR [esp]
0x901c5e: dd5c2408                         fstp   QWORD PTR [esp+0x8]
0x901c62: e802000000                       call   0x901c69
0x901c67: c9                               leave
0x901c68: c3                               ret

## F-901C69 VA 0x901c69..0x9027b0 raw 0x501069 len 2887 SHA256 8519e66763adc434a3a9bd426d0ab382483585d5045cf4c33c2a47cc3512eff8
0x901c69: 660f12442404                     movlpd xmm0,QWORD PTR [esp+0x4]
0x901c6f: 660f123dd0e3c500                 movlpd xmm7,QWORD PTR ds:0xc5e3d0
0x901c77: 660f1215e0e3c500                 movlpd xmm2,QWORD PTR ds:0xc5e3e0
0x901c7f: 660f54f8                         andpd  xmm7,xmm0
0x901c83: f20f10e0                         movsd  xmm4,xmm0
0x901c87: 660f73d02c                       psrlq  xmm0,0x2c
0x901c8c: 660fc5c000                       pextrw eax,xmm0,0x0
0x901c91: 660f56fa                         orpd   xmm7,xmm2
0x901c95: 660fc5cc03                       pextrw ecx,xmm4,0x3
0x901c9a: 25ff000000                       and    eax,0xff
0x901c9f: 83c001                           add    eax,0x1
0x901ca2: 25fe010000                       and    eax,0x1fe
0x901ca7: f20f593c8540abc500               mulsd  xmm7,QWORD PTR [eax*4+0xc5ab40]
0x901cb0: 660f122c8540abc500               movlpd xmm5,QWORD PTR [eax*4+0xc5ab40]
0x901cb9: 03c0                             add    eax,eax
0x901cbb: 660f28348550afc500               movapd xmm6,XMMWORD PTR [eax*4+0xc5af50]
0x901cc4: baef7f0000                       mov    edx,0x7fef
0x901cc9: 2bd1                             sub    edx,ecx
0x901ccb: 83e910                           sub    ecx,0x10
0x901cce: 0bca                             or     ecx,edx
0x901cd0: 81f900000080                     cmp    ecx,0x80000000
0x901cd6: 0f83db020000                     jae    0x901fb7
0x901cdc: b900000000                       mov    ecx,0x0
0x901ce1: ba7ffe0300                       mov    edx,0x3fe7f
0x901ce6: 660f6eca                         movd   xmm1,edx
0x901cea: 660ffbc1                         psubq  xmm0,xmm1
0x901cee: 660f73d008                       psrlq  xmm0,0x8
0x901cf3: f30fe6c0                         cvtdq2pd xmm0,xmm0
0x901cf7: 660f120d28e4c500                 movlpd xmm1,QWORD PTR ds:0xc5e428
0x901cff: f20f10df                         movsd  xmm3,xmm7
0x901d03: 660f73d726                       psrlq  xmm7,0x26
0x901d08: 660fc5c700                       pextrw eax,xmm7,0x0
0x901d0d: 660f5425d0e3c500                 andpd  xmm4,XMMWORD PTR ds:0xc5e3d0
0x901d15: 25ff000000                       and    eax,0xff
0x901d1a: 83c001                           add    eax,0x1
0x901d1d: 25fe010000                       and    eax,0x1fe
0x901d22: f20f591c8560b7c500               mulsd  xmm3,QWORD PTR [eax*4+0xc5b760]
0x901d2b: f20f592c8560b7c500               mulsd  xmm5,QWORD PTR [eax*4+0xc5b760]
0x901d34: 03c0                             add    eax,eax
0x901d36: 660f58348570bbc500               addpd  xmm6,XMMWORD PTR [eax*4+0xc5bb70]
0x901d3f: 660f5625e0e3c500                 orpd   xmm4,XMMWORD PTR ds:0xc5e3e0
0x901d47: f20f58f0                         addsd  xmm6,xmm0
0x901d4b: 660f54cc                         andpd  xmm1,xmm4
0x901d4f: f20f10d3                         movsd  xmm2,xmm3
0x901d53: 660f73d31f                       psrlq  xmm3,0x1f
0x901d58: 660fc5c300                       pextrw eax,xmm3,0x0
0x901d5d: 660f120528e4c500                 movlpd xmm0,QWORD PTR ds:0xc5e428
0x901d65: f20f5ce1                         subsd  xmm4,xmm1
0x901d69: 660f123d30e4c500                 movlpd xmm7,QWORD PTR ds:0xc5e430
0x901d71: 25ff010000                       and    eax,0x1ff
0x901d76: 83c001                           add    eax,0x1
0x901d79: 25fe030000                       and    eax,0x3fe
0x901d7e: f20f592c8580c3c500               mulsd  xmm5,QWORD PTR [eax*4+0xc5c380]
0x901d87: f20f59148580c3c500               mulsd  xmm2,QWORD PTR [eax*4+0xc5c380]
0x901d90: 660f5834c590cbc500               addpd  xmm6,XMMWORD PTR [eax*8+0xc5cb90]
0x901d99: 660f54c5                         andpd  xmm0,xmm5
0x901d9d: f20f5ce8                         subsd  xmm5,xmm0
0x901da1: f20f58fa                         addsd  xmm7,xmm2
0x901da5: f20f10d8                         movsd  xmm3,xmm0
0x901da9: f20f59c1                         mulsd  xmm0,xmm1
0x901dad: f20f59cd                         mulsd  xmm1,xmm5
0x901db1: f20f59dc                         mulsd  xmm3,xmm4
0x901db5: f20f5cd0                         subsd  xmm2,xmm0
0x901db9: f20f59e5                         mulsd  xmm4,xmm5
0x901dbd: f20f10c6                         movsd  xmm0,xmm6
0x901dc1: f20f5cd1                         subsd  xmm2,xmm1
0x901dc5: f20f58f7                         addsd  xmm6,xmm7
0x901dc9: 660f124c240c                     movlpd xmm1,QWORD PTR [esp+0xc]
0x901dcf: 660fc5c103                       pextrw eax,xmm1,0x3
0x901dd4: f20f5cd3                         subsd  xmm2,xmm3
0x901dd8: f20f5cc6                         subsd  xmm0,xmm6
0x901ddc: 660f121d28e4c500                 movlpd xmm3,QWORD PTR ds:0xc5e428
0x901de4: 660fc5d603                       pextrw edx,xmm6,0x3
0x901de9: f20f5cd4                         subsd  xmm2,xmm4
0x901ded: f20f10e6                         movsd  xmm4,xmm6
0x901df1: f20f58c7                         addsd  xmm0,xmm7
0x901df5: f20f5cfa                         subsd  xmm7,xmm2
0x901df9: f20f5cf2                         subsd  xmm6,xmm2
0x901dfd: 660f14ff                         unpcklpd xmm7,xmm7
0x901e01: 25f07f0000                       and    eax,0x7ff0
0x901e06: 3df07f0000                       cmp    eax,0x7ff0
0x901e0b: 0f8317050000                     jae    0x902328
0x901e11: 81e2f07f0000                     and    edx,0x7ff0
0x901e17: 2df03f0000                       sub    eax,0x3ff0
0x901e1c: 03c2                             add    eax,edx
0x901e1e: baa0400000                       mov    edx,0x40a0
0x901e23: 2bd0                             sub    edx,eax
0x901e25: 2d703c0000                       sub    eax,0x3c70
0x901e2a: 0bd0                             or     edx,eax
0x901e2c: 81fa00000080                     cmp    edx,0x80000000
0x901e32: 0f83e4080000                     jae    0x90271c
0x901e38: f20f5ce6                         subsd  xmm4,xmm6
0x901e3c: f20f5cd4                         subsd  xmm2,xmm4
0x901e40: 660f122528e4c500                 movlpd xmm4,QWORD PTR ds:0xc5e428
0x901e48: 660f54d9                         andpd  xmm3,xmm1
0x901e4c: 660f54e6                         andpd  xmm4,xmm6
0x901e50: f20f5cc2                         subsd  xmm0,xmm2
0x901e54: 660f57d2                         xorpd  xmm2,xmm2
0x901e58: ba60400000                       mov    edx,0x4060
0x901e5d: 660fc4d203                       pinsrw xmm2,edx,0x3
0x901e62: f20f10eb                         movsd  xmm5,xmm3
0x901e66: f20f59dc                         mulsd  xmm3,xmm4
0x901e6a: f20f5cf4                         subsd  xmm6,xmm4
0x901e6e: f20f5ccd                         subsd  xmm1,xmm5
0x901e72: f20f59da                         mulsd  xmm3,xmm2
0x901e76: f20f59ee                         mulsd  xmm5,xmm6
0x901e7a: 660f2815a0dbc500                 movapd xmm2,XMMWORD PTR ds:0xc5dba0
0x901e82: f20f59e1                         mulsd  xmm4,xmm1
0x901e86: f20f2dc3                         cvtsd2si eax,xmm3
0x901e8a: f20f59f1                         mulsd  xmm6,xmm1
0x901e8e: 660f280db0dbc500                 movapd xmm1,XMMWORD PTR ds:0xc5dbb0
0x901e96: f20f58ec                         addsd  xmm5,xmm4
0x901e9a: 660f70e6ee                       pshufd xmm4,xmm6,0xee
0x901e9f: f20f58ee                         addsd  xmm5,xmm6
0x901ea3: ba7fff0100                       mov    edx,0x1ff7f
0x901ea8: 2bd0                             sub    edx,eax
0x901eaa: 05ffe10100                       add    eax,0x1e1ff
0x901eaf: 0bd0                             or     edx,eax
0x901eb1: 2dffe10100                       sub    eax,0x1e1ff
0x901eb6: 83fa00                           cmp    edx,0x0
0x901eb9: 0f8ee1050000                     jle    0x9024a0
0x901ebf: 03c8                             add    ecx,eax
0x901ec1: 83e07f                           and    eax,0x7f
0x901ec4: 83e180                           and    ecx,0xffffff80
0x901ec7: 81c180ff0100                     add    ecx,0x1ff80
0x901ecd: f20f58e0                         addsd  xmm4,xmm0
0x901ed1: f20f10c3                         movsd  xmm0,xmm3
0x901ed5: f20f581dc0e3c500                 addsd  xmm3,QWORD PTR ds:0xc5e3c0
0x901edd: 660f59d7                         mulpd  xmm2,xmm7
0x901ee1: f20f5c1dc0e3c500                 subsd  xmm3,QWORD PTR ds:0xc5e3c0
0x901ee9: 660f59ff                         mulpd  xmm7,xmm7
0x901eed: f20f5cc3                         subsd  xmm0,xmm3
0x901ef1: 03c0                             add    eax,eax
0x901ef3: 03c0                             add    eax,eax
0x901ef5: 03c0                             add    eax,eax
0x901ef7: 03c0                             add    eax,eax
0x901ef9: 660f2898c0dbc500                 movapd xmm3,XMMWORD PTR [eax+0xc5dbc0]
0x901f01: 660f283500e4c500                 movapd xmm6,XMMWORD PTR ds:0xc5e400
0x901f09: 660f59cf                         mulpd  xmm1,xmm7
0x901f0d: 660f58d1                         addpd  xmm2,xmm1
0x901f11: 660f70caee                       pshufd xmm1,xmm2,0xee
0x901f16: f20f59d7                         mulsd  xmm2,xmm7
0x901f1a: 660f57ff                         xorpd  xmm7,xmm7
0x901f1e: ba803f0000                       mov    edx,0x3f80
0x901f23: f20f58d1                         addsd  xmm2,xmm1
0x901f27: 660fc4fa03                       pinsrw xmm7,edx,0x3
0x901f2c: f20f58d4                         addsd  xmm2,xmm4
0x901f30: 660f122520e4c500                 movlpd xmm4,QWORD PTR ds:0xc5e420
0x901f38: 660f6ec9                         movd   xmm1,ecx
0x901f3c: f20f5954240c                     mulsd  xmm2,QWORD PTR [esp+0xc]
0x901f42: f20f59c7                         mulsd  xmm0,xmm7
0x901f46: 660f73f12d                       psllq  xmm1,0x2d
0x901f4b: 660f70c944                       pshufd xmm1,xmm1,0x44
0x901f50: 660f283d10e4c500                 movapd xmm7,XMMWORD PTR ds:0xc5e410
0x901f58: f20f58ea                         addsd  xmm5,xmm2
0x901f5c: 660f59d9                         mulpd  xmm3,xmm1
0x901f60: f20f58c5                         addsd  xmm0,xmm5
0x901f64: 660f14c0                         unpcklpd xmm0,xmm0
0x901f68: 660f59f0                         mulpd  xmm6,xmm0
0x901f6c: f20f59e0                         mulsd  xmm4,xmm0
0x901f70: 660f59c0                         mulpd  xmm0,xmm0
0x901f74: 660f58fe                         addpd  xmm7,xmm6
0x901f78: 660f59f8                         mulpd  xmm7,xmm0
0x901f7c: f20f59c3                         mulsd  xmm0,xmm3
0x901f80: 660f70f7ee                       pshufd xmm6,xmm7,0xee
0x901f85: f20f59c7                         mulsd  xmm0,xmm7
0x901f89: 660f70ebee                       pshufd xmm5,xmm3,0xee
0x901f8e: f20f59f3                         mulsd  xmm6,xmm3
0x901f92: f20f59e3                         mulsd  xmm4,xmm3
0x901f96: f20f58c5                         addsd  xmm0,xmm5
0x901f9a: 83ec10                           sub    esp,0x10
0x901f9d: f20f58c6                         addsd  xmm0,xmm6
0x901fa1: f20f58c4                         addsd  xmm0,xmm4
0x901fa5: f20f58c3                         addsd  xmm0,xmm3
0x901fa9: 660f13442404                     movlpd QWORD PTR [esp+0x4],xmm0
0x901faf: dd442404                         fld    QWORD PTR [esp+0x4]
0x901fb3: 83c410                           add    esp,0x10
0x901fb6: c3                               ret
0x901fb7: 660f124c240c                     movlpd xmm1,QWORD PTR [esp+0xc]
0x901fbd: 660f121df0e3c500                 movlpd xmm3,QWORD PTR ds:0xc5e3f0
0x901fc5: 660f7ec8                         movd   eax,xmm1
0x901fc9: f20f10d1                         movsd  xmm2,xmm1
0x901fcd: 660f54cb                         andpd  xmm1,xmm3
0x901fd1: 660f73d120                       psrlq  xmm1,0x20
0x901fd6: 660f7ec9                         movd   ecx,xmm1
0x901fda: 81f90000f07f                     cmp    ecx,0x7ff00000
0x901fe0: 0f83da000000                     jae    0x9020c0
0x901fe6: 0bc1                             or     eax,ecx
0x901fe8: 83f800                           cmp    eax,0x0
0x901feb: 0f841c040000                     je     0x90240d
0x901ff1: 83fa00                           cmp    edx,0x0
0x901ff4: 0f8d05010000                     jge    0x9020ff
0x901ffa: f7da                             neg    edx
0x901ffc: 81c2ef7f0000                     add    edx,0x7fef
0x902002: 660f73f334                       psllq  xmm3,0x34
0x902007: 660f56d3                         orpd   xmm2,xmm3
0x90200b: b9f3030000                       mov    ecx,0x3f3
0x902010: 660f6ed9                         movd   xmm3,ecx
0x902014: 660f73d114                       psrlq  xmm1,0x14
0x902019: 660ffacb                         psubd  xmm1,xmm3
0x90201d: 660fefdb                         pxor   xmm3,xmm3
0x902021: 660feecb                         pmaxsw xmm1,xmm3
0x902025: 660ff3d1                         psllq  xmm2,xmm1
0x902029: 660f76d3                         pcmpeqd xmm2,xmm3
0x90202d: 660fd7c2                         pmovmskb eax,xmm2
0x902031: 8bca                             mov    ecx,edx
0x902033: 81e2ff7f0000                     and    edx,0x7fff
0x902039: 81faf07f0000                     cmp    edx,0x7ff0
0x90203f: 0f83a3010000                     jae    0x9021e8
0x902045: 25ff000000                       and    eax,0xff
0x90204a: 3dff000000                       cmp    eax,0xff
0x90204f: 0f858c020000                     jne    0x9022e1
0x902055: 660f124c240c                     movlpd xmm1,QWORD PTR [esp+0xc]
0x90205b: 660f1254240c                     movlpd xmm2,QWORD PTR [esp+0xc]
0x902061: b9f4030000                       mov    ecx,0x3f4
0x902066: 660f6ed9                         movd   xmm3,ecx
0x90206a: 660f540df0e3c500                 andpd  xmm1,XMMWORD PTR ds:0xc5e3f0
0x902072: 660f73d134                       psrlq  xmm1,0x34
0x902077: 660ffacb                         psubd  xmm1,xmm3
0x90207b: 660f121d50e4c500                 movlpd xmm3,QWORD PTR ds:0xc5e450
0x902083: 660ff3d1                         psllq  xmm2,xmm1
0x902087: 660f76d3                         pcmpeqd xmm2,xmm3
0x90208b: 660fd7c2                         pmovmskb eax,xmm2
0x90208f: 25ff000000                       and    eax,0xff
0x902094: b901ff0300                       mov    ecx,0x3ff01
0x902099: 03c8                             add    ecx,eax
0x90209b: 81e100000400                     and    ecx,0x40000
0x9020a1: 83fa10                           cmp    edx,0x10
0x9020a4: 725e                             jb     0x902104
0x9020a6: ba7ffe0b00                       mov    edx,0xbfe7f
0x9020ab: 660f121dd0e3c500                 movlpd xmm3,QWORD PTR ds:0xc5e3d0
0x9020b3: 660f1215e0e3c500                 movlpd xmm2,QWORD PTR ds:0xc5e3e0
0x9020bb: e926fcffff                       jmp    0x901ce6
0x9020c0: 660f127c2404                     movlpd xmm7,QWORD PTR [esp+0x4]
0x9020c6: 660f12642404                     movlpd xmm4,QWORD PTR [esp+0x4]
0x9020cc: 660f7efa                         movd   edx,xmm7
0x9020d0: 660f73d720                       psrlq  xmm7,0x20
0x9020d5: 660f7ef8                         movd   eax,xmm7
0x9020d9: 8bc8                             mov    ecx,eax
0x9020db: 25ffffff7f                       and    eax,0x7fffffff
0x9020e0: 3d0000f07f                       cmp    eax,0x7ff00000
0x9020e5: 0f829a020000                     jb     0x902385
0x9020eb: 0f87de010000                     ja     0x9022cf
0x9020f1: 83fa00                           cmp    edx,0x0
0x9020f4: 0f87d5010000                     ja     0x9022cf
0x9020fa: e986020000                       jmp    0x902385
0x9020ff: b900000000                       mov    ecx,0x0
0x902104: 660f57c0                         xorpd  xmm0,xmm0
0x902108: b8f0430000                       mov    eax,0x43f0
0x90210d: 660fc4c003                       pinsrw xmm0,eax,0x3
0x902112: 660f123dd0e3c500                 movlpd xmm7,QWORD PTR ds:0xc5e3d0
0x90211a: 660f1215e0e3c500                 movlpd xmm2,QWORD PTR ds:0xc5e3e0
0x902122: f20f59c4                         mulsd  xmm0,xmm4
0x902126: 660f7ee2                         movd   edx,xmm4
0x90212a: 660f73d420                       psrlq  xmm4,0x20
0x90212f: 660f7ee0                         movd   eax,xmm4
0x902133: 83fa00                           cmp    edx,0x0
0x902136: 7452                             je     0x90218a
0x902138: 660f54f8                         andpd  xmm7,xmm0
0x90213c: f20f10e0                         movsd  xmm4,xmm0
0x902140: 660f5405f0e3c500                 andpd  xmm0,XMMWORD PTR ds:0xc5e3f0
0x902148: 660f73d02c                       psrlq  xmm0,0x2c
0x90214d: 660fc5c000                       pextrw eax,xmm0,0x0
0x902152: 660f56fa                         orpd   xmm7,xmm2
0x902156: 25ff000000                       and    eax,0xff
0x90215b: 83c001                           add    eax,0x1
0x90215e: 25fe010000                       and    eax,0x1fe
0x902163: f20f593c8540abc500               mulsd  xmm7,QWORD PTR [eax*4+0xc5ab40]
0x90216c: 660f122c8540abc500               movlpd xmm5,QWORD PTR [eax*4+0xc5ab40]
0x902175: 03c0                             add    eax,eax
0x902177: 660f28348550afc500               movapd xmm6,XMMWORD PTR [eax*4+0xc5af50]
0x902180: ba7f3e0400                       mov    edx,0x43e7f
0x902185: e95cfbffff                       jmp    0x901ce6
0x90218a: 8bd0                             mov    edx,eax
0x90218c: 81e2ffffff7f                     and    edx,0x7fffffff
0x902192: 83fa00                           cmp    edx,0x0
0x902195: 75a1                             jne    0x902138
0x902197: 8b542410                         mov    edx,DWORD PTR [esp+0x10]
0x90219b: 81e200000080                     and    edx,0x80000000
0x9021a1: 83fa00                           cmp    edx,0x0
0x9021a4: 7431                             je     0x9021d7
0x9021a6: c1e10d                           shl    ecx,0xd
0x9021a9: 23c1                             and    eax,ecx
0x9021ab: ba0000f07f                       mov    edx,0x7ff00000
0x9021b0: 0bd0                             or     edx,eax
0x9021b2: 660f6ec2                         movd   xmm0,edx
0x9021b6: 660f73f020                       psllq  xmm0,0x20
0x9021bb: 660f120de0e3c500                 movlpd xmm1,QWORD PTR ds:0xc5e3e0
0x9021c3: 660f12542404                     movlpd xmm2,QWORD PTR [esp+0x4]
0x9021c9: f20f5eca                         divsd  xmm1,xmm2
0x9021cd: ba1b000000                       mov    edx,0x1b
0x9021d2: e999020000                       jmp    0x902470
0x9021d7: c1e10d                           shl    ecx,0xd
0x9021da: 23c1                             and    eax,ecx
0x9021dc: 83f800                           cmp    eax,0x0
0x9021df: 0f85a4000000                     jne    0x902289
0x9021e5: d9ee                             fldz
0x9021e7: c3                               ret
0x9021e8: 660f121dd0e3c500                 movlpd xmm3,QWORD PTR ds:0xc5e3d0
0x9021f0: 660f57c9                         xorpd  xmm1,xmm1
0x9021f4: 660f54dc                         andpd  xmm3,xmm4
0x9021f8: 660f76cb                         pcmpeqd xmm1,xmm3
0x9021fc: 660fd7c9                         pmovmskb ecx,xmm1
0x902200: 81e1ff000000                     and    ecx,0xff
0x902206: 81f9ff000000                     cmp    ecx,0xff
0x90220c: 0f85bd000000                     jne    0x9022cf
0x902212: 660fc5cc03                       pextrw ecx,xmm4,0x3
0x902217: 81e100800000                     and    ecx,0x8000
0x90221d: 83f900                           cmp    ecx,0x0
0x902220: 0f848d000000                     je     0x9022b3
0x902226: 25ff000000                       and    eax,0xff
0x90222b: 3dff000000                       cmp    eax,0xff
0x902230: 7565                             jne    0x902297
0x902232: 660f124c240c                     movlpd xmm1,QWORD PTR [esp+0xc]
0x902238: 660f1254240c                     movlpd xmm2,QWORD PTR [esp+0xc]
0x90223e: b9f4030000                       mov    ecx,0x3f4
0x902243: 660f6ed9                         movd   xmm3,ecx
0x902247: 660f540df0e3c500                 andpd  xmm1,XMMWORD PTR ds:0xc5e3f0
0x90224f: 660f73d134                       psrlq  xmm1,0x34
0x902254: 660ffacb                         psubd  xmm1,xmm3
0x902258: 660fefdb                         pxor   xmm3,xmm3
0x90225c: 660ff3d1                         psllq  xmm2,xmm1
0x902260: 660f76d3                         pcmpeqd xmm2,xmm3
0x902264: 660fd7c2                         pmovmskb eax,xmm2
0x902268: 25ff000000                       and    eax,0xff
0x90226d: 3dff000000                       cmp    eax,0xff
0x902272: 7423                             je     0x902297
0x902274: 660f124c240c                     movlpd xmm1,QWORD PTR [esp+0xc]
0x90227a: 660fc5c103                       pextrw eax,xmm1,0x3
0x90227f: 2500800000                       and    eax,0x8000
0x902284: 83f800                           cmp    eax,0x0
0x902287: 7407                             je     0x902290
0x902289: dd0550e4c500                     fld    QWORD PTR ds:0xc5e450
0x90228f: c3                               ret
0x902290: dd0548e4c500                     fld    QWORD PTR ds:0xc5e448
0x902296: c3                               ret
0x902297: 660f124c240c                     movlpd xmm1,QWORD PTR [esp+0xc]
0x90229d: 660fc5c103                       pextrw eax,xmm1,0x3
0x9022a2: 2500800000                       and    eax,0x8000
0x9022a7: 83f800                           cmp    eax,0x0
0x9022aa: 0f8447010000                     je     0x9023f7
0x9022b0: d9ee                             fldz
0x9022b2: c3                               ret
0x9022b3: 660f124c240c                     movlpd xmm1,QWORD PTR [esp+0xc]
0x9022b9: 660fc5c103                       pextrw eax,xmm1,0x3
0x9022be: 2500800000                       and    eax,0x8000
0x9022c3: 83f800                           cmp    eax,0x0
0x9022c6: 0f842b010000                     je     0x9023f7
0x9022cc: d9ee                             fldz
0x9022ce: c3                               ret
0x9022cf: f20f58e4                         addsd  xmm4,xmm4
0x9022d3: f20f10c4                         movsd  xmm0,xmm4
0x9022d7: baee030000                       mov    edx,0x3ee
0x9022dc: e98f010000                       jmp    0x902470
0x9022e1: 660f12542404                     movlpd xmm2,QWORD PTR [esp+0x4]
0x9022e7: 660f7ed0                         movd   eax,xmm2
0x9022eb: 660f73d220                       psrlq  xmm2,0x20
0x9022f0: 660f7ed2                         movd   edx,xmm2
0x9022f4: 81e2ffffff7f                     and    edx,0x7fffffff
0x9022fa: 0bc2                             or     eax,edx
0x9022fc: b900000000                       mov    ecx,0x0
0x902301: 83f800                           cmp    eax,0x0
0x902304: 0f8480feffff                     je     0x90218a
0x90230a: 660f120d38e4c500                 movlpd xmm1,QWORD PTR ds:0xc5e438
0x902312: 660f120570e4c500                 movlpd xmm0,QWORD PTR ds:0xc5e470
0x90231a: f20f59c9                         mulsd  xmm1,xmm1
0x90231e: ba1c000000                       mov    edx,0x1c
0x902323: e948010000                       jmp    0x902470
0x902328: 660f12642404                     movlpd xmm4,QWORD PTR [esp+0x4]
0x90232e: 660f1254240c                     movlpd xmm2,QWORD PTR [esp+0xc]
0x902334: 660f121dd0e3c500                 movlpd xmm3,QWORD PTR ds:0xc5e3d0
0x90233c: 660f57c9                         xorpd  xmm1,xmm1
0x902340: 660f54da                         andpd  xmm3,xmm2
0x902344: 660f76cb                         pcmpeqd xmm1,xmm3
0x902348: 660fd7c1                         pmovmskb eax,xmm1
0x90234c: 25ff000000                       and    eax,0xff
0x902351: 3dff000000                       cmp    eax,0xff
0x902356: 0f85a2000000                     jne    0x9023fe
0x90235c: 660f7ee0                         movd   eax,xmm4
0x902360: 83f800                           cmp    eax,0x0
0x902363: 7520                             jne    0x902385
0x902365: 660f73d420                       psrlq  xmm4,0x20
0x90236a: 660f7ee2                         movd   edx,xmm4
0x90236e: 81fa0000f03f                     cmp    edx,0x3ff00000
0x902374: 0f84e9000000                     je     0x902463
0x90237a: 81fa0000f0bf                     cmp    edx,0xbff00000
0x902380: 7503                             jne    0x902385
0x902382: d9e8                             fld1
0x902384: c3                               ret
0x902385: 660f121dd0e3c500                 movlpd xmm3,QWORD PTR ds:0xc5e3d0
0x90238d: 660f57c9                         xorpd  xmm1,xmm1
0x902391: 660f54da                         andpd  xmm3,xmm2
0x902395: 660f76cb                         pcmpeqd xmm1,xmm3
0x902399: 660fd7c1                         pmovmskb eax,xmm1
0x90239d: 25ff000000                       and    eax,0xff
0x9023a2: 3dff000000                       cmp    eax,0xff
0x9023a7: 7555                             jne    0x9023fe
0x9023a9: 660fc5c203                       pextrw eax,xmm2,0x3
0x9023ae: 660f12642404                     movlpd xmm4,QWORD PTR [esp+0x4]
0x9023b4: 2500800000                       and    eax,0x8000
0x9023b9: 81f10000f0bf                     xor    ecx,0xbff00000
0x9023bf: 0bd1                             or     edx,ecx
0x9023c1: 83fa00                           cmp    edx,0x0
0x9023c4: 0f8499000000                     je     0x902463
0x9023ca: 83f800                           cmp    eax,0x0
0x9023cd: 7414                             je     0x9023e3
0x9023cf: 660fc5c403                       pextrw eax,xmm4,0x3
0x9023d4: 25f07f0000                       and    eax,0x7ff0
0x9023d9: 3df03f0000                       cmp    eax,0x3ff0
0x9023de: 7217                             jb     0x9023f7
0x9023e0: d9ee                             fldz
0x9023e2: c3                               ret
0x9023e3: 660fc5c403                       pextrw eax,xmm4,0x3
0x9023e8: 25f07f0000                       and    eax,0x7ff0
0x9023ed: 3df03f0000                       cmp    eax,0x3ff0
0x9023f2: 7303                             jae    0x9023f7
0x9023f4: d9ee                             fldz
0x9023f6: c3                               ret
0x9023f7: dd0540e4c500                     fld    QWORD PTR ds:0xc5e440
0x9023fd: c3                               ret
0x9023fe: f20f58d2                         addsd  xmm2,xmm2
0x902402: f20f10c2                         movsd  xmm0,xmm2
0x902406: baee030000                       mov    edx,0x3ee
0x90240b: eb63                             jmp    0x902470
0x90240d: 660f7ee0                         movd   eax,xmm4
0x902411: 660f73d420                       psrlq  xmm4,0x20
0x902416: 660f7ee2                         movd   edx,xmm4
0x90241a: 81e2ffffff7f                     and    edx,0x7fffffff
0x902420: 8bc8                             mov    ecx,eax
0x902422: 0bc2                             or     eax,edx
0x902424: 660f1205e0e3c500                 movlpd xmm0,QWORD PTR ds:0xc5e3e0
0x90242c: ba1a000000                       mov    edx,0x1a
0x902431: 83f800                           cmp    eax,0x0
0x902434: 743a                             je     0x902470
0x902436: 660f7ee0                         movd   eax,xmm4
0x90243a: ba1d000000                       mov    edx,0x1d
0x90243f: 25ffffff7f                       and    eax,0x7fffffff
0x902444: 3d0000f07f                       cmp    eax,0x7ff00000
0x902449: 7725                             ja     0x902470
0x90244b: 7205                             jb     0x902452
0x90244d: 83f900                           cmp    ecx,0x0
0x902450: 771e                             ja     0x902470
0x902452: 83ec10                           sub    esp,0x10
0x902455: 660f13442404                     movlpd QWORD PTR [esp+0x4],xmm0
0x90245b: dd442404                         fld    QWORD PTR [esp+0x4]
0x90245f: 83c410                           add    esp,0x10
0x902462: c3                               ret
0x902463: 660f120540abc500                 movlpd xmm0,QWORD PTR ds:0xc5ab40
0x90246b: ba1c000000                       mov    edx,0x1c
0x902470: 83ec1c                           sub    esp,0x1c
0x902473: 660f13442410                     movlpd QWORD PTR [esp+0x10],xmm0
0x902479: 8954240c                         mov    DWORD PTR [esp+0xc],edx
0x90247d: 8bd4                             mov    edx,esp
0x90247f: 83c210                           add    edx,0x10
0x902482: 89542408                         mov    DWORD PTR [esp+0x8],edx
0x902486: 83c218                           add    edx,0x18
0x902489: 89542404                         mov    DWORD PTR [esp+0x4],edx
0x90248d: 83ea08                           sub    edx,0x8
0x902490: 891424                           mov    DWORD PTR [esp],edx
0x902493: e8e73ffaff                       call   0x8a647f
0x902498: dd442410                         fld    QWORD PTR [esp+0x10]
0x90249c: 83c41c                           add    esp,0x1c
0x90249f: c3                               ret
0x9024a0: 83f800                           cmp    eax,0x0
0x9024a3: 7e28                             jle    0x9024cd
0x9024a5: 3d00000400                       cmp    eax,0x40000
0x9024aa: 0f833c020000                     jae    0x9026ec
0x9024b0: 56                               push   esi
0x9024b1: 8bd0                             mov    edx,eax
0x9024b3: 83e07f                           and    eax,0x7f
0x9024b6: 81c100ff0300                     add    ecx,0x3ff00
0x9024bc: 81ea80000000                     sub    edx,0x80
0x9024c2: 83e280                           and    edx,0xffffff80
0x9024c5: 57                               push   edi
0x9024c6: bff03f0000                       mov    edi,0x3ff0
0x9024cb: eb26                             jmp    0x9024f3
0x9024cd: 3d0002fcff                       cmp    eax,0xfffc0200
0x9024d2: 0f8ef1010000                     jle    0x9026c9
0x9024d8: 56                               push   esi
0x9024d9: 8bd0                             mov    edx,eax
0x9024db: 83e07f                           and    eax,0x7f
0x9024de: 81c180000000                     add    ecx,0x80
0x9024e4: 83e280                           and    edx,0xffffff80
0x9024e7: 81c280fe0300                     add    edx,0x3fe80
0x9024ed: 57                               push   edi
0x9024ee: bf00000000                       mov    edi,0x0
0x9024f3: f20f58e0                         addsd  xmm4,xmm0
0x9024f7: f20f10c3                         movsd  xmm0,xmm3
0x9024fb: f20f581dc0e3c500                 addsd  xmm3,QWORD PTR ds:0xc5e3c0
0x902503: 8bf2                             mov    esi,edx
0x902505: 81ee80ff0100                     sub    esi,0x1ff80
0x90250b: 660f59d7                         mulpd  xmm2,xmm7
0x90250f: f20f5c1dc0e3c500                 subsd  xmm3,QWORD PTR ds:0xc5e3c0
0x902517: 660f59ff                         mulpd  xmm7,xmm7
0x90251b: f20f5cc3                         subsd  xmm0,xmm3
0x90251f: 03c0                             add    eax,eax
0x902521: 03c0                             add    eax,eax
0x902523: 03c0                             add    eax,eax
0x902525: 03c0                             add    eax,eax
0x902527: 660f2898c0dbc500                 movapd xmm3,XMMWORD PTR [eax+0xc5dbc0]
0x90252f: 660f283500e4c500                 movapd xmm6,XMMWORD PTR ds:0xc5e400
0x902537: 660f59cf                         mulpd  xmm1,xmm7
0x90253b: 660f58d1                         addpd  xmm2,xmm1
0x90253f: 660f70caee                       pshufd xmm1,xmm2,0xee
0x902544: f20f59d7                         mulsd  xmm2,xmm7
0x902548: f20f58d1                         addsd  xmm2,xmm1
0x90254c: f20f58d4                         addsd  xmm2,xmm4
0x902550: 660f122520e4c500                 movlpd xmm4,QWORD PTR ds:0xc5e420
0x902558: 660f6eca                         movd   xmm1,edx
0x90255c: 81ea80ff0100                     sub    edx,0x1ff80
0x902562: f7da                             neg    edx
0x902564: c1fa07                           sar    edx,0x7
0x902567: 83c202                           add    edx,0x2
0x90256a: 8bc2                             mov    eax,edx
0x90256c: 83e020                           and    eax,0x20
0x90256f: 03d0                             add    edx,eax
0x902571: 660f57ff                         xorpd  xmm7,xmm7
0x902575: b8803f0000                       mov    eax,0x3f80
0x90257a: 660fc4f803                       pinsrw xmm7,eax,0x3
0x90257f: f20f59542414                     mulsd  xmm2,QWORD PTR [esp+0x14]
0x902585: f20f59c7                         mulsd  xmm0,xmm7
0x902589: 660f73f12d                       psllq  xmm1,0x2d
0x90258e: 660f70c944                       pshufd xmm1,xmm1,0x44
0x902593: 660f283d10e4c500                 movapd xmm7,XMMWORD PTR ds:0xc5e410
0x90259b: f20f58ea                         addsd  xmm5,xmm2
0x90259f: 660f59d9                         mulpd  xmm3,xmm1
0x9025a3: f20f58c5                         addsd  xmm0,xmm5
0x9025a7: 660f14c0                         unpcklpd xmm0,xmm0
0x9025ab: 660f59f0                         mulpd  xmm6,xmm0
0x9025af: f20f59e0                         mulsd  xmm4,xmm0
0x9025b3: 660f59c0                         mulpd  xmm0,xmm0
0x9025b7: 660f58fe                         addpd  xmm7,xmm6
0x9025bb: 660f59f8                         mulpd  xmm7,xmm0
0x9025bf: f20f59c3                         mulsd  xmm0,xmm3
0x9025c3: 660f70f7ee                       pshufd xmm6,xmm7,0xee
0x9025c8: f20f59c7                         mulsd  xmm0,xmm7
0x9025cc: 660f70ebee                       pshufd xmm5,xmm3,0xee
0x9025d1: f20f59f3                         mulsd  xmm6,xmm3
0x9025d5: f20f59e3                         mulsd  xmm4,xmm3
0x9025d9: 660f6ef9                         movd   xmm7,ecx
0x9025dd: 660f73f72d                       psllq  xmm7,0x2d
0x9025e2: 660f6ed2                         movd   xmm2,edx
0x9025e6: 660f76c9                         pcmpeqd xmm1,xmm1
0x9025ea: 660ff3ca                         psllq  xmm1,xmm2
0x9025ee: f20f58c5                         addsd  xmm0,xmm5
0x9025f2: f20f58c6                         addsd  xmm0,xmm6
0x9025f6: 660f54cb                         andpd  xmm1,xmm3
0x9025fa: f20f58c4                         addsd  xmm0,xmm4
0x9025fe: 660f57f6                         xorpd  xmm6,xmm6
0x902602: 660f76e4                         pcmpeqd xmm4,xmm4
0x902606: 660ff3e2                         psllq  xmm4,xmm2
0x90260a: f20f5cd9                         subsd  xmm3,xmm1
0x90260e: f20f10d1                         movsd  xmm2,xmm1
0x902612: f20f58c8                         addsd  xmm1,xmm0
0x902616: 660f54cc                         andpd  xmm1,xmm4
0x90261a: 660fc4f703                       pinsrw xmm6,edi,0x3
0x90261f: 5f                               pop    edi
0x902620: f20f5cd1                         subsd  xmm2,xmm1
0x902624: f20f58c2                         addsd  xmm0,xmm2
0x902628: f20f58c3                         addsd  xmm0,xmm3
0x90262c: 83fe00                           cmp    esi,0x0
0x90262f: 7f4e                             jg     0x90267f
0x902631: 5e                               pop    esi
0x902632: f20f59c7                         mulsd  xmm0,xmm7
0x902636: f20f59cf                         mulsd  xmm1,xmm7
0x90263a: f20f58c1                         addsd  xmm0,xmm1
0x90263e: f20f59f0                         mulsd  xmm6,xmm0
0x902642: f20f58c6                         addsd  xmm0,xmm6
0x902646: 660fc5c003                       pextrw eax,xmm0,0x3
0x90264b: 25f07f0000                       and    eax,0x7ff0
0x902650: ba18000000                       mov    edx,0x18
0x902655: 3df07f0000                       cmp    eax,0x7ff0
0x90265a: 0f8410feffff                     je     0x902470
0x902660: ba19000000                       mov    edx,0x19
0x902665: 83f800                           cmp    eax,0x0
0x902668: 0f8402feffff                     je     0x902470
0x90266e: 83ec10                           sub    esp,0x10
0x902671: 660f13442404                     movlpd QWORD PTR [esp+0x4],xmm0
0x902677: dd442404                         fld    QWORD PTR [esp+0x4]
0x90267b: 83c410                           add    esp,0x10
0x90267e: c3                               ret
0x90267f: 5e                               pop    esi
0x902680: f20f58c1                         addsd  xmm0,xmm1
0x902684: f20f59c7                         mulsd  xmm0,xmm7
0x902688: f20f59f0                         mulsd  xmm6,xmm0
0x90268c: f20f58c6                         addsd  xmm0,xmm6
0x902690: 660fc5c003                       pextrw eax,xmm0,0x3
0x902695: 25f07f0000                       and    eax,0x7ff0
0x90269a: ba18000000                       mov    edx,0x18
0x90269f: 3df07f0000                       cmp    eax,0x7ff0
0x9026a4: 0f84c6fdffff                     je     0x902470
0x9026aa: ba19000000                       mov    edx,0x19
0x9026af: 83f800                           cmp    eax,0x0
0x9026b2: 0f84b8fdffff                     je     0x902470
0x9026b8: 83ec10                           sub    esp,0x10
0x9026bb: 660f13442404                     movlpd QWORD PTR [esp+0x4],xmm0
0x9026c1: dd442404                         fld    QWORD PTR [esp+0x4]
0x9026c5: 83c410                           add    esp,0x10
0x9026c8: c3                               ret
0x9026c9: 660f120568e4c500                 movlpd xmm0,QWORD PTR ds:0xc5e468
0x9026d1: 660f6ec9                         movd   xmm1,ecx
0x9026d5: f20f59c0                         mulsd  xmm0,xmm0
0x9026d9: 660f73f12d                       psllq  xmm1,0x2d
0x9026de: 660f56c1                         orpd   xmm0,xmm1
0x9026e2: ba19000000                       mov    edx,0x19
0x9026e7: e984fdffff                       jmp    0x902470
0x9026ec: ba18000000                       mov    edx,0x18
0x9026f1: 83f900                           cmp    ecx,0x0
0x9026f4: 7415                             je     0x90270b
0x9026f6: 660f120558e4c500                 movlpd xmm0,QWORD PTR ds:0xc5e458
0x9026fe: f20f590560e4c500                 mulsd  xmm0,QWORD PTR ds:0xc5e460
0x902706: e965fdffff                       jmp    0x902470
0x90270b: 660f120560e4c500                 movlpd xmm0,QWORD PTR ds:0xc5e460
0x902713: f20f59c0                         mulsd  xmm0,xmm0
0x902717: e954fdffff                       jmp    0x902470
0x90271c: 660f70e144                       pshufd xmm4,xmm1,0x44
0x902721: 660f59e6                         mulpd  xmm4,xmm6
0x902725: 660fc5c403                       pextrw eax,xmm4,0x3
0x90272a: 25f07f0000                       and    eax,0x7ff0
0x90272f: baa0400000                       mov    edx,0x40a0
0x902734: 2bd0                             sub    edx,eax
0x902736: 2d703c0000                       sub    eax,0x3c70
0x90273b: 0bd0                             or     edx,eax
0x90273d: 81fa00000080                     cmp    edx,0x80000000
0x902743: 0f82eff6ffff                     jb     0x901e38
0x902749: 3d00000080                       cmp    eax,0x80000000
0x90274e: 7220                             jb     0x902770
0x902750: 81c980ff0100                     or     ecx,0x1ff80
0x902756: 660f6ec1                         movd   xmm0,ecx
0x90275a: 660f73f02d                       psllq  xmm0,0x2d
0x90275f: 83ec10                           sub    esp,0x10
0x902762: 660f13442404                     movlpd QWORD PTR [esp+0x4],xmm0
0x902768: dd442404                         fld    QWORD PTR [esp+0x4]
0x90276c: 83c410                           add    esp,0x10
0x90276f: c3                               ret
0x902770: 660f12642404                     movlpd xmm4,QWORD PTR [esp+0x4]
0x902776: 660fc5d403                       pextrw edx,xmm4,0x3
0x90277b: 81e2f07f0000                     and    edx,0x7ff0
0x902781: 81eaf03f0000                     sub    edx,0x3ff0
0x902787: 660fc5c103                       pextrw eax,xmm1,0x3
0x90278c: 33c2                             xor    eax,edx
0x90278e: 2500800000                       and    eax,0x8000
0x902793: 83f800                           cmp    eax,0x0
0x902796: 0f852dffffff                     jne    0x9026c9
0x90279c: e94bffffff                       jmp    0x9026ec
0x9027a1: 8da42400000000                   lea    esp,[esp+0x0]
0x9027a8: 8da42400000000                   lea    esp,[esp+0x0]
0x9027af: 90                               nop

## F-900CE5 VA 0x900ce5..0x900d28 raw 0x5000e5 len 67 SHA256 49756c88592603c59a91d5ecf8589dab665fc8a2ad0f138e5d6e3c3b05c21169
0x900ce5: 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x900ce8: 250000f07f                       and    eax,0x7ff00000
0x900ced: 3d0000f07f                       cmp    eax,0x7ff00000
0x900cf2: 7403                             je     0x900cf7
0x900cf4: dd02                             fld    QWORD PTR [edx]
0x900cf6: c3                               ret
0x900cf7: 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x900cfa: 83ec0a                           sub    esp,0xa
0x900cfd: 0d0000ff7f                       or     eax,0x7fff0000
0x900d02: 89442406                         mov    DWORD PTR [esp+0x6],eax
0x900d06: 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x900d09: 8b0a                             mov    ecx,DWORD PTR [edx]
0x900d0b: 0fa4c80b                         shld   eax,ecx,0xb
0x900d0f: c1e10b                           shl    ecx,0xb
0x900d12: 89442404                         mov    DWORD PTR [esp+0x4],eax
0x900d16: 890c24                           mov    DWORD PTR [esp],ecx
0x900d19: db2c24                           fld    TBYTE PTR [esp]
0x900d1c: 83c40a                           add    esp,0xa
0x900d1f: a900000000                       test   eax,0x0
0x900d24: 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x900d27: c3                               ret

## F-900CB5 VA 0x900cb5..0x900ccc raw 0x5000b5 len 23 SHA256 e6ec999d45c3c78e22ed722d9cdd003ca3e8685d7954a7d030915df1e55eb902
0x900cb5: 8b542404                         mov    edx,DWORD PTR [esp+0x4]
0x900cb9: 81e200030000                     and    edx,0x300
0x900cbf: 83ca7f                           or     edx,0x7f
0x900cc2: 6689542406                       mov    WORD PTR [esp+0x6],dx
0x900cc7: d96c2406                         fldcw  WORD PTR [esp+0x6]
0x900ccb: c3                               ret

## F-900CA0 VA 0x900ca0..0x900cb5 raw 0x5000a0 len 21 SHA256 2dce0bc1ec224128643a743b9a3cab6795651b19324ae7b387a872b7d615ab3b
0x900ca0: d9c0                             fld    st(0)
0x900ca2: d9fc                             frndint
0x900ca4: dce1                             fsubr  st(1),st
0x900ca6: d9c9                             fxch   st(1)
0x900ca8: d9e0                             fchs
0x900caa: d9f0                             f2xm1
0x900cac: d9e8                             fld1
0x900cae: dec1                             faddp  st(1),st
0x900cb0: d9fd                             fscale
0x900cb2: ddd9                             fstp   st(1)
0x900cb4: c3                               ret

## F-900D89 VA 0x900d89..0x900e2c raw 0x500189 len 163 SHA256 292029cf32b504b13de73dcf5f68d9f2675751d29ed7c36f49456c8ca81356ed
0x900d89: 83ec08                           sub    esp,0x8
0x900d8c: dd1424                           fst    QWORD PTR [esp]
0x900d8f: 8b442404                         mov    eax,DWORD PTR [esp+0x4]
0x900d93: 83c408                           add    esp,0x8
0x900d96: 250000f07f                       and    eax,0x7ff00000
0x900d9b: 743d                             je     0x900dda
0x900d9d: 3d0000f07f                       cmp    eax,0x7ff00000
0x900da2: 745f                             je     0x900e03
0x900da4: 668b0424                         mov    ax,WORD PTR [esp]
0x900da8: 663d7f02                         cmp    ax,0x27f
0x900dac: 742a                             je     0x900dd8
0x900dae: 6683e020                         and    ax,0x20
0x900db2: 7521                             jne    0x900dd5
0x900db4: 9bdfe0                           fstsw  ax
0x900db7: 6683e020                         and    ax,0x20
0x900dbb: 7418                             je     0x900dd5
0x900dbd: b808000000                       mov    eax,0x8
0x900dc2: 83fa1d                           cmp    edx,0x1d
0x900dc5: 7407                             je     0x900dce
0x900dc7: e88bfeffff                       call   0x900c57
0x900dcc: 5a                               pop    edx
0x900dcd: c3                               ret
0x900dce: e86dfeffff                       call   0x900c40
0x900dd3: 5a                               pop    edx
0x900dd4: c3                               ret
0x900dd5: d92c24                           fldcw  WORD PTR [esp]
0x900dd8: 5a                               pop    edx
0x900dd9: c3                               ret
0x900dda: dd054c78c500                     fld    QWORD PTR ds:0xc5784c
0x900de0: d9c9                             fxch   st(1)
0x900de2: d9fd                             fscale
0x900de4: ddd9                             fstp   st(1)
0x900de6: d9c0                             fld    st(0)
0x900de8: d9e1                             fabs
0x900dea: dc1d3c78c500                     fcomp  QWORD PTR ds:0xc5783c
0x900df0: 9bdfe0                           fstsw  ax
0x900df3: 9e                               sahf
0x900df4: b804000000                       mov    eax,0x4
0x900df9: 73c7                             jae    0x900dc2
0x900dfb: dc0d5c78c500                     fmul   QWORD PTR ds:0xc5785c
0x900e01: ebbf                             jmp    0x900dc2
0x900e03: dd054478c500                     fld    QWORD PTR ds:0xc57844
0x900e09: d9c9                             fxch   st(1)
0x900e0b: d9fd                             fscale
0x900e0d: ddd9                             fstp   st(1)
0x900e0f: d9c0                             fld    st(0)
0x900e11: d9e1                             fabs
0x900e13: dc1d3478c500                     fcomp  QWORD PTR ds:0xc57834
0x900e19: 9bdfe0                           fstsw  ax
0x900e1c: 9e                               sahf
0x900e1d: b803000000                       mov    eax,0x3
0x900e22: 769e                             jbe    0x900dc2
0x900e24: dc0d5478c500                     fmul   QWORD PTR ds:0xc57854
0x900e2a: eb96                             jmp    0x900dc2

## F-900C40 VA 0x900c40..0x900c57 raw 0x500040 len 23 SHA256 0f6bedbaacb032256ec1d8adf83f852975544b42c821b77ce77abfd6ee3580e1
0x900c40: 55                               push   ebp
0x900c41: 8bec                             mov    ebp,esp
0x900c43: 83c4e0                           add    esp,0xffffffe0
0x900c46: 8945e0                           mov    DWORD PTR [ebp-0x20],eax
0x900c49: 8b4518                           mov    eax,DWORD PTR [ebp+0x18]
0x900c4c: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x900c4f: 8b451c                           mov    eax,DWORD PTR [ebp+0x1c]
0x900c52: 8945f4                           mov    DWORD PTR [ebp-0xc],eax
0x900c55: eb09                             jmp    0x900c60

## F-900C57 VA 0x900c57..0x900cb5 raw 0x500057 len 94 SHA256 6ed173763c726c66da072d84e640050294b388ec4a23f569fea692413411f219
0x900c57: 55                               push   ebp
0x900c58: 8bec                             mov    ebp,esp
0x900c5a: 83c4e0                           add    esp,0xffffffe0
0x900c5d: 8945e0                           mov    DWORD PTR [ebp-0x20],eax
0x900c60: dd5df8                           fstp   QWORD PTR [ebp-0x8]
0x900c63: 894de4                           mov    DWORD PTR [ebp-0x1c],ecx
0x900c66: 8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x900c69: 8b4d14                           mov    ecx,DWORD PTR [ebp+0x14]
0x900c6c: 8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x900c6f: 894dec                           mov    DWORD PTR [ebp-0x14],ecx
0x900c72: 8d4508                           lea    eax,[ebp+0x8]
0x900c75: 8d4de0                           lea    ecx,[ebp-0x20]
0x900c78: 50                               push   eax
0x900c79: 51                               push   ecx
0x900c7a: 52                               push   edx
0x900c7b: e870280000                       call   0x9034f0
0x900c80: 83c40c                           add    esp,0xc
0x900c83: dd45f8                           fld    QWORD PTR [ebp-0x8]
0x900c86: 66817d087f02                     cmp    WORD PTR [ebp+0x8],0x27f
0x900c8c: 7403                             je     0x900c91
0x900c8e: d96d08                           fldcw  WORD PTR [ebp+0x8]
0x900c91: c9                               leave
0x900c92: c3                               ret
0x900c93: cc                               int3
0x900c94: cc                               int3
0x900c95: cc                               int3
0x900c96: cc                               int3
0x900c97: cc                               int3
0x900c98: cc                               int3
0x900c99: cc                               int3
0x900c9a: cc                               int3
0x900c9b: cc                               int3
0x900c9c: cc                               int3
0x900c9d: cc                               int3
0x900c9e: cc                               int3
0x900c9f: cc                               int3
0x900ca0: d9c0                             fld    st(0)
0x900ca2: d9fc                             frndint
0x900ca4: dce1                             fsubr  st(1),st
0x900ca6: d9c9                             fxch   st(1)
0x900ca8: d9e0                             fchs
0x900caa: d9f0                             f2xm1
0x900cac: d9e8                             fld1
0x900cae: dec1                             faddp  st(1),st
0x900cb0: d9fd                             fscale
0x900cb2: ddd9                             fstp   st(1)
0x900cb4: c3                               ret

## F-900D3E VA 0x900d3e..0x900d4b raw 0x50013e len 13 SHA256 b0971b5d2cb4945dc056293d2dac8d989fc1d1488b22edb4125e67fdf93c85bd
0x900d3e: 66813c247f02                     cmp    WORD PTR [esp],0x27f
0x900d44: 7403                             je     0x900d49
0x900d46: d92c24                           fldcw  WORD PTR [esp]
0x900d49: 5a                               pop    edx
0x900d4a: c3                               ret

## F-90281A VA 0x90281a..0x902945 raw 0x501c1a len 299 SHA256 87c66c61e942fbdb0dc22baf785fd9e5e6e24195aafe187543139a596f3b1d0d
0x90281a: 8bff                             mov    edi,edi
0x90281c: 55                               push   ebp
0x90281d: 8bec                             mov    ebp,esp
0x90281f: dd4508                           fld    QWORD PTR [ebp+0x8]
0x902822: 56                               push   esi
0x902823: b80000f07f                       mov    eax,0x7ff00000
0x902828: d9e1                             fabs
0x90282a: 33d2                             xor    edx,edx
0x90282c: 33f6                             xor    esi,esi
0x90282e: b90000f0ff                       mov    ecx,0xfff00000
0x902833: 394514                           cmp    DWORD PTR [ebp+0x14],eax
0x902836: 753a                             jne    0x902872
0x902838: 395510                           cmp    DWORD PTR [ebp+0x10],edx
0x90283b: 757a                             jne    0x9028b7
0x90283d: d9e8                             fld1
0x90283f: d8d1                             fcom   st(1)
0x902841: dfe0                             fnstsw ax
0x902843: f6c405                           test   ah,0x5
0x902846: 7a0f                             jp     0x902857
0x902848: ddd8                             fstp   st(0)
0x90284a: ddd8                             fstp   st(0)
0x90284c: dd05682bd600                     fld    QWORD PTR ds:0xd62b68
0x902852: e9e4000000                       jmp    0x90293b
0x902857: d8d1                             fcom   st(1)
0x902859: dfe0                             fnstsw ax
0x90285b: ddd9                             fstp   st(1)
0x90285d: f6c441                           test   ah,0x41
0x902860: 8b4518                           mov    eax,DWORD PTR [ebp+0x18]
0x902863: 0f85d5000000                     jne    0x90293e
0x902869: ddd8                             fstp   st(0)
0x90286b: d9ee                             fldz
0x90286d: e9cc000000                       jmp    0x90293e
0x902872: 394d14                           cmp    DWORD PTR [ebp+0x14],ecx
0x902875: 7540                             jne    0x9028b7
0x902877: 395510                           cmp    DWORD PTR [ebp+0x10],edx
0x90287a: 753b                             jne    0x9028b7
0x90287c: d9e8                             fld1
0x90287e: d8d1                             fcom   st(1)
0x902880: dfe0                             fnstsw ax
0x902882: f6c405                           test   ah,0x5
0x902885: 7a0b                             jp     0x902892
0x902887: ddd8                             fstp   st(0)
0x902889: ddd8                             fstp   st(0)
0x90288b: d9ee                             fldz
0x90288d: e9a9000000                       jmp    0x90293b
0x902892: ded9                             fcompp
0x902894: dfe0                             fnstsw ax
0x902896: f6c441                           test   ah,0x41
0x902899: 8b4518                           mov    eax,DWORD PTR [ebp+0x18]
0x90289c: 750b                             jne    0x9028a9
0x90289e: dd05682bd600                     fld    QWORD PTR ds:0xd62b68
0x9028a4: e995000000                       jmp    0x90293e
0x9028a9: dd05702bd600                     fld    QWORD PTR ds:0xd62b70
0x9028af: 33f6                             xor    esi,esi
0x9028b1: 46                               inc    esi
0x9028b2: e987000000                       jmp    0x90293e
0x9028b7: ddd8                             fstp   st(0)
0x9028b9: 39450c                           cmp    DWORD PTR [ebp+0xc],eax
0x9028bc: 7528                             jne    0x9028e6
0x9028be: 395508                           cmp    DWORD PTR [ebp+0x8],edx
0x9028c1: 757d                             jne    0x902940
0x9028c3: d9ee                             fldz
0x9028c5: dc5510                           fcom   QWORD PTR [ebp+0x10]
0x9028c8: dfe0                             fnstsw ax
0x9028ca: f6c405                           test   ah,0x5
0x9028cd: 0f8b77ffffff                     jnp    0x90284a
0x9028d3: dc5510                           fcom   QWORD PTR [ebp+0x10]
0x9028d6: dfe0                             fnstsw ax
0x9028d8: f6c441                           test   ah,0x41
0x9028db: 8b4518                           mov    eax,DWORD PTR [ebp+0x18]
0x9028de: 745e                             je     0x90293e
0x9028e0: ddd8                             fstp   st(0)
0x9028e2: d9e8                             fld1
0x9028e4: eb58                             jmp    0x90293e
0x9028e6: 394d0c                           cmp    DWORD PTR [ebp+0xc],ecx
0x9028e9: 7555                             jne    0x902940
0x9028eb: 395508                           cmp    DWORD PTR [ebp+0x8],edx
0x9028ee: 7550                             jne    0x902940
0x9028f0: dd4510                           fld    QWORD PTR [ebp+0x10]
0x9028f3: 51                               push   ecx
0x9028f4: 51                               push   ecx
0x9028f5: dd1c24                           fstp   QWORD PTR [esp]
0x9028f8: e8b3feffff                       call   0x9027b0
0x9028fd: d9ee                             fldz
0x9028ff: 59                               pop    ecx
0x902900: dc5510                           fcom   QWORD PTR [ebp+0x10]
0x902903: 59                               pop    ecx
0x902904: 8bc8                             mov    ecx,eax
0x902906: dfe0                             fnstsw ax
0x902908: f6c405                           test   ah,0x5
0x90290b: 7a11                             jp     0x90291e
0x90290d: ddd8                             fstp   st(0)
0x90290f: dd05682bd600                     fld    QWORD PTR ds:0xd62b68
0x902915: 83f901                           cmp    ecx,0x1
0x902918: 7521                             jne    0x90293b
0x90291a: d9e0                             fchs
0x90291c: eb1d                             jmp    0x90293b
0x90291e: dc5510                           fcom   QWORD PTR [ebp+0x10]
0x902921: dfe0                             fnstsw ax
0x902923: f6c441                           test   ah,0x41
0x902926: 750f                             jne    0x902937
0x902928: 83f901                           cmp    ecx,0x1
0x90292b: 750e                             jne    0x90293b
0x90292d: ddd8                             fstp   st(0)
0x90292f: dd05882bd600                     fld    QWORD PTR ds:0xd62b88
0x902935: eb04                             jmp    0x90293b
0x902937: ddd8                             fstp   st(0)
0x902939: d9e8                             fld1
0x90293b: 8b4518                           mov    eax,DWORD PTR [ebp+0x18]
0x90293e: dd18                             fstp   QWORD PTR [eax]
0x902940: 8bc6                             mov    eax,esi
0x902942: 5e                               pop    esi
0x902943: 5d                               pop    ebp
0x902944: c3                               ret

## F-9027B0 VA 0x9027b0..0x90281a raw 0x501bb0 len 106 SHA256 4580c87b2f0a1890dc273d94087323a75185e4a17b5cfe23079a033a3bcef880
0x9027b0: 8bff                             mov    edi,edi
0x9027b2: 55                               push   ebp
0x9027b3: 8bec                             mov    ebp,esp
0x9027b5: 51                               push   ecx
0x9027b6: 51                               push   ecx
0x9027b7: dd4508                           fld    QWORD PTR [ebp+0x8]
0x9027ba: 51                               push   ecx
0x9027bb: 51                               push   ecx
0x9027bc: dd1c24                           fstp   QWORD PTR [esp]
0x9027bf: e86198f9ff                       call   0x89c025
0x9027c4: 59                               pop    ecx
0x9027c5: 59                               pop    ecx
0x9027c6: a890                             test   al,0x90
0x9027c8: 754c                             jne    0x902816
0x9027ca: dd4508                           fld    QWORD PTR [ebp+0x8]
0x9027cd: 51                               push   ecx
0x9027ce: 51                               push   ecx
0x9027cf: dd1c24                           fstp   QWORD PTR [esp]
0x9027d2: e87bfffaff                       call   0x8b2752
0x9027d7: dd4508                           fld    QWORD PTR [ebp+0x8]
0x9027da: 59                               pop    ecx
0x9027db: dae9                             fucompp
0x9027dd: 59                               pop    ecx
0x9027de: dfe0                             fnstsw ax
0x9027e0: f6c444                           test   ah,0x44
0x9027e3: 7a31                             jp     0x902816
0x9027e5: dd4508                           fld    QWORD PTR [ebp+0x8]
0x9027e8: 51                               push   ecx
0x9027e9: dc0db056c500                     fmul   QWORD PTR ds:0xc556b0
0x9027ef: 51                               push   ecx
0x9027f0: dd5df8                           fstp   QWORD PTR [ebp-0x8]
0x9027f3: dd45f8                           fld    QWORD PTR [ebp-0x8]
0x9027f6: dd1c24                           fstp   QWORD PTR [esp]
0x9027f9: e854fffaff                       call   0x8b2752
0x9027fe: dd45f8                           fld    QWORD PTR [ebp-0x8]
0x902801: 59                               pop    ecx
0x902802: dae9                             fucompp
0x902804: 59                               pop    ecx
0x902805: dfe0                             fnstsw ax
0x902807: f6c444                           test   ah,0x44
0x90280a: 7a05                             jp     0x902811
0x90280c: 6a02                             push   0x2
0x90280e: 58                               pop    eax
0x90280f: c9                               leave
0x902810: c3                               ret
0x902811: 33c0                             xor    eax,eax
0x902813: 40                               inc    eax
0x902814: c9                               leave
0x902815: c3                               ret
0x902816: 33c0                             xor    eax,eax
0x902818: c9                               leave
0x902819: c3                               ret

## R-491FCC VA 0x491fc7..0x492007 raw 0x913c7 len 64 SHA256 4eafb5fcfc9909b556c7eed58faa34bde640ff9b6e8ec5e0cb89481ac71b7e6f
0x491fc7: e86433f9ff                       call   0x425330
0x491fcc: 8bf0                             mov    esi,eax
0x491fce: e8ad4b0600                       call   0x4f6b80
0x491fd3: 80bb9000000000                   cmp    BYTE PTR [ebx+0x90],0x0
0x491fda: 7508                             jne    0x491fe4
0x491fdc: 53                               push   ebx
0x491fdd: e85e2a3700                       call   0x804a40
0x491fe2: eb07                             jmp    0x491feb
0x491fe4: 8bf3                             mov    esi,ebx
0x491fe6: e8852c3700                       call   0x804c70
0x491feb: 53                               push   ebx
0x491fec: e8cf2f3700                       call   0x804fc0
0x491ff1: 8b442418                         mov    eax,DWORD PTR [esp+0x18]
0x491ff5: 8b8c2450030000                   mov    ecx,DWORD PTR [esp+0x350]
0x491ffc: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x492003: 59                               pop    ecx
0x492004: 5f                               pop    edi
0x492005: 5e                               pop    esi
0x492006: 5b                               pop    ebx

## R-53CC33 VA 0x53cc2e..0x53cc63 raw 0x13c02e len 53 SHA256 567faef7a4c75231fb180272003843cdef982de910dbdd4faa93b118c67fddd2
0x53cc2e: e8fd86eeff                       call   0x425330
0x53cc33: 8bf8                             mov    edi,eax
0x53cc35: 8d45b8                           lea    eax,[ebp-0x48]
0x53cc38: e8e39efbff                       call   0x4f6b20
0x53cc3d: e87e88ecff                       call   0x4054c0
0x53cc42: 53                               push   ebx
0x53cc43: 53                               push   ebx
0x53cc44: 83ec1c                           sub    esp,0x1c
0x53cc47: 8bcc                             mov    ecx,esp
0x53cc49: 8965b0                           mov    DWORD PTR [ebp-0x50],esp
0x53cc4c: 68fcd1be00                       push   0xbed1fc
0x53cc51: e8fa55ecff                       call   0x402250
0x53cc56: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x53cc5a: 837dcc08                         cmp    DWORD PTR [ebp-0x34],0x8
0x53cc5e: 8b7db8                           mov    edi,DWORD PTR [ebp-0x48]
0x53cc61: 7303                             jae    0x53cc66

## R-4D607F VA 0x4d607a..0x4d60d0 raw 0xd547a len 86 SHA256 5b49ea9b52567d4dbf6a0fbae44155e1cb5ad29b9f467e8d58e7d5c69d1e122d
0x4d607a: e8b1f2f4ff                       call   0x425330
0x4d607f: 8bf8                             mov    edi,eax
0x4d6081: e89a0c0200                       call   0x4f6d20
0x4d6086: 84c0                             test   al,al
0x4d6088: 0f8476feffff                     je     0x4d5f04
0x4d608e: e8cd8ff3ff                       call   0x40f060
0x4d6093: 8bf0                             mov    esi,eax
0x4d6095: 8b85a8fcffff                     mov    eax,DWORD PTR [ebp-0x358]
0x4d609b: e8309a0000                       call   0x4dfad0
0x4d60a0: 0fb74014                         movzx  eax,WORD PTR [eax+0x14]
0x4d60a4: 6685c0                           test   ax,ax
0x4d60a7: 0f8457feffff                     je     0x4d5f04
0x4d60ad: 8bf0                             mov    esi,eax
0x4d60af: e8cce5f3ff                       call   0x414680
0x4d60b4: 56                               push   esi
0x4d60b5: e886e1fcff                       call   0x4a4240
0x4d60ba: 8d8d24fdffff                     lea    ecx,[ebp-0x2dc]
0x4d60c0: e87b430200                       call   0x4fa440
0x4d60c5: e9b2040000                       jmp    0x4d657c
0x4d60ca: 8b8524fdffff                     mov    eax,DWORD PTR [ebp-0x2dc]

## R-4D6587 VA 0x4d657c..0x4d658a raw 0xd597c len 14 SHA256 1af6ec619706a6e035e8f47dd864296cbfe7d18b99099df18261fdc3ce480142
0x4d657c: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4d657f: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4d6586: 59                               pop    ecx
0x4d6587: 5f                               pop    edi
0x4d6588: 5e                               pop    esi
0x4d6589: 5b                               pop    ebx

## R-4B4152 VA 0x4b4152..0x4b4222 raw 0xb3552 len 208 SHA256 5c14c3bcd05af5503d8d33e326a6785299bba47742aaa069e6bc0186f2208e32
0x4b4152: bf7074fb00                       mov    edi,0xfb7470
0x4b4157: e8242d0400                       call   0x4f6e80
0x4b415c: 8bc8                             mov    ecx,eax
0x4b415e: c745e80f000000                   mov    DWORD PTR [ebp-0x18],0xf
0x4b4165: 895de4                           mov    DWORD PTR [ebp-0x1c],ebx
0x4b4168: 885dd4                           mov    BYTE PTR [ebp-0x2c],bl
0x4b416b: 8d7101                           lea    esi,[ecx+0x1]
0x4b416e: 8bff                             mov    edi,edi
0x4b4170: 8a11                             mov    dl,BYTE PTR [ecx]
0x4b4172: 41                               inc    ecx
0x4b4173: 3ad3                             cmp    dl,bl
0x4b4175: 75f9                             jne    0x4b4170
0x4b4177: 2bce                             sub    ecx,esi
0x4b4179: 51                               push   ecx
0x4b417a: 50                               push   eax
0x4b417b: 8d4dd4                           lea    ecx,[ebp-0x2c]
0x4b417e: e8ede8f4ff                       call   0x402a70
0x4b4183: be01000000                       mov    esi,0x1
0x4b4188: 8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x4b418b: f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x4b4192: 7520                             jne    0x4b41b4
0x4b4194: 09352888fb00                     or     DWORD PTR ds:0xfb8828,esi
0x4b419a: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x4b419e: e8adb60900                       call   0x54f850
0x4b41a3: 6880d5bc00                       push   0xbcd580
0x4b41a8: e86de13d00                       call   0x89231a
0x4b41ad: 83c404                           add    esp,0x4
0x4b41b0: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x4b41b4: f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x4b41bb: 668b1dea90fb00                   mov    bx,WORD PTR ds:0xfb90ea
0x4b41c2: 7520                             jne    0x4b41e4
0x4b41c4: 09352888fb00                     or     DWORD PTR ds:0xfb8828,esi
0x4b41ca: c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x4b41ce: e87db60900                       call   0x54f850
0x4b41d3: 6880d5bc00                       push   0xbcd580
0x4b41d8: e83de13d00                       call   0x89231a
0x4b41dd: 83c404                           add    esp,0x4
0x4b41e0: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x4b41e4: f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x4b41eb: f30f10055c93fb00                 movss  xmm0,DWORD PTR ds:0xfb935c
0x4b41f3: f30f1145b4                       movss  DWORD PTR [ebp-0x4c],xmm0
0x4b41f8: 7520                             jne    0x4b421a
0x4b41fa: 0935c00ffc00                     or     DWORD PTR ds:0xfc0fc0,esi
0x4b4200: c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x4b4204: e8474c2200                       call   0x6d8e50
0x4b4209: 68b0dbbc00                       push   0xbcdbb0
0x4b420e: e807e13d00                       call   0x89231a
0x4b4213: 83c404                           add    esp,0x4
0x4b4216: c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x4b421a: 8b75d4                           mov    esi,DWORD PTR [ebp-0x2c]
0x4b421d: bf10000000                       mov    edi,0x10

## R-4BAD73 VA 0x4bad73..0x4baeb9 raw 0xba173 len 326 SHA256 0496e180f799e2a4f71933e8af17796d976d4dd4a37f91937ec0aedd25fdac5a
0x4bad73: bf7074fb00                       mov    edi,0xfb7470
0x4bad78: e803c10300                       call   0x4f6e80
0x4bad7d: f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x4bad84: 8bd8                             mov    ebx,eax
0x4bad86: 7530                             jne    0x4badb8
0x4bad88: 830d2888fb0001                   or     DWORD PTR ds:0xfb8828,0x1
0x4bad8f: c78424980000000e000000           mov    DWORD PTR [esp+0x98],0xe
0x4bad9a: e8b14a0900                       call   0x54f850
0x4bad9f: 6880d5bc00                       push   0xbcd580
0x4bada4: e871753d00                       call   0x89231a
0x4bada9: 83c404                           add    esp,0x4
0x4badac: 83ceff                           or     esi,0xffffffff
0x4badaf: 89b42498000000                   mov    DWORD PTR [esp+0x98],esi
0x4badb6: eb03                             jmp    0x4badbb
0x4badb8: 83ceff                           or     esi,0xffffffff
0x4badbb: f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x4badc2: 668b3dea90fb00                   mov    di,WORD PTR ds:0xfb90ea
0x4badc9: 752b                             jne    0x4badf6
0x4badcb: 830d2888fb0001                   or     DWORD PTR ds:0xfb8828,0x1
0x4badd2: c78424980000000f000000           mov    DWORD PTR [esp+0x98],0xf
0x4baddd: e86e4a0900                       call   0x54f850
0x4bade2: 6880d5bc00                       push   0xbcd580
0x4bade7: e82e753d00                       call   0x89231a
0x4badec: 83c404                           add    esp,0x4
0x4badef: 89b42498000000                   mov    DWORD PTR [esp+0x98],esi
0x4badf6: f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x4badfd: f30f10055c93fb00                 movss  xmm0,DWORD PTR ds:0xfb935c
0x4bae05: f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x4bae0b: 755f                             jne    0x4bae6c
0x4bae0d: 830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x4bae14: c784249800000010000000           mov    DWORD PTR [esp+0x98],0x10
0x4bae1f: e82ce02100                       call   0x6d8e50
0x4bae24: 68b0dbbc00                       push   0xbcdbb0
0x4bae29: e8ec743d00                       call   0x89231a
0x4bae2e: 83c404                           add    esp,0x4
0x4bae31: 89b42498000000                   mov    DWORD PTR [esp+0x98],esi
0x4bae38: f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x4bae3f: 752b                             jne    0x4bae6c
0x4bae41: 830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x4bae48: c784249800000011000000           mov    DWORD PTR [esp+0x98],0x11
0x4bae53: e8f8df2100                       call   0x6d8e50
0x4bae58: 68b0dbbc00                       push   0xbcdbb0
0x4bae5d: e8b8743d00                       call   0x89231a
0x4bae62: 83c404                           add    esp,0x4
0x4bae65: 89b42498000000                   mov    DWORD PTR [esp+0x98],esi
0x4bae6c: d9442414                         fld    DWORD PTR [esp+0x14]
0x4bae70: 0fbfd7                           movsx  edx,di
0x4bae73: 89542414                         mov    DWORD PTR [esp+0x14],edx
0x4bae77: db442414                         fild   DWORD PTR [esp+0x14]
0x4bae7b: dec9                             fmulp  st(1),st
0x4bae7d: e88e3e4400                       call   0x8fed10
0x4bae82: e8e9fb2100                       call   0x6daa70
0x4bae87: e8843e4400                       call   0x8fed10
0x4bae8c: 0fb7c0                           movzx  eax,ax
0x4bae8f: 50                               push   eax
0x4bae90: 6a00                             push   0x0
0x4bae92: 53                               push   ebx
0x4bae93: 68c80ffc00                       push   0xfc0fc8
0x4bae98: b9fc0ffc00                       mov    ecx,0xfc0ffc
0x4bae9d: e88eec2100                       call   0x6d9b30
0x4baea2: 8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
0x4baea6: 83b8bc5e000000                   cmp    DWORD PTR [eax+0x5ebc],0x0
0x4baead: bfe46ec000                       mov    edi,0xc06ee4
0x4baeb2: 7505                             jne    0x4baeb9
0x4baeb4: bf0c6fc000                       mov    edi,0xc06f0c

## R-6D9616 VA 0x6d9616..0x6d967e raw 0x2d8a16 len 104 SHA256 544f5f615c37c486c8316d893dd91c41263495dd8865f00d096ac5da982d251f
0x6d9616: bf7074fb00                       mov    edi,0xfb7470
0x6d961b: e860d8e1ff                       call   0x4f6e80
0x6d9620: 8bf0                             mov    esi,eax
0x6d9622: 85f6                             test   esi,esi
0x6d9624: 7444                             je     0x6d966a
0x6d9626: f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x6d962d: 7527                             jne    0x6d9656
0x6d962f: b801000000                       mov    eax,0x1
0x6d9634: 09052888fb00                     or     DWORD PTR ds:0xfb8828,eax
0x6d963a: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x6d963d: e80e62e7ff                       call   0x54f850
0x6d9642: 6880d5bc00                       push   0xbcd580
0x6d9647: e8ce8c1b00                       call   0x89231a
0x6d964c: 83c404                           add    esp,0x4
0x6d964f: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x6d9656: 0fb715d692fb00                   movzx  edx,WORD PTR ds:0xfb92d6
0x6d965d: 52                               push   edx
0x6d965e: 6a01                             push   0x1
0x6d9660: 56                               push   esi
0x6d9661: 8d4b6c                           lea    ecx,[ebx+0x6c]
0x6d9664: 53                               push   ebx
0x6d9665: e8c6040000                       call   0x6d9b30
0x6d966a: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x6d966d: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x6d9674: 59                               pop    ecx
0x6d9675: 5f                               pop    edi
0x6d9676: 5e                               pop    esi
0x6d9677: 5b                               pop    ebx
0x6d9678: 8be5                             mov    esp,ebp
0x6d967a: 5d                               pop    ebp
0x6d967b: c20800                           ret    0x8

## W-803F76 VA 0x803f37..0x803f8b raw 0x403337 len 84 SHA256 777ca1f21f285070fd70775ab86dc236f498734e476b7a08be02533e22f3e399
0x803f37: 74f7                             je     0x803f30
0x803f39: eb19                             jmp    0x803f54
0x803f3b: 8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x803f3e: 385815                           cmp    BYTE PTR [eax+0x15],bl
0x803f41: 750f                             jne    0x803f52
0x803f43: 3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x803f46: 750a                             jne    0x803f52
0x803f48: 8bf0                             mov    esi,eax
0x803f4a: 8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x803f4d: 385815                           cmp    BYTE PTR [eax+0x15],bl
0x803f50: 74f1                             je     0x803f43
0x803f52: 8bf0                             mov    esi,eax
0x803f54: 3b770c                           cmp    esi,DWORD PTR [edi+0xc]
0x803f57: 75a8                             jne    0x803f01
0x803f59: 8b5750                           mov    edx,DWORD PTR [edi+0x50]
0x803f5c: 6aff                             push   0xffffffff
0x803f5e: 52                               push   edx
0x803f5f: c7474c01000000                   mov    DWORD PTR [edi+0x4c],0x1
0x803f66: ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
0x803f6c: 8b4750                           mov    eax,DWORD PTR [edi+0x50]
0x803f6f: 50                               push   eax
0x803f70: ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
0x803f76: 891d54a8fb00                     mov    DWORD PTR ds:0xfba854,ebx
0x803f7c: 8d5f18                           lea    ebx,[edi+0x18]
0x803f7f: 895dec                           mov    DWORD PTR [ebp-0x14],ebx
0x803f82: c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x803f86: 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x803f89: 8b08                             mov    ecx,DWORD PTR [eax]

## W-8045EE VA 0x8045af..0x804604 raw 0x4039af len 85 SHA256 4f0f7b56fd64ecde3b0dc997e152371d235140e4c4c38b536c9be4a1beb012cc
0x8045af: 8bbea8000000                     mov    edi,DWORD PTR [esi+0xa8]
0x8045b5: 3bf9                             cmp    edi,ecx
0x8045b7: 7423                             je     0x8045dc
0x8045b9: 8bc1                             mov    eax,ecx
0x8045bb: 2bc1                             sub    eax,ecx
0x8045bd: c1f802                           sar    eax,0x2
0x8045c0: 8d1c8500000000                   lea    ebx,[eax*4+0x0]
0x8045c7: 53                               push   ebx
0x8045c8: 51                               push   ecx
0x8045c9: 57                               push   edi
0x8045ca: e821cd0800                       call   0x8912f0
0x8045cf: 03df                             add    ebx,edi
0x8045d1: 83c40c                           add    esp,0xc
0x8045d4: 899eac000000                     mov    DWORD PTR [esi+0xac],ebx
0x8045da: 33db                             xor    ebx,ebx
0x8045dc: 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x8045e2: 3bcb                             cmp    ecx,ebx
0x8045e4: 740e                             je     0x8045f4
0x8045e6: 8b11                             mov    edx,DWORD PTR [ecx]
0x8045e8: 8b02                             mov    eax,DWORD PTR [edx]
0x8045ea: 6a01                             push   0x1
0x8045ec: ffd0                             call   eax
0x8045ee: 891d54a8fb00                     mov    DWORD PTR ds:0xfba854,ebx
0x8045f4: 8b86a8000000                     mov    eax,DWORD PTR [esi+0xa8]
0x8045fa: 3bc3                             cmp    eax,ebx
0x8045fc: 7409                             je     0x804607
0x8045fe: 50                               push   eax
0x8045ff: e808cc0800                       call   0x89120c

## W-80470F VA 0x8046c5..0x804724 raw 0x403ac5 len 95 SHA256 17741497fcc8c36302f418dc02beb9749a6e1ae62278dffa3f9ea7567dba3c81
0x8046c5: eb05                             jmp    0x8046cc
0x8046c7: e83469c9ff                       call   0x49b000
0x8046cc: a158a8fb00                       mov    eax,ds:0xfba858
0x8046d1: 50                               push   eax
0x8046d2: e849100000                       call   0x805720
0x8046d7: 6a5c                             push   0x5c
0x8046d9: e88acb0800                       call   0x891268
0x8046de: 8bf0                             mov    esi,eax
0x8046e0: 83c404                           add    esp,0x4
0x8046e3: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x8046e6: c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0x8046ed: 85f6                             test   esi,esi
0x8046ef: 7410                             je     0x804701
0x8046f1: 56                               push   esi
0x8046f2: e869f6ffff                       call   0x803d60
0x8046f7: c7064817c500                     mov    DWORD PTR [esi],0xc51748
0x8046fd: 8bce                             mov    ecx,esi
0x8046ff: eb02                             jmp    0x804703
0x804701: 33c9                             xor    ecx,ecx
0x804703: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x80470a: 8b11                             mov    edx,DWORD PTR [ecx]
0x80470c: 8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x80470f: 890d54a8fb00                     mov    DWORD PTR ds:0xfba854,ecx
0x804715: ffd0                             call   eax
0x804717: 8b35a025bd00                     mov    esi,DWORD PTR ds:0xbd25a0
0x80471d: ffd6                             call   esi
0x80471f: 894760                           mov    DWORD PTR [edi+0x60],eax
0x804722: ffd6                             call   esi

## W-42456F VA 0x424523..0x42458f raw 0x23923 len 108 SHA256 b9b4928c3407f4987e36748117123fc08516019cd128433def8bd2fdf5673f7e
0x424523: 8b01                             mov    eax,DWORD PTR [ecx]
0x424525: 8b10                             mov    edx,DWORD PTR [eax]
0x424527: 6a01                             push   0x1
0x424529: ffd2                             call   edx
0x42452b: 68b4000000                       push   0xb4
0x424530: e833cd4600                       call   0x891268
0x424535: 8bf0                             mov    esi,eax
0x424537: 83c404                           add    esp,0x4
0x42453a: 89742410                         mov    DWORD PTR [esp+0x10],esi
0x42453e: c744242005000000                 mov    DWORD PTR [esp+0x20],0x5
0x424546: 85f6                             test   esi,esi
0x424548: 741a                             je     0x424564
0x42454a: 56                               push   esi
0x42454b: e8f0061200                       call   0x544c40
0x424550: c7066cfac000                     mov    DWORD PTR [esi],0xc0fa6c
0x424556: c705aca7fb0001000000             mov    DWORD PTR ds:0xfba7ac,0x1
0x424560: 8bce                             mov    ecx,esi
0x424562: eb02                             jmp    0x424566
0x424564: 33c9                             xor    ecx,ecx
0x424566: 895c2420                         mov    DWORD PTR [esp+0x20],ebx
0x42456a: 8b01                             mov    eax,DWORD PTR [ecx]
0x42456c: 8b5024                           mov    edx,DWORD PTR [eax+0x24]
0x42456f: 890da4a7fb00                     mov    DWORD PTR ds:0xfba7a4,ecx
0x424575: ffd2                             call   edx
0x424577: f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x42457e: 7525                             jne    0x4245a5
0x424580: 830dd4adfa0001                   or     DWORD PTR ds:0xfaadd4,0x1
0x424587: c74424200c000000                 mov    DWORD PTR [esp+0x20],0xc

## W-436AF2 VA 0x436aaa..0x436b07 raw 0x35eaa len 93 SHA256 039b14204948bd0948ae6bfe5c27b98f1fa5f08d9fd1cf4814111e0165126046
0x436aaa: 8b5028                           mov    edx,DWORD PTR [eax+0x28]
0x436aad: ffd2                             call   edx
0x436aaf: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x436ab5: 85c9                             test   ecx,ecx
0x436ab7: 7408                             je     0x436ac1
0x436ab9: 8b01                             mov    eax,DWORD PTR [ecx]
0x436abb: 8b10                             mov    edx,DWORD PTR [eax]
0x436abd: 6a01                             push   0x1
0x436abf: ffd2                             call   edx
0x436ac1: 68c0000000                       push   0xc0
0x436ac6: e89da74500                       call   0x891268
0x436acb: 83c404                           add    esp,0x4
0x436ace: 89442408                         mov    DWORD PTR [esp+0x8],eax
0x436ad2: c744241806000000                 mov    DWORD PTR [esp+0x18],0x6
0x436ada: 85c0                             test   eax,eax
0x436adc: 7408                             je     0x436ae6
0x436ade: 50                               push   eax
0x436adf: e82cd70000                       call   0x444210
0x436ae4: eb02                             jmp    0x436ae8
0x436ae6: 33c0                             xor    eax,eax
0x436ae8: c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x436af0: 8b10                             mov    edx,DWORD PTR [eax]
0x436af2: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x436af7: 8bc8                             mov    ecx,eax
0x436af9: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x436afc: ffd0                             call   eax
0x436afe: f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x436b05: 7529                             jne    0x436b30

## W-456612 VA 0x4565ca..0x456627 raw 0x559ca len 93 SHA256 985d9110248d2f553a4dafa11a1f20c2a55b5d9cb9b4c9a2c9a4e9bebc1e49b1
0x4565ca: 8b5028                           mov    edx,DWORD PTR [eax+0x28]
0x4565cd: ffd2                             call   edx
0x4565cf: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4565d5: 85c9                             test   ecx,ecx
0x4565d7: 7408                             je     0x4565e1
0x4565d9: 8b01                             mov    eax,DWORD PTR [ecx]
0x4565db: 8b10                             mov    edx,DWORD PTR [eax]
0x4565dd: 6a01                             push   0x1
0x4565df: ffd2                             call   edx
0x4565e1: 68c8000000                       push   0xc8
0x4565e6: e87dac4300                       call   0x891268
0x4565eb: 83c404                           add    esp,0x4
0x4565ee: 89442408                         mov    DWORD PTR [esp+0x8],eax
0x4565f2: c744241803000000                 mov    DWORD PTR [esp+0x18],0x3
0x4565fa: 85c0                             test   eax,eax
0x4565fc: 7408                             je     0x456606
0x4565fe: 50                               push   eax
0x4565ff: e88c0d0f00                       call   0x547390
0x456604: eb02                             jmp    0x456608
0x456606: 33c0                             xor    eax,eax
0x456608: c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x456610: 8b10                             mov    edx,DWORD PTR [eax]
0x456612: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x456617: 8bc8                             mov    ecx,eax
0x456619: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x45661c: ffd0                             call   eax
0x45661e: f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x456625: 7529                             jne    0x456650

## W-4BAD15 VA 0x4bacbf..0x4bad2f raw 0xba0bf len 112 SHA256 6dd4b46dd3d1e9a7a5f213a9bedb90da17044cd1dce7ec900e192c020ffea373
0x4bacbf: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bacc1: 8b10                             mov    edx,DWORD PTR [eax]
0x4bacc3: 6a01                             push   0x1
0x4bacc5: ffd2                             call   edx
0x4bacc7: 68b4000000                       push   0xb4
0x4baccc: e897653d00                       call   0x891268
0x4bacd1: 8bf0                             mov    esi,eax
0x4bacd3: 83c404                           add    esp,0x4
0x4bacd6: 89742414                         mov    DWORD PTR [esp+0x14],esi
0x4bacda: c784249800000009000000           mov    DWORD PTR [esp+0x98],0x9
0x4bace5: 85f6                             test   esi,esi
0x4bace7: 741a                             je     0x4bad03
0x4bace9: 56                               push   esi
0x4bacea: e8519f0800                       call   0x544c40
0x4bacef: c7069cf9c000                     mov    DWORD PTR [esi],0xc0f99c
0x4bacf5: c705aca7fb0000000000             mov    DWORD PTR ds:0xfba7ac,0x0
0x4bacff: 8bce                             mov    ecx,esi
0x4bad01: eb02                             jmp    0x4bad05
0x4bad03: 33c9                             xor    ecx,ecx
0x4bad05: c7842498000000ffffffff           mov    DWORD PTR [esp+0x98],0xffffffff
0x4bad10: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bad12: 8b5024                           mov    edx,DWORD PTR [eax+0x24]
0x4bad15: 890da4a7fb00                     mov    DWORD PTR ds:0xfba7a4,ecx
0x4bad1b: ffd2                             call   edx
0x4bad1d: 837d0800                         cmp    DWORD PTR [ebp+0x8],0x0
0x4bad21: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4bad27: b801000000                       mov    eax,0x1
0x4bad2c: 894104                           mov    DWORD PTR [ecx+0x4],eax

## W-4BB758 VA 0x4bb716..0x4bb76d raw 0xbab16 len 87 SHA256 0b1d1f91cfbe1946e6ed5451701a96fb664bba202d6c1e49b0efea58fe03c7d4
0x4bb716: 85c9                             test   ecx,ecx
0x4bb718: 740e                             je     0x4bb728
0x4bb71a: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bb71c: 8b10                             mov    edx,DWORD PTR [eax]
0x4bb71e: 57                               push   edi
0x4bb71f: ffd2                             call   edx
0x4bb721: eb05                             jmp    0x4bb728
0x4bb723: bf01000000                       mov    edi,0x1
0x4bb728: 68c0000000                       push   0xc0
0x4bb72d: e8365b3d00                       call   0x891268
0x4bb732: 83c404                           add    esp,0x4
0x4bb735: 89442418                         mov    DWORD PTR [esp+0x18],eax
0x4bb739: c744244806000000                 mov    DWORD PTR [esp+0x48],0x6
0x4bb741: 85c0                             test   eax,eax
0x4bb743: 7408                             je     0x4bb74d
0x4bb745: 50                               push   eax
0x4bb746: e8f5cd0800                       call   0x548540
0x4bb74b: eb02                             jmp    0x4bb74f
0x4bb74d: 33c0                             xor    eax,eax
0x4bb74f: 83ceff                           or     esi,0xffffffff
0x4bb752: 89742448                         mov    DWORD PTR [esp+0x48],esi
0x4bb756: 8b10                             mov    edx,DWORD PTR [eax]
0x4bb758: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4bb75d: 8bc8                             mov    ecx,eax
0x4bb75f: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4bb762: ffd0                             call   eax
0x4bb764: f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x4bb76b: 7524                             jne    0x4bb791

## W-4BBD9E VA 0x4bbd5b..0x4bbdb3 raw 0xbb15b len 88 SHA256 724f62feda52e48288bec29f63ec4126245cf0d934101047663242dd63dc90dd
0x4bbd5b: 8b5028                           mov    edx,DWORD PTR [eax+0x28]
0x4bbd5e: ffd2                             call   edx
0x4bbd60: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4bbd66: 85c9                             test   ecx,ecx
0x4bbd68: 7407                             je     0x4bbd71
0x4bbd6a: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bbd6c: 8b10                             mov    edx,DWORD PTR [eax]
0x4bbd6e: 57                               push   edi
0x4bbd6f: ffd2                             call   edx
0x4bbd71: 68c0000000                       push   0xc0
0x4bbd76: e8ed543d00                       call   0x891268
0x4bbd7b: 83c404                           add    esp,0x4
0x4bbd7e: 89442418                         mov    DWORD PTR [esp+0x18],eax
0x4bbd82: c744242805000000                 mov    DWORD PTR [esp+0x28],0x5
0x4bbd8a: 85c0                             test   eax,eax
0x4bbd8c: 7408                             je     0x4bbd96
0x4bbd8e: 50                               push   eax
0x4bbd8f: e8acc70800                       call   0x548540
0x4bbd94: eb02                             jmp    0x4bbd98
0x4bbd96: 33c0                             xor    eax,eax
0x4bbd98: 895c2428                         mov    DWORD PTR [esp+0x28],ebx
0x4bbd9c: 8b10                             mov    edx,DWORD PTR [eax]
0x4bbd9e: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4bbda3: 8bc8                             mov    ecx,eax
0x4bbda5: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4bbda8: ffd0                             call   eax
0x4bbdaa: f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x4bbdb1: 7524                             jne    0x4bbdd7

## W-4BC874 VA 0x4bc831..0x4bc889 raw 0xbbc31 len 88 SHA256 7fb380c0a9259f3780489a4e93b17d7bac22cfa05f111a8e3b092dd125074f4d
0x4bc831: 8b5028                           mov    edx,DWORD PTR [eax+0x28]
0x4bc834: ffd2                             call   edx
0x4bc836: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4bc83c: 85c9                             test   ecx,ecx
0x4bc83e: 7407                             je     0x4bc847
0x4bc840: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bc842: 8b10                             mov    edx,DWORD PTR [eax]
0x4bc844: 57                               push   edi
0x4bc845: ffd2                             call   edx
0x4bc847: 68c0000000                       push   0xc0
0x4bc84c: e8174a3d00                       call   0x891268
0x4bc851: 83c404                           add    esp,0x4
0x4bc854: 89442410                         mov    DWORD PTR [esp+0x10],eax
0x4bc858: c744242004000000                 mov    DWORD PTR [esp+0x20],0x4
0x4bc860: 85c0                             test   eax,eax
0x4bc862: 7408                             je     0x4bc86c
0x4bc864: 50                               push   eax
0x4bc865: e8d6bc0800                       call   0x548540
0x4bc86a: eb02                             jmp    0x4bc86e
0x4bc86c: 33c0                             xor    eax,eax
0x4bc86e: 895c2420                         mov    DWORD PTR [esp+0x20],ebx
0x4bc872: 8b10                             mov    edx,DWORD PTR [eax]
0x4bc874: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4bc879: 8bc8                             mov    ecx,eax
0x4bc87b: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4bc87e: ffd0                             call   eax
0x4bc880: f605a472fb0001                   test   BYTE PTR ds:0xfb72a4,0x1
0x4bc887: 7524                             jne    0x4bc8ad

## W-4BCE3F VA 0x4bcdf4..0x4bce5d raw 0xbc1f4 len 105 SHA256 d8ca61bb1d6cd1eef05f808abc0ad3ec5d7cc256c1108f3e3e82865d29916bbd
0x4bcdf4: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bcdf6: 8b10                             mov    edx,DWORD PTR [eax]
0x4bcdf8: 53                               push   ebx
0x4bcdf9: ffd2                             call   edx
0x4bcdfb: 68b4000000                       push   0xb4
0x4bce00: e863443d00                       call   0x891268
0x4bce05: 8bf0                             mov    esi,eax
0x4bce07: 83c404                           add    esp,0x4
0x4bce0a: 89742410                         mov    DWORD PTR [esp+0x10],esi
0x4bce0e: c744242006000000                 mov    DWORD PTR [esp+0x20],0x6
0x4bce16: 85f6                             test   esi,esi
0x4bce18: 7416                             je     0x4bce30
0x4bce1a: 56                               push   esi
0x4bce1b: e8207e0800                       call   0x544c40
0x4bce20: c7066cfac000                     mov    DWORD PTR [esi],0xc0fa6c
0x4bce26: 891daca7fb00                     mov    DWORD PTR ds:0xfba7ac,ebx
0x4bce2c: 8bce                             mov    ecx,esi
0x4bce2e: eb02                             jmp    0x4bce32
0x4bce30: 33c9                             xor    ecx,ecx
0x4bce32: c7442420ffffffff                 mov    DWORD PTR [esp+0x20],0xffffffff
0x4bce3a: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bce3c: 8b5024                           mov    edx,DWORD PTR [eax+0x24]
0x4bce3f: 890da4a7fb00                     mov    DWORD PTR ds:0xfba7a4,ecx
0x4bce45: ffd2                             call   edx
0x4bce47: 841dd4adfa00                     test   BYTE PTR ds:0xfaadd4,bl
0x4bce4d: 7528                             jne    0x4bce77
0x4bce4f: 091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
0x4bce55: c74424200d000000                 mov    DWORD PTR [esp+0x20],0xd

## W-4BDDCC VA 0x4bdd89..0x4bdde3 raw 0xbd189 len 90 SHA256 cced74eab060cf406a79c92112516808400021cd4c9b9aa1c112c79f70df8bc5
0x4bdd89: ffd2                             call   edx
0x4bdd8b: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4bdd91: 3bce                             cmp    ecx,esi
0x4bdd93: 7407                             je     0x4bdd9c
0x4bdd95: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bdd97: 8b10                             mov    edx,DWORD PTR [eax]
0x4bdd99: 53                               push   ebx
0x4bdd9a: ffd2                             call   edx
0x4bdd9c: 68c0000000                       push   0xc0
0x4bdda1: e8c2343d00                       call   0x891268
0x4bdda6: 83c404                           add    esp,0x4
0x4bdda9: 89442410                         mov    DWORD PTR [esp+0x10],eax
0x4bddad: c744242004000000                 mov    DWORD PTR [esp+0x20],0x4
0x4bddb5: 3bc6                             cmp    eax,esi
0x4bddb7: 7408                             je     0x4bddc1
0x4bddb9: 50                               push   eax
0x4bddba: e881a70800                       call   0x548540
0x4bddbf: eb02                             jmp    0x4bddc3
0x4bddc1: 33c0                             xor    eax,eax
0x4bddc3: 83cfff                           or     edi,0xffffffff
0x4bddc6: 897c2420                         mov    DWORD PTR [esp+0x20],edi
0x4bddca: 8b10                             mov    edx,DWORD PTR [eax]
0x4bddcc: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4bddd1: 8bc8                             mov    ecx,eax
0x4bddd3: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4bddd6: ffd0                             call   eax
0x4bddd8: be0a000000                       mov    esi,0xa
0x4bdddd: 841da472fb00                     test   BYTE PTR ds:0xfb72a4,bl

## W-4BE719 VA 0x4be6d2..0x4be738 raw 0xbdad2 len 102 SHA256 977309251858951d45d28b4565826f386aaa164d2ee8668a2ceaa43cb98944d2
0x4be6d2: 8b01                             mov    eax,DWORD PTR [ecx]
0x4be6d4: 8b10                             mov    edx,DWORD PTR [eax]
0x4be6d6: 57                               push   edi
0x4be6d7: ffd2                             call   edx
0x4be6d9: 68b4000000                       push   0xb4
0x4be6de: e8852b3d00                       call   0x891268
0x4be6e3: 8bf0                             mov    esi,eax
0x4be6e5: 83c404                           add    esp,0x4
0x4be6e8: 89742410                         mov    DWORD PTR [esp+0x10],esi
0x4be6ec: c744242006000000                 mov    DWORD PTR [esp+0x20],0x6
0x4be6f4: 85f6                             test   esi,esi
0x4be6f6: 7416                             je     0x4be70e
0x4be6f8: 56                               push   esi
0x4be6f9: e842650800                       call   0x544c40
0x4be6fe: c7066cfac000                     mov    DWORD PTR [esi],0xc0fa6c
0x4be704: 893daca7fb00                     mov    DWORD PTR ds:0xfba7ac,edi
0x4be70a: 8bce                             mov    ecx,esi
0x4be70c: eb02                             jmp    0x4be710
0x4be70e: 33c9                             xor    ecx,ecx
0x4be710: 895c2420                         mov    DWORD PTR [esp+0x20],ebx
0x4be714: 8b01                             mov    eax,DWORD PTR [ecx]
0x4be716: 8b5024                           mov    edx,DWORD PTR [eax+0x24]
0x4be719: 890da4a7fb00                     mov    DWORD PTR ds:0xfba7a4,ecx
0x4be71f: ffd2                             call   edx
0x4be721: f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x4be728: 7524                             jne    0x4be74e
0x4be72a: 093dd4adfa00                     or     DWORD PTR ds:0xfaadd4,edi
0x4be730: c74424200d000000                 mov    DWORD PTR [esp+0x20],0xd

## W-4BF4D7 VA 0x4bf493..0x4bf4e7 raw 0xbe893 len 84 SHA256 639ac9cd469c5fdb685c965c279bb577c2d31485115d11f679bbb37e222232f1
0x4bf493: 8b5028                           mov    edx,DWORD PTR [eax+0x28]
0x4bf496: ffd2                             call   edx
0x4bf498: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4bf49e: 85c9                             test   ecx,ecx
0x4bf4a0: 7408                             je     0x4bf4aa
0x4bf4a2: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bf4a4: 8b10                             mov    edx,DWORD PTR [eax]
0x4bf4a6: 6a01                             push   0x1
0x4bf4a8: ffd2                             call   edx
0x4bf4aa: 68c0000000                       push   0xc0
0x4bf4af: e8b41d3d00                       call   0x891268
0x4bf4b4: 83c404                           add    esp,0x4
0x4bf4b7: 89442410                         mov    DWORD PTR [esp+0x10],eax
0x4bf4bb: c744246003000000                 mov    DWORD PTR [esp+0x60],0x3
0x4bf4c3: 85c0                             test   eax,eax
0x4bf4c5: 7408                             je     0x4bf4cf
0x4bf4c7: 50                               push   eax
0x4bf4c8: e873900800                       call   0x548540
0x4bf4cd: eb02                             jmp    0x4bf4d1
0x4bf4cf: 33c0                             xor    eax,eax
0x4bf4d1: 895c2460                         mov    DWORD PTR [esp+0x60],ebx
0x4bf4d5: 8b10                             mov    edx,DWORD PTR [eax]
0x4bf4d7: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4bf4dc: 8bc8                             mov    ecx,eax
0x4bf4de: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4bf4e1: ffd0                             call   eax
0x4bf4e3: 85f6                             test   esi,esi
0x4bf4e5: 740e                             je     0x4bf4f5

## W-4BF8D5 VA 0x4bf883..0x4bf8e9 raw 0xbec83 len 102 SHA256 b5edf3ee25db231a4107119b1e56afd214ab81cfca5c4238229b9f095a52e9d8
0x4bf883: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bf885: 8b10                             mov    edx,DWORD PTR [eax]
0x4bf887: 6a01                             push   0x1
0x4bf889: ffd2                             call   edx
0x4bf88b: 68b4000000                       push   0xb4
0x4bf890: e8d3193d00                       call   0x891268
0x4bf895: 8bf0                             mov    esi,eax
0x4bf897: 83c404                           add    esp,0x4
0x4bf89a: 89742414                         mov    DWORD PTR [esp+0x14],esi
0x4bf89e: c784248800000002000000           mov    DWORD PTR [esp+0x88],0x2
0x4bf8a9: 85f6                             test   esi,esi
0x4bf8ab: 741a                             je     0x4bf8c7
0x4bf8ad: 56                               push   esi
0x4bf8ae: e88d530800                       call   0x544c40
0x4bf8b3: c7066cfac000                     mov    DWORD PTR [esi],0xc0fa6c
0x4bf8b9: c705aca7fb0001000000             mov    DWORD PTR ds:0xfba7ac,0x1
0x4bf8c3: 8bce                             mov    ecx,esi
0x4bf8c5: eb02                             jmp    0x4bf8c9
0x4bf8c7: 33c9                             xor    ecx,ecx
0x4bf8c9: 89bc2488000000                   mov    DWORD PTR [esp+0x88],edi
0x4bf8d0: 8b01                             mov    eax,DWORD PTR [ecx]
0x4bf8d2: 8b5024                           mov    edx,DWORD PTR [eax+0x24]
0x4bf8d5: 890da4a7fb00                     mov    DWORD PTR ds:0xfba7a4,ecx
0x4bf8db: ffd2                             call   edx
0x4bf8dd: 33f6                             xor    esi,esi
0x4bf8df: 3bde                             cmp    ebx,esi
0x4bf8e1: 740e                             je     0x4bf8f1
0x4bf8e3: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4

## W-4C18F9 VA 0x4c18b1..0x4c190e raw 0xc0cb1 len 93 SHA256 c7e5179382a3d94e95e54858ffe49066d3aac898955a8ba6f22498c7d99e78bb
0x4c18b1: 8b4228                           mov    eax,DWORD PTR [edx+0x28]
0x4c18b4: ffd0                             call   eax
0x4c18b6: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4c18bc: 3bcf                             cmp    ecx,edi
0x4c18be: 7407                             je     0x4c18c7
0x4c18c0: 8b11                             mov    edx,DWORD PTR [ecx]
0x4c18c2: 8b02                             mov    eax,DWORD PTR [edx]
0x4c18c4: 53                               push   ebx
0x4c18c5: ffd0                             call   eax
0x4c18c7: 68b4000000                       push   0xb4
0x4c18cc: e897f93c00                       call   0x891268
0x4c18d1: 83c404                           add    esp,0x4
0x4c18d4: 89442410                         mov    DWORD PTR [esp+0x10],eax
0x4c18d8: c74424200a000000                 mov    DWORD PTR [esp+0x20],0xa
0x4c18e0: 3bc7                             cmp    eax,edi
0x4c18e2: 7409                             je     0x4c18ed
0x4c18e4: 8bf0                             mov    esi,eax
0x4c18e6: e8f5580800                       call   0x5471e0
0x4c18eb: eb02                             jmp    0x4c18ef
0x4c18ed: 33c0                             xor    eax,eax
0x4c18ef: c7442420ffffffff                 mov    DWORD PTR [esp+0x20],0xffffffff
0x4c18f7: 8b10                             mov    edx,DWORD PTR [eax]
0x4c18f9: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4c18fe: 8bc8                             mov    ecx,eax
0x4c1900: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4c1903: ffd0                             call   eax
0x4c1905: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4c190b: 895904                           mov    DWORD PTR [ecx+0x4],ebx

## W-4C3456 VA 0x4c3410..0x4c346f raw 0xc2810 len 95 SHA256 53a6404f56cc122bc4409fd7144df57f23455721d3ab244fb65eeb02c3a91244
0x4c3410: ffd2                             call   edx
0x4c3412: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4c3418: 3bcf                             cmp    ecx,edi
0x4c341a: 7407                             je     0x4c3423
0x4c341c: 8b01                             mov    eax,DWORD PTR [ecx]
0x4c341e: 8b10                             mov    edx,DWORD PTR [eax]
0x4c3420: 56                               push   esi
0x4c3421: ffd2                             call   edx
0x4c3423: 68b4000000                       push   0xb4
0x4c3428: e83bde3c00                       call   0x891268
0x4c342d: 83c404                           add    esp,0x4
0x4c3430: 89442410                         mov    DWORD PTR [esp+0x10],eax
0x4c3434: c744242005000000                 mov    DWORD PTR [esp+0x20],0x5
0x4c343c: 3bc7                             cmp    eax,edi
0x4c343e: 740e                             je     0x4c344e
0x4c3440: 8bf0                             mov    esi,eax
0x4c3442: e8993d0800                       call   0x5471e0
0x4c3447: be01000000                       mov    esi,0x1
0x4c344c: eb02                             jmp    0x4c3450
0x4c344e: 33c0                             xor    eax,eax
0x4c3450: 895c2420                         mov    DWORD PTR [esp+0x20],ebx
0x4c3454: 8b10                             mov    edx,DWORD PTR [eax]
0x4c3456: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4c345b: 8bc8                             mov    ecx,eax
0x4c345d: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4c3460: ffd0                             call   eax
0x4c3462: f605c01afe0001                   test   BYTE PTR ds:0xfe1ac0,0x1
0x4c3469: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4

## W-4C4812 VA 0x4c47ca..0x4c4827 raw 0xc3bca len 93 SHA256 7abfeac55717e3443144b29c99ec58bda0c5d4157e5ee9009322ab769f43b123
0x4c47ca: 8b5028                           mov    edx,DWORD PTR [eax+0x28]
0x4c47cd: ffd2                             call   edx
0x4c47cf: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4c47d5: 85c9                             test   ecx,ecx
0x4c47d7: 7408                             je     0x4c47e1
0x4c47d9: 8b01                             mov    eax,DWORD PTR [ecx]
0x4c47db: 8b10                             mov    edx,DWORD PTR [eax]
0x4c47dd: 6a01                             push   0x1
0x4c47df: ffd2                             call   edx
0x4c47e1: 68c8000000                       push   0xc8
0x4c47e6: e87dca3c00                       call   0x891268
0x4c47eb: 83c404                           add    esp,0x4
0x4c47ee: 89442408                         mov    DWORD PTR [esp+0x8],eax
0x4c47f2: c744241803000000                 mov    DWORD PTR [esp+0x18],0x3
0x4c47fa: 85c0                             test   eax,eax
0x4c47fc: 7408                             je     0x4c4806
0x4c47fe: 50                               push   eax
0x4c47ff: e88c2b0800                       call   0x547390
0x4c4804: eb02                             jmp    0x4c4808
0x4c4806: 33c0                             xor    eax,eax
0x4c4808: c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x4c4810: 8b10                             mov    edx,DWORD PTR [eax]
0x4c4812: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4c4817: 8bc8                             mov    ecx,eax
0x4c4819: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4c481c: ffd0                             call   eax
0x4c481e: f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x4c4825: 7529                             jne    0x4c4850

## W-4C4D01 VA 0x4c4cbd..0x4c4d16 raw 0xc40bd len 89 SHA256 fc6f81c43be18b86a6321f846d31f08a803bfd7c8e86685d1b9b9459ec96b963
0x4c4cbd: 8b5028                           mov    edx,DWORD PTR [eax+0x28]
0x4c4cc0: ffd2                             call   edx
0x4c4cc2: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4c4cc8: 3bce                             cmp    ecx,esi
0x4c4cca: 7407                             je     0x4c4cd3
0x4c4ccc: 8b01                             mov    eax,DWORD PTR [ecx]
0x4c4cce: 8b10                             mov    edx,DWORD PTR [eax]
0x4c4cd0: 57                               push   edi
0x4c4cd1: ffd2                             call   edx
0x4c4cd3: 6838010000                       push   0x138
0x4c4cd8: e88bc53c00                       call   0x891268
0x4c4cdd: 83c404                           add    esp,0x4
0x4c4ce0: 89442410                         mov    DWORD PTR [esp+0x10],eax
0x4c4ce4: c744242008000000                 mov    DWORD PTR [esp+0x20],0x8
0x4c4cec: 3bc6                             cmp    eax,esi
0x4c4cee: 7409                             je     0x4c4cf9
0x4c4cf0: 8bf0                             mov    esi,eax
0x4c4cf2: e8993e0800                       call   0x548b90
0x4c4cf7: eb02                             jmp    0x4c4cfb
0x4c4cf9: 33c0                             xor    eax,eax
0x4c4cfb: 895c2420                         mov    DWORD PTR [esp+0x20],ebx
0x4c4cff: 8b10                             mov    edx,DWORD PTR [eax]
0x4c4d01: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4c4d06: 8bc8                             mov    ecx,eax
0x4c4d08: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4c4d0b: ffd0                             call   eax
0x4c4d0d: f605800ffc0001                   test   BYTE PTR ds:0xfc0f80,0x1
0x4c4d14: 7524                             jne    0x4c4d3a

## W-4C5BCF VA 0x4c5b83..0x4c5bef raw 0xc4f83 len 108 SHA256 1c32e82b5082c556dbcf4022e45e6badf24fe3807862350d4f4551e3797ef226
0x4c5b83: 8b01                             mov    eax,DWORD PTR [ecx]
0x4c5b85: 8b10                             mov    edx,DWORD PTR [eax]
0x4c5b87: 6a01                             push   0x1
0x4c5b89: ffd2                             call   edx
0x4c5b8b: 68b4000000                       push   0xb4
0x4c5b90: e8d3b63c00                       call   0x891268
0x4c5b95: 8bf0                             mov    esi,eax
0x4c5b97: 83c404                           add    esp,0x4
0x4c5b9a: 89742410                         mov    DWORD PTR [esp+0x10],esi
0x4c5b9e: c744242005000000                 mov    DWORD PTR [esp+0x20],0x5
0x4c5ba6: 85f6                             test   esi,esi
0x4c5ba8: 741a                             je     0x4c5bc4
0x4c5baa: 56                               push   esi
0x4c5bab: e890f00700                       call   0x544c40
0x4c5bb0: c7066cfac000                     mov    DWORD PTR [esi],0xc0fa6c
0x4c5bb6: c705aca7fb0001000000             mov    DWORD PTR ds:0xfba7ac,0x1
0x4c5bc0: 8bce                             mov    ecx,esi
0x4c5bc2: eb02                             jmp    0x4c5bc6
0x4c5bc4: 33c9                             xor    ecx,ecx
0x4c5bc6: 895c2420                         mov    DWORD PTR [esp+0x20],ebx
0x4c5bca: 8b01                             mov    eax,DWORD PTR [ecx]
0x4c5bcc: 8b5024                           mov    edx,DWORD PTR [eax+0x24]
0x4c5bcf: 890da4a7fb00                     mov    DWORD PTR ds:0xfba7a4,ecx
0x4c5bd5: ffd2                             call   edx
0x4c5bd7: f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x4c5bde: 7525                             jne    0x4c5c05
0x4c5be0: 830dd4adfa0001                   or     DWORD PTR ds:0xfaadd4,0x1
0x4c5be7: c74424200c000000                 mov    DWORD PTR [esp+0x20],0xc

## W-4DEF0F VA 0x4deed0..0x4def23 raw 0xde2d0 len 83 SHA256 f1c678c166365da16c6edf5aabe0cc29cd288de790f61045a3bb8cb61a62a9a0
0x4deed0: 8b4228                           mov    eax,DWORD PTR [edx+0x28]
0x4deed3: ffd0                             call   eax
0x4deed5: 8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4deedb: 3bce                             cmp    ecx,esi
0x4deedd: 7407                             je     0x4deee6
0x4deedf: 8b11                             mov    edx,DWORD PTR [ecx]
0x4deee1: 8b02                             mov    eax,DWORD PTR [edx]
0x4deee3: 53                               push   ebx
0x4deee4: ffd0                             call   eax
0x4deee6: 68b4000000                       push   0xb4
0x4deeeb: e878233b00                       call   0x891268
0x4deef0: 83c404                           add    esp,0x4
0x4deef3: 8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4deef6: c645fc09                         mov    BYTE PTR [ebp-0x4],0x9
0x4deefa: 3bc6                             cmp    eax,esi
0x4deefc: 7409                             je     0x4def07
0x4deefe: 8bf0                             mov    esi,eax
0x4def00: e8db820600                       call   0x5471e0
0x4def05: eb02                             jmp    0x4def09
0x4def07: 33c0                             xor    eax,eax
0x4def09: c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x4def0d: 8b10                             mov    edx,DWORD PTR [eax]
0x4def0f: a3a4a7fb00                       mov    ds:0xfba7a4,eax
0x4def14: 8bc8                             mov    ecx,eax
0x4def16: 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4def19: ffd0                             call   eax
0x4def1b: b830b1fa00                       mov    eax,0xfab130
0x4def20: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]

## W-735009 VA 0x734faf..0x735038 raw 0x3343af len 137 SHA256 5163b408f0bef998155daa886ef6c08f7eca724ae96ca4acee4ff211127e766a
0x734faf: a1987bfb00                       mov    eax,ds:0xfb7b98
0x734fb4: 894008                           mov    DWORD PTR [eax+0x8],eax
0x734fb7: 8b15987bfb00                     mov    edx,DWORD PTR ds:0xfb7b98
0x734fbd: 885a10                           mov    BYTE PTR [edx+0x10],bl
0x734fc0: a1987bfb00                       mov    eax,ds:0xfb7b98
0x734fc5: 885811                           mov    BYTE PTR [eax+0x11],bl
0x734fc8: 885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x734fcb: 6818090000                       push   0x918
0x734fd0: 893dac7bfb00                     mov    DWORD PTR ds:0xfb7bac,edi
0x734fd6: 891db07bfb00                     mov    DWORD PTR ds:0xfb7bb0,ebx
0x734fdc: 891dc47bfb00                     mov    DWORD PTR ds:0xfb7bc4,ebx
0x734fe2: 893db47bfb00                     mov    DWORD PTR ds:0xfb7bb4,edi
0x734fe8: e87bc21500                       call   0x891268
0x734fed: 83c404                           add    esp,0x4
0x734ff0: 3bc7                             cmp    eax,edi
0x734ff2: 7409                             je     0x734ffd
0x734ff4: 8bf0                             mov    esi,eax
0x734ff6: e8b5f9ffff                       call   0x7349b0
0x734ffb: eb02                             jmp    0x734fff
0x734ffd: 33c0                             xor    eax,eax
0x734fff: a3a87bfb00                       mov    ds:0xfb7ba8,eax
0x735004: e8477f0000                       call   0x73cf50
0x735009: a3787bfb00                       mov    ds:0xfb7b78,eax
0x73500e: a1a87bfb00                       mov    eax,ds:0xfb7ba8
0x735013: c705b87bfb0003000000             mov    DWORD PTR ds:0xfb7bb8,0x3
0x73501d: c705bc7bfb003c000000             mov    DWORD PTR ds:0xfb7bbc,0x3c
0x735027: c705c07bfb00100e0000             mov    DWORD PTR ds:0xfb7bc0,0xe10
0x735031: c7401000080000                   mov    DWORD PTR [eax+0x10],0x800

## W-7351E5 VA 0x73519a..0x7351fa raw 0x33459a len 96 SHA256 10709a985f0027b90ef00383cf09a93f5ba862f559f2bd19d9f1ce52ee118300
0x73519a: 64a100000000                     mov    eax,fs:0x0
0x7351a0: 50                               push   eax
0x7351a1: 83ec0c                           sub    esp,0xc
0x7351a4: 56                               push   esi
0x7351a5: a1201fd600                       mov    eax,ds:0xd61f20
0x7351aa: 33c5                             xor    eax,ebp
0x7351ac: 50                               push   eax
0x7351ad: 8d45f4                           lea    eax,[ebp-0xc]
0x7351b0: 64a300000000                     mov    fs:0x0,eax
0x7351b6: c745f0707bfb00                   mov    DWORD PTR [ebp-0x10],0xfb7b70
0x7351bd: 68947bfb00                       push   0xfb7b94
0x7351c2: c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0x7351c9: e8b2120000                       call   0x736480
0x7351ce: 8b0d787bfb00                     mov    ecx,DWORD PTR ds:0xfb7b78
0x7351d4: 33f6                             xor    esi,esi
0x7351d6: 83c404                           add    esp,0x4
0x7351d9: 3bce                             cmp    ecx,esi
0x7351db: 740e                             je     0x7351eb
0x7351dd: 8b01                             mov    eax,DWORD PTR [ecx]
0x7351df: 8b10                             mov    edx,DWORD PTR [eax]
0x7351e1: 6a01                             push   0x1
0x7351e3: ffd2                             call   edx
0x7351e5: 8935787bfb00                     mov    DWORD PTR ds:0xfb7b78,esi
0x7351eb: a1a87bfb00                       mov    eax,ds:0xfb7ba8
0x7351f0: 3bc6                             cmp    eax,esi
0x7351f2: 740f                             je     0x735203
0x7351f4: 50                               push   eax
0x7351f5: e812c01500                       call   0x89120c

## W-48E4B8 VA 0x48e48a..0x48e4bd raw 0x8d88a len 51 SHA256 3cb879f1b25a6da96b1b323650b0ea1423cc9fb4d91ba9e2405ea7d617f0a1b4
0x48e48a: f6059816fc0001                   test   BYTE PTR ds:0xfc1698,0x1
0x48e491: 8b442420                         mov    eax,DWORD PTR [esp+0x20]
0x48e495: 8b7008                           mov    esi,DWORD PTR [eax+0x8]
0x48e498: 7518                             jne    0x48e4b2
0x48e49a: 093d9816fc00                     or     DWORD PTR ds:0xfc1698,edi
0x48e4a0: e8fbe33700                       call   0x80c8a0
0x48e4a5: 6820e3bc00                       push   0xbce320
0x48e4aa: e86b3e4000                       call   0x89231a
0x48e4af: 83c404                           add    esp,0x4
0x48e4b2: 56                               push   esi
0x48e4b3: 68a016fc00                       push   0xfc16a0
0x48e4b8: e893e43700                       call   0x80c950

## W-6D9067 VA 0x6d9059..0x6d908d raw 0x2d8459 len 52 SHA256 7776c01dedea5588d91b3e751a99a1d4204d240fefdbf7f28fecb60a2eb0f741
0x6d9059: 6a0c                             push   0xc
0x6d905b: e808821b00                       call   0x891268
0x6d9060: 83c404                           add    esp,0x4
0x6d9063: 3bc3                             cmp    eax,ebx
0x6d9065: 741b                             je     0x6d9082
0x6d9067: c700ec0fc400                     mov    DWORD PTR [eax],0xc40fec
0x6d906d: c74004c80ffc00                   mov    DWORD PTR [eax+0x4],0xfc0fc8
0x6d9074: c7400870986d00                   mov    DWORD PTR [eax+0x8],0x6d9870
0x6d907b: e8a0fcffff                       call   0x6d8d20
0x6d9080: eb0b                             jmp    0x6d908d
0x6d9082: 33c0                             xor    eax,eax
0x6d9084: e897fcffff                       call   0x6d8d20
0x6d9089: eb02                             jmp    0x6d908d
0x6d908b: 33c0                             xor    eax,eax

## VT-C51748 VA 0xc51748..0xc51768 raw 0x84fd48 len 32 SHA256 f3d64021ce790d865813ee57e7974ed6ef29f5bc69abe170ab0ffed4431fd37d
70668000f06c800050688000b0688000a0698000006a8000d06a8000606f8000

## VT-C45F94 VA 0xc45f94..0xc45fc4 raw 0x844594 len 48 SHA256 a258df7a756cecf3b067922c3ec6efd684482e994b7bf36d233dee28ae12cc05
f0c37300105d5f00105d5f00c0c37300d0c37300105d5f00105d5f00105d5f00105d5f00105d5f0050bb730090bc7300

## VT-C45FEC VA 0xc45fec..0xc4601c raw 0x8445ec len 48 SHA256 46cdc077ecb2ee7de7452b9e8cb31d571e3026bf8bde192af270180306c2a9e7
90cd7300105d5f00105d5f00105d5f00105d5f00105d5f00105d5f00105d5f00105d5f0060cd7300b0c5730090c77300

## VT-C0F944 VA 0xc0f944..0xc0f974 raw 0x80df44 len 48 SHA256 4b6e82f4c432d9965afe88b8679bbeb862d89317e61271d4bf53f398302225bf
504e540040505400d0515400105d5f00105d5f0010525400b03d400090525400b0525400f0c28d00f0c28d00c0525400

## VT-C0F99C VA 0xc0f99c..0xc0f9cc raw 0x80df9c len 48 SHA256 3a7d9b06fc32e1a723e076457e056ee3e0e289cfbf1df30e6a48c0419dca78ca
0072540040505400d0515400105d5f00105d5f0010525400b03d400090525400b0525400f0c28d00f0c28d00f0c28d00

## VT-C0FA6C VA 0xc0fa6c..0xc0fa9c raw 0x80e06c len 48 SHA256 a8b121257c16b5d5640ae79e1a5e3d0b336102ae9d2ad838184d250fc163001e
504e540040505400d0515400105d5f00105d5f0010525400b03d400090525400b0525400f0c28d00f0c28d0050835400

## VT-C0FA14 VA 0xc0fa14..0xc0fa44 raw 0x80e014 len 48 SHA256 6a26b31cdf629b4fcb907fd7096a2179a3e1b3ad2a7b4b4d8370824409b7eca1
d0755400d0765400d051540010785400f078540050775400607a540090525400b0525400407c5400807c5400907f5400

## VT-C0FAC4 VA 0xc0fac4..0xc0faf4 raw 0x80e0c4 len 48 SHA256 fa3b2d7ec6ef4da91d67e6a6398b5dcd681e393a53fcfb78922e97ec2e4d1d5b
0086540040505400d0515400105d5f00105d5f00105254003087540090525400b0525400b0434400e0865400908a5400

## VT-C0FB1C VA 0xc0fb1c..0xc0fb4c raw 0x80e11c len 48 SHA256 203f2fbcb079b5f704fe62f33b27fa088263ddb3b9e0059ce4ef99f75374f380
808c540040505400d0515400105d5f00105d5f0010525400b03d400090525400b0525400f0c28d00f0c28d00b08c5400

## VT-BFB5A4 VA 0xbfb5a4..0xbfb5d4 raw 0x7f9ba4 len 48 SHA256 3baca3b95b69b4416c52261fbd8e630a25a567eed5339feca267ad658cdeecb5
d042440040505400d0515400105d5f00105d5f0010494400f047440090525400b0525400b0434400e086540070464400

## VT-C40FEC VA 0xc40fec..0xc40ff8 raw 0x83f5ec len 12 SHA256 dc0ae2458b34a93e84c79c30c1cf9eaffe709e30859fe3fc4aaca5c31e1f4765
e0ac4f0010ab6d00d0ac4f00

## VT-C51BF4 VA 0xc51bf4..0xc51c44 raw 0x8501f4 len 80 SHA256 4506896f3a5d4976d1a89c53cbe6e1766c14e291d66a7788320c1636b46a4ec4
10e7800050e78000a0e78000f0c28d00d0e7800040e9800020ea800090ea8000f0ea800010eb8000f0c28d0030eb800000ed800050ec800070ec8000a0ec8000d0ec800020ed800090eb8000c0eb8000

## VT-C51EEC VA 0xc51eec..0xc51ef8 raw 0x8504ec len 12 SHA256 db4d957df3ac4dcdde165e45737a1c7286c404c7e29288a87ff337ae1869da69
a0fd8000d0fd8000d0fe8000

## VT-C51F40 VA 0xc51f40..0xc51f4c raw 0x850540 len 12 SHA256 b1dc2d38169e21abd081afe9e3afe8337286f5586c6027ccaa0deeff595c24c5
a0098100d00a8100100b8100

## B-MATHERR-ENTRY VA 0x8a647f..0x8a64ad raw 0x4a587f len 46 SHA256 5df4399a51959275d46e85a09ac8d9113154264183eaa90bc6dc10b46dce40d4
0x8a647f: 8bff                             mov    edi,edi
0x8a6481: 55                               push   ebp
0x8a6482: 8bec                             mov    ebp,esp
0x8a6484: 83ec28                           sub    esp,0x28
0x8a6487: 33c0                             xor    eax,eax
0x8a6489: 8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x8a648c: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x8a648f: 390514d5f800                     cmp    DWORD PTR ds:0xf8d514,eax
0x8a6495: 740e                             je     0x8a64a5
0x8a6497: ff359072fe00                     push   DWORD PTR ds:0xfe7290
0x8a649d: ff155822bd00                     call   DWORD PTR ds:0xbd2258
0x8a64a3: eb05                             jmp    0x8a64aa
0x8a64a5: b84f278b00                       mov    eax,0x8b274f
0x8a64aa: 8b4d14                           mov    ecx,DWORD PTR [ebp+0x14]

## B-MATHERR-CALL VA 0x8a6515..0x8a653c raw 0x4a5915 len 39 SHA256 35ca3664ab4e42d2d3f59ff4a5aea6dcfdd858d0301b464d47322090ea2c17f2
0x8a6515: 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x8a6518: dd01                             fld    QWORD PTR [ecx]
0x8a651a: 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x8a651d: 8b7510                           mov    esi,DWORD PTR [ebp+0x10]
0x8a6520: dd5de0                           fstp   QWORD PTR [ebp-0x20]
0x8a6523: dd01                             fld    QWORD PTR [ecx]
0x8a6525: 8d4dd8                           lea    ecx,[ebp-0x28]
0x8a6528: dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x8a652b: 51                               push   ecx
0x8a652c: dd06                             fld    QWORD PTR [esi]
0x8a652e: dd5df0                           fstp   QWORD PTR [ebp-0x10]
0x8a6531: ffd0                             call   eax
0x8a6533: 59                               pop    ecx
0x8a6534: 85c0                             test   eax,eax
0x8a6536: 0f85d2010000                     jne    0x8a670e

## IAT-BD2210 VA 0xbd2210..0xbd2214 raw 0x7d0810 len 4 SHA256 7f7d9a0cbd1567ed6006af6960ab31098289990fd7177d8bc203f5af9fee67a9
18f99500

## IMPORT-BD2210 VA 0xd5f91a..0xd5f923 raw 0x95df1a len 9 SHA256 6ee1ab76583916054186ec00b81f75c025cad38ad4c059a58c2384f67223e2fb
486561704672656500

## IAT-BD2214 VA 0xbd2214..0xbd2218 raw 0x7d0814 len 4 SHA256 3543056c517b94ba42c05fceb5e4d7982b8253bbe05e3d957b7d1c0b4926976e
0cf99500

## IMPORT-BD2214 VA 0xd5f90e..0xd5f918 raw 0x95df0e len 10 SHA256 923305cd45e5ce52995c8ee25810c11e49025cac70a1a8e4c481040d6bd4d9b5
48656170416c6c6f6300

## IAT-BD222C VA 0xbd222c..0xbd2230 raw 0x7d082c len 4 SHA256 2c34b3a3864b04b9f633320d47e980bb3cb0afb8adbe4eb24fb07bdbe252b474
bce49500

## IMPORT-BD222C VA 0xd5e4be..0xd5e4e4 raw 0x95cabe len 38 SHA256 c142f764ccea0b35a43e19573417a221997af846a3fd93f7ddd0262a34f0ef6f
496e697469616c697a65437269746963616c53656374696f6e416e645370696e436f756e7400

## IAT-BD2248 VA 0xbd2248..0xbd224c raw 0x7d0848 len 4 SHA256 b3e4edd761489978baa556feb20e0cc4150d5c83ebcd710b0c644d16ecb5b9ac
4ae49500

## IMPORT-BD2248 VA 0xd5e44c..0xd5e461 raw 0x95ca4c len 21 SHA256 ec8ca490fa1cf71ca1c49108506a997aa98c4d7868b4a72263b87198eaf84f5f
4c65617665437269746963616c53656374696f6e00

## IAT-BD224C VA 0xbd224c..0xbd2250 raw 0x7d084c len 4 SHA256 7a12408b607fef4abfd8648402dac6453d510d1acd73744fe80c22406da2eaa0
32e49500

## IMPORT-BD224C VA 0xd5e434..0xd5e449 raw 0x95ca34 len 21 SHA256 a03617cea0c3ce223889bf08fed52ff4fd2a94e81a24c5bfb454e43540dd2c15
456e746572437269746963616c53656374696f6e00

## IAT-BD2258 VA 0xbd2258..0xbd225c raw 0x7d0858 len 4 SHA256 64cd889402be5750663c0bc5b17a7d2b52b8b4bc3bcae080e3bd09200f744882
def89500

## IMPORT-BD2258 VA 0xd5f8e0..0xd5f8ee raw 0x95dee0 len 14 SHA256 e787102ed31b054ca473edf00b9817374bb4c7910e4bf69282654c10a93c4048
4465636f6465506f696e74657200

## IAT-BD225C VA 0xbd225c..0xbd2260 raw 0x7d085c len 4 SHA256 e15f1f5b80fc9afa437ea24915694d16132dc1506bb12bf785a4b4ddf78cef52
cef89500

## IMPORT-BD225C VA 0xd5f8d0..0xd5f8de raw 0x95ded0 len 14 SHA256 14600312a2953818429b73ed52af4556e4b531d5cf3197292d1ba6e78f6f38da
456e636f6465506f696e74657200

## IAT-BD2304 VA 0xbd2304..0xbd2308 raw 0x7d0904 len 4 SHA256 88a588aab0c8f47ab895e24cc10bb694487dfe5eadc12346d4f7a65b70fca6b6
16e49500

## IMPORT-BD2304 VA 0xd5e418..0xd5e41e raw 0x95ca18 len 6 SHA256 2fb1b55eba90510bbdbc4df181ff5b9957177abd1b44f7aee9a45dade97f0e0e
536c65657000

## IAT-BD25A0 VA 0xbd25a0..0xbd25a4 raw 0x7d0ba0 len 4 SHA256 a97ae5afd67781c071a0dab4669c8269d43488c2ac730375a8dfea105f7b2b6d
0cf09500

## IMPORT-BD25A0 VA 0xd5f00e..0xd5f01a raw 0x95d60e len 12 SHA256 920a75756bca9e7fda02c616820e02a34ce9461c662621b9f13d02ac0d294fb9
74696d6547657454696d6500

## IAT-BD26C0 VA 0xbd26c0..0xbd26c4 raw 0x7d0cc0 len 4 SHA256 1ce39bd482d372c0da0444e14eade0881baa2dddd25373e504e414652a443e0e
cef09500

## IMPORT-BD26C0 VA 0xd5f0d0..0xd5f0d9 raw 0x95d6d0 len 9 SHA256 dd031b70c0f66e916f2dfb7d9f0a471e1470baeea20865dd68bcc5c19438c578
6f765f636c65617200

## IAT-BD23B0 VA 0xbd23b0..0xbd23b4 raw 0x7d09b0 len 4 SHA256 ba739cbea143a6a93f3c84ecee43d3c8af587d8f2cf683a5841e0845c08b761d
42f29500

## IMPORT-BD23B0 VA 0xd5f244..0xd5f251 raw 0x95d844 len 13 SHA256 df51cf0a1b8e86143a7d64a411240174307a40c834187badf49d6669b736f4a4
616c536f7572636553746f7000

## IAT-BD23B4 VA 0xbd23b4..0xbd23b8 raw 0x7d09b4 len 4 SHA256 d79ed1dc90d37e4a92d2b1149d3e6ed7cd0f486e86e24a13a6581dc5d7b88e82
52f29500

## IMPORT-BD23B4 VA 0xd5f254..0xd5f264 raw 0x95d854 len 16 SHA256 1851420e180043b61887a3b2594e1d3882d738d80be86905882fa15ed13b353d
616c44656c657465536f757263657300

## IAT-BD23B8 VA 0xbd23b8..0xbd23bc raw 0x7d09b8 len 4 SHA256 c500c5adde425537dc9c2fba85f19006ea1080c8493e0feff1f86404d9155112
64f29500

## IMPORT-BD23B8 VA 0xd5f266..0xd5f276 raw 0x95d866 len 16 SHA256 2a4a019c8b3330d26478ec3f54e48a56caad940e2c61459c5897c4138b64bee1
616c44656c6574654275666665727300

## IDESC-D5D8C4 VA 0xd5d8c4..0xd5d8d8 raw 0x95bec4 len 20 SHA256 3c8aa37de89ad6ae316bc7789fc84ac6b818b6656d5f9c884045b7bfa892c9b0
38db950000000000000000009ce59500bc207d00

## IDLL-D5D8C4 VA 0xd5e59c..0xd5e5a9 raw 0x95cb9c len 13 SHA256 f8efc1f27ef6c525f7fd20dcb8d65e8197e97410eced20db4d323dfbf230a2a4
4b45524e454c33322e646c6c00

## IDESC-D5D9DC VA 0xd5d9dc..0xd5d9f0 raw 0x95bfdc len 20 SHA256 f84aeb1795a1129e7ed3890f8de7a3fa05180cd4da0c25317fe4bfe53ab661a9
1ce0950000000000000000001af09500a0257d00

## IDLL-D5D9DC VA 0xd5f01a..0xd5f024 raw 0x95d61a len 10 SHA256 3dcc58863abf2f785ba8ac50ad54a5de24defb3a73995ad33dd23a9233f1c85e
57494e4d4d2e646c6c00

## IDESC-D5DA2C VA 0xd5da2c..0xd5da40 raw 0x95c02c len 20 SHA256 c5081e01e8c22f5bd78af9ba4ebcf7c2b45c8017eea76714bed962f0dfa4d44c
30e1950000000000000000000ef19500b4267d00

## IDLL-D5DA2C VA 0xd5f10e..0xd5f120 raw 0x95d70e len 18 SHA256 5ad9cc9eb7a456d82949f9eaf3f63b82d5465e94657855cbf468eaf06ad9c854
6c6962766f7262697366696c652e646c6c00

## IDESC-D5DA40 VA 0xd5da40..0xd5da54 raw 0x95c040 len 20 SHA256 73a8babb1f10ca4047711a7ca94eac8fae2ec406178a84d0fe18730096a51431
98dd9500000000000000000094f595001c237d00

## IDLL-D5DA40 VA 0xd5f594..0xd5f5a1 raw 0x95db94 len 13 SHA256 2d9f9a5a07081eb5bcbf3bca5b2947b42131da092cc51f337d2eb5dae6850565
4f70656e414c33322e646c6c00

