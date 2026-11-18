# N01-actor-move 0x4cabe0..0x4cacc0
004cabe0  55                                push   ebp
004cabe1  8bec                              mov    ebp,esp
004cabe3  83e4f8                            and    esp,0xfffffff8
004cabe6  6aff                              push   0xffffffff
004cabe8  681e6a9300                        push   0x936a1e
004cabed  64a100000000                      mov    eax,fs:0x0
004cabf3  50                                push   eax
004cabf4  83ec18                            sub    esp,0x18
004cabf7  56                                push   esi
004cabf8  a1201fd600                        mov    eax,ds:0xd61f20
004cabfd  33c4                              xor    eax,esp
004cabff  50                                push   eax
004cac00  8d442420                          lea    eax,[esp+0x20]
004cac04  64a300000000                      mov    fs:0x0,eax
004cac0a  8bf1                              mov    esi,ecx
004cac0c  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
004cac13  7529                              jne    0x4cac3e
004cac15  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
004cac1c  c744242800000000                  mov    DWORD PTR [esp+0x28],0x0
004cac24  e867400100                        call   0x4dec90
004cac29  6830cebc00                        push   0xbcce30
004cac2e  e8e7763c00                        call   0x89231a
004cac33  83c404                            add    esp,0x4
004cac36  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
004cac3e  8b0dd0b1fa00                      mov    ecx,DWORD PTR ds:0xfab1d0
004cac44  85c9                              test   ecx,ecx
004cac46  7461                              je     0x4caca9
004cac48  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
004cac4b  d900                              fld    DWORD PTR [eax]
004cac4d  d886a0000000                      fadd   DWORD PTR [esi+0xa0]
004cac53  d95c240c                          fstp   DWORD PTR [esp+0xc]
004cac57  d944240c                          fld    DWORD PTR [esp+0xc]
004cac5b  d95c2414                          fstp   DWORD PTR [esp+0x14]
004cac5f  d986a4000000                      fld    DWORD PTR [esi+0xa4]
004cac65  d84004                            fadd   DWORD PTR [eax+0x4]
004cac68  8d442414                          lea    eax,[esp+0x14]
004cac6c  d95c2410                          fstp   DWORD PTR [esp+0x10]
004cac70  d9442410                          fld    DWORD PTR [esp+0x10]
004cac74  d95c2418                          fstp   DWORD PTR [esp+0x18]
004cac78  e873213600                        call   0x82cdf0
004cac7d  85c0                              test   eax,eax
004cac7f  7428                              je     0x4caca9
004cac81  f30f1044240c                      movss  xmm0,DWORD PTR [esp+0xc]
004cac87  8b06                              mov    eax,DWORD PTR [esi]
004cac89  8b5044                            mov    edx,DWORD PTR [eax+0x44]
004cac8c  6a01                              push   0x1
004cac8e  8d4c2418                          lea    ecx,[esp+0x18]
004cac92  f30f11442418                      movss  DWORD PTR [esp+0x18],xmm0
004cac98  f30f10442414                      movss  xmm0,DWORD PTR [esp+0x14]
004cac9e  51                                push   ecx
004cac9f  8bce                              mov    ecx,esi
004caca1  f30f11442420                      movss  DWORD PTR [esp+0x20],xmm0
004caca7  ffd2                              call   edx
004caca9  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
004cacad  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004cacb4  59                                pop    ecx
004cacb5  5e                                pop    esi
004cacb6  8be5                              mov    esp,ebp
004cacb8  5d                                pop    ebp
004cacb9  c20400                            ret    0x4
004cacbc  cc                                int3
004cacbd  cc                                int3
004cacbe  cc                                int3
004cacbf  cc                                int3

# N02-bound-query 0x82cdf0..0x82ce80
0082cdf0  55                                push   ebp
0082cdf1  8bec                              mov    ebp,esp
0082cdf3  83ec14                            sub    esp,0x14
0082cdf6  53                                push   ebx
0082cdf7  56                                push   esi
0082cdf8  8bf1                              mov    esi,ecx
0082cdfa  8b5e24                            mov    ebx,DWORD PTR [esi+0x24]
0082cdfd  57                                push   edi
0082cdfe  85db                              test   ebx,ebx
0082ce00  750e                              jne    0x82ce10
0082ce02  395e28                            cmp    DWORD PTR [esi+0x28],ebx
0082ce05  7509                              jne    0x82ce10
0082ce07  33c0                              xor    eax,eax
0082ce09  5f                                pop    edi
0082ce0a  5e                                pop    esi
0082ce0b  5b                                pop    ebx
0082ce0c  8be5                              mov    esp,ebp
0082ce0e  5d                                pop    ebp
0082ce0f  c3                                ret
0082ce10  8b08                              mov    ecx,DWORD PTR [eax]
0082ce12  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0082ce15  894df8                            mov    DWORD PTR [ebp-0x8],ecx
0082ce18  8955fc                            mov    DWORD PTR [ebp-0x4],edx
0082ce1b  8d4df8                            lea    ecx,[ebp-0x8]
0082ce1e  8bd6                              mov    edx,esi
0082ce20  e85b000000                        call   0x82ce80
0082ce25  d94614                            fld    DWORD PTR [esi+0x14]
0082ce28  d84df8                            fmul   DWORD PTR [ebp-0x8]
0082ce2b  e8e01e0d00                        call   0x8fed10
0082ce30  d94618                            fld    DWORD PTR [esi+0x18]
0082ce33  d84dfc                            fmul   DWORD PTR [ebp-0x4]
0082ce36  8bf8                              mov    edi,eax
0082ce38  897df0                            mov    DWORD PTR [ebp-0x10],edi
0082ce3b  e8d01e0d00                        call   0x8fed10
0082ce40  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0082ce43  8945f4                            mov    DWORD PTR [ebp-0xc],eax
0082ce46  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0082ce49  8d45f8                            lea    eax,[ebp-0x8]
0082ce4c  50                                push   eax
0082ce4d  51                                push   ecx
0082ce4e  897df8                            mov    DWORD PTR [ebp-0x8],edi
0082ce51  e84a5f0000                        call   0x832da0
0082ce56  8d55f0                            lea    edx,[ebp-0x10]
0082ce59  52                                push   edx
0082ce5a  53                                push   ebx
0082ce5b  8bf0                              mov    esi,eax
0082ce5d  e83e5f0000                        call   0x832da0
0082ce62  0bf0                              or     esi,eax
0082ce64  f7de                              neg    esi
0082ce66  1bf6                              sbb    esi,esi
0082ce68  5f                                pop    edi
0082ce69  8d4601                            lea    eax,[esi+0x1]
0082ce6c  5e                                pop    esi
0082ce6d  5b                                pop    ebx
0082ce6e  8be5                              mov    esp,ebp
0082ce70  5d                                pop    ebp
0082ce71  c3                                ret
0082ce72  cc                                int3
0082ce73  cc                                int3
0082ce74  cc                                int3
0082ce75  cc                                int3
0082ce76  cc                                int3
0082ce77  cc                                int3
0082ce78  cc                                int3
0082ce79  cc                                int3
0082ce7a  cc                                int3
0082ce7b  cc                                int3
0082ce7c  cc                                int3
0082ce7d  cc                                int3
0082ce7e  cc                                int3
0082ce7f  cc                                int3

# N03-region-scan-and-base-return 0x832da0..0x832ec0
00832da0  55                                push   ebp
00832da1  8bec                              mov    ebp,esp
00832da3  83ec14                            sub    esp,0x14
00832da6  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
00832da9  53                                push   ebx
00832daa  8b5808                            mov    ebx,DWORD PTR [eax+0x8]
00832dad  2b5804                            sub    ebx,DWORD PTR [eax+0x4]
00832db0  33c9                              xor    ecx,ecx
00832db2  c1fb03                            sar    ebx,0x3
00832db5  56                                push   esi
00832db6  57                                push   edi
00832db7  894dfc                            mov    DWORD PTR [ebp-0x4],ecx
00832dba  894df8                            mov    DWORD PTR [ebp-0x8],ecx
00832dbd  3bd9                              cmp    ebx,ecx
00832dbf  7659                              jbe    0x832e1a
00832dc1  837dfc00                          cmp    DWORD PTR [ebp-0x4],0x0
00832dc5  7553                              jne    0x832e1a
00832dc7  8b5004                            mov    edx,DWORD PTR [eax+0x4]
00832dca  833cca00                          cmp    DWORD PTR [edx+ecx*8],0x0
00832dce  8d0cca                            lea    ecx,[edx+ecx*8]
00832dd1  743c                              je     0x832e0f
00832dd3  8b4904                            mov    ecx,DWORD PTR [ecx+0x4]
00832dd6  8b750c                            mov    esi,DWORD PTR [ebp+0xc]
00832dd9  8b16                              mov    edx,DWORD PTR [esi]
00832ddb  8b7908                            mov    edi,DWORD PTR [ecx+0x8]
00832dde  3bd7                              cmp    edx,edi
00832de0  7e2d                              jle    0x832e0f
00832de2  8b7604                            mov    esi,DWORD PTR [esi+0x4]
00832de5  3bf7                              cmp    esi,edi
00832de7  7e26                              jle    0x832e0f
00832de9  3b510c                            cmp    edx,DWORD PTR [ecx+0xc]
00832dec  7d21                              jge    0x832e0f
00832dee  3b7110                            cmp    esi,DWORD PTR [ecx+0x10]
00832df1  7d1c                              jge    0x832e0f
00832df3  2b5104                            sub    edx,DWORD PTR [ecx+0x4]
00832df6  2bf7                              sub    esi,edi
00832df8  8d7918                            lea    edi,[ecx+0x18]
00832dfb  8d45f0                            lea    eax,[ebp-0x10]
00832dfe  8955f0                            mov    DWORD PTR [ebp-0x10],edx
00832e01  8975f4                            mov    DWORD PTR [ebp-0xc],esi
00832e04  e8774d0000                        call   0x837b80
00832e09  8945fc                            mov    DWORD PTR [ebp-0x4],eax
00832e0c  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
00832e0f  8b4df8                            mov    ecx,DWORD PTR [ebp-0x8]
00832e12  41                                inc    ecx
00832e13  894df8                            mov    DWORD PTR [ebp-0x8],ecx
00832e16  3bcb                              cmp    ecx,ebx
00832e18  72a7                              jb     0x832dc1
00832e1a  8b08                              mov    ecx,DWORD PTR [eax]
00832e1c  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
00832e1f  8b33                              mov    esi,DWORD PTR [ebx]
00832e21  8b39                              mov    edi,DWORD PTR [ecx]
00832e23  8bc6                              mov    eax,esi
00832e25  99                                cdq
00832e26  f7ff                              idiv   edi
00832e28  894508                            mov    DWORD PTR [ebp+0x8],eax
00832e2b  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
00832e2e  0faf7d08                          imul   edi,DWORD PTR [ebp+0x8]
00832e32  8b5904                            mov    ebx,DWORD PTR [ecx+0x4]
00832e35  89450c                            mov    DWORD PTR [ebp+0xc],eax
00832e38  99                                cdq
00832e39  f7fb                              idiv   ebx
00832e3b  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
00832e3e  2bf7                              sub    esi,edi
00832e40  8bfe                              mov    edi,esi
00832e42  8b7108                            mov    esi,DWORD PTR [ecx+0x8]
00832e45  0faff0                            imul   esi,eax
00832e48  0fafd8                            imul   ebx,eax
00832e4b  037508                            add    esi,DWORD PTR [ebp+0x8]
00832e4e  2bd3                              sub    edx,ebx
00832e50  c1e604                            shl    esi,0x4
00832e53  037118                            add    esi,DWORD PTR [ecx+0x18]
00832e56  833e00                            cmp    DWORD PTR [esi],0x0
00832e59  740c                              je     0x832e67
00832e5b  8b4604                            mov    eax,DWORD PTR [esi+0x4]
00832e5e  5f                                pop    edi
00832e5f  5e                                pop    esi
00832e60  5b                                pop    ebx
00832e61  8be5                              mov    esp,ebp
00832e63  5d                                pop    ebp
00832e64  c20800                            ret    0x8
00832e67  8b5e0c                            mov    ebx,DWORD PTR [esi+0xc]
00832e6a  0fafda                            imul   ebx,edx
00832e6d  03df                              add    ebx,edi
00832e6f  895d08                            mov    DWORD PTR [ebp+0x8],ebx
00832e72  395e04                            cmp    DWORD PTR [esi+0x4],ebx
00832e75  7f0b                              jg     0x832e82
00832e77  33c0                              xor    eax,eax
00832e79  5f                                pop    edi
00832e7a  5e                                pop    esi
00832e7b  5b                                pop    ebx
00832e7c  8be5                              mov    esp,ebp
00832e7e  5d                                pop    ebp
00832e7f  c20800                            ret    0x8
00832e82  db4508                            fild   DWORD PTR [ebp+0x8]
00832e85  dc0d9056c500                      fmul   QWORD PTR ds:0xc55690
00832e8b  e880be0c00                        call   0x8fed10
00832e90  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
00832e93  2bc8                              sub    ecx,eax
00832e95  0fbe01                            movsx  eax,BYTE PTR [ecx]
00832e98  8bcb                              mov    ecx,ebx
00832e9a  81e107000080                      and    ecx,0x80000007
00832ea0  7905                              jns    0x832ea7
00832ea2  49                                dec    ecx
00832ea3  83c9f8                            or     ecx,0xfffffff8
00832ea6  41                                inc    ecx
00832ea7  b201                              mov    dl,0x1
00832ea9  d2e2                              shl    dl,cl
00832eab  5f                                pop    edi
00832eac  5e                                pop    esi
00832ead  5b                                pop    ebx
00832eae  0fbeca                            movsx  ecx,dl
00832eb1  23c1                              and    eax,ecx
00832eb3  8be5                              mov    esp,ebp
00832eb5  5d                                pop    ebp
00832eb6  c20800                            ret    0x8
00832eb9  cc                                int3
00832eba  cc                                int3
00832ebb  cc                                int3
00832ebc  cc                                int3
00832ebd  cc                                int3
00832ebe  cc                                int3
00832ebf  cc                                int3

# N04-layer-wrapper-factory 0x833280..0x8333d0
00833280  55                                push   ebp
00833281  8bec                              mov    ebp,esp
00833283  83ec18                            sub    esp,0x18
00833286  53                                push   ebx
00833287  56                                push   esi
00833288  57                                push   edi
00833289  6a14                              push   0x14
0083328b  e8d8df0500                        call   0x891268
00833290  33c9                              xor    ecx,ecx
00833292  83c404                            add    esp,0x4
00833295  3bc1                              cmp    eax,ecx
00833297  7413                              je     0x8332ac
00833299  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0083329c  8910                              mov    DWORD PTR [eax],edx
0083329e  894804                            mov    DWORD PTR [eax+0x4],ecx
008332a1  894808                            mov    DWORD PTR [eax+0x8],ecx
008332a4  89480c                            mov    DWORD PTR [eax+0xc],ecx
008332a7  8945f4                            mov    DWORD PTR [ebp-0xc],eax
008332aa  eb03                              jmp    0x8332af
008332ac  894df4                            mov    DWORD PTR [ebp-0xc],ecx
008332af  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
008332b2  8b581c                            mov    ebx,DWORD PTR [eax+0x1c]
008332b5  895df8                            mov    DWORD PTR [ebp-0x8],ebx
008332b8  395820                            cmp    DWORD PTR [eax+0x20],ebx
008332bb  0f84f2000000                      je     0x8333b3
008332c1  8b75f4                            mov    esi,DWORD PTR [ebp-0xc]
008332c4  8b03                              mov    eax,DWORD PTR [ebx]
008332c6  8b7814                            mov    edi,DWORD PTR [eax+0x14]
008332c9  8945f0                            mov    DWORD PTR [ebp-0x10],eax
008332cc  8b4608                            mov    eax,DWORD PTR [esi+0x8]
008332cf  8d4dec                            lea    ecx,[ebp-0x14]
008332d2  897dec                            mov    DWORD PTR [ebp-0x14],edi
008332d5  3bc8                              cmp    ecx,eax
008332d7  736e                              jae    0x833347
008332d9  8b5604                            mov    edx,DWORD PTR [esi+0x4]
008332dc  3bd1                              cmp    edx,ecx
008332de  7767                              ja     0x833347
008332e0  8bf9                              mov    edi,ecx
008332e2  8b4e0c                            mov    ecx,DWORD PTR [esi+0xc]
008332e5  2bfa                              sub    edi,edx
008332e7  c1ff03                            sar    edi,0x3
008332ea  3bc1                              cmp    eax,ecx
008332ec  7541                              jne    0x83332f
008332ee  2bc2                              sub    eax,edx
008332f0  c1f803                            sar    eax,0x3
008332f3  3dfeffff1f                        cmp    eax,0x1ffffffe
008332f8  0f87c1000000                      ja     0x8333bf
008332fe  2bca                              sub    ecx,edx
00833300  40                                inc    eax
00833301  c1f903                            sar    ecx,0x3
00833304  3bc1                              cmp    eax,ecx
00833306  7627                              jbe    0x83332f
00833308  8bd1                              mov    edx,ecx
0083330a  d1ea                              shr    edx,1
0083330c  bbffffff1f                        mov    ebx,0x1fffffff
00833311  2bda                              sub    ebx,edx
00833313  3bd9                              cmp    ebx,ecx
00833315  7304                              jae    0x83331b
00833317  33c9                              xor    ecx,ecx
00833319  eb02                              jmp    0x83331d
0083331b  03ca                              add    ecx,edx
0083331d  3bc8                              cmp    ecx,eax
0083331f  7302                              jae    0x833323
00833321  8bc8                              mov    ecx,eax
00833323  51                                push   ecx
00833324  8d4e04                            lea    ecx,[esi+0x4]
00833327  e80440cbff                        call   0x4e7330
0083332c  8b5df8                            mov    ebx,DWORD PTR [ebp-0x8]
0083332f  8b4608                            mov    eax,DWORD PTR [esi+0x8]
00833332  85c0                              test   eax,eax
00833334  7467                              je     0x83339d
00833336  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
00833339  8b14f9                            mov    edx,DWORD PTR [ecx+edi*8]
0083333c  8910                              mov    DWORD PTR [eax],edx
0083333e  8b4cf904                          mov    ecx,DWORD PTR [ecx+edi*8+0x4]
00833342  894804                            mov    DWORD PTR [eax+0x4],ecx
00833345  eb56                              jmp    0x83339d
00833347  8b4e0c                            mov    ecx,DWORD PTR [esi+0xc]
0083334a  3bc1                              cmp    eax,ecx
0083334c  7540                              jne    0x83338e
0083334e  8b5604                            mov    edx,DWORD PTR [esi+0x4]
00833351  2bc2                              sub    eax,edx
00833353  c1f803                            sar    eax,0x3
00833356  3dfeffff1f                        cmp    eax,0x1ffffffe
0083335b  7762                              ja     0x8333bf
0083335d  2bca                              sub    ecx,edx
0083335f  40                                inc    eax
00833360  c1f903                            sar    ecx,0x3
00833363  3bc1                              cmp    eax,ecx
00833365  7627                              jbe    0x83338e
00833367  8bd1                              mov    edx,ecx
00833369  d1ea                              shr    edx,1
0083336b  bbffffff1f                        mov    ebx,0x1fffffff
00833370  2bda                              sub    ebx,edx
00833372  3bd9                              cmp    ebx,ecx
00833374  7304                              jae    0x83337a
00833376  33c9                              xor    ecx,ecx
00833378  eb02                              jmp    0x83337c
0083337a  03ca                              add    ecx,edx
0083337c  3bc8                              cmp    ecx,eax
0083337e  7302                              jae    0x833382
00833380  8bc8                              mov    ecx,eax
00833382  51                                push   ecx
00833383  8d4e04                            lea    ecx,[esi+0x4]
00833386  e8a53fcbff                        call   0x4e7330
0083338b  8b5df8                            mov    ebx,DWORD PTR [ebp-0x8]
0083338e  8b4608                            mov    eax,DWORD PTR [esi+0x8]
00833391  85c0                              test   eax,eax
00833393  7408                              je     0x83339d
00833395  8b55f0                            mov    edx,DWORD PTR [ebp-0x10]
00833398  8938                              mov    DWORD PTR [eax],edi
0083339a  895004                            mov    DWORD PTR [eax+0x4],edx
0083339d  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
008333a0  83460808                          add    DWORD PTR [esi+0x8],0x8
008333a4  83c304                            add    ebx,0x4
008333a7  895df8                            mov    DWORD PTR [ebp-0x8],ebx
008333aa  395820                            cmp    DWORD PTR [eax+0x20],ebx
008333ad  0f8511ffffff                      jne    0x8332c4
008333b3  8b45f4                            mov    eax,DWORD PTR [ebp-0xc]
008333b6  5f                                pop    edi
008333b7  5e                                pop    esi
008333b8  5b                                pop    ebx
008333b9  8be5                              mov    esp,ebp
008333bb  5d                                pop    ebp
008333bc  c20400                            ret    0x4
008333bf  687823bf00                        push   0xbf2378
008333c4  e867a70400                        call   0x87db30
008333c9  cc                                int3
008333ca  cc                                int3
008333cb  cc                                int3
008333cc  cc                                int3
008333cd  cc                                int3
008333ce  cc                                int3
008333cf  cc                                int3

# N05-region-bitmap-read 0x837b80..0x837be0
00837b80  55                                push   ebp
00837b81  8bec                              mov    ebp,esp
00837b83  51                                push   ecx
00837b84  833f00                            cmp    DWORD PTR [edi],0x0
00837b87  7407                              je     0x837b90
00837b89  8b4704                            mov    eax,DWORD PTR [edi+0x4]
00837b8c  8be5                              mov    esp,ebp
00837b8e  5d                                pop    ebp
00837b8f  c3                                ret
00837b90  56                                push   esi
00837b91  8b7004                            mov    esi,DWORD PTR [eax+0x4]
00837b94  0faf770c                          imul   esi,DWORD PTR [edi+0xc]
00837b98  0330                              add    esi,DWORD PTR [eax]
00837b9a  8975fc                            mov    DWORD PTR [ebp-0x4],esi
00837b9d  397704                            cmp    DWORD PTR [edi+0x4],esi
00837ba0  7f07                              jg     0x837ba9
00837ba2  33c0                              xor    eax,eax
00837ba4  5e                                pop    esi
00837ba5  8be5                              mov    esp,ebp
00837ba7  5d                                pop    ebp
00837ba8  c3                                ret
00837ba9  db45fc                            fild   DWORD PTR [ebp-0x4]
00837bac  dc0d9056c500                      fmul   QWORD PTR ds:0xc55690
00837bb2  e859710c00                        call   0x8fed10
00837bb7  8b4f08                            mov    ecx,DWORD PTR [edi+0x8]
00837bba  2bc8                              sub    ecx,eax
00837bbc  0fbe01                            movsx  eax,BYTE PTR [ecx]
00837bbf  8bce                              mov    ecx,esi
00837bc1  81e107000080                      and    ecx,0x80000007
00837bc7  7905                              jns    0x837bce
00837bc9  49                                dec    ecx
00837bca  83c9f8                            or     ecx,0xfffffff8
00837bcd  41                                inc    ecx
00837bce  b201                              mov    dl,0x1
00837bd0  d2e2                              shl    dl,cl
00837bd2  5e                                pop    esi
00837bd3  0fbeca                            movsx  ecx,dl
00837bd6  23c1                              and    eax,ecx
00837bd8  8be5                              mov    esp,ebp
00837bda  5d                                pop    ebp
00837bdb  c3                                ret
00837bdc  cc                                int3
00837bdd  cc                                int3
00837bde  cc                                int3
00837bdf  cc                                int3

# N06-bound-owner-lifetime 0x82cbc0..0x82cdf0
0082cbc0  55                                push   ebp
0082cbc1  8bec                              mov    ebp,esp
0082cbc3  6aff                              push   0xffffffff
0082cbc5  6828719000                        push   0x907128
0082cbca  64a100000000                      mov    eax,fs:0x0
0082cbd0  50                                push   eax
0082cbd1  83ec0c                            sub    esp,0xc
0082cbd4  53                                push   ebx
0082cbd5  56                                push   esi
0082cbd6  a1201fd600                        mov    eax,ds:0xd61f20
0082cbdb  33c5                              xor    eax,ebp
0082cbdd  50                                push   eax
0082cbde  8d45f4                            lea    eax,[ebp-0xc]
0082cbe1  64a300000000                      mov    fs:0x0,eax
0082cbe7  33c9                              xor    ecx,ecx
0082cbe9  894dfc                            mov    DWORD PTR [ebp-0x4],ecx
0082cbec  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0082cbef  c70701000000                      mov    DWORD PTR [edi],0x1
0082cbf5  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0082cbf8  895704                            mov    DWORD PTR [edi+0x4],edx
0082cbfb  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0082cbfe  895708                            mov    DWORD PTR [edi+0x8],edx
0082cc01  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0082cc04  89570c                            mov    DWORD PTR [edi+0xc],edx
0082cc07  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0082cc0a  895710                            mov    DWORD PTR [edi+0x10],edx
0082cc0d  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0082cc10  8d771c                            lea    esi,[edi+0x1c]
0082cc13  890e                              mov    DWORD PTR [esi],ecx
0082cc15  894e04                            mov    DWORD PTR [esi+0x4],ecx
0082cc18  8bda                              mov    ebx,edx
0082cc1a  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0082cc1d  3bd1                              cmp    edx,ecx
0082cc1f  7416                              je     0x82cc37
0082cc21  e82af6c4ff                        call   0x47c250
0082cc26  84c0                              test   al,al
0082cc28  740a                              je     0x82cc34
0082cc2a  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0082cc2d  53                                push   ebx
0082cc2e  50                                push   eax
0082cc2f  e88c65f7ff                        call   0x7a31c0
0082cc34  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0082cc37  db4704                            fild   DWORD PTR [edi+0x4]
0082cc3a  d8770c                            fdiv   DWORD PTR [edi+0xc]
0082cc3d  d95df0                            fstp   DWORD PTR [ebp-0x10]
0082cc40  db4708                            fild   DWORD PTR [edi+0x8]
0082cc43  d87710                            fdiv   DWORD PTR [edi+0x10]
0082cc46  d95de8                            fstp   DWORD PTR [ebp-0x18]
0082cc49  d945f0                            fld    DWORD PTR [ebp-0x10]
0082cc4c  d95dec                            fstp   DWORD PTR [ebp-0x14]
0082cc4f  d945e8                            fld    DWORD PTR [ebp-0x18]
0082cc52  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0082cc55  d95df0                            fstp   DWORD PTR [ebp-0x10]
0082cc58  894f14                            mov    DWORD PTR [edi+0x14],ecx
0082cc5b  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0082cc5e  894718                            mov    DWORD PTR [edi+0x18],eax
0082cc61  33c0                              xor    eax,eax
0082cc63  894724                            mov    DWORD PTR [edi+0x24],eax
0082cc66  894728                            mov    DWORD PTR [edi+0x28],eax
0082cc69  89472c                            mov    DWORD PTR [edi+0x2c],eax
0082cc6c  894730                            mov    DWORD PTR [edi+0x30],eax
0082cc6f  894734                            mov    DWORD PTR [edi+0x34],eax
0082cc72  894738                            mov    DWORD PTR [edi+0x38],eax
0082cc75  89473c                            mov    DWORD PTR [edi+0x3c],eax
0082cc78  894740                            mov    DWORD PTR [edi+0x40],eax
0082cc7b  894744                            mov    DWORD PTR [edi+0x44],eax
0082cc7e  894748                            mov    DWORD PTR [edi+0x48],eax
0082cc81  89474c                            mov    DWORD PTR [edi+0x4c],eax
0082cc84  894750                            mov    DWORD PTR [edi+0x50],eax
0082cc87  894754                            mov    DWORD PTR [edi+0x54],eax
0082cc8a  894758                            mov    DWORD PTR [edi+0x58],eax
0082cc8d  89475c                            mov    DWORD PTR [edi+0x5c],eax
0082cc90  894760                            mov    DWORD PTR [edi+0x60],eax
0082cc93  894764                            mov    DWORD PTR [edi+0x64],eax
0082cc96  894768                            mov    DWORD PTR [edi+0x68],eax
0082cc99  89476c                            mov    DWORD PTR [edi+0x6c],eax
0082cc9c  894770                            mov    DWORD PTR [edi+0x70],eax
0082cc9f  894774                            mov    DWORD PTR [edi+0x74],eax
0082cca2  894778                            mov    DWORD PTR [edi+0x78],eax
0082cca5  89477c                            mov    DWORD PTR [edi+0x7c],eax
0082cca8  898780000000                      mov    DWORD PTR [edi+0x80],eax
0082ccae  898784000000                      mov    DWORD PTR [edi+0x84],eax
0082ccb4  898788000000                      mov    DWORD PTR [edi+0x88],eax
0082ccba  89878c000000                      mov    DWORD PTR [edi+0x8c],eax
0082ccc0  898790000000                      mov    DWORD PTR [edi+0x90],eax
0082ccc6  898794000000                      mov    DWORD PTR [edi+0x94],eax
0082cccc  898798000000                      mov    DWORD PTR [edi+0x98],eax
0082ccd2  89879c000000                      mov    DWORD PTR [edi+0x9c],eax
0082ccd8  8987a0000000                      mov    DWORD PTR [edi+0xa0],eax
0082ccde  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0082cce5  85d2                              test   edx,edx
0082cce7  742b                              je     0x82cd14
0082cce9  8bf2                              mov    esi,edx
0082cceb  83c204                            add    edx,0x4
0082ccee  83c9ff                            or     ecx,0xffffffff
0082ccf1  f00fc10a                          lock xadd DWORD PTR [edx],ecx
0082ccf5  751d                              jne    0x82cd14
0082ccf7  8b16                              mov    edx,DWORD PTR [esi]
0082ccf9  8b02                              mov    eax,DWORD PTR [edx]
0082ccfb  8bce                              mov    ecx,esi
0082ccfd  ffd0                              call   eax
0082ccff  8d4e08                            lea    ecx,[esi+0x8]
0082cd02  83caff                            or     edx,0xffffffff
0082cd05  f00fc111                          lock xadd DWORD PTR [ecx],edx
0082cd09  7509                              jne    0x82cd14
0082cd0b  8b06                              mov    eax,DWORD PTR [esi]
0082cd0d  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0082cd10  8bce                              mov    ecx,esi
0082cd12  ffd2                              call   edx
0082cd14  8bc7                              mov    eax,edi
0082cd16  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0082cd19  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0082cd20  59                                pop    ecx
0082cd21  5e                                pop    esi
0082cd22  5b                                pop    ebx
0082cd23  8be5                              mov    esp,ebp
0082cd25  5d                                pop    ebp
0082cd26  c20800                            ret    0x8
0082cd29  cc                                int3
0082cd2a  cc                                int3
0082cd2b  cc                                int3
0082cd2c  cc                                int3
0082cd2d  cc                                int3
0082cd2e  cc                                int3
0082cd2f  cc                                int3
0082cd30  55                                push   ebp
0082cd31  8bec                              mov    ebp,esp
0082cd33  53                                push   ebx
0082cd34  56                                push   esi
0082cd35  57                                push   edi
0082cd36  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0082cd39  83c724                            add    edi,0x24
0082cd3c  bb20000000                        mov    ebx,0x20
0082cd41  8b37                              mov    esi,DWORD PTR [edi]
0082cd43  85f6                              test   esi,esi
0082cd45  740b                              je     0x82cd52
0082cd47  e854000000                        call   0x82cda0
0082cd4c  c70700000000                      mov    DWORD PTR [edi],0x0
0082cd52  83c704                            add    edi,0x4
0082cd55  4b                                dec    ebx
0082cd56  75e9                              jne    0x82cd41
0082cd58  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0082cd5b  8b7020                            mov    esi,DWORD PTR [eax+0x20]
0082cd5e  85f6                              test   esi,esi
0082cd60  7429                              je     0x82cd8b
0082cd62  8d4e04                            lea    ecx,[esi+0x4]
0082cd65  83caff                            or     edx,0xffffffff
0082cd68  f00fc111                          lock xadd DWORD PTR [ecx],edx
0082cd6c  751d                              jne    0x82cd8b
0082cd6e  8b06                              mov    eax,DWORD PTR [esi]
0082cd70  8b10                              mov    edx,DWORD PTR [eax]
0082cd72  8bce                              mov    ecx,esi
0082cd74  ffd2                              call   edx
0082cd76  8d4608                            lea    eax,[esi+0x8]
0082cd79  83c9ff                            or     ecx,0xffffffff
0082cd7c  f00fc108                          lock xadd DWORD PTR [eax],ecx
0082cd80  7509                              jne    0x82cd8b
0082cd82  8b16                              mov    edx,DWORD PTR [esi]
0082cd84  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0082cd87  8bce                              mov    ecx,esi
0082cd89  ffd0                              call   eax
0082cd8b  5f                                pop    edi
0082cd8c  5e                                pop    esi
0082cd8d  5b                                pop    ebx
0082cd8e  5d                                pop    ebp
0082cd8f  c20400                            ret    0x4
0082cd92  cc                                int3
0082cd93  cc                                int3
0082cd94  cc                                int3
0082cd95  cc                                int3
0082cd96  cc                                int3
0082cd97  cc                                int3
0082cd98  cc                                int3
0082cd99  cc                                int3
0082cd9a  cc                                int3
0082cd9b  cc                                int3
0082cd9c  cc                                int3
0082cd9d  cc                                int3
0082cd9e  cc                                int3
0082cd9f  cc                                int3
0082cda0  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
0082cda3  8b5608                            mov    edx,DWORD PTR [esi+0x8]
0082cda6  57                                push   edi
0082cda7  3bca                              cmp    ecx,edx
0082cda9  741d                              je     0x82cdc8
0082cdab  8bc2                              mov    eax,edx
0082cdad  3bd2                              cmp    edx,edx
0082cdaf  7414                              je     0x82cdc5
0082cdb1  8b38                              mov    edi,DWORD PTR [eax]
0082cdb3  8939                              mov    DWORD PTR [ecx],edi
0082cdb5  8b7804                            mov    edi,DWORD PTR [eax+0x4]
0082cdb8  897904                            mov    DWORD PTR [ecx+0x4],edi
0082cdbb  83c008                            add    eax,0x8
0082cdbe  83c108                            add    ecx,0x8
0082cdc1  3bc2                              cmp    eax,edx
0082cdc3  75ec                              jne    0x82cdb1
0082cdc5  894e08                            mov    DWORD PTR [esi+0x8],ecx
0082cdc8  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0082cdcb  33ff                              xor    edi,edi
0082cdcd  3bc7                              cmp    eax,edi
0082cdcf  7409                              je     0x82cdda
0082cdd1  50                                push   eax
0082cdd2  e835440600                        call   0x89120c
0082cdd7  83c404                            add    esp,0x4
0082cdda  56                                push   esi
0082cddb  897e04                            mov    DWORD PTR [esi+0x4],edi
0082cdde  897e08                            mov    DWORD PTR [esi+0x8],edi
0082cde1  897e0c                            mov    DWORD PTR [esi+0xc],edi
0082cde4  e823440600                        call   0x89120c
0082cde9  83c404                            add    esp,0x4
0082cdec  8bc6                              mov    eax,esi
0082cdee  5f                                pop    edi
0082cdef  c3                                ret

