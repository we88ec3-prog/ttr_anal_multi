; Bounded original BIN evidence. Never executed.

; N01 Q manager constructor normal prefix; allocation failure branches leave window
00560170  55                               push   ebp
00560171  8bec                             mov    ebp,esp
00560173  6aff                             push   0xffffffff
00560175  68c8ad9300                       push   0x93adc8
0056017A  64a100000000                     mov    eax,fs:0x0
00560180  50                               push   eax
00560181  83ec38                           sub    esp,0x38
00560184  53                               push   ebx
00560185  56                               push   esi
00560186  a1201fd600                       mov    eax,ds:0xd61f20
0056018B  33c5                             xor    eax,ebp
0056018D  50                               push   eax
0056018E  8d45f4                           lea    eax,[ebp-0xc]
00560191  64a300000000                     mov    fs:0x0,eax
00560197  33db                             xor    ebx,ebx
00560199  6a34                             push   0x34
0056019B  c745e4c073fb00                   mov    DWORD PTR [ebp-0x1c],0xfb73c0
005601A2  891dc073fb00                     mov    DWORD PTR ds:0xfb73c0,ebx
005601A8  891dc473fb00                     mov    DWORD PTR ds:0xfb73c4,ebx
005601AE  891dd073fb00                     mov    DWORD PTR ds:0xfb73d0,ebx
005601B4  e8af103300                       call   0x891268
005601B9  83c404                           add    esp,0x4
005601BC  3bc3                             cmp    eax,ebx
005601BE  0f8432020000                     je     0x5603f6
005601C4  a3cc73fb00                       mov    ds:0xfb73cc,eax
005601C9  8900                             mov    DWORD PTR [eax],eax
005601CB  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601D0  894004                           mov    DWORD PTR [eax+0x4],eax
005601D3  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601D8  894008                           mov    DWORD PTR [eax+0x8],eax
005601DB  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601E0  c6403001                         mov    BYTE PTR [eax+0x30],0x1
005601E4  8b0dcc73fb00                     mov    ecx,DWORD PTR ds:0xfb73cc
005601EA  c6413101                         mov    BYTE PTR [ecx+0x31],0x1
005601EE  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
005601F1  6a18                             push   0x18
005601F3  891de073fb00                     mov    DWORD PTR ds:0xfb73e0,ebx
005601F9  e86a103300                       call   0x891268
005601FE  83c404                           add    esp,0x4
00560201  3bc3                             cmp    eax,ebx
00560203  0f84c9010000                     je     0x5603d2
00560209  a3dc73fb00                       mov    ds:0xfb73dc,eax
0056020E  8900                             mov    DWORD PTR [eax],eax
00560210  a1dc73fb00                       mov    eax,ds:0xfb73dc
00560215  894004                           mov    DWORD PTR [eax+0x4],eax
00560218  a1dc73fb00                       mov    eax,ds:0xfb73dc
0056021D  894008                           mov    DWORD PTR [eax+0x8],eax
00560220  8b15dc73fb00                     mov    edx,DWORD PTR ds:0xfb73dc
00560226  c6421401                         mov    BYTE PTR [edx+0x14],0x1
0056022A  a1dc73fb00                       mov    eax,ds:0xfb73dc
0056022F  c6401501                         mov    BYTE PTR [eax+0x15],0x1
00560233  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
00560237  6a48                             push   0x48
00560239  891de873fb00                     mov    DWORD PTR ds:0xfb73e8,ebx
0056023F  891dec73fb00                     mov    DWORD PTR ds:0xfb73ec,ebx
00560245  e81e103300                       call   0x891268
0056024A  83c404                           add    esp,0x4
0056024D  8945e8                           mov    DWORD PTR [ebp-0x18],eax
00560250  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
00560254  3bc3                             cmp    eax,ebx
00560256  7409                             je     0x560261
00560258  8bf0                             mov    esi,eax
0056025A  e851d02600                       call   0x7cd2b0
0056025F  eb02                             jmp    0x560263
00560261  33c0                             xor    eax,eax
00560263  a3f073fb00                       mov    ds:0xfb73f0,eax
00560268  891df873fb00                     mov    DWORD PTR ds:0xfb73f8,ebx
0056026E  891dfc73fb00                     mov    DWORD PTR ds:0xfb73fc,ebx
00560274  c7050074fb00ffffffff             mov    DWORD PTR ds:0xfb7400,0xffffffff
0056027E  c7051874fb000f000000             mov    DWORD PTR ds:0xfb7418,0xf
00560288  891d1474fb00                     mov    DWORD PTR ds:0xfb7414,ebx
0056028E  881d0474fb00                     mov    BYTE PTR ds:0xfb7404,bl
00560294  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
00560298  6a14                             push   0x14
0056029A  891d2874fb00                     mov    DWORD PTR ds:0xfb7428,ebx
005602A0  e8c30f3300                       call   0x891268
005602A5  83c404                           add    esp,0x4
005602A8  3bc3                             cmp    eax,ebx
005602AA  0f84fe000000                     je     0x5603ae
005602B0  a32474fb00                       mov    ds:0xfb7424,eax
005602B5  8900                             mov    DWORD PTR [eax],eax
005602B7  a12474fb00                       mov    eax,ds:0xfb7424
005602BC  894004                           mov    DWORD PTR [eax+0x4],eax
005602BF  a12474fb00                       mov    eax,ds:0xfb7424
005602C4  894008                           mov    DWORD PTR [eax+0x8],eax
005602C7  8b0d2474fb00                     mov    ecx,DWORD PTR ds:0xfb7424
005602CD  c6411001                         mov    BYTE PTR [ecx+0x10],0x1
005602D1  8b152474fb00                     mov    edx,DWORD PTR ds:0xfb7424
005602D7  c6421101                         mov    BYTE PTR [edx+0x11],0x1
005602DB  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
005602DF  6a14                             push   0x14
005602E1  891d3074fb00                     mov    DWORD PTR ds:0xfb7430,ebx
005602E7  891d3c74fb00                     mov    DWORD PTR ds:0xfb743c,ebx
005602ED  e8760f3300                       call   0x891268
005602F2  83c404                           add    esp,0x4
005602F5  3bc3                             cmp    eax,ebx
005602F7  0f848d000000                     je     0x56038a
005602FD  a33874fb00                       mov    ds:0xfb7438,eax
00560302  8900                             mov    DWORD PTR [eax],eax
00560304  a13874fb00                       mov    eax,ds:0xfb7438
00560309  894004                           mov    DWORD PTR [eax+0x4],eax
0056030C  a13874fb00                       mov    eax,ds:0xfb7438
00560311  894008                           mov    DWORD PTR [eax+0x8],eax
00560314  a13874fb00                       mov    eax,ds:0xfb7438
00560319  c6401001                         mov    BYTE PTR [eax+0x10],0x1
0056031D  8b0d3874fb00                     mov    ecx,DWORD PTR ds:0xfb7438
00560323  c6411101                         mov    BYTE PTR [ecx+0x11],0x1
00560327  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0056032B  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
00560333  f30f11054474fb00                 movss  DWORD PTR ds:0xfb7444,xmm0
0056033B  66c7054874fb000100               mov    WORD PTR ds:0xfb7448,0x1
00560344  e887040000                       call   0x5607d0
00560349  e8f2200000                       call   0x562440
0056034E  f6054027fe0001                   test   BYTE PTR ds:0xfe2740,0x1
00560355  751d                             jne    0x560374
00560357  830d4027fe0001                   or     DWORD PTR ds:0xfe2740,0x1
0056035E  c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
00560362  e819e3ffff                       call   0x55e680
00560367  68a0f2bc00                       push   0xbcf2a0
0056036C  e8a91f3300                       call   0x89231a
00560371  83c404                           add    esp,0x4
00560374  b8c073fb00                       mov    eax,0xfb73c0
00560379  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0056037C  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00560383  59                               pop    ecx
00560384  5e                               pop    esi
00560385  5b                               pop    ebx
00560386  8be5                             mov    esp,ebp
00560388  5d                               pop    ebp
00560389  c3                               ret

