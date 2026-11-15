
### R01 重驗：T tick numeric result and T+34
VA 0x4a8b90 RAW 0xa7f90 END 0x4a8c1b SHA256 95c2feeed86b698b3804f837a80e8735b79346041df8bb3ef796f64d20db79de
0x4a8b90  55                                push   ebp
0x4a8b91  8bec                              mov    ebp,esp
0x4a8b93  83ec18                            sub    esp,0x18
0x4a8b96  53                                push   ebx
0x4a8b97  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x4a8b9a  8b03                              mov    eax,DWORD PTR [ebx]
0x4a8b9c  56                                push   esi
0x4a8b9d  57                                push   edi
0x4a8b9e  68d468c000                        push   0xc068d4
0x4a8ba3  6a01                              push   0x1
0x4a8ba5  50                                push   eax
0x4a8ba6  e8f5440000                        call   0x4ad0a0
0x4a8bab  8b0b                              mov    ecx,DWORD PTR [ebx]
0x4a8bad  8b09                              mov    ecx,DWORD PTR [ecx]
0x4a8baf  83c8ff                            or     eax,0xffffffff
0x4a8bb2  e839c52400                        call   0x6f50f0
0x4a8bb7  8b4808                            mov    ecx,DWORD PTR [eax+0x8]
0x4a8bba  83f903                            cmp    ecx,0x3
0x4a8bbd  7426                              je     0x4a8be5
0x4a8bbf  83f904                            cmp    ecx,0x4
0x4a8bc2  7542                              jne    0x4a8c06
0x4a8bc4  8b30                              mov    esi,DWORD PTR [eax]
0x4a8bc6  83c610                            add    esi,0x10
0x4a8bc9  8d7df4                            lea    edi,[ebp-0xc]
0x4a8bcc  e88feb2400                        call   0x6f7760
0x4a8bd1  85c0                              test   eax,eax
0x4a8bd3  7431                              je     0x4a8c06
0x4a8bd5  dd45f4                            fld    QWORD PTR [ebp-0xc]
0x4a8bd8  c745f403000000                    mov    DWORD PTR [ebp-0xc],0x3
0x4a8bdf  dd5dec                            fstp   QWORD PTR [ebp-0x14]
0x4a8be2  8d45ec                            lea    eax,[ebp-0x14]
0x4a8be5  dd00                              fld    QWORD PTR [eax]
0x4a8be7  dd5df4                            fstp   QWORD PTR [ebp-0xc]
0x4a8bea  dd45f4                            fld    QWORD PTR [ebp-0xc]
0x4a8bed  db5d08                            fistp  DWORD PTR [ebp+0x8]
0x4a8bf0  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4a8bf3  33d2                              xor    edx,edx
0x4a8bf5  85c0                              test   eax,eax
0x4a8bf7  0f95c2                            setne  dl
0x4a8bfa  895334                            mov    DWORD PTR [ebx+0x34],edx
0x4a8bfd  5f                                pop    edi
0x4a8bfe  5e                                pop    esi
0x4a8bff  5b                                pop    ebx
0x4a8c00  8be5                              mov    esp,ebp
0x4a8c02  5d                                pop    ebp
0x4a8c03  c20400                            ret    0x4
0x4a8c06  33d2                              xor    edx,edx
0x4a8c08  33c0                              xor    eax,eax
0x4a8c0a  85c0                              test   eax,eax
0x4a8c0c  0f95c2                            setne  dl
0x4a8c0f  5f                                pop    edi
0x4a8c10  5e                                pop    esi
0x4a8c11  895334                            mov    DWORD PTR [ebx+0x34],edx
0x4a8c14  5b                                pop    ebx
0x4a8c15  8be5                              mov    esp,ebp
0x4a8c17  5d                                pop    ebp
0x4a8c18  c20400                            ret    0x4

### R02 重驗：W stored into T; TutorialBase load
VA 0x4a88e0 RAW 0xa7ce0 END 0x4a89bf SHA256 c02c1bb33b21151db1ec5bbeffe4086005d24a77413a8d395d70428a8a528ff0
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

### R03 006E payload gate and CTutorial factory/install
VA 0x4b9260 RAW 0xb8660 END 0x4b931f SHA256 ecd34aed356f4fed01503737f971b4e020c39f4facf1a5a723c6c95bb5200ebf
0x4b9260  55                                push   ebp
0x4b9261  8bec                              mov    ebp,esp
0x4b9263  83e4f8                            and    esp,0xfffffff8
0x4b9266  6aff                              push   0xffffffff
0x4b9268  683e719400                        push   0x94713e
0x4b926d  64a100000000                      mov    eax,fs:0x0
0x4b9273  50                                push   eax
0x4b9274  83ec08                            sub    esp,0x8
0x4b9277  53                                push   ebx
0x4b9278  56                                push   esi
0x4b9279  57                                push   edi
0x4b927a  a1201fd600                        mov    eax,ds:0xd61f20
0x4b927f  33c4                              xor    eax,esp
0x4b9281  50                                push   eax
0x4b9282  8d442418                          lea    eax,[esp+0x18]
0x4b9286  64a300000000                      mov    fs:0x0,eax
0x4b928c  8bd9                              mov    ebx,ecx
0x4b928e  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x4b9291  0fbe4802                          movsx  ecx,BYTE PTR [eax+0x2]
0x4b9295  8bc1                              mov    eax,ecx
0x4b9297  48                                dec    eax
0x4b9298  740b                              je     0x4b92a5
0x4b929a  51                                push   ecx
0x4b929b  68286ec000                        push   0xc06e28
0x4b92a0  e8cb492300                        call   0x6edc70
0x4b92a5  6854bd0000                        push   0xbd54
0x4b92aa  e8b97f3d00                        call   0x891268
0x4b92af  83c404                            add    esp,0x4
0x4b92b2  85c0                              test   eax,eax
0x4b92b4  7409                              je     0x4b92bf
0x4b92b6  8bf0                              mov    esi,eax
0x4b92b8  e803b80000                        call   0x4c4ac0
0x4b92bd  eb02                              jmp    0x4b92c1
0x4b92bf  33c0                              xor    eax,eax
0x4b92c1  8bf8                              mov    edi,eax
0x4b92c3  8bf3                              mov    esi,ebx
0x4b92c5  e886eaffff                        call   0x4b7d50
0x4b92ca  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
0x4b92d1  7521                              jne    0x4b92f4
0x4b92d3  830d9043f90001                    or     DWORD PTR ds:0xf94390,0x1
0x4b92da  c744242000000000                  mov    DWORD PTR [esp+0x20],0x0
0x4b92e2  e8a9820200                        call   0x4e1590
0x4b92e7  6880ccbc00                        push   0xbccc80
0x4b92ec  e829903d00                        call   0x89231a
0x4b92f1  83c404                            add    esp,0x4
0x4b92f4  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x4b92f7  0fbe4102                          movsx  eax,BYTE PTR [ecx+0x2]
0x4b92fb  39052c39f900                      cmp    DWORD PTR ds:0xf9392c,eax
0x4b9301  7405                              je     0x4b9308
0x4b9303  a32c39f900                        mov    ds:0xf9392c,eax
0x4b9308  33c0                              xor    eax,eax
0x4b930a  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x4b930e  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4b9315  59                                pop    ecx
0x4b9316  5f                                pop    edi
0x4b9317  5e                                pop    esi
0x4b9318  5b                                pop    ebx
0x4b9319  8be5                              mov    esp,ebp
0x4b931b  5d                                pop    ebp
0x4b931c  c20c00                            ret    0xc

### R04 重驗：old field exit/delete, new field install/init
VA 0x4b7d50 RAW 0xb7150 END 0x4b7dc0 SHA256 aec02e527925bbab0eb169d2dc72839399cc7c3c9c8b55a43a0945395f8b4525
0x4b7d50  51                                push   ecx
0x4b7d51  85ff                              test   edi,edi
0x4b7d53  750a                              jne    0x4b7d5f
0x4b7d55  68cc6dc000                        push   0xc06dcc
0x4b7d5a  e8115f2300                        call   0x6edc70
0x4b7d5f  8b8eac5e0000                      mov    ecx,DWORD PTR [esi+0x5eac]
0x4b7d65  85c9                              test   ecx,ecx
0x4b7d67  7423                              je     0x4b7d8c
0x4b7d69  8b01                              mov    eax,DWORD PTR [ecx]
0x4b7d6b  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x4b7d6e  ffd2                              call   edx
0x4b7d70  8b8eac5e0000                      mov    ecx,DWORD PTR [esi+0x5eac]
0x4b7d76  85c9                              test   ecx,ecx
0x4b7d78  7412                              je     0x4b7d8c
0x4b7d7a  8b01                              mov    eax,DWORD PTR [ecx]
0x4b7d7c  8b10                              mov    edx,DWORD PTR [eax]
0x4b7d7e  6a01                              push   0x1
0x4b7d80  ffd2                              call   edx
0x4b7d82  c786ac5e000000000000              mov    DWORD PTR [esi+0x5eac],0x0
0x4b7d8c  a174a6d600                        mov    eax,ds:0xd6a674
0x4b7d91  50                                push   eax
0x4b7d92  8bc8                              mov    ecx,eax
0x4b7d94  8bd0                              mov    edx,eax
0x4b7d96  c1e908                            shr    ecx,0x8
0x4b7d99  51                                push   ecx
0x4b7d9a  c1ea10                            shr    edx,0x10
0x4b7d9d  52                                push   edx
0x4b7d9e  c1e818                            shr    eax,0x18
0x4b7da1  50                                push   eax
0x4b7da2  68e06dc000                        push   0xc06de0
0x4b7da7  89beac5e0000                      mov    DWORD PTR [esi+0x5eac],edi
0x4b7dad  e84e5f2300                        call   0x6edd00
0x4b7db2  8b07                              mov    eax,DWORD PTR [edi]
0x4b7db4  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x4b7db7  83c414                            add    esp,0x14
0x4b7dba  8bcf                              mov    ecx,edi
0x4b7dbc  ffd2                              call   edx
0x4b7dbe  59                                pop    ecx
0x4b7dbf  c3                                ret

### R05 CTutorial vptr constructor
VA 0x4c4ac0 RAW 0xc3ec0 END 0x4c4b04 SHA256 e1a0928c0da336ceabf02254b2e983b676a8c62e96d459a5b61624df9ea62935
0x4c4ac0  8bc6                              mov    eax,esi
0x4c4ac2  e88992feff                        call   0x4add50
0x4c4ac7  68a85e0000                        push   0x5ea8
0x4c4acc  8d86ac5e0000                      lea    eax,[esi+0x5eac]
0x4c4ad2  6a00                              push   0x0
0x4c4ad4  50                                push   eax
0x4c4ad5  c706e873c000                      mov    DWORD PTR [esi],0xc073e8
0x4c4adb  c70574a6d6004f545554              mov    DWORD PTR ds:0xd6a674,0x5455544f
0x4c4ae5  e8769d3d00                        call   0x89e860
0x4c4aea  83c40c                            add    esp,0xc
0x4c4aed  c7860c610000204f4c00              mov    DWORD PTR [esi+0x610c],0x4c4f20
0x4c4af7  c786106100007523bf00              mov    DWORD PTR [esi+0x6110],0xbf2375
0x4c4b01  8bc6                              mov    eax,esi
0x4c4b03  c3                                ret

### R06 重驗：Tutorial init, controller kind4 and T entry
VA 0x4c4b10 RAW 0xc3f10 END 0x4c4d59 SHA256 16bef376cffec0067d24a5e66b3173d882520941f7bb73d9b26e7ed55a738bba
0x4c4b10  55                                push   ebp
0x4c4b11  8bec                              mov    ebp,esp
0x4c4b13  83e4f8                            and    esp,0xfffffff8
0x4c4b16  6aff                              push   0xffffffff
0x4c4b18  6851a59300                        push   0x93a551
0x4c4b1d  64a100000000                      mov    eax,fs:0x0
0x4c4b23  50                                push   eax
0x4c4b24  83ec08                            sub    esp,0x8
0x4c4b27  53                                push   ebx
0x4c4b28  56                                push   esi
0x4c4b29  57                                push   edi
0x4c4b2a  a1201fd600                        mov    eax,ds:0xd61f20
0x4c4b2f  33c4                              xor    eax,esp
0x4c4b31  50                                push   eax
0x4c4b32  8d442418                          lea    eax,[esp+0x18]
0x4c4b36  64a300000000                      mov    fs:0x0,eax
0x4c4b3c  f605f02cfd0001                    test   BYTE PTR ds:0xfd2cf0,0x1
0x4c4b43  bf01000000                        mov    edi,0x1
0x4c4b48  7518                              jne    0x4c4b62
0x4c4b4a  093df02cfd00                      or     DWORD PTR ds:0xfd2cf0,edi
0x4c4b50  e83b352700                        call   0x738090
0x4c4b55  6880e6bc00                        push   0xbce680
0x4c4b5a  e8bbd73c00                        call   0x89231a
0x4c4b5f  83c404                            add    esp,0x4
0x4c4b62  33f6                              xor    esi,esi
0x4c4b64  3935b82bfd00                      cmp    DWORD PTR ds:0xfd2bb8,esi
0x4c4b6a  7439                              je     0x4c4ba5
0x4c4b6c  8b0dd02cfd00                      mov    ecx,DWORD PTR ds:0xfd2cd0
0x4c4b72  893dc42bfd00                      mov    DWORD PTR ds:0xfd2bc4,edi
0x4c4b78  c705c82bfd00c8000000              mov    DWORD PTR ds:0xfd2bc8,0xc8
0x4c4b82  3bce                              cmp    ecx,esi
0x4c4b84  740d                              je     0x4c4b93
0x4c4b86  8b01                              mov    eax,DWORD PTR [ecx]
0x4c4b88  8b5008                            mov    edx,DWORD PTR [eax+0x8]
0x4c4b8b  ffd2                              call   edx
0x4c4b8d  8935d02cfd00                      mov    DWORD PTR ds:0xfd2cd0,esi
0x4c4b93  8935d42cfd00                      mov    DWORD PTR ds:0xfd2cd4,esi
0x4c4b99  893dcc2bfd00                      mov    DWORD PTR ds:0xfd2bcc,edi
0x4c4b9f  893de82cfd00                      mov    DWORD PTR ds:0xfd2ce8,edi
0x4c4ba5  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x4c4bab  8b01                              mov    eax,DWORD PTR [ecx]
0x4c4bad  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x4c4bb0  ffd2                              call   edx
0x4c4bb2  83cbff                            or     ebx,0xffffffff
0x4c4bb5  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x4c4bbc  7520                              jne    0x4c4bde
0x4c4bbe  093d2cb2fa00                      or     DWORD PTR ds:0xfab22c,edi
0x4c4bc4  89742420                          mov    DWORD PTR [esp+0x20],esi
0x4c4bc8  e8c3a00100                        call   0x4dec90
0x4c4bcd  6830cebc00                        push   0xbcce30
0x4c4bd2  e843d73c00                        call   0x89231a
0x4c4bd7  83c404                            add    esp,0x4
0x4c4bda  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x4c4bde  6830b1fa00                        push   0xfab130
0x4c4be3  e8a8b20100                        call   0x4dfe90
0x4c4be8  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x4c4bef  7520                              jne    0x4c4c11
0x4c4bf1  093d2cb2fa00                      or     DWORD PTR ds:0xfab22c,edi
0x4c4bf7  897c2420                          mov    DWORD PTR [esp+0x20],edi
0x4c4bfb  e890a00100                        call   0x4dec90
0x4c4c00  6830cebc00                        push   0xbcce30
0x4c4c05  e810d73c00                        call   0x89231a
0x4c4c0a  83c404                            add    esp,0x4
0x4c4c0d  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x4c4c11  6848b1fa00                        push   0xfab148
0x4c4c16  893528b2fa00                      mov    DWORD PTR ds:0xfab228,esi
0x4c4c1c  e84fc40100                        call   0x4e1070
0x4c4c21  83c404                            add    esp,0x4
0x4c4c24  f605c818fe0001                    test   BYTE PTR ds:0xfe18c8,0x1
0x4c4c2b  7524                              jne    0x4c4c51
0x4c4c2d  093dc818fe00                      or     DWORD PTR ds:0xfe18c8,edi
0x4c4c33  c744242002000000                  mov    DWORD PTR [esp+0x20],0x2
0x4c4c3b  e830ad0700                        call   0x53f970
0x4c4c40  6810e8bc00                        push   0xbce810
0x4c4c45  e8d0d63c00                        call   0x89231a
0x4c4c4a  83c404                            add    esp,0x4
0x4c4c4d  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x4c4c51  a1cc18fe00                        mov    eax,ds:0xfe18cc
0x4c4c56  3b05d018fe00                      cmp    eax,DWORD PTR ds:0xfe18d0
0x4c4c5c  7405                              je     0x4c4c63
0x4c4c5e  a3d018fe00                        mov    ds:0xfe18d0,eax
0x4c4c63  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x4c4c6a  7524                              jne    0x4c4c90
0x4c4c6c  093d800ffc00                      or     DWORD PTR ds:0xfc0f80,edi
0x4c4c72  c744242003000000                  mov    DWORD PTR [esp+0x20],0x3
0x4c4c7a  e83162fbff                        call   0x47aeb0
0x4c4c7f  6870dbbc00                        push   0xbcdb70
0x4c4c84  e891d63c00                        call   0x89231a
0x4c4c89  83c404                            add    esp,0x4
0x4c4c8c  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x4c4c90  b9840ffc00                        mov    ecx,0xfc0f84
0x4c4c95  e8863ffeff                        call   0x4a8c20
0x4c4c9a  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x4c4ca0  3bce                              cmp    ecx,esi
0x4c4ca2  742f                              je     0x4c4cd3
0x4c4ca4  833daca7fb0004                    cmp    DWORD PTR ds:0xfba7ac,0x4
0x4c4cab  750e                              jne    0x4c4cbb
0x4c4cad  8bf9                              mov    edi,ecx
0x4c4caf  e89c020800                        call   0x544f50
0x4c4cb4  bf01000000                        mov    edi,0x1
0x4c4cb9  eb52                              jmp    0x4c4d0d
0x4c4cbb  8b01                              mov    eax,DWORD PTR [ecx]
0x4c4cbd  8b5028                            mov    edx,DWORD PTR [eax+0x28]
0x4c4cc0  ffd2                              call   edx
0x4c4cc2  8b0da4a7fb00                      mov    ecx,DWORD PTR ds:0xfba7a4
0x4c4cc8  3bce                              cmp    ecx,esi
0x4c4cca  7407                              je     0x4c4cd3
0x4c4ccc  8b01                              mov    eax,DWORD PTR [ecx]
0x4c4cce  8b10                              mov    edx,DWORD PTR [eax]
0x4c4cd0  57                                push   edi
0x4c4cd1  ffd2                              call   edx
0x4c4cd3  6838010000                        push   0x138
0x4c4cd8  e88bc53c00                        call   0x891268
0x4c4cdd  83c404                            add    esp,0x4
0x4c4ce0  89442410                          mov    DWORD PTR [esp+0x10],eax
0x4c4ce4  c744242008000000                  mov    DWORD PTR [esp+0x20],0x8
0x4c4cec  3bc6                              cmp    eax,esi
0x4c4cee  7409                              je     0x4c4cf9
0x4c4cf0  8bf0                              mov    esi,eax
0x4c4cf2  e8993e0800                        call   0x548b90
0x4c4cf7  eb02                              jmp    0x4c4cfb
0x4c4cf9  33c0                              xor    eax,eax
0x4c4cfb  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x4c4cff  8b10                              mov    edx,DWORD PTR [eax]
0x4c4d01  a3a4a7fb00                        mov    ds:0xfba7a4,eax
0x4c4d06  8bc8                              mov    ecx,eax
0x4c4d08  8b4224                            mov    eax,DWORD PTR [edx+0x24]
0x4c4d0b  ffd0                              call   eax
0x4c4d0d  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x4c4d14  7524                              jne    0x4c4d3a
0x4c4d16  093d800ffc00                      or     DWORD PTR ds:0xfc0f80,edi
0x4c4d1c  c74424200b000000                  mov    DWORD PTR [esp+0x20],0xb
0x4c4d24  e88761fbff                        call   0x47aeb0
0x4c4d29  6870dbbc00                        push   0xbcdb70
0x4c4d2e  e8e7d53c00                        call   0x89231a
0x4c4d33  83c404                            add    esp,0x4
0x4c4d36  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x4c4d3a  be840ffc00                        mov    esi,0xfc0f84
0x4c4d3f  e81c3dfeff                        call   0x4a8a60
0x4c4d44  33c0                              xor    eax,eax
0x4c4d46  8b4c2418                          mov    ecx,DWORD PTR [esp+0x18]
0x4c4d4a  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c4d51  59                                pop    ecx
0x4c4d52  5f                                pop    edi
0x4c4d53  5e                                pop    esi
0x4c4d54  5b                                pop    ebx
0x4c4d55  8be5                              mov    esp,ebp
0x4c4d57  5d                                pop    ebp
0x4c4d58  c3                                ret

### R07 重驗：fixed TutorialMain/Tutorial_EntryPoint
VA 0x4a8a60 RAW 0xa7e60 END 0x4a8b8d SHA256 f4b6014a2c69e25eb92fc0c95c4beab00880db7d0f5d27c9a53c3b346105e715
0x4a8a60  55                                push   ebp
0x4a8a61  8bec                              mov    ebp,esp
0x4a8a63  6aff                              push   0xffffffff
0x4a8a65  684ca49300                        push   0x93a44c
0x4a8a6a  64a100000000                      mov    eax,fs:0x0
0x4a8a70  50                                push   eax
0x4a8a71  83ec08                            sub    esp,0x8
0x4a8a74  53                                push   ebx
0x4a8a75  57                                push   edi
0x4a8a76  a1201fd600                        mov    eax,ds:0xd61f20
0x4a8a7b  33c5                              xor    eax,ebp
0x4a8a7d  50                                push   eax
0x4a8a7e  8d45f4                            lea    eax,[ebp-0xc]
0x4a8a81  64a300000000                      mov    fs:0x0,eax
0x4a8a87  8d7e04                            lea    edi,[esi+0x4]
0x4a8a8a  c705a0a7fb0000000000              mov    DWORD PTR ds:0xfba7a0,0x0
0x4a8a94  e8b7ad3700                        call   0x823850
0x4a8a99  8d7e14                            lea    edi,[esi+0x14]
0x4a8a9c  e87f893a00                        call   0x851420
0x4a8aa1  bb01000000                        mov    ebx,0x1
0x4a8aa6  83cfff                            or     edi,0xffffffff
0x4a8aa9  841d5473fb00                      test   BYTE PTR ds:0xfb7354,bl
0x4a8aaf  7522                              jne    0x4a8ad3
0x4a8ab1  091d5473fb00                      or     DWORD PTR ds:0xfb7354,ebx
0x4a8ab7  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4a8abe  e80da90a00                        call   0x5533d0
0x4a8ac3  6800d1bc00                        push   0xbcd100
0x4a8ac8  e84d983e00                        call   0x89231a
0x4a8acd  83c404                            add    esp,0x4
0x4a8ad0  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x4a8ad3  891db473fb00                      mov    DWORD PTR ds:0xfb73b4,ebx
0x4a8ad9  841dd4adfa00                      test   BYTE PTR ds:0xfaadd4,bl
0x4a8adf  751e                              jne    0x4a8aff
0x4a8ae1  091dd4adfa00                      or     DWORD PTR ds:0xfaadd4,ebx
0x4a8ae7  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x4a8aea  e891e90d00                        call   0x587480
0x4a8aef  68c0ccbc00                        push   0xbcccc0
0x4a8af4  e821983e00                        call   0x89231a
0x4a8af9  83c404                            add    esp,0x4
0x4a8afc  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x4a8aff  b80f000000                        mov    eax,0xf
0x4a8b04  3905ecadfa00                      cmp    DWORD PTR ds:0xfaadec,eax
0x4a8b0a  7407                              je     0x4a8b13
0x4a8b0c  a3f0adfa00                        mov    ds:0xfaadf0,eax
0x4a8b11  eb05                              jmp    0x4a8b18
0x4a8b13  e8881e0e00                        call   0x58a9a0
0x4a8b18  841d1413fb00                      test   BYTE PTR ds:0xfb1314,bl
0x4a8b1e  7513                              jne    0x4a8b33
0x4a8b20  091d1413fb00                      or     DWORD PTR ds:0xfb1314,ebx
0x4a8b26  6810cfbc00                        push   0xbccf10
0x4a8b2b  e8ea973e00                        call   0x89231a
0x4a8b30  83c404                            add    esp,0x4
0x4a8b33  833d98a7fb0000                    cmp    DWORD PTR ds:0xfba798,0x0
0x4a8b3a  b80c000000                        mov    eax,0xc
0x4a8b3f  668945ec                          mov    WORD PTR [ebp-0x14],ax
0x4a8b43  895dee                            mov    DWORD PTR [ebp-0x12],ebx
0x4a8b46  7515                              jne    0x4a8b5d
0x4a8b48  8b0d54a8fb00                      mov    ecx,DWORD PTR ds:0xfba854
0x4a8b4e  8b11                              mov    edx,DWORD PTR [ecx]
0x4a8b50  8b5210                            mov    edx,DWORD PTR [edx+0x10]
0x4a8b53  6a06                              push   0x6
0x4a8b55  8d45ec                            lea    eax,[ebp-0x14]
0x4a8b58  50                                push   eax
0x4a8b59  6a00                              push   0x0
0x4a8b5b  ffd2                              call   edx
0x4a8b5d  8b0e                              mov    ecx,DWORD PTR [esi]
0x4a8b5f  687c68c000                        push   0xc0687c
0x4a8b64  e8e7be2400                        call   0x6f4a50
0x4a8b69  8b06                              mov    eax,DWORD PTR [esi]
0x4a8b6b  6a00                              push   0x0
0x4a8b6d  6a00                              push   0x0
0x4a8b6f  68a868c000                        push   0xc068a8
0x4a8b74  e857c22400                        call   0x6f4dd0
0x4a8b79  83c40c                            add    esp,0xc
0x4a8b7c  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4a8b7f  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4a8b86  59                                pop    ecx
0x4a8b87  5f                                pop    edi
0x4a8b88  5b                                pop    ebx
0x4a8b89  8be5                              mov    esp,ebp
0x4a8b8b  5d                                pop    ebp
0x4a8b8c  c3                                ret

### R08 重驗：Tutorial field tick; no consumption of T+34
VA 0x4c4df0 RAW 0xc41f0 END 0x4c4ea2 SHA256 52b779dae92ed649222a184e70b08f555f9070b278715a9f213fd5723357a1df
0x4c4df0  55                                push   ebp
0x4c4df1  8bec                              mov    ebp,esp
0x4c4df3  6aff                              push   0xffffffff
0x4c4df5  68dc799400                        push   0x9479dc
0x4c4dfa  64a100000000                      mov    eax,fs:0x0
0x4c4e00  50                                push   eax
0x4c4e01  56                                push   esi
0x4c4e02  57                                push   edi
0x4c4e03  a1201fd600                        mov    eax,ds:0xd61f20
0x4c4e08  33c5                              xor    eax,ebp
0x4c4e0a  50                                push   eax
0x4c4e0b  8d45f4                            lea    eax,[ebp-0xc]
0x4c4e0e  64a300000000                      mov    fs:0x0,eax
0x4c4e14  e8f78cfeff                        call   0x4adb10
0x4c4e19  f605c818fe0001                    test   BYTE PTR ds:0xfe18c8,0x1
0x4c4e20  8bf0                              mov    esi,eax
0x4c4e22  7527                              jne    0x4c4e4b
0x4c4e24  830dc818fe0001                    or     DWORD PTR ds:0xfe18c8,0x1
0x4c4e2b  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4c4e32  e839ab0700                        call   0x53f970
0x4c4e37  6810e8bc00                        push   0xbce810
0x4c4e3c  e8d9d43c00                        call   0x89231a
0x4c4e41  83c404                            add    esp,0x4
0x4c4e44  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c4e4b  bfcc18fe00                        mov    edi,0xfe18cc
0x4c4e50  e8fbb00700                        call   0x53ff50
0x4c4e55  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x4c4e5c  7527                              jne    0x4c4e85
0x4c4e5e  b801000000                        mov    eax,0x1
0x4c4e63  0905800ffc00                      or     DWORD PTR ds:0xfc0f80,eax
0x4c4e69  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x4c4e6c  e83f60fbff                        call   0x47aeb0
0x4c4e71  6870dbbc00                        push   0xbcdb70
0x4c4e76  e89fd43c00                        call   0x89231a
0x4c4e7b  83c404                            add    esp,0x4
0x4c4e7e  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c4e85  68840ffc00                        push   0xfc0f84
0x4c4e8a  e8013dfeff                        call   0x4a8b90
0x4c4e8f  8bc6                              mov    eax,esi
0x4c4e91  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4c4e94  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c4e9b  59                                pop    ecx
0x4c4e9c  5f                                pop    edi
0x4c4e9d  5e                                pop    esi
0x4c4e9e  8be5                              mov    esp,ebp
0x4c4ea0  5d                                pop    ebp
0x4c4ea1  c3                                ret

### R09 重驗：Tutorial field exit removes tco
VA 0x4c4d60 RAW 0xc4160 END 0x4c4de2 SHA256 6a4c57774a6ff8aecb820bdffe6ecc177944b6f9e57862dec6bb82dbf008ff89
0x4c4d60  55                                push   ebp
0x4c4d61  8bec                              mov    ebp,esp
0x4c4d63  6aff                              push   0xffffffff
0x4c4d65  68ce3e9300                        push   0x933ece
0x4c4d6a  64a100000000                      mov    eax,fs:0x0
0x4c4d70  50                                push   eax
0x4c4d71  a1201fd600                        mov    eax,ds:0xd61f20
0x4c4d76  33c5                              xor    eax,ebp
0x4c4d78  50                                push   eax
0x4c4d79  8d45f4                            lea    eax,[ebp-0xc]
0x4c4d7c  64a300000000                      mov    fs:0x0,eax
0x4c4d82  b801000000                        mov    eax,0x1
0x4c4d87  8405800ffc00                      test   BYTE PTR ds:0xfc0f80,al
0x4c4d8d  7526                              jne    0x4c4db5
0x4c4d8f  0905800ffc00                      or     DWORD PTR ds:0xfc0f80,eax
0x4c4d95  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4c4d9c  e80f61fbff                        call   0x47aeb0
0x4c4da1  6870dbbc00                        push   0xbcdb70
0x4c4da6  e86fd53c00                        call   0x89231a
0x4c4dab  83c404                            add    esp,0x4
0x4c4dae  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c4db5  a1840ffc00                        mov    eax,ds:0xfc0f84
0x4c4dba  68bc68c000                        push   0xc068bc
0x4c4dbf  6a00                              push   0x0
0x4c4dc1  50                                push   eax
0x4c4dc2  e8d982feff                        call   0x4ad0a0
0x4c4dc7  b9840ffc00                        mov    ecx,0xfc0f84
0x4c4dcc  e8df4ffeff                        call   0x4a9db0
0x4c4dd1  33c0                              xor    eax,eax
0x4c4dd3  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4c4dd6  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c4ddd  59                                pop    ecx
0x4c4dde  8be5                              mov    esp,ebp
0x4c4de0  5d                                pop    ebp
0x4c4de1  c3                                ret

### R10 Expedition tag EXPD, field+BD78 initialized0
VA 0x4c13e0 RAW 0xc07e0 END 0x4c152e SHA256 1aeae80c48cb8387c3404cf2e9dc63ac7d04410e323110f0ab7abf56955ab3e5
0x4c13e0  55                                push   ebp
0x4c13e1  8bec                              mov    ebp,esp
0x4c13e3  6aff                              push   0xffffffff
0x4c13e5  6828909400                        push   0x949028
0x4c13ea  64a100000000                      mov    eax,fs:0x0
0x4c13f0  50                                push   eax
0x4c13f1  83ec10                            sub    esp,0x10
0x4c13f4  56                                push   esi
0x4c13f5  57                                push   edi
0x4c13f6  a1201fd600                        mov    eax,ds:0xd61f20
0x4c13fb  33c5                              xor    eax,ebp
0x4c13fd  50                                push   eax
0x4c13fe  8d45f4                            lea    eax,[ebp-0xc]
0x4c1401  64a300000000                      mov    fs:0x0,eax
0x4c1407  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x4c140a  8bc6                              mov    eax,esi
0x4c140c  c70574a6d6004c4c554e              mov    DWORD PTR ds:0xd6a674,0x4e554c4c
0x4c1416  e835c9feff                        call   0x4add50
0x4c141b  33ff                              xor    edi,edi
0x4c141d  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x4c1420  0f57c0                            xorps  xmm0,xmm0
0x4c1423  c7068072c000                      mov    DWORD PTR [esi],0xc07280
0x4c1429  89be54bd0000                      mov    DWORD PTR [esi+0xbd54],edi
0x4c142f  c78658bd00000a000000              mov    DWORD PTR [esi+0xbd58],0xa
0x4c1439  89be5cbd0000                      mov    DWORD PTR [esi+0xbd5c],edi
0x4c143f  f30f118660bd0000                  movss  DWORD PTR [esi+0xbd60],xmm0
0x4c1447  f30f118664bd0000                  movss  DWORD PTR [esi+0xbd64],xmm0
0x4c144f  f30f118668bd0000                  movss  DWORD PTR [esi+0xbd68],xmm0
0x4c1457  f30f11866cbd0000                  movss  DWORD PTR [esi+0xbd6c],xmm0
0x4c145f  89be70bd0000                      mov    DWORD PTR [esi+0xbd70],edi
0x4c1465  89be78bd0000                      mov    DWORD PTR [esi+0xbd78],edi
0x4c146b  6a18                              push   0x18
0x4c146d  89be84bd0000                      mov    DWORD PTR [esi+0xbd84],edi
0x4c1473  e8f0fd3c00                        call   0x891268
0x4c1478  83c404                            add    esp,0x4
0x4c147b  3bc7                              cmp    eax,edi
0x4c147d  0f8487000000                      je     0x4c150a
0x4c1483  898680bd0000                      mov    DWORD PTR [esi+0xbd80],eax
0x4c1489  8900                              mov    DWORD PTR [eax],eax
0x4c148b  8b8680bd0000                      mov    eax,DWORD PTR [esi+0xbd80]
0x4c1491  894004                            mov    DWORD PTR [eax+0x4],eax
0x4c1494  8b8680bd0000                      mov    eax,DWORD PTR [esi+0xbd80]
0x4c149a  894008                            mov    DWORD PTR [eax+0x8],eax
0x4c149d  8b8e80bd0000                      mov    ecx,DWORD PTR [esi+0xbd80]
0x4c14a3  b001                              mov    al,0x1
0x4c14a5  884114                            mov    BYTE PTR [ecx+0x14],al
0x4c14a8  8b9680bd0000                      mov    edx,DWORD PTR [esi+0xbd80]
0x4c14ae  68a85e0000                        push   0x5ea8
0x4c14b3  884215                            mov    BYTE PTR [edx+0x15],al
0x4c14b6  8d86ac5e0000                      lea    eax,[esi+0x5eac]
0x4c14bc  57                                push   edi
0x4c14bd  50                                push   eax
0x4c14be  c70574a6d60044505845              mov    DWORD PTR ds:0xd6a674,0x45585044
0x4c14c8  e893d33d00                        call   0x89e860
0x4c14cd  b87523bf00                        mov    eax,0xbf2375
0x4c14d2  898600610000                      mov    DWORD PTR [esi+0x6100],eax
0x4c14d8  8986f0610000                      mov    DWORD PTR [esi+0x61f0],eax
0x4c14de  83c40c                            add    esp,0xc
0x4c14e1  c786fc600000d0214c00              mov    DWORD PTR [esi+0x60fc],0x4c21d0
0x4c14eb  c786ec610000f0214c00              mov    DWORD PTR [esi+0x61ec],0x4c21f0
0x4c14f5  8bc6                              mov    eax,esi
0x4c14f7  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4c14fa  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c1501  59                                pop    ecx
0x4c1502  5f                                pop    edi
0x4c1503  5e                                pop    esi
0x4c1504  8be5                              mov    esp,ebp
0x4c1506  5d                                pop    ebp
0x4c1507  c20400                            ret    0x4
0x4c150a  8d4df0                            lea    ecx,[ebp-0x10]
0x4c150d  51                                push   ecx
0x4c150e  8d4de4                            lea    ecx,[ebp-0x1c]
0x4c1511  897df0                            mov    DWORD PTR [ebp-0x10],edi
0x4c1514  e890fb3c00                        call   0x8910a9
0x4c1519  68a857c800                        push   0xc857a8
0x4c151e  8d55e4                            lea    edx,[ebp-0x1c]
0x4c1521  52                                push   edx
0x4c1522  c745e4a42cbd00                    mov    DWORD PTR [ebp-0x1c],0xbd2ca4
0x4c1529  e8c2b43d00                        call   0x89c9f0

