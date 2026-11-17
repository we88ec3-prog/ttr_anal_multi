
[V01] Formal wrapper constructor; owns state VA=0x6f4380 raw=0x2f3780 bytes=142 sha256=388a182e5936c08a3a0f85f3b07f9abe22ea4858831cf99c3ff976d37bc21d5f
006f4380  51                                push   ecx
006f4381  56                                push   esi
006f4382  57                                push   edi
006f4383  e828310000                        call   0x6f74b0
006f4388  85c0                              test   eax,eax
006f438a  740a                              je     0x6f4396
006f438c  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
006f438f  c74158a0716f00                    mov    DWORD PTR [ecx+0x58],0x6f71a0
006f4396  a3c8f3fd00                        mov    ds:0xfdf3c8,eax
006f439b  c705ccf3fd0000000000              mov    DWORD PTR ds:0xfdf3cc,0x0
006f43a5  c705d0f3fd0001000000              mov    DWORD PTR ds:0xfdf3d0,0x1
006f43af  e8ac320000                        call   0x6f7660
006f43b4  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8
006f43ba  6a00                              push   0x0
006f43bc  6820446f00                        push   0x6f4420
006f43c1  e8ea110000                        call   0x6f55b0
006f43c6  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8
006f43cc  bf7c25c400                        mov    edi,0xc4257c
006f43d1  b8eed8ffff                        mov    eax,0xffffd8ee
006f43d6  e8b5130000                        call   0x6f5790
006f43db  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8
006f43e1  6a00                              push   0x0
006f43e3  68a0486f00                        push   0x6f48a0
006f43e8  e8c3110000                        call   0x6f55b0
006f43ed  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8
006f43f3  83c410                            add    esp,0x10
006f43f6  bf9025c400                        mov    edi,0xc42590
006f43fb  b8eed8ffff                        mov    eax,0xffffd8ee
006f4400  e88b130000                        call   0x6f5790
006f4405  5f                                pop    edi
006f4406  b8c8f3fd00                        mov    eax,0xfdf3c8
006f440b  5e                                pop    esi
006f440c  59                                pop    ecx
006f440d  c3                                ret

[V02] Generic wrapper ownership-gated destructor VA=0x6f4410 raw=0x2f3810 bytes=14 sha256=60ea9f4cf51753869c798272c079538fc08f65e3c47ee6bd15a20ae0ecdb84be
006f4410  83780800                          cmp    DWORD PTR [eax+0x8],0x0
006f4414  7407                              je     0x6f441d
006f4416  8b00                              mov    eax,DWORD PTR [eax]
006f4418  e9d3310000                        jmp    0x6f75f0
006f441d  c3                                ret

[V03] New independent state; main-thread and allocator writer VA=0x6f74b0 raw=0x2f68b0 bytes=295 sha256=c0d2ae5347a32f3f4a31195bdb6b62fe3cb9fd74309efe4200996eb4a4892417
006f74b0  51                                push   ecx
006f74b1  53                                push   ebx
006f74b2  56                                push   esi
006f74b3  6878010000                        push   0x178
006f74b8  33db                              xor    ebx,ebx
006f74ba  53                                push   ebx
006f74bb  e8a6051a00                        call   0x897a66
006f74c0  8bf0                              mov    esi,eax
006f74c2  83c408                            add    esp,0x8
006f74c5  3bf3                              cmp    esi,ebx
006f74c7  7506                              jne    0x6f74cf
006f74c9  33c0                              xor    eax,eax
006f74cb  5e                                pop    esi
006f74cc  5b                                pop    ebx
006f74cd  59                                pop    ecx
006f74ce  c3                                ret
006f74cf  8d4678                            lea    eax,[esi+0x78]
006f74d2  891e                              mov    DWORD PTR [esi],ebx
006f74d4  c6460408                          mov    BYTE PTR [esi+0x4],0x8
006f74d8  c6401421                          mov    BYTE PTR [eax+0x14],0x21
006f74dc  894610                            mov    DWORD PTR [esi+0x10],eax
006f74df  895e20                            mov    DWORD PTR [esi+0x20],ebx
006f74e2  895e2c                            mov    DWORD PTR [esi+0x2c],ebx
006f74e5  895e70                            mov    DWORD PTR [esi+0x70],ebx
006f74e8  895e44                            mov    DWORD PTR [esi+0x44],ebx
006f74eb  895e3c                            mov    DWORD PTR [esi+0x3c],ebx
006f74ee  895e40                            mov    DWORD PTR [esi+0x40],ebx
006f74f1  895e68                            mov    DWORD PTR [esi+0x68],ebx
006f74f4  895e30                            mov    DWORD PTR [esi+0x30],ebx
006f74f7  c7463600000001                    mov    DWORD PTR [esi+0x36],0x1000000
006f74fe  66c746056100                      mov    WORD PTR [esi+0x5],0x61
006f7504  895e14                            mov    DWORD PTR [esi+0x14],ebx
006f7507  895e28                            mov    DWORD PTR [esi+0x28],ebx
006f750a  895e18                            mov    DWORD PTR [esi+0x18],ebx
006f750d  895e74                            mov    DWORD PTR [esi+0x74],ebx
006f7510  895e50                            mov    DWORD PTR [esi+0x50],ebx
006f7513  8d4878                            lea    ecx,[eax+0x78]
006f7516  33d2                              xor    edx,edx
006f7518  66895634                          mov    WORD PTR [esi+0x34],dx
006f751c  898888000000                      mov    DWORD PTR [eax+0x88],ecx
006f7522  89888c000000                      mov    DWORD PTR [eax+0x8c],ecx
006f7528  c7400c70716f00                    mov    DWORD PTR [eax+0xc],0x6f7170
006f752f  895810                            mov    DWORD PTR [eax+0x10],ebx
006f7532  897070                            mov    DWORD PTR [eax+0x70],esi
006f7535  895840                            mov    DWORD PTR [eax+0x40],ebx
006f7538  895808                            mov    DWORD PTR [eax+0x8],ebx
006f753b  895804                            mov    DWORD PTR [eax+0x4],ebx
006f753e  8918                              mov    DWORD PTR [eax],ebx
006f7540  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
006f7543  895968                            mov    DWORD PTR [ecx+0x68],ebx
006f7546  89701c                            mov    DWORD PTR [eax+0x1c],esi
006f7549  895834                            mov    DWORD PTR [eax+0x34],ebx
006f754c  89583c                            mov    DWORD PTR [eax+0x3c],ebx
006f754f  895858                            mov    DWORD PTR [eax+0x58],ebx
006f7552  885815                            mov    BYTE PTR [eax+0x15],bl
006f7555  895818                            mov    DWORD PTR [eax+0x18],ebx
006f7558  895824                            mov    DWORD PTR [eax+0x24],ebx
006f755b  895828                            mov    DWORD PTR [eax+0x28],ebx
006f755e  89582c                            mov    DWORD PTR [eax+0x2c],ebx
006f7561  895830                            mov    DWORD PTR [eax+0x30],ebx
006f7564  c7404478010000                    mov    DWORD PTR [eax+0x44],0x178
006f756b  89584c                            mov    DWORD PTR [eax+0x4c],ebx
006f756e  8d481c                            lea    ecx,[eax+0x1c]
006f7571  894820                            mov    DWORD PTR [eax+0x20],ecx
006f7574  53                                push   ebx
006f7575  b9c8000000                        mov    ecx,0xc8
006f757a  894850                            mov    DWORD PTR [eax+0x50],ecx
006f757d  894854                            mov    DWORD PTR [eax+0x54],ecx
006f7580  6880726f00                        push   0x6f7280
006f7585  56                                push   esi
006f7586  899898000000                      mov    DWORD PTR [eax+0x98],ebx
006f758c  89989c000000                      mov    DWORD PTR [eax+0x9c],ebx
006f7592  8998a0000000                      mov    DWORD PTR [eax+0xa0],ebx
006f7598  8998a4000000                      mov    DWORD PTR [eax+0xa4],ebx
006f759e  8998a8000000                      mov    DWORD PTR [eax+0xa8],ebx
006f75a4  8998ac000000                      mov    DWORD PTR [eax+0xac],ebx
006f75aa  8998b0000000                      mov    DWORD PTR [eax+0xb0],ebx
006f75b0  8998b4000000                      mov    DWORD PTR [eax+0xb4],ebx
006f75b6  8998b8000000                      mov    DWORD PTR [eax+0xb8],ebx
006f75bc  e8df650000                        call   0x6fdba0
006f75c1  83c40c                            add    esp,0xc
006f75c4  85c0                              test   eax,eax
006f75c6  7409                              je     0x6f75d1
006f75c8  8bc6                              mov    eax,esi
006f75ca  e831fdffff                        call   0x6f7300
006f75cf  33f6                              xor    esi,esi
006f75d1  8bc6                              mov    eax,esi
006f75d3  5e                                pop    esi
006f75d4  5b                                pop    ebx
006f75d5  59                                pop    ecx
006f75d6  c3                                ret

[V04] State close canonicalizes main thread and drains finalizers VA=0x6f75f0 raw=0x2f69f0 bytes=98 sha256=5b1dcae2cd23466959da92f18b84e56b995ec2d3b7696acb48e48944112bc575
006f75f0  55                                push   ebp
006f75f1  8bec                              mov    ebp,esp
006f75f3  83e4f8                            and    esp,0xfffffff8
006f75f6  51                                push   ecx
006f75f7  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
006f75fa  57                                push   edi
006f75fb  8b7970                            mov    edi,DWORD PTR [ecx+0x70]
006f75fe  8b5720                            mov    edx,DWORD PTR [edi+0x20]
006f7601  52                                push   edx
006f7602  e859620000                        call   0x6fd860
006f7607  83c404                            add    esp,0x4
006f760a  6a01                              push   0x1
006f760c  57                                push   edi
006f760d  e81e2b0000                        call   0x6fa130
006f7612  83c408                            add    esp,0x8
006f7615  c7477400000000                    mov    DWORD PTR [edi+0x74],0x0
006f761c  8d642400                          lea    esp,[esp+0x0]
006f7620  8b4728                            mov    eax,DWORD PTR [edi+0x28]
006f7623  894714                            mov    DWORD PTR [edi+0x14],eax
006f7626  8b00                              mov    eax,DWORD PTR [eax]
006f7628  894708                            mov    DWORD PTR [edi+0x8],eax
006f762b  89470c                            mov    DWORD PTR [edi+0xc],eax
006f762e  33c0                              xor    eax,eax
006f7630  50                                push   eax
006f7631  68e0756f00                        push   0x6f75e0
006f7636  57                                push   edi
006f7637  894734                            mov    DWORD PTR [edi+0x34],eax
006f763a  e861650000                        call   0x6fdba0
006f763f  83c40c                            add    esp,0xc
006f7642  85c0                              test   eax,eax
006f7644  75da                              jne    0x6f7620
006f7646  8bc7                              mov    eax,edi
006f7648  e8b3fcffff                        call   0x6f7300
006f764d  5f                                pop    edi
006f764e  8be5                              mov    esp,ebp
006f7650  5d                                pop    ebp
006f7651  c3                                ret

[V05] Whole state release and allocator call VA=0x6f7300 raw=0x2f6700 bytes=140 sha256=79a4aa3426b412aba81d544edca0062a23ddd4fbea9efea3e6e650593f305c5b
006f7300  56                                push   esi
006f7301  57                                push   edi
006f7302  8bf8                              mov    edi,eax
006f7304  8b4720                            mov    eax,DWORD PTR [edi+0x20]
006f7307  8b7710                            mov    esi,DWORD PTR [edi+0x10]
006f730a  50                                push   eax
006f730b  e850650000                        call   0x6fd860
006f7310  57                                push   edi
006f7311  e8da3b0000                        call   0x6faef0
006f7316  8b4710                            mov    eax,DWORD PTR [edi+0x10]
006f7319  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
006f731c  8b10                              mov    edx,DWORD PTR [eax]
006f731e  03c9                              add    ecx,ecx
006f7320  6a00                              push   0x0
006f7322  03c9                              add    ecx,ecx
006f7324  51                                push   ecx
006f7325  52                                push   edx
006f7326  57                                push   edi
006f7327  e854950000                        call   0x700880
006f732c  8b463c                            mov    eax,DWORD PTR [esi+0x3c]
006f732f  8b4e34                            mov    ecx,DWORD PTR [esi+0x34]
006f7332  6a00                              push   0x0
006f7334  50                                push   eax
006f7335  51                                push   ecx
006f7336  57                                push   edi
006f7337  e844950000                        call   0x700880
006f733c  894634                            mov    DWORD PTR [esi+0x34],eax
006f733f  c7463c00000000                    mov    DWORD PTR [esi+0x3c],0x0
006f7346  8b4730                            mov    eax,DWORD PTR [edi+0x30]
006f7349  8d1440                            lea    edx,[eax+eax*2]
006f734c  8b4728                            mov    eax,DWORD PTR [edi+0x28]
006f734f  03d2                              add    edx,edx
006f7351  03d2                              add    edx,edx
006f7353  6a00                              push   0x0
006f7355  03d2                              add    edx,edx
006f7357  52                                push   edx
006f7358  50                                push   eax
006f7359  57                                push   edi
006f735a  e821950000                        call   0x700880
006f735f  8b4f2c                            mov    ecx,DWORD PTR [edi+0x2c]
006f7362  8b5720                            mov    edx,DWORD PTR [edi+0x20]
006f7365  6a00                              push   0x0
006f7367  c1e104                            shl    ecx,0x4
006f736a  51                                push   ecx
006f736b  52                                push   edx
006f736c  57                                push   edi
006f736d  e80e950000                        call   0x700880
006f7372  8b4610                            mov    eax,DWORD PTR [esi+0x10]
006f7375  8b4e0c                            mov    ecx,DWORD PTR [esi+0xc]
006f7378  83c448                            add    esp,0x48
006f737b  6a00                              push   0x0
006f737d  6878010000                        push   0x178
006f7382  57                                push   edi
006f7383  50                                push   eax
006f7384  ffd1                              call   ecx
006f7386  83c410                            add    esp,0x10
006f7389  5f                                pop    edi
006f738a  5e                                pop    esi
006f738b  c3                                ret

[V06] Protected close finalizer callback VA=0x6f75e0 raw=0x2f69e0 bytes=15 sha256=ec9300125a0dbc0d5ea9d94c5eb03396a69b9bee0f499c3a2bf0b812598ab1c3
006f75e0  55                                push   ebp
006f75e1  8bec                              mov    ebp,esp
006f75e3  56                                push   esi
006f75e4  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
006f75e7  e8e4370000                        call   0x6fadd0
006f75ec  5e                                pop    esi
006f75ed  5d                                pop    ebp
006f75ee  c3                                ret

[V07] Global formal wrapper atexit target VA=0xbce6d0 raw=0x7cdad0 bytes=22 sha256=78192562040d365653be17b97552250ddc799abe1375a5dd5bf9539b584360ba
00bce6d0  51                                push   ecx
00bce6d1  833dd0f3fd0000                    cmp    DWORD PTR ds:0xfdf3d0,0x0
00bce6d8  740a                              je     0xbce6e4
00bce6da  a1c8f3fd00                        mov    eax,ds:0xfdf3c8
00bce6df  e80c8fb2ff                        call   0x6f75f0
00bce6e4  59                                pop    ecx
00bce6e5  c3                                ret

[V08] Formal singleton getter with initialization guard VA=0x49b230 raw=0x9a630 bytes=98 sha256=55f6514d5e0cf44d2eeb13e4e2a3c8e5df3be4933b39c103405a3b33e50b661f
0049b230  55                                push   ebp
0049b231  8bec                              mov    ebp,esp
0049b233  6aff                              push   0xffffffff
0049b235  68cea59300                        push   0x93a5ce
0049b23a  64a100000000                      mov    eax,fs:0x0
0049b240  50                                push   eax
0049b241  a1201fd600                        mov    eax,ds:0xd61f20
0049b246  33c5                              xor    eax,ebp
0049b248  50                                push   eax
0049b249  8d45f4                            lea    eax,[ebp-0xc]
0049b24c  64a300000000                      mov    fs:0x0,eax
0049b252  b801000000                        mov    eax,0x1
0049b257  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al
0049b25d  751f                              jne    0x49b27e
0049b25f  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax
0049b265  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0049b26c  e80f912500                        call   0x6f4380
0049b271  68d0e6bc00                        push   0xbce6d0
0049b276  e89f703f00                        call   0x89231a
0049b27b  83c404                            add    esp,0x4
0049b27e  b8c8f3fd00                        mov    eax,0xfdf3c8
0049b283  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0049b286  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0049b28d  59                                pop    ecx
0049b28e  8be5                              mov    esp,ebp
0049b290  5d                                pop    ebp
0049b291  c3                                ret

[P01] Prepass singleton construction and nonowning wrapper VA=0x55c610 raw=0x15ba10 bytes=272 sha256=3078ede28e1ce7a101048ff45c73ced35e51f5938e8e6c31a62925f78dcd31ae
0055c610  55                                push   ebp
0055c611  8bec                              mov    ebp,esp
0055c613  6aff                              push   0xffffffff
0055c615  68a8899300                        push   0x9389a8
0055c61a  64a100000000                      mov    eax,fs:0x0
0055c620  50                                push   eax
0055c621  83ec14                            sub    esp,0x14
0055c624  53                                push   ebx
0055c625  a1201fd600                        mov    eax,ds:0xd61f20
0055c62a  33c5                              xor    eax,ebp
0055c62c  50                                push   eax
0055c62d  8d45f4                            lea    eax,[ebp-0xc]
0055c630  64a300000000                      mov    fs:0x0,eax
0055c636  33db                              xor    ebx,ebx
0055c638  6a18                              push   0x18
0055c63a  c745ecec1efe00                    mov    DWORD PTR [ebp-0x14],0xfe1eec
0055c641  891dfc1efe00                      mov    DWORD PTR ds:0xfe1efc,ebx
0055c647  e81c4c3300                        call   0x891268
0055c64c  83c404                            add    esp,0x4
0055c64f  3bc3                              cmp    eax,ebx
0055c651  0f849e000000                      je     0x55c6f5
0055c657  a3f81efe00                        mov    ds:0xfe1ef8,eax
0055c65c  8900                              mov    DWORD PTR [eax],eax
0055c65e  a1f81efe00                        mov    eax,ds:0xfe1ef8
0055c663  894004                            mov    DWORD PTR [eax+0x4],eax
0055c666  a1f81efe00                        mov    eax,ds:0xfe1ef8
0055c66b  894008                            mov    DWORD PTR [eax+0x8],eax
0055c66e  8b0df81efe00                      mov    ecx,DWORD PTR ds:0xfe1ef8
0055c674  b001                              mov    al,0x1
0055c676  884114                            mov    BYTE PTR [ecx+0x14],al
0055c679  8b15f81efe00                      mov    edx,DWORD PTR ds:0xfe1ef8
0055c67f  884215                            mov    BYTE PTR [edx+0x15],al
0055c682  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0055c685  c705181ffe000f000000              mov    DWORD PTR ds:0xfe1f18,0xf
0055c68f  891d141ffe00                      mov    DWORD PTR ds:0xfe1f14,ebx
0055c695  881d041ffe00                      mov    BYTE PTR ds:0xfe1f04,bl
0055c69b  8845fc                            mov    BYTE PTR [ebp-0x4],al
0055c69e  e80dae1900                        call   0x6f74b0
0055c6a3  3bc3                              cmp    eax,ebx
0055c6a5  740a                              je     0x55c6b1
0055c6a7  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0055c6aa  c74158a0716f00                    mov    DWORD PTR [ecx+0x58],0x6f71a0
0055c6b1  6a0c                              push   0xc
0055c6b3  a3ec1efe00                        mov    ds:0xfe1eec,eax
0055c6b8  e8ab4b3300                        call   0x891268
0055c6bd  83c404                            add    esp,0x4
0055c6c0  3bc3                              cmp    eax,ebx
0055c6c2  7410                              je     0x55c6d4
0055c6c4  8b15ec1efe00                      mov    edx,DWORD PTR ds:0xfe1eec
0055c6ca  8910                              mov    DWORD PTR [eax],edx
0055c6cc  895804                            mov    DWORD PTR [eax+0x4],ebx
0055c6cf  895808                            mov    DWORD PTR [eax+0x8],ebx
0055c6d2  eb02                              jmp    0x55c6d6
0055c6d4  33c0                              xor    eax,eax
0055c6d6  a3f01efe00                        mov    ds:0xfe1ef0,eax
0055c6db  e800110000                        call   0x55d7e0
0055c6e0  b8ec1efe00                        mov    eax,0xfe1eec
0055c6e5  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0055c6e8  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0055c6ef  59                                pop    ecx
0055c6f0  5b                                pop    ebx
0055c6f1  8be5                              mov    esp,ebp
0055c6f3  5d                                pop    ebp
0055c6f4  c3                                ret
0055c6f5  8d45f0                            lea    eax,[ebp-0x10]
0055c6f8  50                                push   eax
0055c6f9  8d4de0                            lea    ecx,[ebp-0x20]
0055c6fc  895df0                            mov    DWORD PTR [ebp-0x10],ebx
0055c6ff  e8a5493300                        call   0x8910a9
0055c704  68a857c800                        push   0xc857a8
0055c709  8d4de0                            lea    ecx,[ebp-0x20]
0055c70c  51                                push   ecx
0055c70d  c745e0a42cbd00                    mov    DWORD PTR [ebp-0x20],0xbd2ca4
0055c714  e8d7023400                        call   0x89c9f0
0055c719  cc                                int3
0055c71a  cc                                int3
0055c71b  cc                                int3
0055c71c  cc                                int3
0055c71d  cc                                int3
0055c71e  cc                                int3
0055c71f  cc                                int3

[P02] Prepass singleton destructor; wrapper then owned state VA=0x55c720 raw=0x15bb20 bytes=234 sha256=26ca7270b2c2f5aa40c475140fb317da25e818106bb2cead8bf137909b5840db
0055c720  55                                push   ebp
0055c721  8bec                              mov    ebp,esp
0055c723  6aff                              push   0xffffffff
0055c725  6880869300                        push   0x938680
0055c72a  64a100000000                      mov    eax,fs:0x0
0055c730  50                                push   eax
0055c731  83ec0c                            sub    esp,0xc
0055c734  56                                push   esi
0055c735  a1201fd600                        mov    eax,ds:0xd61f20
0055c73a  33c5                              xor    eax,ebp
0055c73c  50                                push   eax
0055c73d  8d45f4                            lea    eax,[ebp-0xc]
0055c740  64a300000000                      mov    fs:0x0,eax
0055c746  c745f0ec1efe00                    mov    DWORD PTR [ebp-0x10],0xfe1eec
0055c74d  68f41efe00                        push   0xfe1ef4
0055c752  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0055c759  e8821b0000                        call   0x55e2e0
0055c75e  a1f01efe00                        mov    eax,ds:0xfe1ef0
0055c763  83c404                            add    esp,0x4
0055c766  85c0                              test   eax,eax
0055c768  7422                              je     0x55c78c
0055c76a  83780800                          cmp    DWORD PTR [eax+0x8],0x0
0055c76e  8bf0                              mov    esi,eax
0055c770  7407                              je     0x55c779
0055c772  8b00                              mov    eax,DWORD PTR [eax]
0055c774  e877ae1900                        call   0x6f75f0
0055c779  56                                push   esi
0055c77a  e88d4a3300                        call   0x89120c
0055c77f  83c404                            add    esp,0x4
0055c782  c705f01efe0000000000              mov    DWORD PTR ds:0xfe1ef0,0x0
0055c78c  a1ec1efe00                        mov    eax,ds:0xfe1eec
0055c791  e85aae1900                        call   0x6f75f0
0055c796  833d181ffe0010                    cmp    DWORD PTR ds:0xfe1f18,0x10
0055c79d  720e                              jb     0x55c7ad
0055c79f  a1041ffe00                        mov    eax,ds:0xfe1f04
0055c7a4  50                                push   eax
0055c7a5  e8624a3300                        call   0x89120c
0055c7aa  83c404                            add    esp,0x4
0055c7ad  c705181ffe000f000000              mov    DWORD PTR ds:0xfe1f18,0xf
0055c7b7  c705141ffe0000000000              mov    DWORD PTR ds:0xfe1f14,0x0
0055c7c1  c605041ffe0000                    mov    BYTE PTR ds:0xfe1f04,0x0
0055c7c8  c745f0f41efe00                    mov    DWORD PTR [ebp-0x10],0xfe1ef4
0055c7cf  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0055c7d6  a1f81efe00                        mov    eax,ds:0xfe1ef8
0055c7db  8b08                              mov    ecx,DWORD PTR [eax]
0055c7dd  50                                push   eax
0055c7de  51                                push   ecx
0055c7df  8d75ec                            lea    esi,[ebp-0x14]
0055c7e2  b8f41efe00                        mov    eax,0xfe1ef4
0055c7e7  e8d478ffff                        call   0x5540c0
0055c7ec  a1f81efe00                        mov    eax,ds:0xfe1ef8
0055c7f1  50                                push   eax
0055c7f2  e8154a3300                        call   0x89120c
0055c7f7  83c404                            add    esp,0x4
0055c7fa  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0055c7fd  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0055c804  59                                pop    ecx
0055c805  5e                                pop    esi
0055c806  8be5                              mov    esp,ebp
0055c808  5d                                pop    ebp
0055c809  c3                                ret

