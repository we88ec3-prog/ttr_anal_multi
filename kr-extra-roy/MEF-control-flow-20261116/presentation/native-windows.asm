; MEF R10 presentation: verified native excerpts, end-exclusive VA windows.
; Code/data are separate. No inferred C signatures used as the native proof.

; q_end [0x561db0,0x5620aa) raw=0x1611b0 sha256=7223d999bb2cbb1f717f5abc13332fde0f434450d5a8428bcc680ce276e3324b End active/confirmation/list/UI path
0x561db0   55                                 push   ebp
0x561db1   8bec                               mov    ebp,esp
0x561db3   83e4f8                             and    esp,0xfffffff8
0x561db6   6aff                               push   0xffffffff
0x561db8   6864fc9300                         push   0x93fc64
0x561dbd   64a100000000                       mov    eax,fs:0x0
0x561dc3   50                                 push   eax
0x561dc4   83ec10                             sub    esp,0x10
0x561dc7   53                                 push   ebx
0x561dc8   56                                 push   esi
0x561dc9   57                                 push   edi
0x561dca   a1201fd600                         mov    eax,ds:0xd61f20
0x561dcf   33c4                               xor    eax,esp
0x561dd1   50                                 push   eax
0x561dd2   8d442420                           lea    eax,[esp+0x20]
0x561dd6   64a300000000                       mov    fs:0x0,eax
0x561ddc   8bf9                               mov    edi,ecx
0x561dde   33f6                               xor    esi,esi
0x561de0   80bf8900000000                     cmp    BYTE PTR [edi+0x89],0x0
0x561de7   0f8473010000                       je     0x561f60
0x561ded   397728                             cmp    DWORD PTR [edi+0x28],esi
0x561df0   0f84aa000000                       je     0x561ea0
0x561df6   897728                             mov    DWORD PTR [edi+0x28],esi
0x561df9   e85224edff                         call   0x434250
0x561dfe   bb01000000                         mov    ebx,0x1
0x561e03   895814                             mov    DWORD PTR [eax+0x14],ebx
0x561e06   841dd4f3fd00                       test   BYTE PTR ds:0xfdf3d4,bl
0x561e0c   7525                               jne    0x561e33
0x561e0e   091dd4f3fd00                       or     DWORD PTR ds:0xfdf3d4,ebx
0x561e14   89742428                           mov    DWORD PTR [esp+0x28],esi
0x561e18   e863251900                         call   0x6f4380
0x561e1d   68d0e6bc00                         push   0xbce6d0
0x561e22   e8f3043300                         call   0x89231a
0x561e27   83c404                             add    esp,0x4
0x561e2a   83ceff                             or     esi,0xffffffff
0x561e2d   89742428                           mov    DWORD PTR [esp+0x28],esi
0x561e31   eb03                               jmp    0x561e36
0x561e33   83ceff                             or     esi,0xffffffff
0x561e36   68ec06c100                         push   0xc106ec
0x561e3b   6a00                               push   0x0
0x561e3d   68c8f3fd00                         push   0xfdf3c8
0x561e42   e859b2f4ff                         call   0x4ad0a0
0x561e47   f605d4adfa0001                     test   BYTE PTR ds:0xfaadd4,0x1
0x561e4e   7520                               jne    0x561e70
0x561e50   091dd4adfa00                       or     DWORD PTR ds:0xfaadd4,ebx
0x561e56   895c2428                           mov    DWORD PTR [esp+0x28],ebx
0x561e5a   e821560200                         call   0x587480
0x561e5f   68c0ccbc00                         push   0xbcccc0
0x561e64   e8b1043300                         call   0x89231a
0x561e69   83c404                             add    esp,0x4
0x561e6c   89742428                           mov    DWORD PTR [esp+0x28],esi
0x561e70   d98784000000                       fld    DWORD PTR [edi+0x84]
0x561e76   83ec08                             sub    esp,0x8
0x561e79   d95c241c                           fstp   DWORD PTR [esp+0x1c]
0x561e7d   d944241c                           fld    DWORD PTR [esp+0x1c]
0x561e81   d9542404                           fst    DWORD PTR [esp+0x4]
0x561e85   d91c24                             fstp   DWORD PTR [esp]
0x561e88   e8937b0200                         call   0x589a20
0x561e8d   8a9f88000000                       mov    bl,BYTE PTR [edi+0x88]
0x561e93   e8082deaff                         call   0x404ba0
0x561e98   8898c4680000                       mov    BYTE PTR [eax+0x68c4],bl
0x561e9e   eb03                               jmp    0x561ea3
0x561ea0   83ceff                             or     esi,0xffffffff
0x561ea3   f605640ffc0001                     test   BYTE PTR ds:0xfc0f64,0x1
0x561eaa   7525                               jne    0x561ed1
0x561eac   830d640ffc0001                     or     DWORD PTR ds:0xfc0f64,0x1
0x561eb3   c744242802000000                   mov    DWORD PTR [esp+0x28],0x2
0x561ebb   e820bef1ff                         call   0x47dce0
0x561ec0   68f0dabc00                         push   0xbcdaf0
0x561ec5   e850043300                         call   0x89231a
0x561eca   83c404                             add    esp,0x4
0x561ecd   89742428                           mov    DWORD PTR [esp+0x28],esi
0x561ed1   8b473c                             mov    eax,DWORD PTR [edi+0x3c]
0x561ed4   8b4f38                             mov    ecx,DWORD PTR [edi+0x38]
0x561ed7   50                                 push   eax
0x561ed8   51                                 push   ecx
0x561ed9   68680ffc00                         push   0xfc0f68
0x561ede   e85dc7f1ff                         call   0x47e640
0x561ee3   33db                               xor    ebx,ebx
0x561ee5   89473c                             mov    DWORD PTR [edi+0x3c],eax
0x561ee8   3bc3                               cmp    eax,ebx
0x561eea   741f                               je     0x561f0b
0x561eec   8b5738                             mov    edx,DWORD PTR [edi+0x38]
0x561eef   50                                 push   eax
0x561ef0   52                                 push   edx
0x561ef1   8bf7                               mov    esi,edi
0x561ef3   e828380000                         call   0x565720
0x561ef8   8b4c2420                           mov    ecx,DWORD PTR [esp+0x20]
0x561efc   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x561f03   59                                 pop    ecx
0x561f04   5f                                 pop    edi
0x561f05   5e                                 pop    esi
0x561f06   5b                                 pop    ebx
0x561f07   8be5                               mov    esp,ebp
0x561f09   5d                                 pop    ebp
0x561f0a   c3                                 ret
0x561f0b   f605c00ffc0001                     test   BYTE PTR ds:0xfc0fc0,0x1
0x561f12   7525                               jne    0x561f39
0x561f14   830dc00ffc0001                     or     DWORD PTR ds:0xfc0fc0,0x1
0x561f1b   c744242803000000                   mov    DWORD PTR [esp+0x28],0x3
0x561f23   e8286f1700                         call   0x6d8e50
0x561f28   68b0dbbc00                         push   0xbcdbb0
0x561f2d   e8e8033300                         call   0x89231a
0x561f32   83c404                             add    esp,0x4
0x561f35   89742428                           mov    DWORD PTR [esp+0x28],esi
0x561f39   8b4734                             mov    eax,DWORD PTR [edi+0x34]
0x561f3c   50                                 push   eax
0x561f3d   b9c80ffc00                         mov    ecx,0xfc0fc8
0x561f42   e8e9741700                         call   0x6d9430
0x561f47   895f38                             mov    DWORD PTR [edi+0x38],ebx
0x561f4a   895f3c                             mov    DWORD PTR [edi+0x3c],ebx
0x561f4d   8b4c2420                           mov    ecx,DWORD PTR [esp+0x20]
0x561f51   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x561f58   59                                 pop    ecx
0x561f59   5f                                 pop    edi
0x561f5a   5e                                 pop    esi
0x561f5b   5b                                 pop    ebx
0x561f5c   8be5                               mov    esp,ebp
0x561f5e   5d                                 pop    ebp
0x561f5f   c3                                 ret
0x561f60   397728                             cmp    DWORD PTR [edi+0x28],esi
0x561f63   0f8428010000                       je     0x562091
0x561f69   897728                             mov    DWORD PTR [edi+0x28],esi
0x561f6c   e8df22edff                         call   0x434250
0x561f71   bb01000000                         mov    ebx,0x1
0x561f76   895814                             mov    DWORD PTR [eax+0x14],ebx
0x561f79   397738                             cmp    DWORD PTR [edi+0x38],esi
0x561f7c   7439                               je     0x561fb7
0x561f7e   684403c100                         push   0xc10344
0x561f83   53                                 push   ebx
0x561f84   e8a792f3ff                         call   0x49b230
0x561f89   50                                 push   eax
0x561f8a   e811b1f4ff                         call   0x4ad0a0
0x561f8f   6aff                               push   0xffffffff
0x561f91   51                                 push   ecx
0x561f92   e89992f3ff                         call   0x49b230
0x561f97   83c404                             add    esp,0x4
0x561f9a   e8b10bf4ff                         call   0x4a2b50
0x561f9f   3bc3                               cmp    eax,ebx
0x561fa1   754e                               jne    0x561ff1
0x561fa3   e8d826ebff                         call   0x414680
0x561fa8   8b4f3c                             mov    ecx,DWORD PTR [edi+0x3c]
0x561fab   8b5738                             mov    edx,DWORD PTR [edi+0x38]
0x561fae   51                                 push   ecx
0x561faf   52                                 push   edx
0x561fb0   e8eb19f4ff                         call   0x4a39a0
0x561fb5   eb3a                               jmp    0x561ff1
0x561fb7   8d5f3c                             lea    ebx,[edi+0x3c]
0x561fba   8d7774                             lea    esi,[edi+0x74]
0x561fbd   53                                 push   ebx
0x561fbe   e87dbe1500                         call   0x6bde40
0x561fc3   50                                 push   eax
0x561fc4   56                                 push   esi
0x561fc5   8d74241c                           lea    esi,[esp+0x1c]
0x561fc9   e8c248edff                         call   0x436890
0x561fce   57                                 push   edi
0x561fcf   e8cc030000                         call   0x5623a0
0x561fd4   e8a726ebff                         call   0x414680
0x561fd9   8b03                               mov    eax,DWORD PTR [ebx]
0x561fdb   8b4f38                             mov    ecx,DWORD PTR [edi+0x38]
0x561fde   50                                 push   eax
0x561fdf   51                                 push   ecx
0x561fe0   e8bb19f4ff                         call   0x4a39a0
0x561fe5   e8c6000000                         call   0x5620b0
0x561fea   bb01000000                         mov    ebx,0x1
0x561fef   33f6                               xor    esi,esi
0x561ff1   f605d4f3fd0001                     test   BYTE PTR ds:0xfdf3d4,0x1
0x561ff8   7528                               jne    0x562022
0x561ffa   091dd4f3fd00                       or     DWORD PTR ds:0xfdf3d4,ebx
0x562000   c744242804000000                   mov    DWORD PTR [esp+0x28],0x4
0x562008   e873231900                         call   0x6f4380
0x56200d   68d0e6bc00                         push   0xbce6d0
0x562012   e803033300                         call   0x89231a
0x562017   83c404                             add    esp,0x4
0x56201a   c7442428ffffffff                   mov    DWORD PTR [esp+0x28],0xffffffff
0x562022   68ec06c100                         push   0xc106ec
0x562027   56                                 push   esi
0x562028   68c8f3fd00                         push   0xfdf3c8
0x56202d   e86eb0f4ff                         call   0x4ad0a0
0x562032   f605d4adfa0001                     test   BYTE PTR ds:0xfaadd4,0x1
0x562039   7528                               jne    0x562063
0x56203b   091dd4adfa00                       or     DWORD PTR ds:0xfaadd4,ebx
0x562041   c744242805000000                   mov    DWORD PTR [esp+0x28],0x5
0x562049   e832540200                         call   0x587480
0x56204e   68c0ccbc00                         push   0xbcccc0
0x562053   e8c2023300                         call   0x89231a
0x562058   83c404                             add    esp,0x4
0x56205b   c7442428ffffffff                   mov    DWORD PTR [esp+0x28],0xffffffff
0x562063   d98784000000                       fld    DWORD PTR [edi+0x84]
0x562069   83ec08                             sub    esp,0x8
0x56206c   d95c241c                           fstp   DWORD PTR [esp+0x1c]
0x562070   d944241c                           fld    DWORD PTR [esp+0x1c]
0x562074   d9542404                           fst    DWORD PTR [esp+0x4]
0x562078   d91c24                             fstp   DWORD PTR [esp]
0x56207b   e8a0790200                         call   0x589a20
0x562080   8a9f88000000                       mov    bl,BYTE PTR [edi+0x88]
0x562086   e8152beaff                         call   0x404ba0
0x56208b   8898c4680000                       mov    BYTE PTR [eax+0x68c4],bl
0x562091   897738                             mov    DWORD PTR [edi+0x38],esi
0x562094   89773c                             mov    DWORD PTR [edi+0x3c],esi
0x562097   8b4c2420                           mov    ecx,DWORD PTR [esp+0x20]
0x56209b   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x5620a2   59                                 pop    ecx
0x5620a3   5f                                 pop    edi
0x5620a4   5e                                 pop    esi
0x5620a5   5b                                 pop    ebx
0x5620a6   8be5                               mov    esp,ebp
0x5620a8   5d                                 pop    ebp
0x5620a9   c3                                 ret

; q_stop [0x5624b0,0x5628b1) raw=0x1618b0 sha256=26f5d929e2c917f4e74f3747d539d53dbe0005fba82989f00170e36e5e56ecc9 Stop active guard, ordered bulk cleanup then End
0x5624b0   55                                 push   ebp
0x5624b1   8bec                               mov    ebp,esp
0x5624b3   83e4f8                             and    esp,0xfffffff8
0x5624b6   6aff                               push   0xffffffff
0x5624b8   68603d9400                         push   0x943d60
0x5624bd   64a100000000                       mov    eax,fs:0x0
0x5624c3   50                                 push   eax
0x5624c4   83ec28                             sub    esp,0x28
0x5624c7   a1201fd600                         mov    eax,ds:0xd61f20
0x5624cc   33c4                               xor    eax,esp
0x5624ce   89442420                           mov    DWORD PTR [esp+0x20],eax
0x5624d2   53                                 push   ebx
0x5624d3   56                                 push   esi
0x5624d4   57                                 push   edi
0x5624d5   a1201fd600                         mov    eax,ds:0xd61f20
0x5624da   33c4                               xor    eax,esp
0x5624dc   50                                 push   eax
0x5624dd   8d442438                           lea    eax,[esp+0x38]
0x5624e1   64a300000000                       mov    fs:0x0,eax
0x5624e7   33f6                               xor    esi,esi
0x5624e9   8bf9                               mov    edi,ecx
0x5624eb   897c2410                           mov    DWORD PTR [esp+0x10],edi
0x5624ef   397508                             cmp    DWORD PTR [ebp+0x8],esi
0x5624f2   742a                               je     0x56251e
0x5624f4   817f38e8030000                     cmp    DWORD PTR [edi+0x38],0x3e8
0x5624fb   7521                               jne    0x56251e
0x5624fd   8b473c                             mov    eax,DWORD PTR [edi+0x3c]
0x562500   83f80f                             cmp    eax,0xf
0x562503   740f                               je     0x562514
0x562505   83f810                             cmp    eax,0x10
0x562508   740a                               je     0x562514
0x56250a   83f811                             cmp    eax,0x11
0x56250d   7405                               je     0x562514
0x56250f   83f812                             cmp    eax,0x12
0x562512   750a                               jne    0x56251e
0x562514   c705a0a7fb0001000000               mov    DWORD PTR ds:0xfba7a0,0x1
0x56251e   397728                             cmp    DWORD PTR [edi+0x28],esi
0x562521   0f846a030000                       je     0x562891
0x562527   83cbff                             or     ebx,0xffffffff
0x56252a   f6051c76fb0001                     test   BYTE PTR ds:0xfb761c,0x1
0x562531   7521                               jne    0x562554
0x562533   830d1c76fb0001                     or     DWORD PTR ds:0xfb761c,0x1
0x56253a   89742440                           mov    DWORD PTR [esp+0x40],esi
0x56253e   e80dc2feff                         call   0x54e750
0x562543   6860d2bc00                         push   0xbcd260
0x562548   e8cdfd3200                         call   0x89231a
0x56254d   83c404                             add    esp,0x4
0x562550   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x562554   8b0d2076fb00                       mov    ecx,DWORD PTR ds:0xfb7620
0x56255a   3bce                               cmp    ecx,esi
0x56255c   7407                               je     0x562565
0x56255e   8b01                               mov    eax,DWORD PTR [ecx]
0x562560   8b500c                             mov    edx,DWORD PTR [eax+0xc]
0x562563   ffd2                               call   edx
0x562565   e8f676f2ff                         call   0x489c60
0x56256a   b920000000                         mov    ecx,0x20
0x56256f   90                                 nop
0x562570   8930                               mov    DWORD PTR [eax],esi
0x562572   83c014                             add    eax,0x14
0x562575   49                                 dec    ecx
0x562576   75f8                               jne    0x562570
0x562578   f605881bfc0001                     test   BYTE PTR ds:0xfc1b88,0x1
0x56257f   7525                               jne    0x5625a6
0x562581   b801000000                         mov    eax,0x1
0x562586   0905881bfc00                       or     DWORD PTR ds:0xfc1b88,eax
0x56258c   89442440                           mov    DWORD PTR [esp+0x40],eax
0x562590   e87bf60100                         call   0x581c10
0x562595   68a0dfbc00                         push   0xbcdfa0
0x56259a   e87bfd3200                         call   0x89231a
0x56259f   83c404                             add    esp,0x4
0x5625a2   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x5625a6   a1901bfc00                         mov    eax,ds:0xfc1b90
0x5625ab   8935c01bfc00                       mov    DWORD PTR ds:0xfc1bc0,esi
0x5625b1   8935bc1bfc00                       mov    DWORD PTR ds:0xfc1bbc,esi
0x5625b7   3bc6                               cmp    eax,esi
0x5625b9   740c                               je     0x5625c7
0x5625bb   50                                 push   eax
0x5625bc   e80f22f4ff                         call   0x4a47d0
0x5625c1   8935901bfc00                       mov    DWORD PTR ds:0xfc1b90,esi
0x5625c7   f605f41bfc0001                     test   BYTE PTR ds:0xfc1bf4,0x1
0x5625ce   7525                               jne    0x5625f5
0x5625d0   830df41bfc0001                     or     DWORD PTR ds:0xfc1bf4,0x1
0x5625d7   c744244002000000                   mov    DWORD PTR [esp+0x40],0x2
0x5625df   e8acc90100                         call   0x57ef90
0x5625e4   68b0dfbc00                         push   0xbcdfb0
0x5625e9   e82cfd3200                         call   0x89231a
0x5625ee   83c404                             add    esp,0x4
0x5625f1   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x5625f5   89356c1cfc00                       mov    DWORD PTR ds:0xfc1c6c,esi
0x5625fb   8b4754                             mov    eax,DWORD PTR [edi+0x54]
0x5625fe   bf04000000                         mov    edi,0x4
0x562603   3bc6                               cmp    eax,esi
0x562605   0f857c000000                       jne    0x562687
0x56260b   f605e81efe0001                     test   BYTE PTR ds:0xfe1ee8,0x1
0x562612   7525                               jne    0x562639
0x562614   830de81efe0001                     or     DWORD PTR ds:0xfe1ee8,0x1
0x56261b   c744244003000000                   mov    DWORD PTR [esp+0x40],0x3
0x562623   e8e89fffff                         call   0x55c610
0x562628   6890f2bc00                         push   0xbcf290
0x56262d   e8e8fc3200                         call   0x89231a
0x562632   83c404                             add    esp,0x4
0x562635   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x562639   68ec1efe00                         push   0xfe1eec
0x56263e   8d742418                           lea    esi,[esp+0x18]
0x562642   e879d9ffff                         call   0x55ffc0
0x562647   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x56264b   50                                 push   eax
0x56264c   83c144                             add    ecx,0x44
0x56264f   897c2444                           mov    DWORD PTR [esp+0x44],edi
0x562653   e85805eaff                         call   0x402bb0
0x562658   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x56265c   837c242810                         cmp    DWORD PTR [esp+0x28],0x10
0x562661   720d                               jb     0x562670
0x562663   8b442414                           mov    eax,DWORD PTR [esp+0x14]
0x562667   50                                 push   eax
0x562668   e89feb3200                         call   0x89120c
0x56266d   83c404                             add    esp,0x4
0x562670   c74424280f000000                   mov    DWORD PTR [esp+0x28],0xf
0x562678   c744242400000000                   mov    DWORD PTR [esp+0x24],0x0
0x562680   c644241400                         mov    BYTE PTR [esp+0x14],0x0
0x562685   33f6                               xor    esi,esi
0x562687   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x56268b   e810190000                         call   0x563fa0
0x562690   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x562694   e8d7130000                         call   0x563a70
0x562699   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x56269d   e85e040000                         call   0x562b00
0x5626a2   397508                             cmp    DWORD PTR [ebp+0x8],esi
0x5626a5   743a                               je     0x5626e1
0x5626a7   f605141bfc0001                     test   BYTE PTR ds:0xfc1b14,0x1
0x5626ae   7525                               jne    0x5626d5
0x5626b0   830d141bfc0001                     or     DWORD PTR ds:0xfc1b14,0x1
0x5626b7   c744244005000000                   mov    DWORD PTR [esp+0x40],0x5
0x5626bf   e8ccc7ffff                         call   0x55ee90
0x5626c4   6890dfbc00                         push   0xbcdf90
0x5626c9   e84cfc3200                         call   0x89231a
0x5626ce   83c404                             add    esp,0x4
0x5626d1   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x5626d5   be181bfc00                         mov    esi,0xfc1b18
0x5626da   e8c1d1ffff                         call   0x55f8a0
0x5626df   33f6                               xor    esi,esi
0x5626e1   e88ad8ffff                         call   0x55ff70
0x5626e6   f6054027fe0001                     test   BYTE PTR ds:0xfe2740,0x1
0x5626ed   89700c                             mov    DWORD PTR [eax+0xc],esi
0x5626f0   7525                               jne    0x562717
0x5626f2   830d4027fe0001                     or     DWORD PTR ds:0xfe2740,0x1
0x5626f9   c744244006000000                   mov    DWORD PTR [esp+0x40],0x6
0x562701   e87abfffff                         call   0x55e680
0x562706   68a0f2bc00                         push   0xbcf2a0
0x56270b   e80afc3200                         call   0x89231a
0x562710   83c404                             add    esp,0x4
0x562713   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x562717   397508                             cmp    DWORD PTR [ebp+0x8],esi
0x56271a   7406                               je     0x562722
0x56271c   89355427fe00                       mov    DWORD PTR ds:0xfe2754,esi
0x562722   f605dc36fe0001                     test   BYTE PTR ds:0xfe36dc,0x1
0x562729   89355027fe00                       mov    DWORD PTR ds:0xfe2750,esi
0x56272f   7507                               jne    0x562738
0x562731   830ddc36fe0001                     or     DWORD PTR ds:0xfe36dc,0x1
0x562738   f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
0x56273f   893dd436fe00                       mov    DWORD PTR ds:0xfe36d4,edi
0x562745   8935d836fe00                       mov    DWORD PTR ds:0xfe36d8,esi
0x56274b   7525                               jne    0x562772
0x56274d   830d2cb2fa0001                     or     DWORD PTR ds:0xfab22c,0x1
0x562754   c744244007000000                   mov    DWORD PTR [esp+0x40],0x7
0x56275c   e82fc5f7ff                         call   0x4dec90
0x562761   6830cebc00                         push   0xbcce30
0x562766   e8affb3200                         call   0x89231a
0x56276b   83c404                             add    esp,0x4
0x56276e   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x562772   f605d4adfa0001                     test   BYTE PTR ds:0xfaadd4,0x1
0x562779   8935e0b1fa00                       mov    DWORD PTR ds:0xfab1e0,esi
0x56277f   7525                               jne    0x5627a6
0x562781   830dd4adfa0001                     or     DWORD PTR ds:0xfaadd4,0x1
0x562788   c744244008000000                   mov    DWORD PTR [esp+0x40],0x8
0x562790   e8eb4c0200                         call   0x587480
0x562795   68c0ccbc00                         push   0xbcccc0
0x56279a   e87bfb3200                         call   0x89231a
0x56279f   83c404                             add    esp,0x4
0x5627a2   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x5627a6   684e430f00                         push   0xf434e
0x5627ab   e820830200                         call   0x58aad0
0x5627b0   83c404                             add    esp,0x4
0x5627b3   f605d4adfa0001                     test   BYTE PTR ds:0xfaadd4,0x1
0x5627ba   bf01000000                         mov    edi,0x1
0x5627bf   7524                               jne    0x5627e5
0x5627c1   093dd4adfa00                       or     DWORD PTR ds:0xfaadd4,edi
0x5627c7   c744244009000000                   mov    DWORD PTR [esp+0x40],0x9
0x5627cf   e8ac4c0200                         call   0x587480
0x5627d4   68c0ccbc00                         push   0xbcccc0
0x5627d9   e83cfb3200                         call   0x89231a
0x5627de   83c404                             add    esp,0x4
0x5627e1   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x5627e5   e8268d0200                         call   0x58b510
0x5627ea   f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
0x5627f1   7524                               jne    0x562817
0x5627f3   093d2cb2fa00                       or     DWORD PTR ds:0xfab22c,edi
0x5627f9   c74424400a000000                   mov    DWORD PTR [esp+0x40],0xa
0x562801   e88ac4f7ff                         call   0x4dec90
0x562806   6830cebc00                         push   0xbcce30
0x56280b   e80afb3200                         call   0x89231a
0x562810   83c404                             add    esp,0x4
0x562813   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x562817   f605147cfb0001                     test   BYTE PTR ds:0xfb7c14,0x1
0x56281e   8935d8b1fa00                       mov    DWORD PTR ds:0xfab1d8,esi
0x562824   7524                               jne    0x56284a
0x562826   093d147cfb00                       or     DWORD PTR ds:0xfb7c14,edi
0x56282c   c74424400b000000                   mov    DWORD PTR [esp+0x40],0xb
0x562834   e817df1600                         call   0x6d0750
0x562839   6830d5bc00                         push   0xbcd530
0x56283e   e8d7fa3200                         call   0x89231a
0x562843   83c404                             add    esp,0x4
0x562846   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x56284a   83253088fb00fd                     and    DWORD PTR ds:0xfb8830,0xfffffffd
0x562851   f6055473fb0001                     test   BYTE PTR ds:0xfb7354,0x1
0x562858   7524                               jne    0x56287e
0x56285a   093d5473fb00                       or     DWORD PTR ds:0xfb7354,edi
0x562860   c74424400c000000                   mov    DWORD PTR [esp+0x40],0xc
0x562868   e8630bffff                         call   0x5533d0
0x56286d   6800d1bc00                         push   0xbcd100
0x562872   e8a3fa3200                         call   0x89231a
0x562877   83c404                             add    esp,0x4
0x56287a   895c2440                           mov    DWORD PTR [esp+0x40],ebx
0x56287e   b85873fb00                         mov    eax,0xfb7358
0x562883   e8b80effff                         call   0x553740
0x562888   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x56288c   e81ff5ffff                         call   0x561db0
0x562891   8b4c2438                           mov    ecx,DWORD PTR [esp+0x38]
0x562895   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x56289c   59                                 pop    ecx
0x56289d   5f                                 pop    edi
0x56289e   5e                                 pop    esi
0x56289f   5b                                 pop    ebx
0x5628a0   8b4c2420                           mov    ecx,DWORD PTR [esp+0x20]
0x5628a4   33cc                               xor    ecx,esp
0x5628a6   e856e73200                         call   0x891001
0x5628ab   8be5                               mov    esp,ebp
0x5628ad   5d                                 pop    ebp
0x5628ae   c20400                             ret    0x4