### R11 重驗：Expedition+BD78 enable and Synopsis entry
VA 0x4c1e10 RAW 0xc1210 END 0x4c204f SHA256 f82e46de9c9eecb337ea9f13532193a4dd94a0382d73d901dc827dd5b36f2957
0x4c1e10  55                                push   ebp
0x4c1e11  8bec                              mov    ebp,esp
0x4c1e13  83e4f8                            and    esp,0xfffffff8
0x4c1e16  6aff                              push   0xffffffff
0x4c1e18  689ca59300                        push   0x93a59c
0x4c1e1d  64a100000000                      mov    eax,fs:0x0
0x4c1e23  50                                push   eax
0x4c1e24  83ec10                            sub    esp,0x10
0x4c1e27  53                                push   ebx
0x4c1e28  56                                push   esi
0x4c1e29  57                                push   edi
0x4c1e2a  a1201fd600                        mov    eax,ds:0xd61f20
0x4c1e2f  33c4                              xor    eax,esp
0x4c1e31  50                                push   eax
0x4c1e32  8d442420                          lea    eax,[esp+0x20]
0x4c1e36  64a300000000                      mov    fs:0x0,eax
0x4c1e3c  6a1c                              push   0x1c
0x4c1e3e  e825f43c00                        call   0x891268
0x4c1e43  33db                              xor    ebx,ebx
0x4c1e45  83c404                            add    esp,0x4
0x4c1e48  3bc3                              cmp    eax,ebx
0x4c1e4a  7411                              je     0x4c1e5d
0x4c1e4c  8918                              mov    DWORD PTR [eax],ebx
0x4c1e4e  c6400801                          mov    BYTE PTR [eax+0x8],0x1
0x4c1e52  89580c                            mov    DWORD PTR [eax+0xc],ebx
0x4c1e55  895810                            mov    DWORD PTR [eax+0x10],ebx
0x4c1e58  895814                            mov    DWORD PTR [eax+0x14],ebx
0x4c1e5b  eb02                              jmp    0x4c1e5f
0x4c1e5d  33c0                              xor    eax,eax
0x4c1e5f  50                                push   eax
0x4c1e60  8d442418                          lea    eax,[esp+0x18]
0x4c1e64  50                                push   eax
0x4c1e65  895c241c                          mov    DWORD PTR [esp+0x1c],ebx
0x4c1e69  895c2420                          mov    DWORD PTR [esp+0x20],ebx
0x4c1e6d  e85ea2fbff                        call   0x47c0d0
0x4c1e72  895c2428                          mov    DWORD PTR [esp+0x28],ebx
0x4c1e76  8b742414                          mov    esi,DWORD PTR [esp+0x14]
0x4c1e7a  c6460801                          mov    BYTE PTR [esi+0x8],0x1
0x4c1e7e  8d7e0c                            lea    edi,[esi+0xc]
0x4c1e81  8d442410                          lea    eax,[esp+0x10]
0x4c1e85  c7460403000000                    mov    DWORD PTR [esi+0x4],0x3
0x4c1e8c  c7442410f8030000                  mov    DWORD PTR [esp+0x10],0x3f8
0x4c1e94  e8e767feff                        call   0x4a8680
0x4c1e99  8d442410                          lea    eax,[esp+0x10]
0x4c1e9d  c7442410f9030000                  mov    DWORD PTR [esp+0x10],0x3f9
0x4c1ea5  e8d667feff                        call   0x4a8680
0x4c1eaa  8d442410                          lea    eax,[esp+0x10]
0x4c1eae  c744241014270000                  mov    DWORD PTR [esp+0x10],0x2714
0x4c1eb6  e8c567feff                        call   0x4a8680
0x4c1ebb  8d442410                          lea    eax,[esp+0x10]
0x4c1ebf  c744241015270000                  mov    DWORD PTR [esp+0x10],0x2715
0x4c1ec7  e8b467feff                        call   0x4a8680
0x4c1ecc  8d442410                          lea    eax,[esp+0x10]
0x4c1ed0  c744241016270000                  mov    DWORD PTR [esp+0x10],0x2716
0x4c1ed8  e8a367feff                        call   0x4a8680
0x4c1edd  8d442410                          lea    eax,[esp+0x10]
0x4c1ee1  c744241017270000                  mov    DWORD PTR [esp+0x10],0x2717
0x4c1ee9  e89267feff                        call   0x4a8680
0x4c1eee  8d442410                          lea    eax,[esp+0x10]
0x4c1ef2  c744241038270000                  mov    DWORD PTR [esp+0x10],0x2738
0x4c1efa  e88167feff                        call   0x4a8680
0x4c1eff  8d442410                          lea    eax,[esp+0x10]
0x4c1f03  c744241044270000                  mov    DWORD PTR [esp+0x10],0x2744
0x4c1f0b  e87067feff                        call   0x4a8680
0x4c1f10  8d442410                          lea    eax,[esp+0x10]
0x4c1f14  c744241045270000                  mov    DWORD PTR [esp+0x10],0x2745
0x4c1f1c  e85f67feff                        call   0x4a8680
0x4c1f21  8d442410                          lea    eax,[esp+0x10]
0x4c1f25  c74424102b4e0000                  mov    DWORD PTR [esp+0x10],0x4e2b
0x4c1f2d  e84e67feff                        call   0x4a8680
0x4c1f32  8d442410                          lea    eax,[esp+0x10]
0x4c1f36  c7442410314e0000                  mov    DWORD PTR [esp+0x10],0x4e31
0x4c1f3e  e83d67feff                        call   0x4a8680
0x4c1f43  8b542418                          mov    edx,DWORD PTR [esp+0x18]
0x4c1f47  83ec08                            sub    esp,0x8
0x4c1f4a  8bfc                              mov    edi,esp
0x4c1f4c  89642418                          mov    DWORD PTR [esp+0x18],esp
0x4c1f50  891f                              mov    DWORD PTR [edi],ebx
0x4c1f52  895f04                            mov    DWORD PTR [edi+0x4],ebx
0x4c1f55  3bd3                              cmp    edx,ebx
0x4c1f57  7416                              je     0x4c1f6f
0x4c1f59  e8f2a2fbff                        call   0x47c250
0x4c1f5e  84c0                              test   al,al
0x4c1f60  740d                              je     0x4c1f6f
0x4c1f62  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x4c1f66  51                                push   ecx
0x4c1f67  56                                push   esi
0x4c1f68  8bf7                              mov    esi,edi
0x4c1f6a  e851122e00                        call   0x7a31c0
0x4c1f6f  c644243001                        mov    BYTE PTR [esp+0x30],0x1
0x4c1f74  f605600ffc0001                    test   BYTE PTR ds:0xfc0f60,0x1
0x4c1f7b  bf01000000                        mov    edi,0x1
0x4c1f80  7522                              jne    0x4c1fa4
0x4c1f82  093d600ffc00                      or     DWORD PTR ds:0xfc0f60,edi
0x4c1f88  c644243002                        mov    BYTE PTR [esp+0x30],0x2
0x4c1f8d  e8aeaf2d00                        call   0x79cf40
0x4c1f92  6880dbbc00                        push   0xbcdb80
0x4c1f97  e87e033d00                        call   0x89231a
0x4c1f9c  83c404                            add    esp,0x4
0x4c1f9f  c644243001                        mov    BYTE PTR [esp+0x30],0x1
0x4c1fa4  b9900efc00                        mov    ecx,0xfc0e90
0x4c1fa9  885c2430                          mov    BYTE PTR [esp+0x30],bl
0x4c1fad  e82ebd2d00                        call   0x79dce0
0x4c1fb2  8bf0                              mov    esi,eax
0x4c1fb4  6aff                              push   0xffffffff
0x4c1fb6  56                                push   esi
0x4c1fb7  ff15fc20bd00                      call   DWORD PTR ds:0xbd20fc
0x4c1fbd  56                                push   esi
0x4c1fbe  ff15c821bd00                      call   DWORD PTR ds:0xbd21c8
0x4c1fc4  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x4c1fcb  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x4c1fce  89ba78bd0000                      mov    DWORD PTR [edx+0xbd78],edi
0x4c1fd4  7521                              jne    0x4c1ff7
0x4c1fd6  093d800ffc00                      or     DWORD PTR ds:0xfc0f80,edi
0x4c1fdc  c644242803                        mov    BYTE PTR [esp+0x28],0x3
0x4c1fe1  e8ca8efbff                        call   0x47aeb0
0x4c1fe6  6870dbbc00                        push   0xbcdb70
0x4c1feb  e82a033d00                        call   0x89231a
0x4c1ff0  83c404                            add    esp,0x4
0x4c1ff3  885c2428                          mov    BYTE PTR [esp+0x28],bl
0x4c1ff7  be840ffc00                        mov    esi,0xfc0f84
0x4c1ffc  e8bf69feff                        call   0x4a89c0
0x4c2001  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x4c2009  8b742418                          mov    esi,DWORD PTR [esp+0x18]
0x4c200d  3bf3                              cmp    esi,ebx
0x4c200f  7429                              je     0x4c203a
0x4c2011  8d4604                            lea    eax,[esi+0x4]
0x4c2014  83c9ff                            or     ecx,0xffffffff
0x4c2017  f00fc108                          lock xadd DWORD PTR [eax],ecx
0x4c201b  751d                              jne    0x4c203a
0x4c201d  8b16                              mov    edx,DWORD PTR [esi]
0x4c201f  8b02                              mov    eax,DWORD PTR [edx]
0x4c2021  8bce                              mov    ecx,esi
0x4c2023  ffd0                              call   eax
0x4c2025  8d4e08                            lea    ecx,[esi+0x8]
0x4c2028  83caff                            or     edx,0xffffffff
0x4c202b  f00fc111                          lock xadd DWORD PTR [ecx],edx
0x4c202f  7509                              jne    0x4c203a
0x4c2031  8b06                              mov    eax,DWORD PTR [esi]
0x4c2033  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x4c2036  8bce                              mov    ecx,esi
0x4c2038  ffd2                              call   edx
0x4c203a  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x4c203e  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c2045  59                                pop    ecx
0x4c2046  5f                                pop    edi
0x4c2047  5e                                pop    esi
0x4c2048  5b                                pop    ebx
0x4c2049  8be5                              mov    esp,ebp
0x4c204b  5d                                pop    ebp
0x4c204c  c20400                            ret    0x4

### R12 重驗：fixed TutorialMain/Synopsis_EntryPoint
VA 0x4a89c0 RAW 0xa7dc0 END 0x4a8a5e SHA256 6e3761a6fe77f800e4af8d145992fc0d537a826e39b8c6fc2e31868710d5dc46
0x4a89c0  55                                push   ebp
0x4a89c1  8bec                              mov    ebp,esp
0x4a89c3  6aff                              push   0xffffffff
0x4a89c5  687ea49300                        push   0x93a47e
0x4a89ca  64a100000000                      mov    eax,fs:0x0
0x4a89d0  50                                push   eax
0x4a89d1  57                                push   edi
0x4a89d2  a1201fd600                        mov    eax,ds:0xd61f20
0x4a89d7  33c5                              xor    eax,ebp
0x4a89d9  50                                push   eax
0x4a89da  8d45f4                            lea    eax,[ebp-0xc]
0x4a89dd  64a300000000                      mov    fs:0x0,eax
0x4a89e3  8d7e14                            lea    edi,[esi+0x14]
0x4a89e6  c705a0a7fb0000000000              mov    DWORD PTR ds:0xfba7a0,0x0
0x4a89f0  e82b8a3a00                        call   0x851420
0x4a89f5  f6055473fb0001                    test   BYTE PTR ds:0xfb7354,0x1
0x4a89fc  7527                              jne    0x4a8a25
0x4a89fe  830d5473fb0001                    or     DWORD PTR ds:0xfb7354,0x1
0x4a8a05  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4a8a0c  e8bfa90a00                        call   0x5533d0
0x4a8a11  6800d1bc00                        push   0xbcd100
0x4a8a16  e8ff983e00                        call   0x89231a
0x4a8a1b  83c404                            add    esp,0x4
0x4a8a1e  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a8a25  c705b473fb0001000000              mov    DWORD PTR ds:0xfb73b4,0x1
0x4a8a2f  8b0e                              mov    ecx,DWORD PTR [esi]
0x4a8a31  687c68c000                        push   0xc0687c
0x4a8a36  e815c02400                        call   0x6f4a50
0x4a8a3b  8b06                              mov    eax,DWORD PTR [esi]
0x4a8a3d  6a00                              push   0x0
0x4a8a3f  6a00                              push   0x0
0x4a8a41  689468c000                        push   0xc06894
0x4a8a46  e885c32400                        call   0x6f4dd0
0x4a8a4b  83c40c                            add    esp,0xc
0x4a8a4e  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4a8a51  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4a8a58  59                                pop    ecx
0x4a8a59  5f                                pop    edi
0x4a8a5a  8be5                              mov    esp,ebp
0x4a8a5c  5d                                pop    ebp
0x4a8a5d  c3                                ret

### R13 重驗：Expedition gated T tick and status0 finish
VA 0x4c1930 RAW 0xc0d30 END 0x4c1c72 SHA256 aafa813d51386ba2eb688e54b58a3c11fe053f24cdf6cfa6c3b59ea4978a2029
0x4c1930  55                                push   ebp
0x4c1931  8bec                              mov    ebp,esp
0x4c1933  83e4f8                            and    esp,0xfffffff8
0x4c1936  6aff                              push   0xffffffff
0x4c1938  68d2079400                        push   0x9407d2
0x4c193d  64a100000000                      mov    eax,fs:0x0
0x4c1943  50                                push   eax
0x4c1944  83ec28                            sub    esp,0x28
0x4c1947  53                                push   ebx
0x4c1948  56                                push   esi
0x4c1949  57                                push   edi
0x4c194a  a1201fd600                        mov    eax,ds:0xd61f20
0x4c194f  33c4                              xor    eax,esp
0x4c1951  50                                push   eax
0x4c1952  8d442438                          lea    eax,[esp+0x38]
0x4c1956  64a300000000                      mov    fs:0x0,eax
0x4c195c  8bf1                              mov    esi,ecx
0x4c195e  89742410                          mov    DWORD PTR [esp+0x10],esi
0x4c1962  83be78bd000000                    cmp    DWORD PTR [esi+0xbd78],0x0
0x4c1969  bf01000000                        mov    edi,0x1
0x4c196e  0f84c2000000                      je     0x4c1a36
0x4c1974  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x4c197b  7529                              jne    0x4c19a6
0x4c197d  093d800ffc00                      or     DWORD PTR ds:0xfc0f80,edi
0x4c1983  c744244000000000                  mov    DWORD PTR [esp+0x40],0x0
0x4c198b  e82095fbff                        call   0x47aeb0
0x4c1990  6870dbbc00                        push   0xbcdb70
0x4c1995  e880093d00                        call   0x89231a
0x4c199a  83c404                            add    esp,0x4
0x4c199d  83cbff                            or     ebx,0xffffffff
0x4c19a0  895c2440                          mov    DWORD PTR [esp+0x40],ebx
0x4c19a4  eb03                              jmp    0x4c19a9
0x4c19a6  83cbff                            or     ebx,0xffffffff
0x4c19a9  68840ffc00                        push   0xfc0f84
0x4c19ae  e8dd71feff                        call   0x4a8b90
0x4c19b3  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x4c19ba  7520                              jne    0x4c19dc
0x4c19bc  093d800ffc00                      or     DWORD PTR ds:0xfc0f80,edi
0x4c19c2  897c2440                          mov    DWORD PTR [esp+0x40],edi
0x4c19c6  e8e594fbff                        call   0x47aeb0
0x4c19cb  6870dbbc00                        push   0xbcdb70
0x4c19d0  e845093d00                        call   0x89231a
0x4c19d5  83c404                            add    esp,0x4
0x4c19d8  895c2440                          mov    DWORD PTR [esp+0x40],ebx
0x4c19dc  833db80ffc0000                    cmp    DWORD PTR ds:0xfc0fb8,0x0
0x4c19e3  7554                              jne    0x4c1a39
0x4c19e5  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x4c19ec  7524                              jne    0x4c1a12
0x4c19ee  093d800ffc00                      or     DWORD PTR ds:0xfc0f80,edi
0x4c19f4  c744244002000000                  mov    DWORD PTR [esp+0x40],0x2
0x4c19fc  e8af94fbff                        call   0x47aeb0
0x4c1a01  6870dbbc00                        push   0xbcdb70
0x4c1a06  e80f093d00                        call   0x89231a
0x4c1a0b  83c404                            add    esp,0x4
0x4c1a0e  895c2440                          mov    DWORD PTR [esp+0x40],ebx
0x4c1a12  a1840ffc00                        mov    eax,ds:0xfc0f84
0x4c1a17  68bc68c000                        push   0xc068bc
0x4c1a1c  6a00                              push   0x0
0x4c1a1e  50                                push   eax
0x4c1a1f  e87cb6feff                        call   0x4ad0a0
0x4c1a24  b9840ffc00                        mov    ecx,0xfc0f84
0x4c1a29  e88283feff                        call   0x4a9db0
0x4c1a2e  56                                push   esi
0x4c1a2f  e81c060000                        call   0x4c2050
0x4c1a34  eb03                              jmp    0x4c1a39
0x4c1a36  83cbff                            or     ebx,0xffffffff
0x4c1a39  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
0x4c1a40  7524                              jne    0x4c1a66
0x4c1a42  093d9043f900                      or     DWORD PTR ds:0xf94390,edi
0x4c1a48  c744244003000000                  mov    DWORD PTR [esp+0x40],0x3
0x4c1a50  e83bfb0100                        call   0x4e1590
0x4c1a55  6880ccbc00                        push   0xbccc80
0x4c1a5a  e8bb083d00                        call   0x89231a
0x4c1a5f  83c404                            add    esp,0x4
0x4c1a62  895c2440                          mov    DWORD PTR [esp+0x40],ebx
0x4c1a66  803da542f90000                    cmp    BYTE PTR ds:0xf942a5,0x0
0x4c1a6d  0f85e3010000                      jne    0x4c1c56
0x4c1a73  f605e879fb0001                    test   BYTE PTR ds:0xfb79e8,0x1
0x4c1a7a  8b351813fb00                      mov    esi,DWORD PTR ds:0xfb1318
0x4c1a80  7524                              jne    0x4c1aa6
0x4c1a82  093de879fb00                      or     DWORD PTR ds:0xfb79e8,edi
0x4c1a88  c744244004000000                  mov    DWORD PTR [esp+0x40],0x4
0x4c1a90  e84b732d00                        call   0x798de0
0x4c1a95  68e0d2bc00                        push   0xbcd2e0
0x4c1a9a  e87b083d00                        call   0x89231a
0x4c1a9f  83c404                            add    esp,0x4
0x4c1aa2  895c2440                          mov    DWORD PTR [esp+0x40],ebx
0x4c1aa6  8b8e10c00000                      mov    ecx,DWORD PTR [esi+0xc010]
0x4c1aac  8b960cc00000                      mov    edx,DWORD PTR [esi+0xc00c]
0x4c1ab2  51                                push   ecx
0x4c1ab3  52                                push   edx
0x4c1ab4  8d442424                          lea    eax,[esp+0x24]
0x4c1ab8  50                                push   eax
0x4c1ab9  68a876fb00                        push   0xfb76a8
0x4c1abe  8d7c2438                          lea    edi,[esp+0x38]
0x4c1ac2  e8d98c2d00                        call   0x79a7a0
0x4c1ac7  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x4c1acb  899974bd0000                      mov    DWORD PTR [ecx+0xbd74],ebx
0x4c1ad1  bb09000000                        mov    ebx,0x9
0x4c1ad6  be28230000                        mov    esi,0x2328
0x4c1adb  eb03                              jmp    0x4c1ae0
0x4c1add  8d4900                            lea    ecx,[ecx+0x0]
0x4c1ae0  f6052cb2fa0001                    test   BYTE PTR ds:0xfab22c,0x1
0x4c1ae7  7529                              jne    0x4c1b12
0x4c1ae9  830d2cb2fa0001                    or     DWORD PTR ds:0xfab22c,0x1
0x4c1af0  c744244005000000                  mov    DWORD PTR [esp+0x40],0x5
0x4c1af8  e893d10100                        call   0x4dec90
0x4c1afd  6830cebc00                        push   0xbcce30
0x4c1b02  e813083d00                        call   0x89231a
0x4c1b07  83c404                            add    esp,0x4
0x4c1b0a  c7442440ffffffff                  mov    DWORD PTR [esp+0x40],0xffffffff
0x4c1b12  8d542414                          lea    edx,[esp+0x14]
0x4c1b16  52                                push   edx
0x4c1b17  8d44241c                          lea    eax,[esp+0x1c]
0x4c1b1b  b938b1fa00                        mov    ecx,0xfab138
0x4c1b20  89742418                          mov    DWORD PTR [esp+0x18],esi
0x4c1b24  e8d7d33600                        call   0x82ef00
0x4c1b29  8b442418                          mov    eax,DWORD PTR [esp+0x18]
0x4c1b2d  3b053cb1fa00                      cmp    eax,DWORD PTR ds:0xfab13c
0x4c1b33  7423                              je     0x4c1b58
0x4c1b35  8b4010                            mov    eax,DWORD PTR [eax+0x10]
0x4c1b38  85c0                              test   eax,eax
0x4c1b3a  741c                              je     0x4c1b58
0x4c1b3c  8bb85c010000                      mov    edi,DWORD PTR [eax+0x15c]
0x4c1b42  85ff                              test   edi,edi
0x4c1b44  7412                              je     0x4c1b58
0x4c1b46  8d44241c                          lea    eax,[esp+0x1c]
0x4c1b4a  50                                push   eax
0x4c1b4b  8d4c242c                          lea    ecx,[esp+0x2c]
0x4c1b4f  e8dc642e00                        call   0x7a8030
0x4c1b54  85c0                              test   eax,eax
0x4c1b56  750f                              jne    0x4c1b67
0x4c1b58  4b                                dec    ebx
0x4c1b59  81eee8030000                      sub    esi,0x3e8
0x4c1b5f  0f897bffffff                      jns    0x4c1ae0
0x4c1b65  eb0a                              jmp    0x4c1b71
0x4c1b67  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x4c1b6b  899974bd0000                      mov    DWORD PTR [ecx+0xbd74],ebx
0x4c1b71  8b542410                          mov    edx,DWORD PTR [esp+0x10]
0x4c1b75  83ba74bd000000                    cmp    DWORD PTR [edx+0xbd74],0x0
0x4c1b7c  0f8cd4000000                      jl     0x4c1c56
0x4c1b82  a10ca8fb00                        mov    eax,ds:0xfba80c
0x4c1b87  85c0                              test   eax,eax
0x4c1b89  7521                              jne    0x4c1bac
0x4c1b8b  687c050000                        push   0x57c
0x4c1b90  e8d3f63c00                        call   0x891268
0x4c1b95  83c404                            add    esp,0x4
0x4c1b98  85c0                              test   eax,eax
0x4c1b9a  7409                              je     0x4c1ba5
0x4c1b9c  8bf0                              mov    esi,eax
0x4c1b9e  e8cdf72200                        call   0x6f1370
0x4c1ba3  eb02                              jmp    0x4c1ba7
0x4c1ba5  33c0                              xor    eax,eax
0x4c1ba7  a30ca8fb00                        mov    ds:0xfba80c,eax
0x4c1bac  83782000                          cmp    DWORD PTR [eax+0x20],0x0
0x4c1bb0  0f84a0000000                      je     0x4c1c56
0x4c1bb6  80b86803000001                    cmp    BYTE PTR [eax+0x368],0x1
0x4c1bbd  0f8593000000                      jne    0x4c1c56
0x4c1bc3  6a18                              push   0x18
0x4c1bc5  e89ef63c00                        call   0x891268
0x4c1bca  83c404                            add    esp,0x4
0x4c1bcd  85c0                              test   eax,eax
0x4c1bcf  742e                              je     0x4c1bff
0x4c1bd1  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x4c1bd5  8b8974bd0000                      mov    ecx,DWORD PTR [ecx+0xbd74]
0x4c1bdb  83cfff                            or     edi,0xffffffff
0x4c1bde  897804                            mov    DWORD PTR [eax+0x4],edi
0x4c1be1  897808                            mov    DWORD PTR [eax+0x8],edi
0x4c1be4  c7400c00000000                    mov    DWORD PTR [eax+0xc],0x0
0x4c1beb  c7401046420f00                    mov    DWORD PTR [eax+0x10],0xf4246
0x4c1bf2  c700ac67c400                      mov    DWORD PTR [eax],0xc467ac
0x4c1bf8  894814                            mov    DWORD PTR [eax+0x14],ecx
0x4c1bfb  8bf0                              mov    esi,eax
0x4c1bfd  eb05                              jmp    0x4c1c04
0x4c1bff  33f6                              xor    esi,esi
0x4c1c01  83cfff                            or     edi,0xffffffff
0x4c1c04  f605d0adfa0001                    test   BYTE PTR ds:0xfaadd0,0x1
0x4c1c0b  7525                              jne    0x4c1c32
0x4c1c0d  830dd0adfa0001                    or     DWORD PTR ds:0xfaadd0,0x1
0x4c1c14  c744244006000000                  mov    DWORD PTR [esp+0x40],0x6
0x4c1c1c  e86fbd2800                        call   0x74d990
0x4c1c21  6870ccbc00                        push   0xbccc70
0x4c1c26  e8ef063d00                        call   0x89231a
0x4c1c2b  83c404                            add    esp,0x4
0x4c1c2e  897c2440                          mov    DWORD PTR [esp+0x40],edi
0x4c1c32  8b0dd45bf900                      mov    ecx,DWORD PTR ds:0xf95bd4
0x4c1c38  85c9                              test   ecx,ecx
0x4c1c3a  740b                              je     0x4c1c47
0x4c1c3c  8b11                              mov    edx,DWORD PTR [ecx]
0x4c1c3e  8b825c010000                      mov    eax,DWORD PTR [edx+0x15c]
0x4c1c44  56                                push   esi
0x4c1c45  ffd0                              call   eax
0x4c1c47  85f6                              test   esi,esi
0x4c1c49  740b                              je     0x4c1c56
0x4c1c4b  8b16                              mov    edx,DWORD PTR [esi]
0x4c1c4d  8b4210                            mov    eax,DWORD PTR [edx+0x10]
0x4c1c50  6a01                              push   0x1
0x4c1c52  8bce                              mov    ecx,esi
0x4c1c54  ffd0                              call   eax
0x4c1c56  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x4c1c5a  e8b1befeff                        call   0x4adb10
0x4c1c5f  8b4c2438                          mov    ecx,DWORD PTR [esp+0x38]
0x4c1c63  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c1c6a  59                                pop    ecx
0x4c1c6b  5f                                pop    edi
0x4c1c6c  5e                                pop    esi
0x4c1c6d  5b                                pop    ebx
0x4c1c6e  8be5                              mov    esp,ebp
0x4c1c70  5d                                pop    ebp
0x4c1c71  c3                                ret

### R14 重驗：Expedition finish clears gate and removes tco
VA 0x4c2050 RAW 0xc1450 END 0x4c21d0 SHA256 a749c2f0ea7db405cf505bf8bdbf8a3de45c2232a1d0832fdd82f6f578bfadb5
0x4c2050  55                                push   ebp
0x4c2051  8bec                              mov    ebp,esp
0x4c2053  6aff                              push   0xffffffff
0x4c2055  68cc969300                        push   0x9396cc
0x4c205a  64a100000000                      mov    eax,fs:0x0
0x4c2060  50                                push   eax
0x4c2061  83ec10                            sub    esp,0x10
0x4c2064  53                                push   ebx
0x4c2065  56                                push   esi
0x4c2066  57                                push   edi
0x4c2067  a1201fd600                        mov    eax,ds:0xd61f20
0x4c206c  33c5                              xor    eax,ebp
0x4c206e  50                                push   eax
0x4c206f  8d45f4                            lea    eax,[ebp-0xc]
0x4c2072  64a300000000                      mov    fs:0x0,eax
0x4c2078  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x4c207f  7527                              jne    0x4c20a8
0x4c2081  830d800ffc0001                    or     DWORD PTR ds:0xfc0f80,0x1
0x4c2088  33ff                              xor    edi,edi
0x4c208a  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x4c208d  e81e8efbff                        call   0x47aeb0
0x4c2092  6870dbbc00                        push   0xbcdb70
0x4c2097  e87e023d00                        call   0x89231a
0x4c209c  83c404                            add    esp,0x4
0x4c209f  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c20a6  eb02                              jmp    0x4c20aa
0x4c20a8  33ff                              xor    edi,edi
0x4c20aa  a1840ffc00                        mov    eax,ds:0xfc0f84
0x4c20af  68bc68c000                        push   0xc068bc
0x4c20b4  57                                push   edi
0x4c20b5  50                                push   eax
0x4c20b6  e8e5affeff                        call   0x4ad0a0
0x4c20bb  b9840ffc00                        mov    ecx,0xfc0f84
0x4c20c0  e8eb7cfeff                        call   0x4a9db0
0x4c20c5  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x4c20c8  6a1c                              push   0x1c
0x4c20ca  89b978bd0000                      mov    DWORD PTR [ecx+0xbd78],edi
0x4c20d0  e893f13c00                        call   0x891268
0x4c20d5  83c404                            add    esp,0x4
0x4c20d8  3bc7                              cmp    eax,edi
0x4c20da  7411                              je     0x4c20ed
0x4c20dc  8938                              mov    DWORD PTR [eax],edi
0x4c20de  c6400801                          mov    BYTE PTR [eax+0x8],0x1
0x4c20e2  89780c                            mov    DWORD PTR [eax+0xc],edi
0x4c20e5  897810                            mov    DWORD PTR [eax+0x10],edi
0x4c20e8  897814                            mov    DWORD PTR [eax+0x14],edi
0x4c20eb  eb02                              jmp    0x4c20ef
0x4c20ed  33c0                              xor    eax,eax
0x4c20ef  50                                push   eax
0x4c20f0  8d55e8                            lea    edx,[ebp-0x18]
0x4c20f3  52                                push   edx
0x4c20f4  897de8                            mov    DWORD PTR [ebp-0x18],edi
0x4c20f7  897dec                            mov    DWORD PTR [ebp-0x14],edi
0x4c20fa  e8d19ffbff                        call   0x47c0d0
0x4c20ff  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x4c2106  8b5de8                            mov    ebx,DWORD PTR [ebp-0x18]
0x4c2109  83ec08                            sub    esp,0x8
0x4c210c  c6430801                          mov    BYTE PTR [ebx+0x8],0x1
0x4c2110  8bf4                              mov    esi,esp
0x4c2112  c7430403000000                    mov    DWORD PTR [ebx+0x4],0x3
0x4c2119  893e                              mov    DWORD PTR [esi],edi
0x4c211b  897e04                            mov    DWORD PTR [esi+0x4],edi
0x4c211e  8b7dec                            mov    edi,DWORD PTR [ebp-0x14]
0x4c2121  896508                            mov    DWORD PTR [ebp+0x8],esp
0x4c2124  85ff                              test   edi,edi
0x4c2126  7412                              je     0x4c213a
0x4c2128  8bd7                              mov    edx,edi
0x4c212a  e821a1fbff                        call   0x47c250
0x4c212f  84c0                              test   al,al
0x4c2131  7407                              je     0x4c213a
0x4c2133  57                                push   edi
0x4c2134  53                                push   ebx
0x4c2135  e886102e00                        call   0x7a31c0
0x4c213a  b302                              mov    bl,0x2
0x4c213c  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x4c213f  f605600ffc0001                    test   BYTE PTR ds:0xfc0f60,0x1
0x4c2146  7520                              jne    0x4c2168
0x4c2148  830d600ffc0001                    or     DWORD PTR ds:0xfc0f60,0x1
0x4c214f  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0x4c2153  e8e8ad2d00                        call   0x79cf40
0x4c2158  6880dbbc00                        push   0xbcdb80
0x4c215d  e8b8013d00                        call   0x89231a
0x4c2162  83c404                            add    esp,0x4
0x4c2165  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x4c2168  b9900efc00                        mov    ecx,0xfc0e90
0x4c216d  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x4c2171  e86abb2d00                        call   0x79dce0
0x4c2176  8bf0                              mov    esi,eax
0x4c2178  6aff                              push   0xffffffff
0x4c217a  56                                push   esi
0x4c217b  ff15fc20bd00                      call   DWORD PTR ds:0xbd20fc
0x4c2181  56                                push   esi
0x4c2182  ff15c821bd00                      call   DWORD PTR ds:0xbd21c8
0x4c2188  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c218f  85ff                              test   edi,edi
0x4c2191  7429                              je     0x4c21bc
0x4c2193  8d4704                            lea    eax,[edi+0x4]
0x4c2196  83c9ff                            or     ecx,0xffffffff
0x4c2199  f00fc108                          lock xadd DWORD PTR [eax],ecx
0x4c219d  751d                              jne    0x4c21bc
0x4c219f  8b17                              mov    edx,DWORD PTR [edi]
0x4c21a1  8b02                              mov    eax,DWORD PTR [edx]
0x4c21a3  8bcf                              mov    ecx,edi
0x4c21a5  ffd0                              call   eax
0x4c21a7  8d4f08                            lea    ecx,[edi+0x8]
0x4c21aa  83caff                            or     edx,0xffffffff
0x4c21ad  f00fc111                          lock xadd DWORD PTR [ecx],edx
0x4c21b1  7509                              jne    0x4c21bc
0x4c21b3  8b07                              mov    eax,DWORD PTR [edi]
0x4c21b5  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x4c21b8  8bcf                              mov    ecx,edi
0x4c21ba  ffd2                              call   edx
0x4c21bc  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4c21bf  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c21c6  59                                pop    ecx
0x4c21c7  5f                                pop    edi
0x4c21c8  5e                                pop    esi
0x4c21c9  5b                                pop    ebx
0x4c21ca  8be5                              mov    esp,ebp
0x4c21cc  5d                                pop    ebp
0x4c21cd  c20400                            ret    0x4

### R15 重驗：Expedition UI start tag and currentfield gates
VA 0x5a64b0 RAW 0x1a58b0 END 0x5a6505 SHA256 f00fdd16a56638b7a345e8b942e9d3e46eac465b596e962a114935fd792d232d
0x5a64b0  b801000000                        mov    eax,0x1
0x5a64b5  8405f42cfd00                      test   BYTE PTR ds:0xfd2cf4,al
0x5a64bb  752c                              jne    0x5a64e9
0x5a64bd  0905f42cfd00                      or     DWORD PTR ds:0xfd2cf4,eax
0x5a64c3  c705f82cfd00b46ec000              mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
0x5a64cd  c705a48bfd0000000000              mov    DWORD PTR ds:0xfd8ba4,0x0
0x5a64d7  e8e418f1ff                        call   0x4b7dc0
0x5a64dc  68f0dcbc00                        push   0xbcdcf0
0x5a64e1  e834be2e00                        call   0x89231a
0x5a64e6  83c404                            add    esp,0x4
0x5a64e9  813d74a6d60044505845              cmp    DWORD PTR ds:0xd6a674,0x45585044
0x5a64f3  750f                              jne    0x5a6504
0x5a64f5  a1a48bfd00                        mov    eax,ds:0xfd8ba4
0x5a64fa  85c0                              test   eax,eax
0x5a64fc  7406                              je     0x5a6504
0x5a64fe  50                                push   eax
0x5a64ff  e80cb9f1ff                        call   0x4c1e10
0x5a6504  c3                                ret

### R16 Expedition destructor native map only
VA 0x4c1530 RAW 0xc0930 END 0x4c15b9 SHA256 2ac67f44af8ce5dbba861b931be53e448a50a117a5144237e9ebc97ca23af948
0x4c1530  55                                push   ebp
0x4c1531  8bec                              mov    ebp,esp
0x4c1533  6aff                              push   0xffffffff
0x4c1535  6850b59000                        push   0x90b550
0x4c153a  64a100000000                      mov    eax,fs:0x0
0x4c1540  50                                push   eax
0x4c1541  83ec0c                            sub    esp,0xc
0x4c1544  53                                push   ebx
0x4c1545  56                                push   esi
0x4c1546  57                                push   edi
0x4c1547  a1201fd600                        mov    eax,ds:0xd61f20
0x4c154c  33c5                              xor    eax,ebp
0x4c154e  50                                push   eax
0x4c154f  8d45f4                            lea    eax,[ebp-0xc]
0x4c1552  64a300000000                      mov    fs:0x0,eax
0x4c1558  8bd9                              mov    ebx,ecx
0x4c155a  895df0                            mov    DWORD PTR [ebp-0x10],ebx
0x4c155d  8dbb7cbd0000                      lea    edi,[ebx+0xbd7c]
0x4c1563  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x4c156a  897dec                            mov    DWORD PTR [ebp-0x14],edi
0x4c156d  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x4c1571  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x4c1574  8b08                              mov    ecx,DWORD PTR [eax]
0x4c1576  50                                push   eax
0x4c1577  51                                push   ecx
0x4c1578  8d75e8                            lea    esi,[ebp-0x18]
0x4c157b  8bc7                              mov    eax,edi
0x4c157d  e83e2b0900                        call   0x5540c0
0x4c1582  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x4c1585  50                                push   eax
0x4c1586  e881fc3c00                        call   0x89120c
0x4c158b  83c404                            add    esp,0x4
0x4c158e  f6450801                          test   BYTE PTR [ebp+0x8],0x1
0x4c1592  c703385bc000                      mov    DWORD PTR [ebx],0xc05b38
0x4c1598  7409                              je     0x4c15a3
0x4c159a  53                                push   ebx
0x4c159b  e86cfc3c00                        call   0x89120c
0x4c15a0  83c404                            add    esp,0x4
0x4c15a3  8bc3                              mov    eax,ebx
0x4c15a5  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x4c15a8  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x4c15af  59                                pop    ecx
0x4c15b0  5f                                pop    edi
0x4c15b1  5e                                pop    esi
0x4c15b2  5b                                pop    ebx
0x4c15b3  8be5                              mov    esp,ebp
0x4c15b5  5d                                pop    ebp
0x4c15b6  c20400                            ret    0x4

### R17 Empty field exit target
VA 0x8dc2f0 RAW 0x4db6f0 END 0x8dc2f3 SHA256 4bc724f3b1d0caf4fe369c18cba3102e6c4ea057f63fe1587e3973134a7f755e
0x8dc2f0  33c0                              xor    eax,eax
0x8dc2f2  c3                                ret

### R18 Full-range tree clear selects823850
VA 0x5540c0 RAW 0x1534c0 END 0x55415c SHA256 2e660183b91d98cd00fa71fad33e756a9a4ac930ac26c8afb75e13efc6252040
0x5540c0  55                                push   ebp
0x5540c1  8bec                              mov    ebp,esp
0x5540c3  51                                push   ecx
0x5540c4  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x5540c7  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x5540ca  57                                push   edi
0x5540cb  8bf8                              mov    edi,eax
0x5540cd  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x5540d0  3b08                              cmp    ecx,DWORD PTR [eax]
0x5540d2  7519                              jne    0x5540ed
0x5540d4  3bd0                              cmp    edx,eax
0x5540d6  7515                              jne    0x5540ed
0x5540d8  e873f72c00                        call   0x823850
0x5540dd  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x5540e0  8b08                              mov    ecx,DWORD PTR [eax]
0x5540e2  8bc6                              mov    eax,esi
0x5540e4  890e                              mov    DWORD PTR [esi],ecx
0x5540e6  5f                                pop    edi
0x5540e7  8be5                              mov    esp,ebp
0x5540e9  5d                                pop    ebp
0x5540ea  c20800                            ret    0x8
0x5540ed  3bca                              cmp    ecx,edx
0x5540ef  7460                              je     0x554151
0x5540f1  80791500                          cmp    BYTE PTR [ecx+0x15],0x0
0x5540f5  8bd1                              mov    edx,ecx
0x5540f7  7545                              jne    0x55413e
0x5540f9  8b4108                            mov    eax,DWORD PTR [ecx+0x8]
0x5540fc  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x554100  751d                              jne    0x55411f
0x554102  8bc8                              mov    ecx,eax
0x554104  8b01                              mov    eax,DWORD PTR [ecx]
0x554106  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x55410a  750e                              jne    0x55411a
0x55410c  8d642400                          lea    esp,[esp+0x0]
0x554110  8bc8                              mov    ecx,eax
0x554112  8b01                              mov    eax,DWORD PTR [ecx]
0x554114  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x554118  74f6                              je     0x554110
0x55411a  894d08                            mov    DWORD PTR [ebp+0x8],ecx
0x55411d  eb1f                              jmp    0x55413e
0x55411f  8b4104                            mov    eax,DWORD PTR [ecx+0x4]
0x554122  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x554126  7513                              jne    0x55413b
0x554128  3b4808                            cmp    ecx,DWORD PTR [eax+0x8]
0x55412b  750e                              jne    0x55413b
0x55412d  8bc8                              mov    ecx,eax
0x55412f  894d08                            mov    DWORD PTR [ebp+0x8],ecx
0x554132  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x554135  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x554139  74ed                              je     0x554128
0x55413b  894508                            mov    DWORD PTR [ebp+0x8],eax
0x55413e  52                                push   edx
0x55413f  8d55fc                            lea    edx,[ebp-0x4]
0x554142  52                                push   edx
0x554143  57                                push   edi
0x554144  e847272600                        call   0x7b6890
0x554149  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x55414c  3b4d0c                            cmp    ecx,DWORD PTR [ebp+0xc]
0x55414f  75a0                              jne    0x5540f1
0x554151  8bc6                              mov    eax,esi
0x554153  890e                              mov    DWORD PTR [esi],ecx
0x554155  5f                                pop    edi
0x554156  8be5                              mov    esp,ebp
0x554158  5d                                pop    ebp
0x554159  c20800                            ret    0x8

