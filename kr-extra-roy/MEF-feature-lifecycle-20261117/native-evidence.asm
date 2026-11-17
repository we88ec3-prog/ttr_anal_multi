; normal_and_review_end [REUSED_JOIN] 0x561db0..0x5620aa
00561DB0  55                             push   ebp
00561DB1  8bec                           mov    ebp,esp
00561DB3  83e4f8                         and    esp,0xfffffff8
00561DB6  6aff                           push   0xffffffff
00561DB8  6864fc9300                     push   0x93fc64
00561DBD  64a100000000                   mov    eax,fs:0x0
00561DC3  50                             push   eax
00561DC4  83ec10                         sub    esp,0x10
00561DC7  53                             push   ebx
00561DC8  56                             push   esi
00561DC9  57                             push   edi
00561DCA  a1201fd600                     mov    eax,ds:0xd61f20
00561DCF  33c4                           xor    eax,esp
00561DD1  50                             push   eax
00561DD2  8d442420                       lea    eax,[esp+0x20]
00561DD6  64a300000000                   mov    fs:0x0,eax
00561DDC  8bf9                           mov    edi,ecx
00561DDE  33f6                           xor    esi,esi
00561DE0  80bf8900000000                 cmp    BYTE PTR [edi+0x89],0x0
00561DE7  0f8473010000                   je     0x561f60
00561DED  397728                         cmp    DWORD PTR [edi+0x28],esi
00561DF0  0f84aa000000                   je     0x561ea0
00561DF6  897728                         mov    DWORD PTR [edi+0x28],esi
00561DF9  e85224edff                     call   0x434250
00561DFE  bb01000000                     mov    ebx,0x1
00561E03  895814                         mov    DWORD PTR [eax+0x14],ebx
00561E06  841dd4f3fd00                   test   BYTE PTR ds:0xfdf3d4,bl
00561E0C  7525                           jne    0x561e33
00561E0E  091dd4f3fd00                   or     DWORD PTR ds:0xfdf3d4,ebx
00561E14  89742428                       mov    DWORD PTR [esp+0x28],esi
00561E18  e863251900                     call   0x6f4380
00561E1D  68d0e6bc00                     push   0xbce6d0
00561E22  e8f3043300                     call   0x89231a
00561E27  83c404                         add    esp,0x4
00561E2A  83ceff                         or     esi,0xffffffff
00561E2D  89742428                       mov    DWORD PTR [esp+0x28],esi
00561E31  eb03                           jmp    0x561e36
00561E33  83ceff                         or     esi,0xffffffff
00561E36  68ec06c100                     push   0xc106ec
00561E3B  6a00                           push   0x0
00561E3D  68c8f3fd00                     push   0xfdf3c8
00561E42  e859b2f4ff                     call   0x4ad0a0
00561E47  f605d4adfa0001                 test   BYTE PTR ds:0xfaadd4,0x1
00561E4E  7520                           jne    0x561e70
00561E50  091dd4adfa00                   or     DWORD PTR ds:0xfaadd4,ebx
00561E56  895c2428                       mov    DWORD PTR [esp+0x28],ebx
00561E5A  e821560200                     call   0x587480
00561E5F  68c0ccbc00                     push   0xbcccc0
00561E64  e8b1043300                     call   0x89231a
00561E69  83c404                         add    esp,0x4
00561E6C  89742428                       mov    DWORD PTR [esp+0x28],esi
00561E70  d98784000000                   fld    DWORD PTR [edi+0x84]
00561E76  83ec08                         sub    esp,0x8
00561E79  d95c241c                       fstp   DWORD PTR [esp+0x1c]
00561E7D  d944241c                       fld    DWORD PTR [esp+0x1c]
00561E81  d9542404                       fst    DWORD PTR [esp+0x4]
00561E85  d91c24                         fstp   DWORD PTR [esp]
00561E88  e8937b0200                     call   0x589a20
00561E8D  8a9f88000000                   mov    bl,BYTE PTR [edi+0x88]
00561E93  e8082deaff                     call   0x404ba0
00561E98  8898c4680000                   mov    BYTE PTR [eax+0x68c4],bl
00561E9E  eb03                           jmp    0x561ea3
00561EA0  83ceff                         or     esi,0xffffffff
00561EA3  f605640ffc0001                 test   BYTE PTR ds:0xfc0f64,0x1
00561EAA  7525                           jne    0x561ed1
00561EAC  830d640ffc0001                 or     DWORD PTR ds:0xfc0f64,0x1
00561EB3  c744242802000000               mov    DWORD PTR [esp+0x28],0x2
00561EBB  e820bef1ff                     call   0x47dce0
00561EC0  68f0dabc00                     push   0xbcdaf0
00561EC5  e850043300                     call   0x89231a
00561ECA  83c404                         add    esp,0x4
00561ECD  89742428                       mov    DWORD PTR [esp+0x28],esi
00561ED1  8b473c                         mov    eax,DWORD PTR [edi+0x3c]
00561ED4  8b4f38                         mov    ecx,DWORD PTR [edi+0x38]
00561ED7  50                             push   eax
00561ED8  51                             push   ecx
00561ED9  68680ffc00                     push   0xfc0f68
00561EDE  e85dc7f1ff                     call   0x47e640
00561EE3  33db                           xor    ebx,ebx
00561EE5  89473c                         mov    DWORD PTR [edi+0x3c],eax
00561EE8  3bc3                           cmp    eax,ebx
00561EEA  741f                           je     0x561f0b
00561EEC  8b5738                         mov    edx,DWORD PTR [edi+0x38]
00561EEF  50                             push   eax
00561EF0  52                             push   edx
00561EF1  8bf7                           mov    esi,edi
00561EF3  e828380000                     call   0x565720
00561EF8  8b4c2420                       mov    ecx,DWORD PTR [esp+0x20]
00561EFC  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00561F03  59                             pop    ecx
00561F04  5f                             pop    edi
00561F05  5e                             pop    esi
00561F06  5b                             pop    ebx
00561F07  8be5                           mov    esp,ebp
00561F09  5d                             pop    ebp
00561F0A  c3                             ret
00561F0B  f605c00ffc0001                 test   BYTE PTR ds:0xfc0fc0,0x1
00561F12  7525                           jne    0x561f39
00561F14  830dc00ffc0001                 or     DWORD PTR ds:0xfc0fc0,0x1
00561F1B  c744242803000000               mov    DWORD PTR [esp+0x28],0x3
00561F23  e8286f1700                     call   0x6d8e50
00561F28  68b0dbbc00                     push   0xbcdbb0
00561F2D  e8e8033300                     call   0x89231a
00561F32  83c404                         add    esp,0x4
00561F35  89742428                       mov    DWORD PTR [esp+0x28],esi
00561F39  8b4734                         mov    eax,DWORD PTR [edi+0x34]
00561F3C  50                             push   eax
00561F3D  b9c80ffc00                     mov    ecx,0xfc0fc8
00561F42  e8e9741700                     call   0x6d9430
00561F47  895f38                         mov    DWORD PTR [edi+0x38],ebx
00561F4A  895f3c                         mov    DWORD PTR [edi+0x3c],ebx
00561F4D  8b4c2420                       mov    ecx,DWORD PTR [esp+0x20]
00561F51  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00561F58  59                             pop    ecx
00561F59  5f                             pop    edi
00561F5A  5e                             pop    esi
00561F5B  5b                             pop    ebx
00561F5C  8be5                           mov    esp,ebp
00561F5E  5d                             pop    ebp
00561F5F  c3                             ret
00561F60  397728                         cmp    DWORD PTR [edi+0x28],esi
00561F63  0f8428010000                   je     0x562091
00561F69  897728                         mov    DWORD PTR [edi+0x28],esi
00561F6C  e8df22edff                     call   0x434250
00561F71  bb01000000                     mov    ebx,0x1
00561F76  895814                         mov    DWORD PTR [eax+0x14],ebx
00561F79  397738                         cmp    DWORD PTR [edi+0x38],esi
00561F7C  7439                           je     0x561fb7
00561F7E  684403c100                     push   0xc10344
00561F83  53                             push   ebx
00561F84  e8a792f3ff                     call   0x49b230
00561F89  50                             push   eax
00561F8A  e811b1f4ff                     call   0x4ad0a0
00561F8F  6aff                           push   0xffffffff
00561F91  51                             push   ecx
00561F92  e89992f3ff                     call   0x49b230
00561F97  83c404                         add    esp,0x4
00561F9A  e8b10bf4ff                     call   0x4a2b50
00561F9F  3bc3                           cmp    eax,ebx
00561FA1  754e                           jne    0x561ff1
00561FA3  e8d826ebff                     call   0x414680
00561FA8  8b4f3c                         mov    ecx,DWORD PTR [edi+0x3c]
00561FAB  8b5738                         mov    edx,DWORD PTR [edi+0x38]
00561FAE  51                             push   ecx
00561FAF  52                             push   edx
00561FB0  e8eb19f4ff                     call   0x4a39a0
00561FB5  eb3a                           jmp    0x561ff1
00561FB7  8d5f3c                         lea    ebx,[edi+0x3c]
00561FBA  8d7774                         lea    esi,[edi+0x74]
00561FBD  53                             push   ebx
00561FBE  e87dbe1500                     call   0x6bde40
00561FC3  50                             push   eax
00561FC4  56                             push   esi
00561FC5  8d74241c                       lea    esi,[esp+0x1c]
00561FC9  e8c248edff                     call   0x436890
00561FCE  57                             push   edi
00561FCF  e8cc030000                     call   0x5623a0
00561FD4  e8a726ebff                     call   0x414680
00561FD9  8b03                           mov    eax,DWORD PTR [ebx]
00561FDB  8b4f38                         mov    ecx,DWORD PTR [edi+0x38]
00561FDE  50                             push   eax
00561FDF  51                             push   ecx
00561FE0  e8bb19f4ff                     call   0x4a39a0
00561FE5  e8c6000000                     call   0x5620b0
00561FEA  bb01000000                     mov    ebx,0x1
00561FEF  33f6                           xor    esi,esi
00561FF1  f605d4f3fd0001                 test   BYTE PTR ds:0xfdf3d4,0x1
00561FF8  7528                           jne    0x562022
00561FFA  091dd4f3fd00                   or     DWORD PTR ds:0xfdf3d4,ebx
00562000  c744242804000000               mov    DWORD PTR [esp+0x28],0x4
00562008  e873231900                     call   0x6f4380
0056200D  68d0e6bc00                     push   0xbce6d0
00562012  e803033300                     call   0x89231a
00562017  83c404                         add    esp,0x4
0056201A  c7442428ffffffff               mov    DWORD PTR [esp+0x28],0xffffffff
00562022  68ec06c100                     push   0xc106ec
00562027  56                             push   esi
00562028  68c8f3fd00                     push   0xfdf3c8
0056202D  e86eb0f4ff                     call   0x4ad0a0
00562032  f605d4adfa0001                 test   BYTE PTR ds:0xfaadd4,0x1
00562039  7528                           jne    0x562063
0056203B  091dd4adfa00                   or     DWORD PTR ds:0xfaadd4,ebx
00562041  c744242805000000               mov    DWORD PTR [esp+0x28],0x5
00562049  e832540200                     call   0x587480
0056204E  68c0ccbc00                     push   0xbcccc0
00562053  e8c2023300                     call   0x89231a
00562058  83c404                         add    esp,0x4
0056205B  c7442428ffffffff               mov    DWORD PTR [esp+0x28],0xffffffff
00562063  d98784000000                   fld    DWORD PTR [edi+0x84]
00562069  83ec08                         sub    esp,0x8
0056206C  d95c241c                       fstp   DWORD PTR [esp+0x1c]
00562070  d944241c                       fld    DWORD PTR [esp+0x1c]
00562074  d9542404                       fst    DWORD PTR [esp+0x4]
00562078  d91c24                         fstp   DWORD PTR [esp]
0056207B  e8a0790200                     call   0x589a20
00562080  8a9f88000000                   mov    bl,BYTE PTR [edi+0x88]
00562086  e8152beaff                     call   0x404ba0
0056208B  8898c4680000                   mov    BYTE PTR [eax+0x68c4],bl
00562091  897738                         mov    DWORD PTR [edi+0x38],esi
00562094  89773c                         mov    DWORD PTR [edi+0x3c],esi
00562097  8b4c2420                       mov    ecx,DWORD PTR [esp+0x20]
0056209B  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
005620A2  59                             pop    ecx
005620A3  5f                             pop    edi
005620A4  5e                             pop    esi
005620A5  5b                             pop    ebx
005620A6  8be5                           mov    esp,ebp
005620A8  5d                             pop    ebp
005620A9  c3                             ret