[P03] Prepass singleton getter VA=0x55c5a0 raw=0x15b9a0 bytes=98 sha256=9daad88bc97a7320723a69fc8295a1c37b85c68c655cb5c33af70fa5b5e9a8b2
0055c5a0  55                                push   ebp
0055c5a1  8bec                              mov    ebp,esp
0055c5a3  6aff                              push   0xffffffff
0055c5a5  68de899300                        push   0x9389de
0055c5aa  64a100000000                      mov    eax,fs:0x0
0055c5b0  50                                push   eax
0055c5b1  a1201fd600                        mov    eax,ds:0xd61f20
0055c5b6  33c5                              xor    eax,ebp
0055c5b8  50                                push   eax
0055c5b9  8d45f4                            lea    eax,[ebp-0xc]
0055c5bc  64a300000000                      mov    fs:0x0,eax
0055c5c2  b801000000                        mov    eax,0x1
0055c5c7  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al
0055c5cd  751f                              jne    0x55c5ee
0055c5cf  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax
0055c5d5  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0055c5dc  e82f000000                        call   0x55c610
0055c5e1  6890f2bc00                        push   0xbcf290
0055c5e6  e82f5d3300                        call   0x89231a
0055c5eb  83c404                            add    esp,0x4
0055c5ee  b8ec1efe00                        mov    eax,0xfe1eec
0055c5f3  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0055c5f6  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0055c5fd  59                                pop    ecx
0055c5fe  8be5                              mov    esp,ebp
0055c600  5d                                pop    ebp
0055c601  c3                                ret

[P04] Per-load collector reset and six rebinding operations VA=0x55d6a0 raw=0x15caa0 bytes=307 sha256=3ba41e59f3fd8e858ada7d94ca290144d24b17c955f9e7e7798540b516bf99ca
0055d6a0  55                                push   ebp
0055d6a1  8bec                              mov    ebp,esp
0055d6a3  51                                push   ecx
0055d6a4  53                                push   ebx
0055d6a5  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0055d6a8  56                                push   esi
0055d6a9  8d4308                            lea    eax,[ebx+0x8]
0055d6ac  57                                push   edi
0055d6ad  50                                push   eax
0055d6ae  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0055d6b1  e82a0c0000                        call   0x55e2e0
0055d6b6  83c404                            add    esp,0x4
0055d6b9  6a00                              push   0x0
0055d6bb  687523bf00                        push   0xbf2375
0055d6c0  8d4b18                            lea    ecx,[ebx+0x18]
0055d6c3  e8a853eaff                        call   0x402a70
0055d6c8  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0055d6cb  8b30                              mov    esi,DWORD PTR [eax]
0055d6cd  6a00                              push   0x0
0055d6cf  6840c95500                        push   0x55c940
0055d6d4  894508                            mov    DWORD PTR [ebp+0x8],eax
0055d6d7  e8d47e1900                        call   0x6f55b0
0055d6dc  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0055d6df  8b31                              mov    esi,DWORD PTR [ecx]
0055d6e1  bf3002c100                        mov    edi,0xc10230
0055d6e6  b8eed8ffff                        mov    eax,0xffffd8ee
0055d6eb  e8a0801900                        call   0x6f5790
0055d6f0  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0055d6f3  8b30                              mov    esi,DWORD PTR [eax]
0055d6f5  6a00                              push   0x0
0055d6f7  68e0cc5500                        push   0x55cce0
0055d6fc  894508                            mov    DWORD PTR [ebp+0x8],eax
0055d6ff  e8ac7e1900                        call   0x6f55b0
0055d704  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0055d707  8b32                              mov    esi,DWORD PTR [edx]
0055d709  bf4002c100                        mov    edi,0xc10240
0055d70e  b8eed8ffff                        mov    eax,0xffffd8ee
0055d713  e878801900                        call   0x6f5790
0055d718  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0055d71b  8b30                              mov    esi,DWORD PTR [eax]
0055d71d  6a00                              push   0x0
0055d71f  68d0ce5500                        push   0x55ced0
0055d724  894508                            mov    DWORD PTR [ebp+0x8],eax
0055d727  e8847e1900                        call   0x6f55b0
0055d72c  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0055d72f  8b31                              mov    esi,DWORD PTR [ecx]
0055d731  bf4c02c100                        mov    edi,0xc1024c
0055d736  b8eed8ffff                        mov    eax,0xffffd8ee
0055d73b  e850801900                        call   0x6f5790
0055d740  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0055d743  8b30                              mov    esi,DWORD PTR [eax]
0055d745  6a00                              push   0x0
0055d747  6820d25500                        push   0x55d220
0055d74c  894508                            mov    DWORD PTR [ebp+0x8],eax
0055d74f  e85c7e1900                        call   0x6f55b0
0055d754  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0055d757  8b32                              mov    esi,DWORD PTR [edx]
0055d759  bf5802c100                        mov    edi,0xc10258
0055d75e  b8eed8ffff                        mov    eax,0xffffd8ee
0055d763  e828801900                        call   0x6f5790
0055d768  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0055d76b  8b30                              mov    esi,DWORD PTR [eax]
0055d76d  6a00                              push   0x0
0055d76f  6860d55500                        push   0x55d560
0055d774  894508                            mov    DWORD PTR [ebp+0x8],eax
0055d777  e8347e1900                        call   0x6f55b0
0055d77c  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0055d77f  8b31                              mov    esi,DWORD PTR [ecx]
0055d781  bf6402c100                        mov    edi,0xc10264
0055d786  b8eed8ffff                        mov    eax,0xffffd8ee
0055d78b  e800801900                        call   0x6f5790
0055d790  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0055d793  8b30                              mov    esi,DWORD PTR [eax]
0055d795  6a00                              push   0x0
0055d797  68e0d55500                        push   0x55d5e0
0055d79c  894508                            mov    DWORD PTR [ebp+0x8],eax
0055d79f  e80c7e1900                        call   0x6f55b0
0055d7a4  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0055d7a7  8b32                              mov    esi,DWORD PTR [edx]
0055d7a9  83c430                            add    esp,0x30
0055d7ac  bf7002c100                        mov    edi,0xc10270
0055d7b1  b8eed8ffff                        mov    eax,0xffffd8ee
0055d7b6  e8d57f1900                        call   0x6f5790
0055d7bb  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0055d7be  8b4b04                            mov    ecx,DWORD PTR [ebx+0x4]
0055d7c1  50                                push   eax
0055d7c2  e889721900                        call   0x6f4a50
0055d7c7  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0055d7ca  5f                                pop    edi
0055d7cb  5e                                pop    esi
0055d7cc  5b                                pop    ebx
0055d7cd  8be5                              mov    esp,ebp
0055d7cf  5d                                pop    ebp
0055d7d0  c20800                            ret    0x8

[P05] Prepass atexit target VA=0xbcf290 raw=0x7ce690 bytes=8 sha256=30dad028846456aa41b18c1e6244c80686d352019915791f48f5104be3490702
00bcf290  51                                push   ecx
00bcf291  e88ad498ff                        call   0x55c720
00bcf296  59                                pop    ecx
00bcf297  c3                                ret

[B01] Borrowed-wrapper cleanup thunk and EH handler family 1 VA=0x9383c0 raw=0x5377c0 bytes=35 sha256=6f792ce105be5f64d60406554a6777f665a5c2921852f32b847c90cefdbf333c
009383c0  8d45e8                            lea    eax,[ebp-0x18]
009383c3  e948c0dbff                        jmp    0x6f4410
009383c8  8b542408                          mov    edx,DWORD PTR [esp+0x8]
009383cc  8d420c                            lea    eax,[edx+0xc]
009383cf  8b4af0                            mov    ecx,DWORD PTR [edx-0x10]
009383d2  33c8                              xor    ecx,eax
009383d4  e8288cf5ff                        call   0x891001
009383d9  b89065cb00                        mov    eax,0xcb6590
009383de  e9cf53f6ff                        jmp    0x89d7b2

[B02] Borrowed-wrapper cleanup thunk and EH handler family 2 VA=0x938630 raw=0x537a30 bytes=35 sha256=d24f0774a00cf1f78a30b661821dd4e1f278bf505bbd77aa5e82d291ac4ca58c
00938630  8d45e8                            lea    eax,[ebp-0x18]
00938633  e9d8bddbff                        jmp    0x6f4410
00938638  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093863c  8d420c                            lea    eax,[edx+0xc]
0093863f  8b4ae8                            mov    ecx,DWORD PTR [edx-0x18]
00938642  33c8                              xor    ecx,eax
00938644  e8b889f5ff                        call   0x891001
00938649  b8a067cb00                        mov    eax,0xcb67a0
0093864e  e95f51f6ff                        jmp    0x89d7b2

[B03] Borrowed-wrapper cleanup thunk and EH handler family 3 VA=0x9387d0 raw=0x537bd0 bytes=35 sha256=d09422f564c4e1527c535e0bfc24f0d2ab8913ada47b72db4552739c6bf19bc4
009387d0  8d45e8                            lea    eax,[ebp-0x18]
009387d3  e938bcdbff                        jmp    0x6f4410
009387d8  8b542408                          mov    edx,DWORD PTR [esp+0x8]
009387dc  8d420c                            lea    eax,[edx+0xc]
009387df  8b4aec                            mov    ecx,DWORD PTR [edx-0x14]
009387e2  33c8                              xor    ecx,eax
009387e4  e81888f5ff                        call   0x891001
009387e9  b81869cb00                        mov    eax,0xcb6918
009387ee  e9bf4ff6ff                        jmp    0x89d7b2

[B04] Representative Q.EnableInput wrapper with owns=0 VA=0x568bc0 raw=0x167fc0 bytes=86 sha256=6d54802889a3f1be68047959bdd3a74fd816ca1198bc2aba3b308900cabe0c3f
00568bc0  55                                push   ebp
00568bc1  8bec                              mov    ebp,esp
00568bc3  6aff                              push   0xffffffff
00568bc5  68c8839300                        push   0x9383c8
00568bca  64a100000000                      mov    eax,fs:0x0
00568bd0  50                                push   eax
00568bd1  83ec0c                            sub    esp,0xc
00568bd4  a1201fd600                        mov    eax,ds:0xd61f20
00568bd9  33c5                              xor    eax,ebp
00568bdb  50                                push   eax
00568bdc  8d45f4                            lea    eax,[ebp-0xc]
00568bdf  64a300000000                      mov    fs:0x0,eax
00568be5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
00568be8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
00568beb  33c0                              xor    eax,eax
00568bed  8945ec                            mov    DWORD PTR [ebp-0x14],eax
00568bf0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
00568bf3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
00568bf6  8b0d7827fe00                      mov    ecx,DWORD PTR ds:0xfe2778
00568bfc  ff158c27fe00                      call   DWORD PTR ds:0xfe278c
00568c02  b801000000                        mov    eax,0x1
00568c07  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
00568c0a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00568c11  59                                pop    ecx
00568c12  8be5                              mov    esp,ebp
00568c14  5d                                pop    ebp
00568c15  c3                                ret

[B05] Representative Q callback wrapper with owns=0 VA=0x569d20 raw=0x169120 bytes=103 sha256=6504f76cc74fe83904cf873f6bd24587eddb872f88e4bb1e6eddd8ddb334aa42
00569d20  55                                push   ebp
00569d21  8bec                              mov    ebp,esp
00569d23  6aff                              push   0xffffffff
00569d25  6838869300                        push   0x938638
00569d2a  64a100000000                      mov    eax,fs:0x0
00569d30  50                                push   eax
00569d31  83ec0c                            sub    esp,0xc
00569d34  56                                push   esi
00569d35  57                                push   edi
00569d36  a1201fd600                        mov    eax,ds:0xd61f20
00569d3b  33c5                              xor    eax,ebp
00569d3d  50                                push   eax
00569d3e  8d45f4                            lea    eax,[ebp-0xc]
00569d41  64a300000000                      mov    fs:0x0,eax
00569d47  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
00569d4a  8945e8                            mov    DWORD PTR [ebp-0x18],eax
00569d4d  33c0                              xor    eax,eax
00569d4f  8945ec                            mov    DWORD PTR [ebp-0x14],eax
00569d52  8945f0                            mov    DWORD PTR [ebp-0x10],eax
00569d55  8945fc                            mov    DWORD PTR [ebp-0x4],eax
00569d58  8b354428fe00                      mov    esi,DWORD PTR ds:0xfe2844
00569d5e  8b3d7827fe00                      mov    edi,DWORD PTR ds:0xfe2778
00569d64  8d45e8                            lea    eax,[ebp-0x18]
00569d67  e8c4180000                        call   0x56b630
00569d6c  50                                push   eax
00569d6d  8bcf                              mov    ecx,edi
00569d6f  ffd6                              call   esi
00569d71  b801000000                        mov    eax,0x1
00569d76  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
00569d79  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00569d80  59                                pop    ecx
00569d81  5f                                pop    edi
00569d82  5e                                pop    esi
00569d83  8be5                              mov    esp,ebp
00569d85  5d                                pop    ebp
00569d86  c3                                ret

[B06] Representative Tutorial callback wrapper with owns=0 VA=0x4ac270 raw=0xab670 bytes=110 sha256=6c806b1c24f0af2426d5af3b6072265c5224fe47a7e7e1ad6fe9880c86fc30c1
004ac270  55                                push   ebp
004ac271  8bec                              mov    ebp,esp
004ac273  6aff                              push   0xffffffff
004ac275  68d8879300                        push   0x9387d8
004ac27a  64a100000000                      mov    eax,fs:0x0
004ac280  50                                push   eax
004ac281  83ec0c                            sub    esp,0xc
004ac284  56                                push   esi
004ac285  a1201fd600                        mov    eax,ds:0xd61f20
004ac28a  33c5                              xor    eax,ebp
004ac28c  50                                push   eax
004ac28d  8d45f4                            lea    eax,[ebp-0xc]
004ac290  64a300000000                      mov    fs:0x0,eax
004ac296  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
004ac299  33c0                              xor    eax,eax
004ac29b  8975e8                            mov    DWORD PTR [ebp-0x18],esi
004ac29e  8945ec                            mov    DWORD PTR [ebp-0x14],eax
004ac2a1  8945f0                            mov    DWORD PTR [ebp-0x10],eax
004ac2a4  8945fc                            mov    DWORD PTR [ebp-0x4],eax
004ac2a7  8b0d0418fe00                      mov    ecx,DWORD PTR ds:0xfe1804
004ac2ad  ff153018fe00                      call   DWORD PTR ds:0xfe1830
004ac2b3  894508                            mov    DWORD PTR [ebp+0x8],eax
004ac2b6  8b4608                            mov    eax,DWORD PTR [esi+0x8]
004ac2b9  db4508                            fild   DWORD PTR [ebp+0x8]
004ac2bc  c7400803000000                    mov    DWORD PTR [eax+0x8],0x3
004ac2c3  dd18                              fstp   QWORD PTR [eax]
004ac2c5  83460810                          add    DWORD PTR [esi+0x8],0x10
004ac2c9  b801000000                        mov    eax,0x1
004ac2ce  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
004ac2d1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
004ac2d8  59                                pop    ecx
004ac2d9  5e                                pop    esi
004ac2da  8be5                              mov    esp,ebp
004ac2dc  5d                                pop    ebp
004ac2dd  c3                                ret

[A01] Default VM allocator implementation VA=0x6f7170 raw=0x2f6570 bytes=48 sha256=87ad57bfb370aa087c812174ffb8f9cc6032a37aa415be0ed84df545a5f7dc8d
006f7170  55                                push   ebp
006f7171  8bec                              mov    ebp,esp
006f7173  8b4514                            mov    eax,DWORD PTR [ebp+0x14]
006f7176  85c0                              test   eax,eax
006f7178  7510                              jne    0x6f718a
006f717a  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
006f717d  50                                push   eax
006f717e  e879af1900                        call   0x8920fc
006f7183  83c404                            add    esp,0x4
006f7186  33c0                              xor    eax,eax
006f7188  5d                                pop    ebp
006f7189  c3                                ret
006f718a  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
006f718d  50                                push   eax
006f718e  51                                push   ecx
006f718f  e8d2081a00                        call   0x897a66
006f7194  83c408                            add    esp,0x8
006f7197  5d                                pop    ebp
006f7198  c3                                ret
006f7199  cc                                int3
006f719a  cc                                int3
006f719b  cc                                int3
006f719c  cc                                int3
006f719d  cc                                int3
006f719e  cc                                int3
006f719f  cc                                int3

[W01] Literal use of 0xfdf3c8 VA=0x48b118 raw=0x8a518 bytes=5 sha256=d6062fcc9bd72bdd3f35b0d2475a74123b7efba6c1ea9f692ce756464bf507f8
0048b118  b9c8f3fd00                        mov    ecx,0xfdf3c8

[W02] Literal use of 0xfdf3c8 VA=0x48b127 raw=0x8a527 bytes=5 sha256=d6062fcc9bd72bdd3f35b0d2475a74123b7efba6c1ea9f692ce756464bf507f8
0048b127  b9c8f3fd00                        mov    ecx,0xfdf3c8

[W03] Literal use of 0xfdf3c8 VA=0x48b136 raw=0x8a536 bytes=5 sha256=d6062fcc9bd72bdd3f35b0d2475a74123b7efba6c1ea9f692ce756464bf507f8
0048b136  b9c8f3fd00                        mov    ecx,0xfdf3c8

[W04] Literal use of 0xfdf3c8 VA=0x48ca0c raw=0x8be0c bytes=5 sha256=d6062fcc9bd72bdd3f35b0d2475a74123b7efba6c1ea9f692ce756464bf507f8
0048ca0c  b9c8f3fd00                        mov    ecx,0xfdf3c8

[W05] Literal use of 0xfdf3c8 VA=0x48ca48 raw=0x8be48 bytes=5 sha256=d6062fcc9bd72bdd3f35b0d2475a74123b7efba6c1ea9f692ce756464bf507f8
0048ca48  b9c8f3fd00                        mov    ecx,0xfdf3c8

[W06] Literal use of 0xfdf3c8 VA=0x48d76b raw=0x8cb6b bytes=5 sha256=d1945c4922f190eda68c632d4a140498ba539123e7c507ca545fb6232a741a50
0048d76b  bec8f3fd00                        mov    esi,0xfdf3c8

[W07] Literal use of 0xfdf3c8 VA=0x48d7d4 raw=0x8cbd4 bytes=5 sha256=d1945c4922f190eda68c632d4a140498ba539123e7c507ca545fb6232a741a50
0048d7d4  bec8f3fd00                        mov    esi,0xfdf3c8

[W08] Literal use of 0xfdf3c8 VA=0x49b27e raw=0x9a67e bytes=5 sha256=a5b71fa26cc7a172a7eb45200d8c30cda21a953270028894b5546936e9d08f1d
0049b27e  b8c8f3fd00                        mov    eax,0xfdf3c8

[W09] Literal use of 0xfdf3c8 VA=0x4a09ab raw=0x9fdab bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
004a09ab  68c8f3fd00                        push   0xfdf3c8

[W10] Literal use of 0xfdf3c8 VA=0x4a12e2 raw=0xa06e2 bytes=5 sha256=0d33e2d6713f46f7b9ba0a15741359cc13aec8fd9d22ee16287f007c6b9f9f84
004a12e2  bfc8f3fd00                        mov    edi,0xfdf3c8

[W11] Literal use of 0xfdf3c8 VA=0x4b5ad5 raw=0xb4ed5 bytes=6 sha256=836633999fa085a4e888480d2d7dd772703fd38332c53a01f40c70effff98b09
004b5ad5  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8

[W12] Literal use of 0xfdf3c8 VA=0x4b5aea raw=0xb4eea bytes=6 sha256=45e6ead069f946e961e4fe06baa31863c3dc073832da018ab5dfc5a29c3d3101
004b5aea  8b15c8f3fd00                      mov    edx,DWORD PTR ds:0xfdf3c8

[W13] Literal use of 0xfdf3c8 VA=0x4b5b2a raw=0xb4f2a bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
004b5b2a  68c8f3fd00                        push   0xfdf3c8

[W14] Literal use of 0xfdf3c8 VA=0x4b5be1 raw=0xb4fe1 bytes=5 sha256=a7e03ac4edba341ccdc0d72a07599ef57a187d786c27fb92fb85550d9b5ce85f
004b5be1  a1c8f3fd00                        mov    eax,ds:0xfdf3c8

[W15] Literal use of 0xfdf3c8 VA=0x54e8c2 raw=0x14dcc2 bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
0054e8c2  68c8f3fd00                        push   0xfdf3c8

[W16] Literal use of 0xfdf3c8 VA=0x55e706 raw=0x15db06 bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
0055e706  68c8f3fd00                        push   0xfdf3c8

[W17] Literal use of 0xfdf3c8 VA=0x55f06e raw=0x15e46e bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
0055f06e  68c8f3fd00                        push   0xfdf3c8

[W18] Literal use of 0xfdf3c8 VA=0x561e3d raw=0x16123d bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
00561e3d  68c8f3fd00                        push   0xfdf3c8

[W19] Literal use of 0xfdf3c8 VA=0x562028 raw=0x161428 bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
00562028  68c8f3fd00                        push   0xfdf3c8

[W20] Literal use of 0xfdf3c8 VA=0x5b973d raw=0x1b8b3d bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
005b973d  68c8f3fd00                        push   0xfdf3c8

[W21] Literal use of 0xfdf3c8 VA=0x5c366d raw=0x1c2a6d bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
005c366d  68c8f3fd00                        push   0xfdf3c8

[W22] Literal use of 0xfdf3c8 VA=0x672fd9 raw=0x2723d9 bytes=6 sha256=836633999fa085a4e888480d2d7dd772703fd38332c53a01f40c70effff98b09
00672fd9  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8

[W23] Literal use of 0xfdf3c8 VA=0x672fee raw=0x2723ee bytes=6 sha256=45e6ead069f946e961e4fe06baa31863c3dc073832da018ab5dfc5a29c3d3101
00672fee  8b15c8f3fd00                      mov    edx,DWORD PTR ds:0xfdf3c8

[W24] Literal use of 0xfdf3c8 VA=0x67302f raw=0x27242f bytes=5 sha256=a5b71fa26cc7a172a7eb45200d8c30cda21a953270028894b5546936e9d08f1d
0067302f  b8c8f3fd00                        mov    eax,0xfdf3c8

[W25] Literal use of 0xfdf3c8 VA=0x673039 raw=0x272439 bytes=6 sha256=2d0cddf1269a7b6e189828f689aadf678298623491be759313285752467162b6
00673039  8b3dc8f3fd00                      mov    edi,DWORD PTR ds:0xfdf3c8

[W26] Literal use of 0xfdf3c8 VA=0x673151 raw=0x272551 bytes=5 sha256=a7e03ac4edba341ccdc0d72a07599ef57a187d786c27fb92fb85550d9b5ce85f
00673151  a1c8f3fd00                        mov    eax,ds:0xfdf3c8

[W27] Literal use of 0xfdf3c8 VA=0x6bcf0e raw=0x2bc30e bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
006bcf0e  68c8f3fd00                        push   0xfdf3c8

[W28] Literal use of 0xfdf3c8 VA=0x6bcfef raw=0x2bc3ef bytes=5 sha256=a7e03ac4edba341ccdc0d72a07599ef57a187d786c27fb92fb85550d9b5ce85f
006bcfef  a1c8f3fd00                        mov    eax,ds:0xfdf3c8

