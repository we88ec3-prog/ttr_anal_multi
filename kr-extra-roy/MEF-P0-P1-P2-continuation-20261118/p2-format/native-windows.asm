; MOUNT_WALK REVERIFIED_EXISTING: directory kind gate, AttachedPackage read, success-only provider assignment and recursion
; VA 007135b0..00713735 raw 003129b0 sha256 54fcd5ee7bf1a4e74414e12c2f992d270a90d5da3cc0805df2046bfeb03ec272
007135b0  55                                push   ebp
007135b1  8bec                              mov    ebp,esp
007135b3  6aff                              push   0xffffffff
007135b5  683ece9100                        push   0x91ce3e
007135ba  64a100000000                      mov    eax,fs:0x0
007135c0  50                                push   eax
007135c1  81ec14020000                      sub    esp,0x214
007135c7  a1201fd600                        mov    eax,ds:0xd61f20
007135cc  33c5                              xor    eax,ebp
007135ce  8945f0                            mov    DWORD PTR [ebp-0x10],eax
007135d1  53                                push   ebx
007135d2  56                                push   esi
007135d3  57                                push   edi
007135d4  50                                push   eax
007135d5  8d45f4                            lea    eax,[ebp-0xc]
007135d8  64a300000000                      mov    fs:0x0,eax
007135de  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
007135e1  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
007135e4  8b5514                            mov    edx,DWORD PTR [ebp+0x14]
007135e7  8985e8fdffff                      mov    DWORD PTR [ebp-0x218],eax
007135ed  8b01                              mov    eax,DWORD PTR [ecx]
007135ef  8995ecfdffff                      mov    DWORD PTR [ebp-0x214],edx
007135f5  8b5014                            mov    edx,DWORD PTR [eax+0x14]
007135f8  ffd2                              call   edx
007135fa  8bf0                              mov    esi,eax
007135fc  85f6                              test   esi,esi
007135fe  0f8415010000                      je     0x713719
00713604  8b06                              mov    eax,DWORD PTR [esi]
00713606  8b500c                            mov    edx,DWORD PTR [eax+0xc]
00713609  8bce                              mov    ecx,esi
0071360b  ffd2                              call   edx
0071360d  83f801                            cmp    eax,0x1
00713610  0f85f8000000                      jne    0x71370e
00713616  8b06                              mov    eax,DWORD PTR [esi]
00713618  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0071361b  8bce                              mov    ecx,esi
0071361d  ffd2                              call   edx
0071361f  8b8de8fdffff                      mov    ecx,DWORD PTR [ebp-0x218]
00713625  50                                push   eax
00713626  e825170000                        call   0x714d50
0071362b  8bd8                              mov    ebx,eax
0071362d  8b06                              mov    eax,DWORD PTR [esi]
0071362f  8b5038                            mov    edx,DWORD PTR [eax+0x38]
00713632  685841c400                        push   0xc44158
00713637  8bce                              mov    ecx,esi
00713639  ffd2                              call   edx
0071363b  8bf8                              mov    edi,eax
0071363d  85ff                              test   edi,edi
0071363f  0f84b4000000                      je     0x7136f9
00713645  8b07                              mov    eax,DWORD PTR [edi]
00713647  8b5020                            mov    edx,DWORD PTR [eax+0x20]
0071364a  8bcf                              mov    ecx,edi
0071364c  ffd2                              call   edx
0071364e  f7d8                              neg    eax
00713650  1bc0                              sbb    eax,eax
00713652  23c7                              and    eax,edi
00713654  0f849f000000                      je     0x7136f9
0071365a  8bb818010000                      mov    edi,DWORD PTR [eax+0x118]
00713660  68ff010000                        push   0x1ff
00713665  8d85f1fdffff                      lea    eax,[ebp-0x20f]
0071366b  6a00                              push   0x0
0071366d  50                                push   eax
0071366e  c685f0fdffff00                    mov    BYTE PTR [ebp-0x210],0x0
00713675  e8e6b11800                        call   0x89e860
0071367a  8b4f4c                            mov    ecx,DWORD PTR [edi+0x4c]
0071367d  8b5748                            mov    edx,DWORD PTR [edi+0x48]
00713680  83c40c                            add    esp,0xc
00713683  51                                push   ecx
00713684  52                                push   edx
00713685  8d85f0fdffff                      lea    eax,[ebp-0x210]
0071368b  50                                push   eax
0071368c  e83fa51800                        call   0x89dbd0
00713691  83c40c                            add    esp,0xc
00713694  6878010000                        push   0x178
00713699  e8cadb1700                        call   0x891268
0071369e  83c404                            add    esp,0x4
007136a1  8985e4fdffff                      mov    DWORD PTR [ebp-0x21c],eax
007136a7  33ff                              xor    edi,edi
007136a9  897dfc                            mov    DWORD PTR [ebp-0x4],edi
007136ac  3bc7                              cmp    eax,edi
007136ae  7408                              je     0x7136b8
007136b0  50                                push   eax
007136b1  e8ba1b0000                        call   0x715270
007136b6  8bf8                              mov    edi,eax
007136b8  6a01                              push   0x1
007136ba  8d95f0fdffff                      lea    edx,[ebp-0x210]
007136c0  8bcf                              mov    ecx,edi
007136c2  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
007136c9  e8521f0000                        call   0x715620
007136ce  85c0                              test   eax,eax
007136d0  7508                              jne    0x7136da
007136d2  89bb00010000                      mov    DWORD PTR [ebx+0x100],edi
007136d8  eb1f                              jmp    0x7136f9
007136da  83f8ff                            cmp    eax,0xffffffff
007136dd  740c                              je     0x7136eb
007136df  8b8decfdffff                      mov    ecx,DWORD PTR [ebp-0x214]
007136e5  c70101000000                      mov    DWORD PTR [ecx],0x1
007136eb  85ff                              test   edi,edi
007136ed  740a                              je     0x7136f9
007136ef  8b17                              mov    edx,DWORD PTR [edi]
007136f1  8b02                              mov    eax,DWORD PTR [edx]
007136f3  6a01                              push   0x1
007136f5  8bcf                              mov    ecx,edi
007136f7  ffd0                              call   eax
007136f9  8b8decfdffff                      mov    ecx,DWORD PTR [ebp-0x214]
007136ff  8b5510                            mov    edx,DWORD PTR [ebp+0x10]
00713702  51                                push   ecx
00713703  52                                push   edx
00713704  53                                push   ebx
00713705  56                                push   esi
00713706  e8a5feffff                        call   0x7135b0
0071370b  83c410                            add    esp,0x10
0071370e  8b7608                            mov    esi,DWORD PTR [esi+0x8]
00713711  85f6                              test   esi,esi
00713713  0f85ebfeffff                      jne    0x713604
00713719  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0071371c  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00713723  59                                pop    ecx
00713724  5f                                pop    edi
00713725  5e                                pop    esi
00713726  5b                                pop    ebx
00713727  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
0071372a  33cd                              xor    ecx,ebp
0071372c  e8d0d81700                        call   0x891001
00713731  8be5                              mov    esp,ebp
00713733  5d                                pop    ebp
00713734  c3                                ret