; active_stop [REUSED_BOUNDARY] 0x5624b0..0x5628b1
005624B0  55                             push   ebp
005624B1  8bec                           mov    ebp,esp
005624B3  83e4f8                         and    esp,0xfffffff8
005624B6  6aff                           push   0xffffffff
005624B8  68603d9400                     push   0x943d60
005624BD  64a100000000                   mov    eax,fs:0x0
005624C3  50                             push   eax
005624C4  83ec28                         sub    esp,0x28
005624C7  a1201fd600                     mov    eax,ds:0xd61f20
005624CC  33c4                           xor    eax,esp
005624CE  89442420                       mov    DWORD PTR [esp+0x20],eax
005624D2  53                             push   ebx
005624D3  56                             push   esi
005624D4  57                             push   edi
005624D5  a1201fd600                     mov    eax,ds:0xd61f20
005624DA  33c4                           xor    eax,esp
005624DC  50                             push   eax
005624DD  8d442438                       lea    eax,[esp+0x38]
005624E1  64a300000000                   mov    fs:0x0,eax
005624E7  33f6                           xor    esi,esi
005624E9  8bf9                           mov    edi,ecx
005624EB  897c2410                       mov    DWORD PTR [esp+0x10],edi
005624EF  397508                         cmp    DWORD PTR [ebp+0x8],esi
005624F2  742a                           je     0x56251e
005624F4  817f38e8030000                 cmp    DWORD PTR [edi+0x38],0x3e8
005624FB  7521                           jne    0x56251e
005624FD  8b473c                         mov    eax,DWORD PTR [edi+0x3c]
00562500  83f80f                         cmp    eax,0xf
00562503  740f                           je     0x562514
00562505  83f810                         cmp    eax,0x10
00562508  740a                           je     0x562514
0056250A  83f811                         cmp    eax,0x11
0056250D  7405                           je     0x562514
0056250F  83f812                         cmp    eax,0x12
00562512  750a                           jne    0x56251e
00562514  c705a0a7fb0001000000           mov    DWORD PTR ds:0xfba7a0,0x1
0056251E  397728                         cmp    DWORD PTR [edi+0x28],esi
00562521  0f846a030000                   je     0x562891
00562527  83cbff                         or     ebx,0xffffffff
0056252A  f6051c76fb0001                 test   BYTE PTR ds:0xfb761c,0x1
00562531  7521                           jne    0x562554
00562533  830d1c76fb0001                 or     DWORD PTR ds:0xfb761c,0x1
0056253A  89742440                       mov    DWORD PTR [esp+0x40],esi
0056253E  e80dc2feff                     call   0x54e750
00562543  6860d2bc00                     push   0xbcd260
00562548  e8cdfd3200                     call   0x89231a
0056254D  83c404                         add    esp,0x4
00562550  895c2440                       mov    DWORD PTR [esp+0x40],ebx
00562554  8b0d2076fb00                   mov    ecx,DWORD PTR ds:0xfb7620
0056255A  3bce                           cmp    ecx,esi
0056255C  7407                           je     0x562565
0056255E  8b01                           mov    eax,DWORD PTR [ecx]
00562560  8b500c                         mov    edx,DWORD PTR [eax+0xc]
00562563  ffd2                           call   edx
00562565  e8f676f2ff                     call   0x489c60
0056256A  b920000000                     mov    ecx,0x20
0056256F  90                             nop
00562570  8930                           mov    DWORD PTR [eax],esi
00562572  83c014                         add    eax,0x14
00562575  49                             dec    ecx
00562576  75f8                           jne    0x562570
00562578  f605881bfc0001                 test   BYTE PTR ds:0xfc1b88,0x1
0056257F  7525                           jne    0x5625a6
00562581  b801000000                     mov    eax,0x1
00562586  0905881bfc00                   or     DWORD PTR ds:0xfc1b88,eax
0056258C  89442440                       mov    DWORD PTR [esp+0x40],eax
00562590  e87bf60100                     call   0x581c10
00562595  68a0dfbc00                     push   0xbcdfa0
0056259A  e87bfd3200                     call   0x89231a
0056259F  83c404                         add    esp,0x4
005625A2  895c2440                       mov    DWORD PTR [esp+0x40],ebx
005625A6  a1901bfc00                     mov    eax,ds:0xfc1b90
005625AB  8935c01bfc00                   mov    DWORD PTR ds:0xfc1bc0,esi
005625B1  8935bc1bfc00                   mov    DWORD PTR ds:0xfc1bbc,esi
005625B7  3bc6                           cmp    eax,esi
005625B9  740c                           je     0x5625c7
005625BB  50                             push   eax
005625BC  e80f22f4ff                     call   0x4a47d0
005625C1  8935901bfc00                   mov    DWORD PTR ds:0xfc1b90,esi
005625C7  f605f41bfc0001                 test   BYTE PTR ds:0xfc1bf4,0x1
005625CE  7525                           jne    0x5625f5
005625D0  830df41bfc0001                 or     DWORD PTR ds:0xfc1bf4,0x1
005625D7  c744244002000000               mov    DWORD PTR [esp+0x40],0x2
005625DF  e8acc90100                     call   0x57ef90
005625E4  68b0dfbc00                     push   0xbcdfb0
005625E9  e82cfd3200                     call   0x89231a
005625EE  83c404                         add    esp,0x4
005625F1  895c2440                       mov    DWORD PTR [esp+0x40],ebx
005625F5  89356c1cfc00                   mov    DWORD PTR ds:0xfc1c6c,esi
005625FB  8b4754                         mov    eax,DWORD PTR [edi+0x54]
005625FE  bf04000000                     mov    edi,0x4
00562603  3bc6                           cmp    eax,esi
00562605  0f857c000000                   jne    0x562687
0056260B  f605e81efe0001                 test   BYTE PTR ds:0xfe1ee8,0x1
00562612  7525                           jne    0x562639
00562614  830de81efe0001                 or     DWORD PTR ds:0xfe1ee8,0x1
0056261B  c744244003000000               mov    DWORD PTR [esp+0x40],0x3
00562623  e8e89fffff                     call   0x55c610
00562628  6890f2bc00                     push   0xbcf290
0056262D  e8e8fc3200                     call   0x89231a
00562632  83c404                         add    esp,0x4
00562635  895c2440                       mov    DWORD PTR [esp+0x40],ebx
00562639  68ec1efe00                     push   0xfe1eec
0056263E  8d742418                       lea    esi,[esp+0x18]
00562642  e879d9ffff                     call   0x55ffc0
00562647  8b4c2410                       mov    ecx,DWORD PTR [esp+0x10]
0056264B  50                             push   eax
0056264C  83c144                         add    ecx,0x44
0056264F  897c2444                       mov    DWORD PTR [esp+0x44],edi
00562653  e85805eaff                     call   0x402bb0
00562658  895c2440                       mov    DWORD PTR [esp+0x40],ebx
0056265C  837c242810                     cmp    DWORD PTR [esp+0x28],0x10
00562661  720d                           jb     0x562670
00562663  8b442414                       mov    eax,DWORD PTR [esp+0x14]
00562667  50                             push   eax
00562668  e89feb3200                     call   0x89120c
0056266D  83c404                         add    esp,0x4
00562670  c74424280f000000               mov    DWORD PTR [esp+0x28],0xf
00562678  c744242400000000               mov    DWORD PTR [esp+0x24],0x0
00562680  c644241400                     mov    BYTE PTR [esp+0x14],0x0
00562685  33f6                           xor    esi,esi
00562687  8b4c2410                       mov    ecx,DWORD PTR [esp+0x10]
0056268B  e810190000                     call   0x563fa0
00562690  8b4c2410                       mov    ecx,DWORD PTR [esp+0x10]
00562694  e8d7130000                     call   0x563a70
00562699  8b4c2410                       mov    ecx,DWORD PTR [esp+0x10]
0056269D  e85e040000                     call   0x562b00
005626A2  397508                         cmp    DWORD PTR [ebp+0x8],esi
005626A5  743a                           je     0x5626e1
005626A7  f605141bfc0001                 test   BYTE PTR ds:0xfc1b14,0x1
005626AE  7525                           jne    0x5626d5
005626B0  830d141bfc0001                 or     DWORD PTR ds:0xfc1b14,0x1
005626B7  c744244005000000               mov    DWORD PTR [esp+0x40],0x5
005626BF  e8ccc7ffff                     call   0x55ee90
005626C4  6890dfbc00                     push   0xbcdf90
005626C9  e84cfc3200                     call   0x89231a
005626CE  83c404                         add    esp,0x4
005626D1  895c2440                       mov    DWORD PTR [esp+0x40],ebx
005626D5  be181bfc00                     mov    esi,0xfc1b18
005626DA  e8c1d1ffff                     call   0x55f8a0
005626DF  33f6                           xor    esi,esi
005626E1  e88ad8ffff                     call   0x55ff70
005626E6  f6054027fe0001                 test   BYTE PTR ds:0xfe2740,0x1
005626ED  89700c                         mov    DWORD PTR [eax+0xc],esi
005626F0  7525                           jne    0x562717
005626F2  830d4027fe0001                 or     DWORD PTR ds:0xfe2740,0x1
005626F9  c744244006000000               mov    DWORD PTR [esp+0x40],0x6
00562701  e87abfffff                     call   0x55e680
00562706  68a0f2bc00                     push   0xbcf2a0
0056270B  e80afc3200                     call   0x89231a
00562710  83c404                         add    esp,0x4
00562713  895c2440                       mov    DWORD PTR [esp+0x40],ebx
00562717  397508                         cmp    DWORD PTR [ebp+0x8],esi
0056271A  7406                           je     0x562722
0056271C  89355427fe00                   mov    DWORD PTR ds:0xfe2754,esi
00562722  f605dc36fe0001                 test   BYTE PTR ds:0xfe36dc,0x1
00562729  89355027fe00                   mov    DWORD PTR ds:0xfe2750,esi
0056272F  7507                           jne    0x562738
00562731  830ddc36fe0001                 or     DWORD PTR ds:0xfe36dc,0x1
00562738  f6052cb2fa0001                 test   BYTE PTR ds:0xfab22c,0x1
0056273F  893dd436fe00                   mov    DWORD PTR ds:0xfe36d4,edi
00562745  8935d836fe00                   mov    DWORD PTR ds:0xfe36d8,esi
0056274B  7525                           jne    0x562772
0056274D  830d2cb2fa0001                 or     DWORD PTR ds:0xfab22c,0x1
00562754  c744244007000000               mov    DWORD PTR [esp+0x40],0x7
0056275C  e82fc5f7ff                     call   0x4dec90
00562761  6830cebc00                     push   0xbcce30
00562766  e8affb3200                     call   0x89231a
0056276B  83c404                         add    esp,0x4
0056276E  895c2440                       mov    DWORD PTR [esp+0x40],ebx
00562772  f605d4adfa0001                 test   BYTE PTR ds:0xfaadd4,0x1
00562779  8935e0b1fa00                   mov    DWORD PTR ds:0xfab1e0,esi
0056277F  7525                           jne    0x5627a6
00562781  830dd4adfa0001                 or     DWORD PTR ds:0xfaadd4,0x1
00562788  c744244008000000               mov    DWORD PTR [esp+0x40],0x8
00562790  e8eb4c0200                     call   0x587480
00562795  68c0ccbc00                     push   0xbcccc0
0056279A  e87bfb3200                     call   0x89231a
0056279F  83c404                         add    esp,0x4
005627A2  895c2440                       mov    DWORD PTR [esp+0x40],ebx
005627A6  684e430f00                     push   0xf434e
005627AB  e820830200                     call   0x58aad0
005627B0  83c404                         add    esp,0x4
005627B3  f605d4adfa0001                 test   BYTE PTR ds:0xfaadd4,0x1
005627BA  bf01000000                     mov    edi,0x1
005627BF  7524                           jne    0x5627e5
005627C1  093dd4adfa00                   or     DWORD PTR ds:0xfaadd4,edi
005627C7  c744244009000000               mov    DWORD PTR [esp+0x40],0x9
005627CF  e8ac4c0200                     call   0x587480
005627D4  68c0ccbc00                     push   0xbcccc0
005627D9  e83cfb3200                     call   0x89231a
005627DE  83c404                         add    esp,0x4
005627E1  895c2440                       mov    DWORD PTR [esp+0x40],ebx
005627E5  e8268d0200                     call   0x58b510
005627EA  f6052cb2fa0001                 test   BYTE PTR ds:0xfab22c,0x1
005627F1  7524                           jne    0x562817
005627F3  093d2cb2fa00                   or     DWORD PTR ds:0xfab22c,edi
005627F9  c74424400a000000               mov    DWORD PTR [esp+0x40],0xa
00562801  e88ac4f7ff                     call   0x4dec90
00562806  6830cebc00                     push   0xbcce30
0056280B  e80afb3200                     call   0x89231a
00562810  83c404                         add    esp,0x4
00562813  895c2440                       mov    DWORD PTR [esp+0x40],ebx
00562817  f605147cfb0001                 test   BYTE PTR ds:0xfb7c14,0x1
0056281E  8935d8b1fa00                   mov    DWORD PTR ds:0xfab1d8,esi
00562824  7524                           jne    0x56284a
00562826  093d147cfb00                   or     DWORD PTR ds:0xfb7c14,edi
0056282C  c74424400b000000               mov    DWORD PTR [esp+0x40],0xb
00562834  e817df1600                     call   0x6d0750
00562839  6830d5bc00                     push   0xbcd530
0056283E  e8d7fa3200                     call   0x89231a
00562843  83c404                         add    esp,0x4
00562846  895c2440                       mov    DWORD PTR [esp+0x40],ebx
0056284A  83253088fb00fd                 and    DWORD PTR ds:0xfb8830,0xfffffffd
00562851  f6055473fb0001                 test   BYTE PTR ds:0xfb7354,0x1
00562858  7524                           jne    0x56287e
0056285A  093d5473fb00                   or     DWORD PTR ds:0xfb7354,edi
00562860  c74424400c000000               mov    DWORD PTR [esp+0x40],0xc
00562868  e8630bffff                     call   0x5533d0
0056286D  6800d1bc00                     push   0xbcd100
00562872  e8a3fa3200                     call   0x89231a
00562877  83c404                         add    esp,0x4
0056287A  895c2440                       mov    DWORD PTR [esp+0x40],ebx
0056287E  b85873fb00                     mov    eax,0xfb7358
00562883  e8b80effff                     call   0x553740
00562888  8b4c2410                       mov    ecx,DWORD PTR [esp+0x10]
0056288C  e81ff5ffff                     call   0x561db0
00562891  8b4c2438                       mov    ecx,DWORD PTR [esp+0x38]
00562895  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0056289C  59                             pop    ecx
0056289D  5f                             pop    edi
0056289E  5e                             pop    esi
0056289F  5b                             pop    ebx
005628A0  8b4c2420                       mov    ecx,DWORD PTR [esp+0x20]
005628A4  33cc                           xor    ecx,esp
005628A6  e856e73200                     call   0x891001
005628AB  8be5                           mov    esp,ebp
005628AD  5d                             pop    ebp
005628AE  c20400                         ret    0x4

; q_stop_object [RECHECKED_CONSUMER] 0x5637e0..0x56382f
005637E0  55                             push   ebp
005637E1  8bec                           mov    ebp,esp
005637E3  51                             push   ecx
005637E4  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
005637E7  56                             push   esi
005637E8  8bf1                           mov    esi,ecx
005637EA  8d4d08                         lea    ecx,[ebp+0x8]
005637ED  894508                         mov    DWORD PTR [ebp+0x8],eax
005637F0  51                             push   ecx
005637F1  8d4e18                         lea    ecx,[esi+0x18]
005637F4  8d45fc                         lea    eax,[ebp-0x4]
005637F7  e804b72c00                     call   0x82ef00
005637FC  8b45fc                         mov    eax,DWORD PTR [ebp-0x4]
005637FF  3b461c                         cmp    eax,DWORD PTR [esi+0x1c]
00563802  7424                           je     0x563828
00563804  8b7010                         mov    esi,DWORD PTR [eax+0x10]
00563807  85f6                           test   esi,esi
00563809  741d                           je     0x563828
0056380B  d9e8                           fld1
0056380D  8b16                           mov    edx,DWORD PTR [esi]
0056380F  8b4268                         mov    eax,DWORD PTR [edx+0x68]
00563812  51                             push   ecx
00563813  d91c24                         fstp   DWORD PTR [esp]
00563816  6a01                           push   0x1
00563818  8bce                           mov    ecx,esi
0056381A  ffd0                           call   eax
0056381C  b9ff7f0000                     mov    ecx,0x7fff
00563821  66218ee2000000                 and    WORD PTR [esi+0xe2],cx
00563828  5e                             pop    esi
00563829  8be5                           mov    esp,ebp
0056382B  5d                             pop    ebp
0056382C  c20400                         ret    0x4

; q_delete_all [CURRENT_JOIN] 0x563a70..0x563c37
00563A70  55                             push   ebp
00563A71  8bec                           mov    ebp,esp
00563A73  83e4f8                         and    esp,0xfffffff8
00563A76  6aff                           push   0xffffffff
00563A78  683e939300                     push   0x93933e
00563A7D  64a100000000                   mov    eax,fs:0x0
00563A83  50                             push   eax
00563A84  83ec18                         sub    esp,0x18
00563A87  53                             push   ebx
00563A88  56                             push   esi
00563A89  57                             push   edi
00563A8A  a1201fd600                     mov    eax,ds:0xd61f20
00563A8F  33c4                           xor    eax,esp
00563A91  50                             push   eax
00563A92  8d442428                       lea    eax,[esp+0x28]
00563A96  64a300000000                   mov    fs:0x0,eax
00563A9C  894c2414                       mov    DWORD PTR [esp+0x14],ecx
00563AA0  8b411c                         mov    eax,DWORD PTR [ecx+0x1c]
00563AA3  8b30                           mov    esi,DWORD PTR [eax]
00563AA5  3bf0                           cmp    esi,eax
00563AA7  746f                           je     0x563b18
00563AA9  8da42400000000                 lea    esp,[esp+0x0]
00563AB0  8b7e10                         mov    edi,DWORD PTR [esi+0x10]
00563AB3  33db                           xor    ebx,ebx
00563AB5  3bfb                           cmp    edi,ebx
00563AB7  7417                           je     0x563ad0
00563AB9  8b07                           mov    eax,DWORD PTR [edi]
00563ABB  8b5014                         mov    edx,DWORD PTR [eax+0x14]
00563ABE  8bcf                           mov    ecx,edi
00563AC0  ffd2                           call   edx
00563AC2  8b07                           mov    eax,DWORD PTR [edi]
00563AC4  8b10                           mov    edx,DWORD PTR [eax]
00563AC6  6a01                           push   0x1
00563AC8  8bcf                           mov    ecx,edi
00563ACA  ffd2                           call   edx
00563ACC  8b4c2414                       mov    ecx,DWORD PTR [esp+0x14]
00563AD0  385e15                         cmp    BYTE PTR [esi+0x15],bl
00563AD3  753c                           jne    0x563b11
00563AD5  8b4608                         mov    eax,DWORD PTR [esi+0x8]
00563AD8  385815                         cmp    BYTE PTR [eax+0x15],bl
00563ADB  7514                           jne    0x563af1
00563ADD  8bf0                           mov    esi,eax
00563ADF  8b06                           mov    eax,DWORD PTR [esi]
00563AE1  385815                         cmp    BYTE PTR [eax+0x15],bl
00563AE4  752b                           jne    0x563b11
00563AE6  8bf0                           mov    esi,eax
00563AE8  8b06                           mov    eax,DWORD PTR [esi]
00563AEA  385815                         cmp    BYTE PTR [eax+0x15],bl
00563AED  74f7                           je     0x563ae6
00563AEF  eb20                           jmp    0x563b11
00563AF1  8b4604                         mov    eax,DWORD PTR [esi+0x4]
00563AF4  385815                         cmp    BYTE PTR [eax+0x15],bl
00563AF7  7516                           jne    0x563b0f
00563AF9  8da42400000000                 lea    esp,[esp+0x0]
00563B00  3b7008                         cmp    esi,DWORD PTR [eax+0x8]
00563B03  750a                           jne    0x563b0f
00563B05  8bf0                           mov    esi,eax
00563B07  8b4004                         mov    eax,DWORD PTR [eax+0x4]
00563B0A  385815                         cmp    BYTE PTR [eax+0x15],bl
00563B0D  74f1                           je     0x563b00
00563B0F  8bf0                           mov    esi,eax
00563B11  3b711c                         cmp    esi,DWORD PTR [ecx+0x1c]
00563B14  759a                           jne    0x563ab0
00563B16  eb02                           jmp    0x563b1a
00563B18  33db                           xor    ebx,ebx
00563B1A  8d7918                         lea    edi,[ecx+0x18]
00563B1D  e82efd2b00                     call   0x823850
00563B22  6a1c                           push   0x1c
00563B24  e83fd73200                     call   0x891268
00563B29  83c404                         add    esp,0x4
00563B2C  3bc3                           cmp    eax,ebx
00563B2E  7411                           je     0x563b41
00563B30  8918                           mov    DWORD PTR [eax],ebx
00563B32  c6400801                       mov    BYTE PTR [eax+0x8],0x1
00563B36  89580c                         mov    DWORD PTR [eax+0xc],ebx
00563B39  895810                         mov    DWORD PTR [eax+0x10],ebx
00563B3C  895814                         mov    DWORD PTR [eax+0x14],ebx
00563B3F  eb02                           jmp    0x563b43
00563B41  33c0                           xor    eax,eax
00563B43  50                             push   eax
00563B44  8d442420                       lea    eax,[esp+0x20]
00563B48  50                             push   eax
00563B49  895c2424                       mov    DWORD PTR [esp+0x24],ebx
00563B4D  895c2428                       mov    DWORD PTR [esp+0x28],ebx
00563B51  e87a85f1ff                     call   0x47c0d0
00563B56  895c2430                       mov    DWORD PTR [esp+0x30],ebx
00563B5A  8b7c241c                       mov    edi,DWORD PTR [esp+0x1c]
00563B5E  83ec08                         sub    esp,0x8
00563B61  c6470801                       mov    BYTE PTR [edi+0x8],0x1
00563B65  8bf4                           mov    esi,esp
00563B67  c7470403000000                 mov    DWORD PTR [edi+0x4],0x3
00563B6E  891e                           mov    DWORD PTR [esi],ebx
00563B70  895e04                         mov    DWORD PTR [esi+0x4],ebx
00563B73  8b5c2428                       mov    ebx,DWORD PTR [esp+0x28]
00563B77  89642420                       mov    DWORD PTR [esp+0x20],esp
00563B7B  85db                           test   ebx,ebx
00563B7D  7412                           je     0x563b91
00563B7F  8bd3                           mov    edx,ebx
00563B81  e8ca86f1ff                     call   0x47c250
00563B86  84c0                           test   al,al
00563B88  7407                           je     0x563b91
00563B8A  53                             push   ebx
00563B8B  57                             push   edi
00563B8C  e82ff62300                     call   0x7a31c0
00563B91  c644243801                     mov    BYTE PTR [esp+0x38],0x1
00563B96  f605600ffc0001                 test   BYTE PTR ds:0xfc0f60,0x1
00563B9D  7523                           jne    0x563bc2
00563B9F  830d600ffc0001                 or     DWORD PTR ds:0xfc0f60,0x1
00563BA6  c644243802                     mov    BYTE PTR [esp+0x38],0x2
00563BAB  e890932300                     call   0x79cf40
00563BB0  6880dbbc00                     push   0xbcdb80
00563BB5  e860e73200                     call   0x89231a
00563BBA  83c404                         add    esp,0x4
00563BBD  c644243801                     mov    BYTE PTR [esp+0x38],0x1
00563BC2  b9900efc00                     mov    ecx,0xfc0e90
00563BC7  c644243800                     mov    BYTE PTR [esp+0x38],0x0
00563BCC  e80fa12300                     call   0x79dce0
00563BD1  8bf0                           mov    esi,eax
00563BD3  6aff                           push   0xffffffff
00563BD5  56                             push   esi
00563BD6  ff15fc20bd00                   call   DWORD PTR ds:0xbd20fc
00563BDC  56                             push   esi
00563BDD  ff15c821bd00                   call   DWORD PTR ds:0xbd21c8
00563BE3  8b7c2414                       mov    edi,DWORD PTR [esp+0x14]
00563BE7  83c760                         add    edi,0x60
00563BEA  e831d82e00                     call   0x851420
00563BEF  c7442430ffffffff               mov    DWORD PTR [esp+0x30],0xffffffff
00563BF7  85db                           test   ebx,ebx
00563BF9  7429                           je     0x563c24
00563BFB  8d4b04                         lea    ecx,[ebx+0x4]
00563BFE  83caff                         or     edx,0xffffffff
00563C01  f00fc111                       lock xadd DWORD PTR [ecx],edx
00563C05  751d                           jne    0x563c24
00563C07  8b03                           mov    eax,DWORD PTR [ebx]
00563C09  8b10                           mov    edx,DWORD PTR [eax]
00563C0B  8bcb                           mov    ecx,ebx
00563C0D  ffd2                           call   edx
00563C0F  8d4308                         lea    eax,[ebx+0x8]
00563C12  83c9ff                         or     ecx,0xffffffff
00563C15  f00fc108                       lock xadd DWORD PTR [eax],ecx
00563C19  7509                           jne    0x563c24
00563C1B  8b13                           mov    edx,DWORD PTR [ebx]
00563C1D  8b4204                         mov    eax,DWORD PTR [edx+0x4]
00563C20  8bcb                           mov    ecx,ebx
00563C22  ffd0                           call   eax
00563C24  8b4c2428                       mov    ecx,DWORD PTR [esp+0x28]
00563C28  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00563C2F  59                             pop    ecx
00563C30  5f                             pop    edi
00563C31  5e                             pop    esi
00563C32  5b                             pop    ebx
00563C33  8be5                           mov    esp,ebp
00563C35  5d                             pop    ebp
00563C36  c3                             ret

