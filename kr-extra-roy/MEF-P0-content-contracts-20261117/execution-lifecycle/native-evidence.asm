; N01_doll_release_before_actor_delete [NEW_OWNER_JOIN] 0x7a57c0..0x7a5ba1 exclusive
007A57C0  55                               push   ebp
007A57C1  8bec                             mov    ebp,esp
007A57C3  83e4f8                           and    esp,0xfffffff8
007A57C6  6aff                             push   0xffffffff
007A57C8  68a9919300                       push   0x9391a9
007A57CD  64a100000000                     mov    eax,fs:0x0
007A57D3  50                               push   eax
007A57D4  83ec18                           sub    esp,0x18
007A57D7  53                               push   ebx
007A57D8  56                               push   esi
007A57D9  57                               push   edi
007A57DA  a1201fd600                       mov    eax,ds:0xd61f20
007A57DF  33c4                             xor    eax,esp
007A57E1  50                               push   eax
007A57E2  8d442428                         lea    eax,[esp+0x28]
007A57E6  64a300000000                     mov    fs:0x0,eax
007A57EC  8bd9                             mov    ebx,ecx
007A57EE  8b8b18010000                     mov    ecx,DWORD PTR [ebx+0x118]
007A57F4  33ff                             xor    edi,edi
007A57F6  3bcf                             cmp    ecx,edi
007A57F8  740d                             je     0x7a5807
007A57FA  8b01                             mov    eax,DWORD PTR [ecx]
007A57FC  8b5008                           mov    edx,DWORD PTR [eax+0x8]
007A57FF  ffd2                             call   edx
007A5801  89bb18010000                     mov    DWORD PTR [ebx+0x118],edi
007A5807  be01000000                       mov    esi,0x1
007A580C  39731c                           cmp    DWORD PTR [ebx+0x1c],esi
007A580F  0f8568010000                     jne    0x7a597d
007A5815  6a38                             push   0x38
007A5817  e84cba0e00                       call   0x891268
007A581C  83c404                           add    esp,0x4
007A581F  89442420                         mov    DWORD PTR [esp+0x20],eax
007A5823  897c2430                         mov    DWORD PTR [esp+0x30],edi
007A5827  3bc7                             cmp    eax,edi
007A5829  7408                             je     0x7a5833
007A582B  50                               push   eax
007A582C  e84ffeffff                       call   0x7a5680
007A5831  eb02                             jmp    0x7a5835
007A5833  33c0                             xor    eax,eax
007A5835  50                               push   eax
007A5836  8d44241c                         lea    eax,[esp+0x1c]
007A583A  c7442434ffffffff                 mov    DWORD PTR [esp+0x34],0xffffffff
007A5842  50                               push   eax
007A5843  897c2420                         mov    DWORD PTR [esp+0x20],edi
007A5847  897c2424                         mov    DWORD PTR [esp+0x24],edi
007A584B  e8304f0000                       call   0x7aa780
007A5850  89742430                         mov    DWORD PTR [esp+0x30],esi
007A5854  8b742418                         mov    esi,DWORD PTR [esp+0x18]
007A5858  8b4b10                           mov    ecx,DWORD PTR [ebx+0x10]
007A585B  8d5324                           lea    edx,[ebx+0x24]
007A585E  52                               push   edx
007A585F  8d7e08                           lea    edi,[esi+0x8]
007A5862  890e                             mov    DWORD PTR [esi],ecx
007A5864  e8c7feffff                       call   0x7a5730
007A5869  8b4314                           mov    eax,DWORD PTR [ebx+0x14]
007A586C  894604                           mov    DWORD PTR [esi+0x4],eax
007A586F  8d4364                           lea    eax,[ebx+0x64]
007A5872  8d7e28                           lea    edi,[esi+0x28]
007A5875  3bf8                             cmp    edi,eax
007A5877  7421                             je     0x7a589a
007A5879  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A587C  8b08                             mov    ecx,DWORD PTR [eax]
007A587E  50                               push   eax
007A587F  51                               push   ecx
007A5880  8d742428                         lea    esi,[esp+0x28]
007A5884  8bc7                             mov    eax,edi
007A5886  e89518f3ff                       call   0x6d7120
007A588B  8d4364                           lea    eax,[ebx+0x64]
007A588E  50                               push   eax
007A588F  8bc7                             mov    eax,edi
007A5891  e8ba480000                       call   0x7aa150
007A5896  8b742418                         mov    esi,DWORD PTR [esp+0x18]
007A589A  8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
007A589E  83ec08                           sub    esp,0x8
007A58A1  8bfc                             mov    edi,esp
007A58A3  89642428                         mov    DWORD PTR [esp+0x28],esp
007A58A7  c70700000000                     mov    DWORD PTR [edi],0x0
007A58AD  c7470400000000                   mov    DWORD PTR [edi+0x4],0x0
007A58B4  85d2                             test   edx,edx
007A58B6  7416                             je     0x7a58ce
007A58B8  e89369cdff                       call   0x47c250
007A58BD  84c0                             test   al,al
007A58BF  740d                             je     0x7a58ce
007A58C1  8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
007A58C5  51                               push   ecx
007A58C6  56                               push   esi
007A58C7  8bf7                             mov    esi,edi
007A58C9  e8f2d8ffff                       call   0x7a31c0
007A58CE  c644243802                       mov    BYTE PTR [esp+0x38],0x2
007A58D3  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
007A58DA  7523                             jne    0x7a58ff
007A58DC  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
007A58E3  c644243803                       mov    BYTE PTR [esp+0x38],0x3
007A58E8  e85376ffff                       call   0x79cf40
007A58ED  6880dbbc00                       push   0xbcdb80
007A58F2  e823ca0e00                       call   0x89231a
007A58F7  83c404                           add    esp,0x4
007A58FA  c644243802                       mov    BYTE PTR [esp+0x38],0x2
007A58FF  b9900efc00                       mov    ecx,0xfc0e90
007A5904  c644243801                       mov    BYTE PTR [esp+0x38],0x1
007A5909  e8f284ffff                       call   0x79de00
007A590E  8d7b64                           lea    edi,[ebx+0x64]
007A5911  c7431400000000                   mov    DWORD PTR [ebx+0x14],0x0
007A5918  e85322dfff                       call   0x597b70
007A591D  8b8398000000                     mov    eax,DWORD PTR [ebx+0x98]
007A5923  33ff                             xor    edi,edi
007A5925  3bc7                             cmp    eax,edi
007A5927  7414                             je     0x7a593d
007A5929  8b08                             mov    ecx,DWORD PTR [eax]
007A592B  ff492c                           dec    DWORD PTR [ecx+0x2c]
007A592E  50                               push   eax
007A592F  e8d8b80e00                       call   0x89120c
007A5934  83c404                           add    esp,0x4
007A5937  89bb98000000                     mov    DWORD PTR [ebx+0x98],edi
007A593D  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
007A5945  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
007A5949  897b1c                           mov    DWORD PTR [ebx+0x1c],edi
007A594C  c6432001                         mov    BYTE PTR [ebx+0x20],0x1
007A5950  3bf7                             cmp    esi,edi
007A5952  7429                             je     0x7a597d
007A5954  8d5604                           lea    edx,[esi+0x4]
007A5957  83c8ff                           or     eax,0xffffffff
007A595A  f00fc102                         lock xadd DWORD PTR [edx],eax
007A595E  751d                             jne    0x7a597d
007A5960  8b16                             mov    edx,DWORD PTR [esi]
007A5962  8b02                             mov    eax,DWORD PTR [edx]
007A5964  8bce                             mov    ecx,esi
007A5966  ffd0                             call   eax
007A5968  8d4e08                           lea    ecx,[esi+0x8]
007A596B  83caff                           or     edx,0xffffffff
007A596E  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A5972  7509                             jne    0x7a597d
007A5974  8b06                             mov    eax,DWORD PTR [esi]
007A5976  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A5979  8bce                             mov    ecx,esi
007A597B  ffd2                             call   edx
007A597D  8b8348010000                     mov    eax,DWORD PTR [ebx+0x148]
007A5983  2b8344010000                     sub    eax,DWORD PTR [ebx+0x144]
007A5989  33f6                             xor    esi,esi
007A598B  c1f803                           sar    eax,0x3
007A598E  85c0                             test   eax,eax
007A5990  743f                             je     0x7a59d1
007A5992  8b8b44010000                     mov    ecx,DWORD PTR [ebx+0x144]
007A5998  8b7cf104                         mov    edi,DWORD PTR [ecx+esi*8+0x4]
007A599C  85ff                             test   edi,edi
007A599E  741d                             je     0x7a59bd
007A59A0  57                               push   edi
007A59A1  e8ea2e0300                       call   0x7d8890
007A59A6  57                               push   edi
007A59A7  e860b80e00                       call   0x89120c
007A59AC  8b9344010000                     mov    edx,DWORD PTR [ebx+0x144]
007A59B2  83c404                           add    esp,0x4
007A59B5  c744f20400000000                 mov    DWORD PTR [edx+esi*8+0x4],0x0
007A59BD  8b8348010000                     mov    eax,DWORD PTR [ebx+0x148]
007A59C3  2b8344010000                     sub    eax,DWORD PTR [ebx+0x144]
007A59C9  46                               inc    esi
007A59CA  c1f803                           sar    eax,0x3
007A59CD  3bf0                             cmp    esi,eax
007A59CF  72c1                             jb     0x7a5992
007A59D1  8b8b44010000                     mov    ecx,DWORD PTR [ebx+0x144]
007A59D7  8b9348010000                     mov    edx,DWORD PTR [ebx+0x148]
007A59DD  3bca                             cmp    ecx,edx
007A59DF  7420                             je     0x7a5a01
007A59E1  8bc2                             mov    eax,edx
007A59E3  3bd2                             cmp    edx,edx
007A59E5  7414                             je     0x7a59fb
007A59E7  8b30                             mov    esi,DWORD PTR [eax]
007A59E9  8931                             mov    DWORD PTR [ecx],esi
007A59EB  8b7004                           mov    esi,DWORD PTR [eax+0x4]
007A59EE  897104                           mov    DWORD PTR [ecx+0x4],esi
007A59F1  83c008                           add    eax,0x8
007A59F4  83c108                           add    ecx,0x8
007A59F7  3bc2                             cmp    eax,edx
007A59F9  75ec                             jne    0x7a59e7
007A59FB  898b48010000                     mov    DWORD PTR [ebx+0x148],ecx
007A5A01  8b8300010000                     mov    eax,DWORD PTR [ebx+0x100]
007A5A07  85c0                             test   eax,eax
007A5A09  7406                             je     0x7a5a11
007A5A0B  50                               push   eax
007A5A0C  e8df860100                       call   0x7be0f0
007A5A11  8b8304010000                     mov    eax,DWORD PTR [ebx+0x104]
007A5A17  8b38                             mov    edi,DWORD PTR [eax]
007A5A19  897c2414                         mov    DWORD PTR [esp+0x14],edi
007A5A1D  3bf8                             cmp    edi,eax
007A5A1F  0f842b010000                     je     0x7a5b50
007A5A25  eb04                             jmp    0x7a5a2b
007A5A27  8b7c2414                         mov    edi,DWORD PTR [esp+0x14]
007A5A2B  8b7708                           mov    esi,DWORD PTR [edi+0x8]
007A5A2E  85f6                             test   esi,esi
007A5A30  0f84cb000000                     je     0x7a5b01
007A5A36  8b06                             mov    eax,DWORD PTR [esi]
007A5A38  ff4860                           dec    DWORD PTR [eax+0x60]
007A5A3B  8b4674                           mov    eax,DWORD PTR [esi+0x74]
007A5A3E  85c0                             test   eax,eax
007A5A40  0f849c000000                     je     0x7a5ae2
007A5A46  837e7800                         cmp    DWORD PTR [esi+0x78],0x0
007A5A4A  0f8492000000                     je     0x7a5ae2
007A5A50  8b3e                             mov    edi,DWORD PTR [esi]
007A5A52  837f4401                         cmp    DWORD PTR [edi+0x44],0x1
007A5A56  89742418                         mov    DWORD PTR [esp+0x18],esi
007A5A5A  0f8c8d000000                     jl     0x7a5aed
007A5A60  8d4764                           lea    eax,[edi+0x64]
007A5A63  50                               push   eax
007A5A64  89442424                         mov    DWORD PTR [esp+0x24],eax
007A5A68  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
007A5A6E  8b8780000000                     mov    eax,DWORD PTR [edi+0x80]
007A5A74  8d4c2418                         lea    ecx,[esp+0x18]
007A5A78  3bc8                             cmp    ecx,eax
007A5A7A  7336                             jae    0x7a5ab2
007A5A7C  8b4f7c                           mov    ecx,DWORD PTR [edi+0x7c]
007A5A7F  8d542418                         lea    edx,[esp+0x18]
007A5A83  3bca                             cmp    ecx,edx
007A5A85  772b                             ja     0x7a5ab2
007A5A87  8bf2                             mov    esi,edx
007A5A89  2bf1                             sub    esi,ecx
007A5A8B  c1fe02                           sar    esi,0x2
007A5A8E  3b8784000000                     cmp    eax,DWORD PTR [edi+0x84]
007A5A94  7508                             jne    0x7a5a9e
007A5A96  8d477c                           lea    eax,[edi+0x7c]
007A5A99  e8921effff                       call   0x797930
007A5A9E  8b8780000000                     mov    eax,DWORD PTR [edi+0x80]
007A5AA4  85c0                             test   eax,eax
007A5AA6  7426                             je     0x7a5ace
007A5AA8  8b4f7c                           mov    ecx,DWORD PTR [edi+0x7c]
007A5AAB  8b14b1                           mov    edx,DWORD PTR [ecx+esi*4]
007A5AAE  8910                             mov    DWORD PTR [eax],edx
007A5AB0  eb1c                             jmp    0x7a5ace
007A5AB2  3b8784000000                     cmp    eax,DWORD PTR [edi+0x84]
007A5AB8  7508                             jne    0x7a5ac2
007A5ABA  8d477c                           lea    eax,[edi+0x7c]
007A5ABD  e86e1effff                       call   0x797930
007A5AC2  8b8780000000                     mov    eax,DWORD PTR [edi+0x80]
007A5AC8  85c0                             test   eax,eax
007A5ACA  7402                             je     0x7a5ace
007A5ACC  8930                             mov    DWORD PTR [eax],esi
007A5ACE  8b442420                         mov    eax,DWORD PTR [esp+0x20]
007A5AD2  83878000000004                   add    DWORD PTR [edi+0x80],0x4
007A5AD9  50                               push   eax
007A5ADA  ff154822bd00                     call   DWORD PTR ds:0xbd2248
007A5AE0  eb1b                             jmp    0x7a5afd
007A5AE2  83f801                           cmp    eax,0x1
007A5AE5  7c06                             jl     0x7a5aed
007A5AE7  56                               push   esi
007A5AE8  e803860100                       call   0x7be0f0
007A5AED  8bfe                             mov    edi,esi
007A5AEF  e85c7d0100                       call   0x7bd850
007A5AF4  56                               push   esi
007A5AF5  e812b70e00                       call   0x89120c
007A5AFA  83c404                           add    esp,0x4
007A5AFD  8b7c2414                         mov    edi,DWORD PTR [esp+0x14]
007A5B01  8b770c                           mov    esi,DWORD PTR [edi+0xc]
007A5B04  85f6                             test   esi,esi
007A5B06  7412                             je     0x7a5b1a
007A5B08  8b16                             mov    edx,DWORD PTR [esi]
007A5B0A  8b4210                           mov    eax,DWORD PTR [edx+0x10]
007A5B0D  8bce                             mov    ecx,esi
007A5B0F  ffd0                             call   eax
007A5B11  8b16                             mov    edx,DWORD PTR [esi]
007A5B13  8b4208                           mov    eax,DWORD PTR [edx+0x8]
007A5B16  8bce                             mov    ecx,esi
007A5B18  ffd0                             call   eax
007A5B1A  8b37                             mov    esi,DWORD PTR [edi]
007A5B1C  3bbb04010000                     cmp    edi,DWORD PTR [ebx+0x104]
007A5B22  741c                             je     0x7a5b40
007A5B24  8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
007A5B27  8931                             mov    DWORD PTR [ecx],esi
007A5B29  8b17                             mov    edx,DWORD PTR [edi]
007A5B2B  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A5B2E  57                               push   edi
007A5B2F  894204                           mov    DWORD PTR [edx+0x4],eax
007A5B32  e8d5b60e00                       call   0x89120c
007A5B37  83c404                           add    esp,0x4
007A5B3A  ff8b08010000                     dec    DWORD PTR [ebx+0x108]
007A5B40  89742414                         mov    DWORD PTR [esp+0x14],esi
007A5B44  3bb304010000                     cmp    esi,DWORD PTR [ebx+0x104]
007A5B4A  0f85d7feffff                     jne    0x7a5a27
007A5B50  8b8b04010000                     mov    ecx,DWORD PTR [ebx+0x104]
007A5B56  8b01                             mov    eax,DWORD PTR [ecx]
007A5B58  8909                             mov    DWORD PTR [ecx],ecx
007A5B5A  8b8b04010000                     mov    ecx,DWORD PTR [ebx+0x104]
007A5B60  894904                           mov    DWORD PTR [ecx+0x4],ecx
007A5B63  33ff                             xor    edi,edi
007A5B65  89bb08010000                     mov    DWORD PTR [ebx+0x108],edi
007A5B6B  3b8304010000                     cmp    eax,DWORD PTR [ebx+0x104]
007A5B71  7415                             je     0x7a5b88
007A5B73  8b30                             mov    esi,DWORD PTR [eax]
007A5B75  50                               push   eax
007A5B76  e891b60e00                       call   0x89120c
007A5B7B  83c404                           add    esp,0x4
007A5B7E  8bc6                             mov    eax,esi
007A5B80  3bb304010000                     cmp    esi,DWORD PTR [ebx+0x104]
007A5B86  75eb                             jne    0x7a5b73
007A5B88  89bb10010000                     mov    DWORD PTR [ebx+0x110],edi
007A5B8E  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
007A5B92  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A5B99  59                               pop    ecx
007A5B9A  5f                               pop    edi
007A5B9B  5e                               pop    esi
007A5B9C  5b                               pop    ebx
007A5B9D  8be5                             mov    esp,ebp
007A5B9F  5d                               pop    ebp
007A5BA0  c3                               ret

