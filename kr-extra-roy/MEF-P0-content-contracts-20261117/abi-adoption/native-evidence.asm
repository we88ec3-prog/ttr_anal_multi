; Original KR BIN bounded supplemental evidence. Never executed.
; SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91

; F_00565600 VA 0x565600 RAW 0x164a00 SHA256 2b84862b44c871197789e80ba044db2f6d5761b9a80209e74e38fd38e9298a4f
0x565600  55                                push   ebp
0x565601  8bec                              mov    ebp,esp
0x565603  b801000000                        mov    eax,0x1
0x565608  c705d436fe0004000000              mov    DWORD PTR ds:0xfe36d4,0x4
0x565612  8405dc36fe00                      test   BYTE PTR ds:0xfe36dc,al
0x565618  7512                              jne    0x56562c
0x56561a  0905dc36fe00                      or     DWORD PTR ds:0xfe36dc,eax
0x565620  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x565623  a3d836fe00                        mov    ds:0xfe36d8,eax
0x565628  5d                                pop    ebp
0x565629  c20400                            ret    0x4
0x56562c  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x56562f  890dd836fe00                      mov    DWORD PTR ds:0xfe36d8,ecx
0x565635  5d                                pop    ebp
0x565636  c20400                            ret    0x4

; F_006F7170 VA 0x6f7170 RAW 0x2f6570 SHA256 5c25bb80e7654d2e9a2219514f25239b0b72f0accef74b066229d5f6103a172a
0x6f7170  55                                push   ebp
0x6f7171  8bec                              mov    ebp,esp
0x6f7173  8b4514                            mov    eax,DWORD PTR [ebp+0x14]
0x6f7176  85c0                              test   eax,eax
0x6f7178  7510                              jne    0x6f718a
0x6f717a  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6f717d  50                                push   eax
0x6f717e  e879af1900                        call   0x8920fc
0x6f7183  83c404                            add    esp,0x4
0x6f7186  33c0                              xor    eax,eax
0x6f7188  5d                                pop    ebp
0x6f7189  c3                                ret
0x6f718a  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x6f718d  50                                push   eax
0x6f718e  51                                push   ecx
0x6f718f  e8d2081a00                        call   0x897a66
0x6f7194  83c408                            add    esp,0x8
0x6f7197  5d                                pop    ebp
0x6f7198  c3                                ret

