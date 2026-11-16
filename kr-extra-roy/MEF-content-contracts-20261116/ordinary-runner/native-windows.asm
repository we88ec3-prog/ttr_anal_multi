
### F01 ordinary base update: concrete CCheckPointMgr list and field+24
VA 0x4adb10 RAW 0xacf10 END 0x4adb85 SHA256 841d4681588bc3232052568928f36093c042060b473781ecaf09598b6e3b05c8
0x4adb10  56                                push   esi
0x4adb11  57                                push   edi
0x4adb12  8bf9                              mov    edi,ecx
0x4adb14  b901000000                        mov    ecx,0x1
0x4adb19  840dec79fb00                      test   BYTE PTR ds:0xfb79ec,cl
0x4adb1f  7534                              jne    0x4adb55
0x4adb21  090dec79fb00                      or     DWORD PTR ds:0xfb79ec,ecx
0x4adb27  33c0                              xor    eax,eax
0x4adb29  6870d2bc00                        push   0xbcd270
0x4adb2e  c705f079fb0068f8c000              mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x4adb38  a3f479fb00                        mov    ds:0xfb79f4,eax
0x4adb3d  a3f879fb00                        mov    ds:0xfb79f8,eax
0x4adb42  a3fc79fb00                        mov    ds:0xfb79fc,eax
0x4adb47  890d047afb00                      mov    DWORD PTR ds:0xfb7a04,ecx
0x4adb4d  e8c8473e00                        call   0x89231a
0x4adb52  83c404                            add    esp,0x4
0x4adb55  8b35f479fb00                      mov    esi,DWORD PTR ds:0xfb79f4
0x4adb5b  3b35f879fb00                      cmp    esi,DWORD PTR ds:0xfb79f8
0x4adb61  7414                              je     0x4adb77
0x4adb63  8b0e                              mov    ecx,DWORD PTR [esi]
0x4adb65  8b01                              mov    eax,DWORD PTR [ecx]
0x4adb67  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0x4adb6a  ffd2                              call   edx
0x4adb6c  83c604                            add    esi,0x4
0x4adb6f  3b35f879fb00                      cmp    esi,DWORD PTR ds:0xfb79f8
0x4adb75  75ec                              jne    0x4adb63
0x4adb77  8b07                              mov    eax,DWORD PTR [edi]
0x4adb79  8b5024                            mov    edx,DWORD PTR [eax+0x24]
0x4adb7c  8bcf                              mov    ecx,edi
0x4adb7e  ffd2                              call   edx
0x4adb80  5f                                pop    edi
0x4adb81  33c0                              xor    eax,eax
0x4adb83  5e                                pop    esi
0x4adb84  c3                                ret

### F02 Mission update wraps F01; native countdown and 4-byte49 sender
VA 0x423060 RAW 0x22460 END 0x4230eb SHA256 fbf6509bdb667ced7428d4fbc7a0699f8f215db8dbeae665dd416569df7c3a1f
0x423060  55                                push   ebp
0x423061  8bec                              mov    ebp,esp
0x423063  51                                push   ecx
0x423064  56                                push   esi
0x423065  8bf1                              mov    esi,ecx
0x423067  e8a4aa0800                        call   0x4adb10
0x42306c  83be54bd000000                    cmp    DWORD PTR [esi+0xbd54],0x0
0x423073  746f                              je     0x4230e4
0x423075  d98658bd0000                      fld    DWORD PTR [esi+0xbd58]
0x42307b  dc25705ac500                      fsub   QWORD PTR ds:0xc55a70
0x423081  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x423084  d945fc                            fld    DWORD PTR [ebp-0x4]
0x423087  d99658bd0000                      fst    DWORD PTR [esi+0xbd58]
0x42308d  d9ee                              fldz
0x42308f  dff1                              fcomip st,st(1)
0x423091  ddd8                              fstp   st(0)
0x423093  764f                              jbe    0x4230e4
0x423095  b801000000                        mov    eax,0x1
0x42309a  84051413fb00                      test   BYTE PTR ds:0xfb1314,al
0x4230a0  7513                              jne    0x4230b5
0x4230a2  09051413fb00                      or     DWORD PTR ds:0xfb1314,eax
0x4230a8  6810cfbc00                        push   0xbccf10
0x4230ad  e868f24600                        call   0x89231a
0x4230b2  83c404                            add    esp,0x4
0x4230b5  833d98a7fb0000                    cmp    DWORD PTR ds:0xfba798,0x0
0x4230bc  c745fc31000000                    mov    DWORD PTR [ebp-0x4],0x31
0x4230c3  7515                              jne    0x4230da
0x4230c5  8b0d54a8fb00                      mov    ecx,DWORD PTR ds:0xfba854
0x4230cb  8b11                              mov    edx,DWORD PTR [ecx]
0x4230cd  8b5210                            mov    edx,DWORD PTR [edx+0x10]
0x4230d0  6a04                              push   0x4
0x4230d2  8d45fc                            lea    eax,[ebp-0x4]
0x4230d5  50                                push   eax
0x4230d6  6a00                              push   0x0
0x4230d8  ffd2                              call   edx
0x4230da  c78654bd000000000000              mov    DWORD PTR [esi+0xbd54],0x0
0x4230e4  33c0                              xor    eax,eax
0x4230e6  5e                                pop    esi
0x4230e7  8be5                              mov    esp,ebp
0x4230e9  5d                                pop    ebp
0x4230ea  c3                                ret

### F03 both ordinary field+24 targets select fixed FB11E8 message owner
VA 0x4c4890 RAW 0xc3c90 END 0x4c4902 SHA256 70470c45b8a568a9f97fddd1b37befde3d6ffa1bf822599bbd2e293dd1e17288
0x4c4890  55                                push   ebp
0x4c4891  8bec                              mov    ebp,esp
0x4c4893  6aff                              push   0xffffffff
0x4c4895  68fe3e9300                        push   0x933efe
0x4c489a  64a100000000                      mov    eax,fs:0x0
0x4c48a0  50                                push   eax
0x4c48a1  56                                push   esi
0x4c48a2  a1201fd600                        mov    eax,ds:0xd61f20
0x4c48a7  33c5                              xor    eax,ebp
0x4c48a9  50                                push   eax
0x4c48aa  8d45f4                            lea    eax,[ebp-0xc]
0x4c48ad  64a300000000                      mov    fs:0x0,eax
0x4c48b3  b801000000                        mov    eax,0x1
0x4c48b8  8405e011fb00                      test   BYTE PTR ds:0xfb11e0,al
0x4c48be  7526                              jne    0x4c48e6
0x4c48c0  0905e011fb00                      or     DWORD PTR ds:0xfb11e0,eax
0x4c48c6  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4c48cd  e83e040100                        call   0x4d4d10
0x4c48d2  68f0cebc00                        push   0xbccef0
0x4c48d7  e83eda3c00                        call   0x89231a
0x4c48dc  83c404                            add    esp,0x4
0x4c48df  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c48e6  bee811fb00                        mov    esi,0xfb11e8
0x4c48eb  e830310100                        call   0x4d7a20
0x4c48f0  33c0                              xor    eax,eax
0x4c48f2  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4c48f5  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c48fc  59                                pop    ecx
0x4c48fd  5e                                pop    esi
0x4c48fe  8be5                              mov    esp,ebp
0x4c4900  5d                                pop    ebp
0x4c4901  c3                                ret

### F04 message-owner +10C/+110 string-pointer maintenance and refresh
VA 0x4d7a20 RAW 0xd6e20 END 0x4d7aa1 SHA256 ffacac6a0813bacac9137f6f86cf89c71aebba3bef7d65c27638a04539826024
0x4d7a20  55                                push   ebp
0x4d7a21  8bec                              mov    ebp,esp
0x4d7a23  83ec08                            sub    esp,0x8
0x4d7a26  57                                push   edi
0x4d7a27  8bbe0c010000                      mov    edi,DWORD PTR [esi+0x10c]
0x4d7a2d  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4d7a34  3bbe10010000                      cmp    edi,DWORD PTR [esi+0x110]
0x4d7a3a  7460                              je     0x4d7a9c
0x4d7a3c  53                                push   ebx
0x4d7a3d  8d5f04                            lea    ebx,[edi+0x4]
0x4d7a40  8b07                              mov    eax,DWORD PTR [edi]
0x4d7a42  8d5002                            lea    edx,[eax+0x2]
0x4d7a45  668b08                            mov    cx,WORD PTR [eax]
0x4d7a48  83c002                            add    eax,0x2
0x4d7a4b  6685c9                            test   cx,cx
0x4d7a4e  75f5                              jne    0x4d7a45
0x4d7a50  2bc2                              sub    eax,edx
0x4d7a52  d1f8                              sar    eax,1
0x4d7a54  742a                              je     0x4d7a80
0x4d7a56  8b8610010000                      mov    eax,DWORD PTR [esi+0x110]
0x4d7a5c  2bc3                              sub    eax,ebx
0x4d7a5e  c1f802                            sar    eax,0x2
0x4d7a61  03c0                              add    eax,eax
0x4d7a63  03c0                              add    eax,eax
0x4d7a65  50                                push   eax
0x4d7a66  53                                push   ebx
0x4d7a67  57                                push   edi
0x4d7a68  e883983b00                        call   0x8912f0
0x4d7a6d  83c40c                            add    esp,0xc
0x4d7a70  838610010000fc                    add    DWORD PTR [esi+0x110],0xfffffffc
0x4d7a77  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x4d7a7e  eb06                              jmp    0x4d7a86
0x4d7a80  83c704                            add    edi,0x4
0x4d7a83  83c304                            add    ebx,0x4
0x4d7a86  3bbe10010000                      cmp    edi,DWORD PTR [esi+0x110]
0x4d7a8c  75b2                              jne    0x4d7a40
0x4d7a8e  837dfc00                          cmp    DWORD PTR [ebp-0x4],0x0
0x4d7a92  5b                                pop    ebx
0x4d7a93  7407                              je     0x4d7a9c
0x4d7a95  8bce                              mov    ecx,esi
0x4d7a97  e8f4f1ffff                        call   0x4d6c90
0x4d7a9c  5f                                pop    edi
0x4d7a9d  8be5                              mov    esp,ebp
0x4d7a9f  5d                                pop    ebp
0x4d7aa0  c3                                ret

### F05 rechecked existing message rebuild and FXUI event F4366 producer
VA 0x4d6c90 RAW 0xd6090 END 0x4d6cd5 SHA256 780913b5ef9393e9b210ad15eb1227525d5996be30a48e9e0389645ac52616f9
0x4d6c90  56                                push   esi
0x4d6c91  e80ae3ffff                        call   0x4d4fa0
0x4d6c96  6a14                              push   0x14
0x4d6c98  e8cba53b00                        call   0x891268
0x4d6c9d  83c404                            add    esp,0x4
0x4d6ca0  85c0                              test   eax,eax
0x4d6ca2  7426                              je     0x4d6cca
0x4d6ca4  83c9ff                            or     ecx,0xffffffff
0x4d6ca7  8bf0                              mov    esi,eax
0x4d6ca9  c7000c7bc400                      mov    DWORD PTR [eax],0xc47b0c
0x4d6caf  894804                            mov    DWORD PTR [eax+0x4],ecx
0x4d6cb2  894808                            mov    DWORD PTR [eax+0x8],ecx
0x4d6cb5  c7400c00000000                    mov    DWORD PTR [eax+0xc],0x0
0x4d6cbc  c7401066430f00                    mov    DWORD PTR [eax+0x10],0xf4366
0x4d6cc3  e8d805f3ff                        call   0x4072a0
0x4d6cc8  5e                                pop    esi
0x4d6cc9  c3                                ret
0x4d6cca  33c0                              xor    eax,eax
0x4d6ccc  8bf0                              mov    esi,eax
0x4d6cce  e8cd05f3ff                        call   0x4072a0
0x4d6cd3  5e                                pop    esi
0x4d6cd4  c3                                ret

### F06 existing checkpoint payload producer:108 allocation,constructor,vector append
VA 0x4b2af0 RAW 0xb1ef0 END 0x4b2cc4 SHA256 b751c920ab03b268bb69252a6969a73ebb99278af1c03736fca6ff3fb3f9aa77
0x4b2af0  55                                push   ebp
0x4b2af1  8bec                              mov    ebp,esp
0x4b2af3  83e4f8                            and    esp,0xfffffff8
0x4b2af6  6aff                              push   0xffffffff
0x4b2af8  683b9f9200                        push   0x929f3b
0x4b2afd  64a100000000                      mov    eax,fs:0x0
0x4b2b03  50                                push   eax
0x4b2b04  83ec10                            sub    esp,0x10
0x4b2b07  53                                push   ebx
0x4b2b08  56                                push   esi
0x4b2b09  57                                push   edi
0x4b2b0a  a1201fd600                        mov    eax,ds:0xd61f20
0x4b2b0f  33c4                              xor    eax,esp
0x4b2b11  50                                push   eax
0x4b2b12  8d442420                          lea    eax,[esp+0x20]
0x4b2b16  64a300000000                      mov    fs:0x0,eax
0x4b2b1c  33db                              xor    ebx,ebx
0x4b2b1e  f605ec79fb0001                    test   BYTE PTR ds:0xfb79ec,0x1
0x4b2b25  7539                              jne    0x4b2b60
0x4b2b27  b801000000                        mov    eax,0x1
0x4b2b2c  0905ec79fb00                      or     DWORD PTR ds:0xfb79ec,eax
0x4b2b32  6870d2bc00                        push   0xbcd270
0x4b2b37  c705f079fb0068f8c000              mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x4b2b41  891df479fb00                      mov    DWORD PTR ds:0xfb79f4,ebx
0x4b2b47  891df879fb00                      mov    DWORD PTR ds:0xfb79f8,ebx
0x4b2b4d  891dfc79fb00                      mov    DWORD PTR ds:0xfb79fc,ebx
0x4b2b53  a3047afb00                        mov    ds:0xfb7a04,eax
0x4b2b58  e8bdf73d00                        call   0x89231a
0x4b2b5d  83c404                            add    esp,0x4
0x4b2b60  68f079fb00                        push   0xfb79f0
0x4b2b65  e8361e0900                        call   0x5449a0
0x4b2b6a  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x4b2b6d  83f802                            cmp    eax,0x2
0x4b2b70  7304                              jae    0x4b2b76
0x4b2b72  33d2                              xor    edx,edx
0x4b2b74  eb0d                              jmp    0x4b2b83
0x4b2b76  8d48fe                            lea    ecx,[eax-0x2]
0x4b2b79  b8398ee338                        mov    eax,0x38e38e39
0x4b2b7e  f7e1                              mul    ecx
0x4b2b80  c1ea02                            shr    edx,0x2
0x4b2b83  3bd3                              cmp    edx,ebx
0x4b2b85  0f8622010000                      jbe    0x4b2cad
0x4b2b8b  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x4b2b8e  83c712                            add    edi,0x12
0x4b2b91  89542418                          mov    DWORD PTR [esp+0x18],edx
0x4b2b95  6808010000                        push   0x108
0x4b2b9a  e8c9e63d00                        call   0x891268
0x4b2b9f  83c404                            add    esp,0x4
0x4b2ba2  89442414                          mov    DWORD PTR [esp+0x14],eax
0x4b2ba6  895c2428                          mov    DWORD PTR [esp+0x28],ebx
0x4b2baa  3bc3                              cmp    eax,ebx
0x4b2bac  7430                              je     0x4b2bde
0x4b2bae  0fb65701                          movzx  edx,BYTE PTR [edi+0x1]
0x4b2bb2  d947fc                            fld    DWORD PTR [edi-0x4]
0x4b2bb5  0fb60f                            movzx  ecx,BYTE PTR [edi]
0x4b2bb8  52                                push   edx
0x4b2bb9  0fb657f3                          movzx  edx,BYTE PTR [edi-0xd]
0x4b2bbd  51                                push   ecx
0x4b2bbe  52                                push   edx
0x4b2bbf  0fb757f0                          movzx  edx,WORD PTR [edi-0x10]
0x4b2bc3  51                                push   ecx
0x4b2bc4  8d4ff4                            lea    ecx,[edi-0xc]
0x4b2bc7  d91c24                            fstp   DWORD PTR [esp]
0x4b2bca  52                                push   edx
0x4b2bcb  660fbe57f2                        movsx  dx,BYTE PTR [edi-0xe]
0x4b2bd0  0fb7d2                            movzx  edx,dx
0x4b2bd3  52                                push   edx
0x4b2bd4  50                                push   eax
0x4b2bd5  e8260b0900                        call   0x543700
0x4b2bda  8bf0                              mov    esi,eax
0x4b2bdc  eb02                              jmp    0x4b2be0
0x4b2bde  33f6                              xor    esi,esi
0x4b2be0  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x4b2be8  f605ec79fb0001                    test   BYTE PTR ds:0xfb79ec,0x1
0x4b2bef  7539                              jne    0x4b2c2a
0x4b2bf1  b801000000                        mov    eax,0x1
0x4b2bf6  0905ec79fb00                      or     DWORD PTR ds:0xfb79ec,eax
0x4b2bfc  6870d2bc00                        push   0xbcd270
0x4b2c01  c705f079fb0068f8c000              mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x4b2c0b  891df479fb00                      mov    DWORD PTR ds:0xfb79f4,ebx
0x4b2c11  891df879fb00                      mov    DWORD PTR ds:0xfb79f8,ebx
0x4b2c17  891dfc79fb00                      mov    DWORD PTR ds:0xfb79fc,ebx
0x4b2c1d  a3047afb00                        mov    ds:0xfb7a04,eax
0x4b2c22  e8f3f63d00                        call   0x89231a
0x4b2c27  83c404                            add    esp,0x4
0x4b2c2a  a1f879fb00                        mov    eax,ds:0xfb79f8
0x4b2c2f  8d4c2414                          lea    ecx,[esp+0x14]
0x4b2c33  89742414                          mov    DWORD PTR [esp+0x14],esi
0x4b2c37  3bc8                              cmp    ecx,eax
0x4b2c39  733b                              jae    0x4b2c76
0x4b2c3b  8bd1                              mov    edx,ecx
0x4b2c3d  8b0df479fb00                      mov    ecx,DWORD PTR ds:0xfb79f4
0x4b2c43  3bca                              cmp    ecx,edx
0x4b2c45  772f                              ja     0x4b2c76
0x4b2c47  8bf2                              mov    esi,edx
0x4b2c49  2bf1                              sub    esi,ecx
0x4b2c4b  c1fe02                            sar    esi,0x2
0x4b2c4e  3b05fc79fb00                      cmp    eax,DWORD PTR ds:0xfb79fc
0x4b2c54  7515                              jne    0x4b2c6b
0x4b2c56  b8f479fb00                        mov    eax,0xfb79f4
0x4b2c5b  e850be0200                        call   0x4deab0
0x4b2c60  a1f879fb00                        mov    eax,ds:0xfb79f8
0x4b2c65  8b0df479fb00                      mov    ecx,DWORD PTR ds:0xfb79f4
0x4b2c6b  3bc3                              cmp    eax,ebx
0x4b2c6d  7429                              je     0x4b2c98
0x4b2c6f  8b0cb1                            mov    ecx,DWORD PTR [ecx+esi*4]
0x4b2c72  8908                              mov    DWORD PTR [eax],ecx
0x4b2c74  eb1d                              jmp    0x4b2c93
0x4b2c76  3b05fc79fb00                      cmp    eax,DWORD PTR ds:0xfb79fc
0x4b2c7c  750f                              jne    0x4b2c8d
0x4b2c7e  b8f479fb00                        mov    eax,0xfb79f4
0x4b2c83  e828be0200                        call   0x4deab0
0x4b2c88  a1f879fb00                        mov    eax,ds:0xfb79f8
0x4b2c8d  3bc3                              cmp    eax,ebx
0x4b2c8f  7407                              je     0x4b2c98
0x4b2c91  8930                              mov    DWORD PTR [eax],esi
0x4b2c93  a1f879fb00                        mov    eax,ds:0xfb79f8
0x4b2c98  83c004                            add    eax,0x4
0x4b2c9b  83c712                            add    edi,0x12
0x4b2c9e  ff4c2418                          dec    DWORD PTR [esp+0x18]
0x4b2ca2  a3f879fb00                        mov    ds:0xfb79f8,eax
0x4b2ca7  0f85e8feffff                      jne    0x4b2b95
0x4b2cad  33c0                              xor    eax,eax
0x4b2caf  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x4b2cb3  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4b2cba  59                                pop    ecx
0x4b2cbb  5f                                pop    edi
0x4b2cbc  5e                                pop    esi
0x4b2cbd  5b                                pop    ebx
0x4b2cbe  8be5                              mov    esp,ebp
0x4b2cc0  5d                                pop    ebp
0x4b2cc1  c20c00                            ret    0xc

### F07 CCheckPoint constructor assigns C0F7FC and point properties/effect
VA 0x543700 RAW 0x142b00 END 0x543b2a SHA256 affc19e395b1bf97a0f035cd6ea640ecc0d4b0c5cc5645860e3f42fc6ef8e592
0x543700  55                                push   ebp
0x543701  8bec                              mov    ebp,esp
0x543703  6aff                              push   0xffffffff
0x543705  6828989200                        push   0x929828
0x54370a  64a100000000                      mov    eax,fs:0x0
0x543710  50                                push   eax
0x543711  83ec28                            sub    esp,0x28
0x543714  53                                push   ebx
0x543715  56                                push   esi
0x543716  57                                push   edi
0x543717  a1201fd600                        mov    eax,ds:0xd61f20
0x54371c  33c5                              xor    eax,ebp
0x54371e  50                                push   eax
0x54371f  8d45f4                            lea    eax,[ebp-0xc]
0x543722  64a300000000                      mov    fs:0x0,eax
0x543728  8bf9                              mov    edi,ecx
0x54372a  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x54372d  8a4518                            mov    al,BYTE PTR [ebp+0x18]
0x543730  8bf3                              mov    esi,ebx
0x543732  895dcc                            mov    DWORD PTR [ebp-0x34],ebx
0x543735  8845f3                            mov    BYTE PTR [ebp-0xd],al
0x543738  e8f36ff8ff                        call   0x4ca730
0x54373d  33d2                              xor    edx,edx
0x54373f  8993f0000000                      mov    DWORD PTR [ebx+0xf0],edx
0x543745  668b4510                          mov    ax,WORD PTR [ebp+0x10]
0x543749  668b4d0c                          mov    cx,WORD PTR [ebp+0xc]
0x54374d  f30f104514                        movss  xmm0,DWORD PTR [ebp+0x14]
0x543752  8955fc                            mov    DWORD PTR [ebp-0x4],edx
0x543755  668983f6000000                    mov    WORD PTR [ebx+0xf6],ax
0x54375c  8a4520                            mov    al,BYTE PTR [ebp+0x20]
0x54375f  8883f8000000                      mov    BYTE PTR [ebx+0xf8],al
0x543765  8b451c                            mov    eax,DWORD PTR [ebp+0x1c]
0x543768  898300010000                      mov    DWORD PTR [ebx+0x100],eax
0x54376e  0fb645f3                          movzx  eax,BYTE PTR [ebp-0xd]
0x543772  c703fcf7c000                      mov    DWORD PTR [ebx],0xc0f7fc
0x543778  66898bf4000000                    mov    WORD PTR [ebx+0xf4],cx
0x54377f  f30f1183fc000000                  movss  DWORD PTR [ebx+0xfc],xmm0
0x543787  889304010000                      mov    BYTE PTR [ebx+0x104],dl
0x54378d  888305010000                      mov    BYTE PTR [ebx+0x105],al
0x543793  d983a0000000                      fld    DWORD PTR [ebx+0xa0]
0x543799  8db3a0000000                      lea    esi,[ebx+0xa0]
0x54379f  d907                              fld    DWORD PTR [edi]
0x5437a1  dfe9                              fucomip st,st(1)
0x5437a3  9f                                lahf
0x5437a4  ddd8                              fstp   st(0)
0x5437a6  f6c444                            test   ah,0x44
0x5437a9  7a10                              jp     0x5437bb
0x5437ab  d94604                            fld    DWORD PTR [esi+0x4]
0x5437ae  d94704                            fld    DWORD PTR [edi+0x4]
0x5437b1  dfe9                              fucomip st,st(1)
0x5437b3  ddd8                              fstp   st(0)
0x5437b5  9f                                lahf
0x5437b6  f6c444                            test   ah,0x44
0x5437b9  7b22                              jnp    0x5437dd
0x5437bb  8b0f                              mov    ecx,DWORD PTR [edi]
0x5437bd  890e                              mov    DWORD PTR [esi],ecx
0x5437bf  8b5704                            mov    edx,DWORD PTR [edi+0x4]
0x5437c2  8bcb                              mov    ecx,ebx
0x5437c4  895604                            mov    DWORD PTR [esi+0x4],edx
0x5437c7  c783ac00000001000000              mov    DWORD PTR [ebx+0xac],0x1
0x5437d1  ff1534f8c000                      call   DWORD PTR ds:0xc0f834
0x5437d7  668b4d0c                          mov    cx,WORD PTR [ebp+0xc]
0x5437db  33d2                              xor    edx,edx
0x5437dd  6683f902                          cmp    cx,0x2
0x5437e1  0f8588000000                      jne    0x54386f
0x5437e7  0fbf7d10                          movsx  edi,WORD PTR [ebp+0x10]
0x5437eb  a1b41dfe00                        mov    eax,ds:0xfe1db4
0x5437f0  e81b81fbff                        call   0x4fb910
0x5437f5  85c0                              test   eax,eax
0x5437f7  7410                              je     0x543809
0x5437f9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x5437fc  8d48ff                            lea    ecx,[eax-0x1]
0x5437ff  83f903                            cmp    ecx,0x3
0x543802  7705                              ja     0x543809
0x543804  8d78ff                            lea    edi,[eax-0x1]
0x543807  eb02                              jmp    0x54380b
0x543809  33ff                              xor    edi,edi
0x54380b  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
0x543812  7521                              jne    0x543835
0x543814  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
0x54381b  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x54381f  e8fccf0000                        call   0x550820
0x543824  68b0e6bc00                        push   0xbce6b0
0x543829  e8ecea3400                        call   0x89231a
0x54382e  83c404                            add    esp,0x4
0x543831  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0x543835  57                                push   edi
0x543836  6a00                              push   0x0
0x543838  b9c8f7c000                        mov    ecx,0xc0f7c8
0x54383d  ba80f6fd00                        mov    edx,0xfdf680
0x543842  e839e30000                        call   0x551b80
0x543847  d905f8c7c000                      fld    DWORD PTR ds:0xc0c7f8
0x54384d  6a00                              push   0x0
0x54384f  83ec08                            sub    esp,0x8
0x543852  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x543856  8bc8                              mov    ecx,eax
0x543858  d9ee                              fldz
0x54385a  d91c24                            fstp   DWORD PTR [esp]
0x54385d  56                                push   esi
0x54385e  6a00                              push   0x0
0x543860  6880f6fd00                        push   0xfdf680
0x543865  e866e50000                        call   0x551dd0
0x54386a  e99f020000                        jmp    0x543b0e
0x54386f  663bca                            cmp    cx,dx
0x543872  0f8545020000                      jne    0x543abd
0x543878  80bbf800000000                    cmp    BYTE PTR [ebx+0xf8],0x0
0x54387f  d94514                            fld    DWORD PTR [ebp+0x14]
0x543882  dd05405cc500                      fld    QWORD PTR ds:0xc55c40
0x543888  6a48                              push   0x48
0x54388a  d8c9                              fmul   st,st(1)
0x54388c  d99bb4000000                      fstp   DWORD PTR [ebx+0xb4]
0x543892  dc0da85bc500                      fmul   QWORD PTR ds:0xc55ba8
0x543898  d99bfc000000                      fstp   DWORD PTR [ebx+0xfc]
0x54389e  0f85c4000000                      jne    0x543968
0x5438a4  e8bfd93400                        call   0x891268
0x5438a9  8bf8                              mov    edi,eax
0x5438ab  83c404                            add    esp,0x4
0x5438ae  897dec                            mov    DWORD PTR [ebp-0x14],edi
0x5438b1  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x5438b5  85ff                              test   edi,edi
0x5438b7  0f8497000000                      je     0x543954
0x5438bd  807df301                          cmp    BYTE PTR [ebp-0xd],0x1
0x5438c1  7507                              jne    0x5438ca
0x5438c3  b804000000                        mov    eax,0x4
0x5438c8  eb08                              jmp    0x5438d2
0x5438ca  0fbf83f6000000                    movsx  eax,WORD PTR [ebx+0xf6]
0x5438d1  40                                inc    eax
0x5438d2  0fbf8bf6000000                    movsx  ecx,WORD PTR [ebx+0xf6]
0x5438d9  0f57c0                            xorps  xmm0,xmm0
0x5438dc  894f04                            mov    DWORD PTR [edi+0x4],ecx
0x5438df  894708                            mov    DWORD PTR [edi+0x8],eax
0x5438e2  c70708000000                      mov    DWORD PTR [edi],0x8
0x5438e8  c6470c01                          mov    BYTE PTR [edi+0xc],0x1
0x5438ec  8b16                              mov    edx,DWORD PTR [esi]
0x5438ee  895710                            mov    DWORD PTR [edi+0x10],edx
0x5438f1  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x5438f4  894714                            mov    DWORD PTR [edi+0x14],eax
0x5438f7  f30f1145e4                        movss  DWORD PTR [ebp-0x1c],xmm0
0x5438fc  8b4de4                            mov    ecx,DWORD PTR [ebp-0x1c]
0x5438ff  894f1c                            mov    DWORD PTR [edi+0x1c],ecx
0x543902  33c0                              xor    eax,eax
0x543904  f30f1145e8                        movss  DWORD PTR [ebp-0x18],xmm0
0x543909  8b55e8                            mov    edx,DWORD PTR [ebp-0x18]
0x54390c  8d4f24                            lea    ecx,[edi+0x24]
0x54390f  f30f114718                        movss  DWORD PTR [edi+0x18],xmm0
0x543914  895720                            mov    DWORD PTR [edi+0x20],edx
0x543917  50                                push   eax
0x543918  c7411407000000                    mov    DWORD PTR [ecx+0x14],0x7
0x54391f  c7411000000000                    mov    DWORD PTR [ecx+0x10],0x0
0x543926  68fcd1be00                        push   0xbed1fc
0x54392b  668901                            mov    WORD PTR [ecx],ax
0x54392e  e82de8ebff                        call   0x402160
0x543933  0f57c0                            xorps  xmm0,xmm0
0x543936  c7474000000000                    mov    DWORD PTR [edi+0x40],0x0
0x54393d  f30f114744                        movss  DWORD PTR [edi+0x44],xmm0
0x543942  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0x543946  e86566f4ff                        call   0x489fb0
0x54394b  8b08                              mov    ecx,DWORD PTR [eax]
0x54394d  57                                push   edi
0x54394e  51                                push   ecx
0x54394f  e9b4000000                        jmp    0x543a08
0x543954  33ff                              xor    edi,edi
0x543956  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0x54395a  e85166f4ff                        call   0x489fb0
0x54395f  8b08                              mov    ecx,DWORD PTR [eax]
0x543961  57                                push   edi
0x543962  51                                push   ecx
0x543963  e9a0000000                        jmp    0x543a08
0x543968  e8fbd83400                        call   0x891268
0x54396d  8bf8                              mov    edi,eax
0x54396f  83c404                            add    esp,0x4
0x543972  897dec                            mov    DWORD PTR [ebp-0x14],edi
0x543975  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0x543979  85ff                              test   edi,edi
0x54397b  747c                              je     0x5439f9
0x54397d  0fbf83f6000000                    movsx  eax,WORD PTR [ebx+0xf6]
0x543984  0f57c0                            xorps  xmm0,xmm0
0x543987  33d2                              xor    edx,edx
0x543989  807df301                          cmp    BYTE PTR [ebp-0xd],0x1
0x54398d  894704                            mov    DWORD PTR [edi+0x4],eax
0x543990  0f94c2                            sete   dl
0x543993  c7070b000000                      mov    DWORD PTR [edi],0xb
0x543999  c6470c01                          mov    BYTE PTR [edi+0xc],0x1
0x54399d  f30f1145e4                        movss  DWORD PTR [ebp-0x1c],xmm0
0x5439a2  f30f1145e8                        movss  DWORD PTR [ebp-0x18],xmm0
0x5439a7  42                                inc    edx
0x5439a8  895708                            mov    DWORD PTR [edi+0x8],edx
0x5439ab  8b06                              mov    eax,DWORD PTR [esi]
0x5439ad  8b55e4                            mov    edx,DWORD PTR [ebp-0x1c]
0x5439b0  894710                            mov    DWORD PTR [edi+0x10],eax
0x5439b3  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
0x5439b6  8b45e8                            mov    eax,DWORD PTR [ebp-0x18]
0x5439b9  89571c                            mov    DWORD PTR [edi+0x1c],edx
0x5439bc  894f14                            mov    DWORD PTR [edi+0x14],ecx
0x5439bf  33d2                              xor    edx,edx
0x5439c1  8d4f24                            lea    ecx,[edi+0x24]
0x5439c4  f30f114718                        movss  DWORD PTR [edi+0x18],xmm0
0x5439c9  894720                            mov    DWORD PTR [edi+0x20],eax
0x5439cc  52                                push   edx
0x5439cd  c7411407000000                    mov    DWORD PTR [ecx+0x14],0x7
0x5439d4  c7411000000000                    mov    DWORD PTR [ecx+0x10],0x0
0x5439db  68fcd1be00                        push   0xbed1fc
0x5439e0  668911                            mov    WORD PTR [ecx],dx
0x5439e3  e878e7ebff                        call   0x402160
0x5439e8  0f57c0                            xorps  xmm0,xmm0
0x5439eb  c7474000000000                    mov    DWORD PTR [edi+0x40],0x0
0x5439f2  f30f114744                        movss  DWORD PTR [edi+0x44],xmm0
0x5439f7  eb02                              jmp    0x5439fb
0x5439f9  33ff                              xor    edi,edi
0x5439fb  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0x5439ff  e8ac65f4ff                        call   0x489fb0
0x543a04  8b00                              mov    eax,DWORD PTR [eax]
0x543a06  57                                push   edi
0x543a07  50                                push   eax
0x543a08  e8b3bb0200                        call   0x56f5c0
0x543a0d  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
0x543a14  7521                              jne    0x543a37
0x543a16  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
0x543a1d  c645fc04                          mov    BYTE PTR [ebp-0x4],0x4
0x543a21  e85a03fbff                        call   0x4f3d80
0x543a26  68e0d1bc00                        push   0xbcd1e0
0x543a2b  e8eae83400                        call   0x89231a
0x543a30  83c404                            add    esp,0x4
0x543a33  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0x543a37  660fbe8bf8000000                  movsx  cx,BYTE PTR [ebx+0xf8]
0x543a3f  660fbe45f3                        movsx  ax,BYTE PTR [ebp-0xd]
0x543a44  0fb7d1                            movzx  edx,cx
0x543a47  0fb7c8                            movzx  ecx,ax
0x543a4a  c1e210                            shl    edx,0x10
0x543a4d  0bd1                              or     edx,ecx
0x543a4f  8955ec                            mov    DWORD PTR [ebp-0x14],edx
0x543a52  8d55ec                            lea    edx,[ebp-0x14]
0x543a55  b93075fb00                        mov    ecx,0xfb7530
0x543a5a  e86142fbff                        call   0x4f7cc0
0x543a5f  83781410                          cmp    DWORD PTR [eax+0x14],0x10
0x543a63  7202                              jb     0x543a67
0x543a65  8b00                              mov    eax,DWORD PTR [eax]
0x543a67  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
0x543a6e  c745d003000000                    mov    DWORD PTR [ebp-0x30],0x3
0x543a75  c745d4bcd6c000                    mov    DWORD PTR [ebp-0x2c],0xc0d6bc
0x543a7c  8945e0                            mov    DWORD PTR [ebp-0x20],eax
0x543a7f  7521                              jne    0x543aa2
0x543a81  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
0x543a88  c645fc05                          mov    BYTE PTR [ebp-0x4],0x5
0x543a8c  e88fcd0000                        call   0x550820
0x543a91  68b0e6bc00                        push   0xbce6b0
0x543a96  e87fe83400                        call   0x89231a
0x543a9b  83c404                            add    esp,0x4
0x543a9e  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0x543aa2  d983b4000000                      fld    DWORD PTR [ebx+0xb4]
0x543aa8  83ec08                            sub    esp,0x8
0x543aab  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x543aaf  b980f6fd00                        mov    ecx,0xfdf680
0x543ab4  d9ee                              fldz
0x543ab6  d91c24                            fstp   DWORD PTR [esp]
0x543ab9  6a00                              push   0x0
0x543abb  eb49                              jmp    0x543b06
0x543abd  6683f904                          cmp    cx,0x4
0x543ac1  7551                              jne    0x543b14
0x543ac3  d94514                            fld    DWORD PTR [ebp+0x14]
0x543ac6  83ec08                            sub    esp,0x8
0x543ac9  dc0db056c500                      fmul   QWORD PTR ds:0xc556b0
0x543acf  83c8ff                            or     eax,0xffffffff
0x543ad2  c745d002000000                    mov    DWORD PTR [ebp-0x30],0x2
0x543ad9  c745d4dcf7c000                    mov    DWORD PTR [ebp-0x2c],0xc0f7dc
0x543ae0  d99bfc000000                      fstp   DWORD PTR [ebx+0xfc]
0x543ae6  8945d8                            mov    DWORD PTR [ebp-0x28],eax
0x543ae9  d983b4000000                      fld    DWORD PTR [ebx+0xb4]
0x543aef  8945dc                            mov    DWORD PTR [ebp-0x24],eax
0x543af2  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x543af6  8955e0                            mov    DWORD PTR [ebp-0x20],edx
0x543af9  d9ee                              fldz
0x543afb  d91c24                            fstp   DWORD PTR [esp]
0x543afe  52                                push   edx
0x543aff  e83c76f5ff                        call   0x49b140
0x543b04  8bc8                              mov    ecx,eax
0x543b06  8d55d0                            lea    edx,[ebp-0x30]
0x543b09  e882e40000                        call   0x551f90
0x543b0e  8983f0000000                      mov    DWORD PTR [ebx+0xf0],eax
0x543b14  8bc3                              mov    eax,ebx
0x543b16  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x543b19  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x543b20  59                                pop    ecx
0x543b21  5f                                pop    edi
0x543b22  5e                                pop    esi
0x543b23  5b                                pop    ebx
0x543b24  8be5                              mov    esp,ebp
0x543b26  5d                                pop    ebp
0x543b27  c21c00                            ret    0x1c

### F08 CCheckPoint inherited update:base motion then effect+F0
VA 0x4cb000 RAW 0xca400 END 0x4cb01f SHA256 c0e9e29c9117ef212128da7e471d59fee08cbfe5c84d0e4b4f4b21ebab3eccd6
0x4cb000  56                                push   esi
0x4cb001  57                                push   edi
0x4cb002  8bf1                              mov    esi,ecx
0x4cb004  e887f8ffff                        call   0x4ca890
0x4cb009  8bb6f0000000                      mov    esi,DWORD PTR [esi+0xf0]
0x4cb00f  8bf8                              mov    edi,eax
0x4cb011  85f6                              test   esi,esi
0x4cb013  7407                              je     0x4cb01c
0x4cb015  e866570800                        call   0x550780
0x4cb01a  8bc7                              mov    eax,edi
0x4cb01c  5f                                pop    edi
0x4cb01d  5e                                pop    esi
0x4cb01e  c3                                ret

### F09 native position and movement update for concrete checkpoint vtable
VA 0x4ca890 RAW 0xc9c90 END 0x4caaf8 SHA256 5d1ac20eb0cca613004d11d69398c7517dba5ecfe36824740ef55b4e48c2bacf
0x4ca890  55                                push   ebp
0x4ca891  8bec                              mov    ebp,esp
0x4ca893  83e4f8                            and    esp,0xfffffff8
0x4ca896  83ec14                            sub    esp,0x14
0x4ca899  53                                push   ebx
0x4ca89a  56                                push   esi
0x4ca89b  8bf1                              mov    esi,ecx
0x4ca89d  83beac00000000                    cmp    DWORD PTR [esi+0xac],0x0
0x4ca8a4  57                                push   edi
0x4ca8a5  7407                              je     0x4ca8ae
0x4ca8a7  8b06                              mov    eax,DWORD PTR [esi]
0x4ca8a9  8b5038                            mov    edx,DWORD PTR [eax+0x38]
0x4ca8ac  ffd2                              call   edx
0x4ca8ae  a1cca7fb00                        mov    eax,ds:0xfba7cc
0x4ca8b3  85c0                              test   eax,eax
0x4ca8b5  751f                              jne    0x4ca8d6
0x4ca8b7  6880130000                        push   0x1380
0x4ca8bc  e8a7693c00                        call   0x891268
0x4ca8c1  83c404                            add    esp,0x4
0x4ca8c4  85c0                              test   eax,eax
0x4ca8c6  7407                              je     0x4ca8cf
0x4ca8c8  e8034b2100                        call   0x6df3d0
0x4ca8cd  eb02                              jmp    0x4ca8d1
0x4ca8cf  33c0                              xor    eax,eax
0x4ca8d1  a3cca7fb00                        mov    ds:0xfba7cc,eax
0x4ca8d6  83bed400000001                    cmp    DWORD PTR [esi+0xd4],0x1
0x4ca8dd  db8060130000                      fild   DWORD PTR [eax+0x1360]
0x4ca8e3  d9e8                              fld1
0x4ca8e5  def1                              fdivrp st(1),st
0x4ca8e7  d95c240c                          fstp   DWORD PTR [esp+0xc]
0x4ca8eb  0f856b010000                      jne    0x4caa5c
0x4ca8f1  d986c0000000                      fld    DWORD PTR [esi+0xc0]
0x4ca8f7  8b9ec8000000                      mov    ebx,DWORD PTR [esi+0xc8]
0x4ca8fd  d8a6a0000000                      fsub   DWORD PTR [esi+0xa0]
0x4ca903  8dbec0000000                      lea    edi,[esi+0xc0]
0x4ca909  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x4ca90d  d94704                            fld    DWORD PTR [edi+0x4]
0x4ca910  d8a6a4000000                      fsub   DWORD PTR [esi+0xa4]
0x4ca916  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x4ca91a  85db                              test   ebx,ebx
0x4ca91c  0f85bc000000                      jne    0x4ca9de
0x4ca922  8b06                              mov    eax,DWORD PTR [esi]
0x4ca924  8b5044                            mov    edx,DWORD PTR [eax+0x44]
0x4ca927  6a01                              push   0x1
0x4ca929  57                                push   edi
0x4ca92a  8bce                              mov    ecx,esi
0x4ca92c  ffd2                              call   edx
0x4ca92e  8b07                              mov    eax,DWORD PTR [edi]
0x4ca930  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x4ca933  8986e8000000                      mov    DWORD PTR [esi+0xe8],eax
0x4ca939  898eec000000                      mov    DWORD PTR [esi+0xec],ecx
0x4ca93f  d986e8000000                      fld    DWORD PTR [esi+0xe8]
0x4ca945  d8a6a0000000                      fsub   DWORD PTR [esi+0xa0]
0x4ca94b  d95c240c                          fstp   DWORD PTR [esp+0xc]
0x4ca94f  d944240c                          fld    DWORD PTR [esp+0xc]
0x4ca953  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x4ca957  d986ec000000                      fld    DWORD PTR [esi+0xec]
0x4ca95d  d8a6a4000000                      fsub   DWORD PTR [esi+0xa4]
0x4ca963  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x4ca967  d9442410                          fld    DWORD PTR [esp+0x10]
0x4ca96b  d95c241c                          fstp   DWORD PTR [esp+0x1c]
0x4ca96f  d9442418                          fld    DWORD PTR [esp+0x18]
0x4ca973  d944241c                          fld    DWORD PTR [esp+0x1c]
0x4ca977  dcc8                              fmul   st(0),st
0x4ca979  d9c1                              fld    st(1)
0x4ca97b  deca                              fmulp  st(2),st
0x4ca97d  dec1                              faddp  st(1),st
0x4ca97f  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x4ca983  d905645ac500                      fld    DWORD PTR ds:0xc55a64
0x4ca989  d9442418                          fld    DWORD PTR [esp+0x18]
0x4ca98d  dff1                              fcomip st,st(1)
0x4ca98f  ddd8                              fstp   st(0)
0x4ca991  762c                              jbe    0x4ca9bf
0x4ca993  f30f1044240c                      movss  xmm0,DWORD PTR [esp+0xc]
0x4ca999  f30f11442418                      movss  DWORD PTR [esp+0x18],xmm0
0x4ca99f  f30f10442410                      movss  xmm0,DWORD PTR [esp+0x10]
0x4ca9a5  8b542418                          mov    edx,DWORD PTR [esp+0x18]
0x4ca9a9  f30f1144241c                      movss  DWORD PTR [esp+0x1c],xmm0
0x4ca9af  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
0x4ca9b3  8996d8000000                      mov    DWORD PTR [esi+0xd8],edx
0x4ca9b9  8986dc000000                      mov    DWORD PTR [esi+0xdc],eax
0x4ca9bf  b9ff7f0000                        mov    ecx,0x7fff
0x4ca9c4  66218ee2000000                    and    WORD PTR [esi+0xe2],cx
0x4ca9cb  c786d400000000000000              mov    DWORD PTR [esi+0xd4],0x0
0x4ca9d5  33c0                              xor    eax,eax
0x4ca9d7  5f                                pop    edi
0x4ca9d8  5e                                pop    esi
0x4ca9d9  5b                                pop    ebx
0x4ca9da  8be5                              mov    esp,ebp
0x4ca9dc  5d                                pop    ebp
0x4ca9dd  c3                                ret
0x4ca9de  d9442414                          fld    DWORD PTR [esp+0x14]
0x4ca9e2  d9442410                          fld    DWORD PTR [esp+0x10]
0x4ca9e6  dcc8                              fmul   st(0),st
0x4ca9e8  d9c1                              fld    st(1)
0x4ca9ea  deca                              fmulp  st(2),st
0x4ca9ec  dec1                              faddp  st(1),st
0x4ca9ee  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x4ca9f2  d9442418                          fld    DWORD PTR [esp+0x18]
0x4ca9f6  e8754e4300                        call   0x8ff870
0x4ca9fb  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x4ca9ff  d9442418                          fld    DWORD PTR [esp+0x18]
0x4caa03  895c2418                          mov    DWORD PTR [esp+0x18],ebx
0x4caa07  db442418                          fild   DWORD PTR [esp+0x18]
0x4caa0b  85db                              test   ebx,ebx
0x4caa0d  7906                              jns    0x4caa15
0x4caa0f  d8058056c500                      fadd   DWORD PTR ds:0xc55680
0x4caa15  def9                              fdivp  st(1),st
0x4caa17  8d542410                          lea    edx,[esp+0x10]
0x4caa1b  52                                push   edx
0x4caa1c  8bc2                              mov    eax,edx
0x4caa1e  50                                push   eax
0x4caa1f  d95c2420                          fstp   DWORD PTR [esp+0x20]
0x4caa23  ff15f825bd00                      call   DWORD PTR ds:0xbd25f8
0x4caa29  d9442418                          fld    DWORD PTR [esp+0x18]
0x4caa2d  8b16                              mov    edx,DWORD PTR [esi]
0x4caa2f  d9c0                              fld    st(0)
0x4caa31  d84c2410                          fmul   DWORD PTR [esp+0x10]
0x4caa35  8b5254                            mov    edx,DWORD PTR [edx+0x54]
0x4caa38  8d442410                          lea    eax,[esp+0x10]
0x4caa3c  50                                push   eax
0x4caa3d  8bce                              mov    ecx,esi
0x4caa3f  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x4caa43  d84c2418                          fmul   DWORD PTR [esp+0x18]
0x4caa47  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x4caa4b  ffd2                              call   edx
0x4caa4d  ff8ec8000000                      dec    DWORD PTR [esi+0xc8]
0x4caa53  33c0                              xor    eax,eax
0x4caa55  5f                                pop    edi
0x4caa56  5e                                pop    esi
0x4caa57  5b                                pop    ebx
0x4caa58  8be5                              mov    esp,ebp
0x4caa5a  5d                                pop    ebp
0x4caa5b  c3                                ret
0x4caa5c  b800800000                        mov    eax,0x8000
0x4caa61  8bce                              mov    ecx,esi
0x4caa63  668586e2000000                    test   WORD PTR [esi+0xe2],ax
0x4caa6a  7468                              je     0x4caad4
0x4caa6c  8b16                              mov    edx,DWORD PTR [esi]
0x4caa6e  8b4260                            mov    eax,DWORD PTR [edx+0x60]
0x4caa71  ffd0                              call   eax
0x4caa73  d84c240c                          fmul   DWORD PTR [esp+0xc]
0x4caa77  f605187cfb0001                    test   BYTE PTR ds:0xfb7c18,0x1
0x4caa7e  8a9ee4000000                      mov    bl,BYTE PTR [esi+0xe4]
0x4caa84  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x4caa88  750c                              jne    0x4caa96
0x4caa8a  830d187cfb0001                    or     DWORD PTR ds:0xfb7c18,0x1
0x4caa91  e83a9ff7ff                        call   0x4449d0
0x4caa96  8b16                              mov    edx,DWORD PTR [esi]
0x4caa98  8b5254                            mov    edx,DWORD PTR [edx+0x54]
0x4caa9b  0fb6c3                            movzx  eax,bl
0x4caa9e  d904c52080fb00                    fld    DWORD PTR [eax*8+0xfb8020]
0x4caaa5  8d04c52080fb00                    lea    eax,[eax*8+0xfb8020]
0x4caaac  d9442418                          fld    DWORD PTR [esp+0x18]
0x4caab0  8bce                              mov    ecx,esi
0x4caab2  d9c0                              fld    st(0)
0x4caab4  deca                              fmulp  st(2),st
0x4caab6  d9c9                              fxch   st(1)
0x4caab8  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x4caabc  d84804                            fmul   DWORD PTR [eax+0x4]
0x4caabf  8d442410                          lea    eax,[esp+0x10]
0x4caac3  50                                push   eax
0x4caac4  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x4caac8  ffd2                              call   edx
0x4caaca  d905f8c7c000                      fld    DWORD PTR ds:0xc0c7f8
0x4caad0  8bce                              mov    ecx,esi
0x4caad2  eb06                              jmp    0x4caada
0x4caad4  d905645ac500                      fld    DWORD PTR ds:0xc55a64
0x4caada  6a00                              push   0x0
0x4caadc  83ec08                            sub    esp,0x8
0x4caadf  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x4caae3  d9442418                          fld    DWORD PTR [esp+0x18]
0x4caae7  d91c24                            fstp   DWORD PTR [esp]
0x4caaea  e871020000                        call   0x4cad60
0x4caaef  5f                                pop    edi
0x4caaf0  5e                                pop    esi
0x4caaf1  33c0                              xor    eax,eax
0x4caaf3  5b                                pop    ebx
0x4caaf4  8be5                              mov    esp,ebp
0x4caaf6  5d                                pop    ebp
0x4caaf7  c3                                ret

### F10 native height update when actor+AC dirty
VA 0x4cab30 RAW 0xc9f30 END 0x4cab73 SHA256 026233e611eecc2c2e2ccc448524d69ead44b4da3e91498d71bbe82f2bb8cef0
0x4cab30  56                                push   esi
0x4cab31  8bf1                              mov    esi,ecx
0x4cab33  83beac00000000                    cmp    DWORD PTR [esi+0xac],0x0
0x4cab3a  7435                              je     0x4cab71
0x4cab3c  8b0d38a8fb00                      mov    ecx,DWORD PTR ds:0xfba838
0x4cab42  d986a4000000                      fld    DWORD PTR [esi+0xa4]
0x4cab48  8b01                              mov    eax,DWORD PTR [ecx]
0x4cab4a  8b00                              mov    eax,DWORD PTR [eax]
0x4cab4c  6a00                              push   0x0
0x4cab4e  8d96a8000000                      lea    edx,[esi+0xa8]
0x4cab54  52                                push   edx
0x4cab55  83ec08                            sub    esp,0x8
0x4cab58  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x4cab5c  d986a0000000                      fld    DWORD PTR [esi+0xa0]
0x4cab62  d91c24                            fstp   DWORD PTR [esp]
0x4cab65  ffd0                              call   eax
0x4cab67  c786ac00000000000000              mov    DWORD PTR [esi+0xac],0x0
0x4cab71  5e                                pop    esi
0x4cab72  c3                                ret

### F11 native position writer and optional height update
VA 0x4cab80 RAW 0xc9f80 END 0x4cabd7 SHA256 91d77ee3fa0e58dbf90bb727f421211aedd94d094cb69d31f53a5eb619d1b44a
0x4cab80  55                                push   ebp
0x4cab81  8bec                              mov    ebp,esp
0x4cab83  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x4cab86  d981a0000000                      fld    DWORD PTR [ecx+0xa0]
0x4cab8c  d902                              fld    DWORD PTR [edx]
0x4cab8e  dfe9                              fucomip st,st(1)
0x4cab90  ddd8                              fstp   st(0)
0x4cab92  9f                                lahf
0x4cab93  f6c444                            test   ah,0x44
0x4cab96  7a13                              jp     0x4cabab
0x4cab98  d981a4000000                      fld    DWORD PTR [ecx+0xa4]
0x4cab9e  d94204                            fld    DWORD PTR [edx+0x4]
0x4caba1  dfe9                              fucomip st,st(1)
0x4caba3  ddd8                              fstp   st(0)
0x4caba5  9f                                lahf
0x4caba6  f6c444                            test   ah,0x44
0x4caba9  7b28                              jnp    0x4cabd3
0x4cabab  837d0c00                          cmp    DWORD PTR [ebp+0xc],0x0
0x4cabaf  8b02                              mov    eax,DWORD PTR [edx]
0x4cabb1  8981a0000000                      mov    DWORD PTR [ecx+0xa0],eax
0x4cabb7  8b5204                            mov    edx,DWORD PTR [edx+0x4]
0x4cabba  8991a4000000                      mov    DWORD PTR [ecx+0xa4],edx
0x4cabc0  7411                              je     0x4cabd3
0x4cabc2  8b01                              mov    eax,DWORD PTR [ecx]
0x4cabc4  8b5038                            mov    edx,DWORD PTR [eax+0x38]
0x4cabc7  c781ac00000001000000              mov    DWORD PTR [ecx+0xac],0x1
0x4cabd1  ffd2                              call   edx
0x4cabd3  5d                                pop    ebp
0x4cabd4  c20800                            ret    0x8

### F12 native movement/collision candidate to concrete +44 writer
VA 0x4cabe0 RAW 0xc9fe0 END 0x4cacbc SHA256 a0a883ae10ce8eec8cd8010ca8005306a0d3b8aa362f53f5f690c8fac1da8494
0x4cabe0  55                                push   ebp
0x4cabe1  8bec                              mov    ebp,esp
0x4cabe3  83e4f8                            and    esp,0xfffffff8
0x4cabe6  6aff                              push   0xffffffff
0x4cabe8  681e6a9300                        push   0x936a1e
0x4cabed  64a100000000                      mov    eax,fs:0x0
0x4cabf3  50                                push   eax
0x4cabf4  83ec18                            sub    esp,0x18
0x4cabf7  56                                push   esi
0x4cabf8  a1201fd600                        mov    eax,ds:0xd61f20
0x4cabfd  33c4                              xor    eax,esp
0x4cabff  50                                push   eax
0x4cac00  8d442420                          lea    eax,[esp+0x20]
0x4cac04  64a300000000                      mov    fs:0x0,eax
0x4cac0a  8bf1                              mov    esi,ecx
0x4cac0c  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x4cac13  7529                              jne    0x4cac3e
0x4cac15  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
0x4cac1c  c744242800000000                  mov    DWORD PTR [esp+0x28],0x0
0x4cac24  e867400100                        call   0x4dec90
0x4cac29  6830cebc00                        push   0xbcce30
0x4cac2e  e8e7763c00                        call   0x89231a
0x4cac33  83c404                            add    esp,0x4
0x4cac36  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x4cac3e  8b0dd0b1fa00                      mov    ecx,DWORD PTR ds:0xfab1d0
0x4cac44  85c9                              test   ecx,ecx
0x4cac46  7461                              je     0x4caca9
0x4cac48  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4cac4b  d900                              fld    DWORD PTR [eax]
0x4cac4d  d886a0000000                      fadd   DWORD PTR [esi+0xa0]
0x4cac53  d95c240c                          fstp   DWORD PTR [esp+0xc]
0x4cac57  d944240c                          fld    DWORD PTR [esp+0xc]
0x4cac5b  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x4cac5f  d986a4000000                      fld    DWORD PTR [esi+0xa4]
0x4cac65  d84004                            fadd   DWORD PTR [eax+0x4]
0x4cac68  8d442414                          lea    eax,[esp+0x14]
0x4cac6c  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x4cac70  d9442410                          fld    DWORD PTR [esp+0x10]
0x4cac74  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x4cac78  e873213600                        call   0x82cdf0
0x4cac7d  85c0                              test   eax,eax
0x4cac7f  7428                              je     0x4caca9
0x4cac81  f30f1044240c                      movss  xmm0,DWORD PTR [esp+0xc]
0x4cac87  8b06                              mov    eax,DWORD PTR [esi]
0x4cac89  8b5044                            mov    edx,DWORD PTR [eax+0x44]
0x4cac8c  6a01                              push   0x1
0x4cac8e  8d4c2418                          lea    ecx,[esp+0x18]
0x4cac92  f30f11442418                      movss  DWORD PTR [esp+0x18],xmm0
0x4cac98  f30f10442414                      movss  xmm0,DWORD PTR [esp+0x14]
0x4cac9e  51                                push   ecx
0x4cac9f  8bce                              mov    ecx,esi
0x4caca1  f30f11442420                      movss  DWORD PTR [esp+0x20],xmm0
0x4caca7  ffd2                              call   edx
0x4caca9  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x4cacad  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4cacb4  59                                pop    ecx
0x4cacb5  5e                                pop    esi
0x4cacb6  8be5                              mov    esp,ebp
0x4cacb8  5d                                pop    ebp
0x4cacb9  c20400                            ret    0x4

### F13 native speed arithmetic
VA 0x4cad40 RAW 0xca140 END 0x4cad60 SHA256 91861a684ee29d4129c7b466e57cdefc65e197b1c4020b9c22979377efe9031f
0x4cad40  55                                push   ebp
0x4cad41  8bec                              mov    ebp,esp
0x4cad43  51                                push   ecx
0x4cad44  db81d0000000                      fild   DWORD PTR [ecx+0xd0]
0x4cad4a  dc0df857c500                      fmul   QWORD PTR ds:0xc557f8
0x4cad50  d889cc000000                      fmul   DWORD PTR [ecx+0xcc]
0x4cad56  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x4cad59  d945fc                            fld    DWORD PTR [ebp-0x4]
0x4cad5c  8be5                              mov    esp,ebp
0x4cad5e  5d                                pop    ebp
0x4cad5f  c3                                ret

### F14 native displacement smoothing to concrete +54/+44
VA 0x4cad60 RAW 0xca160 END 0x4cae94 SHA256 0d3f09b44671f342f9c8da1c7922d0d979f72932218983ac0be25e5a67e55bd0
0x4cad60  55                                push   ebp
0x4cad61  8bec                              mov    ebp,esp
0x4cad63  83ec1c                            sub    esp,0x1c
0x4cad66  d981dc000000                      fld    DWORD PTR [ecx+0xdc]
0x4cad6c  0f57c0                            xorps  xmm0,xmm0
0x4cad6f  d981d8000000                      fld    DWORD PTR [ecx+0xd8]
0x4cad75  f30f1145ec                        movss  DWORD PTR [ebp-0x14],xmm0
0x4cad7a  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x4cad7d  f30f1145f0                        movss  DWORD PTR [ebp-0x10],xmm0
0x4cad82  d945f8                            fld    DWORD PTR [ebp-0x8]
0x4cad85  d9c0                              fld    st(0)
0x4cad87  dcc8                              fmul   st(0),st
0x4cad89  d9c2                              fld    st(2)
0x4cad8b  decb                              fmulp  st(3),st
0x4cad8d  dec2                              faddp  st(2),st
0x4cad8f  d9c9                              fxch   st(1)
0x4cad91  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x4cad94  d905c058c500                      fld    DWORD PTR ds:0xc558c0
0x4cad9a  d945f8                            fld    DWORD PTR [ebp-0x8]
0x4cad9d  dff1                              fcomip st,st(1)
0x4cad9f  ddd8                              fstp   st(0)
0x4cada1  767b                              jbe    0x4cae1e
0x4cada3  d9450c                            fld    DWORD PTR [ebp+0xc]
0x4cada6  d9c0                              fld    st(0)
0x4cada8  deca                              fmulp  st(2),st
0x4cadaa  d9c9                              fxch   st(1)
0x4cadac  d95df4                            fstp   DWORD PTR [ebp-0xc]
0x4cadaf  d889dc000000                      fmul   DWORD PTR [ecx+0xdc]
0x4cadb5  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x4cadb8  d945f4                            fld    DWORD PTR [ebp-0xc]
0x4cadbb  d94508                            fld    DWORD PTR [ebp+0x8]
0x4cadbe  d9c0                              fld    st(0)
0x4cadc0  deca                              fmulp  st(2),st
0x4cadc2  d9c9                              fxch   st(1)
0x4cadc4  d95de4                            fstp   DWORD PTR [ebp-0x1c]
0x4cadc7  d84df8                            fmul   DWORD PTR [ebp-0x8]
0x4cadca  d95de8                            fstp   DWORD PTR [ebp-0x18]
0x4cadcd  d945e4                            fld    DWORD PTR [ebp-0x1c]
0x4cadd0  d9ee                              fldz
0x4cadd2  dcc1                              fadd   st(1),st
0x4cadd4  d9c9                              fxch   st(1)
0x4cadd6  d95dec                            fstp   DWORD PTR [ebp-0x14]
0x4cadd9  d845e8                            fadd   DWORD PTR [ebp-0x18]
0x4caddc  d95df0                            fstp   DWORD PTR [ebp-0x10]
0x4caddf  d981d8000000                      fld    DWORD PTR [ecx+0xd8]
0x4cade5  d865ec                            fsub   DWORD PTR [ebp-0x14]
0x4cade8  d999d8000000                      fstp   DWORD PTR [ecx+0xd8]
0x4cadee  d981dc000000                      fld    DWORD PTR [ecx+0xdc]
0x4cadf4  d865f0                            fsub   DWORD PTR [ebp-0x10]
0x4cadf7  d999dc000000                      fstp   DWORD PTR [ecx+0xdc]
0x4cadfd  d981dc000000                      fld    DWORD PTR [ecx+0xdc]
0x4cae03  d981d8000000                      fld    DWORD PTR [ecx+0xd8]
0x4cae09  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x4cae0c  d945f8                            fld    DWORD PTR [ebp-0x8]
0x4cae0f  d9c0                              fld    st(0)
0x4cae11  d9c2                              fld    st(2)
0x4cae13  decb                              fmulp  st(3),st
0x4cae15  dcc8                              fmul   st(0),st
0x4cae17  dec2                              faddp  st(2),st
0x4cae19  d9c9                              fxch   st(1)
0x4cae1b  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x4cae1e  f30f100d605ac500                  movss  xmm1,DWORD PTR ds:0xc55a60
0x4cae26  0f2f4df8                          comiss xmm1,DWORD PTR [ebp-0x8]
0x4cae2a  7624                              jbe    0x4cae50
0x4cae2c  d845ec                            fadd   DWORD PTR [ebp-0x14]
0x4cae2f  d95dec                            fstp   DWORD PTR [ebp-0x14]
0x4cae32  d981dc000000                      fld    DWORD PTR [ecx+0xdc]
0x4cae38  f30f1181dc000000                  movss  DWORD PTR [ecx+0xdc],xmm0
0x4cae40  d845f0                            fadd   DWORD PTR [ebp-0x10]
0x4cae43  f30f1181d8000000                  movss  DWORD PTR [ecx+0xd8],xmm0
0x4cae4b  d95df0                            fstp   DWORD PTR [ebp-0x10]
0x4cae4e  eb02                              jmp    0x4cae52
0x4cae50  ddd8                              fstp   st(0)
0x4cae52  837d1000                          cmp    DWORD PTR [ebp+0x10],0x0
0x4cae56  742b                              je     0x4cae83
0x4cae58  d981a0000000                      fld    DWORD PTR [ecx+0xa0]
0x4cae5e  8b01                              mov    eax,DWORD PTR [ecx]
0x4cae60  d845ec                            fadd   DWORD PTR [ebp-0x14]
0x4cae63  8b4044                            mov    eax,DWORD PTR [eax+0x44]
0x4cae66  6a01                              push   0x1
0x4cae68  8d55e4                            lea    edx,[ebp-0x1c]
0x4cae6b  d95de4                            fstp   DWORD PTR [ebp-0x1c]
0x4cae6e  52                                push   edx
0x4cae6f  d981a4000000                      fld    DWORD PTR [ecx+0xa4]
0x4cae75  d845f0                            fadd   DWORD PTR [ebp-0x10]
0x4cae78  d95de8                            fstp   DWORD PTR [ebp-0x18]
0x4cae7b  ffd0                              call   eax
0x4cae7d  8be5                              mov    esp,ebp
0x4cae7f  5d                                pop    ebp
0x4cae80  c20c00                            ret    0xc
0x4cae83  8b11                              mov    edx,DWORD PTR [ecx]
0x4cae85  8b5254                            mov    edx,DWORD PTR [edx+0x54]
0x4cae88  8d45ec                            lea    eax,[ebp-0x14]
0x4cae8b  50                                push   eax
0x4cae8c  ffd2                              call   edx
0x4cae8e  8be5                              mov    esp,ebp
0x4cae90  5d                                pop    ebp
0x4cae91  c20c00                            ret    0xc

### F15 effect instance position/lifetime maintenance; nested effect callback retained
VA 0x550780 RAW 0x14fb80 END 0x55081c SHA256 eab1740fac1e206bae0645cee0706a8cadaf98f3ae61238505ccdd3a0b2daf7f
0x550780  55                                push   ebp
0x550781  8bec                              mov    ebp,esp
0x550783  83ec08                            sub    esp,0x8
0x550786  837e2400                          cmp    DWORD PTR [esi+0x24],0x0
0x55078a  57                                push   edi
0x55078b  7466                              je     0x5507f3
0x55078d  8b466c                            mov    eax,DWORD PTR [esi+0x6c]
0x550790  85c0                              test   eax,eax
0x550792  745f                              je     0x5507f3
0x550794  837e7000                          cmp    DWORD PTR [esi+0x70],0x0
0x550798  7459                              je     0x5507f3
0x55079a  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x55079d  e8bee8ebff                        call   0x40f060
0x5507a2  8bf8                              mov    edi,eax
0x5507a4  8d45fc                            lea    eax,[ebp-0x4]
0x5507a7  50                                push   eax
0x5507a8  8d4f08                            lea    ecx,[edi+0x8]
0x5507ab  8d45f8                            lea    eax,[ebp-0x8]
0x5507ae  e84de72d00                        call   0x82ef00
0x5507b3  8b45f8                            mov    eax,DWORD PTR [ebp-0x8]
0x5507b6  3b470c                            cmp    eax,DWORD PTR [edi+0xc]
0x5507b9  7455                              je     0x550810
0x5507bb  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x5507be  85c9                              test   ecx,ecx
0x5507c0  744e                              je     0x550810
0x5507c2  8b11                              mov    edx,DWORD PTR [ecx]
0x5507c4  8b424c                            mov    eax,DWORD PTR [edx+0x4c]
0x5507c7  ffd0                              call   eax
0x5507c9  8b4e24                            mov    ecx,DWORD PTR [esi+0x24]
0x5507cc  8b10                              mov    edx,DWORD PTR [eax]
0x5507ce  895128                            mov    DWORD PTR [ecx+0x28],edx
0x5507d1  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x5507d4  89512c                            mov    DWORD PTR [ecx+0x2c],edx
0x5507d7  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x5507da  895130                            mov    DWORD PTR [ecx+0x30],edx
0x5507dd  c7417001000000                    mov    DWORD PTR [ecx+0x70],0x1
0x5507e4  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x5507e7  85c9                              test   ecx,ecx
0x5507e9  7408                              je     0x5507f3
0x5507eb  8b11                              mov    edx,DWORD PTR [ecx]
0x5507ed  50                                push   eax
0x5507ee  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x5507f1  ffd0                              call   eax
0x5507f3  8b4624                            mov    eax,DWORD PTR [esi+0x24]
0x5507f6  85c0                              test   eax,eax
0x5507f8  741d                              je     0x550817
0x5507fa  83786c00                          cmp    DWORD PTR [eax+0x6c],0x0
0x5507fe  7417                              je     0x550817
0x550800  8b4678                            mov    eax,DWORD PTR [esi+0x78]
0x550803  85c0                              test   eax,eax
0x550805  7409                              je     0x550810
0x550807  48                                dec    eax
0x550808  894678                            mov    DWORD PTR [esi+0x78],eax
0x55080b  5f                                pop    edi
0x55080c  8be5                              mov    esp,ebp
0x55080e  5d                                pop    ebp
0x55080f  c3                                ret
0x550810  c7467401000000                    mov    DWORD PTR [esi+0x74],0x1
0x550817  5f                                pop    edi
0x550818  8be5                              mov    esp,ebp
0x55081a  5d                                pop    ebp
0x55081b  c3                                ret

### U01 ordinary shared page update and its two selected UI dynamic boundaries
VA 0x59b1f0 RAW 0x19a5f0 END 0x59b418 SHA256 b0f3f4c951752dbda76ed1e38225a17c97d146b70448427cadc11e1c17101da9
0x59b1f0  55                                push   ebp
0x59b1f1  8bec                              mov    ebp,esp
0x59b1f3  6aff                              push   0xffffffff
0x59b1f5  68fc8f9400                        push   0x948ffc
0x59b1fa  64a100000000                      mov    eax,fs:0x0
0x59b200  50                                push   eax
0x59b201  51                                push   ecx
0x59b202  53                                push   ebx
0x59b203  56                                push   esi
0x59b204  57                                push   edi
0x59b205  a1201fd600                        mov    eax,ds:0xd61f20
0x59b20a  33c5                              xor    eax,ebp
0x59b20c  50                                push   eax
0x59b20d  8d45f4                            lea    eax,[ebp-0xc]
0x59b210  64a300000000                      mov    fs:0x0,eax
0x59b216  8bd9                              mov    ebx,ecx
0x59b218  e823930000                        call   0x5a4540
0x59b21d  83bb6401000000                    cmp    DWORD PTR [ebx+0x164],0x0
0x59b224  7410                              je     0x59b236
0x59b226  8b8b64010000                      mov    ecx,DWORD PTR [ebx+0x164]
0x59b22c  8b01                              mov    eax,DWORD PTR [ecx]
0x59b22e  8b9098010000                      mov    edx,DWORD PTR [eax+0x198]
0x59b234  ffd2                              call   edx
0x59b236  8bb370010000                      mov    esi,DWORD PTR [ebx+0x170]
0x59b23c  85f6                              test   esi,esi
0x59b23e  740f                              je     0x59b24f
0x59b240  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x59b243  c1e808                            shr    eax,0x8
0x59b246  a801                              test   al,0x1
0x59b248  7405                              je     0x59b24f
0x59b24a  e861430c00                        call   0x65f5b0
0x59b24f  8bb38c010000                      mov    esi,DWORD PTR [ebx+0x18c]
0x59b255  85f6                              test   esi,esi
0x59b257  7426                              je     0x59b27f
0x59b259  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x59b25c  c1e908                            shr    ecx,0x8
0x59b25f  f6c101                            test   cl,0x1
0x59b262  741b                              je     0x59b27f
0x59b264  8bbe80000000                      mov    edi,DWORD PTR [esi+0x80]
0x59b26a  85ff                              test   edi,edi
0x59b26c  7411                              je     0x59b27f
0x59b26e  e84df80f00                        call   0x69aac0
0x59b273  8b9684000000                      mov    edx,DWORD PTR [esi+0x84]
0x59b279  52                                push   edx
0x59b27a  e871dfe7ff                        call   0x4191f0
0x59b27f  8b8368010000                      mov    eax,DWORD PTR [ebx+0x168]
0x59b285  83ceff                            or     esi,0xffffffff
0x59b288  85c0                              test   eax,eax
0x59b28a  7428                              je     0x59b2b4
0x59b28c  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x59b28f  c1e908                            shr    ecx,0x8
0x59b292  f6c101                            test   cl,0x1
0x59b295  741d                              je     0x59b2b4
0x59b297  8b8818010000                      mov    ecx,DWORD PTR [eax+0x118]
0x59b29d  3bce                              cmp    ecx,esi
0x59b29f  7413                              je     0x59b2b4
0x59b2a1  8b9004010000                      mov    edx,DWORD PTR [eax+0x104]
0x59b2a7  8b0c8a                            mov    ecx,DWORD PTR [edx+ecx*4]
0x59b2aa  8b01                              mov    eax,DWORD PTR [ecx]
0x59b2ac  8b90a8010000                      mov    edx,DWORD PTR [eax+0x1a8]
0x59b2b2  ffd2                              call   edx
0x59b2b4  8bbba4010000                      mov    edi,DWORD PTR [ebx+0x1a4]
0x59b2ba  85ff                              test   edi,edi
0x59b2bc  740f                              je     0x59b2cd
0x59b2be  8b4728                            mov    eax,DWORD PTR [edi+0x28]
0x59b2c1  c1e808                            shr    eax,0x8
0x59b2c4  a801                              test   al,0x1
0x59b2c6  7405                              je     0x59b2cd
0x59b2c8  e8d3f90900                        call   0x63aca0
0x59b2cd  8bbbd8010000                      mov    edi,DWORD PTR [ebx+0x1d8]
0x59b2d3  8b4f28                            mov    ecx,DWORD PTR [edi+0x28]
0x59b2d6  c1e908                            shr    ecx,0x8
0x59b2d9  f6c101                            test   cl,0x1
0x59b2dc  7405                              je     0x59b2e3
0x59b2de  e88dfb0600                        call   0x60ae70
0x59b2e3  8b8300020000                      mov    eax,DWORD PTR [ebx+0x200]
0x59b2e9  85c0                              test   eax,eax
0x59b2eb  7411                              je     0x59b2fe
0x59b2ed  8b5028                            mov    edx,DWORD PTR [eax+0x28]
0x59b2f0  c1ea08                            shr    edx,0x8
0x59b2f3  f6c201                            test   dl,0x1
0x59b2f6  7406                              je     0x59b2fe
0x59b2f8  50                                push   eax
0x59b2f9  e8420c1300                        call   0x6cbf40
0x59b2fe  8b83f0010000                      mov    eax,DWORD PTR [ebx+0x1f0]
0x59b304  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x59b307  c1e908                            shr    ecx,0x8
0x59b30a  f6c101                            test   cl,0x1
0x59b30d  7405                              je     0x59b314
0x59b30f  e86cf20700                        call   0x61a580
0x59b314  8b8b90010000                      mov    ecx,DWORD PTR [ebx+0x190]
0x59b31a  8b5128                            mov    edx,DWORD PTR [ecx+0x28]
0x59b31d  c1ea08                            shr    edx,0x8
0x59b320  f6c201                            test   dl,0x1
0x59b323  7405                              je     0x59b32a
0x59b325  e846171000                        call   0x69ca70
0x59b32a  f60534affa0001                    test   BYTE PTR ds:0xfaaf34,0x1
0x59b331  7523                              jne    0x59b356
0x59b333  830d34affa0001                    or     DWORD PTR ds:0xfaaf34,0x1
0x59b33a  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x59b341  e87ac0e6ff                        call   0x4073c0
0x59b346  68d0ccbc00                        push   0xbcccd0
0x59b34b  e8ca6f2f00                        call   0x89231a
0x59b350  83c404                            add    esp,0x4
0x59b353  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x59b356  803d45affa0000                    cmp    BYTE PTR ds:0xfaaf45,0x0
0x59b35d  0f848d000000                      je     0x59b3f0
0x59b363  8bbb08020000                      mov    edi,DWORD PTR [ebx+0x208]
0x59b369  e892b3e6ff                        call   0x406700
0x59b36e  84c0                              test   al,al
0x59b370  747e                              je     0x59b3f0
0x59b372  8b8308020000                      mov    eax,DWORD PTR [ebx+0x208]
0x59b378  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x59b37b  c1e908                            shr    ecx,0x8
0x59b37e  f6c101                            test   cl,0x1
0x59b381  750e                              jne    0x59b391
0x59b383  e81898e6ff                        call   0x404ba0
0x59b388  83b84c5f000007                    cmp    DWORD PTR [eax+0x5f4c],0x7
0x59b38f  741c                              je     0x59b3ad
0x59b391  e80a98e6ff                        call   0x404ba0
0x59b396  83b84c5f000017                    cmp    DWORD PTR [eax+0x5f4c],0x17
0x59b39d  740e                              je     0x59b3ad
0x59b39f  e8fc97e6ff                        call   0x404ba0
0x59b3a4  83b84c5f000018                    cmp    DWORD PTR [eax+0x5f4c],0x18
0x59b3ab  7510                              jne    0x59b3bd
0x59b3ad  8b8b08020000                      mov    ecx,DWORD PTR [ebx+0x208]
0x59b3b3  8b11                              mov    edx,DWORD PTR [ecx]
0x59b3b5  8b82d0000000                      mov    eax,DWORD PTR [edx+0xd0]
0x59b3bb  ffd0                              call   eax
0x59b3bd  f60534affa0001                    test   BYTE PTR ds:0xfaaf34,0x1
0x59b3c4  7523                              jne    0x59b3e9
0x59b3c6  b801000000                        mov    eax,0x1
0x59b3cb  090534affa00                      or     DWORD PTR ds:0xfaaf34,eax
0x59b3d1  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x59b3d4  e8e7bfe6ff                        call   0x4073c0
0x59b3d9  68d0ccbc00                        push   0xbcccd0
0x59b3de  e8376f2f00                        call   0x89231a
0x59b3e3  83c404                            add    esp,0x4
0x59b3e6  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x59b3e9  c60545affa0000                    mov    BYTE PTR ds:0xfaaf45,0x0
0x59b3f0  8bbb18020000                      mov    edi,DWORD PTR [ebx+0x218]
0x59b3f6  8b4f28                            mov    ecx,DWORD PTR [edi+0x28]
0x59b3f9  c1e908                            shr    ecx,0x8
0x59b3fc  f6c101                            test   cl,0x1
0x59b3ff  7405                              je     0x59b406
0x59b401  e86aa4f0ff                        call   0x4a5870
0x59b406  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x59b409  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x59b410  59                                pop    ecx
0x59b411  5f                                pop    edi
0x59b412  5e                                pop    esi
0x59b413  5b                                pop    ebx
0x59b414  8be5                              mov    esp,ebp
0x59b416  5d                                pop    ebp
0x59b417  c3                                ret

### U02 Mission page update including +22C visible->v+16C
VA 0x5ad6a0 RAW 0x1acaa0 END 0x5ad87c SHA256 5e3401e87ba62c468b434d469b79dd085e3e7893adc88ef7accba71d470f11d3
0x5ad6a0  55                                push   ebp
0x5ad6a1  8bec                              mov    ebp,esp
0x5ad6a3  83e4f8                            and    esp,0xfffffff8
0x5ad6a6  6aff                              push   0xffffffff
0x5ad6a8  685e609300                        push   0x93605e
0x5ad6ad  64a100000000                      mov    eax,fs:0x0
0x5ad6b3  50                                push   eax
0x5ad6b4  83ec08                            sub    esp,0x8
0x5ad6b7  53                                push   ebx
0x5ad6b8  56                                push   esi
0x5ad6b9  57                                push   edi
0x5ad6ba  a1201fd600                        mov    eax,ds:0xd61f20
0x5ad6bf  33c4                              xor    eax,esp
0x5ad6c1  50                                push   eax
0x5ad6c2  8d442418                          lea    eax,[esp+0x18]
0x5ad6c6  64a300000000                      mov    fs:0x0,eax
0x5ad6cc  8bd9                              mov    ebx,ecx
0x5ad6ce  e81ddbfeff                        call   0x59b1f0
0x5ad6d3  8b831c020000                      mov    eax,DWORD PTR [ebx+0x21c]
0x5ad6d9  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5ad6dc  c1e908                            shr    ecx,0x8
0x5ad6df  f6c101                            test   cl,0x1
0x5ad6e2  7406                              je     0x5ad6ea
0x5ad6e4  50                                push   eax
0x5ad6e5  e8460d0a00                        call   0x64e430
0x5ad6ea  8bb320020000                      mov    esi,DWORD PTR [ebx+0x220]
0x5ad6f0  8b5628                            mov    edx,DWORD PTR [esi+0x28]
0x5ad6f3  c1ea08                            shr    edx,0x8
0x5ad6f6  f6c201                            test   dl,0x1
0x5ad6f9  7405                              je     0x5ad700
0x5ad6fb  e860fc0a00                        call   0x65d360
0x5ad700  8b8324020000                      mov    eax,DWORD PTR [ebx+0x224]
0x5ad706  85c0                              test   eax,eax
0x5ad708  7406                              je     0x5ad710
0x5ad70a  50                                push   eax
0x5ad70b  e8b0c40a00                        call   0x659bc0
0x5ad710  8bbb28020000                      mov    edi,DWORD PTR [ebx+0x228]
0x5ad716  85ff                              test   edi,edi
0x5ad718  740b                              je     0x5ad725
0x5ad71a  57                                push   edi
0x5ad71b  e8a0510a00                        call   0x6528c0
0x5ad720  e89b530a00                        call   0x652ac0
0x5ad725  8b8b2c020000                      mov    ecx,DWORD PTR [ebx+0x22c]
0x5ad72b  8b4128                            mov    eax,DWORD PTR [ecx+0x28]
0x5ad72e  c1e808                            shr    eax,0x8
0x5ad731  a801                              test   al,0x1
0x5ad733  740a                              je     0x5ad73f
0x5ad735  8b11                              mov    edx,DWORD PTR [ecx]
0x5ad737  8b826c010000                      mov    eax,DWORD PTR [edx+0x16c]
0x5ad73d  ffd0                              call   eax
0x5ad73f  8b8338020000                      mov    eax,DWORD PTR [ebx+0x238]
0x5ad745  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5ad748  c1e908                            shr    ecx,0x8
0x5ad74b  f6c101                            test   cl,0x1
0x5ad74e  7406                              je     0x5ad756
0x5ad750  50                                push   eax
0x5ad751  e88a490a00                        call   0x6520e0
0x5ad756  8b8334020000                      mov    eax,DWORD PTR [ebx+0x234]
0x5ad75c  8b5028                            mov    edx,DWORD PTR [eax+0x28]
0x5ad75f  c1ea08                            shr    edx,0x8
0x5ad762  f6c201                            test   dl,0x1
0x5ad765  7406                              je     0x5ad76d
0x5ad767  50                                push   eax
0x5ad768  e813410a00                        call   0x651880
0x5ad76d  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x5ad774  7529                              jne    0x5ad79f
0x5ad776  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
0x5ad77d  c744242000000000                  mov    DWORD PTR [esp+0x20],0x0
0x5ad785  e80615f3ff                        call   0x4dec90
0x5ad78a  6830cebc00                        push   0xbcce30
0x5ad78f  e8864b2e00                        call   0x89231a
0x5ad794  83c404                            add    esp,0x4
0x5ad797  c7442420ffffffff                  mov    DWORD PTR [esp+0x20],0xffffffff
0x5ad79f  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x5ad7a5  8b01                              mov    eax,DWORD PTR [ecx]
0x5ad7a7  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0x5ad7aa  ffd2                              call   edx
0x5ad7ac  85c0                              test   eax,eax
0x5ad7ae  747a                              je     0x5ad82a
0x5ad7b0  8b8b38020000                      mov    ecx,DWORD PTR [ebx+0x238]
0x5ad7b6  8b5128                            mov    edx,DWORD PTR [ecx+0x28]
0x5ad7b9  c1ea08                            shr    edx,0x8
0x5ad7bc  f6c201                            test   dl,0x1
0x5ad7bf  7569                              jne    0x5ad82a
0x5ad7c1  8b8058010000                      mov    eax,DWORD PTR [eax+0x158]
0x5ad7c7  85c0                              test   eax,eax
0x5ad7c9  7406                              je     0x5ad7d1
0x5ad7cb  83783400                          cmp    DWORD PTR [eax+0x34],0x0
0x5ad7cf  7435                              je     0x5ad806
0x5ad7d1  8b8b34020000                      mov    ecx,DWORD PTR [ebx+0x234]
0x5ad7d7  8b4128                            mov    eax,DWORD PTR [ecx+0x28]
0x5ad7da  c1e808                            shr    eax,0x8
0x5ad7dd  a801                              test   al,0x1
0x5ad7df  7563                              jne    0x5ad844
0x5ad7e1  80bb3002000000                    cmp    BYTE PTR [ebx+0x230],0x0
0x5ad7e8  755a                              jne    0x5ad844
0x5ad7ea  80bb4402000000                    cmp    BYTE PTR [ebx+0x244],0x0
0x5ad7f1  750a                              jne    0x5ad7fd
0x5ad7f3  8b11                              mov    edx,DWORD PTR [ecx]
0x5ad7f5  8b82d0000000                      mov    eax,DWORD PTR [edx+0xd0]
0x5ad7fb  ffd0                              call   eax
0x5ad7fd  c6833002000001                    mov    BYTE PTR [ebx+0x230],0x1
0x5ad804  eb3e                              jmp    0x5ad844
0x5ad806  8b8b34020000                      mov    ecx,DWORD PTR [ebx+0x234]
0x5ad80c  8b5128                            mov    edx,DWORD PTR [ecx+0x28]
0x5ad80f  c1ea08                            shr    edx,0x8
0x5ad812  f6c201                            test   dl,0x1
0x5ad815  740a                              je     0x5ad821
0x5ad817  8b01                              mov    eax,DWORD PTR [ecx]
0x5ad819  8b90d4000000                      mov    edx,DWORD PTR [eax+0xd4]
0x5ad81f  ffd2                              call   edx
0x5ad821  c6833002000000                    mov    BYTE PTR [ebx+0x230],0x0
0x5ad828  eb1a                              jmp    0x5ad844
0x5ad82a  8b8b34020000                      mov    ecx,DWORD PTR [ebx+0x234]
0x5ad830  8b4128                            mov    eax,DWORD PTR [ecx+0x28]
0x5ad833  c1e808                            shr    eax,0x8
0x5ad836  a801                              test   al,0x1
0x5ad838  740a                              je     0x5ad844
0x5ad83a  8b11                              mov    edx,DWORD PTR [ecx]
0x5ad83c  8b82d4000000                      mov    eax,DWORD PTR [edx+0xd4]
0x5ad842  ffd0                              call   eax
0x5ad844  8b9b4c020000                      mov    ebx,DWORD PTR [ebx+0x24c]
0x5ad84a  8b33                              mov    esi,DWORD PTR [ebx]
0x5ad84c  3bf3                              cmp    esi,ebx
0x5ad84e  7419                              je     0x5ad869
0x5ad850  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x5ad853  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5ad856  c1e908                            shr    ecx,0x8
0x5ad859  f6c101                            test   cl,0x1
0x5ad85c  7405                              je     0x5ad863
0x5ad85e  e83dbe1100                        call   0x6c96a0
0x5ad863  8b36                              mov    esi,DWORD PTR [esi]
0x5ad865  3bf3                              cmp    esi,ebx
0x5ad867  75e7                              jne    0x5ad850
0x5ad869  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x5ad86d  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5ad874  59                                pop    ecx
0x5ad875  5f                                pop    edi
0x5ad876  5e                                pop    esi
0x5ad877  5b                                pop    ebx
0x5ad878  8be5                              mov    esp,ebp
0x5ad87a  5d                                pop    ebp
0x5ad87b  c3                                ret

### U03 Scenario page update calls common FieldPage update
VA 0x5afeb0 RAW 0x1af2b0 END 0x5aff0e SHA256 5316c8932451c198dbb1377faee0ff1c392686853821f7c3a282de22d3fbe031
0x5afeb0  57                                push   edi
0x5afeb1  8bf9                              mov    edi,ecx
0x5afeb3  e838b3feff                        call   0x59b1f0
0x5afeb8  8b871c020000                      mov    eax,DWORD PTR [edi+0x21c]
0x5afebe  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5afec1  c1e908                            shr    ecx,0x8
0x5afec4  f6c101                            test   cl,0x1
0x5afec7  7406                              je     0x5afecf
0x5afec9  50                                push   eax
0x5afeca  e861e50900                        call   0x64e430
0x5afecf  56                                push   esi
0x5afed0  8bb720020000                      mov    esi,DWORD PTR [edi+0x220]
0x5afed6  8b5628                            mov    edx,DWORD PTR [esi+0x28]
0x5afed9  c1ea08                            shr    edx,0x8
0x5afedc  f6c201                            test   dl,0x1
0x5afedf  7405                              je     0x5afee6
0x5afee1  e87ad40a00                        call   0x65d360
0x5afee6  8b8724020000                      mov    eax,DWORD PTR [edi+0x224]
0x5afeec  5e                                pop    esi
0x5afeed  85c0                              test   eax,eax
0x5afeef  7406                              je     0x5afef7
0x5afef1  50                                push   eax
0x5afef2  e8c99c0a00                        call   0x659bc0
0x5afef7  8bbf28020000                      mov    edi,DWORD PTR [edi+0x228]
0x5afefd  85ff                              test   edi,edi
0x5afeff  740b                              je     0x5aff0c
0x5aff01  57                                push   edi
0x5aff02  e8b9290a00                        call   0x6528c0
0x5aff07  e8b42b0a00                        call   0x652ac0
0x5aff0c  5f                                pop    edi
0x5aff0d  c3                                ret

### U04 ordinary derived page initializer calls shared598890
VA 0x5ac3e0 RAW 0x1ab7e0 END 0x5ac4fa SHA256 10be00bdf552d8c13af0e7cc5d1230296e929810695c463cc79eaf4581d6e4e1
0x5ac3e0  55                                push   ebp
0x5ac3e1  8bec                              mov    ebp,esp
0x5ac3e3  6aff                              push   0xffffffff
0x5ac3e5  68ce399400                        push   0x9439ce
0x5ac3ea  64a100000000                      mov    eax,fs:0x0
0x5ac3f0  50                                push   eax
0x5ac3f1  83ec14                            sub    esp,0x14
0x5ac3f4  53                                push   ebx
0x5ac3f5  56                                push   esi
0x5ac3f6  57                                push   edi
0x5ac3f7  a1201fd600                        mov    eax,ds:0xd61f20
0x5ac3fc  33c5                              xor    eax,ebp
0x5ac3fe  50                                push   eax
0x5ac3ff  8d45f4                            lea    eax,[ebp-0xc]
0x5ac402  64a300000000                      mov    fs:0x0,eax
0x5ac408  8bd9                              mov    ebx,ecx
0x5ac40a  e881c4feff                        call   0x598890
0x5ac40f  33c0                              xor    eax,eax
0x5ac411  8945e4                            mov    DWORD PTR [ebp-0x1c],eax
0x5ac414  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x5ac417  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5ac41a  c745e00c92c100                    mov    DWORD PTR [ebp-0x20],0xc1920c
0x5ac421  390570fcf700                      cmp    DWORD PTR ds:0xf7fc70,eax
0x5ac427  7405                              je     0x5ac42e
0x5ac429  a370fcf700                        mov    ds:0xf7fc70,eax
0x5ac42e  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x5ac435  8db31c020000                      lea    esi,[ebx+0x21c]
0x5ac43b  e8e0040000                        call   0x5ac920
0x5ac440  56                                push   esi
0x5ac441  8bc8                              mov    ecx,eax
0x5ac443  8d7de0                            lea    edi,[ebp-0x20]
0x5ac446  e8f5daffff                        call   0x5a9f40
0x5ac44b  e8b0050000                        call   0x5aca00
0x5ac450  8d8b20020000                      lea    ecx,[ebx+0x220]
0x5ac456  51                                push   ecx
0x5ac457  8bc8                              mov    ecx,eax
0x5ac459  e8e2daffff                        call   0x5a9f40
0x5ac45e  53                                push   ebx
0x5ac45f  8bf7                              mov    esi,edi
0x5ac461  e80af2e5ff                        call   0x40b670
0x5ac466  8b8b1c020000                      mov    ecx,DWORD PTR [ebx+0x21c]
0x5ac46c  8b11                              mov    edx,DWORD PTR [ecx]
0x5ac46e  8b82d0000000                      mov    eax,DWORD PTR [edx+0xd0]
0x5ac474  ffd0                              call   eax
0x5ac476  8b8bdc010000                      mov    ecx,DWORD PTR [ebx+0x1dc]
0x5ac47c  8b11                              mov    edx,DWORD PTR [ecx]
0x5ac47e  8b82d4000000                      mov    eax,DWORD PTR [edx+0xd4]
0x5ac484  ffd0                              call   eax
0x5ac486  6a01                              push   0x1
0x5ac488  32c9                              xor    cl,cl
0x5ac48a  8bd3                              mov    edx,ebx
0x5ac48c  e84f91ffff                        call   0x5a55e0
0x5ac491  f6057caffa0001                    test   BYTE PTR ds:0xfaaf7c,0x1
0x5ac498  7521                              jne    0x5ac4bb
0x5ac49a  830d7caffa0001                    or     DWORD PTR ds:0xfaaf7c,0x1
0x5ac4a1  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x5ac4a5  e8660ffeff                        call   0x58d410
0x5ac4aa  68c0cdbc00                        push   0xbccdc0
0x5ac4af  e8665e2e00                        call   0x89231a
0x5ac4b4  83c404                            add    esp,0x4
0x5ac4b7  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5ac4bb  8b8b1c020000                      mov    ecx,DWORD PTR [ebx+0x21c]
0x5ac4c1  51                                push   ecx
0x5ac4c2  bf4cd1c100                        mov    edi,0xc1d14c
0x5ac4c7  b980affa00                        mov    ecx,0xfaaf80
0x5ac4cc  e8ef1cfeff                        call   0x58e1c0
0x5ac4d1  8b45e4                            mov    eax,DWORD PTR [ebp-0x1c]
0x5ac4d4  c745e0e429bf00                    mov    DWORD PTR [ebp-0x20],0xbf29e4
0x5ac4db  85c0                              test   eax,eax
0x5ac4dd  7409                              je     0x5ac4e8
0x5ac4df  50                                push   eax
0x5ac4e0  e8274d2e00                        call   0x89120c
0x5ac4e5  83c404                            add    esp,0x4
0x5ac4e8  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5ac4eb  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5ac4f2  59                                pop    ecx
0x5ac4f3  5f                                pop    edi
0x5ac4f4  5e                                pop    esi
0x5ac4f5  5b                                pop    ebx
0x5ac4f6  8be5                              mov    esp,ebp
0x5ac4f8  5d                                pop    ebp
0x5ac4f9  c3                                ret

### U05 Mission page init:common base and +22C descriptor binding
VA 0x5acea0 RAW 0x1ac2a0 END 0x5ad04a SHA256 730130bb837618d751e8731f0899977d9a399897f3ef4e48dcc94eb07ddfaf15
0x5acea0  55                                push   ebp
0x5acea1  8bec                              mov    ebp,esp
0x5acea3  6aff                              push   0xffffffff
0x5acea5  68ce399400                        push   0x9439ce
0x5aceaa  64a100000000                      mov    eax,fs:0x0
0x5aceb0  50                                push   eax
0x5aceb1  83ec14                            sub    esp,0x14
0x5aceb4  53                                push   ebx
0x5aceb5  56                                push   esi
0x5aceb6  57                                push   edi
0x5aceb7  a1201fd600                        mov    eax,ds:0xd61f20
0x5acebc  33c5                              xor    eax,ebp
0x5acebe  50                                push   eax
0x5acebf  8d45f4                            lea    eax,[ebp-0xc]
0x5acec2  64a300000000                      mov    fs:0x0,eax
0x5acec8  8bd9                              mov    ebx,ecx
0x5aceca  e811f5ffff                        call   0x5ac3e0
0x5acecf  33c0                              xor    eax,eax
0x5aced1  8945e4                            mov    DWORD PTR [ebp-0x1c],eax
0x5aced4  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x5aced7  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5aceda  c745e00c92c100                    mov    DWORD PTR [ebp-0x20],0xc1920c
0x5acee1  390570fcf700                      cmp    DWORD PTR ds:0xf7fc70,eax
0x5acee7  7405                              je     0x5aceee
0x5acee9  a370fcf700                        mov    ds:0xf7fc70,eax
0x5aceee  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x5acef5  8db324020000                      lea    esi,[ebx+0x224]
0x5acefb  e870a2e8ff                        call   0x437170
0x5acf00  56                                push   esi
0x5acf01  8bc8                              mov    ecx,eax
0x5acf03  8d7de0                            lea    edi,[ebp-0x20]
0x5acf06  e835d0ffff                        call   0x5a9f40
0x5acf0b  8db328020000                      lea    esi,[ebx+0x228]
0x5acf11  e87aa1e8ff                        call   0x437090
0x5acf16  56                                push   esi
0x5acf17  8bc8                              mov    ecx,eax
0x5acf19  e822d0ffff                        call   0x5a9f40
0x5acf1e  8db32c020000                      lea    esi,[ebx+0x22c]
0x5acf24  e8370d0000                        call   0x5adc60
0x5acf29  56                                push   esi
0x5acf2a  8bc8                              mov    ecx,eax
0x5acf2c  e80fd0ffff                        call   0x5a9f40
0x5acf31  e80a0e0000                        call   0x5add40
0x5acf36  8d8b34020000                      lea    ecx,[ebx+0x234]
0x5acf3c  51                                push   ecx
0x5acf3d  8bc8                              mov    ecx,eax
0x5acf3f  e8fccfffff                        call   0x5a9f40
0x5acf44  e8e70e0000                        call   0x5ade30
0x5acf49  8d9338020000                      lea    edx,[ebx+0x238]
0x5acf4f  52                                push   edx
0x5acf50  8bc8                              mov    ecx,eax
0x5acf52  e8e9cfffff                        call   0x5a9f40
0x5acf57  8db33c020000                      lea    esi,[ebx+0x23c]
0x5acf5d  e8ae0f0000                        call   0x5adf10
0x5acf62  56                                push   esi
0x5acf63  8bc8                              mov    ecx,eax
0x5acf65  e8d6cfffff                        call   0x5a9f40
0x5acf6a  e881100000                        call   0x5adff0
0x5acf6f  8d8b40020000                      lea    ecx,[ebx+0x240]
0x5acf75  51                                push   ecx
0x5acf76  8bc8                              mov    ecx,eax
0x5acf78  e8c3cfffff                        call   0x5a9f40
0x5acf7d  e84e110000                        call   0x5ae0d0
0x5acf82  8d9348020000                      lea    edx,[ebx+0x248]
0x5acf88  52                                push   edx
0x5acf89  8bc8                              mov    ecx,eax
0x5acf8b  e8b0cfffff                        call   0x5a9f40
0x5acf90  53                                push   ebx
0x5acf91  8bf7                              mov    esi,edi
0x5acf93  e8d8e6e5ff                        call   0x40b670
0x5acf98  8b8b24020000                      mov    ecx,DWORD PTR [ebx+0x224]
0x5acf9e  8b01                              mov    eax,DWORD PTR [ecx]
0x5acfa0  8b90d0000000                      mov    edx,DWORD PTR [eax+0xd0]
0x5acfa6  ffd2                              call   edx
0x5acfa8  8b8b28020000                      mov    ecx,DWORD PTR [ebx+0x228]
0x5acfae  8b01                              mov    eax,DWORD PTR [ecx]
0x5acfb0  8b90d0000000                      mov    edx,DWORD PTR [eax+0xd0]
0x5acfb6  ffd2                              call   edx
0x5acfb8  8b8b2c020000                      mov    ecx,DWORD PTR [ebx+0x22c]
0x5acfbe  8b01                              mov    eax,DWORD PTR [ecx]
0x5acfc0  8b90d0000000                      mov    edx,DWORD PTR [eax+0xd0]
0x5acfc6  ffd2                              call   edx
0x5acfc8  8b833c020000                      mov    eax,DWORD PTR [ebx+0x23c]
0x5acfce  6a00                              push   0x0
0x5acfd0  6a00                              push   0x0
0x5acfd2  6a00                              push   0x0
0x5acfd4  6a00                              push   0x0
0x5acfd6  6a00                              push   0x0
0x5acfd8  50                                push   eax
0x5acfd9  53                                push   ebx
0x5acfda  33c0                              xor    eax,eax
0x5acfdc  e88f9dfeff                        call   0x596d70
0x5acfe1  f6057caffa0001                    test   BYTE PTR ds:0xfaaf7c,0x1
0x5acfe8  7521                              jne    0x5ad00b
0x5acfea  830d7caffa0001                    or     DWORD PTR ds:0xfaaf7c,0x1
0x5acff1  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x5acff5  e81604feff                        call   0x58d410
0x5acffa  68c0cdbc00                        push   0xbccdc0
0x5acfff  e816532e00                        call   0x89231a
0x5ad004  83c404                            add    esp,0x4
0x5ad007  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5ad00b  8b8324020000                      mov    eax,DWORD PTR [ebx+0x224]
0x5ad011  50                                push   eax
0x5ad012  bfdc9bbf00                        mov    edi,0xbf9bdc
0x5ad017  b980affa00                        mov    ecx,0xfaaf80
0x5ad01c  e89f11feff                        call   0x58e1c0
0x5ad021  8b45e4                            mov    eax,DWORD PTR [ebp-0x1c]
0x5ad024  c745e0e429bf00                    mov    DWORD PTR [ebp-0x20],0xbf29e4
0x5ad02b  85c0                              test   eax,eax
0x5ad02d  7409                              je     0x5ad038
0x5ad02f  50                                push   eax
0x5ad030  e8d7412e00                        call   0x89120c
0x5ad035  83c404                            add    esp,0x4
0x5ad038  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5ad03b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5ad042  59                                pop    ecx
0x5ad043  5f                                pop    edi
0x5ad044  5e                                pop    esi
0x5ad045  5b                                pop    ebx
0x5ad046  8be5                              mov    esp,ebp
0x5ad048  5d                                pop    ebp
0x5ad049  c3                                ret

### U06 Scenario page init:common base and distinct own children
VA 0x5afc30 RAW 0x1af030 END 0x5afdb1 SHA256 d31a00025257e34be1cd58005ba36765df5b388a295c480f4d207ea2ad4a913c
0x5afc30  55                                push   ebp
0x5afc31  8bec                              mov    ebp,esp
0x5afc33  83e4f8                            and    esp,0xfffffff8
0x5afc36  6aff                              push   0xffffffff
0x5afc38  684c749400                        push   0x94744c
0x5afc3d  64a100000000                      mov    eax,fs:0x0
0x5afc43  50                                push   eax
0x5afc44  83ec20                            sub    esp,0x20
0x5afc47  53                                push   ebx
0x5afc48  56                                push   esi
0x5afc49  57                                push   edi
0x5afc4a  a1201fd600                        mov    eax,ds:0xd61f20
0x5afc4f  33c4                              xor    eax,esp
0x5afc51  50                                push   eax
0x5afc52  8d442430                          lea    eax,[esp+0x30]
0x5afc56  64a300000000                      mov    fs:0x0,eax
0x5afc5c  8bf1                              mov    esi,ecx
0x5afc5e  e87dc7ffff                        call   0x5ac3e0
0x5afc63  33c0                              xor    eax,eax
0x5afc65  8944241c                          mov    DWORD PTR [esp+0x1c],eax
0x5afc69  89442420                          mov    DWORD PTR [esp+0x20],eax
0x5afc6d  89442424                          mov    DWORD PTR [esp+0x24],eax
0x5afc71  c74424180c92c100                  mov    DWORD PTR [esp+0x18],0xc1920c
0x5afc79  390570fcf700                      cmp    DWORD PTR ds:0xf7fc70,eax
0x5afc7f  7405                              je     0x5afc86
0x5afc81  a370fcf700                        mov    ds:0xf7fc70,eax
0x5afc86  c744243801000000                  mov    DWORD PTR [esp+0x38],0x1
0x5afc8e  8d9e28020000                      lea    ebx,[esi+0x228]
0x5afc94  e8f773e8ff                        call   0x437090
0x5afc99  53                                push   ebx
0x5afc9a  8bc8                              mov    ecx,eax
0x5afc9c  8d7c241c                          lea    edi,[esp+0x1c]
0x5afca0  e89ba2ffff                        call   0x5a9f40
0x5afca5  8dbe24020000                      lea    edi,[esi+0x224]
0x5afcab  897c2410                          mov    DWORD PTR [esp+0x10],edi
0x5afcaf  e8bc74e8ff                        call   0x437170
0x5afcb4  57                                push   edi
0x5afcb5  8bc8                              mov    ecx,eax
0x5afcb7  8d7c241c                          lea    edi,[esp+0x1c]
0x5afcbb  e880a2ffff                        call   0x5a9f40
0x5afcc0  8dbe2c020000                      lea    edi,[esi+0x22c]
0x5afcc6  897c2414                          mov    DWORD PTR [esp+0x14],edi
0x5afcca  e8516deaff                        call   0x456a20
0x5afccf  57                                push   edi
0x5afcd0  8bc8                              mov    ecx,eax
0x5afcd2  8d7c241c                          lea    edi,[esp+0x1c]
0x5afcd6  e865a2ffff                        call   0x5a9f40
0x5afcdb  56                                push   esi
0x5afcdc  8bf7                              mov    esi,edi
0x5afcde  e88db9e5ff                        call   0x40b670
0x5afce3  8b742410                          mov    esi,DWORD PTR [esp+0x10]
0x5afce7  8b0e                              mov    ecx,DWORD PTR [esi]
0x5afce9  8b01                              mov    eax,DWORD PTR [ecx]
0x5afceb  8b90d0000000                      mov    edx,DWORD PTR [eax+0xd0]
0x5afcf1  ffd2                              call   edx
0x5afcf3  8b1b                              mov    ebx,DWORD PTR [ebx]
0x5afcf5  8b03                              mov    eax,DWORD PTR [ebx]
0x5afcf7  8b90d0000000                      mov    edx,DWORD PTR [eax+0xd0]
0x5afcfd  8bcb                              mov    ecx,ebx
0x5afcff  ffd2                              call   edx
0x5afd01  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x5afd08  7523                              jne    0x5afd2d
0x5afd0a  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
0x5afd11  c644243802                        mov    BYTE PTR [esp+0x38],0x2
0x5afd16  e875eff2ff                        call   0x4dec90
0x5afd1b  6830cebc00                        push   0xbcce30
0x5afd20  e8f5252e00                        call   0x89231a
0x5afd25  83c404                            add    esp,0x4
0x5afd28  c644243801                        mov    BYTE PTR [esp+0x38],0x1
0x5afd2d  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x5afd33  8b01                              mov    eax,DWORD PTR [ecx]
0x5afd35  8b504c                            mov    edx,DWORD PTR [eax+0x4c]
0x5afd38  ffd2                              call   edx
0x5afd3a  50                                push   eax
0x5afd3b  8b442418                          mov    eax,DWORD PTR [esp+0x18]
0x5afd3f  8b08                              mov    ecx,DWORD PTR [eax]
0x5afd41  51                                push   ecx
0x5afd42  e849ab1000                        call   0x6ba890
0x5afd47  f6057caffa0001                    test   BYTE PTR ds:0xfaaf7c,0x1
0x5afd4e  7523                              jne    0x5afd73
0x5afd50  830d7caffa0001                    or     DWORD PTR ds:0xfaaf7c,0x1
0x5afd57  c644243803                        mov    BYTE PTR [esp+0x38],0x3
0x5afd5c  e8afd6fdff                        call   0x58d410
0x5afd61  68c0cdbc00                        push   0xbccdc0
0x5afd66  e8af252e00                        call   0x89231a
0x5afd6b  83c404                            add    esp,0x4
0x5afd6e  c644243801                        mov    BYTE PTR [esp+0x38],0x1
0x5afd73  8b16                              mov    edx,DWORD PTR [esi]
0x5afd75  52                                push   edx
0x5afd76  bfdc9bbf00                        mov    edi,0xbf9bdc
0x5afd7b  b980affa00                        mov    ecx,0xfaaf80
0x5afd80  e83be4fdff                        call   0x58e1c0
0x5afd85  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
0x5afd89  c7442418e429bf00                  mov    DWORD PTR [esp+0x18],0xbf29e4
0x5afd91  85c0                              test   eax,eax
0x5afd93  7409                              je     0x5afd9e
0x5afd95  50                                push   eax
0x5afd96  e871142e00                        call   0x89120c
0x5afd9b  83c404                            add    esp,0x4
0x5afd9e  8b4c2430                          mov    ecx,DWORD PTR [esp+0x30]
0x5afda2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5afda9  59                                pop    ecx
0x5afdaa  5f                                pop    edi
0x5afdab  5e                                pop    esi
0x5afdac  5b                                pop    ebx
0x5afdad  8be5                              mov    esp,ebp
0x5afdaf  5d                                pop    ebp
0x5afdb0  c3                                ret

### U07 shared page init assigns +168 Inventory and +164 via page+1A4
VA 0x598a61 RAW 0x197e61 END 0x598ade SHA256 ade81cfc27e9025102ee5dbd260630bd83133ef2e644b05a5d462a512b323a18
0x598a61  8db368010000                      lea    esi,[ebx+0x168]
0x598a67  e844560000                        call   0x59e0b0
0x598a6c  56                                push   esi
0x598a6d  8bc8                              mov    ecx,eax
0x598a6f  8d7c244c                          lea    edi,[esp+0x4c]
0x598a73  e8c8140100                        call   0x5a9f40
0x598a78  e813570000                        call   0x59e190
0x598a7d  8d8b7c010000                      lea    ecx,[ebx+0x17c]
0x598a83  51                                push   ecx
0x598a84  8bc8                              mov    ecx,eax
0x598a86  e8b5140100                        call   0x5a9f40
0x598a8b  e8e0570000                        call   0x59e270
0x598a90  8d9378010000                      lea    edx,[ebx+0x178]
0x598a96  52                                push   edx
0x598a97  8bc8                              mov    ecx,eax
0x598a99  e8a2140100                        call   0x5a9f40
0x598a9e  8db370010000                      lea    esi,[ebx+0x170]
0x598aa4  e8a7580000                        call   0x59e350
0x598aa9  56                                push   esi
0x598aaa  8bc8                              mov    ecx,eax
0x598aac  e88f140100                        call   0x5a9f40
0x598ab1  e87a590000                        call   0x59e430
0x598ab6  8d8b74010000                      lea    ecx,[ebx+0x174]
0x598abc  51                                push   ecx
0x598abd  8bc8                              mov    ecx,eax
0x598abf  e87c140100                        call   0x5a9f40
0x598ac4  8b13                              mov    edx,DWORD PTR [ebx]
0x598ac6  8b82a4010000                      mov    eax,DWORD PTR [edx+0x1a4]
0x598acc  8bcb                              mov    ecx,ebx
0x598ace  8db364010000                      lea    esi,[ebx+0x164]
0x598ad4  ffd0                              call   eax
0x598ad6  56                                push   esi
0x598ad7  8bc8                              mov    ecx,eax
0x598ad9  e862140100                        call   0x5a9f40

### U08 native Mission page+1A4 thunk to descriptor5AE1B0
VA 0x5ad690 RAW 0x1aca90 END 0x5ad695 SHA256 1c9e0a255cea9025a3692f3a56ef1ffd41de6d275eb857f769ad6854a9909f6a
0x5ad690  e91b0b0000                        jmp    0x5ae1b0

### U09 native Scenario page+1A4 thunk to descriptor456B00
VA 0x5b0160 RAW 0x1af560 END 0x5b0165 SHA256 2c713fa88663e58a0f8b9b06659b267bd2bebcf16eef744e60b7b36e7bc7bc8c
0x5b0160  e99b69eaff                        jmp    0x456b00

### U10 rechecked descriptor binding helper
VA 0x5a9f40 RAW 0x1a9340 END 0x5a9fce SHA256 517bf6a7931e0ce382ad8e162fe369d6a9d8d4a9e8c533366ba4ace5a071e3be
0x5a9f40  55                                push   ebp
0x5a9f41  8bec                              mov    ebp,esp
0x5a9f43  81ec08020000                      sub    esp,0x208
0x5a9f49  a1201fd600                        mov    eax,ds:0xd61f20
0x5a9f4e  33c5                              xor    eax,ebp
0x5a9f50  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5a9f53  53                                push   ebx
0x5a9f54  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x5a9f57  56                                push   esi
0x5a9f58  8bf1                              mov    esi,ecx
0x5a9f5a  8b06                              mov    eax,DWORD PTR [esi]
0x5a9f5c  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x5a9f5f  ffd2                              call   edx
0x5a9f61  8985f8fdffff                      mov    DWORD PTR [ebp-0x208],eax
0x5a9f67  8b06                              mov    eax,DWORD PTR [esi]
0x5a9f69  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x5a9f6c  8bce                              mov    ecx,esi
0x5a9f6e  ffd2                              call   edx
0x5a9f70  8bf0                              mov    esi,eax
0x5a9f72  8b85f8fdffff                      mov    eax,DWORD PTR [ebp-0x208]
0x5a9f78  53                                push   ebx
0x5a9f79  56                                push   esi
0x5a9f7a  8bcf                              mov    ecx,edi
0x5a9f7c  e8bf98ffff                        call   0x5a3840
0x5a9f81  8bd8                              mov    ebx,eax
0x5a9f83  85db                              test   ebx,ebx
0x5a9f85  7535                              jne    0x5a9fbc
0x5a9f87  8b07                              mov    eax,DWORD PTR [edi]
0x5a9f89  8b501c                            mov    edx,DWORD PTR [eax+0x1c]
0x5a9f8c  56                                push   esi
0x5a9f8d  8bcf                              mov    ecx,edi
0x5a9f8f  ffd2                              call   edx
0x5a9f91  50                                push   eax
0x5a9f92  56                                push   esi
0x5a9f93  689827bf00                        push   0xbf2798
0x5a9f98  8d95fcfdffff                      lea    edx,[ebp-0x204]
0x5a9f9e  e80d0fe6ff                        call   0x40aeb0
0x5a9fa3  83c40c                            add    esp,0xc
0x5a9fa6  53                                push   ebx
0x5a9fa7  68c01fbf00                        push   0xbf1fc0
0x5a9fac  8d85fcfdffff                      lea    eax,[ebp-0x204]
0x5a9fb2  50                                push   eax
0x5a9fb3  53                                push   ebx
0x5a9fb4  ff158025bd00                      call   DWORD PTR ds:0xbd2580
0x5a9fba  8bc3                              mov    eax,ebx
0x5a9fbc  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x5a9fbf  5e                                pop    esi
0x5a9fc0  33cd                              xor    ecx,ebp
0x5a9fc2  5b                                pop    ebx
0x5a9fc3  e839702e00                        call   0x891001
0x5a9fc8  8be5                              mov    esp,ebp
0x5a9fca  5d                                pop    ebp
0x5a9fcb  c20400                            ret    0x4

### U11 rechecked binding destination store
VA 0x5a3840 RAW 0x1a2c40 END 0x5a38e4 SHA256 969a39d4621985ff33a5a2ec1625366c43138a8df796d6dc5eeec363c4c95b21
0x5a3840  55                                push   ebp
0x5a3841  8bec                              mov    ebp,esp
0x5a3843  56                                push   esi
0x5a3844  57                                push   edi
0x5a3845  8bf1                              mov    esi,ecx
0x5a3847  8bf8                              mov    edi,eax
0x5a3849  8b06                              mov    eax,DWORD PTR [esi]
0x5a384b  8b5018                            mov    edx,DWORD PTR [eax+0x18]
0x5a384e  ffd2                              call   edx
0x5a3850  8b4f3c                            mov    ecx,DWORD PTR [edi+0x3c]
0x5a3853  894724                            mov    DWORD PTR [edi+0x24],eax
0x5a3856  85c9                              test   ecx,ecx
0x5a3858  740f                              je     0x5a3869
0x5a385a  f7472800000400                    test   DWORD PTR [edi+0x28],0x40000
0x5a3861  7506                              jne    0x5a3869
0x5a3863  50                                push   eax
0x5a3864  e8874e1a00                        call   0x7486f0
0x5a3869  53                                push   ebx
0x5a386a  8b5f64                            mov    ebx,DWORD PTR [edi+0x64]
0x5a386d  8b13                              mov    edx,DWORD PTR [ebx]
0x5a386f  3bd3                              cmp    edx,ebx
0x5a3871  7412                              je     0x5a3885
0x5a3873  8b4724                            mov    eax,DWORD PTR [edi+0x24]
0x5a3876  8b4a08                            mov    ecx,DWORD PTR [edx+0x8]
0x5a3879  50                                push   eax
0x5a387a  e8714e1a00                        call   0x7486f0
0x5a387f  8b12                              mov    edx,DWORD PTR [edx]
0x5a3881  3bd3                              cmp    edx,ebx
0x5a3883  75ee                              jne    0x5a3873
0x5a3885  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x5a3888  8939                              mov    DWORD PTR [ecx],edi
0x5a388a  8b16                              mov    edx,DWORD PTR [esi]
0x5a388c  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x5a388f  8bce                              mov    ecx,esi
0x5a3891  ffd0                              call   eax
0x5a3893  8b16                              mov    edx,DWORD PTR [esi]
0x5a3895  8b521c                            mov    edx,DWORD PTR [edx+0x1c]
0x5a3898  8bd8                              mov    ebx,eax
0x5a389a  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5a389d  8b3b                              mov    edi,DWORD PTR [ebx]
0x5a389f  8d4e04                            lea    ecx,[esi+0x4]
0x5a38a2  51                                push   ecx
0x5a38a3  50                                push   eax
0x5a38a4  8bce                              mov    ecx,esi
0x5a38a6  ffd2                              call   edx
0x5a38a8  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x5a38ab  50                                push   eax
0x5a38ac  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x5a38af  8b08                              mov    ecx,DWORD PTR [eax]
0x5a38b1  8b4728                            mov    eax,DWORD PTR [edi+0x28]
0x5a38b4  51                                push   ecx
0x5a38b5  52                                push   edx
0x5a38b6  8bcb                              mov    ecx,ebx
0x5a38b8  ffd0                              call   eax
0x5a38ba  8bf0                              mov    esi,eax
0x5a38bc  5b                                pop    ebx
0x5a38bd  85f6                              test   esi,esi
0x5a38bf  741b                              je     0x5a38dc
0x5a38c1  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x5a38c4  a801                              test   al,0x1
0x5a38c6  7406                              je     0x5a38ce
0x5a38c8  83f001                            xor    eax,0x1
0x5a38cb  894628                            mov    DWORD PTR [esi+0x28],eax
0x5a38ce  8b16                              mov    edx,DWORD PTR [esi]
0x5a38d0  8b8294000000                      mov    eax,DWORD PTR [edx+0x94]
0x5a38d6  6a00                              push   0x0
0x5a38d8  8bce                              mov    ecx,esi
0x5a38da  ffd0                              call   eax
0x5a38dc  5f                                pop    edi
0x5a38dd  8bc6                              mov    eax,esi
0x5a38df  5e                                pop    esi
0x5a38e0  5d                                pop    ebp
0x5a38e1  c20800                            ret    0x8

### U12 descriptor+10 getter returns owned +C window
VA 0x5ade20 RAW 0x1ad220 END 0x5ade24 SHA256 2e339cdc5de837ec151dbde90057caeabba18ac3ea32e7c2cffc8f95df41a6ff
0x5ade20  8b410c                            mov    eax,DWORD PTR [ecx+0xc]
0x5ade23  c3                                ret

### B01 Mission bottom singleton descriptor FE2DD0
VA 0x5ae1b0 RAW 0x1ad5b0 END 0x5ae284 SHA256 1aee5c46bae36e69d90e070bd64a72cf2e257619be914dc05943774021318712
0x5ae1b0  55                                push   ebp
0x5ae1b1  8bec                              mov    ebp,esp
0x5ae1b3  6aff                              push   0xffffffff
0x5ae1b5  6849e69100                        push   0x91e649
0x5ae1ba  64a100000000                      mov    eax,fs:0x0
0x5ae1c0  50                                push   eax
0x5ae1c1  83ec08                            sub    esp,0x8
0x5ae1c4  56                                push   esi
0x5ae1c5  57                                push   edi
0x5ae1c6  a1201fd600                        mov    eax,ds:0xd61f20
0x5ae1cb  33c5                              xor    eax,ebp
0x5ae1cd  50                                push   eax
0x5ae1ce  8d45f4                            lea    eax,[ebp-0xc]
0x5ae1d1  64a300000000                      mov    fs:0x0,eax
0x5ae1d7  a1d02dfe00                        mov    eax,ds:0xfe2dd0
0x5ae1dc  85c0                              test   eax,eax
0x5ae1de  0f858f000000                      jne    0x5ae273
0x5ae1e4  6a10                              push   0x10
0x5ae1e6  e87d302e00                        call   0x891268
0x5ae1eb  83c404                            add    esp,0x4
0x5ae1ee  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5ae1f1  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5ae1f8  85c0                              test   eax,eax
0x5ae1fa  7408                              je     0x5ae204
0x5ae1fc  50                                push   eax
0x5ae1fd  e88e070000                        call   0x5ae990
0x5ae202  eb02                              jmp    0x5ae206
0x5ae204  33c0                              xor    eax,eax
0x5ae206  83ceff                            or     esi,0xffffffff
0x5ae209  8bc8                              mov    ecx,eax
0x5ae20b  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5ae20e  b801000000                        mov    eax,0x1
0x5ae213  890dd02dfe00                      mov    DWORD PTR ds:0xfe2dd0,ecx
0x5ae219  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x5ae21f  7524                              jne    0x5ae245
0x5ae221  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x5ae227  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5ae22a  e881fde9ff                        call   0x44dfb0
0x5ae22f  6810cdbc00                        push   0xbccd10
0x5ae234  e8e1402e00                        call   0x89231a
0x5ae239  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5ae23c  8b0dd02dfe00                      mov    ecx,DWORD PTR ds:0xfe2dd0
0x5ae242  83c404                            add    esp,0x4
0x5ae245  8b01                              mov    eax,DWORD PTR [ecx]
0x5ae247  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x5ae24a  8bf1                              mov    esi,ecx
0x5ae24c  ffd2                              call   edx
0x5ae24e  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x5ae251  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5ae254  8d7dec                            lea    edi,[ebp-0x14]
0x5ae257  beecaffa00                        mov    esi,0xfaafec
0x5ae25c  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5ae25f  e8bc0cfdff                        call   0x57ef20
0x5ae264  50                                push   eax
0x5ae265  56                                push   esi
0x5ae266  8d75ec                            lea    esi,[ebp-0x14]
0x5ae269  e8920f2800                        call   0x82f200
0x5ae26e  a1d02dfe00                        mov    eax,ds:0xfe2dd0
0x5ae273  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5ae276  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5ae27d  59                                pop    ecx
0x5ae27e  5f                                pop    edi
0x5ae27f  5e                                pop    esi
0x5ae280  8be5                              mov    esp,ebp
0x5ae282  5d                                pop    ebp
0x5ae283  c3                                ret

### B02 Scenario bottom singleton descriptor FC0C74
VA 0x456b00 RAW 0x55f00 END 0x456bd4 SHA256 0b9ebb0b174e6a073cfc8e6a8c75de7e5f9c3fa8b0d54b6b4635b3b140b145b6
0x456b00  55                                push   ebp
0x456b01  8bec                              mov    ebp,esp
0x456b03  6aff                              push   0xffffffff
0x456b05  6849e69100                        push   0x91e649
0x456b0a  64a100000000                      mov    eax,fs:0x0
0x456b10  50                                push   eax
0x456b11  83ec08                            sub    esp,0x8
0x456b14  56                                push   esi
0x456b15  57                                push   edi
0x456b16  a1201fd600                        mov    eax,ds:0xd61f20
0x456b1b  33c5                              xor    eax,ebp
0x456b1d  50                                push   eax
0x456b1e  8d45f4                            lea    eax,[ebp-0xc]
0x456b21  64a300000000                      mov    fs:0x0,eax
0x456b27  a1740cfc00                        mov    eax,ds:0xfc0c74
0x456b2c  85c0                              test   eax,eax
0x456b2e  0f858f000000                      jne    0x456bc3
0x456b34  6a10                              push   0x10
0x456b36  e82da74300                        call   0x891268
0x456b3b  83c404                            add    esp,0x4
0x456b3e  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x456b41  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x456b48  85c0                              test   eax,eax
0x456b4a  7408                              je     0x456b54
0x456b4c  50                                push   eax
0x456b4d  e81e020000                        call   0x456d70
0x456b52  eb02                              jmp    0x456b56
0x456b54  33c0                              xor    eax,eax
0x456b56  83ceff                            or     esi,0xffffffff
0x456b59  8bc8                              mov    ecx,eax
0x456b5b  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x456b5e  b801000000                        mov    eax,0x1
0x456b63  890d740cfc00                      mov    DWORD PTR ds:0xfc0c74,ecx
0x456b69  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x456b6f  7524                              jne    0x456b95
0x456b71  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x456b77  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x456b7a  e83174ffff                        call   0x44dfb0
0x456b7f  6810cdbc00                        push   0xbccd10
0x456b84  e891b74300                        call   0x89231a
0x456b89  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x456b8c  8b0d740cfc00                      mov    ecx,DWORD PTR ds:0xfc0c74
0x456b92  83c404                            add    esp,0x4
0x456b95  8b01                              mov    eax,DWORD PTR [ecx]
0x456b97  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x456b9a  8bf1                              mov    esi,ecx
0x456b9c  ffd2                              call   edx
0x456b9e  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x456ba1  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x456ba4  8d7dec                            lea    edi,[ebp-0x14]
0x456ba7  beecaffa00                        mov    esi,0xfaafec
0x456bac  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x456baf  e86c831200                        call   0x57ef20
0x456bb4  50                                push   eax
0x456bb5  56                                push   esi
0x456bb6  8d75ec                            lea    esi,[ebp-0x14]
0x456bb9  e842863d00                        call   0x82f200
0x456bbe  a1740cfc00                        mov    eax,ds:0xfc0c74
0x456bc3  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x456bc6  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x456bcd  59                                pop    ecx
0x456bce  5f                                pop    edi
0x456bcf  5e                                pop    esi
0x456bd0  8be5                              mov    esp,ebp
0x456bd2  5d                                pop    ebp
0x456bd3  c3                                ret

### B03 Mission bottom descriptor alloc384 and concrete vptr C21B64
VA 0x5ae990 RAW 0x1add90 END 0x5aea19 SHA256 cf08c44665568bd0463a0f3e128c263c8bba59e214c20be02e45841cf3cf8d13
0x5ae990  55                                push   ebp
0x5ae991  8bec                              mov    ebp,esp
0x5ae993  6aff                              push   0xffffffff
0x5ae995  6820189200                        push   0x921820
0x5ae99a  64a100000000                      mov    eax,fs:0x0
0x5ae9a0  50                                push   eax
0x5ae9a1  51                                push   ecx
0x5ae9a2  53                                push   ebx
0x5ae9a3  56                                push   esi
0x5ae9a4  57                                push   edi
0x5ae9a5  a1201fd600                        mov    eax,ds:0xd61f20
0x5ae9aa  33c5                              xor    eax,ebp
0x5ae9ac  50                                push   eax
0x5ae9ad  8d45f4                            lea    eax,[ebp-0xc]
0x5ae9b0  64a300000000                      mov    fs:0x0,eax
0x5ae9b6  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5ae9b9  33db                              xor    ebx,ebx
0x5ae9bb  895f04                            mov    DWORD PTR [edi+0x4],ebx
0x5ae9be  895f08                            mov    DWORD PTR [edi+0x8],ebx
0x5ae9c1  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x5ae9c4  6884030000                        push   0x384
0x5ae9c9  c707e8d3c100                      mov    DWORD PTR [edi],0xc1d3e8
0x5ae9cf  e894362e00                        call   0x892068
0x5ae9d4  8bf0                              mov    esi,eax
0x5ae9d6  83c404                            add    esp,0x4
0x5ae9d9  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5ae9dc  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5ae9e0  3bf3                              cmp    esi,ebx
0x5ae9e2  7413                              je     0x5ae9f7
0x5ae9e4  e817d80100                        call   0x5cc200
0x5ae9e9  c706641bc200                      mov    DWORD PTR [esi],0xc21b64
0x5ae9ef  899e80030000                      mov    DWORD PTR [esi+0x380],ebx
0x5ae9f5  eb02                              jmp    0x5ae9f9
0x5ae9f7  33f6                              xor    esi,esi
0x5ae9f9  89770c                            mov    DWORD PTR [edi+0xc],esi
0x5ae9fc  c747044b000000                    mov    DWORD PTR [edi+0x4],0x4b
0x5aea03  8bc7                              mov    eax,edi
0x5aea05  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5aea08  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5aea0f  59                                pop    ecx
0x5aea10  5f                                pop    edi
0x5aea11  5e                                pop    esi
0x5aea12  5b                                pop    ebx
0x5aea13  8be5                              mov    esp,ebp
0x5aea15  5d                                pop    ebp
0x5aea16  c20400                            ret    0x4

### B04 Scenario bottom descriptor alloc384 and concrete vptr C2208C
VA 0x456d70 RAW 0x56170 END 0x456dfb SHA256 16f84e46f39519d9523239133d6aa9d9cbea29996fda626ecb844b73b0e6e24c
0x456d70  55                                push   ebp
0x456d71  8bec                              mov    ebp,esp
0x456d73  6aff                              push   0xffffffff
0x456d75  6820ae9100                        push   0x91ae20
0x456d7a  64a100000000                      mov    eax,fs:0x0
0x456d80  50                                push   eax
0x456d81  51                                push   ecx
0x456d82  56                                push   esi
0x456d83  57                                push   edi
0x456d84  a1201fd600                        mov    eax,ds:0xd61f20
0x456d89  33c5                              xor    eax,ebp
0x456d8b  50                                push   eax
0x456d8c  8d45f4                            lea    eax,[ebp-0xc]
0x456d8f  64a300000000                      mov    fs:0x0,eax
0x456d95  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x456d98  c7470400000000                    mov    DWORD PTR [edi+0x4],0x0
0x456d9f  c7470800000000                    mov    DWORD PTR [edi+0x8],0x0
0x456da6  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x456dad  6884030000                        push   0x384
0x456db2  c70770dbbf00                      mov    DWORD PTR [edi],0xbfdb70
0x456db8  e8abb24300                        call   0x892068
0x456dbd  8bf0                              mov    esi,eax
0x456dbf  83c404                            add    esp,0x4
0x456dc2  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x456dc5  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x456dc9  85f6                              test   esi,esi
0x456dcb  740d                              je     0x456dda
0x456dcd  e82e541700                        call   0x5cc200
0x456dd2  c7068c20c200                      mov    DWORD PTR [esi],0xc2208c
0x456dd8  eb02                              jmp    0x456ddc
0x456dda  33f6                              xor    esi,esi
0x456ddc  89770c                            mov    DWORD PTR [edi+0xc],esi
0x456ddf  c747044b000000                    mov    DWORD PTR [edi+0x4],0x4b
0x456de6  8bc7                              mov    eax,edi
0x456de8  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x456deb  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x456df2  59                                pop    ecx
0x456df3  5f                                pop    edi
0x456df4  5e                                pop    esi
0x456df5  8be5                              mov    esp,ebp
0x456df7  5d                                pop    ebp
0x456df8  c20400                            ret    0x4

### B05 Mission bottom+198 reads its +380 part then5D1BF0
VA 0x5d4780 RAW 0x1d3b80 END 0x5d4797 SHA256 92134555f8cedb592bd177526106ee7da23e9a7d62b5b3c2d9cce93ab7bc5a1b
0x5d4780  56                                push   esi
0x5d4781  57                                push   edi
0x5d4782  8bf1                              mov    esi,ecx
0x5d4784  e827a3ffff                        call   0x5ceab0
0x5d4789  8bbe80030000                      mov    edi,DWORD PTR [esi+0x380]
0x5d478f  e85cd4ffff                        call   0x5d1bf0
0x5d4794  5f                                pop    edi
0x5d4795  5e                                pop    esi
0x5d4796  c3                                ret

### B06 Scenario bottom+198 reads its +380 part then5D3700
VA 0x5d5180 RAW 0x1d4580 END 0x5d5196 SHA256 3a81b2032234332af827fad53d65f2023d95004c16ee838e89e58a95893a2cb0
0x5d5180  56                                push   esi
0x5d5181  8bf1                              mov    esi,ecx
0x5d5183  e82899ffff                        call   0x5ceab0
0x5d5188  8b8680030000                      mov    eax,DWORD PTR [esi+0x380]
0x5d518e  50                                push   eax
0x5d518f  e86ce5ffff                        call   0x5d3700
0x5d5194  5e                                pop    esi
0x5d5195  c3                                ret

### B07 shared bottom native refresh calls and action-availability UI writer
VA 0x5ceab0 RAW 0x1cdeb0 END 0x5ceb90 SHA256 56932fe230e4497a90beeaf1a6ae756f309e749c6e297fae108f8fb71f3c5e9e
0x5ceab0  55                                push   ebp
0x5ceab1  8bec                              mov    ebp,esp
0x5ceab3  83e4f8                            and    esp,0xfffffff8
0x5ceab6  6aff                              push   0xffffffff
0x5ceab8  682e389400                        push   0x94382e
0x5ceabd  64a100000000                      mov    eax,fs:0x0
0x5ceac3  50                                push   eax
0x5ceac4  83ec0c                            sub    esp,0xc
0x5ceac7  53                                push   ebx
0x5ceac8  57                                push   edi
0x5ceac9  a1201fd600                        mov    eax,ds:0xd61f20
0x5ceace  33c4                              xor    eax,esp
0x5cead0  50                                push   eax
0x5cead1  8d442418                          lea    eax,[esp+0x18]
0x5cead5  64a300000000                      mov    fs:0x0,eax
0x5ceadb  8bf9                              mov    edi,ecx
0x5ceadd  e84ee2ffff                        call   0x5ccd30
0x5ceae2  e829e7ffff                        call   0x5cd210
0x5ceae7  57                                push   edi
0x5ceae8  e833eaffff                        call   0x5cd520
0x5ceaed  57                                push   edi
0x5ceaee  e8cde8ffff                        call   0x5cd3c0
0x5ceaf3  57                                push   edi
0x5ceaf4  e837f9ffff                        call   0x5ce430
0x5ceaf9  57                                push   edi
0x5ceafa  e8f1fbffff                        call   0x5ce6f0
0x5ceaff  8b8748030000                      mov    eax,DWORD PTR [edi+0x348]
0x5ceb05  bb01000000                        mov    ebx,0x1
0x5ceb0a  8998dc000000                      mov    DWORD PTR [eax+0xdc],ebx
0x5ceb10  8b8748030000                      mov    eax,DWORD PTR [edi+0x348]
0x5ceb16  50                                push   eax
0x5ceb17  e844c70b00                        call   0x68b260
0x5ceb1c  841d00b1fa00                      test   BYTE PTR ds:0xfab100,bl
0x5ceb22  7528                              jne    0x5ceb4c
0x5ceb24  091d00b1fa00                      or     DWORD PTR ds:0xfab100,ebx
0x5ceb2a  c744242000000000                  mov    DWORD PTR [esp+0x20],0x0
0x5ceb32  e869ebecff                        call   0x49d6a0
0x5ceb37  6820cebc00                        push   0xbcce20
0x5ceb3c  e8d9372c00                        call   0x89231a
0x5ceb41  83c404                            add    esp,0x4
0x5ceb44  c7442420ffffffff                  mov    DWORD PTR [esp+0x20],0xffffffff
0x5ceb4c  f60504b1fa0020                    test   BYTE PTR ds:0xfab104,0x20
0x5ceb53  7406                              je     0x5ceb5b
0x5ceb55  885c2410                          mov    BYTE PTR [esp+0x10],bl
0x5ceb59  eb0e                              jmp    0x5ceb69
0x5ceb5b  803d28b1fa0000                    cmp    BYTE PTR ds:0xfab128,0x0
0x5ceb62  0f95c1                            setne  cl
0x5ceb65  884c2410                          mov    BYTE PTR [esp+0x10],cl
0x5ceb69  8b8f04010000                      mov    ecx,DWORD PTR [edi+0x104]
0x5ceb6f  8b11                              mov    edx,DWORD PTR [ecx]
0x5ceb71  8b442410                          mov    eax,DWORD PTR [esp+0x10]
0x5ceb75  8b9290000000                      mov    edx,DWORD PTR [edx+0x90]
0x5ceb7b  50                                push   eax
0x5ceb7c  ffd2                              call   edx
0x5ceb7e  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x5ceb82  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5ceb89  59                                pop    ecx
0x5ceb8a  5f                                pop    edi
0x5ceb8b  5b                                pop    ebx
0x5ceb8c  8be5                              mov    esp,ebp
0x5ceb8e  5d                                pop    ebp
0x5ceb8f  c3                                ret

### B08 Mission native leader status ratios and UI consumer
VA 0x5d1bf0 RAW 0x1d0ff0 END 0x5d2120 SHA256 827ab1d0d1bb53aacf95a9fc35e9bf1da704041534ff055a5db92d16cfceb581
0x5d1bf0  55                                push   ebp
0x5d1bf1  8bec                              mov    ebp,esp
0x5d1bf3  83e4f8                            and    esp,0xfffffff8
0x5d1bf6  6aff                              push   0xffffffff
0x5d1bf8  68f6379400                        push   0x9437f6
0x5d1bfd  64a100000000                      mov    eax,fs:0x0
0x5d1c03  50                                push   eax
0x5d1c04  83ec2c                            sub    esp,0x2c
0x5d1c07  a1201fd600                        mov    eax,ds:0xd61f20
0x5d1c0c  33c4                              xor    eax,esp
0x5d1c0e  89442424                          mov    DWORD PTR [esp+0x24],eax
0x5d1c12  53                                push   ebx
0x5d1c13  56                                push   esi
0x5d1c14  a1201fd600                        mov    eax,ds:0xd61f20
0x5d1c19  33c4                              xor    eax,esp
0x5d1c1b  50                                push   eax
0x5d1c1c  8d442438                          lea    eax,[esp+0x38]
0x5d1c20  64a300000000                      mov    fs:0x0,eax
0x5d1c26  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x5d1c2d  7529                              jne    0x5d1c58
0x5d1c2f  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
0x5d1c36  c744244000000000                  mov    DWORD PTR [esp+0x40],0x0
0x5d1c3e  e84dd0f0ff                        call   0x4dec90
0x5d1c43  6830cebc00                        push   0xbcce30
0x5d1c48  e8cd062c00                        call   0x89231a
0x5d1c4d  83c404                            add    esp,0x4
0x5d1c50  c7442440ffffffff                  mov    DWORD PTR [esp+0x40],0xffffffff
0x5d1c58  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x5d1c5e  85c9                              test   ecx,ecx
0x5d1c60  0f849d040000                      je     0x5d2103
0x5d1c66  8b01                              mov    eax,DWORD PTR [ecx]
0x5d1c68  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0x5d1c6b  ffd2                              call   edx
0x5d1c6d  8bd8                              mov    ebx,eax
0x5d1c6f  85db                              test   ebx,ebx
0x5d1c71  0f848c040000                      je     0x5d2103
0x5d1c77  8b8358010000                      mov    eax,DWORD PTR [ebx+0x158]
0x5d1c7d  85c0                              test   eax,eax
0x5d1c7f  740a                              je     0x5d1c8b
0x5d1c81  83783400                          cmp    DWORD PTR [eax+0x34],0x0
0x5d1c85  0f8450010000                      je     0x5d1ddb
0x5d1c8b  80bf8000000000                    cmp    BYTE PTR [edi+0x80],0x0
0x5d1c92  0f8575030000                      jne    0x5d200d
0x5d1c98  8b83bc030000                      mov    eax,DWORD PTR [ebx+0x3bc]
0x5d1c9e  83ec1c                            sub    esp,0x1c
0x5d1ca1  8bf4                              mov    esi,esp
0x5d1ca3  89642428                          mov    DWORD PTR [esp+0x28],esp
0x5d1ca7  68f82bbf00                        push   0xbf2bf8
0x5d1cac  33c9                              xor    ecx,ecx
0x5d1cae  e8adc7e3ff                        call   0x40e460
0x5d1cb3  8b87a4000000                      mov    eax,DWORD PTR [edi+0xa4]
0x5d1cb9  83c404                            add    esp,0x4
0x5d1cbc  50                                push   eax
0x5d1cbd  e82ed3e3ff                        call   0x40eff0
0x5d1cc2  8b8fa4000000                      mov    ecx,DWORD PTR [edi+0xa4]
0x5d1cc8  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1cca  0f57c0                            xorps  xmm0,xmm0
0x5d1ccd  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d1cd3  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d1cdb  ffd0                              call   eax
0x5d1cdd  8b8fa4000000                      mov    ecx,DWORD PTR [edi+0xa4]
0x5d1ce3  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1ce5  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d1ceb  ffd0                              call   eax
0x5d1ced  8b83c0030000                      mov    eax,DWORD PTR [ebx+0x3c0]
0x5d1cf3  83ec1c                            sub    esp,0x1c
0x5d1cf6  8bf4                              mov    esi,esp
0x5d1cf8  89642428                          mov    DWORD PTR [esp+0x28],esp
0x5d1cfc  68f82bbf00                        push   0xbf2bf8
0x5d1d01  33c9                              xor    ecx,ecx
0x5d1d03  e858c7e3ff                        call   0x40e460
0x5d1d08  8b8fa8000000                      mov    ecx,DWORD PTR [edi+0xa8]
0x5d1d0e  83c404                            add    esp,0x4
0x5d1d11  51                                push   ecx
0x5d1d12  e8d9d2e3ff                        call   0x40eff0
0x5d1d17  8b8fa8000000                      mov    ecx,DWORD PTR [edi+0xa8]
0x5d1d1d  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1d1f  0f57c0                            xorps  xmm0,xmm0
0x5d1d22  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d1d28  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d1d30  ffd0                              call   eax
0x5d1d32  8b8fa8000000                      mov    ecx,DWORD PTR [edi+0xa8]
0x5d1d38  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1d3a  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d1d40  ffd0                              call   eax
0x5d1d42  8b83c4030000                      mov    eax,DWORD PTR [ebx+0x3c4]
0x5d1d48  83ec1c                            sub    esp,0x1c
0x5d1d4b  8bf4                              mov    esi,esp
0x5d1d4d  89642428                          mov    DWORD PTR [esp+0x28],esp
0x5d1d51  68f82bbf00                        push   0xbf2bf8
0x5d1d56  33c9                              xor    ecx,ecx
0x5d1d58  e803c7e3ff                        call   0x40e460
0x5d1d5d  8b8fac000000                      mov    ecx,DWORD PTR [edi+0xac]
0x5d1d63  83c404                            add    esp,0x4
0x5d1d66  51                                push   ecx
0x5d1d67  e884d2e3ff                        call   0x40eff0
0x5d1d6c  8b8fac000000                      mov    ecx,DWORD PTR [edi+0xac]
0x5d1d72  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1d74  0f57c0                            xorps  xmm0,xmm0
0x5d1d77  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d1d7d  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d1d85  ffd0                              call   eax
0x5d1d87  8b8fac000000                      mov    ecx,DWORD PTR [edi+0xac]
0x5d1d8d  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1d8f  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d1d95  ffd0                              call   eax
0x5d1d97  33c0                              xor    eax,eax
0x5d1d99  c6878000000001                    mov    BYTE PTR [edi+0x80],0x1
0x5d1da0  89878c000000                      mov    DWORD PTR [edi+0x8c],eax
0x5d1da6  898790000000                      mov    DWORD PTR [edi+0x90],eax
0x5d1dac  898794000000                      mov    DWORD PTR [edi+0x94],eax
0x5d1db2  8b83bc030000                      mov    eax,DWORD PTR [ebx+0x3bc]
0x5d1db8  898798000000                      mov    DWORD PTR [edi+0x98],eax
0x5d1dbe  8b83c0030000                      mov    eax,DWORD PTR [ebx+0x3c0]
0x5d1dc4  89879c000000                      mov    DWORD PTR [edi+0x9c],eax
0x5d1dca  8b83c4030000                      mov    eax,DWORD PTR [ebx+0x3c4]
0x5d1dd0  8987a0000000                      mov    DWORD PTR [edi+0xa0],eax
0x5d1dd6  e932020000                        jmp    0x5d200d
0x5d1ddb  8b8bc8030000                      mov    ecx,DWORD PTR [ebx+0x3c8]
0x5d1de1  398f8c000000                      cmp    DWORD PTR [edi+0x8c],ecx
0x5d1de7  7512                              jne    0x5d1dfb
0x5d1de9  8b83bc030000                      mov    eax,DWORD PTR [ebx+0x3bc]
0x5d1def  398798000000                      cmp    DWORD PTR [edi+0x98],eax
0x5d1df5  0f8499000000                      je     0x5d1e94
0x5d1dfb  8b83bc030000                      mov    eax,DWORD PTR [ebx+0x3bc]
0x5d1e01  85c0                              test   eax,eax
0x5d1e03  7e1e                              jle    0x5d1e23
0x5d1e05  894c2410                          mov    DWORD PTR [esp+0x10],ecx
0x5d1e09  db442410                          fild   DWORD PTR [esp+0x10]
0x5d1e0d  8944240c                          mov    DWORD PTR [esp+0xc],eax
0x5d1e11  8b8fa4000000                      mov    ecx,DWORD PTR [edi+0xa4]
0x5d1e17  da74240c                          fidiv  DWORD PTR [esp+0xc]
0x5d1e1b  d999d0000000                      fstp   DWORD PTR [ecx+0xd0]
0x5d1e21  eb11                              jmp    0x5d1e34
0x5d1e23  8b8fa4000000                      mov    ecx,DWORD PTR [edi+0xa4]
0x5d1e29  0f57c0                            xorps  xmm0,xmm0
0x5d1e2c  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d1e34  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1e36  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d1e3c  ffd0                              call   eax
0x5d1e3e  8b83bc030000                      mov    eax,DWORD PTR [ebx+0x3bc]
0x5d1e44  8b8bc8030000                      mov    ecx,DWORD PTR [ebx+0x3c8]
0x5d1e4a  83ec1c                            sub    esp,0x1c
0x5d1e4d  8bf4                              mov    esi,esp
0x5d1e4f  89642428                          mov    DWORD PTR [esp+0x28],esp
0x5d1e53  68f82bbf00                        push   0xbf2bf8
0x5d1e58  e803c6e3ff                        call   0x40e460
0x5d1e5d  8b8fa4000000                      mov    ecx,DWORD PTR [edi+0xa4]
0x5d1e63  83c404                            add    esp,0x4
0x5d1e66  51                                push   ecx
0x5d1e67  e884d1e3ff                        call   0x40eff0
0x5d1e6c  8b8fa4000000                      mov    ecx,DWORD PTR [edi+0xa4]
0x5d1e72  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1e74  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d1e7a  ffd0                              call   eax
0x5d1e7c  8b8bc8030000                      mov    ecx,DWORD PTR [ebx+0x3c8]
0x5d1e82  898f8c000000                      mov    DWORD PTR [edi+0x8c],ecx
0x5d1e88  8b83bc030000                      mov    eax,DWORD PTR [ebx+0x3bc]
0x5d1e8e  898798000000                      mov    DWORD PTR [edi+0x98],eax
0x5d1e94  8b8bcc030000                      mov    ecx,DWORD PTR [ebx+0x3cc]
0x5d1e9a  398f90000000                      cmp    DWORD PTR [edi+0x90],ecx
0x5d1ea0  7512                              jne    0x5d1eb4
0x5d1ea2  8b83c0030000                      mov    eax,DWORD PTR [ebx+0x3c0]
0x5d1ea8  39879c000000                      cmp    DWORD PTR [edi+0x9c],eax
0x5d1eae  0f8499000000                      je     0x5d1f4d
0x5d1eb4  8b83c0030000                      mov    eax,DWORD PTR [ebx+0x3c0]
0x5d1eba  85c0                              test   eax,eax
0x5d1ebc  7e1e                              jle    0x5d1edc
0x5d1ebe  894c240c                          mov    DWORD PTR [esp+0xc],ecx
0x5d1ec2  db44240c                          fild   DWORD PTR [esp+0xc]
0x5d1ec6  89442410                          mov    DWORD PTR [esp+0x10],eax
0x5d1eca  8b8fa8000000                      mov    ecx,DWORD PTR [edi+0xa8]
0x5d1ed0  da742410                          fidiv  DWORD PTR [esp+0x10]
0x5d1ed4  d999d0000000                      fstp   DWORD PTR [ecx+0xd0]
0x5d1eda  eb11                              jmp    0x5d1eed
0x5d1edc  8b8fa8000000                      mov    ecx,DWORD PTR [edi+0xa8]
0x5d1ee2  0f57c0                            xorps  xmm0,xmm0
0x5d1ee5  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d1eed  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1eef  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d1ef5  ffd0                              call   eax
0x5d1ef7  8b83c0030000                      mov    eax,DWORD PTR [ebx+0x3c0]
0x5d1efd  8b8bcc030000                      mov    ecx,DWORD PTR [ebx+0x3cc]
0x5d1f03  83ec1c                            sub    esp,0x1c
0x5d1f06  8bf4                              mov    esi,esp
0x5d1f08  89642428                          mov    DWORD PTR [esp+0x28],esp
0x5d1f0c  68f82bbf00                        push   0xbf2bf8
0x5d1f11  e84ac5e3ff                        call   0x40e460
0x5d1f16  8b8fa8000000                      mov    ecx,DWORD PTR [edi+0xa8]
0x5d1f1c  83c404                            add    esp,0x4
0x5d1f1f  51                                push   ecx
0x5d1f20  e8cbd0e3ff                        call   0x40eff0
0x5d1f25  8b8fa8000000                      mov    ecx,DWORD PTR [edi+0xa8]
0x5d1f2b  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1f2d  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d1f33  ffd0                              call   eax
0x5d1f35  8b8bcc030000                      mov    ecx,DWORD PTR [ebx+0x3cc]
0x5d1f3b  898f90000000                      mov    DWORD PTR [edi+0x90],ecx
0x5d1f41  8b83c0030000                      mov    eax,DWORD PTR [ebx+0x3c0]
0x5d1f47  89879c000000                      mov    DWORD PTR [edi+0x9c],eax
0x5d1f4d  8b8bd0030000                      mov    ecx,DWORD PTR [ebx+0x3d0]
0x5d1f53  398f94000000                      cmp    DWORD PTR [edi+0x94],ecx
0x5d1f59  7512                              jne    0x5d1f6d
0x5d1f5b  8b83c4030000                      mov    eax,DWORD PTR [ebx+0x3c4]
0x5d1f61  3987a0000000                      cmp    DWORD PTR [edi+0xa0],eax
0x5d1f67  0f8499000000                      je     0x5d2006
0x5d1f6d  8b83c4030000                      mov    eax,DWORD PTR [ebx+0x3c4]
0x5d1f73  85c0                              test   eax,eax
0x5d1f75  7e1e                              jle    0x5d1f95
0x5d1f77  894c240c                          mov    DWORD PTR [esp+0xc],ecx
0x5d1f7b  db44240c                          fild   DWORD PTR [esp+0xc]
0x5d1f7f  89442410                          mov    DWORD PTR [esp+0x10],eax
0x5d1f83  8b8fac000000                      mov    ecx,DWORD PTR [edi+0xac]
0x5d1f89  da742410                          fidiv  DWORD PTR [esp+0x10]
0x5d1f8d  d999d0000000                      fstp   DWORD PTR [ecx+0xd0]
0x5d1f93  eb11                              jmp    0x5d1fa6
0x5d1f95  8b8fac000000                      mov    ecx,DWORD PTR [edi+0xac]
0x5d1f9b  0f57c0                            xorps  xmm0,xmm0
0x5d1f9e  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d1fa6  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1fa8  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d1fae  ffd0                              call   eax
0x5d1fb0  8b83c4030000                      mov    eax,DWORD PTR [ebx+0x3c4]
0x5d1fb6  8b8bd0030000                      mov    ecx,DWORD PTR [ebx+0x3d0]
0x5d1fbc  83ec1c                            sub    esp,0x1c
0x5d1fbf  8bf4                              mov    esi,esp
0x5d1fc1  89642428                          mov    DWORD PTR [esp+0x28],esp
0x5d1fc5  68f82bbf00                        push   0xbf2bf8
0x5d1fca  e891c4e3ff                        call   0x40e460
0x5d1fcf  8b8fac000000                      mov    ecx,DWORD PTR [edi+0xac]
0x5d1fd5  83c404                            add    esp,0x4
0x5d1fd8  51                                push   ecx
0x5d1fd9  e812d0e3ff                        call   0x40eff0
0x5d1fde  8b8fac000000                      mov    ecx,DWORD PTR [edi+0xac]
0x5d1fe4  8b11                              mov    edx,DWORD PTR [ecx]
0x5d1fe6  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d1fec  ffd0                              call   eax
0x5d1fee  8b8bd0030000                      mov    ecx,DWORD PTR [ebx+0x3d0]
0x5d1ff4  898f94000000                      mov    DWORD PTR [edi+0x94],ecx
0x5d1ffa  8b83c4030000                      mov    eax,DWORD PTR [ebx+0x3c4]
0x5d2000  8987a0000000                      mov    DWORD PTR [edi+0xa0],eax
0x5d2006  c6878000000000                    mov    BYTE PTR [edi+0x80],0x0
0x5d200d  0fb7b388000000                    movzx  esi,WORD PTR [ebx+0x88]
0x5d2014  8974240c                          mov    DWORD PTR [esp+0xc],esi
0x5d2018  39b784000000                      cmp    DWORD PTR [edi+0x84],esi
0x5d201e  742e                              je     0x5d204e
0x5d2020  e84b14e3ff                        call   0x403470
0x5d2025  8b74b058                          mov    esi,DWORD PTR [eax+esi*4+0x58]
0x5d2029  8b87b8000000                      mov    eax,DWORD PTR [edi+0xb8]
0x5d202f  e8cc301700                        call   0x745100
0x5d2034  8b8fb8000000                      mov    ecx,DWORD PTR [edi+0xb8]
0x5d203a  8b11                              mov    edx,DWORD PTR [ecx]
0x5d203c  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d2042  ffd0                              call   eax
0x5d2044  8b4c240c                          mov    ecx,DWORD PTR [esp+0xc]
0x5d2048  898f84000000                      mov    DWORD PTR [edi+0x84],ecx
0x5d204e  8b9bd4030000                      mov    ebx,DWORD PTR [ebx+0x3d4]
0x5d2054  399f88000000                      cmp    DWORD PTR [edi+0x88],ebx
0x5d205a  746e                              je     0x5d20ca
0x5d205c  8bcb                              mov    ecx,ebx
0x5d205e  8d742414                          lea    esi,[esp+0x14]
0x5d2062  e819cfe3ff                        call   0x40ef80
0x5d2067  c744244001000000                  mov    DWORD PTR [esp+0x40],0x1
0x5d206f  8bb7b0000000                      mov    esi,DWORD PTR [edi+0xb0]
0x5d2075  50                                push   eax
0x5d2076  8db6e8000000                      lea    esi,[esi+0xe8]
0x5d207c  e87f571800                        call   0x757800
0x5d2081  c7442440ffffffff                  mov    DWORD PTR [esp+0x40],0xffffffff
0x5d2089  837c242808                        cmp    DWORD PTR [esp+0x28],0x8
0x5d208e  720d                              jb     0x5d209d
0x5d2090  8b542414                          mov    edx,DWORD PTR [esp+0x14]
0x5d2094  52                                push   edx
0x5d2095  e872f12b00                        call   0x89120c
0x5d209a  83c404                            add    esp,0x4
0x5d209d  8b8fb0000000                      mov    ecx,DWORD PTR [edi+0xb0]
0x5d20a3  8b11                              mov    edx,DWORD PTR [ecx]
0x5d20a5  33c0                              xor    eax,eax
0x5d20a7  6689442414                        mov    WORD PTR [esp+0x14],ax
0x5d20ac  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d20b2  c744242807000000                  mov    DWORD PTR [esp+0x28],0x7
0x5d20ba  c744242400000000                  mov    DWORD PTR [esp+0x24],0x0
0x5d20c2  ffd0                              call   eax
0x5d20c4  899f88000000                      mov    DWORD PTR [edi+0x88],ebx
0x5d20ca  e891cfe3ff                        call   0x40f060
0x5d20cf  8b80f8000000                      mov    eax,DWORD PTR [eax+0xf8]
0x5d20d5  85c0                              test   eax,eax
0x5d20d7  740a                              je     0x5d20e3
0x5d20d9  80782800                          cmp    BYTE PTR [eax+0x28],0x0
0x5d20dd  7404                              je     0x5d20e3
0x5d20df  b001                              mov    al,0x1
0x5d20e1  eb02                              jmp    0x5d20e5
0x5d20e3  32c0                              xor    al,al
0x5d20e5  8b8fb4000000                      mov    ecx,DWORD PTR [edi+0xb4]
0x5d20eb  8b11                              mov    edx,DWORD PTR [ecx]
0x5d20ed  50                                push   eax
0x5d20ee  8b8294000000                      mov    eax,DWORD PTR [edx+0x94]
0x5d20f4  ffd0                              call   eax
0x5d20f6  57                                push   edi
0x5d20f7  e8d4f9ffff                        call   0x5d1ad0
0x5d20fc  8bf7                              mov    esi,edi
0x5d20fe  e80d010000                        call   0x5d2210
0x5d2103  8b4c2438                          mov    ecx,DWORD PTR [esp+0x38]
0x5d2107  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5d210e  59                                pop    ecx
0x5d210f  5e                                pop    esi
0x5d2110  5b                                pop    ebx
0x5d2111  8b4c2424                          mov    ecx,DWORD PTR [esp+0x24]
0x5d2115  33cc                              xor    ecx,esp
0x5d2117  e8e5ee2b00                        call   0x891001
0x5d211c  8be5                              mov    esp,ebp
0x5d211e  5d                                pop    ebp
0x5d211f  c3                                ret

### B09 Scenario native leader status ratios and UI consumer
VA 0x5d3700 RAW 0x1d2b00 END 0x5d3bce SHA256 df6841b380a3c7bcfa9e487a8e609f606ddf49bcc0cc812d087176fb195d6cc9
0x5d3700  55                                push   ebp
0x5d3701  8bec                              mov    ebp,esp
0x5d3703  83e4f8                            and    esp,0xfffffff8
0x5d3706  6aff                              push   0xffffffff
0x5d3708  6852379400                        push   0x943752
0x5d370d  64a100000000                      mov    eax,fs:0x0
0x5d3713  50                                push   eax
0x5d3714  83ec30                            sub    esp,0x30
0x5d3717  a1201fd600                        mov    eax,ds:0xd61f20
0x5d371c  33c4                              xor    eax,esp
0x5d371e  89442428                          mov    DWORD PTR [esp+0x28],eax
0x5d3722  53                                push   ebx
0x5d3723  56                                push   esi
0x5d3724  57                                push   edi
0x5d3725  a1201fd600                        mov    eax,ds:0xd61f20
0x5d372a  33c4                              xor    eax,esp
0x5d372c  50                                push   eax
0x5d372d  8d442440                          lea    eax,[esp+0x40]
0x5d3731  64a300000000                      mov    fs:0x0,eax
0x5d3737  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x5d373e  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x5d3741  7529                              jne    0x5d376c
0x5d3743  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
0x5d374a  c744244800000000                  mov    DWORD PTR [esp+0x48],0x0
0x5d3752  e839b5f0ff                        call   0x4dec90
0x5d3757  6830cebc00                        push   0xbcce30
0x5d375c  e8b9eb2b00                        call   0x89231a
0x5d3761  83c404                            add    esp,0x4
0x5d3764  c7442448ffffffff                  mov    DWORD PTR [esp+0x48],0xffffffff
0x5d376c  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x5d3772  85c9                              test   ecx,ecx
0x5d3774  0f8434040000                      je     0x5d3bae
0x5d377a  8b01                              mov    eax,DWORD PTR [ecx]
0x5d377c  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0x5d377f  ffd2                              call   edx
0x5d3781  8bf8                              mov    edi,eax
0x5d3783  897c2418                          mov    DWORD PTR [esp+0x18],edi
0x5d3787  85ff                              test   edi,edi
0x5d3789  0f841f040000                      je     0x5d3bae
0x5d378f  8b8758010000                      mov    eax,DWORD PTR [edi+0x158]
0x5d3795  85c0                              test   eax,eax
0x5d3797  740a                              je     0x5d37a3
0x5d3799  83783400                          cmp    DWORD PTR [eax+0x34],0x0
0x5d379d  0f8402010000                      je     0x5d38a5
0x5d37a3  8b8b80000000                      mov    ecx,DWORD PTR [ebx+0x80]
0x5d37a9  8b01                              mov    eax,DWORD PTR [ecx]
0x5d37ab  0f57c0                            xorps  xmm0,xmm0
0x5d37ae  8b9028010000                      mov    edx,DWORD PTR [eax+0x128]
0x5d37b4  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d37bc  ffd2                              call   edx
0x5d37be  8b87bc030000                      mov    eax,DWORD PTR [edi+0x3bc]
0x5d37c4  83ec1c                            sub    esp,0x1c
0x5d37c7  8bf4                              mov    esi,esp
0x5d37c9  8964242c                          mov    DWORD PTR [esp+0x2c],esp
0x5d37cd  68f82bbf00                        push   0xbf2bf8
0x5d37d2  33c9                              xor    ecx,ecx
0x5d37d4  e887ace3ff                        call   0x40e460
0x5d37d9  8b8380000000                      mov    eax,DWORD PTR [ebx+0x80]
0x5d37df  83c404                            add    esp,0x4
0x5d37e2  50                                push   eax
0x5d37e3  e808b8e3ff                        call   0x40eff0
0x5d37e8  8b8b80000000                      mov    ecx,DWORD PTR [ebx+0x80]
0x5d37ee  8b11                              mov    edx,DWORD PTR [ecx]
0x5d37f0  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d37f6  ffd0                              call   eax
0x5d37f8  8b8b84000000                      mov    ecx,DWORD PTR [ebx+0x84]
0x5d37fe  8b11                              mov    edx,DWORD PTR [ecx]
0x5d3800  0f57c0                            xorps  xmm0,xmm0
0x5d3803  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d3809  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d3811  ffd0                              call   eax
0x5d3813  8b87c0030000                      mov    eax,DWORD PTR [edi+0x3c0]
0x5d3819  83ec1c                            sub    esp,0x1c
0x5d381c  8bf4                              mov    esi,esp
0x5d381e  8964242c                          mov    DWORD PTR [esp+0x2c],esp
0x5d3822  68f82bbf00                        push   0xbf2bf8
0x5d3827  33c9                              xor    ecx,ecx
0x5d3829  e832ace3ff                        call   0x40e460
0x5d382e  8b8b84000000                      mov    ecx,DWORD PTR [ebx+0x84]
0x5d3834  83c404                            add    esp,0x4
0x5d3837  51                                push   ecx
0x5d3838  e8b3b7e3ff                        call   0x40eff0
0x5d383d  8b8b84000000                      mov    ecx,DWORD PTR [ebx+0x84]
0x5d3843  8b11                              mov    edx,DWORD PTR [ecx]
0x5d3845  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d384b  ffd0                              call   eax
0x5d384d  8b8b88000000                      mov    ecx,DWORD PTR [ebx+0x88]
0x5d3853  8b11                              mov    edx,DWORD PTR [ecx]
0x5d3855  0f57c0                            xorps  xmm0,xmm0
0x5d3858  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d385e  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d3866  ffd0                              call   eax
0x5d3868  8b87c4030000                      mov    eax,DWORD PTR [edi+0x3c4]
0x5d386e  83ec1c                            sub    esp,0x1c
0x5d3871  8bf4                              mov    esi,esp
0x5d3873  8964242c                          mov    DWORD PTR [esp+0x2c],esp
0x5d3877  68f82bbf00                        push   0xbf2bf8
0x5d387c  33c9                              xor    ecx,ecx
0x5d387e  e8ddabe3ff                        call   0x40e460
0x5d3883  8b8b88000000                      mov    ecx,DWORD PTR [ebx+0x88]
0x5d3889  83c404                            add    esp,0x4
0x5d388c  51                                push   ecx
0x5d388d  e85eb7e3ff                        call   0x40eff0
0x5d3892  8b8b88000000                      mov    ecx,DWORD PTR [ebx+0x88]
0x5d3898  8b11                              mov    edx,DWORD PTR [ecx]
0x5d389a  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d38a0  e993010000                        jmp    0x5d3a38
0x5d38a5  8b87bc030000                      mov    eax,DWORD PTR [edi+0x3bc]
0x5d38ab  8b8fc8030000                      mov    ecx,DWORD PTR [edi+0x3c8]
0x5d38b1  83ec1c                            sub    esp,0x1c
0x5d38b4  8bf4                              mov    esi,esp
0x5d38b6  8964242c                          mov    DWORD PTR [esp+0x2c],esp
0x5d38ba  68f82bbf00                        push   0xbf2bf8
0x5d38bf  e89cabe3ff                        call   0x40e460
0x5d38c4  8b8b80000000                      mov    ecx,DWORD PTR [ebx+0x80]
0x5d38ca  83c404                            add    esp,0x4
0x5d38cd  51                                push   ecx
0x5d38ce  e81db7e3ff                        call   0x40eff0
0x5d38d3  8b8b80000000                      mov    ecx,DWORD PTR [ebx+0x80]
0x5d38d9  8b11                              mov    edx,DWORD PTR [ecx]
0x5d38db  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d38e1  ffd0                              call   eax
0x5d38e3  8b87bc030000                      mov    eax,DWORD PTR [edi+0x3bc]
0x5d38e9  85c0                              test   eax,eax
0x5d38eb  7e24                              jle    0x5d3911
0x5d38ed  8b8fc8030000                      mov    ecx,DWORD PTR [edi+0x3c8]
0x5d38f3  894c2414                          mov    DWORD PTR [esp+0x14],ecx
0x5d38f7  db442414                          fild   DWORD PTR [esp+0x14]
0x5d38fb  89442410                          mov    DWORD PTR [esp+0x10],eax
0x5d38ff  8b8b80000000                      mov    ecx,DWORD PTR [ebx+0x80]
0x5d3905  da742410                          fidiv  DWORD PTR [esp+0x10]
0x5d3909  d999d0000000                      fstp   DWORD PTR [ecx+0xd0]
0x5d390f  eb11                              jmp    0x5d3922
0x5d3911  8b8b80000000                      mov    ecx,DWORD PTR [ebx+0x80]
0x5d3917  0f57c0                            xorps  xmm0,xmm0
0x5d391a  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d3922  8b11                              mov    edx,DWORD PTR [ecx]
0x5d3924  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d392a  ffd0                              call   eax
0x5d392c  8b87c0030000                      mov    eax,DWORD PTR [edi+0x3c0]
0x5d3932  8b8fcc030000                      mov    ecx,DWORD PTR [edi+0x3cc]
0x5d3938  83ec1c                            sub    esp,0x1c
0x5d393b  8bf4                              mov    esi,esp
0x5d393d  8964242c                          mov    DWORD PTR [esp+0x2c],esp
0x5d3941  68f82bbf00                        push   0xbf2bf8
0x5d3946  e815abe3ff                        call   0x40e460
0x5d394b  8b8b84000000                      mov    ecx,DWORD PTR [ebx+0x84]
0x5d3951  83c404                            add    esp,0x4
0x5d3954  51                                push   ecx
0x5d3955  e896b6e3ff                        call   0x40eff0
0x5d395a  8b8b84000000                      mov    ecx,DWORD PTR [ebx+0x84]
0x5d3960  8b11                              mov    edx,DWORD PTR [ecx]
0x5d3962  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d3968  ffd0                              call   eax
0x5d396a  8b87c0030000                      mov    eax,DWORD PTR [edi+0x3c0]
0x5d3970  85c0                              test   eax,eax
0x5d3972  7e24                              jle    0x5d3998
0x5d3974  8b8fcc030000                      mov    ecx,DWORD PTR [edi+0x3cc]
0x5d397a  894c2410                          mov    DWORD PTR [esp+0x10],ecx
0x5d397e  db442410                          fild   DWORD PTR [esp+0x10]
0x5d3982  89442414                          mov    DWORD PTR [esp+0x14],eax
0x5d3986  8b8b84000000                      mov    ecx,DWORD PTR [ebx+0x84]
0x5d398c  da742414                          fidiv  DWORD PTR [esp+0x14]
0x5d3990  d999d0000000                      fstp   DWORD PTR [ecx+0xd0]
0x5d3996  eb11                              jmp    0x5d39a9
0x5d3998  8b8b84000000                      mov    ecx,DWORD PTR [ebx+0x84]
0x5d399e  0f57c0                            xorps  xmm0,xmm0
0x5d39a1  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d39a9  8b11                              mov    edx,DWORD PTR [ecx]
0x5d39ab  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d39b1  ffd0                              call   eax
0x5d39b3  8b87c4030000                      mov    eax,DWORD PTR [edi+0x3c4]
0x5d39b9  8b8fd0030000                      mov    ecx,DWORD PTR [edi+0x3d0]
0x5d39bf  83ec1c                            sub    esp,0x1c
0x5d39c2  8bf4                              mov    esi,esp
0x5d39c4  8964242c                          mov    DWORD PTR [esp+0x2c],esp
0x5d39c8  68f82bbf00                        push   0xbf2bf8
0x5d39cd  e88eaae3ff                        call   0x40e460
0x5d39d2  8b8b88000000                      mov    ecx,DWORD PTR [ebx+0x88]
0x5d39d8  83c404                            add    esp,0x4
0x5d39db  51                                push   ecx
0x5d39dc  e80fb6e3ff                        call   0x40eff0
0x5d39e1  8b8b88000000                      mov    ecx,DWORD PTR [ebx+0x88]
0x5d39e7  8b11                              mov    edx,DWORD PTR [ecx]
0x5d39e9  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d39ef  ffd0                              call   eax
0x5d39f1  8b87c4030000                      mov    eax,DWORD PTR [edi+0x3c4]
0x5d39f7  85c0                              test   eax,eax
0x5d39f9  7e24                              jle    0x5d3a1f
0x5d39fb  8b8fd0030000                      mov    ecx,DWORD PTR [edi+0x3d0]
0x5d3a01  894c2410                          mov    DWORD PTR [esp+0x10],ecx
0x5d3a05  db442410                          fild   DWORD PTR [esp+0x10]
0x5d3a09  89442414                          mov    DWORD PTR [esp+0x14],eax
0x5d3a0d  8b8b88000000                      mov    ecx,DWORD PTR [ebx+0x88]
0x5d3a13  da742414                          fidiv  DWORD PTR [esp+0x14]
0x5d3a17  d999d0000000                      fstp   DWORD PTR [ecx+0xd0]
0x5d3a1d  eb11                              jmp    0x5d3a30
0x5d3a1f  8b8b88000000                      mov    ecx,DWORD PTR [ebx+0x88]
0x5d3a25  0f57c0                            xorps  xmm0,xmm0
0x5d3a28  f30f1181d0000000                  movss  DWORD PTR [ecx+0xd0],xmm0
0x5d3a30  8b11                              mov    edx,DWORD PTR [ecx]
0x5d3a32  8b8228010000                      mov    eax,DWORD PTR [edx+0x128]
0x5d3a38  ffd0                              call   eax
0x5d3a3a  f6059443f90001                    test   BYTE PTR ds:0xf94394,0x1
0x5d3a41  0fb7b788000000                    movzx  esi,WORD PTR [edi+0x88]
0x5d3a48  7529                              jne    0x5d3a73
0x5d3a4a  b801000000                        mov    eax,0x1
0x5d3a4f  09059443f900                      or     DWORD PTR ds:0xf94394,eax
0x5d3a55  89442448                          mov    DWORD PTR [esp+0x48],eax
0x5d3a59  e88203ffff                        call   0x5c3de0
0x5d3a5e  6830ccbc00                        push   0xbccc30
0x5d3a63  e8b2e82b00                        call   0x89231a
0x5d3a68  83c404                            add    esp,0x4
0x5d3a6b  c7442448ffffffff                  mov    DWORD PTR [esp+0x48],0xffffffff
0x5d3a73  8b14b5f043f900                    mov    edx,DWORD PTR [esi*4+0xf943f0]
0x5d3a7a  8bb390000000                      mov    esi,DWORD PTR [ebx+0x90]
0x5d3a80  80bea400000000                    cmp    BYTE PTR [esi+0xa4],0x0
0x5d3a87  89542410                          mov    DWORD PTR [esp+0x10],edx
0x5d3a8b  7430                              je     0x5d3abd
0x5d3a8d  83be9400000000                    cmp    DWORD PTR [esi+0x94],0x0
0x5d3a94  7427                              je     0x5d3abd
0x5d3a96  8b8e94000000                      mov    ecx,DWORD PTR [esi+0x94]
0x5d3a9c  8b01                              mov    eax,DWORD PTR [ecx]
0x5d3a9e  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x5d3aa1  ffd2                              call   edx
0x5d3aa3  3d6bbf0000                        cmp    eax,0xbf6b
0x5d3aa8  7513                              jne    0x5d3abd
0x5d3aaa  8bbe94000000                      mov    edi,DWORD PTR [esi+0x94]
0x5d3ab0  8b742410                          mov    esi,DWORD PTR [esp+0x10]
0x5d3ab4  e847771a00                        call   0x77b200
0x5d3ab9  8b7c2418                          mov    edi,DWORD PTR [esp+0x18]
0x5d3abd  8b8b90000000                      mov    ecx,DWORD PTR [ebx+0x90]
0x5d3ac3  8b01                              mov    eax,DWORD PTR [ecx]
0x5d3ac5  8b90c8000000                      mov    edx,DWORD PTR [eax+0xc8]
0x5d3acb  ffd2                              call   edx
0x5d3acd  8b8fd4030000                      mov    ecx,DWORD PTR [edi+0x3d4]
0x5d3ad3  8d74241c                          lea    esi,[esp+0x1c]
0x5d3ad7  e8a4b4e3ff                        call   0x40ef80
0x5d3adc  bf02000000                        mov    edi,0x2
0x5d3ae1  897c2448                          mov    DWORD PTR [esp+0x48],edi
0x5d3ae5  8bb38c000000                      mov    esi,DWORD PTR [ebx+0x8c]
0x5d3aeb  50                                push   eax
0x5d3aec  8db6e8000000                      lea    esi,[esi+0xe8]
0x5d3af2  e8093d1800                        call   0x757800
0x5d3af7  c7442448ffffffff                  mov    DWORD PTR [esp+0x48],0xffffffff
0x5d3aff  837c243008                        cmp    DWORD PTR [esp+0x30],0x8
0x5d3b04  720d                              jb     0x5d3b13
0x5d3b06  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
0x5d3b0a  50                                push   eax
0x5d3b0b  e8fcd62b00                        call   0x89120c
0x5d3b10  83c404                            add    esp,0x4
0x5d3b13  33c9                              xor    ecx,ecx
0x5d3b15  66894c241c                        mov    WORD PTR [esp+0x1c],cx
0x5d3b1a  8b8b8c000000                      mov    ecx,DWORD PTR [ebx+0x8c]
0x5d3b20  8b11                              mov    edx,DWORD PTR [ecx]
0x5d3b22  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5d3b28  c744243007000000                  mov    DWORD PTR [esp+0x30],0x7
0x5d3b30  c744242c00000000                  mov    DWORD PTR [esp+0x2c],0x0
0x5d3b38  ffd0                              call   eax
0x5d3b3a  8db39c000000                      lea    esi,[ebx+0x9c]
0x5d3b40  897c2414                          mov    DWORD PTR [esp+0x14],edi
0x5d3b44  8b3e                              mov    edi,DWORD PTR [esi]
0x5d3b46  e8c5eaffff                        call   0x5d2610
0x5d3b4b  83c604                            add    esi,0x4
0x5d3b4e  ff4c2414                          dec    DWORD PTR [esp+0x14]
0x5d3b52  75f0                              jne    0x5d3b44
0x5d3b54  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
0x5d3b5b  7529                              jne    0x5d3b86
0x5d3b5d  830d9043f90001                    or     DWORD PTR ds:0xf94390,0x1
0x5d3b64  c744244803000000                  mov    DWORD PTR [esp+0x48],0x3
0x5d3b6c  e81fdaf0ff                        call   0x4e1590
0x5d3b71  6880ccbc00                        push   0xbccc80
0x5d3b76  e89fe72b00                        call   0x89231a
0x5d3b7b  83c404                            add    esp,0x4
0x5d3b7e  c7442448ffffffff                  mov    DWORD PTR [esp+0x48],0xffffffff
0x5d3b86  8b8398000000                      mov    eax,DWORD PTR [ebx+0x98]
0x5d3b8c  8b0d3039f900                      mov    ecx,DWORD PTR ds:0xf93930
0x5d3b92  8988e0000000                      mov    DWORD PTR [eax+0xe0],ecx
0x5d3b98  c780dc00000002000000              mov    DWORD PTR [eax+0xdc],0x2
0x5d3ba2  8b9398000000                      mov    edx,DWORD PTR [ebx+0x98]
0x5d3ba8  52                                push   edx
0x5d3ba9  e8b2760b00                        call   0x68b260
0x5d3bae  8b4c2440                          mov    ecx,DWORD PTR [esp+0x40]
0x5d3bb2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5d3bb9  59                                pop    ecx
0x5d3bba  5f                                pop    edi
0x5d3bbb  5e                                pop    esi
0x5d3bbc  5b                                pop    ebx
0x5d3bbd  8b4c2428                          mov    ecx,DWORD PTR [esp+0x28]
0x5d3bc1  33cc                              xor    ecx,esp
0x5d3bc3  e839d42b00                        call   0x891001
0x5d3bc8  8be5                              mov    esp,ebp
0x5d3bca  5d                                pop    ebp
0x5d3bcb  c20400                            ret    0x4

### B10 Mission bottom onload binds distinct +380 part
VA 0x5d47b0 RAW 0x1d3bb0 END 0x5d48ab SHA256 b0272f9cc3a23590faab7e8cd3ecbf68431eefb6b9d4c986aa3c9d28ad6855a3
0x5d47b0  55                                push   ebp
0x5d47b1  8bec                              mov    ebp,esp
0x5d47b3  6aff                              push   0xffffffff
0x5d47b5  6830a99100                        push   0x91a930
0x5d47ba  64a100000000                      mov    eax,fs:0x0
0x5d47c0  50                                push   eax
0x5d47c1  83ec2c                            sub    esp,0x2c
0x5d47c4  53                                push   ebx
0x5d47c5  56                                push   esi
0x5d47c6  57                                push   edi
0x5d47c7  a1201fd600                        mov    eax,ds:0xd61f20
0x5d47cc  33c5                              xor    eax,ebp
0x5d47ce  50                                push   eax
0x5d47cf  8d45f4                            lea    eax,[ebp-0xc]
0x5d47d2  64a300000000                      mov    fs:0x0,eax
0x5d47d8  8bd9                              mov    ebx,ecx
0x5d47da  895df0                            mov    DWORD PTR [ebp-0x10],ebx
0x5d47dd  33ff                              xor    edi,edi
0x5d47df  897dcc                            mov    DWORD PTR [ebp-0x34],edi
0x5d47e2  897dd0                            mov    DWORD PTR [ebp-0x30],edi
0x5d47e5  897dd4                            mov    DWORD PTR [ebp-0x2c],edi
0x5d47e8  c745c80c92c100                    mov    DWORD PTR [ebp-0x38],0xc1920c
0x5d47ef  393d70fcf700                      cmp    DWORD PTR ds:0xf7fc70,edi
0x5d47f5  7406                              je     0x5d47fd
0x5d47f7  893d70fcf700                      mov    DWORD PTR ds:0xf7fc70,edi
0x5d47fd  53                                push   ebx
0x5d47fe  8d75c8                            lea    esi,[ebp-0x38]
0x5d4801  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x5d4808  e8636ee3ff                        call   0x40b670
0x5d480d  8b45cc                            mov    eax,DWORD PTR [ebp-0x34]
0x5d4810  c745c8e429bf00                    mov    DWORD PTR [ebp-0x38],0xbf29e4
0x5d4817  3bc7                              cmp    eax,edi
0x5d4819  7409                              je     0x5d4824
0x5d481b  50                                push   eax
0x5d481c  e8ebc92b00                        call   0x89120c
0x5d4821  83c404                            add    esp,0x4
0x5d4824  897de0                            mov    DWORD PTR [ebp-0x20],edi
0x5d4827  897de4                            mov    DWORD PTR [ebp-0x1c],edi
0x5d482a  897de8                            mov    DWORD PTR [ebp-0x18],edi
0x5d482d  c745dc0c92c100                    mov    DWORD PTR [ebp-0x24],0xc1920c
0x5d4834  393d70fcf700                      cmp    DWORD PTR ds:0xf7fc70,edi
0x5d483a  7406                              je     0x5d4842
0x5d483c  893d70fcf700                      mov    DWORD PTR ds:0xf7fc70,edi
0x5d4842  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
0x5d4849  81c380030000                      add    ebx,0x380
0x5d484f  e81cfdffff                        call   0x5d4570
0x5d4854  53                                push   ebx
0x5d4855  8bc8                              mov    ecx,eax
0x5d4857  8d7ddc                            lea    edi,[ebp-0x24]
0x5d485a  e8e156fdff                        call   0x5a9f40
0x5d485f  8b75f0                            mov    esi,DWORD PTR [ebp-0x10]
0x5d4862  68237a0800                        push   0x87a23
0x5d4867  e8d4201700                        call   0x746940
0x5d486c  50                                push   eax
0x5d486d  8bf7                              mov    esi,edi
0x5d486f  e8fc6de3ff                        call   0x40b670
0x5d4874  8b1b                              mov    ebx,DWORD PTR [ebx]
0x5d4876  8b03                              mov    eax,DWORD PTR [ebx]
0x5d4878  8b90d0000000                      mov    edx,DWORD PTR [eax+0xd0]
0x5d487e  8bcb                              mov    ecx,ebx
0x5d4880  ffd2                              call   edx
0x5d4882  8b45e0                            mov    eax,DWORD PTR [ebp-0x20]
0x5d4885  c745dce429bf00                    mov    DWORD PTR [ebp-0x24],0xbf29e4
0x5d488c  85c0                              test   eax,eax
0x5d488e  7409                              je     0x5d4899
0x5d4890  50                                push   eax
0x5d4891  e876c92b00                        call   0x89120c
0x5d4896  83c404                            add    esp,0x4
0x5d4899  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5d489c  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5d48a3  59                                pop    ecx
0x5d48a4  5f                                pop    edi
0x5d48a5  5e                                pop    esi
0x5d48a6  5b                                pop    ebx
0x5d48a7  8be5                              mov    esp,ebp
0x5d48a9  5d                                pop    ebp
0x5d48aa  c3                                ret

### B11 Scenario bottom onload binds distinct +380 part
VA 0x5d4ff0 RAW 0x1d43f0 END 0x5d50eb SHA256 744270eba8838af74e4307b72d7e07e37645e6cdd1978932436a82b332ca0d09
0x5d4ff0  55                                push   ebp
0x5d4ff1  8bec                              mov    ebp,esp
0x5d4ff3  6aff                              push   0xffffffff
0x5d4ff5  6830a99100                        push   0x91a930
0x5d4ffa  64a100000000                      mov    eax,fs:0x0
0x5d5000  50                                push   eax
0x5d5001  83ec2c                            sub    esp,0x2c
0x5d5004  53                                push   ebx
0x5d5005  56                                push   esi
0x5d5006  57                                push   edi
0x5d5007  a1201fd600                        mov    eax,ds:0xd61f20
0x5d500c  33c5                              xor    eax,ebp
0x5d500e  50                                push   eax
0x5d500f  8d45f4                            lea    eax,[ebp-0xc]
0x5d5012  64a300000000                      mov    fs:0x0,eax
0x5d5018  8bd9                              mov    ebx,ecx
0x5d501a  895df0                            mov    DWORD PTR [ebp-0x10],ebx
0x5d501d  33ff                              xor    edi,edi
0x5d501f  897dcc                            mov    DWORD PTR [ebp-0x34],edi
0x5d5022  897dd0                            mov    DWORD PTR [ebp-0x30],edi
0x5d5025  897dd4                            mov    DWORD PTR [ebp-0x2c],edi
0x5d5028  c745c80c92c100                    mov    DWORD PTR [ebp-0x38],0xc1920c
0x5d502f  393d70fcf700                      cmp    DWORD PTR ds:0xf7fc70,edi
0x5d5035  7406                              je     0x5d503d
0x5d5037  893d70fcf700                      mov    DWORD PTR ds:0xf7fc70,edi
0x5d503d  53                                push   ebx
0x5d503e  8d75c8                            lea    esi,[ebp-0x38]
0x5d5041  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x5d5048  e82366e3ff                        call   0x40b670
0x5d504d  8b45cc                            mov    eax,DWORD PTR [ebp-0x34]
0x5d5050  c745c8e429bf00                    mov    DWORD PTR [ebp-0x38],0xbf29e4
0x5d5057  3bc7                              cmp    eax,edi
0x5d5059  7409                              je     0x5d5064
0x5d505b  50                                push   eax
0x5d505c  e8abc12b00                        call   0x89120c
0x5d5061  83c404                            add    esp,0x4
0x5d5064  897de0                            mov    DWORD PTR [ebp-0x20],edi
0x5d5067  897de4                            mov    DWORD PTR [ebp-0x1c],edi
0x5d506a  897de8                            mov    DWORD PTR [ebp-0x18],edi
0x5d506d  c745dc0c92c100                    mov    DWORD PTR [ebp-0x24],0xc1920c
0x5d5074  393d70fcf700                      cmp    DWORD PTR ds:0xf7fc70,edi
0x5d507a  7406                              je     0x5d5082
0x5d507c  893d70fcf700                      mov    DWORD PTR ds:0xf7fc70,edi
0x5d5082  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
0x5d5089  81c380030000                      add    ebx,0x380
0x5d508f  e80c010000                        call   0x5d51a0
0x5d5094  53                                push   ebx
0x5d5095  8bc8                              mov    ecx,eax
0x5d5097  8d7ddc                            lea    edi,[ebp-0x24]
0x5d509a  e8a14efdff                        call   0x5a9f40
0x5d509f  8b75f0                            mov    esi,DWORD PTR [ebp-0x10]
0x5d50a2  68237a0800                        push   0x87a23
0x5d50a7  e894181700                        call   0x746940
0x5d50ac  50                                push   eax
0x5d50ad  8bf7                              mov    esi,edi
0x5d50af  e8bc65e3ff                        call   0x40b670
0x5d50b4  8b1b                              mov    ebx,DWORD PTR [ebx]
0x5d50b6  8b03                              mov    eax,DWORD PTR [ebx]
0x5d50b8  8b90d0000000                      mov    edx,DWORD PTR [eax+0xd0]
0x5d50be  8bcb                              mov    ecx,ebx
0x5d50c0  ffd2                              call   edx
0x5d50c2  8b45e0                            mov    eax,DWORD PTR [ebp-0x20]
0x5d50c5  c745dce429bf00                    mov    DWORD PTR [ebp-0x24],0xbf29e4
0x5d50cc  85c0                              test   eax,eax
0x5d50ce  7409                              je     0x5d50d9
0x5d50d0  50                                push   eax
0x5d50d1  e836c12b00                        call   0x89120c
0x5d50d6  83c404                            add    esp,0x4
0x5d50d9  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5d50dc  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5d50e3  59                                pop    ecx
0x5d50e4  5f                                pop    edi
0x5d50e5  5e                                pop    esi
0x5d50e6  5b                                pop    ebx
0x5d50e7  8be5                              mov    esp,ebp
0x5d50e9  5d                                pop    ebp
0x5d50ea  c3                                ret

### B12 Mission bottom-part cached descriptor
VA 0x5d4570 RAW 0x1d3970 END 0x5d4644 SHA256 d9e885ab0f821a1fe8c40f7b673df992fb430a733ef81899844cb8335e16d8da
0x5d4570  55                                push   ebp
0x5d4571  8bec                              mov    ebp,esp
0x5d4573  6aff                              push   0xffffffff
0x5d4575  6849e69100                        push   0x91e649
0x5d457a  64a100000000                      mov    eax,fs:0x0
0x5d4580  50                                push   eax
0x5d4581  83ec08                            sub    esp,0x8
0x5d4584  56                                push   esi
0x5d4585  57                                push   edi
0x5d4586  a1201fd600                        mov    eax,ds:0xd61f20
0x5d458b  33c5                              xor    eax,ebp
0x5d458d  50                                push   eax
0x5d458e  8d45f4                            lea    eax,[ebp-0xc]
0x5d4591  64a300000000                      mov    fs:0x0,eax
0x5d4597  a1f82efe00                        mov    eax,ds:0xfe2ef8
0x5d459c  85c0                              test   eax,eax
0x5d459e  0f858f000000                      jne    0x5d4633
0x5d45a4  6a10                              push   0x10
0x5d45a6  e8bdcc2b00                        call   0x891268
0x5d45ab  83c404                            add    esp,0x4
0x5d45ae  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5d45b1  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5d45b8  85c0                              test   eax,eax
0x5d45ba  7408                              je     0x5d45c4
0x5d45bc  50                                push   eax
0x5d45bd  e80e010000                        call   0x5d46d0
0x5d45c2  eb02                              jmp    0x5d45c6
0x5d45c4  33c0                              xor    eax,eax
0x5d45c6  83ceff                            or     esi,0xffffffff
0x5d45c9  8bc8                              mov    ecx,eax
0x5d45cb  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5d45ce  b801000000                        mov    eax,0x1
0x5d45d3  890df82efe00                      mov    DWORD PTR ds:0xfe2ef8,ecx
0x5d45d9  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x5d45df  7524                              jne    0x5d4605
0x5d45e1  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x5d45e7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5d45ea  e8c199e7ff                        call   0x44dfb0
0x5d45ef  6810cdbc00                        push   0xbccd10
0x5d45f4  e821dd2b00                        call   0x89231a
0x5d45f9  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5d45fc  8b0df82efe00                      mov    ecx,DWORD PTR ds:0xfe2ef8
0x5d4602  83c404                            add    esp,0x4
0x5d4605  8b01                              mov    eax,DWORD PTR [ecx]
0x5d4607  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x5d460a  8bf1                              mov    esi,ecx
0x5d460c  ffd2                              call   edx
0x5d460e  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x5d4611  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5d4614  8d7dec                            lea    edi,[ebp-0x14]
0x5d4617  beecaffa00                        mov    esi,0xfaafec
0x5d461c  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5d461f  e8fca8faff                        call   0x57ef20
0x5d4624  50                                push   eax
0x5d4625  56                                push   esi
0x5d4626  8d75ec                            lea    esi,[ebp-0x14]
0x5d4629  e8d2ab2500                        call   0x82f200
0x5d462e  a1f82efe00                        mov    eax,ds:0xfe2ef8
0x5d4633  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5d4636  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5d463d  59                                pop    ecx
0x5d463e  5f                                pop    edi
0x5d463f  5e                                pop    esi
0x5d4640  8be5                              mov    esp,ebp
0x5d4642  5d                                pop    ebp
0x5d4643  c3                                ret

### B13 Scenario bottom-part cached descriptor
VA 0x5d51a0 RAW 0x1d45a0 END 0x5d5274 SHA256 f0cb04658538f490f8a0f4d2ed19e11b96688fa3ba96bb3346991cc0f95da59e
0x5d51a0  55                                push   ebp
0x5d51a1  8bec                              mov    ebp,esp
0x5d51a3  6aff                              push   0xffffffff
0x5d51a5  6849e69100                        push   0x91e649
0x5d51aa  64a100000000                      mov    eax,fs:0x0
0x5d51b0  50                                push   eax
0x5d51b1  83ec08                            sub    esp,0x8
0x5d51b4  56                                push   esi
0x5d51b5  57                                push   edi
0x5d51b6  a1201fd600                        mov    eax,ds:0xd61f20
0x5d51bb  33c5                              xor    eax,ebp
0x5d51bd  50                                push   eax
0x5d51be  8d45f4                            lea    eax,[ebp-0xc]
0x5d51c1  64a300000000                      mov    fs:0x0,eax
0x5d51c7  a1002ffe00                        mov    eax,ds:0xfe2f00
0x5d51cc  85c0                              test   eax,eax
0x5d51ce  0f858f000000                      jne    0x5d5263
0x5d51d4  6a10                              push   0x10
0x5d51d6  e88dc02b00                        call   0x891268
0x5d51db  83c404                            add    esp,0x4
0x5d51de  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5d51e1  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5d51e8  85c0                              test   eax,eax
0x5d51ea  7408                              je     0x5d51f4
0x5d51ec  50                                push   eax
0x5d51ed  e80e010000                        call   0x5d5300
0x5d51f2  eb02                              jmp    0x5d51f6
0x5d51f4  33c0                              xor    eax,eax
0x5d51f6  83ceff                            or     esi,0xffffffff
0x5d51f9  8bc8                              mov    ecx,eax
0x5d51fb  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5d51fe  b801000000                        mov    eax,0x1
0x5d5203  890d002ffe00                      mov    DWORD PTR ds:0xfe2f00,ecx
0x5d5209  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x5d520f  7524                              jne    0x5d5235
0x5d5211  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x5d5217  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5d521a  e8918de7ff                        call   0x44dfb0
0x5d521f  6810cdbc00                        push   0xbccd10
0x5d5224  e8f1d02b00                        call   0x89231a
0x5d5229  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5d522c  8b0d002ffe00                      mov    ecx,DWORD PTR ds:0xfe2f00
0x5d5232  83c404                            add    esp,0x4
0x5d5235  8b01                              mov    eax,DWORD PTR [ecx]
0x5d5237  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x5d523a  8bf1                              mov    esi,ecx
0x5d523c  ffd2                              call   edx
0x5d523e  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x5d5241  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5d5244  8d7dec                            lea    edi,[ebp-0x14]
0x5d5247  beecaffa00                        mov    esi,0xfaafec
0x5d524c  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5d524f  e8cc9cfaff                        call   0x57ef20
0x5d5254  50                                push   eax
0x5d5255  56                                push   esi
0x5d5256  8d75ec                            lea    esi,[ebp-0x14]
0x5d5259  e8a29f2500                        call   0x82f200
0x5d525e  a1002ffe00                        mov    eax,ds:0xfe2f00
0x5d5263  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5d5266  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5d526d  59                                pop    ecx
0x5d526e  5f                                pop    edi
0x5d526f  5e                                pop    esi
0x5d5270  8be5                              mov    esp,ebp
0x5d5272  5d                                pop    ebp
0x5d5273  c3                                ret

### B14 Mission bottom-part descriptor allocD4/resource4E and constructor
VA 0x5d46d0 RAW 0x1d3ad0 END 0x5d474b SHA256 673a1d9e4729058d3b59a01747199ec9473c55f50c8f86db66210a245fc61837
0x5d46d0  55                                push   ebp
0x5d46d1  8bec                              mov    ebp,esp
0x5d46d3  6aff                              push   0xffffffff
0x5d46d5  6820ae9100                        push   0x91ae20
0x5d46da  64a100000000                      mov    eax,fs:0x0
0x5d46e0  50                                push   eax
0x5d46e1  51                                push   ecx
0x5d46e2  56                                push   esi
0x5d46e3  57                                push   edi
0x5d46e4  a1201fd600                        mov    eax,ds:0xd61f20
0x5d46e9  33c5                              xor    eax,ebp
0x5d46eb  50                                push   eax
0x5d46ec  8d45f4                            lea    eax,[ebp-0xc]
0x5d46ef  64a300000000                      mov    fs:0x0,eax
0x5d46f5  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5d46f8  33f6                              xor    esi,esi
0x5d46fa  897704                            mov    DWORD PTR [edi+0x4],esi
0x5d46fd  897708                            mov    DWORD PTR [edi+0x8],esi
0x5d4700  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5d4703  68d4000000                        push   0xd4
0x5d4708  c707481bc200                      mov    DWORD PTR [edi],0xc21b48
0x5d470e  e855d92b00                        call   0x892068
0x5d4713  83c404                            add    esp,0x4
0x5d4716  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5d4719  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5d471d  3bc6                              cmp    eax,esi
0x5d471f  7409                              je     0x5d472a
0x5d4721  8bf0                              mov    esi,eax
0x5d4723  e878d1ffff                        call   0x5d18a0
0x5d4728  eb02                              jmp    0x5d472c
0x5d472a  33c0                              xor    eax,eax
0x5d472c  89470c                            mov    DWORD PTR [edi+0xc],eax
0x5d472f  c747044e000000                    mov    DWORD PTR [edi+0x4],0x4e
0x5d4736  8bc7                              mov    eax,edi
0x5d4738  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5d473b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5d4742  59                                pop    ecx
0x5d4743  5f                                pop    edi
0x5d4744  5e                                pop    esi
0x5d4745  8be5                              mov    esp,ebp
0x5d4747  5d                                pop    ebp
0x5d4748  c20400                            ret    0x4

### B15 Scenario bottom-part descriptor allocA4/resource4D and constructor
VA 0x5d5300 RAW 0x1d4700 END 0x5d537b SHA256 d362b117df99fe890f859a95cd99287aa035479288cec2f91db80b0f30120891
0x5d5300  55                                push   ebp
0x5d5301  8bec                              mov    ebp,esp
0x5d5303  6aff                              push   0xffffffff
0x5d5305  6820ae9100                        push   0x91ae20
0x5d530a  64a100000000                      mov    eax,fs:0x0
0x5d5310  50                                push   eax
0x5d5311  51                                push   ecx
0x5d5312  56                                push   esi
0x5d5313  57                                push   edi
0x5d5314  a1201fd600                        mov    eax,ds:0xd61f20
0x5d5319  33c5                              xor    eax,ebp
0x5d531b  50                                push   eax
0x5d531c  8d45f4                            lea    eax,[ebp-0xc]
0x5d531f  64a300000000                      mov    fs:0x0,eax
0x5d5325  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5d5328  33f6                              xor    esi,esi
0x5d532a  897704                            mov    DWORD PTR [edi+0x4],esi
0x5d532d  897708                            mov    DWORD PTR [edi+0x8],esi
0x5d5330  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5d5333  68a4000000                        push   0xa4
0x5d5338  c7073822c200                      mov    DWORD PTR [edi],0xc22238
0x5d533e  e825cd2b00                        call   0x892068
0x5d5343  83c404                            add    esp,0x4
0x5d5346  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5d5349  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5d534d  3bc6                              cmp    eax,esi
0x5d534f  7409                              je     0x5d535a
0x5d5351  8bf0                              mov    esi,eax
0x5d5353  e808e2ffff                        call   0x5d3560
0x5d5358  eb02                              jmp    0x5d535c
0x5d535a  33c0                              xor    eax,eax
0x5d535c  89470c                            mov    DWORD PTR [edi+0xc],eax
0x5d535f  c747044d000000                    mov    DWORD PTR [edi+0x4],0x4d
0x5d5366  8bc7                              mov    eax,edi
0x5d5368  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5d536b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5d5372  59                                pop    ecx
0x5d5373  5f                                pop    edi
0x5d5374  5e                                pop    esi
0x5d5375  8be5                              mov    esp,ebp
0x5d5377  5d                                pop    ebp
0x5d5378  c20400                            ret    0x4

### B16 CBottomMenuFieldPart constructor concrete vptr C20F2C
VA 0x5d18a0 RAW 0x1d0ca0 END 0x5d1933 SHA256 ed13ec2c63fe3b9f2fdf24c227727e9aa5eb3dfc3227991654389845ed2f82b4
0x5d18a0  8bce                              mov    ecx,esi
0x5d18a2  e849391700                        call   0x7451f0
0x5d18a7  33c0                              xor    eax,eax
0x5d18a9  83c9ff                            or     ecx,0xffffffff
0x5d18ac  888680000000                      mov    BYTE PTR [esi+0x80],al
0x5d18b2  898684000000                      mov    DWORD PTR [esi+0x84],eax
0x5d18b8  8986a4000000                      mov    DWORD PTR [esi+0xa4],eax
0x5d18be  8986a8000000                      mov    DWORD PTR [esi+0xa8],eax
0x5d18c4  8986ac000000                      mov    DWORD PTR [esi+0xac],eax
0x5d18ca  8986b0000000                      mov    DWORD PTR [esi+0xb0],eax
0x5d18d0  8986b4000000                      mov    DWORD PTR [esi+0xb4],eax
0x5d18d6  8986b8000000                      mov    DWORD PTR [esi+0xb8],eax
0x5d18dc  8986bc000000                      mov    DWORD PTR [esi+0xbc],eax
0x5d18e2  c7062c0fc200                      mov    DWORD PTR [esi],0xc20f2c
0x5d18e8  898e88000000                      mov    DWORD PTR [esi+0x88],ecx
0x5d18ee  898e8c000000                      mov    DWORD PTR [esi+0x8c],ecx
0x5d18f4  898e90000000                      mov    DWORD PTR [esi+0x90],ecx
0x5d18fa  898e94000000                      mov    DWORD PTR [esi+0x94],ecx
0x5d1900  898e98000000                      mov    DWORD PTR [esi+0x98],ecx
0x5d1906  898e9c000000                      mov    DWORD PTR [esi+0x9c],ecx
0x5d190c  898ea0000000                      mov    DWORD PTR [esi+0xa0],ecx
0x5d1912  8986c0000000                      mov    DWORD PTR [esi+0xc0],eax
0x5d1918  8986c4000000                      mov    DWORD PTR [esi+0xc4],eax
0x5d191e  8986c8000000                      mov    DWORD PTR [esi+0xc8],eax
0x5d1924  8986cc000000                      mov    DWORD PTR [esi+0xcc],eax
0x5d192a  8986d0000000                      mov    DWORD PTR [esi+0xd0],eax
0x5d1930  8bc6                              mov    eax,esi
0x5d1932  c3                                ret

### B17 CBottomMenuScenarioPart constructor concrete vptr C216BC
VA 0x5d3560 RAW 0x1d2960 END 0x5d35a8 SHA256 b16557b14262e43870420df704ca3f27240311000202ebd982179369bcfe1782
0x5d3560  8bce                              mov    ecx,esi
0x5d3562  e8891c1700                        call   0x7451f0
0x5d3567  33c0                              xor    eax,eax
0x5d3569  898680000000                      mov    DWORD PTR [esi+0x80],eax
0x5d356f  898684000000                      mov    DWORD PTR [esi+0x84],eax
0x5d3575  898688000000                      mov    DWORD PTR [esi+0x88],eax
0x5d357b  89868c000000                      mov    DWORD PTR [esi+0x8c],eax
0x5d3581  898690000000                      mov    DWORD PTR [esi+0x90],eax
0x5d3587  898694000000                      mov    DWORD PTR [esi+0x94],eax
0x5d358d  898698000000                      mov    DWORD PTR [esi+0x98],eax
0x5d3593  c706bc16c200                      mov    DWORD PTR [esi],0xc216bc
0x5d3599  89869c000000                      mov    DWORD PTR [esi+0x9c],eax
0x5d359f  8986a0000000                      mov    DWORD PTR [esi+0xa0],eax
0x5d35a5  8bc6                              mov    eax,esi
0x5d35a7  c3                                ret

### I01 Inventory singleton descriptor FE2C84
VA 0x59e0b0 RAW 0x19d4b0 END 0x59e184 SHA256 a1ad128acbbae446f5128812bbc8430564a0e0a78acfcdffe7d4516eeafaf0bd
0x59e0b0  55                                push   ebp
0x59e0b1  8bec                              mov    ebp,esp
0x59e0b3  6aff                              push   0xffffffff
0x59e0b5  6849e69100                        push   0x91e649
0x59e0ba  64a100000000                      mov    eax,fs:0x0
0x59e0c0  50                                push   eax
0x59e0c1  83ec08                            sub    esp,0x8
0x59e0c4  56                                push   esi
0x59e0c5  57                                push   edi
0x59e0c6  a1201fd600                        mov    eax,ds:0xd61f20
0x59e0cb  33c5                              xor    eax,ebp
0x59e0cd  50                                push   eax
0x59e0ce  8d45f4                            lea    eax,[ebp-0xc]
0x59e0d1  64a300000000                      mov    fs:0x0,eax
0x59e0d7  a1842cfe00                        mov    eax,ds:0xfe2c84
0x59e0dc  85c0                              test   eax,eax
0x59e0de  0f858f000000                      jne    0x59e173
0x59e0e4  6a10                              push   0x10
0x59e0e6  e87d312f00                        call   0x891268
0x59e0eb  83c404                            add    esp,0x4
0x59e0ee  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x59e0f1  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x59e0f8  85c0                              test   eax,eax
0x59e0fa  7408                              je     0x59e104
0x59e0fc  50                                push   eax
0x59e0fd  e88e3d0000                        call   0x5a1e90
0x59e102  eb02                              jmp    0x59e106
0x59e104  33c0                              xor    eax,eax
0x59e106  83ceff                            or     esi,0xffffffff
0x59e109  8bc8                              mov    ecx,eax
0x59e10b  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x59e10e  b801000000                        mov    eax,0x1
0x59e113  890d842cfe00                      mov    DWORD PTR ds:0xfe2c84,ecx
0x59e119  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x59e11f  7524                              jne    0x59e145
0x59e121  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x59e127  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x59e12a  e881feeaff                        call   0x44dfb0
0x59e12f  6810cdbc00                        push   0xbccd10
0x59e134  e8e1412f00                        call   0x89231a
0x59e139  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x59e13c  8b0d842cfe00                      mov    ecx,DWORD PTR ds:0xfe2c84
0x59e142  83c404                            add    esp,0x4
0x59e145  8b01                              mov    eax,DWORD PTR [ecx]
0x59e147  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x59e14a  8bf1                              mov    esi,ecx
0x59e14c  ffd2                              call   edx
0x59e14e  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x59e151  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x59e154  8d7dec                            lea    edi,[ebp-0x14]
0x59e157  beecaffa00                        mov    esi,0xfaafec
0x59e15c  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x59e15f  e8bc0dfeff                        call   0x57ef20
0x59e164  50                                push   eax
0x59e165  56                                push   esi
0x59e166  8d75ec                            lea    esi,[ebp-0x14]
0x59e169  e892102900                        call   0x82f200
0x59e16e  a1842cfe00                        mov    eax,ds:0xfe2c84
0x59e173  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x59e176  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x59e17d  59                                pop    ecx
0x59e17e  5f                                pop    edi
0x59e17f  5e                                pop    esi
0x59e180  8be5                              mov    esp,ebp
0x59e182  5d                                pop    ebp
0x59e183  c3                                ret

### I02 Inventory descriptor allocation and concrete constructor
VA 0x5a1e90 RAW 0x1a1290 END 0x5a1f11 SHA256 14ee4669203cf73a2976182b33392bf02ea7d3c80bb653839a56f3c8c46ff509
0x5a1e90  55                                push   ebp
0x5a1e91  8bec                              mov    ebp,esp
0x5a1e93  6aff                              push   0xffffffff
0x5a1e95  68e0f79100                        push   0x91f7e0
0x5a1e9a  64a100000000                      mov    eax,fs:0x0
0x5a1ea0  50                                push   eax
0x5a1ea1  51                                push   ecx
0x5a1ea2  56                                push   esi
0x5a1ea3  a1201fd600                        mov    eax,ds:0xd61f20
0x5a1ea8  33c5                              xor    eax,ebp
0x5a1eaa  50                                push   eax
0x5a1eab  8d45f4                            lea    eax,[ebp-0xc]
0x5a1eae  64a300000000                      mov    fs:0x0,eax
0x5a1eb4  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x5a1eb7  c7460400000000                    mov    DWORD PTR [esi+0x4],0x0
0x5a1ebe  c7460800000000                    mov    DWORD PTR [esi+0x8],0x0
0x5a1ec5  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5a1ecc  68b0010000                        push   0x1b0
0x5a1ed1  c706c0bac100                      mov    DWORD PTR [esi],0xc1bac0
0x5a1ed7  e88c012f00                        call   0x892068
0x5a1edc  83c404                            add    esp,0x4
0x5a1edf  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5a1ee2  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5a1ee6  85c0                              test   eax,eax
0x5a1ee8  7407                              je     0x5a1ef1
0x5a1eea  e8c18d0500                        call   0x5facb0
0x5a1eef  eb02                              jmp    0x5a1ef3
0x5a1ef1  33c0                              xor    eax,eax
0x5a1ef3  89460c                            mov    DWORD PTR [esi+0xc],eax
0x5a1ef6  c7460465000000                    mov    DWORD PTR [esi+0x4],0x65
0x5a1efd  8bc6                              mov    eax,esi
0x5a1eff  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5a1f02  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5a1f09  59                                pop    ecx
0x5a1f0a  5e                                pop    esi
0x5a1f0b  8be5                              mov    esp,ebp
0x5a1f0d  5d                                pop    ebp
0x5a1f0e  c20400                            ret    0x4

### I03 CInventoryDialog constructor and vptr
VA 0x5facb0 RAW 0x1fa0b0 END 0x5faf07 SHA256 eab19029786f39bec659d34606659bca07e8a79cccf0939b0b8565d58e31d5a3
0x5facb0  56                                push   esi
0x5facb1  8bf0                              mov    esi,eax
0x5facb3  e808a4ffff                        call   0x5f50c0
0x5facb8  33c0                              xor    eax,eax
0x5facba  898628010000                      mov    DWORD PTR [esi+0x128],eax
0x5facc0  89862c010000                      mov    DWORD PTR [esi+0x12c],eax
0x5facc6  898630010000                      mov    DWORD PTR [esi+0x130],eax
0x5faccc  898634010000                      mov    DWORD PTR [esi+0x134],eax
0x5facd2  898638010000                      mov    DWORD PTR [esi+0x138],eax
0x5facd8  89863c010000                      mov    DWORD PTR [esi+0x13c],eax
0x5facde  898640010000                      mov    DWORD PTR [esi+0x140],eax
0x5face4  c706d490c200                      mov    DWORD PTR [esi],0xc290d4
0x5facea  898658010000                      mov    DWORD PTR [esi+0x158],eax
0x5facf0  c7865c01000007000000              mov    DWORD PTR [esi+0x15c],0x7
0x5facfa  33c9                              xor    ecx,ecx
0x5facfc  66898e48010000                    mov    WORD PTR [esi+0x148],cx
0x5fad03  898664010000                      mov    DWORD PTR [esi+0x164],eax
0x5fad09  898668010000                      mov    DWORD PTR [esi+0x168],eax
0x5fad0f  898670010000                      mov    DWORD PTR [esi+0x170],eax
0x5fad15  898674010000                      mov    DWORD PTR [esi+0x174],eax
0x5fad1b  898690010000                      mov    DWORD PTR [esi+0x190],eax
0x5fad21  898694010000                      mov    DWORD PTR [esi+0x194],eax
0x5fad27  898678010000                      mov    DWORD PTR [esi+0x178],eax
0x5fad2d  898698010000                      mov    DWORD PTR [esi+0x198],eax
0x5fad33  89869c010000                      mov    DWORD PTR [esi+0x19c],eax
0x5fad39  89867c010000                      mov    DWORD PTR [esi+0x17c],eax
0x5fad3f  8986a0010000                      mov    DWORD PTR [esi+0x1a0],eax
0x5fad45  8986a4010000                      mov    DWORD PTR [esi+0x1a4],eax
0x5fad4b  898680010000                      mov    DWORD PTR [esi+0x180],eax
0x5fad51  8986a8010000                      mov    DWORD PTR [esi+0x1a8],eax
0x5fad57  8986ac010000                      mov    DWORD PTR [esi+0x1ac],eax
0x5fad5d  8b9694010000                      mov    edx,DWORD PTR [esi+0x194]
0x5fad63  838e9001000002                    or     DWORD PTR [esi+0x190],0x2
0x5fad6a  838e9001000004                    or     DWORD PTR [esi+0x190],0x4
0x5fad71  838e9001000008                    or     DWORD PTR [esi+0x190],0x8
0x5fad78  818ea001000000000200              or     DWORD PTR [esi+0x1a0],0x20000
0x5fad82  818ea001000000000400              or     DWORD PTR [esi+0x1a0],0x40000
0x5fad8c  83c8ff                            or     eax,0xffffffff
0x5fad8f  818ea001000000000800              or     DWORD PTR [esi+0x1a0],0x80000
0x5fad99  898688010000                      mov    DWORD PTR [esi+0x188],eax
0x5fad9f  89868c010000                      mov    DWORD PTR [esi+0x18c],eax
0x5fada5  8bc2                              mov    eax,edx
0x5fada7  8bc8                              mov    ecx,eax
0x5fada9  898e94010000                      mov    DWORD PTR [esi+0x194],ecx
0x5fadaf  898694010000                      mov    DWORD PTR [esi+0x194],eax
0x5fadb5  818e9401000000010000              or     DWORD PTR [esi+0x194],0x100
0x5fadbf  818e9401000000020000              or     DWORD PTR [esi+0x194],0x200
0x5fadc9  818e9401000000040000              or     DWORD PTR [esi+0x194],0x400
0x5fadd3  818e9401000000080000              or     DWORD PTR [esi+0x194],0x800
0x5faddd  b910000000                        mov    ecx,0x10
0x5fade2  098e90010000                      or     DWORD PTR [esi+0x190],ecx
0x5fade8  818e9001000000000008              or     DWORD PTR [esi+0x190],0x8000000
0x5fadf2  8b9690010000                      mov    edx,DWORD PTR [esi+0x190]
0x5fadf8  8bc2                              mov    eax,edx
0x5fadfa  8b9694010000                      mov    edx,DWORD PTR [esi+0x194]
0x5fae00  898690010000                      mov    DWORD PTR [esi+0x190],eax
0x5fae06  818e9001000000000100              or     DWORD PTR [esi+0x190],0x10000
0x5fae10  899694010000                      mov    DWORD PTR [esi+0x194],edx
0x5fae16  8b969c010000                      mov    edx,DWORD PTR [esi+0x19c]
0x5fae1c  b820000000                        mov    eax,0x20
0x5fae21  098698010000                      or     DWORD PTR [esi+0x198],eax
0x5fae27  818e9801000000200000              or     DWORD PTR [esi+0x198],0x2000
0x5fae31  818e9801000000002000              or     DWORD PTR [esi+0x198],0x200000
0x5fae3b  818e9801000000008000              or     DWORD PTR [esi+0x198],0x800000
0x5fae45  818e9801000000000004              or     DWORD PTR [esi+0x198],0x4000000
0x5fae4f  89969c010000                      mov    DWORD PTR [esi+0x19c],edx
0x5fae55  8b9698010000                      mov    edx,DWORD PTR [esi+0x198]
0x5fae5b  838e9c01000040                    or     DWORD PTR [esi+0x19c],0x40
0x5fae62  818e9c01000080000000              or     DWORD PTR [esi+0x19c],0x80
0x5fae6c  899698010000                      mov    DWORD PTR [esi+0x198],edx
0x5fae72  8b96a4010000                      mov    edx,DWORD PTR [esi+0x1a4]
0x5fae78  8996a4010000                      mov    DWORD PTR [esi+0x1a4],edx
0x5fae7e  8b96a0010000                      mov    edx,DWORD PTR [esi+0x1a0]
0x5fae84  838ea401000001                    or     DWORD PTR [esi+0x1a4],0x1
0x5fae8b  098ea4010000                      or     DWORD PTR [esi+0x1a4],ecx
0x5fae91  0986a4010000                      or     DWORD PTR [esi+0x1a4],eax
0x5fae97  8b8694010000                      mov    eax,DWORD PTR [esi+0x194]
0x5fae9d  8bca                              mov    ecx,edx
0x5fae9f  8b9690010000                      mov    edx,DWORD PTR [esi+0x190]
0x5faea5  0996a8010000                      or     DWORD PTR [esi+0x1a8],edx
0x5faeab  898ea0010000                      mov    DWORD PTR [esi+0x1a0],ecx
0x5faeb1  0986ac010000                      or     DWORD PTR [esi+0x1ac],eax
0x5faeb7  8b8e98010000                      mov    ecx,DWORD PTR [esi+0x198]
0x5faebd  098ea8010000                      or     DWORD PTR [esi+0x1a8],ecx
0x5faec3  8b969c010000                      mov    edx,DWORD PTR [esi+0x19c]
0x5faec9  0996ac010000                      or     DWORD PTR [esi+0x1ac],edx
0x5faecf  8b86a0010000                      mov    eax,DWORD PTR [esi+0x1a0]
0x5faed5  0986a8010000                      or     DWORD PTR [esi+0x1a8],eax
0x5faedb  8b8ea4010000                      mov    ecx,DWORD PTR [esi+0x1a4]
0x5faee1  098eac010000                      or     DWORD PTR [esi+0x1ac],ecx
0x5faee7  8b86ac010000                      mov    eax,DWORD PTR [esi+0x1ac]
0x5faeed  8b96a8010000                      mov    edx,DWORD PTR [esi+0x1a8]
0x5faef3  f7d0                              not    eax
0x5faef5  f7d2                              not    edx
0x5faef7  8986ac010000                      mov    DWORD PTR [esi+0x1ac],eax
0x5faefd  8996a8010000                      mov    DWORD PTR [esi+0x1a8],edx
0x5faf03  8bc6                              mov    eax,esi
0x5faf05  5e                                pop    esi
0x5faf06  c3                                ret

### I04 base inventory vector at+104 and selected index+118 init
VA 0x5f50c0 RAW 0x1f44c0 END 0x5f5127 SHA256 974131950ca32bb99b87b242350366082b06023be53c0c4d7234a5839f5b76af
0x5f50c0  8bce                              mov    ecx,esi
0x5f50c2  e819141600                        call   0x7564e0
0x5f50c7  33c0                              xor    eax,eax
0x5f50c9  898680000000                      mov    DWORD PTR [esi+0x80],eax
0x5f50cf  8986ec000000                      mov    DWORD PTR [esi+0xec],eax
0x5f50d5  8986f0000000                      mov    DWORD PTR [esi+0xf0],eax
0x5f50db  c786f400000001010100              mov    DWORD PTR [esi+0xf4],0x10101
0x5f50e5  c7068482c200                      mov    DWORD PTR [esi],0xc28284
0x5f50eb  898604010000                      mov    DWORD PTR [esi+0x104],eax
0x5f50f1  898608010000                      mov    DWORD PTR [esi+0x108],eax
0x5f50f7  89860c010000                      mov    DWORD PTR [esi+0x10c],eax
0x5f50fd  8d4801                            lea    ecx,[eax+0x1]
0x5f5100  8986f8000000                      mov    DWORD PTR [esi+0xf8],eax
0x5f5106  8986fc000000                      mov    DWORD PTR [esi+0xfc],eax
0x5f510c  898600010000                      mov    DWORD PTR [esi+0x100],eax
0x5f5112  898618010000                      mov    DWORD PTR [esi+0x118],eax
0x5f5118  888e24010000                      mov    BYTE PTR [esi+0x124],cl
0x5f511e  898e1c010000                      mov    DWORD PTR [esi+0x11c],ecx
0x5f5124  8bc6                              mov    eax,esi
0x5f5126  c3                                ret

### I05 Inventory onload populates exactly two normal selected panels
VA 0x5fb0e0 RAW 0x1fa4e0 END 0x5fb301 SHA256 8769c89c41cbfc0870463940382ff5b0002456d6fd47c89b0fa76baf6b05de19
0x5fb0e0  55                                push   ebp
0x5fb0e1  8bec                              mov    ebp,esp
0x5fb0e3  6aff                              push   0xffffffff
0x5fb0e5  6816e09200                        push   0x92e016
0x5fb0ea  64a100000000                      mov    eax,fs:0x0
0x5fb0f0  50                                push   eax
0x5fb0f1  83ec3c                            sub    esp,0x3c
0x5fb0f4  a1201fd600                        mov    eax,ds:0xd61f20
0x5fb0f9  33c5                              xor    eax,ebp
0x5fb0fb  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5fb0fe  53                                push   ebx
0x5fb0ff  56                                push   esi
0x5fb100  57                                push   edi
0x5fb101  50                                push   eax
0x5fb102  8d45f4                            lea    eax,[ebp-0xc]
0x5fb105  64a300000000                      mov    fs:0x0,eax
0x5fb10b  8b01                              mov    eax,DWORD PTR [ecx]
0x5fb10d  8b90ac010000                      mov    edx,DWORD PTR [eax+0x1ac]
0x5fb113  894dd0                            mov    DWORD PTR [ebp-0x30],ecx
0x5fb116  8d9904010000                      lea    ebx,[ecx+0x104]
0x5fb11c  ffd2                              call   edx
0x5fb11e  40                                inc    eax
0x5fb11f  50                                push   eax
0x5fb120  8bf3                              mov    esi,ebx
0x5fb122  e819cdffff                        call   0x5f7e40
0x5fb127  33c0                              xor    eax,eax
0x5fb129  8945c0                            mov    DWORD PTR [ebp-0x40],eax
0x5fb12c  8945c4                            mov    DWORD PTR [ebp-0x3c],eax
0x5fb12f  8945c8                            mov    DWORD PTR [ebp-0x38],eax
0x5fb132  c745bc0c92c100                    mov    DWORD PTR [ebp-0x44],0xc1920c
0x5fb139  390570fcf700                      cmp    DWORD PTR ds:0xf7fc70,eax
0x5fb13f  7405                              je     0x5fb146
0x5fb141  a370fcf700                        mov    ds:0xf7fc70,eax
0x5fb146  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x5fb14d  8b33                              mov    esi,DWORD PTR [ebx]
0x5fb14f  e8ec350000                        call   0x5fe740
0x5fb154  56                                push   esi
0x5fb155  8bc8                              mov    ecx,eax
0x5fb157  8d7dbc                            lea    edi,[ebp-0x44]
0x5fb15a  e8e1edfaff                        call   0x5a9f40
0x5fb15f  8b33                              mov    esi,DWORD PTR [ebx]
0x5fb161  83c604                            add    esi,0x4
0x5fb164  e8b7360000                        call   0x5fe820
0x5fb169  56                                push   esi
0x5fb16a  8bc8                              mov    ecx,eax
0x5fb16c  e8cfedfaff                        call   0x5a9f40
0x5fb171  8b7dd0                            mov    edi,DWORD PTR [ebp-0x30]
0x5fb174  57                                push   edi
0x5fb175  8d75bc                            lea    esi,[ebp-0x44]
0x5fb178  e8f304e1ff                        call   0x40b670
0x5fb17d  8b03                              mov    eax,DWORD PTR [ebx]
0x5fb17f  8b30                              mov    esi,DWORD PTR [eax]
0x5fb181  6a01                              push   0x1
0x5fb183  e818abffff                        call   0x5f5ca0
0x5fb188  8b0b                              mov    ecx,DWORD PTR [ebx]
0x5fb18a  8b31                              mov    esi,DWORD PTR [ecx]
0x5fb18c  8b16                              mov    edx,DWORD PTR [esi]
0x5fb18e  8b82a4010000                      mov    eax,DWORD PTR [edx+0x1a4]
0x5fb194  8bce                              mov    ecx,esi
0x5fb196  ffd0                              call   eax
0x5fb198  8b16                              mov    edx,DWORD PTR [esi]
0x5fb19a  8b92a0010000                      mov    edx,DWORD PTR [edx+0x1a0]
0x5fb1a0  8bce                              mov    ecx,esi
0x5fb1a2  8945d0                            mov    DWORD PTR [ebp-0x30],eax
0x5fb1a5  ffd2                              call   edx
0x5fb1a7  8bc8                              mov    ecx,eax
0x5fb1a9  8b45d0                            mov    eax,DWORD PTR [ebp-0x30]
0x5fb1ac  68f82bbf00                        push   0xbf2bf8
0x5fb1b1  8d75d4                            lea    esi,[ebp-0x2c]
0x5fb1b4  e8a732e1ff                        call   0x40e460
0x5fb1b9  83c404                            add    esp,0x4
0x5fb1bc  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x5fb1c0  8bb764010000                      mov    esi,DWORD PTR [edi+0x164]
0x5fb1c6  50                                push   eax
0x5fb1c7  8db6e8000000                      lea    esi,[esi+0xe8]
0x5fb1cd  e82ec61500                        call   0x757800
0x5fb1d2  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5fb1d6  837de808                          cmp    DWORD PTR [ebp-0x18],0x8
0x5fb1da  720c                              jb     0x5fb1e8
0x5fb1dc  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
0x5fb1df  50                                push   eax
0x5fb1e0  e827602900                        call   0x89120c
0x5fb1e5  83c404                            add    esp,0x4
0x5fb1e8  8b0b                              mov    ecx,DWORD PTR [ebx]
0x5fb1ea  8b01                              mov    eax,DWORD PTR [ecx]
0x5fb1ec  8d9728010000                      lea    edx,[edi+0x128]
0x5fb1f2  899010010000                      mov    DWORD PTR [eax+0x110],edx
0x5fb1f8  8b03                              mov    eax,DWORD PTR [ebx]
0x5fb1fa  8b08                              mov    ecx,DWORD PTR [eax]
0x5fb1fc  8b87f8000000                      mov    eax,DWORD PTR [edi+0xf8]
0x5fb202  8b80d8000000                      mov    eax,DWORD PTR [eax+0xd8]
0x5fb208  85c0                              test   eax,eax
0x5fb20a  7409                              je     0x5fb215
0x5fb20c  51                                push   ecx
0x5fb20d  6a00                              push   0x0
0x5fb20f  50                                push   eax
0x5fb210  e89bfae0ff                        call   0x40acb0
0x5fb215  8b0b                              mov    ecx,DWORD PTR [ebx]
0x5fb217  8b7104                            mov    esi,DWORD PTR [ecx+0x4]
0x5fb21a  6a02                              push   0x2
0x5fb21c  e87faaffff                        call   0x5f5ca0
0x5fb221  f605e45afe0001                    test   BYTE PTR ds:0xfe5ae4,0x1
0x5fb228  7526                              jne    0x5fb250
0x5fb22a  830de45afe0001                    or     DWORD PTR ds:0xfe5ae4,0x1
0x5fb231  68c45afe00                        push   0xfe5ac4
0x5fb236  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0x5fb23a  e8019af8ff                        call   0x584c40
0x5fb23f  6890f3bc00                        push   0xbcf390
0x5fb244  e8d1702900                        call   0x89231a
0x5fb249  83c404                            add    esp,0x4
0x5fb24c  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5fb250  8d55d0                            lea    edx,[ebp-0x30]
0x5fb253  52                                push   edx
0x5fb254  8d45b8                            lea    eax,[ebp-0x48]
0x5fb257  b9c45afe00                        mov    ecx,0xfe5ac4
0x5fb25c  c745d003000000                    mov    DWORD PTR [ebp-0x30],0x3
0x5fb263  e8888ef7ff                        call   0x5740f0
0x5fb268  8b45b8                            mov    eax,DWORD PTR [ebp-0x48]
0x5fb26b  3b05c85afe00                      cmp    eax,DWORD PTR ds:0xfe5ac8
0x5fb271  740d                              je     0x5fb280
0x5fb273  83782408                          cmp    DWORD PTR [eax+0x24],0x8
0x5fb277  8d4810                            lea    ecx,[eax+0x10]
0x5fb27a  720a                              jb     0x5fb286
0x5fb27c  8b09                              mov    ecx,DWORD PTR [ecx]
0x5fb27e  eb06                              jmp    0x5fb286
0x5fb280  cc                                int3
0x5fb281  b9fcd1be00                        mov    ecx,0xbed1fc
0x5fb286  8bb768010000                      mov    esi,DWORD PTR [edi+0x168]
0x5fb28c  81c6e8000000                      add    esi,0xe8
0x5fb292  e879c41500                        call   0x757710
0x5fb297  8b87f8000000                      mov    eax,DWORD PTR [edi+0xf8]
0x5fb29d  8b80d8000000                      mov    eax,DWORD PTR [eax+0xd8]
0x5fb2a3  85c0                              test   eax,eax
0x5fb2a5  740e                              je     0x5fb2b5
0x5fb2a7  8b0b                              mov    ecx,DWORD PTR [ebx]
0x5fb2a9  8b5104                            mov    edx,DWORD PTR [ecx+0x4]
0x5fb2ac  52                                push   edx
0x5fb2ad  6a01                              push   0x1
0x5fb2af  50                                push   eax
0x5fb2b0  e8fbf9e0ff                        call   0x40acb0
0x5fb2b5  8b87f8000000                      mov    eax,DWORD PTR [edi+0xf8]
0x5fb2bb  50                                push   eax
0x5fb2bc  e85fe61400                        call   0x749920
0x5fb2c1  8bb7f8000000                      mov    esi,DWORD PTR [edi+0xf8]
0x5fb2c7  6a00                              push   0x0
0x5fb2c9  e8e202e1ff                        call   0x40b5b0
0x5fb2ce  8b45c0                            mov    eax,DWORD PTR [ebp-0x40]
0x5fb2d1  c745bce429bf00                    mov    DWORD PTR [ebp-0x44],0xbf29e4
0x5fb2d8  85c0                              test   eax,eax
0x5fb2da  7409                              je     0x5fb2e5
0x5fb2dc  50                                push   eax
0x5fb2dd  e82a5f2900                        call   0x89120c
0x5fb2e2  83c404                            add    esp,0x4
0x5fb2e5  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5fb2e8  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5fb2ef  59                                pop    ecx
0x5fb2f0  5f                                pop    edi
0x5fb2f1  5e                                pop    esi
0x5fb2f2  5b                                pop    ebx
0x5fb2f3  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x5fb2f6  33cd                              xor    ecx,ebp
0x5fb2f8  e8045d2900                        call   0x891001
0x5fb2fd  8be5                              mov    esp,ebp
0x5fb2ff  5d                                pop    ebp
0x5fb300  c3                                ret

### I06 InventoryInside descriptor singleton
VA 0x5fe740 RAW 0x1fdb40 END 0x5fe814 SHA256 2514b94ae3d674611690675d5bb25b6e466a31e675fc2b2f0aaf65fb9aff7f81
0x5fe740  55                                push   ebp
0x5fe741  8bec                              mov    ebp,esp
0x5fe743  6aff                              push   0xffffffff
0x5fe745  6849e69100                        push   0x91e649
0x5fe74a  64a100000000                      mov    eax,fs:0x0
0x5fe750  50                                push   eax
0x5fe751  83ec08                            sub    esp,0x8
0x5fe754  56                                push   esi
0x5fe755  57                                push   edi
0x5fe756  a1201fd600                        mov    eax,ds:0xd61f20
0x5fe75b  33c5                              xor    eax,ebp
0x5fe75d  50                                push   eax
0x5fe75e  8d45f4                            lea    eax,[ebp-0xc]
0x5fe761  64a300000000                      mov    fs:0x0,eax
0x5fe767  a1802ffe00                        mov    eax,ds:0xfe2f80
0x5fe76c  85c0                              test   eax,eax
0x5fe76e  0f858f000000                      jne    0x5fe803
0x5fe774  6a10                              push   0x10
0x5fe776  e8ed2a2900                        call   0x891268
0x5fe77b  83c404                            add    esp,0x4
0x5fe77e  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5fe781  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5fe788  85c0                              test   eax,eax
0x5fe78a  7408                              je     0x5fe794
0x5fe78c  50                                push   eax
0x5fe78d  e86e020000                        call   0x5fea00
0x5fe792  eb02                              jmp    0x5fe796
0x5fe794  33c0                              xor    eax,eax
0x5fe796  83ceff                            or     esi,0xffffffff
0x5fe799  8bc8                              mov    ecx,eax
0x5fe79b  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5fe79e  b801000000                        mov    eax,0x1
0x5fe7a3  890d802ffe00                      mov    DWORD PTR ds:0xfe2f80,ecx
0x5fe7a9  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x5fe7af  7524                              jne    0x5fe7d5
0x5fe7b1  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x5fe7b7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5fe7ba  e8f1f7e4ff                        call   0x44dfb0
0x5fe7bf  6810cdbc00                        push   0xbccd10
0x5fe7c4  e8513b2900                        call   0x89231a
0x5fe7c9  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5fe7cc  8b0d802ffe00                      mov    ecx,DWORD PTR ds:0xfe2f80
0x5fe7d2  83c404                            add    esp,0x4
0x5fe7d5  8b01                              mov    eax,DWORD PTR [ecx]
0x5fe7d7  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x5fe7da  8bf1                              mov    esi,ecx
0x5fe7dc  ffd2                              call   edx
0x5fe7de  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x5fe7e1  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5fe7e4  8d7dec                            lea    edi,[ebp-0x14]
0x5fe7e7  beecaffa00                        mov    esi,0xfaafec
0x5fe7ec  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5fe7ef  e82c07f8ff                        call   0x57ef20
0x5fe7f4  50                                push   eax
0x5fe7f5  56                                push   esi
0x5fe7f6  8d75ec                            lea    esi,[ebp-0x14]
0x5fe7f9  e8020a2300                        call   0x82f200
0x5fe7fe  a1802ffe00                        mov    eax,ds:0xfe2f80
0x5fe803  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5fe806  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5fe80d  59                                pop    ecx
0x5fe80e  5f                                pop    edi
0x5fe80f  5e                                pop    esi
0x5fe810  8be5                              mov    esp,ebp
0x5fe812  5d                                pop    ebp
0x5fe813  c3                                ret

### I07 QuestInventoryInside descriptor singleton
VA 0x5fe820 RAW 0x1fdc20 END 0x5fe8f4 SHA256 13cb3ca4750b1c33f8acfeac3dbc8b9e102612c09fabe72c2e8bf8efdfde476e
0x5fe820  55                                push   ebp
0x5fe821  8bec                              mov    ebp,esp
0x5fe823  6aff                              push   0xffffffff
0x5fe825  6849e69100                        push   0x91e649
0x5fe82a  64a100000000                      mov    eax,fs:0x0
0x5fe830  50                                push   eax
0x5fe831  83ec08                            sub    esp,0x8
0x5fe834  56                                push   esi
0x5fe835  57                                push   edi
0x5fe836  a1201fd600                        mov    eax,ds:0xd61f20
0x5fe83b  33c5                              xor    eax,ebp
0x5fe83d  50                                push   eax
0x5fe83e  8d45f4                            lea    eax,[ebp-0xc]
0x5fe841  64a300000000                      mov    fs:0x0,eax
0x5fe847  a1842ffe00                        mov    eax,ds:0xfe2f84
0x5fe84c  85c0                              test   eax,eax
0x5fe84e  0f858f000000                      jne    0x5fe8e3
0x5fe854  6a10                              push   0x10
0x5fe856  e80d2a2900                        call   0x891268
0x5fe85b  83c404                            add    esp,0x4
0x5fe85e  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5fe861  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5fe868  85c0                              test   eax,eax
0x5fe86a  7408                              je     0x5fe874
0x5fe86c  50                                push   eax
0x5fe86d  e81e020000                        call   0x5fea90
0x5fe872  eb02                              jmp    0x5fe876
0x5fe874  33c0                              xor    eax,eax
0x5fe876  83ceff                            or     esi,0xffffffff
0x5fe879  8bc8                              mov    ecx,eax
0x5fe87b  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5fe87e  b801000000                        mov    eax,0x1
0x5fe883  890d842ffe00                      mov    DWORD PTR ds:0xfe2f84,ecx
0x5fe889  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x5fe88f  7524                              jne    0x5fe8b5
0x5fe891  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x5fe897  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5fe89a  e811f7e4ff                        call   0x44dfb0
0x5fe89f  6810cdbc00                        push   0xbccd10
0x5fe8a4  e8713a2900                        call   0x89231a
0x5fe8a9  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5fe8ac  8b0d842ffe00                      mov    ecx,DWORD PTR ds:0xfe2f84
0x5fe8b2  83c404                            add    esp,0x4
0x5fe8b5  8b01                              mov    eax,DWORD PTR [ecx]
0x5fe8b7  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x5fe8ba  8bf1                              mov    esi,ecx
0x5fe8bc  ffd2                              call   edx
0x5fe8be  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x5fe8c1  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5fe8c4  8d7dec                            lea    edi,[ebp-0x14]
0x5fe8c7  beecaffa00                        mov    esi,0xfaafec
0x5fe8cc  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5fe8cf  e84c06f8ff                        call   0x57ef20
0x5fe8d4  50                                push   eax
0x5fe8d5  56                                push   esi
0x5fe8d6  8d75ec                            lea    esi,[ebp-0x14]
0x5fe8d9  e822092300                        call   0x82f200
0x5fe8de  a1842ffe00                        mov    eax,ds:0xfe2f84
0x5fe8e3  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5fe8e6  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5fe8ed  59                                pop    ecx
0x5fe8ee  5f                                pop    edi
0x5fe8ef  5e                                pop    esi
0x5fe8f0  8be5                              mov    esp,ebp
0x5fe8f2  5d                                pop    ebp
0x5fe8f3  c3                                ret

### I08 InventoryInside descriptor alloc178 and constructor
VA 0x5fea00 RAW 0x1fde00 END 0x5fea82 SHA256 ef6820054dca5b5b8e75e3e6af0c0ba0e5cb2fc1ba4f3924113cb890b5878d07
0x5fea00  55                                push   ebp
0x5fea01  8bec                              mov    ebp,esp
0x5fea03  6aff                              push   0xffffffff
0x5fea05  68e0f79100                        push   0x91f7e0
0x5fea0a  64a100000000                      mov    eax,fs:0x0
0x5fea10  50                                push   eax
0x5fea11  51                                push   ecx
0x5fea12  56                                push   esi
0x5fea13  a1201fd600                        mov    eax,ds:0xd61f20
0x5fea18  33c5                              xor    eax,ebp
0x5fea1a  50                                push   eax
0x5fea1b  8d45f4                            lea    eax,[ebp-0xc]
0x5fea1e  64a300000000                      mov    fs:0x0,eax
0x5fea24  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x5fea27  c7460400000000                    mov    DWORD PTR [esi+0x4],0x0
0x5fea2e  c7460800000000                    mov    DWORD PTR [esi+0x8],0x0
0x5fea35  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5fea3c  6878010000                        push   0x178
0x5fea41  c7069c92c200                      mov    DWORD PTR [esi],0xc2929c
0x5fea47  e81c362900                        call   0x892068
0x5fea4c  83c404                            add    esp,0x4
0x5fea4f  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5fea52  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5fea56  85c0                              test   eax,eax
0x5fea58  7408                              je     0x5fea62
0x5fea5a  50                                push   eax
0x5fea5b  e8e0040000                        call   0x5fef40
0x5fea60  eb02                              jmp    0x5fea64
0x5fea62  33c0                              xor    eax,eax
0x5fea64  89460c                            mov    DWORD PTR [esi+0xc],eax
0x5fea67  c7460466000000                    mov    DWORD PTR [esi+0x4],0x66
0x5fea6e  8bc6                              mov    eax,esi
0x5fea70  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5fea73  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5fea7a  59                                pop    ecx
0x5fea7b  5e                                pop    esi
0x5fea7c  8be5                              mov    esp,ebp
0x5fea7e  5d                                pop    ebp
0x5fea7f  c20400                            ret    0x4

### I09 QuestInventoryInside descriptor alloc110 and concrete vptr
VA 0x5fea90 RAW 0x1fde90 END 0x5feb42 SHA256 2b9716b9ca9c96b269924ff84de7e6a5c46b87d9aafeaf1451e38a2f0dc78338
0x5fea90  55                                push   ebp
0x5fea91  8bec                              mov    ebp,esp
0x5fea93  6aff                              push   0xffffffff
0x5fea95  6820189200                        push   0x921820
0x5fea9a  64a100000000                      mov    eax,fs:0x0
0x5feaa0  50                                push   eax
0x5feaa1  51                                push   ecx
0x5feaa2  53                                push   ebx
0x5feaa3  56                                push   esi
0x5feaa4  57                                push   edi
0x5feaa5  a1201fd600                        mov    eax,ds:0xd61f20
0x5feaaa  33c5                              xor    eax,ebp
0x5feaac  50                                push   eax
0x5feaad  8d45f4                            lea    eax,[ebp-0xc]
0x5feab0  64a300000000                      mov    fs:0x0,eax
0x5feab6  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x5feab9  33ff                              xor    edi,edi
0x5feabb  897b04                            mov    DWORD PTR [ebx+0x4],edi
0x5feabe  897b08                            mov    DWORD PTR [ebx+0x8],edi
0x5feac1  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x5feac4  6810010000                        push   0x110
0x5feac9  c703b492c200                      mov    DWORD PTR [ebx],0xc292b4
0x5feacf  e894352900                        call   0x892068
0x5fead4  8bf0                              mov    esi,eax
0x5fead6  83c404                            add    esp,0x4
0x5fead9  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5feadc  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5feae0  3bf7                              cmp    esi,edi
0x5feae2  743c                              je     0x5feb20
0x5feae4  8bce                              mov    ecx,esi
0x5feae6  e8f5791500                        call   0x7564e0
0x5feaeb  89beec000000                      mov    DWORD PTR [esi+0xec],edi
0x5feaf1  89bef0000000                      mov    DWORD PTR [esi+0xf0],edi
0x5feaf7  89bef4000000                      mov    DWORD PTR [esi+0xf4],edi
0x5feafd  89bef8000000                      mov    DWORD PTR [esi+0xf8],edi
0x5feb03  89befc000000                      mov    DWORD PTR [esi+0xfc],edi
0x5feb09  83c8ff                            or     eax,0xffffffff
0x5feb0c  898608010000                      mov    DWORD PTR [esi+0x108],eax
0x5feb12  89860c010000                      mov    DWORD PTR [esi+0x10c],eax
0x5feb18  c7069426c000                      mov    DWORD PTR [esi],0xc02694
0x5feb1e  eb02                              jmp    0x5feb22
0x5feb20  33f6                              xor    esi,esi
0x5feb22  89730c                            mov    DWORD PTR [ebx+0xc],esi
0x5feb25  c7430467000000                    mov    DWORD PTR [ebx+0x4],0x67
0x5feb2c  8bc3                              mov    eax,ebx
0x5feb2e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5feb31  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5feb38  59                                pop    ecx
0x5feb39  5f                                pop    edi
0x5feb3a  5e                                pop    esi
0x5feb3b  5b                                pop    ebx
0x5feb3c  8be5                              mov    esp,ebp
0x5feb3e  5d                                pop    ebp
0x5feb3f  c20400                            ret    0x4

### I10 CInventoryInsideWindow constructor and concrete vptr
VA 0x5fef40 RAW 0x1fe340 END 0x5ff148 SHA256 27ea196bf57950b20121749c7f0fdb32db0fa494d02ac9ee95383ed0bd01516d
0x5fef40  55                                push   ebp
0x5fef41  8bec                              mov    ebp,esp
0x5fef43  6aff                              push   0xffffffff
0x5fef45  68238f9200                        push   0x928f23
0x5fef4a  64a100000000                      mov    eax,fs:0x0
0x5fef50  50                                push   eax
0x5fef51  83ec08                            sub    esp,0x8
0x5fef54  53                                push   ebx
0x5fef55  56                                push   esi
0x5fef56  57                                push   edi
0x5fef57  a1201fd600                        mov    eax,ds:0xd61f20
0x5fef5c  33c5                              xor    eax,ebp
0x5fef5e  50                                push   eax
0x5fef5f  8d45f4                            lea    eax,[ebp-0xc]
0x5fef62  64a300000000                      mov    fs:0x0,eax
0x5fef68  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5fef6b  8bcf                              mov    ecx,edi
0x5fef6d  e86e751500                        call   0x7564e0
0x5fef72  33db                              xor    ebx,ebx
0x5fef74  899fec000000                      mov    DWORD PTR [edi+0xec],ebx
0x5fef7a  899ff0000000                      mov    DWORD PTR [edi+0xf0],ebx
0x5fef80  83c8ff                            or     eax,0xffffffff
0x5fef83  899ff4000000                      mov    DWORD PTR [edi+0xf4],ebx
0x5fef89  899ff8000000                      mov    DWORD PTR [edi+0xf8],ebx
0x5fef8f  899ffc000000                      mov    DWORD PTR [edi+0xfc],ebx
0x5fef95  898708010000                      mov    DWORD PTR [edi+0x108],eax
0x5fef9b  89870c010000                      mov    DWORD PTR [edi+0x10c],eax
0x5fefa1  8db714010000                      lea    esi,[edi+0x114]
0x5fefa7  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x5fefaa  56                                push   esi
0x5fefab  c7071493c200                      mov    DWORD PTR [edi],0xc29314
0x5fefb1  e84a821500                        call   0x757200
0x5fefb6  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5fefba  8d8f5c010000                      lea    ecx,[edi+0x15c]
0x5fefc0  66899f58010000                    mov    WORD PTR [edi+0x158],bx
0x5fefc7  53                                push   ebx
0x5fefc8  33c0                              xor    eax,eax
0x5fefca  c7411407000000                    mov    DWORD PTR [ecx+0x14],0x7
0x5fefd1  895910                            mov    DWORD PTR [ecx+0x10],ebx
0x5fefd4  68fcd1be00                        push   0xbed1fc
0x5fefd9  668901                            mov    WORD PTR [ecx],ax
0x5fefdc  e87f31e0ff                        call   0x402160
0x5fefe1  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x5fefe5  f6052c5bfe0001                    test   BYTE PTR ds:0xfe5b2c,0x1
0x5fefec  899f10010000                      mov    DWORD PTR [edi+0x110],ebx
0x5feff2  7526                              jne    0x5ff01a
0x5feff4  830d2c5bfe0001                    or     DWORD PTR ds:0xfe5b2c,0x1
0x5feffb  680c5bfe00                        push   0xfe5b0c
0x5ff000  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0x5ff004  e8375cf8ff                        call   0x584c40
0x5ff009  6870f3bc00                        push   0xbcf370
0x5ff00e  e807332900                        call   0x89231a
0x5ff013  83c404                            add    esp,0x4
0x5ff016  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x5ff01a  8d4df0                            lea    ecx,[ebp-0x10]
0x5ff01d  51                                push   ecx
0x5ff01e  8d45ec                            lea    eax,[ebp-0x14]
0x5ff021  b90c5bfe00                        mov    ecx,0xfe5b0c
0x5ff026  c745f0f1000000                    mov    DWORD PTR [ebp-0x10],0xf1
0x5ff02d  e8be50f7ff                        call   0x5740f0
0x5ff032  8b45ec                            mov    eax,DWORD PTR [ebp-0x14]
0x5ff035  3b05105bfe00                      cmp    eax,DWORD PTR ds:0xfe5b10
0x5ff03b  740d                              je     0x5ff04a
0x5ff03d  83782408                          cmp    DWORD PTR [eax+0x24],0x8
0x5ff041  8d4810                            lea    ecx,[eax+0x10]
0x5ff044  720a                              jb     0x5ff050
0x5ff046  8b09                              mov    ecx,DWORD PTR [ecx]
0x5ff048  eb06                              jmp    0x5ff050
0x5ff04a  cc                                int3
0x5ff04b  b9fcd1be00                        mov    ecx,0xbed1fc
0x5ff050  e8bb861500                        call   0x757710
0x5ff055  8d55ec                            lea    edx,[ebp-0x14]
0x5ff058  52                                push   edx
0x5ff059  8d4e28                            lea    ecx,[esi+0x28]
0x5ff05c  8d45f0                            lea    eax,[ebp-0x10]
0x5ff05f  895dec                            mov    DWORD PTR [ebp-0x14],ebx
0x5ff062  e8b98f2400                        call   0x848020
0x5ff067  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0x5ff06a  bb7cc2c3ff                        mov    ebx,0xffc3c27c
0x5ff06f  3b462c                            cmp    eax,DWORD PTR [esi+0x2c]
0x5ff072  7419                              je     0x5ff08d
0x5ff074  895818                            mov    DWORD PTR [eax+0x18],ebx
0x5ff077  c6401c01                          mov    BYTE PTR [eax+0x1c],0x1
0x5ff07b  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x5ff07e  8b4014                            mov    eax,DWORD PTR [eax+0x14]
0x5ff081  53                                push   ebx
0x5ff082  2bc1                              sub    eax,ecx
0x5ff084  50                                push   eax
0x5ff085  51                                push   ecx
0x5ff086  8bc6                              mov    eax,esi
0x5ff088  e813a11500                        call   0x7591a0
0x5ff08d  8d4dec                            lea    ecx,[ebp-0x14]
0x5ff090  51                                push   ecx
0x5ff091  8d4e28                            lea    ecx,[esi+0x28]
0x5ff094  8d45f0                            lea    eax,[ebp-0x10]
0x5ff097  c745ec01000000                    mov    DWORD PTR [ebp-0x14],0x1
0x5ff09e  e87d8f2400                        call   0x848020
0x5ff0a3  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0x5ff0a6  3b462c                            cmp    eax,DWORD PTR [esi+0x2c]
0x5ff0a9  7419                              je     0x5ff0c4
0x5ff0ab  895818                            mov    DWORD PTR [eax+0x18],ebx
0x5ff0ae  c6401c01                          mov    BYTE PTR [eax+0x1c],0x1
0x5ff0b2  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x5ff0b5  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x5ff0b8  53                                push   ebx
0x5ff0b9  2bd1                              sub    edx,ecx
0x5ff0bb  52                                push   edx
0x5ff0bc  51                                push   ecx
0x5ff0bd  8bc6                              mov    eax,esi
0x5ff0bf  e8dca01500                        call   0x7591a0
0x5ff0c4  8d45ec                            lea    eax,[ebp-0x14]
0x5ff0c7  50                                push   eax
0x5ff0c8  8d4e28                            lea    ecx,[esi+0x28]
0x5ff0cb  8d45f0                            lea    eax,[ebp-0x10]
0x5ff0ce  c745ec02000000                    mov    DWORD PTR [ebp-0x14],0x2
0x5ff0d5  e8468f2400                        call   0x848020
0x5ff0da  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0x5ff0dd  3b462c                            cmp    eax,DWORD PTR [esi+0x2c]
0x5ff0e0  7419                              je     0x5ff0fb
0x5ff0e2  895818                            mov    DWORD PTR [eax+0x18],ebx
0x5ff0e5  c6401c01                          mov    BYTE PTR [eax+0x1c],0x1
0x5ff0e9  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x5ff0ec  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x5ff0ef  53                                push   ebx
0x5ff0f0  2bd1                              sub    edx,ecx
0x5ff0f2  52                                push   edx
0x5ff0f3  51                                push   ecx
0x5ff0f4  8bc6                              mov    eax,esi
0x5ff0f6  e8a5a01500                        call   0x7591a0
0x5ff0fb  8d45ec                            lea    eax,[ebp-0x14]
0x5ff0fe  50                                push   eax
0x5ff0ff  8d4e28                            lea    ecx,[esi+0x28]
0x5ff102  8d45f0                            lea    eax,[ebp-0x10]
0x5ff105  c745ec03000000                    mov    DWORD PTR [ebp-0x14],0x3
0x5ff10c  e80f8f2400                        call   0x848020
0x5ff111  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0x5ff114  3b462c                            cmp    eax,DWORD PTR [esi+0x2c]
0x5ff117  7419                              je     0x5ff132
0x5ff119  895818                            mov    DWORD PTR [eax+0x18],ebx
0x5ff11c  c6401c01                          mov    BYTE PTR [eax+0x1c],0x1
0x5ff120  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x5ff123  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x5ff126  53                                push   ebx
0x5ff127  2bd1                              sub    edx,ecx
0x5ff129  52                                push   edx
0x5ff12a  51                                push   ecx
0x5ff12b  8bc6                              mov    eax,esi
0x5ff12d  e86ea01500                        call   0x7591a0
0x5ff132  8bc7                              mov    eax,edi
0x5ff134  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5ff137  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5ff13e  59                                pop    ecx
0x5ff13f  5f                                pop    edi
0x5ff140  5e                                pop    esi
0x5ff141  5b                                pop    ebx
0x5ff142  8be5                              mov    esp,ebp
0x5ff144  5d                                pop    ebp
0x5ff145  c20400                            ret    0x4

### I11 InventoryInside+1A8 native item state/cooldown UI loop
VA 0x603430 RAW 0x202830 END 0x603805 SHA256 44a8e939e6216e7784f0f32fdb151f73b91d9ad8818a8310a57ff63a4d0fd3aa
0x603430  55                                push   ebp
0x603431  8bec                              mov    ebp,esp
0x603433  83e4f8                            and    esp,0xfffffff8
0x603436  6aff                              push   0xffffffff
0x603438  685d6d9400                        push   0x946d5d
0x60343d  64a100000000                      mov    eax,fs:0x0
0x603443  50                                push   eax
0x603444  83ec38                            sub    esp,0x38
0x603447  53                                push   ebx
0x603448  56                                push   esi
0x603449  57                                push   edi
0x60344a  a1201fd600                        mov    eax,ds:0xd61f20
0x60344f  33c4                              xor    eax,esp
0x603451  50                                push   eax
0x603452  8d442448                          lea    eax,[esp+0x48]
0x603456  64a300000000                      mov    fs:0x0,eax
0x60345c  8bf1                              mov    esi,ecx
0x60345e  89742430                          mov    DWORD PTR [esp+0x30],esi
0x603462  8b06                              mov    eax,DWORD PTR [esi]
0x603464  8b9098010000                      mov    edx,DWORD PTR [eax+0x198]
0x60346a  33db                              xor    ebx,ebx
0x60346c  33ff                              xor    edi,edi
0x60346e  895c2418                          mov    DWORD PTR [esp+0x18],ebx
0x603472  ffd2                              call   edx
0x603474  85c0                              test   eax,eax
0x603476  7f1a                              jg     0x603492
0x603478  8b4c2448                          mov    ecx,DWORD PTR [esp+0x48]
0x60347c  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x603483  59                                pop    ecx
0x603484  5f                                pop    edi
0x603485  5e                                pop    esi
0x603486  5b                                pop    ebx
0x603487  8be5                              mov    esp,ebp
0x603489  5d                                pop    ebp
0x60348a  c3                                ret
0x60348b  eb03                              jmp    0x603490
0x60348d  8d4900                            lea    ecx,[ecx+0x0]
0x603490  33ff                              xor    edi,edi
0x603492  f605a8d9f80001                    test   BYTE PTR ds:0xf8d9a8,0x1
0x603499  8b86f4000000                      mov    eax,DWORD PTR [esi+0xf4]
0x60349f  8b1c98                            mov    ebx,DWORD PTR [eax+ebx*4]
0x6034a2  7573                              jne    0x603517
0x6034a4  830da8d9f80001                    or     DWORD PTR ds:0xf8d9a8,0x1
0x6034ab  897c2450                          mov    DWORD PTR [esp+0x50],edi
0x6034af  6a18                              push   0x18
0x6034b1  893db4d9f800                      mov    DWORD PTR ds:0xf8d9b4,edi
0x6034b7  e8acdd2800                        call   0x891268
0x6034bc  83c404                            add    esp,0x4
0x6034bf  3bc7                              cmp    eax,edi
0x6034c1  0f8415030000                      je     0x6037dc
0x6034c7  a3b0d9f800                        mov    ds:0xf8d9b0,eax
0x6034cc  8900                              mov    DWORD PTR [eax],eax
0x6034ce  a1b0d9f800                        mov    eax,ds:0xf8d9b0
0x6034d3  894004                            mov    DWORD PTR [eax+0x4],eax
0x6034d6  a1b0d9f800                        mov    eax,ds:0xf8d9b0
0x6034db  894008                            mov    DWORD PTR [eax+0x8],eax
0x6034de  8b0db0d9f800                      mov    ecx,DWORD PTR ds:0xf8d9b0
0x6034e4  c6411401                          mov    BYTE PTR [ecx+0x14],0x1
0x6034e8  8b15b0d9f800                      mov    edx,DWORD PTR ds:0xf8d9b0
0x6034ee  c6421501                          mov    BYTE PTR [edx+0x15],0x1
0x6034f2  68bcd9f800                        push   0xf8d9bc
0x6034f7  c644245401                        mov    BYTE PTR [esp+0x54],0x1
0x6034fc  e87fdbf1ff                        call   0x521080
0x603501  6850ccbc00                        push   0xbccc50
0x603506  e80fee2800                        call   0x89231a
0x60350b  83c404                            add    esp,0x4
0x60350e  83cfff                            or     edi,0xffffffff
0x603511  897c2450                          mov    DWORD PTR [esp+0x50],edi
0x603515  eb03                              jmp    0x60351a
0x603517  83cfff                            or     edi,0xffffffff
0x60351a  8b8350020000                      mov    eax,DWORD PTR [ebx+0x250]
0x603520  8d4c241c                          lea    ecx,[esp+0x1c]
0x603524  8944241c                          mov    DWORD PTR [esp+0x1c],eax
0x603528  51                                push   ecx
0x603529  8d442424                          lea    eax,[esp+0x24]
0x60352d  b9acd9f800                        mov    ecx,0xf8d9ac
0x603532  e889032400                        call   0x8438c0
0x603537  8b442420                          mov    eax,DWORD PTR [esp+0x20]
0x60353b  3b05b0d9f800                      cmp    eax,DWORD PTR ds:0xf8d9b0
0x603541  0f8461020000                      je     0x6037a8
0x603547  8b7010                            mov    esi,DWORD PTR [eax+0x10]
0x60354a  85f6                              test   esi,esi
0x60354c  0f8456020000                      je     0x6037a8
0x603552  83bbb402000000                    cmp    DWORD PTR [ebx+0x2b4],0x0
0x603559  0f8e8d000000                      jle    0x6035ec
0x60355f  f6059443f90001                    test   BYTE PTR ds:0xf94394,0x1
0x603566  7525                              jne    0x60358d
0x603568  830d9443f90001                    or     DWORD PTR ds:0xf94394,0x1
0x60356f  c744245002000000                  mov    DWORD PTR [esp+0x50],0x2
0x603577  e86408fcff                        call   0x5c3de0
0x60357c  6830ccbc00                        push   0xbccc30
0x603581  e894ed2800                        call   0x89231a
0x603586  83c404                            add    esp,0x4
0x603589  897c2450                          mov    DWORD PTR [esp+0x50],edi
0x60358d  8bbbb4020000                      mov    edi,DWORD PTR [ebx+0x2b4]
0x603593  b93c000000                        mov    ecx,0x3c
0x603598  2bcf                              sub    ecx,edi
0x60359a  b889888888                        mov    eax,0x88888889
0x60359f  f7e9                              imul   ecx
0x6035a1  03d1                              add    edx,ecx
0x6035a3  c1fa05                            sar    edx,0x5
0x6035a6  8bc2                              mov    eax,edx
0x6035a8  c1e81f                            shr    eax,0x1f
0x6035ab  03c2                              add    eax,edx
0x6035ad  8bd0                              mov    edx,eax
0x6035af  c1e204                            shl    edx,0x4
0x6035b2  2bd0                              sub    edx,eax
0x6035b4  03d2                              add    edx,edx
0x6035b6  03d2                              add    edx,edx
0x6035b8  2bca                              sub    ecx,edx
0x6035ba  894c241c                          mov    DWORD PTR [esp+0x1c],ecx
0x6035be  db44241c                          fild   DWORD PTR [esp+0x1c]
0x6035c2  dc35b85ac500                      fdiv   QWORD PTR ds:0xc55ab8
0x6035c8  dc0d8057c500                      fmul   QWORD PTR ds:0xc55780
0x6035ce  e83db72f00                        call   0x8fed10
0x6035d3  03c0                              add    eax,eax
0x6035d5  03c0                              add    eax,eax
0x6035d7  b9b044f900                        mov    ecx,0xf944b0
0x6035dc  2bc8                              sub    ecx,eax
0x6035de  8b31                              mov    esi,DWORD PTR [ecx]
0x6035e0  4f                                dec    edi
0x6035e1  89bbb4020000                      mov    DWORD PTR [ebx+0x2b4],edi
0x6035e7  e9bc000000                        jmp    0x6036a8
0x6035ec  f6054c74fb0001                    test   BYTE PTR ds:0xfb744c,0x1
0x6035f3  7525                              jne    0x60361a
0x6035f5  830d4c74fb0001                    or     DWORD PTR ds:0xfb744c,0x1
0x6035fc  c744245003000000                  mov    DWORD PTR [esp+0x50],0x3
0x603604  e857b6eeff                        call   0x4eec60
0x603609  6840d1bc00                        push   0xbcd140
0x60360e  e807ed2800                        call   0x89231a
0x603613  83c404                            add    esp,0x4
0x603616  897c2450                          mov    DWORD PTR [esp+0x50],edi
0x60361a  8a5670                            mov    dl,BYTE PTR [esi+0x70]
0x60361d  be5074fb00                        mov    esi,0xfb7450
0x603622  e8d9b4eeff                        call   0x4eeb00
0x603627  8bf0                              mov    esi,eax
0x603629  85f6                              test   esi,esi
0x60362b  7479                              je     0x6036a6
0x60362d  f6059443f90001                    test   BYTE PTR ds:0xf94394,0x1
0x603634  7525                              jne    0x60365b
0x603636  830d9443f90001                    or     DWORD PTR ds:0xf94394,0x1
0x60363d  c744245004000000                  mov    DWORD PTR [esp+0x50],0x4
0x603645  e89607fcff                        call   0x5c3de0
0x60364a  6830ccbc00                        push   0xbccc30
0x60364f  e8c6ec2800                        call   0x89231a
0x603654  83c404                            add    esp,0x4
0x603657  897c2450                          mov    DWORD PTR [esp+0x50],edi
0x60365b  0fb74602                          movzx  eax,WORD PTR [esi+0x2]
0x60365f  0fb73e                            movzx  edi,WORD PTR [esi]
0x603662  89442428                          mov    DWORD PTR [esp+0x28],eax
0x603666  99                                cdq
0x603667  f7ff                              idiv   edi
0x603669  897c2424                          mov    DWORD PTR [esp+0x24],edi
0x60366d  8954241c                          mov    DWORD PTR [esp+0x1c],edx
0x603671  db44241c                          fild   DWORD PTR [esp+0x1c]
0x603675  da742424                          fidiv  DWORD PTR [esp+0x24]
0x603679  dc0d8857c500                      fmul   QWORD PTR ds:0xc55788
0x60367f  e88cb62f00                        call   0x8fed10
0x603684  03c0                              add    eax,eax
0x603686  03c0                              add    eax,eax
0x603688  ba4844f900                        mov    edx,0xf94448
0x60368d  2bd0                              sub    edx,eax
0x60368f  8b442428                          mov    eax,DWORD PTR [esp+0x28]
0x603693  8b32                              mov    esi,DWORD PTR [edx]
0x603695  48                                dec    eax
0x603696  3bc7                              cmp    eax,edi
0x603698  750e                              jne    0x6036a8
0x60369a  c783b40200003c000000              mov    DWORD PTR [ebx+0x2b4],0x3c
0x6036a4  eb02                              jmp    0x6036a8
0x6036a6  33f6                              xor    esi,esi
0x6036a8  3bb3b8020000                      cmp    esi,DWORD PTR [ebx+0x2b8]
0x6036ae  744d                              je     0x6036fd
0x6036b0  8bbbac020000                      mov    edi,DWORD PTR [ebx+0x2ac]
0x6036b6  80bfa400000000                    cmp    BYTE PTR [edi+0xa4],0x0
0x6036bd  7428                              je     0x6036e7
0x6036bf  83bf9400000000                    cmp    DWORD PTR [edi+0x94],0x0
0x6036c6  741f                              je     0x6036e7
0x6036c8  8b8f94000000                      mov    ecx,DWORD PTR [edi+0x94]
0x6036ce  8b11                              mov    edx,DWORD PTR [ecx]
0x6036d0  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x6036d3  ffd0                              call   eax
0x6036d5  3d6bbf0000                        cmp    eax,0xbf6b
0x6036da  750b                              jne    0x6036e7
0x6036dc  8bbf94000000                      mov    edi,DWORD PTR [edi+0x94]
0x6036e2  e8197b1700                        call   0x77b200
0x6036e7  8b8bac020000                      mov    ecx,DWORD PTR [ebx+0x2ac]
0x6036ed  8b11                              mov    edx,DWORD PTR [ecx]
0x6036ef  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x6036f5  ffd0                              call   eax
0x6036f7  89b3b8020000                      mov    DWORD PTR [ebx+0x2b8],esi
0x6036fd  8bb358020000                      mov    esi,DWORD PTR [ebx+0x258]
0x603703  85f6                              test   esi,esi
0x603705  7439                              je     0x603740
0x603707  8b8ba8020000                      mov    ecx,DWORD PTR [ebx+0x2a8]
0x60370d  8b5128                            mov    edx,DWORD PTR [ecx+0x28]
0x603710  c1ea08                            shr    edx,0x8
0x603713  80e201                            and    dl,0x1
0x603716  88542417                          mov    BYTE PTR [esp+0x17],dl
0x60371a  e86189f1ff                        call   0x51c080
0x60371f  85c0                              test   eax,eax
0x603721  0f95c0                            setne  al
0x603724  807c241700                        cmp    BYTE PTR [esp+0x17],0x0
0x603729  0f95c1                            setne  cl
0x60372c  3ac8                              cmp    cl,al
0x60372e  7510                              jne    0x603740
0x603730  8b934c020000                      mov    edx,DWORD PTR [ebx+0x24c]
0x603736  8b8348020000                      mov    eax,DWORD PTR [ebx+0x248]
0x60373c  52                                push   edx
0x60373d  50                                push   eax
0x60373e  eb61                              jmp    0x6037a1
0x603740  8b8358020000                      mov    eax,DWORD PTR [ebx+0x258]
0x603746  85c0                              test   eax,eax
0x603748  745e                              je     0x6037a8
0x60374a  83786800                          cmp    DWORD PTR [eax+0x68],0x0
0x60374e  7458                              je     0x6037a8
0x603750  8b4068                            mov    eax,DWORD PTR [eax+0x68]
0x603753  85c0                              test   eax,eax
0x603755  7451                              je     0x6037a8
0x603757  0fb77808                          movzx  edi,WORD PTR [eax+0x8]
0x60375b  e84014e0ff                        call   0x404ba0
0x603760  8bb028690000                      mov    esi,DWORD PTR [eax+0x6928]
0x603766  8bcf                              mov    ecx,edi
0x603768  8d542428                          lea    edx,[esp+0x28]
0x60376c  894c2428                          mov    DWORD PTR [esp+0x28],ecx
0x603770  52                                push   edx
0x603771  8d4e10                            lea    ecx,[esi+0x10]
0x603774  8d442430                          lea    eax,[esp+0x30]
0x603778  e84315eaff                        call   0x4a4cc0
0x60377d  8b44242c                          mov    eax,DWORD PTR [esp+0x2c]
0x603781  3b4614                            cmp    eax,DWORD PTR [esi+0x14]
0x603784  740d                              je     0x603793
0x603786  8b4010                            mov    eax,DWORD PTR [eax+0x10]
0x603789  85c0                              test   eax,eax
0x60378b  7406                              je     0x603793
0x60378d  83780c00                          cmp    DWORD PTR [eax+0xc],0x0
0x603791  7515                              jne    0x6037a8
0x603793  8b834c020000                      mov    eax,DWORD PTR [ebx+0x24c]
0x603799  8b8b48020000                      mov    ecx,DWORD PTR [ebx+0x248]
0x60379f  50                                push   eax
0x6037a0  51                                push   ecx
0x6037a1  8bfb                              mov    edi,ebx
0x6037a3  e8a898fdff                        call   0x5dd050
0x6037a8  8b742430                          mov    esi,DWORD PTR [esp+0x30]
0x6037ac  8b5c2418                          mov    ebx,DWORD PTR [esp+0x18]
0x6037b0  8b16                              mov    edx,DWORD PTR [esi]
0x6037b2  8b8298010000                      mov    eax,DWORD PTR [edx+0x198]
0x6037b8  43                                inc    ebx
0x6037b9  8bce                              mov    ecx,esi
0x6037bb  895c2418                          mov    DWORD PTR [esp+0x18],ebx
0x6037bf  ffd0                              call   eax
0x6037c1  3bd8                              cmp    ebx,eax
0x6037c3  0f8cc7fcffff                      jl     0x603490
0x6037c9  8b4c2448                          mov    ecx,DWORD PTR [esp+0x48]
0x6037cd  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x6037d4  59                                pop    ecx
0x6037d5  5f                                pop    edi
0x6037d6  5e                                pop    esi
0x6037d7  5b                                pop    ebx
0x6037d8  8be5                              mov    esp,ebp
0x6037da  5d                                pop    ebp
0x6037db  c3                                ret
0x6037dc  8d4c2434                          lea    ecx,[esp+0x34]
0x6037e0  51                                push   ecx
0x6037e1  8d4c243c                          lea    ecx,[esp+0x3c]
0x6037e5  897c2438                          mov    DWORD PTR [esp+0x38],edi
0x6037e9  e8bbd82800                        call   0x8910a9
0x6037ee  68a857c800                        push   0xc857a8
0x6037f3  8d54243c                          lea    edx,[esp+0x3c]
0x6037f7  52                                push   edx
0x6037f8  c7442440a42cbd00                  mov    DWORD PTR [esp+0x40],0xbd2ca4
0x603800  e8eb912900                        call   0x89c9f0

### I12 InventoryInside+198 returns100 displayed slots
VA 0x603810 RAW 0x202c10 END 0x603816 SHA256 76fc033e4b81818e8751a7c71ffbea9dbbf2e91f49f13425ac6f0c80a5f36ca5
0x603810  b864000000                        mov    eax,0x64
0x603815  c3                                ret

### I13 QuestInventoryInside+1A8 empty native target
VA 0x5f5d10 RAW 0x1f5110 END 0x5f5d11 SHA256 ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e
0x5f5d10  c3                                ret

### I14 InventoryDialog+1AC returns1; onload allocates1+1 panel slots
VA 0x87af60 RAW 0x47a360 END 0x87af66 SHA256 2db31f4e09597946e56e859813bfdad7046d457c32332c3a882654d1e3ffdf67
0x87af60  b801000000                        mov    eax,0x1
0x87af65  c3                                ret

### I15 native vector resize zero-initializes newly added panel slots
VA 0x5f7e40 RAW 0x1f7240 END 0x5f7ea5 SHA256 9f85c57b86c7350a23804655e462b0e611b58fc5e25074e4f0904a1a220dccad
0x5f7e40  55                                push   ebp
0x5f7e41  8bec                              mov    ebp,esp
0x5f7e43  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
0x5f7e46  8b16                              mov    edx,DWORD PTR [esi]
0x5f7e48  8bc1                              mov    eax,ecx
0x5f7e4a  2bc2                              sub    eax,edx
0x5f7e4c  53                                push   ebx
0x5f7e4d  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x5f7e50  c1f802                            sar    eax,0x2
0x5f7e53  57                                push   edi
0x5f7e54  3bc3                              cmp    eax,ebx
0x5f7e56  7614                              jbe    0x5f7e6c
0x5f7e58  51                                push   ecx
0x5f7e59  8d049a                            lea    eax,[edx+ebx*4]
0x5f7e5c  50                                push   eax
0x5f7e5d  56                                push   esi
0x5f7e5e  8d7d08                            lea    edi,[ebp+0x8]
0x5f7e61  e85a0ae1ff                        call   0x4088c0
0x5f7e66  5f                                pop    edi
0x5f7e67  5b                                pop    ebx
0x5f7e68  5d                                pop    ebp
0x5f7e69  c20400                            ret    0x4
0x5f7e6c  7331                              jae    0x5f7e9f
0x5f7e6e  8bcb                              mov    ecx,ebx
0x5f7e70  2bc8                              sub    ecx,eax
0x5f7e72  8bc6                              mov    eax,esi
0x5f7e74  e8c7e30d00                        call   0x6d6240
0x5f7e79  8b7e04                            mov    edi,DWORD PTR [esi+0x4]
0x5f7e7c  8bc7                              mov    eax,edi
0x5f7e7e  2b06                              sub    eax,DWORD PTR [esi]
0x5f7e80  8bcb                              mov    ecx,ebx
0x5f7e82  c1f802                            sar    eax,0x2
0x5f7e85  2bc8                              sub    ecx,eax
0x5f7e87  7404                              je     0x5f7e8d
0x5f7e89  33c0                              xor    eax,eax
0x5f7e8b  f3ab                              rep stos DWORD PTR es:[edi],eax
0x5f7e8d  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x5f7e90  8bc8                              mov    ecx,eax
0x5f7e92  2b0e                              sub    ecx,DWORD PTR [esi]
0x5f7e94  c1f902                            sar    ecx,0x2
0x5f7e97  2bd9                              sub    ebx,ecx
0x5f7e99  8d1498                            lea    edx,[eax+ebx*4]
0x5f7e9c  895604                            mov    DWORD PTR [esi+0x4],edx
0x5f7e9f  5f                                pop    edi
0x5f7ea0  5b                                pop    ebx
0x5f7ea1  5d                                pop    ebp
0x5f7ea2  c20400                            ret    0x4

### A01 Mission alliance panel singleton descriptor FE2DB8
VA 0x5adc60 RAW 0x1ad060 END 0x5add34 SHA256 1e6800d36b8342fdf15d1d9add3a9f2d4c9842aaa29ebe3459b357c098f7360d
0x5adc60  55                                push   ebp
0x5adc61  8bec                              mov    ebp,esp
0x5adc63  6aff                              push   0xffffffff
0x5adc65  6849e69100                        push   0x91e649
0x5adc6a  64a100000000                      mov    eax,fs:0x0
0x5adc70  50                                push   eax
0x5adc71  83ec08                            sub    esp,0x8
0x5adc74  56                                push   esi
0x5adc75  57                                push   edi
0x5adc76  a1201fd600                        mov    eax,ds:0xd61f20
0x5adc7b  33c5                              xor    eax,ebp
0x5adc7d  50                                push   eax
0x5adc7e  8d45f4                            lea    eax,[ebp-0xc]
0x5adc81  64a300000000                      mov    fs:0x0,eax
0x5adc87  a1b82dfe00                        mov    eax,ds:0xfe2db8
0x5adc8c  85c0                              test   eax,eax
0x5adc8e  0f858f000000                      jne    0x5add23
0x5adc94  6a10                              push   0x10
0x5adc96  e8cd352e00                        call   0x891268
0x5adc9b  83c404                            add    esp,0x4
0x5adc9e  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5adca1  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5adca8  85c0                              test   eax,eax
0x5adcaa  7408                              je     0x5adcb4
0x5adcac  50                                push   eax
0x5adcad  e85e090000                        call   0x5ae610
0x5adcb2  eb02                              jmp    0x5adcb6
0x5adcb4  33c0                              xor    eax,eax
0x5adcb6  83ceff                            or     esi,0xffffffff
0x5adcb9  8bc8                              mov    ecx,eax
0x5adcbb  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5adcbe  b801000000                        mov    eax,0x1
0x5adcc3  890db82dfe00                      mov    DWORD PTR ds:0xfe2db8,ecx
0x5adcc9  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x5adccf  7524                              jne    0x5adcf5
0x5adcd1  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x5adcd7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5adcda  e8d102eaff                        call   0x44dfb0
0x5adcdf  6810cdbc00                        push   0xbccd10
0x5adce4  e831462e00                        call   0x89231a
0x5adce9  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5adcec  8b0db82dfe00                      mov    ecx,DWORD PTR ds:0xfe2db8
0x5adcf2  83c404                            add    esp,0x4
0x5adcf5  8b01                              mov    eax,DWORD PTR [ecx]
0x5adcf7  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x5adcfa  8bf1                              mov    esi,ecx
0x5adcfc  ffd2                              call   edx
0x5adcfe  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x5add01  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5add04  8d7dec                            lea    edi,[ebp-0x14]
0x5add07  beecaffa00                        mov    esi,0xfaafec
0x5add0c  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5add0f  e80c12fdff                        call   0x57ef20
0x5add14  50                                push   eax
0x5add15  56                                push   esi
0x5add16  8d75ec                            lea    esi,[ebp-0x14]
0x5add19  e8e2142800                        call   0x82f200
0x5add1e  a1b82dfe00                        mov    eax,ds:0xfe2db8
0x5add23  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5add26  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5add2d  59                                pop    ecx
0x5add2e  5f                                pop    edi
0x5add2f  5e                                pop    esi
0x5add30  8be5                              mov    esp,ebp
0x5add32  5d                                pop    ebp
0x5add33  c3                                ret

### A02 Alliance descriptor alloc98 and concrete C383F4 vptr
VA 0x5ae610 RAW 0x1ada10 END 0x5ae6c3 SHA256 9b262785ae389ba533bf8cb540196565675a94a5718b5f1c354c3bd587b4384e
0x5ae610  55                                push   ebp
0x5ae611  8bec                              mov    ebp,esp
0x5ae613  6aff                              push   0xffffffff
0x5ae615  6820ae9100                        push   0x91ae20
0x5ae61a  64a100000000                      mov    eax,fs:0x0
0x5ae620  50                                push   eax
0x5ae621  51                                push   ecx
0x5ae622  56                                push   esi
0x5ae623  57                                push   edi
0x5ae624  a1201fd600                        mov    eax,ds:0xd61f20
0x5ae629  33c5                              xor    eax,ebp
0x5ae62b  50                                push   eax
0x5ae62c  8d45f4                            lea    eax,[ebp-0xc]
0x5ae62f  64a300000000                      mov    fs:0x0,eax
0x5ae635  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5ae638  c7470400000000                    mov    DWORD PTR [edi+0x4],0x0
0x5ae63f  c7470800000000                    mov    DWORD PTR [edi+0x8],0x0
0x5ae646  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5ae64d  6898000000                        push   0x98
0x5ae652  c70758d3c100                      mov    DWORD PTR [edi],0xc1d358
0x5ae658  e80b3a2e00                        call   0x892068
0x5ae65d  8bf0                              mov    esi,eax
0x5ae65f  83c404                            add    esp,0x4
0x5ae662  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5ae665  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5ae669  85f6                              test   esi,esi
0x5ae66b  7435                              je     0x5ae6a2
0x5ae66d  8bce                              mov    ecx,esi
0x5ae66f  e87c6b1900                        call   0x7451f0
0x5ae674  33c0                              xor    eax,eax
0x5ae676  c706f483c300                      mov    DWORD PTR [esi],0xc383f4
0x5ae67c  898680000000                      mov    DWORD PTR [esi+0x80],eax
0x5ae682  898684000000                      mov    DWORD PTR [esi+0x84],eax
0x5ae688  898688000000                      mov    DWORD PTR [esi+0x88],eax
0x5ae68e  89868c000000                      mov    DWORD PTR [esi+0x8c],eax
0x5ae694  898690000000                      mov    DWORD PTR [esi+0x90],eax
0x5ae69a  898694000000                      mov    DWORD PTR [esi+0x94],eax
0x5ae6a0  eb02                              jmp    0x5ae6a4
0x5ae6a2  33f6                              xor    esi,esi
0x5ae6a4  89770c                            mov    DWORD PTR [edi+0xc],esi
0x5ae6a7  c7470416000000                    mov    DWORD PTR [edi+0x4],0x16
0x5ae6ae  8bc7                              mov    eax,edi
0x5ae6b0  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5ae6b3  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5ae6ba  59                                pop    ecx
0x5ae6bb  5f                                pop    edi
0x5ae6bc  5e                                pop    esi
0x5ae6bd  8be5                              mov    esp,ebp
0x5ae6bf  5d                                pop    ebp
0x5ae6c0  c20400                            ret    0x4

### A03 Alliance panel onload creates three child slots
VA 0x6926b0 RAW 0x291ab0 END 0x6927a4 SHA256 f73ff75d2f8c10dc0cb874cc79fef791531a2686d37e44e0ef63778fa7e1c122
0x6926b0  55                                push   ebp
0x6926b1  8bec                              mov    ebp,esp
0x6926b3  6aff                              push   0xffffffff
0x6926b5  68e0119200                        push   0x9211e0
0x6926ba  64a100000000                      mov    eax,fs:0x0
0x6926c0  50                                push   eax
0x6926c1  83ec14                            sub    esp,0x14
0x6926c4  53                                push   ebx
0x6926c5  56                                push   esi
0x6926c6  57                                push   edi
0x6926c7  a1201fd600                        mov    eax,ds:0xd61f20
0x6926cc  33c5                              xor    eax,ebp
0x6926ce  50                                push   eax
0x6926cf  8d45f4                            lea    eax,[ebp-0xc]
0x6926d2  64a300000000                      mov    fs:0x0,eax
0x6926d8  8bf1                              mov    esi,ecx
0x6926da  33c0                              xor    eax,eax
0x6926dc  8945e4                            mov    DWORD PTR [ebp-0x1c],eax
0x6926df  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x6926e2  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x6926e5  c745e00c92c100                    mov    DWORD PTR [ebp-0x20],0xc1920c
0x6926ec  390570fcf700                      cmp    DWORD PTR ds:0xf7fc70,eax
0x6926f2  7405                              je     0x6926f9
0x6926f4  a370fcf700                        mov    ds:0xf7fc70,eax
0x6926f9  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x692700  8d9e8c000000                      lea    ebx,[esi+0x8c]
0x692706  e825030000                        call   0x692a30
0x69270b  53                                push   ebx
0x69270c  8bc8                              mov    ecx,eax
0x69270e  8d7de0                            lea    edi,[ebp-0x20]
0x692711  e82a78f1ff                        call   0x5a9f40
0x692716  e8f5030000                        call   0x692b10
0x69271b  8d8e90000000                      lea    ecx,[esi+0x90]
0x692721  51                                push   ecx
0x692722  8bc8                              mov    ecx,eax
0x692724  e81778f1ff                        call   0x5a9f40
0x692729  e8c2040000                        call   0x692bf0
0x69272e  8d9694000000                      lea    edx,[esi+0x94]
0x692734  52                                push   edx
0x692735  8bc8                              mov    ecx,eax
0x692737  e80478f1ff                        call   0x5a9f40
0x69273c  56                                push   esi
0x69273d  8bf7                              mov    esi,edi
0x69273f  e82c8fd7ff                        call   0x40b670
0x692744  8bf3                              mov    esi,ebx
0x692746  bf03000000                        mov    edi,0x3
0x69274b  eb03                              jmp    0x692750
0x69274d  8d4900                            lea    ecx,[ecx+0x0]
0x692750  8b4ef4                            mov    ecx,DWORD PTR [esi-0xc]
0x692753  8b01                              mov    eax,DWORD PTR [ecx]
0x692755  8b16                              mov    edx,DWORD PTR [esi]
0x692757  8b4070                            mov    eax,DWORD PTR [eax+0x70]
0x69275a  52                                push   edx
0x69275b  ffd0                              call   eax
0x69275d  8b06                              mov    eax,DWORD PTR [esi]
0x69275f  c780b000000000000000              mov    DWORD PTR [eax+0xb0],0x0
0x692769  8b0e                              mov    ecx,DWORD PTR [esi]
0x69276b  8b11                              mov    edx,DWORD PTR [ecx]
0x69276d  8b82d0000000                      mov    eax,DWORD PTR [edx+0xd0]
0x692773  ffd0                              call   eax
0x692775  83c604                            add    esi,0x4
0x692778  4f                                dec    edi
0x692779  75d5                              jne    0x692750
0x69277b  8b45e4                            mov    eax,DWORD PTR [ebp-0x1c]
0x69277e  c745e0e429bf00                    mov    DWORD PTR [ebp-0x20],0xbf29e4
0x692785  85c0                              test   eax,eax
0x692787  7409                              je     0x692792
0x692789  50                                push   eax
0x69278a  e87dea1f00                        call   0x89120c
0x69278f  83c404                            add    esp,0x4
0x692792  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x692795  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x69279c  59                                pop    ecx
0x69279d  5f                                pop    edi
0x69279e  5e                                pop    esi
0x69279f  5b                                pop    ebx
0x6927a0  8be5                              mov    esp,ebp
0x6927a2  5d                                pop    ebp
0x6927a3  c3                                ret

### A04 Alliance tick selects at most3 non-self roster members and toggles child UI
VA 0x6928b0 RAW 0x291cb0 END 0x692a27 SHA256 649975d548710723c4dcd1b9d57d63969766dd680e6a8ed10a1030a0c1c7d5f1
0x6928b0  55                                push   ebp
0x6928b1  8bec                              mov    ebp,esp
0x6928b3  83e4f8                            and    esp,0xfffffff8
0x6928b6  6aff                              push   0xffffffff
0x6928b8  687c5b9400                        push   0x945b7c
0x6928bd  64a100000000                      mov    eax,fs:0x0
0x6928c3  50                                push   eax
0x6928c4  83ec18                            sub    esp,0x18
0x6928c7  53                                push   ebx
0x6928c8  56                                push   esi
0x6928c9  57                                push   edi
0x6928ca  a1201fd600                        mov    eax,ds:0xd61f20
0x6928cf  33c4                              xor    eax,esp
0x6928d1  50                                push   eax
0x6928d2  8d442428                          lea    eax,[esp+0x28]
0x6928d6  64a300000000                      mov    fs:0x0,eax
0x6928dc  8bf9                              mov    edi,ecx
0x6928de  897c2420                          mov    DWORD PTR [esp+0x20],edi
0x6928e2  f6057813fb0001                    test   BYTE PTR ds:0xfb1378,0x1
0x6928e9  7529                              jne    0x692914
0x6928eb  830d7813fb0001                    or     DWORD PTR ds:0xfb1378,0x1
0x6928f2  c744243000000000                  mov    DWORD PTR [esp+0x30],0x0
0x6928fa  e82173eaff                        call   0x539c20
0x6928ff  68b0cfbc00                        push   0xbccfb0
0x692904  e811fa1f00                        call   0x89231a
0x692909  83c404                            add    esp,0x4
0x69290c  c7442430ffffffff                  mov    DWORD PTR [esp+0x30],0xffffffff
0x692914  8b155872fb00                      mov    edx,DWORD PTR ds:0xfb7258
0x69291a  33db                              xor    ebx,ebx
0x69291c  89542414                          mov    DWORD PTR [esp+0x14],edx
0x692920  85d2                              test   edx,edx
0x692922  0f84c1000000                      je     0x6929e9
0x692928  8b4a2c                            mov    ecx,DWORD PTR [edx+0x2c]
0x69292b  2b4a28                            sub    ecx,DWORD PTR [edx+0x28]
0x69292e  33c0                              xor    eax,eax
0x692930  c1f902                            sar    ecx,0x2
0x692933  894c241c                          mov    DWORD PTR [esp+0x1c],ecx
0x692937  89442418                          mov    DWORD PTR [esp+0x18],eax
0x69293b  85c9                              test   ecx,ecx
0x69293d  0f84a6000000                      je     0x6929e9
0x692943  81c78c000000                      add    edi,0x8c
0x692949  83fb03                            cmp    ebx,0x3
0x69294c  0f8dc2000000                      jge    0x692a14
0x692952  8b722c                            mov    esi,DWORD PTR [edx+0x2c]
0x692955  2b7228                            sub    esi,DWORD PTR [edx+0x28]
0x692958  c1fe02                            sar    esi,0x2
0x69295b  3bc6                              cmp    eax,esi
0x69295d  737d                              jae    0x6929dc
0x69295f  8b7228                            mov    esi,DWORD PTR [edx+0x28]
0x692962  8b3486                            mov    esi,DWORD PTR [esi+eax*4]
0x692965  807e0a00                          cmp    BYTE PTR [esi+0xa],0x0
0x692969  7471                              je     0x6929dc
0x69296b  85f6                              test   esi,esi
0x69296d  746d                              je     0x6929dc
0x69296f  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
0x692976  7531                              jne    0x6929a9
0x692978  b801000000                        mov    eax,0x1
0x69297d  09059043f900                      or     DWORD PTR ds:0xf94390,eax
0x692983  89442430                          mov    DWORD PTR [esp+0x30],eax
0x692987  e804ece4ff                        call   0x4e1590
0x69298c  6880ccbc00                        push   0xbccc80
0x692991  e884f91f00                        call   0x89231a
0x692996  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x69299a  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
0x69299e  83c404                            add    esp,0x4
0x6929a1  c7442430ffffffff                  mov    DWORD PTR [esp+0x30],0xffffffff
0x6929a9  8b36                              mov    esi,DWORD PTR [esi]
0x6929ab  8b542414                          mov    edx,DWORD PTR [esp+0x14]
0x6929af  3b353039f900                      cmp    esi,DWORD PTR ds:0xf93930
0x6929b5  7425                              je     0x6929dc
0x6929b7  8b07                              mov    eax,DWORD PTR [edi]
0x6929b9  e8e2150000                        call   0x693fa0
0x6929be  8b0f                              mov    ecx,DWORD PTR [edi]
0x6929c0  8b01                              mov    eax,DWORD PTR [ecx]
0x6929c2  8b9094000000                      mov    edx,DWORD PTR [eax+0x94]
0x6929c8  6a01                              push   0x1
0x6929ca  ffd2                              call   edx
0x6929cc  8b542414                          mov    edx,DWORD PTR [esp+0x14]
0x6929d0  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
0x6929d4  8b442418                          mov    eax,DWORD PTR [esp+0x18]
0x6929d8  43                                inc    ebx
0x6929d9  83c704                            add    edi,0x4
0x6929dc  40                                inc    eax
0x6929dd  89442418                          mov    DWORD PTR [esp+0x18],eax
0x6929e1  3bc1                              cmp    eax,ecx
0x6929e3  0f8260ffffff                      jb     0x692949
0x6929e9  83fb03                            cmp    ebx,0x3
0x6929ec  7d26                              jge    0x692a14
0x6929ee  8b442420                          mov    eax,DWORD PTR [esp+0x20]
0x6929f2  bf03000000                        mov    edi,0x3
0x6929f7  8db4988c000000                    lea    esi,[eax+ebx*4+0x8c]
0x6929fe  2bfb                              sub    edi,ebx
0x692a00  8b0e                              mov    ecx,DWORD PTR [esi]
0x692a02  8b11                              mov    edx,DWORD PTR [ecx]
0x692a04  8b8294000000                      mov    eax,DWORD PTR [edx+0x94]
0x692a0a  6a00                              push   0x0
0x692a0c  ffd0                              call   eax
0x692a0e  83c604                            add    esi,0x4
0x692a11  4f                                dec    edi
0x692a12  75ec                              jne    0x692a00
0x692a14  8b4c2428                          mov    ecx,DWORD PTR [esp+0x28]
0x692a18  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x692a1f  59                                pop    ecx
0x692a20  5f                                pop    edi
0x692a21  5e                                pop    esi
0x692a22  5b                                pop    ebx
0x692a23  8be5                              mov    esp,ebp
0x692a25  5d                                pop    ebp
0x692a26  c3                                ret

### A05 selected roster child native value assignment and status widget refresh
VA 0x693fa0 RAW 0x2933a0 END 0x693fff SHA256 cb1cb12d1877367ba2be43799e831499f84b7f52f9b5ab3cace14407f793d7b1
0x693fa0  57                                push   edi
0x693fa1  8bf8                              mov    edi,eax
0x693fa3  8b87b0000000                      mov    eax,DWORD PTR [edi+0xb0]
0x693fa9  85c0                              test   eax,eax
0x693fab  7509                              jne    0x693fb6
0x693fad  8bce                              mov    ecx,esi
0x693faf  e80c010000                        call   0x6940c0
0x693fb4  eb0d                              jmp    0x693fc3
0x693fb6  83f801                            cmp    eax,0x1
0x693fb9  7508                              jne    0x693fc3
0x693fbb  57                                push   edi
0x693fbc  8bce                              mov    ecx,esi
0x693fbe  e88d070000                        call   0x694750
0x693fc3  8b8780000000                      mov    eax,DWORD PTR [edi+0x80]
0x693fc9  89b7b4000000                      mov    DWORD PTR [edi+0xb4],esi
0x693fcf  89b094010000                      mov    DWORD PTR [eax+0x194],esi
0x693fd5  8b87ac000000                      mov    eax,DWORD PTR [edi+0xac]
0x693fdb  8b8fb4000000                      mov    ecx,DWORD PTR [edi+0xb4]
0x693fe1  8988e0000000                      mov    DWORD PTR [eax+0xe0],ecx
0x693fe7  c780dc00000002000000              mov    DWORD PTR [eax+0xdc],0x2
0x693ff1  8b97ac000000                      mov    edx,DWORD PTR [edi+0xac]
0x693ff7  52                                push   edx
0x693ff8  e86372ffff                        call   0x68b260
0x693ffd  5f                                pop    edi
0x693ffe  c3                                ret

### V_CMissionField vtable/COL pointer CMissionField
VA 0xc07058 RAW 0x805658 END 0xc07084 SHA256 75f6a6c3729b4975c8c4fb7d73979d24b63dca3c1868930ae18b5face4ce785e
889ac60040594c0070464c0010284200f027420050c74b0010bf4b006030420090db4a0020dc4a0090484c00

### C_CMissionField RTTI COL CMissionField
VA 0xc69a88 RAW 0x868088 END 0xc69a9c SHA256 7c80caf43078914f34f0826513b4262211ed4b57a12d69933f6a68eedd15f350
00000000000000000000000060e0f7009c9ac600

### T_CMissionField RTTI type descriptor CMissionField
VA 0xf7e060 RAW 0xb7b860 END 0xf7e082 SHA256 47647aca74ada0df592bad63e1e65a35a85ac059c83302765562980cb676bc74
f435bd00000000002e3f4156434d697373696f6e4669656c64405363656e65404000

### V_CScenarioField vtable/COL pointer CScenarioField
VA 0xc073b0 RAW 0x8059b0 END 0xc073dc SHA256 af10796c20ee32a0409d73d0c4f8c0dc4b466ea43fc24752b6b2dbe5bf504e65
b49dc60040594c0070464c0010284200f027420050474c00f0c28d0010db4a0090db4a0020dc4a0090484c00

### C_CScenarioField RTTI COL CScenarioField
VA 0xc69db4 RAW 0x8683b4 END 0xc69dc8 SHA256 ff124ddaba4212fcfd89b7bf88fe990df3978afdaa51673d24373b570e86a2bc
000000000000000000000000bce1f700c89dc600

### T_CScenarioField RTTI type descriptor CScenarioField
VA 0xf7e1bc RAW 0xb7b9bc END 0xf7e1df SHA256 a663ff0c03ccb4acb4ca1d5f1a3d532bc2aeb7e65faa56b837954b1cc421d2fc
f435bd00000000002e3f4156435363656e6172696f4669656c64405363656e65404000

### V_CCheckPointMgr vtable/COL pointer CCheckPointMgr
VA 0xc0f864 RAW 0x80de64 END 0xc0f86c SHA256 8321403987973ec4645bafe008e87dec46e1b413bbbee76c200de2bb1b158e40
34c5c60090485400

### C_CCheckPointMgr RTTI COL CCheckPointMgr
VA 0xc6c534 RAW 0x86ab34 END 0xc6c548 SHA256 5af72ddf5082e11283ad87c55160c6e541e0a51ac6eef6dfda1f4b88526a5802
00000000000000000000000014f5f70048c5c600

### T_CCheckPointMgr RTTI type descriptor CCheckPointMgr
VA 0xf7f514 RAW 0xb7cd14 END 0xf7f531 SHA256 fcb3e956ad6238070bac200f7e436c7c8365695d3b7ccdab935a8667aab12e20
f435bd00000000002e3f415643436865636b506f696e744d6772404000

### V_CCheckPoint vtable/COL pointer CCheckPoint
VA 0xc0f7f8 RAW 0x80ddf8 END 0xc0f860 SHA256 082511827b8b62e3ab86b8cf17104065ef9b7ffaba0e1a36988dc70eb2e67740
d0c4c600d0c04c0040a84c0080a84c00f0c28d00c0af4c00e0af4c00f0c28d00f0c28d0000b04c0020b04c0050b04c0070a84c0010af4c0060af870030ab4c00b06f4c00d06f4c0080ab4c00c0ac4c00908f4c0000a74c00e0ab4c0070b04c0030b14c0040ad4c00

### C_CCheckPoint RTTI COL CCheckPoint
VA 0xc6c4d0 RAW 0x86aad0 END 0xc6c4e4 SHA256 8e18e75824394d98ce5c837028d96724a0d0ff698d0ad43cb6a5f3ca1fda89f6
000000000000000000000000d8f4f700e4c4c600

### T_CCheckPoint RTTI type descriptor CCheckPoint
VA 0xf7f4d8 RAW 0xb7ccd8 END 0xf7f4f2 SHA256 c4f30db2ad2037696a24e302c9c1629a9e172ff56eeae89e288f7ecf5f28213d
f435bd00000000002e3f415643436865636b506f696e74404000

### V_CMissionFieldPage vtable/COL pointer CMissionFieldPage
VA 0xc1d1a8 RAW 0x81b7a8 END 0xc1d354 SHA256 4886eb6c227e275ff69454802506f0301e6754032266ec883115aa14c7a2a03d
e8fbc600203f4200103f4200103f4200003f4200e03d4000408c74006094740000ce5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550080d85a00e0674000d0877400f08774001088740010887400105d5f00a0ce5a0050d05a0010ae4900105d5f00f0ab590070ad5900f0ae590070b0590030d25900105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900a0d65a00806b590090c55a00c0c55a0010d55a0030d65a00f0cd590030ce590090d65a00

### C_CMissionFieldPage RTTI COL CMissionFieldPage
VA 0xc6fbe8 RAW 0x86e1e8 END 0xc6fbfc SHA256 1a02c243a5866c24cb623d3b824cc8c3f7a4cc2997c74a47b651f8fe2ee1c177
0000000000000000000000009818f800fcfbc600

### T_CMissionFieldPage RTTI type descriptor CMissionFieldPage
VA 0xf81898 RAW 0xb7f098 END 0xf818bc SHA256 68e02dd91919b515d5e7ea05e1fea1787f2a7d4ff0114141aff24640a7fd6315
f435bd00000000002e3f4156434d697373696f6e4669656c645061676540465549404000

### V_CScenarioFieldPage vtable/COL pointer CScenarioFieldPage
VA 0xc1d628 RAW 0x81bc28 END 0xc1d7d4 SHA256 d63a312403d6292227e6d53196662cbb22e96b3e23453a7c9c61ca30ec66ffca
2cfec600203f4200103f4200103f4200003f4200e03d4000408c74006094740020ea5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550010ff5a00e0674000d0877400f08774001088740010887400105d5f0030fc5a00c0fd5a0010ae4900105d5f00f0ab590070ad5900f0ae590070b0590030d25900105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900b0fe5a00806b590090c55a00c0c55a0060fe5a0070fe5a00f0cd590030ce590060015b00

### C_CScenarioFieldPage RTTI COL CScenarioFieldPage
VA 0xc6fe2c RAW 0x86e42c END 0xc6fe40 SHA256 7e496ac560476a542bf82d8ed3a00be9f5d258221a61de033783bc7a648f0f98
000000000000000000000000281af80040fec600

### T_CScenarioFieldPage RTTI type descriptor CScenarioFieldPage
VA 0xf81a28 RAW 0xb7f228 END 0xf81a4d SHA256 c4fea19adb1af17d587e6645283bbb22f83696b37c108fbd9a9d21cf2653ef64
f435bd00000000002e3f4156435363656e6172696f4669656c645061676540465549404000

### V_CBottomMenuFrameField vtable/COL pointer CBottomMenuFrameField
VA 0xc21b60 RAW 0x820160 END 0xc21d00 SHA256 89d0be2a72c18c52e592fd43f9dc9228a613657fdb74f14a72b0fe9617b6a9c5
4823c700e0824800508e4000508e4000408e4000e03d4000e06675004067750050475d00e08d4000308d4000a08c4000c063750030557400f0567400d0af7500205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b740080707500703d4000d05a7400205b74004070750000707500f0a07400503d4000b03d4000403d400050045500e0674000e0674000d0877400f08774006071750060717500a0475d00b0475d00b0485d0070c45c0010455d00b06a7400d06a7400f06a7400106b740090b07500105d5f00105d5f0050045500d06f400020a17400306447003064470010b17500e0674000e0674000306447003064470000ee5c0080717500b03d400030717500c06f400030644700f0c28d00906f4000e0214200408c4000b06f7500c0697500d0677500a0697500b069750080475d00

### C_CBottomMenuFrameField RTTI COL CBottomMenuFrameField
VA 0xc72348 RAW 0x870948 END 0xc7235c SHA256 9503300fc24e062ee2664ce05b32f532f88699fa29235b450eb9d3ba72d79a05
0000000000000000000000002435f8005c23c700

### T_CBottomMenuFrameField RTTI type descriptor CBottomMenuFrameField
VA 0xf83524 RAW 0xb80d24 END 0xf8354c SHA256 37224f8bef070bbb267fccf7650b106f490ff1f0ba26d9300a80355f962eaafd
f435bd00000000002e3f415643426f74746f6d4d656e754672616d654669656c6440465549404000

### V_CBottomMenuFrameScenario vtable/COL pointer CBottomMenuFrameScenario
VA 0xc22088 RAW 0x820688 END 0xc22228 SHA256 e1fdd18aee7a8a5d04a291aa1661deab2668df7e945d327c41e7051c22b94b72
f424c700e0824800508e4000508e4000408e4000e03d4000e066750040677500c04f5d00e08d4000308d4000a08c4000c063750030557400f0567400d0af7500205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b740080707500703d4000d05a7400205b74004070750000707500f0a07400503d4000b03d4000403d400050045500e0674000e0674000d0877400f08774006071750060717500c0d14000f04f5d00f0505d0070c45c00c0c55c00b06a7400d06a7400f06a7400106b740090b07500105d5f00105d5f0050045500d06f400020a17400306447003064470010b17500e0674000e0674000306447003064470000ee5c0080717500b03d400030717500c06f400030644700f0c28d00906f4000e0214200408c4000b06f7500c0697500d0677500a0697500b069750080515d00

### C_CBottomMenuFrameScenario RTTI COL CBottomMenuFrameScenario
VA 0xc724f4 RAW 0x870af4 END 0xc72508 SHA256 7d35ffadb493321148842a36e9522b6a244d30019f3c63312a1ef65204dc95c0
0000000000000000000000003036f8000825c700

### T_CBottomMenuFrameScenario RTTI type descriptor CBottomMenuFrameScenario
VA 0xf83630 RAW 0xb80e30 END 0xf8365b SHA256 4e7095771eb9d1a85845499bb63e2c188d1741bfb0e13f97e10d55ed54eeb8ba
f435bd00000000002e3f415643426f74746f6d4d656e754672616d655363656e6172696f40465549404000

### V_MissionBottomDescriptor vtable/COL pointer MissionBottomDescriptor
VA 0xc1d3e4 RAW 0x81b9e4 END 0xc1d3fc SHA256 54d5a4f33451191765443bfd05fe1557b80f73c2795de3a94b5f694bcade436c
d4f9c60090e55a0050327b00109540002095400020de5a00

### C_MissionBottomDescriptor RTTI COL MissionBottomDescriptor
VA 0xc6f9d4 RAW 0x86dfd4 END 0xc6f9e8 SHA256 6baf39afc5d53bd47c5b65cb0ceae2d2945adef9a52f0ce2742f2690a4592cb0
000000000000000000000000b016f800e8f9c600

### T_MissionBottomDescriptor RTTI type descriptor MissionBottomDescriptor
VA 0xf816b0 RAW 0xb7eeb0 END 0xf816f4 SHA256 8459d431a17fcbf78b5ed322b868acc3a1d7e19a8c22642693bb62d5a2a59501
f435bd00000000002e3f41563f24554943616368696e6744617461402430454c405643426f74746f6d4d656e754672616d654669656c6440465549404040465549404000

### V_ScenarioBottomDescriptor vtable/COL pointer ScenarioBottomDescriptor
VA 0xbfdb6c RAW 0x7fc16c END 0xbfdb84 SHA256 7e0b94a2bca1e90fdd53913f315a177f808642ee98d5cbdbf161e3675e0c58fb
9871c600606c450050327b00109540002095400020de5a00

### C_ScenarioBottomDescriptor RTTI COL ScenarioBottomDescriptor
VA 0xc67198 RAW 0x865798 END 0xc671ac SHA256 e6d4eacfc97e78680ed9625239f9957b3dba233e17c75221e1fc58fcdf243ca3
00000000000000000000000020cbf700ac71c600

### T_ScenarioBottomDescriptor RTTI type descriptor ScenarioBottomDescriptor
VA 0xf7cb20 RAW 0xb7a320 END 0xf7cb67 SHA256 fcbb548bd88ca0be649238d2137d41f585f19fe7ddbac760f1b122751d52c046
f435bd00000000002e3f41563f24554943616368696e6744617461402430454c405643426f74746f6d4d656e754672616d655363656e6172696f40465549404040465549404000

### V_CBottomMenuFieldPart vtable/COL pointer CBottomMenuFieldPart
VA 0xc20f28 RAW 0x81f528 END 0xc20f30 SHA256 bb963bcff1780eeb523ccac8d68747af800b9bc4f6c871b8e9dd23842e577b3c
2420c70010045500

### C_CBottomMenuFieldPart RTTI COL CBottomMenuFieldPart
VA 0xc72024 RAW 0x870624 END 0xc72038 SHA256 5172e21b103d8a9eb131c83af0bb4500be1971a59ce1992fd958f39895a8c33e
0000000000000000000000000833f8000020c700

### T_CBottomMenuFieldPart RTTI type descriptor CBottomMenuFieldPart
VA 0xf83308 RAW 0xb80b08 END 0xf8332f SHA256 ed1028aac6748203d3bff3d0430e2efb322cdec9de79c01195e19466bca52706
f435bd00000000002e3f415643426f74746f6d4d656e754669656c645061727440465549404000

### V_CBottomMenuScenarioPart vtable/COL pointer CBottomMenuScenarioPart
VA 0xc216b8 RAW 0x81fcb8 END 0xc216c0 SHA256 8983519397a28bf3a5fad380cb4ebd533dc71ec52773478a5ba1f74b041f495c
f821c70010045500

### C_CBottomMenuScenarioPart RTTI COL CBottomMenuScenarioPart
VA 0xc721f8 RAW 0x8707f8 END 0xc7220c SHA256 1a708265cc4b872ede4de83dc480db515384bdfb02e44cf4393c966987f6bcd1
0000000000000000000000004c34f8000c22c700

### T_CBottomMenuScenarioPart RTTI type descriptor CBottomMenuScenarioPart
VA 0xf8344c RAW 0xb80c4c END 0xf83476 SHA256 b6b9a1f86fdab7105a5ea9796806e17ff5be5b0fc720a3667b2857b7c57613d3
f435bd00000000002e3f415643426f74746f6d4d656e755363656e6172696f5061727440465549404000

### V_MissionBottomPartDescriptor vtable/COL pointer MissionBottomPartDescriptor
VA 0xc21b44 RAW 0x820144 END 0xc21b5c SHA256 d9fe817a96c3b8b28cb0e27aef270add84063ef3be9fe3240f1c6c5d9d96a37c
a022c70050465d0050327b00109540002095400020de5a00

### C_MissionBottomPartDescriptor RTTI COL MissionBottomPartDescriptor
VA 0xc722a0 RAW 0x8708a0 END 0xc722b4 SHA256 b186a3ff885176526701e3e851d2d9df0a4d906e2b34e53c5d8ceefe1e1d8b57
000000000000000000000000b834f800b422c700

### T_MissionBottomPartDescriptor RTTI type descriptor MissionBottomPartDescriptor
VA 0xf834b8 RAW 0xb80cb8 END 0xf834fb SHA256 101aededa49132bf6d8e24cedf4aff31dedda48bb6094556cc274b67b82f22b6
f435bd00000000002e3f41563f24554943616368696e6744617461402430454f405643426f74746f6d4d656e754669656c645061727440465549404040465549404000

### V_ScenarioBottomPartDescriptor vtable/COL pointer ScenarioBottomPartDescriptor
VA 0xc22234 RAW 0x820834 END 0xc2224c SHA256 4e1ac94dabb8abe15237fd488f304985e2d20a62da46658fe131b828f585a3e8
a824c70080525d0050327b00109540002095400020de5a00

### C_ScenarioBottomPartDescriptor RTTI COL ScenarioBottomPartDescriptor
VA 0xc724a8 RAW 0x870aa8 END 0xc724bc SHA256 ae751946ddfd9fae5c459e30495eed051e15417d69bda553c99bee002e42aa5e
000000000000000000000000e835f800bc24c700

### T_ScenarioBottomPartDescriptor RTTI type descriptor ScenarioBottomPartDescriptor
VA 0xf835e8 RAW 0xb80de8 END 0xf8362e SHA256 50b858f0d3d0d2646b57836debabe85ebe1cf1ae85ea4f44a7eddbf9e3ce2124
f435bd00000000002e3f41563f24554943616368696e6744617461402430454e405643426f74746f6d4d656e755363656e6172696f5061727440465549404040465549404000

### V_InventoryDescriptor vtable/COL pointer InventoryDescriptor
VA 0xc1babc RAW 0x81a0bc END 0xc1bad4 SHA256 777457babb82580ef05e5bb0ea3dd9b06dc3ddfe96be4f63623c4248b97f8a84
dcebc60010085a0050327b00109540002095400020de5a00

### C_InventoryDescriptor RTTI COL InventoryDescriptor
VA 0xc6ebdc RAW 0x86d1dc END 0xc6ebf0 SHA256 29943e689778b93f13b1cd0d5fe68e7b64ccdac5181c58e7d55efe5b7df7b7e4
000000000000000000000000780cf800f0ebc600

### T_InventoryDescriptor RTTI type descriptor InventoryDescriptor
VA 0xf80c78 RAW 0xb7e478 END 0xf80cb7 SHA256 92d8f8155bd24d280c27af1db458f22d3ece07d482bf869a28ff511f70fd4496
f435bd00000000002e3f41563f24554943616368696e67446174614024304746405643496e76656e746f72794469616c6f6740465549404040465549404000

### V_CInventoryDialog vtable/COL pointer CInventoryDialog
VA 0xc290d0 RAW 0x8276d0 END 0xc29284 SHA256 9a54e6494fd4b2270b10764bd4d11feeef76a798a2cd10d6769f65906d10ed0b
8c48c700e082480010585f0010585f0000585f00e03d4000f0f4760050f5760010af5f0070575f00c0565f0010565f00508e480030557400f0567400800b7600205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b740080707500703d4000d05a7400205b7400a0515f00607f5f00f0a07400503d4000b03d4000403d4000500455003039410030394100d0877400f0877400607175006071750090555f00e0b05f0010b35f00c0af5f00f0af5f00b06a7400d06a7400f06a7400106b7400800c7600105d5f00105d5f0050045500d06f400020a17400b07e5f003064470070f77600e0674000e0674000306447003064470030ca5f0080717500b03d400030717500c06f400030644700f0c28d00906f4000f08a480060517400b06f750080f97600d0677500a0697500b0697500c0f5760000f6760030f6760060f87600f0f8760060af8700

### C_CInventoryDialog RTTI COL CInventoryDialog
VA 0xc7488c RAW 0x872e8c END 0xc748a0 SHA256 299b38421fa482531cd543d100198ca2c6965cec3a90accb2803bc500f0a963a
000000000000000000000000704af800a048c700

### T_CInventoryDialog RTTI type descriptor CInventoryDialog
VA 0xf84a70 RAW 0xb82270 END 0xf84a93 SHA256 f3d084ea464dad0e0624d7aa86ae30da74222e473cec7c75a944534f02d58fbd
f435bd00000000002e3f415643496e76656e746f72794469616c6f6740465549404000

### V_CInventoryInsideWindow vtable/COL pointer CInventoryInsideWindow
VA 0xc29310 RAW 0x827910 END 0xc294c0 SHA256 862514ca44a4263d1e5998790e7fd7781b834764502ffbe96b7fd0892e920a22
b049c700e0824800508e4000508e4000408e4000e03d4000e06675004067750050f15f00e08d4000308d4000a08c4000c063750030557400f0567400d0af7500205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b740080707500703d4000d05a7400205b74004070750000707500f0a07400503d4000b03d4000403d400050045500e0674000e0674000d0877400f08774006071750060717500105d5f00105d5f00105d5f0040644700605b5f00b06a7400d06a7400f06a7400106b740090b07500105d5f00105d5f0050045500d06f400020a17400306447003064470010b17500e0674000e0674000306447003064470020f45f0080717500b03d400030717500c06f400030644700f0c28d00906f4000e0214200408c4000b06f7500c0697500d0677500a0697500b06975001038600050f25f00d03260008033600030346000

### C_CInventoryInsideWindow RTTI COL CInventoryInsideWindow
VA 0xc749b0 RAW 0x872fb0 END 0xc749c4 SHA256 5b5060d14a29efeb159bfb65e5a9da59c2763949586e75f65ee8171027194b5a
000000000000000000000000dc4af800c449c700

### T_CInventoryInsideWindow RTTI type descriptor CInventoryInsideWindow
VA 0xf84adc RAW 0xb822dc END 0xf84b05 SHA256 0d04800af56debad99a15359f143e397a75195a3b8c9ffe761eea4052540d959
f435bd00000000002e3f415643496e76656e746f7279496e7369646557696e646f7740465549404000

### V_CQuestInventoryInside vtable/COL pointer CQuestInventoryInside
VA 0xc02690 RAW 0x800c90 END 0xc02840 SHA256 5e6cd3ca50fc516f0d0b0f51d46304a377f66b39a702ce5d5cff037a865f61cd
8487c600e0824800508e4000508e4000408e4000e03d4000e066750040677500d0614700e08d4000308d4000a08c4000c063750030557400f0567400d0af7500205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b740080707500703d4000d05a7400205b74004070750000707500f0a07400503d4000b03d4000403d400050045500e0674000e0674000d0877400f08774006071750060717500105d5f00105d5f00105d5f0040644700605b5f00b06a7400d06a7400f06a7400106b740090b07500105d5f00105d5f0050045500d06f400020a17400306447003064470010b17500e0674000e067400030644700306447003064470080717500b03d400030717500c06f400030644700f0c28d00906f4000e0214200408c4000b06f7500c0697500d0677500a0697500b06975002064470030624700f0c28d00f0c28d00105d5f00

### C_CQuestInventoryInside RTTI COL CQuestInventoryInside
VA 0xc68784 RAW 0x866d84 END 0xc68798 SHA256 c0d4b3cdc3f28a79befd0b0d850019271e73e40b1faf6b4a134e0e9922c5b649
000000000000000000000000c8d6f7009887c600

### T_CQuestInventoryInside RTTI type descriptor CQuestInventoryInside
VA 0xf7d6c8 RAW 0xb7aec8 END 0xf7d6f0 SHA256 4bd4495c6b74d6f91e4302ca0005fb54bd521216e841f08cbed743a51c6d34a4
f435bd00000000002e3f4156435175657374496e76656e746f7279496e7369646540465549404000

### V_CPartyAllianceListPanel vtable/COL pointer CPartyAllianceListPanel
VA 0xc383f0 RAW 0x8369f0 END 0xc38564 SHA256 f7fad38bdc608bfe9904ee8682f57fbd48b8d542a6c01bef421b18949de3bd44
b88dc70010045500f0ec4000f0ec4000e0ec4000e03d4000408c74006094740010105b0080ec4000d0eb400040eb4000f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400d06e7400703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500e0674000e0674000d0877400f08774001088740010887400105d5f00b0266900b027690010ae490070286900b06a7400d06a7400f06a7400106b7400105d5f00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e067400030644700306447003064470030ed4000b03d4000e0674000b0286900

### C_CPartyAllianceListPanel RTTI COL CPartyAllianceListPanel
VA 0xc78db8 RAW 0x8773b8 END 0xc78dcc SHA256 7f9691cf9bfb92ab3b42a6f0a5356c6369d0913ea78a90cb0a1302881da9f5d5
000000000000000000000000b46df800cc8dc700

### T_CPartyAllianceListPanel RTTI type descriptor CPartyAllianceListPanel
VA 0xf86db4 RAW 0xb845b4 END 0xf86dde SHA256 57cd5ffbd5722839ce1320807365e0c9e4d5b848fdf63f34a7c63803a5b025ec
f435bd00000000002e3f4156435061727479416c6c69616e63654c69737450616e656c40465549404000

### V_AllianceDescriptor vtable/COL pointer AllianceDescriptor
VA 0xc1d354 RAW 0x81b954 END 0xc1d36c SHA256 e4d7128997c140c0ba6f6bac98ef52f94f88965424547476215a86c82544e41a
9cfbc60090e25a0050327b00109540002095400020de5a00

### C_AllianceDescriptor RTTI COL AllianceDescriptor
VA 0xc6fb9c RAW 0x86e19c END 0xc6fbb0 SHA256 8b0cf5b73932919753eb851e42f404c2ad89efd66676a07e50b494c781e6bbe3
0000000000000000000000005018f800b0fbc600

### T_AllianceDescriptor RTTI type descriptor AllianceDescriptor
VA 0xf81850 RAW 0xb7f050 END 0xf81896 SHA256 f99abe70944b27c4df57fdb298a82cf20c7852124502c9fb4dabaa5a6f66d7ad
f435bd00000000002e3f41563f24554943616368696e674461746140243042474056435061727479416c6c69616e63654c69737450616e656c40465549404040465549404000

### V_InventoryInsideDescriptor vtable/COL pointer InventoryInsideDescriptor
VA 0xc29298 RAW 0x827898 END 0xc292b0 SHA256 6bef2b9c6f01aeef1735909072f30a3573c48debe85fca4a30ae3736b8dab7c4
4048c70000e95f0050327b00109540002095400020de5a00

### C_InventoryInsideDescriptor RTTI COL InventoryInsideDescriptor
VA 0xc74840 RAW 0x872e40 END 0xc74854 SHA256 8489597c8c63a4f32388cd14bca0d8eb361290e24accf9ad1e15798d8d6c7503
000000000000000000000000284af8005448c700

### T_InventoryInsideDescriptor RTTI type descriptor InventoryInsideDescriptor
VA 0xf84a28 RAW 0xb82228 END 0xf84a6d SHA256 fe9c8f41513fd6482dddb4a3be62b19ebd04fbac2078be4594c5ffd82ff16dfd
f435bd00000000002e3f41563f24554943616368696e67446174614024304747405643496e76656e746f7279496e7369646557696e646f7740465549404040465549404000

### V_QuestInventoryDescriptor vtable/COL pointer QuestInventoryDescriptor
VA 0xc292b0 RAW 0x8278b0 END 0xc292c8 SHA256 fd4f4ab235fff30c95d6667bd40df39745fe8316217af2510f1377a232e1a450
f447c70080e95f0050327b00109540002095400020de5a00

### C_QuestInventoryDescriptor RTTI COL QuestInventoryDescriptor
VA 0xc747f4 RAW 0x872df4 END 0xc74808 SHA256 6e98fac6e32da8c612d46ea50c18a78817ca830476180c8b683d506dad8feed3
000000000000000000000000e049f8000848c700

### T_QuestInventoryDescriptor RTTI type descriptor QuestInventoryDescriptor
VA 0xf849e0 RAW 0xb821e0 END 0xf84a24 SHA256 baab8bf3ac23c4ed043908c855c95453faa10381c4d813641812d3f85a5c5b40
f435bd00000000002e3f41563f24554943616368696e674461746140243047484056435175657374496e76656e746f7279496e7369646540465549404040465549404000