# N07-bound-wrapper-install 0x82ff10..0x830040
0082ff10  55                                push   ebp
0082ff11  8bec                              mov    ebp,esp
0082ff13  6aff                              push   0xffffffff
0082ff15  6843949000                        push   0x909443
0082ff1a  64a100000000                      mov    eax,fs:0x0
0082ff20  50                                push   eax
0082ff21  83ec0c                            sub    esp,0xc
0082ff24  53                                push   ebx
0082ff25  56                                push   esi
0082ff26  57                                push   edi
0082ff27  a1201fd600                        mov    eax,ds:0xd61f20
0082ff2c  33c5                              xor    eax,ebp
0082ff2e  50                                push   eax
0082ff2f  8d45f4                            lea    eax,[ebp-0xc]
0082ff32  64a300000000                      mov    fs:0x0,eax
0082ff38  33ff                              xor    edi,edi
0082ff3a  68a4000000                        push   0xa4
0082ff3f  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0082ff42  e821130600                        call   0x891268
0082ff47  83c404                            add    esp,0x4
0082ff4a  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0082ff4d  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0082ff51  3bc7                              cmp    eax,edi
0082ff53  7438                              je     0x82ff8d
0082ff55  83ec08                            sub    esp,0x8
0082ff58  8bf4                              mov    esi,esp
0082ff5a  893e                              mov    DWORD PTR [esi],edi
0082ff5c  897e04                            mov    DWORD PTR [esi+0x4],edi
0082ff5f  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0082ff62  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0082ff65  8965e8                            mov    DWORD PTR [ebp-0x18],esp
0082ff68  8bda                              mov    ebx,edx
0082ff6a  85d2                              test   edx,edx
0082ff6c  7410                              je     0x82ff7e
0082ff6e  e8ddc2c4ff                        call   0x47c250
0082ff73  84c0                              test   al,al
0082ff75  7407                              je     0x82ff7e
0082ff77  53                                push   ebx
0082ff78  57                                push   edi
0082ff79  e84232f7ff                        call   0x7a31c0
0082ff7e  8b7dec                            mov    edi,DWORD PTR [ebp-0x14]
0082ff81  e83accffff                        call   0x82cbc0
0082ff86  8bd8                              mov    ebx,eax
0082ff88  895df0                            mov    DWORD PTR [ebp-0x10],ebx
0082ff8b  eb05                              jmp    0x82ff92
0082ff8d  897df0                            mov    DWORD PTR [ebp-0x10],edi
0082ff90  8bdf                              mov    ebx,edi
0082ff92  b9f8ffffff                        mov    ecx,0xfffffff8
0082ff97  2bcb                              sub    ecx,ebx
0082ff99  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0082ff9d  8d7b24                            lea    edi,[ebx+0x24]
0082ffa0  894de8                            mov    DWORD PTR [ebp-0x18],ecx
0082ffa3  c745ec20000000                    mov    DWORD PTR [ebp-0x14],0x20
0082ffaa  8d9b00000000                      lea    ebx,[ebx+0x0]
0082ffb0  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0082ffb3  8d0439                            lea    eax,[ecx+edi*1]
0082ffb6  833c1000                          cmp    DWORD PTR [eax+edx*1],0x0
0082ffba  7424                              je     0x82ffe0
0082ffbc  8b0410                            mov    eax,DWORD PTR [eax+edx*1]
0082ffbf  50                                push   eax
0082ffc0  e8bb320000                        call   0x833280
0082ffc5  8b37                              mov    esi,DWORD PTR [edi]
0082ffc7  8bd8                              mov    ebx,eax
0082ffc9  85f6                              test   esi,esi
0082ffcb  740b                              je     0x82ffd8
0082ffcd  e8cecdffff                        call   0x82cda0
0082ffd2  c70700000000                      mov    DWORD PTR [edi],0x0
0082ffd8  8b4de8                            mov    ecx,DWORD PTR [ebp-0x18]
0082ffdb  891f                              mov    DWORD PTR [edi],ebx
0082ffdd  8b5df0                            mov    ebx,DWORD PTR [ebp-0x10]
0082ffe0  83c704                            add    edi,0x4
0082ffe3  ff4dec                            dec    DWORD PTR [ebp-0x14]
0082ffe6  75c8                              jne    0x82ffb0
0082ffe8  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0082ffef  8b750c                            mov    esi,DWORD PTR [ebp+0xc]
0082fff2  85f6                              test   esi,esi
0082fff4  7429                              je     0x83001f
0082fff6  8d4e04                            lea    ecx,[esi+0x4]
0082fff9  83caff                            or     edx,0xffffffff
0082fffc  f00fc111                          lock xadd DWORD PTR [ecx],edx
00830000  751d                              jne    0x83001f
00830002  8b06                              mov    eax,DWORD PTR [esi]
00830004  8b10                              mov    edx,DWORD PTR [eax]
00830006  8bce                              mov    ecx,esi
00830008  ffd2                              call   edx
0083000a  8d4608                            lea    eax,[esi+0x8]
0083000d  83c9ff                            or     ecx,0xffffffff
00830010  f00fc108                          lock xadd DWORD PTR [eax],ecx
00830014  7509                              jne    0x83001f
00830016  8b16                              mov    edx,DWORD PTR [esi]
00830018  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0083001b  8bce                              mov    ecx,esi
0083001d  ffd0                              call   eax
0083001f  8bc3                              mov    eax,ebx
00830021  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
00830024  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0083002b  59                                pop    ecx
0083002c  5f                                pop    edi
0083002d  5e                                pop    esi
0083002e  5b                                pop    ebx
0083002f  8be5                              mov    esp,ebp
00830031  5d                                pop    ebp
00830032  c3                                ret
00830033  cc                                int3
00830034  cc                                int3
00830035  cc                                int3
00830036  cc                                int3
00830037  cc                                int3
00830038  cc                                int3
00830039  cc                                int3
0083003a  cc                                int3
0083003b  cc                                int3
0083003c  cc                                int3
0083003d  cc                                int3
0083003e  cc                                int3
0083003f  cc                                int3

# N08-player-probes 0x545f30..0x546100
00545f30  55                                push   ebp
00545f31  8bec                              mov    ebp,esp
00545f33  83e4f8                            and    esp,0xfffffff8
00545f36  6aff                              push   0xffffffff
00545f38  680e8a9300                        push   0x938a0e
00545f3d  64a100000000                      mov    eax,fs:0x0
00545f43  50                                push   eax
00545f44  83ec20                            sub    esp,0x20
00545f47  53                                push   ebx
00545f48  56                                push   esi
00545f49  57                                push   edi
00545f4a  a1201fd600                        mov    eax,ds:0xd61f20
00545f4f  33c4                              xor    eax,esp
00545f51  50                                push   eax
00545f52  8d442430                          lea    eax,[esp+0x30]
00545f56  64a300000000                      mov    fs:0x0,eax
00545f5c  8bf1                              mov    esi,ecx
00545f5e  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
00545f65  7521                              jne    0x545f88
00545f67  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
00545f6e  c744243800000000                  mov    DWORD PTR [esp+0x38],0x0
00545f76  e8158df9ff                        call   0x4dec90
00545f7b  6830cebc00                        push   0xbcce30
00545f80  e895c33400                        call   0x89231a
00545f85  83c404                            add    esp,0x4
00545f88  8b0dd0b1fa00                      mov    ecx,DWORD PTR ds:0xfab1d0
00545f8e  894c2410                          mov    DWORD PTR [esp+0x10],ecx
00545f92  85c9                              test   ecx,ecx
00545f94  0f844a010000                      je     0x5460e4
00545f9a  f30f10450c                        movss  xmm0,DWORD PTR [ebp+0xc]
00545f9f  0f2e056c56c500                    ucomiss xmm0,DWORD PTR ds:0xc5566c
00545fa6  9f                                lahf
00545fa7  f6c444                            test   ah,0x44
00545faa  7a21                              jp     0x545fcd
00545fac  8bc6                              mov    eax,esi
00545fae  e83d6e2e00                        call   0x82cdf0
00545fb3  f7d8                              neg    eax
00545fb5  1bc0                              sbb    eax,eax
00545fb7  40                                inc    eax
00545fb8  8b4c2430                          mov    ecx,DWORD PTR [esp+0x30]
00545fbc  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00545fc3  59                                pop    ecx
00545fc4  5f                                pop    edi
00545fc5  5e                                pop    esi
00545fc6  5b                                pop    ebx
00545fc7  8be5                              mov    esp,ebp
00545fc9  5d                                pop    ebp
00545fca  c20800                            ret    0x8
00545fcd  8b1d187cfb00                      mov    ebx,DWORD PTR ds:0xfb7c18
00545fd3  8b06                              mov    eax,DWORD PTR [esi]
00545fd5  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
00545fd8  89442414                          mov    DWORD PTR [esp+0x14],eax
00545fdc  894c2418                          mov    DWORD PTR [esp+0x18],ecx
00545fe0  f6c301                            test   bl,0x1
00545fe3  750e                              jne    0x545ff3
00545fe5  83cb01                            or     ebx,0x1
00545fe8  891d187cfb00                      mov    DWORD PTR ds:0xfb7c18,ebx
00545fee  e8dde9efff                        call   0x4449d0
00545ff3  0fb67d08                          movzx  edi,BYTE PTR [ebp+0x8]
00545ff7  d9450c                            fld    DWORD PTR [ebp+0xc]
00545ffa  d9c0                              fld    st(0)
00545ffc  33f6                              xor    esi,esi
00545ffe  d80cfd2080fb00                    fmul   DWORD PTR [edi*8+0xfb8020]
00546005  d95c241c                          fstp   DWORD PTR [esp+0x1c]
00546009  d80cfd2480fb00                    fmul   DWORD PTR [edi*8+0xfb8024]
00546010  d95c2420                          fstp   DWORD PTR [esp+0x20]
00546014  d944241c                          fld    DWORD PTR [esp+0x1c]
00546018  dd052857c500                      fld    QWORD PTR ds:0xc55728
0054601e  dcc9                              fmul   st(1),st
00546020  d9c9                              fxch   st(1)
00546022  d95c2424                          fstp   DWORD PTR [esp+0x24]
00546026  d84c2420                          fmul   DWORD PTR [esp+0x20]
0054602a  d95c2428                          fstp   DWORD PTR [esp+0x28]
0054602e  d9442424                          fld    DWORD PTR [esp+0x24]
00546032  d8442414                          fadd   DWORD PTR [esp+0x14]
00546036  d95c2414                          fstp   DWORD PTR [esp+0x14]
0054603a  d9442418                          fld    DWORD PTR [esp+0x18]
0054603e  d8442428                          fadd   DWORD PTR [esp+0x28]
00546042  d95c2418                          fstp   DWORD PTR [esp+0x18]
00546046  eb08                              jmp    0x546050
00546048  8da42400000000                    lea    esp,[esp+0x0]
0054604f  90                                nop
00546050  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
00546054  8d442414                          lea    eax,[esp+0x14]
00546058  e8936d2e00                        call   0x82cdf0
0054605d  85c0                              test   eax,eax
0054605f  747d                              je     0x5460de
00546061  f6c301                            test   bl,0x1
00546064  7508                              jne    0x54606e
00546066  83cb01                            or     ebx,0x1
00546069  e862e9efff                        call   0x4449d0
0054606e  d9450c                            fld    DWORD PTR [ebp+0xc]
00546071  46                                inc    esi
00546072  d9c0                              fld    st(0)
00546074  d80cfd2080fb00                    fmul   DWORD PTR [edi*8+0xfb8020]
0054607b  d95c2424                          fstp   DWORD PTR [esp+0x24]
0054607f  d80cfd2480fb00                    fmul   DWORD PTR [edi*8+0xfb8024]
00546086  d95c2428                          fstp   DWORD PTR [esp+0x28]
0054608a  d9442424                          fld    DWORD PTR [esp+0x24]
0054608e  dd059858c500                      fld    QWORD PTR ds:0xc55898
00546094  dcc9                              fmul   st(1),st
00546096  d9c9                              fxch   st(1)
00546098  d95c241c                          fstp   DWORD PTR [esp+0x1c]
0054609c  d84c2428                          fmul   DWORD PTR [esp+0x28]
005460a0  d95c2420                          fstp   DWORD PTR [esp+0x20]
005460a4  d944241c                          fld    DWORD PTR [esp+0x1c]
005460a8  d8442414                          fadd   DWORD PTR [esp+0x14]
005460ac  d95c2414                          fstp   DWORD PTR [esp+0x14]
005460b0  d9442420                          fld    DWORD PTR [esp+0x20]
005460b4  d8442418                          fadd   DWORD PTR [esp+0x18]
005460b8  d95c2418                          fstp   DWORD PTR [esp+0x18]
005460bc  83fe03                            cmp    esi,0x3
005460bf  7c8f                              jl     0x546050
005460c1  891d187cfb00                      mov    DWORD PTR ds:0xfb7c18,ebx
005460c7  33c0                              xor    eax,eax
005460c9  8b4c2430                          mov    ecx,DWORD PTR [esp+0x30]
005460cd  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
005460d4  59                                pop    ecx
005460d5  5f                                pop    edi
005460d6  5e                                pop    esi
005460d7  5b                                pop    ebx
005460d8  8be5                              mov    esp,ebp
005460da  5d                                pop    ebp
005460db  c20800                            ret    0x8
005460de  891d187cfb00                      mov    DWORD PTR ds:0xfb7c18,ebx
005460e4  b801000000                        mov    eax,0x1
005460e9  8b4c2430                          mov    ecx,DWORD PTR [esp+0x30]
005460ed  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
005460f4  59                                pop    ecx
005460f5  5f                                pop    edi
005460f6  5e                                pop    esi
005460f7  5b                                pop    ebx
005460f8  8be5                              mov    esp,ebp
005460fa  5d                                pop    ebp
005460fb  c20800                            ret    0x8
005460fe  cc                                int3
005460ff  cc                                int3

# N09-player-movement-consumer 0x546100..0x5464c0
00546100  55                                push   ebp
00546101  8bec                              mov    ebp,esp
00546103  83e4f8                            and    esp,0xfffffff8
00546106  6aff                              push   0xffffffff
00546108  686cfe9300                        push   0x93fe6c
0054610d  64a100000000                      mov    eax,fs:0x0
00546113  50                                push   eax
00546114  83ec28                            sub    esp,0x28
00546117  53                                push   ebx
00546118  56                                push   esi
00546119  57                                push   edi
0054611a  a1201fd600                        mov    eax,ds:0xd61f20
0054611f  33c4                              xor    eax,esp
00546121  50                                push   eax
00546122  8d442438                          lea    eax,[esp+0x38]
00546126  64a300000000                      mov    fs:0x0,eax
0054612c  894c2418                          mov    DWORD PTR [esp+0x18],ecx
00546130  833daca7fb0003                    cmp    DWORD PTR ds:0xfba7ac,0x3
00546137  8b790c                            mov    edi,DWORD PTR [ecx+0xc]
0054613a  c644241700                        mov    BYTE PTR [esp+0x17],0x0
0054613f  750a                              jne    0x54614b
00546141  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
00546144  8d444003                          lea    eax,[eax+eax*2+0x3]
00546148  8b3c81                            mov    edi,DWORD PTR [ecx+eax*4]
0054614b  33f6                              xor    esi,esi
0054614d  3bfe                              cmp    edi,esi
0054614f  7520                              jne    0x546171
00546151  89717c                            mov    DWORD PTR [ecx+0x7c],esi
00546154  89b180000000                      mov    DWORD PTR [ecx+0x80],esi
0054615a  32c0                              xor    al,al
0054615c  8b4c2438                          mov    ecx,DWORD PTR [esp+0x38]
00546160  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00546167  59                                pop    ecx
00546168  5f                                pop    edi
00546169  5e                                pop    esi
0054616a  5b                                pop    ebx
0054616b  8be5                              mov    esp,ebp
0054616d  5d                                pop    ebp
0054616e  c20800                            ret    0x8
00546171  0fb687e4000000                    movzx  eax,BYTE PTR [edi+0xe4]
00546178  8b97e0000000                      mov    edx,DWORD PTR [edi+0xe0]
0054617e  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
00546181  88442430                          mov    BYTE PTR [esp+0x30],al
00546185  33c0                              xor    eax,eax
00546187  8954242c                          mov    DWORD PTR [esp+0x2c],edx
0054618b  8a97b0000000                      mov    dl,BYTE PTR [edi+0xb0]
00546191  66894302                          mov    WORD PTR [ebx+0x2],ax
00546195  8a87b0000000                      mov    al,BYTE PTR [edi+0xb0]
0054619b  884304                            mov    BYTE PTR [ebx+0x4],al
0054619e  8b8758010000                      mov    eax,DWORD PTR [edi+0x158]
005461a4  8854241c                          mov    BYTE PTR [esp+0x1c],dl
005461a8  89742420                          mov    DWORD PTR [esp+0x20],esi
005461ac  3bc6                              cmp    eax,esi
005461ae  7405                              je     0x5461b5
005461b0  397034                            cmp    DWORD PTR [eax+0x34],esi
005461b3  7409                              je     0x5461be
005461b5  89717c                            mov    DWORD PTR [ecx+0x7c],esi
005461b8  89b180000000                      mov    DWORD PTR [ecx+0x80],esi
005461be  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
005461c5  89742428                          mov    DWORD PTR [esp+0x28],esi
005461c9  7525                              jne    0x5461f0
005461cb  830d9043f90001                    or     DWORD PTR ds:0xf94390,0x1
005461d2  89742440                          mov    DWORD PTR [esp+0x40],esi
005461d6  e8b5b3f9ff                        call   0x4e1590
005461db  6880ccbc00                        push   0xbccc80
005461e0  e835c13400                        call   0x89231a
005461e5  83c404                            add    esp,0x4
005461e8  c7442440ffffffff                  mov    DWORD PTR [esp+0x40],0xffffffff
005461f0  0fb78788000000                    movzx  eax,WORD PTR [edi+0x88]
005461f7  8b0d0443f900                      mov    ecx,DWORD PTR ds:0xf94304
005461fd  83f809                            cmp    eax,0x9
00546200  0f8754ffffff                      ja     0x54615a
00546206  69c010020000                      imul   eax,eax,0x210
0054620c  03c1                              add    eax,ecx
0054620e  39705c                            cmp    DWORD PTR [eax+0x5c],esi
00546211  0f8443ffffff                      je     0x54615a
00546217  3bc6                              cmp    eax,esi
00546219  0f843bffffff                      je     0x54615a
0054621f  05f4010000                        add    eax,0x1f4
00546224  89442424                          mov    DWORD PTR [esp+0x24],eax
00546228  3bc6                              cmp    eax,esi
0054622a  0f842affffff                      je     0x54615a
00546230  8b8758010000                      mov    eax,DWORD PTR [edi+0x158]
00546236  85c0                              test   eax,eax
00546238  7403                              je     0x54623d
0054623a  8b702c                            mov    esi,DWORD PTR [eax+0x2c]
0054623d  8bcf                              mov    ecx,edi
0054623f  e88c3cf8ff                        call   0x4c9ed0
00546244  85f6                              test   esi,esi
00546246  0f84ba000000                      je     0x546306
0054624c  85c0                              test   eax,eax
0054624e  0f85b2000000                      jne    0x546306
00546254  8b442418                          mov    eax,DWORD PTR [esp+0x18]
00546258  8d4c2420                          lea    ecx,[esp+0x20]
0054625c  51                                push   ecx
0054625d  8d542420                          lea    edx,[esp+0x20]
00546261  52                                push   edx
00546262  57                                push   edi
00546263  e818050000                        call   0x546780
00546268  89442428                          mov    DWORD PTR [esp+0x28],eax
0054626c  e8efe6efff                        call   0x444960
00546271  80b8ef07000001                    cmp    BYTE PTR [eax+0x7ef],0x1
00546278  750c                              jne    0x546286
0054627a  b800010000                        mov    eax,0x100
0054627f  c644241701                        mov    BYTE PTR [esp+0x17],0x1
00546284  eb09                              jmp    0x54628f
00546286  8b442420                          mov    eax,DWORD PTR [esp+0x20]
0054628a  6685c0                            test   ax,ax
0054628d  7413                              je     0x5462a2
0054628f  668b4b02                          mov    cx,WORD PTR [ebx+0x2]
00546293  6633c8                            xor    cx,ax
00546296  baff7f0000                        mov    edx,0x7fff
0054629b  6623ca                            and    cx,dx
0054629e  66314b02                          xor    WORD PTR [ebx+0x2],cx
005462a2  833daca7fb0001                    cmp    DWORD PTR ds:0xfba7ac,0x1
005462a9  745b                              je     0x546306
005462ab  6685c0                            test   ax,ax
005462ae  7456                              je     0x546306
005462b0  8b742424                          mov    esi,DWORD PTR [esp+0x24]
005462b4  8b8fe8030000                      mov    ecx,DWORD PTR [edi+0x3e8]
005462ba  33d2                              xor    edx,edx
005462bc  385602                            cmp    BYTE PTR [esi+0x2],dl
005462bf  51                                push   ecx
005462c0  0f95c2                            setne  dl
005462c3  8a1432                            mov    dl,BYTE PTR [edx+esi*1]
005462c6  88542428                          mov    BYTE PTR [esp+0x28],dl
005462ca  8b4c2428                          mov    ecx,DWORD PTR [esp+0x28]
005462ce  51                                push   ecx
005462cf  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
005462d2  8d1449                            lea    edx,[ecx+ecx*2]
005462d5  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
005462d9  8b4c9110                          mov    ecx,DWORD PTR [ecx+edx*4+0x10]
005462dd  e88e8f0000                        call   0x54f270
005462e2  85c0                              test   eax,eax
005462e4  7407                              je     0x5462ed
005462e6  c644241701                        mov    BYTE PTR [esp+0x17],0x1
005462eb  eb19                              jmp    0x546306
005462ed  83bfe803000000                    cmp    DWORD PTR [edi+0x3e8],0x0
005462f4  7407                              je     0x5462fd
005462f6  c644241701                        mov    BYTE PTR [esp+0x17],0x1
005462fb  eb09                              jmp    0x546306
005462fd  ba00800000                        mov    edx,0x8000
00546302  66215302                          and    WORD PTR [ebx+0x2],dx
00546306  f605147cfb0001                    test   BYTE PTR ds:0xfb7c14,0x1
0054630d  7529                              jne    0x546338
0054630f  b801000000                        mov    eax,0x1
00546314  0905147cfb00                      or     DWORD PTR ds:0xfb7c14,eax
0054631a  89442440                          mov    DWORD PTR [esp+0x40],eax
0054631e  e82da41800                        call   0x6d0750
00546323  6830d5bc00                        push   0xbcd530
00546328  e8edbf3400                        call   0x89231a
0054632d  83c404                            add    esp,0x4
00546330  c7442440ffffffff                  mov    DWORD PTR [esp+0x40],0xffffffff
00546338  33c0                              xor    eax,eax
0054633a  38050990fb00                      cmp    BYTE PTR ds:0xfb9009,al
00546340  0f94c0                            sete   al
00546343  8bf0                              mov    esi,eax
00546345  8b8758010000                      mov    eax,DWORD PTR [edi+0x158]
0054634b  85c0                              test   eax,eax
0054634d  0f8429010000                      je     0x54647c
00546353  83783000                          cmp    DWORD PTR [eax+0x30],0x0
00546357  0f841f010000                      je     0x54647c
0054635d  8bcf                              mov    ecx,edi
0054635f  e86c3bf8ff                        call   0x4c9ed0
00546364  85c0                              test   eax,eax
00546366  0f8510010000                      jne    0x54647c
0054636c  85f6                              test   esi,esi
0054636e  0f8408010000                      je     0x54647c
00546374  8a4c241c                          mov    cl,BYTE PTR [esp+0x1c]
00546378  884b04                            mov    BYTE PTR [ebx+0x4],cl
0054637b  39442428                          cmp    DWORD PTR [esp+0x28],eax
0054637f  0f84ea000000                      je     0x54646f
00546385  baff7f0000                        mov    edx,0x7fff
0054638a  66855302                          test   WORD PTR [ebx+0x2],dx
0054638e  0f85db000000                      jne    0x54646f
00546394  8b07                              mov    eax,DWORD PTR [edi]
00546396  8b5060                            mov    edx,DWORD PTR [eax+0x60]
00546399  8bcf                              mov    ecx,edi
0054639b  8db7a0000000                      lea    esi,[edi+0xa0]
005463a1  ffd2                              call   edx
005463a3  dc0d705ac500                      fmul   QWORD PTR ds:0xc55a70
005463a9  0fb64304                          movzx  eax,BYTE PTR [ebx+0x4]
005463ad  51                                push   ecx
005463ae  d95c242c                          fstp   DWORD PTR [esp+0x2c]
005463b2  8bce                              mov    ecx,esi
005463b4  d944242c                          fld    DWORD PTR [esp+0x2c]
005463b8  d91c24                            fstp   DWORD PTR [esp]
005463bb  50                                push   eax
005463bc  e86ffbffff                        call   0x545f30
005463c1  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
005463c5  33d2                              xor    edx,edx
005463c7  895170                            mov    DWORD PTR [ecx+0x70],edx
005463ca  3bc2                              cmp    eax,edx
005463cc  7543                              jne    0x546411
005463ce  395174                            cmp    DWORD PTR [ecx+0x74],edx
005463d1  753e                              jne    0x546411
005463d3  3997a8030000                      cmp    DWORD PTR [edi+0x3a8],edx
005463d9  7406                              je     0x5463e1
005463db  8997a8030000                      mov    DWORD PTR [edi+0x3a8],edx
005463e1  8b8758010000                      mov    eax,DWORD PTR [edi+0x158]
005463e7  3bc2                              cmp    eax,edx
005463e9  741b                              je     0x546406
005463eb  395028                            cmp    DWORD PTR [eax+0x28],edx
005463ee  7416                              je     0x546406
005463f0  0fb74302                          movzx  eax,WORD PTR [ebx+0x2]
005463f4  a9ff7f0000                        test   eax,0x7fff
005463f9  750b                              jne    0x546406
005463fb  0d00800000                        or     eax,0x8000
00546400  66894302                          mov    WORD PTR [ebx+0x2],ax
00546404  eb4d                              jmp    0x546453
00546406  b8ff7f0000                        mov    eax,0x7fff
0054640b  66214302                          and    WORD PTR [ebx+0x2],ax
0054640f  eb42                              jmp    0x546453
00546411  8b17                              mov    edx,DWORD PTR [edi]
00546413  8d4304                            lea    eax,[ebx+0x4]
00546416  50                                push   eax
00546417  8b442420                          mov    eax,DWORD PTR [esp+0x20]
0054641b  50                                push   eax
0054641c  8b4260                            mov    eax,DWORD PTR [edx+0x60]
0054641f  8bcf                              mov    ecx,edi
00546421  ffd0                              call   eax
00546423  51                                push   ecx
00546424  8b4c2424                          mov    ecx,DWORD PTR [esp+0x24]
00546428  d91c24                            fstp   DWORD PTR [esp]
0054642b  8b5174                            mov    edx,DWORD PTR [ecx+0x74]
0054642e  52                                push   edx
0054642f  e88c000000                        call   0x5464c0
00546434  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
00546438  894170                            mov    DWORD PTR [ecx+0x70],eax
0054643b  b800800000                        mov    eax,0x8000
00546440  66094302                          or     WORD PTR [ebx+0x2],ax
00546444  83797000                          cmp    DWORD PTR [ecx+0x70],0x0
00546448  7409                              je     0x546453
0054644a  6a01                              push   0x1
0054644c  8bf7                              mov    esi,edi
0054644e  e86d2cf8ff                        call   0x4c90c0
00546453  0fb64304                          movzx  eax,BYTE PTR [ebx+0x4]
00546457  8b17                              mov    edx,DWORD PTR [edi]
00546459  8b5258                            mov    edx,DWORD PTR [edx+0x58]
0054645c  50                                push   eax
0054645d  8bcf                              mov    ecx,edi
0054645f  ffd2                              call   edx
00546461  8a442430                          mov    al,BYTE PTR [esp+0x30]
00546465  384304                            cmp    BYTE PTR [ebx+0x4],al
00546468  7405                              je     0x54646f
0054646a  c644241701                        mov    BYTE PTR [esp+0x17],0x1
0054646f  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
00546473  c7417400000000                    mov    DWORD PTR [ecx+0x74],0x0
0054647a  eb09                              jmp    0x546485
0054647c  baff7f0000                        mov    edx,0x7fff
00546481  66215302                          and    WORD PTR [ebx+0x2],dx
00546485  668b4302                          mov    ax,WORD PTR [ebx+0x2]
00546489  663344242e                        xor    ax,WORD PTR [esp+0x2e]
0054648e  b900800000                        mov    ecx,0x8000
00546493  6685c1                            test   cx,ax
00546496  7405                              je     0x54649d
00546498  c644241701                        mov    BYTE PTR [esp+0x17],0x1
0054649d  8a442417                          mov    al,BYTE PTR [esp+0x17]
005464a1  8b4c2438                          mov    ecx,DWORD PTR [esp+0x38]
005464a5  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
005464ac  59                                pop    ecx
005464ad  5f                                pop    edi
005464ae  5e                                pop    esi
005464af  5b                                pop    ebx
005464b0  8be5                              mov    esp,ebp
005464b2  5d                                pop    ebp
005464b3  c20800                            ret    0x8
005464b6  cc                                int3
005464b7  cc                                int3
005464b8  cc                                int3
005464b9  cc                                int3
005464ba  cc                                int3
005464bb  cc                                int3
005464bc  cc                                int3
005464bd  cc                                int3
005464be  cc                                int3
005464bf  cc                                int3

