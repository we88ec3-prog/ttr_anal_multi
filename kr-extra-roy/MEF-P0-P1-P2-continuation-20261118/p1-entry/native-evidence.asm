; U01 | 普通 page+B4 的 CFXUIBinder 棧上來源；舊窗口的新 receiver 證明 | full-function
; VA 0x596010..0x5960a8 raw 0x195410 bytes 152 SHA256 e4075c2504fb00655fa946391f4cf534885adbf44e04f73f17da03d6a12732d6
  596010  55                                push   ebp
  596011  8bec                              mov    ebp,esp
  596013  6aff                              push   0xffffffff
  596015  68c0749400                        push   0x9474c0
  59601a  64a100000000                      mov    eax,fs:0x0
  596020  50                                push   eax
  596021  83ec14                            sub    esp,0x14
  596024  53                                push   ebx
  596025  56                                push   esi
  596026  57                                push   edi
  596027  a1201fd600                        mov    eax,ds:0xd61f20
  59602c  33c5                              xor    eax,ebp
  59602e  50                                push   eax
  59602f  8d45f4                            lea    eax,[ebp-0xc]
  596032  64a300000000                      mov    fs:0x0,eax
  596038  8bf1                              mov    esi,ecx
  59603a  33db                              xor    ebx,ebx
  59603c  895de4                            mov    DWORD PTR [ebp-0x1c],ebx
  59603f  895de8                            mov    DWORD PTR [ebp-0x18],ebx
  596042  895dec                            mov    DWORD PTR [ebp-0x14],ebx
  596045  c745e00c92c100                    mov    DWORD PTR [ebp-0x20],0xc1920c
  59604c  391d70fcf700                      cmp    DWORD PTR ds:0xf7fc70,ebx
  596052  7406                              je     0x59605a
  596054  891d70fcf700                      mov    DWORD PTR ds:0xf7fc70,ebx
  59605a  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
  596061  e85a1b0000                        call   0x597bc0
  596066  8d8eb4000000                      lea    ecx,[esi+0xb4]
  59606c  51                                push   ecx
  59606d  8bc8                              mov    ecx,eax
  59606f  8d7de0                            lea    edi,[ebp-0x20]
  596072  e8c93e0100                        call   0x5a9f40
  596077  56                                push   esi
  596078  8bf7                              mov    esi,edi
  59607a  e8f155e7ff                        call   0x40b670
  59607f  8b45e4                            mov    eax,DWORD PTR [ebp-0x1c]
  596082  c745e0e429bf00                    mov    DWORD PTR [ebp-0x20],0xbf29e4
  596089  3bc3                              cmp    eax,ebx
  59608b  7409                              je     0x596096
  59608d  50                                push   eax
  59608e  e879b12f00                        call   0x89120c
  596093  83c404                            add    esp,0x4
  596096  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  596099  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  5960a0  59                                pop    ecx
  5960a1  5f                                pop    edi
  5960a2  5e                                pop    esi
  5960a3  5b                                pop    ebx
  5960a4  8be5                              mov    esp,ebp
  5960a6  5d                                pop    ebp
  5960a7  c3                                ret

; U02 | descriptor 的 ID/window → EDI binder | full-function
; VA 0x5a9f40..0x5a9fce raw 0x1a9340 bytes 142 SHA256 517bf6a7931e0ce382ad8e162fe369d6a9d8d4a9e8c533366ba4ace5a071e3be
  5a9f40  55                                push   ebp
  5a9f41  8bec                              mov    ebp,esp
  5a9f43  81ec08020000                      sub    esp,0x208
  5a9f49  a1201fd600                        mov    eax,ds:0xd61f20
  5a9f4e  33c5                              xor    eax,ebp
  5a9f50  8945fc                            mov    DWORD PTR [ebp-0x4],eax
  5a9f53  53                                push   ebx
  5a9f54  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
  5a9f57  56                                push   esi
  5a9f58  8bf1                              mov    esi,ecx
  5a9f5a  8b06                              mov    eax,DWORD PTR [esi]
  5a9f5c  8b5010                            mov    edx,DWORD PTR [eax+0x10]
  5a9f5f  ffd2                              call   edx
  5a9f61  8985f8fdffff                      mov    DWORD PTR [ebp-0x208],eax
  5a9f67  8b06                              mov    eax,DWORD PTR [esi]
  5a9f69  8b5004                            mov    edx,DWORD PTR [eax+0x4]
  5a9f6c  8bce                              mov    ecx,esi
  5a9f6e  ffd2                              call   edx
  5a9f70  8bf0                              mov    esi,eax
  5a9f72  8b85f8fdffff                      mov    eax,DWORD PTR [ebp-0x208]
  5a9f78  53                                push   ebx
  5a9f79  56                                push   esi
  5a9f7a  8bcf                              mov    ecx,edi
  5a9f7c  e8bf98ffff                        call   0x5a3840
  5a9f81  8bd8                              mov    ebx,eax
  5a9f83  85db                              test   ebx,ebx
  5a9f85  7535                              jne    0x5a9fbc
  5a9f87  8b07                              mov    eax,DWORD PTR [edi]
  5a9f89  8b501c                            mov    edx,DWORD PTR [eax+0x1c]
  5a9f8c  56                                push   esi
  5a9f8d  8bcf                              mov    ecx,edi
  5a9f8f  ffd2                              call   edx
  5a9f91  50                                push   eax
  5a9f92  56                                push   esi
  5a9f93  689827bf00                        push   0xbf2798
  5a9f98  8d95fcfdffff                      lea    edx,[ebp-0x204]
  5a9f9e  e80d0fe6ff                        call   0x40aeb0
  5a9fa3  83c40c                            add    esp,0xc
  5a9fa6  53                                push   ebx
  5a9fa7  68c01fbf00                        push   0xbf1fc0
  5a9fac  8d85fcfdffff                      lea    eax,[ebp-0x204]
  5a9fb2  50                                push   eax
  5a9fb3  53                                push   ebx
  5a9fb4  ff158025bd00                      call   DWORD PTR ds:0xbd2580
  5a9fba  8bc3                              mov    eax,ebx
  5a9fbc  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
  5a9fbf  5e                                pop    esi
  5a9fc0  33cd                              xor    ecx,ebp
  5a9fc2  5b                                pop    ebx
  5a9fc3  e839702e00                        call   0x891001
  5a9fc8  8be5                              mov    esp,ebp
  5a9fca  5d                                pop    ebp
  5a9fcb  c20400                            ret    0x4

; U03 | binder getter → filename → manager load → hide | full-function
; VA 0x5a3840..0x5a38e4 raw 0x1a2c40 bytes 164 SHA256 969a39d4621985ff33a5a2ec1625366c43138a8df796d6dc5eeec363c4c95b21
  5a3840  55                                push   ebp
  5a3841  8bec                              mov    ebp,esp
  5a3843  56                                push   esi
  5a3844  57                                push   edi
  5a3845  8bf1                              mov    esi,ecx
  5a3847  8bf8                              mov    edi,eax
  5a3849  8b06                              mov    eax,DWORD PTR [esi]
  5a384b  8b5018                            mov    edx,DWORD PTR [eax+0x18]
  5a384e  ffd2                              call   edx
  5a3850  8b4f3c                            mov    ecx,DWORD PTR [edi+0x3c]
  5a3853  894724                            mov    DWORD PTR [edi+0x24],eax
  5a3856  85c9                              test   ecx,ecx
  5a3858  740f                              je     0x5a3869
  5a385a  f7472800000400                    test   DWORD PTR [edi+0x28],0x40000
  5a3861  7506                              jne    0x5a3869
  5a3863  50                                push   eax
  5a3864  e8874e1a00                        call   0x7486f0
  5a3869  53                                push   ebx
  5a386a  8b5f64                            mov    ebx,DWORD PTR [edi+0x64]
  5a386d  8b13                              mov    edx,DWORD PTR [ebx]
  5a386f  3bd3                              cmp    edx,ebx
  5a3871  7412                              je     0x5a3885
  5a3873  8b4724                            mov    eax,DWORD PTR [edi+0x24]
  5a3876  8b4a08                            mov    ecx,DWORD PTR [edx+0x8]
  5a3879  50                                push   eax
  5a387a  e8714e1a00                        call   0x7486f0
  5a387f  8b12                              mov    edx,DWORD PTR [edx]
  5a3881  3bd3                              cmp    edx,ebx
  5a3883  75ee                              jne    0x5a3873
  5a3885  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
  5a3888  8939                              mov    DWORD PTR [ecx],edi
  5a388a  8b16                              mov    edx,DWORD PTR [esi]
  5a388c  8b4214                            mov    eax,DWORD PTR [edx+0x14]
  5a388f  8bce                              mov    ecx,esi
  5a3891  ffd0                              call   eax
  5a3893  8b16                              mov    edx,DWORD PTR [esi]
  5a3895  8b521c                            mov    edx,DWORD PTR [edx+0x1c]
  5a3898  8bd8                              mov    ebx,eax
  5a389a  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  5a389d  8b3b                              mov    edi,DWORD PTR [ebx]
  5a389f  8d4e04                            lea    ecx,[esi+0x4]
  5a38a2  51                                push   ecx
  5a38a3  50                                push   eax
  5a38a4  8bce                              mov    ecx,esi
  5a38a6  ffd2                              call   edx
  5a38a8  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
  5a38ab  50                                push   eax
  5a38ac  8b450c                            mov    eax,DWORD PTR [ebp+0xc]
  5a38af  8b08                              mov    ecx,DWORD PTR [eax]
  5a38b1  8b4728                            mov    eax,DWORD PTR [edi+0x28]
  5a38b4  51                                push   ecx
  5a38b5  52                                push   edx
  5a38b6  8bcb                              mov    ecx,ebx
  5a38b8  ffd0                              call   eax
  5a38ba  8bf0                              mov    esi,eax
  5a38bc  5b                                pop    ebx
  5a38bd  85f6                              test   esi,esi
  5a38bf  741b                              je     0x5a38dc
  5a38c1  8b4628                            mov    eax,DWORD PTR [esi+0x28]
  5a38c4  a801                              test   al,0x1
  5a38c6  7406                              je     0x5a38ce
  5a38c8  83f001                            xor    eax,0x1
  5a38cb  894628                            mov    DWORD PTR [esi+0x28],eax
  5a38ce  8b16                              mov    edx,DWORD PTR [esi]
  5a38d0  8b8294000000                      mov    eax,DWORD PTR [edx+0x94]
  5a38d6  6a00                              push   0x0
  5a38d8  8bce                              mov    ecx,esi
  5a38da  ffd0                              call   eax
  5a38dc  5f                                pop    edi
  5a38dd  8bc6                              mov    eax,esi
  5a38df  5e                                pop    esi
  5a38e0  5d                                pop    ebp
  5a38e1  c20800                            ret    0x8

; U04 | CFXUIBinder+14 回固定 FXUICachingMgrCmdTarget singleton | full-function
; VA 0x585690..0x5856f2 raw 0x184a90 bytes 98 SHA256 1f93036c8b204a3188b8d502bb558ce3673af230d14fb33947ab3dbe8db0426b
  585690  55                                push   ebp
  585691  8bec                              mov    ebp,esp
  585693  6aff                              push   0xffffffff
  585695  68de2a9100                        push   0x912ade
  58569a  64a100000000                      mov    eax,fs:0x0
  5856a0  50                                push   eax
  5856a1  a1201fd600                        mov    eax,ds:0xd61f20
  5856a6  33c5                              xor    eax,ebp
  5856a8  50                                push   eax
  5856a9  8d45f4                            lea    eax,[ebp-0xc]
  5856ac  64a300000000                      mov    fs:0x0,eax
  5856b2  b801000000                        mov    eax,0x1
  5856b7  8405d4affa00                      test   BYTE PTR ds:0xfaafd4,al
  5856bd  751f                              jne    0x5856de
  5856bf  0905d4affa00                      or     DWORD PTR ds:0xfaafd4,eax
  5856c5  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
  5856cc  e8df88ecff                        call   0x44dfb0
  5856d1  6810cdbc00                        push   0xbccd10
  5856d6  e83fcc3000                        call   0x89231a
  5856db  83c404                            add    esp,0x4
  5856de  b8d8affa00                        mov    eax,0xfaafd8
  5856e3  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  5856e6  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  5856ed  59                                pop    ecx
  5856ee  8be5                              mov    esp,ebp
  5856f0  5d                                pop    ebp
  5856f1  c3                                ret

