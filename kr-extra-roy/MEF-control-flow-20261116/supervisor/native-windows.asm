; coroutine_create 0x707380..0x707444 raw 0x306780 SHA256 b9caa25028e918ccc8c1d80cdbb8b851890b0ff666ff9c74faf4223d5e3a8129
; Original Lua closure validation, new thread and TValue transfer; R6/R9 reused ABI
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

; new_thread 0x6f7390..0x6f7457 raw 0x2f6790 SHA256 90eda11f96b8dc1ee811b9bdf2a847035276d8c5bad277364e53f2d19ca73237
; Separate lua_State allocation, shared global_State/environment, inherited hooks
0x6f7390  55                                push   ebp
0x6f7391  8bec                              mov    ebp,esp
0x6f7393  83e4f8                            and    esp,0xfffffff8
0x6f7396  51                                push   ecx
0x6f7397  53                                push   ebx
0x6f7398  56                                push   esi
0x6f7399  57                                push   edi
0x6f739a  6a78                              push   0x78
0x6f739c  8bf8                              mov    edi,eax
0x6f739e  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x6f73a1  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x6f73a4  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0x6f73a7  33db                              xor    ebx,ebx
0x6f73a9  53                                push   ebx
0x6f73aa  53                                push   ebx
0x6f73ab  51                                push   ecx
0x6f73ac  8944241c                          mov    DWORD PTR [esp+0x1c],eax
0x6f73b0  ffd2                              call   edx
0x6f73b2  8bf0                              mov    esi,eax
0x6f73b4  83c410                            add    esp,0x10
0x6f73b7  3bf3                              cmp    esi,ebx
0x6f73b9  7508                              jne    0x6f73c3
0x6f73bb  6a04                              push   0x4
0x6f73bd  57                                push   edi
0x6f73be  e87d670000                        call   0x6fdb40
0x6f73c3  8b44240c                          mov    eax,DWORD PTR [esp+0xc]
0x6f73c7  83404478                          add    DWORD PTR [eax+0x44],0x78
0x6f73cb  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x6f73ce  8b481c                            mov    ecx,DWORD PTR [eax+0x1c]
0x6f73d1  890e                              mov    DWORD PTR [esi],ecx
0x6f73d3  8a5014                            mov    dl,BYTE PTR [eax+0x14]
0x6f73d6  89701c                            mov    DWORD PTR [eax+0x1c],esi
0x6f73d9  80e203                            and    dl,0x3
0x6f73dc  885605                            mov    BYTE PTR [esi+0x5],dl
0x6f73df  c6460408                          mov    BYTE PTR [esi+0x4],0x8
0x6f73e3  8b4710                            mov    eax,DWORD PTR [edi+0x10]
0x6f73e6  33d2                              xor    edx,edx
0x6f73e8  894610                            mov    DWORD PTR [esi+0x10],eax
0x6f73eb  895e20                            mov    DWORD PTR [esi+0x20],ebx
0x6f73ee  895e2c                            mov    DWORD PTR [esi+0x2c],ebx
0x6f73f1  895e70                            mov    DWORD PTR [esi+0x70],ebx
0x6f73f4  895e44                            mov    DWORD PTR [esi+0x44],ebx
0x6f73f7  895e3c                            mov    DWORD PTR [esi+0x3c],ebx
0x6f73fa  895e40                            mov    DWORD PTR [esi+0x40],ebx
0x6f73fd  895e68                            mov    DWORD PTR [esi+0x68],ebx
0x6f7400  895e30                            mov    DWORD PTR [esi+0x30],ebx
0x6f7403  c7463600000001                    mov    DWORD PTR [esi+0x36],0x1000000
0x6f740a  66895634                          mov    WORD PTR [esi+0x34],dx
0x6f740e  885e06                            mov    BYTE PTR [esi+0x6],bl
0x6f7411  895e14                            mov    DWORD PTR [esi+0x14],ebx
0x6f7414  895e28                            mov    DWORD PTR [esi+0x28],ebx
0x6f7417  895e18                            mov    DWORD PTR [esi+0x18],ebx
0x6f741a  895e74                            mov    DWORD PTR [esi+0x74],ebx
0x6f741d  895e50                            mov    DWORD PTR [esi+0x50],ebx
0x6f7420  e8dbfdffff                        call   0x6f7200
0x6f7425  8b4748                            mov    eax,DWORD PTR [edi+0x48]
0x6f7428  894648                            mov    DWORD PTR [esi+0x48],eax
0x6f742b  8b4f4c                            mov    ecx,DWORD PTR [edi+0x4c]
0x6f742e  894e4c                            mov    DWORD PTR [esi+0x4c],ecx
0x6f7431  8b5750                            mov    edx,DWORD PTR [edi+0x50]
0x6f7434  895650                            mov    DWORD PTR [esi+0x50],edx
0x6f7437  8a4738                            mov    al,BYTE PTR [edi+0x38]
0x6f743a  884638                            mov    BYTE PTR [esi+0x38],al
0x6f743d  8b4f3c                            mov    ecx,DWORD PTR [edi+0x3c]
0x6f7440  894e3c                            mov    DWORD PTR [esi+0x3c],ecx
0x6f7443  8b5744                            mov    edx,DWORD PTR [edi+0x44]
0x6f7446  8bc1                              mov    eax,ecx
0x6f7448  894640                            mov    DWORD PTR [esi+0x40],eax
0x6f744b  5f                                pop    edi
0x6f744c  895644                            mov    DWORD PTR [esi+0x44],edx
0x6f744f  8bc6                              mov    eax,esi
0x6f7451  5e                                pop    esi
0x6f7452  5b                                pop    ebx
0x6f7453  8be5                              mov    esp,ebp
0x6f7455  5d                                pop    ebp
0x6f7456  c3                                ret

; coroutine_resume 0x707230..0x7072c3 raw 0x306630 SHA256 668e607225404c727034e012df371f32c3787ed7f9de7156e57743a93a5e1877
; Public resume argument count and Boolean/result tuple
0x707230  55                                push   ebp
0x707231  8bec                              mov    ebp,esp
0x707233  56                                push   esi
0x707234  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x707237  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x70723a  57                                push   edi
0x70723b  3b4608                            cmp    eax,DWORD PTR [esi+0x8]
0x70723e  7205                              jb     0x707245
0x707240  b8c8bfc000                        mov    eax,0xc0bfc8
0x707245  83780808                          cmp    DWORD PTR [eax+0x8],0x8
0x707249  53                                push   ebx
0x70724a  7404                              je     0x707250
0x70724c  33db                              xor    ebx,ebx
0x70724e  eb06                              jmp    0x707256
0x707250  8b18                              mov    ebx,DWORD PTR [eax]
0x707252  85db                              test   ebx,ebx
0x707254  750f                              jne    0x707265
0x707256  6a01                              push   0x1
0x707258  bf8c36c400                        mov    edi,0xc4368c
0x70725d  e83eebfeff                        call   0x6f5da0
0x707262  83c404                            add    esp,0x4
0x707265  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x707268  2b460c                            sub    eax,DWORD PTR [esi+0xc]
0x70726b  c1f804                            sar    eax,0x4
0x70726e  48                                dec    eax
0x70726f  50                                push   eax
0x707270  53                                push   ebx
0x707271  56                                push   esi
0x707272  e899feffff                        call   0x707110
0x707277  8bf8                              mov    edi,eax
0x707279  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x70727c  83c40c                            add    esp,0xc
0x70727f  5b                                pop    ebx
0x707280  c7400801000000                    mov    DWORD PTR [eax+0x8],0x1
0x707287  85ff                              test   edi,edi
0x707289  791d                              jns    0x7072a8
0x70728b  c70000000000                      mov    DWORD PTR [eax],0x0
0x707291  83460810                          add    DWORD PTR [esi+0x8],0x10
0x707295  b8feffffff                        mov    eax,0xfffffffe
0x70729a  e811e0feff                        call   0x6f52b0
0x70729f  5f                                pop    edi
0x7072a0  b802000000                        mov    eax,0x2
0x7072a5  5e                                pop    esi
0x7072a6  5d                                pop    ebp
0x7072a7  c3                                ret
0x7072a8  c70001000000                      mov    DWORD PTR [eax],0x1
0x7072ae  83460810                          add    DWORD PTR [esi+0x8],0x10
0x7072b2  83c8ff                            or     eax,0xffffffff
0x7072b5  2bc7                              sub    eax,edi
0x7072b7  e8f4dffeff                        call   0x6f52b0
0x7072bc  8d4701                            lea    eax,[edi+0x1]
0x7072bf  5f                                pop    edi
0x7072c0  5e                                pop    esi
0x7072c1  5d                                pop    ebp
0x7072c2  c3                                ret

; auxresume 0x707110..0x70722b raw 0x306510 SHA256 21492a7e104977743063df4ab1636edf432f6853c68a30720ea65a2e5e136587
; State admission, argument/result/error movement and copied C-depth
0x707110  55                                push   ebp
0x707111  8bec                              mov    ebp,esp
0x707113  83ec64                            sub    esp,0x64
0x707116  53                                push   ebx
0x707117  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
0x70711a  56                                push   esi
0x70711b  57                                push   edi
0x70711c  395d08                            cmp    DWORD PTR [ebp+0x8],ebx
0x70711f  7504                              jne    0x707125
0x707121  33ff                              xor    edi,edi
0x707123  eb44                              jmp    0x707169
0x707125  0fb64306                          movzx  eax,BYTE PTR [ebx+0x6]
0x707129  83e800                            sub    eax,0x0
0x70712c  7411                              je     0x70713f
0x70712e  48                                dec    eax
0x70712f  7407                              je     0x707138
0x707131  bf03000000                        mov    edi,0x3
0x707136  eb31                              jmp    0x707169
0x707138  bf01000000                        mov    edi,0x1
0x70713d  eb2a                              jmp    0x707169
0x70713f  8d7d9c                            lea    edi,[ebp-0x64]
0x707142  33c9                              xor    ecx,ecx
0x707144  8bd3                              mov    edx,ebx
0x707146  e8850cffff                        call   0x6f7dd0
0x70714b  85c0                              test   eax,eax
0x70714d  7e07                              jle    0x707156
0x70714f  bf02000000                        mov    edi,0x2
0x707154  eb13                              jmp    0x707169
0x707156  8b7b08                            mov    edi,DWORD PTR [ebx+0x8]
0x707159  2b7b0c                            sub    edi,DWORD PTR [ebx+0xc]
0x70715c  83e7f0                            and    edi,0xfffffff0
0x70715f  f7df                              neg    edi
0x707161  1bff                              sbb    edi,edi
0x707163  83e7fe                            and    edi,0xfffffffe
0x707166  83c703                            add    edi,0x3
0x707169  8b7510                            mov    esi,DWORD PTR [ebp+0x10]
0x70716c  8bc6                              mov    eax,esi
0x70716e  8bcb                              mov    ecx,ebx
0x707170  e8fbdffeff                        call   0x6f5170
0x707175  85c0                              test   eax,eax
0x707177  7511                              jne    0x70718a
0x707179  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x70717c  68a036c400                        push   0xc436a0
0x707181  50                                push   eax
0x707182  e8a9edfeff                        call   0x6f5f30
0x707187  83c408                            add    esp,0x8
0x70718a  83ff01                            cmp    edi,0x1
0x70718d  7423                              je     0x7071b2
0x70718f  8b0cbd58bcc000                    mov    ecx,DWORD PTR [edi*4+0xc0bc58]
0x707196  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x707199  51                                push   ecx
0x70719a  68c036c400                        push   0xc436c0
0x70719f  52                                push   edx
0x7071a0  e8dbe3feff                        call   0x6f5580
0x7071a5  83c40c                            add    esp,0xc
0x7071a8  5f                                pop    edi
0x7071a9  5e                                pop    esi
0x7071aa  83c8ff                            or     eax,0xffffffff
0x7071ad  5b                                pop    ebx
0x7071ae  8be5                              mov    esp,ebp
0x7071b0  5d                                pop    ebp
0x7071b1  c3                                ret
0x7071b2  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x7071b5  8bc6                              mov    eax,esi
0x7071b7  8bf3                              mov    esi,ebx
0x7071b9  e812e0feff                        call   0x6f51d0
0x7071be  8b4d10                            mov    ecx,DWORD PTR [ebp+0x10]
0x7071c1  8bf7                              mov    esi,edi
0x7071c3  668b4634                          mov    ax,WORD PTR [esi+0x34]
0x7071c7  66894334                          mov    WORD PTR [ebx+0x34],ax
0x7071cb  8bc3                              mov    eax,ebx
0x7071cd  e8fe74ffff                        call   0x6fe6d0
0x7071d2  85c0                              test   eax,eax
0x7071d4  741b                              je     0x7071f1
0x7071d6  83f801                            cmp    eax,0x1
0x7071d9  7416                              je     0x7071f1
0x7071db  b801000000                        mov    eax,0x1
0x7071e0  8bfb                              mov    edi,ebx
0x7071e2  e8e9dffeff                        call   0x6f51d0
0x7071e7  5f                                pop    edi
0x7071e8  5e                                pop    esi
0x7071e9  83c8ff                            or     eax,0xffffffff
0x7071ec  5b                                pop    ebx
0x7071ed  8be5                              mov    esp,ebp
0x7071ef  5d                                pop    ebp
0x7071f0  c3                                ret
0x7071f1  8b7b08                            mov    edi,DWORD PTR [ebx+0x8]
0x7071f4  2b7b0c                            sub    edi,DWORD PTR [ebx+0xc]
0x7071f7  8bce                              mov    ecx,esi
0x7071f9  c1ff04                            sar    edi,0x4
0x7071fc  8bc7                              mov    eax,edi
0x7071fe  897d08                            mov    DWORD PTR [ebp+0x8],edi
0x707201  e86adffeff                        call   0x6f5170
0x707206  85c0                              test   eax,eax
0x707208  750e                              jne    0x707218
0x70720a  68dc36c400                        push   0xc436dc
0x70720f  56                                push   esi
0x707210  e81bedfeff                        call   0x6f5f30
0x707215  83c408                            add    esp,0x8
0x707218  8bc7                              mov    eax,edi
0x70721a  8bfb                              mov    edi,ebx
0x70721c  e8afdffeff                        call   0x6f51d0
0x707221  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x707224  5f                                pop    edi
0x707225  5e                                pop    esi
0x707226  5b                                pop    ebx
0x707227  8be5                              mov    esp,ebp
0x707229  5d                                pop    ebp
0x70722a  c3                                ret

