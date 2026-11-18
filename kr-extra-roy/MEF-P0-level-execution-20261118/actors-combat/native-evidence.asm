; Bounded static PE evidence; no target execution.

; B01 CBasicObject constructor; defaults group127, relation0, speed factor100/base0
; VA [0x4ca730,0x4ca7fa) SHA256 5dbbdfe1db56107601a261aa7786c1b010339967ce24bd4c4bdc5e7c5f25f391
0x4ca730: f30f1005c056c400         movss  xmm0,DWORD PTR ds:0xc456c0
0x4ca738: f30f1186b4000000         movss  DWORD PTR [esi+0xb4],xmm0
0x4ca740: 0f57c0                   xorps  xmm0,xmm0
0x4ca743: 53                       push   ebx
0x4ca744: 33db                     xor    ebx,ebx
0x4ca746: c706ac76c000             mov    DWORD PTR [esi],0xc076ac
0x4ca74c: 899e88000000             mov    DWORD PTR [esi+0x88],ebx
0x4ca752: 899e8c000000             mov    DWORD PTR [esi+0x8c],ebx
0x4ca758: c786900000007f000000     mov    DWORD PTR [esi+0x90],0x7f
0x4ca762: 899e98000000             mov    DWORD PTR [esi+0x98],ebx
0x4ca768: 899e9c000000             mov    DWORD PTR [esi+0x9c],ebx
0x4ca76e: 899eac000000             mov    DWORD PTR [esi+0xac],ebx
0x4ca774: 899eb8000000             mov    DWORD PTR [esi+0xb8],ebx
0x4ca77a: 889ebc000000             mov    BYTE PTR [esi+0xbc],bl
0x4ca780: f30f1186c0000000         movss  DWORD PTR [esi+0xc0],xmm0
0x4ca788: f30f1186c4000000         movss  DWORD PTR [esi+0xc4],xmm0
0x4ca790: 899ec8000000             mov    DWORD PTR [esi+0xc8],ebx
0x4ca796: 6880000000               push   0x80
0x4ca79b: f30f1186cc000000         movss  DWORD PTR [esi+0xcc],xmm0
0x4ca7a3: c786d000000064000000     mov    DWORD PTR [esi+0xd0],0x64
0x4ca7ad: 899ed4000000             mov    DWORD PTR [esi+0xd4],ebx
0x4ca7b3: 8d4606                   lea    eax,[esi+0x6]
0x4ca7b6: 33d2                     xor    edx,edx
0x4ca7b8: 53                       push   ebx
0x4ca7b9: f30f1186d8000000         movss  DWORD PTR [esi+0xd8],xmm0
0x4ca7c1: f30f1186dc000000         movss  DWORD PTR [esi+0xdc],xmm0
0x4ca7c9: 50                       push   eax
0x4ca7ca: 66895604                 mov    WORD PTR [esi+0x4],dx
0x4ca7ce: e88d403d00               call   0x89e860
0x4ca7d3: 33c0                     xor    eax,eax
0x4ca7d5: 8986a0000000             mov    DWORD PTR [esi+0xa0],eax
0x4ca7db: 8986a4000000             mov    DWORD PTR [esi+0xa4],eax
0x4ca7e1: 8986a8000000             mov    DWORD PTR [esi+0xa8],eax
0x4ca7e7: 899ee0000000             mov    DWORD PTR [esi+0xe0],ebx
0x4ca7ed: 83c40c                   add    esp,0xc
0x4ca7f0: 889ee4000000             mov    BYTE PTR [esi+0xe4],bl
0x4ca7f6: 8bc6                     mov    eax,esi
0x4ca7f8: 5b                       pop    ebx
0x4ca7f9: c3                       ret

; B02 CActor constructor prefix through all six absolute resource defaults and ratio0; not full FSM installation
; VA [0x4c7070,0x4c726f) SHA256 c988962a8a6c90e761841da478af586ffc94bd80301458e1e54390b6d5223a8e
0x4c7070: 55                       push   ebp
0x4c7071: 8bec                     mov    ebp,esp
0x4c7073: 6aff                     push   0xffffffff
0x4c7075: 68dcda9000               push   0x90dadc
0x4c707a: 64a100000000             mov    eax,fs:0x0
0x4c7080: 50                       push   eax
0x4c7081: 83ec24                   sub    esp,0x24
0x4c7084: 53                       push   ebx
0x4c7085: 56                       push   esi
0x4c7086: 57                       push   edi
0x4c7087: a1201fd600               mov    eax,ds:0xd61f20
0x4c708c: 33c5                     xor    eax,ebp
0x4c708e: 50                       push   eax
0x4c708f: 8d45f4                   lea    eax,[ebp-0xc]
0x4c7092: 64a300000000             mov    fs:0x0,eax
0x4c7098: 8b5d08                   mov    ebx,DWORD PTR [ebp+0x8]
0x4c709b: 8bf3                     mov    esi,ebx
0x4c709d: e88e360000               call   0x4ca730
0x4c70a2: 8d83f0000000             lea    eax,[ebx+0xf0]
0x4c70a8: c745fc00000000           mov    DWORD PTR [ebp-0x4],0x0
0x4c70af: e8dc2e0000               call   0x4c9f90
0x4c70b4: c783f0000000ec75c000     mov    DWORD PTR [ebx+0xf0],0xc075ec
0x4c70be: 33f6                     xor    esi,esi
0x4c70c0: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x4c70c4: 8d835c010000             lea    eax,[ebx+0x15c]
0x4c70ca: 56                       push   esi
0x4c70cb: c7035475c000             mov    DWORD PTR [ebx],0xc07554
0x4c70d1: c783f0000000dc75c000     mov    DWORD PTR [ebx+0xf0],0xc075dc
0x4c70db: 50                       push   eax
0x4c70dc: 8930                     mov    DWORD PTR [eax],esi
0x4c70de: 897004                   mov    DWORD PTR [eax+0x4],esi
0x4c70e1: e87a330000               call   0x4ca460
0x4c70e6: c645fc02                 mov    BYTE PTR [ebp-0x4],0x2
0x4c70ea: 89b36c030000             mov    DWORD PTR [ebx+0x36c],esi
0x4c70f0: 89b370030000             mov    DWORD PTR [ebx+0x370],esi
0x4c70f6: c7837403000001000000     mov    DWORD PTR [ebx+0x374],0x1
0x4c7100: 6a14                     push   0x14
0x4c7102: 89b380030000             mov    DWORD PTR [ebx+0x380],esi
0x4c7108: e85ba13c00               call   0x891268
0x4c710d: 83c404                   add    esp,0x4
0x4c7110: 3bc6                     cmp    eax,esi
0x4c7112: 0f84170a0000             je     0x4c7b2f
0x4c7118: 89837c030000             mov    DWORD PTR [ebx+0x37c],eax
0x4c711e: 8900                     mov    DWORD PTR [eax],eax
0x4c7120: 8b837c030000             mov    eax,DWORD PTR [ebx+0x37c]
0x4c7126: 894004                   mov    DWORD PTR [eax+0x4],eax
0x4c7129: 8b837c030000             mov    eax,DWORD PTR [ebx+0x37c]
0x4c712f: 894008                   mov    DWORD PTR [eax+0x8],eax
0x4c7132: 8b837c030000             mov    eax,DWORD PTR [ebx+0x37c]
0x4c7138: c6401001                 mov    BYTE PTR [eax+0x10],0x1
0x4c713c: 8b8b7c030000             mov    ecx,DWORD PTR [ebx+0x37c]
0x4c7142: c6411101                 mov    BYTE PTR [ecx+0x11],0x1
0x4c7146: c645fc03                 mov    BYTE PTR [ebp-0x4],0x3
0x4c714a: f30f1005c056c400         movss  xmm0,DWORD PTR ds:0xc456c0
0x4c7152: b801000000               mov    eax,0x1
0x4c7157: 89838c030000             mov    DWORD PTR [ebx+0x38c],eax
0x4c715d: 8983ac030000             mov    DWORD PTR [ebx+0x3ac],eax
0x4c7163: b864000000               mov    eax,0x64
0x4c7168: 33d2                     xor    edx,edx
0x4c716a: 66899388030000           mov    WORD PTR [ebx+0x388],dx
0x4c7171: 89b390030000             mov    DWORD PTR [ebx+0x390],esi
0x4c7177: f30f118398030000         movss  DWORD PTR [ebx+0x398],xmm0
0x4c717f: c7839c0300007f000000     mov    DWORD PTR [ebx+0x39c],0x7f
0x4c7189: 89b3a0030000             mov    DWORD PTR [ebx+0x3a0],esi
0x4c718f: 8893a4030000             mov    BYTE PTR [ebx+0x3a4],dl
0x4c7195: 89b3a8030000             mov    DWORD PTR [ebx+0x3a8],esi
0x4c719b: 89b3b0030000             mov    DWORD PTR [ebx+0x3b0],esi
0x4c71a1: 89b3b4030000             mov    DWORD PTR [ebx+0x3b4],esi
0x4c71a7: 89b3b8030000             mov    DWORD PTR [ebx+0x3b8],esi
0x4c71ad: 8983bc030000             mov    DWORD PTR [ebx+0x3bc],eax
0x4c71b3: 8983c0030000             mov    DWORD PTR [ebx+0x3c0],eax
0x4c71b9: 8983c4030000             mov    DWORD PTR [ebx+0x3c4],eax
0x4c71bf: 8983c8030000             mov    DWORD PTR [ebx+0x3c8],eax
0x4c71c5: 8983cc030000             mov    DWORD PTR [ebx+0x3cc],eax
0x4c71cb: 8983d0030000             mov    DWORD PTR [ebx+0x3d0],eax
0x4c71d1: 89b3d4030000             mov    DWORD PTR [ebx+0x3d4],esi
0x4c71d7: 89b3d8030000             mov    DWORD PTR [ebx+0x3d8],esi
0x4c71dd: 89b3dc030000             mov    DWORD PTR [ebx+0x3dc],esi
0x4c71e3: 89b3e0030000             mov    DWORD PTR [ebx+0x3e0],esi
0x4c71e9: 89b3e4030000             mov    DWORD PTR [ebx+0x3e4],esi
0x4c71ef: 89b3e8030000             mov    DWORD PTR [ebx+0x3e8],esi
0x4c71f5: 6a18                     push   0x18
0x4c71f7: 89b3f8030000             mov    DWORD PTR [ebx+0x3f8],esi
0x4c71fd: e866a03c00               call   0x891268
0x4c7202: 83c404                   add    esp,0x4
0x4c7205: 3bc6                     cmp    eax,esi
0x4c7207: 0f84fe080000             je     0x4c7b0b
0x4c720d: 8983f4030000             mov    DWORD PTR [ebx+0x3f4],eax
0x4c7213: 8900                     mov    DWORD PTR [eax],eax
0x4c7215: 8b83f4030000             mov    eax,DWORD PTR [ebx+0x3f4]
0x4c721b: 894004                   mov    DWORD PTR [eax+0x4],eax
0x4c721e: 8b83f4030000             mov    eax,DWORD PTR [ebx+0x3f4]
0x4c7224: 894008                   mov    DWORD PTR [eax+0x8],eax
0x4c7227: 8b83f4030000             mov    eax,DWORD PTR [ebx+0x3f4]
0x4c722d: c6401401                 mov    BYTE PTR [eax+0x14],0x1
0x4c7231: 8b8bf4030000             mov    ecx,DWORD PTR [ebx+0x3f4]
0x4c7237: c6411501                 mov    BYTE PTR [ecx+0x15],0x1
0x4c723b: c645fc04                 mov    BYTE PTR [ebp-0x4],0x4
0x4c723f: 6a38                     push   0x38
0x4c7241: 89b300040000             mov    DWORD PTR [ebx+0x400],esi
0x4c7247: 89b304040000             mov    DWORD PTR [ebx+0x404],esi
0x4c724d: 89b308040000             mov    DWORD PTR [ebx+0x408],esi
0x4c7253: 89b310040000             mov    DWORD PTR [ebx+0x410],esi
0x4c7259: 89b314040000             mov    DWORD PTR [ebx+0x414],esi
0x4c725f: 89b318040000             mov    DWORD PTR [ebx+0x418],esi
0x4c7265: c7831c04000001000000     mov    DWORD PTR [ebx+0x41c],0x1

; B03 CMonster constructor complete; no explicit +424 initialization in this body
; VA [0x4d1710,0x4d18d0) SHA256 41cc95ca5aa7aac20573d3aea111d56f8c53b7c97bb1025dad2185dad5c51577
0x4d1710: 55                       push   ebp
0x4d1711: 8bec                     mov    ebp,esp
0x4d1713: 6aff                     push   0xffffffff
0x4d1715: 68b9089100               push   0x9108b9
0x4d171a: 64a100000000             mov    eax,fs:0x0
0x4d1720: 50                       push   eax
0x4d1721: 51                       push   ecx
0x4d1722: 53                       push   ebx
0x4d1723: 56                       push   esi
0x4d1724: 57                       push   edi
0x4d1725: a1201fd600               mov    eax,ds:0xd61f20
0x4d172a: 33c5                     xor    eax,ebp
0x4d172c: 50                       push   eax
0x4d172d: 8d45f4                   lea    eax,[ebp-0xc]
0x4d1730: 64a300000000             mov    fs:0x0,eax
0x4d1736: 8b7d08                   mov    edi,DWORD PTR [ebp+0x8]
0x4d1739: 57                       push   edi
0x4d173a: e83159ffff               call   0x4c7070
0x4d173f: 33db                     xor    ebx,ebx
0x4d1741: 895dfc                   mov    DWORD PTR [ebp-0x4],ebx
0x4d1744: 0f57c0                   xorps  xmm0,xmm0
0x4d1747: 6a3c                     push   0x3c
0x4d1749: c707dcc9c000             mov    DWORD PTR [edi],0xc0c9dc
0x4d174f: c787f000000064cac000     mov    DWORD PTR [edi+0xf0],0xc0ca64
0x4d1759: 899f20040000             mov    DWORD PTR [edi+0x420],ebx
0x4d175f: 899f28040000             mov    DWORD PTR [edi+0x428],ebx
0x4d1765: f30f11872c040000         movss  DWORD PTR [edi+0x42c],xmm0
0x4d176d: 899f30040000             mov    DWORD PTR [edi+0x430],ebx
0x4d1773: e8f0fa3b00               call   0x891268
0x4d1778: 8bf0                     mov    esi,eax
0x4d177a: 83c404                   add    esp,0x4
0x4d177d: 8975f0                   mov    DWORD PTR [ebp-0x10],esi
0x4d1780: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x4d1784: 3bf3                     cmp    esi,ebx
0x4d1786: 7419                     je     0x4d17a1
0x4d1788: 8bc7                     mov    eax,edi
0x4d178a: 8d4b03                   lea    ecx,[ebx+0x3]
0x4d178d: e89e9affff               call   0x4cb230
0x4d1792: c706cc77c000             mov    DWORD PTR [esi],0xc077cc
0x4d1798: c7463401000000           mov    DWORD PTR [esi+0x34],0x1
0x4d179f: eb02                     jmp    0x4d17a3
0x4d17a1: 33f6                     xor    esi,esi
0x4d17a3: c645fc00                 mov    BYTE PTR [ebp-0x4],0x0
0x4d17a7: 8b5e08                   mov    ebx,DWORD PTR [esi+0x8]
0x4d17aa: 83bc9ff400000000         cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
0x4d17b2: 740d                     je     0x4d17c1
0x4d17b4: 683c75c000               push   0xc0753c
0x4d17b9: e8a2c32100               call   0x6edb60
0x4d17be: 83c404                   add    esp,0x4
0x4d17c1: 89b49ff4000000           mov    DWORD PTR [edi+ebx*4+0xf4],esi
0x4d17c8: 83bf5801000000           cmp    DWORD PTR [edi+0x158],0x0
0x4d17cf: 7506                     jne    0x4d17d7
0x4d17d1: 89b758010000             mov    DWORD PTR [edi+0x158],esi
0x4d17d7: 6a38                     push   0x38
0x4d17d9: e88afa3b00               call   0x891268
0x4d17de: 8bf0                     mov    esi,eax
0x4d17e0: 83c404                   add    esp,0x4
0x4d17e3: 8975f0                   mov    DWORD PTR [ebp-0x10],esi
0x4d17e6: b902000000               mov    ecx,0x2
0x4d17eb: 884dfc                   mov    BYTE PTR [ebp-0x4],cl
0x4d17ee: 85f6                     test   esi,esi
0x4d17f0: 741d                     je     0x4d180f
0x4d17f2: 8bc7                     mov    eax,edi
0x4d17f4: e8379affff               call   0x4cb230
0x4d17f9: b801000000               mov    eax,0x1
0x4d17fe: c706b477c000             mov    DWORD PTR [esi],0xc077b4
0x4d1804: 894628                   mov    DWORD PTR [esi+0x28],eax
0x4d1807: 89462c                   mov    DWORD PTR [esi+0x2c],eax
0x4d180a: 894630                   mov    DWORD PTR [esi+0x30],eax
0x4d180d: eb02                     jmp    0x4d1811
0x4d180f: 33f6                     xor    esi,esi
0x4d1811: c645fc00                 mov    BYTE PTR [ebp-0x4],0x0
0x4d1815: 8b5e08                   mov    ebx,DWORD PTR [esi+0x8]
0x4d1818: 83bc9ff400000000         cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
0x4d1820: 740d                     je     0x4d182f
0x4d1822: 683c75c000               push   0xc0753c
0x4d1827: e834c32100               call   0x6edb60
0x4d182c: 83c404                   add    esp,0x4
0x4d182f: 89b49ff4000000           mov    DWORD PTR [edi+ebx*4+0xf4],esi
0x4d1836: 83bf5801000000           cmp    DWORD PTR [edi+0x158],0x0
0x4d183d: 7506                     jne    0x4d1845
0x4d183f: 89b758010000             mov    DWORD PTR [edi+0x158],esi
0x4d1845: 6a3c                     push   0x3c
0x4d1847: e81cfa3b00               call   0x891268
0x4d184c: 8bf0                     mov    esi,eax
0x4d184e: 83c404                   add    esp,0x4
0x4d1851: 8975f0                   mov    DWORD PTR [ebp-0x10],esi
0x4d1854: c645fc03                 mov    BYTE PTR [ebp-0x4],0x3
0x4d1858: 85f6                     test   esi,esi
0x4d185a: 7422                     je     0x4d187e
0x4d185c: 8bc7                     mov    eax,edi
0x4d185e: b905000000               mov    ecx,0x5
0x4d1863: e8c899ffff               call   0x4cb230
0x4d1868: c7463809000000           mov    DWORD PTR [esi+0x38],0x9
0x4d186f: c706fc77c000             mov    DWORD PTR [esi],0xc077fc
0x4d1875: c7462c01000000           mov    DWORD PTR [esi+0x2c],0x1
0x4d187c: eb02                     jmp    0x4d1880
0x4d187e: 33f6                     xor    esi,esi
0x4d1880: 8b5e08                   mov    ebx,DWORD PTR [esi+0x8]
0x4d1883: 83bc9ff400000000         cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
0x4d188b: 740d                     je     0x4d189a
0x4d188d: 683c75c000               push   0xc0753c
0x4d1892: e8c9c22100               call   0x6edb60
0x4d1897: 83c404                   add    esp,0x4
0x4d189a: 89b49ff4000000           mov    DWORD PTR [edi+ebx*4+0xf4],esi
0x4d18a1: 83bf5801000000           cmp    DWORD PTR [edi+0x158],0x0
0x4d18a8: 8bc7                     mov    eax,edi
0x4d18aa: 7506                     jne    0x4d18b2
0x4d18ac: 89b758010000             mov    DWORD PTR [edi+0x158],esi
0x4d18b2: c7879c03000001000000     mov    DWORD PTR [edi+0x39c],0x1
0x4d18bc: 8b4df4                   mov    ecx,DWORD PTR [ebp-0xc]
0x4d18bf: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4d18c6: 59                       pop    ecx
0x4d18c7: 5f                       pop    edi
0x4d18c8: 5e                       pop    esi
0x4d18c9: 5b                       pop    ebx
0x4d18ca: 8be5                     mov    esp,ebp
0x4d18cc: 5d                       pop    ebp
0x4d18cd: c20400                   ret    0x4