[W29] Literal use of 0xfdf3c8 VA=0x6bd00a raw=0x2bc40a bytes=6 sha256=836633999fa085a4e888480d2d7dd772703fd38332c53a01f40c70effff98b09
006bd00a  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8

[W30] Literal use of 0xfdf3c8 VA=0x6bd7b7 raw=0x2bcbb7 bytes=5 sha256=3f5f41799bea95d9ee965479727c5828910f6d1a8eb9fbfba8ac81ce4bb41abe
006bd7b7  68c8f3fd00                        push   0xfdf3c8

[W31] Literal use of 0xfdf3c8 VA=0x6bf788 raw=0x2beb88 bytes=6 sha256=836633999fa085a4e888480d2d7dd772703fd38332c53a01f40c70effff98b09
006bf788  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8

[W32] Literal use of 0xfdf3c8 VA=0x6bf79d raw=0x2beb9d bytes=6 sha256=39f0756233676633bacceda28bd6592ff9b7dbdb70319a17eab2dfb86d7892a6
006bf79d  8b0dc8f3fd00                      mov    ecx,DWORD PTR ds:0xfdf3c8

[W33] Literal use of 0xfdf3c8 VA=0x6bf7e0 raw=0x2bebe0 bytes=5 sha256=a5b71fa26cc7a172a7eb45200d8c30cda21a953270028894b5546936e9d08f1d
006bf7e0  b8c8f3fd00                        mov    eax,0xfdf3c8

[W34] Literal use of 0xfdf3c8 VA=0x6bf7ef raw=0x2bebef bytes=5 sha256=a5b71fa26cc7a172a7eb45200d8c30cda21a953270028894b5546936e9d08f1d
006bf7ef  b8c8f3fd00                        mov    eax,0xfdf3c8

[W35] Literal use of 0xfdf3c8 VA=0x6bf8be raw=0x2becbe bytes=5 sha256=a7e03ac4edba341ccdc0d72a07599ef57a187d786c27fb92fb85550d9b5ce85f
006bf8be  a1c8f3fd00                        mov    eax,ds:0xfdf3c8

[W36] Literal use of 0xfdf3c8 VA=0x6f4396 raw=0x2f3796 bytes=5 sha256=e99ffad89e68bc3568b2cdbf7cf23879bb8c967a1c84616dfbd65a7ec49c9e8e
006f4396  a3c8f3fd00                        mov    ds:0xfdf3c8,eax

[W37] Literal use of 0xfdf3c8 VA=0x6f43b4 raw=0x2f37b4 bytes=6 sha256=836633999fa085a4e888480d2d7dd772703fd38332c53a01f40c70effff98b09
006f43b4  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8

[W38] Literal use of 0xfdf3c8 VA=0x6f43c6 raw=0x2f37c6 bytes=6 sha256=836633999fa085a4e888480d2d7dd772703fd38332c53a01f40c70effff98b09
006f43c6  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8

[W39] Literal use of 0xfdf3c8 VA=0x6f43db raw=0x2f37db bytes=6 sha256=836633999fa085a4e888480d2d7dd772703fd38332c53a01f40c70effff98b09
006f43db  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8

[W40] Literal use of 0xfdf3c8 VA=0x6f43ed raw=0x2f37ed bytes=6 sha256=836633999fa085a4e888480d2d7dd772703fd38332c53a01f40c70effff98b09
006f43ed  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8

[W41] Literal use of 0xfdf3c8 VA=0x6f4406 raw=0x2f3806 bytes=5 sha256=a5b71fa26cc7a172a7eb45200d8c30cda21a953270028894b5546936e9d08f1d
006f4406  b8c8f3fd00                        mov    eax,0xfdf3c8

[W42] Literal use of 0xfdf3c8 VA=0xbce6da raw=0x7cdada bytes=5 sha256=a7e03ac4edba341ccdc0d72a07599ef57a187d786c27fb92fb85550d9b5ce85f
00bce6da  a1c8f3fd00                        mov    eax,ds:0xfdf3c8

[X01] Literal use of 0xfdf3cc VA=0x6f439b raw=0x2f379b bytes=10 sha256=7d071cb95036ef9235d3a53b6074aa2c83beea18e127fee00bc9e9bf08fc280b
006f439b  c705ccf3fd0000000000              mov    DWORD PTR ds:0xfdf3cc,0x0

[O01] Literal use of 0xfdf3d0 VA=0x6f43a5 raw=0x2f37a5 bytes=10 sha256=65521881b7ccfca9f5312d2207a0388874133290e04b5e068873ceb743e8966b
006f43a5  c705d0f3fd0001000000              mov    DWORD PTR ds:0xfdf3d0,0x1

[O02] Literal use of 0xfdf3d0 VA=0xbce6d1 raw=0x7cdad1 bytes=7 sha256=0f6c8897f2c19c5e4bd276d575f8fcba16455fa09e97b537fac4049191a60786
00bce6d1  833dd0f3fd0000                    cmp    DWORD PTR ds:0xfdf3d0,0x0

[G01] Literal use of 0xfdf3d4 VA=0x48b0e3 raw=0x8a4e3 bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
0048b0e3  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G02] Literal use of 0xfdf3d4 VA=0x48b0f2 raw=0x8a4f2 bytes=7 sha256=5f77ee5356044d08c08690bd0d560360b05d698640dbab90257d90a1bc57d03d
0048b0f2  830dd4f3fd0001                    or     DWORD PTR ds:0xfdf3d4,0x1

[G03] Literal use of 0xfdf3d4 VA=0x48c9da raw=0x8bdda bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
0048c9da  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G04] Literal use of 0xfdf3d4 VA=0x48c9e3 raw=0x8bde3 bytes=6 sha256=cb643b97fbc237556d8284040f4818fdc9c98557a1b0470d08ca3ae31b4bdf18
0048c9e3  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi

[G05] Literal use of 0xfdf3d4 VA=0x48ca16 raw=0x8be16 bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
0048ca16  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G06] Literal use of 0xfdf3d4 VA=0x48ca1f raw=0x8be1f bytes=6 sha256=cb643b97fbc237556d8284040f4818fdc9c98557a1b0470d08ca3ae31b4bdf18
0048ca1f  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi

[G07] Literal use of 0xfdf3d4 VA=0x48d6fd raw=0x8cafd bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
0048d6fd  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G08] Literal use of 0xfdf3d4 VA=0x48d71a raw=0x8cb1a bytes=6 sha256=cb643b97fbc237556d8284040f4818fdc9c98557a1b0470d08ca3ae31b4bdf18
0048d71a  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi

[G09] Literal use of 0xfdf3d4 VA=0x48d77a raw=0x8cb7a bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
0048d77a  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G10] Literal use of 0xfdf3d4 VA=0x48d783 raw=0x8cb83 bytes=6 sha256=cb643b97fbc237556d8284040f4818fdc9c98557a1b0470d08ca3ae31b4bdf18
0048d783  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi

[G11] Literal use of 0xfdf3d4 VA=0x49b257 raw=0x9a657 bytes=6 sha256=c781bb238fbf9632706f3d12638c7a77461562a57aa630eb96ac63f948cbfd92
0049b257  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al

[G12] Literal use of 0xfdf3d4 VA=0x49b25f raw=0x9a65f bytes=6 sha256=975a4d12d983c511bdce58f3a220952527be885f475b8743a7c6fab63b7760de
0049b25f  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax

[G13] Literal use of 0xfdf3d4 VA=0x4a097a raw=0x9fd7a bytes=6 sha256=c781bb238fbf9632706f3d12638c7a77461562a57aa630eb96ac63f948cbfd92
004a097a  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al

[G14] Literal use of 0xfdf3d4 VA=0x4a0982 raw=0x9fd82 bytes=6 sha256=975a4d12d983c511bdce58f3a220952527be885f475b8743a7c6fab63b7760de
004a0982  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax

[G15] Literal use of 0xfdf3d4 VA=0x4a12b1 raw=0xa06b1 bytes=6 sha256=c781bb238fbf9632706f3d12638c7a77461562a57aa630eb96ac63f948cbfd92
004a12b1  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al

[G16] Literal use of 0xfdf3d4 VA=0x4a12b9 raw=0xa06b9 bytes=6 sha256=975a4d12d983c511bdce58f3a220952527be885f475b8743a7c6fab63b7760de
004a12b9  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax

[G17] Literal use of 0xfdf3d4 VA=0x4b5aa5 raw=0xb4ea5 bytes=6 sha256=058e3e84620c9015080d6d3b28028f2dc0d296bb9de98f2b4bb09a644e6a3349
004b5aa5  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl

[G18] Literal use of 0xfdf3d4 VA=0x4b5aad raw=0xb4ead bytes=6 sha256=a85d663768f64f55c24f5e960247b04bc9fce86041b34328220bfcf0ca3c7bb5
004b5aad  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx

[G19] Literal use of 0xfdf3d4 VA=0x54e89b raw=0x14dc9b bytes=6 sha256=058e3e84620c9015080d6d3b28028f2dc0d296bb9de98f2b4bb09a644e6a3349
0054e89b  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl

[G20] Literal use of 0xfdf3d4 VA=0x54e8a3 raw=0x14dca3 bytes=6 sha256=a85d663768f64f55c24f5e960247b04bc9fce86041b34328220bfcf0ca3c7bb5
0054e8a3  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx

[G21] Literal use of 0xfdf3d4 VA=0x55e6d9 raw=0x15dad9 bytes=6 sha256=5cfbc35e0cd7d38a781f666c204a04e95b37de60f7e4190bfdb40e158db9ccba
0055e6d9  840dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,cl

[G22] Literal use of 0xfdf3d4 VA=0x55e6e1 raw=0x15dae1 bytes=6 sha256=f0e4500831cac3de920afe6da07d498f37975bf2e585ba3804ba1fd09268afca
0055e6e1  090dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ecx

[G23] Literal use of 0xfdf3d4 VA=0x55f044 raw=0x15e444 bytes=6 sha256=058e3e84620c9015080d6d3b28028f2dc0d296bb9de98f2b4bb09a644e6a3349
0055f044  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl

[G24] Literal use of 0xfdf3d4 VA=0x55f04c raw=0x15e44c bytes=6 sha256=a85d663768f64f55c24f5e960247b04bc9fce86041b34328220bfcf0ca3c7bb5
0055f04c  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx

[G25] Literal use of 0xfdf3d4 VA=0x561e06 raw=0x161206 bytes=6 sha256=058e3e84620c9015080d6d3b28028f2dc0d296bb9de98f2b4bb09a644e6a3349
00561e06  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl

[G26] Literal use of 0xfdf3d4 VA=0x561e0e raw=0x16120e bytes=6 sha256=a85d663768f64f55c24f5e960247b04bc9fce86041b34328220bfcf0ca3c7bb5
00561e0e  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx

[G27] Literal use of 0xfdf3d4 VA=0x561ff1 raw=0x1613f1 bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
00561ff1  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G28] Literal use of 0xfdf3d4 VA=0x561ffa raw=0x1613fa bytes=6 sha256=a85d663768f64f55c24f5e960247b04bc9fce86041b34328220bfcf0ca3c7bb5
00561ffa  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx

[G29] Literal use of 0xfdf3d4 VA=0x5b9708 raw=0x1b8b08 bytes=6 sha256=058e3e84620c9015080d6d3b28028f2dc0d296bb9de98f2b4bb09a644e6a3349
005b9708  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl

[G30] Literal use of 0xfdf3d4 VA=0x5b9710 raw=0x1b8b10 bytes=6 sha256=a85d663768f64f55c24f5e960247b04bc9fce86041b34328220bfcf0ca3c7bb5
005b9710  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx

[G31] Literal use of 0xfdf3d4 VA=0x5c3638 raw=0x1c2a38 bytes=6 sha256=058e3e84620c9015080d6d3b28028f2dc0d296bb9de98f2b4bb09a644e6a3349
005c3638  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl

[G32] Literal use of 0xfdf3d4 VA=0x5c3640 raw=0x1c2a40 bytes=6 sha256=a85d663768f64f55c24f5e960247b04bc9fce86041b34328220bfcf0ca3c7bb5
005c3640  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx

[G33] Literal use of 0xfdf3d4 VA=0x672fa7 raw=0x2723a7 bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
00672fa7  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G34] Literal use of 0xfdf3d4 VA=0x672fb5 raw=0x2723b5 bytes=6 sha256=975a4d12d983c511bdce58f3a220952527be885f475b8743a7c6fab63b7760de
00672fb5  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax

[G35] Literal use of 0xfdf3d4 VA=0x6bcee5 raw=0x2bc2e5 bytes=6 sha256=c781bb238fbf9632706f3d12638c7a77461562a57aa630eb96ac63f948cbfd92
006bcee5  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al

[G36] Literal use of 0xfdf3d4 VA=0x6bceed raw=0x2bc2ed bytes=6 sha256=975a4d12d983c511bdce58f3a220952527be885f475b8743a7c6fab63b7760de
006bceed  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax

[G37] Literal use of 0xfdf3d4 VA=0x6bcfc8 raw=0x2bc3c8 bytes=6 sha256=c781bb238fbf9632706f3d12638c7a77461562a57aa630eb96ac63f948cbfd92
006bcfc8  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al

[G38] Literal use of 0xfdf3d4 VA=0x6bcfd0 raw=0x2bc3d0 bytes=6 sha256=975a4d12d983c511bdce58f3a220952527be885f475b8743a7c6fab63b7760de
006bcfd0  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax

[G39] Literal use of 0xfdf3d4 VA=0x6bd780 raw=0x2bcb80 bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
006bd780  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G40] Literal use of 0xfdf3d4 VA=0x6bd78e raw=0x2bcb8e bytes=6 sha256=975a4d12d983c511bdce58f3a220952527be885f475b8743a7c6fab63b7760de
006bd78e  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax

[G41] Literal use of 0xfdf3d4 VA=0x6bf754 raw=0x2beb54 bytes=7 sha256=eabe52903bb6c201ccd7f7397cf3e96ea981aef9df9e61e2c9036bfcfef97cf1
006bf754  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1

[G42] Literal use of 0xfdf3d4 VA=0x6bf75d raw=0x2beb5d bytes=7 sha256=5f77ee5356044d08c08690bd0d560360b05d698640dbab90257d90a1bc57d03d
006bf75d  830dd4f3fd0001                    or     DWORD PTR ds:0xfdf3d4,0x1

[G43] Literal use of 0xfdf3d4 VA=0x93a5c0 raw=0x5399c0 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093a5c0  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G44] Literal use of 0xfdf3d4 VA=0x93a5c8 raw=0x5399c8 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093a5c8  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G45] Literal use of 0xfdf3d4 VA=0x93a72f raw=0x539b2f bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093a72f  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G46] Literal use of 0xfdf3d4 VA=0x93a737 raw=0x539b37 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093a737  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G47] Literal use of 0xfdf3d4 VA=0x93a76e raw=0x539b6e bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093a76e  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G48] Literal use of 0xfdf3d4 VA=0x93a776 raw=0x539b76 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093a776  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G49] Literal use of 0xfdf3d4 VA=0x93a7a8 raw=0x539ba8 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093a7a8  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G50] Literal use of 0xfdf3d4 VA=0x93a7b0 raw=0x539bb0 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093a7b0  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G51] Literal use of 0xfdf3d4 VA=0x93a837 raw=0x539c37 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093a837  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G52] Literal use of 0xfdf3d4 VA=0x93a83f raw=0x539c3f bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093a83f  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G53] Literal use of 0xfdf3d4 VA=0x93a886 raw=0x539c86 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093a886  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G54] Literal use of 0xfdf3d4 VA=0x93a88e raw=0x539c8e bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093a88e  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G55] Literal use of 0xfdf3d4 VA=0x93a8d7 raw=0x539cd7 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093a8d7  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G56] Literal use of 0xfdf3d4 VA=0x93a8df raw=0x539cdf bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093a8df  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G57] Literal use of 0xfdf3d4 VA=0x93a970 raw=0x539d70 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093a970  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G58] Literal use of 0xfdf3d4 VA=0x93a978 raw=0x539d78 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093a978  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G59] Literal use of 0xfdf3d4 VA=0x93beb2 raw=0x53b2b2 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093beb2  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G60] Literal use of 0xfdf3d4 VA=0x93beba raw=0x53b2ba bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093beba  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G61] Literal use of 0xfdf3d4 VA=0x93fc10 raw=0x53f010 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093fc10  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G62] Literal use of 0xfdf3d4 VA=0x93fc18 raw=0x53f018 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093fc18  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G63] Literal use of 0xfdf3d4 VA=0x93fc48 raw=0x53f048 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0093fc48  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G64] Literal use of 0xfdf3d4 VA=0x93fc50 raw=0x53f050 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
0093fc50  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G65] Literal use of 0xfdf3d4 VA=0x944eb0 raw=0x5442b0 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
00944eb0  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G66] Literal use of 0xfdf3d4 VA=0x944eb8 raw=0x5442b8 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
00944eb8  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G67] Literal use of 0xfdf3d4 VA=0x94608e raw=0x54548e bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
0094608e  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G68] Literal use of 0xfdf3d4 VA=0x946096 raw=0x545496 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
00946096  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G69] Literal use of 0xfdf3d4 VA=0x947350 raw=0x546750 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
00947350  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G70] Literal use of 0xfdf3d4 VA=0x947358 raw=0x546758 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
00947358  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G71] Literal use of 0xfdf3d4 VA=0x949aa2 raw=0x548ea2 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
00949aa2  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G72] Literal use of 0xfdf3d4 VA=0x949aaa raw=0x548eaa bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
00949aaa  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G73] Literal use of 0xfdf3d4 VA=0x949ab0 raw=0x548eb0 bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
00949ab0  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G74] Literal use of 0xfdf3d4 VA=0x949ab8 raw=0x548eb8 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
00949ab8  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G75] Literal use of 0xfdf3d4 VA=0x949d2e raw=0x54912e bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
00949d2e  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G76] Literal use of 0xfdf3d4 VA=0x949d36 raw=0x549136 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
00949d36  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[G77] Literal use of 0xfdf3d4 VA=0x949d4a raw=0x54914a bytes=5 sha256=4dbebd638957eed6cb8fed166dd10e39e3ec0d0127719b6ba04175b20f7f6caa
00949d4a  a1d4f3fd00                        mov    eax,ds:0xfdf3d4

[G78] Literal use of 0xfdf3d4 VA=0x949d52 raw=0x549152 bytes=5 sha256=7ff9f836e63f586b5ea322fb24e6052c0905b7917c3bf7691e8c925d6eeec4f5
00949d52  a3d4f3fd00                        mov    ds:0xfdf3d4,eax

[L01] Literal use of 0xfe1eec VA=0x55c5ee raw=0x15b9ee bytes=5 sha256=911bf06b9b2d343d5c05dddb968720026119ddadea8e4112ba3c340dfa2f2d46
0055c5ee  b8ec1efe00                        mov    eax,0xfe1eec

[L02] Literal use of 0xfe1eec VA=0x55c63a raw=0x15ba3a bytes=7 sha256=1aadef1057300a77c76edce36d34bb7a24e7c49eacd605cc07c20e3fce87116e
0055c63a  c745ecec1efe00                    mov    DWORD PTR [ebp-0x14],0xfe1eec

[L03] Literal use of 0xfe1eec VA=0x55c6b3 raw=0x15bab3 bytes=5 sha256=906ab52e350d9d5d14f36afdbd96d6545425ab27b9da175a053357afc754cebd
0055c6b3  a3ec1efe00                        mov    ds:0xfe1eec,eax

[L04] Literal use of 0xfe1eec VA=0x55c6c4 raw=0x15bac4 bytes=6 sha256=63819bfe415bf7c7c038a60719e5abbcb7a3b80ff0b0770e669149099b6ff5a9
0055c6c4  8b15ec1efe00                      mov    edx,DWORD PTR ds:0xfe1eec

[L05] Literal use of 0xfe1eec VA=0x55c6e0 raw=0x15bae0 bytes=5 sha256=911bf06b9b2d343d5c05dddb968720026119ddadea8e4112ba3c340dfa2f2d46
0055c6e0  b8ec1efe00                        mov    eax,0xfe1eec

[L06] Literal use of 0xfe1eec VA=0x55c746 raw=0x15bb46 bytes=7 sha256=1d0434ec0684520a45d39358ab8f752e072812b22fe42bfbbeddf847569e762f
0055c746  c745f0ec1efe00                    mov    DWORD PTR [ebp-0x10],0xfe1eec

[L07] Literal use of 0xfe1eec VA=0x55c78c raw=0x15bb8c bytes=5 sha256=63f49c69587c6d6cdd5a3d030a73c435114bc660d2b6ca044640bac7f244d186
0055c78c  a1ec1efe00                        mov    eax,ds:0xfe1eec

[L08] Literal use of 0xfe1eec VA=0x55cc96 raw=0x15c096 bytes=5 sha256=aca63727e131f21bab586da450084ae8c1bfb14924f35c96370a2e7aafc5c8c1
0055cc96  68ec1efe00                        push   0xfe1eec

[L09] Literal use of 0xfe1eec VA=0x55e428 raw=0x15d828 bytes=10 sha256=0c8178f2f89e5d21c1f6f184a80cd97332b7fee0ee6860266143f570f6f9f604
0055e428  c705241ffe00ec1efe00              mov    DWORD PTR ds:0xfe1f24,0xfe1eec

[L10] Literal use of 0xfe1eec VA=0x562639 raw=0x161a39 bytes=5 sha256=aca63727e131f21bab586da450084ae8c1bfb14924f35c96370a2e7aafc5c8c1
00562639  68ec1efe00                        push   0xfe1eec

[L11] Literal use of 0xfe1eec VA=0x5659b6 raw=0x164db6 bytes=5 sha256=aca63727e131f21bab586da450084ae8c1bfb14924f35c96370a2e7aafc5c8c1
005659b6  68ec1efe00                        push   0xfe1eec

[H01] Literal use of 0xfe1ee8 VA=0x55c5c7 raw=0x15b9c7 bytes=6 sha256=8f6c9334ab47e9bc4a1612cd52b07b922874f7defd28d9657fd3af0fd5d07481
0055c5c7  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al

[H02] Literal use of 0xfe1ee8 VA=0x55c5cf raw=0x15b9cf bytes=6 sha256=74dae1fef8f4915626e96b818d4ef671d775a6c612355f7bc84a7ab6f558c175
0055c5cf  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax

[H03] Literal use of 0xfe1ee8 VA=0x55cc57 raw=0x15c057 bytes=6 sha256=8f6c9334ab47e9bc4a1612cd52b07b922874f7defd28d9657fd3af0fd5d07481
0055cc57  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al

[H04] Literal use of 0xfe1ee8 VA=0x55cc5f raw=0x15c05f bytes=6 sha256=74dae1fef8f4915626e96b818d4ef671d775a6c612355f7bc84a7ab6f558c175
0055cc5f  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax

[H05] Literal use of 0xfe1ee8 VA=0x55ce19 raw=0x15c219 bytes=6 sha256=8f6c9334ab47e9bc4a1612cd52b07b922874f7defd28d9657fd3af0fd5d07481
0055ce19  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al

[H06] Literal use of 0xfe1ee8 VA=0x55ce21 raw=0x15c221 bytes=6 sha256=74dae1fef8f4915626e96b818d4ef671d775a6c612355f7bc84a7ab6f558c175
0055ce21  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax

[H07] Literal use of 0xfe1ee8 VA=0x55d14d raw=0x15c54d bytes=6 sha256=8f6c9334ab47e9bc4a1612cd52b07b922874f7defd28d9657fd3af0fd5d07481
0055d14d  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al

[H08] Literal use of 0xfe1ee8 VA=0x55d155 raw=0x15c555 bytes=6 sha256=74dae1fef8f4915626e96b818d4ef671d775a6c612355f7bc84a7ab6f558c175
0055d155  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax

[H09] Literal use of 0xfe1ee8 VA=0x55d499 raw=0x15c899 bytes=6 sha256=2e33e22485b6d9191d97053cb859cd2800148d29ac5e6807cd8a789229a21d67
0055d499  841de81efe00                      test   BYTE PTR ds:0xfe1ee8,bl