; U05 | cache manager constructor，寫 FAAFD8=BFC9D8 | full-function
; VA 0x44dfb0..0x44e071 raw 0x4d3b0 bytes 193 SHA256 686eebb929d65ac34aa24cbe4599201a8d8a7029ab20808fba3bc12299cc9853
  44dfb0  55                                push   ebp
  44dfb1  8bec                              mov    ebp,esp
  44dfb3  6aff                              push   0xffffffff
  44dfb5  68580d9100                        push   0x910d58
  44dfba  64a100000000                      mov    eax,fs:0x0
  44dfc0  50                                push   eax
  44dfc1  83ec14                            sub    esp,0x14
  44dfc4  a1201fd600                        mov    eax,ds:0xd61f20
  44dfc9  33c5                              xor    eax,ebp
  44dfcb  50                                push   eax
  44dfcc  8d45f4                            lea    eax,[ebp-0xc]
  44dfcf  64a300000000                      mov    fs:0x0,eax
  44dfd5  c745ecd8affa00                    mov    DWORD PTR [ebp-0x14],0xfaafd8
  44dfdc  e85f663100                        call   0x764640
  44dfe1  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
  44dfe8  6a18                              push   0x18
  44dfea  c705d8affa00d8c9bf00              mov    DWORD PTR ds:0xfaafd8,0xbfc9d8
  44dff4  c705f4affa0000000000              mov    DWORD PTR ds:0xfaaff4,0x0
  44dffe  e865324400                        call   0x891268
  44e003  83c404                            add    esp,0x4
  44e006  85c0                              test   eax,eax
  44e008  743f                              je     0x44e049
  44e00a  a3f0affa00                        mov    ds:0xfaaff0,eax
  44e00f  8900                              mov    DWORD PTR [eax],eax
  44e011  a1f0affa00                        mov    eax,ds:0xfaaff0
  44e016  894004                            mov    DWORD PTR [eax+0x4],eax
  44e019  a1f0affa00                        mov    eax,ds:0xfaaff0
  44e01e  894008                            mov    DWORD PTR [eax+0x8],eax
  44e021  8b0df0affa00                      mov    ecx,DWORD PTR ds:0xfaaff0
  44e027  b001                              mov    al,0x1
  44e029  884114                            mov    BYTE PTR [ecx+0x14],al
  44e02c  8b15f0affa00                      mov    edx,DWORD PTR ds:0xfaaff0
  44e032  884215                            mov    BYTE PTR [edx+0x15],al
  44e035  b8d8affa00                        mov    eax,0xfaafd8
  44e03a  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  44e03d  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  44e044  59                                pop    ecx
  44e045  8be5                              mov    esp,ebp
  44e047  5d                                pop    ebp
  44e048  c3                                ret
  44e049  8d45f0                            lea    eax,[ebp-0x10]
  44e04c  50                                push   eax
  44e04d  8d4de0                            lea    ecx,[ebp-0x20]
  44e050  c745f000000000                    mov    DWORD PTR [ebp-0x10],0x0
  44e057  e84d304400                        call   0x8910a9
  44e05c  68a857c800                        push   0xc857a8
  44e061  8d4de0                            lea    ecx,[ebp-0x20]
  44e064  51                                push   ecx
  44e065  c745e0a42cbd00                    mov    DWORD PTR [ebp-0x20],0xbd2ca4
  44e06c  e87fe94400                        call   0x89c9f0

; U06 | resource ID * 0x1c 對 E560B8 字串陣列索引 | full-function
; VA 0x585700..0x585726 raw 0x184b00 bytes 38 SHA256 0b4cdb53f42a76dc1a65178bf30aa03a2d9c7011924367ab68f7b6379cab17f9
  585700  55                                push   ebp
  585701  8bec                              mov    ebp,esp
  585703  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  585706  8d0cc500000000                    lea    ecx,[eax*8+0x0]
  58570d  2bc8                              sub    ecx,eax
  58570f  833c8dcc60e50008                  cmp    DWORD PTR [ecx*4+0xe560cc],0x8
  585717  8d048db860e500                    lea    eax,[ecx*4+0xe560b8]
  58571e  7202                              jb     0x585722
  585720  8b00                              mov    eax,DWORD PTR [eax]
  585722  5d                                pop    ebp
  585723  c20400                            ret    0x4

; U08 | wstring 初始化與明確輸入長度 | full-function
; VA 0x402250..0x402292 raw 0x1650 bytes 66 SHA256 e8388168722e12095e3361803df0a948b0ca2ad2d1a494d39f56473b3467761c
  402250  55                                push   ebp
  402251  8bec                              mov    ebp,esp
  402253  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
  402256  56                                push   esi
  402257  8bf1                              mov    esi,ecx
  402259  33c0                              xor    eax,eax
  40225b  c7461407000000                    mov    DWORD PTR [esi+0x14],0x7
  402262  c7461000000000                    mov    DWORD PTR [esi+0x10],0x0
  402269  668906                            mov    WORD PTR [esi],ax
  40226c  8bc2                              mov    eax,edx
  40226e  57                                push   edi
  40226f  8d7802                            lea    edi,[eax+0x2]
  402272  668b08                            mov    cx,WORD PTR [eax]
  402275  83c002                            add    eax,0x2
  402278  6685c9                            test   cx,cx
  40227b  75f5                              jne    0x402272
  40227d  2bc7                              sub    eax,edi
  40227f  d1f8                              sar    eax,1
  402281  50                                push   eax
  402282  52                                push   edx
  402283  8bce                              mov    ecx,esi
  402285  e8d6feffff                        call   0x402160
  40228a  5f                                pop    edi
  40228b  8bc6                              mov    eax,esi
  40228d  5e                                pop    esi
  40228e  5d                                pop    ebp
  40228f  c20400                            ret    0x4

; U09 | resource 212 首載／cache 未初始化／cache 重入三分支 | full-function
; VA 0x44e120..0x44e3e8 raw 0x4d520 bytes 712 SHA256 3f25a27f2b0141fe67d04397e97818ff4b367fbef8bee3d276bcaf6580556e0b
  44e120  55                                push   ebp
  44e121  8bec                              mov    ebp,esp
  44e123  83e4f8                            and    esp,0xfffffff8
  44e126  6aff                              push   0xffffffff
  44e128  68d17b9200                        push   0x927bd1
  44e12d  64a100000000                      mov    eax,fs:0x0
  44e133  50                                push   eax
  44e134  81ec38010000                      sub    esp,0x138
  44e13a  a1201fd600                        mov    eax,ds:0xd61f20
  44e13f  33c4                              xor    eax,esp
  44e141  89842430010000                    mov    DWORD PTR [esp+0x130],eax
  44e148  53                                push   ebx
  44e149  56                                push   esi
  44e14a  57                                push   edi
  44e14b  a1201fd600                        mov    eax,ds:0xd61f20
  44e150  33c4                              xor    eax,esp
  44e152  50                                push   eax
  44e153  8d842448010000                    lea    eax,[esp+0x148]
  44e15a  64a300000000                      mov    fs:0x0,eax
  44e160  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  44e163  8b7d0c                            mov    edi,DWORD PTR [ebp+0xc]
  44e166  8b5704                            mov    edx,DWORD PTR [edi+0x4]
  44e169  8b7510                            mov    esi,DWORD PTR [ebp+0x10]
  44e16c  8bd9                              mov    ebx,ecx
  44e16e  8b4d14                            mov    ecx,DWORD PTR [ebp+0x14]
  44e171  8944241c                          mov    DWORD PTR [esp+0x1c],eax
  44e175  8d442418                          lea    eax,[esp+0x18]
  44e179  894c2420                          mov    DWORD PTR [esp+0x20],ecx
  44e17d  50                                push   eax
  44e17e  8d4b14                            lea    ecx,[ebx+0x14]
  44e181  8d442428                          lea    eax,[esp+0x28]
  44e185  897c2430                          mov    DWORD PTR [esp+0x30],edi
  44e189  8974242c                          mov    DWORD PTR [esp+0x2c],esi
  44e18d  8954241c                          mov    DWORD PTR [esp+0x1c],edx
  44e191  e86a0d3e00                        call   0x82ef00
  44e196  8b4c2424                          mov    ecx,DWORD PTR [esp+0x24]
  44e19a  3b4b18                            cmp    ecx,DWORD PTR [ebx+0x18]
  44e19d  0f84e1000000                      je     0x44e284
  44e1a3  8b7110                            mov    esi,DWORD PTR [ecx+0x10]
  44e1a6  8b16                              mov    edx,DWORD PTR [esi]
  44e1a8  8b4208                            mov    eax,DWORD PTR [edx+0x8]
  44e1ab  8bce                              mov    ecx,esi
  44e1ad  ffd0                              call   eax
  44e1af  85c0                              test   eax,eax
  44e1b1  0f858e000000                      jne    0x44e245
  44e1b7  8d8c24c4000000                    lea    ecx,[esp+0xc4]
  44e1be  51                                push   ecx
  44e1bf  e8bc0b2e00                        call   0x72ed80
  44e1c4  8b542428                          mov    edx,DWORD PTR [esp+0x28]
  44e1c8  52                                push   edx
  44e1c9  8d8c24c8000000                    lea    ecx,[esp+0xc8]
  44e1d0  c784245401000000000000            mov    DWORD PTR [esp+0x154],0x0
  44e1db  e8106b3100                        call   0x764cf0
  44e1e0  83c404                            add    esp,0x4
  44e1e3  84c0                              test   al,al
  44e1e5  751e                              jne    0x44e205
  44e1e7  8d8c24c4000000                    lea    ecx,[esp+0xc4]
  44e1ee  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
  44e1f9  e8b29dfbff                        call   0x407fb0
  44e1fe  33c0                              xor    eax,eax
  44e200  e9bd010000                        jmp    0x44e3c2
  44e205  8b44241c                          mov    eax,DWORD PTR [esp+0x1c]
  44e209  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
  44e20d  57                                push   edi
  44e20e  50                                push   eax
  44e20f  53                                push   ebx
  44e210  8d9424d0000000                    lea    edx,[esp+0xd0]
  44e217  e804633100                        call   0x764520
  44e21c  8b16                              mov    edx,DWORD PTR [esi]
  44e21e  8bf8                              mov    edi,eax
  44e220  8b420c                            mov    eax,DWORD PTR [edx+0xc]
  44e223  6a01                              push   0x1
  44e225  8bce                              mov    ecx,esi
  44e227  ffd0                              call   eax
  44e229  8d8c24c4000000                    lea    ecx,[esp+0xc4]
  44e230  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
  44e23b  e8709dfbff                        call   0x407fb0
  44e240  e97b010000                        jmp    0x44e3c0
  44e245  8b16                              mov    edx,DWORD PTR [esi]
  44e247  8b4210                            mov    eax,DWORD PTR [edx+0x10]
  44e24a  8bce                              mov    ecx,esi
  44e24c  ffd0                              call   eax
  44e24e  8b74241c                          mov    esi,DWORD PTR [esp+0x1c]
  44e252  8bf8                              mov    edi,eax
  44e254  57                                push   edi
  44e255  56                                push   esi
  44e256  8bc3                              mov    eax,ebx
  44e258  897c2420                          mov    DWORD PTR [esp+0x20],edi
  44e25c  e85f040000                        call   0x44e6c0
  44e261  8b4c2420                          mov    ecx,DWORD PTR [esp+0x20]
  44e265  897720                            mov    DWORD PTR [edi+0x20],esi
  44e268  85c9                              test   ecx,ecx
  44e26a  0f8450010000                      je     0x44e3c0
  44e270  8d442418                          lea    eax,[esp+0x18]
  44e274  8bf9                              mov    edi,ecx
  44e276  e8955affff                        call   0x443d10
  44e27b  8b7c2418                          mov    edi,DWORD PTR [esp+0x18]
  44e27f  e93c010000                        jmp    0x44e3c0
  44e284  8d4c244c                          lea    ecx,[esp+0x4c]
  44e288  51                                push   ecx
  44e289  e8f20a2e00                        call   0x72ed80
  44e28e  56                                push   esi
  44e28f  8d7c2434                          lea    edi,[esp+0x34]
  44e293  c784245401000001000000            mov    DWORD PTR [esp+0x154],0x1
  44e29e  e89d120300                        call   0x47f540
  44e2a3  83c404                            add    esp,0x4
  44e2a6  c684245001000002                  mov    BYTE PTR [esp+0x150],0x2
  44e2ae  8b4c2430                          mov    ecx,DWORD PTR [esp+0x30]
  44e2b2  bf10000000                        mov    edi,0x10
  44e2b7  397c2444                          cmp    DWORD PTR [esp+0x44],edi
  44e2bb  7304                              jae    0x44e2c1
  44e2bd  8d4c2430                          lea    ecx,[esp+0x30]
  44e2c1  6a01                              push   0x1
  44e2c3  8d742450                          lea    esi,[esp+0x50]
  44e2c7  e8440e2e00                        call   0x72f110
  44e2cc  c684245001000001                  mov    BYTE PTR [esp+0x150],0x1
  44e2d4  88442417                          mov    BYTE PTR [esp+0x17],al
  44e2d8  397c2444                          cmp    DWORD PTR [esp+0x44],edi
  44e2dc  720d                              jb     0x44e2eb
  44e2de  8b542430                          mov    edx,DWORD PTR [esp+0x30]
  44e2e2  52                                push   edx
  44e2e3  e8242f4400                        call   0x89120c
  44e2e8  83c404                            add    esp,0x4
  44e2eb  33f6                              xor    esi,esi
  44e2ed  807c241700                        cmp    BYTE PTR [esp+0x17],0x0
  44e2f2  bf0f000000                        mov    edi,0xf
  44e2f7  897c2444                          mov    DWORD PTR [esp+0x44],edi
  44e2fb  89742440                          mov    DWORD PTR [esp+0x40],esi
  44e2ff  c644243000                        mov    BYTE PTR [esp+0x30],0x0
  44e304  7550                              jne    0x44e356
  44e306  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
  44e311  83bc24ac00000010                  cmp    DWORD PTR [esp+0xac],0x10
  44e319  c744244c9423bf00                  mov    DWORD PTR [esp+0x4c],0xbf2394
  44e321  7210                              jb     0x44e333
  44e323  8b842498000000                    mov    eax,DWORD PTR [esp+0x98]
  44e32a  50                                push   eax
  44e32b  e8dc2e4400                        call   0x89120c
  44e330  83c404                            add    esp,0x4
  44e333  8d4c244c                          lea    ecx,[esp+0x4c]
  44e337  89bc24ac000000                    mov    DWORD PTR [esp+0xac],edi
  44e33e  89b424a8000000                    mov    DWORD PTR [esp+0xa8],esi
  44e345  c684249800000000                  mov    BYTE PTR [esp+0x98],0x0
  44e34d  e8eefc2d00                        call   0x72e040
  44e352  33c0                              xor    eax,eax
  44e354  eb6c                              jmp    0x44e3c2
  44e356  8b4c242c                          mov    ecx,DWORD PTR [esp+0x2c]
  44e35a  8b54241c                          mov    edx,DWORD PTR [esp+0x1c]
  44e35e  51                                push   ecx
  44e35f  8b4c2424                          mov    ecx,DWORD PTR [esp+0x24]
  44e363  52                                push   edx
  44e364  53                                push   ebx
  44e365  8d542458                          lea    edx,[esp+0x58]
  44e369  e8b2613100                        call   0x764520
  44e36e  c7842450010000ffffffff            mov    DWORD PTR [esp+0x150],0xffffffff
  44e379  83bc24ac00000010                  cmp    DWORD PTR [esp+0xac],0x10
  44e381  8bf8                              mov    edi,eax
  44e383  c744244c9423bf00                  mov    DWORD PTR [esp+0x4c],0xbf2394
  44e38b  7210                              jb     0x44e39d
  44e38d  8b842498000000                    mov    eax,DWORD PTR [esp+0x98]
  44e394  50                                push   eax
  44e395  e8722e4400                        call   0x89120c
  44e39a  83c404                            add    esp,0x4
  44e39d  8d4c244c                          lea    ecx,[esp+0x4c]
  44e3a1  c78424ac0000000f000000            mov    DWORD PTR [esp+0xac],0xf
  44e3ac  89b424a8000000                    mov    DWORD PTR [esp+0xa8],esi
  44e3b3  c684249800000000                  mov    BYTE PTR [esp+0x98],0x0
  44e3bb  e880fc2d00                        call   0x72e040
  44e3c0  8bc7                              mov    eax,edi
  44e3c2  8b8c2448010000                    mov    ecx,DWORD PTR [esp+0x148]
  44e3c9  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  44e3d0  59                                pop    ecx
  44e3d1  5f                                pop    edi
  44e3d2  5e                                pop    esi
  44e3d3  5b                                pop    ebx
  44e3d4  8b8c2430010000                    mov    ecx,DWORD PTR [esp+0x130]
  44e3db  33cc                              xor    ecx,esp
  44e3dd  e81f2c4400                        call   0x891001
  44e3e2  8be5                              mov    esp,ebp
  44e3e4  5d                                pop    ebp
  44e3e5  c21000                            ret    0x10