; q_all_stopped [REUSED_BOUNDARY] 0x564880..0x5648f6
00564880  8b511c                         mov    edx,DWORD PTR [ecx+0x1c]
00564883  8b0a                           mov    ecx,DWORD PTR [edx]
00564885  56                             push   esi
00564886  3bca                           cmp    ecx,edx
00564888  7461                           je     0x5648eb
0056488A  8d9b00000000                   lea    ebx,[ebx+0x0]
00564890  8b4110                         mov    eax,DWORD PTR [ecx+0x10]
00564893  be00800000                     mov    esi,0x8000
00564898  6685b0e2000000                 test   WORD PTR [eax+0xe2],si
0056489F  7551                           jne    0x5648f2
005648A1  80791500                       cmp    BYTE PTR [ecx+0x15],0x0
005648A5  7540                           jne    0x5648e7
005648A7  8b4108                         mov    eax,DWORD PTR [ecx+0x8]
005648AA  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005648AE  751c                           jne    0x5648cc
005648B0  8bc8                           mov    ecx,eax
005648B2  8b01                           mov    eax,DWORD PTR [ecx]
005648B4  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005648B8  752d                           jne    0x5648e7
005648BA  8d9b00000000                   lea    ebx,[ebx+0x0]
005648C0  8bc8                           mov    ecx,eax
005648C2  8b01                           mov    eax,DWORD PTR [ecx]
005648C4  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005648C8  74f6                           je     0x5648c0
005648CA  eb1b                           jmp    0x5648e7
005648CC  8b4104                         mov    eax,DWORD PTR [ecx+0x4]
005648CF  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005648D3  7510                           jne    0x5648e5
005648D5  3b4808                         cmp    ecx,DWORD PTR [eax+0x8]
005648D8  750b                           jne    0x5648e5
005648DA  8bc8                           mov    ecx,eax
005648DC  8b4004                         mov    eax,DWORD PTR [eax+0x4]
005648DF  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005648E3  74f0                           je     0x5648d5
005648E5  8bc8                           mov    ecx,eax
005648E7  3bca                           cmp    ecx,edx
005648E9  75a5                           jne    0x564890
005648EB  b801000000                     mov    eax,0x1
005648F0  5e                             pop    esi
005648F1  c3                             ret
005648F2  33c0                           xor    eax,eax
005648F4  5e                             pop    esi
005648F5  c3                             ret

; camera_load [REUSED_ENTRY] 0x54e970..0x54e989
0054E970  55                             push   ebp
0054E971  8bec                           mov    ebp,esp
0054E973  51                             push   ecx
0054E974  8b5508                         mov    edx,DWORD PTR [ebp+0x8]
0054E977  8d4104                         lea    eax,[ecx+0x4]
0054E97A  8901                           mov    DWORD PTR [ecx],eax
0054E97C  83c108                         add    ecx,0x8
0054E97F  e85c852400                     call   0x796ee0
0054E984  59                             pop    ecx
0054E985  5d                             pop    ebp
0054E986  c20400                         ret    0x4

; camera_play_stop_query [CURRENT_JOIN] 0x54e9e0..0x54ea13
0054E9E0  8b09                           mov    ecx,DWORD PTR [ecx]
0054E9E2  85c9                           test   ecx,ecx
0054E9E4  7407                           je     0x54e9ed
0054E9E6  8b01                           mov    eax,DWORD PTR [ecx]
0054E9E8  8b5008                         mov    edx,DWORD PTR [eax+0x8]
0054E9EB  ffe2                           jmp    edx
0054E9ED  c3                             ret
0054E9EE  cc                             int3
0054E9EF  cc                             int3
0054E9F0  8b09                           mov    ecx,DWORD PTR [ecx]
0054E9F2  85c9                           test   ecx,ecx
0054E9F4  7407                           je     0x54e9fd
0054E9F6  8b01                           mov    eax,DWORD PTR [ecx]
0054E9F8  8b500c                         mov    edx,DWORD PTR [eax+0xc]
0054E9FB  ffe2                           jmp    edx
0054E9FD  c3                             ret
0054E9FE  cc                             int3
0054E9FF  cc                             int3
0054EA00  8b09                           mov    ecx,DWORD PTR [ecx]
0054EA02  85c9                           test   ecx,ecx
0054EA04  7407                           je     0x54ea0d
0054EA06  8b01                           mov    eax,DWORD PTR [ecx]
0054EA08  8b5020                         mov    edx,DWORD PTR [eax+0x20]
0054EA0B  ffe2                           jmp    edx
0054EA0D  b801000000                     mov    eax,0x1
0054EA12  c3                             ret

; keyframe_play [REUSED_STATE] 0x54e230..0x54e255
0054E230  8b410c                         mov    eax,DWORD PTR [ecx+0xc]
0054E233  2b4108                         sub    eax,DWORD PTR [ecx+0x8]
0054E236  a9fcffffff                     test   eax,0xfffffffc
0054E23B  7508                           jne    0x54e245
0054E23D  c7414000000000                 mov    DWORD PTR [ecx+0x40],0x0
0054E244  c3                             ret
0054E245  33c0                           xor    eax,eax
0054E247  894144                         mov    DWORD PTR [ecx+0x44],eax
0054E24A  89413c                         mov    DWORD PTR [ecx+0x3c],eax
0054E24D  c7414001000000                 mov    DWORD PTR [ecx+0x40],0x1
0054E254  c3                             ret

; keyframe_stop [CURRENT_JOIN] 0x54e260..0x54e268
0054E260  c7414000000000                 mov    DWORD PTR [ecx+0x40],0x0
0054E267  c3                             ret

; keyframe_tick [CURRENT_JOIN] 0x54e270..0x54e2b5
0054E270  56                             push   esi
0054E271  57                             push   edi
0054E272  8bf9                           mov    edi,ecx
0054E274  837f4000                       cmp    DWORD PTR [edi+0x40],0x0
0054E278  7430                           je     0x54e2aa
0054E27A  8b470c                         mov    eax,DWORD PTR [edi+0xc]
0054E27D  2b4708                         sub    eax,DWORD PTR [edi+0x8]
0054E280  c1f802                         sar    eax,0x2
0054E283  85c0                           test   eax,eax
0054E285  7418                           je     0x54e29f
0054E287  8b4f08                         mov    ecx,DWORD PTR [edi+0x8]
0054E28A  8b5481fc                       mov    edx,DWORD PTR [ecx+eax*4-0x4]
0054E28E  8b4224                         mov    eax,DWORD PTR [edx+0x24]
0054E291  3b4744                         cmp    eax,DWORD PTR [edi+0x44]
0054E294  7d09                           jge    0x54e29f
0054E296  c7474000000000                 mov    DWORD PTR [edi+0x40],0x0
0054E29D  eb0b                           jmp    0x54e2aa
0054E29F  8d4704                         lea    eax,[edi+0x4]
0054E2A2  e8e9942400                     call   0x797790
0054E2A7  ff4744                         inc    DWORD PTR [edi+0x44]
0054E2AA  8b17                           mov    edx,DWORD PTR [edi]
0054E2AC  8b4204                         mov    eax,DWORD PTR [edx+0x4]
0054E2AF  8bcf                           mov    ecx,edi
0054E2B1  5f                             pop    edi
0054E2B2  5e                             pop    esi
0054E2B3  ffe0                           jmp    eax

; keyframe_apply [CURRENT_JOIN] 0x54e080..0x54e22a
0054E080  55                             push   ebp
0054E081  8bec                           mov    ebp,esp
0054E083  6aff                           push   0xffffffff
0054E085  6896ed9200                     push   0x92ed96
0054E08A  64a100000000                   mov    eax,fs:0x0
0054E090  50                             push   eax
0054E091  53                             push   ebx
0054E092  56                             push   esi
0054E093  57                             push   edi
0054E094  a1201fd600                     mov    eax,ds:0xd61f20
0054E099  33c5                           xor    eax,ebp
0054E09B  50                             push   eax
0054E09C  8d45f4                         lea    eax,[ebp-0xc]
0054E09F  64a300000000                   mov    fs:0x0,eax
0054E0A5  8bf1                           mov    esi,ecx
0054E0A7  33ff                           xor    edi,edi
0054E0A9  397e40                         cmp    DWORD PTR [esi+0x40],edi
0054E0AC  0f8466010000                   je     0x54e218
0054E0B2  8b4e08                         mov    ecx,DWORD PTR [esi+0x8]
0054E0B5  8b460c                         mov    eax,DWORD PTR [esi+0xc]
0054E0B8  2bc1                           sub    eax,ecx
0054E0BA  c1f802                         sar    eax,0x2
0054E0BD  3bc7                           cmp    eax,edi
0054E0BF  7410                           je     0x54e0d1
0054E0C1  8b4481fc                       mov    eax,DWORD PTR [ecx+eax*4-0x4]
0054E0C5  8b4824                         mov    ecx,DWORD PTR [eax+0x24]
0054E0C8  3b4e44                         cmp    ecx,DWORD PTR [esi+0x44]
0054E0CB  0f8c47010000                   jl     0x54e218
0054E0D1  83cbff                         or     ebx,0xffffffff
0054E0D4  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
0054E0DB  751f                           jne    0x54e0fc
0054E0DD  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
0054E0E4  897dfc                         mov    DWORD PTR [ebp-0x4],edi
0054E0E7  e8f4ac2400                     call   0x798de0
0054E0EC  68e0d2bc00                     push   0xbcd2e0
0054E0F1  e824423400                     call   0x89231a
0054E0F6  83c404                         add    esp,0x4
0054E0F9  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0054E0FC  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
0054E103  a1e876fb00                     mov    eax,ds:0xfb76e8
0054E108  8b5618                         mov    edx,DWORD PTR [esi+0x18]
0054E10B  89500c                         mov    DWORD PTR [eax+0xc],edx
0054E10E  8b561c                         mov    edx,DWORD PTR [esi+0x1c]
0054E111  895010                         mov    DWORD PTR [eax+0x10],edx
0054E114  8b5620                         mov    edx,DWORD PTR [esi+0x20]
0054E117  8bc8                           mov    ecx,eax
0054E119  895014                         mov    DWORD PTR [eax+0x14],edx
0054E11C  89b9cc000000                   mov    DWORD PTR [ecx+0xcc],edi
0054E122  7523                           jne    0x54e147
0054E124  b801000000                     mov    eax,0x1
0054E129  0905e879fb00                   or     DWORD PTR ds:0xfb79e8,eax
0054E12F  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0054E132  e8a9ac2400                     call   0x798de0
0054E137  68e0d2bc00                     push   0xbcd2e0
0054E13C  e8d9413400                     call   0x89231a
0054E141  83c404                         add    esp,0x4
0054E144  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0054E147  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
0054E14E  a1e876fb00                     mov    eax,ds:0xfb76e8
0054E153  f30f104624                     movss  xmm0,DWORD PTR [esi+0x24]
0054E158  f30f114018                     movss  DWORD PTR [eax+0x18],xmm0
0054E15D  89b8cc000000                   mov    DWORD PTR [eax+0xcc],edi
0054E163  7523                           jne    0x54e188
0054E165  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
0054E16C  c745fc02000000                 mov    DWORD PTR [ebp-0x4],0x2
0054E173  e868ac2400                     call   0x798de0
0054E178  68e0d2bc00                     push   0xbcd2e0
0054E17D  e898413400                     call   0x89231a
0054E182  83c404                         add    esp,0x4
0054E185  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0054E188  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
0054E18F  a1e876fb00                     mov    eax,ds:0xfb76e8
0054E194  f30f104628                     movss  xmm0,DWORD PTR [esi+0x28]
0054E199  f30f114020                     movss  DWORD PTR [eax+0x20],xmm0
0054E19E  89b8cc000000                   mov    DWORD PTR [eax+0xcc],edi
0054E1A4  7523                           jne    0x54e1c9
0054E1A6  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
0054E1AD  c745fc03000000                 mov    DWORD PTR [ebp-0x4],0x3
0054E1B4  e827ac2400                     call   0x798de0
0054E1B9  68e0d2bc00                     push   0xbcd2e0
0054E1BE  e857413400                     call   0x89231a
0054E1C3  83c404                         add    esp,0x4
0054E1C6  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0054E1C9  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
0054E1D0  a1e876fb00                     mov    eax,ds:0xfb76e8
0054E1D5  f30f10462c                     movss  xmm0,DWORD PTR [esi+0x2c]
0054E1DA  f30f11401c                     movss  DWORD PTR [eax+0x1c],xmm0
0054E1DF  89b8cc000000                   mov    DWORD PTR [eax+0xcc],edi
0054E1E5  7520                           jne    0x54e207
0054E1E7  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
0054E1EE  c745fc04000000                 mov    DWORD PTR [ebp-0x4],0x4
0054E1F5  e8e6ab2400                     call   0x798de0
0054E1FA  68e0d2bc00                     push   0xbcd2e0
0054E1FF  e816413400                     call   0x89231a
0054E204  83c404                         add    esp,0x4
0054E207  a1e876fb00                     mov    eax,ds:0xfb76e8
0054E20C  d94630                         fld    DWORD PTR [esi+0x30]
0054E20F  d95824                         fstp   DWORD PTR [eax+0x24]
0054E212  89b8cc000000                   mov    DWORD PTR [eax+0xcc],edi
0054E218  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0054E21B  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0054E222  59                             pop    ecx
0054E223  5f                             pop    edi
0054E224  5e                             pop    esi
0054E225  5b                             pop    ebx
0054E226  8be5                           mov    esp,ebp
0054E228  5d                             pop    ebp
0054E229  c3                             ret

; keyframe_ended [CURRENT_JOIN] 0x54e310..0x54e33a
0054E310  83794000                       cmp    DWORD PTR [ecx+0x40],0x0
0054E314  741e                           je     0x54e334
0054E316  8b5108                         mov    edx,DWORD PTR [ecx+0x8]
0054E319  8b410c                         mov    eax,DWORD PTR [ecx+0xc]
0054E31C  2bc2                           sub    eax,edx
0054E31E  c1f802                         sar    eax,0x2
0054E321  85c0                           test   eax,eax
0054E323  740c                           je     0x54e331
0054E325  8b4482fc                       mov    eax,DWORD PTR [edx+eax*4-0x4]
0054E329  8b5024                         mov    edx,DWORD PTR [eax+0x24]
0054E32C  3b5144                         cmp    edx,DWORD PTR [ecx+0x44]
0054E32F  7c03                           jl     0x54e334
0054E331  33c0                           xor    eax,eax
0054E333  c3                             ret
0054E334  b801000000                     mov    eax,0x1
0054E339  c3                             ret

; camera_attach [REUSED_ENTRY] 0x563830..0x5638f2
00563830  55                             push   ebp
00563831  8bec                           mov    ebp,esp
00563833  83e4f8                         and    esp,0xfffffff8
00563836  6aff                           push   0xffffffff
00563838  68ccaa9300                     push   0x93aacc
0056383D  64a100000000                   mov    eax,fs:0x0
00563843  50                             push   eax
00563844  83ec08                         sub    esp,0x8
00563847  53                             push   ebx
00563848  a1201fd600                     mov    eax,ds:0xd61f20
0056384D  33c4                           xor    eax,esp
0056384F  50                             push   eax
00563850  8d442410                       lea    eax,[esp+0x10]
00563854  64a300000000                   mov    fs:0x0,eax
0056385A  bb01000000                     mov    ebx,0x1
0056385F  841d1c76fb00                   test   BYTE PTR ds:0xfb761c,bl
00563865  7528                           jne    0x56388f
00563867  091d1c76fb00                   or     DWORD PTR ds:0xfb761c,ebx
0056386D  c744241800000000               mov    DWORD PTR [esp+0x18],0x0
00563875  e8d6aefeff                     call   0x54e750
0056387A  6860d2bc00                     push   0xbcd260
0056387F  e896ea3200                     call   0x89231a
00563884  83c404                         add    esp,0x4
00563887  c7442418ffffffff               mov    DWORD PTR [esp+0x18],0xffffffff
0056388F  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
00563892  b96c76fb00                     mov    ecx,0xfb766c
00563897  890d2076fb00                   mov    DWORD PTR ds:0xfb7620,ecx
0056389D  a37076fb00                     mov    ds:0xfb7670,eax
005638A2  841d1c76fb00                   test   BYTE PTR ds:0xfb761c,bl
005638A8  752e                           jne    0x5638d8
005638AA  091d1c76fb00                   or     DWORD PTR ds:0xfb761c,ebx
005638B0  895c2418                       mov    DWORD PTR [esp+0x18],ebx
005638B4  e897aefeff                     call   0x54e750
005638B9  6860d2bc00                     push   0xbcd260
005638BE  e857ea3200                     call   0x89231a
005638C3  c744241cffffffff               mov    DWORD PTR [esp+0x1c],0xffffffff
005638CB  8b0d2076fb00                   mov    ecx,DWORD PTR ds:0xfb7620
005638D1  83c404                         add    esp,0x4
005638D4  85c9                           test   ecx,ecx
005638D6  7407                           je     0x5638df
005638D8  8b11                           mov    edx,DWORD PTR [ecx]
005638DA  8b4208                         mov    eax,DWORD PTR [edx+0x8]
005638DD  ffd0                           call   eax
005638DF  8b4c2410                       mov    ecx,DWORD PTR [esp+0x10]
005638E3  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
005638EA  59                             pop    ecx
005638EB  5b                             pop    ebx
005638EC  8be5                           mov    esp,ebp
005638EE  5d                             pop    ebp
005638EF  c20400                         ret    0x4