; coroutine_status 0x707070..0x707110 raw 0x306470 SHA256 9905344d94c8ee47a4a76e332496963315c948da5256334cb5590bd894fea54e
; running/suspended/normal/dead classification on actual thread state
0x707070  55                                push   ebp
0x707071  8bec                              mov    ebp,esp
0x707073  83ec64                            sub    esp,0x64
0x707076  53                                push   ebx
0x707077  56                                push   esi
0x707078  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x70707b  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x70707e  57                                push   edi
0x70707f  3b4608                            cmp    eax,DWORD PTR [esi+0x8]
0x707082  7205                              jb     0x707089
0x707084  b8c8bfc000                        mov    eax,0xc0bfc8
0x707089  83780808                          cmp    DWORD PTR [eax+0x8],0x8
0x70708d  7404                              je     0x707093
0x70708f  33db                              xor    ebx,ebx
0x707091  eb06                              jmp    0x707099
0x707093  8b18                              mov    ebx,DWORD PTR [eax]
0x707095  85db                              test   ebx,ebx
0x707097  750f                              jne    0x7070a8
0x707099  6a01                              push   0x1
0x70709b  bf8c36c400                        mov    edi,0xc4368c
0x7070a0  e8fbecfeff                        call   0x6f5da0
0x7070a5  83c404                            add    esp,0x4
0x7070a8  3bf3                              cmp    esi,ebx
0x7070aa  7504                              jne    0x7070b0
0x7070ac  33c0                              xor    eax,eax
0x7070ae  eb44                              jmp    0x7070f4
0x7070b0  0fb64306                          movzx  eax,BYTE PTR [ebx+0x6]
0x7070b4  83e800                            sub    eax,0x0
0x7070b7  7411                              je     0x7070ca
0x7070b9  48                                dec    eax
0x7070ba  7407                              je     0x7070c3
0x7070bc  b803000000                        mov    eax,0x3
0x7070c1  eb31                              jmp    0x7070f4
0x7070c3  b801000000                        mov    eax,0x1
0x7070c8  eb2a                              jmp    0x7070f4
0x7070ca  8d7d9c                            lea    edi,[ebp-0x64]
0x7070cd  33c9                              xor    ecx,ecx
0x7070cf  8bd3                              mov    edx,ebx
0x7070d1  e8fa0cffff                        call   0x6f7dd0
0x7070d6  85c0                              test   eax,eax
0x7070d8  7e07                              jle    0x7070e1
0x7070da  b802000000                        mov    eax,0x2
0x7070df  eb13                              jmp    0x7070f4
0x7070e1  8b4308                            mov    eax,DWORD PTR [ebx+0x8]
0x7070e4  2b430c                            sub    eax,DWORD PTR [ebx+0xc]
0x7070e7  83e0f0                            and    eax,0xfffffff0
0x7070ea  f7d8                              neg    eax
0x7070ec  1bc0                              sbb    eax,eax
0x7070ee  83e0fe                            and    eax,0xfffffffe
0x7070f1  83c003                            add    eax,0x3
0x7070f4  8b048558bcc000                    mov    eax,DWORD PTR [eax*4+0xc0bc58]
0x7070fb  50                                push   eax
0x7070fc  e80fe4feff                        call   0x6f5510
0x707101  83c404                            add    esp,0x4
0x707104  5f                                pop    edi
0x707105  5e                                pop    esi
0x707106  b801000000                        mov    eax,0x1
0x70710b  5b                                pop    ebx
0x70710c  8be5                              mov    esp,ebp
0x70710e  5d                                pop    ebp
0x70710f  c3                                ret

; getstack 0x6f7dd0..0x6f7e3b raw 0x2f71d0 SHA256 6c9bf3a0d8bd92140b1d1bd27f87235fba5837acccbb4ac3e2e4a6fa93309941
; Level-zero CallInfo query used by coroutine status
0x6f7dd0  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x6f7dd3  85c9                              test   ecx,ecx
0x6f7dd5  7e27                              jle    0x6f7dfe
0x6f7dd7  56                                push   esi
0x6f7dd8  8b7228                            mov    esi,DWORD PTR [edx+0x28]
0x6f7ddb  53                                push   ebx
0x6f7ddc  8d642400                          lea    esp,[esp+0x0]
0x6f7de0  3bc6                              cmp    eax,esi
0x6f7de2  7616                              jbe    0x6f7dfa
0x6f7de4  8b5804                            mov    ebx,DWORD PTR [eax+0x4]
0x6f7de7  8b1b                              mov    ebx,DWORD PTR [ebx]
0x6f7de9  49                                dec    ecx
0x6f7dea  807b0600                          cmp    BYTE PTR [ebx+0x6],0x0
0x6f7dee  7503                              jne    0x6f7df3
0x6f7df0  2b4814                            sub    ecx,DWORD PTR [eax+0x14]
0x6f7df3  83e818                            sub    eax,0x18
0x6f7df6  85c9                              test   ecx,ecx
0x6f7df8  7fe6                              jg     0x6f7de0
0x6f7dfa  5b                                pop    ebx
0x6f7dfb  5e                                pop    esi
0x6f7dfc  85c9                              test   ecx,ecx
0x6f7dfe  7527                              jne    0x6f7e27
0x6f7e00  8b5228                            mov    edx,DWORD PTR [edx+0x28]
0x6f7e03  3bc2                              cmp    eax,edx
0x6f7e05  7631                              jbe    0x6f7e38
0x6f7e07  2bc2                              sub    eax,edx
0x6f7e09  8bd0                              mov    edx,eax
0x6f7e0b  b8abaaaa2a                        mov    eax,0x2aaaaaab
0x6f7e10  f7ea                              imul   edx
0x6f7e12  c1fa02                            sar    edx,0x2
0x6f7e15  8bc2                              mov    eax,edx
0x6f7e17  c1e81f                            shr    eax,0x1f
0x6f7e1a  03c2                              add    eax,edx
0x6f7e1c  b901000000                        mov    ecx,0x1
0x6f7e21  894760                            mov    DWORD PTR [edi+0x60],eax
0x6f7e24  8bc1                              mov    eax,ecx
0x6f7e26  c3                                ret
0x6f7e27  85c9                              test   ecx,ecx
0x6f7e29  790d                              jns    0x6f7e38
0x6f7e2b  b801000000                        mov    eax,0x1
0x6f7e30  c7476000000000                    mov    DWORD PTR [edi+0x60],0x0
0x6f7e37  c3                                ret
0x6f7e38  33c0                              xor    eax,eax
0x6f7e3a  c3                                ret

; coroutine_yield 0x707480..0x7074bc raw 0x306880 SHA256 73f97712addbb6eaba1a33e4983ac155d5a3843e670440ac00982b050b297bff
; Current-thread depth check, yielded result base and status=1
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

; coroutine_running 0x7074c0..0x7074f8 raw 0x3068c0 SHA256 65a389498ed7c98b65bc076913d33dbab20b9c17152aa2b2f7c7a48141db99b7
; Incoming current lua_State returned; main thread produces nil
0x7074c0  55                                push   ebp
0x7074c1  8bec                              mov    ebp,esp
0x7074c3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x7074c6  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x7074c9  8901                              mov    DWORD PTR [ecx],eax
0x7074cb  c7410808000000                    mov    DWORD PTR [ecx+0x8],0x8
0x7074d2  56                                push   esi
0x7074d3  8b7010                            mov    esi,DWORD PTR [eax+0x10]
0x7074d6  ba10000000                        mov    edx,0x10
0x7074db  015008                            add    DWORD PTR [eax+0x8],edx
0x7074de  394670                            cmp    DWORD PTR [esi+0x70],eax
0x7074e1  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x7074e4  5e                                pop    esi
0x7074e5  750a                              jne    0x7074f1
0x7074e7  c7410800000000                    mov    DWORD PTR [ecx+0x8],0x0
0x7074ee  015008                            add    DWORD PTR [eax+0x8],edx
0x7074f1  b801000000                        mov    eax,0x1
0x7074f6  5d                                pop    ebp
0x7074f7  c3                                ret

; stack_capacity 0x6f5170..0x6f51c6 raw 0x2f4570 SHA256 23fce7484f889eb158e22acebf423993cedb24aee88a68d953163964aa1e61ec
; Capacity rejection or expansion, outside inner protected body
0x6f5170  56                                push   esi
0x6f5171  8bf1                              mov    esi,ecx
0x6f5173  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6f5176  8bd1                              mov    edx,ecx
0x6f5178  2b560c                            sub    edx,DWORD PTR [esi+0xc]
0x6f517b  c1fa04                            sar    edx,0x4
0x6f517e  03d0                              add    edx,eax
0x6f5180  81faff7f0000                      cmp    edx,0x7fff
0x6f5186  7e04                              jle    0x6f518c
0x6f5188  33c0                              xor    eax,eax
0x6f518a  5e                                pop    esi
0x6f518b  c3                                ret
0x6f518c  8b561c                            mov    edx,DWORD PTR [esi+0x1c]
0x6f518f  57                                push   edi
0x6f5190  8bf8                              mov    edi,eax
0x6f5192  c1e704                            shl    edi,0x4
0x6f5195  2bd1                              sub    edx,ecx
0x6f5197  3bd7                              cmp    edx,edi
0x6f5199  7f13                              jg     0x6f51ae
0x6f519b  8b4e2c                            mov    ecx,DWORD PTR [esi+0x2c]
0x6f519e  3bc1                              cmp    eax,ecx
0x6f51a0  7f05                              jg     0x6f51a7
0x6f51a2  8d0409                            lea    eax,[ecx+ecx*1]
0x6f51a5  eb02                              jmp    0x6f51a9
0x6f51a7  03c1                              add    eax,ecx
0x6f51a9  e8028b0000                        call   0x6fdcb0
0x6f51ae  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6f51b1  8b7614                            mov    esi,DWORD PTR [esi+0x14]
0x6f51b4  03c7                              add    eax,edi
0x6f51b6  5f                                pop    edi
0x6f51b7  394608                            cmp    DWORD PTR [esi+0x8],eax
0x6f51ba  7303                              jae    0x6f51bf
0x6f51bc  894608                            mov    DWORD PTR [esi+0x8],eax
0x6f51bf  b801000000                        mov    eax,0x1
0x6f51c4  5e                                pop    esi
0x6f51c5  c3                                ret

; xmove 0x6f51d0..0x6f521c raw 0x2f45d0 SHA256 e293aee815d4e1fbfcf8dc911f2392dc6c899140f80c5224f3acac11c577e2d0
; Ordered full TValue movement between caller and child stacks
0x6f51d0  55                                push   ebp
0x6f51d1  8bec                              mov    ebp,esp
0x6f51d3  51                                push   ecx
0x6f51d4  3bfe                              cmp    edi,esi
0x6f51d6  7440                              je     0x6f5218
0x6f51d8  8bc8                              mov    ecx,eax
0x6f51da  f7d9                              neg    ecx
0x6f51dc  c1e104                            shl    ecx,0x4
0x6f51df  014f08                            add    DWORD PTR [edi+0x8],ecx
0x6f51e2  85c0                              test   eax,eax
0x6f51e4  7e32                              jle    0x6f5218
0x6f51e6  33d2                              xor    edx,edx
0x6f51e8  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x6f51eb  53                                push   ebx
0x6f51ec  8d642400                          lea    esp,[esp+0x0]
0x6f51f0  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6f51f3  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x6f51f6  8d5910                            lea    ebx,[ecx+0x10]
0x6f51f9  895e08                            mov    DWORD PTR [esi+0x8],ebx
0x6f51fc  8b1c10                            mov    ebx,DWORD PTR [eax+edx*1]
0x6f51ff  8919                              mov    DWORD PTR [ecx],ebx
0x6f5201  8b5c1004                          mov    ebx,DWORD PTR [eax+edx*1+0x4]
0x6f5205  895904                            mov    DWORD PTR [ecx+0x4],ebx
0x6f5208  8b441008                          mov    eax,DWORD PTR [eax+edx*1+0x8]
0x6f520c  83c210                            add    edx,0x10
0x6f520f  ff4dfc                            dec    DWORD PTR [ebp-0x4]
0x6f5212  894108                            mov    DWORD PTR [ecx+0x8],eax
0x6f5215  75d9                              jne    0x6f51f0
0x6f5217  5b                                pop    ebx
0x6f5218  8be5                              mov    esp,ebp
0x6f521a  5d                                pop    ebp
0x6f521b  c3                                ret