; begin_override [0x562a60,0x562af2) raw=0x161e60 sha256=d61210fec505707c1a82524402bce6a22fa0d05e53be0c7326f4190bc08340da Push camera snapshot and name QSceneCam
0x562a60   55                                 push   ebp
0x562a61   8bec                               mov    ebp,esp
0x562a63   6aff                               push   0xffffffff
0x562a65   689eb79200                         push   0x92b79e
0x562a6a   64a100000000                       mov    eax,fs:0x0
0x562a70   50                                 push   eax
0x562a71   51                                 push   ecx
0x562a72   56                                 push   esi
0x562a73   a1201fd600                         mov    eax,ds:0xd61f20
0x562a78   33c5                               xor    eax,ebp
0x562a7a   50                                 push   eax
0x562a7b   8d45f4                             lea    eax,[ebp-0xc]
0x562a7e   64a300000000                       mov    fs:0x0,eax
0x562a84   b801000000                         mov    eax,0x1
0x562a89   8405e879fb00                       test   BYTE PTR ds:0xfb79e8,al
0x562a8f   7526                               jne    0x562ab7
0x562a91   0905e879fb00                       or     DWORD PTR ds:0xfb79e8,eax
0x562a97   c745fc00000000                     mov    DWORD PTR [ebp-0x4],0x0
0x562a9e   e83d632300                         call   0x798de0
0x562aa3   68e0d2bc00                         push   0xbcd2e0
0x562aa8   e86df83200                         call   0x89231a
0x562aad   83c404                             add    esp,0x4
0x562ab0   c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
0x562ab7   a1e876fb00                         mov    eax,ds:0xfb76e8
0x562abc   8d480c                             lea    ecx,[eax+0xc]
0x562abf   8bf0                               mov    esi,eax
0x562ac1   51                                 push   ecx
0x562ac2   05a0000000                         add    eax,0xa0
0x562ac7   50                                 push   eax
0x562ac8   e8335e2300                         call   0x798900
0x562acd   8b8ea4000000                       mov    ecx,DWORD PTR [esi+0xa4]
0x562ad3   6a09                               push   0x9
0x562ad5   680c07c100                         push   0xc1070c
0x562ada   83e91c                             sub    ecx,0x1c
0x562add   e88effe9ff                         call   0x402a70
0x562ae2   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x562ae5   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x562aec   59                                 pop    ecx
0x562aed   5e                                 pop    esi
0x562aee   8be5                               mov    esp,ebp
0x562af0   5d                                 pop    ebp
0x562af1   c3                                 ret

; end_override [0x562b00,0x562b74) raw=0x161f00 sha256=6280230ca0a8348531199dcab8393eb5f481d7cff7447ebb4244d911814ad95b Pop camera by QSceneCam label
0x562b00   55                                 push   ebp
0x562b01   8bec                               mov    ebp,esp
0x562b03   6aff                               push   0xffffffff
0x562b05   688ebc9200                         push   0x92bc8e
0x562b0a   64a100000000                       mov    eax,fs:0x0
0x562b10   50                                 push   eax
0x562b11   a1201fd600                         mov    eax,ds:0xd61f20
0x562b16   33c5                               xor    eax,ebp
0x562b18   50                                 push   eax
0x562b19   8d45f4                             lea    eax,[ebp-0xc]
0x562b1c   64a300000000                       mov    fs:0x0,eax
0x562b22   b801000000                         mov    eax,0x1
0x562b27   8405e879fb00                       test   BYTE PTR ds:0xfb79e8,al
0x562b2d   7526                               jne    0x562b55
0x562b2f   0905e879fb00                       or     DWORD PTR ds:0xfb79e8,eax
0x562b35   c745fc00000000                     mov    DWORD PTR [ebp-0x4],0x0
0x562b3c   e89f622300                         call   0x798de0
0x562b41   68e0d2bc00                         push   0xbcd2e0
0x562b46   e8cff73200                         call   0x89231a
0x562b4b   83c404                             add    esp,0x4
0x562b4e   c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
0x562b55   a1e876fb00                         mov    eax,ds:0xfb76e8
0x562b5a   680c07c100                         push   0xc1070c
0x562b5f   50                                 push   eax
0x562b60   e87b5b2300                         call   0x7986e0
0x562b65   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x562b68   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x562b6f   59                                 pop    ecx
0x562b70   8be5                               mov    esp,ebp
0x562b72   5d                                 pop    ebp
0x562b73   c3                                 ret

; camera_push [0x798900,0x7989d3) raw=0x397d00 sha256=6fd8b5ce24f6390f2f4e1759ec102de6b8fb33c572c93fc199a86e69f35623d9 0x48-byte record append
0x798900   55                                 push   ebp
0x798901   8bec                               mov    ebp,esp
0x798903   6aff                               push   0xffffffff
0x798905   6892529100                         push   0x915292
0x79890a   64a100000000                       mov    eax,fs:0x0
0x798910   50                                 push   eax
0x798911   51                                 push   ecx
0x798912   53                                 push   ebx
0x798913   56                                 push   esi
0x798914   57                                 push   edi
0x798915   a1201fd600                         mov    eax,ds:0xd61f20
0x79891a   33c5                               xor    eax,ebp
0x79891c   50                                 push   eax
0x79891d   8d45f4                             lea    eax,[ebp-0xc]
0x798920   64a300000000                       mov    fs:0x0,eax
0x798926   8b5d0c                             mov    ebx,DWORD PTR [ebp+0xc]
0x798929   8b7d08                             mov    edi,DWORD PTR [ebp+0x8]
0x79892c   8b4f04                             mov    ecx,DWORD PTR [edi+0x4]
0x79892f   3bd9                               cmp    ebx,ecx
0x798931   733d                               jae    0x798970
0x798933   8b07                               mov    eax,DWORD PTR [edi]
0x798935   3bc3                               cmp    eax,ebx
0x798937   7737                               ja     0x798970
0x798939   2bd8                               sub    ebx,eax
0x79893b   b8398ee338                         mov    eax,0x38e38e39
0x798940   f7eb                               imul   ebx
0x798942   c1fa04                             sar    edx,0x4
0x798945   8bf2                               mov    esi,edx
0x798947   c1ee1f                             shr    esi,0x1f
0x79894a   03f2                               add    esi,edx
0x79894c   3b4f08                             cmp    ecx,DWORD PTR [edi+0x8]
0x79894f   7507                               jne    0x798958
0x798951   8bcf                               mov    ecx,edi
0x798953   e888000000                         call   0x7989e0
0x798958   8b0f                               mov    ecx,DWORD PTR [edi]
0x79895a   8d04f6                             lea    eax,[esi+esi*8]
0x79895d   8d1cc1                             lea    ebx,[ecx+eax*8]
0x798960   8b4704                             mov    eax,DWORD PTR [edi+0x4]
0x798963   89450c                             mov    DWORD PTR [ebp+0xc],eax
0x798966   8945f0                             mov    DWORD PTR [ebp-0x10],eax
0x798969   33d2                               xor    edx,edx
0x79896b   8955fc                             mov    DWORD PTR [ebp-0x4],edx
0x79896e   eb1e                               jmp    0x79898e
0x798970   3b4f08                             cmp    ecx,DWORD PTR [edi+0x8]
0x798973   7507                               jne    0x79897c
0x798975   8bcf                               mov    ecx,edi
0x798977   e864000000                         call   0x7989e0
0x79897c   8b4704                             mov    eax,DWORD PTR [edi+0x4]
0x79897f   89450c                             mov    DWORD PTR [ebp+0xc],eax
0x798982   8945f0                             mov    DWORD PTR [ebp-0x10],eax
0x798985   c745fc01000000                     mov    DWORD PTR [ebp-0x4],0x1
0x79898c   33d2                               xor    edx,edx
0x79898e   3bc2                               cmp    eax,edx
0x798990   7429                               je     0x7989bb
0x798992   8bf8                               mov    edi,eax
0x798994   8bf3                               mov    esi,ebx
0x798996   b90b000000                         mov    ecx,0xb
0x79899b   f3a5                               rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x79899d   6aff                               push   0xffffffff
0x79899f   8d482c                             lea    ecx,[eax+0x2c]
0x7989a2   52                                 push   edx
0x7989a3   83c32c                             add    ebx,0x2c
0x7989a6   c741140f000000                     mov    DWORD PTR [ecx+0x14],0xf
0x7989ad   895110                             mov    DWORD PTR [ecx+0x10],edx
0x7989b0   53                                 push   ebx
0x7989b1   8811                               mov    BYTE PTR [ecx],dl
0x7989b3   e888a6c6ff                         call   0x403040
0x7989b8   8b7d08                             mov    edi,DWORD PTR [ebp+0x8]
0x7989bb   83470448                           add    DWORD PTR [edi+0x4],0x48
0x7989bf   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x7989c2   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x7989c9   59                                 pop    ecx
0x7989ca   5f                                 pop    edi
0x7989cb   5e                                 pop    esi
0x7989cc   5b                                 pop    ebx
0x7989cd   8be5                               mov    esp,ebp
0x7989cf   5d                                 pop    ebp
0x7989d0   c20800                             ret    0x8

; camera_pop [0x7986e0,0x7988f8) raw=0x397ae0 sha256=394b5c8c7047e081b1d9f485da49a8e854746c0cb7de730683c612daf8331c36 Restore and erase BEFORE name comparison; mismatch loop
0x7986e0   55                                 push   ebp
0x7986e1   8bec                               mov    ebp,esp
0x7986e3   6aff                               push   0xffffffff
0x7986e5   6838559100                         push   0x915538
0x7986ea   64a100000000                       mov    eax,fs:0x0
0x7986f0   50                                 push   eax
0x7986f1   83ec38                             sub    esp,0x38
0x7986f4   a1201fd600                         mov    eax,ds:0xd61f20
0x7986f9   33c5                               xor    eax,ebp
0x7986fb   8945f0                             mov    DWORD PTR [ebp-0x10],eax
0x7986fe   53                                 push   ebx
0x7986ff   56                                 push   esi
0x798700   57                                 push   edi
0x798701   50                                 push   eax
0x798702   8d45f4                             lea    eax,[ebp-0xc]
0x798705   64a300000000                       mov    fs:0x0,eax
0x79870b   8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
0x79870e   8b450c                             mov    eax,DWORD PTR [ebp+0xc]
0x798711   8b8ba4000000                       mov    ecx,DWORD PTR [ebx+0xa4]
0x798717   2b8ba0000000                       sub    ecx,DWORD PTR [ebx+0xa0]
0x79871d   8945c0                             mov    DWORD PTR [ebp-0x40],eax
0x798720   b8398ee338                         mov    eax,0x38e38e39
0x798725   f7e9                               imul   ecx
0x798727   c1fa04                             sar    edx,0x4
0x79872a   8bc2                               mov    eax,edx
0x79872c   c1e81f                             shr    eax,0x1f
0x79872f   03c2                               add    eax,edx
0x798731   895dd0                             mov    DWORD PTR [ebp-0x30],ebx
0x798734   0f84a0010000                       je     0x7988da
0x79873a   8d4b38                             lea    ecx,[ebx+0x38]
0x79873d   894dc4                             mov    DWORD PTR [ebp-0x3c],ecx
0x798740   8d0cc0                             lea    ecx,[eax+eax*8]
0x798743   03c9                               add    ecx,ecx
0x798745   03c9                               add    ecx,ecx
0x798747   03c9                               add    ecx,ecx
0x798749   eb0e                               jmp    0x798759
0x79874b   eb03                               jmp    0x798750
0x79874d   8d4900                             lea    ecx,[ecx+0x0]
0x798750   8b5dd0                             mov    ebx,DWORD PTR [ebp-0x30]
0x798753   8b45c8                             mov    eax,DWORD PTR [ebp-0x38]
0x798756   8b4dcc                             mov    ecx,DWORD PTR [ebp-0x34]
0x798759   48                                 dec    eax
0x79875a   83e948                             sub    ecx,0x48
0x79875d   8945c8                             mov    DWORD PTR [ebp-0x38],eax
0x798760   8b83a0000000                       mov    eax,DWORD PTR [ebx+0xa0]
0x798766   03c1                               add    eax,ecx
0x798768   894dcc                             mov    DWORD PTR [ebp-0x34],ecx
0x79876b   6aff                               push   0xffffffff
0x79876d   8bf0                               mov    esi,eax
0x79876f   b90b000000                         mov    ecx,0xb
0x798774   8d7b0c                             lea    edi,[ebx+0xc]
0x798777   6a00                               push   0x0
0x798779   83c02c                             add    eax,0x2c
0x79877c   f3a5                               rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x79877e   8b4dc4                             mov    ecx,DWORD PTR [ebp-0x3c]
0x798781   50                                 push   eax
0x798782   e8b9a8c6ff                         call   0x403040
0x798787   8b83a0000000                       mov    eax,DWORD PTR [ebx+0xa0]
0x79878d   8b75cc                             mov    esi,DWORD PTR [ebp-0x34]
0x798790   837c304010                         cmp    DWORD PTR [eax+esi*1+0x40],0x10
0x798795   7206                               jb     0x79879d
0x798797   8b7c302c                           mov    edi,DWORD PTR [eax+esi*1+0x2c]
0x79879b   eb04                               jmp    0x7987a1
0x79879d   8d7c302c                           lea    edi,[eax+esi*1+0x2c]
0x7987a1   8bc7                               mov    eax,edi
0x7987a3   c745e80f000000                     mov    DWORD PTR [ebp-0x18],0xf
0x7987aa   c745e400000000                     mov    DWORD PTR [ebp-0x1c],0x0
0x7987b1   c645d400                           mov    BYTE PTR [ebp-0x2c],0x0
0x7987b5   8d5001                             lea    edx,[eax+0x1]
0x7987b8   8a08                               mov    cl,BYTE PTR [eax]
0x7987ba   40                                 inc    eax
0x7987bb   84c9                               test   cl,cl
0x7987bd   75f9                               jne    0x7987b8
0x7987bf   2bc2                               sub    eax,edx
0x7987c1   50                                 push   eax
0x7987c2   57                                 push   edi
0x7987c3   8d4dd4                             lea    ecx,[ebp-0x2c]
0x7987c6   e8a5a2c6ff                         call   0x402a70
0x7987cb   c745fc00000000                     mov    DWORD PTR [ebp-0x4],0x0
0x7987d2   8b8ba4000000                       mov    ecx,DWORD PTR [ebx+0xa4]
0x7987d8   8b83a0000000                       mov    eax,DWORD PTR [ebx+0xa0]
0x7987de   8d5c0648                           lea    ebx,[esi+eax*1+0x48]
0x7987e2   894dbc                             mov    DWORD PTR [ebp-0x44],ecx
0x7987e5   3bd9                               cmp    ebx,ecx
0x7987e7   742b                               je     0x798814
0x7987e9   8da42400000000                     lea    esp,[esp+0x0]
0x7987f0   6aff                               push   0xffffffff
0x7987f2   8d7bb8                             lea    edi,[ebx-0x48]
0x7987f5   b90b000000                         mov    ecx,0xb
0x7987fa   8bf3                               mov    esi,ebx
0x7987fc   6a00                               push   0x0
0x7987fe   8d532c                             lea    edx,[ebx+0x2c]
0x798801   f3a5                               rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x798803   52                                 push   edx
0x798804   8d4be4                             lea    ecx,[ebx-0x1c]
0x798807   e834a8c6ff                         call   0x403040
0x79880c   83c348                             add    ebx,0x48
0x79880f   3b5dbc                             cmp    ebx,DWORD PTR [ebp-0x44]
0x798812   75dc                               jne    0x7987f0
0x798814   8b45d0                             mov    eax,DWORD PTR [ebp-0x30]
0x798817   8bb8a4000000                       mov    edi,DWORD PTR [eax+0xa4]
0x79881d   8d5fb8                             lea    ebx,[edi-0x48]
0x798820   3bdf                               cmp    ebx,edi
0x798822   7432                               je     0x798856
0x798824   8d7340                             lea    esi,[ebx+0x40]
0x798827   833e10                             cmp    DWORD PTR [esi],0x10
0x79882a   720c                               jb     0x798838
0x79882c   8b46ec                             mov    eax,DWORD PTR [esi-0x14]
0x79882f   50                                 push   eax
0x798830   e8d7890f00                         call   0x89120c
0x798835   83c404                             add    esp,0x4
0x798838   c7060f000000                       mov    DWORD PTR [esi],0xf
0x79883e   c746fc00000000                     mov    DWORD PTR [esi-0x4],0x0
0x798845   c646ec00                           mov    BYTE PTR [esi-0x14],0x0
0x798849   83c348                             add    ebx,0x48
0x79884c   83c648                             add    esi,0x48
0x79884f   3bdf                               cmp    ebx,edi
0x798851   75d4                               jne    0x798827
0x798853   8b45d0                             mov    eax,DWORD PTR [ebp-0x30]
0x798856   8380a4000000b8                     add    DWORD PTR [eax+0xa4],0xffffffb8
0x79885d   8b45d4                             mov    eax,DWORD PTR [ebp-0x2c]
0x798860   bf10000000                         mov    edi,0x10
0x798865   397de8                             cmp    DWORD PTR [ebp-0x18],edi
0x798868   7303                               jae    0x79886d
0x79886a   8d45d4                             lea    eax,[ebp-0x2c]
0x79886d   8b75c0                             mov    esi,DWORD PTR [ebp-0x40]
0x798870   56                                 push   esi
0x798871   50                                 push   eax
0x798872   e83ab40f00                         call   0x893cb1
0x798877   83c408                             add    esp,0x8
0x79887a   85c0                               test   eax,eax
0x79887c   743e                               je     0x7988bc
0x79887e   8b45d4                             mov    eax,DWORD PTR [ebp-0x2c]
0x798881   397de8                             cmp    DWORD PTR [ebp-0x18],edi
0x798884   7303                               jae    0x798889
0x798886   8d45d4                             lea    eax,[ebp-0x2c]
0x798889   50                                 push   eax
0x79888a   56                                 push   esi
0x79888b   6830f2c400                         push   0xc4f230
0x798890   e828a80f00                         call   0x8930bd
0x798895   83c40c                             add    esp,0xc
0x798898   c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
0x79889f   397de8                             cmp    DWORD PTR [ebp-0x18],edi
0x7988a2   720c                               jb     0x7988b0
0x7988a4   8b45d4                             mov    eax,DWORD PTR [ebp-0x2c]
0x7988a7   50                                 push   eax
0x7988a8   e85f890f00                         call   0x89120c
0x7988ad   83c404                             add    esp,0x4
0x7988b0   837dc800                           cmp    DWORD PTR [ebp-0x38],0x0
0x7988b4   0f8796feffff                       ja     0x798750
0x7988ba   eb1e                               jmp    0x7988da
0x7988bc   8b4dd0                             mov    ecx,DWORD PTR [ebp-0x30]
0x7988bf   c781cc00000000000000               mov    DWORD PTR [ecx+0xcc],0x0
0x7988c9   397de8                             cmp    DWORD PTR [ebp-0x18],edi
0x7988cc   720c                               jb     0x7988da
0x7988ce   8b55d4                             mov    edx,DWORD PTR [ebp-0x2c]
0x7988d1   52                                 push   edx
0x7988d2   e835890f00                         call   0x89120c
0x7988d7   83c404                             add    esp,0x4
0x7988da   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x7988dd   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x7988e4   59                                 pop    ecx
0x7988e5   5f                                 pop    edi
0x7988e6   5e                                 pop    esi
0x7988e7   5b                                 pop    ebx
0x7988e8   8b4df0                             mov    ecx,DWORD PTR [ebp-0x10]
0x7988eb   33cd                               xor    ecx,ebp
0x7988ed   e80f870f00                         call   0x891001
0x7988f2   8be5                               mov    esp,ebp
0x7988f4   5d                                 pop    ebp
0x7988f5   c20800                             ret    0x8

; attach_camera [0x563830,0x5638f2) raw=0x162c30 sha256=94f05a029f52ffefd368a9208def8c0e4c5ae77a090aeaf7fc81ef745d4cb4d9 Select singleton AttachSceneObj with Q-local slot
0x563830   55                                 push   ebp
0x563831   8bec                               mov    ebp,esp
0x563833   83e4f8                             and    esp,0xfffffff8
0x563836   6aff                               push   0xffffffff
0x563838   68ccaa9300                         push   0x93aacc
0x56383d   64a100000000                       mov    eax,fs:0x0
0x563843   50                                 push   eax
0x563844   83ec08                             sub    esp,0x8
0x563847   53                                 push   ebx
0x563848   a1201fd600                         mov    eax,ds:0xd61f20
0x56384d   33c4                               xor    eax,esp
0x56384f   50                                 push   eax
0x563850   8d442410                           lea    eax,[esp+0x10]
0x563854   64a300000000                       mov    fs:0x0,eax
0x56385a   bb01000000                         mov    ebx,0x1
0x56385f   841d1c76fb00                       test   BYTE PTR ds:0xfb761c,bl
0x563865   7528                               jne    0x56388f
0x563867   091d1c76fb00                       or     DWORD PTR ds:0xfb761c,ebx
0x56386d   c744241800000000                   mov    DWORD PTR [esp+0x18],0x0
0x563875   e8d6aefeff                         call   0x54e750
0x56387a   6860d2bc00                         push   0xbcd260
0x56387f   e896ea3200                         call   0x89231a
0x563884   83c404                             add    esp,0x4
0x563887   c7442418ffffffff                   mov    DWORD PTR [esp+0x18],0xffffffff
0x56388f   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x563892   b96c76fb00                         mov    ecx,0xfb766c
0x563897   890d2076fb00                       mov    DWORD PTR ds:0xfb7620,ecx
0x56389d   a37076fb00                         mov    ds:0xfb7670,eax
0x5638a2   841d1c76fb00                       test   BYTE PTR ds:0xfb761c,bl
0x5638a8   752e                               jne    0x5638d8
0x5638aa   091d1c76fb00                       or     DWORD PTR ds:0xfb761c,ebx
0x5638b0   895c2418                           mov    DWORD PTR [esp+0x18],ebx
0x5638b4   e897aefeff                         call   0x54e750
0x5638b9   6860d2bc00                         push   0xbcd260
0x5638be   e857ea3200                         call   0x89231a
0x5638c3   c744241cffffffff                   mov    DWORD PTR [esp+0x1c],0xffffffff
0x5638cb   8b0d2076fb00                       mov    ecx,DWORD PTR ds:0xfb7620
0x5638d1   83c404                             add    esp,0x4
0x5638d4   85c9                               test   ecx,ecx
0x5638d6   7407                               je     0x5638df
0x5638d8   8b11                               mov    edx,DWORD PTR [ecx]
0x5638da   8b4208                             mov    eax,DWORD PTR [edx+0x8]
0x5638dd   ffd0                               call   eax
0x5638df   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x5638e3   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x5638ea   59                                 pop    ecx
0x5638eb   5b                                 pop    ebx
0x5638ec   8be5                               mov    esp,ebp
0x5638ee   5d                                 pop    ebp
0x5638ef   c20400                             ret    0x4

; detach_camera [0x563900,0x56396e) raw=0x162d00 sha256=d709eeece6aba489c9140e7465f5c1d6422610014fbd8ff8732eaaf3420d32bf Clear current CameraWorks pointer
0x563900   55                                 push   ebp
0x563901   8bec                               mov    ebp,esp
0x563903   83e4f8                             and    esp,0xfffffff8
0x563906   6aff                               push   0xffffffff
0x563908   68dea99300                         push   0x93a9de
0x56390d   64a100000000                       mov    eax,fs:0x0
0x563913   50                                 push   eax
0x563914   51                                 push   ecx
0x563915   a1201fd600                         mov    eax,ds:0xd61f20
0x56391a   33c4                               xor    eax,esp
0x56391c   50                                 push   eax
0x56391d   8d442408                           lea    eax,[esp+0x8]
0x563921   64a300000000                       mov    fs:0x0,eax
0x563927   b801000000                         mov    eax,0x1
0x56392c   84051c76fb00                       test   BYTE PTR ds:0xfb761c,al
0x563932   7520                               jne    0x563954
0x563934   09051c76fb00                       or     DWORD PTR ds:0xfb761c,eax
0x56393a   c744241000000000                   mov    DWORD PTR [esp+0x10],0x0
0x563942   e809aefeff                         call   0x54e750
0x563947   6860d2bc00                         push   0xbcd260
0x56394c   e8c9e93200                         call   0x89231a
0x563951   83c404                             add    esp,0x4
0x563954   c7052076fb0000000000               mov    DWORD PTR ds:0xfb7620,0x0
0x56395e   8b4c2408                           mov    ecx,DWORD PTR [esp+0x8]
0x563962   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x563969   59                                 pop    ecx
0x56396a   8be5                               mov    esp,ebp
0x56396c   5d                                 pop    ebp
0x56396d   c3                                 ret

; camera_works_ctor [0x54e750,0x54e90b) raw=0x14db50 sha256=bc49608403373b99ea9fa767c1167db101c55193c1ef066f0deb9799007f2f53 Singletons and formal-VM CameraWorks registration
0x54e750   55                                 push   ebp
0x54e751   8bec                               mov    ebp,esp
0x54e753   6aff                               push   0xffffffff
0x54e755   6894a89300                         push   0x93a894
0x54e75a   64a100000000                       mov    eax,fs:0x0
0x54e760   50                                 push   eax
0x54e761   83ec0c                             sub    esp,0xc
0x54e764   53                                 push   ebx
0x54e765   a1201fd600                         mov    eax,ds:0xd61f20
0x54e76a   33c5                               xor    eax,ebp
0x54e76c   50                                 push   eax
0x54e76d   8d45f4                             lea    eax,[ebp-0xc]
0x54e770   64a300000000                       mov    fs:0x0,eax
0x54e776   0f57c0                             xorps  xmm0,xmm0
0x54e779   33c0                               xor    eax,eax
0x54e77b   c745f02076fb00                     mov    DWORD PTR [ebp-0x10],0xfb7620
0x54e782   a32076fb00                         mov    ds:0xfb7620,eax
0x54e787   c7052476fb0020fdc000               mov    DWORD PTR ds:0xfb7624,0xc0fd20
0x54e791   c7052876fb002cf2c400               mov    DWORD PTR ds:0xfb7628,0xc4f22c
0x54e79b   a32c76fb00                         mov    ds:0xfb762c,eax
0x54e7a0   a33076fb00                         mov    ds:0xfb7630,eax
0x54e7a5   a33476fb00                         mov    ds:0xfb7634,eax
0x54e7aa   f30f11053c76fb00                   movss  DWORD PTR ds:0xfb763c,xmm0
0x54e7b2   f30f11054076fb00                   movss  DWORD PTR ds:0xfb7640,xmm0
0x54e7ba   f30f11054476fb00                   movss  DWORD PTR ds:0xfb7644,xmm0
0x54e7c2   f30f11054876fb00                   movss  DWORD PTR ds:0xfb7648,xmm0
0x54e7ca   f30f11054c76fb00                   movss  DWORD PTR ds:0xfb764c,xmm0
0x54e7d2   f30f11055076fb00                   movss  DWORD PTR ds:0xfb7650,xmm0
0x54e7da   f30f11055476fb00                   movss  DWORD PTR ds:0xfb7654,xmm0
0x54e7e2   a35876fb00                         mov    ds:0xfb7658,eax
0x54e7e7   f30f11055c76fb00                   movss  DWORD PTR ds:0xfb765c,xmm0
0x54e7ef   a36076fb00                         mov    ds:0xfb7660,eax
0x54e7f4   a36476fb00                         mov    ds:0xfb7664,eax
0x54e7f9   a36876fb00                         mov    ds:0xfb7668,eax
0x54e7fe   8945fc                             mov    DWORD PTR [ebp-0x4],eax
0x54e801   f30f100da857c500                   movss  xmm1,DWORD PTR ds:0xc557a8
0x54e809   f30f11057876fb00                   movss  DWORD PTR ds:0xfb7678,xmm0
0x54e811   f30f11057c76fb00                   movss  DWORD PTR ds:0xfb767c,xmm0
0x54e819   f30f11058076fb00                   movss  DWORD PTR ds:0xfb7680,xmm0
0x54e821   f30f11058876fb00                   movss  DWORD PTR ds:0xfb7688,xmm0
0x54e829   f30f11058c76fb00                   movss  DWORD PTR ds:0xfb768c,xmm0
0x54e831   f30f11059076fb00                   movss  DWORD PTR ds:0xfb7690,xmm0
0x54e839   f30f11059476fb00                   movss  DWORD PTR ds:0xfb7694,xmm0
0x54e841   f30f1005c056c400                   movss  xmm0,DWORD PTR ds:0xc456c0
0x54e849   f30f11059876fb00                   movss  DWORD PTR ds:0xfb7698,xmm0
0x54e851   f30f10053458c500                   movss  xmm0,DWORD PTR ds:0xc55834
0x54e859   f30f11059c76fb00                   movss  DWORD PTR ds:0xfb769c,xmm0
0x54e861   f30f10053058c500                   movss  xmm0,DWORD PTR ds:0xc55830
0x54e869   bb01000000                         mov    ebx,0x1
0x54e86e   c7056c76fb0048fdc000               mov    DWORD PTR ds:0xfb766c,0xc0fd48
0x54e878   a37076fb00                         mov    ds:0xfb7670,eax
0x54e87d   a37476fb00                         mov    ds:0xfb7674,eax
0x54e882   f30f110d8476fb00                   movss  DWORD PTR ds:0xfb7684,xmm1
0x54e88a   f30f1105a076fb00                   movss  DWORD PTR ds:0xfb76a0,xmm0
0x54e892   891da476fb00                       mov    DWORD PTR ds:0xfb76a4,ebx
0x54e898   885dfc                             mov    BYTE PTR [ebp-0x4],bl
0x54e89b   841dd4f3fd00                       test   BYTE PTR ds:0xfdf3d4,bl
0x54e8a1   751f                               jne    0x54e8c2
0x54e8a3   091dd4f3fd00                       or     DWORD PTR ds:0xfdf3d4,ebx
0x54e8a9   c645fc02                           mov    BYTE PTR [ebp-0x4],0x2
0x54e8ad   e8ce5a1a00                         call   0x6f4380
0x54e8b2   68d0e6bc00                         push   0xbce6d0
0x54e8b7   e85e3a3400                         call   0x89231a
0x54e8bc   83c404                             add    esp,0x4
0x54e8bf   885dfc                             mov    BYTE PTR [ebp-0x4],bl
0x54e8c2   68c8f3fd00                         push   0xfdf3c8
0x54e8c7   e86458eeff                         call   0x434130
0x54e8cc   8d4dec                             lea    ecx,[ebp-0x14]
0x54e8cf   51                                 push   ecx
0x54e8d0   e84b010000                         call   0x54ea20
0x54e8d5   83c408                             add    esp,0x8
0x54e8d8   50                                 push   eax
0x54e8d9   e822020000                         call   0x54eb00
0x54e8de   50                                 push   eax
0x54e8df   e8bc020000                         call   0x54eba0
0x54e8e4   50                                 push   eax
0x54e8e5   e856030000                         call   0x54ec40
0x54e8ea   50                                 push   eax
0x54e8eb   e8f0030000                         call   0x54ece0
0x54e8f0   50                                 push   eax
0x54e8f1   e88a040000                         call   0x54ed80
0x54e8f6   b82076fb00                         mov    eax,0xfb7620
0x54e8fb   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x54e8fe   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x54e905   59                                 pop    ecx
0x54e906   5b                                 pop    ebx
0x54e907   8be5                               mov    esp,ebp
0x54e909   5d                                 pop    ebp
0x54e90a   c3                                 ret

