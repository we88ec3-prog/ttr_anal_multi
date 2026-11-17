; P1 new bounded original-code windows. Reused windows remain in pinned publications.
; BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91

; blank_loadmap_nonnull_and_backup | Q.LoadMap checks null pointer, then saves camera/map and calls graphics loader; empty string is not an early no-op
; VA 0x563c40..0x563d4d raw 0x163040 SHA256 8c4e702533835040a942c56ff4c04bcfe78969a4fba75f0f8606a99fa85295a9
0x563c40  55                                push   ebp
0x563c41  8bec                              mov    ebp,esp
0x563c43  83e4f8                            and    esp,0xfffffff8
0x563c46  6aff                              push   0xffffffff
0x563c48  68c0649300                        push   0x9364c0
0x563c4d  64a100000000                      mov    eax,fs:0x0
0x563c53  50                                push   eax
0x563c54  81ec28010000                      sub    esp,0x128
0x563c5a  a1201fd600                        mov    eax,ds:0xd61f20
0x563c5f  33c4                              xor    eax,esp
0x563c61  89842420010000                    mov    DWORD PTR [esp+0x120],eax
0x563c68  53                                push   ebx
0x563c69  56                                push   esi
0x563c6a  57                                push   edi
0x563c6b  a1201fd600                        mov    eax,ds:0xd61f20
0x563c70  33c4                              xor    eax,esp
0x563c72  50                                push   eax
0x563c73  8d842438010000                    lea    eax,[esp+0x138]
0x563c7a  64a300000000                      mov    fs:0x0,eax
0x563c80  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x563c83  8bd9                              mov    ebx,ecx
0x563c85  89442414                          mov    DWORD PTR [esp+0x14],eax
0x563c89  85c0                              test   eax,eax
0x563c8b  0f84de020000                      je     0x563f6f
0x563c91  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x563c98  752f                              jne    0x563cc9
0x563c9a  830de879fb0001                    or     DWORD PTR ds:0xfb79e8,0x1
0x563ca1  c784244001000000000000            mov    DWORD PTR [esp+0x140],0x0
0x563cac  e82f512300                        call   0x798de0
0x563cb1  68e0d2bc00                        push   0xbcd2e0
0x563cb6  e85fe63200                        call   0x89231a
0x563cbb  83c404                            add    esp,0x4
0x563cbe  c7842440010000ffffffff            mov    DWORD PTR [esp+0x140],0xffffffff
0x563cc9  8b35e876fb00                      mov    esi,DWORD PTR ds:0xfb76e8
0x563ccf  8b7b30                            mov    edi,DWORD PTR [ebx+0x30]
0x563cd2  83c60c                            add    esi,0xc
0x563cd5  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x563cdc  b90b000000                        mov    ecx,0xb
0x563ce1  f3a5                              rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x563ce3  bf01000000                        mov    edi,0x1
0x563ce8  752a                              jne    0x563d14
0x563cea  093d2cb2fa00                      or     DWORD PTR ds:0xfab22c,edi
0x563cf0  89bc2440010000                    mov    DWORD PTR [esp+0x140],edi
0x563cf7  e894aff7ff                        call   0x4dec90
0x563cfc  6830cebc00                        push   0xbcce30
0x563d01  e814e63200                        call   0x89231a
0x563d06  83c404                            add    esp,0x4
0x563d09  c7842440010000ffffffff            mov    DWORD PTR [esp+0x140],0xffffffff
0x563d14  8b542414                          mov    edx,DWORD PTR [esp+0x14]
0x563d18  a178b1fa00                        mov    eax,ds:0xfab178
0x563d1d  6a00                              push   0x0
0x563d1f  6a00                              push   0x0
0x563d21  6804010000                        push   0x104
0x563d26  8d4c2430                          lea    ecx,[esp+0x30]
0x563d2a  51                                push   ecx
0x563d2b  6a00                              push   0x0
0x563d2d  6a00                              push   0x0
0x563d2f  6a00                              push   0x0
0x563d31  6a00                              push   0x0
0x563d33  52                                push   edx
0x563d34  894334                            mov    DWORD PTR [ebx+0x34],eax
0x563d37  e8a72b3300                        call   0x8968e3
0x563d3c  83c424                            add    esp,0x24
0x563d3f  6a00                              push   0x0
0x563d41  8d742428                          lea    esi,[esp+0x28]
0x563d45  e8b6e02500                        call   0x7c1e00
0x563d4a  83c404                            add    esp,0x4