; camera_detach [CURRENT_JOIN] 0x563900..0x56396e
00563900  55                             push   ebp
00563901  8bec                           mov    ebp,esp
00563903  83e4f8                         and    esp,0xfffffff8
00563906  6aff                           push   0xffffffff
00563908  68dea99300                     push   0x93a9de
0056390D  64a100000000                   mov    eax,fs:0x0
00563913  50                             push   eax
00563914  51                             push   ecx
00563915  a1201fd600                     mov    eax,ds:0xd61f20
0056391A  33c4                           xor    eax,esp
0056391C  50                             push   eax
0056391D  8d442408                       lea    eax,[esp+0x8]
00563921  64a300000000                   mov    fs:0x0,eax
00563927  b801000000                     mov    eax,0x1
0056392C  84051c76fb00                   test   BYTE PTR ds:0xfb761c,al
00563932  7520                           jne    0x563954
00563934  09051c76fb00                   or     DWORD PTR ds:0xfb761c,eax
0056393A  c744241000000000               mov    DWORD PTR [esp+0x10],0x0
00563942  e809aefeff                     call   0x54e750
00563947  6860d2bc00                     push   0xbcd260
0056394C  e8c9e93200                     call   0x89231a
00563951  83c404                         add    esp,0x4
00563954  c7052076fb0000000000           mov    DWORD PTR ds:0xfb7620,0x0
0056395E  8b4c2408                       mov    ecx,DWORD PTR [esp+0x8]
00563962  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00563969  59                             pop    ecx
0056396A  8be5                           mov    esp,ebp
0056396C  5d                             pop    ebp
0056396D  c3                             ret

; camera_attach_stop [CURRENT_JOIN] 0x54e570..0x54e578
0054E570  c7413801000000                 mov    DWORD PTR [ecx+0x38],0x1
0054E577  c3                             ret

; camera_attach_apply [CURRENT_JOIN] 0x54e340..0x54e3b4
0054E340  55                             push   ebp
0054E341  8bec                           mov    ebp,esp
0054E343  6aff                           push   0xffffffff
0054E345  682eed9200                     push   0x92ed2e
0054E34A  64a100000000                   mov    eax,fs:0x0
0054E350  50                             push   eax
0054E351  56                             push   esi
0054E352  a1201fd600                     mov    eax,ds:0xd61f20
0054E357  33c5                           xor    eax,ebp
0054E359  50                             push   eax
0054E35A  8d45f4                         lea    eax,[ebp-0xc]
0054E35D  64a300000000                   mov    fs:0x0,eax
0054E363  8bf1                           mov    esi,ecx
0054E365  837e3800                       cmp    DWORD PTR [esi+0x38],0x0
0054E369  7539                           jne    0x54e3a4
0054E36B  b801000000                     mov    eax,0x1
0054E370  8405e879fb00                   test   BYTE PTR ds:0xfb79e8,al
0054E376  751f                           jne    0x54e397
0054E378  0905e879fb00                   or     DWORD PTR ds:0xfb79e8,eax
0054E37E  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0054E385  e856aa2400                     call   0x798de0
0054E38A  68e0d2bc00                     push   0xbcd2e0
0054E38F  e8863f3400                     call   0x89231a
0054E394  83c404                         add    esp,0x4
0054E397  a1e876fb00                     mov    eax,ds:0xfb76e8
0054E39C  8d4e0c                         lea    ecx,[esi+0xc]
0054E39F  e8cc9f2400                     call   0x798370
0054E3A4  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0054E3A7  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0054E3AE  59                             pop    ecx
0054E3AF  5e                             pop    esi
0054E3B0  8be5                           mov    esp,ebp
0054E3B2  5d                             pop    ebp
0054E3B3  c3                             ret

; camera_attach_tick [CURRENT_JOIN] 0x54e580..0x54e735
0054E580  55                             push   ebp
0054E581  8bec                           mov    ebp,esp
0054E583  83e4f8                         and    esp,0xfffffff8
0054E586  6aff                           push   0xffffffff
0054E588  6826af9300                     push   0x93af26
0054E58D  64a100000000                   mov    eax,fs:0x0
0054E593  50                             push   eax
0054E594  83ec48                         sub    esp,0x48
0054E597  53                             push   ebx
0054E598  56                             push   esi
0054E599  57                             push   edi
0054E59A  a1201fd600                     mov    eax,ds:0xd61f20
0054E59F  33c4                           xor    eax,esp
0054E5A1  50                             push   eax
0054E5A2  8d442458                       lea    eax,[esp+0x58]
0054E5A6  64a300000000                   mov    fs:0x0,eax
0054E5AC  8bd9                           mov    ebx,ecx
0054E5AE  837b3800                       cmp    DWORD PTR [ebx+0x38],0x0
0054E5B2  0f8568010000                   jne    0x54e720
0054E5B8  f605b873fb0001                 test   BYTE PTR ds:0xfb73b8,0x1
0054E5BF  be01000000                     mov    esi,0x1
0054E5C4  7528                           jne    0x54e5ee
0054E5C6  0935b873fb00                   or     DWORD PTR ds:0xfb73b8,esi
0054E5CC  c744246000000000               mov    DWORD PTR [esp+0x60],0x0
0054E5D4  e8971b0100                     call   0x560170
0054E5D9  6810d1bc00                     push   0xbcd110
0054E5DE  e8373d3400                     call   0x89231a
0054E5E3  83c404                         add    esp,0x4
0054E5E6  c7442460ffffffff               mov    DWORD PTR [esp+0x60],0xffffffff
0054E5EE  8b4304                         mov    eax,DWORD PTR [ebx+0x4]
0054E5F1  8d4c2410                       lea    ecx,[esp+0x10]
0054E5F5  89442410                       mov    DWORD PTR [esp+0x10],eax
0054E5F9  51                             push   ecx
0054E5FA  8d442418                       lea    eax,[esp+0x18]
0054E5FE  b9d873fb00                     mov    ecx,0xfb73d8
0054E603  e8f8082e00                     call   0x82ef00
0054E608  8b442414                       mov    eax,DWORD PTR [esp+0x14]
0054E60C  3b05dc73fb00                   cmp    eax,DWORD PTR ds:0xfb73dc
0054E612  0f8408010000                   je     0x54e720
0054E618  8b4010                         mov    eax,DWORD PTR [eax+0x10]
0054E61B  85c0                           test   eax,eax
0054E61D  0f84fd000000                   je     0x54e720
0054E623  8d4c2414                       lea    ecx,[esp+0x14]
0054E627  e8a4ddf4ff                     call   0x49c3d0
0054E62C  89742460                       mov    DWORD PTR [esp+0x60],esi
0054E630  8b442414                       mov    eax,DWORD PTR [esp+0x14]
0054E634  85c0                           test   eax,eax
0054E636  0f84d3000000                   je     0x54e70f
0054E63C  0f57c0                         xorps  xmm0,xmm0
0054E63F  8b401c                         mov    eax,DWORD PTR [eax+0x1c]
0054E642  8b4b08                         mov    ecx,DWORD PTR [ebx+0x8]
0054E645  f30f11442428                   movss  DWORD PTR [esp+0x28],xmm0
0054E64B  f30f1144242c                   movss  DWORD PTR [esp+0x2c],xmm0
0054E651  f30f11442430                   movss  DWORD PTR [esp+0x30],xmm0
0054E657  f30f11442434                   movss  DWORD PTR [esp+0x34],xmm0
0054E65D  f30f11442438                   movss  DWORD PTR [esp+0x38],xmm0
0054E663  f30f1144243c                   movss  DWORD PTR [esp+0x3c],xmm0
0054E669  f30f1005c056c400               movss  xmm0,DWORD PTR ds:0xc456c0
0054E671  f30f11442440                   movss  DWORD PTR [esp+0x40],xmm0
0054E677  f30f11442444                   movss  DWORD PTR [esp+0x44],xmm0
0054E67D  f30f11442448                   movss  DWORD PTR [esp+0x48],xmm0
0054E683  f30f1144244c                   movss  DWORD PTR [esp+0x4c],xmm0
0054E689  89742450                       mov    DWORD PTR [esp+0x50],esi
0054E68D  85c0                           test   eax,eax
0054E68F  7409                           je     0x54e69a
0054E691  8d7c2428                       lea    edi,[esp+0x28]
0054E695  e8a64c2800                     call   0x7d3340
0054E69A  8d542420                       lea    edx,[esp+0x20]
0054E69E  52                             push   edx
0054E69F  8d442420                       lea    eax,[esp+0x20]
0054E6A3  50                             push   eax
0054E6A4  8d4c242c                       lea    ecx,[esp+0x2c]
0054E6A8  51                             push   ecx
0054E6A9  8d742440                       lea    esi,[esp+0x40]
0054E6AD  e8eedc2700                     call   0x7cc3a0
0054E6B2  8b542434                       mov    edx,DWORD PTR [esp+0x34]
0054E6B6  8b442438                       mov    eax,DWORD PTR [esp+0x38]
0054E6BA  8b4c243c                       mov    ecx,DWORD PTR [esp+0x3c]
0054E6BE  0f57c0                         xorps  xmm0,xmm0
0054E6C1  89530c                         mov    DWORD PTR [ebx+0xc],edx
0054E6C4  8b542428                       mov    edx,DWORD PTR [esp+0x28]
0054E6C8  894310                         mov    DWORD PTR [ebx+0x10],eax
0054E6CB  8b44242c                       mov    eax,DWORD PTR [esp+0x2c]
0054E6CF  894b14                         mov    DWORD PTR [ebx+0x14],ecx
0054E6D2  8b4c2430                       mov    ecx,DWORD PTR [esp+0x30]
0054E6D6  895318                         mov    DWORD PTR [ebx+0x18],edx
0054E6D9  8b13                           mov    edx,DWORD PTR [ebx]
0054E6DB  f30f114328                     movss  DWORD PTR [ebx+0x28],xmm0
0054E6E0  f30f114324                     movss  DWORD PTR [ebx+0x24],xmm0
0054E6E5  f30f1005d058c500               movss  xmm0,DWORD PTR ds:0xc558d0
0054E6ED  89431c                         mov    DWORD PTR [ebx+0x1c],eax
0054E6F0  8b4204                         mov    eax,DWORD PTR [edx+0x4]
0054E6F3  894b20                         mov    DWORD PTR [ebx+0x20],ecx
0054E6F6  f30f11432c                     movss  DWORD PTR [ebx+0x2c],xmm0
0054E6FB  f30f1005085ec500               movss  xmm0,DWORD PTR ds:0xc55e08
0054E703  83c40c                         add    esp,0xc
0054E706  8bcb                           mov    ecx,ebx
0054E708  f30f114334                     movss  DWORD PTR [ebx+0x34],xmm0
0054E70D  ffd0                           call   eax
0054E70F  8d442414                       lea    eax,[esp+0x14]
0054E713  c7442460ffffffff               mov    DWORD PTR [esp+0x60],0xffffffff
0054E71B  e830292500                     call   0x7a1050
0054E720  8b4c2458                       mov    ecx,DWORD PTR [esp+0x58]
0054E724  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0054E72B  59                             pop    ecx
0054E72C  5f                             pop    edi
0054E72D  5e                             pop    esi
0054E72E  5b                             pop    ebx
0054E72F  8be5                           mov    esp,ebp
0054E731  5d                             pop    ebp
0054E732  c20400                         ret    0x4

; camera_frame_edge [CURRENT_JOIN] 0x491ca7..0x491cd8
00491CA7  39b7ccbf0000                   cmp    DWORD PTR [edi+0xbfcc],esi
00491CAD  7554                           jne    0x491d03
00491CAF  e8acd3f7ff                     call   0x40f060
00491CB4  8bc8                           mov    ecx,eax
00491CB6  e8a5e30400                     call   0x4e0060
00491CBB  e8a07fffff                     call   0x489c60
00491CC0  50                             push   eax
00491CC1  e86a78ffff                     call   0x489530
00491CC6  e86524faff                     call   0x434130
00491CCB  8b08                           mov    ecx,DWORD PTR [eax]
00491CCD  3bce                           cmp    ecx,esi
00491CCF  7407                           je     0x491cd8
00491CD1  8b01                           mov    eax,DWORD PTR [ecx]
00491CD3  8b5014                         mov    edx,DWORD PTR [eax+0x14]
00491CD6  ffd2                           call   edx

; world_visibility_off [CURRENT_JOIN] 0x5647a0..0x56480e
005647A0  55                             push   ebp
005647A1  8bec                           mov    ebp,esp
005647A3  83e4f8                         and    esp,0xfffffff8
005647A6  6aff                           push   0xffffffff
005647A8  68fe6e9300                     push   0x936efe
005647AD  64a100000000                   mov    eax,fs:0x0
005647B3  50                             push   eax
005647B4  83ec08                         sub    esp,0x8
005647B7  53                             push   ebx
005647B8  a1201fd600                     mov    eax,ds:0xd61f20
005647BD  33c4                           xor    eax,esp
005647BF  50                             push   eax
005647C0  8d442410                       lea    eax,[esp+0x10]
005647C4  64a300000000                   mov    fs:0x0,eax
005647CA  bb01000000                     mov    ebx,0x1
005647CF  841d2cb2fa00                   test   BYTE PTR ds:0xfab22c,bl
005647D5  7520                           jne    0x5647f7
005647D7  091d2cb2fa00                   or     DWORD PTR ds:0xfab22c,ebx
005647DD  c744241800000000               mov    DWORD PTR [esp+0x18],0x0
005647E5  e8a6a4f7ff                     call   0x4dec90
005647EA  6830cebc00                     push   0xbcce30
005647EF  e826db3200                     call   0x89231a
005647F4  83c404                         add    esp,0x4
005647F7  891dd8b1fa00                   mov    DWORD PTR ds:0xfab1d8,ebx
005647FD  8b4c2410                       mov    ecx,DWORD PTR [esp+0x10]
00564801  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00564808  59                             pop    ecx
00564809  5b                             pop    ebx
0056480A  8be5                           mov    esp,ebp
0056480C  5d                             pop    ebp
0056480D  c3                             ret

; world_visibility_on [CURRENT_JOIN] 0x564810..0x56487e
00564810  55                             push   ebp
00564811  8bec                           mov    ebp,esp
00564813  83e4f8                         and    esp,0xfffffff8
00564816  6aff                           push   0xffffffff
00564818  68ee619400                     push   0x9461ee
0056481D  64a100000000                   mov    eax,fs:0x0
00564823  50                             push   eax
00564824  51                             push   ecx
00564825  a1201fd600                     mov    eax,ds:0xd61f20
0056482A  33c4                           xor    eax,esp
0056482C  50                             push   eax
0056482D  8d442408                       lea    eax,[esp+0x8]
00564831  64a300000000                   mov    fs:0x0,eax
00564837  b801000000                     mov    eax,0x1
0056483C  84052cb2fa00                   test   BYTE PTR ds:0xfab22c,al
00564842  7520                           jne    0x564864
00564844  09052cb2fa00                   or     DWORD PTR ds:0xfab22c,eax
0056484A  c744241000000000               mov    DWORD PTR [esp+0x10],0x0
00564852  e839a4f7ff                     call   0x4dec90
00564857  6830cebc00                     push   0xbcce30
0056485C  e8b9da3200                     call   0x89231a
00564861  83c404                         add    esp,0x4
00564864  c705d8b1fa0000000000           mov    DWORD PTR ds:0xfab1d8,0x0
0056486E  8b4c2408                       mov    ecx,DWORD PTR [esp+0x8]
00564872  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00564879  59                             pop    ecx
0056487A  8be5                           mov    esp,ebp
0056487C  5d                             pop    ebp
0056487D  c3                             ret

; world_owner [REUSED_RECEIVER] 0x40f060..0x40f0c9
0040F060  55                             push   ebp
0040F061  8bec                           mov    ebp,esp
0040F063  83e4f8                         and    esp,0xfffffff8
0040F066  6aff                           push   0xffffffff
0040F068  68ee619400                     push   0x9461ee
0040F06D  64a100000000                   mov    eax,fs:0x0
0040F073  50                             push   eax
0040F074  51                             push   ecx
0040F075  a1201fd600                     mov    eax,ds:0xd61f20
0040F07A  33c4                           xor    eax,esp
0040F07C  50                             push   eax
0040F07D  8d442408                       lea    eax,[esp+0x8]
0040F081  64a300000000                   mov    fs:0x0,eax
0040F087  b801000000                     mov    eax,0x1
0040F08C  84052cb2fa00                   test   BYTE PTR ds:0xfab22c,al
0040F092  7520                           jne    0x40f0b4
0040F094  09052cb2fa00                   or     DWORD PTR ds:0xfab22c,eax
0040F09A  c744241000000000               mov    DWORD PTR [esp+0x10],0x0
0040F0A2  e8e9fb0c00                     call   0x4dec90
0040F0A7  6830cebc00                     push   0xbcce30
0040F0AC  e869324800                     call   0x89231a
0040F0B1  83c404                         add    esp,0x4
0040F0B4  b830b1fa00                     mov    eax,0xfab130
0040F0B9  8b4c2408                       mov    ecx,DWORD PTR [esp+0x8]
0040F0BD  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0040F0C4  59                             pop    ecx
0040F0C5  8be5                           mov    esp,ebp
0040F0C7  5d                             pop    ebp
0040F0C8  c3                             ret

; world_animation_frame [CURRENT_JOIN] 0x492599..0x4925aa
00492599  d9450c                         fld    DWORD PTR [ebp+0xc]
0049259C  51                             push   ecx
0049259D  d91c24                         fstp   DWORD PTR [esp]
004925A0  6830b1fa00                     push   0xfab130
004925A5  e856dc0400                     call   0x4e0200

; world_draw_frame [CURRENT_JOIN] 0x492b19..0x492b25
00492B19  e842c5f7ff                     call   0x40f060
00492B1E  8bf0                           mov    esi,eax
00492B20  e81bda0400                     call   0x4e0540

; world_draw [CURRENT_JOIN] 0x4e0540..0x4e0584
004E0540  55                             push   ebp
004E0541  8bec                           mov    ebp,esp
004E0543  51                             push   ecx
004E0544  8b0d38a8fb00                   mov    ecx,DWORD PTR ds:0xfba838
004E054A  8b01                           mov    eax,DWORD PTR [ecx]
004E054C  8b501c                         mov    edx,DWORD PTR [eax+0x1c]
004E054F  ffd2                           call   edx
004E0551  83bea800000000                 cmp    DWORD PTR [esi+0xa8],0x0
004E0558  7524                           jne    0x4e057e
004E055A  8b0da4a7fb00                   mov    ecx,DWORD PTR ds:0xfba7a4
004E0560  8b01                           mov    eax,DWORD PTR [ecx]
004E0562  8b5034                         mov    edx,DWORD PTR [eax+0x34]
004E0565  ffd2                           call   edx
004E0567  8b460c                         mov    eax,DWORD PTR [esi+0xc]
004E056A  8b08                           mov    ecx,DWORD PTR [eax]
004E056C  c645fc00                       mov    BYTE PTR [ebp-0x4],0x0
004E0570  8b55fc                         mov    edx,DWORD PTR [ebp-0x4]
004E0573  52                             push   edx
004E0574  50                             push   eax
004E0575  51                             push   ecx
004E0576  e8f50e0000                     call   0x4e1470
004E057B  83c40c                         add    esp,0xc
004E057E  33c0                           xor    eax,eax
004E0580  8be5                           mov    esp,ebp
004E0582  5d                             pop    ebp
004E0583  c3                             ret