; U10 | cache 首載的 wide path→TiXmlDocument LoadFile adapter | full-function
; VA 0x764cf0..0x764d7b raw 0x3640f0 bytes 139 SHA256 7914482fa9965ff830ea74c653ff1a65f8c87ada83c197f4e6724f6568bdde67
  764cf0  55                                push   ebp
  764cf1  8bec                              mov    ebp,esp
  764cf3  6aff                              push   0xffffffff
  764cf5  68287e9100                        push   0x917e28
  764cfa  64a100000000                      mov    eax,fs:0x0
  764d00  50                                push   eax
  764d01  83ec20                            sub    esp,0x20
  764d04  a1201fd600                        mov    eax,ds:0xd61f20
  764d09  33c5                              xor    eax,ebp
  764d0b  8945f0                            mov    DWORD PTR [ebp-0x10],eax
  764d0e  53                                push   ebx
  764d0f  56                                push   esi
  764d10  57                                push   edi
  764d11  50                                push   eax
  764d12  8d45f4                            lea    eax,[ebp-0xc]
  764d15  64a300000000                      mov    fs:0x0,eax
  764d1b  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  764d1e  50                                push   eax
  764d1f  8d7dd4                            lea    edi,[ebp-0x2c]
  764d22  8bf1                              mov    esi,ecx
  764d24  e817a8d1ff                        call   0x47f540
  764d29  83c404                            add    esp,0x4
  764d2c  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
  764d33  8b4dd4                            mov    ecx,DWORD PTR [ebp-0x2c]
  764d36  bf10000000                        mov    edi,0x10
  764d3b  397de8                            cmp    DWORD PTR [ebp-0x18],edi
  764d3e  7303                              jae    0x764d43
  764d40  8d4dd4                            lea    ecx,[ebp-0x2c]
  764d43  6a01                              push   0x1
  764d45  e8c6a3fcff                        call   0x72f110
  764d4a  8ad8                              mov    bl,al
  764d4c  397de8                            cmp    DWORD PTR [ebp-0x18],edi
  764d4f  720c                              jb     0x764d5d
  764d51  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
  764d54  50                                push   eax
  764d55  e8b2c41200                        call   0x89120c
  764d5a  83c404                            add    esp,0x4
  764d5d  8ac3                              mov    al,bl
  764d5f  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  764d62  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  764d69  59                                pop    ecx
  764d6a  5f                                pop    edi
  764d6b  5e                                pop    esi
  764d6c  5b                                pop    ebx
  764d6d  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
  764d70  33cd                              xor    ecx,ebp
  764d72  e88ac21200                        call   0x891001
  764d77  8be5                              mov    esp,ebp
  764d79  5d                                pop    ebp
  764d7a  c3                                ret

; U11 | TiXmlDocument file open→read/parse→file close | full-function
; VA 0x72f110..0x72f255 raw 0x32e510 bytes 325 SHA256 d91691f227399e2554d794197459552e09292bce0199c241196994928401ca51
  72f110  55                                push   ebp
  72f111  8bec                              mov    ebp,esp
  72f113  6aff                              push   0xffffffff
  72f115  68f84b9100                        push   0x914bf8
  72f11a  64a100000000                      mov    eax,fs:0x0
  72f120  50                                push   eax
  72f121  83ec2c                            sub    esp,0x2c
  72f124  a1201fd600                        mov    eax,ds:0xd61f20
  72f129  33c5                              xor    eax,ebp
  72f12b  8945f0                            mov    DWORD PTR [ebp-0x10],eax
  72f12e  53                                push   ebx
  72f12f  57                                push   edi
  72f130  50                                push   eax
  72f131  8d45f4                            lea    eax,[ebp-0xc]
  72f134  64a300000000                      mov    fs:0x0,eax
  72f13a  33db                              xor    ebx,ebx
  72f13c  8bc1                              mov    eax,ecx
  72f13e  c745e80f000000                    mov    DWORD PTR [ebp-0x18],0xf
  72f145  895de4                            mov    DWORD PTR [ebp-0x1c],ebx
  72f148  885dd4                            mov    BYTE PTR [ebp-0x2c],bl
  72f14b  8d7801                            lea    edi,[eax+0x1]
  72f14e  8bff                              mov    edi,edi
  72f150  8a10                              mov    dl,BYTE PTR [eax]
  72f152  40                                inc    eax
  72f153  84d2                              test   dl,dl
  72f155  75f9                              jne    0x72f150
  72f157  2bc7                              sub    eax,edi
  72f159  50                                push   eax
  72f15a  51                                push   ecx
  72f15b  8d4dd4                            lea    ecx,[ebp-0x2c]
  72f15e  e80d39cdff                        call   0x402a70
  72f163  6aff                              push   0xffffffff
  72f165  53                                push   ebx
  72f166  8d45d4                            lea    eax,[ebp-0x2c]
  72f169  8d7e20                            lea    edi,[esi+0x20]
  72f16c  50                                push   eax
  72f16d  8bcf                              mov    ecx,edi
  72f16f  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
  72f172  e8c93ecdff                        call   0x403040
  72f177  837f1410                          cmp    DWORD PTR [edi+0x14],0x10
  72f17b  7204                              jb     0x72f181
  72f17d  8b07                              mov    eax,DWORD PTR [edi]
  72f17f  eb02                              jmp    0x72f183
  72f181  8bc7                              mov    eax,edi
  72f183  68e0d1be00                        push   0xbed1e0
  72f188  50                                push   eax
  72f189  e8e255feff                        call   0x714770
  72f18e  8bd8                              mov    ebx,eax
  72f190  83c408                            add    esp,0x8
  72f193  85db                              test   ebx,ebx
  72f195  7430                              je     0x72f1c7
  72f197  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
  72f19a  51                                push   ecx
  72f19b  8bd3                              mov    edx,ebx
  72f19d  8bce                              mov    ecx,esi
  72f19f  e8bc000000                        call   0x72f260
  72f1a4  8b13                              mov    edx,DWORD PTR [ebx]
  72f1a6  8845d3                            mov    BYTE PTR [ebp-0x2d],al
  72f1a9  8b4204                            mov    eax,DWORD PTR [edx+0x4]
  72f1ac  8bcb                              mov    ecx,ebx
  72f1ae  ffd0                              call   eax
  72f1b0  837de810                          cmp    DWORD PTR [ebp-0x18],0x10
  72f1b4  720c                              jb     0x72f1c2
  72f1b6  8b4dd4                            mov    ecx,DWORD PTR [ebp-0x2c]
  72f1b9  51                                push   ecx
  72f1ba  e84d201600                        call   0x89120c
  72f1bf  83c404                            add    esp,0x4
  72f1c2  8a45d3                            mov    al,BYTE PTR [ebp-0x2d]
  72f1c5  eb71                              jmp    0x72f238
  72f1c7  807e4400                          cmp    BYTE PTR [esi+0x44],0x0
  72f1cb  7557                              jne    0x72f224
  72f1cd  c6464401                          mov    BYTE PTR [esi+0x44],0x1
  72f1d1  c7464802000000                    mov    DWORD PTR [esi+0x48],0x2
  72f1d8  8b15903cd600                      mov    edx,DWORD PTR ds:0xd63c90
  72f1de  8bc2                              mov    eax,edx
  72f1e0  8d5801                            lea    ebx,[eax+0x1]
  72f1e3  8a08                              mov    cl,BYTE PTR [eax]
  72f1e5  40                                inc    eax
  72f1e6  84c9                              test   cl,cl
  72f1e8  75f9                              jne    0x72f1e3
  72f1ea  2bc3                              sub    eax,ebx
  72f1ec  50                                push   eax
  72f1ed  52                                push   edx
  72f1ee  8d4e4c                            lea    ecx,[esi+0x4c]
  72f1f1  e87a38cdff                        call   0x402a70
  72f1f6  83c8ff                            or     eax,0xffffffff
  72f1f9  894670                            mov    DWORD PTR [esi+0x70],eax
  72f1fc  89466c                            mov    DWORD PTR [esi+0x6c],eax
  72f1ff  837f1410                          cmp    DWORD PTR [edi+0x14],0x10
  72f203  c745ccf451c400                    mov    DWORD PTR [ebp-0x34],0xc451f4
  72f20a  7202                              jb     0x72f20e
  72f20c  8b3f                              mov    edi,DWORD PTR [edi]
  72f20e  6a00                              push   0x0
  72f210  6a00                              push   0x0
  72f212  6a00                              push   0x0
  72f214  8d55cc                            lea    edx,[ebp-0x34]
  72f217  52                                push   edx
  72f218  8bd7                              mov    edx,edi
  72f21a  b902000000                        mov    ecx,0x2
  72f21f  e8bc2b0000                        call   0x731de0
  72f224  837de810                          cmp    DWORD PTR [ebp-0x18],0x10
  72f228  720c                              jb     0x72f236
  72f22a  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
  72f22d  50                                push   eax
  72f22e  e8d91f1600                        call   0x89120c
  72f233  83c404                            add    esp,0x4
  72f236  32c0                              xor    al,al
  72f238  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  72f23b  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  72f242  59                                pop    ecx
  72f243  5f                                pop    edi
  72f244  5b                                pop    ebx
  72f245  8b4df0                            mov    ecx,DWORD PTR [ebp-0x10]
  72f248  33cd                              xor    ecx,ebp
  72f24a  e8b21d1600                        call   0x891001
  72f24f  8be5                              mov    esp,ebp
  72f251  5d                                pop    ebp
  72f252  c20400                            ret    0x4

; U12 | CMDTARGET root→ClassID→root+18=self→typed deserialize | full-function
; VA 0x764520..0x764638 raw 0x363920 bytes 280 SHA256 41425ccd0aace8b9362b262b685b878df236e838b66cd99fc2ca73f804f2c9f5
  764520  55                                push   ebp
  764521  8bec                              mov    ebp,esp
  764523  83ec30                            sub    esp,0x30
  764526  a1201fd600                        mov    eax,ds:0xd61f20
  76452b  33c5                              xor    eax,ebp
  76452d  8945fc                            mov    DWORD PTR [ebp-0x4],eax
  764530  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  764533  53                                push   ebx
  764534  8b5d10                            mov    ebx,DWORD PTR [ebp+0x10]
  764537  56                                push   esi
  764538  57                                push   edi
  764539  8bfa                              mov    edi,edx
  76453b  8945d8                            mov    DWORD PTR [ebp-0x28],eax
  76453e  895ddc                            mov    DWORD PTR [ebp-0x24],ebx
  764541  894dd0                            mov    DWORD PTR [ebp-0x30],ecx
  764544  85ff                              test   edi,edi
  764546  0f84c8000000                      je     0x764614
  76454c  ba481fbf00                        mov    edx,0xbf1f48
  764551  8d75e0                            lea    esi,[ebp-0x20]
  764554  e85752ccff                        call   0x4297b0
  764559  8b45e0                            mov    eax,DWORD PTR [ebp-0x20]
  76455c  be10000000                        mov    esi,0x10
  764561  3975f4                            cmp    DWORD PTR [ebp-0xc],esi
  764564  7303                              jae    0x764569
  764566  8d45e0                            lea    eax,[ebp-0x20]
  764569  50                                push   eax
  76456a  8bc7                              mov    eax,edi
  76456c  e86f9dfcff                        call   0x72e2e0
  764571  8bf8                              mov    edi,eax
  764573  3975f4                            cmp    DWORD PTR [ebp-0xc],esi
  764576  720c                              jb     0x764584
  764578  8b55e0                            mov    edx,DWORD PTR [ebp-0x20]
  76457b  52                                push   edx
  76457c  e88bcc1200                        call   0x89120c
  764581  83c404                            add    esp,0x4
  764584  c745f40f000000                    mov    DWORD PTR [ebp-0xc],0xf
  76458b  c745f000000000                    mov    DWORD PTR [ebp-0x10],0x0
  764592  c645e000                          mov    BYTE PTR [ebp-0x20],0x0
  764596  85ff                              test   edi,edi
  764598  747a                              je     0x764614
  76459a  8d45d4                            lea    eax,[ebp-0x2c]
  76459d  50                                push   eax
  76459e  ba589ec400                        mov    edx,0xc49e58
  7645a3  8bcf                              mov    ecx,edi
  7645a5  c745d400000000                    mov    DWORD PTR [ebp-0x2c],0x0
  7645ac  e8af52ccff                        call   0x429860
  7645b1  83c404                            add    esp,0x4
  7645b4  85db                              test   ebx,ebx
  7645b6  7517                              jne    0x7645cf
  7645b8  8b4dd8                            mov    ecx,DWORD PTR [ebp-0x28]
  7645bb  8b11                              mov    edx,DWORD PTR [ecx]
  7645bd  8b45d4                            mov    eax,DWORD PTR [ebp-0x2c]
  7645c0  8b522c                            mov    edx,DWORD PTR [edx+0x2c]
  7645c3  50                                push   eax
  7645c4  ffd2                              call   edx
  7645c6  8bd8                              mov    ebx,eax
  7645c8  895ddc                            mov    DWORD PTR [ebp-0x24],ebx
  7645cb  85db                              test   ebx,ebx
  7645cd  7454                              je     0x764623
  7645cf  8bf3                              mov    esi,ebx
  7645d1  895b18                            mov    DWORD PTR [ebx+0x18],ebx
  7645d4  e887260100                        call   0x776c60
  7645d9  84c0                              test   al,al
  7645db  7446                              je     0x764623
  7645dd  8b750c                            mov    esi,DWORD PTR [ebp+0xc]
  7645e0  8b45d8                            mov    eax,DWORD PTR [ebp-0x28]
  7645e3  53                                push   ebx
  7645e4  56                                push   esi
  7645e5  e8d6a0ceff                        call   0x44e6c0
  7645ea  8b7dd0                            mov    edi,DWORD PTR [ebp-0x30]
  7645ed  897320                            mov    DWORD PTR [ebx+0x20],esi
  7645f0  85ff                              test   edi,edi
  7645f2  740b                              je     0x7645ff
  7645f4  8d45dc                            lea    eax,[ebp-0x24]
  7645f7  e814f7cdff                        call   0x443d10
  7645fc  8b5ddc                            mov    ebx,DWORD PTR [ebp-0x24]
  7645ff  8bc3                              mov    eax,ebx
  764601  5f                                pop    edi
  764602  5e                                pop    esi
  764603  5b                                pop    ebx
  764604  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
  764607  33cd                              xor    ecx,ebp
  764609  e8f3c91200                        call   0x891001
  76460e  8be5                              mov    esp,ebp
  764610  5d                                pop    ebp
  764611  c20c00                            ret    0xc
  764614  85db                              test   ebx,ebx
  764616  740b                              je     0x764623
  764618  8b03                              mov    eax,DWORD PTR [ebx]
  76461a  8b501c                            mov    edx,DWORD PTR [eax+0x1c]
  76461d  6a01                              push   0x1
  76461f  8bcb                              mov    ecx,ebx
  764621  ffd2                              call   edx
  764623  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
  764626  5f                                pop    edi
  764627  5e                                pop    esi
  764628  33cd                              xor    ecx,ebp
  76462a  33c0                              xor    eax,eax
  76462c  5b                                pop    ebx
  76462d  e8cfc91200                        call   0x891001
  764632  8be5                              mov    esp,ebp
  764634  5d                                pop    ebp
  764635  c20c00                            ret    0xc

