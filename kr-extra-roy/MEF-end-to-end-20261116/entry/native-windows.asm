
; prepass_register 0x55d560..0x55d5de Immediate protected callback; error discarded; no Lua results
0x55d560  55                                push   ebp
0x55d561  8bec                              mov    ebp,esp
0x55d563  83e4f8                            and    esp,0xfffffff8
0x55d566  83ec08                            sub    esp,0x8
0x55d569  56                                push   esi
0x55d56a  57                                push   edi
0x55d56b  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x55d56e  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x55d571  83c0f0                            add    eax,0xfffffff0
0x55d574  3dc8bfc000                        cmp    eax,0xc0bfc8
0x55d579  745b                              je     0x55d5d6
0x55d57b  83780806                          cmp    DWORD PTR [eax+0x8],0x6
0x55d57f  7555                              jne    0x55d5d6
0x55d581  89442408                          mov    DWORD PTR [esp+0x8],eax
0x55d585  2b4720                            sub    eax,DWORD PTR [edi+0x20]
0x55d588  33d2                              xor    edx,edx
0x55d58a  50                                push   eax
0x55d58b  8d44240c                          lea    eax,[esp+0xc]
0x55d58f  50                                push   eax
0x55d590  68505a6f00                        push   0x6f5a50
0x55d595  8bc7                              mov    eax,edi
0x55d597  c744241800000000                  mov    DWORD PTR [esp+0x18],0x0
0x55d59f  e8cc111a00                        call   0x6fe770
0x55d5a4  83c40c                            add    esp,0xc
0x55d5a7  85c0                              test   eax,eax
0x55d5a9  742b                              je     0x55d5d6
0x55d5ab  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x55d5ae  83ee10                            sub    esi,0x10
0x55d5b1  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x55d5b5  741b                              je     0x55d5d2
0x55d5b7  e814e01900                        call   0x6fb5d0
0x55d5bc  85c0                              test   eax,eax
0x55d5be  7412                              je     0x55d5d2
0x55d5c0  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x55d5c3  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x55d5c6  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x55d5c9  7207                              jb     0x55d5d2
0x55d5cb  8bc7                              mov    eax,edi
0x55d5cd  e8cedd1900                        call   0x6fb3a0
0x55d5d2  834708f0                          add    DWORD PTR [edi+0x8],0xfffffff0
0x55d5d6  5f                                pop    edi
0x55d5d7  33c0                              xor    eax,eax
0x55d5d9  5e                                pop    esi
0x55d5da  8be5                              mov    esp,ebp
0x55d5dc  5d                                pop    ebp
0x55d5dd  c3                                ret

; prepass_constructor 0x55c610..0x55c720 Reused independent prepass state construction
0x55c610  55                                push   ebp
0x55c611  8bec                              mov    ebp,esp
0x55c613  6aff                              push   0xffffffff
0x55c615  68a8899300                        push   0x9389a8
0x55c61a  64a100000000                      mov    eax,fs:0x0
0x55c620  50                                push   eax
0x55c621  83ec14                            sub    esp,0x14
0x55c624  53                                push   ebx
0x55c625  a1201fd600                        mov    eax,ds:0xd61f20
0x55c62a  33c5                              xor    eax,ebp
0x55c62c  50                                push   eax
0x55c62d  8d45f4                            lea    eax,[ebp-0xc]
0x55c630  64a300000000                      mov    fs:0x0,eax
0x55c636  33db                              xor    ebx,ebx
0x55c638  6a18                              push   0x18
0x55c63a  c745ecec1efe00                    mov    DWORD PTR [ebp-0x14],0xfe1eec
0x55c641  891dfc1efe00                      mov    DWORD PTR ds:0xfe1efc,ebx
0x55c647  e81c4c3300                        call   0x891268
0x55c64c  83c404                            add    esp,0x4
0x55c64f  3bc3                              cmp    eax,ebx
0x55c651  0f849e000000                      je     0x55c6f5
0x55c657  a3f81efe00                        mov    ds:0xfe1ef8,eax
0x55c65c  8900                              mov    DWORD PTR [eax],eax
0x55c65e  a1f81efe00                        mov    eax,ds:0xfe1ef8
0x55c663  894004                            mov    DWORD PTR [eax+0x4],eax
0x55c666  a1f81efe00                        mov    eax,ds:0xfe1ef8
0x55c66b  894008                            mov    DWORD PTR [eax+0x8],eax
0x55c66e  8b0df81efe00                      mov    ecx,DWORD PTR ds:0xfe1ef8
0x55c674  b001                              mov    al,0x1
0x55c676  884114                            mov    BYTE PTR [ecx+0x14],al
0x55c679  8b15f81efe00                      mov    edx,DWORD PTR ds:0xfe1ef8
0x55c67f  884215                            mov    BYTE PTR [edx+0x15],al
0x55c682  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x55c685  c705181ffe000f000000              mov    DWORD PTR ds:0xfe1f18,0xf
0x55c68f  891d141ffe00                      mov    DWORD PTR ds:0xfe1f14,ebx
0x55c695  881d041ffe00                      mov    BYTE PTR ds:0xfe1f04,bl
0x55c69b  8845fc                            mov    BYTE PTR [ebp-0x4],al
0x55c69e  e80dae1900                        call   0x6f74b0
0x55c6a3  3bc3                              cmp    eax,ebx
0x55c6a5  740a                              je     0x55c6b1
0x55c6a7  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x55c6aa  c74158a0716f00                    mov    DWORD PTR [ecx+0x58],0x6f71a0
0x55c6b1  6a0c                              push   0xc
0x55c6b3  a3ec1efe00                        mov    ds:0xfe1eec,eax
0x55c6b8  e8ab4b3300                        call   0x891268
0x55c6bd  83c404                            add    esp,0x4
0x55c6c0  3bc3                              cmp    eax,ebx
0x55c6c2  7410                              je     0x55c6d4
0x55c6c4  8b15ec1efe00                      mov    edx,DWORD PTR ds:0xfe1eec
0x55c6ca  8910                              mov    DWORD PTR [eax],edx
0x55c6cc  895804                            mov    DWORD PTR [eax+0x4],ebx
0x55c6cf  895808                            mov    DWORD PTR [eax+0x8],ebx
0x55c6d2  eb02                              jmp    0x55c6d6
0x55c6d4  33c0                              xor    eax,eax
0x55c6d6  a3f01efe00                        mov    ds:0xfe1ef0,eax
0x55c6db  e800110000                        call   0x55d7e0
0x55c6e0  b8ec1efe00                        mov    eax,0xfe1eec
0x55c6e5  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x55c6e8  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x55c6ef  59                                pop    ecx
0x55c6f0  5b                                pop    ebx
0x55c6f1  8be5                              mov    esp,ebp
0x55c6f3  5d                                pop    ebp
0x55c6f4  c3                                ret
0x55c6f5  8d45f0                            lea    eax,[ebp-0x10]
0x55c6f8  50                                push   eax
0x55c6f9  8d4de0                            lea    ecx,[ebp-0x20]
0x55c6fc  895df0                            mov    DWORD PTR [ebp-0x10],ebx
0x55c6ff  e8a5493300                        call   0x8910a9
0x55c704  68a857c800                        push   0xc857a8
0x55c709  8d4de0                            lea    ecx,[ebp-0x20]
0x55c70c  51                                push   ecx
0x55c70d  c745e0a42cbd00                    mov    DWORD PTR [ebp-0x20],0xbd2ca4
0x55c714  e8d7023400                        call   0x89c9f0
0x55c719  cc                                int3
0x55c71a  cc                                int3
0x55c71b  cc                                int3
0x55c71c  cc                                int3
0x55c71d  cc                                int3
0x55c71e  cc                                int3
0x55c71f  cc                                int3

; prepass_reload 0x55d6a0..0x55d7d3 Reused reset and six callback bindings; status not a caller gate
0x55d6a0  55                                push   ebp
0x55d6a1  8bec                              mov    ebp,esp
0x55d6a3  51                                push   ecx
0x55d6a4  53                                push   ebx
0x55d6a5  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x55d6a8  56                                push   esi
0x55d6a9  8d4308                            lea    eax,[ebx+0x8]
0x55d6ac  57                                push   edi
0x55d6ad  50                                push   eax
0x55d6ae  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x55d6b1  e82a0c0000                        call   0x55e2e0
0x55d6b6  83c404                            add    esp,0x4
0x55d6b9  6a00                              push   0x0
0x55d6bb  687523bf00                        push   0xbf2375
0x55d6c0  8d4b18                            lea    ecx,[ebx+0x18]
0x55d6c3  e8a853eaff                        call   0x402a70
0x55d6c8  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0x55d6cb  8b30                              mov    esi,DWORD PTR [eax]
0x55d6cd  6a00                              push   0x0
0x55d6cf  6840c95500                        push   0x55c940
0x55d6d4  894508                            mov    DWORD PTR [ebp+0x8],eax
0x55d6d7  e8d47e1900                        call   0x6f55b0
0x55d6dc  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x55d6df  8b31                              mov    esi,DWORD PTR [ecx]
0x55d6e1  bf3002c100                        mov    edi,0xc10230
0x55d6e6  b8eed8ffff                        mov    eax,0xffffd8ee
0x55d6eb  e8a0801900                        call   0x6f5790
0x55d6f0  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0x55d6f3  8b30                              mov    esi,DWORD PTR [eax]
0x55d6f5  6a00                              push   0x0
0x55d6f7  68e0cc5500                        push   0x55cce0
0x55d6fc  894508                            mov    DWORD PTR [ebp+0x8],eax
0x55d6ff  e8ac7e1900                        call   0x6f55b0
0x55d704  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x55d707  8b32                              mov    esi,DWORD PTR [edx]
0x55d709  bf4002c100                        mov    edi,0xc10240
0x55d70e  b8eed8ffff                        mov    eax,0xffffd8ee
0x55d713  e878801900                        call   0x6f5790
0x55d718  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0x55d71b  8b30                              mov    esi,DWORD PTR [eax]
0x55d71d  6a00                              push   0x0
0x55d71f  68d0ce5500                        push   0x55ced0
0x55d724  894508                            mov    DWORD PTR [ebp+0x8],eax
0x55d727  e8847e1900                        call   0x6f55b0
0x55d72c  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x55d72f  8b31                              mov    esi,DWORD PTR [ecx]
0x55d731  bf4c02c100                        mov    edi,0xc1024c
0x55d736  b8eed8ffff                        mov    eax,0xffffd8ee
0x55d73b  e850801900                        call   0x6f5790
0x55d740  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0x55d743  8b30                              mov    esi,DWORD PTR [eax]
0x55d745  6a00                              push   0x0
0x55d747  6820d25500                        push   0x55d220
0x55d74c  894508                            mov    DWORD PTR [ebp+0x8],eax
0x55d74f  e85c7e1900                        call   0x6f55b0
0x55d754  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x55d757  8b32                              mov    esi,DWORD PTR [edx]
0x55d759  bf5802c100                        mov    edi,0xc10258
0x55d75e  b8eed8ffff                        mov    eax,0xffffd8ee
0x55d763  e828801900                        call   0x6f5790
0x55d768  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0x55d76b  8b30                              mov    esi,DWORD PTR [eax]
0x55d76d  6a00                              push   0x0
0x55d76f  6860d55500                        push   0x55d560
0x55d774  894508                            mov    DWORD PTR [ebp+0x8],eax
0x55d777  e8347e1900                        call   0x6f55b0
0x55d77c  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x55d77f  8b31                              mov    esi,DWORD PTR [ecx]
0x55d781  bf6402c100                        mov    edi,0xc10264
0x55d786  b8eed8ffff                        mov    eax,0xffffd8ee
0x55d78b  e800801900                        call   0x6f5790
0x55d790  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0x55d793  8b30                              mov    esi,DWORD PTR [eax]
0x55d795  6a00                              push   0x0
0x55d797  68e0d55500                        push   0x55d5e0
0x55d79c  894508                            mov    DWORD PTR [ebp+0x8],eax
0x55d79f  e80c7e1900                        call   0x6f55b0
0x55d7a4  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x55d7a7  8b32                              mov    esi,DWORD PTR [edx]
0x55d7a9  83c430                            add    esp,0x30
0x55d7ac  bf7002c100                        mov    edi,0xc10270
0x55d7b1  b8eed8ffff                        mov    eax,0xffffd8ee
0x55d7b6  e8d57f1900                        call   0x6f5790
0x55d7bb  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x55d7be  8b4b04                            mov    ecx,DWORD PTR [ebx+0x4]
0x55d7c1  50                                push   eax
0x55d7c2  e889721900                        call   0x6f4a50
0x55d7c7  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x55d7ca  5f                                pop    edi
0x55d7cb  5e                                pop    esi
0x55d7cc  5b                                pop    ebx
0x55d7cd  8be5                              mov    esp,ebp
0x55d7cf  5d                                pop    ebp
0x55d7d0  c20800                            ret    0x8

; formal_constructor 0x6f4380..0x6f440e Reused main VM/openlibs and DoFile binding
0x6f4380  51                                push   ecx
0x6f4381  56                                push   esi
0x6f4382  57                                push   edi
0x6f4383  e828310000                        call   0x6f74b0
0x6f4388  85c0                              test   eax,eax
0x6f438a  740a                              je     0x6f4396
0x6f438c  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x6f438f  c74158a0716f00                    mov    DWORD PTR [ecx+0x58],0x6f71a0
0x6f4396  a3c8f3fd00                        mov    ds:0xfdf3c8,eax
0x6f439b  c705ccf3fd0000000000              mov    DWORD PTR ds:0xfdf3cc,0x0
0x6f43a5  c705d0f3fd0001000000              mov    DWORD PTR ds:0xfdf3d0,0x1
0x6f43af  e8ac320000                        call   0x6f7660
0x6f43b4  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8
0x6f43ba  6a00                              push   0x0
0x6f43bc  6820446f00                        push   0x6f4420
0x6f43c1  e8ea110000                        call   0x6f55b0
0x6f43c6  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8
0x6f43cc  bf7c25c400                        mov    edi,0xc4257c
0x6f43d1  b8eed8ffff                        mov    eax,0xffffd8ee
0x6f43d6  e8b5130000                        call   0x6f5790
0x6f43db  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8
0x6f43e1  6a00                              push   0x0
0x6f43e3  68a0486f00                        push   0x6f48a0
0x6f43e8  e8c3110000                        call   0x6f55b0
0x6f43ed  8b35c8f3fd00                      mov    esi,DWORD PTR ds:0xfdf3c8
0x6f43f3  83c410                            add    esp,0x10
0x6f43f6  bf9025c400                        mov    edi,0xc42590
0x6f43fb  b8eed8ffff                        mov    eax,0xffffd8ee
0x6f4400  e88b130000                        call   0x6f5790
0x6f4405  5f                                pop    edi
0x6f4406  b8c8f3fd00                        mov    eax,0xfdf3c8
0x6f440b  5e                                pop    esi
0x6f440c  59                                pop    ecx
0x6f440d  c3                                ret

; open_libraries 0x6f7660..0x6f7704 Actual library opener dispatch
0x6f7660  55                                push   ebp
0x6f7661  8bec                              mov    ebp,esp
0x6f7663  83ec0c                            sub    esp,0xc
0x6f7666  833ddcc0c00000                    cmp    DWORD PTR ds:0xc0c0dc,0x0
0x6f766d  53                                push   ebx
0x6f766e  56                                push   esi
0x6f766f  57                                push   edi
0x6f7670  8bf0                              mov    esi,eax
0x6f7672  0f8485000000                      je     0x6f76fd
0x6f7678  bfdcc0c000                        mov    edi,0xc0c0dc
0x6f767d  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x6f7680  8b07                              mov    eax,DWORD PTR [edi]
0x6f7682  6a00                              push   0x0
0x6f7684  50                                push   eax
0x6f7685  e826dfffff                        call   0x6f55b0
0x6f768a  8b5ffc                            mov    ebx,DWORD PTR [edi-0x4]
0x6f768d  83c408                            add    esp,0x8
0x6f7690  85db                              test   ebx,ebx
0x6f7692  7508                              jne    0x6f769c
0x6f7694  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6f7697  895908                            mov    DWORD PTR [ecx+0x8],ebx
0x6f769a  eb40                              jmp    0x6f76dc
0x6f769c  8bc3                              mov    eax,ebx
0x6f769e  8d5001                            lea    edx,[eax+0x1]
0x6f76a1  8a08                              mov    cl,BYTE PTR [eax]
0x6f76a3  40                                inc    eax
0x6f76a4  84c9                              test   cl,cl
0x6f76a6  75f9                              jne    0x6f76a1
0x6f76a8  2bc2                              sub    eax,edx
0x6f76aa  8945f8                            mov    DWORD PTR [ebp-0x8],eax
0x6f76ad  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x6f76b0  8b5044                            mov    edx,DWORD PTR [eax+0x44]
0x6f76b3  3b5040                            cmp    edx,DWORD PTR [eax+0x40]
0x6f76b6  7207                              jb     0x6f76bf
0x6f76b8  8bc6                              mov    eax,esi
0x6f76ba  e8e13c0000                        call   0x6fb3a0
0x6f76bf  8b45f8                            mov    eax,DWORD PTR [ebp-0x8]
0x6f76c2  8b7e08                            mov    edi,DWORD PTR [esi+0x8]
0x6f76c5  50                                push   eax
0x6f76c6  53                                push   ebx
0x6f76c7  56                                push   esi
0x6f76c8  e8a3750000                        call   0x6fec70
0x6f76cd  8907                              mov    DWORD PTR [edi],eax
0x6f76cf  c7470804000000                    mov    DWORD PTR [edi+0x8],0x4
0x6f76d6  8b7dfc                            mov    edi,DWORD PTR [ebp-0x4]
0x6f76d9  83c40c                            add    esp,0xc
0x6f76dc  83460810                          add    DWORD PTR [esi+0x8],0x10
0x6f76e0  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6f76e3  6a00                              push   0x0
0x6f76e5  83c0e0                            add    eax,0xffffffe0
0x6f76e8  50                                push   eax
0x6f76e9  56                                push   esi
0x6f76ea  e8616e0000                        call   0x6fe550
0x6f76ef  83c708                            add    edi,0x8
0x6f76f2  83c40c                            add    esp,0xc
0x6f76f5  833f00                            cmp    DWORD PTR [edi],0x0
0x6f76f8  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x6f76fb  7583                              jne    0x6f7680
0x6f76fd  5f                                pop    edi
0x6f76fe  5e                                pop    esi
0x6f76ff  5b                                pop    ebx
0x6f7700  8be5                              mov    esp,ebp
0x6f7702  5d                                pop    ebp
0x6f7703  c3                                ret

; open_table_library 0x70cbf0..0x70cc0f table library registered through original native table
0x70cbf0  55                                push   ebp
0x70cbf1  8bec                              mov    ebp,esp
0x70cbf3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x70cbf6  6868b9c000                        push   0xc0b968
0x70cbfb  688428c400                        push   0xc42884
0x70cc00  e88b99feff                        call   0x6f6590
0x70cc05  83c408                            add    esp,0x8
0x70cc08  b801000000                        mov    eax,0x1
0x70cc0d  5d                                pop    ebp
0x70cc0e  c3                                ret

; open_coroutine_library 0x707790..0x7077ba coroutine standard binding table
0x707790  55                                push   ebp
0x707791  8bec                              mov    ebp,esp
0x707793  56                                push   esi
0x707794  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x707797  8bc6                              mov    eax,esi
0x707799  e8e2fdffff                        call   0x707580
0x70779e  6868bcc000                        push   0xc0bc68
0x7077a3  684837c400                        push   0xc43748
0x7077a8  8bc6                              mov    eax,esi
0x7077aa  e8e1edfeff                        call   0x6f6590
0x7077af  83c408                            add    esp,0x8
0x7077b2  b802000000                        mov    eax,0x2
0x7077b7  5e                                pop    esi
0x7077b8  5d                                pop    ebp
0x7077b9  c3                                ret

