; q_create_actor [REUSED_CALLER_CONTEXT] 0x562ec0..0x5632c5 exclusive
00562EC0  55                               push   ebp
00562EC1  8bec                             mov    ebp,esp
00562EC3  83e4f8                           and    esp,0xfffffff8
00562EC6  6aff                             push   0xffffffff
00562EC8  6803a19300                       push   0x93a103
00562ECD  64a100000000                     mov    eax,fs:0x0
00562ED3  50                               push   eax
00562ED4  83ec20                           sub    esp,0x20
00562ED7  53                               push   ebx
00562ED8  56                               push   esi
00562ED9  57                               push   edi
00562EDA  a1201fd600                       mov    eax,ds:0xd61f20
00562EDF  33c4                             xor    eax,esp
00562EE1  50                               push   eax
00562EE2  8d442430                         lea    eax,[esp+0x30]
00562EE6  64a300000000                     mov    fs:0x0,eax
00562EEC  894c2418                         mov    DWORD PTR [esp+0x18],ecx
00562EF0  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
00562EF3  33c0                             xor    eax,eax
00562EF5  6689442414                       mov    WORD PTR [esp+0x14],ax
00562EFA  83ff0a                           cmp    edi,0xa
00562EFD  7d06                             jge    0x562f05
00562EFF  88442414                         mov    BYTE PTR [esp+0x14],al
00562F03  eb40                             jmp    0x562f45
00562F05  81ff10270000                     cmp    edi,0x2710
00562F0B  7d07                             jge    0x562f14
00562F0D  c644241401                       mov    BYTE PTR [esp+0x14],0x1
00562F12  eb31                             jmp    0x562f45
00562F14  81fff82a0000                     cmp    edi,0x2af8
00562F1A  7d07                             jge    0x562f23
00562F1C  c644241406                       mov    BYTE PTR [esp+0x14],0x6
00562F21  eb22                             jmp    0x562f45
00562F23  81ff08520000                     cmp    edi,0x5208
00562F29  7d07                             jge    0x562f32
00562F2B  c644241407                       mov    BYTE PTR [esp+0x14],0x7
00562F30  eb13                             jmp    0x562f45
00562F32  57                               push   edi
00562F33  681807c100                       push   0xc10718
00562F38  e823ac1800                       call   0x6edb60
00562F3D  83c408                           add    esp,0x8
00562F40  c644241400                       mov    BYTE PTR [esp+0x14],0x0
00562F45  8a4d08                           mov    cl,BYTE PTR [ebp+0x8]
00562F48  6838040000                       push   0x438
00562F4D  884c2419                         mov    BYTE PTR [esp+0x19],cl
00562F51  e812e33200                       call   0x891268
00562F56  83c404                           add    esp,0x4
00562F59  89442424                         mov    DWORD PTR [esp+0x24],eax
00562F5D  33db                             xor    ebx,ebx
00562F5F  895c2438                         mov    DWORD PTR [esp+0x38],ebx
00562F63  3bc3                             cmp    eax,ebx
00562F65  7408                             je     0x562f6f
00562F67  50                               push   eax
00562F68  e813dcf6ff                       call   0x4d0b80
00562F6D  8bd8                             mov    ebx,eax
00562F6F  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00562F77  668b542414                       mov    dx,WORD PTR [esp+0x14]
00562F7C  0fb6f2                           movzx  esi,dl
00562F7F  0fb7c7                           movzx  eax,di
00562F82  66895304                         mov    WORD PTR [ebx+0x4],dx
00562F86  8b13                             mov    edx,DWORD PTR [ebx]
00562F88  c1e618                           shl    esi,0x18
00562F8B  0bf0                             or     esi,eax
00562F8D  8b423c                           mov    eax,DWORD PTR [edx+0x3c]
00562F90  56                               push   esi
00562F91  8bcb                             mov    ecx,ebx
00562F93  c7839000000010000000             mov    DWORD PTR [ebx+0x90],0x10
00562F9D  ffd0                             call   eax
00562F9F  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
00562FA4  8b13                             mov    edx,DWORD PTR [ebx]
00562FA6  8b5244                           mov    edx,DWORD PTR [edx+0x44]
00562FA9  6a01                             push   0x1
00562FAB  8d442428                         lea    eax,[esp+0x28]
00562FAF  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
00562FB5  f30f104514                       movss  xmm0,DWORD PTR [ebp+0x14]
00562FBA  50                               push   eax
00562FBB  8bcb                             mov    ecx,ebx
00562FBD  f30f11442430                     movss  DWORD PTR [esp+0x30],xmm0
00562FC3  ffd2                             call   edx
00562FC5  8b4d18                           mov    ecx,DWORD PTR [ebp+0x18]
00562FC8  8b03                             mov    eax,DWORD PTR [ebx]
00562FCA  8b5058                           mov    edx,DWORD PTR [eax+0x58]
00562FCD  51                               push   ecx
00562FCE  8bcb                             mov    ecx,ebx
00562FD0  ffd2                             call   edx
00562FD2  f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
00562FD9  7529                             jne    0x563004
00562FDB  b801000000                       mov    eax,0x1
00562FE0  0905b075fb00                     or     DWORD PTR ds:0xfb75b0,eax
00562FE6  89442438                         mov    DWORD PTR [esp+0x38],eax
00562FEA  e8910df9ff                       call   0x4f3d80
00562FEF  68e0d1bc00                       push   0xbcd1e0
00562FF4  e821f33200                       call   0x89231a
00562FF9  83c404                           add    esp,0x4
00562FFC  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563004  8d54241c                         lea    edx,[esp+0x1c]
00563008  b97074fb00                       mov    ecx,0xfb7470
0056300D  8974241c                         mov    DWORD PTR [esp+0x1c],esi
00563011  e85a4af9ff                       call   0x4f7a70
00563016  d9405c                           fld    DWORD PTR [eax+0x5c]
00563019  8b03                             mov    eax,DWORD PTR [ebx]
0056301B  d95c241c                         fstp   DWORD PTR [esp+0x1c]
0056301F  d944241c                         fld    DWORD PTR [esp+0x1c]
00563023  8b505c                           mov    edx,DWORD PTR [eax+0x5c]
00563026  51                               push   ecx
00563027  8bcb                             mov    ecx,ebx
00563029  d91c24                           fstp   DWORD PTR [esp]
0056302C  ffd2                             call   edx
0056302E  8b4d24                           mov    ecx,DWORD PTR [ebp+0x24]
00563031  83ff0a                           cmp    edi,0xa
00563034  7d09                             jge    0x56303f
00563036  85c9                             test   ecx,ecx
00563038  7505                             jne    0x56303f
0056303A  b901000000                       mov    ecx,0x1
0056303F  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
00563045  66898b88030000                   mov    WORD PTR [ebx+0x388],cx
0056304C  85c0                             test   eax,eax
0056304E  7412                             je     0x563062
00563050  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
00563057  7409                             je     0x563062
00563059  51                               push   ecx
0056305A  6a01                             push   0x1
0056305C  50                               push   eax
0056305D  e83e3e2400                       call   0x7a6ea0
00563062  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00563069  7529                             jne    0x563094
0056306B  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00563072  c744243802000000                 mov    DWORD PTR [esp+0x38],0x2
0056307A  e8c19e2300                       call   0x79cf40
0056307F  6880dbbc00                       push   0xbcdb80
00563084  e891f23200                       call   0x89231a
00563089  83c404                           add    esp,0x4
0056308C  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563094  8d44241c                         lea    eax,[esp+0x1c]
00563098  50                               push   eax
00563099  8d442418                         lea    eax,[esp+0x18]
0056309D  b9900efc00                       mov    ecx,0xfc0e90
005630A2  897c2420                         mov    DWORD PTR [esp+0x20],edi
005630A6  e8e526fbff                       call   0x515790
005630AB  8b442414                         mov    eax,DWORD PTR [esp+0x14]
005630AF  3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
005630B5  7409                             je     0x5630c0
005630B7  8b4010                           mov    eax,DWORD PTR [eax+0x10]
005630BA  83785400                         cmp    DWORD PTR [eax+0x54],0x0
005630BE  7553                             jne    0x563113
005630C0  8b742418                         mov    esi,DWORD PTR [esp+0x18]
005630C4  8d4d0c                           lea    ecx,[ebp+0xc]
005630C7  83c660                           add    esi,0x60
005630CA  51                               push   ecx
005630CB  e870ad1500                       call   0x6bde40
005630D0  50                               push   eax
005630D1  56                               push   esi
005630D2  8d74242c                         lea    esi,[esp+0x2c]
005630D6  e8f58aeeff                       call   0x44bbd0
005630DB  f605400efc0001                   test   BYTE PTR ds:0xfc0e40,0x1
005630E2  7529                             jne    0x56310d
005630E4  830d400efc0001                   or     DWORD PTR ds:0xfc0e40,0x1
005630EB  c744243803000000                 mov    DWORD PTR [esp+0x38],0x3
005630F3  e878d6fdff                       call   0x540770
005630F8  6860dbbc00                       push   0xbcdb60
005630FD  e818f23200                       call   0x89231a
00563102  83c404                           add    esp,0x4
00563105  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
0056310D  57                               push   edi
0056310E  e8fde4fdff                       call   0x541610
00563113  8b542418                         mov    edx,DWORD PTR [esp+0x18]
00563117  837a7000                         cmp    DWORD PTR [edx+0x70],0x0
0056311B  0f840b010000                     je     0x56322c
00563121  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00563128  7529                             jne    0x563153
0056312A  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00563131  c744243804000000                 mov    DWORD PTR [esp+0x38],0x4
00563139  e8029e2300                       call   0x79cf40
0056313E  6880dbbc00                       push   0xbcdb80
00563143  e8d2f13200                       call   0x89231a
00563148  83c404                           add    esp,0x4
0056314B  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563153  8d44241c                         lea    eax,[esp+0x1c]
00563157  50                               push   eax
00563158  8d442418                         lea    eax,[esp+0x18]
0056315C  b9900efc00                       mov    ecx,0xfc0e90
00563161  897c2420                         mov    DWORD PTR [esp+0x20],edi
00563165  e82626fbff                       call   0x515790
0056316A  8b442414                         mov    eax,DWORD PTR [esp+0x14]
0056316E  3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
00563174  0f84b2000000                     je     0x56322c
0056317A  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0056317D  8b7154                           mov    esi,DWORD PTR [ecx+0x54]
00563180  85f6                             test   esi,esi
00563182  0f84a4000000                     je     0x56322c
00563188  6a01                             push   0x1
0056318A  8bfe                             mov    edi,esi
0056318C  e85f262600                       call   0x7c57f0
00563191  6a04                             push   0x4
00563193  e858262600                       call   0x7c57f0
00563198  8b442418                         mov    eax,DWORD PTR [esp+0x18]
0056319C  0fb75508                         movzx  edx,WORD PTR [ebp+0x8]
005631A0  8b7870                           mov    edi,DWORD PTR [eax+0x70]
005631A3  8d4c241c                         lea    ecx,[esp+0x1c]
005631A7  51                               push   ecx
005631A8  8d442418                         lea    eax,[esp+0x18]
005631AC  8bcf                             mov    ecx,edi
005631AE  89542420                         mov    DWORD PTR [esp+0x20],edx
005631B2  e8c9302c00                       call   0x826280
005631B7  8b442414                         mov    eax,DWORD PTR [esp+0x14]
005631BB  3b4704                           cmp    eax,DWORD PTR [edi+0x4]
005631BE  746c                             je     0x56322c
005631C0  8b4010                           mov    eax,DWORD PTR [eax+0x10]
005631C3  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
005631C6  89442424                         mov    DWORD PTR [esp+0x24],eax
005631CA  8b01                             mov    eax,DWORD PTR [ecx]
005631CC  8944241c                         mov    DWORD PTR [esp+0x1c],eax
005631D0  3bc1                             cmp    eax,ecx
005631D2  7458                             je     0x56322c
005631D4  0fb7500c                         movzx  edx,WORD PTR [eax+0xc]
005631D8  8d442414                         lea    eax,[esp+0x14]
005631DC  50                               push   eax
005631DD  8d442424                         lea    eax,[esp+0x24]
005631E1  8d8ed4000000                     lea    ecx,[esi+0xd4]
005631E7  89542418                         mov    DWORD PTR [esp+0x18],edx
005631EB  e810bd2c00                       call   0x82ef00
005631F0  8b7c2420                         mov    edi,DWORD PTR [esp+0x20]
005631F4  3bbed8000000                     cmp    edi,DWORD PTR [esi+0xd8]
005631FA  741a                             je     0x563216
005631FC  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
005631FF  8b11                             mov    edx,DWORD PTR [ecx]
00563201  8b4208                           mov    eax,DWORD PTR [edx+0x8]
00563204  ffd0                             call   eax
00563206  3b442414                         cmp    eax,DWORD PTR [esp+0x14]
0056320A  750a                             jne    0x563216
0056320C  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
0056320F  8b11                             mov    edx,DWORD PTR [ecx]
00563211  8b4224                           mov    eax,DWORD PTR [edx+0x24]
00563214  ffd0                             call   eax
00563216  8d44241c                         lea    eax,[esp+0x1c]
0056321A  e831a62b00                       call   0x81d850
0056321F  8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
00563223  8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
00563227  3b4108                           cmp    eax,DWORD PTR [ecx+0x8]
0056322A  75a8                             jne    0x5631d4
0056322C  8bf3                             mov    esi,ebx
0056322E  e8adddf6ff                       call   0x4d0fe0
00563233  8b93f0000000                     mov    edx,DWORD PTR [ebx+0xf0]
00563239  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0056323C  8d8bf0000000                     lea    ecx,[ebx+0xf0]
00563242  6a14                             push   0x14
00563244  ffd0                             call   eax
00563246  d9e8                             fld1
00563248  8b13                             mov    edx,DWORD PTR [ebx]
0056324A  8b451c                           mov    eax,DWORD PTR [ebp+0x1c]
0056324D  8b5268                           mov    edx,DWORD PTR [edx+0x68]
00563250  51                               push   ecx
00563251  d91c24                           fstp   DWORD PTR [esp]
00563254  50                               push   eax
00563255  8bcb                             mov    ecx,ebx
00563257  ffd2                             call   edx
00563259  8b4d28                           mov    ecx,DWORD PTR [ebp+0x28]
0056325C  85c9                             test   ecx,ecx
0056325E  7421                             je     0x563281
00563260  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
00563266  85c0                             test   eax,eax
00563268  7417                             je     0x563281
0056326A  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
00563271  740e                             je     0x563281
00563273  6a00                             push   0x0
00563275  0fb7c9                           movzx  ecx,cx
00563278  6a00                             push   0x0
0056327A  51                               push   ecx
0056327B  50                               push   eax
0056327C  e8bf3f2400                       call   0x7a7240
00563281  8b5520                           mov    edx,DWORD PTR [ebp+0x20]
00563284  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00563287  8b742418                         mov    esi,DWORD PTR [esp+0x18]
0056328B  83c618                           add    esi,0x18
0056328E  8d7c2424                         lea    edi,[esp+0x24]
00563292  89932c040000                     mov    DWORD PTR [ebx+0x42c],edx
00563298  89442424                         mov    DWORD PTR [esp+0x24],eax
0056329C  895c2428                         mov    DWORD PTR [esp+0x28],ebx
005632A0  e87bbc0100                       call   0x57ef20
005632A5  50                               push   eax
005632A6  56                               push   esi
005632A7  8d74242c                         lea    esi,[esp+0x2c]
005632AB  e850bf2c00                       call   0x82f200
005632B0  8b4c2430                         mov    ecx,DWORD PTR [esp+0x30]
005632B4  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
005632BB  59                               pop    ecx
005632BC  5f                               pop    edi
005632BD  5e                               pop    esi
005632BE  5b                               pop    ebx
005632BF  8be5                             mov    esp,ebp
005632C1  5d                               pop    ebp
005632C2  c22400                           ret    0x24

; q_actor_immediate_init [NEW_DIRECT_CALL_JOIN] 0x4d0fe0..0x4d1042 exclusive
004D0FE0  57                               push   edi
004D0FE1  6a01                             push   0x1
004D0FE3  56                               push   esi
004D0FE4  e8076effff                       call   0x4c7df0
004D0FE9  8d8ef0000000                     lea    ecx,[esi+0xf0]
004D0FEF  8bf8                             mov    edi,eax
004D0FF1  8b01                             mov    eax,DWORD PTR [ecx]
004D0FF3  8b5008                           mov    edx,DWORD PTR [eax+0x8]
004D0FF6  6a14                             push   0x14
004D0FF8  ffd2                             call   edx
004D0FFA  8b8668030000                     mov    eax,DWORD PTR [esi+0x368]
004D1000  85c0                             test   eax,eax
004D1002  7407                             je     0x4d100b
004D1004  c7402400000000                   mov    DWORD PTR [eax+0x24],0x0
004D100B  83be5c01000000                   cmp    DWORD PTR [esi+0x15c],0x0
004D1012  742a                             je     0x4d103e
004D1014  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
004D101A  8b4818                           mov    ecx,DWORD PTR [eax+0x18]
004D101D  6a00                             push   0x0
004D101F  6a00                             push   0x0
004D1021  81c118790000                     add    ecx,0x7918
004D1027  51                               push   ecx
004D1028  50                               push   eax
004D1029  e812622d00                       call   0x7a7240
004D102E  8b965c010000                     mov    edx,DWORD PTR [esi+0x15c]
004D1034  c7823c01000000000000             mov    DWORD PTR [edx+0x13c],0x0
004D103E  8bc7                             mov    eax,edi
004D1040  5f                               pop    edi
004D1041  c3                               ret

; actor_doll_init [NEW_OWNERSHIP_JOIN] 0x4c7df0..0x4c8050 exclusive
004C7DF0  55                               push   ebp
004C7DF1  8bec                             mov    ebp,esp
004C7DF3  83e4f8                           and    esp,0xfffffff8
004C7DF6  6aff                             push   0xffffffff
004C7DF8  683e969300                       push   0x93963e
004C7DFD  64a100000000                     mov    eax,fs:0x0
004C7E03  50                               push   eax
004C7E04  83ec10                           sub    esp,0x10
004C7E07  53                               push   ebx
004C7E08  56                               push   esi
004C7E09  57                               push   edi
004C7E0A  a1201fd600                       mov    eax,ds:0xd61f20
004C7E0F  33c4                             xor    eax,esp
004C7E11  50                               push   eax
004C7E12  8d442420                         lea    eax,[esp+0x20]
004C7E16  64a300000000                     mov    fs:0x0,eax
004C7E1C  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004C7E1F  33ff                             xor    edi,edi
004C7E21  39bb70030000                     cmp    DWORD PTR [ebx+0x370],edi
004C7E27  0f8509020000                     jne    0x4c8036
004C7E2D  8b838c000000                     mov    eax,DWORD PTR [ebx+0x8c]
004C7E33  8bf0                             mov    esi,eax
004C7E35  3bc7                             cmp    eax,edi
004C7E37  7506                             jne    0x4c7e3f
004C7E39  8bb388000000                     mov    esi,DWORD PTR [ebx+0x88]
004C7E3F  6870010000                       push   0x170
004C7E44  e81f943c00                       call   0x891268
004C7E49  83c404                           add    esp,0x4
004C7E4C  89442414                         mov    DWORD PTR [esp+0x14],eax
004C7E50  897c2428                         mov    DWORD PTR [esp+0x28],edi
004C7E54  3bc7                             cmp    eax,edi
004C7E56  740c                             je     0x4c7e64
004C7E58  0fb7ce                           movzx  ecx,si
004C7E5B  51                               push   ecx
004C7E5C  50                               push   eax
004C7E5D  e8eecd2d00                       call   0x7a4c50
004C7E62  eb02                             jmp    0x4c7e66
004C7E64  33c0                             xor    eax,eax
004C7E66  50                               push   eax
004C7E67  8d542418                         lea    edx,[esp+0x18]
004C7E6B  83ceff                           or     esi,0xffffffff
004C7E6E  8974242c                         mov    DWORD PTR [esp+0x2c],esi
004C7E72  52                               push   edx
004C7E73  897c241c                         mov    DWORD PTR [esp+0x1c],edi
004C7E77  897c2420                         mov    DWORD PTR [esp+0x20],edi
004C7E7B  e8e0250000                       call   0x4ca460
004C7E80  8dbb5c010000                     lea    edi,[ebx+0x15c]
004C7E86  8d442414                         lea    eax,[esp+0x14]
004C7E8A  c744242801000000                 mov    DWORD PTR [esp+0x28],0x1
004C7E92  e8c9900100                       call   0x4e0f60
004C7E97  89742428                         mov    DWORD PTR [esp+0x28],esi
004C7E9B  8b742418                         mov    esi,DWORD PTR [esp+0x18]
004C7E9F  85f6                             test   esi,esi
004C7EA1  7429                             je     0x4c7ecc
004C7EA3  8d4604                           lea    eax,[esi+0x4]
004C7EA6  83c9ff                           or     ecx,0xffffffff
004C7EA9  f00fc108                         lock xadd DWORD PTR [eax],ecx
004C7EAD  751d                             jne    0x4c7ecc
004C7EAF  8b16                             mov    edx,DWORD PTR [esi]
004C7EB1  8b02                             mov    eax,DWORD PTR [edx]
004C7EB3  8bce                             mov    ecx,esi
004C7EB5  ffd0                             call   eax
004C7EB7  8d4e08                           lea    ecx,[esi+0x8]
004C7EBA  83caff                           or     edx,0xffffffff
004C7EBD  f00fc111                         lock xadd DWORD PTR [ecx],edx
004C7EC1  7509                             jne    0x4c7ecc
004C7EC3  8b06                             mov    eax,DWORD PTR [esi]
004C7EC5  8b5004                           mov    edx,DWORD PTR [eax+0x4]
004C7EC8  8bce                             mov    ecx,esi
004C7ECA  ffd2                             call   edx
004C7ECC  0fb78b88030000                   movzx  ecx,WORD PTR [ebx+0x388]
004C7ED3  8b07                             mov    eax,DWORD PTR [edi]
004C7ED5  51                               push   ecx
004C7ED6  6a01                             push   0x1
004C7ED8  50                               push   eax
004C7ED9  e8c2ef2d00                       call   0x7a6ea0
004C7EDE  807d0c00                         cmp    BYTE PTR [ebp+0xc],0x0
004C7EE2  740e                             je     0x4c7ef2
004C7EE4  8b07                             mov    eax,DWORD PTR [edi]
004C7EE6  c6402001                         mov    BYTE PTR [eax+0x20],0x1
004C7EEA  8b07                             mov    eax,DWORD PTR [edi]
004C7EEC  50                               push   eax
004C7EED  e87e0f2e00                       call   0x7a8e70
004C7EF2  8b13                             mov    edx,DWORD PTR [ebx]
004C7EF4  8b5244                           mov    edx,DWORD PTR [edx+0x44]
004C7EF7  6a01                             push   0x1
004C7EF9  8d83a0000000                     lea    eax,[ebx+0xa0]
004C7EFF  50                               push   eax
004C7F00  8bcb                             mov    ecx,ebx
004C7F02  c7837003000001000000             mov    DWORD PTR [ebx+0x370],0x1
004C7F0C  ffd2                             call   edx
004C7F0E  0fb68bb0000000                   movzx  ecx,BYTE PTR [ebx+0xb0]
004C7F15  8b03                             mov    eax,DWORD PTR [ebx]
004C7F17  8b5058                           mov    edx,DWORD PTR [eax+0x58]
004C7F1A  51                               push   ecx
004C7F1B  8bcb                             mov    ecx,ebx
004C7F1D  ffd2                             call   edx
004C7F1F  83bba803000000                   cmp    DWORD PTR [ebx+0x3a8],0x0
004C7F26  8a83b0000000                     mov    al,BYTE PTR [ebx+0xb0]
004C7F2C  88442414                         mov    BYTE PTR [esp+0x14],al
004C7F30  752f                             jne    0x4c7f61
004C7F32  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
004C7F39  8883a4030000                     mov    BYTE PTR [ebx+0x3a4],al
004C7F3F  7420                             je     0x4c7f61
004C7F41  8b3f                             mov    edi,DWORD PTR [edi]
004C7F43  85ff                             test   edi,edi
004C7F45  741a                             je     0x4c7f61
004C7F47  8b442414                         mov    eax,DWORD PTR [esp+0x14]
004C7F4B  8b7704                           mov    esi,DWORD PTR [edi+0x4]
004C7F4E  50                               push   eax
004C7F4F  e83ccbf7ff                       call   0x444a90
004C7F54  8b560c                           mov    edx,DWORD PTR [esi+0xc]
004C7F57  8d4f04                           lea    ecx,[edi+0x4]
004C7F5A  f30f110424                       movss  DWORD PTR [esp],xmm0
004C7F5F  ffd2                             call   edx
004C7F61  8b03                             mov    eax,DWORD PTR [ebx]
004C7F63  d983b4000000                     fld    DWORD PTR [ebx+0xb4]
004C7F69  8b505c                           mov    edx,DWORD PTR [eax+0x5c]
004C7F6C  51                               push   ecx
004C7F6D  8bcb                             mov    ecx,ebx
004C7F6F  d91c24                           fstp   DWORD PTR [esp]
004C7F72  ffd2                             call   edx
004C7F74  d9e8                             fld1
004C7F76  8b03                             mov    eax,DWORD PTR [ebx]
004C7F78  8b5068                           mov    edx,DWORD PTR [eax+0x68]
004C7F7B  51                               push   ecx
004C7F7C  8b8b8c030000                     mov    ecx,DWORD PTR [ebx+0x38c]
004C7F82  d91c24                           fstp   DWORD PTR [esp]
004C7F85  51                               push   ecx
004C7F86  8bcb                             mov    ecx,ebx
004C7F88  ffd2                             call   edx
004C7F8A  6a30                             push   0x30
004C7F8C  e8d7923c00                       call   0x891268
004C7F91  83c404                           add    esp,0x4
004C7F94  89442414                         mov    DWORD PTR [esp+0x14],eax
004C7F98  c744242802000000                 mov    DWORD PTR [esp+0x28],0x2
004C7FA0  85c0                             test   eax,eax
004C7FA2  7409                             je     0x4c7fad
004C7FA4  8bf0                             mov    esi,eax
004C7FA6  e855c02e00                       call   0x7b4000
004C7FAB  eb02                             jmp    0x4c7faf
004C7FAD  33c0                             xor    eax,eax
004C7FAF  c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
004C7FB7  898368030000                     mov    DWORD PTR [ebx+0x368],eax
004C7FBD  c7402401000000                   mov    DWORD PTR [eax+0x24],0x1
004C7FC4  8b03                             mov    eax,DWORD PTR [ebx]
004C7FC6  8b504c                           mov    edx,DWORD PTR [eax+0x4c]
004C7FC9  8bcb                             mov    ecx,ebx
004C7FCB  ffd2                             call   edx
004C7FCD  8b08                             mov    ecx,DWORD PTR [eax]
004C7FCF  8b5004                           mov    edx,DWORD PTR [eax+0x4]
004C7FD2  8b7808                           mov    edi,DWORD PTR [eax+0x8]
004C7FD5  8b8368030000                     mov    eax,DWORD PTR [ebx+0x368]
004C7FDB  f30f10058c5ac500                 movss  xmm0,DWORD PTR ds:0xc55a8c
004C7FE3  894810                           mov    DWORD PTR [eax+0x10],ecx
004C7FE6  895014                           mov    DWORD PTR [eax+0x14],edx
004C7FE9  897818                           mov    DWORD PTR [eax+0x18],edi
004C7FEC  8b8368030000                     mov    eax,DWORD PTR [ebx+0x368]
004C7FF2  f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
004C7FF8  f30f10050858c500                 movss  xmm0,DWORD PTR ds:0xc55808
004C8000  8b4c2414                         mov    ecx,DWORD PTR [esp+0x14]
004C8004  f30f11442418                     movss  DWORD PTR [esp+0x18],xmm0
004C800A  8b542418                         mov    edx,DWORD PTR [esp+0x18]
004C800E  89481c                           mov    DWORD PTR [eax+0x1c],ecx
004C8011  895020                           mov    DWORD PTR [eax+0x20],edx
004C8014  8b9b68030000                     mov    ebx,DWORD PTR [ebx+0x368]
004C801A  53                               push   ebx
004C801B  8d442414                         lea    eax,[esp+0x14]
004C801F  c644241400                       mov    BYTE PTR [esp+0x14],0x0
004C8024  e8a7ce2e00                       call   0x7b4ed0
004C8029  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
004C8031  f30f11400c                       movss  DWORD PTR [eax+0xc],xmm0
004C8036  b801000000                       mov    eax,0x1
004C803B  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
004C803F  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004C8046  59                               pop    ecx
004C8047  5f                               pop    edi
004C8048  5e                               pop    esi
004C8049  5b                               pop    ebx
004C804A  8be5                             mov    esp,ebp
004C804C  5d                               pop    ebp
004C804D  c20800                           ret    0x8

; base_init_virtual_slot [REUSED_SLOT_NOT_Q_DIRECT_CALL] 0x4c8050..0x4c8059 exclusive
004C8050  6a00                             push   0x0
004C8052  51                               push   ecx
004C8053  e898fdffff                       call   0x4c7df0
004C8058  c3                               ret

; doll_ctor_state [NEW_STATE_JOIN] 0x7a4c50..0x7a4cd0 exclusive
007A4C50  55                               push   ebp
007A4C51  8bec                             mov    ebp,esp
007A4C53  6aff                             push   0xffffffff
007A4C55  6863799000                       push   0x907963
007A4C5A  64a100000000                     mov    eax,fs:0x0
007A4C60  50                               push   eax
007A4C61  83ec1c                           sub    esp,0x1c
007A4C64  53                               push   ebx
007A4C65  56                               push   esi
007A4C66  a1201fd600                       mov    eax,ds:0xd61f20
007A4C6B  33c5                             xor    eax,ebp
007A4C6D  50                               push   eax
007A4C6E  8d45f4                           lea    eax,[ebp-0xc]
007A4C71  64a300000000                     mov    fs:0x0,eax
007A4C77  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
007A4C7A  33db                             xor    ebx,ebx
007A4C7C  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
007A4C7F  c746044cf6c400                   mov    DWORD PTR [esi+0x4],0xc4f64c
007A4C86  c7460878f8c000                   mov    DWORD PTR [esi+0x8],0xc0f878
007A4C8D  c7460c6cf6c400                   mov    DWORD PTR [esi+0xc],0xc4f66c
007A4C94  895e10                           mov    DWORD PTR [esi+0x10],ebx
007A4C97  895e14                           mov    DWORD PTR [esi+0x14],ebx
007A4C9A  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
007A4C9E  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A4CA1  8d4e2c                           lea    ecx,[esi+0x2c]
007A4CA4  51                               push   ecx
007A4CA5  c7067cf6c400                     mov    DWORD PTR [esi],0xc4f67c
007A4CAB  c7460490f6c400                   mov    DWORD PTR [esi+0x4],0xc4f690
007A4CB2  c74608b0f6c400                   mov    DWORD PTR [esi+0x8],0xc4f6b0
007A4CB9  c7460cc0f6c400                   mov    DWORD PTR [esi+0xc],0xc4f6c0
007A4CC0  894618                           mov    DWORD PTR [esi+0x18],eax
007A4CC3  895e1c                           mov    DWORD PTR [esi+0x1c],ebx
007A4CC6  885e20                           mov    BYTE PTR [esi+0x20],bl
007A4CC9  895e24                           mov    DWORD PTR [esi+0x24],ebx
007A4CCC  c6462801                         mov    BYTE PTR [esi+0x28],0x1

; doll_tick_request_gate [NEW_RETRY_BOUNDARY] 0x7a5c50..0x7a5cb7 exclusive
007A5C50  55                               push   ebp
007A5C51  8bec                             mov    ebp,esp
007A5C53  83e4f8                           and    esp,0xfffffff8
007A5C56  6aff                             push   0xffffffff
007A5C58  688ea09300                       push   0x93a08e
007A5C5D  64a100000000                     mov    eax,fs:0x0
007A5C63  50                               push   eax
007A5C64  81ecb0000000                     sub    esp,0xb0
007A5C6A  a1201fd600                       mov    eax,ds:0xd61f20
007A5C6F  33c4                             xor    eax,esp
007A5C71  898424a8000000                   mov    DWORD PTR [esp+0xa8],eax
007A5C78  53                               push   ebx
007A5C79  56                               push   esi
007A5C7A  57                               push   edi
007A5C7B  a1201fd600                       mov    eax,ds:0xd61f20
007A5C80  33c4                             xor    eax,esp
007A5C82  50                               push   eax
007A5C83  8d8424c0000000                   lea    eax,[esp+0xc0]
007A5C8A  64a300000000                     mov    fs:0x0,eax
007A5C90  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A5C93  807b2800                         cmp    BYTE PTR [ebx+0x28],0x0
007A5C97  7413                             je     0x7a5cac
007A5C99  8b4324                           mov    eax,DWORD PTR [ebx+0x24]
007A5C9C  83f802                           cmp    eax,0x2
007A5C9F  740b                             je     0x7a5cac
007A5CA1  83f803                           cmp    eax,0x3
007A5CA4  7406                             je     0x7a5cac
007A5CA6  53                               push   ebx
007A5CA7  e8c4310000                       call   0x7a8e70
007A5CAC  33f6                             xor    esi,esi
007A5CAE  39731c                           cmp    DWORD PTR [ebx+0x1c],esi
007A5CB1  0f8458060000                     je     0x7a630f