### R19 Tree clear node disposal and sentinel reset
VA 0x823850 RAW 0x422c50 END 0x823899 SHA256 e6c34542ace750d3a671b99b77fbf5367cdaaf2fabade389afd63ff8675556dd
0x823850  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x823853  53                                push   ebx
0x823854  8b5804                            mov    ebx,DWORD PTR [eax+0x4]
0x823857  807b1500                          cmp    BYTE PTR [ebx+0x15],0x0
0x82385b  56                                push   esi
0x82385c  8bf3                              mov    esi,ebx
0x82385e  751e                              jne    0x82387e
0x823860  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
0x823863  51                                push   ecx
0x823864  8bcf                              mov    ecx,edi
0x823866  e835b3f1ff                        call   0x73eba0
0x82386b  8b36                              mov    esi,DWORD PTR [esi]
0x82386d  53                                push   ebx
0x82386e  e899d90600                        call   0x89120c
0x823873  83c404                            add    esp,0x4
0x823876  807e1500                          cmp    BYTE PTR [esi+0x15],0x0
0x82387a  8bde                              mov    ebx,esi
0x82387c  74e2                              je     0x823860
0x82387e  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x823881  894004                            mov    DWORD PTR [eax+0x4],eax
0x823884  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x823887  8900                              mov    DWORD PTR [eax],eax
0x823889  8b4704                            mov    eax,DWORD PTR [edi+0x4]
0x82388c  5e                                pop    esi
0x82388d  894008                            mov    DWORD PTR [eax+0x8],eax
0x823890  c7470800000000                    mov    DWORD PTR [edi+0x8],0x0
0x823897  5b                                pop    ebx
0x823898  c3                                ret

### R20 Tree recursive disposal calls free, no payload callback
VA 0x73eba0 RAW 0x33dfa0 END 0x73ebd8 SHA256 3211dfcfd8af83ce282a49a13e89278e6ceec7f9981bdaae96aaea12dc7e5296
0x73eba0  55                                push   ebp
0x73eba1  8bec                              mov    ebp,esp
0x73eba3  53                                push   ebx
0x73eba4  56                                push   esi
0x73eba5  57                                push   edi
0x73eba6  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x73eba9  807f1500                          cmp    BYTE PTR [edi+0x15],0x0
0x73ebad  8bd9                              mov    ebx,ecx
0x73ebaf  8bf7                              mov    esi,edi
0x73ebb1  751e                              jne    0x73ebd1
0x73ebb3  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x73ebb6  50                                push   eax
0x73ebb7  8bcb                              mov    ecx,ebx
0x73ebb9  e8e2ffffff                        call   0x73eba0
0x73ebbe  8b36                              mov    esi,DWORD PTR [esi]
0x73ebc0  57                                push   edi
0x73ebc1  e846261500                        call   0x89120c
0x73ebc6  83c404                            add    esp,0x4
0x73ebc9  807e1500                          cmp    BYTE PTR [esi+0x15],0x0
0x73ebcd  8bfe                              mov    edi,esi
0x73ebcf  74e2                              je     0x73ebb3
0x73ebd1  5f                                pop    edi
0x73ebd2  5e                                pop    esi
0x73ebd3  5b                                pop    ebx
0x73ebd4  5d                                pop    ebp
0x73ebd5  c20400                            ret    0x4

### R21 Review quest60001 and inactive gate; other quests useQ
VA 0x47b5c0 RAW 0x7a9c0 END 0x47b6ac SHA256 8b78ccce5ac611587162a487e9c98c5c6c2b95a983e6ef19c52225642f2d4b0c
0x47b5c0  55                                push   ebp
0x47b5c1  8bec                              mov    ebp,esp
0x47b5c3  83e4f8                            and    esp,0xfffffff8
0x47b5c6  6aff                              push   0xffffffff
0x47b5c8  687c109400                        push   0x94107c
0x47b5cd  64a100000000                      mov    eax,fs:0x0
0x47b5d3  50                                push   eax
0x47b5d4  51                                push   ecx
0x47b5d5  56                                push   esi
0x47b5d6  57                                push   edi
0x47b5d7  a1201fd600                        mov    eax,ds:0xd61f20
0x47b5dc  33c4                              xor    eax,esp
0x47b5de  50                                push   eax
0x47b5df  8d442410                          lea    eax,[esp+0x10]
0x47b5e3  64a300000000                      mov    fs:0x0,eax
0x47b5e9  8bf9                              mov    edi,ecx
0x47b5eb  81bf4802000061ea0000              cmp    DWORD PTR [edi+0x248],0xea61
0x47b5f5  7511                              jne    0x47b608
0x47b5f7  80bf6c02000000                    cmp    BYTE PTR [edi+0x26c],0x0
0x47b5fe  754f                              jne    0x47b64f
0x47b600  57                                push   edi
0x47b601  e84a020000                        call   0x47b850
0x47b606  eb47                              jmp    0x47b64f
0x47b608  f605b873fb0001                    test   BYTE PTR ds:0xfb73b8,0x1
0x47b60f  7529                              jne    0x47b63a
0x47b611  830db873fb0001                    or     DWORD PTR ds:0xfb73b8,0x1
0x47b618  c744241800000000                  mov    DWORD PTR [esp+0x18],0x0
0x47b620  e84b4b0e00                        call   0x560170
0x47b625  6810d1bc00                        push   0xbcd110
0x47b62a  e8eb6c4100                        call   0x89231a
0x47b62f  83c404                            add    esp,0x4
0x47b632  c7442418ffffffff                  mov    DWORD PTR [esp+0x18],0xffffffff
0x47b63a  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x47b63d  8b8f48020000                      mov    ecx,DWORD PTR [edi+0x248]
0x47b643  50                                push   eax
0x47b644  51                                push   ecx
0x47b645  bec073fb00                        mov    esi,0xfb73c0
0x47b64a  e8d1a00e00                        call   0x565720
0x47b64f  f605640ffc0001                    test   BYTE PTR ds:0xfc0f64,0x1
0x47b656  7529                              jne    0x47b681
0x47b658  b801000000                        mov    eax,0x1
0x47b65d  0905640ffc00                      or     DWORD PTR ds:0xfc0f64,eax
0x47b663  89442418                          mov    DWORD PTR [esp+0x18],eax
0x47b667  e874260000                        call   0x47dce0
0x47b66c  68f0dabc00                        push   0xbcdaf0
0x47b671  e8a46c4100                        call   0x89231a
0x47b676  83c404                            add    esp,0x4
0x47b679  c7442418ffffffff                  mov    DWORD PTR [esp+0x18],0xffffffff
0x47b681  8b974c020000                      mov    edx,DWORD PTR [edi+0x24c]
0x47b687  8b8f48020000                      mov    ecx,DWORD PTR [edi+0x248]
0x47b68d  52                                push   edx
0x47b68e  bf680ffc00                        mov    edi,0xfc0f68
0x47b693  e8b8300000                        call   0x47e750
0x47b698  8b4c2410                          mov    ecx,DWORD PTR [esp+0x10]
0x47b69c  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47b6a3  59                                pop    ecx
0x47b6a4  5f                                pop    edi
0x47b6a5  5e                                pop    esi
0x47b6a6  8be5                              mov    esp,ebp
0x47b6a8  5d                                pop    ebp
0x47b6a9  c20400                            ret    0x4

### R22 Review SceneItem+26C enable and Synopsis load
VA 0x47b850 RAW 0x7ac50 END 0x47bb3d SHA256 83c55030d175eb719cb732dc4a7a7aadc9cbcfb587c5c5dac836f038af47abb7
0x47b850  55                                push   ebp
0x47b851  8bec                              mov    ebp,esp
0x47b853  6aff                              push   0xffffffff
0x47b855  68e2a49300                        push   0x93a4e2
0x47b85a  64a100000000                      mov    eax,fs:0x0
0x47b860  50                                push   eax
0x47b861  83ec50                            sub    esp,0x50
0x47b864  53                                push   ebx
0x47b865  56                                push   esi
0x47b866  57                                push   edi
0x47b867  a1201fd600                        mov    eax,ds:0xd61f20
0x47b86c  33c5                              xor    eax,ebp
0x47b86e  50                                push   eax
0x47b86f  8d45f4                            lea    eax,[ebp-0xc]
0x47b872  64a300000000                      mov    fs:0x0,eax
0x47b878  f605400efc0001                    test   BYTE PTR ds:0xfc0e40,0x1
0x47b87f  7520                              jne    0x47b8a1
0x47b881  830d400efc0001                    or     DWORD PTR ds:0xfc0e40,0x1
0x47b888  33f6                              xor    esi,esi
0x47b88a  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x47b88d  e8de4e0c00                        call   0x540770
0x47b892  6860dbbc00                        push   0xbcdb60
0x47b897  e87e6a4100                        call   0x89231a
0x47b89c  83c404                            add    esp,0x4
0x47b89f  eb02                              jmp    0x47b8a3
0x47b8a1  33f6                              xor    esi,esi
0x47b8a3  8975a8                            mov    DWORD PTR [ebp-0x58],esi
0x47b8a6  8975ac                            mov    DWORD PTR [ebp-0x54],esi
0x47b8a9  8975b0                            mov    DWORD PTR [ebp-0x50],esi
0x47b8ac  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x47b8b3  8d45ec                            lea    eax,[ebp-0x14]
0x47b8b6  8d7da8                            lea    edi,[ebp-0x58]
0x47b8b9  c745ecf8030000                    mov    DWORD PTR [ebp-0x14],0x3f8
0x47b8c0  e8bbcd0200                        call   0x4a8680
0x47b8c5  8d45e8                            lea    eax,[ebp-0x18]
0x47b8c8  c745e8f9030000                    mov    DWORD PTR [ebp-0x18],0x3f9
0x47b8cf  e8accd0200                        call   0x4a8680
0x47b8d4  8d45e4                            lea    eax,[ebp-0x1c]
0x47b8d7  c745e414270000                    mov    DWORD PTR [ebp-0x1c],0x2714
0x47b8de  e89dcd0200                        call   0x4a8680
0x47b8e3  8d45e0                            lea    eax,[ebp-0x20]
0x47b8e6  c745e015270000                    mov    DWORD PTR [ebp-0x20],0x2715
0x47b8ed  e88ecd0200                        call   0x4a8680
0x47b8f2  8d45dc                            lea    eax,[ebp-0x24]
0x47b8f5  c745dc16270000                    mov    DWORD PTR [ebp-0x24],0x2716
0x47b8fc  e87fcd0200                        call   0x4a8680
0x47b901  8d45d8                            lea    eax,[ebp-0x28]
0x47b904  c745d817270000                    mov    DWORD PTR [ebp-0x28],0x2717
0x47b90b  e870cd0200                        call   0x4a8680
0x47b910  8d45d4                            lea    eax,[ebp-0x2c]
0x47b913  c745d438270000                    mov    DWORD PTR [ebp-0x2c],0x2738
0x47b91a  e861cd0200                        call   0x4a8680
0x47b91f  8d45d0                            lea    eax,[ebp-0x30]
0x47b922  c745d044270000                    mov    DWORD PTR [ebp-0x30],0x2744
0x47b929  e852cd0200                        call   0x4a8680
0x47b92e  8d45cc                            lea    eax,[ebp-0x34]
0x47b931  c745cc45270000                    mov    DWORD PTR [ebp-0x34],0x2745
0x47b938  e843cd0200                        call   0x4a8680
0x47b93d  8d45c8                            lea    eax,[ebp-0x38]
0x47b940  c745c82b4e0000                    mov    DWORD PTR [ebp-0x38],0x4e2b
0x47b947  e834cd0200                        call   0x4a8680
0x47b94c  8d45c4                            lea    eax,[ebp-0x3c]
0x47b94f  c745c4314e0000                    mov    DWORD PTR [ebp-0x3c],0x4e31
0x47b956  e825cd0200                        call   0x4a8680
0x47b95b  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x47b95e  6a1c                              push   0x1c
0x47b960  c6806c02000001                    mov    BYTE PTR [eax+0x26c],0x1
0x47b967  e8fc584100                        call   0x891268
0x47b96c  83c404                            add    esp,0x4
0x47b96f  3bc6                              cmp    eax,esi
0x47b971  7411                              je     0x47b984
0x47b973  8930                              mov    DWORD PTR [eax],esi
0x47b975  c6400801                          mov    BYTE PTR [eax+0x8],0x1
0x47b979  89700c                            mov    DWORD PTR [eax+0xc],esi
0x47b97c  897010                            mov    DWORD PTR [eax+0x10],esi
0x47b97f  897014                            mov    DWORD PTR [eax+0x14],esi
0x47b982  eb02                              jmp    0x47b986
0x47b984  33c0                              xor    eax,eax
0x47b986  50                                push   eax
0x47b987  8d4db8                            lea    ecx,[ebp-0x48]
0x47b98a  51                                push   ecx
0x47b98b  8975b8                            mov    DWORD PTR [ebp-0x48],esi
0x47b98e  8975bc                            mov    DWORD PTR [ebp-0x44],esi
0x47b991  e83a070000                        call   0x47c0d0
0x47b996  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x47b99a  8b45b8                            mov    eax,DWORD PTR [ebp-0x48]
0x47b99d  8b5da8                            mov    ebx,DWORD PTR [ebp-0x58]
0x47b9a0  c6400801                          mov    BYTE PTR [eax+0x8],0x1
0x47b9a4  c7400403000000                    mov    DWORD PTR [eax+0x4],0x3
0x47b9ab  3b5dac                            cmp    ebx,DWORD PTR [ebp-0x54]
0x47b9ae  7464                              je     0x47ba14
0x47b9b0  8d700c                            lea    esi,[eax+0xc]
0x47b9b3  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x47b9b6  3bd8                              cmp    ebx,eax
0x47b9b8  7330                              jae    0x47b9ea
0x47b9ba  8b0e                              mov    ecx,DWORD PTR [esi]
0x47b9bc  3bcb                              cmp    ecx,ebx
0x47b9be  772a                              ja     0x47b9ea
0x47b9c0  8bfb                              mov    edi,ebx
0x47b9c2  2bf9                              sub    edi,ecx
0x47b9c4  c1ff02                            sar    edi,0x2
0x47b9c7  3b4608                            cmp    eax,DWORD PTR [esi+0x8]
0x47b9ca  750c                              jne    0x47b9d8
0x47b9cc  b901000000                        mov    ecx,0x1
0x47b9d1  8bc6                              mov    eax,esi
0x47b9d3  e868a82500                        call   0x6d6240
0x47b9d8  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x47b9db  8b16                              mov    edx,DWORD PTR [esi]
0x47b9dd  8d0cba                            lea    ecx,[edx+edi*4]
0x47b9e0  85c0                              test   eax,eax
0x47b9e2  7422                              je     0x47ba06
0x47b9e4  8b09                              mov    ecx,DWORD PTR [ecx]
0x47b9e6  8908                              mov    DWORD PTR [eax],ecx
0x47b9e8  eb1c                              jmp    0x47ba06
0x47b9ea  3b4608                            cmp    eax,DWORD PTR [esi+0x8]
0x47b9ed  750c                              jne    0x47b9fb
0x47b9ef  b901000000                        mov    ecx,0x1
0x47b9f4  8bc6                              mov    eax,esi
0x47b9f6  e845a82500                        call   0x6d6240
0x47b9fb  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x47b9fe  85c0                              test   eax,eax
0x47ba00  7404                              je     0x47ba06
0x47ba02  8b13                              mov    edx,DWORD PTR [ebx]
0x47ba04  8910                              mov    DWORD PTR [eax],edx
0x47ba06  83460404                          add    DWORD PTR [esi+0x4],0x4
0x47ba0a  83c304                            add    ebx,0x4
0x47ba0d  3b5dac                            cmp    ebx,DWORD PTR [ebp-0x54]
0x47ba10  75a1                              jne    0x47b9b3
0x47ba12  33f6                              xor    esi,esi
0x47ba14  8b7dbc                            mov    edi,DWORD PTR [ebp-0x44]
0x47ba17  83ec08                            sub    esp,0x8
0x47ba1a  8bc4                              mov    eax,esp
0x47ba1c  8965c0                            mov    DWORD PTR [ebp-0x40],esp
0x47ba1f  894508                            mov    DWORD PTR [ebp+0x8],eax
0x47ba22  8930                              mov    DWORD PTR [eax],esi
0x47ba24  897004                            mov    DWORD PTR [eax+0x4],esi
0x47ba27  3bfe                              cmp    edi,esi
0x47ba29  7426                              je     0x47ba51
0x47ba2b  8b4f04                            mov    ecx,DWORD PTR [edi+0x4]
0x47ba2e  8d5704                            lea    edx,[edi+0x4]
0x47ba31  3bce                              cmp    ecx,esi
0x47ba33  7419                              je     0x47ba4e
0x47ba35  8d7901                            lea    edi,[ecx+0x1]
0x47ba38  8bda                              mov    ebx,edx
0x47ba3a  8bc1                              mov    eax,ecx
0x47ba3c  f00fb13b                          lock cmpxchg DWORD PTR [ebx],edi
0x47ba40  3bc1                              cmp    eax,ecx
0x47ba42  0f84e0000000                      je     0x47bb28
0x47ba48  8b0a                              mov    ecx,DWORD PTR [edx]
0x47ba4a  3bce                              cmp    ecx,esi
0x47ba4c  75e7                              jne    0x47ba35
0x47ba4e  8b7dbc                            mov    edi,DWORD PTR [ebp-0x44]
0x47ba51  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0x47ba55  f605600ffc0001                    test   BYTE PTR ds:0xfc0f60,0x1
0x47ba5c  7521                              jne    0x47ba7f
0x47ba5e  830d600ffc0001                    or     DWORD PTR ds:0xfc0f60,0x1
0x47ba65  c645fc04                          mov    BYTE PTR [ebp-0x4],0x4
0x47ba69  e8d2143200                        call   0x79cf40
0x47ba6e  6880dbbc00                        push   0xbcdb80
0x47ba73  e8a2684100                        call   0x89231a
0x47ba78  83c404                            add    esp,0x4
0x47ba7b  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0x47ba7f  b9900efc00                        mov    ecx,0xfc0e90
0x47ba84  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x47ba88  e853223200                        call   0x79dce0
0x47ba8d  8bf0                              mov    esi,eax
0x47ba8f  6aff                              push   0xffffffff
0x47ba91  56                                push   esi
0x47ba92  ff15fc20bd00                      call   DWORD PTR ds:0xbd20fc
0x47ba98  56                                push   esi
0x47ba99  ff15c821bd00                      call   DWORD PTR ds:0xbd21c8
0x47ba9f  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x47baa6  7521                              jne    0x47bac9
0x47baa8  830d800ffc0001                    or     DWORD PTR ds:0xfc0f80,0x1
0x47baaf  c645fc05                          mov    BYTE PTR [ebp-0x4],0x5
0x47bab3  e8f8f3ffff                        call   0x47aeb0
0x47bab8  6870dbbc00                        push   0xbcdb70
0x47babd  e858684100                        call   0x89231a
0x47bac2  83c404                            add    esp,0x4
0x47bac5  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x47bac9  be840ffc00                        mov    esi,0xfc0f84
0x47bace  e8edce0200                        call   0x4a89c0
0x47bad3  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x47bad7  85ff                              test   edi,edi
0x47bad9  7429                              je     0x47bb04
0x47badb  8d5704                            lea    edx,[edi+0x4]
0x47bade  83c8ff                            or     eax,0xffffffff
0x47bae1  f00fc102                          lock xadd DWORD PTR [edx],eax
0x47bae5  751d                              jne    0x47bb04
0x47bae7  8b17                              mov    edx,DWORD PTR [edi]
0x47bae9  8b02                              mov    eax,DWORD PTR [edx]
0x47baeb  8bcf                              mov    ecx,edi
0x47baed  ffd0                              call   eax
0x47baef  8d4f08                            lea    ecx,[edi+0x8]
0x47baf2  83caff                            or     edx,0xffffffff
0x47baf5  f00fc111                          lock xadd DWORD PTR [ecx],edx
0x47baf9  7509                              jne    0x47bb04
0x47bafb  8b07                              mov    eax,DWORD PTR [edi]
0x47bafd  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x47bb00  8bcf                              mov    ecx,edi
0x47bb02  ffd2                              call   edx
0x47bb04  8b45a8                            mov    eax,DWORD PTR [ebp-0x58]
0x47bb07  85c0                              test   eax,eax
0x47bb09  7409                              je     0x47bb14
0x47bb0b  50                                push   eax
0x47bb0c  e8fb564100                        call   0x89120c
0x47bb11  83c404                            add    esp,0x4
0x47bb14  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47bb17  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47bb1e  59                                pop    ecx
0x47bb1f  5f                                pop    edi
0x47bb20  5e                                pop    esi
0x47bb21  5b                                pop    ebx
0x47bb22  8be5                              mov    esp,ebp
0x47bb24  5d                                pop    ebp
0x47bb25  c20400                            ret    0x4
0x47bb28  8b7dbc                            mov    edi,DWORD PTR [ebp-0x44]
0x47bb2b  8b4db8                            mov    ecx,DWORD PTR [ebp-0x48]
0x47bb2e  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x47bb31  57                                push   edi
0x47bb32  51                                push   ecx
0x47bb33  e888763200                        call   0x7a31c0
0x47bb38  e914ffffff                        jmp    0x47ba51

### R23 Review tco removal, tracking clear, +26C=0
VA 0x47b6b0 RAW 0x7aab0 END 0x47b844 SHA256 ab6ad5a55da819502496526e543ec487cede0b16c4a28de19136d8cb848c1a43
0x47b6b0  55                                push   ebp
0x47b6b1  8bec                              mov    ebp,esp
0x47b6b3  83e4f8                            and    esp,0xfffffff8
0x47b6b6  6aff                              push   0xffffffff
0x47b6b8  685c8f9300                        push   0x938f5c
0x47b6bd  64a100000000                      mov    eax,fs:0x0
0x47b6c3  50                                push   eax
0x47b6c4  83ec10                            sub    esp,0x10
0x47b6c7  53                                push   ebx
0x47b6c8  56                                push   esi
0x47b6c9  57                                push   edi
0x47b6ca  a1201fd600                        mov    eax,ds:0xd61f20
0x47b6cf  33c4                              xor    eax,esp
0x47b6d1  50                                push   eax
0x47b6d2  8d442420                          lea    eax,[esp+0x20]
0x47b6d6  64a300000000                      mov    fs:0x0,eax
0x47b6dc  f605800ffc0001                    test   BYTE PTR ds:0xfc0f80,0x1
0x47b6e3  7529                              jne    0x47b70e
0x47b6e5  830d800ffc0001                    or     DWORD PTR ds:0xfc0f80,0x1
0x47b6ec  33ff                              xor    edi,edi
0x47b6ee  897c2428                          mov    DWORD PTR [esp+0x28],edi
0x47b6f2  e8b9f7ffff                        call   0x47aeb0
0x47b6f7  6870dbbc00                        push   0xbcdb70
0x47b6fc  e8196c4100                        call   0x89231a
0x47b701  83c404                            add    esp,0x4
0x47b704  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x47b70c  eb02                              jmp    0x47b710
0x47b70e  33ff                              xor    edi,edi
0x47b710  a1840ffc00                        mov    eax,ds:0xfc0f84
0x47b715  68bc68c000                        push   0xc068bc
0x47b71a  57                                push   edi
0x47b71b  50                                push   eax
0x47b71c  e87f190300                        call   0x4ad0a0
0x47b721  b9840ffc00                        mov    ecx,0xfc0f84
0x47b726  e885e60200                        call   0x4a9db0
0x47b72b  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x47b72e  6a1c                              push   0x1c
0x47b730  c6816c02000000                    mov    BYTE PTR [ecx+0x26c],0x0
0x47b737  e82c5b4100                        call   0x891268
0x47b73c  83c404                            add    esp,0x4
0x47b73f  3bc7                              cmp    eax,edi
0x47b741  7411                              je     0x47b754
0x47b743  8938                              mov    DWORD PTR [eax],edi
0x47b745  c6400801                          mov    BYTE PTR [eax+0x8],0x1
0x47b749  89780c                            mov    DWORD PTR [eax+0xc],edi
0x47b74c  897810                            mov    DWORD PTR [eax+0x10],edi
0x47b74f  897814                            mov    DWORD PTR [eax+0x14],edi
0x47b752  eb02                              jmp    0x47b756
0x47b754  33c0                              xor    eax,eax
0x47b756  50                                push   eax
0x47b757  8d542418                          lea    edx,[esp+0x18]
0x47b75b  52                                push   edx
0x47b75c  897c241c                          mov    DWORD PTR [esp+0x1c],edi
0x47b760  897c2420                          mov    DWORD PTR [esp+0x20],edi
0x47b764  e867090000                        call   0x47c0d0
0x47b769  c744242801000000                  mov    DWORD PTR [esp+0x28],0x1
0x47b771  8b5c2414                          mov    ebx,DWORD PTR [esp+0x14]
0x47b775  83ec08                            sub    esp,0x8
0x47b778  c6430801                          mov    BYTE PTR [ebx+0x8],0x1
0x47b77c  8bf4                              mov    esi,esp
0x47b77e  c7430403000000                    mov    DWORD PTR [ebx+0x4],0x3
0x47b785  893e                              mov    DWORD PTR [esi],edi
0x47b787  897e04                            mov    DWORD PTR [esi+0x4],edi
0x47b78a  8b7c2420                          mov    edi,DWORD PTR [esp+0x20]
0x47b78e  89642418                          mov    DWORD PTR [esp+0x18],esp
0x47b792  85ff                              test   edi,edi
0x47b794  7412                              je     0x47b7a8
0x47b796  8bd7                              mov    edx,edi
0x47b798  e8b30a0000                        call   0x47c250
0x47b79d  84c0                              test   al,al
0x47b79f  7407                              je     0x47b7a8
0x47b7a1  57                                push   edi
0x47b7a2  53                                push   ebx
0x47b7a3  e8187a3200                        call   0x7a31c0
0x47b7a8  b302                              mov    bl,0x2
0x47b7aa  885c2430                          mov    BYTE PTR [esp+0x30],bl
0x47b7ae  f605600ffc0001                    test   BYTE PTR ds:0xfc0f60,0x1
0x47b7b5  7522                              jne    0x47b7d9
0x47b7b7  830d600ffc0001                    or     DWORD PTR ds:0xfc0f60,0x1
0x47b7be  c644243003                        mov    BYTE PTR [esp+0x30],0x3
0x47b7c3  e878173200                        call   0x79cf40
0x47b7c8  6880dbbc00                        push   0xbcdb80
0x47b7cd  e8486b4100                        call   0x89231a
0x47b7d2  83c404                            add    esp,0x4
0x47b7d5  885c2430                          mov    BYTE PTR [esp+0x30],bl
0x47b7d9  b9900efc00                        mov    ecx,0xfc0e90
0x47b7de  c644243001                        mov    BYTE PTR [esp+0x30],0x1
0x47b7e3  e8f8243200                        call   0x79dce0
0x47b7e8  8bf0                              mov    esi,eax
0x47b7ea  6aff                              push   0xffffffff
0x47b7ec  56                                push   esi
0x47b7ed  ff15fc20bd00                      call   DWORD PTR ds:0xbd20fc
0x47b7f3  56                                push   esi
0x47b7f4  ff15c821bd00                      call   DWORD PTR ds:0xbd21c8
0x47b7fa  c7442428ffffffff                  mov    DWORD PTR [esp+0x28],0xffffffff
0x47b802  85ff                              test   edi,edi
0x47b804  7429                              je     0x47b82f
0x47b806  8d4704                            lea    eax,[edi+0x4]
0x47b809  83c9ff                            or     ecx,0xffffffff
0x47b80c  f00fc108                          lock xadd DWORD PTR [eax],ecx
0x47b810  751d                              jne    0x47b82f
0x47b812  8b17                              mov    edx,DWORD PTR [edi]
0x47b814  8b02                              mov    eax,DWORD PTR [edx]
0x47b816  8bcf                              mov    ecx,edi
0x47b818  ffd0                              call   eax
0x47b81a  8d4f08                            lea    ecx,[edi+0x8]
0x47b81d  83caff                            or     edx,0xffffffff
0x47b820  f00fc111                          lock xadd DWORD PTR [ecx],edx
0x47b824  7509                              jne    0x47b82f
0x47b826  8b07                              mov    eax,DWORD PTR [edi]
0x47b828  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x47b82b  8bcf                              mov    ecx,edi
0x47b82d  ffd2                              call   edx
0x47b82f  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
0x47b833  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47b83a  59                                pop    ecx
0x47b83b  5f                                pop    edi
0x47b83c  5e                                pop    esi
0x47b83d  5b                                pop    ebx
0x47b83e  8be5                              mov    esp,ebp
0x47b840  5d                                pop    ebp
0x47b841  c20400                            ret    0x4

### R24 Review selected item chain, type guard, T tick/finish
VA 0x47c980 RAW 0x7bd80 END 0x47caab SHA256 96d0643a4ac5f4e1e37fefd32bbd1895061e1c411116929f7f0d1b3c4d310b97
0x47c980  55                                push   ebp
0x47c981  8bec                              mov    ebp,esp
0x47c983  6aff                              push   0xffffffff
0x47c985  687c989300                        push   0x93987c
0x47c98a  64a100000000                      mov    eax,fs:0x0
0x47c990  50                                push   eax
0x47c991  53                                push   ebx
0x47c992  56                                push   esi
0x47c993  a1201fd600                        mov    eax,ds:0xd61f20
0x47c998  33c5                              xor    eax,ebp
0x47c99a  50                                push   eax
0x47c99b  8d45f4                            lea    eax,[ebp-0xc]
0x47c99e  64a300000000                      mov    fs:0x0,eax
0x47c9a4  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x47c9a7  8b80fc000000                      mov    eax,DWORD PTR [eax+0xfc]
0x47c9ad  8b80cc000000                      mov    eax,DWORD PTR [eax+0xcc]
0x47c9b3  85c0                              test   eax,eax
0x47c9b5  0f84dd000000                      je     0x47ca98
0x47c9bb  8bb0dc000000                      mov    esi,DWORD PTR [eax+0xdc]
0x47c9c1  85f6                              test   esi,esi
0x47c9c3  0f84cf000000                      je     0x47ca98
0x47c9c9  8b16                              mov    edx,DWORD PTR [esi]
0x47c9cb  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x47c9ce  8bce                              mov    ecx,esi
0x47c9d0  ffd0                              call   eax
0x47c9d2  3d2d010000                        cmp    eax,0x12d
0x47c9d7  7427                              je     0x47ca00
0x47c9d9  6a00                              push   0x0
0x47c9db  68c01fbf00                        push   0xbf1fc0
0x47c9e0  681821bf00                        push   0xbf2118
0x47c9e5  6a00                              push   0x0
0x47c9e7  ff158025bd00                      call   DWORD PTR ds:0xbd2580
0x47c9ed  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47c9f0  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47c9f7  59                                pop    ecx
0x47c9f8  5e                                pop    esi
0x47c9f9  5b                                pop    ebx
0x47c9fa  8be5                              mov    esp,ebp
0x47c9fc  5d                                pop    ebp
0x47c9fd  c20400                            ret    0x4
0x47ca00  80be6c02000000                    cmp    BYTE PTR [esi+0x26c],0x0
0x47ca07  0f848b000000                      je     0x47ca98
0x47ca0d  bb01000000                        mov    ebx,0x1
0x47ca12  841d800ffc00                      test   BYTE PTR ds:0xfc0f80,bl
0x47ca18  7526                              jne    0x47ca40
0x47ca1a  091d800ffc00                      or     DWORD PTR ds:0xfc0f80,ebx
0x47ca20  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x47ca27  e884e4ffff                        call   0x47aeb0
0x47ca2c  6870dbbc00                        push   0xbcdb70
0x47ca31  e8e4584100                        call   0x89231a
0x47ca36  83c404                            add    esp,0x4
0x47ca39  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x47ca40  68840ffc00                        push   0xfc0f84
0x47ca45  e846c10200                        call   0x4a8b90
0x47ca4a  841d800ffc00                      test   BYTE PTR ds:0xfc0f80,bl
0x47ca50  7522                              jne    0x47ca74
0x47ca52  091d800ffc00                      or     DWORD PTR ds:0xfc0f80,ebx
0x47ca58  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x47ca5b  e850e4ffff                        call   0x47aeb0
0x47ca60  6870dbbc00                        push   0xbcdb70
0x47ca65  e8b0584100                        call   0x89231a
0x47ca6a  83c404                            add    esp,0x4
0x47ca6d  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x47ca74  833db80ffc0000                    cmp    DWORD PTR ds:0xfc0fb8,0x0
0x47ca7b  751b                              jne    0x47ca98
0x47ca7d  56                                push   esi
0x47ca7e  e82decffff                        call   0x47b6b0
0x47ca83  e8d825f9ff                        call   0x40f060
0x47ca88  8b4048                            mov    eax,DWORD PTR [eax+0x48]
0x47ca8b  50                                push   eax
0x47ca8c  e86ff8ffff                        call   0x47c300
0x47ca91  8bc8                              mov    ecx,eax
0x47ca93  e898c92500                        call   0x6d9430
0x47ca98  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47ca9b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47caa2  59                                pop    ecx
0x47caa3  5e                                pop    esi
0x47caa4  5b                                pop    ebx
0x47caa5  8be5                              mov    esp,ebp
0x47caa7  5d                                pop    ebp
0x47caa8  c20400                            ret    0x4

### R25 Review key close rejects active +26C; key2AF9
VA 0x47da00 RAW 0x7ce00 END 0x47da87 SHA256 d35c063b59d18044cc1bbe4ecfea1deb860a604c5350e0fe649f955371b85a6e
0x47da00  55                                push   ebp
0x47da01  8bec                              mov    ebp,esp
0x47da03  56                                push   esi
0x47da04  57                                push   edi
0x47da05  8bf9                              mov    edi,ecx
0x47da07  8b87fc000000                      mov    eax,DWORD PTR [edi+0xfc]
0x47da0d  8b80cc000000                      mov    eax,DWORD PTR [eax+0xcc]
0x47da13  85c0                              test   eax,eax
0x47da15  740a                              je     0x47da21
0x47da17  8bb0dc000000                      mov    esi,DWORD PTR [eax+0xdc]
0x47da1d  85f6                              test   esi,esi
0x47da1f  7504                              jne    0x47da25
0x47da21  33c0                              xor    eax,eax
0x47da23  eb1b                              jmp    0x47da40
0x47da25  8b06                              mov    eax,DWORD PTR [esi]
0x47da27  8b5004                            mov    edx,DWORD PTR [eax+0x4]
0x47da2a  8bce                              mov    ecx,esi
0x47da2c  ffd2                              call   edx
0x47da2e  3d2d010000                        cmp    eax,0x12d
0x47da33  7532                              jne    0x47da67
0x47da35  80be6c02000000                    cmp    BYTE PTR [esi+0x26c],0x0
0x47da3c  8bc6                              mov    eax,esi
0x47da3e  753f                              jne    0x47da7f
0x47da40  817d08f92a0000                    cmp    DWORD PTR [ebp+0x8],0x2af9
0x47da47  7536                              jne    0x47da7f
0x47da49  85c0                              test   eax,eax
0x47da4b  7406                              je     0x47da53
0x47da4d  50                                push   eax
0x47da4e  e85ddcffff                        call   0x47b6b0
0x47da53  8b07                              mov    eax,DWORD PTR [edi]
0x47da55  8b90d4000000                      mov    edx,DWORD PTR [eax+0xd4]
0x47da5b  8bcf                              mov    ecx,edi
0x47da5d  ffd2                              call   edx
0x47da5f  5f                                pop    edi
0x47da60  b001                              mov    al,0x1
0x47da62  5e                                pop    esi
0x47da63  5d                                pop    ebp
0x47da64  c20400                            ret    0x4
0x47da67  6a00                              push   0x0
0x47da69  68c01fbf00                        push   0xbf1fc0
0x47da6e  681821bf00                        push   0xbf2118
0x47da73  6a00                              push   0x0
0x47da75  ff158025bd00                      call   DWORD PTR ds:0xbd2580
0x47da7b  33c0                              xor    eax,eax
0x47da7d  ebc1                              jmp    0x47da40
0x47da7f  5f                                pop    edi
0x47da80  32c0                              xor    al,al
0x47da82  5e                                pop    esi
0x47da83  5d                                pop    ebp
0x47da84  c20400                            ret    0x4

### R26 Review show→base show→refresh data
VA 0x47cab0 RAW 0x7beb0 END 0x47caf4 SHA256 ea5ac46da5dd61dbea590998677b058ea3a428d6fc3511779355eda40c63e2dc
0x47cab0  56                                push   esi
0x47cab1  8bf1                              mov    esi,ecx
0x47cab3  e8088f2c00                        call   0x7459c0
0x47cab8  f6462810                          test   BYTE PTR [esi+0x28],0x10
0x47cabc  7404                              je     0x47cac2
0x47cabe  8bc6                              mov    eax,esi
0x47cac0  eb0c                              jmp    0x47cace
0x47cac2  8b4660                            mov    eax,DWORD PTR [esi+0x60]
0x47cac5  85c0                              test   eax,eax
0x47cac7  7423                              je     0x47caec
0x47cac9  e852912c00                        call   0x745c20
0x47cace  85c0                              test   eax,eax
0x47cad0  741a                              je     0x47caec
0x47cad2  57                                push   edi
0x47cad3  8b7860                            mov    edi,DWORD PTR [eax+0x60]
0x47cad6  85ff                              test   edi,edi
0x47cad8  7411                              je     0x47caeb
0x47cada  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x47cadd  c1e90c                            shr    ecx,0xc
0x47cae0  f6c101                            test   cl,0x1
0x47cae3  7506                              jne    0x47caeb
0x47cae5  50                                push   eax
0x47cae6  e825d52c00                        call   0x74a010
0x47caeb  5f                                pop    edi
0x47caec  56                                push   esi
0x47caed  e86efcffff                        call   0x47c760
0x47caf2  5e                                pop    esi
0x47caf3  c3                                ret