; B04 0007 constructor/metadata/insert body plus invalid-type branch; excludes jump-table data
; VA [0x4ae4d0,0x4aed8d) SHA256 500f4eef861516c51948deb5b41051fa1a7a22050ab3c407bbb55a02d27597d5
0x4ae4d0: 55                       push   ebp
0x4ae4d1: 8bec                     mov    ebp,esp
0x4ae4d3: 83e4f8                   and    esp,0xfffffff8
0x4ae4d6: 6aff                     push   0xffffffff
0x4ae4d8: 68db0c9400               push   0x940cdb
0x4ae4dd: 64a100000000             mov    eax,fs:0x0
0x4ae4e3: 50                       push   eax
0x4ae4e4: 81ec38010000             sub    esp,0x138
0x4ae4ea: a1201fd600               mov    eax,ds:0xd61f20
0x4ae4ef: 33c4                     xor    eax,esp
0x4ae4f1: 89842430010000           mov    DWORD PTR [esp+0x130],eax
0x4ae4f8: 53                       push   ebx
0x4ae4f9: 56                       push   esi
0x4ae4fa: 57                       push   edi
0x4ae4fb: a1201fd600               mov    eax,ds:0xd61f20
0x4ae500: 33c4                     xor    eax,esp
0x4ae502: 50                       push   eax
0x4ae503: 8d842448010000           lea    eax,[esp+0x148]
0x4ae50a: 64a300000000             mov    fs:0x0,eax
0x4ae510: 8b450c                   mov    eax,DWORD PTR [ebp+0xc]
0x4ae513: 8b5d08                   mov    ebx,DWORD PTR [ebp+0x8]
0x4ae516: 83f802                   cmp    eax,0x2
0x4ae519: 7304                     jae    0x4ae51f
0x4ae51b: 33d2                     xor    edx,edx
0x4ae51d: eb0d                     jmp    0x4ae52c
0x4ae51f: 8d48fe                   lea    ecx,[eax-0x2]
0x4ae522: b84fecc44e               mov    eax,0x4ec4ec4f
0x4ae527: f7e1                     mul    ecx
0x4ae529: c1ea03                   shr    edx,0x3
0x4ae52c: 89542428                 mov    DWORD PTR [esp+0x28],edx
0x4ae530: c744242400000000         mov    DWORD PTR [esp+0x24],0x0
0x4ae538: 85d2                     test   edx,edx
0x4ae53a: 0f8418080000             je     0x4aed58
0x4ae540: 83c306                   add    ebx,0x6
0x4ae543: eb0b                     jmp    0x4ae550
0x4ae545: 8da42400000000           lea    esp,[esp+0x0]
0x4ae54c: 8d642400                 lea    esp,[esp+0x0]
0x4ae550: b801000000               mov    eax,0x1
0x4ae555: 89442420                 mov    DWORD PTR [esp+0x20],eax
0x4ae559: 84052cb2fa00             test   BYTE PTR ds:0xfab22c,al
0x4ae55f: 752e                     jne    0x4ae58f
0x4ae561: 09052cb2fa00             or     DWORD PTR ds:0xfab22c,eax
0x4ae567: c784245001000000000000   mov    DWORD PTR [esp+0x150],0x0
0x4ae572: e819070300               call   0x4dec90
0x4ae577: 6830cebc00               push   0xbcce30
0x4ae57c: e8993d3e00               call   0x89231a
0x4ae581: 83c404                   add    esp,0x4
0x4ae584: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4ae58f: 0fb753fc                 movzx  edx,WORD PTR [ebx-0x4]
0x4ae593: 8d442418                 lea    eax,[esp+0x18]
0x4ae597: 50                       push   eax
0x4ae598: 8d442458                 lea    eax,[esp+0x58]
0x4ae59c: b938b1fa00               mov    ecx,0xfab138
0x4ae5a1: 8954241c                 mov    DWORD PTR [esp+0x1c],edx
0x4ae5a5: e856093800               call   0x82ef00
0x4ae5aa: 8b08                     mov    ecx,DWORD PTR [eax]
0x4ae5ac: 3b0d3cb1fa00             cmp    ecx,DWORD PTR ds:0xfab13c
0x4ae5b2: 0f858a070000             jne    0x4aed42
0x4ae5b8: 0fb643fc                 movzx  eax,BYTE PTR [ebx-0x4]
0x4ae5bc: 0fb67bfe                 movzx  edi,BYTE PTR [ebx-0x2]
0x4ae5c0: 0fb70b                   movzx  ecx,WORD PTR [ebx]
0x4ae5c3: 4f                       dec    edi
0x4ae5c4: 8bd0                     mov    edx,eax
0x4ae5c6: c1e208                   shl    edx,0x8
0x4ae5c9: 0bfa                     or     edi,edx
0x4ae5cb: c1e710                   shl    edi,0x10
0x4ae5ce: 0bf9                     or     edi,ecx
0x4ae5d0: 897c241c                 mov    DWORD PTR [esp+0x1c],edi
0x4ae5d4: 83f807                   cmp    eax,0x7
0x4ae5d7: 0f87a6070000             ja     0x4aed83
0x4ae5dd: ff248590ed4a00           jmp    DWORD PTR [eax*4+0x4aed90]
0x4ae5e4: 6844040000               push   0x444
0x4ae5e9: e87a2c3e00               call   0x891268
0x4ae5ee: 83c404                   add    esp,0x4
0x4ae5f1: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4ae5f5: c784245001000001000000   mov    DWORD PTR [esp+0x150],0x1
0x4ae600: 85c0                     test   eax,eax
0x4ae602: 740e                     je     0x4ae612
0x4ae604: 8b530e                   mov    edx,DWORD PTR [ebx+0xe]
0x4ae607: 52                       push   edx
0x4ae608: 50                       push   eax
0x4ae609: e8e2f00100               call   0x4cd6f0
0x4ae60e: 8bf0                     mov    esi,eax
0x4ae610: eb02                     jmp    0x4ae614
0x4ae612: 33f6                     xor    esi,esi
0x4ae614: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4ae61f: e87c65f5ff               call   0x404ba0
0x4ae624: 8b80505f0000             mov    eax,DWORD PTR [eax+0x5f50]
0x4ae62a: 39430e                   cmp    DWORD PTR [ebx+0xe],eax
0x4ae62d: 0f85e4020000             jne    0x4ae917
0x4ae633: e86865f5ff               call   0x404ba0
0x4ae638: 8b9024690000             mov    edx,DWORD PTR [eax+0x6924]
0x4ae63e: 0fb703                   movzx  eax,WORD PTR [ebx]
0x4ae641: 83f809                   cmp    eax,0x9
0x4ae644: 0f87cd020000             ja     0x4ae917
0x4ae64a: 8bc8                     mov    ecx,eax
0x4ae64c: 69c910020000             imul   ecx,ecx,0x210
0x4ae652: 03ca                     add    ecx,edx
0x4ae654: 0f84bd020000             je     0x4ae917
0x4ae65a: 83795c00                 cmp    DWORD PTR [ecx+0x5c],0x0
0x4ae65e: 0f85b3020000             jne    0x4ae917
0x4ae664: 8b11                     mov    edx,DWORD PTR [ecx]
0x4ae666: 50                       push   eax
0x4ae667: 8b4204                   mov    eax,DWORD PTR [edx+0x4]
0x4ae66a: ffd0                     call   eax
0x4ae66c: e9a6020000               jmp    0x4ae917
0x4ae671: 6834040000               push   0x434
0x4ae676: e8ed2b3e00               call   0x891268
0x4ae67b: 83c404                   add    esp,0x4
0x4ae67e: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4ae682: c784245001000002000000   mov    DWORD PTR [esp+0x150],0x2
0x4ae68d: 85c0                     test   eax,eax
0x4ae68f: 740a                     je     0x4ae69b
0x4ae691: 50                       push   eax
0x4ae692: e879300200               call   0x4d1710
0x4ae697: 8bf0                     mov    esi,eax
0x4ae699: eb02                     jmp    0x4ae69d
0x4ae69b: 33f6                     xor    esi,esi
0x4ae69d: 6a48                     push   0x48
0x4ae69f: c7842454010000ffffffff   mov    DWORD PTR [esp+0x154],0xffffffff
0x4ae6aa: e8b92b3e00               call   0x891268
0x4ae6af: 8bf8                     mov    edi,eax
0x4ae6b1: 83c404                   add    esp,0x4
0x4ae6b4: 897c2414                 mov    DWORD PTR [esp+0x14],edi
0x4ae6b8: c784245001000003000000   mov    DWORD PTR [esp+0x150],0x3
0x4ae6c3: 85ff                     test   edi,edi
0x4ae6c5: 7478                     je     0x4ae73f
0x4ae6c7: 0fb74604                 movzx  eax,WORD PTR [esi+0x4]
0x4ae6cb: 0f57c0                   xorps  xmm0,xmm0
0x4ae6ce: 894704                   mov    DWORD PTR [edi+0x4],eax
0x4ae6d1: c70707000000             mov    DWORD PTR [edi],0x7
0x4ae6d7: c7470801000000           mov    DWORD PTR [edi+0x8],0x1
0x4ae6de: c6470c01                 mov    BYTE PTR [edi+0xc],0x1
0x4ae6e2: 8b4b02                   mov    ecx,DWORD PTR [ebx+0x2]
0x4ae6e5: 894f10                   mov    DWORD PTR [edi+0x10],ecx
0x4ae6e8: 8b5306                   mov    edx,DWORD PTR [ebx+0x6]
0x4ae6eb: 895714                   mov    DWORD PTR [edi+0x14],edx
0x4ae6ee: f30f1144243c             movss  DWORD PTR [esp+0x3c],xmm0
0x4ae6f4: 8b4c243c                 mov    ecx,DWORD PTR [esp+0x3c]
0x4ae6f8: 894f20                   mov    DWORD PTR [edi+0x20],ecx
0x4ae6fb: 33d2                     xor    edx,edx
0x4ae6fd: f30f11442438             movss  DWORD PTR [esp+0x38],xmm0
0x4ae703: 8b442438                 mov    eax,DWORD PTR [esp+0x38]
0x4ae707: 8d4f24                   lea    ecx,[edi+0x24]
0x4ae70a: f30f114718               movss  DWORD PTR [edi+0x18],xmm0
0x4ae70f: 89471c                   mov    DWORD PTR [edi+0x1c],eax
0x4ae712: 52                       push   edx
0x4ae713: c7411407000000           mov    DWORD PTR [ecx+0x14],0x7
0x4ae71a: c7411000000000           mov    DWORD PTR [ecx+0x10],0x0
0x4ae721: 68fcd1be00               push   0xbed1fc
0x4ae726: 668911                   mov    WORD PTR [ecx],dx
0x4ae729: e8323af5ff               call   0x402160
0x4ae72e: 0f57c0                   xorps  xmm0,xmm0
0x4ae731: c7474000000000           mov    DWORD PTR [edi+0x40],0x0
0x4ae738: f30f114744               movss  DWORD PTR [edi+0x44],xmm0
0x4ae73d: eb02                     jmp    0x4ae741
0x4ae73f: 33ff                     xor    edi,edi
0x4ae741: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4ae74c: f605c0f3fd0001           test   BYTE PTR ds:0xfdf3c0,0x1
0x4ae753: 751e                     jne    0x4ae773
0x4ae755: 830dc0f3fd0001           or     DWORD PTR ds:0xfdf3c0,0x1
0x4ae75c: 6850dfbc00               push   0xbcdf50
0x4ae761: c705c4f3fd0000000000     mov    DWORD PTR ds:0xfdf3c4,0x0
0x4ae76b: e8aa3b3e00               call   0x89231a
0x4ae770: 83c404                   add    esp,0x4
0x4ae773: a1c4f3fd00               mov    eax,ds:0xfdf3c4
0x4ae778: 57                       push   edi
0x4ae779: 50                       push   eax
0x4ae77a: e8410e0c00               call   0x56f5c0
0x4ae77f: f605b075fb0001           test   BYTE PTR ds:0xfb75b0,0x1
0x4ae786: 0fb64313                 movzx  eax,BYTE PTR [ebx+0x13]
0x4ae78a: 898624040000             mov    DWORD PTR [esi+0x424],eax
0x4ae790: 752f                     jne    0x4ae7c1
0x4ae792: 830db075fb0001           or     DWORD PTR ds:0xfb75b0,0x1
0x4ae799: c784245001000004000000   mov    DWORD PTR [esp+0x150],0x4
0x4ae7a4: e8d7550400               call   0x4f3d80
0x4ae7a9: 68e0d1bc00               push   0xbcd1e0
0x4ae7ae: e8673b3e00               call   0x89231a
0x4ae7b3: 83c404                   add    esp,0x4
0x4ae7b6: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4ae7c1: 8b4c241c                 mov    ecx,DWORD PTR [esp+0x1c]
0x4ae7c5: 894c2418                 mov    DWORD PTR [esp+0x18],ecx
0x4ae7c9: 8d542418                 lea    edx,[esp+0x18]
0x4ae7cd: b97074fb00               mov    ecx,0xfb7470
0x4ae7d2: e899920400               call   0x4f7a70
0x4ae7d7: 80786100                 cmp    BYTE PTR [eax+0x61],0x0
0x4ae7db: 751c                     jne    0x4ae7f9
0x4ae7dd: 8b8668030000             mov    eax,DWORD PTR [esi+0x368]
0x4ae7e3: 33c9                     xor    ecx,ecx
0x4ae7e5: 894c2420                 mov    DWORD PTR [esp+0x20],ecx
0x4ae7e9: 3bc1                     cmp    eax,ecx
0x4ae7eb: 7414                     je     0x4ae801
0x4ae7ed: 8b7c241c                 mov    edi,DWORD PTR [esp+0x1c]
0x4ae7f1: 894824                   mov    DWORD PTR [eax+0x24],ecx
0x4ae7f4: e91e010000               jmp    0x4ae917
0x4ae7f9: c744242001000000         mov    DWORD PTR [esp+0x20],0x1
0x4ae801: 8b7c241c                 mov    edi,DWORD PTR [esp+0x1c]
0x4ae805: e90d010000               jmp    0x4ae917
0x4ae80a: 682c040000               push   0x42c
0x4ae80f: e8542a3e00               call   0x891268
0x4ae814: 83c404                   add    esp,0x4
0x4ae817: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4ae81b: c784245001000005000000   mov    DWORD PTR [esp+0x150],0x5
0x4ae826: 85c0                     test   eax,eax
0x4ae828: 740c                     je     0x4ae836
0x4ae82a: 50                       push   eax
0x4ae82b: e8f0380200               call   0x4d2120
0x4ae830: 89442418                 mov    DWORD PTR [esp+0x18],eax
0x4ae834: eb08                     jmp    0x4ae83e
0x4ae836: c744241800000000         mov    DWORD PTR [esp+0x18],0x0
0x4ae83e: 83ceff                   or     esi,0xffffffff
0x4ae841: 89b42450010000           mov    DWORD PTR [esp+0x150],esi
0x4ae848: f605c818fe0001           test   BYTE PTR ds:0xfe18c8,0x1
0x4ae84f: 752b                     jne    0x4ae87c
0x4ae851: 830dc818fe0001           or     DWORD PTR ds:0xfe18c8,0x1
0x4ae858: c784245001000006000000   mov    DWORD PTR [esp+0x150],0x6
0x4ae863: e808110900               call   0x53f970
0x4ae868: 6810e8bc00               push   0xbce810
0x4ae86d: e8a83a3e00               call   0x89231a
0x4ae872: 83c404                   add    esp,0x4
0x4ae875: 89b42450010000           mov    DWORD PTR [esp+0x150],esi
0x4ae87c: 0fb733                   movzx  esi,WORD PTR [ebx]
0x4ae87f: 8d542414                 lea    edx,[esp+0x14]
0x4ae883: 52                       push   edx
0x4ae884: 8d442444                 lea    eax,[esp+0x44]
0x4ae888: b9dc18fe00               mov    ecx,0xfe18dc
0x4ae88d: 89742418                 mov    DWORD PTR [esp+0x18],esi
0x4ae891: e82a503900               call   0x8438c0
0x4ae896: 8b4c2440                 mov    ecx,DWORD PTR [esp+0x40]
0x4ae89a: 3b0de018fe00             cmp    ecx,DWORD PTR ds:0xfe18e0
0x4ae8a0: 742e                     je     0x4ae8d0
0x4ae8a2: 8a43fd                   mov    al,BYTE PTR [ebx-0x3]
0x4ae8a5: 88442444                 mov    BYTE PTR [esp+0x44],al
0x4ae8a9: 8b4110                   mov    eax,DWORD PTR [ecx+0x10]
0x4ae8ac: 8b0dec18fe00             mov    ecx,DWORD PTR ds:0xfe18ec
0x4ae8b2: 8944244c                 mov    DWORD PTR [esp+0x4c],eax
0x4ae8b6: 8d442444                 lea    eax,[esp+0x44]
0x4ae8ba: bfcc18fe00               mov    edi,0xfe18cc
0x4ae8bf: 89742448                 mov    DWORD PTR [esp+0x48],esi
0x4ae8c3: 894c2450                 mov    DWORD PTR [esp+0x50],ecx
0x4ae8c7: e8d4020900               call   0x53eba0
0x4ae8cc: 8b7c241c                 mov    edi,DWORD PTR [esp+0x1c]
0x4ae8d0: 8b742418                 mov    esi,DWORD PTR [esp+0x18]
0x4ae8d4: eb41                     jmp    0x4ae917
0x4ae8d6: 6828040000               push   0x428
0x4ae8db: e888293e00               call   0x891268
0x4ae8e0: 83c404                   add    esp,0x4
0x4ae8e3: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4ae8e7: c784245001000007000000   mov    DWORD PTR [esp+0x150],0x7
0x4ae8f2: 85c0                     test   eax,eax
0x4ae8f4: 7408                     je     0x4ae8fe
0x4ae8f6: 50                       push   eax
0x4ae8f7: e864270200               call   0x4d1060
0x4ae8fc: eb02                     jmp    0x4ae900
0x4ae8fe: 33c0                     xor    eax,eax
0x4ae900: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4ae90b: 0fb64b13                 movzx  ecx,BYTE PTR [ebx+0x13]
0x4ae90f: 898820040000             mov    DWORD PTR [eax+0x420],ecx
0x4ae915: 8bf0                     mov    esi,eax
0x4ae917: 85f6                     test   esi,esi
0x4ae919: 0f8464040000             je     0x4aed83
0x4ae91f: f605600ffc0001           test   BYTE PTR ds:0xfc0f60,0x1
0x4ae926: 752f                     jne    0x4ae957
0x4ae928: 830d600ffc0001           or     DWORD PTR ds:0xfc0f60,0x1
0x4ae92f: c784245001000008000000   mov    DWORD PTR [esp+0x150],0x8
0x4ae93a: e801e62e00               call   0x79cf40
0x4ae93f: 6880dbbc00               push   0xbcdb80
0x4ae944: e8d1393e00               call   0x89231a
0x4ae949: 83c404                   add    esp,0x4
0x4ae94c: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4ae957: 0fb713                   movzx  edx,WORD PTR [ebx]
0x4ae95a: 8d442414                 lea    eax,[esp+0x14]
0x4ae95e: 50                       push   eax
0x4ae95f: 8d442430                 lea    eax,[esp+0x30]
0x4ae963: b9900efc00               mov    ecx,0xfc0e90
0x4ae968: 89542418                 mov    DWORD PTR [esp+0x18],edx
0x4ae96c: e81f6e0600               call   0x515790
0x4ae971: 8b44242c                 mov    eax,DWORD PTR [esp+0x2c]
0x4ae975: 3b05940efc00             cmp    eax,DWORD PTR ds:0xfc0e94
0x4ae97b: 740d                     je     0x4ae98a
0x4ae97d: 8b4010                   mov    eax,DWORD PTR [eax+0x10]
0x4ae980: 83785400                 cmp    DWORD PTR [eax+0x54],0x0
0x4ae984: 0f8523010000             jne    0x4aeaad
0x4ae98a: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4ae990: 8b11                     mov    edx,DWORD PTR [ecx]
0x4ae992: 8b4220                   mov    eax,DWORD PTR [edx+0x20]
0x4ae995: ffd0                     call   eax
0x4ae997: 85c0                     test   eax,eax
0x4ae999: 0f84cd000000             je     0x4aea6c
0x4ae99f: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4ae9a6: 8b889c000000             mov    ecx,DWORD PTR [eax+0x9c]
0x4ae9ac: 894c2414                 mov    DWORD PTR [esp+0x14],ecx
0x4ae9b0: 752f                     jne    0x4ae9e1
0x4ae9b2: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4ae9b9: c784245001000009000000   mov    DWORD PTR [esp+0x150],0x9
0x4ae9c4: e8c7020300               call   0x4dec90
0x4ae9c9: 6830cebc00               push   0xbcce30
0x4ae9ce: e847393e00               call   0x89231a
0x4ae9d3: 83c404                   add    esp,0x4
0x4ae9d6: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4ae9e1: 8b542414                 mov    edx,DWORD PTR [esp+0x14]
0x4ae9e5: 8d442414                 lea    eax,[esp+0x14]
0x4ae9e9: 50                       push   eax
0x4ae9ea: 8d442438                 lea    eax,[esp+0x38]
0x4ae9ee: b948b1fa00               mov    ecx,0xfab148
0x4ae9f3: 89542418                 mov    DWORD PTR [esp+0x18],edx
0x4ae9f7: e8c44e3900               call   0x8438c0
0x4ae9fc: 8b442434                 mov    eax,DWORD PTR [esp+0x34]
0x4aea00: 3b054cb1fa00             cmp    eax,DWORD PTR ds:0xfab14c
0x4aea06: 7464                     je     0x4aea6c
0x4aea08: 8b4010                   mov    eax,DWORD PTR [eax+0x10]
0x4aea0b: 85c0                     test   eax,eax
0x4aea0d: 745d                     je     0x4aea6c
0x4aea0f: 80782005                 cmp    BYTE PTR [eax+0x20],0x5
0x4aea13: 7257                     jb     0x4aea6c
0x4aea15: 0fb70b                   movzx  ecx,WORD PTR [ebx]
0x4aea18: 51                       push   ecx
0x4aea19: 68d869c000               push   0xc069d8
0x4aea1e: 8d54247c                 lea    edx,[esp+0x7c]
0x4aea22: e859920000               call   0x4b7c80
0x4aea27: 83c408                   add    esp,0x8
0x4aea2a: 8d542474                 lea    edx,[esp+0x74]
0x4aea2e: 52                       push   edx
0x4aea2f: 8d4c245c                 lea    ecx,[esp+0x5c]
0x4aea33: e81838f5ff               call   0x402250
0x4aea38: 8d442458                 lea    eax,[esp+0x58]
0x4aea3c: 50                       push   eax
0x4aea3d: c78424540100000a000000   mov    DWORD PTR [esp+0x154],0xa
0x4aea48: e8730ef6ff               call   0x40f8c0
0x4aea4d: 8bf8                     mov    edi,eax
0x4aea4f: e8dc800200               call   0x4d6b30
0x4aea54: 8d4c2458                 lea    ecx,[esp+0x58]
0x4aea58: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4aea63: e8d8b90400               call   0x4fa440
0x4aea68: 8b7c241c                 mov    edi,DWORD PTR [esp+0x1c]
0x4aea6c: f605400efc0001           test   BYTE PTR ds:0xfc0e40,0x1
0x4aea73: 752f                     jne    0x4aeaa4
0x4aea75: 830d400efc0001           or     DWORD PTR ds:0xfc0e40,0x1
0x4aea7c: c78424500100000b000000   mov    DWORD PTR [esp+0x150],0xb
0x4aea87: e8e41c0900               call   0x540770
0x4aea8c: 6860dbbc00               push   0xbcdb60
0x4aea91: e884383e00               call   0x89231a
0x4aea96: 83c404                   add    esp,0x4
0x4aea99: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4aeaa4: 0fb70b                   movzx  ecx,WORD PTR [ebx]
0x4aeaa7: 51                       push   ecx
0x4aeaa8: e8632b0900               call   0x541610
0x4aeaad: f605b075fb0001           test   BYTE PTR ds:0xfb75b0,0x1
0x4aeab4: 752f                     jne    0x4aeae5
0x4aeab6: 830db075fb0001           or     DWORD PTR ds:0xfb75b0,0x1
0x4aeabd: c78424500100000c000000   mov    DWORD PTR [esp+0x150],0xc
0x4aeac8: e8b3520400               call   0x4f3d80
0x4aeacd: 68e0d1bc00               push   0xbcd1e0
0x4aead2: e843383e00               call   0x89231a
0x4aead7: 83c404                   add    esp,0x4
0x4aeada: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4aeae5: 8d542414                 lea    edx,[esp+0x14]
0x4aeae9: b97074fb00               mov    ecx,0xfb7470
0x4aeaee: 897c2414                 mov    DWORD PTR [esp+0x14],edi
0x4aeaf2: e8798f0400               call   0x4f7a70
0x4aeaf7: 0fb65061                 movzx  edx,BYTE PTR [eax+0x61]
0x4aeafb: 8b86f0000000             mov    eax,DWORD PTR [esi+0xf0]
0x4aeb01: 8b4008                   mov    eax,DWORD PTR [eax+0x8]
0x4aeb04: 89961c040000             mov    DWORD PTR [esi+0x41c],edx
0x4aeb0a: 0fb65315                 movzx  edx,BYTE PTR [ebx+0x15]
0x4aeb0e: 8d8ef0000000             lea    ecx,[esi+0xf0]
0x4aeb14: 52                       push   edx
0x4aeb15: ffd0                     call   eax
0x4aeb17: 8b430e                   mov    eax,DWORD PTR [ebx+0xe]
0x4aeb1a: 8b16                     mov    edx,DWORD PTR [esi]
0x4aeb1c: 89869c000000             mov    DWORD PTR [esi+0x9c],eax
0x4aeb22: 0fb64314                 movzx  eax,BYTE PTR [ebx+0x14]
0x4aeb26: 898690000000             mov    DWORD PTR [esi+0x90],eax
0x4aeb2c: 668b43fc                 mov    ax,WORD PTR [ebx-0x4]
0x4aeb30: 66894604                 mov    WORD PTR [esi+0x4],ax
0x4aeb34: 8b423c                   mov    eax,DWORD PTR [edx+0x3c]
0x4aeb37: 57                       push   edi
0x4aeb38: 8bce                     mov    ecx,esi
0x4aeb3a: ffd0                     call   eax
0x4aeb3c: 8b16                     mov    edx,DWORD PTR [esi]
0x4aeb3e: 8b5244                   mov    edx,DWORD PTR [edx+0x44]
0x4aeb41: 6a01                     push   0x1
0x4aeb43: 8d4302                   lea    eax,[ebx+0x2]
0x4aeb46: 50                       push   eax
0x4aeb47: 8bce                     mov    ecx,esi
0x4aeb49: ffd2                     call   edx
0x4aeb4b: 0fb64b12                 movzx  ecx,BYTE PTR [ebx+0x12]
0x4aeb4f: 8b06                     mov    eax,DWORD PTR [esi]
0x4aeb51: 8b5058                   mov    edx,DWORD PTR [eax+0x58]
0x4aeb54: 51                       push   ecx
0x4aeb55: 8bce                     mov    ecx,esi
0x4aeb57: ffd2                     call   edx
0x4aeb59: 8b06                     mov    eax,DWORD PTR [esi]
0x4aeb5b: d9430a                   fld    DWORD PTR [ebx+0xa]
0x4aeb5e: 8b505c                   mov    edx,DWORD PTR [eax+0x5c]
0x4aeb61: 51                       push   ecx
0x4aeb62: 8bce                     mov    ecx,esi
0x4aeb64: d91c24                   fstp   DWORD PTR [esp]
0x4aeb67: ffd2                     call   edx
0x4aeb69: 807b1518                 cmp    BYTE PTR [ebx+0x15],0x18
0x4aeb6d: 7507                     jne    0x4aeb76
0x4aeb6f: c686bc00000001           mov    BYTE PTR [esi+0xbc],0x1
0x4aeb76: 8b06                     mov    eax,DWORD PTR [esi]
0x4aeb78: 8b5030                   mov    edx,DWORD PTR [eax+0x30]
0x4aeb7b: 8bce                     mov    ecx,esi
0x4aeb7d: ffd2                     call   edx
0x4aeb7f: 8a43fc                   mov    al,BYTE PTR [ebx-0x4]
0x4aeb82: 3c01                     cmp    al,0x1
0x4aeb84: 7529                     jne    0x4aebaf
0x4aeb86: 837c242000               cmp    DWORD PTR [esp+0x20],0x0
0x4aeb8b: 7511                     jne    0x4aeb9e
0x4aeb8d: 8b8668030000             mov    eax,DWORD PTR [esi+0x368]
0x4aeb93: 85c0                     test   eax,eax
0x4aeb95: 7407                     je     0x4aeb9e
0x4aeb97: c7402400000000           mov    DWORD PTR [eax+0x24],0x0
0x4aeb9e: 33c0                     xor    eax,eax
0x4aeba0: 807b1304                 cmp    BYTE PTR [ebx+0x13],0x4
0x4aeba4: 0f94c0                   sete   al
0x4aeba7: 898628040000             mov    DWORD PTR [esi+0x428],eax
0x4aebad: eb15                     jmp    0x4aebc4
0x4aebaf: 3c06                     cmp    al,0x6
0x4aebb1: 7511                     jne    0x4aebc4
0x4aebb3: 8b8668030000             mov    eax,DWORD PTR [esi+0x368]
0x4aebb9: 85c0                     test   eax,eax
0x4aebbb: 7407                     je     0x4aebc4
0x4aebbd: c7402400000000           mov    DWORD PTR [eax+0x24],0x0
0x4aebc4: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4aebcb: 752f                     jne    0x4aebfc
0x4aebcd: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4aebd4: c78424500100000d000000   mov    DWORD PTR [esp+0x150],0xd
0x4aebdf: e8ac000300               call   0x4dec90
0x4aebe4: 6830cebc00               push   0xbcce30
0x4aebe9: e82c373e00               call   0x89231a
0x4aebee: 83c404                   add    esp,0x4
0x4aebf1: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4aebfc: 6830b1fa00               push   0xfab130
0x4aec01: 8bc6                     mov    eax,esi
0x4aec03: e828130300               call   0x4dff30
0x4aec08: 837b0e00                 cmp    DWORD PTR [ebx+0xe],0x0
0x4aec0c: 0f8486000000             je     0x4aec98
0x4aec12: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4aec19: 752f                     jne    0x4aec4a
0x4aec1b: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4aec22: c78424500100000e000000   mov    DWORD PTR [esp+0x150],0xe
0x4aec2d: e85e000300               call   0x4dec90
0x4aec32: 6830cebc00               push   0xbcce30
0x4aec37: e8de363e00               call   0x89231a
0x4aec3c: 83c404                   add    esp,0x4
0x4aec3f: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4aec4a: 8b4b0e                   mov    ecx,DWORD PTR [ebx+0xe]
0x4aec4d: 8d542414                 lea    edx,[esp+0x14]
0x4aec51: 894c2414                 mov    DWORD PTR [esp+0x14],ecx
0x4aec55: 52                       push   edx
0x4aec56: 8d442434                 lea    eax,[esp+0x34]
0x4aec5a: b948b1fa00               mov    ecx,0xfab148
0x4aec5f: e85c4c3900               call   0x8438c0
0x4aec64: 8b442430                 mov    eax,DWORD PTR [esp+0x30]
0x4aec68: 3b054cb1fa00             cmp    eax,DWORD PTR ds:0xfab14c
0x4aec6e: 7428                     je     0x4aec98
0x4aec70: 8b4810                   mov    ecx,DWORD PTR [eax+0x10]
0x4aec73: 85c9                     test   ecx,ecx
0x4aec75: 7421                     je     0x4aec98
0x4aec77: 83790400                 cmp    DWORD PTR [ecx+0x4],0x0
0x4aec7b: 751b                     jne    0x4aec98
0x4aec7d: 0fb743fc                 movzx  eax,WORD PTR [ebx-0x4]
0x4aec81: 8bf9                     mov    edi,ecx
0x4aec83: e8c8810100               call   0x4c6e50
0x4aec88: 807e0400                 cmp    BYTE PTR [esi+0x4],0x0
0x4aec8c: 750a                     jne    0x4aec98
0x4aec8e: c7869800000001000000     mov    DWORD PTR [esi+0x98],0x1
0x4aec98: 8a4313                   mov    al,BYTE PTR [ebx+0x13]
0x4aec9b: 3c04                     cmp    al,0x4
0x4aec9d: 755a                     jne    0x4aecf9
0x4aec9f: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4aeca6: 752f                     jne    0x4aecd7
0x4aeca8: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4aecaf: c78424500100000f000000   mov    DWORD PTR [esp+0x150],0xf
0x4aecba: e8d1ff0200               call   0x4dec90
0x4aecbf: 6830cebc00               push   0xbcce30
0x4aecc4: e851363e00               call   0x89231a
0x4aecc9: 83c404                   add    esp,0x4
0x4aeccc: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4aecd7: a134b1fa00               mov    eax,ds:0xfab134
0x4aecdc: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4aece0: 8d7820                   lea    edi,[eax+0x20]
0x4aece3: 8d43fc                   lea    eax,[ebx-0x4]
0x4aece6: e8b5f00800               call   0x53dda0
0x4aeceb: 668b43fc                 mov    ax,WORD PTR [ebx-0x4]
0x4aecef: 8b4c2414                 mov    ecx,DWORD PTR [esp+0x14]
0x4aecf3: 66894130                 mov    WORD PTR [ecx+0x30],ax
0x4aecf7: eb49                     jmp    0x4aed42
0x4aecf9: 3c06                     cmp    al,0x6
0x4aecfb: 7545                     jne    0x4aed42
0x4aecfd: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4aed04: 752f                     jne    0x4aed35
0x4aed06: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4aed0d: c784245001000010000000   mov    DWORD PTR [esp+0x150],0x10
0x4aed18: e873ff0200               call   0x4dec90
0x4aed1d: 6830cebc00               push   0xbcce30
0x4aed22: e8f3353e00               call   0x89231a
0x4aed27: 83c404                   add    esp,0x4
0x4aed2a: c7842450010000ffffffff   mov    DWORD PTR [esp+0x150],0xffffffff
0x4aed35: 668b53fc                 mov    dx,WORD PTR [ebx-0x4]
0x4aed39: a134b1fa00               mov    eax,ds:0xfab134
0x4aed3e: 66895032                 mov    WORD PTR [eax+0x32],dx
0x4aed42: 8b442424                 mov    eax,DWORD PTR [esp+0x24]
0x4aed46: 40                       inc    eax
0x4aed47: 83c31a                   add    ebx,0x1a
0x4aed4a: 89442424                 mov    DWORD PTR [esp+0x24],eax
0x4aed4e: 3b442428                 cmp    eax,DWORD PTR [esp+0x28]
0x4aed52: 0f82f8f7ffff             jb     0x4ae550
0x4aed58: b800010000               mov    eax,0x100
0x4aed5d: 8b8c2448010000           mov    ecx,DWORD PTR [esp+0x148]
0x4aed64: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4aed6b: 59                       pop    ecx
0x4aed6c: 5f                       pop    edi
0x4aed6d: 5e                       pop    esi
0x4aed6e: 5b                       pop    ebx
0x4aed6f: 8b8c2430010000           mov    ecx,DWORD PTR [esp+0x130]
0x4aed76: 33cc                     xor    ecx,esp
0x4aed78: e884223e00               call   0x891001
0x4aed7d: 8be5                     mov    esp,ebp
0x4aed7f: 5d                       pop    ebp
0x4aed80: c20c00                   ret    0xc
0x4aed83: 68c069c000               push   0xc069c0
0x4aed88: e8e3ee2300               call   0x6edc70

; B05 CMonster model/bar init and variant spawn effects
; VA [0x4d1910,0x4d1ad8) SHA256 99dbd12f1cc431c104633738a02ec1c6b9e311546c5407fa08021b13f5044898
0x4d1910: 55                       push   ebp
0x4d1911: 8bec                     mov    ebp,esp
0x4d1913: 6aff                     push   0xffffffff
0x4d1915: 68b89d9300               push   0x939db8
0x4d191a: 64a100000000             mov    eax,fs:0x0
0x4d1920: 50                       push   eax
0x4d1921: 83ec1c                   sub    esp,0x1c
0x4d1924: 53                       push   ebx
0x4d1925: 56                       push   esi
0x4d1926: 57                       push   edi
0x4d1927: a1201fd600               mov    eax,ds:0xd61f20
0x4d192c: 33c5                     xor    eax,ebp
0x4d192e: 50                       push   eax
0x4d192f: 8d45f4                   lea    eax,[ebp-0xc]
0x4d1932: 64a300000000             mov    fs:0x0,eax
0x4d1938: 8bf1                     mov    esi,ecx
0x4d193a: 33ff                     xor    edi,edi
0x4d193c: 57                       push   edi
0x4d193d: 56                       push   esi
0x4d193e: e8ad64ffff               call   0x4c7df0
0x4d1943: 8945ec                   mov    DWORD PTR [ebp-0x14],eax
0x4d1946: 8b06                     mov    eax,DWORD PTR [esi]
0x4d1948: 8b5064                   mov    edx,DWORD PTR [eax+0x64]
0x4d194b: 8bce                     mov    ecx,esi
0x4d194d: ffd2                     call   edx
0x4d194f: 8b8624040000             mov    eax,DWORD PTR [esi+0x424]
0x4d1955: bb01000000               mov    ebx,0x1
0x4d195a: 2bc3                     sub    eax,ebx
0x4d195c: 0f8496000000             je     0x4d19f8
0x4d1962: b902000000               mov    ecx,0x2
0x4d1967: 2bc1                     sub    eax,ecx
0x4d1969: 7467                     je     0x4d19d2
0x4d196b: 2bc1                     sub    eax,ecx
0x4d196d: 0f85f0000000             jne    0x4d1a63
0x4d1973: 897dd8                   mov    DWORD PTR [ebp-0x28],edi
0x4d1976: c745dc386ac000           mov    DWORD PTR [ebp-0x24],0xc06a38
0x4d197d: 897de0                   mov    DWORD PTR [ebp-0x20],edi
0x4d1980: 895de4                   mov    DWORD PTR [ebp-0x1c],ebx
0x4d1983: 897de8                   mov    DWORD PTR [ebp-0x18],edi
0x4d1986: 841ddcf6fd00             test   BYTE PTR ds:0xfdf6dc,bl
0x4d198c: 7522                     jne    0x4d19b0
0x4d198e: 091ddcf6fd00             or     DWORD PTR ds:0xfdf6dc,ebx
0x4d1994: 894dfc                   mov    DWORD PTR [ebp-0x4],ecx
0x4d1997: e884ee0700               call   0x550820
0x4d199c: 68b0e6bc00               push   0xbce6b0
0x4d19a1: e874093c00               call   0x89231a
0x4d19a6: 83c404                   add    esp,0x4
0x4d19a9: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x4d19b0: d9e8                     fld1
0x4d19b2: 8b06                     mov    eax,DWORD PTR [esi]
0x4d19b4: 8b504c                   mov    edx,DWORD PTR [eax+0x4c]
0x4d19b7: 83ec08                   sub    esp,0x8
0x4d19ba: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4d19be: 8bce                     mov    ecx,esi
0x4d19c0: d9ee                     fldz
0x4d19c2: d91c24                   fstp   DWORD PTR [esp]
0x4d19c5: ffd2                     call   edx
0x4d19c7: 50                       push   eax
0x4d19c8: 0fb74604                 movzx  eax,WORD PTR [esi+0x4]
0x4d19cc: 50                       push   eax
0x4d19cd: e984000000               jmp    0x4d1a56
0x4d19d2: 897dd8                   mov    DWORD PTR [ebp-0x28],edi
0x4d19d5: c745dc386ac000           mov    DWORD PTR [ebp-0x24],0xc06a38
0x4d19dc: 897de0                   mov    DWORD PTR [ebp-0x20],edi
0x4d19df: 894de4                   mov    DWORD PTR [ebp-0x1c],ecx
0x4d19e2: 897de8                   mov    DWORD PTR [ebp-0x18],edi
0x4d19e5: 841ddcf6fd00             test   BYTE PTR ds:0xfdf6dc,bl
0x4d19eb: 754c                     jne    0x4d1a39
0x4d19ed: 091ddcf6fd00             or     DWORD PTR ds:0xfdf6dc,ebx
0x4d19f3: 895dfc                   mov    DWORD PTR [ebp-0x4],ebx
0x4d19f6: eb28                     jmp    0x4d1a20
0x4d19f8: 897dd8                   mov    DWORD PTR [ebp-0x28],edi
0x4d19fb: c745dc386ac000           mov    DWORD PTR [ebp-0x24],0xc06a38
0x4d1a02: 897de0                   mov    DWORD PTR [ebp-0x20],edi
0x4d1a05: c745e402000000           mov    DWORD PTR [ebp-0x1c],0x2
0x4d1a0c: 897de8                   mov    DWORD PTR [ebp-0x18],edi
0x4d1a0f: 841ddcf6fd00             test   BYTE PTR ds:0xfdf6dc,bl
0x4d1a15: 7522                     jne    0x4d1a39
0x4d1a17: 091ddcf6fd00             or     DWORD PTR ds:0xfdf6dc,ebx
0x4d1a1d: 897dfc                   mov    DWORD PTR [ebp-0x4],edi
0x4d1a20: e8fbed0700               call   0x550820
0x4d1a25: 68b0e6bc00               push   0xbce6b0
0x4d1a2a: e8eb083c00               call   0x89231a
0x4d1a2f: 83c404                   add    esp,0x4
0x4d1a32: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x4d1a39: d9e8                     fld1
0x4d1a3b: 8b16                     mov    edx,DWORD PTR [esi]
0x4d1a3d: 8b424c                   mov    eax,DWORD PTR [edx+0x4c]
0x4d1a40: 83ec08                   sub    esp,0x8
0x4d1a43: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4d1a47: 8bce                     mov    ecx,esi
0x4d1a49: d9ee                     fldz
0x4d1a4b: d91c24                   fstp   DWORD PTR [esp]
0x4d1a4e: ffd0                     call   eax
0x4d1a50: 0fb74e04                 movzx  ecx,WORD PTR [esi+0x4]
0x4d1a54: 50                       push   eax
0x4d1a55: 51                       push   ecx
0x4d1a56: 8d55d8                   lea    edx,[ebp-0x28]
0x4d1a59: b980f6fd00               mov    ecx,0xfdf680
0x4d1a5e: e8bd040800               call   0x551f20
0x4d1a63: 841db075fb00             test   BYTE PTR ds:0xfb75b0,bl
0x4d1a69: 7526                     jne    0x4d1a91
0x4d1a6b: 091db075fb00             or     DWORD PTR ds:0xfb75b0,ebx
0x4d1a71: c745fc03000000           mov    DWORD PTR [ebp-0x4],0x3
0x4d1a78: e803230200               call   0x4f3d80
0x4d1a7d: 68e0d1bc00               push   0xbcd1e0
0x4d1a82: e893083c00               call   0x89231a
0x4d1a87: 83c404                   add    esp,0x4
0x4d1a8a: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x4d1a91: 8b9688000000             mov    edx,DWORD PTR [esi+0x88]
0x4d1a97: 8955f0                   mov    DWORD PTR [ebp-0x10],edx
0x4d1a9a: 8d55f0                   lea    edx,[ebp-0x10]
0x4d1a9d: b97074fb00               mov    ecx,0xfb7470
0x4d1aa2: e8c95f0200               call   0x4f7a70
0x4d1aa7: 83c01c                   add    eax,0x1c
0x4d1aaa: 83781408                 cmp    DWORD PTR [eax+0x14],0x8
0x4d1aae: 7202                     jb     0x4d1ab2
0x4d1ab0: 8b00                     mov    eax,DWORD PTR [eax]
0x4d1ab2: 50                       push   eax
0x4d1ab3: 6860c9c000               push   0xc0c960
0x4d1ab8: 8d5606                   lea    edx,[esi+0x6]
0x4d1abb: e820fcffff               call   0x4d16e0
0x4d1ac0: 8b45ec                   mov    eax,DWORD PTR [ebp-0x14]
0x4d1ac3: 83c408                   add    esp,0x8
0x4d1ac6: 8b4df4                   mov    ecx,DWORD PTR [ebp-0xc]
0x4d1ac9: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4d1ad0: 59                       pop    ecx
0x4d1ad1: 5f                       pop    edi
0x4d1ad2: 5e                       pop    esi
0x4d1ad3: 5b                       pop    ebx
0x4d1ad4: 8be5                     mov    esp,ebp
0x4d1ad6: 5d                       pop    ebp
0x4d1ad7: c3                       ret

; B06 CMonster relation/variant bar style; visual consumer
; VA [0x4d1f90,0x4d2102) SHA256 2a093cfd4b149fed616c1fadde474df4b493a26afdf5fb129db437808993696e
0x4d1f90: 55                       push   ebp
0x4d1f91: 8bec                     mov    ebp,esp
0x4d1f93: 83e4f8                   and    esp,0xfffffff8
0x4d1f96: 6aff                     push   0xffffffff
0x4d1f98: 68deed9300               push   0x93edde
0x4d1f9d: 64a100000000             mov    eax,fs:0x0
0x4d1fa3: 50                       push   eax
0x4d1fa4: 83ec14                   sub    esp,0x14
0x4d1fa7: 53                       push   ebx
0x4d1fa8: 56                       push   esi
0x4d1fa9: a1201fd600               mov    eax,ds:0xd61f20
0x4d1fae: 33c4                     xor    eax,esp
0x4d1fb0: 50                       push   eax
0x4d1fb1: 8d442420                 lea    eax,[esp+0x20]
0x4d1fb5: 64a300000000             mov    fs:0x0,eax
0x4d1fbb: 8bf1                     mov    esi,ecx
0x4d1fbd: 56                       push   esi
0x4d1fbe: e8bd75ffff               call   0x4c9580
0x4d1fc3: 33db                     xor    ebx,ebx
0x4d1fc5: 83f810                   cmp    eax,0x10
0x4d1fc8: 7566                     jne    0x4d2030
0x4d1fca: b801000000               mov    eax,0x1
0x4d1fcf: 84059043f900             test   BYTE PTR ds:0xf94390,al
0x4d1fd5: 7524                     jne    0x4d1ffb
0x4d1fd7: 09059043f900             or     DWORD PTR ds:0xf94390,eax
0x4d1fdd: 895c2428                 mov    DWORD PTR [esp+0x28],ebx
0x4d1fe1: e8aaf50000               call   0x4e1590
0x4d1fe6: 6880ccbc00               push   0xbccc80
0x4d1feb: e82a033c00               call   0x89231a
0x4d1ff0: 83c404                   add    esp,0x4
0x4d1ff3: c7442428ffffffff         mov    DWORD PTR [esp+0x28],0xffffffff
0x4d1ffb: a13039f900               mov    eax,ds:0xf93930
0x4d2000: 3b869c000000             cmp    eax,DWORD PTR [esi+0x9c]
0x4d2006: 8b8668030000             mov    eax,DWORD PTR [esi+0x368]
0x4d200c: 752d                     jne    0x4d203b
0x4d200e: 3bc3                     cmp    eax,ebx
0x4d2010: 0f84cd000000             je     0x4d20e3
0x4d2016: 50                       push   eax
0x4d2017: 8d442414                 lea    eax,[esp+0x14]
0x4d201b: 885c2414                 mov    BYTE PTR [esp+0x14],bl
0x4d201f: e8ac2e2e00               call   0x7b4ed0
0x4d2024: c7400404000000           mov    DWORD PTR [eax+0x4],0x4
0x4d202b: e9b3000000               jmp    0x4d20e3
0x4d2030: 83f811                   cmp    eax,0x11
0x4d2033: 7528                     jne    0x4d205d
0x4d2035: 8b8668030000             mov    eax,DWORD PTR [esi+0x368]
0x4d203b: 3bc3                     cmp    eax,ebx
0x4d203d: 0f84a0000000             je     0x4d20e3
0x4d2043: 50                       push   eax
0x4d2044: 8d442414                 lea    eax,[esp+0x14]
0x4d2048: 885c2414                 mov    BYTE PTR [esp+0x14],bl
0x4d204c: e87f2e2e00               call   0x7b4ed0
0x4d2051: c7400402000000           mov    DWORD PTR [eax+0x4],0x2
0x4d2058: e986000000               jmp    0x4d20e3
0x4d205d: 83f812                   cmp    eax,0x12
0x4d2060: 7562                     jne    0x4d20c4
0x4d2062: 8b8624040000             mov    eax,DWORD PTR [esi+0x424]
0x4d2068: 83e803                   sub    eax,0x3
0x4d206b: 744c                     je     0x4d20b9
0x4d206d: 48                       dec    eax
0x4d206e: 740b                     je     0x4d207b
0x4d2070: 6a05                     push   0x5
0x4d2072: 8bc6                     mov    eax,esi
0x4d2074: e8d763ffff               call   0x4c8450
0x4d2079: eb68                     jmp    0x4d20e3
0x4d207b: 8b8668030000             mov    eax,DWORD PTR [esi+0x368]
0x4d2081: 3bc3                     cmp    eax,ebx
0x4d2083: 742a                     je     0x4d20af
0x4d2085: f30f1005b058c500         movss  xmm0,DWORD PTR ds:0xc558b0
0x4d208d: f30f11442414             movss  DWORD PTR [esp+0x14],xmm0
0x4d2093: f30f1005c056c500         movss  xmm0,DWORD PTR ds:0xc556c0
0x4d209b: 8b4c2414                 mov    ecx,DWORD PTR [esp+0x14]
0x4d209f: f30f11442418             movss  DWORD PTR [esp+0x18],xmm0
0x4d20a5: 8b542418                 mov    edx,DWORD PTR [esp+0x18]
0x4d20a9: 89481c                   mov    DWORD PTR [eax+0x1c],ecx
0x4d20ac: 895020                   mov    DWORD PTR [eax+0x20],edx
0x4d20af: 53                       push   ebx
0x4d20b0: 8bc6                     mov    eax,esi
0x4d20b2: e89963ffff               call   0x4c8450
0x4d20b7: eb2a                     jmp    0x4d20e3
0x4d20b9: 6a06                     push   0x6
0x4d20bb: 8bc6                     mov    eax,esi
0x4d20bd: e88e63ffff               call   0x4c8450
0x4d20c2: eb1f                     jmp    0x4d20e3
0x4d20c4: 8b8668030000             mov    eax,DWORD PTR [esi+0x368]
0x4d20ca: 3bc3                     cmp    eax,ebx
0x4d20cc: 7415                     je     0x4d20e3
0x4d20ce: 50                       push   eax
0x4d20cf: 8d442414                 lea    eax,[esp+0x14]
0x4d20d3: 885c2414                 mov    BYTE PTR [esp+0x14],bl
0x4d20d7: e8f42d2e00               call   0x7b4ed0
0x4d20dc: c7400407000000           mov    DWORD PTR [eax+0x4],0x7
0x4d20e3: 8bb668030000             mov    esi,DWORD PTR [esi+0x368]
0x4d20e9: 3bf3                     cmp    esi,ebx
0x4d20eb: 7403                     je     0x4d20f0
0x4d20ed: 895e28                   mov    DWORD PTR [esi+0x28],ebx
0x4d20f0: 8b4c2420                 mov    ecx,DWORD PTR [esp+0x20]
0x4d20f4: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4d20fb: 59                       pop    ecx
0x4d20fc: 5e                       pop    esi
0x4d20fd: 5b                       pop    ebx
0x4d20fe: 8be5                     mov    esp,ebp
0x4d2100: 5d                       pop    ebp
0x4d2101: c3                       ret