[H10] Literal use of 0xfe1ee8 VA=0x55d4a1 raw=0x15c8a1 bytes=6 sha256=d3333067c375b86b24f9948d227b6c4ac8a1d36d735cca90df70da0ba74e9b2a
0055d4a1  091de81efe00                      or     DWORD PTR ds:0xfe1ee8,ebx

[H11] Literal use of 0xfe1ee8 VA=0x55d641 raw=0x15ca41 bytes=6 sha256=8f6c9334ab47e9bc4a1612cd52b07b922874f7defd28d9657fd3af0fd5d07481
0055d641  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al

[H12] Literal use of 0xfe1ee8 VA=0x55d649 raw=0x15ca49 bytes=6 sha256=74dae1fef8f4915626e96b818d4ef671d775a6c612355f7bc84a7ab6f558c175
0055d649  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax

[H13] Literal use of 0xfe1ee8 VA=0x56260b raw=0x161a0b bytes=7 sha256=43bd0c9057f14438dac79162c9440f1a43f3ecf9e3331a79cad205162411dc39
0056260b  f605e81efe0001                    test   BYTE PTR ds:0xfe1ee8,0x1

[H14] Literal use of 0xfe1ee8 VA=0x562614 raw=0x161a14 bytes=7 sha256=90ee4086cb29f8e345226bdbea45618e2237a91be5d37b0787c7312aa57d86c5
00562614  830de81efe0001                    or     DWORD PTR ds:0xfe1ee8,0x1

[H15] Literal use of 0xfe1ee8 VA=0x56598a raw=0x164d8a bytes=7 sha256=43bd0c9057f14438dac79162c9440f1a43f3ecf9e3331a79cad205162411dc39
0056598a  f605e81efe0001                    test   BYTE PTR ds:0xfe1ee8,0x1

[H16] Literal use of 0xfe1ee8 VA=0x565993 raw=0x164d93 bytes=7 sha256=90ee4086cb29f8e345226bdbea45618e2237a91be5d37b0787c7312aa57d86c5
00565993  830de81efe0001                    or     DWORD PTR ds:0xfe1ee8,0x1

[H17] Literal use of 0xfe1ee8 VA=0x9389d0 raw=0x537dd0 bytes=5 sha256=7b212ba5008c39c3e5ff8d48e0852a3199df52febc7f3ec011a243eef8e7aacc
009389d0  a1e81efe00                        mov    eax,ds:0xfe1ee8

[H18] Literal use of 0xfe1ee8 VA=0x9389d8 raw=0x537dd8 bytes=5 sha256=36a1090add504eaeafb728f9898fba22898c220a6ea7af4b33333e261827d3ae
009389d8  a3e81efe00                        mov    ds:0xfe1ee8,eax

[H19] Literal use of 0xfe1ee8 VA=0x938cd0 raw=0x5380d0 bytes=5 sha256=7b212ba5008c39c3e5ff8d48e0852a3199df52febc7f3ec011a243eef8e7aacc
00938cd0  a1e81efe00                        mov    eax,ds:0xfe1ee8

[H20] Literal use of 0xfe1ee8 VA=0x938cd8 raw=0x5380d8 bytes=5 sha256=36a1090add504eaeafb728f9898fba22898c220a6ea7af4b33333e261827d3ae
00938cd8  a3e81efe00                        mov    ds:0xfe1ee8,eax

[H21] Literal use of 0xfe1ee8 VA=0x938d00 raw=0x538100 bytes=5 sha256=7b212ba5008c39c3e5ff8d48e0852a3199df52febc7f3ec011a243eef8e7aacc
00938d00  a1e81efe00                        mov    eax,ds:0xfe1ee8

[H22] Literal use of 0xfe1ee8 VA=0x938d08 raw=0x538108 bytes=5 sha256=36a1090add504eaeafb728f9898fba22898c220a6ea7af4b33333e261827d3ae
00938d08  a3e81efe00                        mov    ds:0xfe1ee8,eax

[H23] Literal use of 0xfe1ee8 VA=0x938d30 raw=0x538130 bytes=5 sha256=7b212ba5008c39c3e5ff8d48e0852a3199df52febc7f3ec011a243eef8e7aacc
00938d30  a1e81efe00                        mov    eax,ds:0xfe1ee8

[H24] Literal use of 0xfe1ee8 VA=0x938d38 raw=0x538138 bytes=5 sha256=36a1090add504eaeafb728f9898fba22898c220a6ea7af4b33333e261827d3ae
00938d38  a3e81efe00                        mov    ds:0xfe1ee8,eax

[H25] Literal use of 0xfe1ee8 VA=0x938d60 raw=0x538160 bytes=5 sha256=7b212ba5008c39c3e5ff8d48e0852a3199df52febc7f3ec011a243eef8e7aacc
00938d60  a1e81efe00                        mov    eax,ds:0xfe1ee8

[H26] Literal use of 0xfe1ee8 VA=0x938d68 raw=0x538168 bytes=5 sha256=36a1090add504eaeafb728f9898fba22898c220a6ea7af4b33333e261827d3ae
00938d68  a3e81efe00                        mov    ds:0xfe1ee8,eax

[H27] Literal use of 0xfe1ee8 VA=0x93fbbe raw=0x53efbe bytes=5 sha256=7b212ba5008c39c3e5ff8d48e0852a3199df52febc7f3ec011a243eef8e7aacc
0093fbbe  a1e81efe00                        mov    eax,ds:0xfe1ee8

[H28] Literal use of 0xfe1ee8 VA=0x93fbc6 raw=0x53efc6 bytes=5 sha256=36a1090add504eaeafb728f9898fba22898c220a6ea7af4b33333e261827d3ae
0093fbc6  a3e81efe00                        mov    ds:0xfe1ee8,eax

[H29] Literal use of 0xfe1ee8 VA=0x943cda raw=0x5430da bytes=5 sha256=7b212ba5008c39c3e5ff8d48e0852a3199df52febc7f3ec011a243eef8e7aacc
00943cda  a1e81efe00                        mov    eax,ds:0xfe1ee8

[H30] Literal use of 0xfe1ee8 VA=0x943ce2 raw=0x5430e2 bytes=5 sha256=36a1090add504eaeafb728f9898fba22898c220a6ea7af4b33333e261827d3ae
00943ce2  a3e81efe00                        mov    ds:0xfe1ee8,eax

[F01] Guarded constructor then atexit registration VA=0x48b0aa raw=0x8a4aa bytes=98 sha256=33d26d859ac6cc5b48128ffa7286be0b25971cf02542bd625667cb138829d73d
0048b0aa  7408                              je     0x48b0b4
0048b0ac  50                                push   eax
0048b0ad  e85eae2400                        call   0x6d5f10
0048b0b2  eb02                              jmp    0x48b0b6
0048b0b4  33c0                              xor    eax,eax
0048b0b6  c645fc0b                          mov    BYTE PTR [ebp-0x4],0xb
0048b0ba  6a28                              push   0x28
0048b0bc  8987e4bf0000                      mov    DWORD PTR [edi+0xbfe4],eax
0048b0c2  e8a1614000                        call   0x891268
0048b0c7  83c404                            add    esp,0x4
0048b0ca  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0048b0cd  c645fc17                          mov    BYTE PTR [ebp-0x4],0x17
0048b0d1  3bc3                              cmp    eax,ebx
0048b0d3  7408                              je     0x48b0dd
0048b0d5  50                                push   eax
0048b0d6  e8f5b90700                        call   0x506ad0
0048b0db  eb02                              jmp    0x48b0df
0048b0dd  33c0                              xor    eax,eax
0048b0df  c645fc0b                          mov    BYTE PTR [ebp-0x4],0xb
0048b0e3  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
0048b0ea  89875cbf0000                      mov    DWORD PTR [edi+0xbf5c],eax
0048b0f0  7521                              jne    0x48b113
0048b0f2  830dd4f3fd0001                    or     DWORD PTR ds:0xfdf3d4,0x1
0048b0f9  c645fc18                          mov    BYTE PTR [ebp-0x4],0x18
0048b0fd  e87e922600                        call   0x6f4380
0048b102  68d0e6bc00                        push   0xbce6d0
0048b107  e80e724000                        call   0x89231a

[F02] Guarded constructor then atexit registration VA=0x48c987 raw=0x8bd87 bytes=121 sha256=73851f95070298721f9caa7407f053878df4e2ffb387be7bcb9ab8999e8f9736
0048c987  e8c42e0c00                        call   0x54f850
0048c98c  6880d5bc00                        push   0xbcd580
0048c991  e884594000                        call   0x89231a
0048c996  83c404                            add    esp,0x4
0048c999  895c2470                          mov    DWORD PTR [esp+0x70],ebx
0048c99d  8b0dc490fb00                      mov    ecx,DWORD PTR ds:0xfb90c4
0048c9a3  8b06                              mov    eax,DWORD PTR [esi]
0048c9a5  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0048c9a8  51                                push   ecx
0048c9a9  8bce                              mov    ecx,esi
0048c9ab  ffd2                              call   edx
0048c9ad  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0048c9b4  7524                              jne    0x48c9da
0048c9b6  093de879fb00                      or     DWORD PTR ds:0xfb79e8,edi
0048c9bc  c744247006000000                  mov    DWORD PTR [esp+0x70],0x6
0048c9c4  e817c43000                        call   0x798de0
0048c9c9  68e0d2bc00                        push   0xbcd2e0
0048c9ce  e847594000                        call   0x89231a
0048c9d3  83c404                            add    esp,0x4
0048c9d6  895c2470                          mov    DWORD PTR [esp+0x70],ebx
0048c9da  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
0048c9e1  7524                              jne    0x48ca07
0048c9e3  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi
0048c9e9  c744247007000000                  mov    DWORD PTR [esp+0x70],0x7
0048c9f1  e88a792600                        call   0x6f4380
0048c9f6  68d0e6bc00                        push   0xbce6d0
0048c9fb  e81a594000                        call   0x89231a

[F03] Guarded constructor then atexit registration VA=0x48c9b4 raw=0x8bdb4 bytes=136 sha256=24f07f704d62421d9c759dfdcc652c9cfef0d0126aa28c947549d8111f429ca2
0048c9b4  7524                              jne    0x48c9da
0048c9b6  093de879fb00                      or     DWORD PTR ds:0xfb79e8,edi
0048c9bc  c744247006000000                  mov    DWORD PTR [esp+0x70],0x6
0048c9c4  e817c43000                        call   0x798de0
0048c9c9  68e0d2bc00                        push   0xbcd2e0
0048c9ce  e847594000                        call   0x89231a
0048c9d3  83c404                            add    esp,0x4
0048c9d6  895c2470                          mov    DWORD PTR [esp+0x70],ebx
0048c9da  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
0048c9e1  7524                              jne    0x48ca07
0048c9e3  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi
0048c9e9  c744247007000000                  mov    DWORD PTR [esp+0x70],0x7
0048c9f1  e88a792600                        call   0x6f4380
0048c9f6  68d0e6bc00                        push   0xbce6d0
0048c9fb  e81a594000                        call   0x89231a
0048ca00  83c404                            add    esp,0x4
0048ca03  895c2470                          mov    DWORD PTR [esp+0x70],ebx
0048ca07  684c57c000                        push   0xc0574c
0048ca0c  b9c8f3fd00                        mov    ecx,0xfdf3c8
0048ca11  e83a802600                        call   0x6f4a50
0048ca16  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
0048ca1d  7524                              jne    0x48ca43
0048ca1f  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi
0048ca25  c744247008000000                  mov    DWORD PTR [esp+0x70],0x8
0048ca2d  e84e792600                        call   0x6f4380
0048ca32  68d0e6bc00                        push   0xbce6d0
0048ca37  e8de584000                        call   0x89231a

[F04] Guarded constructor then atexit registration VA=0x48d6a9 raw=0x8caa9 bytes=142 sha256=54571e11421d9fe315993b28274f89aac0a690fa72bf02fa2c93dc68f54f524e
0048d6a9  897824                            mov    DWORD PTR [eax+0x24],edi
0048d6ac  7524                              jne    0x48d6d2
0048d6ae  093df41bfc00                      or     DWORD PTR ds:0xfc1bf4,edi
0048d6b4  c744247035000000                  mov    DWORD PTR [esp+0x70],0x35
0048d6bc  e8cf180f00                        call   0x57ef90
0048d6c1  68b0dfbc00                        push   0xbcdfb0
0048d6c6  e84f4c4000                        call   0x89231a
0048d6cb  83c404                            add    esp,0x4
0048d6ce  895c2470                          mov    DWORD PTR [esp+0x70],ebx
0048d6d2  68f81bfc00                        push   0xfc1bf8
0048d6d7  e8b41c0f00                        call   0x57f390
0048d6dc  f605f02cfd0001                    test   BYTE PTR ds:0xfd2cf0,0x1
0048d6e3  7518                              jne    0x48d6fd
0048d6e5  093df02cfd00                      or     DWORD PTR ds:0xfd2cf0,edi
0048d6eb  e8a0a92a00                        call   0x738090
0048d6f0  6880e6bc00                        push   0xbce680
0048d6f5  e8204c4000                        call   0x89231a
0048d6fa  83c404                            add    esp,0x4
0048d6fd  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
0048d704  c705bc2bfd0008000000              mov    DWORD PTR ds:0xfd2bbc,0x8
0048d70e  c705c02bfd0078000000              mov    DWORD PTR ds:0xfd2bc0,0x78
0048d718  7524                              jne    0x48d73e
0048d71a  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi
0048d720  c744247036000000                  mov    DWORD PTR [esp+0x70],0x36
0048d728  e8536c2600                        call   0x6f4380
0048d72d  68d0e6bc00                        push   0xbce6d0
0048d732  e8e34b4000                        call   0x89231a

[F05] Guarded constructor then atexit registration VA=0x48d718 raw=0x8cb18 bytes=136 sha256=2b8a3d93c95e4847e5b2051785fdb69ec9aadd57c9a82277a138df7b391d4a92
0048d718  7524                              jne    0x48d73e
0048d71a  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi
0048d720  c744247036000000                  mov    DWORD PTR [esp+0x70],0x36
0048d728  e8536c2600                        call   0x6f4380
0048d72d  68d0e6bc00                        push   0xbce6d0
0048d732  e8e34b4000                        call   0x89231a
0048d737  83c404                            add    esp,0x4
0048d73a  895c2470                          mov    DWORD PTR [esp+0x70],ebx
0048d73e  f605b873fb0001                    test   BYTE PTR ds:0xfb73b8,0x1
0048d745  7524                              jne    0x48d76b
0048d747  093db873fb00                      or     DWORD PTR ds:0xfb73b8,edi
0048d74d  c744247037000000                  mov    DWORD PTR [esp+0x70],0x37
0048d755  e8162a0d00                        call   0x560170
0048d75a  6810d1bc00                        push   0xbcd110
0048d75f  e8b64b4000                        call   0x89231a
0048d764  83c404                            add    esp,0x4
0048d767  895c2470                          mov    DWORD PTR [esp+0x70],ebx
0048d76b  bec8f3fd00                        mov    esi,0xfdf3c8
0048d770  b8c073fb00                        mov    eax,0xfb73c0
0048d775  e8862e0d00                        call   0x560600
0048d77a  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
0048d781  7524                              jne    0x48d7a7
0048d783  093dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,edi
0048d789  c744247038000000                  mov    DWORD PTR [esp+0x70],0x38
0048d791  e8ea6b2600                        call   0x6f4380
0048d796  68d0e6bc00                        push   0xbce6d0
0048d79b  e87a4b4000                        call   0x89231a

[F06] Guarded constructor then atexit registration VA=0x49b230 raw=0x9a630 bytes=75 sha256=9261229320f87ff926e0e3ff266c1e43b591204f6fabd15247c129d0d25de31d
0049b230  55                                push   ebp
0049b231  8bec                              mov    ebp,esp
0049b233  6aff                              push   0xffffffff
0049b235  68cea59300                        push   0x93a5ce
0049b23a  64a100000000                      mov    eax,fs:0x0
0049b240  50                                push   eax
0049b241  a1201fd600                        mov    eax,ds:0xd61f20
0049b246  33c5                              xor    eax,ebp
0049b248  50                                push   eax
0049b249  8d45f4                            lea    eax,[ebp-0xc]
0049b24c  64a300000000                      mov    fs:0x0,eax
0049b252  b801000000                        mov    eax,0x1
0049b257  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al
0049b25d  751f                              jne    0x49b27e
0049b25f  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax
0049b265  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0049b26c  e80f912500                        call   0x6f4380
0049b271  68d0e6bc00                        push   0xbce6d0
0049b276  e89f703f00                        call   0x89231a

[F07] Guarded constructor then atexit registration VA=0x4a0950 raw=0x9fd50 bytes=78 sha256=248d75f37cc019b5475f6b4a1d43e95d36cd2a66db03bf65d0ab502970afff90
004a0950  55                                push   ebp
004a0951  8bec                              mov    ebp,esp
004a0953  6aff                              push   0xffffffff
004a0955  68be4e9400                        push   0x944ebe
004a095a  64a100000000                      mov    eax,fs:0x0
004a0960  50                                push   eax
004a0961  83ec08                            sub    esp,0x8
004a0964  a1201fd600                        mov    eax,ds:0xd61f20
004a0969  33c5                              xor    eax,ebp
004a096b  50                                push   eax
004a096c  8d45f4                            lea    eax,[ebp-0xc]
004a096f  64a300000000                      mov    fs:0x0,eax
004a0975  b801000000                        mov    eax,0x1
004a097a  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al
004a0980  7526                              jne    0x4a09a8
004a0982  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax
004a0988  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
004a098f  e8ec392500                        call   0x6f4380
004a0994  68d0e6bc00                        push   0xbce6d0
004a0999  e87c193f00                        call   0x89231a

[F08] Guarded constructor then atexit registration VA=0x4a127e raw=0xa067e bytes=87 sha256=7894996d68a97a46fc6b5e765189ad453a346064b24567f9ce5097b7024710d2
004a127e  51                                push   ecx
004a127f  e8b9c93d00                        call   0x87dc3d
004a1284  8b16                              mov    edx,DWORD PTR [esi]
004a1286  83c404                            add    esp,0x4
004a1289  8bd8                              mov    ebx,eax
004a128b  8b4238                            mov    eax,DWORD PTR [edx+0x38]
004a128e  57                                push   edi
004a128f  8bce                              mov    ecx,esi
004a1291  ffd0                              call   eax
004a1293  50                                push   eax
004a1294  53                                push   ebx
004a1295  e836c93f00                        call   0x89dbd0
004a129a  c6041f00                          mov    BYTE PTR [edi+ebx*1],0x0
004a129e  8b16                              mov    edx,DWORD PTR [esi]
004a12a0  8b422c                            mov    eax,DWORD PTR [edx+0x2c]
004a12a3  83c40c                            add    esp,0xc
004a12a6  8bce                              mov    ecx,esi
004a12a8  ffd0                              call   eax
004a12aa  8bf8                              mov    edi,eax
004a12ac  b801000000                        mov    eax,0x1
004a12b1  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al
004a12b7  7526                              jne    0x4a12df
004a12b9  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax
004a12bf  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
004a12c6  e8b5302500                        call   0x6f4380
004a12cb  68d0e6bc00                        push   0xbce6d0
004a12d0  e845103f00                        call   0x89231a

[F09] Guarded constructor then atexit registration VA=0x4b5a4f raw=0xb4e4f bytes=123 sha256=be4ccb41c829d01de5a7f2e9da598c9a149b419b18dc647d7de6d2bd7457868c
004b5a4f  56                                push   esi
004b5a50  50                                push   eax
004b5a51  e86a9b0b00                        call   0x56f5c0
004b5a56  0fb7b788000000                    movzx  esi,WORD PTR [edi+0x88]
004b5a5d  841da472fb00                      test   BYTE PTR ds:0xfb72a4,bl
004b5a63  7528                              jne    0x4b5a8d
004b5a65  091da472fb00                      or     DWORD PTR ds:0xfb72a4,ebx
004b5a6b  c744246802000000                  mov    DWORD PTR [esp+0x68],0x2
004b5a73  e8d89dfeff                        call   0x49f850
004b5a78  68e0cfbc00                        push   0xbccfe0
004b5a7d  e898c83d00                        call   0x89231a
004b5a82  83c404                            add    esp,0x4
004b5a85  c7442468ffffffff                  mov    DWORD PTR [esp+0x68],0xffffffff
004b5a8d  8b442414                          mov    eax,DWORD PTR [esp+0x14]
004b5a91  0fb64806                          movzx  ecx,BYTE PTR [eax+0x6]
004b5a95  51                                push   ecx
004b5a96  8b4802                            mov    ecx,DWORD PTR [eax+0x2]
004b5a99  8bd6                              mov    edx,esi
004b5a9b  68a872fb00                        push   0xfb72a8
004b5aa0  e80babfeff                        call   0x4a05b0
004b5aa5  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl
004b5aab  7528                              jne    0x4b5ad5
004b5aad  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
004b5ab3  c744246803000000                  mov    DWORD PTR [esp+0x68],0x3
004b5abb  e8c0e82300                        call   0x6f4380
004b5ac0  68d0e6bc00                        push   0xbce6d0
004b5ac5  e850c83d00                        call   0x89231a

[F10] Guarded constructor then atexit registration VA=0x54e809 raw=0x14dc09 bytes=179 sha256=7377d7159b4c4a0315ce2912676eefc1db6557027110293c7f779b519d62a7b1
0054e809  f30f11057876fb00                  movss  DWORD PTR ds:0xfb7678,xmm0
0054e811  f30f11057c76fb00                  movss  DWORD PTR ds:0xfb767c,xmm0
0054e819  f30f11058076fb00                  movss  DWORD PTR ds:0xfb7680,xmm0
0054e821  f30f11058876fb00                  movss  DWORD PTR ds:0xfb7688,xmm0
0054e829  f30f11058c76fb00                  movss  DWORD PTR ds:0xfb768c,xmm0
0054e831  f30f11059076fb00                  movss  DWORD PTR ds:0xfb7690,xmm0
0054e839  f30f11059476fb00                  movss  DWORD PTR ds:0xfb7694,xmm0
0054e841  f30f1005c056c400                  movss  xmm0,DWORD PTR ds:0xc456c0
0054e849  f30f11059876fb00                  movss  DWORD PTR ds:0xfb7698,xmm0
0054e851  f30f10053458c500                  movss  xmm0,DWORD PTR ds:0xc55834
0054e859  f30f11059c76fb00                  movss  DWORD PTR ds:0xfb769c,xmm0
0054e861  f30f10053058c500                  movss  xmm0,DWORD PTR ds:0xc55830
0054e869  bb01000000                        mov    ebx,0x1
0054e86e  c7056c76fb0048fdc000              mov    DWORD PTR ds:0xfb766c,0xc0fd48
0054e878  a37076fb00                        mov    ds:0xfb7670,eax
0054e87d  a37476fb00                        mov    ds:0xfb7674,eax
0054e882  f30f110d8476fb00                  movss  DWORD PTR ds:0xfb7684,xmm1
0054e88a  f30f1105a076fb00                  movss  DWORD PTR ds:0xfb76a0,xmm0
0054e892  891da476fb00                      mov    DWORD PTR ds:0xfb76a4,ebx
0054e898  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0054e89b  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl
0054e8a1  751f                              jne    0x54e8c2
0054e8a3  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
0054e8a9  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0054e8ad  e8ce5a1a00                        call   0x6f4380
0054e8b2  68d0e6bc00                        push   0xbce6d0
0054e8b7  e85e3a3400                        call   0x89231a