; N02 normal Start prefix through the seen-skip branch; accepted path continues at end
00561760  55                               push   ebp
00561761  8bec                             mov    ebp,esp
00561763  83e4f8                           and    esp,0xfffffff8
00561766  6aff                             push   0xffffffff
00561768  682cfd9300                       push   0x93fd2c
0056176D  64a100000000                     mov    eax,fs:0x0
00561773  50                               push   eax
00561774  83ec50                           sub    esp,0x50
00561777  a1201fd600                       mov    eax,ds:0xd61f20
0056177C  33c4                             xor    eax,esp
0056177E  89442448                         mov    DWORD PTR [esp+0x48],eax
00561782  53                               push   ebx
00561783  56                               push   esi
00561784  57                               push   edi
00561785  a1201fd600                       mov    eax,ds:0xd61f20
0056178A  33c4                             xor    eax,esp
0056178C  50                               push   eax
0056178D  8d442460                         lea    eax,[esp+0x60]
00561791  64a300000000                     mov    fs:0x0,eax
00561797  833d18abfb0000                   cmp    DWORD PTR ds:0xfbab18,0x0
0056179E  8bd9                             mov    ebx,ecx
005617A0  7420                             je     0x5617c2
005617A2  0f57c0                           xorps  xmm0,xmm0
005617A5  f30f110524abfb00                 movss  DWORD PTR ds:0xfbab24,xmm0
005617AD  e8aed8eaff                       call   0x40f060
005617B2  f30f10057059c500                 movss  xmm0,DWORD PTR ds:0xc55970
005617BA  f30f1180ac000000                 movss  DWORD PTR [eax+0xac],xmm0
005617C2  837b2800                         cmp    DWORD PTR [ebx+0x28],0x0
005617C6  c6838900000000                   mov    BYTE PTR [ebx+0x89],0x0
005617CD  741a                             je     0x5617e9
005617CF  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
005617D2  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
005617D5  50                               push   eax
005617D6  51                               push   ecx
005617D7  68ac06c100                       push   0xc106ac
005617DC  e87fc31800                       call   0x6edb60
005617E1  83c40c                           add    esp,0xc
005617E4  e99d050000                       jmp    0x561d86
005617E9  f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
005617F0  be01000000                       mov    esi,0x1
005617F5  7529                             jne    0x561820
005617F7  09352888fb00                     or     DWORD PTR ds:0xfb8828,esi
005617FD  c744246800000000                 mov    DWORD PTR [esp+0x68],0x0
00561805  e846e0feff                       call   0x54f850
0056180A  6880d5bc00                       push   0xbcd580
0056180F  e8060b3300                       call   0x89231a
00561814  83c404                           add    esp,0x4
00561817  83cfff                           or     edi,0xffffffff
0056181A  897c2468                         mov    DWORD PTR [esp+0x68],edi
0056181E  eb03                             jmp    0x561823
00561820  83cfff                           or     edi,0xffffffff
00561823  803df192fb0000                   cmp    BYTE PTR ds:0xfb92f1,0x0
0056182A  0f84ac000000                     je     0x5618dc
00561830  837d0800                         cmp    DWORD PTR [ebp+0x8],0x0
00561834  0f85a2000000                     jne    0x5618dc
0056183A  e86133eaff                       call   0x404ba0
0056183F  83b84c5f000009                   cmp    DWORD PTR [eax+0x5f4c],0x9
00561846  741c                             je     0x561864
00561848  e85333eaff                       call   0x404ba0
0056184D  83b84c5f000004                   cmp    DWORD PTR [eax+0x5f4c],0x4
00561854  740e                             je     0x561864
00561856  e84533eaff                       call   0x404ba0
0056185B  83b84c5f000019                   cmp    DWORD PTR [eax+0x5f4c],0x19
00561862  7578                             jne    0x5618dc
00561864  8b7378                           mov    esi,DWORD PTR [ebx+0x78]
00561867  8d550c                           lea    edx,[ebp+0xc]
0056186A  52                               push   edx
0056186B  8d4b74                           lea    ecx,[ebx+0x74]
0056186E  8d442414                         lea    eax,[esp+0x14]
00561872  e8494cedff                       call   0x4364c0
00561877  3930                             cmp    DWORD PTR [eax],esi
00561879  745c                             je     0x5618d7
0056187B  6a0f                             push   0xf
0056187D  e82e3d0200                       call   0x5855b0
00561882  8bf0                             mov    esi,eax
00561884  e8a73a0200                       call   0x585330
00561889  50                               push   eax
0056188A  8d4c2440                         lea    ecx,[esp+0x40]
0056188E  e8bd09eaff                       call   0x402250
00561893  8d44243c                         lea    eax,[esp+0x3c]
00561897  50                               push   eax
00561898  c744246c01000000                 mov    DWORD PTR [esp+0x6c],0x1
005618A0  e81be0eaff                       call   0x40f8c0
005618A5  8bf8                             mov    edi,eax
005618A7  e88452f7ff                       call   0x4d6b30
005618AC  8d4c243c                         lea    ecx,[esp+0x3c]
005618B0  c7442468ffffffff                 mov    DWORD PTR [esp+0x68],0xffffffff
005618B8  e8838bf9ff                       call   0x4fa440
005618BD  e8be2debff                       call   0x414680
005618C2  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
005618C5  51                               push   ecx
005618C6  6a00                             push   0x0
005618C8  e8d320f4ff                       call   0x4a39a0
005618CD  e8de070000                       call   0x5620b0
005618D2  e9af040000                       jmp    0x561d86
005618D7  be01000000                       mov    esi,0x1