; B07 Relation bitmask resolver; no target choice
; VA [0x4c6f60,0x4c6fb0) SHA256 4e85d841bea2532075b83d6f4e58dbbe1425833b796de45c359bfc9e10bc85d3
0x4c6f60: 0fb602                   movzx  eax,BYTE PTR [edx]
0x4c6f63: 3bc1                     cmp    eax,ecx
0x4c6f65: 7506                     jne    0x4c6f6d
0x4c6f67: b810000000               mov    eax,0x10
0x4c6f6c: c3                       ret
0x4c6f6d: 83f908                   cmp    ecx,0x8
0x4c6f70: 7329                     jae    0x4c6f9b
0x4c6f72: b801000000               mov    eax,0x1
0x4c6f77: d3e0                     shl    eax,cl
0x4c6f79: 844201                   test   BYTE PTR [edx+0x1],al
0x4c6f7c: 7413                     je     0x4c6f91
0x4c6f7e: 8a4a02                   mov    cl,BYTE PTR [edx+0x2]
0x4c6f81: 22c8                     and    cl,al
0x4c6f83: 0fbec1                   movsx  eax,cl
0x4c6f86: f7d8                     neg    eax
0x4c6f88: 1bc0                     sbb    eax,eax
0x4c6f8a: 83e06e                   and    eax,0x6e
0x4c6f8d: 83c011                   add    eax,0x11
0x4c6f90: c3                       ret
0x4c6f91: 844202                   test   BYTE PTR [edx+0x2],al
0x4c6f94: b812000000               mov    eax,0x12
0x4c6f99: 7505                     jne    0x4c6fa0
0x4c6f9b: b87f000000               mov    eax,0x7f
0x4c6fa0: c3                       ret
0x4c6fa1: cc                       int3
0x4c6fa2: cc                       int3
0x4c6fa3: cc                       int3
0x4c6fa4: cc                       int3
0x4c6fa5: cc                       int3
0x4c6fa6: cc                       int3
0x4c6fa7: cc                       int3
0x4c6fa8: cc                       int3
0x4c6fa9: cc                       int3
0x4c6faa: cc                       int3
0x4c6fab: cc                       int3
0x4c6fac: cc                       int3
0x4c6fad: cc                       int3
0x4c6fae: cc                       int3
0x4c6faf: cc                       int3

; B08 Leader/object group relation lookup; no hostile-instance producer
; VA [0x4c9580,0x4c96b0) SHA256 a780c3b964004cd36c1311a423e97879e29ed8813fdf8751395a2db6e7439212
0x4c9580: 55                       push   ebp
0x4c9581: 8bec                     mov    ebp,esp
0x4c9583: 83e4f8                   and    esp,0xfffffff8
0x4c9586: 6aff                     push   0xffffffff
0x4c9588: 689c6a9300               push   0x936a9c
0x4c958d: 64a100000000             mov    eax,fs:0x0
0x4c9593: 50                       push   eax
0x4c9594: 83ec08                   sub    esp,0x8
0x4c9597: 53                       push   ebx
0x4c9598: 56                       push   esi
0x4c9599: 57                       push   edi
0x4c959a: a1201fd600               mov    eax,ds:0xd61f20
0x4c959f: 33c4                     xor    eax,esp
0x4c95a1: 50                       push   eax
0x4c95a2: 8d442418                 lea    eax,[esp+0x18]
0x4c95a6: 64a300000000             mov    fs:0x0,eax
0x4c95ac: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4c95b2: 8b01                     mov    eax,DWORD PTR [ecx]
0x4c95b4: 8b5020                   mov    edx,DWORD PTR [eax+0x20]
0x4c95b7: ffd2                     call   edx
0x4c95b9: 8bd8                     mov    ebx,eax
0x4c95bb: 33ff                     xor    edi,edi
0x4c95bd: 3bdf                     cmp    ebx,edi
0x4c95bf: 0f84cd000000             je     0x4c9692
0x4c95c5: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4c95cc: 8bb390000000             mov    esi,DWORD PTR [ebx+0x90]
0x4c95d2: 7525                     jne    0x4c95f9
0x4c95d4: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4c95db: 897c2420                 mov    DWORD PTR [esp+0x20],edi
0x4c95df: e8ac560100               call   0x4dec90
0x4c95e4: 6830cebc00               push   0xbcce30
0x4c95e9: e82c8d3c00               call   0x89231a
0x4c95ee: 83c404                   add    esp,0x4
0x4c95f1: c7442420ffffffff         mov    DWORD PTR [esp+0x20],0xffffffff
0x4c95f9: 8bc6                     mov    eax,esi
0x4c95fb: 99                       cdq
0x4c95fc: 83e207                   and    edx,0x7
0x4c95ff: 03c2                     add    eax,edx
0x4c9601: c1f803                   sar    eax,0x3
0x4c9604: 85c0                     test   eax,eax
0x4c9606: 7507                     jne    0x4c960f
0x4c9608: 8dbc76e8b1fa00           lea    edi,[esi+esi*2+0xfab1e8]
0x4c960f: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4c9616: 7521                     jne    0x4c9639
0x4c9618: b801000000               mov    eax,0x1
0x4c961d: 09052cb2fa00             or     DWORD PTR ds:0xfab22c,eax
0x4c9623: 89442420                 mov    DWORD PTR [esp+0x20],eax
0x4c9627: e864560100               call   0x4dec90
0x4c962c: 6830cebc00               push   0xbcce30
0x4c9631: e8e48c3c00               call   0x89231a
0x4c9636: 83c404                   add    esp,0x4
0x4c9639: 8b4508                   mov    eax,DWORD PTR [ebp+0x8]
0x4c963c: 8b8890000000             mov    ecx,DWORD PTR [eax+0x90]
0x4c9642: 8bc1                     mov    eax,ecx
0x4c9644: 99                       cdq
0x4c9645: 83e207                   and    edx,0x7
0x4c9648: 03c2                     add    eax,edx
0x4c964a: c1f803                   sar    eax,0x3
0x4c964d: 85c0                     test   eax,eax
0x4c964f: 7404                     je     0x4c9655
0x4c9651: 33f6                     xor    esi,esi
0x4c9653: eb07                     jmp    0x4c965c
0x4c9655: 8db449e8b1fa00           lea    esi,[ecx+ecx*2+0xfab1e8]
0x4c965c: 85ff                     test   edi,edi
0x4c965e: 7432                     je     0x4c9692
0x4c9660: 85f6                     test   esi,esi
0x4c9662: 742e                     je     0x4c9692
0x4c9664: 8bd7                     mov    edx,edi
0x4c9666: e8f5d8ffff               call   0x4c6f60
0x4c966b: 83f87f                   cmp    eax,0x7f
0x4c966e: 7527                     jne    0x4c9697
0x4c9670: 8b8b90000000             mov    ecx,DWORD PTR [ebx+0x90]
0x4c9676: 8bd6                     mov    edx,esi
0x4c9678: e8e3d8ffff               call   0x4c6f60
0x4c967d: 8b4c2418                 mov    ecx,DWORD PTR [esp+0x18]
0x4c9681: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4c9688: 59                       pop    ecx
0x4c9689: 5f                       pop    edi
0x4c968a: 5e                       pop    esi
0x4c968b: 5b                       pop    ebx
0x4c968c: 8be5                     mov    esp,ebp
0x4c968e: 5d                       pop    ebp
0x4c968f: c20400                   ret    0x4
0x4c9692: b87f000000               mov    eax,0x7f
0x4c9697: 8b4c2418                 mov    ecx,DWORD PTR [esp+0x18]
0x4c969b: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4c96a2: 59                       pop    ecx
0x4c96a3: 5f                       pop    edi
0x4c96a4: 5e                       pop    esi
0x4c96a5: 5b                       pop    ebx
0x4c96a6: 8be5                     mov    esp,ebp
0x4c96a8: 5d                       pop    ebp
0x4c96a9: c20400                   ret    0x4
0x4c96ac: cc                       int3
0x4c96ad: cc                       int3
0x4c96ae: cc                       int3
0x4c96af: cc                       int3

; B09 Common handler map +0x4a4 = 0x0094*8+4 registers 4AF1F0
; VA [0x4adfcd,0x4adfd7) SHA256 b980abfb5b5498d6c8571e95dcebcbf80a24bc154867c40bb592fa93a50bd1ae
0x4adfcd: c780a4040000f0f14a00     mov    DWORD PTR [eax+0x4a4],0x4af1f0

; B10 0094 complete 24-byte row creation consumer
; VA [0x4af1f0,0x4af52e) SHA256 bdb7bc2f76831ec5aa8f3b898fc9a47eeb3b27756a20ef28ef26125749beb189
0x4af1f0: 55                       push   ebp
0x4af1f1: 8bec                     mov    ebp,esp
0x4af1f3: 83e4f8                   and    esp,0xfffffff8
0x4af1f6: 6aff                     push   0xffffffff
0x4af1f8: 686a6e9300               push   0x936e6a
0x4af1fd: 64a100000000             mov    eax,fs:0x0
0x4af203: 50                       push   eax
0x4af204: 83ec38                   sub    esp,0x38
0x4af207: a1201fd600               mov    eax,ds:0xd61f20
0x4af20c: 33c4                     xor    eax,esp
0x4af20e: 89442430                 mov    DWORD PTR [esp+0x30],eax
0x4af212: 53                       push   ebx
0x4af213: 56                       push   esi
0x4af214: 57                       push   edi
0x4af215: a1201fd600               mov    eax,ds:0xd61f20
0x4af21a: 33c4                     xor    eax,esp
0x4af21c: 50                       push   eax
0x4af21d: 8d442448                 lea    eax,[esp+0x48]
0x4af221: 64a300000000             mov    fs:0x0,eax
0x4af227: 8b450c                   mov    eax,DWORD PTR [ebp+0xc]
0x4af22a: 8b7d08                   mov    edi,DWORD PTR [ebp+0x8]
0x4af22d: 83f802                   cmp    eax,0x2
0x4af230: 7304                     jae    0x4af236
0x4af232: 33d2                     xor    edx,edx
0x4af234: eb0d                     jmp    0x4af243
0x4af236: 8d48fe                   lea    ecx,[eax-0x2]
0x4af239: b8abaaaaaa               mov    eax,0xaaaaaaab
0x4af23e: f7e1                     mul    ecx
0x4af240: c1ea04                   shr    edx,0x4
0x4af243: 85d2                     test   edx,edx
0x4af245: 0f84be020000             je     0x4af509
0x4af24b: 83c704                   add    edi,0x4
0x4af24e: 89542418                 mov    DWORD PTR [esp+0x18],edx
0x4af252: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4af259: 7529                     jne    0x4af284
0x4af25b: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4af262: c744245000000000         mov    DWORD PTR [esp+0x50],0x0
0x4af26a: e821fa0200               call   0x4dec90
0x4af26f: 6830cebc00               push   0xbcce30
0x4af274: e8a1303e00               call   0x89231a
0x4af279: 83c404                   add    esp,0x4
0x4af27c: c7442450ffffffff         mov    DWORD PTR [esp+0x50],0xffffffff
0x4af284: 0fb717                   movzx  edx,WORD PTR [edi]
0x4af287: 8d442414                 lea    eax,[esp+0x14]
0x4af28b: 50                       push   eax
0x4af28c: 8d442434                 lea    eax,[esp+0x34]
0x4af290: b938b1fa00               mov    ecx,0xfab138
0x4af295: 89542418                 mov    DWORD PTR [esp+0x18],edx
0x4af299: e862fc3700               call   0x82ef00
0x4af29e: 8b0d3cb1fa00             mov    ecx,DWORD PTR ds:0xfab13c
0x4af2a4: 3908                     cmp    DWORD PTR [eax],ecx
0x4af2a6: 0f8550020000             jne    0x4af4fc
0x4af2ac: 0fb75f04                 movzx  ebx,WORD PTR [edi+0x4]
0x4af2b0: 6838010000               push   0x138
0x4af2b5: 81cb00000002             or     ebx,0x2000000
0x4af2bb: e8a81f3e00               call   0x891268
0x4af2c0: 83c404                   add    esp,0x4
0x4af2c3: 85c0                     test   eax,eax
0x4af2c5: 740e                     je     0x4af2d5
0x4af2c7: 0fb75702                 movzx  edx,WORD PTR [edi+0x2]
0x4af2cb: 52                       push   edx
0x4af2cc: e81fcd0100               call   0x4cbff0
0x4af2d1: 8bf0                     mov    esi,eax
0x4af2d3: eb02                     jmp    0x4af2d7
0x4af2d5: 33f6                     xor    esi,esi
0x4af2d7: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4af2de: 7529                     jne    0x4af309
0x4af2e0: b801000000               mov    eax,0x1
0x4af2e5: 09052cb2fa00             or     DWORD PTR ds:0xfab22c,eax
0x4af2eb: 89442450                 mov    DWORD PTR [esp+0x50],eax
0x4af2ef: e89cf90200               call   0x4dec90
0x4af2f4: 6830cebc00               push   0xbcce30
0x4af2f9: e81c303e00               call   0x89231a
0x4af2fe: 83c404                   add    esp,0x4
0x4af301: c7442450ffffffff         mov    DWORD PTR [esp+0x50],0xffffffff
0x4af309: 0fb747fe                 movzx  eax,WORD PTR [edi-0x2]
0x4af30d: 8d4c2414                 lea    ecx,[esp+0x14]
0x4af311: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4af315: 51                       push   ecx
0x4af316: 8d442428                 lea    eax,[esp+0x28]
0x4af31a: b938b1fa00               mov    ecx,0xfab138
0x4af31f: e8dcfb3700               call   0x82ef00
0x4af324: 8b442424                 mov    eax,DWORD PTR [esp+0x24]
0x4af328: 3b053cb1fa00             cmp    eax,DWORD PTR ds:0xfab13c
0x4af32e: 0f84c8010000             je     0x4af4fc
0x4af334: 8b4010                   mov    eax,DWORD PTR [eax+0x10]
0x4af337: 85c0                     test   eax,eax
0x4af339: 0f84bd010000             je     0x4af4fc
0x4af33f: 8b889c000000             mov    ecx,DWORD PTR [eax+0x9c]
0x4af345: 8b16                     mov    edx,DWORD PTR [esi]
0x4af347: 898e9c000000             mov    DWORD PTR [esi+0x9c],ecx
0x4af34d: 8b8090000000             mov    eax,DWORD PTR [eax+0x90]
0x4af353: 898690000000             mov    DWORD PTR [esi+0x90],eax
0x4af359: 668b07                   mov    ax,WORD PTR [edi]
0x4af35c: 66894604                 mov    WORD PTR [esi+0x4],ax
0x4af360: 8b423c                   mov    eax,DWORD PTR [edx+0x3c]
0x4af363: 53                       push   ebx
0x4af364: 8bce                     mov    ecx,esi
0x4af366: ffd0                     call   eax
0x4af368: 8a4711                   mov    al,BYTE PTR [edi+0x11]
0x4af36b: 3c01                     cmp    al,0x1
0x4af36d: 7521                     jne    0x4af390
0x4af36f: 0fb74712                 movzx  eax,WORD PTR [edi+0x12]
0x4af373: c786f400000001000000     mov    DWORD PTR [esi+0xf4],0x1
0x4af37d: c786f800000000000000     mov    DWORD PTR [esi+0xf8],0x0
0x4af387: 66898628010000           mov    WORD PTR [esi+0x128],ax
0x4af38e: eb3b                     jmp    0x4af3cb
0x4af390: 3c02                     cmp    al,0x2
0x4af392: 7537                     jne    0x4af3cb
0x4af394: 0fb74f12                 movzx  ecx,WORD PTR [edi+0x12]
0x4af398: 0fb75714                 movzx  edx,WORD PTR [edi+0x14]
0x4af39c: b801000000               mov    eax,0x1
0x4af3a1: 0f57c0                   xorps  xmm0,xmm0
0x4af3a4: 0f57c9                   xorps  xmm1,xmm1
0x4af3a7: f30f2ac1                 cvtsi2ss xmm0,ecx
0x4af3ab: f30f2aca                 cvtsi2ss xmm1,edx
0x4af3af: 8986f4000000             mov    DWORD PTR [esi+0xf4],eax
0x4af3b5: 8986f8000000             mov    DWORD PTR [esi+0xf8],eax
0x4af3bb: f30f118628010000         movss  DWORD PTR [esi+0x128],xmm0
0x4af3c3: f30f118e2c010000         movss  DWORD PTR [esi+0x12c],xmm1
0x4af3cb: 0fbf4706                 movsx  eax,WORD PTR [edi+0x6]
0x4af3cf: 0fbf4f08                 movsx  ecx,WORD PTR [edi+0x8]
0x4af3d3: 8b16                     mov    edx,DWORD PTR [esi]
0x4af3d5: 8b5244                   mov    edx,DWORD PTR [edx+0x44]
0x4af3d8: 0f57c0                   xorps  xmm0,xmm0
0x4af3db: f30f2ac0                 cvtsi2ss xmm0,eax
0x4af3df: 0f57c9                   xorps  xmm1,xmm1
0x4af3e2: f30f2ac9                 cvtsi2ss xmm1,ecx
0x4af3e6: 6a01                     push   0x1
0x4af3e8: 8d44242c                 lea    eax,[esp+0x2c]
0x4af3ec: 50                       push   eax
0x4af3ed: 8bce                     mov    ecx,esi
0x4af3ef: f30f11442430             movss  DWORD PTR [esp+0x30],xmm0
0x4af3f5: f30f114c2434             movss  DWORD PTR [esp+0x34],xmm1
0x4af3fb: ffd2                     call   edx
0x4af3fd: 0fb64f0e                 movzx  ecx,BYTE PTR [edi+0xe]
0x4af401: 8b06                     mov    eax,DWORD PTR [esi]
0x4af403: 8b5058                   mov    edx,DWORD PTR [eax+0x58]
0x4af406: 51                       push   ecx
0x4af407: 8bce                     mov    ecx,esi
0x4af409: ffd2                     call   edx
0x4af40b: 8b06                     mov    eax,DWORD PTR [esi]
0x4af40d: d9470a                   fld    DWORD PTR [edi+0xa]
0x4af410: 8b505c                   mov    edx,DWORD PTR [eax+0x5c]
0x4af413: 51                       push   ecx
0x4af414: 8bce                     mov    ecx,esi
0x4af416: d91c24                   fstp   DWORD PTR [esp]
0x4af419: ffd2                     call   edx
0x4af41b: 0fb7470f                 movzx  eax,WORD PTR [edi+0xf]
0x4af41f: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4af423: 0f57c9                   xorps  xmm1,xmm1
0x4af426: db442414                 fild   DWORD PTR [esp+0x14]
0x4af42a: 6a00                     push   0x0
0x4af42c: 0f57c0                   xorps  xmm0,xmm0
0x4af42f: dc35d857c500             fdiv   QWORD PTR ds:0xc557d8
0x4af435: d95c2418                 fstp   DWORD PTR [esp+0x18]
0x4af439: d9442418                 fld    DWORD PTR [esp+0x18]
0x4af43d: d99e30010000             fstp   DWORD PTR [esi+0x130]
0x4af443: 0fbf5708                 movsx  edx,WORD PTR [edi+0x8]
0x4af447: 0fbf4f06                 movsx  ecx,WORD PTR [edi+0x6]
0x4af44b: f30f2aca                 cvtsi2ss xmm1,edx
0x4af44f: f30f2ac1                 cvtsi2ss xmm0,ecx
0x4af453: 8b0d38a8fb00             mov    ecx,DWORD PTR ds:0xfba838
0x4af459: 8b01                     mov    eax,DWORD PTR [ecx]
0x4af45b: 8b00                     mov    eax,DWORD PTR [eax]
0x4af45d: 8d542440                 lea    edx,[esp+0x40]
0x4af461: f30f114c2420             movss  DWORD PTR [esp+0x20],xmm1
0x4af467: d9442420                 fld    DWORD PTR [esp+0x20]
0x4af46b: 52                       push   edx
0x4af46c: 83ec08                   sub    esp,0x8
0x4af46f: f30f11442430             movss  DWORD PTR [esp+0x30],xmm0
0x4af475: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4af479: d9442430                 fld    DWORD PTR [esp+0x30]
0x4af47d: f30f11442444             movss  DWORD PTR [esp+0x44],xmm0
0x4af483: 0f57c0                   xorps  xmm0,xmm0
0x4af486: d91c24                   fstp   DWORD PTR [esp]
0x4af489: f30f114c2448             movss  DWORD PTR [esp+0x48],xmm1
0x4af48f: f30f1144244c             movss  DWORD PTR [esp+0x4c],xmm0
0x4af495: ffd0                     call   eax
0x4af497: 8b4c2434                 mov    ecx,DWORD PTR [esp+0x34]
0x4af49b: 8b542438                 mov    edx,DWORD PTR [esp+0x38]
0x4af49f: 8b44243c                 mov    eax,DWORD PTR [esp+0x3c]
0x4af4a3: 898e00010000             mov    DWORD PTR [esi+0x100],ecx
0x4af4a9: 899604010000             mov    DWORD PTR [esi+0x104],edx
0x4af4af: 8b16                     mov    edx,DWORD PTR [esi]
0x4af4b1: 898608010000             mov    DWORD PTR [esi+0x108],eax
0x4af4b7: 8b4230                   mov    eax,DWORD PTR [edx+0x30]
0x4af4ba: 8bce                     mov    ecx,esi
0x4af4bc: ffd0                     call   eax
0x4af4be: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4af4c5: 7529                     jne    0x4af4f0
0x4af4c7: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4af4ce: c744245002000000         mov    DWORD PTR [esp+0x50],0x2
0x4af4d6: e8b5f70200               call   0x4dec90
0x4af4db: 6830cebc00               push   0xbcce30
0x4af4e0: e8352e3e00               call   0x89231a
0x4af4e5: 83c404                   add    esp,0x4
0x4af4e8: c7442450ffffffff         mov    DWORD PTR [esp+0x50],0xffffffff
0x4af4f0: 6830b1fa00               push   0xfab130
0x4af4f5: 8bc6                     mov    eax,esi
0x4af4f7: e8340a0300               call   0x4dff30
0x4af4fc: 83c718                   add    edi,0x18
0x4af4ff: ff4c2418                 dec    DWORD PTR [esp+0x18]
0x4af503: 0f8549fdffff             jne    0x4af252
0x4af509: b800010000               mov    eax,0x100
0x4af50e: 8b4c2448                 mov    ecx,DWORD PTR [esp+0x48]
0x4af512: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4af519: 59                       pop    ecx
0x4af51a: 5f                       pop    edi
0x4af51b: 5e                       pop    esi
0x4af51c: 5b                       pop    ebx
0x4af51d: 8b4c2430                 mov    ecx,DWORD PTR [esp+0x30]
0x4af521: 33cc                     xor    ecx,esp
0x4af523: e8d91a3e00               call   0x891001
0x4af528: 8be5                     mov    esp,ebp
0x4af52a: 5d                       pop    ebp
0x4af52b: c20c00                   ret    0xc

; B11 CBullet constructor complete; mode/elapsed/resource initialization
; VA [0x4cbff0,0x4cc0d0) SHA256 6564d955985f3703df9c0a352b4bb52df56cded707c39ceb7a729dc654287908
0x4cbff0: 55                       push   ebp
0x4cbff1: 8bec                     mov    ebp,esp
0x4cbff3: 51                       push   ecx
0x4cbff4: 53                       push   ebx
0x4cbff5: 56                       push   esi
0x4cbff6: 57                       push   edi
0x4cbff7: 8bf0                     mov    esi,eax
0x4cbff9: e832e7ffff               call   0x4ca730
0x4cbffe: 0f57c0                   xorps  xmm0,xmm0
0x4cc001: 8b4508                   mov    eax,DWORD PTR [ebp+0x8]
0x4cc004: 33c9                     xor    ecx,ecx
0x4cc006: 89860c010000             mov    DWORD PTR [esi+0x10c],eax
0x4cc00c: 898ef0000000             mov    DWORD PTR [esi+0xf0],ecx
0x4cc012: c706fc79c000             mov    DWORD PTR [esi],0xc079fc
0x4cc018: 898ef4000000             mov    DWORD PTR [esi+0xf4],ecx
0x4cc01e: 898ef8000000             mov    DWORD PTR [esi+0xf8],ecx
0x4cc024: 898efc000000             mov    DWORD PTR [esi+0xfc],ecx
0x4cc02a: f30f118610010000         movss  DWORD PTR [esi+0x110],xmm0
0x4cc032: f30f118614010000         movss  DWORD PTR [esi+0x114],xmm0
0x4cc03a: f30f118618010000         movss  DWORD PTR [esi+0x118],xmm0
0x4cc042: 0fb79e0c010000           movzx  ebx,WORD PTR [esi+0x10c]
0x4cc049: f30f11861c010000         movss  DWORD PTR [esi+0x11c],xmm0
0x4cc051: 898e20010000             mov    DWORD PTR [esi+0x120],ecx
0x4cc057: 898e24010000             mov    DWORD PTR [esi+0x124],ecx
0x4cc05d: f30f118634010000         movss  DWORD PTR [esi+0x134],xmm0
0x4cc065: 8b15e8aafb00             mov    edx,DWORD PTR ds:0xfbaae8
0x4cc06b: 8b4204                   mov    eax,DWORD PTR [edx+0x4]
0x4cc06e: 8bfa                     mov    edi,edx
0x4cc070: 3888a1000000             cmp    BYTE PTR [eax+0xa1],cl
0x4cc076: 7517                     jne    0x4cc08f
0x4cc078: 6639580c                 cmp    WORD PTR [eax+0xc],bx
0x4cc07c: 7305                     jae    0x4cc083
0x4cc07e: 8b4008                   mov    eax,DWORD PTR [eax+0x8]
0x4cc081: eb04                     jmp    0x4cc087
0x4cc083: 8bf8                     mov    edi,eax
0x4cc085: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc087: 3888a1000000             cmp    BYTE PTR [eax+0xa1],cl
0x4cc08d: 74e9                     je     0x4cc078
0x4cc08f: 897d08                   mov    DWORD PTR [ebp+0x8],edi
0x4cc092: 3bfa                     cmp    edi,edx
0x4cc094: 740b                     je     0x4cc0a1
0x4cc096: 663b5f0c                 cmp    bx,WORD PTR [edi+0xc]
0x4cc09a: 7205                     jb     0x4cc0a1
0x4cc09c: 8d4508                   lea    eax,[ebp+0x8]
0x4cc09f: eb06                     jmp    0x4cc0a7
0x4cc0a1: 8955fc                   mov    DWORD PTR [ebp-0x4],edx
0x4cc0a4: 8d45fc                   lea    eax,[ebp-0x4]
0x4cc0a7: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc0a9: 3bc2                     cmp    eax,edx
0x4cc0ab: 7418                     je     0x4cc0c5
0x4cc0ad: 8b8894000000             mov    ecx,DWORD PTR [eax+0x94]
0x4cc0b3: 898e20010000             mov    DWORD PTR [esi+0x120],ecx
0x4cc0b9: d98090000000             fld    DWORD PTR [eax+0x90]
0x4cc0bf: d99e1c010000             fstp   DWORD PTR [esi+0x11c]
0x4cc0c5: 5f                       pop    edi
0x4cc0c6: 8bc6                     mov    eax,esi
0x4cc0c8: 5e                       pop    esi
0x4cc0c9: 5b                       pop    ebx
0x4cc0ca: 8be5                     mov    esp,ebp
0x4cc0cc: 5d                       pop    ebp
0x4cc0cd: c20400                   ret    0x4