; MASTER_INIT REVERIFIED_EXISTING: Master0z and EncSetting; no new MEF parser claim
; VA 00713740..007138e0 raw 00312b40 sha256 275c09cbf765e62234a8dffb9c71ba2e545e42d878b0d02cc8397a08bc08815b
00713740  55                                push   ebp
00713741  8bec                              mov    ebp,esp
00713743  6aff                              push   0xffffffff
00713745  680df49100                        push   0x91f40d
0071374a  64a100000000                      mov    eax,fs:0x0
00713750  50                                push   eax
00713751  81ec8c010000                      sub    esp,0x18c
00713757  a1201fd600                        mov    eax,ds:0xd61f20
0071375c  33c5                              xor    eax,ebp
0071375e  8945ec                            mov    DWORD PTR [ebp-0x14],eax
00713761  56                                push   esi
00713762  57                                push   edi
00713763  50                                push   eax
00713764  8d45f4                            lea    eax,[ebp-0xc]
00713767  64a300000000                      mov    fs:0x0,eax
0071376d  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
00713770  8d8d74feffff                      lea    ecx,[ebp-0x18c]
00713776  51                                push   ecx
00713777  898568feffff                      mov    DWORD PTR [ebp-0x198],eax
0071377d  e8ee1a0000                        call   0x715270
00713782  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
00713789  6a01                              push   0x1
0071378b  ba6056c000                        mov    edx,0xc05660
00713790  8d8d74feffff                      lea    ecx,[ebp-0x18c]
00713796  c7856cfeffff01000000              mov    DWORD PTR [ebp-0x194],0x1
007137a0  e87b1e0000                        call   0x715620
007137a5  85c0                              test   eax,eax
007137a7  741a                              je     0x7137c3
007137a9  8d9574feffff                      lea    edx,[ebp-0x18c]
007137af  52                                push   edx
007137b0  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
007137b7  e8c41b0000                        call   0x715380
007137bc  33c0                              xor    eax,eax
007137be  e900010000                        jmp    0x7138c3
007137c3  8b7dac                            mov    edi,DWORD PTR [ebp-0x54]
007137c6  e8f54f0000                        call   0x7187c0
007137cb  8d8d80feffff                      lea    ecx,[ebp-0x180]
007137d1  b86856c000                        mov    eax,0xc05668
007137d6  8a10                              mov    dl,BYTE PTR [eax]
007137d8  3a11                              cmp    dl,BYTE PTR [ecx]
007137da  751a                              jne    0x7137f6
007137dc  84d2                              test   dl,dl
007137de  7412                              je     0x7137f2
007137e0  8a5001                            mov    dl,BYTE PTR [eax+0x1]
007137e3  3a5101                            cmp    dl,BYTE PTR [ecx+0x1]
007137e6  750e                              jne    0x7137f6
007137e8  83c002                            add    eax,0x2
007137eb  83c102                            add    ecx,0x2
007137ee  84d2                              test   dl,dl
007137f0  75e4                              jne    0x7137d6
007137f2  33c0                              xor    eax,eax
007137f4  eb05                              jmp    0x7137fb
007137f6  1bc0                              sbb    eax,eax
007137f8  83d8ff                            sbb    eax,0xffffffff
007137fb  85c0                              test   eax,eax
007137fd  741a                              je     0x713819
007137ff  8d8574feffff                      lea    eax,[ebp-0x18c]
00713805  50                                push   eax
00713806  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0071380d  e86e1b0000                        call   0x715380
00713812  33c0                              xor    eax,eax
00713814  e9aa000000                        jmp    0x7138c3
00713819  686841c400                        push   0xc44168
0071381e  8d8d74feffff                      lea    ecx,[ebp-0x18c]
00713824  e8e73b0000                        call   0x717410
00713829  8bf0                              mov    esi,eax
0071382b  85f6                              test   esi,esi
0071382d  743b                              je     0x71386a
0071382f  8b16                              mov    edx,DWORD PTR [esi]
00713831  8b4220                            mov    eax,DWORD PTR [edx+0x20]
00713834  8bce                              mov    ecx,esi
00713836  ffd0                              call   eax
00713838  f7d8                              neg    eax
0071383a  1bc0                              sbb    eax,eax
0071383c  23c6                              and    eax,esi
0071383e  742a                              je     0x71386a
00713840  8b8018010000                      mov    eax,DWORD PTR [eax+0x118]
00713846  83784c04                          cmp    DWORD PTR [eax+0x4c],0x4
0071384a  7417                              je     0x713863
0071384c  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
00713853  8d8d74feffff                      lea    ecx,[ebp-0x18c]
00713859  51                                push   ecx
0071385a  e8211b0000                        call   0x715380
0071385f  33c0                              xor    eax,eax
00713861  eb60                              jmp    0x7138c3
00713863  8b5048                            mov    edx,DWORD PTR [eax+0x48]
00713866  8b02                              mov    eax,DWORD PTR [edx]
00713868  eb06                              jmp    0x713870
0071386a  8b856cfeffff                      mov    eax,DWORD PTR [ebp-0x194]
00713870  8b9568feffff                      mov    edx,DWORD PTR [ebp-0x198]
00713876  8d8d70feffff                      lea    ecx,[ebp-0x190]
0071387c  51                                push   ecx
0071387d  50                                push   eax
0071387e  83c204                            add    edx,0x4
00713881  52                                push   edx
00713882  8d8574feffff                      lea    eax,[ebp-0x18c]
00713888  50                                push   eax
00713889  c78570feffff00000000              mov    DWORD PTR [ebp-0x190],0x0
00713893  e818fdffff                        call   0x7135b0
00713898  83c410                            add    esp,0x10
0071389b  8dbd74feffff                      lea    edi,[ebp-0x18c]
007138a1  e85a220000                        call   0x715b00
007138a6  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
007138ad  83bd70feffff00                    cmp    DWORD PTR [ebp-0x190],0x0
007138b4  759d                              jne    0x713853
007138b6  8bd7                              mov    edx,edi
007138b8  52                                push   edx
007138b9  e8c21a0000                        call   0x715380
007138be  b801000000                        mov    eax,0x1
007138c3  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
007138c6  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
007138cd  59                                pop    ecx
007138ce  5f                                pop    edi
007138cf  5e                                pop    esi
007138d0  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
007138d3  33cd                              xor    ecx,ebp
007138d5  e827d71700                        call   0x891001
007138da  8be5                              mov    esp,ebp
007138dc  5d                                pop    ebp
007138dd  c20400                            ret    0x4