; N02_item_install_marks_dirty [NEW_OWNER_JOIN] 0x7a7510..0x7a7620 exclusive
007A7510  55                               push   ebp
007A7511  8bec                             mov    ebp,esp
007A7513  6aff                             push   0xffffffff
007A7515  689e8d9100                       push   0x918d9e
007A751A  64a100000000                     mov    eax,fs:0x0
007A7520  50                               push   eax
007A7521  83ec18                           sub    esp,0x18
007A7524  53                               push   ebx
007A7525  56                               push   esi
007A7526  57                               push   edi
007A7527  a1201fd600                       mov    eax,ds:0xd61f20
007A752C  33c5                             xor    eax,ebp
007A752E  50                               push   eax
007A752F  8d45f4                           lea    eax,[ebp-0xc]
007A7532  64a300000000                     mov    fs:0x0,eax
007A7538  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A753B  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
007A7542  7527                             jne    0x7a756b
007A7544  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
007A754B  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
007A7552  e8a9790100                       call   0x7bef00
007A7557  6850ecbc00                       push   0xbcec50
007A755C  e8b9ad0e00                       call   0x89231a
007A7561  83c404                           add    esp,0x4
007A7564  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007A756B  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
007A756E  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
007A7571  8d4de4                           lea    ecx,[ebp-0x1c]
007A7574  51                               push   ecx
007A7575  8d5508                           lea    edx,[ebp+0x8]
007A7578  52                               push   edx
007A7579  68601bfe00                       push   0xfe1b60
007A757E  8975e4                           mov    DWORD PTR [ebp-0x1c],esi
007A7581  8945e8                           mov    DWORD PTR [ebp-0x18],eax
007A7584  e8775ed3ff                       call   0x4dd400
007A7589  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A758C  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
007A7592  7476                             je     0x7a760a
007A7594  8b4018                           mov    eax,DWORD PTR [eax+0x18]
007A7597  85c0                             test   eax,eax
007A7599  746f                             je     0x7a760a
007A759B  8b7820                           mov    edi,DWORD PTR [eax+0x20]
007A759E  8bc6                             mov    eax,esi
007A75A0  c1e818                           shr    eax,0x18
007A75A3  3c01                             cmp    al,0x1
007A75A5  7503                             jne    0x7a75aa
007A75A7  83c710                           add    edi,0x10
007A75AA  8d4d08                           lea    ecx,[ebp+0x8]
007A75AD  8d735c                           lea    esi,[ebx+0x5c]
007A75B0  51                               push   ecx
007A75B1  8d45e8                           lea    eax,[ebp-0x18]
007A75B4  8bce                             mov    ecx,esi
007A75B6  897d08                           mov    DWORD PTR [ebp+0x8],edi
007A75B9  e84296ffff                       call   0x7a0c00
007A75BE  8b5360                           mov    edx,DWORD PTR [ebx+0x60]
007A75C1  3b10                             cmp    edx,DWORD PTR [eax]
007A75C3  7407                             je     0x7a75cc
007A75C5  57                               push   edi
007A75C6  53                               push   ebx
007A75C7  e854000000                       call   0x7a7620
007A75CC  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A75CF  8b4d10                           mov    ecx,DWORD PTR [ebp+0x10]
007A75D2  897ddc                           mov    DWORD PTR [ebp-0x24],edi
007A75D5  8d7ddc                           lea    edi,[ebp-0x24]
007A75D8  8945e4                           mov    DWORD PTR [ebp-0x1c],eax
007A75DB  894de8                           mov    DWORD PTR [ebp-0x18],ecx
007A75DE  e80db0ffff                       call   0x7a25f0
007A75E3  50                               push   eax
007A75E4  56                               push   esi
007A75E5  8d750c                           lea    esi,[ebp+0xc]
007A75E8  e823b2ffff                       call   0x7a2810
007A75ED  c6432801                         mov    BYTE PTR [ebx+0x28],0x1
007A75F1  b801000000                       mov    eax,0x1
007A75F6  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007A75F9  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A7600  59                               pop    ecx
007A7601  5f                               pop    edi
007A7602  5e                               pop    esi
007A7603  5b                               pop    ebx
007A7604  8be5                             mov    esp,ebp
007A7606  5d                               pop    ebp
007A7607  c20c00                           ret    0xc
007A760A  33c0                             xor    eax,eax
007A760C  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007A760F  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A7616  59                               pop    ecx
007A7617  5f                               pop    edi
007A7618  5e                               pop    esi
007A7619  5b                               pop    ebx
007A761A  8be5                             mov    esp,ebp
007A761C  5d                               pop    ebp
007A761D  c20c00                           ret    0xc