; insert_boolean 0x6f52b0..0x6f52f1 raw 0x2f46b0 SHA256 314e560fee5889f24d7da91b71e60ea48db5cc45d7071cf74ffba4ada5cedcfc
; Insert Boolean before moved results without stringifying values
0x6f52b0  8bce                              mov    ecx,esi
0x6f52b2  e839feffff                        call   0x6f50f0
0x6f52b7  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6f52ba  3bc8                              cmp    ecx,eax
0x6f52bc  761f                              jbe    0x6f52dd
0x6f52be  8d51f0                            lea    edx,[ecx-0x10]
0x6f52c1  57                                push   edi
0x6f52c2  8b3a                              mov    edi,DWORD PTR [edx]
0x6f52c4  8939                              mov    DWORD PTR [ecx],edi
0x6f52c6  8b7a04                            mov    edi,DWORD PTR [edx+0x4]
0x6f52c9  897904                            mov    DWORD PTR [ecx+0x4],edi
0x6f52cc  8b7a08                            mov    edi,DWORD PTR [edx+0x8]
0x6f52cf  897a18                            mov    DWORD PTR [edx+0x18],edi
0x6f52d2  83e910                            sub    ecx,0x10
0x6f52d5  83ea10                            sub    edx,0x10
0x6f52d8  3bc8                              cmp    ecx,eax
0x6f52da  77e6                              ja     0x6f52c2
0x6f52dc  5f                                pop    edi
0x6f52dd  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6f52e0  8b11                              mov    edx,DWORD PTR [ecx]
0x6f52e2  8910                              mov    DWORD PTR [eax],edx
0x6f52e4  8b5104                            mov    edx,DWORD PTR [ecx+0x4]
0x6f52e7  895004                            mov    DWORD PTR [eax+0x4],edx
0x6f52ea  8b4908                            mov    ecx,DWORD PTR [ecx+0x8]
0x6f52ed  894808                            mov    DWORD PTR [eax+0x8],ecx
0x6f52f0  c3                                ret

; lua_resume 0x6fe6d0..0x6fe769 raw 0x2fdad0 SHA256 1fca58436f6b5125a28d1b1b27a9069f3bc5944a0557fd2f2b9a860427569c5a
; Child-specific C-depth/base, protected execution, yielded/error return statuses
0x6fe6d0  57                                push   edi
0x6fe6d1  8bf8                              mov    edi,eax
0x6fe6d3  8a4706                            mov    al,BYTE PTR [edi+0x6]
0x6fe6d6  3c01                              cmp    al,0x1
0x6fe6d8  7419                              je     0x6fe6f3
0x6fe6da  84c0                              test   al,al
0x6fe6dc  7508                              jne    0x6fe6e6
0x6fe6de  8b4714                            mov    eax,DWORD PTR [edi+0x14]
0x6fe6e1  3b4728                            cmp    eax,DWORD PTR [edi+0x28]
0x6fe6e4  740d                              je     0x6fe6f3
0x6fe6e6  8bc7                              mov    eax,edi
0x6fe6e8  ba182bc400                        mov    edx,0xc42b18
0x6fe6ed  5f                                pop    edi
0x6fe6ee  e96dffffff                        jmp    0x6fe660
0x6fe6f3  0fb74734                          movzx  eax,WORD PTR [edi+0x34]
0x6fe6f7  bac8000000                        mov    edx,0xc8
0x6fe6fc  663bc2                            cmp    ax,dx
0x6fe6ff  720d                              jb     0x6fe70e
0x6fe701  8bc7                              mov    eax,edi
0x6fe703  ba042bc400                        mov    edx,0xc42b04
0x6fe708  5f                                pop    edi
0x6fe709  e952ffffff                        jmp    0x6fe660
0x6fe70e  40                                inc    eax
0x6fe70f  66894734                          mov    WORD PTR [edi+0x34],ax
0x6fe713  66894736                          mov    WORD PTR [edi+0x36],ax
0x6fe717  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x6fe71a  c1e104                            shl    ecx,0x4
0x6fe71d  53                                push   ebx
0x6fe71e  2bc1                              sub    eax,ecx
0x6fe720  50                                push   eax
0x6fe721  68e0e56f00                        push   0x6fe5e0
0x6fe726  57                                push   edi
0x6fe727  e874f4ffff                        call   0x6fdba0
0x6fe72c  8bd8                              mov    ebx,eax
0x6fe72e  83c40c                            add    esp,0xc
0x6fe731  85db                              test   ebx,ebx
0x6fe733  7422                              je     0x6fe757
0x6fe735  8b4f08                            mov    ecx,DWORD PTR [edi+0x8]
0x6fe738  885f06                            mov    BYTE PTR [edi+0x6],bl
0x6fe73b  e820f3ffff                        call   0x6fda60
0x6fe740  8b4f14                            mov    ecx,DWORD PTR [edi+0x14]
0x6fe743  8b5708                            mov    edx,DWORD PTR [edi+0x8]
0x6fe746  b8ffff0000                        mov    eax,0xffff
0x6fe74b  895108                            mov    DWORD PTR [ecx+0x8],edx
0x6fe74e  66014734                          add    WORD PTR [edi+0x34],ax
0x6fe752  8bc3                              mov    eax,ebx
0x6fe754  5b                                pop    ebx
0x6fe755  5f                                pop    edi
0x6fe756  c3                                ret
0x6fe757  0fb65f06                          movzx  ebx,BYTE PTR [edi+0x6]
0x6fe75b  b8ffff0000                        mov    eax,0xffff
0x6fe760  66014734                          add    WORD PTR [edi+0x34],ax
0x6fe764  8bc3                              mov    eax,ebx
0x6fe766  5b                                pop    ebx
0x6fe767  5f                                pop    edi
0x6fe768  c3                                ret

; resume_thunk 0x6fe5e0..0x6fe65b raw 0x2fd9e0 SHA256 98ea14fbf578337a2f77dc7633c93c6d498b330f68e4ff56e7eb5d701ecd0676
; First call vs resuming yield; resume arguments become yield-call results
0x6fe5e0  55                                push   ebp
0x6fe5e1  8bec                              mov    ebp,esp
0x6fe5e3  56                                push   esi
0x6fe5e4  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x6fe5e7  807e0600                          cmp    BYTE PTR [esi+0x6],0x0
0x6fe5eb  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6fe5ee  7518                              jne    0x6fe608
0x6fe5f0  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6fe5f3  6aff                              push   0xffffffff
0x6fe5f5  83c0f0                            add    eax,0xfffffff0
0x6fe5f8  8bce                              mov    ecx,esi
0x6fe5fa  e8c1fbffff                        call   0x6fe1c0
0x6fe5ff  83c404                            add    esp,0x4
0x6fe602  85c0                              test   eax,eax
0x6fe604  7552                              jne    0x6fe658
0x6fe606  eb2f                              jmp    0x6fe637
0x6fe608  c6460600                          mov    BYTE PTR [esi+0x6],0x0
0x6fe60c  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x6fe60f  8b11                              mov    edx,DWORD PTR [ecx]
0x6fe611  807a0600                          cmp    BYTE PTR [edx+0x6],0x0
0x6fe615  741b                              je     0x6fe632
0x6fe617  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6fe61a  56                                push   esi
0x6fe61b  e8a0feffff                        call   0x6fe4c0
0x6fe620  83c404                            add    esp,0x4
0x6fe623  85c0                              test   eax,eax
0x6fe625  7410                              je     0x6fe637
0x6fe627  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6fe62a  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x6fe62d  894e08                            mov    DWORD PTR [esi+0x8],ecx
0x6fe630  eb05                              jmp    0x6fe637
0x6fe632  8b10                              mov    edx,DWORD PTR [eax]
0x6fe634  89560c                            mov    DWORD PTR [esi+0xc],edx
0x6fe637  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x6fe63a  2b4e28                            sub    ecx,DWORD PTR [esi+0x28]
0x6fe63d  b8abaaaa2a                        mov    eax,0x2aaaaaab
0x6fe642  f7e9                              imul   ecx
0x6fe644  c1fa02                            sar    edx,0x2
0x6fe647  8bc2                              mov    eax,edx
0x6fe649  c1e81f                            shr    eax,0x1f
0x6fe64c  03c2                              add    eax,edx
0x6fe64e  50                                push   eax
0x6fe64f  56                                push   esi
0x6fe650  e8fbdeffff                        call   0x6fc550
0x6fe655  83c408                            add    esp,0x8
0x6fe658  5e                                pop    esi
0x6fe659  5d                                pop    ebp
0x6fe65a  c3                                ret

; resume_rejection 0x6fe660..0x6fe6c9 raw 0x2fda60 SHA256 d7897dafb7f6d0822c46512875964ac611f20e2bf7d0d2acfd0588373a18bc06
; Early non-suspended/C-depth rejection stores error and returns status 2
0x6fe660  53                                push   ebx
0x6fe661  56                                push   esi
0x6fe662  8bf0                              mov    esi,eax
0x6fe664  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6fe667  57                                push   edi
0x6fe668  8b38                              mov    edi,DWORD PTR [eax]
0x6fe66a  8bc2                              mov    eax,edx
0x6fe66c  897e08                            mov    DWORD PTR [esi+0x8],edi
0x6fe66f  8d5801                            lea    ebx,[eax+0x1]
0x6fe672  8a08                              mov    cl,BYTE PTR [eax]
0x6fe674  40                                inc    eax
0x6fe675  84c9                              test   cl,cl
0x6fe677  75f9                              jne    0x6fe672
0x6fe679  2bc3                              sub    eax,ebx
0x6fe67b  50                                push   eax
0x6fe67c  52                                push   edx
0x6fe67d  56                                push   esi
0x6fe67e  e8ed050000                        call   0x6fec70
0x6fe683  8907                              mov    DWORD PTR [edi],eax
0x6fe685  c7470804000000                    mov    DWORD PTR [edi+0x8],0x4
0x6fe68c  8b4e1c                            mov    ecx,DWORD PTR [esi+0x1c]
0x6fe68f  2b4e08                            sub    ecx,DWORD PTR [esi+0x8]
0x6fe692  bf10000000                        mov    edi,0x10
0x6fe697  83c40c                            add    esp,0xc
0x6fe69a  3bcf                              cmp    ecx,edi
0x6fe69c  7f1f                              jg     0x6fe6bd
0x6fe69e  8b462c                            mov    eax,DWORD PTR [esi+0x2c]
0x6fe6a1  83f801                            cmp    eax,0x1
0x6fe6a4  7c11                              jl     0x6fe6b7
0x6fe6a6  03c0                              add    eax,eax
0x6fe6a8  e803f6ffff                        call   0x6fdcb0
0x6fe6ad  017e08                            add    DWORD PTR [esi+0x8],edi
0x6fe6b0  8d47f2                            lea    eax,[edi-0xe]
0x6fe6b3  5f                                pop    edi
0x6fe6b4  5e                                pop    esi
0x6fe6b5  5b                                pop    ebx
0x6fe6b6  c3                                ret
0x6fe6b7  40                                inc    eax
0x6fe6b8  e8f3f5ffff                        call   0x6fdcb0
0x6fe6bd  017e08                            add    DWORD PTR [esi+0x8],edi
0x6fe6c0  5f                                pop    edi
0x6fe6c1  5e                                pop    esi
0x6fe6c2  b802000000                        mov    eax,0x2
0x6fe6c7  5b                                pop    ebx
0x6fe6c8  c3                                ret

; raw_protected_call 0x6fdba0..0x6fdc29 raw 0x2fcfa0 SHA256 cc78030fd4791c892bf458c32b7449422b6b148779aa7acd70917910f0546520
; Per-state error-frame installation/restoration around actual callback
0x6fdba0  55                                push   ebp
0x6fdba1  8bec                              mov    ebp,esp
0x6fdba3  83ec60                            sub    esp,0x60
0x6fdba6  a1201fd600                        mov    eax,ds:0xd61f20
0x6fdbab  33c5                              xor    eax,ebp
0x6fdbad  8945f8                            mov    DWORD PTR [ebp-0x8],eax
0x6fdbb0  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6fdbb3  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x6fdbb6  8b5510                            mov    edx,DWORD PTR [ebp+0x10]
0x6fdbb9  8945a8                            mov    DWORD PTR [ebp-0x58],eax
0x6fdbbc  894da0                            mov    DWORD PTR [ebp-0x60],ecx
0x6fdbbf  8955a4                            mov    DWORD PTR [ebp-0x5c],edx
0x6fdbc2  c745f000000000                    mov    DWORD PTR [ebp-0x10],0x0
0x6fdbc9  8b4870                            mov    ecx,DWORD PTR [eax+0x70]
0x6fdbcc  8d55ac                            lea    edx,[ebp-0x54]
0x6fdbcf  56                                push   esi
0x6fdbd0  894dac                            mov    DWORD PTR [ebp-0x54],ecx
0x6fdbd3  895070                            mov    DWORD PTR [eax+0x70],edx
0x6fdbd6  8d45b0                            lea    eax,[ebp-0x50]
0x6fdbd9  6a00                              push   0x0
0x6fdbdb  50                                push   eax
0x6fdbdc  e86ff11f00                        call   0x8fcd50
0x6fdbe1  83c408                            add    esp,0x8
0x6fdbe4  85c0                              test   eax,eax
0x6fdbe6  7526                              jne    0x6fdc0e
0x6fdbe8  8b4da4                            mov    ecx,DWORD PTR [ebp-0x5c]
0x6fdbeb  8b75a8                            mov    esi,DWORD PTR [ebp-0x58]
0x6fdbee  51                                push   ecx
0x6fdbef  56                                push   esi
0x6fdbf0  ff55a0                            call   DWORD PTR [ebp-0x60]
0x6fdbf3  8b55ac                            mov    edx,DWORD PTR [ebp-0x54]
0x6fdbf6  895670                            mov    DWORD PTR [esi+0x70],edx
0x6fdbf9  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0x6fdbfc  83c408                            add    esp,0x8
0x6fdbff  5e                                pop    esi
0x6fdc00  8b4df8                            mov    ecx,DWORD PTR [ebp-0x8]
0x6fdc03  33cd                              xor    ecx,ebp
0x6fdc05  e8f7331900                        call   0x891001
0x6fdc0a  8be5                              mov    esp,ebp
0x6fdc0c  5d                                pop    ebp
0x6fdc0d  c3                                ret
0x6fdc0e  8b45ac                            mov    eax,DWORD PTR [ebp-0x54]
0x6fdc11  8b4da8                            mov    ecx,DWORD PTR [ebp-0x58]
0x6fdc14  894170                            mov    DWORD PTR [ecx+0x70],eax
0x6fdc17  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0x6fdc1a  8b4df8                            mov    ecx,DWORD PTR [ebp-0x8]
0x6fdc1d  33cd                              xor    ecx,ebp
0x6fdc1f  5e                                pop    esi
0x6fdc20  e8dc331900                        call   0x891001
0x6fdc25  8be5                              mov    esp,ebp
0x6fdc27  5d                                pop    ebp
0x6fdc28  c3                                ret