# N10-event-object-state 0x4d1250..0x4d1370
004d1250  55                                push   ebp
004d1251  8bec                              mov    ebp,esp
004d1253  6aff                              push   0xffffffff
004d1255  68ee9d9300                        push   0x939dee
004d125a  64a100000000                      mov    eax,fs:0x0
004d1260  50                                push   eax
004d1261  51                                push   ecx
004d1262  53                                push   ebx
004d1263  56                                push   esi
004d1264  57                                push   edi
004d1265  a1201fd600                        mov    eax,ds:0xd61f20
004d126a  33c5                              xor    eax,ebp
004d126c  50                                push   eax
004d126d  8d45f4                            lea    eax,[ebp-0xc]
004d1270  64a300000000                      mov    fs:0x0,eax
004d1276  8bd9                              mov    ebx,ecx
004d1278  66837d081c                        cmp    WORD PTR [ebp+0x8],0x1c
004d127d  0f85ce000000                      jne    0x4d1351
004d1283  f6056092fd0001                    test   BYTE PTR ds:0xfd9260,0x1
004d128a  0fb7b388000000                    movzx  esi,WORD PTR [ebx+0x88]
004d1291  7527                              jne    0x4d12ba
004d1293  830d6092fd0001                    or     DWORD PTR ds:0xfd9260,0x1
004d129a  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
004d12a1  e8ea54ffff                        call   0x4c6790
004d12a6  6860ddbc00                        push   0xbcdd60
004d12ab  e86a103c00                        call   0x89231a
004d12b0  83c404                            add    esp,0x4
004d12b3  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004d12ba  8bc6                              mov    eax,esi
004d12bc  8d4d08                            lea    ecx,[ebp+0x8]
004d12bf  894508                            mov    DWORD PTR [ebp+0x8],eax
004d12c2  51                                push   ecx
004d12c3  8d45f0                            lea    eax,[ebp-0x10]
004d12c6  b96492fd00                        mov    ecx,0xfd9264
004d12cb  e85054ffff                        call   0x4c6720
004d12d0  8b75f0                            mov    esi,DWORD PTR [ebp-0x10]
004d12d3  3b356892fd00                      cmp    esi,DWORD PTR ds:0xfd9268
004d12d9  7476                              je     0x4d1351
004d12db  0fbf550c                          movsx  edx,WORD PTR [ebp+0xc]
004d12df  8d74d610                          lea    esi,[esi+edx*8+0x10]
004d12e3  85f6                              test   esi,esi
004d12e5  746a                              je     0x4d1351
004d12e7  d9e8                              fld1
004d12e9  8b03                              mov    eax,DWORD PTR [ebx]
004d12eb  8b5068                            mov    edx,DWORD PTR [eax+0x68]
004d12ee  51                                push   ecx
004d12ef  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
004d12f2  d91c24                            fstp   DWORD PTR [esp]
004d12f5  51                                push   ecx
004d12f6  8bcb                              mov    ecx,ebx
004d12f8  ffd2                              call   edx
004d12fa  0fb706                            movzx  eax,WORD PTR [esi]
004d12fd  8b8b5c010000                      mov    ecx,DWORD PTR [ebx+0x15c]
004d1303  66898388030000                    mov    WORD PTR [ebx+0x388],ax
004d130a  85c9                              test   ecx,ecx
004d130c  7412                              je     0x4d1320
004d130e  83bb7003000000                    cmp    DWORD PTR [ebx+0x370],0x0
004d1315  7409                              je     0x4d1320
004d1317  50                                push   eax
004d1318  6a01                              push   0x1
004d131a  51                                push   ecx
004d131b  e8805b2d00                        call   0x7a6ea0
004d1320  8b8324040000                      mov    eax,DWORD PTR [ebx+0x424]
004d1326  85c0                              test   eax,eax
004d1328  7427                              je     0x4d1351
004d132a  83782400                          cmp    DWORD PTR [eax+0x24],0x0
004d132e  8d7024                            lea    esi,[eax+0x24]
004d1331  7405                              je     0x4d1338
004d1333  e8b8d22e00                        call   0x7be5f0
004d1338  8bbb24040000                      mov    edi,DWORD PTR [ebx+0x424]
004d133e  85ff                              test   edi,edi
004d1340  740f                              je     0x4d1351
004d1342  e8696affff                        call   0x4c7db0
004d1347  c7832404000000000000              mov    DWORD PTR [ebx+0x424],0x0
004d1351  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004d1354  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004d135b  59                                pop    ecx
004d135c  5f                                pop    edi
004d135d  5e                                pop    esi
004d135e  5b                                pop    ebx
004d135f  8be5                              mov    esp,ebp
004d1361  5d                                pop    ebp
004d1362  c20800                            ret    0x8
004d1365  cc                                int3
004d1366  cc                                int3
004d1367  cc                                int3
004d1368  cc                                int3
004d1369  cc                                int3
004d136a  cc                                int3
004d136b  cc                                int3
004d136c  cc                                int3
004d136d  cc                                int3
004d136e  cc                                int3
004d136f  cc                                int3

# N11-event-object-initialize 0x4d1370..0x4d1640
004d1370  55                                push   ebp
004d1371  8bec                              mov    ebp,esp
004d1373  6aff                              push   0xffffffff
004d1375  6848a39300                        push   0x93a348
004d137a  64a100000000                      mov    eax,fs:0x0
004d1380  50                                push   eax
004d1381  83ec3c                            sub    esp,0x3c
004d1384  a1201fd600                        mov    eax,ds:0xd61f20
004d1389  33c5                              xor    eax,ebp
004d138b  8945f0                            mov    DWORD PTR [ebp-0x10],eax
004d138e  53                                push   ebx
004d138f  56                                push   esi
004d1390  57                                push   edi
004d1391  50                                push   eax
004d1392  8d45f4                            lea    eax,[ebp-0xc]
004d1395  64a300000000                      mov    fs:0x0,eax
004d139b  8bd9                              mov    ebx,ecx
004d139d  6a01                              push   0x1
004d139f  53                                push   ebx
004d13a0  e84b6affff                        call   0x4c7df0
004d13a5  8945d0                            mov    DWORD PTR [ebp-0x30],eax
004d13a8  8b8368030000                      mov    eax,DWORD PTR [ebx+0x368]
004d13ae  33ff                              xor    edi,edi
004d13b0  3bc7                              cmp    eax,edi
004d13b2  7403                              je     0x4d13b7
004d13b4  897824                            mov    DWORD PTR [eax+0x24],edi
004d13b7  8b83f0000000                      mov    eax,DWORD PTR [ebx+0xf0]
004d13bd  8b5008                            mov    edx,DWORD PTR [eax+0x8]
004d13c0  8d8bf0000000                      lea    ecx,[ebx+0xf0]
004d13c6  6a14                              push   0x14
004d13c8  ffd2                              call   edx
004d13ca  f6056092fd0001                    test   BYTE PTR ds:0xfd9260,0x1
004d13d1  0fb7b388000000                    movzx  esi,WORD PTR [ebx+0x88]
004d13d8  7523                              jne    0x4d13fd
004d13da  830d6092fd0001                    or     DWORD PTR ds:0xfd9260,0x1
004d13e1  897dfc                            mov    DWORD PTR [ebp-0x4],edi
004d13e4  e8a753ffff                        call   0x4c6790
004d13e9  6860ddbc00                        push   0xbcdd60
004d13ee  e8270f3c00                        call   0x89231a
004d13f3  83c404                            add    esp,0x4
004d13f6  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004d13fd  8bc6                              mov    eax,esi
004d13ff  8d4dcc                            lea    ecx,[ebp-0x34]
004d1402  8945cc                            mov    DWORD PTR [ebp-0x34],eax
004d1405  51                                push   ecx
004d1406  8d45d4                            lea    eax,[ebp-0x2c]
004d1409  b96492fd00                        mov    ecx,0xfd9264
004d140e  e80d53ffff                        call   0x4c6720
004d1413  8b75d4                            mov    esi,DWORD PTR [ebp-0x2c]
004d1416  3b356892fd00                      cmp    esi,DWORD PTR ds:0xfd9268
004d141c  745c                              je     0x4d147a
004d141e  83c610                            add    esi,0x10
004d1421  3bf7                              cmp    esi,edi
004d1423  7455                              je     0x4d147a
004d1425  d9e8                              fld1
004d1427  8b13                              mov    edx,DWORD PTR [ebx]
004d1429  8b4604                            mov    eax,DWORD PTR [esi+0x4]
004d142c  8b5268                            mov    edx,DWORD PTR [edx+0x68]
004d142f  51                                push   ecx
004d1430  d91c24                            fstp   DWORD PTR [esp]
004d1433  50                                push   eax
004d1434  8bcb                              mov    ecx,ebx
004d1436  ffd2                              call   edx
004d1438  0fb706                            movzx  eax,WORD PTR [esi]
004d143b  8b8b5c010000                      mov    ecx,DWORD PTR [ebx+0x15c]
004d1441  66898388030000                    mov    WORD PTR [ebx+0x388],ax
004d1448  3bcf                              cmp    ecx,edi
004d144a  7411                              je     0x4d145d
004d144c  39bb70030000                      cmp    DWORD PTR [ebx+0x370],edi
004d1452  7409                              je     0x4d145d
004d1454  50                                push   eax
004d1455  6a01                              push   0x1
004d1457  51                                push   ecx
004d1458  e8435a2d00                        call   0x7a6ea0
004d145d  8bb35c010000                      mov    esi,DWORD PTR [ebx+0x15c]
004d1463  3bf7                              cmp    esi,edi
004d1465  7413                              je     0x4d147a
004d1467  39bb70030000                      cmp    DWORD PTR [ebx+0x370],edi
004d146d  740b                              je     0x4d147a
004d146f  d9ee                              fldz
004d1471  51                                push   ecx
004d1472  d91c24                            fstp   DWORD PTR [esp]
004d1475  e8b6532d00                        call   0x7a6830
004d147a  8b8320040000                      mov    eax,DWORD PTR [ebx+0x420]
004d1480  83e805                            sub    eax,0x5
004d1483  0f84b6000000                      je     0x4d153f
004d1489  83e802                            sub    eax,0x2
004d148c  0f8521010000                      jne    0x4d15b3
004d1492  8b835c010000                      mov    eax,DWORD PTR [ebx+0x15c]
004d1498  8d8ba0000000                      lea    ecx,[ebx+0xa0]
004d149e  3bc7                              cmp    eax,edi
004d14a0  741a                              je     0x4d14bc
004d14a2  39bb70030000                      cmp    DWORD PTR [ebx+0x370],edi
004d14a8  7412                              je     0x4d14bc
004d14aa  d9ee                              fldz
004d14ac  51                                push   ecx
004d14ad  8d7de4                            lea    edi,[ebp-0x1c]
004d14b0  d91c24                            fstp   DWORD PTR [esp]
004d14b3  e878712d00                        call   0x7a8630
004d14b8  33ff                              xor    edi,edi
004d14ba  eb11                              jmp    0x4d14cd
004d14bc  8b01                              mov    eax,DWORD PTR [ecx]
004d14be  8b5104                            mov    edx,DWORD PTR [ecx+0x4]
004d14c1  8945e4                            mov    DWORD PTR [ebp-0x1c],eax
004d14c4  8b4108                            mov    eax,DWORD PTR [ecx+0x8]
004d14c7  8955e8                            mov    DWORD PTR [ebp-0x18],edx
004d14ca  8945ec                            mov    DWORD PTR [ebp-0x14],eax
004d14cd  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
004d14d4  897db8                            mov    DWORD PTR [ebp-0x48],edi
004d14d7  c745bcb8c8c000                    mov    DWORD PTR [ebp-0x44],0xc0c8b8
004d14de  897dc0                            mov    DWORD PTR [ebp-0x40],edi
004d14e1  c745c405000000                    mov    DWORD PTR [ebp-0x3c],0x5
004d14e8  897dc8                            mov    DWORD PTR [ebp-0x38],edi
004d14eb  7527                              jne    0x4d1514
004d14ed  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
004d14f4  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
004d14fb  e820f30700                        call   0x550820
004d1500  68b0e6bc00                        push   0xbce6b0
004d1505  e8100e3c00                        call   0x89231a
004d150a  83c404                            add    esp,0x4
004d150d  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004d1514  d9e8                              fld1
004d1516  0fb74b04                          movzx  ecx,WORD PTR [ebx+0x4]
004d151a  83ec08                            sub    esp,0x8
004d151d  8d75e4                            lea    esi,[ebp-0x1c]
004d1520  8d55b8                            lea    edx,[ebp-0x48]
004d1523  d95c2404                          fstp   DWORD PTR [esp+0x4]
004d1527  d9ee                              fldz
004d1529  d91c24                            fstp   DWORD PTR [esp]
004d152c  51                                push   ecx
004d152d  b980f6fd00                        mov    ecx,0xfdf680
004d1532  e8590a0800                        call   0x551f90
004d1537  898324040000                      mov    DWORD PTR [ebx+0x424],eax
004d153d  eb74                              jmp    0x4d15b3
004d153f  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
004d1546  7527                              jne    0x4d156f
004d1548  b801000000                        mov    eax,0x1
004d154d  0905dcf6fd00                      or     DWORD PTR ds:0xfdf6dc,eax
004d1553  8945fc                            mov    DWORD PTR [ebp-0x4],eax
004d1556  e8c5f20700                        call   0x550820
004d155b  68b0e6bc00                        push   0xbce6b0
004d1560  e8b50d3c00                        call   0x89231a
004d1565  83c404                            add    esp,0x4
004d1568  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004d156f  8b13                              mov    edx,DWORD PTR [ebx]
004d1571  8b5250                            mov    edx,DWORD PTR [edx+0x50]
004d1574  0fb77304                          movzx  esi,WORD PTR [ebx+0x4]
004d1578  8d45d8                            lea    eax,[ebp-0x28]
004d157b  50                                push   eax
004d157c  8bcb                              mov    ecx,ebx
004d157e  ffd2                              call   edx
004d1580  6a02                              push   0x2
004d1582  6a00                              push   0x0
004d1584  b9386ac000                        mov    ecx,0xc06a38
004d1589  ba80f6fd00                        mov    edx,0xfdf680
004d158e  8bf8                              mov    edi,eax
004d1590  e8eb050800                        call   0x551b80
004d1595  d9e8                              fld1
004d1597  6a01                              push   0x1
004d1599  83ec08                            sub    esp,0x8
004d159c  d95c2404                          fstp   DWORD PTR [esp+0x4]
004d15a0  d9ee                              fldz
004d15a2  8bc8                              mov    ecx,eax
004d15a4  d91c24                            fstp   DWORD PTR [esp]
004d15a7  57                                push   edi
004d15a8  56                                push   esi
004d15a9  6880f6fd00                        push   0xfdf680
004d15ae  e81d080800                        call   0x551dd0
004d15b3  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
004d15ba  7527                              jne    0x4d15e3
004d15bc  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
004d15c3  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
004d15ca  e8b1270200                        call   0x4f3d80
004d15cf  68e0d1bc00                        push   0xbcd1e0
004d15d4  e8410d3c00                        call   0x89231a
004d15d9  83c404                            add    esp,0x4
004d15dc  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004d15e3  8b8388000000                      mov    eax,DWORD PTR [ebx+0x88]
004d15e9  8d55d4                            lea    edx,[ebp-0x2c]
004d15ec  b97074fb00                        mov    ecx,0xfb7470
004d15f1  8945d4                            mov    DWORD PTR [ebp-0x2c],eax
004d15f4  e877640200                        call   0x4f7a70
004d15f9  83c01c                            add    eax,0x1c
004d15fc  83781408                          cmp    DWORD PTR [eax+0x14],0x8
004d1600  7202                              jb     0x4d1604
004d1602  8b00                              mov    eax,DWORD PTR [eax]
004d1604  50                                push   eax
004d1605  6858c9c000                        push   0xc0c958
004d160a  8d5306                            lea    edx,[ebx+0x6]
004d160d  e8ce000000                        call   0x4d16e0
004d1612  8b45d0                            mov    eax,DWORD PTR [ebp-0x30]
004d1615  83c408                            add    esp,0x8
004d1618  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004d161b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004d1622  59                                pop    ecx
004d1623  5f                                pop    edi
004d1624  5e                                pop    esi
004d1625  5b                                pop    ebx
004d1626  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
004d1629  33cd                              xor    ecx,ebp
004d162b  e8d1f93b00                        call   0x891001
004d1630  8be5                              mov    esp,ebp
004d1632  5d                                pop    ebp
004d1633  c3                                ret
004d1634  cc                                int3
004d1635  cc                                int3
004d1636  cc                                int3
004d1637  cc                                int3
004d1638  cc                                int3
004d1639  cc                                int3
004d163a  cc                                int3
004d163b  cc                                int3
004d163c  cc                                int3
004d163d  cc                                int3
004d163e  cc                                int3
004d163f  cc                                int3

# N12-event-object-construct 0x4d1060..0x4d1130
004d1060  55                                push   ebp
004d1061  8bec                              mov    ebp,esp
004d1063  6aff                              push   0xffffffff
004d1065  6823099100                        push   0x910923
004d106a  64a100000000                      mov    eax,fs:0x0
004d1070  50                                push   eax
004d1071  51                                push   ecx
004d1072  53                                push   ebx
004d1073  56                                push   esi
004d1074  57                                push   edi
004d1075  a1201fd600                        mov    eax,ds:0xd61f20
004d107a  33c5                              xor    eax,ebp
004d107c  50                                push   eax
004d107d  8d45f4                            lea    eax,[ebp-0xc]
004d1080  64a300000000                      mov    fs:0x0,eax
004d1086  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
004d1089  57                                push   edi
004d108a  e8e15fffff                        call   0x4c7070
004d108f  33db                              xor    ebx,ebx
004d1091  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004d1094  6a3c                              push   0x3c
004d1096  c707c4c8c000                      mov    DWORD PTR [edi],0xc0c8c4
004d109c  c787f00000004cc9c000              mov    DWORD PTR [edi+0xf0],0xc0c94c
004d10a6  899f24040000                      mov    DWORD PTR [edi+0x424],ebx
004d10ac  e8b7013c00                        call   0x891268
004d10b1  8bf0                              mov    esi,eax
004d10b3  83c404                            add    esp,0x4
004d10b6  8975f0                            mov    DWORD PTR [ebp-0x10],esi
004d10b9  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
004d10bd  3bf3                              cmp    esi,ebx
004d10bf  7419                              je     0x4d10da
004d10c1  8bc7                              mov    eax,edi
004d10c3  8d4b03                            lea    ecx,[ebx+0x3]
004d10c6  e865a1ffff                        call   0x4cb230
004d10cb  c706cc77c000                      mov    DWORD PTR [esi],0xc077cc
004d10d1  c7463401000000                    mov    DWORD PTR [esi+0x34],0x1
004d10d8  eb02                              jmp    0x4d10dc
004d10da  33f6                              xor    esi,esi
004d10dc  8b5e08                            mov    ebx,DWORD PTR [esi+0x8]
004d10df  83bc9ff400000000                  cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
004d10e7  740d                              je     0x4d10f6
004d10e9  683c75c000                        push   0xc0753c
004d10ee  e86dca2100                        call   0x6edb60
004d10f3  83c404                            add    esp,0x4
004d10f6  89b49ff4000000                    mov    DWORD PTR [edi+ebx*4+0xf4],esi
004d10fd  83bf5801000000                    cmp    DWORD PTR [edi+0x158],0x0
004d1104  8bc7                              mov    eax,edi
004d1106  7506                              jne    0x4d110e
004d1108  89b758010000                      mov    DWORD PTR [edi+0x158],esi
004d110e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004d1111  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004d1118  59                                pop    ecx
004d1119  5f                                pop    edi
004d111a  5e                                pop    esi
004d111b  5b                                pop    ebx
004d111c  8be5                              mov    esp,ebp
004d111e  5d                                pop    ebp
004d111f  c20400                            ret    0x4
004d1122  cc                                int3
004d1123  cc                                int3
004d1124  cc                                int3
004d1125  cc                                int3
004d1126  cc                                int3
004d1127  cc                                int3
004d1128  cc                                int3
004d1129  cc                                int3
004d112a  cc                                int3
004d112b  cc                                int3
004d112c  cc                                int3
004d112d  cc                                int3
004d112e  cc                                int3
004d112f  cc                                int3

# N13-actor-motion 0x4c8da0..0x4c8de0
004c8da0  55                                push   ebp
004c8da1  8bec                              mov    ebp,esp
004c8da3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
004c8da6  57                                push   edi
004c8da7  8bb95c010000                      mov    edi,DWORD PTR [ecx+0x15c]
004c8dad  89818c030000                      mov    DWORD PTR [ecx+0x38c],eax
004c8db3  85ff                              test   edi,edi
004c8db5  7416                              je     0x4c8dcd
004c8db7  83b97003000000                    cmp    DWORD PTR [ecx+0x370],0x0
004c8dbe  740d                              je     0x4c8dcd
004c8dc0  d9450c                            fld    DWORD PTR [ebp+0xc]
004c8dc3  51                                push   ecx
004c8dc4  d91c24                            fstp   DWORD PTR [esp]
004c8dc7  50                                push   eax
004c8dc8  e8a3db2d00                        call   0x7a6970
004c8dcd  5f                                pop    edi
004c8dce  5d                                pop    ebp
004c8dcf  c20800                            ret    0x8
004c8dd2  cc                                int3
004c8dd3  cc                                int3
004c8dd4  cc                                int3
004c8dd5  cc                                int3
004c8dd6  cc                                int3
004c8dd7  cc                                int3
004c8dd8  cc                                int3
004c8dd9  cc                                int3
004c8dda  cc                                int3
004c8ddb  cc                                int3
004c8ddc  cc                                int3
004c8ddd  cc                                int3
004c8dde  cc                                int3
004c8ddf  cc                                int3

# N14-parameter-packet 0x4afaf0..0x4afb80
004afaf0  55                                push   ebp
004afaf1  8bec                              mov    ebp,esp
004afaf3  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
004afaf6  83f802                            cmp    eax,0x2
004afaf9  7304                              jae    0x4afaff
004afafb  33d2                              xor    edx,edx
004afafd  eb0d                              jmp    0x4afb0c
004afaff  8d48fe                            lea    ecx,[eax-0x2]
004afb02  b8abaaaaaa                        mov    eax,0xaaaaaaab
004afb07  f7e1                              mul    ecx
004afb09  c1ea02                            shr    edx,0x2
004afb0c  85d2                              test   edx,edx
004afb0e  7464                              je     0x4afb74
004afb10  53                                push   ebx
004afb11  56                                push   esi
004afb12  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
004afb15  57                                push   edi
004afb16  83c604                            add    esi,0x4
004afb19  8bda                              mov    ebx,edx
004afb1b  eb03                              jmp    0x4afb20
004afb1d  8d4900                            lea    ecx,[ecx+0x0]
004afb20  0fb756fe                          movzx  edx,WORD PTR [esi-0x2]
004afb24  89550c                            mov    DWORD PTR [ebp+0xc],edx
004afb27  e834f5f5ff                        call   0x40f060
004afb2c  8bf8                              mov    edi,eax
004afb2e  8d450c                            lea    eax,[ebp+0xc]
004afb31  50                                push   eax
004afb32  8d4f08                            lea    ecx,[edi+0x8]
004afb35  8d4508                            lea    eax,[ebp+0x8]
004afb38  e8c3f33700                        call   0x82ef00
004afb3d  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
004afb40  3b470c                            cmp    eax,DWORD PTR [edi+0xc]
004afb43  7407                              je     0x4afb4c
004afb45  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
004afb48  85c9                              test   ecx,ecx
004afb4a  750f                              jne    0x4afb5b
004afb4c  68886ac000                        push   0xc06a88
004afb51  e80ae02300                        call   0x6edb60
004afb56  83c404                            add    esp,0x4
004afb59  eb10                              jmp    0x4afb6b
004afb5b  0fb74602                          movzx  eax,WORD PTR [esi+0x2]
004afb5f  8b11                              mov    edx,DWORD PTR [ecx]
004afb61  8b522c                            mov    edx,DWORD PTR [edx+0x2c]
004afb64  50                                push   eax
004afb65  0fb706                            movzx  eax,WORD PTR [esi]
004afb68  50                                push   eax
004afb69  ffd2                              call   edx
004afb6b  83c606                            add    esi,0x6
004afb6e  4b                                dec    ebx
004afb6f  75af                              jne    0x4afb20
004afb71  5f                                pop    edi
004afb72  5e                                pop    esi
004afb73  5b                                pop    ebx
004afb74  33c0                              xor    eax,eax
004afb76  5d                                pop    ebp
004afb77  c20c00                            ret    0xc
004afb7a  cc                                int3
004afb7b  cc                                int3
004afb7c  cc                                int3
004afb7d  cc                                int3
004afb7e  cc                                int3
004afb7f  cc                                int3