; F_006F74B0 VA 0x6f74b0 RAW 0x2f68b0 SHA256 c0d2ae5347a32f3f4a31195bdb6b62fe3cb9fd74309efe4200996eb4a4892417
0x6f74b0  51                                push   ecx
0x6f74b1  53                                push   ebx
0x6f74b2  56                                push   esi
0x6f74b3  6878010000                        push   0x178
0x6f74b8  33db                              xor    ebx,ebx
0x6f74ba  53                                push   ebx
0x6f74bb  e8a6051a00                        call   0x897a66
0x6f74c0  8bf0                              mov    esi,eax
0x6f74c2  83c408                            add    esp,0x8
0x6f74c5  3bf3                              cmp    esi,ebx
0x6f74c7  7506                              jne    0x6f74cf
0x6f74c9  33c0                              xor    eax,eax
0x6f74cb  5e                                pop    esi
0x6f74cc  5b                                pop    ebx
0x6f74cd  59                                pop    ecx
0x6f74ce  c3                                ret
0x6f74cf  8d4678                            lea    eax,[esi+0x78]
0x6f74d2  891e                              mov    DWORD PTR [esi],ebx
0x6f74d4  c6460408                          mov    BYTE PTR [esi+0x4],0x8
0x6f74d8  c6401421                          mov    BYTE PTR [eax+0x14],0x21
0x6f74dc  894610                            mov    DWORD PTR [esi+0x10],eax
0x6f74df  895e20                            mov    DWORD PTR [esi+0x20],ebx
0x6f74e2  895e2c                            mov    DWORD PTR [esi+0x2c],ebx
0x6f74e5  895e70                            mov    DWORD PTR [esi+0x70],ebx
0x6f74e8  895e44                            mov    DWORD PTR [esi+0x44],ebx
0x6f74eb  895e3c                            mov    DWORD PTR [esi+0x3c],ebx
0x6f74ee  895e40                            mov    DWORD PTR [esi+0x40],ebx
0x6f74f1  895e68                            mov    DWORD PTR [esi+0x68],ebx
0x6f74f4  895e30                            mov    DWORD PTR [esi+0x30],ebx
0x6f74f7  c7463600000001                    mov    DWORD PTR [esi+0x36],0x1000000
0x6f74fe  66c746056100                      mov    WORD PTR [esi+0x5],0x61
0x6f7504  895e14                            mov    DWORD PTR [esi+0x14],ebx
0x6f7507  895e28                            mov    DWORD PTR [esi+0x28],ebx
0x6f750a  895e18                            mov    DWORD PTR [esi+0x18],ebx
0x6f750d  895e74                            mov    DWORD PTR [esi+0x74],ebx
0x6f7510  895e50                            mov    DWORD PTR [esi+0x50],ebx
0x6f7513  8d4878                            lea    ecx,[eax+0x78]
0x6f7516  33d2                              xor    edx,edx
0x6f7518  66895634                          mov    WORD PTR [esi+0x34],dx
0x6f751c  898888000000                      mov    DWORD PTR [eax+0x88],ecx
0x6f7522  89888c000000                      mov    DWORD PTR [eax+0x8c],ecx
0x6f7528  c7400c70716f00                    mov    DWORD PTR [eax+0xc],0x6f7170
0x6f752f  895810                            mov    DWORD PTR [eax+0x10],ebx
0x6f7532  897070                            mov    DWORD PTR [eax+0x70],esi
0x6f7535  895840                            mov    DWORD PTR [eax+0x40],ebx
0x6f7538  895808                            mov    DWORD PTR [eax+0x8],ebx
0x6f753b  895804                            mov    DWORD PTR [eax+0x4],ebx
0x6f753e  8918                              mov    DWORD PTR [eax],ebx
0x6f7540  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
0x6f7543  895968                            mov    DWORD PTR [ecx+0x68],ebx
0x6f7546  89701c                            mov    DWORD PTR [eax+0x1c],esi
0x6f7549  895834                            mov    DWORD PTR [eax+0x34],ebx
0x6f754c  89583c                            mov    DWORD PTR [eax+0x3c],ebx
0x6f754f  895858                            mov    DWORD PTR [eax+0x58],ebx
0x6f7552  885815                            mov    BYTE PTR [eax+0x15],bl
0x6f7555  895818                            mov    DWORD PTR [eax+0x18],ebx
0x6f7558  895824                            mov    DWORD PTR [eax+0x24],ebx
0x6f755b  895828                            mov    DWORD PTR [eax+0x28],ebx
0x6f755e  89582c                            mov    DWORD PTR [eax+0x2c],ebx
0x6f7561  895830                            mov    DWORD PTR [eax+0x30],ebx
0x6f7564  c7404478010000                    mov    DWORD PTR [eax+0x44],0x178
0x6f756b  89584c                            mov    DWORD PTR [eax+0x4c],ebx
0x6f756e  8d481c                            lea    ecx,[eax+0x1c]
0x6f7571  894820                            mov    DWORD PTR [eax+0x20],ecx
0x6f7574  53                                push   ebx
0x6f7575  b9c8000000                        mov    ecx,0xc8
0x6f757a  894850                            mov    DWORD PTR [eax+0x50],ecx
0x6f757d  894854                            mov    DWORD PTR [eax+0x54],ecx
0x6f7580  6880726f00                        push   0x6f7280
0x6f7585  56                                push   esi
0x6f7586  899898000000                      mov    DWORD PTR [eax+0x98],ebx
0x6f758c  89989c000000                      mov    DWORD PTR [eax+0x9c],ebx
0x6f7592  8998a0000000                      mov    DWORD PTR [eax+0xa0],ebx
0x6f7598  8998a4000000                      mov    DWORD PTR [eax+0xa4],ebx
0x6f759e  8998a8000000                      mov    DWORD PTR [eax+0xa8],ebx
0x6f75a4  8998ac000000                      mov    DWORD PTR [eax+0xac],ebx
0x6f75aa  8998b0000000                      mov    DWORD PTR [eax+0xb0],ebx
0x6f75b0  8998b4000000                      mov    DWORD PTR [eax+0xb4],ebx
0x6f75b6  8998b8000000                      mov    DWORD PTR [eax+0xb8],ebx
0x6f75bc  e8df650000                        call   0x6fdba0
0x6f75c1  83c40c                            add    esp,0xc
0x6f75c4  85c0                              test   eax,eax
0x6f75c6  7409                              je     0x6f75d1
0x6f75c8  8bc6                              mov    eax,esi
0x6f75ca  e831fdffff                        call   0x6f7300
0x6f75cf  33f6                              xor    esi,esi
0x6f75d1  8bc6                              mov    eax,esi
0x6f75d3  5e                                pop    esi
0x6f75d4  5b                                pop    ebx
0x6f75d5  59                                pop    ecx
0x6f75d6  c3                                ret