; throw_error 0x6fdb40..0x6fdb94 raw 0x2fcf40 SHA256 6996d92bae7835379ff846c6429b5f67633f3e9fa02ef6514e0af1fb89e1f06e
; Transfer through same L+70 error frame; missing frame has panic/exit branch
0x6fdb40  55                                push   ebp
0x6fdb41  8bec                              mov    ebp,esp
0x6fdb43  83e4f8                            and    esp,0xfffffff8
0x6fdb46  51                                push   ecx
0x6fdb47  56                                push   esi
0x6fdb48  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x6fdb4b  8b4670                            mov    eax,DWORD PTR [esi+0x70]
0x6fdb4e  85c0                              test   eax,eax
0x6fdb50  7414                              je     0x6fdb66
0x6fdb52  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x6fdb55  894844                            mov    DWORD PTR [eax+0x44],ecx
0x6fdb58  8b5670                            mov    edx,DWORD PTR [esi+0x70]
0x6fdb5b  6a01                              push   0x1
0x6fdb5d  83c204                            add    edx,0x4
0x6fdb60  52                                push   edx
0x6fdb61  e89ab41900                        call   0x899000
0x6fdb66  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6fdb69  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
0x6fdb6c  884606                            mov    BYTE PTR [esi+0x6],al
0x6fdb6f  83795800                          cmp    DWORD PTR [ecx+0x58],0x0
0x6fdb73  7417                              je     0x6fdb8c
0x6fdb75  50                                push   eax
0x6fdb76  8bc6                              mov    eax,esi
0x6fdb78  e853ffffff                        call   0x6fdad0
0x6fdb7d  8b5610                            mov    edx,DWORD PTR [esi+0x10]
0x6fdb80  8b4258                            mov    eax,DWORD PTR [edx+0x58]
0x6fdb83  83c404                            add    esp,0x4
0x6fdb86  56                                push   esi
0x6fdb87  ffd0                              call   eax
0x6fdb89  83c404                            add    esp,0x4
0x6fdb8c  6a01                              push   0x1
0x6fdb8e  e8205e1900                        call   0x8939b3
0x6fdb93  cc                                int3

; set_error_object 0x6fda60..0x6fdab8 raw 0x2fce60 SHA256 63428129215313fadd542bd148ee0891aae0ba70b5608672b36d4f76cdd4b2f7
; Preserve arbitrary runtime error TValue; special memory/error-handler messages
0x6fda60  83c0fe                            add    eax,0xfffffffe
0x6fda63  56                                push   esi
0x6fda64  8bf1                              mov    esi,ecx
0x6fda66  83f803                            cmp    eax,0x3
0x6fda69  7745                              ja     0x6fdab0
0x6fda6b  ff2485b8da6f00                    jmp    DWORD PTR [eax*4+0x6fdab8]
0x6fda72  6a11                              push   0x11
0x6fda74  685028c400                        push   0xc42850
0x6fda79  57                                push   edi
0x6fda7a  e8f1110000                        call   0x6fec70
0x6fda7f  8906                              mov    DWORD PTR [esi],eax
0x6fda81  c7460804000000                    mov    DWORD PTR [esi+0x8],0x4
0x6fda88  83c40c                            add    esp,0xc
0x6fda8b  83c610                            add    esi,0x10
0x6fda8e  897708                            mov    DWORD PTR [edi+0x8],esi
0x6fda91  5e                                pop    esi
0x6fda92  c3                                ret
0x6fda93  6a17                              push   0x17
0x6fda95  68d42ac400                        push   0xc42ad4
0x6fda9a  ebdd                              jmp    0x6fda79
0x6fda9c  8b4708                            mov    eax,DWORD PTR [edi+0x8]
0x6fda9f  8b48f0                            mov    ecx,DWORD PTR [eax-0x10]
0x6fdaa2  890e                              mov    DWORD PTR [esi],ecx
0x6fdaa4  8b50f4                            mov    edx,DWORD PTR [eax-0xc]
0x6fdaa7  895604                            mov    DWORD PTR [esi+0x4],edx
0x6fdaaa  8b40f8                            mov    eax,DWORD PTR [eax-0x8]
0x6fdaad  894608                            mov    DWORD PTR [esi+0x8],eax
0x6fdab0  83c610                            add    esi,0x10
0x6fdab3  897708                            mov    DWORD PTR [edi+0x8],esi
0x6fdab6  5e                                pop    esi
0x6fdab7  c3                                ret

; precall 0x6fe1c0..0x6fe394 raw 0x2fd5c0 SHA256 cdc97c3e9ef59235e8072416e3f980d7a418db3239539c2704e8a5e821692ec7
; Lua/C dispatch; C callback receives current L; negative callback result denotes yield
0x6fe1c0  55                                push   ebp
0x6fe1c1  8bec                              mov    ebp,esp
0x6fe1c3  83ec08                            sub    esp,0x8
0x6fe1c6  83780806                          cmp    DWORD PTR [eax+0x8],0x6
0x6fe1ca  53                                push   ebx
0x6fe1cb  56                                push   esi
0x6fe1cc  57                                push   edi
0x6fe1cd  8bf1                              mov    esi,ecx
0x6fe1cf  740b                              je     0x6fe1dc
0x6fe1d1  50                                push   eax
0x6fe1d2  8bfe                              mov    edi,esi
0x6fe1d4  e807ffffff                        call   0x6fe0e0
0x6fe1d9  83c404                            add    esp,0x4
0x6fe1dc  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x6fe1df  8b5618                            mov    edx,DWORD PTR [esi+0x18]
0x6fe1e2  8bd8                              mov    ebx,eax
0x6fe1e4  2b5e20                            sub    ebx,DWORD PTR [esi+0x20]
0x6fe1e7  8b00                              mov    eax,DWORD PTR [eax]
0x6fe1e9  89510c                            mov    DWORD PTR [ecx+0xc],edx
0x6fe1ec  80780600                          cmp    BYTE PTR [eax+0x6],0x0
0x6fe1f0  895df8                            mov    DWORD PTR [ebp-0x8],ebx
0x6fe1f3  0f85ed000000                      jne    0x6fe2e6
0x6fe1f9  8b4810                            mov    ecx,DWORD PTR [eax+0x10]
0x6fe1fc  0fb6414b                          movzx  eax,BYTE PTR [ecx+0x4b]
0x6fe200  8b561c                            mov    edx,DWORD PTR [esi+0x1c]
0x6fe203  2b5608                            sub    edx,DWORD PTR [esi+0x8]
0x6fe206  8bf8                              mov    edi,eax
0x6fe208  c1e704                            shl    edi,0x4
0x6fe20b  894dfc                            mov    DWORD PTR [ebp-0x4],ecx
0x6fe20e  3bd7                              cmp    edx,edi
0x6fe210  7f16                              jg     0x6fe228
0x6fe212  8b4e2c                            mov    ecx,DWORD PTR [esi+0x2c]
0x6fe215  3bc1                              cmp    eax,ecx
0x6fe217  7f05                              jg     0x6fe21e
0x6fe219  8d0409                            lea    eax,[ecx+ecx*1]
0x6fe21c  eb02                              jmp    0x6fe220
0x6fe21e  03c1                              add    eax,ecx
0x6fe220  e88bfaffff                        call   0x6fdcb0
0x6fe225  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x6fe228  8b7e20                            mov    edi,DWORD PTR [esi+0x20]
0x6fe22b  03fb                              add    edi,ebx
0x6fe22d  80794a00                          cmp    BYTE PTR [ecx+0x4a],0x0
0x6fe231  7516                              jne    0x6fe249
0x6fe233  0fb64149                          movzx  eax,BYTE PTR [ecx+0x49]
0x6fe237  c1e004                            shl    eax,0x4
0x6fe23a  8d5f10                            lea    ebx,[edi+0x10]
0x6fe23d  03c3                              add    eax,ebx
0x6fe23f  394608                            cmp    DWORD PTR [esi+0x8],eax
0x6fe242  7625                              jbe    0x6fe269
0x6fe244  894608                            mov    DWORD PTR [esi+0x8],eax
0x6fe247  eb20                              jmp    0x6fe269
0x6fe249  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6fe24c  2bc7                              sub    eax,edi
0x6fe24e  c1f804                            sar    eax,0x4
0x6fe251  48                                dec    eax
0x6fe252  50                                push   eax
0x6fe253  56                                push   esi
0x6fe254  8bc1                              mov    eax,ecx
0x6fe256  e865fcffff                        call   0x6fdec0
0x6fe25b  8b7e20                            mov    edi,DWORD PTR [esi+0x20]
0x6fe25e  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x6fe261  83c408                            add    esp,0x8
0x6fe264  037df8                            add    edi,DWORD PTR [ebp-0x8]
0x6fe267  8bd8                              mov    ebx,eax
0x6fe269  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6fe26c  3b4624                            cmp    eax,DWORD PTR [esi+0x24]
0x6fe26f  750c                              jne    0x6fe27d
0x6fe271  8bc6                              mov    eax,esi
0x6fe273  e818fbffff                        call   0x6fdd90
0x6fe278  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x6fe27b  eb06                              jmp    0x6fe283
0x6fe27d  83c018                            add    eax,0x18
0x6fe280  894614                            mov    DWORD PTR [esi+0x14],eax
0x6fe283  897804                            mov    DWORD PTR [eax+0x4],edi
0x6fe286  8918                              mov    DWORD PTR [eax],ebx
0x6fe288  895e0c                            mov    DWORD PTR [esi+0xc],ebx
0x6fe28b  0fb6514b                          movzx  edx,BYTE PTR [ecx+0x4b]
0x6fe28f  c1e204                            shl    edx,0x4
0x6fe292  03d3                              add    edx,ebx
0x6fe294  895008                            mov    DWORD PTR [eax+0x8],edx
0x6fe297  8b490c                            mov    ecx,DWORD PTR [ecx+0xc]
0x6fe29a  894e18                            mov    DWORD PTR [esi+0x18],ecx
0x6fe29d  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x6fe2a0  33d2                              xor    edx,edx
0x6fe2a2  895014                            mov    DWORD PTR [eax+0x14],edx
0x6fe2a5  894810                            mov    DWORD PTR [eax+0x10],ecx
0x6fe2a8  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x6fe2ab  3b4808                            cmp    ecx,DWORD PTR [eax+0x8]
0x6fe2ae  730b                              jae    0x6fe2bb
0x6fe2b0  895108                            mov    DWORD PTR [ecx+0x8],edx
0x6fe2b3  83c110                            add    ecx,0x10
0x6fe2b6  3b4808                            cmp    ecx,DWORD PTR [eax+0x8]
0x6fe2b9  72f5                              jb     0x6fe2b0
0x6fe2bb  f6463801                          test   BYTE PTR [esi+0x38],0x1
0x6fe2bf  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x6fe2c2  895608                            mov    DWORD PTR [esi+0x8],edx
0x6fe2c5  7416                              je     0x6fe2dd
0x6fe2c7  83461804                          add    DWORD PTR [esi+0x18],0x4
0x6fe2cb  6aff                              push   0xffffffff
0x6fe2cd  33d2                              xor    edx,edx
0x6fe2cf  8bce                              mov    ecx,esi
0x6fe2d1  e80afbffff                        call   0x6fdde0
0x6fe2d6  83c404                            add    esp,0x4
0x6fe2d9  834618fc                          add    DWORD PTR [esi+0x18],0xfffffffc
0x6fe2dd  33c0                              xor    eax,eax
0x6fe2df  5f                                pop    edi
0x6fe2e0  5e                                pop    esi
0x6fe2e1  5b                                pop    ebx
0x6fe2e2  8be5                              mov    esp,ebp
0x6fe2e4  5d                                pop    ebp
0x6fe2e5  c3                                ret
0x6fe2e6  8b461c                            mov    eax,DWORD PTR [esi+0x1c]
0x6fe2e9  2b4608                            sub    eax,DWORD PTR [esi+0x8]
0x6fe2ec  3d40010000                        cmp    eax,0x140
0x6fe2f1  7f14                              jg     0x6fe307
0x6fe2f3  8b462c                            mov    eax,DWORD PTR [esi+0x2c]
0x6fe2f6  83f814                            cmp    eax,0x14
0x6fe2f9  7c04                              jl     0x6fe2ff
0x6fe2fb  03c0                              add    eax,eax
0x6fe2fd  eb03                              jmp    0x6fe302
0x6fe2ff  83c014                            add    eax,0x14
0x6fe302  e8a9f9ffff                        call   0x6fdcb0
0x6fe307  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6fe30a  3b4624                            cmp    eax,DWORD PTR [esi+0x24]
0x6fe30d  7509                              jne    0x6fe318
0x6fe30f  8bc6                              mov    eax,esi
0x6fe311  e87afaffff                        call   0x6fdd90
0x6fe316  eb06                              jmp    0x6fe31e
0x6fe318  83c018                            add    eax,0x18
0x6fe31b  894614                            mov    DWORD PTR [esi+0x14],eax
0x6fe31e  8b4e20                            mov    ecx,DWORD PTR [esi+0x20]
0x6fe321  03cb                              add    ecx,ebx
0x6fe323  894804                            mov    DWORD PTR [eax+0x4],ecx
0x6fe326  83c110                            add    ecx,0x10
0x6fe329  8908                              mov    DWORD PTR [eax],ecx
0x6fe32b  8b5608                            mov    edx,DWORD PTR [esi+0x8]
0x6fe32e  894e0c                            mov    DWORD PTR [esi+0xc],ecx
0x6fe331  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x6fe334  81c240010000                      add    edx,0x140
0x6fe33a  895008                            mov    DWORD PTR [eax+0x8],edx
0x6fe33d  894810                            mov    DWORD PTR [eax+0x10],ecx
0x6fe340  f6463801                          test   BYTE PTR [esi+0x38],0x1
0x6fe344  740e                              je     0x6fe354
0x6fe346  6aff                              push   0xffffffff
0x6fe348  33d2                              xor    edx,edx
0x6fe34a  8bce                              mov    ecx,esi
0x6fe34c  e88ffaffff                        call   0x6fdde0
0x6fe351  83c404                            add    esp,0x4
0x6fe354  8b5614                            mov    edx,DWORD PTR [esi+0x14]
0x6fe357  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x6fe35a  8b08                              mov    ecx,DWORD PTR [eax]
0x6fe35c  8b5110                            mov    edx,DWORD PTR [ecx+0x10]
0x6fe35f  56                                push   esi
0x6fe360  ffd2                              call   edx
0x6fe362  83c404                            add    esp,0x4
0x6fe365  85c0                              test   eax,eax
0x6fe367  790c                              jns    0x6fe375
0x6fe369  b802000000                        mov    eax,0x2
0x6fe36e  5f                                pop    edi
0x6fe36f  5e                                pop    esi
0x6fe370  5b                                pop    ebx
0x6fe371  8be5                              mov    esp,ebp
0x6fe373  5d                                pop    ebp
0x6fe374  c3                                ret
0x6fe375  c1e004                            shl    eax,0x4
0x6fe378  8bc8                              mov    ecx,eax
0x6fe37a  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6fe37d  2bc1                              sub    eax,ecx
0x6fe37f  56                                push   esi
0x6fe380  e83b010000                        call   0x6fe4c0
0x6fe385  83c404                            add    esp,0x4
0x6fe388  5f                                pop    edi
0x6fe389  5e                                pop    esi
0x6fe38a  b801000000                        mov    eax,0x1
0x6fe38f  5b                                pop    ebx
0x6fe390  8be5                              mov    esp,ebp
0x6fe392  5d                                pop    ebp
0x6fe393  c3                                ret