; STP_OPEN REVERIFIED_EXISTING: append .stp, generic file open and STP container header/index routing
; VA 00715620..00715afa raw 00314a20 sha256 fe24d244241ce189de0d3e62ed66300e748aaafcb201f38cabe69194c75d876a
00715620  55                                push   ebp
00715621  8bec                              mov    ebp,esp
00715623  6aff                              push   0xffffffff
00715625  68d6cd9100                        push   0x91cdd6
0071562a  64a100000000                      mov    eax,fs:0x0
00715630  50                                push   eax
00715631  81ec50060000                      sub    esp,0x650
00715637  a1201fd600                        mov    eax,ds:0xd61f20
0071563c  33c5                              xor    eax,ebp
0071563e  8945ec                            mov    DWORD PTR [ebp-0x14],eax
00715641  53                                push   ebx
00715642  56                                push   esi
00715643  57                                push   edi
00715644  50                                push   eax
00715645  8d45f4                            lea    eax,[ebp-0xc]
00715648  64a300000000                      mov    fs:0x0,eax
0071564e  8bf2                              mov    esi,edx
00715650  8bf9                              mov    edi,ecx
00715652  8bc6                              mov    eax,esi
00715654  89bda8f9ffff                      mov    DWORD PTR [ebp-0x658],edi
0071565a  8d5001                            lea    edx,[eax+0x1]
0071565d  33db                              xor    ebx,ebx
0071565f  90                                nop
00715660  8a08                              mov    cl,BYTE PTR [eax]
00715662  40                                inc    eax
00715663  3acb                              cmp    cl,bl
00715665  75f9                              jne    0x715660
00715667  2bc2                              sub    eax,edx
00715669  50                                push   eax
0071566a  81c758010000                      add    edi,0x158
00715670  56                                push   esi
00715671  8bcf                              mov    ecx,edi
00715673  e8f8d3ceff                        call   0x402a70
00715678  837f1410                          cmp    DWORD PTR [edi+0x14],0x10
0071567c  7202                              jb     0x715680
0071567e  8b3f                              mov    edi,DWORD PTR [edi]
00715680  57                                push   edi
00715681  8bbda8f9ffff                      mov    edi,DWORD PTR [ebp-0x658]
00715687  8d470c                            lea    eax,[edi+0xc]
0071568a  6800010000                        push   0x100
0071568f  50                                push   eax
00715690  e8c4e41700                        call   0x893b59
00715695  83c40c                            add    esp,0xc
00715698  c785b4f9ffff8044c400              mov    DWORD PTR [ebp-0x64c],0xc44480
007156a2  c785b8f9ffff9c44c400              mov    DWORD PTR [ebp-0x648],0xc4449c
007156ac  c785bcf9ffffa844c400              mov    DWORD PTR [ebp-0x644],0xc444a8
007156b6  899dc0f9ffff                      mov    DWORD PTR [ebp-0x640],ebx
007156bc  889dc4fbffff                      mov    BYTE PTR [ebp-0x43c],bl
007156c2  889dc4f9ffff                      mov    BYTE PTR [ebp-0x63c],bl
007156c8  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
007156cb  8bc6                              mov    eax,esi
007156cd  c785e4fbffff0f000000              mov    DWORD PTR [ebp-0x41c],0xf
007156d7  899de0fbffff                      mov    DWORD PTR [ebp-0x420],ebx
007156dd  889dd0fbffff                      mov    BYTE PTR [ebp-0x430],bl
007156e3  8d5001                            lea    edx,[eax+0x1]
007156e6  8a08                              mov    cl,BYTE PTR [eax]
007156e8  40                                inc    eax
007156e9  3acb                              cmp    cl,bl
007156eb  75f9                              jne    0x7156e6
007156ed  2bc2                              sub    eax,edx
007156ef  50                                push   eax
007156f0  56                                push   esi
007156f1  8d8dd0fbffff                      lea    ecx,[ebp-0x430]
007156f7  e874d3ceff                        call   0x402a70
007156fc  6a04                              push   0x4
007156fe  683056c000                        push   0xc05630
00715703  8d8dd0fbffff                      lea    ecx,[ebp-0x430]
00715709  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0071570d  e8aec8ceff                        call   0x401fc0
00715712  83bde4fbffff10                    cmp    DWORD PTR [ebp-0x41c],0x10
00715719  8bb5d0fbffff                      mov    esi,DWORD PTR [ebp-0x430]
0071571f  889dacf9ffff                      mov    BYTE PTR [ebp-0x654],bl
00715725  7306                              jae    0x71572d
00715727  8db5d0fbffff                      lea    esi,[ebp-0x430]
0071572d  68ff030000                        push   0x3ff
00715732  8d8dedfbffff                      lea    ecx,[ebp-0x413]
00715738  53                                push   ebx
00715739  51                                push   ecx
0071573a  889decfbffff                      mov    BYTE PTR [ebp-0x414],bl
00715740  e81b911800                        call   0x89e860
00715745  83c40c                            add    esp,0xc
00715748  56                                push   esi
00715749  8d95ecfbffff                      lea    edx,[ebp-0x414]
0071574f  6800040000                        push   0x400
00715754  52                                push   edx
00715755  e8ab041800                        call   0x895c05
0071575a  83c40c                            add    esp,0xc
0071575d  68e0d1be00                        push   0xbed1e0
00715762  8d85b0f9ffff                      lea    eax,[ebp-0x650]
00715768  6a04                              push   0x4
0071576a  50                                push   eax
0071576b  e8e9e31700                        call   0x893b59
00715770  83c40c                            add    esp,0xc
00715773  8d8db0f9ffff                      lea    ecx,[ebp-0x650]
00715779  51                                push   ecx
0071577a  8d95ecfbffff                      lea    edx,[ebp-0x414]
00715780  52                                push   edx
00715781  889dc4fbffff                      mov    BYTE PTR [ebp-0x43c],bl
00715787  e8e4efffff                        call   0x714770
0071578c  83c408                            add    esp,0x8
0071578f  3bc3                              cmp    eax,ebx
00715791  747c                              je     0x71580f
00715793  8d8db4f9ffff                      lea    ecx,[ebp-0x64c]
00715799  8985c0f9ffff                      mov    DWORD PTR [ebp-0x640],eax
0071579f  e81c2a0000                        call   0x7181c0
007157a4  85c0                              test   eax,eax
007157a6  0f859b000000                      jne    0x715847
007157ac  8b8dc0f9ffff                      mov    ecx,DWORD PTR [ebp-0x640]
007157b2  3bcb                              cmp    ecx,ebx
007157b4  7407                              je     0x7157bd
007157b6  8b01                              mov    eax,DWORD PTR [ecx]
007157b8  8b5004                            mov    edx,DWORD PTR [eax+0x4]
007157bb  ffd2                              call   edx
007157bd  8b95d0fbffff                      mov    edx,DWORD PTR [ebp-0x430]
007157c3  be10000000                        mov    esi,0x10
007157c8  899dc0f9ffff                      mov    DWORD PTR [ebp-0x640],ebx
007157ce  39b5e4fbffff                      cmp    DWORD PTR [ebp-0x41c],esi
007157d4  7306                              jae    0x7157dc
007157d6  8d95d0fbffff                      lea    edx,[ebp-0x430]
007157dc  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
007157df  8b8f38010000                      mov    ecx,DWORD PTR [edi+0x138]
007157e5  50                                push   eax
007157e6  53                                push   ebx
007157e7  e8e4300000                        call   0x7188d0
007157ec  85c0                              test   eax,eax
007157ee  7427                              je     0x715817
007157f0  39b5e4fbffff                      cmp    DWORD PTR [ebp-0x41c],esi
007157f6  720f                              jb     0x715807
007157f8  8b8dd0fbffff                      mov    ecx,DWORD PTR [ebp-0x430]
007157fe  51                                push   ecx
007157ff  e808ba1700                        call   0x89120c
00715804  83c404                            add    esp,0x4
00715807  83c8ff                            or     eax,0xffffffff
0071580a  e9cd020000                        jmp    0x715adc
0071580f  899dc0f9ffff                      mov    DWORD PTR [ebp-0x640],ebx
00715815  eb67                              jmp    0x71587e
00715817  8b8738010000                      mov    eax,DWORD PTR [edi+0x138]
0071581d  8b4824                            mov    ecx,DWORD PTR [eax+0x24]
00715820  8b11                              mov    edx,DWORD PTR [ecx]
00715822  8b02                              mov    eax,DWORD PTR [edx]
00715824  53                                push   ebx
00715825  ffd0                              call   eax
00715827  39b5e4fbffff                      cmp    DWORD PTR [ebp-0x41c],esi
0071582d  0f82a7020000                      jb     0x715ada
00715833  8b8dd0fbffff                      mov    ecx,DWORD PTR [ebp-0x430]
00715839  51                                push   ecx
0071583a  e8cdb91700                        call   0x89120c
0071583f  83c404                            add    esp,0x4
00715842  e993020000                        jmp    0x715ada
00715847  8db5b8f9ffff                      lea    esi,[ebp-0x648]
0071584d  e80e2c0000                        call   0x718460
00715852  8b8dc0f9ffff                      mov    ecx,DWORD PTR [ebp-0x640]
00715858  8bf0                              mov    esi,eax
0071585a  3bcb                              cmp    ecx,ebx
0071585c  7407                              je     0x715865
0071585e  8b11                              mov    edx,DWORD PTR [ecx]
00715860  8b4204                            mov    eax,DWORD PTR [edx+0x4]
00715863  ffd0                              call   eax
00715865  899dc0f9ffff                      mov    DWORD PTR [ebp-0x640],ebx
0071586b  81fe44505453                      cmp    esi,0x53545044
00715871  0f8575010000                      jne    0x7159ec
00715877  c685acf9ffffff                    mov    BYTE PTR [ebp-0x654],0xff
0071587e  8bb5d0fbffff                      mov    esi,DWORD PTR [ebp-0x430]
00715884  bf10000000                        mov    edi,0x10
00715889  39bde4fbffff                      cmp    DWORD PTR [ebp-0x41c],edi
0071588f  7306                              jae    0x715897
00715891  8db5d0fbffff                      lea    esi,[ebp-0x430]
00715897  68ff030000                        push   0x3ff
0071589c  8d95edfbffff                      lea    edx,[ebp-0x413]
007158a2  53                                push   ebx
007158a3  52                                push   edx
007158a4  889decfbffff                      mov    BYTE PTR [ebp-0x414],bl
007158aa  e8b18f1800                        call   0x89e860
007158af  83c40c                            add    esp,0xc
007158b2  56                                push   esi
007158b3  8d85ecfbffff                      lea    eax,[ebp-0x414]
007158b9  6800040000                        push   0x400
007158be  50                                push   eax
007158bf  e841031800                        call   0x895c05
007158c4  83c40c                            add    esp,0xc
007158c7  68e0d1be00                        push   0xbed1e0
007158cc  8d8db0f9ffff                      lea    ecx,[ebp-0x650]
007158d2  6a04                              push   0x4
007158d4  51                                push   ecx
007158d5  e87fe21700                        call   0x893b59
007158da  8a95acf9ffff                      mov    dl,BYTE PTR [ebp-0x654]
007158e0  83c40c                            add    esp,0xc
007158e3  8d85b0f9ffff                      lea    eax,[ebp-0x650]
007158e9  50                                push   eax
007158ea  8d8decfbffff                      lea    ecx,[ebp-0x414]
007158f0  51                                push   ecx
007158f1  8895c4fbffff                      mov    BYTE PTR [ebp-0x43c],dl
007158f7  e874eeffff                        call   0x714770
007158fc  83c408                            add    esp,0x8
007158ff  3bc3                              cmp    eax,ebx
00715901  7459                              je     0x71595c
00715903  8985c0f9ffff                      mov    DWORD PTR [ebp-0x640],eax
00715909  8b10                              mov    edx,DWORD PTR [eax]
0071590b  53                                push   ebx
0071590c  8bc8                              mov    ecx,eax
0071590e  8b4234                            mov    eax,DWORD PTR [edx+0x34]
00715911  6a04                              push   0x4
00715913  ffd0                              call   eax
00715915  85c0                              test   eax,eax
00715917  7911                              jns    0x71592a
00715919  8b8dc0f9ffff                      mov    ecx,DWORD PTR [ebp-0x640]
0071591f  3bcb                              cmp    ecx,ebx
00715921  7407                              je     0x71592a
00715923  8b11                              mov    edx,DWORD PTR [ecx]
00715925  8b421c                            mov    eax,DWORD PTR [edx+0x1c]
00715928  ffd0                              call   eax
0071592a  8b95b8f9ffff                      mov    edx,DWORD PTR [ebp-0x648]
00715930  8b02                              mov    eax,DWORD PTR [edx]
00715932  6a04                              push   0x4
00715934  8d8db0f9ffff                      lea    ecx,[ebp-0x650]
0071593a  51                                push   ecx
0071593b  8d8db8f9ffff                      lea    ecx,[ebp-0x648]
00715941  ffd0                              call   eax
00715943  8b8dc0f9ffff                      mov    ecx,DWORD PTR [ebp-0x640]
00715949  3bcb                              cmp    ecx,ebx
0071594b  7538                              jne    0x715985
0071594d  684c44c400                        push   0xc4444c
00715952  e866d71700                        call   0x8930bd
00715957  83c404                            add    esp,0x4
0071595a  eb4d                              jmp    0x7159a9
0071595c  899dc0f9ffff                      mov    DWORD PTR [ebp-0x640],ebx
00715962  39bde4fbffff                      cmp    DWORD PTR [ebp-0x41c],edi
00715968  0f8299feffff                      jb     0x715807
0071596e  8b95d0fbffff                      mov    edx,DWORD PTR [ebp-0x430]
00715974  52                                push   edx
00715975  e892b81700                        call   0x89120c
0071597a  83c404                            add    esp,0x4
0071597d  83c8ff                            or     eax,0xffffffff
00715980  e957010000                        jmp    0x715adc
00715985  8b11                              mov    edx,DWORD PTR [ecx]
00715987  8b85b0f9ffff                      mov    eax,DWORD PTR [ebp-0x650]
0071598d  8b5234                            mov    edx,DWORD PTR [edx+0x34]
00715990  53                                push   ebx
00715991  50                                push   eax
00715992  ffd2                              call   edx
00715994  85c0                              test   eax,eax
00715996  7911                              jns    0x7159a9
00715998  8b8dc0f9ffff                      mov    ecx,DWORD PTR [ebp-0x640]
0071599e  3bcb                              cmp    ecx,ebx
007159a0  7407                              je     0x7159a9
007159a2  8b01                              mov    eax,DWORD PTR [ecx]
007159a4  8b501c                            mov    edx,DWORD PTR [eax+0x1c]
007159a7  ffd2                              call   edx
007159a9  0fb6bdacf9ffff                    movzx  edi,BYTE PTR [ebp-0x654]
007159b0  8db5b8f9ffff                      lea    esi,[ebp-0x648]
007159b6  e8a52a0000                        call   0x718460
007159bb  8bcf                              mov    ecx,edi
007159bd  c1e108                            shl    ecx,0x8
007159c0  0bcf                              or     ecx,edi
007159c2  c1e108                            shl    ecx,0x8
007159c5  0bcf                              or     ecx,edi
007159c7  c1e108                            shl    ecx,0x8
007159ca  0bcf                              or     ecx,edi
007159cc  33c1                              xor    eax,ecx
007159ce  3d49505453                        cmp    eax,0x53545049
007159d3  7439                              je     0x715a0e
007159d5  8b8dc0f9ffff                      mov    ecx,DWORD PTR [ebp-0x640]
007159db  3bcb                              cmp    ecx,ebx
007159dd  7407                              je     0x7159e6
007159df  8b11                              mov    edx,DWORD PTR [ecx]
007159e1  8b4204                            mov    eax,DWORD PTR [edx+0x4]
007159e4  ffd0                              call   eax
007159e6  899dc0f9ffff                      mov    DWORD PTR [ebp-0x640],ebx
007159ec  83bde4fbffff10                    cmp    DWORD PTR [ebp-0x41c],0x10
007159f3  720f                              jb     0x715a04
007159f5  8b8dd0fbffff                      mov    ecx,DWORD PTR [ebp-0x430]
007159fb  51                                push   ecx
007159fc  e80bb81700                        call   0x89120c
00715a01  83c404                            add    esp,0x4
00715a04  b8feffffff                        mov    eax,0xfffffffe
00715a09  e9ce000000                        jmp    0x715adc
00715a0e  8b85b8f9ffff                      mov    eax,DWORD PTR [ebp-0x648]
00715a14  6a04                              push   0x4
00715a16  8d95b0f9ffff                      lea    edx,[ebp-0x650]
00715a1c  52                                push   edx
00715a1d  8b10                              mov    edx,DWORD PTR [eax]
00715a1f  8d8db8f9ffff                      lea    ecx,[ebp-0x648]
00715a25  ffd2                              call   edx
00715a27  8bbda8f9ffff                      mov    edi,DWORD PTR [ebp-0x658]
00715a2d  8db5b8f9ffff                      lea    esi,[ebp-0x648]
00715a33  e848faffff                        call   0x715480
00715a38  8b8dc0f9ffff                      mov    ecx,DWORD PTR [ebp-0x640]
00715a3e  85c0                              test   eax,eax
00715a40  7523                              jne    0x715a65
00715a42  3bcb                              cmp    ecx,ebx
00715a44  7407                              je     0x715a4d
00715a46  8b01                              mov    eax,DWORD PTR [ecx]
00715a48  8b5004                            mov    edx,DWORD PTR [eax+0x4]
00715a4b  ffd2                              call   edx
00715a4d  8d8dd0fbffff                      lea    ecx,[ebp-0x430]
00715a53  899dc0f9ffff                      mov    DWORD PTR [ebp-0x640],ebx
00715a59  e8f2d1ceff                        call   0x402c50
00715a5e  b8feffffff                        mov    eax,0xfffffffe
00715a63  eb77                              jmp    0x715adc
00715a65  3bcb                              cmp    ecx,ebx
00715a67  7407                              je     0x715a70
00715a69  8b01                              mov    eax,DWORD PTR [ecx]
00715a6b  8b5004                            mov    edx,DWORD PTR [eax+0x4]
00715a6e  ffd2                              call   edx
00715a70  83bde4fbffff10                    cmp    DWORD PTR [ebp-0x41c],0x10
00715a77  8b95d0fbffff                      mov    edx,DWORD PTR [ebp-0x430]
00715a7d  899dc0f9ffff                      mov    DWORD PTR [ebp-0x640],ebx
00715a83  7306                              jae    0x715a8b
00715a85  8d95d0fbffff                      lea    edx,[ebp-0x430]
00715a8b  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
00715a8e  8b8dacf9ffff                      mov    ecx,DWORD PTR [ebp-0x654]
00715a94  50                                push   eax
00715a95  51                                push   ecx
00715a96  8bf7                              mov    esi,edi
00715a98  8b8e38010000                      mov    ecx,DWORD PTR [esi+0x138]
00715a9e  e82d2e0000                        call   0x7188d0
00715aa3  85c0                              test   eax,eax
00715aa5  7410                              je     0x715ab7
00715aa7  8d8dd0fbffff                      lea    ecx,[ebp-0x430]
00715aad  e89ed1ceff                        call   0x402c50
00715ab2  83c8ff                            or     eax,0xffffffff
00715ab5  eb25                              jmp    0x715adc
00715ab7  8b8638010000                      mov    eax,DWORD PTR [esi+0x138]
00715abd  8b4824                            mov    ecx,DWORD PTR [eax+0x24]
00715ac0  8b11                              mov    edx,DWORD PTR [ecx]
00715ac2  8b02                              mov    eax,DWORD PTR [edx]
00715ac4  53                                push   ebx
00715ac5  ffd0                              call   eax
00715ac7  53                                push   ebx
00715ac8  8bce                              mov    ecx,esi
00715aca  e8d1000000                        call   0x715ba0
00715acf  8d8dd0fbffff                      lea    ecx,[ebp-0x430]
00715ad5  e876d1ceff                        call   0x402c50
00715ada  33c0                              xor    eax,eax
00715adc  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
00715adf  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00715ae6  59                                pop    ecx
00715ae7  5f                                pop    edi
00715ae8  5e                                pop    esi
00715ae9  5b                                pop    ebx
00715aea  8b4dec                            mov    ecx,DWORD PTR [ebp-0x14]
00715aed  33cd                              xor    ecx,ebp
00715aef  e80db51700                        call   0x891001
00715af4  8be5                              mov    esp,ebp
00715af6  5d                                pop    ebp
00715af7  c20400                            ret    0x4