; U13 | ClassID 與實例 v+4 相等才呼 v+14 | full-function
; VA 0x776c60..0x776ca0 raw 0x376060 bytes 64 SHA256 fb481aef124bd24f982d22a407b3c3e668b82bee8bdf5cef23ed6410813e3fdf
  776c60  55                                push   ebp
  776c61  8bec                              mov    ebp,esp
  776c63  51                                push   ecx
  776c64  8d45fc                            lea    eax,[ebp-0x4]
  776c67  50                                push   eax
  776c68  ba589ec400                        mov    edx,0xc49e58
  776c6d  8bcf                              mov    ecx,edi
  776c6f  c745fc00000000                    mov    DWORD PTR [ebp-0x4],0x0
  776c76  e8e52bcbff                        call   0x429860
  776c7b  8b16                              mov    edx,DWORD PTR [esi]
  776c7d  8b4204                            mov    eax,DWORD PTR [edx+0x4]
  776c80  83c404                            add    esp,0x4
  776c83  8bce                              mov    ecx,esi
  776c85  ffd0                              call   eax
  776c87  3945fc                            cmp    DWORD PTR [ebp-0x4],eax
  776c8a  750e                              jne    0x776c9a
  776c8c  8b16                              mov    edx,DWORD PTR [esi]
  776c8e  8b4214                            mov    eax,DWORD PTR [edx+0x14]
  776c91  57                                push   edi
  776c92  8bce                              mov    ecx,esi
  776c94  ffd0                              call   eax
  776c96  8be5                              mov    esp,ebp
  776c98  5d                                pop    ebp
  776c99  c3                                ret
  776c9a  32c0                              xor    al,al
  776c9c  8be5                              mov    esp,ebp
  776c9e  5d                                pop    ebp
  776c9f  c3                                ret

; U14 | 自訂 child out-parameter hook，只 RET 0xc | full-function
; VA 0x49ae10..0x49ae13 raw 0x9a210 bytes 3 SHA256 dbd1a662565b07272069f88faadf4327acaf51b7d14f236c84c0a9679d07cef3
  49ae10  c20c00                            ret    0xc

; U15 | 通用 child factory forwarder | full-function
; VA 0x746fe0..0x746ff3 raw 0x3463e0 bytes 19 SHA256 81ed7e4da173b23a0d8cafb8907e7181ab4a1987bc187554241446ce88f11ce7
  746fe0  55                                push   ebp
  746fe1  8bec                              mov    ebp,esp
  746fe3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  746fe6  50                                push   eax
  746fe7  e814000000                        call   0x747000
  746fec  83c404                            add    esp,0x4
  746fef  5d                                pop    ebp
  746ff0  c20400                            ret    0x4

; U16 | dock factory 的三個 code／allocation／vptr | full-function
; VA 0x76e0c0..0x76e154 raw 0x36d4c0 bytes 148 SHA256 293d00ed2ab59f5917076e4d4835ad611c42465439197f2564df3aec3dd55aa9
  76e0c0  2dc4030100                        sub    eax,0x103c4
  76e0c5  745c                              je     0x76e123
  76e0c7  48                                dec    eax
  76e0c8  741f                              je     0x76e0e9
  76e0ca  48                                dec    eax
  76e0cb  0f8580000000                      jne    0x76e151
  76e0d1  6a0c                              push   0xc
  76e0d3  e8903f1200                        call   0x892068
  76e0d8  33d2                              xor    edx,edx
  76e0da  83c404                            add    esp,0x4
  76e0dd  3bc2                              cmp    eax,edx
  76e0df  7470                              je     0x76e151
  76e0e1  c700f4d4c400                      mov    DWORD PTR [eax],0xc4d4f4
  76e0e7  eb50                              jmp    0x76e139
  76e0e9  6a1c                              push   0x1c
  76e0eb  e8783f1200                        call   0x892068
  76e0f0  33d2                              xor    edx,edx
  76e0f2  83c404                            add    esp,0x4
  76e0f5  3bc2                              cmp    eax,edx
  76e0f7  7458                              je     0x76e151
  76e0f9  8b0d28a8fb00                      mov    ecx,DWORD PTR ds:0xfba828
  76e0ff  41                                inc    ecx
  76e100  894804                            mov    DWORD PTR [eax+0x4],ecx
  76e103  c7400806000000                    mov    DWORD PTR [eax+0x8],0x6
  76e10a  c700b4d4c400                      mov    DWORD PTR [eax],0xc4d4b4
  76e110  895018                            mov    DWORD PTR [eax+0x18],edx
  76e113  895014                            mov    DWORD PTR [eax+0x14],edx
  76e116  895010                            mov    DWORD PTR [eax+0x10],edx
  76e119  89500c                            mov    DWORD PTR [eax+0xc],edx
  76e11c  890d28a8fb00                      mov    DWORD PTR ds:0xfba828,ecx
  76e122  c3                                ret
  76e123  6a0c                              push   0xc
  76e125  e83e3f1200                        call   0x892068
  76e12a  33d2                              xor    edx,edx
  76e12c  83c404                            add    esp,0x4
  76e12f  3bc2                              cmp    eax,edx
  76e131  741e                              je     0x76e151
  76e133  c70074d4c400                      mov    DWORD PTR [eax],0xc4d474
  76e139  8b0d28a8fb00                      mov    ecx,DWORD PTR ds:0xfba828
  76e13f  41                                inc    ecx
  76e140  c7400806000000                    mov    DWORD PTR [eax+0x8],0x6
  76e147  894804                            mov    DWORD PTR [eax+0x4],ecx
  76e14a  890d28a8fb00                      mov    DWORD PTR ds:0xfba828,ecx
  76e150  c3                                ret
  76e151  33c0                              xor    eax,eax
  76e153  c3                                ret

; U17 | type 1400 FXUIPicture constructor | full-function
; VA 0x745040..0x745059 raw 0x344440 bytes 25 SHA256 5d2f48a19e097406b5b4306f9686d1ab41dca2b6ef3ecd7616b5e179b8b0a612
  745040  56                                push   esi
  745041  8bf1                              mov    esi,ecx
  745043  e8d8f2ffff                        call   0x744320
  745048  c7067c69c400                      mov    DWORD PTR [esi],0xc4697c
  74504e  c686a400000000                    mov    BYTE PTR [esi+0xa4],0x0
  745055  8bc6                              mov    eax,esi
  745057  5e                                pop    esi
  745058  c3                                ret

; U18 | talk ClassID getter = 53000 | full-function
; VA 0x40ecf0..0x40ecf6 raw 0xe0f0 bytes 6 SHA256 561e68fa320b1151c763f308c9ea4a21c57b06e6d88dc15ee6f9115072abb59b
  40ecf0  b808cf0000                        mov    eax,0xcf08
  40ecf5  c3                                ret

; U19 | descriptor+8 cache state getter | full-function
; VA 0x409510..0x409514 raw 0x8910 bytes 4 SHA256 916ae10aa3fd76a4d5b25b2fb66e9df0fd04957c7ab10930268d1ed7808be689
  409510  8b4108                            mov    eax,DWORD PTR [ecx+0x8]
  409513  c3                                ret

; U20 | descriptor+8 cache state setter | full-function
; VA 0x409520..0x40952d raw 0x8920 bytes 13 SHA256 7dd3c0df92e475b5ecdbd89e4b18571bfe34961f32b51a9f9c3b8326dfd56f3c
  409520  55                                push   ebp
  409521  8bec                              mov    ebp,esp
  409523  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  409526  894108                            mov    DWORD PTR [ecx+0x8],eax
  409529  5d                                pop    ebp
  40952a  c20400                            ret    0x4

; U26 | 普通 base-page cleanup 明確卸下 resource 212 | full-function
; VA 0x5960b0..0x59613b raw 0x1954b0 bytes 139 SHA256 03e1b2f8fecad69d920ca4e02efc13d94879e8cd265c294ffe3626d00ac53a8c
  5960b0  55                                push   ebp
  5960b1  8bec                              mov    ebp,esp
  5960b3  6aff                              push   0xffffffff
  5960b5  6870249100                        push   0x912470
  5960ba  64a100000000                      mov    eax,fs:0x0
  5960c0  50                                push   eax
  5960c1  83ec14                            sub    esp,0x14
  5960c4  56                                push   esi
  5960c5  57                                push   edi
  5960c6  a1201fd600                        mov    eax,ds:0xd61f20
  5960cb  33c5                              xor    eax,ebp
  5960cd  50                                push   eax
  5960ce  8d45f4                            lea    eax,[ebp-0xc]
  5960d1  64a300000000                      mov    fs:0x0,eax
  5960d7  8bf1                              mov    esi,ecx
  5960d9  33ff                              xor    edi,edi
  5960db  897de4                            mov    DWORD PTR [ebp-0x1c],edi
  5960de  897de8                            mov    DWORD PTR [ebp-0x18],edi
  5960e1  897dec                            mov    DWORD PTR [ebp-0x14],edi
  5960e4  c745e00c92c100                    mov    DWORD PTR [ebp-0x20],0xc1920c
  5960eb  393d70fcf700                      cmp    DWORD PTR ds:0xf7fc70,edi
  5960f1  7406                              je     0x5960f9
  5960f3  893d70fcf700                      mov    DWORD PTR ds:0xf7fc70,edi
  5960f9  68d4000000                        push   0xd4
  5960fe  8d4de0                            lea    ecx,[ebp-0x20]
  596101  c745fc01000000                    mov    DWORD PTR [ebp-0x4],0x1
  596108  e8d334e7ff                        call   0x4095e0
  59610d  56                                push   esi
  59610e  e87d0b0000                        call   0x596c90
  596113  8b45e4                            mov    eax,DWORD PTR [ebp-0x1c]
  596116  c745e0e429bf00                    mov    DWORD PTR [ebp-0x20],0xbf29e4
  59611d  3bc7                              cmp    eax,edi
  59611f  7409                              je     0x59612a
  596121  50                                push   eax
  596122  e8e5b02f00                        call   0x89120c
  596127  83c404                            add    esp,0x4
  59612a  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  59612d  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  596134  59                                pop    ecx
  596135  5f                                pop    edi
  596136  5e                                pop    esi
  596137  8be5                              mov    esp,ebp
  596139  5d                                pop    ebp
  59613a  c3                                ret