; graphics_empty_basename_lookup | append .fld even to empty basename; lookup MAP_FLD; missing entry takes failure branch
; VA 0x7c1e00..0x7c1ed1 raw 0x3c1200 SHA256 c4a16439cc6e7fe20e06ee4b61b95e404709251d32cc838cf63eb0923e325932
0x7c1e00  55                                push   ebp
0x7c1e01  8bec                              mov    ebp,esp
0x7c1e03  6aff                              push   0xffffffff
0x7c1e05  68728a9100                        push   0x918a72
0x7c1e0a  64a100000000                      mov    eax,fs:0x0
0x7c1e10  50                                push   eax
0x7c1e11  81ec44010000                      sub    esp,0x144
0x7c1e17  a1201fd600                        mov    eax,ds:0xd61f20
0x7c1e1c  33c5                              xor    eax,ebp
0x7c1e1e  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x7c1e21  53                                push   ebx
0x7c1e22  57                                push   edi
0x7c1e23  50                                push   eax
0x7c1e24  8d45f4                            lea    eax,[ebp-0xc]
0x7c1e27  64a300000000                      mov    fs:0x0,eax
0x7c1e2d  33db                              xor    ebx,ebx
0x7c1e2f  8bc6                              mov    eax,esi
0x7c1e31  c785c8feffff0f000000              mov    DWORD PTR [ebp-0x138],0xf
0x7c1e3b  899dc4feffff                      mov    DWORD PTR [ebp-0x13c],ebx
0x7c1e41  889db4feffff                      mov    BYTE PTR [ebp-0x14c],bl
0x7c1e47  8d5001                            lea    edx,[eax+0x1]
0x7c1e4a  8d9b00000000                      lea    ebx,[ebx+0x0]
0x7c1e50  8a08                              mov    cl,BYTE PTR [eax]
0x7c1e52  40                                inc    eax
0x7c1e53  3acb                              cmp    cl,bl
0x7c1e55  75f9                              jne    0x7c1e50
0x7c1e57  2bc2                              sub    eax,edx
0x7c1e59  50                                push   eax
0x7c1e5a  56                                push   esi
0x7c1e5b  8d8db4feffff                      lea    ecx,[ebp-0x14c]
0x7c1e61  e80a0cc4ff                        call   0x402a70
0x7c1e66  6a04                              push   0x4
0x7c1e68  6834fdc400                        push   0xc4fd34
0x7c1e6d  8d8db4feffff                      lea    ecx,[ebp-0x14c]
0x7c1e73  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x7c1e76  e84501c4ff                        call   0x401fc0
0x7c1e7b  83bdc8feffff10                    cmp    DWORD PTR [ebp-0x138],0x10
0x7c1e82  8bbdb4feffff                      mov    edi,DWORD PTR [ebp-0x14c]
0x7c1e88  7306                              jae    0x7c1e90
0x7c1e8a  8dbdb4feffff                      lea    edi,[ebp-0x14c]
0x7c1e90  f605f81dfe0001                    test   BYTE PTR ds:0xfe1df8,0x1
0x7c1e97  7520                              jne    0x7c1eb9
0x7c1e99  830df81dfe0001                    or     DWORD PTR ds:0xfe1df8,0x1
0x7c1ea0  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x7c1ea4  e8374df5ff                        call   0x716be0
0x7c1ea9  68a0f1bc00                        push   0xbcf1a0
0x7c1eae  e867040d00                        call   0x89231a
0x7c1eb3  83c404                            add    esp,0x4
0x7c1eb6  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x7c1eb9  57                                push   edi
0x7c1eba  b9e8f2c400                        mov    ecx,0xc4f2e8
0x7c1ebf  bafc1dfe00                        mov    edx,0xfe1dfc
0x7c1ec4  e87748f5ff                        call   0x716740
0x7c1ec9  85c0                              test   eax,eax
0x7c1ecb  0f84dc000000                      je     0x7c1fad

; literal_fld_suffix | exact .fld suffix
; VA 0xc4fd34..0xc4fd39 raw 0x84e334 SHA256 9f2094ff8574379752c84a2ef867a32ab4627074f15be45794e2a9e6ae12f170
db 2e666c6400