; F_006FDC30 VA 0x6fdc30 RAW 0x2fd030 SHA256 25e1b1c85750b2e617c7633897eac161ac89a7e4213a2e223dc206d0a5af3425
0x6fdc30  8b4108                            mov    eax,DWORD PTR [ecx+0x8]
0x6fdc33  2bc2                              sub    eax,edx
0x6fdc35  83e0f0                            and    eax,0xfffffff0
0x6fdc38  034120                            add    eax,DWORD PTR [ecx+0x20]
0x6fdc3b  56                                push   esi
0x6fdc3c  894108                            mov    DWORD PTR [ecx+0x8],eax
0x6fdc3f  8b4168                            mov    eax,DWORD PTR [ecx+0x68]
0x6fdc42  85c0                              test   eax,eax
0x6fdc44  7414                              je     0x6fdc5a
0x6fdc46  8b7008                            mov    esi,DWORD PTR [eax+0x8]
0x6fdc49  2bf2                              sub    esi,edx
0x6fdc4b  83e6f0                            and    esi,0xfffffff0
0x6fdc4e  037120                            add    esi,DWORD PTR [ecx+0x20]
0x6fdc51  897008                            mov    DWORD PTR [eax+0x8],esi
0x6fdc54  8b00                              mov    eax,DWORD PTR [eax]
0x6fdc56  85c0                              test   eax,eax
0x6fdc58  75ec                              jne    0x6fdc46
0x6fdc5a  8b4128                            mov    eax,DWORD PTR [ecx+0x28]
0x6fdc5d  3b4114                            cmp    eax,DWORD PTR [ecx+0x14]
0x6fdc60  7732                              ja     0x6fdc94
0x6fdc62  8b7008                            mov    esi,DWORD PTR [eax+0x8]
0x6fdc65  2bf2                              sub    esi,edx
0x6fdc67  83e6f0                            and    esi,0xfffffff0
0x6fdc6a  037120                            add    esi,DWORD PTR [ecx+0x20]
0x6fdc6d  83c018                            add    eax,0x18
0x6fdc70  8970f0                            mov    DWORD PTR [eax-0x10],esi
0x6fdc73  8b70e8                            mov    esi,DWORD PTR [eax-0x18]
0x6fdc76  2bf2                              sub    esi,edx
0x6fdc78  83e6f0                            and    esi,0xfffffff0
0x6fdc7b  037120                            add    esi,DWORD PTR [ecx+0x20]
0x6fdc7e  8970e8                            mov    DWORD PTR [eax-0x18],esi
0x6fdc81  8b70ec                            mov    esi,DWORD PTR [eax-0x14]
0x6fdc84  2bf2                              sub    esi,edx
0x6fdc86  83e6f0                            and    esi,0xfffffff0
0x6fdc89  037120                            add    esi,DWORD PTR [ecx+0x20]
0x6fdc8c  8970ec                            mov    DWORD PTR [eax-0x14],esi
0x6fdc8f  3b4114                            cmp    eax,DWORD PTR [ecx+0x14]
0x6fdc92  76ce                              jbe    0x6fdc62
0x6fdc94  8b410c                            mov    eax,DWORD PTR [ecx+0xc]
0x6fdc97  2bc2                              sub    eax,edx
0x6fdc99  83e0f0                            and    eax,0xfffffff0
0x6fdc9c  034120                            add    eax,DWORD PTR [ecx+0x20]
0x6fdc9f  5e                                pop    esi
0x6fdca0  89410c                            mov    DWORD PTR [ecx+0xc],eax
0x6fdca3  c3                                ret