; U27 | binder unbind：先 parent+74 detach，再 manager+30 remove | full-function
; VA 0x4095e0..0x4096a3 raw 0x89e0 bytes 195 SHA256 765083aae1757a323616aa16d5ddf88fd617b78d3f93aa36800b30bec6d840a2
  4095e0  55                                push   ebp
  4095e1  8bec                              mov    ebp,esp
  4095e3  81ec0c020000                      sub    esp,0x20c
  4095e9  a1201fd600                        mov    eax,ds:0xd61f20
  4095ee  33c5                              xor    eax,ebp
  4095f0  8945fc                            mov    DWORD PTR [ebp-0x4],eax
  4095f3  53                                push   ebx
  4095f4  56                                push   esi
  4095f5  8bf1                              mov    esi,ecx
  4095f7  8b06                              mov    eax,DWORD PTR [esi]
  4095f9  8b5014                            mov    edx,DWORD PTR [eax+0x14]
  4095fc  57                                push   edi
  4095fd  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
  409600  89bdf4fdffff                      mov    DWORD PTR [ebp-0x20c],edi
  409606  ffd2                              call   edx
  409608  8bd8                              mov    ebx,eax
  40960a  8d85f4fdffff                      lea    eax,[ebp-0x20c]
  409610  50                                push   eax
  409611  8d4b04                            lea    ecx,[ebx+0x4]
  409614  8d85f8fdffff                      lea    eax,[ebp-0x208]
  40961a  e8e1584200                        call   0x82ef00
  40961f  8b85f8fdffff                      mov    eax,DWORD PTR [ebp-0x208]
  409625  3b4308                            cmp    eax,DWORD PTR [ebx+0x8]
  409628  7416                              je     0x409640
  40962a  8b4010                            mov    eax,DWORD PTR [eax+0x10]
  40962d  85c0                              test   eax,eax
  40962f  740f                              je     0x409640
  409631  8b4860                            mov    ecx,DWORD PTR [eax+0x60]
  409634  85c9                              test   ecx,ecx
  409636  7408                              je     0x409640
  409638  8b11                              mov    edx,DWORD PTR [ecx]
  40963a  50                                push   eax
  40963b  8b4274                            mov    eax,DWORD PTR [edx+0x74]
  40963e  ffd0                              call   eax
  409640  8b16                              mov    edx,DWORD PTR [esi]
  409642  8b4214                            mov    eax,DWORD PTR [edx+0x14]
  409645  8bce                              mov    ecx,esi
  409647  ffd0                              call   eax
  409649  8b10                              mov    edx,DWORD PTR [eax]
  40964b  8bc8                              mov    ecx,eax
  40964d  8b4230                            mov    eax,DWORD PTR [edx+0x30]
  409650  57                                push   edi
  409651  ffd0                              call   eax
  409653  8ad8                              mov    bl,al
  409655  84db                              test   bl,bl
  409657  7535                              jne    0x40968e
  409659  8b16                              mov    edx,DWORD PTR [esi]
  40965b  8b421c                            mov    eax,DWORD PTR [edx+0x1c]
  40965e  57                                push   edi
  40965f  8bce                              mov    ecx,esi
  409661  ffd0                              call   eax
  409663  50                                push   eax
  409664  57                                push   edi
  409665  689827bf00                        push   0xbf2798
  40966a  8d95fcfdffff                      lea    edx,[ebp-0x204]
  409670  e83b180000                        call   0x40aeb0
  409675  83c40c                            add    esp,0xc
  409678  6a00                              push   0x0
  40967a  68c01fbf00                        push   0xbf1fc0
  40967f  8d8dfcfdffff                      lea    ecx,[ebp-0x204]
  409685  51                                push   ecx
  409686  6a00                              push   0x0
  409688  ff158025bd00                      call   DWORD PTR ds:0xbd2580
  40968e  8b4dfc                            mov    ecx,DWORD PTR [ebp-0x4]
  409691  5f                                pop    edi
  409692  5e                                pop    esi
  409693  8ac3                              mov    al,bl
  409695  33cd                              xor    ecx,ebp
  409697  5b                                pop    ebx
  409698  e864794800                        call   0x891001
  40969d  8be5                              mov    esp,ebp
  40969f  5d                                pop    ebp
  4096a0  c20400                            ret    0x4

; U28 | active map erase；descriptor registry hit 保留 window | full-function
; VA 0x44e3f0..0x44e482 raw 0x4d7f0 bytes 146 SHA256 d0a6aa3a0643d4bd4422feba6ba977e6111d09b3b20012a610c7e84724b9e9d5
  44e3f0  55                                push   ebp
  44e3f1  8bec                              mov    ebp,esp
  44e3f3  83ec08                            sub    esp,0x8
  44e3f6  53                                push   ebx
  44e3f7  57                                push   edi
  44e3f8  8bf9                              mov    edi,ecx
  44e3fa  8d4508                            lea    eax,[ebp+0x8]
  44e3fd  8d4f04                            lea    ecx,[edi+0x4]
  44e400  50                                push   eax
  44e401  8d45fc                            lea    eax,[ebp-0x4]
  44e404  894df8                            mov    DWORD PTR [ebp-0x8],ecx
  44e407  e8f40a3e00                        call   0x82ef00
  44e40c  8b5dfc                            mov    ebx,DWORD PTR [ebp-0x4]
  44e40f  3b5f08                            cmp    ebx,DWORD PTR [edi+0x8]
  44e412  7464                              je     0x44e478
  44e414  56                                push   esi
  44e415  8b7310                            mov    esi,DWORD PTR [ebx+0x10]
  44e418  8b4e28                            mov    ecx,DWORD PTR [esi+0x28]
  44e41b  c1e915                            shr    ecx,0x15
  44e41e  f6c101                            test   cl,0x1
  44e421  7407                              je     0x44e42a
  44e423  8bce                              mov    ecx,esi
  44e425  e856722f00                        call   0x745680
  44e42a  8b5604                            mov    edx,DWORD PTR [esi+0x4]
  44e42d  8d4508                            lea    eax,[ebp+0x8]
  44e430  50                                push   eax
  44e431  8d4f14                            lea    ecx,[edi+0x14]
  44e434  8d45fc                            lea    eax,[ebp-0x4]
  44e437  895508                            mov    DWORD PTR [ebp+0x8],edx
  44e43a  e8c10a3e00                        call   0x82ef00
  44e43f  8b08                              mov    ecx,DWORD PTR [eax]
  44e441  3b4f18                            cmp    ecx,DWORD PTR [edi+0x18]
  44e444  7519                              jne    0x44e45f
  44e446  8bce                              mov    ecx,esi
  44e448  e833872f00                        call   0x746b80
  44e44d  8bce                              mov    ecx,esi
  44e44f  e8bc872f00                        call   0x746c10
  44e454  8b16                              mov    edx,DWORD PTR [esi]
  44e456  8b421c                            mov    eax,DWORD PTR [edx+0x1c]
  44e459  6a01                              push   0x1
  44e45b  8bce                              mov    ecx,esi
  44e45d  ffd0                              call   eax
  44e45f  8b55f8                            mov    edx,DWORD PTR [ebp-0x8]
  44e462  53                                push   ebx
  44e463  8d4d08                            lea    ecx,[ebp+0x8]
  44e466  51                                push   ecx
  44e467  52                                push   edx
  44e468  e823843600                        call   0x7b6890
  44e46d  5e                                pop    esi
  44e46e  5f                                pop    edi
  44e46f  b001                              mov    al,0x1
  44e471  5b                                pop    ebx
  44e472  8be5                              mov    esp,ebp
  44e474  5d                                pop    ebp
  44e475  c20400                            ret    0x4
  44e478  5f                                pop    edi
  44e479  32c0                              xor    al,al
  44e47b  5b                                pop    ebx
  44e47c  8be5                              mov    esp,ebp
  44e47e  5d                                pop    ebp
  44e47f  c20400                            ret    0x4

; U29 | parent list detach，window+60=0，解除 UI manager 關聯 | full-function
; VA 0x746700..0x74677e raw 0x345b00 bytes 126 SHA256 fb819a6e55b4c8c2c6d139e20749ec6d85f496ae5e3c5652890d805d1bf89c6c
  746700  55                                push   ebp
  746701  8bec                              mov    ebp,esp
  746703  56                                push   esi
  746704  57                                push   edi
  746705  8bf9                              mov    edi,ecx
  746707  8b4764                            mov    eax,DWORD PTR [edi+0x64]
  74670a  8b30                              mov    esi,DWORD PTR [eax]
  74670c  3bf0                              cmp    esi,eax
  74670e  7468                              je     0x746778
  746710  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
  746713  394e08                            cmp    DWORD PTR [esi+0x8],ecx
  746716  740c                              je     0x746724
  746718  8b36                              mov    esi,DWORD PTR [esi]
  74671a  3bf0                              cmp    esi,eax
  74671c  75f5                              jne    0x746713
  74671e  5f                                pop    edi
  74671f  5e                                pop    esi
  746720  5d                                pop    ebp
  746721  c20400                            ret    0x4
  746724  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  746727  e8e4040000                        call   0x746c10
  74672c  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  74672f  e84c040000                        call   0x746b80
  746734  8b4608                            mov    eax,DWORD PTR [esi+0x8]
  746737  c7406000000000                    mov    DWORD PTR [eax+0x60],0x0
  74673e  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  746741  6a00                              push   0x0
  746743  e8a81f0000                        call   0x7486f0
  746748  8b4f24                            mov    ecx,DWORD PTR [edi+0x24]
  74674b  85c9                              test   ecx,ecx
  74674d  7409                              je     0x746758
  74674f  8b5608                            mov    edx,DWORD PTR [esi+0x8]
  746752  52                                push   edx
  746753  e8389a0000                        call   0x750190
  746758  3b7764                            cmp    esi,DWORD PTR [edi+0x64]
  74675b  741b                              je     0x746778
  74675d  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  746760  8b0e                              mov    ecx,DWORD PTR [esi]
  746762  8908                              mov    DWORD PTR [eax],ecx
  746764  8b16                              mov    edx,DWORD PTR [esi]
  746766  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  746769  56                                push   esi
  74676a  894204                            mov    DWORD PTR [edx+0x4],eax
  74676d  e89aaa1400                        call   0x89120c
  746772  83c404                            add    esp,0x4
  746775  ff4f68                            dec    DWORD PTR [edi+0x68]
  746778  5f                                pop    edi
  746779  5e                                pop    esi
  74677a  5d                                pop    ebp
  74677b  c20400                            ret    0x4

; U30 | uninitialize tree：+10c 回呼與 bit21 清除 | full-function
; VA 0x745680..0x7456ef raw 0x344a80 bytes 111 SHA256 fd503287fb335b5579f9c74a1e33c7576ddd3a94b079ac34ad43197442053d71
  745680  56                                push   esi
  745681  8bf1                              mov    esi,ecx
  745683  8b06                              mov    eax,DWORD PTR [esi]
  745685  8b900c010000                      mov    edx,DWORD PTR [eax+0x10c]
  74568b  81762800002000                    xor    DWORD PTR [esi+0x28],0x200000
  745692  57                                push   edi
  745693  ffd2                              call   edx
  745695  8b7e50                            mov    edi,DWORD PTR [esi+0x50]
  745698  8b37                              mov    esi,DWORD PTR [edi]
  74569a  3bf7                              cmp    esi,edi
  74569c  744e                              je     0x7456ec
  74569e  8bff                              mov    edi,edi
  7456a0  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
  7456a3  e8d8ffffff                        call   0x745680
  7456a8  807e1500                          cmp    BYTE PTR [esi+0x15],0x0
  7456ac  753a                              jne    0x7456e8
  7456ae  8b4608                            mov    eax,DWORD PTR [esi+0x8]
  7456b1  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7456b5  7516                              jne    0x7456cd
  7456b7  8bf0                              mov    esi,eax
  7456b9  8b06                              mov    eax,DWORD PTR [esi]
  7456bb  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7456bf  7527                              jne    0x7456e8
  7456c1  8bf0                              mov    esi,eax
  7456c3  8b06                              mov    eax,DWORD PTR [esi]
  7456c5  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7456c9  74f6                              je     0x7456c1
  7456cb  eb1b                              jmp    0x7456e8
  7456cd  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  7456d0  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7456d4  7510                              jne    0x7456e6
  7456d6  3b7008                            cmp    esi,DWORD PTR [eax+0x8]
  7456d9  750b                              jne    0x7456e6
  7456db  8bf0                              mov    esi,eax
  7456dd  8b4004                            mov    eax,DWORD PTR [eax+0x4]
  7456e0  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7456e4  74f0                              je     0x7456d6
  7456e6  8bf0                              mov    esi,eax
  7456e8  3bf7                              cmp    esi,edi
  7456ea  75b4                              jne    0x7456a0
  7456ec  5f                                pop    edi
  7456ed  5e                                pop    esi
  7456ee  c3                                ret

; U31 | initialize tree：+108 回呼與 bit21 設定 | full-function
; VA 0x745600..0x745676 raw 0x344a00 bytes 118 SHA256 4b9ccfb3b787c2f7a65cc93c46249978996a1816164a13cd3c81da266f35ea12
  745600  53                                push   ebx
  745601  56                                push   esi
  745602  57                                push   edi
  745603  8bf9                              mov    edi,ecx
  745605  8b07                              mov    eax,DWORD PTR [edi]
  745607  8b9008010000                      mov    edx,DWORD PTR [eax+0x108]
  74560d  ffd2                              call   edx
  74560f  8b5f50                            mov    ebx,DWORD PTR [edi+0x50]
  745612  8b33                              mov    esi,DWORD PTR [ebx]
  745614  3bf3                              cmp    esi,ebx
  745616  7453                              je     0x74566b
  745618  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
  74561b  e8e0ffffff                        call   0x745600
  745620  807e1500                          cmp    BYTE PTR [esi+0x15],0x0
  745624  7541                              jne    0x745667
  745626  8b4608                            mov    eax,DWORD PTR [esi+0x8]
  745629  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  74562d  751d                              jne    0x74564c
  74562f  8bf0                              mov    esi,eax
  745631  8b06                              mov    eax,DWORD PTR [esi]
  745633  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  745637  752e                              jne    0x745667
  745639  8da42400000000                    lea    esp,[esp+0x0]
  745640  8bf0                              mov    esi,eax
  745642  8b06                              mov    eax,DWORD PTR [esi]
  745644  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  745648  74f6                              je     0x745640
  74564a  eb1b                              jmp    0x745667
  74564c  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  74564f  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  745653  7510                              jne    0x745665
  745655  3b7008                            cmp    esi,DWORD PTR [eax+0x8]
  745658  750b                              jne    0x745665
  74565a  8bf0                              mov    esi,eax
  74565c  8b4004                            mov    eax,DWORD PTR [eax+0x4]
  74565f  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  745663  74f0                              je     0x745655
  745665  8bf0                              mov    esi,eax
  745667  3bf3                              cmp    esi,ebx
  745669  75ad                              jne    0x745618
  74566b  814f2800002000                    or     DWORD PTR [edi+0x28],0x200000
  745672  5f                                pop    edi
  745673  5e                                pop    esi
  745674  5b                                pop    ebx
  745675  c3                                ret