; coroutine_create 0x707380..0x707444 Lua closure validation; copies same closure TValue into new thread
0x707380  55                                push   ebp
0x707381  8bec                              mov    ebp,esp
0x707383  53                                push   ebx
0x707384  56                                push   esi
0x707385  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x707388  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x70738b  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x70738e  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x707391  7207                              jb     0x70739a
0x707393  8bc6                              mov    eax,esi
0x707395  e80640ffff                        call   0x6fb3a0
0x70739a  8bc6                              mov    eax,esi
0x70739c  e8effffeff                        call   0x6f7390
0x7073a1  8bd8                              mov    ebx,eax
0x7073a3  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x7073a6  8918                              mov    DWORD PTR [eax],ebx
0x7073a8  c7400808000000                    mov    DWORD PTR [eax+0x8],0x8
0x7073af  83460810                          add    DWORD PTR [esi+0x8],0x10
0x7073b3  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x7073b6  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x7073b9  3bc1                              cmp    eax,ecx
0x7073bb  7324                              jae    0x7073e1
0x7073bd  3dc8bfc000                        cmp    eax,0xc0bfc8
0x7073c2  741d                              je     0x7073e1
0x7073c4  83780806                          cmp    DWORD PTR [eax+0x8],0x6
0x7073c8  7517                              jne    0x7073e1
0x7073ca  3bc1                              cmp    eax,ecx
0x7073cc  7205                              jb     0x7073d3
0x7073ce  b8c8bfc000                        mov    eax,0xc0bfc8
0x7073d3  83780806                          cmp    DWORD PTR [eax+0x8],0x6
0x7073d7  7519                              jne    0x7073f2
0x7073d9  8b10                              mov    edx,DWORD PTR [eax]
0x7073db  807a0600                          cmp    BYTE PTR [edx+0x6],0x0
0x7073df  7411                              je     0x7073f2
0x7073e1  57                                push   edi
0x7073e2  6a01                              push   0x1
0x7073e4  bff836c400                        mov    edi,0xc436f8
0x7073e9  e8b2e9feff                        call   0x6f5da0
0x7073ee  83c404                            add    esp,0x4
0x7073f1  5f                                pop    edi
0x7073f2  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x7073f5  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x7073f8  3bc1                              cmp    eax,ecx
0x7073fa  7205                              jb     0x707401
0x7073fc  b8c8bfc000                        mov    eax,0xc0bfc8
0x707401  8b10                              mov    edx,DWORD PTR [eax]
0x707403  8911                              mov    DWORD PTR [ecx],edx
0x707405  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x707408  895104                            mov    DWORD PTR [ecx+0x4],edx
0x70740b  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x70740e  894108                            mov    DWORD PTR [ecx+0x8],eax
0x707411  83460810                          add    DWORD PTR [esi+0x8],0x10
0x707415  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x707418  3bf3                              cmp    esi,ebx
0x70741a  741f                              je     0x70743b
0x70741c  83c0f0                            add    eax,0xfffffff0
0x70741f  894608                            mov    DWORD PTR [esi+0x8],eax
0x707422  8b4b08                            mov    ecx,DWORD PTR [ebx+0x8]
0x707425  8d5110                            lea    edx,[ecx+0x10]
0x707428  895308                            mov    DWORD PTR [ebx+0x8],edx
0x70742b  8b10                              mov    edx,DWORD PTR [eax]
0x70742d  8911                              mov    DWORD PTR [ecx],edx
0x70742f  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x707432  895104                            mov    DWORD PTR [ecx+0x4],edx
0x707435  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x707438  894108                            mov    DWORD PTR [ecx+0x8],eax
0x70743b  5e                                pop    esi
0x70743c  b801000000                        mov    eax,0x1
0x707441  5b                                pop    ebx
0x707442  5d                                pop    ebp
0x707443  c3                                ret

; table_insert 0x70bd80..0x70bedc Two-argument insert path appends at raw length+1
0x70bd80  55                                push   ebp
0x70bd81  8bec                              mov    ebp,esp
0x70bd83  83ec08                            sub    esp,0x8
0x70bd86  53                                push   ebx
0x70bd87  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x70bd8a  8b430c                            mov    eax,DWORD PTR [ebx+0xc]
0x70bd8d  8b4b08                            mov    ecx,DWORD PTR [ebx+0x8]
0x70bd90  56                                push   esi
0x70bd91  57                                push   edi
0x70bd92  3bc1                              cmp    eax,ecx
0x70bd94  7320                              jae    0x70bdb6
0x70bd96  3dc8bfc000                        cmp    eax,0xc0bfc8
0x70bd9b  7406                              je     0x70bda3
0x70bd9d  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x70bda1  7441                              je     0x70bde4
0x70bda3  3bc1                              cmp    eax,ecx
0x70bda5  730f                              jae    0x70bdb6
0x70bda7  3dc8bfc000                        cmp    eax,0xc0bfc8
0x70bdac  7408                              je     0x70bdb6
0x70bdae  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x70bdb1  83f8ff                            cmp    eax,0xffffffff
0x70bdb4  7507                              jne    0x70bdbd
0x70bdb6  b8f426c400                        mov    eax,0xc426f4
0x70bdbb  eb07                              jmp    0x70bdc4
0x70bdbd  8b04851cbec000                    mov    eax,DWORD PTR [eax*4+0xc0be1c]
0x70bdc4  50                                push   eax
0x70bdc5  a130bec000                        mov    eax,ds:0xc0be30
0x70bdca  50                                push   eax
0x70bdcb  686827c400                        push   0xc42768
0x70bdd0  53                                push   ebx
0x70bdd1  e8aa97feff                        call   0x6f5580
0x70bdd6  6a01                              push   0x1
0x70bdd8  8bf8                              mov    edi,eax
0x70bdda  8bf3                              mov    esi,ebx
0x70bddc  e8bf9ffeff                        call   0x6f5da0
0x70bde1  83c414                            add    esp,0x14
0x70bde4  8b730c                            mov    esi,DWORD PTR [ebx+0xc]
0x70bde7  3b7308                            cmp    esi,DWORD PTR [ebx+0x8]
0x70bdea  7205                              jb     0x70bdf1
0x70bdec  bec8bfc000                        mov    esi,0xc0bfc8
0x70bdf1  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x70bdf4  83c0fd                            add    eax,0xfffffffd
0x70bdf7  83f804                            cmp    eax,0x4
0x70bdfa  7730                              ja     0x70be2c
0x70bdfc  ff2485dcbe7000                    jmp    DWORD PTR [eax*4+0x70bedc]
0x70be03  8b0e                              mov    ecx,DWORD PTR [esi]
0x70be05  8b410c                            mov    eax,DWORD PTR [ecx+0xc]
0x70be08  eb24                              jmp    0x70be2e
0x70be0a  8b16                              mov    edx,DWORD PTR [esi]
0x70be0c  8b4210                            mov    eax,DWORD PTR [edx+0x10]
0x70be0f  eb1d                              jmp    0x70be2e
0x70be11  8b06                              mov    eax,DWORD PTR [esi]
0x70be13  e8f8e0feff                        call   0x6f9f10
0x70be18  eb14                              jmp    0x70be2e
0x70be1a  8bfb                              mov    edi,ebx
0x70be1c  e8aff7feff                        call   0x6fb5d0
0x70be21  85c0                              test   eax,eax
0x70be23  7407                              je     0x70be2c
0x70be25  8b06                              mov    eax,DWORD PTR [esi]
0x70be27  8b400c                            mov    eax,DWORD PTR [eax+0xc]
0x70be2a  eb02                              jmp    0x70be2e
0x70be2c  33c0                              xor    eax,eax
0x70be2e  8d7801                            lea    edi,[eax+0x1]
0x70be31  8b4308                            mov    eax,DWORD PTR [ebx+0x8]
0x70be34  2b430c                            sub    eax,DWORD PTR [ebx+0xc]
0x70be37  c1f804                            sar    eax,0x4
0x70be3a  83e802                            sub    eax,0x2
0x70be3d  747d                              je     0x70bebc
0x70be3f  48                                dec    eax
0x70be40  7415                              je     0x70be57
0x70be42  68943cc400                        push   0xc43c94
0x70be47  53                                push   ebx
0x70be48  e8e3a0feff                        call   0x6f5f30
0x70be4d  83c408                            add    esp,0x8
0x70be50  5f                                pop    edi
0x70be51  5e                                pop    esi
0x70be52  5b                                pop    ebx
0x70be53  8be5                              mov    esp,ebp
0x70be55  5d                                pop    ebp
0x70be56  c3                                ret
0x70be57  6a02                              push   0x2
0x70be59  53                                push   ebx
0x70be5a  e811a5feff                        call   0x6f6370
0x70be5f  83c408                            add    esp,0x8
0x70be62  894508                            mov    DWORD PTR [ebp+0x8],eax
0x70be65  3bf8                              cmp    edi,eax
0x70be67  7d04                              jge    0x70be6d
0x70be69  8bf8                              mov    edi,eax
0x70be6b  3bf8                              cmp    edi,eax
0x70be6d  7e53                              jle    0x70bec2
0x70be6f  90                                nop
0x70be70  8b430c                            mov    eax,DWORD PTR [ebx+0xc]
0x70be73  3b4308                            cmp    eax,DWORD PTR [ebx+0x8]
0x70be76  7205                              jb     0x70be7d
0x70be78  b8c8bfc000                        mov    eax,0xc0bfc8
0x70be7d  8b30                              mov    esi,DWORD PTR [eax]
0x70be7f  8d4fff                            lea    ecx,[edi-0x1]
0x70be82  51                                push   ecx
0x70be83  894df8                            mov    DWORD PTR [ebp-0x8],ecx
0x70be86  e8e5dcfeff                        call   0x6f9b70
0x70be8b  8b10                              mov    edx,DWORD PTR [eax]
0x70be8d  8b4b08                            mov    ecx,DWORD PTR [ebx+0x8]
0x70be90  8911                              mov    DWORD PTR [ecx],edx
0x70be92  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x70be95  895104                            mov    DWORD PTR [ecx+0x4],edx
0x70be98  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x70be9b  894108                            mov    DWORD PTR [ecx+0x8],eax
0x70be9e  83430810                          add    DWORD PTR [ebx+0x8],0x10
0x70bea2  57                                push   edi
0x70bea3  b801000000                        mov    eax,0x1
0x70bea8  8bfb                              mov    edi,ebx
0x70beaa  e8c199feff                        call   0x6f5870
0x70beaf  8b7df8                            mov    edi,DWORD PTR [ebp-0x8]
0x70beb2  83c408                            add    esp,0x8
0x70beb5  3b7d08                            cmp    edi,DWORD PTR [ebp+0x8]
0x70beb8  7fb6                              jg     0x70be70
0x70beba  eb03                              jmp    0x70bebf
0x70bebc  897d08                            mov    DWORD PTR [ebp+0x8],edi
0x70bebf  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x70bec2  50                                push   eax
0x70bec3  b801000000                        mov    eax,0x1
0x70bec8  8bfb                              mov    edi,ebx
0x70beca  e8a199feff                        call   0x6f5870
0x70becf  83c404                            add    esp,0x4
0x70bed2  5f                                pop    edi
0x70bed3  5e                                pop    esi
0x70bed4  33c0                              xor    eax,eax
0x70bed6  5b                                pop    ebx
0x70bed7  8be5                              mov    esp,ebp
0x70bed9  5d                                pop    ebp
0x70beda  c3                                ret
0x70bedb  90                                nop

; DATA table_insert_type_table 0x70bedc..0x70bef0
; 1abe700003be700011be70002cbe70000abe7000

; raw_seti 0x6f5870..0x6f5908 Raw numeric key storage and TValue copy
0x6f5870  55                                push   ebp
0x6f5871  8bec                              mov    ebp,esp
0x6f5873  83e4f8                            and    esp,0xfffffff8
0x6f5876  83ec18                            sub    esp,0x18
0x6f5879  53                                push   ebx
0x6f587a  56                                push   esi
0x6f587b  8bcf                              mov    ecx,edi
0x6f587d  e86ef8ffff                        call   0x6f50f0
0x6f5882  8b30                              mov    esi,DWORD PTR [eax]
0x6f5884  8b5f08                            mov    ebx,DWORD PTR [edi+0x8]
0x6f5887  8944240c                          mov    DWORD PTR [esp+0xc],eax
0x6f588b  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6f588e  50                                push   eax
0x6f588f  e8dc420000                        call   0x6f9b70
0x6f5894  83c404                            add    esp,0x4
0x6f5897  3dc8bfc000                        cmp    eax,0xc0bfc8
0x6f589c  751e                              jne    0x6f58bc
0x6f589e  db4508                            fild   DWORD PTR [ebp+0x8]
0x6f58a1  8d4c2410                          lea    ecx,[esp+0x10]
0x6f58a5  51                                push   ecx
0x6f58a6  56                                push   esi
0x6f58a7  57                                push   edi
0x6f58a8  dd5c241c                          fstp   QWORD PTR [esp+0x1c]
0x6f58ac  c744242403000000                  mov    DWORD PTR [esp+0x24],0x3
0x6f58b4  e8a7410000                        call   0x6f9a60
0x6f58b9  83c40c                            add    esp,0xc
0x6f58bc  8b53f0                            mov    edx,DWORD PTR [ebx-0x10]
0x6f58bf  8910                              mov    DWORD PTR [eax],edx
0x6f58c1  8b4bf4                            mov    ecx,DWORD PTR [ebx-0xc]
0x6f58c4  894804                            mov    DWORD PTR [eax+0x4],ecx
0x6f58c7  8b53f8                            mov    edx,DWORD PTR [ebx-0x8]
0x6f58ca  895008                            mov    DWORD PTR [eax+0x8],edx
0x6f58cd  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x6f58d0  b904000000                        mov    ecx,0x4
0x6f58d5  3948f8                            cmp    DWORD PTR [eax-0x8],ecx
0x6f58d8  7c24                              jl     0x6f58fe
0x6f58da  8b40f0                            mov    eax,DWORD PTR [eax-0x10]
0x6f58dd  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6f58e1  741b                              je     0x6f58fe
0x6f58e3  8b54240c                          mov    edx,DWORD PTR [esp+0xc]
0x6f58e7  8b02                              mov    eax,DWORD PTR [edx]
0x6f58e9  844805                            test   BYTE PTR [eax+0x5],cl
0x6f58ec  7410                              je     0x6f58fe
0x6f58ee  8b4f10                            mov    ecx,DWORD PTR [edi+0x10]
0x6f58f1  806005fb                          and    BYTE PTR [eax+0x5],0xfb
0x6f58f5  8b5128                            mov    edx,DWORD PTR [ecx+0x28]
0x6f58f8  895018                            mov    DWORD PTR [eax+0x18],edx
0x6f58fb  894128                            mov    DWORD PTR [ecx+0x28],eax
0x6f58fe  834708f0                          add    DWORD PTR [edi+0x8],0xfffffff0
0x6f5902  5e                                pop    esi
0x6f5903  5b                                pop    ebx
0x6f5904  8be5                              mov    esp,ebp
0x6f5906  5d                                pop    ebp
0x6f5907  c3                                ret

; table_length 0x6f9f10..0x6f9f6c Raw array/hash boundary length
0x6f9f10  8b501c                            mov    edx,DWORD PTR [eax+0x1c]
0x6f9f13  56                                push   esi
0x6f9f14  57                                push   edi
0x6f9f15  85d2                              test   edx,edx
0x6f9f17  7439                              je     0x6f9f52
0x6f9f19  8b700c                            mov    esi,DWORD PTR [eax+0xc]
0x6f9f1c  8bca                              mov    ecx,edx
0x6f9f1e  03c9                              add    ecx,ecx
0x6f9f20  837ccef800                        cmp    DWORD PTR [esi+ecx*8-0x8],0x0
0x6f9f25  752b                              jne    0x6f9f52
0x6f9f27  33c0                              xor    eax,eax
0x6f9f29  83fa01                            cmp    edx,0x1
0x6f9f2c  763b                              jbe    0x6f9f69
0x6f9f2e  8bff                              mov    edi,edi
0x6f9f30  8d0c10                            lea    ecx,[eax+edx*1]
0x6f9f33  d1e9                              shr    ecx,1
0x6f9f35  8bf9                              mov    edi,ecx
0x6f9f37  03ff                              add    edi,edi
0x6f9f39  837cfef800                        cmp    DWORD PTR [esi+edi*8-0x8],0x0
0x6f9f3e  7504                              jne    0x6f9f44
0x6f9f40  8bd1                              mov    edx,ecx
0x6f9f42  eb02                              jmp    0x6f9f46
0x6f9f44  8bc1                              mov    eax,ecx
0x6f9f46  8bca                              mov    ecx,edx
0x6f9f48  2bc8                              sub    ecx,eax
0x6f9f4a  83f901                            cmp    ecx,0x1
0x6f9f4d  77e1                              ja     0x6f9f30
0x6f9f4f  5f                                pop    edi
0x6f9f50  5e                                pop    esi
0x6f9f51  c3                                ret
0x6f9f52  817810a8bfc000                    cmp    DWORD PTR [eax+0x10],0xc0bfa8
0x6f9f59  7505                              jne    0x6f9f60
0x6f9f5b  8bc2                              mov    eax,edx
0x6f9f5d  5f                                pop    edi
0x6f9f5e  5e                                pop    esi
0x6f9f5f  c3                                ret
0x6f9f60  52                                push   edx
0x6f9f61  e87afeffff                        call   0x6f9de0
0x6f9f66  83c404                            add    esp,0x4
0x6f9f69  5f                                pop    edi
0x6f9f6a  5e                                pop    esi
0x6f9f6b  c3                                ret