; literal_map_group | exact MAP_FLD group
; VA 0xc4f2e8..0xc4f2f0 raw 0x84d8e8 SHA256 93f94fe4da25db58e9586b3287bd395274f7300a9ae9efc4e60624c4e0343692
db 4d41505f464c4400

; tutorial_insert_point_public | public insertion delegates low-level lookup; no new Lua point handle
; VA 0x4a9430..0x4a9457 raw 0xa8830 SHA256 2fea30ffd6350fc424a6b322f5712e91871dba60e0e9bc424d68befcbb2dd975
0x4a9430  55                                push   ebp
0x4a9431  8bec                              mov    ebp,esp
0x4a9433  51                                push   ecx
0x4a9434  56                                push   esi
0x4a9435  8b35a4a7fb00                      mov    esi,DWORD PTR ds:0xfba7a4
0x4a943b  57                                push   edi
0x4a943c  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x4a943f  57                                push   edi
0x4a9440  e87bfcffff                        call   0x4a90c0
0x4a9445  85c0                              test   eax,eax
0x4a9447  7507                              jne    0x4a9450
0x4a9449  8984beb4000000                    mov    DWORD PTR [esi+edi*4+0xb4],eax
0x4a9450  5f                                pop    edi
0x4a9451  5e                                pop    esi
0x4a9452  59                                pop    ecx
0x4a9453  5d                                pop    ebp
0x4a9454  c20400                            ret    0x4