; F_006FDCB0 VA 0x6fdcb0 RAW 0x2fd0b0 SHA256 a7e46edc1287265bb19480b2c894d95a100d65869dc4c1e15115a2038c3c3a00
0x6fdcb0  55                                push   ebp
0x6fdcb1  8bec                              mov    ebp,esp
0x6fdcb3  51                                push   ecx
0x6fdcb4  53                                push   ebx
0x6fdcb5  57                                push   edi
0x6fdcb6  8bf8                              mov    edi,eax
0x6fdcb8  8b4620                            mov    eax,DWORD PTR [esi+0x20]
0x6fdcbb  8d5f06                            lea    ebx,[edi+0x6]
0x6fdcbe  8d4b01                            lea    ecx,[ebx+0x1]
0x6fdcc1  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x6fdcc4  81f9ffffff0f                      cmp    ecx,0xfffffff
0x6fdcca  7719                              ja     0x6fdce5
0x6fdccc  8b4e2c                            mov    ecx,DWORD PTR [esi+0x2c]
0x6fdccf  8bd3                              mov    edx,ebx
0x6fdcd1  c1e204                            shl    edx,0x4
0x6fdcd4  52                                push   edx
0x6fdcd5  c1e104                            shl    ecx,0x4
0x6fdcd8  51                                push   ecx
0x6fdcd9  50                                push   eax
0x6fdcda  56                                push   esi
0x6fdcdb  e8a02b0000                        call   0x700880
0x6fdce0  83c410                            add    esp,0x10
0x6fdce3  eb09                              jmp    0x6fdcee
0x6fdce5  56                                push   esi
0x6fdce6  e8752b0000                        call   0x700860
0x6fdceb  83c404                            add    esp,0x4
0x6fdcee  8b55fc                            mov    edx,DWORD PTR [ebp-0x4]
0x6fdcf1  c1e704                            shl    edi,0x4
0x6fdcf4  03f8                              add    edi,eax
0x6fdcf6  8bce                              mov    ecx,esi
0x6fdcf8  894620                            mov    DWORD PTR [esi+0x20],eax
0x6fdcfb  895e2c                            mov    DWORD PTR [esi+0x2c],ebx
0x6fdcfe  897e1c                            mov    DWORD PTR [esi+0x1c],edi
0x6fdd01  e82affffff                        call   0x6fdc30
0x6fdd06  5f                                pop    edi
0x6fdd07  5b                                pop    ebx
0x6fdd08  8be5                              mov    esp,ebp
0x6fdd0a  5d                                pop    ebp
0x6fdd0b  c3                                ret

; F_006FDD10 VA 0x6fdd10 RAW 0x2fd110 SHA256 e2f689ff4633915fe8857ccccaa8b96765f95b5794d7cf70db7c1a46366dca69
0x6fdd10  55                                push   ebp
0x6fdd11  8bec                              mov    ebp,esp
0x6fdd13  51                                push   ecx
0x6fdd14  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x6fdd17  8d4701                            lea    eax,[edi+0x1]
0x6fdd1a  53                                push   ebx
0x6fdd1b  894dfc                            mov    DWORD PTR [ebp-0x4],ecx
0x6fdd1e  3daaaaaa0a                        cmp    eax,0xaaaaaaa
0x6fdd23  7723                              ja     0x6fdd48
0x6fdd25  8b4630                            mov    eax,DWORD PTR [esi+0x30]
0x6fdd28  8d0440                            lea    eax,[eax+eax*2]
0x6fdd2b  8d147f                            lea    edx,[edi+edi*2]
0x6fdd2e  03d2                              add    edx,edx
0x6fdd30  03c0                              add    eax,eax
0x6fdd32  03d2                              add    edx,edx
0x6fdd34  03d2                              add    edx,edx
0x6fdd36  52                                push   edx
0x6fdd37  03c0                              add    eax,eax
0x6fdd39  03c0                              add    eax,eax
0x6fdd3b  50                                push   eax
0x6fdd3c  51                                push   ecx
0x6fdd3d  56                                push   esi
0x6fdd3e  e83d2b0000                        call   0x700880
0x6fdd43  83c410                            add    esp,0x10
0x6fdd46  eb09                              jmp    0x6fdd51
0x6fdd48  56                                push   esi
0x6fdd49  e8122b0000                        call   0x700860
0x6fdd4e  83c404                            add    esp,0x4
0x6fdd51  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x6fdd54  2b4dfc                            sub    ecx,DWORD PTR [ebp-0x4]
0x6fdd57  8bd8                              mov    ebx,eax
0x6fdd59  b8abaaaa2a                        mov    eax,0x2aaaaaab
0x6fdd5e  f7e9                              imul   ecx
0x6fdd60  c1fa02                            sar    edx,0x2
0x6fdd63  8bc2                              mov    eax,edx
0x6fdd65  c1e81f                            shr    eax,0x1f
0x6fdd68  03c2                              add    eax,edx
0x6fdd6a  8d0c40                            lea    ecx,[eax+eax*2]
0x6fdd6d  8d14cb                            lea    edx,[ebx+ecx*8]
0x6fdd70  8d047f                            lea    eax,[edi+edi*2]
0x6fdd73  8d4cc3e8                          lea    ecx,[ebx+eax*8-0x18]
0x6fdd77  895e28                            mov    DWORD PTR [esi+0x28],ebx
0x6fdd7a  897e30                            mov    DWORD PTR [esi+0x30],edi
0x6fdd7d  895614                            mov    DWORD PTR [esi+0x14],edx
0x6fdd80  894e24                            mov    DWORD PTR [esi+0x24],ecx
0x6fdd83  5b                                pop    ebx
0x6fdd84  8be5                              mov    esp,ebp
0x6fdd86  5d                                pop    ebp
0x6fdd87  c3                                ret