; world_animate [CURRENT_JOIN] 0x4e0200..0x4e051c
004E0200  55                             push   ebp
004E0201  8bec                           mov    ebp,esp
004E0203  6aff                           push   0xffffffff
004E0205  68c4439400                     push   0x9443c4
004E020A  64a100000000                   mov    eax,fs:0x0
004E0210  50                             push   eax
004E0211  83ec0c                         sub    esp,0xc
004E0214  53                             push   ebx
004E0215  56                             push   esi
004E0216  57                             push   edi
004E0217  a1201fd600                     mov    eax,ds:0xd61f20
004E021C  33c5                           xor    eax,ebp
004E021E  50                             push   eax
004E021F  8d45f4                         lea    eax,[ebp-0xc]
004E0222  64a300000000                   mov    fs:0x0,eax
004E0228  f605600ffc0001                 test   BYTE PTR ds:0xfc0f60,0x1
004E022F  be01000000                     mov    esi,0x1
004E0234  7527                           jne    0x4e025d
004E0236  0935600ffc00                   or     DWORD PTR ds:0xfc0f60,esi
004E023C  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
004E0243  e8f8cc2b00                     call   0x79cf40
004E0248  6880dbbc00                     push   0xbcdb80
004E024D  e8c8203b00                     call   0x89231a
004E0252  83c404                         add    esp,0x4
004E0255  83cfff                         or     edi,0xffffffff
004E0258  897dfc                         mov    DWORD PTR [ebp-0x4],edi
004E025B  eb03                           jmp    0x4e0260
004E025D  83cfff                         or     edi,0xffffffff
004E0260  b9900efc00                     mov    ecx,0xfc0e90
004E0265  e8a6d82b00                     call   0x79db10
004E026A  d9450c                         fld    DWORD PTR [ebp+0xc]
004E026D  8b0d38a8fb00                   mov    ecx,DWORD PTR ds:0xfba838
004E0273  8b01                           mov    eax,DWORD PTR [ecx]
004E0275  8b5018                         mov    edx,DWORD PTR [eax+0x18]
004E0278  51                             push   ecx
004E0279  d91c24                         fstp   DWORD PTR [esp]
004E027C  ffd2                           call   edx
004E027E  f30f10450c                     movss  xmm0,DWORD PTR [ebp+0xc]
004E0283  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
004E0286  0f57c9                         xorps  xmm1,xmm1
004E0289  f30f1145f0                     movss  DWORD PTR [ebp-0x10],xmm0
004E028E  f30f1083ac000000               movss  xmm0,DWORD PTR [ebx+0xac]
004E0296  0f2fc1                         comiss xmm0,xmm1
004E0299  f30f1145ec                     movss  DWORD PTR [ebp-0x14],xmm0
004E029E  7709                           ja     0x4e02a9
004E02A0  83bbb000000000                 cmp    DWORD PTR [ebx+0xb0],0x0
004E02A7  742d                           je     0x4e02d6
004E02A9  d9450c                         fld    DWORD PTR [ebp+0xc]
004E02AC  dd059058c500                   fld    QWORD PTR ds:0xc55890
004E02B2  d8c9                           fmul   st,st(1)
004E02B4  d95df0                         fstp   DWORD PTR [ebp-0x10]
004E02B7  d86dec                         fsubr  DWORD PTR [ebp-0x14]
004E02BA  d95dec                         fstp   DWORD PTR [ebp-0x14]
004E02BD  d945ec                         fld    DWORD PTR [ebp-0x14]
004E02C0  d993ac000000                   fst    DWORD PTR [ebx+0xac]
004E02C6  d9ee                           fldz
004E02C8  dff1                           fcomip st,st(1)
004E02CA  ddd8                           fstp   st(0)
004E02CC  7208                           jb     0x4e02d6
004E02CE  f30f118bac000000               movss  DWORD PTR [ebx+0xac],xmm1
004E02D6  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
004E02DD  f30f1045f0                     movss  xmm0,DWORD PTR [ebp-0x10]
004E02E2  c745e82ccfc000                 mov    DWORD PTR [ebp-0x18],0xc0cf2c
004E02E9  f30f1145ec                     movss  DWORD PTR [ebp-0x14],xmm0
004E02EE  751e                           jne    0x4e030e
004E02F0  0935e879fb00                   or     DWORD PTR ds:0xfb79e8,esi
004E02F6  8975fc                         mov    DWORD PTR [ebp-0x4],esi
004E02F9  e8e28a2b00                     call   0x798de0
004E02FE  68e0d2bc00                     push   0xbcd2e0
004E0303  e812203b00                     call   0x89231a
004E0308  83c404                         add    esp,0x4
004E030B  897dfc                         mov    DWORD PTR [ebp-0x4],edi
004E030E  8d45e8                         lea    eax,[ebp-0x18]
004E0311  a3e479fb00                     mov    ds:0xfb79e4,eax
004E0316  8b430c                         mov    eax,DWORD PTR [ebx+0xc]
004E0319  8b30                           mov    esi,DWORD PTR [eax]
004E031B  3bf0                           cmp    esi,eax
004E031D  0f84ed000000                   je     0x4e0410
004E0323  bb02000000                     mov    ebx,0x2
004E0328  eb06                           jmp    0x4e0330
004E032A  8d9b00000000                   lea    ebx,[ebx+0x0]
004E0330  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
004E0337  751f                           jne    0x4e0358
004E0339  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
004E0340  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
004E0343  e8988a2b00                     call   0x798de0
004E0348  68e0d2bc00                     push   0xbcd2e0
004E034D  e8c81f3b00                     call   0x89231a
004E0352  83c404                         add    esp,0x4
004E0355  897dfc                         mov    DWORD PTR [ebp-0x4],edi
004E0358  8b0de079fb00                   mov    ecx,DWORD PTR ds:0xfb79e0
004E035E  8b4610                         mov    eax,DWORD PTR [esi+0x10]
004E0361  8b15d079fb00                   mov    edx,DWORD PTR ds:0xfb79d0
004E0367  8d0c49                         lea    ecx,[ecx+ecx*2]
004E036A  89448a08                       mov    DWORD PTR [edx+ecx*4+0x8],eax
004E036E  a1e079fb00                     mov    eax,ds:0xfb79e0
004E0373  0fb60dad79fb00                 movzx  ecx,BYTE PTR ds:0xfb79ad
004E037A  40                             inc    eax
004E037B  a3e079fb00                     mov    ds:0xfb79e0,eax
004E0380  3bc1                           cmp    eax,ecx
004E0382  7539                           jne    0x4e03bd
004E0384  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
004E038B  7523                           jne    0x4e03b0
004E038D  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
004E0394  c745fc03000000                 mov    DWORD PTR [ebp-0x4],0x3
004E039B  e8408a2b00                     call   0x798de0
004E03A0  68e0d2bc00                     push   0xbcd2e0
004E03A5  e8701f3b00                     call   0x89231a
004E03AA  83c404                         add    esp,0x4
004E03AD  897dfc                         mov    DWORD PTR [ebp-0x4],edi
004E03B0  bfac79fb00                     mov    edi,0xfb79ac
004E03B5  e836e12000                     call   0x6ee4f0
004E03BA  83cfff                         or     edi,0xffffffff
004E03BD  807e1500                       cmp    BYTE PTR [esi+0x15],0x0
004E03C1  753f                           jne    0x4e0402
004E03C3  8b4608                         mov    eax,DWORD PTR [esi+0x8]
004E03C6  80781500                       cmp    BYTE PTR [eax+0x15],0x0
004E03CA  7516                           jne    0x4e03e2
004E03CC  8bf0                           mov    esi,eax
004E03CE  8b06                           mov    eax,DWORD PTR [esi]
004E03D0  80781500                       cmp    BYTE PTR [eax+0x15],0x0
004E03D4  752c                           jne    0x4e0402
004E03D6  8bf0                           mov    esi,eax
004E03D8  8b06                           mov    eax,DWORD PTR [esi]
004E03DA  80781500                       cmp    BYTE PTR [eax+0x15],0x0
004E03DE  74f6                           je     0x4e03d6
004E03E0  eb20                           jmp    0x4e0402
004E03E2  8b4604                         mov    eax,DWORD PTR [esi+0x4]
004E03E5  80781500                       cmp    BYTE PTR [eax+0x15],0x0
004E03E9  7515                           jne    0x4e0400
004E03EB  eb03                           jmp    0x4e03f0
004E03ED  8d4900                         lea    ecx,[ecx+0x0]
004E03F0  3b7008                         cmp    esi,DWORD PTR [eax+0x8]
004E03F3  750b                           jne    0x4e0400
004E03F5  8bf0                           mov    esi,eax
004E03F7  8b4004                         mov    eax,DWORD PTR [eax+0x4]
004E03FA  80781500                       cmp    BYTE PTR [eax+0x15],0x0
004E03FE  74f0                           je     0x4e03f0
004E0400  8bf0                           mov    esi,eax
004E0402  8b5508                         mov    edx,DWORD PTR [ebp+0x8]
004E0405  3b720c                         cmp    esi,DWORD PTR [edx+0xc]
004E0408  0f8522ffffff                   jne    0x4e0330
004E040E  8bda                           mov    ebx,edx
004E0410  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
004E0417  7523                           jne    0x4e043c
004E0419  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
004E0420  c745fc04000000                 mov    DWORD PTR [ebp-0x4],0x4
004E0427  e8b4892b00                     call   0x798de0
004E042C  68e0d2bc00                     push   0xbcd2e0
004E0431  e8e41e3b00                     call   0x89231a
004E0436  83c404                         add    esp,0x4
004E0439  897dfc                         mov    DWORD PTR [ebp-0x4],edi
004E043C  a1e079fb00                     mov    eax,ds:0xfb79e0
004E0441  85c0                           test   eax,eax
004E0443  7438                           je     0x4e047d
004E0445  33f6                           xor    esi,esi
004E0447  85c0                           test   eax,eax
004E0449  7421                           je     0x4e046c
004E044B  8b3dd020bd00                   mov    edi,DWORD PTR ds:0xbd20d0
004E0451  a1b079fb00                     mov    eax,ds:0xfb79b0
004E0456  8b0cb0                         mov    ecx,DWORD PTR [eax+esi*4]
004E0459  51                             push   ecx
004E045A  ffd7                           call   edi
004E045C  a1e079fb00                     mov    eax,ds:0xfb79e0
004E0461  46                             inc    esi
004E0462  3bf0                           cmp    esi,eax
004E0464  72eb                           jb     0x4e0451
004E0466  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
004E0469  83cfff                         or     edi,0xffffffff
004E046C  8b15c079fb00                   mov    edx,DWORD PTR ds:0xfb79c0
004E0472  57                             push   edi
004E0473  6a01                           push   0x1
004E0475  52                             push   edx
004E0476  50                             push   eax
004E0477  ff15b422bd00                   call   DWORD PTR ds:0xbd22b4
004E047D  33c0                           xor    eax,eax
004E047F  f60500b1fa0001                 test   BYTE PTR ds:0xfab100,0x1
004E0486  a3e079fb00                     mov    ds:0xfb79e0,eax
004E048B  a3e479fb00                     mov    ds:0xfb79e4,eax
004E0490  7523                           jne    0x4e04b5
004E0492  830d00b1fa0001                 or     DWORD PTR ds:0xfab100,0x1
004E0499  c745fc05000000                 mov    DWORD PTR [ebp-0x4],0x5
004E04A0  e8fbd1fbff                     call   0x49d6a0
004E04A5  6820cebc00                     push   0xbcce20
004E04AA  e86b1e3b00                     call   0x89231a
004E04AF  83c404                         add    esp,0x4
004E04B2  897dfc                         mov    DWORD PTR [ebp-0x4],edi
004E04B5  8b0da4a7fb00                   mov    ecx,DWORD PTR ds:0xfba7a4
004E04BB  8b01                           mov    eax,DWORD PTR [ecx]
004E04BD  8b5020                         mov    edx,DWORD PTR [eax+0x20]
004E04C0  ffd2                           call   edx
004E04C2  85c0                           test   eax,eax
004E04C4  742c                           je     0x4e04f2
004E04C6  a1a4a7fb00                     mov    eax,ds:0xfba7a4
004E04CB  83787c00                       cmp    DWORD PTR [eax+0x7c],0x0
004E04CF  7521                           jne    0x4e04f2
004E04D1  a11813fb00                     mov    eax,ds:0xfb1318
004E04D6  8b881cc00000                   mov    ecx,DWORD PTR [eax+0xc01c]
004E04DC  d1e9                           shr    ecx,1
004E04DE  f6c101                         test   cl,0x1
004E04E1  750f                           jne    0x4e04f2
004E04E3  f6801cc0000001                 test   BYTE PTR [eax+0xc01c],0x1
004E04EA  7506                           jne    0x4e04f2
004E04EC  53                             push   ebx
004E04ED  e8de010000                     call   0x4e06d0
004E04F2  8b0da4a7fb00                   mov    ecx,DWORD PTR ds:0xfba7a4
004E04F8  d9450c                         fld    DWORD PTR [ebp+0xc]
004E04FB  8b11                           mov    edx,DWORD PTR [ecx]
004E04FD  8b4230                         mov    eax,DWORD PTR [edx+0x30]
004E0500  51                             push   ecx
004E0501  d91c24                         fstp   DWORD PTR [esp]
004E0504  ffd0                           call   eax
004E0506  33c0                           xor    eax,eax
004E0508  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
004E050B  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
004E0512  59                             pop    ecx
004E0513  5f                             pop    edi
004E0514  5e                             pop    esi
004E0515  5b                             pop    ebx
004E0516  8be5                           mov    esp,ebp
004E0518  5d                             pop    ebp
004E0519  c20800                         ret    0x8

; world_animation_executor [CURRENT_JOIN] 0x4e0520..0x4e053f
004E0520  55                             push   ebp
004E0521  8bec                           mov    ebp,esp
004E0523  8bc1                           mov    eax,ecx
004E0525  8b4d08                         mov    ecx,DWORD PTR [ebp+0x8]
004E0528  d94004                         fld    DWORD PTR [eax+0x4]
004E052B  8b11                           mov    edx,DWORD PTR [ecx]
004E052D  8b4224                         mov    eax,DWORD PTR [edx+0x24]
004E0530  51                             push   ecx
004E0531  d91c24                         fstp   DWORD PTR [esp]
004E0534  ffd0                           call   eax
004E0536  b801000000                     mov    eax,0x1
004E053B  5d                             pop    ebp
004E053C  c20400                         ret    0x4

; slow_motion_on [CURRENT_JOIN] 0x565640..0x5656ae
00565640  55                             push   ebp
00565641  8bec                           mov    ebp,esp
00565643  83e4f8                         and    esp,0xfffffff8
00565646  6aff                           push   0xffffffff
00565648  68fe6e9300                     push   0x936efe
0056564D  64a100000000                   mov    eax,fs:0x0
00565653  50                             push   eax
00565654  83ec08                         sub    esp,0x8
00565657  53                             push   ebx
00565658  a1201fd600                     mov    eax,ds:0xd61f20
0056565D  33c4                           xor    eax,esp
0056565F  50                             push   eax
00565660  8d442410                       lea    eax,[esp+0x10]
00565664  64a300000000                   mov    fs:0x0,eax
0056566A  bb01000000                     mov    ebx,0x1
0056566F  841d2cb2fa00                   test   BYTE PTR ds:0xfab22c,bl
00565675  7520                           jne    0x565697
00565677  091d2cb2fa00                   or     DWORD PTR ds:0xfab22c,ebx
0056567D  c744241800000000               mov    DWORD PTR [esp+0x18],0x0
00565685  e80696f7ff                     call   0x4dec90
0056568A  6830cebc00                     push   0xbcce30
0056568F  e886cc3200                     call   0x89231a
00565694  83c404                         add    esp,0x4
00565697  891de0b1fa00                   mov    DWORD PTR ds:0xfab1e0,ebx
0056569D  8b4c2410                       mov    ecx,DWORD PTR [esp+0x10]
005656A1  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
005656A8  59                             pop    ecx
005656A9  5b                             pop    ebx
005656AA  8be5                           mov    esp,ebp
005656AC  5d                             pop    ebp
005656AD  c3                             ret

; slow_motion_off [CURRENT_JOIN] 0x5656b0..0x56571e
005656B0  55                             push   ebp
005656B1  8bec                           mov    ebp,esp
005656B3  83e4f8                         and    esp,0xfffffff8
005656B6  6aff                           push   0xffffffff
005656B8  68ee619400                     push   0x9461ee
005656BD  64a100000000                   mov    eax,fs:0x0
005656C3  50                             push   eax
005656C4  51                             push   ecx
005656C5  a1201fd600                     mov    eax,ds:0xd61f20
005656CA  33c4                           xor    eax,esp
005656CC  50                             push   eax
005656CD  8d442408                       lea    eax,[esp+0x8]
005656D1  64a300000000                   mov    fs:0x0,eax
005656D7  b801000000                     mov    eax,0x1
005656DC  84052cb2fa00                   test   BYTE PTR ds:0xfab22c,al
005656E2  7520                           jne    0x565704
005656E4  09052cb2fa00                   or     DWORD PTR ds:0xfab22c,eax
005656EA  c744241000000000               mov    DWORD PTR [esp+0x10],0x0
005656F2  e89995f7ff                     call   0x4dec90
005656F7  6830cebc00                     push   0xbcce30
005656FC  e819cc3200                     call   0x89231a
00565701  83c404                         add    esp,0x4
00565704  c705e0b1fa0000000000           mov    DWORD PTR ds:0xfab1e0,0x0
0056570E  8b4c2408                       mov    ecx,DWORD PTR [esp+0x8]
00565712  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00565719  59                             pop    ecx
0056571A  8be5                           mov    esp,ebp
0056571C  5d                             pop    ebp
0056571D  c3                             ret

; letterbox_on [CURRENT_JOIN] 0x564b00..0x564b47
00564B00  53                             push   ebx
00564B01  bb01000000                     mov    ebx,0x1
00564B06  841dcc38fe00                   test   BYTE PTR ds:0xfe38cc,bl
00564B0C  7531                           jne    0x564b3f
00564B0E  091dcc38fe00                   or     DWORD PTR ds:0xfe38cc,ebx
00564B14  68d0f2bc00                     push   0xbcf2d0
00564B19  c705e436fe0000040000           mov    DWORD PTR ds:0xfe36e4,0x400
00564B23  c705e836fe0000030000           mov    DWORD PTR ds:0xfe36e8,0x300
00564B2D  c705ec36fe0000000000           mov    DWORD PTR ds:0xfe36ec,0x0
00564B37  e8ded73200                     call   0x89231a
00564B3C  83c404                         add    esp,0x4
00564B3F  891dec36fe00                   mov    DWORD PTR ds:0xfe36ec,ebx
00564B45  5b                             pop    ebx
00564B46  c3                             ret