; U32 | binder vector finalize→native initialization→page attachment | full-function
; VA 0x40b670..0x40b815 raw 0xaa70 bytes 421 SHA256 8d1168b0aae940184e8754d2a9301c067a5af9d5b347d309008415e893df77e9
  40b670  55                                push   ebp
  40b671  8bec                              mov    ebp,esp
  40b673  51                                push   ecx
  40b674  8b4608                            mov    eax,DWORD PTR [esi+0x8]
  40b677  2b4604                            sub    eax,DWORD PTR [esi+0x4]
  40b67a  53                                push   ebx
  40b67b  57                                push   edi
  40b67c  33ff                              xor    edi,edi
  40b67e  c1f802                            sar    eax,0x2
  40b681  897dfc                            mov    DWORD PTR [ebp-0x4],edi
  40b684  85c0                              test   eax,eax
  40b686  746a                              je     0x40b6f2
  40b688  eb06                              jmp    0x40b690
  40b68a  8d9b00000000                      lea    ebx,[ebx+0x0]
  40b690  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
  40b693  833cb900                          cmp    DWORD PTR [ecx+edi*4],0x0
  40b697  8d04b9                            lea    eax,[ecx+edi*4]
  40b69a  7445                              je     0x40b6e1
  40b69c  8b18                              mov    ebx,DWORD PTR [eax]
  40b69e  8b4328                            mov    eax,DWORD PTR [ebx+0x28]
  40b6a1  8bd0                              mov    edx,eax
  40b6a3  c1ea15                            shr    edx,0x15
  40b6a6  f6c201                            test   dl,0x1
  40b6a9  7536                              jne    0x40b6e1
  40b6ab  c1e816                            shr    eax,0x16
  40b6ae  a801                              test   al,0x1
  40b6b0  7519                              jne    0x40b6cb
  40b6b2  8b06                              mov    eax,DWORD PTR [esi]
  40b6b4  8b5010                            mov    edx,DWORD PTR [eax+0x10]
  40b6b7  8b3b                              mov    edi,DWORD PTR [ebx]
  40b6b9  8bce                              mov    ecx,esi
  40b6bb  ffd2                              call   edx
  40b6bd  50                                push   eax
  40b6be  8b87c0000000                      mov    eax,DWORD PTR [edi+0xc0]
  40b6c4  8bcb                              mov    ecx,ebx
  40b6c6  ffd0                              call   eax
  40b6c8  8b7dfc                            mov    edi,DWORD PTR [ebp-0x4]
  40b6cb  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
  40b6ce  8b0cb9                            mov    ecx,DWORD PTR [ecx+edi*4]
  40b6d1  e8ba9e3300                        call   0x745590
  40b6d6  8b5604                            mov    edx,DWORD PTR [esi+0x4]
  40b6d9  8b0cba                            mov    ecx,DWORD PTR [edx+edi*4]
  40b6dc  e81f9f3300                        call   0x745600
  40b6e1  8b4608                            mov    eax,DWORD PTR [esi+0x8]
  40b6e4  2b4604                            sub    eax,DWORD PTR [esi+0x4]
  40b6e7  47                                inc    edi
  40b6e8  c1f802                            sar    eax,0x2
  40b6eb  897dfc                            mov    DWORD PTR [ebp-0x4],edi
  40b6ee  3bf8                              cmp    edi,eax
  40b6f0  729e                              jb     0x40b690
  40b6f2  8b5d08                            mov    ebx,DWORD PTR [ebp+0x8]
  40b6f5  85db                              test   ebx,ebx
  40b6f7  0f8410010000                      je     0x40b80d
  40b6fd  8b13                              mov    edx,DWORD PTR [ebx]
  40b6ff  8b4204                            mov    eax,DWORD PTR [edx+0x4]
  40b702  8bcb                              mov    ecx,ebx
  40b704  ffd0                              call   eax
  40b706  33d2                              xor    edx,edx
  40b708  3dd8d60000                        cmp    eax,0xd6d8
  40b70d  0f8583000000                      jne    0x40b796
  40b713  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  40b716  2b4e04                            sub    ecx,DWORD PTR [esi+0x4]
  40b719  c1f902                            sar    ecx,0x2
  40b71c  85c9                              test   ecx,ecx
  40b71e  743c                              je     0x40b75c
  40b720  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  40b723  833c9000                          cmp    DWORD PTR [eax+edx*4],0x0
  40b727  8d0490                            lea    eax,[eax+edx*4]
  40b72a  7422                              je     0x40b74e
  40b72c  8b00                              mov    eax,DWORD PTR [eax]
  40b72e  83482810                          or     DWORD PTR [eax+0x28],0x10
  40b732  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
  40b735  f6c120                            test   cl,0x20
  40b738  7406                              je     0x40b740
  40b73a  83f120                            xor    ecx,0x20
  40b73d  894828                            mov    DWORD PTR [eax+0x28],ecx
  40b740  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
  40b743  f6c140                            test   cl,0x40
  40b746  7406                              je     0x40b74e
  40b748  83f140                            xor    ecx,0x40
  40b74b  894828                            mov    DWORD PTR [eax+0x28],ecx
  40b74e  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  40b751  2b4e04                            sub    ecx,DWORD PTR [esi+0x4]
  40b754  42                                inc    edx
  40b755  c1f902                            sar    ecx,0x2
  40b758  3bd1                              cmp    edx,ecx
  40b75a  72c4                              jb     0x40b720
  40b75c  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  40b75f  8b5608                            mov    edx,DWORD PTR [esi+0x8]
  40b762  2bd0                              sub    edx,eax
  40b764  c1fa02                            sar    edx,0x2
  40b767  33ff                              xor    edi,edi
  40b769  85d2                              test   edx,edx
  40b76b  0f849c000000                      je     0x40b80d
  40b771  8b13                              mov    edx,DWORD PTR [ebx]
  40b773  8b04b8                            mov    eax,DWORD PTR [eax+edi*4]
  40b776  8b5270                            mov    edx,DWORD PTR [edx+0x70]
  40b779  50                                push   eax
  40b77a  8bcb                              mov    ecx,ebx
  40b77c  ffd2                              call   edx
  40b77e  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  40b781  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  40b784  2bc8                              sub    ecx,eax
  40b786  47                                inc    edi
  40b787  c1f902                            sar    ecx,0x2
  40b78a  3bf9                              cmp    edi,ecx
  40b78c  72e3                              jb     0x40b771
  40b78e  5f                                pop    edi
  40b78f  5b                                pop    ebx
  40b790  8be5                              mov    esp,ebp
  40b792  5d                                pop    ebp
  40b793  c20400                            ret    0x4
  40b796  8b4608                            mov    eax,DWORD PTR [esi+0x8]
  40b799  2b4604                            sub    eax,DWORD PTR [esi+0x4]
  40b79c  c1f802                            sar    eax,0x2
  40b79f  85c0                              test   eax,eax
  40b7a1  743c                              je     0x40b7df
  40b7a3  8b4e04                            mov    ecx,DWORD PTR [esi+0x4]
  40b7a6  833c9100                          cmp    DWORD PTR [ecx+edx*4],0x0
  40b7aa  8d0491                            lea    eax,[ecx+edx*4]
  40b7ad  7422                              je     0x40b7d1
  40b7af  8b00                              mov    eax,DWORD PTR [eax]
  40b7b1  83482820                          or     DWORD PTR [eax+0x28],0x20
  40b7b5  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
  40b7b8  f6c110                            test   cl,0x10
  40b7bb  7406                              je     0x40b7c3
  40b7bd  83f110                            xor    ecx,0x10
  40b7c0  894828                            mov    DWORD PTR [eax+0x28],ecx
  40b7c3  8b4828                            mov    ecx,DWORD PTR [eax+0x28]
  40b7c6  f6c140                            test   cl,0x40
  40b7c9  7406                              je     0x40b7d1
  40b7cb  83f140                            xor    ecx,0x40
  40b7ce  894828                            mov    DWORD PTR [eax+0x28],ecx
  40b7d1  8b4608                            mov    eax,DWORD PTR [esi+0x8]
  40b7d4  2b4604                            sub    eax,DWORD PTR [esi+0x4]
  40b7d7  42                                inc    edx
  40b7d8  c1f802                            sar    eax,0x2
  40b7db  3bd0                              cmp    edx,eax
  40b7dd  72c4                              jb     0x40b7a3
  40b7df  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  40b7e2  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  40b7e5  2bc8                              sub    ecx,eax
  40b7e7  c1f902                            sar    ecx,0x2
  40b7ea  33ff                              xor    edi,edi
  40b7ec  85c9                              test   ecx,ecx
  40b7ee  741d                              je     0x40b80d
  40b7f0  8b13                              mov    edx,DWORD PTR [ebx]
  40b7f2  8b04b8                            mov    eax,DWORD PTR [eax+edi*4]
  40b7f5  8b5270                            mov    edx,DWORD PTR [edx+0x70]
  40b7f8  50                                push   eax
  40b7f9  8bcb                              mov    ecx,ebx
  40b7fb  ffd2                              call   edx
  40b7fd  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  40b800  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  40b803  2bc8                              sub    ecx,eax
  40b805  47                                inc    edi
  40b806  c1f902                            sar    ecx,0x2
  40b809  3bf9                              cmp    edi,ecx
  40b80b  72e3                              jb     0x40b7f0
  40b80d  5f                                pop    edi
  40b80e  5b                                pop    ebx
  40b80f  8be5                              mov    esp,ebp
  40b811  5d                                pop    ebp
  40b812  c20400                            ret    0x4

; U33 | active resource ID→window 註冊，與 descriptor registry 分開 | full-function
; VA 0x44e6c0..0x44e718 raw 0x4dac0 bytes 88 SHA256 626eda300f1cb85714100044fe8d4d8285d6fdbde0f4da762b244caaab2e0600
  44e6c0  55                                push   ebp
  44e6c1  8bec                              mov    ebp,esp
  44e6c3  83ec0c                            sub    esp,0xc
  44e6c6  53                                push   ebx
  44e6c7  8b5d0c                            mov    ebx,DWORD PTR [ebp+0xc]
  44e6ca  56                                push   esi
  44e6cb  57                                push   edi
  44e6cc  8bf8                              mov    edi,eax
  44e6ce  8d4508                            lea    eax,[ebp+0x8]
  44e6d1  8d7704                            lea    esi,[edi+0x4]
  44e6d4  50                                push   eax
  44e6d5  8d450c                            lea    eax,[ebp+0xc]
  44e6d8  8bce                              mov    ecx,esi
  44e6da  e821083e00                        call   0x82ef00
  44e6df  8b4d0c                            mov    ecx,DWORD PTR [ebp+0xc]
  44e6e2  3b4f08                            cmp    ecx,DWORD PTR [edi+0x8]
  44e6e5  7526                              jne    0x44e70d
  44e6e7  8b5508                            mov    edx,DWORD PTR [ebp+0x8]
  44e6ea  8d7df8                            lea    edi,[ebp-0x8]
  44e6ed  8955f8                            mov    DWORD PTR [ebp-0x8],edx
  44e6f0  895dfc                            mov    DWORD PTR [ebp-0x4],ebx
  44e6f3  e828081300                        call   0x57ef20
  44e6f8  50                                push   eax
  44e6f9  56                                push   esi
  44e6fa  8d75f8                            lea    esi,[ebp-0x8]
  44e6fd  e8fe0a3e00                        call   0x82f200
  44e702  8bc3                              mov    eax,ebx
  44e704  5f                                pop    edi
  44e705  5e                                pop    esi
  44e706  5b                                pop    ebx
  44e707  8be5                              mov    esp,ebp
  44e709  5d                                pop    ebp
  44e70a  c20800                            ret    0x8
  44e70d  5f                                pop    edi
  44e70e  5e                                pop    esi
  44e70f  33c0                              xor    eax,eax
  44e711  5b                                pop    ebx
  44e712  8be5                              mov    esp,ebp
  44e714  5d                                pop    ebp
  44e715  c20800                            ret    0x8

; U34 | binder vector append selected pointer | full-function
; VA 0x443d10..0x443d62 raw 0x43110 bytes 82 SHA256 160f52414f2adbb0edf8ffc5d1eeeec178a08f40e58c850a1951f9e6348e7448
  443d10  56                                push   esi
  443d11  8bf0                              mov    esi,eax
  443d13  8b4704                            mov    eax,DWORD PTR [edi+0x4]
  443d16  3bf0                              cmp    esi,eax
  443d18  732b                              jae    0x443d45
  443d1a  8b0f                              mov    ecx,DWORD PTR [edi]
  443d1c  3bce                              cmp    ecx,esi
  443d1e  7725                              ja     0x443d45
  443d20  2bf1                              sub    esi,ecx
  443d22  c1fe02                            sar    esi,0x2
  443d25  3b4708                            cmp    eax,DWORD PTR [edi+0x8]
  443d28  7507                              jne    0x443d31
  443d2a  8bc7                              mov    eax,edi
  443d2c  e87fad0900                        call   0x4deab0
  443d31  8b4704                            mov    eax,DWORD PTR [edi+0x4]
  443d34  85c0                              test   eax,eax
  443d36  7424                              je     0x443d5c
  443d38  8b0f                              mov    ecx,DWORD PTR [edi]
  443d3a  8b14b1                            mov    edx,DWORD PTR [ecx+esi*4]
  443d3d  8910                              mov    DWORD PTR [eax],edx
  443d3f  83470404                          add    DWORD PTR [edi+0x4],0x4
  443d43  5e                                pop    esi
  443d44  c3                                ret
  443d45  3b4708                            cmp    eax,DWORD PTR [edi+0x8]
  443d48  7507                              jne    0x443d51
  443d4a  8bc7                              mov    eax,edi
  443d4c  e85fad0900                        call   0x4deab0
  443d51  8b4704                            mov    eax,DWORD PTR [edi+0x4]
  443d54  85c0                              test   eax,eax
  443d56  7404                              je     0x443d5c
  443d58  8b0e                              mov    ecx,DWORD PTR [esi]
  443d5a  8908                              mov    DWORD PTR [eax],ecx
  443d5c  83470404                          add    DWORD PTR [edi+0x4],0x4
  443d60  5e                                pop    esi
  443d61  c3                                ret