; doll_request [NEW_REQUEST_AND_STRONG_HOLD_JOIN] 0x7a8e70..0x7a90e7 exclusive
007A8E70  55                               push   ebp
007A8E71  8bec                             mov    ebp,esp
007A8E73  83e4f8                           and    esp,0xfffffff8
007A8E76  6aff                             push   0xffffffff
007A8E78  68fb909300                       push   0x9390fb
007A8E7D  64a100000000                     mov    eax,fs:0x0
007A8E83  50                               push   eax
007A8E84  83ec18                           sub    esp,0x18
007A8E87  53                               push   ebx
007A8E88  56                               push   esi
007A8E89  57                               push   edi
007A8E8A  a1201fd600                       mov    eax,ds:0xd61f20
007A8E8F  33c4                             xor    eax,esp
007A8E91  50                               push   eax
007A8E92  8d442428                         lea    eax,[esp+0x28]
007A8E96  64a300000000                     mov    fs:0x0,eax
007A8E9C  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A8E9F  6a74                             push   0x74
007A8EA1  e8c2830e00                       call   0x891268
007A8EA6  8bf0                             mov    esi,eax
007A8EA8  83c404                           add    esp,0x4
007A8EAB  89742414                         mov    DWORD PTR [esp+0x14],esi
007A8EAF  33ff                             xor    edi,edi
007A8EB1  897c2430                         mov    DWORD PTR [esp+0x30],edi
007A8EB5  3bf7                             cmp    esi,edi
007A8EB7  742d                             je     0x7a8ee6
007A8EB9  8d4608                           lea    eax,[esi+0x8]
007A8EBC  50                               push   eax
007A8EBD  e85ec1ffff                       call   0x7a5020
007A8EC2  8d4e28                           lea    ecx,[esi+0x28]
007A8EC5  51                               push   ecx
007A8EC6  c644243401                       mov    BYTE PTR [esp+0x34],0x1
007A8ECB  e850c1ffff                       call   0x7a5020
007A8ED0  8d5648                           lea    edx,[esi+0x48]
007A8ED3  52                               push   edx
007A8ED4  c644243402                       mov    BYTE PTR [esp+0x34],0x2
007A8ED9  e842c1ffff                       call   0x7a5020
007A8EDE  897e68                           mov    DWORD PTR [esi+0x68],edi
007A8EE1  897e6c                           mov    DWORD PTR [esi+0x6c],edi
007A8EE4  eb02                             jmp    0x7a8ee8
007A8EE6  33f6                             xor    esi,esi
007A8EE8  56                               push   esi
007A8EE9  8d442420                         lea    eax,[esp+0x20]
007A8EED  c7442434ffffffff                 mov    DWORD PTR [esp+0x34],0xffffffff
007A8EF5  50                               push   eax
007A8EF6  897c2424                         mov    DWORD PTR [esp+0x24],edi
007A8EFA  897c2428                         mov    DWORD PTR [esp+0x28],edi
007A8EFE  e80d190000                       call   0x7aa810
007A8F03  c744243003000000                 mov    DWORD PTR [esp+0x30],0x3
007A8F0B  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
007A8F0F  8b4b18                           mov    ecx,DWORD PTR [ebx+0x18]
007A8F12  8d434c                           lea    eax,[ebx+0x4c]
007A8F15  8d7e28                           lea    edi,[esi+0x28]
007A8F18  890e                             mov    DWORD PTR [esi],ecx
007A8F1A  3bf8                             cmp    edi,eax
007A8F1C  7421                             je     0x7a8f3f
007A8F1E  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A8F21  8b08                             mov    ecx,DWORD PTR [eax]
007A8F23  50                               push   eax
007A8F24  51                               push   ecx
007A8F25  8d74241c                         lea    esi,[esp+0x1c]
007A8F29  8bc7                             mov    eax,edi
007A8F2B  e83012d2ff                       call   0x4ca160
007A8F30  8d434c                           lea    eax,[ebx+0x4c]
007A8F33  50                               push   eax
007A8F34  8bc7                             mov    eax,edi
007A8F36  e80586ffff                       call   0x7a1540
007A8F3B  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
007A8F3F  8d435c                           lea    eax,[ebx+0x5c]
007A8F42  8d7e38                           lea    edi,[esi+0x38]
007A8F45  3bf8                             cmp    edi,eax
007A8F47  7421                             je     0x7a8f6a
007A8F49  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A8F4C  8b08                             mov    ecx,DWORD PTR [eax]
007A8F4E  50                               push   eax
007A8F4F  51                               push   ecx
007A8F50  8d74241c                         lea    esi,[esp+0x1c]
007A8F54  8bc7                             mov    eax,edi
007A8F56  e8c5e1f2ff                       call   0x6d7120
007A8F5B  8d435c                           lea    eax,[ebx+0x5c]
007A8F5E  50                               push   eax
007A8F5F  8bc7                             mov    eax,edi
007A8F61  e8fa86ffff                       call   0x7a1660
007A8F66  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
007A8F6A  8d4310                           lea    eax,[ebx+0x10]
007A8F6D  8d4c2414                         lea    ecx,[esp+0x14]
007A8F71  e81a0e0000                       call   0x7a9d90
007A8F76  8d7e68                           lea    edi,[esi+0x68]
007A8F79  c644243004                       mov    BYTE PTR [esp+0x30],0x4
007A8F7E  e8dd7fd3ff                       call   0x4e0f60
007A8F83  c644243003                       mov    BYTE PTR [esp+0x30],0x3
007A8F88  8b442418                         mov    eax,DWORD PTR [esp+0x18]
007A8F8C  85c0                             test   eax,eax
007A8F8E  742b                             je     0x7a8fbb
007A8F90  8bf0                             mov    esi,eax
007A8F92  83c004                           add    eax,0x4
007A8F95  83caff                           or     edx,0xffffffff
007A8F98  f00fc110                         lock xadd DWORD PTR [eax],edx
007A8F9C  751d                             jne    0x7a8fbb
007A8F9E  8b06                             mov    eax,DWORD PTR [esi]
007A8FA0  8b10                             mov    edx,DWORD PTR [eax]
007A8FA2  8bce                             mov    ecx,esi
007A8FA4  ffd2                             call   edx
007A8FA6  8d4608                           lea    eax,[esi+0x8]
007A8FA9  83c9ff                           or     ecx,0xffffffff
007A8FAC  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A8FB0  7509                             jne    0x7a8fbb
007A8FB2  8b16                             mov    edx,DWORD PTR [esi]
007A8FB4  8b4204                           mov    eax,DWORD PTR [edx+0x4]
007A8FB7  8bce                             mov    ecx,esi
007A8FB9  ffd0                             call   eax
007A8FBB  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
007A8FBF  8d4b2c                           lea    ecx,[ebx+0x2c]
007A8FC2  51                               push   ecx
007A8FC3  8d7e08                           lea    edi,[esi+0x8]
007A8FC6  e865c7ffff                       call   0x7a5730
007A8FCB  837b2400                         cmp    DWORD PTR [ebx+0x24],0x0
007A8FCF  0f94c2                           sete   dl
007A8FD2  885604                           mov    BYTE PTR [esi+0x4],dl
007A8FD5  807b2000                         cmp    BYTE PTR [ebx+0x20],0x0
007A8FD9  7410                             je     0x7a8feb
007A8FDB  6a00                             push   0x0
007A8FDD  6a00                             push   0x0
007A8FDF  6a00                             push   0x0
007A8FE1  6a00                             push   0x0
007A8FE3  ff15cc20bd00                     call   DWORD PTR ds:0xbd20cc
007A8FE9  eb03                             jmp    0x7a8fee
007A8FEB  83c8ff                           or     eax,0xffffffff
007A8FEE  8b7c2420                         mov    edi,DWORD PTR [esp+0x20]
007A8FF2  894670                           mov    DWORD PTR [esi+0x70],eax
007A8FF5  83ec08                           sub    esp,0x8
007A8FF8  8bf4                             mov    esi,esp
007A8FFA  c6432800                         mov    BYTE PTR [ebx+0x28],0x0
007A8FFE  c7432402000000                   mov    DWORD PTR [ebx+0x24],0x2
007A9005  8964241c                         mov    DWORD PTR [esp+0x1c],esp
007A9009  c70600000000                     mov    DWORD PTR [esi],0x0
007A900F  c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
007A9016  85ff                             test   edi,edi
007A9018  7416                             je     0x7a9030
007A901A  8bd7                             mov    edx,edi
007A901C  e82f32cdff                       call   0x47c250
007A9021  84c0                             test   al,al
007A9023  740b                             je     0x7a9030
007A9025  8b442424                         mov    eax,DWORD PTR [esp+0x24]
007A9029  57                               push   edi
007A902A  50                               push   eax
007A902B  e890a1ffff                       call   0x7a31c0
007A9030  c644243805                       mov    BYTE PTR [esp+0x38],0x5
007A9035  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
007A903C  7523                             jne    0x7a9061
007A903E  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
007A9045  c644243806                       mov    BYTE PTR [esp+0x38],0x6
007A904A  e8f13effff                       call   0x79cf40
007A904F  6880dbbc00                       push   0xbcdb80
007A9054  e8c1920e00                       call   0x89231a
007A9059  83c404                           add    esp,0x4
007A905C  c644243805                       mov    BYTE PTR [esp+0x38],0x5
007A9061  b9900efc00                       mov    ecx,0xfc0e90
007A9066  c644243803                       mov    BYTE PTR [esp+0x38],0x3
007A906B  e8004affff                       call   0x79da70
007A9070  807b2000                         cmp    BYTE PTR [ebx+0x20],0x0
007A9074  7427                             je     0x7a909d
007A9076  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
007A907A  8b4e70                           mov    ecx,DWORD PTR [esi+0x70]
007A907D  6aff                             push   0xffffffff
007A907F  51                               push   ecx
007A9080  ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
007A9086  8b5670                           mov    edx,DWORD PTR [esi+0x70]
007A9089  52                               push   edx
007A908A  ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
007A9090  681cf6c400                       push   0xc4f61c
007A9095  e823a00e00                       call   0x8930bd
007A909A  83c404                           add    esp,0x4
007A909D  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
007A90A5  85ff                             test   edi,edi
007A90A7  7429                             je     0x7a90d2
007A90A9  8d4704                           lea    eax,[edi+0x4]
007A90AC  83c9ff                           or     ecx,0xffffffff
007A90AF  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A90B3  751d                             jne    0x7a90d2
007A90B5  8b17                             mov    edx,DWORD PTR [edi]
007A90B7  8b02                             mov    eax,DWORD PTR [edx]
007A90B9  8bcf                             mov    ecx,edi
007A90BB  ffd0                             call   eax
007A90BD  8d4f08                           lea    ecx,[edi+0x8]
007A90C0  83caff                           or     edx,0xffffffff
007A90C3  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A90C7  7509                             jne    0x7a90d2
007A90C9  8b07                             mov    eax,DWORD PTR [edi]
007A90CB  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A90CE  8bcf                             mov    ecx,edi
007A90D0  ffd2                             call   edx
007A90D2  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
007A90D6  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A90DD  59                               pop    ecx
007A90DE  5f                               pop    edi
007A90DF  5e                               pop    esi
007A90E0  5b                               pop    ebx
007A90E1  8be5                             mov    esp,ebp
007A90E3  5d                               pop    ebp
007A90E4  c20400                           ret    0x4

; enqueue_doll_request [NEW_QUEUE_JOIN] 0x79da70..0x79db0c exclusive
0079DA70  55                               push   ebp
0079DA71  8bec                             mov    ebp,esp
0079DA73  6aff                             push   0xffffffff
0079DA75  6870a29000                       push   0x90a270
0079DA7A  64a100000000                     mov    eax,fs:0x0
0079DA80  50                               push   eax
0079DA81  51                               push   ecx
0079DA82  56                               push   esi
0079DA83  57                               push   edi
0079DA84  a1201fd600                       mov    eax,ds:0xd61f20
0079DA89  33c5                             xor    eax,ebp
0079DA8B  50                               push   eax
0079DA8C  8d45f4                           lea    eax,[ebp-0xc]
0079DA8F  64a300000000                     mov    fs:0x0,eax
0079DA95  8bf9                             mov    edi,ecx
0079DA97  8d7770                           lea    esi,[edi+0x70]
0079DA9A  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0079DAA1  56                               push   esi
0079DAA2  8975f0                           mov    DWORD PTR [ebp-0x10],esi
0079DAA5  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0079DAAB  83c728                           add    edi,0x28
0079DAAE  57                               push   edi
0079DAAF  8d4d08                           lea    ecx,[ebp+0x8]
0079DAB2  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0079DAB6  e8a5340000                       call   0x7a0f60
0079DABB  56                               push   esi
0079DABC  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0079DAC2  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0079DAC9  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0079DACC  85f6                             test   esi,esi
0079DACE  7429                             je     0x79daf9
0079DAD0  8d4604                           lea    eax,[esi+0x4]
0079DAD3  83c9ff                           or     ecx,0xffffffff
0079DAD6  f00fc108                         lock xadd DWORD PTR [eax],ecx
0079DADA  751d                             jne    0x79daf9
0079DADC  8b16                             mov    edx,DWORD PTR [esi]
0079DADE  8b02                             mov    eax,DWORD PTR [edx]
0079DAE0  8bce                             mov    ecx,esi
0079DAE2  ffd0                             call   eax
0079DAE4  8d4e08                           lea    ecx,[esi+0x8]
0079DAE7  83caff                           or     edx,0xffffffff
0079DAEA  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079DAEE  7509                             jne    0x79daf9
0079DAF0  8b06                             mov    eax,DWORD PTR [esi]
0079DAF2  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079DAF5  8bce                             mov    ecx,esi
0079DAF7  ffd2                             call   edx
0079DAF9  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0079DAFC  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0079DB03  59                               pop    ecx
0079DB04  5f                               pop    edi
0079DB05  5e                               pop    esi
0079DB06  8be5                             mov    esp,ebp
0079DB08  5d                               pop    ebp
0079DB09  c20800                           ret    0x8

; model_worker_loop [NEW_JOB_ORDER_JOIN] 0x79dea0..0x79e532 exclusive
0079DEA0  55                               push   ebp
0079DEA1  8bec                             mov    ebp,esp
0079DEA3  83e4f8                           and    esp,0xfffffff8
0079DEA6  6aff                             push   0xffffffff
0079DEA8  68858e9300                       push   0x938e85
0079DEAD  64a100000000                     mov    eax,fs:0x0
0079DEB3  50                               push   eax
0079DEB4  81ec90000000                     sub    esp,0x90
0079DEBA  53                               push   ebx
0079DEBB  56                               push   esi
0079DEBC  57                               push   edi
0079DEBD  a1201fd600                       mov    eax,ds:0xd61f20
0079DEC2  33c4                             xor    eax,esp
0079DEC4  50                               push   eax
0079DEC5  8d8424a0000000                   lea    eax,[esp+0xa0]
0079DECC  64a300000000                     mov    fs:0x0,eax
0079DED2  33ff                             xor    edi,edi
0079DED4  6a08                             push   0x8
0079DED6  897c2454                         mov    DWORD PTR [esp+0x54],edi
0079DEDA  e889330f00                       call   0x891268
0079DEDF  83c404                           add    esp,0x4
0079DEE2  3bc7                             cmp    eax,edi
0079DEE4  0f841c060000                     je     0x79e506
0079DEEA  89442450                         mov    DWORD PTR [esp+0x50],eax
0079DEEE  33c9                             xor    ecx,ecx
0079DEF0  8908                             mov    DWORD PTR [eax],ecx
0079DEF2  33d2                             xor    edx,edx
0079DEF4  895004                           mov    DWORD PTR [eax+0x4],edx
0079DEF7  8b4c2450                         mov    ecx,DWORD PTR [esp+0x50]
0079DEFB  8d442450                         lea    eax,[esp+0x50]
0079DEFF  8901                             mov    DWORD PTR [ecx],eax
0079DF01  897c2454                         mov    DWORD PTR [esp+0x54],edi
0079DF05  897c2458                         mov    DWORD PTR [esp+0x58],edi
0079DF09  897c245c                         mov    DWORD PTR [esp+0x5c],edi
0079DF0D  897c2460                         mov    DWORD PTR [esp+0x60],edi
0079DF11  89bc24a8000000                   mov    DWORD PTR [esp+0xa8],edi
0079DF18  6a08                             push   0x8
0079DF1A  897c243c                         mov    DWORD PTR [esp+0x3c],edi
0079DF1E  e845330f00                       call   0x891268
0079DF23  83c404                           add    esp,0x4
0079DF26  3bc7                             cmp    eax,edi
0079DF28  0f84af050000                     je     0x79e4dd
0079DF2E  89442438                         mov    DWORD PTR [esp+0x38],eax
0079DF32  33d2                             xor    edx,edx
0079DF34  895004                           mov    DWORD PTR [eax+0x4],edx
0079DF37  33c9                             xor    ecx,ecx
0079DF39  8908                             mov    DWORD PTR [eax],ecx
0079DF3B  8b442438                         mov    eax,DWORD PTR [esp+0x38]
0079DF3F  8d542438                         lea    edx,[esp+0x38]
0079DF43  8910                             mov    DWORD PTR [eax],edx
0079DF45  897c243c                         mov    DWORD PTR [esp+0x3c],edi
0079DF49  897c2440                         mov    DWORD PTR [esp+0x40],edi
0079DF4D  897c2444                         mov    DWORD PTR [esp+0x44],edi
0079DF51  897c2448                         mov    DWORD PTR [esp+0x48],edi
0079DF55  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079DF58  c68424a800000001                 mov    BYTE PTR [esp+0xa8],0x1
0079DF60  388bc0000000                     cmp    BYTE PTR [ebx+0xc0],cl
0079DF66  0f8506050000                     jne    0x79e472
0079DF6C  8d642400                         lea    esp,[esp+0x0]
0079DF70  8d7370                           lea    esi,[ebx+0x70]
0079DF73  56                               push   esi
0079DF74  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0079DF7A  8b4b28                           mov    ecx,DWORD PTR [ebx+0x28]
0079DF7D  3b4b2c                           cmp    ecx,DWORD PTR [ebx+0x2c]
0079DF80  753a                             jne    0x79dfbc
0079DF82  8b5338                           mov    edx,DWORD PTR [ebx+0x38]
0079DF85  3b533c                           cmp    edx,DWORD PTR [ebx+0x3c]
0079DF88  7532                             jne    0x79dfbc
0079DF8A  397b68                           cmp    DWORD PTR [ebx+0x68],edi
0079DF8D  752d                             jne    0x79dfbc
0079DF8F  56                               push   esi
0079DF90  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0079DF96  80bbc800000000                   cmp    BYTE PTR [ebx+0xc8],0x0
0079DF9D  0f84b8040000                     je     0x79e45b
0079DFA3  8b83cc000000                     mov    eax,DWORD PTR [ebx+0xcc]
0079DFA9  50                               push   eax
0079DFAA  c683c800000000                   mov    BYTE PTR [ebx+0xc8],0x0
0079DFB1  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0079DFB7  e9a7040000                       jmp    0x79e463
0079DFBC  56                               push   esi
0079DFBD  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0079DFC3  8d442450                         lea    eax,[esp+0x50]
0079DFC7  50                               push   eax
0079DFC8  8bf3                             mov    esi,ebx
0079DFCA  e8f1070000                       call   0x79e7c0
0079DFCF  8d4c2438                         lea    ecx,[esp+0x38]
0079DFD3  51                               push   ecx
0079DFD4  e8c7080000                       call   0x79e8a0
0079DFD9  397b68                           cmp    DWORD PTR [ebx+0x68],edi
0079DFDC  0f8447010000                     je     0x79e129
0079DFE2  8b736c                           mov    esi,DWORD PTR [ebx+0x6c]
0079DFE5  8b5368                           mov    edx,DWORD PTR [ebx+0x68]
0079DFE8  33ff                             xor    edi,edi
0079DFEA  897c2428                         mov    DWORD PTR [esp+0x28],edi
0079DFEE  897c242c                         mov    DWORD PTR [esp+0x2c],edi
0079DFF2  89542414                         mov    DWORD PTR [esp+0x14],edx
0079DFF6  3bf7                             cmp    esi,edi
0079DFF8  7436                             je     0x79e030
0079DFFA  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0079DFFD  3bcf                             cmp    ecx,edi
0079DFFF  742b                             je     0x79e02c
0079E001  8d7901                           lea    edi,[ecx+0x1]
0079E004  8d5e04                           lea    ebx,[esi+0x4]
0079E007  8bc1                             mov    eax,ecx
0079E009  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
0079E00D  3bc1                             cmp    eax,ecx
0079E00F  7409                             je     0x79e01a
0079E011  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0079E014  85c9                             test   ecx,ecx
0079E016  75e9                             jne    0x79e001
0079E018  eb0f                             jmp    0x79e029
0079E01A  8b4c2414                         mov    ecx,DWORD PTR [esp+0x14]
0079E01E  56                               push   esi
0079E01F  51                               push   ecx
0079E020  8d742430                         lea    esi,[esp+0x30]
0079E024  e897510000                       call   0x7a31c0
0079E029  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079E02C  8b7c242c                         mov    edi,DWORD PTR [esp+0x2c]
0079E030  83ec08                           sub    esp,0x8
0079E033  c68424b000000002                 mov    BYTE PTR [esp+0xb0],0x2
0079E03B  8bf4                             mov    esi,esp
0079E03D  89642438                         mov    DWORD PTR [esp+0x38],esp
0079E041  c70600000000                     mov    DWORD PTR [esi],0x0
0079E047  c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0079E04E  85ff                             test   edi,edi
0079E050  7430                             je     0x79e082
0079E052  8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0079E055  85c9                             test   ecx,ecx
0079E057  7425                             je     0x79e07e
0079E059  8da42400000000                   lea    esp,[esp+0x0]
0079E060  8d5101                           lea    edx,[ecx+0x1]
0079E063  8d5f04                           lea    ebx,[edi+0x4]
0079E066  8bc1                             mov    eax,ecx
0079E068  f00fb113                         lock cmpxchg DWORD PTR [ebx],edx
0079E06C  3bc1                             cmp    eax,ecx
0079E06E  0f849e000000                     je     0x79e112
0079E074  8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0079E077  85c9                             test   ecx,ecx
0079E079  75e5                             jne    0x79e060
0079E07B  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079E07E  8b7c2434                         mov    edi,DWORD PTR [esp+0x34]
0079E082  53                               push   ebx
0079E083  e828230000                       call   0x7a03b0
0079E088  8b4368                           mov    eax,DWORD PTR [ebx+0x68]
0079E08B  8b08                             mov    ecx,DWORD PTR [eax]
0079E08D  51                               push   ecx
0079E08E  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0079E094  8b736c                           mov    esi,DWORD PTR [ebx+0x6c]
0079E097  33c0                             xor    eax,eax
0079E099  89436c                           mov    DWORD PTR [ebx+0x6c],eax
0079E09C  894368                           mov    DWORD PTR [ebx+0x68],eax
0079E09F  3bf0                             cmp    esi,eax
0079E0A1  7429                             je     0x79e0cc
0079E0A3  8d5604                           lea    edx,[esi+0x4]
0079E0A6  83c8ff                           or     eax,0xffffffff
0079E0A9  f00fc102                         lock xadd DWORD PTR [edx],eax
0079E0AD  751d                             jne    0x79e0cc
0079E0AF  8b16                             mov    edx,DWORD PTR [esi]
0079E0B1  8b02                             mov    eax,DWORD PTR [edx]
0079E0B3  8bce                             mov    ecx,esi
0079E0B5  ffd0                             call   eax
0079E0B7  8d4e08                           lea    ecx,[esi+0x8]
0079E0BA  83caff                           or     edx,0xffffffff
0079E0BD  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079E0C1  7509                             jne    0x79e0cc
0079E0C3  8b06                             mov    eax,DWORD PTR [esi]
0079E0C5  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079E0C8  8bce                             mov    ecx,esi
0079E0CA  ffd2                             call   edx
0079E0CC  c68424a800000001                 mov    BYTE PTR [esp+0xa8],0x1
0079E0D4  85ff                             test   edi,edi
0079E0D6  0f8487030000                     je     0x79e463
0079E0DC  8d4704                           lea    eax,[edi+0x4]
0079E0DF  83c9ff                           or     ecx,0xffffffff
0079E0E2  f00fc108                         lock xadd DWORD PTR [eax],ecx
0079E0E6  0f8577030000                     jne    0x79e463
0079E0EC  8b17                             mov    edx,DWORD PTR [edi]
0079E0EE  8b02                             mov    eax,DWORD PTR [edx]
0079E0F0  8bcf                             mov    ecx,edi
0079E0F2  ffd0                             call   eax
0079E0F4  8d4f08                           lea    ecx,[edi+0x8]
0079E0F7  83caff                           or     edx,0xffffffff
0079E0FA  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079E0FE  0f855f030000                     jne    0x79e463
0079E104  8b07                             mov    eax,DWORD PTR [edi]
0079E106  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079E109  8bcf                             mov    ecx,edi
0079E10B  ffd2                             call   edx
0079E10D  e951030000                       jmp    0x79e463
0079E112  8b7c2434                         mov    edi,DWORD PTR [esp+0x34]
0079E116  8b442430                         mov    eax,DWORD PTR [esp+0x30]
0079E11A  57                               push   edi
0079E11B  50                               push   eax
0079E11C  e89f500000                       call   0x7a31c0
0079E121  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079E124  e959ffffff                       jmp    0x79e082
0079E129  397c2460                         cmp    DWORD PTR [esp+0x60],edi
0079E12D  0f84ac010000                     je     0x79e2df
0079E133  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0079E139  89442414                         mov    DWORD PTR [esp+0x14],eax
0079E13D  397c2460                         cmp    DWORD PTR [esp+0x60],edi
0079E141  0f841c030000                     je     0x79e463
0079E147  eb07                             jmp    0x79e150
0079E149  8da42400000000                   lea    esp,[esp+0x0]
0079E150  8d842490000000                   lea    eax,[esp+0x90]
0079E157  8d4c2450                         lea    ecx,[esp+0x50]
0079E15B  e8b040daff                       call   0x542210
0079E160  8b08                             mov    ecx,DWORD PTR [eax]
0079E162  33ff                             xor    edi,edi
0079E164  3bcf                             cmp    ecx,edi
0079E166  7504                             jne    0x79e16c
0079E168  33d2                             xor    edx,edx
0079E16A  eb02                             jmp    0x79e16e
0079E16C  8b11                             mov    edx,DWORD PTR [ecx]
0079E16E  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0079E171  8b7208                           mov    esi,DWORD PTR [edx+0x8]
0079E174  8bc1                             mov    eax,ecx
0079E176  d1e8                             shr    eax,1
0079E178  83e101                           and    ecx,0x1
0079E17B  3bf0                             cmp    esi,eax
0079E17D  7702                             ja     0x79e181
0079E17F  2bc6                             sub    eax,esi
0079E181  8b5204                           mov    edx,DWORD PTR [edx+0x4]
0079E184  8b0482                           mov    eax,DWORD PTR [edx+eax*4]
0079E187  8b74c804                         mov    esi,DWORD PTR [eax+ecx*8+0x4]
0079E18B  8d04c8                           lea    eax,[eax+ecx*8]
0079E18E  8b08                             mov    ecx,DWORD PTR [eax]
0079E190  897c2420                         mov    DWORD PTR [esp+0x20],edi
0079E194  897c2424                         mov    DWORD PTR [esp+0x24],edi
0079E198  894c2434                         mov    DWORD PTR [esp+0x34],ecx
0079E19C  3bf7                             cmp    esi,edi
0079E19E  7426                             je     0x79e1c6
0079E1A0  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0079E1A3  3bcf                             cmp    ecx,edi
0079E1A5  741b                             je     0x79e1c2
0079E1A7  8d7901                           lea    edi,[ecx+0x1]
0079E1AA  8d5e04                           lea    ebx,[esi+0x4]
0079E1AD  8bc1                             mov    eax,ecx
0079E1AF  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
0079E1B3  3bc1                             cmp    eax,ecx
0079E1B5  0f84cf000000                     je     0x79e28a
0079E1BB  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0079E1BE  85c9                             test   ecx,ecx
0079E1C0  75e5                             jne    0x79e1a7
0079E1C2  8b7c2424                         mov    edi,DWORD PTR [esp+0x24]
0079E1C6  8d742450                         lea    esi,[esp+0x50]
0079E1CA  c68424a800000003                 mov    BYTE PTR [esp+0xa8],0x3
0079E1D2  e809320000                       call   0x7a13e0
0079E1D7  83ec08                           sub    esp,0x8
0079E1DA  8bdc                             mov    ebx,esp
0079E1DC  89642438                         mov    DWORD PTR [esp+0x38],esp
0079E1E0  c70300000000                     mov    DWORD PTR [ebx],0x0
0079E1E6  c7430400000000                   mov    DWORD PTR [ebx+0x4],0x0
0079E1ED  85ff                             test   edi,edi
0079E1EF  7426                             je     0x79e217
0079E1F1  8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0079E1F4  85c9                             test   ecx,ecx
0079E1F6  741b                             je     0x79e213
0079E1F8  8d5101                           lea    edx,[ecx+0x1]
0079E1FB  8d7704                           lea    esi,[edi+0x4]
0079E1FE  8bc1                             mov    eax,ecx
0079E200  f00fb116                         lock cmpxchg DWORD PTR [esi],edx
0079E204  3bc1                             cmp    eax,ecx
0079E206  0f8491000000                     je     0x79e29d
0079E20C  8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0079E20F  85c9                             test   ecx,ecx
0079E211  75e5                             jne    0x79e1f8
0079E213  8b7c242c                         mov    edi,DWORD PTR [esp+0x2c]
0079E217  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0079E21A  51                               push   ecx
0079E21B  e860070000                       call   0x79e980
0079E220  8b35a025bd00                     mov    esi,DWORD PTR ds:0xbd25a0
0079E226  83c40c                           add    esp,0xc
0079E229  ffd6                             call   esi
0079E22B  2b442414                         sub    eax,DWORD PTR [esp+0x14]
0079E22F  83f80f                           cmp    eax,0xf
0079E232  760e                             jbe    0x79e242
0079E234  ffd6                             call   esi
0079E236  6a05                             push   0x5
0079E238  89442418                         mov    DWORD PTR [esp+0x18],eax
0079E23C  ff150423bd00                     call   DWORD PTR ds:0xbd2304
0079E242  c68424a800000001                 mov    BYTE PTR [esp+0xa8],0x1
0079E24A  85ff                             test   edi,edi
0079E24C  7429                             je     0x79e277
0079E24E  8d5704                           lea    edx,[edi+0x4]
0079E251  83c8ff                           or     eax,0xffffffff
0079E254  f00fc102                         lock xadd DWORD PTR [edx],eax
0079E258  751d                             jne    0x79e277
0079E25A  8b17                             mov    edx,DWORD PTR [edi]
0079E25C  8b02                             mov    eax,DWORD PTR [edx]
0079E25E  8bcf                             mov    ecx,edi
0079E260  ffd0                             call   eax
0079E262  8d4f08                           lea    ecx,[edi+0x8]
0079E265  83caff                           or     edx,0xffffffff
0079E268  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079E26C  7509                             jne    0x79e277
0079E26E  8b07                             mov    eax,DWORD PTR [edi]
0079E270  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079E273  8bcf                             mov    ecx,edi
0079E275  ffd2                             call   edx
0079E277  837c246000                       cmp    DWORD PTR [esp+0x60],0x0
0079E27C  0f85cefeffff                     jne    0x79e150
0079E282  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079E285  e9d9010000                       jmp    0x79e463
0079E28A  8b4c2434                         mov    ecx,DWORD PTR [esp+0x34]
0079E28E  8bfe                             mov    edi,esi
0079E290  897c2424                         mov    DWORD PTR [esp+0x24],edi
0079E294  894c2420                         mov    DWORD PTR [esp+0x20],ecx
0079E298  e929ffffff                       jmp    0x79e1c6
0079E29D  8b7304                           mov    esi,DWORD PTR [ebx+0x4]
0079E2A0  85f6                             test   esi,esi
0079E2A2  7429                             je     0x79e2cd
0079E2A4  8d4604                           lea    eax,[esi+0x4]
0079E2A7  83c9ff                           or     ecx,0xffffffff
0079E2AA  f00fc108                         lock xadd DWORD PTR [eax],ecx
0079E2AE  751d                             jne    0x79e2cd
0079E2B0  8b16                             mov    edx,DWORD PTR [esi]
0079E2B2  8b02                             mov    eax,DWORD PTR [edx]
0079E2B4  8bce                             mov    ecx,esi
0079E2B6  ffd0                             call   eax
0079E2B8  8d4e08                           lea    ecx,[esi+0x8]
0079E2BB  83caff                           or     edx,0xffffffff
0079E2BE  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079E2C2  7509                             jne    0x79e2cd
0079E2C4  8b06                             mov    eax,DWORD PTR [esi]
0079E2C6  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079E2C9  8bce                             mov    ecx,esi
0079E2CB  ffd2                             call   edx
0079E2CD  8b7c242c                         mov    edi,DWORD PTR [esp+0x2c]
0079E2D1  8b442428                         mov    eax,DWORD PTR [esp+0x28]
0079E2D5  897b04                           mov    DWORD PTR [ebx+0x4],edi
0079E2D8  8903                             mov    DWORD PTR [ebx],eax
0079E2DA  e938ffffff                       jmp    0x79e217
0079E2DF  397c2448                         cmp    DWORD PTR [esp+0x48],edi
0079E2E3  0f847a010000                     je     0x79e463
0079E2E9  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0079E2EF  89442414                         mov    DWORD PTR [esp+0x14],eax
0079E2F3  397c2448                         cmp    DWORD PTR [esp+0x48],edi
0079E2F7  0f8466010000                     je     0x79e463
0079E2FD  8d4900                           lea    ecx,[ecx+0x0]
0079E300  8d842484000000                   lea    eax,[esp+0x84]
0079E307  8d4c2438                         lea    ecx,[esp+0x38]
0079E30B  e8003fdaff                       call   0x542210
0079E310  8b08                             mov    ecx,DWORD PTR [eax]
0079E312  85c9                             test   ecx,ecx
0079E314  7504                             jne    0x79e31a
0079E316  33d2                             xor    edx,edx
0079E318  eb02                             jmp    0x79e31c
0079E31A  8b11                             mov    edx,DWORD PTR [ecx]
0079E31C  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0079E31F  8b7208                           mov    esi,DWORD PTR [edx+0x8]
0079E322  8bc1                             mov    eax,ecx
0079E324  d1e8                             shr    eax,1
0079E326  83e101                           and    ecx,0x1
0079E329  3bf0                             cmp    esi,eax
0079E32B  7702                             ja     0x79e32f
0079E32D  2bc6                             sub    eax,esi
0079E32F  8b5204                           mov    edx,DWORD PTR [edx+0x4]
0079E332  8b0482                           mov    eax,DWORD PTR [edx+eax*4]
0079E335  8b74c804                         mov    esi,DWORD PTR [eax+ecx*8+0x4]
0079E339  8d04c8                           lea    eax,[eax+ecx*8]
0079E33C  8b08                             mov    ecx,DWORD PTR [eax]
0079E33E  33ff                             xor    edi,edi
0079E340  897c2418                         mov    DWORD PTR [esp+0x18],edi
0079E344  897c241c                         mov    DWORD PTR [esp+0x1c],edi
0079E348  894c2434                         mov    DWORD PTR [esp+0x34],ecx
0079E34C  85f6                             test   esi,esi
0079E34E  7436                             je     0x79e386
0079E350  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0079E353  85c9                             test   ecx,ecx
0079E355  742b                             je     0x79e382
0079E357  8d7901                           lea    edi,[ecx+0x1]
0079E35A  8d5e04                           lea    ebx,[esi+0x4]
0079E35D  8bc1                             mov    eax,ecx
0079E35F  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
0079E363  3bc1                             cmp    eax,ecx
0079E365  7409                             je     0x79e370
0079E367  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0079E36A  85c9                             test   ecx,ecx
0079E36C  75e9                             jne    0x79e357
0079E36E  eb0f                             jmp    0x79e37f
0079E370  8b4c2434                         mov    ecx,DWORD PTR [esp+0x34]
0079E374  56                               push   esi
0079E375  51                               push   ecx
0079E376  8d742420                         lea    esi,[esp+0x20]
0079E37A  e8414e0000                       call   0x7a31c0
0079E37F  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079E382  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
0079E386  8d742438                         lea    esi,[esp+0x38]
0079E38A  c68424a800000004                 mov    BYTE PTR [esp+0xa8],0x4
0079E392  e849300000                       call   0x7a13e0
0079E397  83ec08                           sub    esp,0x8
0079E39A  8bf4                             mov    esi,esp
0079E39C  89642438                         mov    DWORD PTR [esp+0x38],esp
0079E3A0  c70600000000                     mov    DWORD PTR [esi],0x0
0079E3A6  c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0079E3AD  85ff                             test   edi,edi
0079E3AF  742b                             je     0x79e3dc
0079E3B1  8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0079E3B4  8d5704                           lea    edx,[edi+0x4]
0079E3B7  85c9                             test   ecx,ecx
0079E3B9  741d                             je     0x79e3d8
0079E3BB  eb03                             jmp    0x79e3c0
0079E3BD  8d4900                           lea    ecx,[ecx+0x0]
0079E3C0  8d7901                           lea    edi,[ecx+0x1]
0079E3C3  8bda                             mov    ebx,edx
0079E3C5  8bc1                             mov    eax,ecx
0079E3C7  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
0079E3CB  3bc1                             cmp    eax,ecx
0079E3CD  7478                             je     0x79e447
0079E3CF  8b0a                             mov    ecx,DWORD PTR [edx]
0079E3D1  85c9                             test   ecx,ecx
0079E3D3  75eb                             jne    0x79e3c0
0079E3D5  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079E3D8  8b7c2424                         mov    edi,DWORD PTR [esp+0x24]
0079E3DC  8bcb                             mov    ecx,ebx
0079E3DE  e81d090000                       call   0x79ed00
0079E3E3  8b35a025bd00                     mov    esi,DWORD PTR ds:0xbd25a0
0079E3E9  83c408                           add    esp,0x8
0079E3EC  ffd6                             call   esi
0079E3EE  2b442414                         sub    eax,DWORD PTR [esp+0x14]
0079E3F2  83f80f                           cmp    eax,0xf
0079E3F5  760e                             jbe    0x79e405
0079E3F7  ffd6                             call   esi
0079E3F9  6a05                             push   0x5
0079E3FB  89442418                         mov    DWORD PTR [esp+0x18],eax
0079E3FF  ff150423bd00                     call   DWORD PTR ds:0xbd2304
0079E405  c68424a800000001                 mov    BYTE PTR [esp+0xa8],0x1
0079E40D  85ff                             test   edi,edi
0079E40F  7429                             je     0x79e43a
0079E411  8d5704                           lea    edx,[edi+0x4]
0079E414  83c8ff                           or     eax,0xffffffff
0079E417  f00fc102                         lock xadd DWORD PTR [edx],eax
0079E41B  751d                             jne    0x79e43a
0079E41D  8b17                             mov    edx,DWORD PTR [edi]
0079E41F  8b02                             mov    eax,DWORD PTR [edx]
0079E421  8bcf                             mov    ecx,edi
0079E423  ffd0                             call   eax
0079E425  8d4f08                           lea    ecx,[edi+0x8]
0079E428  83caff                           or     edx,0xffffffff
0079E42B  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079E42F  7509                             jne    0x79e43a
0079E431  8b07                             mov    eax,DWORD PTR [edi]
0079E433  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079E436  8bcf                             mov    ecx,edi
0079E438  ffd2                             call   edx
0079E43A  837c244800                       cmp    DWORD PTR [esp+0x48],0x0
0079E43F  0f85bbfeffff                     jne    0x79e300
0079E445  eb1c                             jmp    0x79e463
0079E447  8b7c2424                         mov    edi,DWORD PTR [esp+0x24]
0079E44B  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0079E44F  57                               push   edi
0079E450  51                               push   ecx
0079E451  e86a4d0000                       call   0x7a31c0
0079E456  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079E459  eb81                             jmp    0x79e3dc
0079E45B  6a0f                             push   0xf
0079E45D  ff150423bd00                     call   DWORD PTR ds:0xbd2304
0079E463  33ff                             xor    edi,edi
0079E465  80bbc000000000                   cmp    BYTE PTR [ebx+0xc0],0x0
0079E46C  0f84fefaffff                     je     0x79df70
0079E472  8b8bc4000000                     mov    ecx,DWORD PTR [ebx+0xc4]
0079E478  51                               push   ecx
0079E479  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0079E47F  e8ee770f00                       call   0x895c72
0079E484  8d742438                         lea    esi,[esp+0x38]
0079E488  c68424a800000005                 mov    BYTE PTR [esp+0xa8],0x5
0079E490  e88b2e0000                       call   0x7a1320
0079E495  8b542438                         mov    edx,DWORD PTR [esp+0x38]
0079E499  52                               push   edx
0079E49A  e86d2d0f00                       call   0x89120c
0079E49F  83c404                           add    esp,0x4
0079E4A2  897c2438                         mov    DWORD PTR [esp+0x38],edi
0079E4A6  8d742450                         lea    esi,[esp+0x50]
0079E4AA  c78424a800000006000000           mov    DWORD PTR [esp+0xa8],0x6
0079E4B5  e8662e0000                       call   0x7a1320
0079E4BA  8b442450                         mov    eax,DWORD PTR [esp+0x50]
0079E4BE  50                               push   eax
0079E4BF  e8482d0f00                       call   0x89120c
0079E4C4  83c404                           add    esp,0x4
0079E4C7  8b8c24a0000000                   mov    ecx,DWORD PTR [esp+0xa0]
0079E4CE  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0079E4D5  59                               pop    ecx
0079E4D6  5f                               pop    edi
0079E4D7  5e                               pop    esi
0079E4D8  5b                               pop    ebx
0079E4D9  8be5                             mov    esp,ebp
0079E4DB  5d                               pop    ebp
0079E4DC  c3                               ret
0079E4DD  8d4c2468                         lea    ecx,[esp+0x68]
0079E4E1  51                               push   ecx
0079E4E2  8d4c2470                         lea    ecx,[esp+0x70]
0079E4E6  897c246c                         mov    DWORD PTR [esp+0x6c],edi
0079E4EA  e8ba2b0f00                       call   0x8910a9
0079E4EF  68a857c800                       push   0xc857a8
0079E4F4  8d542470                         lea    edx,[esp+0x70]
0079E4F8  52                               push   edx
0079E4F9  c7442474a42cbd00                 mov    DWORD PTR [esp+0x74],0xbd2ca4
0079E501  e8eae40f00                       call   0x89c9f0
0079E506  8d442430                         lea    eax,[esp+0x30]
0079E50A  50                               push   eax
0079E50B  8d4c247c                         lea    ecx,[esp+0x7c]
0079E50F  897c2434                         mov    DWORD PTR [esp+0x34],edi
0079E513  e8912b0f00                       call   0x8910a9
0079E518  68a857c800                       push   0xc857a8
0079E51D  8d4c247c                         lea    ecx,[esp+0x7c]
0079E521  51                               push   ecx
0079E522  c7842480000000a42cbd00           mov    DWORD PTR [esp+0x80],0xbd2ca4
0079E52D  e8bee40f00                       call   0x89c9f0