; N03 complete normal/review End body
00561DB0  55                               push   ebp
00561DB1  8bec                             mov    ebp,esp
00561DB3  83e4f8                           and    esp,0xfffffff8
00561DB6  6aff                             push   0xffffffff
00561DB8  6864fc9300                       push   0x93fc64
00561DBD  64a100000000                     mov    eax,fs:0x0
00561DC3  50                               push   eax
00561DC4  83ec10                           sub    esp,0x10
00561DC7  53                               push   ebx
00561DC8  56                               push   esi
00561DC9  57                               push   edi
00561DCA  a1201fd600                       mov    eax,ds:0xd61f20
00561DCF  33c4                             xor    eax,esp
00561DD1  50                               push   eax
00561DD2  8d442420                         lea    eax,[esp+0x20]
00561DD6  64a300000000                     mov    fs:0x0,eax
00561DDC  8bf9                             mov    edi,ecx
00561DDE  33f6                             xor    esi,esi
00561DE0  80bf8900000000                   cmp    BYTE PTR [edi+0x89],0x0
00561DE7  0f8473010000                     je     0x561f60
00561DED  397728                           cmp    DWORD PTR [edi+0x28],esi
00561DF0  0f84aa000000                     je     0x561ea0
00561DF6  897728                           mov    DWORD PTR [edi+0x28],esi
00561DF9  e85224edff                       call   0x434250
00561DFE  bb01000000                       mov    ebx,0x1
00561E03  895814                           mov    DWORD PTR [eax+0x14],ebx
00561E06  841dd4f3fd00                     test   BYTE PTR ds:0xfdf3d4,bl
00561E0C  7525                             jne    0x561e33
00561E0E  091dd4f3fd00                     or     DWORD PTR ds:0xfdf3d4,ebx
00561E14  89742428                         mov    DWORD PTR [esp+0x28],esi
00561E18  e863251900                       call   0x6f4380
00561E1D  68d0e6bc00                       push   0xbce6d0
00561E22  e8f3043300                       call   0x89231a
00561E27  83c404                           add    esp,0x4
00561E2A  83ceff                           or     esi,0xffffffff
00561E2D  89742428                         mov    DWORD PTR [esp+0x28],esi
00561E31  eb03                             jmp    0x561e36
00561E33  83ceff                           or     esi,0xffffffff
00561E36  68ec06c100                       push   0xc106ec
00561E3B  6a00                             push   0x0
00561E3D  68c8f3fd00                       push   0xfdf3c8
00561E42  e859b2f4ff                       call   0x4ad0a0
00561E47  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
00561E4E  7520                             jne    0x561e70
00561E50  091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
00561E56  895c2428                         mov    DWORD PTR [esp+0x28],ebx
00561E5A  e821560200                       call   0x587480
00561E5F  68c0ccbc00                       push   0xbcccc0
00561E64  e8b1043300                       call   0x89231a
00561E69  83c404                           add    esp,0x4
00561E6C  89742428                         mov    DWORD PTR [esp+0x28],esi
00561E70  d98784000000                     fld    DWORD PTR [edi+0x84]
00561E76  83ec08                           sub    esp,0x8
00561E79  d95c241c                         fstp   DWORD PTR [esp+0x1c]
00561E7D  d944241c                         fld    DWORD PTR [esp+0x1c]
00561E81  d9542404                         fst    DWORD PTR [esp+0x4]
00561E85  d91c24                           fstp   DWORD PTR [esp]
00561E88  e8937b0200                       call   0x589a20
00561E8D  8a9f88000000                     mov    bl,BYTE PTR [edi+0x88]
00561E93  e8082deaff                       call   0x404ba0
00561E98  8898c4680000                     mov    BYTE PTR [eax+0x68c4],bl
00561E9E  eb03                             jmp    0x561ea3
00561EA0  83ceff                           or     esi,0xffffffff
00561EA3  f605640ffc0001                   test   BYTE PTR ds:0xfc0f64,0x1
00561EAA  7525                             jne    0x561ed1
00561EAC  830d640ffc0001                   or     DWORD PTR ds:0xfc0f64,0x1
00561EB3  c744242802000000                 mov    DWORD PTR [esp+0x28],0x2
00561EBB  e820bef1ff                       call   0x47dce0
00561EC0  68f0dabc00                       push   0xbcdaf0
00561EC5  e850043300                       call   0x89231a
00561ECA  83c404                           add    esp,0x4
00561ECD  89742428                         mov    DWORD PTR [esp+0x28],esi
00561ED1  8b473c                           mov    eax,DWORD PTR [edi+0x3c]
00561ED4  8b4f38                           mov    ecx,DWORD PTR [edi+0x38]
00561ED7  50                               push   eax
00561ED8  51                               push   ecx
00561ED9  68680ffc00                       push   0xfc0f68
00561EDE  e85dc7f1ff                       call   0x47e640
00561EE3  33db                             xor    ebx,ebx
00561EE5  89473c                           mov    DWORD PTR [edi+0x3c],eax
00561EE8  3bc3                             cmp    eax,ebx
00561EEA  741f                             je     0x561f0b
00561EEC  8b5738                           mov    edx,DWORD PTR [edi+0x38]
00561EEF  50                               push   eax
00561EF0  52                               push   edx
00561EF1  8bf7                             mov    esi,edi
00561EF3  e828380000                       call   0x565720
00561EF8  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00561EFC  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00561F03  59                               pop    ecx
00561F04  5f                               pop    edi
00561F05  5e                               pop    esi
00561F06  5b                               pop    ebx
00561F07  8be5                             mov    esp,ebp
00561F09  5d                               pop    ebp
00561F0A  c3                               ret
00561F0B  f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
00561F12  7525                             jne    0x561f39
00561F14  830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
00561F1B  c744242803000000                 mov    DWORD PTR [esp+0x28],0x3
00561F23  e8286f1700                       call   0x6d8e50
00561F28  68b0dbbc00                       push   0xbcdbb0
00561F2D  e8e8033300                       call   0x89231a
00561F32  83c404                           add    esp,0x4
00561F35  89742428                         mov    DWORD PTR [esp+0x28],esi
00561F39  8b4734                           mov    eax,DWORD PTR [edi+0x34]
00561F3C  50                               push   eax
00561F3D  b9c80ffc00                       mov    ecx,0xfc0fc8
00561F42  e8e9741700                       call   0x6d9430
00561F47  895f38                           mov    DWORD PTR [edi+0x38],ebx
00561F4A  895f3c                           mov    DWORD PTR [edi+0x3c],ebx
00561F4D  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00561F51  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00561F58  59                               pop    ecx
00561F59  5f                               pop    edi
00561F5A  5e                               pop    esi
00561F5B  5b                               pop    ebx
00561F5C  8be5                             mov    esp,ebp
00561F5E  5d                               pop    ebp
00561F5F  c3                               ret
00561F60  397728                           cmp    DWORD PTR [edi+0x28],esi
00561F63  0f8428010000                     je     0x562091
00561F69  897728                           mov    DWORD PTR [edi+0x28],esi
00561F6C  e8df22edff                       call   0x434250
00561F71  bb01000000                       mov    ebx,0x1
00561F76  895814                           mov    DWORD PTR [eax+0x14],ebx
00561F79  397738                           cmp    DWORD PTR [edi+0x38],esi
00561F7C  7439                             je     0x561fb7
00561F7E  684403c100                       push   0xc10344
00561F83  53                               push   ebx
00561F84  e8a792f3ff                       call   0x49b230
00561F89  50                               push   eax
00561F8A  e811b1f4ff                       call   0x4ad0a0
00561F8F  6aff                             push   0xffffffff
00561F91  51                               push   ecx
00561F92  e89992f3ff                       call   0x49b230
00561F97  83c404                           add    esp,0x4
00561F9A  e8b10bf4ff                       call   0x4a2b50
00561F9F  3bc3                             cmp    eax,ebx
00561FA1  754e                             jne    0x561ff1
00561FA3  e8d826ebff                       call   0x414680
00561FA8  8b4f3c                           mov    ecx,DWORD PTR [edi+0x3c]
00561FAB  8b5738                           mov    edx,DWORD PTR [edi+0x38]
00561FAE  51                               push   ecx
00561FAF  52                               push   edx
00561FB0  e8eb19f4ff                       call   0x4a39a0
00561FB5  eb3a                             jmp    0x561ff1
00561FB7  8d5f3c                           lea    ebx,[edi+0x3c]
00561FBA  8d7774                           lea    esi,[edi+0x74]
00561FBD  53                               push   ebx
00561FBE  e87dbe1500                       call   0x6bde40
00561FC3  50                               push   eax
00561FC4  56                               push   esi
00561FC5  8d74241c                         lea    esi,[esp+0x1c]
00561FC9  e8c248edff                       call   0x436890
00561FCE  57                               push   edi
00561FCF  e8cc030000                       call   0x5623a0
00561FD4  e8a726ebff                       call   0x414680
00561FD9  8b03                             mov    eax,DWORD PTR [ebx]
00561FDB  8b4f38                           mov    ecx,DWORD PTR [edi+0x38]
00561FDE  50                               push   eax
00561FDF  51                               push   ecx
00561FE0  e8bb19f4ff                       call   0x4a39a0
00561FE5  e8c6000000                       call   0x5620b0
00561FEA  bb01000000                       mov    ebx,0x1
00561FEF  33f6                             xor    esi,esi
00561FF1  f605d4f3fd0001                   test   BYTE PTR ds:0xfdf3d4,0x1
00561FF8  7528                             jne    0x562022
00561FFA  091dd4f3fd00                     or     DWORD PTR ds:0xfdf3d4,ebx
00562000  c744242804000000                 mov    DWORD PTR [esp+0x28],0x4
00562008  e873231900                       call   0x6f4380
0056200D  68d0e6bc00                       push   0xbce6d0
00562012  e803033300                       call   0x89231a
00562017  83c404                           add    esp,0x4
0056201A  c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
00562022  68ec06c100                       push   0xc106ec
00562027  56                               push   esi
00562028  68c8f3fd00                       push   0xfdf3c8
0056202D  e86eb0f4ff                       call   0x4ad0a0
00562032  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
00562039  7528                             jne    0x562063
0056203B  091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
00562041  c744242805000000                 mov    DWORD PTR [esp+0x28],0x5
00562049  e832540200                       call   0x587480
0056204E  68c0ccbc00                       push   0xbcccc0
00562053  e8c2023300                       call   0x89231a
00562058  83c404                           add    esp,0x4
0056205B  c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
00562063  d98784000000                     fld    DWORD PTR [edi+0x84]
00562069  83ec08                           sub    esp,0x8
0056206C  d95c241c                         fstp   DWORD PTR [esp+0x1c]
00562070  d944241c                         fld    DWORD PTR [esp+0x1c]
00562074  d9542404                         fst    DWORD PTR [esp+0x4]
00562078  d91c24                           fstp   DWORD PTR [esp]
0056207B  e8a0790200                       call   0x589a20
00562080  8a9f88000000                     mov    bl,BYTE PTR [edi+0x88]
00562086  e8152beaff                       call   0x404ba0
0056208B  8898c4680000                     mov    BYTE PTR [eax+0x68c4],bl
00562091  897738                           mov    DWORD PTR [edi+0x38],esi
00562094  89773c                           mov    DWORD PTR [edi+0x3c],esi
00562097  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0056209B  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
005620A2  59                               pop    ecx
005620A3  5f                               pop    edi
005620A4  5e                               pop    esi
005620A5  5b                               pop    ebx
005620A6  8be5                             mov    esp,ebp
005620A8  5d                               pop    ebp
005620A9  c3                               ret