; N03_item_remove_marks_dirty [NEW_OWNER_JOIN] 0x7a7620..0x7a76a1 exclusive
007A7620  55                               push   ebp
007A7621  8bec                             mov    ebp,esp
007A7623  83ec0c                           sub    esp,0xc
007A7626  53                               push   ebx
007A7627  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A762A  56                               push   esi
007A762B  57                               push   edi
007A762C  8d450c                           lea    eax,[ebp+0xc]
007A762F  50                               push   eax
007A7630  8d4df8                           lea    ecx,[ebp-0x8]
007A7633  51                               push   ecx
007A7634  8d435c                           lea    eax,[ebx+0x5c]
007A7637  e8842a0000                       call   0x7aa0c0
007A763C  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
007A763F  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
007A7642  52                               push   edx
007A7643  50                               push   eax
007A7644  8d7508                           lea    esi,[ebp+0x8]
007A7647  8d435c                           lea    eax,[ebx+0x5c]
007A764A  e8d1faf2ff                       call   0x6d7120
007A764F  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
007A7652  8d4d0c                           lea    ecx,[ebp+0xc]
007A7655  51                               push   ecx
007A7656  83c610                           add    esi,0x10
007A7659  8d4508                           lea    eax,[ebp+0x8]
007A765C  8d4b5c                           lea    ecx,[ebx+0x5c]
007A765F  89750c                           mov    DWORD PTR [ebp+0xc],esi
007A7662  e89995ffff                       call   0x7a0c00
007A7667  8b5360                           mov    edx,DWORD PTR [ebx+0x60]
007A766A  3b10                             cmp    edx,DWORD PTR [eax]
007A766C  7426                             je     0x7a7694
007A766E  8d450c                           lea    eax,[ebp+0xc]
007A7671  50                               push   eax
007A7672  8d4df8                           lea    ecx,[ebp-0x8]
007A7675  51                               push   ecx
007A7676  8d435c                           lea    eax,[ebx+0x5c]
007A7679  89750c                           mov    DWORD PTR [ebp+0xc],esi
007A767C  e83f2a0000                       call   0x7aa0c0
007A7681  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
007A7684  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
007A7687  52                               push   edx
007A7688  50                               push   eax
007A7689  8d750c                           lea    esi,[ebp+0xc]
007A768C  8d435c                           lea    eax,[ebx+0x5c]
007A768F  e88cfaf2ff                       call   0x6d7120
007A7694  5f                               pop    edi
007A7695  5e                               pop    esi
007A7696  c6432801                         mov    BYTE PTR [ebx+0x28],0x1
007A769A  5b                               pop    ebx
007A769B  8be5                             mov    esp,ebp
007A769D  5d                               pop    ebp
007A769E  c20800                           ret    0x8