; doll_request_worker [NEW_RESOURCE_LEASE_JOIN] 0x79e980..0x79ecf7 exclusive
0079E980  55                               push   ebp
0079E981  8bec                             mov    ebp,esp
0079E983  6aff                             push   0xffffffff
0079E985  68338c9300                       push   0x938c33
0079E98A  64a100000000                     mov    eax,fs:0x0
0079E990  50                               push   eax
0079E991  83ec30                           sub    esp,0x30
0079E994  53                               push   ebx
0079E995  56                               push   esi
0079E996  57                               push   edi
0079E997  a1201fd600                       mov    eax,ds:0xd61f20
0079E99C  33c5                             xor    eax,ebp
0079E99E  50                               push   eax
0079E99F  8d45f4                           lea    eax,[ebp-0xc]
0079E9A2  64a300000000                     mov    fs:0x0,eax
0079E9A8  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079E9AB  33f6                             xor    esi,esi
0079E9AD  8975fc                           mov    DWORD PTR [ebp-0x4],esi
0079E9B0  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0079E9B3  8b08                             mov    ecx,DWORD PTR [eax]
0079E9B5  8d55e8                           lea    edx,[ebp-0x18]
0079E9B8  894de8                           mov    DWORD PTR [ebp-0x18],ecx
0079E9BB  52                               push   edx
0079E9BC  8d45e4                           lea    eax,[ebp-0x1c]
0079E9BF  8bcb                             mov    ecx,ebx
0079E9C1  e8ca6dd7ff                       call   0x515790
0079E9C6  8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
0079E9C9  3b4b04                           cmp    ecx,DWORD PTR [ebx+0x4]
0079E9CC  7411                             je     0x79e9df
0079E9CE  8b4110                           mov    eax,DWORD PTR [ecx+0x10]
0079E9D1  8b7854                           mov    edi,DWORD PTR [eax+0x54]
0079E9D4  897dec                           mov    DWORD PTR [ebp-0x14],edi
0079E9D7  3bfe                             cmp    edi,esi
0079E9D9  0f8509010000                     jne    0x79eae8
0079E9DF  6a28                             push   0x28
0079E9E1  e882280f00                       call   0x891268
0079E9E6  83c404                           add    esp,0x4
0079E9E9  894508                           mov    DWORD PTR [ebp+0x8],eax
0079E9EC  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0079E9F0  3bc6                             cmp    eax,esi
0079E9F2  7408                             je     0x79e9fc
0079E9F4  50                               push   eax
0079E9F5  e896e4ffff                       call   0x79ce90
0079E9FA  eb02                             jmp    0x79e9fe
0079E9FC  33c0                             xor    eax,eax
0079E9FE  50                               push   eax
0079E9FF  8d45cc                           lea    eax,[ebp-0x34]
0079EA02  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0079EA06  50                               push   eax
0079EA07  8975cc                           mov    DWORD PTR [ebp-0x34],esi
0079EA0A  8975d0                           mov    DWORD PTR [ebp-0x30],esi
0079EA0D  e8ee490000                       call   0x7a3400
0079EA12  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0079EA16  8b75cc                           mov    esi,DWORD PTR [ebp-0x34]
0079EA19  8d7e08                           lea    edi,[esi+0x8]
0079EA1C  8d450c                           lea    eax,[ebp+0xc]
0079EA1F  c60600                           mov    BYTE PTR [esi],0x0
0079EA22  e879230000                       call   0x7a0da0
0079EA27  33c0                             xor    eax,eax
0079EA29  894604                           mov    DWORD PTR [esi+0x4],eax
0079EA2C  894610                           mov    DWORD PTR [esi+0x10],eax
0079EA2F  894614                           mov    DWORD PTR [esi+0x14],eax
0079EA32  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0079EA35  837970ff                         cmp    DWORD PTR [ecx+0x70],0xffffffff
0079EA39  7443                             je     0x79ea7e
0079EA3B  8b7dd0                           mov    edi,DWORD PTR [ebp-0x30]
0079EA3E  83ec08                           sub    esp,0x8
0079EA41  8bdc                             mov    ebx,esp
0079EA43  896508                           mov    DWORD PTR [ebp+0x8],esp
0079EA46  8903                             mov    DWORD PTR [ebx],eax
0079EA48  894304                           mov    DWORD PTR [ebx+0x4],eax
0079EA4B  85ff                             test   edi,edi
0079EA4D  7414                             je     0x79ea63
0079EA4F  8bd7                             mov    edx,edi
0079EA51  e8fad7cdff                       call   0x47c250
0079EA56  84c0                             test   al,al
0079EA58  7409                             je     0x79ea63
0079EA5A  57                               push   edi
0079EA5B  56                               push   esi
0079EA5C  8bf3                             mov    esi,ebx
0079EA5E  e85d470000                       call   0x7a31c0
0079EA63  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0079EA66  8b4268                           mov    eax,DWORD PTR [edx+0x68]
0079EA69  50                               push   eax
0079EA6A  e881a60000                       call   0x7a90f0
0079EA6F  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0079EA72  8b4870                           mov    ecx,DWORD PTR [eax+0x70]
0079EA75  51                               push   ecx
0079EA76  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0079EA7C  eb2d                             jmp    0x79eaab
0079EA7E  8db398000000                     lea    esi,[ebx+0x98]
0079EA84  56                               push   esi
0079EA85  8975d8                           mov    DWORD PTR [ebp-0x28],esi
0079EA88  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0079EA8E  81c388000000                     add    ebx,0x88
0079EA94  53                               push   ebx
0079EA95  8d4dcc                           lea    ecx,[ebp-0x34]
0079EA98  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0079EA9C  e8bf240000                       call   0x7a0f60
0079EAA1  56                               push   esi
0079EAA2  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0079EAA8  8b7dd0                           mov    edi,DWORD PTR [ebp-0x30]
0079EAAB  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0079EAAF  85ff                             test   edi,edi
0079EAB1  0f84f7010000                     je     0x79ecae
0079EAB7  8d5704                           lea    edx,[edi+0x4]
0079EABA  83c8ff                           or     eax,0xffffffff
0079EABD  f00fc102                         lock xadd DWORD PTR [edx],eax
0079EAC1  0f85e7010000                     jne    0x79ecae
0079EAC7  8b17                             mov    edx,DWORD PTR [edi]
0079EAC9  8b02                             mov    eax,DWORD PTR [edx]
0079EACB  8bcf                             mov    ecx,edi
0079EACD  ffd0                             call   eax
0079EACF  8d4f08                           lea    ecx,[edi+0x8]
0079EAD2  83caff                           or     edx,0xffffffff
0079EAD5  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079EAD9  0f85cf010000                     jne    0x79ecae
0079EADF  8b07                             mov    eax,DWORD PTR [edi]
0079EAE1  8bcf                             mov    ecx,edi
0079EAE3  e9c1010000                       jmp    0x79eca9
0079EAE8  837f5010                         cmp    DWORD PTR [edi+0x50],0x10
0079EAEC  8d473c                           lea    eax,[edi+0x3c]
0079EAEF  7202                             jb     0x79eaf3
0079EAF1  8b00                             mov    eax,DWORD PTR [eax]
0079EAF3  8b4f5c                           mov    ecx,DWORD PTR [edi+0x5c]
0079EAF6  41                               inc    ecx
0079EAF7  51                               push   ecx
0079EAF8  50                               push   eax
0079EAF9  6824fec400                       push   0xc4fe24
0079EAFE  e8ba450f00                       call   0x8930bd
0079EB03  ff475c                           inc    DWORD PTR [edi+0x5c]
0079EB06  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0079EB09  83c40c                           add    esp,0xc
0079EB0C  8d5048                           lea    edx,[eax+0x48]
0079EB0F  52                               push   edx
0079EB10  83c028                           add    eax,0x28
0079EB13  50                               push   eax
0079EB14  57                               push   edi
0079EB15  e8a6100000                       call   0x79fbc0
0079EB1A  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0079EB1D  8b404c                           mov    eax,DWORD PTR [eax+0x4c]
0079EB20  8b30                             mov    esi,DWORD PTR [eax]
0079EB22  83c40c                           add    esp,0xc
0079EB25  3bf0                             cmp    esi,eax
0079EB27  7466                             je     0x79eb8f
0079EB29  8da42400000000                   lea    esp,[esp+0x0]
0079EB30  0fb74e0e                         movzx  ecx,WORD PTR [esi+0xe]
0079EB34  0fb7460c                         movzx  eax,WORD PTR [esi+0xc]
0079EB38  6a01                             push   0x1
0079EB3A  57                               push   edi
0079EB3B  e810700200                       call   0x7c5b50
0079EB40  807e1100                         cmp    BYTE PTR [esi+0x11],0x0
0079EB44  7541                             jne    0x79eb87
0079EB46  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0079EB49  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EB4D  751d                             jne    0x79eb6c
0079EB4F  8bf0                             mov    esi,eax
0079EB51  8b06                             mov    eax,DWORD PTR [esi]
0079EB53  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EB57  752e                             jne    0x79eb87
0079EB59  8da42400000000                   lea    esp,[esp+0x0]
0079EB60  8bf0                             mov    esi,eax
0079EB62  8b06                             mov    eax,DWORD PTR [esi]
0079EB64  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EB68  74f6                             je     0x79eb60
0079EB6A  eb1b                             jmp    0x79eb87
0079EB6C  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0079EB6F  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EB73  7510                             jne    0x79eb85
0079EB75  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0079EB78  750b                             jne    0x79eb85
0079EB7A  8bf0                             mov    esi,eax
0079EB7C  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0079EB7F  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EB83  74f0                             je     0x79eb75
0079EB85  8bf0                             mov    esi,eax
0079EB87  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0079EB8A  3b714c                           cmp    esi,DWORD PTR [ecx+0x4c]
0079EB8D  75a1                             jne    0x79eb30
0079EB8F  83ec08                           sub    esp,0x8
0079EB92  8bf4                             mov    esi,esp
0079EB94  c70600000000                     mov    DWORD PTR [esi],0x0
0079EB9A  c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0079EBA1  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0079EBA4  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0079EBA7  8965d8                           mov    DWORD PTR [ebp-0x28],esp
0079EBAA  8945e0                           mov    DWORD PTR [ebp-0x20],eax
0079EBAD  8955dc                           mov    DWORD PTR [ebp-0x24],edx
0079EBB0  85c0                             test   eax,eax
0079EBB2  7436                             je     0x79ebea
0079EBB4  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0079EBB7  8d5004                           lea    edx,[eax+0x4]
0079EBBA  85c9                             test   ecx,ecx
0079EBBC  742c                             je     0x79ebea
0079EBBE  8bff                             mov    edi,edi
0079EBC0  8d7901                           lea    edi,[ecx+0x1]
0079EBC3  8bda                             mov    ebx,edx
0079EBC5  8bc1                             mov    eax,ecx
0079EBC7  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
0079EBCB  3bc1                             cmp    eax,ecx
0079EBCD  7408                             je     0x79ebd7
0079EBCF  8b0a                             mov    ecx,DWORD PTR [edx]
0079EBD1  85c9                             test   ecx,ecx
0079EBD3  75eb                             jne    0x79ebc0
0079EBD5  eb0d                             jmp    0x79ebe4
0079EBD7  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
0079EBDA  8b55dc                           mov    edx,DWORD PTR [ebp-0x24]
0079EBDD  51                               push   ecx
0079EBDE  52                               push   edx
0079EBDF  e8dc450000                       call   0x7a31c0
0079EBE4  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0079EBE7  8b7dec                           mov    edi,DWORD PTR [ebp-0x14]
0079EBEA  8d45c4                           lea    eax,[ebp-0x3c]
0079EBED  57                               push   edi
0079EBEE  50                               push   eax
0079EBEF  e8cc030000                       call   0x79efc0
0079EBF4  83c410                           add    esp,0x10
0079EBF7  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0079EBFB  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0079EBFE  837970ff                         cmp    DWORD PTR [ecx+0x70],0xffffffff
0079EC02  744c                             je     0x79ec50
0079EC04  83ec08                           sub    esp,0x8
0079EC07  8bf4                             mov    esi,esp
0079EC09  c70600000000                     mov    DWORD PTR [esi],0x0
0079EC0F  c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0079EC16  8b55c8                           mov    edx,DWORD PTR [ebp-0x38]
0079EC19  8b5dc4                           mov    ebx,DWORD PTR [ebp-0x3c]
0079EC1C  896508                           mov    DWORD PTR [ebp+0x8],esp
0079EC1F  8bfa                             mov    edi,edx
0079EC21  85d2                             test   edx,edx
0079EC23  7410                             je     0x79ec35
0079EC25  e826d6cdff                       call   0x47c250
0079EC2A  84c0                             test   al,al
0079EC2C  7407                             je     0x79ec35
0079EC2E  57                               push   edi
0079EC2F  53                               push   ebx
0079EC30  e88b450000                       call   0x7a31c0
0079EC35  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0079EC38  8b4268                           mov    eax,DWORD PTR [edx+0x68]
0079EC3B  50                               push   eax
0079EC3C  e8afa40000                       call   0x7a90f0
0079EC41  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0079EC44  8b4870                           mov    ecx,DWORD PTR [eax+0x70]
0079EC47  51                               push   ecx
0079EC48  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0079EC4E  eb2a                             jmp    0x79ec7a
0079EC50  8db398000000                     lea    esi,[ebx+0x98]
0079EC56  56                               push   esi
0079EC57  8975d4                           mov    DWORD PTR [ebp-0x2c],esi
0079EC5A  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0079EC60  81c388000000                     add    ebx,0x88
0079EC66  53                               push   ebx
0079EC67  8d4dc4                           lea    ecx,[ebp-0x3c]
0079EC6A  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0079EC6E  e8ed220000                       call   0x7a0f60
0079EC73  56                               push   esi
0079EC74  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0079EC7A  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0079EC7E  8b75c8                           mov    esi,DWORD PTR [ebp-0x38]
0079EC81  85f6                             test   esi,esi
0079EC83  7429                             je     0x79ecae
0079EC85  8d5604                           lea    edx,[esi+0x4]
0079EC88  83c8ff                           or     eax,0xffffffff
0079EC8B  f00fc102                         lock xadd DWORD PTR [edx],eax
0079EC8F  751d                             jne    0x79ecae
0079EC91  8b16                             mov    edx,DWORD PTR [esi]
0079EC93  8b02                             mov    eax,DWORD PTR [edx]
0079EC95  8bce                             mov    ecx,esi
0079EC97  ffd0                             call   eax
0079EC99  8d4e08                           lea    ecx,[esi+0x8]
0079EC9C  83caff                           or     edx,0xffffffff
0079EC9F  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079ECA3  7509                             jne    0x79ecae
0079ECA5  8b06                             mov    eax,DWORD PTR [esi]
0079ECA7  8bce                             mov    ecx,esi
0079ECA9  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079ECAC  ffd2                             call   edx
0079ECAE  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0079ECB5  8b7510                           mov    esi,DWORD PTR [ebp+0x10]
0079ECB8  85f6                             test   esi,esi
0079ECBA  7429                             je     0x79ece5
0079ECBC  83c9ff                           or     ecx,0xffffffff
0079ECBF  8d4604                           lea    eax,[esi+0x4]
0079ECC2  f00fc108                         lock xadd DWORD PTR [eax],ecx
0079ECC6  751d                             jne    0x79ece5
0079ECC8  8b16                             mov    edx,DWORD PTR [esi]
0079ECCA  8b02                             mov    eax,DWORD PTR [edx]
0079ECCC  8bce                             mov    ecx,esi
0079ECCE  ffd0                             call   eax
0079ECD0  83caff                           or     edx,0xffffffff
0079ECD3  8d4e08                           lea    ecx,[esi+0x8]
0079ECD6  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079ECDA  7509                             jne    0x79ece5
0079ECDC  8b06                             mov    eax,DWORD PTR [esi]
0079ECDE  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079ECE1  8bce                             mov    ecx,esi
0079ECE3  ffd2                             call   edx
0079ECE5  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0079ECE8  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0079ECEF  59                               pop    ecx
0079ECF0  5f                               pop    edi
0079ECF1  5e                               pop    esi
0079ECF2  5b                               pop    ebx
0079ECF3  8be5                             mov    esp,ebp
0079ECF5  5d                               pop    ebp
0079ECF6  c3                               ret

; materialize_reload_prefix [NEW_SAME_RESOURCE_RELOAD_JOIN] 0x79efc0..0x79f074 exclusive
0079EFC0  55                               push   ebp
0079EFC1  8bec                             mov    ebp,esp
0079EFC3  6aff                             push   0xffffffff
0079EFC5  68ab8b9300                       push   0x938bab
0079EFCA  64a100000000                     mov    eax,fs:0x0
0079EFD0  50                               push   eax
0079EFD1  81ec8c000000                     sub    esp,0x8c
0079EFD7  53                               push   ebx
0079EFD8  56                               push   esi
0079EFD9  57                               push   edi
0079EFDA  a1201fd600                       mov    eax,ds:0xd61f20
0079EFDF  33c5                             xor    eax,ebp
0079EFE1  50                               push   eax
0079EFE2  8d45f4                           lea    eax,[ebp-0xc]
0079EFE5  64a300000000                     mov    fs:0x0,eax
0079EFEB  33f6                             xor    esi,esi
0079EFED  897584                           mov    DWORD PTR [ebp-0x7c],esi
0079EFF0  6a28                             push   0x28
0079EFF2  c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0079EFF9  e86a220f00                       call   0x891268
0079EFFE  83c404                           add    esp,0x4
0079F001  8945d4                           mov    DWORD PTR [ebp-0x2c],eax
0079F004  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0079F008  3bc6                             cmp    eax,esi
0079F00A  7408                             je     0x79f014
0079F00C  50                               push   eax
0079F00D  e87edeffff                       call   0x79ce90
0079F012  eb02                             jmp    0x79f016
0079F014  33c0                             xor    eax,eax
0079F016  50                               push   eax
0079F017  8d45e8                           lea    eax,[ebp-0x18]
0079F01A  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0079F01E  50                               push   eax
0079F01F  8975e8                           mov    DWORD PTR [ebp-0x18],esi
0079F022  8975ec                           mov    DWORD PTR [ebp-0x14],esi
0079F025  e8d6430000                       call   0x7a3400
0079F02A  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0079F02E  8b5de8                           mov    ebx,DWORD PTR [ebp-0x18]
0079F031  8d7b08                           lea    edi,[ebx+0x8]
0079F034  8d4510                           lea    eax,[ebp+0x10]
0079F037  c60301                           mov    BYTE PTR [ebx],0x1
0079F03A  e8611d0000                       call   0x7a0da0
0079F03F  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0079F042  894b04                           mov    DWORD PTR [ebx+0x4],ecx
0079F045  e8966b0200                       call   0x7c5be0
0079F04A  8b7510                           mov    esi,DWORD PTR [ebp+0x10]
0079F04D  8b464c                           mov    eax,DWORD PTR [esi+0x4c]
0079F050  8b38                             mov    edi,DWORD PTR [eax]
0079F052  3bf8                             cmp    edi,eax
0079F054  7469                             je     0x79f0bf
0079F056  83c310                           add    ebx,0x10
0079F059  8da42400000000                   lea    esp,[esp+0x0]
0079F060  0fb74f0e                         movzx  ecx,WORD PTR [edi+0xe]
0079F064  0fb7570c                         movzx  edx,WORD PTR [edi+0xc]
0079F068  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0079F06B  53                               push   ebx
0079F06C  51                               push   ecx
0079F06D  52                               push   edx
0079F06E  50                               push   eax
0079F06F  e88c600200                       call   0x7c5100

; resource_reload [REUSED_RESOURCE_GATE] 0x7c5be0..0x7c5dc3 exclusive
007C5BE0  55                               push   ebp
007C5BE1  8bec                             mov    ebp,esp
007C5BE3  6aff                             push   0xffffffff
007C5BE5  687e999300                       push   0x93997e
007C5BEA  64a100000000                     mov    eax,fs:0x0
007C5BF0  50                               push   eax
007C5BF1  83ec44                           sub    esp,0x44
007C5BF4  a1201fd600                       mov    eax,ds:0xd61f20
007C5BF9  33c5                             xor    eax,ebp
007C5BFB  8945f0                           mov    DWORD PTR [ebp-0x10],eax
007C5BFE  53                               push   ebx
007C5BFF  56                               push   esi
007C5C00  57                               push   edi
007C5C01  50                               push   eax
007C5C02  8d45f4                           lea    eax,[ebp-0xc]
007C5C05  64a300000000                     mov    fs:0x0,eax
007C5C0B  8bf1                             mov    esi,ecx
007C5C0D  33db                             xor    ebx,ebx
007C5C0F  395e5c                           cmp    DWORD PTR [esi+0x5c],ebx
007C5C12  0f848a010000                     je     0x7c5da2
007C5C18  385e60                           cmp    BYTE PTR [esi+0x60],bl
007C5C1B  0f8581010000                     jne    0x7c5da2
007C5C21  8d45b8                           lea    eax,[ebp-0x48]
007C5C24  50                               push   eax
007C5C25  e846faffff                       call   0x7c5670
007C5C2A  8d4e3c                           lea    ecx,[esi+0x3c]
007C5C2D  bf10000000                       mov    edi,0x10
007C5C32  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
007C5C35  397914                           cmp    DWORD PTR [ecx+0x14],edi
007C5C38  7202                             jb     0x7c5c3c
007C5C3A  8b09                             mov    ecx,DWORD PTR [ecx]
007C5C3C  397814                           cmp    DWORD PTR [eax+0x14],edi
007C5C3F  7202                             jb     0x7c5c43
007C5C41  8b00                             mov    eax,DWORD PTR [eax]
007C5C43  8bd1                             mov    edx,ecx
007C5C45  56                               push   esi
007C5C46  8bc8                             mov    ecx,eax
007C5C48  e8c3e6ffff                       call   0x7c4310
007C5C4D  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007C5C54  397dcc                           cmp    DWORD PTR [ebp-0x34],edi
007C5C57  720c                             jb     0x7c5c65
007C5C59  8b4db8                           mov    ecx,DWORD PTR [ebp-0x48]
007C5C5C  51                               push   ecx
007C5C5D  e8aab50c00                       call   0x89120c
007C5C62  83c404                           add    esp,0x4
007C5C65  8bce                             mov    ecx,esi
007C5C67  e8d4e2ffff                       call   0x7c3f40
007C5C6C  8b8ec8000000                     mov    ecx,DWORD PTR [esi+0xc8]
007C5C72  2b8ec4000000                     sub    ecx,DWORD PTR [esi+0xc4]
007C5C78  b893244992                       mov    eax,0x92492493
007C5C7D  f7e9                             imul   ecx
007C5C7F  03d1                             add    edx,ecx
007C5C81  c1fa05                           sar    edx,0x5
007C5C84  8bc2                             mov    eax,edx
007C5C86  c1e81f                           shr    eax,0x1f
007C5C89  03c2                             add    eax,edx
007C5C8B  0f840a010000                     je     0x7c5d9b
007C5C91  33ff                             xor    edi,edi
007C5C93  8b86c4000000                     mov    eax,DWORD PTR [esi+0xc4]
007C5C99  6aff                             push   0xffffffff
007C5C9B  03c7                             add    eax,edi
007C5C9D  6a00                             push   0x0
007C5C9F  50                               push   eax
007C5CA0  8d4dd4                           lea    ecx,[ebp-0x2c]
007C5CA3  c745e80f000000                   mov    DWORD PTR [ebp-0x18],0xf
007C5CAA  c745e400000000                   mov    DWORD PTR [ebp-0x1c],0x0
007C5CB1  c645d400                         mov    BYTE PTR [ebp-0x2c],0x0
007C5CB5  e886d3c3ff                       call   0x403040
007C5CBA  c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
007C5CC1  8b8ec4000000                     mov    ecx,DWORD PTR [esi+0xc4]
007C5CC7  6aff                             push   0xffffffff
007C5CC9  8d440f1c                         lea    eax,[edi+ecx*1+0x1c]
007C5CCD  6a00                             push   0x0
007C5CCF  50                               push   eax
007C5CD0  8d4dd4                           lea    ecx,[ebp-0x2c]
007C5CD3  e8f8c1c3ff                       call   0x401ed0
007C5CD8  b910000000                       mov    ecx,0x10
007C5CDD  394de8                           cmp    DWORD PTR [ebp-0x18],ecx
007C5CE0  7208                             jb     0x7c5cea
007C5CE2  8b55d4                           mov    edx,DWORD PTR [ebp-0x2c]
007C5CE5  8955b0                           mov    DWORD PTR [ebp-0x50],edx
007C5CE8  eb06                             jmp    0x7c5cf0
007C5CEA  8d45d4                           lea    eax,[ebp-0x2c]
007C5CED  8945b0                           mov    DWORD PTR [ebp-0x50],eax
007C5CF0  8b86c4000000                     mov    eax,DWORD PTR [esi+0xc4]
007C5CF6  03c7                             add    eax,edi
007C5CF8  83c01c                           add    eax,0x1c
007C5CFB  394814                           cmp    DWORD PTR [eax+0x14],ecx
007C5CFE  7207                             jb     0x7c5d07
007C5D00  8b08                             mov    ecx,DWORD PTR [eax]
007C5D02  894db4                           mov    DWORD PTR [ebp-0x4c],ecx
007C5D05  eb03                             jmp    0x7c5d0a
007C5D07  8945b4                           mov    DWORD PTR [ebp-0x4c],eax
007C5D0A  f6054c32fe0001                   test   BYTE PTR ds:0xfe324c,0x1
007C5D11  7521                             jne    0x7c5d34
007C5D13  830d4c32fe0001                   or     DWORD PTR ds:0xfe324c,0x1
007C5D1A  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
007C5D1E  e88d810000                       call   0x7cdeb0
007C5D23  68b009bd00                       push   0xbd09b0
007C5D28  e8edc50c00                       call   0x89231a
007C5D2D  83c404                           add    esp,0x4
007C5D30  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
007C5D34  8b55b0                           mov    edx,DWORD PTR [ebp-0x50]
007C5D37  8b4db4                           mov    ecx,DWORD PTR [ebp-0x4c]
007C5D3A  52                               push   edx
007C5D3B  685032fe00                       push   0xfe3250
007C5D40  e89b850000                       call   0x7ce2e0
007C5D45  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007C5D4C  837de810                         cmp    DWORD PTR [ebp-0x18],0x10
007C5D50  720c                             jb     0x7c5d5e
007C5D52  8b45d4                           mov    eax,DWORD PTR [ebp-0x2c]
007C5D55  50                               push   eax
007C5D56  e8b1b40c00                       call   0x89120c
007C5D5B  83c404                           add    esp,0x4
007C5D5E  8b8ec8000000                     mov    ecx,DWORD PTR [esi+0xc8]
007C5D64  2b8ec4000000                     sub    ecx,DWORD PTR [esi+0xc4]
007C5D6A  b893244992                       mov    eax,0x92492493
007C5D6F  f7e9                             imul   ecx
007C5D71  03d1                             add    edx,ecx
007C5D73  c1fa05                           sar    edx,0x5
007C5D76  8bca                             mov    ecx,edx
007C5D78  c1e91f                           shr    ecx,0x1f
007C5D7B  43                               inc    ebx
007C5D7C  03ca                             add    ecx,edx
007C5D7E  83c738                           add    edi,0x38
007C5D81  c745e80f000000                   mov    DWORD PTR [ebp-0x18],0xf
007C5D88  c745e400000000                   mov    DWORD PTR [ebp-0x1c],0x0
007C5D8F  c645d400                         mov    BYTE PTR [ebp-0x2c],0x0
007C5D93  3bd9                             cmp    ebx,ecx
007C5D95  0f82f8feffff                     jb     0x7c5c93
007C5D9B  c7465801000000                   mov    DWORD PTR [esi+0x58],0x1
007C5DA2  e899e2ffff                       call   0x7c4040
007C5DA7  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007C5DAA  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007C5DB1  59                               pop    ecx
007C5DB2  5f                               pop    edi
007C5DB3  5e                               pop    esi
007C5DB4  5b                               pop    ebx
007C5DB5  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
007C5DB8  33cd                             xor    ecx,ebp
007C5DBA  e842b20c00                       call   0x891001
007C5DBF  8be5                             mov    esp,ebp
007C5DC1  5d                               pop    ebp
007C5DC2  c3                               ret