[F11] Guarded constructor then atexit registration VA=0x55e681 raw=0x15da81 bytes=120 sha256=102c7d9f207aa556a8102df7a6a58f24045f027cb65b71136cb53d586a56a793
0055e681  8bec                              mov    ebp,esp
0055e683  6aff                              push   0xffffffff
0055e685  68be4e9400                        push   0x944ebe
0055e68a  64a100000000                      mov    eax,fs:0x0
0055e690  50                                push   eax
0055e691  83ec08                            sub    esp,0x8
0055e694  a1201fd600                        mov    eax,ds:0xd61f20
0055e699  33c5                              xor    eax,ebp
0055e69b  50                                push   eax
0055e69c  8d45f4                            lea    eax,[ebp-0xc]
0055e69f  64a300000000                      mov    fs:0x0,eax
0055e6a5  33c0                              xor    eax,eax
0055e6a7  b901000000                        mov    ecx,0x1
0055e6ac  c7054827fe0000040000              mov    DWORD PTR ds:0xfe2748,0x400
0055e6b6  c7054c27fe0000030000              mov    DWORD PTR ds:0xfe274c,0x300
0055e6c0  a35027fe00                        mov    ds:0xfe2750,eax
0055e6c5  a35427fe00                        mov    ds:0xfe2754,eax
0055e6ca  a35827fe00                        mov    ds:0xfe2758,eax
0055e6cf  a35c27fe00                        mov    ds:0xfe275c,eax
0055e6d4  a36027fe00                        mov    ds:0xfe2760,eax
0055e6d9  840dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,cl
0055e6df  7522                              jne    0x55e703
0055e6e1  090dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ecx
0055e6e7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0055e6ea  e8915c1900                        call   0x6f4380
0055e6ef  68d0e6bc00                        push   0xbce6d0
0055e6f4  e8213c3300                        call   0x89231a

[F12] Guarded constructor then atexit registration VA=0x55f000 raw=0x15e400 bytes=101 sha256=f456ac6637ae531eb56b607e71aed99d609f0ab94daff98f97a2b6a877bee435
0055f000  c745e41a000000                    mov    DWORD PTR [ebp-0x1c],0x1a
0055f007  c745e804000000                    mov    DWORD PTR [ebp-0x18],0x4
0055f00e  895dec                            mov    DWORD PTR [ebp-0x14],ebx
0055f011  e8373e3300                        call   0x892e4d
0055f016  83c40c                            add    esp,0xc
0055f019  6a50                              push   0x50
0055f01b  e848223300                        call   0x891268
0055f020  83c404                            add    esp,0x4
0055f023  89459c                            mov    DWORD PTR [ebp-0x64],eax
0055f026  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0055f02a  3bc6                              cmp    eax,esi
0055f02c  740c                              je     0x55f03a
0055f02e  8d4da0                            lea    ecx,[ebp-0x60]
0055f031  51                                push   ecx
0055f032  50                                push   eax
0055f033  e838d50000                        call   0x56c570
0055f038  eb02                              jmp    0x55f03c
0055f03a  33c0                              xor    eax,eax
0055f03c  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0055f03f  a31c1bfc00                        mov    ds:0xfc1b1c,eax
0055f044  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl
0055f04a  751f                              jne    0x55f06b
0055f04c  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
0055f052  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0055f056  e825531900                        call   0x6f4380
0055f05b  68d0e6bc00                        push   0xbce6d0
0055f060  e8b5323300                        call   0x89231a

[F13] Guarded constructor then atexit registration VA=0x561dc3 raw=0x1611c3 bytes=100 sha256=fb85b17a33fc0c7d2fad2eef660cfd1a30f9e6035d958ec613906201f0f04394
00561dc3  50                                push   eax
00561dc4  83ec10                            sub    esp,0x10
00561dc7  53                                push   ebx
00561dc8  56                                push   esi
00561dc9  57                                push   edi
00561dca  a1201fd600                        mov    eax,ds:0xd61f20
00561dcf  33c4                              xor    eax,esp
00561dd1  50                                push   eax
00561dd2  8d442420                          lea    eax,[esp+0x20]
00561dd6  64a300000000                      mov    fs:0x0,eax
00561ddc  8bf9                              mov    edi,ecx
00561dde  33f6                              xor    esi,esi
00561de0  80bf8900000000                    cmp    BYTE PTR [edi+0x89],0x0
00561de7  0f8473010000                      je     0x561f60
00561ded  397728                            cmp    DWORD PTR [edi+0x28],esi
00561df0  0f84aa000000                      je     0x561ea0
00561df6  897728                            mov    DWORD PTR [edi+0x28],esi
00561df9  e85224edff                        call   0x434250
00561dfe  bb01000000                        mov    ebx,0x1
00561e03  895814                            mov    DWORD PTR [eax+0x14],ebx
00561e06  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl
00561e0c  7525                              jne    0x561e33
00561e0e  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
00561e14  89742428                          mov    DWORD PTR [esp+0x28],esi
00561e18  e863251900                        call   0x6f4380
00561e1d  68d0e6bc00                        push   0xbce6d0
00561e22  e8f3043300                        call   0x89231a

[F14] Guarded constructor then atexit registration VA=0x561fb5 raw=0x1613b5 bytes=98 sha256=783196c47137095e0a879788c5132c6a74e0cc1b9cda93db106439887ee4286b
00561fb5  eb3a                              jmp    0x561ff1
00561fb7  8d5f3c                            lea    ebx,[edi+0x3c]
00561fba  8d7774                            lea    esi,[edi+0x74]
00561fbd  53                                push   ebx
00561fbe  e87dbe1500                        call   0x6bde40
00561fc3  50                                push   eax
00561fc4  56                                push   esi
00561fc5  8d74241c                          lea    esi,[esp+0x1c]
00561fc9  e8c248edff                        call   0x436890
00561fce  57                                push   edi
00561fcf  e8cc030000                        call   0x5623a0
00561fd4  e8a726ebff                        call   0x414680
00561fd9  8b03                              mov    eax,DWORD PTR [ebx]
00561fdb  8b4f38                            mov    ecx,DWORD PTR [edi+0x38]
00561fde  50                                push   eax
00561fdf  51                                push   ecx
00561fe0  e8bb19f4ff                        call   0x4a39a0
00561fe5  e8c6000000                        call   0x5620b0
00561fea  bb01000000                        mov    ebx,0x1
00561fef  33f6                              xor    esi,esi
00561ff1  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
00561ff8  7528                              jne    0x562022
00561ffa  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
00562000  c744242804000000                  mov    DWORD PTR [esp+0x28],0x4
00562008  e873231900                        call   0x6f4380
0056200d  68d0e6bc00                        push   0xbce6d0
00562012  e803033300                        call   0x89231a

[F15] Guarded constructor then atexit registration VA=0x5b96e0 raw=0x1b8ae0 bytes=76 sha256=d254e399070f3b81ef68f15863cca4899548542f1f6beb338b59cfdf0e3fca0d
005b96e0  55                                push   ebp
005b96e1  8bec                              mov    ebp,esp
005b96e3  6aff                              push   0xffffffff
005b96e5  686c739400                        push   0x94736c
005b96ea  64a100000000                      mov    eax,fs:0x0
005b96f0  50                                push   eax
005b96f1  53                                push   ebx
005b96f2  a1201fd600                        mov    eax,ds:0xd61f20
005b96f7  33c5                              xor    eax,ebp
005b96f9  50                                push   eax
005b96fa  8d45f4                            lea    eax,[ebp-0xc]
005b96fd  64a300000000                      mov    fs:0x0,eax
005b9703  bb01000000                        mov    ebx,0x1
005b9708  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl
005b970e  7526                              jne    0x5b9736
005b9710  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
005b9716  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
005b971d  e85eac1300                        call   0x6f4380
005b9722  68d0e6bc00                        push   0xbce6d0
005b9727  e8ee8b2d00                        call   0x89231a

[F16] Guarded constructor then atexit registration VA=0x5c3610 raw=0x1c2a10 bytes=76 sha256=fbbaa2e9944dbdab5895740f1e624beeb299398d9f33cc75dcbbb33e7eea6f7f
005c3610  55                                push   ebp
005c3611  8bec                              mov    ebp,esp
005c3613  6aff                              push   0xffffffff
005c3615  686c739400                        push   0x94736c
005c361a  64a100000000                      mov    eax,fs:0x0
005c3620  50                                push   eax
005c3621  53                                push   ebx
005c3622  a1201fd600                        mov    eax,ds:0xd61f20
005c3627  33c5                              xor    eax,ebp
005c3629  50                                push   eax
005c362a  8d45f4                            lea    eax,[ebp-0xc]
005c362d  64a300000000                      mov    fs:0x0,eax
005c3633  bb01000000                        mov    ebx,0x1
005c3638  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl
005c363e  7526                              jne    0x5c3666
005c3640  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
005c3646  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
005c364d  e82e0d1300                        call   0x6f4380
005c3652  68d0e6bc00                        push   0xbce6d0
005c3657  e8beec2c00                        call   0x89231a

[F17] Guarded constructor then atexit registration VA=0x672f5b raw=0x27235b bytes=115 sha256=018db05cde0fd34a2c337da4cec3d3a2b325665787a4a2bb86bab8bfed436f42
00672f5b  830d9043f90001                    or     DWORD PTR ds:0xf94390,0x1
00672f62  897c2468                          mov    DWORD PTR [esp+0x68],edi
00672f66  e825e6e6ff                        call   0x4e1590
00672f6b  6880ccbc00                        push   0xbccc80
00672f70  e8a5f32100                        call   0x89231a
00672f75  83c404                            add    esp,0x4
00672f78  c7442468ffffffff                  mov    DWORD PTR [esp+0x68],0xffffffff
00672f80  83fe09                            cmp    esi,0x9
00672f83  771e                              ja     0x672fa3
00672f85  8b0d0443f900                      mov    ecx,DWORD PTR ds:0xf94304
00672f8b  69f610020000                      imul   esi,esi,0x210
00672f91  8b44315c                          mov    eax,DWORD PTR [ecx+esi*1+0x5c]
00672f95  03ce                              add    ecx,esi
00672f97  f7d8                              neg    eax
00672f99  1bc0                              sbb    eax,eax
00672f9b  23c1                              and    eax,ecx
00672f9d  8944241c                          mov    DWORD PTR [esp+0x1c],eax
00672fa1  eb04                              jmp    0x672fa7
00672fa3  897c241c                          mov    DWORD PTR [esp+0x1c],edi
00672fa7  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
00672fae  7529                              jne    0x672fd9
00672fb0  b801000000                        mov    eax,0x1
00672fb5  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax
00672fbb  89442468                          mov    DWORD PTR [esp+0x68],eax
00672fbf  e8bc130800                        call   0x6f4380
00672fc4  68d0e6bc00                        push   0xbce6d0
00672fc9  e84cf32100                        call   0x89231a

[F18] Guarded constructor then atexit registration VA=0x6bce89 raw=0x2bc289 bytes=124 sha256=0f15e0fd3b0df569f5d3b21bb4032f49f9c95022f4f33254d877da35e29a0af2
006bce89  33c5                              xor    eax,ebp
006bce8b  50                                push   eax
006bce8c  8d45f4                            lea    eax,[ebp-0xc]
006bce8f  64a300000000                      mov    fs:0x0,eax
006bce95  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
006bce98  8bce                              mov    ecx,esi
006bce9a  e851830800                        call   0x7451f0
006bce9f  33db                              xor    ebx,ebx
006bcea1  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
006bcea4  b801000000                        mov    eax,0x1
006bcea9  c70644ebc300                      mov    DWORD PTR [esi],0xc3eb44
006bceaf  899e80000000                      mov    DWORD PTR [esi+0x80],ebx
006bceb5  899e84000000                      mov    DWORD PTR [esi+0x84],ebx
006bcebb  899e88000000                      mov    DWORD PTR [esi+0x88],ebx
006bcec1  899e8c000000                      mov    DWORD PTR [esi+0x8c],ebx
006bcec7  899e90000000                      mov    DWORD PTR [esi+0x90],ebx
006bcecd  899e94000000                      mov    DWORD PTR [esi+0x94],ebx
006bced3  899e98000000                      mov    DWORD PTR [esi+0x98],ebx
006bced9  899e9c000000                      mov    DWORD PTR [esi+0x9c],ebx
006bcedf  899ea0000000                      mov    DWORD PTR [esi+0xa0],ebx
006bcee5  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al
006bceeb  751e                              jne    0x6bcf0b
006bceed  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax
006bcef3  8845fc                            mov    BYTE PTR [ebp-0x4],al
006bcef6  e885740300                        call   0x6f4380
006bcefb  68d0e6bc00                        push   0xbce6d0
006bcf00  e815541d00                        call   0x89231a

[F19] Guarded constructor then atexit registration VA=0x6bcf90 raw=0x2bc390 bytes=88 sha256=84cdb9e49b2abf3a7e1220c42d36983d84e2eec0751242270cf4b2a7fb7aa887
006bcf90  55                                push   ebp
006bcf91  8bec                              mov    ebp,esp
006bcf93  6aff                              push   0xffffffff
006bcf95  68b6a79300                        push   0x93a7b6
006bcf9a  64a100000000                      mov    eax,fs:0x0
006bcfa0  50                                push   eax
006bcfa1  53                                push   ebx
006bcfa2  56                                push   esi
006bcfa3  57                                push   edi
006bcfa4  a1201fd600                        mov    eax,ds:0xd61f20
006bcfa9  33c5                              xor    eax,ebp
006bcfab  50                                push   eax
006bcfac  8d45f4                            lea    eax,[ebp-0xc]
006bcfaf  64a300000000                      mov    fs:0x0,eax
006bcfb5  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
006bcfb8  c70344ebc300                      mov    DWORD PTR [ebx],0xc3eb44
006bcfbe  33f6                              xor    esi,esi
006bcfc0  b801000000                        mov    eax,0x1
006bcfc5  8975fc                            mov    DWORD PTR [ebp-0x4],esi
006bcfc8  8405d4f3fd00                      test   BYTE PTR ds:0xfdf3d4,al
006bcfce  751f                              jne    0x6bcfef
006bcfd0  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax
006bcfd6  8845fc                            mov    BYTE PTR [ebp-0x4],al
006bcfd9  e8a2730300                        call   0x6f4380
006bcfde  68d0e6bc00                        push   0xbce6d0
006bcfe3  e832531d00                        call   0x89231a

[F20] Guarded constructor then atexit registration VA=0x6bd731 raw=0x2bcb31 bytes=117 sha256=1464c0edc786843aed507a8bd0a3d7d8f7bc0326903e6d19303aea587615b35d
006bd731  51                                push   ecx
006bd732  56                                push   esi
006bd733  a1201fd600                        mov    eax,ds:0xd61f20
006bd738  33c5                              xor    eax,ebp
006bd73a  50                                push   eax
006bd73b  8d45f4                            lea    eax,[ebp-0xc]
006bd73e  64a300000000                      mov    fs:0x0,eax
006bd744  8bf1                              mov    esi,ecx
006bd746  f605a472fb0001                    test   BYTE PTR ds:0xfb72a4,0x1
006bd74d  7527                              jne    0x6bd776
006bd74f  830da472fb0001                    or     DWORD PTR ds:0xfb72a4,0x1
006bd756  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
006bd75d  e8ee20deff                        call   0x49f850
006bd762  68e0cfbc00                        push   0xbccfe0
006bd767  e8ae4b1d00                        call   0x89231a
006bd76c  83c404                            add    esp,0x4
006bd76f  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
006bd776  baa872fb00                        mov    edx,0xfb72a8
006bd77b  e8c02ddeff                        call   0x4a0540
006bd780  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
006bd787  7527                              jne    0x6bd7b0
006bd789  b801000000                        mov    eax,0x1
006bd78e  0905d4f3fd00                      or     DWORD PTR ds:0xfdf3d4,eax
006bd794  8945fc                            mov    DWORD PTR [ebp-0x4],eax
006bd797  e8e46b0300                        call   0x6f4380
006bd79c  68d0e6bc00                        push   0xbce6d0
006bd7a1  e8744b1d00                        call   0x89231a

[F21] Guarded constructor then atexit registration VA=0x6bf6fb raw=0x2beafb bytes=131 sha256=5362945ea5baf1aac931e9050a00ccbd0ac5ba56b7d61523281bd48b2ab2dfcd
006bf6fb  8b11                              mov    edx,DWORD PTR [ecx]
006bf6fd  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
006bf703  ffd0                              call   eax
006bf705  8b9398000000                      mov    edx,DWORD PTR [ebx+0x98]
006bf70b  8b8fbc000000                      mov    ecx,DWORD PTR [edi+0xbc]
006bf711  6a00                              push   0x0
006bf713  81c2e8000000                      add    edx,0xe8
006bf719  e892a00900                        call   0x7597b0
006bf71e  8b8b98000000                      mov    ecx,DWORD PTR [ebx+0x98]
006bf724  8b11                              mov    edx,DWORD PTR [ecx]
006bf726  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
006bf72c  ffd0                              call   eax
006bf72e  8b8bb4000000                      mov    ecx,DWORD PTR [ebx+0xb4]
006bf734  81c1e8000000                      add    ecx,0xe8
006bf73a  bafcd1be00                        mov    edx,0xbed1fc
006bf73f  e8dc870900                        call   0x757f20
006bf744  8b8bb4000000                      mov    ecx,DWORD PTR [ebx+0xb4]
006bf74a  8b11                              mov    edx,DWORD PTR [ecx]
006bf74c  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
006bf752  ffd0                              call   eax
006bf754  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
006bf75b  752b                              jne    0x6bf788
006bf75d  830dd4f3fd0001                    or     DWORD PTR ds:0xfdf3d4,0x1
006bf764  c784248800000004000000            mov    DWORD PTR [esp+0x88],0x4
006bf76f  e80c4c0300                        call   0x6f4380
006bf774  68d0e6bc00                        push   0xbce6d0
006bf779  e89c2b1d00                        call   0x89231a

[C01] Guarded constructor then atexit registration VA=0x55c5a0 raw=0x15b9a0 bytes=75 sha256=0a1f8a3f0dde24b591c5be51e77454c1ecaf2f392904fe19afb7e2ea0ce12717
0055c5a0  55                                push   ebp
0055c5a1  8bec                              mov    ebp,esp
0055c5a3  6aff                              push   0xffffffff
0055c5a5  68de899300                        push   0x9389de
0055c5aa  64a100000000                      mov    eax,fs:0x0
0055c5b0  50                                push   eax
0055c5b1  a1201fd600                        mov    eax,ds:0xd61f20
0055c5b6  33c5                              xor    eax,ebp
0055c5b8  50                                push   eax
0055c5b9  8d45f4                            lea    eax,[ebp-0xc]
0055c5bc  64a300000000                      mov    fs:0x0,eax
0055c5c2  b801000000                        mov    eax,0x1
0055c5c7  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al
0055c5cd  751f                              jne    0x55c5ee
0055c5cf  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax
0055c5d5  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0055c5dc  e82f000000                        call   0x55c610
0055c5e1  6890f2bc00                        push   0xbcf290
0055c5e6  e82f5d3300                        call   0x89231a

[C02] Guarded constructor then atexit registration VA=0x55cc11 raw=0x15c011 bytes=107 sha256=a495361ebf83277bc4d935355a01a1b6c4e4eca8847e42d0436590771f4906c5
0055cc11  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0055cc14  83f903                            cmp    ecx,0x3
0055cc17  742b                              je     0x55cc44
0055cc19  83f904                            cmp    ecx,0x4
0055cc1c  7534                              jne    0x55cc52
0055cc1e  8b30                              mov    esi,DWORD PTR [eax]
0055cc20  83c610                            add    esi,0x10
0055cc23  8d7c2434                          lea    edi,[esp+0x34]
0055cc27  e834ab1900                        call   0x6f7760
0055cc2c  85c0                              test   eax,eax
0055cc2e  7422                              je     0x55cc52
0055cc30  dd442434                          fld    QWORD PTR [esp+0x34]
0055cc34  c744243c03000000                  mov    DWORD PTR [esp+0x3c],0x3
0055cc3c  dd5c2434                          fstp   QWORD PTR [esp+0x34]
0055cc40  8d442434                          lea    eax,[esp+0x34]
0055cc44  dd00                              fld    QWORD PTR [eax]
0055cc46  dd5c2434                          fstp   QWORD PTR [esp+0x34]
0055cc4a  dd442434                          fld    QWORD PTR [esp+0x34]
0055cc4e  db5c242c                          fistp  DWORD PTR [esp+0x2c]
0055cc52  b801000000                        mov    eax,0x1
0055cc57  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al
0055cc5d  7528                              jne    0x55cc87
0055cc5f  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax
0055cc65  c744245000000000                  mov    DWORD PTR [esp+0x50],0x0
0055cc6d  e89ef9ffff                        call   0x55c610
0055cc72  6890f2bc00                        push   0xbcf290
0055cc77  e89e563300                        call   0x89231a

[C03] Guarded constructor then atexit registration VA=0x55cdd3 raw=0x15c1d3 bytes=107 sha256=f2c1840a6918301a564d75288921706b2eaaa4a99e556974c7c52510c73cbbc9
0055cdd3  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0055cdd6  83f903                            cmp    ecx,0x3
0055cdd9  742b                              je     0x55ce06
0055cddb  83f904                            cmp    ecx,0x4
0055cdde  7534                              jne    0x55ce14
0055cde0  8b30                              mov    esi,DWORD PTR [eax]
0055cde2  83c610                            add    esi,0x10
0055cde5  8d7c241c                          lea    edi,[esp+0x1c]
0055cde9  e872a91900                        call   0x6f7760
0055cdee  85c0                              test   eax,eax
0055cdf0  7422                              je     0x55ce14
0055cdf2  dd44241c                          fld    QWORD PTR [esp+0x1c]
0055cdf6  c744242c03000000                  mov    DWORD PTR [esp+0x2c],0x3
0055cdfe  dd5c2424                          fstp   QWORD PTR [esp+0x24]
0055ce02  8d442424                          lea    eax,[esp+0x24]
0055ce06  dd00                              fld    QWORD PTR [eax]
0055ce08  dd5c2424                          fstp   QWORD PTR [esp+0x24]
0055ce0c  dd442424                          fld    QWORD PTR [esp+0x24]
0055ce10  db5c241c                          fistp  DWORD PTR [esp+0x1c]
0055ce14  b801000000                        mov    eax,0x1
0055ce19  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al
0055ce1f  7528                              jne    0x55ce49
0055ce21  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax
0055ce27  c744244000000000                  mov    DWORD PTR [esp+0x40],0x0
0055ce2f  e8dcf7ffff                        call   0x55c610
0055ce34  6890f2bc00                        push   0xbcf290
0055ce39  e8dc543300                        call   0x89231a

[C04] Guarded constructor then atexit registration VA=0x55d107 raw=0x15c507 bytes=107 sha256=42f13991ce51c967485fef7885a7221ed8a401fe8bf53f217c93cdfb9aec603b
0055d107  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0055d10a  83f903                            cmp    ecx,0x3
0055d10d  742b                              je     0x55d13a
0055d10f  83f904                            cmp    ecx,0x4
0055d112  7534                              jne    0x55d148
0055d114  8b30                              mov    esi,DWORD PTR [eax]
0055d116  83c610                            add    esi,0x10
0055d119  8d7c241c                          lea    edi,[esp+0x1c]
0055d11d  e83ea61900                        call   0x6f7760
0055d122  85c0                              test   eax,eax
0055d124  7422                              je     0x55d148
0055d126  dd44241c                          fld    QWORD PTR [esp+0x1c]
0055d12a  c744242c03000000                  mov    DWORD PTR [esp+0x2c],0x3
0055d132  dd5c2424                          fstp   QWORD PTR [esp+0x24]
0055d136  8d442424                          lea    eax,[esp+0x24]
0055d13a  dd00                              fld    QWORD PTR [eax]
0055d13c  dd5c2424                          fstp   QWORD PTR [esp+0x24]
0055d140  dd442424                          fld    QWORD PTR [esp+0x24]
0055d144  db5c241c                          fistp  DWORD PTR [esp+0x1c]
0055d148  b801000000                        mov    eax,0x1
0055d14d  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al
0055d153  7528                              jne    0x55d17d
0055d155  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax
0055d15b  c744244000000000                  mov    DWORD PTR [esp+0x40],0x0
0055d163  e8a8f4ffff                        call   0x55c610
0055d168  6890f2bc00                        push   0xbcf290
0055d16d  e8a8513300                        call   0x89231a