; B12 CBullet v+20 complete; directional or target/coordinate interpolation
; VA [0x4cc150,0x4cc537) SHA256 8e51ef3bd722ec1e9771ebc06ca308ba4a86859a72f8cb2997ec0c701fc1b94c
0x4cc150: 55                       push   ebp
0x4cc151: 8bec                     mov    ebp,esp
0x4cc153: 83e4f8                   and    esp,0xfffffff8
0x4cc156: 6aff                     push   0xffffffff
0x4cc158: 68de699300               push   0x9369de
0x4cc15d: 64a100000000             mov    eax,fs:0x0
0x4cc163: 50                       push   eax
0x4cc164: 83ec54                   sub    esp,0x54
0x4cc167: a1201fd600               mov    eax,ds:0xd61f20
0x4cc16c: 33c4                     xor    eax,esp
0x4cc16e: 8944244c                 mov    DWORD PTR [esp+0x4c],eax
0x4cc172: 53                       push   ebx
0x4cc173: 56                       push   esi
0x4cc174: a1201fd600               mov    eax,ds:0xd61f20
0x4cc179: 33c4                     xor    eax,esp
0x4cc17b: 50                       push   eax
0x4cc17c: 8d442460                 lea    eax,[esp+0x60]
0x4cc180: 64a300000000             mov    fs:0x0,eax
0x4cc186: 8bf1                     mov    esi,ecx
0x4cc188: 83bef400000000           cmp    DWORD PTR [esi+0xf4],0x0
0x4cc18f: 0f8493020000             je     0x4cc428
0x4cc195: 83beac00000000           cmp    DWORD PTR [esi+0xac],0x0
0x4cc19c: 7407                     je     0x4cc1a5
0x4cc19e: 8b06                     mov    eax,DWORD PTR [esi]
0x4cc1a0: 8b5038                   mov    edx,DWORD PTR [eax+0x38]
0x4cc1a3: ffd2                     call   edx
0x4cc1a5: 83be2001000000           cmp    DWORD PTR [esi+0x120],0x0
0x4cc1ac: d98634010000             fld    DWORD PTR [esi+0x134]
0x4cc1b2: d8b630010000             fdiv   DWORD PTR [esi+0x130]
0x4cc1b8: d95c2410                 fstp   DWORD PTR [esp+0x10]
0x4cc1bc: d9442410                 fld    DWORD PTR [esp+0x10]
0x4cc1c0: d9542410                 fst    DWORD PTR [esp+0x10]
0x4cc1c4: 7613                     jbe    0x4cc1d9
0x4cc1c6: 8b8620010000             mov    eax,DWORD PTR [esi+0x120]
0x4cc1cc: 48                       dec    eax
0x4cc1cd: d9442410                 fld    DWORD PTR [esp+0x10]
0x4cc1d1: d8c9                     fmul   st,st(1)
0x4cc1d3: d95c2410                 fstp   DWORD PTR [esp+0x10]
0x4cc1d7: 75f3                     jne    0x4cc1cc
0x4cc1d9: dc0d505ac500             fmul   QWORD PTR ds:0xc55a50
0x4cc1df: d95c2420                 fstp   DWORD PTR [esp+0x20]
0x4cc1e3: d9442420                 fld    DWORD PTR [esp+0x20]
0x4cc1e7: e8b42e4300               call   0x8ff0a0
0x4cc1ec: d95c2420                 fstp   DWORD PTR [esp+0x20]
0x4cc1f0: 83bef800000000           cmp    DWORD PTR [esi+0xf8],0x0
0x4cc1f7: d9442420                 fld    DWORD PTR [esp+0x20]
0x4cc1fb: d95c2420                 fstp   DWORD PTR [esp+0x20]
0x4cc1ff: d9861c010000             fld    DWORD PTR [esi+0x11c]
0x4cc205: d84c2420                 fmul   DWORD PTR [esp+0x20]
0x4cc209: d95c2418                 fstp   DWORD PTR [esp+0x18]
0x4cc20d: 7447                     je     0x4cc256
0x4cc20f: d98628010000             fld    DWORD PTR [esi+0x128]
0x4cc215: 0f57c0                   xorps  xmm0,xmm0
0x4cc218: 8b0d38a8fb00             mov    ecx,DWORD PTR ds:0xfba838
0x4cc21e: d95c2440                 fstp   DWORD PTR [esp+0x40]
0x4cc222: d9862c010000             fld    DWORD PTR [esi+0x12c]
0x4cc228: 6a00                     push   0x0
0x4cc22a: d95c2448                 fstp   DWORD PTR [esp+0x48]
0x4cc22e: 8d54244c                 lea    edx,[esp+0x4c]
0x4cc232: d9442448                 fld    DWORD PTR [esp+0x48]
0x4cc236: 52                       push   edx
0x4cc237: 83ec08                   sub    esp,0x8
0x4cc23a: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4cc23e: f30f11442458             movss  DWORD PTR [esp+0x58],xmm0
0x4cc244: 8b01                     mov    eax,DWORD PTR [ecx]
0x4cc246: d9442450                 fld    DWORD PTR [esp+0x50]
0x4cc24a: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc24c: d91c24                   fstp   DWORD PTR [esp]
0x4cc24f: ffd0                     call   eax
0x4cc251: e9b0000000               jmp    0x4cc306
0x4cc256: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4cc25d: 7529                     jne    0x4cc288
0x4cc25f: 830d2cb2fa0001           or     DWORD PTR ds:0xfab22c,0x1
0x4cc266: c744246800000000         mov    DWORD PTR [esp+0x68],0x0
0x4cc26e: e81d2a0100               call   0x4dec90
0x4cc273: 6830cebc00               push   0xbcce30
0x4cc278: e89d603c00               call   0x89231a
0x4cc27d: 83c404                   add    esp,0x4
0x4cc280: c7442468ffffffff         mov    DWORD PTR [esp+0x68],0xffffffff
0x4cc288: 0fb78e28010000           movzx  ecx,WORD PTR [esi+0x128]
0x4cc28f: 8d542420                 lea    edx,[esp+0x20]
0x4cc293: 894c2420                 mov    DWORD PTR [esp+0x20],ecx
0x4cc297: 52                       push   edx
0x4cc298: 8d442418                 lea    eax,[esp+0x18]
0x4cc29c: b938b1fa00               mov    ecx,0xfab138
0x4cc2a1: e85a2c3600               call   0x82ef00
0x4cc2a6: 8b442414                 mov    eax,DWORD PTR [esp+0x14]
0x4cc2aa: 3b053cb1fa00             cmp    eax,DWORD PTR ds:0xfab13c
0x4cc2b0: 7407                     je     0x4cc2b9
0x4cc2b2: 8b4810                   mov    ecx,DWORD PTR [eax+0x10]
0x4cc2b5: 85c9                     test   ecx,ecx
0x4cc2b7: 7520                     jne    0x4cc2d9
0x4cc2b9: 8b8610010000             mov    eax,DWORD PTR [esi+0x110]
0x4cc2bf: 8b8e14010000             mov    ecx,DWORD PTR [esi+0x114]
0x4cc2c5: 8b9618010000             mov    edx,DWORD PTR [esi+0x118]
0x4cc2cb: 89442440                 mov    DWORD PTR [esp+0x40],eax
0x4cc2cf: 894c2444                 mov    DWORD PTR [esp+0x44],ecx
0x4cc2d3: 89542448                 mov    DWORD PTR [esp+0x48],edx
0x4cc2d7: eb2d                     jmp    0x4cc306
0x4cc2d9: 8b01                     mov    eax,DWORD PTR [ecx]
0x4cc2db: 8b504c                   mov    edx,DWORD PTR [eax+0x4c]
0x4cc2de: ffd2                     call   edx
0x4cc2e0: 8b08                     mov    ecx,DWORD PTR [eax]
0x4cc2e2: 894c2440                 mov    DWORD PTR [esp+0x40],ecx
0x4cc2e6: 8b5004                   mov    edx,DWORD PTR [eax+0x4]
0x4cc2e9: 89542444                 mov    DWORD PTR [esp+0x44],edx
0x4cc2ed: 8b4008                   mov    eax,DWORD PTR [eax+0x8]
0x4cc2f0: 898e10010000             mov    DWORD PTR [esi+0x110],ecx
0x4cc2f6: 899614010000             mov    DWORD PTR [esi+0x114],edx
0x4cc2fc: 89442448                 mov    DWORD PTR [esp+0x48],eax
0x4cc300: 898618010000             mov    DWORD PTR [esi+0x118],eax
0x4cc306: d98600010000             fld    DWORD PTR [esi+0x100]
0x4cc30c: 8b06                     mov    eax,DWORD PTR [esi]
0x4cc30e: d95c2414                 fstp   DWORD PTR [esp+0x14]
0x4cc312: 8b5048                   mov    edx,DWORD PTR [eax+0x48]
0x4cc315: d9442440                 fld    DWORD PTR [esp+0x40]
0x4cc319: 6a00                     push   0x0
0x4cc31b: d9442418                 fld    DWORD PTR [esp+0x18]
0x4cc31f: 8d4c2450                 lea    ecx,[esp+0x50]
0x4cc323: d9c0                     fld    st(0)
0x4cc325: 51                       push   ecx
0x4cc326: deea                     fsubp  st(2),st
0x4cc328: 8bce                     mov    ecx,esi
0x4cc32a: d9c9                     fxch   st(1)
0x4cc32c: d95c2430                 fstp   DWORD PTR [esp+0x30]
0x4cc330: d98604010000             fld    DWORD PTR [esi+0x104]
0x4cc336: d95c241c                 fstp   DWORD PTR [esp+0x1c]
0x4cc33a: d944244c                 fld    DWORD PTR [esp+0x4c]
0x4cc33e: d944241c                 fld    DWORD PTR [esp+0x1c]
0x4cc342: d9c0                     fld    st(0)
0x4cc344: deea                     fsubp  st(2),st
0x4cc346: d9c9                     fxch   st(1)
0x4cc348: d95c2434                 fstp   DWORD PTR [esp+0x34]
0x4cc34c: d98608010000             fld    DWORD PTR [esi+0x108]
0x4cc352: d95c241c                 fstp   DWORD PTR [esp+0x1c]
0x4cc356: d9442450                 fld    DWORD PTR [esp+0x50]
0x4cc35a: d944241c                 fld    DWORD PTR [esp+0x1c]
0x4cc35e: d9c0                     fld    st(0)
0x4cc360: deea                     fsubp  st(2),st
0x4cc362: d9c9                     fxch   st(1)
0x4cc364: d95c2438                 fstp   DWORD PTR [esp+0x38]
0x4cc368: d9442430                 fld    DWORD PTR [esp+0x30]
0x4cc36c: d9442418                 fld    DWORD PTR [esp+0x18]
0x4cc370: d9c0                     fld    st(0)
0x4cc372: deca                     fmulp  st(2),st
0x4cc374: d9c9                     fxch   st(1)
0x4cc376: d95c243c                 fstp   DWORD PTR [esp+0x3c]
0x4cc37a: d9442434                 fld    DWORD PTR [esp+0x34]
0x4cc37e: d8c9                     fmul   st,st(1)
0x4cc380: d95c2440                 fstp   DWORD PTR [esp+0x40]
0x4cc384: d84c2438                 fmul   DWORD PTR [esp+0x38]
0x4cc388: d95c2444                 fstp   DWORD PTR [esp+0x44]
0x4cc38c: d944243c                 fld    DWORD PTR [esp+0x3c]
0x4cc390: dec3                     faddp  st(3),st
0x4cc392: d9ca                     fxch   st(2)
0x4cc394: d95c2454                 fstp   DWORD PTR [esp+0x54]
0x4cc398: d8442440                 fadd   DWORD PTR [esp+0x40]
0x4cc39c: d95c2458                 fstp   DWORD PTR [esp+0x58]
0x4cc3a0: d8442444                 fadd   DWORD PTR [esp+0x44]
0x4cc3a4: d95c241c                 fstp   DWORD PTR [esp+0x1c]
0x4cc3a8: d944241c                 fld    DWORD PTR [esp+0x1c]
0x4cc3ac: d8442420                 fadd   DWORD PTR [esp+0x20]
0x4cc3b0: d95c245c                 fstp   DWORD PTR [esp+0x5c]
0x4cc3b4: ffd2                     call   edx
0x4cc3b6: d944242c                 fld    DWORD PTR [esp+0x2c]
0x4cc3ba: d9442428                 fld    DWORD PTR [esp+0x28]
0x4cc3be: e8072a4300               call   0x8fedca
0x4cc3c3: d95c2418                 fstp   DWORD PTR [esp+0x18]
0x4cc3c7: f605187cfb0001           test   BYTE PTR ds:0xfb7c18,0x1
0x4cc3ce: d9442418                 fld    DWORD PTR [esp+0x18]
0x4cc3d2: dc052858c500             fadd   QWORD PTR ds:0xc55828
0x4cc3d8: d95c2418                 fstp   DWORD PTR [esp+0x18]
0x4cc3dc: 750c                     jne    0x4cc3ea
0x4cc3de: 830d187cfb0001           or     DWORD PTR ds:0xfb7c18,0x1
0x4cc3e5: e8e685f7ff               call   0x4449d0
0x4cc3ea: d9052488fb00             fld    DWORD PTR ds:0xfb8824
0x4cc3f0: 8b16                     mov    edx,DWORD PTR [esi]
0x4cc3f2: d84c2418                 fmul   DWORD PTR [esp+0x18]
0x4cc3f6: 8b5258                   mov    edx,DWORD PTR [edx+0x58]
0x4cc3f9: d97c2410                 fnstcw WORD PTR [esp+0x10]
0x4cc3fd: 0fb7442410               movzx  eax,WORD PTR [esp+0x10]
0x4cc402: 0d000c0000               or     eax,0xc00
0x4cc407: 89442418                 mov    DWORD PTR [esp+0x18],eax
0x4cc40b: d96c2418                 fldcw  WORD PTR [esp+0x18]
0x4cc40f: db5c2418                 fistp  DWORD PTR [esp+0x18]
0x4cc413: 8a442418                 mov    al,BYTE PTR [esp+0x18]
0x4cc417: 0fb6c8                   movzx  ecx,al
0x4cc41a: 51                       push   ecx
0x4cc41b: d96c2414                 fldcw  WORD PTR [esp+0x14]
0x4cc41f: 8bce                     mov    ecx,esi
0x4cc421: ffd2                     call   edx
0x4cc423: e9e1000000               jmp    0x4cc509
0x4cc428: 83beac00000000           cmp    DWORD PTR [esi+0xac],0x0
0x4cc42f: 7407                     je     0x4cc438
0x4cc431: 8b06                     mov    eax,DWORD PTR [esi]
0x4cc433: 8b5038                   mov    edx,DWORD PTR [eax+0x38]
0x4cc436: ffd2                     call   edx
0x4cc438: a1cca7fb00               mov    eax,ds:0xfba7cc
0x4cc43d: 85c0                     test   eax,eax
0x4cc43f: 751f                     jne    0x4cc460
0x4cc441: 6880130000               push   0x1380
0x4cc446: e81d4e3c00               call   0x891268
0x4cc44b: 83c404                   add    esp,0x4
0x4cc44e: 85c0                     test   eax,eax
0x4cc450: 7407                     je     0x4cc459
0x4cc452: e8792f2100               call   0x6df3d0
0x4cc457: eb02                     jmp    0x4cc45b
0x4cc459: 33c0                     xor    eax,eax
0x4cc45b: a3cca7fb00               mov    ds:0xfba7cc,eax
0x4cc460: db8060130000             fild   DWORD PTR [eax+0x1360]
0x4cc466: 8b06                     mov    eax,DWORD PTR [esi]
0x4cc468: d9e8                     fld1
0x4cc46a: 8b5060                   mov    edx,DWORD PTR [eax+0x60]
0x4cc46d: def1                     fdivrp st(1),st
0x4cc46f: 8bce                     mov    ecx,esi
0x4cc471: d95c2410                 fstp   DWORD PTR [esp+0x10]
0x4cc475: ffd2                     call   edx
0x4cc477: d84c2410                 fmul   DWORD PTR [esp+0x10]
0x4cc47b: f605187cfb0001           test   BYTE PTR ds:0xfb7c18,0x1
0x4cc482: 8a9ee4000000             mov    bl,BYTE PTR [esi+0xe4]
0x4cc488: d95c2418                 fstp   DWORD PTR [esp+0x18]
0x4cc48c: 750c                     jne    0x4cc49a
0x4cc48e: 830d187cfb0001           or     DWORD PTR ds:0xfb7c18,0x1
0x4cc495: e83685f7ff               call   0x4449d0
0x4cc49a: 0fb6c3                   movzx  eax,bl
0x4cc49d: d904c52080fb00           fld    DWORD PTR [eax*8+0xfb8020]
0x4cc4a4: 8d04c52080fb00           lea    eax,[eax*8+0xfb8020]
0x4cc4ab: d9442418                 fld    DWORD PTR [esp+0x18]
0x4cc4af: 6a01                     push   0x1
0x4cc4b1: d9c0                     fld    st(0)
0x4cc4b3: 8d4c2424                 lea    ecx,[esp+0x24]
0x4cc4b7: deca                     fmulp  st(2),st
0x4cc4b9: 51                       push   ecx
0x4cc4ba: d9c9                     fxch   st(1)
0x4cc4bc: 8bce                     mov    ecx,esi
0x4cc4be: d95c2420                 fstp   DWORD PTR [esp+0x20]
0x4cc4c2: d84804                   fmul   DWORD PTR [eax+0x4]
0x4cc4c5: 8b06                     mov    eax,DWORD PTR [esi]
0x4cc4c7: 8b5044                   mov    edx,DWORD PTR [eax+0x44]
0x4cc4ca: d95c2424                 fstp   DWORD PTR [esp+0x24]
0x4cc4ce: d986a0000000             fld    DWORD PTR [esi+0xa0]
0x4cc4d4: d8442420                 fadd   DWORD PTR [esp+0x20]
0x4cc4d8: d95c2428                 fstp   DWORD PTR [esp+0x28]
0x4cc4dc: d986a4000000             fld    DWORD PTR [esi+0xa4]
0x4cc4e2: d8442424                 fadd   DWORD PTR [esp+0x24]
0x4cc4e6: d95c242c                 fstp   DWORD PTR [esp+0x2c]
0x4cc4ea: ffd2                     call   edx
0x4cc4ec: d905f8c7c000             fld    DWORD PTR ds:0xc0c7f8
0x4cc4f2: 6a00                     push   0x0
0x4cc4f4: 83ec08                   sub    esp,0x8
0x4cc4f7: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4cc4fb: 8bce                     mov    ecx,esi
0x4cc4fd: d944241c                 fld    DWORD PTR [esp+0x1c]
0x4cc501: d91c24                   fstp   DWORD PTR [esp]
0x4cc504: e857e8ffff               call   0x4cad60
0x4cc509: 8bb6f0000000             mov    esi,DWORD PTR [esi+0xf0]
0x4cc50f: 85f6                     test   esi,esi
0x4cc511: 7405                     je     0x4cc518
0x4cc513: e868420800               call   0x550780
0x4cc518: 33c0                     xor    eax,eax
0x4cc51a: 8b4c2460                 mov    ecx,DWORD PTR [esp+0x60]
0x4cc51e: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4cc525: 59                       pop    ecx
0x4cc526: 5e                       pop    esi
0x4cc527: 5b                       pop    ebx
0x4cc528: 8b4c244c                 mov    ecx,DWORD PTR [esp+0x4c]
0x4cc52c: 33cc                     xor    ecx,esp
0x4cc52e: e8ce4a3c00               call   0x891001
0x4cc533: 8be5                     mov    esp,ebp
0x4cc535: 5d                       pop    ebp
0x4cc536: c3                       ret

; B13 CBullet v+24 complete; elapsed accumulates/clamps without automatic erasure
; VA [0x4cc540,0x4cc5cc) SHA256 3e0202152be65fcd34d66522d2c50e2d9453330846fe241ced7db476423e17a7
0x4cc540: 55                       push   ebp
0x4cc541: 8bec                     mov    ebp,esp
0x4cc543: d94508                   fld    DWORD PTR [ebp+0x8]
0x4cc546: 56                       push   esi
0x4cc547: 8bf1                     mov    esi,ecx
0x4cc549: 8b86f0000000             mov    eax,DWORD PTR [esi+0xf0]
0x4cc54f: 57                       push   edi
0x4cc550: 85c0                     test   eax,eax
0x4cc552: 7415                     je     0x4cc569
0x4cc554: 8b4024                   mov    eax,DWORD PTR [eax+0x24]
0x4cc557: 85c0                     test   eax,eax
0x4cc559: 740e                     je     0x4cc569
0x4cc55b: 51                       push   ecx
0x4cc55c: 8bf8                     mov    edi,eax
0x4cc55e: d91c24                   fstp   DWORD PTR [esp]
0x4cc561: e86a132f00               call   0x7bd8d0
0x4cc566: d94508                   fld    DWORD PTR [ebp+0x8]
0x4cc569: d9c0                     fld    st(0)
0x4cc56b: d88634010000             fadd   DWORD PTR [esi+0x134]
0x4cc571: d95d08                   fstp   DWORD PTR [ebp+0x8]
0x4cc574: d94508                   fld    DWORD PTR [ebp+0x8]
0x4cc577: d99634010000             fst    DWORD PTR [esi+0x134]
0x4cc57d: d98630010000             fld    DWORD PTR [esi+0x130]
0x4cc583: d95d08                   fstp   DWORD PTR [ebp+0x8]
0x4cc586: d94508                   fld    DWORD PTR [ebp+0x8]
0x4cc589: d9c9                     fxch   st(1)
0x4cc58b: dff1                     fcomip st,st(1)
0x4cc58d: ddd8                     fstp   st(0)
0x4cc58f: 760d                     jbe    0x4cc59e
0x4cc591: f30f104508               movss  xmm0,DWORD PTR [ebp+0x8]
0x4cc596: f30f118634010000         movss  DWORD PTR [esi+0x134],xmm0
0x4cc59e: 8bb6fc000000             mov    esi,DWORD PTR [esi+0xfc]
0x4cc5a4: 85f6                     test   esi,esi
0x4cc5a6: 741a                     je     0x4cc5c2
0x4cc5a8: 8b7624                   mov    esi,DWORD PTR [esi+0x24]
0x4cc5ab: 85f6                     test   esi,esi
0x4cc5ad: 7413                     je     0x4cc5c2
0x4cc5af: 51                       push   ecx
0x4cc5b0: 8bfe                     mov    edi,esi
0x4cc5b2: d91c24                   fstp   DWORD PTR [esp]
0x4cc5b5: e816132f00               call   0x7bd8d0
0x4cc5ba: 5f                       pop    edi
0x4cc5bb: 33c0                     xor    eax,eax
0x4cc5bd: 5e                       pop    esi
0x4cc5be: 5d                       pop    ebp
0x4cc5bf: c20400                   ret    0x4
0x4cc5c2: 5f                       pop    edi
0x4cc5c3: ddd8                     fstp   st(0)
0x4cc5c5: 33c0                     xor    eax,eax
0x4cc5c7: 5e                       pop    esi
0x4cc5c8: 5d                       pop    ebp
0x4cc5c9: c20400                   ret    0x4

; B14 CBullet v+30 init; optional target marker and common effect initialization
; VA [0x4cc5d0,0x4cc6e6) SHA256 98f1695d4d94577588369015b5af490a9c6cce2dfffb14ba47ecae92972655d1
0x4cc5d0: 55                       push   ebp
0x4cc5d1: 8bec                     mov    ebp,esp
0x4cc5d3: 83ec2c                   sub    esp,0x2c
0x4cc5d6: a1201fd600               mov    eax,ds:0xd61f20
0x4cc5db: 33c5                     xor    eax,ebp
0x4cc5dd: 8945fc                   mov    DWORD PTR [ebp-0x4],eax
0x4cc5e0: 57                       push   edi
0x4cc5e1: 8bf9                     mov    edi,ecx
0x4cc5e3: 83bff400000000           cmp    DWORD PTR [edi+0xf4],0x0
0x4cc5ea: 0f84e0000000             je     0x4cc6d0
0x4cc5f0: 83bff800000000           cmp    DWORD PTR [edi+0xf8],0x0
0x4cc5f7: 0f84d3000000             je     0x4cc6d0
0x4cc5fd: d98728010000             fld    DWORD PTR [edi+0x128]
0x4cc603: 8b0d38a8fb00             mov    ecx,DWORD PTR ds:0xfba838
0x4cc609: 8b01                     mov    eax,DWORD PTR [ecx]
0x4cc60b: d95df0                   fstp   DWORD PTR [ebp-0x10]
0x4cc60e: d9872c010000             fld    DWORD PTR [edi+0x12c]
0x4cc614: 0f57c0                   xorps  xmm0,xmm0
0x4cc617: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc619: d95df4                   fstp   DWORD PTR [ebp-0xc]
0x4cc61c: d945f4                   fld    DWORD PTR [ebp-0xc]
0x4cc61f: 56                       push   esi
0x4cc620: 6a00                     push   0x0
0x4cc622: 8d55f8                   lea    edx,[ebp-0x8]
0x4cc625: 52                       push   edx
0x4cc626: 83ec08                   sub    esp,0x8
0x4cc629: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4cc62d: f30f1145f8               movss  DWORD PTR [ebp-0x8],xmm0
0x4cc632: d945f0                   fld    DWORD PTR [ebp-0x10]
0x4cc635: d91c24                   fstp   DWORD PTR [esp]
0x4cc638: ffd0                     call   eax
0x4cc63a: 8b0de8aafb00             mov    ecx,DWORD PTR ds:0xfbaae8
0x4cc640: 8b4104                   mov    eax,DWORD PTR [ecx+0x4]
0x4cc643: 80b8a100000000           cmp    BYTE PTR [eax+0xa1],0x0
0x4cc64a: 0fb7b70c010000           movzx  esi,WORD PTR [edi+0x10c]
0x4cc651: 8bd1                     mov    edx,ecx
0x4cc653: 7518                     jne    0x4cc66d
0x4cc655: 6639700c                 cmp    WORD PTR [eax+0xc],si
0x4cc659: 7305                     jae    0x4cc660
0x4cc65b: 8b4008                   mov    eax,DWORD PTR [eax+0x8]
0x4cc65e: eb04                     jmp    0x4cc664
0x4cc660: 8bd0                     mov    edx,eax
0x4cc662: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc664: 80b8a100000000           cmp    BYTE PTR [eax+0xa1],0x0
0x4cc66b: 74e8                     je     0x4cc655
0x4cc66d: 8955e8                   mov    DWORD PTR [ebp-0x18],edx
0x4cc670: 3bd1                     cmp    edx,ecx
0x4cc672: 740b                     je     0x4cc67f
0x4cc674: 663b720c                 cmp    si,WORD PTR [edx+0xc]
0x4cc678: 7205                     jb     0x4cc67f
0x4cc67a: 8d45e8                   lea    eax,[ebp-0x18]
0x4cc67d: eb06                     jmp    0x4cc685
0x4cc67f: 894dec                   mov    DWORD PTR [ebp-0x14],ecx
0x4cc682: 8d45ec                   lea    eax,[ebp-0x14]
0x4cc685: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc687: 3bc1                     cmp    eax,ecx
0x4cc689: 7444                     je     0x4cc6cf
0x4cc68b: 83c04c                   add    eax,0x4c
0x4cc68e: 83781410                 cmp    DWORD PTR [eax+0x14],0x10
0x4cc692: 7202                     jb     0x4cc696
0x4cc694: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc696: d9e8                     fld1
0x4cc698: 83ec08                   sub    esp,0x8
0x4cc69b: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4cc69f: c745d403000000           mov    DWORD PTR [ebp-0x2c],0x3
0x4cc6a6: d9ee                     fldz
0x4cc6a8: c745d8e079c000           mov    DWORD PTR [ebp-0x28],0xc079e0
0x4cc6af: d91c24                   fstp   DWORD PTR [esp]
0x4cc6b2: 8945e4                   mov    DWORD PTR [ebp-0x1c],eax
0x4cc6b5: 6a00                     push   0x0
0x4cc6b7: e884eafcff               call   0x49b140
0x4cc6bc: 8d75f0                   lea    esi,[ebp-0x10]
0x4cc6bf: 8d55d4                   lea    edx,[ebp-0x2c]
0x4cc6c2: 8bc8                     mov    ecx,eax
0x4cc6c4: e8c7580800               call   0x551f90
0x4cc6c9: 8987fc000000             mov    DWORD PTR [edi+0xfc],eax
0x4cc6cf: 5e                       pop    esi
0x4cc6d0: 8bcf                     mov    ecx,edi
0x4cc6d2: e839e8ffff               call   0x4caf10
0x4cc6d7: 8b4dfc                   mov    ecx,DWORD PTR [ebp-0x4]
0x4cc6da: 33cd                     xor    ecx,ebp
0x4cc6dc: 5f                       pop    edi
0x4cc6dd: e81f493c00               call   0x891001
0x4cc6e2: 8be5                     mov    esp,ebp
0x4cc6e4: 5d                       pop    ebp
0x4cc6e5: c3                       ret

; B15 CEffectObject common initializer calls 551FF0 with model and position
; VA [0x4caf10,0x4cafc0) SHA256 811ebba9a4a5b662be47fcdf57a80e8be9d328e70d53287f9af53fe62873bf07
0x4caf10: 55                       push   ebp
0x4caf11: 8bec                     mov    ebp,esp
0x4caf13: 6aff                     push   0xffffffff
0x4caf15: 68fe9d9200               push   0x929dfe
0x4caf1a: 64a100000000             mov    eax,fs:0x0
0x4caf20: 50                       push   eax
0x4caf21: 56                       push   esi
0x4caf22: 57                       push   edi
0x4caf23: a1201fd600               mov    eax,ds:0xd61f20
0x4caf28: 33c5                     xor    eax,ebp
0x4caf2a: 50                       push   eax
0x4caf2b: 8d45f4                   lea    eax,[ebp-0xc]
0x4caf2e: 64a300000000             mov    fs:0x0,eax
0x4caf34: 8bf1                     mov    esi,ecx
0x4caf36: f605dcf6fd0001           test   BYTE PTR ds:0xfdf6dc,0x1
0x4caf3d: 7527                     jne    0x4caf66
0x4caf3f: 830ddcf6fd0001           or     DWORD PTR ds:0xfdf6dc,0x1
0x4caf46: c745fc00000000           mov    DWORD PTR [ebp-0x4],0x0
0x4caf4d: e8ce580800               call   0x550820
0x4caf52: 68b0e6bc00               push   0xbce6b0
0x4caf57: e8be733c00               call   0x89231a
0x4caf5c: 83c404                   add    esp,0x4
0x4caf5f: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x4caf66: 0fb74604                 movzx  eax,WORD PTR [esi+0x4]
0x4caf6a: 8b16                     mov    edx,DWORD PTR [esi]
0x4caf6c: 50                       push   eax
0x4caf6d: 8b424c                   mov    eax,DWORD PTR [edx+0x4c]
0x4caf70: 8bce                     mov    ecx,esi
0x4caf72: ffd0                     call   eax
0x4caf74: 8b8e88000000             mov    ecx,DWORD PTR [esi+0x88]
0x4caf7a: 8bf8                     mov    edi,eax
0x4caf7c: e86f700800               call   0x551ff0
0x4caf81: 8b16                     mov    edx,DWORD PTR [esi]
0x4caf83: 8986f0000000             mov    DWORD PTR [esi+0xf0],eax
0x4caf89: 0fb686b0000000           movzx  eax,BYTE PTR [esi+0xb0]
0x4caf90: b900800000               mov    ecx,0x8000
0x4caf95: 66098ee2000000           or     WORD PTR [esi+0xe2],cx
0x4caf9c: 8886e4000000             mov    BYTE PTR [esi+0xe4],al
0x4cafa2: 50                       push   eax
0x4cafa3: 8b4258                   mov    eax,DWORD PTR [edx+0x58]
0x4cafa6: 8bce                     mov    ecx,esi
0x4cafa8: ffd0                     call   eax
0x4cafaa: b801000000               mov    eax,0x1
0x4cafaf: 8b4df4                   mov    ecx,DWORD PTR [ebp-0xc]
0x4cafb2: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4cafb9: 59                       pop    ecx
0x4cafba: 5f                       pop    edi
0x4cafbb: 5e                       pop    esi
0x4cafbc: 8be5                     mov    esp,ebp
0x4cafbe: 5d                       pop    ebp
0x4cafbf: c3                       ret

; B16 CBullet cleanup v+14 stops/releases visual effects
; VA [0x4cc850,0x4cc8a4) SHA256 47425f4dd7965c901ddb857cdd77add0a4da4b65e5a81d2471653d5ba5ff8d5a
0x4cc850: 53                       push   ebx
0x4cc851: 8bd9                     mov    ebx,ecx
0x4cc853: 8b83fc000000             mov    eax,DWORD PTR [ebx+0xfc]
0x4cc859: 56                       push   esi
0x4cc85a: 85c0                     test   eax,eax
0x4cc85c: 7429                     je     0x4cc887
0x4cc85e: 83782400                 cmp    DWORD PTR [eax+0x24],0x0
0x4cc862: 8d7024                   lea    esi,[eax+0x24]
0x4cc865: 7405                     je     0x4cc86c
0x4cc867: e8841d2f00               call   0x7be5f0
0x4cc86c: 57                       push   edi
0x4cc86d: 8bbbfc000000             mov    edi,DWORD PTR [ebx+0xfc]
0x4cc873: 85ff                     test   edi,edi
0x4cc875: 740f                     je     0x4cc886
0x4cc877: e834b5ffff               call   0x4c7db0
0x4cc87c: c783fc00000000000000     mov    DWORD PTR [ebx+0xfc],0x0
0x4cc886: 5f                       pop    edi
0x4cc887: 8b9bf0000000             mov    ebx,DWORD PTR [ebx+0xf0]
0x4cc88d: 85db                     test   ebx,ebx
0x4cc88f: 740e                     je     0x4cc89f
0x4cc891: 837b2400                 cmp    DWORD PTR [ebx+0x24],0x0
0x4cc895: 8d7324                   lea    esi,[ebx+0x24]
0x4cc898: 7405                     je     0x4cc89f
0x4cc89a: e8511d2f00               call   0x7be5f0
0x4cc89f: 5e                       pop    esi
0x4cc8a0: 33c0                     xor    eax,eax
0x4cc8a2: 5b                       pop    ebx
0x4cc8a3: c3                       ret

; B17 One-shot bullet terminal effect; does not update target HP
; VA [0x4cc8b0,0x4cca41) SHA256 c446791248ee8eda947ec324535f931e9f0be6ae2804ed708ccfbf30c5c4e3a3
0x4cc8b0: 55                       push   ebp
0x4cc8b1: 8bec                     mov    ebp,esp
0x4cc8b3: 83ec2c                   sub    esp,0x2c
0x4cc8b6: a1201fd600               mov    eax,ds:0xd61f20
0x4cc8bb: 33c5                     xor    eax,ebp
0x4cc8bd: 8945fc                   mov    DWORD PTR [ebp-0x4],eax
0x4cc8c0: 83be2401000000           cmp    DWORD PTR [esi+0x124],0x0
0x4cc8c7: 57                       push   edi
0x4cc8c8: 0f8564010000             jne    0x4cca32
0x4cc8ce: 83bef400000000           cmp    DWORD PTR [esi+0xf4],0x0
0x4cc8d5: 0f8457010000             je     0x4cca32
0x4cc8db: 83bef800000000           cmp    DWORD PTR [esi+0xf8],0x0
0x4cc8e2: 743e                     je     0x4cc922
0x4cc8e4: d98628010000             fld    DWORD PTR [esi+0x128]
0x4cc8ea: 8b0d38a8fb00             mov    ecx,DWORD PTR ds:0xfba838
0x4cc8f0: 8b01                     mov    eax,DWORD PTR [ecx]
0x4cc8f2: d95df0                   fstp   DWORD PTR [ebp-0x10]
0x4cc8f5: d9862c010000             fld    DWORD PTR [esi+0x12c]
0x4cc8fb: 0f57c0                   xorps  xmm0,xmm0
0x4cc8fe: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc900: d95df4                   fstp   DWORD PTR [ebp-0xc]
0x4cc903: d945f4                   fld    DWORD PTR [ebp-0xc]
0x4cc906: 6a00                     push   0x0
0x4cc908: 8d55f8                   lea    edx,[ebp-0x8]
0x4cc90b: 52                       push   edx
0x4cc90c: 83ec08                   sub    esp,0x8
0x4cc90f: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4cc913: f30f1145f8               movss  DWORD PTR [ebp-0x8],xmm0
0x4cc918: d945f0                   fld    DWORD PTR [ebp-0x10]
0x4cc91b: d91c24                   fstp   DWORD PTR [esp]
0x4cc91e: ffd0                     call   eax
0x4cc920: eb76                     jmp    0x4cc998
0x4cc922: 0fb78e28010000           movzx  ecx,WORD PTR [esi+0x128]
0x4cc929: 894de8                   mov    DWORD PTR [ebp-0x18],ecx
0x4cc92c: e82f27f4ff               call   0x40f060
0x4cc931: 8bf8                     mov    edi,eax
0x4cc933: 8d55e8                   lea    edx,[ebp-0x18]
0x4cc936: 52                       push   edx
0x4cc937: 8d4f08                   lea    ecx,[edi+0x8]
0x4cc93a: 8d45ec                   lea    eax,[ebp-0x14]
0x4cc93d: e8be253600               call   0x82ef00
0x4cc942: 8b45ec                   mov    eax,DWORD PTR [ebp-0x14]
0x4cc945: 3b470c                   cmp    eax,DWORD PTR [edi+0xc]
0x4cc948: 7407                     je     0x4cc951
0x4cc94a: 8b4810                   mov    ecx,DWORD PTR [eax+0x10]
0x4cc94d: 85c9                     test   ecx,ecx
0x4cc94f: 751d                     jne    0x4cc96e
0x4cc951: 8b8610010000             mov    eax,DWORD PTR [esi+0x110]
0x4cc957: 8b8e14010000             mov    ecx,DWORD PTR [esi+0x114]
0x4cc95d: 8b9618010000             mov    edx,DWORD PTR [esi+0x118]
0x4cc963: 8945f0                   mov    DWORD PTR [ebp-0x10],eax
0x4cc966: 894df4                   mov    DWORD PTR [ebp-0xc],ecx
0x4cc969: 8955f8                   mov    DWORD PTR [ebp-0x8],edx
0x4cc96c: eb2a                     jmp    0x4cc998
0x4cc96e: 8b01                     mov    eax,DWORD PTR [ecx]
0x4cc970: 8b504c                   mov    edx,DWORD PTR [eax+0x4c]
0x4cc973: ffd2                     call   edx
0x4cc975: 8b08                     mov    ecx,DWORD PTR [eax]
0x4cc977: 894df0                   mov    DWORD PTR [ebp-0x10],ecx
0x4cc97a: 8b5004                   mov    edx,DWORD PTR [eax+0x4]
0x4cc97d: 8955f4                   mov    DWORD PTR [ebp-0xc],edx
0x4cc980: 8b4008                   mov    eax,DWORD PTR [eax+0x8]
0x4cc983: 898e10010000             mov    DWORD PTR [esi+0x110],ecx
0x4cc989: 899614010000             mov    DWORD PTR [esi+0x114],edx
0x4cc98f: 8945f8                   mov    DWORD PTR [ebp-0x8],eax
0x4cc992: 898618010000             mov    DWORD PTR [esi+0x118],eax
0x4cc998: 8b15e8aafb00             mov    edx,DWORD PTR ds:0xfbaae8
0x4cc99e: 8b4204                   mov    eax,DWORD PTR [edx+0x4]
0x4cc9a1: 80b8a100000000           cmp    BYTE PTR [eax+0xa1],0x0
0x4cc9a8: 0fb7be0c010000           movzx  edi,WORD PTR [esi+0x10c]
0x4cc9af: 8bca                     mov    ecx,edx
0x4cc9b1: 7518                     jne    0x4cc9cb
0x4cc9b3: 6639780c                 cmp    WORD PTR [eax+0xc],di
0x4cc9b7: 7305                     jae    0x4cc9be
0x4cc9b9: 8b4008                   mov    eax,DWORD PTR [eax+0x8]
0x4cc9bc: eb04                     jmp    0x4cc9c2
0x4cc9be: 8bc8                     mov    ecx,eax
0x4cc9c0: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc9c2: 80b8a100000000           cmp    BYTE PTR [eax+0xa1],0x0
0x4cc9c9: 74e8                     je     0x4cc9b3
0x4cc9cb: 894dec                   mov    DWORD PTR [ebp-0x14],ecx
0x4cc9ce: 3bca                     cmp    ecx,edx
0x4cc9d0: 740b                     je     0x4cc9dd
0x4cc9d2: 663b790c                 cmp    di,WORD PTR [ecx+0xc]
0x4cc9d6: 7205                     jb     0x4cc9dd
0x4cc9d8: 8d45ec                   lea    eax,[ebp-0x14]
0x4cc9db: eb06                     jmp    0x4cc9e3
0x4cc9dd: 8955e8                   mov    DWORD PTR [ebp-0x18],edx
0x4cc9e0: 8d45e8                   lea    eax,[ebp-0x18]
0x4cc9e3: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc9e5: 3bc2                     cmp    eax,edx
0x4cc9e7: 743f                     je     0x4cca28
0x4cc9e9: 83c068                   add    eax,0x68
0x4cc9ec: 83781410                 cmp    DWORD PTR [eax+0x14],0x10
0x4cc9f0: 7202                     jb     0x4cc9f4
0x4cc9f2: 8b00                     mov    eax,DWORD PTR [eax]
0x4cc9f4: d9e8                     fld1
0x4cc9f6: 83ec08                   sub    esp,0x8
0x4cc9f9: d95c2404                 fstp   DWORD PTR [esp+0x4]
0x4cc9fd: 8945e4                   mov    DWORD PTR [ebp-0x1c],eax
0x4cca00: d9ee                     fldz
0x4cca02: 8d45f0                   lea    eax,[ebp-0x10]
0x4cca05: d91c24                   fstp   DWORD PTR [esp]
0x4cca08: c745d403000000           mov    DWORD PTR [ebp-0x2c],0x3
0x4cca0f: c745d8e879c000           mov    DWORD PTR [ebp-0x28],0xc079e8
0x4cca16: 50                       push   eax
0x4cca17: 6a00                     push   0x0
0x4cca19: e822e7fcff               call   0x49b140
0x4cca1e: 8d55d4                   lea    edx,[ebp-0x2c]
0x4cca21: 8bc8                     mov    ecx,eax
0x4cca23: e8f8540800               call   0x551f20
0x4cca28: c7862401000001000000     mov    DWORD PTR [esi+0x124],0x1
0x4cca32: 8b4dfc                   mov    ecx,DWORD PTR [ebp-0x4]
0x4cca35: 33cd                     xor    ecx,ebp
0x4cca37: 5f                       pop    edi
0x4cca38: e8c4453c00               call   0x891001
0x4cca3d: 8be5                     mov    esp,ebp
0x4cca3f: 5d                       pop    ebp
0x4cca40: c3                       ret