; camera_works_namespace [0x54ea20,0x54eaf5) raw=0x14de20 sha256=3d4aa8445bc24eb8c227ec9293890bc7808e1e1744be34146729c238d8c89d9e Namespace, binding VM and receiver
0x54ea20   55                                 push   ebp
0x54ea21   8bec                               mov    ebp,esp
0x54ea23   51                                 push   ecx
0x54ea24   53                                 push   ebx
0x54ea25   8b5d0c                             mov    ebx,DWORD PTR [ebp+0xc]
0x54ea28   56                                 push   esi
0x54ea29   8b33                               mov    esi,DWORD PTR [ebx]
0x54ea2b   a3281efe00                         mov    ds:0xfe1e28,eax
0x54ea30   8b4610                             mov    eax,DWORD PTR [esi+0x10]
0x54ea33   8b4844                             mov    ecx,DWORD PTR [eax+0x44]
0x54ea36   57                                 push   edi
0x54ea37   891d241efe00                       mov    DWORD PTR ds:0xfe1e24,ebx
0x54ea3d   3b4840                             cmp    ecx,DWORD PTR [eax+0x40]
0x54ea40   7207                               jb     0x54ea49
0x54ea42   8bc6                               mov    eax,esi
0x54ea44   e857c91a00                         call   0x6fb3a0
0x54ea49   8b7e08                             mov    edi,DWORD PTR [esi+0x8]
0x54ea4c   6a00                               push   0x0
0x54ea4e   6a00                               push   0x0
0x54ea50   56                                 push   esi
0x54ea51   e84aaf1a00                         call   0x6f99a0
0x54ea56   8907                               mov    DWORD PTR [edi],eax
0x54ea58   c7470805000000                     mov    DWORD PTR [edi+0x8],0x5
0x54ea5f   83460810                           add    DWORD PTR [esi+0x8],0x10
0x54ea63   8b33                               mov    esi,DWORD PTR [ebx]
0x54ea65   83c40c                             add    esp,0xc
0x54ea68   bf10fdc000                         mov    edi,0xc0fd10
0x54ea6d   b8eed8ffff                         mov    eax,0xffffd8ee
0x54ea72   e8196d1a00                         call   0x6f5790
0x54ea77   8b33                               mov    esi,DWORD PTR [ebx]
0x54ea79   b8eed8ffff                         mov    eax,0xffffd8ee
0x54ea7e   e8fd6b1a00                         call   0x6f5680
0x54ea83   8b03                               mov    eax,DWORD PTR [ebx]
0x54ea85   8b4008                             mov    eax,DWORD PTR [eax+0x8]
0x54ea88   83e810                             sub    eax,0x10
0x54ea8b   bff0ffffff                         mov    edi,0xfffffff0
0x54ea90   3dc8bfc000                         cmp    eax,0xc0bfc8
0x54ea95   7406                               je     0x54ea9d
0x54ea97   83780805                           cmp    DWORD PTR [eax+0x8],0x5
0x54ea9b   7417                               je     0x54eab4
0x54ea9d   6810fdc000                         push   0xc0fd10
0x54eaa2   68c426c400                         push   0xc426c4
0x54eaa7   e811463400                         call   0x8930bd
0x54eaac   8b03                               mov    eax,DWORD PTR [ebx]
0x54eaae   83c408                             add    esp,0x8
0x54eab1   017808                             add    DWORD PTR [eax+0x8],edi
0x54eab4   8b33                               mov    esi,DWORD PTR [ebx]
0x54eab6   682462c000                         push   0xc06224
0x54eabb   e8506a1a00                         call   0x6f5510
0x54eac0   8b33                               mov    esi,DWORD PTR [ebx]
0x54eac2   83c404                             add    esp,0x4
0x54eac5   6a00                               push   0x0
0x54eac7   6820ee5400                         push   0x54ee20
0x54eacc   e8df6a1a00                         call   0x6f55b0
0x54ead1   8b13                               mov    edx,DWORD PTR [ebx]
0x54ead3   52                                 push   edx
0x54ead4   b8fdffffff                         mov    eax,0xfffffffd
0x54ead9   e8126d1a00                         call   0x6f57f0
0x54eade   8b1b                               mov    ebx,DWORD PTR [ebx]
0x54eae0   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x54eae3   83c40c                             add    esp,0xc
0x54eae6   017b08                             add    DWORD PTR [ebx+0x8],edi
0x54eae9   5f                                 pop    edi
0x54eaea   5e                                 pop    esi
0x54eaeb   c70010fdc000                       mov    DWORD PTR [eax],0xc0fd10
0x54eaf1   5b                                 pop    ebx
0x54eaf2   59                                 pop    ecx
0x54eaf3   5d                                 pop    ebp
0x54eaf4   c3                                 ret

; camera_works_stop_register [0x54ece0,0x54ed79) raw=0x14e0e0 sha256=3c99017efc0ead3c43bf3f4d5f872ac87867399c11cfd4f72c1691c69950918c Stop target and Lua closure registration
0x54ece0   55                                 push   ebp
0x54ece1   8bec                               mov    ebp,esp
0x54ece3   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x54ece6   53                                 push   ebx
0x54ece7   8b1d241efe00                       mov    ebx,DWORD PTR ds:0xfe1e24
0x54eced   56                                 push   esi
0x54ecee   8b33                               mov    esi,DWORD PTR [ebx]
0x54ecf0   57                                 push   edi
0x54ecf1   8b38                               mov    edi,DWORD PTR [eax]
0x54ecf3   b8eed8ffff                         mov    eax,0xffffd8ee
0x54ecf8   c705381efe00f0e95400               mov    DWORD PTR ds:0xfe1e38,0x54e9f0
0x54ed02   e879691a00                         call   0x6f5680
0x54ed07   8b03                               mov    eax,DWORD PTR [ebx]
0x54ed09   8b4008                             mov    eax,DWORD PTR [eax+0x8]
0x54ed0c   83e810                             sub    eax,0x10
0x54ed0f   3dc8bfc000                         cmp    eax,0xc0bfc8
0x54ed14   7406                               je     0x54ed1c
0x54ed16   83780805                           cmp    DWORD PTR [eax+0x8],0x5
0x54ed1a   7414                               je     0x54ed30
0x54ed1c   57                                 push   edi
0x54ed1d   68c426c400                         push   0xc426c4
0x54ed22   e896433400                         call   0x8930bd
0x54ed27   8b1b                               mov    ebx,DWORD PTR [ebx]
0x54ed29   83c408                             add    esp,0x8
0x54ed2c   834308f0                           add    DWORD PTR [ebx+0x8],0xfffffff0
0x54ed30   8b3d241efe00                       mov    edi,DWORD PTR ds:0xfe1e24
0x54ed36   8b37                               mov    esi,DWORD PTR [edi]
0x54ed38   68f8a5d600                         push   0xd6a5f8
0x54ed3d   e8ce671a00                         call   0x6f5510
0x54ed42   8b37                               mov    esi,DWORD PTR [edi]
0x54ed44   83c404                             add    esp,0x4
0x54ed47   6a00                               push   0x0
0x54ed49   6860ef5400                         push   0x54ef60
0x54ed4e   e85d681a00                         call   0x6f55b0
0x54ed53   8b0f                               mov    ecx,DWORD PTR [edi]
0x54ed55   51                                 push   ecx
0x54ed56   b8fdffffff                         mov    eax,0xfffffffd
0x54ed5b   e8906a1a00                         call   0x6f57f0
0x54ed60   8b15241efe00                       mov    edx,DWORD PTR ds:0xfe1e24
0x54ed66   8b02                               mov    eax,DWORD PTR [edx]
0x54ed68   83c40c                             add    esp,0xc
0x54ed6b   834008f0                           add    DWORD PTR [eax+0x8],0xfffffff0
0x54ed6f   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x54ed72   5f                                 pop    edi
0x54ed73   5e                                 pop    esi
0x54ed74   5b                                 pop    ebx
0x54ed75   5d                                 pop    ebp
0x54ed76   c20400                             ret    0x4

; camera_works_ended_register [0x54ed80,0x54ee19) raw=0x14e180 sha256=05c90231b77b0c16b1fe768c4531e9460770c38bbe5810a16ee9ae6a08d8065c IsEnded target and Lua closure registration
0x54ed80   55                                 push   ebp
0x54ed81   8bec                               mov    ebp,esp
0x54ed83   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x54ed86   53                                 push   ebx
0x54ed87   8b1d241efe00                       mov    ebx,DWORD PTR ds:0xfe1e24
0x54ed8d   56                                 push   esi
0x54ed8e   8b33                               mov    esi,DWORD PTR [ebx]
0x54ed90   57                                 push   edi
0x54ed91   8b38                               mov    edi,DWORD PTR [eax]
0x54ed93   b8eed8ffff                         mov    eax,0xffffd8ee
0x54ed98   c7053c1efe0000ea5400               mov    DWORD PTR ds:0xfe1e3c,0x54ea00
0x54eda2   e8d9681a00                         call   0x6f5680
0x54eda7   8b03                               mov    eax,DWORD PTR [ebx]
0x54eda9   8b4008                             mov    eax,DWORD PTR [eax+0x8]
0x54edac   83e810                             sub    eax,0x10
0x54edaf   3dc8bfc000                         cmp    eax,0xc0bfc8
0x54edb4   7406                               je     0x54edbc
0x54edb6   83780805                           cmp    DWORD PTR [eax+0x8],0x5
0x54edba   7414                               je     0x54edd0
0x54edbc   57                                 push   edi
0x54edbd   68c426c400                         push   0xc426c4
0x54edc2   e8f6423400                         call   0x8930bd
0x54edc7   8b1b                               mov    ebx,DWORD PTR [ebx]
0x54edc9   83c408                             add    esp,0x8
0x54edcc   834308f0                           add    DWORD PTR [ebx+0x8],0xfffffff0
0x54edd0   8b3d241efe00                       mov    edi,DWORD PTR ds:0xfe1e24
0x54edd6   8b37                               mov    esi,DWORD PTR [edi]
0x54edd8   6800a6d600                         push   0xd6a600
0x54eddd   e82e671a00                         call   0x6f5510
0x54ede2   8b37                               mov    esi,DWORD PTR [edi]
0x54ede4   83c404                             add    esp,0x4
0x54ede7   6a00                               push   0x0
0x54ede9   68c0ef5400                         push   0x54efc0
0x54edee   e8bd671a00                         call   0x6f55b0
0x54edf3   8b0f                               mov    ecx,DWORD PTR [edi]
0x54edf5   51                                 push   ecx
0x54edf6   b8fdffffff                         mov    eax,0xfffffffd
0x54edfb   e8f0691a00                         call   0x6f57f0
0x54ee00   8b15241efe00                       mov    edx,DWORD PTR ds:0xfe1e24
0x54ee06   8b02                               mov    eax,DWORD PTR [edx]
0x54ee08   83c40c                             add    esp,0xc
0x54ee0b   834008f0                           add    DWORD PTR [eax+0x8],0xfffffff0
0x54ee0f   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x54ee12   5f                                 pop    edi
0x54ee13   5e                                 pop    esi
0x54ee14   5b                                 pop    ebx
0x54ee15   5d                                 pop    ebp
0x54ee16   c20400                             ret    0x4

; camera_works_stop_closure [0x54ef60,0x54efb6) raw=0x14e360 sha256=3fdb47122df38e010f7baf6004e2461a37a0d3bf5de56b761244f3e1e08afa48 Stop closure receiver/target
0x54ef60   55                                 push   ebp
0x54ef61   8bec                               mov    ebp,esp
0x54ef63   6aff                               push   0xffffffff
0x54ef65   68c8839300                         push   0x9383c8
0x54ef6a   64a100000000                       mov    eax,fs:0x0
0x54ef70   50                                 push   eax
0x54ef71   83ec0c                             sub    esp,0xc
0x54ef74   a1201fd600                         mov    eax,ds:0xd61f20
0x54ef79   33c5                               xor    eax,ebp
0x54ef7b   50                                 push   eax
0x54ef7c   8d45f4                             lea    eax,[ebp-0xc]
0x54ef7f   64a300000000                       mov    fs:0x0,eax
0x54ef85   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x54ef88   8945e8                             mov    DWORD PTR [ebp-0x18],eax
0x54ef8b   33c0                               xor    eax,eax
0x54ef8d   8945ec                             mov    DWORD PTR [ebp-0x14],eax
0x54ef90   8945f0                             mov    DWORD PTR [ebp-0x10],eax
0x54ef93   8945fc                             mov    DWORD PTR [ebp-0x4],eax
0x54ef96   8b0d281efe00                       mov    ecx,DWORD PTR ds:0xfe1e28
0x54ef9c   ff15381efe00                       call   DWORD PTR ds:0xfe1e38
0x54efa2   b801000000                         mov    eax,0x1
0x54efa7   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x54efaa   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x54efb1   59                                 pop    ecx
0x54efb2   8be5                               mov    esp,ebp
0x54efb4   5d                                 pop    ebp
0x54efb5   c3                                 ret

; camera_works_ended_closure [0x54efc0,0x54f02e) raw=0x14e3c0 sha256=91142e6bfc0f2818f3afea0e54143eb3bede2f57939f3649f4ad7cd6fcdae9c8 IsEnded numerical Lua result
0x54efc0   55                                 push   ebp
0x54efc1   8bec                               mov    ebp,esp
0x54efc3   6aff                               push   0xffffffff
0x54efc5   68d8879300                         push   0x9387d8
0x54efca   64a100000000                       mov    eax,fs:0x0
0x54efd0   50                                 push   eax
0x54efd1   83ec0c                             sub    esp,0xc
0x54efd4   56                                 push   esi
0x54efd5   a1201fd600                         mov    eax,ds:0xd61f20
0x54efda   33c5                               xor    eax,ebp
0x54efdc   50                                 push   eax
0x54efdd   8d45f4                             lea    eax,[ebp-0xc]
0x54efe0   64a300000000                       mov    fs:0x0,eax
0x54efe6   8b7508                             mov    esi,DWORD PTR [ebp+0x8]
0x54efe9   33c0                               xor    eax,eax
0x54efeb   8975e8                             mov    DWORD PTR [ebp-0x18],esi
0x54efee   8945ec                             mov    DWORD PTR [ebp-0x14],eax
0x54eff1   8945f0                             mov    DWORD PTR [ebp-0x10],eax
0x54eff4   8945fc                             mov    DWORD PTR [ebp-0x4],eax
0x54eff7   8b0d281efe00                       mov    ecx,DWORD PTR ds:0xfe1e28
0x54effd   ff153c1efe00                       call   DWORD PTR ds:0xfe1e3c
0x54f003   894508                             mov    DWORD PTR [ebp+0x8],eax
0x54f006   8b4608                             mov    eax,DWORD PTR [esi+0x8]
0x54f009   db4508                             fild   DWORD PTR [ebp+0x8]
0x54f00c   c7400803000000                     mov    DWORD PTR [eax+0x8],0x3
0x54f013   dd18                               fstp   QWORD PTR [eax]
0x54f015   83460810                           add    DWORD PTR [esi+0x8],0x10
0x54f019   b801000000                         mov    eax,0x1
0x54f01e   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x54f021   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x54f028   59                                 pop    ecx
0x54f029   5e                                 pop    esi
0x54f02a   8be5                               mov    esp,ebp
0x54f02c   5d                                 pop    ebp
0x54f02d   c3                                 ret

; camera_works_stop_thunk [0x54e9f0,0x54e9fe) raw=0x14ddf0 sha256=db885be6e2bb5faa4bb47b19c3f2f6e7a399f78f9283a5d530e3deb49c22bdd6 Nullable pointer then virtual +0x0c
0x54e9f0   8b09                               mov    ecx,DWORD PTR [ecx]
0x54e9f2   85c9                               test   ecx,ecx
0x54e9f4   7407                               je     0x54e9fd
0x54e9f6   8b01                               mov    eax,DWORD PTR [ecx]
0x54e9f8   8b500c                             mov    edx,DWORD PTR [eax+0xc]
0x54e9fb   ffe2                               jmp    edx
0x54e9fd   c3                                 ret

; camera_works_ended_thunk [0x54ea00,0x54ea13) raw=0x14de00 sha256=ba2feceb5dec65b2a488bf17e6add42a6fa1914bc5566f1ff709b65686b262ac Nullable pointer then virtual +0x20
0x54ea00   8b09                               mov    ecx,DWORD PTR [ecx]
0x54ea02   85c9                               test   ecx,ecx
0x54ea04   7407                               je     0x54ea0d
0x54ea06   8b01                               mov    eax,DWORD PTR [ecx]
0x54ea08   8b5020                             mov    edx,DWORD PTR [eax+0x20]
0x54ea0b   ffe2                               jmp    edx
0x54ea0d   b801000000                         mov    eax,0x1
0x54ea12   c3                                 ret

; attach_start [0x54e3c0,0x54e56b) raw=0x14d7c0 sha256=5825ec1b12b55e03a6b92a62b8f487f95092184e28da8f9ad7268c8c5293a0c4 Camera snapshot and FB73DC Q-tree slot resolution
0x54e3c0   55                                 push   ebp
0x54e3c1   8bec                               mov    ebp,esp
0x54e3c3   83e4f8                             and    esp,0xfffffff8
0x54e3c6   6aff                               push   0xffffffff
0x54e3c8   6874af9300                         push   0x93af74
0x54e3cd   64a100000000                       mov    eax,fs:0x0
0x54e3d3   50                                 push   eax
0x54e3d4   83ec10                             sub    esp,0x10
0x54e3d7   53                                 push   ebx
0x54e3d8   56                                 push   esi
0x54e3d9   57                                 push   edi
0x54e3da   a1201fd600                         mov    eax,ds:0xd61f20
0x54e3df   33c4                               xor    eax,esp
0x54e3e1   50                                 push   eax
0x54e3e2   8d442420                           lea    eax,[esp+0x20]
0x54e3e6   64a300000000                       mov    fs:0x0,eax
0x54e3ec   8bd9                               mov    ebx,ecx
0x54e3ee   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x54e3f5   7529                               jne    0x54e420
0x54e3f7   830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
0x54e3fe   c744242800000000                   mov    DWORD PTR [esp+0x28],0x0
0x54e406   e8d5a92400                         call   0x798de0
0x54e40b   68e0d2bc00                         push   0xbcd2e0
0x54e410   e8053f3400                         call   0x89231a
0x54e415   83c404                             add    esp,0x4
0x54e418   c7442428ffffffff                   mov    DWORD PTR [esp+0x28],0xffffffff
0x54e420   8b35e876fb00                       mov    esi,DWORD PTR ds:0xfb76e8
0x54e426   83c60c                             add    esi,0xc
0x54e429   f605b873fb0001                     test   BYTE PTR ds:0xfb73b8,0x1
0x54e430   8d7b0c                             lea    edi,[ebx+0xc]
0x54e433   b90b000000                         mov    ecx,0xb
0x54e438   f3a5                               rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x54e43a   7529                               jne    0x54e465
0x54e43c   b801000000                         mov    eax,0x1
0x54e441   0905b873fb00                       or     DWORD PTR ds:0xfb73b8,eax
0x54e447   89442428                           mov    DWORD PTR [esp+0x28],eax
0x54e44b   e8201d0100                         call   0x560170
0x54e450   6810d1bc00                         push   0xbcd110
0x54e455   e8c03e3400                         call   0x89231a
0x54e45a   83c404                             add    esp,0x4
0x54e45d   c7442428ffffffff                   mov    DWORD PTR [esp+0x28],0xffffffff
0x54e465   8b4304                             mov    eax,DWORD PTR [ebx+0x4]
0x54e468   8d4c2410                           lea    ecx,[esp+0x10]
0x54e46c   89442410                           mov    DWORD PTR [esp+0x10],eax
0x54e470   51                                 push   ecx
0x54e471   8d442418                           lea    eax,[esp+0x18]
0x54e475   b9d873fb00                         mov    ecx,0xfb73d8
0x54e47a   e8810a2e00                         call   0x82ef00
0x54e47f   8b442414                           mov    eax,DWORD PTR [esp+0x14]
0x54e483   3b05dc73fb00                       cmp    eax,DWORD PTR ds:0xfb73dc
0x54e489   0f84c9000000                       je     0x54e558
0x54e48f   8b4010                             mov    eax,DWORD PTR [eax+0x10]
0x54e492   85c0                               test   eax,eax
0x54e494   0f84be000000                       je     0x54e558
0x54e49a   8d4c2414                           lea    ecx,[esp+0x14]
0x54e49e   e82ddff4ff                         call   0x49c3d0
0x54e4a3   8b442414                           mov    eax,DWORD PTR [esp+0x14]
0x54e4a7   85c0                               test   eax,eax
0x54e4a9   7554                               jne    0x54e4ff
0x54e4ab   c7442428ffffffff                   mov    DWORD PTR [esp+0x28],0xffffffff
0x54e4b3   8b742418                           mov    esi,DWORD PTR [esp+0x18]
0x54e4b7   85f6                               test   esi,esi
0x54e4b9   0f8499000000                       je     0x54e558
0x54e4bf   8d5604                             lea    edx,[esi+0x4]
0x54e4c2   83c8ff                             or     eax,0xffffffff
0x54e4c5   f00fc102                           lock xadd DWORD PTR [edx],eax
0x54e4c9   0f8589000000                       jne    0x54e558
0x54e4cf   8b16                               mov    edx,DWORD PTR [esi]
0x54e4d1   8b02                               mov    eax,DWORD PTR [edx]
0x54e4d3   8bce                               mov    ecx,esi
0x54e4d5   ffd0                               call   eax
0x54e4d7   8d4e08                             lea    ecx,[esi+0x8]
0x54e4da   83caff                             or     edx,0xffffffff
0x54e4dd   f00fc111                           lock xadd DWORD PTR [ecx],edx
0x54e4e1   7575                               jne    0x54e558
0x54e4e3   8b06                               mov    eax,DWORD PTR [esi]
0x54e4e5   8b5004                             mov    edx,DWORD PTR [eax+0x4]
0x54e4e8   8bce                               mov    ecx,esi
0x54e4ea   ffd2                               call   edx
0x54e4ec   8b4c2420                           mov    ecx,DWORD PTR [esp+0x20]
0x54e4f0   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x54e4f7   59                                 pop    ecx
0x54e4f8   5f                                 pop    edi
0x54e4f9   5e                                 pop    esi
0x54e4fa   5b                                 pop    ebx
0x54e4fb   8be5                               mov    esp,ebp
0x54e4fd   5d                                 pop    ebp
0x54e4fe   c3                                 ret
0x54e4ff   8b701c                             mov    esi,DWORD PTR [eax+0x1c]
0x54e502   85f6                               test   esi,esi
0x54e504   7419                               je     0x54e51f
0x54e506   6800fdc000                         push   0xc0fd00
0x54e50b   8d4308                             lea    eax,[ebx+0x8]
0x54e50e   50                                 push   eax
0x54e50f   e8bc4d2800                         call   0x7d32d0
0x54e514   85c0                               test   eax,eax
0x54e516   7407                               je     0x54e51f
0x54e518   c7433800000000                     mov    DWORD PTR [ebx+0x38],0x0
0x54e51f   c7442428ffffffff                   mov    DWORD PTR [esp+0x28],0xffffffff
0x54e527   8b742418                           mov    esi,DWORD PTR [esp+0x18]
0x54e52b   85f6                               test   esi,esi
0x54e52d   7429                               je     0x54e558
0x54e52f   8d4e04                             lea    ecx,[esi+0x4]
0x54e532   83caff                             or     edx,0xffffffff
0x54e535   f00fc111                           lock xadd DWORD PTR [ecx],edx
0x54e539   751d                               jne    0x54e558
0x54e53b   8b06                               mov    eax,DWORD PTR [esi]
0x54e53d   8b10                               mov    edx,DWORD PTR [eax]
0x54e53f   8bce                               mov    ecx,esi
0x54e541   ffd2                               call   edx
0x54e543   8d4608                             lea    eax,[esi+0x8]
0x54e546   83c9ff                             or     ecx,0xffffffff
0x54e549   f00fc108                           lock xadd DWORD PTR [eax],ecx
0x54e54d   7509                               jne    0x54e558
0x54e54f   8b16                               mov    edx,DWORD PTR [esi]
0x54e551   8b4204                             mov    eax,DWORD PTR [edx+0x4]
0x54e554   8bce                               mov    ecx,esi
0x54e556   ffd0                               call   eax
0x54e558   8b4c2420                           mov    ecx,DWORD PTR [esp+0x20]
0x54e55c   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x54e563   59                                 pop    ecx
0x54e564   5f                                 pop    edi
0x54e565   5e                                 pop    esi
0x54e566   5b                                 pop    ebx
0x54e567   8be5                               mov    esp,ebp
0x54e569   5d                                 pop    ebp
0x54e56a   c3                                 ret