; N04 complete seen-key writer
005623A0  55                               push   ebp
005623A1  8bec                             mov    ebp,esp
005623A3  53                               push   ebx
005623A4  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
005623A7  57                               push   edi
005623A8  68a459c000                       push   0xc059a4
005623AD  b90407c100                       mov    ecx,0xc10704
005623B2  e809191b00                       call   0x713cc0
005623B7  8bf8                             mov    edi,eax
005623B9  83c404                           add    esp,0x4
005623BC  85ff                             test   edi,edi
005623BE  7476                             je     0x562436
005623C0  8b4378                           mov    eax,DWORD PTR [ebx+0x78]
005623C3  56                               push   esi
005623C4  8b30                             mov    esi,DWORD PTR [eax]
005623C6  3bf0                             cmp    esi,eax
005623C8  7462                             je     0x56242c
005623CA  8d9b00000000                     lea    ebx,[ebx+0x0]
005623D0  8b07                             mov    eax,DWORD PTR [edi]
005623D2  8b5014                           mov    edx,DWORD PTR [eax+0x14]
005623D5  6a01                             push   0x1
005623D7  6a04                             push   0x4
005623D9  8d4e0c                           lea    ecx,[esi+0xc]
005623DC  51                               push   ecx
005623DD  8bcf                             mov    ecx,edi
005623DF  ffd2                             call   edx
005623E1  807e1100                         cmp    BYTE PTR [esi+0x11],0x0
005623E5  7540                             jne    0x562427
005623E7  8b4608                           mov    eax,DWORD PTR [esi+0x8]
005623EA  80781100                         cmp    BYTE PTR [eax+0x11],0x0
005623EE  751c                             jne    0x56240c
005623F0  8bf0                             mov    esi,eax
005623F2  8b06                             mov    eax,DWORD PTR [esi]
005623F4  80781100                         cmp    BYTE PTR [eax+0x11],0x0
005623F8  752d                             jne    0x562427
005623FA  8d9b00000000                     lea    ebx,[ebx+0x0]
00562400  8bf0                             mov    esi,eax
00562402  8b06                             mov    eax,DWORD PTR [esi]
00562404  80781100                         cmp    BYTE PTR [eax+0x11],0x0
00562408  74f6                             je     0x562400
0056240A  eb1b                             jmp    0x562427
0056240C  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0056240F  80781100                         cmp    BYTE PTR [eax+0x11],0x0
00562413  7510                             jne    0x562425
00562415  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
00562418  750b                             jne    0x562425
0056241A  8bf0                             mov    esi,eax
0056241C  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0056241F  80781100                         cmp    BYTE PTR [eax+0x11],0x0
00562423  74f0                             je     0x562415
00562425  8bf0                             mov    esi,eax
00562427  3b7378                           cmp    esi,DWORD PTR [ebx+0x78]
0056242A  75a4                             jne    0x5623d0
0056242C  8b07                             mov    eax,DWORD PTR [edi]
0056242E  8b5004                           mov    edx,DWORD PTR [eax+0x4]
00562431  8bcf                             mov    ecx,edi
00562433  ffd2                             call   edx
00562435  5e                               pop    esi
00562436  5f                               pop    edi
00562437  5b                               pop    ebx
00562438  5d                               pop    ebp
00562439  c20400                           ret    0x4