; B18 CBullet property5/6 consume signed16 values to speed factor/base
; VA [0x4cfe50,0x4cfe84) SHA256 bad3778867e9f691942a872ad999adaf5ec65516c5e6efb34113eccce576d4cb
0x4cfe50: 55                       push   ebp
0x4cfe51: 8bec                     mov    ebp,esp
0x4cfe53: 0fbf4508                 movsx  eax,WORD PTR [ebp+0x8]
0x4cfe57: 83e805                   sub    eax,0x5
0x4cfe5a: 741a                     je     0x4cfe76
0x4cfe5c: 48                       dec    eax
0x4cfe5d: 7521                     jne    0x4cfe80
0x4cfe5f: 0fbf450c                 movsx  eax,WORD PTR [ebp+0xc]
0x4cfe63: 0f57c0                   xorps  xmm0,xmm0
0x4cfe66: f30f2ac0                 cvtsi2ss xmm0,eax
0x4cfe6a: f30f1181cc000000         movss  DWORD PTR [ecx+0xcc],xmm0
0x4cfe72: 5d                       pop    ebp
0x4cfe73: c20800                   ret    0x8
0x4cfe76: 0fbf550c                 movsx  edx,WORD PTR [ebp+0xc]
0x4cfe7a: 8991d0000000             mov    DWORD PTR [ecx+0xd0],edx
0x4cfe80: 5d                       pop    ebp
0x4cfe81: c20800                   ret    0x8

; B19 CBasicObject v+60 speed = signed factor * .01 * base
; VA [0x4cad40,0x4cad60) SHA256 91861a684ee29d4129c7b466e57cdefc65e197b1c4020b9c22979377efe9031f
0x4cad40: 55                       push   ebp
0x4cad41: 8bec                     mov    ebp,esp
0x4cad43: 51                       push   ecx
0x4cad44: db81d0000000             fild   DWORD PTR [ecx+0xd0]
0x4cad4a: dc0df857c500             fmul   QWORD PTR ds:0xc557f8
0x4cad50: d889cc000000             fmul   DWORD PTR [ecx+0xcc]
0x4cad56: d95dfc                   fstp   DWORD PTR [ebp-0x4]
0x4cad59: d945fc                   fld    DWORD PTR [ebp-0x4]
0x4cad5c: 8be5                     mov    esp,ebp
0x4cad5e: 5d                       pop    ebp
0x4cad5f: c3                       ret

; B20 001A complete removal; typed bullet prelude then common erase
; VA [0x4b28d0,0x4b2aed) SHA256 d9ccc9c72e362dc9d9b4ff5cb0f3cbd3ae06fa8e0a6d07c001a09606c2025aef
0x4b28d0: 55                       push   ebp
0x4b28d1: 8bec                     mov    ebp,esp
0x4b28d3: 83e4f8                   and    esp,0xfffffff8
0x4b28d6: 6aff                     push   0xffffffff
0x4b28d8: 681c6d9300               push   0x936d1c
0x4b28dd: 64a100000000             mov    eax,fs:0x0
0x4b28e3: 50                       push   eax
0x4b28e4: 83ec28                   sub    esp,0x28
0x4b28e7: 53                       push   ebx
0x4b28e8: 56                       push   esi
0x4b28e9: 57                       push   edi
0x4b28ea: a1201fd600               mov    eax,ds:0xd61f20
0x4b28ef: 33c4                     xor    eax,esp
0x4b28f1: 50                       push   eax
0x4b28f2: 8d442438                 lea    eax,[esp+0x38]
0x4b28f6: 64a300000000             mov    fs:0x0,eax
0x4b28fc: 8b450c                   mov    eax,DWORD PTR [ebp+0xc]
0x4b28ff: 83f804                   cmp    eax,0x4
0x4b2902: 7304                     jae    0x4b2908
0x4b2904: 33c0                     xor    eax,eax
0x4b2906: eb05                     jmp    0x4b290d
0x4b2908: 83c0fc                   add    eax,0xfffffffc
0x4b290b: d1e8                     shr    eax,1
0x4b290d: 85c0                     test   eax,eax
0x4b290f: 0f84c1010000             je     0x4b2ad6
0x4b2915: 8b4d08                   mov    ecx,DWORD PTR [ebp+0x8]
0x4b2918: 83c104                   add    ecx,0x4
0x4b291b: 894c2414                 mov    DWORD PTR [esp+0x14],ecx
0x4b291f: 89442418                 mov    DWORD PTR [esp+0x18],eax
0x4b2923: bb01000000               mov    ebx,0x1
0x4b2928: 841d2cb2fa00             test   BYTE PTR ds:0xfab22c,bl
0x4b292e: 7528                     jne    0x4b2958
0x4b2930: 091d2cb2fa00             or     DWORD PTR ds:0xfab22c,ebx
0x4b2936: c744244000000000         mov    DWORD PTR [esp+0x40],0x0
0x4b293e: e84dc30200               call   0x4dec90
0x4b2943: 6830cebc00               push   0xbcce30
0x4b2948: e8cdf93d00               call   0x89231a
0x4b294d: 83c404                   add    esp,0x4
0x4b2950: c7442440ffffffff         mov    DWORD PTR [esp+0x40],0xffffffff
0x4b2958: 8b542414                 mov    edx,DWORD PTR [esp+0x14]
0x4b295c: 0fb702                   movzx  eax,WORD PTR [edx]
0x4b295f: 8d4c241c                 lea    ecx,[esp+0x1c]
0x4b2963: 8944241c                 mov    DWORD PTR [esp+0x1c],eax
0x4b2967: 51                       push   ecx
0x4b2968: 8d442424                 lea    eax,[esp+0x24]
0x4b296c: b938b1fa00               mov    ecx,0xfab138
0x4b2971: e88ac53700               call   0x82ef00
0x4b2976: 8b442420                 mov    eax,DWORD PTR [esp+0x20]
0x4b297a: 3b053cb1fa00             cmp    eax,DWORD PTR ds:0xfab13c
0x4b2980: 7407                     je     0x4b2989
0x4b2982: 8b7010                   mov    esi,DWORD PTR [eax+0x10]
0x4b2985: 85f6                     test   esi,esi
0x4b2987: 7512                     jne    0x4b299b
0x4b2989: 68e06cc000               push   0xc06ce0
0x4b298e: e8cdb12300               call   0x6edb60
0x4b2993: 83c404                   add    esp,0x4
0x4b2996: e92c010000               jmp    0x4b2ac7
0x4b299b: 0fb74604                 movzx  eax,WORD PTR [esi+0x4]
0x4b299f: 3ac3                     cmp    al,bl
0x4b29a1: 740c                     je     0x4b29af
0x4b29a3: 3c06                     cmp    al,0x6
0x4b29a5: 7408                     je     0x4b29af
0x4b29a7: 84c0                     test   al,al
0x4b29a9: 7404                     je     0x4b29af
0x4b29ab: 3c07                     cmp    al,0x7
0x4b29ad: 7566                     jne    0x4b2a15
0x4b29af: f30f1005c056c400         movss  xmm0,DWORD PTR ds:0xc456c0
0x4b29b7: 8b865c010000             mov    eax,DWORD PTR [esi+0x15c]
0x4b29bd: f30f11442424             movss  DWORD PTR [esp+0x24],xmm0
0x4b29c3: f30f11442428             movss  DWORD PTR [esp+0x28],xmm0
0x4b29c9: f30f1144242c             movss  DWORD PTR [esp+0x2c],xmm0
0x4b29cf: f30f11442430             movss  DWORD PTR [esp+0x30],xmm0
0x4b29d5: 85c0                     test   eax,eax
0x4b29d7: 743c                     je     0x4b2a15
0x4b29d9: 83be7003000000           cmp    DWORD PTR [esi+0x370],0x0
0x4b29e0: 7433                     je     0x4b2a15
0x4b29e2: 6a00                     push   0x0
0x4b29e4: 50                       push   eax
0x4b29e5: e8d6522f00               call   0x7a7cc0
0x4b29ea: 8b542424                 mov    edx,DWORD PTR [esp+0x24]
0x4b29ee: 8b865c010000             mov    eax,DWORD PTR [esi+0x15c]
0x4b29f4: 83ec10                   sub    esp,0x10
0x4b29f7: 8bcc                     mov    ecx,esp
0x4b29f9: 8911                     mov    DWORD PTR [ecx],edx
0x4b29fb: 8b542438                 mov    edx,DWORD PTR [esp+0x38]
0x4b29ff: 895104                   mov    DWORD PTR [ecx+0x4],edx
0x4b2a02: 8b54243c                 mov    edx,DWORD PTR [esp+0x3c]
0x4b2a06: 895108                   mov    DWORD PTR [ecx+0x8],edx
0x4b2a09: 8b542440                 mov    edx,DWORD PTR [esp+0x40]
0x4b2a0d: 89510c                   mov    DWORD PTR [ecx+0xc],edx
0x4b2a10: e8db512f00               call   0x7a7bf0
0x4b2a15: 0fb74604                 movzx  eax,WORD PTR [esi+0x4]
0x4b2a19: 3c02                     cmp    al,0x2
0x4b2a1b: 7408                     je     0x4b2a25
0x4b2a1d: 3c08                     cmp    al,0x8
0x4b2a1f: 7404                     je     0x4b2a25
0x4b2a21: 3c09                     cmp    al,0x9
0x4b2a23: 7531                     jne    0x4b2a56
0x4b2a25: 83bef400000000           cmp    DWORD PTR [esi+0xf4],0x0
0x4b2a2c: 7428                     je     0x4b2a56
0x4b2a2e: 83be2401000000           cmp    DWORD PTR [esi+0x124],0x0
0x4b2a35: 751f                     jne    0x4b2a56
0x4b2a37: d98634010000             fld    DWORD PTR [esi+0x134]
0x4b2a3d: d8b630010000             fdiv   DWORD PTR [esi+0x130]
0x4b2a43: dd05f057c500             fld    QWORD PTR ds:0xc557f0
0x4b2a49: d9c9                     fxch   st(1)
0x4b2a4b: dff1                     fcomip st,st(1)
0x4b2a4d: ddd8                     fstp   st(0)
0x4b2a4f: 7605                     jbe    0x4b2a56
0x4b2a51: e85a9e0100               call   0x4cc8b0
0x4b2a56: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4b2a5c: 668b7604                 mov    si,WORD PTR [esi+0x4]
0x4b2a60: 33c0                     xor    eax,eax
0x4b2a62: 8d510c                   lea    edx,[ecx+0xc]
0x4b2a65: 8b3a                     mov    edi,DWORD PTR [edx]
0x4b2a67: 85ff                     test   edi,edi
0x4b2a69: 7406                     je     0x4b2a71
0x4b2a6b: 66397704                 cmp    WORD PTR [edi+0x4],si
0x4b2a6f: 740c                     je     0x4b2a7d
0x4b2a71: 03c3                     add    eax,ebx
0x4b2a73: 83c20c                   add    edx,0xc
0x4b2a76: 83f803                   cmp    eax,0x3
0x4b2a79: 7cea                     jl     0x4b2a65
0x4b2a7b: eb0c                     jmp    0x4b2a89
0x4b2a7d: 83f8ff                   cmp    eax,0xffffffff
0x4b2a80: 7407                     je     0x4b2a89
0x4b2a82: 8b01                     mov    eax,DWORD PTR [ecx]
0x4b2a84: 8b5014                   mov    edx,DWORD PTR [eax+0x14]
0x4b2a87: ffd2                     call   edx
0x4b2a89: 841d2cb2fa00             test   BYTE PTR ds:0xfab22c,bl
0x4b2a8f: 7524                     jne    0x4b2ab5
0x4b2a91: 091d2cb2fa00             or     DWORD PTR ds:0xfab22c,ebx
0x4b2a97: 895c2440                 mov    DWORD PTR [esp+0x40],ebx
0x4b2a9b: e8f0c10200               call   0x4dec90
0x4b2aa0: 6830cebc00               push   0xbcce30
0x4b2aa5: e870f83d00               call   0x89231a
0x4b2aaa: 83c404                   add    esp,0x4
0x4b2aad: c7442440ffffffff         mov    DWORD PTR [esp+0x40],0xffffffff
0x4b2ab5: 8b442414                 mov    eax,DWORD PTR [esp+0x14]
0x4b2ab9: 0fb708                   movzx  ecx,WORD PTR [eax]
0x4b2abc: 51                       push   ecx
0x4b2abd: b830b1fa00               mov    eax,0xfab130
0x4b2ac2: e8f9d00200               call   0x4dfbc0
0x4b2ac7: 8344241402               add    DWORD PTR [esp+0x14],0x2
0x4b2acc: 295c2418                 sub    DWORD PTR [esp+0x18],ebx
0x4b2ad0: 0f8552feffff             jne    0x4b2928
0x4b2ad6: 33c0                     xor    eax,eax
0x4b2ad8: 8b4c2438                 mov    ecx,DWORD PTR [esp+0x38]
0x4b2adc: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4b2ae3: 59                       pop    ecx
0x4b2ae4: 5f                       pop    edi
0x4b2ae5: 5e                       pop    esi
0x4b2ae6: 5b                       pop    ebx
0x4b2ae7: 8be5                     mov    esp,ebp
0x4b2ae9: 5d                       pop    ebp
0x4b2aea: c20c00                   ret    0xc

; B21 Frame calls world AnimateFrame with delta and FAB130
; VA [0x492599,0x4925aa) SHA256 a46a2817e1949a8c368f1da8fde4b57ab5a190c99d776fdcfb6755b3be76378c
0x492599: d9450c                   fld    DWORD PTR [ebp+0xc]
0x49259c: 51                       push   ecx
0x49259d: d91c24                   fstp   DWORD PTR [esp]
0x4925a0: 6830b1fa00               push   0xfab130
0x4925a5: e856dc0400               call   0x4e0200

; B22 World animation enumeration, callback object and worker delivery; scaled visual delta possible
; VA [0x4e0200,0x4e051c) SHA256 dd92867357a58ccb569987dedf51146fe5efae3aaade9c76e8e982a0d516ab0d
0x4e0200: 55                       push   ebp
0x4e0201: 8bec                     mov    ebp,esp
0x4e0203: 6aff                     push   0xffffffff
0x4e0205: 68c4439400               push   0x9443c4
0x4e020a: 64a100000000             mov    eax,fs:0x0
0x4e0210: 50                       push   eax
0x4e0211: 83ec0c                   sub    esp,0xc
0x4e0214: 53                       push   ebx
0x4e0215: 56                       push   esi
0x4e0216: 57                       push   edi
0x4e0217: a1201fd600               mov    eax,ds:0xd61f20
0x4e021c: 33c5                     xor    eax,ebp
0x4e021e: 50                       push   eax
0x4e021f: 8d45f4                   lea    eax,[ebp-0xc]
0x4e0222: 64a300000000             mov    fs:0x0,eax
0x4e0228: f605600ffc0001           test   BYTE PTR ds:0xfc0f60,0x1
0x4e022f: be01000000               mov    esi,0x1
0x4e0234: 7527                     jne    0x4e025d
0x4e0236: 0935600ffc00             or     DWORD PTR ds:0xfc0f60,esi
0x4e023c: c745fc00000000           mov    DWORD PTR [ebp-0x4],0x0
0x4e0243: e8f8cc2b00               call   0x79cf40
0x4e0248: 6880dbbc00               push   0xbcdb80
0x4e024d: e8c8203b00               call   0x89231a
0x4e0252: 83c404                   add    esp,0x4
0x4e0255: 83cfff                   or     edi,0xffffffff
0x4e0258: 897dfc                   mov    DWORD PTR [ebp-0x4],edi
0x4e025b: eb03                     jmp    0x4e0260
0x4e025d: 83cfff                   or     edi,0xffffffff
0x4e0260: b9900efc00               mov    ecx,0xfc0e90
0x4e0265: e8a6d82b00               call   0x79db10
0x4e026a: d9450c                   fld    DWORD PTR [ebp+0xc]
0x4e026d: 8b0d38a8fb00             mov    ecx,DWORD PTR ds:0xfba838
0x4e0273: 8b01                     mov    eax,DWORD PTR [ecx]
0x4e0275: 8b5018                   mov    edx,DWORD PTR [eax+0x18]
0x4e0278: 51                       push   ecx
0x4e0279: d91c24                   fstp   DWORD PTR [esp]
0x4e027c: ffd2                     call   edx
0x4e027e: f30f10450c               movss  xmm0,DWORD PTR [ebp+0xc]
0x4e0283: 8b5d08                   mov    ebx,DWORD PTR [ebp+0x8]
0x4e0286: 0f57c9                   xorps  xmm1,xmm1
0x4e0289: f30f1145f0               movss  DWORD PTR [ebp-0x10],xmm0
0x4e028e: f30f1083ac000000         movss  xmm0,DWORD PTR [ebx+0xac]
0x4e0296: 0f2fc1                   comiss xmm0,xmm1
0x4e0299: f30f1145ec               movss  DWORD PTR [ebp-0x14],xmm0
0x4e029e: 7709                     ja     0x4e02a9
0x4e02a0: 83bbb000000000           cmp    DWORD PTR [ebx+0xb0],0x0
0x4e02a7: 742d                     je     0x4e02d6
0x4e02a9: d9450c                   fld    DWORD PTR [ebp+0xc]
0x4e02ac: dd059058c500             fld    QWORD PTR ds:0xc55890
0x4e02b2: d8c9                     fmul   st,st(1)
0x4e02b4: d95df0                   fstp   DWORD PTR [ebp-0x10]
0x4e02b7: d86dec                   fsubr  DWORD PTR [ebp-0x14]
0x4e02ba: d95dec                   fstp   DWORD PTR [ebp-0x14]
0x4e02bd: d945ec                   fld    DWORD PTR [ebp-0x14]
0x4e02c0: d993ac000000             fst    DWORD PTR [ebx+0xac]
0x4e02c6: d9ee                     fldz
0x4e02c8: dff1                     fcomip st,st(1)
0x4e02ca: ddd8                     fstp   st(0)
0x4e02cc: 7208                     jb     0x4e02d6
0x4e02ce: f30f118bac000000         movss  DWORD PTR [ebx+0xac],xmm1
0x4e02d6: f605e879fb0001           test   BYTE PTR ds:0xfb79e8,0x1
0x4e02dd: f30f1045f0               movss  xmm0,DWORD PTR [ebp-0x10]
0x4e02e2: c745e82ccfc000           mov    DWORD PTR [ebp-0x18],0xc0cf2c
0x4e02e9: f30f1145ec               movss  DWORD PTR [ebp-0x14],xmm0
0x4e02ee: 751e                     jne    0x4e030e
0x4e02f0: 0935e879fb00             or     DWORD PTR ds:0xfb79e8,esi
0x4e02f6: 8975fc                   mov    DWORD PTR [ebp-0x4],esi
0x4e02f9: e8e28a2b00               call   0x798de0
0x4e02fe: 68e0d2bc00               push   0xbcd2e0
0x4e0303: e812203b00               call   0x89231a
0x4e0308: 83c404                   add    esp,0x4
0x4e030b: 897dfc                   mov    DWORD PTR [ebp-0x4],edi
0x4e030e: 8d45e8                   lea    eax,[ebp-0x18]
0x4e0311: a3e479fb00               mov    ds:0xfb79e4,eax
0x4e0316: 8b430c                   mov    eax,DWORD PTR [ebx+0xc]
0x4e0319: 8b30                     mov    esi,DWORD PTR [eax]
0x4e031b: 3bf0                     cmp    esi,eax
0x4e031d: 0f84ed000000             je     0x4e0410
0x4e0323: bb02000000               mov    ebx,0x2
0x4e0328: eb06                     jmp    0x4e0330
0x4e032a: 8d9b00000000             lea    ebx,[ebx+0x0]
0x4e0330: f605e879fb0001           test   BYTE PTR ds:0xfb79e8,0x1
0x4e0337: 751f                     jne    0x4e0358
0x4e0339: 830de879fb0001           or     DWORD PTR ds:0xfb79e8,0x1
0x4e0340: 895dfc                   mov    DWORD PTR [ebp-0x4],ebx
0x4e0343: e8988a2b00               call   0x798de0
0x4e0348: 68e0d2bc00               push   0xbcd2e0
0x4e034d: e8c81f3b00               call   0x89231a
0x4e0352: 83c404                   add    esp,0x4
0x4e0355: 897dfc                   mov    DWORD PTR [ebp-0x4],edi
0x4e0358: 8b0de079fb00             mov    ecx,DWORD PTR ds:0xfb79e0
0x4e035e: 8b4610                   mov    eax,DWORD PTR [esi+0x10]
0x4e0361: 8b15d079fb00             mov    edx,DWORD PTR ds:0xfb79d0
0x4e0367: 8d0c49                   lea    ecx,[ecx+ecx*2]
0x4e036a: 89448a08                 mov    DWORD PTR [edx+ecx*4+0x8],eax
0x4e036e: a1e079fb00               mov    eax,ds:0xfb79e0
0x4e0373: 0fb60dad79fb00           movzx  ecx,BYTE PTR ds:0xfb79ad
0x4e037a: 40                       inc    eax
0x4e037b: a3e079fb00               mov    ds:0xfb79e0,eax
0x4e0380: 3bc1                     cmp    eax,ecx
0x4e0382: 7539                     jne    0x4e03bd
0x4e0384: f605e879fb0001           test   BYTE PTR ds:0xfb79e8,0x1
0x4e038b: 7523                     jne    0x4e03b0
0x4e038d: 830de879fb0001           or     DWORD PTR ds:0xfb79e8,0x1
0x4e0394: c745fc03000000           mov    DWORD PTR [ebp-0x4],0x3
0x4e039b: e8408a2b00               call   0x798de0
0x4e03a0: 68e0d2bc00               push   0xbcd2e0
0x4e03a5: e8701f3b00               call   0x89231a
0x4e03aa: 83c404                   add    esp,0x4
0x4e03ad: 897dfc                   mov    DWORD PTR [ebp-0x4],edi
0x4e03b0: bfac79fb00               mov    edi,0xfb79ac
0x4e03b5: e836e12000               call   0x6ee4f0
0x4e03ba: 83cfff                   or     edi,0xffffffff
0x4e03bd: 807e1500                 cmp    BYTE PTR [esi+0x15],0x0
0x4e03c1: 753f                     jne    0x4e0402
0x4e03c3: 8b4608                   mov    eax,DWORD PTR [esi+0x8]
0x4e03c6: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e03ca: 7516                     jne    0x4e03e2
0x4e03cc: 8bf0                     mov    esi,eax
0x4e03ce: 8b06                     mov    eax,DWORD PTR [esi]
0x4e03d0: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e03d4: 752c                     jne    0x4e0402
0x4e03d6: 8bf0                     mov    esi,eax
0x4e03d8: 8b06                     mov    eax,DWORD PTR [esi]
0x4e03da: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e03de: 74f6                     je     0x4e03d6
0x4e03e0: eb20                     jmp    0x4e0402
0x4e03e2: 8b4604                   mov    eax,DWORD PTR [esi+0x4]
0x4e03e5: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e03e9: 7515                     jne    0x4e0400
0x4e03eb: eb03                     jmp    0x4e03f0
0x4e03ed: 8d4900                   lea    ecx,[ecx+0x0]
0x4e03f0: 3b7008                   cmp    esi,DWORD PTR [eax+0x8]
0x4e03f3: 750b                     jne    0x4e0400
0x4e03f5: 8bf0                     mov    esi,eax
0x4e03f7: 8b4004                   mov    eax,DWORD PTR [eax+0x4]
0x4e03fa: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e03fe: 74f0                     je     0x4e03f0
0x4e0400: 8bf0                     mov    esi,eax
0x4e0402: 8b5508                   mov    edx,DWORD PTR [ebp+0x8]
0x4e0405: 3b720c                   cmp    esi,DWORD PTR [edx+0xc]
0x4e0408: 0f8522ffffff             jne    0x4e0330
0x4e040e: 8bda                     mov    ebx,edx
0x4e0410: f605e879fb0001           test   BYTE PTR ds:0xfb79e8,0x1
0x4e0417: 7523                     jne    0x4e043c
0x4e0419: 830de879fb0001           or     DWORD PTR ds:0xfb79e8,0x1
0x4e0420: c745fc04000000           mov    DWORD PTR [ebp-0x4],0x4
0x4e0427: e8b4892b00               call   0x798de0
0x4e042c: 68e0d2bc00               push   0xbcd2e0
0x4e0431: e8e41e3b00               call   0x89231a
0x4e0436: 83c404                   add    esp,0x4
0x4e0439: 897dfc                   mov    DWORD PTR [ebp-0x4],edi
0x4e043c: a1e079fb00               mov    eax,ds:0xfb79e0
0x4e0441: 85c0                     test   eax,eax
0x4e0443: 7438                     je     0x4e047d
0x4e0445: 33f6                     xor    esi,esi
0x4e0447: 85c0                     test   eax,eax
0x4e0449: 7421                     je     0x4e046c
0x4e044b: 8b3dd020bd00             mov    edi,DWORD PTR ds:0xbd20d0
0x4e0451: a1b079fb00               mov    eax,ds:0xfb79b0
0x4e0456: 8b0cb0                   mov    ecx,DWORD PTR [eax+esi*4]
0x4e0459: 51                       push   ecx
0x4e045a: ffd7                     call   edi
0x4e045c: a1e079fb00               mov    eax,ds:0xfb79e0
0x4e0461: 46                       inc    esi
0x4e0462: 3bf0                     cmp    esi,eax
0x4e0464: 72eb                     jb     0x4e0451
0x4e0466: 8b5d08                   mov    ebx,DWORD PTR [ebp+0x8]
0x4e0469: 83cfff                   or     edi,0xffffffff
0x4e046c: 8b15c079fb00             mov    edx,DWORD PTR ds:0xfb79c0
0x4e0472: 57                       push   edi
0x4e0473: 6a01                     push   0x1
0x4e0475: 52                       push   edx
0x4e0476: 50                       push   eax
0x4e0477: ff15b422bd00             call   DWORD PTR ds:0xbd22b4
0x4e047d: 33c0                     xor    eax,eax
0x4e047f: f60500b1fa0001           test   BYTE PTR ds:0xfab100,0x1
0x4e0486: a3e079fb00               mov    ds:0xfb79e0,eax
0x4e048b: a3e479fb00               mov    ds:0xfb79e4,eax
0x4e0490: 7523                     jne    0x4e04b5
0x4e0492: 830d00b1fa0001           or     DWORD PTR ds:0xfab100,0x1
0x4e0499: c745fc05000000           mov    DWORD PTR [ebp-0x4],0x5
0x4e04a0: e8fbd1fbff               call   0x49d6a0
0x4e04a5: 6820cebc00               push   0xbcce20
0x4e04aa: e86b1e3b00               call   0x89231a
0x4e04af: 83c404                   add    esp,0x4
0x4e04b2: 897dfc                   mov    DWORD PTR [ebp-0x4],edi
0x4e04b5: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4e04bb: 8b01                     mov    eax,DWORD PTR [ecx]
0x4e04bd: 8b5020                   mov    edx,DWORD PTR [eax+0x20]
0x4e04c0: ffd2                     call   edx
0x4e04c2: 85c0                     test   eax,eax
0x4e04c4: 742c                     je     0x4e04f2
0x4e04c6: a1a4a7fb00               mov    eax,ds:0xfba7a4
0x4e04cb: 83787c00                 cmp    DWORD PTR [eax+0x7c],0x0
0x4e04cf: 7521                     jne    0x4e04f2
0x4e04d1: a11813fb00               mov    eax,ds:0xfb1318
0x4e04d6: 8b881cc00000             mov    ecx,DWORD PTR [eax+0xc01c]
0x4e04dc: d1e9                     shr    ecx,1
0x4e04de: f6c101                   test   cl,0x1
0x4e04e1: 750f                     jne    0x4e04f2
0x4e04e3: f6801cc0000001           test   BYTE PTR [eax+0xc01c],0x1
0x4e04ea: 7506                     jne    0x4e04f2
0x4e04ec: 53                       push   ebx
0x4e04ed: e8de010000               call   0x4e06d0
0x4e04f2: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4e04f8: d9450c                   fld    DWORD PTR [ebp+0xc]
0x4e04fb: 8b11                     mov    edx,DWORD PTR [ecx]
0x4e04fd: 8b4230                   mov    eax,DWORD PTR [edx+0x30]
0x4e0500: 51                       push   ecx
0x4e0501: d91c24                   fstp   DWORD PTR [esp]
0x4e0504: ffd0                     call   eax
0x4e0506: 33c0                     xor    eax,eax
0x4e0508: 8b4df4                   mov    ecx,DWORD PTR [ebp-0xc]
0x4e050b: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4e0512: 59                       pop    ecx
0x4e0513: 5f                       pop    edi
0x4e0514: 5e                       pop    esi
0x4e0515: 5b                       pop    ebx
0x4e0516: 8be5                     mov    esp,ebp
0x4e0518: 5d                       pop    ebp
0x4e0519: c20800                   ret    0x8

; B23 AnimateExecuter virtual callback dispatches object v+24 with delta
; VA [0x4e0520,0x4e053f) SHA256 334b4577534d7d1aa76734352c50067b2082fa72f977b3acb02bc2295acce30e
0x4e0520: 55                       push   ebp
0x4e0521: 8bec                     mov    ebp,esp
0x4e0523: 8bc1                     mov    eax,ecx
0x4e0525: 8b4d08                   mov    ecx,DWORD PTR [ebp+0x8]
0x4e0528: d94004                   fld    DWORD PTR [eax+0x4]
0x4e052b: 8b11                     mov    edx,DWORD PTR [ecx]
0x4e052d: 8b4224                   mov    eax,DWORD PTR [edx+0x24]
0x4e0530: 51                       push   ecx
0x4e0531: d91c24                   fstp   DWORD PTR [esp]
0x4e0534: ffd0                     call   eax
0x4e0536: b801000000               mov    eax,0x1
0x4e053b: 5d                       pop    ebp
0x4e053c: c20400                   ret    0x4

; B24 Worker reads owner+38 callback and stride12 object+8, invokes callback
; VA [0x6ee540,0x6ee59b) SHA256 72948807e456fa0eca08ee26b282e6dae9b55f320a8b0daa96dc9ff56aff5c88
0x6ee540: 55                       push   ebp
0x6ee541: 8bec                     mov    ebp,esp
0x6ee543: 8b4508                   mov    eax,DWORD PTR [ebp+0x8]
0x6ee546: 56                       push   esi
0x6ee547: 8b30                     mov    esi,DWORD PTR [eax]
0x6ee549: 803e00                   cmp    BYTE PTR [esi],0x0
0x6ee54c: 57                       push   edi
0x6ee54d: 8b7804                   mov    edi,DWORD PTR [eax+0x4]
0x6ee550: 7541                     jne    0x6ee593
0x6ee552: 53                       push   ebx
0x6ee553: 8d1c7f                   lea    ebx,[edi+edi*2]
0x6ee556: 03db                     add    ebx,ebx
0x6ee558: 03db                     add    ebx,ebx
0x6ee55a: 8d9b00000000             lea    ebx,[ebx+0x0]
0x6ee560: 8b4604                   mov    eax,DWORD PTR [esi+0x4]
0x6ee563: 8b0cb8                   mov    ecx,DWORD PTR [eax+edi*4]
0x6ee566: 6aff                     push   0xffffffff
0x6ee568: 51                       push   ecx
0x6ee569: ff15fc20bd00             call   DWORD PTR ds:0xbd20fc
0x6ee56f: 8b4e38                   mov    ecx,DWORD PTR [esi+0x38]
0x6ee572: 8b4624                   mov    eax,DWORD PTR [esi+0x24]
0x6ee575: 8b11                     mov    edx,DWORD PTR [ecx]
0x6ee577: 8b440308                 mov    eax,DWORD PTR [ebx+eax*1+0x8]
0x6ee57b: 8b12                     mov    edx,DWORD PTR [edx]
0x6ee57d: 50                       push   eax
0x6ee57e: ffd2                     call   edx
0x6ee580: 8b4614                   mov    eax,DWORD PTR [esi+0x14]
0x6ee583: 8b0cb8                   mov    ecx,DWORD PTR [eax+edi*4]
0x6ee586: 51                       push   ecx
0x6ee587: ff15d020bd00             call   DWORD PTR ds:0xbd20d0
0x6ee58d: 803e00                   cmp    BYTE PTR [esi],0x0
0x6ee590: 74ce                     je     0x6ee560
0x6ee592: 5b                       pop    ebx
0x6ee593: 5f                       pop    edi
0x6ee594: 5e                       pop    esi
0x6ee595: 5d                       pop    ebp
0x6ee596: e9d7761a00               jmp    0x895c72

; B25 Worker constructor tail fixes worker entry 6EE540 and stride12
; VA [0x6ee4b0,0x6ee4e4) SHA256 dff51419d97dc8594fd7175610465f45340d800cdb7a9bc593cbd029cac23a9a
0x6ee4b0: 8b5df4                   mov    ebx,DWORD PTR [ebp-0xc]
0x6ee4b3: 85db                     test   ebx,ebx
0x6ee4b5: 7424                     je     0x6ee4db
0x6ee4b7: 33f6                     xor    esi,esi
0x6ee4b9: 8da42400000000           lea    esp,[esp+0x0]
0x6ee4c0: 8b5724                   mov    edx,DWORD PTR [edi+0x24]
0x6ee4c3: 03d6                     add    edx,esi
0x6ee4c5: 52                       push   edx
0x6ee4c6: 6a00                     push   0x0
0x6ee4c8: 6840e56e00               push   0x6ee540
0x6ee4cd: e867781a00               call   0x895d39
0x6ee4d2: 83c40c                   add    esp,0xc
0x6ee4d5: 83c60c                   add    esi,0xc
0x6ee4d8: 4b                       dec    ebx
0x6ee4d9: 75e5                     jne    0x6ee4c0
0x6ee4db: 5e                       pop    esi
0x6ee4dc: 5b                       pop    ebx
0x6ee4dd: 5f                       pop    edi
0x6ee4de: 8be5                     mov    esp,ebp
0x6ee4e0: 5d                       pop    ebp
0x6ee4e1: c20400                   ret    0x4