; poscall 0x6fe4c0..0x6fe548 raw 0x2fd8c0 SHA256 f8b78b6ed21ac373130454a4547d800c0cb269a617fe6bb24bee4a67e76c8587
; Pop CallInfo and copy/pad resume or return results
0x6fe4c0  55                                push   ebp
0x6fe4c1  8bec                              mov    ebp,esp
0x6fe4c3  51                                push   ecx
0x6fe4c4  53                                push   ebx
0x6fe4c5  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6fe4c8  f6433802                          test   BYTE PTR [ebx+0x38],0x2
0x6fe4cc  56                                push   esi
0x6fe4cd  57                                push   edi
0x6fe4ce  740b                              je     0x6fe4db
0x6fe4d0  50                                push   eax
0x6fe4d1  8bcb                              mov    ecx,ebx
0x6fe4d3  e8c8feffff                        call   0x6fe3a0
0x6fe4d8  83c404                            add    esp,0x4
0x6fe4db  8b5314                            mov    edx,DWORD PTR [ebx+0x14]
0x6fe4de  8d72e8                            lea    esi,[edx-0x18]
0x6fe4e1  897314                            mov    DWORD PTR [ebx+0x14],esi
0x6fe4e4  8b7a10                            mov    edi,DWORD PTR [edx+0x10]
0x6fe4e7  8b36                              mov    esi,DWORD PTR [esi]
0x6fe4e9  8b4a04                            mov    ecx,DWORD PTR [edx+0x4]
0x6fe4ec  89730c                            mov    DWORD PTR [ebx+0xc],esi
0x6fe4ef  8b52f4                            mov    edx,DWORD PTR [edx-0xc]
0x6fe4f2  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x6fe4f5  895318                            mov    DWORD PTR [ebx+0x18],edx
0x6fe4f8  8bf7                              mov    esi,edi
0x6fe4fa  85ff                              test   edi,edi
0x6fe4fc  742a                              je     0x6fe528
0x6fe4fe  8bf8                              mov    edi,eax
0x6fe500  3b7b08                            cmp    edi,DWORD PTR [ebx+0x8]
0x6fe503  7320                              jae    0x6fe525
0x6fe505  8bc7                              mov    eax,edi
0x6fe507  8b18                              mov    ebx,DWORD PTR [eax]
0x6fe509  8bd1                              mov    edx,ecx
0x6fe50b  891a                              mov    DWORD PTR [edx],ebx
0x6fe50d  8b5804                            mov    ebx,DWORD PTR [eax+0x4]
0x6fe510  895a04                            mov    DWORD PTR [edx+0x4],ebx
0x6fe513  8b4008                            mov    eax,DWORD PTR [eax+0x8]
0x6fe516  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6fe519  83c110                            add    ecx,0x10
0x6fe51c  83c710                            add    edi,0x10
0x6fe51f  4e                                dec    esi
0x6fe520  894208                            mov    DWORD PTR [edx+0x8],eax
0x6fe523  75db                              jne    0x6fe500
0x6fe525  8b7dfc                            mov    edi,DWORD PTR [ebp-0x4]
0x6fe528  33c0                              xor    eax,eax
0x6fe52a  3bf0                              cmp    esi,eax
0x6fe52c  7e0d                              jle    0x6fe53b
0x6fe52e  8bff                              mov    edi,edi
0x6fe530  4e                                dec    esi
0x6fe531  894108                            mov    DWORD PTR [ecx+0x8],eax
0x6fe534  83c110                            add    ecx,0x10
0x6fe537  3bf0                              cmp    esi,eax
0x6fe539  7ff5                              jg     0x6fe530
0x6fe53b  8d4701                            lea    eax,[edi+0x1]
0x6fe53e  5f                                pop    edi
0x6fe53f  5e                                pop    esi
0x6fe540  894b08                            mov    DWORD PTR [ebx+0x8],ecx
0x6fe543  5b                                pop    ebx
0x6fe544  8be5                              mov    esp,ebp
0x6fe546  5d                                pop    ebp
0x6fe547  c3                                ret

; call_boundary 0x6fe550..0x6fe5d6 raw 0x2fd950 SHA256 d85c70ff477a89163626159756f2b01ea8efce94d8b20fe5aa50f1b1930f667b
; C-to-Lua call increments nCcalls, unlike VM direct CALL
0x6fe550  55                                push   ebp
0x6fe551  8bec                              mov    ebp,esp
0x6fe553  83e4f8                            and    esp,0xfffffff8
0x6fe556  51                                push   ecx
0x6fe557  56                                push   esi
0x6fe558  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x6fe55b  66ff4634                          inc    WORD PTR [esi+0x34]
0x6fe55f  668b4634                          mov    ax,WORD PTR [esi+0x34]
0x6fe563  b9c8000000                        mov    ecx,0xc8
0x6fe568  663bc1                            cmp    ax,cx
0x6fe56b  7229                              jb     0x6fe596
0x6fe56d  8bd1                              mov    edx,ecx
0x6fe56f  663bc2                            cmp    ax,dx
0x6fe572  750d                              jne    0x6fe581
0x6fe574  68042bc400                        push   0xc42b04
0x6fe579  56                                push   esi
0x6fe57a  e8e1a5ffff                        call   0x6f8b60
0x6fe57f  eb12                              jmp    0x6fe593
0x6fe581  b9e1000000                        mov    ecx,0xe1
0x6fe586  663bc1                            cmp    ax,cx
0x6fe589  720b                              jb     0x6fe596
0x6fe58b  6a05                              push   0x5
0x6fe58d  56                                push   esi
0x6fe58e  e8adf5ffff                        call   0x6fdb40
0x6fe593  83c408                            add    esp,0x8
0x6fe596  8b5510                            mov    edx,DWORD PTR [ebp+0x10]
0x6fe599  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6fe59c  52                                push   edx
0x6fe59d  8bce                              mov    ecx,esi
0x6fe59f  e81cfcffff                        call   0x6fe1c0
0x6fe5a4  83c404                            add    esp,0x4
0x6fe5a7  85c0                              test   eax,eax
0x6fe5a9  750b                              jne    0x6fe5b6
0x6fe5ab  6a01                              push   0x1
0x6fe5ad  56                                push   esi
0x6fe5ae  e89ddfffff                        call   0x6fc550
0x6fe5b3  83c408                            add    esp,0x8
0x6fe5b6  b8ffff0000                        mov    eax,0xffff
0x6fe5bb  66014634                          add    WORD PTR [esi+0x34],ax
0x6fe5bf  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x6fe5c2  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x6fe5c5  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x6fe5c8  7207                              jb     0x6fe5d1
0x6fe5ca  8bc6                              mov    eax,esi
0x6fe5cc  e8cfcdffff                        call   0x6fb3a0
0x6fe5d1  5e                                pop    esi
0x6fe5d2  8be5                              mov    esp,ebp
0x6fe5d4  5d                                pop    ebp
0x6fe5d5  c3                                ret

; vm_call 0x6fd01e..0x6fd076 raw 0x2fc41e SHA256 0a8bc950ad578e9f782df5b2b028fc844bf62140081982ad4166f38a4132c384
; VM CALL routes yield return to VM exit rather than crossing caller state
0x6fd01e  8bc3                              mov    eax,ebx
0x6fd020  c1eb0e                            shr    ebx,0xe
0x6fd023  81e3ff010000                      and    ebx,0x1ff
0x6fd029  c1e817                            shr    eax,0x17
0x6fd02c  4b                                dec    ebx
0x6fd02d  85c0                              test   eax,eax
0x6fd02f  7408                              je     0x6fd039
0x6fd031  c1e004                            shl    eax,0x4
0x6fd034  03c6                              add    eax,esi
0x6fd036  894708                            mov    DWORD PTR [edi+0x8],eax
0x6fd039  8b442434                          mov    eax,DWORD PTR [esp+0x34]
0x6fd03d  894718                            mov    DWORD PTR [edi+0x18],eax
0x6fd040  53                                push   ebx
0x6fd041  8bc6                              mov    eax,esi
0x6fd043  8bcf                              mov    ecx,edi
0x6fd045  e876110000                        call   0x6fe1c0
0x6fd04a  83c404                            add    esp,0x4
0x6fd04d  83e800                            sub    eax,0x0
0x6fd050  0f843b050000                      je     0x6fd591
0x6fd056  48                                dec    eax
0x6fd057  0f852d060000                      jne    0x6fd68a
0x6fd05d  85db                              test   ebx,ebx
0x6fd05f  7809                              js     0x6fd06a
0x6fd061  8b4f14                            mov    ecx,DWORD PTR [edi+0x14]
0x6fd064  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x6fd067  895708                            mov    DWORD PTR [edi+0x8],edx
0x6fd06a  8b470c                            mov    eax,DWORD PTR [edi+0xc]
0x6fd06d  89442438                          mov    DWORD PTR [esp+0x38],eax
0x6fd071  e914f5ffff                        jmp    0x6fc58a

; vm_return 0x6fd629..0x6fd691 raw 0x2fca29 SHA256 fed916eec85ed3cfc2b1f7a5bc2800684b69ce5dce263377e8351f46e5104a36
; Lua RETURN closes own upvalues, completes call and exits interpreter
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

; error_formatter 0x6f8b60..0x6f8b91 raw 0x2f7f60 SHA256 9e92c40ab26e64058ed61a5e6d8ac2c9bcde7eabf61f59da1e543645d7d4252c
; Yield boundary error reaches runtime throw helper
0x6f8b60  55                                push   ebp
0x6f8b61  8bec                              mov    ebp,esp
0x6f8b63  83e4f8                            and    esp,0xfffffff8
0x6f8b66  51                                push   ecx
0x6f8b67  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x6f8b6a  57                                push   edi
0x6f8b6b  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x6f8b6e  8d4510                            lea    eax,[ebp+0x10]
0x6f8b71  50                                push   eax
0x6f8b72  8bcf                              mov    ecx,edi
0x6f8b74  e8e7ecffff                        call   0x6f7860
0x6f8b79  83c404                            add    esp,0x4
0x6f8b7c  50                                push   eax
0x6f8b7d  e8befeffff                        call   0x6f8a40
0x6f8b82  83c404                            add    esp,0x4
0x6f8b85  8bc7                              mov    eax,edi
0x6f8b87  e844ffffff                        call   0x6f8ad0
0x6f8b8c  5f                                pop    edi
0x6f8b8d  8be5                              mov    esp,ebp
0x6f8b8f  5d                                pop    ebp
0x6f8b90  c3                                ret