; N05 complete seen-key reader
00562440  55                               push   ebp
00562441  8bec                             mov    ebp,esp
00562443  83ec0c                           sub    esp,0xc
00562446  53                               push   ebx
00562447  56                               push   esi
00562448  57                               push   edi
00562449  68e0d1be00                       push   0xbed1e0
0056244E  b90407c100                       mov    ecx,0xc10704
00562453  e868181b00                       call   0x713cc0
00562458  8bd8                             mov    ebx,eax
0056245A  83c404                           add    esp,0x4
0056245D  85db                             test   ebx,ebx
0056245F  7443                             je     0x5624a4
00562461  bf3474fb00                       mov    edi,0xfb7434
00562466  e8b5ef2e00                       call   0x851420
0056246B  8b03                             mov    eax,DWORD PTR [ebx]
0056246D  8b5010                           mov    edx,DWORD PTR [eax+0x10]
00562470  6a01                             push   0x1
00562472  6a04                             push   0x4
00562474  8d4dfc                           lea    ecx,[ebp-0x4]
00562477  51                               push   ecx
00562478  8bcb                             mov    ecx,ebx
0056247A  ffd2                             call   edx
0056247C  8bf8                             mov    edi,eax
0056247E  8d45fc                           lea    eax,[ebp-0x4]
00562481  50                               push   eax
00562482  be3474fb00                       mov    esi,0xfb7434
00562487  e8b4b91500                       call   0x6bde40
0056248C  50                               push   eax
0056248D  56                               push   esi
0056248E  8d75f4                           lea    esi,[ebp-0xc]
00562491  e8fa43edff                       call   0x436890
00562496  83ff01                           cmp    edi,0x1
00562499  74d0                             je     0x56246b
0056249B  8b13                             mov    edx,DWORD PTR [ebx]
0056249D  8b4204                           mov    eax,DWORD PTR [edx+0x4]
005624A0  8bcb                             mov    ecx,ebx
005624A2  ffd0                             call   eax
005624A4  5f                               pop    edi
005624A5  5e                               pop    esi
005624A6  5b                               pop    ebx
005624A7  8be5                             mov    esp,ebp
005624A9  5d                               pop    ebp
005624AA  c3                               ret