[C05] Guarded constructor then atexit registration VA=0x55d44a raw=0x15c84a bytes=116 sha256=3eb50b6194bbbe4dceb74d45672e38a9c83d48b00c9dc97c284a33402b290506
0055d44a  83f903                            cmp    ecx,0x3
0055d44d  7433                              je     0x55d482
0055d44f  83f904                            cmp    ecx,0x4
0055d452  0f85f5000000                      jne    0x55d54d
0055d458  8b30                              mov    esi,DWORD PTR [eax]
0055d45a  83c610                            add    esi,0x10
0055d45d  8d7c2414                          lea    edi,[esp+0x14]
0055d461  e8faa21900                        call   0x6f7760
0055d466  85c0                              test   eax,eax
0055d468  0f84df000000                      je     0x55d54d
0055d46e  dd442414                          fld    QWORD PTR [esp+0x14]
0055d472  c744243403000000                  mov    DWORD PTR [esp+0x34],0x3
0055d47a  dd5c242c                          fstp   QWORD PTR [esp+0x2c]
0055d47e  8d44242c                          lea    eax,[esp+0x2c]
0055d482  dd00                              fld    QWORD PTR [eax]
0055d484  dd5c242c                          fstp   QWORD PTR [esp+0x2c]
0055d488  dd44242c                          fld    QWORD PTR [esp+0x2c]
0055d48c  db5c2414                          fistp  DWORD PTR [esp+0x14]
0055d490  8b742414                          mov    esi,DWORD PTR [esp+0x14]
0055d494  bb01000000                        mov    ebx,0x1
0055d499  841de81efe00                      test   BYTE PTR ds:0xfe1ee8,bl
0055d49f  7528                              jne    0x55d4c9
0055d4a1  091de81efe00                      or     DWORD PTR ds:0xfe1ee8,ebx
0055d4a7  c744244800000000                  mov    DWORD PTR [esp+0x48],0x0
0055d4af  e85cf1ffff                        call   0x55c610
0055d4b4  6890f2bc00                        push   0xbcf290
0055d4b9  e85c4e3300                        call   0x89231a

[C06] Guarded constructor then atexit registration VA=0x55d605 raw=0x15ca05 bytes=96 sha256=fcfd4337d430e95e4f79403a1f135ab6e0eb50780ed3f43c0bf438c0b563b528
0055d605  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0055d608  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0055d60b  83ee10                            sub    esi,0x10
0055d60e  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0055d612  7421                              je     0x55d635
0055d614  e8b7df1900                        call   0x6fb5d0
0055d619  85c0                              test   eax,eax
0055d61b  746c                              je     0x55d689
0055d61d  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0055d620  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0055d623  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0055d626  7207                              jb     0x55d62f
0055d628  8bc7                              mov    eax,edi
0055d62a  e871dd1900                        call   0x6fb3a0
0055d62f  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0055d632  83ee10                            sub    esi,0x10
0055d635  8b36                              mov    esi,DWORD PTR [esi]
0055d637  83c610                            add    esi,0x10
0055d63a  744d                              je     0x55d689
0055d63c  b801000000                        mov    eax,0x1
0055d641  8405e81efe00                      test   BYTE PTR ds:0xfe1ee8,al
0055d647  7526                              jne    0x55d66f
0055d649  0905e81efe00                      or     DWORD PTR ds:0xfe1ee8,eax
0055d64f  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0055d656  e8b5efffff                        call   0x55c610
0055d65b  6890f2bc00                        push   0xbcf290
0055d660  e8b54c3300                        call   0x89231a

[C07] Guarded constructor then atexit registration VA=0x5625b1 raw=0x1619b1 bytes=129 sha256=4e6126d579c5c8741b022d29a2839d40cfc00c65a7f5200e3d44867c13bc5cc1
005625b1  8935bc1bfc00                      mov    DWORD PTR ds:0xfc1bbc,esi
005625b7  3bc6                              cmp    eax,esi
005625b9  740c                              je     0x5625c7
005625bb  50                                push   eax
005625bc  e80f22f4ff                        call   0x4a47d0
005625c1  8935901bfc00                      mov    DWORD PTR ds:0xfc1b90,esi
005625c7  f605f41bfc0001                    test   BYTE PTR ds:0xfc1bf4,0x1
005625ce  7525                              jne    0x5625f5
005625d0  830df41bfc0001                    or     DWORD PTR ds:0xfc1bf4,0x1
005625d7  c744244002000000                  mov    DWORD PTR [esp+0x40],0x2
005625df  e8acc90100                        call   0x57ef90
005625e4  68b0dfbc00                        push   0xbcdfb0
005625e9  e82cfd3200                        call   0x89231a
005625ee  83c404                            add    esp,0x4
005625f1  895c2440                          mov    DWORD PTR [esp+0x40],ebx
005625f5  89356c1cfc00                      mov    DWORD PTR ds:0xfc1c6c,esi
005625fb  8b4754                            mov    eax,DWORD PTR [edi+0x54]
005625fe  bf04000000                        mov    edi,0x4
00562603  3bc6                              cmp    eax,esi
00562605  0f857c000000                      jne    0x562687
0056260b  f605e81efe0001                    test   BYTE PTR ds:0xfe1ee8,0x1
00562612  7525                              jne    0x562639
00562614  830de81efe0001                    or     DWORD PTR ds:0xfe1ee8,0x1
0056261b  c744244003000000                  mov    DWORD PTR [esp+0x40],0x3
00562623  e8e89fffff                        call   0x55c610
00562628  6890f2bc00                        push   0xbcf290
0056262d  e8e8fc3200                        call   0x89231a

[C08] Guarded constructor then atexit registration VA=0x565937 raw=0x164d37 bytes=119 sha256=0d528b57394c052018f39a3735899780b26827b08c590546756da34e71ddc4d3
00565937  c74424380f000000                  mov    DWORD PTR [esp+0x38],0xf
0056593f  c744243400000000                  mov    DWORD PTR [esp+0x34],0x0
00565947  c644242400                        mov    BYTE PTR [esp+0x24],0x0
0056594c  e81fd1e9ff                        call   0x402a70
00565951  6aff                              push   0xffffffff
00565953  8d4714                            lea    eax,[edi+0x14]
00565956  6a00                              push   0x0
00565958  bb05000000                        mov    ebx,0x5
0056595d  50                                push   eax
0056595e  8d4c2428                          lea    ecx,[esp+0x28]
00565962  895c2454                          mov    DWORD PTR [esp+0x54],ebx
00565966  e865c5e9ff                        call   0x401ed0
0056596b  6a04                              push   0x4
0056596d  68e406c100                        push   0xc106e4
00565972  8d4c2424                          lea    ecx,[esp+0x24]
00565976  e845c6e9ff                        call   0x401fc0
0056597b  837c243010                        cmp    DWORD PTR [esp+0x30],0x10
00565980  8b7c241c                          mov    edi,DWORD PTR [esp+0x1c]
00565984  7304                              jae    0x56598a
00565986  8d7c241c                          lea    edi,[esp+0x1c]
0056598a  f605e81efe0001                    test   BYTE PTR ds:0xfe1ee8,0x1
00565991  7522                              jne    0x5659b5
00565993  830de81efe0001                    or     DWORD PTR ds:0xfe1ee8,0x1
0056599a  c644244806                        mov    BYTE PTR [esp+0x48],0x6
0056599f  e86c6cffff                        call   0x55c610
005659a4  6890f2bc00                        push   0xbcf290
005659a9  e86cc93200                        call   0x89231a

[E01_24] Exception unwind clears singleton initialization guard VA=0x93a72f raw=0x539b2f bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a72f  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a734  83e0fe                            and    eax,0xfffffffe
0093a737  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a73c  c3                                ret

[E01_24D] Unwind-map entry for guard clear VA=0xcb8350 raw=0x8b6950 bytes=8 sha256=2032f1f2f05ccb01db68c9850d3c8ce151e253cb36e3642262c2796dcba14635
0b0000002fa79300

[EH01] Installed function EH handler VA=0x93a73d raw=0x539b3d bytes=27 sha256=37ae9d11ba9d1226987ab3f608a4483b013a90e8cda9ffd6d7e5eb756649e6f2
0093a73d  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a741  8d420c                            lea    eax,[edx+0xc]
0093a744  8b4ae0                            mov    ecx,DWORD PTR [edx-0x20]
0093a747  33c8                              xor    ecx,eax
0093a749  e8b368f5ff                        call   0x891001
0093a74e  b85883cb00                        mov    eax,0xcb8358
0093a753  e95a30f6ff                        jmp    0x89d7b2

[EH01I] Compiler function EH info VA=0xcb8358 raw=0x8b6958 bytes=36 sha256=7c17e3805cf69acc478e6041fb03b9abe45b6cbf4d8a7b1f199f364249e6459d
22059319190000009082cb00000000000000000000000000000000000000000001000000

[EH01P] Caller installs EH handler in FS chain VA=0x48ab70 raw=0x89f70 bytes=40 sha256=03bb46ff1b5c9573e053c9b3b684fc483ad5073118bceb776e883733417644e4
0048ab70  55                                push   ebp
0048ab71  8bec                              mov    ebp,esp
0048ab73  6aff                              push   0xffffffff
0048ab75  683da79300                        push   0x93a73d
0048ab7a  64a100000000                      mov    eax,fs:0x0
0048ab80  50                                push   eax
0048ab81  83ec10                            sub    esp,0x10
0048ab84  53                                push   ebx
0048ab85  56                                push   esi
0048ab86  57                                push   edi
0048ab87  a1201fd600                        mov    eax,ds:0xd61f20
0048ab8c  33c5                              xor    eax,ebp
0048ab8e  50                                push   eax
0048ab8f  8d45f4                            lea    eax,[ebp-0xc]
0048ab92  64a300000000                      mov    fs:0x0,eax

[E02_7] Exception unwind clears singleton initialization guard VA=0x949aa2 raw=0x548ea2 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
00949aa2  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00949aa7  83e0fe                            and    eax,0xfffffffe
00949aaa  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
00949aaf  c3                                ret

[E02_7D] Unwind-map entry for guard clear VA=0xcc46b0 raw=0x8c2cb0 bytes=8 sha256=05b2e2e24adfb2c1be2ef0c31154ecdda8d442940d8e591bd52bc0003523a444
ffffffffa29a9400

[E02_8] Exception unwind clears singleton initialization guard VA=0x949ab0 raw=0x548eb0 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
00949ab0  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00949ab5  83e0fe                            and    eax,0xfffffffe
00949ab8  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
00949abd  c3                                ret

[E02_8D] Unwind-map entry for guard clear VA=0xcc46b8 raw=0x8c2cb8 bytes=8 sha256=cbdf239ed36fcc8f13bc00bd54676426acbb50cd8f080c9c42814feaba0a1868
ffffffffb09a9400

[E02_54] Exception unwind clears singleton initialization guard VA=0x949d2e raw=0x54912e bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
00949d2e  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00949d33  83e0fe                            and    eax,0xfffffffe
00949d36  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
00949d3b  c3                                ret

[E02_54D] Unwind-map entry for guard clear VA=0xcc4828 raw=0x8c2e28 bytes=8 sha256=157aa7dc47a031388430d41671f4fae3d9a41b96ac692580bd3c6e7e900925dc
ffffffff2e9d9400

[E02_56] Exception unwind clears singleton initialization guard VA=0x949d4a raw=0x54914a bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
00949d4a  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00949d4f  83e0fe                            and    eax,0xfffffffe
00949d52  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
00949d57  c3                                ret

[E02_56D] Unwind-map entry for guard clear VA=0xcc4838 raw=0x8c2e38 bytes=8 sha256=f6bbcbd8baa5dedf7e1d45a0efd2cd69c467921c94ec2a06df8bbc00faa9cef6
ffffffff4a9d9400

[EH02] Installed function EH handler VA=0x949fb2 raw=0x5493b2 bytes=40 sha256=be8b1fa0e04b22dcc19e7c60d437a673a75baf111cd7a1c65264ad8e92c6ff30
00949fb2  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00949fb6  8d429c                            lea    eax,[edx-0x64]
00949fb9  8b4a98                            mov    ecx,DWORD PTR [edx-0x68]
00949fbc  33c8                              xor    ecx,eax
00949fbe  e83e70f4ff                        call   0x891001
00949fc3  83c00c                            add    eax,0xc
00949fc6  8b4af8                            mov    ecx,DWORD PTR [edx-0x8]
00949fc9  33c8                              xor    ecx,eax
00949fcb  e83170f4ff                        call   0x891001
00949fd0  b8b049cc00                        mov    eax,0xcc49b0
00949fd5  e9d837f5ff                        jmp    0x89d7b2

[EH02I] Compiler function EH info VA=0xcc49b0 raw=0x8c2fb0 bytes=36 sha256=2ccd5e0d1bae0e8e47d124822474d7a4c8e52c287bd744525b9039e40f19589f
22059319670000007846cc00000000000000000000000000000000000000000001000000

[EH02P] Caller installs EH handler in FS chain VA=0x48c6e0 raw=0x8bae0 bytes=55 sha256=0e197e5816dc12d232d509d9aa0045e16c28996a8d59a262c6d50eddd636fcbc
0048c6e0  55                                push   ebp
0048c6e1  8bec                              mov    ebp,esp
0048c6e3  83e4f8                            and    esp,0xfffffff8
0048c6e6  6aff                              push   0xffffffff
0048c6e8  68b29f9400                        push   0x949fb2
0048c6ed  64a100000000                      mov    eax,fs:0x0
0048c6f3  50                                push   eax
0048c6f4  83ec58                            sub    esp,0x58
0048c6f7  a1201fd600                        mov    eax,ds:0xd61f20
0048c6fc  33c4                              xor    eax,esp
0048c6fe  89442450                          mov    DWORD PTR [esp+0x50],eax
0048c702  53                                push   ebx
0048c703  56                                push   esi
0048c704  57                                push   edi
0048c705  a1201fd600                        mov    eax,ds:0xd61f20
0048c70a  33c4                              xor    eax,esp
0048c70c  50                                push   eax
0048c70d  8d442468                          lea    eax,[esp+0x68]
0048c711  64a300000000                      mov    fs:0x0,eax

[E03_0] Exception unwind clears singleton initialization guard VA=0x93a5c0 raw=0x5399c0 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a5c0  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a5c5  83e0fe                            and    eax,0xfffffffe
0093a5c8  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a5cd  c3                                ret

[E03_0D] Unwind-map entry for guard clear VA=0xcb8260 raw=0x8b6860 bytes=8 sha256=e7a8680ee4f1985aea6d765e5e4b251fdb167ec9b6249da9f66e9b03c5c2e61a
ffffffffc0a59300

[EH03] Installed function EH handler VA=0x93a5ce raw=0x5399ce bytes=27 sha256=f77ce9c30d7b9343186c0c6d986bb8969785bce56b32be7bc3bc829b8fa423e0
0093a5ce  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a5d2  8d420c                            lea    eax,[edx+0xc]
0093a5d5  8b4afc                            mov    ecx,DWORD PTR [edx-0x4]
0093a5d8  33c8                              xor    ecx,eax
0093a5da  e8226af5ff                        call   0x891001
0093a5df  b86882cb00                        mov    eax,0xcb8268
0093a5e4  e9c931f6ff                        jmp    0x89d7b2

[EH03I] Compiler function EH info VA=0xcb8268 raw=0x8b6868 bytes=36 sha256=b11a7ba7ef7223914148e0cda159e6862b8bd44b322bd547265361091c199b77
22059319010000006082cb00000000000000000000000000000000000000000001000000

[EH03P] Caller installs EH handler in FS chain VA=0x49b230 raw=0x9a630 bytes=34 sha256=df8e12def83223dc56a9bf99c8e344686a6319f33302e542171403c6ec195a39
0049b230  55                                push   ebp
0049b231  8bec                              mov    ebp,esp
0049b233  6aff                              push   0xffffffff
0049b235  68cea59300                        push   0x93a5ce
0049b23a  64a100000000                      mov    eax,fs:0x0
0049b240  50                                push   eax
0049b241  a1201fd600                        mov    eax,ds:0xd61f20
0049b246  33c5                              xor    eax,ebp
0049b248  50                                push   eax
0049b249  8d45f4                            lea    eax,[ebp-0xc]
0049b24c  64a300000000                      mov    fs:0x0,eax

[E04_0] Exception unwind clears singleton initialization guard VA=0x944eb0 raw=0x5442b0 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
00944eb0  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00944eb5  83e0fe                            and    eax,0xfffffffe
00944eb8  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
00944ebd  c3                                ret

[E04_0D] Unwind-map entry for guard clear VA=0xcc0a88 raw=0x8bf088 bytes=8 sha256=89eb7ea032ac05ea5301ad14012d04efeb160e1b0203cc4e83dec0401e88f584
ffffffffb04e9400

[EH04] Installed function EH handler VA=0x944ebe raw=0x5442be bytes=27 sha256=ea1c0980c14307b0b9a872c56502ad57c13c2796aadbc8502a7ff45f90d11c56
00944ebe  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00944ec2  8d420c                            lea    eax,[edx+0xc]
00944ec5  8b4af4                            mov    ecx,DWORD PTR [edx-0xc]
00944ec8  33c8                              xor    ecx,eax
00944eca  e832c1f4ff                        call   0x891001
00944ecf  b8900acc00                        mov    eax,0xcc0a90
00944ed4  e9d988f5ff                        jmp    0x89d7b2

[EH04I] Compiler function EH info VA=0xcc0a90 raw=0x8bf090 bytes=36 sha256=e0df425a57ba57866d119423e3a7a6cad00f872f47674ab006eba64088e56d20
2205931901000000880acc00000000000000000000000000000000000000000001000000

[EH04P] Caller installs EH handler in FS chain VA=0x4a0950 raw=0x9fd50 bytes=37 sha256=9753c5452227196030135bac0c686d7bb338107d720a12780ad617b22de774cd
004a0950  55                                push   ebp
004a0951  8bec                              mov    ebp,esp
004a0953  6aff                              push   0xffffffff
004a0955  68be4e9400                        push   0x944ebe
004a095a  64a100000000                      mov    eax,fs:0x0
004a0960  50                                push   eax
004a0961  83ec08                            sub    esp,0x8
004a0964  a1201fd600                        mov    eax,ds:0xd61f20
004a0969  33c5                              xor    eax,ebp
004a096b  50                                push   eax
004a096c  8d45f4                            lea    eax,[ebp-0xc]
004a096f  64a300000000                      mov    fs:0x0,eax

[E05_0] Exception unwind clears singleton initialization guard VA=0x93a970 raw=0x539d70 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a970  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a975  83e0fe                            and    eax,0xfffffffe
0093a978  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a97d  c3                                ret

[E05_0D] Unwind-map entry for guard clear VA=0xcb8540 raw=0x8b6b40 bytes=8 sha256=d73f5711f848e03ee349814c847ca290d604820620f30325f6444b36a2816f4f
ffffffff70a99300

[EH05] Installed function EH handler VA=0x93a97e raw=0x539d7e bytes=27 sha256=3bee99f45bb923553a6fb04cebc8dde7fe2a609e2703e1db6f9ef2b70ebb078e
0093a97e  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a982  8d420c                            lea    eax,[edx+0xc]
0093a985  8b4af0                            mov    ecx,DWORD PTR [edx-0x10]
0093a988  33c8                              xor    ecx,eax
0093a98a  e87266f5ff                        call   0x891001
0093a98f  b84885cb00                        mov    eax,0xcb8548
0093a994  e9192ef6ff                        jmp    0x89d7b2

[EH05I] Compiler function EH info VA=0xcb8548 raw=0x8b6b48 bytes=36 sha256=550d89a4eefc06464028333142ba58f06f87e4f306533b1b9e14eb978ad13ba7
22059319010000004085cb00000000000000000000000000000000000000000001000000

[EH05P] Caller installs EH handler in FS chain VA=0x4a1230 raw=0xa0630 bytes=37 sha256=f1ffc0f1ee8fe4ed605abe9e688e924be0958fe85f23f101840a243eaaad1e04
004a1230  55                                push   ebp
004a1231  8bec                              mov    ebp,esp
004a1233  6aff                              push   0xffffffff
004a1235  687ea99300                        push   0x93a97e
004a123a  64a100000000                      mov    eax,fs:0x0
004a1240  50                                push   eax
004a1241  53                                push   ebx
004a1242  56                                push   esi
004a1243  57                                push   edi
004a1244  a1201fd600                        mov    eax,ds:0xd61f20
004a1249  33c5                              xor    eax,ebp
004a124b  50                                push   eax
004a124c  8d45f4                            lea    eax,[ebp-0xc]
004a124f  64a300000000                      mov    fs:0x0,eax

[E06_3] Exception unwind clears singleton initialization guard VA=0x93a8d7 raw=0x539cd7 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a8d7  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a8dc  83e0fe                            and    eax,0xfffffffe
0093a8df  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a8e4  c3                                ret

[E06_3D] Unwind-map entry for guard clear VA=0xcb84c8 raw=0x8b6ac8 bytes=8 sha256=a17585f8490fb04fbde9245b2e08743f278568447e531eaad8ca8ec78789b2aa
ffffffffd7a89300

[EH06] Installed function EH handler VA=0x93a8f5 raw=0x539cf5 bytes=40 sha256=368bd81267ef547d47cfc579cdd6715abbc0282b38ecb9e96baaf59de897007c
0093a8f5  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a8f9  8d42a4                            lea    eax,[edx-0x5c]
0093a8fc  8b4aa0                            mov    ecx,DWORD PTR [edx-0x60]
0093a8ff  33c8                              xor    ecx,eax
0093a901  e8fb66f5ff                        call   0x891001
0093a906  83c00c                            add    eax,0xc
0093a909  8b4af8                            mov    ecx,DWORD PTR [edx-0x8]
0093a90c  33c8                              xor    ecx,eax
0093a90e  e8ee66f5ff                        call   0x891001
0093a913  b8e084cb00                        mov    eax,0xcb84e0
0093a918  e9952ef6ff                        jmp    0x89d7b2

[EH06I] Compiler function EH info VA=0xcb84e0 raw=0x8b6ae0 bytes=36 sha256=b39bb9151099a35c70ea271e838b36dd3e4cd0b528a9a566bcd41f4e2b389b50
2205931906000000b084cb00000000000000000000000000000000000000000001000000

[EH06P] Caller installs EH handler in FS chain VA=0x4b5900 raw=0xb4d00 bytes=55 sha256=ec008aea78870cf34eb776a5dbef009ffbe2d9e6e000b6783619aea7423e4c71
004b5900  55                                push   ebp
004b5901  8bec                              mov    ebp,esp
004b5903  83e4f8                            and    esp,0xfffffff8
004b5906  6aff                              push   0xffffffff
004b5908  68f5a89300                        push   0x93a8f5
004b590d  64a100000000                      mov    eax,fs:0x0
004b5913  50                                push   eax
004b5914  83ec50                            sub    esp,0x50
004b5917  a1201fd600                        mov    eax,ds:0xd61f20
004b591c  33c4                              xor    eax,esp
004b591e  89442448                          mov    DWORD PTR [esp+0x48],eax
004b5922  53                                push   ebx
004b5923  56                                push   esi
004b5924  57                                push   edi
004b5925  a1201fd600                        mov    eax,ds:0xd61f20
004b592a  33c4                              xor    eax,esp
004b592c  50                                push   eax
004b592d  8d442460                          lea    eax,[esp+0x60]
004b5931  64a300000000                      mov    fs:0x0,eax

[E07_2] Exception unwind clears singleton initialization guard VA=0x93a886 raw=0x539c86 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a886  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a88b  83e0fe                            and    eax,0xfffffffe
0093a88e  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a893  c3                                ret

[E07_2D] Unwind-map entry for guard clear VA=0xcb8480 raw=0x8b6a80 bytes=8 sha256=0c6068990589082ccd3e047843d8a47c1d18c239f5e84ee30eb6b9dfbadd9f5f
0100000086a89300

[EH07] Installed function EH handler VA=0x93a894 raw=0x539c94 bytes=27 sha256=c890926eb753d724a4c4f1056417f42d2a0825d32e1576904396ccd985e9d0e9
0093a894  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a898  8d420c                            lea    eax,[edx+0xc]
0093a89b  8b4aec                            mov    ecx,DWORD PTR [edx-0x14]
0093a89e  33c8                              xor    ecx,eax
0093a8a0  e85c67f5ff                        call   0x891001
0093a8a5  b88884cb00                        mov    eax,0xcb8488
0093a8aa  e9032ff6ff                        jmp    0x89d7b2

[EH07I] Compiler function EH info VA=0xcb8488 raw=0x8b6a88 bytes=36 sha256=cf585ae2334892275497ac90211af691d3fbc63029e7509b18bece9f8f6f7a57
22059319030000007084cb00000000000000000000000000000000000000000001000000