; resource_base_reload [NEW_RESIDENT_WRITER_JOIN] 0x7c4310..0x7c493c exclusive
007C4310  55                               push   ebp
007C4311  8bec                             mov    ebp,esp
007C4313  6aff                             push   0xffffffff
007C4315  681d7d9300                       push   0x937d1d
007C431A  64a100000000                     mov    eax,fs:0x0
007C4320  50                               push   eax
007C4321  81ec98000000                     sub    esp,0x98
007C4327  a1201fd600                       mov    eax,ds:0xd61f20
007C432C  33c5                             xor    eax,ebp
007C432E  8945ec                           mov    DWORD PTR [ebp-0x14],eax
007C4331  53                               push   ebx
007C4332  56                               push   esi
007C4333  57                               push   edi
007C4334  50                               push   eax
007C4335  8d45f4                           lea    eax,[ebp-0xc]
007C4338  64a300000000                     mov    fs:0x0,eax
007C433E  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007C4341  807b6000                         cmp    BYTE PTR [ebx+0x60],0x0
007C4345  8bf1                             mov    esi,ecx
007C4347  8bfa                             mov    edi,edx
007C4349  0f85cf050000                     jne    0x7c491e
007C434F  8bc6                             mov    eax,esi
007C4351  c7459c0f000000                   mov    DWORD PTR [ebp-0x64],0xf
007C4358  c7459800000000                   mov    DWORD PTR [ebp-0x68],0x0
007C435F  c6458800                         mov    BYTE PTR [ebp-0x78],0x0
007C4363  8d5001                           lea    edx,[eax+0x1]
007C4366  8a08                             mov    cl,BYTE PTR [eax]
007C4368  40                               inc    eax
007C4369  84c9                             test   cl,cl
007C436B  75f9                             jne    0x7c4366
007C436D  2bc2                             sub    eax,edx
007C436F  50                               push   eax
007C4370  56                               push   esi
007C4371  8d4d88                           lea    ecx,[ebp-0x78]
007C4374  e8f7e6c3ff                       call   0x402a70
007C4379  8bc7                             mov    eax,edi
007C437B  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
007C4382  8d5001                           lea    edx,[eax+0x1]
007C4385  8a08                             mov    cl,BYTE PTR [eax]
007C4387  40                               inc    eax
007C4388  84c9                             test   cl,cl
007C438A  75f9                             jne    0x7c4385
007C438C  2bc2                             sub    eax,edx
007C438E  50                               push   eax
007C438F  57                               push   edi
007C4390  8d4d88                           lea    ecx,[ebp-0x78]
007C4393  e828dcc3ff                       call   0x401fc0
007C4398  8b7588                           mov    esi,DWORD PTR [ebp-0x78]
007C439B  bf10000000                       mov    edi,0x10
007C43A0  397d9c                           cmp    DWORD PTR [ebp-0x64],edi
007C43A3  7303                             jae    0x7c43a8
007C43A5  8d7588                           lea    esi,[ebp-0x78]
007C43A8  f6051c32fe0001                   test   BYTE PTR ds:0xfe321c,0x1
007C43AF  7528                             jne    0x7c43d9
007C43B1  830d1c32fe0001                   or     DWORD PTR ds:0xfe321c,0x1
007C43B8  8d857fffffff                     lea    eax,[ebp-0x81]
007C43BE  50                               push   eax
007C43BF  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
007C43C3  e8e8cb0000                       call   0x7d0fb0
007C43C8  68c009bd00                       push   0xbd09c0
007C43CD  e848df0c00                       call   0x89231a
007C43D2  83c404                           add    esp,0x4
007C43D5  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
007C43D9  6a00                             push   0x0
007C43DB  8bd6                             mov    edx,esi
007C43DD  b92032fe00                       mov    ecx,0xfe3220
007C43E2  e839c50000                       call   0x7d0920
007C43E7  8983ec000000                     mov    DWORD PTR [ebx+0xec],eax
007C43ED  85c0                             test   eax,eax
007C43EF  7512                             jne    0x7c4403
007C43F1  397d9c                           cmp    DWORD PTR [ebp-0x64],edi
007C43F4  0f8224050000                     jb     0x7c491e
007C43FA  8b4d88                           mov    ecx,DWORD PTR [ebp-0x78]
007C43FD  51                               push   ecx
007C43FE  e913050000                       jmp    0x7c4916
007C4403  8b90dc000000                     mov    edx,DWORD PTR [eax+0xdc]
007C4409  2b90d8000000                     sub    edx,DWORD PTR [eax+0xd8]
007C440F  f7c2fcffffff                     test   edx,0xfffffffc
007C4415  743f                             je     0x7c4456
007C4417  68e8000000                       push   0xe8
007C441C  e847ce0c00                       call   0x891268
007C4421  83c404                           add    esp,0x4
007C4424  894580                           mov    DWORD PTR [ebp-0x80],eax
007C4427  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
007C442B  85c0                             test   eax,eax
007C442D  740b                             je     0x7c443a
007C442F  8bf0                             mov    esi,eax
007C4431  e87aa7fbff                       call   0x77ebb0
007C4436  8bf0                             mov    esi,eax
007C4438  eb02                             jmp    0x7c443c
007C443A  33f6                             xor    esi,esi
007C443C  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
007C4440  8b83ec000000                     mov    eax,DWORD PTR [ebx+0xec]
007C4446  8b16                             mov    edx,DWORD PTR [esi]
007C4448  50                               push   eax
007C4449  8b4240                           mov    eax,DWORD PTR [edx+0x40]
007C444C  8bce                             mov    ecx,esi
007C444E  ffd0                             call   eax
007C4450  89b3ec000000                     mov    DWORD PTR [ebx+0xec],esi
007C4456  8b8b88000000                     mov    ecx,DWORD PTR [ebx+0x88]
007C445C  2b8b84000000                     sub    ecx,DWORD PTR [ebx+0x84]
007C4462  b893244992                       mov    eax,0x92492493
007C4467  f7e9                             imul   ecx
007C4469  8b83ec000000                     mov    eax,DWORD PTR [ebx+0xec]
007C446F  03d1                             add    edx,ecx
007C4471  c1fa05                           sar    edx,0x5
007C4474  8bca                             mov    ecx,edx
007C4476  c1e91f                           shr    ecx,0x1f
007C4479  03ca                             add    ecx,edx
007C447B  7510                             jne    0x7c448d
007C447D  6a02                             push   0x2
007C447F  50                               push   eax
007C4480  e8ab2b0000                       call   0x7c7030
007C4485  83c408                           add    esp,0x8
007C4488  e9ec010000                       jmp    0x7c4679
007C448D  6a03                             push   0x3
007C448F  50                               push   eax
007C4490  e89b2b0000                       call   0x7c7030
007C4495  8b8bec000000                     mov    ecx,DWORD PTR [ebx+0xec]
007C449B  8b11                             mov    edx,DWORD PTR [ecx]
007C449D  8b420c                           mov    eax,DWORD PTR [edx+0xc]
007C44A0  83c408                           add    esp,0x8
007C44A3  ffd0                             call   eax
007C44A5  8b8bec000000                     mov    ecx,DWORD PTR [ebx+0xec]
007C44AB  33ff                             xor    edi,edi
007C44AD  8bf0                             mov    esi,eax
007C44AF  3bcf                             cmp    ecx,edi
007C44B1  740e                             je     0x7c44c1
007C44B3  8b11                             mov    edx,DWORD PTR [ecx]
007C44B5  8b02                             mov    eax,DWORD PTR [edx]
007C44B7  6a01                             push   0x1
007C44B9  ffd0                             call   eax
007C44BB  89bbec000000                     mov    DWORD PTR [ebx+0xec],edi
007C44C1  89b3ec000000                     mov    DWORD PTR [ebx+0xec],esi
007C44C7  e84494f1ff                       call   0x6dd910
007C44CC  8bf0                             mov    esi,eax
007C44CE  897580                           mov    DWORD PTR [ebp-0x80],esi
007C44D1  897ddc                           mov    DWORD PTR [ebp-0x24],edi
007C44D4  897de0                           mov    DWORD PTR [ebp-0x20],edi
007C44D7  897de4                           mov    DWORD PTR [ebp-0x1c],edi
007C44DA  8d4ddc                           lea    ecx,[ebp-0x24]
007C44DD  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007C44E1  8b83ec000000                     mov    eax,DWORD PTR [ebx+0xec]
007C44E7  51                               push   ecx
007C44E8  50                               push   eax
007C44E9  e8e2380000                       call   0x7c7dd0
007C44EE  8b55e0                           mov    edx,DWORD PTR [ebp-0x20]
007C44F1  8b45dc                           mov    eax,DWORD PTR [ebp-0x24]
007C44F4  2bd0                             sub    edx,eax
007C44F6  c1fa02                           sar    edx,0x2
007C44F9  83c408                           add    esp,0x8
007C44FC  897d84                           mov    DWORD PTR [ebp-0x7c],edi
007C44FF  85d2                             test   edx,edx
007C4501  0f8461010000                     je     0x7c4668
007C4507  eb07                             jmp    0x7c4510
007C4509  8da42400000000                   lea    esp,[esp+0x0]
007C4510  8b4d84                           mov    ecx,DWORD PTR [ebp-0x7c]
007C4513  8b0488                           mov    eax,DWORD PTR [eax+ecx*4]
007C4516  89bd74ffffff                     mov    DWORD PTR [ebp-0x8c],edi
007C451C  33ff                             xor    edi,edi
007C451E  898570ffffff                     mov    DWORD PTR [ebp-0x90],eax
007C4524  e8c7f90700                       call   0x843ef0
007C4529  8b90b8000000                     mov    edx,DWORD PTR [eax+0xb8]
007C452F  8b06                             mov    eax,DWORD PTR [esi]
007C4531  8b4058                           mov    eax,DWORD PTR [eax+0x58]
007C4534  8d8d74ffffff                     lea    ecx,[ebp-0x8c]
007C453A  89956cffffff                     mov    DWORD PTR [ebp-0x94],edx
007C4540  51                               push   ecx
007C4541  8d956cffffff                     lea    edx,[ebp-0x94]
007C4547  52                               push   edx
007C4548  8bce                             mov    ecx,esi
007C454A  ffd0                             call   eax
007C454C  8b8b88000000                     mov    ecx,DWORD PTR [ebx+0x88]
007C4552  2b8b84000000                     sub    ecx,DWORD PTR [ebx+0x84]
007C4558  b893244992                       mov    eax,0x92492493
007C455D  f7e9                             imul   ecx
007C455F  03d1                             add    edx,ecx
007C4561  c1fa05                           sar    edx,0x5
007C4564  8bca                             mov    ecx,edx
007C4566  c1e91f                           shr    ecx,0x1f
007C4569  03ca                             add    ecx,edx
007C456B  89bd78ffffff                     mov    DWORD PTR [ebp-0x88],edi
007C4571  0f84d5000000                     je     0x7c464c
007C4577  33f6                             xor    esi,esi
007C4579  8da42400000000                   lea    esp,[esp+0x0]
007C4580  8b8384000000                     mov    eax,DWORD PTR [ebx+0x84]
007C4586  03c6                             add    eax,esi
007C4588  bf10000000                       mov    edi,0x10
007C458D  397814                           cmp    DWORD PTR [eax+0x14],edi
007C4590  7202                             jb     0x7c4594
007C4592  8b00                             mov    eax,DWORD PTR [eax]
007C4594  8b9574ffffff                     mov    edx,DWORD PTR [ebp-0x8c]
007C459A  52                               push   edx
007C459B  50                               push   eax
007C459C  e810f70c00                       call   0x893cb1
007C45A1  83c408                           add    esp,0x8
007C45A4  85c0                             test   eax,eax
007C45A6  756a                             jne    0x7c4612
007C45A8  8b8384000000                     mov    eax,DWORD PTR [ebx+0x84]
007C45AE  397c3030                         cmp    DWORD PTR [eax+esi*1+0x30],edi
007C45B2  7206                             jb     0x7c45ba
007C45B4  8b7c301c                         mov    edi,DWORD PTR [eax+esi*1+0x1c]
007C45B8  eb04                             jmp    0x7c45be
007C45BA  8d7c301c                         lea    edi,[eax+esi*1+0x1c]
007C45BE  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
007C45C5  7521                             jne    0x7c45e8
007C45C7  830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
007C45CE  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
007C45D2  e80948fdff                       call   0x798de0
007C45D7  68e0d2bc00                       push   0xbcd2e0
007C45DC  e839dd0c00                       call   0x89231a
007C45E1  83c404                           add    esp,0x4
007C45E4  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007C45E8  57                               push   edi
007C45E9  8dbd68ffffff                     lea    edi,[ebp-0x98]
007C45EF  b9a876fb00                       mov    ecx,0xfb76a8
007C45F4  e80778fdff                       call   0x79be00
007C45F9  8b8570ffffff                     mov    eax,DWORD PTR [ebp-0x90]
007C45FF  33ff                             xor    edi,edi
007C4601  e8eaf80700                       call   0x843ef0
007C4606  8b8d68ffffff                     mov    ecx,DWORD PTR [ebp-0x98]
007C460C  8988b8000000                     mov    DWORD PTR [eax+0xb8],ecx
007C4612  8b8b88000000                     mov    ecx,DWORD PTR [ebx+0x88]
007C4618  2b8b84000000                     sub    ecx,DWORD PTR [ebx+0x84]
007C461E  8bbd78ffffff                     mov    edi,DWORD PTR [ebp-0x88]
007C4624  b893244992                       mov    eax,0x92492493
007C4629  f7e9                             imul   ecx
007C462B  03d1                             add    edx,ecx
007C462D  c1fa05                           sar    edx,0x5
007C4630  8bc2                             mov    eax,edx
007C4632  c1e81f                           shr    eax,0x1f
007C4635  47                               inc    edi
007C4636  03c2                             add    eax,edx
007C4638  83c638                           add    esi,0x38
007C463B  89bd78ffffff                     mov    DWORD PTR [ebp-0x88],edi
007C4641  3bf8                             cmp    edi,eax
007C4643  0f8237ffffff                     jb     0x7c4580
007C4649  8b7580                           mov    esi,DWORD PTR [ebp-0x80]
007C464C  8b55e0                           mov    edx,DWORD PTR [ebp-0x20]
007C464F  8b45dc                           mov    eax,DWORD PTR [ebp-0x24]
007C4652  8b4d84                           mov    ecx,DWORD PTR [ebp-0x7c]
007C4655  2bd0                             sub    edx,eax
007C4657  41                               inc    ecx
007C4658  c1fa02                           sar    edx,0x2
007C465B  33ff                             xor    edi,edi
007C465D  894d84                           mov    DWORD PTR [ebp-0x7c],ecx
007C4660  3bca                             cmp    ecx,edx
007C4662  0f82a8feffff                     jb     0x7c4510
007C4668  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
007C466C  3bc7                             cmp    eax,edi
007C466E  7409                             je     0x7c4679
007C4670  50                               push   eax
007C4671  e896cb0c00                       call   0x89120c
007C4676  83c404                           add    esp,0x4
007C4679  8b83ec000000                     mov    eax,DWORD PTR [ebx+0xec]
007C467F  6a00                             push   0x0
007C4681  6a00                             push   0x0
007C4683  68e8fdc400                       push   0xc4fde8
007C4688  50                               push   eax
007C4689  e8a21d0000                       call   0x7c6430
007C468E  d9ee                             fldz
007C4690  d955a4                           fst    DWORD PTR [ebp-0x5c]
007C4693  83c410                           add    esp,0x10
007C4696  d955a8                           fst    DWORD PTR [ebp-0x58]
007C4699  be01000000                       mov    esi,0x1
007C469E  d955ac                           fst    DWORD PTR [ebp-0x54]
007C46A1  8975cc                           mov    DWORD PTR [ebp-0x34],esi
007C46A4  d955b0                           fst    DWORD PTR [ebp-0x50]
007C46A7  d955b4                           fst    DWORD PTR [ebp-0x4c]
007C46AA  d955b8                           fst    DWORD PTR [ebp-0x48]
007C46AD  d9e8                             fld1
007C46AF  d955bc                           fst    DWORD PTR [ebp-0x44]
007C46B2  d955c0                           fst    DWORD PTR [ebp-0x40]
007C46B5  d955c4                           fst    DWORD PTR [ebp-0x3c]
007C46B8  d95dc8                           fstp   DWORD PTR [ebp-0x38]
007C46BB  85c0                             test   eax,eax
007C46BD  7425                             je     0x7c46e4
007C46BF  8b83ec000000                     mov    eax,DWORD PTR [ebx+0xec]
007C46C5  ddd8                             fstp   st(0)
007C46C7  8d4da4                           lea    ecx,[ebp-0x5c]
007C46CA  51                               push   ecx
007C46CB  68e8fdc400                       push   0xc4fde8
007C46D0  50                               push   eax
007C46D1  e8aa210000                       call   0x7c6880
007C46D6  83c40c                           add    esp,0xc
007C46D9  85c0                             test   eax,eax
007C46DB  7405                             je     0x7c46e2
007C46DD  d945ac                           fld    DWORD PTR [ebp-0x54]
007C46E0  eb44                             jmp    0x7c4726
007C46E2  d9ee                             fldz
007C46E4  8b83ec000000                     mov    eax,DWORD PTR [ebx+0xec]
007C46EA  d955e0                           fst    DWORD PTR [ebp-0x20]
007C46ED  8d5580                           lea    edx,[ebp-0x80]
007C46F0  d955e4                           fst    DWORD PTR [ebp-0x1c]
007C46F3  52                               push   edx
007C46F4  d955e8                           fst    DWORD PTR [ebp-0x18]
007C46F7  8d8d5cffffff                     lea    ecx,[ebp-0xa4]
007C46FD  d9955cffffff                     fst    DWORD PTR [ebp-0xa4]
007C4703  51                               push   ecx
007C4704  d99560ffffff                     fst    DWORD PTR [ebp-0xa0]
007C470A  8d55e0                           lea    edx,[ebp-0x20]
007C470D  d99d64ffffff                     fstp   DWORD PTR [ebp-0x9c]
007C4713  52                               push   edx
007C4714  50                               push   eax
007C4715  897580                           mov    DWORD PTR [ebp-0x80],esi
007C4718  e8832c0000                       call   0x7c73a0
007C471D  d98564ffffff                     fld    DWORD PTR [ebp-0x9c]
007C4723  83c410                           add    esp,0x10
007C4726  8b83ec000000                     mov    eax,DWORD PTR [ebx+0xec]
007C472C  d99bf0000000                     fstp   DWORD PTR [ebx+0xf0]
007C4732  68ecfdc400                       push   0xc4fdec
007C4737  50                               push   eax
007C4738  e8c31f0000                       call   0x7c6700
007C473D  83c408                           add    esp,0x8
007C4740  85c0                             test   eax,eax
007C4742  7417                             je     0x7c475b
007C4744  8b10                             mov    edx,DWORD PTR [eax]
007C4746  8bc8                             mov    ecx,eax
007C4748  8b420c                           mov    eax,DWORD PTR [edx+0xc]
007C474B  ffd0                             call   eax
007C474D  8b8be4000000                     mov    ecx,DWORD PTR [ebx+0xe4]
007C4753  50                               push   eax
007C4754  56                               push   esi
007C4755  51                               push   ecx
007C4756  e8b51d0100                       call   0x7d6510
007C475B  8d55b4                           lea    edx,[ebp-0x4c]
007C475E  52                               push   edx
007C475F  8bcb                             mov    ecx,ebx
007C4761  e80a0f0000                       call   0x7c5670
007C4766  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
007C476A  83781410                         cmp    DWORD PTR [eax+0x14],0x10
007C476E  7204                             jb     0x7c4774
007C4770  8b30                             mov    esi,DWORD PTR [eax]
007C4772  eb02                             jmp    0x7c4776
007C4774  8bf0                             mov    esi,eax
007C4776  8b8be4000000                     mov    ecx,DWORD PTR [ebx+0xe4]
007C477C  8bc6                             mov    eax,esi
007C477E  8d7801                           lea    edi,[eax+0x1]
007C4781  8a10                             mov    dl,BYTE PTR [eax]
007C4783  40                               inc    eax
007C4784  84d2                             test   dl,dl
007C4786  75f9                             jne    0x7c4781
007C4788  2bc7                             sub    eax,edi
007C478A  50                               push   eax
007C478B  56                               push   esi
007C478C  e8dfe2c3ff                       call   0x402a70
007C4791  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
007C4795  837dc810                         cmp    DWORD PTR [ebp-0x38],0x10
007C4799  720c                             jb     0x7c47a7
007C479B  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
007C479E  50                               push   eax
007C479F  e868ca0c00                       call   0x89120c
007C47A4  83c404                           add    esp,0x4
007C47A7  8bbbe4000000                     mov    edi,DWORD PTR [ebx+0xe4]
007C47AD  e8de190100                       call   0x7d6190
007C47B2  83bbec00000000                   cmp    DWORD PTR [ebx+0xec],0x0
007C47B9  0f8449010000                     je     0x7c4908
007C47BF  8b4b78                           mov    ecx,DWORD PTR [ebx+0x78]
007C47C2  8b4374                           mov    eax,DWORD PTR [ebx+0x74]
007C47C5  894d80                           mov    DWORD PTR [ebp-0x80],ecx
007C47C8  894584                           mov    DWORD PTR [ebp-0x7c],eax
007C47CB  3bc1                             cmp    eax,ecx
007C47CD  0f840d010000                     je     0x7c48e0
007C47D3  eb03                             jmp    0x7c47d8
007C47D5  8b4584                           mov    eax,DWORD PTR [ebp-0x7c]
007C47D8  6aff                             push   0xffffffff
007C47DA  6a00                             push   0x0
007C47DC  50                               push   eax
007C47DD  8d4dd0                           lea    ecx,[ebp-0x30]
007C47E0  c745e40f000000                   mov    DWORD PTR [ebp-0x1c],0xf
007C47E7  c745e000000000                   mov    DWORD PTR [ebp-0x20],0x0
007C47EE  c645d000                         mov    BYTE PTR [ebp-0x30],0x0
007C47F2  e849e8c3ff                       call   0x403040
007C47F7  8d4db4                           lea    ecx,[ebp-0x4c]
007C47FA  51                               push   ecx
007C47FB  8bcb                             mov    ecx,ebx
007C47FD  c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
007C4801  e8fa0d0000                       call   0x7c5600
007C4806  c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
007C480A  8b55d0                           mov    edx,DWORD PTR [ebp-0x30]
007C480D  be10000000                       mov    esi,0x10
007C4812  3975e4                           cmp    DWORD PTR [ebp-0x1c],esi
007C4815  7303                             jae    0x7c481a
007C4817  8d55d0                           lea    edx,[ebp-0x30]
007C481A  8bc2                             mov    eax,edx
007C481C  8d7801                           lea    edi,[eax+0x1]
007C481F  90                               nop
007C4820  8a08                             mov    cl,BYTE PTR [eax]
007C4822  40                               inc    eax
007C4823  84c9                             test   cl,cl
007C4825  75f9                             jne    0x7c4820
007C4827  2bc7                             sub    eax,edi
007C4829  50                               push   eax
007C482A  52                               push   edx
007C482B  8d4db4                           lea    ecx,[ebp-0x4c]
007C482E  e88dd7c3ff                       call   0x401fc0
007C4833  8b7db4                           mov    edi,DWORD PTR [ebp-0x4c]
007C4836  3975c8                           cmp    DWORD PTR [ebp-0x38],esi
007C4839  7303                             jae    0x7c483e
007C483B  8d7db4                           lea    edi,[ebp-0x4c]
007C483E  3975e4                           cmp    DWORD PTR [ebp-0x1c],esi
007C4841  8b75d0                           mov    esi,DWORD PTR [ebp-0x30]
007C4844  7303                             jae    0x7c4849
007C4846  8d75d0                           lea    esi,[ebp-0x30]
007C4849  f605c01afe0001                   test   BYTE PTR ds:0xfe1ac0,0x1
007C4850  7521                             jne    0x7c4873
007C4852  830dc01afe0001                   or     DWORD PTR ds:0xfe1ac0,0x1
007C4859  c645fc08                         mov    BYTE PTR [ebp-0x4],0x8
007C485D  e80e71ffff                       call   0x7bb970
007C4862  68c0eabc00                       push   0xbceac0
007C4867  e8aeda0c00                       call   0x89231a
007C486C  83c404                           add    esp,0x4
007C486F  c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
007C4873  68081bfe00                       push   0xfe1b08
007C4878  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
007C487E  57                               push   edi
007C487F  56                               push   esi
007C4880  b9c81afe00                       mov    ecx,0xfe1ac8
007C4885  ff15e01afe00                     call   DWORD PTR ds:0xfe1ae0
007C488B  8b152c1bfe00                     mov    edx,DWORD PTR ds:0xfe1b2c
007C4891  52                               push   edx
007C4892  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
007C4898  68081bfe00                       push   0xfe1b08
007C489D  ff154822bd00                     call   DWORD PTR ds:0xbd2248
007C48A3  be10000000                       mov    esi,0x10
007C48A8  3975c8                           cmp    DWORD PTR [ebp-0x38],esi
007C48AB  720c                             jb     0x7c48b9
007C48AD  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
007C48B0  50                               push   eax
007C48B1  e856c90c00                       call   0x89120c
007C48B6  83c404                           add    esp,0x4
007C48B9  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
007C48BD  3975e4                           cmp    DWORD PTR [ebp-0x1c],esi
007C48C0  720c                             jb     0x7c48ce
007C48C2  8b4dd0                           mov    ecx,DWORD PTR [ebp-0x30]
007C48C5  51                               push   ecx
007C48C6  e841c90c00                       call   0x89120c
007C48CB  83c404                           add    esp,0x4
007C48CE  8b4584                           mov    eax,DWORD PTR [ebp-0x7c]
007C48D1  83c01c                           add    eax,0x1c
007C48D4  894584                           mov    DWORD PTR [ebp-0x7c],eax
007C48D7  3b4580                           cmp    eax,DWORD PTR [ebp-0x80]
007C48DA  0f85f5feffff                     jne    0x7c47d5
007C48E0  83bbbc00000000                   cmp    DWORD PTR [ebx+0xbc],0x0
007C48E7  750e                             jne    0x7c48f7
007C48E9  8b9384000000                     mov    edx,DWORD PTR [ebx+0x84]
007C48EF  3b9388000000                     cmp    edx,DWORD PTR [ebx+0x88]
007C48F5  7411                             je     0x7c4908
007C48F7  8b83ec000000                     mov    eax,DWORD PTR [ebx+0xec]
007C48FD  6a03                             push   0x3
007C48FF  50                               push   eax
007C4900  e82b270000                       call   0x7c7030
007C4905  83c408                           add    esp,0x8
007C4908  837d9c10                         cmp    DWORD PTR [ebp-0x64],0x10
007C490C  c6436001                         mov    BYTE PTR [ebx+0x60],0x1
007C4910  720c                             jb     0x7c491e
007C4912  8b4588                           mov    eax,DWORD PTR [ebp-0x78]
007C4915  50                               push   eax
007C4916  e8f1c80c00                       call   0x89120c
007C491B  83c404                           add    esp,0x4
007C491E  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007C4921  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007C4928  59                               pop    ecx
007C4929  5f                               pop    edi
007C492A  5e                               pop    esi
007C492B  5b                               pop    ebx
007C492C  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
007C492F  33cd                             xor    ecx,ebp
007C4931  e8cbc60c00                       call   0x891001
007C4936  8be5                             mov    esp,ebp
007C4938  5d                               pop    ebp
007C4939  c20400                           ret    0x4

; resource_clone_instance [NEW_INSTANCE_GATE_JOIN] 0x7c5100..0x7c520e exclusive
007C5100  55                               push   ebp
007C5101  8bec                             mov    ebp,esp
007C5103  6aff                             push   0xffffffff
007C5105  687b8a9300                       push   0x938a7b
007C510A  64a100000000                     mov    eax,fs:0x0
007C5110  50                               push   eax
007C5111  51                               push   ecx
007C5112  53                               push   ebx
007C5113  56                               push   esi
007C5114  57                               push   edi
007C5115  a1201fd600                       mov    eax,ds:0xd61f20
007C511A  33c5                             xor    eax,ebp
007C511C  50                               push   eax
007C511D  8d45f4                           lea    eax,[ebp-0xc]
007C5120  64a300000000                     mov    fs:0x0,eax
007C5126  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007C5129  83bbec00000000                   cmp    DWORD PTR [ebx+0xec],0x0
007C5130  7516                             jne    0x7c5148
007C5132  33c0                             xor    eax,eax
007C5134  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007C5137  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007C513E  59                               pop    ecx
007C513F  5f                               pop    edi
007C5140  5e                               pop    esi
007C5141  5b                               pop    ebx
007C5142  8be5                             mov    esp,ebp
007C5144  5d                               pop    ebp
007C5145  c21000                           ret    0x10
007C5148  8b7d14                           mov    edi,DWORD PTR [ebp+0x14]
007C514B  833f00                           cmp    DWORD PTR [edi],0x0
007C514E  753e                             jne    0x7c518e
007C5150  8b8bec000000                     mov    ecx,DWORD PTR [ebx+0xec]
007C5156  8b01                             mov    eax,DWORD PTR [ecx]
007C5158  8b500c                           mov    edx,DWORD PTR [eax+0xc]
007C515B  ffd2                             call   edx
007C515D  68b8000000                       push   0xb8
007C5162  8bf0                             mov    esi,eax
007C5164  e8ffc00c00                       call   0x891268
007C5169  83c404                           add    esp,0x4
007C516C  894508                           mov    DWORD PTR [ebp+0x8],eax
007C516F  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
007C5176  85c0                             test   eax,eax
007C5178  7409                             je     0x7c5183
007C517A  56                               push   esi
007C517B  50                               push   eax
007C517C  e82fdc0000                       call   0x7d2db0
007C5181  eb02                             jmp    0x7c5185
007C5183  33c0                             xor    eax,eax
007C5185  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007C518C  8907                             mov    DWORD PTR [edi],eax
007C518E  0fb7450c                         movzx  eax,WORD PTR [ebp+0xc]
007C5192  0fb74d10                         movzx  ecx,WORD PTR [ebp+0x10]
007C5196  c1e010                           shl    eax,0x10
007C5199  0bc1                             or     eax,ecx
007C519B  8d550c                           lea    edx,[ebp+0xc]
007C519E  89450c                           mov    DWORD PTR [ebp+0xc],eax
007C51A1  52                               push   edx
007C51A2  8d8bb4000000                     lea    ecx,[ebx+0xb4]
007C51A8  8d4510                           lea    eax,[ebp+0x10]
007C51AB  e8509d0600                       call   0x82ef00
007C51B0  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
007C51B3  3b83b8000000                     cmp    eax,DWORD PTR [ebx+0xb8]
007C51B9  743a                             je     0x7c51f5
007C51BB  8b7810                           mov    edi,DWORD PTR [eax+0x10]
007C51BE  8b7728                           mov    esi,DWORD PTR [edi+0x28]
007C51C1  3b772c                           cmp    esi,DWORD PTR [edi+0x2c]
007C51C4  741f                             je     0x7c51e5
007C51C6  8b5514                           mov    edx,DWORD PTR [ebp+0x14]
007C51C9  8d4621                           lea    eax,[esi+0x21]
007C51CC  50                               push   eax
007C51CD  0fb606                           movzx  eax,BYTE PTR [esi]
007C51D0  8d4e01                           lea    ecx,[esi+0x1]
007C51D3  51                               push   ecx
007C51D4  8b0a                             mov    ecx,DWORD PTR [edx]
007C51D6  51                               push   ecx
007C51D7  53                               push   ebx
007C51D8  e893000000                       call   0x7c5270
007C51DD  83c668                           add    esi,0x68
007C51E0  3b772c                           cmp    esi,DWORD PTR [edi+0x2c]
007C51E3  75e1                             jne    0x7c51c6
007C51E5  66833f00                         cmp    WORD PTR [edi],0x0
007C51E9  7507                             jne    0x7c51f2
007C51EB  8bcb                             mov    ecx,ebx
007C51ED  e88efaffff                       call   0x7c4c80
007C51F2  66ff07                           inc    WORD PTR [edi]
007C51F5  b801000000                       mov    eax,0x1
007C51FA  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007C51FD  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007C5204  59                               pop    ecx
007C5205  5f                               pop    edi
007C5206  5e                               pop    esi
007C5207  5b                               pop    ebx
007C5208  8be5                             mov    esp,ebp
007C520A  5d                               pop    ebp
007C520B  c21000                           ret    0x10