# N15-type7-factory 0x4ae4d0..0x4aed90
004ae4d0  55                                push   ebp
004ae4d1  8bec                              mov    ebp,esp
004ae4d3  83e4f8                            and    esp,0xfffffff8
004ae4d6  6aff                              push   0xffffffff
004ae4d8  68db0c9400                        push   0x940cdb
004ae4dd  64a100000000                      mov    eax,fs:0x0
004ae4e3  50                                push   eax
004ae4e4  81ec38010000                      sub    esp,0x138
004ae4ea  a1201fd600                        mov    eax,ds:0xd61f20
004ae4ef  33c4                              xor    eax,esp
004ae4f1  89842430010000                    mov    DWORD PTR [esp+0x130],eax
004ae4f8  53                                push   ebx
004ae4f9  56                                push   esi
004ae4fa  57                                push   edi
004ae4fb  a1201fd600                        mov    eax,ds:0xd61f20
004ae500  33c4                              xor    eax,esp
004ae502  50                                push   eax
004ae503  8d842448010000                    lea    eax,[esp+0x148]
004ae50a  64a300000000                      mov    fs:0x0,eax
004ae510  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
004ae513  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
004ae516  83f802                            cmp    eax,0x2
004ae519  7304                              jae    0x4ae51f
004ae51b  33d2                              xor    edx,edx
004ae51d  eb0d                              jmp    0x4ae52c
004ae51f  8d48fe                            lea    ecx,[eax-0x2]
004ae522  b84fecc44e                        mov    eax,0x4ec4ec4f
004ae527  f7e1                              mul    ecx
004ae529  c1ea03                            shr    edx,0x3
004ae52c  89542428                          mov    DWORD PTR [esp+0x28],edx
004ae530  c744242400000000                  mov    DWORD PTR [esp+0x24],0x0
004ae538  85d2                              test   edx,edx
004ae53a  0f8418080000                      je     0x4aed58
004ae540  83c306                            add    ebx,0x6
004ae543  eb0b                              jmp    0x4ae550
004ae545  8da42400000000                    lea    esp,[esp+0x0]
004ae54c  8d642400                          lea    esp,[esp+0x0]
004ae550  b801000000                        mov    eax,0x1
004ae555  89442420                          mov    DWORD PTR [esp+0x20],eax
004ae559  84052cb2fa00                      test   BYTE PTR ds:0xfab22c,al
004ae55f  752e                              jne    0x4ae58f
004ae561  09052cb2fa00                      or     DWORD PTR ds:0xfab22c,eax
004ae567  c784245001000000000000            mov    DWORD PTR [esp+0x150],0x0
004ae572  e819070300                        call   0x4dec90
004ae577  6830cebc00                        push   0xbcce30
004ae57c  e8993d3e00                        call   0x89231a
004ae581  83c404                            add    esp,0x4
004ae584  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004ae58f  0fb753fc                          movzx  edx,WORD PTR [ebx-0x4]
004ae593  8d442418                          lea    eax,[esp+0x18]
004ae597  50                                push   eax
004ae598  8d442458                          lea    eax,[esp+0x58]
004ae59c  b938b1fa00                        mov    ecx,0xfab138
004ae5a1  8954241c                          mov    DWORD PTR [esp+0x1c],edx
004ae5a5  e856093800                        call   0x82ef00
004ae5aa  8b08                              mov    ecx,DWORD PTR [eax]
004ae5ac  3b0d3cb1fa00                      cmp    ecx,DWORD PTR ds:0xfab13c
004ae5b2  0f858a070000                      jne    0x4aed42
004ae5b8  0fb643fc                          movzx  eax,BYTE PTR [ebx-0x4]
004ae5bc  0fb67bfe                          movzx  edi,BYTE PTR [ebx-0x2]
004ae5c0  0fb70b                            movzx  ecx,WORD PTR [ebx]
004ae5c3  4f                                dec    edi
004ae5c4  8bd0                              mov    edx,eax
004ae5c6  c1e208                            shl    edx,0x8
004ae5c9  0bfa                              or     edi,edx
004ae5cb  c1e710                            shl    edi,0x10
004ae5ce  0bf9                              or     edi,ecx
004ae5d0  897c241c                          mov    DWORD PTR [esp+0x1c],edi
004ae5d4  83f807                            cmp    eax,0x7
004ae5d7  0f87a6070000                      ja     0x4aed83
004ae5dd  ff248590ed4a00                    jmp    DWORD PTR [eax*4+0x4aed90]
004ae5e4  6844040000                        push   0x444
004ae5e9  e87a2c3e00                        call   0x891268
004ae5ee  83c404                            add    esp,0x4
004ae5f1  89442414                          mov    DWORD PTR [esp+0x14],eax
004ae5f5  c784245001000001000000            mov    DWORD PTR [esp+0x150],0x1
004ae600  85c0                              test   eax,eax
004ae602  740e                              je     0x4ae612
004ae604  8b530e                            mov    edx,DWORD PTR [ebx+0xe]
004ae607  52                                push   edx
004ae608  50                                push   eax
004ae609  e8e2f00100                        call   0x4cd6f0
004ae60e  8bf0                              mov    esi,eax
004ae610  eb02                              jmp    0x4ae614
004ae612  33f6                              xor    esi,esi
004ae614  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004ae61f  e87c65f5ff                        call   0x404ba0
004ae624  8b80505f0000                      mov    eax,DWORD PTR [eax+0x5f50]
004ae62a  39430e                            cmp    DWORD PTR [ebx+0xe],eax
004ae62d  0f85e4020000                      jne    0x4ae917
004ae633  e86865f5ff                        call   0x404ba0
004ae638  8b9024690000                      mov    edx,DWORD PTR [eax+0x6924]
004ae63e  0fb703                            movzx  eax,WORD PTR [ebx]
004ae641  83f809                            cmp    eax,0x9
004ae644  0f87cd020000                      ja     0x4ae917
004ae64a  8bc8                              mov    ecx,eax
004ae64c  69c910020000                      imul   ecx,ecx,0x210
004ae652  03ca                              add    ecx,edx
004ae654  0f84bd020000                      je     0x4ae917
004ae65a  83795c00                          cmp    DWORD PTR [ecx+0x5c],0x0
004ae65e  0f85b3020000                      jne    0x4ae917
004ae664  8b11                              mov    edx,DWORD PTR [ecx]
004ae666  50                                push   eax
004ae667  8b4204                            mov    eax,DWORD PTR [edx+0x4]
004ae66a  ffd0                              call   eax
004ae66c  e9a6020000                        jmp    0x4ae917
004ae671  6834040000                        push   0x434
004ae676  e8ed2b3e00                        call   0x891268
004ae67b  83c404                            add    esp,0x4
004ae67e  89442414                          mov    DWORD PTR [esp+0x14],eax
004ae682  c784245001000002000000            mov    DWORD PTR [esp+0x150],0x2
004ae68d  85c0                              test   eax,eax
004ae68f  740a                              je     0x4ae69b
004ae691  50                                push   eax
004ae692  e879300200                        call   0x4d1710
004ae697  8bf0                              mov    esi,eax
004ae699  eb02                              jmp    0x4ae69d
004ae69b  33f6                              xor    esi,esi
004ae69d  6a48                              push   0x48
004ae69f  c7842454010000ffffffff            mov    DWORD PTR [esp+0x154],0xffffffff
004ae6aa  e8b92b3e00                        call   0x891268
004ae6af  8bf8                              mov    edi,eax
004ae6b1  83c404                            add    esp,0x4
004ae6b4  897c2414                          mov    DWORD PTR [esp+0x14],edi
004ae6b8  c784245001000003000000            mov    DWORD PTR [esp+0x150],0x3
004ae6c3  85ff                              test   edi,edi
004ae6c5  7478                              je     0x4ae73f
004ae6c7  0fb74604                          movzx  eax,WORD PTR [esi+0x4]
004ae6cb  0f57c0                            xorps  xmm0,xmm0
004ae6ce  894704                            mov    DWORD PTR [edi+0x4],eax
004ae6d1  c70707000000                      mov    DWORD PTR [edi],0x7
004ae6d7  c7470801000000                    mov    DWORD PTR [edi+0x8],0x1
004ae6de  c6470c01                          mov    BYTE PTR [edi+0xc],0x1
004ae6e2  8b4b02                            mov    ecx,DWORD PTR [ebx+0x2]
004ae6e5  894f10                            mov    DWORD PTR [edi+0x10],ecx
004ae6e8  8b5306                            mov    edx,DWORD PTR [ebx+0x6]
004ae6eb  895714                            mov    DWORD PTR [edi+0x14],edx
004ae6ee  f30f1144243c                      movss  DWORD PTR [esp+0x3c],xmm0
004ae6f4  8b4c243c                          mov    ecx,DWORD PTR [esp+0x3c]
004ae6f8  894f20                            mov    DWORD PTR [edi+0x20],ecx
004ae6fb  33d2                              xor    edx,edx
004ae6fd  f30f11442438                      movss  DWORD PTR [esp+0x38],xmm0
004ae703  8b442438                          mov    eax,DWORD PTR [esp+0x38]
004ae707  8d4f24                            lea    ecx,[edi+0x24]
004ae70a  f30f114718                        movss  DWORD PTR [edi+0x18],xmm0
004ae70f  89471c                            mov    DWORD PTR [edi+0x1c],eax
004ae712  52                                push   edx
004ae713  c7411407000000                    mov    DWORD PTR [ecx+0x14],0x7
004ae71a  c7411000000000                    mov    DWORD PTR [ecx+0x10],0x0
004ae721  68fcd1be00                        push   0xbed1fc
004ae726  668911                            mov    WORD PTR [ecx],dx
004ae729  e8323af5ff                        call   0x402160
004ae72e  0f57c0                            xorps  xmm0,xmm0
004ae731  c7474000000000                    mov    DWORD PTR [edi+0x40],0x0
004ae738  f30f114744                        movss  DWORD PTR [edi+0x44],xmm0
004ae73d  eb02                              jmp    0x4ae741
004ae73f  33ff                              xor    edi,edi
004ae741  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004ae74c  f605c0f3fd0001                    test   BYTE PTR ds:0xfdf3c0,0x1
004ae753  751e                              jne    0x4ae773
004ae755  830dc0f3fd0001                    or     DWORD PTR ds:0xfdf3c0,0x1
004ae75c  6850dfbc00                        push   0xbcdf50
004ae761  c705c4f3fd0000000000              mov    DWORD PTR ds:0xfdf3c4,0x0
004ae76b  e8aa3b3e00                        call   0x89231a
004ae770  83c404                            add    esp,0x4
004ae773  a1c4f3fd00                        mov    eax,ds:0xfdf3c4
004ae778  57                                push   edi
004ae779  50                                push   eax
004ae77a  e8410e0c00                        call   0x56f5c0
004ae77f  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
004ae786  0fb64313                          movzx  eax,BYTE PTR [ebx+0x13]
004ae78a  898624040000                      mov    DWORD PTR [esi+0x424],eax
004ae790  752f                              jne    0x4ae7c1
004ae792  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
004ae799  c784245001000004000000            mov    DWORD PTR [esp+0x150],0x4
004ae7a4  e8d7550400                        call   0x4f3d80
004ae7a9  68e0d1bc00                        push   0xbcd1e0
004ae7ae  e8673b3e00                        call   0x89231a
004ae7b3  83c404                            add    esp,0x4
004ae7b6  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004ae7c1  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
004ae7c5  894c2418                          mov    DWORD PTR [esp+0x18],ecx
004ae7c9  8d542418                          lea    edx,[esp+0x18]
004ae7cd  b97074fb00                        mov    ecx,0xfb7470
004ae7d2  e899920400                        call   0x4f7a70
004ae7d7  80786100                          cmp    BYTE PTR [eax+0x61],0x0
004ae7db  751c                              jne    0x4ae7f9
004ae7dd  8b8668030000                      mov    eax,DWORD PTR [esi+0x368]
004ae7e3  33c9                              xor    ecx,ecx
004ae7e5  894c2420                          mov    DWORD PTR [esp+0x20],ecx
004ae7e9  3bc1                              cmp    eax,ecx
004ae7eb  7414                              je     0x4ae801
004ae7ed  8b7c241c                          mov    edi,DWORD PTR [esp+0x1c]
004ae7f1  894824                            mov    DWORD PTR [eax+0x24],ecx
004ae7f4  e91e010000                        jmp    0x4ae917
004ae7f9  c744242001000000                  mov    DWORD PTR [esp+0x20],0x1
004ae801  8b7c241c                          mov    edi,DWORD PTR [esp+0x1c]
004ae805  e90d010000                        jmp    0x4ae917
004ae80a  682c040000                        push   0x42c
004ae80f  e8542a3e00                        call   0x891268
004ae814  83c404                            add    esp,0x4
004ae817  89442414                          mov    DWORD PTR [esp+0x14],eax
004ae81b  c784245001000005000000            mov    DWORD PTR [esp+0x150],0x5
004ae826  85c0                              test   eax,eax
004ae828  740c                              je     0x4ae836
004ae82a  50                                push   eax
004ae82b  e8f0380200                        call   0x4d2120
004ae830  89442418                          mov    DWORD PTR [esp+0x18],eax
004ae834  eb08                              jmp    0x4ae83e
004ae836  c744241800000000                  mov    DWORD PTR [esp+0x18],0x0
004ae83e  83ceff                            or     esi,0xffffffff
004ae841  89b42450010000                    mov    DWORD PTR [esp+0x150],esi
004ae848  f605c818fe0001                    test   BYTE PTR ds:0xfe18c8,0x1
004ae84f  752b                              jne    0x4ae87c
004ae851  830dc818fe0001                    or     DWORD PTR ds:0xfe18c8,0x1
004ae858  c784245001000006000000            mov    DWORD PTR [esp+0x150],0x6
004ae863  e808110900                        call   0x53f970
004ae868  6810e8bc00                        push   0xbce810
004ae86d  e8a83a3e00                        call   0x89231a
004ae872  83c404                            add    esp,0x4
004ae875  89b42450010000                    mov    DWORD PTR [esp+0x150],esi
004ae87c  0fb733                            movzx  esi,WORD PTR [ebx]
004ae87f  8d542414                          lea    edx,[esp+0x14]
004ae883  52                                push   edx
004ae884  8d442444                          lea    eax,[esp+0x44]
004ae888  b9dc18fe00                        mov    ecx,0xfe18dc
004ae88d  89742418                          mov    DWORD PTR [esp+0x18],esi
004ae891  e82a503900                        call   0x8438c0
004ae896  8b4c2440                          mov    ecx,DWORD PTR [esp+0x40]
004ae89a  3b0de018fe00                      cmp    ecx,DWORD PTR ds:0xfe18e0
004ae8a0  742e                              je     0x4ae8d0
004ae8a2  8a43fd                            mov    al,BYTE PTR [ebx-0x3]
004ae8a5  88442444                          mov    BYTE PTR [esp+0x44],al
004ae8a9  8b4110                            mov    eax,DWORD PTR [ecx+0x10]
004ae8ac  8b0dec18fe00                      mov    ecx,DWORD PTR ds:0xfe18ec
004ae8b2  8944244c                          mov    DWORD PTR [esp+0x4c],eax
004ae8b6  8d442444                          lea    eax,[esp+0x44]
004ae8ba  bfcc18fe00                        mov    edi,0xfe18cc
004ae8bf  89742448                          mov    DWORD PTR [esp+0x48],esi
004ae8c3  894c2450                          mov    DWORD PTR [esp+0x50],ecx
004ae8c7  e8d4020900                        call   0x53eba0
004ae8cc  8b7c241c                          mov    edi,DWORD PTR [esp+0x1c]
004ae8d0  8b742418                          mov    esi,DWORD PTR [esp+0x18]
004ae8d4  eb41                              jmp    0x4ae917
004ae8d6  6828040000                        push   0x428
004ae8db  e888293e00                        call   0x891268
004ae8e0  83c404                            add    esp,0x4
004ae8e3  89442414                          mov    DWORD PTR [esp+0x14],eax
004ae8e7  c784245001000007000000            mov    DWORD PTR [esp+0x150],0x7
004ae8f2  85c0                              test   eax,eax
004ae8f4  7408                              je     0x4ae8fe
004ae8f6  50                                push   eax
004ae8f7  e864270200                        call   0x4d1060
004ae8fc  eb02                              jmp    0x4ae900
004ae8fe  33c0                              xor    eax,eax
004ae900  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004ae90b  0fb64b13                          movzx  ecx,BYTE PTR [ebx+0x13]
004ae90f  898820040000                      mov    DWORD PTR [eax+0x420],ecx
004ae915  8bf0                              mov    esi,eax
004ae917  85f6                              test   esi,esi
004ae919  0f8464040000                      je     0x4aed83
004ae91f  f605600ffc0001                    test   BYTE PTR ds:0xfc0f60,0x1
004ae926  752f                              jne    0x4ae957
004ae928  830d600ffc0001                    or     DWORD PTR ds:0xfc0f60,0x1
004ae92f  c784245001000008000000            mov    DWORD PTR [esp+0x150],0x8
004ae93a  e801e62e00                        call   0x79cf40
004ae93f  6880dbbc00                        push   0xbcdb80
004ae944  e8d1393e00                        call   0x89231a
004ae949  83c404                            add    esp,0x4
004ae94c  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004ae957  0fb713                            movzx  edx,WORD PTR [ebx]
004ae95a  8d442414                          lea    eax,[esp+0x14]
004ae95e  50                                push   eax
004ae95f  8d442430                          lea    eax,[esp+0x30]
004ae963  b9900efc00                        mov    ecx,0xfc0e90
004ae968  89542418                          mov    DWORD PTR [esp+0x18],edx
004ae96c  e81f6e0600                        call   0x515790
004ae971  8b44242c                          mov    eax,DWORD PTR [esp+0x2c]
004ae975  3b05940efc00                      cmp    eax,DWORD PTR ds:0xfc0e94
004ae97b  740d                              je     0x4ae98a
004ae97d  8b4010                            mov    eax,DWORD PTR [eax+0x10]
004ae980  83785400                          cmp    DWORD PTR [eax+0x54],0x0
004ae984  0f8523010000                      jne    0x4aeaad
004ae98a  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
004ae990  8b11                              mov    edx,DWORD PTR [ecx]
004ae992  8b4220                            mov    eax,DWORD PTR [edx+0x20]
004ae995  ffd0                              call   eax
004ae997  85c0                              test   eax,eax
004ae999  0f84cd000000                      je     0x4aea6c
004ae99f  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
004ae9a6  8b889c000000                      mov    ecx,DWORD PTR [eax+0x9c]
004ae9ac  894c2414                          mov    DWORD PTR [esp+0x14],ecx
004ae9b0  752f                              jne    0x4ae9e1
004ae9b2  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
004ae9b9  c784245001000009000000            mov    DWORD PTR [esp+0x150],0x9
004ae9c4  e8c7020300                        call   0x4dec90
004ae9c9  6830cebc00                        push   0xbcce30
004ae9ce  e847393e00                        call   0x89231a
004ae9d3  83c404                            add    esp,0x4
004ae9d6  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004ae9e1  8b542414                          mov    edx,DWORD PTR [esp+0x14]
004ae9e5  8d442414                          lea    eax,[esp+0x14]
004ae9e9  50                                push   eax
004ae9ea  8d442438                          lea    eax,[esp+0x38]
004ae9ee  b948b1fa00                        mov    ecx,0xfab148
004ae9f3  89542418                          mov    DWORD PTR [esp+0x18],edx
004ae9f7  e8c44e3900                        call   0x8438c0
004ae9fc  8b442434                          mov    eax,DWORD PTR [esp+0x34]
004aea00  3b054cb1fa00                      cmp    eax,DWORD PTR ds:0xfab14c
004aea06  7464                              je     0x4aea6c
004aea08  8b4010                            mov    eax,DWORD PTR [eax+0x10]
004aea0b  85c0                              test   eax,eax
004aea0d  745d                              je     0x4aea6c
004aea0f  80782005                          cmp    BYTE PTR [eax+0x20],0x5
004aea13  7257                              jb     0x4aea6c
004aea15  0fb70b                            movzx  ecx,WORD PTR [ebx]
004aea18  51                                push   ecx
004aea19  68d869c000                        push   0xc069d8
004aea1e  8d54247c                          lea    edx,[esp+0x7c]
004aea22  e859920000                        call   0x4b7c80
004aea27  83c408                            add    esp,0x8
004aea2a  8d542474                          lea    edx,[esp+0x74]
004aea2e  52                                push   edx
004aea2f  8d4c245c                          lea    ecx,[esp+0x5c]
004aea33  e81838f5ff                        call   0x402250
004aea38  8d442458                          lea    eax,[esp+0x58]
004aea3c  50                                push   eax
004aea3d  c78424540100000a000000            mov    DWORD PTR [esp+0x154],0xa
004aea48  e8730ef6ff                        call   0x40f8c0
004aea4d  8bf8                              mov    edi,eax
004aea4f  e8dc800200                        call   0x4d6b30
004aea54  8d4c2458                          lea    ecx,[esp+0x58]
004aea58  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004aea63  e8d8b90400                        call   0x4fa440
004aea68  8b7c241c                          mov    edi,DWORD PTR [esp+0x1c]
004aea6c  f605400efc0001                    test   BYTE PTR ds:0xfc0e40,0x1
004aea73  752f                              jne    0x4aeaa4
004aea75  830d400efc0001                    or     DWORD PTR ds:0xfc0e40,0x1
004aea7c  c78424500100000b000000            mov    DWORD PTR [esp+0x150],0xb
004aea87  e8e41c0900                        call   0x540770
004aea8c  6860dbbc00                        push   0xbcdb60
004aea91  e884383e00                        call   0x89231a
004aea96  83c404                            add    esp,0x4
004aea99  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004aeaa4  0fb70b                            movzx  ecx,WORD PTR [ebx]
004aeaa7  51                                push   ecx
004aeaa8  e8632b0900                        call   0x541610
004aeaad  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
004aeab4  752f                              jne    0x4aeae5
004aeab6  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
004aeabd  c78424500100000c000000            mov    DWORD PTR [esp+0x150],0xc
004aeac8  e8b3520400                        call   0x4f3d80
004aeacd  68e0d1bc00                        push   0xbcd1e0
004aead2  e843383e00                        call   0x89231a
004aead7  83c404                            add    esp,0x4
004aeada  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004aeae5  8d542414                          lea    edx,[esp+0x14]
004aeae9  b97074fb00                        mov    ecx,0xfb7470
004aeaee  897c2414                          mov    DWORD PTR [esp+0x14],edi
004aeaf2  e8798f0400                        call   0x4f7a70
004aeaf7  0fb65061                          movzx  edx,BYTE PTR [eax+0x61]
004aeafb  8b86f0000000                      mov    eax,DWORD PTR [esi+0xf0]
004aeb01  8b4008                            mov    eax,DWORD PTR [eax+0x8]
004aeb04  89961c040000                      mov    DWORD PTR [esi+0x41c],edx
004aeb0a  0fb65315                          movzx  edx,BYTE PTR [ebx+0x15]
004aeb0e  8d8ef0000000                      lea    ecx,[esi+0xf0]
004aeb14  52                                push   edx
004aeb15  ffd0                              call   eax
004aeb17  8b430e                            mov    eax,DWORD PTR [ebx+0xe]
004aeb1a  8b16                              mov    edx,DWORD PTR [esi]
004aeb1c  89869c000000                      mov    DWORD PTR [esi+0x9c],eax
004aeb22  0fb64314                          movzx  eax,BYTE PTR [ebx+0x14]
004aeb26  898690000000                      mov    DWORD PTR [esi+0x90],eax
004aeb2c  668b43fc                          mov    ax,WORD PTR [ebx-0x4]
004aeb30  66894604                          mov    WORD PTR [esi+0x4],ax
004aeb34  8b423c                            mov    eax,DWORD PTR [edx+0x3c]
004aeb37  57                                push   edi
004aeb38  8bce                              mov    ecx,esi
004aeb3a  ffd0                              call   eax
004aeb3c  8b16                              mov    edx,DWORD PTR [esi]
004aeb3e  8b5244                            mov    edx,DWORD PTR [edx+0x44]
004aeb41  6a01                              push   0x1
004aeb43  8d4302                            lea    eax,[ebx+0x2]
004aeb46  50                                push   eax
004aeb47  8bce                              mov    ecx,esi
004aeb49  ffd2                              call   edx
004aeb4b  0fb64b12                          movzx  ecx,BYTE PTR [ebx+0x12]
004aeb4f  8b06                              mov    eax,DWORD PTR [esi]
004aeb51  8b5058                            mov    edx,DWORD PTR [eax+0x58]
004aeb54  51                                push   ecx
004aeb55  8bce                              mov    ecx,esi
004aeb57  ffd2                              call   edx
004aeb59  8b06                              mov    eax,DWORD PTR [esi]
004aeb5b  d9430a                            fld    DWORD PTR [ebx+0xa]
004aeb5e  8b505c                            mov    edx,DWORD PTR [eax+0x5c]
004aeb61  51                                push   ecx
004aeb62  8bce                              mov    ecx,esi
004aeb64  d91c24                            fstp   DWORD PTR [esp]
004aeb67  ffd2                              call   edx
004aeb69  807b1518                          cmp    BYTE PTR [ebx+0x15],0x18
004aeb6d  7507                              jne    0x4aeb76
004aeb6f  c686bc00000001                    mov    BYTE PTR [esi+0xbc],0x1
004aeb76  8b06                              mov    eax,DWORD PTR [esi]
004aeb78  8b5030                            mov    edx,DWORD PTR [eax+0x30]
004aeb7b  8bce                              mov    ecx,esi
004aeb7d  ffd2                              call   edx
004aeb7f  8a43fc                            mov    al,BYTE PTR [ebx-0x4]
004aeb82  3c01                              cmp    al,0x1
004aeb84  7529                              jne    0x4aebaf
004aeb86  837c242000                        cmp    DWORD PTR [esp+0x20],0x0
004aeb8b  7511                              jne    0x4aeb9e
004aeb8d  8b8668030000                      mov    eax,DWORD PTR [esi+0x368]
004aeb93  85c0                              test   eax,eax
004aeb95  7407                              je     0x4aeb9e
004aeb97  c7402400000000                    mov    DWORD PTR [eax+0x24],0x0
004aeb9e  33c0                              xor    eax,eax
004aeba0  807b1304                          cmp    BYTE PTR [ebx+0x13],0x4
004aeba4  0f94c0                            sete   al
004aeba7  898628040000                      mov    DWORD PTR [esi+0x428],eax
004aebad  eb15                              jmp    0x4aebc4
004aebaf  3c06                              cmp    al,0x6
004aebb1  7511                              jne    0x4aebc4
004aebb3  8b8668030000                      mov    eax,DWORD PTR [esi+0x368]
004aebb9  85c0                              test   eax,eax
004aebbb  7407                              je     0x4aebc4
004aebbd  c7402400000000                    mov    DWORD PTR [eax+0x24],0x0
004aebc4  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
004aebcb  752f                              jne    0x4aebfc
004aebcd  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
004aebd4  c78424500100000d000000            mov    DWORD PTR [esp+0x150],0xd
004aebdf  e8ac000300                        call   0x4dec90
004aebe4  6830cebc00                        push   0xbcce30
004aebe9  e82c373e00                        call   0x89231a
004aebee  83c404                            add    esp,0x4
004aebf1  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004aebfc  6830b1fa00                        push   0xfab130
004aec01  8bc6                              mov    eax,esi
004aec03  e828130300                        call   0x4dff30
004aec08  837b0e00                          cmp    DWORD PTR [ebx+0xe],0x0
004aec0c  0f8486000000                      je     0x4aec98
004aec12  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
004aec19  752f                              jne    0x4aec4a
004aec1b  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
004aec22  c78424500100000e000000            mov    DWORD PTR [esp+0x150],0xe
004aec2d  e85e000300                        call   0x4dec90
004aec32  6830cebc00                        push   0xbcce30
004aec37  e8de363e00                        call   0x89231a
004aec3c  83c404                            add    esp,0x4
004aec3f  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004aec4a  8b4b0e                            mov    ecx,DWORD PTR [ebx+0xe]
004aec4d  8d542414                          lea    edx,[esp+0x14]
004aec51  894c2414                          mov    DWORD PTR [esp+0x14],ecx
004aec55  52                                push   edx
004aec56  8d442434                          lea    eax,[esp+0x34]
004aec5a  b948b1fa00                        mov    ecx,0xfab148
004aec5f  e85c4c3900                        call   0x8438c0
004aec64  8b442430                          mov    eax,DWORD PTR [esp+0x30]
004aec68  3b054cb1fa00                      cmp    eax,DWORD PTR ds:0xfab14c
004aec6e  7428                              je     0x4aec98
004aec70  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
004aec73  85c9                              test   ecx,ecx
004aec75  7421                              je     0x4aec98
004aec77  83790400                          cmp    DWORD PTR [ecx+0x4],0x0
004aec7b  751b                              jne    0x4aec98
004aec7d  0fb743fc                          movzx  eax,WORD PTR [ebx-0x4]
004aec81  8bf9                              mov    edi,ecx
004aec83  e8c8810100                        call   0x4c6e50
004aec88  807e0400                          cmp    BYTE PTR [esi+0x4],0x0
004aec8c  750a                              jne    0x4aec98
004aec8e  c7869800000001000000              mov    DWORD PTR [esi+0x98],0x1
004aec98  8a4313                            mov    al,BYTE PTR [ebx+0x13]
004aec9b  3c04                              cmp    al,0x4
004aec9d  755a                              jne    0x4aecf9
004aec9f  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
004aeca6  752f                              jne    0x4aecd7
004aeca8  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
004aecaf  c78424500100000f000000            mov    DWORD PTR [esp+0x150],0xf
004aecba  e8d1ff0200                        call   0x4dec90
004aecbf  6830cebc00                        push   0xbcce30
004aecc4  e851363e00                        call   0x89231a
004aecc9  83c404                            add    esp,0x4
004aeccc  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004aecd7  a134b1fa00                        mov    eax,ds:0xfab134
004aecdc  89442414                          mov    DWORD PTR [esp+0x14],eax
004aece0  8d7820                            lea    edi,[eax+0x20]
004aece3  8d43fc                            lea    eax,[ebx-0x4]
004aece6  e8b5f00800                        call   0x53dda0
004aeceb  668b43fc                          mov    ax,WORD PTR [ebx-0x4]
004aecef  8b4c2414                          mov    ecx,DWORD PTR [esp+0x14]
004aecf3  66894130                          mov    WORD PTR [ecx+0x30],ax
004aecf7  eb49                              jmp    0x4aed42
004aecf9  3c06                              cmp    al,0x6
004aecfb  7545                              jne    0x4aed42
004aecfd  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
004aed04  752f                              jne    0x4aed35
004aed06  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
004aed0d  c784245001000010000000            mov    DWORD PTR [esp+0x150],0x10
004aed18  e873ff0200                        call   0x4dec90
004aed1d  6830cebc00                        push   0xbcce30
004aed22  e8f3353e00                        call   0x89231a
004aed27  83c404                            add    esp,0x4
004aed2a  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
004aed35  668b53fc                          mov    dx,WORD PTR [ebx-0x4]
004aed39  a134b1fa00                        mov    eax,ds:0xfab134
004aed3e  66895032                          mov    WORD PTR [eax+0x32],dx
004aed42  8b442424                          mov    eax,DWORD PTR [esp+0x24]
004aed46  40                                inc    eax
004aed47  83c31a                            add    ebx,0x1a
004aed4a  89442424                          mov    DWORD PTR [esp+0x24],eax
004aed4e  3b442428                          cmp    eax,DWORD PTR [esp+0x28]
004aed52  0f82f8f7ffff                      jb     0x4ae550
004aed58  b800010000                        mov    eax,0x100
004aed5d  8b8c2448010000                    mov    ecx,DWORD PTR [esp+0x148]
004aed64  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004aed6b  59                                pop    ecx
004aed6c  5f                                pop    edi
004aed6d  5e                                pop    esi
004aed6e  5b                                pop    ebx
004aed6f  8b8c2430010000                    mov    ecx,DWORD PTR [esp+0x130]
004aed76  33cc                              xor    ecx,esp
004aed78  e884223e00                        call   0x891001
004aed7d  8be5                              mov    esp,ebp
004aed7f  5d                                pop    ebp
004aed80  c20c00                            ret    0xc
004aed83  68c069c000                        push   0xc069c0
004aed88  e8e3ee2300                        call   0x6edc70
004aed8d  8d4900                            lea    ecx,[ecx+0x0]

# N16-point-latch 0x544730..0x5447f0
00544730  55                                push   ebp
00544731  8bec                              mov    ebp,esp
00544733  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
00544736  83ec08                            sub    esp,0x8
00544739  80b90501000000                    cmp    BYTE PTR [ecx+0x105],0x0
00544740  750e                              jne    0x544750
00544742  c70200000000                      mov    DWORD PTR [edx],0x0
00544748  33c0                              xor    eax,eax
0054474a  8be5                              mov    esp,ebp
0054474c  5d                                pop    ebp
0054474d  c20c00                            ret    0xc
00544750  d900                              fld    DWORD PTR [eax]
00544752  c70201000000                      mov    DWORD PTR [edx],0x1
00544758  d8a1a0000000                      fsub   DWORD PTR [ecx+0xa0]
0054475e  d95df8                            fstp   DWORD PTR [ebp-0x8]
00544761  d94004                            fld    DWORD PTR [eax+0x4]
00544764  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
00544767  d8a1a4000000                      fsub   DWORD PTR [ecx+0xa4]
0054476d  d95dfc                            fstp   DWORD PTR [ebp-0x4]
00544770  d945f8                            fld    DWORD PTR [ebp-0x8]
00544773  d945fc                            fld    DWORD PTR [ebp-0x4]
00544776  dcc8                              fmul   st(0),st
00544778  d9c1                              fld    st(1)
0054477a  deca                              fmulp  st(2),st
0054477c  dec1                              faddp  st(1),st
0054477e  d95d08                            fstp   DWORD PTR [ebp+0x8]
00544781  d94508                            fld    DWORD PTR [ebp+0x8]
00544784  d910                              fst    DWORD PTR [eax]
00544786  d981fc000000                      fld    DWORD PTR [ecx+0xfc]
0054478c  dcc8                              fmul   st(0),st
0054478e  dff1                              fcomip st,st(1)
00544790  ddd8                              fstp   st(0)
00544792  7604                              jbe    0x544798
00544794  b001                              mov    al,0x1
00544796  eb02                              jmp    0x54479a
00544798  32c0                              xor    al,al
0054479a  83b90001000000                    cmp    DWORD PTR [ecx+0x100],0x0
005447a1  752b                              jne    0x5447ce
005447a3  837d1000                          cmp    DWORD PTR [ebp+0x10],0x0
005447a7  7437                              je     0x5447e0
005447a9  84c0                              test   al,al
005447ab  7433                              je     0x5447e0
005447ad  80b90401000000                    cmp    BYTE PTR [ecx+0x104],0x0
005447b4  7406                              je     0x5447bc
005447b6  c70200000000                      mov    DWORD PTR [edx],0x0
005447bc  c6810401000001                    mov    BYTE PTR [ecx+0x104],0x1
005447c3  b801000000                        mov    eax,0x1
005447c8  8be5                              mov    esp,ebp
005447ca  5d                                pop    ebp
005447cb  c20c00                            ret    0xc
005447ce  84c0                              test   al,al
005447d0  75db                              jne    0x5447ad
005447d2  388104010000                      cmp    BYTE PTR [ecx+0x104],al
005447d8  7506                              jne    0x5447e0
005447da  c70200000000                      mov    DWORD PTR [edx],0x0
005447e0  c6810401000000                    mov    BYTE PTR [ecx+0x104],0x0
005447e7  33c0                              xor    eax,eax
005447e9  8be5                              mov    esp,ebp
005447eb  5d                                pop    ebp
005447ec  c20c00                            ret    0xc
005447ef  cc                                int3

# N17-point-selection 0x544a00..0x544b60
00544a00  55                                push   ebp
00544a01  8bec                              mov    ebp,esp
00544a03  83e4f8                            and    esp,0xfffffff8
00544a06  6aff                              push   0xffffffff
00544a08  68be059400                        push   0x9405be
00544a0d  64a100000000                      mov    eax,fs:0x0
00544a13  50                                push   eax
00544a14  83ec18                            sub    esp,0x18
00544a17  53                                push   ebx
00544a18  56                                push   esi
00544a19  57                                push   edi
00544a1a  a1201fd600                        mov    eax,ds:0xd61f20
00544a1f  33c4                              xor    eax,esp
00544a21  50                                push   eax
00544a22  8d442428                          lea    eax,[esp+0x28]
00544a26  64a300000000                      mov    fs:0x0,eax
00544a2c  8bf1                              mov    esi,ecx
00544a2e  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
00544a34  8b01                              mov    eax,DWORD PTR [ecx]
00544a36  8b5020                            mov    edx,DWORD PTR [eax+0x20]
00544a39  ffd2                              call   edx
00544a3b  33db                              xor    ebx,ebx
00544a3d  3bc3                              cmp    eax,ebx
00544a3f  0f8404010000                      je     0x544b49
00544a45  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
00544a48  2b4e04                            sub    ecx,DWORD PTR [esi+0x4]
00544a4b  f30f1005605ec500                  movss  xmm0,DWORD PTR ds:0xc55e60
00544a53  c1f902                            sar    ecx,0x2
00544a56  f30f11442418                      movss  DWORD PTR [esp+0x18],xmm0
00544a5c  895c241c                          mov    DWORD PTR [esp+0x1c],ebx
00544a60  85c9                              test   ecx,ecx
00544a62  0f84e1000000                      je     0x544b49
00544a68  0f57c0                            xorps  xmm0,xmm0
00544a6b  05a0000000                        add    eax,0xa0
00544a70  89442420                          mov    DWORD PTR [esp+0x20],eax
00544a74  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
00544a77  8b4604                            mov    eax,DWORD PTR [esi+0x4]
00544a7a  52                                push   edx
00544a7b  8b1498                            mov    edx,DWORD PTR [eax+ebx*4]
00544a7e  8b442424                          mov    eax,DWORD PTR [esp+0x24]
00544a82  8d4c2414                          lea    ecx,[esp+0x14]
00544a86  8d3c9d00000000                    lea    edi,[ebx*4+0x0]
00544a8d  51                                push   ecx
00544a8e  52                                push   edx
00544a8f  8d542420                          lea    edx,[esp+0x20]
00544a93  c744242000000000                  mov    DWORD PTR [esp+0x20],0x0
00544a9b  f30f1144241c                      movss  DWORD PTR [esp+0x1c],xmm0
00544aa1  e88afcffff                        call   0x544730
00544aa6  837c241400                        cmp    DWORD PTR [esp+0x14],0x0
00544aab  7428                              je     0x544ad5
00544aad  85c0                              test   eax,eax
00544aaf  7424                              je     0x544ad5
00544ab1  d9442410                          fld    DWORD PTR [esp+0x10]
00544ab5  d9442418                          fld    DWORD PTR [esp+0x18]
00544ab9  dff1                              fcomip st,st(1)
00544abb  ddd8                              fstp   st(0)
00544abd  7616                              jbe    0x544ad5
00544abf  8b4604                            mov    eax,DWORD PTR [esi+0x4]
00544ac2  8b0c07                            mov    ecx,DWORD PTR [edi+eax*1]
00544ac5  f30f104c2410                      movss  xmm1,DWORD PTR [esp+0x10]
00544acb  f30f114c2418                      movss  DWORD PTR [esp+0x18],xmm1
00544ad1  894c241c                          mov    DWORD PTR [esp+0x1c],ecx
00544ad5  8b5608                            mov    edx,DWORD PTR [esi+0x8]
00544ad8  2b5604                            sub    edx,DWORD PTR [esi+0x4]
00544adb  43                                inc    ebx
00544adc  c1fa02                            sar    edx,0x2
00544adf  3bda                              cmp    ebx,edx
00544ae1  7291                              jb     0x544a74
00544ae3  8b74241c                          mov    esi,DWORD PTR [esp+0x1c]
00544ae7  85f6                              test   esi,esi
00544ae9  745e                              je     0x544b49
00544aeb  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
00544af2  7529                              jne    0x544b1d
00544af4  830d9043f90001                    or     DWORD PTR ds:0xf94390,0x1
00544afb  c744243000000000                  mov    DWORD PTR [esp+0x30],0x0
00544b03  e888caf9ff                        call   0x4e1590
00544b08  6880ccbc00                        push   0xbccc80
00544b0d  e808d83400                        call   0x89231a
00544b12  83c404                            add    esp,0x4
00544b15  c7442430ffffffff                  mov    DWORD PTR [esp+0x30],0xffffffff
00544b1d  803dc042f90000                    cmp    BYTE PTR ds:0xf942c0,0x0
00544b24  7523                              jne    0x544b49
00544b26  8b06                              mov    eax,DWORD PTR [esi]
00544b28  8b5064                            mov    edx,DWORD PTR [eax+0x64]
00544b2b  8bce                              mov    ecx,esi
00544b2d  ffd2                              call   edx
00544b2f  b801000000                        mov    eax,0x1
00544b34  8b4c2428                          mov    ecx,DWORD PTR [esp+0x28]
00544b38  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00544b3f  59                                pop    ecx
00544b40  5f                                pop    edi
00544b41  5e                                pop    esi
00544b42  5b                                pop    ebx
00544b43  8be5                              mov    esp,ebp
00544b45  5d                                pop    ebp
00544b46  c20400                            ret    0x4
00544b49  33c0                              xor    eax,eax
00544b4b  8b4c2428                          mov    ecx,DWORD PTR [esp+0x28]
00544b4f  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00544b56  59                                pop    ecx
00544b57  5f                                pop    edi
00544b58  5e                                pop    esi
00544b59  5b                                pop    ebx
00544b5a  8be5                              mov    esp,ebp
00544b5c  5d                                pop    ebp
00544b5d  c20400                            ret    0x4