; N04_item_selection_dispatch [NEW_OWNER_JOIN] 0x7a7240..0x7a7501 exclusive
007A7240  55                               push   ebp
007A7241  8bec                             mov    ebp,esp
007A7243  83e4f8                           and    esp,0xfffffff8
007A7246  6aff                             push   0xffffffff
007A7248  68ea8d9100                       push   0x918dea
007A724D  64a100000000                     mov    eax,fs:0x0
007A7253  50                               push   eax
007A7254  83ec30                           sub    esp,0x30
007A7257  53                               push   ebx
007A7258  56                               push   esi
007A7259  57                               push   edi
007A725A  a1201fd600                       mov    eax,ds:0xd61f20
007A725F  33c4                             xor    eax,esp
007A7261  50                               push   eax
007A7262  8d442440                         lea    eax,[esp+0x40]
007A7266  64a300000000                     mov    fs:0x0,eax
007A726C  668b450c                         mov    ax,WORD PTR [ebp+0xc]
007A7270  668944241c                       mov    WORD PTR [esp+0x1c],ax
007A7275  c644241f00                       mov    BYTE PTR [esp+0x1f],0x0
007A727A  66c74424220000                   mov    WORD PTR [esp+0x22],0x0
007A7281  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
007A7288  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007A728B  0fb74118                         movzx  eax,WORD PTR [ecx+0x18]
007A728F  8a5510                           mov    dl,BYTE PTR [ebp+0x10]
007A7292  8854241e                         mov    BYTE PTR [esp+0x1e],dl
007A7296  6689442420                       mov    WORD PTR [esp+0x20],ax
007A729B  7529                             jne    0x7a72c6
007A729D  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
007A72A4  c744244800000000                 mov    DWORD PTR [esp+0x48],0x0
007A72AC  e84f7c0100                       call   0x7bef00
007A72B1  6850ecbc00                       push   0xbcec50
007A72B6  e85fb00e00                       call   0x89231a
007A72BB  83c404                           add    esp,0x4
007A72BE  c7442448ffffffff                 mov    DWORD PTR [esp+0x48],0xffffffff
007A72C6  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
007A72CA  8b5c2420                         mov    ebx,DWORD PTR [esp+0x20]
007A72CE  8d44242c                         lea    eax,[esp+0x2c]
007A72D2  50                               push   eax
007A72D3  8d4c2418                         lea    ecx,[esp+0x18]
007A72D7  51                               push   ecx
007A72D8  68601bfe00                       push   0xfe1b60
007A72DD  897c2438                         mov    DWORD PTR [esp+0x38],edi
007A72E1  895c243c                         mov    DWORD PTR [esp+0x3c],ebx
007A72E5  e81661d3ff                       call   0x4dd400
007A72EA  8b442414                         mov    eax,DWORD PTR [esp+0x14]
007A72EE  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
007A72F4  740b                             je     0x7a7301
007A72F6  8b7018                           mov    esi,DWORD PTR [eax+0x18]
007A72F9  85f6                             test   esi,esi
007A72FB  0f8584000000                     jne    0x7a7385
007A7301  668b550c                         mov    dx,WORD PTR [ebp+0xc]
007A7305  8a4510                           mov    al,BYTE PTR [ebp+0x10]
007A7308  33c9                             xor    ecx,ecx
007A730A  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
007A7311  6689542424                       mov    WORD PTR [esp+0x24],dx
007A7316  88442426                         mov    BYTE PTR [esp+0x26],al
007A731A  c644242700                       mov    BYTE PTR [esp+0x27],0x0
007A731F  894c2428                         mov    DWORD PTR [esp+0x28],ecx
007A7323  7529                             jne    0x7a734e
007A7325  b801000000                       mov    eax,0x1
007A732A  0905c01bfe00                     or     DWORD PTR ds:0xfe1bc0,eax
007A7330  89442448                         mov    DWORD PTR [esp+0x48],eax
007A7334  e8c77b0100                       call   0x7bef00
007A7339  6850ecbc00                       push   0xbcec50
007A733E  e8d7af0e00                       call   0x89231a
007A7343  83c404                           add    esp,0x4
007A7346  c7442448ffffffff                 mov    DWORD PTR [esp+0x48],0xffffffff
007A734E  8b7c2424                         mov    edi,DWORD PTR [esp+0x24]
007A7352  8b5c2428                         mov    ebx,DWORD PTR [esp+0x28]
007A7356  8d542434                         lea    edx,[esp+0x34]
007A735A  52                               push   edx
007A735B  8d44241c                         lea    eax,[esp+0x1c]
007A735F  50                               push   eax
007A7360  68601bfe00                       push   0xfe1b60
007A7365  897c2440                         mov    DWORD PTR [esp+0x40],edi
007A7369  895c2444                         mov    DWORD PTR [esp+0x44],ebx
007A736D  e88e60d3ff                       call   0x4dd400
007A7372  8b442418                         mov    eax,DWORD PTR [esp+0x18]
007A7376  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
007A737C  7504                             jne    0x7a7382
007A737E  33f6                             xor    esi,esi
007A7380  eb03                             jmp    0x7a7385
007A7382  8b7018                           mov    esi,DWORD PTR [eax+0x18]
007A7385  8bcb                             mov    ecx,ebx
007A7387  8bc7                             mov    eax,edi
007A7389  85f6                             test   esi,esi
007A738B  7511                             jne    0x7a739e
007A738D  397510                           cmp    DWORD PTR [ebp+0x10],esi
007A7390  0f8454010000                     je     0x7a74ea
007A7396  ff4d10                           dec    DWORD PTR [ebp+0x10]
007A7399  e9e3feffff                       jmp    0x7a7281
007A739E  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A73A1  51                               push   ecx
007A73A2  50                               push   eax
007A73A3  53                               push   ebx
007A73A4  e867010000                       call   0x7a7510
007A73A9  8b7e20                           mov    edi,DWORD PTR [esi+0x20]
007A73AC  8b5b60                           mov    ebx,DWORD PTR [ebx+0x60]
007A73AF  8d4c2418                         lea    ecx,[esp+0x18]
007A73B3  51                               push   ecx
007A73B4  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007A73B7  8d7710                           lea    esi,[edi+0x10]
007A73BA  83c15c                           add    ecx,0x5c
007A73BD  8d442418                         lea    eax,[esp+0x18]
007A73C1  8974241c                         mov    DWORD PTR [esp+0x1c],esi
007A73C5  e83698ffff                       call   0x7a0c00
007A73CA  3b18                             cmp    ebx,DWORD PTR [eax]
007A73CC  740a                             je     0x7a73d8
007A73CE  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
007A73D1  56                               push   esi
007A73D2  52                               push   edx
007A73D3  e848020000                       call   0x7a7620
007A73D8  33c0                             xor    eax,eax
007A73DA  394514                           cmp    DWORD PTR [ebp+0x14],eax
007A73DD  0f84ed000000                     je     0x7a74d0
007A73E3  83ff01                           cmp    edi,0x1
007A73E6  0f85e4000000                     jne    0x7a74d0
007A73EC  8944241c                         mov    DWORD PTR [esp+0x1c],eax
007A73F0  89442420                         mov    DWORD PTR [esp+0x20],eax
007A73F4  8b5d10                           mov    ebx,DWORD PTR [ebp+0x10]
007A73F7  85c0                             test   eax,eax
007A73F9  0f85be000000                     jne    0x7a74bd
007A73FF  668b4514                         mov    ax,WORD PTR [ebp+0x14]
007A7403  6689442424                       mov    WORD PTR [esp+0x24],ax
007A7408  c644242701                       mov    BYTE PTR [esp+0x27],0x1
007A740D  66c744242a0000                   mov    WORD PTR [esp+0x2a],0x0
007A7414  eb0a                             jmp    0x7a7420
007A7416  8da42400000000                   lea    esp,[esp+0x0]
007A741D  8d4900                           lea    ecx,[ecx+0x0]
007A7420  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
007A7427  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007A742A  0fb74118                         movzx  eax,WORD PTR [ecx+0x18]
007A742E  885c2426                         mov    BYTE PTR [esp+0x26],bl
007A7432  8b742424                         mov    esi,DWORD PTR [esp+0x24]
007A7436  6689442428                       mov    WORD PTR [esp+0x28],ax
007A743B  8b7c2428                         mov    edi,DWORD PTR [esp+0x28]
007A743F  8974241c                         mov    DWORD PTR [esp+0x1c],esi
007A7443  897c2420                         mov    DWORD PTR [esp+0x20],edi
007A7447  7529                             jne    0x7a7472
007A7449  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
007A7450  c744244802000000                 mov    DWORD PTR [esp+0x48],0x2
007A7458  e8a37a0100                       call   0x7bef00
007A745D  6850ecbc00                       push   0xbcec50
007A7462  e8b3ae0e00                       call   0x89231a
007A7467  83c404                           add    esp,0x4
007A746A  c7442448ffffffff                 mov    DWORD PTR [esp+0x48],0xffffffff
007A7472  8d542434                         lea    edx,[esp+0x34]
007A7476  52                               push   edx
007A7477  8d44241c                         lea    eax,[esp+0x1c]
007A747B  50                               push   eax
007A747C  68601bfe00                       push   0xfe1b60
007A7481  89742440                         mov    DWORD PTR [esp+0x40],esi
007A7485  897c2444                         mov    DWORD PTR [esp+0x44],edi
007A7489  e8725fd3ff                       call   0x4dd400
007A748E  8b442418                         mov    eax,DWORD PTR [esp+0x18]
007A7492  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
007A7498  7504                             jne    0x7a749e
007A749A  33c0                             xor    eax,eax
007A749C  eb07                             jmp    0x7a74a5
007A749E  8b4018                           mov    eax,DWORD PTR [eax+0x18]
007A74A1  85c0                             test   eax,eax
007A74A3  7518                             jne    0x7a74bd
007A74A5  85db                             test   ebx,ebx
007A74A7  7406                             je     0x7a74af
007A74A9  4b                               dec    ebx
007A74AA  e971ffffff                       jmp    0x7a7420
007A74AF  837d1400                         cmp    DWORD PTR [ebp+0x14],0x0
007A74B3  7408                             je     0x7a74bd
007A74B5  ff4d14                           dec    DWORD PTR [ebp+0x14]
007A74B8  e937ffffff                       jmp    0x7a73f4
007A74BD  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
007A74C1  8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
007A74C5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A74C8  51                               push   ecx
007A74C9  52                               push   edx
007A74CA  50                               push   eax
007A74CB  e840000000                       call   0x7a7510
007A74D0  b801000000                       mov    eax,0x1
007A74D5  8b4c2440                         mov    ecx,DWORD PTR [esp+0x40]
007A74D9  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A74E0  59                               pop    ecx
007A74E1  5f                               pop    edi
007A74E2  5e                               pop    esi
007A74E3  5b                               pop    ebx
007A74E4  8be5                             mov    esp,ebp
007A74E6  5d                               pop    ebp
007A74E7  c21000                           ret    0x10
007A74EA  33c0                             xor    eax,eax
007A74EC  8b4c2440                         mov    ecx,DWORD PTR [esp+0x40]
007A74F0  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A74F7  59                               pop    ecx
007A74F8  5f                               pop    edi
007A74F9  5e                               pop    esi
007A74FA  5b                               pop    ebx
007A74FB  8be5                             mov    esp,ebp
007A74FD  5d                               pop    ebp
007A74FE  c21000                           ret    0x10