; doll_apply_result [NEW_APPLY_AND_REPLACE_RELEASE_JOIN] 0x7a90f0..0x7a9a65 exclusive
007A90F0  55                               push   ebp
007A90F1  8bec                             mov    ebp,esp
007A90F3  6aff                             push   0xffffffff
007A90F5  68648d9100                       push   0x918d64
007A90FA  64a100000000                     mov    eax,fs:0x0
007A9100  50                               push   eax
007A9101  81ecd8000000                     sub    esp,0xd8
007A9107  a1201fd600                       mov    eax,ds:0xd61f20
007A910C  33c5                             xor    eax,ebp
007A910E  8945ec                           mov    DWORD PTR [ebp-0x14],eax
007A9111  53                               push   ebx
007A9112  56                               push   esi
007A9113  57                               push   edi
007A9114  50                               push   eax
007A9115  8d45f4                           lea    eax,[ebp-0xc]
007A9118  64a300000000                     mov    fs:0x0,eax
007A911E  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A9121  895dc0                           mov    DWORD PTR [ebp-0x40],ebx
007A9124  33c0                             xor    eax,eax
007A9126  8945fc                           mov    DWORD PTR [ebp-0x4],eax
007A9129  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
007A912C  3801                             cmp    BYTE PTR [ecx],al
007A912E  7531                             jne    0x7a9161
007A9130  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007A9137  8b7510                           mov    esi,DWORD PTR [ebp+0x10]
007A913A  c7432403000000                   mov    DWORD PTR [ebx+0x24],0x3
007A9141  89431c                           mov    DWORD PTR [ebx+0x1c],eax
007A9144  8983a0000000                     mov    DWORD PTR [ebx+0xa0],eax
007A914A  3bf0                             cmp    esi,eax
007A914C  0f84f5080000                     je     0x7a9a47
007A9152  8d5604                           lea    edx,[esi+0x4]
007A9155  83c8ff                           or     eax,0xffffffff
007A9158  f00fc102                         lock xadd DWORD PTR [edx],eax
007A915C  e9c7080000                       jmp    0x7a9a28
007A9161  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
007A9167  8d7b2c                           lea    edi,[ebx+0x2c]
007A916A  894590                           mov    DWORD PTR [ebp-0x70],eax
007A916D  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
007A9170  57                               push   edi
007A9171  8d8d6cffffff                     lea    ecx,[ebp-0x94]
007A9177  51                               push   ecx
007A9178  8945a0                           mov    DWORD PTR [ebp-0x60],eax
007A917B  e8d00c0000                       call   0x7a9e50
007A9180  8d5710                           lea    edx,[edi+0x10]
007A9183  52                               push   edx
007A9184  8d857cffffff                     lea    eax,[ebp-0x84]
007A918A  50                               push   eax
007A918B  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
007A918F  e88c0d0000                       call   0x7a9f20
007A9194  8d736c                           lea    esi,[ebx+0x6c]
007A9197  56                               push   esi
007A9198  8d8d54ffffff                     lea    ecx,[ebp-0xac]
007A919E  51                               push   ecx
007A919F  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
007A91A3  e8480e0000                       call   0x7a9ff0
007A91A8  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007A91AC  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A91AF  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A91B2  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
007A91B5  894b1c                           mov    DWORD PTR [ebx+0x1c],ecx
007A91B8  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A91BB  83c048                           add    eax,0x48
007A91BE  50                               push   eax
007A91BF  8955bc                           mov    DWORD PTR [ebp-0x44],edx
007A91C2  e869c5ffff                       call   0x7a5730
007A91C7  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A91CA  83c018                           add    eax,0x18
007A91CD  8945cc                           mov    DWORD PTR [ebp-0x34],eax
007A91D0  3bf0                             cmp    esi,eax
007A91D2  741e                             je     0x7a91f2
007A91D4  8b4370                           mov    eax,DWORD PTR [ebx+0x70]
007A91D7  8b08                             mov    ecx,DWORD PTR [eax]
007A91D9  50                               push   eax
007A91DA  51                               push   ecx
007A91DB  8d75c8                           lea    esi,[ebp-0x38]
007A91DE  8d436c                           lea    eax,[ebx+0x6c]
007A91E1  e83adff2ff                       call   0x6d7120
007A91E6  8b55cc                           mov    edx,DWORD PTR [ebp-0x34]
007A91E9  52                               push   edx
007A91EA  8d436c                           lea    eax,[ebx+0x6c]
007A91ED  e85e0f0000                       call   0x7aa150
007A91F2  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
007A91F5  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A91F8  8d8bec000000                     lea    ecx,[ebx+0xec]
007A91FE  51                               push   ecx
007A91FF  8d4b04                           lea    ecx,[ebx+0x4]
007A9202  ffd2                             call   edx
007A9204  d983f8000000                     fld    DWORD PTR [ebx+0xf8]
007A920A  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
007A920D  8b5014                           mov    edx,DWORD PTR [eax+0x14]
007A9210  51                               push   ecx
007A9211  8d4b04                           lea    ecx,[ebx+0x4]
007A9214  d91c24                           fstp   DWORD PTR [esp]
007A9217  ffd2                             call   edx
007A9219  d983fc000000                     fld    DWORD PTR [ebx+0xfc]
007A921F  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
007A9222  8b500c                           mov    edx,DWORD PTR [eax+0xc]
007A9225  51                               push   ecx
007A9226  8d4b04                           lea    ecx,[ebx+0x4]
007A9229  d91c24                           fstp   DWORD PTR [esp]
007A922C  ffd2                             call   edx
007A922E  8d737c                           lea    esi,[ebx+0x7c]
007A9231  8bfe                             mov    edi,esi
007A9233  e818a60700                       call   0x823850
007A9238  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A923B  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A923E  8945c4                           mov    DWORD PTR [ebp-0x3c],eax
007A9241  8b403c                           mov    eax,DWORD PTR [eax+0x3c]
007A9244  8b38                             mov    edi,DWORD PTR [eax]
007A9246  3bf8                             cmp    edi,eax
007A9248  0f84c0000000                     je     0x7a930e
007A924E  8bff                             mov    edi,edi
007A9250  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
007A9257  7521                             jne    0x7a927a
007A9259  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
007A9260  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
007A9264  e8975c0100                       call   0x7bef00
007A9269  6850ecbc00                       push   0xbcec50
007A926E  e8a7900e00                       call   0x89231a
007A9273  83c404                           add    esp,0x4
007A9276  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007A927A  8b4f18                           mov    ecx,DWORD PTR [edi+0x18]
007A927D  8b571c                           mov    edx,DWORD PTR [edi+0x1c]
007A9280  8d8564ffffff                     lea    eax,[ebp-0x9c]
007A9286  898d64ffffff                     mov    DWORD PTR [ebp-0x9c],ecx
007A928C  50                               push   eax
007A928D  8d4dcc                           lea    ecx,[ebp-0x34]
007A9290  51                               push   ecx
007A9291  68601bfe00                       push   0xfe1b60
007A9296  899568ffffff                     mov    DWORD PTR [ebp-0x98],edx
007A929C  e85f41d3ff                       call   0x4dd400
007A92A1  8b45cc                           mov    eax,DWORD PTR [ebp-0x34]
007A92A4  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
007A92AA  7411                             je     0x7a92bd
007A92AC  8b4018                           mov    eax,DWORD PTR [eax+0x18]
007A92AF  85c0                             test   eax,eax
007A92B1  740a                             je     0x7a92bd
007A92B3  8b55bc                           mov    edx,DWORD PTR [ebp-0x44]
007A92B6  56                               push   esi
007A92B7  52                               push   edx
007A92B8  e813ca0200                       call   0x7d5cd0
007A92BD  807f2100                         cmp    BYTE PTR [edi+0x21],0x0
007A92C1  753f                             jne    0x7a9302
007A92C3  8b4708                           mov    eax,DWORD PTR [edi+0x8]
007A92C6  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A92CA  7516                             jne    0x7a92e2
007A92CC  8bf8                             mov    edi,eax
007A92CE  8b07                             mov    eax,DWORD PTR [edi]
007A92D0  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A92D4  752c                             jne    0x7a9302
007A92D6  8bf8                             mov    edi,eax
007A92D8  8b07                             mov    eax,DWORD PTR [edi]
007A92DA  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A92DE  74f6                             je     0x7a92d6
007A92E0  eb20                             jmp    0x7a9302
007A92E2  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A92E5  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A92E9  7515                             jne    0x7a9300
007A92EB  eb03                             jmp    0x7a92f0
007A92ED  8d4900                           lea    ecx,[ecx+0x0]
007A92F0  3b7808                           cmp    edi,DWORD PTR [eax+0x8]
007A92F3  750b                             jne    0x7a9300
007A92F5  8bf8                             mov    edi,eax
007A92F7  8b4004                           mov    eax,DWORD PTR [eax+0x4]
007A92FA  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A92FE  74f0                             je     0x7a92f0
007A9300  8bf8                             mov    edi,eax
007A9302  8b45c4                           mov    eax,DWORD PTR [ebp-0x3c]
007A9305  3b783c                           cmp    edi,DWORD PTR [eax+0x3c]
007A9308  0f8542ffffff                     jne    0x7a9250
007A930E  8b8ba8000000                     mov    ecx,DWORD PTR [ebx+0xa8]
007A9314  51                               push   ecx
007A9315  8bc3                             mov    eax,ebx
007A9317  e8e4e4ffff                       call   0x7a7800
007A931C  d983b4000000                     fld    DWORD PTR [ebx+0xb4]
007A9322  d95dcc                           fstp   DWORD PTR [ebp-0x34]
007A9325  51                               push   ecx
007A9326  d9ee                             fldz
007A9328  8bf3                             mov    esi,ebx
007A932A  d91c24                           fstp   DWORD PTR [esp]
007A932D  8983ac000000                     mov    DWORD PTR [ebx+0xac],eax
007A9333  e8f8d4ffff                       call   0x7a6830
007A9338  d945cc                           fld    DWORD PTR [ebp-0x34]
007A933B  51                               push   ecx
007A933C  d91c24                           fstp   DWORD PTR [esp]
007A933F  e8ecd4ffff                       call   0x7a6830
007A9344  8b4370                           mov    eax,DWORD PTR [ebx+0x70]
007A9347  8b08                             mov    ecx,DWORD PTR [eax]
007A9349  894dc8                           mov    DWORD PTR [ebp-0x38],ecx
007A934C  3bc8                             cmp    ecx,eax
007A934E  0f848f000000                     je     0x7a93e3
007A9354  8b45c8                           mov    eax,DWORD PTR [ebp-0x38]
007A9357  8b7018                           mov    esi,DWORD PTR [eax+0x18]
007A935A  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
007A935D  2b4e18                           sub    ecx,DWORD PTR [esi+0x18]
007A9360  8b93a8000000                     mov    edx,DWORD PTR [ebx+0xa8]
007A9366  c1f902                           sar    ecx,0x2
007A9369  33ff                             xor    edi,edi
007A936B  8955cc                           mov    DWORD PTR [ebp-0x34],edx
007A936E  85c9                             test   ecx,ecx
007A9370  741f                             je     0x7a9391
007A9372  8b5618                           mov    edx,DWORD PTR [esi+0x18]
007A9375  8b0cba                           mov    ecx,DWORD PTR [edx+edi*4]
007A9378  8b01                             mov    eax,DWORD PTR [ecx]
007A937A  8b55cc                           mov    edx,DWORD PTR [ebp-0x34]
007A937D  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A9380  52                               push   edx
007A9381  ffd0                             call   eax
007A9383  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
007A9386  2b4e18                           sub    ecx,DWORD PTR [esi+0x18]
007A9389  47                               inc    edi
007A938A  c1f902                           sar    ecx,0x2
007A938D  3bf9                             cmp    edi,ecx
007A938F  72e1                             jb     0x7a9372
007A9391  8b4dc8                           mov    ecx,DWORD PTR [ebp-0x38]
007A9394  80792100                         cmp    BYTE PTR [ecx+0x21],0x0
007A9398  7540                             jne    0x7a93da
007A939A  8b4108                           mov    eax,DWORD PTR [ecx+0x8]
007A939D  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A93A1  7519                             jne    0x7a93bc
007A93A3  8bc8                             mov    ecx,eax
007A93A5  8b01                             mov    eax,DWORD PTR [ecx]
007A93A7  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A93AB  752a                             jne    0x7a93d7
007A93AD  8d4900                           lea    ecx,[ecx+0x0]
007A93B0  8bc8                             mov    ecx,eax
007A93B2  8b01                             mov    eax,DWORD PTR [ecx]
007A93B4  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A93B8  74f6                             je     0x7a93b0
007A93BA  eb1b                             jmp    0x7a93d7
007A93BC  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A93BF  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A93C3  7510                             jne    0x7a93d5
007A93C5  3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
007A93C8  750b                             jne    0x7a93d5
007A93CA  8bc8                             mov    ecx,eax
007A93CC  8b4004                           mov    eax,DWORD PTR [eax+0x4]
007A93CF  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A93D3  74f0                             je     0x7a93c5
007A93D5  8bc8                             mov    ecx,eax
007A93D7  894dc8                           mov    DWORD PTR [ebp-0x38],ecx
007A93DA  3b4b70                           cmp    ecx,DWORD PTR [ebx+0x70]
007A93DD  0f8571ffffff                     jne    0x7a9354
007A93E3  8b83a0000000                     mov    eax,DWORD PTR [ebx+0xa0]
007A93E9  33ff                             xor    edi,edi
007A93EB  3bc7                             cmp    eax,edi
007A93ED  7414                             je     0x7a9403
007A93EF  8b08                             mov    ecx,DWORD PTR [eax]
007A93F1  ff492c                           dec    DWORD PTR [ecx+0x2c]
007A93F4  50                               push   eax
007A93F5  e8127e0e00                       call   0x89120c
007A93FA  83c404                           add    esp,0x4
007A93FD  89bba0000000                     mov    DWORD PTR [ebx+0xa0],edi
007A9403  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
007A9406  8b4214                           mov    eax,DWORD PTR [edx+0x14]
007A9409  8983a0000000                     mov    DWORD PTR [ebx+0xa0],eax
007A940F  8b45bc                           mov    eax,DWORD PTR [ebp-0x44]
007A9412  8bb0c4000000                     mov    esi,DWORD PTR [eax+0xc4]
007A9418  8b88c8000000                     mov    ecx,DWORD PTR [eax+0xc8]
007A941E  2bce                             sub    ecx,esi
007A9420  b893244992                       mov    eax,0x92492493
007A9425  f7e9                             imul   ecx
007A9427  03d1                             add    edx,ecx
007A9429  c1fa05                           sar    edx,0x5
007A942C  8bc2                             mov    eax,edx
007A942E  c1e81f                           shr    eax,0x1f
007A9431  03c2                             add    eax,edx
007A9433  0f84a5020000                     je     0x7a96de
007A9439  897dcc                           mov    DWORD PTR [ebp-0x34],edi
007A943C  3bc7                             cmp    eax,edi
007A943E  0f869a020000                     jbe    0x7a96de
007A9444  897dc8                           mov    DWORD PTR [ebp-0x38],edi
007A9447  eb07                             jmp    0x7a9450
007A9449  8da42400000000                   lea    esp,[esp+0x0]
007A9450  8b4dc8                           mov    ecx,DWORD PTR [ebp-0x38]
007A9453  837c0e3010                       cmp    DWORD PTR [esi+ecx*1+0x30],0x10
007A9458  8d440e1c                         lea    eax,[esi+ecx*1+0x1c]
007A945C  c745c4ffffffff                   mov    DWORD PTR [ebp-0x3c],0xffffffff
007A9463  7204                             jb     0x7a9469
007A9465  8b38                             mov    edi,DWORD PTR [eax]
007A9467  eb02                             jmp    0x7a946b
007A9469  8bf8                             mov    edi,eax
007A946B  f6054c32fe0001                   test   BYTE PTR ds:0xfe324c,0x1
007A9472  0f85bf000000                     jne    0x7a9537
007A9478  830d4c32fe0001                   or     DWORD PTR ds:0xfe324c,0x1
007A947F  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
007A9483  33f6                             xor    esi,esi
007A9485  6a34                             push   0x34
007A9487  89355832fe00                     mov    DWORD PTR ds:0xfe3258,esi
007A948D  e8d67d0e00                       call   0x891268
007A9492  83c404                           add    esp,0x4
007A9495  3bc6                             cmp    eax,esi
007A9497  0f84db020000                     je     0x7a9778
007A949D  a35432fe00                       mov    ds:0xfe3254,eax
007A94A2  8900                             mov    DWORD PTR [eax],eax
007A94A4  a15432fe00                       mov    eax,ds:0xfe3254
007A94A9  894004                           mov    DWORD PTR [eax+0x4],eax
007A94AC  a15432fe00                       mov    eax,ds:0xfe3254
007A94B1  894008                           mov    DWORD PTR [eax+0x8],eax
007A94B4  8b155432fe00                     mov    edx,DWORD PTR ds:0xfe3254
007A94BA  c6423001                         mov    BYTE PTR [edx+0x30],0x1
007A94BE  a15432fe00                       mov    eax,ds:0xfe3254
007A94C3  c6403101                         mov    BYTE PTR [eax+0x31],0x1
007A94C7  c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
007A94CB  6a30                             push   0x30
007A94CD  89356832fe00                     mov    DWORD PTR ds:0xfe3268,esi
007A94D3  e8907d0e00                       call   0x891268
007A94D8  83c404                           add    esp,0x4
007A94DB  3bc6                             cmp    eax,esi
007A94DD  0f8468020000                     je     0x7a974b
007A94E3  a36432fe00                       mov    ds:0xfe3264,eax
007A94E8  8900                             mov    DWORD PTR [eax],eax
007A94EA  a16432fe00                       mov    eax,ds:0xfe3264
007A94EF  894004                           mov    DWORD PTR [eax+0x4],eax
007A94F2  a16432fe00                       mov    eax,ds:0xfe3264
007A94F7  894008                           mov    DWORD PTR [eax+0x8],eax
007A94FA  8b0d6432fe00                     mov    ecx,DWORD PTR ds:0xfe3264
007A9500  c6412c01                         mov    BYTE PTR [ecx+0x2c],0x1
007A9504  8b156432fe00                     mov    edx,DWORD PTR ds:0xfe3264
007A950A  c6422d01                         mov    BYTE PTR [edx+0x2d],0x1
007A950E  68b009bd00                       push   0xbd09b0
007A9513  89357032fe00                     mov    DWORD PTR ds:0xfe3270,esi
007A9519  89357432fe00                     mov    DWORD PTR ds:0xfe3274,esi
007A951F  89357832fe00                     mov    DWORD PTR ds:0xfe3278,esi
007A9525  89358032fe00                     mov    DWORD PTR ds:0xfe3280,esi
007A952B  e8ea8d0e00                       call   0x89231a
007A9530  83c404                           add    esp,0x4
007A9533  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007A9537  8bd7                             mov    edx,edi
007A9539  b95032fe00                       mov    ecx,0xfe3250
007A953E  e80d630200                       call   0x7cf850
007A9543  8bf8                             mov    edi,eax
007A9545  c745e40f000000                   mov    DWORD PTR [ebp-0x1c],0xf
007A954C  c745e000000000                   mov    DWORD PTR [ebp-0x20],0x0
007A9553  c645d000                         mov    BYTE PTR [ebp-0x30],0x0
007A9557  6aff                             push   0xffffffff
007A9559  6a00                             push   0x0
007A955B  8d5f7c                           lea    ebx,[edi+0x7c]
007A955E  53                               push   ebx
007A955F  8d4dd0                           lea    ecx,[ebp-0x30]
007A9562  c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
007A9566  e8d59ac5ff                       call   0x403040
007A956B  837f7800                         cmp    DWORD PTR [edi+0x78],0x0
007A956F  0f84c7000000                     je     0x7a963c
007A9575  837de410                         cmp    DWORD PTR [ebp-0x1c],0x10
007A9579  8b45d0                           mov    eax,DWORD PTR [ebp-0x30]
007A957C  7303                             jae    0x7a9581
007A957E  8d45d0                           lea    eax,[ebp-0x30]
007A9581  8b4dc0                           mov    ecx,DWORD PTR [ebp-0x40]
007A9584  8b711c                           mov    esi,DWORD PTR [ecx+0x1c]
007A9587  85f6                             test   esi,esi
007A9589  0f84ad000000                     je     0x7a963c
007A958F  50                               push   eax
007A9590  8d55c4                           lea    edx,[ebp-0x3c]
007A9593  52                               push   edx
007A9594  e8379d0200                       call   0x7d32d0
007A9599  85c0                             test   eax,eax
007A959B  0f849b000000                     je     0x7a963c
007A95A1  8b45c4                           mov    eax,DWORD PTR [ebp-0x3c]
007A95A4  85c0                             test   eax,eax
007A95A6  0f8890000000                     js     0x7a963c
007A95AC  8b75c0                           mov    esi,DWORD PTR [ebp-0x40]
007A95AF  8bd8                             mov    ebx,eax
007A95B1  8b8650010000                     mov    eax,DWORD PTR [esi+0x150]
007A95B7  8d4d98                           lea    ecx,[ebp-0x68]
007A95BA  895d98                           mov    DWORD PTR [ebp-0x68],ebx
007A95BD  897d9c                           mov    DWORD PTR [ebp-0x64],edi
007A95C0  3bc8                             cmp    ecx,eax
007A95C2  734d                             jae    0x7a9611
007A95C4  8b8e4c010000                     mov    ecx,DWORD PTR [esi+0x14c]
007A95CA  8d5598                           lea    edx,[ebp-0x68]
007A95CD  3bca                             cmp    ecx,edx
007A95CF  7740                             ja     0x7a9611
007A95D1  8bfa                             mov    edi,edx
007A95D3  2bf9                             sub    edi,ecx
007A95D5  c1ff03                           sar    edi,0x3
007A95D8  3b8654010000                     cmp    eax,DWORD PTR [esi+0x154]
007A95DE  750b                             jne    0x7a95eb
007A95E0  8d8e4c010000                     lea    ecx,[esi+0x14c]
007A95E6  e805480200                       call   0x7cddf0
007A95EB  8b864c010000                     mov    eax,DWORD PTR [esi+0x14c]
007A95F1  8d0cf8                           lea    ecx,[eax+edi*8]
007A95F4  8b8650010000                     mov    eax,DWORD PTR [esi+0x150]
007A95FA  85c0                             test   eax,eax
007A95FC  740a                             je     0x7a9608
007A95FE  8b11                             mov    edx,DWORD PTR [ecx]
007A9600  8910                             mov    DWORD PTR [eax],edx
007A9602  8b4904                           mov    ecx,DWORD PTR [ecx+0x4]
007A9605  894804                           mov    DWORD PTR [eax+0x4],ecx
007A9608  83865001000008                   add    DWORD PTR [esi+0x150],0x8
007A960F  eb7b                             jmp    0x7a968c
007A9611  3b8654010000                     cmp    eax,DWORD PTR [esi+0x154]
007A9617  750b                             jne    0x7a9624
007A9619  8d8e4c010000                     lea    ecx,[esi+0x14c]
007A961F  e8cc470200                       call   0x7cddf0
007A9624  8b8650010000                     mov    eax,DWORD PTR [esi+0x150]
007A962A  85c0                             test   eax,eax
007A962C  7405                             je     0x7a9633
007A962E  8918                             mov    DWORD PTR [eax],ebx
007A9630  897804                           mov    DWORD PTR [eax+0x4],edi
007A9633  83865001000008                   add    DWORD PTR [esi+0x150],0x8
007A963A  eb50                             jmp    0x7a968c
007A963C  897dc4                           mov    DWORD PTR [ebp-0x3c],edi
007A963F  8bf7                             mov    esi,edi
007A9641  c645fc09                         mov    BYTE PTR [ebp-0x4],0x9
007A9645  e8d6f20200                       call   0x7d8920
007A964A  837b1410                         cmp    DWORD PTR [ebx+0x14],0x10
007A964E  720b                             jb     0x7a965b
007A9650  8b03                             mov    eax,DWORD PTR [ebx]
007A9652  50                               push   eax
007A9653  e8b47b0e00                       call   0x89120c
007A9658  83c404                           add    esp,0x4
007A965B  33f6                             xor    esi,esi
007A965D  c743140f000000                   mov    DWORD PTR [ebx+0x14],0xf
007A9664  897310                           mov    DWORD PTR [ebx+0x10],esi
007A9667  c60300                           mov    BYTE PTR [ebx],0x0
007A966A  8b475c                           mov    eax,DWORD PTR [edi+0x5c]
007A966D  3bc6                             cmp    eax,esi
007A966F  7409                             je     0x7a967a
007A9671  50                               push   eax
007A9672  e8957b0e00                       call   0x89120c
007A9677  83c404                           add    esp,0x4
007A967A  57                               push   edi
007A967B  89775c                           mov    DWORD PTR [edi+0x5c],esi
007A967E  897760                           mov    DWORD PTR [edi+0x60],esi
007A9681  897764                           mov    DWORD PTR [edi+0x64],esi
007A9684  e8837b0e00                       call   0x89120c
007A9689  83c404                           add    esp,0x4
007A968C  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007A9690  837de410                         cmp    DWORD PTR [ebp-0x1c],0x10
007A9694  720c                             jb     0x7a96a2
007A9696  8b55d0                           mov    edx,DWORD PTR [ebp-0x30]
007A9699  52                               push   edx
007A969A  e86d7b0e00                       call   0x89120c
007A969F  83c404                           add    esp,0x4
007A96A2  8b45bc                           mov    eax,DWORD PTR [ebp-0x44]
007A96A5  8bb0c4000000                     mov    esi,DWORD PTR [eax+0xc4]
007A96AB  8b88c8000000                     mov    ecx,DWORD PTR [eax+0xc8]
007A96B1  8b7dcc                           mov    edi,DWORD PTR [ebp-0x34]
007A96B4  8345c838                         add    DWORD PTR [ebp-0x38],0x38
007A96B8  2bce                             sub    ecx,esi
007A96BA  b893244992                       mov    eax,0x92492493
007A96BF  f7e9                             imul   ecx
007A96C1  03d1                             add    edx,ecx
007A96C3  c1fa05                           sar    edx,0x5
007A96C6  8bc2                             mov    eax,edx
007A96C8  c1e81f                           shr    eax,0x1f
007A96CB  47                               inc    edi
007A96CC  03c2                             add    eax,edx
007A96CE  897dcc                           mov    DWORD PTR [ebp-0x34],edi
007A96D1  3bf8                             cmp    edi,eax
007A96D3  0f8277fdffff                     jb     0x7a9450
007A96D9  8b5dc0                           mov    ebx,DWORD PTR [ebp-0x40]
007A96DC  33ff                             xor    edi,edi
007A96DE  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
007A96E1  8b4208                           mov    eax,DWORD PTR [edx+0x8]
007A96E4  80780400                         cmp    BYTE PTR [eax+0x4],0x0
007A96E8  0f8571020000                     jne    0x7a995f
007A96EE  6a38                             push   0x38
007A96F0  e8737b0e00                       call   0x891268
007A96F5  8bf0                             mov    esi,eax
007A96F7  83c404                           add    esp,0x4
007A96FA  8975b0                           mov    DWORD PTR [ebp-0x50],esi
007A96FD  c645fc0a                         mov    BYTE PTR [ebp-0x4],0xa
007A9701  3bf7                             cmp    esi,edi
007A9703  0f84c9000000                     je     0x7a97d2
007A9709  8d4608                           lea    eax,[esi+0x8]
007A970C  50                               push   eax
007A970D  e80eb9ffff                       call   0x7a5020
007A9712  c645fc0b                         mov    BYTE PTR [ebp-0x4],0xb
007A9716  6a28                             push   0x28
007A9718  897e30                           mov    DWORD PTR [esi+0x30],edi
007A971B  e8487b0e00                       call   0x891268
007A9720  83c404                           add    esp,0x4
007A9723  3bc7                             cmp    eax,edi
007A9725  747e                             je     0x7a97a5
007A9727  89462c                           mov    DWORD PTR [esi+0x2c],eax
007A972A  8900                             mov    DWORD PTR [eax],eax
007A972C  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
007A972F  894004                           mov    DWORD PTR [eax+0x4],eax
007A9732  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
007A9735  894008                           mov    DWORD PTR [eax+0x8],eax
007A9738  8b4e2c                           mov    ecx,DWORD PTR [esi+0x2c]
007A973B  c6412001                         mov    BYTE PTR [ecx+0x20],0x1
007A973F  8b562c                           mov    edx,DWORD PTR [esi+0x2c]
007A9742  c6422101                         mov    BYTE PTR [edx+0x21],0x1
007A9746  e989000000                       jmp    0x7a97d4
007A974B  8d4d8c                           lea    ecx,[ebp-0x74]
007A974E  51                               push   ecx
007A974F  8d8d24ffffff                     lea    ecx,[ebp-0xdc]
007A9755  89758c                           mov    DWORD PTR [ebp-0x74],esi
007A9758  e84c790e00                       call   0x8910a9
007A975D  68a857c800                       push   0xc857a8
007A9762  8d9524ffffff                     lea    edx,[ebp-0xdc]
007A9768  52                               push   edx
007A9769  c78524ffffffa42cbd00             mov    DWORD PTR [ebp-0xdc],0xbd2ca4
007A9773  e878320f00                       call   0x89c9f0
007A9778  8d45b0                           lea    eax,[ebp-0x50]
007A977B  50                               push   eax
007A977C  8d8d48ffffff                     lea    ecx,[ebp-0xb8]
007A9782  8975b0                           mov    DWORD PTR [ebp-0x50],esi
007A9785  e81f790e00                       call   0x8910a9
007A978A  68a857c800                       push   0xc857a8
007A978F  8d8d48ffffff                     lea    ecx,[ebp-0xb8]
007A9795  51                               push   ecx
007A9796  c78548ffffffa42cbd00             mov    DWORD PTR [ebp-0xb8],0xbd2ca4
007A97A0  e84b320f00                       call   0x89c9f0
007A97A5  8d45c0                           lea    eax,[ebp-0x40]
007A97A8  50                               push   eax
007A97A9  8d8d3cffffff                     lea    ecx,[ebp-0xc4]
007A97AF  897dc0                           mov    DWORD PTR [ebp-0x40],edi
007A97B2  e8f2780e00                       call   0x8910a9
007A97B7  68a857c800                       push   0xc857a8
007A97BC  8d8d3cffffff                     lea    ecx,[ebp-0xc4]
007A97C2  51                               push   ecx
007A97C3  c7853cffffffa42cbd00             mov    DWORD PTR [ebp-0xc4],0xbd2ca4
007A97CD  e81e320f00                       call   0x89c9f0
007A97D2  33f6                             xor    esi,esi
007A97D4  33c0                             xor    eax,eax
007A97D6  56                               push   esi
007A97D7  8d55b4                           lea    edx,[ebp-0x4c]
007A97DA  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007A97DE  52                               push   edx
007A97DF  8945b4                           mov    DWORD PTR [ebp-0x4c],eax
007A97E2  8945b8                           mov    DWORD PTR [ebp-0x48],eax
007A97E5  e8960f0000                       call   0x7aa780
007A97EA  c645fc0c                         mov    BYTE PTR [ebp-0x4],0xc
007A97EE  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
007A97F1  8b4b18                           mov    ecx,DWORD PTR [ebx+0x18]
007A97F4  8d7808                           lea    edi,[eax+0x8]
007A97F7  8d956cffffff                     lea    edx,[ebp-0x94]
007A97FD  8908                             mov    DWORD PTR [eax],ecx
007A97FF  3bfa                             cmp    edi,edx
007A9801  7422                             je     0x7a9825
007A9803  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A9806  8b08                             mov    ecx,DWORD PTR [eax]
007A9808  50                               push   eax
007A9809  51                               push   ecx
007A980A  8d75bc                           lea    esi,[ebp-0x44]
007A980D  8bc7                             mov    eax,edi
007A980F  e84c09d2ff                       call   0x4ca160
007A9814  8d856cffffff                     lea    eax,[ebp-0x94]
007A981A  50                               push   eax
007A981B  8bc7                             mov    eax,edi
007A981D  e81e7dffff                       call   0x7a1540
007A9822  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
007A9825  83c710                           add    edi,0x10
007A9828  8d8d7cffffff                     lea    ecx,[ebp-0x84]
007A982E  3bf9                             cmp    edi,ecx
007A9830  7425                             je     0x7a9857
007A9832  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A9835  8b08                             mov    ecx,DWORD PTR [eax]
007A9837  50                               push   eax
007A9838  51                               push   ecx
007A9839  8db520ffffff                     lea    esi,[ebp-0xe0]
007A983F  8bc7                             mov    eax,edi
007A9841  e8dad8f2ff                       call   0x6d7120
007A9846  8d957cffffff                     lea    edx,[ebp-0x84]
007A984C  52                               push   edx
007A984D  8bc7                             mov    eax,edi
007A984F  e80c7effff                       call   0x7a1660
007A9854  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
007A9857  8b4da0                           mov    ecx,DWORD PTR [ebp-0x60]
007A985A  8d7828                           lea    edi,[eax+0x28]
007A985D  8d9554ffffff                     lea    edx,[ebp-0xac]
007A9863  894804                           mov    DWORD PTR [eax+0x4],ecx
007A9866  3bfa                             cmp    edi,edx
007A9868  741f                             je     0x7a9889
007A986A  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A986D  8b08                             mov    ecx,DWORD PTR [eax]
007A986F  50                               push   eax
007A9870  51                               push   ecx
007A9871  8d75a0                           lea    esi,[ebp-0x60]
007A9874  8bc7                             mov    eax,edi
007A9876  e8a5d8f2ff                       call   0x6d7120
007A987B  8d8554ffffff                     lea    eax,[ebp-0xac]
007A9881  50                               push   eax
007A9882  8bc7                             mov    eax,edi
007A9884  e8c7080000                       call   0x7aa150
007A9889  8b55b8                           mov    edx,DWORD PTR [ebp-0x48]
007A988C  33c0                             xor    eax,eax
007A988E  8945a4                           mov    DWORD PTR [ebp-0x5c],eax
007A9891  8945a8                           mov    DWORD PTR [ebp-0x58],eax
007A9894  3bd0                             cmp    edx,eax
007A9896  742d                             je     0x7a98c5
007A9898  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
007A989B  3bc8                             cmp    ecx,eax
007A989D  7426                             je     0x7a98c5
007A989F  90                               nop
007A98A0  8d7101                           lea    esi,[ecx+0x1]
007A98A3  8d7a04                           lea    edi,[edx+0x4]
007A98A6  8bc1                             mov    eax,ecx
007A98A8  f00fb137                         lock cmpxchg DWORD PTR [edi],esi
007A98AC  3bc1                             cmp    eax,ecx
007A98AE  7409                             je     0x7a98b9
007A98B0  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
007A98B3  85c9                             test   ecx,ecx
007A98B5  75e9                             jne    0x7a98a0
007A98B7  eb0c                             jmp    0x7a98c5
007A98B9  8b4db8                           mov    ecx,DWORD PTR [ebp-0x48]
007A98BC  8b55b4                           mov    edx,DWORD PTR [ebp-0x4c]
007A98BF  894da8                           mov    DWORD PTR [ebp-0x58],ecx
007A98C2  8955a4                           mov    DWORD PTR [ebp-0x5c],edx
007A98C5  c645fc0d                         mov    BYTE PTR [ebp-0x4],0xd
007A98C9  e8c229cdff                       call   0x47c290
007A98CE  8bf0                             mov    esi,eax
007A98D0  8d7e70                           lea    edi,[esi+0x70]
007A98D3  57                               push   edi
007A98D4  89bd34ffffff                     mov    DWORD PTR [ebp-0xcc],edi
007A98DA  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
007A98E0  83c638                           add    esi,0x38
007A98E3  56                               push   esi
007A98E4  8d4da4                           lea    ecx,[ebp-0x5c]
007A98E7  c645fc0f                         mov    BYTE PTR [ebp-0x4],0xf
007A98EB  e87076ffff                       call   0x7a0f60
007A98F0  57                               push   edi
007A98F1  ff154822bd00                     call   DWORD PTR ds:0xbd2248
007A98F7  c645fc0c                         mov    BYTE PTR [ebp-0x4],0xc
007A98FB  8b75a8                           mov    esi,DWORD PTR [ebp-0x58]
007A98FE  85f6                             test   esi,esi
007A9900  7429                             je     0x7a992b
007A9902  8d4604                           lea    eax,[esi+0x4]
007A9905  83c9ff                           or     ecx,0xffffffff
007A9908  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A990C  751d                             jne    0x7a992b
007A990E  8b16                             mov    edx,DWORD PTR [esi]
007A9910  8b02                             mov    eax,DWORD PTR [edx]
007A9912  8bce                             mov    ecx,esi
007A9914  ffd0                             call   eax
007A9916  8d4e08                           lea    ecx,[esi+0x8]
007A9919  83caff                           or     edx,0xffffffff
007A991C  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A9920  7509                             jne    0x7a992b
007A9922  8b06                             mov    eax,DWORD PTR [esi]
007A9924  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A9927  8bce                             mov    ecx,esi
007A9929  ffd2                             call   edx
007A992B  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007A992F  8b75b8                           mov    esi,DWORD PTR [ebp-0x48]
007A9932  85f6                             test   esi,esi
007A9934  7429                             je     0x7a995f
007A9936  8d4604                           lea    eax,[esi+0x4]
007A9939  83c9ff                           or     ecx,0xffffffff
007A993C  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A9940  751d                             jne    0x7a995f
007A9942  8b16                             mov    edx,DWORD PTR [esi]
007A9944  8b02                             mov    eax,DWORD PTR [edx]
007A9946  8bce                             mov    ecx,esi
007A9948  ffd0                             call   eax
007A994A  8d4e08                           lea    ecx,[esi+0x8]
007A994D  83caff                           or     edx,0xffffffff
007A9950  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A9954  7509                             jne    0x7a995f
007A9956  8b06                             mov    eax,DWORD PTR [esi]
007A9958  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A995B  8bce                             mov    ecx,esi
007A995D  ffd2                             call   edx
007A995F  b801000000                       mov    eax,0x1
007A9964  894324                           mov    DWORD PTR [ebx+0x24],eax
007A9967  898318010000                     mov    DWORD PTR [ebx+0x118],eax
007A996D  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
007A9973  2b4590                           sub    eax,DWORD PTR [ebp-0x70]
007A9976  50                               push   eax
007A9977  6838f6c400                       push   0xc4f638
007A997C  e83c970e00                       call   0x8930bd
007A9981  83c408                           add    esp,0x8
007A9984  c645fc10                         mov    BYTE PTR [ebp-0x4],0x10
007A9988  8b8558ffffff                     mov    eax,DWORD PTR [ebp-0xa8]
007A998E  8b08                             mov    ecx,DWORD PTR [eax]
007A9990  50                               push   eax
007A9991  51                               push   ecx
007A9992  8d7594                           lea    esi,[ebp-0x6c]
007A9995  8d8554ffffff                     lea    eax,[ebp-0xac]
007A999B  e880d7f2ff                       call   0x6d7120
007A99A0  8b8558ffffff                     mov    eax,DWORD PTR [ebp-0xa8]
007A99A6  50                               push   eax
007A99A7  e860780e00                       call   0x89120c
007A99AC  83c404                           add    esp,0x4
007A99AF  8d8d7cffffff                     lea    ecx,[ebp-0x84]
007A99B5  894d94                           mov    DWORD PTR [ebp-0x6c],ecx
007A99B8  c645fc12                         mov    BYTE PTR [ebp-0x4],0x12
007A99BC  8b4580                           mov    eax,DWORD PTR [ebp-0x80]
007A99BF  8b08                             mov    ecx,DWORD PTR [eax]
007A99C1  50                               push   eax
007A99C2  51                               push   ecx
007A99C3  8db538ffffff                     lea    esi,[ebp-0xc8]
007A99C9  8d857cffffff                     lea    eax,[ebp-0x84]
007A99CF  e84cd7f2ff                       call   0x6d7120
007A99D4  8b5580                           mov    edx,DWORD PTR [ebp-0x80]
007A99D7  52                               push   edx
007A99D8  e82f780e00                       call   0x89120c
007A99DD  83c404                           add    esp,0x4
007A99E0  c645fc13                         mov    BYTE PTR [ebp-0x4],0x13
007A99E4  8b8570ffffff                     mov    eax,DWORD PTR [ebp-0x90]
007A99EA  8b08                             mov    ecx,DWORD PTR [eax]
007A99EC  50                               push   eax
007A99ED  51                               push   ecx
007A99EE  8db530ffffff                     lea    esi,[ebp-0xd0]
007A99F4  8d856cffffff                     lea    eax,[ebp-0x94]
007A99FA  e86107d2ff                       call   0x4ca160
007A99FF  8b8570ffffff                     mov    eax,DWORD PTR [ebp-0x90]
007A9A05  50                               push   eax
007A9A06  e801780e00                       call   0x89120c
007A9A0B  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007A9A12  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
007A9A15  83c404                           add    esp,0x4
007A9A18  85c0                             test   eax,eax
007A9A1A  742b                             je     0x7a9a47
007A9A1C  8bf0                             mov    esi,eax
007A9A1E  83c004                           add    eax,0x4
007A9A21  83c9ff                           or     ecx,0xffffffff
007A9A24  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A9A28  751d                             jne    0x7a9a47
007A9A2A  8b16                             mov    edx,DWORD PTR [esi]
007A9A2C  8b02                             mov    eax,DWORD PTR [edx]
007A9A2E  8bce                             mov    ecx,esi
007A9A30  ffd0                             call   eax
007A9A32  83caff                           or     edx,0xffffffff
007A9A35  8d4e08                           lea    ecx,[esi+0x8]
007A9A38  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A9A3C  7509                             jne    0x7a9a47
007A9A3E  8b06                             mov    eax,DWORD PTR [esi]
007A9A40  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A9A43  8bce                             mov    ecx,esi
007A9A45  ffd2                             call   edx
007A9A47  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007A9A4A  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A9A51  59                               pop    ecx
007A9A52  5f                               pop    edi
007A9A53  5e                               pop    esi
007A9A54  5b                               pop    ebx
007A9A55  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
007A9A58  33cd                             xor    ecx,ebp
007A9A5A  e8a2750e00                       call   0x891001
007A9A5F  8be5                             mov    esp,ebp
007A9A61  5d                               pop    ebp
007A9A62  c20c00                           ret    0xc