; runtime_error 0x6f8ad0..0x6f8b5b raw 0x2f7ed0 SHA256 0176729c758006345e3de85cc6a1987083c8977645fcb6aa86d04361628654ec
; Runtime errors enter 6FDB40 with status 2
0x6f8ad0  56                                push   esi
0x6f8ad1  8bf0                              mov    esi,eax
0x6f8ad3  8b4674                            mov    eax,DWORD PTR [esi+0x74]
0x6f8ad6  57                                push   edi
0x6f8ad7  85c0                              test   eax,eax
0x6f8ad9  7471                              je     0x6f8b4c
0x6f8adb  8b7e20                            mov    edi,DWORD PTR [esi+0x20]
0x6f8ade  03f8                              add    edi,eax
0x6f8ae0  837f0806                          cmp    DWORD PTR [edi+0x8],0x6
0x6f8ae4  740b                              je     0x6f8af1
0x6f8ae6  6a05                              push   0x5
0x6f8ae8  56                                push   esi
0x6f8ae9  e852500000                        call   0x6fdb40
0x6f8aee  83c408                            add    esp,0x8
0x6f8af1  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6f8af4  8b48f0                            mov    ecx,DWORD PTR [eax-0x10]
0x6f8af7  8908                              mov    DWORD PTR [eax],ecx
0x6f8af9  8b50f4                            mov    edx,DWORD PTR [eax-0xc]
0x6f8afc  895004                            mov    DWORD PTR [eax+0x4],edx
0x6f8aff  8b48f8                            mov    ecx,DWORD PTR [eax-0x8]
0x6f8b02  894808                            mov    DWORD PTR [eax+0x8],ecx
0x6f8b05  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6f8b08  8b17                              mov    edx,DWORD PTR [edi]
0x6f8b0a  8950f0                            mov    DWORD PTR [eax-0x10],edx
0x6f8b0d  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x6f8b10  8948f4                            mov    DWORD PTR [eax-0xc],ecx
0x6f8b13  8b5708                            mov    edx,DWORD PTR [edi+0x8]
0x6f8b16  8950f8                            mov    DWORD PTR [eax-0x8],edx
0x6f8b19  8b461c                            mov    eax,DWORD PTR [esi+0x1c]
0x6f8b1c  2b4608                            sub    eax,DWORD PTR [esi+0x8]
0x6f8b1f  83f810                            cmp    eax,0x10
0x6f8b22  7f12                              jg     0x6f8b36
0x6f8b24  8b462c                            mov    eax,DWORD PTR [esi+0x2c]
0x6f8b27  83f801                            cmp    eax,0x1
0x6f8b2a  7c04                              jl     0x6f8b30
0x6f8b2c  03c0                              add    eax,eax
0x6f8b2e  eb01                              jmp    0x6f8b31
0x6f8b30  40                                inc    eax
0x6f8b31  e87a510000                        call   0x6fdcb0
0x6f8b36  83460810                          add    DWORD PTR [esi+0x8],0x10
0x6f8b3a  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x6f8b3d  6a01                              push   0x1
0x6f8b3f  83c0e0                            add    eax,0xffffffe0
0x6f8b42  50                                push   eax
0x6f8b43  56                                push   esi
0x6f8b44  e8075a0000                        call   0x6fe550
0x6f8b49  83c40c                            add    esp,0xc
0x6f8b4c  6a02                              push   0x2
0x6f8b4e  56                                push   esi
0x6f8b4f  e8ec4f0000                        call   0x6fdb40
0x6f8b54  83c408                            add    esp,0x8
0x6f8b57  5f                                pop    edi
0x6f8b58  5e                                pop    esi
0x6f8b59  c3                                ret
0x6f8b5a  cc                                int3

; argument_error 0x6f5da0..0x6f5e8d raw 0x2f51a0 SHA256 91ffdfceb9ce0592fcc3f0a181296a6549dd78b90fd49463eac203564d325d3c
; Invalid public coroutine arguments raise outside child body protection
0x6f5da0  55                                push   ebp
0x6f5da1  8bec                              mov    ebp,esp
0x6f5da3  83ec70                            sub    esp,0x70
0x6f5da6  a1201fd600                        mov    eax,ds:0xd61f20
0x6f5dab  33c5                              xor    eax,ebp
0x6f5dad  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x6f5db0  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6f5db3  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x6f5db6  53                                push   ebx
0x6f5db7  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x6f5dba  3bc1                              cmp    eax,ecx
0x6f5dbc  7652                              jbe    0x6f5e10
0x6f5dbe  2bc1                              sub    eax,ecx
0x6f5dc0  8bc8                              mov    ecx,eax
0x6f5dc2  b8abaaaa2a                        mov    eax,0x2aaaaaab
0x6f5dc7  f7e9                              imul   ecx
0x6f5dc9  c1fa02                            sar    edx,0x2
0x6f5dcc  8bc2                              mov    eax,edx
0x6f5dce  c1e81f                            shr    eax,0x1f
0x6f5dd1  03c2                              add    eax,edx
0x6f5dd3  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x6f5dd6  681c27c400                        push   0xc4271c
0x6f5ddb  8d4590                            lea    eax,[ebp-0x70]
0x6f5dde  8bce                              mov    ecx,esi
0x6f5de0  e89b230000                        call   0x6f8180
0x6f5de5  8b4598                            mov    eax,DWORD PTR [ebp-0x68]
0x6f5de8  83c404                            add    esp,0x4
0x6f5deb  b92027c400                        mov    ecx,0xc42720
0x6f5df0  8a10                              mov    dl,BYTE PTR [eax]
0x6f5df2  3a11                              cmp    dl,BYTE PTR [ecx]
0x6f5df4  7539                              jne    0x6f5e2f
0x6f5df6  84d2                              test   dl,dl
0x6f5df8  7412                              je     0x6f5e0c
0x6f5dfa  8a5001                            mov    dl,BYTE PTR [eax+0x1]
0x6f5dfd  3a5101                            cmp    dl,BYTE PTR [ecx+0x1]
0x6f5e00  752d                              jne    0x6f5e2f
0x6f5e02  83c002                            add    eax,0x2
0x6f5e05  83c102                            add    ecx,0x2
0x6f5e08  84d2                              test   dl,dl
0x6f5e0a  75e4                              jne    0x6f5df0
0x6f5e0c  33c0                              xor    eax,eax
0x6f5e0e  eb24                              jmp    0x6f5e34
0x6f5e10  57                                push   edi
0x6f5e11  53                                push   ebx
0x6f5e12  680427c400                        push   0xc42704
0x6f5e17  56                                push   esi
0x6f5e18  e813010000                        call   0x6f5f30
0x6f5e1d  83c410                            add    esp,0x10
0x6f5e20  5b                                pop    ebx
0x6f5e21  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x6f5e24  33cd                              xor    ecx,ebp
0x6f5e26  e8d6b11900                        call   0x891001
0x6f5e2b  8be5                              mov    esp,ebp
0x6f5e2d  5d                                pop    ebp
0x6f5e2e  c3                                ret
0x6f5e2f  1bc0                              sbb    eax,eax
0x6f5e31  83d8ff                            sbb    eax,0xffffffff
0x6f5e34  85c0                              test   eax,eax
0x6f5e36  7525                              jne    0x6f5e5d
0x6f5e38  4b                                dec    ebx
0x6f5e39  7522                              jne    0x6f5e5d
0x6f5e3b  8b4d94                            mov    ecx,DWORD PTR [ebp-0x6c]
0x6f5e3e  57                                push   edi
0x6f5e3f  51                                push   ecx
0x6f5e40  682827c400                        push   0xc42728
0x6f5e45  56                                push   esi
0x6f5e46  e8e5000000                        call   0x6f5f30
0x6f5e4b  83c410                            add    esp,0x10
0x6f5e4e  5b                                pop    ebx
0x6f5e4f  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x6f5e52  33cd                              xor    ecx,ebp
0x6f5e54  e8a8b11900                        call   0x891001
0x6f5e59  8be5                              mov    esp,ebp
0x6f5e5b  5d                                pop    ebp
0x6f5e5c  c3                                ret
0x6f5e5d  8b4594                            mov    eax,DWORD PTR [ebp-0x6c]
0x6f5e60  85c0                              test   eax,eax
0x6f5e62  7508                              jne    0x6f5e6c
0x6f5e64  b80027c400                        mov    eax,0xc42700
0x6f5e69  894594                            mov    DWORD PTR [ebp-0x6c],eax
0x6f5e6c  57                                push   edi
0x6f5e6d  50                                push   eax
0x6f5e6e  53                                push   ebx
0x6f5e6f  684827c400                        push   0xc42748
0x6f5e74  56                                push   esi
0x6f5e75  e8b6000000                        call   0x6f5f30
0x6f5e7a  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x6f5e7d  83c414                            add    esp,0x14
0x6f5e80  33cd                              xor    ecx,ebp
0x6f5e82  5b                                pop    ebx
0x6f5e83  e879b11900                        call   0x891001
0x6f5e88  8be5                              mov    esp,ebp
0x6f5e8a  5d                                pop    ebp
0x6f5e8b  c3                                ret
0x6f5e8c  cc                                int3

; raise_formatted_error 0x6f5f30..0x6f5f9f raw 0x2f5330 SHA256 02bbe8854fe62491f7b0043c92969d4d859653c9303c3e92f0eb8a08899ee0d8
; Auxresume capacity rejection raises on caller
0x6f5f30  55                                push   ebp
0x6f5f31  8bec                              mov    ebp,esp
0x6f5f33  51                                push   ecx
0x6f5f34  56                                push   esi
0x6f5f35  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x6f5f38  b901000000                        mov    ecx,0x1
0x6f5f3d  e84effffff                        call   0x6f5e90
0x6f5f42  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x6f5f45  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x6f5f48  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x6f5f4b  7207                              jb     0x6f5f54
0x6f5f4d  8bc6                              mov    eax,esi
0x6f5f4f  e84c540000                        call   0x6fb3a0
0x6f5f54  8d5510                            lea    edx,[ebp+0x10]
0x6f5f57  52                                push   edx
0x6f5f58  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x6f5f5b  8bce                              mov    ecx,esi
0x6f5f5d  e8fe180000                        call   0x6f7860
0x6f5f62  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x6f5f65  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
0x6f5f68  83c404                            add    esp,0x4
0x6f5f6b  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
0x6f5f6e  7207                              jb     0x6f5f77
0x6f5f70  8bc6                              mov    eax,esi
0x6f5f72  e829540000                        call   0x6fb3a0
0x6f5f77  8b5608                            mov    edx,DWORD PTR [esi+0x8]
0x6f5f7a  2b560c                            sub    edx,DWORD PTR [esi+0xc]
0x6f5f7d  c1fa04                            sar    edx,0x4
0x6f5f80  4a                                dec    edx
0x6f5f81  52                                push   edx
0x6f5f82  6a02                              push   0x2
0x6f5f84  56                                push   esi
0x6f5f85  e8f6600000                        call   0x6fc080
0x6f5f8a  834608f0                          add    DWORD PTR [esi+0x8],0xfffffff0
0x6f5f8e  83c40c                            add    esp,0xc
0x6f5f91  8bc6                              mov    eax,esi
0x6f5f93  e8382b0000                        call   0x6f8ad0
0x6f5f98  33c0                              xor    eax,eax
0x6f5f9a  5e                                pop    esi
0x6f5f9b  59                                pop    ecx
0x6f5f9c  5d                                pop    ebp
0x6f5f9d  c3                                ret
0x6f5f9e  cc                                int3

; global_dofile 0x6f48a0..0x6f4a50 raw 0x2f3ca0 SHA256 fe72d7521c01ead56408d1bbbd30cf82046b0628cec91235a1db2f732002253e
; Current L loader/protected top-level; returns only numeric 0/1
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

; protected_call 0x6fe770..0x6fe858 raw 0x2fdb70 SHA256 bab3d3f1b7a1749c76c289a8f42ca0690cbf5fe1b4f334896422f50c7d976793
; DoFile protected-call state restoration; same-state C boundary persists
0x6fe770  55                                push   ebp
0x6fe771  8bec                              mov    ebp,esp
0x6fe773  83ec18                            sub    esp,0x18
0x6fe776  53                                push   ebx
0x6fe777  56                                push   esi
0x6fe778  8bf0                              mov    esi,eax
0x6fe77a  0fb74634                          movzx  eax,WORD PTR [esi+0x34]
0x6fe77e  8a4e39                            mov    cl,BYTE PTR [esi+0x39]
0x6fe781  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x6fe784  8b4614                            mov    eax,DWORD PTR [esi+0x14]
0x6fe787  2b4628                            sub    eax,DWORD PTR [esi+0x28]
0x6fe78a  57                                push   edi
0x6fe78b  8b7e74                            mov    edi,DWORD PTR [esi+0x74]
0x6fe78e  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x6fe791  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6fe794  884dff                            mov    BYTE PTR [ebp-0x1],cl
0x6fe797  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x6fe79a  50                                push   eax
0x6fe79b  51                                push   ecx
0x6fe79c  56                                push   esi
0x6fe79d  897df8                            mov    DWORD PTR [ebp-0x8],edi
0x6fe7a0  895674                            mov    DWORD PTR [esi+0x74],edx
0x6fe7a3  e8f8f3ffff                        call   0x6fdba0
0x6fe7a8  83c40c                            add    esp,0xc
0x6fe7ab  8945f4                            mov    DWORD PTR [ebp-0xc],eax
0x6fe7ae  85c0                              test   eax,eax
0x6fe7b0  0f8498000000                      je     0x6fe84e
0x6fe7b6  8b5e20                            mov    ebx,DWORD PTR [esi+0x20]
0x6fe7b9  035d10                            add    ebx,DWORD PTR [ebp+0x10]
0x6fe7bc  8bfe                              mov    edi,esi
0x6fe7be  53                                push   ebx
0x6fe7bf  e89cf0ffff                        call   0x6fd860
0x6fe7c4  8bcb                              mov    ecx,ebx
0x6fe7c6  8b5df4                            mov    ebx,DWORD PTR [ebp-0xc]
0x6fe7c9  83c404                            add    esp,0x4
0x6fe7cc  8bc3                              mov    eax,ebx
0x6fe7ce  e88df2ffff                        call   0x6fda60
0x6fe7d3  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x6fe7d6  8b45ec                            mov    eax,DWORD PTR [ebp-0x14]
0x6fe7d9  668b55f0                          mov    dx,WORD PTR [ebp-0x10]
0x6fe7dd  03c1                              add    eax,ecx
0x6fe7df  66895634                          mov    WORD PTR [esi+0x34],dx
0x6fe7e3  894614                            mov    DWORD PTR [esi+0x14],eax
0x6fe7e6  8b10                              mov    edx,DWORD PTR [eax]
0x6fe7e8  89560c                            mov    DWORD PTR [esi+0xc],edx
0x6fe7eb  8b500c                            mov    edx,DWORD PTR [eax+0xc]
0x6fe7ee  895618                            mov    DWORD PTR [esi+0x18],edx
0x6fe7f1  8a55ff                            mov    dl,BYTE PTR [ebp-0x1]
0x6fe7f4  bf204e0000                        mov    edi,0x4e20
0x6fe7f9  885639                            mov    BYTE PTR [esi+0x39],dl
0x6fe7fc  397e30                            cmp    DWORD PTR [esi+0x30],edi
0x6fe7ff  7e3e                              jle    0x6fe83f
0x6fe801  2bc1                              sub    eax,ecx
0x6fe803  8bc8                              mov    ecx,eax
0x6fe805  b8abaaaa2a                        mov    eax,0x2aaaaaab
0x6fe80a  f7e9                              imul   ecx
0x6fe80c  c1fa02                            sar    edx,0x2
0x6fe80f  8bc2                              mov    eax,edx
0x6fe811  c1e81f                            shr    eax,0x1f
0x6fe814  8d4c0201                          lea    ecx,[edx+eax*1+0x1]
0x6fe818  3bcf                              cmp    ecx,edi
0x6fe81a  7d14                              jge    0x6fe830
0x6fe81c  e8eff4ffff                        call   0x6fdd10
0x6fe821  8b55f8                            mov    edx,DWORD PTR [ebp-0x8]
0x6fe824  895674                            mov    DWORD PTR [esi+0x74],edx
0x6fe827  8bc3                              mov    eax,ebx
0x6fe829  5f                                pop    edi
0x6fe82a  5e                                pop    esi
0x6fe82b  5b                                pop    ebx
0x6fe82c  8be5                              mov    esp,ebp
0x6fe82e  5d                                pop    ebp
0x6fe82f  c3                                ret
0x6fe830  8b45f8                            mov    eax,DWORD PTR [ebp-0x8]
0x6fe833  894674                            mov    DWORD PTR [esi+0x74],eax
0x6fe836  8bc3                              mov    eax,ebx
0x6fe838  5f                                pop    edi
0x6fe839  5e                                pop    esi
0x6fe83a  5b                                pop    ebx
0x6fe83b  8be5                              mov    esp,ebp
0x6fe83d  5d                                pop    ebp
0x6fe83e  c3                                ret
0x6fe83f  8b4df8                            mov    ecx,DWORD PTR [ebp-0x8]
0x6fe842  894e74                            mov    DWORD PTR [esi+0x74],ecx
0x6fe845  8bc3                              mov    eax,ebx
0x6fe847  5f                                pop    edi
0x6fe848  5e                                pop    esi
0x6fe849  5b                                pop    ebx
0x6fe84a  8be5                              mov    esp,ebp
0x6fe84c  5d                                pop    ebp
0x6fe84d  c3                                ret
0x6fe84e  897e74                            mov    DWORD PTR [esi+0x74],edi
0x6fe851  5f                                pop    edi
0x6fe852  5e                                pop    esi
0x6fe853  5b                                pop    ebx
0x6fe854  8be5                              mov    esp,ebp
0x6fe856  5d                                pop    ebp
0x6fe857  c3                                ret