# N18-point-intent-send 0x544020..0x544070
00544020  55                                push   ebp
00544021  8bec                              mov    ebp,esp
00544023  83ec08                            sub    esp,0x8
00544026  833d98a7fb0000                    cmp    DWORD PTR ds:0xfba798,0x0
0054402d  668b90f4000000                    mov    dx,WORD PTR [eax+0xf4]
00544034  668b80f6000000                    mov    ax,WORD PTR [eax+0xf6]
0054403b  b91c000000                        mov    ecx,0x1c
00544040  66894df8                          mov    WORD PTR [ebp-0x8],cx
00544044  668955fa                          mov    WORD PTR [ebp-0x6],dx
00544048  668945fc                          mov    WORD PTR [ebp-0x4],ax
0054404c  7515                              jne    0x544063
0054404e  8b0d54a8fb00                      mov    ecx,DWORD PTR ds:0xfba854
00544054  8b11                              mov    edx,DWORD PTR [ecx]
00544056  8b5210                            mov    edx,DWORD PTR [edx+0x10]
00544059  6a06                              push   0x6
0054405b  8d45f8                            lea    eax,[ebp-0x8]
0054405e  50                                push   eax
0054405f  6a00                              push   0x0
00544061  ffd2                              call   edx
00544063  8be5                              mov    esp,ebp
00544065  5d                                pop    ebp
00544066  c3                                ret
00544067  cc                                int3
00544068  cc                                int3
00544069  cc                                int3
0054406a  cc                                int3
0054406b  cc                                int3
0054406c  cc                                int3
0054406d  cc                                int3
0054406e  cc                                int3
0054406f  cc                                int3

# N19-point-category-action 0x544070..0x544730
00544070  55                                push   ebp
00544071  8bec                              mov    ebp,esp
00544073  83e4f8                            and    esp,0xfffffff8
00544076  6aff                              push   0xffffffff
00544078  6804789400                        push   0x947804
0054407d  64a100000000                      mov    eax,fs:0x0
00544083  50                                push   eax
00544084  83ec10                            sub    esp,0x10
00544087  53                                push   ebx
00544088  56                                push   esi
00544089  57                                push   edi
0054408a  a1201fd600                        mov    eax,ds:0xd61f20
0054408f  33c4                              xor    eax,esp
00544091  50                                push   eax
00544092  8d442420                          lea    eax,[esp+0x20]
00544096  64a300000000                      mov    fs:0x0,eax
0054409c  8bf1                              mov    esi,ecx
0054409e  0fb786f4000000                    movzx  eax,WORD PTR [esi+0xf4]
005440a5  6683f803                          cmp    ax,0x3
005440a9  0f8511030000                      jne    0x5443c0
005440af  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
005440b5  8b01                              mov    eax,DWORD PTR [ecx]
005440b7  8b5020                            mov    edx,DWORD PTR [eax+0x20]
005440ba  ffd2                              call   edx
005440bc  8bf8                              mov    edi,eax
005440be  85ff                              test   edi,edi
005440c0  745e                              je     0x544120
005440c2  d987a0000000                      fld    DWORD PTR [edi+0xa0]
005440c8  d8a6a0000000                      fsub   DWORD PTR [esi+0xa0]
005440ce  d95c2414                          fstp   DWORD PTR [esp+0x14]
005440d2  d987a4000000                      fld    DWORD PTR [edi+0xa4]
005440d8  d8a6a4000000                      fsub   DWORD PTR [esi+0xa4]
005440de  d95c2410                          fstp   DWORD PTR [esp+0x10]
005440e2  d9442410                          fld    DWORD PTR [esp+0x10]
005440e6  d9442414                          fld    DWORD PTR [esp+0x14]
005440ea  e8dbac3b00                        call   0x8fedca
005440ef  d95c2414                          fstp   DWORD PTR [esp+0x14]
005440f3  d9442414                          fld    DWORD PTR [esp+0x14]
005440f7  8b1f                              mov    ebx,DWORD PTR [edi]
005440f9  dc052858c500                      fadd   QWORD PTR ds:0xc55828
005440ff  51                                push   ecx
00544100  d95c2418                          fstp   DWORD PTR [esp+0x18]
00544104  d9442418                          fld    DWORD PTR [esp+0x18]
00544108  d91c24                            fstp   DWORD PTR [esp]
0054410b  e84073f7ff                        call   0x4bb450
00544110  8b5358                            mov    edx,DWORD PTR [ebx+0x58]
00544113  2c80                              sub    al,0x80
00544115  0fb6c0                            movzx  eax,al
00544118  83c404                            add    esp,0x4
0054411b  50                                push   eax
0054411c  8bcf                              mov    ecx,edi
0054411e  ffd2                              call   edx
00544120  f6059cb2fa0001                    test   BYTE PTR ds:0xfab29c,0x1
00544127  0fb786f6000000                    movzx  eax,WORD PTR [esi+0xf6]
0054412e  0fbff8                            movsx  edi,ax
00544131  7529                              jne    0x54415c
00544133  830d9cb2fa0001                    or     DWORD PTR ds:0xfab29c,0x1
0054413a  c744242800000000                  mov    DWORD PTR [esp+0x28],0x0
00544142  e819bdfbff                        call   0x4ffe60
00544147  6800cfbc00                        push   0xbccf00
0054414c  e8c9e13400                        call   0x89231a
00544151  83c404                            add    esp,0x4
00544154  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0054415c  57                                push   edi
0054415d  68a0b2fa00                        push   0xfab2a0
00544162  e819c9fbff                        call   0x500a80
00544167  83f805                            cmp    eax,0x5
0054416a  747b                              je     0x5441e7
0054416c  8b35d01bfe00                      mov    esi,DWORD PTR ds:0xfe1bd0
00544172  8d442414                          lea    eax,[esp+0x14]
00544176  50                                push   eax
00544177  8d4e08                            lea    ecx,[esi+0x8]
0054417a  8d442414                          lea    eax,[esp+0x14]
0054417e  897c2418                          mov    DWORD PTR [esp+0x18],edi
00544182  e839f72f00                        call   0x8438c0
00544187  8b760c                            mov    esi,DWORD PTR [esi+0xc]
0054418a  8b442410                          mov    eax,DWORD PTR [esp+0x10]
0054418e  3bc6                              cmp    eax,esi
00544190  0f847d050000                      je     0x544713
00544196  8b4010                            mov    eax,DWORD PTR [eax+0x10]
00544199  85c0                              test   eax,eax
0054419b  0f8472050000                      je     0x544713
005441a1  8b4840                            mov    ecx,DWORD PTR [eax+0x40]
005441a4  3b4844                            cmp    ecx,DWORD PTR [eax+0x44]
005441a7  0f8466050000                      je     0x544713
005441ad  6a1c                              push   0x1c
005441af  e8b4d03400                        call   0x891268
005441b4  8bf0                              mov    esi,eax
005441b6  83c404                            add    esp,0x4
005441b9  89742414                          mov    DWORD PTR [esp+0x14],esi
005441bd  c744242801000000                  mov    DWORD PTR [esp+0x28],0x1
005441c5  85f6                              test   esi,esi
005441c7  0f8426030000                      je     0x5444f3
005441cd  e88eaeecff                        call   0x40f060
005441d2  8b808c000000                      mov    eax,DWORD PTR [eax+0x8c]
005441d8  50                                push   eax
005441d9  8bd7                              mov    edx,edi
005441db  8bc6                              mov    eax,esi
005441dd  e89efd2000                        call   0x753f80
005441e2  e90e030000                        jmp    0x5444f5
005441e7  e8b409ecff                        call   0x404ba0
005441ec  8b804c5f0000                      mov    eax,DWORD PTR [eax+0x5f4c]
005441f2  83f803                            cmp    eax,0x3
005441f5  7413                              je     0x54420a
005441f7  83f807                            cmp    eax,0x7
005441fa  740e                              je     0x54420a
005441fc  83f817                            cmp    eax,0x17
005441ff  7409                              je     0x54420a
00544201  83f818                            cmp    eax,0x18
00544204  0f8509050000                      jne    0x544713
0054420a  e8c162edff                        call   0x41a4d0
0054420f  8b98d85e0000                      mov    ebx,DWORD PTR [eax+0x5ed8]
00544215  85db                              test   ebx,ebx
00544217  0f84af000000                      je     0x5442cc
0054421d  8bd3                              mov    edx,ebx
0054421f  e84c58ffff                        call   0x539a70
00544224  83f801                            cmp    eax,0x1
00544227  0f849f000000                      je     0x5442cc
0054422d  e88e12ecff                        call   0x4054c0
00544232  6a1c                              push   0x1c
00544234  e82fd03400                        call   0x891268
00544239  33f6                              xor    esi,esi
0054423b  83c404                            add    esp,0x4
0054423e  83cbff                            or     ebx,0xffffffff
00544241  3bc6                              cmp    eax,esi
00544243  741e                              je     0x544263
00544245  89700c                            mov    DWORD PTR [eax+0xc],esi
00544248  897018                            mov    DWORD PTR [eax+0x18],esi
0054424b  895804                            mov    DWORD PTR [eax+0x4],ebx
0054424e  895808                            mov    DWORD PTR [eax+0x8],ebx
00544251  c74010d6430f00                    mov    DWORD PTR [eax+0x10],0xf43d6
00544258  c700cc7bc400                      mov    DWORD PTR [eax],0xc47bcc
0054425e  897814                            mov    DWORD PTR [eax+0x14],edi
00544261  8bf0                              mov    esi,eax
00544263  e83808ecff                        call   0x404aa0
00544268  8b80c4130000                      mov    eax,DWORD PTR [eax+0x13c4]
0054426e  50                                push   eax
0054426f  56                                push   esi
00544270  83ec1c                            sub    esp,0x1c
00544273  8bcc                              mov    ecx,esp
00544275  89642438                          mov    DWORD PTR [esp+0x38],esp
00544279  68fcd1be00                        push   0xbed1fc
0054427e  e8cddfebff                        call   0x402250
00544283  6a20                              push   0x20
00544285  c744245002000000                  mov    DWORD PTR [esp+0x50],0x2
0054428d  e81e120400                        call   0x5854b0
00544292  8bf0                              mov    esi,eax
00544294  e897100400                        call   0x585330
00544299  83ec1c                            sub    esp,0x1c
0054429c  8bcc                              mov    ecx,esp
0054429e  89642450                          mov    DWORD PTR [esp+0x50],esp
005442a2  50                                push   eax
005442a3  e8a8dfebff                        call   0x402250
005442a8  68cf000000                        push   0xcf
005442ad  895c246c                          mov    DWORD PTR [esp+0x6c],ebx
005442b1  e8ba6f0400                        call   0x58b270
005442b6  83c444                            add    esp,0x44
005442b9  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
005442bd  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
005442c4  59                                pop    ecx
005442c5  5f                                pop    edi
005442c6  5e                                pop    esi
005442c7  5b                                pop    ebx
005442c8  8be5                              mov    esp,ebp
005442ca  5d                                pop    ebp
005442cb  c3                                ret
005442cc  53                                push   ebx
005442cd  e81e58ffff                        call   0x539af0
005442d2  e8e911ecff                        call   0x4054c0
005442d7  6a20                              push   0x20
005442d9  e88acf3400                        call   0x891268
005442de  83c404                            add    esp,0x4
005442e1  85c0                              test   eax,eax
005442e3  743e                              je     0x544323
005442e5  0fb78ef6000000                    movzx  ecx,WORD PTR [esi+0xf6]
005442ec  0fb796f4000000                    movzx  edx,WORD PTR [esi+0xf4]
005442f3  0fbfd2                            movsx  edx,dx
005442f6  0fbfc9                            movsx  ecx,cx
005442f9  83cbff                            or     ebx,0xffffffff
005442fc  895804                            mov    DWORD PTR [eax+0x4],ebx
005442ff  895808                            mov    DWORD PTR [eax+0x8],ebx
00544302  c7400c00000000                    mov    DWORD PTR [eax+0xc],0x0
00544309  c74010d9430f00                    mov    DWORD PTR [eax+0x10],0xf43d9
00544310  c700e47bc400                      mov    DWORD PTR [eax],0xc47be4
00544316  897814                            mov    DWORD PTR [eax+0x14],edi
00544319  895018                            mov    DWORD PTR [eax+0x18],edx
0054431c  89481c                            mov    DWORD PTR [eax+0x1c],ecx
0054431f  8bf0                              mov    esi,eax
00544321  eb05                              jmp    0x544328
00544323  33f6                              xor    esi,esi
00544325  83cbff                            or     ebx,0xffffffff
00544328  e87307ecff                        call   0x404aa0
0054432d  8b80c4130000                      mov    eax,DWORD PTR [eax+0x13c4]
00544333  50                                push   eax
00544334  56                                push   esi
00544335  83ec1c                            sub    esp,0x1c
00544338  8bcc                              mov    ecx,esp
0054433a  8964243c                          mov    DWORD PTR [esp+0x3c],esp
0054433e  68fcd1be00                        push   0xbed1fc
00544343  e808dfebff                        call   0x402250
00544348  c744244c03000000                  mov    DWORD PTR [esp+0x4c],0x3
00544350  c744243821000000                  mov    DWORD PTR [esp+0x38],0x21
00544358  e853110400                        call   0x5854b0
0054435d  8bf0                              mov    esi,eax
0054435f  8d542438                          lea    edx,[esp+0x38]
00544363  52                                push   edx
00544364  8d442438                          lea    eax,[esp+0x38]
00544368  8bce                              mov    ecx,esi
0054436a  e881fd0200                        call   0x5740f0
0054436f  8b7604                            mov    esi,DWORD PTR [esi+0x4]
00544372  8b442434                          mov    eax,DWORD PTR [esp+0x34]
00544376  3bc6                              cmp    eax,esi
00544378  740d                              je     0x544387
0054437a  83c010                            add    eax,0x10
0054437d  83781408                          cmp    DWORD PTR [eax+0x14],0x8
00544381  720a                              jb     0x54438d
00544383  8b00                              mov    eax,DWORD PTR [eax]
00544385  eb06                              jmp    0x54438d
00544387  cc                                int3
00544388  b8fcd1be00                        mov    eax,0xbed1fc
0054438d  83ec1c                            sub    esp,0x1c
00544390  8bcc                              mov    ecx,esp
00544392  89642454                          mov    DWORD PTR [esp+0x54],esp
00544396  50                                push   eax
00544397  e8b4deebff                        call   0x402250
0054439c  68cf000000                        push   0xcf
005443a1  895c246c                          mov    DWORD PTR [esp+0x6c],ebx
005443a5  e8c66e0400                        call   0x58b270
005443aa  83c444                            add    esp,0x44
005443ad  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
005443b1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
005443b8  59                                pop    ecx
005443b9  5f                                pop    edi
005443ba  5e                                pop    esi
005443bb  5b                                pop    ebx
005443bc  8be5                              mov    esp,ebp
005443be  5d                                pop    ebp
005443bf  c3                                ret
005443c0  bb04000000                        mov    ebx,0x4
005443c5  663bc3                            cmp    ax,bx
005443c8  7537                              jne    0x544401
005443ca  391daca7fb00                      cmp    DWORD PTR ds:0xfba7ac,ebx
005443d0  0f853d030000                      jne    0x544713
005443d6  0fbf86f6000000                    movsx  eax,WORD PTR [esi+0xf6]
005443dd  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
005443e3  c78481b400000001000000            mov    DWORD PTR [ecx+eax*4+0xb4],0x1
005443ee  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
005443f2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
005443f9  59                                pop    ecx
005443fa  5f                                pop    edi
005443fb  5e                                pop    esi
005443fc  5b                                pop    ebx
005443fd  8be5                              mov    esp,ebp
005443ff  5d                                pop    ebp
00544400  c3                                ret
00544401  6683f805                          cmp    ax,0x5
00544405  7571                              jne    0x544478
00544407  e89407ecff                        call   0x404ba0
0054440c  83b84c5f000003                    cmp    DWORD PTR [eax+0x5f4c],0x3
00544413  0f85fa020000                      jne    0x544713
00544419  e842acecff                        call   0x40f060
0054441e  8b80f8000000                      mov    eax,DWORD PTR [eax+0xf8]
00544424  85c0                              test   eax,eax
00544426  0f84e7020000                      je     0x544713
0054442c  80782800                          cmp    BYTE PTR [eax+0x28],0x0
00544430  7429                              je     0x54445b
00544432  e809eeedff                        call   0x423240
00544437  8bf8                              mov    edi,eax
00544439  e8622bfdff                        call   0x516fa0
0054443e  e83d02edff                        call   0x414680
00544443  e8a8f1f5ff                        call   0x4a35f0
00544448  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0054444c  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00544453  59                                pop    ecx
00544454  5f                                pop    edi
00544455  5e                                pop    esi
00544456  5b                                pop    ebx
00544457  8be5                              mov    esp,ebp
00544459  5d                                pop    ebp
0054445a  c3                                ret
0054445b  e82002edff                        call   0x414680
00544460  e85bf1f5ff                        call   0x4a35c0
00544465  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
00544469  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00544470  59                                pop    ecx
00544471  5f                                pop    edi
00544472  5e                                pop    esi
00544473  5b                                pop    ebx
00544474  8be5                              mov    esp,ebp
00544476  5d                                pop    ebp
00544477  c3                                ret
00544478  6683f802                          cmp    ax,0x2
0054447c  0f85a7000000                      jne    0x544529
00544482  0fb786f6000000                    movzx  eax,WORD PTR [esi+0xf6]
00544489  0fbff8                            movsx  edi,ax
0054448c  a1b41dfe00                        mov    eax,ds:0xfe1db4
00544491  e87a74fbff                        call   0x4fb910
00544496  8bf8                              mov    edi,eax
00544498  85ff                              test   edi,edi
0054449a  0f8473020000                      je     0x544713
005444a0  8b570c                            mov    edx,DWORD PTR [edi+0xc]
005444a3  8b35d01bfe00                      mov    esi,DWORD PTR ds:0xfe1bd0
005444a9  52                                push   edx
005444aa  e8612bfeff                        call   0x527010
005444af  85c0                              test   eax,eax
005444b1  0f845c020000                      je     0x544713
005444b7  8b4840                            mov    ecx,DWORD PTR [eax+0x40]
005444ba  3b4844                            cmp    ecx,DWORD PTR [eax+0x44]
005444bd  0f8450020000                      je     0x544713
005444c3  6a1c                              push   0x1c
005444c5  e89ecd3400                        call   0x891268
005444ca  8bf0                              mov    esi,eax
005444cc  83c404                            add    esp,0x4
005444cf  89742418                          mov    DWORD PTR [esp+0x18],esi
005444d3  895c2428                          mov    DWORD PTR [esp+0x28],ebx
005444d7  85f6                              test   esi,esi
005444d9  7418                              je     0x5444f3
005444db  e880abecff                        call   0x40f060
005444e0  8b808c000000                      mov    eax,DWORD PTR [eax+0x8c]
005444e6  8b570c                            mov    edx,DWORD PTR [edi+0xc]
005444e9  50                                push   eax
005444ea  8bc6                              mov    eax,esi
005444ec  e88ffa2000                        call   0x753f80
005444f1  eb02                              jmp    0x5444f5
005444f3  33c0                              xor    eax,eax
005444f5  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
005444fd  89442414                          mov    DWORD PTR [esp+0x14],eax
00544501  e89a05ecff                        call   0x404aa0
00544506  8d542414                          lea    edx,[esp+0x14]
0054450a  52                                push   edx
0054450b  8db05c140000                      lea    esi,[eax+0x145c]
00544511  e84afd2b00                        call   0x804260
00544516  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0054451a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00544521  59                                pop    ecx
00544522  5f                                pop    edi
00544523  5e                                pop    esi
00544524  5b                                pop    ebx
00544525  8be5                              mov    esp,ebp
00544527  5d                                pop    ebp
00544528  c3                                ret
00544529  e87206ecff                        call   0x404ba0
0054452e  8b804c5f0000                      mov    eax,DWORD PTR [eax+0x5f4c]
00544534  83c0e9                            add    eax,0xffffffe9
00544537  83f801                            cmp    eax,0x1
0054453a  0f87cc010000                      ja     0x54470c
00544540  e88b5fedff                        call   0x41a4d0
00544545  8bb8d85e0000                      mov    edi,DWORD PTR [eax+0x5ed8]
0054454b  85ff                              test   edi,edi
0054454d  0f84b9010000                      je     0x54470c
00544553  e84806ecff                        call   0x404ba0
00544558  8b80505f0000                      mov    eax,DWORD PTR [eax+0x5f50]
0054455e  50                                push   eax
0054455f  8bd7                              mov    edx,edi
00544561  e83a55ffff                        call   0x539aa0
00544566  8bd7                              mov    edx,edi
00544568  8bd8                              mov    ebx,eax
0054456a  e80155ffff                        call   0x539a70
0054456f  8bf8                              mov    edi,eax
00544571  85db                              test   ebx,ebx
00544573  7406                              je     0x54457b
00544575  807b0600                          cmp    BYTE PTR [ebx+0x6],0x0
00544579  7412                              je     0x54458d
0054457b  e82006ecff                        call   0x404ba0
00544580  83b84c5f000005                    cmp    DWORD PTR [eax+0x5f4c],0x5
00544587  0f85b2000000                      jne    0x54463f
0054458d  e82e0fecff                        call   0x4054c0
00544592  6a1c                              push   0x1c
00544594  e8cfcc3400                        call   0x891268
00544599  83c404                            add    esp,0x4
0054459c  85c0                              test   eax,eax
0054459e  7423                              je     0x5445c3
005445a0  0fb78ef6000000                    movzx  ecx,WORD PTR [esi+0xf6]
005445a7  0fb796f4000000                    movzx  edx,WORD PTR [esi+0xf4]
005445ae  0fbfc9                            movsx  ecx,cx
005445b1  51                                push   ecx
005445b2  0fbfd2                            movsx  edx,dx
005445b5  6895430f00                        push   0xf4395
005445ba  e841f82000                        call   0x753e00
005445bf  8bf0                              mov    esi,eax
005445c1  eb02                              jmp    0x5445c5
005445c3  33f6                              xor    esi,esi
005445c5  e8d604ecff                        call   0x404aa0
005445ca  8b80c4130000                      mov    eax,DWORD PTR [eax+0x13c4]
005445d0  50                                push   eax
005445d1  56                                push   esi
005445d2  6896010000                        push   0x196
005445d7  e8d40e0400                        call   0x5854b0
005445dc  8bf0                              mov    esi,eax
005445de  e84d0d0400                        call   0x585330
005445e3  83ec1c                            sub    esp,0x1c
005445e6  8bcc                              mov    ecx,esp
005445e8  8964243c                          mov    DWORD PTR [esp+0x3c],esp
005445ec  50                                push   eax
005445ed  e85edcebff                        call   0x402250
005445f2  6a3b                              push   0x3b
005445f4  c744245005000000                  mov    DWORD PTR [esp+0x50],0x5
005445fc  e8af0e0400                        call   0x5854b0
00544601  8bf0                              mov    esi,eax
00544603  e8280d0400                        call   0x585330
00544608  83ec1c                            sub    esp,0x1c
0054460b  8bcc                              mov    ecx,esp
0054460d  89642454                          mov    DWORD PTR [esp+0x54],esp
00544611  50                                push   eax
00544612  e839dcebff                        call   0x402250
00544617  68cf000000                        push   0xcf
0054461c  c744246cffffffff                  mov    DWORD PTR [esp+0x6c],0xffffffff
00544624  e8476c0400                        call   0x58b270
00544629  83c444                            add    esp,0x44
0054462c  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
00544630  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00544637  59                                pop    ecx
00544638  5f                                pop    edi
00544639  5e                                pop    esi
0054463a  5b                                pop    ebx
0054463b  8be5                              mov    esp,ebp
0054463d  5d                                pop    ebp
0054463e  c3                                ret
0054463f  85db                              test   ebx,ebx
00544641  0f84c5000000                      je     0x54470c
00544647  807b0600                          cmp    BYTE PTR [ebx+0x6],0x0
0054464b  0f84bb000000                      je     0x54470c
00544651  83ff01                            cmp    edi,0x1
00544654  0f86b2000000                      jbe    0x54470c
0054465a  e8610eecff                        call   0x4054c0
0054465f  6a1c                              push   0x1c
00544661  e802cc3400                        call   0x891268
00544666  83c404                            add    esp,0x4
00544669  85c0                              test   eax,eax
0054466b  7423                              je     0x544690
0054466d  0fb78ef6000000                    movzx  ecx,WORD PTR [esi+0xf6]
00544674  0fb796f4000000                    movzx  edx,WORD PTR [esi+0xf4]
0054467b  0fbfc9                            movsx  ecx,cx
0054467e  51                                push   ecx
0054467f  0fbfd2                            movsx  edx,dx
00544682  6895430f00                        push   0xf4395
00544687  e874f72000                        call   0x753e00
0054468c  8bf0                              mov    esi,eax
0054468e  eb02                              jmp    0x544692
00544690  33f6                              xor    esi,esi
00544692  e80904ecff                        call   0x404aa0
00544697  8b80c4130000                      mov    eax,DWORD PTR [eax+0x13c4]
0054469d  50                                push   eax
0054469e  56                                push   esi
0054469f  6896010000                        push   0x196
005446a4  e8070e0400                        call   0x5854b0
005446a9  8bf0                              mov    esi,eax
005446ab  e8800c0400                        call   0x585330
005446b0  83ec1c                            sub    esp,0x1c
005446b3  8bcc                              mov    ecx,esp
005446b5  8964243c                          mov    DWORD PTR [esp+0x3c],esp
005446b9  50                                push   eax
005446ba  e891dbebff                        call   0x402250
005446bf  6a31                              push   0x31
005446c1  c744245006000000                  mov    DWORD PTR [esp+0x50],0x6
005446c9  e8e20d0400                        call   0x5854b0
005446ce  8bf0                              mov    esi,eax
005446d0  e85b0c0400                        call   0x585330
005446d5  83ec1c                            sub    esp,0x1c
005446d8  8bcc                              mov    ecx,esp
005446da  89642454                          mov    DWORD PTR [esp+0x54],esp
005446de  50                                push   eax
005446df  e86cdbebff                        call   0x402250
005446e4  68cf000000                        push   0xcf
005446e9  c744246cffffffff                  mov    DWORD PTR [esp+0x6c],0xffffffff
005446f1  e87a6b0400                        call   0x58b270
005446f6  83c444                            add    esp,0x44
005446f9  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
005446fd  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00544704  59                                pop    ecx
00544705  5f                                pop    edi
00544706  5e                                pop    esi
00544707  5b                                pop    ebx
00544708  8be5                              mov    esp,ebp
0054470a  5d                                pop    ebp
0054470b  c3                                ret
0054470c  8bc6                              mov    eax,esi
0054470e  e80df9ffff                        call   0x544020
00544713  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
00544717  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0054471e  59                                pop    ecx
0054471f  5f                                pop    edi
00544720  5e                                pop    esi
00544721  5b                                pop    ebx
00544722  8be5                              mov    esp,ebp
00544724  5d                                pop    ebp
00544725  c3                                ret
00544726  cc                                int3
00544727  cc                                int3
00544728  cc                                int3
00544729  cc                                int3
0054472a  cc                                int3
0054472b  cc                                int3
0054472c  cc                                int3
0054472d  cc                                int3
0054472e  cc                                int3
0054472f  cc                                int3