; table_integer_lookup 0x6f9b70..0x6f9c04 Raw numeric-key lookup; no Lua function call
0x6f9b70  55                                push   ebp
0x6f9b71  8bec                              mov    ebp,esp
0x6f9b73  83e4f8                            and    esp,0xfffffff8
0x6f9b76  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6f9b79  83ec0c                            sub    esp,0xc
0x6f9b7c  8d48ff                            lea    ecx,[eax-0x1]
0x6f9b7f  57                                push   edi
0x6f9b80  3b4e1c                            cmp    ecx,DWORD PTR [esi+0x1c]
0x6f9b83  730e                              jae    0x6f9b93
0x6f9b85  8b560c                            mov    edx,DWORD PTR [esi+0xc]
0x6f9b88  03c0                              add    eax,eax
0x6f9b8a  8d44c2f0                          lea    eax,[edx+eax*8-0x10]
0x6f9b8e  5f                                pop    edi
0x6f9b8f  8be5                              mov    esp,ebp
0x6f9b91  5d                                pop    ebp
0x6f9b92  c3                                ret
0x6f9b93  db4508                            fild   DWORD PTR [ebp+0x8]
0x6f9b96  dd542408                          fst    QWORD PTR [esp+0x8]
0x6f9b9a  d9c0                              fld    st(0)
0x6f9b9c  d9ee                              fldz
0x6f9b9e  dae9                              fucompp
0x6f9ba0  dfe0                              fnstsw ax
0x6f9ba2  f6c444                            test   ah,0x44
0x6f9ba5  7a05                              jp     0x6f9bac
0x6f9ba7  8b5610                            mov    edx,DWORD PTR [esi+0x10]
0x6f9baa  eb20                              jmp    0x6f9bcc
0x6f9bac  8a4e07                            mov    cl,BYTE PTR [esi+0x7]
0x6f9baf  8b44240c                          mov    eax,DWORD PTR [esp+0xc]
0x6f9bb3  03442408                          add    eax,DWORD PTR [esp+0x8]
0x6f9bb7  bf01000000                        mov    edi,0x1
0x6f9bbc  d3e7                              shl    edi,cl
0x6f9bbe  33d2                              xor    edx,edx
0x6f9bc0  4f                                dec    edi
0x6f9bc1  83cf01                            or     edi,0x1
0x6f9bc4  f7f7                              div    edi
0x6f9bc6  c1e205                            shl    edx,0x5
0x6f9bc9  035610                            add    edx,DWORD PTR [esi+0x10]
0x6f9bcc  85d2                              test   edx,edx
0x6f9bce  741f                              je     0x6f9bef
0x6f9bd0  b903000000                        mov    ecx,0x3
0x6f9bd5  394a18                            cmp    DWORD PTR [edx+0x18],ecx
0x6f9bd8  750e                              jne    0x6f9be8
0x6f9bda  dd4210                            fld    QWORD PTR [edx+0x10]
0x6f9bdd  d9c1                              fld    st(1)
0x6f9bdf  dae9                              fucompp
0x6f9be1  dfe0                              fnstsw ax
0x6f9be3  f6c444                            test   ah,0x44
0x6f9be6  7b13                              jnp    0x6f9bfb
0x6f9be8  8b521c                            mov    edx,DWORD PTR [edx+0x1c]
0x6f9beb  85d2                              test   edx,edx
0x6f9bed  75e6                              jne    0x6f9bd5
0x6f9bef  b8c8bfc000                        mov    eax,0xc0bfc8
0x6f9bf4  ddd8                              fstp   st(0)
0x6f9bf6  5f                                pop    edi
0x6f9bf7  8be5                              mov    esp,ebp
0x6f9bf9  5d                                pop    ebp
0x6f9bfa  c3                                ret
0x6f9bfb  8bc2                              mov    eax,edx
0x6f9bfd  ddd8                              fstp   st(0)
0x6f9bff  5f                                pop    edi
0x6f9c00  8be5                              mov    esp,ebp
0x6f9c02  5d                                pop    ebp
0x6f9c03  c3                                ret

; vm_fetch 0x6fc550..0x6fc5f8 Lua frame/closure/base, hook gate, opcode switch
0x6fc550  55                                push   ebp
0x6fc551  8bec                              mov    ebp,esp
0x6fc553  83e4c0                            and    esp,0xffffffc0
0x6fc556  81ecb4000000                      sub    esp,0xb4
0x6fc55c  53                                push   ebx
0x6fc55d  56                                push   esi
0x6fc55e  57                                push   edi
0x6fc55f  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x6fc562  8b4f14                            mov    ecx,DWORD PTR [edi+0x14]
0x6fc565  8b4718                            mov    eax,DWORD PTR [edi+0x18]
0x6fc568  8b5104                            mov    edx,DWORD PTR [ecx+0x4]
0x6fc56b  8b4f0c                            mov    ecx,DWORD PTR [edi+0xc]
0x6fc56e  89442434                          mov    DWORD PTR [esp+0x34],eax
0x6fc572  8b02                              mov    eax,DWORD PTR [edx]
0x6fc574  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x6fc577  8944245c                          mov    DWORD PTR [esp+0x5c],eax
0x6fc57b  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x6fc57e  894c2438                          mov    DWORD PTR [esp+0x38],ecx
0x6fc582  89442440                          mov    DWORD PTR [esp+0x40],eax
0x6fc586  eb02                              jmp    0x6fc58a
0x6fc588  ddd8                              fstp   st(0)
0x6fc58a  8b442434                          mov    eax,DWORD PTR [esp+0x34]
0x6fc58e  8b18                              mov    ebx,DWORD PTR [eax]
0x6fc590  83c004                            add    eax,0x4
0x6fc593  89442434                          mov    DWORD PTR [esp+0x34],eax
0x6fc597  8a4738                            mov    al,BYTE PTR [edi+0x38]
0x6fc59a  a80c                              test   al,0xc
0x6fc59c  7429                              je     0x6fc5c7
0x6fc59e  ff4f40                            dec    DWORD PTR [edi+0x40]
0x6fc5a1  7404                              je     0x6fc5a7
0x6fc5a3  a804                              test   al,0x4
0x6fc5a5  7420                              je     0x6fc5c7
0x6fc5a7  8b4c2434                          mov    ecx,DWORD PTR [esp+0x34]
0x6fc5ab  51                                push   ecx
0x6fc5ac  8bf7                              mov    esi,edi
0x6fc5ae  e8adf0ffff                        call   0x6fb660
0x6fc5b3  83c404                            add    esp,0x4
0x6fc5b6  807f0601                          cmp    BYTE PTR [edi+0x6],0x1
0x6fc5ba  0f84c0100000                      je     0x6fd680
0x6fc5c0  8b570c                            mov    edx,DWORD PTR [edi+0xc]
0x6fc5c3  89542438                          mov    DWORD PTR [esp+0x38],edx
0x6fc5c7  8b4c2438                          mov    ecx,DWORD PTR [esp+0x38]
0x6fc5cb  8bc3                              mov    eax,ebx
0x6fc5cd  c1e806                            shr    eax,0x6
0x6fc5d0  25ff000000                        and    eax,0xff
0x6fc5d5  8944243c                          mov    DWORD PTR [esp+0x3c],eax
0x6fc5d9  c1e004                            shl    eax,0x4
0x6fc5dc  8d3408                            lea    esi,[eax+ecx*1]
0x6fc5df  89442448                          mov    DWORD PTR [esp+0x48],eax
0x6fc5e3  8bc3                              mov    eax,ebx
0x6fc5e5  83e03f                            and    eax,0x3f
0x6fc5e8  89742444                          mov    DWORD PTR [esp+0x44],esi
0x6fc5ec  83f825                            cmp    eax,0x25
0x6fc5ef  7799                              ja     0x6fc58a
0x6fc5f1  ff248594d66f00                    jmp    DWORD PTR [eax*4+0x6fd694]

; loadbool 0x6fc621..0x6fc645 Writes boolean value and tag at selected local register
0x6fc621  8bc3                              mov    eax,ebx
0x6fc623  c1e817                            shr    eax,0x17
0x6fc626  8906                              mov    DWORD PTR [esi],eax
0x6fc628  c7460801000000                    mov    DWORD PTR [esi+0x8],0x1
0x6fc62f  f7c300c07f00                      test   ebx,0x7fc000
0x6fc635  0f844fffffff                      je     0x6fc58a
0x6fc63b  8344243404                        add    DWORD PTR [esp+0x34],0x4
0x6fc640  e945ffffff                        jmp    0x6fc58a

; getupval 0x6fc65f..0x6fc682 Reads closure upvalue current value pointer
0x6fc65f  8b4c245c                          mov    ecx,DWORD PTR [esp+0x5c]
0x6fc663  c1eb17                            shr    ebx,0x17
0x6fc666  8b549914                          mov    edx,DWORD PTR [ecx+ebx*4+0x14]
0x6fc66a  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x6fc66d  8b08                              mov    ecx,DWORD PTR [eax]
0x6fc66f  890e                              mov    DWORD PTR [esi],ecx
0x6fc671  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x6fc674  895604                            mov    DWORD PTR [esi+0x4],edx
0x6fc677  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x6fc67a  894608                            mov    DWORD PTR [esi+0x8],eax
0x6fc67d  e908ffffff                        jmp    0x6fc58a

; close_and_closure 0x6fd3e9..0x6fd4c2 CLOSE and CLOSURE; parent-local upvalue capture
0x6fd3e9  8b4c2444                          mov    ecx,DWORD PTR [esp+0x44]
0x6fd3ed  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x6fd3f0  51                                push   ecx
0x6fd3f1  e86a040000                        call   0x6fd860
0x6fd3f6  83c404                            add    esp,0x4
0x6fd3f9  e98cf1ffff                        jmp    0x6fc58a
0x6fd3fe  8b44245c                          mov    eax,DWORD PTR [esp+0x5c]
0x6fd402  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x6fd405  8b4a10                            mov    ecx,DWORD PTR [edx+0x10]
0x6fd408  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0x6fd40b  c1eb0e                            shr    ebx,0xe
0x6fd40e  8b1c99                            mov    ebx,DWORD PTR [ecx+ebx*4]
0x6fd411  895c2448                          mov    DWORD PTR [esp+0x48],ebx
0x6fd415  0fb65b48                          movzx  ebx,BYTE PTR [ebx+0x48]
0x6fd419  52                                push   edx
0x6fd41a  53                                push   ebx
0x6fd41b  8bc7                              mov    eax,edi
0x6fd41d  e80e030000                        call   0x6fd730
0x6fd422  8b4c2450                          mov    ecx,DWORD PTR [esp+0x50]
0x6fd426  83c408                            add    esp,0x8
0x6fd429  89442444                          mov    DWORD PTR [esp+0x44],eax
0x6fd42d  894810                            mov    DWORD PTR [eax+0x10],ecx
0x6fd430  85db                              test   ebx,ebx
0x6fd432  7e5c                              jle    0x6fd490
0x6fd434  8bd0                              mov    edx,eax
0x6fd436  83c214                            add    edx,0x14
0x6fd439  895c2450                          mov    DWORD PTR [esp+0x50],ebx
0x6fd43d  8b5c2434                          mov    ebx,DWORD PTR [esp+0x34]
0x6fd441  8954243c                          mov    DWORD PTR [esp+0x3c],edx
0x6fd445  8b03                              mov    eax,DWORD PTR [ebx]
0x6fd447  8bc8                              mov    ecx,eax
0x6fd449  80e13f                            and    cl,0x3f
0x6fd44c  c1e817                            shr    eax,0x17
0x6fd44f  80f904                            cmp    cl,0x4
0x6fd452  7510                              jne    0x6fd464
0x6fd454  8b54245c                          mov    edx,DWORD PTR [esp+0x5c]
0x6fd458  8b448214                          mov    eax,DWORD PTR [edx+eax*4+0x14]
0x6fd45c  8b4c243c                          mov    ecx,DWORD PTR [esp+0x3c]
0x6fd460  8901                              mov    DWORD PTR [ecx],eax
0x6fd462  eb18                              jmp    0x6fd47c
0x6fd464  c1e004                            shl    eax,0x4
0x6fd467  03442438                          add    eax,DWORD PTR [esp+0x38]
0x6fd46b  8bd7                              mov    edx,edi
0x6fd46d  50                                push   eax
0x6fd46e  e82d030000                        call   0x6fd7a0
0x6fd473  8b542440                          mov    edx,DWORD PTR [esp+0x40]
0x6fd477  83c404                            add    esp,0x4
0x6fd47a  8902                              mov    DWORD PTR [edx],eax
0x6fd47c  8344243c04                        add    DWORD PTR [esp+0x3c],0x4
0x6fd481  83c304                            add    ebx,0x4
0x6fd484  ff4c2450                          dec    DWORD PTR [esp+0x50]
0x6fd488  75bb                              jne    0x6fd445
0x6fd48a  895c2434                          mov    DWORD PTR [esp+0x34],ebx
0x6fd48e  eb04                              jmp    0x6fd494
0x6fd490  8b5c2434                          mov    ebx,DWORD PTR [esp+0x34]
0x6fd494  8b442444                          mov    eax,DWORD PTR [esp+0x44]
0x6fd498  8906                              mov    DWORD PTR [esi],eax
0x6fd49a  c7460806000000                    mov    DWORD PTR [esi+0x8],0x6
0x6fd4a1  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x6fd4a4  895f18                            mov    DWORD PTR [edi+0x18],ebx
0x6fd4a7  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x6fd4aa  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x6fd4ad  7207                              jb     0x6fd4b6
0x6fd4af  8bc7                              mov    eax,edi
0x6fd4b1  e8eadeffff                        call   0x6fb3a0
0x6fd4b6  8b570c                            mov    edx,DWORD PTR [edi+0xc]
0x6fd4b9  89542438                          mov    DWORD PTR [esp+0x38],edx
0x6fd4bd  e9c8f0ffff                        jmp    0x6fc58a

; return_close 0x6fd629..0x6fd691 RETURN closes surviving upvalues before frame return
0x6fd629  c1eb17                            shr    ebx,0x17
0x6fd62c  85db                              test   ebx,ebx
0x6fd62e  7409                              je     0x6fd639
0x6fd630  03db                              add    ebx,ebx
0x6fd632  8d44def0                          lea    eax,[esi+ebx*8-0x10]
0x6fd636  894708                            mov    DWORD PTR [edi+0x8],eax
0x6fd639  837f6800                          cmp    DWORD PTR [edi+0x68],0x0
0x6fd63d  7414                              je     0x6fd653
0x6fd63f  8b4c2438                          mov    ecx,DWORD PTR [esp+0x38]
0x6fd643  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x6fd646  51                                push   ecx
0x6fd647  e814020000                        call   0x6fd860
0x6fd64c  8b742448                          mov    esi,DWORD PTR [esp+0x48]
0x6fd650  83c404                            add    esp,0x4
0x6fd653  8b542434                          mov    edx,DWORD PTR [esp+0x34]
0x6fd657  57                                push   edi
0x6fd658  8bc6                              mov    eax,esi
0x6fd65a  895718                            mov    DWORD PTR [edi+0x18],edx
0x6fd65d  e85e0e0000                        call   0x6fe4c0
0x6fd662  83c404                            add    esp,0x4
0x6fd665  ff4d0c                            dec    DWORD PTR [ebp+0xc]
0x6fd668  7420                              je     0x6fd68a
0x6fd66a  85c0                              test   eax,eax
0x6fd66c  0f84f0eeffff                      je     0x6fc562
0x6fd672  8b4714                            mov    eax,DWORD PTR [edi+0x14]
0x6fd675  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x6fd678  894f08                            mov    DWORD PTR [edi+0x8],ecx
0x6fd67b  e9e2eeffff                        jmp    0x6fc562
0x6fd680  8b542434                          mov    edx,DWORD PTR [esp+0x34]
0x6fd684  83c2fc                            add    edx,0xfffffffc
0x6fd687  895718                            mov    DWORD PTR [edi+0x18],edx
0x6fd68a  5f                                pop    edi
0x6fd68b  5e                                pop    esi
0x6fd68c  5b                                pop    ebx
0x6fd68d  8be5                              mov    esp,ebp
0x6fd68f  5d                                pop    ebp
0x6fd690  c3                                ret

; allocate_lua_closure 0x6fd730..0x6fd791 Lua closure size and nups array initialization
0x6fd730  55                                push   ebp
0x6fd731  8bec                              mov    ebp,esp
0x6fd733  53                                push   ebx
0x6fd734  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6fd737  56                                push   esi
0x6fd738  57                                push   edi
0x6fd739  8d3c9d14000000                    lea    edi,[ebx*4+0x14]
0x6fd740  57                                push   edi
0x6fd741  6a00                              push   0x0
0x6fd743  8bf0                              mov    esi,eax
0x6fd745  6a00                              push   0x0
0x6fd747  56                                push   esi
0x6fd748  e833310000                        call   0x700880
0x6fd74d  8b7610                            mov    esi,DWORD PTR [esi+0x10]
0x6fd750  8b4e1c                            mov    ecx,DWORD PTR [esi+0x1c]
0x6fd753  8908                              mov    DWORD PTR [eax],ecx
0x6fd755  8a5614                            mov    dl,BYTE PTR [esi+0x14]
0x6fd758  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x6fd75b  89461c                            mov    DWORD PTR [esi+0x1c],eax
0x6fd75e  80e203                            and    dl,0x3
0x6fd761  83c410                            add    esp,0x10
0x6fd764  885005                            mov    BYTE PTR [eax+0x5],dl
0x6fd767  c6400406                          mov    BYTE PTR [eax+0x4],0x6
0x6fd76b  c6400600                          mov    BYTE PTR [eax+0x6],0x0
0x6fd76f  89480c                            mov    DWORD PTR [eax+0xc],ecx
0x6fd772  885807                            mov    BYTE PTR [eax+0x7],bl
0x6fd775  85db                              test   ebx,ebx
0x6fd777  7413                              je     0x6fd78c
0x6fd779  8d0c07                            lea    ecx,[edi+eax*1]
0x6fd77c  8d642400                          lea    esp,[esp+0x0]
0x6fd780  83e904                            sub    ecx,0x4
0x6fd783  4b                                dec    ebx
0x6fd784  c70100000000                      mov    DWORD PTR [ecx],0x0
0x6fd78a  75f4                              jne    0x6fd780
0x6fd78c  5f                                pop    edi
0x6fd78d  5e                                pop    esi
0x6fd78e  5b                                pop    ebx
0x6fd78f  5d                                pop    ebp
0x6fd790  c3                                ret

; find_open_upvalue 0x6fd7a0..0x6fd827 Shared stack slot capture or reuse
0x6fd7a0  55                                push   ebp
0x6fd7a1  8bec                              mov    ebp,esp
0x6fd7a3  837a6800                          cmp    DWORD PTR [edx+0x68],0x0
0x6fd7a7  53                                push   ebx
0x6fd7a8  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6fd7ab  56                                push   esi
0x6fd7ac  8d7268                            lea    esi,[edx+0x68]
0x6fd7af  57                                push   edi
0x6fd7b0  8b7a10                            mov    edi,DWORD PTR [edx+0x10]
0x6fd7b3  7412                              je     0x6fd7c7
0x6fd7b5  8b06                              mov    eax,DWORD PTR [esi]
0x6fd7b7  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x6fd7ba  3bcb                              cmp    ecx,ebx
0x6fd7bc  7209                              jb     0x6fd7c7
0x6fd7be  7449                              je     0x6fd809
0x6fd7c0  833800                            cmp    DWORD PTR [eax],0x0
0x6fd7c3  8bf0                              mov    esi,eax
0x6fd7c5  75ee                              jne    0x6fd7b5
0x6fd7c7  6a20                              push   0x20
0x6fd7c9  6a00                              push   0x0
0x6fd7cb  6a00                              push   0x0
0x6fd7cd  52                                push   edx
0x6fd7ce  e8ad300000                        call   0x700880
0x6fd7d3  c640040a                          mov    BYTE PTR [eax+0x4],0xa
0x6fd7d7  8a4f14                            mov    cl,BYTE PTR [edi+0x14]
0x6fd7da  895808                            mov    DWORD PTR [eax+0x8],ebx
0x6fd7dd  83c410                            add    esp,0x10
0x6fd7e0  80e103                            and    cl,0x3
0x6fd7e3  884805                            mov    BYTE PTR [eax+0x5],cl
0x6fd7e6  8b16                              mov    edx,DWORD PTR [esi]
0x6fd7e8  8910                              mov    DWORD PTR [eax],edx
0x6fd7ea  8906                              mov    DWORD PTR [esi],eax
0x6fd7ec  8d4f78                            lea    ecx,[edi+0x78]
0x6fd7ef  894810                            mov    DWORD PTR [eax+0x10],ecx
0x6fd7f2  8b8f8c000000                      mov    ecx,DWORD PTR [edi+0x8c]
0x6fd7f8  894814                            mov    DWORD PTR [eax+0x14],ecx
0x6fd7fb  894110                            mov    DWORD PTR [ecx+0x10],eax
0x6fd7fe  89878c000000                      mov    DWORD PTR [edi+0x8c],eax
0x6fd804  5f                                pop    edi
0x6fd805  5e                                pop    esi
0x6fd806  5b                                pop    ebx
0x6fd807  5d                                pop    ebp
0x6fd808  c3                                ret
0x6fd809  8a4805                            mov    cl,BYTE PTR [eax+0x5]
0x6fd80c  0fb65f14                          movzx  ebx,BYTE PTR [edi+0x14]
0x6fd810  0fb6d1                            movzx  edx,cl
0x6fd813  83e203                            and    edx,0x3
0x6fd816  f7d3                              not    ebx
0x6fd818  84d3                              test   bl,dl
0x6fd81a  74e8                              je     0x6fd804
0x6fd81c  5f                                pop    edi
0x6fd81d  80f103                            xor    cl,0x3
0x6fd820  5e                                pop    esi
0x6fd821  884805                            mov    BYTE PTR [eax+0x5],cl
0x6fd824  5b                                pop    ebx
0x6fd825  5d                                pop    ebp
0x6fd826  c3                                ret