; B26 0000 complete generic world object property receiver
; VA [0x4afaf0,0x4afb7a) SHA256 62c0d3c264bcecf78db78c7c358b4850d08c2bed5aa421908681f7b59441c07e
0x4afaf0: 55                       push   ebp
0x4afaf1: 8bec                     mov    ebp,esp
0x4afaf3: 8b450c                   mov    eax,DWORD PTR [ebp+0xc]
0x4afaf6: 83f802                   cmp    eax,0x2
0x4afaf9: 7304                     jae    0x4afaff
0x4afafb: 33d2                     xor    edx,edx
0x4afafd: eb0d                     jmp    0x4afb0c
0x4afaff: 8d48fe                   lea    ecx,[eax-0x2]
0x4afb02: b8abaaaaaa               mov    eax,0xaaaaaaab
0x4afb07: f7e1                     mul    ecx
0x4afb09: c1ea02                   shr    edx,0x2
0x4afb0c: 85d2                     test   edx,edx
0x4afb0e: 7464                     je     0x4afb74
0x4afb10: 53                       push   ebx
0x4afb11: 56                       push   esi
0x4afb12: 8b7508                   mov    esi,DWORD PTR [ebp+0x8]
0x4afb15: 57                       push   edi
0x4afb16: 83c604                   add    esi,0x4
0x4afb19: 8bda                     mov    ebx,edx
0x4afb1b: eb03                     jmp    0x4afb20
0x4afb1d: 8d4900                   lea    ecx,[ecx+0x0]
0x4afb20: 0fb756fe                 movzx  edx,WORD PTR [esi-0x2]
0x4afb24: 89550c                   mov    DWORD PTR [ebp+0xc],edx
0x4afb27: e834f5f5ff               call   0x40f060
0x4afb2c: 8bf8                     mov    edi,eax
0x4afb2e: 8d450c                   lea    eax,[ebp+0xc]
0x4afb31: 50                       push   eax
0x4afb32: 8d4f08                   lea    ecx,[edi+0x8]
0x4afb35: 8d4508                   lea    eax,[ebp+0x8]
0x4afb38: e8c3f33700               call   0x82ef00
0x4afb3d: 8b4508                   mov    eax,DWORD PTR [ebp+0x8]
0x4afb40: 3b470c                   cmp    eax,DWORD PTR [edi+0xc]
0x4afb43: 7407                     je     0x4afb4c
0x4afb45: 8b4810                   mov    ecx,DWORD PTR [eax+0x10]
0x4afb48: 85c9                     test   ecx,ecx
0x4afb4a: 750f                     jne    0x4afb5b
0x4afb4c: 68886ac000               push   0xc06a88
0x4afb51: e80ae02300               call   0x6edb60
0x4afb56: 83c404                   add    esp,0x4
0x4afb59: eb10                     jmp    0x4afb6b
0x4afb5b: 0fb74602                 movzx  eax,WORD PTR [esi+0x2]
0x4afb5f: 8b11                     mov    edx,DWORD PTR [ecx]
0x4afb61: 8b522c                   mov    edx,DWORD PTR [edx+0x2c]
0x4afb64: 50                       push   eax
0x4afb65: 0fb706                   movzx  eax,WORD PTR [esi]
0x4afb68: 50                       push   eax
0x4afb69: ffd2                     call   edx
0x4afb6b: 83c606                   add    esi,0x6
0x4afb6e: 4b                       dec    ebx
0x4afb6f: 75af                     jne    0x4afb20
0x4afb71: 5f                       pop    edi
0x4afb72: 5e                       pop    esi
0x4afb73: 5b                       pop    ebx
0x4afb74: 33c0                     xor    eax,eax
0x4afb76: 5d                       pop    ebp
0x4afb77: c20c00                   ret    0xc

; B27 CMonster property dispatcher and complete branch bodies; data excluded
; VA [0x4d1e10,0x4d1f32) SHA256 9af5daac334b99d0db69a85caa156565106b07525f850a27b1b66d9fae521c5b
0x4d1e10: 55                       push   ebp
0x4d1e11: 8bec                     mov    ebp,esp
0x4d1e13: 56                       push   esi
0x4d1e14: 8bf1                     mov    esi,ecx
0x4d1e16: 0fbf4d08                 movsx  ecx,WORD PTR [ebp+0x8]
0x4d1e1a: 8d41ff                   lea    eax,[ecx-0x1]
0x4d1e1d: 83f81c                   cmp    eax,0x1c
0x4d1e20: 0f87f4000000             ja     0x4d1f1a
0x4d1e26: 0fb6804c1f4d00           movzx  eax,BYTE PTR [eax+0x4d1f4c]
0x4d1e2d: ff2485341f4d00           jmp    DWORD PTR [eax*4+0x4d1f34]
0x4d1e34: 0fbf450c                 movsx  eax,WORD PTR [ebp+0xc]
0x4d1e38: 89450c                   mov    DWORD PTR [ebp+0xc],eax
0x4d1e3b: 8986b0030000             mov    DWORD PTR [esi+0x3b0],eax
0x4d1e41: db450c                   fild   DWORD PTR [ebp+0xc]
0x4d1e44: 8bb668030000             mov    esi,DWORD PTR [esi+0x368]
0x4d1e4a: 56                       push   esi
0x4d1e4b: 8d450c                   lea    eax,[ebp+0xc]
0x4d1e4e: dc0dd856c500             fmul   QWORD PTR ds:0xc556d8
0x4d1e54: c6450c00                 mov    BYTE PTR [ebp+0xc],0x0
0x4d1e58: d95d08                   fstp   DWORD PTR [ebp+0x8]
0x4d1e5b: e870302e00               call   0x7b4ed0
0x4d1e60: d94508                   fld    DWORD PTR [ebp+0x8]
0x4d1e63: 5e                       pop    esi
0x4d1e64: d9580c                   fstp   DWORD PTR [eax+0xc]
0x4d1e67: 5d                       pop    ebp
0x4d1e68: c20800                   ret    0x8
0x4d1e6b: 0fbf4d0c                 movsx  ecx,WORD PTR [ebp+0xc]
0x4d1e6f: 8b9688000000             mov    edx,DWORD PTR [esi+0x88]
0x4d1e75: 898ed4030000             mov    DWORD PTR [esi+0x3d4],ecx
0x4d1e7b: 89550c                   mov    DWORD PTR [ebp+0xc],edx
0x4d1e7e: e8ad34f5ff               call   0x425330
0x4d1e83: 8d550c                   lea    edx,[ebp+0xc]
0x4d1e86: 8bc8                     mov    ecx,eax
0x4d1e88: e8e35b0200               call   0x4f7a70
0x4d1e8d: 83c01c                   add    eax,0x1c
0x4d1e90: 83781408                 cmp    DWORD PTR [eax+0x14],0x8
0x4d1e94: 7202                     jb     0x4d1e98
0x4d1e96: 8b00                     mov    eax,DWORD PTR [eax]
0x4d1e98: 50                       push   eax
0x4d1e99: 8b86d4030000             mov    eax,DWORD PTR [esi+0x3d4]
0x4d1e9f: 50                       push   eax
0x4d1ea0: 6884c9c000               push   0xc0c984
0x4d1ea5: 8d5606                   lea    edx,[esi+0x6]
0x4d1ea8: e833f8ffff               call   0x4d16e0
0x4d1ead: 83c40c                   add    esp,0xc
0x4d1eb0: 5e                       pop    esi
0x4d1eb1: 5d                       pop    ebp
0x4d1eb2: c20800                   ret    0x8
0x4d1eb5: 83be2004000000           cmp    DWORD PTR [esi+0x420],0x0
0x4d1ebc: 0fbf4d0c                 movsx  ecx,WORD PTR [ebp+0xc]
0x4d1ec0: 0f57c0                   xorps  xmm0,xmm0
0x4d1ec3: f30f2ac1                 cvtsi2ss xmm0,ecx
0x4d1ec7: f30f11450c               movss  DWORD PTR [ebp+0xc],xmm0
0x4d1ecc: f30f1186cc000000         movss  DWORD PTR [esi+0xcc],xmm0
0x4d1ed4: 7512                     jne    0x4d1ee8
0x4d1ed6: f30f118694030000         movss  DWORD PTR [esi+0x394],xmm0
0x4d1ede: c7862004000001000000     mov    DWORD PTR [esi+0x420],0x1
0x4d1ee8: d9450c                   fld    DWORD PTR [ebp+0xc]
0x4d1eeb: d8b694030000             fdiv   DWORD PTR [esi+0x394]
0x4d1ef1: d99e98030000             fstp   DWORD PTR [esi+0x398]
0x4d1ef7: 5e                       pop    esi
0x4d1ef8: 5d                       pop    ebp
0x4d1ef9: c20800                   ret    0x8
0x4d1efc: 0fbf550c                 movsx  edx,WORD PTR [ebp+0xc]
0x4d1f00: 8996d0000000             mov    DWORD PTR [esi+0xd0],edx
0x4d1f06: 5e                       pop    esi
0x4d1f07: 5d                       pop    ebp
0x4d1f08: c20800                   ret    0x8
0x4d1f0b: 0fbf450c                 movsx  eax,WORD PTR [ebp+0xc]
0x4d1f0f: 898690000000             mov    DWORD PTR [esi+0x90],eax
0x4d1f15: 5e                       pop    esi
0x4d1f16: 5d                       pop    ebp
0x4d1f17: c20800                   ret    0x8
0x4d1f1a: 0fbf550c                 movsx  edx,WORD PTR [ebp+0xc]
0x4d1f1e: 52                       push   edx
0x4d1f1f: 51                       push   ecx
0x4d1f20: 6898c9c000               push   0xc0c998
0x4d1f25: e836bc2100               call   0x6edb60
0x4d1f2a: 83c40c                   add    esp,0xc
0x4d1f2d: 5e                       pop    esi
0x4d1f2e: 5d                       pop    ebp
0x4d1f2f: c20800                   ret    0x8

; D01 CMonster property jumptable and 29-byte case map
; VA [0x4d1f34,0x4d1f69) bytes 341e4d00fc1e4d00b51e4d006b1e4d000b1f4d001a1f4d000005050501020505050505050505050505050505050503050505050504

; D02 CBullet RTTI COL pointer and exactly25 slots (+00..+60)
; VA [0xc079f8,0xc07a60) bytes 64a9c600d0c04c0040a84c0080a84c00f0c28d0030c74c0050c84c00f0c28d00f0c28d0050c14c0040c54c00f0c64c0050fe4c00d0c54c0060af870030ab4c00b06f4c00d06f4c0080ab4c00c0ac4c00908f4c0000a74c00e0ab4c0070b04c0030b14c0040ad4c00

; D03 CBullet COL points to type descriptor at +12
; VA [0xc6a964,0xc6a978) bytes 00000000000000000000000074e7f70078a9c600

; D04 CBullet RTTI descriptor header and null-terminated name
; VA [0xf7e774,0xf7e789) bytes f435bd00000000002e3f41564342756c6c65744040

; D05 CMonster RTTI COL pointer and methods through +80
; VA [0xc0c9d8,0xc0ca60) bytes 84acc600d0184d00105d5f0080a84c00f0c28d00701f4d00801f4d00f0c28d00f0c28d00e01a4d00f01a4d00901b4d00101e4d0010194d0060804c0030ab4c00b06f4c00d06f4c00908b4c00e08b4c00908f4c00a08f4c00e0ab4c00308c4c00408c4c0040ad4c00901f4d00a08d4c0050954c0040704c0060704c00d08e4c00708f4c00808f4c00

; D06 CMonster COL points to type descriptor at +12
; VA [0xc6ac84,0xc6ac98) bytes 000000000000000000000000acdff70098acc600

; D07 CMonster RTTI descriptor header and null-terminated name
; VA [0xf7dfac,0xf7dfc3) bytes f435bd00000000002e3f4156434d6f6e73746572404000

; D08 AnimateExecuter COL and callback slot
; VA [0xc0cf28,0xc0cf30) bytes c4aec60020054e00

; D09 Milliseconds divisor 1000.0
; VA [0xc557d8,0xc557e0) bytes 0000000000408f40

; D10 Terminal effect ratio threshold ~0.6
; VA [0xc557f0,0xc557f8) bytes 000000403333e33f

; D11 Arc angle multiplier ~3.14
; VA [0xc55a50,0xc55a58) bytes 00000060b81e0940

; R_frame_world_step Revalidated prior world iteration root: selected frame gate and world update call
; VA [0x491ca7,0x491cbb) SHA256 f2e1c84f724d1d0ca56fd7605928a5248207de6e856fcbbdc066fd930dbf13c7
0x491ca7: 39b7ccbf0000             cmp    DWORD PTR [edi+0xbfcc],esi
0x491cad: 7554                     jne    0x491d03
0x491caf: e8acd3f7ff               call   0x40f060
0x491cb4: 8bc8                     mov    ecx,eax
0x491cb6: e8a5e30400               call   0x4e0060

; R_world_step Revalidated prior world iteration root: controller v+2c then world iterator
; VA [0x4e0060,0x4e0200) SHA256 8cf50b64055d957083c02855034d6472735ecde2f2884024d98f8f5b0cf28717
0x4e0060: 55                       push   ebp
0x4e0061: 8bec                     mov    ebp,esp
0x4e0063: 6aff                     push   0xffffffff
0x4e0065: 68bab19300               push   0x93b1ba
0x4e006a: 64a100000000             mov    eax,fs:0x0
0x4e0070: 50                       push   eax
0x4e0071: 83ec20                   sub    esp,0x20
0x4e0074: a1201fd600               mov    eax,ds:0xd61f20
0x4e0079: 33c5                     xor    eax,ebp
0x4e007b: 8945f0                   mov    DWORD PTR [ebp-0x10],eax
0x4e007e: 56                       push   esi
0x4e007f: 57                       push   edi
0x4e0080: 50                       push   eax
0x4e0081: 8d45f4                   lea    eax,[ebp-0xc]
0x4e0084: 64a300000000             mov    fs:0x0,eax
0x4e008a: 8bf9                     mov    edi,ecx
0x4e008c: f30f1087ac000000         movss  xmm0,DWORD PTR [edi+0xac]
0x4e0094: 0f2f056c56c500           comiss xmm0,DWORD PTR ds:0xc5566c
0x4e009b: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4e00a1: be01000000               mov    esi,0x1
0x4e00a6: 7603                     jbe    0x4e00ab
0x4e00a8: 897158                   mov    DWORD PTR [ecx+0x58],esi
0x4e00ab: 8b01                     mov    eax,DWORD PTR [ecx]
0x4e00ad: 8b502c                   mov    edx,DWORD PTR [eax+0x2c]
0x4e00b0: ffd2                     call   edx
0x4e00b2: 8b470c                   mov    eax,DWORD PTR [edi+0xc]
0x4e00b5: 8b08                     mov    ecx,DWORD PTR [eax]
0x4e00b7: c645d400                 mov    BYTE PTR [ebp-0x2c],0x0
0x4e00bb: 8b55d4                   mov    edx,DWORD PTR [ebp-0x2c]
0x4e00be: 52                       push   edx
0x4e00bf: 50                       push   eax
0x4e00c0: 51                       push   ecx
0x4e00c1: e82a130000               call   0x4e13f0
0x4e00c6: 83c40c                   add    esp,0xc
0x4e00c9: f605b873fb0001           test   BYTE PTR ds:0xfb73b8,0x1
0x4e00d0: 7526                     jne    0x4e00f8
0x4e00d2: 0935b873fb00             or     DWORD PTR ds:0xfb73b8,esi
0x4e00d8: c745fc00000000           mov    DWORD PTR [ebp-0x4],0x0
0x4e00df: e88c000800               call   0x560170
0x4e00e4: 6810d1bc00               push   0xbcd110
0x4e00e9: e82c223b00               call   0x89231a
0x4e00ee: 83c404                   add    esp,0x4
0x4e00f1: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e00f8: 833de873fb0000           cmp    DWORD PTR ds:0xfb73e8,0x0
0x4e00ff: 0f84cd000000             je     0x4e01d2
0x4e0105: f605d4b0fa0001           test   BYTE PTR ds:0xfab0d4,0x1
0x4e010c: 7522                     jne    0x4e0130
0x4e010e: 0935d4b0fa00             or     DWORD PTR ds:0xfab0d4,esi
0x4e0114: 8975fc                   mov    DWORD PTR [ebp-0x4],esi
0x4e0117: e884a23200               call   0x80a3a0
0x4e011c: 68d0cdbc00               push   0xbccdd0
0x4e0121: e8f4213b00               call   0x89231a
0x4e0126: 83c404                   add    esp,0x4
0x4e0129: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e0130: 833d90b0fa0000           cmp    DWORD PTR ds:0xfab090,0x0
0x4e0137: 7521                     jne    0x4e015a
0x4e0139: 8b0d28b0fa00             mov    ecx,DWORD PTR ds:0xfab028
0x4e013f: 85c9                     test   ecx,ecx
0x4e0141: 7417                     je     0x4e015a
0x4e0143: 8b01                     mov    eax,DWORD PTR [ecx]
0x4e0145: 8b5020                   mov    edx,DWORD PTR [eax+0x20]
0x4e0148: ffd2                     call   edx
0x4e014a: a390b0fa00               mov    ds:0xfab090,eax
0x4e014f: 8b10                     mov    edx,DWORD PTR [eax]
0x4e0151: 8bc8                     mov    ecx,eax
0x4e0153: 8b4218                   mov    eax,DWORD PTR [edx+0x18]
0x4e0156: 6a03                     push   0x3
0x4e0158: ffd0                     call   eax
0x4e015a: f605e879fb0001           test   BYTE PTR ds:0xfb79e8,0x1
0x4e0161: 8b3590b0fa00             mov    esi,DWORD PTR ds:0xfab090
0x4e0167: 7527                     jne    0x4e0190
0x4e0169: 830de879fb0001           or     DWORD PTR ds:0xfb79e8,0x1
0x4e0170: c745fc02000000           mov    DWORD PTR [ebp-0x4],0x2
0x4e0177: e8648c2b00               call   0x798de0
0x4e017c: 68e0d2bc00               push   0xbcd2e0
0x4e0181: e894213b00               call   0x89231a
0x4e0186: 83c404                   add    esp,0x4
0x4e0189: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e0190: a1e876fb00               mov    eax,ds:0xfb76e8
0x4e0195: 8b480c                   mov    ecx,DWORD PTR [eax+0xc]
0x4e0198: 8b5010                   mov    edx,DWORD PTR [eax+0x10]
0x4e019b: 8b4014                   mov    eax,DWORD PTR [eax+0x14]
0x4e019e: 894dd8                   mov    DWORD PTR [ebp-0x28],ecx
0x4e01a1: d945d8                   fld    DWORD PTR [ebp-0x28]
0x4e01a4: dd059858c500             fld    QWORD PTR ds:0xc55898
0x4e01aa: 8955dc                   mov    DWORD PTR [ebp-0x24],edx
0x4e01ad: dcc9                     fmul   st(1),st
0x4e01af: 8945e0                   mov    DWORD PTR [ebp-0x20],eax
0x4e01b2: d9c9                     fxch   st(1)
0x4e01b4: 8d45e4                   lea    eax,[ebp-0x1c]
0x4e01b7: 50                       push   eax
0x4e01b8: d95de4                   fstp   DWORD PTR [ebp-0x1c]
0x4e01bb: 8bce                     mov    ecx,esi
0x4e01bd: d945dc                   fld    DWORD PTR [ebp-0x24]
0x4e01c0: d8c9                     fmul   st,st(1)
0x4e01c2: d95de8                   fstp   DWORD PTR [ebp-0x18]
0x4e01c5: d84de0                   fmul   DWORD PTR [ebp-0x20]
0x4e01c8: d95dec                   fstp   DWORD PTR [ebp-0x14]
0x4e01cb: 8b16                     mov    edx,DWORD PTR [esi]
0x4e01cd: 8b520c                   mov    edx,DWORD PTR [edx+0xc]
0x4e01d0: ffd2                     call   edx
0x4e01d2: 81c7d0000000             add    edi,0xd0
0x4e01d8: 57                       push   edi
0x4e01d9: e8f26c1f00               call   0x6d6ed0
0x4e01de: 33c0                     xor    eax,eax
0x4e01e0: 8b4df4                   mov    ecx,DWORD PTR [ebp-0xc]
0x4e01e3: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4e01ea: 59                       pop    ecx
0x4e01eb: 5f                       pop    edi
0x4e01ec: 5e                       pop    esi
0x4e01ed: 8b4df0                   mov    ecx,DWORD PTR [ebp-0x10]
0x4e01f0: 33cd                     xor    ecx,ebp
0x4e01f2: e80a0e3b00               call   0x891001
0x4e01f7: 8be5                     mov    esp,ebp
0x4e01f9: 5d                       pop    ebp
0x4e01fa: c3                       ret
0x4e01fb: cc                       int3
0x4e01fc: cc                       int3
0x4e01fd: cc                       int3
0x4e01fe: cc                       int3
0x4e01ff: cc                       int3

; R_world_step_iterator Revalidated prior world iteration root: node+10 actor v+20
; VA [0x4e13f0,0x4e1470) SHA256 1762a085a3d6f2434308d86ffa0b51664501f96c3cb62220685b8f8653bb584e
0x4e13f0: 55                       push   ebp
0x4e13f1: 8bec                     mov    ebp,esp
0x4e13f3: 8b4d08                   mov    ecx,DWORD PTR [ebp+0x8]
0x4e13f6: 3b4d0c                   cmp    ecx,DWORD PTR [ebp+0xc]
0x4e13f9: 7462                     je     0x4e145d
0x4e13fb: eb03                     jmp    0x4e1400
0x4e13fd: 8d4900                   lea    ecx,[ecx+0x0]
0x4e1400: 8b4910                   mov    ecx,DWORD PTR [ecx+0x10]
0x4e1403: 8b01                     mov    eax,DWORD PTR [ecx]
0x4e1405: 8b5020                   mov    edx,DWORD PTR [eax+0x20]
0x4e1408: ffd2                     call   edx
0x4e140a: 8b4d08                   mov    ecx,DWORD PTR [ebp+0x8]
0x4e140d: 80791500                 cmp    BYTE PTR [ecx+0x15],0x0
0x4e1411: 7545                     jne    0x4e1458
0x4e1413: 8b4108                   mov    eax,DWORD PTR [ecx+0x8]
0x4e1416: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e141a: 7516                     jne    0x4e1432
0x4e141c: 8bc8                     mov    ecx,eax
0x4e141e: 8b01                     mov    eax,DWORD PTR [ecx]
0x4e1420: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e1424: 752f                     jne    0x4e1455
0x4e1426: 8bc8                     mov    ecx,eax
0x4e1428: 8b01                     mov    eax,DWORD PTR [ecx]
0x4e142a: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e142e: 74f6                     je     0x4e1426
0x4e1430: eb23                     jmp    0x4e1455
0x4e1432: 8b4104                   mov    eax,DWORD PTR [ecx+0x4]
0x4e1435: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e1439: 7518                     jne    0x4e1453
0x4e143b: eb03                     jmp    0x4e1440
0x4e143d: 8d4900                   lea    ecx,[ecx+0x0]
0x4e1440: 3b4808                   cmp    ecx,DWORD PTR [eax+0x8]
0x4e1443: 750e                     jne    0x4e1453
0x4e1445: 8bc8                     mov    ecx,eax
0x4e1447: 894d08                   mov    DWORD PTR [ebp+0x8],ecx
0x4e144a: 8b4004                   mov    eax,DWORD PTR [eax+0x4]
0x4e144d: 80781500                 cmp    BYTE PTR [eax+0x15],0x0
0x4e1451: 74ed                     je     0x4e1440
0x4e1453: 8bc8                     mov    ecx,eax
0x4e1455: 894d08                   mov    DWORD PTR [ebp+0x8],ecx
0x4e1458: 3b4d0c                   cmp    ecx,DWORD PTR [ebp+0xc]
0x4e145b: 75a3                     jne    0x4e1400
0x4e145d: 8a4510                   mov    al,BYTE PTR [ebp+0x10]
0x4e1460: 5d                       pop    ebp
0x4e1461: c3                       ret
0x4e1462: cc                       int3
0x4e1463: cc                       int3
0x4e1464: cc                       int3
0x4e1465: cc                       int3
0x4e1466: cc                       int3
0x4e1467: cc                       int3
0x4e1468: cc                       int3
0x4e1469: cc                       int3
0x4e146a: cc                       int3
0x4e146b: cc                       int3
0x4e146c: cc                       int3
0x4e146d: cc                       int3
0x4e146e: cc                       int3
0x4e146f: cc                       int3