; N06 file constructor/open prefix through initial seek operations; subsequent checks outside window
00713CC0  55                               push   ebp
00713CC1  8bec                             mov    ebp,esp
00713CC3  83ec24                           sub    esp,0x24
00713CC6  a1201fd600                       mov    eax,ds:0xd61f20
00713CCB  33c5                             xor    eax,ebp
00713CCD  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00713CD0  53                               push   ebx
00713CD1  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
00713CD4  56                               push   esi
00713CD5  57                               push   edi
00713CD6  6a10                             push   0x10
00713CD8  8bf9                             mov    edi,ecx
00713CDA  e889d51700                       call   0x891268
00713CDF  33f6                             xor    esi,esi
00713CE1  83c404                           add    esp,0x4
00713CE4  3bc6                             cmp    eax,esi
00713CE6  7411                             je     0x713cf9
00713CE8  897004                           mov    DWORD PTR [eax+0x4],esi
00713CEB  897008                           mov    DWORD PTR [eax+0x8],esi
00713CEE  89700c                           mov    DWORD PTR [eax+0xc],esi
00713CF1  c7000442c400                     mov    DWORD PTR [eax],0xc44204
00713CF7  8bf0                             mov    esi,eax
00713CF9  53                               push   ebx
00713CFA  57                               push   edi
00713CFB  e87bdb1700                       call   0x89187b
00713D00  83c408                           add    esp,0x8
00713D03  894604                           mov    DWORD PTR [esi+0x4],eax
00713D06  85c0                             test   eax,eax
00713D08  8b06                             mov    eax,DWORD PTR [esi]
00713D0A  8bce                             mov    ecx,esi
00713D0C  7519                             jne    0x713d27
00713D0E  8b10                             mov    edx,DWORD PTR [eax]
00713D10  6a01                             push   0x1
00713D12  ffd2                             call   edx
00713D14  5f                               pop    edi
00713D15  5e                               pop    esi
00713D16  33c0                             xor    eax,eax
00713D18  5b                               pop    ebx
00713D19  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
00713D1C  33cd                             xor    ecx,ebp
00713D1E  e8ded21700                       call   0x891001
00713D23  8be5                             mov    esp,ebp
00713D25  5d                               pop    ebp
00713D26  c3                               ret
00713D27  8b5034                           mov    edx,DWORD PTR [eax+0x34]
00713D2A  6a02                             push   0x2
00713D2C  6a00                             push   0x0
00713D2E  ffd2                             call   edx
00713D30  8b06                             mov    eax,DWORD PTR [esi]
00713D32  8b5030                           mov    edx,DWORD PTR [eax+0x30]
00713D35  8bce                             mov    ecx,esi
00713D37  ffd2                             call   edx
00713D39  89460c                           mov    DWORD PTR [esi+0xc],eax
00713D3C  8b06                             mov    eax,DWORD PTR [esi]
00713D3E  8b5034                           mov    edx,DWORD PTR [eax+0x34]
00713D41  6a00                             push   0x0
00713D43  6a00                             push   0x0
00713D45  8bce                             mov    ecx,esi
00713D47  ffd2                             call   edx