; attach_update [0x54e580,0x54e735) raw=0x14d980 sha256=3adf6c649d567acf7930ddf805cbad59bc2f365c058c9d5786f5d297ae1fe3b3 Q-tree slot and CAMERA_DUMMY01 pose update
0x54e580   55                                 push   ebp
0x54e581   8bec                               mov    ebp,esp
0x54e583   83e4f8                             and    esp,0xfffffff8
0x54e586   6aff                               push   0xffffffff
0x54e588   6826af9300                         push   0x93af26
0x54e58d   64a100000000                       mov    eax,fs:0x0
0x54e593   50                                 push   eax
0x54e594   83ec48                             sub    esp,0x48
0x54e597   53                                 push   ebx
0x54e598   56                                 push   esi
0x54e599   57                                 push   edi
0x54e59a   a1201fd600                         mov    eax,ds:0xd61f20
0x54e59f   33c4                               xor    eax,esp
0x54e5a1   50                                 push   eax
0x54e5a2   8d442458                           lea    eax,[esp+0x58]
0x54e5a6   64a300000000                       mov    fs:0x0,eax
0x54e5ac   8bd9                               mov    ebx,ecx
0x54e5ae   837b3800                           cmp    DWORD PTR [ebx+0x38],0x0
0x54e5b2   0f8568010000                       jne    0x54e720
0x54e5b8   f605b873fb0001                     test   BYTE PTR ds:0xfb73b8,0x1
0x54e5bf   be01000000                         mov    esi,0x1
0x54e5c4   7528                               jne    0x54e5ee
0x54e5c6   0935b873fb00                       or     DWORD PTR ds:0xfb73b8,esi
0x54e5cc   c744246000000000                   mov    DWORD PTR [esp+0x60],0x0
0x54e5d4   e8971b0100                         call   0x560170
0x54e5d9   6810d1bc00                         push   0xbcd110
0x54e5de   e8373d3400                         call   0x89231a
0x54e5e3   83c404                             add    esp,0x4
0x54e5e6   c7442460ffffffff                   mov    DWORD PTR [esp+0x60],0xffffffff
0x54e5ee   8b4304                             mov    eax,DWORD PTR [ebx+0x4]
0x54e5f1   8d4c2410                           lea    ecx,[esp+0x10]
0x54e5f5   89442410                           mov    DWORD PTR [esp+0x10],eax
0x54e5f9   51                                 push   ecx
0x54e5fa   8d442418                           lea    eax,[esp+0x18]
0x54e5fe   b9d873fb00                         mov    ecx,0xfb73d8
0x54e603   e8f8082e00                         call   0x82ef00
0x54e608   8b442414                           mov    eax,DWORD PTR [esp+0x14]
0x54e60c   3b05dc73fb00                       cmp    eax,DWORD PTR ds:0xfb73dc
0x54e612   0f8408010000                       je     0x54e720
0x54e618   8b4010                             mov    eax,DWORD PTR [eax+0x10]
0x54e61b   85c0                               test   eax,eax
0x54e61d   0f84fd000000                       je     0x54e720
0x54e623   8d4c2414                           lea    ecx,[esp+0x14]
0x54e627   e8a4ddf4ff                         call   0x49c3d0
0x54e62c   89742460                           mov    DWORD PTR [esp+0x60],esi
0x54e630   8b442414                           mov    eax,DWORD PTR [esp+0x14]
0x54e634   85c0                               test   eax,eax
0x54e636   0f84d3000000                       je     0x54e70f
0x54e63c   0f57c0                             xorps  xmm0,xmm0
0x54e63f   8b401c                             mov    eax,DWORD PTR [eax+0x1c]
0x54e642   8b4b08                             mov    ecx,DWORD PTR [ebx+0x8]
0x54e645   f30f11442428                       movss  DWORD PTR [esp+0x28],xmm0
0x54e64b   f30f1144242c                       movss  DWORD PTR [esp+0x2c],xmm0
0x54e651   f30f11442430                       movss  DWORD PTR [esp+0x30],xmm0
0x54e657   f30f11442434                       movss  DWORD PTR [esp+0x34],xmm0
0x54e65d   f30f11442438                       movss  DWORD PTR [esp+0x38],xmm0
0x54e663   f30f1144243c                       movss  DWORD PTR [esp+0x3c],xmm0
0x54e669   f30f1005c056c400                   movss  xmm0,DWORD PTR ds:0xc456c0
0x54e671   f30f11442440                       movss  DWORD PTR [esp+0x40],xmm0
0x54e677   f30f11442444                       movss  DWORD PTR [esp+0x44],xmm0
0x54e67d   f30f11442448                       movss  DWORD PTR [esp+0x48],xmm0
0x54e683   f30f1144244c                       movss  DWORD PTR [esp+0x4c],xmm0
0x54e689   89742450                           mov    DWORD PTR [esp+0x50],esi
0x54e68d   85c0                               test   eax,eax
0x54e68f   7409                               je     0x54e69a
0x54e691   8d7c2428                           lea    edi,[esp+0x28]
0x54e695   e8a64c2800                         call   0x7d3340
0x54e69a   8d542420                           lea    edx,[esp+0x20]
0x54e69e   52                                 push   edx
0x54e69f   8d442420                           lea    eax,[esp+0x20]
0x54e6a3   50                                 push   eax
0x54e6a4   8d4c242c                           lea    ecx,[esp+0x2c]
0x54e6a8   51                                 push   ecx
0x54e6a9   8d742440                           lea    esi,[esp+0x40]
0x54e6ad   e8eedc2700                         call   0x7cc3a0
0x54e6b2   8b542434                           mov    edx,DWORD PTR [esp+0x34]
0x54e6b6   8b442438                           mov    eax,DWORD PTR [esp+0x38]
0x54e6ba   8b4c243c                           mov    ecx,DWORD PTR [esp+0x3c]
0x54e6be   0f57c0                             xorps  xmm0,xmm0
0x54e6c1   89530c                             mov    DWORD PTR [ebx+0xc],edx
0x54e6c4   8b542428                           mov    edx,DWORD PTR [esp+0x28]
0x54e6c8   894310                             mov    DWORD PTR [ebx+0x10],eax
0x54e6cb   8b44242c                           mov    eax,DWORD PTR [esp+0x2c]
0x54e6cf   894b14                             mov    DWORD PTR [ebx+0x14],ecx
0x54e6d2   8b4c2430                           mov    ecx,DWORD PTR [esp+0x30]
0x54e6d6   895318                             mov    DWORD PTR [ebx+0x18],edx
0x54e6d9   8b13                               mov    edx,DWORD PTR [ebx]
0x54e6db   f30f114328                         movss  DWORD PTR [ebx+0x28],xmm0
0x54e6e0   f30f114324                         movss  DWORD PTR [ebx+0x24],xmm0
0x54e6e5   f30f1005d058c500                   movss  xmm0,DWORD PTR ds:0xc558d0
0x54e6ed   89431c                             mov    DWORD PTR [ebx+0x1c],eax
0x54e6f0   8b4204                             mov    eax,DWORD PTR [edx+0x4]
0x54e6f3   894b20                             mov    DWORD PTR [ebx+0x20],ecx
0x54e6f6   f30f11432c                         movss  DWORD PTR [ebx+0x2c],xmm0
0x54e6fb   f30f1005085ec500                   movss  xmm0,DWORD PTR ds:0xc55e08
0x54e703   83c40c                             add    esp,0xc
0x54e706   8bcb                               mov    ecx,ebx
0x54e708   f30f114334                         movss  DWORD PTR [ebx+0x34],xmm0
0x54e70d   ffd0                               call   eax
0x54e70f   8d442414                           lea    eax,[esp+0x14]
0x54e713   c7442460ffffffff                   mov    DWORD PTR [esp+0x60],0xffffffff
0x54e71b   e830292500                         call   0x7a1050
0x54e720   8b4c2458                           mov    ecx,DWORD PTR [esp+0x58]
0x54e724   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x54e72b   59                                 pop    ecx
0x54e72c   5f                                 pop    edi
0x54e72d   5e                                 pop    esi
0x54e72e   5b                                 pop    ebx
0x54e72f   8be5                               mov    esp,ebp
0x54e731   5d                                 pop    ebp
0x54e732   c20400                             ret    0x4

; attach_apply [0x54e340,0x54e3b4) raw=0x14d740 sha256=5eac7a2fe536840e434283750525602046d083f95a71252478a35c8c16fa0403 Apply attachment camera snapshot
0x54e340   55                                 push   ebp
0x54e341   8bec                               mov    ebp,esp
0x54e343   6aff                               push   0xffffffff
0x54e345   682eed9200                         push   0x92ed2e
0x54e34a   64a100000000                       mov    eax,fs:0x0
0x54e350   50                                 push   eax
0x54e351   56                                 push   esi
0x54e352   a1201fd600                         mov    eax,ds:0xd61f20
0x54e357   33c5                               xor    eax,ebp
0x54e359   50                                 push   eax
0x54e35a   8d45f4                             lea    eax,[ebp-0xc]
0x54e35d   64a300000000                       mov    fs:0x0,eax
0x54e363   8bf1                               mov    esi,ecx
0x54e365   837e3800                           cmp    DWORD PTR [esi+0x38],0x0
0x54e369   7539                               jne    0x54e3a4
0x54e36b   b801000000                         mov    eax,0x1
0x54e370   8405e879fb00                       test   BYTE PTR ds:0xfb79e8,al
0x54e376   751f                               jne    0x54e397
0x54e378   0905e879fb00                       or     DWORD PTR ds:0xfb79e8,eax
0x54e37e   c745fc00000000                     mov    DWORD PTR [ebp-0x4],0x0
0x54e385   e856aa2400                         call   0x798de0
0x54e38a   68e0d2bc00                         push   0xbcd2e0
0x54e38f   e8863f3400                         call   0x89231a
0x54e394   83c404                             add    esp,0x4
0x54e397   a1e876fb00                         mov    eax,ds:0xfb76e8
0x54e39c   8d4e0c                             lea    ecx,[esi+0xc]
0x54e39f   e8cc9f2400                         call   0x798370
0x54e3a4   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x54e3a7   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x54e3ae   59                                 pop    ecx
0x54e3af   5e                                 pop    esi
0x54e3b0   8be5                               mov    esp,ebp
0x54e3b2   5d                                 pop    ebp
0x54e3b3   c3                                 ret

; attach_stop [0x54e570,0x54e578) raw=0x14d970 sha256=e69b26b981ab08990eb35e2fcd233e4fed9a82d6a9f6530c1238ac87cb65bbe3 Set attachment ended +0x38
0x54e570   c7413801000000                     mov    DWORD PTR [ecx+0x38],0x1
0x54e577   c3                                 ret

; attach_ended [0x54e740,0x54e744) raw=0x14db40 sha256=7e6bda0a031f94dbe8477fe3ce3ba2b7e3d761a050d55625bc7d92212670e60c Read attachment ended +0x38
0x54e740   8b4138                             mov    eax,DWORD PTR [ecx+0x38]
0x54e743   c3                                 ret

; keyframe_stop [0x54e260,0x54e268) raw=0x14d660 sha256=31fddf4136f2029aa562bc7ab0769de9f4a8d309753f4ccfe6ecd762c69859b8 Clear keyframe playing +0x40
0x54e260   c7414000000000                     mov    DWORD PTR [ecx+0x40],0x0
0x54e267   c3                                 ret

; keyframe_ended [0x54e310,0x54e33a) raw=0x14d710 sha256=a3aef4609b88cfa012499810aaccd9a8d63737b321a2bbd368cfaf74b27ace74 Keyframe playing/frame completion
0x54e310   83794000                           cmp    DWORD PTR [ecx+0x40],0x0
0x54e314   741e                               je     0x54e334
0x54e316   8b5108                             mov    edx,DWORD PTR [ecx+0x8]
0x54e319   8b410c                             mov    eax,DWORD PTR [ecx+0xc]
0x54e31c   2bc2                               sub    eax,edx
0x54e31e   c1f802                             sar    eax,0x2
0x54e321   85c0                               test   eax,eax
0x54e323   740c                               je     0x54e331
0x54e325   8b4482fc                           mov    eax,DWORD PTR [edx+eax*4-0x4]
0x54e329   8b5024                             mov    edx,DWORD PTR [eax+0x24]
0x54e32c   3b5144                             cmp    edx,DWORD PTR [ecx+0x44]
0x54e32f   7c03                               jl     0x54e334
0x54e331   33c0                               xor    eax,eax
0x54e333   c3                                 ret
0x54e334   b801000000                         mov    eax,0x1
0x54e339   c3                                 ret

; keyframe_frame_tick_noop [0x476430,0x476433) raw=0x75830 sha256=e598d0c3ba86d917b177d7adde0556aa99bc355543c57aee0a3e50b684dd7e99 KeyFrame virtual +0x10 only ret 4, not its animation progress producer
0x476430   c20400                             ret    0x4

; camera_works_tick [0x492410,0x492428) raw=0x91810 sha256=26bcadb87781da0266fcddb04bd4e47061608bada2ce75faf880dbad037e0c66 Main update FB7620 -> virtual +0x10 with frame delta
0x492410   8b0d2076fb00                       mov    ecx,DWORD PTR ds:0xfb7620
0x492416   85c9                               test   ecx,ecx
0x492418   740e                               je     0x492428
0x49241a   8b01                               mov    eax,DWORD PTR [ecx]
0x49241c   d9450c                             fld    DWORD PTR [ebp+0xc]
0x49241f   8b5010                             mov    edx,DWORD PTR [eax+0x10]
0x492422   51                                 push   ecx
0x492423   d91c24                             fstp   DWORD PTR [esp]
0x492426   ffd2                               call   edx

; load_map [0x563c40,0x563f95) raw=0x163040 sha256=f8e19eaddffacf03f9177837a983e7e5d7bff98d4b99791de2ac54ee184e2ff3 One M+0x30 camera buffer and M+0x34 previous map
0x563c40   55                                 push   ebp
0x563c41   8bec                               mov    ebp,esp
0x563c43   83e4f8                             and    esp,0xfffffff8
0x563c46   6aff                               push   0xffffffff
0x563c48   68c0649300                         push   0x9364c0
0x563c4d   64a100000000                       mov    eax,fs:0x0
0x563c53   50                                 push   eax
0x563c54   81ec28010000                       sub    esp,0x128
0x563c5a   a1201fd600                         mov    eax,ds:0xd61f20
0x563c5f   33c4                               xor    eax,esp
0x563c61   89842420010000                     mov    DWORD PTR [esp+0x120],eax
0x563c68   53                                 push   ebx
0x563c69   56                                 push   esi
0x563c6a   57                                 push   edi
0x563c6b   a1201fd600                         mov    eax,ds:0xd61f20
0x563c70   33c4                               xor    eax,esp
0x563c72   50                                 push   eax
0x563c73   8d842438010000                     lea    eax,[esp+0x138]
0x563c7a   64a300000000                       mov    fs:0x0,eax
0x563c80   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x563c83   8bd9                               mov    ebx,ecx
0x563c85   89442414                           mov    DWORD PTR [esp+0x14],eax
0x563c89   85c0                               test   eax,eax
0x563c8b   0f84de020000                       je     0x563f6f
0x563c91   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x563c98   752f                               jne    0x563cc9
0x563c9a   830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
0x563ca1   c784244001000000000000             mov    DWORD PTR [esp+0x140],0x0
0x563cac   e82f512300                         call   0x798de0
0x563cb1   68e0d2bc00                         push   0xbcd2e0
0x563cb6   e85fe63200                         call   0x89231a
0x563cbb   83c404                             add    esp,0x4
0x563cbe   c7842440010000ffffffff             mov    DWORD PTR [esp+0x140],0xffffffff
0x563cc9   8b35e876fb00                       mov    esi,DWORD PTR ds:0xfb76e8
0x563ccf   8b7b30                             mov    edi,DWORD PTR [ebx+0x30]
0x563cd2   83c60c                             add    esi,0xc
0x563cd5   f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
0x563cdc   b90b000000                         mov    ecx,0xb
0x563ce1   f3a5                               rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x563ce3   bf01000000                         mov    edi,0x1
0x563ce8   752a                               jne    0x563d14
0x563cea   093d2cb2fa00                       or     DWORD PTR ds:0xfab22c,edi
0x563cf0   89bc2440010000                     mov    DWORD PTR [esp+0x140],edi
0x563cf7   e894aff7ff                         call   0x4dec90
0x563cfc   6830cebc00                         push   0xbcce30
0x563d01   e814e63200                         call   0x89231a
0x563d06   83c404                             add    esp,0x4
0x563d09   c7842440010000ffffffff             mov    DWORD PTR [esp+0x140],0xffffffff
0x563d14   8b542414                           mov    edx,DWORD PTR [esp+0x14]
0x563d18   a178b1fa00                         mov    eax,ds:0xfab178
0x563d1d   6a00                               push   0x0
0x563d1f   6a00                               push   0x0
0x563d21   6804010000                         push   0x104
0x563d26   8d4c2430                           lea    ecx,[esp+0x30]
0x563d2a   51                                 push   ecx
0x563d2b   6a00                               push   0x0
0x563d2d   6a00                               push   0x0
0x563d2f   6a00                               push   0x0
0x563d31   6a00                               push   0x0
0x563d33   52                                 push   edx
0x563d34   894334                             mov    DWORD PTR [ebx+0x34],eax
0x563d37   e8a72b3300                         call   0x8968e3
0x563d3c   83c424                             add    esp,0x24
0x563d3f   6a00                               push   0x0
0x563d41   8d742428                           lea    esi,[esp+0x28]
0x563d45   e8b6e02500                         call   0x7c1e00
0x563d4a   83c404                             add    esp,0x4
0x563d4d   f605c00ffc0001                     test   BYTE PTR ds:0xfc0fc0,0x1
0x563d54   752e                               jne    0x563d84
0x563d56   093dc00ffc00                       or     DWORD PTR ds:0xfc0fc0,edi
0x563d5c   c784244001000002000000             mov    DWORD PTR [esp+0x140],0x2
0x563d67   e8e4501700                         call   0x6d8e50
0x563d6c   68b0dbbc00                         push   0xbcdbb0
0x563d71   e8a4e53200                         call   0x89231a
0x563d76   83c404                             add    esp,0x4
0x563d79   c7842440010000ffffffff             mov    DWORD PTR [esp+0x140],0xffffffff
0x563d84   b9c80ffc00                         mov    ecx,0xfc0fc8
0x563d89   e8f2591700                         call   0x6d9780
0x563d8e   a138a8fb00                         mov    eax,ds:0xfba838
0x563d93   8b4848                             mov    ecx,DWORD PTR [eax+0x48]
0x563d96   2b4844                             sub    ecx,DWORD PTR [eax+0x44]
0x563d99   c1f902                             sar    ecx,0x2
0x563d9c   85c9                               test   ecx,ecx
0x563d9e   0f84cb010000                       je     0x563f6f
0x563da4   8b5044                             mov    edx,DWORD PTR [eax+0x44]
0x563da7   8b32                               mov    esi,DWORD PTR [edx]
0x563da9   85f6                               test   esi,esi
0x563dab   0f84be010000                       je     0x563f6f
0x563db1   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x563db8   8b4608                             mov    eax,DWORD PTR [esi+0x8]
0x563dbb   8b3e                               mov    edi,DWORD PTR [esi]
0x563dbd   8b5e04                             mov    ebx,DWORD PTR [esi+0x4]
0x563dc0   89442420                           mov    DWORD PTR [esp+0x20],eax
0x563dc4   752f                               jne    0x563df5
0x563dc6   830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
0x563dcd   c784244001000003000000             mov    DWORD PTR [esp+0x140],0x3
0x563dd8   e803502300                         call   0x798de0
0x563ddd   68e0d2bc00                         push   0xbcd2e0
0x563de2   e833e53200                         call   0x89231a
0x563de7   83c404                             add    esp,0x4
0x563dea   c7842440010000ffffffff             mov    DWORD PTR [esp+0x140],0xffffffff
0x563df5   a1e876fb00                         mov    eax,ds:0xfb76e8
0x563dfa   8b542420                           mov    edx,DWORD PTR [esp+0x20]
0x563dfe   89780c                             mov    DWORD PTR [eax+0xc],edi
0x563e01   33ff                               xor    edi,edi
0x563e03   895810                             mov    DWORD PTR [eax+0x10],ebx
0x563e06   8bc8                               mov    ecx,eax
0x563e08   8d5f01                             lea    ebx,[edi+0x1]
0x563e0b   895014                             mov    DWORD PTR [eax+0x14],edx
0x563e0e   89b9cc000000                       mov    DWORD PTR [ecx+0xcc],edi
0x563e14   f30f104614                         movss  xmm0,DWORD PTR [esi+0x14]
0x563e19   f30f11442414                       movss  DWORD PTR [esp+0x14],xmm0
0x563e1f   841de879fb00                       test   BYTE PTR ds:0xfb79e8,bl
0x563e25   752e                               jne    0x563e55
0x563e27   091de879fb00                       or     DWORD PTR ds:0xfb79e8,ebx
0x563e2d   c784244001000004000000             mov    DWORD PTR [esp+0x140],0x4
0x563e38   e8a34f2300                         call   0x798de0
0x563e3d   68e0d2bc00                         push   0xbcd2e0
0x563e42   e8d3e43200                         call   0x89231a
0x563e47   83c404                             add    esp,0x4
0x563e4a   c7842440010000ffffffff             mov    DWORD PTR [esp+0x140],0xffffffff
0x563e55   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x563e5c   a1e876fb00                         mov    eax,ds:0xfb76e8
0x563e61   f30f10442414                       movss  xmm0,DWORD PTR [esp+0x14]
0x563e67   f30f114020                         movss  DWORD PTR [eax+0x20],xmm0
0x563e6c   89b8cc000000                       mov    DWORD PTR [eax+0xcc],edi
0x563e72   f30f104624                         movss  xmm0,DWORD PTR [esi+0x24]
0x563e77   f30f11442414                       movss  DWORD PTR [esp+0x14],xmm0
0x563e7d   7534                               jne    0x563eb3
0x563e7f   091de879fb00                       or     DWORD PTR ds:0xfb79e8,ebx
0x563e85   c784244001000005000000             mov    DWORD PTR [esp+0x140],0x5
0x563e90   e84b4f2300                         call   0x798de0
0x563e95   68e0d2bc00                         push   0xbcd2e0
0x563e9a   e87be43200                         call   0x89231a
0x563e9f   f30f10442418                       movss  xmm0,DWORD PTR [esp+0x18]
0x563ea5   83c404                             add    esp,0x4
0x563ea8   c7842440010000ffffffff             mov    DWORD PTR [esp+0x140],0xffffffff
0x563eb3   a1e876fb00                         mov    eax,ds:0xfb76e8
0x563eb8   8bc8                               mov    ecx,eax
0x563eba   8b00                               mov    eax,DWORD PTR [eax]
0x563ebc   3bc7                               cmp    eax,edi
0x563ebe   7405                               je     0x563ec5
0x563ec0   f30f11407c                         movss  DWORD PTR [eax+0x7c],xmm0
0x563ec5   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x563ecc   f30f114130                         movss  DWORD PTR [ecx+0x30],xmm0
0x563ed1   f30f10460c                         movss  xmm0,DWORD PTR [esi+0xc]
0x563ed6   f30f11442414                       movss  DWORD PTR [esp+0x14],xmm0
0x563edc   752e                               jne    0x563f0c
0x563ede   091de879fb00                       or     DWORD PTR ds:0xfb79e8,ebx
0x563ee4   c784244001000006000000             mov    DWORD PTR [esp+0x140],0x6
0x563eef   e8ec4e2300                         call   0x798de0
0x563ef4   68e0d2bc00                         push   0xbcd2e0
0x563ef9   e81ce43200                         call   0x89231a
0x563efe   83c404                             add    esp,0x4
0x563f01   c7842440010000ffffffff             mov    DWORD PTR [esp+0x140],0xffffffff
0x563f0c   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x563f13   a1e876fb00                         mov    eax,ds:0xfb76e8
0x563f18   f30f10442414                       movss  xmm0,DWORD PTR [esp+0x14]
0x563f1e   f30f114018                         movss  DWORD PTR [eax+0x18],xmm0
0x563f23   89b8cc000000                       mov    DWORD PTR [eax+0xcc],edi
0x563f29   f30f104618                         movss  xmm0,DWORD PTR [esi+0x18]
0x563f2e   f30f11442414                       movss  DWORD PTR [esp+0x14],xmm0
0x563f34   7523                               jne    0x563f59
0x563f36   091de879fb00                       or     DWORD PTR ds:0xfb79e8,ebx
0x563f3c   c784244001000007000000             mov    DWORD PTR [esp+0x140],0x7
0x563f47   e8944e2300                         call   0x798de0
0x563f4c   68e0d2bc00                         push   0xbcd2e0
0x563f51   e8c4e33200                         call   0x89231a
0x563f56   83c404                             add    esp,0x4
0x563f59   a1e876fb00                         mov    eax,ds:0xfb76e8
0x563f5e   f30f10442414                       movss  xmm0,DWORD PTR [esp+0x14]
0x563f64   f30f114024                         movss  DWORD PTR [eax+0x24],xmm0
0x563f69   89b8cc000000                       mov    DWORD PTR [eax+0xcc],edi
0x563f6f   8b8c2438010000                     mov    ecx,DWORD PTR [esp+0x138]
0x563f76   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x563f7d   59                                 pop    ecx
0x563f7e   5f                                 pop    edi
0x563f7f   5e                                 pop    esi
0x563f80   5b                                 pop    ebx
0x563f81   8b8c2420010000                     mov    ecx,DWORD PTR [esp+0x120]
0x563f88   33cc                               xor    ecx,esp
0x563f8a   e872d03200                         call   0x891001
0x563f8f   8be5                               mov    esp,ebp
0x563f91   5d                                 pop    ebp
0x563f92   c20400                             ret    0x4