[EH07P] Caller installs EH handler in FS chain VA=0x54e750 raw=0x14db50 bytes=38 sha256=bc0f593d3756f52ef3db2f32d252eb4ed4365d5259e03c0c93dd3f8916a1b6a5
0054e750  55                                push   ebp
0054e751  8bec                              mov    ebp,esp
0054e753  6aff                              push   0xffffffff
0054e755  6894a89300                        push   0x93a894
0054e75a  64a100000000                      mov    eax,fs:0x0
0054e760  50                                push   eax
0054e761  83ec0c                            sub    esp,0xc
0054e764  53                                push   ebx
0054e765  a1201fd600                        mov    eax,ds:0xd61f20
0054e76a  33c5                              xor    eax,ebp
0054e76c  50                                push   eax
0054e76d  8d45f4                            lea    eax,[ebp-0xc]
0054e770  64a300000000                      mov    fs:0x0,eax

[E08_0] Exception unwind clears singleton initialization guard VA=0x9389d0 raw=0x537dd0 bytes=14 sha256=efee3200999decb7b44b8704c0c214cda2a60c19cd1940625db35c777af538ba
009389d0  a1e81efe00                        mov    eax,ds:0xfe1ee8
009389d5  83e0fe                            and    eax,0xfffffffe
009389d8  a3e81efe00                        mov    ds:0xfe1ee8,eax
009389dd  c3                                ret

[E08_0D] Unwind-map entry for guard clear VA=0xcb6ad8 raw=0x8b50d8 bytes=8 sha256=a03e639df420215c1f5a21a23ccdf15996c663f657b240cd309a5d908b9fba37
ffffffffd0899300

[EH08] Installed function EH handler VA=0x9389de raw=0x537dde bytes=27 sha256=42b23fe2fff1a001d243b5eb70554925c765573a93b8ddcec65da541482a22ca
009389de  8b542408                          mov    edx,DWORD PTR [esp+0x8]
009389e2  8d420c                            lea    eax,[edx+0xc]
009389e5  8b4afc                            mov    ecx,DWORD PTR [edx-0x4]
009389e8  33c8                              xor    ecx,eax
009389ea  e81286f5ff                        call   0x891001
009389ef  b8e06acb00                        mov    eax,0xcb6ae0
009389f4  e9b94df6ff                        jmp    0x89d7b2

[EH08I] Compiler function EH info VA=0xcb6ae0 raw=0x8b50e0 bytes=36 sha256=1d5502514c69cdca7e77a389e21be20d0d8e0ad76b49f40aa4b3906c27b24152
2205931901000000d86acb00000000000000000000000000000000000000000001000000

[EH08P] Caller installs EH handler in FS chain VA=0x55c5a0 raw=0x15b9a0 bytes=34 sha256=2b7b0d8d09d2a7b7bd73986eb091725056bb9af9e078416b1487b0dcd7dd76b9
0055c5a0  55                                push   ebp
0055c5a1  8bec                              mov    ebp,esp
0055c5a3  6aff                              push   0xffffffff
0055c5a5  68de899300                        push   0x9389de
0055c5aa  64a100000000                      mov    eax,fs:0x0
0055c5b0  50                                push   eax
0055c5b1  a1201fd600                        mov    eax,ds:0xd61f20
0055c5b6  33c5                              xor    eax,ebp
0055c5b8  50                                push   eax
0055c5b9  8d45f4                            lea    eax,[ebp-0xc]
0055c5bc  64a300000000                      mov    fs:0x0,eax

[E09_0] Exception unwind clears singleton initialization guard VA=0x938d60 raw=0x538160 bytes=14 sha256=efee3200999decb7b44b8704c0c214cda2a60c19cd1940625db35c777af538ba
00938d60  a1e81efe00                        mov    eax,ds:0xfe1ee8
00938d65  83e0fe                            and    eax,0xfffffffe
00938d68  a3e81efe00                        mov    ds:0xfe1ee8,eax
00938d6d  c3                                ret

[E09_0D] Unwind-map entry for guard clear VA=0xcb6e08 raw=0x8b5408 bytes=8 sha256=ec6c011dcbde5485dd1104f8d9bac5951d2684a25a405b3a89c19be26dbe0ef5
ffffffff608d9300

[EH09] Installed function EH handler VA=0x938d6e raw=0x53816e bytes=27 sha256=c24ed9cc4f733f143ffe1633b77081a452ba6fd62ac3e0143534d55a73defe79
00938d6e  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00938d72  8d42bc                            lea    eax,[edx-0x44]
00938d75  8b4ab8                            mov    ecx,DWORD PTR [edx-0x48]
00938d78  33c8                              xor    ecx,eax
00938d7a  e88282f5ff                        call   0x891001
00938d7f  b8106ecb00                        mov    eax,0xcb6e10
00938d84  e9294af6ff                        jmp    0x89d7b2

[EH09I] Compiler function EH info VA=0xcb6e10 raw=0x8b5410 bytes=36 sha256=e1c7c428e3555309a51005e9454f848406be042f4eaae35078435fa30fa839e9
2205931901000000086ecb00000000000000000000000000000000000000000001000000

[EH09P] Caller installs EH handler in FS chain VA=0x55c940 raw=0x15bd40 bytes=44 sha256=4163fff073be683159632999fda5aafbda92fb0305adc7ae9bd0d576a75e3c36
0055c940  55                                push   ebp
0055c941  8bec                              mov    ebp,esp
0055c943  83e4f8                            and    esp,0xfffffff8
0055c946  6aff                              push   0xffffffff
0055c948  686e8d9300                        push   0x938d6e
0055c94d  64a100000000                      mov    eax,fs:0x0
0055c953  50                                push   eax
0055c954  83ec38                            sub    esp,0x38
0055c957  53                                push   ebx
0055c958  56                                push   esi
0055c959  57                                push   edi
0055c95a  a1201fd600                        mov    eax,ds:0xd61f20
0055c95f  33c4                              xor    eax,esp
0055c961  50                                push   eax
0055c962  8d442448                          lea    eax,[esp+0x48]
0055c966  64a300000000                      mov    fs:0x0,eax

[E10_0] Exception unwind clears singleton initialization guard VA=0x938d30 raw=0x538130 bytes=14 sha256=efee3200999decb7b44b8704c0c214cda2a60c19cd1940625db35c777af538ba
00938d30  a1e81efe00                        mov    eax,ds:0xfe1ee8
00938d35  83e0fe                            and    eax,0xfffffffe
00938d38  a3e81efe00                        mov    ds:0xfe1ee8,eax
00938d3d  c3                                ret

[E10_0D] Unwind-map entry for guard clear VA=0xcb6dd8 raw=0x8b53d8 bytes=8 sha256=10dc4684cb035a624b2c3c354f8018d6084093978cc1b2301837cf1181843d5a
ffffffff308d9300

[EH10] Installed function EH handler VA=0x938d3e raw=0x53813e bytes=27 sha256=596fd9a336203fb42a464e085736cfae41e1e9abe240b01419bd9bb6d267f93c
00938d3e  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00938d42  8d42cc                            lea    eax,[edx-0x34]
00938d45  8b4ac8                            mov    ecx,DWORD PTR [edx-0x38]
00938d48  33c8                              xor    ecx,eax
00938d4a  e8b282f5ff                        call   0x891001
00938d4f  b8e06dcb00                        mov    eax,0xcb6de0
00938d54  e9594af6ff                        jmp    0x89d7b2

[EH10I] Compiler function EH info VA=0xcb6de0 raw=0x8b53e0 bytes=36 sha256=0d7dffdef3b2b26ebfd71cb6dc097c9c8ccf348fc8ffd1825c7df05b3227211a
2205931901000000d86dcb00000000000000000000000000000000000000000001000000

[EH10P] Caller installs EH handler in FS chain VA=0x55cce0 raw=0x15c0e0 bytes=44 sha256=fd56f9a0e8cc46c2c196f77f62aa3723f0e8ab27941631ec4f7feeb8e2520670
0055cce0  55                                push   ebp
0055cce1  8bec                              mov    ebp,esp
0055cce3  83e4f8                            and    esp,0xfffffff8
0055cce6  6aff                              push   0xffffffff
0055cce8  683e8d9300                        push   0x938d3e
0055cced  64a100000000                      mov    eax,fs:0x0
0055ccf3  50                                push   eax
0055ccf4  83ec28                            sub    esp,0x28
0055ccf7  53                                push   ebx
0055ccf8  56                                push   esi
0055ccf9  57                                push   edi
0055ccfa  a1201fd600                        mov    eax,ds:0xd61f20
0055ccff  33c4                              xor    eax,esp
0055cd01  50                                push   eax
0055cd02  8d442438                          lea    eax,[esp+0x38]
0055cd06  64a300000000                      mov    fs:0x0,eax

[E11_0] Exception unwind clears singleton initialization guard VA=0x938d30 raw=0x538130 bytes=14 sha256=efee3200999decb7b44b8704c0c214cda2a60c19cd1940625db35c777af538ba
00938d30  a1e81efe00                        mov    eax,ds:0xfe1ee8
00938d35  83e0fe                            and    eax,0xfffffffe
00938d38  a3e81efe00                        mov    ds:0xfe1ee8,eax
00938d3d  c3                                ret

[E11_0D] Unwind-map entry for guard clear VA=0xcb6dd8 raw=0x8b53d8 bytes=8 sha256=10dc4684cb035a624b2c3c354f8018d6084093978cc1b2301837cf1181843d5a
ffffffff308d9300

[EH11] Installed function EH handler VA=0x938d3e raw=0x53813e bytes=27 sha256=596fd9a336203fb42a464e085736cfae41e1e9abe240b01419bd9bb6d267f93c
00938d3e  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00938d42  8d42cc                            lea    eax,[edx-0x34]
00938d45  8b4ac8                            mov    ecx,DWORD PTR [edx-0x38]
00938d48  33c8                              xor    ecx,eax
00938d4a  e8b282f5ff                        call   0x891001
00938d4f  b8e06dcb00                        mov    eax,0xcb6de0
00938d54  e9594af6ff                        jmp    0x89d7b2

[EH11I] Compiler function EH info VA=0xcb6de0 raw=0x8b53e0 bytes=36 sha256=0d7dffdef3b2b26ebfd71cb6dc097c9c8ccf348fc8ffd1825c7df05b3227211a
2205931901000000d86dcb00000000000000000000000000000000000000000001000000

[EH11P] Caller installs EH handler in FS chain VA=0x55ced0 raw=0x15c2d0 bytes=44 sha256=fd56f9a0e8cc46c2c196f77f62aa3723f0e8ab27941631ec4f7feeb8e2520670
0055ced0  55                                push   ebp
0055ced1  8bec                              mov    ebp,esp
0055ced3  83e4f8                            and    esp,0xfffffff8
0055ced6  6aff                              push   0xffffffff
0055ced8  683e8d9300                        push   0x938d3e
0055cedd  64a100000000                      mov    eax,fs:0x0
0055cee3  50                                push   eax
0055cee4  83ec28                            sub    esp,0x28
0055cee7  53                                push   ebx
0055cee8  56                                push   esi
0055cee9  57                                push   edi
0055ceea  a1201fd600                        mov    eax,ds:0xd61f20
0055ceef  33c4                              xor    eax,esp
0055cef1  50                                push   eax
0055cef2  8d442438                          lea    eax,[esp+0x38]
0055cef6  64a300000000                      mov    fs:0x0,eax

[E12_0] Exception unwind clears singleton initialization guard VA=0x938d00 raw=0x538100 bytes=14 sha256=efee3200999decb7b44b8704c0c214cda2a60c19cd1940625db35c777af538ba
00938d00  a1e81efe00                        mov    eax,ds:0xfe1ee8
00938d05  83e0fe                            and    eax,0xfffffffe
00938d08  a3e81efe00                        mov    ds:0xfe1ee8,eax
00938d0d  c3                                ret

[E12_0D] Unwind-map entry for guard clear VA=0xcb6da8 raw=0x8b53a8 bytes=8 sha256=fc6db8b2c22b203c3527d32dfda22ca8c2b6a7f52e3c5fc2b135f8af11898e80
ffffffff008d9300

[EH12] Installed function EH handler VA=0x938d0e raw=0x53810e bytes=27 sha256=9200414ae8846a0f52175fa80f0e2425e047a29a5dd3458984eb8bead68aa6fd
00938d0e  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00938d12  8d42c4                            lea    eax,[edx-0x3c]
00938d15  8b4ac0                            mov    ecx,DWORD PTR [edx-0x40]
00938d18  33c8                              xor    ecx,eax
00938d1a  e8e282f5ff                        call   0x891001
00938d1f  b8b06dcb00                        mov    eax,0xcb6db0
00938d24  e9894af6ff                        jmp    0x89d7b2

[EH12I] Compiler function EH info VA=0xcb6db0 raw=0x8b53b0 bytes=36 sha256=ec70cdbf93f28624db93c7991a3b6e9c94f51766ac005ed0668ab65620002d93
2205931901000000a86dcb00000000000000000000000000000000000000000001000000

[EH12P] Caller installs EH handler in FS chain VA=0x55d220 raw=0x15c620 bytes=44 sha256=35b314ad98ecac335549e670cac37a21da21f928d5289db98b8badac507efca4
0055d220  55                                push   ebp
0055d221  8bec                              mov    ebp,esp
0055d223  83e4f8                            and    esp,0xfffffff8
0055d226  6aff                              push   0xffffffff
0055d228  680e8d9300                        push   0x938d0e
0055d22d  64a100000000                      mov    eax,fs:0x0
0055d233  50                                push   eax
0055d234  83ec30                            sub    esp,0x30
0055d237  53                                push   ebx
0055d238  56                                push   esi
0055d239  57                                push   edi
0055d23a  a1201fd600                        mov    eax,ds:0xd61f20
0055d23f  33c4                              xor    eax,esp
0055d241  50                                push   eax
0055d242  8d442440                          lea    eax,[esp+0x40]
0055d246  64a300000000                      mov    fs:0x0,eax

[E13_0] Exception unwind clears singleton initialization guard VA=0x938cd0 raw=0x5380d0 bytes=14 sha256=efee3200999decb7b44b8704c0c214cda2a60c19cd1940625db35c777af538ba
00938cd0  a1e81efe00                        mov    eax,ds:0xfe1ee8
00938cd5  83e0fe                            and    eax,0xfffffffe
00938cd8  a3e81efe00                        mov    ds:0xfe1ee8,eax
00938cdd  c3                                ret

[E13_0D] Unwind-map entry for guard clear VA=0xcb6d78 raw=0x8b5378 bytes=8 sha256=beaff3af9c85f855a307d84f0592fa6b7e1730ccb1da91b42ed4df2c7abf60dd
ffffffffd08c9300

[EH13] Installed function EH handler VA=0x938cde raw=0x5380de bytes=27 sha256=d9529ac02714f76d295de9c48ef06424cd2d2dc1e9c692e8548dcf64241b257c
00938cde  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00938ce2  8d420c                            lea    eax,[edx+0xc]
00938ce5  8b4af0                            mov    ecx,DWORD PTR [edx-0x10]
00938ce8  33c8                              xor    ecx,eax
00938cea  e81283f5ff                        call   0x891001
00938cef  b8806dcb00                        mov    eax,0xcb6d80
00938cf4  e9b94af6ff                        jmp    0x89d7b2

[EH13I] Compiler function EH info VA=0xcb6d80 raw=0x8b5380 bytes=36 sha256=fdbdf3fae40920376246ffb712bd18fe83d24dc1980d346448c2ac14823c6841
2205931901000000786dcb00000000000000000000000000000000000000000001000000

[EH13P] Caller installs EH handler in FS chain VA=0x55d5e0 raw=0x15c9e0 bytes=37 sha256=6bc825cc65cf2830f63f8ba2d89e3b7c64bec317f14e0d84fa44358d94a89ae7
0055d5e0  55                                push   ebp
0055d5e1  8bec                              mov    ebp,esp
0055d5e3  6aff                              push   0xffffffff
0055d5e5  68de8c9300                        push   0x938cde
0055d5ea  64a100000000                      mov    eax,fs:0x0
0055d5f0  50                                push   eax
0055d5f1  51                                push   ecx
0055d5f2  56                                push   esi
0055d5f3  57                                push   edi
0055d5f4  a1201fd600                        mov    eax,ds:0xd61f20
0055d5f9  33c5                              xor    eax,ebp
0055d5fb  50                                push   eax
0055d5fc  8d45f4                            lea    eax,[ebp-0xc]
0055d5ff  64a300000000                      mov    fs:0x0,eax

[E14_0] Exception unwind clears singleton initialization guard VA=0x944eb0 raw=0x5442b0 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
00944eb0  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00944eb5  83e0fe                            and    eax,0xfffffffe
00944eb8  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
00944ebd  c3                                ret

[E14_0D] Unwind-map entry for guard clear VA=0xcc0a88 raw=0x8bf088 bytes=8 sha256=89eb7ea032ac05ea5301ad14012d04efeb160e1b0203cc4e83dec0401e88f584
ffffffffb04e9400

[EH14] Installed function EH handler VA=0x944ebe raw=0x5442be bytes=27 sha256=ea1c0980c14307b0b9a872c56502ad57c13c2796aadbc8502a7ff45f90d11c56
00944ebe  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00944ec2  8d420c                            lea    eax,[edx+0xc]
00944ec5  8b4af4                            mov    ecx,DWORD PTR [edx-0xc]
00944ec8  33c8                              xor    ecx,eax
00944eca  e832c1f4ff                        call   0x891001
00944ecf  b8900acc00                        mov    eax,0xcc0a90
00944ed4  e9d988f5ff                        jmp    0x89d7b2

[EH14I] Compiler function EH info VA=0xcc0a90 raw=0x8bf090 bytes=36 sha256=e0df425a57ba57866d119423e3a7a6cad00f872f47674ab006eba64088e56d20
2205931901000000880acc00000000000000000000000000000000000000000001000000

[EH14P] Caller installs EH handler in FS chain VA=0x55e680 raw=0x15da80 bytes=37 sha256=9753c5452227196030135bac0c686d7bb338107d720a12780ad617b22de774cd
0055e680  55                                push   ebp
0055e681  8bec                              mov    ebp,esp
0055e683  6aff                              push   0xffffffff
0055e685  68be4e9400                        push   0x944ebe
0055e68a  64a100000000                      mov    eax,fs:0x0
0055e690  50                                push   eax
0055e691  83ec08                            sub    esp,0x8
0055e694  a1201fd600                        mov    eax,ds:0xd61f20
0055e699  33c5                              xor    eax,ebp
0055e69b  50                                push   eax
0055e69c  8d45f4                            lea    eax,[ebp-0xc]
0055e69f  64a300000000                      mov    fs:0x0,eax

[E15_3] Exception unwind clears singleton initialization guard VA=0x93a837 raw=0x539c37 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a837  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a83c  83e0fe                            and    eax,0xfffffffe
0093a83f  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a844  c3                                ret

[E15_3D] Unwind-map entry for guard clear VA=0xcb8440 raw=0x8b6a40 bytes=8 sha256=13cfe26d0e71e242f6902d9de6f280e3653ad62bc6f36628c3a493db9cd28355
0100000037a89300

[EH15] Installed function EH handler VA=0x93a845 raw=0x539c45 bytes=40 sha256=061711acfe74aa62cf635ffaf513c5356cbdbbfac37bf1cbb14b32037d6c84d1
0093a845  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a849  8d420c                            lea    eax,[edx+0xc]
0093a84c  8b8a74ffffff                      mov    ecx,DWORD PTR [edx-0x8c]
0093a852  33c8                              xor    ecx,eax
0093a854  e8a867f5ff                        call   0x891001
0093a859  8b4afc                            mov    ecx,DWORD PTR [edx-0x4]
0093a85c  33c8                              xor    ecx,eax
0093a85e  e89e67f5ff                        call   0x891001
0093a863  b84884cb00                        mov    eax,0xcb8448
0093a868  e9452ff6ff                        jmp    0x89d7b2

[EH15I] Compiler function EH info VA=0xcb8448 raw=0x8b6a48 bytes=36 sha256=eca0a5efb371ffccc04706cc7431341a3ae60fec1cf1a6c93cb7604b375fb199
22059319040000002884cb00000000000000000000000000000000000000000001000000

[EH15P] Caller installs EH handler in FS chain VA=0x55ee90 raw=0x15e290 bytes=45 sha256=6f04bef0991fdf71665b15686ab3648e57853efb42f2bb48316aff3f8878b09e
0055ee90  55                                push   ebp
0055ee91  8bec                              mov    ebp,esp
0055ee93  6aff                              push   0xffffffff
0055ee95  6845a89300                        push   0x93a845
0055ee9a  64a100000000                      mov    eax,fs:0x0
0055eea0  50                                push   eax
0055eea1  81ec80000000                      sub    esp,0x80
0055eea7  a1201fd600                        mov    eax,ds:0xd61f20
0055eeac  33c5                              xor    eax,ebp
0055eeae  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0055eeb1  53                                push   ebx
0055eeb2  56                                push   esi
0055eeb3  50                                push   eax
0055eeb4  8d45f4                            lea    eax,[ebp-0xc]
0055eeb7  64a300000000                      mov    fs:0x0,eax

[E16_0] Exception unwind clears singleton initialization guard VA=0x93fc10 raw=0x53f010 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093fc10  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093fc15  83e0fe                            and    eax,0xfffffffe
0093fc18  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093fc1d  c3                                ret

[E16_0D] Unwind-map entry for guard clear VA=0xcbc930 raw=0x8baf30 bytes=8 sha256=d3a175088666cec098e342a853ce42098d84e7eee75ffc41565ad7f2e429d564
ffffffff10fc9300

[E16_4] Exception unwind clears singleton initialization guard VA=0x93fc48 raw=0x53f048 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093fc48  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093fc4d  83e0fe                            and    eax,0xfffffffe
0093fc50  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093fc55  c3                                ret

[E16_4D] Unwind-map entry for guard clear VA=0xcbc950 raw=0x8baf50 bytes=8 sha256=4b4d45eaa8e75449bf5ebe181ed3ff20accb0137b00d4b608b8d6abd66fb2d37
ffffffff48fc9300

[EH16] Installed function EH handler VA=0x93fc64 raw=0x53f064 bytes=27 sha256=08cddc82faf4c6f8660ee783378a612102e7ce571da9f6eaa90e1f3798f71370
0093fc64  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093fc68  8d42e4                            lea    eax,[edx-0x1c]
0093fc6b  8b4ae0                            mov    ecx,DWORD PTR [edx-0x20]
0093fc6e  33c8                              xor    ecx,eax
0093fc70  e88c13f5ff                        call   0x891001
0093fc75  b860c9cb00                        mov    eax,0xcbc960
0093fc7a  e933dbf5ff                        jmp    0x89d7b2

[EH16I] Compiler function EH info VA=0xcbc960 raw=0x8baf60 bytes=36 sha256=7c126d5cf370d683d2dfe098c24599c00cb856d94e6b371f4ee8fc0b37be610e
220593190600000030c9cb00000000000000000000000000000000000000000001000000

[EH16P] Caller installs EH handler in FS chain VA=0x561db0 raw=0x1611b0 bytes=44 sha256=a37d0e4b8df26afd9529b106c580b8630e77672de1ed41fe647a8ecbdab280a9
00561db0  55                                push   ebp
00561db1  8bec                              mov    ebp,esp
00561db3  83e4f8                            and    esp,0xfffffff8
00561db6  6aff                              push   0xffffffff
00561db8  6864fc9300                        push   0x93fc64
00561dbd  64a100000000                      mov    eax,fs:0x0
00561dc3  50                                push   eax
00561dc4  83ec10                            sub    esp,0x10
00561dc7  53                                push   ebx
00561dc8  56                                push   esi
00561dc9  57                                push   edi
00561dca  a1201fd600                        mov    eax,ds:0xd61f20
00561dcf  33c4                              xor    eax,esp
00561dd1  50                                push   eax
00561dd2  8d442420                          lea    eax,[esp+0x20]
00561dd6  64a300000000                      mov    fs:0x0,eax

[E17_3] Exception unwind clears singleton initialization guard VA=0x943cda raw=0x5430da bytes=14 sha256=efee3200999decb7b44b8704c0c214cda2a60c19cd1940625db35c777af538ba
00943cda  a1e81efe00                        mov    eax,ds:0xfe1ee8
00943cdf  83e0fe                            and    eax,0xfffffffe
00943ce2  a3e81efe00                        mov    ds:0xfe1ee8,eax
00943ce7  c3                                ret