### R27 Review hide target postsF4350, no direct T removal
VA 0x4067f0 RAW 0x5bf0 END 0x40686e SHA256 a8aff652b6f5a8c1e13d7cdb90827760c575be3fe2034bd080f3b1e1a729399f
0x4067f0  56                                push   esi
0x4067f1  8bf1                              mov    esi,ecx
0x4067f3  e838f13300                        call   0x745930
0x4067f8  f6462810                          test   BYTE PTR [esi+0x28],0x10
0x4067fc  7404                              je     0x406802
0x4067fe  8bc6                              mov    eax,esi
0x406800  eb0c                              jmp    0x40680e
0x406802  8b4660                            mov    eax,DWORD PTR [esi+0x60]
0x406805  85c0                              test   eax,eax
0x406807  7423                              je     0x40682c
0x406809  e812f43300                        call   0x745c20
0x40680e  85c0                              test   eax,eax
0x406810  741a                              je     0x40682c
0x406812  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x406815  c1e90c                            shr    ecx,0xc
0x406818  f6c101                            test   cl,0x1
0x40681b  750f                              jne    0x40682c
0x40681d  8b4860                            mov    ecx,DWORD PTR [eax+0x60]
0x406820  85c9                              test   ecx,ecx
0x406822  7408                              je     0x40682c
0x406824  50                                push   eax
0x406825  8bc1                              mov    eax,ecx
0x406827  e814373400                        call   0x749f40
0x40682c  6a18                              push   0x18
0x40682e  e835aa4800                        call   0x891268
0x406833  83c404                            add    esp,0x4
0x406836  85c0                              test   eax,eax
0x406838  7429                              je     0x406863
0x40683a  83c9ff                            or     ecx,0xffffffff
0x40683d  897014                            mov    DWORD PTR [eax+0x14],esi
0x406840  8bf0                              mov    esi,eax
0x406842  894804                            mov    DWORD PTR [eax+0x4],ecx
0x406845  894808                            mov    DWORD PTR [eax+0x8],ecx
0x406848  c7400c00000000                    mov    DWORD PTR [eax+0xc],0x0
0x40684f  c7401050430f00                    mov    DWORD PTR [eax+0x10],0xf4350
0x406856  c700247bc400                      mov    DWORD PTR [eax],0xc47b24
0x40685c  e83f0a0000                        call   0x4072a0
0x406861  5e                                pop    esi
0x406862  c3                                ret
0x406863  33c0                              xor    eax,eax
0x406865  8bf0                              mov    esi,eax
0x406867  e8340a0000                        call   0x4072a0
0x40686c  5e                                pop    esi
0x40686d  c3                                ret

### R28 Review SceneItem ctor vptr, +26C initial0
VA 0x47b480 RAW 0x7a880 END 0x47b51a SHA256 11d1030f67ae21f1ea934216a98ea97dbd7d20832ae654e94c4c89433aff07de
0x47b480  55                                push   ebp
0x47b481  8bec                              mov    ebp,esp
0x47b483  6aff                              push   0xffffffff
0x47b485  68689c9100                        push   0x919c68
0x47b48a  64a100000000                      mov    eax,fs:0x0
0x47b490  50                                push   eax
0x47b491  51                                push   ecx
0x47b492  53                                push   ebx
0x47b493  56                                push   esi
0x47b494  a1201fd600                        mov    eax,ds:0xd61f20
0x47b499  33c5                              xor    eax,ebp
0x47b49b  50                                push   eax
0x47b49c  8d45f4                            lea    eax,[ebp-0xc]
0x47b49f  64a300000000                      mov    fs:0x0,eax
0x47b4a5  8bf1                              mov    esi,ecx
0x47b4a7  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x47b4aa  e8d1932d00                        call   0x754880
0x47b4af  8d865c010000                      lea    eax,[esi+0x15c]
0x47b4b5  33db                              xor    ebx,ebx
0x47b4b7  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x47b4ba  50                                push   eax
0x47b4bb  c706dc67c400                      mov    DWORD PTR [esi],0xc467dc
0x47b4c1  e85a003000                        call   0x77b520
0x47b4c6  83c8ff                            or     eax,0xffffffff
0x47b4c9  898648020000                      mov    DWORD PTR [esi+0x248],eax
0x47b4cf  89864c020000                      mov    DWORD PTR [esi+0x24c],eax
0x47b4d5  c6865801000001                    mov    BYTE PTR [esi+0x158],0x1
0x47b4dc  c7063c2fc000                      mov    DWORD PTR [esi],0xc02f3c
0x47b4e2  c7866402000007000000              mov    DWORD PTR [esi+0x264],0x7
0x47b4ec  899e60020000                      mov    DWORD PTR [esi+0x260],ebx
0x47b4f2  33c9                              xor    ecx,ecx
0x47b4f4  66898e50020000                    mov    WORD PTR [esi+0x250],cx
0x47b4fb  889e6c020000                      mov    BYTE PTR [esi+0x26c],bl
0x47b501  899e70020000                      mov    DWORD PTR [esi+0x270],ebx
0x47b507  8bc6                              mov    eax,esi
0x47b509  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47b50c  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47b513  59                                pop    ecx
0x47b514  5e                                pop    esi
0x47b515  5b                                pop    ebx
0x47b516  8be5                              mov    esp,ebp
0x47b518  5d                                pop    ebp
0x47b519  c3                                ret

### R29 Review targeted UI event handling
VA 0x47c5d0 RAW 0x7b9d0 END 0x47c6dc SHA256 97713c160ea85d8d1e617a3642ed6960fae4faf86fc88cdd645c0962f5650880
0x47c5d0  55                                push   ebp
0x47c5d1  8bec                              mov    ebp,esp
0x47c5d3  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x47c5d6  8b4210                            mov    eax,DWORD PTR [edx+0x10]
0x47c5d9  2d78050000                        sub    eax,0x578
0x47c5de  0f8490000000                      je     0x47c674
0x47c5e4  2d92010000                        sub    eax,0x192
0x47c5e9  744e                              je     0x47c639
0x47c5eb  48                                dec    eax
0x47c5ec  0f85e6000000                      jne    0x47c6d8
0x47c5f2  817a08a00f0000                    cmp    DWORD PTR [edx+0x8],0xfa0
0x47c5f9  0f83d9000000                      jae    0x47c6d8
0x47c5ff  8b81f8000000                      mov    eax,DWORD PTR [ecx+0xf8]
0x47c605  8b80cc000000                      mov    eax,DWORD PTR [eax+0xcc]
0x47c60b  85c0                              test   eax,eax
0x47c60d  7417                              je     0x47c626
0x47c60f  8b80dc000000                      mov    eax,DWORD PTR [eax+0xdc]
0x47c615  8b8048020000                      mov    eax,DWORD PTR [eax+0x248]
0x47c61b  50                                push   eax
0x47c61c  51                                push   ecx
0x47c61d  e8de040000                        call   0x47cb00
0x47c622  5d                                pop    ebp
0x47c623  c20400                            ret    0x4
0x47c626  33c0                              xor    eax,eax
0x47c628  8b8048020000                      mov    eax,DWORD PTR [eax+0x248]
0x47c62e  50                                push   eax
0x47c62f  51                                push   ecx
0x47c630  e8cb040000                        call   0x47cb00
0x47c635  5d                                pop    ebp
0x47c636  c20400                            ret    0x4
0x47c639  817a0888130000                    cmp    DWORD PTR [edx+0x8],0x1388
0x47c640  0f8292000000                      jb     0x47c6d8
0x47c646  8b81fc000000                      mov    eax,DWORD PTR [ecx+0xfc]
0x47c64c  8b80cc000000                      mov    eax,DWORD PTR [eax+0xcc]
0x47c652  85c0                              test   eax,eax
0x47c654  7411                              je     0x47c667
0x47c656  8b80dc000000                      mov    eax,DWORD PTR [eax+0xdc]
0x47c65c  50                                push   eax
0x47c65d  51                                push   ecx
0x47c65e  e8ad110000                        call   0x47d810
0x47c663  5d                                pop    ebp
0x47c664  c20400                            ret    0x4
0x47c667  33c0                              xor    eax,eax
0x47c669  50                                push   eax
0x47c66a  51                                push   ecx
0x47c66b  e8a0110000                        call   0x47d810
0x47c670  5d                                pop    ebp
0x47c671  c20400                            ret    0x4
0x47c674  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x47c677  8b9108010000                      mov    edx,DWORD PTR [ecx+0x108]
0x47c67d  394220                            cmp    DWORD PTR [edx+0x20],eax
0x47c680  750e                              jne    0x47c690
0x47c682  8b01                              mov    eax,DWORD PTR [ecx]
0x47c684  8b90d4000000                      mov    edx,DWORD PTR [eax+0xd4]
0x47c68a  ffd2                              call   edx
0x47c68c  5d                                pop    ebp
0x47c68d  c20400                            ret    0x4
0x47c690  8b9104010000                      mov    edx,DWORD PTR [ecx+0x104]
0x47c696  394220                            cmp    DWORD PTR [edx+0x20],eax
0x47c699  7529                              jne    0x47c6c4
0x47c69b  8b81fc000000                      mov    eax,DWORD PTR [ecx+0xfc]
0x47c6a1  8b80cc000000                      mov    eax,DWORD PTR [eax+0xcc]
0x47c6a7  85c0                              test   eax,eax
0x47c6a9  7408                              je     0x47c6b3
0x47c6ab  8b80dc000000                      mov    eax,DWORD PTR [eax+0xdc]
0x47c6b1  eb02                              jmp    0x47c6b5
0x47c6b3  33c0                              xor    eax,eax
0x47c6b5  85c0                              test   eax,eax
0x47c6b7  741f                              je     0x47c6d8
0x47c6b9  50                                push   eax
0x47c6ba  51                                push   ecx
0x47c6bb  e850110000                        call   0x47d810
0x47c6c0  5d                                pop    ebp
0x47c6c1  c20400                            ret    0x4
0x47c6c4  8b9100010000                      mov    edx,DWORD PTR [ecx+0x100]
0x47c6ca  394220                            cmp    DWORD PTR [edx+0x20],eax
0x47c6cd  7509                              jne    0x47c6d8
0x47c6cf  56                                push   esi
0x47c6d0  8bf1                              mov    esi,ecx
0x47c6d2  e8b90d0000                        call   0x47d490
0x47c6d7  5e                                pop    esi
0x47c6d8  5d                                pop    ebp
0x47c6d9  c20400                            ret    0x4

### R30 Review selection party gate to47D530
VA 0x47d810 RAW 0x7cc10 END 0x47d9f3 SHA256 3028e59cec38e910664b4e2a2b3b082fa16159aff9fef77c9bf0fef7573c903a
0x47d810  55                                push   ebp
0x47d811  8bec                              mov    ebp,esp
0x47d813  6aff                              push   0xffffffff
0x47d815  68c2919400                        push   0x9491c2
0x47d81a  64a100000000                      mov    eax,fs:0x0
0x47d820  50                                push   eax
0x47d821  51                                push   ecx
0x47d822  53                                push   ebx
0x47d823  56                                push   esi
0x47d824  57                                push   edi
0x47d825  a1201fd600                        mov    eax,ds:0xd61f20
0x47d82a  33c5                              xor    eax,ebp
0x47d82c  50                                push   eax
0x47d82d  8d45f4                            lea    eax,[ebp-0xc]
0x47d830  64a300000000                      mov    fs:0x0,eax
0x47d836  33db                              xor    ebx,ebx
0x47d838  f6057813fb0001                    test   BYTE PTR ds:0xfb1378,0x1
0x47d83f  8d7301                            lea    esi,[ebx+0x1]
0x47d842  7523                              jne    0x47d867
0x47d844  09357813fb00                      or     DWORD PTR ds:0xfb1378,esi
0x47d84a  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
0x47d84d  e8cec30b00                        call   0x539c20
0x47d852  68b0cfbc00                        push   0xbccfb0
0x47d857  e8be4a4100                        call   0x89231a
0x47d85c  83c404                            add    esp,0x4
0x47d85f  83cfff                            or     edi,0xffffffff
0x47d862  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x47d865  eb03                              jmp    0x47d86a
0x47d867  83cfff                            or     edi,0xffffffff
0x47d86a  a15872fb00                        mov    eax,ds:0xfb7258
0x47d86f  3bc3                              cmp    eax,ebx
0x47d871  0f845d010000                      je     0x47d9d4
0x47d877  8b482c                            mov    ecx,DWORD PTR [eax+0x2c]
0x47d87a  2b4828                            sub    ecx,DWORD PTR [eax+0x28]
0x47d87d  83e1fc                            and    ecx,0xfffffffc
0x47d880  83f904                            cmp    ecx,0x4
0x47d883  0f8445010000                      je     0x47d9ce
0x47d889  f605d4adfa0001                    test   BYTE PTR ds:0xfaadd4,0x1
0x47d890  751e                              jne    0x47d8b0
0x47d892  0935d4adfa00                      or     DWORD PTR ds:0xfaadd4,esi
0x47d898  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x47d89b  e8e09b1000                        call   0x587480
0x47d8a0  68c0ccbc00                        push   0xbcccc0
0x47d8a5  e8704a4100                        call   0x89231a
0x47d8aa  83c404                            add    esp,0x4
0x47d8ad  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x47d8b0  6a18                              push   0x18
0x47d8b2  e8b1394100                        call   0x891268
0x47d8b7  83c404                            add    esp,0x4
0x47d8ba  3bc3                              cmp    eax,ebx
0x47d8bc  741d                              je     0x47d8db
0x47d8be  897014                            mov    DWORD PTR [eax+0x14],esi
0x47d8c1  897804                            mov    DWORD PTR [eax+0x4],edi
0x47d8c4  897808                            mov    DWORD PTR [eax+0x8],edi
0x47d8c7  89580c                            mov    DWORD PTR [eax+0xc],ebx
0x47d8ca  c7401021440f00                    mov    DWORD PTR [eax+0x10],0xf4421
0x47d8d1  c700ac67c400                      mov    DWORD PTR [eax],0xc467ac
0x47d8d7  8bf0                              mov    esi,eax
0x47d8d9  eb02                              jmp    0x47d8dd
0x47d8db  33f6                              xor    esi,esi
0x47d8dd  f605d0adfa0001                    test   BYTE PTR ds:0xfaadd0,0x1
0x47d8e4  7523                              jne    0x47d909
0x47d8e6  830dd0adfa0001                    or     DWORD PTR ds:0xfaadd0,0x1
0x47d8ed  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x47d8f4  e897002d00                        call   0x74d990
0x47d8f9  6870ccbc00                        push   0xbccc70
0x47d8fe  e8174a4100                        call   0x89231a
0x47d903  83c404                            add    esp,0x4
0x47d906  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x47d909  8b15d45bf900                      mov    edx,DWORD PTR ds:0xf95bd4
0x47d90f  52                                push   edx
0x47d910  56                                push   esi
0x47d911  83ec1c                            sub    esp,0x1c
0x47d914  8bcc                              mov    ecx,esp
0x47d916  8965f0                            mov    DWORD PTR [ebp-0x10],esp
0x47d919  53                                push   ebx
0x47d91a  bf07000000                        mov    edi,0x7
0x47d91f  33c0                              xor    eax,eax
0x47d921  897914                            mov    DWORD PTR [ecx+0x14],edi
0x47d924  895910                            mov    DWORD PTR [ecx+0x10],ebx
0x47d927  68fcd1be00                        push   0xbed1fc
0x47d92c  668901                            mov    WORD PTR [ecx],ax
0x47d92f  e82c48f8ff                        call   0x402160
0x47d934  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
0x47d93b  c7450c77010000                    mov    DWORD PTR [ebp+0xc],0x177
0x47d942  e8697b1000                        call   0x5854b0
0x47d947  8bf0                              mov    esi,eax
0x47d949  8d4d0c                            lea    ecx,[ebp+0xc]
0x47d94c  51                                push   ecx
0x47d94d  8d4508                            lea    eax,[ebp+0x8]
0x47d950  8bce                              mov    ecx,esi
0x47d952  e899670f00                        call   0x5740f0
0x47d957  8b7604                            mov    esi,DWORD PTR [esi+0x4]
0x47d95a  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x47d95d  3bc6                              cmp    eax,esi
0x47d95f  740d                              je     0x47d96e
0x47d961  83782408                          cmp    DWORD PTR [eax+0x24],0x8
0x47d965  8d7010                            lea    esi,[eax+0x10]
0x47d968  720a                              jb     0x47d974
0x47d96a  8b36                              mov    esi,DWORD PTR [esi]
0x47d96c  eb06                              jmp    0x47d974
0x47d96e  cc                                int3
0x47d96f  befcd1be00                        mov    esi,0xbed1fc
0x47d974  83ec1c                            sub    esp,0x1c
0x47d977  8bcc                              mov    ecx,esp
0x47d979  897914                            mov    DWORD PTR [ecx+0x14],edi
0x47d97c  33d2                              xor    edx,edx
0x47d97e  8bc6                              mov    eax,esi
0x47d980  895910                            mov    DWORD PTR [ecx+0x10],ebx
0x47d983  89650c                            mov    DWORD PTR [ebp+0xc],esp
0x47d986  668911                            mov    WORD PTR [ecx],dx
0x47d989  8d7802                            lea    edi,[eax+0x2]
0x47d98c  8d642400                          lea    esp,[esp+0x0]
0x47d990  668b10                            mov    dx,WORD PTR [eax]
0x47d993  83c002                            add    eax,0x2
0x47d996  663bd3                            cmp    dx,bx
0x47d999  75f5                              jne    0x47d990
0x47d99b  2bc7                              sub    eax,edi
0x47d99d  d1f8                              sar    eax,1
0x47d99f  50                                push   eax
0x47d9a0  56                                push   esi
0x47d9a1  e8ba47f8ff                        call   0x402160
0x47d9a6  68cf000000                        push   0xcf
0x47d9ab  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x47d9b2  e8b9d81000                        call   0x58b270
0x47d9b7  83c444                            add    esp,0x44
0x47d9ba  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47d9bd  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47d9c4  59                                pop    ecx
0x47d9c5  5f                                pop    edi
0x47d9c6  5e                                pop    esi
0x47d9c7  5b                                pop    ebx
0x47d9c8  8be5                              mov    esp,ebp
0x47d9ca  5d                                pop    ebp
0x47d9cb  c20800                            ret    0x8
0x47d9ce  50                                push   eax
0x47d9cf  e81cc10b00                        call   0x539af0
0x47d9d4  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x47d9d7  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x47d9da  e851fbffff                        call   0x47d530
0x47d9df  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47d9e2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47d9e9  59                                pop    ecx
0x47d9ea  5f                                pop    edi
0x47d9eb  5e                                pop    esi
0x47d9ec  5b                                pop    ebx
0x47d9ed  8be5                              mov    esp,ebp
0x47d9ef  5d                                pop    ebp
0x47d9f0  c20800                            ret    0x8

### R31 Review selected quest/scene to47B5C0
VA 0x47d530 RAW 0x7c930 END 0x47d609 SHA256 4891ebad4000dcbeff56bac5aa050c8e557cbb600cc0bd9c7d76c36b9fd9161e
0x47d530  55                                push   ebp
0x47d531  8bec                              mov    ebp,esp
0x47d533  6aff                              push   0xffffffff
0x47d535  687e7e9400                        push   0x947e7e
0x47d53a  64a100000000                      mov    eax,fs:0x0
0x47d540  50                                push   eax
0x47d541  56                                push   esi
0x47d542  57                                push   edi
0x47d543  a1201fd600                        mov    eax,ds:0xd61f20
0x47d548  33c5                              xor    eax,ebp
0x47d54a  50                                push   eax
0x47d54b  8d45f4                            lea    eax,[ebp-0xc]
0x47d54e  64a300000000                      mov    fs:0x0,eax
0x47d554  8bf1                              mov    esi,ecx
0x47d556  8bfa                              mov    edi,edx
0x47d558  8b8648020000                      mov    eax,DWORD PTR [esi+0x248]
0x47d55e  898720010000                      mov    DWORD PTR [edi+0x120],eax
0x47d564  8b864c020000                      mov    eax,DWORD PTR [esi+0x24c]
0x47d56a  89871c010000                      mov    DWORD PTR [edi+0x11c],eax
0x47d570  b801000000                        mov    eax,0x1
0x47d575  8405640ffc00                      test   BYTE PTR ds:0xfc0f64,al
0x47d57b  7526                              jne    0x47d5a3
0x47d57d  0905640ffc00                      or     DWORD PTR ds:0xfc0f64,eax
0x47d583  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x47d58a  e851070000                        call   0x47dce0
0x47d58f  68f0dabc00                        push   0xbcdaf0
0x47d594  e8814d4100                        call   0x89231a
0x47d599  83c404                            add    esp,0x4
0x47d59c  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x47d5a3  8b8720010000                      mov    eax,DWORD PTR [edi+0x120]
0x47d5a9  50                                push   eax
0x47d5aa  68680ffc00                        push   0xfc0f68
0x47d5af  e8dc120000                        call   0x47e890
0x47d5b4  50                                push   eax
0x47d5b5  8bce                              mov    ecx,esi
0x47d5b7  e804e0ffff                        call   0x47b5c0
0x47d5bc  57                                push   edi
0x47d5bd  e82ef8ffff                        call   0x47cdf0
0x47d5c2  8b8f00010000                      mov    ecx,DWORD PTR [edi+0x100]
0x47d5c8  8b31                              mov    esi,DWORD PTR [ecx]
0x47d5ca  e841000000                        call   0x47d610
0x47d5cf  8b8f00010000                      mov    ecx,DWORD PTR [edi+0x100]
0x47d5d5  0fb6d0                            movzx  edx,al
0x47d5d8  8b8690000000                      mov    eax,DWORD PTR [esi+0x90]
0x47d5de  52                                push   edx
0x47d5df  ffd0                              call   eax
0x47d5e1  8b8f00010000                      mov    ecx,DWORD PTR [edi+0x100]
0x47d5e7  8b11                              mov    edx,DWORD PTR [ecx]
0x47d5e9  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x47d5ef  ffd0                              call   eax
0x47d5f1  8bcf                              mov    ecx,edi
0x47d5f3  e8b8faffff                        call   0x47d0b0
0x47d5f8  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47d5fb  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47d602  59                                pop    ecx
0x47d603  5f                                pop    edi
0x47d604  5e                                pop    esi
0x47d605  8be5                              mov    esp,ebp
0x47d607  5d                                pop    ebp
0x47d608  c3                                ret

### R32 Lobby page update; +2AC visibility gates review pump
VA 0x5b87b0 RAW 0x1b7bb0 END 0x5b8b3c SHA256 7b4827018d353ad1168bd4b2fbe3e659744f795b8ea0c5525dddd14a03aca25f
0x5b87b0  55                                push   ebp
0x5b87b1  8bec                              mov    ebp,esp
0x5b87b3  6aff                              push   0xffffffff
0x5b87b5  68e6929400                        push   0x9492e6
0x5b87ba  64a100000000                      mov    eax,fs:0x0
0x5b87c0  50                                push   eax
0x5b87c1  83ec24                            sub    esp,0x24
0x5b87c4  53                                push   ebx
0x5b87c5  56                                push   esi
0x5b87c6  57                                push   edi
0x5b87c7  a1201fd600                        mov    eax,ds:0xd61f20
0x5b87cc  33c5                              xor    eax,ebp
0x5b87ce  50                                push   eax
0x5b87cf  8d45f4                            lea    eax,[ebp-0xc]
0x5b87d2  64a300000000                      mov    fs:0x0,eax
0x5b87d8  8bd9                              mov    ebx,ecx
0x5b87da  e8112afeff                        call   0x59b1f0
0x5b87df  f605e45afe0001                    test   BYTE PTR ds:0xfe5ae4,0x1
0x5b87e6  752c                              jne    0x5b8814
0x5b87e8  830de45afe0001                    or     DWORD PTR ds:0xfe5ae4,0x1
0x5b87ef  68c45afe00                        push   0xfe5ac4
0x5b87f4  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5b87fb  e840c4fcff                        call   0x584c40
0x5b8800  6890f3bc00                        push   0xbcf390
0x5b8805  e8109b2d00                        call   0x89231a
0x5b880a  83c404                            add    esp,0x4
0x5b880d  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x5b8814  8d45f0                            lea    eax,[ebp-0x10]
0x5b8817  50                                push   eax
0x5b8818  8d45ec                            lea    eax,[ebp-0x14]
0x5b881b  b9c45afe00                        mov    ecx,0xfe5ac4
0x5b8820  c745f0e7020000                    mov    DWORD PTR [ebp-0x10],0x2e7
0x5b8827  e8c4b8fbff                        call   0x5740f0
0x5b882c  8b45ec                            mov    eax,DWORD PTR [ebp-0x14]
0x5b882f  bf08000000                        mov    edi,0x8
0x5b8834  3b05c85afe00                      cmp    eax,DWORD PTR ds:0xfe5ac8
0x5b883a  740c                              je     0x5b8848
0x5b883c  397824                            cmp    DWORD PTR [eax+0x24],edi
0x5b883f  8d5010                            lea    edx,[eax+0x10]
0x5b8842  720a                              jb     0x5b884e
0x5b8844  8b12                              mov    edx,DWORD PTR [edx]
0x5b8846  eb06                              jmp    0x5b884e
0x5b8848  cc                                int3
0x5b8849  bafcd1be00                        mov    edx,0xbed1fc
0x5b884e  33c9                              xor    ecx,ecx
0x5b8850  8bc2                              mov    eax,edx
0x5b8852  c745e407000000                    mov    DWORD PTR [ebp-0x1c],0x7
0x5b8859  c745e000000000                    mov    DWORD PTR [ebp-0x20],0x0
0x5b8860  66894dd0                          mov    WORD PTR [ebp-0x30],cx
0x5b8864  8d7002                            lea    esi,[eax+0x2]
0x5b8867  668b08                            mov    cx,WORD PTR [eax]
0x5b886a  83c002                            add    eax,0x2
0x5b886d  6685c9                            test   cx,cx
0x5b8870  75f5                              jne    0x5b8867
0x5b8872  2bc6                              sub    eax,esi
0x5b8874  d1f8                              sar    eax,1
0x5b8876  50                                push   eax
0x5b8877  52                                push   edx
0x5b8878  8d4dd0                            lea    ecx,[ebp-0x30]
0x5b887b  e8e098e4ff                        call   0x402160
0x5b8880  8bb320020000                      mov    esi,DWORD PTR [ebx+0x220]
0x5b8886  8d55d0                            lea    edx,[ebp-0x30]
0x5b8889  52                                push   edx
0x5b888a  8db6e8000000                      lea    esi,[esi+0xe8]
0x5b8890  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x5b8897  e864ef1900                        call   0x757800
0x5b889c  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x5b88a3  397de4                            cmp    DWORD PTR [ebp-0x1c],edi
0x5b88a6  720c                              jb     0x5b88b4
0x5b88a8  8b45d0                            mov    eax,DWORD PTR [ebp-0x30]
0x5b88ab  50                                push   eax
0x5b88ac  e85b892d00                        call   0x89120c
0x5b88b1  83c404                            add    esp,0x4
0x5b88b4  33c9                              xor    ecx,ecx
0x5b88b6  66894dd0                          mov    WORD PTR [ebp-0x30],cx
0x5b88ba  8b8b4c020000                      mov    ecx,DWORD PTR [ebx+0x24c]
0x5b88c0  8b5128                            mov    edx,DWORD PTR [ecx+0x28]
0x5b88c3  c1ea08                            shr    edx,0x8
0x5b88c6  c745e407000000                    mov    DWORD PTR [ebp-0x1c],0x7
0x5b88cd  c745e000000000                    mov    DWORD PTR [ebp-0x20],0x0
0x5b88d4  f6c201                            test   dl,0x1
0x5b88d7  7405                              je     0x5b88de
0x5b88d9  e8125e0d00                        call   0x68e6f0
0x5b88de  8b8350020000                      mov    eax,DWORD PTR [ebx+0x250]
0x5b88e4  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5b88e7  c1e908                            shr    ecx,0x8
0x5b88ea  f6c101                            test   cl,0x1
0x5b88ed  7406                              je     0x5b88f5
0x5b88ef  50                                push   eax
0x5b88f0  e85be60d00                        call   0x696f50
0x5b88f5  8b837c020000                      mov    eax,DWORD PTR [ebx+0x27c]
0x5b88fb  8b5028                            mov    edx,DWORD PTR [eax+0x28]
0x5b88fe  c1ea08                            shr    edx,0x8
0x5b8901  f6c201                            test   dl,0x1
0x5b8904  7405                              je     0x5b890b
0x5b8906  e835170d00                        call   0x68a040
0x5b890b  8b831c020000                      mov    eax,DWORD PTR [ebx+0x21c]
0x5b8911  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5b8914  c1e908                            shr    ecx,0x8
0x5b8917  f6c101                            test   cl,0x1
0x5b891a  7416                              je     0x5b8932
0x5b891c  8b80f4000000                      mov    eax,DWORD PTR [eax+0xf4]
0x5b8922  85c0                              test   eax,eax
0x5b8924  740c                              je     0x5b8932
0x5b8926  8b10                              mov    edx,DWORD PTR [eax]
0x5b8928  8bc8                              mov    ecx,eax
0x5b892a  8b82c8000000                      mov    eax,DWORD PTR [edx+0xc8]
0x5b8930  ffd0                              call   eax
0x5b8932  8b8364010000                      mov    eax,DWORD PTR [ebx+0x164]
0x5b8938  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5b893b  c1e908                            shr    ecx,0x8
0x5b893e  f6c101                            test   cl,0x1
0x5b8941  7406                              je     0x5b8949
0x5b8943  50                                push   eax
0x5b8944  e8e75e0100                        call   0x5ce830
0x5b8949  8b8360020000                      mov    eax,DWORD PTR [ebx+0x260]
0x5b894f  8b5028                            mov    edx,DWORD PTR [eax+0x28]
0x5b8952  c1ea08                            shr    edx,0x8
0x5b8955  f6c201                            test   dl,0x1
0x5b8958  7405                              je     0x5b895f
0x5b895a  e8b12c0c00                        call   0x67b610
0x5b895f  8b8364020000                      mov    eax,DWORD PTR [ebx+0x264]
0x5b8965  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5b8968  c1e908                            shr    ecx,0x8
0x5b896b  f6c101                            test   cl,0x1
0x5b896e  7405                              je     0x5b8975
0x5b8970  e8ebf40c00                        call   0x687e60
0x5b8975  8b8368020000                      mov    eax,DWORD PTR [ebx+0x268]
0x5b897b  8b5028                            mov    edx,DWORD PTR [eax+0x28]
0x5b897e  c1ea08                            shr    edx,0x8
0x5b8981  f6c201                            test   dl,0x1
0x5b8984  7405                              je     0x5b898b
0x5b8986  e8a57a0c00                        call   0x680430
0x5b898b  8bb36c020000                      mov    esi,DWORD PTR [ebx+0x26c]
0x5b8991  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x5b8994  c1e808                            shr    eax,0x8
0x5b8997  a801                              test   al,0x1
0x5b8999  7405                              je     0x5b89a0
0x5b899b  e8004a0c00                        call   0x67d3a0
0x5b89a0  8bb370020000                      mov    esi,DWORD PTR [ebx+0x270]
0x5b89a6  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x5b89a9  c1e908                            shr    ecx,0x8
0x5b89ac  f6c101                            test   cl,0x1
0x5b89af  7405                              je     0x5b89b6
0x5b89b1  e8ea8f0c00                        call   0x6819a0
0x5b89b6  8bb378020000                      mov    esi,DWORD PTR [ebx+0x278]
0x5b89bc  8b5628                            mov    edx,DWORD PTR [esi+0x28]
0x5b89bf  c1ea08                            shr    edx,0x8
0x5b89c2  f6c201                            test   dl,0x1
0x5b89c5  7405                              je     0x5b89cc
0x5b89c7  e8c4130c00                        call   0x679d90
0x5b89cc  8bb394020000                      mov    esi,DWORD PTR [ebx+0x294]
0x5b89d2  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x5b89d5  c1e808                            shr    eax,0x8
0x5b89d8  a801                              test   al,0x1
0x5b89da  7405                              je     0x5b89e1
0x5b89dc  e8df4beaff                        call   0x45d5c0
0x5b89e1  8bb398020000                      mov    esi,DWORD PTR [ebx+0x298]
0x5b89e7  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x5b89ea  c1e908                            shr    ecx,0x8
0x5b89ed  f6c101                            test   cl,0x1
0x5b89f0  7405                              je     0x5b89f7
0x5b89f2  e8c94beaff                        call   0x45d5c0
0x5b89f7  8bbb58020000                      mov    edi,DWORD PTR [ebx+0x258]
0x5b89fd  8b5728                            mov    edx,DWORD PTR [edi+0x28]
0x5b8a00  c1ea08                            shr    edx,0x8
0x5b8a03  f6c201                            test   dl,0x1
0x5b8a06  7405                              je     0x5b8a0d
0x5b8a08  e8b39aecff                        call   0x4824c0
0x5b8a0d  8bb35c020000                      mov    esi,DWORD PTR [ebx+0x25c]
0x5b8a13  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x5b8a16  c1e808                            shr    eax,0x8
0x5b8a19  a801                              test   al,0x1
0x5b8a1b  7405                              je     0x5b8a22
0x5b8a1d  e81eb1ecff                        call   0x483b40
0x5b8a22  8b8b28020000                      mov    ecx,DWORD PTR [ebx+0x228]
0x5b8a28  8b5128                            mov    edx,DWORD PTR [ecx+0x28]
0x5b8a2b  c1ea08                            shr    edx,0x8
0x5b8a2e  f6c201                            test   dl,0x1
0x5b8a31  7427                              je     0x5b8a5a
0x5b8a33  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x5b8a36  83ec10                            sub    esp,0x10
0x5b8a39  8bc4                              mov    eax,esp
0x5b8a3b  8910                              mov    DWORD PTR [eax],edx
0x5b8a3d  8b510c                            mov    edx,DWORD PTR [ecx+0xc]
0x5b8a40  895004                            mov    DWORD PTR [eax+0x4],edx
0x5b8a43  8b5110                            mov    edx,DWORD PTR [ecx+0x10]
0x5b8a46  895008                            mov    DWORD PTR [eax+0x8],edx
0x5b8a49  8b5114                            mov    edx,DWORD PTR [ecx+0x14]
0x5b8a4c  89500c                            mov    DWORD PTR [eax+0xc],edx
0x5b8a4f  8b81f4000000                      mov    eax,DWORD PTR [ecx+0xf4]
0x5b8a55  e8e6300900                        call   0x64bb40
0x5b8a5a  8b8b2c020000                      mov    ecx,DWORD PTR [ebx+0x22c]
0x5b8a60  8b4128                            mov    eax,DWORD PTR [ecx+0x28]
0x5b8a63  c1e808                            shr    eax,0x8
0x5b8a66  a801                              test   al,0x1
0x5b8a68  7427                              je     0x5b8a91
0x5b8a6a  8b5108                            mov    edx,DWORD PTR [ecx+0x8]
0x5b8a6d  83ec10                            sub    esp,0x10
0x5b8a70  8bc4                              mov    eax,esp
0x5b8a72  8910                              mov    DWORD PTR [eax],edx
0x5b8a74  8b510c                            mov    edx,DWORD PTR [ecx+0xc]
0x5b8a77  895004                            mov    DWORD PTR [eax+0x4],edx
0x5b8a7a  8b5110                            mov    edx,DWORD PTR [ecx+0x10]
0x5b8a7d  895008                            mov    DWORD PTR [eax+0x8],edx
0x5b8a80  8b5114                            mov    edx,DWORD PTR [ecx+0x14]
0x5b8a83  89500c                            mov    DWORD PTR [eax+0xc],edx
0x5b8a86  8b81fc000000                      mov    eax,DWORD PTR [ecx+0xfc]
0x5b8a8c  e8af300900                        call   0x64bb40
0x5b8a91  8bb39c020000                      mov    esi,DWORD PTR [ebx+0x29c]
0x5b8a97  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x5b8a9a  c1e808                            shr    eax,0x8
0x5b8a9d  a801                              test   al,0x1
0x5b8a9f  7405                              je     0x5b8aa6
0x5b8aa1  e8ea25eaff                        call   0x45b090
0x5b8aa6  8b83ac020000                      mov    eax,DWORD PTR [ebx+0x2ac]
0x5b8aac  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5b8aaf  c1e908                            shr    ecx,0x8
0x5b8ab2  f6c101                            test   cl,0x1
0x5b8ab5  7406                              je     0x5b8abd
0x5b8ab7  50                                push   eax
0x5b8ab8  e8c33eecff                        call   0x47c980
0x5b8abd  8bbbb0020000                      mov    edi,DWORD PTR [ebx+0x2b0]
0x5b8ac3  8b5728                            mov    edx,DWORD PTR [edi+0x28]
0x5b8ac6  c1ea08                            shr    edx,0x8
0x5b8ac9  f6c201                            test   dl,0x1
0x5b8acc  7405                              je     0x5b8ad3
0x5b8ace  e80dc5ebff                        call   0x474fe0
0x5b8ad3  8bb3d4020000                      mov    esi,DWORD PTR [ebx+0x2d4]
0x5b8ad9  8b4628                            mov    eax,DWORD PTR [esi+0x28]
0x5b8adc  c1e808                            shr    eax,0x8
0x5b8adf  a801                              test   al,0x1
0x5b8ae1  7405                              je     0x5b8ae8
0x5b8ae3  e8a89ae8ff                        call   0x442590
0x5b8ae8  8bb3a4020000                      mov    esi,DWORD PTR [ebx+0x2a4]
0x5b8aee  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x5b8af1  c1e908                            shr    ecx,0x8
0x5b8af4  f6c101                            test   cl,0x1
0x5b8af7  7405                              je     0x5b8afe
0x5b8af9  e8720ce5ff                        call   0x409770
0x5b8afe  8bb3a8020000                      mov    esi,DWORD PTR [ebx+0x2a8]
0x5b8b04  8b5628                            mov    edx,DWORD PTR [esi+0x28]
0x5b8b07  c1ea08                            shr    edx,0x8
0x5b8b0a  f6c201                            test   dl,0x1
0x5b8b0d  7405                              je     0x5b8b14
0x5b8b0f  e89c3ae5ff                        call   0x40c5b0
0x5b8b14  8b9be0020000                      mov    ebx,DWORD PTR [ebx+0x2e0]
0x5b8b1a  8b4328                            mov    eax,DWORD PTR [ebx+0x28]
0x5b8b1d  c1e808                            shr    eax,0x8
0x5b8b20  a801                              test   al,0x1
0x5b8b22  7406                              je     0x5b8b2a
0x5b8b24  53                                push   ebx
0x5b8b25  e8962de7ff                        call   0x42b8c0
0x5b8b2a  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5b8b2d  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5b8b34  59                                pop    ecx
0x5b8b35  5f                                pop    edi
0x5b8b36  5e                                pop    esi
0x5b8b37  5b                                pop    ebx
0x5b8b38  8be5                              mov    esp,ebp
0x5b8b3a  5d                                pop    ebp
0x5b8b3b  c3                                ret