; MOUNT_LOOKUP REVERIFIED_EXISTING: parent provider before child recursion
; VA 00714c50..00714d4d raw 00314050 sha256 c621db144fef019d5bfb764eb36877a1cd07799729a622cfe743327da49654a0
00714c50  55                                push   ebp
00714c51  8bec                              mov    ebp,esp
00714c53  81ec08010000                      sub    esp,0x108
00714c59  a1201fd600                        mov    eax,ds:0xd61f20
00714c5e  33c5                              xor    eax,ebp
00714c60  8945fc                            mov    DWORD PTR [ebp-0x4],eax
00714c63  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
00714c66  53                                push   ebx
00714c67  57                                push   edi
00714c68  50                                push   eax
00714c69  8d85f8feffff                      lea    eax,[ebp-0x108]
00714c6f  6804010000                        push   0x104
00714c74  50                                push   eax
00714c75  8bd9                              mov    ebx,ecx
00714c77  e8ddee1700                        call   0x893b59
00714c7c  8d8df8feffff                      lea    ecx,[ebp-0x108]
00714c82  51                                push   ecx
00714c83  e848240000                        call   0x7170d0
00714c88  8bf8                              mov    edi,eax
00714c8a  83c410                            add    esp,0x10
00714c8d  85ff                              test   edi,edi
00714c8f  7512                              jne    0x714ca3
00714c91  5f                                pop    edi
00714c92  5b                                pop    ebx
00714c93  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
00714c96  33cd                              xor    ecx,ebp
00714c98  e864c31700                        call   0x891001
00714c9d  8be5                              mov    esp,ebp
00714c9f  5d                                pop    ebp
00714ca0  c20800                            ret    0x8
00714ca3  c60700                            mov    BYTE PTR [edi],0x0
00714ca6  47                                inc    edi
00714ca7  8bd7                              mov    edx,edi
00714ca9  8d85f8feffff                      lea    eax,[ebp-0x108]
00714caf  2bd0                              sub    edx,eax
00714cb1  83fa01                            cmp    edx,0x1
00714cb4  7521                              jne    0x714cd7
00714cb6  52                                push   edx
00714cb7  8d8df9feffff                      lea    ecx,[ebp-0x107]
00714cbd  51                                push   ecx
00714cbe  8bcb                              mov    ecx,ebx
00714cc0  e88bffffff                        call   0x714c50
00714cc5  5f                                pop    edi
00714cc6  5b                                pop    ebx
00714cc7  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
00714cca  33cd                              xor    ecx,ebp
00714ccc  e830c31700                        call   0x891001
00714cd1  8be5                              mov    esp,ebp
00714cd3  5d                                pop    ebp
00714cd4  c20800                            ret    0x8
00714cd7  8b8304010000                      mov    eax,DWORD PTR [ebx+0x104]
00714cdd  56                                push   esi
00714cde  8b30                              mov    esi,DWORD PTR [eax]
00714ce0  3bf0                              cmp    esi,eax
00714ce2  7421                              je     0x714d05
00714ce4  8d95f8feffff                      lea    edx,[ebp-0x108]
00714cea  52                                push   edx
00714ceb  8d4608                            lea    eax,[esi+0x8]
00714cee  50                                push   eax
00714cef  e8bdef1700                        call   0x893cb1
00714cf4  83c408                            add    esp,0x8
00714cf7  85c0                              test   eax,eax
00714cf9  741f                              je     0x714d1a
00714cfb  8b36                              mov    esi,DWORD PTR [esi]
00714cfd  3bb304010000                      cmp    esi,DWORD PTR [ebx+0x104]
00714d03  75df                              jne    0x714ce4
00714d05  33c0                              xor    eax,eax
00714d07  5e                                pop    esi
00714d08  5f                                pop    edi
00714d09  5b                                pop    ebx
00714d0a  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
00714d0d  33cd                              xor    ecx,ebp
00714d0f  e8edc21700                        call   0x891001
00714d14  8be5                              mov    esp,ebp
00714d16  5d                                pop    ebp
00714d17  c20800                            ret    0x8
00714d1a  8b8608010000                      mov    eax,DWORD PTR [esi+0x108]
00714d20  85c0                              test   eax,eax
00714d22  740b                              je     0x714d2f
00714d24  8bcf                              mov    ecx,edi
00714d26  e885080000                        call   0x7155b0
00714d2b  85c0                              test   eax,eax
00714d2d  75d8                              jne    0x714d07
00714d2f  6a01                              push   0x1
00714d31  57                                push   edi
00714d32  8d4e08                            lea    ecx,[esi+0x8]
00714d35  e816ffffff                        call   0x714c50
00714d3a  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
00714d3d  5e                                pop    esi
00714d3e  5f                                pop    edi
00714d3f  33cd                              xor    ecx,ebp
00714d41  5b                                pop    ebx
00714d42  e8bac21700                        call   0x891001
00714d47  8be5                              mov    esp,ebp
00714d49  5d                                pop    ebp
00714d4a  c20800                            ret    0x8