; drain_deferred_results [NEW_CALLBACK_TARGET_JOIN] 0x79db10..0x79dcdc exclusive
0079DB10  55                               push   ebp
0079DB11  8bec                             mov    ebp,esp
0079DB13  6aff                             push   0xffffffff
0079DB15  68408f9100                       push   0x918f40
0079DB1A  64a100000000                     mov    eax,fs:0x0
0079DB20  50                               push   eax
0079DB21  83ec2c                           sub    esp,0x2c
0079DB24  53                               push   ebx
0079DB25  56                               push   esi
0079DB26  57                               push   edi
0079DB27  a1201fd600                       mov    eax,ds:0xd61f20
0079DB2C  33c5                             xor    eax,ebp
0079DB2E  50                               push   eax
0079DB2F  8d45f4                           lea    eax,[ebp-0xc]
0079DB32  64a300000000                     mov    fs:0x0,eax
0079DB38  8bf1                             mov    esi,ecx
0079DB3A  8b86b0000000                     mov    eax,DWORD PTR [esi+0xb0]
0079DB40  3b86b4000000                     cmp    eax,DWORD PTR [esi+0xb4]
0079DB46  8d9eb0000000                     lea    ebx,[esi+0xb0]
0079DB4C  755d                             jne    0x79dbab
0079DB4E  8dbe98000000                     lea    edi,[esi+0x98]
0079DB54  57                               push   edi
0079DB55  897de4                           mov    DWORD PTR [ebp-0x1c],edi
0079DB58  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0079DB5E  81c688000000                     add    esi,0x88
0079DB64  56                               push   esi
0079DB65  8bc3                             mov    eax,ebx
0079DB67  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0079DB6E  e8ad320000                       call   0x7a0e20
0079DB73  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0079DB76  8b0e                             mov    ecx,DWORD PTR [esi]
0079DB78  3bc8                             cmp    ecx,eax
0079DB7A  7428                             je     0x79dba4
0079DB7C  8b55d8                           mov    edx,DWORD PTR [ebp-0x28]
0079DB7F  52                               push   edx
0079DB80  51                               push   ecx
0079DB81  50                               push   eax
0079DB82  e8995b0000                       call   0x7a3720
0079DB87  8b4dd8                           mov    ecx,DWORD PTR [ebp-0x28]
0079DB8A  83c40c                           add    esp,0xc
0079DB8D  8bf8                             mov    edi,eax
0079DB8F  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0079DB92  51                               push   ecx
0079DB93  50                               push   eax
0079DB94  8bc7                             mov    eax,edi
0079DB96  e8055c0000                       call   0x7a37a0
0079DB9B  897e04                           mov    DWORD PTR [esi+0x4],edi
0079DB9E  8b7de4                           mov    edi,DWORD PTR [ebp-0x1c]
0079DBA1  83c408                           add    esp,0x8
0079DBA4  57                               push   edi
0079DBA5  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0079DBAB  33f6                             xor    esi,esi
0079DBAD  33ff                             xor    edi,edi
0079DBAF  897dc8                           mov    DWORD PTR [ebp-0x38],edi
0079DBB2  8975cc                           mov    DWORD PTR [ebp-0x34],esi
0079DBB5  8975d0                           mov    DWORD PTR [ebp-0x30],esi
0079DBB8  c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0079DBBF  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0079DBC5  8b5304                           mov    edx,DWORD PTR [ebx+0x4]
0079DBC8  8945d8                           mov    DWORD PTR [ebp-0x28],eax
0079DBCB  8b03                             mov    eax,DWORD PTR [ebx]
0079DBCD  2bd0                             sub    edx,eax
0079DBCF  c1fa03                           sar    edx,0x3
0079DBD2  c645f300                         mov    BYTE PTR [ebp-0xd],0x0
0079DBD6  8975ec                           mov    DWORD PTR [ebp-0x14],esi
0079DBD9  85d2                             test   edx,edx
0079DBDB  0f84bb000000                     je     0x79dc9c
0079DBE1  807df300                         cmp    BYTE PTR [ebp-0xd],0x0
0079DBE5  0f858c000000                     jne    0x79dc77
0079DBEB  83ec08                           sub    esp,0x8
0079DBEE  8bcc                             mov    ecx,esp
0079DBF0  8d3cf500000000                   lea    edi,[esi*8+0x0]
0079DBF7  8965dc                           mov    DWORD PTR [ebp-0x24],esp
0079DBFA  c70100000000                     mov    DWORD PTR [ecx],0x0
0079DC00  c7410400000000                   mov    DWORD PTR [ecx+0x4],0x0
0079DC07  894ddc                           mov    DWORD PTR [ebp-0x24],ecx
0079DC0A  8b4c3804                         mov    ecx,DWORD PTR [eax+edi*1+0x4]
0079DC0E  8b0438                           mov    eax,DWORD PTR [eax+edi*1]
0079DC11  894de8                           mov    DWORD PTR [ebp-0x18],ecx
0079DC14  8945e0                           mov    DWORD PTR [ebp-0x20],eax
0079DC17  85c9                             test   ecx,ecx
0079DC19  7437                             je     0x79dc52
0079DC1B  8d4104                           lea    eax,[ecx+0x4]
0079DC1E  8b08                             mov    ecx,DWORD PTR [eax]
0079DC20  85c9                             test   ecx,ecx
0079DC22  742e                             je     0x79dc52
0079DC24  8bf0                             mov    esi,eax
0079DC26  8d5101                           lea    edx,[ecx+0x1]
0079DC29  8bc1                             mov    eax,ecx
0079DC2B  f00fb116                         lock cmpxchg DWORD PTR [esi],edx
0079DC2F  3bc1                             cmp    eax,ecx
0079DC31  8b45e8                           mov    eax,DWORD PTR [ebp-0x18]
0079DC34  740c                             je     0x79dc42
0079DC36  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0079DC39  83c004                           add    eax,0x4
0079DC3C  85c9                             test   ecx,ecx
0079DC3E  75e4                             jne    0x79dc24
0079DC40  eb0d                             jmp    0x79dc4f
0079DC42  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
0079DC45  8b75dc                           mov    esi,DWORD PTR [ebp-0x24]
0079DC48  50                               push   eax
0079DC49  51                               push   ecx
0079DC4A  e871550000                       call   0x7a31c0
0079DC4F  8b75ec                           mov    esi,DWORD PTR [ebp-0x14]
0079DC52  8b03                             mov    eax,DWORD PTR [ebx]
0079DC54  8b0438                           mov    eax,DWORD PTR [eax+edi*1]
0079DC57  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0079DC5A  8b4068                           mov    eax,DWORD PTR [eax+0x68]
0079DC5D  50                               push   eax
0079DC5E  e88db40000                       call   0x7a90f0
0079DC63  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0079DC69  2b45d8                           sub    eax,DWORD PTR [ebp-0x28]
0079DC6C  83f803                           cmp    eax,0x3
0079DC6F  7612                             jbe    0x79dc83
0079DC71  c645f301                         mov    BYTE PTR [ebp-0xd],0x1
0079DC75  eb0c                             jmp    0x79dc83
0079DC77  8d55c8                           lea    edx,[ebp-0x38]
0079DC7A  8d0cf0                           lea    ecx,[eax+esi*8]
0079DC7D  52                               push   edx
0079DC7E  e8dd320000                       call   0x7a0f60
0079DC83  8b03                             mov    eax,DWORD PTR [ebx]
0079DC85  8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0079DC88  2bc8                             sub    ecx,eax
0079DC8A  46                               inc    esi
0079DC8B  c1f903                           sar    ecx,0x3
0079DC8E  8975ec                           mov    DWORD PTR [ebp-0x14],esi
0079DC91  3bf1                             cmp    esi,ecx
0079DC93  0f8248ffffff                     jb     0x79dbe1
0079DC99  8b7dc8                           mov    edi,DWORD PTR [ebp-0x38]
0079DC9C  8d55c8                           lea    edx,[ebp-0x38]
0079DC9F  52                               push   edx
0079DCA0  8bc3                             mov    eax,ebx
0079DCA2  e879310000                       call   0x7a0e20
0079DCA7  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0079DCAE  85ff                             test   edi,edi
0079DCB0  7418                             je     0x79dcca
0079DCB2  8b45d8                           mov    eax,DWORD PTR [ebp-0x28]
0079DCB5  8b4dcc                           mov    ecx,DWORD PTR [ebp-0x34]
0079DCB8  50                               push   eax
0079DCB9  51                               push   ecx
0079DCBA  8bc7                             mov    eax,edi
0079DCBC  e8df5a0000                       call   0x7a37a0
0079DCC1  57                               push   edi
0079DCC2  e845350f00                       call   0x89120c
0079DCC7  83c40c                           add    esp,0xc
0079DCCA  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0079DCCD  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0079DCD4  59                               pop    ecx
0079DCD5  5f                               pop    edi
0079DCD6  5e                               pop    esi
0079DCD7  5b                               pop    ebx
0079DCD8  8be5                             mov    esp,ebp
0079DCDA  5d                               pop    ebp
0079DCDB  c3                               ret

; doll_destructor_release_prefix [NEW_RELEASE_WRITER_JOIN] 0x7a51c0..0x7a535b exclusive
007A51C0  55                               push   ebp
007A51C1  8bec                             mov    ebp,esp
007A51C3  6aff                             push   0xffffffff
007A51C5  68c6929300                       push   0x9392c6
007A51CA  64a100000000                     mov    eax,fs:0x0
007A51D0  50                               push   eax
007A51D1  83ec10                           sub    esp,0x10
007A51D4  53                               push   ebx
007A51D5  56                               push   esi
007A51D6  57                               push   edi
007A51D7  a1201fd600                       mov    eax,ds:0xd61f20
007A51DC  33c5                             xor    eax,ebp
007A51DE  50                               push   eax
007A51DF  8d45f4                           lea    eax,[ebp-0xc]
007A51E2  64a300000000                     mov    fs:0x0,eax
007A51E8  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A51EB  c7037cf6c400                     mov    DWORD PTR [ebx],0xc4f67c
007A51F1  c7430490f6c400                   mov    DWORD PTR [ebx+0x4],0xc4f690
007A51F8  c74308b0f6c400                   mov    DWORD PTR [ebx+0x8],0xc4f6b0
007A51FF  c7430cc0f6c400                   mov    DWORD PTR [ebx+0xc],0xc4f6c0
007A5206  c745fc0d000000                   mov    DWORD PTR [ebp-0x4],0xd
007A520D  837b2401                         cmp    DWORD PTR [ebx+0x24],0x1
007A5211  0f8544010000                     jne    0x7a535b
007A5217  6a38                             push   0x38
007A5219  e84ac00e00                       call   0x891268
007A521E  83c404                           add    esp,0x4
007A5221  8945e4                           mov    DWORD PTR [ebp-0x1c],eax
007A5224  33f6                             xor    esi,esi
007A5226  c645fc0e                         mov    BYTE PTR [ebp-0x4],0xe
007A522A  3bc6                             cmp    eax,esi
007A522C  7408                             je     0x7a5236
007A522E  50                               push   eax
007A522F  e84c040000                       call   0x7a5680
007A5234  eb02                             jmp    0x7a5238
007A5236  33c0                             xor    eax,eax
007A5238  50                               push   eax
007A5239  8d45e8                           lea    eax,[ebp-0x18]
007A523C  c645fc0d                         mov    BYTE PTR [ebp-0x4],0xd
007A5240  50                               push   eax
007A5241  8975e8                           mov    DWORD PTR [ebp-0x18],esi
007A5244  8975ec                           mov    DWORD PTR [ebp-0x14],esi
007A5247  e834550000                       call   0x7aa780
007A524C  c645fc0f                         mov    BYTE PTR [ebp-0x4],0xf
007A5250  8b75e8                           mov    esi,DWORD PTR [ebp-0x18]
007A5253  8b4b18                           mov    ecx,DWORD PTR [ebx+0x18]
007A5256  8d532c                           lea    edx,[ebx+0x2c]
007A5259  52                               push   edx
007A525A  8d7e08                           lea    edi,[esi+0x8]
007A525D  890e                             mov    DWORD PTR [esi],ecx
007A525F  e8cc040000                       call   0x7a5730
007A5264  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
007A5267  894604                           mov    DWORD PTR [esi+0x4],eax
007A526A  8d436c                           lea    eax,[ebx+0x6c]
007A526D  8d7e28                           lea    edi,[esi+0x28]
007A5270  3bf8                             cmp    edi,eax
007A5272  741f                             je     0x7a5293
007A5274  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A5277  8b08                             mov    ecx,DWORD PTR [eax]
007A5279  50                               push   eax
007A527A  51                               push   ecx
007A527B  8d75e4                           lea    esi,[ebp-0x1c]
007A527E  8bc7                             mov    eax,edi
007A5280  e89b1ef3ff                       call   0x6d7120
007A5285  8d436c                           lea    eax,[ebx+0x6c]
007A5288  50                               push   eax
007A5289  8bc7                             mov    eax,edi
007A528B  e8c04e0000                       call   0x7aa150
007A5290  8b75e8                           mov    esi,DWORD PTR [ebp-0x18]
007A5293  8d7b6c                           lea    edi,[ebx+0x6c]
007A5296  c7431c00000000                   mov    DWORD PTR [ebx+0x1c],0x0
007A529D  e8ce28dfff                       call   0x597b70
007A52A2  8b83a0000000                     mov    eax,DWORD PTR [ebx+0xa0]
007A52A8  33ff                             xor    edi,edi
007A52AA  3bc7                             cmp    eax,edi
007A52AC  7414                             je     0x7a52c2
007A52AE  8b08                             mov    ecx,DWORD PTR [eax]
007A52B0  ff492c                           dec    DWORD PTR [ecx+0x2c]
007A52B3  50                               push   eax
007A52B4  e853bf0e00                       call   0x89120c
007A52B9  83c404                           add    esp,0x4
007A52BC  89bba0000000                     mov    DWORD PTR [ebx+0xa0],edi
007A52C2  83ec08                           sub    esp,0x8
007A52C5  8bc4                             mov    eax,esp
007A52C7  8938                             mov    DWORD PTR [eax],edi
007A52C9  897804                           mov    DWORD PTR [eax+0x4],edi
007A52CC  8b7dec                           mov    edi,DWORD PTR [ebp-0x14]
007A52CF  8965e4                           mov    DWORD PTR [ebp-0x1c],esp
007A52D2  8945f0                           mov    DWORD PTR [ebp-0x10],eax
007A52D5  85ff                             test   edi,edi
007A52D7  7415                             je     0x7a52ee
007A52D9  8bd7                             mov    edx,edi
007A52DB  e8706fcdff                       call   0x47c250
007A52E0  84c0                             test   al,al
007A52E2  740a                             je     0x7a52ee
007A52E4  57                               push   edi
007A52E5  56                               push   esi
007A52E6  8b75f0                           mov    esi,DWORD PTR [ebp-0x10]
007A52E9  e8d2deffff                       call   0x7a31c0
007A52EE  c645fc10                         mov    BYTE PTR [ebp-0x4],0x10
007A52F2  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
007A52F9  7521                             jne    0x7a531c
007A52FB  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
007A5302  c645fc11                         mov    BYTE PTR [ebp-0x4],0x11
007A5306  e8357cffff                       call   0x79cf40
007A530B  6880dbbc00                       push   0xbcdb80
007A5310  e805d00e00                       call   0x89231a
007A5315  83c404                           add    esp,0x4
007A5318  c645fc10                         mov    BYTE PTR [ebp-0x4],0x10
007A531C  b9900efc00                       mov    ecx,0xfc0e90
007A5321  c645fc0f                         mov    BYTE PTR [ebp-0x4],0xf
007A5325  e8d68affff                       call   0x79de00
007A532A  c645fc0d                         mov    BYTE PTR [ebp-0x4],0xd
007A532E  85ff                             test   edi,edi
007A5330  7429                             je     0x7a535b
007A5332  8d4f04                           lea    ecx,[edi+0x4]
007A5335  83caff                           or     edx,0xffffffff
007A5338  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A533C  751d                             jne    0x7a535b
007A533E  8b07                             mov    eax,DWORD PTR [edi]
007A5340  8b10                             mov    edx,DWORD PTR [eax]
007A5342  8bcf                             mov    ecx,edi
007A5344  ffd2                             call   edx
007A5346  8d4708                           lea    eax,[edi+0x8]
007A5349  83c9ff                           or     ecx,0xffffffff
007A534C  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A5350  7509                             jne    0x7a535b
007A5352  8b17                             mov    edx,DWORD PTR [edi]
007A5354  8b4204                           mov    eax,DWORD PTR [edx+0x4]
007A5357  8bcf                             mov    ecx,edi
007A5359  ffd0                             call   eax

; enqueue_doll_release [NEW_RELEASE_QUEUE_JOIN] 0x79de00..0x79de9c exclusive
0079DE00  55                               push   ebp
0079DE01  8bec                             mov    ebp,esp
0079DE03  6aff                             push   0xffffffff
0079DE05  6870a29000                       push   0x90a270
0079DE0A  64a100000000                     mov    eax,fs:0x0
0079DE10  50                               push   eax
0079DE11  51                               push   ecx
0079DE12  56                               push   esi
0079DE13  57                               push   edi
0079DE14  a1201fd600                       mov    eax,ds:0xd61f20
0079DE19  33c5                             xor    eax,ebp
0079DE1B  50                               push   eax
0079DE1C  8d45f4                           lea    eax,[ebp-0xc]
0079DE1F  64a300000000                     mov    fs:0x0,eax
0079DE25  8bf9                             mov    edi,ecx
0079DE27  8d7770                           lea    esi,[edi+0x70]
0079DE2A  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0079DE31  56                               push   esi
0079DE32  8975f0                           mov    DWORD PTR [ebp-0x10],esi
0079DE35  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0079DE3B  83c738                           add    edi,0x38
0079DE3E  57                               push   edi
0079DE3F  8d4d08                           lea    ecx,[ebp+0x8]
0079DE42  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0079DE46  e815310000                       call   0x7a0f60
0079DE4B  56                               push   esi
0079DE4C  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0079DE52  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0079DE59  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0079DE5C  85f6                             test   esi,esi
0079DE5E  7429                             je     0x79de89
0079DE60  8d4604                           lea    eax,[esi+0x4]
0079DE63  83c9ff                           or     ecx,0xffffffff
0079DE66  f00fc108                         lock xadd DWORD PTR [eax],ecx
0079DE6A  751d                             jne    0x79de89
0079DE6C  8b16                             mov    edx,DWORD PTR [esi]
0079DE6E  8b02                             mov    eax,DWORD PTR [edx]
0079DE70  8bce                             mov    ecx,esi
0079DE72  ffd0                             call   eax
0079DE74  8d4e08                           lea    ecx,[esi+0x8]
0079DE77  83caff                           or     edx,0xffffffff
0079DE7A  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079DE7E  7509                             jne    0x79de89
0079DE80  8b06                             mov    eax,DWORD PTR [esi]
0079DE82  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079DE85  8bce                             mov    ecx,esi
0079DE87  ffd2                             call   edx
0079DE89  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0079DE8C  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0079DE93  59                               pop    ecx
0079DE94  5f                               pop    edi
0079DE95  5e                               pop    esi
0079DE96  8be5                             mov    esp,ebp
0079DE98  5d                               pop    ebp
0079DE99  c20800                           ret    0x8

; doll_release_worker [NEW_RESOURCE_RELEASE_JOIN] 0x79ed00..0x79efbf exclusive
0079ED00  55                               push   ebp
0079ED01  8bec                             mov    ebp,esp
0079ED03  6aff                             push   0xffffffff
0079ED05  68d88b9300                       push   0x938bd8
0079ED0A  64a100000000                     mov    eax,fs:0x0
0079ED10  50                               push   eax
0079ED11  83ec0c                           sub    esp,0xc
0079ED14  53                               push   ebx
0079ED15  56                               push   esi
0079ED16  57                               push   edi
0079ED17  a1201fd600                       mov    eax,ds:0xd61f20
0079ED1C  33c5                             xor    eax,ebp
0079ED1E  50                               push   eax
0079ED1F  8d45f4                           lea    eax,[ebp-0xc]
0079ED22  64a300000000                     mov    fs:0x0,eax
0079ED28  8bf1                             mov    esi,ecx
0079ED2A  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0079ED31  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0079ED34  8b08                             mov    ecx,DWORD PTR [eax]
0079ED36  8d55f0                           lea    edx,[ebp-0x10]
0079ED39  894df0                           mov    DWORD PTR [ebp-0x10],ecx
0079ED3C  52                               push   edx
0079ED3D  8d45ec                           lea    eax,[ebp-0x14]
0079ED40  8bce                             mov    ecx,esi
0079ED42  e8496ad7ff                       call   0x515790
0079ED47  8b7604                           mov    esi,DWORD PTR [esi+0x4]
0079ED4A  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
0079ED4D  3bc6                             cmp    eax,esi
0079ED4F  7504                             jne    0x79ed55
0079ED51  33f6                             xor    esi,esi
0079ED53  eb06                             jmp    0x79ed5b
0079ED55  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0079ED58  8b7054                           mov    esi,DWORD PTR [eax+0x54]
0079ED5B  837e5010                         cmp    DWORD PTR [esi+0x50],0x10
0079ED5F  8d463c                           lea    eax,[esi+0x3c]
0079ED62  7202                             jb     0x79ed66
0079ED64  8b00                             mov    eax,DWORD PTR [eax]
0079ED66  8b4e5c                           mov    ecx,DWORD PTR [esi+0x5c]
0079ED69  49                               dec    ecx
0079ED6A  51                               push   ecx
0079ED6B  50                               push   eax
0079ED6C  6834fec400                       push   0xc4fe34
0079ED71  e847430f00                       call   0x8930bd
0079ED76  ff4e5c                           dec    DWORD PTR [esi+0x5c]
0079ED79  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0079ED7C  83c40c                           add    esp,0xc
0079ED7F  83781000                         cmp    DWORD PTR [eax+0x10],0x0
0079ED83  7511                             jne    0x79ed96
0079ED85  33c9                             xor    ecx,ecx
0079ED87  33c0                             xor    eax,eax
0079ED89  e882640200                       call   0x7c5210
0079ED8E  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0079ED91  e9ad000000                       jmp    0x79ee43
0079ED96  8b480c                           mov    ecx,DWORD PTR [eax+0xc]
0079ED99  8b39                             mov    edi,DWORD PTR [ecx]
0079ED9B  3bf9                             cmp    edi,ecx
0079ED9D  0f84a0000000                     je     0x79ee43
0079EDA3  0fb74f0e                         movzx  ecx,WORD PTR [edi+0xe]
0079EDA7  0fb7470c                         movzx  eax,WORD PTR [edi+0xc]
0079EDAB  6aff                             push   0xffffffff
0079EDAD  56                               push   esi
0079EDAE  e89d6d0200                       call   0x7c5b50
0079EDB3  0fb7570c                         movzx  edx,WORD PTR [edi+0xc]
0079EDB7  0fb7470e                         movzx  eax,WORD PTR [edi+0xe]
0079EDBB  c1e210                           shl    edx,0x10
0079EDBE  8d4dec                           lea    ecx,[ebp-0x14]
0079EDC1  0bd0                             or     edx,eax
0079EDC3  51                               push   ecx
0079EDC4  8d45f0                           lea    eax,[ebp-0x10]
0079EDC7  8d8eb4000000                     lea    ecx,[esi+0xb4]
0079EDCD  8955ec                           mov    DWORD PTR [ebp-0x14],edx
0079EDD0  e82b010900                       call   0x82ef00
0079EDD5  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0079EDD8  3b8eb8000000                     cmp    ecx,DWORD PTR [esi+0xb8]
0079EDDE  7413                             je     0x79edf3
0079EDE0  8b4910                           mov    ecx,DWORD PTR [ecx+0x10]
0079EDE3  baffff0000                       mov    edx,0xffff
0079EDE8  660111                           add    WORD PTR [ecx],dx
0079EDEB  7506                             jne    0x79edf3
0079EDED  51                               push   ecx
0079EDEE  e83d5f0200                       call   0x7c4d30
0079EDF3  807f1100                         cmp    BYTE PTR [edi+0x11],0x0
0079EDF7  753e                             jne    0x79ee37
0079EDF9  8b4708                           mov    eax,DWORD PTR [edi+0x8]
0079EDFC  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EE00  751a                             jne    0x79ee1c
0079EE02  8bf8                             mov    edi,eax
0079EE04  8b07                             mov    eax,DWORD PTR [edi]
0079EE06  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EE0A  752b                             jne    0x79ee37
0079EE0C  8d642400                         lea    esp,[esp+0x0]
0079EE10  8bf8                             mov    edi,eax
0079EE12  8b07                             mov    eax,DWORD PTR [edi]
0079EE14  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EE18  74f6                             je     0x79ee10
0079EE1A  eb1b                             jmp    0x79ee37
0079EE1C  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0079EE1F  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EE23  7510                             jne    0x79ee35
0079EE25  3b7808                           cmp    edi,DWORD PTR [eax+0x8]
0079EE28  750b                             jne    0x79ee35
0079EE2A  8bf8                             mov    edi,eax
0079EE2C  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0079EE2F  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0079EE33  74f0                             je     0x79ee25
0079EE35  8bf8                             mov    edi,eax
0079EE37  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0079EE3A  3b780c                           cmp    edi,DWORD PTR [eax+0xc]
0079EE3D  0f8560ffffff                     jne    0x79eda3
0079EE43  8b482c                           mov    ecx,DWORD PTR [eax+0x2c]
0079EE46  8b31                             mov    esi,DWORD PTR [ecx]
0079EE48  3bf1                             cmp    esi,ecx
0079EE4A  7464                             je     0x79eeb0
0079EE4C  8d642400                         lea    esp,[esp+0x0]
0079EE50  8b7e18                           mov    edi,DWORD PTR [esi+0x18]
0079EE53  8bcf                             mov    ecx,edi
0079EE55  e8363b0300                       call   0x7d2990
0079EE5A  85ff                             test   edi,edi
0079EE5C  740a                             je     0x79ee68
0079EE5E  8b07                             mov    eax,DWORD PTR [edi]
0079EE60  8b10                             mov    edx,DWORD PTR [eax]
0079EE62  6a01                             push   0x1
0079EE64  8bcf                             mov    ecx,edi
0079EE66  ffd2                             call   edx
0079EE68  807e2100                         cmp    BYTE PTR [esi+0x21],0x0
0079EE6C  753a                             jne    0x79eea8
0079EE6E  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0079EE71  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0079EE75  7516                             jne    0x79ee8d
0079EE77  8bf0                             mov    esi,eax
0079EE79  8b06                             mov    eax,DWORD PTR [esi]
0079EE7B  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0079EE7F  7527                             jne    0x79eea8
0079EE81  8bf0                             mov    esi,eax
0079EE83  8b06                             mov    eax,DWORD PTR [esi]
0079EE85  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0079EE89  74f6                             je     0x79ee81
0079EE8B  eb1b                             jmp    0x79eea8
0079EE8D  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0079EE90  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0079EE94  7510                             jne    0x79eea6
0079EE96  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0079EE99  750b                             jne    0x79eea6
0079EE9B  8bf0                             mov    esi,eax
0079EE9D  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0079EEA0  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0079EEA4  74f0                             je     0x79ee96
0079EEA6  8bf0                             mov    esi,eax
0079EEA8  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0079EEAB  3b702c                           cmp    esi,DWORD PTR [eax+0x2c]
0079EEAE  75a0                             jne    0x79ee50
0079EEB0  8d7028                           lea    esi,[eax+0x28]
0079EEB3  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0079EEB6  8b5804                           mov    ebx,DWORD PTR [eax+0x4]
0079EEB9  807b2100                         cmp    BYTE PTR [ebx+0x21],0x0
0079EEBD  8bfb                             mov    edi,ebx
0079EEBF  751e                             jne    0x79eedf
0079EEC1  8b4f08                           mov    ecx,DWORD PTR [edi+0x8]
0079EEC4  51                               push   ecx
0079EEC5  8bce                             mov    ecx,esi
0079EEC7  e8e4860b00                       call   0x8575b0
0079EECC  8b3f                             mov    edi,DWORD PTR [edi]
0079EECE  53                               push   ebx
0079EECF  e838230f00                       call   0x89120c
0079EED4  83c404                           add    esp,0x4
0079EED7  807f2100                         cmp    BYTE PTR [edi+0x21],0x0
0079EEDB  8bdf                             mov    ebx,edi
0079EEDD  74e2                             je     0x79eec1
0079EEDF  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0079EEE2  894004                           mov    DWORD PTR [eax+0x4],eax
0079EEE5  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0079EEE8  8900                             mov    DWORD PTR [eax],eax
0079EEEA  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0079EEED  894008                           mov    DWORD PTR [eax+0x8],eax
0079EEF0  c7460800000000                   mov    DWORD PTR [esi+0x8],0x0
0079EEF7  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0079EEFA  8b7204                           mov    esi,DWORD PTR [edx+0x4]
0079EEFD  85f6                             test   esi,esi
0079EEFF  7459                             je     0x79ef5a
0079EF01  8bbea8000000                     mov    edi,DWORD PTR [esi+0xa8]
0079EF07  3bbeac000000                     cmp    edi,DWORD PTR [esi+0xac]
0079EF0D  741a                             je     0x79ef29
0079EF0F  90                               nop
0079EF10  8b0f                             mov    ecx,DWORD PTR [edi]
0079EF12  85c9                             test   ecx,ecx
0079EF14  7408                             je     0x79ef1e
0079EF16  8b01                             mov    eax,DWORD PTR [ecx]
0079EF18  8b10                             mov    edx,DWORD PTR [eax]
0079EF1A  6a01                             push   0x1
0079EF1C  ffd2                             call   edx
0079EF1E  83c704                           add    edi,0x4
0079EF21  3bbeac000000                     cmp    edi,DWORD PTR [esi+0xac]
0079EF27  75e7                             jne    0x79ef10
0079EF29  8b8eac000000                     mov    ecx,DWORD PTR [esi+0xac]
0079EF2F  8b9ea8000000                     mov    ebx,DWORD PTR [esi+0xa8]
0079EF35  3bd9                             cmp    ebx,ecx
0079EF37  7421                             je     0x79ef5a
0079EF39  8bc1                             mov    eax,ecx
0079EF3B  2bc1                             sub    eax,ecx
0079EF3D  c1f802                           sar    eax,0x2
0079EF40  8d3c8500000000                   lea    edi,[eax*4+0x0]
0079EF47  57                               push   edi
0079EF48  51                               push   ecx
0079EF49  53                               push   ebx
0079EF4A  e8a1230f00                       call   0x8912f0
0079EF4F  83c40c                           add    esp,0xc
0079EF52  03fb                             add    edi,ebx
0079EF54  89beac000000                     mov    DWORD PTR [esi+0xac],edi
0079EF5A  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0079EF5D  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0079EF60  85c9                             test   ecx,ecx
0079EF62  7412                             je     0x79ef76
0079EF64  8b11                             mov    edx,DWORD PTR [ecx]
0079EF66  8b02                             mov    eax,DWORD PTR [edx]
0079EF68  6a01                             push   0x1
0079EF6A  ffd0                             call   eax
0079EF6C  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0079EF6F  c7410400000000                   mov    DWORD PTR [ecx+0x4],0x0
0079EF76  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0079EF7D  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0079EF80  85f6                             test   esi,esi
0079EF82  7429                             je     0x79efad
0079EF84  8d5604                           lea    edx,[esi+0x4]
0079EF87  83c8ff                           or     eax,0xffffffff
0079EF8A  f00fc102                         lock xadd DWORD PTR [edx],eax
0079EF8E  751d                             jne    0x79efad
0079EF90  8b16                             mov    edx,DWORD PTR [esi]
0079EF92  8b02                             mov    eax,DWORD PTR [edx]
0079EF94  8bce                             mov    ecx,esi
0079EF96  ffd0                             call   eax
0079EF98  8d4e08                           lea    ecx,[esi+0x8]
0079EF9B  83caff                           or     edx,0xffffffff
0079EF9E  f00fc111                         lock xadd DWORD PTR [ecx],edx
0079EFA2  7509                             jne    0x79efad
0079EFA4  8b06                             mov    eax,DWORD PTR [esi]
0079EFA6  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0079EFA9  8bce                             mov    ecx,esi
0079EFAB  ffd2                             call   edx
0079EFAD  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0079EFB0  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0079EFB7  59                               pop    ecx
0079EFB8  5f                               pop    edi
0079EFB9  5e                               pop    esi
0079EFBA  5b                               pop    ebx
0079EFBB  8be5                             mov    esp,ebp
0079EFBD  5d                               pop    ebp
0079EFBE  c3                               ret