; N07 complete close method
00713DE0  56                               push   esi
00713DE1  8bf1                             mov    esi,ecx
00713DE3  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00713DE6  57                               push   edi
00713DE7  50                               push   eax
00713DE8  e8dcde1700                       call   0x891cc9
00713DED  8b16                             mov    edx,DWORD PTR [esi]
00713DEF  83c404                           add    esp,0x4
00713DF2  8bf8                             mov    edi,eax
00713DF4  8b02                             mov    eax,DWORD PTR [edx]
00713DF6  6a01                             push   0x1
00713DF8  8bce                             mov    ecx,esi
00713DFA  ffd0                             call   eax
00713DFC  8bc7                             mov    eax,edi
00713DFE  5f                               pop    edi
00713DFF  5e                               pop    esi
00713E00  c3                               ret

; N08 complete read method
00713E50  55                               push   ebp
00713E51  8bec                             mov    ebp,esp
00713E53  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
00713E56  8b4d10                           mov    ecx,DWORD PTR [ebp+0x10]
00713E59  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
00713E5C  50                               push   eax
00713E5D  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00713E60  51                               push   ecx
00713E61  52                               push   edx
00713E62  50                               push   eax
00713E63  e8d7dd1700                       call   0x891c3f
00713E68  83c410                           add    esp,0x10
00713E6B  5d                               pop    ebp
00713E6C  c20c00                           ret    0xc

; N09 complete write method
00713E70  55                               push   ebp
00713E71  8bec                             mov    ebp,esp
00713E73  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
00713E76  8b4d10                           mov    ecx,DWORD PTR [ebp+0x10]
00713E79  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
00713E7C  50                               push   eax
00713E7D  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00713E80  51                               push   ecx
00713E81  52                               push   edx
00713E82  50                               push   eax
00713E83  e822f61700                       call   0x8934aa
00713E88  83c410                           add    esp,0x10
00713E8B  5d                               pop    ebp
00713E8C  c20c00                           ret    0xc