; RESOURCE_OPEN REVERIFIED_EXISTING: package-first resource object; ordinary fallback is separate
; VA 00714770..00714880 raw 00313b70 sha256 8f89564267b7dedba9fb666cb5bf8568041c61aad2a31c3a9365101d0759b8c4
00714770  55                                push   ebp
00714771  8bec                              mov    ebp,esp
00714773  6aff                              push   0xffffffff
00714775  686c159200                        push   0x92156c
0071477a  64a100000000                      mov    eax,fs:0x0
00714780  50                                push   eax
00714781  51                                push   ecx
00714782  53                                push   ebx
00714783  57                                push   edi
00714784  a1201fd600                        mov    eax,ds:0xd61f20
00714789  33c5                              xor    eax,ebp
0071478b  50                                push   eax
0071478c  8d45f4                            lea    eax,[ebp-0xc]
0071478f  64a300000000                      mov    fs:0x0,eax
00714795  8b7d0c                            mov    edi,DWORD PTR [ebp+0xc]
00714798  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0071479b  57                                push   edi
0071479c  8bcb                              mov    ecx,ebx
0071479e  e86df1ffff                        call   0x713910
007147a3  83c404                            add    esp,0x4
007147a6  8945f0                            mov    DWORD PTR [ebp-0x10],eax
007147a9  85c0                              test   eax,eax
007147ab  0f85be000000                      jne    0x71486f
007147b1  f605984cfe0001                    test   BYTE PTR ds:0xfe4c98,0x1
007147b8  7523                              jne    0x7147dd
007147ba  830d984cfe0001                    or     DWORD PTR ds:0xfe4c98,0x1
007147c1  8945fc                            mov    DWORD PTR [ebp-0x4],eax
007147c4  e807fbffff                        call   0x7142d0
007147c9  686007bd00                        push   0xbd0760
007147ce  e847db1700                        call   0x89231a
007147d3  83c404                            add    esp,0x4
007147d6  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
007147dd  803d944cfe0000                    cmp    BYTE PTR ds:0xfe4c94,0x0
007147e4  751a                              jne    0x714800
007147e6  8bcf                              mov    ecx,edi
007147e8  8bfb                              mov    edi,ebx
007147ea  e841f8ffff                        call   0x714030
007147ef  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
007147f2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
007147f9  59                                pop    ecx
007147fa  5f                                pop    edi
007147fb  5b                                pop    ebx
007147fc  8be5                              mov    esp,ebp
007147fe  5d                                pop    ebp
007147ff  c3                                ret
00714800  f605984cfe0001                    test   BYTE PTR ds:0xfe4c98,0x1
00714807  7527                              jne    0x714830
00714809  b801000000                        mov    eax,0x1
0071480e  0905984cfe00                      or     DWORD PTR ds:0xfe4c98,eax
00714814  8945fc                            mov    DWORD PTR [ebp-0x4],eax
00714817  e8b4faffff                        call   0x7142d0
0071481c  686007bd00                        push   0xbd0760
00714821  e8f4da1700                        call   0x89231a
00714826  83c404                            add    esp,0x4
00714829  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
00714830  8bcb                              mov    ecx,ebx
00714832  bf7c4cfe00                        mov    edi,0xfe4c7c
00714837  e874fbffff                        call   0x7143b0
0071483c  84c0                              test   al,al
0071483e  7511                              jne    0x714851
00714840  e81bfaffff                        call   0x714260
00714845  50                                push   eax
00714846  8bcb                              mov    ecx,ebx
00714848  e823fcffff                        call   0x714470
0071484d  84c0                              test   al,al
0071484f  741b                              je     0x71486c
00714851  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
00714854  8bfb                              mov    edi,ebx
00714856  e8d5f7ffff                        call   0x714030
0071485b  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0071485e  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00714865  59                                pop    ecx
00714866  5f                                pop    edi
00714867  5b                                pop    ebx
00714868  8be5                              mov    esp,ebp
0071486a  5d                                pop    ebp
0071486b  c3                                ret
0071486c  8b45f0                            mov    eax,DWORD PTR [ebp-0x10]
0071486f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
00714872  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
00714879  59                                pop    ecx
0071487a  5f                                pop    edi
0071487b  5b                                pop    ebx
0071487c  8be5                              mov    esp,ebp
0071487e  5d                                pop    ebp
0071487f  c3                                ret

