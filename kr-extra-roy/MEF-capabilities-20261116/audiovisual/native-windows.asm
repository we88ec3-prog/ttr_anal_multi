; B01_reg Q.PlayCameraWorks native/closure registrar
; VA 0x5662e0..0x566379 raw 0x1656e0 length 153 SHA256 aa282f7d1ce370e136e571db23f6258a7e3d9434ea87bf21c977eeb07310e6e6
0x5662e0  55                                push   ebp
0x5662e1  8bec                              mov    ebp,esp
0x5662e3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5662e6  53                                push   ebx
0x5662e7  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x5662ed  56                                push   esi
0x5662ee  8b33                              mov    esi,DWORD PTR [ebx]
0x5662f0  57                                push   edi
0x5662f1  8b38                              mov    edi,DWORD PTR [eax]
0x5662f3  b8eed8ffff                        mov    eax,0xffffd8ee
0x5662f8  c7059427fe00802b5600              mov    DWORD PTR ds:0xfe2794,0x562b80
0x566302  e879f31800                        call   0x6f5680
0x566307  8b03                              mov    eax,DWORD PTR [ebx]
0x566309  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x56630c  83e810                            sub    eax,0x10
0x56630f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x566314  7406                              je     0x56631c
0x566316  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x56631a  7414                              je     0x566330
0x56631c  57                                push   edi
0x56631d  68c426c400                        push   0xc426c4
0x566322  e896cd3200                        call   0x8930bd
0x566327  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566329  83c408                            add    esp,0x8
0x56632c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566330  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566336  8b37                              mov    esi,DWORD PTR [edi]
0x566338  68b8a2d600                        push   0xd6a2b8
0x56633d  e8cef11800                        call   0x6f5510
0x566342  8b37                              mov    esi,DWORD PTR [edi]
0x566344  83c404                            add    esp,0x4
0x566347  6a00                              push   0x0
0x566349  68808c5600                        push   0x568c80
0x56634e  e85df21800                        call   0x6f55b0
0x566353  8b0f                              mov    ecx,DWORD PTR [edi]
0x566355  51                                push   ecx
0x566356  b8fdffffff                        mov    eax,0xfffffffd
0x56635b  e890f41800                        call   0x6f57f0
0x566360  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x566366  8b02                              mov    eax,DWORD PTR [edx]
0x566368  83c40c                            add    esp,0xc
0x56636b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x56636f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566372  5f                                pop    edi
0x566373  5e                                pop    esi
0x566374  5b                                pop    ebx
0x566375  5d                                pop    ebp
0x566376  c20400                            ret    0x4

; B01_call Initializer direct call
; VA 0x56063a..0x56063f raw 0x15fa3a length 5 SHA256 5eef2d0c45dea651c255639b9ae7dc7c1b95f65eb64738253b060fa6754ae64b
0x56063a  e8a15c0000                        call   0x5662e0

; B01_closure Lua C closure for Q.PlayCameraWorks
; VA 0x568c80..0x568cdd raw 0x168080 length 93 SHA256 74a8f276d31835438032af575a7f23fbf11001994b95a40b7d1ecf196ab8dee4
0x568c80  55                                push   ebp
0x568c81  8bec                              mov    ebp,esp
0x568c83  6aff                              push   0xffffffff
0x568c85  68c8839300                        push   0x9383c8
0x568c8a  64a100000000                      mov    eax,fs:0x0
0x568c90  50                                push   eax
0x568c91  83ec0c                            sub    esp,0xc
0x568c94  a1201fd600                        mov    eax,ds:0xd61f20
0x568c99  33c5                              xor    eax,ebp
0x568c9b  50                                push   eax
0x568c9c  8d45f4                            lea    eax,[ebp-0xc]
0x568c9f  64a300000000                      mov    fs:0x0,eax
0x568ca5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x568ca8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x568cab  33c0                              xor    eax,eax
0x568cad  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x568cb0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x568cb3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x568cb6  8b0d9427fe00                      mov    ecx,DWORD PTR ds:0xfe2794
0x568cbc  51                                push   ecx
0x568cbd  8d55e8                            lea    edx,[ebp-0x18]
0x568cc0  52                                push   edx
0x568cc1  e89a160000                        call   0x56a360
0x568cc6  83c408                            add    esp,0x8
0x568cc9  b801000000                        mov    eax,0x1
0x568cce  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x568cd1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x568cd8  59                                pop    ecx
0x568cd9  8be5                              mov    esp,ebp
0x568cdb  5d                                pop    ebp
0x568cdc  c3                                ret

; B01_name Public binding ASCII name
; VA 0xd6a2b8..0xd6a2c8 raw 0x967ab8 length 16 SHA256 64805ee3c90787b2b63e50262f3efec04d94c9aef928df022d51c775c06dcf0b
; bytes 506c617943616d657261576f726b7300

; B02_reg Q.SkipCamera native/closure registrar
; VA 0x566380..0x566419 raw 0x165780 length 153 SHA256 315b1b493772c218369bbb049cb462e3ea93e2d93425f27d01d2d379f8cf5a7f
0x566380  55                                push   ebp
0x566381  8bec                              mov    ebp,esp
0x566383  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566386  53                                push   ebx
0x566387  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x56638d  56                                push   esi
0x56638e  8b33                              mov    esi,DWORD PTR [ebx]
0x566390  57                                push   edi
0x566391  8b38                              mov    edi,DWORD PTR [eax]
0x566393  b8eed8ffff                        mov    eax,0xffffd8ee
0x566398  c7059827fe00f02c5600              mov    DWORD PTR ds:0xfe2798,0x562cf0
0x5663a2  e8d9f21800                        call   0x6f5680
0x5663a7  8b03                              mov    eax,DWORD PTR [ebx]
0x5663a9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x5663ac  83e810                            sub    eax,0x10
0x5663af  3dc8bfc000                        cmp    eax,0xc0bfc8
0x5663b4  7406                              je     0x5663bc
0x5663b6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x5663ba  7414                              je     0x5663d0
0x5663bc  57                                push   edi
0x5663bd  68c426c400                        push   0xc426c4
0x5663c2  e8f6cc3200                        call   0x8930bd
0x5663c7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x5663c9  83c408                            add    esp,0x8
0x5663cc  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x5663d0  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x5663d6  8b37                              mov    esi,DWORD PTR [edi]
0x5663d8  68c8a2d600                        push   0xd6a2c8
0x5663dd  e82ef11800                        call   0x6f5510
0x5663e2  8b37                              mov    esi,DWORD PTR [edi]
0x5663e4  83c404                            add    esp,0x4
0x5663e7  6a00                              push   0x0
0x5663e9  68e08c5600                        push   0x568ce0
0x5663ee  e8bdf11800                        call   0x6f55b0
0x5663f3  8b0f                              mov    ecx,DWORD PTR [edi]
0x5663f5  51                                push   ecx
0x5663f6  b8fdffffff                        mov    eax,0xfffffffd
0x5663fb  e8f0f31800                        call   0x6f57f0
0x566400  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x566406  8b02                              mov    eax,DWORD PTR [edx]
0x566408  83c40c                            add    esp,0xc
0x56640b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x56640f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566412  5f                                pop    edi
0x566413  5e                                pop    esi
0x566414  5b                                pop    ebx
0x566415  5d                                pop    ebp
0x566416  c20400                            ret    0x4

; B02_call Initializer direct call
; VA 0x560640..0x560645 raw 0x15fa40 length 5 SHA256 e1c98e089bc24273103d69930a0bcd91883f3eb9c74216fe7f2a914ace21a966
0x560640  e83b5d0000                        call   0x566380

; B02_closure Lua C closure for Q.SkipCamera
; VA 0x568ce0..0x568d3c raw 0x1680e0 length 92 SHA256 f926f37ecfbbdd1b5bf01cbd12b6f62355ccd7e425f2f0f94af60e875ed65087
0x568ce0  55                                push   ebp
0x568ce1  8bec                              mov    ebp,esp
0x568ce3  6aff                              push   0xffffffff
0x568ce5  68c8839300                        push   0x9383c8
0x568cea  64a100000000                      mov    eax,fs:0x0
0x568cf0  50                                push   eax
0x568cf1  83ec0c                            sub    esp,0xc
0x568cf4  a1201fd600                        mov    eax,ds:0xd61f20
0x568cf9  33c5                              xor    eax,ebp
0x568cfb  50                                push   eax
0x568cfc  8d45f4                            lea    eax,[ebp-0xc]
0x568cff  64a300000000                      mov    fs:0x0,eax
0x568d05  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x568d08  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x568d0b  33c0                              xor    eax,eax
0x568d0d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x568d10  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x568d13  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x568d16  8b0d9827fe00                      mov    ecx,DWORD PTR ds:0xfe2798
0x568d1c  51                                push   ecx
0x568d1d  8d45e8                            lea    eax,[ebp-0x18]
0x568d20  e80b170000                        call   0x56a430
0x568d25  83c404                            add    esp,0x4
0x568d28  b801000000                        mov    eax,0x1
0x568d2d  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x568d30  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x568d37  59                                pop    ecx
0x568d38  8be5                              mov    esp,ebp
0x568d3a  5d                                pop    ebp
0x568d3b  c3                                ret

; B02_name Public binding ASCII name
; VA 0xd6a2c8..0xd6a2d3 raw 0x967ac8 length 11 SHA256 0598b0d35a874621dbcd9cd38a0e8188e969d0271c28a98d681dab401678a256
; bytes 536b697043616d65726100

; B03_reg Q.CameraEffect native/closure registrar
; VA 0x566420..0x5664b9 raw 0x165820 length 153 SHA256 89f95858f46c299206da50b7a5418ee1fdda89e8baac52732bf62baf2b7b2ddf
0x566420  55                                push   ebp
0x566421  8bec                              mov    ebp,esp
0x566423  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566426  53                                push   ebx
0x566427  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x56642d  56                                push   esi
0x56642e  8b33                              mov    esi,DWORD PTR [ebx]
0x566430  57                                push   edi
0x566431  8b38                              mov    edi,DWORD PTR [eax]
0x566433  b8eed8ffff                        mov    eax,0xffffd8ee
0x566438  c7059c27fe00c0505600              mov    DWORD PTR ds:0xfe279c,0x5650c0
0x566442  e839f21800                        call   0x6f5680
0x566447  8b03                              mov    eax,DWORD PTR [ebx]
0x566449  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x56644c  83e810                            sub    eax,0x10
0x56644f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x566454  7406                              je     0x56645c
0x566456  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x56645a  7414                              je     0x566470
0x56645c  57                                push   edi
0x56645d  68c426c400                        push   0xc426c4
0x566462  e856cc3200                        call   0x8930bd
0x566467  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566469  83c408                            add    esp,0x8
0x56646c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566470  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566476  8b37                              mov    esi,DWORD PTR [edi]
0x566478  68d4a2d600                        push   0xd6a2d4
0x56647d  e88ef01800                        call   0x6f5510
0x566482  8b37                              mov    esi,DWORD PTR [edi]
0x566484  83c404                            add    esp,0x4
0x566487  6a00                              push   0x0
0x566489  68408d5600                        push   0x568d40
0x56648e  e81df11800                        call   0x6f55b0
0x566493  8b0f                              mov    ecx,DWORD PTR [edi]
0x566495  51                                push   ecx
0x566496  b8fdffffff                        mov    eax,0xfffffffd
0x56649b  e850f31800                        call   0x6f57f0
0x5664a0  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x5664a6  8b02                              mov    eax,DWORD PTR [edx]
0x5664a8  83c40c                            add    esp,0xc
0x5664ab  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x5664af  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5664b2  5f                                pop    edi
0x5664b3  5e                                pop    esi
0x5664b4  5b                                pop    ebx
0x5664b5  5d                                pop    ebp
0x5664b6  c20400                            ret    0x4

; B03_call Initializer direct call
; VA 0x560646..0x56064b raw 0x15fa46 length 5 SHA256 8a71d07577e689ebb2d69dc5bfae8769c0f3e32fb74bddd579d7b8eed8e10f2b
0x560646  e8d55d0000                        call   0x566420

; B03_closure Lua C closure for Q.CameraEffect
; VA 0x568d40..0x568d9d raw 0x168140 length 93 SHA256 a8050ff789798df2d84f4bf2fff6cded6ad9c1139f3eff9d3c9f5fe490afd7fa
0x568d40  55                                push   ebp
0x568d41  8bec                              mov    ebp,esp
0x568d43  6aff                              push   0xffffffff
0x568d45  68c8839300                        push   0x9383c8
0x568d4a  64a100000000                      mov    eax,fs:0x0
0x568d50  50                                push   eax
0x568d51  83ec0c                            sub    esp,0xc
0x568d54  a1201fd600                        mov    eax,ds:0xd61f20
0x568d59  33c5                              xor    eax,ebp
0x568d5b  50                                push   eax
0x568d5c  8d45f4                            lea    eax,[ebp-0xc]
0x568d5f  64a300000000                      mov    fs:0x0,eax
0x568d65  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x568d68  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x568d6b  33c0                              xor    eax,eax
0x568d6d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x568d70  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x568d73  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x568d76  8b0d9c27fe00                      mov    ecx,DWORD PTR ds:0xfe279c
0x568d7c  51                                push   ecx
0x568d7d  8d55e8                            lea    edx,[ebp-0x18]
0x568d80  52                                push   edx
0x568d81  e82a170000                        call   0x56a4b0
0x568d86  83c408                            add    esp,0x8
0x568d89  b801000000                        mov    eax,0x1
0x568d8e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x568d91  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x568d98  59                                pop    ecx
0x568d99  8be5                              mov    esp,ebp
0x568d9b  5d                                pop    ebp
0x568d9c  c3                                ret

; B03_name Public binding ASCII name
; VA 0xd6a2d4..0xd6a2e1 raw 0x967ad4 length 13 SHA256 4566398cf58ba87aba22fe4d4f1714f8400f387eafc81ba1920b2b25c11218d4
; bytes 43616d65726145666665637400

; B04_reg Q.SetCameraPoint native/closure registrar
; VA 0x5664c0..0x566559 raw 0x1658c0 length 153 SHA256 2b6139228dfc28656b62ec53ae7dd37d6d108ffa3fb4b4b4303e166ae1984d82
0x5664c0  55                                push   ebp
0x5664c1  8bec                              mov    ebp,esp
0x5664c3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5664c6  53                                push   ebx
0x5664c7  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x5664cd  56                                push   esi
0x5664ce  8b33                              mov    esi,DWORD PTR [ebx]
0x5664d0  57                                push   edi
0x5664d1  8b38                              mov    edi,DWORD PTR [eax]
0x5664d3  b8eed8ffff                        mov    eax,0xffffd8ee
0x5664d8  c705a027fe00102e5600              mov    DWORD PTR ds:0xfe27a0,0x562e10
0x5664e2  e899f11800                        call   0x6f5680
0x5664e7  8b03                              mov    eax,DWORD PTR [ebx]
0x5664e9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x5664ec  83e810                            sub    eax,0x10
0x5664ef  3dc8bfc000                        cmp    eax,0xc0bfc8
0x5664f4  7406                              je     0x5664fc
0x5664f6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x5664fa  7414                              je     0x566510
0x5664fc  57                                push   edi
0x5664fd  68c426c400                        push   0xc426c4
0x566502  e8b6cb3200                        call   0x8930bd
0x566507  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566509  83c408                            add    esp,0x8
0x56650c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566510  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566516  8b37                              mov    esi,DWORD PTR [edi]
0x566518  68a8a2d600                        push   0xd6a2a8
0x56651d  e8eeef1800                        call   0x6f5510
0x566522  8b37                              mov    esi,DWORD PTR [edi]
0x566524  83c404                            add    esp,0x4
0x566527  6a00                              push   0x0
0x566529  68a08d5600                        push   0x568da0
0x56652e  e87df01800                        call   0x6f55b0
0x566533  8b0f                              mov    ecx,DWORD PTR [edi]
0x566535  51                                push   ecx
0x566536  b8fdffffff                        mov    eax,0xfffffffd
0x56653b  e8b0f21800                        call   0x6f57f0
0x566540  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x566546  8b02                              mov    eax,DWORD PTR [edx]
0x566548  83c40c                            add    esp,0xc
0x56654b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x56654f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566552  5f                                pop    edi
0x566553  5e                                pop    esi
0x566554  5b                                pop    ebx
0x566555  5d                                pop    ebp
0x566556  c20400                            ret    0x4

; B04_call Initializer direct call
; VA 0x56064c..0x560651 raw 0x15fa4c length 5 SHA256 4d841939f18973f04b9ad9c7ad69c00f609d8f8f8583b20bfeb3bf410b5da51e
0x56064c  e86f5e0000                        call   0x5664c0

; B04_closure Lua C closure for Q.SetCameraPoint
; VA 0x568da0..0x568dfd raw 0x1681a0 length 93 SHA256 841de1c212a5b3f7bd725fed7b50ef210839ab4706fd56cf8281ef13acf916c2
0x568da0  55                                push   ebp
0x568da1  8bec                              mov    ebp,esp
0x568da3  6aff                              push   0xffffffff
0x568da5  68c8839300                        push   0x9383c8
0x568daa  64a100000000                      mov    eax,fs:0x0
0x568db0  50                                push   eax
0x568db1  83ec0c                            sub    esp,0xc
0x568db4  a1201fd600                        mov    eax,ds:0xd61f20
0x568db9  33c5                              xor    eax,ebp
0x568dbb  50                                push   eax
0x568dbc  8d45f4                            lea    eax,[ebp-0xc]
0x568dbf  64a300000000                      mov    fs:0x0,eax
0x568dc5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x568dc8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x568dcb  33c0                              xor    eax,eax
0x568dcd  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x568dd0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x568dd3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x568dd6  8b0da027fe00                      mov    ecx,DWORD PTR ds:0xfe27a0
0x568ddc  51                                push   ecx
0x568ddd  8d55e8                            lea    edx,[ebp-0x18]
0x568de0  52                                push   edx
0x568de1  e80a180000                        call   0x56a5f0
0x568de6  83c408                            add    esp,0x8
0x568de9  b801000000                        mov    eax,0x1
0x568dee  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x568df1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x568df8  59                                pop    ecx
0x568df9  8be5                              mov    esp,ebp
0x568dfb  5d                                pop    ebp
0x568dfc  c3                                ret

; B04_name Public binding ASCII name
; VA 0xd6a2a8..0xd6a2b7 raw 0x967aa8 length 15 SHA256 f1d1ad0ae3f7381d8fae10cbae43069e909cd92c16b3939bc8df81a308d371fc
; bytes 53657443616d657261506f696e7400

; B05_reg Q.Transition native/closure registrar
; VA 0x566920..0x5669b9 raw 0x165d20 length 153 SHA256 f55919eb6b4e72d21f3f1b027b16b92ce7ade5fa59fab752f33c75ea32a16fed
0x566920  55                                push   ebp
0x566921  8bec                              mov    ebp,esp
0x566923  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566926  53                                push   ebx
0x566927  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x56692d  56                                push   esi
0x56692e  8b33                              mov    esi,DWORD PTR [ebx]
0x566930  57                                push   edi
0x566931  8b38                              mov    edi,DWORD PTR [eax]
0x566933  b8eed8ffff                        mov    eax,0xffffd8ee
0x566938  c705bc27fe00a0465600              mov    DWORD PTR ds:0xfe27bc,0x5646a0
0x566942  e839ed1800                        call   0x6f5680
0x566947  8b03                              mov    eax,DWORD PTR [ebx]
0x566949  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x56694c  83e810                            sub    eax,0x10
0x56694f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x566954  7406                              je     0x56695c
0x566956  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x56695a  7414                              je     0x566970
0x56695c  57                                push   edi
0x56695d  68c426c400                        push   0xc426c4
0x566962  e856c73200                        call   0x8930bd
0x566967  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566969  83c408                            add    esp,0x8
0x56696c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566970  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566976  8b37                              mov    esi,DWORD PTR [edi]
0x566978  6848a3d600                        push   0xd6a348
0x56697d  e88eeb1800                        call   0x6f5510
0x566982  8b37                              mov    esi,DWORD PTR [edi]
0x566984  83c404                            add    esp,0x4
0x566987  6a00                              push   0x0
0x566989  6840905600                        push   0x569040
0x56698e  e81dec1800                        call   0x6f55b0
0x566993  8b0f                              mov    ecx,DWORD PTR [edi]
0x566995  51                                push   ecx
0x566996  b8fdffffff                        mov    eax,0xfffffffd
0x56699b  e850ee1800                        call   0x6f57f0
0x5669a0  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x5669a6  8b02                              mov    eax,DWORD PTR [edx]
0x5669a8  83c40c                            add    esp,0xc
0x5669ab  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x5669af  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5669b2  5f                                pop    edi
0x5669b3  5e                                pop    esi
0x5669b4  5b                                pop    ebx
0x5669b5  5d                                pop    ebp
0x5669b6  c20400                            ret    0x4

; B05_call Initializer direct call
; VA 0x560676..0x56067b raw 0x15fa76 length 5 SHA256 001c7fbd7149fafd23bf8ba8bcd49a9cabecd854b6e317987147eb9e12399c94
0x560676  e8a5620000                        call   0x566920

; B05_closure Lua C closure for Q.Transition
; VA 0x569040..0x56909d raw 0x168440 length 93 SHA256 f93393911ecc154ba69b2eec63ee819756d80a92906d074c4338c34ad149a7b0
0x569040  55                                push   ebp
0x569041  8bec                              mov    ebp,esp
0x569043  6aff                              push   0xffffffff
0x569045  68c8839300                        push   0x9383c8
0x56904a  64a100000000                      mov    eax,fs:0x0
0x569050  50                                push   eax
0x569051  83ec0c                            sub    esp,0xc
0x569054  a1201fd600                        mov    eax,ds:0xd61f20
0x569059  33c5                              xor    eax,ebp
0x56905b  50                                push   eax
0x56905c  8d45f4                            lea    eax,[ebp-0xc]
0x56905f  64a300000000                      mov    fs:0x0,eax
0x569065  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569068  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x56906b  33c0                              xor    eax,eax
0x56906d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569070  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569073  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569076  8b0dbc27fe00                      mov    ecx,DWORD PTR ds:0xfe27bc
0x56907c  51                                push   ecx
0x56907d  8d55e8                            lea    edx,[ebp-0x18]
0x569080  52                                push   edx
0x569081  e89a110000                        call   0x56a220
0x569086  83c408                            add    esp,0x8
0x569089  b801000000                        mov    eax,0x1
0x56908e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x569091  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569098  59                                pop    ecx
0x569099  8be5                              mov    esp,ebp
0x56909b  5d                                pop    ebp
0x56909c  c3                                ret

; B05_name Public binding ASCII name
; VA 0xd6a348..0xd6a353 raw 0x967b48 length 11 SHA256 a557c6f82f9a35c46483a707e7d35c4e29132c378501295fc27c616d907251c3
; bytes 5472616e736974696f6e00

; B06_reg Q.PlayMusic native/closure registrar
; VA 0x5669c0..0x566a59 raw 0x165dc0 length 153 SHA256 c37f0d021c13c800001cc68f1fca3dd6205124934567f7f5bb90125892e6a9e7
0x5669c0  55                                push   ebp
0x5669c1  8bec                              mov    ebp,esp
0x5669c3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5669c6  53                                push   ebx
0x5669c7  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x5669cd  56                                push   esi
0x5669ce  8b33                              mov    esi,DWORD PTR [ebx]
0x5669d0  57                                push   edi
0x5669d1  8b38                              mov    edi,DWORD PTR [eax]
0x5669d3  b8eed8ffff                        mov    eax,0xffffd8ee
0x5669d8  c705c027fe00c0435600              mov    DWORD PTR ds:0xfe27c0,0x5643c0
0x5669e2  e899ec1800                        call   0x6f5680
0x5669e7  8b03                              mov    eax,DWORD PTR [ebx]
0x5669e9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x5669ec  83e810                            sub    eax,0x10
0x5669ef  3dc8bfc000                        cmp    eax,0xc0bfc8
0x5669f4  7406                              je     0x5669fc
0x5669f6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x5669fa  7414                              je     0x566a10
0x5669fc  57                                push   edi
0x5669fd  68c426c400                        push   0xc426c4
0x566a02  e8b6c63200                        call   0x8930bd
0x566a07  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566a09  83c408                            add    esp,0x8
0x566a0c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566a10  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566a16  8b37                              mov    esi,DWORD PTR [edi]
0x566a18  6854a3d600                        push   0xd6a354
0x566a1d  e8eeea1800                        call   0x6f5510
0x566a22  8b37                              mov    esi,DWORD PTR [edi]
0x566a24  83c404                            add    esp,0x4
0x566a27  6a00                              push   0x0
0x566a29  68a0905600                        push   0x5690a0
0x566a2e  e87deb1800                        call   0x6f55b0
0x566a33  8b0f                              mov    ecx,DWORD PTR [edi]
0x566a35  51                                push   ecx
0x566a36  b8fdffffff                        mov    eax,0xfffffffd
0x566a3b  e8b0ed1800                        call   0x6f57f0
0x566a40  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x566a46  8b02                              mov    eax,DWORD PTR [edx]
0x566a48  83c40c                            add    esp,0xc
0x566a4b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x566a4f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566a52  5f                                pop    edi
0x566a53  5e                                pop    esi
0x566a54  5b                                pop    ebx
0x566a55  5d                                pop    ebp
0x566a56  c20400                            ret    0x4

; B06_call Initializer direct call
; VA 0x56067c..0x560681 raw 0x15fa7c length 5 SHA256 4ab5c4ea08d6cd0ea26db0d50938230a61d3b19d456e24962421089b9096b8f4
0x56067c  e83f630000                        call   0x5669c0

; B06_closure Lua C closure for Q.PlayMusic
; VA 0x5690a0..0x5690fd raw 0x1684a0 length 93 SHA256 b4671753575581f77b06d40d38f4cfce83b06ddfeb15b923292d80677f0a14db
0x5690a0  55                                push   ebp
0x5690a1  8bec                              mov    ebp,esp
0x5690a3  6aff                              push   0xffffffff
0x5690a5  68c8839300                        push   0x9383c8
0x5690aa  64a100000000                      mov    eax,fs:0x0
0x5690b0  50                                push   eax
0x5690b1  83ec0c                            sub    esp,0xc
0x5690b4  a1201fd600                        mov    eax,ds:0xd61f20
0x5690b9  33c5                              xor    eax,ebp
0x5690bb  50                                push   eax
0x5690bc  8d45f4                            lea    eax,[ebp-0xc]
0x5690bf  64a300000000                      mov    fs:0x0,eax
0x5690c5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5690c8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x5690cb  33c0                              xor    eax,eax
0x5690cd  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5690d0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5690d3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5690d6  8b0dc027fe00                      mov    ecx,DWORD PTR ds:0xfe27c0
0x5690dc  51                                push   ecx
0x5690dd  8d55e8                            lea    edx,[ebp-0x18]
0x5690e0  52                                push   edx
0x5690e1  e87a120000                        call   0x56a360
0x5690e6  83c408                            add    esp,0x8
0x5690e9  b801000000                        mov    eax,0x1
0x5690ee  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5690f1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5690f8  59                                pop    ecx
0x5690f9  8be5                              mov    esp,ebp
0x5690fb  5d                                pop    ebp
0x5690fc  c3                                ret

; B06_name Public binding ASCII name
; VA 0xd6a354..0xd6a35e raw 0x967b54 length 10 SHA256 9d96e7afbf342dbf0a859d165b8d7d204a982de21c522b52a79827827e73fed3
; bytes 506c61794d7573696300

; B07_reg Q.StopMusic native/closure registrar
; VA 0x566a60..0x566af9 raw 0x165e60 length 153 SHA256 f3eec419a04d55dc5f343cd28afcb1605ce230b4024b7b8765f301a6b3d2bae6
0x566a60  55                                push   ebp
0x566a61  8bec                              mov    ebp,esp
0x566a63  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566a66  53                                push   ebx
0x566a67  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x566a6d  56                                push   esi
0x566a6e  8b33                              mov    esi,DWORD PTR [ebx]
0x566a70  57                                push   edi
0x566a71  8b38                              mov    edi,DWORD PTR [eax]
0x566a73  b8eed8ffff                        mov    eax,0xffffd8ee
0x566a78  c705c427fe0000455600              mov    DWORD PTR ds:0xfe27c4,0x564500
0x566a82  e8f9eb1800                        call   0x6f5680
0x566a87  8b03                              mov    eax,DWORD PTR [ebx]
0x566a89  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x566a8c  83e810                            sub    eax,0x10
0x566a8f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x566a94  7406                              je     0x566a9c
0x566a96  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x566a9a  7414                              je     0x566ab0
0x566a9c  57                                push   edi
0x566a9d  68c426c400                        push   0xc426c4
0x566aa2  e816c63200                        call   0x8930bd
0x566aa7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566aa9  83c408                            add    esp,0x8
0x566aac  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566ab0  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566ab6  8b37                              mov    esi,DWORD PTR [edi]
0x566ab8  6860a3d600                        push   0xd6a360
0x566abd  e84eea1800                        call   0x6f5510
0x566ac2  8b37                              mov    esi,DWORD PTR [edi]
0x566ac4  83c404                            add    esp,0x4
0x566ac7  6a00                              push   0x0
0x566ac9  6800915600                        push   0x569100
0x566ace  e8ddea1800                        call   0x6f55b0
0x566ad3  8b0f                              mov    ecx,DWORD PTR [edi]
0x566ad5  51                                push   ecx
0x566ad6  b8fdffffff                        mov    eax,0xfffffffd
0x566adb  e810ed1800                        call   0x6f57f0
0x566ae0  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x566ae6  8b02                              mov    eax,DWORD PTR [edx]
0x566ae8  83c40c                            add    esp,0xc
0x566aeb  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x566aef  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566af2  5f                                pop    edi
0x566af3  5e                                pop    esi
0x566af4  5b                                pop    ebx
0x566af5  5d                                pop    ebp
0x566af6  c20400                            ret    0x4

; B07_call Initializer direct call
; VA 0x560682..0x560687 raw 0x15fa82 length 5 SHA256 c8cfcc47bb505e06c2ee3c49a94241562d5e95b6e81809e65e9aa91ec904027d
0x560682  e8d9630000                        call   0x566a60

; B07_closure Lua C closure for Q.StopMusic
; VA 0x569100..0x569156 raw 0x168500 length 86 SHA256 b8fb3680768c94da5e12f60935f4dd945ca688e05f62170a1353608663cfb86a
0x569100  55                                push   ebp
0x569101  8bec                              mov    ebp,esp
0x569103  6aff                              push   0xffffffff
0x569105  68c8839300                        push   0x9383c8
0x56910a  64a100000000                      mov    eax,fs:0x0
0x569110  50                                push   eax
0x569111  83ec0c                            sub    esp,0xc
0x569114  a1201fd600                        mov    eax,ds:0xd61f20
0x569119  33c5                              xor    eax,ebp
0x56911b  50                                push   eax
0x56911c  8d45f4                            lea    eax,[ebp-0xc]
0x56911f  64a300000000                      mov    fs:0x0,eax
0x569125  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569128  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x56912b  33c0                              xor    eax,eax
0x56912d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569130  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569133  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569136  8b0d7827fe00                      mov    ecx,DWORD PTR ds:0xfe2778
0x56913c  ff15c427fe00                      call   DWORD PTR ds:0xfe27c4
0x569142  b801000000                        mov    eax,0x1
0x569147  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x56914a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569151  59                                pop    ecx
0x569152  8be5                              mov    esp,ebp
0x569154  5d                                pop    ebp
0x569155  c3                                ret

; B07_name Public binding ASCII name
; VA 0xd6a360..0xd6a36a raw 0x967b60 length 10 SHA256 d1b24a6e2850c0758f52d943155dc8c097e40ada7db258a505b42e4750880537
; bytes 53746f704d7573696300

; B08_reg Q.StopMusicWithFadeOut native/closure registrar
; VA 0x566b00..0x566b99 raw 0x165f00 length 153 SHA256 5a02d90fd2f069829c728139393c51116b01d474b55d7a0951bd546060aa8150
0x566b00  55                                push   ebp
0x566b01  8bec                              mov    ebp,esp
0x566b03  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566b06  53                                push   ebx
0x566b07  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x566b0d  56                                push   esi
0x566b0e  8b33                              mov    esi,DWORD PTR [ebx]
0x566b10  57                                push   edi
0x566b11  8b38                              mov    edi,DWORD PTR [eax]
0x566b13  b8eed8ffff                        mov    eax,0xffffd8ee
0x566b18  c705c827fe0080455600              mov    DWORD PTR ds:0xfe27c8,0x564580
0x566b22  e859eb1800                        call   0x6f5680
0x566b27  8b03                              mov    eax,DWORD PTR [ebx]
0x566b29  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x566b2c  83e810                            sub    eax,0x10
0x566b2f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x566b34  7406                              je     0x566b3c
0x566b36  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x566b3a  7414                              je     0x566b50
0x566b3c  57                                push   edi
0x566b3d  68c426c400                        push   0xc426c4
0x566b42  e876c53200                        call   0x8930bd
0x566b47  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566b49  83c408                            add    esp,0x8
0x566b4c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566b50  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566b56  8b37                              mov    esi,DWORD PTR [edi]
0x566b58  686ca3d600                        push   0xd6a36c
0x566b5d  e8aee91800                        call   0x6f5510
0x566b62  8b37                              mov    esi,DWORD PTR [edi]
0x566b64  83c404                            add    esp,0x4
0x566b67  6a00                              push   0x0
0x566b69  6860915600                        push   0x569160
0x566b6e  e83dea1800                        call   0x6f55b0
0x566b73  8b0f                              mov    ecx,DWORD PTR [edi]
0x566b75  51                                push   ecx
0x566b76  b8fdffffff                        mov    eax,0xfffffffd
0x566b7b  e870ec1800                        call   0x6f57f0
0x566b80  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x566b86  8b02                              mov    eax,DWORD PTR [edx]
0x566b88  83c40c                            add    esp,0xc
0x566b8b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x566b8f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566b92  5f                                pop    edi
0x566b93  5e                                pop    esi
0x566b94  5b                                pop    ebx
0x566b95  5d                                pop    ebp
0x566b96  c20400                            ret    0x4

; B08_call Initializer direct call
; VA 0x560688..0x56068d raw 0x15fa88 length 5 SHA256 1985df8dfb9060f88ae83fd9829dcea766302f53e806a22888b6845429bccedd
0x560688  e873640000                        call   0x566b00

; B08_closure Lua C closure for Q.StopMusicWithFadeOut
; VA 0x569160..0x5691bc raw 0x168560 length 92 SHA256 599fa964d4a30ba0a385ef4a09d1f15d452e912ff967afb0a7c520817f501589
0x569160  55                                push   ebp
0x569161  8bec                              mov    ebp,esp
0x569163  6aff                              push   0xffffffff
0x569165  68c8839300                        push   0x9383c8
0x56916a  64a100000000                      mov    eax,fs:0x0
0x569170  50                                push   eax
0x569171  83ec0c                            sub    esp,0xc
0x569174  a1201fd600                        mov    eax,ds:0xd61f20
0x569179  33c5                              xor    eax,ebp
0x56917b  50                                push   eax
0x56917c  8d45f4                            lea    eax,[ebp-0xc]
0x56917f  64a300000000                      mov    fs:0x0,eax
0x569185  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569188  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x56918b  33c0                              xor    eax,eax
0x56918d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569190  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569193  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569196  8b0dc827fe00                      mov    ecx,DWORD PTR ds:0xfe27c8
0x56919c  51                                push   ecx
0x56919d  8d45e8                            lea    eax,[ebp-0x18]
0x5691a0  e88b120000                        call   0x56a430
0x5691a5  83c404                            add    esp,0x4
0x5691a8  b801000000                        mov    eax,0x1
0x5691ad  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5691b0  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5691b7  59                                pop    ecx
0x5691b8  8be5                              mov    esp,ebp
0x5691ba  5d                                pop    ebp
0x5691bb  c3                                ret

; B08_name Public binding ASCII name
; VA 0xd6a36c..0xd6a381 raw 0x967b6c length 21 SHA256 eaec198e6c4103636f2f5bf099d12fa1a14cb5a6c5b73a786e37303ca1b4e790
; bytes 53746f704d7573696357697468466164654f757400

; B09_reg Q.MoveCamera native/closure registrar
; VA 0x566ce0..0x566d79 raw 0x1660e0 length 153 SHA256 3825a157aef81692e6215f81c86be67db2899e6c2827d7cc8809d4b227947294
0x566ce0  55                                push   ebp
0x566ce1  8bec                              mov    ebp,esp
0x566ce3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566ce6  53                                push   ebx
0x566ce7  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x566ced  56                                push   esi
0x566cee  8b33                              mov    esi,DWORD PTR [ebx]
0x566cf0  57                                push   edi
0x566cf1  8b38                              mov    edi,DWORD PTR [eax]
0x566cf3  b8eed8ffff                        mov    eax,0xffffd8ee
0x566cf8  c705d427fe00102e5600              mov    DWORD PTR ds:0xfe27d4,0x562e10
0x566d02  e879e91800                        call   0x6f5680
0x566d07  8b03                              mov    eax,DWORD PTR [ebx]
0x566d09  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x566d0c  83e810                            sub    eax,0x10
0x566d0f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x566d14  7406                              je     0x566d1c
0x566d16  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x566d1a  7414                              je     0x566d30
0x566d1c  57                                push   edi
0x566d1d  68c426c400                        push   0xc426c4
0x566d22  e896c33200                        call   0x8930bd
0x566d27  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566d29  83c408                            add    esp,0x8
0x566d2c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566d30  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566d36  8b37                              mov    esi,DWORD PTR [edi]
0x566d38  68a4a3d600                        push   0xd6a3a4
0x566d3d  e8cee71800                        call   0x6f5510
0x566d42  8b37                              mov    esi,DWORD PTR [edi]
0x566d44  83c404                            add    esp,0x4
0x566d47  6a00                              push   0x0
0x566d49  6880925600                        push   0x569280
0x566d4e  e85de81800                        call   0x6f55b0
0x566d53  8b0f                              mov    ecx,DWORD PTR [edi]
0x566d55  51                                push   ecx
0x566d56  b8fdffffff                        mov    eax,0xfffffffd
0x566d5b  e890ea1800                        call   0x6f57f0
0x566d60  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x566d66  8b02                              mov    eax,DWORD PTR [edx]
0x566d68  83c40c                            add    esp,0xc
0x566d6b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x566d6f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566d72  5f                                pop    edi
0x566d73  5e                                pop    esi
0x566d74  5b                                pop    ebx
0x566d75  5d                                pop    ebp
0x566d76  c20400                            ret    0x4

; B09_call Initializer direct call
; VA 0x56069a..0x56069f raw 0x15fa9a length 5 SHA256 6ede2258bd42ad8c8c4ae348cdc3d1c2e79ff971194ec7ecc0e4ed5fd6362c88
0x56069a  e841660000                        call   0x566ce0

; B09_closure Lua C closure for Q.MoveCamera
; VA 0x569280..0x5692dd raw 0x168680 length 93 SHA256 a14a154d0f0830c3fd5b8b2177adcd9445d9b6d500212403357bdc5545a4523a
0x569280  55                                push   ebp
0x569281  8bec                              mov    ebp,esp
0x569283  6aff                              push   0xffffffff
0x569285  68c8839300                        push   0x9383c8
0x56928a  64a100000000                      mov    eax,fs:0x0
0x569290  50                                push   eax
0x569291  83ec0c                            sub    esp,0xc
0x569294  a1201fd600                        mov    eax,ds:0xd61f20
0x569299  33c5                              xor    eax,ebp
0x56929b  50                                push   eax
0x56929c  8d45f4                            lea    eax,[ebp-0xc]
0x56929f  64a300000000                      mov    fs:0x0,eax
0x5692a5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5692a8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x5692ab  33c0                              xor    eax,eax
0x5692ad  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5692b0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5692b3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5692b6  8b0dd427fe00                      mov    ecx,DWORD PTR ds:0xfe27d4
0x5692bc  51                                push   ecx
0x5692bd  8d55e8                            lea    edx,[ebp-0x18]
0x5692c0  52                                push   edx
0x5692c1  e82a130000                        call   0x56a5f0
0x5692c6  83c408                            add    esp,0x8
0x5692c9  b801000000                        mov    eax,0x1
0x5692ce  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5692d1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5692d8  59                                pop    ecx
0x5692d9  8be5                              mov    esp,ebp
0x5692db  5d                                pop    ebp
0x5692dc  c3                                ret

; B09_name Public binding ASCII name
; VA 0xd6a3a4..0xd6a3af raw 0x967ba4 length 11 SHA256 eca42f7236ec5ac8cb71ca6a9e2a2cee84277bc49f537ca87923d37e4a2e0718
; bytes 4d6f766543616d65726100

; B10_reg Q.RotCamera native/closure registrar
; VA 0x566d80..0x566e19 raw 0x166180 length 153 SHA256 7251a1cbdfa9e2b0fb5fcdd4c01b5b24cff4f727a4e5597f3e6cc6390aa7a6d9
0x566d80  55                                push   ebp
0x566d81  8bec                              mov    ebp,esp
0x566d83  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566d86  53                                push   ebx
0x566d87  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x566d8d  56                                push   esi
0x566d8e  8b33                              mov    esi,DWORD PTR [ebx]
0x566d90  57                                push   edi
0x566d91  8b38                              mov    edi,DWORD PTR [eax]
0x566d93  b8eed8ffff                        mov    eax,0xffffd8ee
0x566d98  c705d827fe0070395600              mov    DWORD PTR ds:0xfe27d8,0x563970
0x566da2  e8d9e81800                        call   0x6f5680
0x566da7  8b03                              mov    eax,DWORD PTR [ebx]
0x566da9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x566dac  83e810                            sub    eax,0x10
0x566daf  3dc8bfc000                        cmp    eax,0xc0bfc8
0x566db4  7406                              je     0x566dbc
0x566db6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x566dba  7414                              je     0x566dd0
0x566dbc  57                                push   edi
0x566dbd  68c426c400                        push   0xc426c4
0x566dc2  e8f6c23200                        call   0x8930bd
0x566dc7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x566dc9  83c408                            add    esp,0x8
0x566dcc  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x566dd0  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x566dd6  8b37                              mov    esi,DWORD PTR [edi]
0x566dd8  68b0a3d600                        push   0xd6a3b0
0x566ddd  e82ee71800                        call   0x6f5510
0x566de2  8b37                              mov    esi,DWORD PTR [edi]
0x566de4  83c404                            add    esp,0x4
0x566de7  6a00                              push   0x0
0x566de9  68e0925600                        push   0x5692e0
0x566dee  e8bde71800                        call   0x6f55b0
0x566df3  8b0f                              mov    ecx,DWORD PTR [edi]
0x566df5  51                                push   ecx
0x566df6  b8fdffffff                        mov    eax,0xfffffffd
0x566dfb  e8f0e91800                        call   0x6f57f0
0x566e00  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x566e06  8b02                              mov    eax,DWORD PTR [edx]
0x566e08  83c40c                            add    esp,0xc
0x566e0b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x566e0f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x566e12  5f                                pop    edi
0x566e13  5e                                pop    esi
0x566e14  5b                                pop    ebx
0x566e15  5d                                pop    ebp
0x566e16  c20400                            ret    0x4

; B10_call Initializer direct call
; VA 0x5606a0..0x5606a5 raw 0x15faa0 length 5 SHA256 621b4dab2587cd97589e93bdb17a0d8130f05921bf1a99adac4c54380ed9c422
0x5606a0  e8db660000                        call   0x566d80

; B10_closure Lua C closure for Q.RotCamera
; VA 0x5692e0..0x56933d raw 0x1686e0 length 93 SHA256 5d6c593881749553b6ddc57dd9f0d3e082bc2b2ad34ab7c3638fde39fe3ded1f
0x5692e0  55                                push   ebp
0x5692e1  8bec                              mov    ebp,esp
0x5692e3  6aff                              push   0xffffffff
0x5692e5  68c8839300                        push   0x9383c8
0x5692ea  64a100000000                      mov    eax,fs:0x0
0x5692f0  50                                push   eax
0x5692f1  83ec0c                            sub    esp,0xc
0x5692f4  a1201fd600                        mov    eax,ds:0xd61f20
0x5692f9  33c5                              xor    eax,ebp
0x5692fb  50                                push   eax
0x5692fc  8d45f4                            lea    eax,[ebp-0xc]
0x5692ff  64a300000000                      mov    fs:0x0,eax
0x569305  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569308  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x56930b  33c0                              xor    eax,eax
0x56930d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569310  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569313  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569316  8b0dd827fe00                      mov    ecx,DWORD PTR ds:0xfe27d8
0x56931c  51                                push   ecx
0x56931d  8d55e8                            lea    edx,[ebp-0x18]
0x569320  52                                push   edx
0x569321  e8ca120000                        call   0x56a5f0
0x569326  83c408                            add    esp,0x8
0x569329  b801000000                        mov    eax,0x1
0x56932e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x569331  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569338  59                                pop    ecx
0x569339  8be5                              mov    esp,ebp
0x56933b  5d                                pop    ebp
0x56933c  c3                                ret

; B10_name Public binding ASCII name
; VA 0xd6a3b0..0xd6a3ba raw 0x967bb0 length 10 SHA256 4c0b7429604e39751f0a2e17534a264f5ffc32d94d8b3e676ae826b9c33af43f
; bytes 526f7443616d65726100

; B11_reg Q.PlaySound native/closure registrar
; VA 0x567be0..0x567c79 raw 0x166fe0 length 153 SHA256 bda469a3a9b67cbbe1b9cb013e155c25594f9e374733b37648da0c78b70d670c
0x567be0  55                                push   ebp
0x567be1  8bec                              mov    ebp,esp
0x567be3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567be6  53                                push   ebx
0x567be7  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x567bed  56                                push   esi
0x567bee  8b33                              mov    esi,DWORD PTR [ebx]
0x567bf0  57                                push   edi
0x567bf1  8b38                              mov    edi,DWORD PTR [eax]
0x567bf3  b8eed8ffff                        mov    eax,0xffffd8ee
0x567bf8  c7053428fe00c04c5600              mov    DWORD PTR ds:0xfe2834,0x564cc0
0x567c02  e879da1800                        call   0x6f5680
0x567c07  8b03                              mov    eax,DWORD PTR [ebx]
0x567c09  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x567c0c  83e810                            sub    eax,0x10
0x567c0f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x567c14  7406                              je     0x567c1c
0x567c16  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x567c1a  7414                              je     0x567c30
0x567c1c  57                                push   edi
0x567c1d  68c426c400                        push   0xc426c4
0x567c22  e896b43200                        call   0x8930bd
0x567c27  8b1b                              mov    ebx,DWORD PTR [ebx]
0x567c29  83c408                            add    esp,0x8
0x567c2c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x567c30  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x567c36  8b37                              mov    esi,DWORD PTR [edi]
0x567c38  68e8a4d600                        push   0xd6a4e8
0x567c3d  e8ced81800                        call   0x6f5510
0x567c42  8b37                              mov    esi,DWORD PTR [edi]
0x567c44  83c404                            add    esp,0x4
0x567c47  6a00                              push   0x0
0x567c49  68a09b5600                        push   0x569ba0
0x567c4e  e85dd91800                        call   0x6f55b0
0x567c53  8b0f                              mov    ecx,DWORD PTR [edi]
0x567c55  51                                push   ecx
0x567c56  b8fdffffff                        mov    eax,0xfffffffd
0x567c5b  e890db1800                        call   0x6f57f0
0x567c60  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x567c66  8b02                              mov    eax,DWORD PTR [edx]
0x567c68  83c40c                            add    esp,0xc
0x567c6b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x567c6f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567c72  5f                                pop    edi
0x567c73  5e                                pop    esi
0x567c74  5b                                pop    ebx
0x567c75  5d                                pop    ebp
0x567c76  c20400                            ret    0x4

; B11_call Initializer direct call
; VA 0x56072a..0x56072f raw 0x15fb2a length 5 SHA256 28a9c983a9fa535cffcbac3b21e788313b35a0be1c211314b8bf49b69dcb3a40
0x56072a  e8b1740000                        call   0x567be0

; B11_closure Lua C closure for Q.PlaySound
; VA 0x569ba0..0x569bfc raw 0x168fa0 length 92 SHA256 d407722a5799de7fdcd9084ae9dab5cfd5b54111c64bba8fec995edc7b945d20
0x569ba0  55                                push   ebp
0x569ba1  8bec                              mov    ebp,esp
0x569ba3  6aff                              push   0xffffffff
0x569ba5  68c8839300                        push   0x9383c8
0x569baa  64a100000000                      mov    eax,fs:0x0
0x569bb0  50                                push   eax
0x569bb1  83ec0c                            sub    esp,0xc
0x569bb4  a1201fd600                        mov    eax,ds:0xd61f20
0x569bb9  33c5                              xor    eax,ebp
0x569bbb  50                                push   eax
0x569bbc  8d45f4                            lea    eax,[ebp-0xc]
0x569bbf  64a300000000                      mov    fs:0x0,eax
0x569bc5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569bc8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x569bcb  33c0                              xor    eax,eax
0x569bcd  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569bd0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569bd3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569bd6  8b0d3428fe00                      mov    ecx,DWORD PTR ds:0xfe2834
0x569bdc  51                                push   ecx
0x569bdd  8d45e8                            lea    eax,[ebp-0x18]
0x569be0  e81b070000                        call   0x56a300
0x569be5  83c404                            add    esp,0x4
0x569be8  b801000000                        mov    eax,0x1
0x569bed  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x569bf0  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569bf7  59                                pop    ecx
0x569bf8  8be5                              mov    esp,ebp
0x569bfa  5d                                pop    ebp
0x569bfb  c3                                ret

; B11_name Public binding ASCII name
; VA 0xd6a4e8..0xd6a4f2 raw 0x967ce8 length 10 SHA256 dea5f3776fcc718273c392f68b3e4def9d9e894b905651763bdd8e635555c3e5
; bytes 506c6179536f756e6400

; B12_reg Q.PlayTalkSound native/closure registrar
; VA 0x567c80..0x567d19 raw 0x167080 length 153 SHA256 465ad47e3f7685a2bf9101d9adf32a494c500e9d8935218836680fbe23291ff0
0x567c80  55                                push   ebp
0x567c81  8bec                              mov    ebp,esp
0x567c83  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567c86  53                                push   ebx
0x567c87  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x567c8d  56                                push   esi
0x567c8e  8b33                              mov    esi,DWORD PTR [ebx]
0x567c90  57                                push   edi
0x567c91  8b38                              mov    edi,DWORD PTR [eax]
0x567c93  b8eed8ffff                        mov    eax,0xffffd8ee
0x567c98  c7053828fe00904d5600              mov    DWORD PTR ds:0xfe2838,0x564d90
0x567ca2  e8d9d91800                        call   0x6f5680
0x567ca7  8b03                              mov    eax,DWORD PTR [ebx]
0x567ca9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x567cac  83e810                            sub    eax,0x10
0x567caf  3dc8bfc000                        cmp    eax,0xc0bfc8
0x567cb4  7406                              je     0x567cbc
0x567cb6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x567cba  7414                              je     0x567cd0
0x567cbc  57                                push   edi
0x567cbd  68c426c400                        push   0xc426c4
0x567cc2  e8f6b33200                        call   0x8930bd
0x567cc7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x567cc9  83c408                            add    esp,0x8
0x567ccc  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x567cd0  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x567cd6  8b37                              mov    esi,DWORD PTR [edi]
0x567cd8  68f4a4d600                        push   0xd6a4f4
0x567cdd  e82ed81800                        call   0x6f5510
0x567ce2  8b37                              mov    esi,DWORD PTR [edi]
0x567ce4  83c404                            add    esp,0x4
0x567ce7  6a00                              push   0x0
0x567ce9  68009c5600                        push   0x569c00
0x567cee  e8bdd81800                        call   0x6f55b0
0x567cf3  8b0f                              mov    ecx,DWORD PTR [edi]
0x567cf5  51                                push   ecx
0x567cf6  b8fdffffff                        mov    eax,0xfffffffd
0x567cfb  e8f0da1800                        call   0x6f57f0
0x567d00  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x567d06  8b02                              mov    eax,DWORD PTR [edx]
0x567d08  83c40c                            add    esp,0xc
0x567d0b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x567d0f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567d12  5f                                pop    edi
0x567d13  5e                                pop    esi
0x567d14  5b                                pop    ebx
0x567d15  5d                                pop    ebp
0x567d16  c20400                            ret    0x4

; B12_call Initializer direct call
; VA 0x560730..0x560735 raw 0x15fb30 length 5 SHA256 24179db30310579d0f21501b0515d0a9ca400077cdb1b1f511deaece0153ac29
0x560730  e84b750000                        call   0x567c80

; B12_closure Lua C closure for Q.PlayTalkSound
; VA 0x569c00..0x569c5c raw 0x169000 length 92 SHA256 3473a73892226e8d4d1755c1b360ca6c73c0178558e41069d452bd54f4440641
0x569c00  55                                push   ebp
0x569c01  8bec                              mov    ebp,esp
0x569c03  6aff                              push   0xffffffff
0x569c05  68c8839300                        push   0x9383c8
0x569c0a  64a100000000                      mov    eax,fs:0x0
0x569c10  50                                push   eax
0x569c11  83ec0c                            sub    esp,0xc
0x569c14  a1201fd600                        mov    eax,ds:0xd61f20
0x569c19  33c5                              xor    eax,ebp
0x569c1b  50                                push   eax
0x569c1c  8d45f4                            lea    eax,[ebp-0xc]
0x569c1f  64a300000000                      mov    fs:0x0,eax
0x569c25  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569c28  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x569c2b  33c0                              xor    eax,eax
0x569c2d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569c30  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569c33  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569c36  8b0d3828fe00                      mov    ecx,DWORD PTR ds:0xfe2838
0x569c3c  51                                push   ecx
0x569c3d  8d45e8                            lea    eax,[ebp-0x18]
0x569c40  e8bb060000                        call   0x56a300
0x569c45  83c404                            add    esp,0x4
0x569c48  b801000000                        mov    eax,0x1
0x569c4d  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x569c50  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569c57  59                                pop    ecx
0x569c58  8be5                              mov    esp,ebp
0x569c5a  5d                                pop    ebp
0x569c5b  c3                                ret

; B12_name Public binding ASCII name
; VA 0xd6a4f4..0xd6a502 raw 0x967cf4 length 14 SHA256 1941952764ad902efb974f447584f2b8e342d1d546ebc3754459b907038d3e3e
; bytes 506c617954616c6b536f756e6400

; B13_reg Q.FadeOut native/closure registrar
; VA 0x567d20..0x567db9 raw 0x167120 length 153 SHA256 f9850217349920c844057f655aa000fd3c34c3627fd1d545da67e14b2315e6aa
0x567d20  55                                push   ebp
0x567d21  8bec                              mov    ebp,esp
0x567d23  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567d26  53                                push   ebx
0x567d27  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x567d2d  56                                push   esi
0x567d2e  8b33                              mov    esi,DWORD PTR [ebx]
0x567d30  57                                push   edi
0x567d31  8b38                              mov    edi,DWORD PTR [eax]
0x567d33  b8eed8ffff                        mov    eax,0xffffd8ee
0x567d38  c7053c28fe00304f5600              mov    DWORD PTR ds:0xfe283c,0x564f30
0x567d42  e839d91800                        call   0x6f5680
0x567d47  8b03                              mov    eax,DWORD PTR [ebx]
0x567d49  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x567d4c  83e810                            sub    eax,0x10
0x567d4f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x567d54  7406                              je     0x567d5c
0x567d56  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x567d5a  7414                              je     0x567d70
0x567d5c  57                                push   edi
0x567d5d  68c426c400                        push   0xc426c4
0x567d62  e856b33200                        call   0x8930bd
0x567d67  8b1b                              mov    ebx,DWORD PTR [ebx]
0x567d69  83c408                            add    esp,0x8
0x567d6c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x567d70  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x567d76  8b37                              mov    esi,DWORD PTR [edi]
0x567d78  6804a5d600                        push   0xd6a504
0x567d7d  e88ed71800                        call   0x6f5510
0x567d82  8b37                              mov    esi,DWORD PTR [edi]
0x567d84  83c404                            add    esp,0x4
0x567d87  6a00                              push   0x0
0x567d89  68609c5600                        push   0x569c60
0x567d8e  e81dd81800                        call   0x6f55b0
0x567d93  8b0f                              mov    ecx,DWORD PTR [edi]
0x567d95  51                                push   ecx
0x567d96  b8fdffffff                        mov    eax,0xfffffffd
0x567d9b  e850da1800                        call   0x6f57f0
0x567da0  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x567da6  8b02                              mov    eax,DWORD PTR [edx]
0x567da8  83c40c                            add    esp,0xc
0x567dab  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x567daf  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567db2  5f                                pop    edi
0x567db3  5e                                pop    esi
0x567db4  5b                                pop    ebx
0x567db5  5d                                pop    ebp
0x567db6  c20400                            ret    0x4

; B13_call Initializer direct call
; VA 0x560736..0x56073b raw 0x15fb36 length 5 SHA256 07959d56b41f278eaac2a6f23bb570d481e258afc13f8ed77ea22e609a86f5de
0x560736  e8e5750000                        call   0x567d20

; B13_closure Lua C closure for Q.FadeOut
; VA 0x569c60..0x569cbc raw 0x169060 length 92 SHA256 0f7a6a44fe835d94a672245d3f820de97a01f3ac1aeab1ae06439278bef1faa2
0x569c60  55                                push   ebp
0x569c61  8bec                              mov    ebp,esp
0x569c63  6aff                              push   0xffffffff
0x569c65  68c8839300                        push   0x9383c8
0x569c6a  64a100000000                      mov    eax,fs:0x0
0x569c70  50                                push   eax
0x569c71  83ec0c                            sub    esp,0xc
0x569c74  a1201fd600                        mov    eax,ds:0xd61f20
0x569c79  33c5                              xor    eax,ebp
0x569c7b  50                                push   eax
0x569c7c  8d45f4                            lea    eax,[ebp-0xc]
0x569c7f  64a300000000                      mov    fs:0x0,eax
0x569c85  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569c88  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x569c8b  33c0                              xor    eax,eax
0x569c8d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569c90  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569c93  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569c96  8b0d3c28fe00                      mov    ecx,DWORD PTR ds:0xfe283c
0x569c9c  51                                push   ecx
0x569c9d  8d45e8                            lea    eax,[ebp-0x18]
0x569ca0  e88b070000                        call   0x56a430
0x569ca5  83c404                            add    esp,0x4
0x569ca8  b801000000                        mov    eax,0x1
0x569cad  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x569cb0  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569cb7  59                                pop    ecx
0x569cb8  8be5                              mov    esp,ebp
0x569cba  5d                                pop    ebp
0x569cbb  c3                                ret

; B13_name Public binding ASCII name
; VA 0xd6a504..0xd6a50c raw 0x967d04 length 8 SHA256 745bbe7e64851920334859d0f88144088e1e624622286d5b8a4046351318416a
; bytes 466164654f757400

; B14_reg Q.FadeIn native/closure registrar
; VA 0x567dc0..0x567e59 raw 0x1671c0 length 153 SHA256 2a2595e45bba898d111b49d28be2dd8b3645d77216468a2d048d0392df1169a9
0x567dc0  55                                push   ebp
0x567dc1  8bec                              mov    ebp,esp
0x567dc3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567dc6  53                                push   ebx
0x567dc7  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x567dcd  56                                push   esi
0x567dce  8b33                              mov    esi,DWORD PTR [ebx]
0x567dd0  57                                push   edi
0x567dd1  8b38                              mov    edi,DWORD PTR [eax]
0x567dd3  b8eed8ffff                        mov    eax,0xffffd8ee
0x567dd8  c7054028fe00b04f5600              mov    DWORD PTR ds:0xfe2840,0x564fb0
0x567de2  e899d81800                        call   0x6f5680
0x567de7  8b03                              mov    eax,DWORD PTR [ebx]
0x567de9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x567dec  83e810                            sub    eax,0x10
0x567def  3dc8bfc000                        cmp    eax,0xc0bfc8
0x567df4  7406                              je     0x567dfc
0x567df6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x567dfa  7414                              je     0x567e10
0x567dfc  57                                push   edi
0x567dfd  68c426c400                        push   0xc426c4
0x567e02  e8b6b23200                        call   0x8930bd
0x567e07  8b1b                              mov    ebx,DWORD PTR [ebx]
0x567e09  83c408                            add    esp,0x8
0x567e0c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x567e10  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x567e16  8b37                              mov    esi,DWORD PTR [edi]
0x567e18  680ca5d600                        push   0xd6a50c
0x567e1d  e8eed61800                        call   0x6f5510
0x567e22  8b37                              mov    esi,DWORD PTR [edi]
0x567e24  83c404                            add    esp,0x4
0x567e27  6a00                              push   0x0
0x567e29  68c09c5600                        push   0x569cc0
0x567e2e  e87dd71800                        call   0x6f55b0
0x567e33  8b0f                              mov    ecx,DWORD PTR [edi]
0x567e35  51                                push   ecx
0x567e36  b8fdffffff                        mov    eax,0xfffffffd
0x567e3b  e8b0d91800                        call   0x6f57f0
0x567e40  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x567e46  8b02                              mov    eax,DWORD PTR [edx]
0x567e48  83c40c                            add    esp,0xc
0x567e4b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x567e4f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567e52  5f                                pop    edi
0x567e53  5e                                pop    esi
0x567e54  5b                                pop    ebx
0x567e55  5d                                pop    ebp
0x567e56  c20400                            ret    0x4

; B14_call Initializer direct call
; VA 0x56073c..0x560741 raw 0x15fb3c length 5 SHA256 3449a04c2e9c584372ae14c37f3f8effd8d600f14ea8871ead660538096f45e8
0x56073c  e87f760000                        call   0x567dc0

; B14_closure Lua C closure for Q.FadeIn
; VA 0x569cc0..0x569d1c raw 0x1690c0 length 92 SHA256 6ce67b08c821601e00a3647a4eb01fe33b0df8725dd92a33f6076dc1bcb4bca9
0x569cc0  55                                push   ebp
0x569cc1  8bec                              mov    ebp,esp
0x569cc3  6aff                              push   0xffffffff
0x569cc5  68c8839300                        push   0x9383c8
0x569cca  64a100000000                      mov    eax,fs:0x0
0x569cd0  50                                push   eax
0x569cd1  83ec0c                            sub    esp,0xc
0x569cd4  a1201fd600                        mov    eax,ds:0xd61f20
0x569cd9  33c5                              xor    eax,ebp
0x569cdb  50                                push   eax
0x569cdc  8d45f4                            lea    eax,[ebp-0xc]
0x569cdf  64a300000000                      mov    fs:0x0,eax
0x569ce5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569ce8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x569ceb  33c0                              xor    eax,eax
0x569ced  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569cf0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569cf3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569cf6  8b0d4028fe00                      mov    ecx,DWORD PTR ds:0xfe2840
0x569cfc  51                                push   ecx
0x569cfd  8d45e8                            lea    eax,[ebp-0x18]
0x569d00  e82b070000                        call   0x56a430
0x569d05  83c404                            add    esp,0x4
0x569d08  b801000000                        mov    eax,0x1
0x569d0d  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x569d10  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569d17  59                                pop    ecx
0x569d18  8be5                              mov    esp,ebp
0x569d1a  5d                                pop    ebp
0x569d1b  c3                                ret

; B14_name Public binding ASCII name
; VA 0xd6a50c..0xd6a513 raw 0x967d0c length 7 SHA256 7ac67b14115ed4a3da62f3c2473ad9315852e27dcc6d845dab48917b0096e485
; bytes 46616465496e00

; B15_reg Q.FadeColor native/closure registrar
; VA 0x567e60..0x567ef9 raw 0x167260 length 153 SHA256 192cc9315f628492c2f2576243e8b0513f3377c3d15ce81cb3935bf22ffe8410
0x567e60  55                                push   ebp
0x567e61  8bec                              mov    ebp,esp
0x567e63  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567e66  53                                push   ebx
0x567e67  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x567e6d  56                                push   esi
0x567e6e  8b33                              mov    esi,DWORD PTR [ebx]
0x567e70  57                                push   edi
0x567e71  8b38                              mov    edi,DWORD PTR [eax]
0x567e73  b8eed8ffff                        mov    eax,0xffffd8ee
0x567e78  c7054428fe0040505600              mov    DWORD PTR ds:0xfe2844,0x565040
0x567e82  e8f9d71800                        call   0x6f5680
0x567e87  8b03                              mov    eax,DWORD PTR [ebx]
0x567e89  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x567e8c  83e810                            sub    eax,0x10
0x567e8f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x567e94  7406                              je     0x567e9c
0x567e96  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x567e9a  7414                              je     0x567eb0
0x567e9c  57                                push   edi
0x567e9d  68c426c400                        push   0xc426c4
0x567ea2  e816b23200                        call   0x8930bd
0x567ea7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x567ea9  83c408                            add    esp,0x8
0x567eac  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x567eb0  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x567eb6  8b37                              mov    esi,DWORD PTR [edi]
0x567eb8  6814a5d600                        push   0xd6a514
0x567ebd  e84ed61800                        call   0x6f5510
0x567ec2  8b37                              mov    esi,DWORD PTR [edi]
0x567ec4  83c404                            add    esp,0x4
0x567ec7  6a00                              push   0x0
0x567ec9  68209d5600                        push   0x569d20
0x567ece  e8ddd61800                        call   0x6f55b0
0x567ed3  8b0f                              mov    ecx,DWORD PTR [edi]
0x567ed5  51                                push   ecx
0x567ed6  b8fdffffff                        mov    eax,0xfffffffd
0x567edb  e810d91800                        call   0x6f57f0
0x567ee0  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x567ee6  8b02                              mov    eax,DWORD PTR [edx]
0x567ee8  83c40c                            add    esp,0xc
0x567eeb  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x567eef  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x567ef2  5f                                pop    edi
0x567ef3  5e                                pop    esi
0x567ef4  5b                                pop    ebx
0x567ef5  5d                                pop    ebp
0x567ef6  c20400                            ret    0x4

; B15_call Initializer direct call
; VA 0x560742..0x560747 raw 0x15fb42 length 5 SHA256 aa9a2fb0776a62e85273e7e8a89bc8f53a2b2ab2aa41f1cfee25b4dceca19c95
0x560742  e819770000                        call   0x567e60

; B15_closure Lua C closure for Q.FadeColor
; VA 0x569d20..0x569d87 raw 0x169120 length 103 SHA256 6504f76cc74fe83904cf873f6bd24587eddb872f88e4bb1e6eddd8ddb334aa42
0x569d20  55                                push   ebp
0x569d21  8bec                              mov    ebp,esp
0x569d23  6aff                              push   0xffffffff
0x569d25  6838869300                        push   0x938638
0x569d2a  64a100000000                      mov    eax,fs:0x0
0x569d30  50                                push   eax
0x569d31  83ec0c                            sub    esp,0xc
0x569d34  56                                push   esi
0x569d35  57                                push   edi
0x569d36  a1201fd600                        mov    eax,ds:0xd61f20
0x569d3b  33c5                              xor    eax,ebp
0x569d3d  50                                push   eax
0x569d3e  8d45f4                            lea    eax,[ebp-0xc]
0x569d41  64a300000000                      mov    fs:0x0,eax
0x569d47  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x569d4a  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x569d4d  33c0                              xor    eax,eax
0x569d4f  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569d52  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569d55  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569d58  8b354428fe00                      mov    esi,DWORD PTR ds:0xfe2844
0x569d5e  8b3d7827fe00                      mov    edi,DWORD PTR ds:0xfe2778
0x569d64  8d45e8                            lea    eax,[ebp-0x18]
0x569d67  e8c4180000                        call   0x56b630
0x569d6c  50                                push   eax
0x569d6d  8bcf                              mov    ecx,edi
0x569d6f  ffd6                              call   esi
0x569d71  b801000000                        mov    eax,0x1
0x569d76  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x569d79  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569d80  59                                pop    ecx
0x569d81  5f                                pop    edi
0x569d82  5e                                pop    esi
0x569d83  8be5                              mov    esp,ebp
0x569d85  5d                                pop    ebp
0x569d86  c3                                ret

; B15_name Public binding ASCII name
; VA 0xd6a514..0xd6a51e raw 0x967d14 length 10 SHA256 6ae757774e3174015a8c0e242abb9dc5bfe0a307ec88a7fea9d85707280074d9
; bytes 46616465436f6c6f7200

; B16_reg Q.SetFinalMusic native/closure registrar
; VA 0x568360..0x5683f9 raw 0x167760 length 153 SHA256 1e33199d37ce895d61798b7e7d41af6d8b40102d94dff1339265a65e1657a255
0x568360  55                                push   ebp
0x568361  8bec                              mov    ebp,esp
0x568363  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x568366  53                                push   ebx
0x568367  8b1d7427fe00                      mov    ebx,DWORD PTR ds:0xfe2774
0x56836d  56                                push   esi
0x56836e  8b33                              mov    esi,DWORD PTR [ebx]
0x568370  57                                push   edi
0x568371  8b38                              mov    edi,DWORD PTR [eax]
0x568373  b8eed8ffff                        mov    eax,0xffffd8ee
0x568378  c7056428fe0060555600              mov    DWORD PTR ds:0xfe2864,0x565560
0x568382  e8f9d21800                        call   0x6f5680
0x568387  8b03                              mov    eax,DWORD PTR [ebx]
0x568389  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x56838c  83e810                            sub    eax,0x10
0x56838f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x568394  7406                              je     0x56839c
0x568396  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x56839a  7414                              je     0x5683b0
0x56839c  57                                push   edi
0x56839d  68c426c400                        push   0xc426c4
0x5683a2  e816ad3200                        call   0x8930bd
0x5683a7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x5683a9  83c408                            add    esp,0x8
0x5683ac  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x5683b0  8b3d7427fe00                      mov    edi,DWORD PTR ds:0xfe2774
0x5683b6  8b37                              mov    esi,DWORD PTR [edi]
0x5683b8  6874a5d600                        push   0xd6a574
0x5683bd  e84ed11800                        call   0x6f5510
0x5683c2  8b37                              mov    esi,DWORD PTR [edi]
0x5683c4  83c404                            add    esp,0x4
0x5683c7  6a00                              push   0x0
0x5683c9  6840a05600                        push   0x56a040
0x5683ce  e8ddd11800                        call   0x6f55b0
0x5683d3  8b0f                              mov    ecx,DWORD PTR [edi]
0x5683d5  51                                push   ecx
0x5683d6  b8fdffffff                        mov    eax,0xfffffffd
0x5683db  e810d41800                        call   0x6f57f0
0x5683e0  8b157427fe00                      mov    edx,DWORD PTR ds:0xfe2774
0x5683e6  8b02                              mov    eax,DWORD PTR [edx]
0x5683e8  83c40c                            add    esp,0xc
0x5683eb  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x5683ef  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5683f2  5f                                pop    edi
0x5683f3  5e                                pop    esi
0x5683f4  5b                                pop    ebx
0x5683f5  5d                                pop    ebp
0x5683f6  c20400                            ret    0x4

; B16_call Initializer direct call
; VA 0x560772..0x560777 raw 0x15fb72 length 5 SHA256 b7412ac7148c07fdd896a53cbf46c1d1e80421ff5b530ee5cc3e0f120ac97fe7
0x560772  e8e97b0000                        call   0x568360

; B16_closure Lua C closure for Q.SetFinalMusic
; VA 0x56a040..0x56a09c raw 0x169440 length 92 SHA256 c9d0bcda76c3b6720d16c06bfb46331e5e84dd82bbcd99226600405054035c07
0x56a040  55                                push   ebp
0x56a041  8bec                              mov    ebp,esp
0x56a043  6aff                              push   0xffffffff
0x56a045  68c8839300                        push   0x9383c8
0x56a04a  64a100000000                      mov    eax,fs:0x0
0x56a050  50                                push   eax
0x56a051  83ec0c                            sub    esp,0xc
0x56a054  a1201fd600                        mov    eax,ds:0xd61f20
0x56a059  33c5                              xor    eax,ebp
0x56a05b  50                                push   eax
0x56a05c  8d45f4                            lea    eax,[ebp-0xc]
0x56a05f  64a300000000                      mov    fs:0x0,eax
0x56a065  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x56a068  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x56a06b  33c0                              xor    eax,eax
0x56a06d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x56a070  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x56a073  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x56a076  8b0d6428fe00                      mov    ecx,DWORD PTR ds:0xfe2864
0x56a07c  51                                push   ecx
0x56a07d  8d45e8                            lea    eax,[ebp-0x18]
0x56a080  e87b020000                        call   0x56a300
0x56a085  83c404                            add    esp,0x4
0x56a088  b801000000                        mov    eax,0x1
0x56a08d  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x56a090  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x56a097  59                                pop    ecx
0x56a098  8be5                              mov    esp,ebp
0x56a09a  5d                                pop    ebp
0x56a09b  c3                                ret

; B16_name Public binding ASCII name
; VA 0xd6a574..0xd6a582 raw 0x967d74 length 14 SHA256 41603de78bedbefd6ead3accd0043f0d5c574b56a6f32979efeec41efb69d799
; bytes 53657446696e616c4d7573696300

; B17_reg CameraWorks.Load native/closure registrar
; VA 0x54eb00..0x54eb99 raw 0x14df00 length 153 SHA256 43c4fd8daea6a3a80b5292fae7cfba29818ea21f40f0d88365ab5d83c5dc5cd4
0x54eb00  55                                push   ebp
0x54eb01  8bec                              mov    ebp,esp
0x54eb03  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54eb06  53                                push   ebx
0x54eb07  8b1d241efe00                      mov    ebx,DWORD PTR ds:0xfe1e24
0x54eb0d  56                                push   esi
0x54eb0e  8b33                              mov    esi,DWORD PTR [ebx]
0x54eb10  57                                push   edi
0x54eb11  8b38                              mov    edi,DWORD PTR [eax]
0x54eb13  b8eed8ffff                        mov    eax,0xffffd8ee
0x54eb18  c7052c1efe0070e95400              mov    DWORD PTR ds:0xfe1e2c,0x54e970
0x54eb22  e8596b1a00                        call   0x6f5680
0x54eb27  8b03                              mov    eax,DWORD PTR [ebx]
0x54eb29  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54eb2c  83e810                            sub    eax,0x10
0x54eb2f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x54eb34  7406                              je     0x54eb3c
0x54eb36  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x54eb3a  7414                              je     0x54eb50
0x54eb3c  57                                push   edi
0x54eb3d  68c426c400                        push   0xc426c4
0x54eb42  e876453400                        call   0x8930bd
0x54eb47  8b1b                              mov    ebx,DWORD PTR [ebx]
0x54eb49  83c408                            add    esp,0x8
0x54eb4c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x54eb50  8b3d241efe00                      mov    edi,DWORD PTR ds:0xfe1e24
0x54eb56  8b37                              mov    esi,DWORD PTR [edi]
0x54eb58  68e0a5d600                        push   0xd6a5e0
0x54eb5d  e8ae691a00                        call   0x6f5510
0x54eb62  8b37                              mov    esi,DWORD PTR [edi]
0x54eb64  83c404                            add    esp,0x4
0x54eb67  6a00                              push   0x0
0x54eb69  6840ee5400                        push   0x54ee40
0x54eb6e  e83d6a1a00                        call   0x6f55b0
0x54eb73  8b0f                              mov    ecx,DWORD PTR [edi]
0x54eb75  51                                push   ecx
0x54eb76  b8fdffffff                        mov    eax,0xfffffffd
0x54eb7b  e8706c1a00                        call   0x6f57f0
0x54eb80  8b15241efe00                      mov    edx,DWORD PTR ds:0xfe1e24
0x54eb86  8b02                              mov    eax,DWORD PTR [edx]
0x54eb88  83c40c                            add    esp,0xc
0x54eb8b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x54eb8f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54eb92  5f                                pop    edi
0x54eb93  5e                                pop    esi
0x54eb94  5b                                pop    ebx
0x54eb95  5d                                pop    ebp
0x54eb96  c20400                            ret    0x4

; B17_call Initializer direct call
; VA 0x54e8d9..0x54e8de raw 0x14dcd9 length 5 SHA256 242b92a5acb04024a2a1b7c12acbb5ac13aa7e5cfb9e4c23b16cca63394756a4
0x54e8d9  e822020000                        call   0x54eb00

; B17_closure Lua C closure for CameraWorks.Load
; VA 0x54ee40..0x54ee92 raw 0x14e240 length 82 SHA256 c85fef8428f51f70f9e76ac611bf4120cf931cb324989d64ae9b83f15d25e679
0x54ee40  55                                push   ebp
0x54ee41  8bec                              mov    ebp,esp
0x54ee43  6aff                              push   0xffffffff
0x54ee45  68c8839300                        push   0x9383c8
0x54ee4a  64a100000000                      mov    eax,fs:0x0
0x54ee50  50                                push   eax
0x54ee51  83ec0c                            sub    esp,0xc
0x54ee54  a1201fd600                        mov    eax,ds:0xd61f20
0x54ee59  33c5                              xor    eax,ebp
0x54ee5b  50                                push   eax
0x54ee5c  8d45f4                            lea    eax,[ebp-0xc]
0x54ee5f  64a300000000                      mov    fs:0x0,eax
0x54ee65  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ee68  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x54ee6b  33c0                              xor    eax,eax
0x54ee6d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x54ee70  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x54ee73  8d4de8                            lea    ecx,[ebp-0x18]
0x54ee76  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x54ee79  e8b2010000                        call   0x54f030
0x54ee7e  b801000000                        mov    eax,0x1
0x54ee83  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x54ee86  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x54ee8d  59                                pop    ecx
0x54ee8e  8be5                              mov    esp,ebp
0x54ee90  5d                                pop    ebp
0x54ee91  c3                                ret

; B17_name Public binding ASCII name
; VA 0xd6a5e0..0xd6a5e5 raw 0x967de0 length 5 SHA256 51dfb71c0e171fc6a6b8f40d3c557b95c13d49a1b1ace7d44405b857635327f1
; bytes 4c6f616400

; B18_reg CameraWorks.LoadRel native/closure registrar
; VA 0x54eba0..0x54ec39 raw 0x14dfa0 length 153 SHA256 ff2ccdf555961851001f113d738d3be708eb7d7d9d3cf59adf31aa9ae7796925
0x54eba0  55                                push   ebp
0x54eba1  8bec                              mov    ebp,esp
0x54eba3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54eba6  53                                push   ebx
0x54eba7  8b1d241efe00                      mov    ebx,DWORD PTR ds:0xfe1e24
0x54ebad  56                                push   esi
0x54ebae  8b33                              mov    esi,DWORD PTR [ebx]
0x54ebb0  57                                push   edi
0x54ebb1  8b38                              mov    edi,DWORD PTR [eax]
0x54ebb3  b8eed8ffff                        mov    eax,0xffffd8ee
0x54ebb8  c705301efe0090e95400              mov    DWORD PTR ds:0xfe1e30,0x54e990
0x54ebc2  e8b96a1a00                        call   0x6f5680
0x54ebc7  8b03                              mov    eax,DWORD PTR [ebx]
0x54ebc9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54ebcc  83e810                            sub    eax,0x10
0x54ebcf  3dc8bfc000                        cmp    eax,0xc0bfc8
0x54ebd4  7406                              je     0x54ebdc
0x54ebd6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x54ebda  7414                              je     0x54ebf0
0x54ebdc  57                                push   edi
0x54ebdd  68c426c400                        push   0xc426c4
0x54ebe2  e8d6443400                        call   0x8930bd
0x54ebe7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x54ebe9  83c408                            add    esp,0x8
0x54ebec  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x54ebf0  8b3d241efe00                      mov    edi,DWORD PTR ds:0xfe1e24
0x54ebf6  8b37                              mov    esi,DWORD PTR [edi]
0x54ebf8  68e8a5d600                        push   0xd6a5e8
0x54ebfd  e80e691a00                        call   0x6f5510
0x54ec02  8b37                              mov    esi,DWORD PTR [edi]
0x54ec04  83c404                            add    esp,0x4
0x54ec07  6a00                              push   0x0
0x54ec09  68a0ee5400                        push   0x54eea0
0x54ec0e  e89d691a00                        call   0x6f55b0
0x54ec13  8b0f                              mov    ecx,DWORD PTR [edi]
0x54ec15  51                                push   ecx
0x54ec16  b8fdffffff                        mov    eax,0xfffffffd
0x54ec1b  e8d06b1a00                        call   0x6f57f0
0x54ec20  8b15241efe00                      mov    edx,DWORD PTR ds:0xfe1e24
0x54ec26  8b02                              mov    eax,DWORD PTR [edx]
0x54ec28  83c40c                            add    esp,0xc
0x54ec2b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x54ec2f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ec32  5f                                pop    edi
0x54ec33  5e                                pop    esi
0x54ec34  5b                                pop    ebx
0x54ec35  5d                                pop    ebp
0x54ec36  c20400                            ret    0x4

; B18_call Initializer direct call
; VA 0x54e8df..0x54e8e4 raw 0x14dcdf length 5 SHA256 0ea5a64ab0013122a854452dac34c6baa7c559fbfb765046c54b4350f1533f00
0x54e8df  e8bc020000                        call   0x54eba0

; B18_closure Lua C closure for CameraWorks.LoadRel
; VA 0x54eea0..0x54eef6 raw 0x14e2a0 length 86 SHA256 f9f2f66bc09ab7bafceb5fa1044ba983e71d3b60b9c89077b78a40d90e727d10
0x54eea0  55                                push   ebp
0x54eea1  8bec                              mov    ebp,esp
0x54eea3  6aff                              push   0xffffffff
0x54eea5  68c8839300                        push   0x9383c8
0x54eeaa  64a100000000                      mov    eax,fs:0x0
0x54eeb0  50                                push   eax
0x54eeb1  83ec0c                            sub    esp,0xc
0x54eeb4  a1201fd600                        mov    eax,ds:0xd61f20
0x54eeb9  33c5                              xor    eax,ebp
0x54eebb  50                                push   eax
0x54eebc  8d45f4                            lea    eax,[ebp-0xc]
0x54eebf  64a300000000                      mov    fs:0x0,eax
0x54eec5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54eec8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x54eecb  33c0                              xor    eax,eax
0x54eecd  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x54eed0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x54eed3  8d4de8                            lea    ecx,[ebp-0x18]
0x54eed6  51                                push   ecx
0x54eed7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x54eeda  e8c1010000                        call   0x54f0a0
0x54eedf  83c404                            add    esp,0x4
0x54eee2  b801000000                        mov    eax,0x1
0x54eee7  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x54eeea  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x54eef1  59                                pop    ecx
0x54eef2  8be5                              mov    esp,ebp
0x54eef4  5d                                pop    ebp
0x54eef5  c3                                ret

; B18_name Public binding ASCII name
; VA 0xd6a5e8..0xd6a5f0 raw 0x967de8 length 8 SHA256 d13ccc61af320df294e312bd313e78baf9da1aab21b38fe63c3f8528602bebaa
; bytes 4c6f616452656c00

; B19_reg CameraWorks.Play native/closure registrar
; VA 0x54ec40..0x54ecd9 raw 0x14e040 length 153 SHA256 aafb0cc48924a489dc7914214bd7b11c5347788e46e57104ab4dc993e4785865
0x54ec40  55                                push   ebp
0x54ec41  8bec                              mov    ebp,esp
0x54ec43  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ec46  53                                push   ebx
0x54ec47  8b1d241efe00                      mov    ebx,DWORD PTR ds:0xfe1e24
0x54ec4d  56                                push   esi
0x54ec4e  8b33                              mov    esi,DWORD PTR [ebx]
0x54ec50  57                                push   edi
0x54ec51  8b38                              mov    edi,DWORD PTR [eax]
0x54ec53  b8eed8ffff                        mov    eax,0xffffd8ee
0x54ec58  c705341efe00e0e95400              mov    DWORD PTR ds:0xfe1e34,0x54e9e0
0x54ec62  e8196a1a00                        call   0x6f5680
0x54ec67  8b03                              mov    eax,DWORD PTR [ebx]
0x54ec69  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54ec6c  83e810                            sub    eax,0x10
0x54ec6f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x54ec74  7406                              je     0x54ec7c
0x54ec76  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x54ec7a  7414                              je     0x54ec90
0x54ec7c  57                                push   edi
0x54ec7d  68c426c400                        push   0xc426c4
0x54ec82  e836443400                        call   0x8930bd
0x54ec87  8b1b                              mov    ebx,DWORD PTR [ebx]
0x54ec89  83c408                            add    esp,0x8
0x54ec8c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x54ec90  8b3d241efe00                      mov    edi,DWORD PTR ds:0xfe1e24
0x54ec96  8b37                              mov    esi,DWORD PTR [edi]
0x54ec98  68f0a5d600                        push   0xd6a5f0
0x54ec9d  e86e681a00                        call   0x6f5510
0x54eca2  8b37                              mov    esi,DWORD PTR [edi]
0x54eca4  83c404                            add    esp,0x4
0x54eca7  6a00                              push   0x0
0x54eca9  6800ef5400                        push   0x54ef00
0x54ecae  e8fd681a00                        call   0x6f55b0
0x54ecb3  8b0f                              mov    ecx,DWORD PTR [edi]
0x54ecb5  51                                push   ecx
0x54ecb6  b8fdffffff                        mov    eax,0xfffffffd
0x54ecbb  e8306b1a00                        call   0x6f57f0
0x54ecc0  8b15241efe00                      mov    edx,DWORD PTR ds:0xfe1e24
0x54ecc6  8b02                              mov    eax,DWORD PTR [edx]
0x54ecc8  83c40c                            add    esp,0xc
0x54eccb  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x54eccf  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ecd2  5f                                pop    edi
0x54ecd3  5e                                pop    esi
0x54ecd4  5b                                pop    ebx
0x54ecd5  5d                                pop    ebp
0x54ecd6  c20400                            ret    0x4

; B19_call Initializer direct call
; VA 0x54e8e5..0x54e8ea raw 0x14dce5 length 5 SHA256 308a6c45be46375504f690b749edab7462ea4030043cab217d5ecea83a7faf6e
0x54e8e5  e856030000                        call   0x54ec40

; B19_closure Lua C closure for CameraWorks.Play
; VA 0x54ef00..0x54ef56 raw 0x14e300 length 86 SHA256 bbb3945151c5a8f3990780af41292b82d3bf02d38d34bacfd613af421bba409e
0x54ef00  55                                push   ebp
0x54ef01  8bec                              mov    ebp,esp
0x54ef03  6aff                              push   0xffffffff
0x54ef05  68c8839300                        push   0x9383c8
0x54ef0a  64a100000000                      mov    eax,fs:0x0
0x54ef10  50                                push   eax
0x54ef11  83ec0c                            sub    esp,0xc
0x54ef14  a1201fd600                        mov    eax,ds:0xd61f20
0x54ef19  33c5                              xor    eax,ebp
0x54ef1b  50                                push   eax
0x54ef1c  8d45f4                            lea    eax,[ebp-0xc]
0x54ef1f  64a300000000                      mov    fs:0x0,eax
0x54ef25  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ef28  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x54ef2b  33c0                              xor    eax,eax
0x54ef2d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x54ef30  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x54ef33  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x54ef36  8b0d281efe00                      mov    ecx,DWORD PTR ds:0xfe1e28
0x54ef3c  ff15341efe00                      call   DWORD PTR ds:0xfe1e34
0x54ef42  b801000000                        mov    eax,0x1
0x54ef47  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x54ef4a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x54ef51  59                                pop    ecx
0x54ef52  8be5                              mov    esp,ebp
0x54ef54  5d                                pop    ebp
0x54ef55  c3                                ret

; B19_name Public binding ASCII name
; VA 0xd6a5f0..0xd6a5f5 raw 0x967df0 length 5 SHA256 4d7cd0c679fc4e93061c087b44047f1b1e9a4914fef80bcaa3bfbefd0454eb0c
; bytes 506c617900

; B20_reg CameraWorks.Stop native/closure registrar
; VA 0x54ece0..0x54ed79 raw 0x14e0e0 length 153 SHA256 3c99017efc0ead3c43bf3f4d5f872ac87867399c11cfd4f72c1691c69950918c
0x54ece0  55                                push   ebp
0x54ece1  8bec                              mov    ebp,esp
0x54ece3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ece6  53                                push   ebx
0x54ece7  8b1d241efe00                      mov    ebx,DWORD PTR ds:0xfe1e24
0x54eced  56                                push   esi
0x54ecee  8b33                              mov    esi,DWORD PTR [ebx]
0x54ecf0  57                                push   edi
0x54ecf1  8b38                              mov    edi,DWORD PTR [eax]
0x54ecf3  b8eed8ffff                        mov    eax,0xffffd8ee
0x54ecf8  c705381efe00f0e95400              mov    DWORD PTR ds:0xfe1e38,0x54e9f0
0x54ed02  e879691a00                        call   0x6f5680
0x54ed07  8b03                              mov    eax,DWORD PTR [ebx]
0x54ed09  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54ed0c  83e810                            sub    eax,0x10
0x54ed0f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x54ed14  7406                              je     0x54ed1c
0x54ed16  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x54ed1a  7414                              je     0x54ed30
0x54ed1c  57                                push   edi
0x54ed1d  68c426c400                        push   0xc426c4
0x54ed22  e896433400                        call   0x8930bd
0x54ed27  8b1b                              mov    ebx,DWORD PTR [ebx]
0x54ed29  83c408                            add    esp,0x8
0x54ed2c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x54ed30  8b3d241efe00                      mov    edi,DWORD PTR ds:0xfe1e24
0x54ed36  8b37                              mov    esi,DWORD PTR [edi]
0x54ed38  68f8a5d600                        push   0xd6a5f8
0x54ed3d  e8ce671a00                        call   0x6f5510
0x54ed42  8b37                              mov    esi,DWORD PTR [edi]
0x54ed44  83c404                            add    esp,0x4
0x54ed47  6a00                              push   0x0
0x54ed49  6860ef5400                        push   0x54ef60
0x54ed4e  e85d681a00                        call   0x6f55b0
0x54ed53  8b0f                              mov    ecx,DWORD PTR [edi]
0x54ed55  51                                push   ecx
0x54ed56  b8fdffffff                        mov    eax,0xfffffffd
0x54ed5b  e8906a1a00                        call   0x6f57f0
0x54ed60  8b15241efe00                      mov    edx,DWORD PTR ds:0xfe1e24
0x54ed66  8b02                              mov    eax,DWORD PTR [edx]
0x54ed68  83c40c                            add    esp,0xc
0x54ed6b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x54ed6f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ed72  5f                                pop    edi
0x54ed73  5e                                pop    esi
0x54ed74  5b                                pop    ebx
0x54ed75  5d                                pop    ebp
0x54ed76  c20400                            ret    0x4

; B20_call Initializer direct call
; VA 0x54e8eb..0x54e8f0 raw 0x14dceb length 5 SHA256 f78af16058173851ad1690f4567ce3abce646c57ce4fe91e7eb0f29f86586a24
0x54e8eb  e8f0030000                        call   0x54ece0

; B20_closure Lua C closure for CameraWorks.Stop
; VA 0x54ef60..0x54efb6 raw 0x14e360 length 86 SHA256 3fdb47122df38e010f7baf6004e2461a37a0d3bf5de56b761244f3e1e08afa48
0x54ef60  55                                push   ebp
0x54ef61  8bec                              mov    ebp,esp
0x54ef63  6aff                              push   0xffffffff
0x54ef65  68c8839300                        push   0x9383c8
0x54ef6a  64a100000000                      mov    eax,fs:0x0
0x54ef70  50                                push   eax
0x54ef71  83ec0c                            sub    esp,0xc
0x54ef74  a1201fd600                        mov    eax,ds:0xd61f20
0x54ef79  33c5                              xor    eax,ebp
0x54ef7b  50                                push   eax
0x54ef7c  8d45f4                            lea    eax,[ebp-0xc]
0x54ef7f  64a300000000                      mov    fs:0x0,eax
0x54ef85  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ef88  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x54ef8b  33c0                              xor    eax,eax
0x54ef8d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x54ef90  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x54ef93  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x54ef96  8b0d281efe00                      mov    ecx,DWORD PTR ds:0xfe1e28
0x54ef9c  ff15381efe00                      call   DWORD PTR ds:0xfe1e38
0x54efa2  b801000000                        mov    eax,0x1
0x54efa7  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x54efaa  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x54efb1  59                                pop    ecx
0x54efb2  8be5                              mov    esp,ebp
0x54efb4  5d                                pop    ebp
0x54efb5  c3                                ret

; B20_name Public binding ASCII name
; VA 0xd6a5f8..0xd6a5fd raw 0x967df8 length 5 SHA256 ddc2dcaa4e18b15eb75953540bd79f768358abee4654fcca59b2b744d0b67509
; bytes 53746f7000

; B21_reg CameraWorks.IsEnded native/closure registrar
; VA 0x54ed80..0x54ee32 raw 0x14e180 length 178 SHA256 ed70b8370d9f8fec5d27d3ad08f020a24042e9d6a57005cb21a8997f871268ea
0x54ed80  55                                push   ebp
0x54ed81  8bec                              mov    ebp,esp
0x54ed83  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ed86  53                                push   ebx
0x54ed87  8b1d241efe00                      mov    ebx,DWORD PTR ds:0xfe1e24
0x54ed8d  56                                push   esi
0x54ed8e  8b33                              mov    esi,DWORD PTR [ebx]
0x54ed90  57                                push   edi
0x54ed91  8b38                              mov    edi,DWORD PTR [eax]
0x54ed93  b8eed8ffff                        mov    eax,0xffffd8ee
0x54ed98  c7053c1efe0000ea5400              mov    DWORD PTR ds:0xfe1e3c,0x54ea00
0x54eda2  e8d9681a00                        call   0x6f5680
0x54eda7  8b03                              mov    eax,DWORD PTR [ebx]
0x54eda9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54edac  83e810                            sub    eax,0x10
0x54edaf  3dc8bfc000                        cmp    eax,0xc0bfc8
0x54edb4  7406                              je     0x54edbc
0x54edb6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x54edba  7414                              je     0x54edd0
0x54edbc  57                                push   edi
0x54edbd  68c426c400                        push   0xc426c4
0x54edc2  e8f6423400                        call   0x8930bd
0x54edc7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x54edc9  83c408                            add    esp,0x8
0x54edcc  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x54edd0  8b3d241efe00                      mov    edi,DWORD PTR ds:0xfe1e24
0x54edd6  8b37                              mov    esi,DWORD PTR [edi]
0x54edd8  6800a6d600                        push   0xd6a600
0x54eddd  e82e671a00                        call   0x6f5510
0x54ede2  8b37                              mov    esi,DWORD PTR [edi]
0x54ede4  83c404                            add    esp,0x4
0x54ede7  6a00                              push   0x0
0x54ede9  68c0ef5400                        push   0x54efc0
0x54edee  e8bd671a00                        call   0x6f55b0
0x54edf3  8b0f                              mov    ecx,DWORD PTR [edi]
0x54edf5  51                                push   ecx
0x54edf6  b8fdffffff                        mov    eax,0xfffffffd
0x54edfb  e8f0691a00                        call   0x6f57f0
0x54ee00  8b15241efe00                      mov    edx,DWORD PTR ds:0xfe1e24
0x54ee06  8b02                              mov    eax,DWORD PTR [edx]
0x54ee08  83c40c                            add    esp,0xc
0x54ee0b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x54ee0f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54ee12  5f                                pop    edi
0x54ee13  5e                                pop    esi
0x54ee14  5b                                pop    ebx
0x54ee15  5d                                pop    ebp
0x54ee16  c20400                            ret    0x4
0x54ee19  cc                                int3
0x54ee1a  cc                                int3
0x54ee1b  cc                                int3
0x54ee1c  cc                                int3
0x54ee1d  cc                                int3
0x54ee1e  cc                                int3
0x54ee1f  cc                                int3
0x54ee20  a1241efe00                        mov    eax,ds:0xfe1e24
0x54ee25  e8863df5ff                        call   0x4a2bb0
0x54ee2a  a3281efe00                        mov    ds:0xfe1e28,eax
0x54ee2f  33c0                              xor    eax,eax
0x54ee31  c3                                ret

; B21_call Initializer direct call
; VA 0x54e8f1..0x54e8f6 raw 0x14dcf1 length 5 SHA256 c64da0e30e77fa0665bfce9013ab0c3f38f9e425b247bf71a58cfa8718f1ff88
0x54e8f1  e88a040000                        call   0x54ed80

; B21_closure Lua C closure for CameraWorks.IsEnded
; VA 0x54efc0..0x54f02e raw 0x14e3c0 length 110 SHA256 91142e6bfc0f2818f3afea0e54143eb3bede2f57939f3649f4ad7cd6fcdae9c8
0x54efc0  55                                push   ebp
0x54efc1  8bec                              mov    ebp,esp
0x54efc3  6aff                              push   0xffffffff
0x54efc5  68d8879300                        push   0x9387d8
0x54efca  64a100000000                      mov    eax,fs:0x0
0x54efd0  50                                push   eax
0x54efd1  83ec0c                            sub    esp,0xc
0x54efd4  56                                push   esi
0x54efd5  a1201fd600                        mov    eax,ds:0xd61f20
0x54efda  33c5                              xor    eax,ebp
0x54efdc  50                                push   eax
0x54efdd  8d45f4                            lea    eax,[ebp-0xc]
0x54efe0  64a300000000                      mov    fs:0x0,eax
0x54efe6  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x54efe9  33c0                              xor    eax,eax
0x54efeb  8975e8                            mov    DWORD PTR [ebp-0x18],esi
0x54efee  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x54eff1  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x54eff4  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x54eff7  8b0d281efe00                      mov    ecx,DWORD PTR ds:0xfe1e28
0x54effd  ff153c1efe00                      call   DWORD PTR ds:0xfe1e3c
0x54f003  894508                            mov    DWORD PTR [ebp+0x8],eax
0x54f006  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x54f009  db4508                            fild   DWORD PTR [ebp+0x8]
0x54f00c  c7400803000000                    mov    DWORD PTR [eax+0x8],0x3
0x54f013  dd18                              fstp   QWORD PTR [eax]
0x54f015  83460810                          add    DWORD PTR [esi+0x8],0x10
0x54f019  b801000000                        mov    eax,0x1
0x54f01e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x54f021  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x54f028  59                                pop    ecx
0x54f029  5e                                pop    esi
0x54f02a  8be5                              mov    esp,ebp
0x54f02c  5d                                pop    ebp
0x54f02d  c3                                ret

; B21_name Public binding ASCII name
; VA 0xd6a600..0xd6a608 raw 0x967e00 length 8 SHA256 abf68cbdf9bf7b76226f368da9161bd4b37d3c7a34cd2d6d06b8c000ff35d997
; bytes 4973456e64656400

; B22_reg Tutorial.PlayMusic native/closure registrar
; VA 0x4aa720..0x4aa7b9 raw 0xa9b20 length 153 SHA256 e97005f92b956d59ba241fb5db60297912b8cdbc10b8bdfe0445b55b4b6c7adb
0x4aa720  55                                push   ebp
0x4aa721  8bec                              mov    ebp,esp
0x4aa723  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aa726  53                                push   ebx
0x4aa727  8b1d0018fe00                      mov    ebx,DWORD PTR ds:0xfe1800
0x4aa72d  56                                push   esi
0x4aa72e  8b33                              mov    esi,DWORD PTR [ebx]
0x4aa730  57                                push   edi
0x4aa731  8b38                              mov    edi,DWORD PTR [eax]
0x4aa733  b8eed8ffff                        mov    eax,0xffffd8ee
0x4aa738  c7050c18fe0030934a00              mov    DWORD PTR ds:0xfe180c,0x4a9330
0x4aa742  e839af2400                        call   0x6f5680
0x4aa747  8b03                              mov    eax,DWORD PTR [ebx]
0x4aa749  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x4aa74c  83e810                            sub    eax,0x10
0x4aa74f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x4aa754  7406                              je     0x4aa75c
0x4aa756  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x4aa75a  7414                              je     0x4aa770
0x4aa75c  57                                push   edi
0x4aa75d  68c426c400                        push   0xc426c4
0x4aa762  e856893e00                        call   0x8930bd
0x4aa767  8b1b                              mov    ebx,DWORD PTR [ebx]
0x4aa769  83c408                            add    esp,0x8
0x4aa76c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x4aa770  8b3d0018fe00                      mov    edi,DWORD PTR ds:0xfe1800
0x4aa776  8b37                              mov    esi,DWORD PTR [edi]
0x4aa778  6864abd600                        push   0xd6ab64
0x4aa77d  e88ead2400                        call   0x6f5510
0x4aa782  8b37                              mov    esi,DWORD PTR [edi]
0x4aa784  83c404                            add    esp,0x4
0x4aa787  6a00                              push   0x0
0x4aa789  6810bf4a00                        push   0x4abf10
0x4aa78e  e81dae2400                        call   0x6f55b0
0x4aa793  8b0f                              mov    ecx,DWORD PTR [edi]
0x4aa795  51                                push   ecx
0x4aa796  b8fdffffff                        mov    eax,0xfffffffd
0x4aa79b  e850b02400                        call   0x6f57f0
0x4aa7a0  8b150018fe00                      mov    edx,DWORD PTR ds:0xfe1800
0x4aa7a6  8b02                              mov    eax,DWORD PTR [edx]
0x4aa7a8  83c40c                            add    esp,0xc
0x4aa7ab  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x4aa7af  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aa7b2  5f                                pop    edi
0x4aa7b3  5e                                pop    esi
0x4aa7b4  5b                                pop    ebx
0x4aa7b5  5d                                pop    ebp
0x4aa7b6  c20400                            ret    0x4

; B22_call Initializer direct call
; VA 0x4a88fc..0x4a8901 raw 0xa7cfc length 5 SHA256 0b6243494443e1968a207279619c91fe309cdaea0efcfa4483fa0b92e67dac1b
0x4a88fc  e81f1e0000                        call   0x4aa720

; B22_closure Lua C closure for Tutorial.PlayMusic
; VA 0x4abf10..0x4abf66 raw 0xab310 length 86 SHA256 7631786a665021e425c54b0f3fd0b515cbdb77de0ca26f5666371fba8cd85967
0x4abf10  55                                push   ebp
0x4abf11  8bec                              mov    ebp,esp
0x4abf13  6aff                              push   0xffffffff
0x4abf15  68c8839300                        push   0x9383c8
0x4abf1a  64a100000000                      mov    eax,fs:0x0
0x4abf20  50                                push   eax
0x4abf21  83ec0c                            sub    esp,0xc
0x4abf24  a1201fd600                        mov    eax,ds:0xd61f20
0x4abf29  33c5                              xor    eax,ebp
0x4abf2b  50                                push   eax
0x4abf2c  8d45f4                            lea    eax,[ebp-0xc]
0x4abf2f  64a300000000                      mov    fs:0x0,eax
0x4abf35  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4abf38  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x4abf3b  33c0                              xor    eax,eax
0x4abf3d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x4abf40  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x4abf43  8d4de8                            lea    ecx,[ebp-0x18]
0x4abf46  51                                push   ecx
0x4abf47  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x4abf4a  e8510b0000                        call   0x4acaa0
0x4abf4f  83c404                            add    esp,0x4
0x4abf52  b801000000                        mov    eax,0x1
0x4abf57  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4abf5a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4abf61  59                                pop    ecx
0x4abf62  8be5                              mov    esp,ebp
0x4abf64  5d                                pop    ebp
0x4abf65  c3                                ret

; B22_name Public binding ASCII name
; VA 0xd6ab64..0xd6ab6e raw 0x968364 length 10 SHA256 9d96e7afbf342dbf0a859d165b8d7d204a982de21c522b52a79827827e73fed3
; bytes 506c61794d7573696300

; B23_reg Tutorial.StopCameraWorks native/closure registrar
; VA 0x4aa9a0..0x4aaa39 raw 0xa9da0 length 153 SHA256 9cd07a351d00959cd9317e3e3c41de025197c5057a447fbf99a3c8a961324871
0x4aa9a0  55                                push   ebp
0x4aa9a1  8bec                              mov    ebp,esp
0x4aa9a3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aa9a6  53                                push   ebx
0x4aa9a7  8b1d0018fe00                      mov    ebx,DWORD PTR ds:0xfe1800
0x4aa9ad  56                                push   esi
0x4aa9ae  8b33                              mov    esi,DWORD PTR [ebx]
0x4aa9b0  57                                push   edi
0x4aa9b1  8b38                              mov    edi,DWORD PTR [eax]
0x4aa9b3  b8eed8ffff                        mov    eax,0xffffd8ee
0x4aa9b8  c7051c18fe0070954a00              mov    DWORD PTR ds:0xfe181c,0x4a9570
0x4aa9c2  e8b9ac2400                        call   0x6f5680
0x4aa9c7  8b03                              mov    eax,DWORD PTR [ebx]
0x4aa9c9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x4aa9cc  83e810                            sub    eax,0x10
0x4aa9cf  3dc8bfc000                        cmp    eax,0xc0bfc8
0x4aa9d4  7406                              je     0x4aa9dc
0x4aa9d6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x4aa9da  7414                              je     0x4aa9f0
0x4aa9dc  57                                push   edi
0x4aa9dd  68c426c400                        push   0xc426c4
0x4aa9e2  e8d6863e00                        call   0x8930bd
0x4aa9e7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x4aa9e9  83c408                            add    esp,0x8
0x4aa9ec  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x4aa9f0  8b3d0018fe00                      mov    edi,DWORD PTR ds:0xfe1800
0x4aa9f6  8b37                              mov    esi,DWORD PTR [edi]
0x4aa9f8  68b4abd600                        push   0xd6abb4
0x4aa9fd  e80eab2400                        call   0x6f5510
0x4aaa02  8b37                              mov    esi,DWORD PTR [edi]
0x4aaa04  83c404                            add    esp,0x4
0x4aaa07  6a00                              push   0x0
0x4aaa09  6890c04a00                        push   0x4ac090
0x4aaa0e  e89dab2400                        call   0x6f55b0
0x4aaa13  8b0f                              mov    ecx,DWORD PTR [edi]
0x4aaa15  51                                push   ecx
0x4aaa16  b8fdffffff                        mov    eax,0xfffffffd
0x4aaa1b  e8d0ad2400                        call   0x6f57f0
0x4aaa20  8b150018fe00                      mov    edx,DWORD PTR ds:0xfe1800
0x4aaa26  8b02                              mov    eax,DWORD PTR [edx]
0x4aaa28  83c40c                            add    esp,0xc
0x4aaa2b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x4aaa2f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aaa32  5f                                pop    edi
0x4aaa33  5e                                pop    esi
0x4aaa34  5b                                pop    ebx
0x4aaa35  5d                                pop    ebp
0x4aaa36  c20400                            ret    0x4

; B23_call Initializer direct call
; VA 0x4a8914..0x4a8919 raw 0xa7d14 length 5 SHA256 c3992aeb2caf3c4bd7ea2d742d56037831c94e479d3475971122ef234fab7da6
0x4a8914  e887200000                        call   0x4aa9a0

; B23_closure Lua C closure for Tutorial.StopCameraWorks
; VA 0x4ac090..0x4ac0e6 raw 0xab490 length 86 SHA256 660092f4ae5a3b965dc7769811e841c588d98417fdf7485872ff761e5f8e024e
0x4ac090  55                                push   ebp
0x4ac091  8bec                              mov    ebp,esp
0x4ac093  6aff                              push   0xffffffff
0x4ac095  68c8839300                        push   0x9383c8
0x4ac09a  64a100000000                      mov    eax,fs:0x0
0x4ac0a0  50                                push   eax
0x4ac0a1  83ec0c                            sub    esp,0xc
0x4ac0a4  a1201fd600                        mov    eax,ds:0xd61f20
0x4ac0a9  33c5                              xor    eax,ebp
0x4ac0ab  50                                push   eax
0x4ac0ac  8d45f4                            lea    eax,[ebp-0xc]
0x4ac0af  64a300000000                      mov    fs:0x0,eax
0x4ac0b5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4ac0b8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x4ac0bb  33c0                              xor    eax,eax
0x4ac0bd  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x4ac0c0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x4ac0c3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x4ac0c6  8b0d0418fe00                      mov    ecx,DWORD PTR ds:0xfe1804
0x4ac0cc  ff151c18fe00                      call   DWORD PTR ds:0xfe181c
0x4ac0d2  b801000000                        mov    eax,0x1
0x4ac0d7  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4ac0da  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4ac0e1  59                                pop    ecx
0x4ac0e2  8be5                              mov    esp,ebp
0x4ac0e4  5d                                pop    ebp
0x4ac0e5  c3                                ret

; B23_name Public binding ASCII name
; VA 0xd6abb4..0xd6abc4 raw 0x9683b4 length 16 SHA256 594b828c67e47d1ccfd7a95e10c73ff876791f9ddef65e8fc38c22d74011032c
; bytes 53746f7043616d657261576f726b7300

; B24_reg Tutorial.PushCamera native/closure registrar
; VA 0x4aaa40..0x4aaad9 raw 0xa9e40 length 153 SHA256 81fc1ad62b80b622247c92c1fe097ab76fdb63725226923beec4c02d495b2bc8
0x4aaa40  55                                push   ebp
0x4aaa41  8bec                              mov    ebp,esp
0x4aaa43  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aaa46  53                                push   ebx
0x4aaa47  8b1d0018fe00                      mov    ebx,DWORD PTR ds:0xfe1800
0x4aaa4d  56                                push   esi
0x4aaa4e  8b33                              mov    esi,DWORD PTR [ebx]
0x4aaa50  57                                push   edi
0x4aaa51  8b38                              mov    edi,DWORD PTR [eax]
0x4aaa53  b8eed8ffff                        mov    eax,0xffffd8ee
0x4aaa58  c7052018fe00f0954a00              mov    DWORD PTR ds:0xfe1820,0x4a95f0
0x4aaa62  e819ac2400                        call   0x6f5680
0x4aaa67  8b03                              mov    eax,DWORD PTR [ebx]
0x4aaa69  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x4aaa6c  83e810                            sub    eax,0x10
0x4aaa6f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x4aaa74  7406                              je     0x4aaa7c
0x4aaa76  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x4aaa7a  7414                              je     0x4aaa90
0x4aaa7c  57                                push   edi
0x4aaa7d  68c426c400                        push   0xc426c4
0x4aaa82  e836863e00                        call   0x8930bd
0x4aaa87  8b1b                              mov    ebx,DWORD PTR [ebx]
0x4aaa89  83c408                            add    esp,0x8
0x4aaa8c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x4aaa90  8b3d0018fe00                      mov    edi,DWORD PTR ds:0xfe1800
0x4aaa96  8b37                              mov    esi,DWORD PTR [edi]
0x4aaa98  68c4abd600                        push   0xd6abc4
0x4aaa9d  e86eaa2400                        call   0x6f5510
0x4aaaa2  8b37                              mov    esi,DWORD PTR [edi]
0x4aaaa4  83c404                            add    esp,0x4
0x4aaaa7  6a00                              push   0x0
0x4aaaa9  68f0c04a00                        push   0x4ac0f0
0x4aaaae  e8fdaa2400                        call   0x6f55b0
0x4aaab3  8b0f                              mov    ecx,DWORD PTR [edi]
0x4aaab5  51                                push   ecx
0x4aaab6  b8fdffffff                        mov    eax,0xfffffffd
0x4aaabb  e830ad2400                        call   0x6f57f0
0x4aaac0  8b150018fe00                      mov    edx,DWORD PTR ds:0xfe1800
0x4aaac6  8b02                              mov    eax,DWORD PTR [edx]
0x4aaac8  83c40c                            add    esp,0xc
0x4aaacb  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x4aaacf  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aaad2  5f                                pop    edi
0x4aaad3  5e                                pop    esi
0x4aaad4  5b                                pop    ebx
0x4aaad5  5d                                pop    ebp
0x4aaad6  c20400                            ret    0x4

; B24_call Initializer direct call
; VA 0x4a891a..0x4a891f raw 0xa7d1a length 5 SHA256 15a9432c61adbdcde6910b13a4eced71ab02c2e8b911b2e116f36579e7344ea1
0x4a891a  e821210000                        call   0x4aaa40

; B24_closure Lua C closure for Tutorial.PushCamera
; VA 0x4ac0f0..0x4ac14c raw 0xab4f0 length 92 SHA256 b21af20a683bc46e8f1cb943596bea89813876586c82612b632d3dec0ddc5d96
0x4ac0f0  55                                push   ebp
0x4ac0f1  8bec                              mov    ebp,esp
0x4ac0f3  6aff                              push   0xffffffff
0x4ac0f5  68c8839300                        push   0x9383c8
0x4ac0fa  64a100000000                      mov    eax,fs:0x0
0x4ac100  50                                push   eax
0x4ac101  83ec0c                            sub    esp,0xc
0x4ac104  a1201fd600                        mov    eax,ds:0xd61f20
0x4ac109  33c5                              xor    eax,ebp
0x4ac10b  50                                push   eax
0x4ac10c  8d45f4                            lea    eax,[ebp-0xc]
0x4ac10f  64a300000000                      mov    fs:0x0,eax
0x4ac115  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4ac118  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x4ac11b  33c0                              xor    eax,eax
0x4ac11d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x4ac120  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x4ac123  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x4ac126  8b0d2018fe00                      mov    ecx,DWORD PTR ds:0xfe1820
0x4ac12c  51                                push   ecx
0x4ac12d  8d45e8                            lea    eax,[ebp-0x18]
0x4ac130  e8fb0b0000                        call   0x4acd30
0x4ac135  83c404                            add    esp,0x4
0x4ac138  b801000000                        mov    eax,0x1
0x4ac13d  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4ac140  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4ac147  59                                pop    ecx
0x4ac148  8be5                              mov    esp,ebp
0x4ac14a  5d                                pop    ebp
0x4ac14b  c3                                ret

; B24_name Public binding ASCII name
; VA 0xd6abc4..0xd6abcf raw 0x9683c4 length 11 SHA256 99b1319652c18afa9e3112326f5bfb292d1311d06abbda0043d35c1b5097ba7b
; bytes 5075736843616d65726100

; B25_reg Tutorial.PopCamera native/closure registrar
; VA 0x4aaae0..0x4aab79 raw 0xa9ee0 length 153 SHA256 e1d95bc76c54aa8f4ff9ad505b0458880518b4198db91211250949eb0db49aed
0x4aaae0  55                                push   ebp
0x4aaae1  8bec                              mov    ebp,esp
0x4aaae3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aaae6  53                                push   ebx
0x4aaae7  8b1d0018fe00                      mov    ebx,DWORD PTR ds:0xfe1800
0x4aaaed  56                                push   esi
0x4aaaee  8b33                              mov    esi,DWORD PTR [ebx]
0x4aaaf0  57                                push   edi
0x4aaaf1  8b38                              mov    edi,DWORD PTR [eax]
0x4aaaf3  b8eed8ffff                        mov    eax,0xffffd8ee
0x4aaaf8  c7052418fe00a0964a00              mov    DWORD PTR ds:0xfe1824,0x4a96a0
0x4aab02  e879ab2400                        call   0x6f5680
0x4aab07  8b03                              mov    eax,DWORD PTR [ebx]
0x4aab09  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x4aab0c  83e810                            sub    eax,0x10
0x4aab0f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x4aab14  7406                              je     0x4aab1c
0x4aab16  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x4aab1a  7414                              je     0x4aab30
0x4aab1c  57                                push   edi
0x4aab1d  68c426c400                        push   0xc426c4
0x4aab22  e896853e00                        call   0x8930bd
0x4aab27  8b1b                              mov    ebx,DWORD PTR [ebx]
0x4aab29  83c408                            add    esp,0x8
0x4aab2c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x4aab30  8b3d0018fe00                      mov    edi,DWORD PTR ds:0xfe1800
0x4aab36  8b37                              mov    esi,DWORD PTR [edi]
0x4aab38  68d0abd600                        push   0xd6abd0
0x4aab3d  e8cea92400                        call   0x6f5510
0x4aab42  8b37                              mov    esi,DWORD PTR [edi]
0x4aab44  83c404                            add    esp,0x4
0x4aab47  6a00                              push   0x0
0x4aab49  6850c14a00                        push   0x4ac150
0x4aab4e  e85daa2400                        call   0x6f55b0
0x4aab53  8b0f                              mov    ecx,DWORD PTR [edi]
0x4aab55  51                                push   ecx
0x4aab56  b8fdffffff                        mov    eax,0xfffffffd
0x4aab5b  e890ac2400                        call   0x6f57f0
0x4aab60  8b150018fe00                      mov    edx,DWORD PTR ds:0xfe1800
0x4aab66  8b02                              mov    eax,DWORD PTR [edx]
0x4aab68  83c40c                            add    esp,0xc
0x4aab6b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x4aab6f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aab72  5f                                pop    edi
0x4aab73  5e                                pop    esi
0x4aab74  5b                                pop    ebx
0x4aab75  5d                                pop    ebp
0x4aab76  c20400                            ret    0x4

; B25_call Initializer direct call
; VA 0x4a8920..0x4a8925 raw 0xa7d20 length 5 SHA256 e945ae5486cbb0c2f17461d4a5074a089278311b73e126539ca1ff2d115ef575
0x4a8920  e8bb210000                        call   0x4aaae0

; B25_closure Lua C closure for Tutorial.PopCamera
; VA 0x4ac150..0x4ac1ac raw 0xab550 length 92 SHA256 b3703ab313c7f76c60d506c77dd7b76dc9bd6c84a517c48c4e0ee536720befd1
0x4ac150  55                                push   ebp
0x4ac151  8bec                              mov    ebp,esp
0x4ac153  6aff                              push   0xffffffff
0x4ac155  68c8839300                        push   0x9383c8
0x4ac15a  64a100000000                      mov    eax,fs:0x0
0x4ac160  50                                push   eax
0x4ac161  83ec0c                            sub    esp,0xc
0x4ac164  a1201fd600                        mov    eax,ds:0xd61f20
0x4ac169  33c5                              xor    eax,ebp
0x4ac16b  50                                push   eax
0x4ac16c  8d45f4                            lea    eax,[ebp-0xc]
0x4ac16f  64a300000000                      mov    fs:0x0,eax
0x4ac175  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4ac178  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x4ac17b  33c0                              xor    eax,eax
0x4ac17d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x4ac180  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x4ac183  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x4ac186  8b0d2418fe00                      mov    ecx,DWORD PTR ds:0xfe1824
0x4ac18c  51                                push   ecx
0x4ac18d  8d45e8                            lea    eax,[ebp-0x18]
0x4ac190  e89b0b0000                        call   0x4acd30
0x4ac195  83c404                            add    esp,0x4
0x4ac198  b801000000                        mov    eax,0x1
0x4ac19d  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4ac1a0  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4ac1a7  59                                pop    ecx
0x4ac1a8  8be5                              mov    esp,ebp
0x4ac1aa  5d                                pop    ebp
0x4ac1ab  c3                                ret

; B25_name Public binding ASCII name
; VA 0xd6abd0..0xd6abda raw 0x9683d0 length 10 SHA256 6633868aa0e9bd2fd8978408d7e65982f1ec6f0423e648bd1c97b7400bcb0bf9
; bytes 506f7043616d65726100

; B26_reg Tutorial.ApplyDefaultCamera native/closure registrar
; VA 0x4aab80..0x4aac19 raw 0xa9f80 length 153 SHA256 01fd575e4906aca8909b42368b8cfdd890d4ed850627edfa9f0eed5f669f39a5
0x4aab80  55                                push   ebp
0x4aab81  8bec                              mov    ebp,esp
0x4aab83  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aab86  53                                push   ebx
0x4aab87  8b1d0018fe00                      mov    ebx,DWORD PTR ds:0xfe1800
0x4aab8d  56                                push   esi
0x4aab8e  8b33                              mov    esi,DWORD PTR [ebx]
0x4aab90  57                                push   edi
0x4aab91  8b38                              mov    edi,DWORD PTR [eax]
0x4aab93  b8eed8ffff                        mov    eax,0xffffd8ee
0x4aab98  c7052818fe0020974a00              mov    DWORD PTR ds:0xfe1828,0x4a9720
0x4aaba2  e8d9aa2400                        call   0x6f5680
0x4aaba7  8b03                              mov    eax,DWORD PTR [ebx]
0x4aaba9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x4aabac  83e810                            sub    eax,0x10
0x4aabaf  3dc8bfc000                        cmp    eax,0xc0bfc8
0x4aabb4  7406                              je     0x4aabbc
0x4aabb6  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x4aabba  7414                              je     0x4aabd0
0x4aabbc  57                                push   edi
0x4aabbd  68c426c400                        push   0xc426c4
0x4aabc2  e8f6843e00                        call   0x8930bd
0x4aabc7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x4aabc9  83c408                            add    esp,0x8
0x4aabcc  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x4aabd0  8b3d0018fe00                      mov    edi,DWORD PTR ds:0xfe1800
0x4aabd6  8b37                              mov    esi,DWORD PTR [edi]
0x4aabd8  68dcabd600                        push   0xd6abdc
0x4aabdd  e82ea92400                        call   0x6f5510
0x4aabe2  8b37                              mov    esi,DWORD PTR [edi]
0x4aabe4  83c404                            add    esp,0x4
0x4aabe7  6a00                              push   0x0
0x4aabe9  68b0c14a00                        push   0x4ac1b0
0x4aabee  e8bda92400                        call   0x6f55b0
0x4aabf3  8b0f                              mov    ecx,DWORD PTR [edi]
0x4aabf5  51                                push   ecx
0x4aabf6  b8fdffffff                        mov    eax,0xfffffffd
0x4aabfb  e8f0ab2400                        call   0x6f57f0
0x4aac00  8b150018fe00                      mov    edx,DWORD PTR ds:0xfe1800
0x4aac06  8b02                              mov    eax,DWORD PTR [edx]
0x4aac08  83c40c                            add    esp,0xc
0x4aac0b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x4aac0f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aac12  5f                                pop    edi
0x4aac13  5e                                pop    esi
0x4aac14  5b                                pop    ebx
0x4aac15  5d                                pop    ebp
0x4aac16  c20400                            ret    0x4

; B26_call Initializer direct call
; VA 0x4a8926..0x4a892b raw 0xa7d26 length 5 SHA256 f4127defcbe89a816dc6c02303824551a79919fa0a59ea4639af68a01e978de6
0x4a8926  e855220000                        call   0x4aab80

; B26_closure Lua C closure for Tutorial.ApplyDefaultCamera
; VA 0x4ac1b0..0x4ac206 raw 0xab5b0 length 86 SHA256 40ea32e0c76903441f96d986be36a5ede5993c0c81862ec6b9fc69179a156bd3
0x4ac1b0  55                                push   ebp
0x4ac1b1  8bec                              mov    ebp,esp
0x4ac1b3  6aff                              push   0xffffffff
0x4ac1b5  68c8839300                        push   0x9383c8
0x4ac1ba  64a100000000                      mov    eax,fs:0x0
0x4ac1c0  50                                push   eax
0x4ac1c1  83ec0c                            sub    esp,0xc
0x4ac1c4  a1201fd600                        mov    eax,ds:0xd61f20
0x4ac1c9  33c5                              xor    eax,ebp
0x4ac1cb  50                                push   eax
0x4ac1cc  8d45f4                            lea    eax,[ebp-0xc]
0x4ac1cf  64a300000000                      mov    fs:0x0,eax
0x4ac1d5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4ac1d8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x4ac1db  33c0                              xor    eax,eax
0x4ac1dd  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x4ac1e0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x4ac1e3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x4ac1e6  8b0d0418fe00                      mov    ecx,DWORD PTR ds:0xfe1804
0x4ac1ec  ff152818fe00                      call   DWORD PTR ds:0xfe1828
0x4ac1f2  b801000000                        mov    eax,0x1
0x4ac1f7  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4ac1fa  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4ac201  59                                pop    ecx
0x4ac202  8be5                              mov    esp,ebp
0x4ac204  5d                                pop    ebp
0x4ac205  c3                                ret

; B26_name Public binding ASCII name
; VA 0xd6abdc..0xd6abef raw 0x9683dc length 19 SHA256 bb5a39a2a07572680ac2804a61d304cbacb521de6ab3895aef6a682de9f28b9d
; bytes 4170706c7944656661756c7443616d65726100

; B27_reg Fade.Start native/closure registrar
; VA 0x55e930..0x55e9c9 raw 0x15dd30 length 153 SHA256 a5b88792370728ba66ead59176fc1725f42eac12b2c1ac244462eb186c89ad71
0x55e930  55                                push   ebp
0x55e931  8bec                              mov    ebp,esp
0x55e933  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x55e936  53                                push   ebx
0x55e937  8b1d2c1ffe00                      mov    ebx,DWORD PTR ds:0xfe1f2c
0x55e93d  56                                push   esi
0x55e93e  8b33                              mov    esi,DWORD PTR [ebx]
0x55e940  57                                push   edi
0x55e941  8b38                              mov    edi,DWORD PTR [eax]
0x55e943  b8eed8ffff                        mov    eax,0xffffd8ee
0x55e948  c705341ffe0040e75500              mov    DWORD PTR ds:0xfe1f34,0x55e740
0x55e952  e8296d1900                        call   0x6f5680
0x55e957  8b03                              mov    eax,DWORD PTR [ebx]
0x55e959  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x55e95c  83e810                            sub    eax,0x10
0x55e95f  3dc8bfc000                        cmp    eax,0xc0bfc8
0x55e964  7406                              je     0x55e96c
0x55e966  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x55e96a  7414                              je     0x55e980
0x55e96c  57                                push   edi
0x55e96d  68c426c400                        push   0xc426c4
0x55e972  e846473300                        call   0x8930bd
0x55e977  8b1b                              mov    ebx,DWORD PTR [ebx]
0x55e979  83c408                            add    esp,0x8
0x55e97c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x55e980  8b3d2c1ffe00                      mov    edi,DWORD PTR ds:0xfe1f2c
0x55e986  8b37                              mov    esi,DWORD PTR [edi]
0x55e988  68c4a5d600                        push   0xd6a5c4
0x55e98d  e87e6b1900                        call   0x6f5510
0x55e992  8b37                              mov    esi,DWORD PTR [edi]
0x55e994  83c404                            add    esp,0x4
0x55e997  6a00                              push   0x0
0x55e999  6890ea5500                        push   0x55ea90
0x55e99e  e80d6c1900                        call   0x6f55b0
0x55e9a3  8b0f                              mov    ecx,DWORD PTR [edi]
0x55e9a5  51                                push   ecx
0x55e9a6  b8fdffffff                        mov    eax,0xfffffffd
0x55e9ab  e8406e1900                        call   0x6f57f0
0x55e9b0  8b152c1ffe00                      mov    edx,DWORD PTR ds:0xfe1f2c
0x55e9b6  8b02                              mov    eax,DWORD PTR [edx]
0x55e9b8  83c40c                            add    esp,0xc
0x55e9bb  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x55e9bf  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x55e9c2  5f                                pop    edi
0x55e9c3  5e                                pop    esi
0x55e9c4  5b                                pop    ebx
0x55e9c5  5d                                pop    ebp
0x55e9c6  c20400                            ret    0x4

; B27_call Initializer direct call
; VA 0x55e715..0x55e71a raw 0x15db15 length 5 SHA256 6ad5dfbc7c7dd9b07d7331fb21b1fd86e131cd6ec7bcc1389e977f79cf088753
0x55e715  e816020000                        call   0x55e930

; B27_closure Lua C closure for Fade.Start
; VA 0x55ea90..0x55eae6 raw 0x15de90 length 86 SHA256 e3e746b8db4e09b3e99a3f4d8cb04912b117c8133e40e139f6db86cd32d3f0db
0x55ea90  55                                push   ebp
0x55ea91  8bec                              mov    ebp,esp
0x55ea93  6aff                              push   0xffffffff
0x55ea95  68c8839300                        push   0x9383c8
0x55ea9a  64a100000000                      mov    eax,fs:0x0
0x55eaa0  50                                push   eax
0x55eaa1  83ec0c                            sub    esp,0xc
0x55eaa4  a1201fd600                        mov    eax,ds:0xd61f20
0x55eaa9  33c5                              xor    eax,ebp
0x55eaab  50                                push   eax
0x55eaac  8d45f4                            lea    eax,[ebp-0xc]
0x55eaaf  64a300000000                      mov    fs:0x0,eax
0x55eab5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x55eab8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x55eabb  33c0                              xor    eax,eax
0x55eabd  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x55eac0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x55eac3  8d4de8                            lea    ecx,[ebp-0x18]
0x55eac6  51                                push   ecx
0x55eac7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x55eaca  e881000000                        call   0x55eb50
0x55eacf  83c404                            add    esp,0x4
0x55ead2  b801000000                        mov    eax,0x1
0x55ead7  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x55eada  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x55eae1  59                                pop    ecx
0x55eae2  8be5                              mov    esp,ebp
0x55eae4  5d                                pop    ebp
0x55eae5  c3                                ret

; B27_name Public binding ASCII name
; VA 0xd6a5c4..0xd6a5ca raw 0x967dc4 length 6 SHA256 e637763d3a4a936dcdc70b597fd2d529653ef097d145ffae257a6a95de76b7e3
; bytes 537461727400

; B28_reg Fade.End native/closure registrar
; VA 0x55e9d0..0x55ea82 raw 0x15ddd0 length 178 SHA256 980e94e27cab42a1a72ceedd3d9585459b8143bc69f2369f3724abba74f2433e
0x55e9d0  55                                push   ebp
0x55e9d1  8bec                              mov    ebp,esp
0x55e9d3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x55e9d6  53                                push   ebx
0x55e9d7  8b1d2c1ffe00                      mov    ebx,DWORD PTR ds:0xfe1f2c
0x55e9dd  56                                push   esi
0x55e9de  8b33                              mov    esi,DWORD PTR [ebx]
0x55e9e0  57                                push   edi
0x55e9e1  8b38                              mov    edi,DWORD PTR [eax]
0x55e9e3  b8eed8ffff                        mov    eax,0xffffd8ee
0x55e9e8  c705381ffe0070e75500              mov    DWORD PTR ds:0xfe1f38,0x55e770
0x55e9f2  e8896c1900                        call   0x6f5680
0x55e9f7  8b03                              mov    eax,DWORD PTR [ebx]
0x55e9f9  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x55e9fc  83e810                            sub    eax,0x10
0x55e9ff  3dc8bfc000                        cmp    eax,0xc0bfc8
0x55ea04  7406                              je     0x55ea0c
0x55ea06  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x55ea0a  7414                              je     0x55ea20
0x55ea0c  57                                push   edi
0x55ea0d  68c426c400                        push   0xc426c4
0x55ea12  e8a6463300                        call   0x8930bd
0x55ea17  8b1b                              mov    ebx,DWORD PTR [ebx]
0x55ea19  83c408                            add    esp,0x8
0x55ea1c  834308f0                          add    DWORD PTR [ebx+0x8],0xfffffff0
0x55ea20  8b3d2c1ffe00                      mov    edi,DWORD PTR ds:0xfe1f2c
0x55ea26  8b37                              mov    esi,DWORD PTR [edi]
0x55ea28  68cca5d600                        push   0xd6a5cc
0x55ea2d  e8de6a1900                        call   0x6f5510
0x55ea32  8b37                              mov    esi,DWORD PTR [edi]
0x55ea34  83c404                            add    esp,0x4
0x55ea37  6a00                              push   0x0
0x55ea39  68f0ea5500                        push   0x55eaf0
0x55ea3e  e86d6b1900                        call   0x6f55b0
0x55ea43  8b0f                              mov    ecx,DWORD PTR [edi]
0x55ea45  51                                push   ecx
0x55ea46  b8fdffffff                        mov    eax,0xfffffffd
0x55ea4b  e8a06d1900                        call   0x6f57f0
0x55ea50  8b152c1ffe00                      mov    edx,DWORD PTR ds:0xfe1f2c
0x55ea56  8b02                              mov    eax,DWORD PTR [edx]
0x55ea58  83c40c                            add    esp,0xc
0x55ea5b  834008f0                          add    DWORD PTR [eax+0x8],0xfffffff0
0x55ea5f  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x55ea62  5f                                pop    edi
0x55ea63  5e                                pop    esi
0x55ea64  5b                                pop    ebx
0x55ea65  5d                                pop    ebp
0x55ea66  c20400                            ret    0x4
0x55ea69  cc                                int3
0x55ea6a  cc                                int3
0x55ea6b  cc                                int3
0x55ea6c  cc                                int3
0x55ea6d  cc                                int3
0x55ea6e  cc                                int3
0x55ea6f  cc                                int3
0x55ea70  a12c1ffe00                        mov    eax,ds:0xfe1f2c
0x55ea75  e83641f4ff                        call   0x4a2bb0
0x55ea7a  a3301ffe00                        mov    ds:0xfe1f30,eax
0x55ea7f  33c0                              xor    eax,eax
0x55ea81  c3                                ret

; B28_call Initializer direct call
; VA 0x55e71b..0x55e720 raw 0x15db1b length 5 SHA256 54f33456bde9a7f22046c08246a8d568b52e1ee67a14ed55ccd847d20a698435
0x55e71b  e8b0020000                        call   0x55e9d0

; B28_closure Lua C closure for Fade.End
; VA 0x55eaf0..0x55eb42 raw 0x15def0 length 82 SHA256 5444fece565e0bf78268e825b66d43db1b56f1bbb045000624bbc229cb650d0e
0x55eaf0  55                                push   ebp
0x55eaf1  8bec                              mov    ebp,esp
0x55eaf3  6aff                              push   0xffffffff
0x55eaf5  68c8839300                        push   0x9383c8
0x55eafa  64a100000000                      mov    eax,fs:0x0
0x55eb00  50                                push   eax
0x55eb01  83ec0c                            sub    esp,0xc
0x55eb04  a1201fd600                        mov    eax,ds:0xd61f20
0x55eb09  33c5                              xor    eax,ebp
0x55eb0b  50                                push   eax
0x55eb0c  8d45f4                            lea    eax,[ebp-0xc]
0x55eb0f  64a300000000                      mov    fs:0x0,eax
0x55eb15  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x55eb18  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x55eb1b  33c0                              xor    eax,eax
0x55eb1d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x55eb20  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x55eb23  8d4de8                            lea    ecx,[ebp-0x18]
0x55eb26  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x55eb29  e812010000                        call   0x55ec40
0x55eb2e  b801000000                        mov    eax,0x1
0x55eb33  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x55eb36  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x55eb3d  59                                pop    ecx
0x55eb3e  8be5                              mov    esp,ebp
0x55eb40  5d                                pop    ebp
0x55eb41  c3                                ret

; B28_name Public binding ASCII name
; VA 0xd6a5cc..0xd6a5d0 raw 0x967dcc length 4 SHA256 8868f0ce84725cef24ee0cd05a1f2cebc6fd7eb83b5a64c3694f0b58923eb064
; bytes 456e6400

; B_Q_namespace Q namespace/receiver binding
; VA 0x565e40..0x565f15 raw 0x165240 length 213 SHA256 8799844b6771a4b2652be2e4442053f1058ba8213881942a991e94945038efdb
0x565e40  55                                push   ebp
0x565e41  8bec                              mov    ebp,esp
0x565e43  51                                push   ecx
0x565e44  53                                push   ebx
0x565e45  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x565e48  56                                push   esi
0x565e49  8b33                              mov    esi,DWORD PTR [ebx]
0x565e4b  a37827fe00                        mov    ds:0xfe2778,eax
0x565e50  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x565e53  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x565e56  57                                push   edi
0x565e57  891d7427fe00                      mov    DWORD PTR ds:0xfe2774,ebx
0x565e5d  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x565e60  7207                              jb     0x565e69
0x565e62  8bc6                              mov    eax,esi
0x565e64  e837551900                        call   0x6fb3a0
0x565e69  8b7e08                            mov    edi,DWORD PTR [esi+0x8]
0x565e6c  6a00                              push   0x0
0x565e6e  6a00                              push   0x0
0x565e70  56                                push   esi
0x565e71  e82a3b1900                        call   0x6f99a0
0x565e76  8907                              mov    DWORD PTR [edi],eax
0x565e78  c7470805000000                    mov    DWORD PTR [edi+0x8],0x5
0x565e7f  83460810                          add    DWORD PTR [esi+0x8],0x10
0x565e83  8b33                              mov    esi,DWORD PTR [ebx]
0x565e85  83c40c                            add    esp,0xc
0x565e88  bf0406c100                        mov    edi,0xc10604
0x565e8d  b8eed8ffff                        mov    eax,0xffffd8ee
0x565e92  e8f9f81800                        call   0x6f5790
0x565e97  8b33                              mov    esi,DWORD PTR [ebx]
0x565e99  b8eed8ffff                        mov    eax,0xffffd8ee
0x565e9e  e8ddf71800                        call   0x6f5680
0x565ea3  8b03                              mov    eax,DWORD PTR [ebx]
0x565ea5  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x565ea8  83e810                            sub    eax,0x10
0x565eab  bff0ffffff                        mov    edi,0xfffffff0
0x565eb0  3dc8bfc000                        cmp    eax,0xc0bfc8
0x565eb5  7406                              je     0x565ebd
0x565eb7  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x565ebb  7417                              je     0x565ed4
0x565ebd  680406c100                        push   0xc10604
0x565ec2  68c426c400                        push   0xc426c4
0x565ec7  e8f1d13200                        call   0x8930bd
0x565ecc  8b03                              mov    eax,DWORD PTR [ebx]
0x565ece  83c408                            add    esp,0x8
0x565ed1  017808                            add    DWORD PTR [eax+0x8],edi
0x565ed4  8b33                              mov    esi,DWORD PTR [ebx]
0x565ed6  682462c000                        push   0xc06224
0x565edb  e830f61800                        call   0x6f5510
0x565ee0  8b33                              mov    esi,DWORD PTR [ebx]
0x565ee2  83c404                            add    esp,0x4
0x565ee5  6a00                              push   0x0
0x565ee7  6890875600                        push   0x568790
0x565eec  e8bff61800                        call   0x6f55b0
0x565ef1  8b13                              mov    edx,DWORD PTR [ebx]
0x565ef3  52                                push   edx
0x565ef4  b8fdffffff                        mov    eax,0xfffffffd
0x565ef9  e8f2f81800                        call   0x6f57f0
0x565efe  8b1b                              mov    ebx,DWORD PTR [ebx]
0x565f00  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x565f03  83c40c                            add    esp,0xc
0x565f06  017b08                            add    DWORD PTR [ebx+0x8],edi
0x565f09  5f                                pop    edi
0x565f0a  5e                                pop    esi
0x565f0b  c7000406c100                      mov    DWORD PTR [eax],0xc10604
0x565f11  5b                                pop    ebx
0x565f12  59                                pop    ecx
0x565f13  5d                                pop    ebp
0x565f14  c3                                ret

; B_Q_root Q selected public registrar root
; VA 0x560600..0x5607c3 raw 0x15fa00 length 451 SHA256 a3c5450ea3251f3054ea3867396b36851b2743317f2b9d645a2b1711a009dc61
0x560600  55                                push   ebp
0x560601  8bec                              mov    ebp,esp
0x560603  83ec08                            sub    esp,0x8
0x560606  8d4dfc                            lea    ecx,[ebp-0x4]
0x560609  56                                push   esi
0x56060a  51                                push   ecx
0x56060b  8930                              mov    DWORD PTR [eax],esi
0x56060d  e82e580000                        call   0x565e40
0x560612  83c408                            add    esp,0x8
0x560615  50                                push   eax
0x560616  e805590000                        call   0x565f20
0x56061b  50                                push   eax
0x56061c  e89f590000                        call   0x565fc0
0x560621  50                                push   eax
0x560622  e8395a0000                        call   0x566060
0x560627  50                                push   eax
0x560628  e8d35a0000                        call   0x566100
0x56062d  50                                push   eax
0x56062e  e86d5b0000                        call   0x5661a0
0x560633  50                                push   eax
0x560634  e8075c0000                        call   0x566240
0x560639  50                                push   eax
0x56063a  e8a15c0000                        call   0x5662e0
0x56063f  50                                push   eax
0x560640  e83b5d0000                        call   0x566380
0x560645  50                                push   eax
0x560646  e8d55d0000                        call   0x566420
0x56064b  50                                push   eax
0x56064c  e86f5e0000                        call   0x5664c0
0x560651  50                                push   eax
0x560652  e8095f0000                        call   0x566560
0x560657  50                                push   eax
0x560658  e8a35f0000                        call   0x566600
0x56065d  50                                push   eax
0x56065e  e83d600000                        call   0x5666a0
0x560663  50                                push   eax
0x560664  e8d7600000                        call   0x566740
0x560669  50                                push   eax
0x56066a  e871610000                        call   0x5667e0
0x56066f  50                                push   eax
0x560670  e80b620000                        call   0x566880
0x560675  50                                push   eax
0x560676  e8a5620000                        call   0x566920
0x56067b  50                                push   eax
0x56067c  e83f630000                        call   0x5669c0
0x560681  50                                push   eax
0x560682  e8d9630000                        call   0x566a60
0x560687  50                                push   eax
0x560688  e873640000                        call   0x566b00
0x56068d  50                                push   eax
0x56068e  e80d650000                        call   0x566ba0
0x560693  50                                push   eax
0x560694  e8a7650000                        call   0x566c40
0x560699  50                                push   eax
0x56069a  e841660000                        call   0x566ce0
0x56069f  50                                push   eax
0x5606a0  e8db660000                        call   0x566d80
0x5606a5  50                                push   eax
0x5606a6  e875670000                        call   0x566e20
0x5606ab  50                                push   eax
0x5606ac  e80f680000                        call   0x566ec0
0x5606b1  50                                push   eax
0x5606b2  e8a9680000                        call   0x566f60
0x5606b7  50                                push   eax
0x5606b8  e843690000                        call   0x567000
0x5606bd  50                                push   eax
0x5606be  e8dd690000                        call   0x5670a0
0x5606c3  50                                push   eax
0x5606c4  e8776a0000                        call   0x567140
0x5606c9  50                                push   eax
0x5606ca  e8116b0000                        call   0x5671e0
0x5606cf  50                                push   eax
0x5606d0  e8ab6b0000                        call   0x567280
0x5606d5  50                                push   eax
0x5606d6  e8456c0000                        call   0x567320
0x5606db  50                                push   eax
0x5606dc  e8df6c0000                        call   0x5673c0
0x5606e1  50                                push   eax
0x5606e2  e8796d0000                        call   0x567460
0x5606e7  50                                push   eax
0x5606e8  e8136e0000                        call   0x567500
0x5606ed  50                                push   eax
0x5606ee  e8ad6e0000                        call   0x5675a0
0x5606f3  50                                push   eax
0x5606f4  e8476f0000                        call   0x567640
0x5606f9  50                                push   eax
0x5606fa  e8e16f0000                        call   0x5676e0
0x5606ff  50                                push   eax
0x560700  e87b700000                        call   0x567780
0x560705  50                                push   eax
0x560706  e815710000                        call   0x567820
0x56070b  50                                push   eax
0x56070c  e8af710000                        call   0x5678c0
0x560711  50                                push   eax
0x560712  e849720000                        call   0x567960
0x560717  50                                push   eax
0x560718  e8e3720000                        call   0x567a00
0x56071d  50                                push   eax
0x56071e  e87d730000                        call   0x567aa0
0x560723  50                                push   eax
0x560724  e817740000                        call   0x567b40
0x560729  50                                push   eax
0x56072a  e8b1740000                        call   0x567be0
0x56072f  50                                push   eax
0x560730  e84b750000                        call   0x567c80
0x560735  50                                push   eax
0x560736  e8e5750000                        call   0x567d20
0x56073b  50                                push   eax
0x56073c  e87f760000                        call   0x567dc0
0x560741  50                                push   eax
0x560742  e819770000                        call   0x567e60
0x560747  50                                push   eax
0x560748  e8b3770000                        call   0x567f00
0x56074d  50                                push   eax
0x56074e  e84d780000                        call   0x567fa0
0x560753  50                                push   eax
0x560754  e8e7780000                        call   0x568040
0x560759  50                                push   eax
0x56075a  e881790000                        call   0x5680e0
0x56075f  50                                push   eax
0x560760  e81b7a0000                        call   0x568180
0x560765  50                                push   eax
0x560766  e8b57a0000                        call   0x568220
0x56076b  50                                push   eax
0x56076c  e84f7b0000                        call   0x5682c0
0x560771  50                                push   eax
0x560772  e8e97b0000                        call   0x568360
0x560777  50                                push   eax
0x560778  e8837c0000                        call   0x568400
0x56077d  50                                push   eax
0x56077e  e81d7d0000                        call   0x5684a0
0x560783  50                                push   eax
0x560784  e8b77d0000                        call   0x568540
0x560789  50                                push   eax
0x56078a  e8517e0000                        call   0x5685e0
0x56078f  68c855c000                        push   0xc055c8
0x560794  8bce                              mov    ecx,esi
0x560796  e8b5421900                        call   0x6f4a50
0x56079b  68b055c000                        push   0xc055b0
0x5607a0  8bce                              mov    ecx,esi
0x5607a2  e8a9421900                        call   0x6f4a50
0x5607a7  68bc55c000                        push   0xc055bc
0x5607ac  8bce                              mov    ecx,esi
0x5607ae  e89d421900                        call   0x6f4a50
0x5607b3  685806c100                        push   0xc10658
0x5607b8  8bce                              mov    ecx,esi
0x5607ba  e891421900                        call   0x6f4a50
0x5607bf  8be5                              mov    esp,ebp
0x5607c1  5d                                pop    ebp
0x5607c2  c3                                ret

; B_TUT_root Tutorial public registrar root
; VA 0x4a88e0..0x4a89bf raw 0xa7ce0 length 223 SHA256 c02c1bb33b21151db1ec5bbeffe4086005d24a77413a8d395d70428a8a528ff0
0x4a88e0  55                                push   ebp
0x4a88e1  8bec                              mov    ebp,esp
0x4a88e3  83ec08                            sub    esp,0x8
0x4a88e6  8d4dfc                            lea    ecx,[ebp-0x4]
0x4a88e9  56                                push   esi
0x4a88ea  51                                push   ecx
0x4a88eb  8930                              mov    DWORD PTR [eax],esi
0x4a88ed  e8ae1c0000                        call   0x4aa5a0
0x4a88f2  83c408                            add    esp,0x8
0x4a88f5  50                                push   eax
0x4a88f6  e8851d0000                        call   0x4aa680
0x4a88fb  50                                push   eax
0x4a88fc  e81f1e0000                        call   0x4aa720
0x4a8901  50                                push   eax
0x4a8902  e8b91e0000                        call   0x4aa7c0
0x4a8907  50                                push   eax
0x4a8908  e8531f0000                        call   0x4aa860
0x4a890d  50                                push   eax
0x4a890e  e8ed1f0000                        call   0x4aa900
0x4a8913  50                                push   eax
0x4a8914  e887200000                        call   0x4aa9a0
0x4a8919  50                                push   eax
0x4a891a  e821210000                        call   0x4aaa40
0x4a891f  50                                push   eax
0x4a8920  e8bb210000                        call   0x4aaae0
0x4a8925  50                                push   eax
0x4a8926  e855220000                        call   0x4aab80
0x4a892b  50                                push   eax
0x4a892c  e8ef220000                        call   0x4aac20
0x4a8931  50                                push   eax
0x4a8932  e889230000                        call   0x4aacc0
0x4a8937  50                                push   eax
0x4a8938  e823240000                        call   0x4aad60
0x4a893d  50                                push   eax
0x4a893e  e8bd240000                        call   0x4aae00
0x4a8943  50                                push   eax
0x4a8944  e857250000                        call   0x4aaea0
0x4a8949  50                                push   eax
0x4a894a  e8f1250000                        call   0x4aaf40
0x4a894f  50                                push   eax
0x4a8950  e88b260000                        call   0x4aafe0
0x4a8955  50                                push   eax
0x4a8956  e825270000                        call   0x4ab080
0x4a895b  50                                push   eax
0x4a895c  e8bf270000                        call   0x4ab120
0x4a8961  50                                push   eax
0x4a8962  e859280000                        call   0x4ab1c0
0x4a8967  50                                push   eax
0x4a8968  e8f3280000                        call   0x4ab260
0x4a896d  50                                push   eax
0x4a896e  e88d290000                        call   0x4ab300
0x4a8973  50                                push   eax
0x4a8974  e8272a0000                        call   0x4ab3a0
0x4a8979  50                                push   eax
0x4a897a  e8c12a0000                        call   0x4ab440
0x4a897f  50                                push   eax
0x4a8980  e85b2b0000                        call   0x4ab4e0
0x4a8985  50                                push   eax
0x4a8986  e8f52b0000                        call   0x4ab580
0x4a898b  50                                push   eax
0x4a898c  e88f2c0000                        call   0x4ab620
0x4a8991  50                                push   eax
0x4a8992  e8292d0000                        call   0x4ab6c0
0x4a8997  50                                push   eax
0x4a8998  e8c32d0000                        call   0x4ab760
0x4a899d  50                                push   eax
0x4a899e  e85d2e0000                        call   0x4ab800
0x4a89a3  50                                push   eax
0x4a89a4  e8f72e0000                        call   0x4ab8a0
0x4a89a9  50                                push   eax
0x4a89aa  e8912f0000                        call   0x4ab940
0x4a89af  686468c000                        push   0xc06864
0x4a89b4  8bce                              mov    ecx,esi
0x4a89b6  e895c02400                        call   0x6f4a50
0x4a89bb  8be5                              mov    esp,ebp
0x4a89bd  5d                                pop    ebp
0x4a89be  c3                                ret

; A_I2 Lua type and numeric/string conversion
; VA 0x56a220..0x56a2fc raw 0x169620 length 220 SHA256 312edefa624d80e8bf02f8e383c616c82323c5721fbf005601373182f8bde52f
0x56a220  55                                push   ebp
0x56a221  8bec                              mov    ebp,esp
0x56a223  83ec24                            sub    esp,0x24
0x56a226  a17827fe00                        mov    eax,ds:0xfe2778
0x56a22b  53                                push   ebx
0x56a22c  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x56a22f  8b0b                              mov    ecx,DWORD PTR [ebx]
0x56a231  56                                push   esi
0x56a232  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x56a235  57                                push   edi
0x56a236  83c8ff                            or     eax,0xffffffff
0x56a239  e8b2ae1800                        call   0x6f50f0
0x56a23e  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x56a241  83f903                            cmp    ecx,0x3
0x56a244  742a                              je     0x56a270
0x56a246  83f904                            cmp    ecx,0x4
0x56a249  0f858e000000                      jne    0x56a2dd
0x56a24f  8b30                              mov    esi,DWORD PTR [eax]
0x56a251  83c610                            add    esi,0x10
0x56a254  8d7df0                            lea    edi,[ebp-0x10]
0x56a257  e804d51800                        call   0x6f7760
0x56a25c  85c0                              test   eax,eax
0x56a25e  747d                              je     0x56a2dd
0x56a260  dd45f0                            fld    QWORD PTR [ebp-0x10]
0x56a263  c745e403000000                    mov    DWORD PTR [ebp-0x1c],0x3
0x56a26a  dd5ddc                            fstp   QWORD PTR [ebp-0x24]
0x56a26d  8d45dc                            lea    eax,[ebp-0x24]
0x56a270  dd00                              fld    QWORD PTR [eax]
0x56a272  dd5df0                            fstp   QWORD PTR [ebp-0x10]
0x56a275  dd45f0                            fld    QWORD PTR [ebp-0x10]
0x56a278  db5d08                            fistp  DWORD PTR [ebp+0x8]
0x56a27b  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x56a27e  894df4                            mov    DWORD PTR [ebp-0xc],ecx
0x56a281  8b0b                              mov    ecx,DWORD PTR [ebx]
0x56a283  b8feffffff                        mov    eax,0xfffffffe
0x56a288  e863ae1800                        call   0x6f50f0
0x56a28d  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x56a290  83f903                            cmp    ecx,0x3
0x56a293  7426                              je     0x56a2bb
0x56a295  83f904                            cmp    ecx,0x4
0x56a298  754c                              jne    0x56a2e6
0x56a29a  8b30                              mov    esi,DWORD PTR [eax]
0x56a29c  83c610                            add    esi,0x10
0x56a29f  8d7df8                            lea    edi,[ebp-0x8]
0x56a2a2  e8b9d41800                        call   0x6f7760
0x56a2a7  85c0                              test   eax,eax
0x56a2a9  743b                              je     0x56a2e6
0x56a2ab  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x56a2ae  c745e403000000                    mov    DWORD PTR [ebp-0x1c],0x3
0x56a2b5  dd5ddc                            fstp   QWORD PTR [ebp-0x24]
0x56a2b8  8d45dc                            lea    eax,[ebp-0x24]
0x56a2bb  dd00                              fld    QWORD PTR [eax]
0x56a2bd  dd5de4                            fstp   QWORD PTR [ebp-0x1c]
0x56a2c0  dd45e4                            fld    QWORD PTR [ebp-0x1c]
0x56a2c3  db5dfc                            fistp  DWORD PTR [ebp-0x4]
0x56a2c6  8b55f4                            mov    edx,DWORD PTR [ebp-0xc]
0x56a2c9  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x56a2cc  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x56a2cf  52                                push   edx
0x56a2d0  50                                push   eax
0x56a2d1  ff550c                            call   DWORD PTR [ebp+0xc]
0x56a2d4  5f                                pop    edi
0x56a2d5  5e                                pop    esi
0x56a2d6  33c0                              xor    eax,eax
0x56a2d8  5b                                pop    ebx
0x56a2d9  8be5                              mov    esp,ebp
0x56a2db  5d                                pop    ebp
0x56a2dc  c3                                ret
0x56a2dd  c745f400000000                    mov    DWORD PTR [ebp-0xc],0x0
0x56a2e4  eb9b                              jmp    0x56a281
0x56a2e6  8b55f4                            mov    edx,DWORD PTR [ebp-0xc]
0x56a2e9  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x56a2ec  33c0                              xor    eax,eax
0x56a2ee  52                                push   edx
0x56a2ef  50                                push   eax
0x56a2f0  ff550c                            call   DWORD PTR [ebp+0xc]
0x56a2f3  5f                                pop    edi
0x56a2f4  5e                                pop    esi
0x56a2f5  33c0                              xor    eax,eax
0x56a2f7  5b                                pop    ebx
0x56a2f8  8be5                              mov    esp,ebp
0x56a2fa  5d                                pop    ebp
0x56a2fb  c3                                ret

; A_S1 Lua type and numeric/string conversion
; VA 0x56a300..0x56a35c raw 0x169700 length 92 SHA256 e8a138f280e4a8f428c13cbffd8b94c5f7bb524f8d340ad36763dd92e03d4e68
0x56a300  55                                push   ebp
0x56a301  8bec                              mov    ebp,esp
0x56a303  53                                push   ebx
0x56a304  8b1d7827fe00                      mov    ebx,DWORD PTR ds:0xfe2778
0x56a30a  56                                push   esi
0x56a30b  57                                push   edi
0x56a30c  8b38                              mov    edi,DWORD PTR [eax]
0x56a30e  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x56a311  83ee10                            sub    esi,0x10
0x56a314  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x56a318  7430                              je     0x56a34a
0x56a31a  e8b1121900                        call   0x6fb5d0
0x56a31f  85c0                              test   eax,eax
0x56a321  750f                              jne    0x56a332
0x56a323  33f6                              xor    esi,esi
0x56a325  56                                push   esi
0x56a326  8bcb                              mov    ecx,ebx
0x56a328  ff5508                            call   DWORD PTR [ebp+0x8]
0x56a32b  5f                                pop    edi
0x56a32c  5e                                pop    esi
0x56a32d  33c0                              xor    eax,eax
0x56a32f  5b                                pop    ebx
0x56a330  5d                                pop    ebp
0x56a331  c3                                ret
0x56a332  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x56a335  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x56a338  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x56a33b  7207                              jb     0x56a344
0x56a33d  8bc7                              mov    eax,edi
0x56a33f  e85c101900                        call   0x6fb3a0
0x56a344  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x56a347  83ee10                            sub    esi,0x10
0x56a34a  8b36                              mov    esi,DWORD PTR [esi]
0x56a34c  83c610                            add    esi,0x10
0x56a34f  56                                push   esi
0x56a350  8bcb                              mov    ecx,ebx
0x56a352  ff5508                            call   DWORD PTR [ebp+0x8]
0x56a355  5f                                pop    edi
0x56a356  5e                                pop    esi
0x56a357  33c0                              xor    eax,eax
0x56a359  5b                                pop    ebx
0x56a35a  5d                                pop    ebp
0x56a35b  c3                                ret

; A_SI Lua type and numeric/string conversion
; VA 0x56a360..0x56a424 raw 0x169760 length 196 SHA256 df1a415945713d243adcb5354986ed99164799a20953149d40d15c72ea2a58a2
0x56a360  55                                push   ebp
0x56a361  8bec                              mov    ebp,esp
0x56a363  83ec14                            sub    esp,0x14
0x56a366  a17827fe00                        mov    eax,ds:0xfe2778
0x56a36b  53                                push   ebx
0x56a36c  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x56a36f  8b0b                              mov    ecx,DWORD PTR [ebx]
0x56a371  56                                push   esi
0x56a372  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x56a375  57                                push   edi
0x56a376  83c8ff                            or     eax,0xffffffff
0x56a379  e872ad1800                        call   0x6f50f0
0x56a37e  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x56a381  83f903                            cmp    ecx,0x3
0x56a384  7426                              je     0x56a3ac
0x56a386  83f904                            cmp    ecx,0x4
0x56a389  755f                              jne    0x56a3ea
0x56a38b  8b30                              mov    esi,DWORD PTR [eax]
0x56a38d  83c610                            add    esi,0x10
0x56a390  8d7df8                            lea    edi,[ebp-0x8]
0x56a393  e8c8d31800                        call   0x6f7760
0x56a398  85c0                              test   eax,eax
0x56a39a  744e                              je     0x56a3ea
0x56a39c  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x56a39f  c745f803000000                    mov    DWORD PTR [ebp-0x8],0x3
0x56a3a6  dd5df0                            fstp   QWORD PTR [ebp-0x10]
0x56a3a9  8d45f0                            lea    eax,[ebp-0x10]
0x56a3ac  dd00                              fld    QWORD PTR [eax]
0x56a3ae  dd5df8                            fstp   QWORD PTR [ebp-0x8]
0x56a3b1  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x56a3b4  db5d08                            fistp  DWORD PTR [ebp+0x8]
0x56a3b7  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x56a3ba  894dfc                            mov    DWORD PTR [ebp-0x4],ecx
0x56a3bd  8b3b                              mov    edi,DWORD PTR [ebx]
0x56a3bf  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x56a3c2  83ee20                            sub    esi,0x20
0x56a3c5  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x56a3c9  7440                              je     0x56a40b
0x56a3cb  e800121900                        call   0x6fb5d0
0x56a3d0  85c0                              test   eax,eax
0x56a3d2  751f                              jne    0x56a3f3
0x56a3d4  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x56a3d7  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x56a3da  50                                push   eax
0x56a3db  33f6                              xor    esi,esi
0x56a3dd  56                                push   esi
0x56a3de  ff550c                            call   DWORD PTR [ebp+0xc]
0x56a3e1  5f                                pop    edi
0x56a3e2  5e                                pop    esi
0x56a3e3  33c0                              xor    eax,eax
0x56a3e5  5b                                pop    ebx
0x56a3e6  8be5                              mov    esp,ebp
0x56a3e8  5d                                pop    ebp
0x56a3e9  c3                                ret
0x56a3ea  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x56a3f1  ebca                              jmp    0x56a3bd
0x56a3f3  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x56a3f6  8b5044                            mov    edx,DWORD PTR [eax+0x44]
0x56a3f9  3b5040                            cmp    edx,DWORD PTR [eax+0x40]
0x56a3fc  7207                              jb     0x56a405
0x56a3fe  8bc7                              mov    eax,edi
0x56a400  e89b0f1900                        call   0x6fb3a0
0x56a405  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x56a408  83ee20                            sub    esi,0x20
0x56a40b  8b36                              mov    esi,DWORD PTR [esi]
0x56a40d  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x56a410  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x56a413  50                                push   eax
0x56a414  83c610                            add    esi,0x10
0x56a417  56                                push   esi
0x56a418  ff550c                            call   DWORD PTR [ebp+0xc]
0x56a41b  5f                                pop    edi
0x56a41c  5e                                pop    esi
0x56a41d  33c0                              xor    eax,eax
0x56a41f  5b                                pop    ebx
0x56a420  8be5                              mov    esp,ebp
0x56a422  5d                                pop    ebp
0x56a423  c3                                ret

; A_I1 Lua type and numeric/string conversion
; VA 0x56a430..0x56a4a3 raw 0x169830 length 115 SHA256 ed9871da5aa7b7fb1b47dd2cdb5602c38d2554a686fe84960f2c53d470fcd479
0x56a430  55                                push   ebp
0x56a431  8bec                              mov    ebp,esp
0x56a433  8b08                              mov    ecx,DWORD PTR [eax]
0x56a435  83ec18                            sub    esp,0x18
0x56a438  53                                push   ebx
0x56a439  8b1d7827fe00                      mov    ebx,DWORD PTR ds:0xfe2778
0x56a43f  83c8ff                            or     eax,0xffffffff
0x56a442  e8a9ac1800                        call   0x6f50f0
0x56a447  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x56a44a  83f903                            cmp    ecx,0x3
0x56a44d  742a                              je     0x56a479
0x56a44f  83f904                            cmp    ecx,0x4
0x56a452  7540                              jne    0x56a494
0x56a454  56                                push   esi
0x56a455  8b30                              mov    esi,DWORD PTR [eax]
0x56a457  57                                push   edi
0x56a458  83c610                            add    esi,0x10
0x56a45b  8d7df8                            lea    edi,[ebp-0x8]
0x56a45e  e8fdd21800                        call   0x6f7760
0x56a463  5f                                pop    edi
0x56a464  5e                                pop    esi
0x56a465  85c0                              test   eax,eax
0x56a467  742b                              je     0x56a494
0x56a469  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x56a46c  c745f003000000                    mov    DWORD PTR [ebp-0x10],0x3
0x56a473  dd5de8                            fstp   QWORD PTR [ebp-0x18]
0x56a476  8d45e8                            lea    eax,[ebp-0x18]
0x56a479  dd00                              fld    QWORD PTR [eax]
0x56a47b  dd5df0                            fstp   QWORD PTR [ebp-0x10]
0x56a47e  dd45f0                            fld    QWORD PTR [ebp-0x10]
0x56a481  db5dfc                            fistp  DWORD PTR [ebp-0x4]
0x56a484  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x56a487  50                                push   eax
0x56a488  8bcb                              mov    ecx,ebx
0x56a48a  ff5508                            call   DWORD PTR [ebp+0x8]
0x56a48d  33c0                              xor    eax,eax
0x56a48f  5b                                pop    ebx
0x56a490  8be5                              mov    esp,ebp
0x56a492  5d                                pop    ebp
0x56a493  c3                                ret
0x56a494  33c0                              xor    eax,eax
0x56a496  50                                push   eax
0x56a497  8bcb                              mov    ecx,ebx
0x56a499  ff5508                            call   DWORD PTR [ebp+0x8]
0x56a49c  33c0                              xor    eax,eax
0x56a49e  5b                                pop    ebx
0x56a49f  8be5                              mov    esp,ebp
0x56a4a1  5d                                pop    ebp
0x56a4a2  c3                                ret

; A_I3 Lua type and numeric/string conversion
; VA 0x56a4b0..0x56a5e1 raw 0x1698b0 length 305 SHA256 b604bb686dc70f9c2ef96307b3666383c336f21670977c7e60d40b817f0ec1e3
0x56a4b0  55                                push   ebp
0x56a4b1  8bec                              mov    ebp,esp
0x56a4b3  83ec2c                            sub    esp,0x2c
0x56a4b6  a17827fe00                        mov    eax,ds:0xfe2778
0x56a4bb  53                                push   ebx
0x56a4bc  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x56a4bf  8b0b                              mov    ecx,DWORD PTR [ebx]
0x56a4c1  56                                push   esi
0x56a4c2  8945e4                            mov    DWORD PTR [ebp-0x1c],eax
0x56a4c5  57                                push   edi
0x56a4c6  83c8ff                            or     eax,0xffffffff
0x56a4c9  e822ac1800                        call   0x6f50f0
0x56a4ce  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x56a4d1  83f903                            cmp    ecx,0x3
0x56a4d4  742e                              je     0x56a504
0x56a4d6  83f904                            cmp    ecx,0x4
0x56a4d9  0f85e9000000                      jne    0x56a5c8
0x56a4df  8b30                              mov    esi,DWORD PTR [eax]
0x56a4e1  83c610                            add    esi,0x10
0x56a4e4  8d7de8                            lea    edi,[ebp-0x18]
0x56a4e7  e874d21800                        call   0x6f7760
0x56a4ec  85c0                              test   eax,eax
0x56a4ee  0f84d4000000                      je     0x56a5c8
0x56a4f4  dd45e8                            fld    QWORD PTR [ebp-0x18]
0x56a4f7  c745dc03000000                    mov    DWORD PTR [ebp-0x24],0x3
0x56a4fe  dd5dd4                            fstp   QWORD PTR [ebp-0x2c]
0x56a501  8d45d4                            lea    eax,[ebp-0x2c]
0x56a504  dd00                              fld    QWORD PTR [eax]
0x56a506  dd5de8                            fstp   QWORD PTR [ebp-0x18]
0x56a509  dd45e8                            fld    QWORD PTR [ebp-0x18]
0x56a50c  db5d08                            fistp  DWORD PTR [ebp+0x8]
0x56a50f  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x56a512  894df0                            mov    DWORD PTR [ebp-0x10],ecx
0x56a515  8b0b                              mov    ecx,DWORD PTR [ebx]
0x56a517  b8feffffff                        mov    eax,0xfffffffe
0x56a51c  e8cfab1800                        call   0x6f50f0
0x56a521  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x56a524  83f903                            cmp    ecx,0x3
0x56a527  742e                              je     0x56a557
0x56a529  83f904                            cmp    ecx,0x4
0x56a52c  0f85a2000000                      jne    0x56a5d4
0x56a532  8b30                              mov    esi,DWORD PTR [eax]
0x56a534  83c610                            add    esi,0x10
0x56a537  8d7de8                            lea    edi,[ebp-0x18]
0x56a53a  e821d21800                        call   0x6f7760
0x56a53f  85c0                              test   eax,eax
0x56a541  0f848d000000                      je     0x56a5d4
0x56a547  dd45e8                            fld    QWORD PTR [ebp-0x18]
0x56a54a  c745dc03000000                    mov    DWORD PTR [ebp-0x24],0x3
0x56a551  dd5dd4                            fstp   QWORD PTR [ebp-0x2c]
0x56a554  8d45d4                            lea    eax,[ebp-0x2c]
0x56a557  dd00                              fld    QWORD PTR [eax]
0x56a559  dd5de8                            fstp   QWORD PTR [ebp-0x18]
0x56a55c  dd45e8                            fld    QWORD PTR [ebp-0x18]
0x56a55f  db5dfc                            fistp  DWORD PTR [ebp-0x4]
0x56a562  8b55fc                            mov    edx,DWORD PTR [ebp-0x4]
0x56a565  8955ec                            mov    DWORD PTR [ebp-0x14],edx
0x56a568  8b0b                              mov    ecx,DWORD PTR [ebx]
0x56a56a  b8fdffffff                        mov    eax,0xfffffffd
0x56a56f  e87cab1800                        call   0x6f50f0
0x56a574  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x56a577  83f903                            cmp    ecx,0x3
0x56a57a  7426                              je     0x56a5a2
0x56a57c  83f904                            cmp    ecx,0x4
0x56a57f  755c                              jne    0x56a5dd
0x56a581  8b30                              mov    esi,DWORD PTR [eax]
0x56a583  83c610                            add    esi,0x10
0x56a586  8d7df4                            lea    edi,[ebp-0xc]
0x56a589  e8d2d11800                        call   0x6f7760
0x56a58e  85c0                              test   eax,eax
0x56a590  744b                              je     0x56a5dd
0x56a592  dd45f4                            fld    QWORD PTR [ebp-0xc]
0x56a595  c745dc03000000                    mov    DWORD PTR [ebp-0x24],0x3
0x56a59c  dd5dd4                            fstp   QWORD PTR [ebp-0x2c]
0x56a59f  8d45d4                            lea    eax,[ebp-0x2c]
0x56a5a2  dd00                              fld    QWORD PTR [eax]
0x56a5a4  dd5ddc                            fstp   QWORD PTR [ebp-0x24]
0x56a5a7  dd45dc                            fld    QWORD PTR [ebp-0x24]
0x56a5aa  db5df8                            fistp  DWORD PTR [ebp-0x8]
0x56a5ad  8b45f8                            mov    eax,DWORD PTR [ebp-0x8]
0x56a5b0  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x56a5b3  8b55ec                            mov    edx,DWORD PTR [ebp-0x14]
0x56a5b6  51                                push   ecx
0x56a5b7  8b4de4                            mov    ecx,DWORD PTR [ebp-0x1c]
0x56a5ba  52                                push   edx
0x56a5bb  50                                push   eax
0x56a5bc  ff550c                            call   DWORD PTR [ebp+0xc]
0x56a5bf  5f                                pop    edi
0x56a5c0  5e                                pop    esi
0x56a5c1  33c0                              xor    eax,eax
0x56a5c3  5b                                pop    ebx
0x56a5c4  8be5                              mov    esp,ebp
0x56a5c6  5d                                pop    ebp
0x56a5c7  c3                                ret
0x56a5c8  c745f000000000                    mov    DWORD PTR [ebp-0x10],0x0
0x56a5cf  e941ffffff                        jmp    0x56a515
0x56a5d4  c745ec00000000                    mov    DWORD PTR [ebp-0x14],0x0
0x56a5db  eb8b                              jmp    0x56a568
0x56a5dd  33c0                              xor    eax,eax
0x56a5df  ebcf                              jmp    0x56a5b0

; A_F3 Lua type and numeric/string conversion
; VA 0x56a5f0..0x56a706 raw 0x1699f0 length 278 SHA256 dfdb31ae414d2909b0ea07b3d65364f0d7db2d59ff94b17ab55af3ec73321ec6
0x56a5f0  55                                push   ebp
0x56a5f1  8bec                              mov    ebp,esp
0x56a5f3  83ec24                            sub    esp,0x24
0x56a5f6  a17827fe00                        mov    eax,ds:0xfe2778
0x56a5fb  53                                push   ebx
0x56a5fc  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x56a5ff  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x56a602  8b03                              mov    eax,DWORD PTR [ebx]
0x56a604  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x56a607  8b48f8                            mov    ecx,DWORD PTR [eax-0x8]
0x56a60a  83e810                            sub    eax,0x10
0x56a60d  56                                push   esi
0x56a60e  57                                push   edi
0x56a60f  83f903                            cmp    ecx,0x3
0x56a612  742e                              je     0x56a642
0x56a614  83f904                            cmp    ecx,0x4
0x56a617  0f85da000000                      jne    0x56a6f7
0x56a61d  8b30                              mov    esi,DWORD PTR [eax]
0x56a61f  83c610                            add    esi,0x10
0x56a622  8d7dec                            lea    edi,[ebp-0x14]
0x56a625  e836d11800                        call   0x6f7760
0x56a62a  85c0                              test   eax,eax
0x56a62c  0f84c5000000                      je     0x56a6f7
0x56a632  dd45ec                            fld    QWORD PTR [ebp-0x14]
0x56a635  c745e403000000                    mov    DWORD PTR [ebp-0x1c],0x3
0x56a63c  dd5ddc                            fstp   QWORD PTR [ebp-0x24]
0x56a63f  8d45dc                            lea    eax,[ebp-0x24]
0x56a642  dd00                              fld    QWORD PTR [eax]
0x56a644  8b03                              mov    eax,DWORD PTR [ebx]
0x56a646  dd5df4                            fstp   QWORD PTR [ebp-0xc]
0x56a649  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x56a64c  8b48e8                            mov    ecx,DWORD PTR [eax-0x18]
0x56a64f  83e820                            sub    eax,0x20
0x56a652  83f903                            cmp    ecx,0x3
0x56a655  742e                              je     0x56a685
0x56a657  83f904                            cmp    ecx,0x4
0x56a65a  0f859e000000                      jne    0x56a6fe
0x56a660  8b30                              mov    esi,DWORD PTR [eax]
0x56a662  83c610                            add    esi,0x10
0x56a665  8d7dec                            lea    edi,[ebp-0x14]
0x56a668  e8f3d01800                        call   0x6f7760
0x56a66d  85c0                              test   eax,eax
0x56a66f  0f8489000000                      je     0x56a6fe
0x56a675  dd45ec                            fld    QWORD PTR [ebp-0x14]
0x56a678  c745e403000000                    mov    DWORD PTR [ebp-0x1c],0x3
0x56a67f  dd5ddc                            fstp   QWORD PTR [ebp-0x24]
0x56a682  8d45dc                            lea    eax,[ebp-0x24]
0x56a685  dd00                              fld    QWORD PTR [eax]
0x56a687  8b1b                              mov    ebx,DWORD PTR [ebx]
0x56a689  dd5dec                            fstp   QWORD PTR [ebp-0x14]
0x56a68c  8b4308                            mov    eax,DWORD PTR [ebx+0x8]
0x56a68f  8b48d8                            mov    ecx,DWORD PTR [eax-0x28]
0x56a692  83e830                            sub    eax,0x30
0x56a695  83f903                            cmp    ecx,0x3
0x56a698  7426                              je     0x56a6c0
0x56a69a  83f904                            cmp    ecx,0x4
0x56a69d  7563                              jne    0x56a702
0x56a69f  8b30                              mov    esi,DWORD PTR [eax]
0x56a6a1  83c610                            add    esi,0x10
0x56a6a4  8d7de4                            lea    edi,[ebp-0x1c]
0x56a6a7  e8b4d01800                        call   0x6f7760
0x56a6ac  85c0                              test   eax,eax
0x56a6ae  7452                              je     0x56a702
0x56a6b0  dd45e4                            fld    QWORD PTR [ebp-0x1c]
0x56a6b3  c745e403000000                    mov    DWORD PTR [ebp-0x1c],0x3
0x56a6ba  dd5ddc                            fstp   QWORD PTR [ebp-0x24]
0x56a6bd  8d45dc                            lea    eax,[ebp-0x24]
0x56a6c0  dd00                              fld    QWORD PTR [eax]
0x56a6c2  dd45f4                            fld    QWORD PTR [ebp-0xc]
0x56a6c5  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x56a6c8  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x56a6cb  83ec0c                            sub    esp,0xc
0x56a6ce  d94508                            fld    DWORD PTR [ebp+0x8]
0x56a6d1  d95c2408                          fstp   DWORD PTR [esp+0x8]
0x56a6d5  dd45ec                            fld    QWORD PTR [ebp-0x14]
0x56a6d8  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x56a6db  d94508                            fld    DWORD PTR [ebp+0x8]
0x56a6de  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x56a6e2  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x56a6e5  d94508                            fld    DWORD PTR [ebp+0x8]
0x56a6e8  d91c24                            fstp   DWORD PTR [esp]
0x56a6eb  ff550c                            call   DWORD PTR [ebp+0xc]
0x56a6ee  5f                                pop    edi
0x56a6ef  5e                                pop    esi
0x56a6f0  33c0                              xor    eax,eax
0x56a6f2  5b                                pop    ebx
0x56a6f3  8be5                              mov    esp,ebp
0x56a6f5  5d                                pop    ebp
0x56a6f6  c3                                ret
0x56a6f7  d9ee                              fldz
0x56a6f9  e946ffffff                        jmp    0x56a644
0x56a6fe  d9ee                              fldz
0x56a700  eb85                              jmp    0x56a687
0x56a702  d9ee                              fldz
0x56a704  ebbc                              jmp    0x56a6c2

; A_COLOR Lua type and numeric/string conversion
; VA 0x56b630..0x56b68a raw 0x16aa30 length 90 SHA256 a6a5aebd00d69b10de2c0cdfc96f9bea758e22225fe5beef58df261622593612
0x56b630  55                                push   ebp
0x56b631  8bec                              mov    ebp,esp
0x56b633  8b08                              mov    ecx,DWORD PTR [eax]
0x56b635  83ec18                            sub    esp,0x18
0x56b638  83c8ff                            or     eax,0xffffffff
0x56b63b  e8b09a1800                        call   0x6f50f0
0x56b640  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x56b643  83f903                            cmp    ecx,0x3
0x56b646  742a                              je     0x56b672
0x56b648  83f904                            cmp    ecx,0x4
0x56b64b  7537                              jne    0x56b684
0x56b64d  56                                push   esi
0x56b64e  8b30                              mov    esi,DWORD PTR [eax]
0x56b650  57                                push   edi
0x56b651  83c610                            add    esi,0x10
0x56b654  8d7df8                            lea    edi,[ebp-0x8]
0x56b657  e804c11800                        call   0x6f7760
0x56b65c  5f                                pop    edi
0x56b65d  5e                                pop    esi
0x56b65e  85c0                              test   eax,eax
0x56b660  7422                              je     0x56b684
0x56b662  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x56b665  c745f003000000                    mov    DWORD PTR [ebp-0x10],0x3
0x56b66c  dd5de8                            fstp   QWORD PTR [ebp-0x18]
0x56b66f  8d45e8                            lea    eax,[ebp-0x18]
0x56b672  dd00                              fld    QWORD PTR [eax]
0x56b674  dd5df0                            fstp   QWORD PTR [ebp-0x10]
0x56b677  dd45f0                            fld    QWORD PTR [ebp-0x10]
0x56b67a  db5dfc                            fistp  DWORD PTR [ebp-0x4]
0x56b67d  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x56b680  8be5                              mov    esp,ebp
0x56b682  5d                                pop    ebp
0x56b683  c3                                ret
0x56b684  33c0                              xor    eax,eax
0x56b686  8be5                              mov    esp,ebp
0x56b688  5d                                pop    ebp
0x56b689  c3                                ret

; A_CW_S Lua type and numeric/string conversion
; VA 0x54f030..0x54f099 raw 0x14e430 length 105 SHA256 e3d0c6bb5600241e8c2f5adb8b73b340be89327d6318a4c2f85a7cf0a729792e
0x54f030  55                                push   ebp
0x54f031  8bec                              mov    ebp,esp
0x54f033  51                                push   ecx
0x54f034  a1281efe00                        mov    eax,ds:0xfe1e28
0x54f039  53                                push   ebx
0x54f03a  8b1d2c1efe00                      mov    ebx,DWORD PTR ds:0xfe1e2c
0x54f040  56                                push   esi
0x54f041  57                                push   edi
0x54f042  8b39                              mov    edi,DWORD PTR [ecx]
0x54f044  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x54f047  83ee10                            sub    esi,0x10
0x54f04a  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x54f04e  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x54f051  7432                              je     0x54f085
0x54f053  e878c51a00                        call   0x6fb5d0
0x54f058  85c0                              test   eax,eax
0x54f05a  7511                              jne    0x54f06d
0x54f05c  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x54f05f  33f6                              xor    esi,esi
0x54f061  56                                push   esi
0x54f062  ffd3                              call   ebx
0x54f064  5f                                pop    edi
0x54f065  5e                                pop    esi
0x54f066  33c0                              xor    eax,eax
0x54f068  5b                                pop    ebx
0x54f069  8be5                              mov    esp,ebp
0x54f06b  5d                                pop    ebp
0x54f06c  c3                                ret
0x54f06d  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x54f070  8b5044                            mov    edx,DWORD PTR [eax+0x44]
0x54f073  3b5040                            cmp    edx,DWORD PTR [eax+0x40]
0x54f076  7207                              jb     0x54f07f
0x54f078  8bc7                              mov    eax,edi
0x54f07a  e821c31a00                        call   0x6fb3a0
0x54f07f  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x54f082  83ee10                            sub    esi,0x10
0x54f085  8b36                              mov    esi,DWORD PTR [esi]
0x54f087  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x54f08a  83c610                            add    esi,0x10
0x54f08d  56                                push   esi
0x54f08e  ffd3                              call   ebx
0x54f090  5f                                pop    edi
0x54f091  5e                                pop    esi
0x54f092  33c0                              xor    eax,eax
0x54f094  5b                                pop    ebx
0x54f095  8be5                              mov    esp,ebp
0x54f097  5d                                pop    ebp
0x54f098  c3                                ret

; A_CW_SFFF Lua type and numeric/string conversion
; VA 0x54f0a0..0x54f1fa raw 0x14e4a0 length 346 SHA256 0637c451c8a8fce2502d5cf73a54a949b5778b2e05e86c3e4e3982f19ba4a2a2
0x54f0a0  55                                push   ebp
0x54f0a1  8bec                              mov    ebp,esp
0x54f0a3  83ec28                            sub    esp,0x28
0x54f0a6  a1301efe00                        mov    eax,ds:0xfe1e30
0x54f0ab  8b0d281efe00                      mov    ecx,DWORD PTR ds:0xfe1e28
0x54f0b1  53                                push   ebx
0x54f0b2  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x54f0b5  8945f8                            mov    DWORD PTR [ebp-0x8],eax
0x54f0b8  8b03                              mov    eax,DWORD PTR [ebx]
0x54f0ba  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54f0bd  83e810                            sub    eax,0x10
0x54f0c0  894dfc                            mov    DWORD PTR [ebp-0x4],ecx
0x54f0c3  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x54f0c6  56                                push   esi
0x54f0c7  57                                push   edi
0x54f0c8  83f903                            cmp    ecx,0x3
0x54f0cb  742e                              je     0x54f0fb
0x54f0cd  83f904                            cmp    ecx,0x4
0x54f0d0  0f85bf000000                      jne    0x54f195
0x54f0d6  8b30                              mov    esi,DWORD PTR [eax]
0x54f0d8  83c610                            add    esi,0x10
0x54f0db  8d7de0                            lea    edi,[ebp-0x20]
0x54f0de  e87d861a00                        call   0x6f7760
0x54f0e3  85c0                              test   eax,eax
0x54f0e5  0f84aa000000                      je     0x54f195
0x54f0eb  dd45e0                            fld    QWORD PTR [ebp-0x20]
0x54f0ee  c745e003000000                    mov    DWORD PTR [ebp-0x20],0x3
0x54f0f5  dd5dd8                            fstp   QWORD PTR [ebp-0x28]
0x54f0f8  8d45d8                            lea    eax,[ebp-0x28]
0x54f0fb  dd00                              fld    QWORD PTR [eax]
0x54f0fd  8b03                              mov    eax,DWORD PTR [ebx]
0x54f0ff  dd5df0                            fstp   QWORD PTR [ebp-0x10]
0x54f102  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54f105  8b48e8                            mov    ecx,DWORD PTR [eax-0x18]
0x54f108  83e820                            sub    eax,0x20
0x54f10b  83f903                            cmp    ecx,0x3
0x54f10e  742a                              je     0x54f13a
0x54f110  83f904                            cmp    ecx,0x4
0x54f113  0f8583000000                      jne    0x54f19c
0x54f119  8b30                              mov    esi,DWORD PTR [eax]
0x54f11b  83c610                            add    esi,0x10
0x54f11e  8d7de0                            lea    edi,[ebp-0x20]
0x54f121  e83a861a00                        call   0x6f7760
0x54f126  85c0                              test   eax,eax
0x54f128  7472                              je     0x54f19c
0x54f12a  dd45e0                            fld    QWORD PTR [ebp-0x20]
0x54f12d  c745e003000000                    mov    DWORD PTR [ebp-0x20],0x3
0x54f134  dd5dd8                            fstp   QWORD PTR [ebp-0x28]
0x54f137  8d45d8                            lea    eax,[ebp-0x28]
0x54f13a  dd00                              fld    QWORD PTR [eax]
0x54f13c  8b03                              mov    eax,DWORD PTR [ebx]
0x54f13e  dd5de8                            fstp   QWORD PTR [ebp-0x18]
0x54f141  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54f144  8b48d8                            mov    ecx,DWORD PTR [eax-0x28]
0x54f147  83e830                            sub    eax,0x30
0x54f14a  83f903                            cmp    ecx,0x3
0x54f14d  7426                              je     0x54f175
0x54f14f  83f904                            cmp    ecx,0x4
0x54f152  754c                              jne    0x54f1a0
0x54f154  8b30                              mov    esi,DWORD PTR [eax]
0x54f156  83c610                            add    esi,0x10
0x54f159  8d7de0                            lea    edi,[ebp-0x20]
0x54f15c  e8ff851a00                        call   0x6f7760
0x54f161  85c0                              test   eax,eax
0x54f163  743b                              je     0x54f1a0
0x54f165  dd45e0                            fld    QWORD PTR [ebp-0x20]
0x54f168  c745e003000000                    mov    DWORD PTR [ebp-0x20],0x3
0x54f16f  dd5dd8                            fstp   QWORD PTR [ebp-0x28]
0x54f172  8d45d8                            lea    eax,[ebp-0x28]
0x54f175  dd00                              fld    QWORD PTR [eax]
0x54f177  8b3b                              mov    edi,DWORD PTR [ebx]
0x54f179  dd5de0                            fstp   QWORD PTR [ebp-0x20]
0x54f17c  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x54f17f  83ee40                            sub    esi,0x40
0x54f182  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x54f186  7434                              je     0x54f1bc
0x54f188  e843c41a00                        call   0x6fb5d0
0x54f18d  85c0                              test   eax,eax
0x54f18f  7513                              jne    0x54f1a4
0x54f191  33f6                              xor    esi,esi
0x54f193  eb2c                              jmp    0x54f1c1
0x54f195  d9ee                              fldz
0x54f197  e961ffffff                        jmp    0x54f0fd
0x54f19c  d9ee                              fldz
0x54f19e  eb9c                              jmp    0x54f13c
0x54f1a0  d9ee                              fldz
0x54f1a2  ebd3                              jmp    0x54f177
0x54f1a4  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x54f1a7  8b5044                            mov    edx,DWORD PTR [eax+0x44]
0x54f1aa  3b5040                            cmp    edx,DWORD PTR [eax+0x40]
0x54f1ad  7207                              jb     0x54f1b6
0x54f1af  8bc7                              mov    eax,edi
0x54f1b1  e8eac11a00                        call   0x6fb3a0
0x54f1b6  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x54f1b9  83ee40                            sub    esi,0x40
0x54f1bc  8b36                              mov    esi,DWORD PTR [esi]
0x54f1be  83c610                            add    esi,0x10
0x54f1c1  dd45f0                            fld    QWORD PTR [ebp-0x10]
0x54f1c4  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x54f1c7  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x54f1ca  83ec0c                            sub    esp,0xc
0x54f1cd  d94508                            fld    DWORD PTR [ebp+0x8]
0x54f1d0  d95c2408                          fstp   DWORD PTR [esp+0x8]
0x54f1d4  dd45e8                            fld    QWORD PTR [ebp-0x18]
0x54f1d7  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x54f1da  d94508                            fld    DWORD PTR [ebp+0x8]
0x54f1dd  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x54f1e1  dd45e0                            fld    QWORD PTR [ebp-0x20]
0x54f1e4  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x54f1e7  d94508                            fld    DWORD PTR [ebp+0x8]
0x54f1ea  d91c24                            fstp   DWORD PTR [esp]
0x54f1ed  56                                push   esi
0x54f1ee  ff55f8                            call   DWORD PTR [ebp-0x8]
0x54f1f1  5f                                pop    edi
0x54f1f2  5e                                pop    esi
0x54f1f3  33c0                              xor    eax,eax
0x54f1f5  5b                                pop    ebx
0x54f1f6  8be5                              mov    esp,ebp
0x54f1f8  5d                                pop    ebp
0x54f1f9  c3                                ret

; A_TUT_SI Lua type and numeric/string conversion
; VA 0x4acaa0..0x4acb6d raw 0xabea0 length 205 SHA256 1c76692817a6eccb7610d63fcd9438604273b2d99b2aaeb9662ebbb815fb7cdc
0x4acaa0  55                                push   ebp
0x4acaa1  8bec                              mov    ebp,esp
0x4acaa3  83ec18                            sub    esp,0x18
0x4acaa6  a10c18fe00                        mov    eax,ds:0xfe180c
0x4acaab  8b0d0418fe00                      mov    ecx,DWORD PTR ds:0xfe1804
0x4acab1  53                                push   ebx
0x4acab2  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x4acab5  56                                push   esi
0x4acab6  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x4acab9  894dec                            mov    DWORD PTR [ebp-0x14],ecx
0x4acabc  8b0b                              mov    ecx,DWORD PTR [ebx]
0x4acabe  57                                push   edi
0x4acabf  83c8ff                            or     eax,0xffffffff
0x4acac2  e829862400                        call   0x6f50f0
0x4acac7  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x4acaca  83f903                            cmp    ecx,0x3
0x4acacd  7426                              je     0x4acaf5
0x4acacf  83f904                            cmp    ecx,0x4
0x4acad2  755f                              jne    0x4acb33
0x4acad4  8b30                              mov    esi,DWORD PTR [eax]
0x4acad6  83c610                            add    esi,0x10
0x4acad9  8d7df8                            lea    edi,[ebp-0x8]
0x4acadc  e87fac2400                        call   0x6f7760
0x4acae1  85c0                              test   eax,eax
0x4acae3  744e                              je     0x4acb33
0x4acae5  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x4acae8  c745f803000000                    mov    DWORD PTR [ebp-0x8],0x3
0x4acaef  dd5df0                            fstp   QWORD PTR [ebp-0x10]
0x4acaf2  8d45f0                            lea    eax,[ebp-0x10]
0x4acaf5  dd00                              fld    QWORD PTR [eax]
0x4acaf7  dd5df8                            fstp   QWORD PTR [ebp-0x8]
0x4acafa  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x4acafd  db5d08                            fistp  DWORD PTR [ebp+0x8]
0x4acb00  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x4acb03  8955fc                            mov    DWORD PTR [ebp-0x4],edx
0x4acb06  8b3b                              mov    edi,DWORD PTR [ebx]
0x4acb08  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x4acb0b  83ee20                            sub    esi,0x20
0x4acb0e  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x4acb12  7440                              je     0x4acb54
0x4acb14  e8b7ea2400                        call   0x6fb5d0
0x4acb19  85c0                              test   eax,eax
0x4acb1b  751f                              jne    0x4acb3c
0x4acb1d  8b55fc                            mov    edx,DWORD PTR [ebp-0x4]
0x4acb20  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x4acb23  52                                push   edx
0x4acb24  33f6                              xor    esi,esi
0x4acb26  56                                push   esi
0x4acb27  ff55e8                            call   DWORD PTR [ebp-0x18]
0x4acb2a  5f                                pop    edi
0x4acb2b  5e                                pop    esi
0x4acb2c  33c0                              xor    eax,eax
0x4acb2e  5b                                pop    ebx
0x4acb2f  8be5                              mov    esp,ebp
0x4acb31  5d                                pop    ebp
0x4acb32  c3                                ret
0x4acb33  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4acb3a  ebca                              jmp    0x4acb06
0x4acb3c  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x4acb3f  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x4acb42  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x4acb45  7207                              jb     0x4acb4e
0x4acb47  8bc7                              mov    eax,edi
0x4acb49  e852e82400                        call   0x6fb3a0
0x4acb4e  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x4acb51  83ee20                            sub    esi,0x20
0x4acb54  8b36                              mov    esi,DWORD PTR [esi]
0x4acb56  8b55fc                            mov    edx,DWORD PTR [ebp-0x4]
0x4acb59  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x4acb5c  52                                push   edx
0x4acb5d  83c610                            add    esi,0x10
0x4acb60  56                                push   esi
0x4acb61  ff55e8                            call   DWORD PTR [ebp-0x18]
0x4acb64  5f                                pop    edi
0x4acb65  5e                                pop    esi
0x4acb66  33c0                              xor    eax,eax
0x4acb68  5b                                pop    ebx
0x4acb69  8be5                              mov    esp,ebp
0x4acb6b  5d                                pop    ebp
0x4acb6c  c3                                ret

; A_TUT_S Lua type and numeric/string conversion
; VA 0x4acd30..0x4acd8c raw 0xac130 length 92 SHA256 5063eb847628214773abbe1e8b3d8ed88eef46df5ee854c2aa03d3d953ed0f67
0x4acd30  55                                push   ebp
0x4acd31  8bec                              mov    ebp,esp
0x4acd33  53                                push   ebx
0x4acd34  8b1d0418fe00                      mov    ebx,DWORD PTR ds:0xfe1804
0x4acd3a  56                                push   esi
0x4acd3b  57                                push   edi
0x4acd3c  8b38                              mov    edi,DWORD PTR [eax]
0x4acd3e  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x4acd41  83ee10                            sub    esi,0x10
0x4acd44  837e0804                          cmp    DWORD PTR [esi+0x8],0x4
0x4acd48  7430                              je     0x4acd7a
0x4acd4a  e881e82400                        call   0x6fb5d0
0x4acd4f  85c0                              test   eax,eax
0x4acd51  750f                              jne    0x4acd62
0x4acd53  33f6                              xor    esi,esi
0x4acd55  56                                push   esi
0x4acd56  8bcb                              mov    ecx,ebx
0x4acd58  ff5508                            call   DWORD PTR [ebp+0x8]
0x4acd5b  5f                                pop    edi
0x4acd5c  5e                                pop    esi
0x4acd5d  33c0                              xor    eax,eax
0x4acd5f  5b                                pop    ebx
0x4acd60  5d                                pop    ebp
0x4acd61  c3                                ret
0x4acd62  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x4acd65  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x4acd68  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x4acd6b  7207                              jb     0x4acd74
0x4acd6d  8bc7                              mov    eax,edi
0x4acd6f  e82ce62400                        call   0x6fb3a0
0x4acd74  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x4acd77  83ee10                            sub    esi,0x10
0x4acd7a  8b36                              mov    esi,DWORD PTR [esi]
0x4acd7c  83c610                            add    esi,0x10
0x4acd7f  56                                push   esi
0x4acd80  8bcb                              mov    ecx,ebx
0x4acd82  ff5508                            call   DWORD PTR [ebp+0x8]
0x4acd85  5f                                pop    edi
0x4acd86  5e                                pop    esi
0x4acd87  33c0                              xor    eax,eax
0x4acd89  5b                                pop    ebx
0x4acd8a  5d                                pop    ebp
0x4acd8b  c3                                ret

; A_FADE_I2 Lua type and numeric/string conversion
; VA 0x55eb50..0x55ec35 raw 0x15df50 length 229 SHA256 df7219ed9a2643863735764d3f64be290280b009400d8fb2c2364b8e395c05d7
0x55eb50  55                                push   ebp
0x55eb51  8bec                              mov    ebp,esp
0x55eb53  83ec28                            sub    esp,0x28
0x55eb56  a1341ffe00                        mov    eax,ds:0xfe1f34
0x55eb5b  8b0d301ffe00                      mov    ecx,DWORD PTR ds:0xfe1f30
0x55eb61  53                                push   ebx
0x55eb62  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x55eb65  56                                push   esi
0x55eb66  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x55eb69  894dec                            mov    DWORD PTR [ebp-0x14],ecx
0x55eb6c  8b0b                              mov    ecx,DWORD PTR [ebx]
0x55eb6e  57                                push   edi
0x55eb6f  83c8ff                            or     eax,0xffffffff
0x55eb72  e879651900                        call   0x6f50f0
0x55eb77  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x55eb7a  83f903                            cmp    ecx,0x3
0x55eb7d  742a                              je     0x55eba9
0x55eb7f  83f904                            cmp    ecx,0x4
0x55eb82  0f858e000000                      jne    0x55ec16
0x55eb88  8b30                              mov    esi,DWORD PTR [eax]
0x55eb8a  83c610                            add    esi,0x10
0x55eb8d  8d7df0                            lea    edi,[ebp-0x10]
0x55eb90  e8cb8b1900                        call   0x6f7760
0x55eb95  85c0                              test   eax,eax
0x55eb97  747d                              je     0x55ec16
0x55eb99  dd45f0                            fld    QWORD PTR [ebp-0x10]
0x55eb9c  c745e003000000                    mov    DWORD PTR [ebp-0x20],0x3
0x55eba3  dd5dd8                            fstp   QWORD PTR [ebp-0x28]
0x55eba6  8d45d8                            lea    eax,[ebp-0x28]
0x55eba9  dd00                              fld    QWORD PTR [eax]
0x55ebab  dd5df0                            fstp   QWORD PTR [ebp-0x10]
0x55ebae  dd45f0                            fld    QWORD PTR [ebp-0x10]
0x55ebb1  db5d08                            fistp  DWORD PTR [ebp+0x8]
0x55ebb4  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x55ebb7  8955f4                            mov    DWORD PTR [ebp-0xc],edx
0x55ebba  8b0b                              mov    ecx,DWORD PTR [ebx]
0x55ebbc  b8feffffff                        mov    eax,0xfffffffe
0x55ebc1  e82a651900                        call   0x6f50f0
0x55ebc6  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x55ebc9  83f903                            cmp    ecx,0x3
0x55ebcc  7426                              je     0x55ebf4
0x55ebce  83f904                            cmp    ecx,0x4
0x55ebd1  754c                              jne    0x55ec1f
0x55ebd3  8b30                              mov    esi,DWORD PTR [eax]
0x55ebd5  83c610                            add    esi,0x10
0x55ebd8  8d7df8                            lea    edi,[ebp-0x8]
0x55ebdb  e8808b1900                        call   0x6f7760
0x55ebe0  85c0                              test   eax,eax
0x55ebe2  743b                              je     0x55ec1f
0x55ebe4  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x55ebe7  c745e003000000                    mov    DWORD PTR [ebp-0x20],0x3
0x55ebee  dd5dd8                            fstp   QWORD PTR [ebp-0x28]
0x55ebf1  8d45d8                            lea    eax,[ebp-0x28]
0x55ebf4  dd00                              fld    QWORD PTR [eax]
0x55ebf6  dd5de0                            fstp   QWORD PTR [ebp-0x20]
0x55ebf9  dd45e0                            fld    QWORD PTR [ebp-0x20]
0x55ebfc  db5dfc                            fistp  DWORD PTR [ebp-0x4]
0x55ebff  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x55ec02  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x55ec05  51                                push   ecx
0x55ec06  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x55ec09  50                                push   eax
0x55ec0a  ff55e8                            call   DWORD PTR [ebp-0x18]
0x55ec0d  5f                                pop    edi
0x55ec0e  5e                                pop    esi
0x55ec0f  33c0                              xor    eax,eax
0x55ec11  5b                                pop    ebx
0x55ec12  8be5                              mov    esp,ebp
0x55ec14  5d                                pop    ebp
0x55ec15  c3                                ret
0x55ec16  c745f400000000                    mov    DWORD PTR [ebp-0xc],0x0
0x55ec1d  eb9b                              jmp    0x55ebba
0x55ec1f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x55ec22  51                                push   ecx
0x55ec23  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x55ec26  33c0                              xor    eax,eax
0x55ec28  50                                push   eax
0x55ec29  ff55e8                            call   DWORD PTR [ebp-0x18]
0x55ec2c  5f                                pop    edi
0x55ec2d  5e                                pop    esi
0x55ec2e  33c0                              xor    eax,eax
0x55ec30  5b                                pop    ebx
0x55ec31  8be5                              mov    esp,ebp
0x55ec33  5d                                pop    ebp
0x55ec34  c3                                ret

; A_FADE_I1 Lua type and numeric/string conversion
; VA 0x55ec40..0x55ecbb raw 0x15e040 length 123 SHA256 89aa52822fe2760d0b3e4ed15e55da26a382365d455833d4c0c2d1ce5a19b45e
0x55ec40  55                                push   ebp
0x55ec41  8bec                              mov    ebp,esp
0x55ec43  83ec1c                            sub    esp,0x1c
0x55ec46  a1301ffe00                        mov    eax,ds:0xfe1f30
0x55ec4b  8b09                              mov    ecx,DWORD PTR [ecx]
0x55ec4d  8945f4                            mov    DWORD PTR [ebp-0xc],eax
0x55ec50  53                                push   ebx
0x55ec51  8b1d381ffe00                      mov    ebx,DWORD PTR ds:0xfe1f38
0x55ec57  83c8ff                            or     eax,0xffffffff
0x55ec5a  e891641900                        call   0x6f50f0
0x55ec5f  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x55ec62  83f903                            cmp    ecx,0x3
0x55ec65  742a                              je     0x55ec91
0x55ec67  83f904                            cmp    ecx,0x4
0x55ec6a  7540                              jne    0x55ecac
0x55ec6c  56                                push   esi
0x55ec6d  8b30                              mov    esi,DWORD PTR [eax]
0x55ec6f  57                                push   edi
0x55ec70  83c610                            add    esi,0x10
0x55ec73  8d7df8                            lea    edi,[ebp-0x8]
0x55ec76  e8e58a1900                        call   0x6f7760
0x55ec7b  5f                                pop    edi
0x55ec7c  5e                                pop    esi
0x55ec7d  85c0                              test   eax,eax
0x55ec7f  742b                              je     0x55ecac
0x55ec81  dd45f8                            fld    QWORD PTR [ebp-0x8]
0x55ec84  c745ec03000000                    mov    DWORD PTR [ebp-0x14],0x3
0x55ec8b  dd5de4                            fstp   QWORD PTR [ebp-0x1c]
0x55ec8e  8d45e4                            lea    eax,[ebp-0x1c]
0x55ec91  dd00                              fld    QWORD PTR [eax]
0x55ec93  dd5dec                            fstp   QWORD PTR [ebp-0x14]
0x55ec96  dd45ec                            fld    QWORD PTR [ebp-0x14]
0x55ec99  db5dfc                            fistp  DWORD PTR [ebp-0x4]
0x55ec9c  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x55ec9f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x55eca2  50                                push   eax
0x55eca3  ffd3                              call   ebx
0x55eca5  33c0                              xor    eax,eax
0x55eca7  5b                                pop    ebx
0x55eca8  8be5                              mov    esp,ebp
0x55ecaa  5d                                pop    ebp
0x55ecab  c3                                ret
0x55ecac  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x55ecaf  33c0                              xor    eax,eax
0x55ecb1  50                                push   eax
0x55ecb2  ffd3                              call   ebx
0x55ecb4  33c0                              xor    eax,eax
0x55ecb6  5b                                pop    ebx
0x55ecb7  8be5                              mov    esp,ebp
0x55ecb9  5d                                pop    ebp
0x55ecba  c3                                ret

; C01 CameraWorks constructor and formal VM registrations
; VA 0x54e750..0x54e90b raw 0x14db50 length 443 SHA256 bc49608403373b99ea9fa767c1167db101c55193c1ef066f0deb9799007f2f53
0x54e750  55                                push   ebp
0x54e751  8bec                              mov    ebp,esp
0x54e753  6aff                              push   0xffffffff
0x54e755  6894a89300                        push   0x93a894
0x54e75a  64a100000000                      mov    eax,fs:0x0
0x54e760  50                                push   eax
0x54e761  83ec0c                            sub    esp,0xc
0x54e764  53                                push   ebx
0x54e765  a1201fd600                        mov    eax,ds:0xd61f20
0x54e76a  33c5                              xor    eax,ebp
0x54e76c  50                                push   eax
0x54e76d  8d45f4                            lea    eax,[ebp-0xc]
0x54e770  64a300000000                      mov    fs:0x0,eax
0x54e776  0f57c0                            xorps  xmm0,xmm0
0x54e779  33c0                              xor    eax,eax
0x54e77b  c745f02076fb00                    mov    DWORD PTR [ebp-0x10],0xfb7620
0x54e782  a32076fb00                        mov    ds:0xfb7620,eax
0x54e787  c7052476fb0020fdc000              mov    DWORD PTR ds:0xfb7624,0xc0fd20
0x54e791  c7052876fb002cf2c400              mov    DWORD PTR ds:0xfb7628,0xc4f22c
0x54e79b  a32c76fb00                        mov    ds:0xfb762c,eax
0x54e7a0  a33076fb00                        mov    ds:0xfb7630,eax
0x54e7a5  a33476fb00                        mov    ds:0xfb7634,eax
0x54e7aa  f30f11053c76fb00                  movss  DWORD PTR ds:0xfb763c,xmm0
0x54e7b2  f30f11054076fb00                  movss  DWORD PTR ds:0xfb7640,xmm0
0x54e7ba  f30f11054476fb00                  movss  DWORD PTR ds:0xfb7644,xmm0
0x54e7c2  f30f11054876fb00                  movss  DWORD PTR ds:0xfb7648,xmm0
0x54e7ca  f30f11054c76fb00                  movss  DWORD PTR ds:0xfb764c,xmm0
0x54e7d2  f30f11055076fb00                  movss  DWORD PTR ds:0xfb7650,xmm0
0x54e7da  f30f11055476fb00                  movss  DWORD PTR ds:0xfb7654,xmm0
0x54e7e2  a35876fb00                        mov    ds:0xfb7658,eax
0x54e7e7  f30f11055c76fb00                  movss  DWORD PTR ds:0xfb765c,xmm0
0x54e7ef  a36076fb00                        mov    ds:0xfb7660,eax
0x54e7f4  a36476fb00                        mov    ds:0xfb7664,eax
0x54e7f9  a36876fb00                        mov    ds:0xfb7668,eax
0x54e7fe  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x54e801  f30f100da857c500                  movss  xmm1,DWORD PTR ds:0xc557a8
0x54e809  f30f11057876fb00                  movss  DWORD PTR ds:0xfb7678,xmm0
0x54e811  f30f11057c76fb00                  movss  DWORD PTR ds:0xfb767c,xmm0
0x54e819  f30f11058076fb00                  movss  DWORD PTR ds:0xfb7680,xmm0
0x54e821  f30f11058876fb00                  movss  DWORD PTR ds:0xfb7688,xmm0
0x54e829  f30f11058c76fb00                  movss  DWORD PTR ds:0xfb768c,xmm0
0x54e831  f30f11059076fb00                  movss  DWORD PTR ds:0xfb7690,xmm0
0x54e839  f30f11059476fb00                  movss  DWORD PTR ds:0xfb7694,xmm0
0x54e841  f30f1005c056c400                  movss  xmm0,DWORD PTR ds:0xc456c0
0x54e849  f30f11059876fb00                  movss  DWORD PTR ds:0xfb7698,xmm0
0x54e851  f30f10053458c500                  movss  xmm0,DWORD PTR ds:0xc55834
0x54e859  f30f11059c76fb00                  movss  DWORD PTR ds:0xfb769c,xmm0
0x54e861  f30f10053058c500                  movss  xmm0,DWORD PTR ds:0xc55830
0x54e869  bb01000000                        mov    ebx,0x1
0x54e86e  c7056c76fb0048fdc000              mov    DWORD PTR ds:0xfb766c,0xc0fd48
0x54e878  a37076fb00                        mov    ds:0xfb7670,eax
0x54e87d  a37476fb00                        mov    ds:0xfb7674,eax
0x54e882  f30f110d8476fb00                  movss  DWORD PTR ds:0xfb7684,xmm1
0x54e88a  f30f1105a076fb00                  movss  DWORD PTR ds:0xfb76a0,xmm0
0x54e892  891da476fb00                      mov    DWORD PTR ds:0xfb76a4,ebx
0x54e898  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x54e89b  841dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,bl
0x54e8a1  751f                              jne    0x54e8c2
0x54e8a3  091dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ebx
0x54e8a9  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x54e8ad  e8ce5a1a00                        call   0x6f4380
0x54e8b2  68d0e6bc00                        push   0xbce6d0
0x54e8b7  e85e3a3400                        call   0x89231a
0x54e8bc  83c404                            add    esp,0x4
0x54e8bf  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x54e8c2  68c8f3fd00                        push   0xfdf3c8
0x54e8c7  e86458eeff                        call   0x434130
0x54e8cc  8d4dec                            lea    ecx,[ebp-0x14]
0x54e8cf  51                                push   ecx
0x54e8d0  e84b010000                        call   0x54ea20
0x54e8d5  83c408                            add    esp,0x8
0x54e8d8  50                                push   eax
0x54e8d9  e822020000                        call   0x54eb00
0x54e8de  50                                push   eax
0x54e8df  e8bc020000                        call   0x54eba0
0x54e8e4  50                                push   eax
0x54e8e5  e856030000                        call   0x54ec40
0x54e8ea  50                                push   eax
0x54e8eb  e8f0030000                        call   0x54ece0
0x54e8f0  50                                push   eax
0x54e8f1  e88a040000                        call   0x54ed80
0x54e8f6  b82076fb00                        mov    eax,0xfb7620
0x54e8fb  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x54e8fe  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x54e905  59                                pop    ecx
0x54e906  5b                                pop    ebx
0x54e907  8be5                              mov    esp,ebp
0x54e909  5d                                pop    ebp
0x54e90a  c3                                ret

; C02 CameraWorks namespace / current-pointer receiver
; VA 0x54ea20..0x54eaf5 raw 0x14de20 length 213 SHA256 3d4aa8445bc24eb8c227ec9293890bc7808e1e1744be34146729c238d8c89d9e
0x54ea20  55                                push   ebp
0x54ea21  8bec                              mov    ebp,esp
0x54ea23  51                                push   ecx
0x54ea24  53                                push   ebx
0x54ea25  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x54ea28  56                                push   esi
0x54ea29  8b33                              mov    esi,DWORD PTR [ebx]
0x54ea2b  a3281efe00                        mov    ds:0xfe1e28,eax
0x54ea30  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x54ea33  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x54ea36  57                                push   edi
0x54ea37  891d241efe00                      mov    DWORD PTR ds:0xfe1e24,ebx
0x54ea3d  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x54ea40  7207                              jb     0x54ea49
0x54ea42  8bc6                              mov    eax,esi
0x54ea44  e857c91a00                        call   0x6fb3a0
0x54ea49  8b7e08                            mov    edi,DWORD PTR [esi+0x8]
0x54ea4c  6a00                              push   0x0
0x54ea4e  6a00                              push   0x0
0x54ea50  56                                push   esi
0x54ea51  e84aaf1a00                        call   0x6f99a0
0x54ea56  8907                              mov    DWORD PTR [edi],eax
0x54ea58  c7470805000000                    mov    DWORD PTR [edi+0x8],0x5
0x54ea5f  83460810                          add    DWORD PTR [esi+0x8],0x10
0x54ea63  8b33                              mov    esi,DWORD PTR [ebx]
0x54ea65  83c40c                            add    esp,0xc
0x54ea68  bf10fdc000                        mov    edi,0xc0fd10
0x54ea6d  b8eed8ffff                        mov    eax,0xffffd8ee
0x54ea72  e8196d1a00                        call   0x6f5790
0x54ea77  8b33                              mov    esi,DWORD PTR [ebx]
0x54ea79  b8eed8ffff                        mov    eax,0xffffd8ee
0x54ea7e  e8fd6b1a00                        call   0x6f5680
0x54ea83  8b03                              mov    eax,DWORD PTR [ebx]
0x54ea85  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x54ea88  83e810                            sub    eax,0x10
0x54ea8b  bff0ffffff                        mov    edi,0xfffffff0
0x54ea90  3dc8bfc000                        cmp    eax,0xc0bfc8
0x54ea95  7406                              je     0x54ea9d
0x54ea97  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x54ea9b  7417                              je     0x54eab4
0x54ea9d  6810fdc000                        push   0xc0fd10
0x54eaa2  68c426c400                        push   0xc426c4
0x54eaa7  e811463400                        call   0x8930bd
0x54eaac  8b03                              mov    eax,DWORD PTR [ebx]
0x54eaae  83c408                            add    esp,0x8
0x54eab1  017808                            add    DWORD PTR [eax+0x8],edi
0x54eab4  8b33                              mov    esi,DWORD PTR [ebx]
0x54eab6  682462c000                        push   0xc06224
0x54eabb  e8506a1a00                        call   0x6f5510
0x54eac0  8b33                              mov    esi,DWORD PTR [ebx]
0x54eac2  83c404                            add    esp,0x4
0x54eac5  6a00                              push   0x0
0x54eac7  6820ee5400                        push   0x54ee20
0x54eacc  e8df6a1a00                        call   0x6f55b0
0x54ead1  8b13                              mov    edx,DWORD PTR [ebx]
0x54ead3  52                                push   edx
0x54ead4  b8fdffffff                        mov    eax,0xfffffffd
0x54ead9  e8126d1a00                        call   0x6f57f0
0x54eade  8b1b                              mov    ebx,DWORD PTR [ebx]
0x54eae0  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x54eae3  83c40c                            add    esp,0xc
0x54eae6  017b08                            add    DWORD PTR [ebx+0x8],edi
0x54eae9  5f                                pop    edi
0x54eaea  5e                                pop    esi
0x54eaeb  c70010fdc000                      mov    DWORD PTR [eax],0xc0fd10
0x54eaf1  5b                                pop    ebx
0x54eaf2  59                                pop    ecx
0x54eaf3  5d                                pop    ebp
0x54eaf4  c3                                ret

; C03 Load absolute KeyFrame
; VA 0x54e970..0x54e989 raw 0x14dd70 length 25 SHA256 20c37be7c14727a6bb8b2671eade7ae063086ad1d930f05c66e37e9881093092
0x54e970  55                                push   ebp
0x54e971  8bec                              mov    ebp,esp
0x54e973  51                                push   ecx
0x54e974  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x54e977  8d4104                            lea    eax,[ecx+0x4]
0x54e97a  8901                              mov    DWORD PTR [ecx],eax
0x54e97c  83c108                            add    ecx,0x8
0x54e97f  e85c852400                        call   0x796ee0
0x54e984  59                                pop    ecx
0x54e985  5d                                pop    ebp
0x54e986  c20400                            ret    0x4

; C04 LoadRel explicit offset
; VA 0x54e990..0x54ea13 raw 0x14dd90 length 131 SHA256 c33b4693847ac0dd1b7b7fd0ff70cb18365c057fbc72dbacdd5bb14a87cb5998
0x54e990  55                                push   ebp
0x54e991  8bec                              mov    ebp,esp
0x54e993  83ec10                            sub    esp,0x10
0x54e996  f30f10450c                        movss  xmm0,DWORD PTR [ebp+0xc]
0x54e99b  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x54e99e  56                                push   esi
0x54e99f  f30f1145f4                        movss  DWORD PTR [ebp-0xc],xmm0
0x54e9a4  f30f104510                        movss  xmm0,DWORD PTR [ebp+0x10]
0x54e9a9  57                                push   edi
0x54e9aa  8d4104                            lea    eax,[ecx+0x4]
0x54e9ad  f30f1145f8                        movss  DWORD PTR [ebp-0x8],xmm0
0x54e9b2  f30f104514                        movss  xmm0,DWORD PTR [ebp+0x14]
0x54e9b7  8d7908                            lea    edi,[ecx+0x8]
0x54e9ba  8d75f4                            lea    esi,[ebp-0xc]
0x54e9bd  8901                              mov    DWORD PTR [ecx],eax
0x54e9bf  f30f1145fc                        movss  DWORD PTR [ebp-0x4],xmm0
0x54e9c4  e8078b2400                        call   0x7974d0
0x54e9c9  5f                                pop    edi
0x54e9ca  5e                                pop    esi
0x54e9cb  8be5                              mov    esp,ebp
0x54e9cd  5d                                pop    ebp
0x54e9ce  c21000                            ret    0x10
0x54e9d1  cc                                int3
0x54e9d2  cc                                int3
0x54e9d3  cc                                int3
0x54e9d4  cc                                int3
0x54e9d5  cc                                int3
0x54e9d6  cc                                int3
0x54e9d7  cc                                int3
0x54e9d8  cc                                int3
0x54e9d9  cc                                int3
0x54e9da  cc                                int3
0x54e9db  cc                                int3
0x54e9dc  cc                                int3
0x54e9dd  cc                                int3
0x54e9de  cc                                int3
0x54e9df  cc                                int3
0x54e9e0  8b09                              mov    ecx,DWORD PTR [ecx]
0x54e9e2  85c9                              test   ecx,ecx
0x54e9e4  7407                              je     0x54e9ed
0x54e9e6  8b01                              mov    eax,DWORD PTR [ecx]
0x54e9e8  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x54e9eb  ffe2                              jmp    edx
0x54e9ed  c3                                ret
0x54e9ee  cc                                int3
0x54e9ef  cc                                int3
0x54e9f0  8b09                              mov    ecx,DWORD PTR [ecx]
0x54e9f2  85c9                              test   ecx,ecx
0x54e9f4  7407                              je     0x54e9fd
0x54e9f6  8b01                              mov    eax,DWORD PTR [ecx]
0x54e9f8  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0x54e9fb  ffe2                              jmp    edx
0x54e9fd  c3                                ret
0x54e9fe  cc                                int3
0x54e9ff  cc                                int3
0x54ea00  8b09                              mov    ecx,DWORD PTR [ecx]
0x54ea02  85c9                              test   ecx,ecx
0x54ea04  7407                              je     0x54ea0d
0x54ea06  8b01                              mov    eax,DWORD PTR [ecx]
0x54ea08  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0x54ea0b  ffe2                              jmp    edx
0x54ea0d  b801000000                        mov    eax,0x1
0x54ea12  c3                                ret

; C08 Q PlayCameraWorks absolute/current-position-relative and immediate Play
; VA 0x562b80..0x562cef raw 0x161f80 length 367 SHA256 a0529f36c52e9b3663a3525a1c05a5a2fdc8b8d459bac8bbd7a03f554b521c97
0x562b80  55                                push   ebp
0x562b81  8bec                              mov    ebp,esp
0x562b83  83e4f8                            and    esp,0xfffffff8
0x562b86  6aff                              push   0xffffffff
0x562b88  6868ab9300                        push   0x93ab68
0x562b8d  64a100000000                      mov    eax,fs:0x0
0x562b93  50                                push   eax
0x562b94  83ec14                            sub    esp,0x14
0x562b97  56                                push   esi
0x562b98  57                                push   edi
0x562b99  a1201fd600                        mov    eax,ds:0xd61f20
0x562b9e  33c4                              xor    eax,esp
0x562ba0  50                                push   eax
0x562ba1  8d442420                          lea    eax,[esp+0x20]
0x562ba5  64a300000000                      mov    fs:0x0,eax
0x562bab  837d0c00                          cmp    DWORD PTR [ebp+0xc],0x0
0x562baf  0f849a000000                      je     0x562c4f
0x562bb5  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x562bbc  be01000000                        mov    esi,0x1
0x562bc1  7528                              jne    0x562beb
0x562bc3  0935e879fb00                      or     DWORD PTR ds:0xfb79e8,esi
0x562bc9  c744242800000000                  mov    DWORD PTR [esp+0x28],0x0
0x562bd1  e80a622300                        call   0x798de0
0x562bd6  68e0d2bc00                        push   0xbcd2e0
0x562bdb  e83af73200                        call   0x89231a
0x562be0  83c404                            add    esp,0x4
0x562be3  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x562beb  f6051c76fb0001                    test   BYTE PTR ds:0xfb761c,0x1
0x562bf2  a1e876fb00                        mov    eax,ds:0xfb76e8
0x562bf7  8b480c                            mov    ecx,DWORD PTR [eax+0xc]
0x562bfa  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x562bfd  8b4014                            mov    eax,DWORD PTR [eax+0x14]
0x562c00  894c2410                          mov    DWORD PTR [esp+0x10],ecx
0x562c04  89542414                          mov    DWORD PTR [esp+0x14],edx
0x562c08  89442418                          mov    DWORD PTR [esp+0x18],eax
0x562c0c  7524                              jne    0x562c32
0x562c0e  09351c76fb00                      or     DWORD PTR ds:0xfb761c,esi
0x562c14  89742428                          mov    DWORD PTR [esp+0x28],esi
0x562c18  e833bbfeff                        call   0x54e750
0x562c1d  6860d2bc00                        push   0xbcd260
0x562c22  e8f3f63200                        call   0x89231a
0x562c27  83c404                            add    esp,0x4
0x562c2a  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x562c32  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x562c35  8d742410                          lea    esi,[esp+0x10]
0x562c39  bf2876fb00                        mov    edi,0xfb7628
0x562c3e  c7052076fb002476fb00              mov    DWORD PTR ds:0xfb7620,0xfb7624
0x562c48  e883482300                        call   0x7974d0
0x562c4d  eb49                              jmp    0x562c98
0x562c4f  f6051c76fb0001                    test   BYTE PTR ds:0xfb761c,0x1
0x562c56  7529                              jne    0x562c81
0x562c58  830d1c76fb0001                    or     DWORD PTR ds:0xfb761c,0x1
0x562c5f  c744242802000000                  mov    DWORD PTR [esp+0x28],0x2
0x562c67  e8e4bafeff                        call   0x54e750
0x562c6c  6860d2bc00                        push   0xbcd260
0x562c71  e8a4f63200                        call   0x89231a
0x562c76  83c404                            add    esp,0x4
0x562c79  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x562c81  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x562c84  b92876fb00                        mov    ecx,0xfb7628
0x562c89  c7052076fb002476fb00              mov    DWORD PTR ds:0xfb7620,0xfb7624
0x562c93  e848422300                        call   0x796ee0
0x562c98  f6051c76fb0001                    test   BYTE PTR ds:0xfb761c,0x1
0x562c9f  7529                              jne    0x562cca
0x562ca1  830d1c76fb0001                    or     DWORD PTR ds:0xfb761c,0x1
0x562ca8  c744242803000000                  mov    DWORD PTR [esp+0x28],0x3
0x562cb0  e89bbafeff                        call   0x54e750
0x562cb5  6860d2bc00                        push   0xbcd260
0x562cba  e85bf63200                        call   0x89231a
0x562cbf  83c404                            add    esp,0x4
0x562cc2  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x562cca  8b0d2076fb00                      mov    ecx,DWORD PTR ds:0xfb7620
0x562cd0  85c9                              test   ecx,ecx
0x562cd2  7407                              je     0x562cdb
0x562cd4  8b11                              mov    edx,DWORD PTR [ecx]
0x562cd6  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x562cd9  ffd0                              call   eax
0x562cdb  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x562cdf  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x562ce6  59                                pop    ecx
0x562ce7  5f                                pop    edi
0x562ce8  5e                                pop    esi
0x562ce9  8be5                              mov    esp,ebp
0x562ceb  5d                                pop    ebp
0x562cec  c20800                            ret    0x8

; C09 Q SkipCamera current frame plus converted input/rate
; VA 0x562cf0..0x562e02 raw 0x1620f0 length 274 SHA256 6c1ba2c0b077f1b7398b7b6a4f715bab8d7ee51efb173152b242dbb9b353d24c
0x562cf0  55                                push   ebp
0x562cf1  8bec                              mov    ebp,esp
0x562cf3  83e4f8                            and    esp,0xfffffff8
0x562cf6  6aff                              push   0xffffffff
0x562cf8  680cab9300                        push   0x93ab0c
0x562cfd  64a100000000                      mov    eax,fs:0x0
0x562d03  50                                push   eax
0x562d04  83ec0c                            sub    esp,0xc
0x562d07  53                                push   ebx
0x562d08  56                                push   esi
0x562d09  a1201fd600                        mov    eax,ds:0xd61f20
0x562d0e  33c4                              xor    eax,esp
0x562d10  50                                push   eax
0x562d11  8d442418                          lea    eax,[esp+0x18]
0x562d15  64a300000000                      mov    fs:0x0,eax
0x562d1b  a1cca7fb00                        mov    eax,ds:0xfba7cc
0x562d20  85c0                              test   eax,eax
0x562d22  751f                              jne    0x562d43
0x562d24  6880130000                        push   0x1380
0x562d29  e83ae53200                        call   0x891268
0x562d2e  83c404                            add    esp,0x4
0x562d31  85c0                              test   eax,eax
0x562d33  7407                              je     0x562d3c
0x562d35  e896c61700                        call   0x6df3d0
0x562d3a  eb02                              jmp    0x562d3e
0x562d3c  33c0                              xor    eax,eax
0x562d3e  a3cca7fb00                        mov    ds:0xfba7cc,eax
0x562d43  8b8060130000                      mov    eax,DWORD PTR [eax+0x1360]
0x562d49  db4508                            fild   DWORD PTR [ebp+0x8]
0x562d4c  89442410                          mov    DWORD PTR [esp+0x10],eax
0x562d50  bb01000000                        mov    ebx,0x1
0x562d55  da742410                          fidiv  DWORD PTR [esp+0x10]
0x562d59  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x562d5d  841d1c76fb00                      test   BYTE PTR ds:0xfb761c,bl
0x562d63  7528                              jne    0x562d8d
0x562d65  091d1c76fb00                      or     DWORD PTR ds:0xfb761c,ebx
0x562d6b  c744242000000000                  mov    DWORD PTR [esp+0x20],0x0
0x562d73  e8d8b9feff                        call   0x54e750
0x562d78  6860d2bc00                        push   0xbcd260
0x562d7d  e898f53200                        call   0x89231a
0x562d82  83c404                            add    esp,0x4
0x562d85  c7442420ffffffff                  mov    DWORD PTR [esp+0x20],0xffffffff
0x562d8d  8b0d2076fb00                      mov    ecx,DWORD PTR ds:0xfb7620
0x562d93  85c9                              test   ecx,ecx
0x562d95  740f                              je     0x562da6
0x562d97  8b11                              mov    edx,DWORD PTR [ecx]
0x562d99  8b4218                            mov    eax,DWORD PTR [edx+0x18]
0x562d9c  ffd0                              call   eax
0x562d9e  8b0d2076fb00                      mov    ecx,DWORD PTR ds:0xfb7620
0x562da4  eb02                              jmp    0x562da8
0x562da6  33c0                              xor    eax,eax
0x562da8  f30f2c742410                      cvttss2si esi,DWORD PTR [esp+0x10]
0x562dae  03f0                              add    esi,eax
0x562db0  841d1c76fb00                      test   BYTE PTR ds:0xfb761c,bl
0x562db6  752a                              jne    0x562de2
0x562db8  091d1c76fb00                      or     DWORD PTR ds:0xfb761c,ebx
0x562dbe  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x562dc2  e889b9feff                        call   0x54e750
0x562dc7  6860d2bc00                        push   0xbcd260
0x562dcc  e849f53200                        call   0x89231a
0x562dd1  c7442424ffffffff                  mov    DWORD PTR [esp+0x24],0xffffffff
0x562dd9  8b0d2076fb00                      mov    ecx,DWORD PTR ds:0xfb7620
0x562ddf  83c404                            add    esp,0x4
0x562de2  85c9                              test   ecx,ecx
0x562de4  7408                              je     0x562dee
0x562de6  8b11                              mov    edx,DWORD PTR [ecx]
0x562de8  8b421c                            mov    eax,DWORD PTR [edx+0x1c]
0x562deb  56                                push   esi
0x562dec  ffd0                              call   eax
0x562dee  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x562df2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x562df9  59                                pop    ecx
0x562dfa  5e                                pop    esi
0x562dfb  5b                                pop    ebx
0x562dfc  8be5                              mov    esp,ebp
0x562dfe  5d                                pop    ebp
0x562dff  c20400                            ret    0x4

; C10 SetCameraPoint/MoveCamera write current camera XYZ
; VA 0x562e10..0x562eb3 raw 0x162210 length 163 SHA256 4733d5e53b449ab636d34d83c553791b2d64328719d3813eee31079de4952427
0x562e10  55                                push   ebp
0x562e11  8bec                              mov    ebp,esp
0x562e13  6aff                              push   0xffffffff
0x562e15  680e259300                        push   0x93250e
0x562e1a  64a100000000                      mov    eax,fs:0x0
0x562e20  50                                push   eax
0x562e21  83ec0c                            sub    esp,0xc
0x562e24  a1201fd600                        mov    eax,ds:0xd61f20
0x562e29  33c5                              xor    eax,ebp
0x562e2b  50                                push   eax
0x562e2c  8d45f4                            lea    eax,[ebp-0xc]
0x562e2f  64a300000000                      mov    fs:0x0,eax
0x562e35  f30f104508                        movss  xmm0,DWORD PTR [ebp+0x8]
0x562e3a  f30f1145e8                        movss  DWORD PTR [ebp-0x18],xmm0
0x562e3f  f30f10450c                        movss  xmm0,DWORD PTR [ebp+0xc]
0x562e44  b801000000                        mov    eax,0x1
0x562e49  f30f1145ec                        movss  DWORD PTR [ebp-0x14],xmm0
0x562e4e  f30f104510                        movss  xmm0,DWORD PTR [ebp+0x10]
0x562e53  f30f1145f0                        movss  DWORD PTR [ebp-0x10],xmm0
0x562e58  8405e879fb00                      test   BYTE PTR ds:0xfb79e8,al
0x562e5e  751f                              jne    0x562e7f
0x562e60  0905e879fb00                      or     DWORD PTR ds:0xfb79e8,eax
0x562e66  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x562e6d  e86e5f2300                        call   0x798de0
0x562e72  68e0d2bc00                        push   0xbcd2e0
0x562e77  e89ef43200                        call   0x89231a
0x562e7c  83c404                            add    esp,0x4
0x562e7f  a1e876fb00                        mov    eax,ds:0xfb76e8
0x562e84  8b55e8                            mov    edx,DWORD PTR [ebp-0x18]
0x562e87  89500c                            mov    DWORD PTR [eax+0xc],edx
0x562e8a  8b55ec                            mov    edx,DWORD PTR [ebp-0x14]
0x562e8d  895010                            mov    DWORD PTR [eax+0x10],edx
0x562e90  8b55f0                            mov    edx,DWORD PTR [ebp-0x10]
0x562e93  8bc8                              mov    ecx,eax
0x562e95  895014                            mov    DWORD PTR [eax+0x14],edx
0x562e98  c781cc00000000000000              mov    DWORD PTR [ecx+0xcc],0x0
0x562ea2  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x562ea5  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x562eac  59                                pop    ecx
0x562ead  8be5                              mov    esp,ebp
0x562eaf  5d                                pop    ebp
0x562eb0  c20c00                            ret    0xc

; C11 RotCamera arg1 angleZ, arg2 angleX, arg3 local camera distance
; VA 0x563970..0x563a69 raw 0x162d70 length 249 SHA256 bc3400ae25824a40b0c07879e50d382d1645c4a077ebfa85d966e2eb4dda1c81
0x563970  55                                push   ebp
0x563971  8bec                              mov    ebp,esp
0x563973  6aff                              push   0xffffffff
0x563975  68faeb9200                        push   0x92ebfa
0x56397a  64a100000000                      mov    eax,fs:0x0
0x563980  50                                push   eax
0x563981  51                                push   ecx
0x563982  53                                push   ebx
0x563983  56                                push   esi
0x563984  a1201fd600                        mov    eax,ds:0xd61f20
0x563989  33c5                              xor    eax,ebp
0x56398b  50                                push   eax
0x56398c  8d45f4                            lea    eax,[ebp-0xc]
0x56398f  64a300000000                      mov    fs:0x0,eax
0x563995  bb01000000                        mov    ebx,0x1
0x56399a  33f6                              xor    esi,esi
0x56399c  841de879fb00                      test   BYTE PTR ds:0xfb79e8,bl
0x5639a2  7522                              jne    0x5639c6
0x5639a4  091de879fb00                      or     DWORD PTR ds:0xfb79e8,ebx
0x5639aa  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5639ad  e82e542300                        call   0x798de0
0x5639b2  68e0d2bc00                        push   0xbcd2e0
0x5639b7  e85ee93200                        call   0x89231a
0x5639bc  83c404                            add    esp,0x4
0x5639bf  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x5639c6  a1e876fb00                        mov    eax,ds:0xfb76e8
0x5639cb  f30f104508                        movss  xmm0,DWORD PTR [ebp+0x8]
0x5639d0  f30f114020                        movss  DWORD PTR [eax+0x20],xmm0
0x5639d5  89b0cc000000                      mov    DWORD PTR [eax+0xcc],esi
0x5639db  841de879fb00                      test   BYTE PTR ds:0xfb79e8,bl
0x5639e1  7522                              jne    0x563a05
0x5639e3  091de879fb00                      or     DWORD PTR ds:0xfb79e8,ebx
0x5639e9  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x5639ec  e8ef532300                        call   0x798de0
0x5639f1  68e0d2bc00                        push   0xbcd2e0
0x5639f6  e81fe93200                        call   0x89231a
0x5639fb  83c404                            add    esp,0x4
0x5639fe  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x563a05  a1e876fb00                        mov    eax,ds:0xfb76e8
0x563a0a  f30f10450c                        movss  xmm0,DWORD PTR [ebp+0xc]
0x563a0f  f30f114018                        movss  DWORD PTR [eax+0x18],xmm0
0x563a14  89b0cc000000                      mov    DWORD PTR [eax+0xcc],esi
0x563a1a  841de879fb00                      test   BYTE PTR ds:0xfb79e8,bl
0x563a20  751f                              jne    0x563a41
0x563a22  091de879fb00                      or     DWORD PTR ds:0xfb79e8,ebx
0x563a28  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x563a2f  e8ac532300                        call   0x798de0
0x563a34  68e0d2bc00                        push   0xbcd2e0
0x563a39  e8dce83200                        call   0x89231a
0x563a3e  83c404                            add    esp,0x4
0x563a41  a1e876fb00                        mov    eax,ds:0xfb76e8
0x563a46  f30f104510                        movss  xmm0,DWORD PTR [ebp+0x10]
0x563a4b  f30f114024                        movss  DWORD PTR [eax+0x24],xmm0
0x563a50  89b0cc000000                      mov    DWORD PTR [eax+0xcc],esi
0x563a56  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x563a59  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x563a60  59                                pop    ecx
0x563a61  5e                                pop    esi
0x563a62  5b                                pop    ebx
0x563a63  8be5                              mov    esp,ebp
0x563a65  5d                                pop    ebp
0x563a66  c20c00                            ret    0xc

; C12 KeyFrame XML load/field parsing
; VA 0x796ee0..0x7974cb raw 0x3962e0 length 1515 SHA256 28125bcfb88d3713c03932a958df5cdbdb8fe66a5f15919a6494cff02918056a
0x796ee0  55                                push   ebp
0x796ee1  8bec                              mov    ebp,esp
0x796ee3  83e4f8                            and    esp,0xfffffff8
0x796ee6  6aff                              push   0xffffffff
0x796ee8  687b289200                        push   0x92287b
0x796eed  64a100000000                      mov    eax,fs:0x0
0x796ef3  50                                push   eax
0x796ef4  81ec98000000                      sub    esp,0x98
0x796efa  a1201fd600                        mov    eax,ds:0xd61f20
0x796eff  33c4                              xor    eax,esp
0x796f01  89842490000000                    mov    DWORD PTR [esp+0x90],eax
0x796f08  53                                push   ebx
0x796f09  56                                push   esi
0x796f0a  57                                push   edi
0x796f0b  a1201fd600                        mov    eax,ds:0xd61f20
0x796f10  33c4                              xor    eax,esp
0x796f12  50                                push   eax
0x796f13  8d8424a8000000                    lea    eax,[esp+0xa8]
0x796f1a  64a300000000                      mov    fs:0x0,eax
0x796f20  8bf9                              mov    edi,ecx
0x796f22  8bf2                              mov    esi,edx
0x796f24  e8e7050000                        call   0x797510
0x796f29  8d442424                          lea    eax,[esp+0x24]
0x796f2d  50                                push   eax
0x796f2e  8bce                              mov    ecx,esi
0x796f30  e8fb7ef9ff                        call   0x72ee30
0x796f35  c78424b000000000000000            mov    DWORD PTR [esp+0xb0],0x0
0x796f40  837c245810                        cmp    DWORD PTR [esp+0x58],0x10
0x796f45  8b4c2444                          mov    ecx,DWORD PTR [esp+0x44]
0x796f49  7304                              jae    0x796f4f
0x796f4b  8d4c2444                          lea    ecx,[esp+0x44]
0x796f4f  6a00                              push   0x0
0x796f51  8d742428                          lea    esi,[esp+0x28]
0x796f55  e8b681f9ff                        call   0x72f110
0x796f5a  84c0                              test   al,al
0x796f5c  0f84f7040000                      je     0x797459
0x796f62  68b8f1c400                        push   0xc4f1b8
0x796f67  8bc6                              mov    eax,esi
0x796f69  e87273f9ff                        call   0x72e2e0
0x796f6e  68c4f1c400                        push   0xc4f1c4
0x796f73  e86873f9ff                        call   0x72e2e0
0x796f78  89442418                          mov    DWORD PTR [esp+0x18],eax
0x796f7c  85c0                              test   eax,eax
0x796f7e  0f84d5040000                      je     0x797459
0x796f84  83c704                            add    edi,0x4
0x796f87  897c2420                          mov    DWORD PTR [esp+0x20],edi
0x796f8b  eb03                              jmp    0x796f90
0x796f8d  8d4900                            lea    ecx,[ecx+0x0]
0x796f90  6a28                              push   0x28
0x796f92  e8d1a20f00                        call   0x891268
0x796f97  83c404                            add    esp,0x4
0x796f9a  85c0                              test   eax,eax
0x796f9c  7425                              je     0x796fc3
0x796f9e  d9ee                              fldz
0x796fa0  33c9                              xor    ecx,ecx
0x796fa2  d910                              fst    DWORD PTR [eax]
0x796fa4  89481c                            mov    DWORD PTR [eax+0x1c],ecx
0x796fa7  d95004                            fst    DWORD PTR [eax+0x4]
0x796faa  894824                            mov    DWORD PTR [eax+0x24],ecx
0x796fad  d95008                            fst    DWORD PTR [eax+0x8]
0x796fb0  8bd8                              mov    ebx,eax
0x796fb2  d9500c                            fst    DWORD PTR [eax+0xc]
0x796fb5  d95010                            fst    DWORD PTR [eax+0x10]
0x796fb8  d95014                            fst    DWORD PTR [eax+0x14]
0x796fbb  d95018                            fst    DWORD PTR [eax+0x18]
0x796fbe  d95820                            fstp   DWORD PTR [eax+0x20]
0x796fc1  eb02                              jmp    0x796fc5
0x796fc3  33db                              xor    ebx,ebx
0x796fc5  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x796fc9  8b11                              mov    edx,DWORD PTR [ecx]
0x796fcb  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x796fce  895c241c                          mov    DWORD PTR [esp+0x1c],ebx
0x796fd2  ffd0                              call   eax
0x796fd4  8bb094000000                      mov    esi,DWORD PTR [eax+0x94]
0x796fda  8d7844                            lea    edi,[eax+0x44]
0x796fdd  3bf7                              cmp    esi,edi
0x796fdf  7428                              je     0x797009
0x796fe1  837e2810                          cmp    DWORD PTR [esi+0x28],0x10
0x796fe5  8d4614                            lea    eax,[esi+0x14]
0x796fe8  7202                              jb     0x796fec
0x796fea  8b00                              mov    eax,DWORD PTR [eax]
0x796fec  68d0f1c400                        push   0xc4f1d0
0x796ff1  50                                push   eax
0x796ff2  e8bacc0f00                        call   0x893cb1
0x796ff7  83c408                            add    esp,0x8
0x796ffa  85c0                              test   eax,eax
0x796ffc  0f8487000000                      je     0x797089
0x797002  8b7650                            mov    esi,DWORD PTR [esi+0x50]
0x797005  3bf7                              cmp    esi,edi
0x797007  75d8                              jne    0x796fe1
0x797009  33c0                              xor    eax,eax
0x79700b  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x79700f  894324                            mov    DWORD PTR [ebx+0x24],eax
0x797012  8b11                              mov    edx,DWORD PTR [ecx]
0x797014  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x797017  ffd0                              call   eax
0x797019  8bb094000000                      mov    esi,DWORD PTR [eax+0x94]
0x79701f  8d7844                            lea    edi,[eax+0x44]
0x797022  3bf7                              cmp    esi,edi
0x797024  7424                              je     0x79704a
0x797026  837e2810                          cmp    DWORD PTR [esi+0x28],0x10
0x79702a  8d4614                            lea    eax,[esi+0x14]
0x79702d  7202                              jb     0x797031
0x79702f  8b00                              mov    eax,DWORD PTR [eax]
0x797031  68dcf1c400                        push   0xc4f1dc
0x797036  50                                push   eax
0x797037  e875cc0f00                        call   0x893cb1
0x79703c  83c408                            add    esp,0x8
0x79703f  85c0                              test   eax,eax
0x797041  7407                              je     0x79704a
0x797043  8b7650                            mov    esi,DWORD PTR [esi+0x50]
0x797046  3bf7                              cmp    esi,edi
0x797048  75dc                              jne    0x797026
0x79704a  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x79704e  8b7118                            mov    esi,DWORD PTR [ecx+0x18]
0x797051  85f6                              test   esi,esi
0x797053  0f8432010000                      je     0x79718b
0x797059  8da42400000000                    lea    esp,[esp+0x0]
0x797060  837e3410                          cmp    DWORD PTR [esi+0x34],0x10
0x797064  8d4620                            lea    eax,[esi+0x20]
0x797067  7202                              jb     0x79706b
0x797069  8b00                              mov    eax,DWORD PTR [eax]
0x79706b  68b045c400                        push   0xc445b0
0x797070  50                                push   eax
0x797071  e83bcc0f00                        call   0x893cb1
0x797076  83c408                            add    esp,0x8
0x797079  85c0                              test   eax,eax
0x79707b  7435                              je     0x7970b2
0x79707d  8b7640                            mov    esi,DWORD PTR [esi+0x40]
0x797080  85f6                              test   esi,esi
0x797082  75dc                              jne    0x797060
0x797084  e902010000                        jmp    0x79718b
0x797089  85f6                              test   esi,esi
0x79708b  0f8478ffffff                      je     0x797009
0x797091  837e4410                          cmp    DWORD PTR [esi+0x44],0x10
0x797095  8d4630                            lea    eax,[esi+0x30]
0x797098  7202                              jb     0x79709c
0x79709a  8b00                              mov    eax,DWORD PTR [eax]
0x79709c  85c0                              test   eax,eax
0x79709e  0f8465ffffff                      je     0x797009
0x7970a4  50                                push   eax
0x7970a5  e80aa70f00                        call   0x8917b4
0x7970aa  83c404                            add    esp,0x4
0x7970ad  e959ffffff                        jmp    0x79700b
0x7970b2  85f6                              test   esi,esi
0x7970b4  0f84d1000000                      je     0x79718b
0x7970ba  8b16                              mov    edx,DWORD PTR [esi]
0x7970bc  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x7970bf  8bce                              mov    ecx,esi
0x7970c1  ffd0                              call   eax
0x7970c3  85c0                              test   eax,eax
0x7970c5  0f84c0000000                      je     0x79718b
0x7970cb  8b16                              mov    edx,DWORD PTR [esi]
0x7970cd  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x7970d0  8bce                              mov    ecx,esi
0x7970d2  ffd0                              call   eax
0x7970d4  85c0                              test   eax,eax
0x7970d6  0f84af000000                      je     0x79718b
0x7970dc  8d7844                            lea    edi,[eax+0x44]
0x7970df  682869c000                        push   0xc06928
0x7970e4  e8b78ff9ff                        call   0x7300a0
0x7970e9  be10000000                        mov    esi,0x10
0x7970ee  85c0                              test   eax,eax
0x7970f0  741d                              je     0x79710f
0x7970f2  83c030                            add    eax,0x30
0x7970f5  397014                            cmp    DWORD PTR [eax+0x14],esi
0x7970f8  7202                              jb     0x7970fc
0x7970fa  8b00                              mov    eax,DWORD PTR [eax]
0x7970fc  85c0                              test   eax,eax
0x7970fe  740f                              je     0x79710f
0x797100  50                                push   eax
0x797101  e870511000                        call   0x89c276
0x797106  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x79710a  83c404                            add    esp,0x4
0x79710d  eb06                              jmp    0x797115
0x79710f  d9ee                              fldz
0x797111  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x797115  d9442414                          fld    DWORD PTR [esp+0x14]
0x797119  682c69c000                        push   0xc0692c
0x79711e  d91b                              fstp   DWORD PTR [ebx]
0x797120  e87b8ff9ff                        call   0x7300a0
0x797125  85c0                              test   eax,eax
0x797127  741d                              je     0x797146
0x797129  83c030                            add    eax,0x30
0x79712c  397014                            cmp    DWORD PTR [eax+0x14],esi
0x79712f  7202                              jb     0x797133
0x797131  8b00                              mov    eax,DWORD PTR [eax]
0x797133  85c0                              test   eax,eax
0x797135  740f                              je     0x797146
0x797137  50                                push   eax
0x797138  e839511000                        call   0x89c276
0x79713d  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x797141  83c404                            add    esp,0x4
0x797144  eb06                              jmp    0x79714c
0x797146  d9ee                              fldz
0x797148  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x79714c  d9442414                          fld    DWORD PTR [esp+0x14]
0x797150  68ecf1c400                        push   0xc4f1ec
0x797155  d95b04                            fstp   DWORD PTR [ebx+0x4]
0x797158  e8438ff9ff                        call   0x7300a0
0x79715d  85c0                              test   eax,eax
0x79715f  741d                              je     0x79717e
0x797161  83c030                            add    eax,0x30
0x797164  397014                            cmp    DWORD PTR [eax+0x14],esi
0x797167  7202                              jb     0x79716b
0x797169  8b00                              mov    eax,DWORD PTR [eax]
0x79716b  85c0                              test   eax,eax
0x79716d  740f                              je     0x79717e
0x79716f  50                                push   eax
0x797170  e801511000                        call   0x89c276
0x797175  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x797179  83c404                            add    esp,0x4
0x79717c  eb06                              jmp    0x797184
0x79717e  d9ee                              fldz
0x797180  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x797184  d9442414                          fld    DWORD PTR [esp+0x14]
0x797188  d95b08                            fstp   DWORD PTR [ebx+0x8]
0x79718b  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x79718f  8b7118                            mov    esi,DWORD PTR [ecx+0x18]
0x797192  85f6                              test   esi,esi
0x797194  0f84a4010000                      je     0x79733e
0x79719a  bf10000000                        mov    edi,0x10
0x79719f  90                                nop
0x7971a0  397e34                            cmp    DWORD PTR [esi+0x34],edi
0x7971a3  8d4620                            lea    eax,[esi+0x20]
0x7971a6  7202                              jb     0x7971aa
0x7971a8  8b00                              mov    eax,DWORD PTR [eax]
0x7971aa  68f0f1c400                        push   0xc4f1f0
0x7971af  50                                push   eax
0x7971b0  e8fcca0f00                        call   0x893cb1
0x7971b5  83c408                            add    esp,0x8
0x7971b8  85c0                              test   eax,eax
0x7971ba  740c                              je     0x7971c8
0x7971bc  8b7640                            mov    esi,DWORD PTR [esi+0x40]
0x7971bf  85f6                              test   esi,esi
0x7971c1  75dd                              jne    0x7971a0
0x7971c3  e976010000                        jmp    0x79733e
0x7971c8  85f6                              test   esi,esi
0x7971ca  0f846e010000                      je     0x79733e
0x7971d0  8b16                              mov    edx,DWORD PTR [esi]
0x7971d2  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x7971d5  8bce                              mov    ecx,esi
0x7971d7  ffd0                              call   eax
0x7971d9  85c0                              test   eax,eax
0x7971db  0f845d010000                      je     0x79733e
0x7971e1  8b16                              mov    edx,DWORD PTR [esi]
0x7971e3  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x7971e6  8bce                              mov    ecx,esi
0x7971e8  ffd0                              call   eax
0x7971ea  85c0                              test   eax,eax
0x7971ec  0f844c010000                      je     0x79733e
0x7971f2  8d7844                            lea    edi,[eax+0x44]
0x7971f5  68f8f1c400                        push   0xc4f1f8
0x7971fa  e8a18ef9ff                        call   0x7300a0
0x7971ff  be10000000                        mov    esi,0x10
0x797204  85c0                              test   eax,eax
0x797206  741d                              je     0x797225
0x797208  83c030                            add    eax,0x30
0x79720b  397014                            cmp    DWORD PTR [eax+0x14],esi
0x79720e  7202                              jb     0x797212
0x797210  8b00                              mov    eax,DWORD PTR [eax]
0x797212  85c0                              test   eax,eax
0x797214  740f                              je     0x797225
0x797216  50                                push   eax
0x797217  e85a501000                        call   0x89c276
0x79721c  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x797220  83c404                            add    esp,0x4
0x797223  eb06                              jmp    0x79722b
0x797225  d9ee                              fldz
0x797227  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x79722b  d9442414                          fld    DWORD PTR [esp+0x14]
0x79722f  6800f2c400                        push   0xc4f200
0x797234  d95b0c                            fstp   DWORD PTR [ebx+0xc]
0x797237  e8648ef9ff                        call   0x7300a0
0x79723c  85c0                              test   eax,eax
0x79723e  741d                              je     0x79725d
0x797240  83c030                            add    eax,0x30
0x797243  397014                            cmp    DWORD PTR [eax+0x14],esi
0x797246  7202                              jb     0x79724a
0x797248  8b00                              mov    eax,DWORD PTR [eax]
0x79724a  85c0                              test   eax,eax
0x79724c  740f                              je     0x79725d
0x79724e  50                                push   eax
0x79724f  e822501000                        call   0x89c276
0x797254  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x797258  83c404                            add    esp,0x4
0x79725b  eb06                              jmp    0x797263
0x79725d  d9ee                              fldz
0x79725f  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x797263  d9442414                          fld    DWORD PTR [esp+0x14]
0x797267  6804f2c400                        push   0xc4f204
0x79726c  d95b10                            fstp   DWORD PTR [ebx+0x10]
0x79726f  e82c8ef9ff                        call   0x7300a0
0x797274  85c0                              test   eax,eax
0x797276  741d                              je     0x797295
0x797278  83c030                            add    eax,0x30
0x79727b  397014                            cmp    DWORD PTR [eax+0x14],esi
0x79727e  7202                              jb     0x797282
0x797280  8b00                              mov    eax,DWORD PTR [eax]
0x797282  85c0                              test   eax,eax
0x797284  740f                              je     0x797295
0x797286  50                                push   eax
0x797287  e8ea4f1000                        call   0x89c276
0x79728c  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x797290  83c404                            add    esp,0x4
0x797293  eb06                              jmp    0x79729b
0x797295  d9ee                              fldz
0x797297  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x79729b  d9442414                          fld    DWORD PTR [esp+0x14]
0x79729f  680cf2c400                        push   0xc4f20c
0x7972a4  d95b14                            fstp   DWORD PTR [ebx+0x14]
0x7972a7  e8f48df9ff                        call   0x7300a0
0x7972ac  85c0                              test   eax,eax
0x7972ae  741d                              je     0x7972cd
0x7972b0  83c030                            add    eax,0x30
0x7972b3  397014                            cmp    DWORD PTR [eax+0x14],esi
0x7972b6  7202                              jb     0x7972ba
0x7972b8  8b00                              mov    eax,DWORD PTR [eax]
0x7972ba  85c0                              test   eax,eax
0x7972bc  740f                              je     0x7972cd
0x7972be  50                                push   eax
0x7972bf  e8b24f1000                        call   0x89c276
0x7972c4  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x7972c8  83c404                            add    esp,0x4
0x7972cb  eb06                              jmp    0x7972d3
0x7972cd  d9ee                              fldz
0x7972cf  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x7972d3  d9442414                          fld    DWORD PTR [esp+0x14]
0x7972d7  6814f2c400                        push   0xc4f214
0x7972dc  d95b18                            fstp   DWORD PTR [ebx+0x18]
0x7972df  e8bc8df9ff                        call   0x7300a0
0x7972e4  85c0                              test   eax,eax
0x7972e6  741d                              je     0x797305
0x7972e8  83c030                            add    eax,0x30
0x7972eb  397014                            cmp    DWORD PTR [eax+0x14],esi
0x7972ee  7202                              jb     0x7972f2
0x7972f0  8b00                              mov    eax,DWORD PTR [eax]
0x7972f2  85c0                              test   eax,eax
0x7972f4  740f                              je     0x797305
0x7972f6  50                                push   eax
0x7972f7  e87a4f1000                        call   0x89c276
0x7972fc  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x797300  83c404                            add    esp,0x4
0x797303  eb06                              jmp    0x79730b
0x797305  d9ee                              fldz
0x797307  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x79730b  d9442414                          fld    DWORD PTR [esp+0x14]
0x79730f  681cf2c400                        push   0xc4f21c
0x797314  d95b20                            fstp   DWORD PTR [ebx+0x20]
0x797317  e8848df9ff                        call   0x7300a0
0x79731c  85c0                              test   eax,eax
0x79731e  7419                              je     0x797339
0x797320  83c030                            add    eax,0x30
0x797323  397014                            cmp    DWORD PTR [eax+0x14],esi
0x797326  7202                              jb     0x79732a
0x797328  8b00                              mov    eax,DWORD PTR [eax]
0x79732a  85c0                              test   eax,eax
0x79732c  740b                              je     0x797339
0x79732e  50                                push   eax
0x79732f  e880a40f00                        call   0x8917b4
0x797334  83c404                            add    esp,0x4
0x797337  eb02                              jmp    0x79733b
0x797339  33c0                              xor    eax,eax
0x79733b  89431c                            mov    DWORD PTR [ebx+0x1c],eax
0x79733e  8b7c2420                          mov    edi,DWORD PTR [esp+0x20]
0x797342  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x797345  2b07                              sub    eax,DWORD PTR [edi]
0x797347  c1f802                            sar    eax,0x2
0x79734a  83f801                            cmp    eax,0x1
0x79734d  0f86a0000000                      jbe    0x7973f3
0x797353  8b0f                              mov    ecx,DWORD PTR [edi]
0x797355  8b5481f8                          mov    edx,DWORD PTR [ecx+eax*4-0x8]
0x797359  8b4c81fc                          mov    ecx,DWORD PTR [ecx+eax*4-0x4]
0x79735d  8b7124                            mov    esi,DWORD PTR [ecx+0x24]
0x797360  397324                            cmp    DWORD PTR [ebx+0x24],esi
0x797363  0f858a000000                      jne    0x7973f3
0x797369  d902                              fld    DWORD PTR [edx]
0x79736b  d901                              fld    DWORD PTR [ecx]
0x79736d  dae9                              fucompp
0x79736f  dfe0                              fnstsw ax
0x797371  f6c444                            test   ah,0x44
0x797374  7a6f                              jp     0x7973e5
0x797376  d94204                            fld    DWORD PTR [edx+0x4]
0x797379  d94104                            fld    DWORD PTR [ecx+0x4]
0x79737c  dae9                              fucompp
0x79737e  dfe0                              fnstsw ax
0x797380  f6c444                            test   ah,0x44
0x797383  7a60                              jp     0x7973e5
0x797385  d94208                            fld    DWORD PTR [edx+0x8]
0x797388  d94108                            fld    DWORD PTR [ecx+0x8]
0x79738b  dae9                              fucompp
0x79738d  dfe0                              fnstsw ax
0x79738f  f6c444                            test   ah,0x44
0x797392  7a51                              jp     0x7973e5
0x797394  d9420c                            fld    DWORD PTR [edx+0xc]
0x797397  d9410c                            fld    DWORD PTR [ecx+0xc]
0x79739a  dae9                              fucompp
0x79739c  dfe0                              fnstsw ax
0x79739e  f6c444                            test   ah,0x44
0x7973a1  7a42                              jp     0x7973e5
0x7973a3  d94210                            fld    DWORD PTR [edx+0x10]
0x7973a6  d94110                            fld    DWORD PTR [ecx+0x10]
0x7973a9  dae9                              fucompp
0x7973ab  dfe0                              fnstsw ax
0x7973ad  f6c444                            test   ah,0x44
0x7973b0  7a33                              jp     0x7973e5
0x7973b2  d94218                            fld    DWORD PTR [edx+0x18]
0x7973b5  d94118                            fld    DWORD PTR [ecx+0x18]
0x7973b8  dae9                              fucompp
0x7973ba  dfe0                              fnstsw ax
0x7973bc  f6c444                            test   ah,0x44
0x7973bf  7a24                              jp     0x7973e5
0x7973c1  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x7973c4  3907                              cmp    DWORD PTR [edi],eax
0x7973c6  7406                              je     0x7973ce
0x7973c8  83c0fc                            add    eax,0xfffffffc
0x7973cb  894704                            mov    DWORD PTR [edi+0x4],eax
0x7973ce  8b07                              mov    eax,DWORD PTR [edi]
0x7973d0  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x7973d3  2bc8                              sub    ecx,eax
0x7973d5  c1f902                            sar    ecx,0x2
0x7973d8  8b4488fc                          mov    eax,DWORD PTR [eax+ecx*4-0x4]
0x7973dc  c7401c04000000                    mov    DWORD PTR [eax+0x1c],0x4
0x7973e3  eb0e                              jmp    0x7973f3
0x7973e5  8bc6                              mov    eax,esi
0x7973e7  2b4224                            sub    eax,DWORD PTR [edx+0x24]
0x7973ea  83f801                            cmp    eax,0x1
0x7973ed  7e04                              jle    0x7973f3
0x7973ef  4e                                dec    esi
0x7973f0  897124                            mov    DWORD PTR [ecx+0x24],esi
0x7973f3  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x7973f6  8d4c241c                          lea    ecx,[esp+0x1c]
0x7973fa  3bc8                              cmp    ecx,eax
0x7973fc  732f                              jae    0x79742d
0x7973fe  8b0f                              mov    ecx,DWORD PTR [edi]
0x797400  8d54241c                          lea    edx,[esp+0x1c]
0x797404  3bca                              cmp    ecx,edx
0x797406  7725                              ja     0x79742d
0x797408  8bf2                              mov    esi,edx
0x79740a  2bf1                              sub    esi,ecx
0x79740c  c1fe02                            sar    esi,0x2
0x79740f  3b4708                            cmp    eax,DWORD PTR [edi+0x8]
0x797412  7507                              jne    0x79741b
0x797414  8bc7                              mov    eax,edi
0x797416  e815050000                        call   0x797930
0x79741b  8b07                              mov    eax,DWORD PTR [edi]
0x79741d  8d0cb0                            lea    ecx,[eax+esi*4]
0x797420  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x797423  85c0                              test   eax,eax
0x797425  741b                              je     0x797442
0x797427  8b09                              mov    ecx,DWORD PTR [ecx]
0x797429  8908                              mov    DWORD PTR [eax],ecx
0x79742b  eb15                              jmp    0x797442
0x79742d  3b4708                            cmp    eax,DWORD PTR [edi+0x8]
0x797430  7507                              jne    0x797439
0x797432  8bc7                              mov    eax,edi
0x797434  e8f7040000                        call   0x797930
0x797439  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x79743c  85c0                              test   eax,eax
0x79743e  7402                              je     0x797442
0x797440  8918                              mov    DWORD PTR [eax],ebx
0x797442  8b542418                          mov    edx,DWORD PTR [esp+0x18]
0x797446  83470404                          add    DWORD PTR [edi+0x4],0x4
0x79744a  8b4240                            mov    eax,DWORD PTR [edx+0x40]
0x79744d  89442418                          mov    DWORD PTR [esp+0x18],eax
0x797451  85c0                              test   eax,eax
0x797453  0f8537fbffff                      jne    0x796f90
0x797459  c78424b0000000ffffffff            mov    DWORD PTR [esp+0xb0],0xffffffff
0x797464  83bc248400000010                  cmp    DWORD PTR [esp+0x84],0x10
0x79746c  c74424249423bf00                  mov    DWORD PTR [esp+0x24],0xbf2394
0x797474  720d                              jb     0x797483
0x797476  8b442470                          mov    eax,DWORD PTR [esp+0x70]
0x79747a  50                                push   eax
0x79747b  e88c9d0f00                        call   0x89120c
0x797480  83c404                            add    esp,0x4
0x797483  8d4c2424                          lea    ecx,[esp+0x24]
0x797487  c78424840000000f000000            mov    DWORD PTR [esp+0x84],0xf
0x797492  c784248000000000000000            mov    DWORD PTR [esp+0x80],0x0
0x79749d  c644247000                        mov    BYTE PTR [esp+0x70],0x0
0x7974a2  e8996bf9ff                        call   0x72e040
0x7974a7  8b8c24a8000000                    mov    ecx,DWORD PTR [esp+0xa8]
0x7974ae  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x7974b5  59                                pop    ecx
0x7974b6  5f                                pop    edi
0x7974b7  5e                                pop    esi
0x7974b8  5b                                pop    ebx
0x7974b9  8b8c2490000000                    mov    ecx,DWORD PTR [esp+0x90]
0x7974c0  33cc                              xor    ecx,esp
0x7974c2  e83a9b0f00                        call   0x891001
0x7974c7  8be5                              mov    esp,ebp
0x7974c9  5d                                pop    ebp
0x7974ca  c3                                ret

; C13 Add explicit relative position to each loaded keyframe
; VA 0x7974d0..0x797503 raw 0x3968d0 length 51 SHA256 0e862cb3c9cfe356f5217eab761c49b108f15724a47896f30221d097ef04bc01
0x7974d0  8bcf                              mov    ecx,edi
0x7974d2  e809faffff                        call   0x796ee0
0x7974d7  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x7974da  3b4f08                            cmp    ecx,DWORD PTR [edi+0x8]
0x7974dd  7423                              je     0x797502
0x7974df  90                                nop
0x7974e0  8b01                              mov    eax,DWORD PTR [ecx]
0x7974e2  d900                              fld    DWORD PTR [eax]
0x7974e4  83c104                            add    ecx,0x4
0x7974e7  d806                              fadd   DWORD PTR [esi]
0x7974e9  d918                              fstp   DWORD PTR [eax]
0x7974eb  d94004                            fld    DWORD PTR [eax+0x4]
0x7974ee  d84604                            fadd   DWORD PTR [esi+0x4]
0x7974f1  d95804                            fstp   DWORD PTR [eax+0x4]
0x7974f4  d94608                            fld    DWORD PTR [esi+0x8]
0x7974f7  d84008                            fadd   DWORD PTR [eax+0x8]
0x7974fa  d95808                            fstp   DWORD PTR [eax+0x8]
0x7974fd  3b4f08                            cmp    ecx,DWORD PTR [edi+0x8]
0x797500  75de                              jne    0x7974e0
0x797502  c3                                ret

; C14 Play start and empty-keyframe gate
; VA 0x54e230..0x54e255 raw 0x14d630 length 37 SHA256 ee26a26f5899af5785725e4b4ffc9ef8168363e50319626b275418227935130e
0x54e230  8b410c                            mov    eax,DWORD PTR [ecx+0xc]
0x54e233  2b4108                            sub    eax,DWORD PTR [ecx+0x8]
0x54e236  a9fcffffff                        test   eax,0xfffffffc
0x54e23b  7508                              jne    0x54e245
0x54e23d  c7414000000000                    mov    DWORD PTR [ecx+0x40],0x0
0x54e244  c3                                ret
0x54e245  33c0                              xor    eax,eax
0x54e247  894144                            mov    DWORD PTR [ecx+0x44],eax
0x54e24a  89413c                            mov    DWORD PTR [ecx+0x3c],eax
0x54e24d  c7414001000000                    mov    DWORD PTR [ecx+0x40],0x1
0x54e254  c3                                ret

; C15 Stop clears playing
; VA 0x54e260..0x54e268 raw 0x14d660 length 8 SHA256 31fddf4136f2029aa562bc7ab0769de9f4a8d309753f4ccfe6ecd762c69859b8
0x54e260  c7414000000000                    mov    DWORD PTR [ecx+0x40],0x0
0x54e267  c3                                ret

; C16 KeyFrame frame-count tick then virtual apply
; VA 0x54e270..0x54e2b5 raw 0x14d670 length 69 SHA256 6818f56ac95b1efff2e7778bc962368e401e00f71a47671581bde0f1cde0c19e
0x54e270  56                                push   esi
0x54e271  57                                push   edi
0x54e272  8bf9                              mov    edi,ecx
0x54e274  837f4000                          cmp    DWORD PTR [edi+0x40],0x0
0x54e278  7430                              je     0x54e2aa
0x54e27a  8b470c                            mov    eax,DWORD PTR [edi+0xc]
0x54e27d  2b4708                            sub    eax,DWORD PTR [edi+0x8]
0x54e280  c1f802                            sar    eax,0x2
0x54e283  85c0                              test   eax,eax
0x54e285  7418                              je     0x54e29f
0x54e287  8b4f08                            mov    ecx,DWORD PTR [edi+0x8]
0x54e28a  8b5481fc                          mov    edx,DWORD PTR [ecx+eax*4-0x4]
0x54e28e  8b4224                            mov    eax,DWORD PTR [edx+0x24]
0x54e291  3b4744                            cmp    eax,DWORD PTR [edi+0x44]
0x54e294  7d09                              jge    0x54e29f
0x54e296  c7474000000000                    mov    DWORD PTR [edi+0x40],0x0
0x54e29d  eb0b                              jmp    0x54e2aa
0x54e29f  8d4704                            lea    eax,[edi+0x4]
0x54e2a2  e8e9942400                        call   0x797790
0x54e2a7  ff4744                            inc    DWORD PTR [edi+0x44]
0x54e2aa  8b17                              mov    edx,DWORD PTR [edi]
0x54e2ac  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x54e2af  8bcf                              mov    ecx,edi
0x54e2b1  5f                                pop    edi
0x54e2b2  5e                                pop    esi
0x54e2b3  ffe0                              jmp    eax

; C17 Apply interpolated fields to current camera; post-increment last-frame gate
; VA 0x54e080..0x54e22a raw 0x14d480 length 426 SHA256 ba375e97ee26750da34b8a61957108525a4a5d1581fa82aa02e3421738d08465
0x54e080  55                                push   ebp
0x54e081  8bec                              mov    ebp,esp
0x54e083  6aff                              push   0xffffffff
0x54e085  6896ed9200                        push   0x92ed96
0x54e08a  64a100000000                      mov    eax,fs:0x0
0x54e090  50                                push   eax
0x54e091  53                                push   ebx
0x54e092  56                                push   esi
0x54e093  57                                push   edi
0x54e094  a1201fd600                        mov    eax,ds:0xd61f20
0x54e099  33c5                              xor    eax,ebp
0x54e09b  50                                push   eax
0x54e09c  8d45f4                            lea    eax,[ebp-0xc]
0x54e09f  64a300000000                      mov    fs:0x0,eax
0x54e0a5  8bf1                              mov    esi,ecx
0x54e0a7  33ff                              xor    edi,edi
0x54e0a9  397e40                            cmp    DWORD PTR [esi+0x40],edi
0x54e0ac  0f8466010000                      je     0x54e218
0x54e0b2  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x54e0b5  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x54e0b8  2bc1                              sub    eax,ecx
0x54e0ba  c1f802                            sar    eax,0x2
0x54e0bd  3bc7                              cmp    eax,edi
0x54e0bf  7410                              je     0x54e0d1
0x54e0c1  8b4481fc                          mov    eax,DWORD PTR [ecx+eax*4-0x4]
0x54e0c5  8b4824                            mov    ecx,DWORD PTR [eax+0x24]
0x54e0c8  3b4e44                            cmp    ecx,DWORD PTR [esi+0x44]
0x54e0cb  0f8c47010000                      jl     0x54e218
0x54e0d1  83cbff                            or     ebx,0xffffffff
0x54e0d4  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x54e0db  751f                              jne    0x54e0fc
0x54e0dd  830de879fb0001                    or     DWORD PTR ds:0xfb79e8,0x1
0x54e0e4  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x54e0e7  e8f4ac2400                        call   0x798de0
0x54e0ec  68e0d2bc00                        push   0xbcd2e0
0x54e0f1  e824423400                        call   0x89231a
0x54e0f6  83c404                            add    esp,0x4
0x54e0f9  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x54e0fc  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x54e103  a1e876fb00                        mov    eax,ds:0xfb76e8
0x54e108  8b5618                            mov    edx,DWORD PTR [esi+0x18]
0x54e10b  89500c                            mov    DWORD PTR [eax+0xc],edx
0x54e10e  8b561c                            mov    edx,DWORD PTR [esi+0x1c]
0x54e111  895010                            mov    DWORD PTR [eax+0x10],edx
0x54e114  8b5620                            mov    edx,DWORD PTR [esi+0x20]
0x54e117  8bc8                              mov    ecx,eax
0x54e119  895014                            mov    DWORD PTR [eax+0x14],edx
0x54e11c  89b9cc000000                      mov    DWORD PTR [ecx+0xcc],edi
0x54e122  7523                              jne    0x54e147
0x54e124  b801000000                        mov    eax,0x1
0x54e129  0905e879fb00                      or     DWORD PTR ds:0xfb79e8,eax
0x54e12f  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x54e132  e8a9ac2400                        call   0x798de0
0x54e137  68e0d2bc00                        push   0xbcd2e0
0x54e13c  e8d9413400                        call   0x89231a
0x54e141  83c404                            add    esp,0x4
0x54e144  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x54e147  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x54e14e  a1e876fb00                        mov    eax,ds:0xfb76e8
0x54e153  f30f104624                        movss  xmm0,DWORD PTR [esi+0x24]
0x54e158  f30f114018                        movss  DWORD PTR [eax+0x18],xmm0
0x54e15d  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
0x54e163  7523                              jne    0x54e188
0x54e165  830de879fb0001                    or     DWORD PTR ds:0xfb79e8,0x1
0x54e16c  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x54e173  e868ac2400                        call   0x798de0
0x54e178  68e0d2bc00                        push   0xbcd2e0
0x54e17d  e898413400                        call   0x89231a
0x54e182  83c404                            add    esp,0x4
0x54e185  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x54e188  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x54e18f  a1e876fb00                        mov    eax,ds:0xfb76e8
0x54e194  f30f104628                        movss  xmm0,DWORD PTR [esi+0x28]
0x54e199  f30f114020                        movss  DWORD PTR [eax+0x20],xmm0
0x54e19e  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
0x54e1a4  7523                              jne    0x54e1c9
0x54e1a6  830de879fb0001                    or     DWORD PTR ds:0xfb79e8,0x1
0x54e1ad  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
0x54e1b4  e827ac2400                        call   0x798de0
0x54e1b9  68e0d2bc00                        push   0xbcd2e0
0x54e1be  e857413400                        call   0x89231a
0x54e1c3  83c404                            add    esp,0x4
0x54e1c6  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x54e1c9  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x54e1d0  a1e876fb00                        mov    eax,ds:0xfb76e8
0x54e1d5  f30f10462c                        movss  xmm0,DWORD PTR [esi+0x2c]
0x54e1da  f30f11401c                        movss  DWORD PTR [eax+0x1c],xmm0
0x54e1df  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
0x54e1e5  7520                              jne    0x54e207
0x54e1e7  830de879fb0001                    or     DWORD PTR ds:0xfb79e8,0x1
0x54e1ee  c745fc04000000                    mov    DWORD PTR [ebp-0x4],0x4
0x54e1f5  e8e6ab2400                        call   0x798de0
0x54e1fa  68e0d2bc00                        push   0xbcd2e0
0x54e1ff  e816413400                        call   0x89231a
0x54e204  83c404                            add    esp,0x4
0x54e207  a1e876fb00                        mov    eax,ds:0xfb76e8
0x54e20c  d94630                            fld    DWORD PTR [esi+0x30]
0x54e20f  d95824                            fstp   DWORD PTR [eax+0x24]
0x54e212  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
0x54e218  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x54e21b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x54e222  59                                pop    ecx
0x54e223  5f                                pop    edi
0x54e224  5e                                pop    esi
0x54e225  5b                                pop    ebx
0x54e226  8be5                              mov    esp,ebp
0x54e228  5d                                pop    ebp
0x54e229  c3                                ret

; C18 Get current frame
; VA 0x54e2c0..0x54e2c4 raw 0x14d6c0 length 4 SHA256 75315a13a7503cb9a126675518a19ff201faa8c510e8a849d0f971d9c61bbb2b
0x54e2c0  8b4144                            mov    eax,DWORD PTR [ecx+0x44]
0x54e2c3  c3                                ret

; C19 Set current frame with upper clamp only
; VA 0x54e2d0..0x54e30c raw 0x14d6d0 length 60 SHA256 8ec7b2c14f3d98538ebd86fc678012cc44908783693595ae7f9d37c2a37a4396
0x54e2d0  55                                push   ebp
0x54e2d1  8bec                              mov    ebp,esp
0x54e2d3  8b410c                            mov    eax,DWORD PTR [ecx+0xc]
0x54e2d6  2b4108                            sub    eax,DWORD PTR [ecx+0x8]
0x54e2d9  a9fcffffff                        test   eax,0xfffffffc
0x54e2de  7428                              je     0x54e308
0x54e2e0  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x54e2e3  56                                push   esi
0x54e2e4  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x54e2e7  897144                            mov    DWORD PTR [ecx+0x44],esi
0x54e2ea  8b410c                            mov    eax,DWORD PTR [ecx+0xc]
0x54e2ed  2b4108                            sub    eax,DWORD PTR [ecx+0x8]
0x54e2f0  c1f802                            sar    eax,0x2
0x54e2f3  8b5482fc                          mov    edx,DWORD PTR [edx+eax*4-0x4]
0x54e2f7  8b5224                            mov    edx,DWORD PTR [edx+0x24]
0x54e2fa  3bd6                              cmp    edx,esi
0x54e2fc  5e                                pop    esi
0x54e2fd  7f09                              jg     0x54e308
0x54e2ff  f7d8                              neg    eax
0x54e301  1bc0                              sbb    eax,eax
0x54e303  23c2                              and    eax,edx
0x54e305  894144                            mov    DWORD PTR [ecx+0x44],eax
0x54e308  5d                                pop    ebp
0x54e309  c20400                            ret    0x4

; C20 IsEnded tests playing/current/last frame
; VA 0x54e310..0x54e33a raw 0x14d710 length 42 SHA256 a3aef4609b88cfa012499810aaccd9a8d63737b321a2bbd368cfaf74b27ace74
0x54e310  83794000                          cmp    DWORD PTR [ecx+0x40],0x0
0x54e314  741e                              je     0x54e334
0x54e316  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x54e319  8b410c                            mov    eax,DWORD PTR [ecx+0xc]
0x54e31c  2bc2                              sub    eax,edx
0x54e31e  c1f802                            sar    eax,0x2
0x54e321  85c0                              test   eax,eax
0x54e323  740c                              je     0x54e331
0x54e325  8b4482fc                          mov    eax,DWORD PTR [edx+eax*4-0x4]
0x54e329  8b5024                            mov    edx,DWORD PTR [eax+0x24]
0x54e32c  3b5144                            cmp    edx,DWORD PTR [ecx+0x44]
0x54e32f  7c03                              jl     0x54e334
0x54e331  33c0                              xor    eax,eax
0x54e333  c3                                ret
0x54e334  b801000000                        mov    eax,0x1
0x54e339  c3                                ret

; C21 KeyFrame segment selection and interpolation
; VA 0x797790..0x79792a raw 0x396b90 length 410 SHA256 4f0baed52247e3da732c2dd8864c74a36bb3389ae0451787c6988eec1960b3bf
0x797790  55                                push   ebp
0x797791  8bec                              mov    ebp,esp
0x797793  83ec14                            sub    esp,0x14
0x797796  56                                push   esi
0x797797  57                                push   edi
0x797798  8bf8                              mov    edi,eax
0x79779a  8b4f08                            mov    ecx,DWORD PTR [edi+0x8]
0x79779d  2b4f04                            sub    ecx,DWORD PTR [edi+0x4]
0x7977a0  33c0                              xor    eax,eax
0x7977a2  f7c1fcffffff                      test   ecx,0xfffffffc
0x7977a8  7e21                              jle    0x7977cb
0x7977aa  8b5740                            mov    edx,DWORD PTR [edi+0x40]
0x7977ad  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x7977b0  8b31                              mov    esi,DWORD PTR [ecx]
0x7977b2  395624                            cmp    DWORD PTR [esi+0x24],edx
0x7977b5  7f14                              jg     0x7977cb
0x7977b7  894738                            mov    DWORD PTR [edi+0x38],eax
0x7977ba  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x7977bd  2b7704                            sub    esi,DWORD PTR [edi+0x4]
0x7977c0  40                                inc    eax
0x7977c1  c1fe02                            sar    esi,0x2
0x7977c4  83c104                            add    ecx,0x4
0x7977c7  3bc6                              cmp    eax,esi
0x7977c9  7ce5                              jl     0x7977b0
0x7977cb  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x7977ce  2b4704                            sub    eax,DWORD PTR [edi+0x4]
0x7977d1  c1f802                            sar    eax,0x2
0x7977d4  85c0                              test   eax,eax
0x7977d6  740b                              je     0x7977e3
0x7977d8  8b5738                            mov    edx,DWORD PTR [edi+0x38]
0x7977db  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x7977de  8b1491                            mov    edx,DWORD PTR [ecx+edx*4]
0x7977e1  eb02                              jmp    0x7977e5
0x7977e3  33d2                              xor    edx,edx
0x7977e5  8b4f38                            mov    ecx,DWORD PTR [edi+0x38]
0x7977e8  8d7101                            lea    esi,[ecx+0x1]
0x7977eb  3bf0                              cmp    esi,eax
0x7977ed  7d09                              jge    0x7977f8
0x7977ef  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x7977f2  8b748804                          mov    esi,DWORD PTR [eax+ecx*4+0x4]
0x7977f6  eb02                              jmp    0x7977fa
0x7977f8  33f6                              xor    esi,esi
0x7977fa  85d2                              test   edx,edx
0x7977fc  7508                              jne    0x797806
0x7977fe  5f                                pop    edi
0x7977ff  33c0                              xor    eax,eax
0x797801  5e                                pop    esi
0x797802  8be5                              mov    esp,ebp
0x797804  5d                                pop    ebp
0x797805  c3                                ret
0x797806  8b4a24                            mov    ecx,DWORD PTR [edx+0x24]
0x797809  8b4740                            mov    eax,DWORD PTR [edi+0x40]
0x79780c  3bc8                              cmp    ecx,eax
0x79780e  0f84ff000000                      je     0x797913
0x797814  837a1c04                          cmp    DWORD PTR [edx+0x1c],0x4
0x797818  0f84f5000000                      je     0x797913
0x79781e  85f6                              test   esi,esi
0x797820  0f84f9000000                      je     0x79791f
0x797826  3bc8                              cmp    ecx,eax
0x797828  0f8df1000000                      jge    0x79791f
0x79782e  8b4e24                            mov    ecx,DWORD PTR [esi+0x24]
0x797831  3bc1                              cmp    eax,ecx
0x797833  0f8de6000000                      jge    0x79791f
0x797839  d94220                            fld    DWORD PTR [edx+0x20]
0x79783c  53                                push   ebx
0x79783d  8b5a1c                            mov    ebx,DWORD PTR [edx+0x1c]
0x797840  51                                push   ecx
0x797841  d91c24                            fstp   DWORD PTR [esp]
0x797844  53                                push   ebx
0x797845  8b5a24                            mov    ebx,DWORD PTR [edx+0x24]
0x797848  2bc3                              sub    eax,ebx
0x79784a  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x79784d  db45fc                            fild   DWORD PTR [ebp-0x4]
0x797850  2bcb                              sub    ecx,ebx
0x797852  894dfc                            mov    DWORD PTR [ebp-0x4],ecx
0x797855  51                                push   ecx
0x797856  da75fc                            fidiv  DWORD PTR [ebp-0x4]
0x797859  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x79785c  d945fc                            fld    DWORD PTR [ebp-0x4]
0x79785f  d91c24                            fstp   DWORD PTR [esp]
0x797862  e809feffff                        call   0x797670
0x797867  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x79786a  d945fc                            fld    DWORD PTR [ebp-0x4]
0x79786d  83c408                            add    esp,0x8
0x797870  8d4dec                            lea    ecx,[ebp-0x14]
0x797873  d91c24                            fstp   DWORD PTR [esp]
0x797876  51                                push   ecx
0x797877  8bce                              mov    ecx,esi
0x797879  e8e2fcffff                        call   0x797560
0x79787e  8b08                              mov    ecx,DWORD PTR [eax]
0x797880  894f14                            mov    DWORD PTR [edi+0x14],ecx
0x797883  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x797886  894f18                            mov    DWORD PTR [edi+0x18],ecx
0x797889  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x79788c  89471c                            mov    DWORD PTR [edi+0x1c],eax
0x79788f  d9420c                            fld    DWORD PTR [edx+0xc]
0x797892  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x797895  83c408                            add    esp,0x8
0x797898  d9460c                            fld    DWORD PTR [esi+0xc]
0x79789b  5b                                pop    ebx
0x79789c  d945f8                            fld    DWORD PTR [ebp-0x8]
0x79789f  b801000000                        mov    eax,0x1
0x7978a4  d9c0                              fld    st(0)
0x7978a6  deea                              fsubp  st(2),st
0x7978a8  d945fc                            fld    DWORD PTR [ebp-0x4]
0x7978ab  d9c0                              fld    st(0)
0x7978ad  decb                              fmulp  st(3),st
0x7978af  d9ca                              fxch   st(2)
0x7978b1  dec1                              faddp  st(1),st
0x7978b3  d95f20                            fstp   DWORD PTR [edi+0x20]
0x7978b6  d94210                            fld    DWORD PTR [edx+0x10]
0x7978b9  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x7978bc  d94610                            fld    DWORD PTR [esi+0x10]
0x7978bf  d945f8                            fld    DWORD PTR [ebp-0x8]
0x7978c2  d9c0                              fld    st(0)
0x7978c4  deea                              fsubp  st(2),st
0x7978c6  d9c2                              fld    st(2)
0x7978c8  deca                              fmulp  st(2),st
0x7978ca  dec1                              faddp  st(1),st
0x7978cc  d95f24                            fstp   DWORD PTR [edi+0x24]
0x7978cf  d94214                            fld    DWORD PTR [edx+0x14]
0x7978d2  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x7978d5  d94614                            fld    DWORD PTR [esi+0x14]
0x7978d8  d945f8                            fld    DWORD PTR [ebp-0x8]
0x7978db  d9c0                              fld    st(0)
0x7978dd  deea                              fsubp  st(2),st
0x7978df  d9c2                              fld    st(2)
0x7978e1  deca                              fmulp  st(2),st
0x7978e3  dec1                              faddp  st(1),st
0x7978e5  d95f28                            fstp   DWORD PTR [edi+0x28]
0x7978e8  d94218                            fld    DWORD PTR [edx+0x18]
0x7978eb  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x7978ee  d94618                            fld    DWORD PTR [esi+0x18]
0x7978f1  d945f8                            fld    DWORD PTR [ebp-0x8]
0x7978f4  d9c0                              fld    st(0)
0x7978f6  deea                              fsubp  st(2),st
0x7978f8  d9c9                              fxch   st(1)
0x7978fa  deca                              fmulp  st(2),st
0x7978fc  dec1                              faddp  st(1),st
0x7978fe  d95f2c                            fstp   DWORD PTR [edi+0x2c]
0x797901  8b4a1c                            mov    ecx,DWORD PTR [edx+0x1c]
0x797904  894f30                            mov    DWORD PTR [edi+0x30],ecx
0x797907  d94220                            fld    DWORD PTR [edx+0x20]
0x79790a  d95f34                            fstp   DWORD PTR [edi+0x34]
0x79790d  5f                                pop    edi
0x79790e  5e                                pop    esi
0x79790f  8be5                              mov    esp,ebp
0x797911  5d                                pop    ebp
0x797912  c3                                ret
0x797913  83c714                            add    edi,0x14
0x797916  b909000000                        mov    ecx,0x9
0x79791b  8bf2                              mov    esi,edx
0x79791d  f3a5                              rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x79791f  5f                                pop    edi
0x797920  b801000000                        mov    eax,0x1
0x797925  5e                                pop    esi
0x797926  8be5                              mov    esp,ebp
0x797928  5d                                pop    ebp
0x797929  c3                                ret

; C23 Lazy initialized CameraWorks current-pointer accessor
; VA 0x434130..0x4341fb raw 0x33530 length 203 SHA256 6d438bd501a0e931dc41f7e06eeec66da6515dd7a9b4fb550df4911eb6d1d33c
0x434130  55                                push   ebp
0x434131  8bec                              mov    ebp,esp
0x434133  83e4f8                            and    esp,0xfffffff8
0x434136  6aff                              push   0xffffffff
0x434138  68dea99300                        push   0x93a9de
0x43413d  64a100000000                      mov    eax,fs:0x0
0x434143  50                                push   eax
0x434144  51                                push   ecx
0x434145  a1201fd600                        mov    eax,ds:0xd61f20
0x43414a  33c4                              xor    eax,esp
0x43414c  50                                push   eax
0x43414d  8d442408                          lea    eax,[esp+0x8]
0x434151  64a300000000                      mov    fs:0x0,eax
0x434157  b801000000                        mov    eax,0x1
0x43415c  84051c76fb00                      test   BYTE PTR ds:0xfb761c,al
0x434162  7520                              jne    0x434184
0x434164  09051c76fb00                      or     DWORD PTR ds:0xfb761c,eax
0x43416a  c744241000000000                  mov    DWORD PTR [esp+0x10],0x0
0x434172  e8d9a51100                        call   0x54e750
0x434177  6860d2bc00                        push   0xbcd260
0x43417c  e899e14500                        call   0x89231a
0x434181  83c404                            add    esp,0x4
0x434184  b82076fb00                        mov    eax,0xfb7620
0x434189  8b4c2408                          mov    ecx,DWORD PTR [esp+0x8]
0x43418d  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x434194  59                                pop    ecx
0x434195  8be5                              mov    esp,ebp
0x434197  5d                                pop    ebp
0x434198  c3                                ret
0x434199  cc                                int3
0x43419a  cc                                int3
0x43419b  cc                                int3
0x43419c  cc                                int3
0x43419d  cc                                int3
0x43419e  cc                                int3
0x43419f  cc                                int3
0x4341a0  57                                push   edi
0x4341a1  bf2c76fb00                        mov    edi,0xfb762c
0x4341a6  c7056c76fb00d497bf00              mov    DWORD PTR ds:0xfb766c,0xbf97d4
0x4341b0  c7052876fb002cf2c400              mov    DWORD PTR ds:0xfb7628,0xc4f22c
0x4341ba  e841383600                        call   0x797a00
0x4341bf  a12c76fb00                        mov    eax,ds:0xfb762c
0x4341c4  5f                                pop    edi
0x4341c5  85c0                              test   eax,eax
0x4341c7  7409                              je     0x4341d2
0x4341c9  50                                push   eax
0x4341ca  e83dd04500                        call   0x89120c
0x4341cf  83c404                            add    esp,0x4
0x4341d2  c7052c76fb0000000000              mov    DWORD PTR ds:0xfb762c,0x0
0x4341dc  c7053076fb0000000000              mov    DWORD PTR ds:0xfb7630,0x0
0x4341e6  c7053476fb0000000000              mov    DWORD PTR ds:0xfb7634,0x0
0x4341f0  c7052476fb00d497bf00              mov    DWORD PTR ds:0xfb7624,0xbf97d4
0x4341fa  c3                                ret

; C25 Camera transform consumes position, angles, distance and effect offset
; VA 0x797ec0..0x798083 raw 0x3972c0 length 451 SHA256 4b9d24b441631cd88d83540e903b774f3a85010fdbced7d66ca7e68f4bb68ae8
0x797ec0  55                                push   ebp
0x797ec1  8bec                              mov    ebp,esp
0x797ec3  83e4f8                            and    esp,0xfffffff8
0x797ec6  6aff                              push   0xffffffff
0x797ec8  68de269300                        push   0x9326de
0x797ecd  64a100000000                      mov    eax,fs:0x0
0x797ed3  50                                push   eax
0x797ed4  83ec60                            sub    esp,0x60
0x797ed7  56                                push   esi
0x797ed8  a1201fd600                        mov    eax,ds:0xd61f20
0x797edd  33c4                              xor    eax,esp
0x797edf  50                                push   eax
0x797ee0  8d442468                          lea    eax,[esp+0x68]
0x797ee4  64a300000000                      mov    fs:0x0,eax
0x797eea  d94724                            fld    DWORD PTR [edi+0x24]
0x797eed  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x797ef0  d95c2408                          fstp   DWORD PTR [esp+0x8]
0x797ef4  83ec0c                            sub    esp,0xc
0x797ef7  d9442414                          fld    DWORD PTR [esp+0x14]
0x797efb  d95c2408                          fstp   DWORD PTR [esp+0x8]
0x797eff  d9ee                              fldz
0x797f01  d9542404                          fst    DWORD PTR [esp+0x4]
0x797f05  d91c24                            fstp   DWORD PTR [esp]
0x797f08  e82371feff                        call   0x77f030
0x797f0d  d9ee                              fldz
0x797f0f  d9542420                          fst    DWORD PTR [esp+0x20]
0x797f13  6a34                              push   0x34
0x797f15  d9542428                          fst    DWORD PTR [esp+0x28]
0x797f19  8d442434                          lea    eax,[esp+0x34]
0x797f1d  d95c242c                          fstp   DWORD PTR [esp+0x2c]
0x797f21  6a00                              push   0x0
0x797f23  d9e8                              fld1
0x797f25  50                                push   eax
0x797f26  d95c2438                          fstp   DWORD PTR [esp+0x38]
0x797f2a  d94720                            fld    DWORD PTR [edi+0x20]
0x797f2d  d95c241c                          fstp   DWORD PTR [esp+0x1c]
0x797f31  d9471c                            fld    DWORD PTR [edi+0x1c]
0x797f34  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x797f38  d94718                            fld    DWORD PTR [edi+0x18]
0x797f3b  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x797f3f  e81c691000                        call   0x89e860
0x797f44  d9e8                              fld1
0x797f46  d954245c                          fst    DWORD PTR [esp+0x5c]
0x797f4a  83c408                            add    esp,0x8
0x797f4d  d9542444                          fst    DWORD PTR [esp+0x44]
0x797f51  8d742434                          lea    esi,[esp+0x34]
0x797f55  d95c2434                          fstp   DWORD PTR [esp+0x34]
0x797f59  d944240c                          fld    DWORD PTR [esp+0xc]
0x797f5d  d91c24                            fstp   DWORD PTR [esp]
0x797f60  e85b8effff                        call   0x790dc0
0x797f65  d944240c                          fld    DWORD PTR [esp+0xc]
0x797f69  51                                push   ecx
0x797f6a  d91c24                            fstp   DWORD PTR [esp]
0x797f6d  e81e8fffff                        call   0x790e90
0x797f72  d9442410                          fld    DWORD PTR [esp+0x10]
0x797f76  51                                push   ecx
0x797f77  d91c24                            fstp   DWORD PTR [esp]
0x797f7a  e8e18fffff                        call   0x790f60
0x797f7f  8d4c2420                          lea    ecx,[esp+0x20]
0x797f83  e80889feff                        call   0x780890
0x797f88  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x797f8b  8d542420                          lea    edx,[esp+0x20]
0x797f8f  e82c70feff                        call   0x77efc0
0x797f94  d94728                            fld    DWORD PTR [edi+0x28]
0x797f97  8b4714                            mov    eax,DWORD PTR [edi+0x14]
0x797f9a  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x797f9e  8b4f0c                            mov    ecx,DWORD PTR [edi+0xc]
0x797fa1  8b5710                            mov    edx,DWORD PTR [edi+0x10]
0x797fa4  8944241c                          mov    DWORD PTR [esp+0x1c],eax
0x797fa8  d944241c                          fld    DWORD PTR [esp+0x1c]
0x797fac  d8442410                          fadd   DWORD PTR [esp+0x10]
0x797fb0  894c2414                          mov    DWORD PTR [esp+0x14],ecx
0x797fb4  894c2414                          mov    DWORD PTR [esp+0x14],ecx
0x797fb8  89542424                          mov    DWORD PTR [esp+0x24],edx
0x797fbc  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x797fc0  89542418                          mov    DWORD PTR [esp+0x18],edx
0x797fc4  d9442414                          fld    DWORD PTR [esp+0x14]
0x797fc8  89542418                          mov    DWORD PTR [esp+0x18],edx
0x797fcc  d95c2414                          fstp   DWORD PTR [esp+0x14]
0x797fd0  8944241c                          mov    DWORD PTR [esp+0x1c],eax
0x797fd4  d9442424                          fld    DWORD PTR [esp+0x24]
0x797fd8  894c2420                          mov    DWORD PTR [esp+0x20],ecx
0x797fdc  8b4c2414                          mov    ecx,DWORD PTR [esp+0x14]
0x797fe0  d95c2418                          fstp   DWORD PTR [esp+0x18]
0x797fe4  d9442410                          fld    DWORD PTR [esp+0x10]
0x797fe8  8b542418                          mov    edx,DWORD PTR [esp+0x18]
0x797fec  89442428                          mov    DWORD PTR [esp+0x28],eax
0x797ff0  d95c241c                          fstp   DWORD PTR [esp+0x1c]
0x797ff4  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x797ff7  894868                            mov    DWORD PTR [eax+0x68],ecx
0x797ffa  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
0x797ffe  89506c                            mov    DWORD PTR [eax+0x6c],edx
0x798001  894870                            mov    DWORD PTR [eax+0x70],ecx
0x798004  c780c000000000000000              mov    DWORD PTR [eax+0xc0],0x0
0x79800e  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x798011  8b5030                            mov    edx,DWORD PTR [eax+0x30]
0x798014  52                                push   edx
0x798015  50                                push   eax
0x798016  e83581feff                        call   0x780150
0x79801b  d94724                            fld    DWORD PTR [edi+0x24]
0x79801e  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x798022  b801000000                        mov    eax,0x1
0x798027  d9442410                          fld    DWORD PTR [esp+0x10]
0x79802b  d99fd4000000                      fstp   DWORD PTR [edi+0xd4]
0x798031  8405e879fb00                      test   BYTE PTR ds:0xfb79e8,al
0x798037  7528                              jne    0x798061
0x798039  0905e879fb00                      or     DWORD PTR ds:0xfb79e8,eax
0x79803f  c744247000000000                  mov    DWORD PTR [esp+0x70],0x0
0x798047  e8940d0000                        call   0x798de0
0x79804c  68e0d2bc00                        push   0xbcd2e0
0x798051  e8c4a20f00                        call   0x89231a
0x798056  83c404                            add    esp,0x4
0x798059  c7442470ffffffff                  mov    DWORD PTR [esp+0x70],0xffffffff
0x798061  8b4f08                            mov    ecx,DWORD PTR [edi+0x8]
0x798064  8b01                              mov    eax,DWORD PTR [ecx]
0x798066  8b15a876fb00                      mov    edx,DWORD PTR ds:0xfb76a8
0x79806c  8b4028                            mov    eax,DWORD PTR [eax+0x28]
0x79806f  52                                push   edx
0x798070  ffd0                              call   eax
0x798072  8b4c2468                          mov    ecx,DWORD PTR [esp+0x68]
0x798076  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x79807d  59                                pop    ecx
0x79807e  5e                                pop    esi
0x79807f  8be5                              mov    esp,ebp
0x798081  5d                                pop    ebp
0x798082  c3                                ret

; C26 X-axis rotation uses raw radians
; VA 0x790dc0..0x790e8c raw 0x3901c0 length 204 SHA256 c2fbaa3ac4fe1388d9c11a6f90d1659fc0d95f70ceb83026660d023088b27632
0x790dc0  55                                push   ebp
0x790dc1  8bec                              mov    ebp,esp
0x790dc3  83e4f8                            and    esp,0xfffffff8
0x790dc6  d94508                            fld    DWORD PTR [ebp+0x8]
0x790dc9  83ec10                            sub    esp,0x10
0x790dcc  d9c0                              fld    st(0)
0x790dce  d9ee                              fldz
0x790dd0  dae9                              fucompp
0x790dd2  dfe0                              fnstsw ax
0x790dd4  f6c444                            test   ah,0x44
0x790dd7  0f8ba7000000                      jnp    0x790e84
0x790ddd  e8bee21600                        call   0x8ff0a0
0x790de2  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x790de6  d9442404                          fld    DWORD PTR [esp+0x4]
0x790dea  dd5c2408                          fstp   QWORD PTR [esp+0x8]
0x790dee  d94508                            fld    DWORD PTR [ebp+0x8]
0x790df1  e87ae11600                        call   0x8fef70
0x790df6  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x790dfa  d9442404                          fld    DWORD PTR [esp+0x4]
0x790dfe  d94604                            fld    DWORD PTR [esi+0x4]
0x790e01  d8c9                              fmul   st,st(1)
0x790e03  d94608                            fld    DWORD PTR [esi+0x8]
0x790e06  dd442408                          fld    QWORD PTR [esp+0x8]
0x790e0a  dcc9                              fmul   st(1),st
0x790e0c  d9ca                              fxch   st(2)
0x790e0e  dee1                              fsubrp st(1),st
0x790e10  d94604                            fld    DWORD PTR [esi+0x4]
0x790e13  d8ca                              fmul   st,st(2)
0x790e15  d94608                            fld    DWORD PTR [esi+0x8]
0x790e18  d8cc                              fmul   st,st(4)
0x790e1a  dec1                              faddp  st(1),st
0x790e1c  d95e08                            fstp   DWORD PTR [esi+0x8]
0x790e1f  d95e04                            fstp   DWORD PTR [esi+0x4]
0x790e22  d94610                            fld    DWORD PTR [esi+0x10]
0x790e25  d8ca                              fmul   st,st(2)
0x790e27  d94614                            fld    DWORD PTR [esi+0x14]
0x790e2a  d8ca                              fmul   st,st(2)
0x790e2c  dee9                              fsubp  st(1),st
0x790e2e  d94614                            fld    DWORD PTR [esi+0x14]
0x790e31  d8cb                              fmul   st,st(3)
0x790e33  d94610                            fld    DWORD PTR [esi+0x10]
0x790e36  d8cb                              fmul   st,st(3)
0x790e38  dec1                              faddp  st(1),st
0x790e3a  d95e14                            fstp   DWORD PTR [esi+0x14]
0x790e3d  d95e10                            fstp   DWORD PTR [esi+0x10]
0x790e40  d9461c                            fld    DWORD PTR [esi+0x1c]
0x790e43  d8ca                              fmul   st,st(2)
0x790e45  d94620                            fld    DWORD PTR [esi+0x20]
0x790e48  d8ca                              fmul   st,st(2)
0x790e4a  dee9                              fsubp  st(1),st
0x790e4c  d94620                            fld    DWORD PTR [esi+0x20]
0x790e4f  d8cb                              fmul   st,st(3)
0x790e51  d9461c                            fld    DWORD PTR [esi+0x1c]
0x790e54  d8cb                              fmul   st,st(3)
0x790e56  dec1                              faddp  st(1),st
0x790e58  d95e20                            fstp   DWORD PTR [esi+0x20]
0x790e5b  d95e1c                            fstp   DWORD PTR [esi+0x1c]
0x790e5e  d94628                            fld    DWORD PTR [esi+0x28]
0x790e61  d8ca                              fmul   st,st(2)
0x790e63  d9462c                            fld    DWORD PTR [esi+0x2c]
0x790e66  d8ca                              fmul   st,st(2)
0x790e68  dee9                              fsubp  st(1),st
0x790e6a  d9462c                            fld    DWORD PTR [esi+0x2c]
0x790e6d  decb                              fmulp  st(3),st
0x790e6f  d94628                            fld    DWORD PTR [esi+0x28]
0x790e72  deca                              fmulp  st(2),st
0x790e74  d9ca                              fxch   st(2)
0x790e76  dec1                              faddp  st(1),st
0x790e78  d95e2c                            fstp   DWORD PTR [esi+0x2c]
0x790e7b  d95e28                            fstp   DWORD PTR [esi+0x28]
0x790e7e  8be5                              mov    esp,ebp
0x790e80  5d                                pop    ebp
0x790e81  c20400                            ret    0x4
0x790e84  ddd8                              fstp   st(0)
0x790e86  8be5                              mov    esp,ebp
0x790e88  5d                                pop    ebp
0x790e89  c20400                            ret    0x4

; C27 Z-axis rotation uses raw radians
; VA 0x790f60..0x791029 raw 0x390360 length 201 SHA256 b6049b75cdf6c87887ab93a332c2d051a49dea0946de0e3680696b69f54f81ae
0x790f60  55                                push   ebp
0x790f61  8bec                              mov    ebp,esp
0x790f63  83e4f8                            and    esp,0xfffffff8
0x790f66  d94508                            fld    DWORD PTR [ebp+0x8]
0x790f69  83ec10                            sub    esp,0x10
0x790f6c  d9c0                              fld    st(0)
0x790f6e  d9ee                              fldz
0x790f70  dae9                              fucompp
0x790f72  dfe0                              fnstsw ax
0x790f74  f6c444                            test   ah,0x44
0x790f77  0f8ba4000000                      jnp    0x791021
0x790f7d  e81ee11600                        call   0x8ff0a0
0x790f82  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x790f86  d9442404                          fld    DWORD PTR [esp+0x4]
0x790f8a  dd5c2408                          fstp   QWORD PTR [esp+0x8]
0x790f8e  d94508                            fld    DWORD PTR [ebp+0x8]
0x790f91  e8dadf1600                        call   0x8fef70
0x790f96  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x790f9a  d9442404                          fld    DWORD PTR [esp+0x4]
0x790f9e  d906                              fld    DWORD PTR [esi]
0x790fa0  d8c9                              fmul   st,st(1)
0x790fa2  d94604                            fld    DWORD PTR [esi+0x4]
0x790fa5  dd442408                          fld    QWORD PTR [esp+0x8]
0x790fa9  dcc9                              fmul   st(1),st
0x790fab  d9ca                              fxch   st(2)
0x790fad  dee1                              fsubrp st(1),st
0x790faf  d94604                            fld    DWORD PTR [esi+0x4]
0x790fb2  d8cb                              fmul   st,st(3)
0x790fb4  d906                              fld    DWORD PTR [esi]
0x790fb6  d8cb                              fmul   st,st(3)
0x790fb8  dec1                              faddp  st(1),st
0x790fba  d95e04                            fstp   DWORD PTR [esi+0x4]
0x790fbd  d91e                              fstp   DWORD PTR [esi]
0x790fbf  d9460c                            fld    DWORD PTR [esi+0xc]
0x790fc2  d8ca                              fmul   st,st(2)
0x790fc4  d94610                            fld    DWORD PTR [esi+0x10]
0x790fc7  d8ca                              fmul   st,st(2)
0x790fc9  dee9                              fsubp  st(1),st
0x790fcb  d9460c                            fld    DWORD PTR [esi+0xc]
0x790fce  d8ca                              fmul   st,st(2)
0x790fd0  d94610                            fld    DWORD PTR [esi+0x10]
0x790fd3  d8cc                              fmul   st,st(4)
0x790fd5  dec1                              faddp  st(1),st
0x790fd7  d95e10                            fstp   DWORD PTR [esi+0x10]
0x790fda  d95e0c                            fstp   DWORD PTR [esi+0xc]
0x790fdd  d94618                            fld    DWORD PTR [esi+0x18]
0x790fe0  d8ca                              fmul   st,st(2)
0x790fe2  d9461c                            fld    DWORD PTR [esi+0x1c]
0x790fe5  d8ca                              fmul   st,st(2)
0x790fe7  dee9                              fsubp  st(1),st
0x790fe9  d9461c                            fld    DWORD PTR [esi+0x1c]
0x790fec  d8cb                              fmul   st,st(3)
0x790fee  d94618                            fld    DWORD PTR [esi+0x18]
0x790ff1  d8cb                              fmul   st,st(3)
0x790ff3  dec1                              faddp  st(1),st
0x790ff5  d95e1c                            fstp   DWORD PTR [esi+0x1c]
0x790ff8  d95e18                            fstp   DWORD PTR [esi+0x18]
0x790ffb  d94624                            fld    DWORD PTR [esi+0x24]
0x790ffe  d8ca                              fmul   st,st(2)
0x791000  d94628                            fld    DWORD PTR [esi+0x28]
0x791003  d8ca                              fmul   st,st(2)
0x791005  dee9                              fsubp  st(1),st
0x791007  d94628                            fld    DWORD PTR [esi+0x28]
0x79100a  decb                              fmulp  st(3),st
0x79100c  d94624                            fld    DWORD PTR [esi+0x24]
0x79100f  deca                              fmulp  st(2),st
0x791011  d9ca                              fxch   st(2)
0x791013  dec1                              faddp  st(1),st
0x791015  d95e28                            fstp   DWORD PTR [esi+0x28]
0x791018  d95e24                            fstp   DWORD PTR [esi+0x24]
0x79101b  8be5                              mov    esp,ebp
0x79101d  5d                                pop    ebp
0x79101e  c20400                            ret    0x4
0x791021  ddd8                              fstp   st(0)
0x791023  8be5                              mov    esp,ebp
0x791025  5d                                pop    ebp
0x791026  c20400                            ret    0x4

; C28 Local XYZ translation including camera distance
; VA 0x77f030..0x77f08d raw 0x37e430 length 93 SHA256 3528e21e2d15d651b0300e9050afe72616e9cd13b3040a1452cc45e4e370a964
0x77f030  55                                push   ebp
0x77f031  8bec                              mov    ebp,esp
0x77f033  d94168                            fld    DWORD PTR [ecx+0x68]
0x77f036  d94508                            fld    DWORD PTR [ebp+0x8]
0x77f039  d9c0                              fld    st(0)
0x77f03b  ddea                              fucomp st(2)
0x77f03d  dfe0                              fnstsw ax
0x77f03f  ddd9                              fstp   st(1)
0x77f041  d94510                            fld    DWORD PTR [ebp+0x10]
0x77f044  d9450c                            fld    DWORD PTR [ebp+0xc]
0x77f047  f6c444                            test   ah,0x44
0x77f04a  7a1c                              jp     0x77f068
0x77f04c  d9416c                            fld    DWORD PTR [ecx+0x6c]
0x77f04f  d9c1                              fld    st(1)
0x77f051  dae9                              fucompp
0x77f053  dfe0                              fnstsw ax
0x77f055  f6c444                            test   ah,0x44
0x77f058  7a0e                              jp     0x77f068
0x77f05a  d94170                            fld    DWORD PTR [ecx+0x70]
0x77f05d  d9c2                              fld    st(2)
0x77f05f  dae9                              fucompp
0x77f061  dfe0                              fnstsw ax
0x77f063  f6c444                            test   ah,0x44
0x77f066  7b1b                              jnp    0x77f083
0x77f068  d9ca                              fxch   st(2)
0x77f06a  c781c000000000000000              mov    DWORD PTR [ecx+0xc0],0x0
0x77f074  d95968                            fstp   DWORD PTR [ecx+0x68]
0x77f077  d9c9                              fxch   st(1)
0x77f079  d9596c                            fstp   DWORD PTR [ecx+0x6c]
0x77f07c  d95970                            fstp   DWORD PTR [ecx+0x70]
0x77f07f  5d                                pop    ebp
0x77f080  c20c00                            ret    0xc
0x77f083  ddda                              fstp   st(2)
0x77f085  ddd8                              fstp   st(0)
0x77f087  ddd8                              fstp   st(0)
0x77f089  5d                                pop    ebp
0x77f08a  c20c00                            ret    0xc

; C30 CameraEffect type10 fixed-capacity registration
; VA 0x5650c0..0x565135 raw 0x1644c0 length 117 SHA256 f99dcc981a129b8843b69d0b66c3fe699be822623d1471d06167c0c10d967a64
0x5650c0  55                                push   ebp
0x5650c1  8bec                              mov    ebp,esp
0x5650c3  e8984bf2ff                        call   0x489c60
0x5650c8  33c9                              xor    ecx,ecx
0x5650ca  8bd0                              mov    edx,eax
0x5650cc  8d642400                          lea    esp,[esp+0x0]
0x5650d0  833a0a                            cmp    DWORD PTR [edx],0xa
0x5650d3  7f5c                              jg     0x565131
0x5650d5  41                                inc    ecx
0x5650d6  83c214                            add    edx,0x14
0x5650d9  83f920                            cmp    ecx,0x20
0x5650dc  7cf2                              jl     0x5650d0
0x5650de  33c9                              xor    ecx,ecx
0x5650e0  8bd0                              mov    edx,eax
0x5650e2  833a00                            cmp    DWORD PTR [edx],0x0
0x5650e5  740d                              je     0x5650f4
0x5650e7  41                                inc    ecx
0x5650e8  83c214                            add    edx,0x14
0x5650eb  83f920                            cmp    ecx,0x20
0x5650ee  7cf2                              jl     0x5650e2
0x5650f0  5d                                pop    ebp
0x5650f1  c20c00                            ret    0xc
0x5650f4  0f57c0                            xorps  xmm0,xmm0
0x5650f7  8d0c89                            lea    ecx,[ecx+ecx*4]
0x5650fa  8d0488                            lea    eax,[eax+ecx*4]
0x5650fd  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x565100  c7000a000000                      mov    DWORD PTR [eax],0xa
0x565106  f30f114004                        movss  DWORD PTR [eax+0x4],xmm0
0x56510b  85c9                              test   ecx,ecx
0x56510d  7409                              je     0x565118
0x56510f  0f57c0                            xorps  xmm0,xmm0
0x565112  f30f2ac1                          cvtsi2ss xmm0,ecx
0x565116  eb08                              jmp    0x565120
0x565118  f30f1005c457c500                  movss  xmm0,DWORD PTR ds:0xc557c4
0x565120  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x565123  8b4d10                            mov    ecx,DWORD PTR [ebp+0x10]
0x565126  f30f114008                        movss  DWORD PTR [eax+0x8],xmm0
0x56512b  89500c                            mov    DWORD PTR [eax+0xc],edx
0x56512e  894810                            mov    DWORD PTR [eax+0x10],ecx
0x565131  5d                                pop    ebp
0x565132  c20c00                            ret    0xc

; C31 32-entry camera effect owner
; VA 0x489c60..0x489cab raw 0x89060 length 75 SHA256 4f7c18626129112d3b3b0b54927495cc7a2e3aed8bcd54ae519b888c7c03639c
0x489c60  f605248cfd0001                    test   BYTE PTR ds:0xfd8c24,0x1
0x489c67  753c                              jne    0x489ca5
0x489c69  830d248cfd0001                    or     DWORD PTR ds:0xfd8c24,0x1
0x489c70  0f57c0                            xorps  xmm0,xmm0
0x489c73  ba1f000000                        mov    edx,0x1f
0x489c78  b8308cfd00                        mov    eax,0xfd8c30
0x489c7d  33c9                              xor    ecx,ecx
0x489c7f  90                                nop
0x489c80  8948f8                            mov    DWORD PTR [eax-0x8],ecx
0x489c83  f30f1140fc                        movss  DWORD PTR [eax-0x4],xmm0
0x489c88  f30f1100                          movss  DWORD PTR [eax],xmm0
0x489c8c  894804                            mov    DWORD PTR [eax+0x4],ecx
0x489c8f  894808                            mov    DWORD PTR [eax+0x8],ecx
0x489c92  83c014                            add    eax,0x14
0x489c95  4a                                dec    edx
0x489c96  79e8                              jns    0x489c80
0x489c98  68e0dcbc00                        push   0xbcdce0
0x489c9d  e878864000                        call   0x89231a
0x489ca2  83c404                            add    esp,0x4
0x489ca5  b8288cfd00                        mov    eax,0xfd8c28
0x489caa  c3                                ret

; C32 Reset current effect offset then evaluate and increment each active record
; VA 0x489530..0x48961f raw 0x88930 length 239 SHA256 ef97e1dc8a4d26c172dfbbe69d44c4f15897b4f11e1eb53d4f22775b663dbf2f
0x489530  55                                push   ebp
0x489531  8bec                              mov    ebp,esp
0x489533  6aff                              push   0xffffffff
0x489535  68dc119300                        push   0x9311dc
0x48953a  64a100000000                      mov    eax,fs:0x0
0x489540  50                                push   eax
0x489541  53                                push   ebx
0x489542  56                                push   esi
0x489543  57                                push   edi
0x489544  a1201fd600                        mov    eax,ds:0xd61f20
0x489549  33c5                              xor    eax,ebp
0x48954b  50                                push   eax
0x48954c  8d45f4                            lea    eax,[ebp-0xc]
0x48954f  64a300000000                      mov    fs:0x0,eax
0x489555  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x489558  83ceff                            or     esi,0xffffffff
0x48955b  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
0x489562  8d7e02                            lea    edi,[esi+0x2]
0x489565  7522                              jne    0x489589
0x489567  093d2888fb00                      or     DWORD PTR ds:0xfb8828,edi
0x48956d  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x489574  e8d7620c00                        call   0x54f850
0x489579  6880d5bc00                        push   0xbcd580
0x48957e  e8978d4000                        call   0x89231a
0x489583  83c404                            add    esp,0x4
0x489586  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x489589  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x489590  f30f1005a490fb00                  movss  xmm0,DWORD PTR ds:0xfb90a4
0x489598  f30f114508                        movss  DWORD PTR [ebp+0x8],xmm0
0x48959d  751e                              jne    0x4895bd
0x48959f  093de879fb00                      or     DWORD PTR ds:0xfb79e8,edi
0x4895a5  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x4895a8  e833f83000                        call   0x798de0
0x4895ad  68e0d2bc00                        push   0xbcd2e0
0x4895b2  e8638d4000                        call   0x89231a
0x4895b7  83c404                            add    esp,0x4
0x4895ba  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x4895bd  a1e876fb00                        mov    eax,ds:0xfb76e8
0x4895c2  f30f104508                        movss  xmm0,DWORD PTR [ebp+0x8]
0x4895c7  f30f114028                        movss  DWORD PTR [eax+0x28],xmm0
0x4895cc  33ff                              xor    edi,edi
0x4895ce  8d7304                            lea    esi,[ebx+0x4]
0x4895d1  837efc00                          cmp    DWORD PTR [esi-0x4],0x0
0x4895d5  742b                              je     0x489602
0x4895d7  8bc7                              mov    eax,edi
0x4895d9  8bcb                              mov    ecx,ebx
0x4895db  e870000000                        call   0x489650
0x4895e0  d906                              fld    DWORD PTR [esi]
0x4895e2  dc05c85cc500                      fadd   QWORD PTR ds:0xc55cc8
0x4895e8  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x4895eb  d94508                            fld    DWORD PTR [ebp+0x8]
0x4895ee  d916                              fst    DWORD PTR [esi]
0x4895f0  d94604                            fld    DWORD PTR [esi+0x4]
0x4895f3  d9c9                              fxch   st(1)
0x4895f5  dff1                              fcomip st,st(1)
0x4895f7  ddd8                              fstp   st(0)
0x4895f9  7607                              jbe    0x489602
0x4895fb  c746fc00000000                    mov    DWORD PTR [esi-0x4],0x0
0x489602  47                                inc    edi
0x489603  83c614                            add    esi,0x14
0x489606  83ff20                            cmp    edi,0x20
0x489609  7cc6                              jl     0x4895d1
0x48960b  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x48960e  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x489615  59                                pop    ecx
0x489616  5f                                pop    edi
0x489617  5e                                pop    esi
0x489618  5b                                pop    ebx
0x489619  8be5                              mov    esp,ebp
0x48961b  5d                                pop    ebp
0x48961c  c20400                            ret    0x4

; C05 CameraWorks Play nullable virtual +8
; VA 0x54e9e0..0x54e9ee raw 0x14dde0 length 14 SHA256 bd329d0cce1c0e26200fb8697c5980361cafe516995442b6c32faf6f4ffd275c
0x54e9e0  8b09                              mov    ecx,DWORD PTR [ecx]
0x54e9e2  85c9                              test   ecx,ecx
0x54e9e4  7407                              je     0x54e9ed
0x54e9e6  8b01                              mov    eax,DWORD PTR [ecx]
0x54e9e8  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x54e9eb  ffe2                              jmp    edx
0x54e9ed  c3                                ret

; C06 CameraWorks Stop nullable virtual +C
; VA 0x54e9f0..0x54e9fe raw 0x14ddf0 length 14 SHA256 db885be6e2bb5faa4bb47b19c3f2f6e7a399f78f9283a5d530e3deb49c22bdd6
0x54e9f0  8b09                              mov    ecx,DWORD PTR [ecx]
0x54e9f2  85c9                              test   ecx,ecx
0x54e9f4  7407                              je     0x54e9fd
0x54e9f6  8b01                              mov    eax,DWORD PTR [ecx]
0x54e9f8  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0x54e9fb  ffe2                              jmp    edx
0x54e9fd  c3                                ret

; C07 CameraWorks IsEnded nullable virtual +20 / numeric1
; VA 0x54ea00..0x54ea13 raw 0x14de00 length 19 SHA256 ba2feceb5dec65b2a488bf17e6add42a6fa1914bc5566f1ff709b65686b262ac
0x54ea00  8b09                              mov    ecx,DWORD PTR [ecx]
0x54ea02  85c9                              test   ecx,ecx
0x54ea04  7407                              je     0x54ea0d
0x54ea06  8b01                              mov    eax,DWORD PTR [ecx]
0x54ea08  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0x54ea0b  ffe2                              jmp    edx
0x54ea0d  b801000000                        mov    eax,0x1
0x54ea12  c3                                ret

; C22 Main update ESI=0, BFCC zero gate, CameraEffect and KeyFrame virtual+14
; VA 0x491c40..0x491cd8 raw 0x91040 length 152 SHA256 b203d9516cc1cbadabb6a616cc2c8eefad15b589ba49eae81b7c7b9e1a6cf496
0x491c40  33f6                              xor    esi,esi
0x491c42  83f8ff                            cmp    eax,0xffffffff
0x491c45  7460                              je     0x491ca7
0x491c47  3935aca7fb00                      cmp    DWORD PTR ds:0xfba7ac,esi
0x491c4d  7458                              je     0x491ca7
0x491c4f  83f821                            cmp    eax,0x21
0x491c52  7f4a                              jg     0x491c9e
0x491c54  b810000000                        mov    eax,0x10
0x491c59  c78768bf0000a00f0000              mov    DWORD PTR [edi+0xbf68],0xfa0
0x491c63  6689442414                        mov    WORD PTR [esp+0x14],ax
0x491c68  393598a7fb00                      cmp    DWORD PTR ds:0xfba798,esi
0x491c6e  7515                              jne    0x491c85
0x491c70  8b0d54a8fb00                      mov    ecx,DWORD PTR ds:0xfba854
0x491c76  8b11                              mov    edx,DWORD PTR [ecx]
0x491c78  8b5210                            mov    edx,DWORD PTR [edx+0x10]
0x491c7b  6a02                              push   0x2
0x491c7d  8d442418                          lea    eax,[esp+0x18]
0x491c81  50                                push   eax
0x491c82  56                                push   esi
0x491c83  ffd2                              call   edx
0x491c85  ff15a025bd00                      call   DWORD PTR ds:0xbd25a0
0x491c8b  898764bf0000                      mov    DWORD PTR [edi+0xbf64],eax
0x491c91  e80a2ff7ff                        call   0x404ba0
0x491c96  ff80545f0000                      inc    DWORD PTR [eax+0x5f54]
0x491c9c  eb09                              jmp    0x491ca7
0x491c9e  83c0df                            add    eax,0xffffffdf
0x491ca1  898768bf0000                      mov    DWORD PTR [edi+0xbf68],eax
0x491ca7  39b7ccbf0000                      cmp    DWORD PTR [edi+0xbfcc],esi
0x491cad  7554                              jne    0x491d03
0x491caf  e8acd3f7ff                        call   0x40f060
0x491cb4  8bc8                              mov    ecx,eax
0x491cb6  e8a5e30400                        call   0x4e0060
0x491cbb  e8a07fffff                        call   0x489c60
0x491cc0  50                                push   eax
0x491cc1  e86a78ffff                        call   0x489530
0x491cc6  e86524faff                        call   0x434130
0x491ccb  8b08                              mov    ecx,DWORD PTR [eax]
0x491ccd  3bce                              cmp    ecx,esi
0x491ccf  7407                              je     0x491cd8
0x491cd1  8b01                              mov    eax,DWORD PTR [ecx]
0x491cd3  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x491cd6  ffd2                              call   edx

; C24 Main visual update applies FB76E8 camera transform
; VA 0x4924a2..0x4924ad raw 0x918a2 length 11 SHA256 1038b6f8d392d7c9c18e2d04b019b641a5556249f7a781ac332354d2652b9b9c
0x4924a2  8b3de876fb00                      mov    edi,DWORD PTR ds:0xfb76e8
0x4924a8  e8135a3000                        call   0x797ec0

; C29 Sine helper including x87 FSIN path
; VA 0x8ff0a0..0x8ff189 raw 0x4fe4a0 length 233 SHA256 37bc36763fec8cd0937880b6f5cc2a319c31667db972b97b4e7b50bc707598bb
0x8ff0a0  833d8c72fe0000                    cmp    DWORD PTR ds:0xfe728c,0x0
0x8ff0a7  7432                              je     0x8ff0db
0x8ff0a9  83ec08                            sub    esp,0x8
0x8ff0ac  0fae5c2404                        stmxcsr DWORD PTR [esp+0x4]
0x8ff0b1  8b442404                          mov    eax,DWORD PTR [esp+0x4]
0x8ff0b5  25807f0000                        and    eax,0x7f80
0x8ff0ba  3d801f0000                        cmp    eax,0x1f80
0x8ff0bf  750f                              jne    0x8ff0d0
0x8ff0c1  d93c24                            fnstcw WORD PTR [esp]
0x8ff0c4  668b0424                          mov    ax,WORD PTR [esp]
0x8ff0c8  6683e07f                          and    ax,0x7f
0x8ff0cc  6683f87f                          cmp    ax,0x7f
0x8ff0d0  8d642408                          lea    esp,[esp+0x8]
0x8ff0d4  7505                              jne    0x8ff0db
0x8ff0d6  e9051f0000                        jmp    0x900fe0
0x8ff0db  83ec0c                            sub    esp,0xc
0x8ff0de  dd1424                            fst    QWORD PTR [esp]
0x8ff0e1  e8421c0000                        call   0x900d28
0x8ff0e6  e80d000000                        call   0x8ff0f8
0x8ff0eb  83c40c                            add    esp,0xc
0x8ff0ee  c3                                ret
0x8ff0ef  8d542404                          lea    edx,[esp+0x4]
0x8ff0f3  e8ed1b0000                        call   0x900ce5
0x8ff0f8  52                                push   edx
0x8ff0f9  9bd93c24                          fstcw  WORD PTR [esp]
0x8ff0fd  7450                              je     0x8ff14f
0x8ff0ff  66813c247f02                      cmp    WORD PTR [esp],0x27f
0x8ff105  7406                              je     0x8ff10d
0x8ff107  d92d2878c500                      fldcw  WORD PTR ds:0xc57828
0x8ff10d  d9fe                              fsin
0x8ff10f  9bdfe0                            fstsw  ax
0x8ff112  9e                                sahf
0x8ff113  7a1d                              jp     0x8ff132
0x8ff115  833d74cbf80000                    cmp    DWORD PTR ds:0xf8cb74,0x0
0x8ff11c  0f851c1c0000                      jne    0x900d3e
0x8ff122  ba1e000000                        mov    edx,0x1e
0x8ff127  8d0d10c7f800                      lea    ecx,ds:0xf8c710
0x8ff12d  e9191c0000                        jmp    0x900d4b
0x8ff132  db2d2a78c500                      fld    TBYTE PTR ds:0xc5782a
0x8ff138  d9c9                              fxch   st(1)
0x8ff13a  d9f5                              fprem1
0x8ff13c  9bdfe0                            fstsw  ax
0x8ff13f  9e                                sahf
0x8ff140  7af8                              jp     0x8ff13a
0x8ff142  ddd9                              fstp   st(1)
0x8ff144  d9fe                              fsin
0x8ff146  ebcd                              jmp    0x8ff115
0x8ff148  e87f1b0000                        call   0x900ccc
0x8ff14d  eb1b                              jmp    0x8ff16a
0x8ff14f  a9ffff0f00                        test   eax,0xfffff
0x8ff154  75f2                              jne    0x8ff148
0x8ff156  837c240800                        cmp    DWORD PTR [esp+0x8],0x0
0x8ff15b  75eb                              jne    0x8ff148
0x8ff15d  ddd8                              fstp   st(0)
0x8ff15f  db2df077c500                      fld    TBYTE PTR ds:0xc577f0
0x8ff165  b801000000                        mov    eax,0x1
0x8ff16a  833d74cbf80000                    cmp    DWORD PTR ds:0xf8cb74,0x0
0x8ff171  0f85c71b0000                      jne    0x900d3e
0x8ff177  ba1e000000                        mov    edx,0x1e
0x8ff17c  8d0d10c7f800                      lea    ecx,ds:0xf8c710
0x8ff182  e8d01a0000                        call   0x900c57
0x8ff187  5a                                pop    edx
0x8ff188  c3                                ret

; C33_dispatch Effect type-1 jump table dispatch
; VA 0x489650..0x489680 raw 0x88a50 length 48 SHA256 467b74133cd96f2e29e44bf49a2246b3c7e4bf5d596b7d31ac734b1cdbcadb3e
0x489650  55                                push   ebp
0x489651  8bec                              mov    ebp,esp
0x489653  83e4f8                            and    esp,0xfffffff8
0x489656  83ec18                            sub    esp,0x18
0x489659  8d0480                            lea    eax,[eax+eax*4]
0x48965c  f30f10448104                      movss  xmm0,DWORD PTR [ecx+eax*4+0x4]
0x489662  56                                push   esi
0x489663  8d3481                            lea    esi,[ecx+eax*4]
0x489666  8b06                              mov    eax,DWORD PTR [esi]
0x489668  48                                dec    eax
0x489669  57                                push   edi
0x48966a  f30f11442408                      movss  DWORD PTR [esp+0x8],xmm0
0x489670  83f809                            cmp    eax,0x9
0x489673  0f876f020000                      ja     0x4898e8
0x489679  ff2485f0984800                    jmp    DWORD PTR [eax*4+0x4898f0]

; C33_type10 sin(t)*(arg2-t)/arg3 -> current camera+28
; VA 0x4898b2..0x4898ee raw 0x88cb2 length 60 SHA256 4495ad573641fb915b1d7f24c56222a2e94f5e8b85dbf0d07e764c3cd2147292
0x4898b2  e889aefaff                        call   0x434740
0x4898b7  d9442408                          fld    DWORD PTR [esp+0x8]
0x4898bb  8bf8                              mov    edi,eax
0x4898bd  e8de574700                        call   0x8ff0a0
0x4898c2  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x4898c6  d9442410                          fld    DWORD PTR [esp+0x10]
0x4898ca  8b5740                            mov    edx,DWORD PTR [edi+0x40]
0x4898cd  db460c                            fild   DWORD PTR [esi+0xc]
0x4898d0  d9442408                          fld    DWORD PTR [esp+0x8]
0x4898d4  d9e0                              fchs
0x4898d6  dec1                              faddp  st(1),st
0x4898d8  dec9                              fmulp  st(1),st
0x4898da  da7610                            fidiv  DWORD PTR [esi+0x10]
0x4898dd  d95c2410                          fstp   DWORD PTR [esp+0x10]
0x4898e1  d9442410                          fld    DWORD PTR [esp+0x10]
0x4898e5  d95a28                            fstp   DWORD PTR [edx+0x28]
0x4898e8  5f                                pop    edi
0x4898e9  5e                                pop    esi
0x4898ea  8be5                              mov    esp,ebp
0x4898ec  5d                                pop    ebp
0x4898ed  c3                                ret

; C33_switch Effect types1..10 jump targets
; VA 0x4898f0..0x489918 raw 0x88cf0 length 40 SHA256 e5c6d3b5b24f8a91ac36e212f0b268b378c5a54afa021d908f2edc5a4f62a85b
; bytes 80964800c096480033974800b297480037984800e8984800e8984800e8984800e8984800b2984800

; C34 R10 shared current CameraWorks delta virtual+10; not KeyFrame progress
; VA 0x492410..0x492428 raw 0x91810 length 24 SHA256 26bcadb87781da0266fcddb04bd4e47061608bada2ce75faf880dbad037e0c66
0x492410  8b0d2076fb00                      mov    ecx,DWORD PTR ds:0xfb7620
0x492416  85c9                              test   ecx,ecx
0x492418  740e                              je     0x492428
0x49241a  8b01                              mov    eax,DWORD PTR [ecx]
0x49241c  d9450c                            fld    DWORD PTR [ebp+0xc]
0x49241f  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x492422  51                                push   ecx
0x492423  d91c24                            fstp   DWORD PTR [esp]
0x492426  ffd2                              call   edx

; C35 KeyFrame virtual+10 is ret4
; VA 0x476430..0x476433 raw 0x75830 length 3 SHA256 e598d0c3ba86d917b177d7adde0556aa99bc355543c57aee0a3e50b684dd7e99
0x476430  c20400                            ret    0x4

; U01 Tutorial music delegates same primary BGM slot
; VA 0x4a9330..0x4a9423 raw 0xa8730 length 243 SHA256 5a134b5bcb5f45eeb22e5fc6eaacc5d625e8c2adff1acc65168e2f02db18b51e
0x4a9330  55                                push   ebp
0x4a9331  8bec                              mov    ebp,esp
0x4a9333  6aff                              push   0xffffffff
0x4a9335  68dab69100                        push   0x91b6da
0x4a933a  64a100000000                      mov    eax,fs:0x0
0x4a9340  50                                push   eax
0x4a9341  51                                push   ecx
0x4a9342  53                                push   ebx
0x4a9343  a1201fd600                        mov    eax,ds:0xd61f20
0x4a9348  33c5                              xor    eax,ebp
0x4a934a  50                                push   eax
0x4a934b  8d45f4                            lea    eax,[ebp-0xc]
0x4a934e  64a300000000                      mov    fs:0x0,eax
0x4a9354  bb01000000                        mov    ebx,0x1
0x4a9359  841d2888fb00                      test   BYTE PTR ds:0xfb8828,bl
0x4a935f  7526                              jne    0x4a9387
0x4a9361  091d2888fb00                      or     DWORD PTR ds:0xfb8828,ebx
0x4a9367  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4a936e  e8dd640a00                        call   0x54f850
0x4a9373  6880d5bc00                        push   0xbcd580
0x4a9378  e89d8f3e00                        call   0x89231a
0x4a937d  83c404                            add    esp,0x4
0x4a9380  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a9387  66a1ea90fb00                      mov    ax,ds:0xfb90ea
0x4a938d  668945f0                          mov    WORD PTR [ebp-0x10],ax
0x4a9391  841dc00ffc00                      test   BYTE PTR ds:0xfc0fc0,bl
0x4a9397  7550                              jne    0x4a93e9
0x4a9399  091dc00ffc00                      or     DWORD PTR ds:0xfc0fc0,ebx
0x4a939f  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x4a93a2  e8a9fa2200                        call   0x6d8e50
0x4a93a7  68b0dbbc00                        push   0xbcdbb0
0x4a93ac  e8698f3e00                        call   0x89231a
0x4a93b1  83c404                            add    esp,0x4
0x4a93b4  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a93bb  841dc00ffc00                      test   BYTE PTR ds:0xfc0fc0,bl
0x4a93c1  7526                              jne    0x4a93e9
0x4a93c3  091dc00ffc00                      or     DWORD PTR ds:0xfc0fc0,ebx
0x4a93c9  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x4a93d0  e87bfa2200                        call   0x6d8e50
0x4a93d5  68b0dbbc00                        push   0xbcdbb0
0x4a93da  e83b8f3e00                        call   0x89231a
0x4a93df  83c404                            add    esp,0x4
0x4a93e2  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a93e9  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0x4a93ec  e87f162300                        call   0x6daa70
0x4a93f1  e81a594500                        call   0x8fed10
0x4a93f6  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x4a93f9  0fb7c8                            movzx  ecx,ax
0x4a93fc  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4a93ff  51                                push   ecx
0x4a9400  52                                push   edx
0x4a9401  50                                push   eax
0x4a9402  68c80ffc00                        push   0xfc0fc8
0x4a9407  b9fc0ffc00                        mov    ecx,0xfc0ffc
0x4a940c  e81f072300                        call   0x6d9b30
0x4a9411  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4a9414  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4a941b  59                                pop    ecx
0x4a941c  5b                                pop    ebx
0x4a941d  8be5                              mov    esp,ebp
0x4a941f  5d                                pop    ebp
0x4a9420  c20800                            ret    0x8

; U02 Tutorial StopCameraWorks nullable current virtual+C
; VA 0x4a9570..0x4a95ed raw 0xa8970 length 125 SHA256 bcf93ed9fea84a143890ace474c673b2bb4f34ec82ee5ba1651db93e27c96dc5
0x4a9570  55                                push   ebp
0x4a9571  8bec                              mov    ebp,esp
0x4a9573  83e4f8                            and    esp,0xfffffff8
0x4a9576  6aff                              push   0xffffffff
0x4a9578  68dea99300                        push   0x93a9de
0x4a957d  64a100000000                      mov    eax,fs:0x0
0x4a9583  50                                push   eax
0x4a9584  51                                push   ecx
0x4a9585  a1201fd600                        mov    eax,ds:0xd61f20
0x4a958a  33c4                              xor    eax,esp
0x4a958c  50                                push   eax
0x4a958d  8d442408                          lea    eax,[esp+0x8]
0x4a9591  64a300000000                      mov    fs:0x0,eax
0x4a9597  b801000000                        mov    eax,0x1
0x4a959c  84051c76fb00                      test   BYTE PTR ds:0xfb761c,al
0x4a95a2  7528                              jne    0x4a95cc
0x4a95a4  09051c76fb00                      or     DWORD PTR ds:0xfb761c,eax
0x4a95aa  c744241000000000                  mov    DWORD PTR [esp+0x10],0x0
0x4a95b2  e899510a00                        call   0x54e750
0x4a95b7  6860d2bc00                        push   0xbcd260
0x4a95bc  e8598d3e00                        call   0x89231a
0x4a95c1  83c404                            add    esp,0x4
0x4a95c4  c7442410ffffffff                  mov    DWORD PTR [esp+0x10],0xffffffff
0x4a95cc  8b0d2076fb00                      mov    ecx,DWORD PTR ds:0xfb7620
0x4a95d2  85c9                              test   ecx,ecx
0x4a95d4  7407                              je     0x4a95dd
0x4a95d6  8b01                              mov    eax,DWORD PTR [ecx]
0x4a95d8  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0x4a95db  ffd2                              call   edx
0x4a95dd  8b4c2408                          mov    ecx,DWORD PTR [esp+0x8]
0x4a95e1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4a95e8  59                                pop    ecx
0x4a95e9  8be5                              mov    esp,ebp
0x4a95eb  5d                                pop    ebp
0x4a95ec  c3                                ret

; U03 Tutorial PushCamera(label) snapshot then assign label
; VA 0x4a95f0..0x4a9692 raw 0xa89f0 length 162 SHA256 4ab69ab81fb4681d3b8c7b280abaf5aa33e0e8cdced163ad4ed53ab981f1e047
0x4a95f0  55                                push   ebp
0x4a95f1  8bec                              mov    ebp,esp
0x4a95f3  6aff                              push   0xffffffff
0x4a95f5  680e259300                        push   0x93250e
0x4a95fa  64a100000000                      mov    eax,fs:0x0
0x4a9600  50                                push   eax
0x4a9601  51                                push   ecx
0x4a9602  56                                push   esi
0x4a9603  57                                push   edi
0x4a9604  a1201fd600                        mov    eax,ds:0xd61f20
0x4a9609  33c5                              xor    eax,ebp
0x4a960b  50                                push   eax
0x4a960c  8d45f4                            lea    eax,[ebp-0xc]
0x4a960f  64a300000000                      mov    fs:0x0,eax
0x4a9615  b801000000                        mov    eax,0x1
0x4a961a  8405e879fb00                      test   BYTE PTR ds:0xfb79e8,al
0x4a9620  7526                              jne    0x4a9648
0x4a9622  0905e879fb00                      or     DWORD PTR ds:0xfb79e8,eax
0x4a9628  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4a962f  e8acf72e00                        call   0x798de0
0x4a9634  68e0d2bc00                        push   0xbcd2e0
0x4a9639  e8dc8c3e00                        call   0x89231a
0x4a963e  83c404                            add    esp,0x4
0x4a9641  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a9648  a1e876fb00                        mov    eax,ds:0xfb76e8
0x4a964d  8d480c                            lea    ecx,[eax+0xc]
0x4a9650  8bf0                              mov    esi,eax
0x4a9652  51                                push   ecx
0x4a9653  05a0000000                        add    eax,0xa0
0x4a9658  50                                push   eax
0x4a9659  e8a2f22e00                        call   0x798900
0x4a965e  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x4a9661  8bc2                              mov    eax,edx
0x4a9663  8d7801                            lea    edi,[eax+0x1]
0x4a9666  8a08                              mov    cl,BYTE PTR [eax]
0x4a9668  40                                inc    eax
0x4a9669  84c9                              test   cl,cl
0x4a966b  75f9                              jne    0x4a9666
0x4a966d  8b8ea4000000                      mov    ecx,DWORD PTR [esi+0xa4]
0x4a9673  2bc7                              sub    eax,edi
0x4a9675  50                                push   eax
0x4a9676  52                                push   edx
0x4a9677  83e91c                            sub    ecx,0x1c
0x4a967a  e8f193f5ff                        call   0x402a70
0x4a967f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4a9682  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4a9689  59                                pop    ecx
0x4a968a  5f                                pop    edi
0x4a968b  5e                                pop    esi
0x4a968c  8be5                              mov    esp,ebp
0x4a968e  5d                                pop    ebp
0x4a968f  c20400                            ret    0x4

; U04 Tutorial PopCamera(label) -> destructive labelled pop
; VA 0x4a96a0..0x4a972d raw 0xa8aa0 length 141 SHA256 1451180b5a801e95f9ecb3721d8a65dc85d505de8cd6d5c0ef5091fcbb821022
0x4a96a0  55                                push   ebp
0x4a96a1  8bec                              mov    ebp,esp
0x4a96a3  6aff                              push   0xffffffff
0x4a96a5  682eed9200                        push   0x92ed2e
0x4a96aa  64a100000000                      mov    eax,fs:0x0
0x4a96b0  50                                push   eax
0x4a96b1  a1201fd600                        mov    eax,ds:0xd61f20
0x4a96b6  51                                push   ecx
0x4a96b7  33c5                              xor    eax,ebp
0x4a96b9  50                                push   eax
0x4a96ba  8d45f4                            lea    eax,[ebp-0xc]
0x4a96bd  64a300000000                      mov    fs:0x0,eax
0x4a96c3  b801000000                        mov    eax,0x1
0x4a96c8  8405e879fb00                      test   BYTE PTR ds:0xfb79e8,al
0x4a96ce  7526                              jne    0x4a96f6
0x4a96d0  0905e879fb00                      or     DWORD PTR ds:0xfb79e8,eax
0x4a96d6  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4a96dd  e8fef62e00                        call   0x798de0
0x4a96e2  68e0d2bc00                        push   0xbcd2e0
0x4a96e7  e82e8c3e00                        call   0x89231a
0x4a96ec  83c404                            add    esp,0x4
0x4a96ef  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a96f6  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4a96f9  8b0de876fb00                      mov    ecx,DWORD PTR ds:0xfb76e8
0x4a96ff  50                                push   eax
0x4a9700  51                                push   ecx
0x4a9701  e8daef2e00                        call   0x7986e0
0x4a9706  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4a9709  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4a9710  59                                pop    ecx
0x4a9711  8be5                              mov    esp,ebp
0x4a9713  5d                                pop    ebp
0x4a9714  c20400                            ret    0x4
0x4a9717  cc                                int3
0x4a9718  cc                                int3
0x4a9719  cc                                int3
0x4a971a  cc                                int3
0x4a971b  cc                                int3
0x4a971c  cc                                int3
0x4a971d  cc                                int3
0x4a971e  cc                                int3
0x4a971f  cc                                int3
0x4a9720  51                                push   ecx
0x4a9721  68f8aafb00                        push   0xfbaaf8
0x4a9726  e8e52c0a00                        call   0x54c410
0x4a972b  59                                pop    ecx
0x4a972c  c3                                ret

; U06 ApplyDefaultCamera defaults plus optional leader heading
; VA 0x54c410..0x54c611 raw 0x14b810 length 513 SHA256 c57304d6b64ed1d15b6693076376081ed311e6bc1dd780451930118dcd0a59da
0x54c410  55                                push   ebp
0x54c411  8bec                              mov    ebp,esp
0x54c413  6aff                              push   0xffffffff
0x54c415  68d4ee9200                        push   0x92eed4
0x54c41a  64a100000000                      mov    eax,fs:0x0
0x54c420  50                                push   eax
0x54c421  83ec08                            sub    esp,0x8
0x54c424  53                                push   ebx
0x54c425  56                                push   esi
0x54c426  57                                push   edi
0x54c427  a1201fd600                        mov    eax,ds:0xd61f20
0x54c42c  33c5                              xor    eax,ebp
0x54c42e  50                                push   eax
0x54c42f  8d45f4                            lea    eax,[ebp-0xc]
0x54c432  64a300000000                      mov    fs:0x0,eax
0x54c438  33ff                              xor    edi,edi
0x54c43a  8d5f01                            lea    ebx,[edi+0x1]
0x54c43d  83ceff                            or     esi,0xffffffff
0x54c440  841d2888fb00                      test   BYTE PTR ds:0xfb8828,bl
0x54c446  751e                              jne    0x54c466
0x54c448  091d2888fb00                      or     DWORD PTR ds:0xfb8828,ebx
0x54c44e  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x54c451  e8fa330000                        call   0x54f850
0x54c456  6880d5bc00                        push   0xbcd580
0x54c45b  e8ba5e3400                        call   0x89231a
0x54c460  83c404                            add    esp,0x4
0x54c463  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x54c466  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x54c46d  f30f10059490fb00                  movss  xmm0,DWORD PTR ds:0xfb9094
0x54c475  f30f1145f0                        movss  DWORD PTR [ebp-0x10],xmm0
0x54c47a  751e                              jne    0x54c49a
0x54c47c  091de879fb00                      or     DWORD PTR ds:0xfb79e8,ebx
0x54c482  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x54c485  e856c92400                        call   0x798de0
0x54c48a  68e0d2bc00                        push   0xbcd2e0
0x54c48f  e8865e3400                        call   0x89231a
0x54c494  83c404                            add    esp,0x4
0x54c497  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x54c49a  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
0x54c4a1  a1e876fb00                        mov    eax,ds:0xfb76e8
0x54c4a6  f30f1045f0                        movss  xmm0,DWORD PTR [ebp-0x10]
0x54c4ab  f30f114018                        movss  DWORD PTR [eax+0x18],xmm0
0x54c4b0  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
0x54c4b6  7522                              jne    0x54c4da
0x54c4b8  091d2888fb00                      or     DWORD PTR ds:0xfb8828,ebx
0x54c4be  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x54c4c5  e886330000                        call   0x54f850
0x54c4ca  6880d5bc00                        push   0xbcd580
0x54c4cf  e8465e3400                        call   0x89231a
0x54c4d4  83c404                            add    esp,0x4
0x54c4d7  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x54c4da  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x54c4e1  f30f10057c90fb00                  movss  xmm0,DWORD PTR ds:0xfb907c
0x54c4e9  f30f1145f0                        movss  DWORD PTR [ebp-0x10],xmm0
0x54c4ee  7522                              jne    0x54c512
0x54c4f0  091de879fb00                      or     DWORD PTR ds:0xfb79e8,ebx
0x54c4f6  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
0x54c4fd  e8dec82400                        call   0x798de0
0x54c502  68e0d2bc00                        push   0xbcd2e0
0x54c507  e80e5e3400                        call   0x89231a
0x54c50c  83c404                            add    esp,0x4
0x54c50f  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x54c512  a1e876fb00                        mov    eax,ds:0xfb76e8
0x54c517  f30f1045f0                        movss  xmm0,DWORD PTR [ebp-0x10]
0x54c51c  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x54c522  f30f114024                        movss  DWORD PTR [eax+0x24],xmm0
0x54c527  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
0x54c52d  8b01                              mov    eax,DWORD PTR [ecx]
0x54c52f  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0x54c532  ffd2                              call   edx
0x54c534  85c0                              test   eax,eax
0x54c536  0f8481000000                      je     0x54c5bd
0x54c53c  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x54c542  8b01                              mov    eax,DWORD PTR [ecx]
0x54c544  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0x54c547  ffd2                              call   edx
0x54c549  f605187cfb0001                    test   BYTE PTR ds:0xfb7c18,0x1
0x54c550  8a98b0000000                      mov    bl,BYTE PTR [eax+0xb0]
0x54c556  750c                              jne    0x54c564
0x54c558  830d187cfb0001                    or     DWORD PTR ds:0xfb7c18,0x1
0x54c55f  e86c84efff                        call   0x4449d0
0x54c564  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x54c56b  0fb6c3                            movzx  eax,bl
0x54c56e  f30f100485207cfb00                movss  xmm0,DWORD PTR [eax*4+0xfb7c20]
0x54c577  f30f1145f0                        movss  DWORD PTR [ebp-0x10],xmm0
0x54c57c  7523                              jne    0x54c5a1
0x54c57e  830de879fb0001                    or     DWORD PTR ds:0xfb79e8,0x1
0x54c585  c745fc04000000                    mov    DWORD PTR [ebp-0x4],0x4
0x54c58c  e84fc82400                        call   0x798de0
0x54c591  68e0d2bc00                        push   0xbcd2e0
0x54c596  e87f5d3400                        call   0x89231a
0x54c59b  83c404                            add    esp,0x4
0x54c59e  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x54c5a1  d945f0                            fld    DWORD PTR [ebp-0x10]
0x54c5a4  a1e876fb00                        mov    eax,ds:0xfb76e8
0x54c5a9  dc05d85ac500                      fadd   QWORD PTR ds:0xc55ad8
0x54c5af  89b8cc000000                      mov    DWORD PTR [eax+0xcc],edi
0x54c5b5  bb01000000                        mov    ebx,0x1
0x54c5ba  d95820                            fstp   DWORD PTR [eax+0x20]
0x54c5bd  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x54c5c0  397940                            cmp    DWORD PTR [ecx+0x40],edi
0x54c5c3  7438                              je     0x54c5fd
0x54c5c5  f605d4adfa0001                    test   BYTE PTR ds:0xfaadd4,0x1
0x54c5cc  7522                              jne    0x54c5f0
0x54c5ce  091dd4adfa00                      or     DWORD PTR ds:0xfaadd4,ebx
0x54c5d4  c745fc05000000                    mov    DWORD PTR [ebp-0x4],0x5
0x54c5db  e8a0ae0300                        call   0x587480
0x54c5e0  68c0ccbc00                        push   0xbcccc0
0x54c5e5  e8305d3400                        call   0x89231a
0x54c5ea  83c404                            add    esp,0x4
0x54c5ed  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x54c5f0  6858430f00                        push   0xf4358
0x54c5f5  e8d6e40300                        call   0x58aad0
0x54c5fa  83c404                            add    esp,0x4
0x54c5fd  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x54c600  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x54c607  59                                pop    ecx
0x54c608  5f                                pop    edi
0x54c609  5e                                pop    esi
0x54c60a  5b                                pop    ebx
0x54c60b  8be5                              mov    esp,ebp
0x54c60d  5d                                pop    ebp
0x54c60e  c20400                            ret    0x4

; U07 Shared 0x48-byte camera snapshot append
; VA 0x798900..0x7989d3 raw 0x397d00 length 211 SHA256 6fd8b5ce24f6390f2f4e1759ec102de6b8fb33c572c93fc199a86e69f35623d9
0x798900  55                                push   ebp
0x798901  8bec                              mov    ebp,esp
0x798903  6aff                              push   0xffffffff
0x798905  6892529100                        push   0x915292
0x79890a  64a100000000                      mov    eax,fs:0x0
0x798910  50                                push   eax
0x798911  51                                push   ecx
0x798912  53                                push   ebx
0x798913  56                                push   esi
0x798914  57                                push   edi
0x798915  a1201fd600                        mov    eax,ds:0xd61f20
0x79891a  33c5                              xor    eax,ebp
0x79891c  50                                push   eax
0x79891d  8d45f4                            lea    eax,[ebp-0xc]
0x798920  64a300000000                      mov    fs:0x0,eax
0x798926  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x798929  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x79892c  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x79892f  3bd9                              cmp    ebx,ecx
0x798931  733d                              jae    0x798970
0x798933  8b07                              mov    eax,DWORD PTR [edi]
0x798935  3bc3                              cmp    eax,ebx
0x798937  7737                              ja     0x798970
0x798939  2bd8                              sub    ebx,eax
0x79893b  b8398ee338                        mov    eax,0x38e38e39
0x798940  f7eb                              imul   ebx
0x798942  c1fa04                            sar    edx,0x4
0x798945  8bf2                              mov    esi,edx
0x798947  c1ee1f                            shr    esi,0x1f
0x79894a  03f2                              add    esi,edx
0x79894c  3b4f08                            cmp    ecx,DWORD PTR [edi+0x8]
0x79894f  7507                              jne    0x798958
0x798951  8bcf                              mov    ecx,edi
0x798953  e888000000                        call   0x7989e0
0x798958  8b0f                              mov    ecx,DWORD PTR [edi]
0x79895a  8d04f6                            lea    eax,[esi+esi*8]
0x79895d  8d1cc1                            lea    ebx,[ecx+eax*8]
0x798960  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x798963  89450c                            mov    DWORD PTR [ebp+0xc],eax
0x798966  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x798969  33d2                              xor    edx,edx
0x79896b  8955fc                            mov    DWORD PTR [ebp-0x4],edx
0x79896e  eb1e                              jmp    0x79898e
0x798970  3b4f08                            cmp    ecx,DWORD PTR [edi+0x8]
0x798973  7507                              jne    0x79897c
0x798975  8bcf                              mov    ecx,edi
0x798977  e864000000                        call   0x7989e0
0x79897c  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x79897f  89450c                            mov    DWORD PTR [ebp+0xc],eax
0x798982  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x798985  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x79898c  33d2                              xor    edx,edx
0x79898e  3bc2                              cmp    eax,edx
0x798990  7429                              je     0x7989bb
0x798992  8bf8                              mov    edi,eax
0x798994  8bf3                              mov    esi,ebx
0x798996  b90b000000                        mov    ecx,0xb
0x79899b  f3a5                              rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x79899d  6aff                              push   0xffffffff
0x79899f  8d482c                            lea    ecx,[eax+0x2c]
0x7989a2  52                                push   edx
0x7989a3  83c32c                            add    ebx,0x2c
0x7989a6  c741140f000000                    mov    DWORD PTR [ecx+0x14],0xf
0x7989ad  895110                            mov    DWORD PTR [ecx+0x10],edx
0x7989b0  53                                push   ebx
0x7989b1  8811                              mov    BYTE PTR [ecx],dl
0x7989b3  e888a6c6ff                        call   0x403040
0x7989b8  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x7989bb  83470448                          add    DWORD PTR [edi+0x4],0x48
0x7989bf  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x7989c2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x7989c9  59                                pop    ecx
0x7989ca  5f                                pop    edi
0x7989cb  5e                                pop    esi
0x7989cc  5b                                pop    ebx
0x7989cd  8be5                              mov    esp,ebp
0x7989cf  5d                                pop    ebp
0x7989d0  c20800                            ret    0x8

; U08 Shared restore+erase before name matching
; VA 0x7986e0..0x7988f8 raw 0x397ae0 length 536 SHA256 394b5c8c7047e081b1d9f485da49a8e854746c0cb7de730683c612daf8331c36
0x7986e0  55                                push   ebp
0x7986e1  8bec                              mov    ebp,esp
0x7986e3  6aff                              push   0xffffffff
0x7986e5  6838559100                        push   0x915538
0x7986ea  64a100000000                      mov    eax,fs:0x0
0x7986f0  50                                push   eax
0x7986f1  83ec38                            sub    esp,0x38
0x7986f4  a1201fd600                        mov    eax,ds:0xd61f20
0x7986f9  33c5                              xor    eax,ebp
0x7986fb  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x7986fe  53                                push   ebx
0x7986ff  56                                push   esi
0x798700  57                                push   edi
0x798701  50                                push   eax
0x798702  8d45f4                            lea    eax,[ebp-0xc]
0x798705  64a300000000                      mov    fs:0x0,eax
0x79870b  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x79870e  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x798711  8b8ba4000000                      mov    ecx,DWORD PTR [ebx+0xa4]
0x798717  2b8ba0000000                      sub    ecx,DWORD PTR [ebx+0xa0]
0x79871d  8945c0                            mov    DWORD PTR [ebp-0x40],eax
0x798720  b8398ee338                        mov    eax,0x38e38e39
0x798725  f7e9                              imul   ecx
0x798727  c1fa04                            sar    edx,0x4
0x79872a  8bc2                              mov    eax,edx
0x79872c  c1e81f                            shr    eax,0x1f
0x79872f  03c2                              add    eax,edx
0x798731  895dd0                            mov    DWORD PTR [ebp-0x30],ebx
0x798734  0f84a0010000                      je     0x7988da
0x79873a  8d4b38                            lea    ecx,[ebx+0x38]
0x79873d  894dc4                            mov    DWORD PTR [ebp-0x3c],ecx
0x798740  8d0cc0                            lea    ecx,[eax+eax*8]
0x798743  03c9                              add    ecx,ecx
0x798745  03c9                              add    ecx,ecx
0x798747  03c9                              add    ecx,ecx
0x798749  eb0e                              jmp    0x798759
0x79874b  eb03                              jmp    0x798750
0x79874d  8d4900                            lea    ecx,[ecx+0x0]
0x798750  8b5dd0                            mov    ebx,DWORD PTR [ebp-0x30]
0x798753  8b45c8                            mov    eax,DWORD PTR [ebp-0x38]
0x798756  8b4dcc                            mov    ecx,DWORD PTR [ebp-0x34]
0x798759  48                                dec    eax
0x79875a  83e948                            sub    ecx,0x48
0x79875d  8945c8                            mov    DWORD PTR [ebp-0x38],eax
0x798760  8b83a0000000                      mov    eax,DWORD PTR [ebx+0xa0]
0x798766  03c1                              add    eax,ecx
0x798768  894dcc                            mov    DWORD PTR [ebp-0x34],ecx
0x79876b  6aff                              push   0xffffffff
0x79876d  8bf0                              mov    esi,eax
0x79876f  b90b000000                        mov    ecx,0xb
0x798774  8d7b0c                            lea    edi,[ebx+0xc]
0x798777  6a00                              push   0x0
0x798779  83c02c                            add    eax,0x2c
0x79877c  f3a5                              rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x79877e  8b4dc4                            mov    ecx,DWORD PTR [ebp-0x3c]
0x798781  50                                push   eax
0x798782  e8b9a8c6ff                        call   0x403040
0x798787  8b83a0000000                      mov    eax,DWORD PTR [ebx+0xa0]
0x79878d  8b75cc                            mov    esi,DWORD PTR [ebp-0x34]
0x798790  837c304010                        cmp    DWORD PTR [eax+esi*1+0x40],0x10
0x798795  7206                              jb     0x79879d
0x798797  8b7c302c                          mov    edi,DWORD PTR [eax+esi*1+0x2c]
0x79879b  eb04                              jmp    0x7987a1
0x79879d  8d7c302c                          lea    edi,[eax+esi*1+0x2c]
0x7987a1  8bc7                              mov    eax,edi
0x7987a3  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
0x7987aa  c745e400000000                    mov    DWORD PTR [ebp-0x1c],0x0
0x7987b1  c645d400                          mov    BYTE PTR [ebp-0x2c],0x0
0x7987b5  8d5001                            lea    edx,[eax+0x1]
0x7987b8  8a08                              mov    cl,BYTE PTR [eax]
0x7987ba  40                                inc    eax
0x7987bb  84c9                              test   cl,cl
0x7987bd  75f9                              jne    0x7987b8
0x7987bf  2bc2                              sub    eax,edx
0x7987c1  50                                push   eax
0x7987c2  57                                push   edi
0x7987c3  8d4dd4                            lea    ecx,[ebp-0x2c]
0x7987c6  e8a5a2c6ff                        call   0x402a70
0x7987cb  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x7987d2  8b8ba4000000                      mov    ecx,DWORD PTR [ebx+0xa4]
0x7987d8  8b83a0000000                      mov    eax,DWORD PTR [ebx+0xa0]
0x7987de  8d5c0648                          lea    ebx,[esi+eax*1+0x48]
0x7987e2  894dbc                            mov    DWORD PTR [ebp-0x44],ecx
0x7987e5  3bd9                              cmp    ebx,ecx
0x7987e7  742b                              je     0x798814
0x7987e9  8da42400000000                    lea    esp,[esp+0x0]
0x7987f0  6aff                              push   0xffffffff
0x7987f2  8d7bb8                            lea    edi,[ebx-0x48]
0x7987f5  b90b000000                        mov    ecx,0xb
0x7987fa  8bf3                              mov    esi,ebx
0x7987fc  6a00                              push   0x0
0x7987fe  8d532c                            lea    edx,[ebx+0x2c]
0x798801  f3a5                              rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x798803  52                                push   edx
0x798804  8d4be4                            lea    ecx,[ebx-0x1c]
0x798807  e834a8c6ff                        call   0x403040
0x79880c  83c348                            add    ebx,0x48
0x79880f  3b5dbc                            cmp    ebx,DWORD PTR [ebp-0x44]
0x798812  75dc                              jne    0x7987f0
0x798814  8b45d0                            mov    eax,DWORD PTR [ebp-0x30]
0x798817  8bb8a4000000                      mov    edi,DWORD PTR [eax+0xa4]
0x79881d  8d5fb8                            lea    ebx,[edi-0x48]
0x798820  3bdf                              cmp    ebx,edi
0x798822  7432                              je     0x798856
0x798824  8d7340                            lea    esi,[ebx+0x40]
0x798827  833e10                            cmp    DWORD PTR [esi],0x10
0x79882a  720c                              jb     0x798838
0x79882c  8b46ec                            mov    eax,DWORD PTR [esi-0x14]
0x79882f  50                                push   eax
0x798830  e8d7890f00                        call   0x89120c
0x798835  83c404                            add    esp,0x4
0x798838  c7060f000000                      mov    DWORD PTR [esi],0xf
0x79883e  c746fc00000000                    mov    DWORD PTR [esi-0x4],0x0
0x798845  c646ec00                          mov    BYTE PTR [esi-0x14],0x0
0x798849  83c348                            add    ebx,0x48
0x79884c  83c648                            add    esi,0x48
0x79884f  3bdf                              cmp    ebx,edi
0x798851  75d4                              jne    0x798827
0x798853  8b45d0                            mov    eax,DWORD PTR [ebp-0x30]
0x798856  8380a4000000b8                    add    DWORD PTR [eax+0xa4],0xffffffb8
0x79885d  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
0x798860  bf10000000                        mov    edi,0x10
0x798865  397de8                            cmp    DWORD PTR [ebp-0x18],edi
0x798868  7303                              jae    0x79886d
0x79886a  8d45d4                            lea    eax,[ebp-0x2c]
0x79886d  8b75c0                            mov    esi,DWORD PTR [ebp-0x40]
0x798870  56                                push   esi
0x798871  50                                push   eax
0x798872  e83ab40f00                        call   0x893cb1
0x798877  83c408                            add    esp,0x8
0x79887a  85c0                              test   eax,eax
0x79887c  743e                              je     0x7988bc
0x79887e  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
0x798881  397de8                            cmp    DWORD PTR [ebp-0x18],edi
0x798884  7303                              jae    0x798889
0x798886  8d45d4                            lea    eax,[ebp-0x2c]
0x798889  50                                push   eax
0x79888a  56                                push   esi
0x79888b  6830f2c400                        push   0xc4f230
0x798890  e828a80f00                        call   0x8930bd
0x798895  83c40c                            add    esp,0xc
0x798898  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x79889f  397de8                            cmp    DWORD PTR [ebp-0x18],edi
0x7988a2  720c                              jb     0x7988b0
0x7988a4  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
0x7988a7  50                                push   eax
0x7988a8  e85f890f00                        call   0x89120c
0x7988ad  83c404                            add    esp,0x4
0x7988b0  837dc800                          cmp    DWORD PTR [ebp-0x38],0x0
0x7988b4  0f8796feffff                      ja     0x798750
0x7988ba  eb1e                              jmp    0x7988da
0x7988bc  8b4dd0                            mov    ecx,DWORD PTR [ebp-0x30]
0x7988bf  c781cc00000000000000              mov    DWORD PTR [ecx+0xcc],0x0
0x7988c9  397de8                            cmp    DWORD PTR [ebp-0x18],edi
0x7988cc  720c                              jb     0x7988da
0x7988ce  8b55d4                            mov    edx,DWORD PTR [ebp-0x2c]
0x7988d1  52                                push   edx
0x7988d2  e835890f00                        call   0x89120c
0x7988d7  83c404                            add    esp,0x4
0x7988da  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x7988dd  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x7988e4  59                                pop    ecx
0x7988e5  5f                                pop    edi
0x7988e6  5e                                pop    esi
0x7988e7  5b                                pop    ebx
0x7988e8  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x7988eb  33cd                              xor    ecx,ebp
0x7988ed  e80f870f00                        call   0x891001
0x7988f2  8be5                              mov    esp,ebp
0x7988f4  5d                                pop    ebp
0x7988f5  c20800                            ret    0x8

; U09 Tutorial namespace and receiver binding
; VA 0x4aa5a0..0x4aa675 raw 0xa99a0 length 213 SHA256 7b198aa4b837241a2280cacaebdbf76857375b17a7edac95cf415c3480660dbf
0x4aa5a0  55                                push   ebp
0x4aa5a1  8bec                              mov    ebp,esp
0x4aa5a3  51                                push   ecx
0x4aa5a4  53                                push   ebx
0x4aa5a5  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x4aa5a8  56                                push   esi
0x4aa5a9  8b33                              mov    esi,DWORD PTR [ebx]
0x4aa5ab  a30418fe00                        mov    ds:0xfe1804,eax
0x4aa5b0  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x4aa5b3  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x4aa5b6  57                                push   edi
0x4aa5b7  891d0018fe00                      mov    DWORD PTR ds:0xfe1800,ebx
0x4aa5bd  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x4aa5c0  7207                              jb     0x4aa5c9
0x4aa5c2  8bc6                              mov    eax,esi
0x4aa5c4  e8d70d2500                        call   0x6fb3a0
0x4aa5c9  8b7e08                            mov    edi,DWORD PTR [esi+0x8]
0x4aa5cc  6a00                              push   0x0
0x4aa5ce  6a00                              push   0x0
0x4aa5d0  56                                push   esi
0x4aa5d1  e8caf32400                        call   0x6f99a0
0x4aa5d6  8907                              mov    DWORD PTR [edi],eax
0x4aa5d8  c7470805000000                    mov    DWORD PTR [edi+0x8],0x5
0x4aa5df  83460810                          add    DWORD PTR [esi+0x8],0x10
0x4aa5e3  8b33                              mov    esi,DWORD PTR [ebx]
0x4aa5e5  83c40c                            add    esp,0xc
0x4aa5e8  bf5868c000                        mov    edi,0xc06858
0x4aa5ed  b8eed8ffff                        mov    eax,0xffffd8ee
0x4aa5f2  e899b12400                        call   0x6f5790
0x4aa5f7  8b33                              mov    esi,DWORD PTR [ebx]
0x4aa5f9  b8eed8ffff                        mov    eax,0xffffd8ee
0x4aa5fe  e87db02400                        call   0x6f5680
0x4aa603  8b03                              mov    eax,DWORD PTR [ebx]
0x4aa605  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x4aa608  83e810                            sub    eax,0x10
0x4aa60b  bff0ffffff                        mov    edi,0xfffffff0
0x4aa610  3dc8bfc000                        cmp    eax,0xc0bfc8
0x4aa615  7406                              je     0x4aa61d
0x4aa617  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x4aa61b  7417                              je     0x4aa634
0x4aa61d  685868c000                        push   0xc06858
0x4aa622  68c426c400                        push   0xc426c4
0x4aa627  e8918a3e00                        call   0x8930bd
0x4aa62c  8b03                              mov    eax,DWORD PTR [ebx]
0x4aa62e  83c408                            add    esp,0x8
0x4aa631  017808                            add    DWORD PTR [eax+0x8],edi
0x4aa634  8b33                              mov    esi,DWORD PTR [ebx]
0x4aa636  682462c000                        push   0xc06224
0x4aa63b  e8d0ae2400                        call   0x6f5510
0x4aa640  8b33                              mov    esi,DWORD PTR [ebx]
0x4aa642  83c404                            add    esp,0x4
0x4aa645  6a00                              push   0x0
0x4aa647  68e0bb4a00                        push   0x4abbe0
0x4aa64c  e85faf2400                        call   0x6f55b0
0x4aa651  8b13                              mov    edx,DWORD PTR [ebx]
0x4aa653  52                                push   edx
0x4aa654  b8fdffffff                        mov    eax,0xfffffffd
0x4aa659  e892b12400                        call   0x6f57f0
0x4aa65e  8b1b                              mov    ebx,DWORD PTR [ebx]
0x4aa660  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4aa663  83c40c                            add    esp,0xc
0x4aa666  017b08                            add    DWORD PTR [ebx+0x8],edi
0x4aa669  5f                                pop    edi
0x4aa66a  5e                                pop    esi
0x4aa66b  c7005868c000                      mov    DWORD PTR [eax],0xc06858
0x4aa671  5b                                pop    ebx
0x4aa672  59                                pop    ecx
0x4aa673  5d                                pop    ebp
0x4aa674  c3                                ret

; U05 Tutorial ApplyDefaultCamera() ->54C410(FBAAF8)
; VA 0x4a9720..0x4a972d raw 0xa8b20 length 13 SHA256 4250b5de2eab619e727508841611bb89ac323b6bbd0b619d0a94ac0fe1389eed
0x4a9720  51                                push   ecx
0x4a9721  68f8aafb00                        push   0xfbaaf8
0x4a9726  e8e52c0a00                        call   0x54c410
0x4a972b  59                                pop    ecx
0x4a972c  c3                                ret

; F01 Fade owner constructor + binding bootstrap
; VA 0x55e680..0x55e734 raw 0x15da80 length 180 SHA256 ff3e743476a179f2906c4eb42e89f4da17fde91838d996e796914efeaf5dbf10
0x55e680  55                                push   ebp
0x55e681  8bec                              mov    ebp,esp
0x55e683  6aff                              push   0xffffffff
0x55e685  68be4e9400                        push   0x944ebe
0x55e68a  64a100000000                      mov    eax,fs:0x0
0x55e690  50                                push   eax
0x55e691  83ec08                            sub    esp,0x8
0x55e694  a1201fd600                        mov    eax,ds:0xd61f20
0x55e699  33c5                              xor    eax,ebp
0x55e69b  50                                push   eax
0x55e69c  8d45f4                            lea    eax,[ebp-0xc]
0x55e69f  64a300000000                      mov    fs:0x0,eax
0x55e6a5  33c0                              xor    eax,eax
0x55e6a7  b901000000                        mov    ecx,0x1
0x55e6ac  c7054827fe0000040000              mov    DWORD PTR ds:0xfe2748,0x400
0x55e6b6  c7054c27fe0000030000              mov    DWORD PTR ds:0xfe274c,0x300
0x55e6c0  a35027fe00                        mov    ds:0xfe2750,eax
0x55e6c5  a35427fe00                        mov    ds:0xfe2754,eax
0x55e6ca  a35827fe00                        mov    ds:0xfe2758,eax
0x55e6cf  a35c27fe00                        mov    ds:0xfe275c,eax
0x55e6d4  a36027fe00                        mov    ds:0xfe2760,eax
0x55e6d9  840dd4f3fd00                      test   BYTE PTR ds:0xfdf3d4,cl
0x55e6df  7522                              jne    0x55e703
0x55e6e1  090dd4f3fd00                      or     DWORD PTR ds:0xfdf3d4,ecx
0x55e6e7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x55e6ea  e8915c1900                        call   0x6f4380
0x55e6ef  68d0e6bc00                        push   0xbce6d0
0x55e6f4  e8213c3300                        call   0x89231a
0x55e6f9  83c404                            add    esp,0x4
0x55e6fc  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x55e703  8d45f0                            lea    eax,[ebp-0x10]
0x55e706  68c8f3fd00                        push   0xfdf3c8
0x55e70b  50                                push   eax
0x55e70c  e83f010000                        call   0x55e850
0x55e711  83c408                            add    esp,0x8
0x55e714  50                                push   eax
0x55e715  e816020000                        call   0x55e930
0x55e71a  50                                push   eax
0x55e71b  e8b0020000                        call   0x55e9d0
0x55e720  b84427fe00                        mov    eax,0xfe2744
0x55e725  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x55e728  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x55e72f  59                                pop    ecx
0x55e730  8be5                              mov    esp,ebp
0x55e732  5d                                pop    ebp
0x55e733  c3                                ret

; F02 Fade namespace and FE1F30 receiver
; VA 0x55e850..0x55e92a raw 0x15dc50 length 218 SHA256 cc829a31f43bd52ed6d8c2222b1cfc837425a336e372e7a0193ea1adaa238583
0x55e850  55                                push   ebp
0x55e851  8bec                              mov    ebp,esp
0x55e853  51                                push   ecx
0x55e854  53                                push   ebx
0x55e855  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x55e858  56                                push   esi
0x55e859  8b33                              mov    esi,DWORD PTR [ebx]
0x55e85b  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x55e85e  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x55e861  57                                push   edi
0x55e862  891d2c1ffe00                      mov    DWORD PTR ds:0xfe1f2c,ebx
0x55e868  c705301ffe004427fe00              mov    DWORD PTR ds:0xfe1f30,0xfe2744
0x55e872  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x55e875  7207                              jb     0x55e87e
0x55e877  8bc6                              mov    eax,esi
0x55e879  e822cb1900                        call   0x6fb3a0
0x55e87e  8b7e08                            mov    edi,DWORD PTR [esi+0x8]
0x55e881  6a00                              push   0x0
0x55e883  6a00                              push   0x0
0x55e885  56                                push   esi
0x55e886  e815b11900                        call   0x6f99a0
0x55e88b  8907                              mov    DWORD PTR [edi],eax
0x55e88d  c7470805000000                    mov    DWORD PTR [edi+0x8],0x5
0x55e894  83460810                          add    DWORD PTR [esi+0x8],0x10
0x55e898  8b33                              mov    esi,DWORD PTR [ebx]
0x55e89a  83c40c                            add    esp,0xc
0x55e89d  bf0806c100                        mov    edi,0xc10608
0x55e8a2  b8eed8ffff                        mov    eax,0xffffd8ee
0x55e8a7  e8e46e1900                        call   0x6f5790
0x55e8ac  8b33                              mov    esi,DWORD PTR [ebx]
0x55e8ae  b8eed8ffff                        mov    eax,0xffffd8ee
0x55e8b3  e8c86d1900                        call   0x6f5680
0x55e8b8  8b03                              mov    eax,DWORD PTR [ebx]
0x55e8ba  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x55e8bd  83e810                            sub    eax,0x10
0x55e8c0  bff0ffffff                        mov    edi,0xfffffff0
0x55e8c5  3dc8bfc000                        cmp    eax,0xc0bfc8
0x55e8ca  7406                              je     0x55e8d2
0x55e8cc  83780805                          cmp    DWORD PTR [eax+0x8],0x5
0x55e8d0  7417                              je     0x55e8e9
0x55e8d2  680806c100                        push   0xc10608
0x55e8d7  68c426c400                        push   0xc426c4
0x55e8dc  e8dc473300                        call   0x8930bd
0x55e8e1  8b03                              mov    eax,DWORD PTR [ebx]
0x55e8e3  83c408                            add    esp,0x8
0x55e8e6  017808                            add    DWORD PTR [eax+0x8],edi
0x55e8e9  8b33                              mov    esi,DWORD PTR [ebx]
0x55e8eb  682462c000                        push   0xc06224
0x55e8f0  e81b6c1900                        call   0x6f5510
0x55e8f5  8b33                              mov    esi,DWORD PTR [ebx]
0x55e8f7  83c404                            add    esp,0x4
0x55e8fa  6a00                              push   0x0
0x55e8fc  6870ea5500                        push   0x55ea70
0x55e901  e8aa6c1900                        call   0x6f55b0
0x55e906  8b13                              mov    edx,DWORD PTR [ebx]
0x55e908  52                                push   edx
0x55e909  b8fdffffff                        mov    eax,0xfffffffd
0x55e90e  e8dd6e1900                        call   0x6f57f0
0x55e913  8b1b                              mov    ebx,DWORD PTR [ebx]
0x55e915  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x55e918  83c40c                            add    esp,0xc
0x55e91b  017b08                            add    DWORD PTR [ebx+0x8],edi
0x55e91e  5f                                pop    edi
0x55e91f  5e                                pop    esi
0x55e920  c7000806c100                      mov    DWORD PTR [eax],0xc10608
0x55e926  5b                                pop    ebx
0x55e927  59                                pop    ecx
0x55e928  5d                                pop    ebp
0x55e929  c3                                ret

; F03 Fade.Start(dir,count)
; VA 0x55e740..0x55e76d raw 0x15db40 length 45 SHA256 e6b07bd8085e11e6af11011518708139702fdd1bdc7ed7cac56350a1a9633d19
0x55e740  55                                push   ebp
0x55e741  8bec                              mov    ebp,esp
0x55e743  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x55e746  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x55e749  894114                            mov    DWORD PTR [ecx+0x14],eax
0x55e74c  f7d8                              neg    eax
0x55e74e  1bc0                              sbb    eax,eax
0x55e750  25ff000000                        and    eax,0xff
0x55e755  895118                            mov    DWORD PTR [ecx+0x18],edx
0x55e758  c7411c00000000                    mov    DWORD PTR [ecx+0x1c],0x0
0x55e75f  c7410c01000000                    mov    DWORD PTR [ecx+0xc],0x1
0x55e766  894110                            mov    DWORD PTR [ecx+0x10],eax
0x55e769  5d                                pop    ebp
0x55e76a  c20800                            ret    0x8

; F04 Fade.End(clear) does not clear alpha for zero
; VA 0x55e770..0x55e784 raw 0x15db70 length 20 SHA256 a5d13182a7a0d4538fec9683f092df8dd3961894153c4f29fa758d5642b7c87b
0x55e770  55                                push   ebp
0x55e771  8bec                              mov    ebp,esp
0x55e773  33c0                              xor    eax,eax
0x55e775  89410c                            mov    DWORD PTR [ecx+0xc],eax
0x55e778  394508                            cmp    DWORD PTR [ebp+0x8],eax
0x55e77b  7403                              je     0x55e780
0x55e77d  894110                            mov    DWORD PTR [ecx+0x10],eax
0x55e780  5d                                pop    ebp
0x55e781  c20400                            ret    0x4

; F05 One eligible tick increments counter and computes alpha
; VA 0x55e790..0x55e7ef raw 0x15db90 length 95 SHA256 46af6f1cea738561ae0ba65a06c37b86327d52b859d4b36b36afc5ea1f122469
0x55e790  55                                push   ebp
0x55e791  8bec                              mov    ebp,esp
0x55e793  51                                push   ecx
0x55e794  837e0c00                          cmp    DWORD PTR [esi+0xc],0x0
0x55e798  7451                              je     0x55e7eb
0x55e79a  ff461c                            inc    DWORD PTR [esi+0x1c]
0x55e79d  8b461c                            mov    eax,DWORD PTR [esi+0x1c]
0x55e7a0  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x55e7a3  db45fc                            fild   DWORD PTR [ebp-0x4]
0x55e7a6  da7618                            fidiv  DWORD PTR [esi+0x18]
0x55e7a9  dc0d8856c500                      fmul   QWORD PTR ds:0xc55688
0x55e7af  e85c053a00                        call   0x8fed10
0x55e7b4  837e1400                          cmp    DWORD PTR [esi+0x14],0x0
0x55e7b8  7420                              je     0x55e7da
0x55e7ba  b9ff000000                        mov    ecx,0xff
0x55e7bf  2bc8                              sub    ecx,eax
0x55e7c1  894e10                            mov    DWORD PTR [esi+0x10],ecx
0x55e7c4  85c9                              test   ecx,ecx
0x55e7c6  7f23                              jg     0x55e7eb
0x55e7c8  c7461000000000                    mov    DWORD PTR [esi+0x10],0x0
0x55e7cf  c7460c00000000                    mov    DWORD PTR [esi+0xc],0x0
0x55e7d6  8be5                              mov    esp,ebp
0x55e7d8  5d                                pop    ebp
0x55e7d9  c3                                ret
0x55e7da  894610                            mov    DWORD PTR [esi+0x10],eax
0x55e7dd  3dff000000                        cmp    eax,0xff
0x55e7e2  7c07                              jl     0x55e7eb
0x55e7e4  c74610ff000000                    mov    DWORD PTR [esi+0x10],0xff
0x55e7eb  8be5                              mov    esp,ebp
0x55e7ed  5d                                pop    ebp
0x55e7ee  c3                                ret

; F06 Overlay draw checks texture/alpha, not active
; VA 0x55e7f0..0x55e84c raw 0x15dbf0 length 92 SHA256 b5900753da44c971ddf9c1edea543fd2990324dca1caa9a9c08c71ec2f8819e4
0x55e7f0  55                                push   ebp
0x55e7f1  8bec                              mov    ebp,esp
0x55e7f3  8b08                              mov    ecx,DWORD PTR [eax]
0x55e7f5  83ec08                            sub    esp,0x8
0x55e7f8  85c9                              test   ecx,ecx
0x55e7fa  744c                              je     0x55e848
0x55e7fc  83781001                          cmp    DWORD PTR [eax+0x10],0x1
0x55e800  7e46                              jle    0x55e848
0x55e802  db4004                            fild   DWORD PTR [eax+0x4]
0x55e805  dd05e858c500                      fld    QWORD PTR ds:0xc558e8
0x55e80b  dcc9                              fmul   st(1),st
0x55e80d  dd05a056c500                      fld    QWORD PTR ds:0xc556a0
0x55e813  dcc2                              fadd   st(2),st
0x55e815  d9ca                              fxch   st(2)
0x55e817  d95df8                            fstp   DWORD PTR [ebp-0x8]
0x55e81a  da4808                            fimul  DWORD PTR [eax+0x8]
0x55e81d  0fb64010                          movzx  eax,BYTE PTR [eax+0x10]
0x55e821  c1e018                            shl    eax,0x18
0x55e824  0dffffff00                        or     eax,0xffffff
0x55e829  50                                push   eax
0x55e82a  51                                push   ecx
0x55e82b  8d45f8                            lea    eax,[ebp-0x8]
0x55e82e  dec1                              faddp  st(1),st
0x55e830  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x55e833  8b11                              mov    edx,DWORD PTR [ecx]
0x55e835  d9ee                              fldz
0x55e837  8b5224                            mov    edx,DWORD PTR [edx+0x24]
0x55e83a  d91c24                            fstp   DWORD PTR [esp]
0x55e83d  6a00                              push   0x0
0x55e83f  50                                push   eax
0x55e840  6a00                              push   0x0
0x55e842  6ae0                              push   0xffffffe0
0x55e844  6ae0                              push   0xffffffe0
0x55e846  ffd2                              call   edx
0x55e848  8be5                              mov    esp,ebp
0x55e84a  5d                                pop    ebp
0x55e84b  c3                                ret

; F07 Q FadeOut numeric count
; VA 0x564f30..0x564fb0 raw 0x164330 length 128 SHA256 b013bd76f3f362a77c8efce6a6f584d0d599d5fa8ffb558659a323a59ee4e549
0x564f30  55                                push   ebp
0x564f31  8bec                              mov    ebp,esp
0x564f33  6aff                              push   0xffffffff
0x564f35  680eac9300                        push   0x93ac0e
0x564f3a  64a100000000                      mov    eax,fs:0x0
0x564f40  50                                push   eax
0x564f41  56                                push   esi
0x564f42  a1201fd600                        mov    eax,ds:0xd61f20
0x564f47  33c5                              xor    eax,ebp
0x564f49  50                                push   eax
0x564f4a  8d45f4                            lea    eax,[ebp-0xc]
0x564f4d  64a300000000                      mov    fs:0x0,eax
0x564f53  33f6                              xor    esi,esi
0x564f55  f6054027fe0001                    test   BYTE PTR ds:0xfe2740,0x1
0x564f5c  751c                              jne    0x564f7a
0x564f5e  830d4027fe0001                    or     DWORD PTR ds:0xfe2740,0x1
0x564f65  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x564f68  e81397ffff                        call   0x55e680
0x564f6d  68a0f2bc00                        push   0xbcf2a0
0x564f72  e8a3d33200                        call   0x89231a
0x564f77  83c404                            add    esp,0x4
0x564f7a  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x564f7d  89355827fe00                      mov    DWORD PTR ds:0xfe2758,esi
0x564f83  a35c27fe00                        mov    ds:0xfe275c,eax
0x564f88  89356027fe00                      mov    DWORD PTR ds:0xfe2760,esi
0x564f8e  c7055027fe0001000000              mov    DWORD PTR ds:0xfe2750,0x1
0x564f98  89355427fe00                      mov    DWORD PTR ds:0xfe2754,esi
0x564f9e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x564fa1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x564fa8  59                                pop    ecx
0x564fa9  5e                                pop    esi
0x564faa  8be5                              mov    esp,ebp
0x564fac  5d                                pop    ebp
0x564fad  c20400                            ret    0x4

; F08 Q FadeIn numeric count
; VA 0x564fb0..0x565039 raw 0x1643b0 length 137 SHA256 648e3db54d618988c2e5df72fdb555e550c1f12959d5dae1cf4d28997c0c8c34
0x564fb0  55                                push   ebp
0x564fb1  8bec                              mov    ebp,esp
0x564fb3  6aff                              push   0xffffffff
0x564fb5  680eac9300                        push   0x93ac0e
0x564fba  64a100000000                      mov    eax,fs:0x0
0x564fc0  50                                push   eax
0x564fc1  53                                push   ebx
0x564fc2  a1201fd600                        mov    eax,ds:0xd61f20
0x564fc7  33c5                              xor    eax,ebp
0x564fc9  50                                push   eax
0x564fca  8d45f4                            lea    eax,[ebp-0xc]
0x564fcd  64a300000000                      mov    fs:0x0,eax
0x564fd3  bb01000000                        mov    ebx,0x1
0x564fd8  841d4027fe00                      test   BYTE PTR ds:0xfe2740,bl
0x564fde  751f                              jne    0x564fff
0x564fe0  091d4027fe00                      or     DWORD PTR ds:0xfe2740,ebx
0x564fe6  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x564fed  e88e96ffff                        call   0x55e680
0x564ff2  68a0f2bc00                        push   0xbcf2a0
0x564ff7  e81ed33200                        call   0x89231a
0x564ffc  83c404                            add    esp,0x4
0x564fff  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x565002  891d5827fe00                      mov    DWORD PTR ds:0xfe2758,ebx
0x565008  a35c27fe00                        mov    ds:0xfe275c,eax
0x56500d  c7056027fe0000000000              mov    DWORD PTR ds:0xfe2760,0x0
0x565017  891d5027fe00                      mov    DWORD PTR ds:0xfe2750,ebx
0x56501d  c7055427fe00ff000000              mov    DWORD PTR ds:0xfe2754,0xff
0x565027  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x56502a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x565031  59                                pop    ecx
0x565032  5b                                pop    ebx
0x565033  8be5                              mov    esp,ebp
0x565035  5d                                pop    ebp
0x565036  c20400                            ret    0x4

; F09 Q FadeColor packed integer
; VA 0x565040..0x5650b7 raw 0x164440 length 119 SHA256 b80afc407a139ae44115768d1dceb7ee4e01b2559b2c3e45100febbfd11d2977
0x565040  55                                push   ebp
0x565041  8bec                              mov    ebp,esp
0x565043  6aff                              push   0xffffffff
0x565045  680eac9300                        push   0x93ac0e
0x56504a  64a100000000                      mov    eax,fs:0x0
0x565050  50                                push   eax
0x565051  a1201fd600                        mov    eax,ds:0xd61f20
0x565056  51                                push   ecx
0x565057  33c5                              xor    eax,ebp
0x565059  50                                push   eax
0x56505a  8d45f4                            lea    eax,[ebp-0xc]
0x56505d  64a300000000                      mov    fs:0x0,eax
0x565063  b801000000                        mov    eax,0x1
0x565068  84054027fe00                      test   BYTE PTR ds:0xfe2740,al
0x56506e  7526                              jne    0x565096
0x565070  09054027fe00                      or     DWORD PTR ds:0xfe2740,eax
0x565076  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x56507d  e8fe95ffff                        call   0x55e680
0x565082  68a0f2bc00                        push   0xbcf2a0
0x565087  e88ed23200                        call   0x89231a
0x56508c  83c404                            add    esp,0x4
0x56508f  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x565096  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x565099  8b0d4427fe00                      mov    ecx,DWORD PTR ds:0xfe2744
0x56509f  50                                push   eax
0x5650a0  51                                push   ecx
0x5650a1  e8caf31c00                        call   0x734470
0x5650a6  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5650a9  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5650b0  59                                pop    ecx
0x5650b1  8be5                              mov    esp,ebp
0x5650b3  5d                                pop    ebp
0x5650b4  c20400                            ret    0x4

; F10 Fill texture pixel color
; VA 0x734470..0x73459b raw 0x333870 length 299 SHA256 9b794178c07319604d5f05e54852125a8b52416c969c07d8682bcbdd5d02035e
0x734470  55                                push   ebp
0x734471  8bec                              mov    ebp,esp
0x734473  83ec34                            sub    esp,0x34
0x734476  a1201fd600                        mov    eax,ds:0xd61f20
0x73447b  33c5                              xor    eax,ebp
0x73447d  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x734480  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x734483  83784400                          cmp    DWORD PTR [eax+0x44],0x0
0x734487  53                                push   ebx
0x734488  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x73448b  56                                push   esi
0x73448c  57                                push   edi
0x73448d  8945d4                            mov    DWORD PTR [ebp-0x2c],eax
0x734490  7518                              jne    0x7344aa
0x734492  b805400080                        mov    eax,0x80004005
0x734497  5f                                pop    edi
0x734498  5e                                pop    esi
0x734499  5b                                pop    ebx
0x73449a  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x73449d  33cd                              xor    ecx,ebp
0x73449f  e85dcb1500                        call   0x891001
0x7344a4  8be5                              mov    esp,ebp
0x7344a6  5d                                pop    ebp
0x7344a7  c20800                            ret    0x8
0x7344aa  8b4044                            mov    eax,DWORD PTR [eax+0x44]
0x7344ad  8b10                              mov    edx,DWORD PTR [eax]
0x7344af  8b5244                            mov    edx,DWORD PTR [edx+0x44]
0x7344b2  0fb6cb                            movzx  ecx,bl
0x7344b5  894dd8                            mov    DWORD PTR [ebp-0x28],ecx
0x7344b8  8d4ddc                            lea    ecx,[ebp-0x24]
0x7344bb  51                                push   ecx
0x7344bc  8bf3                              mov    esi,ebx
0x7344be  8bfb                              mov    edi,ebx
0x7344c0  6a00                              push   0x0
0x7344c2  c1ee10                            shr    esi,0x10
0x7344c5  c1ef08                            shr    edi,0x8
0x7344c8  50                                push   eax
0x7344c9  81e6ff000000                      and    esi,0xff
0x7344cf  81e7ff000000                      and    edi,0xff
0x7344d5  ffd2                              call   edx
0x7344d7  8b45dc                            mov    eax,DWORD PTR [ebp-0x24]
0x7344da  83f81a                            cmp    eax,0x1a
0x7344dd  751b                              jne    0x7344fa
0x7344df  8b45d8                            mov    eax,DWORD PTR [ebp-0x28]
0x7344e2  83e6f0                            and    esi,0xfffffff0
0x7344e5  8d9e000f0000                      lea    ebx,[esi+0xf00]
0x7344eb  c1e304                            shl    ebx,0x4
0x7344ee  c1e804                            shr    eax,0x4
0x7344f1  03d8                              add    ebx,eax
0x7344f3  83e7f0                            and    edi,0xfffffff0
0x7344f6  03df                              add    ebx,edi
0x7344f8  eb2a                              jmp    0x734524
0x7344fa  83f819                            cmp    eax,0x19
0x7344fd  751c                              jne    0x73451b
0x7344ff  8b5dd8                            mov    ebx,DWORD PTR [ebp-0x28]
0x734502  83e6f8                            and    esi,0xfffffff8
0x734505  81c600010000                      add    esi,0x100
0x73450b  c1e605                            shl    esi,0x5
0x73450e  83e7f8                            and    edi,0xfffffff8
0x734511  03f7                              add    esi,edi
0x734513  c1eb03                            shr    ebx,0x3
0x734516  8d1cb3                            lea    ebx,[ebx+esi*4]
0x734519  eb09                              jmp    0x734524
0x73451b  83f815                            cmp    eax,0x15
0x73451e  0f856effffff                      jne    0x734492
0x734524  8b75d4                            mov    esi,DWORD PTR [ebp-0x2c]
0x734527  8b4644                            mov    eax,DWORD PTR [esi+0x44]
0x73452a  8b08                              mov    ecx,DWORD PTR [eax]
0x73452c  6a00                              push   0x0
0x73452e  6a00                              push   0x0
0x734530  8d55cc                            lea    edx,[ebp-0x34]
0x734533  52                                push   edx
0x734534  6a00                              push   0x0
0x734536  50                                push   eax
0x734537  8b414c                            mov    eax,DWORD PTR [ecx+0x4c]
0x73453a  ffd0                              call   eax
0x73453c  85c0                              test   eax,eax
0x73453e  0f884effffff                      js     0x734492
0x734544  33d2                              xor    edx,edx
0x734546  3955f8                            cmp    DWORD PTR [ebp-0x8],edx
0x734549  762e                              jbe    0x734579
0x73454b  8b45f4                            mov    eax,DWORD PTR [ebp-0xc]
0x73454e  33c9                              xor    ecx,ecx
0x734550  85c0                              test   eax,eax
0x734552  741f                              je     0x734573
0x734554  8b7dd0                            mov    edi,DWORD PTR [ebp-0x30]
0x734557  0fafc2                            imul   eax,edx
0x73455a  03c1                              add    eax,ecx
0x73455c  837ddc15                          cmp    DWORD PTR [ebp-0x24],0x15
0x734560  7505                              jne    0x734567
0x734562  891c87                            mov    DWORD PTR [edi+eax*4],ebx
0x734565  eb04                              jmp    0x73456b
0x734567  66891c47                          mov    WORD PTR [edi+eax*2],bx
0x73456b  8b45f4                            mov    eax,DWORD PTR [ebp-0xc]
0x73456e  41                                inc    ecx
0x73456f  3bc8                              cmp    ecx,eax
0x734571  72e1                              jb     0x734554
0x734573  42                                inc    edx
0x734574  3b55f8                            cmp    edx,DWORD PTR [ebp-0x8]
0x734577  72d5                              jb     0x73454e
0x734579  8b4644                            mov    eax,DWORD PTR [esi+0x44]
0x73457c  8b08                              mov    ecx,DWORD PTR [eax]
0x73457e  8b5150                            mov    edx,DWORD PTR [ecx+0x50]
0x734581  6a00                              push   0x0
0x734583  50                                push   eax
0x734584  ffd2                              call   edx
0x734586  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x734589  5f                                pop    edi
0x73458a  5e                                pop    esi
0x73458b  33cd                              xor    ecx,ebp
0x73458d  33c0                              xor    eax,eax
0x73458f  5b                                pop    ebx
0x734590  e86cca1500                        call   0x891001
0x734595  8be5                              mov    esp,ebp
0x734597  5d                                pop    ebp
0x734598  c20800                            ret    0x8

; T01 Q Transition two integers
; VA 0x5646a0..0x5646de raw 0x163aa0 length 62 SHA256 4197256a72e1468f085d6948624d339ebd509ec394d15e2dedbfd95c1e00c216
0x5646a0  55                                push   ebp
0x5646a1  8bec                              mov    ebp,esp
0x5646a3  b801000000                        mov    eax,0x1
0x5646a8  8405f02cfd00                      test   BYTE PTR ds:0xfd2cf0,al
0x5646ae  7518                              jne    0x5646c8
0x5646b0  0905f02cfd00                      or     DWORD PTR ds:0xfd2cf0,eax
0x5646b6  e8d5391d00                        call   0x738090
0x5646bb  6880e6bc00                        push   0xbce680
0x5646c0  e855dc3200                        call   0x89231a
0x5646c5  83c404                            add    esp,0x4
0x5646c8  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x5646cb  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x5646ce  56                                push   esi
0x5646cf  beb82bfd00                        mov    esi,0xfd2bb8
0x5646d4  e8273a1d00                        call   0x738100
0x5646d9  5e                                pop    esi
0x5646da  5d                                pop    ebp
0x5646db  c20800                            ret    0x8

; T02 Transition owner ctor, capacity32, disabled initially
; VA 0x738090..0x7380fb raw 0x337490 length 107 SHA256 d3e398a8a5589e2a868777e8d71c238409063e823c749e2e772acaf207e80cb7
0x738090  d9e8                              fld1
0x738092  33c0                              xor    eax,eax
0x738094  d9051057c500                      fld    DWORD PTR ds:0xc55710
0x73809a  b901000000                        mov    ecx,0x1
0x73809f  a3b82bfd00                        mov    ds:0xfd2bb8,eax
0x7380a4  a3cc2bfd00                        mov    ds:0xfd2bcc,eax
0x7380a9  a3d02cfd00                        mov    ds:0xfd2cd0,eax
0x7380ae  a3d42cfd00                        mov    ds:0xfd2cd4,eax
0x7380b3  a3e82cfd00                        mov    ds:0xfd2ce8,eax
0x7380b8  a3ec2cfd00                        mov    ds:0xfd2cec,eax
0x7380bd  890dd82cfd00                      mov    DWORD PTR ds:0xfd2cd8,ecx
0x7380c3  890ddc2cfd00                      mov    DWORD PTR ds:0xfd2cdc,ecx
0x7380c9  890de02cfd00                      mov    DWORD PTR ds:0xfd2ce0,ecx
0x7380cf  890de42cfd00                      mov    DWORD PTR ds:0xfd2ce4,ecx
0x7380d5  b8502cfd00                        mov    eax,0xfd2c50
0x7380da  d9c9                              fxch   st(1)
0x7380dc  83c004                            add    eax,0x4
0x7380df  d9907cffffff                      fst    DWORD PTR [eax-0x84]
0x7380e5  d9c9                              fxch   st(1)
0x7380e7  d950fc                            fst    DWORD PTR [eax-0x4]
0x7380ea  3dd02cfd00                        cmp    eax,0xfd2cd0
0x7380ef  7ce9                              jl     0x7380da
0x7380f1  ddd9                              fstp   st(1)
0x7380f3  b8b82bfd00                        mov    eax,0xfd2bb8
0x7380f8  ddd8                              fstp   st(0)
0x7380fa  c3                                ret

; T03 Transition request / -1 default substitution / reset
; VA 0x738100..0x738157 raw 0x337500 length 87 SHA256 17151c2b56c754076f860bc798261036d363782f9621147aa18b863e8edd5fbb
0x738100  833e00                            cmp    DWORD PTR [esi],0x0
0x738103  7451                              je     0x738156
0x738105  83f9ff                            cmp    ecx,0xffffffff
0x738108  740d                              je     0x738117
0x73810a  83f8ff                            cmp    eax,0xffffffff
0x73810d  7408                              je     0x738117
0x73810f  894e0c                            mov    DWORD PTR [esi+0xc],ecx
0x738112  894610                            mov    DWORD PTR [esi+0x10],eax
0x738115  eb0c                              jmp    0x738123
0x738117  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x73811a  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x73811d  89460c                            mov    DWORD PTR [esi+0xc],eax
0x738120  894e10                            mov    DWORD PTR [esi+0x10],ecx
0x738123  8b8e18010000                      mov    ecx,DWORD PTR [esi+0x118]
0x738129  85c9                              test   ecx,ecx
0x73812b  7411                              je     0x73813e
0x73812d  8b11                              mov    edx,DWORD PTR [ecx]
0x73812f  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x738132  ffd0                              call   eax
0x738134  c7861801000000000000              mov    DWORD PTR [esi+0x118],0x0
0x73813e  b801000000                        mov    eax,0x1
0x738143  c7861c01000000000000              mov    DWORD PTR [esi+0x11c],0x0
0x73814d  894614                            mov    DWORD PTR [esi+0x14],eax
0x738150  898630010000                      mov    DWORD PTR [esi+0x130],eax
0x738156  c3                                ret

; T04 Deferred capture, layered scaling+alpha delta tick and release
; VA 0x738160..0x7382f0 raw 0x337560 length 400 SHA256 2376b0d2fdaca78d4a25e27a499d554b24579a42c47dc70b54b94ff6a25941ba
0x738160  55                                push   ebp
0x738161  8bec                              mov    ebp,esp
0x738163  51                                push   ecx
0x738164  8b8630010000                      mov    eax,DWORD PTR [esi+0x130]
0x73816a  53                                push   ebx
0x73816b  33db                              xor    ebx,ebx
0x73816d  3bc3                              cmp    eax,ebx
0x73816f  7e1a                              jle    0x73818b
0x738171  48                                dec    eax
0x738172  898630010000                      mov    DWORD PTR [esi+0x130],eax
0x738178  c705dca7fb0001000000              mov    DWORD PTR ds:0xfba7dc,0x1
0x738182  33c0                              xor    eax,eax
0x738184  5b                                pop    ebx
0x738185  8be5                              mov    esp,ebp
0x738187  5d                                pop    ebp
0x738188  c20400                            ret    0x4
0x73818b  399e1c010000                      cmp    DWORD PTR [esi+0x11c],ebx
0x738191  7554                              jne    0x7381e7
0x738193  8b8e18010000                      mov    ecx,DWORD PTR [esi+0x118]
0x738199  3bcb                              cmp    ecx,ebx
0x73819b  740d                              je     0x7381aa
0x73819d  8b01                              mov    eax,DWORD PTR [ecx]
0x73819f  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x7381a2  ffd2                              call   edx
0x7381a4  899e18010000                      mov    DWORD PTR [esi+0x118],ebx
0x7381aa  8b8628010000                      mov    eax,DWORD PTR [esi+0x128]
0x7381b0  8b8e2c010000                      mov    ecx,DWORD PTR [esi+0x12c]
0x7381b6  50                                push   eax
0x7381b7  c7861c01000001000000              mov    DWORD PTR [esi+0x11c],0x1
0x7381c1  e82ac6ffff                        call   0x7347f0
0x7381c6  8b8e28010000                      mov    ecx,DWORD PTR [esi+0x128]
0x7381cc  8b962c010000                      mov    edx,DWORD PTR [esi+0x12c]
0x7381d2  83c404                            add    esp,0x4
0x7381d5  898618010000                      mov    DWORD PTR [esi+0x118],eax
0x7381db  898e20010000                      mov    DWORD PTR [esi+0x120],ecx
0x7381e1  899624010000                      mov    DWORD PTR [esi+0x124],edx
0x7381e7  399e34010000                      cmp    DWORD PTR [esi+0x134],ebx
0x7381ed  0f85f4000000                      jne    0x7382e7
0x7381f3  d94508                            fld    DWORD PTR [ebp+0x8]
0x7381f6  dc159858c500                      fcom   QWORD PTR ds:0xc55898
0x7381fc  dfe0                              fnstsw ax
0x7381fe  f6c441                            test   ah,0x41
0x738201  7508                              jne    0x73820b
0x738203  ddd8                              fstp   st(0)
0x738205  d9057059c500                      fld    DWORD PTR ds:0xc55970
0x73820b  837e1401                          cmp    DWORD PTR [esi+0x14],0x1
0x73820f  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x738212  7547                              jne    0x73825b
0x738214  33c9                              xor    ecx,ecx
0x738216  395e0c                            cmp    DWORD PTR [esi+0xc],ebx
0x738219  7e39                              jle    0x738254
0x73821b  d9e8                              fld1
0x73821d  8d9698000000                      lea    edx,[esi+0x98]
0x738223  d95280                            fst    DWORD PTR [edx-0x80]
0x738226  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x738229  8d58ff                            lea    ebx,[eax-0x1]
0x73822c  f7db                              neg    ebx
0x73822e  1bdb                              sbb    ebx,ebx
0x738230  0fafc1                            imul   eax,ecx
0x738233  83e381                            and    ebx,0xffffff81
0x738236  81c3ff000000                      add    ebx,0xff
0x73823c  2bd8                              sub    ebx,eax
0x73823e  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x738241  41                                inc    ecx
0x738242  83c204                            add    edx,0x4
0x738245  db45fc                            fild   DWORD PTR [ebp-0x4]
0x738248  d95afc                            fstp   DWORD PTR [edx-0x4]
0x73824b  3b4e0c                            cmp    ecx,DWORD PTR [esi+0xc]
0x73824e  7cd3                              jl     0x738223
0x738250  ddd8                              fstp   st(0)
0x738252  33db                              xor    ebx,ebx
0x738254  c7461402000000                    mov    DWORD PTR [esi+0x14],0x2
0x73825b  837e1402                          cmp    DWORD PTR [esi+0x14],0x2
0x73825f  0f8582000000                      jne    0x7382e7
0x738265  d9ee                              fldz
0x738267  33c0                              xor    eax,eax
0x738269  395e0c                            cmp    DWORD PTR [esi+0xc],ebx
0x73826c  7e50                              jle    0x7382be
0x73826e  d94508                            fld    DWORD PTR [ebp+0x8]
0x738271  8d8e98000000                      lea    ecx,[esi+0x98]
0x738277  dd05085cc500                      fld    QWORD PTR ds:0xc55c08
0x73827d  8d5001                            lea    edx,[eax+0x1]
0x738280  895508                            mov    DWORD PTR [ebp+0x8],edx
0x738283  db4508                            fild   DWORD PTR [ebp+0x8]
0x738286  d8c9                              fmul   st,st(1)
0x738288  d8ca                              fmul   st,st(2)
0x73828a  d84180                            fadd   DWORD PTR [ecx-0x80]
0x73828d  d95980                            fstp   DWORD PTR [ecx-0x80]
0x738290  d901                              fld    DWORD PTR [ecx]
0x738292  db4610                            fild   DWORD PTR [esi+0x10]
0x738295  d8cb                              fmul   st,st(3)
0x738297  dee9                              fsubp  st(1),st
0x738299  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x73829c  d94508                            fld    DWORD PTR [ebp+0x8]
0x73829f  d911                              fst    DWORD PTR [ecx]
0x7382a1  d8db                              fcomp  st(3)
0x7382a3  dfe0                              fnstsw ax
0x7382a5  f6c405                            test   ah,0x5
0x7382a8  7a06                              jp     0x7382b0
0x7382aa  d9ca                              fxch   st(2)
0x7382ac  d911                              fst    DWORD PTR [ecx]
0x7382ae  d9ca                              fxch   st(2)
0x7382b0  8bc2                              mov    eax,edx
0x7382b2  83c104                            add    ecx,0x4
0x7382b5  3b460c                            cmp    eax,DWORD PTR [esi+0xc]
0x7382b8  7cc3                              jl     0x73827d
0x7382ba  ddd9                              fstp   st(1)
0x7382bc  ddd8                              fstp   st(0)
0x7382be  d98698000000                      fld    DWORD PTR [esi+0x98]
0x7382c4  dae9                              fucompp
0x7382c6  dfe0                              fnstsw ax
0x7382c8  f6c444                            test   ah,0x44
0x7382cb  7a1a                              jp     0x7382e7
0x7382cd  8b8e18010000                      mov    ecx,DWORD PTR [esi+0x118]
0x7382d3  3bcb                              cmp    ecx,ebx
0x7382d5  740d                              je     0x7382e4
0x7382d7  8b01                              mov    eax,DWORD PTR [ecx]
0x7382d9  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x7382dc  ffd2                              call   edx
0x7382de  899e18010000                      mov    DWORD PTR [esi+0x118],ebx
0x7382e4  895e14                            mov    DWORD PTR [esi+0x14],ebx
0x7382e7  33c0                              xor    eax,eax
0x7382e9  5b                                pop    ebx
0x7382ea  8be5                              mov    esp,ebp
0x7382ec  5d                                pop    ebp
0x7382ed  c20400                            ret    0x4

; T05 Centered captured-texture layer drawing
; VA 0x7382f0..0x7383d6 raw 0x3376f0 length 230 SHA256 d40fa8841fe2b20bddfdfb5db48e23c0a8c5f873d49e5b37f73610a6b783a94b
0x7382f0  55                                push   ebp
0x7382f1  8bec                              mov    ebp,esp
0x7382f3  83ec20                            sub    esp,0x20
0x7382f6  837f1402                          cmp    DWORD PTR [edi+0x14],0x2
0x7382fa  8b8f28010000                      mov    ecx,DWORD PTR [edi+0x128]
0x738300  894df8                            mov    DWORD PTR [ebp-0x8],ecx
0x738303  db45f8                            fild   DWORD PTR [ebp-0x8]
0x738306  8b872c010000                      mov    eax,DWORD PTR [edi+0x12c]
0x73830c  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x73830f  53                                push   ebx
0x738310  dab720010000                      fidiv  DWORD PTR [edi+0x120]
0x738316  56                                push   esi
0x738317  d95df4                            fstp   DWORD PTR [ebp-0xc]
0x73831a  db45fc                            fild   DWORD PTR [ebp-0x4]
0x73831d  dab724010000                      fidiv  DWORD PTR [edi+0x124]
0x738323  d95df0                            fstp   DWORD PTR [ebp-0x10]
0x738326  0f85a2000000                      jne    0x7383ce
0x73832c  83bf1801000000                    cmp    DWORD PTR [edi+0x118],0x0
0x738333  0f8495000000                      je     0x7383ce
0x738339  837f0c00                          cmp    DWORD PTR [edi+0xc],0x0
0x73833d  c745f800000000                    mov    DWORD PTR [ebp-0x8],0x0
0x738344  0f8e84000000                      jle    0x7383ce
0x73834a  99                                cdq
0x73834b  2bc2                              sub    eax,edx
0x73834d  8bd8                              mov    ebx,eax
0x73834f  8bc1                              mov    eax,ecx
0x738351  99                                cdq
0x738352  2bc2                              sub    eax,edx
0x738354  d1fb                              sar    ebx,1
0x738356  d1f8                              sar    eax,1
0x738358  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x73835b  8d7718                            lea    esi,[edi+0x18]
0x73835e  d906                              fld    DWORD PTR [esi]
0x738360  8b8f18010000                      mov    ecx,DWORD PTR [edi+0x118]
0x738366  d84df4                            fmul   DWORD PTR [ebp-0xc]
0x738369  d97dfe                            fnstcw WORD PTR [ebp-0x2]
0x73836c  0fb745fe                          movzx  eax,WORD PTR [ebp-0x2]
0x738370  d95de0                            fstp   DWORD PTR [ebp-0x20]
0x738373  d906                              fld    DWORD PTR [esi]
0x738375  0d000c0000                        or     eax,0xc00
0x73837a  d84df0                            fmul   DWORD PTR [ebp-0x10]
0x73837d  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x738380  d95de4                            fstp   DWORD PTR [ebp-0x1c]
0x738383  8b11                              mov    edx,DWORD PTR [ecx]
0x738385  d98680000000                      fld    DWORD PTR [esi+0x80]
0x73838b  8b5224                            mov    edx,DWORD PTR [edx+0x24]
0x73838e  d96dec                            fldcw  WORD PTR [ebp-0x14]
0x738391  db5dec                            fistp  DWORD PTR [ebp-0x14]
0x738394  8a45ec                            mov    al,BYTE PTR [ebp-0x14]
0x738397  0fb6c0                            movzx  eax,al
0x73839a  c1e018                            shl    eax,0x18
0x73839d  d96dfe                            fldcw  WORD PTR [ebp-0x2]
0x7383a0  0dffffff00                        or     eax,0xffffff
0x7383a5  50                                push   eax
0x7383a6  51                                push   ecx
0x7383a7  8d45e0                            lea    eax,[ebp-0x20]
0x7383aa  d9ee                              fldz
0x7383ac  d91c24                            fstp   DWORD PTR [esp]
0x7383af  6a01                              push   0x1
0x7383b1  50                                push   eax
0x7383b2  8b45e8                            mov    eax,DWORD PTR [ebp-0x18]
0x7383b5  6a00                              push   0x0
0x7383b7  53                                push   ebx
0x7383b8  50                                push   eax
0x7383b9  ffd2                              call   edx
0x7383bb  85c0                              test   eax,eax
0x7383bd  7811                              js     0x7383d0
0x7383bf  8b45f8                            mov    eax,DWORD PTR [ebp-0x8]
0x7383c2  40                                inc    eax
0x7383c3  83c604                            add    esi,0x4
0x7383c6  8945f8                            mov    DWORD PTR [ebp-0x8],eax
0x7383c9  3b470c                            cmp    eax,DWORD PTR [edi+0xc]
0x7383cc  7c90                              jl     0x73835e
0x7383ce  33c0                              xor    eax,eax
0x7383d0  5e                                pop    esi
0x7383d1  5b                                pop    ebx
0x7383d2  8be5                              mov    esp,ebp
0x7383d4  5d                                pop    ebp
0x7383d5  c3                                ret

; T06 Capture graphics surface into texture
; VA 0x7347f0..0x7349ac raw 0x333bf0 length 444 SHA256 31f67e0245feba988f57ba2153eeab26577d64fa3630ebfb6454a8602625d39e
0x7347f0  55                                push   ebp
0x7347f1  8bec                              mov    ebp,esp
0x7347f3  83e4f8                            and    esp,0xfffffff8
0x7347f6  6aff                              push   0xffffffff
0x7347f8  68f9cc9100                        push   0x91ccf9
0x7347fd  64a100000000                      mov    eax,fs:0x0
0x734803  50                                push   eax
0x734804  83ec38                            sub    esp,0x38
0x734807  a1201fd600                        mov    eax,ds:0xd61f20
0x73480c  33c4                              xor    eax,esp
0x73480e  89442430                          mov    DWORD PTR [esp+0x30],eax
0x734812  53                                push   ebx
0x734813  56                                push   esi
0x734814  57                                push   edi
0x734815  a1201fd600                        mov    eax,ds:0xd61f20
0x73481a  33c4                              xor    eax,esp
0x73481c  50                                push   eax
0x73481d  8d442448                          lea    eax,[esp+0x48]
0x734821  64a300000000                      mov    fs:0x0,eax
0x734827  8bf9                              mov    edi,ecx
0x734829  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x73482c  6a48                              push   0x48
0x73482e  e835ca1500                        call   0x891268
0x734833  83c404                            add    esp,0x4
0x734836  8944241c                          mov    DWORD PTR [esp+0x1c],eax
0x73483a  33f6                              xor    esi,esi
0x73483c  89742450                          mov    DWORD PTR [esp+0x50],esi
0x734840  3bc6                              cmp    eax,esi
0x734842  7409                              je     0x73484d
0x734844  8bf0                              mov    esi,eax
0x734846  e8c5f7ffff                        call   0x734010
0x73484b  8bf0                              mov    esi,eax
0x73484d  57                                push   edi
0x73484e  53                                push   ebx
0x73484f  6a00                              push   0x0
0x734851  6a00                              push   0x0
0x734853  8d442430                          lea    eax,[esp+0x30]
0x734857  50                                push   eax
0x734858  c7442464ffffffff                  mov    DWORD PTR [esp+0x64],0xffffffff
0x734860  ff15f024bd00                      call   DWORD PTR ds:0xbd24f0
0x734866  57                                push   edi
0x734867  53                                push   ebx
0x734868  6a00                              push   0x0
0x73486a  6a00                              push   0x0
0x73486c  8d4c2440                          lea    ecx,[esp+0x40]
0x734870  51                                push   ecx
0x734871  ff15f024bd00                      call   DWORD PTR ds:0xbd24f0
0x734877  53                                push   ebx
0x734878  8bce                              mov    ecx,esi
0x73487a  e851fbffff                        call   0x7343d0
0x73487f  85c0                              test   eax,eax
0x734881  7915                              jns    0x734898
0x734883  85f6                              test   esi,esi
0x734885  740a                              je     0x734891
0x734887  8b16                              mov    edx,DWORD PTR [esi]
0x734889  8b02                              mov    eax,DWORD PTR [edx]
0x73488b  6a01                              push   0x1
0x73488d  8bce                              mov    ecx,esi
0x73488f  ffd0                              call   eax
0x734891  33c0                              xor    eax,eax
0x734893  e9f6000000                        jmp    0x73498e
0x734898  bb01000000                        mov    ebx,0x1
0x73489d  841d40defc00                      test   BYTE PTR ds:0xfcde40,bl
0x7348a3  7524                              jne    0x7348c9
0x7348a5  091d40defc00                      or     DWORD PTR ds:0xfcde40,ebx
0x7348ab  895c2450                          mov    DWORD PTR [esp+0x50],ebx
0x7348af  e8cc1f0000                        call   0x736880
0x7348b4  68f0e6bc00                        push   0xbce6f0
0x7348b9  e85cda1500                        call   0x89231a
0x7348be  83c404                            add    esp,0x4
0x7348c1  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
0x7348c9  a12cdefc00                        mov    eax,ds:0xfcde2c
0x7348ce  8b08                              mov    ecx,DWORD PTR [eax]
0x7348d0  8d542414                          lea    edx,[esp+0x14]
0x7348d4  52                                push   edx
0x7348d5  6a00                              push   0x0
0x7348d7  53                                push   ebx
0x7348d8  6a00                              push   0x0
0x7348da  50                                push   eax
0x7348db  8b4148                            mov    eax,DWORD PTR [ecx+0x48]
0x7348de  ffd0                              call   eax
0x7348e0  85c0                              test   eax,eax
0x7348e2  741f                              je     0x734903
0x7348e4  8b442414                          mov    eax,DWORD PTR [esp+0x14]
0x7348e8  8b08                              mov    ecx,DWORD PTR [eax]
0x7348ea  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x7348ed  50                                push   eax
0x7348ee  ffd2                              call   edx
0x7348f0  53                                push   ebx
0x7348f1  686054c400                        push   0xc45460
0x7348f6  e81592fbff                        call   0x6edb10
0x7348fb  83c408                            add    esp,0x8
0x7348fe  e989000000                        jmp    0x73498c
0x734903  8b4644                            mov    eax,DWORD PTR [esi+0x44]
0x734906  8b08                              mov    ecx,DWORD PTR [eax]
0x734908  8d542418                          lea    edx,[esp+0x18]
0x73490c  52                                push   edx
0x73490d  6a00                              push   0x0
0x73490f  50                                push   eax
0x734910  8b4148                            mov    eax,DWORD PTR [ecx+0x48]
0x734913  ffd0                              call   eax
0x734915  85c0                              test   eax,eax
0x734917  7413                              je     0x73492c
0x734919  8b442414                          mov    eax,DWORD PTR [esp+0x14]
0x73491d  8b08                              mov    ecx,DWORD PTR [eax]
0x73491f  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x734922  50                                push   eax
0x734923  ffd2                              call   edx
0x734925  688454c400                        push   0xc45484
0x73492a  eb58                              jmp    0x734984
0x73492c  8b4c2414                          mov    ecx,DWORD PTR [esp+0x14]
0x734930  6a00                              push   0x0
0x734932  6aff                              push   0xffffffff
0x734934  8d442428                          lea    eax,[esp+0x28]
0x734938  50                                push   eax
0x734939  8b442424                          mov    eax,DWORD PTR [esp+0x24]
0x73493d  6a00                              push   0x0
0x73493f  51                                push   ecx
0x734940  8d542444                          lea    edx,[esp+0x44]
0x734944  52                                push   edx
0x734945  6a00                              push   0x0
0x734947  50                                push   eax
0x734948  ff151426bd00                      call   DWORD PTR ds:0xbd2614
0x73494e  85c0                              test   eax,eax
0x734950  8b442414                          mov    eax,DWORD PTR [esp+0x14]
0x734954  8b08                              mov    ecx,DWORD PTR [eax]
0x734956  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x734959  50                                push   eax
0x73495a  7415                              je     0x734971
0x73495c  ffd2                              call   edx
0x73495e  8b442418                          mov    eax,DWORD PTR [esp+0x18]
0x734962  8b08                              mov    ecx,DWORD PTR [eax]
0x734964  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x734967  50                                push   eax
0x734968  ffd2                              call   edx
0x73496a  68a054c400                        push   0xc454a0
0x73496f  eb13                              jmp    0x734984
0x734971  ffd2                              call   edx
0x734973  8b442418                          mov    eax,DWORD PTR [esp+0x18]
0x734977  8b08                              mov    ecx,DWORD PTR [eax]
0x734979  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x73497c  50                                push   eax
0x73497d  ffd2                              call   edx
0x73497f  68b854c400                        push   0xc454b8
0x734984  e88791fbff                        call   0x6edb10
0x734989  83c404                            add    esp,0x4
0x73498c  8bc6                              mov    eax,esi
0x73498e  8b4c2448                          mov    ecx,DWORD PTR [esp+0x48]
0x734992  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x734999  59                                pop    ecx
0x73499a  5f                                pop    edi
0x73499b  5e                                pop    esi
0x73499c  5b                                pop    ebx
0x73499d  8b4c2430                          mov    ecx,DWORD PTR [esp+0x30]
0x7349a1  33cc                              xor    ecx,esp
0x7349a3  e859c61500                        call   0x891001
0x7349a8  8be5                              mov    esp,ebp
0x7349aa  5d                                pop    ebp
0x7349ab  c3                                ret

; F11 Graphics create path makes 32x32 texture and fills FF000000
; VA 0x560ec5..0x560fcd raw 0x1602c5 length 264 SHA256 ee76ddccd25bef7d992cb5084c4d0ea4fc9e25cb2e4e2a78db4103ae2ee99ccf
0x560ec5  3bc3                              cmp    eax,ebx
0x560ec7  7434                              je     0x560efd
0x560ec9  8bf0                              mov    esi,eax
0x560ecb  e840311d00                        call   0x734010
0x560ed0  8bf0                              mov    esi,eax
0x560ed2  eb2b                              jmp    0x560eff
0x560ed4  8d442438                          lea    eax,[esp+0x38]
0x560ed8  50                                push   eax
0x560ed9  8d4c2440                          lea    ecx,[esp+0x40]
0x560edd  895c243c                          mov    DWORD PTR [esp+0x3c],ebx
0x560ee1  e8c3013300                        call   0x8910a9
0x560ee6  68a857c800                        push   0xc857a8
0x560eeb  8d4c2440                          lea    ecx,[esp+0x40]
0x560eef  51                                push   ecx
0x560ef0  c7442444a42cbd00                  mov    DWORD PTR [esp+0x44],0xbd2ca4
0x560ef8  e8f3ba3300                        call   0x89c9f0
0x560efd  33f6                              xor    esi,esi
0x560eff  c7442460ffffffff                  mov    DWORD PTR [esp+0x60],0xffffffff
0x560f07  f60540defc0001                    test   BYTE PTR ds:0xfcde40,0x1
0x560f0e  89354427fe00                      mov    DWORD PTR ds:0xfe2744,esi
0x560f14  b820000000                        mov    eax,0x20
0x560f19  89460c                            mov    DWORD PTR [esi+0xc],eax
0x560f1c  894610                            mov    DWORD PTR [esi+0x10],eax
0x560f1f  c7461c15000000                    mov    DWORD PTR [esi+0x1c],0x15
0x560f26  7573                              jne    0x560f9b
0x560f28  830d40defc0001                    or     DWORD PTR ds:0xfcde40,0x1
0x560f2f  c744246005000000                  mov    DWORD PTR [esp+0x60],0x5
0x560f37  6a30                              push   0x30
0x560f39  891d28defc00                      mov    DWORD PTR ds:0xfcde28,ebx
0x560f3f  891d2cdefc00                      mov    DWORD PTR ds:0xfcde2c,ebx
0x560f45  891d38defc00                      mov    DWORD PTR ds:0xfcde38,ebx
0x560f4b  e818033300                        call   0x891268
0x560f50  83c404                            add    esp,0x4
0x560f53  3bc3                              cmp    eax,ebx
0x560f55  0f8489000000                      je     0x560fe4
0x560f5b  a334defc00                        mov    ds:0xfcde34,eax
0x560f60  8900                              mov    DWORD PTR [eax],eax
0x560f62  a134defc00                        mov    eax,ds:0xfcde34
0x560f67  894004                            mov    DWORD PTR [eax+0x4],eax
0x560f6a  a134defc00                        mov    eax,ds:0xfcde34
0x560f6f  894008                            mov    DWORD PTR [eax+0x8],eax
0x560f72  8b0d34defc00                      mov    ecx,DWORD PTR ds:0xfcde34
0x560f78  c6412c01                          mov    BYTE PTR [ecx+0x2c],0x1
0x560f7c  8b1534defc00                      mov    edx,DWORD PTR ds:0xfcde34
0x560f82  68f0e6bc00                        push   0xbce6f0
0x560f87  c6422d01                          mov    BYTE PTR [edx+0x2d],0x1
0x560f8b  e88a133300                        call   0x89231a
0x560f90  83c404                            add    esp,0x4
0x560f93  c7442460ffffffff                  mov    DWORD PTR [esp+0x60],0xffffffff
0x560f9b  8b152cdefc00                      mov    edx,DWORD PTR ds:0xfcde2c
0x560fa1  83c644                            add    esi,0x44
0x560fa4  56                                push   esi
0x560fa5  6a01                              push   0x1
0x560fa7  6a15                              push   0x15
0x560fa9  53                                push   ebx
0x560faa  6a01                              push   0x1
0x560fac  6a20                              push   0x20
0x560fae  6a20                              push   0x20
0x560fb0  52                                push   edx
0x560fb1  ffd7                              call   edi
0x560fb3  53                                push   ebx
0x560fb4  50                                push   eax
0x560fb5  e8d62f1d00                        call   0x733f90
0x560fba  a14427fe00                        mov    eax,ds:0xfe2744
0x560fbf  83c408                            add    esp,0x8
0x560fc2  68000000ff                        push   0xff000000
0x560fc7  50                                push   eax
0x560fc8  e8a3341d00                        call   0x734470

; F11_import_load EDI loads D3DXCreateTexture import for texture creation
; VA 0x560e48..0x560e4e raw 0x160248 length 6 SHA256 fe27b33395fe12e5658ace5b7828d2586b000bd776ad9fd3b4b3c45ebb515eab
0x560e48  8b3d1826bd00                      mov    edi,DWORD PTR ds:0xbd2618

; F11_import_iat PE import name RVA for D3DXCreateTexture
; VA 0xbd2618..0xbd261c raw 0x7d0c18 length 4 SHA256 822669bf0354255e0565b0876d0f8e5ea663939452189a629b11fc51087c189a
; bytes 5aed9500

; F11_import_name Import hint and D3DXCreateTexture name
; VA 0xd5ed5a..0xd5ed6e raw 0x95d35a length 20 SHA256 e8ac897f474ad3f938b435a85eb1f8ea0ecee12dd3889c77df83b65d5ae22f91
; bytes 5d00443344584372656174655465787475726500

; F12 Graphics teardown releases Fade texture
; VA 0x56103c..0x561083 raw 0x16043c length 71 SHA256 7ceab6fbbed5c049e0d8a161c46b478ac1d91ae50c26c34e15c5f7d740797d76
0x56103c  33db                              xor    ebx,ebx
0x56103e  f6054027fe0001                    test   BYTE PTR ds:0xfe2740,0x1
0x561045  7525                              jne    0x56106c
0x561047  830d4027fe0001                    or     DWORD PTR ds:0xfe2740,0x1
0x56104e  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x561052  e829d6ffff                        call   0x55e680
0x561057  68a0f2bc00                        push   0xbcf2a0
0x56105c  e8b9123300                        call   0x89231a
0x561061  83c404                            add    esp,0x4
0x561064  c7442420ffffffff                  mov    DWORD PTR [esp+0x20],0xffffffff
0x56106c  8b0d4427fe00                      mov    ecx,DWORD PTR ds:0xfe2744
0x561072  3bcb                              cmp    ecx,ebx
0x561074  740d                              je     0x561083
0x561076  8b01                              mov    eax,DWORD PTR [ecx]
0x561078  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x56107b  ffd2                              call   edx
0x56107d  891d4427fe00                      mov    DWORD PTR ds:0xfe2744,ebx

; F13 Fade tick precedes Q active/pause checks
; VA 0x561520..0x561594 raw 0x160920 length 116 SHA256 a17699418e0ed7b7698825de06390e40866e658feaeccdbe7b6a729b1f8d5414
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

; F14 Q presentation calls overlay draw
; VA 0x564754..0x564784 raw 0x163b54 length 48 SHA256 97514d070148bb3381adcf871d0dbec26243738f2448205981911e2a1d892ba6
0x564754  091d4027fe00                      or     DWORD PTR ds:0xfe2740,ebx
0x56475a  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x564761  e81a9fffff                        call   0x55e680
0x564766  68a0f2bc00                        push   0xbcf2a0
0x56476b  e8aadb3200                        call   0x89231a
0x564770  83c404                            add    esp,0x4
0x564773  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x56477a  b84427fe00                        mov    eax,0xfe2744
0x56477f  e86ca0ffff                        call   0x55e7f0

; F15 Graphics setup calls texture initialization
; VA 0x48f458..0x48f475 raw 0x8e858 length 29 SHA256 d31d58bf03287bd10d4ca3ce3504a0a25024f7de3d95a6cfd1887f12cd9ed6ab
0x48f458  83cfff                            or     edi,0xffffffff
0x48f45b  897c2438                          mov    DWORD PTR [esp+0x38],edi
0x48f45f  eb03                              jmp    0x48f464
0x48f461  83cfff                            or     edi,0xffffffff
0x48f464  68c073fb00                        push   0xfb73c0
0x48f469  e832160d00                        call   0x560aa0
0x48f46e  f6054492fd0001                    test   BYTE PTR ds:0xfd9244,0x1

; F16 Graphics teardown calls texture release
; VA 0x48fc52..0x48fc74 raw 0x8f052 length 34 SHA256 d56590fbeeff4d4903b21e2c7912f287cf6315c7014facac9c13642eb94de6ce
0x48fc52  6810d1bc00                        push   0xbcd110
0x48fc57  e8be264000                        call   0x89231a
0x48fc5c  83c404                            add    esp,0x4
0x48fc5f  897c2428                          mov    DWORD PTR [esp+0x28],edi
0x48fc63  68c073fb00                        push   0xfb73c0
0x48fc68  e8a3130d00                        call   0x561010
0x48fc6d  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1

; T07 Graphics setup sets Transition.enabled=1
; VA 0x48f7b0..0x48f7df raw 0x8ebb0 length 47 SHA256 ce872394451ec1033025c758902ffc55141918a7f678fbad6979a7afc9b75c54
0x48f7b0  f605f02cfd0001                    test   BYTE PTR ds:0xfd2cf0,0x1
0x48f7b7  be01000000                        mov    esi,0x1
0x48f7bc  7518                              jne    0x48f7d6
0x48f7be  0935f02cfd00                      or     DWORD PTR ds:0xfd2cf0,esi
0x48f7c4  e8c7882a00                        call   0x738090
0x48f7c9  6880e6bc00                        push   0xbce680
0x48f7ce  e8472b4000                        call   0x89231a
0x48f7d3  83c404                            add    esp,0x4
0x48f7d6  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x48f7d9  8935b82bfd00                      mov    DWORD PTR ds:0xfd2bb8,esi

; T08 Graphics teardown frees capture, clears phase/enabled
; VA 0x48fdd0..0x48fe1b raw 0x8f1d0 length 75 SHA256 3ed2af1476583304d558ec3681f5cd35c17b866b31a1849810187ef40d9ed58f
0x48fdd0  f605f02cfd0001                    test   BYTE PTR ds:0xfd2cf0,0x1
0x48fdd7  7518                              jne    0x48fdf1
0x48fdd9  0935f02cfd00                      or     DWORD PTR ds:0xfd2cf0,esi
0x48fddf  e8ac822a00                        call   0x738090
0x48fde4  6880e6bc00                        push   0xbce680
0x48fde9  e82c254000                        call   0x89231a
0x48fdee  83c404                            add    esp,0x4
0x48fdf1  8b0dd02cfd00                      mov    ecx,DWORD PTR ds:0xfd2cd0
0x48fdf7  3bcb                              cmp    ecx,ebx
0x48fdf9  740d                              je     0x48fe08
0x48fdfb  8b11                              mov    edx,DWORD PTR [ecx]
0x48fdfd  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x48fe00  ffd0                              call   eax
0x48fe02  891dd02cfd00                      mov    DWORD PTR ds:0xfd2cd0,ebx
0x48fe08  f6050894fd0001                    test   BYTE PTR ds:0xfd9408,0x1
0x48fe0f  891dcc2bfd00                      mov    DWORD PTR ds:0xfd2bcc,ebx
0x48fe15  891db82bfd00                      mov    DWORD PTR ds:0xfd2bb8,ebx

; T09 Client setup defaults layers8/fade-rate120
; VA 0x48d6dc..0x48d718 raw 0x8cadc length 60 SHA256 861857411192f22dc49d1fba8c0e8e2dbd361c2626629535d81af46528ca923b
0x48d6dc  f605f02cfd0001                    test   BYTE PTR ds:0xfd2cf0,0x1
0x48d6e3  7518                              jne    0x48d6fd
0x48d6e5  093df02cfd00                      or     DWORD PTR ds:0xfd2cf0,edi
0x48d6eb  e8a0a92a00                        call   0x738090
0x48d6f0  6880e6bc00                        push   0xbce680
0x48d6f5  e8204c4000                        call   0x89231a
0x48d6fa  83c404                            add    esp,0x4
0x48d6fd  f605d4f3fd0001                    test   BYTE PTR ds:0xfdf3d4,0x1
0x48d704  c705bc2bfd0008000000              mov    DWORD PTR ds:0xfd2bbc,0x8
0x48d70e  c705c02bfd0078000000              mov    DWORD PTR ds:0xfd2bc0,0x78

; T10 Native visual update passes real delta to transition tick
; VA 0x4923bf..0x4923d0 raw 0x917bf length 17 SHA256 1d642f54204d77faa3b1381f6d7cfa20e979a9147a4f067ebb07eea42e81a9f9
0x4923bf  d9450c                            fld    DWORD PTR [ebp+0xc]
0x4923c2  51                                push   ecx
0x4923c3  beb82bfd00                        mov    esi,0xfd2bb8
0x4923c8  d91c24                            fstp   DWORD PTR [esp]
0x4923cb  e8905d2a00                        call   0x738160

; T11 Main render calls captured transition draw
; VA 0x492fcd..0x492feb raw 0x923cd length 30 SHA256 22e42286373c28c7414324fea9a4711452a9b64b2a2b16c7584192f2e546c73d
0x492fcd  50                                push   eax
0x492fce  e8ed880f00                        call   0x58b8c0
0x492fd3  e86872ffff                        call   0x48a240
0x492fd8  8bc8                              mov    ecx,eax
0x492fda  e8e1422a00                        call   0x7372c0
0x492fdf  e8bc800000                        call   0x49b0a0
0x492fe4  8bf8                              mov    edi,eax
0x492fe6  e805532a00                        call   0x7382f0

; M01 Q PlayMusic path/int/settings gain
; VA 0x5643c0..0x5644f2 raw 0x1637c0 length 306 SHA256 5b7c8323acc8fab4e3738af467c7446a1d1613490a643569c5df5e089201f148
0x5643c0  55                                push   ebp
0x5643c1  8bec                              mov    ebp,esp
0x5643c3  6aff                              push   0xffffffff
0x5643c5  68a8b29100                        push   0x91b2a8
0x5643ca  64a100000000                      mov    eax,fs:0x0
0x5643d0  50                                push   eax
0x5643d1  51                                push   ecx
0x5643d2  53                                push   ebx
0x5643d3  56                                push   esi
0x5643d4  57                                push   edi
0x5643d5  a1201fd600                        mov    eax,ds:0xd61f20
0x5643da  33c5                              xor    eax,ebp
0x5643dc  50                                push   eax
0x5643dd  8d45f4                            lea    eax,[ebp-0xc]
0x5643e0  64a300000000                      mov    fs:0x0,eax
0x5643e6  bb01000000                        mov    ebx,0x1
0x5643eb  83ceff                            or     esi,0xffffffff
0x5643ee  841d2888fb00                      test   BYTE PTR ds:0xfb8828,bl
0x5643f4  7522                              jne    0x564418
0x5643f6  091d2888fb00                      or     DWORD PTR ds:0xfb8828,ebx
0x5643fc  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x564403  e848b4feff                        call   0x54f850
0x564408  6880d5bc00                        push   0xbcd580
0x56440d  e808df3200                        call   0x89231a
0x564412  83c404                            add    esp,0x4
0x564415  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x564418  668b3dea90fb00                    mov    di,WORD PTR ds:0xfb90ea
0x56441f  841d2888fb00                      test   BYTE PTR ds:0xfb8828,bl
0x564425  751e                              jne    0x564445
0x564427  091d2888fb00                      or     DWORD PTR ds:0xfb8828,ebx
0x56442d  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x564430  e81bb4feff                        call   0x54f850
0x564435  6880d5bc00                        push   0xbcd580
0x56443a  e8dbde3200                        call   0x89231a
0x56443f  83c404                            add    esp,0x4
0x564442  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x564445  f30f10055c93fb00                  movss  xmm0,DWORD PTR ds:0xfb935c
0x56444d  f30f1145f0                        movss  DWORD PTR [ebp-0x10],xmm0
0x564452  841dc00ffc00                      test   BYTE PTR ds:0xfc0fc0,bl
0x564458  754c                              jne    0x5644a6
0x56445a  091dc00ffc00                      or     DWORD PTR ds:0xfc0fc0,ebx
0x564460  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x564467  e8e4491700                        call   0x6d8e50
0x56446c  68b0dbbc00                        push   0xbcdbb0
0x564471  e8a4de3200                        call   0x89231a
0x564476  83c404                            add    esp,0x4
0x564479  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x56447c  841dc00ffc00                      test   BYTE PTR ds:0xfc0fc0,bl
0x564482  7522                              jne    0x5644a6
0x564484  091dc00ffc00                      or     DWORD PTR ds:0xfc0fc0,ebx
0x56448a  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
0x564491  e8ba491700                        call   0x6d8e50
0x564496  68b0dbbc00                        push   0xbcdbb0
0x56449b  e87ade3200                        call   0x89231a
0x5644a0  83c404                            add    esp,0x4
0x5644a3  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5644a6  d945f0                            fld    DWORD PTR [ebp-0x10]
0x5644a9  0fbfc7                            movsx  eax,di
0x5644ac  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5644af  db45f0                            fild   DWORD PTR [ebp-0x10]
0x5644b2  dec9                              fmulp  st(1),st
0x5644b4  e857a83900                        call   0x8fed10
0x5644b9  e8b2651700                        call   0x6daa70
0x5644be  e84da83900                        call   0x8fed10
0x5644c3  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x5644c6  0fb7c8                            movzx  ecx,ax
0x5644c9  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x5644cc  51                                push   ecx
0x5644cd  52                                push   edx
0x5644ce  50                                push   eax
0x5644cf  68c80ffc00                        push   0xfc0fc8
0x5644d4  b9fc0ffc00                        mov    ecx,0xfc0ffc
0x5644d9  e852561700                        call   0x6d9b30
0x5644de  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5644e1  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5644e8  59                                pop    ecx
0x5644e9  5f                                pop    edi
0x5644ea  5e                                pop    esi
0x5644eb  5b                                pop    ebx
0x5644ec  8be5                              mov    esp,ebp
0x5644ee  5d                                pop    ebp
0x5644ef  c20800                            ret    0x8

; M02 Q StopMusic shared player
; VA 0x564500..0x564571 raw 0x163900 length 113 SHA256 ae87d8f2cc666c6f2648fe928d76893b6d1154fae121b5cd1b629a84aa5197f4
0x564500  55                                push   ebp
0x564501  8bec                              mov    ebp,esp
0x564503  6aff                              push   0xffffffff
0x564505  684eb29100                        push   0x91b24e
0x56450a  64a100000000                      mov    eax,fs:0x0
0x564510  50                                push   eax
0x564511  51                                push   ecx
0x564512  56                                push   esi
0x564513  a1201fd600                        mov    eax,ds:0xd61f20
0x564518  33c5                              xor    eax,ebp
0x56451a  50                                push   eax
0x56451b  8d45f4                            lea    eax,[ebp-0xc]
0x56451e  64a300000000                      mov    fs:0x0,eax
0x564524  b801000000                        mov    eax,0x1
0x564529  8405c00ffc00                      test   BYTE PTR ds:0xfc0fc0,al
0x56452f  7526                              jne    0x564557
0x564531  0905c00ffc00                      or     DWORD PTR ds:0xfc0fc0,eax
0x564537  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x56453e  e80d491700                        call   0x6d8e50
0x564543  68b0dbbc00                        push   0xbcdbb0
0x564548  e8cddd3200                        call   0x89231a
0x56454d  83c404                            add    esp,0x4
0x564550  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x564557  bec80ffc00                        mov    esi,0xfc0fc8
0x56455c  e85f571700                        call   0x6d9cc0
0x564561  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x564564  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x56456b  59                                pop    ecx
0x56456c  5e                                pop    esi
0x56456d  8be5                              mov    esp,ebp
0x56456f  5d                                pop    ebp
0x564570  c3                                ret

; M03 Q fade argument divided by1000
; VA 0x564580..0x564605 raw 0x163980 length 133 SHA256 11abe37f9c0c8229581185acbd916cecb900462122294b890948130e14c12502
0x564580  55                                push   ebp
0x564581  8bec                              mov    ebp,esp
0x564583  6aff                              push   0xffffffff
0x564585  681eb29100                        push   0x91b21e
0x56458a  64a100000000                      mov    eax,fs:0x0
0x564590  50                                push   eax
0x564591  56                                push   esi
0x564592  a1201fd600                        mov    eax,ds:0xd61f20
0x564597  33c5                              xor    eax,ebp
0x564599  50                                push   eax
0x56459a  8d45f4                            lea    eax,[ebp-0xc]
0x56459d  64a300000000                      mov    fs:0x0,eax
0x5645a3  b801000000                        mov    eax,0x1
0x5645a8  8405c00ffc00                      test   BYTE PTR ds:0xfc0fc0,al
0x5645ae  7526                              jne    0x5645d6
0x5645b0  0905c00ffc00                      or     DWORD PTR ds:0xfc0fc0,eax
0x5645b6  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5645bd  e88e481700                        call   0x6d8e50
0x5645c2  68b0dbbc00                        push   0xbcdbb0
0x5645c7  e84edd3200                        call   0x89231a
0x5645cc  83c404                            add    esp,0x4
0x5645cf  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x5645d6  db4508                            fild   DWORD PTR [ebp+0x8]
0x5645d9  51                                push   ecx
0x5645da  bec80ffc00                        mov    esi,0xfc0fc8
0x5645df  dc35d857c500                      fdiv   QWORD PTR ds:0xc557d8
0x5645e5  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x5645e8  d94508                            fld    DWORD PTR [ebp+0x8]
0x5645eb  d91c24                            fstp   DWORD PTR [esp]
0x5645ee  e8ad571700                        call   0x6d9da0
0x5645f3  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5645f6  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5645fd  59                                pop    ecx
0x5645fe  5e                                pop    esi
0x5645ff  8be5                              mov    esp,ebp
0x564601  5d                                pop    ebp
0x564602  c20400                            ret    0x4

; M04 Primary/secondary slot request, same-name early return, delayed start
; VA 0x6d9b30..0x6d9cb3 raw 0x2d8f30 length 387 SHA256 4286d815e3b2d8dc26926d7570409ec9604a956d5db134fa24e23fb369c094a0
0x6d9b30  55                                push   ebp
0x6d9b31  8bec                              mov    ebp,esp
0x6d9b33  6aff                              push   0xffffffff
0x6d9b35  689e9a9100                        push   0x919a9e
0x6d9b3a  64a100000000                      mov    eax,fs:0x0
0x6d9b40  50                                push   eax
0x6d9b41  53                                push   ebx
0x6d9b42  56                                push   esi
0x6d9b43  57                                push   edi
0x6d9b44  a1201fd600                        mov    eax,ds:0xd61f20
0x6d9b49  33c5                              xor    eax,ebp
0x6d9b4b  50                                push   eax
0x6d9b4c  8d45f4                            lea    eax,[ebp-0xc]
0x6d9b4f  64a300000000                      mov    fs:0x0,eax
0x6d9b55  8bf1                              mov    esi,ecx
0x6d9b57  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6d9b5a  837e1810                          cmp    DWORD PTR [esi+0x18],0x10
0x6d9b5e  7205                              jb     0x6d9b65
0x6d9b60  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x6d9b63  eb03                              jmp    0x6d9b68
0x6d9b65  8d4604                            lea    eax,[esi+0x4]
0x6d9b68  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x6d9b6b  51                                push   ecx
0x6d9b6c  50                                push   eax
0x6d9b6d  e83fa11b00                        call   0x893cb1
0x6d9b72  83c408                            add    esp,0x8
0x6d9b75  85c0                              test   eax,eax
0x6d9b77  0f8422010000                      je     0x6d9c9f
0x6d9b7d  833e00                            cmp    DWORD PTR [esi],0x0
0x6d9b80  746c                              je     0x6d9bee
0x6d9b82  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
0x6d9b89  7527                              jne    0x6d9bb2
0x6d9b8b  830d2888fb0001                    or     DWORD PTR ds:0xfb8828,0x1
0x6d9b92  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x6d9b99  e8b25ce7ff                        call   0x54f850
0x6d9b9e  6880d5bc00                        push   0xbcd580
0x6d9ba3  e872871b00                        call   0x89231a
0x6d9ba8  83c404                            add    esp,0x4
0x6d9bab  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x6d9bb2  803d3593fb0000                    cmp    BYTE PTR ds:0xfb9335,0x0
0x6d9bb9  7415                              je     0x6d9bd0
0x6d9bbb  d905f4c7c000                      fld    DWORD PTR ds:0xc0c7f4
0x6d9bc1  51                                push   ecx
0x6d9bc2  8bd6                              mov    edx,esi
0x6d9bc4  d91c24                            fstp   DWORD PTR [esp]
0x6d9bc7  8bcb                              mov    ecx,ebx
0x6d9bc9  e8b2f6ffff                        call   0x6d9280
0x6d9bce  eb09                              jmp    0x6d9bd9
0x6d9bd0  8b0e                              mov    ecx,DWORD PTR [esi]
0x6d9bd2  8b11                              mov    edx,DWORD PTR [ecx]
0x6d9bd4  8b422c                            mov    eax,DWORD PTR [edx+0x2c]
0x6d9bd7  ffd0                              call   eax
0x6d9bd9  6a00                              push   0x0
0x6d9bdb  687523bf00                        push   0xbf2375
0x6d9be0  8d4e04                            lea    ecx,[esi+0x4]
0x6d9be3  e8888ed2ff                        call   0x402a70
0x6d9be8  c70600000000                      mov    DWORD PTR [esi],0x0
0x6d9bee  668b5514                          mov    dx,WORD PTR [ebp+0x14]
0x6d9bf2  8b4d10                            mov    ecx,DWORD PTR [ebp+0x10]
0x6d9bf5  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6d9bf8  66895624                          mov    WORD PTR [esi+0x24],dx
0x6d9bfc  894e20                            mov    DWORD PTR [esi+0x20],ecx
0x6d9bff  8d5001                            lea    edx,[eax+0x1]
0x6d9c02  8a08                              mov    cl,BYTE PTR [eax]
0x6d9c04  40                                inc    eax
0x6d9c05  84c9                              test   cl,cl
0x6d9c07  75f9                              jne    0x6d9c02
0x6d9c09  2bc2                              sub    eax,edx
0x6d9c0b  50                                push   eax
0x6d9c0c  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6d9c0f  50                                push   eax
0x6d9c10  8d4e04                            lea    ecx,[esi+0x4]
0x6d9c13  e8588ed2ff                        call   0x402a70
0x6d9c18  c70600000000                      mov    DWORD PTR [esi],0x0
0x6d9c1e  32c9                              xor    cl,cl
0x6d9c20  837b2c00                          cmp    DWORD PTR [ebx+0x2c],0x0
0x6d9c24  743a                              je     0x6d9c60
0x6d9c26  8b5328                            mov    edx,DWORD PTR [ebx+0x28]
0x6d9c29  8b02                              mov    eax,DWORD PTR [edx]
0x6d9c2b  3bc2                              cmp    eax,edx
0x6d9c2d  7431                              je     0x6d9c60
0x6d9c2f  f30f1005c85bc500                  movss  xmm0,DWORD PTR ds:0xc55bc8
0x6d9c37  eb07                              jmp    0x6d9c40
0x6d9c39  8da42400000000                    lea    esp,[esp+0x0]
0x6d9c40  f30f104834                        movss  xmm1,DWORD PTR [eax+0x34]
0x6d9c45  0f2fc8                            comiss xmm1,xmm0
0x6d9c48  7602                              jbe    0x6d9c4c
0x6d9c4a  b101                              mov    cl,0x1
0x6d9c4c  8b00                              mov    eax,DWORD PTR [eax]
0x6d9c4e  3bc2                              cmp    eax,edx
0x6d9c50  75ee                              jne    0x6d9c40
0x6d9c52  84c9                              test   cl,cl
0x6d9c54  740a                              je     0x6d9c60
0x6d9c56  f30f1005f8c7c000                  movss  xmm0,DWORD PTR ds:0xc0c7f8
0x6d9c5e  eb08                              jmp    0x6d9c68
0x6d9c60  f30f1005c058c500                  movss  xmm0,DWORD PTR ds:0xc558c0
0x6d9c68  f30f114634                        movss  DWORD PTR [esi+0x34],xmm0
0x6d9c6d  8db3b4000000                      lea    esi,[ebx+0xb4]
0x6d9c73  56                                push   esi
0x6d9c74  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x6d9c7a  bf01000000                        mov    edi,0x1
0x6d9c7f  56                                push   esi
0x6d9c80  89bba8000000                      mov    DWORD PTR [ebx+0xa8],edi
0x6d9c86  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x6d9c8c  8b83ac000000                      mov    eax,DWORD PTR [ebx+0xac]
0x6d9c92  8b480c                            mov    ecx,DWORD PTR [eax+0xc]
0x6d9c95  51                                push   ecx
0x6d9c96  897810                            mov    DWORD PTR [eax+0x10],edi
0x6d9c99  ff15d020bd00                      call   DWORD PTR ds:0xbd20d0
0x6d9c9f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x6d9ca2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x6d9ca9  59                                pop    ecx
0x6d9caa  5f                                pop    edi
0x6d9cab  5e                                pop    esi
0x6d9cac  5b                                pop    ebx
0x6d9cad  8be5                              mov    esp,ebp
0x6d9caf  5d                                pop    ebp
0x6d9cb0  c21000                            ret    0x10

; M05 AlarmedThread registration and event/thread creation
; VA 0x6d8d20..0x6d8d94 raw 0x2d8120 length 116 SHA256 789eaf8d929cea6f12a2ba3a052e90e46002af14906741964cbfc92289a2e972
0x6d8d20  57                                push   edi
0x6d8d21  33ff                              xor    edi,edi
0x6d8d23  57                                push   edi
0x6d8d24  57                                push   edi
0x6d8d25  57                                push   edi
0x6d8d26  57                                push   edi
0x6d8d27  c706d40fc400                      mov    DWORD PTR [esi],0xc40fd4
0x6d8d2d  897e04                            mov    DWORD PTR [esi+0x4],edi
0x6d8d30  897e08                            mov    DWORD PTR [esi+0x8],edi
0x6d8d33  c7460cffffffff                    mov    DWORD PTR [esi+0xc],0xffffffff
0x6d8d3a  897e10                            mov    DWORD PTR [esi+0x10],edi
0x6d8d3d  894614                            mov    DWORD PTR [esi+0x14],eax
0x6d8d40  ff15cc20bd00                      call   DWORD PTR ds:0xbd20cc
0x6d8d46  6a0c                              push   0xc
0x6d8d48  89460c                            mov    DWORD PTR [esi+0xc],eax
0x6d8d4b  c7460801000000                    mov    DWORD PTR [esi+0x8],0x1
0x6d8d52  e811851b00                        call   0x891268
0x6d8d57  83c404                            add    esp,0x4
0x6d8d5a  3bc7                              cmp    eax,edi
0x6d8d5c  7412                              je     0x6d8d70
0x6d8d5e  c700dc0fc400                      mov    DWORD PTR [eax],0xc40fdc
0x6d8d64  897004                            mov    DWORD PTR [eax+0x4],esi
0x6d8d67  c74008a08d6d00                    mov    DWORD PTR [eax+0x8],0x6d8da0
0x6d8d6e  eb02                              jmp    0x6d8d72
0x6d8d70  33c0                              xor    eax,eax
0x6d8d72  8bf8                              mov    edi,eax
0x6d8d74  e8f729e2ff                        call   0x4fb770
0x6d8d79  894604                            mov    DWORD PTR [esi+0x4],eax
0x6d8d7c  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x6d8d7f  51                                push   ecx
0x6d8d80  83c9ff                            or     ecx,0xffffffff
0x6d8d83  bac00fc400                        mov    edx,0xc40fc0
0x6d8d88  e8b3feffff                        call   0x6d8c40
0x6d8d8d  83c404                            add    esp,0x4
0x6d8d90  8bc6                              mov    eax,esi
0x6d8d92  5f                                pop    edi
0x6d8d93  c3                                ret

; M06 Event wake -> stored functor virtual+8 loop
; VA 0x6d8da0..0x6d8de6 raw 0x2d81a0 length 70 SHA256 77db1d299b377415cddd1cf33eb3c7ecab98a7788c7dd1b2b9504ed529750838
0x6d8da0  56                                push   esi
0x6d8da1  8bf1                              mov    esi,ecx
0x6d8da3  837e0800                          cmp    DWORD PTR [esi+0x8],0x0
0x6d8da7  743b                              je     0x6d8de4
0x6d8da9  57                                push   edi
0x6d8daa  8b3dfc20bd00                      mov    edi,DWORD PTR ds:0xbd20fc
0x6d8db0  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x6d8db3  68e8030000                        push   0x3e8
0x6d8db8  50                                push   eax
0x6d8db9  ffd7                              call   edi
0x6d8dbb  85c0                              test   eax,eax
0x6d8dbd  751e                              jne    0x6d8ddd
0x6d8dbf  394608                            cmp    DWORD PTR [esi+0x8],eax
0x6d8dc2  741f                              je     0x6d8de3
0x6d8dc4  837e1000                          cmp    DWORD PTR [esi+0x10],0x0
0x6d8dc8  7413                              je     0x6d8ddd
0x6d8dca  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x6d8dcd  8b11                              mov    edx,DWORD PTR [ecx]
0x6d8dcf  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x6d8dd2  ffd0                              call   eax
0x6d8dd4  837e0800                          cmp    DWORD PTR [esi+0x8],0x0
0x6d8dd8  75ea                              jne    0x6d8dc4
0x6d8dda  5f                                pop    edi
0x6d8ddb  5e                                pop    esi
0x6d8ddc  c3                                ret
0x6d8ddd  837e0800                          cmp    DWORD PTR [esi+0x8],0x0
0x6d8de1  75cd                              jne    0x6d8db0
0x6d8de3  5f                                pop    edi
0x6d8de4  5e                                pop    esi
0x6d8de5  c3                                ret

; M07 Native member-function functor receiver+callback
; VA 0x4facd0..0x4facda raw 0xfa0d0 length 10 SHA256 3e450d1bc183b3f5cca4ce5e2649698aeb93207a26d57ba939e786da9c9311a5
0x4facd0  8bc1                              mov    eax,ecx
0x4facd2  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x4facd5  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x4facd8  ffe0                              jmp    eax

; M08 Music worker pending start, volume fade and Sleep(33)
; VA 0x6d9870..0x6d9970 raw 0x2d8c70 length 256 SHA256 8f707ec35c736960bdfe2e9d443fbd31726b417b88442926f10eb6a05e1fdcb4
0x6d9870  55                                push   ebp
0x6d9871  8bec                              mov    ebp,esp
0x6d9873  6aff                              push   0xffffffff
0x6d9875  68685f9100                        push   0x915f68
0x6d987a  64a100000000                      mov    eax,fs:0x0
0x6d9880  50                                push   eax
0x6d9881  51                                push   ecx
0x6d9882  53                                push   ebx
0x6d9883  56                                push   esi
0x6d9884  57                                push   edi
0x6d9885  a1201fd600                        mov    eax,ds:0xd61f20
0x6d988a  33c5                              xor    eax,ebp
0x6d988c  50                                push   eax
0x6d988d  8d45f4                            lea    eax,[ebp-0xc]
0x6d9890  64a300000000                      mov    fs:0x0,eax
0x6d9896  8bf9                              mov    edi,ecx
0x6d9898  8d87b4000000                      lea    eax,[edi+0xb4]
0x6d989e  50                                push   eax
0x6d989f  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x6d98a2  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x6d98a8  33c0                              xor    eax,eax
0x6d98aa  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x6d98ad  3987a8000000                      cmp    DWORD PTR [edi+0xa8],eax
0x6d98b3  750e                              jne    0x6d98c3
0x6d98b5  39472c                            cmp    DWORD PTR [edi+0x2c],eax
0x6d98b8  7509                              jne    0x6d98c3
0x6d98ba  8b8fac000000                      mov    ecx,DWORD PTR [edi+0xac]
0x6d98c0  894110                            mov    DWORD PTR [ecx+0x10],eax
0x6d98c3  8987a8000000                      mov    DWORD PTR [edi+0xa8],eax
0x6d98c9  8d7734                            lea    esi,[edi+0x34]
0x6d98cc  8bc6                              mov    eax,esi
0x6d98ce  e89d000000                        call   0x6d9970
0x6d98d3  8d476c                            lea    eax,[edi+0x6c]
0x6d98d6  e895000000                        call   0x6d9970
0x6d98db  e830010000                        call   0x6d9a10
0x6d98e0  8d776c                            lea    esi,[edi+0x6c]
0x6d98e3  e828010000                        call   0x6d9a10
0x6d98e8  8b4728                            mov    eax,DWORD PTR [edi+0x28]
0x6d98eb  8b18                              mov    ebx,DWORD PTR [eax]
0x6d98ed  3bd8                              cmp    ebx,eax
0x6d98ef  745b                              je     0x6d994c
0x6d98f1  8d7308                            lea    esi,[ebx+0x8]
0x6d98f4  e817010000                        call   0x6d9a10
0x6d98f9  85c0                              test   eax,eax
0x6d98fb  7448                              je     0x6d9945
0x6d98fd  8b33                              mov    esi,DWORD PTR [ebx]
0x6d98ff  3b5f28                            cmp    ebx,DWORD PTR [edi+0x28]
0x6d9902  743d                              je     0x6d9941
0x6d9904  8b5304                            mov    edx,DWORD PTR [ebx+0x4]
0x6d9907  8932                              mov    DWORD PTR [edx],esi
0x6d9909  8b03                              mov    eax,DWORD PTR [ebx]
0x6d990b  8b4b04                            mov    ecx,DWORD PTR [ebx+0x4]
0x6d990e  894804                            mov    DWORD PTR [eax+0x4],ecx
0x6d9911  837b2010                          cmp    DWORD PTR [ebx+0x20],0x10
0x6d9915  720c                              jb     0x6d9923
0x6d9917  8b530c                            mov    edx,DWORD PTR [ebx+0xc]
0x6d991a  52                                push   edx
0x6d991b  e8ec781b00                        call   0x89120c
0x6d9920  83c404                            add    esp,0x4
0x6d9923  c743200f000000                    mov    DWORD PTR [ebx+0x20],0xf
0x6d992a  c7431c00000000                    mov    DWORD PTR [ebx+0x1c],0x0
0x6d9931  53                                push   ebx
0x6d9932  c6430c00                          mov    BYTE PTR [ebx+0xc],0x0
0x6d9936  e8d1781b00                        call   0x89120c
0x6d993b  83c404                            add    esp,0x4
0x6d993e  ff4f2c                            dec    DWORD PTR [edi+0x2c]
0x6d9941  8bde                              mov    ebx,esi
0x6d9943  eb02                              jmp    0x6d9947
0x6d9945  8b1b                              mov    ebx,DWORD PTR [ebx]
0x6d9947  3b5f28                            cmp    ebx,DWORD PTR [edi+0x28]
0x6d994a  75a5                              jne    0x6d98f1
0x6d994c  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0x6d994f  50                                push   eax
0x6d9950  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x6d9956  6a21                              push   0x21
0x6d9958  ff150423bd00                      call   DWORD PTR ds:0xbd2304
0x6d995e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x6d9961  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x6d9968  59                                pop    ecx
0x6d9969  5f                                pop    edi
0x6d996a  5e                                pop    esi
0x6d996b  5b                                pop    ebx
0x6d996c  8be5                              mov    esp,ebp
0x6d996e  5d                                pop    ebp
0x6d996f  c3                                ret

; M09 Delayed start decrement1/R then concrete start
; VA 0x6d9970..0x6d9a08 raw 0x2d8d70 length 152 SHA256 f9996a5de9a66da2c66bb30504159539756eecf53c2992b8ba4768dcc1eefbc1
0x6d9970  55                                push   ebp
0x6d9971  8bec                              mov    ebp,esp
0x6d9973  51                                push   ecx
0x6d9974  56                                push   esi
0x6d9975  8bf0                              mov    esi,eax
0x6d9977  f30f104634                        movss  xmm0,DWORD PTR [esi+0x34]
0x6d997c  0f2f056c56c500                    comiss xmm0,DWORD PTR ds:0xc5566c
0x6d9983  767e                              jbe    0x6d9a03
0x6d9985  a1cca7fb00                        mov    eax,ds:0xfba7cc
0x6d998a  85c0                              test   eax,eax
0x6d998c  751f                              jne    0x6d99ad
0x6d998e  6880130000                        push   0x1380
0x6d9993  e8d0781b00                        call   0x891268
0x6d9998  83c404                            add    esp,0x4
0x6d999b  85c0                              test   eax,eax
0x6d999d  7407                              je     0x6d99a6
0x6d999f  e82c5a0000                        call   0x6df3d0
0x6d99a4  eb02                              jmp    0x6d99a8
0x6d99a6  33c0                              xor    eax,eax
0x6d99a8  a3cca7fb00                        mov    ds:0xfba7cc,eax
0x6d99ad  d94634                            fld    DWORD PTR [esi+0x34]
0x6d99b0  db8060130000                      fild   DWORD PTR [eax+0x1360]
0x6d99b6  d9e8                              fld1
0x6d99b8  def1                              fdivrp st(1),st
0x6d99ba  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x6d99bd  d865fc                            fsub   DWORD PTR [ebp-0x4]
0x6d99c0  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x6d99c3  d945fc                            fld    DWORD PTR [ebp-0x4]
0x6d99c6  d95634                            fst    DWORD PTR [esi+0x34]
0x6d99c9  d9ee                              fldz
0x6d99cb  dff1                              fcomip st,st(1)
0x6d99cd  ddd8                              fstp   st(0)
0x6d99cf  7214                              jb     0x6d99e5
0x6d99d1  0f57c0                            xorps  xmm0,xmm0
0x6d99d4  56                                push   esi
0x6d99d5  57                                push   edi
0x6d99d6  f30f114634                        movss  DWORD PTR [esi+0x34],xmm0
0x6d99db  e830040000                        call   0x6d9e10
0x6d99e0  5e                                pop    esi
0x6d99e1  8be5                              mov    esp,ebp
0x6d99e3  5d                                pop    ebp
0x6d99e4  c3                                ret
0x6d99e5  8db7b4000000                      lea    esi,[edi+0xb4]
0x6d99eb  56                                push   esi
0x6d99ec  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x6d99f2  56                                push   esi
0x6d99f3  c787a800000001000000              mov    DWORD PTR [edi+0xa8],0x1
0x6d99fd  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x6d9a03  5e                                pop    esi
0x6d9a04  8be5                              mov    esp,ebp
0x6d9a06  5d                                pop    ebp
0x6d9a07  c3                                ret

; M11 Choose nonbusy stream driver; load/play then set gain
; VA 0x6d9e10..0x6d9efa raw 0x2d9210 length 234 SHA256 4e80a27c17e3c5a5f285a9ca2104ca94b534300dc3802ea43eaa894995841037
0x6d9e10  55                                push   ebp
0x6d9e11  8bec                              mov    ebp,esp
0x6d9e13  f6059816fc0001                    test   BYTE PTR ds:0xfc1698,0x1
0x6d9e1a  53                                push   ebx
0x6d9e1b  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x6d9e1e  56                                push   esi
0x6d9e1f  7519                              jne    0x6d9e3a
0x6d9e21  830d9816fc0001                    or     DWORD PTR ds:0xfc1698,0x1
0x6d9e28  e8732a1300                        call   0x80c8a0
0x6d9e2d  6820e3bc00                        push   0xbce320
0x6d9e32  e8e3841b00                        call   0x89231a
0x6d9e37  83c404                            add    esp,0x4
0x6d9e3a  33f6                              xor    esi,esi
0x6d9e3c  8d642400                          lea    esp,[esp+0x0]
0x6d9e40  8b0cb5a016fc00                    mov    ecx,DWORD PTR [esi*4+0xfc16a0]
0x6d9e47  85c9                              test   ecx,ecx
0x6d9e49  740b                              je     0x6d9e56
0x6d9e4b  8b01                              mov    eax,DWORD PTR [ecx]
0x6d9e4d  8b5030                            mov    edx,DWORD PTR [eax+0x30]
0x6d9e50  ffd2                              call   edx
0x6d9e52  85c0                              test   eax,eax
0x6d9e54  740c                              je     0x6d9e62
0x6d9e56  46                                inc    esi
0x6d9e57  83fe10                            cmp    esi,0x10
0x6d9e5a  7ce4                              jl     0x6d9e40
0x6d9e5c  5e                                pop    esi
0x6d9e5d  5b                                pop    ebx
0x6d9e5e  5d                                pop    ebp
0x6d9e5f  c20800                            ret    0x8
0x6d9e62  8b34b5a016fc00                    mov    esi,DWORD PTR [esi*4+0xfc16a0]
0x6d9e69  85f6                              test   esi,esi
0x6d9e6b  0f8483000000                      je     0x6d9ef4
0x6d9e71  837b1810                          cmp    DWORD PTR [ebx+0x18],0x10
0x6d9e75  57                                push   edi
0x6d9e76  7205                              jb     0x6d9e7d
0x6d9e78  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0x6d9e7b  eb03                              jmp    0x6d9e80
0x6d9e7d  8d4304                            lea    eax,[ebx+0x4]
0x6d9e80  8b4b20                            mov    ecx,DWORD PTR [ebx+0x20]
0x6d9e83  8b16                              mov    edx,DWORD PTR [esi]
0x6d9e85  8b5214                            mov    edx,DWORD PTR [edx+0x14]
0x6d9e88  51                                push   ecx
0x6d9e89  50                                push   eax
0x6d9e8a  8bce                              mov    ecx,esi
0x6d9e8c  ffd2                              call   edx
0x6d9e8e  85c0                              test   eax,eax
0x6d9e90  784c                              js     0x6d9ede
0x6d9e92  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6d9e95  80782500                          cmp    BYTE PTR [eax+0x25],0x0
0x6d9e99  7412                              je     0x6d9ead
0x6d9e9b  0fbf4b24                          movsx  ecx,WORD PTR [ebx+0x24]
0x6d9e9f  894d0c                            mov    DWORD PTR [ebp+0xc],ecx
0x6d9ea2  db450c                            fild   DWORD PTR [ebp+0xc]
0x6d9ea5  dc0d7056c500                      fmul   QWORD PTR ds:0xc55670
0x6d9eab  eb0a                              jmp    0x6d9eb7
0x6d9ead  0fbf5324                          movsx  edx,WORD PTR [ebx+0x24]
0x6d9eb1  89550c                            mov    DWORD PTR [ebp+0xc],edx
0x6d9eb4  db450c                            fild   DWORD PTR [ebp+0xc]
0x6d9eb7  8b3e                              mov    edi,DWORD PTR [esi]
0x6d9eb9  e8524e2200                        call   0x8fed10
0x6d9ebe  50                                push   eax
0x6d9ebf  8b4748                            mov    eax,DWORD PTR [edi+0x48]
0x6d9ec2  8bce                              mov    ecx,esi
0x6d9ec4  ffd0                              call   eax
0x6d9ec6  d9e8                              fld1
0x6d9ec8  8b16                              mov    edx,DWORD PTR [esi]
0x6d9eca  8b424c                            mov    eax,DWORD PTR [edx+0x4c]
0x6d9ecd  51                                push   ecx
0x6d9ece  8bce                              mov    ecx,esi
0x6d9ed0  d91c24                            fstp   DWORD PTR [esp]
0x6d9ed3  ffd0                              call   eax
0x6d9ed5  5f                                pop    edi
0x6d9ed6  8933                              mov    DWORD PTR [ebx],esi
0x6d9ed8  5e                                pop    esi
0x6d9ed9  5b                                pop    ebx
0x6d9eda  5d                                pop    ebp
0x6d9edb  c20800                            ret    0x8
0x6d9ede  6a00                              push   0x0
0x6d9ee0  687523bf00                        push   0xbf2375
0x6d9ee5  8d4b04                            lea    ecx,[ebx+0x4]
0x6d9ee8  e8838bd2ff                        call   0x402a70
0x6d9eed  c70300000000                      mov    DWORD PTR [ebx],0x0
0x6d9ef3  5f                                pop    edi
0x6d9ef4  5e                                pop    esi
0x6d9ef5  5b                                pop    ebx
0x6d9ef6  5d                                pop    ebp
0x6d9ef7  c20800                            ret    0x8

; M12 Move active stream reference into fade list
; VA 0x6d9280..0x6d9422 raw 0x2d8680 length 418 SHA256 9c2e510a34cfd4fec84c5af3dc52194c00af1aa5618933f345fd88f70c436d7f
0x6d9280  55                                push   ebp
0x6d9281  8bec                              mov    ebp,esp
0x6d9283  83e4f8                            and    esp,0xfffffff8
0x6d9286  6aff                              push   0xffffffff
0x6d9288  68a85f9100                        push   0x915fa8
0x6d928d  64a100000000                      mov    eax,fs:0x0
0x6d9293  50                                push   eax
0x6d9294  83ec68                            sub    esp,0x68
0x6d9297  a1201fd600                        mov    eax,ds:0xd61f20
0x6d929c  33c4                              xor    eax,esp
0x6d929e  89442460                          mov    DWORD PTR [esp+0x60],eax
0x6d92a2  53                                push   ebx
0x6d92a3  56                                push   esi
0x6d92a4  57                                push   edi
0x6d92a5  a1201fd600                        mov    eax,ds:0xd61f20
0x6d92aa  33c4                              xor    eax,esp
0x6d92ac  50                                push   eax
0x6d92ad  8d442478                          lea    eax,[esp+0x78]
0x6d92b1  64a300000000                      mov    fs:0x0,eax
0x6d92b7  8bf1                              mov    esi,ecx
0x6d92b9  8d86b4000000                      lea    eax,[esi+0xb4]
0x6d92bf  8bfa                              mov    edi,edx
0x6d92c1  50                                push   eax
0x6d92c2  897c241c                          mov    DWORD PTR [esp+0x1c],edi
0x6d92c6  89442418                          mov    DWORD PTR [esp+0x18],eax
0x6d92ca  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x6d92d0  33db                              xor    ebx,ebx
0x6d92d2  899c2480000000                    mov    DWORD PTR [esp+0x80],ebx
0x6d92d9  53                                push   ebx
0x6d92da  687523bf00                        push   0xbf2375
0x6d92df  8d4c245c                          lea    ecx,[esp+0x5c]
0x6d92e3  c74424700f000000                  mov    DWORD PTR [esp+0x70],0xf
0x6d92eb  895c246c                          mov    DWORD PTR [esp+0x6c],ebx
0x6d92ef  885c245c                          mov    BYTE PTR [esp+0x5c],bl
0x6d92f3  e87897d2ff                        call   0x402a70
0x6d92f8  c684248000000001                  mov    BYTE PTR [esp+0x80],0x1
0x6d9300  8b07                              mov    eax,DWORD PTR [edi]
0x6d9302  6aff                              push   0xffffffff
0x6d9304  53                                push   ebx
0x6d9305  8d4c245c                          lea    ecx,[esp+0x5c]
0x6d9309  51                                push   ecx
0x6d930a  8d4c242c                          lea    ecx,[esp+0x2c]
0x6d930e  89442428                          mov    DWORD PTR [esp+0x28],eax
0x6d9312  c74424400f000000                  mov    DWORD PTR [esp+0x40],0xf
0x6d931a  895c243c                          mov    DWORD PTR [esp+0x3c],ebx
0x6d931e  885c242c                          mov    BYTE PTR [esp+0x2c],bl
0x6d9322  e8199dd2ff                        call   0x403040
0x6d9327  f30f1005c056c400                  movss  xmm0,DWORD PTR ds:0xc456c0
0x6d932f  f30f11442448                      movss  DWORD PTR [esp+0x48],xmm0
0x6d9335  f30f104508                        movss  xmm0,DWORD PTR [ebp+0x8]
0x6d933a  b801000000                        mov    eax,0x1
0x6d933f  ba10270000                        mov    edx,0x2710
0x6d9344  f30f1144244c                      movss  DWORD PTR [esp+0x4c],xmm0
0x6d934a  0f57c0                            xorps  xmm0,xmm0
0x6d934d  8944243c                          mov    DWORD PTR [esp+0x3c],eax
0x6d9351  6689542440                        mov    WORD PTR [esp+0x40],dx
0x6d9356  89442444                          mov    DWORD PTR [esp+0x44],eax
0x6d935a  f30f11442450                      movss  DWORD PTR [esp+0x50],xmm0
0x6d9360  c684248000000002                  mov    BYTE PTR [esp+0x80],0x2
0x6d9368  8b7e28                            mov    edi,DWORD PTR [esi+0x28]
0x6d936b  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x6d936e  8d44241c                          lea    eax,[esp+0x1c]
0x6d9372  50                                push   eax
0x6d9373  51                                push   ecx
0x6d9374  57                                push   edi
0x6d9375  e826180000                        call   0x6daba0
0x6d937a  8b4e2c                            mov    ecx,DWORD PTR [esi+0x2c]
0x6d937d  ba23499204                        mov    edx,0x4924923
0x6d9382  2bd1                              sub    edx,ecx
0x6d9384  83fa01                            cmp    edx,0x1
0x6d9387  730a                              jae    0x6d9393
0x6d9389  683420bf00                        push   0xbf2034
0x6d938e  e89d471a00                        call   0x87db30
0x6d9393  41                                inc    ecx
0x6d9394  894e2c                            mov    DWORD PTR [esi+0x2c],ecx
0x6d9397  894704                            mov    DWORD PTR [edi+0x4],eax
0x6d939a  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x6d939d  bf10000000                        mov    edi,0x10
0x6d93a2  8901                              mov    DWORD PTR [ecx],eax
0x6d93a4  397c2434                          cmp    DWORD PTR [esp+0x34],edi
0x6d93a8  720d                              jb     0x6d93b7
0x6d93aa  8b542420                          mov    edx,DWORD PTR [esp+0x20]
0x6d93ae  52                                push   edx
0x6d93af  e8587e1b00                        call   0x89120c
0x6d93b4  83c404                            add    esp,0x4
0x6d93b7  c74424340f000000                  mov    DWORD PTR [esp+0x34],0xf
0x6d93bf  895c2430                          mov    DWORD PTR [esp+0x30],ebx
0x6d93c3  885c2420                          mov    BYTE PTR [esp+0x20],bl
0x6d93c7  397c2468                          cmp    DWORD PTR [esp+0x68],edi
0x6d93cb  720d                              jb     0x6d93da
0x6d93cd  8b442454                          mov    eax,DWORD PTR [esp+0x54]
0x6d93d1  50                                push   eax
0x6d93d2  e8357e1b00                        call   0x89120c
0x6d93d7  83c404                            add    esp,0x4
0x6d93da  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x6d93de  8919                              mov    DWORD PTR [ecx],ebx
0x6d93e0  8bb6ac000000                      mov    esi,DWORD PTR [esi+0xac]
0x6d93e6  8b560c                            mov    edx,DWORD PTR [esi+0xc]
0x6d93e9  52                                push   edx
0x6d93ea  c7461001000000                    mov    DWORD PTR [esi+0x10],0x1
0x6d93f1  ff15d020bd00                      call   DWORD PTR ds:0xbd20d0
0x6d93f7  8b442414                          mov    eax,DWORD PTR [esp+0x14]
0x6d93fb  50                                push   eax
0x6d93fc  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x6d9402  8b4c2478                          mov    ecx,DWORD PTR [esp+0x78]
0x6d9406  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x6d940d  59                                pop    ecx
0x6d940e  5f                                pop    edi
0x6d940f  5e                                pop    esi
0x6d9410  5b                                pop    ebx
0x6d9411  8b4c2460                          mov    ecx,DWORD PTR [esp+0x60]
0x6d9415  33cc                              xor    ecx,esp
0x6d9417  e8e57b1b00                        call   0x891001
0x6d941c  8be5                              mov    esp,ebp
0x6d941e  5d                                pop    ebp
0x6d941f  c20400                            ret    0x4

; M13 Fade both slots and clear names/pending delay
; VA 0x6d9da0..0x6d9e0b raw 0x2d91a0 length 107 SHA256 effa9b3697f5478ee9af53f642fa815a9a2cb980f8e3626d8001020b92a6dc01
0x6d9da0  55                                push   ebp
0x6d9da1  8bec                              mov    ebp,esp
0x6d9da3  83e4f8                            and    esp,0xfffffff8
0x6d9da6  837e3400                          cmp    DWORD PTR [esi+0x34],0x0
0x6d9daa  0f57c0                            xorps  xmm0,xmm0
0x6d9dad  8d5634                            lea    edx,[esi+0x34]
0x6d9db0  f30f114668                        movss  DWORD PTR [esi+0x68],xmm0
0x6d9db5  741d                              je     0x6d9dd4
0x6d9db7  d94508                            fld    DWORD PTR [ebp+0x8]
0x6d9dba  51                                push   ecx
0x6d9dbb  8bce                              mov    ecx,esi
0x6d9dbd  d91c24                            fstp   DWORD PTR [esp]
0x6d9dc0  e8bbf4ffff                        call   0x6d9280
0x6d9dc5  6a00                              push   0x0
0x6d9dc7  687523bf00                        push   0xbf2375
0x6d9dcc  8d4e38                            lea    ecx,[esi+0x38]
0x6d9dcf  e89c8cd2ff                        call   0x402a70
0x6d9dd4  837e6c00                          cmp    DWORD PTR [esi+0x6c],0x0
0x6d9dd8  0f57c0                            xorps  xmm0,xmm0
0x6d9ddb  8d566c                            lea    edx,[esi+0x6c]
0x6d9dde  f30f1186a0000000                  movss  DWORD PTR [esi+0xa0],xmm0
0x6d9de6  741d                              je     0x6d9e05
0x6d9de8  d94508                            fld    DWORD PTR [ebp+0x8]
0x6d9deb  51                                push   ecx
0x6d9dec  8bce                              mov    ecx,esi
0x6d9dee  d91c24                            fstp   DWORD PTR [esp]
0x6d9df1  e88af4ffff                        call   0x6d9280
0x6d9df6  6a00                              push   0x0
0x6d9df8  687523bf00                        push   0xbf2375
0x6d9dfd  8d4e70                            lea    ecx,[esi+0x70]
0x6d9e00  e86b8cd2ff                        call   0x402a70
0x6d9e05  8be5                              mov    esp,ebp
0x6d9e07  5d                                pop    ebp
0x6d9e08  c20400                            ret    0x4

; M14 Stop all16 stream drivers, clear fade list and slots
; VA 0x6d9cc0..0x6d9d96 raw 0x2d90c0 length 214 SHA256 af76320128d91d2c9c5a88d269b93d453bc36d08513b714840a14d0488a3b05c
0x6d9cc0  55                                push   ebp
0x6d9cc1  8bec                              mov    ebp,esp
0x6d9cc3  6aff                              push   0xffffffff
0x6d9cc5  68385f9100                        push   0x915f38
0x6d9cca  64a100000000                      mov    eax,fs:0x0
0x6d9cd0  50                                push   eax
0x6d9cd1  51                                push   ecx
0x6d9cd2  53                                push   ebx
0x6d9cd3  57                                push   edi
0x6d9cd4  a1201fd600                        mov    eax,ds:0xd61f20
0x6d9cd9  33c5                              xor    eax,ebp
0x6d9cdb  50                                push   eax
0x6d9cdc  8d45f4                            lea    eax,[ebp-0xc]
0x6d9cdf  64a300000000                      mov    fs:0x0,eax
0x6d9ce5  8d9eb4000000                      lea    ebx,[esi+0xb4]
0x6d9ceb  53                                push   ebx
0x6d9cec  895df0                            mov    DWORD PTR [ebp-0x10],ebx
0x6d9cef  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x6d9cf5  b801000000                        mov    eax,0x1
0x6d9cfa  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x6d9d01  84059816fc00                      test   BYTE PTR ds:0xfc1698,al
0x6d9d07  7518                              jne    0x6d9d21
0x6d9d09  09059816fc00                      or     DWORD PTR ds:0xfc1698,eax
0x6d9d0f  e88c2b1300                        call   0x80c8a0
0x6d9d14  6820e3bc00                        push   0xbce320
0x6d9d19  e8fc851b00                        call   0x89231a
0x6d9d1e  83c404                            add    esp,0x4
0x6d9d21  bfa016fc00                        mov    edi,0xfc16a0
0x6d9d26  8b0f                              mov    ecx,DWORD PTR [edi]
0x6d9d28  85c9                              test   ecx,ecx
0x6d9d2a  7407                              je     0x6d9d33
0x6d9d2c  8b01                              mov    eax,DWORD PTR [ecx]
0x6d9d2e  8b502c                            mov    edx,DWORD PTR [eax+0x2c]
0x6d9d31  ffd2                              call   edx
0x6d9d33  83c704                            add    edi,0x4
0x6d9d36  81ffe016fc00                      cmp    edi,0xfc16e0
0x6d9d3c  7ce8                              jl     0x6d9d26
0x6d9d3e  8d4628                            lea    eax,[esi+0x28]
0x6d9d41  50                                push   eax
0x6d9d42  e8f90d0000                        call   0x6dab40
0x6d9d47  33ff                              xor    edi,edi
0x6d9d49  57                                push   edi
0x6d9d4a  687523bf00                        push   0xbf2375
0x6d9d4f  8d4e38                            lea    ecx,[esi+0x38]
0x6d9d52  e8198dd2ff                        call   0x402a70
0x6d9d57  0f57c0                            xorps  xmm0,xmm0
0x6d9d5a  57                                push   edi
0x6d9d5b  687523bf00                        push   0xbf2375
0x6d9d60  8d4e70                            lea    ecx,[esi+0x70]
0x6d9d63  897e34                            mov    DWORD PTR [esi+0x34],edi
0x6d9d66  f30f114668                        movss  DWORD PTR [esi+0x68],xmm0
0x6d9d6b  e8008dd2ff                        call   0x402a70
0x6d9d70  0f57c0                            xorps  xmm0,xmm0
0x6d9d73  53                                push   ebx
0x6d9d74  897e6c                            mov    DWORD PTR [esi+0x6c],edi
0x6d9d77  f30f1186a0000000                  movss  DWORD PTR [esi+0xa0],xmm0
0x6d9d7f  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x6d9d85  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x6d9d88  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x6d9d8f  59                                pop    ecx
0x6d9d90  5f                                pop    edi
0x6d9d91  5b                                pop    ebx
0x6d9d92  8be5                              mov    esp,ebp
0x6d9d94  5d                                pop    ebp
0x6d9d95  c3                                ret

; M15 Create16 concrete CStreamDriver instances
; VA 0x80c950..0x80ca05 raw 0x40bd50 length 181 SHA256 8e67438c4682e771eec3f786e71a53811ce747420ff1e6e76ef18b901843ca68
0x80c950  55                                push   ebp
0x80c951  8bec                              mov    ebp,esp
0x80c953  51                                push   ecx
0x80c954  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x80c957  57                                push   edi
0x80c958  33ff                              xor    edi,edi
0x80c95a  397844                            cmp    DWORD PTR [eax+0x44],edi
0x80c95d  0f8596000000                      jne    0x80c9f9
0x80c963  53                                push   ebx
0x80c964  56                                push   esi
0x80c965  33db                              xor    ebx,ebx
0x80c967  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x80c96a  8d9b00000000                      lea    ebx,[ebx+0x0]
0x80c970  6a40                              push   0x40
0x80c972  e8f1480800                        call   0x891268
0x80c977  8bf0                              mov    esi,eax
0x80c979  83c404                            add    esp,0x4
0x80c97c  3bf7                              cmp    esi,edi
0x80c97e  7436                              je     0x80c9b6
0x80c980  d9e8                              fld1
0x80c982  68a00f0000                        push   0xfa0
0x80c987  8d4e28                            lea    ecx,[esi+0x28]
0x80c98a  d95e24                            fstp   DWORD PTR [esi+0x24]
0x80c98d  51                                push   ecx
0x80c98e  c706f41bc500                      mov    DWORD PTR [esi],0xc51bf4
0x80c994  897e04                            mov    DWORD PTR [esi+0x4],edi
0x80c997  897e08                            mov    DWORD PTR [esi+0x8],edi
0x80c99a  897e0c                            mov    DWORD PTR [esi+0xc],edi
0x80c99d  897e10                            mov    DWORD PTR [esi+0x10],edi
0x80c9a0  897e14                            mov    DWORD PTR [esi+0x14],edi
0x80c9a3  897e18                            mov    DWORD PTR [esi+0x18],edi
0x80c9a6  897e1c                            mov    DWORD PTR [esi+0x1c],edi
0x80c9a9  897e20                            mov    DWORD PTR [esi+0x20],edi
0x80c9ac  ff152c22bd00                      call   DWORD PTR ds:0xbd222c
0x80c9b2  8bce                              mov    ecx,esi
0x80c9b4  eb02                              jmp    0x80c9b8
0x80c9b6  33c9                              xor    ecx,ecx
0x80c9b8  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x80c9bb  8b75fc                            mov    esi,DWORD PTR [ebp-0x4]
0x80c9be  890cb2                            mov    DWORD PTR [edx+esi*4],ecx
0x80c9c1  3bdf                              cmp    ebx,edi
0x80c9c3  7c13                              jl     0x80c9d8
0x80c9c5  8b01                              mov    eax,DWORD PTR [ecx]
0x80c9c7  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x80c9ca  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x80c9cd  52                                push   edx
0x80c9ce  ffd0                              call   eax
0x80c9d0  85c0                              test   eax,eax
0x80c9d2  7804                              js     0x80c9d8
0x80c9d4  33db                              xor    ebx,ebx
0x80c9d6  eb05                              jmp    0x80c9dd
0x80c9d8  bb05400080                        mov    ebx,0x80004005
0x80c9dd  46                                inc    esi
0x80c9de  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x80c9e1  83fe10                            cmp    esi,0x10
0x80c9e4  7c8a                              jl     0x80c970
0x80c9e6  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x80c9e9  8b08                              mov    ecx,DWORD PTR [eax]
0x80c9eb  5e                                pop    esi
0x80c9ec  894844                            mov    DWORD PTR [eax+0x44],ecx
0x80c9ef  8bc3                              mov    eax,ebx
0x80c9f1  5b                                pop    ebx
0x80c9f2  5f                                pop    edi
0x80c9f3  8be5                              mov    esp,ebp
0x80c9f5  5d                                pop    ebp
0x80c9f6  c20800                            ret    0x8
0x80c9f9  b805400080                        mov    eax,0x80004005
0x80c9fe  5f                                pop    edi
0x80c9ff  8be5                              mov    esp,ebp
0x80ca01  5d                                pop    ebp
0x80ca02  c20800                            ret    0x8

; M16 CStreamDriver Play creates COGGStream and starts native output
; VA 0x80e940..0x80ea1e raw 0x40dd40 length 222 SHA256 1d48573b53dbabb6829c2dd82310fd43cf7d5ce05ea2957cc5bc768ddcc35e7f
0x80e940  55                                push   ebp
0x80e941  8bec                              mov    ebp,esp
0x80e943  53                                push   ebx
0x80e944  33db                              xor    ebx,ebx
0x80e946  56                                push   esi
0x80e947  8bf1                              mov    esi,ecx
0x80e949  395d08                            cmp    DWORD PTR [ebp+0x8],ebx
0x80e94c  750b                              jne    0x80e959
0x80e94e  5e                                pop    esi
0x80e94f  b857000780                        mov    eax,0x80070057
0x80e954  5b                                pop    ebx
0x80e955  5d                                pop    ebp
0x80e956  c20800                            ret    0x8
0x80e959  395e14                            cmp    DWORD PTR [esi+0x14],ebx
0x80e95c  750b                              jne    0x80e969
0x80e95e  5e                                pop    esi
0x80e95f  b801400080                        mov    eax,0x80004001
0x80e964  5b                                pop    ebx
0x80e965  5d                                pop    ebp
0x80e966  c20800                            ret    0x8
0x80e969  8b06                              mov    eax,DWORD PTR [esi]
0x80e96b  8b502c                            mov    edx,DWORD PTR [eax+0x2c]
0x80e96e  57                                push   edi
0x80e96f  ffd2                              call   edx
0x80e971  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x80e974  6a20                              push   0x20
0x80e976  89461c                            mov    DWORD PTR [esi+0x1c],eax
0x80e979  e8ea280800                        call   0x891268
0x80e97e  83c404                            add    esp,0x4
0x80e981  3bc3                              cmp    eax,ebx
0x80e983  7416                              je     0x80e99b
0x80e985  c700401fc500                      mov    DWORD PTR [eax],0xc51f40
0x80e98b  895810                            mov    DWORD PTR [eax+0x10],ebx
0x80e98e  895814                            mov    DWORD PTR [eax+0x14],ebx
0x80e991  895818                            mov    DWORD PTR [eax+0x18],ebx
0x80e994  89581c                            mov    DWORD PTR [eax+0x1c],ebx
0x80e997  8bf8                              mov    edi,eax
0x80e999  eb02                              jmp    0x80e99d
0x80e99b  33ff                              xor    edi,edi
0x80e99d  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x80e9a0  8bcf                              mov    ecx,edi
0x80e9a2  e8691d0000                        call   0x810710
0x80e9a7  85c0                              test   eax,eax
0x80e9a9  751f                              jne    0x80e9ca
0x80e9ab  3bfb                              cmp    edi,ebx
0x80e9ad  740f                              je     0x80e9be
0x80e9af  57                                push   edi
0x80e9b0  c707401fc500                      mov    DWORD PTR [edi],0xc51f40
0x80e9b6  e851280800                        call   0x89120c
0x80e9bb  83c404                            add    esp,0x4
0x80e9be  5f                                pop    edi
0x80e9bf  5e                                pop    esi
0x80e9c0  b857000780                        mov    eax,0x80070057
0x80e9c5  5b                                pop    ebx
0x80e9c6  5d                                pop    ebp
0x80e9c7  c20800                            ret    0x8
0x80e9ca  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x80e9cd  897e10                            mov    DWORD PTR [esi+0x10],edi
0x80e9d0  8b17                              mov    edx,DWORD PTR [edi]
0x80e9d2  8b5208                            mov    edx,DWORD PTR [edx+0x8]
0x80e9d5  50                                push   eax
0x80e9d6  8bcf                              mov    ecx,edi
0x80e9d8  ffd2                              call   edx
0x80e9da  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e9dd  8b01                              mov    eax,DWORD PTR [ecx]
0x80e9df  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x80e9e2  57                                push   edi
0x80e9e3  ffd2                              call   edx
0x80e9e5  85c0                              test   eax,eax
0x80e9e7  7429                              je     0x80ea12
0x80e9e9  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e9ec  8b01                              mov    eax,DWORD PTR [ecx]
0x80e9ee  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0x80e9f1  ffd2                              call   edx
0x80e9f3  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e9f6  8b01                              mov    eax,DWORD PTR [ecx]
0x80e9f8  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x80e9fb  ffd2                              call   edx
0x80e9fd  c7461801000000                    mov    DWORD PTR [esi+0x18],0x1
0x80ea04  e8c7feffff                        call   0x80e8d0
0x80ea09  5f                                pop    edi
0x80ea0a  5e                                pop    esi
0x80ea0b  33c0                              xor    eax,eax
0x80ea0d  5b                                pop    ebx
0x80ea0e  5d                                pop    ebp
0x80ea0f  c20800                            ret    0x8
0x80ea12  5f                                pop    edi
0x80ea13  5e                                pop    esi
0x80ea14  b805400080                        mov    eax,0x80004005
0x80ea19  5b                                pop    ebx
0x80ea1a  5d                                pop    ebp
0x80ea1b  c20800                            ret    0x8

; M17 Stream per-update looping if flag nonzero
; VA 0x80e7d0..0x80e848 raw 0x40dbd0 length 120 SHA256 eeffb289069eb0d5b4ff367157f2b1508000c3f9ce582e1bdd32ae519cde8910
0x80e7d0  56                                push   esi
0x80e7d1  8bf1                              mov    esi,ecx
0x80e7d3  837e1800                          cmp    DWORD PTR [esi+0x18],0x0
0x80e7d7  746b                              je     0x80e844
0x80e7d9  837e1c00                          cmp    DWORD PTR [esi+0x1c],0x0
0x80e7dd  7465                              je     0x80e844
0x80e7df  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e7e2  8b01                              mov    eax,DWORD PTR [ecx]
0x80e7e4  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x80e7e7  ffd2                              call   edx
0x80e7e9  85c0                              test   eax,eax
0x80e7eb  7557                              jne    0x80e844
0x80e7ed  394604                            cmp    DWORD PTR [esi+0x4],eax
0x80e7f0  7552                              jne    0x80e844
0x80e7f2  394608                            cmp    DWORD PTR [esi+0x8],eax
0x80e7f5  754d                              jne    0x80e844
0x80e7f7  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
0x80e7fa  8b01                              mov    eax,DWORD PTR [ecx]
0x80e7fc  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x80e7ff  ffd2                              call   edx
0x80e801  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e804  8b01                              mov    eax,DWORD PTR [ecx]
0x80e806  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x80e809  ffd2                              call   edx
0x80e80b  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e80e  8b01                              mov    eax,DWORD PTR [ecx]
0x80e810  8b5610                            mov    edx,DWORD PTR [esi+0x10]
0x80e813  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x80e816  52                                push   edx
0x80e817  ffd0                              call   eax
0x80e819  85c0                              test   eax,eax
0x80e81b  7427                              je     0x80e844
0x80e81d  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e820  8b11                              mov    edx,DWORD PTR [ecx]
0x80e822  8b420c                            mov    eax,DWORD PTR [edx+0xc]
0x80e825  ffd0                              call   eax
0x80e827  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e82a  8b11                              mov    edx,DWORD PTR [ecx]
0x80e82c  8b4210                            mov    eax,DWORD PTR [edx+0x10]
0x80e82f  ffd0                              call   eax
0x80e831  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80e834  8b11                              mov    edx,DWORD PTR [ecx]
0x80e836  8b4620                            mov    eax,DWORD PTR [esi+0x20]
0x80e839  8b5220                            mov    edx,DWORD PTR [edx+0x20]
0x80e83c  50                                push   eax
0x80e83d  ffd2                              call   edx
0x80e83f  e88c000000                        call   0x80e8d0
0x80e844  33c0                              xor    eax,eax
0x80e846  5e                                pop    esi
0x80e847  c3                                ret

; M18 Concrete Stop waits worker, clears playing, stops native output, frees stream
; VA 0x80eb30..0x80eb8b raw 0x40df30 length 91 SHA256 36a04fb710767747e92344df94aff52b2dc5d42a76001832143d49f63cc7f25f
0x80eb30  56                                push   esi
0x80eb31  8bf1                              mov    esi,ecx
0x80eb33  837e0800                          cmp    DWORD PTR [esi+0x8],0x0
0x80eb37  c7460400000000                    mov    DWORD PTR [esi+0x4],0x0
0x80eb3e  7412                              je     0x80eb52
0x80eb40  57                                push   edi
0x80eb41  8b3d0423bd00                      mov    edi,DWORD PTR ds:0xbd2304
0x80eb47  6a0a                              push   0xa
0x80eb49  ffd7                              call   edi
0x80eb4b  837e0800                          cmp    DWORD PTR [esi+0x8],0x0
0x80eb4f  75f6                              jne    0x80eb47
0x80eb51  5f                                pop    edi
0x80eb52  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x80eb55  c7461800000000                    mov    DWORD PTR [esi+0x18],0x0
0x80eb5c  8b01                              mov    eax,DWORD PTR [ecx]
0x80eb5e  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x80eb61  ffd2                              call   edx
0x80eb63  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
0x80eb66  85c9                              test   ecx,ecx
0x80eb68  741d                              je     0x80eb87
0x80eb6a  8b01                              mov    eax,DWORD PTR [ecx]
0x80eb6c  8b10                              mov    edx,DWORD PTR [eax]
0x80eb6e  ffd2                              call   edx
0x80eb70  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x80eb73  85c0                              test   eax,eax
0x80eb75  7410                              je     0x80eb87
0x80eb77  50                                push   eax
0x80eb78  e88f260800                        call   0x89120c
0x80eb7d  83c404                            add    esp,0x4
0x80eb80  c7461000000000                    mov    DWORD PTR [esi+0x10],0x0
0x80eb87  33c0                              xor    eax,eax
0x80eb89  5e                                pop    esi
0x80eb8a  c3                                ret

; M19 Busy status used by free-slot selector
; VA 0x80ed00..0x80ed1b raw 0x40e100 length 27 SHA256 f8334d401852598ce092c035cf10f374eb66deae5cf2b534acabc8e4e1ca9b9a
0x80ed00  83790400                          cmp    DWORD PTR [ecx+0x4],0x0
0x80ed04  750f                              jne    0x80ed15
0x80ed06  8b4914                            mov    ecx,DWORD PTR [ecx+0x14]
0x80ed09  8b01                              mov    eax,DWORD PTR [ecx]
0x80ed0b  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x80ed0e  ffd2                              call   edx
0x80ed10  85c0                              test   eax,eax
0x80ed12  7501                              jne    0x80ed15
0x80ed14  c3                                ret
0x80ed15  b801000000                        mov    eax,0x1
0x80ed1a  c3                                ret

; M20 Volume forwards transformed gain to output
; VA 0x80eb90..0x80ebbb raw 0x40df90 length 43 SHA256 26db0700a080492730ba766c82060a392f8f93b4942e8f3985e2311ac3265d85
0x80eb90  55                                push   ebp
0x80eb91  8bec                              mov    ebp,esp
0x80eb93  d94124                            fld    DWORD PTR [ecx+0x24]
0x80eb96  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x80eb99  da4d08                            fimul  DWORD PTR [ebp+0x8]
0x80eb9c  56                                push   esi
0x80eb9d  8b7114                            mov    esi,DWORD PTR [ecx+0x14]
0x80eba0  57                                push   edi
0x80eba1  894120                            mov    DWORD PTR [ecx+0x20],eax
0x80eba4  8b3e                              mov    edi,DWORD PTR [esi]
0x80eba6  e865010f00                        call   0x8fed10
0x80ebab  8b5720                            mov    edx,DWORD PTR [edi+0x20]
0x80ebae  50                                push   eax
0x80ebaf  8bce                              mov    ecx,esi
0x80ebb1  ffd2                              call   edx
0x80ebb3  5f                                pop    edi
0x80ebb4  33c0                              xor    eax,eax
0x80ebb6  5e                                pop    esi
0x80ebb7  5d                                pop    ebp
0x80ebb8  c20400                            ret    0x4

; M21 Fade factor clamped[0,1], no Stop call
; VA 0x80ebc0..0x80ec4e raw 0x40dfc0 length 142 SHA256 fc7f2541d6807bacd43939bfea4abf3149af82ddf29df44e10a6fbb69067f67a
0x80ebc0  55                                push   ebp
0x80ebc1  8bec                              mov    ebp,esp
0x80ebc3  51                                push   ecx
0x80ebc4  d9e8                              fld1
0x80ebc6  d94508                            fld    DWORD PTR [ebp+0x8]
0x80ebc9  d8d1                              fcom   st(1)
0x80ebcb  dfe0                              fnstsw ax
0x80ebcd  f6c441                            test   ah,0x41
0x80ebd0  7507                              jne    0x80ebd9
0x80ebd2  ddd8                              fstp   st(0)
0x80ebd4  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x80ebd7  eb11                              jmp    0x80ebea
0x80ebd9  ddd9                              fstp   st(1)
0x80ebdb  d9ee                              fldz
0x80ebdd  d8d1                              fcom   st(1)
0x80ebdf  dfe0                              fnstsw ax
0x80ebe1  ddd9                              fstp   st(1)
0x80ebe3  f6c441                            test   ah,0x41
0x80ebe6  74ec                              je     0x80ebd4
0x80ebe8  ddd8                              fstp   st(0)
0x80ebea  d94508                            fld    DWORD PTR [ebp+0x8]
0x80ebed  dc057856c500                      fadd   QWORD PTR ds:0xc55678
0x80ebf3  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x80ebf6  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x80ebf9  8bc2                              mov    eax,edx
0x80ebfb  81e2ffff7f80                      and    edx,0x807fffff
0x80ec01  81c20000803f                      add    edx,0x3f800000
0x80ec07  895508                            mov    DWORD PTR [ebp+0x8],edx
0x80ec0a  d94508                            fld    DWORD PTR [ebp+0x8]
0x80ec0d  dd05a856c500                      fld    QWORD PTR ds:0xc556a8
0x80ec13  8b5120                            mov    edx,DWORD PTR [ecx+0x20]
0x80ec16  d8c9                              fmul   st,st(1)
0x80ec18  c1f817                            sar    eax,0x17
0x80ec1b  25ff000000                        and    eax,0xff
0x80ec20  83c080                            add    eax,0xffffff80
0x80ec23  dc2da056c500                      fsubr  QWORD PTR ds:0xc556a0
0x80ec29  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x80ec2c  8b01                              mov    eax,DWORD PTR [ecx]
0x80ec2e  8b4048                            mov    eax,DWORD PTR [eax+0x48]
0x80ec31  dec9                              fmulp  st(1),st
0x80ec33  52                                push   edx
0x80ec34  dc259856c500                      fsub   QWORD PTR ds:0xc55698
0x80ec3a  d95d08                            fstp   DWORD PTR [ebp+0x8]
0x80ec3d  db45fc                            fild   DWORD PTR [ebp-0x4]
0x80ec40  d84508                            fadd   DWORD PTR [ebp+0x8]
0x80ec43  d95924                            fstp   DWORD PTR [ecx+0x24]
0x80ec46  ffd0                              call   eax
0x80ec48  8be5                              mov    esp,ebp
0x80ec4a  5d                                pop    ebp
0x80ec4b  c20400                            ret    0x4

; M22 Main-stream pool update dispatch virtual+10 for16 slots
; VA 0x80ca10..0x80ca44 raw 0x40be10 length 52 SHA256 a5efb15c5b89cf618ee5eafa6b473fe3a4c1875cf193029224bc1a649caf48c1
0x80ca10  837f4400                          cmp    DWORD PTR [edi+0x44],0x0
0x80ca14  7506                              jne    0x80ca1c
0x80ca16  b803400080                        mov    eax,0x80004003
0x80ca1b  c3                                ret
0x80ca1c  56                                push   esi
0x80ca1d  33c0                              xor    eax,eax
0x80ca1f  33f6                              xor    esi,esi
0x80ca21  85c0                              test   eax,eax
0x80ca23  7812                              js     0x80ca37
0x80ca25  8b0cb7                            mov    ecx,DWORD PTR [edi+esi*4]
0x80ca28  8b01                              mov    eax,DWORD PTR [ecx]
0x80ca2a  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x80ca2d  ffd2                              call   edx
0x80ca2f  85c0                              test   eax,eax
0x80ca31  7804                              js     0x80ca37
0x80ca33  33c0                              xor    eax,eax
0x80ca35  eb05                              jmp    0x80ca3c
0x80ca37  b805400080                        mov    eax,0x80004005
0x80ca3c  46                                inc    esi
0x80ca3d  83fe10                            cmp    esi,0x10
0x80ca40  7cdf                              jl     0x80ca21
0x80ca42  5e                                pop    esi
0x80ca43  c3                                ret

; M24 SetFinalMusic null/whitespace/append branches
; VA 0x565560..0x5655b1 raw 0x164960 length 81 SHA256 1ca85acec027b4e5fb868d35c1f8630292f41a344ebea261d40f0063de65ff31
0x565560  55                                push   ebp
0x565561  8bec                              mov    ebp,esp
0x565563  56                                push   esi
0x565564  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x565567  57                                push   edi
0x565568  8bf9                              mov    edi,ecx
0x56556a  85f6                              test   esi,esi
0x56556c  743d                              je     0x5655ab
0x56556e  0fbe06                            movsx  eax,BYTE PTR [esi]
0x565571  50                                push   eax
0x565572  e8b9ff3200                        call   0x895530
0x565577  83c404                            add    esp,0x4
0x56557a  85c0                              test   eax,eax
0x56557c  7415                              je     0x565593
0x56557e  6a00                              push   0x0
0x565580  687523bf00                        push   0xbf2375
0x565585  8d4f44                            lea    ecx,[edi+0x44]
0x565588  e8e3d4e9ff                        call   0x402a70
0x56558d  5f                                pop    edi
0x56558e  5e                                pop    esi
0x56558f  5d                                pop    ebp
0x565590  c20400                            ret    0x4
0x565593  8bc6                              mov    eax,esi
0x565595  8d5001                            lea    edx,[eax+0x1]
0x565598  8a08                              mov    cl,BYTE PTR [eax]
0x56559a  40                                inc    eax
0x56559b  84c9                              test   cl,cl
0x56559d  75f9                              jne    0x565598
0x56559f  2bc2                              sub    eax,edx
0x5655a1  50                                push   eax
0x5655a2  56                                push   esi
0x5655a3  8d4f44                            lea    ecx,[edi+0x44]
0x5655a6  e815cae9ff                        call   0x401fc0
0x5655ab  5f                                pop    edi
0x5655ac  5e                                pop    esi
0x5655ad  5d                                pop    ebp
0x5655ae  c20400                            ret    0x4

; M25 String append copies at old length then adds length
; VA 0x401fc0..0x4020db raw 0x13c0 length 283 SHA256 55162959165f19d4cfb02f7c92d7455b78cf0dbfa0d0dd0a918d717adf6f73ad
0x401fc0  55                                push   ebp
0x401fc1  8bec                              mov    ebp,esp
0x401fc3  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x401fc6  56                                push   esi
0x401fc7  57                                push   edi
0x401fc8  8bf1                              mov    esi,ecx
0x401fca  85d2                              test   edx,edx
0x401fcc  7459                              je     0x402027
0x401fce  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x401fd1  83f910                            cmp    ecx,0x10
0x401fd4  7204                              jb     0x401fda
0x401fd6  8b06                              mov    eax,DWORD PTR [esi]
0x401fd8  eb02                              jmp    0x401fdc
0x401fda  8bc6                              mov    eax,esi
0x401fdc  3bd0                              cmp    edx,eax
0x401fde  7247                              jb     0x402027
0x401fe0  83f910                            cmp    ecx,0x10
0x401fe3  7204                              jb     0x401fe9
0x401fe5  8b06                              mov    eax,DWORD PTR [esi]
0x401fe7  eb02                              jmp    0x401feb
0x401fe9  8bc6                              mov    eax,esi
0x401feb  8b7e10                            mov    edi,DWORD PTR [esi+0x10]
0x401fee  03f8                              add    edi,eax
0x401ff0  3bfa                              cmp    edi,edx
0x401ff2  7633                              jbe    0x402027
0x401ff4  83f910                            cmp    ecx,0x10
0x401ff7  7217                              jb     0x402010
0x401ff9  8b06                              mov    eax,DWORD PTR [esi]
0x401ffb  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x401ffe  51                                push   ecx
0x401fff  2bd0                              sub    edx,eax
0x402001  52                                push   edx
0x402002  56                                push   esi
0x402003  8bce                              mov    ecx,esi
0x402005  e8c6feffff                        call   0x401ed0
0x40200a  5f                                pop    edi
0x40200b  5e                                pop    esi
0x40200c  5d                                pop    ebp
0x40200d  c20800                            ret    0x8
0x402010  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x402013  8bc6                              mov    eax,esi
0x402015  51                                push   ecx
0x402016  2bd0                              sub    edx,eax
0x402018  52                                push   edx
0x402019  56                                push   esi
0x40201a  8bce                              mov    ecx,esi
0x40201c  e8affeffff                        call   0x401ed0
0x402021  5f                                pop    edi
0x402022  5e                                pop    esi
0x402023  5d                                pop    ebp
0x402024  c20800                            ret    0x8
0x402027  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x40202a  83c9ff                            or     ecx,0xffffffff
0x40202d  53                                push   ebx
0x40202e  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x402031  2bc8                              sub    ecx,eax
0x402033  3bcb                              cmp    ecx,ebx
0x402035  770a                              ja     0x402041
0x402037  6800d2be00                        push   0xbed200
0x40203c  e8efba4700                        call   0x87db30
0x402041  85db                              test   ebx,ebx
0x402043  0f8489000000                      je     0x4020d2
0x402049  8d3c18                            lea    edi,[eax+ebx*1]
0x40204c  83fffe                            cmp    edi,0xfffffffe
0x40204f  760a                              jbe    0x40205b
0x402051  6800d2be00                        push   0xbed200
0x402056  e8d5ba4700                        call   0x87db30
0x40205b  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x40205e  3bcf                              cmp    ecx,edi
0x402060  731a                              jae    0x40207c
0x402062  50                                push   eax
0x402063  57                                push   edi
0x402064  8bce                              mov    ecx,esi
0x402066  e8550d0000                        call   0x402dc0
0x40206b  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x40206e  85ff                              test   edi,edi
0x402070  7460                              je     0x4020d2
0x402072  837e1410                          cmp    DWORD PTR [esi+0x14],0x10
0x402076  722a                              jb     0x4020a2
0x402078  8b06                              mov    eax,DWORD PTR [esi]
0x40207a  eb28                              jmp    0x4020a4
0x40207c  85ff                              test   edi,edi
0x40207e  75f2                              jne    0x402072
0x402080  897e10                            mov    DWORD PTR [esi+0x10],edi
0x402083  83f910                            cmp    ecx,0x10
0x402086  720e                              jb     0x402096
0x402088  8b06                              mov    eax,DWORD PTR [esi]
0x40208a  5b                                pop    ebx
0x40208b  c60000                            mov    BYTE PTR [eax],0x0
0x40208e  5f                                pop    edi
0x40208f  8bc6                              mov    eax,esi
0x402091  5e                                pop    esi
0x402092  5d                                pop    ebp
0x402093  c20800                            ret    0x8
0x402096  5b                                pop    ebx
0x402097  8bc6                              mov    eax,esi
0x402099  5f                                pop    edi
0x40209a  c60000                            mov    BYTE PTR [eax],0x0
0x40209d  5e                                pop    esi
0x40209e  5d                                pop    ebp
0x40209f  c20800                            ret    0x8
0x4020a2  8bc6                              mov    eax,esi
0x4020a4  53                                push   ebx
0x4020a5  52                                push   edx
0x4020a6  8b5610                            mov    edx,DWORD PTR [esi+0x10]
0x4020a9  03d0                              add    edx,eax
0x4020ab  52                                push   edx
0x4020ac  e81fbb4900                        call   0x89dbd0
0x4020b1  83c40c                            add    esp,0xc
0x4020b4  837e1410                          cmp    DWORD PTR [esi+0x14],0x10
0x4020b8  897e10                            mov    DWORD PTR [esi+0x10],edi
0x4020bb  720f                              jb     0x4020cc
0x4020bd  8b06                              mov    eax,DWORD PTR [esi]
0x4020bf  5b                                pop    ebx
0x4020c0  c6043800                          mov    BYTE PTR [eax+edi*1],0x0
0x4020c4  5f                                pop    edi
0x4020c5  8bc6                              mov    eax,esi
0x4020c7  5e                                pop    esi
0x4020c8  5d                                pop    ebp
0x4020c9  c20800                            ret    0x8
0x4020cc  8bc6                              mov    eax,esi
0x4020ce  c6043800                          mov    BYTE PTR [eax+edi*1],0x0
0x4020d2  5b                                pop    ebx
0x4020d3  5f                                pop    edi
0x4020d4  8bc6                              mov    eax,esi
0x4020d6  5e                                pop    esi
0x4020d7  5d                                pop    ebp
0x4020d8  c20800                            ret    0x8

; M26 RestoreMap uses final-music string and secondary map track
; VA 0x563fa0..0x5643bd raw 0x1633a0 length 1053 SHA256 693ed5e79dd68fbad0adacd08ab767ffc3f6e067155c862b58fe4f321fcbc5bf
0x563fa0  55                                push   ebp
0x563fa1  8bec                              mov    ebp,esp
0x563fa3  83e4f8                            and    esp,0xfffffff8
0x563fa6  6aff                              push   0xffffffff
0x563fa8  6822649300                        push   0x936422
0x563fad  64a100000000                      mov    eax,fs:0x0
0x563fb3  50                                push   eax
0x563fb4  83ec38                            sub    esp,0x38
0x563fb7  a1201fd600                        mov    eax,ds:0xd61f20
0x563fbc  33c4                              xor    eax,esp
0x563fbe  89442430                          mov    DWORD PTR [esp+0x30],eax
0x563fc2  53                                push   ebx
0x563fc3  56                                push   esi
0x563fc4  57                                push   edi
0x563fc5  a1201fd600                        mov    eax,ds:0xd61f20
0x563fca  33c4                              xor    eax,esp
0x563fcc  50                                push   eax
0x563fcd  8d442448                          lea    eax,[esp+0x48]
0x563fd1  64a300000000                      mov    fs:0x0,eax
0x563fd7  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
0x563fde  8bf1                              mov    esi,ecx
0x563fe0  8974241c                          mov    DWORD PTR [esp+0x1c],esi
0x563fe4  bf01000000                        mov    edi,0x1
0x563fe9  7528                              jne    0x564013
0x563feb  093db075fb00                      or     DWORD PTR ds:0xfb75b0,edi
0x563ff1  c744245000000000                  mov    DWORD PTR [esp+0x50],0x0
0x563ff9  e882fdf8ff                        call   0x4f3d80
0x563ffe  68e0d1bc00                        push   0xbcd1e0
0x564003  e812e33200                        call   0x89231a
0x564008  83c404                            add    esp,0x4
0x56400b  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
0x564013  8b4634                            mov    eax,DWORD PTR [esi+0x34]
0x564016  8d4c2418                          lea    ecx,[esp+0x18]
0x56401a  89442418                          mov    DWORD PTR [esp+0x18],eax
0x56401e  51                                push   ecx
0x56401f  8d442418                          lea    eax,[esp+0x18]
0x564023  b9e074fb00                        mov    ecx,0xfb74e0
0x564028  e8c3bdf1ff                        call   0x47fdf0
0x56402d  8b442414                          mov    eax,DWORD PTR [esp+0x14]
0x564031  bb10000000                        mov    ebx,0x10
0x564036  3b05e474fb00                      cmp    eax,DWORD PTR ds:0xfb74e4
0x56403c  741a                              je     0x564058
0x56403e  03c3                              add    eax,ebx
0x564040  395814                            cmp    DWORD PTR [eax+0x14],ebx
0x564043  7202                              jb     0x564047
0x564045  8b00                              mov    eax,DWORD PTR [eax]
0x564047  8bc8                              mov    ecx,eax
0x564049  bf7074fb00                        mov    edi,0xfb7470
0x56404e  e82d2ef9ff                        call   0x4f6e80
0x564053  bf01000000                        mov    edi,0x1
0x564058  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
0x56405f  7524                              jne    0x564085
0x564061  093db075fb00                      or     DWORD PTR ds:0xfb75b0,edi
0x564067  897c2450                          mov    DWORD PTR [esp+0x50],edi
0x56406b  e810fdf8ff                        call   0x4f3d80
0x564070  68e0d1bc00                        push   0xbcd1e0
0x564075  e8a0e23200                        call   0x89231a
0x56407a  83c404                            add    esp,0x4
0x56407d  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
0x564085  8b5634                            mov    edx,DWORD PTR [esi+0x34]
0x564088  89542414                          mov    DWORD PTR [esp+0x14],edx
0x56408c  8d542414                          lea    edx,[esp+0x14]
0x564090  b9b074fb00                        mov    ecx,0xfb74b0
0x564095  e8563df9ff                        call   0x4f7df0
0x56409a  395814                            cmp    DWORD PTR [eax+0x14],ebx
0x56409d  7202                              jb     0x5640a1
0x56409f  8b00                              mov    eax,DWORD PTR [eax]
0x5640a1  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
0x5640a8  89442418                          mov    DWORD PTR [esp+0x18],eax
0x5640ac  7528                              jne    0x5640d6
0x5640ae  093db075fb00                      or     DWORD PTR ds:0xfb75b0,edi
0x5640b4  c744245002000000                  mov    DWORD PTR [esp+0x50],0x2
0x5640bc  e8bffcf8ff                        call   0x4f3d80
0x5640c1  68e0d1bc00                        push   0xbcd1e0
0x5640c6  e84fe23200                        call   0x89231a
0x5640cb  83c404                            add    esp,0x4
0x5640ce  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
0x5640d6  8b4e34                            mov    ecx,DWORD PTR [esi+0x34]
0x5640d9  8d542414                          lea    edx,[esp+0x14]
0x5640dd  894c2414                          mov    DWORD PTR [esp+0x14],ecx
0x5640e1  52                                push   edx
0x5640e2  8d442424                          lea    eax,[esp+0x24]
0x5640e6  b9f074fb00                        mov    ecx,0xfb74f0
0x5640eb  e800bdf1ff                        call   0x47fdf0
0x5640f0  8b442420                          mov    eax,DWORD PTR [esp+0x20]
0x5640f4  3b05f474fb00                      cmp    eax,DWORD PTR ds:0xfb74f4
0x5640fa  741b                              je     0x564117
0x5640fc  83c010                            add    eax,0x10
0x5640ff  395814                            cmp    DWORD PTR [eax+0x14],ebx
0x564102  7202                              jb     0x564106
0x564104  8b00                              mov    eax,DWORD PTR [eax]
0x564106  8bc8                              mov    ecx,eax
0x564108  bf7074fb00                        mov    edi,0xfb7470
0x56410d  e86e2df9ff                        call   0x4f6e80
0x564112  bf01000000                        mov    edi,0x1
0x564117  837e5400                          cmp    DWORD PTR [esi+0x54],0x0
0x56411b  0f84bc010000                      je     0x5642dd
0x564121  6a06                              push   0x6
0x564123  683c07c100                        push   0xc1073c
0x564128  8d4c242c                          lea    ecx,[esp+0x2c]
0x56412c  c74424400f000000                  mov    DWORD PTR [esp+0x40],0xf
0x564134  c744243c00000000                  mov    DWORD PTR [esp+0x3c],0x0
0x56413c  c644242c00                        mov    BYTE PTR [esp+0x2c],0x0
0x564141  e82ae9e9ff                        call   0x402a70
0x564146  6aff                              push   0xffffffff
0x564148  6a00                              push   0x0
0x56414a  83c644                            add    esi,0x44
0x56414d  bb03000000                        mov    ebx,0x3
0x564152  56                                push   esi
0x564153  8d4c2430                          lea    ecx,[esp+0x30]
0x564157  895c245c                          mov    DWORD PTR [esp+0x5c],ebx
0x56415b  e870dde9ff                        call   0x401ed0
0x564160  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
0x564167  7522                              jne    0x56418b
0x564169  830d2888fb0001                    or     DWORD PTR ds:0xfb8828,0x1
0x564170  c644245004                        mov    BYTE PTR [esp+0x50],0x4
0x564175  e8d6b6feff                        call   0x54f850
0x56417a  6880d5bc00                        push   0xbcd580
0x56417f  e896e13200                        call   0x89231a
0x564184  83c404                            add    esp,0x4
0x564187  885c2450                          mov    BYTE PTR [esp+0x50],bl
0x56418b  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
0x564192  668b35ea90fb00                    mov    si,WORD PTR ds:0xfb90ea
0x564199  7522                              jne    0x5641bd
0x56419b  830d2888fb0001                    or     DWORD PTR ds:0xfb8828,0x1
0x5641a2  c644245005                        mov    BYTE PTR [esp+0x50],0x5
0x5641a7  e8a4b6feff                        call   0x54f850
0x5641ac  6880d5bc00                        push   0xbcd580
0x5641b1  e864e13200                        call   0x89231a
0x5641b6  83c404                            add    esp,0x4
0x5641b9  885c2450                          mov    BYTE PTR [esp+0x50],bl
0x5641bd  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
0x5641c4  f30f10055c93fb00                  movss  xmm0,DWORD PTR ds:0xfb935c
0x5641cc  f30f11442414                      movss  DWORD PTR [esp+0x14],xmm0
0x5641d2  7522                              jne    0x5641f6
0x5641d4  830dc00ffc0001                    or     DWORD PTR ds:0xfc0fc0,0x1
0x5641db  c644245006                        mov    BYTE PTR [esp+0x50],0x6
0x5641e0  e86b4c1700                        call   0x6d8e50
0x5641e5  68b0dbbc00                        push   0xbcdbb0
0x5641ea  e82be13200                        call   0x89231a
0x5641ef  83c404                            add    esp,0x4
0x5641f2  885c2450                          mov    BYTE PTR [esp+0x50],bl
0x5641f6  837c243810                        cmp    DWORD PTR [esp+0x38],0x10
0x5641fb  8b7c2424                          mov    edi,DWORD PTR [esp+0x24]
0x5641ff  7304                              jae    0x564205
0x564201  8d7c2424                          lea    edi,[esp+0x24]
0x564205  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
0x56420c  7522                              jne    0x564230
0x56420e  830dc00ffc0001                    or     DWORD PTR ds:0xfc0fc0,0x1
0x564215  c644245007                        mov    BYTE PTR [esp+0x50],0x7
0x56421a  e8314c1700                        call   0x6d8e50
0x56421f  68b0dbbc00                        push   0xbcdbb0
0x564224  e8f1e03200                        call   0x89231a
0x564229  83c404                            add    esp,0x4
0x56422c  885c2450                          mov    BYTE PTR [esp+0x50],bl
0x564230  0fbfc6                            movsx  eax,si
0x564233  89442420                          mov    DWORD PTR [esp+0x20],eax
0x564237  db442420                          fild   DWORD PTR [esp+0x20]
0x56423b  d84c2414                          fmul   DWORD PTR [esp+0x14]
0x56423f  e8ccaa3900                        call   0x8fed10
0x564244  e827681700                        call   0x6daa70
0x564249  e8c2aa3900                        call   0x8fed10
0x56424e  0fb7c0                            movzx  eax,ax
0x564251  50                                push   eax
0x564252  6a01                              push   0x1
0x564254  57                                push   edi
0x564255  68c80ffc00                        push   0xfc0fc8
0x56425a  b9fc0ffc00                        mov    ecx,0xfc0ffc
0x56425f  e8cc581700                        call   0x6d9b30
0x564264  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
0x56426b  7522                              jne    0x56428f
0x56426d  830dc00ffc0001                    or     DWORD PTR ds:0xfc0fc0,0x1
0x564274  c644245008                        mov    BYTE PTR [esp+0x50],0x8
0x564279  e8d24b1700                        call   0x6d8e50
0x56427e  68b0dbbc00                        push   0xbcdbb0
0x564283  e892e03200                        call   0x89231a
0x564288  83c404                            add    esp,0x4
0x56428b  885c2450                          mov    BYTE PTR [esp+0x50],bl
0x56428f  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
0x564293  8b5134                            mov    edx,DWORD PTR [ecx+0x34]
0x564296  52                                push   edx
0x564297  68c80ffc00                        push   0xfc0fc8
0x56429c  e8df521700                        call   0x6d9580
0x5642a1  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
0x5642a9  837c243810                        cmp    DWORD PTR [esp+0x38],0x10
0x5642ae  720d                              jb     0x5642bd
0x5642b0  8b442424                          mov    eax,DWORD PTR [esp+0x24]
0x5642b4  50                                push   eax
0x5642b5  e852cf3200                        call   0x89120c
0x5642ba  83c404                            add    esp,0x4
0x5642bd  8b74241c                          mov    esi,DWORD PTR [esp+0x1c]
0x5642c1  c74424380f000000                  mov    DWORD PTR [esp+0x38],0xf
0x5642c9  c744243400000000                  mov    DWORD PTR [esp+0x34],0x0
0x5642d1  c644242400                        mov    BYTE PTR [esp+0x24],0x0
0x5642d6  bf01000000                        mov    edi,0x1
0x5642db  eb3f                              jmp    0x56431c
0x5642dd  f605c00ffc0001                    test   BYTE PTR ds:0xfc0fc0,0x1
0x5642e4  7528                              jne    0x56430e
0x5642e6  093dc00ffc00                      or     DWORD PTR ds:0xfc0fc0,edi
0x5642ec  c744245009000000                  mov    DWORD PTR [esp+0x50],0x9
0x5642f4  e8574b1700                        call   0x6d8e50
0x5642f9  68b0dbbc00                        push   0xbcdbb0
0x5642fe  e817e03200                        call   0x89231a
0x564303  83c404                            add    esp,0x4
0x564306  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
0x56430e  8b4e34                            mov    ecx,DWORD PTR [esi+0x34]
0x564311  51                                push   ecx
0x564312  68c80ffc00                        push   0xfc0fc8
0x564317  e864521700                        call   0x6d9580
0x56431c  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x564323  7528                              jne    0x56434d
0x564325  093d2cb2fa00                      or     DWORD PTR ds:0xfab22c,edi
0x56432b  c74424500a000000                  mov    DWORD PTR [esp+0x50],0xa
0x564333  e858a9f7ff                        call   0x4dec90
0x564338  6830cebc00                        push   0xbcce30
0x56433d  e8d8df3200                        call   0x89231a
0x564342  83c404                            add    esp,0x4
0x564345  c7442450ffffffff                  mov    DWORD PTR [esp+0x50],0xffffffff
0x56434d  8b1578b1fa00                      mov    edx,DWORD PTR ds:0xfab178
0x564353  895634                            mov    DWORD PTR [esi+0x34],edx
0x564356  8b742418                          mov    esi,DWORD PTR [esp+0x18]
0x56435a  6a00                              push   0x0
0x56435c  e89fda2500                        call   0x7c1e00
0x564361  83c404                            add    esp,0x4
0x564364  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x56436b  7521                              jne    0x56438e
0x56436d  830de879fb0001                    or     DWORD PTR ds:0xfb79e8,0x1
0x564374  c74424500b000000                  mov    DWORD PTR [esp+0x50],0xb
0x56437c  e85f4a2300                        call   0x798de0
0x564381  68e0d2bc00                        push   0xbcd2e0
0x564386  e88fdf3200                        call   0x89231a
0x56438b  83c404                            add    esp,0x4
0x56438e  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
0x564392  8b4830                            mov    ecx,DWORD PTR [eax+0x30]
0x564395  a1e876fb00                        mov    eax,ds:0xfb76e8
0x56439a  e8d13f2300                        call   0x798370
0x56439f  8b4c2448                          mov    ecx,DWORD PTR [esp+0x48]
0x5643a3  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5643aa  59                                pop    ecx
0x5643ab  5f                                pop    edi
0x5643ac  5e                                pop    esi
0x5643ad  5b                                pop    ebx
0x5643ae  8b4c2430                          mov    ecx,DWORD PTR [esp+0x30]
0x5643b2  33cc                              xor    ecx,esp
0x5643b4  e848cc3200                        call   0x891001
0x5643b9  8be5                              mov    esp,ebp
0x5643bb  5d                                pop    ebp
0x5643bc  c3                                ret

; M27 Secondary music slot PM+6C by map lookup
; VA 0x6d9580..0x6d967e raw 0x2d8980 length 254 SHA256 106ed450985f6aa6d7e9d9629fc6b357044e396202adb61e52acf030c2c2dd26
0x6d9580  55                                push   ebp
0x6d9581  8bec                              mov    ebp,esp
0x6d9583  6aff                              push   0xffffffff
0x6d9585  68cc969200                        push   0x9296cc
0x6d958a  64a100000000                      mov    eax,fs:0x0
0x6d9590  50                                push   eax
0x6d9591  51                                push   ecx
0x6d9592  53                                push   ebx
0x6d9593  56                                push   esi
0x6d9594  57                                push   edi
0x6d9595  a1201fd600                        mov    eax,ds:0xd61f20
0x6d959a  33c5                              xor    eax,ebp
0x6d959c  50                                push   eax
0x6d959d  8d45f4                            lea    eax,[ebp-0xc]
0x6d95a0  64a300000000                      mov    fs:0x0,eax
0x6d95a6  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6d95a9  8bcb                              mov    ecx,ebx
0x6d95ab  e8d0010000                        call   0x6d9780
0x6d95b0  f605b075fb0001                    test   BYTE PTR ds:0xfb75b0,0x1
0x6d95b7  7527                              jne    0x6d95e0
0x6d95b9  830db075fb0001                    or     DWORD PTR ds:0xfb75b0,0x1
0x6d95c0  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x6d95c7  e8b4a7e1ff                        call   0x4f3d80
0x6d95cc  68e0d1bc00                        push   0xbcd1e0
0x6d95d1  e8448d1b00                        call   0x89231a
0x6d95d6  83c404                            add    esp,0x4
0x6d95d9  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x6d95e0  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6d95e3  8d4d08                            lea    ecx,[ebp+0x8]
0x6d95e6  894508                            mov    DWORD PTR [ebp+0x8],eax
0x6d95e9  51                                push   ecx
0x6d95ea  8d450c                            lea    eax,[ebp+0xc]
0x6d95ed  b9f074fb00                        mov    ecx,0xfb74f0
0x6d95f2  e8f967daff                        call   0x47fdf0
0x6d95f7  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6d95fa  3b05f474fb00                      cmp    eax,DWORD PTR ds:0xfb74f4
0x6d9600  7507                              jne    0x6d9609
0x6d9602  be1cd6c000                        mov    esi,0xc0d61c
0x6d9607  eb1d                              jmp    0x6d9626
0x6d9609  83c010                            add    eax,0x10
0x6d960c  83781410                          cmp    DWORD PTR [eax+0x14],0x10
0x6d9610  7202                              jb     0x6d9614
0x6d9612  8b00                              mov    eax,DWORD PTR [eax]
0x6d9614  8bc8                              mov    ecx,eax
0x6d9616  bf7074fb00                        mov    edi,0xfb7470
0x6d961b  e860d8e1ff                        call   0x4f6e80
0x6d9620  8bf0                              mov    esi,eax
0x6d9622  85f6                              test   esi,esi
0x6d9624  7444                              je     0x6d966a
0x6d9626  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
0x6d962d  7527                              jne    0x6d9656
0x6d962f  b801000000                        mov    eax,0x1
0x6d9634  09052888fb00                      or     DWORD PTR ds:0xfb8828,eax
0x6d963a  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x6d963d  e80e62e7ff                        call   0x54f850
0x6d9642  6880d5bc00                        push   0xbcd580
0x6d9647  e8ce8c1b00                        call   0x89231a
0x6d964c  83c404                            add    esp,0x4
0x6d964f  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x6d9656  0fb715d692fb00                    movzx  edx,WORD PTR ds:0xfb92d6
0x6d965d  52                                push   edx
0x6d965e  6a01                              push   0x1
0x6d9660  56                                push   esi
0x6d9661  8d4b6c                            lea    ecx,[ebx+0x6c]
0x6d9664  53                                push   ebx
0x6d9665  e8c6040000                        call   0x6d9b30
0x6d966a  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x6d966d  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x6d9674  59                                pop    ecx
0x6d9675  5f                                pop    edi
0x6d9676  5e                                pop    esi
0x6d9677  5b                                pop    ebx
0x6d9678  8be5                              mov    esp,ebp
0x6d967a  5d                                pop    ebp
0x6d967b  c20800                            ret    0x8

; M28 R runtime update-rate getter
; VA 0x6df1b0..0x6df1e9 raw 0x2de5b0 length 57 SHA256 bd1c14b702d35e7690571e13543012a8fff1195656328999a26b49cbe519c60d
0x6df1b0  a1cca7fb00                        mov    eax,ds:0xfba7cc
0x6df1b5  85c0                              test   eax,eax
0x6df1b7  7529                              jne    0x6df1e2
0x6df1b9  6880130000                        push   0x1380
0x6df1be  e8a5201b00                        call   0x891268
0x6df1c3  83c404                            add    esp,0x4
0x6df1c6  85c0                              test   eax,eax
0x6df1c8  7411                              je     0x6df1db
0x6df1ca  e801020000                        call   0x6df3d0
0x6df1cf  a3cca7fb00                        mov    ds:0xfba7cc,eax
0x6df1d4  8b8060130000                      mov    eax,DWORD PTR [eax+0x1360]
0x6df1da  c3                                ret
0x6df1db  33c0                              xor    eax,eax
0x6df1dd  a3cca7fb00                        mov    ds:0xfba7cc,eax
0x6df1e2  8b8060130000                      mov    eax,DWORD PTR [eax+0x1360]
0x6df1e8  c3                                ret

; M00 CMusicPlayer constructs functor(receiverFC0FC8, callback6D9870) and AlarmedThread
; VA 0x6d9022..0x6d909d raw 0x2d8422 length 123 SHA256 41eeac966bbf6618e81906de937d74cbdd259e64ece0cea17a367c0e782fe572
0x6d9022  68a00f0000                        push   0xfa0
0x6d9027  687c10fc00                        push   0xfc107c
0x6d902c  891d6c10fc00                      mov    DWORD PTR ds:0xfc106c,ebx
0x6d9032  891d7010fc00                      mov    DWORD PTR ds:0xfc1070,ebx
0x6d9038  ff152c22bd00                      call   DWORD PTR ds:0xbd222c
0x6d903e  6a18                              push   0x18
0x6d9040  c645fc08                          mov    BYTE PTR [ebp-0x4],0x8
0x6d9044  e81f821b00                        call   0x891268
0x6d9049  8bf0                              mov    esi,eax
0x6d904b  83c404                            add    esp,0x4
0x6d904e  8975b4                            mov    DWORD PTR [ebp-0x4c],esi
0x6d9051  c645fc09                          mov    BYTE PTR [ebp-0x4],0x9
0x6d9055  3bf3                              cmp    esi,ebx
0x6d9057  7432                              je     0x6d908b
0x6d9059  6a0c                              push   0xc
0x6d905b  e808821b00                        call   0x891268
0x6d9060  83c404                            add    esp,0x4
0x6d9063  3bc3                              cmp    eax,ebx
0x6d9065  741b                              je     0x6d9082
0x6d9067  c700ec0fc400                      mov    DWORD PTR [eax],0xc40fec
0x6d906d  c74004c80ffc00                    mov    DWORD PTR [eax+0x4],0xfc0fc8
0x6d9074  c7400870986d00                    mov    DWORD PTR [eax+0x8],0x6d9870
0x6d907b  e8a0fcffff                        call   0x6d8d20
0x6d9080  eb0b                              jmp    0x6d908d
0x6d9082  33c0                              xor    eax,eax
0x6d9084  e897fcffff                        call   0x6d8d20
0x6d9089  eb02                              jmp    0x6d908d
0x6d908b  33c0                              xor    eax,eax
0x6d908d  c645fc08                          mov    BYTE PTR [ebp-0x4],0x8
0x6d9091  833ddc0ffc0010                    cmp    DWORD PTR ds:0xfc0fdc,0x10
0x6d9098  a37410fc00                        mov    ds:0xfc1074,eax

; M10 Volume fade states0..3; all normal returns0; no Stop on zero factor
; VA 0x6d9a10..0x6d9b12 raw 0x2d8e10 length 258 SHA256 503102cdb339b5256ba0866ae289ec7f801a6dfcf828bee2194c76017426d136
0x6d9a10  55                                push   ebp
0x6d9a11  8bec                              mov    ebp,esp
0x6d9a13  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x6d9a16  83ec0c                            sub    esp,0xc
0x6d9a19  83f803                            cmp    eax,0x3
0x6d9a1c  0f87ea000000                      ja     0x6d9b0c
0x6d9a22  ff2485149b6d00                    jmp    DWORD PTR [eax*4+0x6d9b14]
0x6d9a29  f30f1005c056c400                  movss  xmm0,DWORD PTR ds:0xc456c0
0x6d9a31  f30f11462c                        movss  DWORD PTR [esi+0x2c],xmm0
0x6d9a36  33c0                              xor    eax,eax
0x6d9a38  8be5                              mov    esp,ebp
0x6d9a3a  5d                                pop    ebp
0x6d9a3b  c3                                ret
0x6d9a3c  d9462c                            fld    DWORD PTR [esi+0x2c]
0x6d9a3f  dd5df4                            fstp   QWORD PTR [ebp-0xc]
0x6d9a42  e869570000                        call   0x6df1b0
0x6d9a47  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x6d9a4a  db45fc                            fild   DWORD PTR [ebp-0x4]
0x6d9a4d  d9e8                              fld1
0x6d9a4f  def1                              fdivrp st(1),st
0x6d9a51  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x6d9a54  d945fc                            fld    DWORD PTR [ebp-0x4]
0x6d9a57  d87630                            fdiv   DWORD PTR [esi+0x30]
0x6d9a5a  dc6df4                            fsubr  QWORD PTR [ebp-0xc]
0x6d9a5d  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x6d9a60  d945fc                            fld    DWORD PTR [ebp-0x4]
0x6d9a63  d9562c                            fst    DWORD PTR [esi+0x2c]
0x6d9a66  807f2500                          cmp    BYTE PTR [edi+0x25],0x0
0x6d9a6a  740b                              je     0x6d9a77
0x6d9a6c  dc0d7056c500                      fmul   QWORD PTR ds:0xc55670
0x6d9a72  d95e2c                            fstp   DWORD PTR [esi+0x2c]
0x6d9a75  eb02                              jmp    0x6d9a79
0x6d9a77  ddd8                              fstp   st(0)
0x6d9a79  0f57c0                            xorps  xmm0,xmm0
0x6d9a7c  0f2f462c                          comiss xmm0,DWORD PTR [esi+0x2c]
0x6d9a80  720c                              jb     0x6d9a8e
0x6d9a82  c7462802000000                    mov    DWORD PTR [esi+0x28],0x2
0x6d9a89  f30f11462c                        movss  DWORD PTR [esi+0x2c],xmm0
0x6d9a8e  8b0e                              mov    ecx,DWORD PTR [esi]
0x6d9a90  85c9                              test   ecx,ecx
0x6d9a92  7478                              je     0x6d9b0c
0x6d9a94  8b01                              mov    eax,DWORD PTR [ecx]
0x6d9a96  d9462c                            fld    DWORD PTR [esi+0x2c]
0x6d9a99  8b504c                            mov    edx,DWORD PTR [eax+0x4c]
0x6d9a9c  51                                push   ecx
0x6d9a9d  d91c24                            fstp   DWORD PTR [esp]
0x6d9aa0  ffd2                              call   edx
0x6d9aa2  33c0                              xor    eax,eax
0x6d9aa4  8be5                              mov    esp,ebp
0x6d9aa6  5d                                pop    ebp
0x6d9aa7  c3                                ret
0x6d9aa8  e803570000                        call   0x6df1b0
0x6d9aad  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x6d9ab0  db45fc                            fild   DWORD PTR [ebp-0x4]
0x6d9ab3  d9e8                              fld1
0x6d9ab5  def1                              fdivrp st(1),st
0x6d9ab7  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x6d9aba  d945fc                            fld    DWORD PTR [ebp-0x4]
0x6d9abd  d87630                            fdiv   DWORD PTR [esi+0x30]
0x6d9ac0  d8462c                            fadd   DWORD PTR [esi+0x2c]
0x6d9ac3  d95dfc                            fstp   DWORD PTR [ebp-0x4]
0x6d9ac6  d945fc                            fld    DWORD PTR [ebp-0x4]
0x6d9ac9  d9562c                            fst    DWORD PTR [esi+0x2c]
0x6d9acc  807f2500                          cmp    BYTE PTR [edi+0x25],0x0
0x6d9ad0  740b                              je     0x6d9add
0x6d9ad2  dc0d7056c500                      fmul   QWORD PTR ds:0xc55670
0x6d9ad8  d95e2c                            fstp   DWORD PTR [esi+0x2c]
0x6d9adb  eb02                              jmp    0x6d9adf
0x6d9add  ddd8                              fstp   st(0)
0x6d9adf  f30f104e2c                        movss  xmm1,DWORD PTR [esi+0x2c]
0x6d9ae4  f30f1005c056c400                  movss  xmm0,DWORD PTR ds:0xc456c0
0x6d9aec  0f2fc8                            comiss xmm1,xmm0
0x6d9aef  729d                              jb     0x6d9a8e
0x6d9af1  c7462800000000                    mov    DWORD PTR [esi+0x28],0x0
0x6d9af8  eb8f                              jmp    0x6d9a89
0x6d9afa  833e00                            cmp    DWORD PTR [esi],0x0
0x6d9afd  0f57c0                            xorps  xmm0,xmm0
0x6d9b00  f30f11462c                        movss  DWORD PTR [esi+0x2c],xmm0
0x6d9b05  7405                              je     0x6d9b0c
0x6d9b07  f30f114634                        movss  DWORD PTR [esi+0x34],xmm0
0x6d9b0c  33c0                              xor    eax,eax
0x6d9b0e  8be5                              mov    esp,ebp
0x6d9b10  5d                                pop    ebp
0x6d9b11  c3                                ret

; M10_switch Music fade state jump targets
; VA 0x6d9b14..0x6d9b24 raw 0x2d8f14 length 16 SHA256 0442076cbdabfd8c35c2c48a5f9da38842a1b4d41831ab8529468279c6626a38
; bytes 299a6d003c9a6d00fa9a6d00a89a6d00

; M23 Main update dispatches BGM stream pool
; VA 0x491314..0x49133f raw 0x90714 length 43 SHA256 1cbeae97bc21e7ff6855c428bbaa5e05d26a08eda6baaaf9c4ea876469776fdd
0x491314  f6059816fc0001                    test   BYTE PTR ds:0xfc1698,0x1
0x49131b  7518                              jne    0x491335
0x49131d  093d9816fc00                      or     DWORD PTR ds:0xfc1698,edi
0x491323  e878b53700                        call   0x80c8a0
0x491328  6820e3bc00                        push   0xbce320
0x49132d  e8e80f4000                        call   0x89231a
0x491332  83c404                            add    esp,0x4
0x491335  bfa016fc00                        mov    edi,0xfc16a0
0x49133a  e8d1b63700                        call   0x80ca10

; M29 Native Stop final-music metadata fallback before RestoreMap
; VA 0x5625fb..0x562690 raw 0x1619fb length 149 SHA256 0c093e5d99de13d9e661f3a5e65aabb6557706f1f16f72c793173c3bdb39594b
0x5625fb  8b4754                            mov    eax,DWORD PTR [edi+0x54]
0x5625fe  bf04000000                        mov    edi,0x4
0x562603  3bc6                              cmp    eax,esi
0x562605  0f857c000000                      jne    0x562687
0x56260b  f605e81efe0001                    test   BYTE PTR ds:0xfe1ee8,0x1
0x562612  7525                              jne    0x562639
0x562614  830de81efe0001                    or     DWORD PTR ds:0xfe1ee8,0x1
0x56261b  c744244003000000                  mov    DWORD PTR [esp+0x40],0x3
0x562623  e8e89fffff                        call   0x55c610
0x562628  6890f2bc00                        push   0xbcf290
0x56262d  e8e8fc3200                        call   0x89231a
0x562632  83c404                            add    esp,0x4
0x562635  895c2440                          mov    DWORD PTR [esp+0x40],ebx
0x562639  68ec1efe00                        push   0xfe1eec
0x56263e  8d742418                          lea    esi,[esp+0x18]
0x562642  e879d9ffff                        call   0x55ffc0
0x562647  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x56264b  50                                push   eax
0x56264c  83c144                            add    ecx,0x44
0x56264f  897c2444                          mov    DWORD PTR [esp+0x44],edi
0x562653  e85805eaff                        call   0x402bb0
0x562658  895c2440                          mov    DWORD PTR [esp+0x40],ebx
0x56265c  837c242810                        cmp    DWORD PTR [esp+0x28],0x10
0x562661  720d                              jb     0x562670
0x562663  8b442414                          mov    eax,DWORD PTR [esp+0x14]
0x562667  50                                push   eax
0x562668  e89feb3200                        call   0x89120c
0x56266d  83c404                            add    esp,0x4
0x562670  c74424280f000000                  mov    DWORD PTR [esp+0x28],0xf
0x562678  c744242400000000                  mov    DWORD PTR [esp+0x24],0x0
0x562680  c644241400                        mov    BYTE PTR [esp+0x14],0x0
0x562685  33f6                              xor    esi,esi
0x562687  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x56268b  e810190000                        call   0x563fa0

; S01 Q PlaySound resource lookup and virtual Play
; VA 0x564cc0..0x564d8a raw 0x1640c0 length 202 SHA256 af8439ff78e25aa8832030d721870c35f6876236566f379fdc74dcabd830ba1a
0x564cc0  55                                push   ebp
0x564cc1  8bec                              mov    ebp,esp
0x564cc3  6aff                              push   0xffffffff
0x564cc5  68162c9300                        push   0x932c16
0x564cca  64a100000000                      mov    eax,fs:0x0
0x564cd0  50                                push   eax
0x564cd1  83ec24                            sub    esp,0x24
0x564cd4  a1201fd600                        mov    eax,ds:0xd61f20
0x564cd9  33c5                              xor    eax,ebp
0x564cdb  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x564cde  53                                push   ebx
0x564cdf  56                                push   esi
0x564ce0  50                                push   eax
0x564ce1  8d45f4                            lea    eax,[ebp-0xc]
0x564ce4  64a300000000                      mov    fs:0x0,eax
0x564cea  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x564ced  33db                              xor    ebx,ebx
0x564cef  8bc2                              mov    eax,edx
0x564cf1  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
0x564cf8  895de4                            mov    DWORD PTR [ebp-0x1c],ebx
0x564cfb  885dd4                            mov    BYTE PTR [ebp-0x2c],bl
0x564cfe  8d7001                            lea    esi,[eax+0x1]
0x564d01  8a08                              mov    cl,BYTE PTR [eax]
0x564d03  40                                inc    eax
0x564d04  3acb                              cmp    cl,bl
0x564d06  75f9                              jne    0x564d01
0x564d08  2bc6                              sub    eax,esi
0x564d0a  52                                push   edx
0x564d0b  8d4dd4                            lea    ecx,[ebp-0x2c]
0x564d0e  e8fd65eaff                        call   0x40b310
0x564d13  b801000000                        mov    eax,0x1
0x564d18  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x564d1b  8405d4b0fa00                      test   BYTE PTR ds:0xfab0d4,al
0x564d21  751e                              jne    0x564d41
0x564d23  0905d4b0fa00                      or     DWORD PTR ds:0xfab0d4,eax
0x564d29  8845fc                            mov    BYTE PTR [ebp-0x4],al
0x564d2c  e86f562a00                        call   0x80a3a0
0x564d31  68d0cdbc00                        push   0xbccdd0
0x564d36  e8dfd53200                        call   0x89231a
0x564d3b  83c404                            add    esp,0x4
0x564d3e  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x564d41  6828b0fa00                        push   0xfab028
0x564d46  8d4dd4                            lea    ecx,[ebp-0x2c]
0x564d49  e8b25d2a00                        call   0x80ab00
0x564d4e  3bc3                              cmp    eax,ebx
0x564d50  7409                              je     0x564d5b
0x564d52  8b10                              mov    edx,DWORD PTR [eax]
0x564d54  8bc8                              mov    ecx,eax
0x564d56  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x564d59  ffd0                              call   eax
0x564d5b  837de810                          cmp    DWORD PTR [ebp-0x18],0x10
0x564d5f  720c                              jb     0x564d6d
0x564d61  8b4dd4                            mov    ecx,DWORD PTR [ebp-0x2c]
0x564d64  51                                push   ecx
0x564d65  e8a2c43200                        call   0x89120c
0x564d6a  83c404                            add    esp,0x4
0x564d6d  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x564d70  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x564d77  59                                pop    ecx
0x564d78  5e                                pop    esi
0x564d79  5b                                pop    ebx
0x564d7a  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x564d7d  33cd                              xor    ecx,ebp
0x564d7f  e87dc23200                        call   0x891001
0x564d84  8be5                              mov    esp,ebp
0x564d86  5d                                pop    ebp
0x564d87  c20400                            ret    0x4

; S02 Q PlayTalkSound then assign Voice/default fallback group to channel resource
; VA 0x564d90..0x564f2e raw 0x164190 length 414 SHA256 c8336c5c099faf4ac7da550b52f9c694bc53e8c371454cce4288bd147fbee27e
0x564d90  55                                push   ebp
0x564d91  8bec                              mov    ebp,esp
0x564d93  6aff                              push   0xffffffff
0x564d95  680cff9100                        push   0x91ff0c
0x564d9a  64a100000000                      mov    eax,fs:0x0
0x564da0  50                                push   eax
0x564da1  83ec44                            sub    esp,0x44
0x564da4  a1201fd600                        mov    eax,ds:0xd61f20
0x564da9  33c5                              xor    eax,ebp
0x564dab  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x564dae  53                                push   ebx
0x564daf  56                                push   esi
0x564db0  50                                push   eax
0x564db1  8d45f4                            lea    eax,[ebp-0xc]
0x564db4  64a300000000                      mov    fs:0x0,eax
0x564dba  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x564dbd  33db                              xor    ebx,ebx
0x564dbf  8bc6                              mov    eax,esi
0x564dc1  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
0x564dc8  895de4                            mov    DWORD PTR [ebp-0x1c],ebx
0x564dcb  885dd4                            mov    BYTE PTR [ebp-0x2c],bl
0x564dce  8d5001                            lea    edx,[eax+0x1]
0x564dd1  8a08                              mov    cl,BYTE PTR [eax]
0x564dd3  40                                inc    eax
0x564dd4  3acb                              cmp    cl,bl
0x564dd6  75f9                              jne    0x564dd1
0x564dd8  2bc2                              sub    eax,edx
0x564dda  56                                push   esi
0x564ddb  8d4dd4                            lea    ecx,[ebp-0x2c]
0x564dde  e82d65eaff                        call   0x40b310
0x564de3  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x564de6  f605d4b0fa0001                    test   BYTE PTR ds:0xfab0d4,0x1
0x564ded  7520                              jne    0x564e0f
0x564def  830dd4b0fa0001                    or     DWORD PTR ds:0xfab0d4,0x1
0x564df6  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x564dfa  e8a1552a00                        call   0x80a3a0
0x564dff  68d0cdbc00                        push   0xbccdd0
0x564e04  e811d53200                        call   0x89231a
0x564e09  83c404                            add    esp,0x4
0x564e0c  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x564e0f  6828b0fa00                        push   0xfab028
0x564e14  8d4dd4                            lea    ecx,[ebp-0x2c]
0x564e17  e8e45c2a00                        call   0x80ab00
0x564e1c  3bc3                              cmp    eax,ebx
0x564e1e  740d                              je     0x564e2d
0x564e20  8b10                              mov    edx,DWORD PTR [eax]
0x564e22  8bc8                              mov    ecx,eax
0x564e24  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x564e27  ffd0                              call   eax
0x564e29  8bf0                              mov    esi,eax
0x564e2b  eb02                              jmp    0x564e2f
0x564e2d  33f6                              xor    esi,esi
0x564e2f  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x564e36  837de810                          cmp    DWORD PTR [ebp-0x18],0x10
0x564e3a  720c                              jb     0x564e48
0x564e3c  8b4dd4                            mov    ecx,DWORD PTR [ebp-0x2c]
0x564e3f  51                                push   ecx
0x564e40  e8c7c33200                        call   0x89120c
0x564e45  83c404                            add    esp,0x4
0x564e48  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
0x564e4f  895de4                            mov    DWORD PTR [ebp-0x1c],ebx
0x564e52  885dd4                            mov    BYTE PTR [ebp-0x2c],bl
0x564e55  3bf3                              cmp    esi,ebx
0x564e57  0f84b4000000                      je     0x564f11
0x564e5d  680458c000                        push   0xc05804
0x564e62  b805000000                        mov    eax,0x5
0x564e67  8d4db8                            lea    ecx,[ebp-0x48]
0x564e6a  c745cc0f000000                    mov    DWORD PTR [ebp-0x34],0xf
0x564e71  895dc8                            mov    DWORD PTR [ebp-0x38],ebx
0x564e74  885db8                            mov    BYTE PTR [ebp-0x48],bl
0x564e77  e89464eaff                        call   0x40b310
0x564e7c  bb02000000                        mov    ebx,0x2
0x564e81  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x564e84  f605d4b0fa0001                    test   BYTE PTR ds:0xfab0d4,0x1
0x564e8b  7520                              jne    0x564ead
0x564e8d  830dd4b0fa0001                    or     DWORD PTR ds:0xfab0d4,0x1
0x564e94  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0x564e98  e803552a00                        call   0x80a3a0
0x564e9d  68d0cdbc00                        push   0xbccdd0
0x564ea2  e873d43200                        call   0x89231a
0x564ea7  83c404                            add    esp,0x4
0x564eaa  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x564ead  8d55b8                            lea    edx,[ebp-0x48]
0x564eb0  52                                push   edx
0x564eb1  b850b0fa00                        mov    eax,0xfab050
0x564eb6  e805732a00                        call   0x80c1c0
0x564ebb  8945b0                            mov    DWORD PTR [ebp-0x50],eax
0x564ebe  3b0554b0fa00                      cmp    eax,DWORD PTR ds:0xfab054
0x564ec4  7414                              je     0x564eda
0x564ec6  83c00c                            add    eax,0xc
0x564ec9  8d4db8                            lea    ecx,[ebp-0x48]
0x564ecc  e8cfe7fdff                        call   0x5436a0
0x564ed1  84c0                              test   al,al
0x564ed3  7505                              jne    0x564eda
0x564ed5  8d45b0                            lea    eax,[ebp-0x50]
0x564ed8  eb0b                              jmp    0x564ee5
0x564eda  a154b0fa00                        mov    eax,ds:0xfab054
0x564edf  8945b4                            mov    DWORD PTR [ebp-0x4c],eax
0x564ee2  8d45b4                            lea    eax,[ebp-0x4c]
0x564ee5  8b00                              mov    eax,DWORD PTR [eax]
0x564ee7  3b0554b0fa00                      cmp    eax,DWORD PTR ds:0xfab054
0x564eed  7405                              je     0x564ef4
0x564eef  8b4028                            mov    eax,DWORD PTR [eax+0x28]
0x564ef2  eb05                              jmp    0x564ef9
0x564ef4  a14cb0fa00                        mov    eax,ds:0xfab04c
0x564ef9  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
0x564efc  894108                            mov    DWORD PTR [ecx+0x8],eax
0x564eff  837dcc10                          cmp    DWORD PTR [ebp-0x34],0x10
0x564f03  720c                              jb     0x564f11
0x564f05  8b55b8                            mov    edx,DWORD PTR [ebp-0x48]
0x564f08  52                                push   edx
0x564f09  e8fec23200                        call   0x89120c
0x564f0e  83c404                            add    esp,0x4
0x564f11  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x564f14  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x564f1b  59                                pop    ecx
0x564f1c  5e                                pop    esi
0x564f1d  5b                                pop    ebx
0x564f1e  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x564f21  33cd                              xor    ecx,ebp
0x564f23  e8d9c03200                        call   0x891001
0x564f28  8be5                              mov    esp,ebp
0x564f2a  5d                                pop    ebp
0x564f2b  c20400                            ret    0x4

; S03 SoundManager lookup/normalization/load queue
; VA 0x80ab00..0x80ae16 raw 0x409f00 length 790 SHA256 b71189c9112a87581fb05f3eb82e1bfe9c75c1b248312ddf4531ea5bce9e96f6
0x80ab00  55                                push   ebp
0x80ab01  8bec                              mov    ebp,esp
0x80ab03  83e4f8                            and    esp,0xfffffff8
0x80ab06  6aff                              push   0xffffffff
0x80ab08  684bc49100                        push   0x91c44b
0x80ab0d  64a100000000                      mov    eax,fs:0x0
0x80ab13  50                                push   eax
0x80ab14  83ec50                            sub    esp,0x50
0x80ab17  a1201fd600                        mov    eax,ds:0xd61f20
0x80ab1c  33c4                              xor    eax,esp
0x80ab1e  89442448                          mov    DWORD PTR [esp+0x48],eax
0x80ab22  53                                push   ebx
0x80ab23  56                                push   esi
0x80ab24  57                                push   edi
0x80ab25  a1201fd600                        mov    eax,ds:0xd61f20
0x80ab2a  33c4                              xor    eax,esp
0x80ab2c  50                                push   eax
0x80ab2d  8d442460                          lea    eax,[esp+0x60]
0x80ab31  64a300000000                      mov    fs:0x0,eax
0x80ab37  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x80ab3a  8bf9                              mov    edi,ecx
0x80ab3c  68e817c500                        push   0xc517e8
0x80ab41  8bd7                              mov    edx,edi
0x80ab43  895c2418                          mov    DWORD PTR [esp+0x18],ebx
0x80ab47  897c2414                          mov    DWORD PTR [esp+0x14],edi
0x80ab4b  e8702fedff                        call   0x6ddac0
0x80ab50  85c0                              test   eax,eax
0x80ab52  0f849e020000                      je     0x80adf6
0x80ab58  837f1410                          cmp    DWORD PTR [edi+0x14],0x10
0x80ab5c  7204                              jb     0x80ab62
0x80ab5e  8b07                              mov    eax,DWORD PTR [edi]
0x80ab60  eb02                              jmp    0x80ab64
0x80ab62  8bc7                              mov    eax,edi
0x80ab64  50                                push   eax
0x80ab65  68f017c500                        push   0xc517f0
0x80ab6a  6a05                              push   0x5
0x80ab6c  e83f2feeff                        call   0x6edab0
0x80ab71  83c40c                            add    esp,0xc
0x80ab74  33f6                              xor    esi,esi
0x80ab76  56                                push   esi
0x80ab77  57                                push   edi
0x80ab78  83c9ff                            or     ecx,0xffffffff
0x80ab7b  8d7c2424                          lea    edi,[esp+0x24]
0x80ab7f  c74424380f000000                  mov    DWORD PTR [esp+0x38],0xf
0x80ab87  89742434                          mov    DWORD PTR [esp+0x34],esi
0x80ab8b  c644242400                        mov    BYTE PTR [esp+0x24],0x0
0x80ab90  e81b05c0ff                        call   0x40b0b0
0x80ab95  89742468                          mov    DWORD PTR [esp+0x68],esi
0x80ab99  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
0x80ab9d  33c0                              xor    eax,eax
0x80ab9f  3974242c                          cmp    DWORD PTR [esp+0x2c],esi
0x80aba3  8b742430                          mov    esi,DWORD PTR [esp+0x30]
0x80aba7  7634                              jbe    0x80abdd
0x80aba9  8da42400000000                    lea    esp,[esp+0x0]
0x80abb0  8bd1                              mov    edx,ecx
0x80abb2  83fe10                            cmp    esi,0x10
0x80abb5  7304                              jae    0x80abbb
0x80abb7  8d54241c                          lea    edx,[esp+0x1c]
0x80abbb  803c025c                          cmp    BYTE PTR [edx+eax*1],0x5c
0x80abbf  7515                              jne    0x80abd6
0x80abc1  83fe10                            cmp    esi,0x10
0x80abc4  7304                              jae    0x80abca
0x80abc6  8d4c241c                          lea    ecx,[esp+0x1c]
0x80abca  c604012f                          mov    BYTE PTR [ecx+eax*1],0x2f
0x80abce  8b742430                          mov    esi,DWORD PTR [esp+0x30]
0x80abd2  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
0x80abd6  40                                inc    eax
0x80abd7  3b44242c                          cmp    eax,DWORD PTR [esp+0x2c]
0x80abdb  72d3                              jb     0x80abb0
0x80abdd  8b5314                            mov    edx,DWORD PTR [ebx+0x14]
0x80abe0  8d4304                            lea    eax,[ebx+0x4]
0x80abe3  bf10000000                        mov    edi,0x10
0x80abe8  397814                            cmp    DWORD PTR [eax+0x14],edi
0x80abeb  7202                              jb     0x80abef
0x80abed  8b00                              mov    eax,DWORD PTR [eax]
0x80abef  3bf7                              cmp    esi,edi
0x80abf1  7304                              jae    0x80abf7
0x80abf3  8d4c241c                          lea    ecx,[esp+0x1c]
0x80abf7  52                                push   edx
0x80abf8  50                                push   eax
0x80abf9  51                                push   ecx
0x80abfa  e883bc0800                        call   0x896882
0x80abff  83c40c                            add    esp,0xc
0x80ac02  85c0                              test   eax,eax
0x80ac04  756f                              jne    0x80ac75
0x80ac06  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
0x80ac0a  397c2430                          cmp    DWORD PTR [esp+0x30],edi
0x80ac0e  7304                              jae    0x80ac14
0x80ac10  8d4c241c                          lea    ecx,[esp+0x1c]
0x80ac14  034b14                            add    ecx,DWORD PTR [ebx+0x14]
0x80ac17  c744244c0f000000                  mov    DWORD PTR [esp+0x4c],0xf
0x80ac1f  8bc1                              mov    eax,ecx
0x80ac21  c744244800000000                  mov    DWORD PTR [esp+0x48],0x0
0x80ac29  c644243800                        mov    BYTE PTR [esp+0x38],0x0
0x80ac2e  8d7001                            lea    esi,[eax+0x1]
0x80ac31  8a10                              mov    dl,BYTE PTR [eax]
0x80ac33  40                                inc    eax
0x80ac34  84d2                              test   dl,dl
0x80ac36  75f9                              jne    0x80ac31
0x80ac38  51                                push   ecx
0x80ac39  2bc6                              sub    eax,esi
0x80ac3b  8d4c243c                          lea    ecx,[esp+0x3c]
0x80ac3f  e8cc06c0ff                        call   0x40b310
0x80ac44  6a00                              push   0x0
0x80ac46  8d44243c                          lea    eax,[esp+0x3c]
0x80ac4a  50                                push   eax
0x80ac4b  83c9ff                            or     ecx,0xffffffff
0x80ac4e  8d7c2424                          lea    edi,[esp+0x24]
0x80ac52  c644247001                        mov    BYTE PTR [esp+0x70],0x1
0x80ac57  e85404c0ff                        call   0x40b0b0
0x80ac5c  c644246800                        mov    BYTE PTR [esp+0x68],0x0
0x80ac61  837c244c10                        cmp    DWORD PTR [esp+0x4c],0x10
0x80ac66  720d                              jb     0x80ac75
0x80ac68  8b4c2438                          mov    ecx,DWORD PTR [esp+0x38]
0x80ac6c  51                                push   ecx
0x80ac6d  e89a650800                        call   0x89120c
0x80ac72  83c404                            add    esp,0x4
0x80ac75  8b542410                          mov    edx,DWORD PTR [esp+0x10]
0x80ac79  52                                push   edx
0x80ac7a  53                                push   ebx
0x80ac7b  e830fcffff                        call   0x80a8b0
0x80ac80  8bf0                              mov    esi,eax
0x80ac82  85f6                              test   esi,esi
0x80ac84  7515                              jne    0x80ac9b
0x80ac86  8d44241c                          lea    eax,[esp+0x1c]
0x80ac8a  50                                push   eax
0x80ac8b  53                                push   ebx
0x80ac8c  e81ffcffff                        call   0x80a8b0
0x80ac91  8bf0                              mov    esi,eax
0x80ac93  85f6                              test   esi,esi
0x80ac95  0f84ad000000                      je     0x80ad48
0x80ac9b  837e0c00                          cmp    DWORD PTR [esi+0xc],0x0
0x80ac9f  0f8588000000                      jne    0x80ad2d
0x80aca5  8bfe                              mov    edi,esi
0x80aca7  e8b42a0000                        call   0x80d760
0x80acac  8d4618                            lea    eax,[esi+0x18]
0x80acaf  6a00                              push   0x0
0x80acb1  50                                push   eax
0x80acb2  83c9ff                            or     ecx,0xffffffff
0x80acb5  8d7c2440                          lea    edi,[esp+0x40]
0x80acb9  c74424540f000000                  mov    DWORD PTR [esp+0x54],0xf
0x80acc1  c744245000000000                  mov    DWORD PTR [esp+0x50],0x0
0x80acc9  c644244000                        mov    BYTE PTR [esp+0x40],0x0
0x80acce  e8dd03c0ff                        call   0x40b0b0
0x80acd3  c744245400000000                  mov    DWORD PTR [esp+0x54],0x0
0x80acdb  8d4c2438                          lea    ecx,[esp+0x38]
0x80acdf  8d7b48                            lea    edi,[ebx+0x48]
0x80ace2  51                                push   ecx
0x80ace3  8bcf                              mov    ecx,edi
0x80ace5  c644246c02                        mov    BYTE PTR [esp+0x6c],0x2
0x80acea  e8d188d3ff                        call   0x5435c0
0x80acef  50                                push   eax
0x80acf0  8d542418                          lea    edx,[esp+0x18]
0x80acf4  52                                push   edx
0x80acf5  57                                push   edi
0x80acf6  e865180000                        call   0x80c560
0x80acfb  bf10000000                        mov    edi,0x10
0x80ad00  397c244c                          cmp    DWORD PTR [esp+0x4c],edi
0x80ad04  720d                              jb     0x80ad13
0x80ad06  8b442438                          mov    eax,DWORD PTR [esp+0x38]
0x80ad0a  50                                push   eax
0x80ad0b  e8fc640800                        call   0x89120c
0x80ad10  83c404                            add    esp,0x4
0x80ad13  397c2430                          cmp    DWORD PTR [esp+0x30],edi
0x80ad17  720d                              jb     0x80ad26
0x80ad19  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
0x80ad1d  51                                push   ecx
0x80ad1e  e8e9640800                        call   0x89120c
0x80ad23  83c404                            add    esp,0x4
0x80ad26  8bc6                              mov    eax,esi
0x80ad28  e9c9000000                        jmp    0x80adf6
0x80ad2d  837c243010                        cmp    DWORD PTR [esp+0x30],0x10
0x80ad32  72f2                              jb     0x80ad26
0x80ad34  8b54241c                          mov    edx,DWORD PTR [esp+0x1c]
0x80ad38  52                                push   edx
0x80ad39  e8ce640800                        call   0x89120c
0x80ad3e  83c404                            add    esp,0x4
0x80ad41  8bc6                              mov    eax,esi
0x80ad43  e9ae000000                        jmp    0x80adf6
0x80ad48  6a5c                              push   0x5c
0x80ad4a  e819650800                        call   0x891268
0x80ad4f  83c404                            add    esp,0x4
0x80ad52  89442410                          mov    DWORD PTR [esp+0x10],eax
0x80ad56  c644246803                        mov    BYTE PTR [esp+0x68],0x3
0x80ad5b  85c0                              test   eax,eax
0x80ad5d  740e                              je     0x80ad6d
0x80ad5f  50                                push   eax
0x80ad60  8d7c2420                          lea    edi,[esp+0x20]
0x80ad64  e8772e0000                        call   0x80dbe0
0x80ad69  8bd8                              mov    ebx,eax
0x80ad6b  eb02                              jmp    0x80ad6f
0x80ad6d  33db                              xor    ebx,ebx
0x80ad6f  8bfb                              mov    edi,ebx
0x80ad71  c644246800                        mov    BYTE PTR [esp+0x68],0x0
0x80ad76  e8e5290000                        call   0x80d760
0x80ad7b  6a00                              push   0x0
0x80ad7d  8d442420                          lea    eax,[esp+0x20]
0x80ad81  50                                push   eax
0x80ad82  83c9ff                            or     ecx,0xffffffff
0x80ad85  8d7c2440                          lea    edi,[esp+0x40]
0x80ad89  c74424540f000000                  mov    DWORD PTR [esp+0x54],0xf
0x80ad91  c744245000000000                  mov    DWORD PTR [esp+0x50],0x0
0x80ad99  c644244000                        mov    BYTE PTR [esp+0x40],0x0
0x80ad9e  e80d03c0ff                        call   0x40b0b0
0x80ada3  895c2454                          mov    DWORD PTR [esp+0x54],ebx
0x80ada7  c644246804                        mov    BYTE PTR [esp+0x68],0x4
0x80adac  8b742414                          mov    esi,DWORD PTR [esp+0x14]
0x80adb0  8bcf                              mov    ecx,edi
0x80adb2  83c638                            add    esi,0x38
0x80adb5  51                                push   ecx
0x80adb6  8bce                              mov    ecx,esi
0x80adb8  e80388d3ff                        call   0x5435c0
0x80adbd  50                                push   eax
0x80adbe  8d542418                          lea    edx,[esp+0x18]
0x80adc2  52                                push   edx
0x80adc3  56                                push   esi
0x80adc4  e8b79dd6ff                        call   0x574b80
0x80adc9  be10000000                        mov    esi,0x10
0x80adce  3974244c                          cmp    DWORD PTR [esp+0x4c],esi
0x80add2  720d                              jb     0x80ade1
0x80add4  8b442438                          mov    eax,DWORD PTR [esp+0x38]
0x80add8  50                                push   eax
0x80add9  e82e640800                        call   0x89120c
0x80adde  83c404                            add    esp,0x4
0x80ade1  39742430                          cmp    DWORD PTR [esp+0x30],esi
0x80ade5  720d                              jb     0x80adf4
0x80ade7  8b4c241c                          mov    ecx,DWORD PTR [esp+0x1c]
0x80adeb  51                                push   ecx
0x80adec  e81b640800                        call   0x89120c
0x80adf1  83c404                            add    esp,0x4
0x80adf4  8bc3                              mov    eax,ebx
0x80adf6  8b4c2460                          mov    ecx,DWORD PTR [esp+0x60]
0x80adfa  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80ae01  59                                pop    ecx
0x80ae02  5f                                pop    edi
0x80ae03  5e                                pop    esi
0x80ae04  5b                                pop    ebx
0x80ae05  8b4c2448                          mov    ecx,DWORD PTR [esp+0x48]
0x80ae09  33cc                              xor    ecx,esp
0x80ae0b  e8f1610800                        call   0x891001
0x80ae10  8be5                              mov    esp,ebp
0x80ae12  5d                                pop    ebp
0x80ae13  c20400                            ret    0x4

; S04 Concrete SoundFile ctor and vtables
; VA 0x80dbe0..0x80dcc5 raw 0x40cfe0 length 229 SHA256 08aa1db4f76570c6f5883f3412635bdc556dddae2f9efe649708c3b26b776aa4
0x80dbe0  55                                push   ebp
0x80dbe1  8bec                              mov    ebp,esp
0x80dbe3  6aff                              push   0xffffffff
0x80dbe5  68e6849100                        push   0x9184e6
0x80dbea  64a100000000                      mov    eax,fs:0x0
0x80dbf0  50                                push   eax
0x80dbf1  83ec24                            sub    esp,0x24
0x80dbf4  a1201fd600                        mov    eax,ds:0xd61f20
0x80dbf9  33c5                              xor    eax,ebp
0x80dbfb  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x80dbfe  53                                push   ebx
0x80dbff  56                                push   esi
0x80dc00  50                                push   eax
0x80dc01  8d45f4                            lea    eax,[ebp-0xc]
0x80dc04  64a300000000                      mov    fs:0x0,eax
0x80dc0a  837f1410                          cmp    DWORD PTR [edi+0x14],0x10
0x80dc0e  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x80dc11  8945d0                            mov    DWORD PTR [ebp-0x30],eax
0x80dc14  7204                              jb     0x80dc1a
0x80dc16  8b17                              mov    edx,DWORD PTR [edi]
0x80dc18  eb02                              jmp    0x80dc1c
0x80dc1a  8bd7                              mov    edx,edi
0x80dc1c  33db                              xor    ebx,ebx
0x80dc1e  8bc2                              mov    eax,edx
0x80dc20  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
0x80dc27  895de4                            mov    DWORD PTR [ebp-0x1c],ebx
0x80dc2a  885dd4                            mov    BYTE PTR [ebp-0x2c],bl
0x80dc2d  8d7001                            lea    esi,[eax+0x1]
0x80dc30  8a08                              mov    cl,BYTE PTR [eax]
0x80dc32  40                                inc    eax
0x80dc33  3acb                              cmp    cl,bl
0x80dc35  75f9                              jne    0x80dc30
0x80dc37  2bc6                              sub    eax,esi
0x80dc39  50                                push   eax
0x80dc3a  52                                push   edx
0x80dc3b  8d4dd4                            lea    ecx,[ebp-0x2c]
0x80dc3e  e82d4ebfff                        call   0x402a70
0x80dc43  b801000000                        mov    eax,0x1
0x80dc48  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x80dc4b  8405d4b0fa00                      test   BYTE PTR ds:0xfab0d4,al
0x80dc51  751e                              jne    0x80dc71
0x80dc53  0905d4b0fa00                      or     DWORD PTR ds:0xfab0d4,eax
0x80dc59  8845fc                            mov    BYTE PTR [ebp-0x4],al
0x80dc5c  e83fc7ffff                        call   0x80a3a0
0x80dc61  68d0cdbc00                        push   0xbccdd0
0x80dc66  e8af460800                        call   0x89231a
0x80dc6b  83c404                            add    esp,0x4
0x80dc6e  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x80dc71  8b0d48b0fa00                      mov    ecx,DWORD PTR ds:0xfab048
0x80dc77  8b75d0                            mov    esi,DWORD PTR [ebp-0x30]
0x80dc7a  51                                push   ecx
0x80dc7b  8d55d4                            lea    edx,[ebp-0x2c]
0x80dc7e  52                                push   edx
0x80dc7f  56                                push   esi
0x80dc80  8bcf                              mov    ecx,edi
0x80dc82  e859fcffff                        call   0x80d8e0
0x80dc87  837de810                          cmp    DWORD PTR [ebp-0x18],0x10
0x80dc8b  720c                              jb     0x80dc99
0x80dc8d  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
0x80dc90  50                                push   eax
0x80dc91  e876350800                        call   0x89120c
0x80dc96  83c404                            add    esp,0x4
0x80dc99  c706201bc500                      mov    DWORD PTR [esi],0xc51b20
0x80dc9f  c74604481bc500                    mov    DWORD PTR [esi+0x4],0xc51b48
0x80dca6  8bc6                              mov    eax,esi
0x80dca8  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80dcab  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80dcb2  59                                pop    ecx
0x80dcb3  5e                                pop    esi
0x80dcb4  5b                                pop    ebx
0x80dcb5  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x80dcb8  33cd                              xor    ecx,ebp
0x80dcba  e842330800                        call   0x891001
0x80dcbf  8be5                              mov    esp,ebp
0x80dcc1  5d                                pop    ebp
0x80dcc2  c20400                            ret    0x4

; S05 SoundFile Play uses zero position and fixed flag1
; VA 0x80d550..0x80d585 raw 0x40c950 length 53 SHA256 7b1926ec6ecbce2efcce11ae335c808ef19411a2736355168a80cdc42467b9e2
0x80d550  b801000000                        mov    eax,0x1
0x80d555  8405d437fe00                      test   BYTE PTR ds:0xfe37d4,al
0x80d55b  751a                              jne    0x80d577
0x80d55d  d9ee                              fldz
0x80d55f  0905d437fe00                      or     DWORD PTR ds:0xfe37d4,eax
0x80d565  d915c837fe00                      fst    DWORD PTR ds:0xfe37c8
0x80d56b  d915cc37fe00                      fst    DWORD PTR ds:0xfe37cc
0x80d571  d91dd037fe00                      fstp   DWORD PTR ds:0xfe37d0
0x80d577  8b11                              mov    edx,DWORD PTR [ecx]
0x80d579  50                                push   eax
0x80d57a  8b4210                            mov    eax,DWORD PTR [edx+0x10]
0x80d57d  68c837fe00                        push   0xfe37c8
0x80d582  ffd0                              call   eax
0x80d584  c3                                ret

; S06 Allocate SoundChannel and enqueue native play message
; VA 0x80d590..0x80d75a raw 0x40c990 length 458 SHA256 2b1447a51442e13630a9f3b04473bcd8e70bb143e5470356cb02b6f072e34ab7
0x80d590  55                                push   ebp
0x80d591  8bec                              mov    ebp,esp
0x80d593  6aff                              push   0xffffffff
0x80d595  688a859100                        push   0x91858a
0x80d59a  64a100000000                      mov    eax,fs:0x0
0x80d5a0  50                                push   eax
0x80d5a1  83ec24                            sub    esp,0x24
0x80d5a4  53                                push   ebx
0x80d5a5  56                                push   esi
0x80d5a6  57                                push   edi
0x80d5a7  a1201fd600                        mov    eax,ds:0xd61f20
0x80d5ac  33c5                              xor    eax,ebp
0x80d5ae  50                                push   eax
0x80d5af  8d45f4                            lea    eax,[ebp-0xc]
0x80d5b2  64a300000000                      mov    fs:0x0,eax
0x80d5b8  8bd9                              mov    ebx,ecx
0x80d5ba  895df0                            mov    DWORD PTR [ebp-0x10],ebx
0x80d5bd  f605d4b0fa0001                    test   BYTE PTR ds:0xfab0d4,0x1
0x80d5c4  7520                              jne    0x80d5e6
0x80d5c6  830dd4b0fa0001                    or     DWORD PTR ds:0xfab0d4,0x1
0x80d5cd  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x80d5d4  e8c7cdffff                        call   0x80a3a0
0x80d5d9  68d0cdbc00                        push   0xbccdd0
0x80d5de  e8374d0800                        call   0x89231a
0x80d5e3  83c404                            add    esp,0x4
0x80d5e6  689cb0fa00                        push   0xfab09c
0x80d5eb  c745ec9cb0fa00                    mov    DWORD PTR [ebp-0x14],0xfab09c
0x80d5f2  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x80d5f8  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x80d5ff  8b0d28b0fa00                      mov    ecx,DWORD PTR ds:0xfab028
0x80d605  85c9                              test   ecx,ecx
0x80d607  7521                              jne    0x80d62a
0x80d609  689cb0fa00                        push   0xfab09c
0x80d60e  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80d614  33c0                              xor    eax,eax
0x80d616  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80d619  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80d620  59                                pop    ecx
0x80d621  5f                                pop    edi
0x80d622  5e                                pop    esi
0x80d623  5b                                pop    ebx
0x80d624  8be5                              mov    esp,ebp
0x80d626  5d                                pop    ebp
0x80d627  c20800                            ret    0x8
0x80d62a  8b01                              mov    eax,DWORD PTR [ecx]
0x80d62c  8b501c                            mov    edx,DWORD PTR [eax+0x1c]
0x80d62f  ffd2                              call   edx
0x80d631  83cfff                            or     edi,0xffffffff
0x80d634  689cb0fa00                        push   0xfab09c
0x80d639  8bf0                              mov    esi,eax
0x80d63b  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x80d63e  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80d644  85f6                              test   esi,esi
0x80d646  74cc                              je     0x80d614
0x80d648  f6051434fe0001                    test   BYTE PTR ds:0xfe3414,0x1
0x80d64f  7523                              jne    0x80d674
0x80d651  830d1434fe0001                    or     DWORD PTR ds:0xfe3414,0x1
0x80d658  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x80d65f  e8bc1e0000                        call   0x80f520
0x80d664  68400cbd00                        push   0xbd0c40
0x80d669  e8ac4c0800                        call   0x89231a
0x80d66e  83c404                            add    esp,0x4
0x80d671  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x80d674  833d2c34fe0000                    cmp    DWORD PTR ds:0xfe342c,0x0
0x80d67b  7412                              je     0x80d68f
0x80d67d  8d4318                            lea    eax,[ebx+0x18]
0x80d680  50                                push   eax
0x80d681  8d4de8                            lea    ecx,[ebp-0x18]
0x80d684  51                                push   ecx
0x80d685  681c34fe00                        push   0xfe341c
0x80d68a  e8211f0000                        call   0x80f5b0
0x80d68f  8b16                              mov    edx,DWORD PTR [esi]
0x80d691  8b433c                            mov    eax,DWORD PTR [ebx+0x3c]
0x80d694  8b5214                            mov    edx,DWORD PTR [edx+0x14]
0x80d697  50                                push   eax
0x80d698  8bce                              mov    ecx,esi
0x80d69a  ffd2                              call   edx
0x80d69c  f605d4b0fa0001                    test   BYTE PTR ds:0xfab0d4,0x1
0x80d6a3  7523                              jne    0x80d6c8
0x80d6a5  830dd4b0fa0001                    or     DWORD PTR ds:0xfab0d4,0x1
0x80d6ac  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
0x80d6b3  e8e8ccffff                        call   0x80a3a0
0x80d6b8  68d0cdbc00                        push   0xbccdd0
0x80d6bd  e8584c0800                        call   0x89231a
0x80d6c2  83c404                            add    esp,0x4
0x80d6c5  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x80d6c8  56                                push   esi
0x80d6c9  53                                push   ebx
0x80d6ca  bf28b0fa00                        mov    edi,0xfab028
0x80d6cf  e88ce7ffff                        call   0x80be60
0x80d6d4  8bd8                              mov    ebx,eax
0x80d6d6  85db                              test   ebx,ebx
0x80d6d8  746a                              je     0x80d744
0x80d6da  8d4324                            lea    eax,[ebx+0x24]
0x80d6dd  50                                push   eax
0x80d6de  ff158422bd00                      call   DWORD PTR ds:0xbd2284
0x80d6e4  8b16                              mov    edx,DWORD PTR [esi]
0x80d6e6  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x80d6e9  8bce                              mov    ecx,esi
0x80d6eb  ffd0                              call   eax
0x80d6ed  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x80d6f0  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x80d6f3  8b7d0c                            mov    edi,DWORD PTR [ebp+0xc]
0x80d6f6  c7413458020000                    mov    DWORD PTR [ecx+0x34],0x258
0x80d6fd  8b10                              mov    edx,DWORD PTR [eax]
0x80d6ff  8b7004                            mov    esi,DWORD PTR [eax+0x4]
0x80d702  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x80d705  33c9                              xor    ecx,ecx
0x80d707  894dd0                            mov    DWORD PTR [ebp-0x30],ecx
0x80d70a  895dd4                            mov    DWORD PTR [ebp-0x2c],ebx
0x80d70d  8955d8                            mov    DWORD PTR [ebp-0x28],edx
0x80d710  8975dc                            mov    DWORD PTR [ebp-0x24],esi
0x80d713  8945e0                            mov    DWORD PTR [ebp-0x20],eax
0x80d716  897de4                            mov    DWORD PTR [ebp-0x1c],edi
0x80d719  e8c2cbffff                        call   0x80a2e0
0x80d71e  8bf8                              mov    edi,eax
0x80d720  57                                push   edi
0x80d721  897d08                            mov    DWORD PTR [ebp+0x8],edi
0x80d724  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x80d72a  8d55d0                            lea    edx,[ebp-0x30]
0x80d72d  52                                push   edx
0x80d72e  8d7718                            lea    esi,[edi+0x18]
0x80d731  c745fc04000000                    mov    DWORD PTR [ebp-0x4],0x4
0x80d738  e873f6ffff                        call   0x80cdb0
0x80d73d  57                                push   edi
0x80d73e  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80d744  8bc3                              mov    eax,ebx
0x80d746  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80d749  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80d750  59                                pop    ecx
0x80d751  5f                                pop    edi
0x80d752  5e                                pop    esi
0x80d753  5b                                pop    ebx
0x80d754  8be5                              mov    esp,ebp
0x80d756  5d                                pop    ebp
0x80d757  c20800                            ret    0x8

; S07 Queue native sound resource load
; VA 0x80d760..0x80d866 raw 0x40cb60 length 262 SHA256 ce3732d60e4cf6ac214bb0c6c26d13c2269180ae61e273aa6c2e4671445f0eef
0x80d760  55                                push   ebp
0x80d761  8bec                              mov    ebp,esp
0x80d763  6aff                              push   0xffffffff
0x80d765  6834859100                        push   0x918534
0x80d76a  64a100000000                      mov    eax,fs:0x0
0x80d770  50                                push   eax
0x80d771  83ec1c                            sub    esp,0x1c
0x80d774  56                                push   esi
0x80d775  a1201fd600                        mov    eax,ds:0xd61f20
0x80d77a  33c5                              xor    eax,ebp
0x80d77c  50                                push   eax
0x80d77d  8d45f4                            lea    eax,[ebp-0xc]
0x80d780  64a300000000                      mov    fs:0x0,eax
0x80d786  837f3c00                          cmp    DWORD PTR [edi+0x3c],0x0
0x80d78a  7545                              jne    0x80d7d1
0x80d78c  f605d4b0fa0001                    test   BYTE PTR ds:0xfab0d4,0x1
0x80d793  7527                              jne    0x80d7bc
0x80d795  830dd4b0fa0001                    or     DWORD PTR ds:0xfab0d4,0x1
0x80d79c  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x80d7a3  e8f8cbffff                        call   0x80a3a0
0x80d7a8  68d0cdbc00                        push   0xbccdd0
0x80d7ad  e8684b0800                        call   0x89231a
0x80d7b2  83c404                            add    esp,0x4
0x80d7b5  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x80d7bc  b928b0fa00                        mov    ecx,0xfab028
0x80d7c1  e81ae6ffff                        call   0x80bde0
0x80d7c6  89473c                            mov    DWORD PTR [edi+0x3c],eax
0x80d7c9  85c0                              test   eax,eax
0x80d7cb  0f8485000000                      je     0x80d856
0x80d7d1  f605c433fe0001                    test   BYTE PTR ds:0xfe33c4,0x1
0x80d7d8  be01000000                        mov    esi,0x1
0x80d7dd  7527                              jne    0x80d806
0x80d7df  8bc6                              mov    eax,esi
0x80d7e1  0905c433fe00                      or     DWORD PTR ds:0xfe33c4,eax
0x80d7e7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x80d7ea  e841080000                        call   0x80e030
0x80d7ef  68d00bbd00                        push   0xbd0bd0
0x80d7f4  c705f833fe0000000000              mov    DWORD PTR ds:0xfe33f8,0x0
0x80d7fe  e8174b0800                        call   0x89231a
0x80d803  83c404                            add    esp,0x4
0x80d806  8b45e0                            mov    eax,DWORD PTR [ebp-0x20]
0x80d809  8b4de4                            mov    ecx,DWORD PTR [ebp-0x1c]
0x80d80c  8b55e8                            mov    edx,DWORD PTR [ebp-0x18]
0x80d80f  8945e0                            mov    DWORD PTR [ebp-0x20],eax
0x80d812  8b45ec                            mov    eax,DWORD PTR [ebp-0x14]
0x80d815  68c833fe00                        push   0xfe33c8
0x80d81a  8975d8                            mov    DWORD PTR [ebp-0x28],esi
0x80d81d  897ddc                            mov    DWORD PTR [ebp-0x24],edi
0x80d820  894de4                            mov    DWORD PTR [ebp-0x1c],ecx
0x80d823  8955e8                            mov    DWORD PTR [ebp-0x18],edx
0x80d826  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x80d829  c745f0c833fe00                    mov    DWORD PTR [ebp-0x10],0xfe33c8
0x80d830  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x80d836  8d4dd8                            lea    ecx,[ebp-0x28]
0x80d839  51                                push   ecx
0x80d83a  bee033fe00                        mov    esi,0xfe33e0
0x80d83f  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x80d846  e865f5ffff                        call   0x80cdb0
0x80d84b  68c833fe00                        push   0xfe33c8
0x80d850  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80d856  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80d859  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80d860  59                                pop    ecx
0x80d861  5e                                pop    esi
0x80d862  8be5                              mov    esp,ebp
0x80d864  5d                                pop    ebp
0x80d865  c3                                ret

; S08 Resource callback readiness/loading/failed gates then v+4 Load
; VA 0x80d8b0..0x80d8df raw 0x40ccb0 length 47 SHA256 2fe900d47e0e43c19cbbd1687857e03f852ec204ba8d9fb1ffa2d3063bb1b560
0x80d8b0  56                                push   esi
0x80d8b1  8bf1                              mov    esi,ecx
0x80d8b3  837e0800                          cmp    DWORD PTR [esi+0x8],0x0
0x80d8b7  7524                              jne    0x80d8dd
0x80d8b9  837e0c00                          cmp    DWORD PTR [esi+0xc],0x0
0x80d8bd  8d460c                            lea    eax,[esi+0xc]
0x80d8c0  751b                              jne    0x80d8dd
0x80d8c2  837e1000                          cmp    DWORD PTR [esi+0x10],0x0
0x80d8c6  7515                              jne    0x80d8dd
0x80d8c8  6a01                              push   0x1
0x80d8ca  50                                push   eax
0x80d8cb  ff158022bd00                      call   DWORD PTR ds:0xbd2280
0x80d8d1  8b46fc                            mov    eax,DWORD PTR [esi-0x4]
0x80d8d4  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x80d8d7  8d4efc                            lea    ecx,[esi-0x4]
0x80d8da  5e                                pop    esi
0x80d8db  ffe2                              jmp    edx
0x80d8dd  5e                                pop    esi
0x80d8de  c3                                ret

; S09 SoundFile allowed-prefix gate and actual load/failure flags
; VA 0x80dd00..0x80df09 raw 0x40d100 length 521 SHA256 ec56f7f463c1d72f020477143b81425dc892c1692bd88a926cb33c3bc583989c
0x80dd00  55                                push   ebp
0x80dd01  8bec                              mov    ebp,esp
0x80dd03  6aff                              push   0xffffffff
0x80dd05  68f6839200                        push   0x9283f6
0x80dd0a  64a100000000                      mov    eax,fs:0x0
0x80dd10  50                                push   eax
0x80dd11  83ec20                            sub    esp,0x20
0x80dd14  a1201fd600                        mov    eax,ds:0xd61f20
0x80dd19  33c5                              xor    eax,ebp
0x80dd1b  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x80dd1e  53                                push   ebx
0x80dd1f  56                                push   esi
0x80dd20  57                                push   edi
0x80dd21  50                                push   eax
0x80dd22  8d45f4                            lea    eax,[ebp-0xc]
0x80dd25  64a300000000                      mov    fs:0x0,eax
0x80dd2b  8bf9                              mov    edi,ecx
0x80dd2d  837f0c00                          cmp    DWORD PTR [edi+0xc],0x0
0x80dd31  740a                              je     0x80dd3d
0x80dd33  b801000000                        mov    eax,0x1
0x80dd38  e9b0010000                        jmp    0x80deed
0x80dd3d  833d60a8fb0000                    cmp    DWORD PTR ds:0xfba860,0x0
0x80dd44  bb10000000                        mov    ebx,0x10
0x80dd49  0f8591000000                      jne    0x80dde0
0x80dd4f  395f2c                            cmp    DWORD PTR [edi+0x2c],ebx
0x80dd52  8d7718                            lea    esi,[edi+0x18]
0x80dd55  7204                              jb     0x80dd5b
0x80dd57  8b06                              mov    eax,DWORD PTR [esi]
0x80dd59  eb02                              jmp    0x80dd5d
0x80dd5b  8bc6                              mov    eax,esi
0x80dd5d  6a09                              push   0x9
0x80dd5f  683c1ac500                        push   0xc51a3c
0x80dd64  50                                push   eax
0x80dd65  e8188b0800                        call   0x896882
0x80dd6a  83c40c                            add    esp,0xc
0x80dd6d  85c0                              test   eax,eax
0x80dd6f  746f                              je     0x80dde0
0x80dd71  395e14                            cmp    DWORD PTR [esi+0x14],ebx
0x80dd74  7204                              jb     0x80dd7a
0x80dd76  8b06                              mov    eax,DWORD PTR [esi]
0x80dd78  eb02                              jmp    0x80dd7c
0x80dd7a  8bc6                              mov    eax,esi
0x80dd7c  6a09                              push   0x9
0x80dd7e  68481ac500                        push   0xc51a48
0x80dd83  50                                push   eax
0x80dd84  e8f98a0800                        call   0x896882
0x80dd89  83c40c                            add    esp,0xc
0x80dd8c  85c0                              test   eax,eax
0x80dd8e  7450                              je     0x80dde0
0x80dd90  395e14                            cmp    DWORD PTR [esi+0x14],ebx
0x80dd93  7204                              jb     0x80dd99
0x80dd95  8b06                              mov    eax,DWORD PTR [esi]
0x80dd97  eb02                              jmp    0x80dd9b
0x80dd99  8bc6                              mov    eax,esi
0x80dd9b  6a06                              push   0x6
0x80dd9d  68541ac500                        push   0xc51a54
0x80dda2  50                                push   eax
0x80dda3  e8da8a0800                        call   0x896882
0x80dda8  83c40c                            add    esp,0xc
0x80ddab  85c0                              test   eax,eax
0x80ddad  7431                              je     0x80dde0
0x80ddaf  395e14                            cmp    DWORD PTR [esi+0x14],ebx
0x80ddb2  7202                              jb     0x80ddb6
0x80ddb4  8b36                              mov    esi,DWORD PTR [esi]
0x80ddb6  56                                push   esi
0x80ddb7  685c1ac500                        push   0xc51a5c
0x80ddbc  e89ffdedff                        call   0x6edb60
0x80ddc1  8b358022bd00                      mov    esi,DWORD PTR ds:0xbd2280
0x80ddc7  83c408                            add    esp,0x8
0x80ddca  6a01                              push   0x1
0x80ddcc  8d4714                            lea    eax,[edi+0x14]
0x80ddcf  50                                push   eax
0x80ddd0  ffd6                              call   esi
0x80ddd2  6a00                              push   0x0
0x80ddd4  03fb                              add    edi,ebx
0x80ddd6  57                                push   edi
0x80ddd7  ffd6                              call   esi
0x80ddd9  33c0                              xor    eax,eax
0x80dddb  e90d010000                        jmp    0x80deed
0x80dde0  f605d4b0fa0001                    test   BYTE PTR ds:0xfab0d4,0x1
0x80dde7  7527                              jne    0x80de10
0x80dde9  830dd4b0fa0001                    or     DWORD PTR ds:0xfab0d4,0x1
0x80ddf0  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x80ddf7  e8a4c5ffff                        call   0x80a3a0
0x80ddfc  68d0cdbc00                        push   0xbccdd0
0x80de01  e814450800                        call   0x89231a
0x80de06  83c404                            add    esp,0x4
0x80de09  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x80de10  8b152cb0fa00                      mov    edx,DWORD PTR ds:0xfab02c
0x80de16  391d40b0fa00                      cmp    DWORD PTR ds:0xfab040,ebx
0x80de1c  7305                              jae    0x80de23
0x80de1e  ba2cb0fa00                        mov    edx,0xfab02c
0x80de23  8bc2                              mov    eax,edx
0x80de25  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
0x80de2c  c745e400000000                    mov    DWORD PTR [ebp-0x1c],0x0
0x80de33  c645d400                          mov    BYTE PTR [ebp-0x2c],0x0
0x80de37  8d7001                            lea    esi,[eax+0x1]
0x80de3a  8d9b00000000                      lea    ebx,[ebx+0x0]
0x80de40  8a08                              mov    cl,BYTE PTR [eax]
0x80de42  40                                inc    eax
0x80de43  84c9                              test   cl,cl
0x80de45  75f9                              jne    0x80de40
0x80de47  2bc6                              sub    eax,esi
0x80de49  50                                push   eax
0x80de4a  52                                push   edx
0x80de4b  8d4dd4                            lea    ecx,[ebp-0x2c]
0x80de4e  e81d4cbfff                        call   0x402a70
0x80de53  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x80de5a  395f2c                            cmp    DWORD PTR [edi+0x2c],ebx
0x80de5d  7205                              jb     0x80de64
0x80de5f  8b5718                            mov    edx,DWORD PTR [edi+0x18]
0x80de62  eb03                              jmp    0x80de67
0x80de64  8d5718                            lea    edx,[edi+0x18]
0x80de67  8bc2                              mov    eax,edx
0x80de69  8d7001                            lea    esi,[eax+0x1]
0x80de6c  8d642400                          lea    esp,[esp+0x0]
0x80de70  8a08                              mov    cl,BYTE PTR [eax]
0x80de72  40                                inc    eax
0x80de73  84c9                              test   cl,cl
0x80de75  75f9                              jne    0x80de70
0x80de77  2bc6                              sub    eax,esi
0x80de79  50                                push   eax
0x80de7a  52                                push   edx
0x80de7b  8d4dd4                            lea    ecx,[ebp-0x2c]
0x80de7e  e83d41bfff                        call   0x401fc0
0x80de83  8b4dd4                            mov    ecx,DWORD PTR [ebp-0x2c]
0x80de86  395de8                            cmp    DWORD PTR [ebp-0x18],ebx
0x80de89  7303                              jae    0x80de8e
0x80de8b  8d4dd4                            lea    ecx,[ebp-0x2c]
0x80de8e  8b573c                            mov    edx,DWORD PTR [edi+0x3c]
0x80de91  52                                push   edx
0x80de92  e8b9fbffff                        call   0x80da50
0x80de97  8bd8                              mov    ebx,eax
0x80de99  85db                              test   ebx,ebx
0x80de9b  751f                              jne    0x80debc
0x80de9d  837de810                          cmp    DWORD PTR [ebp-0x18],0x10
0x80dea1  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
0x80dea4  7303                              jae    0x80dea9
0x80dea6  8d45d4                            lea    eax,[ebp-0x2c]
0x80dea9  50                                push   eax
0x80deaa  688c1ac500                        push   0xc51a8c
0x80deaf  e8acfcedff                        call   0x6edb60
0x80deb4  83c408                            add    esp,0x8
0x80deb7  8d4714                            lea    eax,[edi+0x14]
0x80deba  eb0a                              jmp    0x80dec6
0x80debc  c7473458020000                    mov    DWORD PTR [edi+0x34],0x258
0x80dec3  8d470c                            lea    eax,[edi+0xc]
0x80dec6  8b358022bd00                      mov    esi,DWORD PTR ds:0xbd2280
0x80decc  6a01                              push   0x1
0x80dece  50                                push   eax
0x80decf  ffd6                              call   esi
0x80ded1  6a00                              push   0x0
0x80ded3  83c710                            add    edi,0x10
0x80ded6  57                                push   edi
0x80ded7  ffd6                              call   esi
0x80ded9  837de810                          cmp    DWORD PTR [ebp-0x18],0x10
0x80dedd  720c                              jb     0x80deeb
0x80dedf  8b4dd4                            mov    ecx,DWORD PTR [ebp-0x2c]
0x80dee2  51                                push   ecx
0x80dee3  e824330800                        call   0x89120c
0x80dee8  83c404                            add    esp,0x4
0x80deeb  8bc3                              mov    eax,ebx
0x80deed  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80def0  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80def7  59                                pop    ecx
0x80def8  5f                                pop    edi
0x80def9  5e                                pop    esi
0x80defa  5b                                pop    ebx
0x80defb  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x80defe  33cd                              xor    ecx,ebp
0x80df00  e8fc300800                        call   0x891001
0x80df05  8be5                              mov    esp,ebp
0x80df07  5d                                pop    ebp
0x80df08  c3                                ret

; S10 SoundChannel stores resource/output and vtable
; VA 0x80cb50..0x80cb8d raw 0x40bf50 length 61 SHA256 cd7a5c6869b16b88138db342921d8793fdbc7430ace95a0d32d3e4cd85ed4f53
0x80cb50  d9ee                              fldz
0x80cb52  894e08                            mov    DWORD PTR [esi+0x8],ecx
0x80cb55  894604                            mov    DWORD PTR [esi+0x4],eax
0x80cb58  c706d819c500                      mov    DWORD PTR [esi],0xc519d8
0x80cb5e  b901000000                        mov    ecx,0x1
0x80cb63  894e0c                            mov    DWORD PTR [esi+0xc],ecx
0x80cb66  d95610                            fst    DWORD PTR [esi+0x10]
0x80cb69  d95614                            fst    DWORD PTR [esi+0x14]
0x80cb6c  33c0                              xor    eax,eax
0x80cb6e  d95e18                            fstp   DWORD PTR [esi+0x18]
0x80cb71  89461c                            mov    DWORD PTR [esi+0x1c],eax
0x80cb74  894e20                            mov    DWORD PTR [esi+0x20],ecx
0x80cb77  894624                            mov    DWORD PTR [esi+0x24],eax
0x80cb7a  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x80cb7d  014838                            add    DWORD PTR [eax+0x38],ecx
0x80cb80  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x80cb83  8b11                              mov    edx,DWORD PTR [ecx]
0x80cb85  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x80cb88  ffd0                              call   eax
0x80cb8a  8bc6                              mov    eax,esi
0x80cb8c  c3                                ret

; S11 SoundChannel callback: ready->output+18; failed->release pending; otherwise requeue
; VA 0x80cc90..0x80cd48 raw 0x40c090 length 184 SHA256 63ef24fedba088f78079cfdedcbb0cae582e6abe90fe582808932845c353ab96
0x80cc90  55                                push   ebp
0x80cc91  8bec                              mov    ebp,esp
0x80cc93  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x80cc96  56                                push   esi
0x80cc97  8bf1                              mov    esi,ecx
0x80cc99  57                                push   edi
0x80cc9a  397004                            cmp    DWORD PTR [eax+0x4],esi
0x80cc9d  740a                              je     0x80cca9
0x80cc9f  689019c500                        push   0xc51990
0x80cca4  e8c70feeff                        call   0x6edc70
0x80cca9  833800                            cmp    DWORD PTR [eax],0x0
0x80ccac  0f8590000000                      jne    0x80cd42
0x80ccb2  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
0x80ccb5  83790c00                          cmp    DWORD PTR [ecx+0xc],0x0
0x80ccb9  7437                              je     0x80ccf2
0x80ccbb  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x80ccbe  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x80ccc1  83c008                            add    eax,0x8
0x80ccc4  85c9                              test   ecx,ecx
0x80ccc6  741d                              je     0x80cce5
0x80ccc8  8b38                              mov    edi,DWORD PTR [eax]
0x80ccca  897e10                            mov    DWORD PTR [esi+0x10],edi
0x80cccd  8b7804                            mov    edi,DWORD PTR [eax+0x4]
0x80ccd0  897e14                            mov    DWORD PTR [esi+0x14],edi
0x80ccd3  8b7808                            mov    edi,DWORD PTR [eax+0x8]
0x80ccd6  897e18                            mov    DWORD PTR [esi+0x18],edi
0x80ccd9  89561c                            mov    DWORD PTR [esi+0x1c],edx
0x80ccdc  8b39                              mov    edi,DWORD PTR [ecx]
0x80ccde  52                                push   edx
0x80ccdf  50                                push   eax
0x80cce0  8b4718                            mov    eax,DWORD PTR [edi+0x18]
0x80cce3  ffd0                              call   eax
0x80cce5  8bce                              mov    ecx,esi
0x80cce7  e8f4feffff                        call   0x80cbe0
0x80ccec  5f                                pop    edi
0x80cced  5e                                pop    esi
0x80ccee  5d                                pop    ebp
0x80ccef  c20400                            ret    0x4
0x80ccf2  83791400                          cmp    DWORD PTR [ecx+0x14],0x0
0x80ccf6  7417                              je     0x80cd0f
0x80ccf8  c7462000000000                    mov    DWORD PTR [esi+0x20],0x0
0x80ccff  83c624                            add    esi,0x24
0x80cd02  56                                push   esi
0x80cd03  ff157c22bd00                      call   DWORD PTR ds:0xbd227c
0x80cd09  5f                                pop    edi
0x80cd0a  5e                                pop    esi
0x80cd0b  5d                                pop    ebp
0x80cd0c  c20400                            ret    0x4
0x80cd0f  8b10                              mov    edx,DWORD PTR [eax]
0x80cd11  83ec18                            sub    esp,0x18
0x80cd14  8bcc                              mov    ecx,esp
0x80cd16  8911                              mov    DWORD PTR [ecx],edx
0x80cd18  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x80cd1b  895104                            mov    DWORD PTR [ecx+0x4],edx
0x80cd1e  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x80cd21  895108                            mov    DWORD PTR [ecx+0x8],edx
0x80cd24  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0x80cd27  89510c                            mov    DWORD PTR [ecx+0xc],edx
0x80cd2a  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x80cd2d  8b4014                            mov    eax,DWORD PTR [eax+0x14]
0x80cd30  895110                            mov    DWORD PTR [ecx+0x10],edx
0x80cd33  894114                            mov    DWORD PTR [ecx+0x14],eax
0x80cd36  e8a5d5ffff                        call   0x80a2e0
0x80cd3b  8bf8                              mov    edi,eax
0x80cd3d  e80e000000                        call   0x80cd50
0x80cd42  5f                                pop    edi
0x80cd43  5e                                pop    esi
0x80cd44  5d                                pop    ebp
0x80cd45  c20400                            ret    0x4

; S12 Apply resource group and release queued reference
; VA 0x80cbe0..0x80cc8f raw 0x40bfe0 length 175 SHA256 bdfd8f2863abb8aee6500dfe04fffc4757fb2235eb3674be086e4ce2f2f722d3
0x80cbe0  55                                push   ebp
0x80cbe1  8bec                              mov    ebp,esp
0x80cbe3  6aff                              push   0xffffffff
0x80cbe5  680eeb9100                        push   0x91eb0e
0x80cbea  64a100000000                      mov    eax,fs:0x0
0x80cbf0  50                                push   eax
0x80cbf1  56                                push   esi
0x80cbf2  57                                push   edi
0x80cbf3  a1201fd600                        mov    eax,ds:0xd61f20
0x80cbf8  33c5                              xor    eax,ebp
0x80cbfa  50                                push   eax
0x80cbfb  8d45f4                            lea    eax,[ebp-0xc]
0x80cbfe  64a300000000                      mov    fs:0x0,eax
0x80cc04  8bf1                              mov    esi,ecx
0x80cc06  33ff                              xor    edi,edi
0x80cc08  897e20                            mov    DWORD PTR [esi+0x20],edi
0x80cc0b  397e04                            cmp    DWORD PTR [esi+0x4],edi
0x80cc0e  7464                              je     0x80cc74
0x80cc10  b801000000                        mov    eax,0x1
0x80cc15  8405d4b0fa00                      test   BYTE PTR ds:0xfab0d4,al
0x80cc1b  7522                              jne    0x80cc3f
0x80cc1d  0905d4b0fa00                      or     DWORD PTR ds:0xfab0d4,eax
0x80cc23  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x80cc26  e875d7ffff                        call   0x80a3a0
0x80cc2b  68d0cdbc00                        push   0xbccdd0
0x80cc30  e8e5560800                        call   0x89231a
0x80cc35  83c404                            add    esp,0x4
0x80cc38  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x80cc3f  56                                push   esi
0x80cc40  6828b0fa00                        push   0xfab028
0x80cc45  e816eeffff                        call   0x80ba60
0x80cc4a  85c0                              test   eax,eax
0x80cc4c  7426                              je     0x80cc74
0x80cc4e  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x80cc51  3bcf                              cmp    ecx,edi
0x80cc53  741f                              je     0x80cc74
0x80cc55  8b5604                            mov    edx,DWORD PTR [esi+0x4]
0x80cc58  8b01                              mov    eax,DWORD PTR [ecx]
0x80cc5a  8b5208                            mov    edx,DWORD PTR [edx+0x8]
0x80cc5d  8b4020                            mov    eax,DWORD PTR [eax+0x20]
0x80cc60  52                                push   edx
0x80cc61  ffd0                              call   eax
0x80cc63  8b7e04                            mov    edi,DWORD PTR [esi+0x4]
0x80cc66  83c718                            add    edi,0x18
0x80cc69  e882e7bfff                        call   0x40b3f0
0x80cc6e  50                                push   eax
0x80cc6f  e81cf1ffff                        call   0x80bd90
0x80cc74  83c624                            add    esi,0x24
0x80cc77  56                                push   esi
0x80cc78  ff157c22bd00                      call   DWORD PTR ds:0xbd227c
0x80cc7e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80cc81  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80cc88  59                                pop    ecx
0x80cc89  5f                                pop    edi
0x80cc8a  5e                                pop    esi
0x80cc8b  8be5                              mov    esp,ebp
0x80cc8d  5d                                pop    ebp
0x80cc8e  c3                                ret

; S13 SoundManager native worker callback80B360
; VA 0x80afe0..0x80b070 raw 0x40a3e0 length 144 SHA256 6dd95afeb885cdb5822cc51a4110e3bc73d1ae6b7d349fe84655a7e1648a7298
0x80afe0  57                                push   edi
0x80afe1  e87a360000                        call   0x80e660
0x80afe6  8906                              mov    DWORD PTR [esi],eax
0x80afe8  8b10                              mov    edx,DWORD PTR [eax]
0x80afea  8bc8                              mov    ecx,eax
0x80afec  8b420c                            mov    eax,DWORD PTR [edx+0xc]
0x80afef  6a01                              push   0x1
0x80aff1  ffd0                              call   eax
0x80aff3  33ff                              xor    edi,edi
0x80aff5  f605fc33fe0001                    test   BYTE PTR ds:0xfe33fc,0x1
0x80affc  7530                              jne    0x80b02e
0x80affe  830dfc33fe0001                    or     DWORD PTR ds:0xfe33fc,0x1
0x80b005  68000cbd00                        push   0xbd0c00
0x80b00a  893d0034fe00                      mov    DWORD PTR ds:0xfe3400,edi
0x80b010  893d0434fe00                      mov    DWORD PTR ds:0xfe3404,edi
0x80b016  893d0834fe00                      mov    DWORD PTR ds:0xfe3408,edi
0x80b01c  c7051034fe0004000000              mov    DWORD PTR ds:0xfe3410,0x4
0x80b026  e8ef720800                        call   0x89231a
0x80b02b  83c404                            add    esp,0x4
0x80b02e  680034fe00                        push   0xfe3400
0x80b033  e808120000                        call   0x80c240
0x80b038  6a0c                              push   0xc
0x80b03a  e829620800                        call   0x891268
0x80b03f  83c404                            add    esp,0x4
0x80b042  3bc7                              cmp    eax,edi
0x80b044  741c                              je     0x80b062
0x80b046  8bf8                              mov    edi,eax
0x80b048  c7004c19c500                      mov    DWORD PTR [eax],0xc5194c
0x80b04e  897004                            mov    DWORD PTR [eax+0x4],esi
0x80b051  c7400860b38000                    mov    DWORD PTR [eax+0x8],0x80b360
0x80b058  e81307cfff                        call   0x4fb770
0x80b05d  89466c                            mov    DWORD PTR [esi+0x6c],eax
0x80b060  5f                                pop    edi
0x80b061  c3                                ret
0x80b062  33c0                              xor    eax,eax
0x80b064  8bf8                              mov    edi,eax
0x80b066  e80507cfff                        call   0x4fb770
0x80b06b  89466c                            mov    DWORD PTR [esi+0x6c],eax
0x80b06e  5f                                pop    edi
0x80b06f  c3                                ret

; S14 Sound native worker pump and Sleep(5)
; VA 0x80b360..0x80b402 raw 0x40a760 length 162 SHA256 23576b24d51871017ca9fcd8663ac1667186831dff35aaebd1e0e5e1260280aa
0x80b360  55                                push   ebp
0x80b361  8bec                              mov    ebp,esp
0x80b363  83e4f8                            and    esp,0xfffffff8
0x80b366  6aff                              push   0xffffffff
0x80b368  681e749000                        push   0x90741e
0x80b36d  64a100000000                      mov    eax,fs:0x0
0x80b373  50                                push   eax
0x80b374  83ec08                            sub    esp,0x8
0x80b377  53                                push   ebx
0x80b378  56                                push   esi
0x80b379  57                                push   edi
0x80b37a  a1201fd600                        mov    eax,ds:0xd61f20
0x80b37f  33c4                              xor    eax,esp
0x80b381  50                                push   eax
0x80b382  8d442418                          lea    eax,[esp+0x18]
0x80b386  64a300000000                      mov    fs:0x0,eax
0x80b38c  8bd9                              mov    ebx,ecx
0x80b38e  c7437001000000                    mov    DWORD PTR [ebx+0x70],0x1
0x80b395  33f6                              xor    esi,esi
0x80b397  f605c433fe0001                    test   BYTE PTR ds:0xfe33c4,0x1
0x80b39e  752b                              jne    0x80b3cb
0x80b3a0  830dc433fe0001                    or     DWORD PTR ds:0xfe33c4,0x1
0x80b3a7  89742420                          mov    DWORD PTR [esp+0x20],esi
0x80b3ab  e8802c0000                        call   0x80e030
0x80b3b0  68d00bbd00                        push   0xbd0bd0
0x80b3b5  8935f833fe00                      mov    DWORD PTR ds:0xfe33f8,esi
0x80b3bb  e85a6f0800                        call   0x89231a
0x80b3c0  83c404                            add    esp,0x4
0x80b3c3  c7442420ffffffff                  mov    DWORD PTR [esp+0x20],0xffffffff
0x80b3cb  bfc833fe00                        mov    edi,0xfe33c8
0x80b3d0  e82b2d0000                        call   0x80e100
0x80b3d5  6a05                              push   0x5
0x80b3d7  ff150423bd00                      call   DWORD PTR ds:0xbd2304
0x80b3dd  397370                            cmp    DWORD PTR [ebx+0x70],esi
0x80b3e0  75b5                              jne    0x80b397
0x80b3e2  681c18c500                        push   0xc5181c
0x80b3e7  e8d17c0800                        call   0x8930bd
0x80b3ec  83c404                            add    esp,0x4
0x80b3ef  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x80b3f3  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80b3fa  59                                pop    ecx
0x80b3fb  5f                                pop    edi
0x80b3fc  5e                                pop    esi
0x80b3fd  5b                                pop    ebx
0x80b3fe  8be5                              mov    esp,ebp
0x80b400  5d                                pop    ebp
0x80b401  c3                                ret

; S15 Native queued messages -> typed target callback
; VA 0x80e100..0x80e1ec raw 0x40d500 length 236 SHA256 6236f9d82a96d8c91633bd9f5b7a2ce563851927a7367b43558f678d562a8c95
0x80e100  55                                push   ebp
0x80e101  8bec                              mov    ebp,esp
0x80e103  83ec28                            sub    esp,0x28
0x80e106  a1201fd600                        mov    eax,ds:0xd61f20
0x80e10b  33c5                              xor    eax,ebp
0x80e10d  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x80e110  53                                push   ebx
0x80e111  33db                              xor    ebx,ebx
0x80e113  56                                push   esi
0x80e114  395f30                            cmp    DWORD PTR [edi+0x30],ebx
0x80e117  0f85bf000000                      jne    0x80e1dc
0x80e11d  8d4900                            lea    ecx,[ecx+0x0]
0x80e120  57                                push   edi
0x80e121  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x80e127  395f28                            cmp    DWORD PTR [edi+0x28],ebx
0x80e12a  0f84a5000000                      je     0x80e1d5
0x80e130  8d45d8                            lea    eax,[ebp-0x28]
0x80e133  8d4f18                            lea    ecx,[edi+0x18]
0x80e136  e8d540d3ff                        call   0x542210
0x80e13b  8b08                              mov    ecx,DWORD PTR [eax]
0x80e13d  3bcb                              cmp    ecx,ebx
0x80e13f  7504                              jne    0x80e145
0x80e141  33c9                              xor    ecx,ecx
0x80e143  eb02                              jmp    0x80e147
0x80e145  8b09                              mov    ecx,DWORD PTR [ecx]
0x80e147  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x80e14a  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x80e14d  3bd0                              cmp    edx,eax
0x80e14f  7702                              ja     0x80e153
0x80e151  2bc2                              sub    eax,edx
0x80e153  8b4904                            mov    ecx,DWORD PTR [ecx+0x4]
0x80e156  8b0481                            mov    eax,DWORD PTR [ecx+eax*4]
0x80e159  8b10                              mov    edx,DWORD PTR [eax]
0x80e15b  8955e4                            mov    DWORD PTR [ebp-0x1c],edx
0x80e15e  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x80e161  894de8                            mov    DWORD PTR [ebp-0x18],ecx
0x80e164  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x80e167  8955ec                            mov    DWORD PTR [ebp-0x14],edx
0x80e16a  8b480c                            mov    ecx,DWORD PTR [eax+0xc]
0x80e16d  894df0                            mov    DWORD PTR [ebp-0x10],ecx
0x80e170  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x80e173  8955f4                            mov    DWORD PTR [ebp-0xc],edx
0x80e176  8b4014                            mov    eax,DWORD PTR [eax+0x14]
0x80e179  8945f8                            mov    DWORD PTR [ebp-0x8],eax
0x80e17c  8b4728                            mov    eax,DWORD PTR [edi+0x28]
0x80e17f  3bc3                              cmp    eax,ebx
0x80e181  7419                              je     0x80e19c
0x80e183  ff4724                            inc    DWORD PTR [edi+0x24]
0x80e186  8b4f24                            mov    ecx,DWORD PTR [edi+0x24]
0x80e189  394f20                            cmp    DWORD PTR [edi+0x20],ecx
0x80e18c  7703                              ja     0x80e191
0x80e18e  895f24                            mov    DWORD PTR [edi+0x24],ebx
0x80e191  48                                dec    eax
0x80e192  894728                            mov    DWORD PTR [edi+0x28],eax
0x80e195  3bc3                              cmp    eax,ebx
0x80e197  7503                              jne    0x80e19c
0x80e199  895f24                            mov    DWORD PTR [edi+0x24],ebx
0x80e19c  57                                push   edi
0x80e19d  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80e1a3  8b4de8                            mov    ecx,DWORD PTR [ebp-0x18]
0x80e1a6  3bcb                              cmp    ecx,ebx
0x80e1a8  740a                              je     0x80e1b4
0x80e1aa  8b11                              mov    edx,DWORD PTR [ecx]
0x80e1ac  8b12                              mov    edx,DWORD PTR [edx]
0x80e1ae  8d45e4                            lea    eax,[ebp-0x1c]
0x80e1b1  50                                push   eax
0x80e1b2  ffd2                              call   edx
0x80e1b4  6a01                              push   0x1
0x80e1b6  ff150423bd00                      call   DWORD PTR ds:0xbd2304
0x80e1bc  395f30                            cmp    DWORD PTR [edi+0x30],ebx
0x80e1bf  0f845bffffff                      je     0x80e120
0x80e1c5  5e                                pop    esi
0x80e1c6  5b                                pop    ebx
0x80e1c7  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x80e1ca  33cd                              xor    ecx,ebp
0x80e1cc  e8302e0800                        call   0x891001
0x80e1d1  8be5                              mov    esp,ebp
0x80e1d3  5d                                pop    ebp
0x80e1d4  c3                                ret
0x80e1d5  57                                push   edi
0x80e1d6  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80e1dc  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x80e1df  5e                                pop    esi
0x80e1e0  33cd                              xor    ecx,ebp
0x80e1e2  5b                                pop    ebx
0x80e1e3  e8192e0800                        call   0x891001
0x80e1e8  8be5                              mov    esp,ebp
0x80e1ea  5d                                pop    ebp
0x80e1eb  c3                                ret

; S16 Per-client update cleanup and resource hold counter
; VA 0x80b410..0x80b74e raw 0x40a810 length 830 SHA256 1a067c9ac9f2e3980fb28bb71839635cc266d19c764c71100b1e219616f1d1aa
0x80b410  55                                push   ebp
0x80b411  8bec                              mov    ebp,esp
0x80b413  6aff                              push   0xffffffff
0x80b415  6870c29000                        push   0x90c270
0x80b41a  64a100000000                      mov    eax,fs:0x0
0x80b420  50                                push   eax
0x80b421  83ec20                            sub    esp,0x20
0x80b424  53                                push   ebx
0x80b425  56                                push   esi
0x80b426  57                                push   edi
0x80b427  a1201fd600                        mov    eax,ds:0xd61f20
0x80b42c  33c5                              xor    eax,ebp
0x80b42e  50                                push   eax
0x80b42f  8d45f4                            lea    eax,[ebp-0xc]
0x80b432  64a300000000                      mov    fs:0x0,eax
0x80b438  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x80b43b  8db38c000000                      lea    esi,[ebx+0x8c]
0x80b441  56                                push   esi
0x80b442  8975e4                            mov    DWORD PTR [ebp-0x1c],esi
0x80b445  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x80b44b  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x80b452  8b435c                            mov    eax,DWORD PTR [ebx+0x5c]
0x80b455  8b38                              mov    edi,DWORD PTR [eax]
0x80b457  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x80b45a  3bf8                              cmp    edi,eax
0x80b45c  7474                              je     0x80b4d2
0x80b45e  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x80b461  8b4624                            mov    eax,DWORD PTR [esi+0x24]
0x80b464  85c0                              test   eax,eax
0x80b466  7f60                              jg     0x80b4c8
0x80b468  837e0800                          cmp    DWORD PTR [esi+0x8],0x0
0x80b46c  740e                              je     0x80b47c
0x80b46e  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x80b471  8b11                              mov    edx,DWORD PTR [ecx]
0x80b473  8b4210                            mov    eax,DWORD PTR [edx+0x10]
0x80b476  ffd0                              call   eax
0x80b478  85c0                              test   eax,eax
0x80b47a  754c                              jne    0x80b4c8
0x80b47c  837e0c00                          cmp    DWORD PTR [esi+0xc],0x0
0x80b480  7446                              je     0x80b4c8
0x80b482  837e2000                          cmp    DWORD PTR [esi+0x20],0x0
0x80b486  7540                              jne    0x80b4c8
0x80b488  8b7708                            mov    esi,DWORD PTR [edi+0x8]
0x80b48b  85f6                              test   esi,esi
0x80b48d  7415                              je     0x80b4a4
0x80b48f  e8fc160000                        call   0x80cb90
0x80b494  56                                push   esi
0x80b495  e8725d0800                        call   0x89120c
0x80b49a  83c404                            add    esp,0x4
0x80b49d  c7470800000000                    mov    DWORD PTR [edi+0x8],0x0
0x80b4a4  8b37                              mov    esi,DWORD PTR [edi]
0x80b4a6  3b7b5c                            cmp    edi,DWORD PTR [ebx+0x5c]
0x80b4a9  7419                              je     0x80b4c4
0x80b4ab  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x80b4ae  8930                              mov    DWORD PTR [eax],esi
0x80b4b0  8b0f                              mov    ecx,DWORD PTR [edi]
0x80b4b2  8b5704                            mov    edx,DWORD PTR [edi+0x4]
0x80b4b5  57                                push   edi
0x80b4b6  895104                            mov    DWORD PTR [ecx+0x4],edx
0x80b4b9  e84e5d0800                        call   0x89120c
0x80b4be  83c404                            add    esp,0x4
0x80b4c1  ff4b60                            dec    DWORD PTR [ebx+0x60]
0x80b4c4  8bfe                              mov    edi,esi
0x80b4c6  eb02                              jmp    0x80b4ca
0x80b4c8  8b3f                              mov    edi,DWORD PTR [edi]
0x80b4ca  3b7dec                            cmp    edi,DWORD PTR [ebp-0x14]
0x80b4cd  758f                              jne    0x80b45e
0x80b4cf  8b75e4                            mov    esi,DWORD PTR [ebp-0x1c]
0x80b4d2  56                                push   esi
0x80b4d3  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x80b4da  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80b4e0  8b534c                            mov    edx,DWORD PTR [ebx+0x4c]
0x80b4e3  8b0a                              mov    ecx,DWORD PTR [edx]
0x80b4e5  3bca                              cmp    ecx,edx
0x80b4e7  7452                              je     0x80b53b
0x80b4e9  8da42400000000                    lea    esp,[esp+0x0]
0x80b4f0  80792d00                          cmp    BYTE PTR [ecx+0x2d],0x0
0x80b4f4  c7412800000000                    mov    DWORD PTR [ecx+0x28],0x0
0x80b4fb  753a                              jne    0x80b537
0x80b4fd  8b4108                            mov    eax,DWORD PTR [ecx+0x8]
0x80b500  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b504  7516                              jne    0x80b51c
0x80b506  8bc8                              mov    ecx,eax
0x80b508  8b01                              mov    eax,DWORD PTR [ecx]
0x80b50a  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b50e  7527                              jne    0x80b537
0x80b510  8bc8                              mov    ecx,eax
0x80b512  8b01                              mov    eax,DWORD PTR [ecx]
0x80b514  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b518  74f6                              je     0x80b510
0x80b51a  eb1b                              jmp    0x80b537
0x80b51c  8b4104                            mov    eax,DWORD PTR [ecx+0x4]
0x80b51f  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b523  7510                              jne    0x80b535
0x80b525  3b4808                            cmp    ecx,DWORD PTR [eax+0x8]
0x80b528  750b                              jne    0x80b535
0x80b52a  8bc8                              mov    ecx,eax
0x80b52c  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x80b52f  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b533  74f0                              je     0x80b525
0x80b535  8bc8                              mov    ecx,eax
0x80b537  3bca                              cmp    ecx,edx
0x80b539  75b5                              jne    0x80b4f0
0x80b53b  8b435c                            mov    eax,DWORD PTR [ebx+0x5c]
0x80b53e  8b30                              mov    esi,DWORD PTR [eax]
0x80b540  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x80b543  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x80b546  3bf0                              cmp    esi,eax
0x80b548  0f8416010000                      je     0x80b664
0x80b54e  eb03                              jmp    0x80b553
0x80b550  8b75f0                            mov    esi,DWORD PTR [ebp-0x10]
0x80b553  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x80b556  8b7804                            mov    edi,DWORD PTR [eax+0x4]
0x80b559  83c718                            add    edi,0x18
0x80b55c  83780800                          cmp    DWORD PTR [eax+0x8],0x0
0x80b560  740e                              je     0x80b570
0x80b562  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x80b565  8b10                              mov    edx,DWORD PTR [eax]
0x80b567  8bc8                              mov    ecx,eax
0x80b569  8b4230                            mov    eax,DWORD PTR [edx+0x30]
0x80b56c  ffd0                              call   eax
0x80b56e  eb02                              jmp    0x80b572
0x80b570  d9ee                              fldz
0x80b572  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x80b575  d95de8                            fstp   DWORD PTR [ebp-0x18]
0x80b578  8b4904                            mov    ecx,DWORD PTR [ecx+0x4]
0x80b57b  8b11                              mov    edx,DWORD PTR [ecx]
0x80b57d  8b4220                            mov    eax,DWORD PTR [edx+0x20]
0x80b580  ffd0                              call   eax
0x80b582  d95de0                            fstp   DWORD PTR [ebp-0x20]
0x80b585  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x80b588  8b4824                            mov    ecx,DWORD PTR [eax+0x24]
0x80b58b  85c9                              test   ecx,ecx
0x80b58d  7f1c                              jg     0x80b5ab
0x80b58f  83780800                          cmp    DWORD PTR [eax+0x8],0x0
0x80b593  0f84bd000000                      je     0x80b656
0x80b599  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x80b59c  8b11                              mov    edx,DWORD PTR [ecx]
0x80b59e  8b4210                            mov    eax,DWORD PTR [edx+0x10]
0x80b5a1  ffd0                              call   eax
0x80b5a3  85c0                              test   eax,eax
0x80b5a5  0f84ab000000                      je     0x80b656
0x80b5ab  d945e8                            fld    DWORD PTR [ebp-0x18]
0x80b5ae  d94358                            fld    DWORD PTR [ebx+0x58]
0x80b5b1  d84de0                            fmul   DWORD PTR [ebp-0x20]
0x80b5b4  d8d9                              fcomp  st(1)
0x80b5b6  dfe0                              fnstsw ax
0x80b5b8  f6c441                            test   ah,0x41
0x80b5bb  0f8593000000                      jne    0x80b654
0x80b5c1  d9ee                              fldz
0x80b5c3  dae9                              fucompp
0x80b5c5  dfe0                              fnstsw ax
0x80b5c7  f6c444                            test   ah,0x44
0x80b5ca  0f8b86000000                      jnp    0x80b656
0x80b5d0  57                                push   edi
0x80b5d1  8d4348                            lea    eax,[ebx+0x48]
0x80b5d4  e8e70b0000                        call   0x80c1c0
0x80b5d9  8945dc                            mov    DWORD PTR [ebp-0x24],eax
0x80b5dc  3b434c                            cmp    eax,DWORD PTR [ebx+0x4c]
0x80b5df  745b                              je     0x80b63c
0x80b5e1  8b581c                            mov    ebx,DWORD PTR [eax+0x1c]
0x80b5e4  83c00c                            add    eax,0xc
0x80b5e7  83781410                          cmp    DWORD PTR [eax+0x14],0x10
0x80b5eb  7202                              jb     0x80b5ef
0x80b5ed  8b00                              mov    eax,DWORD PTR [eax]
0x80b5ef  8b7710                            mov    esi,DWORD PTR [edi+0x10]
0x80b5f2  8bce                              mov    ecx,esi
0x80b5f4  3bce                              cmp    ecx,esi
0x80b5f6  7300                              jae    0x80b5f8
0x80b5f8  8bd6                              mov    edx,esi
0x80b5fa  3bf3                              cmp    esi,ebx
0x80b5fc  7202                              jb     0x80b600
0x80b5fe  8bd3                              mov    edx,ebx
0x80b600  837f1410                          cmp    DWORD PTR [edi+0x14],0x10
0x80b604  7204                              jb     0x80b60a
0x80b606  8b0f                              mov    ecx,DWORD PTR [edi]
0x80b608  eb02                              jmp    0x80b60c
0x80b60a  8bcf                              mov    ecx,edi
0x80b60c  52                                push   edx
0x80b60d  50                                push   eax
0x80b60e  51                                push   ecx
0x80b60f  e86eb20800                        call   0x896882
0x80b614  83c40c                            add    esp,0xc
0x80b617  85c0                              test   eax,eax
0x80b619  7512                              jne    0x80b62d
0x80b61b  3bf3                              cmp    esi,ebx
0x80b61d  7305                              jae    0x80b624
0x80b61f  83c8ff                            or     eax,0xffffffff
0x80b622  eb07                              jmp    0x80b62b
0x80b624  33c0                              xor    eax,eax
0x80b626  3bf3                              cmp    esi,ebx
0x80b628  0f95c0                            setne  al
0x80b62b  85c0                              test   eax,eax
0x80b62d  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x80b630  0f98c0                            sets   al
0x80b633  84c0                              test   al,al
0x80b635  7505                              jne    0x80b63c
0x80b637  8d45dc                            lea    eax,[ebp-0x24]
0x80b63a  eb09                              jmp    0x80b645
0x80b63c  8b4b4c                            mov    ecx,DWORD PTR [ebx+0x4c]
0x80b63f  894dd8                            mov    DWORD PTR [ebp-0x28],ecx
0x80b642  8d45d8                            lea    eax,[ebp-0x28]
0x80b645  8b00                              mov    eax,DWORD PTR [eax]
0x80b647  8b75f0                            mov    esi,DWORD PTR [ebp-0x10]
0x80b64a  3b434c                            cmp    eax,DWORD PTR [ebx+0x4c]
0x80b64d  7407                              je     0x80b656
0x80b64f  ff4028                            inc    DWORD PTR [eax+0x28]
0x80b652  eb02                              jmp    0x80b656
0x80b654  ddd8                              fstp   st(0)
0x80b656  8b36                              mov    esi,DWORD PTR [esi]
0x80b658  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x80b65b  3b75ec                            cmp    esi,DWORD PTR [ebp-0x14]
0x80b65e  0f85ecfeffff                      jne    0x80b550
0x80b664  8d7374                            lea    esi,[ebx+0x74]
0x80b667  56                                push   esi
0x80b668  8975d4                            mov    DWORD PTR [ebp-0x2c],esi
0x80b66b  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x80b671  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x80b678  8b0b                              mov    ecx,DWORD PTR [ebx]
0x80b67a  8b11                              mov    edx,DWORD PTR [ecx]
0x80b67c  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x80b67f  ffd0                              call   eax
0x80b681  56                                push   esi
0x80b682  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x80b689  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80b68f  8b7b3c                            mov    edi,DWORD PTR [ebx+0x3c]
0x80b692  33c0                              xor    eax,eax
0x80b694  8983a4000000                      mov    DWORD PTR [ebx+0xa4],eax
0x80b69a  8983a8000000                      mov    DWORD PTR [ebx+0xa8],eax
0x80b6a0  8b37                              mov    esi,DWORD PTR [edi]
0x80b6a2  3bf7                              cmp    esi,edi
0x80b6a4  0f8490000000                      je     0x80b73a
0x80b6aa  8d9b00000000                      lea    ebx,[ebx+0x0]
0x80b6b0  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x80b6b3  8b4134                            mov    eax,DWORD PTR [ecx+0x34]
0x80b6b6  85c0                              test   eax,eax
0x80b6b8  7404                              je     0x80b6be
0x80b6ba  48                                dec    eax
0x80b6bb  894134                            mov    DWORD PTR [ecx+0x34],eax
0x80b6be  83793400                          cmp    DWORD PTR [ecx+0x34],0x0
0x80b6c2  7513                              jne    0x80b6d7
0x80b6c4  83793800                          cmp    DWORD PTR [ecx+0x38],0x0
0x80b6c8  750d                              jne    0x80b6d7
0x80b6ca  83790c00                          cmp    DWORD PTR [ecx+0xc],0x0
0x80b6ce  7407                              je     0x80b6d7
0x80b6d0  8b11                              mov    edx,DWORD PTR [ecx]
0x80b6d2  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x80b6d5  ffd0                              call   eax
0x80b6d7  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x80b6da  83790c00                          cmp    DWORD PTR [ecx+0xc],0x0
0x80b6de  7406                              je     0x80b6e6
0x80b6e0  ff83a8000000                      inc    DWORD PTR [ebx+0xa8]
0x80b6e6  ff83a4000000                      inc    DWORD PTR [ebx+0xa4]
0x80b6ec  807e2d00                          cmp    BYTE PTR [esi+0x2d],0x0
0x80b6f0  7540                              jne    0x80b732
0x80b6f2  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x80b6f5  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b6f9  7516                              jne    0x80b711
0x80b6fb  8bf0                              mov    esi,eax
0x80b6fd  8b06                              mov    eax,DWORD PTR [esi]
0x80b6ff  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b703  752d                              jne    0x80b732
0x80b705  8bf0                              mov    esi,eax
0x80b707  8b06                              mov    eax,DWORD PTR [esi]
0x80b709  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b70d  74f6                              je     0x80b705
0x80b70f  eb21                              jmp    0x80b732
0x80b711  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x80b714  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b718  7516                              jne    0x80b730
0x80b71a  8d9b00000000                      lea    ebx,[ebx+0x0]
0x80b720  3b7008                            cmp    esi,DWORD PTR [eax+0x8]
0x80b723  750b                              jne    0x80b730
0x80b725  8bf0                              mov    esi,eax
0x80b727  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x80b72a  80782d00                          cmp    BYTE PTR [eax+0x2d],0x0
0x80b72e  74f0                              je     0x80b720
0x80b730  8bf0                              mov    esi,eax
0x80b732  3bf7                              cmp    esi,edi
0x80b734  0f8576ffffff                      jne    0x80b6b0
0x80b73a  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80b73d  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80b744  59                                pop    ecx
0x80b745  5f                                pop    edi
0x80b746  5e                                pop    esi
0x80b747  5b                                pop    ebx
0x80b748  8be5                              mov    esp,ebp
0x80b74a  5d                                pop    ebp
0x80b74b  c20400                            ret    0x4

; S17 SoundChannel output/resource release
; VA 0x80cb90..0x80cbda raw 0x40bf90 length 74 SHA256 ed7e16dc7a6f7bef96b8f55345f1b3af64442c58c50cafb171bcb35bc14c7d13
0x80cb90  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x80cb93  c706d819c500                      mov    DWORD PTR [esi],0xc519d8
0x80cb99  85c9                              test   ecx,ecx
0x80cb9b  740e                              je     0x80cbab
0x80cb9d  8b01                              mov    eax,DWORD PTR [ecx]
0x80cb9f  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x80cba2  ffd2                              call   edx
0x80cba4  c7460800000000                    mov    DWORD PTR [esi+0x8],0x0
0x80cbab  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x80cbae  85c0                              test   eax,eax
0x80cbb0  7427                              je     0x80cbd9
0x80cbb2  8b4838                            mov    ecx,DWORD PTR [eax+0x38]
0x80cbb5  85c9                              test   ecx,ecx
0x80cbb7  7515                              jne    0x80cbce
0x80cbb9  68fc19c500                        push   0xc519fc
0x80cbbe  e84d0feeff                        call   0x6edb10
0x80cbc3  83c404                            add    esp,0x4
0x80cbc6  c7460400000000                    mov    DWORD PTR [esi+0x4],0x0
0x80cbcd  c3                                ret
0x80cbce  49                                dec    ecx
0x80cbcf  894838                            mov    DWORD PTR [eax+0x38],ecx
0x80cbd2  c7460400000000                    mov    DWORD PTR [esi+0x4],0x0
0x80cbd9  c3                                ret

; S18 SoundChannel allocation and shared live list
; VA 0x80be60..0x80bf4b raw 0x40b260 length 235 SHA256 f968b467f98bbd5fed5cf3671e4ea41be8c507fa68cf983789337fde13439c7d
0x80be60  55                                push   ebp
0x80be61  8bec                              mov    ebp,esp
0x80be63  6aff                              push   0xffffffff
0x80be65  68f3739000                        push   0x9073f3
0x80be6a  64a100000000                      mov    eax,fs:0x0
0x80be70  50                                push   eax
0x80be71  51                                push   ecx
0x80be72  53                                push   ebx
0x80be73  56                                push   esi
0x80be74  a1201fd600                        mov    eax,ds:0xd61f20
0x80be79  33c5                              xor    eax,ebp
0x80be7b  50                                push   eax
0x80be7c  8d45f4                            lea    eax,[ebp-0xc]
0x80be7f  64a300000000                      mov    fs:0x0,eax
0x80be85  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x80be88  8db78c000000                      lea    esi,[edi+0x8c]
0x80be8e  56                                push   esi
0x80be8f  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x80be92  ff154c22bd00                      call   DWORD PTR ds:0xbd224c
0x80be98  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x80be9f  85db                              test   ebx,ebx
0x80bea1  751c                              jne    0x80bebf
0x80bea3  56                                push   esi
0x80bea4  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80beaa  33c0                              xor    eax,eax
0x80beac  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80beaf  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80beb6  59                                pop    ecx
0x80beb7  5e                                pop    esi
0x80beb8  5b                                pop    ebx
0x80beb9  8be5                              mov    esp,ebp
0x80bebb  5d                                pop    ebp
0x80bebc  c20800                            ret    0x8
0x80bebf  817f6000010000                    cmp    DWORD PTR [edi+0x60],0x100
0x80bec6  73db                              jae    0x80bea3
0x80bec8  6a28                              push   0x28
0x80beca  e899530800                        call   0x891268
0x80becf  8bf0                              mov    esi,eax
0x80bed1  83c404                            add    esp,0x4
0x80bed4  897508                            mov    DWORD PTR [ebp+0x8],esi
0x80bed7  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x80bedb  85f6                              test   esi,esi
0x80bedd  740e                              je     0x80beed
0x80bedf  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x80bee2  8bc3                              mov    eax,ebx
0x80bee4  e8670c0000                        call   0x80cb50
0x80bee9  8bd8                              mov    ebx,eax
0x80beeb  eb02                              jmp    0x80beef
0x80beed  33db                              xor    ebx,ebx
0x80beef  c645fc00                          mov    BYTE PTR [ebp-0x4],0x0
0x80bef3  8b775c                            mov    esi,DWORD PTR [edi+0x5c]
0x80bef6  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
0x80bef9  8d4508                            lea    eax,[ebp+0x8]
0x80befc  50                                push   eax
0x80befd  51                                push   ecx
0x80befe  56                                push   esi
0x80beff  895d08                            mov    DWORD PTR [ebp+0x8],ebx
0x80bf02  e8f917f4ff                        call   0x74d700
0x80bf07  8b4f60                            mov    ecx,DWORD PTR [edi+0x60]
0x80bf0a  bafeffff3f                        mov    edx,0x3ffffffe
0x80bf0f  2bd1                              sub    edx,ecx
0x80bf11  83fa01                            cmp    edx,0x1
0x80bf14  730a                              jae    0x80bf20
0x80bf16  683420bf00                        push   0xbf2034
0x80bf1b  e8101c0700                        call   0x87db30
0x80bf20  8b55f0                            mov    edx,DWORD PTR [ebp-0x10]
0x80bf23  41                                inc    ecx
0x80bf24  894f60                            mov    DWORD PTR [edi+0x60],ecx
0x80bf27  894604                            mov    DWORD PTR [esi+0x4],eax
0x80bf2a  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x80bf2d  52                                push   edx
0x80bf2e  8901                              mov    DWORD PTR [ecx],eax
0x80bf30  ff154822bd00                      call   DWORD PTR ds:0xbd2248
0x80bf36  8bc3                              mov    eax,ebx
0x80bf38  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x80bf3b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x80bf42  59                                pop    ecx
0x80bf43  5e                                pop    esi
0x80bf44  5b                                pop    ebx
0x80bf45  8be5                              mov    esp,ebp
0x80bf47  5d                                pop    ebp
0x80bf48  c20800                            ret    0x8

; V_KEYFRAME COL pointer plus exact virtual slots
; VA 0xc0fd1c..0xc0fd44 raw 0x80e31c length 40 SHA256 74af42181e3a1c67fc64361cb9a88cc021a2bca9d538ed3e18993a9dff833e9f
; bytes 34cbc60010e9540080e0540030e2540060e254003064470070e25400c0e25400d0e2540010e35400

; V_KEYFRAME_COL CompleteObjectLocator
; VA 0xc6cb34..0xc6cb48 raw 0x86b134 length 20 SHA256 e8d951c77f4563014287b77657398942cb7e46a5f1939253f916d154c44a5a3f
; bytes 000000000000000000000000ccf7f70048cbc600

; V_KEYFRAME_TYPE Typed RTTI name
; VA 0xf7f7d4..0xf7f7fc raw 0xb7cfd4 length 40 SHA256 14c4273501bdcc7374db124cd045c05066148b33c0ada28169e82b3fe000de7c
; bytes 2e3f41564343616d657261576f726b735f4b65794672616d654043616d657261576f726b73404000

; V_STREAM COL pointer plus exact virtual slots
; VA 0xc51bf0..0xc51c44 raw 0x8501f0 length 84 SHA256 7aa8492853f1d54e312e6d588de54ae90ac267c65541957f357a9c4845c5d9c4
; bytes 8816c80010e7800050e78000a0e78000f0c28d00d0e7800040e9800020ea800090ea8000f0ea800010eb8000f0c28d0030eb800000ed800050ec800070ec8000a0ec8000d0ec800020ed800090eb8000c0eb8000

; V_STREAM_COL CompleteObjectLocator
; VA 0xc81688..0xc8169c raw 0x87fc88 length 20 SHA256 86b1f63190e5f4a0c95e7f2f57e58f798dfa6942161b25feea43209789f6c166
; bytes 000000000000000000000000b4b3f8009c16c800

; V_STREAM_TYPE Typed RTTI name
; VA 0xf8b3bc..0xf8b3da raw 0xb88bbc length 30 SHA256 d354fd278751d2b02705477f300d327e34d2d3c500b1ff7ff0d06d5fee07e63b
; bytes 2e3f41564353747265616d447269766572404d6f6f6e536f756e64404000

; V_SOUND_FILE COL pointer plus exact virtual slots
; VA 0xc51b1c..0xc51b44 raw 0x85011c length 40 SHA256 c389b654da0014ef9d2c68ceba49ad1704db30b38336d37299273769f7f096ca
; bytes 7814c80070d8800000dd800050db8000d0dc800090d5800050d5800090d48000a0db8000c0db8000

; V_SOUND_FILE_COL CompleteObjectLocator
; VA 0xc81478..0xc8148c raw 0x87fa78 length 20 SHA256 51bd3824300306826121f2583e73c6212f3606326eecb04525dde0ffe64cb452
; bytes 000000000000000000000000f8b2f8008c14c800

; V_SOUND_FILE_TYPE Typed RTTI name
; VA 0xf8b300..0xf8b31a raw 0xb88b00 length 26 SHA256 87cbb14cc3bbb67dca0778dcf1b22b3edf106a8f3df1a689d51d83c01794b9a1
; bytes 2e3f4156536f756e6446696c65404d6f6f6e536f756e64404000

; V_SOUND_RESOURCE_CALLBACK COL pointer plus exact virtual slots
; VA 0xc51b44..0xc51b4c raw 0x850144 length 8 SHA256 c1e0f3c021ac2abf96b35a3267835e02e13ab7bd150953ccd26b7be8926a7c2d
; bytes 6414c800b0d88000

; V_SOUND_RESOURCE_CALLBACK_COL CompleteObjectLocator
; VA 0xc81464..0xc81478 raw 0x87fa64 length 20 SHA256 8a39ace0d48f9105d294bdea39e02a5fb09f1b3835cec2b0ef5c20fc8d668f51
; bytes 000000000400000000000000f8b2f8008c14c800

; V_SOUND_RESOURCE_CALLBACK_TYPE Typed RTTI name
; VA 0xf8b300..0xf8b31a raw 0xb88b00 length 26 SHA256 87cbb14cc3bbb67dca0778dcf1b22b3edf106a8f3df1a689d51d83c01794b9a1
; bytes 2e3f4156536f756e6446696c65404d6f6f6e536f756e64404000

; V_SOUND_CHANNEL COL pointer plus exact virtual slots
; VA 0xc519d4..0xc519dc raw 0x84ffd4 length 8 SHA256 762e672ac8d60266baa689530e8cbf276f7560a8c99ea0e9432efe9506d3d154
; bytes e413c80090cc8000

; V_SOUND_CHANNEL_COL CompleteObjectLocator
; VA 0xc813e4..0xc813f8 raw 0x87f9e4 length 20 SHA256 d5c3d5a4f605198ddb71af5bd4b101fc3a4bf9a6fae9962d426c57e6957e7707
; bytes 000000000000000000000000d0b2f800f813c800

; V_SOUND_CHANNEL_TYPE Typed RTTI name
; VA 0xf8b2d8..0xf8b2f5 raw 0xb88ad8 length 29 SHA256 5e36fd45b57fb77f86903aa3519f102e0a7e30fb10bcf9ea28e3ae0177a117a5
; bytes 2e3f4156536f756e644368616e6e656c404d6f6f6e536f756e64404000

; V_MUSIC_FUNCTOR COL pointer plus exact virtual slots
; VA 0xc40fe8..0xc40ff8 raw 0x83f5e8 length 16 SHA256 81dff1d46ea8659c527090c0e8aeb059726aec0ccdb632370520c139b1a9d684
; bytes 8cb5c700e0ac4f0010ab6d00d0ac4f00

; V_MUSIC_FUNCTOR_COL CompleteObjectLocator
; VA 0xc7b58c..0xc7b5a0 raw 0x879b8c length 20 SHA256 f58a5a684c1da594dacf9fbf4cc303f18444df85be2a435cc299cd22d155a69f
; bytes 000000000000000000000000cc83f800a0b5c700

; V_MUSIC_FUNCTOR_TYPE Typed RTTI name
; VA 0xf883d4..0xf883fd raw 0xb85bd4 length 41 SHA256 31145ef34d2b9d7f1567857b8acc23c67bb6e976b2ad96bcf9c6092e27de943d
; bytes 2e3f41563f2446756e63746f7241726730496e7374405856434d75736963506c617965724040404000

; V_SOUND_FUNCTOR COL pointer plus exact virtual slots
; VA 0xc51948..0xc51958 raw 0x84ff48 length 16 SHA256 14f1efb9cd9365c70a5c924696093e0fac9fefd63853624b6133496599d21d41
; bytes 9813c800e0ac4f0010ab6d00d0ac4f00

; V_SOUND_FUNCTOR_COL CompleteObjectLocator
; VA 0xc81398..0xc813ac raw 0x87f998 length 20 SHA256 70d7118dd78049654af782bbeacaa3ef36755d67c1835b71f8da7350ae436bdf
; bytes 00000000000000000000000064b2f800ac13c800

; V_SOUND_FUNCTOR_TYPE Typed RTTI name
; VA 0xf8b26c..0xf8b29f raw 0xb88a6c length 51 SHA256 7a8ad0fb194a7e6321d3e16d017941301dabeb68f2196c507c02317dc5ba4397
; bytes 2e3f41563f2446756e63746f7241726730496e7374405856536f756e644d616e61676572404d6f6f6e536f756e644040404000

; V_OGG_STREAM COL pointer plus exact virtual slots
; VA 0xc51f3c..0xc51f4c raw 0x85053c length 16 SHA256 039a0267c8a85e6969a763a21d27fa08c4840fa54017d69b32d2458b7768b61f
; bytes 841ac800a0098100d00a8100100b8100

; V_OGG_STREAM_COL CompleteObjectLocator
; VA 0xc81a84..0xc81a98 raw 0x880084 length 20 SHA256 70799c344a6fdb2da8f7c9d09023a6c29e094f55146de669f59c75d03f4c16a7
; bytes 000000000000000000000000f8b5f800981ac800

; V_OGG_STREAM_TYPE Typed RTTI name
; VA 0xf8b600..0xf8b61b raw 0xb88e00 length 27 SHA256 115f9bf7b1f7bf8e28aad3b15cfcb2694c9579681c9ea0a7c95fce3b9fb8cdbf
; bytes 2e3f4156434f474753747265616d404d6f6f6e536f756e64404000

; K_EFFECT_STEP Exact floating-point constant
; VA 0xc55cc8..0xc55cd0 raw 0x8542c8 length 8 SHA256 66fa3ce6fff3c968708a104c9f7861dde82032256e928760956f798e93c43f97
; bytes 0000004052c1f03f

; K_EFFECT_ZERO_DEFAULT Exact floating-point constant
; VA 0xc557c4..0xc557c8 raw 0x853dc4 length 4 SHA256 5d5d32c7cf8e2ca77d9af6bf35a0ba5cd09074ccb4f3871aba6f67420b324a57
; bytes 00002042

; K_ALPHA Exact floating-point constant
; VA 0xc55688..0xc55690 raw 0x853c88 length 8 SHA256 729bef532e854760af95391c84e7ba32d372f3384227e6d952a809b8b7f35eb5
; bytes 0000000000e06f40

; K_MILLISECONDS Exact floating-point constant
; VA 0xc557d8..0xc557e0 raw 0x853dd8 length 8 SHA256 139107fd63d004e94cb64abb75361dd8490810c6709a9311896ca17496f5ecde
; bytes 0000000000408f40

; K_ZERO_MULTIPLIER Exact floating-point constant
; VA 0xc55670..0xc55678 raw 0x853c70 length 8 SHA256 af5570f5a1810b7af78caf4bc70a660f0df51e42baf91d4de5b2328de0e83dfc
; bytes 0000000000000000

; K_ONE Exact floating-point constant
; VA 0xc456c0..0xc456c4 raw 0x843cc0 length 4 SHA256 e00e5eb9444182f352323374ef4e08ebcb784725fdd4fd612d7730540b3e0c8c
; bytes 0000803f

; K_DELAY_NORMAL Exact floating-point constant
; VA 0xc558c0..0xc558c4 raw 0x853ec0 length 4 SHA256 0d66bd808e9247acb560fe33efaa62ad6f11ee6f85cc4f61bd17673263de04ee
; bytes 0ad7233c

; K_DELAY_OVERLAP Exact floating-point constant
; VA 0xc0c7f8..0xc0c7fc raw 0x80adf8 length 4 SHA256 d88c86f15bbea365d658ad95a81d45367c465f7af6f7264fb077f01747ddc77d
; bytes 00000040

; K_FADE_THRESHOLD Exact floating-point constant
; VA 0xc55bc8..0xc55bcc raw 0x8541c8 length 4 SHA256 74777d619667e6e4446ced0f1b2757da66086196bacecd1c7d029af0d558a630
; bytes abaaaa3e

; K_OLD_FADE Exact floating-point constant
; VA 0xc0c7f4..0xc0c7f8 raw 0x80adf4 length 4 SHA256 ea2845900b5856c9bf354b1aa9761b5aa6888e5ed61738fe9579ca42bc0f6054
; bytes 00004040

; K_TRANSITION_SCALE Exact floating-point constant
; VA 0xc55c08..0xc55c10 raw 0x854208 length 8 SHA256 1cab600f57951016c0b4bd619177c26235366a7f52e26e839e3aac1219cda82d
; bytes 000000000000c03f

; K_TRANSITION_MAXDELTA Exact floating-point constant
; VA 0xc55898..0xc558a0 raw 0x853e98 length 8 SHA256 3e2a4d232d889625aa1c184b27588b7c6ebdfef18e01332502d986209f65b905
; bytes 000000a09999b93f

; STR00 cameraworks
; VA 0xc4f1b8..0xc4f1c4 raw 0x84d7b8 length 12 SHA256 b1ae92622a43273aa07d76f6a81d18b7ba221e1ede2ebcd134345b4446ae1f61
; bytes 63616d657261776f726b7300

; STR01 keyframe
; VA 0xc4f1c4..0xc4f1cd raw 0x84d7c4 length 9 SHA256 f685297d788eddb96450bc33e7dee5fceb379d1fe1a561a96e573e419a1b5996
; bytes 6b65796672616d6500

; STR02 framepos
; VA 0xc4f1d0..0xc4f1d9 raw 0x84d7d0 length 9 SHA256 fdec79755cb13b28deda9ef05d8276e97b67b186fa81d7cc53a18d39976499f0
; bytes 6672616d65706f7300

; STR03 position
; VA 0xc445b0..0xc445b9 raw 0x842bb0 length 9 SHA256 0e3bc92db34e1ab84eb1bcfd48ca8c4b18f90f689489c1a463253300af6c5326
; bytes 706f736974696f6e00

; STR04 x
; VA 0xc06928..0xc0692a raw 0x804f28 length 2 SHA256 14f825b2bbc32dd8d196367fa8776873069c12a8954d8da7513aa7704ddd09eb
; bytes 7800

; STR05 y
; VA 0xc0692c..0xc0692e raw 0x804f2c length 2 SHA256 6a75da5da0cd28492372c3dde802e4bbe80564f01926cc1af00066623653770c
; bytes 7900

; STR06 z
; VA 0xc4f1ec..0xc4f1ee raw 0x84d7ec length 2 SHA256 c03ad57f5b1b1bddf59ddb5c973b459f432291edad374fe9d051c59d102d8742
; bytes 7a00

; STR07 pivot
; VA 0xc4f1f0..0xc4f1f6 raw 0x84d7f0 length 6 SHA256 5b54590396020ae626fa2766c8ec1773fa1af365b90841d862672ed00cadd0e3
; bytes 7069766f7400

; STR08 pitch
; VA 0xc4f1f8..0xc4f1fe raw 0x84d7f8 length 6 SHA256 688f2c12260c7c24420870c7f07e11ba7f0e48ab320b95706a438f5b2dcd8308
; bytes 706974636800

; STR09 yaw
; VA 0xc4f200..0xc4f204 raw 0x84d800 length 4 SHA256 ce6105ab1a3d7679a8f1a612e53851f340bf571dd4017078cdde1fab837c3f8f
; bytes 79617700

; STR10 roll
; VA 0xc4f204..0xc4f209 raw 0x84d804 length 5 SHA256 50466c7d9b2182fe5a11d8a1a0eacf355c5462e4dc8ae84f5de316346f550aea
; bytes 726f6c6c00

; STR11 dist
; VA 0xc4f20c..0xc4f211 raw 0x84d80c length 5 SHA256 f925e2ca3ac59755eb67e62dd41534c4a3258c434a30008cd835a04f1945aebc
; bytes 6469737400

; STR12 easing
; VA 0xc4f214..0xc4f21b raw 0x84d814 length 7 SHA256 19cde533052561c1a4bac849053f795e315d089b92bd1e10f3145ee2584ae9ab
; bytes 656173696e6700

; STR13 easingtype
; VA 0xc4f21c..0xc4f227 raw 0x84d81c length 11 SHA256 fe873457145e7c9bcc984c6cdf10e362cbae58caba35b885a06e888dd2f62a19
; bytes 656173696e677479706500

; STR14 Failed to take screen shot (%d)!
; VA 0xc45460..0xc45481 raw 0x843a60 length 33 SHA256 3e211d87c0f98b457e30b1b0ccbdd8cd99549adbafb02f4127869c3266443da7
; bytes 4661696c656420746f2074616b652073637265656e2073686f7420282564292100

; STR15 Took screenshot
; VA 0xc454b8..0xc454c8 raw 0x843ab8 length 16 SHA256 a5ffa892f0798a8d088bab0b445dbf7f31431a0e0eaba31457c89a5da2a57f9a
; bytes 546f6f6b2073637265656e73686f7400

; STR16 Sound/
; VA 0xc1073c..0xc10743 raw 0x80ed3c length 7 SHA256 e1e1226a83264342c7981adb7788e979f2c12a254c0c94c2978efdbf5d9ccd14
; bytes 536f756e642f00

; STR17 Voice
; VA 0xc05804..0xc0580a raw 0x803e04 length 6 SHA256 a9edb15f64eee32bbddaa15815e486eac38a9aa96d06fafd014c8620ecf439d6
; bytes 566f69636500

; STR18 Scenario/
; VA 0xc51a3c..0xc51a46 raw 0x85003c length 10 SHA256 61e6be99b25c19ab144712ed9b75f7e2ffd35d9e1905550b7a756069e1f0d9d5
; bytes 5363656e6172696f2f00

; STR19 Prologue/
; VA 0xc51a48..0xc51a52 raw 0x850048 length 10 SHA256 a2a079b70ca601c982e859adb1cdb69fd9a90edf7738e82a1338d7ab0de2d075
; bytes 50726f6c6f6775652f00

; STR20 SoundFile.Load(): File not found: %s
; VA 0xc51a8c..0xc51ab1 raw 0x85008c length 37 SHA256 41df0b49c7fdf772db96737a1cd808a92d7b444da5a82b657e37460f524528e8
; bytes 536f756e6446696c652e4c6f616428293a2046696c65206e6f7420666f756e643a20257300