### R33 UI engine currentpage gate→engine+28 every update
VA 0x750550 RAW 0x34f950 END 0x7506e1 SHA256 a281325e782b4f4855391481bb731fdf38765a02f29461b8379d0002e9611340
0x750550  55                                push   ebp
0x750551  8bec                              mov    ebp,esp
0x750553  8b8ec8140000                      mov    ecx,DWORD PTR [esi+0x14c8]
0x750559  8b01                              mov    eax,DWORD PTR [ecx]
0x75055b  8909                              mov    DWORD PTR [ecx],ecx
0x75055d  8b8ec8140000                      mov    ecx,DWORD PTR [esi+0x14c8]
0x750563  894904                            mov    DWORD PTR [ecx+0x4],ecx
0x750566  57                                push   edi
0x750567  c786cc14000000000000              mov    DWORD PTR [esi+0x14cc],0x0
0x750571  3b86c8140000                      cmp    eax,DWORD PTR [esi+0x14c8]
0x750577  741c                              je     0x750595
0x750579  8da42400000000                    lea    esp,[esp+0x0]
0x750580  8b38                              mov    edi,DWORD PTR [eax]
0x750582  50                                push   eax
0x750583  e8840c1400                        call   0x89120c
0x750588  83c404                            add    esp,0x4
0x75058b  8bc7                              mov    eax,edi
0x75058d  3bbec8140000                      cmp    edi,DWORD PTR [esi+0x14c8]
0x750593  75eb                              jne    0x750580
0x750595  8b06                              mov    eax,DWORD PTR [esi]
0x750597  d9862c130000                      fld    DWORD PTR [esi+0x132c]
0x75059d  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x7505a0  8d4d20                            lea    ecx,[ebp+0x20]
0x7505a3  51                                push   ecx
0x7505a4  8d550c                            lea    edx,[ebp+0xc]
0x7505a7  52                                push   edx
0x7505a8  51                                push   ecx
0x7505a9  8bce                              mov    ecx,esi
0x7505ab  d91c24                            fstp   DWORD PTR [esp]
0x7505ae  ffd0                              call   eax
0x7505b0  8bc6                              mov    eax,esi
0x7505b2  e8e9feffff                        call   0x7504a0
0x7505b7  d986ac130000                      fld    DWORD PTR [esi+0x13ac]
0x7505bd  d9ee                              fldz
0x7505bf  dcc9                              fmul   st(1),st
0x7505c1  d9c9                              fxch   st(1)
0x7505c3  e848e71a00                        call   0x8fed10
0x7505c8  d88eb0130000                      fmul   DWORD PTR [esi+0x13b0]
0x7505ce  8986bc130000                      mov    DWORD PTR [esi+0x13bc],eax
0x7505d4  e837e71a00                        call   0x8fed10
0x7505d9  83bec413000000                    cmp    DWORD PTR [esi+0x13c4],0x0
0x7505e0  8986c0130000                      mov    DWORD PTR [esi+0x13c0],eax
0x7505e6  0f8481000000                      je     0x75066d
0x7505ec  8b16                              mov    edx,DWORD PTR [esi]
0x7505ee  d94508                            fld    DWORD PTR [ebp+0x8]
0x7505f1  8b4224                            mov    eax,DWORD PTR [edx+0x24]
0x7505f4  51                                push   ecx
0x7505f5  8bce                              mov    ecx,esi
0x7505f7  d91c24                            fstp   DWORD PTR [esp]
0x7505fa  ffd0                              call   eax
0x7505fc  d94508                            fld    DWORD PTR [ebp+0x8]
0x7505ff  8b16                              mov    edx,DWORD PTR [esi]
0x750601  8b4220                            mov    eax,DWORD PTR [edx+0x20]
0x750604  51                                push   ecx
0x750605  8bce                              mov    ecx,esi
0x750607  d91c24                            fstp   DWORD PTR [esp]
0x75060a  ffd0                              call   eax
0x75060c  80be0c14000000                    cmp    BYTE PTR [esi+0x140c],0x0
0x750613  7509                              jne    0x75061e
0x750615  8b16                              mov    edx,DWORD PTR [esi]
0x750617  8b4208                            mov    eax,DWORD PTR [edx+0x8]
0x75061a  8bce                              mov    ecx,esi
0x75061c  ffd0                              call   eax
0x75061e  8b16                              mov    edx,DWORD PTR [esi]
0x750620  8b4210                            mov    eax,DWORD PTR [edx+0x10]
0x750623  8bce                              mov    ecx,esi
0x750625  ffd0                              call   eax
0x750627  8b16                              mov    edx,DWORD PTR [esi]
0x750629  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x75062c  8bce                              mov    ecx,esi
0x75062e  ffd0                              call   eax
0x750630  80be0c14000000                    cmp    BYTE PTR [esi+0x140c],0x0
0x750637  7512                              jne    0x75064b
0x750639  8b16                              mov    edx,DWORD PTR [esi]
0x75063b  8b4218                            mov    eax,DWORD PTR [edx+0x18]
0x75063e  8bce                              mov    ecx,esi
0x750640  ffd0                              call   eax
0x750642  8b16                              mov    edx,DWORD PTR [esi]
0x750644  8b421c                            mov    eax,DWORD PTR [edx+0x1c]
0x750647  8bce                              mov    ecx,esi
0x750649  ffd0                              call   eax
0x75064b  8b16                              mov    edx,DWORD PTR [esi]
0x75064d  d94508                            fld    DWORD PTR [ebp+0x8]
0x750650  8b4228                            mov    eax,DWORD PTR [edx+0x28]
0x750653  51                                push   ecx
0x750654  8bce                              mov    ecx,esi
0x750656  d91c24                            fstp   DWORD PTR [esp]
0x750659  ffd0                              call   eax
0x75065b  80be0c14000000                    cmp    BYTE PTR [esi+0x140c],0x0
0x750662  7509                              jne    0x75066d
0x750664  8b16                              mov    edx,DWORD PTR [esi]
0x750666  8b420c                            mov    eax,DWORD PTR [edx+0xc]
0x750669  8bce                              mov    ecx,esi
0x75066b  ffd0                              call   eax
0x75066d  83beb465010000                    cmp    DWORD PTR [esi+0x165b4],0x0
0x750674  745f                              je     0x7506d5
0x750676  8bbed0130000                      mov    edi,DWORD PTR [esi+0x13d0]
0x75067c  85ff                              test   edi,edi
0x75067e  7446                              je     0x7506c6
0x750680  8bc7                              mov    eax,edi
0x750682  e8995dffff                        call   0x746420
0x750687  84c0                              test   al,al
0x750689  743b                              je     0x7506c6
0x75068b  8b4f28                            mov    ecx,DWORD PTR [edi+0x28]
0x75068e  c1e907                            shr    ecx,0x7
0x750691  f6c101                            test   cl,0x1
0x750694  7430                              je     0x7506c6
0x750696  8b17                              mov    edx,DWORD PTR [edi]
0x750698  8b8284000000                      mov    eax,DWORD PTR [edx+0x84]
0x75069e  8bcf                              mov    ecx,edi
0x7506a0  ffd0                              call   eax
0x7506a2  84c0                              test   al,al
0x7506a4  7420                              je     0x7506c6
0x7506a6  8b8eb4650100                      mov    ecx,DWORD PTR [esi+0x165b4]
0x7506ac  8b11                              mov    edx,DWORD PTR [ecx]
0x7506ae  8b86d0130000                      mov    eax,DWORD PTR [esi+0x13d0]
0x7506b4  8b5214                            mov    edx,DWORD PTR [edx+0x14]
0x7506b7  50                                push   eax
0x7506b8  ffd2                              call   edx
0x7506ba  c686bc14000001                    mov    BYTE PTR [esi+0x14bc],0x1
0x7506c1  5f                                pop    edi
0x7506c2  5d                                pop    ebp
0x7506c3  c21801                            ret    0x118
0x7506c6  8b8eb4650100                      mov    ecx,DWORD PTR [esi+0x165b4]
0x7506cc  8b01                              mov    eax,DWORD PTR [ecx]
0x7506ce  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x7506d1  6a00                              push   0x0
0x7506d3  ffd2                              call   edx
0x7506d5  c686bc14000001                    mov    BYTE PTR [esi+0x14bc],0x1
0x7506dc  5f                                pop    edi
0x7506dd  5d                                pop    ebp
0x7506de  c21801                            ret    0x118

### R34 Targeted event delivery and currentpage+184 dispatch
VA 0x7507e0 RAW 0x34fbe0 END 0x7508cb SHA256 89d8f9102bd0c89a4c16b05dd95753a9bbfb3c8d26420ee3811c34ba1c94a071
0x7507e0  55                                push   ebp
0x7507e1  8bec                              mov    ebp,esp
0x7507e3  83ec08                            sub    esp,0x8
0x7507e6  56                                push   esi
0x7507e7  57                                push   edi
0x7507e8  8bf9                              mov    edi,ecx
0x7507ea  83bfc413000000                    cmp    DWORD PTR [edi+0x13c4],0x0
0x7507f1  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x7507f4  0f84b3000000                      je     0x7508ad
0x7507fa  8b872c140000                      mov    eax,DWORD PTR [edi+0x142c]
0x750800  53                                push   ebx
0x750801  8b18                              mov    ebx,DWORD PTR [eax]
0x750803  8945f8                            mov    DWORD PTR [ebp-0x8],eax
0x750806  3bd8                              cmp    ebx,eax
0x750808  7441                              je     0x75084b
0x75080a  8d9b00000000                      lea    ebx,[ebx+0x0]
0x750810  8b4308                            mov    eax,DWORD PTR [ebx+0x8]
0x750813  83780c00                          cmp    DWORD PTR [eax+0xc],0x0
0x750817  7428                              je     0x750841
0x750819  8bf8                              mov    edi,eax
0x75081b  8b770c                            mov    esi,DWORD PTR [edi+0xc]
0x75081e  85f6                              test   esi,esi
0x750820  741f                              je     0x750841
0x750822  8b16                              mov    edx,DWORD PTR [esi]
0x750824  8b825c010000                      mov    eax,DWORD PTR [edx+0x15c]
0x75082a  57                                push   edi
0x75082b  8bce                              mov    ecx,esi
0x75082d  ffd0                              call   eax
0x75082f  f6462801                          test   BYTE PTR [esi+0x28],0x1
0x750833  740c                              je     0x750841
0x750835  8b4660                            mov    eax,DWORD PTR [esi+0x60]
0x750838  85c0                              test   eax,eax
0x75083a  7405                              je     0x750841
0x75083c  e8affeffff                        call   0x7506f0
0x750841  8b1b                              mov    ebx,DWORD PTR [ebx]
0x750843  3b5df8                            cmp    ebx,DWORD PTR [ebp-0x8]
0x750846  75c8                              jne    0x750810
0x750848  8b7dfc                            mov    edi,DWORD PTR [ebp-0x4]
0x75084b  8b8f38140000                      mov    ecx,DWORD PTR [edi+0x1438]
0x750851  8b31                              mov    esi,DWORD PTR [ecx]
0x750853  894df8                            mov    DWORD PTR [ebp-0x8],ecx
0x750856  3bf1                              cmp    esi,ecx
0x750858  7442                              je     0x75089c
0x75085a  8d9b00000000                      lea    ebx,[ebx+0x0]
0x750860  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x750863  83780c00                          cmp    DWORD PTR [eax+0xc],0x0
0x750867  742a                              je     0x750893
0x750869  83782c08                          cmp    DWORD PTR [eax+0x2c],0x8
0x75086d  7205                              jb     0x750874
0x75086f  8b5018                            mov    edx,DWORD PTR [eax+0x18]
0x750872  eb03                              jmp    0x750877
0x750874  8d5018                            lea    edx,[eax+0x18]
0x750877  8b580c                            mov    ebx,DWORD PTR [eax+0xc]
0x75087a  8b4010                            mov    eax,DWORD PTR [eax+0x10]
0x75087d  8b8fc4130000                      mov    ecx,DWORD PTR [edi+0x13c4]
0x750883  8b39                              mov    edi,DWORD PTR [ecx]
0x750885  53                                push   ebx
0x750886  50                                push   eax
0x750887  52                                push   edx
0x750888  8b9788010000                      mov    edx,DWORD PTR [edi+0x188]
0x75088e  ffd2                              call   edx
0x750890  8b4df8                            mov    ecx,DWORD PTR [ebp-0x8]
0x750893  8b36                              mov    esi,DWORD PTR [esi]
0x750895  8b7dfc                            mov    edi,DWORD PTR [ebp-0x4]
0x750898  3bf1                              cmp    esi,ecx
0x75089a  75c4                              jne    0x750860
0x75089c  8b8fc4130000                      mov    ecx,DWORD PTR [edi+0x13c4]
0x7508a2  8b01                              mov    eax,DWORD PTR [ecx]
0x7508a4  8b9084010000                      mov    edx,DWORD PTR [eax+0x184]
0x7508aa  ffd2                              call   edx
0x7508ac  5b                                pop    ebx
0x7508ad  8db738140000                      lea    esi,[edi+0x1438]
0x7508b3  e8782f0000                        call   0x753830
0x7508b8  8db72c140000                      lea    esi,[edi+0x142c]
0x7508be  e86d2f0000                        call   0x753830
0x7508c3  5f                                pop    edi
0x7508c4  5e                                pop    esi
0x7508c5  8be5                              mov    esp,ebp
0x7508c7  5d                                pop    ebp
0x7508c8  c20400                            ret    0x4

### R35 Review toggle hides NPC +224; show/hide +2AC
VA 0x5baf70 RAW 0x1ba370 END 0x5bafaf SHA256 3d942233f0d8fbeb74b36e93f702a136067051c88cf0c086107e1fc052c3f75e
0x5baf70  8b8e24020000                      mov    ecx,DWORD PTR [esi+0x224]
0x5baf76  8b4128                            mov    eax,DWORD PTR [ecx+0x28]
0x5baf79  c1e808                            shr    eax,0x8
0x5baf7c  a801                              test   al,0x1
0x5baf7e  740a                              je     0x5baf8a
0x5baf80  8b11                              mov    edx,DWORD PTR [ecx]
0x5baf82  8b82d4000000                      mov    eax,DWORD PTR [edx+0xd4]
0x5baf88  ffd0                              call   eax
0x5baf8a  8b86ac020000                      mov    eax,DWORD PTR [esi+0x2ac]
0x5baf90  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x5baf93  c1e908                            shr    ecx,0x8
0x5baf96  f6c101                            test   cl,0x1
0x5baf99  740c                              je     0x5bafa7
0x5baf9b  8bc8                              mov    ecx,eax
0x5baf9d  8b11                              mov    edx,DWORD PTR [ecx]
0x5baf9f  8b82d4000000                      mov    eax,DWORD PTR [edx+0xd4]
0x5bafa5  ffe0                              jmp    eax
0x5bafa7  50                                push   eax
0x5bafa8  56                                push   esi
0x5bafa9  e852befdff                        call   0x596e00
0x5bafae  c3                                ret

### R36 Page+F0 gate and registered-window group selection
VA 0x596e00 RAW 0x196200 END 0x596ebf SHA256 21de76b660111ce4684c4794cc72071b8d9f77321082a0779f77b3c5153ba708
0x596e00  55                                push   ebp
0x596e01  8bec                              mov    ebp,esp
0x596e03  83ec0c                            sub    esp,0xc
0x596e06  53                                push   ebx
0x596e07  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x596e0a  83bbf000000000                    cmp    DWORD PTR [ebx+0xf0],0x0
0x596e11  56                                push   esi
0x596e12  57                                push   edi
0x596e13  0f859d000000                      jne    0x596eb6
0x596e19  33f6                              xor    esi,esi
0x596e1b  33ff                              xor    edi,edi
0x596e1d  c745f8ffffffff                    mov    DWORD PTR [ebp-0x8],0xffffffff
0x596e24  81c3c4000000                      add    ebx,0xc4
0x596e2a  8d9b00000000                      lea    ebx,[ebx+0x0]
0x596e30  8d450c                            lea    eax,[ebp+0xc]
0x596e33  50                                push   eax
0x596e34  8d4bfc                            lea    ecx,[ebx-0x4]
0x596e37  8d45fc                            lea    eax,[ebp-0x4]
0x596e3a  e8e1112b00                        call   0x848020
0x596e3f  8b45fc                            mov    eax,DWORD PTR [ebp-0x4]
0x596e42  3b03                              cmp    eax,DWORD PTR [ebx]
0x596e44  750e                              jne    0x596e54
0x596e46  47                                inc    edi
0x596e47  83c310                            add    ebx,0x10
0x596e4a  83ff03                            cmp    edi,0x3
0x596e4d  7ce1                              jl     0x596e30
0x596e4f  8b7df8                            mov    edi,DWORD PTR [ebp-0x8]
0x596e52  eb03                              jmp    0x596e57
0x596e54  8d7010                            lea    esi,[eax+0x10]
0x596e57  8bc7                              mov    eax,edi
0x596e59  83e800                            sub    eax,0x0
0x596e5c  7445                              je     0x596ea3
0x596e5e  48                                dec    eax
0x596e5f  742c                              je     0x596e8d
0x596e61  48                                dec    eax
0x596e62  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x596e65  7413                              je     0x596e7a
0x596e67  8b11                              mov    edx,DWORD PTR [ecx]
0x596e69  8b82d0000000                      mov    eax,DWORD PTR [edx+0xd0]
0x596e6f  ffd0                              call   eax
0x596e71  5f                                pop    edi
0x596e72  5e                                pop    esi
0x596e73  5b                                pop    ebx
0x596e74  8be5                              mov    esp,ebp
0x596e76  5d                                pop    ebp
0x596e77  c20800                            ret    0x8
0x596e7a  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x596e7d  51                                push   ecx
0x596e7e  52                                push   edx
0x596e7f  e83c000000                        call   0x596ec0
0x596e84  5f                                pop    edi
0x596e85  5e                                pop    esi
0x596e86  5b                                pop    ebx
0x596e87  8be5                              mov    esp,ebp
0x596e89  5d                                pop    ebp
0x596e8a  c20800                            ret    0x8
0x596e8d  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x596e90  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x596e93  50                                push   eax
0x596e94  51                                push   ecx
0x596e95  e826000000                        call   0x596ec0
0x596e9a  5f                                pop    edi
0x596e9b  5e                                pop    esi
0x596e9c  5b                                pop    ebx
0x596e9d  8be5                              mov    esp,ebp
0x596e9f  5d                                pop    ebp
0x596ea0  c20800                            ret    0x8
0x596ea3  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x596ea6  57                                push   edi
0x596ea7  e8a4030000                        call   0x597250
0x596eac  8b550c                            mov    edx,DWORD PTR [ebp+0xc]
0x596eaf  52                                push   edx
0x596eb0  57                                push   edi
0x596eb1  e80a000000                        call   0x596ec0
0x596eb6  5f                                pop    edi
0x596eb7  5e                                pop    esi
0x596eb8  5b                                pop    ebx
0x596eb9  8be5                              mov    esp,ebp
0x596ebb  5d                                pop    ebp
0x596ebc  c20800                            ret    0x8

### R37 Registered-window condition gates, existing0049, show
VA 0x596ec0 RAW 0x1962c0 END 0x597033 SHA256 8163cb067abb6224b0739c1e877b2384a396ad8ce00635babd548faaec049371
0x596ec0  55                                push   ebp
0x596ec1  8bec                              mov    ebp,esp
0x596ec3  6aff                              push   0xffffffff
0x596ec5  68fe519400                        push   0x9451fe
0x596eca  64a100000000                      mov    eax,fs:0x0
0x596ed0  50                                push   eax
0x596ed1  53                                push   ebx
0x596ed2  57                                push   edi
0x596ed3  a1201fd600                        mov    eax,ds:0xd61f20
0x596ed8  33c5                              xor    eax,ebp
0x596eda  50                                push   eax
0x596edb  8d45f4                            lea    eax,[ebp-0xc]
0x596ede  64a300000000                      mov    fs:0x0,eax
0x596ee4  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
0x596ee7  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
0x596eea  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
0x596eed  c1e908                            shr    ecx,0x8
0x596ef0  f6c101                            test   cl,0x1
0x596ef3  0f8527010000                      jne    0x597020
0x596ef9  f6057813fb0001                    test   BYTE PTR ds:0xfb1378,0x1
0x596f00  7527                              jne    0x596f29
0x596f02  830d7813fb0001                    or     DWORD PTR ds:0xfb1378,0x1
0x596f09  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x596f10  e80b2dfaff                        call   0x539c20
0x596f15  68b0cfbc00                        push   0xbccfb0
0x596f1a  e8fbb32f00                        call   0x89231a
0x596f1f  83c404                            add    esp,0x4
0x596f22  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x596f29  8b3d5872fb00                      mov    edi,DWORD PTR ds:0xfb7258
0x596f2f  85ff                              test   edi,edi
0x596f31  742b                              je     0x596f5e
0x596f33  e868dce6ff                        call   0x404ba0
0x596f38  8b90505f0000                      mov    edx,DWORD PTR [eax+0x5f50]
0x596f3e  52                                push   edx
0x596f3f  8bd7                              mov    edx,edi
0x596f41  e85a2bfaff                        call   0x539aa0
0x596f46  85c0                              test   eax,eax
0x596f48  0f84d2000000                      je     0x597020
0x596f4e  80780800                          cmp    BYTE PTR [eax+0x8],0x0
0x596f52  740a                              je     0x596f5e
0x596f54  807e0600                          cmp    BYTE PTR [esi+0x6],0x0
0x596f58  0f84c2000000                      je     0x597020
0x596f5e  833e01                            cmp    DWORD PTR [esi],0x1
0x596f61  7519                              jne    0x596f7c
0x596f63  83bbf400000000                    cmp    DWORD PTR [ebx+0xf4],0x0
0x596f6a  7410                              je     0x596f7c
0x596f6c  8b8bf4000000                      mov    ecx,DWORD PTR [ebx+0xf4]
0x596f72  8b01                              mov    eax,DWORD PTR [ecx]
0x596f74  8b90d4000000                      mov    edx,DWORD PTR [eax+0xd4]
0x596f7a  ffd2                              call   edx
0x596f7c  807e0500                          cmp    BYTE PTR [esi+0x5],0x0
0x596f80  7442                              je     0x596fc4
0x596f82  f6051413fb0001                    test   BYTE PTR ds:0xfb1314,0x1
0x596f89  7514                              jne    0x596f9f
0x596f8b  830d1413fb0001                    or     DWORD PTR ds:0xfb1314,0x1
0x596f92  6810cfbc00                        push   0xbccf10
0x596f97  e87eb32f00                        call   0x89231a
0x596f9c  83c404                            add    esp,0x4
0x596f9f  833d98a7fb0000                    cmp    DWORD PTR ds:0xfba798,0x0
0x596fa6  c7450849000100                    mov    DWORD PTR [ebp+0x8],0x10049
0x596fad  7515                              jne    0x596fc4
0x596faf  8b0d54a8fb00                      mov    ecx,DWORD PTR ds:0xfba854
0x596fb5  8b11                              mov    edx,DWORD PTR [ecx]
0x596fb7  8b5210                            mov    edx,DWORD PTR [edx+0x10]
0x596fba  6a04                              push   0x4
0x596fbc  8d4508                            lea    eax,[ebp+0x8]
0x596fbf  50                                push   eax
0x596fc0  6a00                              push   0x0
0x596fc2  ffd2                              call   edx
0x596fc4  807e0400                          cmp    BYTE PTR [esi+0x4],0x0
0x596fc8  7409                              je     0x596fd3
0x596fca  66c783b00000000101                mov    WORD PTR [ebx+0xb0],0x101
0x596fd3  807e0800                          cmp    BYTE PTR [esi+0x8],0x0
0x596fd7  7410                              je     0x596fe9
0x596fd9  8b4e0c                            mov    ecx,DWORD PTR [esi+0xc]
0x596fdc  8b03                              mov    eax,DWORD PTR [ebx]
0x596fde  8b909c010000                      mov    edx,DWORD PTR [eax+0x19c]
0x596fe4  51                                push   ecx
0x596fe5  8bcb                              mov    ecx,ebx
0x596fe7  ffd2                              call   edx
0x596fe9  8b06                              mov    eax,DWORD PTR [esi]
0x596feb  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
0x596fee  898c83f0000000                    mov    DWORD PTR [ebx+eax*4+0xf0],ecx
0x596ff5  8b16                              mov    edx,DWORD PTR [esi]
0x596ff7  03d2                              add    edx,edx
0x596ff9  8d84d3fc000000                    lea    eax,[ebx+edx*8+0xfc]
0x597000  8b16                              mov    edx,DWORD PTR [esi]
0x597002  8910                              mov    DWORD PTR [eax],edx
0x597004  8b5604                            mov    edx,DWORD PTR [esi+0x4]
0x597007  895004                            mov    DWORD PTR [eax+0x4],edx
0x59700a  8b5608                            mov    edx,DWORD PTR [esi+0x8]
0x59700d  895008                            mov    DWORD PTR [eax+0x8],edx
0x597010  8b560c                            mov    edx,DWORD PTR [esi+0xc]
0x597013  89500c                            mov    DWORD PTR [eax+0xc],edx
0x597016  8b01                              mov    eax,DWORD PTR [ecx]
0x597018  8b90d0000000                      mov    edx,DWORD PTR [eax+0xd0]
0x59701e  ffd2                              call   edx
0x597020  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x597023  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x59702a  59                                pop    ecx
0x59702b  5f                                pop    edi
0x59702c  5b                                pop    ebx
0x59702d  8be5                              mov    esp,ebp
0x59702f  5d                                pop    ebp
0x597030  c20800                            ret    0x8

### R38 Review singleton descriptor FE2EAC and cache insertion
VA 0x5bde40 RAW 0x1bd240 END 0x5bdf14 SHA256 5471985a9f146f1c39866d1c685c446192f6845266711d752f6668b9d6260269
0x5bde40  55                                push   ebp
0x5bde41  8bec                              mov    ebp,esp
0x5bde43  6aff                              push   0xffffffff
0x5bde45  6849e69100                        push   0x91e649
0x5bde4a  64a100000000                      mov    eax,fs:0x0
0x5bde50  50                                push   eax
0x5bde51  83ec08                            sub    esp,0x8
0x5bde54  56                                push   esi
0x5bde55  57                                push   edi
0x5bde56  a1201fd600                        mov    eax,ds:0xd61f20
0x5bde5b  33c5                              xor    eax,ebp
0x5bde5d  50                                push   eax
0x5bde5e  8d45f4                            lea    eax,[ebp-0xc]
0x5bde61  64a300000000                      mov    fs:0x0,eax
0x5bde67  a1ac2efe00                        mov    eax,ds:0xfe2eac
0x5bde6c  85c0                              test   eax,eax
0x5bde6e  0f858f000000                      jne    0x5bdf03
0x5bde74  6a10                              push   0x10
0x5bde76  e8ed332d00                        call   0x891268
0x5bde7b  83c404                            add    esp,0x4
0x5bde7e  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5bde81  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5bde88  85c0                              test   eax,eax
0x5bde8a  7408                              je     0x5bde94
0x5bde8c  50                                push   eax
0x5bde8d  e80e3a0000                        call   0x5c18a0
0x5bde92  eb02                              jmp    0x5bde96
0x5bde94  33c0                              xor    eax,eax
0x5bde96  83ceff                            or     esi,0xffffffff
0x5bde99  8bc8                              mov    ecx,eax
0x5bde9b  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5bde9e  b801000000                        mov    eax,0x1
0x5bdea3  890dac2efe00                      mov    DWORD PTR ds:0xfe2eac,ecx
0x5bdea9  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x5bdeaf  7524                              jne    0x5bded5
0x5bdeb1  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x5bdeb7  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x5bdeba  e8f100e9ff                        call   0x44dfb0
0x5bdebf  6810cdbc00                        push   0xbccd10
0x5bdec4  e851442d00                        call   0x89231a
0x5bdec9  8975fc                            mov    DWORD PTR [ebp-0x4],esi
0x5bdecc  8b0dac2efe00                      mov    ecx,DWORD PTR ds:0xfe2eac
0x5bded2  83c404                            add    esp,0x4
0x5bded5  8b01                              mov    eax,DWORD PTR [ecx]
0x5bded7  8b5010                            mov    edx,DWORD PTR [eax+0x10]
0x5bdeda  8bf1                              mov    esi,ecx
0x5bdedc  ffd2                              call   edx
0x5bdede  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x5bdee1  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x5bdee4  8d7dec                            lea    edi,[ebp-0x14]
0x5bdee7  beecaffa00                        mov    esi,0xfaafec
0x5bdeec  8945ec                            mov    DWORD PTR [ebp-0x14],eax
0x5bdeef  e82c10fcff                        call   0x57ef20
0x5bdef4  50                                push   eax
0x5bdef5  56                                push   esi
0x5bdef6  8d75ec                            lea    esi,[ebp-0x14]
0x5bdef9  e802132700                        call   0x82f200
0x5bdefe  a1ac2efe00                        mov    eax,ds:0xfe2eac
0x5bdf03  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5bdf06  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5bdf0d  59                                pop    ecx
0x5bdf0e  5f                                pop    edi
0x5bdf0f  5e                                pop    esi
0x5bdf10  8be5                              mov    esp,ebp
0x5bdf12  5d                                pop    ebp
0x5bdf13  c3                                ret

### R39 Review descriptor0x123 owns newly constructed window
VA 0x5c18a0 RAW 0x1c0ca0 END 0x5c1924 SHA256 5938f3a892f4a67dcf1b21b723097b8c3a4bb85611db6b66ec7bc8ae42a81963
0x5c18a0  55                                push   ebp
0x5c18a1  8bec                              mov    ebp,esp
0x5c18a3  6aff                              push   0xffffffff
0x5c18a5  6820ae9100                        push   0x91ae20
0x5c18aa  64a100000000                      mov    eax,fs:0x0
0x5c18b0  50                                push   eax
0x5c18b1  83ec08                            sub    esp,0x8
0x5c18b4  56                                push   esi
0x5c18b5  a1201fd600                        mov    eax,ds:0xd61f20
0x5c18ba  33c5                              xor    eax,ebp
0x5c18bc  50                                push   eax
0x5c18bd  8d45f4                            lea    eax,[ebp-0xc]
0x5c18c0  64a300000000                      mov    fs:0x0,eax
0x5c18c6  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x5c18c9  c7460400000000                    mov    DWORD PTR [esi+0x4],0x0
0x5c18d0  c7460800000000                    mov    DWORD PTR [esi+0x8],0x0
0x5c18d7  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5c18de  6828010000                        push   0x128
0x5c18e3  c7067cedc100                      mov    DWORD PTR [esi],0xc1ed7c
0x5c18e9  e87a072d00                        call   0x892068
0x5c18ee  83c404                            add    esp,0x4
0x5c18f1  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x5c18f4  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x5c18f8  85c0                              test   eax,eax
0x5c18fa  7408                              je     0x5c1904
0x5c18fc  50                                push   eax
0x5c18fd  e86eaaebff                        call   0x47c370
0x5c1902  eb02                              jmp    0x5c1906
0x5c1904  33c0                              xor    eax,eax
0x5c1906  89460c                            mov    DWORD PTR [esi+0xc],eax
0x5c1909  c7460423010000                    mov    DWORD PTR [esi+0x4],0x123
0x5c1910  8bc6                              mov    eax,esi
0x5c1912  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5c1915  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5c191c  59                                pop    ecx
0x5c191d  5e                                pop    esi
0x5c191e  8be5                              mov    esp,ebp
0x5c1920  5d                                pop    ebp
0x5c1921  c20400                            ret    0x4

### R40 Descriptor getter to page+2AC binding
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

### R41 Binding stores concrete window to destination
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

### R42 Descriptor+10 getter returns +C window
VA 0x5ade20 RAW 0x1ad220 END 0x5ade24 SHA256 2e339cdc5de837ec151dbde90057caeabba18ac3ea32e7c2cffc8f95df41a6ff
0x5ade20  8b410c                            mov    eax,DWORD PTR [ecx+0xc]
0x5ade23  c3                                ret

### R43 Descriptor+4 getter returns +4 resourceID
VA 0x7b3250 RAW 0x3b2650 END 0x7b3254 SHA256 f7e0208f5e988ae39c7a45dfddbd12921d02f9c3deb5695d4c534c8ab0ccdb0f
0x7b3250  8b4104                            mov    eax,DWORD PTR [ecx+0x4]
0x7b3253  c3                                ret

### R44 Independent native callback emitsF4337; absent bulk function start
VA 0x63a130 RAW 0x239530 END 0x63a170 SHA256 22596547bc02a187840946984e801db9e89f79d8898037307c083886d407ebcf
0x63a130  56                                push   esi
0x63a131  6a14                              push   0x14
0x63a133  e830712500                        call   0x891268
0x63a138  83c404                            add    esp,0x4
0x63a13b  85c0                              test   eax,eax
0x63a13d  7426                              je     0x63a165
0x63a13f  83c9ff                            or     ecx,0xffffffff
0x63a142  8bf0                              mov    esi,eax
0x63a144  c7000c7bc400                      mov    DWORD PTR [eax],0xc47b0c
0x63a14a  894804                            mov    DWORD PTR [eax+0x4],ecx
0x63a14d  894808                            mov    DWORD PTR [eax+0x8],ecx
0x63a150  c7400c00000000                    mov    DWORD PTR [eax+0xc],0x0
0x63a157  c7401037430f00                    mov    DWORD PTR [eax+0x10],0xf4337
0x63a15e  e83dd1dcff                        call   0x4072a0
0x63a163  5e                                pop    esi
0x63a164  c3                                ret
0x63a165  33c0                              xor    eax,eax
0x63a167  8bf0                              mov    esi,eax
0x63a169  e832d1dcff                        call   0x4072a0
0x63a16e  5e                                pop    esi
0x63a16f  c3                                ret

### R45 NPC component UI578 dispatches selected callback index
VA 0x638de0 RAW 0x2381e0 END 0x638e24 SHA256 5ca9b4aabca0e883e3a9386c039c212cadb91e99650473517be3374f9b0f939e
0x638de0  55                                push   ebp
0x638de1  8bec                              mov    ebp,esp
0x638de3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x638de6  81781078050000                    cmp    DWORD PTR [eax+0x10],0x578
0x638ded  53                                push   ebx
0x638dee  8bd9                              mov    ebx,ecx
0x638df0  752d                              jne    0x638e1f
0x638df2  56                                push   esi
0x638df3  57                                push   edi
0x638df4  8db3d8000000                      lea    esi,[ebx+0xd8]
0x638dfa  bf29000000                        mov    edi,0x29
0x638dff  90                                nop
0x638e00  8b8e34ffffff                      mov    ecx,DWORD PTR [esi-0xcc]
0x638e06  8b5120                            mov    edx,DWORD PTR [ecx+0x20]
0x638e09  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x638e0c  3b5008                            cmp    edx,DWORD PTR [eax+0x8]
0x638e0f  7506                              jne    0x638e17
0x638e11  8b16                              mov    edx,DWORD PTR [esi]
0x638e13  8bcb                              mov    ecx,ebx
0x638e15  ffd2                              call   edx
0x638e17  83c604                            add    esi,0x4
0x638e1a  4f                                dec    edi
0x638e1b  75e3                              jne    0x638e00
0x638e1d  5f                                pop    edi
0x638e1e  5e                                pop    esi
0x638e1f  5b                                pop    ebx
0x638e20  5d                                pop    ebp
0x638e21  c20400                            ret    0x4

### R46 TalkBoxDialog+15C forwards to NPCcomponent+14
VA 0x636de0 RAW 0x2361e0 END 0x636e0c SHA256 03e1c88531b048287a744098a903893e36141054427acb318eb25c45e6acc61c
0x636de0  55                                push   ebp
0x636de1  8bec                              mov    ebp,esp
0x636de3  56                                push   esi
0x636de4  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x636de7  57                                push   edi
0x636de8  8bf9                              mov    edi,ecx
0x636dea  8b8fbc000000                      mov    ecx,DWORD PTR [edi+0xbc]
0x636df0  8b01                              mov    eax,DWORD PTR [ecx]
0x636df2  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x636df5  56                                push   esi
0x636df6  ffd2                              call   edx
0x636df8  817e1002440f00                    cmp    DWORD PTR [esi+0x10],0xf4402
0x636dff  7505                              jne    0x636e06
0x636e01  e80a000000                        call   0x636e10
0x636e06  5f                                pop    edi
0x636e07  5e                                pop    esi
0x636e08  5d                                pop    ebp
0x636e09  c20400                            ret    0x4

### R47 Binder+14 gets concrete caching manager FAAFD8
VA 0x585690 RAW 0x184a90 END 0x5856f2 SHA256 1f93036c8b204a3188b8d502bb558ce3673af230d14fb33947ab3dbe8db0426b
0x585690  55                                push   ebp
0x585691  8bec                              mov    ebp,esp
0x585693  6aff                              push   0xffffffff
0x585695  68de2a9100                        push   0x912ade
0x58569a  64a100000000                      mov    eax,fs:0x0
0x5856a0  50                                push   eax
0x5856a1  a1201fd600                        mov    eax,ds:0xd61f20
0x5856a6  33c5                              xor    eax,ebp
0x5856a8  50                                push   eax
0x5856a9  8d45f4                            lea    eax,[ebp-0xc]
0x5856ac  64a300000000                      mov    fs:0x0,eax
0x5856b2  b801000000                        mov    eax,0x1
0x5856b7  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
0x5856bd  751f                              jne    0x5856de
0x5856bf  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
0x5856c5  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x5856cc  e8df88ecff                        call   0x44dfb0
0x5856d1  6810cdbc00                        push   0xbccd10
0x5856d6  e83fcc3000                        call   0x89231a
0x5856db  83c404                            add    esp,0x4
0x5856de  b8d8affa00                        mov    eax,0xfaafd8
0x5856e3  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5856e6  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5856ed  59                                pop    ecx
0x5856ee  8be5                              mov    esp,ebp
0x5856f0  5d                                pop    ebp
0x5856f1  c3                                ret