; tutorial_point_table_create | table low-WORD key lookup, category 4 construction, effect request, manager insertion
; VA 0x4a90c0..0x4a9259 raw 0xa84c0 SHA256 b8660be3cd57b0db20676dc33f17f6743afa3e5acb01f18891d1352e721a1cbf
0x4a90c0  55                                push   ebp
0x4a90c1  8bec                              mov    ebp,esp
0x4a90c3  6aff                              push   0xffffffff
0x4a90c5  68879f9200                        push   0x929f87
0x4a90ca  64a100000000                      mov    eax,fs:0x0
0x4a90d0  50                                push   eax
0x4a90d1  83ec08                            sub    esp,0x8
0x4a90d4  53                                push   ebx
0x4a90d5  56                                push   esi
0x4a90d6  57                                push   edi
0x4a90d7  a1201fd600                        mov    eax,ds:0xd61f20
0x4a90dc  33c5                              xor    eax,ebp
0x4a90de  50                                push   eax
0x4a90df  8d45f4                            lea    eax,[ebp-0xc]
0x4a90e2  64a300000000                      mov    fs:0x0,eax
0x4a90e8  0fb74508                          movzx  eax,WORD PTR [ebp+0x8]
0x4a90ec  8bf1                              mov    esi,ecx
0x4a90ee  8d4dec                            lea    ecx,[ebp-0x14]
0x4a90f1  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x4a90f4  51                                push   ecx
0x4a90f5  8d4e24                            lea    ecx,[esi+0x24]
0x4a90f8  8d45f0                            lea    eax,[ebp-0x10]
0x4a90fb  e830140000                        call   0x4aa530
0x4a9100  8b7628                            mov    esi,DWORD PTR [esi+0x28]
0x4a9103  8b7df0                            mov    edi,DWORD PTR [ebp-0x10]
0x4a9106  3bfe                              cmp    edi,esi
0x4a9108  0f8435010000                      je     0x4a9243
0x4a910e  83c710                            add    edi,0x10
0x4a9111  33f6                              xor    esi,esi
0x4a9113  3bfe                              cmp    edi,esi
0x4a9115  0f8428010000                      je     0x4a9243
0x4a911b  6808010000                        push   0x108
0x4a9120  e843813e00                        call   0x891268
0x4a9125  83c404                            add    esp,0x4
0x4a9128  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x4a912b  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x4a912e  3bc6                              cmp    eax,esi
0x4a9130  7420                              je     0x4a9152
0x4a9132  8b5710                            mov    edx,DWORD PTR [edi+0x10]
0x4a9135  d9470c                            fld    DWORD PTR [edi+0xc]
0x4a9138  56                                push   esi
0x4a9139  52                                push   edx
0x4a913a  0fb75702                          movzx  edx,WORD PTR [edi+0x2]
0x4a913e  6a01                              push   0x1
0x4a9140  51                                push   ecx
0x4a9141  8d4f04                            lea    ecx,[edi+0x4]
0x4a9144  d91c24                            fstp   DWORD PTR [esp]
0x4a9147  52                                push   edx
0x4a9148  6a04                              push   0x4
0x4a914a  50                                push   eax
0x4a914b  e8b0a50900                        call   0x543700
0x4a9150  8bf0                              mov    esi,eax
0x4a9152  83cbff                            or     ebx,0xffffffff
0x4a9155  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x4a9158  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
0x4a915f  7523                              jne    0x4a9184
0x4a9161  b801000000                        mov    eax,0x1
0x4a9166  09052888fb00                      or     DWORD PTR ds:0xfb8828,eax
0x4a916c  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x4a916f  e8dc660a00                        call   0x54f850
0x4a9174  6880d5bc00                        push   0xbcd580
0x4a9179  e89c913e00                        call   0x89231a
0x4a917e  83c404                            add    esp,0x4
0x4a9181  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x4a9184  837f2810                          cmp    DWORD PTR [edi+0x28],0x10
0x4a9188  f30f1005bc90fb00                  movss  xmm0,DWORD PTR ds:0xfb90bc
0x4a9190  8d4714                            lea    eax,[edi+0x14]
0x4a9193  f30f1145f0                        movss  DWORD PTR [ebp-0x10],xmm0
0x4a9198  7202                              jb     0x4a919c
0x4a919a  8b00                              mov    eax,DWORD PTR [eax]
0x4a919c  f605dcf6fd0001                    test   BYTE PTR ds:0xfdf6dc,0x1
0x4a91a3  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x4a91a6  7523                              jne    0x4a91cb
0x4a91a8  830ddcf6fd0001                    or     DWORD PTR ds:0xfdf6dc,0x1
0x4a91af  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x4a91b6  e865760a00                        call   0x550820
0x4a91bb  68b0e6bc00                        push   0xbce6b0
0x4a91c0  e855913e00                        call   0x89231a
0x4a91c5  83c404                            add    esp,0x4
0x4a91c8  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x4a91cb  8b16                              mov    edx,DWORD PTR [esi]
0x4a91cd  8b424c                            mov    eax,DWORD PTR [edx+0x4c]
0x4a91d0  8bce                              mov    ecx,esi
0x4a91d2  ffd0                              call   eax
0x4a91d4  d9470c                            fld    DWORD PTR [edi+0xc]
0x4a91d7  d84df0                            fmul   DWORD PTR [ebp-0x10]
0x4a91da  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
0x4a91dd  6aff                              push   0xffffffff
0x4a91df  6aff                              push   0xffffffff
0x4a91e1  ba80f6fd00                        mov    edx,0xfdf680
0x4a91e6  d95df0                            fstp   DWORD PTR [ebp-0x10]
0x4a91e9  8bd8                              mov    ebx,eax
0x4a91eb  e890890a00                        call   0x551b80
0x4a91f0  d945f0                            fld    DWORD PTR [ebp-0x10]
0x4a91f3  6a00                              push   0x0
0x4a91f5  83ec08                            sub    esp,0x8
0x4a91f8  d95c2404                          fstp   DWORD PTR [esp+0x4]
0x4a91fc  8bc8                              mov    ecx,eax
0x4a91fe  d9ee                              fldz
0x4a9200  d91c24                            fstp   DWORD PTR [esp]
0x4a9203  53                                push   ebx
0x4a9204  6a00                              push   0x0
0x4a9206  6880f6fd00                        push   0xfdf680
0x4a920b  e8c08b0a00                        call   0x551dd0
0x4a9210  50                                push   eax
0x4a9211  56                                push   esi
0x4a9212  e8d9b50900                        call   0x5447f0
0x4a9217  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x4a921a  e831b0f8ff                        call   0x434250
0x4a921f  8d7804                            lea    edi,[eax+0x4]
0x4a9222  8d45f0                            lea    eax,[ebp-0x10]
0x4a9225  e8e6aaf9ff                        call   0x443d10
0x4a922a  b801000000                        mov    eax,0x1
0x4a922f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4a9232  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4a9239  59                                pop    ecx
0x4a923a  5f                                pop    edi
0x4a923b  5e                                pop    esi
0x4a923c  5b                                pop    ebx
0x4a923d  8be5                              mov    esp,ebp
0x4a923f  5d                                pop    ebp
0x4a9240  c20400                            ret    0x4
0x4a9243  33c0                              xor    eax,eax
0x4a9245  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4a9248  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4a924f  59                                pop    ecx
0x4a9250  5f                                pop    edi
0x4a9251  5e                                pop    esi
0x4a9252  5b                                pop    ebx
0x4a9253  8be5                              mov    esp,ebp
0x4a9255  5d                                pop    ebp
0x4a9256  c20400                            ret    0x4