; letterbox_off [CURRENT_JOIN] 0x564b50..0x564b99
00564B50  b801000000                     mov    eax,0x1
00564B55  c705ec36fe0000000000           mov    DWORD PTR ds:0xfe36ec,0x0
00564B5F  8405cc38fe00                   test   BYTE PTR ds:0xfe38cc,al
00564B65  7531                           jne    0x564b98
00564B67  0905cc38fe00                   or     DWORD PTR ds:0xfe38cc,eax
00564B6D  68d0f2bc00                     push   0xbcf2d0
00564B72  c705e436fe0000040000           mov    DWORD PTR ds:0xfe36e4,0x400
00564B7C  c705e836fe0000030000           mov    DWORD PTR ds:0xfe36e8,0x300
00564B86  e88fd73200                     call   0x89231a
00564B8B  83c404                         add    esp,0x4
00564B8E  c705ec36fe0000000000           mov    DWORD PTR ds:0xfe36ec,0x0
00564B98  c3                             ret

; letterbox_draw [CURRENT_JOIN] 0x55ecc0..0x55ed57
0055ECC0  55                             push   ebp
0055ECC1  8bec                           mov    ebp,esp
0055ECC3  8b0e                           mov    ecx,DWORD PTR [esi]
0055ECC5  83ec08                         sub    esp,0x8
0055ECC8  85c9                           test   ecx,ecx
0055ECCA  0f8481000000                   je     0x55ed51
0055ECD0  837e0c00                       cmp    DWORD PTR [esi+0xc],0x0
0055ECD4  747b                           je     0x55ed51
0055ECD6  db4604                         fild   DWORD PTR [esi+0x4]
0055ECD9  f30f1005c056c400               movss  xmm0,DWORD PTR ds:0xc456c0
0055ECE1  6aff                           push   0xffffffff
0055ECE3  51                             push   ecx
0055ECE4  dc0de058c500                   fmul   QWORD PTR ds:0xc558e0
0055ECEA  8d55f8                         lea    edx,[ebp-0x8]
0055ECED  f30f1145fc                     movss  DWORD PTR [ebp-0x4],xmm0
0055ECF2  dc05a056c500                   fadd   QWORD PTR ds:0xc556a0
0055ECF8  d95df8                         fstp   DWORD PTR [ebp-0x8]
0055ECFB  8b01                           mov    eax,DWORD PTR [ecx]
0055ECFD  d9ee                           fldz
0055ECFF  8b4024                         mov    eax,DWORD PTR [eax+0x24]
0055ED02  d91c24                         fstp   DWORD PTR [esp]
0055ED05  6a00                           push   0x0
0055ED07  52                             push   edx
0055ED08  6a00                           push   0x0
0055ED0A  6ae4                           push   0xffffffe4
0055ED0C  6af0                           push   0xfffffff0
0055ED0E  ffd0                           call   eax
0055ED10  db4604                         fild   DWORD PTR [esi+0x4]
0055ED13  8b0e                           mov    ecx,DWORD PTR [esi]
0055ED15  f30f1005c056c400               movss  xmm0,DWORD PTR ds:0xc456c0
0055ED1D  dc0de058c500                   fmul   QWORD PTR ds:0xc558e0
0055ED23  6aff                           push   0xffffffff
0055ED25  51                             push   ecx
0055ED26  8d45f8                         lea    eax,[ebp-0x8]
0055ED29  dc05a056c500                   fadd   QWORD PTR ds:0xc556a0
0055ED2F  f30f1145fc                     movss  DWORD PTR [ebp-0x4],xmm0
0055ED34  d95df8                         fstp   DWORD PTR [ebp-0x8]
0055ED37  8b11                           mov    edx,DWORD PTR [ecx]
0055ED39  d9ee                           fldz
0055ED3B  8b5224                         mov    edx,DWORD PTR [edx+0x24]
0055ED3E  d91c24                         fstp   DWORD PTR [esp]
0055ED41  6a00                           push   0x0
0055ED43  50                             push   eax
0055ED44  8b4608                         mov    eax,DWORD PTR [esi+0x8]
0055ED47  6a00                           push   0x0
0055ED49  83e864                         sub    eax,0x64
0055ED4C  50                             push   eax
0055ED4D  6af0                           push   0xfffffff0
0055ED4F  ffd2                           call   edx
0055ED51  8be5                           mov    esp,ebp
0055ED53  5d                             pop    ebp
0055ED54  c3                             ret
0055ED55  cc                             int3
0055ED56  cc                             int3

; presentation_draw [CURRENT_JOIN] 0x5646e0..0x564797
005646E0  55                             push   ebp
005646E1  8bec                           mov    ebp,esp
005646E3  6aff                           push   0xffffffff
005646E5  683eac9300                     push   0x93ac3e
005646EA  64a100000000                   mov    eax,fs:0x0
005646F0  50                             push   eax
005646F1  53                             push   ebx
005646F2  56                             push   esi
005646F3  a1201fd600                     mov    eax,ds:0xd61f20
005646F8  33c5                           xor    eax,ebp
005646FA  50                             push   eax
005646FB  8d45f4                         lea    eax,[ebp-0xc]
005646FE  64a300000000                   mov    fs:0x0,eax
00564704  bb01000000                     mov    ebx,0x1
00564709  841dcc38fe00                   test   BYTE PTR ds:0xfe38cc,bl
0056470F  7531                           jne    0x564742
00564711  091dcc38fe00                   or     DWORD PTR ds:0xfe38cc,ebx
00564717  68d0f2bc00                     push   0xbcf2d0
0056471C  c705e436fe0000040000           mov    DWORD PTR ds:0xfe36e4,0x400
00564726  c705e836fe0000030000           mov    DWORD PTR ds:0xfe36e8,0x300
00564730  c705ec36fe0000000000           mov    DWORD PTR ds:0xfe36ec,0x0
0056473A  e8dbdb3200                     call   0x89231a
0056473F  83c404                         add    esp,0x4
00564742  bee036fe00                     mov    esi,0xfe36e0
00564747  e874a5ffff                     call   0x55ecc0
0056474C  841d4027fe00                   test   BYTE PTR ds:0xfe2740,bl
00564752  7526                           jne    0x56477a
00564754  091d4027fe00                   or     DWORD PTR ds:0xfe2740,ebx
0056475A  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
00564761  e81a9fffff                     call   0x55e680
00564766  68a0f2bc00                     push   0xbcf2a0
0056476B  e8aadb3200                     call   0x89231a
00564770  83c404                         add    esp,0x4
00564773  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0056477A  b84427fe00                     mov    eax,0xfe2744
0056477F  e86ca0ffff                     call   0x55e7f0
00564784  33c0                           xor    eax,eax
00564786  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
00564789  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00564790  59                             pop    ecx
00564791  5e                             pop    esi
00564792  5b                             pop    ebx
00564793  8be5                           mov    esp,ebp
00564795  5d                             pop    ebp
00564796  c3                             ret

; q_flying_create [CURRENT_JOIN] 0x564940..0x564a5b
00564940  55                             push   ebp
00564941  8bec                           mov    ebp,esp
00564943  6aff                           push   0xffffffff
00564945  68b9de9100                     push   0x91deb9
0056494A  64a100000000                   mov    eax,fs:0x0
00564950  50                             push   eax
00564951  83ec10                         sub    esp,0x10
00564954  53                             push   ebx
00564955  56                             push   esi
00564956  57                             push   edi
00564957  a1201fd600                     mov    eax,ds:0xd61f20
0056495C  33c5                           xor    eax,ebp
0056495E  50                             push   eax
0056495F  8d45f4                         lea    eax,[ebp-0xc]
00564962  64a300000000                   mov    fs:0x0,eax
00564968  8bd9                           mov    ebx,ecx
0056496A  e8f1000000                     call   0x564a60
0056496F  6a70                           push   0x70
00564971  e8f2c83200                     call   0x891268
00564976  8bf0                           mov    esi,eax
00564978  83c404                         add    esp,0x4
0056497B  8975ec                         mov    DWORD PTR [ebp-0x14],esi
0056497E  33ff                           xor    edi,edi
00564980  897dfc                         mov    DWORD PTR [ebp-0x4],edi
00564983  3bf7                           cmp    esi,edi
00564985  7433                           je     0x5649ba
00564987  397d20                         cmp    DWORD PTR [ebp+0x20],edi
0056498A  7405                           je     0x564991
0056498C  83c8ff                         or     eax,0xffffffff
0056498F  eb03                           jmp    0x564994
00564991  8b4518                         mov    eax,DWORD PTR [ebp+0x18]
00564994  8b4d1c                         mov    ecx,DWORD PTR [ebp+0x1c]
00564997  8b5508                         mov    edx,DWORD PTR [ebp+0x8]
0056499A  57                             push   edi
0056499B  51                             push   ecx
0056499C  8b4d14                         mov    ecx,DWORD PTR [ebp+0x14]
0056499F  50                             push   eax
005649A0  56                             push   esi
005649A1  e8eaf4feff                     call   0x553e90
005649A6  8b550c                         mov    edx,DWORD PTR [ebp+0xc]
005649A9  8b4510                         mov    eax,DWORD PTR [ebp+0x10]
005649AC  c7064807c100                   mov    DWORD PTR [esi],0xc10748
005649B2  895668                         mov    DWORD PTR [esi+0x68],edx
005649B5  89466c                         mov    DWORD PTR [esi+0x6c],eax
005649B8  eb02                           jmp    0x5649bc
005649BA  33f6                           xor    esi,esi
005649BC  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
005649C3  f6055473fb0001                 test   BYTE PTR ds:0xfb7354,0x1
005649CA  7527                           jne    0x5649f3
005649CC  b801000000                     mov    eax,0x1
005649D1  09055473fb00                   or     DWORD PTR ds:0xfb7354,eax
005649D7  8945fc                         mov    DWORD PTR [ebp-0x4],eax
005649DA  e8f1e9feff                     call   0x5533d0
005649DF  6800d1bc00                     push   0xbcd100
005649E4  e831d93200                     call   0x89231a
005649E9  83c404                         add    esp,0x4
005649EC  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
005649F3  8b16                           mov    edx,DWORD PTR [esi]
005649F5  8b4204                         mov    eax,DWORD PTR [edx+0x4]
005649F8  8bce                           mov    ecx,esi
005649FA  ffd0                           call   eax
005649FC  a1b073fb00                     mov    eax,ds:0xfb73b0
00564A01  8b0dac73fb00                   mov    ecx,DWORD PTR ds:0xfb73ac
00564A07  8b16                           mov    edx,DWORD PTR [esi]
00564A09  8b5220                         mov    edx,DWORD PTR [edx+0x20]
00564A0C  50                             push   eax
00564A0D  51                             push   ecx
00564A0E  8bce                           mov    ecx,esi
00564A10  ffd2                           call   edx
00564A12  897e40                         mov    DWORD PTR [esi+0x40],edi
00564A15  a19873fb00                     mov    eax,ds:0xfb7398
00564A1A  8975ec                         mov    DWORD PTR [ebp-0x14],esi
00564A1D  8d7de8                         lea    edi,[ebp-0x18]
00564A20  be5873fb00                     mov    esi,0xfb7358
00564A25  8945e8                         mov    DWORD PTR [ebp-0x18],eax
00564A28  e8f3a40100                     call   0x57ef20
00564A2D  50                             push   eax
00564A2E  56                             push   esi
00564A2F  8d75e8                         lea    esi,[ebp-0x18]
00564A32  e8c9a72c00                     call   0x82f200
00564A37  a19873fb00                     mov    eax,ds:0xfb7398
00564A3C  8bc8                           mov    ecx,eax
00564A3E  40                             inc    eax
00564A3F  a39873fb00                     mov    ds:0xfb7398,eax
00564A44  894b40                         mov    DWORD PTR [ebx+0x40],ecx
00564A47  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
00564A4A  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00564A51  59                             pop    ecx
00564A52  5f                             pop    edi
00564A53  5e                             pop    esi
00564A54  5b                             pop    ebx
00564A55  8be5                           mov    esp,ebp
00564A57  5d                             pop    ebp
00564A58  c21c00                         ret    0x1c

; q_flying_cancel [CURRENT_JOIN] 0x564a60..0x564afb
00564A60  55                             push   ebp
00564A61  8bec                           mov    ebp,esp
00564A63  6aff                           push   0xffffffff
00564A65  68eece9000                     push   0x90ceee
00564A6A  64a100000000                   mov    eax,fs:0x0
00564A70  50                             push   eax
00564A71  83ec08                         sub    esp,0x8
00564A74  56                             push   esi
00564A75  a1201fd600                     mov    eax,ds:0xd61f20
00564A7A  33c5                           xor    eax,ebp
00564A7C  50                             push   eax
00564A7D  8d45f4                         lea    eax,[ebp-0xc]
00564A80  64a300000000                   mov    fs:0x0,eax
00564A86  8bf1                           mov    esi,ecx
00564A88  b801000000                     mov    eax,0x1
00564A8D  84055473fb00                   test   BYTE PTR ds:0xfb7354,al
00564A93  751f                           jne    0x564ab4
00564A95  09055473fb00                   or     DWORD PTR ds:0xfb7354,eax
00564A9B  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
00564AA2  e829e9feff                     call   0x5533d0
00564AA7  6800d1bc00                     push   0xbcd100
00564AAC  e869d83200                     call   0x89231a
00564AB1  83c404                         add    esp,0x4
00564AB4  8b4640                         mov    eax,DWORD PTR [esi+0x40]
00564AB7  8d4df0                         lea    ecx,[ebp-0x10]
00564ABA  8945f0                         mov    DWORD PTR [ebp-0x10],eax
00564ABD  51                             push   ecx
00564ABE  8d45ec                         lea    eax,[ebp-0x14]
00564AC1  b95873fb00                     mov    ecx,0xfb7358
00564AC6  e835a42c00                     call   0x82ef00
00564ACB  8b45ec                         mov    eax,DWORD PTR [ebp-0x14]
00564ACE  3b055c73fb00                   cmp    eax,DWORD PTR ds:0xfb735c
00564AD4  740e                           je     0x564ae4
00564AD6  8b4010                         mov    eax,DWORD PTR [eax+0x10]
00564AD9  85c0                           test   eax,eax
00564ADB  7407                           je     0x564ae4
00564ADD  c7401400000000                 mov    DWORD PTR [eax+0x14],0x0
00564AE4  c74640ffffffff                 mov    DWORD PTR [esi+0x40],0xffffffff
00564AEB  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
00564AEE  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00564AF5  59                             pop    ecx
00564AF6  5e                             pop    esi
00564AF7  8be5                           mov    esp,ebp
00564AF9  5d                             pop    ebp
00564AFA  c3                             ret

; flying_lifecycle [CURRENT_JOIN] 0x553b60..0x553c50
00553B60  55                             push   ebp
00553B61  8bec                           mov    ebp,esp
00553B63  8b4134                         mov    eax,DWORD PTR [ecx+0x34]
00553B66  83ec08                         sub    esp,0x8
00553B69  83f804                         cmp    eax,0x4
00553B6C  0f87da000000                   ja     0x553c4c
00553B72  ff2485503c5500                 jmp    DWORD PTR [eax*4+0x553c50]
00553B79  c7411400000000                 mov    DWORD PTR [ecx+0x14],0x0
00553B80  8be5                           mov    esp,ebp
00553B82  5d                             pop    ebp
00553B83  c3                             ret
00553B84  8b4124                         mov    eax,DWORD PTR [ecx+0x24]
00553B87  85c0                           test   eax,eax
00553B89  7e08                           jle    0x553b93
00553B8B  48                             dec    eax
00553B8C  894124                         mov    DWORD PTR [ecx+0x24],eax
00553B8F  8be5                           mov    esp,ebp
00553B91  5d                             pop    ebp
00553B92  c3                             ret
00553B93  c7413402000000                 mov    DWORD PTR [ecx+0x34],0x2
00553B9A  8b4128                         mov    eax,DWORD PTR [ecx+0x28]
00553B9D  85c0                           test   eax,eax
00553B9F  7e39                           jle    0x553bda
00553BA1  48                             dec    eax
00553BA2  8945fc                         mov    DWORD PTR [ebp-0x4],eax
00553BA5  db45fc                         fild   DWORD PTR [ebp-0x4]
00553BA8  894128                         mov    DWORD PTR [ecx+0x28],eax
00553BAB  d97dfe                         fnstcw WORD PTR [ebp-0x2]
00553BAE  da711c                         fidiv  DWORD PTR [ecx+0x1c]
00553BB1  0fb745fe                       movzx  eax,WORD PTR [ebp-0x2]
00553BB5  0d000c0000                     or     eax,0xc00
00553BBA  8945f8                         mov    DWORD PTR [ebp-0x8],eax
00553BBD  dd058856c500                   fld    QWORD PTR ds:0xc55688
00553BC3  dcc9                           fmul   st(1),st
00553BC5  dee1                           fsubrp st(1),st
00553BC7  d96df8                         fldcw  WORD PTR [ebp-0x8]
00553BCA  db5df8                         fistp  DWORD PTR [ebp-0x8]
00553BCD  8a45f8                         mov    al,BYTE PTR [ebp-0x8]
00553BD0  884138                         mov    BYTE PTR [ecx+0x38],al
00553BD3  d96dfe                         fldcw  WORD PTR [ebp-0x2]
00553BD6  8be5                           mov    esp,ebp
00553BD8  5d                             pop    ebp
00553BD9  c3                             ret
00553BDA  c64138ff                       mov    BYTE PTR [ecx+0x38],0xff
00553BDE  c7413403000000                 mov    DWORD PTR [ecx+0x34],0x3
00553BE5  8be5                           mov    esp,ebp
00553BE7  5d                             pop    ebp
00553BE8  c3                             ret
00553BE9  8b4130                         mov    eax,DWORD PTR [ecx+0x30]
00553BEC  85c0                           test   eax,eax
00553BEE  7e08                           jle    0x553bf8
00553BF0  48                             dec    eax
00553BF1  894130                         mov    DWORD PTR [ecx+0x30],eax
00553BF4  8be5                           mov    esp,ebp
00553BF6  5d                             pop    ebp
00553BF7  c3                             ret
00553BF8  7552                           jne    0x553c4c
00553BFA  c7413404000000                 mov    DWORD PTR [ecx+0x34],0x4
00553C01  8be5                           mov    esp,ebp
00553C03  5d                             pop    ebp
00553C04  c3                             ret
00553C05  8b412c                         mov    eax,DWORD PTR [ecx+0x2c]
00553C08  85c0                           test   eax,eax
00553C0A  7e35                           jle    0x553c41
00553C0C  48                             dec    eax
00553C0D  d97dfe                         fnstcw WORD PTR [ebp-0x2]
00553C10  8945f8                         mov    DWORD PTR [ebp-0x8],eax
00553C13  db45f8                         fild   DWORD PTR [ebp-0x8]
00553C16  89412c                         mov    DWORD PTR [ecx+0x2c],eax
00553C19  0fb745fe                       movzx  eax,WORD PTR [ebp-0x2]
00553C1D  0d000c0000                     or     eax,0xc00
00553C22  da7120                         fidiv  DWORD PTR [ecx+0x20]
00553C25  8945f8                         mov    DWORD PTR [ebp-0x8],eax
00553C28  dc0d8856c500                   fmul   QWORD PTR ds:0xc55688
00553C2E  d96df8                         fldcw  WORD PTR [ebp-0x8]
00553C31  db5df8                         fistp  DWORD PTR [ebp-0x8]
00553C34  8a55f8                         mov    dl,BYTE PTR [ebp-0x8]
00553C37  885138                         mov    BYTE PTR [ecx+0x38],dl
00553C3A  d96dfe                         fldcw  WORD PTR [ebp-0x2]
00553C3D  8be5                           mov    esp,ebp
00553C3F  5d                             pop    ebp
00553C40  c3                             ret
00553C41  c6413800                       mov    BYTE PTR [ecx+0x38],0x0
00553C45  c7413400000000                 mov    DWORD PTR [ecx+0x34],0x0
00553C4C  8be5                           mov    esp,ebp
00553C4E  5d                             pop    ebp
00553C4F  c3                             ret