; restore_map [0x563fa0,0x5643bd) raw=0x1633a0 sha256=693ed5e79dd68fbad0adacd08ab767ffc3f6e067155c862b58fe4f321fcbc5bf MapList FB74B0 getter -> FLD load and camera snapshot
0x563fa0   55                                 push   ebp
0x563fa1   8bec                               mov    ebp,esp
0x563fa3   83e4f8                             and    esp,0xfffffff8
0x563fa6   6aff                               push   0xffffffff
0x563fa8   6822649300                         push   0x936422
0x563fad   64a100000000                       mov    eax,fs:0x0
0x563fb3   50                                 push   eax
0x563fb4   83ec38                             sub    esp,0x38
0x563fb7   a1201fd600                         mov    eax,ds:0xd61f20
0x563fbc   33c4                               xor    eax,esp
0x563fbe   89442430                           mov    DWORD PTR [esp+0x30],eax
0x563fc2   53                                 push   ebx
0x563fc3   56                                 push   esi
0x563fc4   57                                 push   edi
0x563fc5   a1201fd600                         mov    eax,ds:0xd61f20
0x563fca   33c4                               xor    eax,esp
0x563fcc   50                                 push   eax
0x563fcd   8d442448                           lea    eax,[esp+0x48]
0x563fd1   64a300000000                       mov    fs:0x0,eax
0x563fd7   f605b075fb0001                     test   BYTE PTR ds:0xfb75b0,0x1
0x563fde   8bf1                               mov    esi,ecx
0x563fe0   8974241c                           mov    DWORD PTR [esp+0x1c],esi
0x563fe4   bf01000000                         mov    edi,0x1
0x563fe9   7528                               jne    0x564013
0x563feb   093db075fb00                       or     DWORD PTR ds:0xfb75b0,edi
0x563ff1   c744245000000000                   mov    DWORD PTR [esp+0x50],0x0
0x563ff9   e882fdf8ff                         call   0x4f3d80
0x563ffe   68e0d1bc00                         push   0xbcd1e0
0x564003   e812e33200                         call   0x89231a
0x564008   83c404                             add    esp,0x4
0x56400b   c7442450ffffffff                   mov    DWORD PTR [esp+0x50],0xffffffff
0x564013   8b4634                             mov    eax,DWORD PTR [esi+0x34]
0x564016   8d4c2418                           lea    ecx,[esp+0x18]
0x56401a   89442418                           mov    DWORD PTR [esp+0x18],eax
0x56401e   51                                 push   ecx
0x56401f   8d442418                           lea    eax,[esp+0x18]
0x564023   b9e074fb00                         mov    ecx,0xfb74e0
0x564028   e8c3bdf1ff                         call   0x47fdf0
0x56402d   8b442414                           mov    eax,DWORD PTR [esp+0x14]
0x564031   bb10000000                         mov    ebx,0x10
0x564036   3b05e474fb00                       cmp    eax,DWORD PTR ds:0xfb74e4
0x56403c   741a                               je     0x564058
0x56403e   03c3                               add    eax,ebx
0x564040   395814                             cmp    DWORD PTR [eax+0x14],ebx
0x564043   7202                               jb     0x564047
0x564045   8b00                               mov    eax,DWORD PTR [eax]
0x564047   8bc8                               mov    ecx,eax
0x564049   bf7074fb00                         mov    edi,0xfb7470
0x56404e   e82d2ef9ff                         call   0x4f6e80
0x564053   bf01000000                         mov    edi,0x1
0x564058   f605b075fb0001                     test   BYTE PTR ds:0xfb75b0,0x1
0x56405f   7524                               jne    0x564085
0x564061   093db075fb00                       or     DWORD PTR ds:0xfb75b0,edi
0x564067   897c2450                           mov    DWORD PTR [esp+0x50],edi
0x56406b   e810fdf8ff                         call   0x4f3d80
0x564070   68e0d1bc00                         push   0xbcd1e0
0x564075   e8a0e23200                         call   0x89231a
0x56407a   83c404                             add    esp,0x4
0x56407d   c7442450ffffffff                   mov    DWORD PTR [esp+0x50],0xffffffff
0x564085   8b5634                             mov    edx,DWORD PTR [esi+0x34]
0x564088   89542414                           mov    DWORD PTR [esp+0x14],edx
0x56408c   8d542414                           lea    edx,[esp+0x14]
0x564090   b9b074fb00                         mov    ecx,0xfb74b0
0x564095   e8563df9ff                         call   0x4f7df0
0x56409a   395814                             cmp    DWORD PTR [eax+0x14],ebx
0x56409d   7202                               jb     0x5640a1
0x56409f   8b00                               mov    eax,DWORD PTR [eax]
0x5640a1   f605b075fb0001                     test   BYTE PTR ds:0xfb75b0,0x1
0x5640a8   89442418                           mov    DWORD PTR [esp+0x18],eax
0x5640ac   7528                               jne    0x5640d6
0x5640ae   093db075fb00                       or     DWORD PTR ds:0xfb75b0,edi
0x5640b4   c744245002000000                   mov    DWORD PTR [esp+0x50],0x2
0x5640bc   e8bffcf8ff                         call   0x4f3d80
0x5640c1   68e0d1bc00                         push   0xbcd1e0
0x5640c6   e84fe23200                         call   0x89231a
0x5640cb   83c404                             add    esp,0x4
0x5640ce   c7442450ffffffff                   mov    DWORD PTR [esp+0x50],0xffffffff
0x5640d6   8b4e34                             mov    ecx,DWORD PTR [esi+0x34]
0x5640d9   8d542414                           lea    edx,[esp+0x14]
0x5640dd   894c2414                           mov    DWORD PTR [esp+0x14],ecx
0x5640e1   52                                 push   edx
0x5640e2   8d442424                           lea    eax,[esp+0x24]
0x5640e6   b9f074fb00                         mov    ecx,0xfb74f0
0x5640eb   e800bdf1ff                         call   0x47fdf0
0x5640f0   8b442420                           mov    eax,DWORD PTR [esp+0x20]
0x5640f4   3b05f474fb00                       cmp    eax,DWORD PTR ds:0xfb74f4
0x5640fa   741b                               je     0x564117
0x5640fc   83c010                             add    eax,0x10
0x5640ff   395814                             cmp    DWORD PTR [eax+0x14],ebx
0x564102   7202                               jb     0x564106
0x564104   8b00                               mov    eax,DWORD PTR [eax]
0x564106   8bc8                               mov    ecx,eax
0x564108   bf7074fb00                         mov    edi,0xfb7470
0x56410d   e86e2df9ff                         call   0x4f6e80
0x564112   bf01000000                         mov    edi,0x1
0x564117   837e5400                           cmp    DWORD PTR [esi+0x54],0x0
0x56411b   0f84bc010000                       je     0x5642dd
0x564121   6a06                               push   0x6
0x564123   683c07c100                         push   0xc1073c
0x564128   8d4c242c                           lea    ecx,[esp+0x2c]
0x56412c   c74424400f000000                   mov    DWORD PTR [esp+0x40],0xf
0x564134   c744243c00000000                   mov    DWORD PTR [esp+0x3c],0x0
0x56413c   c644242c00                         mov    BYTE PTR [esp+0x2c],0x0
0x564141   e82ae9e9ff                         call   0x402a70
0x564146   6aff                               push   0xffffffff
0x564148   6a00                               push   0x0
0x56414a   83c644                             add    esi,0x44
0x56414d   bb03000000                         mov    ebx,0x3
0x564152   56                                 push   esi
0x564153   8d4c2430                           lea    ecx,[esp+0x30]
0x564157   895c245c                           mov    DWORD PTR [esp+0x5c],ebx
0x56415b   e870dde9ff                         call   0x401ed0
0x564160   f6052888fb0001                     test   BYTE PTR ds:0xfb8828,0x1
0x564167   7522                               jne    0x56418b
0x564169   830d2888fb0001                     or     DWORD PTR ds:0xfb8828,0x1
0x564170   c644245004                         mov    BYTE PTR [esp+0x50],0x4
0x564175   e8d6b6feff                         call   0x54f850
0x56417a   6880d5bc00                         push   0xbcd580
0x56417f   e896e13200                         call   0x89231a
0x564184   83c404                             add    esp,0x4
0x564187   885c2450                           mov    BYTE PTR [esp+0x50],bl
0x56418b   f6052888fb0001                     test   BYTE PTR ds:0xfb8828,0x1
0x564192   668b35ea90fb00                     mov    si,WORD PTR ds:0xfb90ea
0x564199   7522                               jne    0x5641bd
0x56419b   830d2888fb0001                     or     DWORD PTR ds:0xfb8828,0x1
0x5641a2   c644245005                         mov    BYTE PTR [esp+0x50],0x5
0x5641a7   e8a4b6feff                         call   0x54f850
0x5641ac   6880d5bc00                         push   0xbcd580
0x5641b1   e864e13200                         call   0x89231a
0x5641b6   83c404                             add    esp,0x4
0x5641b9   885c2450                           mov    BYTE PTR [esp+0x50],bl
0x5641bd   f605c00ffc0001                     test   BYTE PTR ds:0xfc0fc0,0x1
0x5641c4   f30f10055c93fb00                   movss  xmm0,DWORD PTR ds:0xfb935c
0x5641cc   f30f11442414                       movss  DWORD PTR [esp+0x14],xmm0
0x5641d2   7522                               jne    0x5641f6
0x5641d4   830dc00ffc0001                     or     DWORD PTR ds:0xfc0fc0,0x1
0x5641db   c644245006                         mov    BYTE PTR [esp+0x50],0x6
0x5641e0   e86b4c1700                         call   0x6d8e50
0x5641e5   68b0dbbc00                         push   0xbcdbb0
0x5641ea   e82be13200                         call   0x89231a
0x5641ef   83c404                             add    esp,0x4
0x5641f2   885c2450                           mov    BYTE PTR [esp+0x50],bl
0x5641f6   837c243810                         cmp    DWORD PTR [esp+0x38],0x10
0x5641fb   8b7c2424                           mov    edi,DWORD PTR [esp+0x24]
0x5641ff   7304                               jae    0x564205
0x564201   8d7c2424                           lea    edi,[esp+0x24]
0x564205   f605c00ffc0001                     test   BYTE PTR ds:0xfc0fc0,0x1
0x56420c   7522                               jne    0x564230
0x56420e   830dc00ffc0001                     or     DWORD PTR ds:0xfc0fc0,0x1
0x564215   c644245007                         mov    BYTE PTR [esp+0x50],0x7
0x56421a   e8314c1700                         call   0x6d8e50
0x56421f   68b0dbbc00                         push   0xbcdbb0
0x564224   e8f1e03200                         call   0x89231a
0x564229   83c404                             add    esp,0x4
0x56422c   885c2450                           mov    BYTE PTR [esp+0x50],bl
0x564230   0fbfc6                             movsx  eax,si
0x564233   89442420                           mov    DWORD PTR [esp+0x20],eax
0x564237   db442420                           fild   DWORD PTR [esp+0x20]
0x56423b   d84c2414                           fmul   DWORD PTR [esp+0x14]
0x56423f   e8ccaa3900                         call   0x8fed10
0x564244   e827681700                         call   0x6daa70
0x564249   e8c2aa3900                         call   0x8fed10
0x56424e   0fb7c0                             movzx  eax,ax
0x564251   50                                 push   eax
0x564252   6a01                               push   0x1
0x564254   57                                 push   edi
0x564255   68c80ffc00                         push   0xfc0fc8
0x56425a   b9fc0ffc00                         mov    ecx,0xfc0ffc
0x56425f   e8cc581700                         call   0x6d9b30
0x564264   f605c00ffc0001                     test   BYTE PTR ds:0xfc0fc0,0x1
0x56426b   7522                               jne    0x56428f
0x56426d   830dc00ffc0001                     or     DWORD PTR ds:0xfc0fc0,0x1
0x564274   c644245008                         mov    BYTE PTR [esp+0x50],0x8
0x564279   e8d24b1700                         call   0x6d8e50
0x56427e   68b0dbbc00                         push   0xbcdbb0
0x564283   e892e03200                         call   0x89231a
0x564288   83c404                             add    esp,0x4
0x56428b   885c2450                           mov    BYTE PTR [esp+0x50],bl
0x56428f   8b4c241c                           mov    ecx,DWORD PTR [esp+0x1c]
0x564293   8b5134                             mov    edx,DWORD PTR [ecx+0x34]
0x564296   52                                 push   edx
0x564297   68c80ffc00                         push   0xfc0fc8
0x56429c   e8df521700                         call   0x6d9580
0x5642a1   c7442450ffffffff                   mov    DWORD PTR [esp+0x50],0xffffffff
0x5642a9   837c243810                         cmp    DWORD PTR [esp+0x38],0x10
0x5642ae   720d                               jb     0x5642bd
0x5642b0   8b442424                           mov    eax,DWORD PTR [esp+0x24]
0x5642b4   50                                 push   eax
0x5642b5   e852cf3200                         call   0x89120c
0x5642ba   83c404                             add    esp,0x4
0x5642bd   8b74241c                           mov    esi,DWORD PTR [esp+0x1c]
0x5642c1   c74424380f000000                   mov    DWORD PTR [esp+0x38],0xf
0x5642c9   c744243400000000                   mov    DWORD PTR [esp+0x34],0x0
0x5642d1   c644242400                         mov    BYTE PTR [esp+0x24],0x0
0x5642d6   bf01000000                         mov    edi,0x1
0x5642db   eb3f                               jmp    0x56431c
0x5642dd   f605c00ffc0001                     test   BYTE PTR ds:0xfc0fc0,0x1
0x5642e4   7528                               jne    0x56430e
0x5642e6   093dc00ffc00                       or     DWORD PTR ds:0xfc0fc0,edi
0x5642ec   c744245009000000                   mov    DWORD PTR [esp+0x50],0x9
0x5642f4   e8574b1700                         call   0x6d8e50
0x5642f9   68b0dbbc00                         push   0xbcdbb0
0x5642fe   e817e03200                         call   0x89231a
0x564303   83c404                             add    esp,0x4
0x564306   c7442450ffffffff                   mov    DWORD PTR [esp+0x50],0xffffffff
0x56430e   8b4e34                             mov    ecx,DWORD PTR [esi+0x34]
0x564311   51                                 push   ecx
0x564312   68c80ffc00                         push   0xfc0fc8
0x564317   e864521700                         call   0x6d9580
0x56431c   f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
0x564323   7528                               jne    0x56434d
0x564325   093d2cb2fa00                       or     DWORD PTR ds:0xfab22c,edi
0x56432b   c74424500a000000                   mov    DWORD PTR [esp+0x50],0xa
0x564333   e858a9f7ff                         call   0x4dec90
0x564338   6830cebc00                         push   0xbcce30
0x56433d   e8d8df3200                         call   0x89231a
0x564342   83c404                             add    esp,0x4
0x564345   c7442450ffffffff                   mov    DWORD PTR [esp+0x50],0xffffffff
0x56434d   8b1578b1fa00                       mov    edx,DWORD PTR ds:0xfab178
0x564353   895634                             mov    DWORD PTR [esi+0x34],edx
0x564356   8b742418                           mov    esi,DWORD PTR [esp+0x18]
0x56435a   6a00                               push   0x0
0x56435c   e89fda2500                         call   0x7c1e00
0x564361   83c404                             add    esp,0x4
0x564364   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x56436b   7521                               jne    0x56438e
0x56436d   830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
0x564374   c74424500b000000                   mov    DWORD PTR [esp+0x50],0xb
0x56437c   e85f4a2300                         call   0x798de0
0x564381   68e0d2bc00                         push   0xbcd2e0
0x564386   e88fdf3200                         call   0x89231a
0x56438b   83c404                             add    esp,0x4
0x56438e   8b44241c                           mov    eax,DWORD PTR [esp+0x1c]
0x564392   8b4830                             mov    ecx,DWORD PTR [eax+0x30]
0x564395   a1e876fb00                         mov    eax,ds:0xfb76e8
0x56439a   e8d13f2300                         call   0x798370
0x56439f   8b4c2448                           mov    ecx,DWORD PTR [esp+0x48]
0x5643a3   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x5643aa   59                                 pop    ecx
0x5643ab   5f                                 pop    edi
0x5643ac   5e                                 pop    esi
0x5643ad   5b                                 pop    ebx
0x5643ae   8b4c2430                           mov    ecx,DWORD PTR [esp+0x30]
0x5643b2   33cc                               xor    ecx,esp
0x5643b4   e848cc3200                         call   0x891001
0x5643b9   8be5                               mov    esp,ebp
0x5643bb   5d                                 pop    ebp
0x5643bc   c3                                 ret

; q_constructor [0x560170,0x56041a) raw=0x15f570 sha256=0e935b9889bac2baf5ab9ba047542789128eeaf557655e64d43927f0d16c89bc Allocate initial camera backup, not a current-run capture
0x560170   55                                 push   ebp
0x560171   8bec                               mov    ebp,esp
0x560173   6aff                               push   0xffffffff
0x560175   68c8ad9300                         push   0x93adc8
0x56017a   64a100000000                       mov    eax,fs:0x0
0x560180   50                                 push   eax
0x560181   83ec38                             sub    esp,0x38
0x560184   53                                 push   ebx
0x560185   56                                 push   esi
0x560186   a1201fd600                         mov    eax,ds:0xd61f20
0x56018b   33c5                               xor    eax,ebp
0x56018d   50                                 push   eax
0x56018e   8d45f4                             lea    eax,[ebp-0xc]
0x560191   64a300000000                       mov    fs:0x0,eax
0x560197   33db                               xor    ebx,ebx
0x560199   6a34                               push   0x34
0x56019b   c745e4c073fb00                     mov    DWORD PTR [ebp-0x1c],0xfb73c0
0x5601a2   891dc073fb00                       mov    DWORD PTR ds:0xfb73c0,ebx
0x5601a8   891dc473fb00                       mov    DWORD PTR ds:0xfb73c4,ebx
0x5601ae   891dd073fb00                       mov    DWORD PTR ds:0xfb73d0,ebx
0x5601b4   e8af103300                         call   0x891268
0x5601b9   83c404                             add    esp,0x4
0x5601bc   3bc3                               cmp    eax,ebx
0x5601be   0f8432020000                       je     0x5603f6
0x5601c4   a3cc73fb00                         mov    ds:0xfb73cc,eax
0x5601c9   8900                               mov    DWORD PTR [eax],eax
0x5601cb   a1cc73fb00                         mov    eax,ds:0xfb73cc
0x5601d0   894004                             mov    DWORD PTR [eax+0x4],eax
0x5601d3   a1cc73fb00                         mov    eax,ds:0xfb73cc
0x5601d8   894008                             mov    DWORD PTR [eax+0x8],eax
0x5601db   a1cc73fb00                         mov    eax,ds:0xfb73cc
0x5601e0   c6403001                           mov    BYTE PTR [eax+0x30],0x1
0x5601e4   8b0dcc73fb00                       mov    ecx,DWORD PTR ds:0xfb73cc
0x5601ea   c6413101                           mov    BYTE PTR [ecx+0x31],0x1
0x5601ee   895dfc                             mov    DWORD PTR [ebp-0x4],ebx
0x5601f1   6a18                               push   0x18
0x5601f3   891de073fb00                       mov    DWORD PTR ds:0xfb73e0,ebx
0x5601f9   e86a103300                         call   0x891268
0x5601fe   83c404                             add    esp,0x4
0x560201   3bc3                               cmp    eax,ebx
0x560203   0f84c9010000                       je     0x5603d2
0x560209   a3dc73fb00                         mov    ds:0xfb73dc,eax
0x56020e   8900                               mov    DWORD PTR [eax],eax
0x560210   a1dc73fb00                         mov    eax,ds:0xfb73dc
0x560215   894004                             mov    DWORD PTR [eax+0x4],eax
0x560218   a1dc73fb00                         mov    eax,ds:0xfb73dc
0x56021d   894008                             mov    DWORD PTR [eax+0x8],eax
0x560220   8b15dc73fb00                       mov    edx,DWORD PTR ds:0xfb73dc
0x560226   c6421401                           mov    BYTE PTR [edx+0x14],0x1
0x56022a   a1dc73fb00                         mov    eax,ds:0xfb73dc
0x56022f   c6401501                           mov    BYTE PTR [eax+0x15],0x1
0x560233   c645fc01                           mov    BYTE PTR [ebp-0x4],0x1
0x560237   6a48                               push   0x48
0x560239   891de873fb00                       mov    DWORD PTR ds:0xfb73e8,ebx
0x56023f   891dec73fb00                       mov    DWORD PTR ds:0xfb73ec,ebx
0x560245   e81e103300                         call   0x891268
0x56024a   83c404                             add    esp,0x4
0x56024d   8945e8                             mov    DWORD PTR [ebp-0x18],eax
0x560250   c645fc02                           mov    BYTE PTR [ebp-0x4],0x2
0x560254   3bc3                               cmp    eax,ebx
0x560256   7409                               je     0x560261
0x560258   8bf0                               mov    esi,eax
0x56025a   e851d02600                         call   0x7cd2b0
0x56025f   eb02                               jmp    0x560263
0x560261   33c0                               xor    eax,eax
0x560263   a3f073fb00                         mov    ds:0xfb73f0,eax
0x560268   891df873fb00                       mov    DWORD PTR ds:0xfb73f8,ebx
0x56026e   891dfc73fb00                       mov    DWORD PTR ds:0xfb73fc,ebx
0x560274   c7050074fb00ffffffff               mov    DWORD PTR ds:0xfb7400,0xffffffff
0x56027e   c7051874fb000f000000               mov    DWORD PTR ds:0xfb7418,0xf
0x560288   891d1474fb00                       mov    DWORD PTR ds:0xfb7414,ebx
0x56028e   881d0474fb00                       mov    BYTE PTR ds:0xfb7404,bl
0x560294   c645fc03                           mov    BYTE PTR [ebp-0x4],0x3
0x560298   6a14                               push   0x14
0x56029a   891d2874fb00                       mov    DWORD PTR ds:0xfb7428,ebx
0x5602a0   e8c30f3300                         call   0x891268
0x5602a5   83c404                             add    esp,0x4
0x5602a8   3bc3                               cmp    eax,ebx
0x5602aa   0f84fe000000                       je     0x5603ae
0x5602b0   a32474fb00                         mov    ds:0xfb7424,eax
0x5602b5   8900                               mov    DWORD PTR [eax],eax
0x5602b7   a12474fb00                         mov    eax,ds:0xfb7424
0x5602bc   894004                             mov    DWORD PTR [eax+0x4],eax
0x5602bf   a12474fb00                         mov    eax,ds:0xfb7424
0x5602c4   894008                             mov    DWORD PTR [eax+0x8],eax
0x5602c7   8b0d2474fb00                       mov    ecx,DWORD PTR ds:0xfb7424
0x5602cd   c6411001                           mov    BYTE PTR [ecx+0x10],0x1
0x5602d1   8b152474fb00                       mov    edx,DWORD PTR ds:0xfb7424
0x5602d7   c6421101                           mov    BYTE PTR [edx+0x11],0x1
0x5602db   c645fc04                           mov    BYTE PTR [ebp-0x4],0x4
0x5602df   6a14                               push   0x14
0x5602e1   891d3074fb00                       mov    DWORD PTR ds:0xfb7430,ebx
0x5602e7   891d3c74fb00                       mov    DWORD PTR ds:0xfb743c,ebx
0x5602ed   e8760f3300                         call   0x891268
0x5602f2   83c404                             add    esp,0x4
0x5602f5   3bc3                               cmp    eax,ebx
0x5602f7   0f848d000000                       je     0x56038a
0x5602fd   a33874fb00                         mov    ds:0xfb7438,eax
0x560302   8900                               mov    DWORD PTR [eax],eax
0x560304   a13874fb00                         mov    eax,ds:0xfb7438
0x560309   894004                             mov    DWORD PTR [eax+0x4],eax
0x56030c   a13874fb00                         mov    eax,ds:0xfb7438
0x560311   894008                             mov    DWORD PTR [eax+0x8],eax
0x560314   a13874fb00                         mov    eax,ds:0xfb7438
0x560319   c6401001                           mov    BYTE PTR [eax+0x10],0x1
0x56031d   8b0d3874fb00                       mov    ecx,DWORD PTR ds:0xfb7438
0x560323   c6411101                           mov    BYTE PTR [ecx+0x11],0x1
0x560327   c645fc05                           mov    BYTE PTR [ebp-0x4],0x5
0x56032b   f30f1005c056c400                   movss  xmm0,DWORD PTR ds:0xc456c0
0x560333   f30f11054474fb00                   movss  DWORD PTR ds:0xfb7444,xmm0
0x56033b   66c7054874fb000100                 mov    WORD PTR ds:0xfb7448,0x1
0x560344   e887040000                         call   0x5607d0
0x560349   e8f2200000                         call   0x562440
0x56034e   f6054027fe0001                     test   BYTE PTR ds:0xfe2740,0x1
0x560355   751d                               jne    0x560374
0x560357   830d4027fe0001                     or     DWORD PTR ds:0xfe2740,0x1
0x56035e   c645fc06                           mov    BYTE PTR [ebp-0x4],0x6
0x560362   e819e3ffff                         call   0x55e680
0x560367   68a0f2bc00                         push   0xbcf2a0
0x56036c   e8a91f3300                         call   0x89231a
0x560371   83c404                             add    esp,0x4
0x560374   b8c073fb00                         mov    eax,0xfb73c0
0x560379   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x56037c   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x560383   59                                 pop    ecx
0x560384   5e                                 pop    esi
0x560385   5b                                 pop    ebx
0x560386   8be5                               mov    esp,ebp
0x560388   5d                                 pop    ebp
0x560389   c3                                 ret
0x56038a   8d55f0                             lea    edx,[ebp-0x10]
0x56038d   52                                 push   edx
0x56038e   8d4dd8                             lea    ecx,[ebp-0x28]
0x560391   895df0                             mov    DWORD PTR [ebp-0x10],ebx
0x560394   e8100d3300                         call   0x8910a9
0x560399   68a857c800                         push   0xc857a8
0x56039e   8d45d8                             lea    eax,[ebp-0x28]
0x5603a1   50                                 push   eax
0x5603a2   c745d8a42cbd00                     mov    DWORD PTR [ebp-0x28],0xbd2ca4
0x5603a9   e842c63300                         call   0x89c9f0
0x5603ae   8d4dec                             lea    ecx,[ebp-0x14]
0x5603b1   51                                 push   ecx
0x5603b2   8d4dcc                             lea    ecx,[ebp-0x34]
0x5603b5   895dec                             mov    DWORD PTR [ebp-0x14],ebx
0x5603b8   e8ec0c3300                         call   0x8910a9
0x5603bd   68a857c800                         push   0xc857a8
0x5603c2   8d55cc                             lea    edx,[ebp-0x34]
0x5603c5   52                                 push   edx
0x5603c6   c745cca42cbd00                     mov    DWORD PTR [ebp-0x34],0xbd2ca4
0x5603cd   e81ec63300                         call   0x89c9f0
0x5603d2   8d45ec                             lea    eax,[ebp-0x14]
0x5603d5   50                                 push   eax
0x5603d6   8d4dcc                             lea    ecx,[ebp-0x34]
0x5603d9   895dec                             mov    DWORD PTR [ebp-0x14],ebx
0x5603dc   e8c80c3300                         call   0x8910a9
0x5603e1   68a857c800                         push   0xc857a8
0x5603e6   8d4dcc                             lea    ecx,[ebp-0x34]
0x5603e9   51                                 push   ecx
0x5603ea   c745cca42cbd00                     mov    DWORD PTR [ebp-0x34],0xbd2ca4
0x5603f1   e8fac53300                         call   0x89c9f0
0x5603f6   8d55e8                             lea    edx,[ebp-0x18]
0x5603f9   52                                 push   edx
0x5603fa   8d4dc0                             lea    ecx,[ebp-0x40]
0x5603fd   895de8                             mov    DWORD PTR [ebp-0x18],ebx
0x560400   e8a40c3300                         call   0x8910a9
0x560405   68a857c800                         push   0xc857a8
0x56040a   8d45c0                             lea    eax,[ebp-0x40]
0x56040d   50                                 push   eax
0x56040e   c745c0a42cbd00                     mov    DWORD PTR [ebp-0x40],0xbd2ca4
0x560415   e8d6c53300                         call   0x89c9f0

; default_camera_snapshot [0x7cd2b0,0x7cd309) raw=0x3cc6b0 sha256=facf88d4922e946e510623d6f600f4ae6a2118247155cdd734114b16580f0116 Default numeric camera snapshot initialization
0x7cd2b0   d9ee                               fldz
0x7cd2b2   8d4e2c                             lea    ecx,[esi+0x2c]
0x7cd2b5   d916                               fst    DWORD PTR [esi]
0x7cd2b7   6a07                               push   0x7
0x7cd2b9   d95604                             fst    DWORD PTR [esi+0x4]
0x7cd2bc   68c0f6c000                         push   0xc0f6c0
0x7cd2c1   d95608                             fst    DWORD PTR [esi+0x8]
0x7cd2c4   d905a857c500                       fld    DWORD PTR ds:0xc557a8
0x7cd2ca   d95e0c                             fstp   DWORD PTR [esi+0xc]
0x7cd2cd   d95610                             fst    DWORD PTR [esi+0x10]
0x7cd2d0   d95614                             fst    DWORD PTR [esi+0x14]
0x7cd2d3   d95618                             fst    DWORD PTR [esi+0x18]
0x7cd2d6   d95e1c                             fstp   DWORD PTR [esi+0x1c]
0x7cd2d9   d9e8                               fld1
0x7cd2db   d95e20                             fstp   DWORD PTR [esi+0x20]
0x7cd2de   d9053458c500                       fld    DWORD PTR ds:0xc55834
0x7cd2e4   d95e24                             fstp   DWORD PTR [esi+0x24]
0x7cd2e7   d9053058c500                       fld    DWORD PTR ds:0xc55830
0x7cd2ed   d95e28                             fstp   DWORD PTR [esi+0x28]
0x7cd2f0   c741140f000000                     mov    DWORD PTR [ecx+0x14],0xf
0x7cd2f7   c7411000000000                     mov    DWORD PTR [ecx+0x10],0x0
0x7cd2fe   c60100                             mov    BYTE PTR [ecx],0x0
0x7cd301   e86a57c3ff                         call   0x402a70
0x7cd306   8bc6                               mov    eax,esi
0x7cd308   c3                                 ret

; apply_camera_snapshot [0x798370,0x798436) raw=0x397770 sha256=81d2abe16f50aeead39cac35cb0dc462dca03ac91353f48672474a951d06100e Apply numeric camera snapshot/lens state
0x798370   55                                 push   ebp
0x798371   8bec                               mov    ebp,esp
0x798373   51                                 push   ecx
0x798374   8b11                               mov    edx,DWORD PTR [ecx]
0x798376   89500c                             mov    DWORD PTR [eax+0xc],edx
0x798379   8b5104                             mov    edx,DWORD PTR [ecx+0x4]
0x79837c   895010                             mov    DWORD PTR [eax+0x10],edx
0x79837f   8b5108                             mov    edx,DWORD PTR [ecx+0x8]
0x798382   895014                             mov    DWORD PTR [eax+0x14],edx
0x798385   33d2                               xor    edx,edx
0x798387   8990cc000000                       mov    DWORD PTR [eax+0xcc],edx
0x79838d   d94114                             fld    DWORD PTR [ecx+0x14]
0x798390   d95820                             fstp   DWORD PTR [eax+0x20]
0x798393   8990cc000000                       mov    DWORD PTR [eax+0xcc],edx
0x798399   d94110                             fld    DWORD PTR [ecx+0x10]
0x79839c   8990cc000000                       mov    DWORD PTR [eax+0xcc],edx
0x7983a2   d9581c                             fstp   DWORD PTR [eax+0x1c]
0x7983a5   56                                 push   esi
0x7983a6   d9410c                             fld    DWORD PTR [ecx+0xc]
0x7983a9   8b30                               mov    esi,DWORD PTR [eax]
0x7983ab   d95818                             fstp   DWORD PTR [eax+0x18]
0x7983ae   8990cc000000                       mov    DWORD PTR [eax+0xcc],edx
0x7983b4   d94110                             fld    DWORD PTR [ecx+0x10]
0x7983b7   8990cc000000                       mov    DWORD PTR [eax+0xcc],edx
0x7983bd   d9581c                             fstp   DWORD PTR [eax+0x1c]
0x7983c0   d94124                             fld    DWORD PTR [ecx+0x24]
0x7983c3   d95dfc                             fstp   DWORD PTR [ebp-0x4]
0x7983c6   d945fc                             fld    DWORD PTR [ebp-0x4]
0x7983c9   3bf2                               cmp    esi,edx
0x7983cb   7403                               je     0x7983d0
0x7983cd   d9567c                             fst    DWORD PTR [esi+0x7c]
0x7983d0   8b30                               mov    esi,DWORD PTR [eax]
0x7983d2   d95830                             fstp   DWORD PTR [eax+0x30]
0x7983d5   d94120                             fld    DWORD PTR [ecx+0x20]
0x7983d8   d95dfc                             fstp   DWORD PTR [ebp-0x4]
0x7983db   d945fc                             fld    DWORD PTR [ebp-0x4]
0x7983de   3bf2                               cmp    esi,edx
0x7983e0   7403                               je     0x7983e5
0x7983e2   d95678                             fst    DWORD PTR [esi+0x78]
0x7983e5   8b30                               mov    esi,DWORD PTR [eax]
0x7983e7   d9582c                             fstp   DWORD PTR [eax+0x2c]
0x7983ea   8990cc000000                       mov    DWORD PTR [eax+0xcc],edx
0x7983f0   d94128                             fld    DWORD PTR [ecx+0x28]
0x7983f3   d95dfc                             fstp   DWORD PTR [ebp-0x4]
0x7983f6   8990cc000000                       mov    DWORD PTR [eax+0xcc],edx
0x7983fc   d945fc                             fld    DWORD PTR [ebp-0x4]
0x7983ff   d95034                             fst    DWORD PTR [eax+0x34]
0x798402   3bf2                               cmp    esi,edx
0x798404   7417                               je     0x79841d
0x798406   dc35f056c500                       fdiv   QWORD PTR ds:0xc556f0
0x79840c   d95dfc                             fstp   DWORD PTR [ebp-0x4]
0x79840f   d945fc                             fld    DWORD PTR [ebp-0x4]
0x798412   d888bc000000                       fmul   DWORD PTR [eax+0xbc]
0x798418   d95e74                             fstp   DWORD PTR [esi+0x74]
0x79841b   eb02                               jmp    0x79841f
0x79841d   ddd8                               fstp   st(0)
0x79841f   d9411c                             fld    DWORD PTR [ecx+0x1c]
0x798422   5e                                 pop    esi
0x798423   d95828                             fstp   DWORD PTR [eax+0x28]
0x798426   d94118                             fld    DWORD PTR [ecx+0x18]
0x798429   8990cc000000                       mov    DWORD PTR [eax+0xcc],edx
0x79842f   d95824                             fstp   DWORD PTR [eax+0x24]
0x798432   8be5                               mov    esp,ebp
0x798434   5d                                 pop    ebp
0x798435   c3                                 ret