; F_006FDD90 VA 0x6fdd90 RAW 0x2fd190 SHA256 26dd40b283b4c4ebc35f81d746d00b7d624532a7e287790b907b5e9887e0796a
0x6fdd90  56                                push   esi
0x6fdd91  8bf0                              mov    esi,eax
0x6fdd93  8b4630                            mov    eax,DWORD PTR [esi+0x30]
0x6fdd96  3d204e0000                        cmp    eax,0x4e20
0x6fdd9b  7e16                              jle    0x6fddb3
0x6fdd9d  6a05                              push   0x5
0x6fdd9f  56                                push   esi
0x6fdda0  e89bfdffff                        call   0x6fdb40
0x6fdda5  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6fdda8  83c408                            add    esp,0x8
0x6fddab  83c018                            add    eax,0x18
0x6fddae  894614                            mov    DWORD PTR [esi+0x14],eax
0x6fddb1  5e                                pop    esi
0x6fddb2  c3                                ret
0x6fddb3  57                                push   edi
0x6fddb4  8d3c00                            lea    edi,[eax+eax*1]
0x6fddb7  e854ffffff                        call   0x6fdd10
0x6fddbc  817e30204e0000                    cmp    DWORD PTR [esi+0x30],0x4e20
0x6fddc3  5f                                pop    edi
0x6fddc4  7e0e                              jle    0x6fddd4
0x6fddc6  68ec2ac400                        push   0xc42aec
0x6fddcb  56                                push   esi
0x6fddcc  e88fadffff                        call   0x6f8b60
0x6fddd1  83c408                            add    esp,0x8
0x6fddd4  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6fddd7  83c018                            add    eax,0x18
0x6fddda  894614                            mov    DWORD PTR [esi+0x14],eax
0x6fdddd  5e                                pop    esi
0x6fddde  c3                                ret

; F_00700880 VA 0x700880 RAW 0x2ffc80 SHA256 27f8855cc78342431c1c2ffe823430e8d2b400859bccf9a49a2697dafdd77ddc
0x700880  55                                push   ebp
0x700881  8bec                              mov    ebp,esp
0x700883  83e4f8                            and    esp,0xfffffff8
0x700886  51                                push   ecx
0x700887  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x70088a  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x70088d  53                                push   ebx
0x70088e  8b5d10                            mov    ebx,DWORD PTR [ebp+0x10]
0x700891  56                                push   esi
0x700892  8b7010                            mov    esi,DWORD PTR [eax+0x10]
0x700895  8b5610                            mov    edx,DWORD PTR [esi+0x10]
0x700898  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x70089b  57                                push   edi
0x70089c  8b7d14                            mov    edi,DWORD PTR [ebp+0x14]
0x70089f  57                                push   edi
0x7008a0  53                                push   ebx
0x7008a1  51                                push   ecx
0x7008a2  52                                push   edx
0x7008a3  ffd0                              call   eax
0x7008a5  83c410                            add    esp,0x10
0x7008a8  85c0                              test   eax,eax
0x7008aa  750f                              jne    0x7008bb
0x7008ac  85ff                              test   edi,edi
0x7008ae  740b                              je     0x7008bb
0x7008b0  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x7008b3  6a04                              push   0x4
0x7008b5  51                                push   ecx
0x7008b6  e885d2ffff                        call   0x6fdb40
0x7008bb  2bfb                              sub    edi,ebx
0x7008bd  017e44                            add    DWORD PTR [esi+0x44],edi
0x7008c0  5f                                pop    edi
0x7008c1  5e                                pop    esi
0x7008c2  5b                                pop    ebx
0x7008c3  8be5                              mov    esp,ebp
0x7008c5  5d                                pop    ebp
0x7008c6  c3                                ret