; B28 Blt2 parser complete; Type/File/Time/Radius/Curve and typed record writes
; VA [0x82bb00,0x82c2a5) SHA256 911cc33fbaa13a3d8426a1c1cad6239a8f94848236faf25fa56d104449aba2cf
0x82bb00: 55                       push   ebp
0x82bb01: 8bec                     mov    ebp,esp
0x82bb03: 6aff                     push   0xffffffff
0x82bb05: 68865b9200               push   0x925b86
0x82bb0a: 64a100000000             mov    eax,fs:0x0
0x82bb10: 50                       push   eax
0x82bb11: 81ec68010000             sub    esp,0x168
0x82bb17: a1201fd600               mov    eax,ds:0xd61f20
0x82bb1c: 33c5                     xor    eax,ebp
0x82bb1e: 8945ec                   mov    DWORD PTR [ebp-0x14],eax
0x82bb21: 53                       push   ebx
0x82bb22: 56                       push   esi
0x82bb23: 57                       push   edi
0x82bb24: 50                       push   eax
0x82bb25: 8d45f4                   lea    eax,[ebp-0xc]
0x82bb28: 64a300000000             mov    fs:0x0,eax
0x82bb2e: 8b4508                   mov    eax,DWORD PTR [ebp+0x8]
0x82bb31: 8d8dacfeffff             lea    ecx,[ebp-0x154]
0x82bb37: 51                       push   ecx
0x82bb38: b97857c000               mov    ecx,0xc05778
0x82bb3d: 8985a4feffff             mov    DWORD PTR [ebp-0x15c],eax
0x82bb43: e8e832f0ff               call   0x72ee30
0x82bb48: 33db                     xor    ebx,ebx
0x82bb4a: 895dfc                   mov    DWORD PTR [ebp-0x4],ebx
0x82bb4d: 8b8dccfeffff             mov    ecx,DWORD PTR [ebp-0x134]
0x82bb53: bf10000000               mov    edi,0x10
0x82bb58: 39bde0feffff             cmp    DWORD PTR [ebp-0x120],edi
0x82bb5e: 7306                     jae    0x82bb66
0x82bb60: 8d8dccfeffff             lea    ecx,[ebp-0x134]
0x82bb66: 53                       push   ebx
0x82bb67: 8db5acfeffff             lea    esi,[ebp-0x154]
0x82bb6d: e89e35f0ff               call   0x72f110
0x82bb72: 84c0                     test   al,al
0x82bb74: 0f84c2060000             je     0x82c23c
0x82bb7a: bff837c500               mov    edi,0xc537f8
0x82bb7f: 8bc6                     mov    eax,esi
0x82bb81: e8da27f0ff               call   0x72e360
0x82bb86: bf0438c500               mov    edi,0xc53804
0x82bb8b: e8d027f0ff               call   0x72e360
0x82bb90: 8985a0feffff             mov    DWORD PTR [ebp-0x160],eax
0x82bb96: 3bc3                     cmp    eax,ebx
0x82bb98: 0f844d060000             je     0x82c1eb
0x82bb9e: 8b95a4feffff             mov    edx,DWORD PTR [ebp-0x15c]
0x82bba4: 83c204                   add    edx,0x4
0x82bba7: 899598feffff             mov    DWORD PTR [ebp-0x168],edx
0x82bbad: 8d4900                   lea    ecx,[ecx+0x0]
0x82bbb0: 8bb5a0feffff             mov    esi,DWORD PTR [ebp-0x160]
0x82bbb6: bf6cd6c000               mov    edi,0xc0d66c
0x82bbbb: 8bc6                     mov    eax,esi
0x82bbbd: e89e27f0ff               call   0x72e360
0x82bbc2: 898594feffff             mov    DWORD PTR [ebp-0x16c],eax
0x82bbc8: bf982bc500               mov    edi,0xc52b98
0x82bbcd: 8bc6                     mov    eax,esi
0x82bbcf: e88c27f0ff               call   0x72e360
0x82bbd4: 898590feffff             mov    DWORD PTR [ebp-0x170],eax
0x82bbda: bf0c38c500               mov    edi,0xc5380c
0x82bbdf: 8bc6                     mov    eax,esi
0x82bbe1: e87a27f0ff               call   0x72e360
0x82bbe6: 89859cfeffff             mov    DWORD PTR [ebp-0x164],eax
0x82bbec: bfcc11c400               mov    edi,0xc411cc
0x82bbf1: 8bc6                     mov    eax,esi
0x82bbf3: e86827f0ff               call   0x72e360
0x82bbf8: d9ee                     fldz
0x82bbfa: d95598                   fst    DWORD PTR [ebp-0x68]
0x82bbfd: 8985a4feffff             mov    DWORD PTR [ebp-0x15c],eax
0x82bc03: d9559c                   fst    DWORD PTR [ebp-0x64]
0x82bc06: 33c0                     xor    eax,eax
0x82bc08: d955a0                   fst    DWORD PTR [ebp-0x60]
0x82bc0b: 66898524ffffff           mov    WORD PTR [ebp-0xdc],ax
0x82bc12: d9055059c500             fld    DWORD PTR ds:0xc55950
0x82bc18: b80f000000               mov    eax,0xf
0x82bc1d: d95da4                   fstp   DWORD PTR [ebp-0x5c]
0x82bc20: 89853cffffff             mov    DWORD PTR [ebp-0xc4],eax
0x82bc26: 899d38ffffff             mov    DWORD PTR [ebp-0xc8],ebx
0x82bc2c: 889d28ffffff             mov    BYTE PTR [ebp-0xd8],bl
0x82bc32: d955ac                   fst    DWORD PTR [ebp-0x54]
0x82bc35: 898558ffffff             mov    DWORD PTR [ebp-0xa8],eax
0x82bc3b: d95db0                   fstp   DWORD PTR [ebp-0x50]
0x82bc3e: 899d54ffffff             mov    DWORD PTR [ebp-0xac],ebx
0x82bc44: 889d44ffffff             mov    BYTE PTR [ebp-0xbc],bl
0x82bc4a: 898574ffffff             mov    DWORD PTR [ebp-0x8c],eax
0x82bc50: 899d70ffffff             mov    DWORD PTR [ebp-0x90],ebx
0x82bc56: 889d60ffffff             mov    BYTE PTR [ebp-0xa0],bl
0x82bc5c: 894590                   mov    DWORD PTR [ebp-0x70],eax
0x82bc5f: 895d8c                   mov    DWORD PTR [ebp-0x74],ebx
0x82bc62: 889d7cffffff             mov    BYTE PTR [ebp-0x84],bl
0x82bc68: c745a802000000           mov    DWORD PTR [ebp-0x58],0x2
0x82bc6f: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x82bc73: 6a04                     push   0x4
0x82bc75: 681438c500               push   0xc53814
0x82bc7a: 8d4dd0                   lea    ecx,[ebp-0x30]
0x82bc7d: 8945e4                   mov    DWORD PTR [ebp-0x1c],eax
0x82bc80: 895de0                   mov    DWORD PTR [ebp-0x20],ebx
0x82bc83: 885dd0                   mov    BYTE PTR [ebp-0x30],bl
0x82bc86: e8e56dbdff               call   0x402a70
0x82bc8b: 8b8da0feffff             mov    ecx,DWORD PTR [ebp-0x160]
0x82bc91: 687523bf00               push   0xbf2375
0x82bc96: 8d45d0                   lea    eax,[ebp-0x30]
0x82bc99: 8d75b4                   lea    esi,[ebp-0x4c]
0x82bc9c: c645fc02                 mov    BYTE PTR [ebp-0x4],0x2
0x82bca0: e84b30f0ff               call   0x72ecf0
0x82bca5: 50                       push   eax
0x82bca6: 8d8d44ffffff             lea    ecx,[ebp-0xbc]
0x82bcac: c645fc03                 mov    BYTE PTR [ebp-0x4],0x3
0x82bcb0: e8fb6ebdff               call   0x402bb0
0x82bcb5: 837dc810                 cmp    DWORD PTR [ebp-0x38],0x10
0x82bcb9: 720c                     jb     0x82bcc7
0x82bcbb: 8b4db4                   mov    ecx,DWORD PTR [ebp-0x4c]
0x82bcbe: 51                       push   ecx
0x82bcbf: e848550600               call   0x89120c
0x82bcc4: 83c404                   add    esp,0x4
0x82bcc7: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x82bccb: 837de410                 cmp    DWORD PTR [ebp-0x1c],0x10
0x82bccf: c745c80f000000           mov    DWORD PTR [ebp-0x38],0xf
0x82bcd6: 895dc4                   mov    DWORD PTR [ebp-0x3c],ebx
0x82bcd9: 885db4                   mov    BYTE PTR [ebp-0x4c],bl
0x82bcdc: 720c                     jb     0x82bcea
0x82bcde: 8b55d0                   mov    edx,DWORD PTR [ebp-0x30]
0x82bce1: 52                       push   edx
0x82bce2: e825550600               call   0x89120c
0x82bce7: 83c404                   add    esp,0x4
0x82bcea: 8bbda0feffff             mov    edi,DWORD PTR [ebp-0x160]
0x82bcf0: 8bb794000000             mov    esi,DWORD PTR [edi+0x94]
0x82bcf6: 83c744                   add    edi,0x44
0x82bcf9: 3bf7                     cmp    esi,edi
0x82bcfb: 742b                     je     0x82bd28
0x82bcfd: 8d4900                   lea    ecx,[ecx+0x0]
0x82bd00: 837e2810                 cmp    DWORD PTR [esi+0x28],0x10
0x82bd04: 8d4614                   lea    eax,[esi+0x14]
0x82bd07: 7202                     jb     0x82bd0b
0x82bd09: 8b00                     mov    eax,DWORD PTR [eax]
0x82bd0b: 68b808c400               push   0xc408b8
0x82bd10: 50                       push   eax
0x82bd11: e89b7f0600               call   0x893cb1
0x82bd16: 83c408                   add    esp,0x8
0x82bd19: 85c0                     test   eax,eax
0x82bd1b: 0f8425030000             je     0x82c046
0x82bd21: 8b7650                   mov    esi,DWORD PTR [esi+0x50]
0x82bd24: 3bf7                     cmp    esi,edi
0x82bd26: 75d8                     jne    0x82bd00
0x82bd28: 33c0                     xor    eax,eax
0x82bd2a: 66898524ffffff           mov    WORD PTR [ebp-0xdc],ax
0x82bd31: 8b7750                   mov    esi,DWORD PTR [edi+0x50]
0x82bd34: 3bf7                     cmp    esi,edi
0x82bd36: 7428                     je     0x82bd60
0x82bd38: 837e2810                 cmp    DWORD PTR [esi+0x28],0x10
0x82bd3c: 8d4614                   lea    eax,[esi+0x14]
0x82bd3f: 7202                     jb     0x82bd43
0x82bd41: 8b00                     mov    eax,DWORD PTR [eax]
0x82bd43: 680405c500               push   0xc50504
0x82bd48: 50                       push   eax
0x82bd49: e8637f0600               call   0x893cb1
0x82bd4e: 83c408                   add    esp,0x8
0x82bd51: 85c0                     test   eax,eax
0x82bd53: 0f8416030000             je     0x82c06f
0x82bd59: 8b7650                   mov    esi,DWORD PTR [esi+0x50]
0x82bd5c: 3bf7                     cmp    esi,edi
0x82bd5e: 75d8                     jne    0x82bd38
0x82bd60: d9ee                     fldz
0x82bd62: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82bd68: d985a8feffff             fld    DWORD PTR [ebp-0x158]
0x82bd6e: 6a0a                     push   0xa
0x82bd70: 681c38c500               push   0xc5381c
0x82bd75: d95d98                   fstp   DWORD PTR [ebp-0x68]
0x82bd78: 8d4dd0                   lea    ecx,[ebp-0x30]
0x82bd7b: c745e40f000000           mov    DWORD PTR [ebp-0x1c],0xf
0x82bd82: 895de0                   mov    DWORD PTR [ebp-0x20],ebx
0x82bd85: 885dd0                   mov    BYTE PTR [ebp-0x30],bl
0x82bd88: e8e36cbdff               call   0x402a70
0x82bd8d: 8bbd94feffff             mov    edi,DWORD PTR [ebp-0x16c]
0x82bd93: 687523bf00               push   0xbf2375
0x82bd98: 8d45d0                   lea    eax,[ebp-0x30]
0x82bd9b: 8d75b4                   lea    esi,[ebp-0x4c]
0x82bd9e: 8bcf                     mov    ecx,edi
0x82bda0: c645fc04                 mov    BYTE PTR [ebp-0x4],0x4
0x82bda4: e8472ff0ff               call   0x72ecf0
0x82bda9: 50                       push   eax
0x82bdaa: 8d8d28ffffff             lea    ecx,[ebp-0xd8]
0x82bdb0: c645fc05                 mov    BYTE PTR [ebp-0x4],0x5
0x82bdb4: e8f76dbdff               call   0x402bb0
0x82bdb9: 837dc810                 cmp    DWORD PTR [ebp-0x38],0x10
0x82bdbd: 720c                     jb     0x82bdcb
0x82bdbf: 8b45b4                   mov    eax,DWORD PTR [ebp-0x4c]
0x82bdc2: 50                       push   eax
0x82bdc3: e844540600               call   0x89120c
0x82bdc8: 83c404                   add    esp,0x4
0x82bdcb: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x82bdcf: 837de410                 cmp    DWORD PTR [ebp-0x1c],0x10
0x82bdd3: c745c80f000000           mov    DWORD PTR [ebp-0x38],0xf
0x82bdda: 895dc4                   mov    DWORD PTR [ebp-0x3c],ebx
0x82bddd: 885db4                   mov    BYTE PTR [ebp-0x4c],bl
0x82bde0: 720c                     jb     0x82bdee
0x82bde2: 8b4dd0                   mov    ecx,DWORD PTR [ebp-0x30]
0x82bde5: 51                       push   ecx
0x82bde6: e821540600               call   0x89120c
0x82bdeb: 83c404                   add    esp,0x4
0x82bdee: 6a15                     push   0x15
0x82bdf0: 682838c500               push   0xc53828
0x82bdf5: 8d4dd0                   lea    ecx,[ebp-0x30]
0x82bdf8: c745e40f000000           mov    DWORD PTR [ebp-0x1c],0xf
0x82bdff: 895de0                   mov    DWORD PTR [ebp-0x20],ebx
0x82be02: 885dd0                   mov    BYTE PTR [ebp-0x30],bl
0x82be05: e8666cbdff               call   0x402a70
0x82be0a: 687523bf00               push   0xbf2375
0x82be0f: 8d45d0                   lea    eax,[ebp-0x30]
0x82be12: 8d75b4                   lea    esi,[ebp-0x4c]
0x82be15: 8bcf                     mov    ecx,edi
0x82be17: c645fc06                 mov    BYTE PTR [ebp-0x4],0x6
0x82be1b: e8d02ef0ff               call   0x72ecf0
0x82be20: 50                       push   eax
0x82be21: 8d8d60ffffff             lea    ecx,[ebp-0xa0]
0x82be27: c645fc07                 mov    BYTE PTR [ebp-0x4],0x7
0x82be2b: e8806dbdff               call   0x402bb0
0x82be30: 837dc810                 cmp    DWORD PTR [ebp-0x38],0x10
0x82be34: 720c                     jb     0x82be42
0x82be36: 8b55b4                   mov    edx,DWORD PTR [ebp-0x4c]
0x82be39: 52                       push   edx
0x82be3a: e8cd530600               call   0x89120c
0x82be3f: 83c404                   add    esp,0x4
0x82be42: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x82be46: 837de410                 cmp    DWORD PTR [ebp-0x1c],0x10
0x82be4a: c745c80f000000           mov    DWORD PTR [ebp-0x38],0xf
0x82be51: 895dc4                   mov    DWORD PTR [ebp-0x3c],ebx
0x82be54: 885db4                   mov    BYTE PTR [ebp-0x4c],bl
0x82be57: 720c                     jb     0x82be65
0x82be59: 8b45d0                   mov    eax,DWORD PTR [ebp-0x30]
0x82be5c: 50                       push   eax
0x82be5d: e8aa530600               call   0x89120c
0x82be62: 83c404                   add    esp,0x4
0x82be65: 6a0c                     push   0xc
0x82be67: 684038c500               push   0xc53840
0x82be6c: 8d4dd0                   lea    ecx,[ebp-0x30]
0x82be6f: c745e40f000000           mov    DWORD PTR [ebp-0x1c],0xf
0x82be76: 895de0                   mov    DWORD PTR [ebp-0x20],ebx
0x82be79: 885dd0                   mov    BYTE PTR [ebp-0x30],bl
0x82be7c: e8ef6bbdff               call   0x402a70
0x82be81: 687523bf00               push   0xbf2375
0x82be86: 8d45d0                   lea    eax,[ebp-0x30]
0x82be89: 8d75b4                   lea    esi,[ebp-0x4c]
0x82be8c: 8bcf                     mov    ecx,edi
0x82be8e: c645fc08                 mov    BYTE PTR [ebp-0x4],0x8
0x82be92: e8592ef0ff               call   0x72ecf0
0x82be97: 50                       push   eax
0x82be98: 8d8d7cffffff             lea    ecx,[ebp-0x84]
0x82be9e: c645fc09                 mov    BYTE PTR [ebp-0x4],0x9
0x82bea2: e8096dbdff               call   0x402bb0
0x82bea7: 837dc810                 cmp    DWORD PTR [ebp-0x38],0x10
0x82beab: 720c                     jb     0x82beb9
0x82bead: 8b4db4                   mov    ecx,DWORD PTR [ebp-0x4c]
0x82beb0: 51                       push   ecx
0x82beb1: e856530600               call   0x89120c
0x82beb6: 83c404                   add    esp,0x4
0x82beb9: be0f000000               mov    esi,0xf
0x82bebe: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x82bec2: 837de410                 cmp    DWORD PTR [ebp-0x1c],0x10
0x82bec6: 8975c8                   mov    DWORD PTR [ebp-0x38],esi
0x82bec9: 895dc4                   mov    DWORD PTR [ebp-0x3c],ebx
0x82becc: 885db4                   mov    BYTE PTR [ebp-0x4c],bl
0x82becf: 720c                     jb     0x82bedd
0x82bed1: 8b55d0                   mov    edx,DWORD PTR [ebp-0x30]
0x82bed4: 52                       push   edx
0x82bed5: e832530600               call   0x89120c
0x82beda: 83c404                   add    esp,0x4
0x82bedd: 8bbd90feffff             mov    edi,DWORD PTR [ebp-0x170]
0x82bee3: 83c744                   add    edi,0x44
0x82bee6: 8975e4                   mov    DWORD PTR [ebp-0x1c],esi
0x82bee9: 8b7750                   mov    esi,DWORD PTR [edi+0x50]
0x82beec: 895de0                   mov    DWORD PTR [ebp-0x20],ebx
0x82beef: 885dd0                   mov    BYTE PTR [ebp-0x30],bl
0x82bef2: 3bf7                     cmp    esi,edi
0x82bef4: 7428                     je     0x82bf1e
0x82bef6: 837e2810                 cmp    DWORD PTR [esi+0x28],0x10
0x82befa: 8d4614                   lea    eax,[esi+0x14]
0x82befd: 7202                     jb     0x82bf01
0x82beff: 8b00                     mov    eax,DWORD PTR [eax]
0x82bf01: 685038c500               push   0xc53850
0x82bf06: 50                       push   eax
0x82bf07: e8a57d0600               call   0x893cb1
0x82bf0c: 83c408                   add    esp,0x8
0x82bf0f: 85c0                     test   eax,eax
0x82bf11: 0f8487010000             je     0x82c09e
0x82bf17: 8b7650                   mov    esi,DWORD PTR [esi+0x50]
0x82bf1a: 3bf7                     cmp    esi,edi
0x82bf1c: 75d8                     jne    0x82bef6
0x82bf1e: d9ee                     fldz
0x82bf20: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82bf26: d985a8feffff             fld    DWORD PTR [ebp-0x158]
0x82bf2c: d95da0                   fstp   DWORD PTR [ebp-0x60]
0x82bf2f: 8b7750                   mov    esi,DWORD PTR [edi+0x50]
0x82bf32: 3bf7                     cmp    esi,edi
0x82bf34: 7428                     je     0x82bf5e
0x82bf36: 837e2810                 cmp    DWORD PTR [esi+0x28],0x10
0x82bf3a: 8d4614                   lea    eax,[esi+0x14]
0x82bf3d: 7202                     jb     0x82bf41
0x82bf3f: 8b00                     mov    eax,DWORD PTR [eax]
0x82bf41: 685c38c500               push   0xc5385c
0x82bf46: 50                       push   eax
0x82bf47: e8657d0600               call   0x893cb1
0x82bf4c: 83c408                   add    esp,0x8
0x82bf4f: 85c0                     test   eax,eax
0x82bf51: 0f8476010000             je     0x82c0cd
0x82bf57: 8b7650                   mov    esi,DWORD PTR [esi+0x50]
0x82bf5a: 3bf7                     cmp    esi,edi
0x82bf5c: 75d8                     jne    0x82bf36
0x82bf5e: d9ee                     fldz
0x82bf60: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82bf66: 8bbd9cfeffff             mov    edi,DWORD PTR [ebp-0x164]
0x82bf6c: d985a8feffff             fld    DWORD PTR [ebp-0x158]
0x82bf72: 83c744                   add    edi,0x44
0x82bf75: d95d9c                   fstp   DWORD PTR [ebp-0x64]
0x82bf78: 8b7750                   mov    esi,DWORD PTR [edi+0x50]
0x82bf7b: 3bf7                     cmp    esi,edi
0x82bf7d: 7428                     je     0x82bfa7
0x82bf7f: 837e2810                 cmp    DWORD PTR [esi+0x28],0x10
0x82bf83: 8d4614                   lea    eax,[esi+0x14]
0x82bf86: 7202                     jb     0x82bf8a
0x82bf88: 8b00                     mov    eax,DWORD PTR [eax]
0x82bf8a: 680c38c500               push   0xc5380c
0x82bf8f: 50                       push   eax
0x82bf90: e81c7d0600               call   0x893cb1
0x82bf95: 83c408                   add    esp,0x8
0x82bf98: 85c0                     test   eax,eax
0x82bf9a: 0f845c010000             je     0x82c0fc
0x82bfa0: 8b7650                   mov    esi,DWORD PTR [esi+0x50]
0x82bfa3: 3bf7                     cmp    esi,edi
0x82bfa5: 75d8                     jne    0x82bf7f
0x82bfa7: d9ee                     fldz
0x82bfa9: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82bfaf: d985a8feffff             fld    DWORD PTR [ebp-0x158]
0x82bfb5: d95dac                   fstp   DWORD PTR [ebp-0x54]
0x82bfb8: 8b7750                   mov    esi,DWORD PTR [edi+0x50]
0x82bfbb: 3bf7                     cmp    esi,edi
0x82bfbd: 7428                     je     0x82bfe7
0x82bfbf: 837e2810                 cmp    DWORD PTR [esi+0x28],0x10
0x82bfc3: 8d4614                   lea    eax,[esi+0x14]
0x82bfc6: 7202                     jb     0x82bfca
0x82bfc8: 8b00                     mov    eax,DWORD PTR [eax]
0x82bfca: 686838c500               push   0xc53868
0x82bfcf: 50                       push   eax
0x82bfd0: e8dc7c0600               call   0x893cb1
0x82bfd5: 83c408                   add    esp,0x8
0x82bfd8: 85c0                     test   eax,eax
0x82bfda: 0f844b010000             je     0x82c12b
0x82bfe0: 8b7650                   mov    esi,DWORD PTR [esi+0x50]
0x82bfe3: 3bf7                     cmp    esi,edi
0x82bfe5: 75d8                     jne    0x82bfbf
0x82bfe7: d9ee                     fldz
0x82bfe9: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82bfef: d985a8feffff             fld    DWORD PTR [ebp-0x158]
0x82bff5: d95db0                   fstp   DWORD PTR [ebp-0x50]
0x82bff8: 399da4feffff             cmp    DWORD PTR [ebp-0x15c],ebx
0x82bffe: 0f849b010000             je     0x82c19f
0x82c004: 8bbda4feffff             mov    edi,DWORD PTR [ebp-0x15c]
0x82c00a: 83c744                   add    edi,0x44
0x82c00d: 680c08c500               push   0xc5080c
0x82c012: e88940f0ff               call   0x7300a0
0x82c017: 3bc3                     cmp    eax,ebx
0x82c019: 0f843b010000             je     0x82c15a
0x82c01f: 83c030                   add    eax,0x30
0x82c022: 83781410                 cmp    DWORD PTR [eax+0x14],0x10
0x82c026: 7202                     jb     0x82c02a
0x82c028: 8b00                     mov    eax,DWORD PTR [eax]
0x82c02a: 3bc3                     cmp    eax,ebx
0x82c02c: 0f8428010000             je     0x82c15a
0x82c032: 50                       push   eax
0x82c033: e83e020700               call   0x89c276
0x82c038: d99da4feffff             fstp   DWORD PTR [ebp-0x15c]
0x82c03e: 83c404                   add    esp,0x4
0x82c041: e920010000               jmp    0x82c166
0x82c046: 3bf3                     cmp    esi,ebx
0x82c048: 0f84dafcffff             je     0x82bd28
0x82c04e: 83c630                   add    esi,0x30
0x82c051: 837e1410                 cmp    DWORD PTR [esi+0x14],0x10
0x82c055: 7202                     jb     0x82c059
0x82c057: 8b36                     mov    esi,DWORD PTR [esi]
0x82c059: 3bf3                     cmp    esi,ebx
0x82c05b: 0f84c7fcffff             je     0x82bd28
0x82c061: 56                       push   esi
0x82c062: e84d570600               call   0x8917b4
0x82c067: 83c404                   add    esp,0x4
0x82c06a: e9bbfcffff               jmp    0x82bd2a
0x82c06f: 3bf3                     cmp    esi,ebx
0x82c071: 0f84e9fcffff             je     0x82bd60
0x82c077: 83c630                   add    esi,0x30
0x82c07a: 837e1410                 cmp    DWORD PTR [esi+0x14],0x10
0x82c07e: 7202                     jb     0x82c082
0x82c080: 8b36                     mov    esi,DWORD PTR [esi]
0x82c082: 3bf3                     cmp    esi,ebx
0x82c084: 0f84d6fcffff             je     0x82bd60
0x82c08a: 56                       push   esi
0x82c08b: e8e6010700               call   0x89c276
0x82c090: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82c096: 83c404                   add    esp,0x4
0x82c099: e9cafcffff               jmp    0x82bd68
0x82c09e: 3bf3                     cmp    esi,ebx
0x82c0a0: 0f8478feffff             je     0x82bf1e
0x82c0a6: 83c630                   add    esi,0x30
0x82c0a9: 837e1410                 cmp    DWORD PTR [esi+0x14],0x10
0x82c0ad: 7202                     jb     0x82c0b1
0x82c0af: 8b36                     mov    esi,DWORD PTR [esi]
0x82c0b1: 3bf3                     cmp    esi,ebx
0x82c0b3: 0f8465feffff             je     0x82bf1e
0x82c0b9: 56                       push   esi
0x82c0ba: e8b7010700               call   0x89c276
0x82c0bf: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82c0c5: 83c404                   add    esp,0x4
0x82c0c8: e959feffff               jmp    0x82bf26
0x82c0cd: 3bf3                     cmp    esi,ebx
0x82c0cf: 0f8489feffff             je     0x82bf5e
0x82c0d5: 83c630                   add    esi,0x30
0x82c0d8: 837e1410                 cmp    DWORD PTR [esi+0x14],0x10
0x82c0dc: 7202                     jb     0x82c0e0
0x82c0de: 8b36                     mov    esi,DWORD PTR [esi]
0x82c0e0: 3bf3                     cmp    esi,ebx
0x82c0e2: 0f8476feffff             je     0x82bf5e
0x82c0e8: 56                       push   esi
0x82c0e9: e888010700               call   0x89c276
0x82c0ee: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82c0f4: 83c404                   add    esp,0x4
0x82c0f7: e96afeffff               jmp    0x82bf66
0x82c0fc: 3bf3                     cmp    esi,ebx
0x82c0fe: 0f84a3feffff             je     0x82bfa7
0x82c104: 83c630                   add    esi,0x30
0x82c107: 837e1410                 cmp    DWORD PTR [esi+0x14],0x10
0x82c10b: 7202                     jb     0x82c10f
0x82c10d: 8b36                     mov    esi,DWORD PTR [esi]
0x82c10f: 3bf3                     cmp    esi,ebx
0x82c111: 0f8490feffff             je     0x82bfa7
0x82c117: 56                       push   esi
0x82c118: e859010700               call   0x89c276
0x82c11d: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82c123: 83c404                   add    esp,0x4
0x82c126: e984feffff               jmp    0x82bfaf
0x82c12b: 3bf3                     cmp    esi,ebx
0x82c12d: 0f84b4feffff             je     0x82bfe7
0x82c133: 83c630                   add    esi,0x30
0x82c136: 837e1410                 cmp    DWORD PTR [esi+0x14],0x10
0x82c13a: 7202                     jb     0x82c13e
0x82c13c: 8b36                     mov    esi,DWORD PTR [esi]
0x82c13e: 3bf3                     cmp    esi,ebx
0x82c140: 0f84a1feffff             je     0x82bfe7
0x82c146: 56                       push   esi
0x82c147: e82a010700               call   0x89c276
0x82c14c: d99da8feffff             fstp   DWORD PTR [ebp-0x158]
0x82c152: 83c404                   add    esp,0x4
0x82c155: e995feffff               jmp    0x82bfef
0x82c15a: d905c056c500             fld    DWORD PTR ds:0xc556c0
0x82c160: d99da4feffff             fstp   DWORD PTR [ebp-0x15c]
0x82c166: d985a4feffff             fld    DWORD PTR [ebp-0x15c]
0x82c16c: 687838c500               push   0xc53878
0x82c171: d95da4                   fstp   DWORD PTR [ebp-0x5c]
0x82c174: e8273ff0ff               call   0x7300a0
0x82c179: 3bc3                     cmp    eax,ebx
0x82c17b: 741a                     je     0x82c197
0x82c17d: 83c030                   add    eax,0x30
0x82c180: 83781410                 cmp    DWORD PTR [eax+0x14],0x10
0x82c184: 7202                     jb     0x82c188
0x82c186: 8b00                     mov    eax,DWORD PTR [eax]
0x82c188: 3bc3                     cmp    eax,ebx
0x82c18a: 740b                     je     0x82c197
0x82c18c: 50                       push   eax
0x82c18d: e822560600               call   0x8917b4
0x82c192: 83c404                   add    esp,0x4
0x82c195: eb05                     jmp    0x82c19c
0x82c197: b801000000               mov    eax,0x1
0x82c19c: 8945a8                   mov    DWORD PTR [ebp-0x58],eax
0x82c19f: 8b8d98feffff             mov    ecx,DWORD PTR [ebp-0x168]
0x82c1a5: 8d9524ffffff             lea    edx,[ebp-0xdc]
0x82c1ab: e890010000               call   0x82c340
0x82c1b0: 8dbd24ffffff             lea    edi,[ebp-0xdc]
0x82c1b6: 8bf0                     mov    esi,eax
0x82c1b8: e8f3000000               call   0x82c2b0
0x82c1bd: 8b85a0feffff             mov    eax,DWORD PTR [ebp-0x160]
0x82c1c3: bf0438c500               mov    edi,0xc53804
0x82c1c8: e8f321f0ff               call   0x72e3c0
0x82c1cd: 8bf8                     mov    edi,eax
0x82c1cf: 8db524ffffff             lea    esi,[ebp-0xdc]
0x82c1d5: 89bda0feffff             mov    DWORD PTR [ebp-0x160],edi
0x82c1db: 885dfc                   mov    BYTE PTR [ebp-0x4],bl
0x82c1de: e8ad0dcaff               call   0x4ccf90
0x82c1e3: 3bfb                     cmp    edi,ebx
0x82c1e5: 0f85c5f9ffff             jne    0x82bbb0
0x82c1eb: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x82c1f2: 83bd0cffffff10           cmp    DWORD PTR [ebp-0xf4],0x10
0x82c1f9: c785acfeffff9423bf00     mov    DWORD PTR [ebp-0x154],0xbf2394
0x82c203: 720f                     jb     0x82c214
0x82c205: 8b85f8feffff             mov    eax,DWORD PTR [ebp-0x108]
0x82c20b: 50                       push   eax
0x82c20c: e8fb4f0600               call   0x89120c
0x82c211: 83c404                   add    esp,0x4
0x82c214: 8d8dacfeffff             lea    ecx,[ebp-0x154]
0x82c21a: c7850cffffff0f000000     mov    DWORD PTR [ebp-0xf4],0xf
0x82c224: 899d08ffffff             mov    DWORD PTR [ebp-0xf8],ebx
0x82c22a: 889df8feffff             mov    BYTE PTR [ebp-0x108],bl
0x82c230: e80b1ef0ff               call   0x72e040
0x82c235: b801000000               mov    eax,0x1
0x82c23a: eb4b                     jmp    0x82c287
0x82c23c: c745fcffffffff           mov    DWORD PTR [ebp-0x4],0xffffffff
0x82c243: c785acfeffff9423bf00     mov    DWORD PTR [ebp-0x154],0xbf2394
0x82c24d: 39bd0cffffff             cmp    DWORD PTR [ebp-0xf4],edi
0x82c253: 720f                     jb     0x82c264
0x82c255: 8b8df8feffff             mov    ecx,DWORD PTR [ebp-0x108]
0x82c25b: 51                       push   ecx
0x82c25c: e8ab4f0600               call   0x89120c
0x82c261: 83c404                   add    esp,0x4
0x82c264: 8d8dacfeffff             lea    ecx,[ebp-0x154]
0x82c26a: c7850cffffff0f000000     mov    DWORD PTR [ebp-0xf4],0xf
0x82c274: 899d08ffffff             mov    DWORD PTR [ebp-0xf8],ebx
0x82c27a: 889df8feffff             mov    BYTE PTR [ebp-0x108],bl
0x82c280: e8bb1df0ff               call   0x72e040
0x82c285: 33c0                     xor    eax,eax
0x82c287: 8b4df4                   mov    ecx,DWORD PTR [ebp-0xc]
0x82c28a: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x82c291: 59                       pop    ecx
0x82c292: 5f                       pop    edi
0x82c293: 5e                       pop    esi
0x82c294: 5b                       pop    ebx
0x82c295: 8b4dec                   mov    ecx,DWORD PTR [ebp-0x14]
0x82c298: 33cd                     xor    ecx,ebp
0x82c29a: e8624d0600               call   0x891001
0x82c29f: 8be5                     mov    esp,ebp
0x82c2a1: 5d                       pop    ebp
0x82c2a2: c20400                   ret    0x4

; B29 Bullet record assignment; four strings and floats/curve fields
; VA [0x82c2b0,0x82c33b) SHA256 8f072036089f5ffc85701a80aea3ed635a4b9756984151cf6d687f8f423814ab
0x82c2b0: 668b07                   mov    ax,WORD PTR [edi]
0x82c2b3: 6aff                     push   0xffffffff
0x82c2b5: 6a00                     push   0x0
0x82c2b7: 8d4f04                   lea    ecx,[edi+0x4]
0x82c2ba: 51                       push   ecx
0x82c2bb: 8d4e04                   lea    ecx,[esi+0x4]
0x82c2be: 668906                   mov    WORD PTR [esi],ax
0x82c2c1: e87a6dbdff               call   0x403040
0x82c2c6: 6aff                     push   0xffffffff
0x82c2c8: 6a00                     push   0x0
0x82c2ca: 8d5720                   lea    edx,[edi+0x20]
0x82c2cd: 52                       push   edx
0x82c2ce: 8d4e20                   lea    ecx,[esi+0x20]
0x82c2d1: e86a6dbdff               call   0x403040
0x82c2d6: 6aff                     push   0xffffffff
0x82c2d8: 6a00                     push   0x0
0x82c2da: 8d473c                   lea    eax,[edi+0x3c]
0x82c2dd: 50                       push   eax
0x82c2de: 8d4e3c                   lea    ecx,[esi+0x3c]
0x82c2e1: e85a6dbdff               call   0x403040
0x82c2e6: 6aff                     push   0xffffffff
0x82c2e8: 6a00                     push   0x0
0x82c2ea: 8d4f58                   lea    ecx,[edi+0x58]
0x82c2ed: 51                       push   ecx
0x82c2ee: 8d4e58                   lea    ecx,[esi+0x58]
0x82c2f1: e84a6dbdff               call   0x403040
0x82c2f6: d94774                   fld    DWORD PTR [edi+0x74]
0x82c2f9: d95e74                   fstp   DWORD PTR [esi+0x74]
0x82c2fc: 8bc6                     mov    eax,esi
0x82c2fe: d94778                   fld    DWORD PTR [edi+0x78]
0x82c301: d95e78                   fstp   DWORD PTR [esi+0x78]
0x82c304: d9477c                   fld    DWORD PTR [edi+0x7c]
0x82c307: d95e7c                   fstp   DWORD PTR [esi+0x7c]
0x82c30a: d98780000000             fld    DWORD PTR [edi+0x80]
0x82c310: d99e80000000             fstp   DWORD PTR [esi+0x80]
0x82c316: 8b9784000000             mov    edx,DWORD PTR [edi+0x84]
0x82c31c: 899684000000             mov    DWORD PTR [esi+0x84],edx
0x82c322: d98788000000             fld    DWORD PTR [edi+0x88]
0x82c328: d99e88000000             fstp   DWORD PTR [esi+0x88]
0x82c32e: d9878c000000             fld    DWORD PTR [edi+0x8c]
0x82c334: d99e8c000000             fstp   DWORD PTR [esi+0x8c]
0x82c33a: c3                       ret

; B30 Blt2 resource records become class2 actor model records, including effect filename
; VA [0x4f5320,0x4f563b) SHA256 8d6da254cdc10e1984620940acaf5637527f70f60cacfeeb430817bbcab7ad56
0x4f5320: 55                       push   ebp
0x4f5321: 8bec                     mov    ebp,esp
0x4f5323: 6aff                     push   0xffffffff
0x4f5325: 6861749200               push   0x927461
0x4f532a: 64a100000000             mov    eax,fs:0x0
0x4f5330: 50                       push   eax
0x4f5331: 81ec94010000             sub    esp,0x194
0x4f5337: a1201fd600               mov    eax,ds:0xd61f20
0x4f533c: 33c5                     xor    eax,ebp
0x4f533e: 8945f0                   mov    DWORD PTR [ebp-0x10],eax
0x4f5341: 53                       push   ebx
0x4f5342: 56                       push   esi
0x4f5343: 57                       push   edi
0x4f5344: 50                       push   eax
0x4f5345: 8d45f4                   lea    eax,[ebp-0xc]
0x4f5348: 64a300000000             mov    fs:0x0,eax
0x4f534e: 33db                     xor    ebx,ebx
0x4f5350: 68a4000000               push   0xa4
0x4f5355: 66899d70feffff           mov    WORD PTR [ebp-0x190],bx
0x4f535c: 899d7cfeffff             mov    DWORD PTR [ebp-0x184],ebx
0x4f5362: e801bf3900               call   0x891268
0x4f5367: 83c404                   add    esp,0x4
0x4f536a: 3bc3                     cmp    eax,ebx
0x4f536c: 0f8496020000             je     0x4f5608
0x4f5372: 898578feffff             mov    DWORD PTR [ebp-0x188],eax
0x4f5378: 8900                     mov    DWORD PTR [eax],eax
0x4f537a: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f5380: 894004                   mov    DWORD PTR [eax+0x4],eax
0x4f5383: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f5389: 894008                   mov    DWORD PTR [eax+0x8],eax
0x4f538c: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f5392: c680a000000001           mov    BYTE PTR [eax+0xa0],0x1
0x4f5399: 8b8d78feffff             mov    ecx,DWORD PTR [ebp-0x188]
0x4f539f: c681a100000001           mov    BYTE PTR [ecx+0xa1],0x1
0x4f53a6: 895dfc                   mov    DWORD PTR [ebp-0x4],ebx
0x4f53a9: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f53af: 33d2                     xor    edx,edx
0x4f53b1: 66899570feffff           mov    WORD PTR [ebp-0x190],dx
0x4f53b8: 8b4804                   mov    ecx,DWORD PTR [eax+0x4]
0x4f53bb: 51                       push   ecx
0x4f53bc: 8d8d74feffff             lea    ecx,[ebp-0x18c]
0x4f53c2: e8097afdff               call   0x4ccdd0
0x4f53c7: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f53cd: 894004                   mov    DWORD PTR [eax+0x4],eax
0x4f53d0: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f53d6: 8900                     mov    DWORD PTR [eax],eax
0x4f53d8: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f53de: 8d9570feffff             lea    edx,[ebp-0x190]
0x4f53e4: 894008                   mov    DWORD PTR [eax+0x8],eax
0x4f53e7: 52                       push   edx
0x4f53e8: 899d7cfeffff             mov    DWORD PTR [ebp-0x184],ebx
0x4f53ee: e80d673300               call   0x82bb00
0x4f53f3: 85c0                     test   eax,eax
0x4f53f5: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f53fb: 0f84b3010000             je     0x4f55b4
0x4f5401: 8b30                     mov    esi,DWORD PTR [eax]
0x4f5403: 89b56cfeffff             mov    DWORD PTR [ebp-0x194],esi
0x4f5409: 3bf0                     cmp    esi,eax
0x4f540b: 0f84a3010000             je     0x4f55b4
0x4f5411: b80f000000               mov    eax,0xf
0x4f5416: 33c9                     xor    ecx,ecx
0x4f5418: 89859cfeffff             mov    DWORD PTR [ebp-0x164],eax
0x4f541e: 899d98feffff             mov    DWORD PTR [ebp-0x168],ebx
0x4f5424: 889d88feffff             mov    BYTE PTR [ebp-0x178],bl
0x4f542a: c785b8feffff07000000     mov    DWORD PTR [ebp-0x148],0x7
0x4f5434: 899db4feffff             mov    DWORD PTR [ebp-0x14c],ebx
0x4f543a: 66898da4feffff           mov    WORD PTR [ebp-0x15c],cx
0x4f5441: 8985d4feffff             mov    DWORD PTR [ebp-0x12c],eax
0x4f5447: 899dd0feffff             mov    DWORD PTR [ebp-0x130],ebx
0x4f544d: 889dc0feffff             mov    BYTE PTR [ebp-0x140],bl
0x4f5453: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x4f5457: 837e2810                 cmp    DWORD PTR [esi+0x28],0x10
0x4f545b: 7205                     jb     0x4f5462
0x4f545d: 8b5614                   mov    edx,DWORD PTR [esi+0x14]
0x4f5460: eb03                     jmp    0x4f5465
0x4f5462: 8d5614                   lea    edx,[esi+0x14]
0x4f5465: 8bc2                     mov    eax,edx
0x4f5467: 8d7801                   lea    edi,[eax+0x1]
0x4f546a: 8d9b00000000             lea    ebx,[ebx+0x0]
0x4f5470: 8a08                     mov    cl,BYTE PTR [eax]
0x4f5472: 40                       inc    eax
0x4f5473: 3acb                     cmp    cl,bl
0x4f5475: 75f9                     jne    0x4f5470
0x4f5477: 2bc7                     sub    eax,edi
0x4f5479: 50                       push   eax
0x4f547a: 52                       push   edx
0x4f547b: 8d8dc0feffff             lea    ecx,[ebp-0x140]
0x4f5481: e8ead5f0ff               call   0x402a70
0x4f5486: 0fb75610                 movzx  edx,WORD PTR [esi+0x10]
0x4f548a: 81ca00000002             or     edx,0x2000000
0x4f5490: 83c630                   add    esi,0x30
0x4f5493: bf10000000               mov    edi,0x10
0x4f5498: 899584feffff             mov    DWORD PTR [ebp-0x17c],edx
0x4f549e: 397e14                   cmp    DWORD PTR [esi+0x14],edi
0x4f54a1: 7204                     jb     0x4f54a7
0x4f54a3: 8b06                     mov    eax,DWORD PTR [esi]
0x4f54a5: eb02                     jmp    0x4f54a9
0x4f54a7: 8bc6                     mov    eax,esi
0x4f54a9: 6804010000               push   0x104
0x4f54ae: 8d8df0feffff             lea    ecx,[ebp-0x110]
0x4f54b4: 51                       push   ecx
0x4f54b5: 6aff                     push   0xffffffff
0x4f54b7: 50                       push   eax
0x4f54b8: 53                       push   ebx
0x4f54b9: 53                       push   ebx
0x4f54ba: ff150c23bd00             call   DWORD PTR ds:0xbd230c
0x4f54c0: 397e14                   cmp    DWORD PTR [esi+0x14],edi
0x4f54c3: 7202                     jb     0x4f54c7
0x4f54c5: 8b36                     mov    esi,DWORD PTR [esi]
0x4f54c7: 8bc6                     mov    eax,esi
0x4f54c9: 8d5001                   lea    edx,[eax+0x1]
0x4f54cc: 8d642400                 lea    esp,[esp+0x0]
0x4f54d0: 8a08                     mov    cl,BYTE PTR [eax]
0x4f54d2: 40                       inc    eax
0x4f54d3: 3acb                     cmp    cl,bl
0x4f54d5: 75f9                     jne    0x4f54d0
0x4f54d7: 2bc2                     sub    eax,edx
0x4f54d9: 50                       push   eax
0x4f54da: 56                       push   esi
0x4f54db: 8d8d88feffff             lea    ecx,[ebp-0x178]
0x4f54e1: e88ad5f0ff               call   0x402a70
0x4f54e6: 8d85f0feffff             lea    eax,[ebp-0x110]
0x4f54ec: 8d5002                   lea    edx,[eax+0x2]
0x4f54ef: 90                       nop
0x4f54f0: 668b08                   mov    cx,WORD PTR [eax]
0x4f54f3: 83c002                   add    eax,0x2
0x4f54f6: 663bcb                   cmp    cx,bx
0x4f54f9: 75f5                     jne    0x4f54f0
0x4f54fb: 2bc2                     sub    eax,edx
0x4f54fd: d1f8                     sar    eax,1
0x4f54ff: 50                       push   eax
0x4f5500: 8d95f0feffff             lea    edx,[ebp-0x110]
0x4f5506: 52                       push   edx
0x4f5507: 8d8da4feffff             lea    ecx,[ebp-0x15c]
0x4f550d: e84eccf0ff               call   0x402160
0x4f5512: 8d9584feffff             lea    edx,[ebp-0x17c]
0x4f5518: b97074fb00               mov    ecx,0xfb7470
0x4f551d: e84e250000               call   0x4f7a70
0x4f5522: 6aff                     push   0xffffffff
0x4f5524: 8bf0                     mov    esi,eax
0x4f5526: 53                       push   ebx
0x4f5527: 8d8588feffff             lea    eax,[ebp-0x178]
0x4f552d: 50                       push   eax
0x4f552e: 8bce                     mov    ecx,esi
0x4f5530: e80bdbf0ff               call   0x403040
0x4f5535: 6aff                     push   0xffffffff
0x4f5537: 53                       push   ebx
0x4f5538: 8d8da4feffff             lea    ecx,[ebp-0x15c]
0x4f553e: 51                       push   ecx
0x4f553f: 8d4e1c                   lea    ecx,[esi+0x1c]
0x4f5542: e899d1f0ff               call   0x4026e0
0x4f5547: 6aff                     push   0xffffffff
0x4f5549: 53                       push   ebx
0x4f554a: 8d95c0feffff             lea    edx,[ebp-0x140]
0x4f5550: 52                       push   edx
0x4f5551: 8d4e38                   lea    ecx,[esi+0x38]
0x4f5554: e8e7daf0ff               call   0x403040
0x4f5559: 8b85dcfeffff             mov    eax,DWORD PTR [ebp-0x124]
0x4f555f: 894654                   mov    DWORD PTR [esi+0x54],eax
0x4f5562: 8b8de0feffff             mov    ecx,DWORD PTR [ebp-0x120]
0x4f5568: 894e58                   mov    DWORD PTR [esi+0x58],ecx
0x4f556b: f30f1085e4feffff         movss  xmm0,DWORD PTR [ebp-0x11c]
0x4f5573: f30f11465c               movss  DWORD PTR [esi+0x5c],xmm0
0x4f5578: 8a95e8feffff             mov    dl,BYTE PTR [ebp-0x118]
0x4f557e: 885660                   mov    BYTE PTR [esi+0x60],dl
0x4f5581: 8a85e9feffff             mov    al,BYTE PTR [ebp-0x117]
0x4f5587: 884661                   mov    BYTE PTR [esi+0x61],al
0x4f558a: 8db588feffff             lea    esi,[ebp-0x178]
0x4f5590: e81bfdffff               call   0x4f52b0
0x4f5595: 8d856cfeffff             lea    eax,[ebp-0x194]
0x4f559b: e88079fdff               call   0x4ccf20
0x4f55a0: 8bb56cfeffff             mov    esi,DWORD PTR [ebp-0x194]
0x4f55a6: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f55ac: 3bf0                     cmp    esi,eax
0x4f55ae: 0f855dfeffff             jne    0x4f5411
0x4f55b4: 8d8d74feffff             lea    ecx,[ebp-0x18c]
0x4f55ba: 898d84feffff             mov    DWORD PTR [ebp-0x17c],ecx
0x4f55c0: c745fc02000000           mov    DWORD PTR [ebp-0x4],0x2
0x4f55c7: 8b08                     mov    ecx,DWORD PTR [eax]
0x4f55c9: 50                       push   eax
0x4f55ca: 51                       push   ecx
0x4f55cb: 8d956cfeffff             lea    edx,[ebp-0x194]
0x4f55d1: 52                       push   edx
0x4f55d2: 8db574feffff             lea    esi,[ebp-0x18c]
0x4f55d8: e87374fdff               call   0x4cca50
0x4f55dd: 8b8578feffff             mov    eax,DWORD PTR [ebp-0x188]
0x4f55e3: 50                       push   eax
0x4f55e4: e823bc3900               call   0x89120c
0x4f55e9: 83c404                   add    esp,0x4
0x4f55ec: 8b4df4                   mov    ecx,DWORD PTR [ebp-0xc]
0x4f55ef: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4f55f6: 59                       pop    ecx
0x4f55f7: 5f                       pop    edi
0x4f55f8: 5e                       pop    esi
0x4f55f9: 5b                       pop    ebx
0x4f55fa: 8b4df0                   mov    ecx,DWORD PTR [ebp-0x10]
0x4f55fd: 33cd                     xor    ecx,ebp
0x4f55ff: e8fdb93900               call   0x891001
0x4f5604: 8be5                     mov    esp,ebp
0x4f5606: 5d                       pop    ebp
0x4f5607: c3                       ret
0x4f5608: 8d8d84feffff             lea    ecx,[ebp-0x17c]
0x4f560e: 51                       push   ecx
0x4f560f: 8d8d60feffff             lea    ecx,[ebp-0x1a0]
0x4f5615: 899d84feffff             mov    DWORD PTR [ebp-0x17c],ebx
0x4f561b: e889ba3900               call   0x8910a9
0x4f5620: 68a857c800               push   0xc857a8
0x4f5625: 8d9560feffff             lea    edx,[ebp-0x1a0]
0x4f562b: 52                       push   edx
0x4f562c: c78560feffffa42cbd00     mov    DWORD PTR [ebp-0x1a0],0xbd2ca4
0x4f5636: e8b5733a00               call   0x89c9f0