; world_owner_getter [0x40f060,0x40f0c9) raw=0xe460 sha256=5e197667d9afd7448532e6c560f1eecd7b6454618ce1b01483291ba0b0775117 Lazy world singleton FAB130
0x40f060   55                                 push   ebp
0x40f061   8bec                               mov    ebp,esp
0x40f063   83e4f8                             and    esp,0xfffffff8
0x40f066   6aff                               push   0xffffffff
0x40f068   68ee619400                         push   0x9461ee
0x40f06d   64a100000000                       mov    eax,fs:0x0
0x40f073   50                                 push   eax
0x40f074   51                                 push   ecx
0x40f075   a1201fd600                         mov    eax,ds:0xd61f20
0x40f07a   33c4                               xor    eax,esp
0x40f07c   50                                 push   eax
0x40f07d   8d442408                           lea    eax,[esp+0x8]
0x40f081   64a300000000                       mov    fs:0x0,eax
0x40f087   b801000000                         mov    eax,0x1
0x40f08c   84052cb2fa00                       test   BYTE PTR ds:0xfab22c,al
0x40f092   7520                               jne    0x40f0b4
0x40f094   09052cb2fa00                       or     DWORD PTR ds:0xfab22c,eax
0x40f09a   c744241000000000                   mov    DWORD PTR [esp+0x10],0x0
0x40f0a2   e8e9fb0c00                         call   0x4dec90
0x40f0a7   6830cebc00                         push   0xbcce30
0x40f0ac   e869324800                         call   0x89231a
0x40f0b1   83c404                             add    esp,0x4
0x40f0b4   b830b1fa00                         mov    eax,0xfab130
0x40f0b9   8b4c2408                           mov    ecx,DWORD PTR [esp+0x8]
0x40f0bd   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x40f0c4   59                                 pop    ecx
0x40f0c5   8be5                               mov    esp,ebp
0x40f0c7   5d                                 pop    ebp
0x40f0c8   c3                                 ret

; world_owner_ctor [0x4dec90,0x4defc2) raw=0xde090 sha256=59b5c7022ba975f45335eac24e972bbb3a7ba8c532893148cf82b6f23b69c570 World render flag and two slow-motion fields initialization
0x4dec90   55                                 push   ebp
0x4dec91   8bec                               mov    ebp,esp
0x4dec93   6aff                               push   0xffffffff
0x4dec95   68db3d9300                         push   0x933ddb
0x4dec9a   64a100000000                       mov    eax,fs:0x0
0x4deca0   50                                 push   eax
0x4deca1   83ec24                             sub    esp,0x24
0x4deca4   53                                 push   ebx
0x4deca5   56                                 push   esi
0x4deca6   57                                 push   edi
0x4deca7   a1201fd600                         mov    eax,ds:0xd61f20
0x4decac   33c5                               xor    eax,ebp
0x4decae   50                                 push   eax
0x4decaf   8d45f4                             lea    eax,[ebp-0xc]
0x4decb2   64a300000000                       mov    fs:0x0,eax
0x4decb8   68245f0000                         push   0x5f24
0x4decbd   c745e830b1fa00                     mov    DWORD PTR [ebp-0x18],0xfab130
0x4decc4   e89f253b00                         call   0x891268
0x4decc9   33f6                               xor    esi,esi
0x4deccb   83c404                             add    esp,0x4
0x4decce   3bc6                               cmp    eax,esi
0x4decd0   7409                               je     0x4decdb
0x4decd2   8bc8                               mov    ecx,eax
0x4decd4   e827eaffff                         call   0x4dd700
0x4decd9   eb02                               jmp    0x4decdd
0x4decdb   33c0                               xor    eax,eax
0x4decdd   6a40                               push   0x40
0x4decdf   a330b1fa00                         mov    ds:0xfab130,eax
0x4dece4   e87f253b00                         call   0x891268
0x4dece9   83c404                             add    esp,0x4
0x4decec   3bc6                               cmp    eax,esi
0x4decee   742a                               je     0x4ded1a
0x4decf0   8930                               mov    DWORD PTR [eax],esi
0x4decf2   897004                             mov    DWORD PTR [eax+0x4],esi
0x4decf5   897008                             mov    DWORD PTR [eax+0x8],esi
0x4decf8   897010                             mov    DWORD PTR [eax+0x10],esi
0x4decfb   897014                             mov    DWORD PTR [eax+0x14],esi
0x4decfe   897018                             mov    DWORD PTR [eax+0x18],esi
0x4ded01   33c9                               xor    ecx,ecx
0x4ded03   897020                             mov    DWORD PTR [eax+0x20],esi
0x4ded06   897024                             mov    DWORD PTR [eax+0x24],esi
0x4ded09   897028                             mov    DWORD PTR [eax+0x28],esi
0x4ded0c   894830                             mov    DWORD PTR [eax+0x30],ecx
0x4ded0f   b938000000                         mov    ecx,0x38
0x4ded14   66894834                           mov    WORD PTR [eax+0x34],cx
0x4ded18   eb02                               jmp    0x4ded1c
0x4ded1a   33c0                               xor    eax,eax
0x4ded1c   6a18                               push   0x18
0x4ded1e   a334b1fa00                         mov    ds:0xfab134,eax
0x4ded23   893540b1fa00                       mov    DWORD PTR ds:0xfab140,esi
0x4ded29   e83a253b00                         call   0x891268
0x4ded2e   83c404                             add    esp,0x4
0x4ded31   3bc6                               cmp    eax,esi
0x4ded33   0f8465020000                       je     0x4def9e
0x4ded39   a33cb1fa00                         mov    ds:0xfab13c,eax
0x4ded3e   8900                               mov    DWORD PTR [eax],eax
0x4ded40   a13cb1fa00                         mov    eax,ds:0xfab13c
0x4ded45   894004                             mov    DWORD PTR [eax+0x4],eax
0x4ded48   a13cb1fa00                         mov    eax,ds:0xfab13c
0x4ded4d   894008                             mov    DWORD PTR [eax+0x8],eax
0x4ded50   8b153cb1fa00                       mov    edx,DWORD PTR ds:0xfab13c
0x4ded56   bb01000000                         mov    ebx,0x1
0x4ded5b   885a14                             mov    BYTE PTR [edx+0x14],bl
0x4ded5e   a13cb1fa00                         mov    eax,ds:0xfab13c
0x4ded63   885815                             mov    BYTE PTR [eax+0x15],bl
0x4ded66   8975fc                             mov    DWORD PTR [ebp-0x4],esi
0x4ded69   6a18                               push   0x18
0x4ded6b   893550b1fa00                       mov    DWORD PTR ds:0xfab150,esi
0x4ded71   e8f2243b00                         call   0x891268
0x4ded76   83c404                             add    esp,0x4
0x4ded79   3bc6                               cmp    eax,esi
0x4ded7b   0f84f9010000                       je     0x4def7a
0x4ded81   a34cb1fa00                         mov    ds:0xfab14c,eax
0x4ded86   8900                               mov    DWORD PTR [eax],eax
0x4ded88   a14cb1fa00                         mov    eax,ds:0xfab14c
0x4ded8d   894004                             mov    DWORD PTR [eax+0x4],eax
0x4ded90   a14cb1fa00                         mov    eax,ds:0xfab14c
0x4ded95   894008                             mov    DWORD PTR [eax+0x8],eax
0x4ded98   8b0d4cb1fa00                       mov    ecx,DWORD PTR ds:0xfab14c
0x4ded9e   885914                             mov    BYTE PTR [ecx+0x14],bl
0x4deda1   8b154cb1fa00                       mov    edx,DWORD PTR ds:0xfab14c
0x4deda7   885a15                             mov    BYTE PTR [edx+0x15],bl
0x4dedaa   885dfc                             mov    BYTE PTR [ebp-0x4],bl
0x4dedad   6a18                               push   0x18
0x4dedaf   893560b1fa00                       mov    DWORD PTR ds:0xfab160,esi
0x4dedb5   e8ae243b00                         call   0x891268
0x4dedba   83c404                             add    esp,0x4
0x4dedbd   3bc6                               cmp    eax,esi
0x4dedbf   0f8491010000                       je     0x4def56
0x4dedc5   a35cb1fa00                         mov    ds:0xfab15c,eax
0x4dedca   8900                               mov    DWORD PTR [eax],eax
0x4dedcc   a15cb1fa00                         mov    eax,ds:0xfab15c
0x4dedd1   894004                             mov    DWORD PTR [eax+0x4],eax
0x4dedd4   a15cb1fa00                         mov    eax,ds:0xfab15c
0x4dedd9   894008                             mov    DWORD PTR [eax+0x8],eax
0x4deddc   a15cb1fa00                         mov    eax,ds:0xfab15c
0x4dede1   885814                             mov    BYTE PTR [eax+0x14],bl
0x4dede4   8b0d5cb1fa00                       mov    ecx,DWORD PTR ds:0xfab15c
0x4dedea   885915                             mov    BYTE PTR [ecx+0x15],bl
0x4deded   c645fc02                           mov    BYTE PTR [ebp-0x4],0x2
0x4dedf1   6a18                               push   0x18
0x4dedf3   893570b1fa00                       mov    DWORD PTR ds:0xfab170,esi
0x4dedf9   e86a243b00                         call   0x891268
0x4dedfe   83c404                             add    esp,0x4
0x4dee01   3bc6                               cmp    eax,esi
0x4dee03   0f8429010000                       je     0x4def32
0x4dee09   a36cb1fa00                         mov    ds:0xfab16c,eax
0x4dee0e   8900                               mov    DWORD PTR [eax],eax
0x4dee10   a16cb1fa00                         mov    eax,ds:0xfab16c
0x4dee15   894004                             mov    DWORD PTR [eax+0x4],eax
0x4dee18   a16cb1fa00                         mov    eax,ds:0xfab16c
0x4dee1d   894008                             mov    DWORD PTR [eax+0x8],eax
0x4dee20   8b156cb1fa00                       mov    edx,DWORD PTR ds:0xfab16c
0x4dee26   885a14                             mov    BYTE PTR [edx+0x14],bl
0x4dee29   a16cb1fa00                         mov    eax,ds:0xfab16c
0x4dee2e   885815                             mov    BYTE PTR [eax+0x15],bl
0x4dee31   c645fc03                           mov    BYTE PTR [ebp-0x4],0x3
0x4dee35   83c8ff                             or     eax,0xffffffff
0x4dee38   56                                 push   esi
0x4dee39   68c8b1fa00                         push   0xfab1c8
0x4dee3e   a378b1fa00                         mov    ds:0xfab178,eax
0x4dee43   a3bcb1fa00                         mov    ds:0xfab1bc,eax
0x4dee48   a3c0b1fa00                         mov    ds:0xfab1c0,eax
0x4dee4d   a3c4b1fa00                         mov    ds:0xfab1c4,eax
0x4dee52   8935c8b1fa00                       mov    DWORD PTR ds:0xfab1c8,esi
0x4dee58   8935ccb1fa00                       mov    DWORD PTR ds:0xfab1cc,esi
0x4dee5e   e8cd220000                         call   0x4e1130
0x4dee63   c645fc04                           mov    BYTE PTR [ebp-0x4],0x4
0x4dee67   0f57c0                             xorps  xmm0,xmm0
0x4dee6a   6800b2fa00                         push   0xfab200
0x4dee6f   8935d0b1fa00                       mov    DWORD PTR ds:0xfab1d0,esi
0x4dee75   8935d4b1fa00                       mov    DWORD PTR ds:0xfab1d4,esi
0x4dee7b   8935d8b1fa00                       mov    DWORD PTR ds:0xfab1d8,esi
0x4dee81   f30f1105dcb1fa00                   movss  DWORD PTR ds:0xfab1dc,xmm0
0x4dee89   8935e0b1fa00                       mov    DWORD PTR ds:0xfab1e0,esi
0x4dee8f   8935e4b1fa00                       mov    DWORD PTR ds:0xfab1e4,esi
0x4dee95   e8467d1f00                         call   0x6d6be0
0x4dee9a   c645fc05                           mov    BYTE PTR [ebp-0x4],0x5
0x4dee9e   33c9                               xor    ecx,ecx
0x4deea0   66890d20b2fa00                     mov    WORD PTR ds:0xfab220,cx
0x4deea7   8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
0x4deead   893524b2fa00                       mov    DWORD PTR ds:0xfab224,esi
0x4deeb3   893528b2fa00                       mov    DWORD PTR ds:0xfab228,esi
0x4deeb9   3bce                               cmp    ecx,esi
0x4deebb   7429                               je     0x4deee6
0x4deebd   3935aca7fb00                       cmp    DWORD PTR ds:0xfba7ac,esi
0x4deec3   7509                               jne    0x4deece
0x4deec5   8bf9                               mov    edi,ecx
0x4deec7   e884600600                         call   0x544f50
0x4deecc   eb4d                               jmp    0x4def1b
0x4deece   8b11                               mov    edx,DWORD PTR [ecx]
0x4deed0   8b4228                             mov    eax,DWORD PTR [edx+0x28]
0x4deed3   ffd0                               call   eax
0x4deed5   8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
0x4deedb   3bce                               cmp    ecx,esi
0x4deedd   7407                               je     0x4deee6
0x4deedf   8b11                               mov    edx,DWORD PTR [ecx]
0x4deee1   8b02                               mov    eax,DWORD PTR [edx]
0x4deee3   53                                 push   ebx
0x4deee4   ffd0                               call   eax
0x4deee6   68b4000000                         push   0xb4
0x4deeeb   e878233b00                         call   0x891268
0x4deef0   83c404                             add    esp,0x4
0x4deef3   8945ec                             mov    DWORD PTR [ebp-0x14],eax
0x4deef6   c645fc09                           mov    BYTE PTR [ebp-0x4],0x9
0x4deefa   3bc6                               cmp    eax,esi
0x4deefc   7409                               je     0x4def07
0x4deefe   8bf0                               mov    esi,eax
0x4def00   e8db820600                         call   0x5471e0
0x4def05   eb02                               jmp    0x4def09
0x4def07   33c0                               xor    eax,eax
0x4def09   c645fc05                           mov    BYTE PTR [ebp-0x4],0x5
0x4def0d   8b10                               mov    edx,DWORD PTR [eax]
0x4def0f   a3a4a7fb00                         mov    ds:0xfba7a4,eax
0x4def14   8bc8                               mov    ecx,eax
0x4def16   8b4224                             mov    eax,DWORD PTR [edx+0x24]
0x4def19   ffd0                               call   eax
0x4def1b   b830b1fa00                         mov    eax,0xfab130
0x4def20   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x4def23   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x4def2a   59                                 pop    ecx
0x4def2b   5f                                 pop    edi
0x4def2c   5e                                 pop    esi
0x4def2d   5b                                 pop    ebx
0x4def2e   8be5                               mov    esp,ebp
0x4def30   5d                                 pop    ebp
0x4def31   c3                                 ret
0x4def32   8d4df0                             lea    ecx,[ebp-0x10]
0x4def35   51                                 push   ecx
0x4def36   8d4ddc                             lea    ecx,[ebp-0x24]
0x4def39   8975f0                             mov    DWORD PTR [ebp-0x10],esi
0x4def3c   e868213b00                         call   0x8910a9
0x4def41   68a857c800                         push   0xc857a8
0x4def46   8d55dc                             lea    edx,[ebp-0x24]
0x4def49   52                                 push   edx
0x4def4a   c745dca42cbd00                     mov    DWORD PTR [ebp-0x24],0xbd2ca4
0x4def51   e89ada3b00                         call   0x89c9f0
0x4def56   8d45ec                             lea    eax,[ebp-0x14]
0x4def59   50                                 push   eax
0x4def5a   8d4dd0                             lea    ecx,[ebp-0x30]
0x4def5d   8975ec                             mov    DWORD PTR [ebp-0x14],esi
0x4def60   e844213b00                         call   0x8910a9
0x4def65   68a857c800                         push   0xc857a8
0x4def6a   8d4dd0                             lea    ecx,[ebp-0x30]
0x4def6d   51                                 push   ecx
0x4def6e   c745d0a42cbd00                     mov    DWORD PTR [ebp-0x30],0xbd2ca4
0x4def75   e876da3b00                         call   0x89c9f0
0x4def7a   8d55f0                             lea    edx,[ebp-0x10]
0x4def7d   52                                 push   edx
0x4def7e   8d4ddc                             lea    ecx,[ebp-0x24]
0x4def81   8975f0                             mov    DWORD PTR [ebp-0x10],esi
0x4def84   e820213b00                         call   0x8910a9
0x4def89   68a857c800                         push   0xc857a8
0x4def8e   8d45dc                             lea    eax,[ebp-0x24]
0x4def91   50                                 push   eax
0x4def92   c745dca42cbd00                     mov    DWORD PTR [ebp-0x24],0xbd2ca4
0x4def99   e852da3b00                         call   0x89c9f0
0x4def9e   8d4dec                             lea    ecx,[ebp-0x14]
0x4defa1   51                                 push   ecx
0x4defa2   8d4dd0                             lea    ecx,[ebp-0x30]
0x4defa5   8975ec                             mov    DWORD PTR [ebp-0x14],esi
0x4defa8   e8fc203b00                         call   0x8910a9
0x4defad   68a857c800                         push   0xc857a8
0x4defb2   8d55d0                             lea    edx,[ebp-0x30]
0x4defb5   52                                 push   edx
0x4defb6   c745d0a42cbd00                     mov    DWORD PTR [ebp-0x30],0xbd2ca4
0x4defbd   e82eda3b00                         call   0x89c9f0

; disable_world_render [0x5647a0,0x56480e) raw=0x163ba0 sha256=bc71845114e97a758b91a6072352730b6ce608b158c8fa2cea09dd454db294d4 Set FAB1D8
0x5647a0   55                                 push   ebp
0x5647a1   8bec                               mov    ebp,esp
0x5647a3   83e4f8                             and    esp,0xfffffff8
0x5647a6   6aff                               push   0xffffffff
0x5647a8   68fe6e9300                         push   0x936efe
0x5647ad   64a100000000                       mov    eax,fs:0x0
0x5647b3   50                                 push   eax
0x5647b4   83ec08                             sub    esp,0x8
0x5647b7   53                                 push   ebx
0x5647b8   a1201fd600                         mov    eax,ds:0xd61f20
0x5647bd   33c4                               xor    eax,esp
0x5647bf   50                                 push   eax
0x5647c0   8d442410                           lea    eax,[esp+0x10]
0x5647c4   64a300000000                       mov    fs:0x0,eax
0x5647ca   bb01000000                         mov    ebx,0x1
0x5647cf   841d2cb2fa00                       test   BYTE PTR ds:0xfab22c,bl
0x5647d5   7520                               jne    0x5647f7
0x5647d7   091d2cb2fa00                       or     DWORD PTR ds:0xfab22c,ebx
0x5647dd   c744241800000000                   mov    DWORD PTR [esp+0x18],0x0
0x5647e5   e8a6a4f7ff                         call   0x4dec90
0x5647ea   6830cebc00                         push   0xbcce30
0x5647ef   e826db3200                         call   0x89231a
0x5647f4   83c404                             add    esp,0x4
0x5647f7   891dd8b1fa00                       mov    DWORD PTR ds:0xfab1d8,ebx
0x5647fd   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x564801   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x564808   59                                 pop    ecx
0x564809   5b                                 pop    ebx
0x56480a   8be5                               mov    esp,ebp
0x56480c   5d                                 pop    ebp
0x56480d   c3                                 ret

; enable_world_render [0x564810,0x56487e) raw=0x163c10 sha256=da0013a31c64f384279b5e00d0d6b315cf62b63084a909decc35621caa258e2b Clear FAB1D8; ends BEFORE independent 564880
0x564810   55                                 push   ebp
0x564811   8bec                               mov    ebp,esp
0x564813   83e4f8                             and    esp,0xfffffff8
0x564816   6aff                               push   0xffffffff
0x564818   68ee619400                         push   0x9461ee
0x56481d   64a100000000                       mov    eax,fs:0x0
0x564823   50                                 push   eax
0x564824   51                                 push   ecx
0x564825   a1201fd600                         mov    eax,ds:0xd61f20
0x56482a   33c4                               xor    eax,esp
0x56482c   50                                 push   eax
0x56482d   8d442408                           lea    eax,[esp+0x8]
0x564831   64a300000000                       mov    fs:0x0,eax
0x564837   b801000000                         mov    eax,0x1
0x56483c   84052cb2fa00                       test   BYTE PTR ds:0xfab22c,al
0x564842   7520                               jne    0x564864
0x564844   09052cb2fa00                       or     DWORD PTR ds:0xfab22c,eax
0x56484a   c744241000000000                   mov    DWORD PTR [esp+0x10],0x0
0x564852   e839a4f7ff                         call   0x4dec90
0x564857   6830cebc00                         push   0xbcce30
0x56485c   e8b9da3200                         call   0x89231a
0x564861   83c404                             add    esp,0x4
0x564864   c705d8b1fa0000000000               mov    DWORD PTR ds:0xfab1d8,0x0
0x56486e   8b4c2408                           mov    ecx,DWORD PTR [esp+0x8]
0x564872   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x564879   59                                 pop    ecx
0x56487a   8be5                               mov    esp,ebp
0x56487c   5d                                 pop    ebp
0x56487d   c3                                 ret

; world_render [0x4e0540,0x4e0584) raw=0xdf940 sha256=2e691defaa08ebf342d5643f214d6a06400ca3d9fc3c40bed0cf426b34654d15 World +A8 controls selected controller/world actor rendering
0x4e0540   55                                 push   ebp
0x4e0541   8bec                               mov    ebp,esp
0x4e0543   51                                 push   ecx
0x4e0544   8b0d38a8fb00                       mov    ecx,DWORD PTR ds:0xfba838
0x4e054a   8b01                               mov    eax,DWORD PTR [ecx]
0x4e054c   8b501c                             mov    edx,DWORD PTR [eax+0x1c]
0x4e054f   ffd2                               call   edx
0x4e0551   83bea800000000                     cmp    DWORD PTR [esi+0xa8],0x0
0x4e0558   7524                               jne    0x4e057e
0x4e055a   8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
0x4e0560   8b01                               mov    eax,DWORD PTR [ecx]
0x4e0562   8b5034                             mov    edx,DWORD PTR [eax+0x34]
0x4e0565   ffd2                               call   edx
0x4e0567   8b460c                             mov    eax,DWORD PTR [esi+0xc]
0x4e056a   8b08                               mov    ecx,DWORD PTR [eax]
0x4e056c   c645fc00                           mov    BYTE PTR [ebp-0x4],0x0
0x4e0570   8b55fc                             mov    edx,DWORD PTR [ebp-0x4]
0x4e0573   52                                 push   edx
0x4e0574   50                                 push   eax
0x4e0575   51                                 push   ecx
0x4e0576   e8f50e0000                         call   0x4e1470
0x4e057b   83c40c                             add    esp,0xc
0x4e057e   33c0                               xor    eax,eax
0x4e0580   8be5                               mov    esp,ebp
0x4e0582   5d                                 pop    ebp
0x4e0583   c3                                 ret

; world_render_tree [0x4e1470,0x4e14e2) raw=0xe0870 sha256=d2b3aa4d9596761bc7b364c2675b75e1aa920778089ef2aa23b3cf4d6b7c9eec Recursive node+0x10 actor virtual +0x28 rendering
0x4e1470   55                                 push   ebp
0x4e1471   8bec                               mov    ebp,esp
0x4e1473   8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
0x4e1476   3b4d0c                             cmp    ecx,DWORD PTR [ebp+0xc]
0x4e1479   7462                               je     0x4e14dd
0x4e147b   eb03                               jmp    0x4e1480
0x4e147d   8d4900                             lea    ecx,[ecx+0x0]
0x4e1480   8b4910                             mov    ecx,DWORD PTR [ecx+0x10]
0x4e1483   8b01                               mov    eax,DWORD PTR [ecx]
0x4e1485   8b5028                             mov    edx,DWORD PTR [eax+0x28]
0x4e1488   ffd2                               call   edx
0x4e148a   8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
0x4e148d   80791500                           cmp    BYTE PTR [ecx+0x15],0x0
0x4e1491   7545                               jne    0x4e14d8
0x4e1493   8b4108                             mov    eax,DWORD PTR [ecx+0x8]
0x4e1496   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e149a   7516                               jne    0x4e14b2
0x4e149c   8bc8                               mov    ecx,eax
0x4e149e   8b01                               mov    eax,DWORD PTR [ecx]
0x4e14a0   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e14a4   752f                               jne    0x4e14d5
0x4e14a6   8bc8                               mov    ecx,eax
0x4e14a8   8b01                               mov    eax,DWORD PTR [ecx]
0x4e14aa   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e14ae   74f6                               je     0x4e14a6
0x4e14b0   eb23                               jmp    0x4e14d5
0x4e14b2   8b4104                             mov    eax,DWORD PTR [ecx+0x4]
0x4e14b5   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e14b9   7518                               jne    0x4e14d3
0x4e14bb   eb03                               jmp    0x4e14c0
0x4e14bd   8d4900                             lea    ecx,[ecx+0x0]
0x4e14c0   3b4808                             cmp    ecx,DWORD PTR [eax+0x8]
0x4e14c3   750e                               jne    0x4e14d3
0x4e14c5   8bc8                               mov    ecx,eax
0x4e14c7   894d08                             mov    DWORD PTR [ebp+0x8],ecx
0x4e14ca   8b4004                             mov    eax,DWORD PTR [eax+0x4]
0x4e14cd   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e14d1   74ed                               je     0x4e14c0
0x4e14d3   8bc8                               mov    ecx,eax
0x4e14d5   894d08                             mov    DWORD PTR [ebp+0x8],ecx
0x4e14d8   3b4d0c                             cmp    ecx,DWORD PTR [ebp+0xc]
0x4e14db   75a3                               jne    0x4e1480
0x4e14dd   8a4510                             mov    al,BYTE PTR [ebp+0x10]
0x4e14e0   5d                                 pop    ebp
0x4e14e1   c3                                 ret

; world_render_caller [0x492b0e,0x492b25) raw=0x91f0e sha256=7c99703e6c06afbfa99c72e2bb308fee5fdd039df65ed25e10b084c9c52715fc Main render obtains actual singleton receiver
0x492b0e   68ec76fb00                         push   0xfb76ec
0x492b13   ff154c22bd00                       call   DWORD PTR ds:0xbd224c
0x492b19   e842c5f7ff                         call   0x40f060
0x492b1e   8bf0                               mov    esi,eax
0x492b20   e81bda0400                         call   0x4e0540