; F_00897A66 VA 0x897a66 RAW 0x496e66 SHA256 f43e9975a8880e5f1b870f96784f3b3db5c850d2a355240aefa7754a8006173e
0x897a66  8bff                              mov    edi,edi
0x897a68  55                                push   ebp
0x897a69  8bec                              mov    ebp,esp
0x897a6b  837d0800                          cmp    DWORD PTR [ebp+0x8],0x0
0x897a6f  750b                              jne    0x897a7c
0x897a71  ff750c                            push   DWORD PTR [ebp+0xc]
0x897a74  e8efa5ffff                        call   0x892068
0x897a79  59                                pop    ecx
0x897a7a  5d                                pop    ebp
0x897a7b  c3                                ret
0x897a7c  56                                push   esi
0x897a7d  8b750c                            mov    esi,DWORD PTR [ebp+0xc]
0x897a80  85f6                              test   esi,esi
0x897a82  750d                              jne    0x897a91
0x897a84  ff7508                            push   DWORD PTR [ebp+0x8]
0x897a87  e870a6ffff                        call   0x8920fc
0x897a8c  59                                pop    ecx
0x897a8d  33c0                              xor    eax,eax
0x897a8f  eb4d                              jmp    0x897ade
0x897a91  57                                push   edi
0x897a92  eb30                              jmp    0x897ac4
0x897a94  85f6                              test   esi,esi
0x897a96  7501                              jne    0x897a99
0x897a98  46                                inc    esi
0x897a99  56                                push   esi
0x897a9a  ff7508                            push   DWORD PTR [ebp+0x8]
0x897a9d  6a00                              push   0x0
0x897a9f  ff35dcd4f800                      push   DWORD PTR ds:0xf8d4dc
0x897aa5  ff15e021bd00                      call   DWORD PTR ds:0xbd21e0
0x897aab  8bf8                              mov    edi,eax
0x897aad  85ff                              test   edi,edi
0x897aaf  755e                              jne    0x897b0f
0x897ab1  3905e0d4f800                      cmp    DWORD PTR ds:0xf8d4e0,eax
0x897ab7  7440                              je     0x897af9
0x897ab9  56                                push   esi
0x897aba  e8b86e0000                        call   0x89e977
0x897abf  59                                pop    ecx
0x897ac0  85c0                              test   eax,eax
0x897ac2  741d                              je     0x897ae1
0x897ac4  83fee0                            cmp    esi,0xffffffe0
0x897ac7  76cb                              jbe    0x897a94
0x897ac9  56                                push   esi
0x897aca  e8a86e0000                        call   0x89e977
0x897acf  59                                pop    ecx
0x897ad0  e8130c0000                        call   0x8986e8
0x897ad5  c7000c000000                      mov    DWORD PTR [eax],0xc
0x897adb  33c0                              xor    eax,eax
0x897add  5f                                pop    edi
0x897ade  5e                                pop    esi
0x897adf  5d                                pop    ebp
0x897ae0  c3                                ret
0x897ae1  e8020c0000                        call   0x8986e8
0x897ae6  8bf0                              mov    esi,eax
0x897ae8  ff150023bd00                      call   DWORD PTR ds:0xbd2300
0x897aee  50                                push   eax
0x897aef  e8b20b0000                        call   0x8986a6
0x897af4  59                                pop    ecx
0x897af5  8906                              mov    DWORD PTR [esi],eax
0x897af7  ebe2                              jmp    0x897adb
0x897af9  e8ea0b0000                        call   0x8986e8
0x897afe  8bf0                              mov    esi,eax
0x897b00  ff150023bd00                      call   DWORD PTR ds:0xbd2300
0x897b06  50                                push   eax
0x897b07  e89a0b0000                        call   0x8986a6
0x897b0c  59                                pop    ecx
0x897b0d  8906                              mov    DWORD PTR [esi],eax
0x897b0f  8bc7                              mov    eax,edi
0x897b11  ebca                              jmp    0x897add