; U35 | talk/static/picture 指定 lifecycle hook 的 RET | full-function
; VA 0x5f5d10..0x5f5d11 raw 0x1f5110 bytes 1 SHA256 ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e
  5f5d10  c3                                ret

; U36 | FXUIPicture XML reader：base reader 後接 control-specific reader | full-function
; VA 0x744450..0x74447c raw 0x343850 bytes 44 SHA256 81b8081aee1cb4ee4b4b710b457194019c65b62a6aa4bb93e568b0b8fb33142c
  744450  55                                push   ebp
  744451  8bec                              mov    ebp,esp
  744453  56                                push   esi
  744454  57                                push   edi
  744455  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
  744458  57                                push   edi
  744459  8bf1                              mov    esi,ecx
  74445b  e8e0470000                        call   0x748c40
  744460  84c0                              test   al,al
  744462  7410                              je     0x744474
  744464  57                                push   edi
  744465  8bce                              mov    ecx,esi
  744467  e8a4020000                        call   0x744710
  74446c  5f                                pop    edi
  74446d  b001                              mov    al,0x1
  74446f  5e                                pop    esi
  744470  5d                                pop    ebp
  744471  c20400                            ret    0x4
  744474  5f                                pop    edi
  744475  32c0                              xor    al,al
  744477  5e                                pop    esi
  744478  5d                                pop    ebp
  744479  c20400                            ret    0x4

; U37 | FXUIStatic XML reader adapter | full-function
; VA 0x75eb80..0x75eb95 raw 0x35df80 bytes 21 SHA256 867c409a0e5afe779a24dcb3b9ef8363513189c7bf3f923cae7bcd1ce8437303
  75eb80  55                                push   ebp
  75eb81  8bec                              mov    ebp,esp
  75eb83  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  75eb86  50                                push   eax
  75eb87  e89460ffff                        call   0x754c20
  75eb8c  84c0                              test   al,al
  75eb8e  0f95c0                            setne  al
  75eb91  5d                                pop    ebp
  75eb92  c20400                            ret    0x4

; U38 | FXUIStatic 文字樣式／屬性 reader；不是完整 font 子圖 | full-function
; VA 0x754c20..0x754cb9 raw 0x354020 bytes 153 SHA256 de5ff1b3cfb20538af1de75706e2ceb677a3a71a18eef1c23417cc3ebed76fad
  754c20  55                                push   ebp
  754c21  8bec                              mov    ebp,esp
  754c23  56                                push   esi
  754c24  57                                push   edi
  754c25  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
  754c28  57                                push   edi
  754c29  8bf1                              mov    esi,ecx
  754c2b  e820f7ffff                        call   0x754350
  754c30  84c0                              test   al,al
  754c32  747d                              je     0x754cb1
  754c34  8d86cc000000                      lea    eax,[esi+0xcc]
  754c3a  50                                push   eax
  754c3b  bad07ec400                        mov    edx,0xc47ed0
  754c40  8bcf                              mov    ecx,edi
  754c42  e8d9590000                        call   0x75a620
  754c47  57                                push   edi
  754c48  8d8e28010000                      lea    ecx,[esi+0x128]
  754c4e  e8bd150200                        call   0x776210
  754c53  68000000ff                        push   0xff000000
  754c58  baf87ec400                        mov    edx,0xc47ef8
  754c5d  8bcf                              mov    ecx,edi
  754c5f  e84c030100                        call   0x764fb0
  754c64  6a05                              push   0x5
  754c66  ba0c7fc400                        mov    edx,0xc47f0c
  754c6b  8bcf                              mov    ecx,edi
  754c6d  898654010000                      mov    DWORD PTR [esi+0x154],eax
  754c73  e838030100                        call   0x764fb0
  754c78  6a02                              push   0x2
  754c7a  ba247fc400                        mov    edx,0xc47f24
  754c7f  8bcf                              mov    ecx,edi
  754c81  898620010000                      mov    DWORD PTR [esi+0x120],eax
  754c87  e824030100                        call   0x764fb0
  754c8c  6a01                              push   0x1
  754c8e  ba3c7fc400                        mov    edx,0xc47f3c
  754c93  8bcf                              mov    ecx,edi
  754c95  898624010000                      mov    DWORD PTR [esi+0x124],eax
  754c9b  e880040100                        call   0x765120
  754ca0  83c410                            add    esp,0x10
  754ca3  8886c8000000                      mov    BYTE PTR [esi+0xc8],al
  754ca9  5f                                pop    edi
  754caa  b001                              mov    al,0x1
  754cac  5e                                pop    esi
  754cad  5d                                pop    ebp
  754cae  c20400                            ret    0x4
  754cb1  5f                                pop    edi
  754cb2  32c0                              xor    al,al
  754cb4  5e                                pop    esi
  754cb5  5d                                pop    ebp
  754cb6  c20400                            ret    0x4

; U39 | 普通／Outter dock reader，只有 numeric property | full-function
; VA 0x76e160..0x76e17d raw 0x36d560 bytes 29 SHA256 c967e5911f68c41a9bdda8f1a888455cfc4aec0838cf3d06d0f0c72f60082489
  76e160  55                                push   ebp
  76e161  8bec                              mov    ebp,esp
  76e163  83c108                            add    ecx,0x8
  76e166  51                                push   ecx
  76e167  8b4d08                            mov    ecx,DWORD PTR [ebp+0x8]
  76e16a  ba30d4c400                        mov    edx,0xc4d430
  76e16f  e8ecb6cbff                        call   0x429860
  76e174  83c404                            add    esp,0x4
  76e177  b001                              mov    al,0x1
  76e179  5d                                pop    ebp
  76e17a  c20400                            ret    0x4

; U40 | Lock dock reader，numeric property 加固定矩形 reader | full-function
; VA 0x76e4f0..0x76e523 raw 0x36d8f0 bytes 51 SHA256 3753bb9714a22cf1eb8553e3b50761c46e98b2ee566ac7b0e34e50428cea9d32
  76e4f0  55                                push   ebp
  76e4f1  8bec                              mov    ebp,esp
  76e4f3  56                                push   esi
  76e4f4  8bf1                              mov    esi,ecx
  76e4f6  57                                push   edi
  76e4f7  8b7d08                            mov    edi,DWORD PTR [ebp+0x8]
  76e4fa  8d4608                            lea    eax,[esi+0x8]
  76e4fd  50                                push   eax
  76e4fe  ba30d4c400                        mov    edx,0xc4d430
  76e503  8bcf                              mov    ecx,edi
  76e505  e856b3cbff                        call   0x429860
  76e50a  83c404                            add    esp,0x4
  76e50d  57                                push   edi
  76e50e  8d7e0c                            lea    edi,[esi+0xc]
  76e511  ba44d4c400                        mov    edx,0xc4d444
  76e516  e8f577feff                        call   0x755d10
  76e51b  5f                                pop    edi
  76e51c  b001                              mov    al,0x1
  76e51e  5e                                pop    esi
  76e51f  5d                                pop    ebp
  76e520  c20400                            ret    0x4

; U41 | native view-state cleanup 與子樹遞迴 | full-function
; VA 0x746b80..0x746bcc raw 0x345f80 bytes 76 SHA256 a849ce488e836d30e7ae6e0c393a4ea2b2d2c3185bc317a6cdb826fc58d7c8e6
  746b80  57                                push   edi
  746b81  8bf9                              mov    edi,ecx
  746b83  8b4728                            mov    eax,DWORD PTR [edi+0x28]
  746b86  c1e80f                            shr    eax,0xf
  746b89  a801                              test   al,0x1
  746b8b  743b                              je     0x746bc8
  746b8d  8b17                              mov    edx,DWORD PTR [edi]
  746b8f  8b8220010000                      mov    eax,DWORD PTR [edx+0x120]
  746b95  53                                push   ebx
  746b96  56                                push   esi
  746b97  ffd0                              call   eax
  746b99  8b5f64                            mov    ebx,DWORD PTR [edi+0x64]
  746b9c  8b33                              mov    esi,DWORD PTR [ebx]
  746b9e  3bf3                              cmp    esi,ebx
  746ba0  740e                              je     0x746bb0
  746ba2  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  746ba5  e8d6ffffff                        call   0x746b80
  746baa  8b36                              mov    esi,DWORD PTR [esi]
  746bac  3bf3                              cmp    esi,ebx
  746bae  75f2                              jne    0x746ba2
  746bb0  8b4728                            mov    eax,DWORD PTR [edi+0x28]
  746bb3  5e                                pop    esi
  746bb4  5b                                pop    ebx
  746bb5  a900800000                        test   eax,0x8000
  746bba  7408                              je     0x746bc4
  746bbc  3500800000                        xor    eax,0x8000
  746bc1  894728                            mov    DWORD PTR [edi+0x28],eax
  746bc4  b001                              mov    al,0x1
  746bc6  5f                                pop    edi
  746bc7  c3                                ret
  746bc8  32c0                              xor    al,al
  746bca  5f                                pop    edi
  746bcb  c3                                ret

; U42 | native UI-state cleanup 與子樹遞迴 | full-function
; VA 0x746c10..0x746c5a raw 0x346010 bytes 74 SHA256 937a6a53687dbce729622e2b3f103960dfde2dfb077ac08cb88e0dd677354252
  746c10  57                                push   edi
  746c11  8bf9                              mov    edi,ecx
  746c13  f6472a01                          test   BYTE PTR [edi+0x2a],0x1
  746c17  743d                              je     0x746c56
  746c19  8b07                              mov    eax,DWORD PTR [edi]
  746c1b  8b901c010000                      mov    edx,DWORD PTR [eax+0x11c]
  746c21  53                                push   ebx
  746c22  56                                push   esi
  746c23  ffd2                              call   edx
  746c25  8b5f64                            mov    ebx,DWORD PTR [edi+0x64]
  746c28  8b33                              mov    esi,DWORD PTR [ebx]
  746c2a  3bf3                              cmp    esi,ebx
  746c2c  7410                              je     0x746c3e
  746c2e  8bff                              mov    edi,edi
  746c30  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  746c33  e8d8ffffff                        call   0x746c10
  746c38  8b36                              mov    esi,DWORD PTR [esi]
  746c3a  3bf3                              cmp    esi,ebx
  746c3c  75f2                              jne    0x746c30
  746c3e  8b4728                            mov    eax,DWORD PTR [edi+0x28]
  746c41  5e                                pop    esi
  746c42  5b                                pop    ebx
  746c43  a900000100                        test   eax,0x10000
  746c48  7408                              je     0x746c52
  746c4a  3500000100                        xor    eax,0x10000
  746c4f  894728                            mov    DWORD PTR [edi+0x28],eax
  746c52  b001                              mov    al,0x1
  746c54  5f                                pop    edi
  746c55  c3                                ret
  746c56  32c0                              xor    al,al
  746c58  5f                                pop    edi
  746c59  c3                                ret

; U43 | recursive UI manager pointer propagation | full-function
; VA 0x7486f0..0x748739 raw 0x347af0 bytes 73 SHA256 7b755782104bf495054c2394e66a808161b1379cd13f9cb892a8e3e3e9e88467
  7486f0  55                                push   ebp
  7486f1  8bec                              mov    ebp,esp
  7486f3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  7486f6  53                                push   ebx
  7486f7  56                                push   esi
  7486f8  57                                push   edi
  7486f9  8bf9                              mov    edi,ecx
  7486fb  8b4f3c                            mov    ecx,DWORD PTR [edi+0x3c]
  7486fe  894724                            mov    DWORD PTR [edi+0x24],eax
  748701  85c9                              test   ecx,ecx
  748703  740f                              je     0x748714
  748705  f7472800000400                    test   DWORD PTR [edi+0x28],0x40000
  74870c  7506                              jne    0x748714
  74870e  50                                push   eax
  74870f  e8dcffffff                        call   0x7486f0
  748714  8b5f64                            mov    ebx,DWORD PTR [edi+0x64]
  748717  8b33                              mov    esi,DWORD PTR [ebx]
  748719  3bf3                              cmp    esi,ebx
  74871b  7415                              je     0x748732
  74871d  8d4900                            lea    ecx,[ecx+0x0]
  748720  8b4724                            mov    eax,DWORD PTR [edi+0x24]
  748723  8b4e08                            mov    ecx,DWORD PTR [esi+0x8]
  748726  50                                push   eax
  748727  e8c4ffffff                        call   0x7486f0
  74872c  8b36                              mov    esi,DWORD PTR [esi]
  74872e  3bf3                              cmp    esi,ebx
  748730  75ee                              jne    0x748720
  748732  5f                                pop    edi
  748733  5e                                pop    esi
  748734  5b                                pop    ebx
  748735  5d                                pop    ebp
  748736  c20400                            ret    0x4

; U44 | dock factory forwarder | full-function
; VA 0x746fd0..0x746fdf raw 0x3463d0 bytes 15 SHA256 23973d7777599cb6f6b80bb08c11f6aacea7f55ac355af73d7e5ecb54480d79f
  746fd0  55                                push   ebp
  746fd1  8bec                              mov    ebp,esp
  746fd3  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  746fd6  e8e5700200                        call   0x76e0c0
  746fdb  5d                                pop    ebp
  746fdc  c20400                            ret    0x4