; doll_draw [NEW_DRAW_CONSUMER_JOIN] 0x7a63c0..0x7a6729 exclusive
007A63C0  55                               push   ebp
007A63C1  8bec                             mov    ebp,esp
007A63C3  6aff                             push   0xffffffff
007A63C5  6876bd9200                       push   0x92bd76
007A63CA  64a100000000                     mov    eax,fs:0x0
007A63D0  50                               push   eax
007A63D1  83ec18                           sub    esp,0x18
007A63D4  53                               push   ebx
007A63D5  56                               push   esi
007A63D6  57                               push   edi
007A63D7  a1201fd600                       mov    eax,ds:0xd61f20
007A63DC  33c5                             xor    eax,ebp
007A63DE  50                               push   eax
007A63DF  8d45f4                           lea    eax,[ebp-0xc]
007A63E2  64a300000000                     mov    fs:0x0,eax
007A63E8  8bf9                             mov    edi,ecx
007A63EA  897df0                           mov    DWORD PTR [ebp-0x10],edi
007A63ED  837f1c00                         cmp    DWORD PTR [edi+0x1c],0x0
007A63F1  0f8492020000                     je     0x7a6689
007A63F7  83bf2401000000                   cmp    DWORD PTR [edi+0x124],0x0
007A63FE  0f8485020000                     je     0x7a6689
007A6404  83bfac00000000                   cmp    DWORD PTR [edi+0xac],0x0
007A640B  be01000000                       mov    esi,0x1
007A6410  8bde                             mov    ebx,esi
007A6412  7413                             je     0x7a6427
007A6414  8b8fac000000                     mov    ecx,DWORD PTR [edi+0xac]
007A641A  8b01                             mov    eax,DWORD PTR [ecx]
007A641C  8b502c                           mov    edx,DWORD PTR [eax+0x2c]
007A641F  ffd2                             call   edx
007A6421  85c0                             test   eax,eax
007A6423  7502                             jne    0x7a6427
007A6425  33db                             xor    ebx,ebx
007A6427  8b4f70                           mov    ecx,DWORD PTR [edi+0x70]
007A642A  8b01                             mov    eax,DWORD PTR [ecx]
007A642C  894de8                           mov    DWORD PTR [ebp-0x18],ecx
007A642F  8945ec                           mov    DWORD PTR [ebp-0x14],eax
007A6432  3bc1                             cmp    eax,ecx
007A6434  744d                             je     0x7a6483
007A6436  8b7018                           mov    esi,DWORD PTR [eax+0x18]
007A6439  8b461c                           mov    eax,DWORD PTR [esi+0x1c]
007A643C  2b4618                           sub    eax,DWORD PTR [esi+0x18]
007A643F  33ff                             xor    edi,edi
007A6441  c1f802                           sar    eax,0x2
007A6444  85c0                             test   eax,eax
007A6446  7423                             je     0x7a646b
007A6448  8b4e18                           mov    ecx,DWORD PTR [esi+0x18]
007A644B  8b0cb9                           mov    ecx,DWORD PTR [ecx+edi*4]
007A644E  8b11                             mov    edx,DWORD PTR [ecx]
007A6450  8b4230                           mov    eax,DWORD PTR [edx+0x30]
007A6453  ffd0                             call   eax
007A6455  85c0                             test   eax,eax
007A6457  7410                             je     0x7a6469
007A6459  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
007A645C  2b4e18                           sub    ecx,DWORD PTR [esi+0x18]
007A645F  47                               inc    edi
007A6460  c1f902                           sar    ecx,0x2
007A6463  3bf9                             cmp    edi,ecx
007A6465  72e1                             jb     0x7a6448
007A6467  eb02                             jmp    0x7a646b
007A6469  33db                             xor    ebx,ebx
007A646B  8d45ec                           lea    eax,[ebp-0x14]
007A646E  e8cd7d0b00                       call   0x85e240
007A6473  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A6476  3b45e8                           cmp    eax,DWORD PTR [ebp-0x18]
007A6479  75bb                             jne    0x7a6436
007A647B  8b7df0                           mov    edi,DWORD PTR [ebp-0x10]
007A647E  be01000000                       mov    esi,0x1
007A6483  85db                             test   ebx,ebx
007A6485  0f858d000000                     jne    0x7a6518
007A648B  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
007A6492  d987fc000000                     fld    DWORD PTR [edi+0xfc]
007A6498  d95ddc                           fstp   DWORD PTR [ebp-0x24]
007A649B  d9ee                             fldz
007A649D  d955e0                           fst    DWORD PTR [ebp-0x20]
007A64A0  d95de4                           fstp   DWORD PTR [ebp-0x1c]
007A64A3  7522                             jne    0x7a64c7
007A64A5  0935e879fb00                     or     DWORD PTR ds:0xfb79e8,esi
007A64AB  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
007A64AE  e82d29ffff                       call   0x798de0
007A64B3  68e0d2bc00                       push   0xbcd2e0
007A64B8  e85dbe0e00                       call   0x89231a
007A64BD  83c404                           add    esp,0x4
007A64C0  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007A64C7  8b55dc                           mov    edx,DWORD PTR [ebp-0x24]
007A64CA  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
007A64CD  83ec0c                           sub    esp,0xc
007A64D0  8bc4                             mov    eax,esp
007A64D2  8910                             mov    DWORD PTR [eax],edx
007A64D4  8b55e4                           mov    edx,DWORD PTR [ebp-0x1c]
007A64D7  894804                           mov    DWORD PTR [eax+0x4],ecx
007A64DA  895008                           mov    DWORD PTR [eax+0x8],edx
007A64DD  8b97ec000000                     mov    edx,DWORD PTR [edi+0xec]
007A64E3  8b87f4000000                     mov    eax,DWORD PTR [edi+0xf4]
007A64E9  83ec0c                           sub    esp,0xc
007A64EC  8bcc                             mov    ecx,esp
007A64EE  8911                             mov    DWORD PTR [ecx],edx
007A64F0  8b97f0000000                     mov    edx,DWORD PTR [edi+0xf0]
007A64F6  895104                           mov    DWORD PTR [ecx+0x4],edx
007A64F9  68a876fb00                       push   0xfb76a8
007A64FE  894108                           mov    DWORD PTR [ecx+0x8],eax
007A6501  e87a46ffff                       call   0x79ab80
007A6506  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007A6509  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A6510  59                               pop    ecx
007A6511  5f                               pop    edi
007A6512  5e                               pop    esi
007A6513  5b                               pop    ebx
007A6514  8be5                             mov    esp,ebp
007A6516  5d                               pop    ebp
007A6517  c3                               ret
007A6518  b8ecf5c400                       mov    eax,0xc4f5ec
007A651D  e88e1b0900                       call   0x8380b0
007A6522  8975fc                           mov    DWORD PTR [ebp-0x4],esi
007A6525  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
007A652C  7520                             jne    0x7a654e
007A652E  0935e879fb00                     or     DWORD PTR ds:0xfb79e8,esi
007A6534  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
007A6538  e8a328ffff                       call   0x798de0
007A653D  68e0d2bc00                       push   0xbcd2e0
007A6542  e8d3bd0e00                       call   0x89231a
007A6547  83c404                           add    esp,0x4
007A654A  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
007A654E  e8cd1c0000                       call   0x7a8220
007A6553  8b7df0                           mov    edi,DWORD PTR [ebp-0x10]
007A6556  8b4f1c                           mov    ecx,DWORD PTR [edi+0x1c]
007A6559  8b11                             mov    edx,DWORD PTR [ecx]
007A655B  8b4208                           mov    eax,DWORD PTR [edx+0x8]
007A655E  ffd0                             call   eax
007A6560  8b4770                           mov    eax,DWORD PTR [edi+0x70]
007A6563  8b30                             mov    esi,DWORD PTR [eax]
007A6565  8b5de8                           mov    ebx,DWORD PTR [ebp-0x18]
007A6568  3bf3                             cmp    esi,ebx
007A656A  7452                             je     0x7a65be
007A656C  8d642400                         lea    esp,[esp+0x0]
007A6570  8b4e18                           mov    ecx,DWORD PTR [esi+0x18]
007A6573  8b11                             mov    edx,DWORD PTR [ecx]
007A6575  8b4208                           mov    eax,DWORD PTR [edx+0x8]
007A6578  ffd0                             call   eax
007A657A  807e2100                         cmp    BYTE PTR [esi+0x21],0x0
007A657E  753a                             jne    0x7a65ba
007A6580  8b4608                           mov    eax,DWORD PTR [esi+0x8]
007A6583  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A6587  7516                             jne    0x7a659f
007A6589  8bf0                             mov    esi,eax
007A658B  8b06                             mov    eax,DWORD PTR [esi]
007A658D  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A6591  7527                             jne    0x7a65ba
007A6593  8bf0                             mov    esi,eax
007A6595  8b06                             mov    eax,DWORD PTR [esi]
007A6597  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A659B  74f6                             je     0x7a6593
007A659D  eb1b                             jmp    0x7a65ba
007A659F  8b4604                           mov    eax,DWORD PTR [esi+0x4]
007A65A2  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A65A6  7510                             jne    0x7a65b8
007A65A8  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
007A65AB  750b                             jne    0x7a65b8
007A65AD  8bf0                             mov    esi,eax
007A65AF  8b4004                           mov    eax,DWORD PTR [eax+0x4]
007A65B2  80782100                         cmp    BYTE PTR [eax+0x21],0x0
007A65B6  74f0                             je     0x7a65a8
007A65B8  8bf0                             mov    esi,eax
007A65BA  3bf3                             cmp    esi,ebx
007A65BC  75b2                             jne    0x7a6570
007A65BE  83bf8c00000000                   cmp    DWORD PTR [edi+0x8c],0x0
007A65C5  0f84a0000000                     je     0x7a666b
007A65CB  b8fcf5c400                       mov    eax,0xc4f5fc
007A65D0  e8db1a0900                       call   0x8380b0
007A65D5  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
007A65D9  8b3538a8fb00                     mov    esi,DWORD PTR ds:0xfba838
007A65DF  8b86b8000000                     mov    eax,DWORD PTR [esi+0xb8]
007A65E5  83c70c                           add    edi,0xc
007A65E8  8d4dec                           lea    ecx,[ebp-0x14]
007A65EB  897dec                           mov    DWORD PTR [ebp-0x14],edi
007A65EE  3bc8                             cmp    ecx,eax
007A65F0  7340                             jae    0x7a6632
007A65F2  8b8eb4000000                     mov    ecx,DWORD PTR [esi+0xb4]
007A65F8  8d55ec                           lea    edx,[ebp-0x14]
007A65FB  3bca                             cmp    ecx,edx
007A65FD  7733                             ja     0x7a6632
007A65FF  8bfa                             mov    edi,edx
007A6601  2bf9                             sub    edi,ecx
007A6603  c1ff02                           sar    edi,0x2
007A6606  3b86bc000000                     cmp    eax,DWORD PTR [esi+0xbc]
007A660C  750b                             jne    0x7a6619
007A660E  8d86b4000000                     lea    eax,[esi+0xb4]
007A6614  e81713ffff                       call   0x797930
007A6619  8b86b4000000                     mov    eax,DWORD PTR [esi+0xb4]
007A661F  8d3cb8                           lea    edi,[eax+edi*4]
007A6622  8b86b8000000                     mov    eax,DWORD PTR [esi+0xb8]
007A6628  85c0                             test   eax,eax
007A662A  7425                             je     0x7a6651
007A662C  8b0f                             mov    ecx,DWORD PTR [edi]
007A662E  8908                             mov    DWORD PTR [eax],ecx
007A6630  eb1f                             jmp    0x7a6651
007A6632  3b86bc000000                     cmp    eax,DWORD PTR [esi+0xbc]
007A6638  750b                             jne    0x7a6645
007A663A  8d86b4000000                     lea    eax,[esi+0xb4]
007A6640  e8eb12ffff                       call   0x797930
007A6645  8b86b8000000                     mov    eax,DWORD PTR [esi+0xb8]
007A664B  85c0                             test   eax,eax
007A664D  7402                             je     0x7a6651
007A664F  8938                             mov    DWORD PTR [eax],edi
007A6651  8386b800000004                   add    DWORD PTR [esi+0xb8],0x4
007A6658  e873190900                       call   0x837fd0
007A665D  8b15fc39d600                     mov    edx,DWORD PTR ds:0xd639fc
007A6663  8b4204                           mov    eax,DWORD PTR [edx+0x4]
007A6666  a3fc39d600                       mov    ds:0xd639fc,eax
007A666B  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007A6672  e859190900                       call   0x837fd0
007A6677  8b0dfc39d600                     mov    ecx,DWORD PTR ds:0xd639fc
007A667D  8b5104                           mov    edx,DWORD PTR [ecx+0x4]
007A6680  8b7df0                           mov    edi,DWORD PTR [ebp-0x10]
007A6683  8915fc39d600                     mov    DWORD PTR ds:0xd639fc,edx
007A6689  8b8708010000                     mov    eax,DWORD PTR [edi+0x108]
007A668F  85c0                             test   eax,eax
007A6691  7406                             je     0x7a6699
007A6693  50                               push   eax
007A6694  e8a7780100                       call   0x7bdf40
007A6699  8b9f0c010000                     mov    ebx,DWORD PTR [edi+0x10c]
007A669F  8b33                             mov    esi,DWORD PTR [ebx]
007A66A1  3bf3                             cmp    esi,ebx
007A66A3  740f                             je     0x7a66b4
007A66A5  8b4608                           mov    eax,DWORD PTR [esi+0x8]
007A66A8  50                               push   eax
007A66A9  e892780100                       call   0x7bdf40
007A66AE  8b36                             mov    esi,DWORD PTR [esi]
007A66B0  3bf3                             cmp    esi,ebx
007A66B2  75f1                             jne    0x7a66a5
007A66B4  8b8750010000                     mov    eax,DWORD PTR [edi+0x150]
007A66BA  2b874c010000                     sub    eax,DWORD PTR [edi+0x14c]
007A66C0  33db                             xor    ebx,ebx
007A66C2  c1f803                           sar    eax,0x3
007A66C5  8945e8                           mov    DWORD PTR [ebp-0x18],eax
007A66C8  85c0                             test   eax,eax
007A66CA  744b                             je     0x7a6717
007A66CC  eb05                             jmp    0x7a66d3
007A66CE  8bff                             mov    edi,edi
007A66D0  8b7df0                           mov    edi,DWORD PTR [ebp-0x10]
007A66D3  8b8f4c010000                     mov    ecx,DWORD PTR [edi+0x14c]
007A66D9  8b74d904                         mov    esi,DWORD PTR [ecx+ebx*8+0x4]
007A66DD  8b5660                           mov    edx,DWORD PTR [esi+0x60]
007A66E0  2b565c                           sub    edx,DWORD PTR [esi+0x5c]
007A66E3  33ff                             xor    edi,edi
007A66E5  c1fa02                           sar    edx,0x2
007A66E8  85d2                             test   edx,edx
007A66EA  7426                             je     0x7a6712
007A66EC  8d642400                         lea    esp,[esp+0x0]
007A66F0  8b465c                           mov    eax,DWORD PTR [esi+0x5c]
007A66F3  8b04b8                           mov    eax,DWORD PTR [eax+edi*4]
007A66F6  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
007A66F9  8b11                             mov    edx,DWORD PTR [ecx]
007A66FB  50                               push   eax
007A66FC  8b421c                           mov    eax,DWORD PTR [edx+0x1c]
007A66FF  ffd0                             call   eax
007A6701  8b4e60                           mov    ecx,DWORD PTR [esi+0x60]
007A6704  2b4e5c                           sub    ecx,DWORD PTR [esi+0x5c]
007A6707  47                               inc    edi
007A6708  c1f902                           sar    ecx,0x2
007A670B  3bf9                             cmp    edi,ecx
007A670D  72e1                             jb     0x7a66f0
007A670F  8b45e8                           mov    eax,DWORD PTR [ebp-0x18]
007A6712  43                               inc    ebx
007A6713  3bd8                             cmp    ebx,eax
007A6715  72b9                             jb     0x7a66d0
007A6717  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007A671A  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A6721  59                               pop    ecx
007A6722  5f                               pop    edi
007A6723  5e                               pop    esi
007A6724  5b                               pop    ebx
007A6725  8be5                             mov    esp,ebp
007A6727  5d                               pop    ebp
007A6728  c3                               ret

; doll_self_weak_setup [NEW_STRONG_HOLD_JOIN] 0x4ca460..0x4ca507 exclusive
004CA460  55                               push   ebp
004CA461  8bec                             mov    ebp,esp
004CA463  6aff                             push   0xffffffff
004CA465  6820899000                       push   0x908920
004CA46A  64a100000000                     mov    eax,fs:0x0
004CA470  50                               push   eax
004CA471  51                               push   ecx
004CA472  53                               push   ebx
004CA473  56                               push   esi
004CA474  57                               push   edi
004CA475  a1201fd600                       mov    eax,ds:0xd61f20
004CA47A  33c5                             xor    eax,ebp
004CA47C  50                               push   eax
004CA47D  8d45f4                           lea    eax,[ebp-0xc]
004CA480  64a300000000                     mov    fs:0x0,eax
004CA486  8965f0                           mov    DWORD PTR [ebp-0x10],esp
004CA489  8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
004CA48C  33ff                             xor    edi,edi
004CA48E  6a10                             push   0x10
004CA490  897dfc                           mov    DWORD PTR [ebp-0x4],edi
004CA493  e8d06d3c00                       call   0x891268
004CA498  83c404                           add    esp,0x4
004CA49B  3bc7                             cmp    eax,edi
004CA49D  7416                             je     0x4ca4b5
004CA49F  b901000000                       mov    ecx,0x1
004CA4A4  894804                           mov    DWORD PTR [eax+0x4],ecx
004CA4A7  894808                           mov    DWORD PTR [eax+0x8],ecx
004CA4AA  c7000c76c000                     mov    DWORD PTR [eax],0xc0760c
004CA4B0  89580c                           mov    DWORD PTR [eax+0xc],ebx
004CA4B3  8bf8                             mov    edi,eax
004CA4B5  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
004CA4B8  57                               push   edi
004CA4B9  53                               push   ebx
004CA4BA  e8018d2d00                       call   0x7a31c0
004CA4BF  85db                             test   ebx,ebx
004CA4C1  7430                             je     0x4ca4f3
004CA4C3  85ff                             test   edi,edi
004CA4C5  740c                             je     0x4ca4d3
004CA4C7  8d4708                           lea    eax,[edi+0x8]
004CA4CA  b901000000                       mov    ecx,0x1
004CA4CF  f00fc108                         lock xadd DWORD PTR [eax],ecx
004CA4D3  8b4b14                           mov    ecx,DWORD PTR [ebx+0x14]
004CA4D6  85c9                             test   ecx,ecx
004CA4D8  7413                             je     0x4ca4ed
004CA4DA  8d5108                           lea    edx,[ecx+0x8]
004CA4DD  83c8ff                           or     eax,0xffffffff
004CA4E0  f00fc102                         lock xadd DWORD PTR [edx],eax
004CA4E4  7507                             jne    0x4ca4ed
004CA4E6  8b11                             mov    edx,DWORD PTR [ecx]
004CA4E8  8b4204                           mov    eax,DWORD PTR [edx+0x4]
004CA4EB  ffd0                             call   eax
004CA4ED  897b14                           mov    DWORD PTR [ebx+0x14],edi
004CA4F0  895b10                           mov    DWORD PTR [ebx+0x10],ebx
004CA4F3  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004CA4F6  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004CA4FD  59                               pop    ecx
004CA4FE  5f                               pop    edi
004CA4FF  5e                               pop    esi
004CA500  5b                               pop    ebx
004CA501  8be5                             mov    esp,ebp
004CA503  5d                               pop    ebp
004CA504  c20800                           ret    0x8

; lock_doll_weak [NEW_STRONG_HOLD_JOIN] 0x7a9d90..0x7a9de6 exclusive
007A9D90  55                               push   ebp
007A9D91  8bec                             mov    ebp,esp
007A9D93  83ec10                           sub    esp,0x10
007A9D96  53                               push   ebx
007A9D97  8b18                             mov    ebx,DWORD PTR [eax]
007A9D99  56                               push   esi
007A9D9A  8bf1                             mov    esi,ecx
007A9D9C  33c9                             xor    ecx,ecx
007A9D9E  57                               push   edi
007A9D9F  8b7804                           mov    edi,DWORD PTR [eax+0x4]
007A9DA2  894dfc                           mov    DWORD PTR [ebp-0x4],ecx
007A9DA5  890e                             mov    DWORD PTR [esi],ecx
007A9DA7  894e04                           mov    DWORD PTR [esi+0x4],ecx
007A9DAA  3bf9                             cmp    edi,ecx
007A9DAC  741b                             je     0x7a9dc9
007A9DAE  8bd7                             mov    edx,edi
007A9DB0  e89b24cdff                       call   0x47c250
007A9DB5  84c0                             test   al,al
007A9DB7  7410                             je     0x7a9dc9
007A9DB9  57                               push   edi
007A9DBA  53                               push   ebx
007A9DBB  e80094ffff                       call   0x7a31c0
007A9DC0  5f                               pop    edi
007A9DC1  8bc6                             mov    eax,esi
007A9DC3  5e                               pop    esi
007A9DC4  5b                               pop    ebx
007A9DC5  8be5                             mov    esp,ebp
007A9DC7  5d                               pop    ebp
007A9DC8  c3                               ret
007A9DC9  8d4df0                           lea    ecx,[ebp-0x10]
007A9DCC  e83f720e00                       call   0x891010
007A9DD1  68ac58c800                       push   0xc858ac
007A9DD6  8d45f0                           lea    eax,[ebp-0x10]
007A9DD9  50                               push   eax
007A9DDA  c745f00031c000                   mov    DWORD PTR [ebp-0x10],0xc03100
007A9DE1  e80a2c0f00                       call   0x89c9f0

; retain_nonzero_shared_count [NEW_STRONG_HOLD_JOIN] 0x47c250..0x47c281 exclusive
0047C250  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0047C253  56                               push   esi
0047C254  57                               push   edi
0047C255  85c9                             test   ecx,ecx
0047C257  741e                             je     0x47c277
0047C259  8da42400000000                   lea    esp,[esp+0x0]
0047C260  8d7101                           lea    esi,[ecx+0x1]
0047C263  8d7a04                           lea    edi,[edx+0x4]
0047C266  8bc1                             mov    eax,ecx
0047C268  f00fb137                         lock cmpxchg DWORD PTR [edi],esi
0047C26C  3bc1                             cmp    eax,ecx
0047C26E  740c                             je     0x47c27c
0047C270  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0047C273  85c9                             test   ecx,ecx
0047C275  75e9                             jne    0x47c260
0047C277  5f                               pop    edi
0047C278  32c0                             xor    al,al
0047C27A  5e                               pop    esi
0047C27B  c3                               ret
0047C27C  5f                               pop    edi
0047C27D  b001                             mov    al,0x1
0047C27F  5e                               pop    esi
0047C280  c3                               ret

; move_shared_pair [NEW_STRONG_HOLD_JOIN] 0x4e0f60..0x4e0fbc exclusive
004E0F60  55                               push   ebp
004E0F61  8bec                             mov    ebp,esp
004E0F63  83ec0c                           sub    esp,0xc
004E0F66  56                               push   esi
004E0F67  8d75f8                           lea    esi,[ebp-0x8]
004E0F6A  33d2                             xor    edx,edx
004E0F6C  33c9                             xor    ecx,ecx
004E0F6E  3bf0                             cmp    esi,eax
004E0F70  740e                             je     0x4e0f80
004E0F72  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
004E0F75  895004                           mov    DWORD PTR [eax+0x4],edx
004E0F78  8b10                             mov    edx,DWORD PTR [eax]
004E0F7A  c70000000000                     mov    DWORD PTR [eax],0x0
004E0F80  8b7704                           mov    esi,DWORD PTR [edi+0x4]
004E0F83  894f04                           mov    DWORD PTR [edi+0x4],ecx
004E0F86  8917                             mov    DWORD PTR [edi],edx
004E0F88  85f6                             test   esi,esi
004E0F8A  7429                             je     0x4e0fb5
004E0F8C  8d4604                           lea    eax,[esi+0x4]
004E0F8F  83c9ff                           or     ecx,0xffffffff
004E0F92  f00fc108                         lock xadd DWORD PTR [eax],ecx
004E0F96  751d                             jne    0x4e0fb5
004E0F98  8b16                             mov    edx,DWORD PTR [esi]
004E0F9A  8b02                             mov    eax,DWORD PTR [edx]
004E0F9C  8bce                             mov    ecx,esi
004E0F9E  ffd0                             call   eax
004E0FA0  8d4e08                           lea    ecx,[esi+0x8]
004E0FA3  83caff                           or     edx,0xffffffff
004E0FA6  f00fc111                         lock xadd DWORD PTR [ecx],edx
004E0FAA  7509                             jne    0x4e0fb5
004E0FAC  8b06                             mov    eax,DWORD PTR [esi]
004E0FAE  8b5004                           mov    edx,DWORD PTR [eax+0x4]
004E0FB1  8bce                             mov    ecx,esi
004E0FB3  ffd2                             call   edx
004E0FB5  8bc7                             mov    eax,edi
004E0FB7  5e                               pop    esi
004E0FB8  8be5                             mov    esp,ebp
004E0FBA  5d                               pop    ebp
004E0FBB  c3                               ret

; retain_request_for_result [NEW_STRONG_HOLD_JOIN] 0x7a0da0..0x7a0e11 exclusive
007A0DA0  55                               push   ebp
007A0DA1  8bec                             mov    ebp,esp
007A0DA3  83ec08                           sub    esp,0x8
007A0DA6  53                               push   ebx
007A0DA7  8b18                             mov    ebx,DWORD PTR [eax]
007A0DA9  33c9                             xor    ecx,ecx
007A0DAB  56                               push   esi
007A0DAC  8b7004                           mov    esi,DWORD PTR [eax+0x4]
007A0DAF  894df8                           mov    DWORD PTR [ebp-0x8],ecx
007A0DB2  894dfc                           mov    DWORD PTR [ebp-0x4],ecx
007A0DB5  3bf1                             cmp    esi,ecx
007A0DB7  7415                             je     0x7a0dce
007A0DB9  8bd6                             mov    edx,esi
007A0DBB  e890b4cdff                       call   0x47c250
007A0DC0  84c0                             test   al,al
007A0DC2  740a                             je     0x7a0dce
007A0DC4  56                               push   esi
007A0DC5  53                               push   ebx
007A0DC6  8d75f8                           lea    esi,[ebp-0x8]
007A0DC9  e8f2230000                       call   0x7a31c0
007A0DCE  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
007A0DD1  8b7704                           mov    esi,DWORD PTR [edi+0x4]
007A0DD4  894704                           mov    DWORD PTR [edi+0x4],eax
007A0DD7  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
007A0DDA  8907                             mov    DWORD PTR [edi],eax
007A0DDC  85f6                             test   esi,esi
007A0DDE  7429                             je     0x7a0e09
007A0DE0  8d4e04                           lea    ecx,[esi+0x4]
007A0DE3  83caff                           or     edx,0xffffffff
007A0DE6  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A0DEA  751d                             jne    0x7a0e09
007A0DEC  8b06                             mov    eax,DWORD PTR [esi]
007A0DEE  8b10                             mov    edx,DWORD PTR [eax]
007A0DF0  8bce                             mov    ecx,esi
007A0DF2  ffd2                             call   edx
007A0DF4  8d4608                           lea    eax,[esi+0x8]
007A0DF7  83c9ff                           or     ecx,0xffffffff
007A0DFA  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A0DFE  7509                             jne    0x7a0e09
007A0E00  8b16                             mov    edx,DWORD PTR [esi]
007A0E02  8b4204                           mov    eax,DWORD PTR [edx+0x4]
007A0E05  8bce                             mov    ecx,esi
007A0E07  ffd0                             call   eax
007A0E09  5e                               pop    esi
007A0E0A  8bc7                             mov    eax,edi
007A0E0C  5b                               pop    ebx
007A0E0D  8be5                             mov    esp,ebp
007A0E0F  5d                               pop    ebp
007A0E10  c3                               ret

; assign_owned_pair [NEW_STRONG_HOLD_JOIN] 0x7a31c0..0x7a3222 exclusive
007A31C0  55                               push   ebp
007A31C1  8bec                             mov    ebp,esp
007A31C3  53                               push   ebx
007A31C4  8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
007A31C7  57                               push   edi
007A31C8  8b7e04                           mov    edi,DWORD PTR [esi+0x4]
007A31CB  85ff                             test   edi,edi
007A31CD  7429                             je     0x7a31f8
007A31CF  8d4704                           lea    eax,[edi+0x4]
007A31D2  83c9ff                           or     ecx,0xffffffff
007A31D5  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A31D9  7539                             jne    0x7a3214
007A31DB  8b17                             mov    edx,DWORD PTR [edi]
007A31DD  8b02                             mov    eax,DWORD PTR [edx]
007A31DF  8bcf                             mov    ecx,edi
007A31E1  ffd0                             call   eax
007A31E3  8d4f08                           lea    ecx,[edi+0x8]
007A31E6  83caff                           or     edx,0xffffffff
007A31E9  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A31ED  7517                             jne    0x7a3206
007A31EF  8b07                             mov    eax,DWORD PTR [edi]
007A31F1  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A31F4  8bcf                             mov    ecx,edi
007A31F6  ffd2                             call   edx
007A31F8  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A31FB  5f                               pop    edi
007A31FC  895e04                           mov    DWORD PTR [esi+0x4],ebx
007A31FF  8906                             mov    DWORD PTR [esi],eax
007A3201  5b                               pop    ebx
007A3202  5d                               pop    ebp
007A3203  c20800                           ret    0x8
007A3206  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007A3209  5f                               pop    edi
007A320A  895e04                           mov    DWORD PTR [esi+0x4],ebx
007A320D  890e                             mov    DWORD PTR [esi],ecx
007A320F  5b                               pop    ebx
007A3210  5d                               pop    ebp
007A3211  c20800                           ret    0x8
007A3214  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
007A3217  5f                               pop    edi
007A3218  895e04                           mov    DWORD PTR [esi+0x4],ebx
007A321B  8916                             mov    DWORD PTR [esi],edx
007A321D  5b                               pop    ebx
007A321E  5d                               pop    ebp
007A321F  c20800                           ret    0x8

; request_shared_wrap [NEW_STRONG_HOLD_JOIN] 0x7aa810..0x7aa887 exclusive
007AA810  55                               push   ebp
007AA811  8bec                             mov    ebp,esp
007AA813  6aff                             push   0xffffffff
007AA815  6810a19000                       push   0x90a110
007AA81A  64a100000000                     mov    eax,fs:0x0
007AA820  50                               push   eax
007AA821  51                               push   ecx
007AA822  53                               push   ebx
007AA823  56                               push   esi
007AA824  57                               push   edi
007AA825  a1201fd600                       mov    eax,ds:0xd61f20
007AA82A  33c5                             xor    eax,ebp
007AA82C  50                               push   eax
007AA82D  8d45f4                           lea    eax,[ebp-0xc]
007AA830  64a300000000                     mov    fs:0x0,eax
007AA836  8965f0                           mov    DWORD PTR [ebp-0x10],esp
007AA839  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
007AA83C  6a10                             push   0x10
007AA83E  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
007AA845  e81e6a0e00                       call   0x891268
007AA84A  83c404                           add    esp,0x4
007AA84D  85c0                             test   eax,eax
007AA84F  7416                             je     0x7aa867
007AA851  b901000000                       mov    ecx,0x1
007AA856  894804                           mov    DWORD PTR [eax+0x4],ecx
007AA859  894808                           mov    DWORD PTR [eax+0x8],ecx
007AA85C  c700e4f6c400                     mov    DWORD PTR [eax],0xc4f6e4
007AA862  89700c                           mov    DWORD PTR [eax+0xc],esi
007AA865  eb02                             jmp    0x7aa869
007AA867  33c0                             xor    eax,eax
007AA869  50                               push   eax
007AA86A  56                               push   esi
007AA86B  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
007AA86E  e84d89ffff                       call   0x7a31c0
007AA873  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007AA876  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007AA87D  59                               pop    ecx
007AA87E  5f                               pop    edi
007AA87F  5e                               pop    esi
007AA880  5b                               pop    ebx
007AA881  8be5                             mov    esp,ebp
007AA883  5d                               pop    ebp
007AA884  c20800                           ret    0x8

; request_destructor [NEW_STRONG_RELEASE_JOIN] 0x7aa9a0..0x7aaa3b exclusive
007AA9A0  55                               push   ebp
007AA9A1  8bec                             mov    ebp,esp
007AA9A3  6aff                             push   0xffffffff
007AA9A5  68b7a09000                       push   0x90a0b7
007AA9AA  64a100000000                     mov    eax,fs:0x0
007AA9B0  50                               push   eax
007AA9B1  56                               push   esi
007AA9B2  57                               push   edi
007AA9B3  a1201fd600                       mov    eax,ds:0xd61f20
007AA9B8  33c5                             xor    eax,ebp
007AA9BA  50                               push   eax
007AA9BB  8d45f4                           lea    eax,[ebp-0xc]
007AA9BE  64a300000000                     mov    fs:0x0,eax
007AA9C4  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
007AA9C7  c745fc02000000                   mov    DWORD PTR [ebp-0x4],0x2
007AA9CE  8b776c                           mov    esi,DWORD PTR [edi+0x6c]
007AA9D1  85f6                             test   esi,esi
007AA9D3  7429                             je     0x7aa9fe
007AA9D5  8d4604                           lea    eax,[esi+0x4]
007AA9D8  83c9ff                           or     ecx,0xffffffff
007AA9DB  f00fc108                         lock xadd DWORD PTR [eax],ecx
007AA9DF  751d                             jne    0x7aa9fe
007AA9E1  8b16                             mov    edx,DWORD PTR [esi]
007AA9E3  8b02                             mov    eax,DWORD PTR [edx]
007AA9E5  8bce                             mov    ecx,esi
007AA9E7  ffd0                             call   eax
007AA9E9  8d4e08                           lea    ecx,[esi+0x8]
007AA9EC  83caff                           or     edx,0xffffffff
007AA9EF  f00fc111                         lock xadd DWORD PTR [ecx],edx
007AA9F3  7509                             jne    0x7aa9fe
007AA9F5  8b06                             mov    eax,DWORD PTR [esi]
007AA9F7  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007AA9FA  8bce                             mov    ecx,esi
007AA9FC  ffd2                             call   edx
007AA9FE  8d4748                           lea    eax,[edi+0x48]
007AAA01  50                               push   eax
007AAA02  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
007AAA06  e815a7ffff                       call   0x7a5120
007AAA0B  8d4f28                           lea    ecx,[edi+0x28]
007AAA0E  51                               push   ecx
007AAA0F  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
007AAA13  e808a7ffff                       call   0x7a5120
007AAA18  83c708                           add    edi,0x8
007AAA1B  57                               push   edi
007AAA1C  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007AAA23  e8f8a6ffff                       call   0x7a5120
007AAA28  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007AAA2B  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007AAA32  59                               pop    ecx
007AAA33  5f                               pop    edi
007AAA34  5e                               pop    esi
007AAA35  8be5                             mov    esp,ebp
007AAA37  5d                               pop    ebp
007AAA38  c20400                           ret    0x4