[E17_3D] Unwind-map entry for guard clear VA=0xcbfbd0 raw=0x8be1d0 bytes=8 sha256=b1840c4f87e2baafdb56d1536fb74f4adcd9a557bab37fd50424a9cfc5b32922
ffffffffda3c9400

[EH17] Installed function EH handler VA=0x943d60 raw=0x543160 bytes=40 sha256=188b91c1967bd18a61b8f0ae8107358d3e078d8c3143bd2166424e5d26f8c986
00943d60  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00943d64  8d42cc                            lea    eax,[edx-0x34]
00943d67  8b4ac8                            mov    ecx,DWORD PTR [edx-0x38]
00943d6a  33c8                              xor    ecx,eax
00943d6c  e890d2f4ff                        call   0x891001
00943d71  83c00c                            add    eax,0xc
00943d74  8b4af8                            mov    ecx,DWORD PTR [edx-0x8]
00943d77  33c8                              xor    ecx,eax
00943d79  e883d2f4ff                        call   0x891001
00943d7e  b820fccb00                        mov    eax,0xcbfc20
00943d83  e92a9af5ff                        jmp    0x89d7b2

[EH17I] Compiler function EH info VA=0xcbfc20 raw=0x8be220 bytes=36 sha256=be64bb5aff4f45c9ec53b2b5f10cdcb259e5579207dc7249fae612a619abd412
220593190d000000b8fbcb00000000000000000000000000000000000000000001000000

[EH17P] Caller installs EH handler in FS chain VA=0x5624b0 raw=0x1618b0 bytes=55 sha256=dce8bce77f89cf5c06ce6381ba826ee33cfd989b51bdcf46ec7c6bb7b8ee98e0
005624b0  55                                push   ebp
005624b1  8bec                              mov    ebp,esp
005624b3  83e4f8                            and    esp,0xfffffff8
005624b6  6aff                              push   0xffffffff
005624b8  68603d9400                        push   0x943d60
005624bd  64a100000000                      mov    eax,fs:0x0
005624c3  50                                push   eax
005624c4  83ec28                            sub    esp,0x28
005624c7  a1201fd600                        mov    eax,ds:0xd61f20
005624cc  33c4                              xor    eax,esp
005624ce  89442420                          mov    DWORD PTR [esp+0x20],eax
005624d2  53                                push   ebx
005624d3  56                                push   esi
005624d4  57                                push   edi
005624d5  a1201fd600                        mov    eax,ds:0xd61f20
005624da  33c4                              xor    eax,esp
005624dc  50                                push   eax
005624dd  8d442438                          lea    eax,[esp+0x38]
005624e1  64a300000000                      mov    fs:0x0,eax

[E18_6] Exception unwind clears singleton initialization guard VA=0x93fbbe raw=0x53efbe bytes=14 sha256=efee3200999decb7b44b8704c0c214cda2a60c19cd1940625db35c777af538ba
0093fbbe  a1e81efe00                        mov    eax,ds:0xfe1ee8
0093fbc3  83e0fe                            and    eax,0xfffffffe
0093fbc6  a3e81efe00                        mov    ds:0xfe1ee8,eax
0093fbcb  c3                                ret

[E18_6D] Unwind-map entry for guard clear VA=0xcbc8f0 raw=0x8baef0 bytes=8 sha256=8e902f23e19de8e7db0c94835dcdd1946b51e3d4c850161cf7b438b8e0f8bcad
05000000befb9300

[EH18] Installed function EH handler VA=0x93fbe8 raw=0x53efe8 bytes=40 sha256=c7113e071ea60b865950ba565ed5db3d71e42fd406a189d3c32676b92040b6a9
0093fbe8  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093fbec  8d42c4                            lea    eax,[edx-0x3c]
0093fbef  8b4ac0                            mov    ecx,DWORD PTR [edx-0x40]
0093fbf2  33c8                              xor    ecx,eax
0093fbf4  e80814f5ff                        call   0x891001
0093fbf9  83c008                            add    eax,0x8
0093fbfc  8b4af8                            mov    ecx,DWORD PTR [edx-0x8]
0093fbff  33c8                              xor    ecx,eax
0093fc01  e8fb13f5ff                        call   0x891001
0093fc06  b808c9cb00                        mov    eax,0xcbc908
0093fc0b  e9a2dbf5ff                        jmp    0x89d7b2

[EH18I] Compiler function EH info VA=0xcbc908 raw=0x8baf08 bytes=36 sha256=46e41749734eaedc934ecc68e9604fc7f89af226c37b60c920ec7a54271b03c4
2205931909000000c0c8cb00000000000000000000000000000000000000000001000000

[EH18P] Caller installs EH handler in FS chain VA=0x565720 raw=0x164b20 bytes=54 sha256=7623c5704363c744ff912879f0853d9884f5a6d3523997773589bdc14c3394b4
00565720  55                                push   ebp
00565721  8bec                              mov    ebp,esp
00565723  83e4f8                            and    esp,0xfffffff8
00565726  6aff                              push   0xffffffff
00565728  68e8fb9300                        push   0x93fbe8
0056572d  64a100000000                      mov    eax,fs:0x0
00565733  50                                push   eax
00565734  83ec34                            sub    esp,0x34
00565737  a1201fd600                        mov    eax,ds:0xd61f20
0056573c  33c4                              xor    eax,esp
0056573e  8944242c                          mov    DWORD PTR [esp+0x2c],eax
00565742  53                                push   ebx
00565743  57                                push   edi
00565744  a1201fd600                        mov    eax,ds:0xd61f20
00565749  33c4                              xor    eax,esp
0056574b  50                                push   eax
0056574c  8d442440                          lea    eax,[esp+0x40]
00565750  64a300000000                      mov    fs:0x0,eax

[E19_0] Exception unwind clears singleton initialization guard VA=0x947350 raw=0x546750 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
00947350  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00947355  83e0fe                            and    eax,0xfffffffe
00947358  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0094735d  c3                                ret

[E19_0D] Unwind-map entry for guard clear VA=0xcc27f8 raw=0x8c0df8 bytes=8 sha256=b6f6f3abbed24fe4a22e441e8cc3a1e45c7a01e97a9601baf4ee7949dce68bfa
ffffffff50739400

[EH19] Installed function EH handler VA=0x94736c raw=0x54676c bytes=27 sha256=5b9cfbcc5ac295a7341fdf5b26626abecdb06675fc9160d840156036fe1dfab9
0094736c  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00947370  8d420c                            lea    eax,[edx+0xc]
00947373  8b4af8                            mov    ecx,DWORD PTR [edx-0x8]
00947376  33c8                              xor    ecx,eax
00947378  e8849cf4ff                        call   0x891001
0094737d  b80828cc00                        mov    eax,0xcc2808
00947382  e92b64f5ff                        jmp    0x89d7b2

[EH19I] Compiler function EH info VA=0xcc2808 raw=0x8c0e08 bytes=36 sha256=5959821b7290d4862f0617013e77c5cf1b807761005536b01aa15efb395ecc53
2205931902000000f827cc00000000000000000000000000000000000000000001000000

[EH19P] Caller installs EH handler in FS chain VA=0x5b96e0 raw=0x1b8ae0 bytes=35 sha256=49bc6c6bfbfad59f5e727c768aa0029729f5193bd22bab287496fd7a5bd036b6
005b96e0  55                                push   ebp
005b96e1  8bec                              mov    ebp,esp
005b96e3  6aff                              push   0xffffffff
005b96e5  686c739400                        push   0x94736c
005b96ea  64a100000000                      mov    eax,fs:0x0
005b96f0  50                                push   eax
005b96f1  53                                push   ebx
005b96f2  a1201fd600                        mov    eax,ds:0xd61f20
005b96f7  33c5                              xor    eax,ebp
005b96f9  50                                push   eax
005b96fa  8d45f4                            lea    eax,[ebp-0xc]
005b96fd  64a300000000                      mov    fs:0x0,eax

[E20_0] Exception unwind clears singleton initialization guard VA=0x947350 raw=0x546750 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
00947350  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00947355  83e0fe                            and    eax,0xfffffffe
00947358  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0094735d  c3                                ret

[E20_0D] Unwind-map entry for guard clear VA=0xcc27f8 raw=0x8c0df8 bytes=8 sha256=b6f6f3abbed24fe4a22e441e8cc3a1e45c7a01e97a9601baf4ee7949dce68bfa
ffffffff50739400

[EH20] Installed function EH handler VA=0x94736c raw=0x54676c bytes=27 sha256=5b9cfbcc5ac295a7341fdf5b26626abecdb06675fc9160d840156036fe1dfab9
0094736c  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00947370  8d420c                            lea    eax,[edx+0xc]
00947373  8b4af8                            mov    ecx,DWORD PTR [edx-0x8]
00947376  33c8                              xor    ecx,eax
00947378  e8849cf4ff                        call   0x891001
0094737d  b80828cc00                        mov    eax,0xcc2808
00947382  e92b64f5ff                        jmp    0x89d7b2

[EH20I] Compiler function EH info VA=0xcc2808 raw=0x8c0e08 bytes=36 sha256=5959821b7290d4862f0617013e77c5cf1b807761005536b01aa15efb395ecc53
2205931902000000f827cc00000000000000000000000000000000000000000001000000

[EH20P] Caller installs EH handler in FS chain VA=0x5c3610 raw=0x1c2a10 bytes=35 sha256=49bc6c6bfbfad59f5e727c768aa0029729f5193bd22bab287496fd7a5bd036b6
005c3610  55                                push   ebp
005c3611  8bec                              mov    ebp,esp
005c3613  6aff                              push   0xffffffff
005c3615  686c739400                        push   0x94736c
005c361a  64a100000000                      mov    eax,fs:0x0
005c3620  50                                push   eax
005c3621  53                                push   ebx
005c3622  a1201fd600                        mov    eax,ds:0xd61f20
005c3627  33c5                              xor    eax,ebp
005c3629  50                                push   eax
005c362a  8d45f4                            lea    eax,[ebp-0xc]
005c362d  64a300000000                      mov    fs:0x0,eax

[E21_1] Exception unwind clears singleton initialization guard VA=0x94608e raw=0x54548e bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0094608e  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
00946093  83e0fe                            and    eax,0xfffffffe
00946096  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0094609b  c3                                ret

[E21_1D] Unwind-map entry for guard clear VA=0xcc1900 raw=0x8bff00 bytes=8 sha256=9561ca7038d05e0ab0dffed7a226803eecffc86ac9e37c480b1d83001c4b5b61
ffffffff8e609400

[EH21] Installed function EH handler VA=0x946110 raw=0x545510 bytes=40 sha256=708708f4b443043564438f23d7925a43dae949d5333a4b23e69015c0b1d7aafb
00946110  8b542408                          mov    edx,DWORD PTR [esp+0x8]
00946114  8d42a4                            lea    eax,[edx-0x5c]
00946117  8b4aa0                            mov    ecx,DWORD PTR [edx-0x60]
0094611a  33c8                              xor    ecx,eax
0094611c  e8e0aef4ff                        call   0x891001
00946121  83c00c                            add    eax,0xc
00946124  8b4af8                            mov    ecx,DWORD PTR [edx-0x8]
00946127  33c8                              xor    ecx,eax
00946129  e8d3aef4ff                        call   0x891001
0094612e  b85819cc00                        mov    eax,0xcc1958
00946133  e97a76f5ff                        jmp    0x89d7b2

[EH21I] Compiler function EH info VA=0xcc1958 raw=0x8bff58 bytes=36 sha256=8a26d7a3f5ad2c22ea0b31ff5de0a6586dc46a58be1c7ed35c39ce904caae6bf
220593190c000000f818cc00000000000000000000000000000000000000000001000000

[EH21P] Caller installs EH handler in FS chain VA=0x672f00 raw=0x272300 bytes=55 sha256=ebbc841f011276ee478ca240b5003dc54a8a50934a53181fe8d908ffaaff71d6
00672f00  55                                push   ebp
00672f01  8bec                              mov    ebp,esp
00672f03  83e4f8                            and    esp,0xfffffff8
00672f06  6aff                              push   0xffffffff
00672f08  6810619400                        push   0x946110
00672f0d  64a100000000                      mov    eax,fs:0x0
00672f13  50                                push   eax
00672f14  83ec50                            sub    esp,0x50
00672f17  a1201fd600                        mov    eax,ds:0xd61f20
00672f1c  33c4                              xor    eax,esp
00672f1e  89442448                          mov    DWORD PTR [esp+0x48],eax
00672f22  53                                push   ebx
00672f23  56                                push   esi
00672f24  57                                push   edi
00672f25  a1201fd600                        mov    eax,ds:0xd61f20
00672f2a  33c4                              xor    eax,esp
00672f2c  50                                push   eax
00672f2d  8d442460                          lea    eax,[esp+0x60]
00672f31  64a300000000                      mov    fs:0x0,eax

[E22_1] Exception unwind clears singleton initialization guard VA=0x93a7a8 raw=0x539ba8 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a7a8  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a7ad  83e0fe                            and    eax,0xfffffffe
0093a7b0  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a7b5  c3                                ret

[E22_1D] Unwind-map entry for guard clear VA=0xcb83c0 raw=0x8b69c0 bytes=8 sha256=c7efe8843d7e1f20d4bff32eb693f77c4506a9a5a38fa8ad7917952616d0c3a2
00000000a8a79300

[EH22] Installed function EH handler VA=0x93a7b6 raw=0x539bb6 bytes=27 sha256=9b07ff9177c589d1617bf48bd9221c9638a7a339c0dab0ca749f558e4378eae6
0093a7b6  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a7ba  8d420c                            lea    eax,[edx+0xc]
0093a7bd  8b4af0                            mov    ecx,DWORD PTR [edx-0x10]
0093a7c0  33c8                              xor    ecx,eax
0093a7c2  e83a68f5ff                        call   0x891001
0093a7c7  b8c883cb00                        mov    eax,0xcb83c8
0093a7cc  e9e12ff6ff                        jmp    0x89d7b2

[EH22I] Compiler function EH info VA=0xcb83c8 raw=0x8b69c8 bytes=36 sha256=5b4e19d6f765c9752885309716bdba435910ddcaf42659884e728c91c89bdd7e
2205931902000000b883cb00000000000000000000000000000000000000000001000000

[EH22P] Caller installs EH handler in FS chain VA=0x6bce70 raw=0x2bc270 bytes=37 sha256=81856e5394d3c01ee9869aedf56cb75a2b47d263cf0a2699bdaeb5bdc0174b26
006bce70  55                                push   ebp
006bce71  8bec                              mov    ebp,esp
006bce73  6aff                              push   0xffffffff
006bce75  68b6a79300                        push   0x93a7b6
006bce7a  64a100000000                      mov    eax,fs:0x0
006bce80  50                                push   eax
006bce81  51                                push   ecx
006bce82  53                                push   ebx
006bce83  56                                push   esi
006bce84  a1201fd600                        mov    eax,ds:0xd61f20
006bce89  33c5                              xor    eax,ebp
006bce8b  50                                push   eax
006bce8c  8d45f4                            lea    eax,[ebp-0xc]
006bce8f  64a300000000                      mov    fs:0x0,eax

[E23_1] Exception unwind clears singleton initialization guard VA=0x93a7a8 raw=0x539ba8 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a7a8  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a7ad  83e0fe                            and    eax,0xfffffffe
0093a7b0  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a7b5  c3                                ret

[E23_1D] Unwind-map entry for guard clear VA=0xcb83c0 raw=0x8b69c0 bytes=8 sha256=c7efe8843d7e1f20d4bff32eb693f77c4506a9a5a38fa8ad7917952616d0c3a2
00000000a8a79300

[EH23] Installed function EH handler VA=0x93a7b6 raw=0x539bb6 bytes=27 sha256=9b07ff9177c589d1617bf48bd9221c9638a7a339c0dab0ca749f558e4378eae6
0093a7b6  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a7ba  8d420c                            lea    eax,[edx+0xc]
0093a7bd  8b4af0                            mov    ecx,DWORD PTR [edx-0x10]
0093a7c0  33c8                              xor    ecx,eax
0093a7c2  e83a68f5ff                        call   0x891001
0093a7c7  b8c883cb00                        mov    eax,0xcb83c8
0093a7cc  e9e12ff6ff                        jmp    0x89d7b2

[EH23I] Compiler function EH info VA=0xcb83c8 raw=0x8b69c8 bytes=36 sha256=5b4e19d6f765c9752885309716bdba435910ddcaf42659884e728c91c89bdd7e
2205931902000000b883cb00000000000000000000000000000000000000000001000000

[EH23P] Caller installs EH handler in FS chain VA=0x6bcf90 raw=0x2bc390 bytes=37 sha256=f9c1b7ff53c8f014e148b268bc971c5ffb66e2315068bdd0eedebd84b562caf9
006bcf90  55                                push   ebp
006bcf91  8bec                              mov    ebp,esp
006bcf93  6aff                              push   0xffffffff
006bcf95  68b6a79300                        push   0x93a7b6
006bcf9a  64a100000000                      mov    eax,fs:0x0
006bcfa0  50                                push   eax
006bcfa1  53                                push   ebx
006bcfa2  56                                push   esi
006bcfa3  57                                push   edi
006bcfa4  a1201fd600                        mov    eax,ds:0xd61f20
006bcfa9  33c5                              xor    eax,ebp
006bcfab  50                                push   eax
006bcfac  8d45f4                            lea    eax,[ebp-0xc]
006bcfaf  64a300000000                      mov    fs:0x0,eax

[E24_1] Exception unwind clears singleton initialization guard VA=0x93a76e raw=0x539b6e bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093a76e  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093a773  83e0fe                            and    eax,0xfffffffe
0093a776  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093a77b  c3                                ret

[E24_1D] Unwind-map entry for guard clear VA=0xcb8388 raw=0x8b6988 bytes=8 sha256=e910ec6cbcf4c5db98af2e0b269320d1a5c43c6c48f8f432d6d38f3fa7bb6483
ffffffff6ea79300

[EH24] Installed function EH handler VA=0x93a77c raw=0x539b7c bytes=27 sha256=72ecf50a98b39ed682e59b03f5d49a07574eae84468f3f4d30902a7003b04a02
0093a77c  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093a780  8d420c                            lea    eax,[edx+0xc]
0093a783  8b4af4                            mov    ecx,DWORD PTR [edx-0xc]
0093a786  33c8                              xor    ecx,eax
0093a788  e87468f5ff                        call   0x891001
0093a78d  b89083cb00                        mov    eax,0xcb8390
0093a792  e91b30f6ff                        jmp    0x89d7b2

[EH24I] Compiler function EH info VA=0xcb8390 raw=0x8b6990 bytes=36 sha256=c47ec27eb02af7e75a664fb3bb226a589b82f930a58efa184280d484424a7063
22059319020000008083cb00000000000000000000000000000000000000000001000000

[EH24P] Caller installs EH handler in FS chain VA=0x6bd720 raw=0x2bcb20 bytes=36 sha256=ebaa90458f0a7a7d042d6a3943b8fd1b385aeabe9c45b5f2730c765069462dc1
006bd720  55                                push   ebp
006bd721  8bec                              mov    ebp,esp
006bd723  6aff                              push   0xffffffff
006bd725  687ca79300                        push   0x93a77c
006bd72a  64a100000000                      mov    eax,fs:0x0
006bd730  50                                push   eax
006bd731  51                                push   ecx
006bd732  56                                push   esi
006bd733  a1201fd600                        mov    eax,ds:0xd61f20
006bd738  33c5                              xor    eax,ebp
006bd73a  50                                push   eax
006bd73b  8d45f4                            lea    eax,[ebp-0xc]
006bd73e  64a300000000                      mov    fs:0x0,eax

[E25_4] Exception unwind clears singleton initialization guard VA=0x93beb2 raw=0x53b2b2 bytes=14 sha256=31e7cff9413378042c23ba15e35c610c5b14f67130a2f71a130c9972ae64a2c8
0093beb2  a1d4f3fd00                        mov    eax,ds:0xfdf3d4
0093beb7  83e0fe                            and    eax,0xfffffffe
0093beba  a3d4f3fd00                        mov    ds:0xfdf3d4,eax
0093bebf  c3                                ret

[E25_4D] Unwind-map entry for guard clear VA=0xcb96f0 raw=0x8b7cf0 bytes=8 sha256=586961bdf4371415a9d46ef3eb4c1208beb312961c6aec5d733169a8c5c1e086
ffffffffb2be9300

[EH25] Installed function EH handler VA=0x93bed0 raw=0x53b2d0 bytes=40 sha256=8eefcdb6ca8ea81b30cfd40b13fae15755a1deb254bdebfb7806aaee3c11722e
0093bed0  8b542408                          mov    edx,DWORD PTR [esp+0x8]
0093bed4  8d4284                            lea    eax,[edx-0x7c]
0093bed7  8b4a80                            mov    ecx,DWORD PTR [edx-0x80]
0093beda  33c8                              xor    ecx,eax
0093bedc  e82051f5ff                        call   0x891001
0093bee1  83c00c                            add    eax,0xc
0093bee4  8b4af8                            mov    ecx,DWORD PTR [edx-0x8]
0093bee7  33c8                              xor    ecx,eax
0093bee9  e81351f5ff                        call   0x891001
0093beee  b80897cb00                        mov    eax,0xcb9708
0093bef3  e9ba18f6ff                        jmp    0x89d7b2

[EH25I] Compiler function EH info VA=0xcb9708 raw=0x8b7d08 bytes=36 sha256=1713a31e0ca85543d82f4a03e1e49c7a95aabe5822776ec441321f64489e78cf
2205931907000000d096cb00000000000000000000000000000000000000000001000000

[EH25P] Caller installs EH handler in FS chain VA=0x6bf310 raw=0x2be710 bytes=58 sha256=037253265fdc79e226118219fea5702e3209e6457675b511302d6116de6476a9
006bf310  55                                push   ebp
006bf311  8bec                              mov    ebp,esp
006bf313  83e4f8                            and    esp,0xfffffff8
006bf316  6aff                              push   0xffffffff
006bf318  68d0be9300                        push   0x93bed0
006bf31d  64a100000000                      mov    eax,fs:0x0
006bf323  50                                push   eax
006bf324  83ec70                            sub    esp,0x70
006bf327  a1201fd600                        mov    eax,ds:0xd61f20
006bf32c  33c4                              xor    eax,esp
006bf32e  89442468                          mov    DWORD PTR [esp+0x68],eax
006bf332  53                                push   ebx
006bf333  56                                push   esi
006bf334  57                                push   edi
006bf335  a1201fd600                        mov    eax,ds:0xd61f20
006bf33a  33c4                              xor    eax,esp
006bf33c  50                                push   eax
006bf33d  8d842480000000                    lea    eax,[esp+0x80]
006bf344  64a300000000                      mov    fs:0x0,eax

[BE1I] Borrowed-wrapper family function EH info VA=0xcb6590 raw=0x8b4b90 bytes=36 sha256=7b59cc823d2f676eb2832d2dd992df24ac0bfdcd220fe09b70b3a64f9afc9237
22059319010000008865cb00000000000000000000000000000000000000000001000000

[BE1U] Borrowed-wrapper family full unwind map VA=0xcb6588 raw=0x8b4b88 bytes=8 sha256=9e08fcb89e02b4bcb652cd89efb7173bfbaf8d2bbd6e8757a86dc2d07f125eba
ffffffffc0839300

[BE2I] Borrowed-wrapper family function EH info VA=0xcb67a0 raw=0x8b4da0 bytes=36 sha256=40d04baabd43b7ffb4df9f52c0e59587dff0f1d729eb78cb1b2692527c9d24b5
22059319010000009867cb00000000000000000000000000000000000000000001000000

[BE2U] Borrowed-wrapper family full unwind map VA=0xcb6798 raw=0x8b4d98 bytes=8 sha256=b89cd7274cf438a8c4c8bb94878615087562f15de2763bca129ea78a0e690fc6
ffffffff30869300

[BE3I] Borrowed-wrapper family function EH info VA=0xcb6918 raw=0x8b4f18 bytes=36 sha256=1066d3723db40b76a0d61b48d4ae0f88b9bbc78695f859629c82833965469a85
22059319010000001069cb00000000000000000000000000000000000000000001000000

[BE3U] Borrowed-wrapper family full unwind map VA=0xcb6910 raw=0x8b4f10 bytes=8 sha256=f1ad9b3385a1b8ba4edc21a32539732c5951d2efbd0c476000439821cdd02097
ffffffffd0879300