; world_animation [0x4e0200,0x4e051c) raw=0xdf600 sha256=dd92867357a58ccb569987dedf51146fe5efae3aaade9c76e8e982a0d516ab0d Selected actor animation scaled to 0.2 by +AC or +B0
0x4e0200   55                                 push   ebp
0x4e0201   8bec                               mov    ebp,esp
0x4e0203   6aff                               push   0xffffffff
0x4e0205   68c4439400                         push   0x9443c4
0x4e020a   64a100000000                       mov    eax,fs:0x0
0x4e0210   50                                 push   eax
0x4e0211   83ec0c                             sub    esp,0xc
0x4e0214   53                                 push   ebx
0x4e0215   56                                 push   esi
0x4e0216   57                                 push   edi
0x4e0217   a1201fd600                         mov    eax,ds:0xd61f20
0x4e021c   33c5                               xor    eax,ebp
0x4e021e   50                                 push   eax
0x4e021f   8d45f4                             lea    eax,[ebp-0xc]
0x4e0222   64a300000000                       mov    fs:0x0,eax
0x4e0228   f605600ffc0001                     test   BYTE PTR ds:0xfc0f60,0x1
0x4e022f   be01000000                         mov    esi,0x1
0x4e0234   7527                               jne    0x4e025d
0x4e0236   0935600ffc00                       or     DWORD PTR ds:0xfc0f60,esi
0x4e023c   c745fc00000000                     mov    DWORD PTR [ebp-0x4],0x0
0x4e0243   e8f8cc2b00                         call   0x79cf40
0x4e0248   6880dbbc00                         push   0xbcdb80
0x4e024d   e8c8203b00                         call   0x89231a
0x4e0252   83c404                             add    esp,0x4
0x4e0255   83cfff                             or     edi,0xffffffff
0x4e0258   897dfc                             mov    DWORD PTR [ebp-0x4],edi
0x4e025b   eb03                               jmp    0x4e0260
0x4e025d   83cfff                             or     edi,0xffffffff
0x4e0260   b9900efc00                         mov    ecx,0xfc0e90
0x4e0265   e8a6d82b00                         call   0x79db10
0x4e026a   d9450c                             fld    DWORD PTR [ebp+0xc]
0x4e026d   8b0d38a8fb00                       mov    ecx,DWORD PTR ds:0xfba838
0x4e0273   8b01                               mov    eax,DWORD PTR [ecx]
0x4e0275   8b5018                             mov    edx,DWORD PTR [eax+0x18]
0x4e0278   51                                 push   ecx
0x4e0279   d91c24                             fstp   DWORD PTR [esp]
0x4e027c   ffd2                               call   edx
0x4e027e   f30f10450c                         movss  xmm0,DWORD PTR [ebp+0xc]
0x4e0283   8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
0x4e0286   0f57c9                             xorps  xmm1,xmm1
0x4e0289   f30f1145f0                         movss  DWORD PTR [ebp-0x10],xmm0
0x4e028e   f30f1083ac000000                   movss  xmm0,DWORD PTR [ebx+0xac]
0x4e0296   0f2fc1                             comiss xmm0,xmm1
0x4e0299   f30f1145ec                         movss  DWORD PTR [ebp-0x14],xmm0
0x4e029e   7709                               ja     0x4e02a9
0x4e02a0   83bbb000000000                     cmp    DWORD PTR [ebx+0xb0],0x0
0x4e02a7   742d                               je     0x4e02d6
0x4e02a9   d9450c                             fld    DWORD PTR [ebp+0xc]
0x4e02ac   dd059058c500                       fld    QWORD PTR ds:0xc55890
0x4e02b2   d8c9                               fmul   st,st(1)
0x4e02b4   d95df0                             fstp   DWORD PTR [ebp-0x10]
0x4e02b7   d86dec                             fsubr  DWORD PTR [ebp-0x14]
0x4e02ba   d95dec                             fstp   DWORD PTR [ebp-0x14]
0x4e02bd   d945ec                             fld    DWORD PTR [ebp-0x14]
0x4e02c0   d993ac000000                       fst    DWORD PTR [ebx+0xac]
0x4e02c6   d9ee                               fldz
0x4e02c8   dff1                               fcomip st,st(1)
0x4e02ca   ddd8                               fstp   st(0)
0x4e02cc   7208                               jb     0x4e02d6
0x4e02ce   f30f118bac000000                   movss  DWORD PTR [ebx+0xac],xmm1
0x4e02d6   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x4e02dd   f30f1045f0                         movss  xmm0,DWORD PTR [ebp-0x10]
0x4e02e2   c745e82ccfc000                     mov    DWORD PTR [ebp-0x18],0xc0cf2c
0x4e02e9   f30f1145ec                         movss  DWORD PTR [ebp-0x14],xmm0
0x4e02ee   751e                               jne    0x4e030e
0x4e02f0   0935e879fb00                       or     DWORD PTR ds:0xfb79e8,esi
0x4e02f6   8975fc                             mov    DWORD PTR [ebp-0x4],esi
0x4e02f9   e8e28a2b00                         call   0x798de0
0x4e02fe   68e0d2bc00                         push   0xbcd2e0
0x4e0303   e812203b00                         call   0x89231a
0x4e0308   83c404                             add    esp,0x4
0x4e030b   897dfc                             mov    DWORD PTR [ebp-0x4],edi
0x4e030e   8d45e8                             lea    eax,[ebp-0x18]
0x4e0311   a3e479fb00                         mov    ds:0xfb79e4,eax
0x4e0316   8b430c                             mov    eax,DWORD PTR [ebx+0xc]
0x4e0319   8b30                               mov    esi,DWORD PTR [eax]
0x4e031b   3bf0                               cmp    esi,eax
0x4e031d   0f84ed000000                       je     0x4e0410
0x4e0323   bb02000000                         mov    ebx,0x2
0x4e0328   eb06                               jmp    0x4e0330
0x4e032a   8d9b00000000                       lea    ebx,[ebx+0x0]
0x4e0330   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x4e0337   751f                               jne    0x4e0358
0x4e0339   830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
0x4e0340   895dfc                             mov    DWORD PTR [ebp-0x4],ebx
0x4e0343   e8988a2b00                         call   0x798de0
0x4e0348   68e0d2bc00                         push   0xbcd2e0
0x4e034d   e8c81f3b00                         call   0x89231a
0x4e0352   83c404                             add    esp,0x4
0x4e0355   897dfc                             mov    DWORD PTR [ebp-0x4],edi
0x4e0358   8b0de079fb00                       mov    ecx,DWORD PTR ds:0xfb79e0
0x4e035e   8b4610                             mov    eax,DWORD PTR [esi+0x10]
0x4e0361   8b15d079fb00                       mov    edx,DWORD PTR ds:0xfb79d0
0x4e0367   8d0c49                             lea    ecx,[ecx+ecx*2]
0x4e036a   89448a08                           mov    DWORD PTR [edx+ecx*4+0x8],eax
0x4e036e   a1e079fb00                         mov    eax,ds:0xfb79e0
0x4e0373   0fb60dad79fb00                     movzx  ecx,BYTE PTR ds:0xfb79ad
0x4e037a   40                                 inc    eax
0x4e037b   a3e079fb00                         mov    ds:0xfb79e0,eax
0x4e0380   3bc1                               cmp    eax,ecx
0x4e0382   7539                               jne    0x4e03bd
0x4e0384   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x4e038b   7523                               jne    0x4e03b0
0x4e038d   830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
0x4e0394   c745fc03000000                     mov    DWORD PTR [ebp-0x4],0x3
0x4e039b   e8408a2b00                         call   0x798de0
0x4e03a0   68e0d2bc00                         push   0xbcd2e0
0x4e03a5   e8701f3b00                         call   0x89231a
0x4e03aa   83c404                             add    esp,0x4
0x4e03ad   897dfc                             mov    DWORD PTR [ebp-0x4],edi
0x4e03b0   bfac79fb00                         mov    edi,0xfb79ac
0x4e03b5   e836e12000                         call   0x6ee4f0
0x4e03ba   83cfff                             or     edi,0xffffffff
0x4e03bd   807e1500                           cmp    BYTE PTR [esi+0x15],0x0
0x4e03c1   753f                               jne    0x4e0402
0x4e03c3   8b4608                             mov    eax,DWORD PTR [esi+0x8]
0x4e03c6   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e03ca   7516                               jne    0x4e03e2
0x4e03cc   8bf0                               mov    esi,eax
0x4e03ce   8b06                               mov    eax,DWORD PTR [esi]
0x4e03d0   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e03d4   752c                               jne    0x4e0402
0x4e03d6   8bf0                               mov    esi,eax
0x4e03d8   8b06                               mov    eax,DWORD PTR [esi]
0x4e03da   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e03de   74f6                               je     0x4e03d6
0x4e03e0   eb20                               jmp    0x4e0402
0x4e03e2   8b4604                             mov    eax,DWORD PTR [esi+0x4]
0x4e03e5   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e03e9   7515                               jne    0x4e0400
0x4e03eb   eb03                               jmp    0x4e03f0
0x4e03ed   8d4900                             lea    ecx,[ecx+0x0]
0x4e03f0   3b7008                             cmp    esi,DWORD PTR [eax+0x8]
0x4e03f3   750b                               jne    0x4e0400
0x4e03f5   8bf0                               mov    esi,eax
0x4e03f7   8b4004                             mov    eax,DWORD PTR [eax+0x4]
0x4e03fa   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x4e03fe   74f0                               je     0x4e03f0
0x4e0400   8bf0                               mov    esi,eax
0x4e0402   8b5508                             mov    edx,DWORD PTR [ebp+0x8]
0x4e0405   3b720c                             cmp    esi,DWORD PTR [edx+0xc]
0x4e0408   0f8522ffffff                       jne    0x4e0330
0x4e040e   8bda                               mov    ebx,edx
0x4e0410   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x4e0417   7523                               jne    0x4e043c
0x4e0419   830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
0x4e0420   c745fc04000000                     mov    DWORD PTR [ebp-0x4],0x4
0x4e0427   e8b4892b00                         call   0x798de0
0x4e042c   68e0d2bc00                         push   0xbcd2e0
0x4e0431   e8e41e3b00                         call   0x89231a
0x4e0436   83c404                             add    esp,0x4
0x4e0439   897dfc                             mov    DWORD PTR [ebp-0x4],edi
0x4e043c   a1e079fb00                         mov    eax,ds:0xfb79e0
0x4e0441   85c0                               test   eax,eax
0x4e0443   7438                               je     0x4e047d
0x4e0445   33f6                               xor    esi,esi
0x4e0447   85c0                               test   eax,eax
0x4e0449   7421                               je     0x4e046c
0x4e044b   8b3dd020bd00                       mov    edi,DWORD PTR ds:0xbd20d0
0x4e0451   a1b079fb00                         mov    eax,ds:0xfb79b0
0x4e0456   8b0cb0                             mov    ecx,DWORD PTR [eax+esi*4]
0x4e0459   51                                 push   ecx
0x4e045a   ffd7                               call   edi
0x4e045c   a1e079fb00                         mov    eax,ds:0xfb79e0
0x4e0461   46                                 inc    esi
0x4e0462   3bf0                               cmp    esi,eax
0x4e0464   72eb                               jb     0x4e0451
0x4e0466   8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
0x4e0469   83cfff                             or     edi,0xffffffff
0x4e046c   8b15c079fb00                       mov    edx,DWORD PTR ds:0xfb79c0
0x4e0472   57                                 push   edi
0x4e0473   6a01                               push   0x1
0x4e0475   52                                 push   edx
0x4e0476   50                                 push   eax
0x4e0477   ff15b422bd00                       call   DWORD PTR ds:0xbd22b4
0x4e047d   33c0                               xor    eax,eax
0x4e047f   f60500b1fa0001                     test   BYTE PTR ds:0xfab100,0x1
0x4e0486   a3e079fb00                         mov    ds:0xfb79e0,eax
0x4e048b   a3e479fb00                         mov    ds:0xfb79e4,eax
0x4e0490   7523                               jne    0x4e04b5
0x4e0492   830d00b1fa0001                     or     DWORD PTR ds:0xfab100,0x1
0x4e0499   c745fc05000000                     mov    DWORD PTR [ebp-0x4],0x5
0x4e04a0   e8fbd1fbff                         call   0x49d6a0
0x4e04a5   6820cebc00                         push   0xbcce20
0x4e04aa   e86b1e3b00                         call   0x89231a
0x4e04af   83c404                             add    esp,0x4
0x4e04b2   897dfc                             mov    DWORD PTR [ebp-0x4],edi
0x4e04b5   8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
0x4e04bb   8b01                               mov    eax,DWORD PTR [ecx]
0x4e04bd   8b5020                             mov    edx,DWORD PTR [eax+0x20]
0x4e04c0   ffd2                               call   edx
0x4e04c2   85c0                               test   eax,eax
0x4e04c4   742c                               je     0x4e04f2
0x4e04c6   a1a4a7fb00                         mov    eax,ds:0xfba7a4
0x4e04cb   83787c00                           cmp    DWORD PTR [eax+0x7c],0x0
0x4e04cf   7521                               jne    0x4e04f2
0x4e04d1   a11813fb00                         mov    eax,ds:0xfb1318
0x4e04d6   8b881cc00000                       mov    ecx,DWORD PTR [eax+0xc01c]
0x4e04dc   d1e9                               shr    ecx,1
0x4e04de   f6c101                             test   cl,0x1
0x4e04e1   750f                               jne    0x4e04f2
0x4e04e3   f6801cc0000001                     test   BYTE PTR [eax+0xc01c],0x1
0x4e04ea   7506                               jne    0x4e04f2
0x4e04ec   53                                 push   ebx
0x4e04ed   e8de010000                         call   0x4e06d0
0x4e04f2   8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
0x4e04f8   d9450c                             fld    DWORD PTR [ebp+0xc]
0x4e04fb   8b11                               mov    edx,DWORD PTR [ecx]
0x4e04fd   8b4230                             mov    eax,DWORD PTR [edx+0x30]
0x4e0500   51                                 push   ecx
0x4e0501   d91c24                             fstp   DWORD PTR [esp]
0x4e0504   ffd0                               call   eax
0x4e0506   33c0                               xor    eax,eax
0x4e0508   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x4e050b   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x4e0512   59                                 pop    ecx
0x4e0513   5f                                 pop    edi
0x4e0514   5e                                 pop    esi
0x4e0515   5b                                 pop    ebx
0x4e0516   8be5                               mov    esp,ebp
0x4e0518   5d                                 pop    ebp
0x4e0519   c20800                             ret    0x8

; world_animation_worker [0x4e0520,0x4e053f) raw=0xdf920 sha256=334b4577534d7d1aa76734352c50067b2082fa72f977b3acb02bc2295acce30e Store scaled float and invoke actor virtual +0x24
0x4e0520   55                                 push   ebp
0x4e0521   8bec                               mov    ebp,esp
0x4e0523   8bc1                               mov    eax,ecx
0x4e0525   8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
0x4e0528   d94004                             fld    DWORD PTR [eax+0x4]
0x4e052b   8b11                               mov    edx,DWORD PTR [ecx]
0x4e052d   8b4224                             mov    eax,DWORD PTR [edx+0x24]
0x4e0530   51                                 push   ecx
0x4e0531   d91c24                             fstp   DWORD PTR [esp]
0x4e0534   ffd0                               call   eax
0x4e0536   b801000000                         mov    eax,0x1
0x4e053b   5d                                 pop    ebp
0x4e053c   c20400                             ret    0x4

; world_animation_caller [0x492599,0x4925aa) raw=0x91999 sha256=a46a2817e1949a8c368f1da8fde4b57ab5a190c99d776fdcfb6755b3be76378c Main animation passes FAB130 and original delta
0x492599   d9450c                             fld    DWORD PTR [ebp+0xc]
0x49259c   51                                 push   ecx
0x49259d   d91c24                             fstp   DWORD PTR [esp]
0x4925a0   6830b1fa00                         push   0xfab130
0x4925a5   e856dc0400                         call   0x4e0200

; world_input_owner [0x4e0060,0x4e01fb) raw=0xdf460 sha256=11258b3a6d17136989de053c38afad00e270cf482d6ed0d0977807e6552398f3 Independent positive +AC can set controller +0x58
0x4e0060   55                                 push   ebp
0x4e0061   8bec                               mov    ebp,esp
0x4e0063   6aff                               push   0xffffffff
0x4e0065   68bab19300                         push   0x93b1ba
0x4e006a   64a100000000                       mov    eax,fs:0x0
0x4e0070   50                                 push   eax
0x4e0071   83ec20                             sub    esp,0x20
0x4e0074   a1201fd600                         mov    eax,ds:0xd61f20
0x4e0079   33c5                               xor    eax,ebp
0x4e007b   8945f0                             mov    DWORD PTR [ebp-0x10],eax
0x4e007e   56                                 push   esi
0x4e007f   57                                 push   edi
0x4e0080   50                                 push   eax
0x4e0081   8d45f4                             lea    eax,[ebp-0xc]
0x4e0084   64a300000000                       mov    fs:0x0,eax
0x4e008a   8bf9                               mov    edi,ecx
0x4e008c   f30f1087ac000000                   movss  xmm0,DWORD PTR [edi+0xac]
0x4e0094   0f2f056c56c500                     comiss xmm0,DWORD PTR ds:0xc5566c
0x4e009b   8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
0x4e00a1   be01000000                         mov    esi,0x1
0x4e00a6   7603                               jbe    0x4e00ab
0x4e00a8   897158                             mov    DWORD PTR [ecx+0x58],esi
0x4e00ab   8b01                               mov    eax,DWORD PTR [ecx]
0x4e00ad   8b502c                             mov    edx,DWORD PTR [eax+0x2c]
0x4e00b0   ffd2                               call   edx
0x4e00b2   8b470c                             mov    eax,DWORD PTR [edi+0xc]
0x4e00b5   8b08                               mov    ecx,DWORD PTR [eax]
0x4e00b7   c645d400                           mov    BYTE PTR [ebp-0x2c],0x0
0x4e00bb   8b55d4                             mov    edx,DWORD PTR [ebp-0x2c]
0x4e00be   52                                 push   edx
0x4e00bf   50                                 push   eax
0x4e00c0   51                                 push   ecx
0x4e00c1   e82a130000                         call   0x4e13f0
0x4e00c6   83c40c                             add    esp,0xc
0x4e00c9   f605b873fb0001                     test   BYTE PTR ds:0xfb73b8,0x1
0x4e00d0   7526                               jne    0x4e00f8
0x4e00d2   0935b873fb00                       or     DWORD PTR ds:0xfb73b8,esi
0x4e00d8   c745fc00000000                     mov    DWORD PTR [ebp-0x4],0x0
0x4e00df   e88c000800                         call   0x560170
0x4e00e4   6810d1bc00                         push   0xbcd110
0x4e00e9   e82c223b00                         call   0x89231a
0x4e00ee   83c404                             add    esp,0x4
0x4e00f1   c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e00f8   833de873fb0000                     cmp    DWORD PTR ds:0xfb73e8,0x0
0x4e00ff   0f84cd000000                       je     0x4e01d2
0x4e0105   f605d4b0fa0001                     test   BYTE PTR ds:0xfab0d4,0x1
0x4e010c   7522                               jne    0x4e0130
0x4e010e   0935d4b0fa00                       or     DWORD PTR ds:0xfab0d4,esi
0x4e0114   8975fc                             mov    DWORD PTR [ebp-0x4],esi
0x4e0117   e884a23200                         call   0x80a3a0
0x4e011c   68d0cdbc00                         push   0xbccdd0
0x4e0121   e8f4213b00                         call   0x89231a
0x4e0126   83c404                             add    esp,0x4
0x4e0129   c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e0130   833d90b0fa0000                     cmp    DWORD PTR ds:0xfab090,0x0
0x4e0137   7521                               jne    0x4e015a
0x4e0139   8b0d28b0fa00                       mov    ecx,DWORD PTR ds:0xfab028
0x4e013f   85c9                               test   ecx,ecx
0x4e0141   7417                               je     0x4e015a
0x4e0143   8b01                               mov    eax,DWORD PTR [ecx]
0x4e0145   8b5020                             mov    edx,DWORD PTR [eax+0x20]
0x4e0148   ffd2                               call   edx
0x4e014a   a390b0fa00                         mov    ds:0xfab090,eax
0x4e014f   8b10                               mov    edx,DWORD PTR [eax]
0x4e0151   8bc8                               mov    ecx,eax
0x4e0153   8b4218                             mov    eax,DWORD PTR [edx+0x18]
0x4e0156   6a03                               push   0x3
0x4e0158   ffd0                               call   eax
0x4e015a   f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0x4e0161   8b3590b0fa00                       mov    esi,DWORD PTR ds:0xfab090
0x4e0167   7527                               jne    0x4e0190
0x4e0169   830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
0x4e0170   c745fc02000000                     mov    DWORD PTR [ebp-0x4],0x2
0x4e0177   e8648c2b00                         call   0x798de0
0x4e017c   68e0d2bc00                         push   0xbcd2e0
0x4e0181   e894213b00                         call   0x89231a
0x4e0186   83c404                             add    esp,0x4
0x4e0189   c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e0190   a1e876fb00                         mov    eax,ds:0xfb76e8
0x4e0195   8b480c                             mov    ecx,DWORD PTR [eax+0xc]
0x4e0198   8b5010                             mov    edx,DWORD PTR [eax+0x10]
0x4e019b   8b4014                             mov    eax,DWORD PTR [eax+0x14]
0x4e019e   894dd8                             mov    DWORD PTR [ebp-0x28],ecx
0x4e01a1   d945d8                             fld    DWORD PTR [ebp-0x28]
0x4e01a4   dd059858c500                       fld    QWORD PTR ds:0xc55898
0x4e01aa   8955dc                             mov    DWORD PTR [ebp-0x24],edx
0x4e01ad   dcc9                               fmul   st(1),st
0x4e01af   8945e0                             mov    DWORD PTR [ebp-0x20],eax
0x4e01b2   d9c9                               fxch   st(1)
0x4e01b4   8d45e4                             lea    eax,[ebp-0x1c]
0x4e01b7   50                                 push   eax
0x4e01b8   d95de4                             fstp   DWORD PTR [ebp-0x1c]
0x4e01bb   8bce                               mov    ecx,esi
0x4e01bd   d945dc                             fld    DWORD PTR [ebp-0x24]
0x4e01c0   d8c9                               fmul   st,st(1)
0x4e01c2   d95de8                             fstp   DWORD PTR [ebp-0x18]
0x4e01c5   d84de0                             fmul   DWORD PTR [ebp-0x20]
0x4e01c8   d95dec                             fstp   DWORD PTR [ebp-0x14]
0x4e01cb   8b16                               mov    edx,DWORD PTR [esi]
0x4e01cd   8b520c                             mov    edx,DWORD PTR [edx+0xc]
0x4e01d0   ffd2                               call   edx
0x4e01d2   81c7d0000000                       add    edi,0xd0
0x4e01d8   57                                 push   edi
0x4e01d9   e8f26c1f00                         call   0x6d6ed0
0x4e01de   33c0                               xor    eax,eax
0x4e01e0   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x4e01e3   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x4e01ea   59                                 pop    ecx
0x4e01eb   5f                                 pop    edi
0x4e01ec   5e                                 pop    esi
0x4e01ed   8b4df0                             mov    ecx,DWORD PTR [ebp-0x10]
0x4e01f0   33cd                               xor    ecx,ebp
0x4e01f2   e80a0e3b00                         call   0x891001
0x4e01f7   8be5                               mov    esp,ebp
0x4e01f9   5d                                 pop    ebp
0x4e01fa   c3                                 ret

; start_slow_motion [0x565640,0x5656ae) raw=0x164a40 sha256=1f5156a4dd09117334bf7b7b89ca48c0f4e871974abac847d142cceffa60e306 Set FAB1E0
0x565640   55                                 push   ebp
0x565641   8bec                               mov    ebp,esp
0x565643   83e4f8                             and    esp,0xfffffff8
0x565646   6aff                               push   0xffffffff
0x565648   68fe6e9300                         push   0x936efe
0x56564d   64a100000000                       mov    eax,fs:0x0
0x565653   50                                 push   eax
0x565654   83ec08                             sub    esp,0x8
0x565657   53                                 push   ebx
0x565658   a1201fd600                         mov    eax,ds:0xd61f20
0x56565d   33c4                               xor    eax,esp
0x56565f   50                                 push   eax
0x565660   8d442410                           lea    eax,[esp+0x10]
0x565664   64a300000000                       mov    fs:0x0,eax
0x56566a   bb01000000                         mov    ebx,0x1
0x56566f   841d2cb2fa00                       test   BYTE PTR ds:0xfab22c,bl
0x565675   7520                               jne    0x565697
0x565677   091d2cb2fa00                       or     DWORD PTR ds:0xfab22c,ebx
0x56567d   c744241800000000                   mov    DWORD PTR [esp+0x18],0x0
0x565685   e80696f7ff                         call   0x4dec90
0x56568a   6830cebc00                         push   0xbcce30
0x56568f   e886cc3200                         call   0x89231a
0x565694   83c404                             add    esp,0x4
0x565697   891de0b1fa00                       mov    DWORD PTR ds:0xfab1e0,ebx
0x56569d   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x5656a1   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x5656a8   59                                 pop    ecx
0x5656a9   5b                                 pop    ebx
0x5656aa   8be5                               mov    esp,ebp
0x5656ac   5d                                 pop    ebp
0x5656ad   c3                                 ret

; end_slow_motion [0x5656b0,0x56571e) raw=0x164ab0 sha256=c81810dc63aa16b2066cdb7944f1b0d16d7b206dce6a3d1c569b960a10a24c1d Clear FAB1E0 only
0x5656b0   55                                 push   ebp
0x5656b1   8bec                               mov    ebp,esp
0x5656b3   83e4f8                             and    esp,0xfffffff8
0x5656b6   6aff                               push   0xffffffff
0x5656b8   68ee619400                         push   0x9461ee
0x5656bd   64a100000000                       mov    eax,fs:0x0
0x5656c3   50                                 push   eax
0x5656c4   51                                 push   ecx
0x5656c5   a1201fd600                         mov    eax,ds:0xd61f20
0x5656ca   33c4                               xor    eax,esp
0x5656cc   50                                 push   eax
0x5656cd   8d442408                           lea    eax,[esp+0x8]
0x5656d1   64a300000000                       mov    fs:0x0,eax
0x5656d7   b801000000                         mov    eax,0x1
0x5656dc   84052cb2fa00                       test   BYTE PTR ds:0xfab22c,al
0x5656e2   7520                               jne    0x565704
0x5656e4   09052cb2fa00                       or     DWORD PTR ds:0xfab22c,eax
0x5656ea   c744241000000000                   mov    DWORD PTR [esp+0x10],0x0
0x5656f2   e89995f7ff                         call   0x4dec90
0x5656f7   6830cebc00                         push   0xbcce30
0x5656fc   e819cc3200                         call   0x89231a
0x565701   83c404                             add    esp,0x4
0x565704   c705e0b1fa0000000000               mov    DWORD PTR ds:0xfab1e0,0x0
0x56570e   8b4c2408                           mov    ecx,DWORD PTR [esp+0x8]
0x565712   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x565719   59                                 pop    ecx
0x56571a   8be5                               mov    esp,ebp
0x56571c   5d                                 pop    ebp
0x56571d   c3                                 ret

; show_letterbox [0x564b00,0x564b47) raw=0x163f00 sha256=6105d496bcac352bfc080f0f502f983ec54e46edaeaea4e9eb546d2445929779 Set FE36EC owner+0x0c
0x564b00   53                                 push   ebx
0x564b01   bb01000000                         mov    ebx,0x1
0x564b06   841dcc38fe00                       test   BYTE PTR ds:0xfe38cc,bl
0x564b0c   7531                               jne    0x564b3f
0x564b0e   091dcc38fe00                       or     DWORD PTR ds:0xfe38cc,ebx
0x564b14   68d0f2bc00                         push   0xbcf2d0
0x564b19   c705e436fe0000040000               mov    DWORD PTR ds:0xfe36e4,0x400
0x564b23   c705e836fe0000030000               mov    DWORD PTR ds:0xfe36e8,0x300
0x564b2d   c705ec36fe0000000000               mov    DWORD PTR ds:0xfe36ec,0x0
0x564b37   e8ded73200                         call   0x89231a
0x564b3c   83c404                             add    esp,0x4
0x564b3f   891dec36fe00                       mov    DWORD PTR ds:0xfe36ec,ebx
0x564b45   5b                                 pop    ebx
0x564b46   c3                                 ret

; hide_letterbox [0x564b50,0x564b99) raw=0x163f50 sha256=0f368790ff5d427f4b990d09574564f85ef2cdabf4d55f364eaa68a3b2de97ad Clear FE36EC owner+0x0c
0x564b50   b801000000                         mov    eax,0x1
0x564b55   c705ec36fe0000000000               mov    DWORD PTR ds:0xfe36ec,0x0
0x564b5f   8405cc38fe00                       test   BYTE PTR ds:0xfe38cc,al
0x564b65   7531                               jne    0x564b98
0x564b67   0905cc38fe00                       or     DWORD PTR ds:0xfe38cc,eax
0x564b6d   68d0f2bc00                         push   0xbcf2d0
0x564b72   c705e436fe0000040000               mov    DWORD PTR ds:0xfe36e4,0x400
0x564b7c   c705e836fe0000030000               mov    DWORD PTR ds:0xfe36e8,0x300
0x564b86   e88fd73200                         call   0x89231a
0x564b8b   83c404                             add    esp,0x4
0x564b8e   c705ec36fe0000000000               mov    DWORD PTR ds:0xfe36ec,0x0
0x564b98   c3                                 ret

; letterbox_owner [0x55ff70,0x55ffb4) raw=0x15f370 sha256=92ee9157d35a8de7b606465f7a5af85b084621e30d905edc432ee7e12e405f11 Initialize and return FE36E0
0x55ff70   b801000000                         mov    eax,0x1
0x55ff75   8405cc38fe00                       test   BYTE PTR ds:0xfe38cc,al
0x55ff7b   7531                               jne    0x55ffae
0x55ff7d   0905cc38fe00                       or     DWORD PTR ds:0xfe38cc,eax
0x55ff83   68d0f2bc00                         push   0xbcf2d0
0x55ff88   c705e436fe0000040000               mov    DWORD PTR ds:0xfe36e4,0x400
0x55ff92   c705e836fe0000030000               mov    DWORD PTR ds:0xfe36e8,0x300
0x55ff9c   c705ec36fe0000000000               mov    DWORD PTR ds:0xfe36ec,0x0
0x55ffa6   e86f233300                         call   0x89231a
0x55ffab   83c404                             add    esp,0x4
0x55ffae   b8e036fe00                         mov    eax,0xfe36e0
0x55ffb3   c3                                 ret