; close_upvalues 0x6fd860..0x6fd946 Live upvalue copies TValue into own storage; redirects pointer
0x6fd860  55                                push   ebp
0x6fd861  8bec                              mov    ebp,esp
0x6fd863  51                                push   ecx
0x6fd864  837f6800                          cmp    DWORD PTR [edi+0x68],0x0
0x6fd868  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x6fd86b  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x6fd86e  0f84ce000000                      je     0x6fd942
0x6fd874  56                                push   esi
0x6fd875  8b4f68                            mov    ecx,DWORD PTR [edi+0x68]
0x6fd878  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x6fd87b  395108                            cmp    DWORD PTR [ecx+0x8],edx
0x6fd87e  0f82bd000000                      jb     0x6fd941
0x6fd884  8b01                              mov    eax,DWORD PTR [ecx]
0x6fd886  894768                            mov    DWORD PTR [edi+0x68],eax
0x6fd889  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x6fd88c  0fb64014                          movzx  eax,BYTE PTR [eax+0x14]
0x6fd890  0fb65105                          movzx  edx,BYTE PTR [ecx+0x5]
0x6fd894  f7d0                              not    eax
0x6fd896  83e203                            and    edx,0x3
0x6fd899  84d0                              test   al,dl
0x6fd89b  8d4110                            lea    eax,[ecx+0x10]
0x6fd89e  7425                              je     0x6fd8c5
0x6fd8a0  394108                            cmp    DWORD PTR [ecx+0x8],eax
0x6fd8a3  7410                              je     0x6fd8b5
0x6fd8a5  8b5114                            mov    edx,DWORD PTR [ecx+0x14]
0x6fd8a8  8b30                              mov    esi,DWORD PTR [eax]
0x6fd8aa  897210                            mov    DWORD PTR [edx+0x10],esi
0x6fd8ad  8b00                              mov    eax,DWORD PTR [eax]
0x6fd8af  8b5114                            mov    edx,DWORD PTR [ecx+0x14]
0x6fd8b2  895014                            mov    DWORD PTR [eax+0x14],edx
0x6fd8b5  6a00                              push   0x0
0x6fd8b7  6a20                              push   0x20
0x6fd8b9  51                                push   ecx
0x6fd8ba  57                                push   edi
0x6fd8bb  e8c02f0000                        call   0x700880
0x6fd8c0  83c410                            add    esp,0x10
0x6fd8c3  eb72                              jmp    0x6fd937
0x6fd8c5  8b30                              mov    esi,DWORD PTR [eax]
0x6fd8c7  8b5114                            mov    edx,DWORD PTR [ecx+0x14]
0x6fd8ca  897210                            mov    DWORD PTR [edx+0x10],esi
0x6fd8cd  8b10                              mov    edx,DWORD PTR [eax]
0x6fd8cf  8b7114                            mov    esi,DWORD PTR [ecx+0x14]
0x6fd8d2  897214                            mov    DWORD PTR [edx+0x14],esi
0x6fd8d5  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x6fd8d8  8b32                              mov    esi,DWORD PTR [edx]
0x6fd8da  8930                              mov    DWORD PTR [eax],esi
0x6fd8dc  8b7204                            mov    esi,DWORD PTR [edx+0x4]
0x6fd8df  897004                            mov    DWORD PTR [eax+0x4],esi
0x6fd8e2  8b5208                            mov    edx,DWORD PTR [edx+0x8]
0x6fd8e5  895008                            mov    DWORD PTR [eax+0x8],edx
0x6fd8e8  894108                            mov    DWORD PTR [ecx+0x8],eax
0x6fd8eb  8b7710                            mov    esi,DWORD PTR [edi+0x10]
0x6fd8ee  8b461c                            mov    eax,DWORD PTR [esi+0x1c]
0x6fd8f1  8901                              mov    DWORD PTR [ecx],eax
0x6fd8f3  894e1c                            mov    DWORD PTR [esi+0x1c],ecx
0x6fd8f6  8a4105                            mov    al,BYTE PTR [ecx+0x5]
0x6fd8f9  a807                              test   al,0x7
0x6fd8fb  753a                              jne    0x6fd937
0x6fd8fd  807e1501                          cmp    BYTE PTR [esi+0x15],0x1
0x6fd901  7527                              jne    0x6fd92a
0x6fd903  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x6fd906  0c04                              or     al,0x4
0x6fd908  884105                            mov    BYTE PTR [ecx+0x5],al
0x6fd90b  837a0804                          cmp    DWORD PTR [edx+0x8],0x4
0x6fd90f  7c26                              jl     0x6fd937
0x6fd911  8b12                              mov    edx,DWORD PTR [edx]
0x6fd913  f6420503                          test   BYTE PTR [edx+0x5],0x3
0x6fd917  741e                              je     0x6fd937
0x6fd919  a804                              test   al,0x4
0x6fd91b  741a                              je     0x6fd937
0x6fd91d  52                                push   edx
0x6fd91e  8bc7                              mov    eax,edi
0x6fd920  e87bdcffff                        call   0x6fb5a0
0x6fd925  83c404                            add    esp,0x4
0x6fd928  eb0d                              jmp    0x6fd937
0x6fd92a  8a5614                            mov    dl,BYTE PTR [esi+0x14]
0x6fd92d  80e203                            and    dl,0x3
0x6fd930  24f8                              and    al,0xf8
0x6fd932  0ad0                              or     dl,al
0x6fd934  885105                            mov    BYTE PTR [ecx+0x5],dl
0x6fd937  837f6800                          cmp    DWORD PTR [edi+0x68],0x0
0x6fd93b  0f8534ffffff                      jne    0x6fd875
0x6fd941  5e                                pop    esi
0x6fd942  8be5                              mov    esp,ebp
0x6fd944  5d                                pop    ebp
0x6fd945  c3                                ret

; global_dofile 0x6f48a0..0x6f4a50 Reused current-state loader; numeric status 0/1
0x6f48a0  55                                push   ebp
0x6f48a1  8bec                              mov    ebp,esp
0x6f48a3  83e4f8                            and    esp,0xfffffff8
0x6f48a6  83ec1c                            sub    esp,0x1c
0x6f48a9  53                                push   ebx
0x6f48aa  56                                push   esi
0x6f48ab  57                                push   edi
0x6f48ac  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x6f48af  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x6f48b2  83ee10                            sub    esi,0x10
0x6f48b5  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x6f48b9  7425                              je     0x6f48e0
0x6f48bb  e8106d0000                        call   0x6fb5d0
0x6f48c0  85c0                              test   eax,eax
0x6f48c2  7504                              jne    0x6f48c8
0x6f48c4  33f6                              xor    esi,esi
0x6f48c6  eb1d                              jmp    0x6f48e5
0x6f48c8  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x6f48cb  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x6f48ce  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x6f48d1  7207                              jb     0x6f48da
0x6f48d3  8bc7                              mov    eax,edi
0x6f48d5  e8c66a0000                        call   0x6fb3a0
0x6f48da  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x6f48dd  83ee10                            sub    esi,0x10
0x6f48e0  8b36                              mov    esi,DWORD PTR [esi]
0x6f48e2  83c610                            add    esi,0x10
0x6f48e5  68e0d1be00                        push   0xbed1e0
0x6f48ea  56                                push   esi
0x6f48eb  c744241401000000                  mov    DWORD PTR [esp+0x14],0x1
0x6f48f3  e878fe0100                        call   0x714770
0x6f48f8  8bf0                              mov    esi,eax
0x6f48fa  83c408                            add    esp,0x8
0x6f48fd  85f6                              test   esi,esi
0x6f48ff  0f842b010000                      je     0x6f4a30
0x6f4905  8b16                              mov    edx,DWORD PTR [esi]
0x6f4907  8b422c                            mov    eax,DWORD PTR [edx+0x2c]
0x6f490a  8bce                              mov    ecx,esi
0x6f490c  ffd0                              call   eax
0x6f490e  8bd8                              mov    ebx,eax
0x6f4910  8d4b01                            lea    ecx,[ebx+0x1]
0x6f4913  51                                push   ecx
0x6f4914  e824931800                        call   0x87dc3d
0x6f4919  8b16                              mov    edx,DWORD PTR [esi]
0x6f491b  83c404                            add    esp,0x4
0x6f491e  8944240c                          mov    DWORD PTR [esp+0xc],eax
0x6f4922  8b4238                            mov    eax,DWORD PTR [edx+0x38]
0x6f4925  53                                push   ebx
0x6f4926  8bce                              mov    ecx,esi
0x6f4928  ffd0                              call   eax
0x6f492a  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x6f492e  50                                push   eax
0x6f492f  51                                push   ecx
0x6f4930  e89b921a00                        call   0x89dbd0
0x6f4935  8b542418                          mov    edx,DWORD PTR [esp+0x18]
0x6f4939  c6041300                          mov    BYTE PTR [ebx+edx*1],0x0
0x6f493d  8b06                              mov    eax,DWORD PTR [esi]
0x6f493f  8b502c                            mov    edx,DWORD PTR [eax+0x2c]
0x6f4942  83c40c                            add    esp,0xc
0x6f4945  8bce                              mov    ecx,esi
0x6f4947  ffd2                              call   edx
0x6f4949  8b5c240c                          mov    ebx,DWORD PTR [esp+0xc]
0x6f494d  83f803                            cmp    eax,0x3
0x6f4950  7242                              jb     0x6f4994
0x6f4952  803bef                            cmp    BYTE PTR [ebx],0xef
0x6f4955  753d                              jne    0x6f4994
0x6f4957  807b01bb                          cmp    BYTE PTR [ebx+0x1],0xbb
0x6f495b  7537                              jne    0x6f4994
0x6f495d  807b02bf                          cmp    BYTE PTR [ebx+0x2],0xbf
0x6f4961  7531                              jne    0x6f4994
0x6f4963  83c0fd                            add    eax,0xfffffffd
0x6f4966  50                                push   eax
0x6f4967  8d4303                            lea    eax,[ebx+0x3]
0x6f496a  50                                push   eax
0x6f496b  33c0                              xor    eax,eax
0x6f496d  8bd7                              mov    edx,edi
0x6f496f  e89c270000                        call   0x6f7110
0x6f4974  83c408                            add    esp,0x8
0x6f4977  85c0                              test   eax,eax
0x6f4979  0f8597000000                      jne    0x6f4a16
0x6f497f  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x6f4982  83e810                            sub    eax,0x10
0x6f4985  8944240c                          mov    DWORD PTR [esp+0xc],eax
0x6f4989  2b4720                            sub    eax,DWORD PTR [edi+0x20]
0x6f498c  8d4c240c                          lea    ecx,[esp+0xc]
0x6f4990  50                                push   eax
0x6f4991  51                                push   ecx
0x6f4992  eb4f                              jmp    0x6f49e3
0x6f4994  89442410                          mov    DWORD PTR [esp+0x10],eax
0x6f4998  33c0                              xor    eax,eax
0x6f499a  8d54240c                          lea    edx,[esp+0xc]
0x6f499e  89442414                          mov    DWORD PTR [esp+0x14],eax
0x6f49a2  89442418                          mov    DWORD PTR [esp+0x18],eax
0x6f49a6  57                                push   edi
0x6f49a7  b90027c400                        mov    ecx,0xc42700
0x6f49ac  8d442418                          lea    eax,[esp+0x18]
0x6f49b0  895c2410                          mov    DWORD PTR [esp+0x10],ebx
0x6f49b4  897c2428                          mov    DWORD PTR [esp+0x28],edi
0x6f49b8  c7442420e0706f00                  mov    DWORD PTR [esp+0x20],0x6f70e0
0x6f49c0  89542424                          mov    DWORD PTR [esp+0x24],edx
0x6f49c4  e8c79f0000                        call   0x6fe990
0x6f49c9  83c404                            add    esp,0x4
0x6f49cc  85c0                              test   eax,eax
0x6f49ce  7546                              jne    0x6f4a16
0x6f49d0  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x6f49d3  83e810                            sub    eax,0x10
0x6f49d6  8944240c                          mov    DWORD PTR [esp+0xc],eax
0x6f49da  2b4720                            sub    eax,DWORD PTR [edi+0x20]
0x6f49dd  50                                push   eax
0x6f49de  8d442410                          lea    eax,[esp+0x10]
0x6f49e2  50                                push   eax
0x6f49e3  68505a6f00                        push   0x6f5a50
0x6f49e8  33d2                              xor    edx,edx
0x6f49ea  8bc7                              mov    eax,edi
0x6f49ec  c744241cffffffff                  mov    DWORD PTR [esp+0x1c],0xffffffff
0x6f49f4  e8779d0000                        call   0x6fe770
0x6f49f9  8b4f14                            mov    ecx,DWORD PTR [edi+0x14]
0x6f49fc  8b5708                            mov    edx,DWORD PTR [edi+0x8]
0x6f49ff  83c40c                            add    esp,0xc
0x6f4a02  3b5108                            cmp    edx,DWORD PTR [ecx+0x8]
0x6f4a05  7203                              jb     0x6f4a0a
0x6f4a07  895108                            mov    DWORD PTR [ecx+0x8],edx
0x6f4a0a  c744240c00000000                  mov    DWORD PTR [esp+0xc],0x0
0x6f4a12  85c0                              test   eax,eax
0x6f4a14  7408                              je     0x6f4a1e
0x6f4a16  c744240c01000000                  mov    DWORD PTR [esp+0xc],0x1
0x6f4a1e  8b16                              mov    edx,DWORD PTR [esi]
0x6f4a20  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x6f4a23  8bce                              mov    ecx,esi
0x6f4a25  ffd0                              call   eax
0x6f4a27  53                                push   ebx
0x6f4a28  e810d31900                        call   0x891d3d
0x6f4a2d  83c404                            add    esp,0x4
0x6f4a30  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x6f4a33  db44240c                          fild   DWORD PTR [esp+0xc]
0x6f4a37  c7400803000000                    mov    DWORD PTR [eax+0x8],0x3
0x6f4a3e  dd18                              fstp   QWORD PTR [eax]
0x6f4a40  83470810                          add    DWORD PTR [edi+0x8],0x10
0x6f4a44  5f                                pop    edi
0x6f4a45  5e                                pop    esi
0x6f4a46  b801000000                        mov    eax,0x1
0x6f4a4b  5b                                pop    ebx
0x6f4a4c  8be5                              mov    esp,ebp
0x6f4a4e  5d                                pop    ebp
0x6f4a4f  c3                                ret

; coroutine_yield 0x707480..0x7074c0 Reused Lua 5.1 C boundary/depth guard
0x707480  55                                push   ebp
0x707481  8bec                              mov    ebp,esp
0x707483  56                                push   esi
0x707484  57                                push   edi
0x707485  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x707488  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x70748b  668b4734                          mov    ax,WORD PTR [edi+0x34]
0x70748f  2b770c                            sub    esi,DWORD PTR [edi+0xc]
0x707492  663b4736                          cmp    ax,WORD PTR [edi+0x36]
0x707496  760e                              jbe    0x7074a6
0x707498  68402bc400                        push   0xc42b40
0x70749d  57                                push   edi
0x70749e  e8bd16ffff                        call   0x6f8b60
0x7074a3  83c408                            add    esp,0x8
0x7074a6  8b4f08                            mov    ecx,DWORD PTR [edi+0x8]
0x7074a9  83e6f0                            and    esi,0xfffffff0
0x7074ac  2bce                              sub    ecx,esi
0x7074ae  894f0c                            mov    DWORD PTR [edi+0xc],ecx
0x7074b1  c6470601                          mov    BYTE PTR [edi+0x6],0x1
0x7074b5  5f                                pop    edi
0x7074b6  83c8ff                            or     eax,0xffffffff
0x7074b9  5e                                pop    esi
0x7074ba  5d                                pop    ebp
0x7074bb  c3                                ret
0x7074bc  cc                                int3
0x7074bd  cc                                int3
0x7074be  cc                                int3
0x7074bf  cc                                int3

; gc_mark 0x6f9f70..0x6fa02e Tag-specific marking; gray lists and upvalue mark
0x6f9f70  55                                push   ebp
0x6f9f71  8bec                              mov    ebp,esp
0x6f9f73  56                                push   esi
0x6f9f74  8b750c                            mov    esi,DWORD PTR [ebp+0xc]
0x6f9f77  0fb64604                          movzx  eax,BYTE PTR [esi+0x4]
0x6f9f7b  806605fc                          and    BYTE PTR [esi+0x5],0xfc
0x6f9f7f  83e804                            sub    eax,0x4
0x6f9f82  83f806                            cmp    eax,0x6
0x6f9f85  0f87a0000000                      ja     0x6fa02b
0x6f9f8b  57                                push   edi
0x6f9f8c  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x6f9f8f  90                                nop
0x6f9f90  ff248530a06f00                    jmp    DWORD PTR [eax*4+0x6fa030]
0x6f9f97  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6f9f9a  804e0504                          or     BYTE PTR [esi+0x5],0x4
0x6f9f9e  85c0                              test   eax,eax
0x6f9fa0  7410                              je     0x6f9fb2
0x6f9fa2  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6f9fa6  740a                              je     0x6f9fb2
0x6f9fa8  50                                push   eax
0x6f9fa9  57                                push   edi
0x6f9faa  e8c1ffffff                        call   0x6f9f70
0x6f9faf  83c408                            add    esp,0x8
0x6f9fb2  8b760c                            mov    esi,DWORD PTR [esi+0xc]
0x6f9fb5  f6460503                          test   BYTE PTR [esi+0x5],0x3
0x6f9fb9  746f                              je     0x6fa02a
0x6f9fbb  806605fc                          and    BYTE PTR [esi+0x5],0xfc
0x6f9fbf  0fb64604                          movzx  eax,BYTE PTR [esi+0x4]
0x6f9fc3  83e804                            sub    eax,0x4
0x6f9fc6  83f806                            cmp    eax,0x6
0x6f9fc9  76c5                              jbe    0x6f9f90
0x6f9fcb  5f                                pop    edi
0x6f9fcc  5e                                pop    esi
0x6f9fcd  5d                                pop    ebp
0x6f9fce  c3                                ret
0x6f9fcf  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6f9fd2  83780804                          cmp    DWORD PTR [eax+0x8],0x4
0x6f9fd6  7c12                              jl     0x6f9fea
0x6f9fd8  8b00                              mov    eax,DWORD PTR [eax]
0x6f9fda  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6f9fde  740a                              je     0x6f9fea
0x6f9fe0  50                                push   eax
0x6f9fe1  57                                push   edi
0x6f9fe2  e889ffffff                        call   0x6f9f70
0x6f9fe7  83c408                            add    esp,0x8
0x6f9fea  8d4610                            lea    eax,[esi+0x10]
0x6f9fed  394608                            cmp    DWORD PTR [esi+0x8],eax
0x6f9ff0  7538                              jne    0x6fa02a
0x6f9ff2  804e0504                          or     BYTE PTR [esi+0x5],0x4
0x6f9ff6  5f                                pop    edi
0x6f9ff7  5e                                pop    esi
0x6f9ff8  5d                                pop    ebp
0x6f9ff9  c3                                ret
0x6f9ffa  8b4f24                            mov    ecx,DWORD PTR [edi+0x24]
0x6f9ffd  894e08                            mov    DWORD PTR [esi+0x8],ecx
0x6fa000  897724                            mov    DWORD PTR [edi+0x24],esi
0x6fa003  5f                                pop    edi
0x6fa004  5e                                pop    esi
0x6fa005  5d                                pop    ebp
0x6fa006  c3                                ret
0x6fa007  8b5724                            mov    edx,DWORD PTR [edi+0x24]
0x6fa00a  895618                            mov    DWORD PTR [esi+0x18],edx
0x6fa00d  897724                            mov    DWORD PTR [edi+0x24],esi
0x6fa010  5f                                pop    edi
0x6fa011  5e                                pop    esi
0x6fa012  5d                                pop    ebp
0x6fa013  c3                                ret
0x6fa014  8b4724                            mov    eax,DWORD PTR [edi+0x24]
0x6fa017  89466c                            mov    DWORD PTR [esi+0x6c],eax
0x6fa01a  897724                            mov    DWORD PTR [edi+0x24],esi
0x6fa01d  5f                                pop    edi
0x6fa01e  5e                                pop    esi
0x6fa01f  5d                                pop    ebp
0x6fa020  c3                                ret
0x6fa021  8b4f24                            mov    ecx,DWORD PTR [edi+0x24]
0x6fa024  894e44                            mov    DWORD PTR [esi+0x44],ecx
0x6fa027  897724                            mov    DWORD PTR [edi+0x24],esi
0x6fa02a  5f                                pop    edi
0x6fa02b  5e                                pop    esi
0x6fa02c  5d                                pop    ebp
0x6fa02d  c3                                ret