; request_control_destroy [NEW_STRONG_RELEASE_JOIN] 0x7aaa50..0x7aaa69 exclusive
007AAA50  56                               push   esi
007AAA51  8b710c                           mov    esi,DWORD PTR [ecx+0xc]
007AAA54  85f6                             test   esi,esi
007AAA56  740f                             je     0x7aaa67
007AAA58  56                               push   esi
007AAA59  e842ffffff                       call   0x7aa9a0
007AAA5E  56                               push   esi
007AAA5F  e8a8670e00                       call   0x89120c
007AAA64  83c404                           add    esp,0x4
007AAA67  5e                               pop    esi
007AAA68  c3                               ret

; doll_control_destroy [NEW_STRONG_RELEASE_JOIN] 0x4ca660..0x4ca670 exclusive
004CA660  8b490c                           mov    ecx,DWORD PTR [ecx+0xc]
004CA663  85c9                             test   ecx,ecx
004CA665  7408                             je     0x4ca66f
004CA667  8b01                             mov    eax,DWORD PTR [ecx]
004CA669  8b10                             mov    edx,DWORD PTR [eax]
004CA66B  6a01                             push   0x1
004CA66D  ffd2                             call   edx
004CA66F  c3                               ret

; doll_scalar_delete [NEW_STRONG_RELEASE_JOIN] 0x7a4ff0..0x7a5012 exclusive
007A4FF0  55                               push   ebp
007A4FF1  8bec                             mov    ebp,esp
007A4FF3  56                               push   esi
007A4FF4  8bf1                             mov    esi,ecx
007A4FF6  56                               push   esi
007A4FF7  e8c4010000                       call   0x7a51c0
007A4FFC  f6450801                         test   BYTE PTR [ebp+0x8],0x1
007A5000  7409                             je     0x7a500b
007A5002  56                               push   esi
007A5003  e804c20e00                       call   0x89120c
007A5008  83c404                           add    esp,0x4
007A500B  8bc6                             mov    eax,esi
007A500D  5e                               pop    esi
007A500E  5d                               pop    ebp
007A500F  c20400                           ret    0x4

; level_replace_worker [REUSED_SHARED_COUNTER_CONTEXT] 0x7a03b0..0x7a0a85 exclusive
007A03B0  55                               push   ebp
007A03B1  8bec                             mov    ebp,esp
007A03B3  6aff                             push   0xffffffff
007A03B5  681a8e9300                       push   0x938e1a
007A03BA  64a100000000                     mov    eax,fs:0x0
007A03C0  50                               push   eax
007A03C1  83ec68                           sub    esp,0x68
007A03C4  53                               push   ebx
007A03C5  56                               push   esi
007A03C6  57                               push   edi
007A03C7  a1201fd600                       mov    eax,ds:0xd61f20
007A03CC  33c5                             xor    eax,ebp
007A03CE  50                               push   eax
007A03CF  8d45f4                           lea    eax,[ebp-0xc]
007A03D2  64a300000000                     mov    fs:0x0,eax
007A03D8  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A03DB  33f6                             xor    esi,esi
007A03DD  8975fc                           mov    DWORD PTR [ebp-0x4],esi
007A03E0  8975e8                           mov    DWORD PTR [ebp-0x18],esi
007A03E3  397048                           cmp    DWORD PTR [eax+0x48],esi
007A03E6  7403                             je     0x7a03eb
007A03E8  8975e8                           mov    DWORD PTR [ebp-0x18],esi
007A03EB  397050                           cmp    DWORD PTR [eax+0x50],esi
007A03EE  7407                             je     0x7a03f7
007A03F0  c745e801000000                   mov    DWORD PTR [ebp-0x18],0x1
007A03F7  397058                           cmp    DWORD PTR [eax+0x58],esi
007A03FA  7407                             je     0x7a0403
007A03FC  c745e802000000                   mov    DWORD PTR [ebp-0x18],0x2
007A0403  8b4060                           mov    eax,DWORD PTR [eax+0x60]
007A0406  3bc6                             cmp    eax,esi
007A0408  7407                             je     0x7a0411
007A040A  c745e803000000                   mov    DWORD PTR [ebp-0x18],0x3
007A0411  6a14                             push   0x14
007A0413  897594                           mov    DWORD PTR [ebp-0x6c],esi
007A0416  e84d0e0f00                       call   0x891268
007A041B  83c404                           add    esp,0x4
007A041E  3bc6                             cmp    eax,esi
007A0420  0f843b060000                     je     0x7a0a61
007A0426  894590                           mov    DWORD PTR [ebp-0x70],eax
007A0429  8900                             mov    DWORD PTR [eax],eax
007A042B  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A042E  894004                           mov    DWORD PTR [eax+0x4],eax
007A0431  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A0434  894008                           mov    DWORD PTR [eax+0x8],eax
007A0437  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A043A  c6401001                         mov    BYTE PTR [eax+0x10],0x1
007A043E  8b4d90                           mov    ecx,DWORD PTR [ebp-0x70]
007A0441  c6411101                         mov    BYTE PTR [ecx+0x11],0x1
007A0445  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
007A0449  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A044C  807f0800                         cmp    BYTE PTR [edi+0x8],0x0
007A0450  0f8474010000                     je     0x7a05ca
007A0456  8b7f04                           mov    edi,DWORD PTR [edi+0x4]
007A0459  81ffff000000                     cmp    edi,0xff
007A045F  7508                             jne    0x7a0469
007A0461  8b55e8                           mov    edx,DWORD PTR [ebp-0x18]
007A0464  8955e0                           mov    DWORD PTR [ebp-0x20],edx
007A0467  eb03                             jmp    0x7a046c
007A0469  897de0                           mov    DWORD PTR [ebp-0x20],edi
007A046C  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A046F  83c048                           add    eax,0x48
007A0472  c745e400000000                   mov    DWORD PTR [ebp-0x1c],0x0
007A0479  8945ec                           mov    DWORD PTR [ebp-0x14],eax
007A047C  8d642400                         lea    esp,[esp+0x0]
007A0480  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A0483  8b00                             mov    eax,DWORD PTR [eax]
007A0485  85c0                             test   eax,eax
007A0487  0f8426010000                     je     0x7a05b3
007A048D  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
007A0490  394de4                           cmp    DWORD PTR [ebp-0x1c],ecx
007A0493  0f821a010000                     jb     0x7a05b3
007A0499  8b5010                           mov    edx,DWORD PTR [eax+0x10]
007A049C  2b500c                           sub    edx,DWORD PTR [eax+0xc]
007A049F  33db                             xor    ebx,ebx
007A04A1  c1fa02                           sar    edx,0x2
007A04A4  85d2                             test   edx,edx
007A04A6  0f84b6000000                     je     0x7a0562
007A04AC  8d642400                         lea    esp,[esp+0x0]
007A04B0  8b400c                           mov    eax,DWORD PTR [eax+0xc]
007A04B3  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007A04B6  8b4904                           mov    ecx,DWORD PTR [ecx+0x4]
007A04B9  8d3c9d00000000                   lea    edi,[ebx*4+0x0]
007A04C0  8b3407                           mov    esi,DWORD PTR [edi+eax*1]
007A04C3  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A04C6  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A04CA  8bd1                             mov    edx,ecx
007A04CC  7516                             jne    0x7a04e4
007A04CE  8bff                             mov    edi,edi
007A04D0  39700c                           cmp    DWORD PTR [eax+0xc],esi
007A04D3  7305                             jae    0x7a04da
007A04D5  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A04D8  eb04                             jmp    0x7a04de
007A04DA  8bd0                             mov    edx,eax
007A04DC  8b00                             mov    eax,DWORD PTR [eax]
007A04DE  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A04E2  74ec                             je     0x7a04d0
007A04E4  8955dc                           mov    DWORD PTR [ebp-0x24],edx
007A04E7  3bd1                             cmp    edx,ecx
007A04E9  740a                             je     0x7a04f5
007A04EB  3b720c                           cmp    esi,DWORD PTR [edx+0xc]
007A04EE  7205                             jb     0x7a04f5
007A04F0  8d45dc                           lea    eax,[ebp-0x24]
007A04F3  eb06                             jmp    0x7a04fb
007A04F5  894dd8                           mov    DWORD PTR [ebp-0x28],ecx
007A04F8  8d45d8                           lea    eax,[ebp-0x28]
007A04FB  8b00                             mov    eax,DWORD PTR [eax]
007A04FD  3bc1                             cmp    eax,ecx
007A04FF  742b                             je     0x7a052c
007A0501  8b4010                           mov    eax,DWORD PTR [eax+0x10]
007A0504  8b7054                           mov    esi,DWORD PTR [eax+0x54]
007A0507  85f6                             test   esi,esi
007A0509  7421                             je     0x7a052c
007A050B  837e5010                         cmp    DWORD PTR [esi+0x50],0x10
007A050F  8d463c                           lea    eax,[esi+0x3c]
007A0512  7202                             jb     0x7a0516
007A0514  8b00                             mov    eax,DWORD PTR [eax]
007A0516  8b565c                           mov    edx,DWORD PTR [esi+0x5c]
007A0519  4a                               dec    edx
007A051A  52                               push   edx
007A051B  50                               push   eax
007A051C  6834fec400                       push   0xc4fe34
007A0521  e8972b0f00                       call   0x8930bd
007A0526  83c40c                           add    esp,0xc
007A0529  ff4e5c                           dec    DWORD PTR [esi+0x5c]
007A052C  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A052F  8b00                             mov    eax,DWORD PTR [eax]
007A0531  8b400c                           mov    eax,DWORD PTR [eax+0xc]
007A0534  03c7                             add    eax,edi
007A0536  50                               push   eax
007A0537  8d758c                           lea    esi,[ebp-0x74]
007A053A  e801d9f1ff                       call   0x6bde40
007A053F  8bce                             mov    ecx,esi
007A0541  50                               push   eax
007A0542  51                               push   ecx
007A0543  8d75b0                           lea    esi,[ebp-0x50]
007A0546  e885b6caff                       call   0x44bbd0
007A054B  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
007A054E  8b02                             mov    eax,DWORD PTR [edx]
007A0550  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
007A0553  2b480c                           sub    ecx,DWORD PTR [eax+0xc]
007A0556  43                               inc    ebx
007A0557  c1f902                           sar    ecx,0x2
007A055A  3bd9                             cmp    ebx,ecx
007A055C  0f824effffff                     jb     0x7a04b0
007A0562  8b55e4                           mov    edx,DWORD PTR [ebp-0x1c]
007A0565  52                               push   edx
007A0566  68f0f4c400                       push   0xc4f4f0
007A056B  e84d2b0f00                       call   0x8930bd
007A0570  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A0573  8b7004                           mov    esi,DWORD PTR [eax+0x4]
007A0576  83c408                           add    esp,0x8
007A0579  c7400400000000                   mov    DWORD PTR [eax+0x4],0x0
007A0580  c70000000000                     mov    DWORD PTR [eax],0x0
007A0586  85f6                             test   esi,esi
007A0588  7429                             je     0x7a05b3
007A058A  8d4604                           lea    eax,[esi+0x4]
007A058D  83c9ff                           or     ecx,0xffffffff
007A0590  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A0594  751d                             jne    0x7a05b3
007A0596  8b16                             mov    edx,DWORD PTR [esi]
007A0598  8b02                             mov    eax,DWORD PTR [edx]
007A059A  8bce                             mov    ecx,esi
007A059C  ffd0                             call   eax
007A059E  8d4e08                           lea    ecx,[esi+0x8]
007A05A1  83caff                           or     edx,0xffffffff
007A05A4  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A05A8  7509                             jne    0x7a05b3
007A05AA  8b06                             mov    eax,DWORD PTR [esi]
007A05AC  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A05AF  8bce                             mov    ecx,esi
007A05B1  ffd2                             call   edx
007A05B3  8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
007A05B6  8345ec08                         add    DWORD PTR [ebp-0x14],0x8
007A05BA  40                               inc    eax
007A05BB  8945e4                           mov    DWORD PTR [ebp-0x1c],eax
007A05BE  83f804                           cmp    eax,0x4
007A05C1  0f82b9feffff                     jb     0x7a0480
007A05C7  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A05CA  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A05CD  83784800                         cmp    DWORD PTR [eax+0x48],0x0
007A05D1  7404                             je     0x7a05d7
007A05D3  33c9                             xor    ecx,ecx
007A05D5  eb03                             jmp    0x7a05da
007A05D7  8b4de8                           mov    ecx,DWORD PTR [ebp-0x18]
007A05DA  83785000                         cmp    DWORD PTR [eax+0x50],0x0
007A05DE  7405                             je     0x7a05e5
007A05E0  b901000000                       mov    ecx,0x1
007A05E5  83785800                         cmp    DWORD PTR [eax+0x58],0x0
007A05E9  7405                             je     0x7a05f0
007A05EB  b902000000                       mov    ecx,0x2
007A05F0  83786000                         cmp    DWORD PTR [eax+0x60],0x0
007A05F4  7405                             je     0x7a05fb
007A05F6  b903000000                       mov    ecx,0x3
007A05FB  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A05FE  894dec                           mov    DWORD PTR [ebp-0x14],ecx
007A0601  3dff000000                       cmp    eax,0xff
007A0606  7403                             je     0x7a060b
007A0608  8945ec                           mov    DWORD PTR [ebp-0x14],eax
007A060B  8b4710                           mov    eax,DWORD PTR [edi+0x10]
007A060E  2b470c                           sub    eax,DWORD PTR [edi+0xc]
007A0611  33db                             xor    ebx,ebx
007A0613  c1f802                           sar    eax,0x2
007A0616  895de0                           mov    DWORD PTR [ebp-0x20],ebx
007A0619  85c0                             test   eax,eax
007A061B  0f841f010000                     je     0x7a0740
007A0621  8b4f0c                           mov    ecx,DWORD PTR [edi+0xc]
007A0624  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
007A0627  8d3499                           lea    esi,[ecx+ebx*4]
007A062A  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
007A062D  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A0630  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A0634  8bd1                             mov    edx,ecx
007A0636  751f                             jne    0x7a0657
007A0638  8b1e                             mov    ebx,DWORD PTR [esi]
007A063A  8d9b00000000                     lea    ebx,[ebx+0x0]
007A0640  39580c                           cmp    DWORD PTR [eax+0xc],ebx
007A0643  7305                             jae    0x7a064a
007A0645  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A0648  eb04                             jmp    0x7a064e
007A064A  8bd0                             mov    edx,eax
007A064C  8b00                             mov    eax,DWORD PTR [eax]
007A064E  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A0652  74ec                             je     0x7a0640
007A0654  8b5de0                           mov    ebx,DWORD PTR [ebp-0x20]
007A0657  8955e0                           mov    DWORD PTR [ebp-0x20],edx
007A065A  3bd1                             cmp    edx,ecx
007A065C  740c                             je     0x7a066a
007A065E  8b06                             mov    eax,DWORD PTR [esi]
007A0660  3b420c                           cmp    eax,DWORD PTR [edx+0xc]
007A0663  7205                             jb     0x7a066a
007A0665  8d45e0                           lea    eax,[ebp-0x20]
007A0668  eb06                             jmp    0x7a0670
007A066A  894de4                           mov    DWORD PTR [ebp-0x1c],ecx
007A066D  8d45e4                           lea    eax,[ebp-0x1c]
007A0670  8b00                             mov    eax,DWORD PTR [eax]
007A0672  3bc1                             cmp    eax,ecx
007A0674  0f84b1000000                     je     0x7a072b
007A067A  8b4010                           mov    eax,DWORD PTR [eax+0x10]
007A067D  83785400                         cmp    DWORD PTR [eax+0x54],0x0
007A0681  750e                             jne    0x7a0691
007A0683  8b0e                             mov    ecx,DWORD PTR [esi]
007A0685  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A0688  51                               push   ecx
007A0689  e8e2ceffff                       call   0x79d570
007A068E  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A0691  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A0694  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
007A0697  8b570c                           mov    edx,DWORD PTR [edi+0xc]
007A069A  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A069D  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A06A1  8b349a                           mov    esi,DWORD PTR [edx+ebx*4]
007A06A4  8bd1                             mov    edx,ecx
007A06A6  7514                             jne    0x7a06bc
007A06A8  39700c                           cmp    DWORD PTR [eax+0xc],esi
007A06AB  7305                             jae    0x7a06b2
007A06AD  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A06B0  eb04                             jmp    0x7a06b6
007A06B2  8bd0                             mov    edx,eax
007A06B4  8b00                             mov    eax,DWORD PTR [eax]
007A06B6  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A06BA  74ec                             je     0x7a06a8
007A06BC  8955e8                           mov    DWORD PTR [ebp-0x18],edx
007A06BF  3bd1                             cmp    edx,ecx
007A06C1  740a                             je     0x7a06cd
007A06C3  3b720c                           cmp    esi,DWORD PTR [edx+0xc]
007A06C6  7205                             jb     0x7a06cd
007A06C8  8d45e8                           lea    eax,[ebp-0x18]
007A06CB  eb06                             jmp    0x7a06d3
007A06CD  894dd4                           mov    DWORD PTR [ebp-0x2c],ecx
007A06D0  8d45d4                           lea    eax,[ebp-0x2c]
007A06D3  8b00                             mov    eax,DWORD PTR [eax]
007A06D5  3bc1                             cmp    eax,ecx
007A06D7  742e                             je     0x7a0707
007A06D9  8b4010                           mov    eax,DWORD PTR [eax+0x10]
007A06DC  8b7054                           mov    esi,DWORD PTR [eax+0x54]
007A06DF  85f6                             test   esi,esi
007A06E1  7424                             je     0x7a0707
007A06E3  837e5010                         cmp    DWORD PTR [esi+0x50],0x10
007A06E7  8d463c                           lea    eax,[esi+0x3c]
007A06EA  7202                             jb     0x7a06ee
007A06EC  8b00                             mov    eax,DWORD PTR [eax]
007A06EE  8b4e5c                           mov    ecx,DWORD PTR [esi+0x5c]
007A06F1  41                               inc    ecx
007A06F2  51                               push   ecx
007A06F3  50                               push   eax
007A06F4  6824fec400                       push   0xc4fe24
007A06F9  e8bf290f00                       call   0x8930bd
007A06FE  83c40c                           add    esp,0xc
007A0701  ff465c                           inc    DWORD PTR [esi+0x5c]
007A0704  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A0707  8b470c                           mov    eax,DWORD PTR [edi+0xc]
007A070A  8d0c9d00000000                   lea    ecx,[ebx*4+0x0]
007A0711  03c1                             add    eax,ecx
007A0713  50                               push   eax
007A0714  8d758c                           lea    esi,[ebp-0x74]
007A0717  e824d7f1ff                       call   0x6bde40
007A071C  8bd6                             mov    edx,esi
007A071E  50                               push   eax
007A071F  52                               push   edx
007A0720  8d75a8                           lea    esi,[ebp-0x58]
007A0723  e8a8b4caff                       call   0x44bbd0
007A0728  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A072B  8b4710                           mov    eax,DWORD PTR [edi+0x10]
007A072E  2b470c                           sub    eax,DWORD PTR [edi+0xc]
007A0731  43                               inc    ebx
007A0732  c1f802                           sar    eax,0x2
007A0735  895de0                           mov    DWORD PTR [ebp-0x20],ebx
007A0738  3bd8                             cmp    ebx,eax
007A073A  0f82e1feffff                     jb     0x7a0621
007A0740  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007A0743  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
007A0746  837cd14800                       cmp    DWORD PTR [ecx+edx*8+0x48],0x0
007A074B  0f8449010000                     je     0x7a089a
007A0751  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
007A0754  2b4f0c                           sub    ecx,DWORD PTR [edi+0xc]
007A0757  8d470c                           lea    eax,[edi+0xc]
007A075A  33db                             xor    ebx,ebx
007A075C  c1f902                           sar    ecx,0x2
007A075F  895de4                           mov    DWORD PTR [ebp-0x1c],ebx
007A0762  85c9                             test   ecx,ecx
007A0764  0f840d010000                     je     0x7a0877
007A076A  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
007A076D  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
007A0770  8b74ca48                         mov    esi,DWORD PTR [edx+ecx*8+0x48]
007A0774  8b38                             mov    edi,DWORD PTR [eax]
007A0776  8b4610                           mov    eax,DWORD PTR [esi+0x10]
007A0779  83c60c                           add    esi,0xc
007A077C  8d0c9d00000000                   lea    ecx,[ebx*4+0x0]
007A0783  03f9                             add    edi,ecx
007A0785  3bf8                             cmp    edi,eax
007A0787  7362                             jae    0x7a07eb
007A0789  8b16                             mov    edx,DWORD PTR [esi]
007A078B  3bd7                             cmp    edx,edi
007A078D  775c                             ja     0x7a07eb
007A078F  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007A0792  2bfa                             sub    edi,edx
007A0794  c1ff02                           sar    edi,0x2
007A0797  3bc1                             cmp    eax,ecx
007A0799  753e                             jne    0x7a07d9
007A079B  2bc2                             sub    eax,edx
007A079D  c1f802                           sar    eax,0x2
007A07A0  3dfeffff3f                       cmp    eax,0x3ffffffe
007A07A5  0f87e5000000                     ja     0x7a0890
007A07AB  2bca                             sub    ecx,edx
007A07AD  40                               inc    eax
007A07AE  c1f902                           sar    ecx,0x2
007A07B1  3bc1                             cmp    eax,ecx
007A07B3  7624                             jbe    0x7a07d9
007A07B5  8bd1                             mov    edx,ecx
007A07B7  d1ea                             shr    edx,1
007A07B9  bbffffff3f                       mov    ebx,0x3fffffff
007A07BE  2bda                             sub    ebx,edx
007A07C0  3bd9                             cmp    ebx,ecx
007A07C2  7304                             jae    0x7a07c8
007A07C4  33c9                             xor    ecx,ecx
007A07C6  eb02                             jmp    0x7a07ca
007A07C8  03ca                             add    ecx,edx
007A07CA  3bc8                             cmp    ecx,eax
007A07CC  7302                             jae    0x7a07d0
007A07CE  8bc8                             mov    ecx,eax
007A07D0  51                               push   ecx
007A07D1  e8aa71ffff                       call   0x797980
007A07D6  8b5de4                           mov    ebx,DWORD PTR [ebp-0x1c]
007A07D9  8b4604                           mov    eax,DWORD PTR [esi+0x4]
007A07DC  8b16                             mov    edx,DWORD PTR [esi]
007A07DE  8d0cba                           lea    ecx,[edx+edi*4]
007A07E1  85c0                             test   eax,eax
007A07E3  7458                             je     0x7a083d
007A07E5  8b09                             mov    ecx,DWORD PTR [ecx]
007A07E7  8908                             mov    DWORD PTR [eax],ecx
007A07E9  eb52                             jmp    0x7a083d
007A07EB  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007A07EE  3bc1                             cmp    eax,ecx
007A07F0  7540                             jne    0x7a0832
007A07F2  8b16                             mov    edx,DWORD PTR [esi]
007A07F4  2bc2                             sub    eax,edx
007A07F6  c1f802                           sar    eax,0x2
007A07F9  3dfeffff3f                       cmp    eax,0x3ffffffe
007A07FE  0f878c000000                     ja     0x7a0890
007A0804  2bca                             sub    ecx,edx
007A0806  40                               inc    eax
007A0807  c1f902                           sar    ecx,0x2
007A080A  3bc1                             cmp    eax,ecx
007A080C  7624                             jbe    0x7a0832
007A080E  8bd1                             mov    edx,ecx
007A0810  d1ea                             shr    edx,1
007A0812  bbffffff3f                       mov    ebx,0x3fffffff
007A0817  2bda                             sub    ebx,edx
007A0819  3bd9                             cmp    ebx,ecx
007A081B  7304                             jae    0x7a0821
007A081D  33c9                             xor    ecx,ecx
007A081F  eb02                             jmp    0x7a0823
007A0821  03ca                             add    ecx,edx
007A0823  3bc8                             cmp    ecx,eax
007A0825  7302                             jae    0x7a0829
007A0827  8bc8                             mov    ecx,eax
007A0829  51                               push   ecx
007A082A  e85171ffff                       call   0x797980
007A082F  8b5de4                           mov    ebx,DWORD PTR [ebp-0x1c]
007A0832  8b4604                           mov    eax,DWORD PTR [esi+0x4]
007A0835  85c0                             test   eax,eax
007A0837  7404                             je     0x7a083d
007A0839  8b17                             mov    edx,DWORD PTR [edi]
007A083B  8910                             mov    DWORD PTR [eax],edx
007A083D  83460404                         add    DWORD PTR [esi+0x4],0x4
007A0841  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A0844  8b480c                           mov    ecx,DWORD PTR [eax+0xc]
007A0847  8b1499                           mov    edx,DWORD PTR [ecx+ebx*4]
007A084A  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A084D  52                               push   edx
007A084E  50                               push   eax
007A084F  680cf5c400                       push   0xc4f50c
007A0854  e864280f00                       call   0x8930bd
007A0859  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A085C  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
007A085F  2b480c                           sub    ecx,DWORD PTR [eax+0xc]
007A0862  83c00c                           add    eax,0xc
007A0865  43                               inc    ebx
007A0866  c1f902                           sar    ecx,0x2
007A0869  83c40c                           add    esp,0xc
007A086C  895de4                           mov    DWORD PTR [ebp-0x1c],ebx
007A086F  3bd9                             cmp    ebx,ecx
007A0871  0f82f3feffff                     jb     0x7a076a
007A0877  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
007A087A  52                               push   edx
007A087B  6828f5c400                       push   0xc4f528
007A0880  e838280f00                       call   0x8930bd
007A0885  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A0888  83c408                           add    esp,0x8
007A088B  e9a5000000                       jmp    0x7a0935
007A0890  687823bf00                       push   0xbf2378
007A0895  e896d20d00                       call   0x87db30
007A089A  8b7dec                           mov    edi,DWORD PTR [ebp-0x14]
007A089D  57                               push   edi
007A089E  6840f5c400                       push   0xc4f540
007A08A3  e815280f00                       call   0x8930bd
007A08A8  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
007A08AB  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
007A08AE  33c9                             xor    ecx,ecx
007A08B0  83c408                           add    esp,0x8
007A08B3  894db8                           mov    DWORD PTR [ebp-0x48],ecx
007A08B6  894dbc                           mov    DWORD PTR [ebp-0x44],ecx
007A08B9  8bf0                             mov    esi,eax
007A08BB  8955d0                           mov    DWORD PTR [ebp-0x30],edx
007A08BE  3bc1                             cmp    eax,ecx
007A08C0  7431                             je     0x7a08f3
007A08C2  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
007A08C5  8d5004                           lea    edx,[eax+0x4]
007A08C8  85c9                             test   ecx,ecx
007A08CA  7427                             je     0x7a08f3
007A08CC  8d642400                         lea    esp,[esp+0x0]
007A08D0  8d7901                           lea    edi,[ecx+0x1]
007A08D3  8bda                             mov    ebx,edx
007A08D5  8bc1                             mov    eax,ecx
007A08D7  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
007A08DB  3bc1                             cmp    eax,ecx
007A08DD  7408                             je     0x7a08e7
007A08DF  8b0a                             mov    ecx,DWORD PTR [edx]
007A08E1  85c9                             test   ecx,ecx
007A08E3  75eb                             jne    0x7a08d0
007A08E5  eb09                             jmp    0x7a08f0
007A08E7  8b4dd0                           mov    ecx,DWORD PTR [ebp-0x30]
007A08EA  8975bc                           mov    DWORD PTR [ebp-0x44],esi
007A08ED  894db8                           mov    DWORD PTR [ebp-0x48],ecx
007A08F0  8b7dec                           mov    edi,DWORD PTR [ebp-0x14]
007A08F3  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A08F6  8b74fb4c                         mov    esi,DWORD PTR [ebx+edi*8+0x4c]
007A08FA  8b45bc                           mov    eax,DWORD PTR [ebp-0x44]
007A08FD  8b55b8                           mov    edx,DWORD PTR [ebp-0x48]
007A0900  8944fb4c                         mov    DWORD PTR [ebx+edi*8+0x4c],eax
007A0904  8954fb48                         mov    DWORD PTR [ebx+edi*8+0x48],edx
007A0908  85f6                             test   esi,esi
007A090A  7429                             je     0x7a0935
007A090C  8d4604                           lea    eax,[esi+0x4]
007A090F  83c9ff                           or     ecx,0xffffffff
007A0912  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A0916  751d                             jne    0x7a0935
007A0918  8b16                             mov    edx,DWORD PTR [esi]
007A091A  8b02                             mov    eax,DWORD PTR [edx]
007A091C  8bce                             mov    ecx,esi
007A091E  ffd0                             call   eax
007A0920  8d4e08                           lea    ecx,[esi+0x8]
007A0923  83caff                           or     edx,0xffffffff
007A0926  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A092A  7509                             jne    0x7a0935
007A092C  8b06                             mov    eax,DWORD PTR [esi]
007A092E  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A0931  8bce                             mov    ecx,esi
007A0933  ffd2                             call   edx
007A0935  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A0938  8b30                             mov    esi,DWORD PTR [eax]
007A093A  3bf0                             cmp    esi,eax
007A093C  0f84b0000000                     je     0x7a09f2
007A0942  8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
007A0945  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A0948  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A094C  8b7e0c                           mov    edi,DWORD PTR [esi+0xc]
007A094F  8bd1                             mov    edx,ecx
007A0951  7514                             jne    0x7a0967
007A0953  39780c                           cmp    DWORD PTR [eax+0xc],edi
007A0956  7305                             jae    0x7a095d
007A0958  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A095B  eb04                             jmp    0x7a0961
007A095D  8bd0                             mov    edx,eax
007A095F  8b00                             mov    eax,DWORD PTR [eax]
007A0961  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A0965  74ec                             je     0x7a0953
007A0967  8955cc                           mov    DWORD PTR [ebp-0x34],edx
007A096A  3bd1                             cmp    edx,ecx
007A096C  740a                             je     0x7a0978
007A096E  3b7a0c                           cmp    edi,DWORD PTR [edx+0xc]
007A0971  7205                             jb     0x7a0978
007A0973  8d45cc                           lea    eax,[ebp-0x34]
007A0976  eb06                             jmp    0x7a097e
007A0978  894dc8                           mov    DWORD PTR [ebp-0x38],ecx
007A097B  8d45c8                           lea    eax,[ebp-0x38]
007A097E  8b00                             mov    eax,DWORD PTR [eax]
007A0980  3bc1                             cmp    eax,ecx
007A0982  7423                             je     0x7a09a7
007A0984  8b4010                           mov    eax,DWORD PTR [eax+0x10]
007A0987  8b4854                           mov    ecx,DWORD PTR [eax+0x54]
007A098A  85c9                             test   ecx,ecx
007A098C  7419                             je     0x7a09a7
007A098E  8b415c                           mov    eax,DWORD PTR [ecx+0x5c]
007A0991  85c0                             test   eax,eax
007A0993  7407                             je     0x7a099c
007A0995  e846520200                       call   0x7c5be0
007A099A  eb0b                             jmp    0x7a09a7
007A099C  80796000                         cmp    BYTE PTR [ecx+0x60],0x0
007A09A0  7405                             je     0x7a09a7
007A09A2  e849460200                       call   0x7c4ff0
007A09A7  807e1100                         cmp    BYTE PTR [esi+0x11],0x0
007A09AB  753c                             jne    0x7a09e9
007A09AD  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007A09B0  80791100                         cmp    BYTE PTR [ecx+0x11],0x0
007A09B4  7518                             jne    0x7a09ce
007A09B6  8b01                             mov    eax,DWORD PTR [ecx]
007A09B8  80781100                         cmp    BYTE PTR [eax+0x11],0x0
007A09BC  750c                             jne    0x7a09ca
007A09BE  8bff                             mov    edi,edi
007A09C0  8bc8                             mov    ecx,eax
007A09C2  8b01                             mov    eax,DWORD PTR [ecx]
007A09C4  80781100                         cmp    BYTE PTR [eax+0x11],0x0
007A09C8  74f6                             je     0x7a09c0
007A09CA  8bf1                             mov    esi,ecx
007A09CC  eb1b                             jmp    0x7a09e9
007A09CE  8b4604                           mov    eax,DWORD PTR [esi+0x4]
007A09D1  80781100                         cmp    BYTE PTR [eax+0x11],0x0
007A09D5  7510                             jne    0x7a09e7
007A09D7  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
007A09DA  750b                             jne    0x7a09e7
007A09DC  8bf0                             mov    esi,eax
007A09DE  8b4004                           mov    eax,DWORD PTR [eax+0x4]
007A09E1  80781100                         cmp    BYTE PTR [eax+0x11],0x0
007A09E5  74f0                             je     0x7a09d7
007A09E7  8bf0                             mov    esi,eax
007A09E9  3b7590                           cmp    esi,DWORD PTR [ebp-0x70]
007A09EC  0f8550ffffff                     jne    0x7a0942
007A09F2  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
007A09F6  8b4d90                           mov    ecx,DWORD PTR [ebp-0x70]
007A09F9  8b01                             mov    eax,DWORD PTR [ecx]
007A09FB  51                               push   ecx
007A09FC  50                               push   eax
007A09FD  8d75c0                           lea    esi,[ebp-0x40]
007A0A00  8d458c                           lea    eax,[ebp-0x74]
007A0A03  e85897d2ff                       call   0x4ca160
007A0A08  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A0A0B  50                               push   eax
007A0A0C  e8fb070f00                       call   0x89120c
007A0A11  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007A0A18  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
007A0A1B  83c404                           add    esp,0x4
007A0A1E  85c0                             test   eax,eax
007A0A20  742b                             je     0x7a0a4d
007A0A22  8bf0                             mov    esi,eax
007A0A24  83c004                           add    eax,0x4
007A0A27  83c9ff                           or     ecx,0xffffffff
007A0A2A  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A0A2E  751d                             jne    0x7a0a4d
007A0A30  8b16                             mov    edx,DWORD PTR [esi]
007A0A32  8b02                             mov    eax,DWORD PTR [edx]
007A0A34  8bce                             mov    ecx,esi
007A0A36  ffd0                             call   eax
007A0A38  8d4e08                           lea    ecx,[esi+0x8]
007A0A3B  83caff                           or     edx,0xffffffff
007A0A3E  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A0A42  7509                             jne    0x7a0a4d
007A0A44  8b06                             mov    eax,DWORD PTR [esi]
007A0A46  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A0A49  8bce                             mov    ecx,esi
007A0A4B  ffd2                             call   edx
007A0A4D  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007A0A50  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A0A57  59                               pop    ecx
007A0A58  5f                               pop    edi
007A0A59  5e                               pop    esi
007A0A5A  5b                               pop    ebx
007A0A5B  8be5                             mov    esp,ebp
007A0A5D  5d                               pop    ebp
007A0A5E  c20c00                           ret    0xc
007A0A61  8d45c4                           lea    eax,[ebp-0x3c]
007A0A64  50                               push   eax
007A0A65  8d4d9c                           lea    ecx,[ebp-0x64]
007A0A68  8975c4                           mov    DWORD PTR [ebp-0x3c],esi
007A0A6B  e839060f00                       call   0x8910a9
007A0A70  68a857c800                       push   0xc857a8
007A0A75  8d4d9c                           lea    ecx,[ebp-0x64]
007A0A78  51                               push   ecx
007A0A79  c7459ca42cbd00                   mov    DWORD PTR [ebp-0x64],0xbd2ca4
007A0A80  e86bbf0f00                       call   0x89c9f0