; MEMBER_LOOKUP REVERIFIED_EXISTING: member-ID/cache lookup, not a MEF executor
; VA 007155b0..0071561d raw 003149b0 sha256 f543b3d623fd495b05d01e4b08bd6d5306607023dd5f036fc79e9ecc4f97cfb0
007155b0  53                                push   ebx
007155b1  56                                push   esi
007155b2  8bf0                              mov    esi,eax
007155b4  8b06                              mov    eax,DWORD PTR [esi]
007155b6  8b5004                            mov    edx,DWORD PTR [eax+0x4]
007155b9  51                                push   ecx
007155ba  8bce                              mov    ecx,esi
007155bc  ffd2                              call   edx
007155be  8bd8                              mov    ebx,eax
007155c0  85db                              test   ebx,ebx
007155c2  7449                              je     0x71560d
007155c4  8b03                              mov    eax,DWORD PTR [ebx]
007155c6  8b500c                            mov    edx,DWORD PTR [eax+0xc]
007155c9  8bcb                              mov    ecx,ebx
007155cb  ffd2                              call   edx
007155cd  85c0                              test   eax,eax
007155cf  753c                              jne    0x71560d
007155d1  8bb638010000                      mov    esi,DWORD PTR [esi+0x138]
007155d7  8b4e2c                            mov    ecx,DWORD PTR [esi+0x2c]
007155da  85c9                              test   ecx,ecx
007155dc  7412                              je     0x7155f0
007155de  8b9b1c010000                      mov    ebx,DWORD PTR [ebx+0x11c]
007155e4  3b5944                            cmp    ebx,DWORD PTR [ecx+0x44]
007155e7  740e                              je     0x7155f7
007155e9  8b4928                            mov    ecx,DWORD PTR [ecx+0x28]
007155ec  85c9                              test   ecx,ecx
007155ee  75f4                              jne    0x7155e4
007155f0  33db                              xor    ebx,ebx
007155f2  5e                                pop    esi
007155f3  8bc3                              mov    eax,ebx
007155f5  5b                                pop    ebx
007155f6  c3                                ret
007155f7  83790800                          cmp    DWORD PTR [ecx+0x8],0x0
007155fb  8bd9                              mov    ebx,ecx
007155fd  7509                              jne    0x715608
007155ff  57                                push   edi
00715600  8bfe                              mov    edi,esi
00715602  e899300000                        call   0x7186a0
00715607  5f                                pop    edi
00715608  5e                                pop    esi
00715609  8bc3                              mov    eax,ebx
0071560b  5b                                pop    ebx
0071560c  c3                                ret
0071560d  5e                                pop    esi
0071560e  33c0                              xor    eax,eax
00715610  5b                                pop    ebx
00715611  c3                                ret
00715612  cc                                int3
00715613  cc                                int3
00715614  cc                                int3
00715615  cc                                int3
00715616  cc                                int3
00715617  cc                                int3
00715618  cc                                int3
00715619  cc                                int3
0071561a  cc                                int3
0071561b  cc                                int3
0071561c  cc                                int3

; ALIAS_PARTIAL_WRITE NEW_CORRECTION: incoming root loses unchanged low-16-bit provenance at 4BADC2
; VA 004bad73..004badc9 raw 000ba173 sha256 a2c10183fb758d1cc065b5d39ab4ae606c6670d966629acef667cadda7bab390
004bad73  bf7074fb00                        mov    edi,0xfb7470
004bad78  e803c10300                        call   0x4f6e80
004bad7d  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
004bad84  8bd8                              mov    ebx,eax
004bad86  7530                              jne    0x4badb8
004bad88  830d2888fb0001                    or     DWORD PTR ds:0xfb8828,0x1
004bad8f  c78424980000000e000000            mov    DWORD PTR [esp+0x98],0xe
004bad9a  e8b14a0900                        call   0x54f850
004bad9f  6880d5bc00                        push   0xbcd580
004bada4  e871753d00                        call   0x89231a
004bada9  83c404                            add    esp,0x4
004badac  83ceff                            or     esi,0xffffffff
004badaf  89b42498000000                    mov    DWORD PTR [esp+0x98],esi
004badb6  eb03                              jmp    0x4badbb
004badb8  83ceff                            or     esi,0xffffffff
004badbb  f6052888fb0001                    test   BYTE PTR ds:0xfb8828,0x1
004badc2  668b3dea90fb00                    mov    di,WORD PTR ds:0xfb90ea

; ALIAS_NUMERIC_USE NEW_CORRECTION_SUPPORT: movsx edx,di uses the replaced low word; resource filename is EBX
; VA 004bae70..004baea2 raw 000ba270 sha256 91de2f00f19e412cb428bfb5f6210b33660156061321068438240a4b20c077aa
004bae70  0fbfd7                            movsx  edx,di
004bae73  89542414                          mov    DWORD PTR [esp+0x14],edx
004bae77  db442414                          fild   DWORD PTR [esp+0x14]
004bae7b  dec9                              fmulp  st(1),st
004bae7d  e88e3e4400                        call   0x8fed10
004bae82  e8e9fb2100                        call   0x6daa70
004bae87  e8843e4400                        call   0x8fed10
004bae8c  0fb7c0                            movzx  eax,ax
004bae8f  50                                push   eax
004bae90  6a00                              push   0x0
004bae92  53                                push   ebx
004bae93  68c80ffc00                        push   0xfc0fc8
004bae98  b9fc0ffc00                        mov    ecx,0xfc0ffc
004bae9d  e88eec2100                        call   0x6d9b30