; DATA gc_mark_switch 0x6fa030..0x6fa04c
; 2aa06f0007a06f00fa9f6f00979f6f0014a06f0021a06f00cf9f6f00

; gc_table 0x6fa1e0..0x6fa38a Strong ordinary table array/hash values are marked
0x6fa1e0  55                                push   ebp
0x6fa1e1  8bec                              mov    ebp,esp
0x6fa1e3  83ec0c                            sub    esp,0xc
0x6fa1e6  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x6fa1e9  53                                push   ebx
0x6fa1ea  56                                push   esi
0x6fa1eb  33f6                              xor    esi,esi
0x6fa1ed  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x6fa1f0  8975f8                            mov    DWORD PTR [ebp-0x8],esi
0x6fa1f3  3bc6                              cmp    eax,esi
0x6fa1f5  7413                              je     0x6fa20a
0x6fa1f7  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa1fb  740d                              je     0x6fa20a
0x6fa1fd  50                                push   eax
0x6fa1fe  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6fa201  50                                push   eax
0x6fa202  e869fdffff                        call   0x6f9f70
0x6fa207  83c408                            add    esp,0x8
0x6fa20a  8b5708                            mov    edx,DWORD PTR [edi+0x8]
0x6fa20d  3bd6                              cmp    edx,esi
0x6fa20f  0f849a000000                      je     0x6fa2af
0x6fa215  f6420608                          test   BYTE PTR [edx+0x6],0x8
0x6fa219  0f8590000000                      jne    0x6fa2af
0x6fa21f  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x6fa222  8bb1c8000000                      mov    esi,DWORD PTR [ecx+0xc8]
0x6fa228  6a03                              push   0x3
0x6fa22a  e831480000                        call   0x6fea60
0x6fa22f  8bf0                              mov    esi,eax
0x6fa231  83c404                            add    esp,0x4
0x6fa234  85f6                              test   esi,esi
0x6fa236  7477                              je     0x6fa2af
0x6fa238  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x6fa23c  7571                              jne    0x6fa2af
0x6fa23e  8b16                              mov    edx,DWORD PTR [esi]
0x6fa240  83c210                            add    edx,0x10
0x6fa243  6a6b                              push   0x6b
0x6fa245  52                                push   edx
0x6fa246  e895741900                        call   0x8916e0
0x6fa24b  f7d8                              neg    eax
0x6fa24d  1bdb                              sbb    ebx,ebx
0x6fa24f  8b06                              mov    eax,DWORD PTR [esi]
0x6fa251  83c010                            add    eax,0x10
0x6fa254  6a76                              push   0x76
0x6fa256  f7db                              neg    ebx
0x6fa258  50                                push   eax
0x6fa259  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x6fa25c  e87f741900                        call   0x8916e0
0x6fa261  83c410                            add    esp,0x10
0x6fa264  f7d8                              neg    eax
0x6fa266  1bc0                              sbb    eax,eax
0x6fa268  f7d8                              neg    eax
0x6fa26a  8945f8                            mov    DWORD PTR [ebp-0x8],eax
0x6fa26d  85db                              test   ebx,ebx
0x6fa26f  7504                              jne    0x6fa275
0x6fa271  85c0                              test   eax,eax
0x6fa273  743a                              je     0x6fa2af
0x6fa275  8a5705                            mov    dl,BYTE PTR [edi+0x5]
0x6fa278  8ac8                              mov    cl,al
0x6fa27a  02c9                              add    cl,cl
0x6fa27c  0acb                              or     cl,bl
0x6fa27e  02c9                              add    cl,cl
0x6fa280  02c9                              add    cl,cl
0x6fa282  02c9                              add    cl,cl
0x6fa284  80e2e7                            and    dl,0xe7
0x6fa287  0aca                              or     cl,dl
0x6fa289  884f05                            mov    BYTE PTR [edi+0x5],cl
0x6fa28c  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x6fa28f  8b512c                            mov    edx,DWORD PTR [ecx+0x2c]
0x6fa292  895718                            mov    DWORD PTR [edi+0x18],edx
0x6fa295  89792c                            mov    DWORD PTR [ecx+0x2c],edi
0x6fa298  85db                              test   ebx,ebx
0x6fa29a  740f                              je     0x6fa2ab
0x6fa29c  85c0                              test   eax,eax
0x6fa29e  740f                              je     0x6fa2af
0x6fa2a0  5e                                pop    esi
0x6fa2a1  b801000000                        mov    eax,0x1
0x6fa2a6  5b                                pop    ebx
0x6fa2a7  8be5                              mov    esp,ebp
0x6fa2a9  5d                                pop    ebp
0x6fa2aa  c3                                ret
0x6fa2ab  85c0                              test   eax,eax
0x6fa2ad  7539                              jne    0x6fa2e8
0x6fa2af  8b5f1c                            mov    ebx,DWORD PTR [edi+0x1c]
0x6fa2b2  85db                              test   ebx,ebx
0x6fa2b4  7432                              je     0x6fa2e8
0x6fa2b6  8bf3                              mov    esi,ebx
0x6fa2b8  c1e604                            shl    esi,0x4
0x6fa2bb  eb03                              jmp    0x6fa2c0
0x6fa2bd  8d4900                            lea    ecx,[ecx+0x0]
0x6fa2c0  8b470c                            mov    eax,DWORD PTR [edi+0xc]
0x6fa2c3  83ee10                            sub    esi,0x10
0x6fa2c6  4b                                dec    ebx
0x6fa2c7  837c300804                        cmp    DWORD PTR [eax+esi*1+0x8],0x4
0x6fa2cc  7c16                              jl     0x6fa2e4
0x6fa2ce  8b0430                            mov    eax,DWORD PTR [eax+esi*1]
0x6fa2d1  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa2d5  740d                              je     0x6fa2e4
0x6fa2d7  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x6fa2da  50                                push   eax
0x6fa2db  51                                push   ecx
0x6fa2dc  e88ffcffff                        call   0x6f9f70
0x6fa2e1  83c408                            add    esp,0x8
0x6fa2e4  85db                              test   ebx,ebx
0x6fa2e6  75d8                              jne    0x6fa2c0
0x6fa2e8  8a4f07                            mov    cl,BYTE PTR [edi+0x7]
0x6fa2eb  bb01000000                        mov    ebx,0x1
0x6fa2f0  d3e3                              shl    ebx,cl
0x6fa2f2  85db                              test   ebx,ebx
0x6fa2f4  7478                              je     0x6fa36e
0x6fa2f6  8bcb                              mov    ecx,ebx
0x6fa2f8  c1e105                            shl    ecx,0x5
0x6fa2fb  eb03                              jmp    0x6fa300
0x6fa2fd  8d4900                            lea    ecx,[ecx+0x0]
0x6fa300  8b7710                            mov    esi,DWORD PTR [edi+0x10]
0x6fa303  83e920                            sub    ecx,0x20
0x6fa306  03f1                              add    esi,ecx
0x6fa308  4b                                dec    ebx
0x6fa309  837e0800                          cmp    DWORD PTR [esi+0x8],0x0
0x6fa30d  894df4                            mov    DWORD PTR [ebp-0xc],ecx
0x6fa310  750f                              jne    0x6fa321
0x6fa312  837e1804                          cmp    DWORD PTR [esi+0x18],0x4
0x6fa316  7c52                              jl     0x6fa36a
0x6fa318  c746180b000000                    mov    DWORD PTR [esi+0x18],0xb
0x6fa31f  eb49                              jmp    0x6fa36a
0x6fa321  837dfc00                          cmp    DWORD PTR [ebp-0x4],0x0
0x6fa325  751f                              jne    0x6fa346
0x6fa327  837e1804                          cmp    DWORD PTR [esi+0x18],0x4
0x6fa32b  7c19                              jl     0x6fa346
0x6fa32d  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x6fa330  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa334  7410                              je     0x6fa346
0x6fa336  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x6fa339  50                                push   eax
0x6fa33a  52                                push   edx
0x6fa33b  e830fcffff                        call   0x6f9f70
0x6fa340  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x6fa343  83c408                            add    esp,0x8
0x6fa346  837df800                          cmp    DWORD PTR [ebp-0x8],0x0
0x6fa34a  751e                              jne    0x6fa36a
0x6fa34c  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x6fa350  7c18                              jl     0x6fa36a
0x6fa352  8b36                              mov    esi,DWORD PTR [esi]
0x6fa354  f6460503                          test   BYTE PTR [esi+0x5],0x3
0x6fa358  7410                              je     0x6fa36a
0x6fa35a  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6fa35d  56                                push   esi
0x6fa35e  50                                push   eax
0x6fa35f  e80cfcffff                        call   0x6f9f70
0x6fa364  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x6fa367  83c408                            add    esp,0x8
0x6fa36a  85db                              test   ebx,ebx
0x6fa36c  7592                              jne    0x6fa300
0x6fa36e  837dfc00                          cmp    DWORD PTR [ebp-0x4],0x0
0x6fa372  0f8528ffffff                      jne    0x6fa2a0
0x6fa378  837df800                          cmp    DWORD PTR [ebp-0x8],0x0
0x6fa37c  0f851effffff                      jne    0x6fa2a0
0x6fa382  5e                                pop    esi
0x6fa383  33c0                              xor    eax,eax
0x6fa385  5b                                pop    ebx
0x6fa386  8be5                              mov    esp,ebp
0x6fa388  5d                                pop    ebp
0x6fa389  c3                                ret

; gc_closure 0x6fa460..0x6fa5b5 Lua closure prototype and upvalue traversal
0x6fa460  55                                push   ebp
0x6fa461  8bec                              mov    ebp,esp
0x6fa463  51                                push   ecx
0x6fa464  53                                push   ebx
0x6fa465  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6fa468  56                                push   esi
0x6fa469  8b750c                            mov    esi,DWORD PTR [ebp+0xc]
0x6fa46c  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x6fa46f  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa473  57                                push   edi
0x6fa474  740a                              je     0x6fa480
0x6fa476  50                                push   eax
0x6fa477  53                                push   ebx
0x6fa478  e8f3faffff                        call   0x6f9f70
0x6fa47d  83c408                            add    esp,0x8
0x6fa480  807e0600                          cmp    BYTE PTR [esi+0x6],0x0
0x6fa484  743d                              je     0x6fa4c3
0x6fa486  33ff                              xor    edi,edi
0x6fa488  807e0700                          cmp    BYTE PTR [esi+0x7],0x0
0x6fa48c  0f861c010000                      jbe    0x6fa5ae
0x6fa492  83c618                            add    esi,0x18
0x6fa495  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x6fa499  7c12                              jl     0x6fa4ad
0x6fa49b  8b06                              mov    eax,DWORD PTR [esi]
0x6fa49d  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa4a1  740a                              je     0x6fa4ad
0x6fa4a3  50                                push   eax
0x6fa4a4  53                                push   ebx
0x6fa4a5  e8c6faffff                        call   0x6f9f70
0x6fa4aa  83c408                            add    esp,0x8
0x6fa4ad  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6fa4b0  0fb64807                          movzx  ecx,BYTE PTR [eax+0x7]
0x6fa4b4  47                                inc    edi
0x6fa4b5  83c610                            add    esi,0x10
0x6fa4b8  3bf9                              cmp    edi,ecx
0x6fa4ba  7cd9                              jl     0x6fa495
0x6fa4bc  5f                                pop    edi
0x6fa4bd  5e                                pop    esi
0x6fa4be  5b                                pop    ebx
0x6fa4bf  8be5                              mov    esp,ebp
0x6fa4c1  5d                                pop    ebp
0x6fa4c2  c3                                ret
0x6fa4c3  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x6fa4c6  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa4ca  740a                              je     0x6fa4d6
0x6fa4cc  50                                push   eax
0x6fa4cd  53                                push   ebx
0x6fa4ce  e89dfaffff                        call   0x6f9f70
0x6fa4d3  83c408                            add    esp,0x8
0x6fa4d6  33ff                              xor    edi,edi
0x6fa4d8  807e0700                          cmp    BYTE PTR [esi+0x7],0x0
0x6fa4dc  0f86cc000000                      jbe    0x6fa5ae
0x6fa4e2  83c614                            add    esi,0x14
0x6fa4e5  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x6fa4e8  eb06                              jmp    0x6fa4f0
0x6fa4ea  8d9b00000000                      lea    ebx,[ebx+0x0]
0x6fa4f0  8b36                              mov    esi,DWORD PTR [esi]
0x6fa4f2  f6460503                          test   BYTE PTR [esi+0x5],0x3
0x6fa4f6  0f8499000000                      je     0x6fa595
0x6fa4fc  0fb64e04                          movzx  ecx,BYTE PTR [esi+0x4]
0x6fa500  806605fc                          and    BYTE PTR [esi+0x5],0xfc
0x6fa504  8a4605                            mov    al,BYTE PTR [esi+0x5]
0x6fa507  83c1fc                            add    ecx,0xfffffffc
0x6fa50a  83f906                            cmp    ecx,0x6
0x6fa50d  0f8782000000                      ja     0x6fa595
0x6fa513  ff248db8a56f00                    jmp    DWORD PTR [ecx*4+0x6fa5b8]
0x6fa51a  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6fa51d  0c04                              or     al,0x4
0x6fa51f  884605                            mov    BYTE PTR [esi+0x5],al
0x6fa522  85c9                              test   ecx,ecx
0x6fa524  7410                              je     0x6fa536
0x6fa526  f6410503                          test   BYTE PTR [ecx+0x5],0x3
0x6fa52a  740a                              je     0x6fa536
0x6fa52c  51                                push   ecx
0x6fa52d  53                                push   ebx
0x6fa52e  e83dfaffff                        call   0x6f9f70
0x6fa533  83c408                            add    esp,0x8
0x6fa536  8b760c                            mov    esi,DWORD PTR [esi+0xc]
0x6fa539  f6460503                          test   BYTE PTR [esi+0x5],0x3
0x6fa53d  7456                              je     0x6fa595
0x6fa53f  56                                push   esi
0x6fa540  53                                push   ebx
0x6fa541  e82afaffff                        call   0x6f9f70
0x6fa546  83c408                            add    esp,0x8
0x6fa549  eb4a                              jmp    0x6fa595
0x6fa54b  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6fa54e  83780804                          cmp    DWORD PTR [eax+0x8],0x4
0x6fa552  7c12                              jl     0x6fa566
0x6fa554  8b00                              mov    eax,DWORD PTR [eax]
0x6fa556  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa55a  740a                              je     0x6fa566
0x6fa55c  50                                push   eax
0x6fa55d  53                                push   ebx
0x6fa55e  e80dfaffff                        call   0x6f9f70
0x6fa563  83c408                            add    esp,0x8
0x6fa566  8d5610                            lea    edx,[esi+0x10]
0x6fa569  395608                            cmp    DWORD PTR [esi+0x8],edx
0x6fa56c  7527                              jne    0x6fa595
0x6fa56e  804e0504                          or     BYTE PTR [esi+0x5],0x4
0x6fa572  eb21                              jmp    0x6fa595
0x6fa574  8b4324                            mov    eax,DWORD PTR [ebx+0x24]
0x6fa577  894608                            mov    DWORD PTR [esi+0x8],eax
0x6fa57a  eb16                              jmp    0x6fa592
0x6fa57c  8b4b24                            mov    ecx,DWORD PTR [ebx+0x24]
0x6fa57f  894e18                            mov    DWORD PTR [esi+0x18],ecx
0x6fa582  eb0e                              jmp    0x6fa592
0x6fa584  8b5324                            mov    edx,DWORD PTR [ebx+0x24]
0x6fa587  89566c                            mov    DWORD PTR [esi+0x6c],edx
0x6fa58a  eb06                              jmp    0x6fa592
0x6fa58c  8b4324                            mov    eax,DWORD PTR [ebx+0x24]
0x6fa58f  894644                            mov    DWORD PTR [esi+0x44],eax
0x6fa592  897324                            mov    DWORD PTR [ebx+0x24],esi
0x6fa595  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x6fa598  8b75fc                            mov    esi,DWORD PTR [ebp-0x4]
0x6fa59b  0fb65107                          movzx  edx,BYTE PTR [ecx+0x7]
0x6fa59f  47                                inc    edi
0x6fa5a0  83c604                            add    esi,0x4
0x6fa5a3  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x6fa5a6  3bfa                              cmp    edi,edx
0x6fa5a8  0f8c42ffffff                      jl     0x6fa4f0
0x6fa5ae  5f                                pop    edi
0x6fa5af  5e                                pop    esi
0x6fa5b0  5b                                pop    ebx
0x6fa5b1  8be5                              mov    esp,ebp
0x6fa5b3  5d                                pop    ebp
0x6fa5b4  c3                                ret

; DATA gc_closure_switch 0x6fa5b8..0x6fa5d4
; 95a56f007ca56f0074a56f001aa56f0084a56f008ca56f004ba56f00