; execute_thunk 0x6f5a50..0x6f5a6b raw 0x2f4e50 SHA256 c3431189a37ce09f00e99f43001ab20bc81d2a79a6a954b6d6f26c035ab0227d
; DoFile execution thunk calls C-to-Lua depth-counted execution
0x6f5a50  55                                push   ebp
0x6f5a51  8bec                              mov    ebp,esp
0x6f5a53  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x6f5a56  8b4804                            mov    ecx,DWORD PTR [eax+0x4]
0x6f5a59  8b10                              mov    edx,DWORD PTR [eax]
0x6f5a5b  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x6f5a5e  51                                push   ecx
0x6f5a5f  52                                push   edx
0x6f5a60  50                                push   eax
0x6f5a61  e8ea8a0000                        call   0x6fe550
0x6f5a66  83c40c                            add    esp,0xc
0x6f5a69  5d                                pop    ebp
0x6f5a6a  c3                                ret

; q_end_closure 0x568a90..0x568ae6 raw 0x167e90 SHA256 9fdad3db2e2d8987f7c3289cf61f95a79611a3bdab5c294a5ff26f191c2212a7
; Q End callback uses shared manager; return is not completion evidence
0x568a90  55                                push   ebp
0x568a91  8bec                              mov    ebp,esp
0x568a93  6aff                              push   0xffffffff
0x568a95  68c8839300                        push   0x9383c8
0x568a9a  64a100000000                      mov    eax,fs:0x0
0x568aa0  50                                push   eax
0x568aa1  83ec0c                            sub    esp,0xc
0x568aa4  a1201fd600                        mov    eax,ds:0xd61f20
0x568aa9  33c5                              xor    eax,ebp
0x568aab  50                                push   eax
0x568aac  8d45f4                            lea    eax,[ebp-0xc]
0x568aaf  64a300000000                      mov    fs:0x0,eax
0x568ab5  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x568ab8  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x568abb  33c0                              xor    eax,eax
0x568abd  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x568ac0  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x568ac3  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x568ac6  8b0d7827fe00                      mov    ecx,DWORD PTR ds:0xfe2778
0x568acc  ff158027fe00                      call   DWORD PTR ds:0xfe2780
0x568ad2  b801000000                        mov    eax,0x1
0x568ad7  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x568ada  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x568ae1  59                                pop    ecx
0x568ae2  8be5                              mov    esp,ebp
0x568ae4  5d                                pop    ebp
0x568ae5  c3                                ret

; q_running_closure 0x568af0..0x568b5e raw 0x167ef0 SHA256 9706651dd69d0fcdb94ad1b562c98cc38010613d85b2211efab1ca3f57975c45
; Q active getter returns number on incoming current L, shared owner
0x568af0  55                                push   ebp
0x568af1  8bec                              mov    ebp,esp
0x568af3  6aff                              push   0xffffffff
0x568af5  68d8879300                        push   0x9387d8
0x568afa  64a100000000                      mov    eax,fs:0x0
0x568b00  50                                push   eax
0x568b01  83ec0c                            sub    esp,0xc
0x568b04  56                                push   esi
0x568b05  a1201fd600                        mov    eax,ds:0xd61f20
0x568b0a  33c5                              xor    eax,ebp
0x568b0c  50                                push   eax
0x568b0d  8d45f4                            lea    eax,[ebp-0xc]
0x568b10  64a300000000                      mov    fs:0x0,eax
0x568b16  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x568b19  33c0                              xor    eax,eax
0x568b1b  8975e8                            mov    DWORD PTR [ebp-0x18],esi
0x568b1e  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x568b21  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x568b24  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x568b27  8b0d7827fe00                      mov    ecx,DWORD PTR ds:0xfe2778
0x568b2d  ff158427fe00                      call   DWORD PTR ds:0xfe2784
0x568b33  894508                            mov    DWORD PTR [ebp+0x8],eax
0x568b36  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x568b39  db4508                            fild   DWORD PTR [ebp+0x8]
0x568b3c  c7400803000000                    mov    DWORD PTR [eax+0x8],0x3
0x568b43  dd18                              fstp   QWORD PTR [eax]
0x568b45  83460810                          add    DWORD PTR [esi+0x8],0x10
0x568b49  b801000000                        mov    eax,0x1
0x568b4e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x568b51  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x568b58  59                                pop    ecx
0x568b59  5e                                pop    esi
0x568b5a  8be5                              mov    esp,ebp
0x568b5c  5d                                pop    ebp
0x568b5d  c3                                ret

; q_objects_stopped_closure 0x5698e0..0x56994e raw 0x168ce0 SHA256 e2a7135ad2faab599d911919f78f87d7c8a1149e36109c81d17f55495f140c63
; WaitForObjectsStop native observer returns number on incoming current L
0x5698e0  55                                push   ebp
0x5698e1  8bec                              mov    ebp,esp
0x5698e3  6aff                              push   0xffffffff
0x5698e5  68d8879300                        push   0x9387d8
0x5698ea  64a100000000                      mov    eax,fs:0x0
0x5698f0  50                                push   eax
0x5698f1  83ec0c                            sub    esp,0xc
0x5698f4  56                                push   esi
0x5698f5  a1201fd600                        mov    eax,ds:0xd61f20
0x5698fa  33c5                              xor    eax,ebp
0x5698fc  50                                push   eax
0x5698fd  8d45f4                            lea    eax,[ebp-0xc]
0x569900  64a300000000                      mov    fs:0x0,eax
0x569906  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x569909  33c0                              xor    eax,eax
0x56990b  8975e8                            mov    DWORD PTR [ebp-0x18],esi
0x56990e  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x569911  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x569914  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x569917  8b0d7827fe00                      mov    ecx,DWORD PTR ds:0xfe2778
0x56991d  ff151828fe00                      call   DWORD PTR ds:0xfe2818
0x569923  894508                            mov    DWORD PTR [ebp+0x8],eax
0x569926  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x569929  db4508                            fild   DWORD PTR [ebp+0x8]
0x56992c  c7400803000000                    mov    DWORD PTR [eax+0x8],0x3
0x569933  dd18                              fstp   QWORD PTR [eax]
0x569935  83460810                          add    DWORD PTR [esi+0x8],0x10
0x569939  b801000000                        mov    eax,0x1
0x56993e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x569941  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x569948  59                                pop    ecx
0x569949  5e                                pop    esi
0x56994a  8be5                              mov    esp,ebp
0x56994c  5d                                pop    ebp
0x56994d  c3                                ret

; coroutine_status_and_bindings 0xc0bc58..0xc0bca0 raw 0x80a258 SHA256 2de8e52774bb9d6eaaa97c289448af67513cbce049f38fa25f4ebb834b34f241
; Status string pointers followed by original coroutine library bindings
0c34c4000034c400f833c400f033c400e833c40080737000e033c400307270000c34c400c074700050eac00070707000d833c400507470008402c100807470000000000000000000

; error_object_switch 0x6fdab8..0x6fdac8 raw 0x2fceb8 SHA256 52a338375110e3e57e46b7f1f4d38a82eac290276d1d17a943b80fc185e18565
; Status 2/3/4/5 branches; not instructions
9cda6f009cda6f0072da6f0093da6f00

; vm_call_return_dispatch 0x6fd704..0x6fd710 raw 0x2fcb04 SHA256 bb458e1fdf4ebd08cd604fca1f3277ee97b48f46a4cf41fd232ba7e7eb7b7796
; Opcode 28 CALL / 29 TAILCALL / 30 RETURN targets
1ed06f0076d06f0029d66f00

; string_c0ea50 0xc0ea50..0xc0ea57 raw 0x80d050 SHA256 afda34ac84d18210ca2fa7083fcbfcb31ad44fab7d47ec0ce7a448683cc1fded
; status
73746174757300

; string_c10284 0xc10284..0xc1028a raw 0x80e884 SHA256 976f9d71279276e8fd4afce4bb7d1b5e19b44472cf8fe5521ad8e1c74310b4a9
; yield
7969656c6400

; string_c42850 0xc42850..0xc42862 raw 0x840e50 SHA256 b10b163d0b406ccd230ac757fa3da9f2c0ba382757d918fa35e5087ee9b61275
; not enough memory
6e6f7420656e6f756768206d656d6f727900

; string_c42ad4 0xc42ad4..0xc42aec raw 0x8410d4 SHA256 f0e7a66ee9b3ae54a60ee9f6887ee242c9130c5a9fd76328601c9a2e66df911c
; error in error handling
6572726f7220696e206572726f722068616e646c696e6700

; string_c42b04 0xc42b04..0xc42b15 raw 0x841104 SHA256 e36a3047158c30b756ceae54ebb91e020eec31b0bd4b2ad8b5efd8434f2544b7
; C stack overflow
4320737461636b206f766572666c6f7700

; string_c42b18 0xc42b18..0xc42b3e raw 0x841118 SHA256 42258283a3d780f025bfce8cccce48b4ef3c8c54f7fcba4bbd1ab672d4023da1
; cannot resume non-suspended coroutine
63616e6e6f7420726573756d65206e6f6e2d73757370656e64656420636f726f7574696e6500

; string_c42b40 0xc42b40..0xc42b73 raw 0x841140 SHA256 4bb8d5db0e1082c405663f0a3de0fc60d6d8f16a95e89634dacdcdc738f29185
; attempt to yield across metamethod/C-call boundary
617474656d707420746f207969656c64206163726f7373206d6574616d6574686f642f432d63616c6c20626f756e6461727900

; string_c433d8 0xc433d8..0xc433dd raw 0x8419d8 SHA256 429e09a96958ef5834dec27ce3ef09faa4082a97a7f7ad79ad63e570c6afa6e6
; wrap
7772617000

; string_c433e0 0xc433e0..0xc433e7 raw 0x8419e0 SHA256 eaf822ae4397cc697a44ce97b87a5f133524ef659e98c40292bc428deefc4d54
; resume
726573756d6500

; string_c433e8 0xc433e8..0xc433ef raw 0x8419e8 SHA256 da4186f7ad86942c422d2853fd92637e1b190b9833a514a24a912cc8c658aec5
; create
63726561746500

; string_c433f0 0xc433f0..0xc433f5 raw 0x8419f0 SHA256 a1f8e3ac026fdfdf0951eb2379aa988e366f068b17377f95a401c53e7fbe66a6
; dead
6465616400

; string_c433f8 0xc433f8..0xc433ff raw 0x8419f8 SHA256 3e4106386be5ad1f3a8daf33e61c948c4f2bced09cf118163345fd38222b563b
; normal
6e6f726d616c00

; string_c43400 0xc43400..0xc4340a raw 0x841a00 SHA256 63d4dde1c72bb6060758076aeb330f177a973d206e07fec23810d2f69919908a
; suspended
73757370656e64656400