; flying_manager_tick [CURRENT_JOIN] 0x5537f0..0x553991
005537F0  55                             push   ebp
005537F1  8bec                           mov    ebp,esp
005537F3  83ec10                         sub    esp,0x10
005537F6  53                             push   ebx
005537F7  56                             push   esi
005537F8  33c0                           xor    eax,eax
005537FA  57                             push   edi
005537FB  33db                           xor    ebx,ebx
005537FD  eb03                           jmp    0x553802
005537FF  90                             nop
00553800  33c0                           xor    eax,eax
00553802  8b7d08                         mov    edi,DWORD PTR [ebp+0x8]
00553805  8945f4                         mov    DWORD PTR [ebp-0xc],eax
00553808  8945f8                         mov    DWORD PTR [ebp-0x8],eax
0055380B  b901000000                     mov    ecx,0x1
00553810  3bd8                           cmp    ebx,eax
00553812  7e09                           jle    0x55381d
00553814  39449f40                       cmp    DWORD PTR [edi+ebx*4+0x40],eax
00553818  7403                           je     0x55381d
0055381A  894df4                         mov    DWORD PTR [ebp-0xc],ecx
0055381D  8bd3                           mov    edx,ebx
0055381F  c1e204                         shl    edx,0x4
00553822  8b443a04                       mov    eax,DWORD PTR [edx+edi*1+0x4]
00553826  8b30                           mov    esi,DWORD PTR [eax]
00553828  03d7                           add    edx,edi
0055382A  8955fc                         mov    DWORD PTR [ebp-0x4],edx
0055382D  3bf0                           cmp    esi,eax
0055382F  0f84d3000000                   je     0x553908
00553835  eb0e                           jmp    0x553845
00553837  eb07                           jmp    0x553840
00553839  8da42400000000                 lea    esp,[esp+0x0]
00553840  b901000000                     mov    ecx,0x1
00553845  8b5204                         mov    edx,DWORD PTR [edx+0x4]
00553848  8b02                           mov    eax,DWORD PTR [edx]
0055384A  8b7e10                         mov    edi,DWORD PTR [esi+0x10]
0055384D  3bf0                           cmp    esi,eax
0055384F  7415                           je     0x553866
00553851  8b4010                         mov    eax,DWORD PTR [eax+0x10]
00553854  83783c00                       cmp    DWORD PTR [eax+0x3c],0x0
00553858  7503                           jne    0x55385d
0055385A  894df8                         mov    DWORD PTR [ebp-0x8],ecx
0055385D  837f3c00                       cmp    DWORD PTR [edi+0x3c],0x0
00553861  7503                           jne    0x553866
00553863  894df8                         mov    DWORD PTR [ebp-0x8],ecx
00553866  837df400                       cmp    DWORD PTR [ebp-0xc],0x0
0055386A  7506                           jne    0x553872
0055386C  837df800                       cmp    DWORD PTR [ebp-0x8],0x0
00553870  7403                           je     0x553875
00553872  014f24                         add    DWORD PTR [edi+0x24],ecx
00553875  8b17                           mov    edx,DWORD PTR [edi]
00553877  8b4214                         mov    eax,DWORD PTR [edx+0x14]
0055387A  8bcf                           mov    ecx,edi
0055387C  ffd0                           call   eax
0055387E  8b17                           mov    edx,DWORD PTR [edi]
00553880  8b4224                         mov    eax,DWORD PTR [edx+0x24]
00553883  8bcf                           mov    ecx,edi
00553885  ffd0                           call   eax
00553887  85c0                           test   eax,eax
00553889  7525                           jne    0x5538b0
0055388B  8b17                           mov    edx,DWORD PTR [edi]
0055388D  8b4208                         mov    eax,DWORD PTR [edx+0x8]
00553890  8bcf                           mov    ecx,edi
00553892  ffd0                           call   eax
00553894  8b17                           mov    edx,DWORD PTR [edi]
00553896  8b02                           mov    eax,DWORD PTR [edx]
00553898  6a01                           push   0x1
0055389A  8bcf                           mov    ecx,edi
0055389C  ffd0                           call   eax
0055389E  8b55fc                         mov    edx,DWORD PTR [ebp-0x4]
005538A1  56                             push   esi
005538A2  8d4df0                         lea    ecx,[ebp-0x10]
005538A5  51                             push   ecx
005538A6  52                             push   edx
005538A7  e8e42f2600                     call   0x7b6890
005538AC  8b30                           mov    esi,DWORD PTR [eax]
005538AE  eb47                           jmp    0x5538f7
005538B0  807e1500                       cmp    BYTE PTR [esi+0x15],0x0
005538B4  7541                           jne    0x5538f7
005538B6  8b4608                         mov    eax,DWORD PTR [esi+0x8]
005538B9  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005538BD  751d                           jne    0x5538dc
005538BF  8bf0                           mov    esi,eax
005538C1  8b06                           mov    eax,DWORD PTR [esi]
005538C3  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005538C7  752e                           jne    0x5538f7
005538C9  8da42400000000                 lea    esp,[esp+0x0]
005538D0  8bf0                           mov    esi,eax
005538D2  8b06                           mov    eax,DWORD PTR [esi]
005538D4  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005538D8  74f6                           je     0x5538d0
005538DA  eb1b                           jmp    0x5538f7
005538DC  8b4604                         mov    eax,DWORD PTR [esi+0x4]
005538DF  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005538E3  7510                           jne    0x5538f5
005538E5  3b7008                         cmp    esi,DWORD PTR [eax+0x8]
005538E8  750b                           jne    0x5538f5
005538EA  8bf0                           mov    esi,eax
005538EC  8b4004                         mov    eax,DWORD PTR [eax+0x4]
005538EF  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005538F3  74f0                           je     0x5538e5
005538F5  8bf0                           mov    esi,eax
005538F7  8b45fc                         mov    eax,DWORD PTR [ebp-0x4]
005538FA  8bd0                           mov    edx,eax
005538FC  3b7004                         cmp    esi,DWORD PTR [eax+0x4]
005538FF  0f853bffffff                   jne    0x553840
00553905  8b7d08                         mov    edi,DWORD PTR [ebp+0x8]
00553908  85db                           test   ebx,ebx
0055390A  7504                           jne    0x553910
0055390C  33c0                           xor    eax,eax
0055390E  eb04                           jmp    0x553914
00553910  8b449f40                       mov    eax,DWORD PTR [edi+ebx*4+0x40]
00553914  89449f44                       mov    DWORD PTR [edi+ebx*4+0x44],eax
00553918  8b4204                         mov    eax,DWORD PTR [edx+0x4]
0055391B  8b08                           mov    ecx,DWORD PTR [eax]
0055391D  3bc8                           cmp    ecx,eax
0055391F  7456                           je     0x553977
00553921  8b4110                         mov    eax,DWORD PTR [ecx+0x10]
00553924  83783404                       cmp    DWORD PTR [eax+0x34],0x4
00553928  7d04                           jge    0x55392e
0055392A  ff449f44                       inc    DWORD PTR [edi+ebx*4+0x44]
0055392E  80791500                       cmp    BYTE PTR [ecx+0x15],0x0
00553932  753e                           jne    0x553972
00553934  8b4108                         mov    eax,DWORD PTR [ecx+0x8]
00553937  80781500                       cmp    BYTE PTR [eax+0x15],0x0
0055393B  7516                           jne    0x553953
0055393D  8bc8                           mov    ecx,eax
0055393F  8b01                           mov    eax,DWORD PTR [ecx]
00553941  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553945  752b                           jne    0x553972
00553947  8bc8                           mov    ecx,eax
00553949  8b01                           mov    eax,DWORD PTR [ecx]
0055394B  80781500                       cmp    BYTE PTR [eax+0x15],0x0
0055394F  74f6                           je     0x553947
00553951  eb1f                           jmp    0x553972
00553953  8b4104                         mov    eax,DWORD PTR [ecx+0x4]
00553956  80781500                       cmp    BYTE PTR [eax+0x15],0x0
0055395A  7514                           jne    0x553970
0055395C  8d642400                       lea    esp,[esp+0x0]
00553960  3b4808                         cmp    ecx,DWORD PTR [eax+0x8]
00553963  750b                           jne    0x553970
00553965  8bc8                           mov    ecx,eax
00553967  8b4004                         mov    eax,DWORD PTR [eax+0x4]
0055396A  80781500                       cmp    BYTE PTR [eax+0x15],0x0
0055396E  74f0                           je     0x553960
00553970  8bc8                           mov    ecx,eax
00553972  3b4a04                         cmp    ecx,DWORD PTR [edx+0x4]
00553975  75aa                           jne    0x553921
00553977  8b4a08                         mov    ecx,DWORD PTR [edx+0x8]
0055397A  014c9f44                       add    DWORD PTR [edi+ebx*4+0x44],ecx
0055397E  43                             inc    ebx
0055397F  83fb04                         cmp    ebx,0x4
00553982  0f8c78feffff                   jl     0x553800
00553988  5f                             pop    edi
00553989  5e                             pop    esi
0055398A  5b                             pop    ebx
0055398B  8be5                           mov    esp,ebp
0055398D  5d                             pop    ebp
0055398E  c20400                         ret    0x4

; flying_alive [CURRENT_JOIN] 0x80f010..0x80f014
0080F010  8b4114                         mov    eax,DWORD PTR [ecx+0x14]
0080F013  c3                             ret

; flying_release [CURRENT_JOIN] 0x553de0..0x553dfa
00553DE0  56                             push   esi
00553DE1  8bf1                           mov    esi,ecx
00553DE3  8b4e44                         mov    ecx,DWORD PTR [esi+0x44]
00553DE6  85c9                           test   ecx,ecx
00553DE8  740e                           je     0x553df8
00553DEA  8b01                           mov    eax,DWORD PTR [ecx]
00553DEC  8b5008                         mov    edx,DWORD PTR [eax+0x8]
00553DEF  ffd2                           call   edx
00553DF1  c7464400000000                 mov    DWORD PTR [esi+0x44],0x0
00553DF8  5e                             pop    esi
00553DF9  c3                             ret

; flying_deleting_dtor [CURRENT_JOIN] 0x553e40..0x553e89
00553E40  55                             push   ebp
00553E41  8bec                           mov    ebp,esp
00553E43  56                             push   esi
00553E44  8bf1                           mov    esi,ecx
00553E46  c70694ffc000                   mov    DWORD PTR [esi],0xc0ff94
00553E4C  837e5c10                       cmp    DWORD PTR [esi+0x5c],0x10
00553E50  720c                           jb     0x553e5e
00553E52  8b4648                         mov    eax,DWORD PTR [esi+0x48]
00553E55  50                             push   eax
00553E56  e8b1d33300                     call   0x89120c
00553E5B  83c404                         add    esp,0x4
00553E5E  33c0                           xor    eax,eax
00553E60  f6450801                       test   BYTE PTR [ebp+0x8],0x1
00553E64  c7465c0f000000                 mov    DWORD PTR [esi+0x5c],0xf
00553E6B  894658                         mov    DWORD PTR [esi+0x58],eax
00553E6E  884648                         mov    BYTE PTR [esi+0x48],al
00553E71  c70634ffc000                   mov    DWORD PTR [esi],0xc0ff34
00553E77  7409                           je     0x553e82
00553E79  56                             push   esi
00553E7A  e88dd33300                     call   0x89120c
00553E7F  83c404                         add    esp,0x4
00553E82  8bc6                           mov    eax,esi
00553E84  5e                             pop    esi
00553E85  5d                             pop    ebp
00553E86  c20400                         ret    0x4

; flying_draw [CURRENT_JOIN] 0x5539a0..0x553ae8
005539A0  55                             push   ebp
005539A1  8bec                           mov    ebp,esp
005539A3  83785c00                       cmp    DWORD PTR [eax+0x5c],0x0
005539A7  0f8437010000                   je     0x553ae4
005539AD  53                             push   ebx
005539AE  56                             push   esi
005539AF  57                             push   edi
005539B0  bb03000000                     mov    ebx,0x3
005539B5  8d7834                         lea    edi,[eax+0x34]
005539B8  eb06                           jmp    0x5539c0
005539BA  8d9b00000000                   lea    ebx,[ebx+0x0]
005539C0  8b37                           mov    esi,DWORD PTR [edi]
005539C2  3b36                           cmp    esi,DWORD PTR [esi]
005539C4  0f840d010000                   je     0x553ad7
005539CA  8d9b00000000                   lea    ebx,[ebx+0x0]
005539D0  8a5615                         mov    dl,BYTE PTR [esi+0x15]
005539D3  8bce                           mov    ecx,esi
005539D5  84d2                           test   dl,dl
005539D7  7405                           je     0x5539de
005539D9  8b4e08                         mov    ecx,DWORD PTR [esi+0x8]
005539DC  eb40                           jmp    0x553a1e
005539DE  8b06                           mov    eax,DWORD PTR [esi]
005539E0  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005539E4  7518                           jne    0x5539fe
005539E6  8bc8                           mov    ecx,eax
005539E8  8b4108                         mov    eax,DWORD PTR [ecx+0x8]
005539EB  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005539EF  752d                           jne    0x553a1e
005539F1  8bc8                           mov    ecx,eax
005539F3  8b4108                         mov    eax,DWORD PTR [ecx+0x8]
005539F6  80781500                       cmp    BYTE PTR [eax+0x15],0x0
005539FA  74f5                           je     0x5539f1
005539FC  eb20                           jmp    0x553a1e
005539FE  8b4604                         mov    eax,DWORD PTR [esi+0x4]
00553A01  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A05  750f                           jne    0x553a16
00553A07  3b08                           cmp    ecx,DWORD PTR [eax]
00553A09  750b                           jne    0x553a16
00553A0B  8bc8                           mov    ecx,eax
00553A0D  8b4004                         mov    eax,DWORD PTR [eax+0x4]
00553A10  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A14  74f1                           je     0x553a07
00553A16  80791500                       cmp    BYTE PTR [ecx+0x15],0x0
00553A1A  7502                           jne    0x553a1e
00553A1C  8bc8                           mov    ecx,eax
00553A1E  8b4110                         mov    eax,DWORD PTR [ecx+0x10]
00553A21  8b4d08                         mov    ecx,DWORD PTR [ebp+0x8]
00553A24  394840                         cmp    DWORD PTR [eax+0x40],ecx
00553A27  7558                           jne    0x553a81
00553A29  8bce                           mov    ecx,esi
00553A2B  84d2                           test   dl,dl
00553A2D  7405                           je     0x553a34
00553A2F  8b4e08                         mov    ecx,DWORD PTR [esi+0x8]
00553A32  eb43                           jmp    0x553a77
00553A34  8b06                           mov    eax,DWORD PTR [esi]
00553A36  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A3A  7518                           jne    0x553a54
00553A3C  8bc8                           mov    ecx,eax
00553A3E  8b4108                         mov    eax,DWORD PTR [ecx+0x8]
00553A41  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A45  7530                           jne    0x553a77
00553A47  8bc8                           mov    ecx,eax
00553A49  8b4108                         mov    eax,DWORD PTR [ecx+0x8]
00553A4C  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A50  74f5                           je     0x553a47
00553A52  eb23                           jmp    0x553a77
00553A54  8b4604                         mov    eax,DWORD PTR [esi+0x4]
00553A57  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A5B  7512                           jne    0x553a6f
00553A5D  8d4900                         lea    ecx,[ecx+0x0]
00553A60  3b08                           cmp    ecx,DWORD PTR [eax]
00553A62  750b                           jne    0x553a6f
00553A64  8bc8                           mov    ecx,eax
00553A66  8b4004                         mov    eax,DWORD PTR [eax+0x4]
00553A69  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A6D  74f1                           je     0x553a60
00553A6F  80791500                       cmp    BYTE PTR [ecx+0x15],0x0
00553A73  7502                           jne    0x553a77
00553A75  8bc8                           mov    ecx,eax
00553A77  8b4910                         mov    ecx,DWORD PTR [ecx+0x10]
00553A7A  8b11                           mov    edx,DWORD PTR [ecx]
00553A7C  8b4218                         mov    eax,DWORD PTR [edx+0x18]
00553A7F  ffd0                           call   eax
00553A81  807e1500                       cmp    BYTE PTR [esi+0x15],0x0
00553A85  7405                           je     0x553a8c
00553A87  8b7608                         mov    esi,DWORD PTR [esi+0x8]
00553A8A  eb41                           jmp    0x553acd
00553A8C  8b06                           mov    eax,DWORD PTR [esi]
00553A8E  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A92  7519                           jne    0x553aad
00553A94  8bf0                           mov    esi,eax
00553A96  8b4608                         mov    eax,DWORD PTR [esi+0x8]
00553A99  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553A9D  752e                           jne    0x553acd
00553A9F  90                             nop
00553AA0  8bf0                           mov    esi,eax
00553AA2  8b4608                         mov    eax,DWORD PTR [esi+0x8]
00553AA5  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553AA9  74f5                           je     0x553aa0
00553AAB  eb20                           jmp    0x553acd
00553AAD  8b4604                         mov    eax,DWORD PTR [esi+0x4]
00553AB0  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553AB4  750f                           jne    0x553ac5
00553AB6  3b30                           cmp    esi,DWORD PTR [eax]
00553AB8  750b                           jne    0x553ac5
00553ABA  8bf0                           mov    esi,eax
00553ABC  8b4004                         mov    eax,DWORD PTR [eax+0x4]
00553ABF  80781500                       cmp    BYTE PTR [eax+0x15],0x0
00553AC3  74f1                           je     0x553ab6
00553AC5  807e1500                       cmp    BYTE PTR [esi+0x15],0x0
00553AC9  7502                           jne    0x553acd
00553ACB  8bf0                           mov    esi,eax
00553ACD  8b0f                           mov    ecx,DWORD PTR [edi]
00553ACF  3b31                           cmp    esi,DWORD PTR [ecx]
00553AD1  0f85f9feffff                   jne    0x5539d0
00553AD7  83ef10                         sub    edi,0x10
00553ADA  4b                             dec    ebx
00553ADB  0f89dffeffff                   jns    0x5539c0
00553AE1  5f                             pop    edi
00553AE2  5e                             pop    esi
00553AE3  5b                             pop    ebx
00553AE4  5d                             pop    ebp
00553AE5  c20400                         ret    0x4