; gc_thread_stack_prefix 0x6fa5e0..0x6fa653 Thread globals and stack values marked before storage shrink
0x6fa5e0  55                                push   ebp
0x6fa5e1  8bec                              mov    ebp,esp
0x6fa5e3  83ec08                            sub    esp,0x8
0x6fa5e6  837e5004                          cmp    DWORD PTR [esi+0x50],0x4
0x6fa5ea  7c16                              jl     0x6fa602
0x6fa5ec  8b4648                            mov    eax,DWORD PTR [esi+0x48]
0x6fa5ef  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa5f3  740d                              je     0x6fa602
0x6fa5f5  50                                push   eax
0x6fa5f6  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6fa5f9  50                                push   eax
0x6fa5fa  e871f9ffff                        call   0x6f9f70
0x6fa5ff  83c408                            add    esp,0x8
0x6fa602  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x6fa605  8b5608                            mov    edx,DWORD PTR [esi+0x8]
0x6fa608  53                                push   ebx
0x6fa609  57                                push   edi
0x6fa60a  8bda                              mov    ebx,edx
0x6fa60c  3b4614                            cmp    eax,DWORD PTR [esi+0x14]
0x6fa60f  7713                              ja     0x6fa624
0x6fa611  8b7e14                            mov    edi,DWORD PTR [esi+0x14]
0x6fa614  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x6fa617  3bd9                              cmp    ebx,ecx
0x6fa619  7302                              jae    0x6fa61d
0x6fa61b  8bd9                              mov    ebx,ecx
0x6fa61d  83c018                            add    eax,0x18
0x6fa620  3bc7                              cmp    eax,edi
0x6fa622  76f0                              jbe    0x6fa614
0x6fa624  8b7e20                            mov    edi,DWORD PTR [esi+0x20]
0x6fa627  3bfa                              cmp    edi,edx
0x6fa629  7328                              jae    0x6fa653
0x6fa62b  eb03                              jmp    0x6fa630
0x6fa62d  8d4900                            lea    ecx,[ecx+0x0]
0x6fa630  837f0804                          cmp    DWORD PTR [edi+0x8],0x4
0x6fa634  7c15                              jl     0x6fa64b
0x6fa636  8b07                              mov    eax,DWORD PTR [edi]
0x6fa638  f6400503                          test   BYTE PTR [eax+0x5],0x3
0x6fa63c  740d                              je     0x6fa64b
0x6fa63e  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x6fa641  50                                push   eax
0x6fa642  51                                push   ecx
0x6fa643  e828f9ffff                        call   0x6f9f70
0x6fa648  83c408                            add    esp,0x8
0x6fa64b  83c710                            add    edi,0x10
0x6fa64e  3b7e08                            cmp    edi,DWORD PTR [esi+0x8]
0x6fa651  72dd                              jb     0x6fa630

; gc_propagate_one 0x6fa790..0x6fa86d Concrete table/closure/thread mark target dispatch
0x6fa790  56                                push   esi
0x6fa791  8b7024                            mov    esi,DWORD PTR [eax+0x24]
0x6fa794  0fb64e04                          movzx  ecx,BYTE PTR [esi+0x4]
0x6fa798  804e0504                          or     BYTE PTR [esi+0x5],0x4
0x6fa79c  83c1fb                            add    ecx,0xfffffffb
0x6fa79f  83f904                            cmp    ecx,0x4
0x6fa7a2  0f87c1000000                      ja     0x6fa869
0x6fa7a8  ff248d70a86f00                    jmp    DWORD PTR [ecx*4+0x6fa870]
0x6fa7af  8b4e18                            mov    ecx,DWORD PTR [esi+0x18]
0x6fa7b2  57                                push   edi
0x6fa7b3  50                                push   eax
0x6fa7b4  8bfe                              mov    edi,esi
0x6fa7b6  894824                            mov    DWORD PTR [eax+0x24],ecx
0x6fa7b9  e822faffff                        call   0x6fa1e0
0x6fa7be  83c404                            add    esp,0x4
0x6fa7c1  5f                                pop    edi
0x6fa7c2  85c0                              test   eax,eax
0x6fa7c4  7404                              je     0x6fa7ca
0x6fa7c6  806605fb                          and    BYTE PTR [esi+0x5],0xfb
0x6fa7ca  8a4e07                            mov    cl,BYTE PTR [esi+0x7]
0x6fa7cd  8b461c                            mov    eax,DWORD PTR [esi+0x1c]
0x6fa7d0  ba01000000                        mov    edx,0x1
0x6fa7d5  d3e2                              shl    edx,cl
0x6fa7d7  5e                                pop    esi
0x6fa7d8  8d445002                          lea    eax,[eax+edx*2+0x2]
0x6fa7dc  c1e004                            shl    eax,0x4
0x6fa7df  c3                                ret
0x6fa7e0  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6fa7e3  56                                push   esi
0x6fa7e4  50                                push   eax
0x6fa7e5  894824                            mov    DWORD PTR [eax+0x24],ecx
0x6fa7e8  e873fcffff                        call   0x6fa460
0x6fa7ed  0fb64607                          movzx  eax,BYTE PTR [esi+0x7]
0x6fa7f1  83c408                            add    esp,0x8
0x6fa7f4  807e0600                          cmp    BYTE PTR [esi+0x6],0x0
0x6fa7f8  7408                              je     0x6fa802
0x6fa7fa  c1e004                            shl    eax,0x4
0x6fa7fd  83c018                            add    eax,0x18
0x6fa800  5e                                pop    esi
0x6fa801  c3                                ret
0x6fa802  8d048514000000                    lea    eax,[eax*4+0x14]
0x6fa809  5e                                pop    esi
0x6fa80a  c3                                ret
0x6fa80b  8b566c                            mov    edx,DWORD PTR [esi+0x6c]
0x6fa80e  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x6fa811  895024                            mov    DWORD PTR [eax+0x24],edx
0x6fa814  894e6c                            mov    DWORD PTR [esi+0x6c],ecx
0x6fa817  897028                            mov    DWORD PTR [eax+0x28],esi
0x6fa81a  806605fb                          and    BYTE PTR [esi+0x5],0xfb
0x6fa81e  50                                push   eax
0x6fa81f  e8bcfdffff                        call   0x6fa5e0
0x6fa824  8b4630                            mov    eax,DWORD PTR [esi+0x30]
0x6fa827  8d54400f                          lea    edx,[eax+eax*2+0xf]
0x6fa82b  8b462c                            mov    eax,DWORD PTR [esi+0x2c]
0x6fa82e  83c404                            add    esp,0x4
0x6fa831  c1e004                            shl    eax,0x4
0x6fa834  8d04d0                            lea    eax,[eax+edx*8]
0x6fa837  5e                                pop    esi
0x6fa838  c3                                ret
0x6fa839  8b4e44                            mov    ecx,DWORD PTR [esi+0x44]
0x6fa83c  50                                push   eax
0x6fa83d  894824                            mov    DWORD PTR [eax+0x24],ecx
0x6fa840  e84bfbffff                        call   0x6fa390
0x6fa845  8b4638                            mov    eax,DWORD PTR [esi+0x38]
0x6fa848  8d1440                            lea    edx,[eax+eax*2]
0x6fa84b  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x6fa84e  8d0482                            lea    eax,[edx+eax*4]
0x6fa851  034634                            add    eax,DWORD PTR [esi+0x34]
0x6fa854  83c404                            add    esp,0x4
0x6fa857  034630                            add    eax,DWORD PTR [esi+0x30]
0x6fa85a  03462c                            add    eax,DWORD PTR [esi+0x2c]
0x6fa85d  034624                            add    eax,DWORD PTR [esi+0x24]
0x6fa860  5e                                pop    esi
0x6fa861  8d04854c000000                    lea    eax,[eax*4+0x4c]
0x6fa868  c3                                ret
0x6fa869  33c0                              xor    eax,eax
0x6fa86b  5e                                pop    esi
0x6fa86c  c3                                ret

; DATA gc_propagate_one_switch 0x6fa870..0x6fa884
; afa76f00e0a76f0069a86f000ba86f0039a86f00

; gc_propagate_all 0x6fa890..0x6fa9a0 Full gray-loop dispatch for table/closure/thread
0x6fa890  55                                push   ebp
0x6fa891  8bec                              mov    ebp,esp
0x6fa893  53                                push   ebx
0x6fa894  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6fa897  33c0                              xor    eax,eax
0x6fa899  894508                            mov    DWORD PTR [ebp+0x8],eax
0x6fa89c  394324                            cmp    DWORD PTR [ebx+0x24],eax
0x6fa89f  0f84f8000000                      je     0x6fa99d
0x6fa8a5  56                                push   esi
0x6fa8a6  57                                push   edi
0x6fa8a7  eb07                              jmp    0x6fa8b0
0x6fa8a9  8da42400000000                    lea    esp,[esp+0x0]
0x6fa8b0  8b7324                            mov    esi,DWORD PTR [ebx+0x24]
0x6fa8b3  0fb64604                          movzx  eax,BYTE PTR [esi+0x4]
0x6fa8b7  804e0504                          or     BYTE PTR [esi+0x5],0x4
0x6fa8bb  83c0fb                            add    eax,0xfffffffb
0x6fa8be  83f804                            cmp    eax,0x4
0x6fa8c1  0f87c2000000                      ja     0x6fa989
0x6fa8c7  ff2485a0a96f00                    jmp    DWORD PTR [eax*4+0x6fa9a0]
0x6fa8ce  8b4618                            mov    eax,DWORD PTR [esi+0x18]
0x6fa8d1  53                                push   ebx
0x6fa8d2  8bfe                              mov    edi,esi
0x6fa8d4  894324                            mov    DWORD PTR [ebx+0x24],eax
0x6fa8d7  e804f9ffff                        call   0x6fa1e0
0x6fa8dc  83c404                            add    esp,0x4
0x6fa8df  85c0                              test   eax,eax
0x6fa8e1  7404                              je     0x6fa8e7
0x6fa8e3  806605fb                          and    BYTE PTR [esi+0x5],0xfb
0x6fa8e7  8a4e07                            mov    cl,BYTE PTR [esi+0x7]
0x6fa8ea  8b461c                            mov    eax,DWORD PTR [esi+0x1c]
0x6fa8ed  ba01000000                        mov    edx,0x1
0x6fa8f2  d3e2                              shl    edx,cl
0x6fa8f4  8d445002                          lea    eax,[eax+edx*2+0x2]
0x6fa8f8  c1e004                            shl    eax,0x4
0x6fa8fb  e98b000000                        jmp    0x6fa98b
0x6fa900  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6fa903  56                                push   esi
0x6fa904  53                                push   ebx
0x6fa905  894b24                            mov    DWORD PTR [ebx+0x24],ecx
0x6fa908  e853fbffff                        call   0x6fa460
0x6fa90d  0fb64607                          movzx  eax,BYTE PTR [esi+0x7]
0x6fa911  83c408                            add    esp,0x8
0x6fa914  807e0600                          cmp    BYTE PTR [esi+0x6],0x0
0x6fa918  7408                              je     0x6fa922
0x6fa91a  c1e004                            shl    eax,0x4
0x6fa91d  83c018                            add    eax,0x18
0x6fa920  eb69                              jmp    0x6fa98b
0x6fa922  8d048514000000                    lea    eax,[eax*4+0x14]
0x6fa929  eb60                              jmp    0x6fa98b
0x6fa92b  8b566c                            mov    edx,DWORD PTR [esi+0x6c]
0x6fa92e  8b4328                            mov    eax,DWORD PTR [ebx+0x28]
0x6fa931  895324                            mov    DWORD PTR [ebx+0x24],edx
0x6fa934  89466c                            mov    DWORD PTR [esi+0x6c],eax
0x6fa937  897328                            mov    DWORD PTR [ebx+0x28],esi
0x6fa93a  806605fb                          and    BYTE PTR [esi+0x5],0xfb
0x6fa93e  53                                push   ebx
0x6fa93f  e89cfcffff                        call   0x6fa5e0
0x6fa944  8b4630                            mov    eax,DWORD PTR [esi+0x30]
0x6fa947  8b562c                            mov    edx,DWORD PTR [esi+0x2c]
0x6fa94a  83c404                            add    esp,0x4
0x6fa94d  8d4c400f                          lea    ecx,[eax+eax*2+0xf]
0x6fa951  c1e204                            shl    edx,0x4
0x6fa954  8d04ca                            lea    eax,[edx+ecx*8]
0x6fa957  eb32                              jmp    0x6fa98b
0x6fa959  8b4644                            mov    eax,DWORD PTR [esi+0x44]
0x6fa95c  53                                push   ebx
0x6fa95d  894324                            mov    DWORD PTR [ebx+0x24],eax
0x6fa960  e82bfaffff                        call   0x6fa390
0x6fa965  8b4638                            mov    eax,DWORD PTR [esi+0x38]
0x6fa968  8b5628                            mov    edx,DWORD PTR [esi+0x28]
0x6fa96b  8d0c40                            lea    ecx,[eax+eax*2]
0x6fa96e  8d0491                            lea    eax,[ecx+edx*4]
0x6fa971  034634                            add    eax,DWORD PTR [esi+0x34]
0x6fa974  83c404                            add    esp,0x4
0x6fa977  034630                            add    eax,DWORD PTR [esi+0x30]
0x6fa97a  03462c                            add    eax,DWORD PTR [esi+0x2c]
0x6fa97d  034624                            add    eax,DWORD PTR [esi+0x24]
0x6fa980  8d04854c000000                    lea    eax,[eax*4+0x4c]
0x6fa987  eb02                              jmp    0x6fa98b
0x6fa989  33c0                              xor    eax,eax
0x6fa98b  014508                            add    DWORD PTR [ebp+0x8],eax
0x6fa98e  837b2400                          cmp    DWORD PTR [ebx+0x24],0x0
0x6fa992  0f8518ffffff                      jne    0x6fa8b0
0x6fa998  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6fa99b  5f                                pop    edi
0x6fa99c  5e                                pop    esi
0x6fa99d  5b                                pop    ebx
0x6fa99e  5d                                pop    ebp
0x6fa99f  c3                                ret

; DATA gc_propagate_all_switch 0x6fa9a0..0x6fa9b4
; cea86f0000a96f0089a96f002ba96f0059a96f00

; DATA standard_library_table 0xc0c0d8..0xc0c120
; 7523bf00907770008c28c400b0b370008428c400f0cb70008028c400309270007c28c400d09d70007428c400c05270006c28c400d02870006428c400001e70000000000000000000

; DATA table_library_bindings 0xc0b968..0xc0b9b8
; 783cc400c0c07000703cc40020b97000643cc40020b770005c3cc400e0bb7000543cc400b0ba70004c3cc40080bd7000c438c400f0be7000443cc400e0bc70003c3cc40040ca70000000000000000000

; DATA coroutine_library_bindings 0xc0bc68..0xc0bca0
; e833c40080737000e033c400307270000c34c400c074700050eac00070707000d833c400507470008402c100807470000000000000000000

; DATA vm_opcode_table 0x6fd694..0x6fd72c
; f8c56f0015c66f0021c66f0045c66f005fc66f0082c66f00cbc66f0018c76f0061c76f00cac76f002cc86f0099c86f00f9c86f0061c96f00c9c96f0031ca6f0099ca6f0022cb6f00adcb6f00b0cc6f00e7cc6f0072cd6f00cfcd6f00e6cd6f0084ce6f000fcf6f0096cf6f00bfcf6f001ed06f0076d06f0029d66f00b6d06f000fd16f0029d26f00d2d26f00e9d36f00fed36f00c2d46f00