; string_c4340c 0xc4340c..0xc43414 raw 0x841a0c SHA256 aa4ca2ac309fb64f39e2f74ca378693fc3dd4db575224757c595191c7f062bfb
; running
72756e6e696e6700

; string_c4368c 0xc4368c..0xc4369f raw 0x841c8c SHA256 8c0ba68e86d4ba534656ceb243300ba0d004406c800d69142c3270522fccf331
; coroutine expected
636f726f7574696e6520657870656374656400

; string_c436a0 0xc436a0..0xc436bd raw 0x841ca0 SHA256 10e54a820e2306c291cadf5df834917b0beffa733a998866daea982d282865b4
; too many arguments to resume
746f6f206d616e7920617267756d656e747320746f20726573756d6500

; string_c436c0 0xc436c0..0xc436db raw 0x841cc0 SHA256 7b45bb74ac2f5c55283b17cd6fe83b311daf69edcbda4113ab70f2a0a25aace4
; cannot resume %s coroutine
63616e6e6f7420726573756d6520257320636f726f7574696e6500

; string_c436dc 0xc436dc..0xc436f7 raw 0x841cdc SHA256 7129a15d1e00312ff2cf57959340fdf1315b3347f6144f380edb4844da802e89
; too many results to resume
746f6f206d616e7920726573756c747320746f20726573756d6500

; string_c436f8 0xc436f8..0xc4370e raw 0x841cf8 SHA256 d4fcef74c91facc9783b1994c05e08bb6ffcbb01cd43fd68e96068b44b02facc
; Lua function expected
4c75612066756e6374696f6e20657870656374656400

; base_error 0x705650..0x705732 raw 0x304a50 SHA256 63ba67468be972afd36ccaf600fe1e84858be4751532c2c677e552378685d849
; Original _G.error accepts first TValue; only string/number takes optional location formatting, others reach runtime_error unchanged
0x705650  55                                push   ebp
0x705651  8bec                              mov    ebp,esp
0x705653  56                                push   esi
0x705654  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x705657  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x70565a  57                                push   edi
0x70565b  bf10000000                        mov    edi,0x10
0x705660  03c7                              add    eax,edi
0x705662  3b4608                            cmp    eax,DWORD PTR [esi+0x8]
0x705665  730d                              jae    0x705674
0x705667  3dc8bfc000                        cmp    eax,0xc0bfc8
0x70566c  7406                              je     0x705674
0x70566e  83780800                          cmp    DWORD PTR [eax+0x8],0x0
0x705672  7f07                              jg     0x70567b
0x705674  b801000000                        mov    eax,0x1
0x705679  eb0b                              jmp    0x705686
0x70567b  6a02                              push   0x2
0x70567d  56                                push   esi
0x70567e  e8ed0cffff                        call   0x6f6370
0x705683  83c408                            add    esp,0x8
0x705686  8b4e0c                            mov    ecx,DWORD PTR [esi+0xc]
0x705689  03cf                              add    ecx,edi
0x70568b  394e08                            cmp    DWORD PTR [esi+0x8],ecx
0x70568e  7317                              jae    0x7056a7
0x705690  8b5608                            mov    edx,DWORD PTR [esi+0x8]
0x705693  c7420800000000                    mov    DWORD PTR [edx+0x8],0x0
0x70569a  017e08                            add    DWORD PTR [esi+0x8],edi
0x70569d  8b4e0c                            mov    ecx,DWORD PTR [esi+0xc]
0x7056a0  03cf                              add    ecx,edi
0x7056a2  394e08                            cmp    DWORD PTR [esi+0x8],ecx
0x7056a5  72e9                              jb     0x705690
0x7056a7  8b560c                            mov    edx,DWORD PTR [esi+0xc]
0x7056aa  03d7                              add    edx,edi
0x7056ac  8d7af0                            lea    edi,[edx-0x10]
0x7056af  895608                            mov    DWORD PTR [esi+0x8],edx
0x7056b2  3bfa                              cmp    edi,edx
0x7056b4  736f                              jae    0x705725
0x7056b6  81ffc8bfc000                      cmp    edi,0xc0bfc8
0x7056bc  7467                              je     0x705725
0x7056be  8b7f08                            mov    edi,DWORD PTR [edi+0x8]
0x7056c1  83ff04                            cmp    edi,0x4
0x7056c4  7405                              je     0x7056cb
0x7056c6  83ff03                            cmp    edi,0x3
0x7056c9  755a                              jne    0x705725
0x7056cb  85c0                              test   eax,eax
0x7056cd  7e56                              jle    0x705725
0x7056cf  8bc8                              mov    ecx,eax
0x7056d1  e8ba07ffff                        call   0x6f5e90
0x7056d6  8b4e0c                            mov    ecx,DWORD PTR [esi+0xc]
0x7056d9  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x7056dc  3bc8                              cmp    ecx,eax
0x7056de  7205                              jb     0x7056e5
0x7056e0  b9c8bfc000                        mov    ecx,0xc0bfc8
0x7056e5  8b11                              mov    edx,DWORD PTR [ecx]
0x7056e7  8910                              mov    DWORD PTR [eax],edx
0x7056e9  8b5104                            mov    edx,DWORD PTR [ecx+0x4]
0x7056ec  895004                            mov    DWORD PTR [eax+0x4],edx
0x7056ef  8b4908                            mov    ecx,DWORD PTR [ecx+0x8]
0x7056f2  894808                            mov    DWORD PTR [eax+0x8],ecx
0x7056f5  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x7056f8  83460810                          add    DWORD PTR [esi+0x8],0x10
0x7056fc  8b5044                            mov    edx,DWORD PTR [eax+0x44]
0x7056ff  3b5040                            cmp    edx,DWORD PTR [eax+0x40]
0x705702  7207                              jb     0x70570b
0x705704  8bc6                              mov    eax,esi
0x705706  e8955cffff                        call   0x6fb3a0
0x70570b  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x70570e  2b460c                            sub    eax,DWORD PTR [esi+0xc]
0x705711  c1f804                            sar    eax,0x4
0x705714  48                                dec    eax
0x705715  50                                push   eax
0x705716  6a02                              push   0x2
0x705718  56                                push   esi
0x705719  e86269ffff                        call   0x6fc080
0x70571e  83c40c                            add    esp,0xc
0x705721  834608f0                          add    DWORD PTR [esi+0x8],0xfffffff0
0x705725  8bc6                              mov    eax,esi
0x705727  e8a433ffff                        call   0x6f8ad0
0x70572c  5f                                pop    edi
0x70572d  33c0                              xor    eax,eax
0x70572f  5e                                pop    esi
0x705730  5d                                pop    ebp
0x705731  c3                                ret

; base_pcall 0x706ac0..0x706b63 raw 0x305ec0 SHA256 9a9bb553c4fabff0cdd62469c57b30551d8f97ec9ae1fff051294ea4066f6765
; Original pcall uses same-state execute_thunk/protected_call; additional C-to-Lua boundary
0x706ac0  55                                push   ebp
0x706ac1  8bec                              mov    ebp,esp
0x706ac3  83e4f8                            and    esp,0xfffffff8
0x706ac6  83ec08                            sub    esp,0x8
0x706ac9  56                                push   esi
0x706aca  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x706acd  8b460c                            mov    eax,DWORD PTR [esi+0xc]
0x706ad0  57                                push   edi
0x706ad1  3b4608                            cmp    eax,DWORD PTR [esi+0x8]
0x706ad4  730d                              jae    0x706ae3
0x706ad6  3dc8bfc000                        cmp    eax,0xc0bfc8
0x706adb  7406                              je     0x706ae3
0x706add  837808ff                          cmp    DWORD PTR [eax+0x8],0xffffffff
0x706ae1  750f                              jne    0x706af2
0x706ae3  6a01                              push   0x1
0x706ae5  bfb027c400                        mov    edi,0xc427b0
0x706aea  e8b1f2feff                        call   0x6f5da0
0x706aef  83c404                            add    esp,0x4
0x706af2  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x706af5  8bc8                              mov    ecx,eax
0x706af7  2b4e0c                            sub    ecx,DWORD PTR [esi+0xc]
0x706afa  8d542408                          lea    edx,[esp+0x8]
0x706afe  83e1f0                            and    ecx,0xfffffff0
0x706b01  2bc1                              sub    eax,ecx
0x706b03  89442408                          mov    DWORD PTR [esp+0x8],eax
0x706b07  2b4620                            sub    eax,DWORD PTR [esi+0x20]
0x706b0a  c744240cffffffff                  mov    DWORD PTR [esp+0xc],0xffffffff
0x706b12  50                                push   eax
0x706b13  52                                push   edx
0x706b14  68505a6f00                        push   0x6f5a50
0x706b19  33d2                              xor    edx,edx
0x706b1b  8bc6                              mov    eax,esi
0x706b1d  e84e7cffff                        call   0x6fe770
0x706b22  8b4e14                            mov    ecx,DWORD PTR [esi+0x14]
0x706b25  8b5608                            mov    edx,DWORD PTR [esi+0x8]
0x706b28  83c40c                            add    esp,0xc
0x706b2b  3b5108                            cmp    edx,DWORD PTR [ecx+0x8]
0x706b2e  7203                              jb     0x706b33
0x706b30  895108                            mov    DWORD PTR [ecx+0x8],edx
0x706b33  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x706b36  33d2                              xor    edx,edx
0x706b38  85c0                              test   eax,eax
0x706b3a  0f94c2                            sete   dl
0x706b3d  c7410801000000                    mov    DWORD PTR [ecx+0x8],0x1
0x706b44  b801000000                        mov    eax,0x1
0x706b49  8911                              mov    DWORD PTR [ecx],edx
0x706b4b  83460810                          add    DWORD PTR [esi+0x8],0x10
0x706b4f  e85ce7feff                        call   0x6f52b0
0x706b54  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x706b57  2b460c                            sub    eax,DWORD PTR [esi+0xc]
0x706b5a  5f                                pop    edi
0x706b5b  c1f804                            sar    eax,0x4
0x706b5e  5e                                pop    esi
0x706b5f  8be5                              mov    esp,ebp
0x706b61  5d                                pop    ebp
0x706b62  c3                                ret

; base_register_prefix 0x707580..0x7075ed raw 0x306980 SHA256 9e162cec3dfe345b74947d0766f11a51328db21fb48261c305754eeabac9d7e1
; Necessary straight-line prefix through _G base binding-table registration, not the entire initializer
0x707580  55                                push   ebp
0x707581  8bec                              mov    ebp,esp
0x707583  83e4f8                            and    esp,0xfffffff8
0x707586  83ec14                            sub    esp,0x14
0x707589  53                                push   ebx
0x70758a  56                                push   esi
0x70758b  8bf0                              mov    esi,eax
0x70758d  8b4e48                            mov    ecx,DWORD PTR [esi+0x48]
0x707590  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x707593  57                                push   edi
0x707594  8d7e48                            lea    edi,[esi+0x48]
0x707597  8908                              mov    DWORD PTR [eax],ecx
0x707599  8b5704                            mov    edx,DWORD PTR [edi+0x4]
0x70759c  895004                            mov    DWORD PTR [eax+0x4],edx
0x70759f  8b4f08                            mov    ecx,DWORD PTR [edi+0x8]
0x7075a2  6a02                              push   0x2
0x7075a4  681037c400                        push   0xc43710
0x7075a9  894808                            mov    DWORD PTR [eax+0x8],ecx
0x7075ac  83460810                          add    DWORD PTR [esi+0x8],0x10
0x7075b0  56                                push   esi
0x7075b1  e8ba76ffff                        call   0x6fec70
0x7075b6  8b5608                            mov    edx,DWORD PTR [esi+0x8]
0x7075b9  83c40c                            add    esp,0xc
0x7075bc  83ea10                            sub    edx,0x10
0x7075bf  52                                push   edx
0x7075c0  89442414                          mov    DWORD PTR [esp+0x14],eax
0x7075c4  8d442414                          lea    eax,[esp+0x14]
0x7075c8  50                                push   eax
0x7075c9  57                                push   edi
0x7075ca  56                                push   esi
0x7075cb  c744242804000000                  mov    DWORD PTR [esp+0x28],0x4
0x7075d3  e8c843ffff                        call   0x6fb9a0
0x7075d8  834608f0                          add    DWORD PTR [esi+0x8],0xfffffff0
0x7075dc  6890bbc000                        push   0xc0bb90
0x7075e1  681037c400                        push   0xc43710
0x7075e6  8bc6                              mov    eax,esi
0x7075e8  e8a3effeff                        call   0x6f6590

; base_and_coroutine_open 0x707790..0x7077ba raw 0x306b90 SHA256 8e10b77878812fdf6ba21d69f210b702f70728b8feb3c8db5a18e5695a126c20
; Original library opener calls base initializer then coroutine table registration
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

; base_binding_error 0xc0bba8..0xc0bbb0 raw 0x80a1a8 SHA256 fdcf67a228bebb5eb0649bd8dc3e0aa63e698ae8daa96edd18466a189853e0fb
; Original base binding error
8c34c40050567000

; string_c4348c 0xc4348c..0xc43492 raw 0x841a8c SHA256 6e7af28ae2a03270bca8d371a066a6dc7471eb8303e6f1c7e4c60c155dee70d3
; error
6572726f7200

; base_binding_pcall 0xc0bbe8..0xc0bbf0 raw 0x80a1e8 SHA256 80c5a0e9e0c133b55a6bda09252a1b3296047b81a78db1ae3725ea673e706e5b
; Original base binding pcall
5c34c400c06a7000

; string_c4345c 0xc4345c..0xc43462 raw 0x841a5c SHA256 e94915dda0bbef302beb1cbb477f408400498ec4bde114740d30074f931b614b
; pcall
7063616c6c00

; string_c43710 0xc43710..0xc43713 raw 0x841d10 SHA256 71b294944f65f97aadd1af8d3c255b85c08e7c36747e3505d913c637df528811
; _G
5f4700