; N05_string_assign [REUSED_CALLEE_JOIN] 0x402a70..0x402b65 exclusive
00402A70  55                               push   ebp
00402A71  8bec                             mov    ebp,esp
00402A73  53                               push   ebx
00402A74  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
00402A77  56                               push   esi
00402A78  8bf1                             mov    esi,ecx
00402A7A  85db                             test   ebx,ebx
00402A7C  7459                             je     0x402ad7
00402A7E  8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
00402A81  83f910                           cmp    ecx,0x10
00402A84  7204                             jb     0x402a8a
00402A86  8b06                             mov    eax,DWORD PTR [esi]
00402A88  eb02                             jmp    0x402a8c
00402A8A  8bc6                             mov    eax,esi
00402A8C  3bd8                             cmp    ebx,eax
00402A8E  7247                             jb     0x402ad7
00402A90  83f910                           cmp    ecx,0x10
00402A93  7204                             jb     0x402a99
00402A95  8b06                             mov    eax,DWORD PTR [esi]
00402A97  eb02                             jmp    0x402a9b
00402A99  8bc6                             mov    eax,esi
00402A9B  8b5610                           mov    edx,DWORD PTR [esi+0x10]
00402A9E  03d0                             add    edx,eax
00402AA0  3bd3                             cmp    edx,ebx
00402AA2  7633                             jbe    0x402ad7
00402AA4  83f910                           cmp    ecx,0x10
00402AA7  7217                             jb     0x402ac0
00402AA9  8b06                             mov    eax,DWORD PTR [esi]
00402AAB  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
00402AAE  51                               push   ecx
00402AAF  2bd8                             sub    ebx,eax
00402AB1  53                               push   ebx
00402AB2  56                               push   esi
00402AB3  8bce                             mov    ecx,esi
00402AB5  e886050000                       call   0x403040
00402ABA  5e                               pop    esi
00402ABB  5b                               pop    ebx
00402ABC  5d                               pop    ebp
00402ABD  c20800                           ret    0x8
00402AC0  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
00402AC3  8bc6                             mov    eax,esi
00402AC5  51                               push   ecx
00402AC6  2bd8                             sub    ebx,eax
00402AC8  53                               push   ebx
00402AC9  56                               push   esi
00402ACA  8bce                             mov    ecx,esi
00402ACC  e86f050000                       call   0x403040
00402AD1  5e                               pop    esi
00402AD2  5b                               pop    ebx
00402AD3  5d                               pop    ebp
00402AD4  c20800                           ret    0x8
00402AD7  57                               push   edi
00402AD8  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
00402ADB  83fffe                           cmp    edi,0xfffffffe
00402ADE  760a                             jbe    0x402aea
00402AE0  6800d2be00                       push   0xbed200
00402AE5  e846b04700                       call   0x87db30
00402AEA  8b4614                           mov    eax,DWORD PTR [esi+0x14]
00402AED  3bc7                             cmp    eax,edi
00402AEF  731a                             jae    0x402b0b
00402AF1  8b5610                           mov    edx,DWORD PTR [esi+0x10]
00402AF4  52                               push   edx
00402AF5  57                               push   edi
00402AF6  8bce                             mov    ecx,esi
00402AF8  e8c3020000                       call   0x402dc0
00402AFD  85ff                             test   edi,edi
00402AFF  745b                             je     0x402b5c
00402B01  837e1410                         cmp    DWORD PTR [esi+0x14],0x10
00402B05  722a                             jb     0x402b31
00402B07  8b06                             mov    eax,DWORD PTR [esi]
00402B09  eb28                             jmp    0x402b33
00402B0B  85ff                             test   edi,edi
00402B0D  75f2                             jne    0x402b01
00402B0F  897e10                           mov    DWORD PTR [esi+0x10],edi
00402B12  83f810                           cmp    eax,0x10
00402B15  720e                             jb     0x402b25
00402B17  8b06                             mov    eax,DWORD PTR [esi]
00402B19  5f                               pop    edi
00402B1A  c60000                           mov    BYTE PTR [eax],0x0
00402B1D  8bc6                             mov    eax,esi
00402B1F  5e                               pop    esi
00402B20  5b                               pop    ebx
00402B21  5d                               pop    ebp
00402B22  c20800                           ret    0x8
00402B25  5f                               pop    edi
00402B26  8bc6                             mov    eax,esi
00402B28  5e                               pop    esi
00402B29  c60000                           mov    BYTE PTR [eax],0x0
00402B2C  5b                               pop    ebx
00402B2D  5d                               pop    ebp
00402B2E  c20800                           ret    0x8
00402B31  8bc6                             mov    eax,esi
00402B33  57                               push   edi
00402B34  53                               push   ebx
00402B35  50                               push   eax
00402B36  e895b04900                       call   0x89dbd0
00402B3B  83c40c                           add    esp,0xc
00402B3E  837e1410                         cmp    DWORD PTR [esi+0x14],0x10
00402B42  897e10                           mov    DWORD PTR [esi+0x10],edi
00402B45  720f                             jb     0x402b56
00402B47  8b06                             mov    eax,DWORD PTR [esi]
00402B49  c6043800                         mov    BYTE PTR [eax+edi*1],0x0
00402B4D  5f                               pop    edi
00402B4E  8bc6                             mov    eax,esi
00402B50  5e                               pop    esi
00402B51  5b                               pop    ebx
00402B52  5d                               pop    ebp
00402B53  c20800                           ret    0x8
00402B56  8bc6                             mov    eax,esi
00402B58  c6043800                         mov    BYTE PTR [eax+edi*1],0x0
00402B5C  5f                               pop    edi
00402B5D  8bc6                             mov    eax,esi
00402B5F  5e                               pop    esi
00402B60  5b                               pop    ebx
00402B61  5d                               pop    ebp
00402B62  c20800                           ret    0x8