; U45 | native view initialization v+104 及子樹遞迴 | full-function
; VA 0x745590..0x7455f9 raw 0x344990 bytes 105 SHA256 be87276c0ebf1639b58bc253d837d6f456490a911b75e68f05e38887b5c122c9
  745590  56                                push   esi
  745591  8bf1                              mov    esi,ecx
  745593  8b06                              mov    eax,DWORD PTR [esi]
  745595  8b9004010000                      mov    edx,DWORD PTR [eax+0x104]
  74559b  57                                push   edi
  74559c  ffd2                              call   edx
  74559e  8b7e50                            mov    edi,DWORD PTR [esi+0x50]
  7455a1  8b37                              mov    esi,DWORD PTR [edi]
  7455a3  3bf7                              cmp    esi,edi
  7455a5  744f                              je     0x7455f6
  7455a7  8b4e10                            mov    ecx,DWORD PTR [esi+0x10]
  7455aa  e8e1ffffff                        call   0x745590
  7455af  807e1500                          cmp    BYTE PTR [esi+0x15],0x0
  7455b3  753d                              jne    0x7455f2
  7455b5  8b4608                            mov    eax,DWORD PTR [esi+0x8]
  7455b8  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7455bc  7516                              jne    0x7455d4
  7455be  8bf0                              mov    esi,eax
  7455c0  8b06                              mov    eax,DWORD PTR [esi]
  7455c2  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7455c6  752a                              jne    0x7455f2
  7455c8  8bf0                              mov    esi,eax
  7455ca  8b06                              mov    eax,DWORD PTR [esi]
  7455cc  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7455d0  74f6                              je     0x7455c8
  7455d2  eb1e                              jmp    0x7455f2
  7455d4  8b4604                            mov    eax,DWORD PTR [esi+0x4]
  7455d7  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7455db  7513                              jne    0x7455f0
  7455dd  8d4900                            lea    ecx,[ecx+0x0]
  7455e0  3b7008                            cmp    esi,DWORD PTR [eax+0x8]
  7455e3  750b                              jne    0x7455f0
  7455e5  8bf0                              mov    esi,eax
  7455e7  8b4004                            mov    eax,DWORD PTR [eax+0x4]
  7455ea  80781500                          cmp    BYTE PTR [eax+0x15],0x0
  7455ee  74f0                              je     0x7455e0
  7455f0  8bf0                              mov    esi,eax
  7455f2  3bf7                              cmp    esi,edi
  7455f4  75b1                              jne    0x7455a7
  7455f6  5f                                pop    edi
  7455f7  5e                                pop    esi
  7455f8  c3                                ret

; U07 | resource 212 靜態字串初始化；只保存該 ordinal 的 fragment | bounded-fragment
; VA 0xad2991..0xad29a4 raw 0x6d1d91 bytes 19 SHA256 3bead2722878c5dd672fd02f8116560580ff28501fd9db337a18f4578104addd
  ad2991  68c8f0be00                        push   0xbef0c8
  ad2996  b9e877e500                        mov    ecx,0xe577e8
  ad299b  c645fcd3                          mov    BYTE PTR [ebp-0x4],0xd3
  ad299f  e8acf892ff                        call   0x402250

; U21 | CMissionFieldPage+10c→common cleanup | entry-prefix-through-selected-call
; VA 0x5ad050..0x5ad07b raw 0x1ac450 bytes 43 SHA256 58d4cccd26334c499bf1ec78a3862b8a927379487f1499647d3edc38b1f74533
  5ad050  55                                push   ebp
  5ad051  8bec                              mov    ebp,esp
  5ad053  6aff                              push   0xffffffff
  5ad055  68a02c9200                        push   0x922ca0
  5ad05a  64a100000000                      mov    eax,fs:0x0
  5ad060  50                                push   eax
  5ad061  83ec14                            sub    esp,0x14
  5ad064  56                                push   esi
  5ad065  a1201fd600                        mov    eax,ds:0xd61f20
  5ad06a  33c5                              xor    eax,ebp
  5ad06c  50                                push   eax
  5ad06d  8d45f4                            lea    eax,[ebp-0xc]
  5ad070  64a300000000                      mov    fs:0x0,eax
  5ad076  e885f4ffff                        call   0x5ac500

; U22 | CScenarioFieldPage+10c→common cleanup | entry-prefix-through-selected-call
; VA 0x5afdc0..0x5afdeb raw 0x1af1c0 bytes 43 SHA256 00794263a587bf780eeb542f375fd198185b93ab52d4de31e44b52fcdc5d40eb
  5afdc0  55                                push   ebp
  5afdc1  8bec                              mov    ebp,esp
  5afdc3  6aff                              push   0xffffffff
  5afdc5  68a02c9200                        push   0x922ca0
  5afdca  64a100000000                      mov    eax,fs:0x0
  5afdd0  50                                push   eax
  5afdd1  83ec14                            sub    esp,0x14
  5afdd4  56                                push   esi
  5afdd5  a1201fd600                        mov    eax,ds:0xd61f20
  5afdda  33c5                              xor    eax,ebp
  5afddc  50                                push   eax
  5afddd  8d45f4                            lea    eax,[ebp-0xc]
  5afde0  64a300000000                      mov    fs:0x0,eax
  5afde6  e815c7ffff                        call   0x5ac500

; U23 | common field page cleanup→shared page cleanup | entry-prefix-through-selected-call
; VA 0x5ac500..0x5ac52b raw 0x1ab900 bytes 43 SHA256 210c149da99dfdc4f53e2453a16882b143383ae6a3197dfcbbfe964d4362c82e
  5ac500  55                                push   ebp
  5ac501  8bec                              mov    ebp,esp
  5ac503  6aff                              push   0xffffffff
  5ac505  68a02c9200                        push   0x922ca0
  5ac50a  64a100000000                      mov    eax,fs:0x0
  5ac510  50                                push   eax
  5ac511  83ec14                            sub    esp,0x14
  5ac514  56                                push   esi
  5ac515  a1201fd600                        mov    eax,ds:0xd61f20
  5ac51a  33c5                              xor    eax,ebp
  5ac51c  50                                push   eax
  5ac51d  8d45f4                            lea    eax,[ebp-0xc]
  5ac520  64a300000000                      mov    fs:0x0,eax
  5ac526  e865d0feff                        call   0x599590

; U24 | shared page cleanup→chatable-page cleanup | entry-prefix-through-selected-call
; VA 0x599590..0x5995bc raw 0x198990 bytes 44 SHA256 e45076585df9b964255068e4262352b830d1456595e30a39ad0b9e3457664baa
  599590  55                                push   ebp
  599591  8bec                              mov    ebp,esp
  599593  6aff                              push   0xffffffff
  599595  6870249100                        push   0x912470
  59959a  64a100000000                      mov    eax,fs:0x0
  5995a0  50                                push   eax
  5995a1  83ec14                            sub    esp,0x14
  5995a4  53                                push   ebx
  5995a5  56                                push   esi
  5995a6  a1201fd600                        mov    eax,ds:0xd61f20
  5995ab  33c5                              xor    eax,ebp
  5995ad  50                                push   eax
  5995ae  8d45f4                            lea    eax,[ebp-0xc]
  5995b1  64a300000000                      mov    fs:0x0,eax
  5995b7  e804a70000                        call   0x5a3cc0

; U25 | chatable-page cleanup→base cleanup | entry-prefix-through-selected-call
; VA 0x5a3cc0..0x5a3cf1 raw 0x1a30c0 bytes 49 SHA256 9f03d56886138bb413db5b09171fa77ec7caed93a63c762bea646a129f7a26db
  5a3cc0  55                                push   ebp
  5a3cc1  8bec                              mov    ebp,esp
  5a3cc3  6aff                              push   0xffffffff
  5a3cc5  68660f9200                        push   0x920f66
  5a3cca  64a100000000                      mov    eax,fs:0x0
  5a3cd0  50                                push   eax
  5a3cd1  83ec34                            sub    esp,0x34
  5a3cd4  a1201fd600                        mov    eax,ds:0xd61f20
  5a3cd9  33c5                              xor    eax,ebp
  5a3cdb  8945f0                            mov    DWORD PTR [ebp-0x10],eax
  5a3cde  56                                push   esi
  5a3cdf  57                                push   edi
  5a3ce0  50                                push   eax
  5a3ce1  8d45f4                            lea    eax,[ebp-0xc]
  5a3ce4  64a300000000                      mov    fs:0x0,eax
  5a3cea  8bf1                              mov    esi,ecx
  5a3cec  e8bf23ffff                        call   0x5960b0

; F01 | factory common comparisons; selected 200/1400 paths only | selected-factory-branch
; VA 0x747000..0x74704d raw 0x346400 bytes 77 SHA256 9f987cd03f0f11bb100ba5f59476e54ad0c306a93b28bb94e523eddc1596ce9d
  747000  55                                push   ebp
  747001  8bec                              mov    ebp,esp
  747003  6aff                              push   0xffffffff
  747005  68c8f19100                        push   0x91f1c8
  74700a  64a100000000                      mov    eax,fs:0x0
  747010  50                                push   eax
  747011  56                                push   esi
  747012  a1201fd600                        mov    eax,ds:0xd61f20
  747017  33c5                              xor    eax,ebp
  747019  50                                push   eax
  74701a  8d45f4                            lea    eax,[ebp-0xc]
  74701d  64a300000000                      mov    fs:0x0,eax
  747023  8b4508                            mov    eax,DWORD PTR [ebp+0x8]
  747026  3d50c30000                        cmp    eax,0xc350
  74702b  0f8700080000                      ja     0x747831
  747031  0f84c4070000                      je     0x7477fb
  747037  3d58020000                        cmp    eax,0x258
  74703c  0f87cd030000                      ja     0x74740f
  747042  0f8491030000                      je     0x7473d9
  747048  83f864                            cmp    eax,0x64
  74704b  7777                              ja     0x7470c4

; F02 | type 200 index transform/table branch/allocation/final vptr | selected-factory-branch
; VA 0x7470c4..0x747133 raw 0x3464c4 bytes 111 SHA256 f660e5a85c47afb3d226383652908c46cf43bc607500b17e7798bc5dc84d05c9
  7470c4  3df4010000                        cmp    eax,0x1f4
  7470c9  0f87da100000                      ja     0x7481a9
  7470cf  0f84ce020000                      je     0x7473a3
  7470d5  0538ffffff                        add    eax,0xffffff38
  7470da  3dc8000000                        cmp    eax,0xc8
  7470df  0f87c4100000                      ja     0x7481a9
  7470e5  0fb680f4817400                    movzx  eax,BYTE PTR [eax+0x7481f4]
  7470ec  ff2485bc817400                    jmp    DWORD PTR [eax*4+0x7481bc]
  7470f3  6858010000                        push   0x158
  7470f8  e86baf1400                        call   0x892068
  7470fd  8bf0                              mov    esi,eax
  7470ff  83c404                            add    esp,0x4
  747102  897508                            mov    DWORD PTR [ebp+0x8],esi
  747105  c745fc03000000                    mov    DWORD PTR [ebp-0x4],0x3
  74710c  85f6                              test   esi,esi
  74710e  0f8495100000                      je     0x7481a9
  747114  8bce                              mov    ecx,esi
  747116  e865d70000                        call   0x754880
  74711b  c7066c9cc400                      mov    DWORD PTR [esi],0xc49c6c
  747121  8bc6                              mov    eax,esi
  747123  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  747126  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  74712d  59                                pop    ecx
  74712e  5e                                pop    esi
  74712f  8be5                              mov    esp,ebp
  747131  5d                                pop    ebp
  747132  c3                                ret

; F03 | type 1400 > 1200 branch | selected-factory-branch
; VA 0x74740f..0x74741a raw 0x34680f bytes 11 SHA256 e02114fbbfe3178318f77711667e650750de88685609e8b3bb295a8160434b13
  74740f  3db0040000                        cmp    eax,0x4b0
  747414  0f873c010000                      ja     0x747556

; F04 | type 1400 > 1300 branch | selected-factory-branch
; VA 0x747556..0x747561 raw 0x346956 bytes 11 SHA256 8cecf36401f80724a98c4ab31877de0e7b2fb0aba1deff970524c688e941cb64
  747556  3d14050000                        cmp    eax,0x514
  74755b  0f874b010000                      ja     0x7476ac

; F05 | type 1400 lookup table/allocation/FXUIPicture constructor | selected-factory-branch
; VA 0x7476ac..0x747700 raw 0x346aac bytes 84 SHA256 6047ed5b55bf5e9aed0b37fa3973d7bea3cc39caafe67c77be9965d5a95f53ed
  7476ac  05ebfaffff                        add    eax,0xfffffaeb
  7476b1  3dc9000000                        cmp    eax,0xc9
  7476b6  0f87ed0a0000                      ja     0x7481a9
  7476bc  0fb688e8827400                    movzx  ecx,BYTE PTR [eax+0x7482e8]
  7476c3  ff248dd0827400                    jmp    DWORD PTR [ecx*4+0x7482d0]
  7476ca  68a8000000                        push   0xa8
  7476cf  e894a91400                        call   0x892068
  7476d4  83c404                            add    esp,0x4
  7476d7  894508                            mov    DWORD PTR [ebp+0x8],eax
  7476da  c745fc02000000                    mov    DWORD PTR [ebp-0x4],0x2
  7476e1  85c0                              test   eax,eax
  7476e3  0f84c00a0000                      je     0x7481a9
  7476e9  8bc8                              mov    ecx,eax
  7476eb  e850d9ffff                        call   0x745040
  7476f0  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  7476f3  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  7476fa  59                                pop    ecx
  7476fb  5e                                pop    esi
  7476fc  8be5                              mov    esp,ebp
  7476fe  5d                                pop    ebp
  7476ff  c3                                ret

; F06 | factory common null return, before switch data | selected-factory-branch
; VA 0x7481a9..0x7481bc raw 0x3475a9 bytes 19 SHA256 a4cf3e873670253a56af66378c34b4fad6be0d1665842f62b3fc296a3845ccd6
  7481a9  33c0                              xor    eax,eax
  7481ab  8b4df4                            mov    ecx,DWORD PTR [ebp-0xc]
  7481ae  64890d00000000                    mov    DWORD PTR fs:0x0,ecx
  7481b5  59                                pop    ecx
  7481b6  5e                                pop    esi
  7481b7  8be5                              mov    esp,ebp
  7481b9  5d                                pop    ebp
  7481ba  c3                                ret
  7481bb  90                                nop