; flying_image_draw [CURRENT_JOIN] 0x553fa0..0x553fe3
00553FA0  8bc1                           mov    eax,ecx
00553FA2  8b4834                         mov    ecx,DWORD PTR [eax+0x34]
00553FA5  85c9                           test   ecx,ecx
00553FA7  7439                           je     0x553fe2
00553FA9  83f901                         cmp    ecx,0x1
00553FAC  7434                           je     0x553fe2
00553FAE  83784400                       cmp    DWORD PTR [eax+0x44],0x0
00553FB2  742e                           je     0x553fe2
00553FB4  8b4844                         mov    ecx,DWORD PTR [eax+0x44]
00553FB7  d9ee                           fldz
00553FB9  8b11                           mov    edx,DWORD PTR [ecx]
00553FBB  56                             push   esi
00553FBC  0fb67038                       movzx  esi,BYTE PTR [eax+0x38]
00553FC0  8b5224                         mov    edx,DWORD PTR [edx+0x24]
00553FC3  c1e618                         shl    esi,0x18
00553FC6  81ceffffff00                   or     esi,0xffffff
00553FCC  56                             push   esi
00553FCD  8b7010                         mov    esi,DWORD PTR [eax+0x10]
00553FD0  8b400c                         mov    eax,DWORD PTR [eax+0xc]
00553FD3  51                             push   ecx
00553FD4  d91c24                         fstp   DWORD PTR [esp]
00553FD7  6a01                           push   0x1
00553FD9  6a00                           push   0x0
00553FDB  6a00                           push   0x0
00553FDD  56                             push   esi
00553FDE  50                             push   eax
00553FDF  ffd2                           call   edx
00553FE1  5e                             pop    esi
00553FE2  c3                             ret

; flying_owner_get [CURRENT_JOIN] 0x422ed0..0x422f32
00422ED0  55                             push   ebp
00422ED1  8bec                           mov    ebp,esp
00422ED3  6aff                           push   0xffffffff
00422ED5  680edb9000                     push   0x90db0e
00422EDA  64a100000000                   mov    eax,fs:0x0
00422EE0  50                             push   eax
00422EE1  a1201fd600                     mov    eax,ds:0xd61f20
00422EE6  33c5                           xor    eax,ebp
00422EE8  50                             push   eax
00422EE9  8d45f4                         lea    eax,[ebp-0xc]
00422EEC  64a300000000                   mov    fs:0x0,eax
00422EF2  b801000000                     mov    eax,0x1
00422EF7  84055473fb00                   test   BYTE PTR ds:0xfb7354,al
00422EFD  751f                           jne    0x422f1e
00422EFF  09055473fb00                   or     DWORD PTR ds:0xfb7354,eax
00422F05  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
00422F0C  e8bf041300                     call   0x5533d0
00422F11  6800d1bc00                     push   0xbcd100
00422F16  e8fff34600                     call   0x89231a
00422F1B  83c404                         add    esp,0x4
00422F1E  b85873fb00                     mov    eax,0xfb7358
00422F23  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
00422F26  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
00422F2D  59                             pop    ecx
00422F2E  8be5                           mov    esp,ebp
00422F30  5d                             pop    ebp
00422F31  c3                             ret

; post_q_effect_calls [CURRENT_JOIN] 0x491ed0..0x491f32
00491ED0  e86b10f9ff                     call   0x422f40
00491ED5  8bc8                           mov    ecx,eax
00491ED7  e844f60c00                     call   0x561520
00491EDC  e8cf81ffff                     call   0x48a0b0
00491EE1  e8eada0c00                     call   0x55f9d0
00491EE6  e83582ffff                     call   0x48a120
00491EEB  8bc8                           mov    ecx,eax
00491EED  e87e000f00                     call   0x581f70
00491EF2  f6050c8ffd0001                 test   BYTE PTR ds:0xfd8f0c,0x1
00491EF9  7518                           jne    0x491f13
00491EFB  09350c8ffd00                   or     DWORD PTR ds:0xfd8f0c,esi
00491F01  e81a720c00                     call   0x559120
00491F06  6860dfbc00                     push   0xbcdf60
00491F0B  e80a044000                     call   0x89231a
00491F10  83c404                         add    esp,0x4
00491F13  be108ffd00                     mov    esi,0xfd8f10
00491F18  e873740c00                     call   0x559390
00491F1D  e86e82ffff                     call   0x48a190
00491F22  e8b9220c00                     call   0x5541e0
00491F27  e8a40ff9ff                     call   0x422ed0
00491F2C  50                             push   eax
00491F2D  e8be180c00                     call   0x5537f0

; draw_post_q_effects [CURRENT_JOIN] 0x492ee9..0x492eff
00492EE9  e85200f9ff                     call   0x422f40
00492EEE  e8ed170d00                     call   0x5646e0
00492EF3  6a00                           push   0x0
00492EF5  e8d6fff8ff                     call   0x422ed0
00492EFA  e8a10a0c00                     call   0x5539a0

; music_functor_thunk [CURRENT_JOIN] 0x4facd0..0x4facda
004FACD0  8bc1                           mov    eax,ecx
004FACD2  8b4804                         mov    ecx,DWORD PTR [eax+0x4]
004FACD5  8b4008                         mov    eax,DWORD PTR [eax+0x8]
004FACD8  ffe0                           jmp    eax

; music_worker [CURRENT_JOIN] 0x6d9870..0x6d9970
006D9870  55                             push   ebp
006D9871  8bec                           mov    ebp,esp
006D9873  6aff                           push   0xffffffff
006D9875  68685f9100                     push   0x915f68
006D987A  64a100000000                   mov    eax,fs:0x0
006D9880  50                             push   eax
006D9881  51                             push   ecx
006D9882  53                             push   ebx
006D9883  56                             push   esi
006D9884  57                             push   edi
006D9885  a1201fd600                     mov    eax,ds:0xd61f20
006D988A  33c5                           xor    eax,ebp
006D988C  50                             push   eax
006D988D  8d45f4                         lea    eax,[ebp-0xc]
006D9890  64a300000000                   mov    fs:0x0,eax
006D9896  8bf9                           mov    edi,ecx
006D9898  8d87b4000000                   lea    eax,[edi+0xb4]
006D989E  50                             push   eax
006D989F  8945f0                         mov    DWORD PTR [ebp-0x10],eax
006D98A2  ff154c22bd00                   call   DWORD PTR ds:0xbd224c
006D98A8  33c0                           xor    eax,eax
006D98AA  8945fc                         mov    DWORD PTR [ebp-0x4],eax
006D98AD  3987a8000000                   cmp    DWORD PTR [edi+0xa8],eax
006D98B3  750e                           jne    0x6d98c3
006D98B5  39472c                         cmp    DWORD PTR [edi+0x2c],eax
006D98B8  7509                           jne    0x6d98c3
006D98BA  8b8fac000000                   mov    ecx,DWORD PTR [edi+0xac]
006D98C0  894110                         mov    DWORD PTR [ecx+0x10],eax
006D98C3  8987a8000000                   mov    DWORD PTR [edi+0xa8],eax
006D98C9  8d7734                         lea    esi,[edi+0x34]
006D98CC  8bc6                           mov    eax,esi
006D98CE  e89d000000                     call   0x6d9970
006D98D3  8d476c                         lea    eax,[edi+0x6c]
006D98D6  e895000000                     call   0x6d9970
006D98DB  e830010000                     call   0x6d9a10
006D98E0  8d776c                         lea    esi,[edi+0x6c]
006D98E3  e828010000                     call   0x6d9a10
006D98E8  8b4728                         mov    eax,DWORD PTR [edi+0x28]
006D98EB  8b18                           mov    ebx,DWORD PTR [eax]
006D98ED  3bd8                           cmp    ebx,eax
006D98EF  745b                           je     0x6d994c
006D98F1  8d7308                         lea    esi,[ebx+0x8]
006D98F4  e817010000                     call   0x6d9a10
006D98F9  85c0                           test   eax,eax
006D98FB  7448                           je     0x6d9945
006D98FD  8b33                           mov    esi,DWORD PTR [ebx]
006D98FF  3b5f28                         cmp    ebx,DWORD PTR [edi+0x28]
006D9902  743d                           je     0x6d9941
006D9904  8b5304                         mov    edx,DWORD PTR [ebx+0x4]
006D9907  8932                           mov    DWORD PTR [edx],esi
006D9909  8b03                           mov    eax,DWORD PTR [ebx]
006D990B  8b4b04                         mov    ecx,DWORD PTR [ebx+0x4]
006D990E  894804                         mov    DWORD PTR [eax+0x4],ecx
006D9911  837b2010                       cmp    DWORD PTR [ebx+0x20],0x10
006D9915  720c                           jb     0x6d9923
006D9917  8b530c                         mov    edx,DWORD PTR [ebx+0xc]
006D991A  52                             push   edx
006D991B  e8ec781b00                     call   0x89120c
006D9920  83c404                         add    esp,0x4
006D9923  c743200f000000                 mov    DWORD PTR [ebx+0x20],0xf
006D992A  c7431c00000000                 mov    DWORD PTR [ebx+0x1c],0x0
006D9931  53                             push   ebx
006D9932  c6430c00                       mov    BYTE PTR [ebx+0xc],0x0
006D9936  e8d1781b00                     call   0x89120c
006D993B  83c404                         add    esp,0x4
006D993E  ff4f2c                         dec    DWORD PTR [edi+0x2c]
006D9941  8bde                           mov    ebx,esi
006D9943  eb02                           jmp    0x6d9947
006D9945  8b1b                           mov    ebx,DWORD PTR [ebx]
006D9947  3b5f28                         cmp    ebx,DWORD PTR [edi+0x28]
006D994A  75a5                           jne    0x6d98f1
006D994C  8b45f0                         mov    eax,DWORD PTR [ebp-0x10]
006D994F  50                             push   eax
006D9950  ff154822bd00                   call   DWORD PTR ds:0xbd2248
006D9956  6a21                           push   0x21
006D9958  ff150423bd00                   call   DWORD PTR ds:0xbd2304
006D995E  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
006D9961  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
006D9968  59                             pop    ecx
006D9969  5f                             pop    edi
006D996A  5e                             pop    esi
006D996B  5b                             pop    ebx
006D996C  8be5                           mov    esp,ebp
006D996E  5d                             pop    ebp
006D996F  c3                             ret

; music_stop_all [CURRENT_JOIN] 0x6d9cc0..0x6d9d96
006D9CC0  55                             push   ebp
006D9CC1  8bec                           mov    ebp,esp
006D9CC3  6aff                           push   0xffffffff
006D9CC5  68385f9100                     push   0x915f38
006D9CCA  64a100000000                   mov    eax,fs:0x0
006D9CD0  50                             push   eax
006D9CD1  51                             push   ecx
006D9CD2  53                             push   ebx
006D9CD3  57                             push   edi
006D9CD4  a1201fd600                     mov    eax,ds:0xd61f20
006D9CD9  33c5                           xor    eax,ebp
006D9CDB  50                             push   eax
006D9CDC  8d45f4                         lea    eax,[ebp-0xc]
006D9CDF  64a300000000                   mov    fs:0x0,eax
006D9CE5  8d9eb4000000                   lea    ebx,[esi+0xb4]
006D9CEB  53                             push   ebx
006D9CEC  895df0                         mov    DWORD PTR [ebp-0x10],ebx
006D9CEF  ff154c22bd00                   call   DWORD PTR ds:0xbd224c
006D9CF5  b801000000                     mov    eax,0x1
006D9CFA  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
006D9D01  84059816fc00                   test   BYTE PTR ds:0xfc1698,al
006D9D07  7518                           jne    0x6d9d21
006D9D09  09059816fc00                   or     DWORD PTR ds:0xfc1698,eax
006D9D0F  e88c2b1300                     call   0x80c8a0
006D9D14  6820e3bc00                     push   0xbce320
006D9D19  e8fc851b00                     call   0x89231a
006D9D1E  83c404                         add    esp,0x4
006D9D21  bfa016fc00                     mov    edi,0xfc16a0
006D9D26  8b0f                           mov    ecx,DWORD PTR [edi]
006D9D28  85c9                           test   ecx,ecx
006D9D2A  7407                           je     0x6d9d33
006D9D2C  8b01                           mov    eax,DWORD PTR [ecx]
006D9D2E  8b502c                         mov    edx,DWORD PTR [eax+0x2c]
006D9D31  ffd2                           call   edx
006D9D33  83c704                         add    edi,0x4
006D9D36  81ffe016fc00                   cmp    edi,0xfc16e0
006D9D3C  7ce8                           jl     0x6d9d26
006D9D3E  8d4628                         lea    eax,[esi+0x28]
006D9D41  50                             push   eax
006D9D42  e8f90d0000                     call   0x6dab40
006D9D47  33ff                           xor    edi,edi
006D9D49  57                             push   edi
006D9D4A  687523bf00                     push   0xbf2375
006D9D4F  8d4e38                         lea    ecx,[esi+0x38]
006D9D52  e8198dd2ff                     call   0x402a70
006D9D57  0f57c0                         xorps  xmm0,xmm0
006D9D5A  57                             push   edi
006D9D5B  687523bf00                     push   0xbf2375
006D9D60  8d4e70                         lea    ecx,[esi+0x70]
006D9D63  897e34                         mov    DWORD PTR [esi+0x34],edi
006D9D66  f30f114668                     movss  DWORD PTR [esi+0x68],xmm0
006D9D6B  e8008dd2ff                     call   0x402a70
006D9D70  0f57c0                         xorps  xmm0,xmm0
006D9D73  53                             push   ebx
006D9D74  897e6c                         mov    DWORD PTR [esi+0x6c],edi
006D9D77  f30f1186a0000000               movss  DWORD PTR [esi+0xa0],xmm0
006D9D7F  ff154822bd00                   call   DWORD PTR ds:0xbd2248
006D9D85  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
006D9D88  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
006D9D8F  59                             pop    ecx
006D9D90  5f                             pop    edi
006D9D91  5b                             pop    ebx
006D9D92  8be5                           mov    esp,ebp
006D9D94  5d                             pop    ebp
006D9D95  c3                             ret

; music_worker_binding [CURRENT_JOIN] 0x6d9059..0x6d909d
006D9059  6a0c                           push   0xc
006D905B  e808821b00                     call   0x891268
006D9060  83c404                         add    esp,0x4
006D9063  3bc3                           cmp    eax,ebx
006D9065  741b                           je     0x6d9082
006D9067  c700ec0fc400                   mov    DWORD PTR [eax],0xc40fec
006D906D  c74004c80ffc00                 mov    DWORD PTR [eax+0x4],0xfc0fc8
006D9074  c7400870986d00                 mov    DWORD PTR [eax+0x8],0x6d9870
006D907B  e8a0fcffff                     call   0x6d8d20
006D9080  eb0b                           jmp    0x6d908d
006D9082  33c0                           xor    eax,eax
006D9084  e897fcffff                     call   0x6d8d20
006D9089  eb02                           jmp    0x6d908d
006D908B  33c0                           xor    eax,eax
006D908D  c645fc08                       mov    BYTE PTR [ebp-0x4],0x8
006D9091  833ddc0ffc0010                 cmp    DWORD PTR ds:0xfc0fdc,0x10
006D9098  a37410fc00                     mov    ds:0xfc1074,eax

; music_stream_stop [CURRENT_JOIN] 0x80eb30..0x80eb8b
0080EB30  56                             push   esi
0080EB31  8bf1                           mov    esi,ecx
0080EB33  837e0800                       cmp    DWORD PTR [esi+0x8],0x0
0080EB37  c7460400000000                 mov    DWORD PTR [esi+0x4],0x0
0080EB3E  7412                           je     0x80eb52
0080EB40  57                             push   edi
0080EB41  8b3d0423bd00                   mov    edi,DWORD PTR ds:0xbd2304
0080EB47  6a0a                           push   0xa
0080EB49  ffd7                           call   edi
0080EB4B  837e0800                       cmp    DWORD PTR [esi+0x8],0x0
0080EB4F  75f6                           jne    0x80eb47
0080EB51  5f                             pop    edi
0080EB52  8b4e14                         mov    ecx,DWORD PTR [esi+0x14]
0080EB55  c7461800000000                 mov    DWORD PTR [esi+0x18],0x0
0080EB5C  8b01                           mov    eax,DWORD PTR [ecx]
0080EB5E  8b5008                         mov    edx,DWORD PTR [eax+0x8]
0080EB61  ffd2                           call   edx
0080EB63  8b4e10                         mov    ecx,DWORD PTR [esi+0x10]
0080EB66  85c9                           test   ecx,ecx
0080EB68  741d                           je     0x80eb87
0080EB6A  8b01                           mov    eax,DWORD PTR [ecx]
0080EB6C  8b10                           mov    edx,DWORD PTR [eax]
0080EB6E  ffd2                           call   edx
0080EB70  8b4610                         mov    eax,DWORD PTR [esi+0x10]
0080EB73  85c0                           test   eax,eax
0080EB75  7410                           je     0x80eb87
0080EB77  50                             push   eax
0080EB78  e88f260800                     call   0x89120c
0080EB7D  83c404                         add    esp,0x4
0080EB80  c7461000000000                 mov    DWORD PTR [esi+0x10],0x0
0080EB87  33c0                           xor    eax,eax
0080EB89  5e                             pop    esi
0080EB8A  c3                             ret

; q_music_stop [CURRENT_JOIN] 0x564500..0x564576
00564500  55                             push   ebp
00564501  8bec                           mov    ebp,esp
00564503  6aff                           push   0xffffffff
00564505  684eb29100                     push   0x91b24e
0056450A  64a100000000                   mov    eax,fs:0x0
00564510  50                             push   eax
00564511  51                             push   ecx
00564512  56                             push   esi
00564513  a1201fd600                     mov    eax,ds:0xd61f20
00564518  33c5                           xor    eax,ebp
0056451A  50                             push   eax
0056451B  8d45f4                         lea    eax,[ebp-0xc]
0056451E  64a300000000                   mov    fs:0x0,eax
00564524  b801000000                     mov    eax,0x1
00564529  8405c00ffc00                   test   BYTE PTR ds:0xfc0fc0,al
0056452F  7526                           jne    0x564557
00564531  0905c00ffc00                   or     DWORD PTR ds:0xfc0fc0,eax
00564537  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0056453E  e80d491700                     call   0x6d8e50
00564543  68b0dbbc00                     push   0xbcdbb0
00564548  e8cddd3200                     call   0x89231a
0056454D  83c404                         add    esp,0x4
00564550  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
00564557  bec80ffc00                     mov    esi,0xfc0fc8
0056455C  e85f571700                     call   0x6d9cc0
00564561  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
00564564  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0056456B  59                             pop    ecx
0056456C  5e                             pop    esi
0056456D  8be5                           mov    esp,ebp
0056456F  5d                             pop    ebp
00564570  c3                             ret
00564571  cc                             int3
00564572  cc                             int3
00564573  cc                             int3
00564574  cc                             int3
00564575  cc                             int3