# N20-event-object-table-parser 0x4c62b0..0x4c66c0
004c62b0  55                                push   ebp
004c62b1  8bec                              mov    ebp,esp
004c62b3  6aff                              push   0xffffffff
004c62b5  685b4d9200                        push   0x924d5b
004c62ba  64a100000000                      mov    eax,fs:0x0
004c62c0  50                                push   eax
004c62c1  81ecd0000000                      sub    esp,0xd0
004c62c7  a1201fd600                        mov    eax,ds:0xd61f20
004c62cc  33c5                              xor    eax,ebp
004c62ce  8945ec                            mov    DWORD PTR [ebp-0x14],eax
004c62d1  53                                push   ebx
004c62d2  56                                push   esi
004c62d3  57                                push   edi
004c62d4  50                                push   eax
004c62d5  8d45f4                            lea    eax,[ebp-0xc]
004c62d8  64a300000000                      mov    fs:0x0,eax
004c62de  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
004c62e1  8d8d5cffffff                      lea    ecx,[ebp-0xa4]
004c62e7  51                                push   ecx
004c62e8  b9f074c000                        mov    ecx,0xc074f0
004c62ed  89854cffffff                      mov    DWORD PTR [ebp-0xb4],eax
004c62f3  e8388b2600                        call   0x72ee30
004c62f8  33ff                              xor    edi,edi
004c62fa  897dfc                            mov    DWORD PTR [ebp-0x4],edi
004c62fd  8b8d7cffffff                      mov    ecx,DWORD PTR [ebp-0x84]
004c6303  bb10000000                        mov    ebx,0x10
004c6308  395d90                            cmp    DWORD PTR [ebp-0x70],ebx
004c630b  7306                              jae    0x4c6313
004c630d  8d8d7cffffff                      lea    ecx,[ebp-0x84]
004c6313  57                                push   edi
004c6314  8db55cffffff                      lea    esi,[ebp-0xa4]
004c631a  e8f18d2600                        call   0x72f110
004c631f  807da000                          cmp    BYTE PTR [ebp-0x60],0x0
004c6323  7442                              je     0x4c6367
004c6325  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004c632c  c7855cffffff9423bf00              mov    DWORD PTR [ebp-0xa4],0xbf2394
004c6336  395dbc                            cmp    DWORD PTR [ebp-0x44],ebx
004c6339  720c                              jb     0x4c6347
004c633b  8b55a8                            mov    edx,DWORD PTR [ebp-0x58]
004c633e  52                                push   edx
004c633f  e8c8ae3c00                        call   0x89120c
004c6344  83c404                            add    esp,0x4
004c6347  8d8d5cffffff                      lea    ecx,[ebp-0xa4]
004c634d  c745bc0f000000                    mov    DWORD PTR [ebp-0x44],0xf
004c6354  897db8                            mov    DWORD PTR [ebp-0x48],edi
004c6357  c645a800                          mov    BYTE PTR [ebp-0x58],0x0
004c635b  e8e07c2600                        call   0x72e040
004c6360  33c0                              xor    eax,eax
004c6362  e9b8020000                        jmp    0x4c661f
004c6367  680875c000                        push   0xc07508
004c636c  8d855cffffff                      lea    eax,[ebp-0xa4]
004c6372  e8697f2600                        call   0x72e2e0
004c6377  3bc7                              cmp    eax,edi
004c6379  751c                              jne    0x4c6397
004c637b  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004c6382  c7855cffffff9423bf00              mov    DWORD PTR [ebp-0xa4],0xbf2394
004c638c  395dbc                            cmp    DWORD PTR [ebp-0x44],ebx
004c638f  72b6                              jb     0x4c6347
004c6391  8b45a8                            mov    eax,DWORD PTR [ebp-0x58]
004c6394  50                                push   eax
004c6395  eba8                              jmp    0x4c633f
004c6397  681875c000                        push   0xc07518
004c639c  e83f7f2600                        call   0x72e2e0
004c63a1  3bc7                              cmp    eax,edi
004c63a3  0f8436020000                      je     0x4c65df
004c63a9  682075c000                        push   0xc07520
004c63ae  e82d7f2600                        call   0x72e2e0
004c63b3  8bd8                              mov    ebx,eax
004c63b5  899d58ffffff                      mov    DWORD PTR [ebp-0xa8],ebx
004c63bb  3bdf                              cmp    ebx,edi
004c63bd  0f8417020000                      je     0x4c65da
004c63c3  eb06                              jmp    0x4c63cb
004c63c5  8b9d58ffffff                      mov    ebx,DWORD PTR [ebp-0xa8]
004c63cb  8b13                              mov    edx,DWORD PTR [ebx]
004c63cd  8b4214                            mov    eax,DWORD PTR [edx+0x14]
004c63d0  8bcb                              mov    ecx,ebx
004c63d2  ffd0                              call   eax
004c63d4  682cb8bf00                        push   0xbfb82c
004c63d9  8d7844                            lea    edi,[eax+0x44]
004c63dc  e8bf9c2600                        call   0x7300a0
004c63e1  85c0                              test   eax,eax
004c63e3  7420                              je     0x4c6405
004c63e5  83c030                            add    eax,0x30
004c63e8  83781410                          cmp    DWORD PTR [eax+0x14],0x10
004c63ec  7202                              jb     0x4c63f0
004c63ee  8b00                              mov    eax,DWORD PTR [eax]
004c63f0  85c0                              test   eax,eax
004c63f2  7411                              je     0x4c6405
004c63f4  50                                push   eax
004c63f5  e8bab33c00                        call   0x8917b4
004c63fa  83c404                            add    esp,0x4
004c63fd  898550ffffff                      mov    DWORD PTR [ebp-0xb0],eax
004c6403  eb0a                              jmp    0x4c640f
004c6405  c78550ffffff00000000              mov    DWORD PTR [ebp-0xb0],0x0
004c640f  682475c000                        push   0xc07524
004c6414  8bc3                              mov    eax,ebx
004c6416  e8c57e2600                        call   0x72e2e0
004c641b  898554ffffff                      mov    DWORD PTR [ebp-0xac],eax
004c6421  85c0                              test   eax,eax
004c6423  0f8410010000                      je     0x4c6539
004c6429  eb0b                              jmp    0x4c6436
004c642b  eb03                              jmp    0x4c6430
004c642d  8d4900                            lea    ecx,[ecx+0x0]
004c6430  8b8554ffffff                      mov    eax,DWORD PTR [ebp-0xac]
004c6436  8b10                              mov    edx,DWORD PTR [eax]
004c6438  8bc8                              mov    ecx,eax
004c643a  8b4214                            mov    eax,DWORD PTR [edx+0x14]
004c643d  ffd0                              call   eax
004c643f  8bb094000000                      mov    esi,DWORD PTR [eax+0x94]
004c6445  8d7844                            lea    edi,[eax+0x44]
004c6448  3bf7                              cmp    esi,edi
004c644a  7430                              je     0x4c647c
004c644c  8d642400                          lea    esp,[esp+0x0]
004c6450  8d4614                            lea    eax,[esi+0x14]
004c6453  bb10000000                        mov    ebx,0x10
004c6458  395814                            cmp    DWORD PTR [eax+0x14],ebx
004c645b  7202                              jb     0x4c645f
004c645d  8b00                              mov    eax,DWORD PTR [eax]
004c645f  682cb8bf00                        push   0xbfb82c
004c6464  50                                push   eax
004c6465  e847d83c00                        call   0x893cb1
004c646a  83c408                            add    esp,0x8
004c646d  85c0                              test   eax,eax
004c646f  0f84c8010000                      je     0x4c663d
004c6475  8b7650                            mov    esi,DWORD PTR [esi+0x50]
004c6478  3bf7                              cmp    esi,edi
004c647a  75d4                              jne    0x4c6450
004c647c  33db                              xor    ebx,ebx
004c647e  8b7750                            mov    esi,DWORD PTR [edi+0x50]
004c6481  3bf7                              cmp    esi,edi
004c6483  7428                              je     0x4c64ad
004c6485  837e2810                          cmp    DWORD PTR [esi+0x28],0x10
004c6489  8d4614                            lea    eax,[esi+0x14]
004c648c  7202                              jb     0x4c6490
004c648e  8b00                              mov    eax,DWORD PTR [eax]
004c6490  682c75c000                        push   0xc0752c
004c6495  50                                push   eax
004c6496  e816d83c00                        call   0x893cb1
004c649b  83c408                            add    esp,0x8
004c649e  85c0                              test   eax,eax
004c64a0  0f84c1010000                      je     0x4c6667
004c64a6  8b7650                            mov    esi,DWORD PTR [esi+0x50]
004c64a9  3bf7                              cmp    esi,edi
004c64ab  75d8                              jne    0x4c6485
004c64ad  33c0                              xor    eax,eax
004c64af  8b7750                            mov    esi,DWORD PTR [edi+0x50]
004c64b2  8944ddd4                          mov    DWORD PTR [ebp+ebx*8-0x2c],eax
004c64b6  3bf7                              cmp    esi,edi
004c64b8  742e                              je     0x4c64e8
004c64ba  8d9b00000000                      lea    ebx,[ebx+0x0]
004c64c0  837e2810                          cmp    DWORD PTR [esi+0x28],0x10
004c64c4  8d4614                            lea    eax,[esi+0x14]
004c64c7  7202                              jb     0x4c64cb
004c64c9  8b00                              mov    eax,DWORD PTR [eax]
004c64cb  683475c000                        push   0xc07534
004c64d0  50                                push   eax
004c64d1  e8dbd73c00                        call   0x893cb1
004c64d6  83c408                            add    esp,0x8
004c64d9  85c0                              test   eax,eax
004c64db  0f84af010000                      je     0x4c6690
004c64e1  8b7650                            mov    esi,DWORD PTR [esi+0x50]
004c64e4  3bf7                              cmp    esi,edi
004c64e6  75d8                              jne    0x4c64c0
004c64e8  33c0                              xor    eax,eax
004c64ea  8d7810                            lea    edi,[eax+0x10]
004c64ed  8b8d54ffffff                      mov    ecx,DWORD PTR [ebp-0xac]
004c64f3  8b7140                            mov    esi,DWORD PTR [ecx+0x40]
004c64f6  8944ddd8                          mov    DWORD PTR [ebp+ebx*8-0x28],eax
004c64fa  85f6                              test   esi,esi
004c64fc  7425                              je     0x4c6523
004c64fe  8bff                              mov    edi,edi
004c6500  397e34                            cmp    DWORD PTR [esi+0x34],edi
004c6503  8d4620                            lea    eax,[esi+0x20]
004c6506  7202                              jb     0x4c650a
004c6508  8b00                              mov    eax,DWORD PTR [eax]
004c650a  682475c000                        push   0xc07524
004c650f  50                                push   eax
004c6510  e89cd73c00                        call   0x893cb1
004c6515  83c408                            add    esp,0x8
004c6518  85c0                              test   eax,eax
004c651a  7409                              je     0x4c6525
004c651c  8b7640                            mov    esi,DWORD PTR [esi+0x40]
004c651f  85f6                              test   esi,esi
004c6521  75dd                              jne    0x4c6500
004c6523  33f6                              xor    esi,esi
004c6525  89b554ffffff                      mov    DWORD PTR [ebp-0xac],esi
004c652b  85f6                              test   esi,esi
004c652d  0f85fdfeffff                      jne    0x4c6430
004c6533  8b9d58ffffff                      mov    ebx,DWORD PTR [ebp-0xa8]
004c6539  668b9550ffffff                    mov    dx,WORD PTR [ebp-0xb0]
004c6540  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
004c6543  8b4dd8                            mov    ecx,DWORD PTR [ebp-0x28]
004c6546  8bb54cffffff                      mov    esi,DWORD PTR [ebp-0xb4]
004c654c  66899530ffffff                    mov    WORD PTR [ebp-0xd0],dx
004c6553  8b55dc                            mov    edx,DWORD PTR [ebp-0x24]
004c6556  898534ffffff                      mov    DWORD PTR [ebp-0xcc],eax
004c655c  8b45e0                            mov    eax,DWORD PTR [ebp-0x20]
004c655f  898d38ffffff                      mov    DWORD PTR [ebp-0xc8],ecx
004c6565  8b4de4                            mov    ecx,DWORD PTR [ebp-0x1c]
004c6568  89953cffffff                      mov    DWORD PTR [ebp-0xc4],edx
004c656e  8b55e8                            mov    edx,DWORD PTR [ebp-0x18]
004c6571  898540ffffff                      mov    DWORD PTR [ebp-0xc0],eax
004c6577  8dbd30ffffff                      lea    edi,[ebp-0xd0]
004c657d  8bc6                              mov    eax,esi
004c657f  898d44ffffff                      mov    DWORD PTR [ebp-0xbc],ecx
004c6585  899548ffffff                      mov    DWORD PTR [ebp-0xb8],edx
004c658b  e830080000                        call   0x4c6dc0
004c6590  50                                push   eax
004c6591  56                                push   esi
004c6592  8db528ffffff                      lea    esi,[ebp-0xd8]
004c6598  e8e3050000                        call   0x4c6b80
004c659d  8b7340                            mov    esi,DWORD PTR [ebx+0x40]
004c65a0  85f6                              test   esi,esi
004c65a2  7424                              je     0x4c65c8
004c65a4  837e3410                          cmp    DWORD PTR [esi+0x34],0x10
004c65a8  8d4620                            lea    eax,[esi+0x20]
004c65ab  7202                              jb     0x4c65af
004c65ad  8b00                              mov    eax,DWORD PTR [eax]
004c65af  682075c000                        push   0xc07520
004c65b4  50                                push   eax
004c65b5  e8f7d63c00                        call   0x893cb1
004c65ba  83c408                            add    esp,0x8
004c65bd  85c0                              test   eax,eax
004c65bf  7409                              je     0x4c65ca
004c65c1  8b7640                            mov    esi,DWORD PTR [esi+0x40]
004c65c4  85f6                              test   esi,esi
004c65c6  75dc                              jne    0x4c65a4
004c65c8  33f6                              xor    esi,esi
004c65ca  89b558ffffff                      mov    DWORD PTR [ebp-0xa8],esi
004c65d0  85f6                              test   esi,esi
004c65d2  0f85edfdffff                      jne    0x4c63c5
004c65d8  33ff                              xor    edi,edi
004c65da  bb10000000                        mov    ebx,0x10
004c65df  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004c65e6  c7855cffffff9423bf00              mov    DWORD PTR [ebp-0xa4],0xbf2394
004c65f0  395dbc                            cmp    DWORD PTR [ebp-0x44],ebx
004c65f3  720c                              jb     0x4c6601
004c65f5  8b45a8                            mov    eax,DWORD PTR [ebp-0x58]
004c65f8  50                                push   eax
004c65f9  e80eac3c00                        call   0x89120c
004c65fe  83c404                            add    esp,0x4
004c6601  8d8d5cffffff                      lea    ecx,[ebp-0xa4]
004c6607  c745bc0f000000                    mov    DWORD PTR [ebp-0x44],0xf
004c660e  897db8                            mov    DWORD PTR [ebp-0x48],edi
004c6611  c645a800                          mov    BYTE PTR [ebp-0x58],0x0
004c6615  e8267a2600                        call   0x72e040
004c661a  b801000000                        mov    eax,0x1
004c661f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004c6622  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004c6629  59                                pop    ecx
004c662a  5f                                pop    edi
004c662b  5e                                pop    esi
004c662c  5b                                pop    ebx
004c662d  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
004c6630  33cd                              xor    ecx,ebp
004c6632  e8caa93c00                        call   0x891001
004c6637  8be5                              mov    esp,ebp
004c6639  5d                                pop    ebp
004c663a  c20400                            ret    0x4
004c663d  85f6                              test   esi,esi
004c663f  0f8437feffff                      je     0x4c647c
004c6645  395e44                            cmp    DWORD PTR [esi+0x44],ebx
004c6648  8d4630                            lea    eax,[esi+0x30]
004c664b  7202                              jb     0x4c664f
004c664d  8b00                              mov    eax,DWORD PTR [eax]
004c664f  85c0                              test   eax,eax
004c6651  0f8425feffff                      je     0x4c647c
004c6657  50                                push   eax
004c6658  e857b13c00                        call   0x8917b4
004c665d  83c404                            add    esp,0x4
004c6660  8bd8                              mov    ebx,eax
004c6662  e917feffff                        jmp    0x4c647e
004c6667  85f6                              test   esi,esi
004c6669  0f843efeffff                      je     0x4c64ad
004c666f  837e4410                          cmp    DWORD PTR [esi+0x44],0x10
004c6673  8d4630                            lea    eax,[esi+0x30]
004c6676  7202                              jb     0x4c667a
004c6678  8b00                              mov    eax,DWORD PTR [eax]
004c667a  85c0                              test   eax,eax
004c667c  0f842bfeffff                      je     0x4c64ad
004c6682  50                                push   eax
004c6683  e82cb13c00                        call   0x8917b4
004c6688  83c404                            add    esp,0x4
004c668b  e91ffeffff                        jmp    0x4c64af
004c6690  85f6                              test   esi,esi
004c6692  0f8450feffff                      je     0x4c64e8
004c6698  8d4630                            lea    eax,[esi+0x30]
004c669b  bf10000000                        mov    edi,0x10
004c66a0  397814                            cmp    DWORD PTR [eax+0x14],edi
004c66a3  7202                              jb     0x4c66a7
004c66a5  8b00                              mov    eax,DWORD PTR [eax]
004c66a7  85c0                              test   eax,eax
004c66a9  0f8439feffff                      je     0x4c64e8
004c66af  50                                push   eax
004c66b0  e8ffb03c00                        call   0x8917b4
004c66b5  83c404                            add    esp,0x4
004c66b8  e930feffff                        jmp    0x4c64ed
004c66bd  cc                                int3
004c66be  cc                                int3
004c66bf  cc                                int3

# N21-bound-clamp 0x82ce80..0x82cee0
0082ce80  d9ee                              fldz
0082ce82  d811                              fcom   DWORD PTR [ecx]
0082ce84  dfe0                              fnstsw ax
0082ce86  d9e8                              fld1
0082ce88  f6c441                            test   ah,0x41
0082ce8b  7506                              jne    0x82ce93
0082ce8d  d9c9                              fxch   st(1)
0082ce8f  d911                              fst    DWORD PTR [ecx]
0082ce91  eb17                              jmp    0x82ceaa
0082ce93  d901                              fld    DWORD PTR [ecx]
0082ce95  d9420c                            fld    DWORD PTR [edx+0xc]
0082ce98  ded9                              fcompp
0082ce9a  dfe0                              fnstsw ax
0082ce9c  f6c441                            test   ah,0x41
0082ce9f  7a07                              jp     0x82cea8
0082cea1  d9420c                            fld    DWORD PTR [edx+0xc]
0082cea4  d8e1                              fsub   st,st(1)
0082cea6  d919                              fstp   DWORD PTR [ecx]
0082cea8  d9c9                              fxch   st(1)
0082ceaa  d85104                            fcom   DWORD PTR [ecx+0x4]
0082cead  dfe0                              fnstsw ax
0082ceaf  f6c441                            test   ah,0x41
0082ceb2  7506                              jne    0x82ceba
0082ceb4  ddd9                              fstp   st(1)
0082ceb6  d95904                            fstp   DWORD PTR [ecx+0x4]
0082ceb9  c3                                ret
0082ceba  ddd8                              fstp   st(0)
0082cebc  d94104                            fld    DWORD PTR [ecx+0x4]
0082cebf  d94210                            fld    DWORD PTR [edx+0x10]
0082cec2  ded9                              fcompp
0082cec4  dfe0                              fnstsw ax
0082cec6  f6c441                            test   ah,0x41
0082cec9  7a07                              jp     0x82ced2
0082cecb  d86a10                            fsubr  DWORD PTR [edx+0x10]
0082cece  d95904                            fstp   DWORD PTR [ecx+0x4]
0082ced1  c3                                ret
0082ced2  ddd8                              fstp   st(0)
0082ced4  c3                                ret
0082ced5  cc                                int3
0082ced6  cc                                int3
0082ced7  cc                                int3
0082ced8  cc                                int3
0082ced9  cc                                int3
0082ceda  cc                                int3
0082cedb  cc                                int3
0082cedc  cc                                int3
0082cedd  cc                                int3
0082cede  cc                                int3
0082cedf  cc                                int3

# N22-point-constructor 0x543700..0x543b30
00543700  55                                push   ebp
00543701  8bec                              mov    ebp,esp
00543703  6aff                              push   0xffffffff
00543705  6828989200                        push   0x929828
0054370a  64a100000000                      mov    eax,fs:0x0
00543710  50                                push   eax
00543711  83ec28                            sub    esp,0x28
00543714  53                                push   ebx
00543715  56                                push   esi
00543716  57                                push   edi
00543717  a1201fd600                        mov    eax,ds:0xd61f20
0054371c  33c5                              xor    eax,ebp
0054371e  50                                push   eax
0054371f  8d45f4                            lea    eax,[ebp-0xc]
00543722  64a300000000                      mov    fs:0x0,eax
00543728  8bf9                              mov    edi,ecx
0054372a  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0054372d  8a4518                            mov    al,BYTE PTR [ebp+0x18]
00543730  8bf3                              mov    esi,ebx
00543732  895dcc                            mov    DWORD PTR [ebp-0x34],ebx
00543735  8845f3                            mov    BYTE PTR [ebp-0xd],al
00543738  e8f36ff8ff                        call   0x4ca730
0054373d  33d2                              xor    edx,edx
0054373f  8993f0000000                      mov    DWORD PTR [ebx+0xf0],edx
00543745  668b4510                          mov    ax,WORD PTR [ebp+0x10]
00543749  668b4d0c                          mov    cx,WORD PTR [ebp+0xc]
0054374d  f30f104514                        movss  xmm0,DWORD PTR [ebp+0x14]
00543752  8955fc                            mov    DWORD PTR [ebp-0x4],edx
00543755  668983f6000000                    mov    WORD PTR [ebx+0xf6],ax
0054375c  8a4520                            mov    al,BYTE PTR [ebp+0x20]
0054375f  8883f8000000                      mov    BYTE PTR [ebx+0xf8],al
00543765  8b451c                            mov    eax,DWORD PTR [ebp+0x1c]
00543768  898300010000                      mov    DWORD PTR [ebx+0x100],eax
0054376e  0fb645f3                          movzx  eax,BYTE PTR [ebp-0xd]
00543772  c703fcf7c000                      mov    DWORD PTR [ebx],0xc0f7fc
00543778  66898bf4000000                    mov    WORD PTR [ebx+0xf4],cx
0054377f  f30f1183fc000000                  movss  DWORD PTR [ebx+0xfc],xmm0
00543787  889304010000                      mov    BYTE PTR [ebx+0x104],dl
0054378d  888305010000                      mov    BYTE PTR [ebx+0x105],al
00543793  d983a0000000                      fld    DWORD PTR [ebx+0xa0]
00543799  8db3a0000000                      lea    esi,[ebx+0xa0]
0054379f  d907                              fld    DWORD PTR [edi]
005437a1  dfe9                              fucomip st,st(1)
005437a3  9f                                lahf
005437a4  ddd8                              fstp   st(0)
005437a6  f6c444                            test   ah,0x44
005437a9  7a10                              jp     0x5437bb
005437ab  d94604                            fld    DWORD PTR [esi+0x4]
005437ae  d94704                            fld    DWORD PTR [edi+0x4]
005437b1  dfe9                              fucomip st,st(1)
005437b3  ddd8                              fstp   st(0)
005437b5  9f                                lahf
005437b6  f6c444                            test   ah,0x44
005437b9  7b22                              jnp    0x5437dd
005437bb  8b0f                              mov    ecx,DWORD PTR [edi]
005437bd  890e                              mov    DWORD PTR [esi],ecx
005437bf  8b5704                            mov    edx,DWORD PTR [edi+0x4]
005437c2  8bcb                              mov    ecx,ebx
005437c4  895604                            mov    DWORD PTR [esi+0x4],edx
005437c7  c783ac00000001000000              mov    DWORD PTR [ebx+0xac],0x1
005437d1  ff1534f8c000                      call   DWORD PTR ds:0xc0f834
005437d7  668b4d0c                          mov    cx,WORD PTR [ebp+0xc]
005437db  33d2                              xor    edx,edx
005437dd  6683f902                          cmp    cx,0x2
005437e1  0f8588000000                      jne    0x54386f
005437e7  0fbf7d10                          movsx  edi,WORD PTR [ebp+0x10]
005437eb  a1b41dfe00                        mov    eax,ds:0xfe1db4
005437f0  e81b81fbff                        call   0x4fb910
005437f5  85c0                              test   eax,eax
005437f7  7410                              je     0x543809
005437f9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
005437fc  8d48ff                            lea    ecx,[eax-0x1]
005437ff  83f903                            cmp    ecx,0x3
00543802  7705                              ja     0x543809
00543804  8d78ff                            lea    edi,[eax-0x1]
00543807  eb02                              jmp    0x54380b
00543809  33ff                              xor    edi,edi
0054380b  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
00543812  7521                              jne    0x543835
00543814  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
0054381b  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0054381f  e8fccf0000                        call   0x550820
00543824  68b0e6bc00                        push   0xbce6b0
00543829  e8ecea3400                        call   0x89231a
0054382e  83c404                            add    esp,0x4
00543831  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
00543835  57                                push   edi
00543836  6a00                              push   0x0
00543838  b9c8f7c000                        mov    ecx,0xc0f7c8
0054383d  ba80f6fd00                        mov    edx,0xfdf680
00543842  e839e30000                        call   0x551b80
00543847  d905f8c7c000                      fld    DWORD PTR ds:0xc0c7f8
0054384d  6a00                              push   0x0
0054384f  83ec08                            sub    esp,0x8
00543852  d95c2404                          fstp   DWORD PTR [esp+0x4]
00543856  8bc8                              mov    ecx,eax
00543858  d9ee                              fldz
0054385a  d91c24                            fstp   DWORD PTR [esp]
0054385d  56                                push   esi
0054385e  6a00                              push   0x0
00543860  6880f6fd00                        push   0xfdf680
00543865  e866e50000                        call   0x551dd0
0054386a  e99f020000                        jmp    0x543b0e
0054386f  663bca                            cmp    cx,dx
00543872  0f8545020000                      jne    0x543abd
00543878  80bbf800000000                    cmp    BYTE PTR [ebx+0xf8],0x0
0054387f  d94514                            fld    DWORD PTR [ebp+0x14]
00543882  dd05405cc500                      fld    QWORD PTR ds:0xc55c40
00543888  6a48                              push   0x48
0054388a  d8c9                              fmul   st,st(1)
0054388c  d99bb4000000                      fstp   DWORD PTR [ebx+0xb4]
00543892  dc0da85bc500                      fmul   QWORD PTR ds:0xc55ba8
00543898  d99bfc000000                      fstp   DWORD PTR [ebx+0xfc]
0054389e  0f85c4000000                      jne    0x543968
005438a4  e8bfd93400                        call   0x891268
005438a9  8bf8                              mov    edi,eax
005438ab  83c404                            add    esp,0x4
005438ae  897dec                            mov    DWORD PTR [ebp-0x14],edi
005438b1  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
005438b5  85ff                              test   edi,edi
005438b7  0f8497000000                      je     0x543954
005438bd  807df301                          cmp    BYTE PTR [ebp-0xd],0x1
005438c1  7507                              jne    0x5438ca
005438c3  b804000000                        mov    eax,0x4
005438c8  eb08                              jmp    0x5438d2
005438ca  0fbf83f6000000                    movsx  eax,WORD PTR [ebx+0xf6]
005438d1  40                                inc    eax
005438d2  0fbf8bf6000000                    movsx  ecx,WORD PTR [ebx+0xf6]
005438d9  0f57c0                            xorps  xmm0,xmm0
005438dc  894f04                            mov    DWORD PTR [edi+0x4],ecx
005438df  894708                            mov    DWORD PTR [edi+0x8],eax
005438e2  c70708000000                      mov    DWORD PTR [edi],0x8
005438e8  c6470c01                          mov    BYTE PTR [edi+0xc],0x1
005438ec  8b16                              mov    edx,DWORD PTR [esi]
005438ee  895710                            mov    DWORD PTR [edi+0x10],edx
005438f1  8b4604                            mov    eax,DWORD PTR [esi+0x4]
005438f4  894714                            mov    DWORD PTR [edi+0x14],eax
005438f7  f30f1145e4                        movss  DWORD PTR [ebp-0x1c],xmm0
005438fc  8b4de4                            mov    ecx,DWORD PTR [ebp-0x1c]
005438ff  894f1c                            mov    DWORD PTR [edi+0x1c],ecx
00543902  33c0                              xor    eax,eax
00543904  f30f1145e8                        movss  DWORD PTR [ebp-0x18],xmm0
00543909  8b55e8                            mov    edx,DWORD PTR [ebp-0x18]
0054390c  8d4f24                            lea    ecx,[edi+0x24]
0054390f  f30f114718                        movss  DWORD PTR [edi+0x18],xmm0
00543914  895720                            mov    DWORD PTR [edi+0x20],edx
00543917  50                                push   eax
00543918  c7411407000000                    mov    DWORD PTR [ecx+0x14],0x7
0054391f  c7411000000000                    mov    DWORD PTR [ecx+0x10],0x0
00543926  68fcd1be00                        push   0xbed1fc
0054392b  668901                            mov    WORD PTR [ecx],ax
0054392e  e82de8ebff                        call   0x402160
00543933  0f57c0                            xorps  xmm0,xmm0
00543936  c7474000000000                    mov    DWORD PTR [edi+0x40],0x0
0054393d  f30f114744                        movss  DWORD PTR [edi+0x44],xmm0
00543942  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
00543946  e86566f4ff                        call   0x489fb0
0054394b  8b08                              mov    ecx,DWORD PTR [eax]
0054394d  57                                push   edi
0054394e  51                                push   ecx
0054394f  e9b4000000                        jmp    0x543a08
00543954  33ff                              xor    edi,edi
00543956  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0054395a  e85166f4ff                        call   0x489fb0
0054395f  8b08                              mov    ecx,DWORD PTR [eax]
00543961  57                                push   edi
00543962  51                                push   ecx
00543963  e9a0000000                        jmp    0x543a08
00543968  e8fbd83400                        call   0x891268
0054396d  8bf8                              mov    edi,eax
0054396f  83c404                            add    esp,0x4
00543972  897dec                            mov    DWORD PTR [ebp-0x14],edi
00543975  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
00543979  85ff                              test   edi,edi
0054397b  747c                              je     0x5439f9
0054397d  0fbf83f6000000                    movsx  eax,WORD PTR [ebx+0xf6]
00543984  0f57c0                            xorps  xmm0,xmm0
00543987  33d2                              xor    edx,edx
00543989  807df301                          cmp    BYTE PTR [ebp-0xd],0x1
0054398d  894704                            mov    DWORD PTR [edi+0x4],eax
00543990  0f94c2                            sete   dl
00543993  c7070b000000                      mov    DWORD PTR [edi],0xb
00543999  c6470c01                          mov    BYTE PTR [edi+0xc],0x1
0054399d  f30f1145e4                        movss  DWORD PTR [ebp-0x1c],xmm0
005439a2  f30f1145e8                        movss  DWORD PTR [ebp-0x18],xmm0
005439a7  42                                inc    edx
005439a8  895708                            mov    DWORD PTR [edi+0x8],edx
005439ab  8b06                              mov    eax,DWORD PTR [esi]
005439ad  8b55e4                            mov    edx,DWORD PTR [ebp-0x1c]
005439b0  894710                            mov    DWORD PTR [edi+0x10],eax
005439b3  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
005439b6  8b45e8                            mov    eax,DWORD PTR [ebp-0x18]
005439b9  89571c                            mov    DWORD PTR [edi+0x1c],edx
005439bc  894f14                            mov    DWORD PTR [edi+0x14],ecx
005439bf  33d2                              xor    edx,edx
005439c1  8d4f24                            lea    ecx,[edi+0x24]
005439c4  f30f114718                        movss  DWORD PTR [edi+0x18],xmm0
005439c9  894720                            mov    DWORD PTR [edi+0x20],eax
005439cc  52                                push   edx
005439cd  c7411407000000                    mov    DWORD PTR [ecx+0x14],0x7
005439d4  c7411000000000                    mov    DWORD PTR [ecx+0x10],0x0
005439db  68fcd1be00                        push   0xbed1fc
005439e0  668911                            mov    WORD PTR [ecx],dx
005439e3  e878e7ebff                        call   0x402160
005439e8  0f57c0                            xorps  xmm0,xmm0
005439eb  c7474000000000                    mov    DWORD PTR [edi+0x40],0x0
005439f2  f30f114744                        movss  DWORD PTR [edi+0x44],xmm0
005439f7  eb02                              jmp    0x5439fb
005439f9  33ff                              xor    edi,edi
005439fb  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
005439ff  e8ac65f4ff                        call   0x489fb0
00543a04  8b00                              mov    eax,DWORD PTR [eax]
00543a06  57                                push   edi
00543a07  50                                push   eax
00543a08  e8b3bb0200                        call   0x56f5c0
00543a0d  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
00543a14  7521                              jne    0x543a37
00543a16  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
00543a1d  c645fc04                          mov    BYTE PTR [ebp-0x4],0x4
00543a21  e85a03fbff                        call   0x4f3d80
00543a26  68e0d1bc00                        push   0xbcd1e0
00543a2b  e8eae83400                        call   0x89231a
00543a30  83c404                            add    esp,0x4
00543a33  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
00543a37  660fbe8bf8000000                  movsx  cx,BYTE PTR [ebx+0xf8]
00543a3f  660fbe45f3                        movsx  ax,BYTE PTR [ebp-0xd]
00543a44  0fb7d1                            movzx  edx,cx
00543a47  0fb7c8                            movzx  ecx,ax
00543a4a  c1e210                            shl    edx,0x10
00543a4d  0bd1                              or     edx,ecx
00543a4f  8955ec                            mov    DWORD PTR [ebp-0x14],edx
00543a52  8d55ec                            lea    edx,[ebp-0x14]
00543a55  b93075fb00                        mov    ecx,0xfb7530
00543a5a  e86142fbff                        call   0x4f7cc0
00543a5f  83781410                          cmp    DWORD PTR [eax+0x14],0x10
00543a63  7202                              jb     0x543a67
00543a65  8b00                              mov    eax,DWORD PTR [eax]
00543a67  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
00543a6e  c745d003000000                    mov    DWORD PTR [ebp-0x30],0x3
00543a75  c745d4bcd6c000                    mov    DWORD PTR [ebp-0x2c],0xc0d6bc
00543a7c  8945e0                            mov    DWORD PTR [ebp-0x20],eax
00543a7f  7521                              jne    0x543aa2
00543a81  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
00543a88  c645fc05                          mov    BYTE PTR [ebp-0x4],0x5
00543a8c  e88fcd0000                        call   0x550820
00543a91  68b0e6bc00                        push   0xbce6b0
00543a96  e87fe83400                        call   0x89231a
00543a9b  83c404                            add    esp,0x4
00543a9e  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
00543aa2  d983b4000000                      fld    DWORD PTR [ebx+0xb4]
00543aa8  83ec08                            sub    esp,0x8
00543aab  d95c2404                          fstp   DWORD PTR [esp+0x4]
00543aaf  b980f6fd00                        mov    ecx,0xfdf680
00543ab4  d9ee                              fldz
00543ab6  d91c24                            fstp   DWORD PTR [esp]
00543ab9  6a00                              push   0x0
00543abb  eb49                              jmp    0x543b06
00543abd  6683f904                          cmp    cx,0x4
00543ac1  7551                              jne    0x543b14
00543ac3  d94514                            fld    DWORD PTR [ebp+0x14]
00543ac6  83ec08                            sub    esp,0x8
00543ac9  dc0db056c500                      fmul   QWORD PTR ds:0xc556b0
00543acf  83c8ff                            or     eax,0xffffffff
00543ad2  c745d002000000                    mov    DWORD PTR [ebp-0x30],0x2
00543ad9  c745d4dcf7c000                    mov    DWORD PTR [ebp-0x2c],0xc0f7dc
00543ae0  d99bfc000000                      fstp   DWORD PTR [ebx+0xfc]
00543ae6  8945d8                            mov    DWORD PTR [ebp-0x28],eax
00543ae9  d983b4000000                      fld    DWORD PTR [ebx+0xb4]
00543aef  8945dc                            mov    DWORD PTR [ebp-0x24],eax
00543af2  d95c2404                          fstp   DWORD PTR [esp+0x4]
00543af6  8955e0                            mov    DWORD PTR [ebp-0x20],edx
00543af9  d9ee                              fldz
00543afb  d91c24                            fstp   DWORD PTR [esp]
00543afe  52                                push   edx
00543aff  e83c76f5ff                        call   0x49b140
00543b04  8bc8                              mov    ecx,eax
00543b06  8d55d0                            lea    edx,[ebp-0x30]
00543b09  e882e40000                        call   0x551f90
00543b0e  8983f0000000                      mov    DWORD PTR [ebx+0xf0],eax
00543b14  8bc3                              mov    eax,ebx
00543b16  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
00543b19  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00543b20  59                                pop    ecx
00543b21  5f                                pop    edi
00543b22  5e                                pop    esi
00543b23  5b                                pop    ebx
00543b24  8be5                              mov    esp,ebp
00543b26  5d                                pop    ebp
00543b27  c21c00                            ret    0x1c
00543b2a  cc                                int3
00543b2b  cc                                int3
00543b2c  cc                                int3
00543b2d  cc                                int3
00543b2e  cc                                int3
00543b2f  cc                                int3