; TRIGGER_STORAGE REVERIFIED_EXISTING: XML trigger attribute to owned narrow-string tree
; VA 004f5640..004f58e3 raw 000f4a40 sha256 b42c57f88aa276f0ef0b535375e984de26fa8165de92f1a244aad4eadf80d535
004f5640  55                                push   ebp
004f5641  8bec                              mov    ebp,esp
004f5643  6aff                              push   0xffffffff
004f5645  6881479200                        push   0x924781
004f564a  64a100000000                      mov    eax,fs:0x0
004f5650  50                                push   eax
004f5651  81ecec010000                      sub    esp,0x1ec
004f5657  a1201fd600                        mov    eax,ds:0xd61f20
004f565c  33c5                              xor    eax,ebp
004f565e  8945f0                            mov    DWORD PTR [ebp-0x10],eax
004f5661  53                                push   ebx
004f5662  56                                push   esi
004f5663  57                                push   edi
004f5664  50                                push   eax
004f5665  8d45f4                            lea    eax,[ebp-0xc]
004f5668  64a300000000                      mov    fs:0x0,eax
004f566e  8d8590feffff                      lea    eax,[ebp-0x170]
004f5674  50                                push   eax
004f5675  b9b4d4c000                        mov    ecx,0xc0d4b4
004f567a  e8b1972300                        call   0x72ee30
004f567f  33db                              xor    ebx,ebx
004f5681  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
004f5684  83bdc4feffff10                    cmp    DWORD PTR [ebp-0x13c],0x10
004f568b  8b8db0feffff                      mov    ecx,DWORD PTR [ebp-0x150]
004f5691  7306                              jae    0x4f5699
004f5693  8d8db0feffff                      lea    ecx,[ebp-0x150]
004f5699  53                                push   ebx
004f569a  8db590feffff                      lea    esi,[ebp-0x170]
004f56a0  e86b9a2300                        call   0x72f110
004f56a5  84c0                              test   al,al
004f56a7  0f8436020000                      je     0x4f58e3
004f56ad  68c8d4c000                        push   0xc0d4c8
004f56b2  8bc6                              mov    eax,esi
004f56b4  e8278c2300                        call   0x72e2e0
004f56b9  68d0d4c000                        push   0xc0d4d0
004f56be  e81d8c2300                        call   0x72e2e0
004f56c3  898510feffff                      mov    DWORD PTR [ebp-0x1f0],eax
004f56c9  3bc3                              cmp    eax,ebx
004f56cb  0f8412020000                      je     0x4f58e3
004f56d1  eb06                              jmp    0x4f56d9
004f56d3  8b8510feffff                      mov    eax,DWORD PTR [ebp-0x1f0]
004f56d9  8b10                              mov    edx,DWORD PTR [eax]
004f56db  8bc8                              mov    ecx,eax
004f56dd  8b4214                            mov    eax,DWORD PTR [edx+0x14]
004f56e0  ffd0                              call   eax
004f56e2  3bc3                              cmp    eax,ebx
004f56e4  0f84e2010000                      je     0x4f58cc
004f56ea  8d7044                            lea    esi,[eax+0x44]
004f56ed  68d0d1be00                        push   0xbed1d0
004f56f2  8bfe                              mov    edi,esi
004f56f4  e8a7a92300                        call   0x7300a0
004f56f9  3bc3                              cmp    eax,ebx
004f56fb  7420                              je     0x4f571d
004f56fd  83c030                            add    eax,0x30
004f5700  83781410                          cmp    DWORD PTR [eax+0x14],0x10
004f5704  7202                              jb     0x4f5708
004f5706  8b00                              mov    eax,DWORD PTR [eax]
004f5708  3bc3                              cmp    eax,ebx
004f570a  7411                              je     0x4f571d
004f570c  50                                push   eax
004f570d  e8a2c03900                        call   0x8917b4
004f5712  83c404                            add    esp,0x4
004f5715  898514feffff                      mov    DWORD PTR [ebp-0x1ec],eax
004f571b  eb06                              jmp    0x4f5723
004f571d  899d14feffff                      mov    DWORD PTR [ebp-0x1ec],ebx
004f5723  68d4d4c000                        push   0xc0d4d4
004f5728  8bfe                              mov    edi,esi
004f572a  e871a92300                        call   0x7300a0
004f572f  3bc3                              cmp    eax,ebx
004f5731  740d                              je     0x4f5740
004f5733  83784410                          cmp    DWORD PTR [eax+0x44],0x10
004f5737  8d7830                            lea    edi,[eax+0x30]
004f573a  7206                              jb     0x4f5742
004f573c  8b3f                              mov    edi,DWORD PTR [edi]
004f573e  eb02                              jmp    0x4f5742
004f5740  33ff                              xor    edi,edi
004f5742  8bc7                              mov    eax,edi
004f5744  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
004f574b  895de4                            mov    DWORD PTR [ebp-0x1c],ebx
004f574e  885dd4                            mov    BYTE PTR [ebp-0x2c],bl
004f5751  8d5001                            lea    edx,[eax+0x1]
004f5754  8a08                              mov    cl,BYTE PTR [eax]
004f5756  40                                inc    eax
004f5757  3acb                              cmp    cl,bl
004f5759  75f9                              jne    0x4f5754
004f575b  2bc2                              sub    eax,edx
004f575d  50                                push   eax
004f575e  57                                push   edi
004f575f  8d4dd4                            lea    ecx,[ebp-0x2c]
004f5762  e809d3f0ff                        call   0x402a70
004f5767  68dcd4c000                        push   0xc0d4dc
004f576c  8bfe                              mov    edi,esi
004f576e  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
004f5772  e829a92300                        call   0x7300a0
004f5777  3bc3                              cmp    eax,ebx
004f5779  7410                              je     0x4f578b
004f577b  83784410                          cmp    DWORD PTR [eax+0x44],0x10
004f577f  7205                              jb     0x4f5786
004f5781  8b7830                            mov    edi,DWORD PTR [eax+0x30]
004f5784  eb07                              jmp    0x4f578d
004f5786  8d7830                            lea    edi,[eax+0x30]
004f5789  eb02                              jmp    0x4f578d
004f578b  33ff                              xor    edi,edi
004f578d  8bc7                              mov    eax,edi
004f578f  c745cc0f000000                    mov    DWORD PTR [ebp-0x34],0xf
004f5796  895dc8                            mov    DWORD PTR [ebp-0x38],ebx
004f5799  885db8                            mov    BYTE PTR [ebp-0x48],bl
004f579c  8d5001                            lea    edx,[eax+0x1]
004f579f  90                                nop
004f57a0  8a08                              mov    cl,BYTE PTR [eax]
004f57a2  40                                inc    eax
004f57a3  3acb                              cmp    cl,bl
004f57a5  75f9                              jne    0x4f57a0
004f57a7  2bc2                              sub    eax,edx
004f57a9  50                                push   eax
004f57aa  57                                push   edi
004f57ab  8d4db8                            lea    ecx,[ebp-0x48]
004f57ae  e8bdd2f0ff                        call   0x402a70
004f57b3  68e0d4c000                        push   0xc0d4e0
004f57b8  8bfe                              mov    edi,esi
004f57ba  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
004f57be  e8dda82300                        call   0x7300a0
004f57c3  3bc3                              cmp    eax,ebx
004f57c5  7410                              je     0x4f57d7
004f57c7  83784410                          cmp    DWORD PTR [eax+0x44],0x10
004f57cb  7205                              jb     0x4f57d2
004f57cd  8b7830                            mov    edi,DWORD PTR [eax+0x30]
004f57d0  eb07                              jmp    0x4f57d9
004f57d2  8d7830                            lea    edi,[eax+0x30]
004f57d5  eb02                              jmp    0x4f57d9
004f57d7  33ff                              xor    edi,edi
004f57d9  8bc7                              mov    eax,edi
004f57db  c745b00f000000                    mov    DWORD PTR [ebp-0x50],0xf
004f57e2  895dac                            mov    DWORD PTR [ebp-0x54],ebx
004f57e5  885d9c                            mov    BYTE PTR [ebp-0x64],bl
004f57e8  8d7001                            lea    esi,[eax+0x1]
004f57eb  eb03                              jmp    0x4f57f0
004f57ed  8d4900                            lea    ecx,[ecx+0x0]
004f57f0  8a08                              mov    cl,BYTE PTR [eax]
004f57f2  40                                inc    eax
004f57f3  3acb                              cmp    cl,bl
004f57f5  75f9                              jne    0x4f57f0
004f57f7  2bc6                              sub    eax,esi
004f57f9  50                                push   eax
004f57fa  57                                push   edi
004f57fb  8d4d9c                            lea    ecx,[ebp-0x64]
004f57fe  e86dd2f0ff                        call   0x402a70
004f5803  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
004f5807  8bb514feffff                      mov    esi,DWORD PTR [ebp-0x1ec]
004f580d  8d950cfeffff                      lea    edx,[ebp-0x1f4]
004f5813  b9c074fb00                        mov    ecx,0xfb74c0
004f5818  89b50cfeffff                      mov    DWORD PTR [ebp-0x1f4],esi
004f581e  e8cd250000                        call   0x4f7df0
004f5823  6aff                              push   0xffffffff
004f5825  53                                push   ebx
004f5826  8d4dd4                            lea    ecx,[ebp-0x2c]
004f5829  51                                push   ecx
004f582a  8bc8                              mov    ecx,eax
004f582c  e80fd8f0ff                        call   0x403040
004f5831  8d950cfeffff                      lea    edx,[ebp-0x1f4]
004f5837  b9b074fb00                        mov    ecx,0xfb74b0
004f583c  89b50cfeffff                      mov    DWORD PTR [ebp-0x1f4],esi
004f5842  e8a9250000                        call   0x4f7df0
004f5847  6aff                              push   0xffffffff
004f5849  53                                push   ebx
004f584a  8d55b8                            lea    edx,[ebp-0x48]
004f584d  52                                push   edx
004f584e  8bc8                              mov    ecx,eax
004f5850  e8ebd7f0ff                        call   0x403040
004f5855  8d950cfeffff                      lea    edx,[ebp-0x1f4]
004f585b  b9d074fb00                        mov    ecx,0xfb74d0
004f5860  89b50cfeffff                      mov    DWORD PTR [ebp-0x1f4],esi
004f5866  e885250000                        call   0x4f7df0
004f586b  6aff                              push   0xffffffff
004f586d  53                                push   ebx
004f586e  8d4d9c                            lea    ecx,[ebp-0x64]
004f5871  51                                push   ecx
004f5872  8bc8                              mov    ecx,eax
004f5874  e8c7d7f0ff                        call   0x403040
004f5879  837db010                          cmp    DWORD PTR [ebp-0x50],0x10
004f587d  720c                              jb     0x4f588b
004f587f  8b559c                            mov    edx,DWORD PTR [ebp-0x64]
004f5882  52                                push   edx
004f5883  e884b93900                        call   0x89120c
004f5888  83c404                            add    esp,0x4
004f588b  bf10000000                        mov    edi,0x10
004f5890  be0f000000                        mov    esi,0xf
004f5895  8975b0                            mov    DWORD PTR [ebp-0x50],esi
004f5898  895dac                            mov    DWORD PTR [ebp-0x54],ebx
004f589b  885d9c                            mov    BYTE PTR [ebp-0x64],bl
004f589e  397dcc                            cmp    DWORD PTR [ebp-0x34],edi
004f58a1  720c                              jb     0x4f58af
004f58a3  8b45b8                            mov    eax,DWORD PTR [ebp-0x48]
004f58a6  50                                push   eax
004f58a7  e860b93900                        call   0x89120c
004f58ac  83c404                            add    esp,0x4
004f58af  885dfc                            mov    BYTE PTR [ebp-0x4],bl
004f58b2  8975cc                            mov    DWORD PTR [ebp-0x34],esi
004f58b5  895dc8                            mov    DWORD PTR [ebp-0x38],ebx
004f58b8  885db8                            mov    BYTE PTR [ebp-0x48],bl
004f58bb  397de8                            cmp    DWORD PTR [ebp-0x18],edi
004f58be  720c                              jb     0x4f58cc
004f58c0  8b4dd4                            mov    ecx,DWORD PTR [ebp-0x2c]
004f58c3  51                                push   ecx
004f58c4  e843b93900                        call   0x89120c
004f58c9  83c404                            add    esp,0x4
004f58cc  8b9510feffff                      mov    edx,DWORD PTR [ebp-0x1f0]
004f58d2  8b4240                            mov    eax,DWORD PTR [edx+0x40]
004f58d5  898510feffff                      mov    DWORD PTR [ebp-0x1f0],eax
004f58db  3bc3                              cmp    eax,ebx
004f58dd  0f85f0fdffff                      jne    0x4f56d3