; N06_first_char_space_test [NEW_PREDICATE_JOIN] 0x895530..0x89555e exclusive
00895530  8bff                             mov    edi,edi
00895532  55                               push   ebp
00895533  8bec                             mov    ebp,esp
00895535  833d10cbf80000                   cmp    DWORD PTR ds:0xf8cb10,0x0
0089553C  7512                             jne    0x895550
0089553E  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00895541  8b0d6828d600                     mov    ecx,DWORD PTR ds:0xd62868
00895547  0fb70441                         movzx  eax,WORD PTR [ecx+eax*2]
0089554B  83e008                           and    eax,0x8
0089554E  5d                               pop    ebp
0089554F  c3                               ret
00895550  6a00                             push   0x0
00895552  ff7508                           push   DWORD PTR [ebp+0x8]
00895555  e885ffffff                       call   0x8954df
0089555A  59                               pop    ecx
0089555B  59                               pop    ecx
0089555C  5d                               pop    ebp
0089555D  c3                               ret

; N07_locale_space_test [NEW_PREDICATE_JOIN] 0x8954df..0x895530 exclusive
008954DF  8bff                             mov    edi,edi
008954E1  55                               push   ebp
008954E2  8bec                             mov    ebp,esp
008954E4  83ec10                           sub    esp,0x10
008954E7  ff750c                           push   DWORD PTR [ebp+0xc]
008954EA  8d4df0                           lea    ecx,[ebp-0x10]
008954ED  e88cd4ffff                       call   0x89297e
008954F2  8b45f0                           mov    eax,DWORD PTR [ebp-0x10]
008954F5  83b8ac00000001                   cmp    DWORD PTR [eax+0xac],0x1
008954FC  7e13                             jle    0x895511
008954FE  8d45f0                           lea    eax,[ebp-0x10]
00895501  50                               push   eax
00895502  6a08                             push   0x8
00895504  ff7508                           push   DWORD PTR [ebp+0x8]
00895507  e8431f0100                       call   0x8a744f
0089550C  83c40c                           add    esp,0xc
0089550F  eb10                             jmp    0x895521
00895511  8b80c8000000                     mov    eax,DWORD PTR [eax+0xc8]
00895517  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0089551A  0fb70448                         movzx  eax,WORD PTR [eax+ecx*2]
0089551E  83e008                           and    eax,0x8
00895521  807dfc00                         cmp    BYTE PTR [ebp-0x4],0x0
00895525  7407                             je     0x89552e
00895527  8b4df8                           mov    ecx,DWORD PTR [ebp-0x8]
0089552A  836170fd                         and    DWORD PTR [ecx+0x70],0xfffffffd
0089552E  c9                               leave
0089552F  c3                               ret