### R48 Resource unlink delegates manager+30; no Lua operation
VA 0x4095e0 RAW 0x89e0 END 0x4096a3 SHA256 765083aae1757a323616aa16d5ddf88fd617b78d3f93aa36800b30bec6d840a2
0x4095e0  55                                push   ebp
0x4095e1  8bec                              mov    ebp,esp
0x4095e3  81ec0c020000                      sub    esp,0x20c
0x4095e9  a1201fd600                        mov    eax,ds:0xd61f20
0x4095ee  33c5                              xor    eax,ebp
0x4095f0  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x4095f3  53                                push   ebx
0x4095f4  56                                push   esi
0x4095f5  8bf1                              mov    esi,ecx
0x4095f7  8b06                              mov    eax,DWORD PTR [esi]
0x4095f9  8b5014                            mov    edx,DWORD PTR [eax+0x14]
0x4095fc  57                                push   edi
0x4095fd  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x409600  89bdf4fdffff                      mov    DWORD PTR [ebp-0x20c],edi
0x409606  ffd2                              call   edx
0x409608  8bd8                              mov    ebx,eax
0x40960a  8d85f4fdffff                      lea    eax,[ebp-0x20c]
0x409610  50                                push   eax
0x409611  8d4b04                            lea    ecx,[ebx+0x4]
0x409614  8d85f8fdffff                      lea    eax,[ebp-0x208]
0x40961a  e8e1584200                        call   0x82ef00
0x40961f  8b85f8fdffff                      mov    eax,DWORD PTR [ebp-0x208]
0x409625  3b4308                            cmp    eax,DWORD PTR [ebx+0x8]
0x409628  7416                              je     0x409640
0x40962a  8b4010                            mov    eax,DWORD PTR [eax+0x10]
0x40962d  85c0                              test   eax,eax
0x40962f  740f                              je     0x409640
0x409631  8b4860                            mov    ecx,DWORD PTR [eax+0x60]
0x409634  85c9                              test   ecx,ecx
0x409636  7408                              je     0x409640
0x409638  8b11                              mov    edx,DWORD PTR [ecx]
0x40963a  50                                push   eax
0x40963b  8b4274                            mov    eax,DWORD PTR [edx+0x74]
0x40963e  ffd0                              call   eax
0x409640  8b16                              mov    edx,DWORD PTR [esi]
0x409642  8b4214                            mov    eax,DWORD PTR [edx+0x14]
0x409645  8bce                              mov    ecx,esi
0x409647  ffd0                              call   eax
0x409649  8b10                              mov    edx,DWORD PTR [eax]
0x40964b  8bc8                              mov    ecx,eax
0x40964d  8b4230                            mov    eax,DWORD PTR [edx+0x30]
0x409650  57                                push   edi
0x409651  ffd0                              call   eax
0x409653  8ad8                              mov    bl,al
0x409655  84db                              test   bl,bl
0x409657  7535                              jne    0x40968e
0x409659  8b16                              mov    edx,DWORD PTR [esi]
0x40965b  8b421c                            mov    eax,DWORD PTR [edx+0x1c]
0x40965e  57                                push   edi
0x40965f  8bce                              mov    ecx,esi
0x409661  ffd0                              call   eax
0x409663  50                                push   eax
0x409664  57                                push   edi
0x409665  689827bf00                        push   0xbf2798
0x40966a  8d95fcfdffff                      lea    edx,[ebp-0x204]
0x409670  e83b180000                        call   0x40aeb0
0x409675  83c40c                            add    esp,0xc
0x409678  6a00                              push   0x0
0x40967a  68c01fbf00                        push   0xbf1fc0
0x40967f  8d8dfcfdffff                      lea    ecx,[ebp-0x204]
0x409685  51                                push   ecx
0x409686  6a00                              push   0x0
0x409688  ff158025bd00                      call   DWORD PTR ds:0xbd2580
0x40968e  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x409691  5f                                pop    edi
0x409692  5e                                pop    esi
0x409693  8ac3                              mov    al,bl
0x409695  33cd                              xor    ecx,ebp
0x409697  5b                                pop    ebx
0x409698  e864794800                        call   0x891001
0x40969d  8be5                              mov    esp,ebp
0x40969f  5d                                pop    ebp
0x4096a0  c20400                            ret    0x4

### R49 Cache hit skips window destructor; erase active map
VA 0x44e3f0 RAW 0x4d7f0 END 0x44e482 SHA256 d0a6aa3a0643d4bd4422feba6ba977e6111d09b3b20012a610c7e84724b9e9d5
0x44e3f0  55                                push   ebp
0x44e3f1  8bec                              mov    ebp,esp
0x44e3f3  83ec08                            sub    esp,0x8
0x44e3f6  53                                push   ebx
0x44e3f7  57                                push   edi
0x44e3f8  8bf9                              mov    edi,ecx
0x44e3fa  8d4508                            lea    eax,[ebp+0x8]
0x44e3fd  8d4f04                            lea    ecx,[edi+0x4]
0x44e400  50                                push   eax
0x44e401  8d45fc                            lea    eax,[ebp-0x4]
0x44e404  894df8                            mov    DWORD PTR [ebp-0x8],ecx
0x44e407  e8f40a3e00                        call   0x82ef00
0x44e40c  8b5dfc                            mov    ebx,DWORD PTR [ebp-0x4]
0x44e40f  3b5f08                            cmp    ebx,DWORD PTR [edi+0x8]
0x44e412  7464                              je     0x44e478
0x44e414  56                                push   esi
0x44e415  8b7310                            mov    esi,DWORD PTR [ebx+0x10]
0x44e418  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
0x44e41b  c1e915                            shr    ecx,0x15
0x44e41e  f6c101                            test   cl,0x1
0x44e421  7407                              je     0x44e42a
0x44e423  8bce                              mov    ecx,esi
0x44e425  e856722f00                        call   0x745680
0x44e42a  8b5604                            mov    edx,DWORD PTR [esi+0x4]
0x44e42d  8d4508                            lea    eax,[ebp+0x8]
0x44e430  50                                push   eax
0x44e431  8d4f14                            lea    ecx,[edi+0x14]
0x44e434  8d45fc                            lea    eax,[ebp-0x4]
0x44e437  895508                            mov    DWORD PTR [ebp+0x8],edx
0x44e43a  e8c10a3e00                        call   0x82ef00
0x44e43f  8b08                              mov    ecx,DWORD PTR [eax]
0x44e441  3b4f18                            cmp    ecx,DWORD PTR [edi+0x18]
0x44e444  7519                              jne    0x44e45f
0x44e446  8bce                              mov    ecx,esi
0x44e448  e833872f00                        call   0x746b80
0x44e44d  8bce                              mov    ecx,esi
0x44e44f  e8bc872f00                        call   0x746c10
0x44e454  8b16                              mov    edx,DWORD PTR [esi]
0x44e456  8b421c                            mov    eax,DWORD PTR [edx+0x1c]
0x44e459  6a01                              push   0x1
0x44e45b  8bce                              mov    ecx,esi
0x44e45d  ffd0                              call   eax
0x44e45f  8b55f8                            mov    edx,DWORD PTR [ebp-0x8]
0x44e462  53                                push   ebx
0x44e463  8d4d08                            lea    ecx,[ebp+0x8]
0x44e466  51                                push   ecx
0x44e467  52                                push   edx
0x44e468  e823843600                        call   0x7b6890
0x44e46d  5e                                pop    esi
0x44e46e  5f                                pop    edi
0x44e46f  b001                              mov    al,0x1
0x44e471  5b                                pop    ebx
0x44e472  8be5                              mov    esp,ebp
0x44e474  5d                                pop    ebp
0x44e475  c20400                            ret    0x4
0x44e478  5f                                pop    edi
0x44e479  32c0                              xor    al,al
0x44e47b  5b                                pop    ebx
0x44e47c  8be5                              mov    esp,ebp
0x44e47e  5d                                pop    ebp
0x44e47f  c20400                            ret    0x4

### R50 Unload calls window+10C then dynamic child unload
VA 0x745680 RAW 0x344a80 END 0x7456ef SHA256 fd503287fb335b5579f9c74a1e33c7576ddd3a94b079ac34ad43197442053d71
0x745680  56                                push   esi
0x745681  8bf1                              mov    esi,ecx
0x745683  8b06                              mov    eax,DWORD PTR [esi]
0x745685  8b900c010000                      mov    edx,DWORD PTR [eax+0x10c]
0x74568b  81762800002000                    xor    DWORD PTR [esi+0x28],0x200000
0x745692  57                                push   edi
0x745693  ffd2                              call   edx
0x745695  8b7e50                            mov    edi,DWORD PTR [esi+0x50]
0x745698  8b37                              mov    esi,DWORD PTR [edi]
0x74569a  3bf7                              cmp    esi,edi
0x74569c  744e                              je     0x7456ec
0x74569e  8bff                              mov    edi,edi
0x7456a0  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
0x7456a3  e8d8ffffff                        call   0x745680
0x7456a8  807e1500                          cmp    BYTE PTR [esi+0x15],0x0
0x7456ac  753a                              jne    0x7456e8
0x7456ae  8b4608                            mov    eax,DWORD PTR [esi+0x8]
0x7456b1  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x7456b5  7516                              jne    0x7456cd
0x7456b7  8bf0                              mov    esi,eax
0x7456b9  8b06                              mov    eax,DWORD PTR [esi]
0x7456bb  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x7456bf  7527                              jne    0x7456e8
0x7456c1  8bf0                              mov    esi,eax
0x7456c3  8b06                              mov    eax,DWORD PTR [esi]
0x7456c5  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x7456c9  74f6                              je     0x7456c1
0x7456cb  eb1b                              jmp    0x7456e8
0x7456cd  8b4604                            mov    eax,DWORD PTR [esi+0x4]
0x7456d0  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x7456d4  7510                              jne    0x7456e6
0x7456d6  3b7008                            cmp    esi,DWORD PTR [eax+0x8]
0x7456d9  750b                              jne    0x7456e6
0x7456db  8bf0                              mov    esi,eax
0x7456dd  8b4004                            mov    eax,DWORD PTR [eax+0x4]
0x7456e0  80781500                          cmp    BYTE PTR [eax+0x15],0x0
0x7456e4  74f0                              je     0x7456d6
0x7456e6  8bf0                              mov    esi,eax
0x7456e8  3bf7                              cmp    esi,edi
0x7456ea  75b4                              jne    0x7456a0
0x7456ec  5f                                pop    edi
0x7456ed  5e                                pop    esi
0x7456ee  c3                                ret

### R51 Review window own load/unload empty
VA 0x5f5d10 RAW 0x1f5110 END 0x5f5d11 SHA256 ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e
0x5f5d10  c3                                ret

### R52 Review window destructor native tree then UI base
VA 0x47c510 RAW 0x7b910 END 0x47c59a SHA256 e26d1eb25b51bc1b3b5ca10c8491431701ddfe3165882c9dc765446b75afb6fd
0x47c510  55                                push   ebp
0x47c511  8bec                              mov    ebp,esp
0x47c513  6aff                              push   0xffffffff
0x47c515  6810b89100                        push   0x91b810
0x47c51a  64a100000000                      mov    eax,fs:0x0
0x47c520  50                                push   eax
0x47c521  83ec0c                            sub    esp,0xc
0x47c524  53                                push   ebx
0x47c525  56                                push   esi
0x47c526  57                                push   edi
0x47c527  a1201fd600                        mov    eax,ds:0xd61f20
0x47c52c  33c5                              xor    eax,ebp
0x47c52e  50                                push   eax
0x47c52f  8d45f4                            lea    eax,[ebp-0xc]
0x47c532  64a300000000                      mov    fs:0x0,eax
0x47c538  8bf9                              mov    edi,ecx
0x47c53a  897df0                            mov    DWORD PTR [ebp-0x10],edi
0x47c53d  c7072c31c000                      mov    DWORD PTR [edi],0xc0312c
0x47c543  8d9f0c010000                      lea    ebx,[edi+0x10c]
0x47c549  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x47c550  895dec                            mov    DWORD PTR [ebp-0x14],ebx
0x47c553  c645fc01                          mov    BYTE PTR [ebp-0x4],0x1
0x47c557  8b4304                            mov    eax,DWORD PTR [ebx+0x4]
0x47c55a  8b08                              mov    ecx,DWORD PTR [eax]
0x47c55c  50                                push   eax
0x47c55d  51                                push   ecx
0x47c55e  8d75e8                            lea    esi,[ebp-0x18]
0x47c561  8bc3                              mov    eax,ebx
0x47c563  e8587b0d00                        call   0x5540c0
0x47c568  8b5b04                            mov    ebx,DWORD PTR [ebx+0x4]
0x47c56b  53                                push   ebx
0x47c56c  e89b4c4100                        call   0x89120c
0x47c571  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x47c578  83c404                            add    esp,0x4
0x47c57b  8bcf                              mov    ecx,edi
0x47c57d  c707cc82c400                      mov    DWORD PTR [edi],0xc482cc
0x47c583  e808a02d00                        call   0x756590
0x47c588  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47c58b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47c592  59                                pop    ecx
0x47c593  5f                                pop    edi
0x47c594  5e                                pop    esi
0x47c595  5b                                pop    ebx
0x47c596  8be5                              mov    esp,ebp
0x47c598  5d                                pop    ebp
0x47c599  c3                                ret

### R53 SceneItem destructor string/base; no named T remove
VA 0x47b520 RAW 0x7a920 END 0x47b5b5 SHA256 44177afe37c3f843cbb00b621657236c282431a2c4160aa59653b4cb60e21d89
0x47b520  55                                push   ebp
0x47b521  8bec                              mov    ebp,esp
0x47b523  6aff                              push   0xffffffff
0x47b525  6838d49100                        push   0x91d438
0x47b52a  64a100000000                      mov    eax,fs:0x0
0x47b530  50                                push   eax
0x47b531  51                                push   ecx
0x47b532  56                                push   esi
0x47b533  a1201fd600                        mov    eax,ds:0xd61f20
0x47b538  33c5                              xor    eax,ebp
0x47b53a  50                                push   eax
0x47b53b  8d45f4                            lea    eax,[ebp-0xc]
0x47b53e  64a300000000                      mov    fs:0x0,eax
0x47b544  8bf1                              mov    esi,ecx
0x47b546  8975f0                            mov    DWORD PTR [ebp-0x10],esi
0x47b549  c7063c2fc000                      mov    DWORD PTR [esi],0xc02f3c
0x47b54f  83be6402000008                    cmp    DWORD PTR [esi+0x264],0x8
0x47b556  720f                              jb     0x47b567
0x47b558  8b8650020000                      mov    eax,DWORD PTR [esi+0x250]
0x47b55e  50                                push   eax
0x47b55f  e8a85c4100                        call   0x89120c
0x47b564  83c404                            add    esp,0x4
0x47b567  33c0                              xor    eax,eax
0x47b569  c7866402000007000000              mov    DWORD PTR [esi+0x264],0x7
0x47b573  898660020000                      mov    DWORD PTR [esi+0x260],eax
0x47b579  33c9                              xor    ecx,ecx
0x47b57b  66898e50020000                    mov    WORD PTR [esi+0x250],cx
0x47b582  c706dc67c400                      mov    DWORD PTR [esi],0xc467dc
0x47b588  8d965c010000                      lea    edx,[esi+0x15c]
0x47b58e  52                                push   edx
0x47b58f  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x47b592  e859003000                        call   0x77b5f0
0x47b597  8bce                              mov    ecx,esi
0x47b599  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x47b5a0  e8db932d00                        call   0x754980
0x47b5a5  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47b5a8  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47b5af  59                                pop    ecx
0x47b5b0  5e                                pop    esi
0x47b5b1  8be5                              mov    esp,ebp
0x47b5b3  5d                                pop    ebp
0x47b5b4  c3                                ret

### R54 Ordinary Mission page+184→59B1F0; dynamic UI children retained
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

### R55 Ordinary Scenario page+184→59B1F0 and own windows
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

### R56 Shared FieldPage base update; explicitly bounded dynamic callbacks
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

### R57 Lobby leave contains resource123 unlink
VA 0x5b5f90 RAW 0x1b5390 END 0x5b6245 SHA256 8d0dc26170683a7c3a932c96e684f56daec78b3b383f89125b9964a598293810
0x5b5f90  55                                push   ebp
0x5b5f91  8bec                              mov    ebp,esp
0x5b5f93  6aff                              push   0xffffffff
0x5b5f95  68a02c9200                        push   0x922ca0
0x5b5f9a  64a100000000                      mov    eax,fs:0x0
0x5b5fa0  50                                push   eax
0x5b5fa1  83ec14                            sub    esp,0x14
0x5b5fa4  56                                push   esi
0x5b5fa5  a1201fd600                        mov    eax,ds:0xd61f20
0x5b5faa  33c5                              xor    eax,ebp
0x5b5fac  50                                push   eax
0x5b5fad  8d45f4                            lea    eax,[ebp-0xc]
0x5b5fb0  64a300000000                      mov    fs:0x0,eax
0x5b5fb6  e8d535feff                        call   0x599590
0x5b5fbb  33f6                              xor    esi,esi
0x5b5fbd  8975e4                            mov    DWORD PTR [ebp-0x1c],esi
0x5b5fc0  8975e8                            mov    DWORD PTR [ebp-0x18],esi
0x5b5fc3  8975ec                            mov    DWORD PTR [ebp-0x14],esi
0x5b5fc6  c745e00c92c100                    mov    DWORD PTR [ebp-0x20],0xc1920c
0x5b5fcd  393570fcf700                      cmp    DWORD PTR ds:0xf7fc70,esi
0x5b5fd3  7406                              je     0x5b5fdb
0x5b5fd5  893570fcf700                      mov    DWORD PTR ds:0xf7fc70,esi
0x5b5fdb  6a5e                              push   0x5e
0x5b5fdd  8d4de0                            lea    ecx,[ebp-0x20]
0x5b5fe0  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
0x5b5fe7  e8f435e5ff                        call   0x4095e0
0x5b5fec  68d2000000                        push   0xd2
0x5b5ff1  8d4de0                            lea    ecx,[ebp-0x20]
0x5b5ff4  e8e735e5ff                        call   0x4095e0
0x5b5ff9  6a58                              push   0x58
0x5b5ffb  8d4de0                            lea    ecx,[ebp-0x20]
0x5b5ffe  e8dd35e5ff                        call   0x4095e0
0x5b6003  6a59                              push   0x59
0x5b6005  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6008  e8d335e5ff                        call   0x4095e0
0x5b600d  6a5c                              push   0x5c
0x5b600f  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6012  e8c935e5ff                        call   0x4095e0
0x5b6017  6a57                              push   0x57
0x5b6019  8d4de0                            lea    ecx,[ebp-0x20]
0x5b601c  e8bf35e5ff                        call   0x4095e0
0x5b6021  6a20                              push   0x20
0x5b6023  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6026  e8b535e5ff                        call   0x4095e0
0x5b602b  688e000000                        push   0x8e
0x5b6030  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6033  e8a835e5ff                        call   0x4095e0
0x5b6038  688f000000                        push   0x8f
0x5b603d  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6040  e89b35e5ff                        call   0x4095e0
0x5b6045  6890000000                        push   0x90
0x5b604a  8d4de0                            lea    ecx,[ebp-0x20]
0x5b604d  e88e35e5ff                        call   0x4095e0
0x5b6052  6891000000                        push   0x91
0x5b6057  8d4de0                            lea    ecx,[ebp-0x20]
0x5b605a  e88135e5ff                        call   0x4095e0
0x5b605f  6a10                              push   0x10
0x5b6061  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6064  e87735e5ff                        call   0x4095e0
0x5b6069  68ad000000                        push   0xad
0x5b606e  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6071  e86a35e5ff                        call   0x4095e0
0x5b6076  68ae000000                        push   0xae
0x5b607b  8d4de0                            lea    ecx,[ebp-0x20]
0x5b607e  e85d35e5ff                        call   0x4095e0
0x5b6083  68af000000                        push   0xaf
0x5b6088  8d4de0                            lea    ecx,[ebp-0x20]
0x5b608b  e85035e5ff                        call   0x4095e0
0x5b6090  68b0000000                        push   0xb0
0x5b6095  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6098  e84335e5ff                        call   0x4095e0
0x5b609d  68b1000000                        push   0xb1
0x5b60a2  8d4de0                            lea    ecx,[ebp-0x20]
0x5b60a5  e83635e5ff                        call   0x4095e0
0x5b60aa  68b2000000                        push   0xb2
0x5b60af  8d4de0                            lea    ecx,[ebp-0x20]
0x5b60b2  e82935e5ff                        call   0x4095e0
0x5b60b7  68b3000000                        push   0xb3
0x5b60bc  8d4de0                            lea    ecx,[ebp-0x20]
0x5b60bf  e81c35e5ff                        call   0x4095e0
0x5b60c4  68a3000000                        push   0xa3
0x5b60c9  8d4de0                            lea    ecx,[ebp-0x20]
0x5b60cc  e80f35e5ff                        call   0x4095e0
0x5b60d1  68d6000000                        push   0xd6
0x5b60d6  8d4de0                            lea    ecx,[ebp-0x20]
0x5b60d9  e80235e5ff                        call   0x4095e0
0x5b60de  68d5000000                        push   0xd5
0x5b60e3  8d4de0                            lea    ecx,[ebp-0x20]
0x5b60e6  e8f534e5ff                        call   0x4095e0
0x5b60eb  68d7000000                        push   0xd7
0x5b60f0  8d4de0                            lea    ecx,[ebp-0x20]
0x5b60f3  e8e834e5ff                        call   0x4095e0
0x5b60f8  68d3000000                        push   0xd3
0x5b60fd  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6100  e8db34e5ff                        call   0x4095e0
0x5b6105  68ee000000                        push   0xee
0x5b610a  8d4de0                            lea    ecx,[ebp-0x20]
0x5b610d  e8ce34e5ff                        call   0x4095e0
0x5b6112  6806010000                        push   0x106
0x5b6117  8d4de0                            lea    ecx,[ebp-0x20]
0x5b611a  e8c134e5ff                        call   0x4095e0
0x5b611f  6a6e                              push   0x6e
0x5b6121  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6124  e8b734e5ff                        call   0x4095e0
0x5b6129  6a71                              push   0x71
0x5b612b  8d4de0                            lea    ecx,[ebp-0x20]
0x5b612e  e8ad34e5ff                        call   0x4095e0
0x5b6133  6a72                              push   0x72
0x5b6135  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6138  e8a334e5ff                        call   0x4095e0
0x5b613d  68b4000000                        push   0xb4
0x5b6142  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6145  e89634e5ff                        call   0x4095e0
0x5b614a  68b5000000                        push   0xb5
0x5b614f  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6152  e88934e5ff                        call   0x4095e0
0x5b6157  68b6000000                        push   0xb6
0x5b615c  8d4de0                            lea    ecx,[ebp-0x20]
0x5b615f  e87c34e5ff                        call   0x4095e0
0x5b6164  68b8000000                        push   0xb8
0x5b6169  8d4de0                            lea    ecx,[ebp-0x20]
0x5b616c  e86f34e5ff                        call   0x4095e0
0x5b6171  6823010000                        push   0x123
0x5b6176  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6179  e86234e5ff                        call   0x4095e0
0x5b617e  6a56                              push   0x56
0x5b6180  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6183  e85834e5ff                        call   0x4095e0
0x5b6188  6825010000                        push   0x125
0x5b618d  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6190  e84b34e5ff                        call   0x4095e0
0x5b6195  6827010000                        push   0x127
0x5b619a  8d4de0                            lea    ecx,[ebp-0x20]
0x5b619d  e83e34e5ff                        call   0x4095e0
0x5b61a2  682c010000                        push   0x12c
0x5b61a7  8d4de0                            lea    ecx,[ebp-0x20]
0x5b61aa  e83134e5ff                        call   0x4095e0
0x5b61af  682f010000                        push   0x12f
0x5b61b4  8d4de0                            lea    ecx,[ebp-0x20]
0x5b61b7  e82434e5ff                        call   0x4095e0
0x5b61bc  6830010000                        push   0x130
0x5b61c1  8d4de0                            lea    ecx,[ebp-0x20]
0x5b61c4  e81734e5ff                        call   0x4095e0
0x5b61c9  6835010000                        push   0x135
0x5b61ce  8d4de0                            lea    ecx,[ebp-0x20]
0x5b61d1  e80a34e5ff                        call   0x4095e0
0x5b61d6  6836010000                        push   0x136
0x5b61db  8d4de0                            lea    ecx,[ebp-0x20]
0x5b61de  e8fd33e5ff                        call   0x4095e0
0x5b61e3  6837010000                        push   0x137
0x5b61e8  8d4de0                            lea    ecx,[ebp-0x20]
0x5b61eb  e8f033e5ff                        call   0x4095e0
0x5b61f0  683a010000                        push   0x13a
0x5b61f5  8d4de0                            lea    ecx,[ebp-0x20]
0x5b61f8  e8e333e5ff                        call   0x4095e0
0x5b61fd  683b010000                        push   0x13b
0x5b6202  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6205  e8d633e5ff                        call   0x4095e0
0x5b620a  6a4a                              push   0x4a
0x5b620c  8d4de0                            lea    ecx,[ebp-0x20]
0x5b620f  e8cc33e5ff                        call   0x4095e0
0x5b6214  6a49                              push   0x49
0x5b6216  8d4de0                            lea    ecx,[ebp-0x20]
0x5b6219  e8c233e5ff                        call   0x4095e0
0x5b621e  8b45e4                            mov    eax,DWORD PTR [ebp-0x1c]
0x5b6221  c745e0e429bf00                    mov    DWORD PTR [ebp-0x20],0xbf29e4
0x5b6228  3bc6                              cmp    eax,esi
0x5b622a  7409                              je     0x5b6235
0x5b622c  50                                push   eax
0x5b622d  e8daaf2d00                        call   0x89120c
0x5b6232  83c404                            add    esp,0x4
0x5b6235  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x5b6238  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x5b623f  59                                pop    ecx
0x5b6240  5e                                pop    esi
0x5b6241  8be5                              mov    esp,ebp
0x5b6243  5d                                pop    ebp
0x5b6244  c3                                ret

### R58 0x12D is shared content-button interface type result
VA 0x403df0 RAW 0x31f0 END 0x403df6 SHA256 bd07eb3200ba48d345efdd2ab715ae7353b3f983db05f2d595d7a198da3baa7b
0x403df0  b82d010000                        mov    eax,0x12d
0x403df5  c3                                ret

### R59 Review hide vtable thunk→4067F0
VA 0x44db00 RAW 0x4cf00 END 0x44db05 SHA256 6d538673c46eb2df0b2ef9232ef4a9a462b27fa0fa67b6848f6cfc331883b070
0x44db00  e9eb8cfbff                        jmp    0x4067f0

### R60 Review window concrete constructor (through normal return)
VA 0x47c370 RAW 0x7b770 END 0x47c4d9 SHA256 9ad53db81825242923062975297ea14db89b0d38e3e4d04e06819770d9ea6702
0x47c370  55                                push   ebp
0x47c371  8bec                              mov    ebp,esp
0x47c373  6aff                              push   0xffffffff
0x47c375  68b37a9200                        push   0x927ab3
0x47c37a  64a100000000                      mov    eax,fs:0x0
0x47c380  50                                push   eax
0x47c381  83ec10                            sub    esp,0x10
0x47c384  53                                push   ebx
0x47c385  56                                push   esi
0x47c386  57                                push   edi
0x47c387  a1201fd600                        mov    eax,ds:0xd61f20
0x47c38c  33c5                              xor    eax,ebp
0x47c38e  50                                push   eax
0x47c38f  8d45f4                            lea    eax,[ebp-0xc]
0x47c392  64a300000000                      mov    fs:0x0,eax
0x47c398  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x47c39b  8bce                              mov    ecx,esi
0x47c39d  e83ea12d00                        call   0x7564e0
0x47c3a2  33ff                              xor    edi,edi
0x47c3a4  bb01000000                        mov    ebx,0x1
0x47c3a9  89beec000000                      mov    DWORD PTR [esi+0xec],edi
0x47c3af  889ef0000000                      mov    BYTE PTR [esi+0xf0],bl
0x47c3b5  897dfc                            mov    DWORD PTR [ebp-0x4],edi
0x47c3b8  c7062c31c000                      mov    DWORD PTR [esi],0xc0312c
0x47c3be  89bef4000000                      mov    DWORD PTR [esi+0xf4],edi
0x47c3c4  89bef8000000                      mov    DWORD PTR [esi+0xf8],edi
0x47c3ca  89befc000000                      mov    DWORD PTR [esi+0xfc],edi
0x47c3d0  89be00010000                      mov    DWORD PTR [esi+0x100],edi
0x47c3d6  89be04010000                      mov    DWORD PTR [esi+0x104],edi
0x47c3dc  89be08010000                      mov    DWORD PTR [esi+0x108],edi
0x47c3e2  6a18                              push   0x18
0x47c3e4  89be14010000                      mov    DWORD PTR [esi+0x114],edi
0x47c3ea  e8794e4100                        call   0x891268
0x47c3ef  83c404                            add    esp,0x4
0x47c3f2  3bc7                              cmp    eax,edi
0x47c3f4  0f84b9000000                      je     0x47c4b3
0x47c3fa  898610010000                      mov    DWORD PTR [esi+0x110],eax
0x47c400  8900                              mov    DWORD PTR [eax],eax
0x47c402  8b8610010000                      mov    eax,DWORD PTR [esi+0x110]
0x47c408  894004                            mov    DWORD PTR [eax+0x4],eax
0x47c40b  8b8610010000                      mov    eax,DWORD PTR [esi+0x110]
0x47c411  894008                            mov    DWORD PTR [eax+0x8],eax
0x47c414  8b8610010000                      mov    eax,DWORD PTR [esi+0x110]
0x47c41a  885814                            mov    BYTE PTR [eax+0x14],bl
0x47c41d  8b8e10010000                      mov    ecx,DWORD PTR [esi+0x110]
0x47c423  885915                            mov    BYTE PTR [ecx+0x15],bl
0x47c426  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x47c429  89be1c010000                      mov    DWORD PTR [esi+0x11c],edi
0x47c42f  89be20010000                      mov    DWORD PTR [esi+0x120],edi
0x47c435  89be24010000                      mov    DWORD PTR [esi+0x124],edi
0x47c43b  841d640ffc00                      test   BYTE PTR ds:0xfc0f64,bl
0x47c441  751f                              jne    0x47c462
0x47c443  091d640ffc00                      or     DWORD PTR ds:0xfc0f64,ebx
0x47c449  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x47c44d  e88e180000                        call   0x47dce0
0x47c452  68f0dabc00                        push   0xbcdaf0
0x47c457  e8be5e4100                        call   0x89231a
0x47c45c  83c404                            add    esp,0x4
0x47c45f  885dfc                            mov    BYTE PTR [ebp-0x4],bl
0x47c462  8b15780ffc00                      mov    edx,DWORD PTR ds:0xfc0f78
0x47c468  89961c010000                      mov    DWORD PTR [esi+0x11c],edx
0x47c46e  841d640ffc00                      test   BYTE PTR ds:0xfc0f64,bl
0x47c474  751c                              jne    0x47c492
0x47c476  091d640ffc00                      or     DWORD PTR ds:0xfc0f64,ebx
0x47c47c  c645fc03                          mov    BYTE PTR [ebp-0x4],0x3
0x47c480  e85b180000                        call   0x47dce0
0x47c485  68f0dabc00                        push   0xbcdaf0
0x47c48a  e88b5e4100                        call   0x89231a
0x47c48f  83c404                            add    esp,0x4
0x47c492  a17c0ffc00                        mov    eax,ds:0xfc0f7c
0x47c497  898620010000                      mov    DWORD PTR [esi+0x120],eax
0x47c49d  8bc6                              mov    eax,esi
0x47c49f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x47c4a2  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x47c4a9  59                                pop    ecx
0x47c4aa  5f                                pop    edi
0x47c4ab  5e                                pop    esi
0x47c4ac  5b                                pop    ebx
0x47c4ad  8be5                              mov    esp,ebp
0x47c4af  5d                                pop    ebp
0x47c4b0  c20400                            ret    0x4
0x47c4b3  8d4df0                            lea    ecx,[ebp-0x10]
0x47c4b6  51                                push   ecx
0x47c4b7  8d4de4                            lea    ecx,[ebp-0x1c]
0x47c4ba  897df0                            mov    DWORD PTR [ebp-0x10],edi
0x47c4bd  e8e74b4100                        call   0x8910a9
0x47c4c2  68a857c800                        push   0xc857a8
0x47c4c7  8d55e4                            lea    edx,[ebp-0x1c]
0x47c4ca  52                                push   edx
0x47c4cb  c745e4a42cbd00                    mov    DWORD PTR [ebp-0x1c],0xbd2ca4
0x47c4d2  e819054200                        call   0x89c9f0
0x47c4d7  cc                                int3
0x47c4d8  cc                                int3

### R61 NPC contentbutton lookup accepts type12D and stores returned pointer
VA 0x615fc0 RAW 0x2153c0 END 0x6160a7 SHA256 be68705af4a3676e8ea494032c539bfbb42cf946c8cf478bbd2b2cb03ed266b6
0x615fc0  55                                push   ebp
0x615fc1  8bec                              mov    ebp,esp
0x615fc3  83ec20                            sub    esp,0x20
0x615fc6  a1201fd600                        mov    eax,ds:0xd61f20
0x615fcb  33c5                              xor    eax,ebp
0x615fcd  8945fc                            mov    DWORD PTR [ebp-0x4],eax
0x615fd0  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x615fd3  56                                push   esi
0x615fd4  8bf1                              mov    esi,ecx
0x615fd6  50                                push   eax
0x615fd7  e864091300                        call   0x746940
0x615fdc  8bf0                              mov    esi,eax
0x615fde  85f6                              test   esi,esi
0x615fe0  7552                              jne    0x616034
0x615fe2  b95c1fbf00                        mov    ecx,0xbf1f5c
0x615fe7  b8681fbf00                        mov    eax,0xbf1f68
0x615fec  8d75e0                            lea    esi,[ebp-0x20]
0x615fef  e88ceadeff                        call   0x404a80
0x615ff4  8b45e0                            mov    eax,DWORD PTR [ebp-0x20]
0x615ff7  be08000000                        mov    esi,0x8
0x615ffc  3975f4                            cmp    DWORD PTR [ebp-0xc],esi
0x615fff  7303                              jae    0x616004
0x616001  8d45e0                            lea    eax,[ebp-0x20]
0x616004  6a00                              push   0x0
0x616006  68c01fbf00                        push   0xbf1fc0
0x61600b  50                                push   eax
0x61600c  6a00                              push   0x0
0x61600e  ff158025bd00                      call   DWORD PTR ds:0xbd2580
0x616014  3975f4                            cmp    DWORD PTR [ebp-0xc],esi
0x616017  727f                              jb     0x616098
0x616019  8b45e0                            mov    eax,DWORD PTR [ebp-0x20]
0x61601c  50                                push   eax
0x61601d  e8eab12700                        call   0x89120c
0x616022  83c404                            add    esp,0x4
0x616025  5e                                pop    esi
0x616026  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x616029  33cd                              xor    ecx,ebp
0x61602b  e8d1af2700                        call   0x891001
0x616030  8be5                              mov    esp,ebp
0x616032  5d                                pop    ebp
0x616033  c3                                ret
0x616034  8b16                              mov    edx,DWORD PTR [esi]
0x616036  8b4204                            mov    eax,DWORD PTR [edx+0x4]
0x616039  8bce                              mov    ecx,esi
0x61603b  ffd0                              call   eax
0x61603d  3d2d010000                        cmp    eax,0x12d
0x616042  7452                              je     0x616096
0x616044  b95c1fbf00                        mov    ecx,0xbf1f5c
0x616049  b8d01fbf00                        mov    eax,0xbf1fd0
0x61604e  8d75e0                            lea    esi,[ebp-0x20]
0x616051  e82aeadeff                        call   0x404a80
0x616056  8b45e0                            mov    eax,DWORD PTR [ebp-0x20]
0x616059  be08000000                        mov    esi,0x8
0x61605e  3975f4                            cmp    DWORD PTR [ebp-0xc],esi
0x616061  7303                              jae    0x616066
0x616063  8d45e0                            lea    eax,[ebp-0x20]
0x616066  6a00                              push   0x0
0x616068  68c01fbf00                        push   0xbf1fc0
0x61606d  50                                push   eax
0x61606e  6a00                              push   0x0
0x616070  ff158025bd00                      call   DWORD PTR ds:0xbd2580
0x616076  3975f4                            cmp    DWORD PTR [ebp-0xc],esi
0x616079  721d                              jb     0x616098
0x61607b  8b4de0                            mov    ecx,DWORD PTR [ebp-0x20]
0x61607e  51                                push   ecx
0x61607f  e888b12700                        call   0x89120c
0x616084  83c404                            add    esp,0x4
0x616087  5e                                pop    esi
0x616088  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x61608b  33cd                              xor    ecx,ebp
0x61608d  e86faf2700                        call   0x891001
0x616092  8be5                              mov    esp,ebp
0x616094  5d                                pop    ebp
0x616095  c3                                ret
0x616096  8937                              mov    DWORD PTR [edi],esi
0x616098  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
0x61609b  33cd                              xor    ecx,ebp
0x61609d  5e                                pop    esi
0x61609e  e85eaf2700                        call   0x891001
0x6160a3  8be5                              mov    esp,ebp
0x6160a5  5d                                pop    ebp
0x6160a6  c3                                ret

### A01 006E direct registration FD306C=4B9260
VA 0x4b7e1f RAW 0xb721f END 0x4b7e29 SHA256 c718baf3320f4eebc2782f563d85437259505a58a08345e98b3b0c2eb8b5bb45
0x4b7e1f  c7056c30fd0060924b00              mov    DWORD PTR ds:0xfd306c,0x4b9260

### A02 Lobby init descriptor→address of page+2AC
VA 0x5b5597 RAW 0x1b4997 END 0x5b55aa SHA256 c001bd4b992cdcec991b21f44bd4b504a8896b85afb54f6017079af6b5091d61
0x5b5597  8db3ac020000                      lea    esi,[ebx+0x2ac]
0x5b559d  e89e880000                        call   0x5bde40
0x5b55a2  56                                push   esi
0x5b55a3  8bc8                              mov    ecx,eax
0x5b55a5  e89649ffff                        call   0x5a9f40

### A03 Register review window group1 flags1,1,0,0,0
VA 0x5b5b8f RAW 0x1b4f8f END 0x5b5bab SHA256 2afcb80af348bb1fd90edef764b376dcf984a93ac278da412ec1045dacfae8b0
0x5b5b8f  8b83ac020000                      mov    eax,DWORD PTR [ebx+0x2ac]
0x5b5b95  6a00                              push   0x0
0x5b5b97  6a00                              push   0x0
0x5b5b99  6a00                              push   0x0
0x5b5b9b  6a01                              push   0x1
0x5b5b9d  6a01                              push   0x1
0x5b5b9f  50                                push   eax
0x5b5ba0  53                                push   ebx
0x5b5ba1  b801000000                        mov    eax,0x1
0x5b5ba6  e8c511feff                        call   0x596d70

### A04 Lobby+18C F42DB-based switch dispatch
VA 0x5b7750 RAW 0x1b6b50 END 0x5b7780 SHA256 4c41464716bdb23c79ca113c975a47e7ed08e130dd054368dcffa9ed362ff5f0
0x5b7750  55                                push   ebp
0x5b7751  8bec                              mov    ebp,esp
0x5b7753  53                                push   ebx
0x5b7754  56                                push   esi
0x5b7755  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x5b7758  56                                push   esi
0x5b7759  8bd9                              mov    ebx,ecx
0x5b775b  e8c03cfeff                        call   0x59b420
0x5b7760  8b4610                            mov    eax,DWORD PTR [esi+0x10]
0x5b7763  0525bdf0ff                        add    eax,0xfff0bd25
0x5b7768  83f86e                            cmp    eax,0x6e
0x5b776b  0f8746030000                      ja     0x5b7ab7
0x5b7771  0fb680707b5b00                    movzx  eax,BYTE PTR [eax+0x5b7b70]
0x5b7778  57                                push   edi
0x5b7779  ff2485c07a5b00                    jmp    DWORD PTR [eax*4+0x5b7ac0]