; q_start_and_skip 0x561760..0x561db0 Reused normal scene start, seen skip, prepass/formal loaders
0x561760  55                                push   ebp
0x561761  8bec                              mov    ebp,esp
0x561763  83e4f8                            and    esp,0xfffffff8
0x561766  6aff                              push   0xffffffff
0x561768  682cfd9300                        push   0x93fd2c
0x56176d  64a100000000                      mov    eax,fs:0x0
0x561773  50                                push   eax
0x561774  83ec50                            sub    esp,0x50
0x561777  a1201fd600                        mov    eax,ds:0xd61f20
0x56177c  33c4                              xor    eax,esp
0x56177e  89442448                          mov    DWORD PTR [esp+0x48],eax
0x561782  53                                push   ebx
0x561783  56                                push   esi
0x561784  57                                push   edi
0x561785  a1201fd600                        mov    eax,ds:0xd61f20
0x56178a  33c4                              xor    eax,esp
0x56178c  50                                push   eax
0x56178d  8d442460                          lea    eax,[esp+0x60]
0x561791  64a300000000                      mov    fs:0x0,eax
0x561797  833d18abfb0000                    cmp    DWORD PTR ds:0xfbab18,0x0
0x56179e  8bd9                              mov    ebx,ecx
0x5617a0  7420                              je     0x5617c2
0x5617a2  0f57c0                            xorps  xmm0,xmm0
0x5617a5  f30f110524abfb00                  movss  DWORD PTR ds:0xfbab24,xmm0
0x5617ad  e8aed8eaff                        call   0x40f060
0x5617b2  f30f10057059c500                  movss  xmm0,DWORD PTR ds:0xc55970
0x5617ba  f30f1180ac000000                  movss  DWORD PTR [eax+0xac],xmm0
0x5617c2  837b2800                          cmp    DWORD PTR [ebx+0x28],0x0
0x5617c6  c6838900000000                    mov    BYTE PTR [ebx+0x89],0x0
0x5617cd  741a                              je     0x5617e9
0x5617cf  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x5617d2  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x5617d5  50                                push   eax
0x5617d6  51                                push   ecx
0x5617d7  68ac06c100                        push   0xc106ac
0x5617dc  e87fc31800                        call   0x6edb60
0x5617e1  83c40c                            add    esp,0xc
0x5617e4  e99d050000                        jmp    0x561d86
0x5617e9  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
0x5617f0  be01000000                        mov    esi,0x1
0x5617f5  7529                              jne    0x561820
0x5617f7  09352888fb00                      or     DWORD PTR ds:0xfb8828,esi
0x5617fd  c744246800000000                  mov    DWORD PTR [esp+0x68],0x0
0x561805  e846e0feff                        call   0x54f850
0x56180a  6880d5bc00                        push   0xbcd580
0x56180f  e8060b3300                        call   0x89231a
0x561814  83c404                            add    esp,0x4
0x561817  83cfff                            or     edi,0xffffffff
0x56181a  897c2468                          mov    DWORD PTR [esp+0x68],edi
0x56181e  eb03                              jmp    0x561823
0x561820  83cfff                            or     edi,0xffffffff
0x561823  803df192fb0000                    cmp    BYTE PTR ds:0xfb92f1,0x0
0x56182a  0f84ac000000                      je     0x5618dc
0x561830  837d0800                          cmp    DWORD PTR [ebp+0x8],0x0
0x561834  0f85a2000000                      jne    0x5618dc
0x56183a  e86133eaff                        call   0x404ba0
0x56183f  83b84c5f000009                    cmp    DWORD PTR [eax+0x5f4c],0x9
0x561846  741c                              je     0x561864
0x561848  e85333eaff                        call   0x404ba0
0x56184d  83b84c5f000004                    cmp    DWORD PTR [eax+0x5f4c],0x4
0x561854  740e                              je     0x561864
0x561856  e84533eaff                        call   0x404ba0
0x56185b  83b84c5f000019                    cmp    DWORD PTR [eax+0x5f4c],0x19
0x561862  7578                              jne    0x5618dc
0x561864  8b7378                            mov    esi,DWORD PTR [ebx+0x78]
0x561867  8d550c                            lea    edx,[ebp+0xc]
0x56186a  52                                push   edx
0x56186b  8d4b74                            lea    ecx,[ebx+0x74]
0x56186e  8d442414                          lea    eax,[esp+0x14]
0x561872  e8494cedff                        call   0x4364c0
0x561877  3930                              cmp    DWORD PTR [eax],esi
0x561879  745c                              je     0x5618d7
0x56187b  6a0f                              push   0xf
0x56187d  e82e3d0200                        call   0x5855b0
0x561882  8bf0                              mov    esi,eax
0x561884  e8a73a0200                        call   0x585330
0x561889  50                                push   eax
0x56188a  8d4c2440                          lea    ecx,[esp+0x40]
0x56188e  e8bd09eaff                        call   0x402250
0x561893  8d44243c                          lea    eax,[esp+0x3c]
0x561897  50                                push   eax
0x561898  c744246c01000000                  mov    DWORD PTR [esp+0x6c],0x1
0x5618a0  e81be0eaff                        call   0x40f8c0
0x5618a5  8bf8                              mov    edi,eax
0x5618a7  e88452f7ff                        call   0x4d6b30
0x5618ac  8d4c243c                          lea    ecx,[esp+0x3c]
0x5618b0  c7442468ffffffff                  mov    DWORD PTR [esp+0x68],0xffffffff
0x5618b8  e8838bf9ff                        call   0x4fa440
0x5618bd  e8be2debff                        call   0x414680
0x5618c2  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x5618c5  51                                push   ecx
0x5618c6  6a00                              push   0x0
0x5618c8  e8d320f4ff                        call   0x4a39a0
0x5618cd  e8de070000                        call   0x5620b0
0x5618d2  e9af040000                        jmp    0x561d86
0x5618d7  be01000000                        mov    esi,0x1
0x5618dc  f605d4adfa0001                    test   BYTE PTR ds:0xfaadd4,0x1
0x5618e3  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x5618e6  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x5618e9  895338                            mov    DWORD PTR [ebx+0x38],edx
0x5618ec  89433c                            mov    DWORD PTR [ebx+0x3c],eax
0x5618ef  897328                            mov    DWORD PTR [ebx+0x28],esi
0x5618f2  7524                              jne    0x561918
0x5618f4  0935d4adfa00                      or     DWORD PTR ds:0xfaadd4,esi
0x5618fa  c744246802000000                  mov    DWORD PTR [esp+0x68],0x2
0x561902  e8795b0200                        call   0x587480
0x561907  68c0ccbc00                        push   0xbcccc0
0x56190c  e8090a3300                        call   0x89231a
0x561911  83c404                            add    esp,0x4
0x561914  897c2468                          mov    DWORD PTR [esp+0x68],edi
0x561918  f605d0adfa0001                    test   BYTE PTR ds:0xfaadd0,0x1
0x56191f  7524                              jne    0x561945
0x561921  0935d0adfa00                      or     DWORD PTR ds:0xfaadd0,esi
0x561927  c744246803000000                  mov    DWORD PTR [esp+0x68],0x3
0x56192f  e85cc01e00                        call   0x74d990
0x561934  6870ccbc00                        push   0xbccc70
0x561939  e8dc093300                        call   0x89231a
0x56193e  83c404                            add    esp,0x4
0x561941  897c2468                          mov    DWORD PTR [esp+0x68],edi
0x561945  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
0x56194c  8b0dbc5bf900                      mov    ecx,DWORD PTR ds:0xf95bbc
0x561952  8b15c05bf900                      mov    edx,DWORD PTR ds:0xf95bc0
0x561958  894c2414                          mov    DWORD PTR [esp+0x14],ecx
0x56195c  f30f10442414                      movss  xmm0,DWORD PTR [esp+0x14]
0x561962  89542418                          mov    DWORD PTR [esp+0x18],edx
0x561966  f30f118384000000                  movss  DWORD PTR [ebx+0x84],xmm0
0x56196e  7524                              jne    0x561994
0x561970  09359043f900                      or     DWORD PTR ds:0xf94390,esi
0x561976  c744246804000000                  mov    DWORD PTR [esp+0x68],0x4
0x56197e  e80dfcf7ff                        call   0x4e1590
0x561983  6880ccbc00                        push   0xbccc80
0x561988  e88d093300                        call   0x89231a
0x56198d  83c404                            add    esp,0x4
0x561990  897c2468                          mov    DWORD PTR [esp+0x68],edi
0x561994  f605d4adfa0001                    test   BYTE PTR ds:0xfaadd4,0x1
0x56199b  a0a442f900                        mov    al,ds:0xf942a4
0x5619a0  888388000000                      mov    BYTE PTR [ebx+0x88],al
0x5619a6  7524                              jne    0x5619cc
0x5619a8  0935d4adfa00                      or     DWORD PTR ds:0xfaadd4,esi
0x5619ae  c744246805000000                  mov    DWORD PTR [esp+0x68],0x5
0x5619b6  e8c55a0200                        call   0x587480
0x5619bb  68c0ccbc00                        push   0xbcccc0
0x5619c0  e855093300                        call   0x89231a
0x5619c5  83c404                            add    esp,0x4
0x5619c8  897c2468                          mov    DWORD PTR [esp+0x68],edi
0x5619cc  6858430f00                        push   0xf4358
0x5619d1  e8fa900200                        call   0x58aad0
0x5619d6  83c404                            add    esp,0x4
0x5619d9  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
0x5619e0  7524                              jne    0x561a06
0x5619e2  09359043f900                      or     DWORD PTR ds:0xf94390,esi
0x5619e8  c744246806000000                  mov    DWORD PTR [esp+0x68],0x6
0x5619f0  e89bfbf7ff                        call   0x4e1590
0x5619f5  6880ccbc00                        push   0xbccc80
0x5619fa  e81b093300                        call   0x89231a
0x5619ff  83c404                            add    esp,0x4
0x561a02  897c2468                          mov    DWORD PTR [esp+0x68],edi
0x561a06  6a00                              push   0x0
0x561a08  687523bf00                        push   0xbf2375
0x561a0d  8d4b44                            lea    ecx,[ebx+0x44]
0x561a10  c605a442f90001                    mov    BYTE PTR ds:0xf942a4,0x1
0x561a17  e85410eaff                        call   0x402a70
0x561a1c  8b730c                            mov    esi,DWORD PTR [ebx+0xc]
0x561a1f  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x561a22  80783100                          cmp    BYTE PTR [eax+0x31],0x0
0x561a26  8bd6                              mov    edx,esi
0x561a28  752c                              jne    0x561a56
0x561a2a  8d9b00000000                      lea    ebx,[ebx+0x0]
0x561a30  8b480c                            mov    ecx,DWORD PTR [eax+0xc]
0x561a33  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x561a36  3bf9                              cmp    edi,ecx
0x561a38  7f0a                              jg     0x561a44
0x561a3a  7c0d                              jl     0x561a49
0x561a3c  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x561a3f  394810                            cmp    DWORD PTR [eax+0x10],ecx
0x561a42  7d05                              jge    0x561a49
0x561a44  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x561a47  eb04                              jmp    0x561a4d
0x561a49  8bd0                              mov    edx,eax
0x561a4b  8b00                              mov    eax,DWORD PTR [eax]
0x561a4d  80783100                          cmp    BYTE PTR [eax+0x31],0x0
0x561a51  74dd                              je     0x561a30
0x561a53  83cfff                            or     edi,0xffffffff
0x561a56  8954241c                          mov    DWORD PTR [esp+0x1c],edx
0x561a5a  3bd6                              cmp    edx,esi
0x561a5c  741a                              je     0x561a78
0x561a5e  8b420c                            mov    eax,DWORD PTR [edx+0xc]
0x561a61  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x561a64  3bc1                              cmp    eax,ecx
0x561a66  7f10                              jg     0x561a78
0x561a68  7c08                              jl     0x561a72
0x561a6a  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x561a6d  3b4210                            cmp    eax,DWORD PTR [edx+0x10]
0x561a70  7c06                              jl     0x561a78
0x561a72  8d44241c                          lea    eax,[esp+0x1c]
0x561a76  eb08                              jmp    0x561a80
0x561a78  89742410                          mov    DWORD PTR [esp+0x10],esi
0x561a7c  8d442410                          lea    eax,[esp+0x10]
0x561a80  8b30                              mov    esi,DWORD PTR [eax]
0x561a82  3b730c                            cmp    esi,DWORD PTR [ebx+0xc]
0x561a85  0f84f4020000                      je     0x561d7f
0x561a8b  6a10                              push   0x10
0x561a8d  68d006c100                        push   0xc106d0
0x561a92  8d4c2428                          lea    ecx,[esp+0x28]
0x561a96  c744243c0f000000                  mov    DWORD PTR [esp+0x3c],0xf
0x561a9e  c744243800000000                  mov    DWORD PTR [esp+0x38],0x0
0x561aa6  c644242800                        mov    BYTE PTR [esp+0x28],0x0
0x561aab  e8c00feaff                        call   0x402a70
0x561ab0  8d4614                            lea    eax,[esi+0x14]
0x561ab3  57                                push   edi
0x561ab4  33f6                              xor    esi,esi
0x561ab6  56                                push   esi
0x561ab7  50                                push   eax
0x561ab8  8d4c242c                          lea    ecx,[esp+0x2c]
0x561abc  c744247407000000                  mov    DWORD PTR [esp+0x74],0x7
0x561ac4  e80704eaff                        call   0x401ed0
0x561ac9  6a04                              push   0x4
0x561acb  68e406c100                        push   0xc106e4
0x561ad0  8d4c2428                          lea    ecx,[esp+0x28]
0x561ad4  e8e704eaff                        call   0x401fc0
0x561ad9  837c243410                        cmp    DWORD PTR [esp+0x34],0x10
0x561ade  8b442420                          mov    eax,DWORD PTR [esp+0x20]
0x561ae2  7304                              jae    0x561ae8
0x561ae4  8d442420                          lea    eax,[esp+0x20]
0x561ae8  50                                push   eax
0x561ae9  51                                push   ecx
0x561aea  e8b1aaffff                        call   0x55c5a0
0x561aef  83c404                            add    esp,0x4
0x561af2  50                                push   eax
0x561af3  e8a8bbffff                        call   0x55d6a0
0x561af8  6a1c                              push   0x1c
0x561afa  894370                            mov    DWORD PTR [ebx+0x70],eax
0x561afd  e866f73200                        call   0x891268
0x561b02  83c404                            add    esp,0x4
0x561b05  3bc6                              cmp    eax,esi
0x561b07  7411                              je     0x561b1a
0x561b09  8930                              mov    DWORD PTR [eax],esi
0x561b0b  c6400801                          mov    BYTE PTR [eax+0x8],0x1
0x561b0f  89700c                            mov    DWORD PTR [eax+0xc],esi
0x561b12  897010                            mov    DWORD PTR [eax+0x10],esi
0x561b15  897014                            mov    DWORD PTR [eax+0x14],esi
0x561b18  eb02                              jmp    0x561b1c
0x561b1a  33c0                              xor    eax,eax
0x561b1c  50                                push   eax
0x561b1d  8d4c2418                          lea    ecx,[esp+0x18]
0x561b21  51                                push   ecx
0x561b22  8974241c                          mov    DWORD PTR [esp+0x1c],esi
0x561b26  89742420                          mov    DWORD PTR [esp+0x20],esi
0x561b2a  e8a1a5f1ff                        call   0x47c0d0
0x561b2f  c644246808                        mov    BYTE PTR [esp+0x68],0x8
0x561b34  8b742414                          mov    esi,DWORD PTR [esp+0x14]
0x561b38  c7460403000000                    mov    DWORD PTR [esi+0x4],0x3
0x561b3f  c6460801                          mov    BYTE PTR [esi+0x8],0x1
0x561b43  8b4b70                            mov    ecx,DWORD PTR [ebx+0x70]
0x561b46  8b4104                            mov    eax,DWORD PTR [ecx+0x4]
0x561b49  8b00                              mov    eax,DWORD PTR [eax]
0x561b4b  8944241c                          mov    DWORD PTR [esp+0x1c],eax
0x561b4f  3b4104                            cmp    eax,DWORD PTR [ecx+0x4]
0x561b52  7436                              je     0x561b8a
0x561b54  8d7e0c                            lea    edi,[esi+0xc]
0x561b57  eb07                              jmp    0x561b60
0x561b59  8da42400000000                    lea    esp,[esp+0x0]
0x561b60  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x561b63  0fb702                            movzx  eax,WORD PTR [edx]
0x561b66  89442410                          mov    DWORD PTR [esp+0x10],eax
0x561b6a  8d442410                          lea    eax,[esp+0x10]
0x561b6e  e80d6bf4ff                        call   0x4a8680
0x561b73  8d44241c                          lea    eax,[esp+0x1c]
0x561b77  e824cbf3ff                        call   0x49e6a0
0x561b7c  8b4370                            mov    eax,DWORD PTR [ebx+0x70]
0x561b7f  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x561b82  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
0x561b86  3bc1                              cmp    eax,ecx
0x561b88  75d6                              jne    0x561b60
0x561b8a  8b542418                          mov    edx,DWORD PTR [esp+0x18]
0x561b8e  83ec08                            sub    esp,0x8
0x561b91  8bfc                              mov    edi,esp
0x561b93  89642418                          mov    DWORD PTR [esp+0x18],esp
0x561b97  c70700000000                      mov    DWORD PTR [edi],0x0
0x561b9d  c7470400000000                    mov    DWORD PTR [edi+0x4],0x0
0x561ba4  85d2                              test   edx,edx
0x561ba6  7416                              je     0x561bbe
0x561ba8  e8a3a6f1ff                        call   0x47c250
0x561bad  84c0                              test   al,al
0x561baf  740d                              je     0x561bbe
0x561bb1  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x561bb5  51                                push   ecx
0x561bb6  56                                push   esi
0x561bb7  8bf7                              mov    esi,edi
0x561bb9  e802162400                        call   0x7a31c0
0x561bbe  c644247009                        mov    BYTE PTR [esp+0x70],0x9
0x561bc3  f605600ffc0001                    test   BYTE PTR ds:0xfc0f60,0x1
0x561bca  7523                              jne    0x561bef
0x561bcc  830d600ffc0001                    or     DWORD PTR ds:0xfc0f60,0x1
0x561bd3  c64424700a                        mov    BYTE PTR [esp+0x70],0xa
0x561bd8  e863b32300                        call   0x79cf40
0x561bdd  6880dbbc00                        push   0xbcdb80
0x561be2  e833073300                        call   0x89231a
0x561be7  83c404                            add    esp,0x4
0x561bea  c644247009                        mov    BYTE PTR [esp+0x70],0x9
0x561bef  b9900efc00                        mov    ecx,0xfc0e90
0x561bf4  c644247008                        mov    BYTE PTR [esp+0x70],0x8
0x561bf9  e8e2c02300                        call   0x79dce0
0x561bfe  8bf0                              mov    esi,eax
0x561c00  6aff                              push   0xffffffff
0x561c02  56                                push   esi
0x561c03  ff15fc20bd00                      call   DWORD PTR ds:0xbd20fc
0x561c09  56                                push   esi
0x561c0a  ff15c821bd00                      call   DWORD PTR ds:0xbd21c8
0x561c10  f6057017fe0001                    test   BYTE PTR ds:0xfe1770,0x1
0x561c17  7523                              jne    0x561c3c
0x561c19  830d7017fe0001                    or     DWORD PTR ds:0xfe1770,0x1
0x561c20  c64424680b                        mov    BYTE PTR [esp+0x68],0xb
0x561c25  e876612500                        call   0x7b7da0
0x561c2a  6890e7bc00                        push   0xbce790
0x561c2f  e8e6063300                        call   0x89231a
0x561c34  83c404                            add    esp,0x4
0x561c37  c644246808                        mov    BYTE PTR [esp+0x68],0x8
0x561c3c  8b3d3c17fe00                      mov    edi,DWORD PTR ds:0xfe173c
0x561c42  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x561c45  8b30                              mov    esi,DWORD PTR [eax]
0x561c47  3bf0                              cmp    esi,eax
0x561c49  741c                              je     0x561c67
0x561c4b  eb03                              jmp    0x561c50
0x561c4d  8d4900                            lea    ecx,[ecx+0x0]
0x561c50  8b4e24                            mov    ecx,DWORD PTR [esi+0x24]
0x561c53  83790400                          cmp    DWORD PTR [ecx+0x4],0x0
0x561c57  7507                              jne    0x561c60
0x561c59  8b11                              mov    edx,DWORD PTR [ecx]
0x561c5b  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x561c5e  ffd0                              call   eax
0x561c60  8b36                              mov    esi,DWORD PTR [esi]
0x561c62  3b7704                            cmp    esi,DWORD PTR [edi+0x4]
0x561c65  75e9                              jne    0x561c50
0x561c67  8b442420                          mov    eax,DWORD PTR [esp+0x20]
0x561c6b  bf10000000                        mov    edi,0x10
0x561c70  397c2434                          cmp    DWORD PTR [esp+0x34],edi
0x561c74  7304                              jae    0x561c7a
0x561c76  8d442420                          lea    eax,[esp+0x20]
0x561c7a  8b0b                              mov    ecx,DWORD PTR [ebx]
0x561c7c  50                                push   eax
0x561c7d  e8ce2d1900                        call   0x6f4a50
0x561c82  33db                              xor    ebx,ebx
0x561c84  f605ec79fb0001                    test   BYTE PTR ds:0xfb79ec,0x1
0x561c8b  be01000000                        mov    esi,0x1
0x561c90  7535                              jne    0x561cc7
0x561c92  0935ec79fb00                      or     DWORD PTR ds:0xfb79ec,esi
0x561c98  6870d2bc00                        push   0xbcd270
0x561c9d  c705f079fb0068f8c000              mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x561ca7  891df479fb00                      mov    DWORD PTR ds:0xfb79f4,ebx
0x561cad  891df879fb00                      mov    DWORD PTR ds:0xfb79f8,ebx
0x561cb3  891dfc79fb00                      mov    DWORD PTR ds:0xfb79fc,ebx
0x561cb9  8935047afb00                      mov    DWORD PTR ds:0xfb7a04,esi
0x561cbf  e856063300                        call   0x89231a
0x561cc4  83c404                            add    esp,0x4
0x561cc7  f605600ffc0001                    test   BYTE PTR ds:0xfc0f60,0x1
0x561cce  891d047afb00                      mov    DWORD PTR ds:0xfb7a04,ebx
0x561cd4  7522                              jne    0x561cf8
0x561cd6  0935600ffc00                      or     DWORD PTR ds:0xfc0f60,esi
0x561cdc  c64424680c                        mov    BYTE PTR [esp+0x68],0xc
0x561ce1  e85ab22300                        call   0x79cf40
0x561ce6  6880dbbc00                        push   0xbcdb80
0x561ceb  e82a063300                        call   0x89231a
0x561cf0  83c404                            add    esp,0x4
0x561cf3  c644246808                        mov    BYTE PTR [esp+0x68],0x8
0x561cf8  6a02                              push   0x2
0x561cfa  68900efc00                        push   0xfc0e90
0x561cff  e8bcbc2300                        call   0x79d9c0
0x561d04  f605d894fd0001                    test   BYTE PTR ds:0xfd94d8,0x1
0x561d0b  751d                              jne    0x561d2a
0x561d0d  0935d894fd00                      or     DWORD PTR ds:0xfd94d8,esi
0x561d13  c64424680d                        mov    BYTE PTR [esp+0x68],0xd
0x561d18  e813372500                        call   0x7b5430
0x561d1d  6860e6bc00                        push   0xbce660
0x561d22  e8f3053300                        call   0x89231a
0x561d27  83c404                            add    esp,0x4
0x561d2a  c644246807                        mov    BYTE PTR [esp+0x68],0x7
0x561d2f  8b742418                          mov    esi,DWORD PTR [esp+0x18]
0x561d33  c705b094fd0002000000              mov    DWORD PTR ds:0xfd94b0,0x2
0x561d3d  3bf3                              cmp    esi,ebx
0x561d3f  7429                              je     0x561d6a
0x561d41  8d4e04                            lea    ecx,[esi+0x4]
0x561d44  83caff                            or     edx,0xffffffff
0x561d47  f00fc111                          lock xadd DWORD PTR [ecx],edx
0x561d4b  751d                              jne    0x561d6a
0x561d4d  8b06                              mov    eax,DWORD PTR [esi]
0x561d4f  8b10                              mov    edx,DWORD PTR [eax]
0x561d51  8bce                              mov    ecx,esi
0x561d53  ffd2                              call   edx
0x561d55  8d4608                            lea    eax,[esi+0x8]
0x561d58  83c9ff                            or     ecx,0xffffffff
0x561d5b  f00fc108                          lock xadd DWORD PTR [eax],ecx
0x561d5f  7509                              jne    0x561d6a
0x561d61  8b16                              mov    edx,DWORD PTR [esi]
0x561d63  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x561d66  8bce                              mov    ecx,esi
0x561d68  ffd0                              call   eax
0x561d6a  397c2434                          cmp    DWORD PTR [esp+0x34],edi
0x561d6e  7216                              jb     0x561d86
0x561d70  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x561d74  51                                push   ecx
0x561d75  e892f43200                        call   0x89120c
0x561d7a  83c404                            add    esp,0x4
0x561d7d  eb07                              jmp    0x561d86
0x561d7f  8bcb                              mov    ecx,ebx
0x561d81  e82a000000                        call   0x561db0
0x561d86  8b4c2460                          mov    ecx,DWORD PTR [esp+0x60]
0x561d8a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x561d91  59                                pop    ecx
0x561d92  5f                                pop    edi
0x561d93  5e                                pop    esi
0x561d94  5b                                pop    ebx
0x561d95  8b4c2448                          mov    ecx,DWORD PTR [esp+0x48]
0x561d99  33cc                              xor    ecx,esp
0x561d9b  e861f23200                        call   0x891001
0x561da0  8be5                              mov    esp,ebp
0x561da2  5d                                pop    ebp
0x561da3  c20800                            ret    0x8
0x561da6  cc                                int3
0x561da7  cc                                int3
0x561da8  cc                                int3
0x561da9  cc                                int3
0x561daa  cc                                int3
0x561dab  cc                                int3
0x561dac  cc                                int3
0x561dad  cc                                int3
0x561dae  cc                                int3
0x561daf  cc                                int3