; fixed_book_paths | four exact Synopsis/book01..04.gb3 literals used in pinned book_constructor
; VA 0xc11098..0xc110e8 raw 0x80f698 SHA256 7021890572de3b834abedbcacc5b7a00e935d9c1275674f9a29bb8cb789b7a38
db 53796e6f707369732f626f6f6b30312e6762330053796e6f707369732f626f6f6b30322e6762330053796e6f707369732f626f6f6b30332e6762330053796e6f707369732f626f6f6b30342e67623300

; effect_category_lookup | category-name lookup, negative subcategory clamps0, selected effect entry resolves through effect-id map; does not prove payload materialization
; VA 0x551b80..0x551cc2 raw 0x150f80 SHA256 b5ca0c9d685fe3de66417486b680c14039ef28c736c5f8cff1538918e3296508
0x551b80  55                                push   ebp
0x551b81  8bec                              mov    ebp,esp
0x551b83  6aff                              push   0xffffffff
0x551b85  68f84b9100                        push   0x914bf8
0x551b8a  64a100000000                      mov    eax,fs:0x0
0x551b90  50                                push   eax
0x551b91  83ec28                            sub    esp,0x28
0x551b94  a1201fd600                        mov    eax,ds:0xd61f20
0x551b99  33c5                              xor    eax,ebp
0x551b9b  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x551b9e  53                                push   ebx
0x551b9f  56                                push   esi
0x551ba0  57                                push   edi
0x551ba1  50                                push   eax
0x551ba2  8d45f4                            lea    eax,[ebp-0xc]
0x551ba5  64a300000000                      mov    fs:0x0,eax
0x551bab  33db                              xor    ebx,ebx
0x551bad  8bfa                              mov    edi,edx
0x551baf  8bc1                              mov    eax,ecx
0x551bb1  897dcc                            mov    DWORD PTR [ebp-0x34],edi
0x551bb4  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
0x551bbb  895de4                            mov    DWORD PTR [ebp-0x1c],ebx
0x551bbe  885dd4                            mov    BYTE PTR [ebp-0x2c],bl
0x551bc1  8d7001                            lea    esi,[eax+0x1]
0x551bc4  8a10                              mov    dl,BYTE PTR [eax]
0x551bc6  40                                inc    eax
0x551bc7  3ad3                              cmp    dl,bl
0x551bc9  75f9                              jne    0x551bc4
0x551bcb  2bc6                              sub    eax,esi
0x551bcd  50                                push   eax
0x551bce  51                                push   ecx
0x551bcf  8d4dd4                            lea    ecx,[ebp-0x2c]
0x551bd2  e8990eebff                        call   0x402a70
0x551bd7  8d45d4                            lea    eax,[ebp-0x2c]
0x551bda  50                                push   eax
0x551bdb  8d4dd0                            lea    ecx,[ebp-0x30]
0x551bde  51                                push   ecx
0x551bdf  8d4730                            lea    eax,[edi+0x30]
0x551be2  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x551be5  e816080000                        call   0x552400
0x551bea  837de810                          cmp    DWORD PTR [ebp-0x18],0x10
0x551bee  720c                              jb     0x551bfc
0x551bf0  8b55d4                            mov    edx,DWORD PTR [ebp-0x2c]
0x551bf3  52                                push   edx
0x551bf4  e813f63300                        call   0x89120c
0x551bf9  83c404                            add    esp,0x4
0x551bfc  8b45d0                            mov    eax,DWORD PTR [ebp-0x30]
0x551bff  3b4734                            cmp    eax,DWORD PTR [edi+0x34]
0x551c02  7507                              jne    0x551c0b
0x551c04  33c0                              xor    eax,eax
0x551c06  e999000000                        jmp    0x551ca4
0x551c0b  395d08                            cmp    DWORD PTR [ebp+0x8],ebx
0x551c0e  7d03                              jge    0x551c13
0x551c10  895d08                            mov    DWORD PTR [ebp+0x8],ebx
0x551c13  8b7024                            mov    esi,DWORD PTR [eax+0x24]
0x551c16  8d4508                            lea    eax,[ebp+0x8]
0x551c19  50                                push   eax
0x551c1a  8d45d0                            lea    eax,[ebp-0x30]
0x551c1d  8bce                              mov    ecx,esi
0x551c1f  e89c1c2f00                        call   0x8438c0
0x551c24  8b45d0                            mov    eax,DWORD PTR [ebp-0x30]
0x551c27  3b4604                            cmp    eax,DWORD PTR [esi+0x4]
0x551c2a  74d8                              je     0x551c04
0x551c2c  8b7010                            mov    esi,DWORD PTR [eax+0x10]
0x551c2f  8b7e08                            mov    edi,DWORD PTR [esi+0x8]
0x551c32  3bfb                              cmp    edi,ebx
0x551c34  74ce                              je     0x551c04
0x551c36  395d0c                            cmp    DWORD PTR [ebp+0xc],ebx
0x551c39  7d33                              jge    0x551c6e
0x551c3b  837e1001                          cmp    DWORD PTR [esi+0x10],0x1
0x551c3f  7526                              jne    0x551c67
0x551c41  e8570c3400                        call   0x89289d
0x551c46  99                                cdq
0x551c47  f7ff                              idiv   edi
0x551c49  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
0x551c4c  8b01                              mov    eax,DWORD PTR [ecx]
0x551c4e  8945d0                            mov    DWORD PTR [ebp-0x30],eax
0x551c51  3bd3                              cmp    edx,ebx
0x551c53  7e29                              jle    0x551c7e
0x551c55  8bfa                              mov    edi,edx
0x551c57  8d45d0                            lea    eax,[ebp-0x30]
0x551c5a  e841caf4ff                        call   0x49e6a0
0x551c5f  4f                                dec    edi
0x551c60  75f5                              jne    0x551c57
0x551c62  8b45d0                            mov    eax,DWORD PTR [ebp-0x30]
0x551c65  eb17                              jmp    0x551c7e
0x551c67  8b5604                            mov    edx,DWORD PTR [esi+0x4]
0x551c6a  8b02                              mov    eax,DWORD PTR [edx]
0x551c6c  eb10                              jmp    0x551c7e
0x551c6e  8d450c                            lea    eax,[ebp+0xc]
0x551c71  50                                push   eax
0x551c72  8d45d0                            lea    eax,[ebp-0x30]
0x551c75  8bce                              mov    ecx,esi
0x551c77  e8441c2f00                        call   0x8438c0
0x551c7c  8b00                              mov    eax,DWORD PTR [eax]
0x551c7e  3b4604                            cmp    eax,DWORD PTR [esi+0x4]
0x551c81  7481                              je     0x551c04
0x551c83  8b75cc                            mov    esi,DWORD PTR [ebp-0x34]
0x551c86  83c010                            add    eax,0x10
0x551c89  50                                push   eax
0x551c8a  8d4e10                            lea    ecx,[esi+0x10]
0x551c8d  8d45cc                            lea    eax,[ebp-0x34]
0x551c90  e82b1c2f00                        call   0x8438c0
0x551c95  8b45cc                            mov    eax,DWORD PTR [ebp-0x34]
0x551c98  3b4614                            cmp    eax,DWORD PTR [esi+0x14]
0x551c9b  0f8463ffffff                      je     0x551c04
0x551ca1  8b4010                            mov    eax,DWORD PTR [eax+0x10]
0x551ca4  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x551ca7  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x551cae  59                                pop    ecx
0x551caf  5f                                pop    edi
0x551cb0  5e                                pop    esi
0x551cb1  5b                                pop    ebx
0x551cb2  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0x551cb5  33cd                              xor    ecx,ebp
0x551cb7  e845f33300                        call   0x891001
0x551cbc  8be5                              mov    esp,ebp
0x551cbe  5d                                pop    ebp
0x551cbf  c20800                            ret    0x8