; B31 Startup loads Blt2 into FBAAE0/FBAAE8 owner for CBullet metadata
; VA [0x48caac,0x48caf3) SHA256 215f7140a2256a494135cd590a4cbc63b909f3997575b4bca3a8a5449d1a5753
0x48caac: 8b0de8aafb00             mov    ecx,DWORD PTR ds:0xfbaae8
0x48cab2: 33c0                     xor    eax,eax
0x48cab4: 66a3e0aafb00             mov    ds:0xfbaae0,ax
0x48caba: 8b5104                   mov    edx,DWORD PTR [ecx+0x4]
0x48cabd: 52                       push   edx
0x48cabe: b9e4aafb00               mov    ecx,0xfbaae4
0x48cac3: e808030400               call   0x4ccdd0
0x48cac8: a1e8aafb00               mov    eax,ds:0xfbaae8
0x48cacd: 894004                   mov    DWORD PTR [eax+0x4],eax
0x48cad0: a1e8aafb00               mov    eax,ds:0xfbaae8
0x48cad5: 8900                     mov    DWORD PTR [eax],eax
0x48cad7: a1e8aafb00               mov    eax,ds:0xfbaae8
0x48cadc: 894008                   mov    DWORD PTR [eax+0x8],eax
0x48cadf: 68e0aafb00               push   0xfbaae0
0x48cae4: c705ecaafb0000000000     mov    DWORD PTR ds:0xfbaaec,0x0
0x48caee: e80df03900               call   0x82bb00

; B32 Effect model lookup: class2 record+38 copied verbatim as effect name
; VA [0x551ff0,0x5520ba) SHA256 c4f6a9ea4cc806d5cd764a1b80ac8e27359a51e83d3c5a485fd4374958ed973a
0x551ff0: 55                       push   ebp
0x551ff1: 8bec                     mov    ebp,esp
0x551ff3: 6aff                     push   0xffffffff
0x551ff5: 6814979200               push   0x929714
0x551ffa: 64a100000000             mov    eax,fs:0x0
0x552000: 50                       push   eax
0x552001: 83ec30                   sub    esp,0x30
0x552004: a1201fd600               mov    eax,ds:0xd61f20
0x552009: 33c5                     xor    eax,ebp
0x55200b: 8945f0                   mov    DWORD PTR [ebp-0x10],eax
0x55200e: 53                       push   ebx
0x55200f: 56                       push   esi
0x552010: 50                       push   eax
0x552011: 8d45f4                   lea    eax,[ebp-0xc]
0x552014: 64a300000000             mov    fs:0x0,eax
0x55201a: 33db                     xor    ebx,ebx
0x55201c: 8bf1                     mov    esi,ecx
0x55201e: c745e80f000000           mov    DWORD PTR [ebp-0x18],0xf
0x552025: 895de4                   mov    DWORD PTR [ebp-0x1c],ebx
0x552028: 885dd4                   mov    BYTE PTR [ebp-0x2c],bl
0x55202b: 895dfc                   mov    DWORD PTR [ebp-0x4],ebx
0x55202e: f605b075fb0001           test   BYTE PTR ds:0xfb75b0,0x1
0x552035: 7520                     jne    0x552057
0x552037: 830db075fb0001           or     DWORD PTR ds:0xfb75b0,0x1
0x55203e: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x552042: e8391dfaff               call   0x4f3d80
0x552047: 68e0d1bc00               push   0xbcd1e0
0x55204c: e8c9023400               call   0x89231a
0x552051: 83c404                   add    esp,0x4
0x552054: 885dfc                   mov    BYTE PTR [ebp-0x4],bl
0x552057: 8d55c4                   lea    edx,[ebp-0x3c]
0x55205a: b97074fb00               mov    ecx,0xfb7470
0x55205f: 8975c4                   mov    DWORD PTR [ebp-0x3c],esi
0x552062: e8095afaff               call   0x4f7a70
0x552067: 83784c10                 cmp    DWORD PTR [eax+0x4c],0x10
0x55206b: 7205                     jb     0x552072
0x55206d: 8b5038                   mov    edx,DWORD PTR [eax+0x38]
0x552070: eb03                     jmp    0x552075
0x552072: 8d5038                   lea    edx,[eax+0x38]
0x552075: 8bc6                     mov    eax,esi
0x552077: c1e818                   shr    eax,0x18
0x55207a: 3c03                     cmp    al,0x3
0x55207c: 8bc2                     mov    eax,edx
0x55207e: 8d7001                   lea    esi,[eax+0x1]
0x552081: 7524                     jne    0x5520a7
0x552083: 8a08                     mov    cl,BYTE PTR [eax]
0x552085: 40                       inc    eax
0x552086: 3acb                     cmp    cl,bl
0x552088: 75f9                     jne    0x552083
0x55208a: 2bc6                     sub    eax,esi
0x55208c: 50                       push   eax
0x55208d: 52                       push   edx
0x55208e: 8d4dd4                   lea    ecx,[ebp-0x2c]
0x552091: e8da09ebff               call   0x402a70
0x552096: 6a04                     push   0x4
0x552098: 68fc7bc000               push   0xc07bfc
0x55209d: 8d4dd4                   lea    ecx,[ebp-0x2c]
0x5520a0: e81bffeaff               call   0x401fc0
0x5520a5: eb13                     jmp    0x5520ba
0x5520a7: 8a08                     mov    cl,BYTE PTR [eax]
0x5520a9: 40                       inc    eax
0x5520aa: 3acb                     cmp    cl,bl
0x5520ac: 75f9                     jne    0x5520a7
0x5520ae: 2bc6                     sub    eax,esi
0x5520b0: 50                       push   eax
0x5520b1: 52                       push   edx
0x5520b2: 8d4dd4                   lea    ecx,[ebp-0x2c]
0x5520b5: e8b609ebff               call   0x402a70

; B33 Bullet Type-key map lookup/insert; returned value receives parsed record
; VA [0x82c340,0x82c420) SHA256 2693b5e1989c5506b9c8a047858476238285b63d1533e50c90d04952407b6e91
0x82c340: 55                       push   ebp
0x82c341: 8bec                     mov    ebp,esp
0x82c343: 6aff                     push   0xffffffff
0x82c345: 6826429100               push   0x914226
0x82c34a: 64a100000000             mov    eax,fs:0x0
0x82c350: 50                       push   eax
0x82c351: 81ec34010000             sub    esp,0x134
0x82c357: a1201fd600               mov    eax,ds:0xd61f20
0x82c35c: 33c5                     xor    eax,ebp
0x82c35e: 8945f0                   mov    DWORD PTR [ebp-0x10],eax
0x82c361: 53                       push   ebx
0x82c362: 56                       push   esi
0x82c363: 57                       push   edi
0x82c364: 50                       push   eax
0x82c365: 8d45f4                   lea    eax,[ebp-0xc]
0x82c368: 64a300000000             mov    fs:0x0,eax
0x82c36e: 8bfa                     mov    edi,edx
0x82c370: 57                       push   edi
0x82c371: 8d85c4feffff             lea    eax,[ebp-0x13c]
0x82c377: 8bf1                     mov    esi,ecx
0x82c379: e8a2000000               call   0x82c420
0x82c37e: 8b9dc4feffff             mov    ebx,DWORD PTR [ebp-0x13c]
0x82c384: 3b5e04                   cmp    ebx,DWORD PTR [esi+0x4]
0x82c387: 7409                     je     0x82c392
0x82c389: 668b07                   mov    ax,WORD PTR [edi]
0x82c38c: 663b430c                 cmp    ax,WORD PTR [ebx+0xc]
0x82c390: 736a                     jae    0x82c3fc
0x82c392: 8d85c8feffff             lea    eax,[ebp-0x138]
0x82c398: e803f7ffff               call   0x82baa0
0x82c39d: c745fc00000000           mov    DWORD PTR [ebp-0x4],0x0
0x82c3a4: 668b0f                   mov    cx,WORD PTR [edi]
0x82c3a7: 8d955cffffff             lea    edx,[ebp-0xa4]
0x82c3ad: 52                       push   edx
0x82c3ae: 8bf8                     mov    edi,eax
0x82c3b0: 66898d58ffffff           mov    WORD PTR [ebp-0xa8],cx
0x82c3b7: e8a4000000               call   0x82c460
0x82c3bc: 8d8558ffffff             lea    eax,[ebp-0xa8]
0x82c3c2: 50                       push   eax
0x82c3c3: 8bce                     mov    ecx,esi
0x82c3c5: c645fc01                 mov    BYTE PTR [ebp-0x4],0x1
0x82c3c9: e8b2050000               call   0x82c980
0x82c3ce: 53                       push   ebx
0x82c3cf: 56                       push   esi
0x82c3d0: 8db5c4feffff             lea    esi,[ebp-0x13c]
0x82c3d6: e885010000               call   0x82c560
0x82c3db: 8bbdc4feffff             mov    edi,DWORD PTR [ebp-0x13c]
0x82c3e1: 8db55cffffff             lea    esi,[ebp-0xa4]
0x82c3e7: e8a40bcaff               call   0x4ccf90
0x82c3ec: 8db5c8feffff             lea    esi,[ebp-0x138]
0x82c3f2: e8990bcaff               call   0x4ccf90
0x82c3f7: 8d4710                   lea    eax,[edi+0x10]
0x82c3fa: eb03                     jmp    0x82c3ff
0x82c3fc: 8d4310                   lea    eax,[ebx+0x10]
0x82c3ff: 8b4df4                   mov    ecx,DWORD PTR [ebp-0xc]
0x82c402: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x82c409: 59                       pop    ecx
0x82c40a: 5f                       pop    edi
0x82c40b: 5e                       pop    esi
0x82c40c: 5b                       pop    ebx
0x82c40d: 8b4df0                   mov    ecx,DWORD PTR [ebp-0x10]
0x82c410: 33cd                     xor    ecx,ebp
0x82c412: e8ea4b0600               call   0x891001
0x82c417: 8be5                     mov    esp,ebp
0x82c419: 5d                       pop    ebp
0x82c41a: c3                       ret
0x82c41b: cc                       int3
0x82c41c: cc                       int3
0x82c41d: cc                       int3
0x82c41e: cc                       int3
0x82c41f: cc                       int3

; B34 Common model assignment writes only +88/+8c
; VA [0x4c6fb0,0x4c6fc6) SHA256 656473216e4d1e8da9092af281a4693cea7d326b41e274f8aa644a5beec30e8c
0x4c6fb0: 55                       push   ebp
0x4c6fb1: 8bec                     mov    ebp,esp
0x4c6fb3: 8b4508                   mov    eax,DWORD PTR [ebp+0x8]
0x4c6fb6: 898188000000             mov    DWORD PTR [ecx+0x88],eax
0x4c6fbc: 89818c000000             mov    DWORD PTR [ecx+0x8c],eax
0x4c6fc2: 5d                       pop    ebp
0x4c6fc3: c20400                   ret    0x4

; D12 Hard literal Table/Blt2.blt with terminator
; VA [0xc05778,0xc05786) SHA256 89b5544b3573f49aa0fb16606d94a9e3a4c71b46f801f3c96cd70700d684664b
5461626c652f426c74322e626c74

; D13 BulletList/Type field family strings
; VA [0xc537f8,0xc5387c) SHA256 1c785536127aedc1e573daa64fc2d1ec3139ecf3a4f94315a4a538ecab4be171
42756c6c65744c697374000042756c6c657400005261646975730000446573630000000045666665637446696c65000047726f756e64546172676574696e67456666656374000000496d70616374456666656374000000004c69666574696d6500000000547261636554696d6500000053706c61736852616469757300000000506f7700

; D14 Curve XML tag
; VA [0xc411cc,0xc411d2) SHA256 43ec4eca692204fb9e27a563e839ebc5e1e0d2f79578ebe313f9d2376e57f6e2
437572766500

; B35 Local CreateObjectEx complete; implicit counterID, class selection, base speed60, optional controller attach
; VA [0x4a0f70,0x4a122d) SHA256 2025e90b45dabd10b017588673b58af5cdeb115834a700b644e29e7c2c3696c4
0x4a0f70: 55                       push   ebp
0x4a0f71: 8bec                     mov    ebp,esp
0x4a0f73: 83e4f8                   and    esp,0xfffffff8
0x4a0f76: 6aff                     push   0xffffffff
0x4a0f78: 686b9f9300               push   0x939f6b
0x4a0f7d: 64a100000000             mov    eax,fs:0x0
0x4a0f83: 50                       push   eax
0x4a0f84: 83ec18                   sub    esp,0x18
0x4a0f87: 53                       push   ebx
0x4a0f88: 56                       push   esi
0x4a0f89: 57                       push   edi
0x4a0f8a: a1201fd600               mov    eax,ds:0xd61f20
0x4a0f8f: 33c4                     xor    eax,esp
0x4a0f91: 50                       push   eax
0x4a0f92: 8d442428                 lea    eax,[esp+0x28]
0x4a0f96: 64a300000000             mov    fs:0x0,eax
0x4a0f9c: 8b7d08                   mov    edi,DWORD PTR [ebp+0x8]
0x4a0f9f: 33f6                     xor    esi,esi
0x4a0fa1: 33db                     xor    ebx,ebx
0x4a0fa3: 83ff0a                   cmp    edi,0xa
0x4a0fa6: 7c10                     jl     0x4a0fb8
0x4a0fa8: 81ff10270000             cmp    edi,0x2710
0x4a0fae: 0f9ec3                   setle  bl
0x4a0fb1: 4b                       dec    ebx
0x4a0fb2: 83e305                   and    ebx,0x5
0x4a0fb5: 43                       inc    ebx
0x4a0fb6: 7527                     jne    0x4a0fdf
0x4a0fb8: 6844040000               push   0x444
0x4a0fbd: e8a6023f00               call   0x891268
0x4a0fc2: 83c404                   add    esp,0x4
0x4a0fc5: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4a0fc9: c744243000000000         mov    DWORD PTR [esp+0x30],0x0
0x4a0fd1: 85c0                     test   eax,eax
0x4a0fd3: 746e                     je     0x4a1043
0x4a0fd5: 6a00                     push   0x0
0x4a0fd7: 50                       push   eax
0x4a0fd8: e813c70200               call   0x4cd6f0
0x4a0fdd: eb66                     jmp    0x4a1045
0x4a0fdf: 83fb01                   cmp    ebx,0x1
0x4a0fe2: 7535                     jne    0x4a1019
0x4a0fe4: 6834040000               push   0x434
0x4a0fe9: e87a023f00               call   0x891268
0x4a0fee: 83c404                   add    esp,0x4
0x4a0ff1: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4a0ff5: 895c2430                 mov    DWORD PTR [esp+0x30],ebx
0x4a0ff9: 85c0                     test   eax,eax
0x4a0ffb: 7408                     je     0x4a1005
0x4a0ffd: 50                       push   eax
0x4a0ffe: e80d070300               call   0x4d1710
0x4a1003: eb02                     jmp    0x4a1007
0x4a1005: 33c0                     xor    eax,eax
0x4a1007: 57                       push   edi
0x4a1008: c7442434ffffffff         mov    DWORD PTR [esp+0x34],0xffffffff
0x4a1010: 8bf0                     mov    esi,eax
0x4a1012: e8b9fdffff               call   0x4a0dd0
0x4a1017: eb36                     jmp    0x4a104f
0x4a1019: 83fb06                   cmp    ebx,0x6
0x4a101c: 7531                     jne    0x4a104f
0x4a101e: 682c040000               push   0x42c
0x4a1023: e840023f00               call   0x891268
0x4a1028: 83c404                   add    esp,0x4
0x4a102b: 89442414                 mov    DWORD PTR [esp+0x14],eax
0x4a102f: c744243002000000         mov    DWORD PTR [esp+0x30],0x2
0x4a1037: 85c0                     test   eax,eax
0x4a1039: 7408                     je     0x4a1043
0x4a103b: 50                       push   eax
0x4a103c: e8df100300               call   0x4d2120
0x4a1041: eb02                     jmp    0x4a1045
0x4a1043: 33c0                     xor    eax,eax
0x4a1045: 8bf0                     mov    esi,eax
0x4a1047: c7442430ffffffff         mov    DWORD PTR [esp+0x30],0xffffffff
0x4a104f: 66a104def700             mov    ax,ds:0xf7de04
0x4a1055: f30f10450c               movss  xmm0,DWORD PTR [ebp+0xc]
0x4a105a: 8b16                     mov    edx,DWORD PTR [esi]
0x4a105c: 8b5244                   mov    edx,DWORD PTR [edx+0x44]
0x4a105f: 66894604                 mov    WORD PTR [esi+0x4],ax
0x4a1063: 6a01                     push   0x1
0x4a1065: 8d442418                 lea    eax,[esp+0x18]
0x4a1069: f30f11442418             movss  DWORD PTR [esp+0x18],xmm0
0x4a106f: f30f104510               movss  xmm0,DWORD PTR [ebp+0x10]
0x4a1074: 50                       push   eax
0x4a1075: 8bce                     mov    ecx,esi
0x4a1077: f30f11442420             movss  DWORD PTR [esp+0x20],xmm0
0x4a107d: ffd2                     call   edx
0x4a107f: 8b4d18                   mov    ecx,DWORD PTR [ebp+0x18]
0x4a1082: 8b06                     mov    eax,DWORD PTR [esi]
0x4a1084: 8b5058                   mov    edx,DWORD PTR [eax+0x58]
0x4a1087: 51                       push   ecx
0x4a1088: 8bce                     mov    ecx,esi
0x4a108a: ffd2                     call   edx
0x4a108c: 8b06                     mov    eax,DWORD PTR [esi]
0x4a108e: 8b403c                   mov    eax,DWORD PTR [eax+0x3c]
0x4a1091: 0fb6cb                   movzx  ecx,bl
0x4a1094: 0fb7d7                   movzx  edx,di
0x4a1097: c1e118                   shl    ecx,0x18
0x4a109a: 0bca                     or     ecx,edx
0x4a109c: 51                       push   ecx
0x4a109d: 8bce                     mov    ecx,esi
0x4a109f: ffd0                     call   eax
0x4a10a1: 83ff0a                   cmp    edi,0xa
0x4a10a4: bf01000000               mov    edi,0x1
0x4a10a9: 7d24                     jge    0x4a10cf
0x4a10ab: 8b865c010000             mov    eax,DWORD PTR [esi+0x15c]
0x4a10b1: 8bcf                     mov    ecx,edi
0x4a10b3: 66898e88030000           mov    WORD PTR [esi+0x388],cx
0x4a10ba: 85c0                     test   eax,eax
0x4a10bc: 7411                     je     0x4a10cf
0x4a10be: 83be7003000000           cmp    DWORD PTR [esi+0x370],0x0
0x4a10c5: 7408                     je     0x4a10cf
0x4a10c7: 57                       push   edi
0x4a10c8: 57                       push   edi
0x4a10c9: 50                       push   eax
0x4a10ca: e8d15d3000               call   0x7a6ea0
0x4a10cf: 8b16                     mov    edx,DWORD PTR [esi]
0x4a10d1: 8b4230                   mov    eax,DWORD PTR [edx+0x30]
0x4a10d4: 8bce                     mov    ecx,esi
0x4a10d6: ffd0                     call   eax
0x4a10d8: f6052888fb0001           test   BYTE PTR ds:0xfb8828,0x1
0x4a10df: 7528                     jne    0x4a1109
0x4a10e1: 093d2888fb00             or     DWORD PTR ds:0xfb8828,edi
0x4a10e7: c744243003000000         mov    DWORD PTR [esp+0x30],0x3
0x4a10ef: e85ce70a00               call   0x54f850
0x4a10f4: 6880d5bc00               push   0xbcd580
0x4a10f9: e81c123f00               call   0x89231a
0x4a10fe: 83c404                   add    esp,0x4
0x4a1101: c7442430ffffffff         mov    DWORD PTR [esp+0x30],0xffffffff
0x4a1109: db4514                   fild   DWORD PTR [ebp+0x14]
0x4a110c: 8b16                     mov    edx,DWORD PTR [esi]
0x4a110e: 8b425c                   mov    eax,DWORD PTR [edx+0x5c]
0x4a1111: 51                       push   ecx
0x4a1112: d80dbc90fb00             fmul   DWORD PTR ds:0xfb90bc
0x4a1118: 8bce                     mov    ecx,esi
0x4a111a: d95c2418                 fstp   DWORD PTR [esp+0x18]
0x4a111e: d9442418                 fld    DWORD PTR [esp+0x18]
0x4a1122: d91c24                   fstp   DWORD PTR [esp]
0x4a1125: ffd0                     call   eax
0x4a1127: f30f10450c               movss  xmm0,DWORD PTR [ebp+0xc]
0x4a112c: 8b16                     mov    edx,DWORD PTR [esi]
0x4a112e: 8b5244                   mov    edx,DWORD PTR [edx+0x44]
0x4a1131: 57                       push   edi
0x4a1132: 8d442420                 lea    eax,[esp+0x20]
0x4a1136: f30f11442420             movss  DWORD PTR [esp+0x20],xmm0
0x4a113c: f30f104510               movss  xmm0,DWORD PTR [ebp+0x10]
0x4a1141: 50                       push   eax
0x4a1142: 8bce                     mov    ecx,esi
0x4a1144: f30f11442428             movss  DWORD PTR [esp+0x28],xmm0
0x4a114a: ffd2                     call   edx
0x4a114c: 8b86f0000000             mov    eax,DWORD PTR [esi+0xf0]
0x4a1152: 8b5008                   mov    edx,DWORD PTR [eax+0x8]
0x4a1155: 8d8ef0000000             lea    ecx,[esi+0xf0]
0x4a115b: 57                       push   edi
0x4a115c: ffd2                     call   edx
0x4a115e: d9e8                     fld1
0x4a1160: 8b06                     mov    eax,DWORD PTR [esi]
0x4a1162: 8b5068                   mov    edx,DWORD PTR [eax+0x68]
0x4a1165: 51                       push   ecx
0x4a1166: d91c24                   fstp   DWORD PTR [esp]
0x4a1169: 57                       push   edi
0x4a116a: 8bce                     mov    ecx,esi
0x4a116c: ffd2                     call   edx
0x4a116e: f6052cb2fa0001           test   BYTE PTR ds:0xfab22c,0x1
0x4a1175: f30f1005b45ac500         movss  xmm0,DWORD PTR ds:0xc55ab4
0x4a117d: f30f1186cc000000         movss  DWORD PTR [esi+0xcc],xmm0
0x4a1185: 7528                     jne    0x4a11af
0x4a1187: 093d2cb2fa00             or     DWORD PTR ds:0xfab22c,edi
0x4a118d: c744243004000000         mov    DWORD PTR [esp+0x30],0x4
0x4a1195: e8f6da0300               call   0x4dec90
0x4a119a: 6830cebc00               push   0xbcce30
0x4a119f: e876113f00               call   0x89231a
0x4a11a4: 83c404                   add    esp,0x4
0x4a11a7: c7442430ffffffff         mov    DWORD PTR [esp+0x30],0xffffffff
0x4a11af: 6830b1fa00               push   0xfab130
0x4a11b4: 8bc6                     mov    eax,esi
0x4a11b6: e875ed0300               call   0x4dff30
0x4a11bb: 013d04def700             add    DWORD PTR ds:0xf7de04,edi
0x4a11c1: 837d1c00                 cmp    DWORD PTR [ebp+0x1c],0x0
0x4a11c5: 7451                     je     0x4a1218
0x4a11c7: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4a11cd: 8b01                     mov    eax,DWORD PTR [ecx]
0x4a11cf: 8b5004                   mov    edx,DWORD PTR [eax+0x4]
0x4a11d2: 56                       push   esi
0x4a11d3: 897904                   mov    DWORD PTR [ecx+0x4],edi
0x4a11d6: ffd2                     call   edx
0x4a11d8: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4a11de: 8b01                     mov    eax,DWORD PTR [ecx]
0x4a11e0: 8b5010                   mov    edx,DWORD PTR [eax+0x10]
0x4a11e3: ffd2                     call   edx
0x4a11e5: f605147cfb0001           test   BYTE PTR ds:0xfb7c14,0x1
0x4a11ec: 7520                     jne    0x4a120e
0x4a11ee: 093d147cfb00             or     DWORD PTR ds:0xfb7c14,edi
0x4a11f4: c744243005000000         mov    DWORD PTR [esp+0x30],0x5
0x4a11fc: e84ff52200               call   0x6d0750
0x4a1201: 6830d5bc00               push   0xbcd530
0x4a1206: e80f113f00               call   0x89231a
0x4a120b: 83c404                   add    esp,0x4
0x4a120e: c7053088fb0000000000     mov    DWORD PTR ds:0xfb8830,0x0
0x4a1218: 8b4c2428                 mov    ecx,DWORD PTR [esp+0x28]
0x4a121c: 64890d00000000           mov    DWORD PTR fs:0x0,ecx
0x4a1223: 59                       pop    ecx
0x4a1224: 5f                       pop    edi
0x4a1225: 5e                       pop    esi
0x4a1226: 5b                       pop    ebx
0x4a1227: 8be5                     mov    esp,ebp
0x4a1229: 5d                       pop    ebp
0x4a122a: c21800                   ret    0x18

; B36 World erasure calls v+14 cleanup, v+00 deleting destructor, then tree deletion
; VA [0x4dfbc0,0x4dfc2c) SHA256 21ae8dd896a0efbf2fc1719b9b2af83daf1fc550fdb8d3c10097a2a4c642baf8
0x4dfbc0: 55                       push   ebp
0x4dfbc1: 8bec                     mov    ebp,esp
0x4dfbc3: 51                       push   ecx
0x4dfbc4: 53                       push   ebx
0x4dfbc5: 56                       push   esi
0x4dfbc6: 8bf0                     mov    esi,eax
0x4dfbc8: 57                       push   edi
0x4dfbc9: 8d4508                   lea    eax,[ebp+0x8]
0x4dfbcc: 8d5e08                   lea    ebx,[esi+0x8]
0x4dfbcf: 50                       push   eax
0x4dfbd0: 8d45fc                   lea    eax,[ebp-0x4]
0x4dfbd3: 8bcb                     mov    ecx,ebx
0x4dfbd5: e826f33400               call   0x82ef00
0x4dfbda: 8b7dfc                   mov    edi,DWORD PTR [ebp-0x4]
0x4dfbdd: 3b7e0c                   cmp    edi,DWORD PTR [esi+0xc]
0x4dfbe0: 7441                     je     0x4dfc23
0x4dfbe2: 33f6                     xor    esi,esi
0x4dfbe4: 8b0da4a7fb00             mov    ecx,DWORD PTR ds:0xfba7a4
0x4dfbea: 8b11                     mov    edx,DWORD PTR [ecx]
0x4dfbec: 8b421c                   mov    eax,DWORD PTR [edx+0x1c]
0x4dfbef: 56                       push   esi
0x4dfbf0: ffd0                     call   eax
0x4dfbf2: 46                       inc    esi
0x4dfbf3: 83fe03                   cmp    esi,0x3
0x4dfbf6: 7cec                     jl     0x4dfbe4
0x4dfbf8: 8b4f10                   mov    ecx,DWORD PTR [edi+0x10]
0x4dfbfb: 8b11                     mov    edx,DWORD PTR [ecx]
0x4dfbfd: 8b4214                   mov    eax,DWORD PTR [edx+0x14]
0x4dfc00: ffd0                     call   eax
0x4dfc02: 8b4f10                   mov    ecx,DWORD PTR [edi+0x10]
0x4dfc05: 85c9                     test   ecx,ecx
0x4dfc07: 740f                     je     0x4dfc18
0x4dfc09: 8b11                     mov    edx,DWORD PTR [ecx]
0x4dfc0b: 8b02                     mov    eax,DWORD PTR [edx]
0x4dfc0d: 6a01                     push   0x1
0x4dfc0f: ffd0                     call   eax
0x4dfc11: c7471000000000           mov    DWORD PTR [edi+0x10],0x0
0x4dfc18: 57                       push   edi
0x4dfc19: 8d4d08                   lea    ecx,[ebp+0x8]
0x4dfc1c: 51                       push   ecx
0x4dfc1d: 53                       push   ebx
0x4dfc1e: e86d6c2d00               call   0x7b6890
0x4dfc23: 5f                       pop    edi
0x4dfc24: 5e                       pop    esi
0x4dfc25: 5b                       pop    ebx
0x4dfc26: 8be5                     mov    esp,ebp
0x4dfc28: 5d                       pop    ebp
0x4dfc29: c20400                   ret    0x4

; D15 0007 lowbyte factory jumptable for0..7
; VA [0x4aed90,0x4aedb0) SHA256 0a53cfd326d1707723c695389deec518cefa21a679aa78babc03e1dd720e53dd
e4e54a0071e64a0083ed4a0083ed4a0083ed4a0083ed4a000ae84a00d6e84a00