; q_tick 0x561520..0x561678 Reused active/pause gates and f_doCoTask consumer
0x561520  55                                push   ebp
0x561521  8bec                              mov    ebp,esp
0x561523  83e4f8                            and    esp,0xfffffff8
0x561526  6aff                              push   0xffffffff
0x561528  687cac9300                        push   0x93ac7c
0x56152d  64a100000000                      mov    eax,fs:0x0
0x561533  50                                push   eax
0x561534  51                                push   ecx
0x561535  56                                push   esi
0x561536  57                                push   edi
0x561537  a1201fd600                        mov    eax,ds:0xd61f20
0x56153c  33c4                              xor    eax,esp
0x56153e  50                                push   eax
0x56153f  8d442410                          lea    eax,[esp+0x10]
0x561543  64a300000000                      mov    fs:0x0,eax
0x561549  8bf9                              mov    edi,ecx
0x56154b  f6054027fe0001                    test   BYTE PTR ds:0xfe2740,0x1
0x561552  7529                              jne    0x56157d
0x561554  830d4027fe0001                    or     DWORD PTR ds:0xfe2740,0x1
0x56155b  c744241800000000                  mov    DWORD PTR [esp+0x18],0x0
0x561563  e818d1ffff                        call   0x55e680
0x561568  68a0f2bc00                        push   0xbcf2a0
0x56156d  e8a80d3300                        call   0x89231a
0x561572  83c404                            add    esp,0x4
0x561575  c7442418ffffffff                  mov    DWORD PTR [esp+0x18],0xffffffff
0x56157d  be4427fe00                        mov    esi,0xfe2744
0x561582  e809d2ffff                        call   0x55e790
0x561587  837f2800                          cmp    DWORD PTR [edi+0x28],0x0
0x56158b  7453                              je     0x5615e0
0x56158d  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x561594  be01000000                        mov    esi,0x1
0x561599  7524                              jne    0x5615bf
0x56159b  09352cb2fa00                      or     DWORD PTR ds:0xfab22c,esi
0x5615a1  89742418                          mov    DWORD PTR [esp+0x18],esi
0x5615a5  e8e6d6f7ff                        call   0x4dec90
0x5615aa  6830cebc00                        push   0xbcce30
0x5615af  e8660d3300                        call   0x89231a
0x5615b4  83c404                            add    esp,0x4
0x5615b7  c7442418ffffffff                  mov    DWORD PTR [esp+0x18],0xffffffff
0x5615bf  a1a4a7fb00                        mov    eax,ds:0xfba7a4
0x5615c4  897058                            mov    DWORD PTR [eax+0x58],esi
0x5615c7  837f2c00                          cmp    DWORD PTR [edi+0x2c],0x0
0x5615cb  7513                              jne    0x5615e0
0x5615cd  8b07                              mov    eax,DWORD PTR [edi]
0x5615cf  6a00                              push   0x0
0x5615d1  6a00                              push   0x0
0x5615d3  68a006c100                        push   0xc106a0
0x5615d8  e8f3371900                        call   0x6f4dd0
0x5615dd  83c40c                            add    esp,0xc
0x5615e0  8b7f1c                            mov    edi,DWORD PTR [edi+0x1c]
0x5615e3  8b37                              mov    esi,DWORD PTR [edi]
0x5615e5  3bf7                              cmp    esi,edi
0x5615e7  7455                              je     0x56163e
0x5615e9  8da42400000000                    lea    esp,[esp+0x0]
0x5615f0  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
0x5615f3  8b11                              mov    edx,DWORD PTR [ecx]
0x5615f5  8b4220                            mov    eax,DWORD PTR [edx+0x20]
0x5615f8  ffd0                              call   eax
0x5615fa  807e1500                          cmp    BYTE PTR [esi+0x15],0x0
0x5615fe  753a                              jne    0x56163a
0x561600  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x561603  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x561607  7516                              jne    0x56161f
0x561609  8bf0                              mov    esi,eax
0x56160b  8b06                              mov    eax,DWORD PTR [esi]
0x56160d  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x561611  7527                              jne    0x56163a
0x561613  8bf0                              mov    esi,eax
0x561615  8b06                              mov    eax,DWORD PTR [esi]
0x561617  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x56161b  74f6                              je     0x561613
0x56161d  eb1b                              jmp    0x56163a
0x56161f  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x561622  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x561626  7510                              jne    0x561638
0x561628  3b7008                            cmp    esi,DWORD PTR [eax+0x8]
0x56162b  750b                              jne    0x561638
0x56162d  8bf0                              mov    esi,eax
0x56162f  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x561632  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x561636  74f0                              je     0x561628
0x561638  8bf0                              mov    esi,eax
0x56163a  3bf7                              cmp    esi,edi
0x56163c  75b2                              jne    0x5615f0
0x56163e  f605dc36fe0001                    test   BYTE PTR ds:0xfe36dc,0x1
0x561645  7513                              jne    0x56165a
0x561647  830ddc36fe0001                    or     DWORD PTR ds:0xfe36dc,0x1
0x56164e  33c0                              xor    eax,eax
0x561650  a3d436fe00                        mov    ds:0xfe36d4,eax
0x561655  a3d836fe00                        mov    ds:0xfe36d8,eax
0x56165a  68d436fe00                        push   0xfe36d4
0x56165f  e82ceaffff                        call   0x560090
0x561664  33c0                              xor    eax,eax
0x561666  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x56166a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x561671  59                                pop    ecx
0x561672  5f                                pop    edi
0x561673  5e                                pop    esi
0x561674  8be5                              mov    esp,ebp
0x561676  5d                                pop    ebp
0x561677  c3                                ret

; q_end 0x561db0..0x5620aa Reused complete normal/review End and conditional 003F
0x561db0  55                                push   ebp
0x561db1  8bec                              mov    ebp,esp
0x561db3  83e4f8                            and    esp,0xfffffff8
0x561db6  6aff                              push   0xffffffff
0x561db8  6864fc9300                        push   0x93fc64
0x561dbd  64a100000000                      mov    eax,fs:0x0
0x561dc3  50                                push   eax
0x561dc4  83ec10                            sub    esp,0x10
0x561dc7  53                                push   ebx
0x561dc8  56                                push   esi
0x561dc9  57                                push   edi
0x561dca  a1201fd600                        mov    eax,ds:0xd61f20
0x561dcf  33c4                              xor    eax,esp
0x561dd1  50                                push   eax
0x561dd2  8d442420                          lea    eax,[esp+0x20]
0x561dd6  64a300000000                      mov    fs:0x0,eax
0x561ddc  8bf9                              mov    edi,ecx
0x561dde  33f6                              xor    esi,esi
0x561de0  80bf8900000000                    cmp    BYTE PTR [edi+0x89],0x0
0x561de7  0f8473010000                      je     0x561f60
0x561ded  397728                            cmp    DWORD PTR [edi+0x28],esi
0x561df0  0f84aa000000                      je     0x561ea0
0x561df6  897728                            mov    DWORD PTR [edi+0x28],esi
0x561df9  e85224edff                        call   0x434250
0x561dfe  bb01000000                        mov    ebx,0x1
0x561e03  895814                            mov    DWORD PTR [eax+0x14],ebx
0x561e06  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl
0x561e0c  7525                              jne    0x561e33
0x561e0e  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
0x561e14  89742428                          mov    DWORD PTR [esp+0x28],esi
0x561e18  e863251900                        call   0x6f4380
0x561e1d  68d0e6bc00                        push   0xbce6d0
0x561e22  e8f3043300                        call   0x89231a
0x561e27  83c404                            add    esp,0x4
0x561e2a  83ceff                            or     esi,0xffffffff
0x561e2d  89742428                          mov    DWORD PTR [esp+0x28],esi
0x561e31  eb03                              jmp    0x561e36
0x561e33  83ceff                            or     esi,0xffffffff
0x561e36  68ec06c100                        push   0xc106ec
0x561e3b  6a00                              push   0x0
0x561e3d  68c8f3fd00                        push   0xfdf3c8
0x561e42  e859b2f4ff                        call   0x4ad0a0
0x561e47  f605d4adfa0001                    test   BYTE PTR ds:0xfaadd4,0x1
0x561e4e  7520                              jne    0x561e70
0x561e50  091dd4adfa00                      or     DWORD PTR ds:0xfaadd4,ebx
0x561e56  895c2428                          mov    DWORD PTR [esp+0x28],ebx
0x561e5a  e821560200                        call   0x587480
0x561e5f  68c0ccbc00                        push   0xbcccc0
0x561e64  e8b1043300                        call   0x89231a
0x561e69  83c404                            add    esp,0x4
0x561e6c  89742428                          mov    DWORD PTR [esp+0x28],esi
0x561e70  d98784000000                      fld    DWORD PTR [edi+0x84]
0x561e76  83ec08                            sub    esp,0x8
0x561e79  d95c241c                          fstp   DWORD PTR [esp+0x1c]
0x561e7d  d944241c                          fld    DWORD PTR [esp+0x1c]
0x561e81  d9542404                          fst    DWORD PTR [esp+0x4]
0x561e85  d91c24                            fstp   DWORD PTR [esp]
0x561e88  e8937b0200                        call   0x589a20
0x561e8d  8a9f88000000                      mov    bl,BYTE PTR [edi+0x88]
0x561e93  e8082deaff                        call   0x404ba0
0x561e98  8898c4680000                      mov    BYTE PTR [eax+0x68c4],bl
0x561e9e  eb03                              jmp    0x561ea3
0x561ea0  83ceff                            or     esi,0xffffffff
0x561ea3  f605640ffc0001                    test   BYTE PTR ds:0xfc0f64,0x1
0x561eaa  7525                              jne    0x561ed1
0x561eac  830d640ffc0001                    or     DWORD PTR ds:0xfc0f64,0x1
0x561eb3  c744242802000000                  mov    DWORD PTR [esp+0x28],0x2
0x561ebb  e820bef1ff                        call   0x47dce0
0x561ec0  68f0dabc00                        push   0xbcdaf0
0x561ec5  e850043300                        call   0x89231a
0x561eca  83c404                            add    esp,0x4
0x561ecd  89742428                          mov    DWORD PTR [esp+0x28],esi
0x561ed1  8b473c                            mov    eax,DWORD PTR [edi+0x3c]
0x561ed4  8b4f38                            mov    ecx,DWORD PTR [edi+0x38]
0x561ed7  50                                push   eax
0x561ed8  51                                push   ecx
0x561ed9  68680ffc00                        push   0xfc0f68
0x561ede  e85dc7f1ff                        call   0x47e640
0x561ee3  33db                              xor    ebx,ebx
0x561ee5  89473c                            mov    DWORD PTR [edi+0x3c],eax
0x561ee8  3bc3                              cmp    eax,ebx
0x561eea  741f                              je     0x561f0b
0x561eec  8b5738                            mov    edx,DWORD PTR [edi+0x38]
0x561eef  50                                push   eax
0x561ef0  52                                push   edx
0x561ef1  8bf7                              mov    esi,edi
0x561ef3  e828380000                        call   0x565720
0x561ef8  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x561efc  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x561f03  59                                pop    ecx
0x561f04  5f                                pop    edi
0x561f05  5e                                pop    esi
0x561f06  5b                                pop    ebx
0x561f07  8be5                              mov    esp,ebp
0x561f09  5d                                pop    ebp
0x561f0a  c3                                ret
0x561f0b  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
0x561f12  7525                              jne    0x561f39
0x561f14  830dc00ffc0001                    or     DWORD PTR ds:0xfc0fc0,0x1
0x561f1b  c744242803000000                  mov    DWORD PTR [esp+0x28],0x3
0x561f23  e8286f1700                        call   0x6d8e50
0x561f28  68b0dbbc00                        push   0xbcdbb0
0x561f2d  e8e8033300                        call   0x89231a
0x561f32  83c404                            add    esp,0x4
0x561f35  89742428                          mov    DWORD PTR [esp+0x28],esi
0x561f39  8b4734                            mov    eax,DWORD PTR [edi+0x34]
0x561f3c  50                                push   eax
0x561f3d  b9c80ffc00                        mov    ecx,0xfc0fc8
0x561f42  e8e9741700                        call   0x6d9430
0x561f47  895f38                            mov    DWORD PTR [edi+0x38],ebx
0x561f4a  895f3c                            mov    DWORD PTR [edi+0x3c],ebx
0x561f4d  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x561f51  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x561f58  59                                pop    ecx
0x561f59  5f                                pop    edi
0x561f5a  5e                                pop    esi
0x561f5b  5b                                pop    ebx
0x561f5c  8be5                              mov    esp,ebp
0x561f5e  5d                                pop    ebp
0x561f5f  c3                                ret
0x561f60  397728                            cmp    DWORD PTR [edi+0x28],esi
0x561f63  0f8428010000                      je     0x562091
0x561f69  897728                            mov    DWORD PTR [edi+0x28],esi
0x561f6c  e8df22edff                        call   0x434250
0x561f71  bb01000000                        mov    ebx,0x1
0x561f76  895814                            mov    DWORD PTR [eax+0x14],ebx
0x561f79  397738                            cmp    DWORD PTR [edi+0x38],esi
0x561f7c  7439                              je     0x561fb7
0x561f7e  684403c100                        push   0xc10344
0x561f83  53                                push   ebx
0x561f84  e8a792f3ff                        call   0x49b230
0x561f89  50                                push   eax
0x561f8a  e811b1f4ff                        call   0x4ad0a0
0x561f8f  6aff                              push   0xffffffff
0x561f91  51                                push   ecx
0x561f92  e89992f3ff                        call   0x49b230
0x561f97  83c404                            add    esp,0x4
0x561f9a  e8b10bf4ff                        call   0x4a2b50
0x561f9f  3bc3                              cmp    eax,ebx
0x561fa1  754e                              jne    0x561ff1
0x561fa3  e8d826ebff                        call   0x414680
0x561fa8  8b4f3c                            mov    ecx,DWORD PTR [edi+0x3c]
0x561fab  8b5738                            mov    edx,DWORD PTR [edi+0x38]
0x561fae  51                                push   ecx
0x561faf  52                                push   edx
0x561fb0  e8eb19f4ff                        call   0x4a39a0
0x561fb5  eb3a                              jmp    0x561ff1
0x561fb7  8d5f3c                            lea    ebx,[edi+0x3c]
0x561fba  8d7774                            lea    esi,[edi+0x74]
0x561fbd  53                                push   ebx
0x561fbe  e87dbe1500                        call   0x6bde40
0x561fc3  50                                push   eax
0x561fc4  56                                push   esi
0x561fc5  8d74241c                          lea    esi,[esp+0x1c]
0x561fc9  e8c248edff                        call   0x436890
0x561fce  57                                push   edi
0x561fcf  e8cc030000                        call   0x5623a0
0x561fd4  e8a726ebff                        call   0x414680
0x561fd9  8b03                              mov    eax,DWORD PTR [ebx]
0x561fdb  8b4f38                            mov    ecx,DWORD PTR [edi+0x38]
0x561fde  50                                push   eax
0x561fdf  51                                push   ecx
0x561fe0  e8bb19f4ff                        call   0x4a39a0
0x561fe5  e8c6000000                        call   0x5620b0
0x561fea  bb01000000                        mov    ebx,0x1
0x561fef  33f6                              xor    esi,esi
0x561ff1  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
0x561ff8  7528                              jne    0x562022
0x561ffa  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
0x562000  c744242804000000                  mov    DWORD PTR [esp+0x28],0x4
0x562008  e873231900                        call   0x6f4380
0x56200d  68d0e6bc00                        push   0xbce6d0
0x562012  e803033300                        call   0x89231a
0x562017  83c404                            add    esp,0x4
0x56201a  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x562022  68ec06c100                        push   0xc106ec
0x562027  56                                push   esi
0x562028  68c8f3fd00                        push   0xfdf3c8
0x56202d  e86eb0f4ff                        call   0x4ad0a0
0x562032  f605d4adfa0001                    test   BYTE PTR ds:0xfaadd4,0x1
0x562039  7528                              jne    0x562063
0x56203b  091dd4adfa00                      or     DWORD PTR ds:0xfaadd4,ebx
0x562041  c744242805000000                  mov    DWORD PTR [esp+0x28],0x5
0x562049  e832540200                        call   0x587480
0x56204e  68c0ccbc00                        push   0xbcccc0
0x562053  e8c2023300                        call   0x89231a
0x562058  83c404                            add    esp,0x4
0x56205b  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x562063  d98784000000                      fld    DWORD PTR [edi+0x84]
0x562069  83ec08                            sub    esp,0x8
0x56206c  d95c241c                          fstp   DWORD PTR [esp+0x1c]
0x562070  d944241c                          fld    DWORD PTR [esp+0x1c]
0x562074  d9542404                          fst    DWORD PTR [esp+0x4]
0x562078  d91c24                            fstp   DWORD PTR [esp]
0x56207b  e8a0790200                        call   0x589a20
0x562080  8a9f88000000                      mov    bl,BYTE PTR [edi+0x88]
0x562086  e8152beaff                        call   0x404ba0
0x56208b  8898c4680000                      mov    BYTE PTR [eax+0x68c4],bl
0x562091  897738                            mov    DWORD PTR [edi+0x38],esi
0x562094  89773c                            mov    DWORD PTR [edi+0x3c],esi
0x562097  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x56209b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5620a2  59                                pop    ecx
0x5620a3  5f                                pop    edi
0x5620a4  5e                                pop    esi
0x5620a5  5b                                pop    ebx
0x5620a6  8be5                              mov    esp,ebp
0x5620a8  5d                                pop    ebp
0x5620a9  c3                                ret

; DATA name_checkconfirm 0xc10344..0xc10358
; 436865636b436f6e6669726d4d65737361676500

; DATA name_insert 0xc43c4c..0xc43c53
; 696e7365727400