; LUA_DISPATCH REVERIFIED_EXISTING: first byte routes Lua text/binary parsers
; VA 006fe860..006fe983 raw 002fdc60 sha256 755c9c11fabbd490a8e298f5b2e5c1f67f6facc7dbbffdfb0147c8138d687d4d
006fe860  55                                push   ebp
006fe861  8bec                              mov    ebp,esp
006fe863  83e4f8                            and    esp,0xfffffff8
006fe866  83ec0c                            sub    esp,0xc
006fe869  53                                push   ebx
006fe86a  56                                push   esi
006fe86b  57                                push   edi
006fe86c  8b7d0c                            mov    edi,DWORD PTR [ebp+0xc]
006fe86f  8b37                              mov    esi,DWORD PTR [edi]
006fe871  e8ba050000                        call   0x6fee30
006fe876  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
006fe879  8bd8                              mov    ebx,eax
006fe87b  8b4610                            mov    eax,DWORD PTR [esi+0x10]
006fe87e  8b4844                            mov    ecx,DWORD PTR [eax+0x44]
006fe881  3b4840                            cmp    ecx,DWORD PTR [eax+0x40]
006fe884  7207                              jb     0x6fe88d
006fe886  8bc6                              mov    eax,esi
006fe888  e813cbffff                        call   0x6fb3a0
006fe88d  b880d67000                        mov    eax,0x70d680
006fe892  83fb1b                            cmp    ebx,0x1b
006fe895  7405                              je     0x6fe89c
006fe897  b820e47000                        mov    eax,0x70e420
006fe89c  8b5710                            mov    edx,DWORD PTR [edi+0x10]
006fe89f  52                                push   edx
006fe8a0  8b17                              mov    edx,DWORD PTR [edi]
006fe8a2  8d4f04                            lea    ecx,[edi+0x4]
006fe8a5  51                                push   ecx
006fe8a6  52                                push   edx
006fe8a7  56                                push   esi
006fe8a8  ffd0                              call   eax
006fe8aa  8bf8                              mov    edi,eax
006fe8ac  8b4648                            mov    eax,DWORD PTR [esi+0x48]
006fe8af  0fb64f48                          movzx  ecx,BYTE PTR [edi+0x48]
006fe8b3  50                                push   eax
006fe8b4  51                                push   ecx
006fe8b5  8bc6                              mov    eax,esi
006fe8b7  897c2428                          mov    DWORD PTR [esp+0x28],edi
006fe8bb  e870eeffff                        call   0x6fd730
006fe8c0  33db                              xor    ebx,ebx
006fe8c2  83c418                            add    esp,0x18
006fe8c5  897810                            mov    DWORD PTR [eax+0x10],edi
006fe8c8  89442414                          mov    DWORD PTR [esp+0x14],eax
006fe8cc  385f48                            cmp    BYTE PTR [edi+0x48],bl
006fe8cf  7667                              jbe    0x6fe938
006fe8d1  83c014                            add    eax,0x14
006fe8d4  8944240c                          mov    DWORD PTR [esp+0xc],eax
006fe8d8  8b7e10                            mov    edi,DWORD PTR [esi+0x10]
006fe8db  8b5710                            mov    edx,DWORD PTR [edi+0x10]
006fe8de  8b470c                            mov    eax,DWORD PTR [edi+0xc]
006fe8e1  6a20                              push   0x20
006fe8e3  6a00                              push   0x0
006fe8e5  6a00                              push   0x0
006fe8e7  52                                push   edx
006fe8e8  ffd0                              call   eax
006fe8ea  83c410                            add    esp,0x10
006fe8ed  85c0                              test   eax,eax
006fe8ef  7478                              je     0x6fe969
006fe8f1  83474420                          add    DWORD PTR [edi+0x44],0x20
006fe8f5  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
006fe8f8  8b511c                            mov    edx,DWORD PTR [ecx+0x1c]
006fe8fb  8910                              mov    DWORD PTR [eax],edx
006fe8fd  8b542410                          mov    edx,DWORD PTR [esp+0x10]
006fe901  89411c                            mov    DWORD PTR [ecx+0x1c],eax
006fe904  8a4914                            mov    cl,BYTE PTR [ecx+0x14]
006fe907  80e103                            and    cl,0x3
006fe90a  884805                            mov    BYTE PTR [eax+0x5],cl
006fe90d  8d4810                            lea    ecx,[eax+0x10]
006fe910  894808                            mov    DWORD PTR [eax+0x8],ecx
006fe913  c640040a                          mov    BYTE PTR [eax+0x4],0xa
006fe917  c7410800000000                    mov    DWORD PTR [ecx+0x8],0x0
006fe91e  8b4c240c                          mov    ecx,DWORD PTR [esp+0xc]
006fe922  8901                              mov    DWORD PTR [ecx],eax
006fe924  0fb64248                          movzx  eax,BYTE PTR [edx+0x48]
006fe928  43                                inc    ebx
006fe929  83c104                            add    ecx,0x4
006fe92c  894c240c                          mov    DWORD PTR [esp+0xc],ecx
006fe930  3bd8                              cmp    ebx,eax
006fe932  7ca4                              jl     0x6fe8d8
006fe934  8b442414                          mov    eax,DWORD PTR [esp+0x14]
006fe938  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
006fe93b  8901                              mov    DWORD PTR [ecx],eax
006fe93d  c7410806000000                    mov    DWORD PTR [ecx+0x8],0x6
006fe944  8b4e1c                            mov    ecx,DWORD PTR [esi+0x1c]
006fe947  2b4e08                            sub    ecx,DWORD PTR [esi+0x8]
006fe94a  83f910                            cmp    ecx,0x10
006fe94d  7f28                              jg     0x6fe977
006fe94f  8b462c                            mov    eax,DWORD PTR [esi+0x2c]
006fe952  83f801                            cmp    eax,0x1
006fe955  7c1a                              jl     0x6fe971
006fe957  03c0                              add    eax,eax
006fe959  e852f3ffff                        call   0x6fdcb0
006fe95e  83460810                          add    DWORD PTR [esi+0x8],0x10
006fe962  5f                                pop    edi
006fe963  5e                                pop    esi
006fe964  5b                                pop    ebx
006fe965  8be5                              mov    esp,ebp
006fe967  5d                                pop    ebp
006fe968  c3                                ret
006fe969  6a04                              push   0x4
006fe96b  56                                push   esi
006fe96c  e8cff1ffff                        call   0x6fdb40
006fe971  40                                inc    eax
006fe972  e839f3ffff                        call   0x6fdcb0
006fe977  83460810                          add    DWORD PTR [esi+0x8],0x10
006fe97b  5f                                pop    edi
006fe97c  5e                                pop    esi
006fe97d  5b                                pop    ebx
006fe97e  8be5                              mov    esp,ebp
006fe980  5d                                pop    ebp
006fe981  c3                                ret
006fe982  cc                                int3

; LUA_HEADER REVERIFIED_EXISTING: 12-byte Lua 5.1 header generation, not an official MEF header
; VA 0070d5f0..0070d670 raw 0030c9f0 sha256 2b0ec39c5efe8c347d059731cb0eb4a6e68b5077c354cedd86276427b0b8ae10
0070d5f0  55                                push   ebp
0070d5f1  8bec                              mov    ebp,esp
0070d5f3  83ec1c                            sub    esp,0x1c
0070d5f6  a1201fd600                        mov    eax,ds:0xd61f20
0070d5fb  33c5                              xor    eax,ebp
0070d5fd  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0070d600  56                                push   esi
0070d601  8b7704                            mov    esi,DWORD PTR [edi+0x4]
0070d604  8d45e4                            lea    eax,[ebp-0x1c]
0070d607  6a0c                              push   0xc
0070d609  50                                push   eax
0070d60a  c745f01b4c7561                    mov    DWORD PTR [ebp-0x10],0x61754c1b
0070d611  c745f451000104                    mov    DWORD PTR [ebp-0xc],0x4010051
0070d618  c745f804040800                    mov    DWORD PTR [ebp-0x8],0x80404
0070d61f  e86c18ffff                        call   0x6fee90
0070d624  83c408                            add    esp,0x8
0070d627  85c0                              test   eax,eax
0070d629  740c                              je     0x70d637
0070d62b  b83c3ec400                        mov    eax,0xc43e3c
0070d630  8bf7                              mov    esi,edi
0070d632  e8d9f5ffff                        call   0x70cc10
0070d637  b80c000000                        mov    eax,0xc
0070d63c  33c9                              xor    ecx,ecx
0070d63e  8bff                              mov    edi,edi
0070d640  8b540df0                          mov    edx,DWORD PTR [ebp+ecx*1-0x10]
0070d644  3b540de4                          cmp    edx,DWORD PTR [ebp+ecx*1-0x1c]
0070d648  751a                              jne    0x70d664
0070d64a  83e804                            sub    eax,0x4
0070d64d  83c104                            add    ecx,0x4
0070d650  83f804                            cmp    eax,0x4
0070d653  73eb                              jae    0x70d640
0070d655  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0070d658  33cd                              xor    ecx,ebp
0070d65a  5e                                pop    esi
0070d65b  e8a1391800                        call   0x891001
0070d660  8be5                              mov    esp,ebp
0070d662  5d                                pop    ebp
0070d663  c3                                ret
0070d664  b8743ec400                        mov    eax,0xc43e74
0070d669  8bf7                              mov    esi,edi
0070d66b  e8a0f5ffff                        call   0x70cc10