### A05 F4337 switch target→5BAF70
VA 0x5b7981 RAW 0x1b6d81 END 0x5b798f SHA256 c85d636be0c36efcc1b1cf25168451603435abeb3aa9e308294ea7db656910d0
0x5b7981  8bf3                              mov    esi,ebx
0x5b7983  e8e8350000                        call   0x5baf70
0x5b7988  5f                                pop    edi
0x5b7989  5e                                pop    esi
0x5b798a  5b                                pop    ebx
0x5b798b  5d                                pop    ebp
0x5b798c  c20400                            ret    0x4

### A06 NPC callback slot+158=63A130
VA 0x63882e RAW 0x237c2e END 0x638838 SHA256 618ca8767f7fde4ccd8f19c1eeee12f86c216a582281a947ad4eae7e3e6065c5
0x63882e  c7815801000030a16300              mov    DWORD PTR [ecx+0x158],0x63a130

### A07 Control0x776 is stored at NPCcomponent+8C
VA 0x638d23 RAW 0x238123 END 0x638d36 SHA256 7560c9aaf4936ead60709c99de035e2f6dade27280283523c7469a93720dbb44
0x638d23  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
0x638d26  6876070000                        push   0x776
0x638d2b  8dbe8c000000                      lea    edi,[esi+0x8c]
0x638d31  e88ad2fdff                        call   0x615fc0

### A08 CTalkBoxNpc vptr
VA 0x6370e8 RAW 0x2364e8 END 0x637102 SHA256 ef81c58a5eb79f68b5c353003c7c9f4df3fa2216f3b1fc81c1017714b96f3153
0x6370e8  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x6370eb  68a4000000                        push   0xa4
0x6370f0  33f6                              xor    esi,esi
0x6370f2  8d470c                            lea    eax,[edi+0xc]
0x6370f5  56                                push   esi
0x6370f6  50                                push   eax
0x6370f7  c70788e5c200                      mov    DWORD PTR [edi],0xc2e588
0x6370fd  e85e772600                        call   0x89e860

### A09 TalkBoxDialog constructs NPCcomponent+BC, backpointer+4
VA 0x6359d0 RAW 0x234dd0 END 0x635a48 SHA256 ad48aa4cae0e03e53c775d2df150bdab0720d63d354dcccf4fe52ba0689c2067
0x6359d0  6880010000                        push   0x180
0x6359d5  66899eb4000000                    mov    WORD PTR [esi+0xb4],bx
0x6359dc  899eb8000000                      mov    DWORD PTR [esi+0xb8],ebx
0x6359e2  e881b82500                        call   0x891268
0x6359e7  83c404                            add    esp,0x4
0x6359ea  8945f0                            mov    DWORD PTR [ebp-0x10],eax
0x6359ed  c645fc02                          mov    BYTE PTR [ebp-0x4],0x2
0x6359f1  3bc3                              cmp    eax,ebx
0x6359f3  7408                              je     0x6359fd
0x6359f5  50                                push   eax
0x6359f6  e8c5160000                        call   0x6370c0
0x6359fb  eb02                              jmp    0x6359ff
0x6359fd  33c0                              xor    eax,eax
0x6359ff  8986bc000000                      mov    DWORD PTR [esi+0xbc],eax
0x635a05  899ec0000000                      mov    DWORD PTR [esi+0xc0],ebx
0x635a0b  899ec4000000                      mov    DWORD PTR [esi+0xc4],ebx
0x635a11  899ec8000000                      mov    DWORD PTR [esi+0xc8],ebx
0x635a17  899ecc000000                      mov    DWORD PTR [esi+0xcc],ebx
0x635a1d  899ed0000000                      mov    DWORD PTR [esi+0xd0],ebx
0x635a23  899ed4000000                      mov    DWORD PTR [esi+0xd4],ebx
0x635a29  899ed8000000                      mov    DWORD PTR [esi+0xd8],ebx
0x635a2f  897004                            mov    DWORD PTR [eax+0x4],esi
0x635a32  8bc6                              mov    eax,esi
0x635a34  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
0x635a37  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
0x635a3e  59                                pop    ecx
0x635a3f  5f                                pop    edi
0x635a40  5e                                pop    esi
0x635a41  5b                                pop    ebx
0x635a42  8be5                              mov    esp,ebp
0x635a44  5d                                pop    ebp
0x635a45  c20400                            ret    0x4

### A10 Concrete caching manager vptr BFC9D8 at FAAFD8
VA 0x44dfe1 RAW 0x4d3e1 END 0x44e003 SHA256 81687946bc86cefe7e9bce7ce04f30618c3d3d8d6eb365866ac84e0c796355ca
0x44dfe1  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
0x44dfe8  6a18                              push   0x18
0x44dfea  c705d8affa00d8c9bf00              mov    DWORD PTR ds:0xfaafd8,0xbfc9d8
0x44dff4  c705f4affa0000000000              mov    DWORD PTR ds:0xfaaff4,0x0
0x44dffe  e865324400                        call   0x891268

### A11 UI engine constructor vptr C4790C
VA 0x74d9bc RAW 0x34cdbc END 0x74d9d2 SHA256 35a5594f03e1eee239990303a874e8086e7dc8ea62143314adac3b32f14f430e
0x74d9bc  c745e81048f900                    mov    DWORD PTR [ebp-0x18],0xf94810
0x74d9c3  c7051048f9000c79c400              mov    DWORD PTR ds:0xf94810,0xc4790c
0x74d9cd  e8fefeffff                        call   0x74d8d0

### A12 CSquarePage concrete vptr
VA 0x5b2670 RAW 0x1b1a70 END 0x5b26b7 SHA256 f0d67de9bc89d9187149b892116c8d20ff4308761e784669c5ce31d201fdafa7
0x5b2670  56                                push   esi
0x5b2671  e8aa290000                        call   0x5b5020
0x5b2676  33c0                              xor    eax,eax
0x5b2678  8986f8020000                      mov    DWORD PTR [esi+0x2f8],eax
0x5b267e  8986fc020000                      mov    DWORD PTR [esi+0x2fc],eax
0x5b2684  898600030000                      mov    DWORD PTR [esi+0x300],eax
0x5b268a  898604030000                      mov    DWORD PTR [esi+0x304],eax
0x5b2690  898608030000                      mov    DWORD PTR [esi+0x308],eax
0x5b2696  89860c030000                      mov    DWORD PTR [esi+0x30c],eax
0x5b269c  898610030000                      mov    DWORD PTR [esi+0x310],eax
0x5b26a2  898614030000                      mov    DWORD PTR [esi+0x314],eax
0x5b26a8  89861c030000                      mov    DWORD PTR [esi+0x31c],eax
0x5b26ae  c70654e4c100                      mov    DWORD PTR [esi],0xc1e454
0x5b26b4  8bc6                              mov    eax,esi
0x5b26b6  c3                                ret

### A13 Factory key2 Square object and map insertion
VA 0x587926 RAW 0x186d26 END 0x58799d SHA256 642e1508baa91cc54d319b0a53cc51ec8c3a15a8b747846f28e73f676248f7b1
0x587926  6820030000                        push   0x320
0x58792b  e838a73000                        call   0x892068
0x587930  83c404                            add    esp,0x4
0x587933  894508                            mov    DWORD PTR [ebp+0x8],eax
0x587936  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
0x58793d  85c0                              test   eax,eax
0x58793f  740c                              je     0x58794d
0x587941  8bf0                              mov    esi,eax
0x587943  e828ad0200                        call   0x5b2670
0x587948  894508                            mov    DWORD PTR [ebp+0x8],eax
0x58794b  eb07                              jmp    0x587954
0x58794d  c7450800000000                    mov    DWORD PTR [ebp+0x8],0x0
0x587954  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x58795b  8b7b2c                            mov    edi,DWORD PTR [ebx+0x2c]
0x58795e  8d4de8                            lea    ecx,[ebp-0x18]
0x587961  8d7704                            lea    esi,[edi+0x4]
0x587964  51                                push   ecx
0x587965  8d45ec                            lea    eax,[ebp-0x14]
0x587968  8bce                              mov    ecx,esi
0x58796a  c745e802000000                    mov    DWORD PTR [ebp-0x18],0x2
0x587971  e88a752a00                        call   0x82ef00
0x587976  8b7f08                            mov    edi,DWORD PTR [edi+0x8]
0x587979  397dec                            cmp    DWORD PTR [ebp-0x14],edi
0x58797c  751f                              jne    0x58799d
0x58797e  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x587981  8d7de4                            lea    edi,[ebp-0x1c]
0x587984  c745e402000000                    mov    DWORD PTR [ebp-0x1c],0x2
0x58798b  8955e8                            mov    DWORD PTR [ebp-0x18],edx
0x58798e  e88d75ffff                        call   0x57ef20
0x587993  50                                push   eax
0x587994  56                                push   esi
0x587995  8d75e4                            lea    esi,[ebp-0x1c]
0x587998  e863782a00                        call   0x82f200

### A14 Factory key3 DuelSquare and key4 MissionLobby
VA 0x58799d RAW 0x186d9d END 0x587ad7 SHA256 5261c9ae905d332aa5247c7c09f977798c3505e11b77468b222153d24613f39a
0x58799d  6814030000                        push   0x314
0x5879a2  e8c1a63000                        call   0x892068
0x5879a7  8bf0                              mov    esi,eax
0x5879a9  83c404                            add    esp,0x4
0x5879ac  897508                            mov    DWORD PTR [ebp+0x8],esi
0x5879af  33ff                              xor    edi,edi
0x5879b1  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
0x5879b8  3bf7                              cmp    esi,edi
0x5879ba  7435                              je     0x5879f1
0x5879bc  56                                push   esi
0x5879bd  e85ed60200                        call   0x5b5020
0x5879c2  89bef8020000                      mov    DWORD PTR [esi+0x2f8],edi
0x5879c8  c70684e0c100                      mov    DWORD PTR [esi],0xc1e084
0x5879ce  89befc020000                      mov    DWORD PTR [esi+0x2fc],edi
0x5879d4  89be00030000                      mov    DWORD PTR [esi+0x300],edi
0x5879da  89be04030000                      mov    DWORD PTR [esi+0x304],edi
0x5879e0  89be0c030000                      mov    DWORD PTR [esi+0x30c],edi
0x5879e6  89be10030000                      mov    DWORD PTR [esi+0x310],edi
0x5879ec  897508                            mov    DWORD PTR [ebp+0x8],esi
0x5879ef  eb03                              jmp    0x5879f4
0x5879f1  897d08                            mov    DWORD PTR [ebp+0x8],edi
0x5879f4  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x5879fb  8b7b2c                            mov    edi,DWORD PTR [ebx+0x2c]
0x5879fe  8d45e8                            lea    eax,[ebp-0x18]
0x587a01  8d7704                            lea    esi,[edi+0x4]
0x587a04  50                                push   eax
0x587a05  8d45ec                            lea    eax,[ebp-0x14]
0x587a08  8bce                              mov    ecx,esi
0x587a0a  c745e803000000                    mov    DWORD PTR [ebp-0x18],0x3
0x587a11  e8ea742a00                        call   0x82ef00
0x587a16  8b7f08                            mov    edi,DWORD PTR [edi+0x8]
0x587a19  397dec                            cmp    DWORD PTR [ebp-0x14],edi
0x587a1c  751f                              jne    0x587a3d
0x587a1e  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x587a21  8d7de4                            lea    edi,[ebp-0x1c]
0x587a24  c745e403000000                    mov    DWORD PTR [ebp-0x1c],0x3
0x587a2b  894de8                            mov    DWORD PTR [ebp-0x18],ecx
0x587a2e  e8ed74ffff                        call   0x57ef20
0x587a33  50                                push   eax
0x587a34  56                                push   esi
0x587a35  8d75e4                            lea    esi,[ebp-0x1c]
0x587a38  e8c3772a00                        call   0x82f200
0x587a3d  680c030000                        push   0x30c
0x587a42  e821a63000                        call   0x892068
0x587a47  8bf0                              mov    esi,eax
0x587a49  83c404                            add    esp,0x4
0x587a4c  897508                            mov    DWORD PTR [ebp+0x8],esi
0x587a4f  33ff                              xor    edi,edi
0x587a51  c745fc04000000                    mov    DWORD PTR [ebp-0x4],0x4
0x587a58  3bf7                              cmp    esi,edi
0x587a5a  742f                              je     0x587a8b
0x587a5c  56                                push   esi
0x587a5d  e8bed50200                        call   0x5b5020
0x587a62  89bef8020000                      mov    DWORD PTR [esi+0x2f8],edi
0x587a68  c706a4d9c100                      mov    DWORD PTR [esi],0xc1d9a4
0x587a6e  89befc020000                      mov    DWORD PTR [esi+0x2fc],edi
0x587a74  89be00030000                      mov    DWORD PTR [esi+0x300],edi
0x587a7a  89be04030000                      mov    DWORD PTR [esi+0x304],edi
0x587a80  89be08030000                      mov    DWORD PTR [esi+0x308],edi
0x587a86  897508                            mov    DWORD PTR [ebp+0x8],esi
0x587a89  eb03                              jmp    0x587a8e
0x587a8b  897d08                            mov    DWORD PTR [ebp+0x8],edi
0x587a8e  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x587a95  8b7b2c                            mov    edi,DWORD PTR [ebx+0x2c]
0x587a98  8d55e8                            lea    edx,[ebp-0x18]
0x587a9b  8d7704                            lea    esi,[edi+0x4]
0x587a9e  52                                push   edx
0x587a9f  8d45ec                            lea    eax,[ebp-0x14]
0x587aa2  8bce                              mov    ecx,esi
0x587aa4  c745e804000000                    mov    DWORD PTR [ebp-0x18],0x4
0x587aab  e850742a00                        call   0x82ef00
0x587ab0  8b7f08                            mov    edi,DWORD PTR [edi+0x8]
0x587ab3  397dec                            cmp    DWORD PTR [ebp-0x14],edi
0x587ab6  751f                              jne    0x587ad7
0x587ab8  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x587abb  8d7de4                            lea    edi,[ebp-0x1c]
0x587abe  c745e404000000                    mov    DWORD PTR [ebp-0x1c],0x4
0x587ac5  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x587ac8  e85374ffff                        call   0x57ef20
0x587acd  50                                push   eax
0x587ace  56                                push   esi
0x587acf  8d75e4                            lea    esi,[ebp-0x1c]
0x587ad2  e829772a00                        call   0x82f200

### A15 Factory key9 DuelLobby and keyD RaidLobby
VA 0x587d82 RAW 0x187182 END 0x587eb7 SHA256 4a85c56edc9c6ce36d1472918bf8db0a229afe0f4f932227bf684f4486c2e20a
0x587d82  6814030000                        push   0x314
0x587d87  e8dca23000                        call   0x892068
0x587d8c  8bf0                              mov    esi,eax
0x587d8e  83c404                            add    esp,0x4
0x587d91  897508                            mov    DWORD PTR [ebp+0x8],esi
0x587d94  33ff                              xor    edi,edi
0x587d96  c745fc0a000000                    mov    DWORD PTR [ebp-0x4],0xa
0x587d9d  3bf7                              cmp    esi,edi
0x587d9f  7436                              je     0x587dd7
0x587da1  56                                push   esi
0x587da2  e879d20200                        call   0x5b5020
0x587da7  89bef8020000                      mov    DWORD PTR [esi+0x2f8],edi
0x587dad  c70634e8c100                      mov    DWORD PTR [esi],0xc1e834
0x587db3  89befc020000                      mov    DWORD PTR [esi+0x2fc],edi
0x587db9  89be00030000                      mov    DWORD PTR [esi+0x300],edi
0x587dbf  89be04030000                      mov    DWORD PTR [esi+0x304],edi
0x587dc5  89be0c030000                      mov    DWORD PTR [esi+0x30c],edi
0x587dcb  c6861003000000                    mov    BYTE PTR [esi+0x310],0x0
0x587dd2  897508                            mov    DWORD PTR [ebp+0x8],esi
0x587dd5  eb03                              jmp    0x587dda
0x587dd7  897d08                            mov    DWORD PTR [ebp+0x8],edi
0x587dda  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x587de1  8b7b2c                            mov    edi,DWORD PTR [ebx+0x2c]
0x587de4  8d55e8                            lea    edx,[ebp-0x18]
0x587de7  8d7704                            lea    esi,[edi+0x4]
0x587dea  52                                push   edx
0x587deb  8d45ec                            lea    eax,[ebp-0x14]
0x587dee  8bce                              mov    ecx,esi
0x587df0  c745e809000000                    mov    DWORD PTR [ebp-0x18],0x9
0x587df7  e804712a00                        call   0x82ef00
0x587dfc  8b7f08                            mov    edi,DWORD PTR [edi+0x8]
0x587dff  397dec                            cmp    DWORD PTR [ebp-0x14],edi
0x587e02  751f                              jne    0x587e23
0x587e04  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
0x587e07  8d7de4                            lea    edi,[ebp-0x1c]
0x587e0a  c745e409000000                    mov    DWORD PTR [ebp-0x1c],0x9
0x587e11  8945e8                            mov    DWORD PTR [ebp-0x18],eax
0x587e14  e80771ffff                        call   0x57ef20
0x587e19  50                                push   eax
0x587e1a  56                                push   esi
0x587e1b  8d75e4                            lea    esi,[ebp-0x1c]
0x587e1e  e8dd732a00                        call   0x82f200
0x587e23  6808030000                        push   0x308
0x587e28  e83ba23000                        call   0x892068
0x587e2d  8bf0                              mov    esi,eax
0x587e2f  83c404                            add    esp,0x4
0x587e32  897508                            mov    DWORD PTR [ebp+0x8],esi
0x587e35  33ff                              xor    edi,edi
0x587e37  c745fc0b000000                    mov    DWORD PTR [ebp-0x4],0xb
0x587e3e  3bf7                              cmp    esi,edi
0x587e40  7429                              je     0x587e6b
0x587e42  56                                push   esi
0x587e43  e8d8d10200                        call   0x5b5020
0x587e48  89bef8020000                      mov    DWORD PTR [esi+0x2f8],edi
0x587e4e  c70614ddc100                      mov    DWORD PTR [esi],0xc1dd14
0x587e54  89befc020000                      mov    DWORD PTR [esi+0x2fc],edi
0x587e5a  89be00030000                      mov    DWORD PTR [esi+0x300],edi
0x587e60  89be04030000                      mov    DWORD PTR [esi+0x304],edi
0x587e66  897508                            mov    DWORD PTR [ebp+0x8],esi
0x587e69  eb03                              jmp    0x587e6e
0x587e6b  897d08                            mov    DWORD PTR [ebp+0x8],edi
0x587e6e  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x587e75  8b7b2c                            mov    edi,DWORD PTR [ebx+0x2c]
0x587e78  8d4de8                            lea    ecx,[ebp-0x18]
0x587e7b  8d7704                            lea    esi,[edi+0x4]
0x587e7e  51                                push   ecx
0x587e7f  8d45ec                            lea    eax,[ebp-0x14]
0x587e82  8bce                              mov    ecx,esi
0x587e84  c745e80d000000                    mov    DWORD PTR [ebp-0x18],0xd
0x587e8b  e870702a00                        call   0x82ef00
0x587e90  8b7f08                            mov    edi,DWORD PTR [edi+0x8]
0x587e93  397dec                            cmp    DWORD PTR [ebp-0x14],edi
0x587e96  751f                              jne    0x587eb7
0x587e98  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
0x587e9b  8d7de4                            lea    edi,[ebp-0x1c]
0x587e9e  c745e40d000000                    mov    DWORD PTR [ebp-0x1c],0xd
0x587ea5  8955e8                            mov    DWORD PTR [ebp-0x18],edx
0x587ea8  e87370ffff                        call   0x57ef20
0x587ead  50                                push   eax
0x587eae  56                                push   esi
0x587eaf  8d75e4                            lea    esi,[ebp-0x1c]
0x587eb2  e849732a00                        call   0x82f200

### A16 Factory key15 DailyDungeonLobby
VA 0x5883b8 RAW 0x1877b8 END 0x588446 SHA256 f389338440fca1343bc45d2e93959ef5eb144fa96c9539f83993510f70ff1b4c
0x5883b8  6804030000                        push   0x304
0x5883bd  e8a69c3000                        call   0x892068
0x5883c2  8bf0                              mov    esi,eax
0x5883c4  83c404                            add    esp,0x4
0x5883c7  897508                            mov    DWORD PTR [ebp+0x8],esi
0x5883ca  33ff                              xor    edi,edi
0x5883cc  c745fc15000000                    mov    DWORD PTR [ebp-0x4],0x15
0x5883d3  3bf7                              cmp    esi,edi
0x5883d5  7423                              je     0x5883fa
0x5883d7  56                                push   esi
0x5883d8  e843cc0200                        call   0x5b5020
0x5883dd  89bef8020000                      mov    DWORD PTR [esi+0x2f8],edi
0x5883e3  c7068c6fbf00                      mov    DWORD PTR [esi],0xbf6f8c
0x5883e9  89befc020000                      mov    DWORD PTR [esi+0x2fc],edi
0x5883ef  89be00030000                      mov    DWORD PTR [esi+0x300],edi
0x5883f5  897508                            mov    DWORD PTR [ebp+0x8],esi
0x5883f8  eb03                              jmp    0x5883fd
0x5883fa  897d08                            mov    DWORD PTR [ebp+0x8],edi
0x5883fd  c745fcffffffff                    mov    DWORD PTR [ebp-0x4],0xffffffff
0x588404  8b7b2c                            mov    edi,DWORD PTR [ebx+0x2c]
0x588407  8d45e8                            lea    eax,[ebp-0x18]
0x58840a  8d7704                            lea    esi,[edi+0x4]
0x58840d  50                                push   eax
0x58840e  8d45ec                            lea    eax,[ebp-0x14]
0x588411  8bce                              mov    ecx,esi
0x588413  c745e815000000                    mov    DWORD PTR [ebp-0x18],0x15
0x58841a  e8e16a2a00                        call   0x82ef00
0x58841f  8b7f08                            mov    edi,DWORD PTR [edi+0x8]
0x588422  397dec                            cmp    DWORD PTR [ebp-0x14],edi
0x588425  751f                              jne    0x588446
0x588427  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
0x58842a  8d7de4                            lea    edi,[ebp-0x1c]
0x58842d  c745e415000000                    mov    DWORD PTR [ebp-0x1c],0x15
0x588434  894de8                            mov    DWORD PTR [ebp-0x18],ecx
0x588437  e8e46affff                        call   0x57ef20
0x58843c  50                                push   eax
0x58843d  56                                push   esi
0x58843e  8d75e4                            lea    esi,[ebp-0x1c]
0x588441  e8ba6d2a00                        call   0x82f200

### A17 Shared currentfield v+18 dispatch anchor
VA 0x491cd8 RAW 0x910d8 END 0x491cf8 SHA256 392938b24e5e2eb52fc636a589ed608f780f36c8d3a0f1a6975d0421288fdbd3
0x491cd8  e8d37fffff                        call   0x489cb0
0x491cdd  8b88ac5e0000                      mov    ecx,DWORD PTR [eax+0x5eac]
0x491ce3  3bce                              cmp    ecx,esi
0x491ce5  740d                              je     0x491cf4
0x491ce7  8b01                              mov    eax,DWORD PTR [ecx]
0x491ce9  8b5018                            mov    edx,DWORD PTR [eax+0x18]
0x491cec  ffd2                              call   edx
0x491cee  89442418                          mov    DWORD PTR [esp+0x18],eax
0x491cf2  eb04                              jmp    0x491cf8
0x491cf4  89742418                          mov    DWORD PTR [esp+0x18],esi

### A18 CTalkBoxDialog constructor concrete vptr
VA 0x635967 RAW 0x234d67 END 0x63596d SHA256 f83798b7398b020f147a7fb069d826642b8d8b50a757db329408d8b218169c91
0x635967  c706dce3c200                      mov    DWORD PTR [esi],0xc2e3dc

### P01 Bounded page init/leave/tick prefix to concrete base target
VA 0x4234e0 RAW 0x228e0 END 0x4234e8 SHA256 815cb96d344b38019dab8207fb890e10c4a0f27630850e0db590e9a5fba8eefe
0x4234e0  56                                push   esi
0x4234e1  8bf1                              mov    esi,ecx
0x4234e3  e8c8521900                        call   0x5b87b0

### P02 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b07b0 RAW 0x1afbb0 END 0x5b07de SHA256 3bc3ed4f7e7ce59033b840de1a1a2efe58f796ac86b591773a75863663a8e903
0x5b07b0  55                                push   ebp
0x5b07b1  8bec                              mov    ebp,esp
0x5b07b3  6aff                              push   0xffffffff
0x5b07b5  68b6949400                        push   0x9494b6
0x5b07ba  64a100000000                      mov    eax,fs:0x0
0x5b07c0  50                                push   eax
0x5b07c1  83ec24                            sub    esp,0x24
0x5b07c4  56                                push   esi
0x5b07c5  57                                push   edi
0x5b07c6  a1201fd600                        mov    eax,ds:0xd61f20
0x5b07cb  33c5                              xor    eax,ebp
0x5b07cd  50                                push   eax
0x5b07ce  8d45f4                            lea    eax,[ebp-0xc]
0x5b07d1  64a300000000                      mov    fs:0x0,eax
0x5b07d7  8bf9                              mov    edi,ecx
0x5b07d9  e8d27f0000                        call   0x5b87b0

### P03 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b1290 RAW 0x1b0690 END 0x5b1298 SHA256 6fe35fde998643ecb2cb0d60fae238db07c76b121ccf56211ea7ded68e50cee2
0x5b1290  56                                push   esi
0x5b1291  8bf1                              mov    esi,ecx
0x5b1293  e818750000                        call   0x5b87b0

### P04 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b2f20 RAW 0x1b2320 END 0x5b2f2d SHA256 d7fcd1e323fa87462afe49ad1e5cb86ae38171d04909ba77239deb679b4a2b3d
0x5b2f20  55                                push   ebp
0x5b2f21  8bec                              mov    ebp,esp
0x5b2f23  51                                push   ecx
0x5b2f24  56                                push   esi
0x5b2f25  57                                push   edi
0x5b2f26  8bf1                              mov    esi,ecx
0x5b2f28  e883580000                        call   0x5b87b0

### P05 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b3f60 RAW 0x1b3360 END 0x5b3f68 SHA256 93f1de73dfe67594868ce2072e7457f6ff4261a287598a889109c23c1be9cd8a
0x5b3f60  56                                push   esi
0x5b3f61  8bf1                              mov    esi,ecx
0x5b3f63  e848480000                        call   0x5b87b0

### P06 Bounded page init/leave/tick prefix to concrete base target
VA 0x5c2af0 RAW 0x1c1ef0 END 0x5c2af8 SHA256 c82508f29120b6f9a2fe026a46db6810f2a27f31e83f93934a1b5b0a90277556
0x5c2af0  56                                push   esi
0x5c2af1  8bf1                              mov    esi,ecx
0x5c2af3  e8b85cffff                        call   0x5b87b0

### P07 Bounded page init/leave/tick prefix to concrete base target
VA 0x5c2c60 RAW 0x1c2060 END 0x5c2c8a SHA256 6ae0393a1e4d745a8fba0db4b4bf5a31ad463e3f0ad2df67d05e61d466af579f
0x5c2c60  55                                push   ebp
0x5c2c61  8bec                              mov    ebp,esp
0x5c2c63  6aff                              push   0xffffffff
0x5c2c65  68de729400                        push   0x9472de
0x5c2c6a  64a100000000                      mov    eax,fs:0x0
0x5c2c70  50                                push   eax
0x5c2c71  56                                push   esi
0x5c2c72  a1201fd600                        mov    eax,ds:0xd61f20
0x5c2c77  33c5                              xor    eax,ebp
0x5c2c79  50                                push   eax
0x5c2c7a  8d45f4                            lea    eax,[ebp-0xc]
0x5c2c7d  64a300000000                      mov    fs:0x0,eax
0x5c2c83  8bf1                              mov    esi,ecx
0x5c2c85  e8265bffff                        call   0x5b87b0

### P08 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b1c30 RAW 0x1b1030 END 0x5b1c3c SHA256 676e026807bb8d0a15dfa0d58248a72f81777e5529be304733eaabe2483235c2
0x5b1c30  55                                push   ebp
0x5b1c31  8bec                              mov    ebp,esp
0x5b1c33  51                                push   ecx
0x5b1c34  56                                push   esi
0x5b1c35  8bf1                              mov    esi,ecx
0x5b1c37  e824100100                        call   0x5c2c60

### P09 Bounded page init/leave/tick prefix to concrete base target
VA 0x5c29b0 RAW 0x1c1db0 END 0x5c29df SHA256 a09ca15e280672c33effd9b4af945b8dd7323beae9f29fb8d0b598d4b899be66
0x5c29b0  55                                push   ebp
0x5c29b1  8bec                              mov    ebp,esp
0x5c29b3  6aff                              push   0xffffffff
0x5c29b5  68c0749400                        push   0x9474c0
0x5c29ba  64a100000000                      mov    eax,fs:0x0
0x5c29c0  50                                push   eax
0x5c29c1  83ec14                            sub    esp,0x14
0x5c29c4  53                                push   ebx
0x5c29c5  56                                push   esi
0x5c29c6  57                                push   edi
0x5c29c7  a1201fd600                        mov    eax,ds:0xd61f20
0x5c29cc  33c5                              xor    eax,ebp
0x5c29ce  50                                push   eax
0x5c29cf  8d45f4                            lea    eax,[ebp-0xc]
0x5c29d2  64a300000000                      mov    fs:0x0,eax
0x5c29d8  8bf1                              mov    esi,ecx
0x5c29da  e8e128ffff                        call   0x5b52c0

### P10 Bounded page init/leave/tick prefix to concrete base target
VA 0x5c2a60 RAW 0x1c1e60 END 0x5c2a8b SHA256 3fc45149dad53697783194c8e9a1b5d75acc234453a69d0e1f36fbfb691f7239
0x5c2a60  55                                push   ebp
0x5c2a61  8bec                              mov    ebp,esp
0x5c2a63  6aff                              push   0xffffffff
0x5c2a65  68a02c9200                        push   0x922ca0
0x5c2a6a  64a100000000                      mov    eax,fs:0x0
0x5c2a70  50                                push   eax
0x5c2a71  83ec14                            sub    esp,0x14
0x5c2a74  56                                push   esi
0x5c2a75  a1201fd600                        mov    eax,ds:0xd61f20
0x5c2a7a  33c5                              xor    eax,ebp
0x5c2a7c  50                                push   eax
0x5c2a7d  8d45f4                            lea    eax,[ebp-0xc]
0x5c2a80  64a300000000                      mov    fs:0x0,eax
0x5c2a86  e80535ffff                        call   0x5b5f90

### P11 Bounded page init/leave/tick prefix to concrete base target
VA 0x5c2b20 RAW 0x1c1f20 END 0x5c2b4f SHA256 43b507d2a5310c6860951916757955784e78d63e15f3ccfbc5edd38ec4444fe1
0x5c2b20  55                                push   ebp
0x5c2b21  8bec                              mov    ebp,esp
0x5c2b23  6aff                              push   0xffffffff
0x5c2b25  68c0749400                        push   0x9474c0
0x5c2b2a  64a100000000                      mov    eax,fs:0x0
0x5c2b30  50                                push   eax
0x5c2b31  83ec14                            sub    esp,0x14
0x5c2b34  53                                push   ebx
0x5c2b35  56                                push   esi
0x5c2b36  57                                push   edi
0x5c2b37  a1201fd600                        mov    eax,ds:0xd61f20
0x5c2b3c  33c5                              xor    eax,ebp
0x5c2b3e  50                                push   eax
0x5c2b3f  8d45f4                            lea    eax,[ebp-0xc]
0x5c2b42  64a300000000                      mov    fs:0x0,eax
0x5c2b48  8bf1                              mov    esi,ecx
0x5c2b4a  e87127ffff                        call   0x5b52c0

### P12 Bounded page init/leave/tick prefix to concrete base target
VA 0x5c2bd0 RAW 0x1c1fd0 END 0x5c2bfb SHA256 63ca52a780b76da6321ecc7159be64a402b72475052bea0ac07e8164c401b62d
0x5c2bd0  55                                push   ebp
0x5c2bd1  8bec                              mov    ebp,esp
0x5c2bd3  6aff                              push   0xffffffff
0x5c2bd5  68a02c9200                        push   0x922ca0
0x5c2bda  64a100000000                      mov    eax,fs:0x0
0x5c2be0  50                                push   eax
0x5c2be1  83ec14                            sub    esp,0x14
0x5c2be4  56                                push   esi
0x5c2be5  a1201fd600                        mov    eax,ds:0xd61f20
0x5c2bea  33c5                              xor    eax,ebp
0x5c2bec  50                                push   eax
0x5c2bed  8d45f4                            lea    eax,[ebp-0xc]
0x5c2bf0  64a300000000                      mov    fs:0x0,eax
0x5c2bf6  e89533ffff                        call   0x5b5f90

### P13 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b26c0 RAW 0x1b1ac0 END 0x5b26ef SHA256 61c1521c78f15f70aaa4005bc974a4bf7a90e305935e4f82439089decc6c336f
0x5b26c0  55                                push   ebp
0x5b26c1  8bec                              mov    ebp,esp
0x5b26c3  6aff                              push   0xffffffff
0x5b26c5  687e949400                        push   0x94947e
0x5b26ca  64a100000000                      mov    eax,fs:0x0
0x5b26d0  50                                push   eax
0x5b26d1  83ec20                            sub    esp,0x20
0x5b26d4  53                                push   ebx
0x5b26d5  56                                push   esi
0x5b26d6  57                                push   edi
0x5b26d7  a1201fd600                        mov    eax,ds:0xd61f20
0x5b26dc  33c5                              xor    eax,ebp
0x5b26de  50                                push   eax
0x5b26df  8d45f4                            lea    eax,[ebp-0xc]
0x5b26e2  64a300000000                      mov    fs:0x0,eax
0x5b26e8  8bd9                              mov    ebx,ecx
0x5b26ea  e8c1020100                        call   0x5c29b0

### P14 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b2a30 RAW 0x1b1e30 END 0x5b2a5b SHA256 1bb1545b3dcb084e8ec53113355065ca12cd42edb8af3bd09ef29dec51505273
0x5b2a30  55                                push   ebp
0x5b2a31  8bec                              mov    ebp,esp
0x5b2a33  6aff                              push   0xffffffff
0x5b2a35  68a02c9200                        push   0x922ca0
0x5b2a3a  64a100000000                      mov    eax,fs:0x0
0x5b2a40  50                                push   eax
0x5b2a41  83ec14                            sub    esp,0x14
0x5b2a44  56                                push   esi
0x5b2a45  a1201fd600                        mov    eax,ds:0xd61f20
0x5b2a4a  33c5                              xor    eax,ebp
0x5b2a4c  50                                push   eax
0x5b2a4d  8d45f4                            lea    eax,[ebp-0xc]
0x5b2a50  64a300000000                      mov    fs:0x0,eax
0x5b2a56  e805000100                        call   0x5c2a60

### P15 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b1860 RAW 0x1b0c60 END 0x5b188f SHA256 e40981c46dcf1b05cb49d07d1b31266bdfa5a854c04ee87f3a63ec398631f2d7
0x5b1860  55                                push   ebp
0x5b1861  8bec                              mov    ebp,esp
0x5b1863  6aff                              push   0xffffffff
0x5b1865  687e949400                        push   0x94947e
0x5b186a  64a100000000                      mov    eax,fs:0x0
0x5b1870  50                                push   eax
0x5b1871  83ec20                            sub    esp,0x20
0x5b1874  53                                push   ebx
0x5b1875  56                                push   esi
0x5b1876  57                                push   edi
0x5b1877  a1201fd600                        mov    eax,ds:0xd61f20
0x5b187c  33c5                              xor    eax,ebp
0x5b187e  50                                push   eax
0x5b187f  8d45f4                            lea    eax,[ebp-0xc]
0x5b1882  64a300000000                      mov    fs:0x0,eax
0x5b1888  8bd9                              mov    ebx,ecx
0x5b188a  e891120100                        call   0x5c2b20

### P16 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b1a80 RAW 0x1b0e80 END 0x5b1aab SHA256 a6e6d00407498224334b3583bba7ad91f37d54a960a38cc5ee1783c794dc2e26
0x5b1a80  55                                push   ebp
0x5b1a81  8bec                              mov    ebp,esp
0x5b1a83  6aff                              push   0xffffffff
0x5b1a85  68a02c9200                        push   0x922ca0
0x5b1a8a  64a100000000                      mov    eax,fs:0x0
0x5b1a90  50                                push   eax
0x5b1a91  83ec14                            sub    esp,0x14
0x5b1a94  56                                push   esi
0x5b1a95  a1201fd600                        mov    eax,ds:0xd61f20
0x5b1a9a  33c5                              xor    eax,ebp
0x5b1a9c  50                                push   eax
0x5b1a9d  8d45f4                            lea    eax,[ebp-0xc]
0x5b1aa0  64a300000000                      mov    fs:0x0,eax
0x5b1aa6  e825110100                        call   0x5c2bd0

### P17 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b0510 RAW 0x1af910 END 0x5b053f SHA256 74c0cddc4890639cf8dd433d8c745b6d2502497329d1233841117f921e32229c
0x5b0510  55                                push   ebp
0x5b0511  8bec                              mov    ebp,esp
0x5b0513  6aff                              push   0xffffffff
0x5b0515  68ce399400                        push   0x9439ce
0x5b051a  64a100000000                      mov    eax,fs:0x0
0x5b0520  50                                push   eax
0x5b0521  83ec14                            sub    esp,0x14
0x5b0524  53                                push   ebx
0x5b0525  56                                push   esi
0x5b0526  57                                push   edi
0x5b0527  a1201fd600                        mov    eax,ds:0xd61f20
0x5b052c  33c5                              xor    eax,ebp
0x5b052e  50                                push   eax
0x5b052f  8d45f4                            lea    eax,[ebp-0xc]
0x5b0532  64a300000000                      mov    fs:0x0,eax
0x5b0538  8bd9                              mov    ebx,ecx
0x5b053a  e871240100                        call   0x5c29b0

### P18 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b0670 RAW 0x1afa70 END 0x5b069b SHA256 5a71d6d1944507548deaa5890c23be0f719bd8f8a0b1fc55d96447cea767d8d4
0x5b0670  55                                push   ebp
0x5b0671  8bec                              mov    ebp,esp
0x5b0673  6aff                              push   0xffffffff
0x5b0675  68a02c9200                        push   0x922ca0
0x5b067a  64a100000000                      mov    eax,fs:0x0
0x5b0680  50                                push   eax
0x5b0681  83ec14                            sub    esp,0x14
0x5b0684  56                                push   esi
0x5b0685  a1201fd600                        mov    eax,ds:0xd61f20
0x5b068a  33c5                              xor    eax,ebp
0x5b068c  50                                push   eax
0x5b068d  8d45f4                            lea    eax,[ebp-0xc]
0x5b0690  64a300000000                      mov    fs:0x0,eax
0x5b0696  e8c5230100                        call   0x5c2a60