# R-point_clear 0x5449a0..0x544a00
005449a0  55                                push   ebp
005449a1  8bec                              mov    ebp,esp
005449a3  53                                push   ebx
005449a4  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
005449a7  56                                push   esi
005449a8  8b7304                            mov    esi,DWORD PTR [ebx+0x4]
005449ab  3b7308                            cmp    esi,DWORD PTR [ebx+0x8]
005449ae  741f                              je     0x5449cf
005449b0  8b0e                              mov    ecx,DWORD PTR [esi]
005449b2  8b01                              mov    eax,DWORD PTR [ecx]
005449b4  8b5014                            mov    edx,DWORD PTR [eax+0x14]
005449b7  ffd2                              call   edx
005449b9  8b0e                              mov    ecx,DWORD PTR [esi]
005449bb  85c9                              test   ecx,ecx
005449bd  7408                              je     0x5449c7
005449bf  8b01                              mov    eax,DWORD PTR [ecx]
005449c1  8b10                              mov    edx,DWORD PTR [eax]
005449c3  6a01                              push   0x1
005449c5  ffd2                              call   edx
005449c7  83c604                            add    esi,0x4
005449ca  3b7308                            cmp    esi,DWORD PTR [ebx+0x8]
005449cd  75e1                              jne    0x5449b0
005449cf  8b4b08                            mov    ecx,DWORD PTR [ebx+0x8]
005449d2  8b7304                            mov    esi,DWORD PTR [ebx+0x4]
005449d5  3bf1                              cmp    esi,ecx
005449d7  7420                              je     0x5449f9
005449d9  8bc1                              mov    eax,ecx
005449db  2bc1                              sub    eax,ecx
005449dd  57                                push   edi
005449de  c1f802                            sar    eax,0x2
005449e1  8d3c8500000000                    lea    edi,[eax*4+0x0]
005449e8  57                                push   edi
005449e9  51                                push   ecx
005449ea  56                                push   esi
005449eb  e800c93400                        call   0x8912f0
005449f0  83c40c                            add    esp,0xc
005449f3  03fe                              add    edi,esi
005449f5  897b08                            mov    DWORD PTR [ebx+0x8],edi
005449f8  5f                                pop    edi
005449f9  5e                                pop    esi
005449fa  5b                                pop    ebx
005449fb  5d                                pop    ebp
005449fc  c20400                            ret    0x4
005449ff  cc                                int3

# R-point_lookup_setter 0x544940..0x5449a0
00544940  55                                push   ebp
00544941  8bec                              mov    ebp,esp
00544943  8b4208                            mov    eax,DWORD PTR [edx+0x8]
00544946  2b4204                            sub    eax,DWORD PTR [edx+0x4]
00544949  53                                push   ebx
0054494a  c1f802                            sar    eax,0x2
0054494d  56                                push   esi
0054494e  33c9                              xor    ecx,ecx
00544950  57                                push   edi
00544951  85c0                              test   eax,eax
00544953  7443                              je     0x544998
00544955  8b5204                            mov    edx,DWORD PTR [edx+0x4]
00544958  8bf2                              mov    esi,edx
0054495a  8d9b00000000                      lea    ebx,[ebx+0x0]
00544960  8b3e                              mov    edi,DWORD PTR [esi]
00544962  668b9ff6000000                    mov    bx,WORD PTR [edi+0xf6]
00544969  663b5d08                          cmp    bx,WORD PTR [ebp+0x8]
0054496d  750e                              jne    0x54497d
0054496f  660fbe5d0c                        movsx  bx,BYTE PTR [ebp+0xc]
00544974  66399ff4000000                    cmp    WORD PTR [edi+0xf4],bx
0054497b  740f                              je     0x54498c
0054497d  41                                inc    ecx
0054497e  83c604                            add    esi,0x4
00544981  3bc8                              cmp    ecx,eax
00544983  72db                              jb     0x544960
00544985  5f                                pop    edi
00544986  5e                                pop    esi
00544987  5b                                pop    ebx
00544988  5d                                pop    ebp
00544989  c20c00                            ret    0xc
0054498c  8b048a                            mov    eax,DWORD PTR [edx+ecx*4]
0054498f  8a4d10                            mov    cl,BYTE PTR [ebp+0x10]
00544992  50                                push   eax
00544993  e898f1ffff                        call   0x543b30
00544998  5f                                pop    edi
00544999  5e                                pop    esi
0054499a  5b                                pop    ebx
0054499b  5d                                pop    ebp
0054499c  c20c00                            ret    0xc
0054499f  cc                                int3

# R-point_set_status 0x543b30..0x544020
00543b30  55                                push   ebp
00543b31  8bec                              mov    ebp,esp
00543b33  83e4f8                            and    esp,0xfffffff8
00543b36  6aff                              push   0xffffffff
00543b38  68ac979200                        push   0x9297ac
00543b3d  64a100000000                      mov    eax,fs:0x0
00543b43  50                                push   eax
00543b44  83ec38                            sub    esp,0x38
00543b47  a1201fd600                        mov    eax,ds:0xd61f20
00543b4c  33c4                              xor    eax,esp
00543b4e  89442430                          mov    DWORD PTR [esp+0x30],eax
00543b52  53                                push   ebx
00543b53  56                                push   esi
00543b54  57                                push   edi
00543b55  a1201fd600                        mov    eax,ds:0xd61f20
00543b5a  33c4                              xor    eax,esp
00543b5c  50                                push   eax
00543b5d  8d442448                          lea    eax,[esp+0x48]
00543b61  64a300000000                      mov    fs:0x0,eax
00543b67  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
00543b6a  0fb783f4000000                    movzx  eax,WORD PTR [ebx+0xf4]
00543b71  33ff                              xor    edi,edi
00543b73  884c2417                          mov    BYTE PTR [esp+0x17],cl
00543b77  888b05010000                      mov    BYTE PTR [ebx+0x105],cl
00543b7d  663bc7                            cmp    ax,di
00543b80  0f853d040000                      jne    0x543fc3
00543b86  8b83f0000000                      mov    eax,DWORD PTR [ebx+0xf0]
00543b8c  3bc7                              cmp    eax,edi
00543b8e  7432                              je     0x543bc2
00543b90  397824                            cmp    DWORD PTR [eax+0x24],edi
00543b93  8d7024                            lea    esi,[eax+0x24]
00543b96  7409                              je     0x543ba1
00543b98  e853aa2700                        call   0x7be5f0
00543b9d  8a4c2417                          mov    cl,BYTE PTR [esp+0x17]
00543ba1  8b83f0000000                      mov    eax,DWORD PTR [ebx+0xf0]
00543ba7  3bc7                              cmp    eax,edi
00543ba9  7417                              je     0x543bc2
00543bab  8bf8                              mov    edi,eax
00543bad  e8fe41f8ff                        call   0x4c7db0
00543bb2  8a4c2417                          mov    cl,BYTE PTR [esp+0x17]
00543bb6  c783f000000000000000              mov    DWORD PTR [ebx+0xf0],0x0
00543bc0  33ff                              xor    edi,edi
00543bc2  6a48                              push   0x48
00543bc4  80f901                            cmp    cl,0x1
00543bc7  0f8525020000                      jne    0x543df2
00543bcd  80bbf800000000                    cmp    BYTE PTR [ebx+0xf8],0x0
00543bd4  7566                              jne    0x543c3c
00543bd6  e88dd63400                        call   0x891268
00543bdb  8bf0                              mov    esi,eax
00543bdd  83c404                            add    esp,0x4
00543be0  89742418                          mov    DWORD PTR [esp+0x18],esi
00543be4  897c2450                          mov    DWORD PTR [esp+0x50],edi
00543be8  3bf7                              cmp    esi,edi
00543bea  0f84df000000                      je     0x543ccf
00543bf0  0fbf83f6000000                    movsx  eax,WORD PTR [ebx+0xf6]
00543bf7  0f57c0                            xorps  xmm0,xmm0
00543bfa  894604                            mov    DWORD PTR [esi+0x4],eax
00543bfd  c70608000000                      mov    DWORD PTR [esi],0x8
00543c03  c7460804000000                    mov    DWORD PTR [esi+0x8],0x4
00543c0a  c6460c01                          mov    BYTE PTR [esi+0xc],0x1
00543c0e  8b83a0000000                      mov    eax,DWORD PTR [ebx+0xa0]
00543c14  894610                            mov    DWORD PTR [esi+0x10],eax
00543c17  8b8ba4000000                      mov    ecx,DWORD PTR [ebx+0xa4]
00543c1d  f30f1144241c                      movss  DWORD PTR [esp+0x1c],xmm0
00543c23  8b54241c                          mov    edx,DWORD PTR [esp+0x1c]
00543c27  f30f11442420                      movss  DWORD PTR [esp+0x20],xmm0
00543c2d  8b442420                          mov    eax,DWORD PTR [esp+0x20]
00543c31  894e14                            mov    DWORD PTR [esi+0x14],ecx
00543c34  89561c                            mov    DWORD PTR [esi+0x1c],edx
00543c37  894620                            mov    DWORD PTR [esi+0x20],eax
00543c3a  eb64                              jmp    0x543ca0
00543c3c  e827d63400                        call   0x891268
00543c41  8bf0                              mov    esi,eax
00543c43  83c404                            add    esp,0x4
00543c46  89742418                          mov    DWORD PTR [esp+0x18],esi
00543c4a  c744245001000000                  mov    DWORD PTR [esp+0x50],0x1
00543c52  3bf7                              cmp    esi,edi
00543c54  7479                              je     0x543ccf
00543c56  0fbf83f6000000                    movsx  eax,WORD PTR [ebx+0xf6]
00543c5d  0f57c0                            xorps  xmm0,xmm0
00543c60  894604                            mov    DWORD PTR [esi+0x4],eax
00543c63  c7060b000000                      mov    DWORD PTR [esi],0xb
00543c69  c7460802000000                    mov    DWORD PTR [esi+0x8],0x2
00543c70  c6460c01                          mov    BYTE PTR [esi+0xc],0x1
00543c74  8b8ba0000000                      mov    ecx,DWORD PTR [ebx+0xa0]
00543c7a  894e10                            mov    DWORD PTR [esi+0x10],ecx
00543c7d  8b93a4000000                      mov    edx,DWORD PTR [ebx+0xa4]
00543c83  f30f1144241c                      movss  DWORD PTR [esp+0x1c],xmm0
00543c89  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
00543c8d  f30f11442420                      movss  DWORD PTR [esp+0x20],xmm0
00543c93  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
00543c97  895614                            mov    DWORD PTR [esi+0x14],edx
00543c9a  89461c                            mov    DWORD PTR [esi+0x1c],eax
00543c9d  894e20                            mov    DWORD PTR [esi+0x20],ecx
00543ca0  8d4e24                            lea    ecx,[esi+0x24]
00543ca3  f30f114618                        movss  DWORD PTR [esi+0x18],xmm0
00543ca8  c7411407000000                    mov    DWORD PTR [ecx+0x14],0x7
00543caf  57                                push   edi
00543cb0  33d2                              xor    edx,edx
00543cb2  897910                            mov    DWORD PTR [ecx+0x10],edi
00543cb5  68fcd1be00                        push   0xbed1fc
00543cba  668911                            mov    WORD PTR [ecx],dx
00543cbd  e89ee4ebff                        call   0x402160
00543cc2  0f57c0                            xorps  xmm0,xmm0
00543cc5  897e40                            mov    DWORD PTR [esi+0x40],edi
00543cc8  f30f114644                        movss  DWORD PTR [esi+0x44],xmm0
00543ccd  eb02                              jmp    0x543cd1
00543ccf  33f6                              xor    esi,esi
00543cd1  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
00543cd9  e8d262f4ff                        call   0x489fb0
00543cde  8b00                              mov    eax,DWORD PTR [eax]
00543ce0  56                                push   esi
00543ce1  50                                push   eax
00543ce2  e8d9b80200                        call   0x56f5c0
00543ce7  80bbf800000000                    cmp    BYTE PTR [ebx+0xf8],0x0
00543cee  bf10000000                        mov    edi,0x10
00543cf3  756f                              jne    0x543d64
00543cf5  68e8f7c000                        push   0xc0f7e8
00543cfa  8d47fa                            lea    eax,[edi-0x6]
00543cfd  8d4c2428                          lea    ecx,[esp+0x28]
00543d01  c744243c0f000000                  mov    DWORD PTR [esp+0x3c],0xf
00543d09  c744243800000000                  mov    DWORD PTR [esp+0x38],0x0
00543d11  c644242800                        mov    BYTE PTR [esp+0x28],0x0
00543d16  e8f575ecff                        call   0x40b310
00543d1b  c744245002000000                  mov    DWORD PTR [esp+0x50],0x2
00543d23  e8c876ecff                        call   0x40b3f0
00543d28  50                                push   eax
00543d29  8d4c2428                          lea    ecx,[esp+0x28]
00543d2d  e8ce6d2c00                        call   0x80ab00
00543d32  85c0                              test   eax,eax
00543d34  7409                              je     0x543d3f
00543d36  8b10                              mov    edx,DWORD PTR [eax]
00543d38  8bc8                              mov    ecx,eax
00543d3a  8b4214                            mov    eax,DWORD PTR [edx+0x14]
00543d3d  ffd0                              call   eax
00543d3f  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
00543d47  397c2438                          cmp    DWORD PTR [esp+0x38],edi
00543d4b  720d                              jb     0x543d5a
00543d4d  8b4c2424                          mov    ecx,DWORD PTR [esp+0x24]
00543d51  51                                push   ecx
00543d52  e8b5d43400                        call   0x89120c
00543d57  83c404                            add    esp,0x4
00543d5a  e8419ff6ff                        call   0x4adca0
00543d5f  e86cf50000                        call   0x5532d0
00543d64  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
00543d6b  be03000000                        mov    esi,0x3
00543d70  7525                              jne    0x543d97
00543d72  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
00543d79  89742450                          mov    DWORD PTR [esp+0x50],esi
00543d7d  e8fefffaff                        call   0x4f3d80
00543d82  68e0d1bc00                        push   0xbcd1e0
00543d87  e88ee53400                        call   0x89231a
00543d8c  83c404                            add    esp,0x4
00543d8f  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
00543d97  660fbe93f8000000                  movsx  dx,BYTE PTR [ebx+0xf8]
00543d9f  0fb7c2                            movzx  eax,dx
00543da2  c1e010                            shl    eax,0x10
00543da5  83c801                            or     eax,0x1
00543da8  8d542418                          lea    edx,[esp+0x18]
00543dac  b93075fb00                        mov    ecx,0xfb7530
00543db1  89442418                          mov    DWORD PTR [esp+0x18],eax
00543db5  e8063ffbff                        call   0x4f7cc0
00543dba  397814                            cmp    DWORD PTR [eax+0x14],edi
00543dbd  7202                              jb     0x543dc1
00543dbf  8b00                              mov    eax,DWORD PTR [eax]
00543dc1  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
00543dc8  89742424                          mov    DWORD PTR [esp+0x24],esi
00543dcc  c7442428bcd6c000                  mov    DWORD PTR [esp+0x28],0xc0d6bc
00543dd4  89442434                          mov    DWORD PTR [esp+0x34],eax
00543dd8  0f85b0010000                      jne    0x543f8e
00543dde  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
00543de5  c744245004000000                  mov    DWORD PTR [esp+0x50],0x4
00543ded  e982010000                        jmp    0x543f74
00543df2  80bbf800000000                    cmp    BYTE PTR [ebx+0xf8],0x0
00543df9  7538                              jne    0x543e33
00543dfb  e868d43400                        call   0x891268
00543e00  8bf0                              mov    esi,eax
00543e02  83c404                            add    esp,0x4
00543e05  89742418                          mov    DWORD PTR [esp+0x18],esi
00543e09  c744245005000000                  mov    DWORD PTR [esp+0x50],0x5
00543e11  bf07000000                        mov    edi,0x7
00543e16  85f6                              test   esi,esi
00543e18  0f84b1000000                      je     0x543ecf
00543e1e  0fbf83f6000000                    movsx  eax,WORD PTR [ebx+0xf6]
00543e25  8d4801                            lea    ecx,[eax+0x1]
00543e28  c70608000000                      mov    DWORD PTR [esi],0x8
00543e2e  894e08                            mov    DWORD PTR [esi+0x8],ecx
00543e31  eb33                              jmp    0x543e66
00543e33  e830d43400                        call   0x891268
00543e38  8bf0                              mov    esi,eax
00543e3a  83c404                            add    esp,0x4
00543e3d  89742418                          mov    DWORD PTR [esp+0x18],esi
00543e41  c744245006000000                  mov    DWORD PTR [esp+0x50],0x6
00543e49  bf07000000                        mov    edi,0x7
00543e4e  85f6                              test   esi,esi
00543e50  747d                              je     0x543ecf
00543e52  0fbf83f6000000                    movsx  eax,WORD PTR [ebx+0xf6]
00543e59  c7060b000000                      mov    DWORD PTR [esi],0xb
00543e5f  c7460801000000                    mov    DWORD PTR [esi+0x8],0x1
00543e66  0f57c0                            xorps  xmm0,xmm0
00543e69  894604                            mov    DWORD PTR [esi+0x4],eax
00543e6c  c6460c01                          mov    BYTE PTR [esi+0xc],0x1
00543e70  8b8ba0000000                      mov    ecx,DWORD PTR [ebx+0xa0]
00543e76  894e10                            mov    DWORD PTR [esi+0x10],ecx
00543e79  8b93a4000000                      mov    edx,DWORD PTR [ebx+0xa4]
00543e7f  895614                            mov    DWORD PTR [esi+0x14],edx
00543e82  f30f114618                        movss  DWORD PTR [esi+0x18],xmm0
00543e87  f30f1144241c                      movss  DWORD PTR [esp+0x1c],xmm0
00543e8d  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
00543e91  89461c                            mov    DWORD PTR [esi+0x1c],eax
00543e94  f30f11442420                      movss  DWORD PTR [esp+0x20],xmm0
00543e9a  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
00543e9e  894e20                            mov    DWORD PTR [esi+0x20],ecx
00543ea1  8d4e24                            lea    ecx,[esi+0x24]
00543ea4  33d2                              xor    edx,edx
00543ea6  897914                            mov    DWORD PTR [ecx+0x14],edi
00543ea9  52                                push   edx
00543eaa  c7411000000000                    mov    DWORD PTR [ecx+0x10],0x0
00543eb1  68fcd1be00                        push   0xbed1fc
00543eb6  668911                            mov    WORD PTR [ecx],dx
00543eb9  e8a2e2ebff                        call   0x402160
00543ebe  0f57c0                            xorps  xmm0,xmm0
00543ec1  c7464000000000                    mov    DWORD PTR [esi+0x40],0x0
00543ec8  f30f114644                        movss  DWORD PTR [esi+0x44],xmm0
00543ecd  eb02                              jmp    0x543ed1
00543ecf  33f6                              xor    esi,esi
00543ed1  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
00543ed9  e8d260f4ff                        call   0x489fb0
00543ede  8b00                              mov    eax,DWORD PTR [eax]
00543ee0  56                                push   esi
00543ee1  50                                push   eax
00543ee2  e8d9b60200                        call   0x56f5c0
00543ee7  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
00543eee  7525                              jne    0x543f15
00543ef0  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
00543ef7  897c2450                          mov    DWORD PTR [esp+0x50],edi
00543efb  e880fefaff                        call   0x4f3d80
00543f00  68e0d1bc00                        push   0xbcd1e0
00543f05  e810e43400                        call   0x89231a
00543f0a  83c404                            add    esp,0x4
00543f0d  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
00543f15  660fbe8bf8000000                  movsx  cx,BYTE PTR [ebx+0xf8]
00543f1d  660fbe442417                      movsx  ax,BYTE PTR [esp+0x17]
00543f23  0fb7d1                            movzx  edx,cx
00543f26  0fb7c8                            movzx  ecx,ax
00543f29  c1e210                            shl    edx,0x10
00543f2c  0bd1                              or     edx,ecx
00543f2e  89542418                          mov    DWORD PTR [esp+0x18],edx
00543f32  8d542418                          lea    edx,[esp+0x18]
00543f36  b93075fb00                        mov    ecx,0xfb7530
00543f3b  e8803dfbff                        call   0x4f7cc0
00543f40  83781410                          cmp    DWORD PTR [eax+0x14],0x10
00543f44  7202                              jb     0x543f48
00543f46  8b00                              mov    eax,DWORD PTR [eax]
00543f48  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
00543f4f  c744242403000000                  mov    DWORD PTR [esp+0x24],0x3
00543f57  c7442428bcd6c000                  mov    DWORD PTR [esp+0x28],0xc0d6bc
00543f5f  89442434                          mov    DWORD PTR [esp+0x34],eax
00543f63  7529                              jne    0x543f8e
00543f65  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
00543f6c  c744245008000000                  mov    DWORD PTR [esp+0x50],0x8
00543f74  e8a7c80000                        call   0x550820
00543f79  68b0e6bc00                        push   0xbce6b0
00543f7e  e897e33400                        call   0x89231a
00543f83  83c404                            add    esp,0x4
00543f86  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
00543f8e  d983b4000000                      fld    DWORD PTR [ebx+0xb4]
00543f94  8b13                              mov    edx,DWORD PTR [ebx]
00543f96  8b424c                            mov    eax,DWORD PTR [edx+0x4c]
00543f99  83ec08                            sub    esp,0x8
00543f9c  d95c2404                          fstp   DWORD PTR [esp+0x4]
00543fa0  8bcb                              mov    ecx,ebx
00543fa2  d9ee                              fldz
00543fa4  d91c24                            fstp   DWORD PTR [esp]
00543fa7  ffd0                              call   eax
00543fa9  6a00                              push   0x0
00543fab  8bf0                              mov    esi,eax
00543fad  8d542430                          lea    edx,[esp+0x30]
00543fb1  b980f6fd00                        mov    ecx,0xfdf680
00543fb6  e8d5df0000                        call   0x551f90
00543fbb  8983f0000000                      mov    DWORD PTR [ebx+0xf0],eax
00543fc1  eb3c                              jmp    0x543fff
00543fc3  6683f804                          cmp    ax,0x4
00543fc7  7536                              jne    0x543fff
00543fc9  84c9                              test   cl,cl
00543fcb  7532                              jne    0x543fff
00543fcd  8b83f0000000                      mov    eax,DWORD PTR [ebx+0xf0]
00543fd3  3bc7                              cmp    eax,edi
00543fd5  7428                              je     0x543fff
00543fd7  397824                            cmp    DWORD PTR [eax+0x24],edi
00543fda  8d7024                            lea    esi,[eax+0x24]
00543fdd  7405                              je     0x543fe4
00543fdf  e80ca62700                        call   0x7be5f0
00543fe4  8b83f0000000                      mov    eax,DWORD PTR [ebx+0xf0]
00543fea  3bc7                              cmp    eax,edi
00543fec  7411                              je     0x543fff
00543fee  8bf8                              mov    edi,eax
00543ff0  e8bb3df8ff                        call   0x4c7db0
00543ff5  c783f000000000000000              mov    DWORD PTR [ebx+0xf0],0x0
00543fff  8b4c2448                          mov    ecx,DWORD PTR [esp+0x48]
00544003  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0054400a  59                                pop    ecx
0054400b  5f                                pop    edi
0054400c  5e                                pop    esi
0054400d  5b                                pop    ebx
0054400e  8b4c2430                          mov    ecx,DWORD PTR [esp+0x30]
00544012  33cc                              xor    ecx,esp
00544014  e8e8cf3400                        call   0x891001
00544019  8be5                              mov    esp,ebp
0054401b  5d                                pop    ebp
0054401c  c20400                            ret    0x4
0054401f  cc                                int3

# R-checkpoint_delta_packet 0x4b32e0..0x4b3350
004b32e0  55                                push   ebp
004b32e1  8bec                              mov    ebp,esp
004b32e3  b901000000                        mov    ecx,0x1
004b32e8  840dec79fb00                      test   BYTE PTR ds:0xfb79ec,cl
004b32ee  7534                              jne    0x4b3324
004b32f0  090dec79fb00                      or     DWORD PTR ds:0xfb79ec,ecx
004b32f6  33c0                              xor    eax,eax
004b32f8  6870d2bc00                        push   0xbcd270
004b32fd  c705f079fb0068f8c000              mov    DWORD PTR ds:0xfb79f0,0xc0f868
004b3307  a3f479fb00                        mov    ds:0xfb79f4,eax
004b330c  a3f879fb00                        mov    ds:0xfb79f8,eax
004b3311  a3fc79fb00                        mov    ds:0xfb79fc,eax
004b3316  890d047afb00                      mov    DWORD PTR ds:0xfb7a04,ecx
004b331c  e8f9ef3d00                        call   0x89231a
004b3321  83c404                            add    esp,0x4
004b3324  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
004b3327  0fb64805                          movzx  ecx,BYTE PTR [eax+0x5]
004b332b  0fb65004                          movzx  edx,BYTE PTR [eax+0x4]
004b332f  0fb74002                          movzx  eax,WORD PTR [eax+0x2]
004b3333  51                                push   ecx
004b3334  52                                push   edx
004b3335  50                                push   eax
004b3336  baf079fb00                        mov    edx,0xfb79f0
004b333b  e800160900                        call   0x544940
004b3340  33c0                              xor    eax,eax
004b3342  5d                                pop    ebp
004b3343  c20c00                            ret    0xc
004b3346  cc                                int3
004b3347  cc                                int3
004b3348  cc                                int3
004b3349  cc                                int3
004b334a  cc                                int3
004b334b  cc                                int3
004b334c  cc                                int3
004b334d  cc                                int3
004b334e  cc                                int3
004b334f  cc                                int3

# R-s2c0012_map 0x4b24f0..0x4b2566
004b24f0  55                                push   ebp
004b24f1  8bec                              mov    ebp,esp
004b24f3  b901000000                        mov    ecx,0x1
004b24f8  840dec79fb00                      test   BYTE PTR ds:0xfb79ec,cl
004b24fe  7534                              jne    0x4b2534
004b2500  090dec79fb00                      or     DWORD PTR ds:0xfb79ec,ecx
004b2506  33c0                              xor    eax,eax
004b2508  6870d2bc00                        push   0xbcd270
004b250d  c705f079fb0068f8c000              mov    DWORD PTR ds:0xfb79f0,0xc0f868
004b2517  a3f479fb00                        mov    ds:0xfb79f4,eax
004b251c  a3f879fb00                        mov    ds:0xfb79f8,eax
004b2521  a3fc79fb00                        mov    ds:0xfb79fc,eax
004b2526  890d047afb00                      mov    DWORD PTR ds:0xfb7a04,ecx
004b252c  e8e9fd3d00                        call   0x89231a
004b2531  83c404                            add    esp,0x4
004b2534  57                                push   edi
004b2535  68f079fb00                        push   0xfb79f0
004b253a  e861240900                        call   0x5449a0
004b253f  8b3da4a7fb00                      mov    edi,DWORD PTR ds:0xfba7a4
004b2545  e8062a0900                        call   0x544f50
004b254a  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
004b254d  8b4802                            mov    ecx,DWORD PTR [eax+0x2]
004b2550  51                                push   ecx
004b2551  e80acbf5ff                        call   0x40f060
004b2556  50                                push   eax
004b2557  e8b4cf0200                        call   0x4df510
004b255c  b800010000                        mov    eax,0x100
004b2561  5f                                pop    edi
004b2562  5d                                pop    ebp
004b2563  c20c00                            ret    0xc