; letterbox_draw [0x55ecc0,0x55ed55) raw=0x15e0c0 sha256=94fcfb33903cb4dcad01ece1bc34be1ab00ec15f56c32b5557c265cbc5f21dd3 Texture and flag guard then two virtual draws
0x55ecc0   55                                 push   ebp
0x55ecc1   8bec                               mov    ebp,esp
0x55ecc3   8b0e                               mov    ecx,DWORD PTR [esi]
0x55ecc5   83ec08                             sub    esp,0x8
0x55ecc8   85c9                               test   ecx,ecx
0x55ecca   0f8481000000                       je     0x55ed51
0x55ecd0   837e0c00                           cmp    DWORD PTR [esi+0xc],0x0
0x55ecd4   747b                               je     0x55ed51
0x55ecd6   db4604                             fild   DWORD PTR [esi+0x4]
0x55ecd9   f30f1005c056c400                   movss  xmm0,DWORD PTR ds:0xc456c0
0x55ece1   6aff                               push   0xffffffff
0x55ece3   51                                 push   ecx
0x55ece4   dc0de058c500                       fmul   QWORD PTR ds:0xc558e0
0x55ecea   8d55f8                             lea    edx,[ebp-0x8]
0x55eced   f30f1145fc                         movss  DWORD PTR [ebp-0x4],xmm0
0x55ecf2   dc05a056c500                       fadd   QWORD PTR ds:0xc556a0
0x55ecf8   d95df8                             fstp   DWORD PTR [ebp-0x8]
0x55ecfb   8b01                               mov    eax,DWORD PTR [ecx]
0x55ecfd   d9ee                               fldz
0x55ecff   8b4024                             mov    eax,DWORD PTR [eax+0x24]
0x55ed02   d91c24                             fstp   DWORD PTR [esp]
0x55ed05   6a00                               push   0x0
0x55ed07   52                                 push   edx
0x55ed08   6a00                               push   0x0
0x55ed0a   6ae4                               push   0xffffffe4
0x55ed0c   6af0                               push   0xfffffff0
0x55ed0e   ffd0                               call   eax
0x55ed10   db4604                             fild   DWORD PTR [esi+0x4]
0x55ed13   8b0e                               mov    ecx,DWORD PTR [esi]
0x55ed15   f30f1005c056c400                   movss  xmm0,DWORD PTR ds:0xc456c0
0x55ed1d   dc0de058c500                       fmul   QWORD PTR ds:0xc558e0
0x55ed23   6aff                               push   0xffffffff
0x55ed25   51                                 push   ecx
0x55ed26   8d45f8                             lea    eax,[ebp-0x8]
0x55ed29   dc05a056c500                       fadd   QWORD PTR ds:0xc556a0
0x55ed2f   f30f1145fc                         movss  DWORD PTR [ebp-0x4],xmm0
0x55ed34   d95df8                             fstp   DWORD PTR [ebp-0x8]
0x55ed37   8b11                               mov    edx,DWORD PTR [ecx]
0x55ed39   d9ee                               fldz
0x55ed3b   8b5224                             mov    edx,DWORD PTR [edx+0x24]
0x55ed3e   d91c24                             fstp   DWORD PTR [esp]
0x55ed41   6a00                               push   0x0
0x55ed43   50                                 push   eax
0x55ed44   8b4608                             mov    eax,DWORD PTR [esi+0x8]
0x55ed47   6a00                               push   0x0
0x55ed49   83e864                             sub    eax,0x64
0x55ed4c   50                                 push   eax
0x55ed4d   6af0                               push   0xfffffff0
0x55ed4f   ffd2                               call   edx
0x55ed51   8be5                               mov    esp,ebp
0x55ed53   5d                                 pop    ebp
0x55ed54   c3                                 ret

; presentation_draw [0x5646e0,0x564797) raw=0x163ae0 sha256=5b409fd2c045aa2919fdbeae637b1319c4b48f4e945a6d8c2d416998901d6ad0 Actual FE36E0 receiver passed to letterbox draw
0x5646e0   55                                 push   ebp
0x5646e1   8bec                               mov    ebp,esp
0x5646e3   6aff                               push   0xffffffff
0x5646e5   683eac9300                         push   0x93ac3e
0x5646ea   64a100000000                       mov    eax,fs:0x0
0x5646f0   50                                 push   eax
0x5646f1   53                                 push   ebx
0x5646f2   56                                 push   esi
0x5646f3   a1201fd600                         mov    eax,ds:0xd61f20
0x5646f8   33c5                               xor    eax,ebp
0x5646fa   50                                 push   eax
0x5646fb   8d45f4                             lea    eax,[ebp-0xc]
0x5646fe   64a300000000                       mov    fs:0x0,eax
0x564704   bb01000000                         mov    ebx,0x1
0x564709   841dcc38fe00                       test   BYTE PTR ds:0xfe38cc,bl
0x56470f   7531                               jne    0x564742
0x564711   091dcc38fe00                       or     DWORD PTR ds:0xfe38cc,ebx
0x564717   68d0f2bc00                         push   0xbcf2d0
0x56471c   c705e436fe0000040000               mov    DWORD PTR ds:0xfe36e4,0x400
0x564726   c705e836fe0000030000               mov    DWORD PTR ds:0xfe36e8,0x300
0x564730   c705ec36fe0000000000               mov    DWORD PTR ds:0xfe36ec,0x0
0x56473a   e8dbdb3200                         call   0x89231a
0x56473f   83c404                             add    esp,0x4
0x564742   bee036fe00                         mov    esi,0xfe36e0
0x564747   e874a5ffff                         call   0x55ecc0
0x56474c   841d4027fe00                       test   BYTE PTR ds:0xfe2740,bl
0x564752   7526                               jne    0x56477a
0x564754   091d4027fe00                       or     DWORD PTR ds:0xfe2740,ebx
0x56475a   c745fc00000000                     mov    DWORD PTR [ebp-0x4],0x0
0x564761   e81a9fffff                         call   0x55e680
0x564766   68a0f2bc00                         push   0xbcf2a0
0x56476b   e8aadb3200                         call   0x89231a
0x564770   83c404                             add    esp,0x4
0x564773   c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
0x56477a   b84427fe00                         mov    eax,0xfe2744
0x56477f   e86ca0ffff                         call   0x55e7f0
0x564784   33c0                               xor    eax,eax
0x564786   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x564789   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x564790   59                                 pop    ecx
0x564791   5e                                 pop    esi
0x564792   5b                                 pop    ebx
0x564793   8be5                               mov    esp,ebp
0x564795   5d                                 pop    ebp
0x564796   c3                                 ret

; presentation_draw_caller [0x492ee5,0x492ef3) raw=0x922e5 sha256=e0ddee1d069b10b6acdfde73ef996f651d4edcbeb8107fc24055f3c23b14f4ae Main render success branch to presentation draw
0x492ee5   85c0                               test   eax,eax
0x492ee7   7830                               js     0x492f19
0x492ee9   e85200f9ff                         call   0x422f40
0x492eee   e8ed170d00                         call   0x5646e0

; start_sepia [0x5655c0,0x5655f4) raw=0x1649c0 sha256=0daef5839fb83401732092d8d8d1cb774af256d70d273d4dac397b46a3e04799 Set phase1 and converted argument
0x5655c0   55                                 push   ebp
0x5655c1   8bec                               mov    ebp,esp
0x5655c3   b801000000                         mov    eax,0x1
0x5655c8   a3d436fe00                         mov    ds:0xfe36d4,eax
0x5655cd   8405dc36fe00                       test   BYTE PTR ds:0xfe36dc,al
0x5655d3   7512                               jne    0x5655e7
0x5655d5   0905dc36fe00                       or     DWORD PTR ds:0xfe36dc,eax
0x5655db   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x5655de   a3d836fe00                         mov    ds:0xfe36d8,eax
0x5655e3   5d                                 pop    ebp
0x5655e4   c20400                             ret    0x4
0x5655e7   8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
0x5655ea   890dd836fe00                       mov    DWORD PTR ds:0xfe36d8,ecx
0x5655f0   5d                                 pop    ebp
0x5655f1   c20400                             ret    0x4

; end_sepia [0x565600,0x565639) raw=0x164a00 sha256=2b84862b44c871197789e80ba044db2f6d5761b9a80209e74e38fd38e9298a4f Set phase4 and converted argument
0x565600   55                                 push   ebp
0x565601   8bec                               mov    ebp,esp
0x565603   b801000000                         mov    eax,0x1
0x565608   c705d436fe0004000000               mov    DWORD PTR ds:0xfe36d4,0x4
0x565612   8405dc36fe00                       test   BYTE PTR ds:0xfe36dc,al
0x565618   7512                               jne    0x56562c
0x56561a   0905dc36fe00                       or     DWORD PTR ds:0xfe36dc,eax
0x565620   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x565623   a3d836fe00                         mov    ds:0xfe36d8,eax
0x565628   5d                                 pop    ebp
0x565629   c20400                             ret    0x4
0x56562c   8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
0x56562f   890dd836fe00                       mov    DWORD PTR ds:0xfe36d8,ecx
0x565635   5d                                 pop    ebp
0x565636   c20400                             ret    0x4

; end_sepia_closure [0x56a100,0x56a15c) raw=0x169500 sha256=4a847ba10e1d61d57aed0dc3f342946eaeeddb5a11774809c3b957afad7db66b EndSepia uses integer marshaller
0x56a100   55                                 push   ebp
0x56a101   8bec                               mov    ebp,esp
0x56a103   6aff                               push   0xffffffff
0x56a105   68c8839300                         push   0x9383c8
0x56a10a   64a100000000                       mov    eax,fs:0x0
0x56a110   50                                 push   eax
0x56a111   83ec0c                             sub    esp,0xc
0x56a114   a1201fd600                         mov    eax,ds:0xd61f20
0x56a119   33c5                               xor    eax,ebp
0x56a11b   50                                 push   eax
0x56a11c   8d45f4                             lea    eax,[ebp-0xc]
0x56a11f   64a300000000                       mov    fs:0x0,eax
0x56a125   8b4508                             mov    eax,DWORD PTR [ebp+0x8]
0x56a128   8945e8                             mov    DWORD PTR [ebp-0x18],eax
0x56a12b   33c0                               xor    eax,eax
0x56a12d   8945ec                             mov    DWORD PTR [ebp-0x14],eax
0x56a130   8945f0                             mov    DWORD PTR [ebp-0x10],eax
0x56a133   8945fc                             mov    DWORD PTR [ebp-0x4],eax
0x56a136   8b0d6c28fe00                       mov    ecx,DWORD PTR ds:0xfe286c
0x56a13c   51                                 push   ecx
0x56a13d   8d45e8                             lea    eax,[ebp-0x18]
0x56a140   e8eb020000                         call   0x56a430
0x56a145   83c404                             add    esp,0x4
0x56a148   b801000000                         mov    eax,0x1
0x56a14d   8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0x56a150   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x56a157   59                                 pop    ecx
0x56a158   8be5                               mov    esp,ebp
0x56a15a   5d                                 pop    ebp
0x56a15b   c3                                 ret

; integer_marshaller [0x56a430,0x56a4a3) raw=0x169830 sha256=ed9871da5aa7b7fb1b47dd2cdb5602c38d2554a686fe84960f2c53d470fcd479 Number/string conversion, other types -> zero
0x56a430   55                                 push   ebp
0x56a431   8bec                               mov    ebp,esp
0x56a433   8b08                               mov    ecx,DWORD PTR [eax]
0x56a435   83ec18                             sub    esp,0x18
0x56a438   53                                 push   ebx
0x56a439   8b1d7827fe00                       mov    ebx,DWORD PTR ds:0xfe2778
0x56a43f   83c8ff                             or     eax,0xffffffff
0x56a442   e8a9ac1800                         call   0x6f50f0
0x56a447   8b4808                             mov    ecx,DWORD PTR [eax+0x8]
0x56a44a   83f903                             cmp    ecx,0x3
0x56a44d   742a                               je     0x56a479
0x56a44f   83f904                             cmp    ecx,0x4
0x56a452   7540                               jne    0x56a494
0x56a454   56                                 push   esi
0x56a455   8b30                               mov    esi,DWORD PTR [eax]
0x56a457   57                                 push   edi
0x56a458   83c610                             add    esi,0x10
0x56a45b   8d7df8                             lea    edi,[ebp-0x8]
0x56a45e   e8fdd21800                         call   0x6f7760
0x56a463   5f                                 pop    edi
0x56a464   5e                                 pop    esi
0x56a465   85c0                               test   eax,eax
0x56a467   742b                               je     0x56a494
0x56a469   dd45f8                             fld    QWORD PTR [ebp-0x8]
0x56a46c   c745f003000000                     mov    DWORD PTR [ebp-0x10],0x3
0x56a473   dd5de8                             fstp   QWORD PTR [ebp-0x18]
0x56a476   8d45e8                             lea    eax,[ebp-0x18]
0x56a479   dd00                               fld    QWORD PTR [eax]
0x56a47b   dd5df0                             fstp   QWORD PTR [ebp-0x10]
0x56a47e   dd45f0                             fld    QWORD PTR [ebp-0x10]
0x56a481   db5dfc                             fistp  DWORD PTR [ebp-0x4]
0x56a484   8b45fc                             mov    eax,DWORD PTR [ebp-0x4]
0x56a487   50                                 push   eax
0x56a488   8bcb                               mov    ecx,ebx
0x56a48a   ff5508                             call   DWORD PTR [ebp+0x8]
0x56a48d   33c0                               xor    eax,eax
0x56a48f   5b                                 pop    ebx
0x56a490   8be5                               mov    esp,ebp
0x56a492   5d                                 pop    ebp
0x56a493   c3                                 ret
0x56a494   33c0                               xor    eax,eax
0x56a496   50                                 push   eax
0x56a497   8bcb                               mov    ecx,ebx
0x56a499   ff5508                             call   DWORD PTR [ebp+0x8]
0x56a49c   33c0                               xor    eax,eax
0x56a49e   5b                                 pop    ebx
0x56a49f   8be5                               mov    esp,ebp
0x56a4a1   5d                                 pop    ebp
0x56a4a2   c3                                 ret

; sepia_update [0x560090,0x560158) raw=0x15f490 sha256=77c930fbe51ec600ac5bc26f97356366909a2418ab9473a5858af6883db1b718 Phase4 ->5 ->6 ->0; separate native update visits
0x560090   55                                 push   ebp
0x560091   8bec                               mov    ebp,esp
0x560093   51                                 push   ecx
0x560094   53                                 push   ebx
0x560095   8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
0x560098   8b03                               mov    eax,DWORD PTR [ebx]
0x56009a   48                                 dec    eax
0x56009b   83f805                             cmp    eax,0x5
0x56009e   0f87ad000000                       ja     0x560151
0x5600a4   56                                 push   esi
0x5600a5   57                                 push   edi
0x5600a6   ff248558015600                     jmp    DWORD PTR [eax*4+0x560158]
0x5600ad   8b357027fe00                       mov    esi,DWORD PTR ds:0xfe2770
0x5600b3   bf02000000                         mov    edi,0x2
0x5600b8   897e20                             mov    DWORD PTR [esi+0x20],edi
0x5600bb   e860601700                         call   0x6d6120
0x5600c0   a17027fe00                         mov    eax,ds:0xfe2770
0x5600c5   8b4818                             mov    ecx,DWORD PTR [eax+0x18]
0x5600c8   8b11                               mov    edx,DWORD PTR [ecx]
0x5600ca   8b4224                             mov    eax,DWORD PTR [edx+0x24]
0x5600cd   ffd0                               call   eax
0x5600cf   893b                               mov    DWORD PTR [ebx],edi
0x5600d1   5f                                 pop    edi
0x5600d2   5e                                 pop    esi
0x5600d3   5b                                 pop    ebx
0x5600d4   8be5                               mov    esp,ebp
0x5600d6   5d                                 pop    ebp
0x5600d7   c20400                             ret    0x4
0x5600da   8b0d7027fe00                       mov    ecx,DWORD PTR ds:0xfe2770
0x5600e0   8b4118                             mov    eax,DWORD PTR [ecx+0x18]
0x5600e3   83780c02                           cmp    DWORD PTR [eax+0xc],0x2
0x5600e7   750d                               jne    0x5600f6
0x5600e9   f30f1005c056c400                   movss  xmm0,DWORD PTR ds:0xc456c0
0x5600f1   f30f11407c                         movss  DWORD PTR [eax+0x7c],xmm0
0x5600f6   5f                                 pop    edi
0x5600f7   5e                                 pop    esi
0x5600f8   c70303000000                       mov    DWORD PTR [ebx],0x3
0x5600fe   5b                                 pop    ebx
0x5600ff   8be5                               mov    esp,ebp
0x560101   5d                                 pop    ebp
0x560102   c20400                             ret    0x4
0x560105   5f                                 pop    edi
0x560106   5e                                 pop    esi
0x560107   c70305000000                       mov    DWORD PTR [ebx],0x5
0x56010d   5b                                 pop    ebx
0x56010e   8be5                               mov    esp,ebp
0x560110   5d                                 pop    ebp
0x560111   c20400                             ret    0x4
0x560114   5f                                 pop    edi
0x560115   5e                                 pop    esi
0x560116   c70306000000                       mov    DWORD PTR [ebx],0x6
0x56011c   5b                                 pop    ebx
0x56011d   8be5                               mov    esp,ebp
0x56011f   5d                                 pop    ebp
0x560120   c20400                             ret    0x4
0x560123   8b357027fe00                       mov    esi,DWORD PTR ds:0xfe2770
0x560129   8d5e20                             lea    ebx,[esi+0x20]
0x56012c   33ff                               xor    edi,edi
0x56012e   c70300000000                       mov    DWORD PTR [ebx],0x0
0x560134   e8e75f1700                         call   0x6d6120
0x560139   833b00                             cmp    DWORD PTR [ebx],0x0
0x56013c   8b7e1c                             mov    edi,DWORD PTR [esi+0x1c]
0x56013f   7505                               jne    0x560146
0x560141   e8da5f1700                         call   0x6d6120
0x560146   8b5508                             mov    edx,DWORD PTR [ebp+0x8]
0x560149   c70200000000                       mov    DWORD PTR [edx],0x0
0x56014f   5f                                 pop    edi
0x560150   5e                                 pop    esi
0x560151   5b                                 pop    ebx
0x560152   8be5                               mov    esp,ebp
0x560154   5d                                 pop    ebp
0x560155   c20400                             ret    0x4

; q_update [0x561520,0x561678) raw=0x160920 sha256=dd0ce28c40977d5a6c043a7a3493d0b281b58178dfb518cd489688aee32b509d Sepia update lies beyond active/Q coroutine pump guard
0x561520   55                                 push   ebp
0x561521   8bec                               mov    ebp,esp
0x561523   83e4f8                             and    esp,0xfffffff8
0x561526   6aff                               push   0xffffffff
0x561528   687cac9300                         push   0x93ac7c
0x56152d   64a100000000                       mov    eax,fs:0x0
0x561533   50                                 push   eax
0x561534   51                                 push   ecx
0x561535   56                                 push   esi
0x561536   57                                 push   edi
0x561537   a1201fd600                         mov    eax,ds:0xd61f20
0x56153c   33c4                               xor    eax,esp
0x56153e   50                                 push   eax
0x56153f   8d442410                           lea    eax,[esp+0x10]
0x561543   64a300000000                       mov    fs:0x0,eax
0x561549   8bf9                               mov    edi,ecx
0x56154b   f6054027fe0001                     test   BYTE PTR ds:0xfe2740,0x1
0x561552   7529                               jne    0x56157d
0x561554   830d4027fe0001                     or     DWORD PTR ds:0xfe2740,0x1
0x56155b   c744241800000000                   mov    DWORD PTR [esp+0x18],0x0
0x561563   e818d1ffff                         call   0x55e680
0x561568   68a0f2bc00                         push   0xbcf2a0
0x56156d   e8a80d3300                         call   0x89231a
0x561572   83c404                             add    esp,0x4
0x561575   c7442418ffffffff                   mov    DWORD PTR [esp+0x18],0xffffffff
0x56157d   be4427fe00                         mov    esi,0xfe2744
0x561582   e809d2ffff                         call   0x55e790
0x561587   837f2800                           cmp    DWORD PTR [edi+0x28],0x0
0x56158b   7453                               je     0x5615e0
0x56158d   f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
0x561594   be01000000                         mov    esi,0x1
0x561599   7524                               jne    0x5615bf
0x56159b   09352cb2fa00                       or     DWORD PTR ds:0xfab22c,esi
0x5615a1   89742418                           mov    DWORD PTR [esp+0x18],esi
0x5615a5   e8e6d6f7ff                         call   0x4dec90
0x5615aa   6830cebc00                         push   0xbcce30
0x5615af   e8660d3300                         call   0x89231a
0x5615b4   83c404                             add    esp,0x4
0x5615b7   c7442418ffffffff                   mov    DWORD PTR [esp+0x18],0xffffffff
0x5615bf   a1a4a7fb00                         mov    eax,ds:0xfba7a4
0x5615c4   897058                             mov    DWORD PTR [eax+0x58],esi
0x5615c7   837f2c00                           cmp    DWORD PTR [edi+0x2c],0x0
0x5615cb   7513                               jne    0x5615e0
0x5615cd   8b07                               mov    eax,DWORD PTR [edi]
0x5615cf   6a00                               push   0x0
0x5615d1   6a00                               push   0x0
0x5615d3   68a006c100                         push   0xc106a0
0x5615d8   e8f3371900                         call   0x6f4dd0
0x5615dd   83c40c                             add    esp,0xc
0x5615e0   8b7f1c                             mov    edi,DWORD PTR [edi+0x1c]
0x5615e3   8b37                               mov    esi,DWORD PTR [edi]
0x5615e5   3bf7                               cmp    esi,edi
0x5615e7   7455                               je     0x56163e
0x5615e9   8da42400000000                     lea    esp,[esp+0x0]
0x5615f0   8b4e10                             mov    ecx,DWORD PTR [esi+0x10]
0x5615f3   8b11                               mov    edx,DWORD PTR [ecx]
0x5615f5   8b4220                             mov    eax,DWORD PTR [edx+0x20]
0x5615f8   ffd0                               call   eax
0x5615fa   807e1500                           cmp    BYTE PTR [esi+0x15],0x0
0x5615fe   753a                               jne    0x56163a
0x561600   8b4608                             mov    eax,DWORD PTR [esi+0x8]
0x561603   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x561607   7516                               jne    0x56161f
0x561609   8bf0                               mov    esi,eax
0x56160b   8b06                               mov    eax,DWORD PTR [esi]
0x56160d   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x561611   7527                               jne    0x56163a
0x561613   8bf0                               mov    esi,eax
0x561615   8b06                               mov    eax,DWORD PTR [esi]
0x561617   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x56161b   74f6                               je     0x561613
0x56161d   eb1b                               jmp    0x56163a
0x56161f   8b4604                             mov    eax,DWORD PTR [esi+0x4]
0x561622   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x561626   7510                               jne    0x561638
0x561628   3b7008                             cmp    esi,DWORD PTR [eax+0x8]
0x56162b   750b                               jne    0x561638
0x56162d   8bf0                               mov    esi,eax
0x56162f   8b4004                             mov    eax,DWORD PTR [eax+0x4]
0x561632   80781500                           cmp    BYTE PTR [eax+0x15],0x0
0x561636   74f0                               je     0x561628
0x561638   8bf0                               mov    esi,eax
0x56163a   3bf7                               cmp    esi,edi
0x56163c   75b2                               jne    0x5615f0
0x56163e   f605dc36fe0001                     test   BYTE PTR ds:0xfe36dc,0x1
0x561645   7513                               jne    0x56165a
0x561647   830ddc36fe0001                     or     DWORD PTR ds:0xfe36dc,0x1
0x56164e   33c0                               xor    eax,eax
0x561650   a3d436fe00                         mov    ds:0xfe36d4,eax
0x561655   a3d836fe00                         mov    ds:0xfe36d8,eax
0x56165a   68d436fe00                         push   0xfe36d4
0x56165f   e82ceaffff                         call   0x560090
0x561664   33c0                               xor    eax,eax
0x561666   8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
0x56166a   64890d00000000                     mov    DWORD PTR fs:0x0,ecx
0x561671   59                                 pop    ecx
0x561672   5f                                 pop    edi
0x561673   5e                                 pop    esi
0x561674   8be5                               mov    esp,ebp
0x561676   5d                                 pop    ebp
0x561677   c3                                 ret

; sepia_switch [0x560158,0x560170) raw=0x15f558 sha256=d945a69d7337a261295cabb86f4a55f4a2a9cc3bf2884ce28e31a54bbd394e58 sepia_switch
; DATA ad005600da0056004f015600050156001401560023015600

; attach_vtable [0xc0fd48,0xc0fd6c) raw=0x80e348 sha256=bf1de2530e6483d13acfaec97667cfebcb9ddd370fc0a0352f1ea23636a53d12 attach_vtable
; DATA 0041430040e35400c0e3540070e5540080e55400105d5f00f0c28d003064470040e75400

; keyframe_vtable [0xc0fd20,0xc0fd44) raw=0x80e320 sha256=d435552d95f0de82d48fa480b8885ed455463be007dfafcb3dc7e48e7290a91c keyframe_vtable
; DATA 10e9540080e0540030e2540060e254003064470070e25400c0e25400d0e2540010e35400

; animation_worker_vtable [0xc0cf2c,0xc0cf30) raw=0x80b52c sha256=cffbc097cf81a85e197cc8951057a84f4bb9b6b0664c3bd8e52a40b2ebfaed77 animation_worker_vtable
; DATA 20054e00

; attach_col [0xc6cae8,0xc6cafc) raw=0x86b0e8 sha256=3a5b4cde82935e1f9c95020b0e9be355dbadf008b0b3a7a46425975eb9f8d22c attach_col
; DATA 00000000000000000000000094f7f700fccac600

; keyframe_col [0xc6cb34,0xc6cb48) raw=0x86b134 sha256=e8d951c77f4563014287b77657398942cb7e46a5f1939253f916d154c44a5a3f keyframe_col
; DATA 000000000000000000000000ccf7f70048cbc600

; slow_factor [0xc55890,0xc55898) raw=0x853e90 sha256=f27f321d41d1f66907d86235348f63886a5307036a6dba8a620dae20e3eb2c2c slow_factor
; DATA 000000a09999c93f

; qscene_label [0xc1070c,0xc10716) raw=0x80ed0c sha256=c5813d369d0588553b1e8a911fcde820bf0b486fa4b51ac4752f6a935e9661b8 QSceneCam
; DATA 515363656e6543616d00

; pop_mismatch_format [0xc4f230,0xc4f25a) raw=0x84d830 sha256=dac26511b1021a55d1700f2c87eb7e6d773b7cb9c0df5d8bc790cee5d5312fbd Popcamera Fault : Required %s, Popped %s

; DATA 506f7063616d657261204661756c74203a2052657175697265642025732c20506f707065642025730a00

; cameraworks_name [0xc0fd10,0xc0fd1c) raw=0x80e310 sha256=eaf9b0ddd7e95a01433b07ea753279dfc595254ff9e52706cb99cb0881100d03 CameraWorks
; DATA 43616d657261576f726b7300

; stop_name [0xd6a5f8,0xd6a5fd) raw=0x967df8 sha256=ddc2dcaa4e18b15eb75953540bd79f768358abee4654fcca59b2b744d0b67509 Stop
; DATA 53746f7000

; ended_name [0xd6a600,0xd6a608) raw=0x967e00 sha256=abf68cbdf9bf7b76226f368da9161bd4b37d3c7a34cd2d6d06b8c000ff35d997 IsEnded
; DATA 4973456e64656400

; attach_type_name [0xf7f79c,0xf7f7ca) raw=0xb7cf9c sha256=5d5b227c0c375d8c5cc6a9dcc3d81a940aa24ccac7e1a687d104f3d13cfc39b7 .?AVCCameraWorks_AttachSceneObj@CameraWorks@@
; DATA 2e3f41564343616d657261576f726b735f4174746163685363656e654f626a4043616d657261576f726b73404000

; keyframe_type_name [0xf7f7d4,0xf7f7fc) raw=0xb7cfd4 sha256=14c4273501bdcc7374db124cd045c05066148b33c0ada28169e82b3fe000de7c .?AVCCameraWorks_KeyFrame@CameraWorks@@
; DATA 2e3f41564343616d657261576f726b735f4b65794672616d654043616d657261576f726b73404000