### P19 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b1040 RAW 0x1b0440 END 0x5b106f SHA256 e69f6adf0ca2ee807d15be09cb1245e0987c0c7d2653cd847053769d8b344800
0x5b1040  55                                push   ebp
0x5b1041  8bec                              mov    ebp,esp
0x5b1043  6aff                              push   0xffffffff
0x5b1045  68ce399400                        push   0x9439ce
0x5b104a  64a100000000                      mov    eax,fs:0x0
0x5b1050  50                                push   eax
0x5b1051  83ec14                            sub    esp,0x14
0x5b1054  53                                push   ebx
0x5b1055  56                                push   esi
0x5b1056  57                                push   edi
0x5b1057  a1201fd600                        mov    eax,ds:0xd61f20
0x5b105c  33c5                              xor    eax,ebp
0x5b105e  50                                push   eax
0x5b105f  8d45f4                            lea    eax,[ebp-0xc]
0x5b1062  64a300000000                      mov    fs:0x0,eax
0x5b1068  8bd9                              mov    ebx,ecx
0x5b106a  e841190100                        call   0x5c29b0

### P20 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b1190 RAW 0x1b0590 END 0x5b11bb SHA256 52c7fa8486883a2357aa14c83c37fc2ba5c66a006d643866801569ad323f505a
0x5b1190  55                                push   ebp
0x5b1191  8bec                              mov    ebp,esp
0x5b1193  6aff                              push   0xffffffff
0x5b1195  68a02c9200                        push   0x922ca0
0x5b119a  64a100000000                      mov    eax,fs:0x0
0x5b11a0  50                                push   eax
0x5b11a1  83ec14                            sub    esp,0x14
0x5b11a4  56                                push   esi
0x5b11a5  a1201fd600                        mov    eax,ds:0xd61f20
0x5b11aa  33c5                              xor    eax,ebp
0x5b11ac  50                                push   eax
0x5b11ad  8d45f4                            lea    eax,[ebp-0xc]
0x5b11b0  64a300000000                      mov    fs:0x0,eax
0x5b11b6  e8a5180100                        call   0x5c2a60

### P21 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b3a10 RAW 0x1b2e10 END 0x5b3a43 SHA256 0e6f1588df8d9e25c06dbdfd990f3950d0de785cf951ee3c8ff9077fcea6f3d8
0x5b3a10  55                                push   ebp
0x5b3a11  8bec                              mov    ebp,esp
0x5b3a13  83e4f8                            and    esp,0xfffffff8
0x5b3a16  6aff                              push   0xffffffff
0x5b3a18  683c949400                        push   0x94943c
0x5b3a1d  64a100000000                      mov    eax,fs:0x0
0x5b3a23  50                                push   eax
0x5b3a24  83ec18                            sub    esp,0x18
0x5b3a27  53                                push   ebx
0x5b3a28  56                                push   esi
0x5b3a29  57                                push   edi
0x5b3a2a  a1201fd600                        mov    eax,ds:0xd61f20
0x5b3a2f  33c4                              xor    eax,esp
0x5b3a31  50                                push   eax
0x5b3a32  8d442428                          lea    eax,[esp+0x28]
0x5b3a36  64a300000000                      mov    fs:0x0,eax
0x5b3a3c  8bd9                              mov    ebx,ecx
0x5b3a3e  e86def0000                        call   0x5c29b0

### P22 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b3c30 RAW 0x1b3030 END 0x5b3d03 SHA256 a89271335d2df2b265d319ee384a11cce85e24a8d88eec44cfbed80643684c84
0x5b3c30  55                                push   ebp
0x5b3c31  8bec                              mov    ebp,esp
0x5b3c33  83e4f8                            and    esp,0xfffffff8
0x5b3c36  6aff                              push   0xffffffff
0x5b3c38  688ef69300                        push   0x93f68e
0x5b3c3d  64a100000000                      mov    eax,fs:0x0
0x5b3c43  50                                push   eax
0x5b3c44  83ec1c                            sub    esp,0x1c
0x5b3c47  53                                push   ebx
0x5b3c48  56                                push   esi
0x5b3c49  a1201fd600                        mov    eax,ds:0xd61f20
0x5b3c4e  33c4                              xor    eax,esp
0x5b3c50  50                                push   eax
0x5b3c51  8d442428                          lea    eax,[esp+0x28]
0x5b3c55  64a300000000                      mov    fs:0x0,eax
0x5b3c5b  8bf1                              mov    esi,ecx
0x5b3c5d  33db                              xor    ebx,ebx
0x5b3c5f  389e10030000                      cmp    BYTE PTR [esi+0x310],bl
0x5b3c65  0f8491000000                      je     0x5b3cfc
0x5b3c6b  8b8e64010000                      mov    ecx,DWORD PTR [esi+0x164]
0x5b3c71  889e10030000                      mov    BYTE PTR [esi+0x310],bl
0x5b3c77  8b01                              mov    eax,DWORD PTR [ecx]
0x5b3c79  8b90a0010000                      mov    edx,DWORD PTR [eax+0x1a0]
0x5b3c7f  ffd2                              call   edx
0x5b3c81  f6059043f90001                    test   BYTE PTR ds:0xf94390,0x1
0x5b3c88  7525                              jne    0x5b3caf
0x5b3c8a  830d9043f90001                    or     DWORD PTR ds:0xf94390,0x1
0x5b3c91  895c2430                          mov    DWORD PTR [esp+0x30],ebx
0x5b3c95  e8f6d8f2ff                        call   0x4e1590
0x5b3c9a  6880ccbc00                        push   0xbccc80
0x5b3c9f  e876e62d00                        call   0x89231a
0x5b3ca4  83c404                            add    esp,0x4
0x5b3ca7  c7442430ffffffff                  mov    DWORD PTR [esp+0x30],0xffffffff
0x5b3caf  f6051413fb0001                    test   BYTE PTR ds:0xfb1314,0x1
0x5b3cb6  8a8610030000                      mov    al,BYTE PTR [esi+0x310]
0x5b3cbc  a2c042f900                        mov    ds:0xf942c0,al
0x5b3cc1  7514                              jne    0x5b3cd7
0x5b3cc3  830d1413fb0001                    or     DWORD PTR ds:0xfb1314,0x1
0x5b3cca  6810cfbc00                        push   0xbccf10
0x5b3ccf  e846e62d00                        call   0x89231a
0x5b3cd4  83c404                            add    esp,0x4
0x5b3cd7  c744240c49000000                  mov    DWORD PTR [esp+0xc],0x49
0x5b3cdf  391d98a7fb00                      cmp    DWORD PTR ds:0xfba798,ebx
0x5b3ce5  7515                              jne    0x5b3cfc
0x5b3ce7  8b0d54a8fb00                      mov    ecx,DWORD PTR ds:0xfba854
0x5b3ced  8b01                              mov    eax,DWORD PTR [ecx]
0x5b3cef  8b4010                            mov    eax,DWORD PTR [eax+0x10]
0x5b3cf2  6a04                              push   0x4
0x5b3cf4  8d542410                          lea    edx,[esp+0x10]
0x5b3cf8  52                                push   edx
0x5b3cf9  53                                push   ebx
0x5b3cfa  ffd0                              call   eax
0x5b3cfc  8bce                              mov    ecx,esi
0x5b3cfe  e85ded0000                        call   0x5c2a60

### P23 Bounded page init/leave/tick prefix to concrete base target
VA 0x4232b0 RAW 0x226b0 END 0x4232df SHA256 6109cd5a2e78696efe98ef9fdba88179e93c961b5a36040ab4924d9dc49fe89a
0x4232b0  55                                push   ebp
0x4232b1  8bec                              mov    ebp,esp
0x4232b3  6aff                              push   0xffffffff
0x4232b5  68ce399400                        push   0x9439ce
0x4232ba  64a100000000                      mov    eax,fs:0x0
0x4232c0  50                                push   eax
0x4232c1  83ec14                            sub    esp,0x14
0x4232c4  53                                push   ebx
0x4232c5  56                                push   esi
0x4232c6  57                                push   edi
0x4232c7  a1201fd600                        mov    eax,ds:0xd61f20
0x4232cc  33c5                              xor    eax,ebp
0x4232ce  50                                push   eax
0x4232cf  8d45f4                            lea    eax,[ebp-0xc]
0x4232d2  64a300000000                      mov    fs:0x0,eax
0x4232d8  8bd9                              mov    ebx,ecx
0x4232da  e8d1f61900                        call   0x5c29b0

### P24 Bounded page init/leave/tick prefix to concrete base target
VA 0x4233e0 RAW 0x227e0 END 0x42340b SHA256 fdef95b38fae8fa8270fa809c7944cb8ad9ec683f81f032f879070ef84e16d2b
0x4233e0  55                                push   ebp
0x4233e1  8bec                              mov    ebp,esp
0x4233e3  6aff                              push   0xffffffff
0x4233e5  68a02c9200                        push   0x922ca0
0x4233ea  64a100000000                      mov    eax,fs:0x0
0x4233f0  50                                push   eax
0x4233f1  83ec14                            sub    esp,0x14
0x4233f4  56                                push   esi
0x4233f5  a1201fd600                        mov    eax,ds:0xd61f20
0x4233fa  33c5                              xor    eax,ebp
0x4233fc  50                                push   eax
0x4233fd  8d45f4                            lea    eax,[ebp-0xc]
0x423400  64a300000000                      mov    fs:0x0,eax
0x423406  e855f61900                        call   0x5c2a60

### P25 Bounded page init/leave/tick prefix to concrete base target
VA 0x4234c0 RAW 0x228c0 END 0x4234cd SHA256 a77a5966137fe068b98551df4eef9d09e5a2431d9129bb5aea4d0351e2248d8b
0x4234c0  55                                push   ebp
0x4234c1  8bec                              mov    ebp,esp
0x4234c3  56                                push   esi
0x4234c4  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x4234c7  56                                push   esi
0x4234c8  e883421900                        call   0x5b7750

### P26 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b0760 RAW 0x1afb60 END 0x5b0770 SHA256 48008f4db47d6c250a5f2e1741749b9a5c42e55cb491426ca1c6b0b4fdb65cc4
0x5b0760  55                                push   ebp
0x5b0761  8bec                              mov    ebp,esp
0x5b0763  56                                push   esi
0x5b0764  57                                push   edi
0x5b0765  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5b0768  57                                push   edi
0x5b0769  8bf1                              mov    esi,ecx
0x5b076b  e8e06f0000                        call   0x5b7750

### P27 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b1270 RAW 0x1b0670 END 0x5b127d SHA256 cf3bd671169d83524a12ec56bdd2b024ac6be880e031804ef021d69826bab7dd
0x5b1270  55                                push   ebp
0x5b1271  8bec                              mov    ebp,esp
0x5b1273  56                                push   esi
0x5b1274  8b7508                            mov    esi,DWORD PTR [ebp+0x8]
0x5b1277  56                                push   esi
0x5b1278  e8d3640000                        call   0x5b7750

### P28 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b2b10 RAW 0x1b1f10 END 0x5b2b20 SHA256 01d650c52a9159bfae6304a3c8e8b3b0eaeb3aadbfc2bcf860b62f1176706dcd
0x5b2b10  55                                push   ebp
0x5b2b11  8bec                              mov    ebp,esp
0x5b2b13  56                                push   esi
0x5b2b14  57                                push   edi
0x5b2b15  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5b2b18  57                                push   edi
0x5b2b19  8bf1                              mov    esi,ecx
0x5b2b1b  e8304c0000                        call   0x5b7750

### P29 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b3d90 RAW 0x1b3190 END 0x5b3da0 SHA256 0644f12d42e26e176811bf129c4855073747255d67b4141ad391371db5b5c7c7
0x5b3d90  55                                push   ebp
0x5b3d91  8bec                              mov    ebp,esp
0x5b3d93  56                                push   esi
0x5b3d94  57                                push   edi
0x5b3d95  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5b3d98  57                                push   edi
0x5b3d99  8bf1                              mov    esi,ecx
0x5b3d9b  e8b0390000                        call   0x5b7750

### P30 Bounded page init/leave/tick prefix to concrete base target
VA 0x5b1b30 RAW 0x1b0f30 END 0x5b1b40 SHA256 be954c9d97491a00c881c9a076ffce8776c2c700008f1193bd3eb8982c5b0eab
0x5b1b30  55                                push   ebp
0x5b1b31  8bec                              mov    ebp,esp
0x5b1b33  56                                push   esi
0x5b1b34  57                                push   edi
0x5b1b35  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
0x5b1b38  57                                push   edi
0x5b1b39  8bf1                              mov    esi,ecx
0x5b1b3b  e8105c0000                        call   0x5b7750

### V_CTutorial vtable and COL pointer for CTutorial
VA 0xc073e4 RAW 0x8059e4 END 0xc07404 SHA256 95643044434199136b0dc78cbfdea8a394ee22606ee0d9ae1126983b30da26a8
049ec60040594c0070464c0010284200f0274200104b4c00604d4c00f04d4c00

### C_CTutorial RTTI COL for CTutorial
VA 0xc69e04 RAW 0x868404 END 0xc69e18 SHA256 c74f577a9774ec02211eb2152a44d9b6addafe25382954c2dcf2db62d9299c10
000000000000000000000000e0e1f700189ec600

### T_CTutorial RTTI type descriptor for CTutorial
VA 0xf7e1e0 RAW 0xb7b9e0 END 0xf7e1fe SHA256 c9791c207c48b8cc2878127b5e06dc208194158e36cb2ec6fcc36022bcc71c21
f435bd00000000002e3f4156435475746f7269616c405363656e65404000

### V_CExpedition vtable and COL pointer for CExpedition
VA 0xc0727c RAW 0x80587c END 0xc0729c SHA256 dfead3795214e2a0f322aad5108530cba463c77851eaa621763696616c426ce5
709cc60030154c0070464c0010284200f0274200c0154c00f0c28d0030194c00

### C_CExpedition RTTI COL for CExpedition
VA 0xc69c70 RAW 0x868270 END 0xc69c84 SHA256 f81be5ae65f6c5f5318e6bb500eed9205c6e9a22166acca6ef73db58c1b96b58
00000000000000000000000038e1f700849cc600

### T_CExpedition RTTI type descriptor for CExpedition
VA 0xf7e138 RAW 0xb7b938 END 0xf7e158 SHA256 c28f0a82f182b34c04f4362cd62d141600a37abdda5062e5471a17f393b504f2
f435bd00000000002e3f41564345787065646974696f6e405363656e65404000

### V_CMissionField vtable and COL pointer for CMissionField
VA 0xc07058 RAW 0x805658 END 0xc07078 SHA256 b5182521b562a45d2d0e31ec4cde4c8aabaeed1cd4aa1a8cbbb3b18bd1d0610b
889ac60040594c0070464c0010284200f027420050c74b0010bf4b0060304200

### C_CMissionField RTTI COL for CMissionField
VA 0xc69a88 RAW 0x868088 END 0xc69a9c SHA256 7c80caf43078914f34f0826513b4262211ed4b57a12d69933f6a68eedd15f350
00000000000000000000000060e0f7009c9ac600

### T_CMissionField RTTI type descriptor for CMissionField
VA 0xf7e060 RAW 0xb7b860 END 0xf7e082 SHA256 47647aca74ada0df592bad63e1e65a35a85ac059c83302765562980cb676bc74
f435bd00000000002e3f4156434d697373696f6e4669656c64405363656e65404000

### V_CScenarioField vtable and COL pointer for CScenarioField
VA 0xc073b0 RAW 0x8059b0 END 0xc073d0 SHA256 86a075c2324190e1ce578c0607d16f032bf44c0b47641bc84ec5eae0127a9a95
b49dc60040594c0070464c0010284200f027420050474c00f0c28d0010db4a00

### C_CScenarioField RTTI COL for CScenarioField
VA 0xc69db4 RAW 0x8683b4 END 0xc69dc8 SHA256 ff124ddaba4212fcfd89b7bf88fe990df3978afdaa51673d24373b570e86a2bc
000000000000000000000000bce1f700c89dc600

### T_CScenarioField RTTI type descriptor for CScenarioField
VA 0xf7e1bc RAW 0xb7b9bc END 0xf7e1df SHA256 a663ff0c03ccb4acb4ca1d5f1a3d532bc2aeb7e65faa56b837954b1cc421d2fc
f435bd00000000002e3f4156435363656e6172696f4669656c64405363656e65404000

### V_UIEngine vtable and COL pointer for UIEngine
VA 0xc47908 RAW 0x845f08 END 0xc47938 SHA256 0307452bbee04f555784c2863f6c9863c71fc8bf402b9648ad887ff413cd3174
a4ccc70080e074000001750080ec740050fb740040ef740000f07400b0f3740080f7740050007500d0007500e0077500

### C_UIEngine RTTI COL for UIEngine
VA 0xc7cca4 RAW 0x87b2a4 END 0xc7ccb8 SHA256 223041cdd96d55893c55b41dbe84be3120db8999d19a95e0b543651ab91f43ff
0000000000000000000000005c90f800b8ccc700

### T_UIEngine RTTI type descriptor for UIEngine
VA 0xf8905c RAW 0xb8685c END 0xf89075 SHA256 04e032efe4c49fc04228b8a6103690a1d800b61ccd508c7ad62bb205edb48920
f435bd00000000002e3f41564658554940466f785549404000

### V_CLobbyPage vtable and COL pointer for CLobbyPage
VA 0xc1ef10 RAW 0x81d510 END 0xc1f0b0 SHA256 c3959f49b9c2042148dff13663be79fde80e4c6c1f31c0ad3d5a3497bba0e701
3408c700203f4200103f4200103f4200003f4200e03d4000408c74006094740000525b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500a0975b00e0674000d0877400f08774001088740010887400105d5f00c0525b00905f5b0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900b0875b00806b590050775b00e07b5b00507c5b00807f5b00

### C_CLobbyPage RTTI COL for CLobbyPage
VA 0xc70834 RAW 0x86ee34 END 0xc70848 SHA256 634d1e8e5a6cf96b741244f397373e14f694637138649f6fac65885c4e874041
0000000000000000000000005cb6f700cc4bc600

### T_CLobbyPage RTTI type descriptor for CLobbyPage
VA 0xf7b65c RAW 0xb78e5c END 0xf7b679 SHA256 b64d3983bd2124a0b3bf7077e286ac78eeeafb359089087b16d901d862210227
f435bd00000000002e3f4156434c6f6262795061676540465549404000

### V_CDailyDungeonLobbyPage vtable and COL pointer for CDailyDungeonLobbyPage
VA 0xbf6f88 RAW 0x7f5588 END 0xbf711c SHA256 2e832c198ea2f47bd9c2d9e85bceb8c85bbc4f67c7b142c0ebd323486c6cba05
144bc600203f4200103f4200103f4200003f4200e03d4000408c740060947400e0045b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550050354200e0674000d0877400f08774001088740010887400105d5f00b0324200e033420010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900e0344200806b5900c0344200

### C_CDailyDungeonLobbyPage RTTI COL for CDailyDungeonLobbyPage
VA 0xc64b14 RAW 0x863114 END 0xc64b28 SHA256 e1cb8b45379e323f1989c252f7503501de118e58a468577f4dc7fdc0e0855a8e
000000000000000000000000a0b6f700284bc600

### T_CDailyDungeonLobbyPage RTTI type descriptor for CDailyDungeonLobbyPage
VA 0xf7b6a0 RAW 0xb78ea0 END 0xf7b6c9 SHA256 450bfad5091b053a6654f49a2027765e01de4f9ea7dce2e7a95acadf057bf735
f435bd00000000002e3f4156434461696c7944756e67656f6e4c6f6262795061676540465549404000

### V_CMissionLobbyPage vtable and COL pointer for CMissionLobbyPage
VA 0xc1d9a0 RAW 0x81bfa0 END 0xc1db34 SHA256 2f8b017e688543875078d4e965c4fcc481bb3fa4d2204e6c58e3491bdd29f8ff
7c00c700203f4200103f4200103f4200003f4200e03d4000408c740060947400e0045b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500a0975b00e0674000d0877400f08774001088740010887400105d5f0010055b0070065b0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900103c5b00c05e590010ae4900b0075b00806b590060075b00

### C_CMissionLobbyPage RTTI COL for CMissionLobbyPage
VA 0xc7007c RAW 0x86e67c END 0xc70090 SHA256 a2d3112f8f1598ed0399d5d878851120a056867232ea31c0ae460ad293470f34
000000000000000000000000a41bf8009000c700

### T_CMissionLobbyPage RTTI type descriptor for CMissionLobbyPage
VA 0xf81ba4 RAW 0xb7f3a4 END 0xf81bc8 SHA256 78db910a199cbbb0043ca8fab91b77f9140088432466dec2972e2b805f3a6aa3
f435bd00000000002e3f4156434d697373696f6e4c6f6262795061676540465549404000

### V_CRaidLobbyPage vtable and COL pointer for CRaidLobbyPage
VA 0xc1dd10 RAW 0x81c310 END 0xc1dea4 SHA256 fd5d68dc57906bfbc3fa15653613b2b14c2453e1663933c0c9d9f621a9e0080b
8801c700203f4200103f4200103f4200003f4200e03d4000408c740060947400e0045b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550010165b00e0674000d0877400f08774001088740010887400105d5f0040105b0090115b0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900103c5b00c05e590010ae490090125b00806b590070125b00

### C_CRaidLobbyPage RTTI COL for CRaidLobbyPage
VA 0xc70188 RAW 0x86e788 END 0xc7019c SHA256 0ff491e543d0bff7283aae13941cf2ef6e89f88509f53a4dc27f7e869220cc5b
0000000000000000000000002c1cf8009c01c700

### T_CRaidLobbyPage RTTI type descriptor for CRaidLobbyPage
VA 0xf81c2c RAW 0xb7f42c END 0xf81c4d SHA256 a8297906e7a96e63ba2294beea732588efe8286b08cd4bc45dfb73987e43489a
f435bd00000000002e3f415643526169644c6f6262795061676540465549404000

### V_CSquarePage vtable and COL pointer for CSquarePage
VA 0xc1e450 RAW 0x81ca50 END 0xc1e5e4 SHA256 a16797bc184ac194fc969ef7a93d1093cbbe85bfca88782920c2f0d240f0de70
c005c700203f4200103f4200103f4200003f4200e03d4000408c740060947400e0045b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500a0975b00e0674000d0877400f08774001088740010887400105d5f00c0265b00302a5b0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900202f5b00806b5900102b5b00

### C_CSquarePage RTTI COL for CSquarePage
VA 0xc705c0 RAW 0x86ebc0 END 0xc705d4 SHA256 abfb76d79538fd692dfe2d20661092fb1ef878c5974ba4606c9a416307450b2f
0000000000000000000000003c1ff800d405c700

### T_CSquarePage RTTI type descriptor for CSquarePage
VA 0xf81f3c RAW 0xb7f73c END 0xf81f5a SHA256 24ed7fc7870d802a75e8e0fa50443acb5d3e3a1f9baf21bef7910ba7aa177d7f
f435bd00000000002e3f4156435371756172655061676540465549404000

### V_CDuelLobbyPage vtable and COL pointer for CDuelLobbyPage
VA 0xc1e830 RAW 0x81ce30 END 0xc1e9c4 SHA256 743f06f2b8cf0a1e341719a656116f439407e46fba5de38857f683212b06e405
6007c700203f4200103f4200103f4200003f4200e03d4000408c740060947400e0045b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500b0455b00e0674000d0877400f08774001088740010887400105d5f00103a5b00303c5b0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590090395b00305e5900103c5b00c05e590010ae4900603f5b00806b5900903d5b00

### C_CDuelLobbyPage RTTI COL for CDuelLobbyPage
VA 0xc70760 RAW 0x86ed60 END 0xc70774 SHA256 4d7d94b39e11320a6d96b09d396059963209ab455dc1e3297382e20725d08690
0000000000000000000000005820f8007407c700

### T_CDuelLobbyPage RTTI type descriptor for CDuelLobbyPage
VA 0xf82058 RAW 0xb7f858 END 0xf82079 SHA256 2c2cea634f7d4130b7da73093df39515deb09dc34f5e255856431d81f8dc2c1d
f435bd00000000002e3f4156434475656c4c6f6262795061676540465549404000

### V_CPartyLobbyPage vtable and COL pointer for CPartyLobbyPage
VA 0xc1f278 RAW 0x81d878 END 0xc1f40c SHA256 2b7e1641c98c84ee1d8c2e6e78d1d561a07a2b755957a652db8e006301a7ec29
2017c700203f4200103f4200103f4200003f4200e03d4000408c740060947400e0045b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500a0975b00e0674000d0877400f08774001088740010887400105d5f00b0295c00602a5c0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900f02a5c00806b590050775b00

### C_CPartyLobbyPage RTTI COL for CPartyLobbyPage
VA 0xc71720 RAW 0x86fd20 END 0xc71734 SHA256 2c4044ff9c9dc7ebeff92c4a42777843ab9c1dcdb699b3a1f317242d665f583b
0000000000000000000000007cb6f7007c4bc600

### T_CPartyLobbyPage RTTI type descriptor for CPartyLobbyPage
VA 0xf7b67c RAW 0xb78e7c END 0xf7b69e SHA256 51387b0329af57d52cc15239a2f00a33c367798ad1b601051175fa371bb8695e
f435bd00000000002e3f41564350617274794c6f6262795061676540465549404000

### V_CUnionPartyLobbdyPage vtable and COL pointer for CUnionPartyLobbdyPage
VA 0xc1f428 RAW 0x81da28 END 0xc1f5bc SHA256 597fe7650eca2c7e9900bfe99f37f0e94283c54a6d0348f04b75933e088fe2fb
8017c700203f4200103f4200103f4200003f4200e03d4000408c74006094740030185b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500a0975b00e0674000d0877400f08774001088740010887400105d5f00202b5c00d02b5c0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900602c5c00806b590050775b00

### C_CUnionPartyLobbdyPage RTTI COL for CUnionPartyLobbdyPage
VA 0xc71780 RAW 0x86fd80 END 0xc71794 SHA256 bf62ac6021ecd0825dacff83061885519af07c38f8cdddec8ecd48639f160a85
000000000000000000000000701df8008803c700

### T_CUnionPartyLobbdyPage RTTI type descriptor for CUnionPartyLobbdyPage
VA 0xf81d70 RAW 0xb7f570 END 0xf81d98 SHA256 4dcaca609167c5a6965006e7bbcf75e2c5ee1d302e0066fbc3379d316a642852
f435bd00000000002e3f415643556e696f6e50617274794c6f626264795061676540465549404000

### V_CDuelSquarePage vtable and COL pointer for CDuelSquarePage
VA 0xc1e080 RAW 0x81c680 END 0xc1e214 SHA256 f3311f9f11baf598415e5c68d62001499a2d7259a22cbf6bc9ed18d8535730d6
2003c700203f4200103f4200103f4200003f4200e03d4000408c74006094740030185b00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500a0975b00e0674000d0877400f08774001088740010887400105d5f0060185b00801a5b0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900f0b05b00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900301c5b00806b5900301b5b00

### C_CDuelSquarePage RTTI COL for CDuelSquarePage
VA 0xc70320 RAW 0x86e920 END 0xc70334 SHA256 f8a4378b4ba4f2e8a8491aa86d77a1e20896d733cab00fbe338bae873534e0d9
000000000000000000000000981df8003403c700

### T_CDuelSquarePage RTTI type descriptor for CDuelSquarePage
VA 0xf81d98 RAW 0xb7f598 END 0xf81dba SHA256 03680134ff3c4e33cda97323a7f512e8d4e5891f776ee82768d95c6270a4e2b6
f435bd00000000002e3f4156434475656c5371756172655061676540465549404000

### V_CMissionFieldPage vtable and COL pointer for CMissionFieldPage
VA 0xc1d1a8 RAW 0x81b7a8 END 0xc1d344 SHA256 f16b133a6ab38e894ec1014fb9721fdccfa548227f46c4ad5c50d5b605ee9d07
e8fbc600203f4200103f4200103f4200003f4200e03d4000408c74006094740000ce5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550080d85a00e0674000d0877400f08774001088740010887400105d5f00a0ce5a0050d05a0010ae4900105d5f00f0ab590070ad5900f0ae590070b0590030d25900105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900a0d65a00806b590090c55a00c0c55a0010d55a00

### C_CMissionFieldPage RTTI COL for CMissionFieldPage
VA 0xc6fbe8 RAW 0x86e1e8 END 0xc6fbfc SHA256 1a02c243a5866c24cb623d3b824cc8c3f7a4cc2997c74a47b651f8fe2ee1c177
0000000000000000000000009818f800fcfbc600

### T_CMissionFieldPage RTTI type descriptor for CMissionFieldPage
VA 0xf81898 RAW 0xb7f098 END 0xf818bc SHA256 68e02dd91919b515d5e7ea05e1fea1787f2a7d4ff0114141aff24640a7fd6315
f435bd00000000002e3f4156434d697373696f6e4669656c645061676540465549404000

### V_CScenarioFieldPage vtable and COL pointer for CScenarioFieldPage
VA 0xc1d628 RAW 0x81bc28 END 0xc1d7c4 SHA256 9c53e992a28a09714f6f2bf25510e56724adaa6de90014c363725ca8e5e78a79
2cfec600203f4200103f4200103f4200003f4200e03d4000408c74006094740020ea5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550010ff5a00e0674000d0877400f08774001088740010887400105d5f0030fc5a00c0fd5a0010ae4900105d5f00f0ab590070ad5900f0ae590070b0590030d25900105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900b0fe5a00806b590090c55a00c0c55a0060fe5a00

### C_CScenarioFieldPage RTTI COL for CScenarioFieldPage
VA 0xc6fe2c RAW 0x86e42c END 0xc6fe40 SHA256 7e496ac560476a542bf82d8ed3a00be9f5d258221a61de033783bc7a648f0f98
000000000000000000000000281af80040fec600

### T_CScenarioFieldPage RTTI type descriptor for CScenarioFieldPage
VA 0xf81a28 RAW 0xb7f228 END 0xf81a4d SHA256 c4fea19adb1af17d587e6645283bbb22f83696b37c108fbd9a9d21cf2653ef64
f435bd00000000002e3f4156435363656e6172696f4669656c645061676540465549404000

### V_CScenarioReviewWnd vtable and COL pointer for CScenarioReviewWnd
VA 0xc03128 RAW 0x801728 END 0xc0328c SHA256 7012bb9649c3ec3fe96a409dc54db06bff9958f49e0f570d9523029bae5c250b
948bc600e0824800907240009072400080724000e03d4000005f7500405f7500e0c44700f071400040714000807040002064580030557400f0567400800b7600205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b740080707500703d4000d05a7400205b7400b0ca470000db4400f0a07400503d4000b03d4000403d40005004550000da4700e0674000d0877400f08774006071750060717500105d5f00105d5f00105d5f00a0c54700e0c64700b06a7400d06a7400f06a7400106b7400800c7600105d5f00105d5f0050045500d06f400020a1740050d5650030644700805f7500e0674000e06740003064470030644700d0c54700

### C_CScenarioReviewWnd RTTI COL for CScenarioReviewWnd
VA 0xc68b94 RAW 0x867194 END 0xc68ba8 SHA256 9cae13210d440a8a7d8ce7deec21be32a1d3c27cfab5b6795dff3a922768f0ac
000000000000000000000000e4d8f700a88bc600

### T_CScenarioReviewWnd RTTI type descriptor for CScenarioReviewWnd
VA 0xf7d8e4 RAW 0xb7b0e4 END 0xf7d909 SHA256 11dcc8afc5899c4c46087bb975bd058ead36a7989e272de9bdf0ccd595f5a2d4
f435bd00000000002e3f4156435363656e6172696f526576696577576e6440465549404000

### V_CScenarioReviewSceneItem vtable and COL pointer for CScenarioReviewSceneItem
VA 0xc02f38 RAW 0x801538 END 0xc02f5c SHA256 e4ca07e13263dcea551c6b8068e2a7f29626ca09b9bec7ebe914094d07d45d8a
cc8ac600e06d4600f03d4000f03d400070464100e03d4000004c7400504c740060ad4700

### C_CScenarioReviewSceneItem RTTI COL for CScenarioReviewSceneItem
VA 0xc68acc RAW 0x8670cc END 0xc68ae0 SHA256 8fce21b77055276f71e340e0490262e5e4cb6d68cb35a7fc371e28c5fd448fa1
00000000000000000000000064d8f700e08ac600

### T_CScenarioReviewSceneItem RTTI type descriptor for CScenarioReviewSceneItem
VA 0xf7d864 RAW 0xb7b064 END 0xf7d88f SHA256 ec9774fb5443d4a0cb23d0c7deead105404534fa48626d5d6a6169f3c8608475
f435bd00000000002e3f4156435363656e6172696f5265766965775363656e654974656d40465549404000

### V_ReviewDescriptor vtable and COL pointer for ReviewDescriptor
VA 0xc1ed78 RAW 0x81d378 END 0xc1ed90 SHA256 c7527138e26cc5c790135afd6b57458c5ba3aa5d92c668aa1b917af8366c13c7
080dc700a0fd5b0050327b00109540002095400020de5a00

### C_ReviewDescriptor RTTI COL for ReviewDescriptor
VA 0xc70d08 RAW 0x86f308 END 0xc70d1c SHA256 f5159049b0f2c68acb40f892c3ac354c3734aee745cb9fbc6ce8555715cd5a3e
0000000000000000000000004025f8001c0dc700

### T_ReviewDescriptor RTTI type descriptor for ReviewDescriptor
VA 0xf82540 RAW 0xb7fd40 END 0xf82582 SHA256 6b5f8ad4dd95b5ff2f5b9bf7cded3d0d99948a3a6be309a7ae2348d5f95d6eb9
f435bd00000000002e3f41563f24554943616368696e67446174614024304243444056435363656e6172696f526576696577576e6440465549404040465549404000

### V_CTalkBoxNpc vtable and COL pointer for CTalkBoxNpc
VA 0xc2e584 RAW 0x82cb84 END 0xc2e5a4 SHA256 8cab87681c5fa1f26a90c51c5400c37f97c87321b91a1964dfabbb41a23190b1
7460c70000896300c08a6300d08a6300608e6300008b6300e08d6300308e6300

### C_CTalkBoxNpc RTTI COL for CTalkBoxNpc
VA 0xc76074 RAW 0x874674 END 0xc76088 SHA256 5b07cd97b88ce1741c61d78ae9601db6293d332b3bf2d69e9bc5931f4f795a1f
0000000000000000000000006056f8008860c700

### T_CTalkBoxNpc RTTI type descriptor for CTalkBoxNpc
VA 0xf85660 RAW 0xb82e60 END 0xf8567e SHA256 c70ebbebe37ac25e2a47b508225936c06f72a82671c36df27efe208b11177630
f435bd00000000002e3f41564354616c6b426f784e706340465549404000

### V_CTalkBoxDialog vtable and COL pointer for CTalkBoxDialog
VA 0xc2e3d8 RAW 0x82c9d8 END 0xc2e53c SHA256 695d630db1252132b33e920528c5cd57b3dd304a6dad6ac8cb1b509179b46c17
1c60c70010045500f0ec4000f0ec4000e0ec4000e03d4000408c740060947400705a630080ec4000d0eb400040eb4000f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400206f6300d06e7400703d4000d05a7400205b74009067630040686300f0a07400503d4000b03d4000403d400050045500d06e6300e0674000d0877400f08774001088740010887400905c6300105d5f00105d5f0010ae4900d05b6300b06a7400d06a7400f06a7400106b7400105d5f00105d5f00105d5f0050045500d06f400020a17400c06d63003064470030644700e0674000e06740003064470030644700e06d6300

### C_CTalkBoxDialog RTTI COL for CTalkBoxDialog
VA 0xc7601c RAW 0x87461c END 0xc76030 SHA256 35c3c3702abe0184f7a7ce703769490adf01370ced66b60f9de8e5bcb0d5ea3b
0000000000000000000000003c56f8003060c700

### T_CTalkBoxDialog RTTI type descriptor for CTalkBoxDialog
VA 0xf8563c RAW 0xb82e3c END 0xf8565d SHA256 1b3fc06217eea4aeab135e2166fd7c7774da7c44f5bd40851a8b7eb9a6f5271c
f435bd00000000002e3f41564354616c6b426f784469616c6f6740465549404000

### V_CFXUIBinder vtable and COL pointer for CFXUIBinder
VA 0xc19208 RAW 0x817808 END 0xc1922c SHA256 0c9a871984b7ff5b740e7514a0754746250271e892cf8823c02db9e234cf7137
88d5c600f0c28d0060b4400060b4400070b440003057580090565800a04a400000575800

### C_CFXUIBinder RTTI COL for CFXUIBinder
VA 0xc6d588 RAW 0x86bb88 END 0xc6d59c SHA256 cd053c6bd601c5d653affd37f566b0f55180272f3be607eb442fc84fba4273e5
00000000000000000000000050fcf7009cd5c600

### T_CFXUIBinder RTTI type descriptor for CFXUIBinder
VA 0xf7fc50 RAW 0xb7d450 END 0xf7fc6e SHA256 08f17d90755a28280b22d89f94bd6820e55dd3f33ed4c9dfbf7d1196f834bdc8
f435bd00000000002e3f4156434658554942696e64657240465549404000

### V_FXUICachingMgrCmdTarget vtable and COL pointer for FXUICachingMgrCmdTarget
VA 0xbfc9d4 RAW 0x7fafd4 END 0xbfca0c SHA256 da7cfc4ea58e9dd16463b9e857e93031c929251e07d854086e2f3f882b133b7a
006cc600c0eb7500f0e74400f0e74400e0e7440080e04400c04176007042760030437600f043760090e4440020e14400e06f7400f0e34400

### C_FXUICachingMgrCmdTarget RTTI COL for FXUICachingMgrCmdTarget
VA 0xc66c00 RAW 0x865200 END 0xc66c14 SHA256 f4e15aecec6e371784ae17105381103847cb6111092291f40307ce121a403722
000000000000000000000000b8c8f700146cc600

### T_FXUICachingMgrCmdTarget RTTI type descriptor for FXUICachingMgrCmdTarget
VA 0xf7c8b8 RAW 0xb7a0b8 END 0xf7c8e2 SHA256 be0b4bdab8dcf272fce9de856d5bb0245980612b94f713264c4b59c6cb816886
f435bd00000000002e3f41564658554943616368696e674d6772436d6454617267657440465549404000

### D_review_switch_byte F4337 selector
VA 0x5b7bcc RAW 0x1b6fcc END 0x5b7bcd SHA256 ffe679bb831c95b67dc17819c63c5090d221aac6f4c7bf530f594ab43d21fa1e
1f

### D_review_switch_target F4337 case target
VA 0x5b7b3c RAW 0x1b6f3c END 0x5b7b40 SHA256 8e730c94380bfa24e81664ac313d7faecd9c7a911ebf7782650b05d58c1e78ce
81795b00