# R-world_map_load 0x4df510..0x4dfa9d
004df510  55                                push   ebp
004df511  8bec                              mov    ebp,esp
004df513  6aff                              push   0xffffffff
004df515  68a4449400                        push   0x9444a4
004df51a  64a100000000                      mov    eax,fs:0x0
004df520  50                                push   eax
004df521  83ec14                            sub    esp,0x14
004df524  53                                push   ebx
004df525  56                                push   esi
004df526  57                                push   edi
004df527  a1201fd600                        mov    eax,ds:0xd61f20
004df52c  33c5                              xor    eax,ebp
004df52e  50                                push   eax
004df52f  8d45f4                            lea    eax,[ebp-0xc]
004df532  64a300000000                      mov    fs:0x0,eax
004df538  8b750c                            mov    esi,DWORD PTR [ebp+0xc]
004df53b  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
004df53e  397048                            cmp    DWORD PTR [eax+0x48],esi
004df541  0f84cc040000                      je     0x4dfa13
004df547  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
004df54e  897048                            mov    DWORD PTR [eax+0x48],esi
004df551  bf01000000                        mov    edi,0x1
004df556  7527                              jne    0x4df57f
004df558  093db075fb00                      or     DWORD PTR ds:0xfb75b0,edi
004df55e  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
004df565  e816480100                        call   0x4f3d80
004df56a  68e0d1bc00                        push   0xbcd1e0
004df56f  e8a62d3b00                        call   0x89231a
004df574  83c404                            add    esp,0x4
004df577  83cbff                            or     ebx,0xffffffff
004df57a  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004df57d  eb03                              jmp    0x4df582
004df57f  83cbff                            or     ebx,0xffffffff
004df582  8d55f0                            lea    edx,[ebp-0x10]
004df585  b9c074fb00                        mov    ecx,0xfb74c0
004df58a  8975f0                            mov    DWORD PTR [ebp-0x10],esi
004df58d  e85e880100                        call   0x4f7df0
004df592  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
004df599  751e                              jne    0x4df5b9
004df59b  093db075fb00                      or     DWORD PTR ds:0xfb75b0,edi
004df5a1  897dfc                            mov    DWORD PTR [ebp-0x4],edi
004df5a4  e8d7470100                        call   0x4f3d80
004df5a9  68e0d1bc00                        push   0xbcd1e0
004df5ae  e8672d3b00                        call   0x89231a
004df5b3  83c404                            add    esp,0x4
004df5b6  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004df5b9  8d45f0                            lea    eax,[ebp-0x10]
004df5bc  50                                push   eax
004df5bd  8d45ec                            lea    eax,[ebp-0x14]
004df5c0  b9e074fb00                        mov    ecx,0xfb74e0
004df5c5  8975f0                            mov    DWORD PTR [ebp-0x10],esi
004df5c8  e82308faff                        call   0x47fdf0
004df5cd  8b45ec                            mov    eax,DWORD PTR [ebp-0x14]
004df5d0  3b05e474fb00                      cmp    eax,DWORD PTR ds:0xfb74e4
004df5d6  741c                              je     0x4df5f4
004df5d8  83c010                            add    eax,0x10
004df5db  83781410                          cmp    DWORD PTR [eax+0x14],0x10
004df5df  7202                              jb     0x4df5e3
004df5e1  8b00                              mov    eax,DWORD PTR [eax]
004df5e3  8bc8                              mov    ecx,eax
004df5e5  bf7074fb00                        mov    edi,0xfb7470
004df5ea  e891780100                        call   0x4f6e80
004df5ef  bf01000000                        mov    edi,0x1
004df5f4  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
004df5fb  7522                              jne    0x4df61f
004df5fd  093db075fb00                      or     DWORD PTR ds:0xfb75b0,edi
004df603  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
004df60a  e871470100                        call   0x4f3d80
004df60f  68e0d1bc00                        push   0xbcd1e0
004df614  e8012d3b00                        call   0x89231a
004df619  83c404                            add    esp,0x4
004df61c  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004df61f  8d55ec                            lea    edx,[ebp-0x14]
004df622  b9b074fb00                        mov    ecx,0xfb74b0
004df627  8975ec                            mov    DWORD PTR [ebp-0x14],esi
004df62a  e8c1870100                        call   0x4f7df0
004df62f  83781410                          cmp    DWORD PTR [eax+0x14],0x10
004df633  7204                              jb     0x4df639
004df635  8b30                              mov    esi,DWORD PTR [eax]
004df637  eb02                              jmp    0x4df63b
004df639  8bf0                              mov    esi,eax
004df63b  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
004df642  7523                              jne    0x4df667
004df644  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
004df64b  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
004df652  e829470100                        call   0x4f3d80
004df657  68e0d1bc00                        push   0xbcd1e0
004df65c  e8b92c3b00                        call   0x89231a
004df661  83c404                            add    esp,0x4
004df664  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004df667  8b7d0c                            mov    edi,DWORD PTR [ebp+0xc]
004df66a  8d4dec                            lea    ecx,[ebp-0x14]
004df66d  51                                push   ecx
004df66e  8d45f0                            lea    eax,[ebp-0x10]
004df671  b9f074fb00                        mov    ecx,0xfb74f0
004df676  897dec                            mov    DWORD PTR [ebp-0x14],edi
004df679  e87207faff                        call   0x47fdf0
004df67e  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
004df681  3b05f474fb00                      cmp    eax,DWORD PTR ds:0xfb74f4
004df687  741a                              je     0x4df6a3
004df689  83c010                            add    eax,0x10
004df68c  83781410                          cmp    DWORD PTR [eax+0x14],0x10
004df690  7202                              jb     0x4df694
004df692  8b00                              mov    eax,DWORD PTR [eax]
004df694  8bc8                              mov    ecx,eax
004df696  bf7074fb00                        mov    edi,0xfb7470
004df69b  e8e0770100                        call   0x4f6e80
004df6a0  8b7d0c                            mov    edi,DWORD PTR [ebp+0xc]
004df6a3  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
004df6aa  7523                              jne    0x4df6cf
004df6ac  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
004df6b3  c745fc04000000                    mov    DWORD PTR [ebp-0x4],0x4
004df6ba  e861110700                        call   0x550820
004df6bf  68b0e6bc00                        push   0xbce6b0
004df6c4  e8512c3b00                        call   0x89231a
004df6c9  83c404                            add    esp,0x4
004df6cc  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004df6cf  6880f6fd00                        push   0xfdf680
004df6d4  e8872c0700                        call   0x552360
004df6d9  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
004df6e0  7523                              jne    0x4df705
004df6e2  830dc00ffc0001                    or     DWORD PTR ds:0xfc0fc0,0x1
004df6e9  c745fc05000000                    mov    DWORD PTR [ebp-0x4],0x5
004df6f0  e85b971f00                        call   0x6d8e50
004df6f5  68b0dbbc00                        push   0xbcdbb0
004df6fa  e81b2c3b00                        call   0x89231a
004df6ff  83c404                            add    esp,0x4
004df702  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004df705  57                                push   edi
004df706  b9c80ffc00                        mov    ecx,0xfc0fc8
004df70b  e8209d1f00                        call   0x6d9430
004df710  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
004df717  7523                              jne    0x4df73c
004df719  830dc00ffc0001                    or     DWORD PTR ds:0xfc0fc0,0x1
004df720  c745fc06000000                    mov    DWORD PTR [ebp-0x4],0x6
004df727  e824971f00                        call   0x6d8e50
004df72c  68b0dbbc00                        push   0xbcdbb0
004df731  e8e42b3b00                        call   0x89231a
004df736  83c404                            add    esp,0x4
004df739  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004df73c  57                                push   edi
004df73d  68c80ffc00                        push   0xfc0fc8
004df742  e8399e1f00                        call   0x6d9580
004df747  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
004df74a  83c74c                            add    edi,0x4c
004df74d  8bce                              mov    ecx,esi
004df74f  8bc7                              mov    eax,edi
004df751  8a10                              mov    dl,BYTE PTR [eax]
004df753  3a11                              cmp    dl,BYTE PTR [ecx]
004df755  751a                              jne    0x4df771
004df757  84d2                              test   dl,dl
004df759  7412                              je     0x4df76d
004df75b  8a5001                            mov    dl,BYTE PTR [eax+0x1]
004df75e  3a5101                            cmp    dl,BYTE PTR [ecx+0x1]
004df761  750e                              jne    0x4df771
004df763  83c002                            add    eax,0x2
004df766  83c102                            add    ecx,0x2
004df769  84d2                              test   dl,dl
004df76b  75e4                              jne    0x4df751
004df76d  33c0                              xor    eax,eax
004df76f  eb04                              jmp    0x4df775
004df771  1bc0                              sbb    eax,eax
004df773  1bc3                              sbb    eax,ebx
004df775  85c0                              test   eax,eax
004df777  7416                              je     0x4df78f
004df779  56                                push   esi
004df77a  6a40                              push   0x40
004df77c  57                                push   edi
004df77d  e8d7433b00                        call   0x893b59
004df782  83c40c                            add    esp,0xc
004df785  6a01                              push   0x1
004df787  e874262e00                        call   0x7c1e00
004df78c  83c404                            add    esp,0x4
004df78f  a138a8fb00                        mov    eax,ds:0xfba838
004df794  8b5048                            mov    edx,DWORD PTR [eax+0x48]
004df797  2b5044                            sub    edx,DWORD PTR [eax+0x44]
004df79a  c1fa02                            sar    edx,0x2
004df79d  85d2                              test   edx,edx
004df79f  0f84d5010000                      je     0x4df97a
004df7a5  8b4044                            mov    eax,DWORD PTR [eax+0x44]
004df7a8  8b30                              mov    esi,DWORD PTR [eax]
004df7aa  85f6                              test   esi,esi
004df7ac  0f84c8010000                      je     0x4df97a
004df7b2  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
004df7b9  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
004df7bc  8b3e                              mov    edi,DWORD PTR [esi]
004df7be  8b5e04                            mov    ebx,DWORD PTR [esi+0x4]
004df7c1  894de8                            mov    DWORD PTR [ebp-0x18],ecx
004df7c4  7527                              jne    0x4df7ed
004df7c6  830de879fb0001                    or     DWORD PTR ds:0xfb79e8,0x1
004df7cd  c745fc07000000                    mov    DWORD PTR [ebp-0x4],0x7
004df7d4  e807962b00                        call   0x798de0
004df7d9  68e0d2bc00                        push   0xbcd2e0
004df7de  e8372b3b00                        call   0x89231a
004df7e3  83c404                            add    esp,0x4
004df7e6  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004df7ed  a1e876fb00                        mov    eax,ds:0xfb76e8
004df7f2  8b55e8                            mov    edx,DWORD PTR [ebp-0x18]
004df7f5  89780c                            mov    DWORD PTR [eax+0xc],edi
004df7f8  33ff                              xor    edi,edi
004df7fa  895810                            mov    DWORD PTR [eax+0x10],ebx
004df7fd  8bc8                              mov    ecx,eax
004df7ff  8d5f01                            lea    ebx,[edi+0x1]
004df802  895014                            mov    DWORD PTR [eax+0x14],edx
004df805  89b9cc000000                      mov    DWORD PTR [ecx+0xcc],edi
004df80b  f30f104614                        movss  xmm0,DWORD PTR [esi+0x14]
004df810  f30f1145ec                        movss  DWORD PTR [ebp-0x14],xmm0
004df815  841de879fb00                      test   BYTE PTR ds:0xfb79e8,bl
004df81b  7526                              jne    0x4df843
004df81d  091de879fb00                      or     DWORD PTR ds:0xfb79e8,ebx
004df823  c745fc08000000                    mov    DWORD PTR [ebp-0x4],0x8
004df82a  e8b1952b00                        call   0x798de0
004df82f  68e0d2bc00                        push   0xbcd2e0
004df834  e8e12a3b00                        call   0x89231a
004df839  83c404                            add    esp,0x4
004df83c  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004df843  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
004df84a  a1e876fb00                        mov    eax,ds:0xfb76e8
004df84f  f30f1045ec                        movss  xmm0,DWORD PTR [ebp-0x14]
004df854  f30f114020                        movss  DWORD PTR [eax+0x20],xmm0
004df859  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
004df85f  f30f104624                        movss  xmm0,DWORD PTR [esi+0x24]
004df864  f30f1145ec                        movss  DWORD PTR [ebp-0x14],xmm0
004df869  752b                              jne    0x4df896
004df86b  091de879fb00                      or     DWORD PTR ds:0xfb79e8,ebx
004df871  c745fc09000000                    mov    DWORD PTR [ebp-0x4],0x9
004df878  e863952b00                        call   0x798de0
004df87d  68e0d2bc00                        push   0xbcd2e0
004df882  e8932a3b00                        call   0x89231a
004df887  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004df88e  f30f1045ec                        movss  xmm0,DWORD PTR [ebp-0x14]
004df893  83c404                            add    esp,0x4
004df896  a1e876fb00                        mov    eax,ds:0xfb76e8
004df89b  8bc8                              mov    ecx,eax
004df89d  8b00                              mov    eax,DWORD PTR [eax]
004df89f  3bc7                              cmp    eax,edi
004df8a1  7405                              je     0x4df8a8
004df8a3  f30f11407c                        movss  DWORD PTR [eax+0x7c],xmm0
004df8a8  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
004df8af  f30f114130                        movss  DWORD PTR [ecx+0x30],xmm0
004df8b4  f30f104628                        movss  xmm0,DWORD PTR [esi+0x28]
004df8b9  f30f1145f0                        movss  DWORD PTR [ebp-0x10],xmm0
004df8be  7526                              jne    0x4df8e6
004df8c0  091de879fb00                      or     DWORD PTR ds:0xfb79e8,ebx
004df8c6  c745fc0a000000                    mov    DWORD PTR [ebp-0x4],0xa
004df8cd  e80e952b00                        call   0x798de0
004df8d2  68e0d2bc00                        push   0xbcd2e0
004df8d7  e83e2a3b00                        call   0x89231a
004df8dc  83c404                            add    esp,0x4
004df8df  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004df8e6  a1e876fb00                        mov    eax,ds:0xfb76e8
004df8eb  8b08                              mov    ecx,DWORD PTR [eax]
004df8ed  f30f1045f0                        movss  xmm0,DWORD PTR [ebp-0x10]
004df8f2  f30f114034                        movss  DWORD PTR [eax+0x34],xmm0
004df8f7  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
004df8fd  3bcf                              cmp    ecx,edi
004df8ff  741e                              je     0x4df91f
004df901  d945f0                            fld    DWORD PTR [ebp-0x10]
004df904  dc35f056c500                      fdiv   QWORD PTR ds:0xc556f0
004df90a  d95dec                            fstp   DWORD PTR [ebp-0x14]
004df90d  d980bc000000                      fld    DWORD PTR [eax+0xbc]
004df913  d84dec                            fmul   DWORD PTR [ebp-0x14]
004df916  d95dec                            fstp   DWORD PTR [ebp-0x14]
004df919  d945ec                            fld    DWORD PTR [ebp-0x14]
004df91c  d95974                            fstp   DWORD PTR [ecx+0x74]
004df91f  393dd41bfe00                      cmp    DWORD PTR ds:0xfe1bd4,edi
004df925  7550                              jne    0x4df977
004df927  f30f10460c                        movss  xmm0,DWORD PTR [esi+0xc]
004df92c  f30f1145ec                        movss  DWORD PTR [ebp-0x14],xmm0
004df931  e80a4ef5ff                        call   0x434740
004df936  8b4040                            mov    eax,DWORD PTR [eax+0x40]
004df939  f30f1045ec                        movss  xmm0,DWORD PTR [ebp-0x14]
004df93e  33ff                              xor    edi,edi
004df940  f30f114018                        movss  DWORD PTR [eax+0x18],xmm0
004df945  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
004df94b  f30f104618                        movss  xmm0,DWORD PTR [esi+0x18]
004df950  f30f1145ec                        movss  DWORD PTR [ebp-0x14],xmm0
004df955  e8e64df5ff                        call   0x434740
004df95a  8b4040                            mov    eax,DWORD PTR [eax+0x40]
004df95d  f30f1045ec                        movss  xmm0,DWORD PTR [ebp-0x14]
004df962  f30f114024                        movss  DWORD PTR [eax+0x24],xmm0
004df967  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
004df96d  c705d41bfe0001000000              mov    DWORD PTR ds:0xfe1bd4,0x1
004df977  83cbff                            or     ebx,0xffffffff
004df97a  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
004df981  7523                              jne    0x4df9a6
004df983  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
004df98a  c745fc0b000000                    mov    DWORD PTR [ebp-0x4],0xb
004df991  e8ea430100                        call   0x4f3d80
004df996  68e0d1bc00                        push   0xbcd1e0
004df99b  e87a293b00                        call   0x89231a
004df9a0  83c404                            add    esp,0x4
004df9a3  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004df9a6  8b750c                            mov    esi,DWORD PTR [ebp+0xc]
004df9a9  8d550c                            lea    edx,[ebp+0xc]
004df9ac  b9d074fb00                        mov    ecx,0xfb74d0
004df9b1  89750c                            mov    DWORD PTR [ebp+0xc],esi
004df9b4  e837840100                        call   0x4f7df0
004df9b9  83781410                          cmp    DWORD PTR [eax+0x14],0x10
004df9bd  7202                              jb     0x4df9c1
004df9bf  8b00                              mov    eax,DWORD PTR [eax]
004df9c1  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
004df9c4  51                                push   ecx
004df9c5  8bc8                              mov    ecx,eax
004df9c7  e8d4f7ffff                        call   0x4df1a0
004df9cc  f605c0f3fd0001                    test   BYTE PTR ds:0xfdf3c0,0x1
004df9d3  751e                              jne    0x4df9f3
004df9d5  830dc0f3fd0001                    or     DWORD PTR ds:0xfdf3c0,0x1
004df9dc  6850dfbc00                        push   0xbcdf50
004df9e1  c705c4f3fd0000000000              mov    DWORD PTR ds:0xfdf3c4,0x0
004df9eb  e82a293b00                        call   0x89231a
004df9f0  83c404                            add    esp,0x4
004df9f3  8bce                              mov    ecx,esi
004df9f5  bfc4f3fd00                        mov    edi,0xfdf3c4
004df9fa  e811d30800                        call   0x56cd10
004df9ff  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004dfa02  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004dfa09  59                                pop    ecx
004dfa0a  5f                                pop    edi
004dfa0b  5e                                pop    esi
004dfa0c  5b                                pop    ebx
004dfa0d  8be5                              mov    esp,ebp
004dfa0f  5d                                pop    ebp
004dfa10  c20800                            ret    0x8
004dfa13  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
004dfa1a  7527                              jne    0x4dfa43
004dfa1c  830dc00ffc0001                    or     DWORD PTR ds:0xfc0fc0,0x1
004dfa23  c745fc0c000000                    mov    DWORD PTR [ebp-0x4],0xc
004dfa2a  e821941f00                        call   0x6d8e50
004dfa2f  68b0dbbc00                        push   0xbcdbb0
004dfa34  e8e1283b00                        call   0x89231a
004dfa39  83c404                            add    esp,0x4
004dfa3c  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004dfa43  56                                push   esi
004dfa44  b9c80ffc00                        mov    ecx,0xfc0fc8
004dfa49  e8e2991f00                        call   0x6d9430
004dfa4e  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
004dfa55  7527                              jne    0x4dfa7e
004dfa57  830dc00ffc0001                    or     DWORD PTR ds:0xfc0fc0,0x1
004dfa5e  c745fc0d000000                    mov    DWORD PTR [ebp-0x4],0xd
004dfa65  e8e6931f00                        call   0x6d8e50
004dfa6a  68b0dbbc00                        push   0xbcdbb0
004dfa6f  e8a6283b00                        call   0x89231a
004dfa74  83c404                            add    esp,0x4
004dfa77  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004dfa7e  56                                push   esi
004dfa7f  68c80ffc00                        push   0xfc0fc8
004dfa84  e8f79a1f00                        call   0x6d9580
004dfa89  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004dfa8c  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004dfa93  59                                pop    ecx
004dfa94  5f                                pop    edi
004dfa95  5e                                pop    esi
004dfa96  5b                                pop    ebx
004dfa97  8be5                              mov    esp,ebp
004dfa99  5d                                pop    ebp
004dfa9a  c20800                            ret    0x8

# R-map_resource_select 0x4df1a0..0x4df510
004df1a0  55                                push   ebp
004df1a1  8bec                              mov    ebp,esp
004df1a3  83e4f8                            and    esp,0xfffffff8
004df1a6  6aff                              push   0xffffffff
004df1a8  6888059400                        push   0x940588
004df1ad  64a100000000                      mov    eax,fs:0x0
004df1b3  50                                push   eax
004df1b4  83ec68                            sub    esp,0x68
004df1b7  a1201fd600                        mov    eax,ds:0xd61f20
004df1bc  33c4                              xor    eax,esp
004df1be  89442460                          mov    DWORD PTR [esp+0x60],eax
004df1c2  53                                push   ebx
004df1c3  56                                push   esi
004df1c4  57                                push   edi
004df1c5  a1201fd600                        mov    eax,ds:0xd61f20
004df1ca  33c4                              xor    eax,esp
004df1cc  50                                push   eax
004df1cd  8d442478                          lea    eax,[esp+0x78]
004df1d1  64a300000000                      mov    fs:0x0,eax
004df1d7  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
004df1da  8bb3a0000000                      mov    esi,DWORD PTR [ebx+0xa0]
004df1e0  895c241c                          mov    DWORD PTR [esp+0x1c],ebx
004df1e4  8bf9                              mov    edi,ecx
004df1e6  85f6                              test   esi,esi
004df1e8  7419                              je     0x4df203
004df1ea  56                                push   esi
004df1eb  e840db3400                        call   0x82cd30
004df1f0  56                                push   esi
004df1f1  e816203b00                        call   0x89120c
004df1f6  83c404                            add    esp,0x4
004df1f9  c783a000000000000000              mov    DWORD PTR [ebx+0xa0],0x0
004df203  8bc7                              mov    eax,edi
004df205  8d5001                            lea    edx,[eax+0x1]
004df208  8a08                              mov    cl,BYTE PTR [eax]
004df20a  40                                inc    eax
004df20b  84c9                              test   cl,cl
004df20d  75f9                              jne    0x4df208
004df20f  2bc2                              sub    eax,edx
004df211  0f844d020000                      je     0x4df464
004df217  68b0cec000                        push   0xc0ceb0
004df21c  8d442430                          lea    eax,[esp+0x30]
004df220  6a40                              push   0x40
004df222  50                                push   eax
004df223  e831493b00                        call   0x893b59
004df228  83c40c                            add    esp,0xc
004df22b  57                                push   edi
004df22c  8d4c2430                          lea    ecx,[esp+0x30]
004df230  6a40                              push   0x40
004df232  51                                push   ecx
004df233  e8cd693b00                        call   0x895c05
004df238  83c40c                            add    esp,0xc
004df23b  68c0cec000                        push   0xc0cec0
004df240  8d542430                          lea    edx,[esp+0x30]
004df244  6a40                              push   0x40
004df246  52                                push   edx
004df247  e8b9693b00                        call   0x895c05
004df24c  83c40c                            add    esp,0xc
004df24f  6838010000                        push   0x138
004df254  e80f203b00                        call   0x891268
004df259  83c404                            add    esp,0x4
004df25c  89442410                          mov    DWORD PTR [esp+0x10],eax
004df260  33ff                              xor    edi,edi
004df262  89bc2480000000                    mov    DWORD PTR [esp+0x80],edi
004df269  3bc7                              cmp    eax,edi
004df26b  7409                              je     0x4df276
004df26d  8bf0                              mov    esi,eax
004df26f  e8fc013500                        call   0x82f470
004df274  eb02                              jmp    0x4df278
004df276  33c0                              xor    eax,eax
004df278  50                                push   eax
004df279  8d442414                          lea    eax,[esp+0x14]
004df27d  83ceff                            or     esi,0xffffffff
004df280  89b42484000000                    mov    DWORD PTR [esp+0x84],esi
004df287  50                                push   eax
004df288  897c2418                          mov    DWORD PTR [esp+0x18],edi
004df28c  897c241c                          mov    DWORD PTR [esp+0x1c],edi
004df290  e89b1e0000                        call   0x4e1130
004df295  8d442410                          lea    eax,[esp+0x10]
004df299  8dbb98000000                      lea    edi,[ebx+0x98]
004df29f  c784248000000001000000            mov    DWORD PTR [esp+0x80],0x1
004df2aa  e8b11c0000                        call   0x4e0f60
004df2af  89b42480000000                    mov    DWORD PTR [esp+0x80],esi
004df2b6  8b7c2414                          mov    edi,DWORD PTR [esp+0x14]
004df2ba  85ff                              test   edi,edi
004df2bc  7425                              je     0x4df2e3
004df2be  8d4f04                            lea    ecx,[edi+0x4]
004df2c1  8bd6                              mov    edx,esi
004df2c3  f00fc111                          lock xadd DWORD PTR [ecx],edx
004df2c7  751a                              jne    0x4df2e3
004df2c9  8b07                              mov    eax,DWORD PTR [edi]
004df2cb  8b10                              mov    edx,DWORD PTR [eax]
004df2cd  8bcf                              mov    ecx,edi
004df2cf  ffd2                              call   edx
004df2d1  8d4708                            lea    eax,[edi+0x8]
004df2d4  f00fc130                          lock xadd DWORD PTR [eax],esi
004df2d8  7509                              jne    0x4df2e3
004df2da  8b17                              mov    edx,DWORD PTR [edi]
004df2dc  8b4204                            mov    eax,DWORD PTR [edx+0x4]
004df2df  8bcf                              mov    ecx,edi
004df2e1  ffd0                              call   eax
004df2e3  8b8398000000                      mov    eax,DWORD PTR [ebx+0x98]
004df2e9  50                                push   eax
004df2ea  8d7c2430                          lea    edi,[esp+0x30]
004df2ee  e84d0d3500                        call   0x830040
004df2f3  8b8b98000000                      mov    ecx,DWORD PTR [ebx+0x98]
004df2f9  89442410                          mov    DWORD PTR [esp+0x10],eax
004df2fd  e82e0f3500                        call   0x830230
004df302  8b8398000000                      mov    eax,DWORD PTR [ebx+0x98]
004df308  e833073500                        call   0x82fa40
004df30d  83ec08                            sub    esp,0x8
004df310  8bf4                              mov    esi,esp
004df312  c70600000000                      mov    DWORD PTR [esi],0x0
004df318  c7460400000000                    mov    DWORD PTR [esi+0x4],0x0
004df31f  8bbb9c000000                      mov    edi,DWORD PTR [ebx+0x9c]
004df325  8b8b98000000                      mov    ecx,DWORD PTR [ebx+0x98]
004df32b  89642420                          mov    DWORD PTR [esp+0x20],esp
004df32f  894c2420                          mov    DWORD PTR [esp+0x20],ecx
004df333  85ff                              test   edi,edi
004df335  7416                              je     0x4df34d
004df337  8bd7                              mov    edx,edi
004df339  e812cff9ff                        call   0x47c250
004df33e  84c0                              test   al,al
004df340  740b                              je     0x4df34d
004df342  8b542420                          mov    edx,DWORD PTR [esp+0x20]
004df346  57                                push   edi
004df347  52                                push   edx
004df348  e8733e2c00                        call   0x7a31c0
004df34d  e8be0b3500                        call   0x82ff10
004df352  8b742424                          mov    esi,DWORD PTR [esp+0x24]
004df356  8bbea4000000                      mov    edi,DWORD PTR [esi+0xa4]
004df35c  83c408                            add    esp,0x8
004df35f  8986a0000000                      mov    DWORD PTR [esi+0xa0],eax
004df365  85ff                              test   edi,edi
004df367  7419                              je     0x4df382
004df369  57                                push   edi
004df36a  e821dc3400                        call   0x82cf90
004df36f  57                                push   edi
004df370  e8971e3b00                        call   0x89120c
004df375  83c404                            add    esp,0x4
004df378  c786a400000000000000              mov    DWORD PTR [esi+0xa4],0x0
004df382  837c241000                        cmp    DWORD PTR [esp+0x10],0x0
004df387  0f84d7000000                      je     0x4df464
004df38d  e80e58f2ff                        call   0x404ba0
004df392  8b804c5f0000                      mov    eax,DWORD PTR [eax+0x5f4c]
004df398  83f802                            cmp    eax,0x2
004df39b  0f85c3000000                      jne    0x4df464
004df3a1  6a34                              push   0x34
004df3a3  e8c01e3b00                        call   0x891268
004df3a8  83c404                            add    esp,0x4
004df3ab  89442410                          mov    DWORD PTR [esp+0x10],eax
004df3af  c784248000000002000000            mov    DWORD PTR [esp+0x80],0x2
004df3ba  85c0                              test   eax,eax
004df3bc  7408                              je     0x4df3c6
004df3be  50                                push   eax
004df3bf  e81cdb3400                        call   0x82cee0
004df3c4  eb02                              jmp    0x4df3c8
004df3c6  33c0                              xor    eax,eax
004df3c8  83cfff                            or     edi,0xffffffff
004df3cb  89bc2480000000                    mov    DWORD PTR [esp+0x80],edi
004df3d2  83ec08                            sub    esp,0x8
004df3d5  8986a4000000                      mov    DWORD PTR [esi+0xa4],eax
004df3db  8d8398000000                      lea    eax,[ebx+0x98]
004df3e1  8bcc                              mov    ecx,esp
004df3e3  89642418                          mov    DWORD PTR [esp+0x18],esp
004df3e7  e8341b0000                        call   0x4e0f20
004df3ec  8d442428                          lea    eax,[esp+0x28]
004df3f0  50                                push   eax
004df3f1  e83a123500                        call   0x830630
004df3f6  c784248000000003000000            mov    DWORD PTR [esp+0x80],0x3
004df401  8b0d38a8fb00                      mov    ecx,DWORD PTR ds:0xfba838
004df407  8b4140                            mov    eax,DWORD PTR [ecx+0x40]
004df40a  8b9b98000000                      mov    ebx,DWORD PTR [ebx+0x98]
004df410  85c0                              test   eax,eax
004df412  740e                              je     0x4df422
004df414  8b9058010000                      mov    edx,DWORD PTR [eax+0x158]
004df41a  8b805c010000                      mov    eax,DWORD PTR [eax+0x15c]
004df420  eb17                              jmp    0x4df439
004df422  0f57c0                            xorps  xmm0,xmm0
004df425  f30f11442410                      movss  DWORD PTR [esp+0x10],xmm0
004df42b  8b542410                          mov    edx,DWORD PTR [esp+0x10]
004df42f  f30f11442414                      movss  DWORD PTR [esp+0x14],xmm0
004df435  8b442414                          mov    eax,DWORD PTR [esp+0x14]
004df439  8b8ea4000000                      mov    ecx,DWORD PTR [esi+0xa4]
004df43f  8b7308                            mov    esi,DWORD PTR [ebx+0x8]
004df442  56                                push   esi
004df443  8b7304                            mov    esi,DWORD PTR [ebx+0x4]
004df446  56                                push   esi
004df447  50                                push   eax
004df448  52                                push   edx
004df449  8d542430                          lea    edx,[esp+0x30]
004df44d  52                                push   edx
004df44e  e8fddb3400                        call   0x82d050
004df453  8d442420                          lea    eax,[esp+0x20]
004df457  50                                push   eax
004df458  89bc2484000000                    mov    DWORD PTR [esp+0x84],edi
004df45f  e82c000000                        call   0x4df490
004df464  8b4c2478                          mov    ecx,DWORD PTR [esp+0x78]
004df468  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004df46f  59                                pop    ecx
004df470  5f                                pop    edi
004df471  5e                                pop    esi
004df472  5b                                pop    ebx
004df473  8b4c2460                          mov    ecx,DWORD PTR [esp+0x60]
004df477  33cc                              xor    ecx,esp
004df479  e8831b3b00                        call   0x891001
004df47e  8be5                              mov    esp,ebp
004df480  5d                                pop    ebp
004df481  c20400                            ret    0x4
004df484  cc                                int3
004df485  cc                                int3
004df486  cc                                int3
004df487  cc                                int3
004df488  cc                                int3
004df489  cc                                int3
004df48a  cc                                int3
004df48b  cc                                int3
004df48c  cc                                int3
004df48d  cc                                int3
004df48e  cc                                int3
004df48f  cc                                int3
004df490  55                                push   ebp
004df491  8bec                              mov    ebp,esp
004df493  6aff                              push   0xffffffff
004df495  6868659000                        push   0x906568
004df49a  64a100000000                      mov    eax,fs:0x0
004df4a0  50                                push   eax
004df4a1  56                                push   esi
004df4a2  57                                push   edi
004df4a3  a1201fd600                        mov    eax,ds:0xd61f20
004df4a8  33c5                              xor    eax,ebp
004df4aa  50                                push   eax
004df4ab  8d45f4                            lea    eax,[ebp-0xc]
004df4ae  64a300000000                      mov    fs:0x0,eax
004df4b4  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
004df4b7  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
004df4be  8b7708                            mov    esi,DWORD PTR [edi+0x8]
004df4c1  85f6                              test   esi,esi
004df4c3  7429                              je     0x4df4ee
004df4c5  8d4604                            lea    eax,[esi+0x4]
004df4c8  83c9ff                            or     ecx,0xffffffff
004df4cb  f00fc108                          lock xadd DWORD PTR [eax],ecx
004df4cf  751d                              jne    0x4df4ee
004df4d1  8b16                              mov    edx,DWORD PTR [esi]
004df4d3  8b02                              mov    eax,DWORD PTR [edx]
004df4d5  8bce                              mov    ecx,esi
004df4d7  ffd0                              call   eax
004df4d9  8d4e08                            lea    ecx,[esi+0x8]
004df4dc  83caff                            or     edx,0xffffffff
004df4df  f00fc111                          lock xadd DWORD PTR [ecx],edx
004df4e3  7509                              jne    0x4df4ee
004df4e5  8b06                              mov    eax,DWORD PTR [esi]
004df4e7  8b5004                            mov    edx,DWORD PTR [eax+0x4]
004df4ea  8bce                              mov    ecx,esi
004df4ec  ffd2                              call   edx
004df4ee  c70720cfc000                      mov    DWORD PTR [edi],0xc0cf20
004df4f4  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004df4f7  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004df4fe  59                                pop    ecx
004df4ff  5f                                pop    edi
004df500  5e                                pop    esi
004df501  8be5                              mov    esp,ebp
004df503  5d                                pop    ebp
004df504  c20400                            ret    0x4
004df507  cc                                int3
004df508  cc                                int3
004df509  cc                                int3
004df50a  cc                                int3
004df50b  cc                                int3
004df50c  cc                                int3
004df50d  cc                                int3
004df50e  cc                                int3
004df50f  cc                                int3

# R-field_ready_common 0x4b2570..0x4b2615
004b2570  55                                push   ebp
004b2571  8bec                              mov    ebp,esp
004b2573  6aff                              push   0xffffffff
004b2575  687cb29300                        push   0x93b27c
004b257a  64a100000000                      mov    eax,fs:0x0
004b2580  50                                push   eax
004b2581  53                                push   ebx
004b2582  a1201fd600                        mov    eax,ds:0xd61f20
004b2587  33c5                              xor    eax,ebp
004b2589  50                                push   eax
004b258a  8d45f4                            lea    eax,[ebp-0xc]
004b258d  64a300000000                      mov    fs:0x0,eax
004b2593  a1a4a7fb00                        mov    eax,ds:0xfba7a4
004b2598  bb01000000                        mov    ebx,0x1
004b259d  895804                            mov    DWORD PTR [eax+0x4],ebx
004b25a0  841db873fb00                      test   BYTE PTR ds:0xfb73b8,bl
004b25a6  7526                              jne    0x4b25ce
004b25a8  091db873fb00                      or     DWORD PTR ds:0xfb73b8,ebx
004b25ae  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
004b25b5  e8b6db0a00                        call   0x560170
004b25ba  6810d1bc00                        push   0xbcd110
004b25bf  e856fd3d00                        call   0x89231a
004b25c4  83c404                            add    esp,0x4
004b25c7  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
004b25ce  833de873fb0000                    cmp    DWORD PTR ds:0xfb73e8,0x0
004b25d5  752a                              jne    0x4b2601
004b25d7  841d147cfb00                      test   BYTE PTR ds:0xfb7c14,bl
004b25dd  751b                              jne    0x4b25fa
004b25df  091d147cfb00                      or     DWORD PTR ds:0xfb7c14,ebx
004b25e5  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004b25e8  e863e12100                        call   0x6d0750
004b25ed  6830d5bc00                        push   0xbcd530
004b25f2  e823fd3d00                        call   0x89231a
004b25f7  83c404                            add    esp,0x4
004b25fa  83253088fb00fe                    and    DWORD PTR ds:0xfb8830,0xfffffffe
004b2601  33c0                              xor    eax,eax
004b2603  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004b2606  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004b260d  59                                pop    ecx
004b260e  5b                                pop    ebx
004b260f  8be5                              mov    esp,ebp
004b2611  5d                                pop    ebp
004b2612  c20c00                            ret    0xc

# R-lb_change_map 0x4a0ac0..0x4a0b3c
004a0ac0  55                                push   ebp
004a0ac1  8bec                              mov    ebp,esp
004a0ac3  83e4f8                            and    esp,0xfffffff8
004a0ac6  6aff                              push   0xffffffff
004a0ac8  68ee619400                        push   0x9461ee
004a0acd  64a100000000                      mov    eax,fs:0x0
004a0ad3  50                                push   eax
004a0ad4  51                                push   ecx
004a0ad5  a1201fd600                        mov    eax,ds:0xd61f20
004a0ada  33c4                              xor    eax,esp
004a0adc  50                                push   eax
004a0add  8d442408                          lea    eax,[esp+0x8]
004a0ae1  64a300000000                      mov    fs:0x0,eax
004a0ae7  b801000000                        mov    eax,0x1
004a0aec  84052cb2fa00                      test   BYTE PTR ds:0xfab22c,al
004a0af2  7528                              jne    0x4a0b1c
004a0af4  09052cb2fa00                      or     DWORD PTR ds:0xfab22c,eax
004a0afa  c744241000000000                  mov    DWORD PTR [esp+0x10],0x0
004a0b02  e889e10300                        call   0x4dec90
004a0b07  6830cebc00                        push   0xbcce30
004a0b0c  e809183f00                        call   0x89231a
004a0b11  83c404                            add    esp,0x4
004a0b14  c7442410ffffffff                  mov    DWORD PTR [esp+0x10],0xffffffff
004a0b1c  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
004a0b1f  50                                push   eax
004a0b20  6830b1fa00                        push   0xfab130
004a0b25  e8e6e90300                        call   0x4df510
004a0b2a  8b4c2408                          mov    ecx,DWORD PTR [esp+0x8]
004a0b2e  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004a0b35  59                                pop    ecx
004a0b36  8be5                              mov    esp,ebp
004a0b38  5d                                pop    ebp
004a0b39  c20400                            ret    0x4

# R-scenario_ready 0x4c4910..0x4c4919
004c4910  55                                push   ebp
004c4911  8bec                              mov    ebp,esp
004c4913  5d                                pop    ebp
004c4914  e957dcfeff                        jmp    0x4b2570

# R-common_ready_delegate 0x4c5930..0x4c5935
004c5930  8b01                              mov    eax,DWORD PTR [ecx]
004c5932  ff602c                            jmp    DWORD PTR [eax+0x2c]
