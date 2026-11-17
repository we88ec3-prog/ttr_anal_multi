; lb_create_ex | local concrete actor allocation, placement, model, scale, world insertion
; VA 0x4a0f70..0x4a1230 raw 0xa0370 length 704 sha256 19f1361623fcbd9d251539c9224d44fe10f5f6995b525a8748ac7c3909848d5e
0x4a0f70  55                               push   ebp
0x4a0f71  8bec                             mov    ebp,esp
0x4a0f73  83e4f8                           and    esp,0xfffffff8
0x4a0f76  6aff                             push   0xffffffff
0x4a0f78  686b9f9300                       push   0x939f6b
0x4a0f7d  64a100000000                     mov    eax,fs:0x0
0x4a0f83  50                               push   eax
0x4a0f84  83ec18                           sub    esp,0x18
0x4a0f87  53                               push   ebx
0x4a0f88  56                               push   esi
0x4a0f89  57                               push   edi
0x4a0f8a  a1201fd600                       mov    eax,ds:0xd61f20
0x4a0f8f  33c4                             xor    eax,esp
0x4a0f91  50                               push   eax
0x4a0f92  8d442428                         lea    eax,[esp+0x28]
0x4a0f96  64a300000000                     mov    fs:0x0,eax
0x4a0f9c  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x4a0f9f  33f6                             xor    esi,esi
0x4a0fa1  33db                             xor    ebx,ebx
0x4a0fa3  83ff0a                           cmp    edi,0xa
0x4a0fa6  7c10                             jl     0x4a0fb8
0x4a0fa8  81ff10270000                     cmp    edi,0x2710
0x4a0fae  0f9ec3                           setle  bl
0x4a0fb1  4b                               dec    ebx
0x4a0fb2  83e305                           and    ebx,0x5
0x4a0fb5  43                               inc    ebx
0x4a0fb6  7527                             jne    0x4a0fdf
0x4a0fb8  6844040000                       push   0x444
0x4a0fbd  e8a6023f00                       call   0x891268
0x4a0fc2  83c404                           add    esp,0x4
0x4a0fc5  89442414                         mov    DWORD PTR [esp+0x14],eax
0x4a0fc9  c744243000000000                 mov    DWORD PTR [esp+0x30],0x0
0x4a0fd1  85c0                             test   eax,eax
0x4a0fd3  746e                             je     0x4a1043
0x4a0fd5  6a00                             push   0x0
0x4a0fd7  50                               push   eax
0x4a0fd8  e813c70200                       call   0x4cd6f0
0x4a0fdd  eb66                             jmp    0x4a1045
0x4a0fdf  83fb01                           cmp    ebx,0x1
0x4a0fe2  7535                             jne    0x4a1019
0x4a0fe4  6834040000                       push   0x434
0x4a0fe9  e87a023f00                       call   0x891268
0x4a0fee  83c404                           add    esp,0x4
0x4a0ff1  89442414                         mov    DWORD PTR [esp+0x14],eax
0x4a0ff5  895c2430                         mov    DWORD PTR [esp+0x30],ebx
0x4a0ff9  85c0                             test   eax,eax
0x4a0ffb  7408                             je     0x4a1005
0x4a0ffd  50                               push   eax
0x4a0ffe  e80d070300                       call   0x4d1710
0x4a1003  eb02                             jmp    0x4a1007
0x4a1005  33c0                             xor    eax,eax
0x4a1007  57                               push   edi
0x4a1008  c7442434ffffffff                 mov    DWORD PTR [esp+0x34],0xffffffff
0x4a1010  8bf0                             mov    esi,eax
0x4a1012  e8b9fdffff                       call   0x4a0dd0
0x4a1017  eb36                             jmp    0x4a104f
0x4a1019  83fb06                           cmp    ebx,0x6
0x4a101c  7531                             jne    0x4a104f
0x4a101e  682c040000                       push   0x42c
0x4a1023  e840023f00                       call   0x891268
0x4a1028  83c404                           add    esp,0x4
0x4a102b  89442414                         mov    DWORD PTR [esp+0x14],eax
0x4a102f  c744243002000000                 mov    DWORD PTR [esp+0x30],0x2
0x4a1037  85c0                             test   eax,eax
0x4a1039  7408                             je     0x4a1043
0x4a103b  50                               push   eax
0x4a103c  e8df100300                       call   0x4d2120
0x4a1041  eb02                             jmp    0x4a1045
0x4a1043  33c0                             xor    eax,eax
0x4a1045  8bf0                             mov    esi,eax
0x4a1047  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x4a104f  66a104def700                     mov    ax,ds:0xf7de04
0x4a1055  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
0x4a105a  8b16                             mov    edx,DWORD PTR [esi]
0x4a105c  8b5244                           mov    edx,DWORD PTR [edx+0x44]
0x4a105f  66894604                         mov    WORD PTR [esi+0x4],ax
0x4a1063  6a01                             push   0x1
0x4a1065  8d442418                         lea    eax,[esp+0x18]
0x4a1069  f30f11442418                     movss  DWORD PTR [esp+0x18],xmm0
0x4a106f  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
0x4a1074  50                               push   eax
0x4a1075  8bce                             mov    ecx,esi
0x4a1077  f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
0x4a107d  ffd2                             call   edx
0x4a107f  8b4d18                           mov    ecx,DWORD PTR [ebp+0x18]
0x4a1082  8b06                             mov    eax,DWORD PTR [esi]
0x4a1084  8b5058                           mov    edx,DWORD PTR [eax+0x58]
0x4a1087  51                               push   ecx
0x4a1088  8bce                             mov    ecx,esi
0x4a108a  ffd2                             call   edx
0x4a108c  8b06                             mov    eax,DWORD PTR [esi]
0x4a108e  8b403c                           mov    eax,DWORD PTR [eax+0x3c]
0x4a1091  0fb6cb                           movzx  ecx,bl
0x4a1094  0fb7d7                           movzx  edx,di
0x4a1097  c1e118                           shl    ecx,0x18
0x4a109a  0bca                             or     ecx,edx
0x4a109c  51                               push   ecx
0x4a109d  8bce                             mov    ecx,esi
0x4a109f  ffd0                             call   eax
0x4a10a1  83ff0a                           cmp    edi,0xa
0x4a10a4  bf01000000                       mov    edi,0x1
0x4a10a9  7d24                             jge    0x4a10cf
0x4a10ab  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
0x4a10b1  8bcf                             mov    ecx,edi
0x4a10b3  66898e88030000                   mov    WORD PTR [esi+0x388],cx
0x4a10ba  85c0                             test   eax,eax
0x4a10bc  7411                             je     0x4a10cf
0x4a10be  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
0x4a10c5  7408                             je     0x4a10cf
0x4a10c7  57                               push   edi
0x4a10c8  57                               push   edi
0x4a10c9  50                               push   eax
0x4a10ca  e8d15d3000                       call   0x7a6ea0
0x4a10cf  8b16                             mov    edx,DWORD PTR [esi]
0x4a10d1  8b4230                           mov    eax,DWORD PTR [edx+0x30]
0x4a10d4  8bce                             mov    ecx,esi
0x4a10d6  ffd0                             call   eax
0x4a10d8  f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x4a10df  7528                             jne    0x4a1109
0x4a10e1  093d2888fb00                     or     DWORD PTR ds:0xfb8828,edi
0x4a10e7  c744243003000000                 mov    DWORD PTR [esp+0x30],0x3
0x4a10ef  e85ce70a00                       call   0x54f850
0x4a10f4  6880d5bc00                       push   0xbcd580
0x4a10f9  e81c123f00                       call   0x89231a
0x4a10fe  83c404                           add    esp,0x4
0x4a1101  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x4a1109  db4514                           fild   DWORD PTR [ebp+0x14]
0x4a110c  8b16                             mov    edx,DWORD PTR [esi]
0x4a110e  8b425c                           mov    eax,DWORD PTR [edx+0x5c]
0x4a1111  51                               push   ecx
0x4a1112  d80dbc90fb00                     fmul   DWORD PTR ds:0xfb90bc
0x4a1118  8bce                             mov    ecx,esi
0x4a111a  d95c2418                         fstp   DWORD PTR [esp+0x18]
0x4a111e  d9442418                         fld    DWORD PTR [esp+0x18]
0x4a1122  d91c24                           fstp   DWORD PTR [esp]
0x4a1125  ffd0                             call   eax
0x4a1127  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
0x4a112c  8b16                             mov    edx,DWORD PTR [esi]
0x4a112e  8b5244                           mov    edx,DWORD PTR [edx+0x44]
0x4a1131  57                               push   edi
0x4a1132  8d442420                         lea    eax,[esp+0x20]
0x4a1136  f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
0x4a113c  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
0x4a1141  50                               push   eax
0x4a1142  8bce                             mov    ecx,esi
0x4a1144  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
0x4a114a  ffd2                             call   edx
0x4a114c  8b86f0000000                     mov    eax,DWORD PTR [esi+0xf0]
0x4a1152  8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x4a1155  8d8ef0000000                     lea    ecx,[esi+0xf0]
0x4a115b  57                               push   edi
0x4a115c  ffd2                             call   edx
0x4a115e  d9e8                             fld1
0x4a1160  8b06                             mov    eax,DWORD PTR [esi]
0x4a1162  8b5068                           mov    edx,DWORD PTR [eax+0x68]
0x4a1165  51                               push   ecx
0x4a1166  d91c24                           fstp   DWORD PTR [esp]
0x4a1169  57                               push   edi
0x4a116a  8bce                             mov    ecx,esi
0x4a116c  ffd2                             call   edx
0x4a116e  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
0x4a1175  f30f1005b45ac500                 movss  xmm0,DWORD PTR ds:0xc55ab4
0x4a117d  f30f1186cc000000                 movss  DWORD PTR [esi+0xcc],xmm0
0x4a1185  7528                             jne    0x4a11af
0x4a1187  093d2cb2fa00                     or     DWORD PTR ds:0xfab22c,edi
0x4a118d  c744243004000000                 mov    DWORD PTR [esp+0x30],0x4
0x4a1195  e8f6da0300                       call   0x4dec90
0x4a119a  6830cebc00                       push   0xbcce30
0x4a119f  e876113f00                       call   0x89231a
0x4a11a4  83c404                           add    esp,0x4
0x4a11a7  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x4a11af  6830b1fa00                       push   0xfab130
0x4a11b4  8bc6                             mov    eax,esi
0x4a11b6  e875ed0300                       call   0x4dff30
0x4a11bb  013d04def700                     add    DWORD PTR ds:0xf7de04,edi
0x4a11c1  837d1c00                         cmp    DWORD PTR [ebp+0x1c],0x0
0x4a11c5  7451                             je     0x4a1218
0x4a11c7  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4a11cd  8b01                             mov    eax,DWORD PTR [ecx]
0x4a11cf  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4a11d2  56                               push   esi
0x4a11d3  897904                           mov    DWORD PTR [ecx+0x4],edi
0x4a11d6  ffd2                             call   edx
0x4a11d8  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4a11de  8b01                             mov    eax,DWORD PTR [ecx]
0x4a11e0  8b5010                           mov    edx,DWORD PTR [eax+0x10]
0x4a11e3  ffd2                             call   edx
0x4a11e5  f605147cfb0001                   test   BYTE PTR ds:0xfb7c14,0x1
0x4a11ec  7520                             jne    0x4a120e
0x4a11ee  093d147cfb00                     or     DWORD PTR ds:0xfb7c14,edi
0x4a11f4  c744243005000000                 mov    DWORD PTR [esp+0x30],0x5
0x4a11fc  e84ff52200                       call   0x6d0750
0x4a1201  6830d5bc00                       push   0xbcd530
0x4a1206  e80f113f00                       call   0x89231a
0x4a120b  83c404                           add    esp,0x4
0x4a120e  c7053088fb0000000000             mov    DWORD PTR ds:0xfb8830,0x0
0x4a1218  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x4a121c  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a1223  59                               pop    ecx
0x4a1224  5f                               pop    edi
0x4a1225  5e                               pop    esi
0x4a1226  5b                               pop    ebx
0x4a1227  8be5                             mov    esp,ebp
0x4a1229  5d                               pop    ebp
0x4a122a  c21800                           ret    0x18
0x4a122d  cc                               int3
0x4a122e  cc                               int3
0x4a122f  cc                               int3

; lb_avatar | DWORD world key lookup; WORD actor avatar; CDoll helper
; VA 0x4a0b80..0x4a0c50 raw 0x9ff80 length 208 sha256 e73b4fec60db789ffbe900e2930eedbc97cc623714fbf92a6f7f9cb719b46227
0x4a0b80  55                               push   ebp
0x4a0b81  8bec                             mov    ebp,esp
0x4a0b83  83e4f8                           and    esp,0xfffffff8
0x4a0b86  6aff                             push   0xffffffff
0x4a0b88  68fe6e9300                       push   0x936efe
0x4a0b8d  64a100000000                     mov    eax,fs:0x0
0x4a0b93  50                               push   eax
0x4a0b94  83ec0c                           sub    esp,0xc
0x4a0b97  a1201fd600                       mov    eax,ds:0xd61f20
0x4a0b9c  33c4                             xor    eax,esp
0x4a0b9e  50                               push   eax
0x4a0b9f  8d442410                         lea    eax,[esp+0x10]
0x4a0ba3  64a300000000                     mov    fs:0x0,eax
0x4a0ba9  b801000000                       mov    eax,0x1
0x4a0bae  84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
0x4a0bb4  7528                             jne    0x4a0bde
0x4a0bb6  09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
0x4a0bbc  c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
0x4a0bc4  e8c7e00300                       call   0x4dec90
0x4a0bc9  6830cebc00                       push   0xbcce30
0x4a0bce  e847173f00                       call   0x89231a
0x4a0bd3  83c404                           add    esp,0x4
0x4a0bd6  c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x4a0bde  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a0be1  8d4c2404                         lea    ecx,[esp+0x4]
0x4a0be5  89442404                         mov    DWORD PTR [esp+0x4],eax
0x4a0be9  51                               push   ecx
0x4a0bea  8d44240c                         lea    eax,[esp+0xc]
0x4a0bee  b938b1fa00                       mov    ecx,0xfab138
0x4a0bf3  e808e33800                       call   0x82ef00
0x4a0bf8  8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x4a0bfc  3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
0x4a0c02  742f                             je     0x4a0c33
0x4a0c04  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4a0c07  85c0                             test   eax,eax
0x4a0c09  7428                             je     0x4a0c33
0x4a0c0b  8b885c010000                     mov    ecx,DWORD PTR [eax+0x15c]
0x4a0c11  8b5510                           mov    edx,DWORD PTR [ebp+0x10]
0x4a0c14  66899088030000                   mov    WORD PTR [eax+0x388],dx
0x4a0c1b  85c9                             test   ecx,ecx
0x4a0c1d  7414                             je     0x4a0c33
0x4a0c1f  83b87003000000                   cmp    DWORD PTR [eax+0x370],0x0
0x4a0c26  740b                             je     0x4a0c33
0x4a0c28  52                               push   edx
0x4a0c29  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x4a0c2c  52                               push   edx
0x4a0c2d  51                               push   ecx
0x4a0c2e  e86d623000                       call   0x7a6ea0
0x4a0c33  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4a0c37  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a0c3e  59                               pop    ecx
0x4a0c3f  8be5                             mov    esp,ebp
0x4a0c41  5d                               pop    ebp
0x4a0c42  c20c00                           ret    0xc
0x4a0c45  cc                               int3
0x4a0c46  cc                               int3
0x4a0c47  cc                               int3
0x4a0c48  cc                               int3
0x4a0c49  cc                               int3
0x4a0c4a  cc                               int3
0x4a0c4b  cc                               int3
0x4a0c4c  cc                               int3
0x4a0c4d  cc                               int3
0x4a0c4e  cc                               int3
0x4a0c4f  cc                               int3

; lb_attach | DWORD world key; low WORD appearance item; zero variant/extra flag
; VA 0x4a0c50..0x4a0d10 raw 0xa0050 length 192 sha256 e5ca57b46563473387fd87085fc1bff9f2302e0800ece0c8c656570ea501dba9
0x4a0c50  55                               push   ebp
0x4a0c51  8bec                             mov    ebp,esp
0x4a0c53  83e4f8                           and    esp,0xfffffff8
0x4a0c56  6aff                             push   0xffffffff
0x4a0c58  68fe6e9300                       push   0x936efe
0x4a0c5d  64a100000000                     mov    eax,fs:0x0
0x4a0c63  50                               push   eax
0x4a0c64  83ec0c                           sub    esp,0xc
0x4a0c67  a1201fd600                       mov    eax,ds:0xd61f20
0x4a0c6c  33c4                             xor    eax,esp
0x4a0c6e  50                               push   eax
0x4a0c6f  8d442410                         lea    eax,[esp+0x10]
0x4a0c73  64a300000000                     mov    fs:0x0,eax
0x4a0c79  b801000000                       mov    eax,0x1
0x4a0c7e  84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
0x4a0c84  7528                             jne    0x4a0cae
0x4a0c86  09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
0x4a0c8c  c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
0x4a0c94  e8f7df0300                       call   0x4dec90
0x4a0c99  6830cebc00                       push   0xbcce30
0x4a0c9e  e877163f00                       call   0x89231a
0x4a0ca3  83c404                           add    esp,0x4
0x4a0ca6  c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x4a0cae  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a0cb1  8d4c2404                         lea    ecx,[esp+0x4]
0x4a0cb5  89442404                         mov    DWORD PTR [esp+0x4],eax
0x4a0cb9  51                               push   ecx
0x4a0cba  8d44240c                         lea    eax,[esp+0xc]
0x4a0cbe  b938b1fa00                       mov    ecx,0xfab138
0x4a0cc3  e838e23800                       call   0x82ef00
0x4a0cc8  8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x4a0ccc  3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
0x4a0cd2  7429                             je     0x4a0cfd
0x4a0cd4  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4a0cd7  85c0                             test   eax,eax
0x4a0cd9  7422                             je     0x4a0cfd
0x4a0cdb  8b885c010000                     mov    ecx,DWORD PTR [eax+0x15c]
0x4a0ce1  85c9                             test   ecx,ecx
0x4a0ce3  7418                             je     0x4a0cfd
0x4a0ce5  83b87003000000                   cmp    DWORD PTR [eax+0x370],0x0
0x4a0cec  740f                             je     0x4a0cfd
0x4a0cee  0fb7550c                         movzx  edx,WORD PTR [ebp+0xc]
0x4a0cf2  6a00                             push   0x0
0x4a0cf4  6a00                             push   0x0
0x4a0cf6  52                               push   edx
0x4a0cf7  51                               push   ecx
0x4a0cf8  e843653000                       call   0x7a7240
0x4a0cfd  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4a0d01  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a0d08  59                               pop    ecx
0x4a0d09  8be5                             mov    esp,ebp
0x4a0d0b  5d                               pop    ebp
0x4a0d0c  c20800                           ret    0x8
0x4a0d0f  cc                               int3

; lb_detach | DWORD world key; DWORD render attachment key
; VA 0x4a0d10..0x4a0dd0 raw 0xa0110 length 192 sha256 51829301cd801c0417ad95e912309be40d161617de406c6b96d7ba7b5b82aa62
0x4a0d10  55                               push   ebp
0x4a0d11  8bec                             mov    ebp,esp
0x4a0d13  83e4f8                           and    esp,0xfffffff8
0x4a0d16  6aff                             push   0xffffffff
0x4a0d18  68fe6e9300                       push   0x936efe
0x4a0d1d  64a100000000                     mov    eax,fs:0x0
0x4a0d23  50                               push   eax
0x4a0d24  83ec0c                           sub    esp,0xc
0x4a0d27  a1201fd600                       mov    eax,ds:0xd61f20
0x4a0d2c  33c4                             xor    eax,esp
0x4a0d2e  50                               push   eax
0x4a0d2f  8d442410                         lea    eax,[esp+0x10]
0x4a0d33  64a300000000                     mov    fs:0x0,eax
0x4a0d39  b801000000                       mov    eax,0x1
0x4a0d3e  84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
0x4a0d44  7528                             jne    0x4a0d6e
0x4a0d46  09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
0x4a0d4c  c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
0x4a0d54  e837df0300                       call   0x4dec90
0x4a0d59  6830cebc00                       push   0xbcce30
0x4a0d5e  e8b7153f00                       call   0x89231a
0x4a0d63  83c404                           add    esp,0x4
0x4a0d66  c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x4a0d6e  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a0d71  8d4c2404                         lea    ecx,[esp+0x4]
0x4a0d75  89442404                         mov    DWORD PTR [esp+0x4],eax
0x4a0d79  51                               push   ecx
0x4a0d7a  8d44240c                         lea    eax,[esp+0xc]
0x4a0d7e  b938b1fa00                       mov    ecx,0xfab138
0x4a0d83  e878e13800                       call   0x82ef00
0x4a0d88  8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x4a0d8c  3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
0x4a0d92  7424                             je     0x4a0db8
0x4a0d94  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4a0d97  85c0                             test   eax,eax
0x4a0d99  741d                             je     0x4a0db8
0x4a0d9b  8b885c010000                     mov    ecx,DWORD PTR [eax+0x15c]
0x4a0da1  85c9                             test   ecx,ecx
0x4a0da3  7413                             je     0x4a0db8
0x4a0da5  83b87003000000                   cmp    DWORD PTR [eax+0x370],0x0
0x4a0dac  740a                             je     0x4a0db8
0x4a0dae  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x4a0db1  52                               push   edx
0x4a0db2  51                               push   ecx
0x4a0db3  e868683000                       call   0x7a7620
0x4a0db8  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4a0dbc  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a0dc3  59                               pop    ecx
0x4a0dc4  8be5                             mov    esp,ebp
0x4a0dc6  5d                               pop    ebp
0x4a0dc7  c20800                           ret    0x8
0x4a0dca  cc                               int3
0x4a0dcb  cc                               int3
0x4a0dcc  cc                               int3
0x4a0dcd  cc                               int3
0x4a0dce  cc                               int3
0x4a0dcf  cc                               int3

; lb_create_marshaller | exact four numeric arguments
; VA 0x4a2460..0x4a25f0 raw 0xa1860 length 400 sha256 f00bc3a0323c588b254cc570a0bc8744d07f97cdd8bb9b6a0da7f1f072e5454c
0x4a2460  55                               push   ebp
0x4a2461  8bec                             mov    ebp,esp
0x4a2463  83ec34                           sub    esp,0x34
0x4a2466  a18817fe00                       mov    eax,ds:0xfe1788
0x4a246b  8b0d7817fe00                     mov    ecx,DWORD PTR ds:0xfe1778
0x4a2471  53                               push   ebx
0x4a2472  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4a2475  56                               push   esi
0x4a2476  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4a2479  894df0                           mov    DWORD PTR [ebp-0x10],ecx
0x4a247c  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a247e  57                               push   edi
0x4a247f  83c8ff                           or     eax,0xffffffff
0x4a2482  e8692c2500                       call   0x6f50f0
0x4a2487  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a248a  83f903                           cmp    ecx,0x3
0x4a248d  742e                             je     0x4a24bd
0x4a248f  83f904                           cmp    ecx,0x4
0x4a2492  0f8534010000                     jne    0x4a25cc
0x4a2498  8b30                             mov    esi,DWORD PTR [eax]
0x4a249a  83c610                           add    esi,0x10
0x4a249d  8d7ddc                           lea    edi,[ebp-0x24]
0x4a24a0  e8bb522500                       call   0x6f7760
0x4a24a5  85c0                             test   eax,eax
0x4a24a7  0f841f010000                     je     0x4a25cc
0x4a24ad  dd45dc                           fld    QWORD PTR [ebp-0x24]
0x4a24b0  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
0x4a24b7  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0x4a24ba  8d45cc                           lea    eax,[ebp-0x34]
0x4a24bd  dd00                             fld    QWORD PTR [eax]
0x4a24bf  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0x4a24c2  dd45dc                           fld    QWORD PTR [ebp-0x24]
0x4a24c5  db5d08                           fistp  DWORD PTR [ebp+0x8]
0x4a24c8  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x4a24cb  8955f4                           mov    DWORD PTR [ebp-0xc],edx
0x4a24ce  8b03                             mov    eax,DWORD PTR [ebx]
0x4a24d0  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a24d3  8b48e8                           mov    ecx,DWORD PTR [eax-0x18]
0x4a24d6  83e820                           sub    eax,0x20
0x4a24d9  83f903                           cmp    ecx,0x3
0x4a24dc  742e                             je     0x4a250c
0x4a24de  83f904                           cmp    ecx,0x4
0x4a24e1  0f85f1000000                     jne    0x4a25d8
0x4a24e7  8b30                             mov    esi,DWORD PTR [eax]
0x4a24e9  83c610                           add    esi,0x10
0x4a24ec  8d7ddc                           lea    edi,[ebp-0x24]
0x4a24ef  e86c522500                       call   0x6f7760
0x4a24f4  85c0                             test   eax,eax
0x4a24f6  0f84dc000000                     je     0x4a25d8
0x4a24fc  dd45dc                           fld    QWORD PTR [ebp-0x24]
0x4a24ff  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
0x4a2506  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0x4a2509  8d45cc                           lea    eax,[ebp-0x34]
0x4a250c  dd00                             fld    QWORD PTR [eax]
0x4a250e  8b03                             mov    eax,DWORD PTR [ebx]
0x4a2510  dd5de4                           fstp   QWORD PTR [ebp-0x1c]
0x4a2513  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a2516  8b48d8                           mov    ecx,DWORD PTR [eax-0x28]
0x4a2519  83e830                           sub    eax,0x30
0x4a251c  83f903                           cmp    ecx,0x3
0x4a251f  742e                             je     0x4a254f
0x4a2521  83f904                           cmp    ecx,0x4
0x4a2524  0f85b5000000                     jne    0x4a25df
0x4a252a  8b30                             mov    esi,DWORD PTR [eax]
0x4a252c  83c610                           add    esi,0x10
0x4a252f  8d7ddc                           lea    edi,[ebp-0x24]
0x4a2532  e829522500                       call   0x6f7760
0x4a2537  85c0                             test   eax,eax
0x4a2539  0f84a0000000                     je     0x4a25df
0x4a253f  dd45dc                           fld    QWORD PTR [ebp-0x24]
0x4a2542  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
0x4a2549  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0x4a254c  8d45cc                           lea    eax,[ebp-0x34]
0x4a254f  dd00                             fld    QWORD PTR [eax]
0x4a2551  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a2553  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0x4a2556  b8fcffffff                       mov    eax,0xfffffffc
0x4a255b  e8902b2500                       call   0x6f50f0
0x4a2560  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a2563  83f903                           cmp    ecx,0x3
0x4a2566  7426                             je     0x4a258e
0x4a2568  83f904                           cmp    ecx,0x4
0x4a256b  7579                             jne    0x4a25e6
0x4a256d  8b30                             mov    esi,DWORD PTR [eax]
0x4a256f  83c610                           add    esi,0x10
0x4a2572  8d7df8                           lea    edi,[ebp-0x8]
0x4a2575  e8e6512500                       call   0x6f7760
0x4a257a  85c0                             test   eax,eax
0x4a257c  7468                             je     0x4a25e6
0x4a257e  dd45f8                           fld    QWORD PTR [ebp-0x8]
0x4a2581  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
0x4a2588  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0x4a258b  8d45cc                           lea    eax,[ebp-0x34]
0x4a258e  dd00                             fld    QWORD PTR [eax]
0x4a2590  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0x4a2593  dd45d4                           fld    QWORD PTR [ebp-0x2c]
0x4a2596  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x4a2599  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4a259c  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4a259f  dd45e4                           fld    QWORD PTR [ebp-0x1c]
0x4a25a2  d95df4                           fstp   DWORD PTR [ebp-0xc]
0x4a25a5  51                               push   ecx
0x4a25a6  d945f4                           fld    DWORD PTR [ebp-0xc]
0x4a25a9  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x4a25ac  83ec08                           sub    esp,0x8
0x4a25af  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4a25b3  dd45dc                           fld    QWORD PTR [ebp-0x24]
0x4a25b6  d95df4                           fstp   DWORD PTR [ebp-0xc]
0x4a25b9  d945f4                           fld    DWORD PTR [ebp-0xc]
0x4a25bc  d91c24                           fstp   DWORD PTR [esp]
0x4a25bf  50                               push   eax
0x4a25c0  ff55ec                           call   DWORD PTR [ebp-0x14]
0x4a25c3  5f                               pop    edi
0x4a25c4  5e                               pop    esi
0x4a25c5  33c0                             xor    eax,eax
0x4a25c7  5b                               pop    ebx
0x4a25c8  8be5                             mov    esp,ebp
0x4a25ca  5d                               pop    ebp
0x4a25cb  c3                               ret
0x4a25cc  c745f400000000                   mov    DWORD PTR [ebp-0xc],0x0
0x4a25d3  e9f6feffff                       jmp    0x4a24ce
0x4a25d8  d9ee                             fldz
0x4a25da  e92fffffff                       jmp    0x4a250e
0x4a25df  d9ee                             fldz
0x4a25e1  e96bffffff                       jmp    0x4a2551
0x4a25e6  33c0                             xor    eax,eax
0x4a25e8  ebb2                             jmp    0x4a259c
0x4a25ea  cc                               int3
0x4a25eb  cc                               int3
0x4a25ec  cc                               int3
0x4a25ed  cc                               int3
0x4a25ee  cc                               int3
0x4a25ef  cc                               int3

; lb_create_ex_marshaller | exact six numeric arguments
; VA 0x4a25f0..0x4a2850 raw 0xa19f0 length 608 sha256 c525b7665afcd142aa7a50f450bf25a7b77818db558151d4a2d0aeb83423c9f1
0x4a25f0  55                               push   ebp
0x4a25f1  8bec                             mov    ebp,esp
0x4a25f3  83ec44                           sub    esp,0x44
0x4a25f6  a18c17fe00                       mov    eax,ds:0xfe178c
0x4a25fb  8b0d7817fe00                     mov    ecx,DWORD PTR ds:0xfe1778
0x4a2601  53                               push   ebx
0x4a2602  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4a2605  56                               push   esi
0x4a2606  8945dc                           mov    DWORD PTR [ebp-0x24],eax
0x4a2609  894de0                           mov    DWORD PTR [ebp-0x20],ecx
0x4a260c  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a260e  57                               push   edi
0x4a260f  83c8ff                           or     eax,0xffffffff
0x4a2612  e8d92a2500                       call   0x6f50f0
0x4a2617  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a261a  83f903                           cmp    ecx,0x3
0x4a261d  742e                             je     0x4a264d
0x4a261f  83f904                           cmp    ecx,0x4
0x4a2622  0f85ea010000                     jne    0x4a2812
0x4a2628  8b30                             mov    esi,DWORD PTR [eax]
0x4a262a  83c610                           add    esi,0x10
0x4a262d  8d7dcc                           lea    edi,[ebp-0x34]
0x4a2630  e82b512500                       call   0x6f7760
0x4a2635  85c0                             test   eax,eax
0x4a2637  0f84d5010000                     je     0x4a2812
0x4a263d  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a2640  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0x4a2647  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0x4a264a  8d45bc                           lea    eax,[ebp-0x44]
0x4a264d  dd00                             fld    QWORD PTR [eax]
0x4a264f  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0x4a2652  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a2655  db5d08                           fistp  DWORD PTR [ebp+0x8]
0x4a2658  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x4a265b  8955ec                           mov    DWORD PTR [ebp-0x14],edx
0x4a265e  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a2660  b8feffffff                       mov    eax,0xfffffffe
0x4a2665  e8862a2500                       call   0x6f50f0
0x4a266a  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a266d  83f903                           cmp    ecx,0x3
0x4a2670  742e                             je     0x4a26a0
0x4a2672  83f904                           cmp    ecx,0x4
0x4a2675  0f85a3010000                     jne    0x4a281e
0x4a267b  8b30                             mov    esi,DWORD PTR [eax]
0x4a267d  83c610                           add    esi,0x10
0x4a2680  8d7dcc                           lea    edi,[ebp-0x34]
0x4a2683  e8d8502500                       call   0x6f7760
0x4a2688  85c0                             test   eax,eax
0x4a268a  0f848e010000                     je     0x4a281e
0x4a2690  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a2693  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0x4a269a  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0x4a269d  8d45bc                           lea    eax,[ebp-0x44]
0x4a26a0  dd00                             fld    QWORD PTR [eax]
0x4a26a2  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0x4a26a5  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a26a8  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x4a26ab  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4a26ae  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4a26b1  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a26b3  b8fdffffff                       mov    eax,0xfffffffd
0x4a26b8  e8332a2500                       call   0x6f50f0
0x4a26bd  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a26c0  83f903                           cmp    ecx,0x3
0x4a26c3  742e                             je     0x4a26f3
0x4a26c5  83f904                           cmp    ecx,0x4
0x4a26c8  0f855c010000                     jne    0x4a282a
0x4a26ce  8b30                             mov    esi,DWORD PTR [eax]
0x4a26d0  83c610                           add    esi,0x10
0x4a26d3  8d7dcc                           lea    edi,[ebp-0x34]
0x4a26d6  e885502500                       call   0x6f7760
0x4a26db  85c0                             test   eax,eax
0x4a26dd  0f8447010000                     je     0x4a282a
0x4a26e3  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a26e6  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0x4a26ed  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0x4a26f0  8d45bc                           lea    eax,[ebp-0x44]
0x4a26f3  dd00                             fld    QWORD PTR [eax]
0x4a26f5  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0x4a26f8  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a26fb  db5df8                           fistp  DWORD PTR [ebp-0x8]
0x4a26fe  8b4df8                           mov    ecx,DWORD PTR [ebp-0x8]
0x4a2701  894de4                           mov    DWORD PTR [ebp-0x1c],ecx
0x4a2704  8b03                             mov    eax,DWORD PTR [ebx]
0x4a2706  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a2709  8b48c8                           mov    ecx,DWORD PTR [eax-0x38]
0x4a270c  83e840                           sub    eax,0x40
0x4a270f  83f903                           cmp    ecx,0x3
0x4a2712  742e                             je     0x4a2742
0x4a2714  83f904                           cmp    ecx,0x4
0x4a2717  0f8519010000                     jne    0x4a2836
0x4a271d  8b30                             mov    esi,DWORD PTR [eax]
0x4a271f  83c610                           add    esi,0x10
0x4a2722  8d7dcc                           lea    edi,[ebp-0x34]
0x4a2725  e836502500                       call   0x6f7760
0x4a272a  85c0                             test   eax,eax
0x4a272c  0f8404010000                     je     0x4a2836
0x4a2732  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a2735  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0x4a273c  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0x4a273f  8d45bc                           lea    eax,[ebp-0x44]
0x4a2742  dd00                             fld    QWORD PTR [eax]
0x4a2744  8b03                             mov    eax,DWORD PTR [ebx]
0x4a2746  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0x4a2749  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a274c  8b48b8                           mov    ecx,DWORD PTR [eax-0x48]
0x4a274f  83e850                           sub    eax,0x50
0x4a2752  83f903                           cmp    ecx,0x3
0x4a2755  742e                             je     0x4a2785
0x4a2757  83f904                           cmp    ecx,0x4
0x4a275a  0f85dd000000                     jne    0x4a283d
0x4a2760  8b30                             mov    esi,DWORD PTR [eax]
0x4a2762  83c610                           add    esi,0x10
0x4a2765  8d7dcc                           lea    edi,[ebp-0x34]
0x4a2768  e8f34f2500                       call   0x6f7760
0x4a276d  85c0                             test   eax,eax
0x4a276f  0f84c8000000                     je     0x4a283d
0x4a2775  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a2778  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0x4a277f  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0x4a2782  8d45bc                           lea    eax,[ebp-0x44]
0x4a2785  dd00                             fld    QWORD PTR [eax]
0x4a2787  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a2789  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0x4a278c  b8faffffff                       mov    eax,0xfffffffa
0x4a2791  e85a292500                       call   0x6f50f0
0x4a2796  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a2799  83f903                           cmp    ecx,0x3
0x4a279c  742e                             je     0x4a27cc
0x4a279e  83f904                           cmp    ecx,0x4
0x4a27a1  0f859d000000                     jne    0x4a2844
0x4a27a7  8b30                             mov    esi,DWORD PTR [eax]
0x4a27a9  83c610                           add    esi,0x10
0x4a27ac  8d7df0                           lea    edi,[ebp-0x10]
0x4a27af  e8ac4f2500                       call   0x6f7760
0x4a27b4  85c0                             test   eax,eax
0x4a27b6  0f8488000000                     je     0x4a2844
0x4a27bc  dd45f0                           fld    QWORD PTR [ebp-0x10]
0x4a27bf  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0x4a27c6  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0x4a27c9  8d45bc                           lea    eax,[ebp-0x44]
0x4a27cc  dd00                             fld    QWORD PTR [eax]
0x4a27ce  dd5dc4                           fstp   QWORD PTR [ebp-0x3c]
0x4a27d1  dd45c4                           fld    QWORD PTR [ebp-0x3c]
0x4a27d4  db5df4                           fistp  DWORD PTR [ebp-0xc]
0x4a27d7  8b45f4                           mov    eax,DWORD PTR [ebp-0xc]
0x4a27da  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
0x4a27dd  dd45d4                           fld    QWORD PTR [ebp-0x2c]
0x4a27e0  8b4de8                           mov    ecx,DWORD PTR [ebp-0x18]
0x4a27e3  52                               push   edx
0x4a27e4  8b55e4                           mov    edx,DWORD PTR [ebp-0x1c]
0x4a27e7  d95de4                           fstp   DWORD PTR [ebp-0x1c]
0x4a27ea  d945e4                           fld    DWORD PTR [ebp-0x1c]
0x4a27ed  51                               push   ecx
0x4a27ee  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
0x4a27f1  52                               push   edx
0x4a27f2  83ec08                           sub    esp,0x8
0x4a27f5  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4a27f9  dd45cc                           fld    QWORD PTR [ebp-0x34]
0x4a27fc  d95de4                           fstp   DWORD PTR [ebp-0x1c]
0x4a27ff  d945e4                           fld    DWORD PTR [ebp-0x1c]
0x4a2802  d91c24                           fstp   DWORD PTR [esp]
0x4a2805  50                               push   eax
0x4a2806  ff55dc                           call   DWORD PTR [ebp-0x24]
0x4a2809  5f                               pop    edi
0x4a280a  5e                               pop    esi
0x4a280b  33c0                             xor    eax,eax
0x4a280d  5b                               pop    ebx
0x4a280e  8be5                             mov    esp,ebp
0x4a2810  5d                               pop    ebp
0x4a2811  c3                               ret
0x4a2812  c745ec00000000                   mov    DWORD PTR [ebp-0x14],0x0
0x4a2819  e940feffff                       jmp    0x4a265e
0x4a281e  c745e800000000                   mov    DWORD PTR [ebp-0x18],0x0
0x4a2825  e987feffff                       jmp    0x4a26b1
0x4a282a  c745e400000000                   mov    DWORD PTR [ebp-0x1c],0x0
0x4a2831  e9cefeffff                       jmp    0x4a2704
0x4a2836  d9ee                             fldz
0x4a2838  e907ffffff                       jmp    0x4a2744
0x4a283d  d9ee                             fldz
0x4a283f  e943ffffff                       jmp    0x4a2787
0x4a2844  33c0                             xor    eax,eax
0x4a2846  eb92                             jmp    0x4a27da
0x4a2848  cc                               int3
0x4a2849  cc                               int3
0x4a284a  cc                               int3
0x4a284b  cc                               int3
0x4a284c  cc                               int3
0x4a284d  cc                               int3
0x4a284e  cc                               int3
0x4a284f  cc                               int3

; lb_avatar_marshaller | three integer numeric conversions
; VA 0x4a2850..0x4a2990 raw 0xa1c50 length 320 sha256 0d10dd69dcb81c33493f90d005cc0be5a5935611d5e7024187812ba55400a974
0x4a2850  55                               push   ebp
0x4a2851  8bec                             mov    ebp,esp
0x4a2853  83ec2c                           sub    esp,0x2c
0x4a2856  a17817fe00                       mov    eax,ds:0xfe1778
0x4a285b  53                               push   ebx
0x4a285c  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4a285f  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a2861  56                               push   esi
0x4a2862  8945e4                           mov    DWORD PTR [ebp-0x1c],eax
0x4a2865  57                               push   edi
0x4a2866  83c8ff                           or     eax,0xffffffff
0x4a2869  e882282500                       call   0x6f50f0
0x4a286e  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a2871  83f903                           cmp    ecx,0x3
0x4a2874  742e                             je     0x4a28a4
0x4a2876  83f904                           cmp    ecx,0x4
0x4a2879  0f85e9000000                     jne    0x4a2968
0x4a287f  8b30                             mov    esi,DWORD PTR [eax]
0x4a2881  83c610                           add    esi,0x10
0x4a2884  8d7de8                           lea    edi,[ebp-0x18]
0x4a2887  e8d44e2500                       call   0x6f7760
0x4a288c  85c0                             test   eax,eax
0x4a288e  0f84d4000000                     je     0x4a2968
0x4a2894  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x4a2897  c745dc03000000                   mov    DWORD PTR [ebp-0x24],0x3
0x4a289e  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0x4a28a1  8d45d4                           lea    eax,[ebp-0x2c]
0x4a28a4  dd00                             fld    QWORD PTR [eax]
0x4a28a6  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x4a28a9  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x4a28ac  db5d08                           fistp  DWORD PTR [ebp+0x8]
0x4a28af  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4a28b2  894df0                           mov    DWORD PTR [ebp-0x10],ecx
0x4a28b5  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a28b7  b8feffffff                       mov    eax,0xfffffffe
0x4a28bc  e82f282500                       call   0x6f50f0
0x4a28c1  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a28c4  83f903                           cmp    ecx,0x3
0x4a28c7  742e                             je     0x4a28f7
0x4a28c9  83f904                           cmp    ecx,0x4
0x4a28cc  0f85a2000000                     jne    0x4a2974
0x4a28d2  8b30                             mov    esi,DWORD PTR [eax]
0x4a28d4  83c610                           add    esi,0x10
0x4a28d7  8d7de8                           lea    edi,[ebp-0x18]
0x4a28da  e8814e2500                       call   0x6f7760
0x4a28df  85c0                             test   eax,eax
0x4a28e1  0f848d000000                     je     0x4a2974
0x4a28e7  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x4a28ea  c745dc03000000                   mov    DWORD PTR [ebp-0x24],0x3
0x4a28f1  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0x4a28f4  8d45d4                           lea    eax,[ebp-0x2c]
0x4a28f7  dd00                             fld    QWORD PTR [eax]
0x4a28f9  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x4a28fc  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x4a28ff  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x4a2902  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x4a2905  8955ec                           mov    DWORD PTR [ebp-0x14],edx
0x4a2908  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a290a  b8fdffffff                       mov    eax,0xfffffffd
0x4a290f  e8dc272500                       call   0x6f50f0
0x4a2914  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a2917  83f903                           cmp    ecx,0x3
0x4a291a  7426                             je     0x4a2942
0x4a291c  83f904                           cmp    ecx,0x4
0x4a291f  755c                             jne    0x4a297d
0x4a2921  8b30                             mov    esi,DWORD PTR [eax]
0x4a2923  83c610                           add    esi,0x10
0x4a2926  8d7df4                           lea    edi,[ebp-0xc]
0x4a2929  e8324e2500                       call   0x6f7760
0x4a292e  85c0                             test   eax,eax
0x4a2930  744b                             je     0x4a297d
0x4a2932  dd45f4                           fld    QWORD PTR [ebp-0xc]
0x4a2935  c745dc03000000                   mov    DWORD PTR [ebp-0x24],0x3
0x4a293c  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0x4a293f  8d45d4                           lea    eax,[ebp-0x2c]
0x4a2942  dd00                             fld    QWORD PTR [eax]
0x4a2944  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0x4a2947  dd45dc                           fld    QWORD PTR [ebp-0x24]
0x4a294a  db5df8                           fistp  DWORD PTR [ebp-0x8]
0x4a294d  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0x4a2950  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x4a2953  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
0x4a2956  51                               push   ecx
0x4a2957  8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
0x4a295a  52                               push   edx
0x4a295b  50                               push   eax
0x4a295c  ff550c                           call   DWORD PTR [ebp+0xc]
0x4a295f  5f                               pop    edi
0x4a2960  5e                               pop    esi
0x4a2961  33c0                             xor    eax,eax
0x4a2963  5b                               pop    ebx
0x4a2964  8be5                             mov    esp,ebp
0x4a2966  5d                               pop    ebp
0x4a2967  c3                               ret
0x4a2968  c745f000000000                   mov    DWORD PTR [ebp-0x10],0x0
0x4a296f  e941ffffff                       jmp    0x4a28b5
0x4a2974  c745ec00000000                   mov    DWORD PTR [ebp-0x14],0x0
0x4a297b  eb8b                             jmp    0x4a2908
0x4a297d  33c0                             xor    eax,eax
0x4a297f  ebcf                             jmp    0x4a2950
0x4a2981  cc                               int3
0x4a2982  cc                               int3
0x4a2983  cc                               int3
0x4a2984  cc                               int3
0x4a2985  cc                               int3
0x4a2986  cc                               int3
0x4a2987  cc                               int3
0x4a2988  cc                               int3
0x4a2989  cc                               int3
0x4a298a  cc                               int3
0x4a298b  cc                               int3
0x4a298c  cc                               int3
0x4a298d  cc                               int3
0x4a298e  cc                               int3
0x4a298f  cc                               int3

; lb_item_marshaller | two integer numeric conversions
; VA 0x4a2990..0x4a2a70 raw 0xa1d90 length 224 sha256 ddaf14a913c4262307e3b61182f9f3cf396bf449859d48d92efb4f8537e506e9
0x4a2990  55                               push   ebp
0x4a2991  8bec                             mov    ebp,esp
0x4a2993  83ec24                           sub    esp,0x24
0x4a2996  a17817fe00                       mov    eax,ds:0xfe1778
0x4a299b  53                               push   ebx
0x4a299c  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4a299f  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a29a1  56                               push   esi
0x4a29a2  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4a29a5  57                               push   edi
0x4a29a6  83c8ff                           or     eax,0xffffffff
0x4a29a9  e842272500                       call   0x6f50f0
0x4a29ae  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a29b1  83f903                           cmp    ecx,0x3
0x4a29b4  742a                             je     0x4a29e0
0x4a29b6  83f904                           cmp    ecx,0x4
0x4a29b9  0f858e000000                     jne    0x4a2a4d
0x4a29bf  8b30                             mov    esi,DWORD PTR [eax]
0x4a29c1  83c610                           add    esi,0x10
0x4a29c4  8d7df0                           lea    edi,[ebp-0x10]
0x4a29c7  e8944d2500                       call   0x6f7760
0x4a29cc  85c0                             test   eax,eax
0x4a29ce  747d                             je     0x4a2a4d
0x4a29d0  dd45f0                           fld    QWORD PTR [ebp-0x10]
0x4a29d3  c745e403000000                   mov    DWORD PTR [ebp-0x1c],0x3
0x4a29da  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0x4a29dd  8d45dc                           lea    eax,[ebp-0x24]
0x4a29e0  dd00                             fld    QWORD PTR [eax]
0x4a29e2  dd5df0                           fstp   QWORD PTR [ebp-0x10]
0x4a29e5  dd45f0                           fld    QWORD PTR [ebp-0x10]
0x4a29e8  db5d08                           fistp  DWORD PTR [ebp+0x8]
0x4a29eb  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4a29ee  894df4                           mov    DWORD PTR [ebp-0xc],ecx
0x4a29f1  8b0b                             mov    ecx,DWORD PTR [ebx]
0x4a29f3  b8feffffff                       mov    eax,0xfffffffe
0x4a29f8  e8f3262500                       call   0x6f50f0
0x4a29fd  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a2a00  83f903                           cmp    ecx,0x3
0x4a2a03  7426                             je     0x4a2a2b
0x4a2a05  83f904                           cmp    ecx,0x4
0x4a2a08  754c                             jne    0x4a2a56
0x4a2a0a  8b30                             mov    esi,DWORD PTR [eax]
0x4a2a0c  83c610                           add    esi,0x10
0x4a2a0f  8d7df8                           lea    edi,[ebp-0x8]
0x4a2a12  e8494d2500                       call   0x6f7760
0x4a2a17  85c0                             test   eax,eax
0x4a2a19  743b                             je     0x4a2a56
0x4a2a1b  dd45f8                           fld    QWORD PTR [ebp-0x8]
0x4a2a1e  c745e403000000                   mov    DWORD PTR [ebp-0x1c],0x3
0x4a2a25  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0x4a2a28  8d45dc                           lea    eax,[ebp-0x24]
0x4a2a2b  dd00                             fld    QWORD PTR [eax]
0x4a2a2d  dd5de4                           fstp   QWORD PTR [ebp-0x1c]
0x4a2a30  dd45e4                           fld    QWORD PTR [ebp-0x1c]
0x4a2a33  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x4a2a36  8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
0x4a2a39  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4a2a3c  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0x4a2a3f  52                               push   edx
0x4a2a40  50                               push   eax
0x4a2a41  ff550c                           call   DWORD PTR [ebp+0xc]
0x4a2a44  5f                               pop    edi
0x4a2a45  5e                               pop    esi
0x4a2a46  33c0                             xor    eax,eax
0x4a2a48  5b                               pop    ebx
0x4a2a49  8be5                             mov    esp,ebp
0x4a2a4b  5d                               pop    ebp
0x4a2a4c  c3                               ret
0x4a2a4d  c745f400000000                   mov    DWORD PTR [ebp-0xc],0x0
0x4a2a54  eb9b                             jmp    0x4a29f1
0x4a2a56  8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
0x4a2a59  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0x4a2a5c  33c0                             xor    eax,eax
0x4a2a5e  52                               push   edx
0x4a2a5f  50                               push   eax
0x4a2a60  ff550c                           call   DWORD PTR [ebp+0xc]
0x4a2a63  5f                               pop    edi
0x4a2a64  5e                               pop    esi
0x4a2a65  33c0                             xor    eax,eax
0x4a2a67  5b                               pop    ebx
0x4a2a68  8be5                             mov    esp,ebp
0x4a2a6a  5d                               pop    ebp
0x4a2a6b  c3                               ret
0x4a2a6c  cc                               int3
0x4a2a6d  cc                               int3
0x4a2a6e  cc                               int3
0x4a2a6f  cc                               int3

; npc_ctor | CNPC concrete type and base constructor
; VA 0x4d2120..0x4d2280 raw 0xd1520 length 352 sha256 5e200bf432911139aeca6bf58709fe50a85b5581584b95db7b23fbada287a9c9
0x4d2120  55                               push   ebp
0x4d2121  8bec                             mov    ebp,esp
0x4d2123  6aff                             push   0xffffffff
0x4d2125  686e089100                       push   0x91086e
0x4d212a  64a100000000                     mov    eax,fs:0x0
0x4d2130  50                               push   eax
0x4d2131  51                               push   ecx
0x4d2132  53                               push   ebx
0x4d2133  56                               push   esi
0x4d2134  57                               push   edi
0x4d2135  a1201fd600                       mov    eax,ds:0xd61f20
0x4d213a  33c5                             xor    eax,ebp
0x4d213c  50                               push   eax
0x4d213d  8d45f4                           lea    eax,[ebp-0xc]
0x4d2140  64a300000000                     mov    fs:0x0,eax
0x4d2146  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x4d2149  57                               push   edi
0x4d214a  e8214fffff                       call   0x4c7070
0x4d214f  33db                             xor    ebx,ebx
0x4d2151  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4d2154  0f57c0                           xorps  xmm0,xmm0
0x4d2157  6a3c                             push   0x3c
0x4d2159  c7079ccac000                     mov    DWORD PTR [edi],0xc0ca9c
0x4d215f  c787f000000024cbc000             mov    DWORD PTR [edi+0xf0],0xc0cb24
0x4d2169  899f20040000                     mov    DWORD PTR [edi+0x420],ebx
0x4d216f  c78724040000ffffffff             mov    DWORD PTR [edi+0x424],0xffffffff
0x4d2179  f30f118728040000                 movss  DWORD PTR [edi+0x428],xmm0
0x4d2181  e8e2f03b00                       call   0x891268
0x4d2186  8bf0                             mov    esi,eax
0x4d2188  83c404                           add    esp,0x4
0x4d218b  8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4d218e  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x4d2192  3bf3                             cmp    esi,ebx
0x4d2194  7419                             je     0x4d21af
0x4d2196  8bc7                             mov    eax,edi
0x4d2198  8d4b03                           lea    ecx,[ebx+0x3]
0x4d219b  e89090ffff                       call   0x4cb230
0x4d21a0  c706cc77c000                     mov    DWORD PTR [esi],0xc077cc
0x4d21a6  c7463401000000                   mov    DWORD PTR [esi+0x34],0x1
0x4d21ad  eb02                             jmp    0x4d21b1
0x4d21af  33f6                             xor    esi,esi
0x4d21b1  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x4d21b5  8b5e08                           mov    ebx,DWORD PTR [esi+0x8]
0x4d21b8  83bc9ff400000000                 cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
0x4d21c0  740d                             je     0x4d21cf
0x4d21c2  683c75c000                       push   0xc0753c
0x4d21c7  e894b92100                       call   0x6edb60
0x4d21cc  83c404                           add    esp,0x4
0x4d21cf  89b49ff4000000                   mov    DWORD PTR [edi+ebx*4+0xf4],esi
0x4d21d6  83bf5801000000                   cmp    DWORD PTR [edi+0x158],0x0
0x4d21dd  7506                             jne    0x4d21e5
0x4d21df  89b758010000                     mov    DWORD PTR [edi+0x158],esi
0x4d21e5  6a3c                             push   0x3c
0x4d21e7  e87cf03b00                       call   0x891268
0x4d21ec  8bf0                             mov    esi,eax
0x4d21ee  83c404                           add    esp,0x4
0x4d21f1  8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4d21f4  b902000000                       mov    ecx,0x2
0x4d21f9  884dfc                           mov    BYTE PTR [ebp-0x4],cl
0x4d21fc  85f6                             test   esi,esi
0x4d21fe  7424                             je     0x4d2224
0x4d2200  8bc7                             mov    eax,edi
0x4d2202  e82990ffff                       call   0x4cb230
0x4d2207  b801000000                       mov    eax,0x1
0x4d220c  894628                           mov    DWORD PTR [esi+0x28],eax
0x4d220f  89462c                           mov    DWORD PTR [esi+0x2c],eax
0x4d2212  894630                           mov    DWORD PTR [esi+0x30],eax
0x4d2215  c7068479c000                     mov    DWORD PTR [esi],0xc07984
0x4d221b  c7463800000000                   mov    DWORD PTR [esi+0x38],0x0
0x4d2222  eb02                             jmp    0x4d2226
0x4d2224  33f6                             xor    esi,esi
0x4d2226  8b5e08                           mov    ebx,DWORD PTR [esi+0x8]
0x4d2229  83bc9ff400000000                 cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
0x4d2231  740d                             je     0x4d2240
0x4d2233  683c75c000                       push   0xc0753c
0x4d2238  e823b92100                       call   0x6edb60
0x4d223d  83c404                           add    esp,0x4
0x4d2240  33c0                             xor    eax,eax
0x4d2242  89b49ff4000000                   mov    DWORD PTR [edi+ebx*4+0xf4],esi
0x4d2249  398758010000                     cmp    DWORD PTR [edi+0x158],eax
0x4d224f  7506                             jne    0x4d2257
0x4d2251  89b758010000                     mov    DWORD PTR [edi+0x158],esi
0x4d2257  89879c030000                     mov    DWORD PTR [edi+0x39c],eax
0x4d225d  8bc7                             mov    eax,edi
0x4d225f  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4d2262  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4d2269  59                               pop    ecx
0x4d226a  5f                               pop    edi
0x4d226b  5e                               pop    esi
0x4d226c  5b                               pop    ebx
0x4d226d  8be5                             mov    esp,ebp
0x4d226f  5d                               pop    ebp
0x4d2270  c20400                           ret    0x4
0x4d2273  cc                               int3
0x4d2274  cc                               int3
0x4d2275  cc                               int3
0x4d2276  cc                               int3
0x4d2277  cc                               int3
0x4d2278  cc                               int3
0x4d2279  cc                               int3
0x4d227a  cc                               int3
0x4d227b  cc                               int3
0x4d227c  cc                               int3
0x4d227d  cc                               int3
0x4d227e  cc                               int3
0x4d227f  cc                               int3

; npc_initialize_doll | CNPC v+30 ->4C7DF0 immediate=1, then quest marker update
; VA 0x4d2820..0x4d2840 raw 0xd1c20 length 32 sha256 70a06317cc0c219845164592fd4a56c8d0011bd36b9f7a6b3278f2bebb243e2b
0x4d2820  56                               push   esi
0x4d2821  57                               push   edi
0x4d2822  8bf1                             mov    esi,ecx
0x4d2824  6a01                             push   0x1
0x4d2826  56                               push   esi
0x4d2827  e8c455ffff                       call   0x4c7df0
0x4d282c  56                               push   esi
0x4d282d  8bf8                             mov    edi,eax
0x4d282f  e82cfbffff                       call   0x4d2360
0x4d2834  8bc7                             mov    eax,edi
0x4d2836  5f                               pop    edi
0x4d2837  5e                               pop    esi
0x4d2838  c3                               ret
0x4d2839  cc                               int3
0x4d283a  cc                               int3
0x4d283b  cc                               int3
0x4d283c  cc                               int3
0x4d283d  cc                               int3
0x4d283e  cc                               int3
0x4d283f  cc                               int3

; actor_model_id | packed model stored at +88/+8C
; VA 0x4c6fb0..0x4c6fd0 raw 0xc63b0 length 32 sha256 74bf7e0c3d5ff41cf31cb0089009d79c4ec72191745060987bdd0b0efa1a1053
0x4c6fb0  55                               push   ebp
0x4c6fb1  8bec                             mov    ebp,esp
0x4c6fb3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4c6fb6  898188000000                     mov    DWORD PTR [ecx+0x88],eax
0x4c6fbc  89818c000000                     mov    DWORD PTR [ecx+0x8c],eax
0x4c6fc2  5d                               pop    ebp
0x4c6fc3  c20400                           ret    0x4
0x4c6fc6  cc                               int3
0x4c6fc7  cc                               int3
0x4c6fc8  cc                               int3
0x4c6fc9  cc                               int3
0x4c6fca  cc                               int3
0x4c6fcb  cc                               int3
0x4c6fcc  cc                               int3
0x4c6fcd  cc                               int3
0x4c6fce  cc                               int3
0x4c6fcf  cc                               int3

; actor_initialize_doll_entry | v+30 invokes 4C7DF0 with immediate flag zero
; VA 0x4c8050..0x4c8060 raw 0xc7450 length 16 sha256 21d1dcc0e89b9cb2092cefdb5ec0088f266aeccac4a63156de3cf96a19a6a9db
0x4c8050  6a00                             push   0x0
0x4c8052  51                               push   ecx
0x4c8053  e898fdffff                       call   0x4c7df0
0x4c8058  c3                               ret
0x4c8059  cc                               int3
0x4c805a  cc                               int3
0x4c805b  cc                               int3
0x4c805c  cc                               int3
0x4c805d  cc                               int3
0x4c805e  cc                               int3
0x4c805f  cc                               int3

; actor_initialize_doll | allocate CDoll, connect +15C, initialize transform and motion
; VA 0x4c7df0..0x4c8050 raw 0xc71f0 length 608 sha256 12768229bfe6d5625163369f99f708d49ea68c525fb67a4d7bf7cb7882c54199
0x4c7df0  55                               push   ebp
0x4c7df1  8bec                             mov    ebp,esp
0x4c7df3  83e4f8                           and    esp,0xfffffff8
0x4c7df6  6aff                             push   0xffffffff
0x4c7df8  683e969300                       push   0x93963e
0x4c7dfd  64a100000000                     mov    eax,fs:0x0
0x4c7e03  50                               push   eax
0x4c7e04  83ec10                           sub    esp,0x10
0x4c7e07  53                               push   ebx
0x4c7e08  56                               push   esi
0x4c7e09  57                               push   edi
0x4c7e0a  a1201fd600                       mov    eax,ds:0xd61f20
0x4c7e0f  33c4                             xor    eax,esp
0x4c7e11  50                               push   eax
0x4c7e12  8d442420                         lea    eax,[esp+0x20]
0x4c7e16  64a300000000                     mov    fs:0x0,eax
0x4c7e1c  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4c7e1f  33ff                             xor    edi,edi
0x4c7e21  39bb70030000                     cmp    DWORD PTR [ebx+0x370],edi
0x4c7e27  0f8509020000                     jne    0x4c8036
0x4c7e2d  8b838c000000                     mov    eax,DWORD PTR [ebx+0x8c]
0x4c7e33  8bf0                             mov    esi,eax
0x4c7e35  3bc7                             cmp    eax,edi
0x4c7e37  7506                             jne    0x4c7e3f
0x4c7e39  8bb388000000                     mov    esi,DWORD PTR [ebx+0x88]
0x4c7e3f  6870010000                       push   0x170
0x4c7e44  e81f943c00                       call   0x891268
0x4c7e49  83c404                           add    esp,0x4
0x4c7e4c  89442414                         mov    DWORD PTR [esp+0x14],eax
0x4c7e50  897c2428                         mov    DWORD PTR [esp+0x28],edi
0x4c7e54  3bc7                             cmp    eax,edi
0x4c7e56  740c                             je     0x4c7e64
0x4c7e58  0fb7ce                           movzx  ecx,si
0x4c7e5b  51                               push   ecx
0x4c7e5c  50                               push   eax
0x4c7e5d  e8eecd2d00                       call   0x7a4c50
0x4c7e62  eb02                             jmp    0x4c7e66
0x4c7e64  33c0                             xor    eax,eax
0x4c7e66  50                               push   eax
0x4c7e67  8d542418                         lea    edx,[esp+0x18]
0x4c7e6b  83ceff                           or     esi,0xffffffff
0x4c7e6e  8974242c                         mov    DWORD PTR [esp+0x2c],esi
0x4c7e72  52                               push   edx
0x4c7e73  897c241c                         mov    DWORD PTR [esp+0x1c],edi
0x4c7e77  897c2420                         mov    DWORD PTR [esp+0x20],edi
0x4c7e7b  e8e0250000                       call   0x4ca460
0x4c7e80  8dbb5c010000                     lea    edi,[ebx+0x15c]
0x4c7e86  8d442414                         lea    eax,[esp+0x14]
0x4c7e8a  c744242801000000                 mov    DWORD PTR [esp+0x28],0x1
0x4c7e92  e8c9900100                       call   0x4e0f60
0x4c7e97  89742428                         mov    DWORD PTR [esp+0x28],esi
0x4c7e9b  8b742418                         mov    esi,DWORD PTR [esp+0x18]
0x4c7e9f  85f6                             test   esi,esi
0x4c7ea1  7429                             je     0x4c7ecc
0x4c7ea3  8d4604                           lea    eax,[esi+0x4]
0x4c7ea6  83c9ff                           or     ecx,0xffffffff
0x4c7ea9  f00fc108                         lock xadd DWORD PTR [eax],ecx
0x4c7ead  751d                             jne    0x4c7ecc
0x4c7eaf  8b16                             mov    edx,DWORD PTR [esi]
0x4c7eb1  8b02                             mov    eax,DWORD PTR [edx]
0x4c7eb3  8bce                             mov    ecx,esi
0x4c7eb5  ffd0                             call   eax
0x4c7eb7  8d4e08                           lea    ecx,[esi+0x8]
0x4c7eba  83caff                           or     edx,0xffffffff
0x4c7ebd  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x4c7ec1  7509                             jne    0x4c7ecc
0x4c7ec3  8b06                             mov    eax,DWORD PTR [esi]
0x4c7ec5  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4c7ec8  8bce                             mov    ecx,esi
0x4c7eca  ffd2                             call   edx
0x4c7ecc  0fb78b88030000                   movzx  ecx,WORD PTR [ebx+0x388]
0x4c7ed3  8b07                             mov    eax,DWORD PTR [edi]
0x4c7ed5  51                               push   ecx
0x4c7ed6  6a01                             push   0x1
0x4c7ed8  50                               push   eax
0x4c7ed9  e8c2ef2d00                       call   0x7a6ea0
0x4c7ede  807d0c00                         cmp    BYTE PTR [ebp+0xc],0x0
0x4c7ee2  740e                             je     0x4c7ef2
0x4c7ee4  8b07                             mov    eax,DWORD PTR [edi]
0x4c7ee6  c6402001                         mov    BYTE PTR [eax+0x20],0x1
0x4c7eea  8b07                             mov    eax,DWORD PTR [edi]
0x4c7eec  50                               push   eax
0x4c7eed  e87e0f2e00                       call   0x7a8e70
0x4c7ef2  8b13                             mov    edx,DWORD PTR [ebx]
0x4c7ef4  8b5244                           mov    edx,DWORD PTR [edx+0x44]
0x4c7ef7  6a01                             push   0x1
0x4c7ef9  8d83a0000000                     lea    eax,[ebx+0xa0]
0x4c7eff  50                               push   eax
0x4c7f00  8bcb                             mov    ecx,ebx
0x4c7f02  c7837003000001000000             mov    DWORD PTR [ebx+0x370],0x1
0x4c7f0c  ffd2                             call   edx
0x4c7f0e  0fb68bb0000000                   movzx  ecx,BYTE PTR [ebx+0xb0]
0x4c7f15  8b03                             mov    eax,DWORD PTR [ebx]
0x4c7f17  8b5058                           mov    edx,DWORD PTR [eax+0x58]
0x4c7f1a  51                               push   ecx
0x4c7f1b  8bcb                             mov    ecx,ebx
0x4c7f1d  ffd2                             call   edx
0x4c7f1f  83bba803000000                   cmp    DWORD PTR [ebx+0x3a8],0x0
0x4c7f26  8a83b0000000                     mov    al,BYTE PTR [ebx+0xb0]
0x4c7f2c  88442414                         mov    BYTE PTR [esp+0x14],al
0x4c7f30  752f                             jne    0x4c7f61
0x4c7f32  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
0x4c7f39  8883a4030000                     mov    BYTE PTR [ebx+0x3a4],al
0x4c7f3f  7420                             je     0x4c7f61
0x4c7f41  8b3f                             mov    edi,DWORD PTR [edi]
0x4c7f43  85ff                             test   edi,edi
0x4c7f45  741a                             je     0x4c7f61
0x4c7f47  8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x4c7f4b  8b7704                           mov    esi,DWORD PTR [edi+0x4]
0x4c7f4e  50                               push   eax
0x4c7f4f  e83ccbf7ff                       call   0x444a90
0x4c7f54  8b560c                           mov    edx,DWORD PTR [esi+0xc]
0x4c7f57  8d4f04                           lea    ecx,[edi+0x4]
0x4c7f5a  f30f110424                       movss  DWORD PTR [esp],xmm0
0x4c7f5f  ffd2                             call   edx
0x4c7f61  8b03                             mov    eax,DWORD PTR [ebx]
0x4c7f63  d983b4000000                     fld    DWORD PTR [ebx+0xb4]
0x4c7f69  8b505c                           mov    edx,DWORD PTR [eax+0x5c]
0x4c7f6c  51                               push   ecx
0x4c7f6d  8bcb                             mov    ecx,ebx
0x4c7f6f  d91c24                           fstp   DWORD PTR [esp]
0x4c7f72  ffd2                             call   edx
0x4c7f74  d9e8                             fld1
0x4c7f76  8b03                             mov    eax,DWORD PTR [ebx]
0x4c7f78  8b5068                           mov    edx,DWORD PTR [eax+0x68]
0x4c7f7b  51                               push   ecx
0x4c7f7c  8b8b8c030000                     mov    ecx,DWORD PTR [ebx+0x38c]
0x4c7f82  d91c24                           fstp   DWORD PTR [esp]
0x4c7f85  51                               push   ecx
0x4c7f86  8bcb                             mov    ecx,ebx
0x4c7f88  ffd2                             call   edx
0x4c7f8a  6a30                             push   0x30
0x4c7f8c  e8d7923c00                       call   0x891268
0x4c7f91  83c404                           add    esp,0x4
0x4c7f94  89442414                         mov    DWORD PTR [esp+0x14],eax
0x4c7f98  c744242802000000                 mov    DWORD PTR [esp+0x28],0x2
0x4c7fa0  85c0                             test   eax,eax
0x4c7fa2  7409                             je     0x4c7fad
0x4c7fa4  8bf0                             mov    esi,eax
0x4c7fa6  e855c02e00                       call   0x7b4000
0x4c7fab  eb02                             jmp    0x4c7faf
0x4c7fad  33c0                             xor    eax,eax
0x4c7faf  c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
0x4c7fb7  898368030000                     mov    DWORD PTR [ebx+0x368],eax
0x4c7fbd  c7402401000000                   mov    DWORD PTR [eax+0x24],0x1
0x4c7fc4  8b03                             mov    eax,DWORD PTR [ebx]
0x4c7fc6  8b504c                           mov    edx,DWORD PTR [eax+0x4c]
0x4c7fc9  8bcb                             mov    ecx,ebx
0x4c7fcb  ffd2                             call   edx
0x4c7fcd  8b08                             mov    ecx,DWORD PTR [eax]
0x4c7fcf  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4c7fd2  8b7808                           mov    edi,DWORD PTR [eax+0x8]
0x4c7fd5  8b8368030000                     mov    eax,DWORD PTR [ebx+0x368]
0x4c7fdb  f30f10058c5ac500                 movss  xmm0,DWORD PTR ds:0xc55a8c
0x4c7fe3  894810                           mov    DWORD PTR [eax+0x10],ecx
0x4c7fe6  895014                           mov    DWORD PTR [eax+0x14],edx
0x4c7fe9  897818                           mov    DWORD PTR [eax+0x18],edi
0x4c7fec  8b8368030000                     mov    eax,DWORD PTR [ebx+0x368]
0x4c7ff2  f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x4c7ff8  f30f10050858c500                 movss  xmm0,DWORD PTR ds:0xc55808
0x4c8000  8b4c2414                         mov    ecx,DWORD PTR [esp+0x14]
0x4c8004  f30f11442418                     movss  DWORD PTR [esp+0x18],xmm0
0x4c800a  8b542418                         mov    edx,DWORD PTR [esp+0x18]
0x4c800e  89481c                           mov    DWORD PTR [eax+0x1c],ecx
0x4c8011  895020                           mov    DWORD PTR [eax+0x20],edx
0x4c8014  8b9b68030000                     mov    ebx,DWORD PTR [ebx+0x368]
0x4c801a  53                               push   ebx
0x4c801b  8d442414                         lea    eax,[esp+0x14]
0x4c801f  c644241400                       mov    BYTE PTR [esp+0x14],0x0
0x4c8024  e8a7ce2e00                       call   0x7b4ed0
0x4c8029  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x4c8031  f30f11400c                       movss  DWORD PTR [eax+0xc],xmm0
0x4c8036  b801000000                       mov    eax,0x1
0x4c803b  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0x4c803f  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4c8046  59                               pop    ecx
0x4c8047  5f                               pop    edi
0x4c8048  5e                               pop    esi
0x4c8049  5b                               pop    ebx
0x4c804a  8be5                             mov    esp,ebp
0x4c804c  5d                               pop    ebp
0x4c804d  c20800                           ret    0x8

; doll_avatar | gated low WORD part/variant map mutation and dirty flag
; VA 0x7a6ea0..0x7a6fb0 raw 0x3a62a0 length 272 sha256 6a5f9aa0bfde8bd32b5cc8ead8210563fe5ba2dec891a7bcc8ead073bff4654f
0x7a6ea0  55                               push   ebp
0x7a6ea1  8bec                             mov    ebp,esp
0x7a6ea3  6aff                             push   0xffffffff
0x7a6ea5  685e919300                       push   0x93915e
0x7a6eaa  64a100000000                     mov    eax,fs:0x0
0x7a6eb0  50                               push   eax
0x7a6eb1  83ec08                           sub    esp,0x8
0x7a6eb4  53                               push   ebx
0x7a6eb5  56                               push   esi
0x7a6eb6  57                               push   edi
0x7a6eb7  a1201fd600                       mov    eax,ds:0xd61f20
0x7a6ebc  33c5                             xor    eax,ebp
0x7a6ebe  50                               push   eax
0x7a6ebf  8d45f4                           lea    eax,[ebp-0xc]
0x7a6ec2  64a300000000                     mov    fs:0x0,eax
0x7a6ec8  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a6ecb  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
0x7a6ed2  7527                             jne    0x7a6efb
0x7a6ed4  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
0x7a6edb  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x7a6ee2  e85960ffff                       call   0x79cf40
0x7a6ee7  6880dbbc00                       push   0xbcdb80
0x7a6eec  e829b40e00                       call   0x89231a
0x7a6ef1  83c404                           add    esp,0x4
0x7a6ef4  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x7a6efb  8b4318                           mov    eax,DWORD PTR [ebx+0x18]
0x7a6efe  8d4d08                           lea    ecx,[ebp+0x8]
0x7a6f01  894508                           mov    DWORD PTR [ebp+0x8],eax
0x7a6f04  51                               push   ecx
0x7a6f05  8d45f0                           lea    eax,[ebp-0x10]
0x7a6f08  b9900efc00                       mov    ecx,0xfc0e90
0x7a6f0d  e87ee8d6ff                       call   0x515790
0x7a6f12  8b45f0                           mov    eax,DWORD PTR [ebp-0x10]
0x7a6f15  3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
0x7a6f1b  7413                             je     0x7a6f30
0x7a6f1d  8b5010                           mov    edx,DWORD PTR [eax+0x10]
0x7a6f20  8b4254                           mov    eax,DWORD PTR [edx+0x54]
0x7a6f23  85c0                             test   eax,eax
0x7a6f25  7409                             je     0x7a6f30
0x7a6f27  83b8bc00000000                   cmp    DWORD PTR [eax+0xbc],0x0
0x7a6f2e  745f                             je     0x7a6f8f
0x7a6f30  8d450c                           lea    eax,[ebp+0xc]
0x7a6f33  50                               push   eax
0x7a6f34  8d4508                           lea    eax,[ebp+0x8]
0x7a6f37  8d4b4c                           lea    ecx,[ebx+0x4c]
0x7a6f3a  e8d19bffff                       call   0x7a0b10
0x7a6f3f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x7a6f42  3b4350                           cmp    eax,DWORD PTR [ebx+0x50]
0x7a6f45  740a                             je     0x7a6f51
0x7a6f47  668b4d10                         mov    cx,WORD PTR [ebp+0x10]
0x7a6f4b  6639480e                         cmp    WORD PTR [eax+0xe],cx
0x7a6f4f  743e                             je     0x7a6f8f
0x7a6f51  8d550c                           lea    edx,[ebp+0xc]
0x7a6f54  52                               push   edx
0x7a6f55  8d45ec                           lea    eax,[ebp-0x14]
0x7a6f58  50                               push   eax
0x7a6f59  8d434c                           lea    eax,[ebx+0x4c]
0x7a6f5c  e86fa6ffff                       call   0x7a15d0
0x7a6f61  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x7a6f64  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
0x7a6f67  51                               push   ecx
0x7a6f68  52                               push   edx
0x7a6f69  8d7508                           lea    esi,[ebp+0x8]
0x7a6f6c  8d434c                           lea    eax,[ebx+0x4c]
0x7a6f6f  e8ec31d2ff                       call   0x4ca160
0x7a6f74  668b7510                         mov    si,WORD PTR [ebp+0x10]
0x7a6f78  6685f6                           test   si,si
0x7a6f7b  740e                             je     0x7a6f8b
0x7a6f7d  8d550c                           lea    edx,[ebp+0xc]
0x7a6f80  8d434c                           lea    eax,[ebx+0x4c]
0x7a6f83  e8089bffff                       call   0x7a0a90
0x7a6f88  668930                           mov    WORD PTR [eax],si
0x7a6f8b  c6432801                         mov    BYTE PTR [ebx+0x28],0x1
0x7a6f8f  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7a6f92  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a6f99  59                               pop    ecx
0x7a6f9a  5f                               pop    edi
0x7a6f9b  5e                               pop    esi
0x7a6f9c  5b                               pop    ebx
0x7a6f9d  8be5                             mov    esp,ebp
0x7a6f9f  5d                               pop    ebp
0x7a6fa0  c20c00                           ret    0xc
0x7a6fa3  cc                               int3
0x7a6fa4  cc                               int3
0x7a6fa5  cc                               int3
0x7a6fa6  cc                               int3
0x7a6fa7  cc                               int3
0x7a6fa8  cc                               int3
0x7a6fa9  cc                               int3
0x7a6faa  cc                               int3
0x7a6fab  cc                               int3
0x7a6fac  cc                               int3
0x7a6fad  cc                               int3
0x7a6fae  cc                               int3
0x7a6faf  cc                               int3

; avatar_map_find | unsigned WORD part key compare
; VA 0x7a0b10..0x7a0b80 raw 0x39ff10 length 112 sha256 65abd0803da8d86166d4d3fe9c3c5f46a6cc02d44c3d665166f4c78a0ee73981
0x7a0b10  55                               push   ebp
0x7a0b11  8bec                             mov    ebp,esp
0x7a0b13  51                               push   ecx
0x7a0b14  53                               push   ebx
0x7a0b15  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a0b18  56                               push   esi
0x7a0b19  8bf1                             mov    esi,ecx
0x7a0b1b  8b5604                           mov    edx,DWORD PTR [esi+0x4]
0x7a0b1e  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0x7a0b21  80791100                         cmp    BYTE PTR [ecx+0x11],0x0
0x7a0b25  751f                             jne    0x7a0b46
0x7a0b27  57                               push   edi
0x7a0b28  0fb73b                           movzx  edi,WORD PTR [ebx]
0x7a0b2b  eb03                             jmp    0x7a0b30
0x7a0b2d  8d4900                           lea    ecx,[ecx+0x0]
0x7a0b30  6639790c                         cmp    WORD PTR [ecx+0xc],di
0x7a0b34  7305                             jae    0x7a0b3b
0x7a0b36  8b4908                           mov    ecx,DWORD PTR [ecx+0x8]
0x7a0b39  eb04                             jmp    0x7a0b3f
0x7a0b3b  8bd1                             mov    edx,ecx
0x7a0b3d  8b09                             mov    ecx,DWORD PTR [ecx]
0x7a0b3f  80791100                         cmp    BYTE PTR [ecx+0x11],0x0
0x7a0b43  74eb                             je     0x7a0b30
0x7a0b45  5f                               pop    edi
0x7a0b46  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x7a0b49  895508                           mov    DWORD PTR [ebp+0x8],edx
0x7a0b4c  3bd1                             cmp    edx,ecx
0x7a0b4e  7418                             je     0x7a0b68
0x7a0b50  668b33                           mov    si,WORD PTR [ebx]
0x7a0b53  663b720c                         cmp    si,WORD PTR [edx+0xc]
0x7a0b57  720f                             jb     0x7a0b68
0x7a0b59  8d4d08                           lea    ecx,[ebp+0x8]
0x7a0b5c  8b09                             mov    ecx,DWORD PTR [ecx]
0x7a0b5e  5e                               pop    esi
0x7a0b5f  8908                             mov    DWORD PTR [eax],ecx
0x7a0b61  5b                               pop    ebx
0x7a0b62  8be5                             mov    esp,ebp
0x7a0b64  5d                               pop    ebp
0x7a0b65  c20400                           ret    0x4
0x7a0b68  894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0x7a0b6b  8d4dfc                           lea    ecx,[ebp-0x4]
0x7a0b6e  8b09                             mov    ecx,DWORD PTR [ecx]
0x7a0b70  5e                               pop    esi
0x7a0b71  8908                             mov    DWORD PTR [eax],ecx
0x7a0b73  5b                               pop    ebx
0x7a0b74  8be5                             mov    esp,ebp
0x7a0b76  5d                               pop    ebp
0x7a0b77  c20400                           ret    0x4
0x7a0b7a  cc                               int3
0x7a0b7b  cc                               int3
0x7a0b7c  cc                               int3
0x7a0b7d  cc                               int3
0x7a0b7e  cc                               int3
0x7a0b7f  cc                               int3

; avatar_map_insert | unsigned WORD key and WORD value node+E
; VA 0x7a0a90..0x7a0b10 raw 0x39fe90 length 128 sha256 f14e8460815532f45722688561d668dec59ceba08a2f9b4cdfa015f87d497067
0x7a0a90  55                               push   ebp
0x7a0a91  8bec                             mov    ebp,esp
0x7a0a93  51                               push   ecx
0x7a0a94  53                               push   ebx
0x7a0a95  56                               push   esi
0x7a0a96  8bf0                             mov    esi,eax
0x7a0a98  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x7a0a9b  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x7a0a9e  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a0aa2  8bd9                             mov    ebx,ecx
0x7a0aa4  751f                             jne    0x7a0ac5
0x7a0aa6  0fb70a                           movzx  ecx,WORD PTR [edx]
0x7a0aa9  8da42400000000                   lea    esp,[esp+0x0]
0x7a0ab0  6639480c                         cmp    WORD PTR [eax+0xc],cx
0x7a0ab4  7305                             jae    0x7a0abb
0x7a0ab6  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x7a0ab9  eb04                             jmp    0x7a0abf
0x7a0abb  8bd8                             mov    ebx,eax
0x7a0abd  8b00                             mov    eax,DWORD PTR [eax]
0x7a0abf  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a0ac3  74eb                             je     0x7a0ab0
0x7a0ac5  3b5e04                           cmp    ebx,DWORD PTR [esi+0x4]
0x7a0ac8  7409                             je     0x7a0ad3
0x7a0aca  668b02                           mov    ax,WORD PTR [edx]
0x7a0acd  663b430c                         cmp    ax,WORD PTR [ebx+0xc]
0x7a0ad1  732f                             jae    0x7a0b02
0x7a0ad3  668b0a                           mov    cx,WORD PTR [edx]
0x7a0ad6  57                               push   edi
0x7a0ad7  33d2                             xor    edx,edx
0x7a0ad9  8d7dfc                           lea    edi,[ebp-0x4]
0x7a0adc  66894dfc                         mov    WORD PTR [ebp-0x4],cx
0x7a0ae0  668955fe                         mov    WORD PTR [ebp-0x2],dx
0x7a0ae4  e8972a0000                       call   0x7a3580
0x7a0ae9  53                               push   ebx
0x7a0aea  8d4dfc                           lea    ecx,[ebp-0x4]
0x7a0aed  51                               push   ecx
0x7a0aee  8bce                             mov    ecx,esi
0x7a0af0  e80b9b0700                       call   0x81a600
0x7a0af5  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x7a0af8  5f                               pop    edi
0x7a0af9  5e                               pop    esi
0x7a0afa  83c00e                           add    eax,0xe
0x7a0afd  5b                               pop    ebx
0x7a0afe  8be5                             mov    esp,ebp
0x7a0b00  5d                               pop    ebp
0x7a0b01  c3                               ret
0x7a0b02  5e                               pop    esi
0x7a0b03  8d430e                           lea    eax,[ebx+0xe]
0x7a0b06  5b                               pop    ebx
0x7a0b07  8be5                             mov    esp,ebp
0x7a0b09  5d                               pop    ebp
0x7a0b0a  c3                               ret
0x7a0b0b  cc                               int3
0x7a0b0c  cc                               int3
0x7a0b0d  cc                               int3
0x7a0b0e  cc                               int3
0x7a0b0f  cc                               int3

; doll_attach | appearance descriptor lookup and model-specific fallback
; VA 0x7a7240..0x7a7510 raw 0x3a6640 length 720 sha256 52b47e3689af6d94c542cac64449f9846fd3549c24028d6a92cadff0f87973e9
0x7a7240  55                               push   ebp
0x7a7241  8bec                             mov    ebp,esp
0x7a7243  83e4f8                           and    esp,0xfffffff8
0x7a7246  6aff                             push   0xffffffff
0x7a7248  68ea8d9100                       push   0x918dea
0x7a724d  64a100000000                     mov    eax,fs:0x0
0x7a7253  50                               push   eax
0x7a7254  83ec30                           sub    esp,0x30
0x7a7257  53                               push   ebx
0x7a7258  56                               push   esi
0x7a7259  57                               push   edi
0x7a725a  a1201fd600                       mov    eax,ds:0xd61f20
0x7a725f  33c4                             xor    eax,esp
0x7a7261  50                               push   eax
0x7a7262  8d442440                         lea    eax,[esp+0x40]
0x7a7266  64a300000000                     mov    fs:0x0,eax
0x7a726c  668b450c                         mov    ax,WORD PTR [ebp+0xc]
0x7a7270  668944241c                       mov    WORD PTR [esp+0x1c],ax
0x7a7275  c644241f00                       mov    BYTE PTR [esp+0x1f],0x0
0x7a727a  66c74424220000                   mov    WORD PTR [esp+0x22],0x0
0x7a7281  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x7a7288  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x7a728b  0fb74118                         movzx  eax,WORD PTR [ecx+0x18]
0x7a728f  8a5510                           mov    dl,BYTE PTR [ebp+0x10]
0x7a7292  8854241e                         mov    BYTE PTR [esp+0x1e],dl
0x7a7296  6689442420                       mov    WORD PTR [esp+0x20],ax
0x7a729b  7529                             jne    0x7a72c6
0x7a729d  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x7a72a4  c744244800000000                 mov    DWORD PTR [esp+0x48],0x0
0x7a72ac  e84f7c0100                       call   0x7bef00
0x7a72b1  6850ecbc00                       push   0xbcec50
0x7a72b6  e85fb00e00                       call   0x89231a
0x7a72bb  83c404                           add    esp,0x4
0x7a72be  c7442448ffffffff                 mov    DWORD PTR [esp+0x48],0xffffffff
0x7a72c6  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
0x7a72ca  8b5c2420                         mov    ebx,DWORD PTR [esp+0x20]
0x7a72ce  8d44242c                         lea    eax,[esp+0x2c]
0x7a72d2  50                               push   eax
0x7a72d3  8d4c2418                         lea    ecx,[esp+0x18]
0x7a72d7  51                               push   ecx
0x7a72d8  68601bfe00                       push   0xfe1b60
0x7a72dd  897c2438                         mov    DWORD PTR [esp+0x38],edi
0x7a72e1  895c243c                         mov    DWORD PTR [esp+0x3c],ebx
0x7a72e5  e81661d3ff                       call   0x4dd400
0x7a72ea  8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x7a72ee  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
0x7a72f4  740b                             je     0x7a7301
0x7a72f6  8b7018                           mov    esi,DWORD PTR [eax+0x18]
0x7a72f9  85f6                             test   esi,esi
0x7a72fb  0f8584000000                     jne    0x7a7385
0x7a7301  668b550c                         mov    dx,WORD PTR [ebp+0xc]
0x7a7305  8a4510                           mov    al,BYTE PTR [ebp+0x10]
0x7a7308  33c9                             xor    ecx,ecx
0x7a730a  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x7a7311  6689542424                       mov    WORD PTR [esp+0x24],dx
0x7a7316  88442426                         mov    BYTE PTR [esp+0x26],al
0x7a731a  c644242700                       mov    BYTE PTR [esp+0x27],0x0
0x7a731f  894c2428                         mov    DWORD PTR [esp+0x28],ecx
0x7a7323  7529                             jne    0x7a734e
0x7a7325  b801000000                       mov    eax,0x1
0x7a732a  0905c01bfe00                     or     DWORD PTR ds:0xfe1bc0,eax
0x7a7330  89442448                         mov    DWORD PTR [esp+0x48],eax
0x7a7334  e8c77b0100                       call   0x7bef00
0x7a7339  6850ecbc00                       push   0xbcec50
0x7a733e  e8d7af0e00                       call   0x89231a
0x7a7343  83c404                           add    esp,0x4
0x7a7346  c7442448ffffffff                 mov    DWORD PTR [esp+0x48],0xffffffff
0x7a734e  8b7c2424                         mov    edi,DWORD PTR [esp+0x24]
0x7a7352  8b5c2428                         mov    ebx,DWORD PTR [esp+0x28]
0x7a7356  8d542434                         lea    edx,[esp+0x34]
0x7a735a  52                               push   edx
0x7a735b  8d44241c                         lea    eax,[esp+0x1c]
0x7a735f  50                               push   eax
0x7a7360  68601bfe00                       push   0xfe1b60
0x7a7365  897c2440                         mov    DWORD PTR [esp+0x40],edi
0x7a7369  895c2444                         mov    DWORD PTR [esp+0x44],ebx
0x7a736d  e88e60d3ff                       call   0x4dd400
0x7a7372  8b442418                         mov    eax,DWORD PTR [esp+0x18]
0x7a7376  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
0x7a737c  7504                             jne    0x7a7382
0x7a737e  33f6                             xor    esi,esi
0x7a7380  eb03                             jmp    0x7a7385
0x7a7382  8b7018                           mov    esi,DWORD PTR [eax+0x18]
0x7a7385  8bcb                             mov    ecx,ebx
0x7a7387  8bc7                             mov    eax,edi
0x7a7389  85f6                             test   esi,esi
0x7a738b  7511                             jne    0x7a739e
0x7a738d  397510                           cmp    DWORD PTR [ebp+0x10],esi
0x7a7390  0f8454010000                     je     0x7a74ea
0x7a7396  ff4d10                           dec    DWORD PTR [ebp+0x10]
0x7a7399  e9e3feffff                       jmp    0x7a7281
0x7a739e  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a73a1  51                               push   ecx
0x7a73a2  50                               push   eax
0x7a73a3  53                               push   ebx
0x7a73a4  e867010000                       call   0x7a7510
0x7a73a9  8b7e20                           mov    edi,DWORD PTR [esi+0x20]
0x7a73ac  8b5b60                           mov    ebx,DWORD PTR [ebx+0x60]
0x7a73af  8d4c2418                         lea    ecx,[esp+0x18]
0x7a73b3  51                               push   ecx
0x7a73b4  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x7a73b7  8d7710                           lea    esi,[edi+0x10]
0x7a73ba  83c15c                           add    ecx,0x5c
0x7a73bd  8d442418                         lea    eax,[esp+0x18]
0x7a73c1  8974241c                         mov    DWORD PTR [esp+0x1c],esi
0x7a73c5  e83698ffff                       call   0x7a0c00
0x7a73ca  3b18                             cmp    ebx,DWORD PTR [eax]
0x7a73cc  740a                             je     0x7a73d8
0x7a73ce  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x7a73d1  56                               push   esi
0x7a73d2  52                               push   edx
0x7a73d3  e848020000                       call   0x7a7620
0x7a73d8  33c0                             xor    eax,eax
0x7a73da  394514                           cmp    DWORD PTR [ebp+0x14],eax
0x7a73dd  0f84ed000000                     je     0x7a74d0
0x7a73e3  83ff01                           cmp    edi,0x1
0x7a73e6  0f85e4000000                     jne    0x7a74d0
0x7a73ec  8944241c                         mov    DWORD PTR [esp+0x1c],eax
0x7a73f0  89442420                         mov    DWORD PTR [esp+0x20],eax
0x7a73f4  8b5d10                           mov    ebx,DWORD PTR [ebp+0x10]
0x7a73f7  85c0                             test   eax,eax
0x7a73f9  0f85be000000                     jne    0x7a74bd
0x7a73ff  668b4514                         mov    ax,WORD PTR [ebp+0x14]
0x7a7403  6689442424                       mov    WORD PTR [esp+0x24],ax
0x7a7408  c644242701                       mov    BYTE PTR [esp+0x27],0x1
0x7a740d  66c744242a0000                   mov    WORD PTR [esp+0x2a],0x0
0x7a7414  eb0a                             jmp    0x7a7420
0x7a7416  8da42400000000                   lea    esp,[esp+0x0]
0x7a741d  8d4900                           lea    ecx,[ecx+0x0]
0x7a7420  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x7a7427  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x7a742a  0fb74118                         movzx  eax,WORD PTR [ecx+0x18]
0x7a742e  885c2426                         mov    BYTE PTR [esp+0x26],bl
0x7a7432  8b742424                         mov    esi,DWORD PTR [esp+0x24]
0x7a7436  6689442428                       mov    WORD PTR [esp+0x28],ax
0x7a743b  8b7c2428                         mov    edi,DWORD PTR [esp+0x28]
0x7a743f  8974241c                         mov    DWORD PTR [esp+0x1c],esi
0x7a7443  897c2420                         mov    DWORD PTR [esp+0x20],edi
0x7a7447  7529                             jne    0x7a7472
0x7a7449  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x7a7450  c744244802000000                 mov    DWORD PTR [esp+0x48],0x2
0x7a7458  e8a37a0100                       call   0x7bef00
0x7a745d  6850ecbc00                       push   0xbcec50
0x7a7462  e8b3ae0e00                       call   0x89231a
0x7a7467  83c404                           add    esp,0x4
0x7a746a  c7442448ffffffff                 mov    DWORD PTR [esp+0x48],0xffffffff
0x7a7472  8d542434                         lea    edx,[esp+0x34]
0x7a7476  52                               push   edx
0x7a7477  8d44241c                         lea    eax,[esp+0x1c]
0x7a747b  50                               push   eax
0x7a747c  68601bfe00                       push   0xfe1b60
0x7a7481  89742440                         mov    DWORD PTR [esp+0x40],esi
0x7a7485  897c2444                         mov    DWORD PTR [esp+0x44],edi
0x7a7489  e8725fd3ff                       call   0x4dd400
0x7a748e  8b442418                         mov    eax,DWORD PTR [esp+0x18]
0x7a7492  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
0x7a7498  7504                             jne    0x7a749e
0x7a749a  33c0                             xor    eax,eax
0x7a749c  eb07                             jmp    0x7a74a5
0x7a749e  8b4018                           mov    eax,DWORD PTR [eax+0x18]
0x7a74a1  85c0                             test   eax,eax
0x7a74a3  7518                             jne    0x7a74bd
0x7a74a5  85db                             test   ebx,ebx
0x7a74a7  7406                             je     0x7a74af
0x7a74a9  4b                               dec    ebx
0x7a74aa  e971ffffff                       jmp    0x7a7420
0x7a74af  837d1400                         cmp    DWORD PTR [ebp+0x14],0x0
0x7a74b3  7408                             je     0x7a74bd
0x7a74b5  ff4d14                           dec    DWORD PTR [ebp+0x14]
0x7a74b8  e937ffffff                       jmp    0x7a73f4
0x7a74bd  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0x7a74c1  8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
0x7a74c5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x7a74c8  51                               push   ecx
0x7a74c9  52                               push   edx
0x7a74ca  50                               push   eax
0x7a74cb  e840000000                       call   0x7a7510
0x7a74d0  b801000000                       mov    eax,0x1
0x7a74d5  8b4c2440                         mov    ecx,DWORD PTR [esp+0x40]
0x7a74d9  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a74e0  59                               pop    ecx
0x7a74e1  5f                               pop    edi
0x7a74e2  5e                               pop    esi
0x7a74e3  5b                               pop    ebx
0x7a74e4  8be5                             mov    esp,ebp
0x7a74e6  5d                               pop    ebp
0x7a74e7  c21000                           ret    0x10
0x7a74ea  33c0                             xor    eax,eax
0x7a74ec  8b4c2440                         mov    ecx,DWORD PTR [esp+0x40]
0x7a74f0  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a74f7  59                               pop    ecx
0x7a74f8  5f                               pop    edi
0x7a74f9  5e                               pop    esi
0x7a74fa  5b                               pop    ebx
0x7a74fb  8be5                             mov    esp,ebp
0x7a74fd  5d                               pop    ebp
0x7a74fe  c21000                           ret    0x10
0x7a7501  cc                               int3
0x7a7502  cc                               int3
0x7a7503  cc                               int3
0x7a7504  cc                               int3
0x7a7505  cc                               int3
0x7a7506  cc                               int3
0x7a7507  cc                               int3
0x7a7508  cc                               int3
0x7a7509  cc                               int3
0x7a750a  cc                               int3
0x7a750b  cc                               int3
0x7a750c  cc                               int3
0x7a750d  cc                               int3
0x7a750e  cc                               int3
0x7a750f  cc                               int3

; doll_attachment_replace | descriptor+20 supplies attachment key; snapshot item key inserted
; VA 0x7a7510..0x7a7620 raw 0x3a6910 length 272 sha256 08f5f7039d9438093b835d2aacb46794cdfecf61a45e8e94e26a7ce2c3cd0c17
0x7a7510  55                               push   ebp
0x7a7511  8bec                             mov    ebp,esp
0x7a7513  6aff                             push   0xffffffff
0x7a7515  689e8d9100                       push   0x918d9e
0x7a751a  64a100000000                     mov    eax,fs:0x0
0x7a7520  50                               push   eax
0x7a7521  83ec18                           sub    esp,0x18
0x7a7524  53                               push   ebx
0x7a7525  56                               push   esi
0x7a7526  57                               push   edi
0x7a7527  a1201fd600                       mov    eax,ds:0xd61f20
0x7a752c  33c5                             xor    eax,ebp
0x7a752e  50                               push   eax
0x7a752f  8d45f4                           lea    eax,[ebp-0xc]
0x7a7532  64a300000000                     mov    fs:0x0,eax
0x7a7538  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a753b  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x7a7542  7527                             jne    0x7a756b
0x7a7544  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x7a754b  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x7a7552  e8a9790100                       call   0x7bef00
0x7a7557  6850ecbc00                       push   0xbcec50
0x7a755c  e8b9ad0e00                       call   0x89231a
0x7a7561  83c404                           add    esp,0x4
0x7a7564  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x7a756b  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x7a756e  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0x7a7571  8d4de4                           lea    ecx,[ebp-0x1c]
0x7a7574  51                               push   ecx
0x7a7575  8d5508                           lea    edx,[ebp+0x8]
0x7a7578  52                               push   edx
0x7a7579  68601bfe00                       push   0xfe1b60
0x7a757e  8975e4                           mov    DWORD PTR [ebp-0x1c],esi
0x7a7581  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x7a7584  e8775ed3ff                       call   0x4dd400
0x7a7589  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x7a758c  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
0x7a7592  7476                             je     0x7a760a
0x7a7594  8b4018                           mov    eax,DWORD PTR [eax+0x18]
0x7a7597  85c0                             test   eax,eax
0x7a7599  746f                             je     0x7a760a
0x7a759b  8b7820                           mov    edi,DWORD PTR [eax+0x20]
0x7a759e  8bc6                             mov    eax,esi
0x7a75a0  c1e818                           shr    eax,0x18
0x7a75a3  3c01                             cmp    al,0x1
0x7a75a5  7503                             jne    0x7a75aa
0x7a75a7  83c710                           add    edi,0x10
0x7a75aa  8d4d08                           lea    ecx,[ebp+0x8]
0x7a75ad  8d735c                           lea    esi,[ebx+0x5c]
0x7a75b0  51                               push   ecx
0x7a75b1  8d45e8                           lea    eax,[ebp-0x18]
0x7a75b4  8bce                             mov    ecx,esi
0x7a75b6  897d08                           mov    DWORD PTR [ebp+0x8],edi
0x7a75b9  e84296ffff                       call   0x7a0c00
0x7a75be  8b5360                           mov    edx,DWORD PTR [ebx+0x60]
0x7a75c1  3b10                             cmp    edx,DWORD PTR [eax]
0x7a75c3  7407                             je     0x7a75cc
0x7a75c5  57                               push   edi
0x7a75c6  53                               push   ebx
0x7a75c7  e854000000                       call   0x7a7620
0x7a75cc  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x7a75cf  8b4d10                           mov    ecx,DWORD PTR [ebp+0x10]
0x7a75d2  897ddc                           mov    DWORD PTR [ebp-0x24],edi
0x7a75d5  8d7ddc                           lea    edi,[ebp-0x24]
0x7a75d8  8945e4                           mov    DWORD PTR [ebp-0x1c],eax
0x7a75db  894de8                           mov    DWORD PTR [ebp-0x18],ecx
0x7a75de  e80db0ffff                       call   0x7a25f0
0x7a75e3  50                               push   eax
0x7a75e4  56                               push   esi
0x7a75e5  8d750c                           lea    esi,[ebp+0xc]
0x7a75e8  e823b2ffff                       call   0x7a2810
0x7a75ed  c6432801                         mov    BYTE PTR [ebx+0x28],0x1
0x7a75f1  b801000000                       mov    eax,0x1
0x7a75f6  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7a75f9  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a7600  59                               pop    ecx
0x7a7601  5f                               pop    edi
0x7a7602  5e                               pop    esi
0x7a7603  5b                               pop    ebx
0x7a7604  8be5                             mov    esp,ebp
0x7a7606  5d                               pop    ebp
0x7a7607  c20c00                           ret    0xc
0x7a760a  33c0                             xor    eax,eax
0x7a760c  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7a760f  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a7616  59                               pop    ecx
0x7a7617  5f                               pop    edi
0x7a7618  5e                               pop    esi
0x7a7619  5b                               pop    ebx
0x7a761a  8be5                             mov    esp,ebp
0x7a761c  5d                               pop    ebp
0x7a761d  c20c00                           ret    0xc

; doll_detach | erase supplied attachment key and key+10; mark dirty
; VA 0x7a7620..0x7a76b0 raw 0x3a6a20 length 144 sha256 357f73e2a1f908ff1770c7800991f07437fba5a7908cb6a482de404f405efe7d
0x7a7620  55                               push   ebp
0x7a7621  8bec                             mov    ebp,esp
0x7a7623  83ec0c                           sub    esp,0xc
0x7a7626  53                               push   ebx
0x7a7627  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a762a  56                               push   esi
0x7a762b  57                               push   edi
0x7a762c  8d450c                           lea    eax,[ebp+0xc]
0x7a762f  50                               push   eax
0x7a7630  8d4df8                           lea    ecx,[ebp-0x8]
0x7a7633  51                               push   ecx
0x7a7634  8d435c                           lea    eax,[ebx+0x5c]
0x7a7637  e8842a0000                       call   0x7aa0c0
0x7a763c  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x7a763f  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0x7a7642  52                               push   edx
0x7a7643  50                               push   eax
0x7a7644  8d7508                           lea    esi,[ebp+0x8]
0x7a7647  8d435c                           lea    eax,[ebx+0x5c]
0x7a764a  e8d1faf2ff                       call   0x6d7120
0x7a764f  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0x7a7652  8d4d0c                           lea    ecx,[ebp+0xc]
0x7a7655  51                               push   ecx
0x7a7656  83c610                           add    esi,0x10
0x7a7659  8d4508                           lea    eax,[ebp+0x8]
0x7a765c  8d4b5c                           lea    ecx,[ebx+0x5c]
0x7a765f  89750c                           mov    DWORD PTR [ebp+0xc],esi
0x7a7662  e89995ffff                       call   0x7a0c00
0x7a7667  8b5360                           mov    edx,DWORD PTR [ebx+0x60]
0x7a766a  3b10                             cmp    edx,DWORD PTR [eax]
0x7a766c  7426                             je     0x7a7694
0x7a766e  8d450c                           lea    eax,[ebp+0xc]
0x7a7671  50                               push   eax
0x7a7672  8d4df8                           lea    ecx,[ebp-0x8]
0x7a7675  51                               push   ecx
0x7a7676  8d435c                           lea    eax,[ebx+0x5c]
0x7a7679  89750c                           mov    DWORD PTR [ebp+0xc],esi
0x7a767c  e83f2a0000                       call   0x7aa0c0
0x7a7681  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x7a7684  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0x7a7687  52                               push   edx
0x7a7688  50                               push   eax
0x7a7689  8d750c                           lea    esi,[ebp+0xc]
0x7a768c  8d435c                           lea    eax,[ebx+0x5c]
0x7a768f  e88cfaf2ff                       call   0x6d7120
0x7a7694  5f                               pop    edi
0x7a7695  5e                               pop    esi
0x7a7696  c6432801                         mov    BYTE PTR [ebx+0x28],0x1
0x7a769a  5b                               pop    ebx
0x7a769b  8be5                             mov    esp,ebp
0x7a769d  5d                               pop    ebp
0x7a769e  c20800                           ret    0x8
0x7a76a1  cc                               int3
0x7a76a2  cc                               int3
0x7a76a3  cc                               int3
0x7a76a4  cc                               int3
0x7a76a5  cc                               int3
0x7a76a6  cc                               int3
0x7a76a7  cc                               int3
0x7a76a8  cc                               int3
0x7a76a9  cc                               int3
0x7a76aa  cc                               int3
0x7a76ab  cc                               int3
0x7a76ac  cc                               int3
0x7a76ad  cc                               int3
0x7a76ae  cc                               int3
0x7a76af  cc                               int3

; doll_attachment_find | DWORD attachment key compare
; VA 0x7a0c00..0x7a0c70 raw 0x3a0000 length 112 sha256 c20f55c15dabe7f92238f4220d9eec38e4c491b97687abe47d65155d2636ebdc
0x7a0c00  55                               push   ebp
0x7a0c01  8bec                             mov    ebp,esp
0x7a0c03  51                               push   ecx
0x7a0c04  53                               push   ebx
0x7a0c05  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a0c08  56                               push   esi
0x7a0c09  8bf1                             mov    esi,ecx
0x7a0c0b  8b5604                           mov    edx,DWORD PTR [esi+0x4]
0x7a0c0e  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0x7a0c11  80792100                         cmp    BYTE PTR [ecx+0x21],0x0
0x7a0c15  751e                             jne    0x7a0c35
0x7a0c17  57                               push   edi
0x7a0c18  8b3b                             mov    edi,DWORD PTR [ebx]
0x7a0c1a  8d9b00000000                     lea    ebx,[ebx+0x0]
0x7a0c20  397910                           cmp    DWORD PTR [ecx+0x10],edi
0x7a0c23  7305                             jae    0x7a0c2a
0x7a0c25  8b4908                           mov    ecx,DWORD PTR [ecx+0x8]
0x7a0c28  eb04                             jmp    0x7a0c2e
0x7a0c2a  8bd1                             mov    edx,ecx
0x7a0c2c  8b09                             mov    ecx,DWORD PTR [ecx]
0x7a0c2e  80792100                         cmp    BYTE PTR [ecx+0x21],0x0
0x7a0c32  74ec                             je     0x7a0c20
0x7a0c34  5f                               pop    edi
0x7a0c35  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x7a0c38  895508                           mov    DWORD PTR [ebp+0x8],edx
0x7a0c3b  3bd1                             cmp    edx,ecx
0x7a0c3d  7416                             je     0x7a0c55
0x7a0c3f  8b33                             mov    esi,DWORD PTR [ebx]
0x7a0c41  3b7210                           cmp    esi,DWORD PTR [edx+0x10]
0x7a0c44  720f                             jb     0x7a0c55
0x7a0c46  8d4d08                           lea    ecx,[ebp+0x8]
0x7a0c49  8b09                             mov    ecx,DWORD PTR [ecx]
0x7a0c4b  5e                               pop    esi
0x7a0c4c  8908                             mov    DWORD PTR [eax],ecx
0x7a0c4e  5b                               pop    ebx
0x7a0c4f  8be5                             mov    esp,ebp
0x7a0c51  5d                               pop    ebp
0x7a0c52  c20400                           ret    0x4
0x7a0c55  894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0x7a0c58  8d4dfc                           lea    ecx,[ebp-0x4]
0x7a0c5b  8b09                             mov    ecx,DWORD PTR [ecx]
0x7a0c5d  5e                               pop    esi
0x7a0c5e  8908                             mov    DWORD PTR [eax],ecx
0x7a0c60  5b                               pop    ebx
0x7a0c61  8be5                             mov    esp,ebp
0x7a0c63  5d                               pop    ebp
0x7a0c64  c20400                           ret    0x4
0x7a0c67  cc                               int3
0x7a0c68  cc                               int3
0x7a0c69  cc                               int3
0x7a0c6a  cc                               int3
0x7a0c6b  cc                               int3
0x7a0c6c  cc                               int3
0x7a0c6d  cc                               int3
0x7a0c6e  cc                               int3
0x7a0c6f  cc                               int3

; doll_update_enqueue | snapshot requested avatar and attachment maps; queue job
; VA 0x7a8e70..0x7a90f0 raw 0x3a8270 length 640 sha256 7f2ba0e1156c91d1eda1fed97b7b18494ea4792fb1fe5ae958640cda45a33492
0x7a8e70  55                               push   ebp
0x7a8e71  8bec                             mov    ebp,esp
0x7a8e73  83e4f8                           and    esp,0xfffffff8
0x7a8e76  6aff                             push   0xffffffff
0x7a8e78  68fb909300                       push   0x9390fb
0x7a8e7d  64a100000000                     mov    eax,fs:0x0
0x7a8e83  50                               push   eax
0x7a8e84  83ec18                           sub    esp,0x18
0x7a8e87  53                               push   ebx
0x7a8e88  56                               push   esi
0x7a8e89  57                               push   edi
0x7a8e8a  a1201fd600                       mov    eax,ds:0xd61f20
0x7a8e8f  33c4                             xor    eax,esp
0x7a8e91  50                               push   eax
0x7a8e92  8d442428                         lea    eax,[esp+0x28]
0x7a8e96  64a300000000                     mov    fs:0x0,eax
0x7a8e9c  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a8e9f  6a74                             push   0x74
0x7a8ea1  e8c2830e00                       call   0x891268
0x7a8ea6  8bf0                             mov    esi,eax
0x7a8ea8  83c404                           add    esp,0x4
0x7a8eab  89742414                         mov    DWORD PTR [esp+0x14],esi
0x7a8eaf  33ff                             xor    edi,edi
0x7a8eb1  897c2430                         mov    DWORD PTR [esp+0x30],edi
0x7a8eb5  3bf7                             cmp    esi,edi
0x7a8eb7  742d                             je     0x7a8ee6
0x7a8eb9  8d4608                           lea    eax,[esi+0x8]
0x7a8ebc  50                               push   eax
0x7a8ebd  e85ec1ffff                       call   0x7a5020
0x7a8ec2  8d4e28                           lea    ecx,[esi+0x28]
0x7a8ec5  51                               push   ecx
0x7a8ec6  c644243401                       mov    BYTE PTR [esp+0x34],0x1
0x7a8ecb  e850c1ffff                       call   0x7a5020
0x7a8ed0  8d5648                           lea    edx,[esi+0x48]
0x7a8ed3  52                               push   edx
0x7a8ed4  c644243402                       mov    BYTE PTR [esp+0x34],0x2
0x7a8ed9  e842c1ffff                       call   0x7a5020
0x7a8ede  897e68                           mov    DWORD PTR [esi+0x68],edi
0x7a8ee1  897e6c                           mov    DWORD PTR [esi+0x6c],edi
0x7a8ee4  eb02                             jmp    0x7a8ee8
0x7a8ee6  33f6                             xor    esi,esi
0x7a8ee8  56                               push   esi
0x7a8ee9  8d442420                         lea    eax,[esp+0x20]
0x7a8eed  c7442434ffffffff                 mov    DWORD PTR [esp+0x34],0xffffffff
0x7a8ef5  50                               push   eax
0x7a8ef6  897c2424                         mov    DWORD PTR [esp+0x24],edi
0x7a8efa  897c2428                         mov    DWORD PTR [esp+0x28],edi
0x7a8efe  e80d190000                       call   0x7aa810
0x7a8f03  c744243003000000                 mov    DWORD PTR [esp+0x30],0x3
0x7a8f0b  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a8f0f  8b4b18                           mov    ecx,DWORD PTR [ebx+0x18]
0x7a8f12  8d434c                           lea    eax,[ebx+0x4c]
0x7a8f15  8d7e28                           lea    edi,[esi+0x28]
0x7a8f18  890e                             mov    DWORD PTR [esi],ecx
0x7a8f1a  3bf8                             cmp    edi,eax
0x7a8f1c  7421                             je     0x7a8f3f
0x7a8f1e  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a8f21  8b08                             mov    ecx,DWORD PTR [eax]
0x7a8f23  50                               push   eax
0x7a8f24  51                               push   ecx
0x7a8f25  8d74241c                         lea    esi,[esp+0x1c]
0x7a8f29  8bc7                             mov    eax,edi
0x7a8f2b  e83012d2ff                       call   0x4ca160
0x7a8f30  8d434c                           lea    eax,[ebx+0x4c]
0x7a8f33  50                               push   eax
0x7a8f34  8bc7                             mov    eax,edi
0x7a8f36  e80586ffff                       call   0x7a1540
0x7a8f3b  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a8f3f  8d435c                           lea    eax,[ebx+0x5c]
0x7a8f42  8d7e38                           lea    edi,[esi+0x38]
0x7a8f45  3bf8                             cmp    edi,eax
0x7a8f47  7421                             je     0x7a8f6a
0x7a8f49  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a8f4c  8b08                             mov    ecx,DWORD PTR [eax]
0x7a8f4e  50                               push   eax
0x7a8f4f  51                               push   ecx
0x7a8f50  8d74241c                         lea    esi,[esp+0x1c]
0x7a8f54  8bc7                             mov    eax,edi
0x7a8f56  e8c5e1f2ff                       call   0x6d7120
0x7a8f5b  8d435c                           lea    eax,[ebx+0x5c]
0x7a8f5e  50                               push   eax
0x7a8f5f  8bc7                             mov    eax,edi
0x7a8f61  e8fa86ffff                       call   0x7a1660
0x7a8f66  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a8f6a  8d4310                           lea    eax,[ebx+0x10]
0x7a8f6d  8d4c2414                         lea    ecx,[esp+0x14]
0x7a8f71  e81a0e0000                       call   0x7a9d90
0x7a8f76  8d7e68                           lea    edi,[esi+0x68]
0x7a8f79  c644243004                       mov    BYTE PTR [esp+0x30],0x4
0x7a8f7e  e8dd7fd3ff                       call   0x4e0f60
0x7a8f83  c644243003                       mov    BYTE PTR [esp+0x30],0x3
0x7a8f88  8b442418                         mov    eax,DWORD PTR [esp+0x18]
0x7a8f8c  85c0                             test   eax,eax
0x7a8f8e  742b                             je     0x7a8fbb
0x7a8f90  8bf0                             mov    esi,eax
0x7a8f92  83c004                           add    eax,0x4
0x7a8f95  83caff                           or     edx,0xffffffff
0x7a8f98  f00fc110                         lock xadd DWORD PTR [eax],edx
0x7a8f9c  751d                             jne    0x7a8fbb
0x7a8f9e  8b06                             mov    eax,DWORD PTR [esi]
0x7a8fa0  8b10                             mov    edx,DWORD PTR [eax]
0x7a8fa2  8bce                             mov    ecx,esi
0x7a8fa4  ffd2                             call   edx
0x7a8fa6  8d4608                           lea    eax,[esi+0x8]
0x7a8fa9  83c9ff                           or     ecx,0xffffffff
0x7a8fac  f00fc108                         lock xadd DWORD PTR [eax],ecx
0x7a8fb0  7509                             jne    0x7a8fbb
0x7a8fb2  8b16                             mov    edx,DWORD PTR [esi]
0x7a8fb4  8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x7a8fb7  8bce                             mov    ecx,esi
0x7a8fb9  ffd0                             call   eax
0x7a8fbb  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a8fbf  8d4b2c                           lea    ecx,[ebx+0x2c]
0x7a8fc2  51                               push   ecx
0x7a8fc3  8d7e08                           lea    edi,[esi+0x8]
0x7a8fc6  e865c7ffff                       call   0x7a5730
0x7a8fcb  837b2400                         cmp    DWORD PTR [ebx+0x24],0x0
0x7a8fcf  0f94c2                           sete   dl
0x7a8fd2  885604                           mov    BYTE PTR [esi+0x4],dl
0x7a8fd5  807b2000                         cmp    BYTE PTR [ebx+0x20],0x0
0x7a8fd9  7410                             je     0x7a8feb
0x7a8fdb  6a00                             push   0x0
0x7a8fdd  6a00                             push   0x0
0x7a8fdf  6a00                             push   0x0
0x7a8fe1  6a00                             push   0x0
0x7a8fe3  ff15cc20bd00                     call   DWORD PTR ds:0xbd20cc
0x7a8fe9  eb03                             jmp    0x7a8fee
0x7a8feb  83c8ff                           or     eax,0xffffffff
0x7a8fee  8b7c2420                         mov    edi,DWORD PTR [esp+0x20]
0x7a8ff2  894670                           mov    DWORD PTR [esi+0x70],eax
0x7a8ff5  83ec08                           sub    esp,0x8
0x7a8ff8  8bf4                             mov    esi,esp
0x7a8ffa  c6432800                         mov    BYTE PTR [ebx+0x28],0x0
0x7a8ffe  c7432402000000                   mov    DWORD PTR [ebx+0x24],0x2
0x7a9005  8964241c                         mov    DWORD PTR [esp+0x1c],esp
0x7a9009  c70600000000                     mov    DWORD PTR [esi],0x0
0x7a900f  c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x7a9016  85ff                             test   edi,edi
0x7a9018  7416                             je     0x7a9030
0x7a901a  8bd7                             mov    edx,edi
0x7a901c  e82f32cdff                       call   0x47c250
0x7a9021  84c0                             test   al,al
0x7a9023  740b                             je     0x7a9030
0x7a9025  8b442424                         mov    eax,DWORD PTR [esp+0x24]
0x7a9029  57                               push   edi
0x7a902a  50                               push   eax
0x7a902b  e890a1ffff                       call   0x7a31c0
0x7a9030  c644243805                       mov    BYTE PTR [esp+0x38],0x5
0x7a9035  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
0x7a903c  7523                             jne    0x7a9061
0x7a903e  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
0x7a9045  c644243806                       mov    BYTE PTR [esp+0x38],0x6
0x7a904a  e8f13effff                       call   0x79cf40
0x7a904f  6880dbbc00                       push   0xbcdb80
0x7a9054  e8c1920e00                       call   0x89231a
0x7a9059  83c404                           add    esp,0x4
0x7a905c  c644243805                       mov    BYTE PTR [esp+0x38],0x5
0x7a9061  b9900efc00                       mov    ecx,0xfc0e90
0x7a9066  c644243803                       mov    BYTE PTR [esp+0x38],0x3
0x7a906b  e8004affff                       call   0x79da70
0x7a9070  807b2000                         cmp    BYTE PTR [ebx+0x20],0x0
0x7a9074  7427                             je     0x7a909d
0x7a9076  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a907a  8b4e70                           mov    ecx,DWORD PTR [esi+0x70]
0x7a907d  6aff                             push   0xffffffff
0x7a907f  51                               push   ecx
0x7a9080  ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
0x7a9086  8b5670                           mov    edx,DWORD PTR [esi+0x70]
0x7a9089  52                               push   edx
0x7a908a  ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
0x7a9090  681cf6c400                       push   0xc4f61c
0x7a9095  e823a00e00                       call   0x8930bd
0x7a909a  83c404                           add    esp,0x4
0x7a909d  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x7a90a5  85ff                             test   edi,edi
0x7a90a7  7429                             je     0x7a90d2
0x7a90a9  8d4704                           lea    eax,[edi+0x4]
0x7a90ac  83c9ff                           or     ecx,0xffffffff
0x7a90af  f00fc108                         lock xadd DWORD PTR [eax],ecx
0x7a90b3  751d                             jne    0x7a90d2
0x7a90b5  8b17                             mov    edx,DWORD PTR [edi]
0x7a90b7  8b02                             mov    eax,DWORD PTR [edx]
0x7a90b9  8bcf                             mov    ecx,edi
0x7a90bb  ffd0                             call   eax
0x7a90bd  8d4f08                           lea    ecx,[edi+0x8]
0x7a90c0  83caff                           or     edx,0xffffffff
0x7a90c3  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x7a90c7  7509                             jne    0x7a90d2
0x7a90c9  8b07                             mov    eax,DWORD PTR [edi]
0x7a90cb  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a90ce  8bcf                             mov    ecx,edi
0x7a90d0  ffd2                             call   edx
0x7a90d2  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x7a90d6  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a90dd  59                               pop    ecx
0x7a90de  5f                               pop    edi
0x7a90df  5e                               pop    esi
0x7a90e0  5b                               pop    ebx
0x7a90e1  8be5                             mov    esp,ebp
0x7a90e3  5d                               pop    ebp
0x7a90e4  c20400                           ret    0x4
0x7a90e7  cc                               int3
0x7a90e8  cc                               int3
0x7a90e9  cc                               int3
0x7a90ea  cc                               int3
0x7a90eb  cc                               int3
0x7a90ec  cc                               int3
0x7a90ed  cc                               int3
0x7a90ee  cc                               int3
0x7a90ef  cc                               int3

; doll_enqueue_manager | publish job into FC0E90+28 queue under lock
; VA 0x79da70..0x79db10 raw 0x39ce70 length 160 sha256 414afa6a1af89bd1bcf1e046c16b320f7f9d7132c4e7758c6bff09eb3bfaa192
0x79da70  55                               push   ebp
0x79da71  8bec                             mov    ebp,esp
0x79da73  6aff                             push   0xffffffff
0x79da75  6870a29000                       push   0x90a270
0x79da7a  64a100000000                     mov    eax,fs:0x0
0x79da80  50                               push   eax
0x79da81  51                               push   ecx
0x79da82  56                               push   esi
0x79da83  57                               push   edi
0x79da84  a1201fd600                       mov    eax,ds:0xd61f20
0x79da89  33c5                             xor    eax,ebp
0x79da8b  50                               push   eax
0x79da8c  8d45f4                           lea    eax,[ebp-0xc]
0x79da8f  64a300000000                     mov    fs:0x0,eax
0x79da95  8bf9                             mov    edi,ecx
0x79da97  8d7770                           lea    esi,[edi+0x70]
0x79da9a  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x79daa1  56                               push   esi
0x79daa2  8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x79daa5  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x79daab  83c728                           add    edi,0x28
0x79daae  57                               push   edi
0x79daaf  8d4d08                           lea    ecx,[ebp+0x8]
0x79dab2  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x79dab6  e8a5340000                       call   0x7a0f60
0x79dabb  56                               push   esi
0x79dabc  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x79dac2  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x79dac9  8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0x79dacc  85f6                             test   esi,esi
0x79dace  7429                             je     0x79daf9
0x79dad0  8d4604                           lea    eax,[esi+0x4]
0x79dad3  83c9ff                           or     ecx,0xffffffff
0x79dad6  f00fc108                         lock xadd DWORD PTR [eax],ecx
0x79dada  751d                             jne    0x79daf9
0x79dadc  8b16                             mov    edx,DWORD PTR [esi]
0x79dade  8b02                             mov    eax,DWORD PTR [edx]
0x79dae0  8bce                             mov    ecx,esi
0x79dae2  ffd0                             call   eax
0x79dae4  8d4e08                           lea    ecx,[esi+0x8]
0x79dae7  83caff                           or     edx,0xffffffff
0x79daea  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x79daee  7509                             jne    0x79daf9
0x79daf0  8b06                             mov    eax,DWORD PTR [esi]
0x79daf2  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x79daf5  8bce                             mov    ecx,esi
0x79daf7  ffd2                             call   edx
0x79daf9  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x79dafc  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x79db03  59                               pop    ecx
0x79db04  5f                               pop    edi
0x79db05  5e                               pop    esi
0x79db06  8be5                             mov    esp,ebp
0x79db08  5d                               pop    ebp
0x79db09  c20800                           ret    0x8
0x79db0c  cc                               int3
0x79db0d  cc                               int3
0x79db0e  cc                               int3
0x79db0f  cc                               int3

; doll_worker_take | consume the same manager+28 queue
; VA 0x79e7c0..0x79e8a0 raw 0x39dbc0 length 224 sha256 7a71b9bbf1416d69bc611aaf27ff9c2f69e7485d15c336a2b04f5e276b41db0e
0x79e7c0  55                               push   ebp
0x79e7c1  8bec                             mov    ebp,esp
0x79e7c3  6aff                             push   0xffffffff
0x79e7c5  68385f9100                       push   0x915f38
0x79e7ca  64a100000000                     mov    eax,fs:0x0
0x79e7d0  50                               push   eax
0x79e7d1  51                               push   ecx
0x79e7d2  53                               push   ebx
0x79e7d3  57                               push   edi
0x79e7d4  a1201fd600                       mov    eax,ds:0xd61f20
0x79e7d9  33c5                             xor    eax,ebp
0x79e7db  50                               push   eax
0x79e7dc  8d45f4                           lea    eax,[ebp-0xc]
0x79e7df  64a300000000                     mov    fs:0x0,eax
0x79e7e5  8d7e70                           lea    edi,[esi+0x70]
0x79e7e8  57                               push   edi
0x79e7e9  897df0                           mov    DWORD PTR [ebp-0x10],edi
0x79e7ec  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x79e7f2  33db                             xor    ebx,ebx
0x79e7f4  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x79e7f7  8b4e28                           mov    ecx,DWORD PTR [esi+0x28]
0x79e7fa  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
0x79e7fd  3bc8                             cmp    ecx,eax
0x79e7ff  751c                             jne    0x79e81d
0x79e801  57                               push   edi
0x79e802  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x79e808  32c0                             xor    al,al
0x79e80a  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x79e80d  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x79e814  59                               pop    ecx
0x79e815  5f                               pop    edi
0x79e816  5b                               pop    ebx
0x79e817  8be5                             mov    esp,ebp
0x79e819  5d                               pop    ebp
0x79e81a  c20400                           ret    0x4
0x79e81d  2bc1                             sub    eax,ecx
0x79e81f  c1f803                           sar    eax,0x3
0x79e822  85c0                             test   eax,eax
0x79e824  7420                             je     0x79e846
0x79e826  8b4628                           mov    eax,DWORD PTR [esi+0x28]
0x79e829  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x79e82c  8d0cd8                           lea    ecx,[eax+ebx*8]
0x79e82f  51                               push   ecx
0x79e830  e8eb290000                       call   0x7a1220
0x79e835  8b562c                           mov    edx,DWORD PTR [esi+0x2c]
0x79e838  2b5628                           sub    edx,DWORD PTR [esi+0x28]
0x79e83b  43                               inc    ebx
0x79e83c  c1fa03                           sar    edx,0x3
0x79e83f  3bda                             cmp    ebx,edx
0x79e841  72e3                             jb     0x79e826
0x79e843  8b7df0                           mov    edi,DWORD PTR [ebp-0x10]
0x79e846  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
0x79e849  8b4e28                           mov    ecx,DWORD PTR [esi+0x28]
0x79e84c  3bc8                             cmp    ecx,eax
0x79e84e  7425                             je     0x79e875
0x79e850  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x79e853  52                               push   edx
0x79e854  51                               push   ecx
0x79e855  50                               push   eax
0x79e856  e8c54e0000                       call   0x7a3720
0x79e85b  8b4e2c                           mov    ecx,DWORD PTR [esi+0x2c]
0x79e85e  8bd8                             mov    ebx,eax
0x79e860  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x79e863  83c40c                           add    esp,0xc
0x79e866  50                               push   eax
0x79e867  51                               push   ecx
0x79e868  8bc3                             mov    eax,ebx
0x79e86a  e8314f0000                       call   0x7a37a0
0x79e86f  83c408                           add    esp,0x8
0x79e872  895e2c                           mov    DWORD PTR [esi+0x2c],ebx
0x79e875  57                               push   edi
0x79e876  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x79e87c  b001                             mov    al,0x1
0x79e87e  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x79e881  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x79e888  59                               pop    ecx
0x79e889  5f                               pop    edi
0x79e88a  5b                               pop    ebx
0x79e88b  8be5                             mov    esp,ebp
0x79e88d  5d                               pop    ebp
0x79e88e  c20400                           ret    0x4
0x79e891  cc                               int3
0x79e892  cc                               int3
0x79e893  cc                               int3
0x79e894  cc                               int3
0x79e895  cc                               int3
0x79e896  cc                               int3
0x79e897  cc                               int3
0x79e898  cc                               int3
0x79e899  cc                               int3
0x79e89a  cc                               int3
0x79e89b  cc                               int3
0x79e89c  cc                               int3
0x79e89d  cc                               int3
0x79e89e  cc                               int3
0x79e89f  cc                               int3

; doll_worker_process | catalog gate, prepare, immediate apply or deferred result queue
; VA 0x79e980..0x79ed00 raw 0x39dd80 length 896 sha256 1a34d897d8d23c20412d41e0d0d53d63482a52cc1561408c6b5b841e5e1584e7
0x79e980  55                               push   ebp
0x79e981  8bec                             mov    ebp,esp
0x79e983  6aff                             push   0xffffffff
0x79e985  68338c9300                       push   0x938c33
0x79e98a  64a100000000                     mov    eax,fs:0x0
0x79e990  50                               push   eax
0x79e991  83ec30                           sub    esp,0x30
0x79e994  53                               push   ebx
0x79e995  56                               push   esi
0x79e996  57                               push   edi
0x79e997  a1201fd600                       mov    eax,ds:0xd61f20
0x79e99c  33c5                             xor    eax,ebp
0x79e99e  50                               push   eax
0x79e99f  8d45f4                           lea    eax,[ebp-0xc]
0x79e9a2  64a300000000                     mov    fs:0x0,eax
0x79e9a8  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x79e9ab  33f6                             xor    esi,esi
0x79e9ad  8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x79e9b0  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x79e9b3  8b08                             mov    ecx,DWORD PTR [eax]
0x79e9b5  8d55e8                           lea    edx,[ebp-0x18]
0x79e9b8  894de8                           mov    DWORD PTR [ebp-0x18],ecx
0x79e9bb  52                               push   edx
0x79e9bc  8d45e4                           lea    eax,[ebp-0x1c]
0x79e9bf  8bcb                             mov    ecx,ebx
0x79e9c1  e8ca6dd7ff                       call   0x515790
0x79e9c6  8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
0x79e9c9  3b4b04                           cmp    ecx,DWORD PTR [ebx+0x4]
0x79e9cc  7411                             je     0x79e9df
0x79e9ce  8b4110                           mov    eax,DWORD PTR [ecx+0x10]
0x79e9d1  8b7854                           mov    edi,DWORD PTR [eax+0x54]
0x79e9d4  897dec                           mov    DWORD PTR [ebp-0x14],edi
0x79e9d7  3bfe                             cmp    edi,esi
0x79e9d9  0f8509010000                     jne    0x79eae8
0x79e9df  6a28                             push   0x28
0x79e9e1  e882280f00                       call   0x891268
0x79e9e6  83c404                           add    esp,0x4
0x79e9e9  894508                           mov    DWORD PTR [ebp+0x8],eax
0x79e9ec  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x79e9f0  3bc6                             cmp    eax,esi
0x79e9f2  7408                             je     0x79e9fc
0x79e9f4  50                               push   eax
0x79e9f5  e896e4ffff                       call   0x79ce90
0x79e9fa  eb02                             jmp    0x79e9fe
0x79e9fc  33c0                             xor    eax,eax
0x79e9fe  50                               push   eax
0x79e9ff  8d45cc                           lea    eax,[ebp-0x34]
0x79ea02  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x79ea06  50                               push   eax
0x79ea07  8975cc                           mov    DWORD PTR [ebp-0x34],esi
0x79ea0a  8975d0                           mov    DWORD PTR [ebp-0x30],esi
0x79ea0d  e8ee490000                       call   0x7a3400
0x79ea12  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x79ea16  8b75cc                           mov    esi,DWORD PTR [ebp-0x34]
0x79ea19  8d7e08                           lea    edi,[esi+0x8]
0x79ea1c  8d450c                           lea    eax,[ebp+0xc]
0x79ea1f  c60600                           mov    BYTE PTR [esi],0x0
0x79ea22  e879230000                       call   0x7a0da0
0x79ea27  33c0                             xor    eax,eax
0x79ea29  894604                           mov    DWORD PTR [esi+0x4],eax
0x79ea2c  894610                           mov    DWORD PTR [esi+0x10],eax
0x79ea2f  894614                           mov    DWORD PTR [esi+0x14],eax
0x79ea32  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x79ea35  837970ff                         cmp    DWORD PTR [ecx+0x70],0xffffffff
0x79ea39  7443                             je     0x79ea7e
0x79ea3b  8b7dd0                           mov    edi,DWORD PTR [ebp-0x30]
0x79ea3e  83ec08                           sub    esp,0x8
0x79ea41  8bdc                             mov    ebx,esp
0x79ea43  896508                           mov    DWORD PTR [ebp+0x8],esp
0x79ea46  8903                             mov    DWORD PTR [ebx],eax
0x79ea48  894304                           mov    DWORD PTR [ebx+0x4],eax
0x79ea4b  85ff                             test   edi,edi
0x79ea4d  7414                             je     0x79ea63
0x79ea4f  8bd7                             mov    edx,edi
0x79ea51  e8fad7cdff                       call   0x47c250
0x79ea56  84c0                             test   al,al
0x79ea58  7409                             je     0x79ea63
0x79ea5a  57                               push   edi
0x79ea5b  56                               push   esi
0x79ea5c  8bf3                             mov    esi,ebx
0x79ea5e  e85d470000                       call   0x7a31c0
0x79ea63  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x79ea66  8b4268                           mov    eax,DWORD PTR [edx+0x68]
0x79ea69  50                               push   eax
0x79ea6a  e881a60000                       call   0x7a90f0
0x79ea6f  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x79ea72  8b4870                           mov    ecx,DWORD PTR [eax+0x70]
0x79ea75  51                               push   ecx
0x79ea76  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0x79ea7c  eb2d                             jmp    0x79eaab
0x79ea7e  8db398000000                     lea    esi,[ebx+0x98]
0x79ea84  56                               push   esi
0x79ea85  8975d8                           mov    DWORD PTR [ebp-0x28],esi
0x79ea88  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x79ea8e  81c388000000                     add    ebx,0x88
0x79ea94  53                               push   ebx
0x79ea95  8d4dcc                           lea    ecx,[ebp-0x34]
0x79ea98  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x79ea9c  e8bf240000                       call   0x7a0f60
0x79eaa1  56                               push   esi
0x79eaa2  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x79eaa8  8b7dd0                           mov    edi,DWORD PTR [ebp-0x30]
0x79eaab  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x79eaaf  85ff                             test   edi,edi
0x79eab1  0f84f7010000                     je     0x79ecae
0x79eab7  8d5704                           lea    edx,[edi+0x4]
0x79eaba  83c8ff                           or     eax,0xffffffff
0x79eabd  f00fc102                         lock xadd DWORD PTR [edx],eax
0x79eac1  0f85e7010000                     jne    0x79ecae
0x79eac7  8b17                             mov    edx,DWORD PTR [edi]
0x79eac9  8b02                             mov    eax,DWORD PTR [edx]
0x79eacb  8bcf                             mov    ecx,edi
0x79eacd  ffd0                             call   eax
0x79eacf  8d4f08                           lea    ecx,[edi+0x8]
0x79ead2  83caff                           or     edx,0xffffffff
0x79ead5  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x79ead9  0f85cf010000                     jne    0x79ecae
0x79eadf  8b07                             mov    eax,DWORD PTR [edi]
0x79eae1  8bcf                             mov    ecx,edi
0x79eae3  e9c1010000                       jmp    0x79eca9
0x79eae8  837f5010                         cmp    DWORD PTR [edi+0x50],0x10
0x79eaec  8d473c                           lea    eax,[edi+0x3c]
0x79eaef  7202                             jb     0x79eaf3
0x79eaf1  8b00                             mov    eax,DWORD PTR [eax]
0x79eaf3  8b4f5c                           mov    ecx,DWORD PTR [edi+0x5c]
0x79eaf6  41                               inc    ecx
0x79eaf7  51                               push   ecx
0x79eaf8  50                               push   eax
0x79eaf9  6824fec400                       push   0xc4fe24
0x79eafe  e8ba450f00                       call   0x8930bd
0x79eb03  ff475c                           inc    DWORD PTR [edi+0x5c]
0x79eb06  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x79eb09  83c40c                           add    esp,0xc
0x79eb0c  8d5048                           lea    edx,[eax+0x48]
0x79eb0f  52                               push   edx
0x79eb10  83c028                           add    eax,0x28
0x79eb13  50                               push   eax
0x79eb14  57                               push   edi
0x79eb15  e8a6100000                       call   0x79fbc0
0x79eb1a  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x79eb1d  8b404c                           mov    eax,DWORD PTR [eax+0x4c]
0x79eb20  8b30                             mov    esi,DWORD PTR [eax]
0x79eb22  83c40c                           add    esp,0xc
0x79eb25  3bf0                             cmp    esi,eax
0x79eb27  7466                             je     0x79eb8f
0x79eb29  8da42400000000                   lea    esp,[esp+0x0]
0x79eb30  0fb74e0e                         movzx  ecx,WORD PTR [esi+0xe]
0x79eb34  0fb7460c                         movzx  eax,WORD PTR [esi+0xc]
0x79eb38  6a01                             push   0x1
0x79eb3a  57                               push   edi
0x79eb3b  e810700200                       call   0x7c5b50
0x79eb40  807e1100                         cmp    BYTE PTR [esi+0x11],0x0
0x79eb44  7541                             jne    0x79eb87
0x79eb46  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x79eb49  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79eb4d  751d                             jne    0x79eb6c
0x79eb4f  8bf0                             mov    esi,eax
0x79eb51  8b06                             mov    eax,DWORD PTR [esi]
0x79eb53  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79eb57  752e                             jne    0x79eb87
0x79eb59  8da42400000000                   lea    esp,[esp+0x0]
0x79eb60  8bf0                             mov    esi,eax
0x79eb62  8b06                             mov    eax,DWORD PTR [esi]
0x79eb64  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79eb68  74f6                             je     0x79eb60
0x79eb6a  eb1b                             jmp    0x79eb87
0x79eb6c  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x79eb6f  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79eb73  7510                             jne    0x79eb85
0x79eb75  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x79eb78  750b                             jne    0x79eb85
0x79eb7a  8bf0                             mov    esi,eax
0x79eb7c  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x79eb7f  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79eb83  74f0                             je     0x79eb75
0x79eb85  8bf0                             mov    esi,eax
0x79eb87  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x79eb8a  3b714c                           cmp    esi,DWORD PTR [ecx+0x4c]
0x79eb8d  75a1                             jne    0x79eb30
0x79eb8f  83ec08                           sub    esp,0x8
0x79eb92  8bf4                             mov    esi,esp
0x79eb94  c70600000000                     mov    DWORD PTR [esi],0x0
0x79eb9a  c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x79eba1  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x79eba4  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x79eba7  8965d8                           mov    DWORD PTR [ebp-0x28],esp
0x79ebaa  8945e0                           mov    DWORD PTR [ebp-0x20],eax
0x79ebad  8955dc                           mov    DWORD PTR [ebp-0x24],edx
0x79ebb0  85c0                             test   eax,eax
0x79ebb2  7436                             je     0x79ebea
0x79ebb4  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0x79ebb7  8d5004                           lea    edx,[eax+0x4]
0x79ebba  85c9                             test   ecx,ecx
0x79ebbc  742c                             je     0x79ebea
0x79ebbe  8bff                             mov    edi,edi
0x79ebc0  8d7901                           lea    edi,[ecx+0x1]
0x79ebc3  8bda                             mov    ebx,edx
0x79ebc5  8bc1                             mov    eax,ecx
0x79ebc7  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
0x79ebcb  3bc1                             cmp    eax,ecx
0x79ebcd  7408                             je     0x79ebd7
0x79ebcf  8b0a                             mov    ecx,DWORD PTR [edx]
0x79ebd1  85c9                             test   ecx,ecx
0x79ebd3  75eb                             jne    0x79ebc0
0x79ebd5  eb0d                             jmp    0x79ebe4
0x79ebd7  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
0x79ebda  8b55dc                           mov    edx,DWORD PTR [ebp-0x24]
0x79ebdd  51                               push   ecx
0x79ebde  52                               push   edx
0x79ebdf  e8dc450000                       call   0x7a31c0
0x79ebe4  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x79ebe7  8b7dec                           mov    edi,DWORD PTR [ebp-0x14]
0x79ebea  8d45c4                           lea    eax,[ebp-0x3c]
0x79ebed  57                               push   edi
0x79ebee  50                               push   eax
0x79ebef  e8cc030000                       call   0x79efc0
0x79ebf4  83c410                           add    esp,0x10
0x79ebf7  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x79ebfb  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x79ebfe  837970ff                         cmp    DWORD PTR [ecx+0x70],0xffffffff
0x79ec02  744c                             je     0x79ec50
0x79ec04  83ec08                           sub    esp,0x8
0x79ec07  8bf4                             mov    esi,esp
0x79ec09  c70600000000                     mov    DWORD PTR [esi],0x0
0x79ec0f  c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x79ec16  8b55c8                           mov    edx,DWORD PTR [ebp-0x38]
0x79ec19  8b5dc4                           mov    ebx,DWORD PTR [ebp-0x3c]
0x79ec1c  896508                           mov    DWORD PTR [ebp+0x8],esp
0x79ec1f  8bfa                             mov    edi,edx
0x79ec21  85d2                             test   edx,edx
0x79ec23  7410                             je     0x79ec35
0x79ec25  e826d6cdff                       call   0x47c250
0x79ec2a  84c0                             test   al,al
0x79ec2c  7407                             je     0x79ec35
0x79ec2e  57                               push   edi
0x79ec2f  53                               push   ebx
0x79ec30  e88b450000                       call   0x7a31c0
0x79ec35  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x79ec38  8b4268                           mov    eax,DWORD PTR [edx+0x68]
0x79ec3b  50                               push   eax
0x79ec3c  e8afa40000                       call   0x7a90f0
0x79ec41  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x79ec44  8b4870                           mov    ecx,DWORD PTR [eax+0x70]
0x79ec47  51                               push   ecx
0x79ec48  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0x79ec4e  eb2a                             jmp    0x79ec7a
0x79ec50  8db398000000                     lea    esi,[ebx+0x98]
0x79ec56  56                               push   esi
0x79ec57  8975d4                           mov    DWORD PTR [ebp-0x2c],esi
0x79ec5a  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x79ec60  81c388000000                     add    ebx,0x88
0x79ec66  53                               push   ebx
0x79ec67  8d4dc4                           lea    ecx,[ebp-0x3c]
0x79ec6a  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x79ec6e  e8ed220000                       call   0x7a0f60
0x79ec73  56                               push   esi
0x79ec74  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x79ec7a  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x79ec7e  8b75c8                           mov    esi,DWORD PTR [ebp-0x38]
0x79ec81  85f6                             test   esi,esi
0x79ec83  7429                             je     0x79ecae
0x79ec85  8d5604                           lea    edx,[esi+0x4]
0x79ec88  83c8ff                           or     eax,0xffffffff
0x79ec8b  f00fc102                         lock xadd DWORD PTR [edx],eax
0x79ec8f  751d                             jne    0x79ecae
0x79ec91  8b16                             mov    edx,DWORD PTR [esi]
0x79ec93  8b02                             mov    eax,DWORD PTR [edx]
0x79ec95  8bce                             mov    ecx,esi
0x79ec97  ffd0                             call   eax
0x79ec99  8d4e08                           lea    ecx,[esi+0x8]
0x79ec9c  83caff                           or     edx,0xffffffff
0x79ec9f  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x79eca3  7509                             jne    0x79ecae
0x79eca5  8b06                             mov    eax,DWORD PTR [esi]
0x79eca7  8bce                             mov    ecx,esi
0x79eca9  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x79ecac  ffd2                             call   edx
0x79ecae  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x79ecb5  8b7510                           mov    esi,DWORD PTR [ebp+0x10]
0x79ecb8  85f6                             test   esi,esi
0x79ecba  7429                             je     0x79ece5
0x79ecbc  83c9ff                           or     ecx,0xffffffff
0x79ecbf  8d4604                           lea    eax,[esi+0x4]
0x79ecc2  f00fc108                         lock xadd DWORD PTR [eax],ecx
0x79ecc6  751d                             jne    0x79ece5
0x79ecc8  8b16                             mov    edx,DWORD PTR [esi]
0x79ecca  8b02                             mov    eax,DWORD PTR [edx]
0x79eccc  8bce                             mov    ecx,esi
0x79ecce  ffd0                             call   eax
0x79ecd0  83caff                           or     edx,0xffffffff
0x79ecd3  8d4e08                           lea    ecx,[esi+0x8]
0x79ecd6  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x79ecda  7509                             jne    0x79ece5
0x79ecdc  8b06                             mov    eax,DWORD PTR [esi]
0x79ecde  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x79ece1  8bce                             mov    ecx,esi
0x79ece3  ffd2                             call   edx
0x79ece5  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x79ece8  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x79ecef  59                               pop    ecx
0x79ecf0  5f                               pop    edi
0x79ecf1  5e                               pop    esi
0x79ecf2  5b                               pop    ebx
0x79ecf3  8be5                             mov    esp,ebp
0x79ecf5  5d                               pop    ebp
0x79ecf6  c3                               ret
0x79ecf7  cc                               int3
0x79ecf8  cc                               int3
0x79ecf9  cc                               int3
0x79ecfa  cc                               int3
0x79ecfb  cc                               int3
0x79ecfc  cc                               int3
0x79ecfd  cc                               int3
0x79ecfe  cc                               int3
0x79ecff  cc                               int3

; doll_prepare_avatar_items | packed part/variant -> model avatar descriptors; combine requested attachments
; VA 0x79fbc0..0x7a03b0 raw 0x39efc0 length 2032 sha256 0a592acc6708d3938b45537371b4cba9f7499d4489612461d437f2841d36e723
0x79fbc0  55                               push   ebp
0x79fbc1  8bec                             mov    ebp,esp
0x79fbc3  6aff                             push   0xffffffff
0x79fbc5  680e8f9100                       push   0x918f0e
0x79fbca  64a100000000                     mov    eax,fs:0x0
0x79fbd0  50                               push   eax
0x79fbd1  83ec78                           sub    esp,0x78
0x79fbd4  53                               push   ebx
0x79fbd5  56                               push   esi
0x79fbd6  57                               push   edi
0x79fbd7  a1201fd600                       mov    eax,ds:0xd61f20
0x79fbdc  33c5                             xor    eax,ebp
0x79fbde  50                               push   eax
0x79fbdf  8d45f4                           lea    eax,[ebp-0xc]
0x79fbe2  64a300000000                     mov    fs:0x0,eax
0x79fbe8  8b7d10                           mov    edi,DWORD PTR [ebp+0x10]
0x79fbeb  8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
0x79fbee  3bfb                             cmp    edi,ebx
0x79fbf0  7419                             je     0x79fc0b
0x79fbf2  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x79fbf5  8b08                             mov    ecx,DWORD PTR [eax]
0x79fbf7  50                               push   eax
0x79fbf8  51                               push   ecx
0x79fbf9  8d75d4                           lea    esi,[ebp-0x2c]
0x79fbfc  8bc7                             mov    eax,edi
0x79fbfe  e85da5d2ff                       call   0x4ca160
0x79fc03  53                               push   ebx
0x79fc04  8bc7                             mov    eax,edi
0x79fc06  e835190000                       call   0x7a1540
0x79fc0b  8d4310                           lea    eax,[ebx+0x10]
0x79fc0e  83c710                           add    edi,0x10
0x79fc11  3bf8                             cmp    edi,eax
0x79fc13  741c                             je     0x79fc31
0x79fc15  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x79fc18  8b08                             mov    ecx,DWORD PTR [eax]
0x79fc1a  50                               push   eax
0x79fc1b  51                               push   ecx
0x79fc1c  8d75d4                           lea    esi,[ebp-0x2c]
0x79fc1f  8bc7                             mov    eax,edi
0x79fc21  e8fa74f3ff                       call   0x6d7120
0x79fc26  8d4310                           lea    eax,[ebx+0x10]
0x79fc29  50                               push   eax
0x79fc2a  8bc7                             mov    eax,edi
0x79fc2c  e82f1a0000                       call   0x7a1660
0x79fc31  33f6                             xor    esi,esi
0x79fc33  6a28                             push   0x28
0x79fc35  897594                           mov    DWORD PTR [ebp-0x6c],esi
0x79fc38  e82b160f00                       call   0x891268
0x79fc3d  83c404                           add    esp,0x4
0x79fc40  3bc6                             cmp    eax,esi
0x79fc42  0f8436070000                     je     0x7a037e
0x79fc48  894590                           mov    DWORD PTR [ebp-0x70],eax
0x79fc4b  8900                             mov    DWORD PTR [eax],eax
0x79fc4d  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
0x79fc50  894004                           mov    DWORD PTR [eax+0x4],eax
0x79fc53  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
0x79fc56  894008                           mov    DWORD PTR [eax+0x8],eax
0x79fc59  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
0x79fc5c  c6402001                         mov    BYTE PTR [eax+0x20],0x1
0x79fc60  8b4d90                           mov    ecx,DWORD PTR [ebp-0x70]
0x79fc63  c6412101                         mov    BYTE PTR [ecx+0x21],0x1
0x79fc67  8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x79fc6a  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x79fc6d  8b30                             mov    esi,DWORD PTR [eax]
0x79fc6f  8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x79fc72  3bf0                             cmp    esi,eax
0x79fc74  0f845e010000                     je     0x79fdd8
0x79fc7a  8d9b00000000                     lea    ebx,[ebx+0x0]
0x79fc80  0fb7560c                         movzx  edx,WORD PTR [esi+0xc]
0x79fc84  0fb7460e                         movzx  eax,WORD PTR [esi+0xe]
0x79fc88  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x79fc8b  c1e210                           shl    edx,0x10
0x79fc8e  8d4de8                           lea    ecx,[ebp-0x18]
0x79fc91  0bd0                             or     edx,eax
0x79fc93  51                               push   ecx
0x79fc94  8d45e4                           lea    eax,[ebp-0x1c]
0x79fc97  8d8fb4000000                     lea    ecx,[edi+0xb4]
0x79fc9d  8955e8                           mov    DWORD PTR [ebp-0x18],edx
0x79fca0  e85bf20800                       call   0x82ef00
0x79fca5  8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
0x79fca8  3b8fb8000000                     cmp    ecx,DWORD PTR [edi+0xb8]
0x79fcae  0f84d5000000                     je     0x79fd89
0x79fcb4  8b4910                           mov    ecx,DWORD PTR [ecx+0x10]
0x79fcb7  894ddc                           mov    DWORD PTR [ebp-0x24],ecx
0x79fcba  85c9                             test   ecx,ecx
0x79fcbc  0f84c7000000                     je     0x79fd89
0x79fcc2  8b5938                           mov    ebx,DWORD PTR [ecx+0x38]
0x79fcc5  3b593c                           cmp    ebx,DWORD PTR [ecx+0x3c]
0x79fcc8  0f84bb000000                     je     0x79fd89
0x79fcce  8bff                             mov    edi,edi
0x79fcd0  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x79fcd7  8b3b                             mov    edi,DWORD PTR [ebx]
0x79fcd9  8b5304                           mov    edx,DWORD PTR [ebx+0x4]
0x79fcdc  897dcc                           mov    DWORD PTR [ebp-0x34],edi
0x79fcdf  8955d0                           mov    DWORD PTR [ebp-0x30],edx
0x79fce2  7521                             jne    0x79fd05
0x79fce4  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x79fceb  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x79fcef  e80cf20100                       call   0x7bef00
0x79fcf4  6850ecbc00                       push   0xbcec50
0x79fcf9  e81c260f00                       call   0x89231a
0x79fcfe  83c404                           add    esp,0x4
0x79fd01  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x79fd05  8b45d0                           mov    eax,DWORD PTR [ebp-0x30]
0x79fd08  8d4dc4                           lea    ecx,[ebp-0x3c]
0x79fd0b  51                               push   ecx
0x79fd0c  8d55e0                           lea    edx,[ebp-0x20]
0x79fd0f  52                               push   edx
0x79fd10  68601bfe00                       push   0xfe1b60
0x79fd15  897dc4                           mov    DWORD PTR [ebp-0x3c],edi
0x79fd18  8945c8                           mov    DWORD PTR [ebp-0x38],eax
0x79fd1b  e8e0d6d3ff                       call   0x4dd400
0x79fd20  8b45e0                           mov    eax,DWORD PTR [ebp-0x20]
0x79fd23  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
0x79fd29  744f                             je     0x79fd7a
0x79fd2b  8b4018                           mov    eax,DWORD PTR [eax+0x18]
0x79fd2e  85c0                             test   eax,eax
0x79fd30  7448                             je     0x79fd7a
0x79fd32  8b7820                           mov    edi,DWORD PTR [eax+0x20]
0x79fd35  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x79fd38  8b7114                           mov    esi,DWORD PTR [ecx+0x14]
0x79fd3b  8d45e8                           lea    eax,[ebp-0x18]
0x79fd3e  50                               push   eax
0x79fd3f  8d45d4                           lea    eax,[ebp-0x2c]
0x79fd42  83c110                           add    ecx,0x10
0x79fd45  897de8                           mov    DWORD PTR [ebp-0x18],edi
0x79fd48  e8b30e0000                       call   0x7a0c00
0x79fd4d  3930                             cmp    DWORD PTR [eax],esi
0x79fd4f  7526                             jne    0x79fd77
0x79fd51  8b4dcc                           mov    ecx,DWORD PTR [ebp-0x34]
0x79fd54  8b55d0                           mov    edx,DWORD PTR [ebp-0x30]
0x79fd57  897dac                           mov    DWORD PTR [ebp-0x54],edi
0x79fd5a  8d7dac                           lea    edi,[ebp-0x54]
0x79fd5d  8d758c                           lea    esi,[ebp-0x74]
0x79fd60  894db4                           mov    DWORD PTR [ebp-0x4c],ecx
0x79fd63  8955b8                           mov    DWORD PTR [ebp-0x48],edx
0x79fd66  e885280000                       call   0x7a25f0
0x79fd6b  50                               push   eax
0x79fd6c  8bc6                             mov    eax,esi
0x79fd6e  50                               push   eax
0x79fd6f  8d75bc                           lea    esi,[ebp-0x44]
0x79fd72  e8992a0000                       call   0x7a2810
0x79fd77  8b75ec                           mov    esi,DWORD PTR [ebp-0x14]
0x79fd7a  8b4ddc                           mov    ecx,DWORD PTR [ebp-0x24]
0x79fd7d  83c308                           add    ebx,0x8
0x79fd80  3b593c                           cmp    ebx,DWORD PTR [ecx+0x3c]
0x79fd83  0f8547ffffff                     jne    0x79fcd0
0x79fd89  807e1100                         cmp    BYTE PTR [esi+0x11],0x0
0x79fd8d  753d                             jne    0x79fdcc
0x79fd8f  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
0x79fd92  80791100                         cmp    BYTE PTR [ecx+0x11],0x0
0x79fd96  7516                             jne    0x79fdae
0x79fd98  8b01                             mov    eax,DWORD PTR [ecx]
0x79fd9a  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79fd9e  750a                             jne    0x79fdaa
0x79fda0  8bc8                             mov    ecx,eax
0x79fda2  8b01                             mov    eax,DWORD PTR [ecx]
0x79fda4  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79fda8  74f6                             je     0x79fda0
0x79fdaa  8bf1                             mov    esi,ecx
0x79fdac  eb1b                             jmp    0x79fdc9
0x79fdae  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x79fdb1  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79fdb5  7510                             jne    0x79fdc7
0x79fdb7  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x79fdba  750b                             jne    0x79fdc7
0x79fdbc  8bf0                             mov    esi,eax
0x79fdbe  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x79fdc1  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x79fdc5  74f0                             je     0x79fdb7
0x79fdc7  8bf0                             mov    esi,eax
0x79fdc9  8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x79fdcc  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x79fdcf  3b7204                           cmp    esi,DWORD PTR [edx+0x4]
0x79fdd2  0f85a8feffff                     jne    0x79fc80
0x79fdd8  33f6                             xor    esi,esi
0x79fdda  6a14                             push   0x14
0x79fddc  897584                           mov    DWORD PTR [ebp-0x7c],esi
0x79fddf  e884140f00                       call   0x891268
0x79fde4  83c404                           add    esp,0x4
0x79fde7  3bc6                             cmp    eax,esi
0x79fde9  0f846b050000                     je     0x7a035a
0x79fdef  894580                           mov    DWORD PTR [ebp-0x80],eax
0x79fdf2  8900                             mov    DWORD PTR [eax],eax
0x79fdf4  8b4580                           mov    eax,DWORD PTR [ebp-0x80]
0x79fdf7  894004                           mov    DWORD PTR [eax+0x4],eax
0x79fdfa  8b4580                           mov    eax,DWORD PTR [ebp-0x80]
0x79fdfd  894008                           mov    DWORD PTR [eax+0x8],eax
0x79fe00  8b4580                           mov    eax,DWORD PTR [ebp-0x80]
0x79fe03  c6401001                         mov    BYTE PTR [eax+0x10],0x1
0x79fe07  8b4d80                           mov    ecx,DWORD PTR [ebp-0x80]
0x79fe0a  c6411101                         mov    BYTE PTR [ecx+0x11],0x1
0x79fe0e  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x79fe12  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x79fe15  8b4214                           mov    eax,DWORD PTR [edx+0x14]
0x79fe18  8b30                             mov    esi,DWORD PTR [eax]
0x79fe1a  3bf0                             cmp    esi,eax
0x79fe1c  0f84f4000000                     je     0x79ff16
0x79fe22  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x79fe29  8b5e18                           mov    ebx,DWORD PTR [esi+0x18]
0x79fe2c  8b7e1c                           mov    edi,DWORD PTR [esi+0x1c]
0x79fe2f  7521                             jne    0x79fe52
0x79fe31  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x79fe38  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x79fe3c  e8bff00100                       call   0x7bef00
0x79fe41  6850ecbc00                       push   0xbcec50
0x79fe46  e8cf240f00                       call   0x89231a
0x79fe4b  83c404                           add    esp,0x4
0x79fe4e  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x79fe52  8d55c4                           lea    edx,[ebp-0x3c]
0x79fe55  b8a01bfe00                       mov    eax,0xfe1ba0
0x79fe5a  895dc4                           mov    DWORD PTR [ebp-0x3c],ebx
0x79fe5d  897dc8                           mov    DWORD PTR [ebp-0x38],edi
0x79fe60  e8db020200                       call   0x7c0140
0x79fe65  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x79fe6c  0fb700                           movzx  eax,WORD PTR [eax]
0x79fe6f  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x79fe72  7521                             jne    0x79fe95
0x79fe74  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x79fe7b  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x79fe7f  e87cf00100                       call   0x7bef00
0x79fe84  6850ecbc00                       push   0xbcec50
0x79fe89  e88c240f00                       call   0x89231a
0x79fe8e  83c404                           add    esp,0x4
0x79fe91  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x79fe95  8d55cc                           lea    edx,[ebp-0x34]
0x79fe98  b8901bfe00                       mov    eax,0xfe1b90
0x79fe9d  895dcc                           mov    DWORD PTR [ebp-0x34],ebx
0x79fea0  897dd0                           mov    DWORD PTR [ebp-0x30],edi
0x79fea3  e898020200                       call   0x7c0140
0x79fea8  66837dec00                       cmp    WORD PTR [ebp-0x14],0x0
0x79fead  0fb708                           movzx  ecx,WORD PTR [eax]
0x79feb0  894ddc                           mov    DWORD PTR [ebp-0x24],ecx
0x79feb3  7415                             je     0x79feca
0x79feb5  8d55dc                           lea    edx,[ebp-0x24]
0x79feb8  8d857cffffff                     lea    eax,[ebp-0x84]
0x79febe  e8cd0b0000                       call   0x7a0a90
0x79fec3  668b55ec                         mov    dx,WORD PTR [ebp-0x14]
0x79fec7  668910                           mov    WORD PTR [eax],dx
0x79feca  807e2100                         cmp    BYTE PTR [esi+0x21],0x0
0x79fece  753a                             jne    0x79ff0a
0x79fed0  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x79fed3  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79fed7  7516                             jne    0x79feef
0x79fed9  8bf0                             mov    esi,eax
0x79fedb  8b06                             mov    eax,DWORD PTR [esi]
0x79fedd  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79fee1  7527                             jne    0x79ff0a
0x79fee3  8bf0                             mov    esi,eax
0x79fee5  8b06                             mov    eax,DWORD PTR [esi]
0x79fee7  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79feeb  74f6                             je     0x79fee3
0x79feed  eb1b                             jmp    0x79ff0a
0x79feef  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x79fef2  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79fef6  7510                             jne    0x79ff08
0x79fef8  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x79fefb  750b                             jne    0x79ff08
0x79fefd  8bf0                             mov    esi,eax
0x79feff  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x79ff02  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79ff06  74f0                             je     0x79fef8
0x79ff08  8bf0                             mov    esi,eax
0x79ff0a  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x79ff0d  3b7014                           cmp    esi,DWORD PTR [eax+0x14]
0x79ff10  0f850cffffff                     jne    0x79fe22
0x79ff16  8b7d80                           mov    edi,DWORD PTR [ebp-0x80]
0x79ff19  8b0f                             mov    ecx,DWORD PTR [edi]
0x79ff1b  894dec                           mov    DWORD PTR [ebp-0x14],ecx
0x79ff1e  3bcf                             cmp    ecx,edi
0x79ff20  0f84b6010000                     je     0x7a00dc
0x79ff26  eb0b                             jmp    0x79ff33
0x79ff28  eb06                             jmp    0x79ff30
0x79ff2a  8d9b00000000                     lea    ebx,[ebx+0x0]
0x79ff30  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0x79ff33  0fb7510e                         movzx  edx,WORD PTR [ecx+0xe]
0x79ff37  0fb7490c                         movzx  ecx,WORD PTR [ecx+0xc]
0x79ff3b  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x79ff3e  c1e110                           shl    ecx,0x10
0x79ff41  0bca                             or     ecx,edx
0x79ff43  8b96b8000000                     mov    edx,DWORD PTR [esi+0xb8]
0x79ff49  8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x79ff4c  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x79ff50  7514                             jne    0x79ff66
0x79ff52  39480c                           cmp    DWORD PTR [eax+0xc],ecx
0x79ff55  7305                             jae    0x79ff5c
0x79ff57  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x79ff5a  eb04                             jmp    0x79ff60
0x79ff5c  8bd0                             mov    edx,eax
0x79ff5e  8b00                             mov    eax,DWORD PTR [eax]
0x79ff60  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x79ff64  74ec                             je     0x79ff52
0x79ff66  8b86b8000000                     mov    eax,DWORD PTR [esi+0xb8]
0x79ff6c  8955dc                           mov    DWORD PTR [ebp-0x24],edx
0x79ff6f  3bd0                             cmp    edx,eax
0x79ff71  740a                             je     0x79ff7d
0x79ff73  3b4a0c                           cmp    ecx,DWORD PTR [edx+0xc]
0x79ff76  7205                             jb     0x79ff7d
0x79ff78  8d45dc                           lea    eax,[ebp-0x24]
0x79ff7b  eb06                             jmp    0x79ff83
0x79ff7d  8945e0                           mov    DWORD PTR [ebp-0x20],eax
0x79ff80  8d45e0                           lea    eax,[ebp-0x20]
0x79ff83  8b00                             mov    eax,DWORD PTR [eax]
0x79ff85  3b86b8000000                     cmp    eax,DWORD PTR [esi+0xb8]
0x79ff8b  0f84f9000000                     je     0x7a008a
0x79ff91  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x79ff94  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x79ff97  85c0                             test   eax,eax
0x79ff99  0f84eb000000                     je     0x7a008a
0x79ff9f  8b5838                           mov    ebx,DWORD PTR [eax+0x38]
0x79ffa2  3b583c                           cmp    ebx,DWORD PTR [eax+0x3c]
0x79ffa5  0f84df000000                     je     0x7a008a
0x79ffab  eb03                             jmp    0x79ffb0
0x79ffad  8d4900                           lea    ecx,[ecx+0x0]
0x79ffb0  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x79ffb7  8b7304                           mov    esi,DWORD PTR [ebx+0x4]
0x79ffba  8b3b                             mov    edi,DWORD PTR [ebx]
0x79ffbc  8975d0                           mov    DWORD PTR [ebp-0x30],esi
0x79ffbf  7521                             jne    0x79ffe2
0x79ffc1  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x79ffc8  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x79ffcc  e82fef0100                       call   0x7bef00
0x79ffd1  6850ecbc00                       push   0xbcec50
0x79ffd6  e83f230f00                       call   0x89231a
0x79ffdb  83c404                           add    esp,0x4
0x79ffde  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x79ffe2  8d45c4                           lea    eax,[ebp-0x3c]
0x79ffe5  50                               push   eax
0x79ffe6  8d4de4                           lea    ecx,[ebp-0x1c]
0x79ffe9  51                               push   ecx
0x79ffea  68601bfe00                       push   0xfe1b60
0x79ffef  897dc4                           mov    DWORD PTR [ebp-0x3c],edi
0x79fff2  8975c8                           mov    DWORD PTR [ebp-0x38],esi
0x79fff5  e806d4d3ff                       call   0x4dd400
0x79fffa  8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
0x79fffd  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
0x7a0003  7473                             je     0x7a0078
0x7a0005  8b4018                           mov    eax,DWORD PTR [eax+0x18]
0x7a0008  85c0                             test   eax,eax
0x7a000a  746c                             je     0x7a0078
0x7a000c  8b5020                           mov    edx,DWORD PTR [eax+0x20]
0x7a000f  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x7a0012  8b7014                           mov    esi,DWORD PTR [eax+0x14]
0x7a0015  8bce                             mov    ecx,esi
0x7a0017  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x7a001a  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a001e  7514                             jne    0x7a0034
0x7a0020  395010                           cmp    DWORD PTR [eax+0x10],edx
0x7a0023  7305                             jae    0x7a002a
0x7a0025  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x7a0028  eb04                             jmp    0x7a002e
0x7a002a  8bc8                             mov    ecx,eax
0x7a002c  8b00                             mov    eax,DWORD PTR [eax]
0x7a002e  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a0032  74ec                             je     0x7a0020
0x7a0034  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x7a0037  8b4014                           mov    eax,DWORD PTR [eax+0x14]
0x7a003a  894ddc                           mov    DWORD PTR [ebp-0x24],ecx
0x7a003d  3bc8                             cmp    ecx,eax
0x7a003f  740a                             je     0x7a004b
0x7a0041  3b5110                           cmp    edx,DWORD PTR [ecx+0x10]
0x7a0044  7205                             jb     0x7a004b
0x7a0046  8d45dc                           lea    eax,[ebp-0x24]
0x7a0049  eb06                             jmp    0x7a0051
0x7a004b  8945d8                           mov    DWORD PTR [ebp-0x28],eax
0x7a004e  8d45d8                           lea    eax,[ebp-0x28]
0x7a0051  3930                             cmp    DWORD PTR [eax],esi
0x7a0053  7523                             jne    0x7a0078
0x7a0055  89559c                           mov    DWORD PTR [ebp-0x64],edx
0x7a0058  8b55d0                           mov    edx,DWORD PTR [ebp-0x30]
0x7a005b  897da4                           mov    DWORD PTR [ebp-0x5c],edi
0x7a005e  8d7d9c                           lea    edi,[ebp-0x64]
0x7a0061  8d758c                           lea    esi,[ebp-0x74]
0x7a0064  8955a8                           mov    DWORD PTR [ebp-0x58],edx
0x7a0067  e884250000                       call   0x7a25f0
0x7a006c  50                               push   eax
0x7a006d  8bc6                             mov    eax,esi
0x7a006f  50                               push   eax
0x7a0070  8d75bc                           lea    esi,[ebp-0x44]
0x7a0073  e898270000                       call   0x7a2810
0x7a0078  8b4de8                           mov    ecx,DWORD PTR [ebp-0x18]
0x7a007b  83c308                           add    ebx,0x8
0x7a007e  3b593c                           cmp    ebx,DWORD PTR [ecx+0x3c]
0x7a0081  0f8529ffffff                     jne    0x79ffb0
0x7a0087  8b7d80                           mov    edi,DWORD PTR [ebp-0x80]
0x7a008a  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
0x7a008d  807a1100                         cmp    BYTE PTR [edx+0x11],0x0
0x7a0091  7540                             jne    0x7a00d3
0x7a0093  8b4a08                           mov    ecx,DWORD PTR [edx+0x8]
0x7a0096  80791100                         cmp    BYTE PTR [ecx+0x11],0x0
0x7a009a  7517                             jne    0x7a00b3
0x7a009c  8b01                             mov    eax,DWORD PTR [ecx]
0x7a009e  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a00a2  750a                             jne    0x7a00ae
0x7a00a4  8bc8                             mov    ecx,eax
0x7a00a6  8b01                             mov    eax,DWORD PTR [ecx]
0x7a00a8  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a00ac  74f6                             je     0x7a00a4
0x7a00ae  894dec                           mov    DWORD PTR [ebp-0x14],ecx
0x7a00b1  eb20                             jmp    0x7a00d3
0x7a00b3  8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x7a00b6  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a00ba  7514                             jne    0x7a00d0
0x7a00bc  8d642400                         lea    esp,[esp+0x0]
0x7a00c0  3b5008                           cmp    edx,DWORD PTR [eax+0x8]
0x7a00c3  750b                             jne    0x7a00d0
0x7a00c5  8bd0                             mov    edx,eax
0x7a00c7  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x7a00ca  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a00ce  74f0                             je     0x7a00c0
0x7a00d0  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x7a00d3  397dec                           cmp    DWORD PTR [ebp-0x14],edi
0x7a00d6  0f8554feffff                     jne    0x79ff30
0x7a00dc  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
0x7a00df  8b30                             mov    esi,DWORD PTR [eax]
0x7a00e1  3bf0                             cmp    esi,eax
0x7a00e3  0f84fc000000                     je     0x7a01e5
0x7a00e9  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x7a00f0  8b7e18                           mov    edi,DWORD PTR [esi+0x18]
0x7a00f3  8b5e1c                           mov    ebx,DWORD PTR [esi+0x1c]
0x7a00f6  7521                             jne    0x7a0119
0x7a00f8  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x7a00ff  c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
0x7a0103  e8f8ed0100                       call   0x7bef00
0x7a0108  6850ecbc00                       push   0xbcec50
0x7a010d  e808220f00                       call   0x89231a
0x7a0112  83c404                           add    esp,0x4
0x7a0115  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x7a0119  8d55c4                           lea    edx,[ebp-0x3c]
0x7a011c  b8a01bfe00                       mov    eax,0xfe1ba0
0x7a0121  897dc4                           mov    DWORD PTR [ebp-0x3c],edi
0x7a0124  895dc8                           mov    DWORD PTR [ebp-0x38],ebx
0x7a0127  e814000200                       call   0x7c0140
0x7a012c  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x7a0133  0fb700                           movzx  eax,WORD PTR [eax]
0x7a0136  89450c                           mov    DWORD PTR [ebp+0xc],eax
0x7a0139  7521                             jne    0x7a015c
0x7a013b  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x7a0142  c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
0x7a0146  e8b5ed0100                       call   0x7bef00
0x7a014b  6850ecbc00                       push   0xbcec50
0x7a0150  e8c5210f00                       call   0x89231a
0x7a0155  83c404                           add    esp,0x4
0x7a0158  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x7a015c  8d55cc                           lea    edx,[ebp-0x34]
0x7a015f  b8901bfe00                       mov    eax,0xfe1b90
0x7a0164  897dcc                           mov    DWORD PTR [ebp-0x34],edi
0x7a0167  895dd0                           mov    DWORD PTR [ebp-0x30],ebx
0x7a016a  e8d1ff0100                       call   0x7c0140
0x7a016f  66837d0c00                       cmp    WORD PTR [ebp+0xc],0x0
0x7a0174  0fb708                           movzx  ecx,WORD PTR [eax]
0x7a0177  894dd8                           mov    DWORD PTR [ebp-0x28],ecx
0x7a017a  7415                             je     0x7a0191
0x7a017c  8d55d8                           lea    edx,[ebp-0x28]
0x7a017f  8d857cffffff                     lea    eax,[ebp-0x84]
0x7a0185  e806090000                       call   0x7a0a90
0x7a018a  668b550c                         mov    dx,WORD PTR [ebp+0xc]
0x7a018e  668910                           mov    WORD PTR [eax],dx
0x7a0191  807e2100                         cmp    BYTE PTR [esi+0x21],0x0
0x7a0195  7540                             jne    0x7a01d7
0x7a0197  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x7a019a  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a019e  751c                             jne    0x7a01bc
0x7a01a0  8bf0                             mov    esi,eax
0x7a01a2  8b06                             mov    eax,DWORD PTR [esi]
0x7a01a4  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a01a8  752d                             jne    0x7a01d7
0x7a01aa  8d9b00000000                     lea    ebx,[ebx+0x0]
0x7a01b0  8bf0                             mov    esi,eax
0x7a01b2  8b06                             mov    eax,DWORD PTR [esi]
0x7a01b4  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a01b8  74f6                             je     0x7a01b0
0x7a01ba  eb1b                             jmp    0x7a01d7
0x7a01bc  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x7a01bf  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a01c3  7510                             jne    0x7a01d5
0x7a01c5  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x7a01c8  750b                             jne    0x7a01d5
0x7a01ca  8bf0                             mov    esi,eax
0x7a01cc  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x7a01cf  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a01d3  74f0                             je     0x7a01c5
0x7a01d5  8bf0                             mov    esi,eax
0x7a01d7  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
0x7a01da  3bf0                             cmp    esi,eax
0x7a01dc  0f8507ffffff                     jne    0x7a00e9
0x7a01e2  8b7d80                           mov    edi,DWORD PTR [ebp-0x80]
0x7a01e5  8b37                             mov    esi,DWORD PTR [edi]
0x7a01e7  8b5d10                           mov    ebx,DWORD PTR [ebp+0x10]
0x7a01ea  3bf7                             cmp    esi,edi
0x7a01ec  7461                             je     0x7a024f
0x7a01ee  8bff                             mov    edi,edi
0x7a01f0  8d560c                           lea    edx,[esi+0xc]
0x7a01f3  8bc3                             mov    eax,ebx
0x7a01f5  e896080000                       call   0x7a0a90
0x7a01fa  668b4e0e                         mov    cx,WORD PTR [esi+0xe]
0x7a01fe  668908                           mov    WORD PTR [eax],cx
0x7a0201  807e1100                         cmp    BYTE PTR [esi+0x11],0x0
0x7a0205  7540                             jne    0x7a0247
0x7a0207  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x7a020a  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a020e  751c                             jne    0x7a022c
0x7a0210  8bf0                             mov    esi,eax
0x7a0212  8b06                             mov    eax,DWORD PTR [esi]
0x7a0214  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a0218  752d                             jne    0x7a0247
0x7a021a  8d9b00000000                     lea    ebx,[ebx+0x0]
0x7a0220  8bf0                             mov    esi,eax
0x7a0222  8b06                             mov    eax,DWORD PTR [esi]
0x7a0224  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a0228  74f6                             je     0x7a0220
0x7a022a  eb1b                             jmp    0x7a0247
0x7a022c  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x7a022f  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a0233  7510                             jne    0x7a0245
0x7a0235  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x7a0238  750b                             jne    0x7a0245
0x7a023a  8bf0                             mov    esi,eax
0x7a023c  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x7a023f  80781100                         cmp    BYTE PTR [eax+0x11],0x0
0x7a0243  74f0                             je     0x7a0235
0x7a0245  8bf0                             mov    esi,eax
0x7a0247  3b7580                           cmp    esi,DWORD PTR [ebp-0x80]
0x7a024a  75a4                             jne    0x7a01f0
0x7a024c  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
0x7a024f  8b30                             mov    esi,DWORD PTR [eax]
0x7a0251  3bf0                             cmp    esi,eax
0x7a0253  7462                             je     0x7a02b7
0x7a0255  8d4610                           lea    eax,[esi+0x10]
0x7a0258  8d4b10                           lea    ecx,[ebx+0x10]
0x7a025b  e820090000                       call   0x7a0b80
0x7a0260  8b5618                           mov    edx,DWORD PTR [esi+0x18]
0x7a0263  8910                             mov    DWORD PTR [eax],edx
0x7a0265  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
0x7a0268  894804                           mov    DWORD PTR [eax+0x4],ecx
0x7a026b  807e2100                         cmp    BYTE PTR [esi+0x21],0x0
0x7a026f  7541                             jne    0x7a02b2
0x7a0271  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x7a0274  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a0278  7516                             jne    0x7a0290
0x7a027a  8bf0                             mov    esi,eax
0x7a027c  8b06                             mov    eax,DWORD PTR [esi]
0x7a027e  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a0282  752e                             jne    0x7a02b2
0x7a0284  8bf0                             mov    esi,eax
0x7a0286  8b06                             mov    eax,DWORD PTR [esi]
0x7a0288  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a028c  74f6                             je     0x7a0284
0x7a028e  eb22                             jmp    0x7a02b2
0x7a0290  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x7a0293  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a0297  7517                             jne    0x7a02b0
0x7a0299  8da42400000000                   lea    esp,[esp+0x0]
0x7a02a0  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x7a02a3  750b                             jne    0x7a02b0
0x7a02a5  8bf0                             mov    esi,eax
0x7a02a7  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x7a02aa  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a02ae  74f0                             je     0x7a02a0
0x7a02b0  8bf0                             mov    esi,eax
0x7a02b2  3b7590                           cmp    esi,DWORD PTR [ebp-0x70]
0x7a02b5  759e                             jne    0x7a0255
0x7a02b7  33c0                             xor    eax,eax
0x7a02b9  394308                           cmp    DWORD PTR [ebx+0x8],eax
0x7a02bc  751c                             jne    0x7a02da
0x7a02be  8d7dc4                           lea    edi,[ebp-0x3c]
0x7a02c1  8bf3                             mov    esi,ebx
0x7a02c3  8945c4                           mov    DWORD PTR [ebp-0x3c],eax
0x7a02c6  8945c8                           mov    DWORD PTR [ebp-0x38],eax
0x7a02c9  e842320000                       call   0x7a3510
0x7a02ce  50                               push   eax
0x7a02cf  53                               push   ebx
0x7a02d0  8d75bc                           lea    esi,[ebp-0x44]
0x7a02d3  e868240000                       call   0x7a2740
0x7a02d8  eb24                             jmp    0x7a02fe
0x7a02da  89450c                           mov    DWORD PTR [ebp+0xc],eax
0x7a02dd  8d550c                           lea    edx,[ebp+0xc]
0x7a02e0  52                               push   edx
0x7a02e1  8d45c4                           lea    eax,[ebp-0x3c]
0x7a02e4  50                               push   eax
0x7a02e5  8bc3                             mov    eax,ebx
0x7a02e7  e8e4120000                       call   0x7a15d0
0x7a02ec  8b4dc8                           mov    ecx,DWORD PTR [ebp-0x38]
0x7a02ef  8b55c4                           mov    edx,DWORD PTR [ebp-0x3c]
0x7a02f2  51                               push   ecx
0x7a02f3  52                               push   edx
0x7a02f4  8d750c                           lea    esi,[ebp+0xc]
0x7a02f7  8bc3                             mov    eax,ebx
0x7a02f9  e8629ed2ff                       call   0x4ca160
0x7a02fe  c645fc08                         mov    BYTE PTR [ebp-0x4],0x8
0x7a0302  8b4580                           mov    eax,DWORD PTR [ebp-0x80]
0x7a0305  8b08                             mov    ecx,DWORD PTR [eax]
0x7a0307  50                               push   eax
0x7a0308  51                               push   ecx
0x7a0309  8d750c                           lea    esi,[ebp+0xc]
0x7a030c  8d857cffffff                     lea    eax,[ebp-0x84]
0x7a0312  e8499ed2ff                       call   0x4ca160
0x7a0317  8b4580                           mov    eax,DWORD PTR [ebp-0x80]
0x7a031a  50                               push   eax
0x7a031b  e8ec0e0f00                       call   0x89120c
0x7a0320  83c404                           add    esp,0x4
0x7a0323  c745fc09000000                   mov    DWORD PTR [ebp-0x4],0x9
0x7a032a  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
0x7a032d  8b08                             mov    ecx,DWORD PTR [eax]
0x7a032f  50                               push   eax
0x7a0330  51                               push   ecx
0x7a0331  8d750c                           lea    esi,[ebp+0xc]
0x7a0334  8d458c                           lea    eax,[ebp-0x74]
0x7a0337  e8e46df3ff                       call   0x6d7120
0x7a033c  8b4d90                           mov    ecx,DWORD PTR [ebp-0x70]
0x7a033f  51                               push   ecx
0x7a0340  e8c70e0f00                       call   0x89120c
0x7a0345  83c404                           add    esp,0x4
0x7a0348  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7a034b  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a0352  59                               pop    ecx
0x7a0353  5f                               pop    edi
0x7a0354  5e                               pop    esi
0x7a0355  5b                               pop    ebx
0x7a0356  8be5                             mov    esp,ebp
0x7a0358  5d                               pop    ebp
0x7a0359  c3                               ret
0x7a035a  8d55d4                           lea    edx,[ebp-0x2c]
0x7a035d  52                               push   edx
0x7a035e  8d4db0                           lea    ecx,[ebp-0x50]
0x7a0361  8975d4                           mov    DWORD PTR [ebp-0x2c],esi
0x7a0364  e8400d0f00                       call   0x8910a9
0x7a0369  68a857c800                       push   0xc857a8
0x7a036e  8d45b0                           lea    eax,[ebp-0x50]
0x7a0371  50                               push   eax
0x7a0372  c745b0a42cbd00                   mov    DWORD PTR [ebp-0x50],0xbd2ca4
0x7a0379  e872c60f00                       call   0x89c9f0
0x7a037e  8d4dd8                           lea    ecx,[ebp-0x28]
0x7a0381  51                               push   ecx
0x7a0382  8d4da0                           lea    ecx,[ebp-0x60]
0x7a0385  8975d8                           mov    DWORD PTR [ebp-0x28],esi
0x7a0388  e81c0d0f00                       call   0x8910a9
0x7a038d  68a857c800                       push   0xc857a8
0x7a0392  8d55a0                           lea    edx,[ebp-0x60]
0x7a0395  52                               push   edx
0x7a0396  c745a0a42cbd00                   mov    DWORD PTR [ebp-0x60],0xbd2ca4
0x7a039d  e84ec60f00                       call   0x89c9f0
0x7a03a2  cc                               int3
0x7a03a3  cc                               int3
0x7a03a4  cc                               int3
0x7a03a5  cc                               int3
0x7a03a6  cc                               int3
0x7a03a7  cc                               int3
0x7a03a8  cc                               int3
0x7a03a9  cc                               int3
0x7a03aa  cc                               int3
0x7a03ab  cc                               int3
0x7a03ac  cc                               int3
0x7a03ad  cc                               int3
0x7a03ae  cc                               int3
0x7a03af  cc                               int3

; doll_apply_deferred | drain result queue and call 7A90F0 with original doll
; VA 0x79db10..0x79dce0 raw 0x39cf10 length 464 sha256 8cf8cd80f229b72e493e90b9fb77c05763228e41da4fefdab29f5a2cebcf08ff
0x79db10  55                               push   ebp
0x79db11  8bec                             mov    ebp,esp
0x79db13  6aff                             push   0xffffffff
0x79db15  68408f9100                       push   0x918f40
0x79db1a  64a100000000                     mov    eax,fs:0x0
0x79db20  50                               push   eax
0x79db21  83ec2c                           sub    esp,0x2c
0x79db24  53                               push   ebx
0x79db25  56                               push   esi
0x79db26  57                               push   edi
0x79db27  a1201fd600                       mov    eax,ds:0xd61f20
0x79db2c  33c5                             xor    eax,ebp
0x79db2e  50                               push   eax
0x79db2f  8d45f4                           lea    eax,[ebp-0xc]
0x79db32  64a300000000                     mov    fs:0x0,eax
0x79db38  8bf1                             mov    esi,ecx
0x79db3a  8b86b0000000                     mov    eax,DWORD PTR [esi+0xb0]
0x79db40  3b86b4000000                     cmp    eax,DWORD PTR [esi+0xb4]
0x79db46  8d9eb0000000                     lea    ebx,[esi+0xb0]
0x79db4c  755d                             jne    0x79dbab
0x79db4e  8dbe98000000                     lea    edi,[esi+0x98]
0x79db54  57                               push   edi
0x79db55  897de4                           mov    DWORD PTR [ebp-0x1c],edi
0x79db58  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x79db5e  81c688000000                     add    esi,0x88
0x79db64  56                               push   esi
0x79db65  8bc3                             mov    eax,ebx
0x79db67  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x79db6e  e8ad320000                       call   0x7a0e20
0x79db73  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x79db76  8b0e                             mov    ecx,DWORD PTR [esi]
0x79db78  3bc8                             cmp    ecx,eax
0x79db7a  7428                             je     0x79dba4
0x79db7c  8b55d8                           mov    edx,DWORD PTR [ebp-0x28]
0x79db7f  52                               push   edx
0x79db80  51                               push   ecx
0x79db81  50                               push   eax
0x79db82  e8995b0000                       call   0x7a3720
0x79db87  8b4dd8                           mov    ecx,DWORD PTR [ebp-0x28]
0x79db8a  83c40c                           add    esp,0xc
0x79db8d  8bf8                             mov    edi,eax
0x79db8f  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x79db92  51                               push   ecx
0x79db93  50                               push   eax
0x79db94  8bc7                             mov    eax,edi
0x79db96  e8055c0000                       call   0x7a37a0
0x79db9b  897e04                           mov    DWORD PTR [esi+0x4],edi
0x79db9e  8b7de4                           mov    edi,DWORD PTR [ebp-0x1c]
0x79dba1  83c408                           add    esp,0x8
0x79dba4  57                               push   edi
0x79dba5  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x79dbab  33f6                             xor    esi,esi
0x79dbad  33ff                             xor    edi,edi
0x79dbaf  897dc8                           mov    DWORD PTR [ebp-0x38],edi
0x79dbb2  8975cc                           mov    DWORD PTR [ebp-0x34],esi
0x79dbb5  8975d0                           mov    DWORD PTR [ebp-0x30],esi
0x79dbb8  c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0x79dbbf  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x79dbc5  8b5304                           mov    edx,DWORD PTR [ebx+0x4]
0x79dbc8  8945d8                           mov    DWORD PTR [ebp-0x28],eax
0x79dbcb  8b03                             mov    eax,DWORD PTR [ebx]
0x79dbcd  2bd0                             sub    edx,eax
0x79dbcf  c1fa03                           sar    edx,0x3
0x79dbd2  c645f300                         mov    BYTE PTR [ebp-0xd],0x0
0x79dbd6  8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x79dbd9  85d2                             test   edx,edx
0x79dbdb  0f84bb000000                     je     0x79dc9c
0x79dbe1  807df300                         cmp    BYTE PTR [ebp-0xd],0x0
0x79dbe5  0f858c000000                     jne    0x79dc77
0x79dbeb  83ec08                           sub    esp,0x8
0x79dbee  8bcc                             mov    ecx,esp
0x79dbf0  8d3cf500000000                   lea    edi,[esi*8+0x0]
0x79dbf7  8965dc                           mov    DWORD PTR [ebp-0x24],esp
0x79dbfa  c70100000000                     mov    DWORD PTR [ecx],0x0
0x79dc00  c7410400000000                   mov    DWORD PTR [ecx+0x4],0x0
0x79dc07  894ddc                           mov    DWORD PTR [ebp-0x24],ecx
0x79dc0a  8b4c3804                         mov    ecx,DWORD PTR [eax+edi*1+0x4]
0x79dc0e  8b0438                           mov    eax,DWORD PTR [eax+edi*1]
0x79dc11  894de8                           mov    DWORD PTR [ebp-0x18],ecx
0x79dc14  8945e0                           mov    DWORD PTR [ebp-0x20],eax
0x79dc17  85c9                             test   ecx,ecx
0x79dc19  7437                             je     0x79dc52
0x79dc1b  8d4104                           lea    eax,[ecx+0x4]
0x79dc1e  8b08                             mov    ecx,DWORD PTR [eax]
0x79dc20  85c9                             test   ecx,ecx
0x79dc22  742e                             je     0x79dc52
0x79dc24  8bf0                             mov    esi,eax
0x79dc26  8d5101                           lea    edx,[ecx+0x1]
0x79dc29  8bc1                             mov    eax,ecx
0x79dc2b  f00fb116                         lock cmpxchg DWORD PTR [esi],edx
0x79dc2f  3bc1                             cmp    eax,ecx
0x79dc31  8b45e8                           mov    eax,DWORD PTR [ebp-0x18]
0x79dc34  740c                             je     0x79dc42
0x79dc36  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0x79dc39  83c004                           add    eax,0x4
0x79dc3c  85c9                             test   ecx,ecx
0x79dc3e  75e4                             jne    0x79dc24
0x79dc40  eb0d                             jmp    0x79dc4f
0x79dc42  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
0x79dc45  8b75dc                           mov    esi,DWORD PTR [ebp-0x24]
0x79dc48  50                               push   eax
0x79dc49  51                               push   ecx
0x79dc4a  e871550000                       call   0x7a31c0
0x79dc4f  8b75ec                           mov    esi,DWORD PTR [ebp-0x14]
0x79dc52  8b03                             mov    eax,DWORD PTR [ebx]
0x79dc54  8b0438                           mov    eax,DWORD PTR [eax+edi*1]
0x79dc57  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x79dc5a  8b4068                           mov    eax,DWORD PTR [eax+0x68]
0x79dc5d  50                               push   eax
0x79dc5e  e88db40000                       call   0x7a90f0
0x79dc63  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x79dc69  2b45d8                           sub    eax,DWORD PTR [ebp-0x28]
0x79dc6c  83f803                           cmp    eax,0x3
0x79dc6f  7612                             jbe    0x79dc83
0x79dc71  c645f301                         mov    BYTE PTR [ebp-0xd],0x1
0x79dc75  eb0c                             jmp    0x79dc83
0x79dc77  8d55c8                           lea    edx,[ebp-0x38]
0x79dc7a  8d0cf0                           lea    ecx,[eax+esi*8]
0x79dc7d  52                               push   edx
0x79dc7e  e8dd320000                       call   0x7a0f60
0x79dc83  8b03                             mov    eax,DWORD PTR [ebx]
0x79dc85  8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0x79dc88  2bc8                             sub    ecx,eax
0x79dc8a  46                               inc    esi
0x79dc8b  c1f903                           sar    ecx,0x3
0x79dc8e  8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x79dc91  3bf1                             cmp    esi,ecx
0x79dc93  0f8248ffffff                     jb     0x79dbe1
0x79dc99  8b7dc8                           mov    edi,DWORD PTR [ebp-0x38]
0x79dc9c  8d55c8                           lea    edx,[ebp-0x38]
0x79dc9f  52                               push   edx
0x79dca0  8bc3                             mov    eax,ebx
0x79dca2  e879310000                       call   0x7a0e20
0x79dca7  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x79dcae  85ff                             test   edi,edi
0x79dcb0  7418                             je     0x79dcca
0x79dcb2  8b45d8                           mov    eax,DWORD PTR [ebp-0x28]
0x79dcb5  8b4dcc                           mov    ecx,DWORD PTR [ebp-0x34]
0x79dcb8  50                               push   eax
0x79dcb9  51                               push   ecx
0x79dcba  8bc7                             mov    eax,edi
0x79dcbc  e8df5a0000                       call   0x7a37a0
0x79dcc1  57                               push   edi
0x79dcc2  e845350f00                       call   0x89120c
0x79dcc7  83c40c                           add    esp,0xc
0x79dcca  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x79dccd  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x79dcd4  59                               pop    ecx
0x79dcd5  5f                               pop    edi
0x79dcd6  5e                               pop    esi
0x79dcd7  5b                               pop    ebx
0x79dcd8  8be5                             mov    esp,ebp
0x79dcda  5d                               pop    ebp
0x79dcdb  c3                               ret
0x79dcdc  cc                               int3
0x79dcdd  cc                               int3
0x79dcde  cc                               int3
0x79dcdf  cc                               int3

; doll_apply | actual model, active attachments, face controller and animation state applied
; VA 0x7a90f0..0x7a9a70 raw 0x3a84f0 length 2432 sha256 2d4b1b9861132a5b3b8496e5ef88087c0238f3e4e3caca2bae2ae4d779a974b2
0x7a90f0  55                               push   ebp
0x7a90f1  8bec                             mov    ebp,esp
0x7a90f3  6aff                             push   0xffffffff
0x7a90f5  68648d9100                       push   0x918d64
0x7a90fa  64a100000000                     mov    eax,fs:0x0
0x7a9100  50                               push   eax
0x7a9101  81ecd8000000                     sub    esp,0xd8
0x7a9107  a1201fd600                       mov    eax,ds:0xd61f20
0x7a910c  33c5                             xor    eax,ebp
0x7a910e  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x7a9111  53                               push   ebx
0x7a9112  56                               push   esi
0x7a9113  57                               push   edi
0x7a9114  50                               push   eax
0x7a9115  8d45f4                           lea    eax,[ebp-0xc]
0x7a9118  64a300000000                     mov    fs:0x0,eax
0x7a911e  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a9121  895dc0                           mov    DWORD PTR [ebp-0x40],ebx
0x7a9124  33c0                             xor    eax,eax
0x7a9126  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x7a9129  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x7a912c  3801                             cmp    BYTE PTR [ecx],al
0x7a912e  7531                             jne    0x7a9161
0x7a9130  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x7a9137  8b7510                           mov    esi,DWORD PTR [ebp+0x10]
0x7a913a  c7432403000000                   mov    DWORD PTR [ebx+0x24],0x3
0x7a9141  89431c                           mov    DWORD PTR [ebx+0x1c],eax
0x7a9144  8983a0000000                     mov    DWORD PTR [ebx+0xa0],eax
0x7a914a  3bf0                             cmp    esi,eax
0x7a914c  0f84f5080000                     je     0x7a9a47
0x7a9152  8d5604                           lea    edx,[esi+0x4]
0x7a9155  83c8ff                           or     eax,0xffffffff
0x7a9158  f00fc102                         lock xadd DWORD PTR [edx],eax
0x7a915c  e9c7080000                       jmp    0x7a9a28
0x7a9161  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x7a9167  8d7b2c                           lea    edi,[ebx+0x2c]
0x7a916a  894590                           mov    DWORD PTR [ebp-0x70],eax
0x7a916d  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
0x7a9170  57                               push   edi
0x7a9171  8d8d6cffffff                     lea    ecx,[ebp-0x94]
0x7a9177  51                               push   ecx
0x7a9178  8945a0                           mov    DWORD PTR [ebp-0x60],eax
0x7a917b  e8d00c0000                       call   0x7a9e50
0x7a9180  8d5710                           lea    edx,[edi+0x10]
0x7a9183  52                               push   edx
0x7a9184  8d857cffffff                     lea    eax,[ebp-0x84]
0x7a918a  50                               push   eax
0x7a918b  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x7a918f  e88c0d0000                       call   0x7a9f20
0x7a9194  8d736c                           lea    esi,[ebx+0x6c]
0x7a9197  56                               push   esi
0x7a9198  8d8d54ffffff                     lea    ecx,[ebp-0xac]
0x7a919e  51                               push   ecx
0x7a919f  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x7a91a3  e8480e0000                       call   0x7a9ff0
0x7a91a8  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x7a91ac  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x7a91af  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a91b2  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0x7a91b5  894b1c                           mov    DWORD PTR [ebx+0x1c],ecx
0x7a91b8  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x7a91bb  83c048                           add    eax,0x48
0x7a91be  50                               push   eax
0x7a91bf  8955bc                           mov    DWORD PTR [ebp-0x44],edx
0x7a91c2  e869c5ffff                       call   0x7a5730
0x7a91c7  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x7a91ca  83c018                           add    eax,0x18
0x7a91cd  8945cc                           mov    DWORD PTR [ebp-0x34],eax
0x7a91d0  3bf0                             cmp    esi,eax
0x7a91d2  741e                             je     0x7a91f2
0x7a91d4  8b4370                           mov    eax,DWORD PTR [ebx+0x70]
0x7a91d7  8b08                             mov    ecx,DWORD PTR [eax]
0x7a91d9  50                               push   eax
0x7a91da  51                               push   ecx
0x7a91db  8d75c8                           lea    esi,[ebp-0x38]
0x7a91de  8d436c                           lea    eax,[ebx+0x6c]
0x7a91e1  e83adff2ff                       call   0x6d7120
0x7a91e6  8b55cc                           mov    edx,DWORD PTR [ebp-0x34]
0x7a91e9  52                               push   edx
0x7a91ea  8d436c                           lea    eax,[ebx+0x6c]
0x7a91ed  e85e0f0000                       call   0x7aa150
0x7a91f2  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x7a91f5  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a91f8  8d8bec000000                     lea    ecx,[ebx+0xec]
0x7a91fe  51                               push   ecx
0x7a91ff  8d4b04                           lea    ecx,[ebx+0x4]
0x7a9202  ffd2                             call   edx
0x7a9204  d983f8000000                     fld    DWORD PTR [ebx+0xf8]
0x7a920a  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x7a920d  8b5014                           mov    edx,DWORD PTR [eax+0x14]
0x7a9210  51                               push   ecx
0x7a9211  8d4b04                           lea    ecx,[ebx+0x4]
0x7a9214  d91c24                           fstp   DWORD PTR [esp]
0x7a9217  ffd2                             call   edx
0x7a9219  d983fc000000                     fld    DWORD PTR [ebx+0xfc]
0x7a921f  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x7a9222  8b500c                           mov    edx,DWORD PTR [eax+0xc]
0x7a9225  51                               push   ecx
0x7a9226  8d4b04                           lea    ecx,[ebx+0x4]
0x7a9229  d91c24                           fstp   DWORD PTR [esp]
0x7a922c  ffd2                             call   edx
0x7a922e  8d737c                           lea    esi,[ebx+0x7c]
0x7a9231  8bfe                             mov    edi,esi
0x7a9233  e818a60700                       call   0x823850
0x7a9238  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x7a923b  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x7a923e  8945c4                           mov    DWORD PTR [ebp-0x3c],eax
0x7a9241  8b403c                           mov    eax,DWORD PTR [eax+0x3c]
0x7a9244  8b38                             mov    edi,DWORD PTR [eax]
0x7a9246  3bf8                             cmp    edi,eax
0x7a9248  0f84c0000000                     je     0x7a930e
0x7a924e  8bff                             mov    edi,edi
0x7a9250  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x7a9257  7521                             jne    0x7a927a
0x7a9259  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x7a9260  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x7a9264  e8975c0100                       call   0x7bef00
0x7a9269  6850ecbc00                       push   0xbcec50
0x7a926e  e8a7900e00                       call   0x89231a
0x7a9273  83c404                           add    esp,0x4
0x7a9276  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x7a927a  8b4f18                           mov    ecx,DWORD PTR [edi+0x18]
0x7a927d  8b571c                           mov    edx,DWORD PTR [edi+0x1c]
0x7a9280  8d8564ffffff                     lea    eax,[ebp-0x9c]
0x7a9286  898d64ffffff                     mov    DWORD PTR [ebp-0x9c],ecx
0x7a928c  50                               push   eax
0x7a928d  8d4dcc                           lea    ecx,[ebp-0x34]
0x7a9290  51                               push   ecx
0x7a9291  68601bfe00                       push   0xfe1b60
0x7a9296  899568ffffff                     mov    DWORD PTR [ebp-0x98],edx
0x7a929c  e85f41d3ff                       call   0x4dd400
0x7a92a1  8b45cc                           mov    eax,DWORD PTR [ebp-0x34]
0x7a92a4  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
0x7a92aa  7411                             je     0x7a92bd
0x7a92ac  8b4018                           mov    eax,DWORD PTR [eax+0x18]
0x7a92af  85c0                             test   eax,eax
0x7a92b1  740a                             je     0x7a92bd
0x7a92b3  8b55bc                           mov    edx,DWORD PTR [ebp-0x44]
0x7a92b6  56                               push   esi
0x7a92b7  52                               push   edx
0x7a92b8  e813ca0200                       call   0x7d5cd0
0x7a92bd  807f2100                         cmp    BYTE PTR [edi+0x21],0x0
0x7a92c1  753f                             jne    0x7a9302
0x7a92c3  8b4708                           mov    eax,DWORD PTR [edi+0x8]
0x7a92c6  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a92ca  7516                             jne    0x7a92e2
0x7a92cc  8bf8                             mov    edi,eax
0x7a92ce  8b07                             mov    eax,DWORD PTR [edi]
0x7a92d0  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a92d4  752c                             jne    0x7a9302
0x7a92d6  8bf8                             mov    edi,eax
0x7a92d8  8b07                             mov    eax,DWORD PTR [edi]
0x7a92da  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a92de  74f6                             je     0x7a92d6
0x7a92e0  eb20                             jmp    0x7a9302
0x7a92e2  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a92e5  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a92e9  7515                             jne    0x7a9300
0x7a92eb  eb03                             jmp    0x7a92f0
0x7a92ed  8d4900                           lea    ecx,[ecx+0x0]
0x7a92f0  3b7808                           cmp    edi,DWORD PTR [eax+0x8]
0x7a92f3  750b                             jne    0x7a9300
0x7a92f5  8bf8                             mov    edi,eax
0x7a92f7  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x7a92fa  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a92fe  74f0                             je     0x7a92f0
0x7a9300  8bf8                             mov    edi,eax
0x7a9302  8b45c4                           mov    eax,DWORD PTR [ebp-0x3c]
0x7a9305  3b783c                           cmp    edi,DWORD PTR [eax+0x3c]
0x7a9308  0f8542ffffff                     jne    0x7a9250
0x7a930e  8b8ba8000000                     mov    ecx,DWORD PTR [ebx+0xa8]
0x7a9314  51                               push   ecx
0x7a9315  8bc3                             mov    eax,ebx
0x7a9317  e8e4e4ffff                       call   0x7a7800
0x7a931c  d983b4000000                     fld    DWORD PTR [ebx+0xb4]
0x7a9322  d95dcc                           fstp   DWORD PTR [ebp-0x34]
0x7a9325  51                               push   ecx
0x7a9326  d9ee                             fldz
0x7a9328  8bf3                             mov    esi,ebx
0x7a932a  d91c24                           fstp   DWORD PTR [esp]
0x7a932d  8983ac000000                     mov    DWORD PTR [ebx+0xac],eax
0x7a9333  e8f8d4ffff                       call   0x7a6830
0x7a9338  d945cc                           fld    DWORD PTR [ebp-0x34]
0x7a933b  51                               push   ecx
0x7a933c  d91c24                           fstp   DWORD PTR [esp]
0x7a933f  e8ecd4ffff                       call   0x7a6830
0x7a9344  8b4370                           mov    eax,DWORD PTR [ebx+0x70]
0x7a9347  8b08                             mov    ecx,DWORD PTR [eax]
0x7a9349  894dc8                           mov    DWORD PTR [ebp-0x38],ecx
0x7a934c  3bc8                             cmp    ecx,eax
0x7a934e  0f848f000000                     je     0x7a93e3
0x7a9354  8b45c8                           mov    eax,DWORD PTR [ebp-0x38]
0x7a9357  8b7018                           mov    esi,DWORD PTR [eax+0x18]
0x7a935a  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
0x7a935d  2b4e18                           sub    ecx,DWORD PTR [esi+0x18]
0x7a9360  8b93a8000000                     mov    edx,DWORD PTR [ebx+0xa8]
0x7a9366  c1f902                           sar    ecx,0x2
0x7a9369  33ff                             xor    edi,edi
0x7a936b  8955cc                           mov    DWORD PTR [ebp-0x34],edx
0x7a936e  85c9                             test   ecx,ecx
0x7a9370  741f                             je     0x7a9391
0x7a9372  8b5618                           mov    edx,DWORD PTR [esi+0x18]
0x7a9375  8b0cba                           mov    ecx,DWORD PTR [edx+edi*4]
0x7a9378  8b01                             mov    eax,DWORD PTR [ecx]
0x7a937a  8b55cc                           mov    edx,DWORD PTR [ebp-0x34]
0x7a937d  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x7a9380  52                               push   edx
0x7a9381  ffd0                             call   eax
0x7a9383  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
0x7a9386  2b4e18                           sub    ecx,DWORD PTR [esi+0x18]
0x7a9389  47                               inc    edi
0x7a938a  c1f902                           sar    ecx,0x2
0x7a938d  3bf9                             cmp    edi,ecx
0x7a938f  72e1                             jb     0x7a9372
0x7a9391  8b4dc8                           mov    ecx,DWORD PTR [ebp-0x38]
0x7a9394  80792100                         cmp    BYTE PTR [ecx+0x21],0x0
0x7a9398  7540                             jne    0x7a93da
0x7a939a  8b4108                           mov    eax,DWORD PTR [ecx+0x8]
0x7a939d  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a93a1  7519                             jne    0x7a93bc
0x7a93a3  8bc8                             mov    ecx,eax
0x7a93a5  8b01                             mov    eax,DWORD PTR [ecx]
0x7a93a7  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a93ab  752a                             jne    0x7a93d7
0x7a93ad  8d4900                           lea    ecx,[ecx+0x0]
0x7a93b0  8bc8                             mov    ecx,eax
0x7a93b2  8b01                             mov    eax,DWORD PTR [ecx]
0x7a93b4  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a93b8  74f6                             je     0x7a93b0
0x7a93ba  eb1b                             jmp    0x7a93d7
0x7a93bc  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x7a93bf  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a93c3  7510                             jne    0x7a93d5
0x7a93c5  3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
0x7a93c8  750b                             jne    0x7a93d5
0x7a93ca  8bc8                             mov    ecx,eax
0x7a93cc  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x7a93cf  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a93d3  74f0                             je     0x7a93c5
0x7a93d5  8bc8                             mov    ecx,eax
0x7a93d7  894dc8                           mov    DWORD PTR [ebp-0x38],ecx
0x7a93da  3b4b70                           cmp    ecx,DWORD PTR [ebx+0x70]
0x7a93dd  0f8571ffffff                     jne    0x7a9354
0x7a93e3  8b83a0000000                     mov    eax,DWORD PTR [ebx+0xa0]
0x7a93e9  33ff                             xor    edi,edi
0x7a93eb  3bc7                             cmp    eax,edi
0x7a93ed  7414                             je     0x7a9403
0x7a93ef  8b08                             mov    ecx,DWORD PTR [eax]
0x7a93f1  ff492c                           dec    DWORD PTR [ecx+0x2c]
0x7a93f4  50                               push   eax
0x7a93f5  e8127e0e00                       call   0x89120c
0x7a93fa  83c404                           add    esp,0x4
0x7a93fd  89bba0000000                     mov    DWORD PTR [ebx+0xa0],edi
0x7a9403  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x7a9406  8b4214                           mov    eax,DWORD PTR [edx+0x14]
0x7a9409  8983a0000000                     mov    DWORD PTR [ebx+0xa0],eax
0x7a940f  8b45bc                           mov    eax,DWORD PTR [ebp-0x44]
0x7a9412  8bb0c4000000                     mov    esi,DWORD PTR [eax+0xc4]
0x7a9418  8b88c8000000                     mov    ecx,DWORD PTR [eax+0xc8]
0x7a941e  2bce                             sub    ecx,esi
0x7a9420  b893244992                       mov    eax,0x92492493
0x7a9425  f7e9                             imul   ecx
0x7a9427  03d1                             add    edx,ecx
0x7a9429  c1fa05                           sar    edx,0x5
0x7a942c  8bc2                             mov    eax,edx
0x7a942e  c1e81f                           shr    eax,0x1f
0x7a9431  03c2                             add    eax,edx
0x7a9433  0f84a5020000                     je     0x7a96de
0x7a9439  897dcc                           mov    DWORD PTR [ebp-0x34],edi
0x7a943c  3bc7                             cmp    eax,edi
0x7a943e  0f869a020000                     jbe    0x7a96de
0x7a9444  897dc8                           mov    DWORD PTR [ebp-0x38],edi
0x7a9447  eb07                             jmp    0x7a9450
0x7a9449  8da42400000000                   lea    esp,[esp+0x0]
0x7a9450  8b4dc8                           mov    ecx,DWORD PTR [ebp-0x38]
0x7a9453  837c0e3010                       cmp    DWORD PTR [esi+ecx*1+0x30],0x10
0x7a9458  8d440e1c                         lea    eax,[esi+ecx*1+0x1c]
0x7a945c  c745c4ffffffff                   mov    DWORD PTR [ebp-0x3c],0xffffffff
0x7a9463  7204                             jb     0x7a9469
0x7a9465  8b38                             mov    edi,DWORD PTR [eax]
0x7a9467  eb02                             jmp    0x7a946b
0x7a9469  8bf8                             mov    edi,eax
0x7a946b  f6054c32fe0001                   test   BYTE PTR ds:0xfe324c,0x1
0x7a9472  0f85bf000000                     jne    0x7a9537
0x7a9478  830d4c32fe0001                   or     DWORD PTR ds:0xfe324c,0x1
0x7a947f  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x7a9483  33f6                             xor    esi,esi
0x7a9485  6a34                             push   0x34
0x7a9487  89355832fe00                     mov    DWORD PTR ds:0xfe3258,esi
0x7a948d  e8d67d0e00                       call   0x891268
0x7a9492  83c404                           add    esp,0x4
0x7a9495  3bc6                             cmp    eax,esi
0x7a9497  0f84db020000                     je     0x7a9778
0x7a949d  a35432fe00                       mov    ds:0xfe3254,eax
0x7a94a2  8900                             mov    DWORD PTR [eax],eax
0x7a94a4  a15432fe00                       mov    eax,ds:0xfe3254
0x7a94a9  894004                           mov    DWORD PTR [eax+0x4],eax
0x7a94ac  a15432fe00                       mov    eax,ds:0xfe3254
0x7a94b1  894008                           mov    DWORD PTR [eax+0x8],eax
0x7a94b4  8b155432fe00                     mov    edx,DWORD PTR ds:0xfe3254
0x7a94ba  c6423001                         mov    BYTE PTR [edx+0x30],0x1
0x7a94be  a15432fe00                       mov    eax,ds:0xfe3254
0x7a94c3  c6403101                         mov    BYTE PTR [eax+0x31],0x1
0x7a94c7  c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
0x7a94cb  6a30                             push   0x30
0x7a94cd  89356832fe00                     mov    DWORD PTR ds:0xfe3268,esi
0x7a94d3  e8907d0e00                       call   0x891268
0x7a94d8  83c404                           add    esp,0x4
0x7a94db  3bc6                             cmp    eax,esi
0x7a94dd  0f8468020000                     je     0x7a974b
0x7a94e3  a36432fe00                       mov    ds:0xfe3264,eax
0x7a94e8  8900                             mov    DWORD PTR [eax],eax
0x7a94ea  a16432fe00                       mov    eax,ds:0xfe3264
0x7a94ef  894004                           mov    DWORD PTR [eax+0x4],eax
0x7a94f2  a16432fe00                       mov    eax,ds:0xfe3264
0x7a94f7  894008                           mov    DWORD PTR [eax+0x8],eax
0x7a94fa  8b0d6432fe00                     mov    ecx,DWORD PTR ds:0xfe3264
0x7a9500  c6412c01                         mov    BYTE PTR [ecx+0x2c],0x1
0x7a9504  8b156432fe00                     mov    edx,DWORD PTR ds:0xfe3264
0x7a950a  c6422d01                         mov    BYTE PTR [edx+0x2d],0x1
0x7a950e  68b009bd00                       push   0xbd09b0
0x7a9513  89357032fe00                     mov    DWORD PTR ds:0xfe3270,esi
0x7a9519  89357432fe00                     mov    DWORD PTR ds:0xfe3274,esi
0x7a951f  89357832fe00                     mov    DWORD PTR ds:0xfe3278,esi
0x7a9525  89358032fe00                     mov    DWORD PTR ds:0xfe3280,esi
0x7a952b  e8ea8d0e00                       call   0x89231a
0x7a9530  83c404                           add    esp,0x4
0x7a9533  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x7a9537  8bd7                             mov    edx,edi
0x7a9539  b95032fe00                       mov    ecx,0xfe3250
0x7a953e  e80d630200                       call   0x7cf850
0x7a9543  8bf8                             mov    edi,eax
0x7a9545  c745e40f000000                   mov    DWORD PTR [ebp-0x1c],0xf
0x7a954c  c745e000000000                   mov    DWORD PTR [ebp-0x20],0x0
0x7a9553  c645d000                         mov    BYTE PTR [ebp-0x30],0x0
0x7a9557  6aff                             push   0xffffffff
0x7a9559  6a00                             push   0x0
0x7a955b  8d5f7c                           lea    ebx,[edi+0x7c]
0x7a955e  53                               push   ebx
0x7a955f  8d4dd0                           lea    ecx,[ebp-0x30]
0x7a9562  c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
0x7a9566  e8d59ac5ff                       call   0x403040
0x7a956b  837f7800                         cmp    DWORD PTR [edi+0x78],0x0
0x7a956f  0f84c7000000                     je     0x7a963c
0x7a9575  837de410                         cmp    DWORD PTR [ebp-0x1c],0x10
0x7a9579  8b45d0                           mov    eax,DWORD PTR [ebp-0x30]
0x7a957c  7303                             jae    0x7a9581
0x7a957e  8d45d0                           lea    eax,[ebp-0x30]
0x7a9581  8b4dc0                           mov    ecx,DWORD PTR [ebp-0x40]
0x7a9584  8b711c                           mov    esi,DWORD PTR [ecx+0x1c]
0x7a9587  85f6                             test   esi,esi
0x7a9589  0f84ad000000                     je     0x7a963c
0x7a958f  50                               push   eax
0x7a9590  8d55c4                           lea    edx,[ebp-0x3c]
0x7a9593  52                               push   edx
0x7a9594  e8379d0200                       call   0x7d32d0
0x7a9599  85c0                             test   eax,eax
0x7a959b  0f849b000000                     je     0x7a963c
0x7a95a1  8b45c4                           mov    eax,DWORD PTR [ebp-0x3c]
0x7a95a4  85c0                             test   eax,eax
0x7a95a6  0f8890000000                     js     0x7a963c
0x7a95ac  8b75c0                           mov    esi,DWORD PTR [ebp-0x40]
0x7a95af  8bd8                             mov    ebx,eax
0x7a95b1  8b8650010000                     mov    eax,DWORD PTR [esi+0x150]
0x7a95b7  8d4d98                           lea    ecx,[ebp-0x68]
0x7a95ba  895d98                           mov    DWORD PTR [ebp-0x68],ebx
0x7a95bd  897d9c                           mov    DWORD PTR [ebp-0x64],edi
0x7a95c0  3bc8                             cmp    ecx,eax
0x7a95c2  734d                             jae    0x7a9611
0x7a95c4  8b8e4c010000                     mov    ecx,DWORD PTR [esi+0x14c]
0x7a95ca  8d5598                           lea    edx,[ebp-0x68]
0x7a95cd  3bca                             cmp    ecx,edx
0x7a95cf  7740                             ja     0x7a9611
0x7a95d1  8bfa                             mov    edi,edx
0x7a95d3  2bf9                             sub    edi,ecx
0x7a95d5  c1ff03                           sar    edi,0x3
0x7a95d8  3b8654010000                     cmp    eax,DWORD PTR [esi+0x154]
0x7a95de  750b                             jne    0x7a95eb
0x7a95e0  8d8e4c010000                     lea    ecx,[esi+0x14c]
0x7a95e6  e805480200                       call   0x7cddf0
0x7a95eb  8b864c010000                     mov    eax,DWORD PTR [esi+0x14c]
0x7a95f1  8d0cf8                           lea    ecx,[eax+edi*8]
0x7a95f4  8b8650010000                     mov    eax,DWORD PTR [esi+0x150]
0x7a95fa  85c0                             test   eax,eax
0x7a95fc  740a                             je     0x7a9608
0x7a95fe  8b11                             mov    edx,DWORD PTR [ecx]
0x7a9600  8910                             mov    DWORD PTR [eax],edx
0x7a9602  8b4904                           mov    ecx,DWORD PTR [ecx+0x4]
0x7a9605  894804                           mov    DWORD PTR [eax+0x4],ecx
0x7a9608  83865001000008                   add    DWORD PTR [esi+0x150],0x8
0x7a960f  eb7b                             jmp    0x7a968c
0x7a9611  3b8654010000                     cmp    eax,DWORD PTR [esi+0x154]
0x7a9617  750b                             jne    0x7a9624
0x7a9619  8d8e4c010000                     lea    ecx,[esi+0x14c]
0x7a961f  e8cc470200                       call   0x7cddf0
0x7a9624  8b8650010000                     mov    eax,DWORD PTR [esi+0x150]
0x7a962a  85c0                             test   eax,eax
0x7a962c  7405                             je     0x7a9633
0x7a962e  8918                             mov    DWORD PTR [eax],ebx
0x7a9630  897804                           mov    DWORD PTR [eax+0x4],edi
0x7a9633  83865001000008                   add    DWORD PTR [esi+0x150],0x8
0x7a963a  eb50                             jmp    0x7a968c
0x7a963c  897dc4                           mov    DWORD PTR [ebp-0x3c],edi
0x7a963f  8bf7                             mov    esi,edi
0x7a9641  c645fc09                         mov    BYTE PTR [ebp-0x4],0x9
0x7a9645  e8d6f20200                       call   0x7d8920
0x7a964a  837b1410                         cmp    DWORD PTR [ebx+0x14],0x10
0x7a964e  720b                             jb     0x7a965b
0x7a9650  8b03                             mov    eax,DWORD PTR [ebx]
0x7a9652  50                               push   eax
0x7a9653  e8b47b0e00                       call   0x89120c
0x7a9658  83c404                           add    esp,0x4
0x7a965b  33f6                             xor    esi,esi
0x7a965d  c743140f000000                   mov    DWORD PTR [ebx+0x14],0xf
0x7a9664  897310                           mov    DWORD PTR [ebx+0x10],esi
0x7a9667  c60300                           mov    BYTE PTR [ebx],0x0
0x7a966a  8b475c                           mov    eax,DWORD PTR [edi+0x5c]
0x7a966d  3bc6                             cmp    eax,esi
0x7a966f  7409                             je     0x7a967a
0x7a9671  50                               push   eax
0x7a9672  e8957b0e00                       call   0x89120c
0x7a9677  83c404                           add    esp,0x4
0x7a967a  57                               push   edi
0x7a967b  89775c                           mov    DWORD PTR [edi+0x5c],esi
0x7a967e  897760                           mov    DWORD PTR [edi+0x60],esi
0x7a9681  897764                           mov    DWORD PTR [edi+0x64],esi
0x7a9684  e8837b0e00                       call   0x89120c
0x7a9689  83c404                           add    esp,0x4
0x7a968c  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x7a9690  837de410                         cmp    DWORD PTR [ebp-0x1c],0x10
0x7a9694  720c                             jb     0x7a96a2
0x7a9696  8b55d0                           mov    edx,DWORD PTR [ebp-0x30]
0x7a9699  52                               push   edx
0x7a969a  e86d7b0e00                       call   0x89120c
0x7a969f  83c404                           add    esp,0x4
0x7a96a2  8b45bc                           mov    eax,DWORD PTR [ebp-0x44]
0x7a96a5  8bb0c4000000                     mov    esi,DWORD PTR [eax+0xc4]
0x7a96ab  8b88c8000000                     mov    ecx,DWORD PTR [eax+0xc8]
0x7a96b1  8b7dcc                           mov    edi,DWORD PTR [ebp-0x34]
0x7a96b4  8345c838                         add    DWORD PTR [ebp-0x38],0x38
0x7a96b8  2bce                             sub    ecx,esi
0x7a96ba  b893244992                       mov    eax,0x92492493
0x7a96bf  f7e9                             imul   ecx
0x7a96c1  03d1                             add    edx,ecx
0x7a96c3  c1fa05                           sar    edx,0x5
0x7a96c6  8bc2                             mov    eax,edx
0x7a96c8  c1e81f                           shr    eax,0x1f
0x7a96cb  47                               inc    edi
0x7a96cc  03c2                             add    eax,edx
0x7a96ce  897dcc                           mov    DWORD PTR [ebp-0x34],edi
0x7a96d1  3bf8                             cmp    edi,eax
0x7a96d3  0f8277fdffff                     jb     0x7a9450
0x7a96d9  8b5dc0                           mov    ebx,DWORD PTR [ebp-0x40]
0x7a96dc  33ff                             xor    edi,edi
0x7a96de  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x7a96e1  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x7a96e4  80780400                         cmp    BYTE PTR [eax+0x4],0x0
0x7a96e8  0f8571020000                     jne    0x7a995f
0x7a96ee  6a38                             push   0x38
0x7a96f0  e8737b0e00                       call   0x891268
0x7a96f5  8bf0                             mov    esi,eax
0x7a96f7  83c404                           add    esp,0x4
0x7a96fa  8975b0                           mov    DWORD PTR [ebp-0x50],esi
0x7a96fd  c645fc0a                         mov    BYTE PTR [ebp-0x4],0xa
0x7a9701  3bf7                             cmp    esi,edi
0x7a9703  0f84c9000000                     je     0x7a97d2
0x7a9709  8d4608                           lea    eax,[esi+0x8]
0x7a970c  50                               push   eax
0x7a970d  e80eb9ffff                       call   0x7a5020
0x7a9712  c645fc0b                         mov    BYTE PTR [ebp-0x4],0xb
0x7a9716  6a28                             push   0x28
0x7a9718  897e30                           mov    DWORD PTR [esi+0x30],edi
0x7a971b  e8487b0e00                       call   0x891268
0x7a9720  83c404                           add    esp,0x4
0x7a9723  3bc7                             cmp    eax,edi
0x7a9725  747e                             je     0x7a97a5
0x7a9727  89462c                           mov    DWORD PTR [esi+0x2c],eax
0x7a972a  8900                             mov    DWORD PTR [eax],eax
0x7a972c  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
0x7a972f  894004                           mov    DWORD PTR [eax+0x4],eax
0x7a9732  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
0x7a9735  894008                           mov    DWORD PTR [eax+0x8],eax
0x7a9738  8b4e2c                           mov    ecx,DWORD PTR [esi+0x2c]
0x7a973b  c6412001                         mov    BYTE PTR [ecx+0x20],0x1
0x7a973f  8b562c                           mov    edx,DWORD PTR [esi+0x2c]
0x7a9742  c6422101                         mov    BYTE PTR [edx+0x21],0x1
0x7a9746  e989000000                       jmp    0x7a97d4
0x7a974b  8d4d8c                           lea    ecx,[ebp-0x74]
0x7a974e  51                               push   ecx
0x7a974f  8d8d24ffffff                     lea    ecx,[ebp-0xdc]
0x7a9755  89758c                           mov    DWORD PTR [ebp-0x74],esi
0x7a9758  e84c790e00                       call   0x8910a9
0x7a975d  68a857c800                       push   0xc857a8
0x7a9762  8d9524ffffff                     lea    edx,[ebp-0xdc]
0x7a9768  52                               push   edx
0x7a9769  c78524ffffffa42cbd00             mov    DWORD PTR [ebp-0xdc],0xbd2ca4
0x7a9773  e878320f00                       call   0x89c9f0
0x7a9778  8d45b0                           lea    eax,[ebp-0x50]
0x7a977b  50                               push   eax
0x7a977c  8d8d48ffffff                     lea    ecx,[ebp-0xb8]
0x7a9782  8975b0                           mov    DWORD PTR [ebp-0x50],esi
0x7a9785  e81f790e00                       call   0x8910a9
0x7a978a  68a857c800                       push   0xc857a8
0x7a978f  8d8d48ffffff                     lea    ecx,[ebp-0xb8]
0x7a9795  51                               push   ecx
0x7a9796  c78548ffffffa42cbd00             mov    DWORD PTR [ebp-0xb8],0xbd2ca4
0x7a97a0  e84b320f00                       call   0x89c9f0
0x7a97a5  8d45c0                           lea    eax,[ebp-0x40]
0x7a97a8  50                               push   eax
0x7a97a9  8d8d3cffffff                     lea    ecx,[ebp-0xc4]
0x7a97af  897dc0                           mov    DWORD PTR [ebp-0x40],edi
0x7a97b2  e8f2780e00                       call   0x8910a9
0x7a97b7  68a857c800                       push   0xc857a8
0x7a97bc  8d8d3cffffff                     lea    ecx,[ebp-0xc4]
0x7a97c2  51                               push   ecx
0x7a97c3  c7853cffffffa42cbd00             mov    DWORD PTR [ebp-0xc4],0xbd2ca4
0x7a97cd  e81e320f00                       call   0x89c9f0
0x7a97d2  33f6                             xor    esi,esi
0x7a97d4  33c0                             xor    eax,eax
0x7a97d6  56                               push   esi
0x7a97d7  8d55b4                           lea    edx,[ebp-0x4c]
0x7a97da  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x7a97de  52                               push   edx
0x7a97df  8945b4                           mov    DWORD PTR [ebp-0x4c],eax
0x7a97e2  8945b8                           mov    DWORD PTR [ebp-0x48],eax
0x7a97e5  e8960f0000                       call   0x7aa780
0x7a97ea  c645fc0c                         mov    BYTE PTR [ebp-0x4],0xc
0x7a97ee  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
0x7a97f1  8b4b18                           mov    ecx,DWORD PTR [ebx+0x18]
0x7a97f4  8d7808                           lea    edi,[eax+0x8]
0x7a97f7  8d956cffffff                     lea    edx,[ebp-0x94]
0x7a97fd  8908                             mov    DWORD PTR [eax],ecx
0x7a97ff  3bfa                             cmp    edi,edx
0x7a9801  7422                             je     0x7a9825
0x7a9803  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a9806  8b08                             mov    ecx,DWORD PTR [eax]
0x7a9808  50                               push   eax
0x7a9809  51                               push   ecx
0x7a980a  8d75bc                           lea    esi,[ebp-0x44]
0x7a980d  8bc7                             mov    eax,edi
0x7a980f  e84c09d2ff                       call   0x4ca160
0x7a9814  8d856cffffff                     lea    eax,[ebp-0x94]
0x7a981a  50                               push   eax
0x7a981b  8bc7                             mov    eax,edi
0x7a981d  e81e7dffff                       call   0x7a1540
0x7a9822  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
0x7a9825  83c710                           add    edi,0x10
0x7a9828  8d8d7cffffff                     lea    ecx,[ebp-0x84]
0x7a982e  3bf9                             cmp    edi,ecx
0x7a9830  7425                             je     0x7a9857
0x7a9832  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a9835  8b08                             mov    ecx,DWORD PTR [eax]
0x7a9837  50                               push   eax
0x7a9838  51                               push   ecx
0x7a9839  8db520ffffff                     lea    esi,[ebp-0xe0]
0x7a983f  8bc7                             mov    eax,edi
0x7a9841  e8dad8f2ff                       call   0x6d7120
0x7a9846  8d957cffffff                     lea    edx,[ebp-0x84]
0x7a984c  52                               push   edx
0x7a984d  8bc7                             mov    eax,edi
0x7a984f  e80c7effff                       call   0x7a1660
0x7a9854  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
0x7a9857  8b4da0                           mov    ecx,DWORD PTR [ebp-0x60]
0x7a985a  8d7828                           lea    edi,[eax+0x28]
0x7a985d  8d9554ffffff                     lea    edx,[ebp-0xac]
0x7a9863  894804                           mov    DWORD PTR [eax+0x4],ecx
0x7a9866  3bfa                             cmp    edi,edx
0x7a9868  741f                             je     0x7a9889
0x7a986a  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a986d  8b08                             mov    ecx,DWORD PTR [eax]
0x7a986f  50                               push   eax
0x7a9870  51                               push   ecx
0x7a9871  8d75a0                           lea    esi,[ebp-0x60]
0x7a9874  8bc7                             mov    eax,edi
0x7a9876  e8a5d8f2ff                       call   0x6d7120
0x7a987b  8d8554ffffff                     lea    eax,[ebp-0xac]
0x7a9881  50                               push   eax
0x7a9882  8bc7                             mov    eax,edi
0x7a9884  e8c7080000                       call   0x7aa150
0x7a9889  8b55b8                           mov    edx,DWORD PTR [ebp-0x48]
0x7a988c  33c0                             xor    eax,eax
0x7a988e  8945a4                           mov    DWORD PTR [ebp-0x5c],eax
0x7a9891  8945a8                           mov    DWORD PTR [ebp-0x58],eax
0x7a9894  3bd0                             cmp    edx,eax
0x7a9896  742d                             je     0x7a98c5
0x7a9898  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0x7a989b  3bc8                             cmp    ecx,eax
0x7a989d  7426                             je     0x7a98c5
0x7a989f  90                               nop
0x7a98a0  8d7101                           lea    esi,[ecx+0x1]
0x7a98a3  8d7a04                           lea    edi,[edx+0x4]
0x7a98a6  8bc1                             mov    eax,ecx
0x7a98a8  f00fb137                         lock cmpxchg DWORD PTR [edi],esi
0x7a98ac  3bc1                             cmp    eax,ecx
0x7a98ae  7409                             je     0x7a98b9
0x7a98b0  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0x7a98b3  85c9                             test   ecx,ecx
0x7a98b5  75e9                             jne    0x7a98a0
0x7a98b7  eb0c                             jmp    0x7a98c5
0x7a98b9  8b4db8                           mov    ecx,DWORD PTR [ebp-0x48]
0x7a98bc  8b55b4                           mov    edx,DWORD PTR [ebp-0x4c]
0x7a98bf  894da8                           mov    DWORD PTR [ebp-0x58],ecx
0x7a98c2  8955a4                           mov    DWORD PTR [ebp-0x5c],edx
0x7a98c5  c645fc0d                         mov    BYTE PTR [ebp-0x4],0xd
0x7a98c9  e8c229cdff                       call   0x47c290
0x7a98ce  8bf0                             mov    esi,eax
0x7a98d0  8d7e70                           lea    edi,[esi+0x70]
0x7a98d3  57                               push   edi
0x7a98d4  89bd34ffffff                     mov    DWORD PTR [ebp-0xcc],edi
0x7a98da  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x7a98e0  83c638                           add    esi,0x38
0x7a98e3  56                               push   esi
0x7a98e4  8d4da4                           lea    ecx,[ebp-0x5c]
0x7a98e7  c645fc0f                         mov    BYTE PTR [ebp-0x4],0xf
0x7a98eb  e87076ffff                       call   0x7a0f60
0x7a98f0  57                               push   edi
0x7a98f1  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x7a98f7  c645fc0c                         mov    BYTE PTR [ebp-0x4],0xc
0x7a98fb  8b75a8                           mov    esi,DWORD PTR [ebp-0x58]
0x7a98fe  85f6                             test   esi,esi
0x7a9900  7429                             je     0x7a992b
0x7a9902  8d4604                           lea    eax,[esi+0x4]
0x7a9905  83c9ff                           or     ecx,0xffffffff
0x7a9908  f00fc108                         lock xadd DWORD PTR [eax],ecx
0x7a990c  751d                             jne    0x7a992b
0x7a990e  8b16                             mov    edx,DWORD PTR [esi]
0x7a9910  8b02                             mov    eax,DWORD PTR [edx]
0x7a9912  8bce                             mov    ecx,esi
0x7a9914  ffd0                             call   eax
0x7a9916  8d4e08                           lea    ecx,[esi+0x8]
0x7a9919  83caff                           or     edx,0xffffffff
0x7a991c  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x7a9920  7509                             jne    0x7a992b
0x7a9922  8b06                             mov    eax,DWORD PTR [esi]
0x7a9924  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a9927  8bce                             mov    ecx,esi
0x7a9929  ffd2                             call   edx
0x7a992b  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x7a992f  8b75b8                           mov    esi,DWORD PTR [ebp-0x48]
0x7a9932  85f6                             test   esi,esi
0x7a9934  7429                             je     0x7a995f
0x7a9936  8d4604                           lea    eax,[esi+0x4]
0x7a9939  83c9ff                           or     ecx,0xffffffff
0x7a993c  f00fc108                         lock xadd DWORD PTR [eax],ecx
0x7a9940  751d                             jne    0x7a995f
0x7a9942  8b16                             mov    edx,DWORD PTR [esi]
0x7a9944  8b02                             mov    eax,DWORD PTR [edx]
0x7a9946  8bce                             mov    ecx,esi
0x7a9948  ffd0                             call   eax
0x7a994a  8d4e08                           lea    ecx,[esi+0x8]
0x7a994d  83caff                           or     edx,0xffffffff
0x7a9950  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x7a9954  7509                             jne    0x7a995f
0x7a9956  8b06                             mov    eax,DWORD PTR [esi]
0x7a9958  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a995b  8bce                             mov    ecx,esi
0x7a995d  ffd2                             call   edx
0x7a995f  b801000000                       mov    eax,0x1
0x7a9964  894324                           mov    DWORD PTR [ebx+0x24],eax
0x7a9967  898318010000                     mov    DWORD PTR [ebx+0x118],eax
0x7a996d  ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x7a9973  2b4590                           sub    eax,DWORD PTR [ebp-0x70]
0x7a9976  50                               push   eax
0x7a9977  6838f6c400                       push   0xc4f638
0x7a997c  e83c970e00                       call   0x8930bd
0x7a9981  83c408                           add    esp,0x8
0x7a9984  c645fc10                         mov    BYTE PTR [ebp-0x4],0x10
0x7a9988  8b8558ffffff                     mov    eax,DWORD PTR [ebp-0xa8]
0x7a998e  8b08                             mov    ecx,DWORD PTR [eax]
0x7a9990  50                               push   eax
0x7a9991  51                               push   ecx
0x7a9992  8d7594                           lea    esi,[ebp-0x6c]
0x7a9995  8d8554ffffff                     lea    eax,[ebp-0xac]
0x7a999b  e880d7f2ff                       call   0x6d7120
0x7a99a0  8b8558ffffff                     mov    eax,DWORD PTR [ebp-0xa8]
0x7a99a6  50                               push   eax
0x7a99a7  e860780e00                       call   0x89120c
0x7a99ac  83c404                           add    esp,0x4
0x7a99af  8d8d7cffffff                     lea    ecx,[ebp-0x84]
0x7a99b5  894d94                           mov    DWORD PTR [ebp-0x6c],ecx
0x7a99b8  c645fc12                         mov    BYTE PTR [ebp-0x4],0x12
0x7a99bc  8b4580                           mov    eax,DWORD PTR [ebp-0x80]
0x7a99bf  8b08                             mov    ecx,DWORD PTR [eax]
0x7a99c1  50                               push   eax
0x7a99c2  51                               push   ecx
0x7a99c3  8db538ffffff                     lea    esi,[ebp-0xc8]
0x7a99c9  8d857cffffff                     lea    eax,[ebp-0x84]
0x7a99cf  e84cd7f2ff                       call   0x6d7120
0x7a99d4  8b5580                           mov    edx,DWORD PTR [ebp-0x80]
0x7a99d7  52                               push   edx
0x7a99d8  e82f780e00                       call   0x89120c
0x7a99dd  83c404                           add    esp,0x4
0x7a99e0  c645fc13                         mov    BYTE PTR [ebp-0x4],0x13
0x7a99e4  8b8570ffffff                     mov    eax,DWORD PTR [ebp-0x90]
0x7a99ea  8b08                             mov    ecx,DWORD PTR [eax]
0x7a99ec  50                               push   eax
0x7a99ed  51                               push   ecx
0x7a99ee  8db530ffffff                     lea    esi,[ebp-0xd0]
0x7a99f4  8d856cffffff                     lea    eax,[ebp-0x94]
0x7a99fa  e86107d2ff                       call   0x4ca160
0x7a99ff  8b8570ffffff                     mov    eax,DWORD PTR [ebp-0x90]
0x7a9a05  50                               push   eax
0x7a9a06  e801780e00                       call   0x89120c
0x7a9a0b  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x7a9a12  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x7a9a15  83c404                           add    esp,0x4
0x7a9a18  85c0                             test   eax,eax
0x7a9a1a  742b                             je     0x7a9a47
0x7a9a1c  8bf0                             mov    esi,eax
0x7a9a1e  83c004                           add    eax,0x4
0x7a9a21  83c9ff                           or     ecx,0xffffffff
0x7a9a24  f00fc108                         lock xadd DWORD PTR [eax],ecx
0x7a9a28  751d                             jne    0x7a9a47
0x7a9a2a  8b16                             mov    edx,DWORD PTR [esi]
0x7a9a2c  8b02                             mov    eax,DWORD PTR [edx]
0x7a9a2e  8bce                             mov    ecx,esi
0x7a9a30  ffd0                             call   eax
0x7a9a32  83caff                           or     edx,0xffffffff
0x7a9a35  8d4e08                           lea    ecx,[esi+0x8]
0x7a9a38  f00fc111                         lock xadd DWORD PTR [ecx],edx
0x7a9a3c  7509                             jne    0x7a9a47
0x7a9a3e  8b06                             mov    eax,DWORD PTR [esi]
0x7a9a40  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a9a43  8bce                             mov    ecx,esi
0x7a9a45  ffd2                             call   edx
0x7a9a47  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7a9a4a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a9a51  59                               pop    ecx
0x7a9a52  5f                               pop    edi
0x7a9a53  5e                               pop    esi
0x7a9a54  5b                               pop    ebx
0x7a9a55  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0x7a9a58  33cd                             xor    ecx,ebp
0x7a9a5a  e8a2750e00                       call   0x891001
0x7a9a5f  8be5                             mov    esp,ebp
0x7a9a61  5d                               pop    ebp
0x7a9a62  c20c00                           ret    0xc
0x7a9a65  cc                               int3
0x7a9a66  cc                               int3
0x7a9a67  cc                               int3
0x7a9a68  cc                               int3
0x7a9a69  cc                               int3
0x7a9a6a  cc                               int3
0x7a9a6b  cc                               int3
0x7a9a6c  cc                               int3
0x7a9a6d  cc                               int3
0x7a9a6e  cc                               int3
0x7a9a6f  cc                               int3

; actor_doll_tick | actor+15C -> 7A5C50 when actor+370 active
; VA 0x4c87d0..0x4c88f0 raw 0xc7bd0 length 288 sha256 a9c9fbd7b958daf039f178e85eb56dc6fa987c1752750a4ca15430003456bcc9
0x4c87d0  55                               push   ebp
0x4c87d1  8bec                             mov    ebp,esp
0x4c87d3  83ec10                           sub    esp,0x10
0x4c87d6  56                               push   esi
0x4c87d7  8bf1                             mov    esi,ecx
0x4c87d9  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
0x4c87e0  0f84e8000000                     je     0x4c88ce
0x4c87e6  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
0x4c87ec  85c0                             test   eax,eax
0x4c87ee  740f                             je     0x4c87ff
0x4c87f0  d94508                           fld    DWORD PTR [ebp+0x8]
0x4c87f3  6a00                             push   0x0
0x4c87f5  51                               push   ecx
0x4c87f6  d91c24                           fstp   DWORD PTR [esp]
0x4c87f9  50                               push   eax
0x4c87fa  e851d42d00                       call   0x7a5c50
0x4c87ff  8b8664030000                     mov    eax,DWORD PTR [esi+0x364]
0x4c8805  57                               push   edi
0x4c8806  85c0                             test   eax,eax
0x4c8808  7415                             je     0x4c881f
0x4c880a  8b4024                           mov    eax,DWORD PTR [eax+0x24]
0x4c880d  85c0                             test   eax,eax
0x4c880f  740e                             je     0x4c881f
0x4c8811  d94508                           fld    DWORD PTR [ebp+0x8]
0x4c8814  51                               push   ecx
0x4c8815  8bf8                             mov    edi,eax
0x4c8817  d91c24                           fstp   DWORD PTR [esp]
0x4c881a  e8b1502f00                       call   0x7bd8d0
0x4c881f  53                               push   ebx
0x4c8820  8d9e64010000                     lea    ebx,[esi+0x164]
0x4c8826  c745fc80000000                   mov    DWORD PTR [ebp-0x4],0x80
0x4c882d  8d4900                           lea    ecx,[ecx+0x0]
0x4c8830  8b03                             mov    eax,DWORD PTR [ebx]
0x4c8832  85c0                             test   eax,eax
0x4c8834  7415                             je     0x4c884b
0x4c8836  8b4024                           mov    eax,DWORD PTR [eax+0x24]
0x4c8839  85c0                             test   eax,eax
0x4c883b  740e                             je     0x4c884b
0x4c883d  d94508                           fld    DWORD PTR [ebp+0x8]
0x4c8840  51                               push   ecx
0x4c8841  8bf8                             mov    edi,eax
0x4c8843  d91c24                           fstp   DWORD PTR [esp]
0x4c8846  e885502f00                       call   0x7bd8d0
0x4c884b  83c304                           add    ebx,0x4
0x4c884e  ff4dfc                           dec    DWORD PTR [ebp-0x4]
0x4c8851  75dd                             jne    0x4c8830
0x4c8853  83be6803000000                   cmp    DWORD PTR [esi+0x368],0x0
0x4c885a  5b                               pop    ebx
0x4c885b  7470                             je     0x4c88cd
0x4c885d  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
0x4c8864  7467                             je     0x4c88cd
0x4c8866  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
0x4c886c  8d8ea0000000                     lea    ecx,[esi+0xa0]
0x4c8872  85c0                             test   eax,eax
0x4c8874  7419                             je     0x4c888f
0x4c8876  d9ee                             fldz
0x4c8878  51                               push   ecx
0x4c8879  8d7df0                           lea    edi,[ebp-0x10]
0x4c887c  d91c24                           fstp   DWORD PTR [esp]
0x4c887f  e8acfd2d00                       call   0x7a8630
0x4c8884  8b4df8                           mov    ecx,DWORD PTR [ebp-0x8]
0x4c8887  8b7df4                           mov    edi,DWORD PTR [ebp-0xc]
0x4c888a  8b55f0                           mov    edx,DWORD PTR [ebp-0x10]
0x4c888d  eb08                             jmp    0x4c8897
0x4c888f  8b11                             mov    edx,DWORD PTR [ecx]
0x4c8891  8b7904                           mov    edi,DWORD PTR [ecx+0x4]
0x4c8894  8b4908                           mov    ecx,DWORD PTR [ecx+0x8]
0x4c8897  8b8668030000                     mov    eax,DWORD PTR [esi+0x368]
0x4c889d  895010                           mov    DWORD PTR [eax+0x10],edx
0x4c88a0  897814                           mov    DWORD PTR [eax+0x14],edi
0x4c88a3  894818                           mov    DWORD PTR [eax+0x18],ecx
0x4c88a6  8b8e68030000                     mov    ecx,DWORD PTR [esi+0x368]
0x4c88ac  d9412c                           fld    DWORD PTR [ecx+0x2c]
0x4c88af  d84508                           fadd   DWORD PTR [ebp+0x8]
0x4c88b2  d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x4c88b5  d945fc                           fld    DWORD PTR [ebp-0x4]
0x4c88b8  d9512c                           fst    DWORD PTR [ecx+0x2c]
0x4c88bb  d9e8                             fld1
0x4c88bd  d9c9                             fxch   st(1)
0x4c88bf  dff1                             fcomip st,st(1)
0x4c88c1  ddd8                             fstp   st(0)
0x4c88c3  7608                             jbe    0x4c88cd
0x4c88c5  0f57c0                           xorps  xmm0,xmm0
0x4c88c8  f30f11412c                       movss  DWORD PTR [ecx+0x2c],xmm0
0x4c88cd  5f                               pop    edi
0x4c88ce  8b8e58010000                     mov    ecx,DWORD PTR [esi+0x158]
0x4c88d4  d94508                           fld    DWORD PTR [ebp+0x8]
0x4c88d7  8b01                             mov    eax,DWORD PTR [ecx]
0x4c88d9  8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x4c88dc  51                               push   ecx
0x4c88dd  d91c24                           fstp   DWORD PTR [esp]
0x4c88e0  ffd2                             call   edx
0x4c88e2  33c0                             xor    eax,eax
0x4c88e4  5e                               pop    esi
0x4c88e5  8be5                             mov    esp,ebp
0x4c88e7  5d                               pop    ebp
0x4c88e8  c20400                           ret    0x4
0x4c88eb  cc                               int3
0x4c88ec  cc                               int3
0x4c88ed  cc                               int3
0x4c88ee  cc                               int3
0x4c88ef  cc                               int3

; actor_doll_draw | actor+15C virtual+8 -> CDoll draw
; VA 0x4c88f0..0x4c89a0 raw 0xc7cf0 length 176 sha256 aff4408c90c056b534f165232453338beba15a42dbd3383049eecc5034f10052
0x4c88f0  55                               push   ebp
0x4c88f1  8bec                             mov    ebp,esp
0x4c88f3  51                               push   ecx
0x4c88f4  53                               push   ebx
0x4c88f5  56                               push   esi
0x4c88f6  57                               push   edi
0x4c88f7  8bf9                             mov    edi,ecx
0x4c88f9  83bf7003000000                   cmp    DWORD PTR [edi+0x370],0x0
0x4c8900  0f8491000000                     je     0x4c8997
0x4c8906  8b8f5c010000                     mov    ecx,DWORD PTR [edi+0x15c]
0x4c890c  85c9                             test   ecx,ecx
0x4c890e  7407                             je     0x4c8917
0x4c8910  8b01                             mov    eax,DWORD PTR [ecx]
0x4c8912  8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x4c8915  ffd2                             call   edx
0x4c8917  8b8764030000                     mov    eax,DWORD PTR [edi+0x364]
0x4c891d  85c0                             test   eax,eax
0x4c891f  740d                             je     0x4c892e
0x4c8921  8b4024                           mov    eax,DWORD PTR [eax+0x24]
0x4c8924  85c0                             test   eax,eax
0x4c8926  7406                             je     0x4c892e
0x4c8928  50                               push   eax
0x4c8929  e812562f00                       call   0x7bdf40
0x4c892e  8db764010000                     lea    esi,[edi+0x164]
0x4c8934  bb80000000                       mov    ebx,0x80
0x4c8939  8da42400000000                   lea    esp,[esp+0x0]
0x4c8940  8b06                             mov    eax,DWORD PTR [esi]
0x4c8942  85c0                             test   eax,eax
0x4c8944  740d                             je     0x4c8953
0x4c8946  8b4024                           mov    eax,DWORD PTR [eax+0x24]
0x4c8949  85c0                             test   eax,eax
0x4c894b  7406                             je     0x4c8953
0x4c894d  50                               push   eax
0x4c894e  e8ed552f00                       call   0x7bdf40
0x4c8953  83c604                           add    esi,0x4
0x4c8956  4b                               dec    ebx
0x4c8957  75e7                             jne    0x4c8940
0x4c8959  399f68030000                     cmp    DWORD PTR [edi+0x368],ebx
0x4c895f  7436                             je     0x4c8997
0x4c8961  57                               push   edi
0x4c8962  e8190c0000                       call   0x4c9580
0x4c8967  8b07                             mov    eax,DWORD PTR [edi]
0x4c8969  8b5070                           mov    edx,DWORD PTR [eax+0x70]
0x4c896c  8bcf                             mov    ecx,edi
0x4c896e  ffd2                             call   edx
0x4c8970  83f864                           cmp    eax,0x64
0x4c8973  7c0b                             jl     0x4c8980
0x4c8975  8b8768030000                     mov    eax,DWORD PTR [edi+0x368]
0x4c897b  395828                           cmp    DWORD PTR [eax+0x28],ebx
0x4c897e  7417                             je     0x4c8997
0x4c8980  8bbf68030000                     mov    edi,DWORD PTR [edi+0x368]
0x4c8986  837f2400                         cmp    DWORD PTR [edi+0x24],0x0
0x4c898a  740b                             je     0x4c8997
0x4c898c  8d45fc                           lea    eax,[ebp-0x4]
0x4c898f  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4c8992  e8e9c52e00                       call   0x7b4f80
0x4c8997  5f                               pop    edi
0x4c8998  5e                               pop    esi
0x4c8999  33c0                             xor    eax,eax
0x4c899b  5b                               pop    ebx
0x4c899c  8be5                             mov    esp,ebp
0x4c899e  5d                               pop    ebp
0x4c899f  c3                               ret

; q_ani | Q slot -> actor virtual+68
; VA 0x5634e0..0x563530 raw 0x1628e0 length 80 sha256 7b51440dbfe32c8cff5ffe9e94fbf61300bc78e3501580fc4e0e5b64eaa7ca9e
0x5634e0  55                               push   ebp
0x5634e1  8bec                             mov    ebp,esp
0x5634e3  51                               push   ecx
0x5634e4  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5634e7  56                               push   esi
0x5634e8  8bf1                             mov    esi,ecx
0x5634ea  8d4d08                           lea    ecx,[ebp+0x8]
0x5634ed  894508                           mov    DWORD PTR [ebp+0x8],eax
0x5634f0  51                               push   ecx
0x5634f1  8d4e18                           lea    ecx,[esi+0x18]
0x5634f4  8d45fc                           lea    eax,[ebp-0x4]
0x5634f7  e804ba2c00                       call   0x82ef00
0x5634fc  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x5634ff  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
0x563502  5e                               pop    esi
0x563503  7419                             je     0x56351e
0x563505  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0x563508  85c9                             test   ecx,ecx
0x56350a  7412                             je     0x56351e
0x56350c  8b11                             mov    edx,DWORD PTR [ecx]
0x56350e  d94510                           fld    DWORD PTR [ebp+0x10]
0x563511  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x563514  8b5268                           mov    edx,DWORD PTR [edx+0x68]
0x563517  51                               push   ecx
0x563518  d91c24                           fstp   DWORD PTR [esp]
0x56351b  50                               push   eax
0x56351c  ffd2                             call   edx
0x56351e  8be5                             mov    esp,ebp
0x563520  5d                               pop    ebp
0x563521  c20c00                           ret    0xc
0x563524  cc                               int3
0x563525  cc                               int3
0x563526  cc                               int3
0x563527  cc                               int3
0x563528  cc                               int3
0x563529  cc                               int3
0x56352a  cc                               int3
0x56352b  cc                               int3
0x56352c  cc                               int3
0x56352d  cc                               int3
0x56352e  cc                               int3
0x56352f  cc                               int3

; q_ani_skip | integer frame-step/current setting; animation time clamp
; VA 0x563530..0x563660 raw 0x162930 length 304 sha256 1f7bcfdfa474641077ad03daeb8a7f71ecd23a2424a24a7e9fe893cdee7a2519
0x563530  55                               push   ebp
0x563531  8bec                             mov    ebp,esp
0x563533  83ec08                           sub    esp,0x8
0x563536  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x563539  56                               push   esi
0x56353a  8bf1                             mov    esi,ecx
0x56353c  57                               push   edi
0x56353d  8d4d08                           lea    ecx,[ebp+0x8]
0x563540  894508                           mov    DWORD PTR [ebp+0x8],eax
0x563543  51                               push   ecx
0x563544  8d4e18                           lea    ecx,[esi+0x18]
0x563547  8d45fc                           lea    eax,[ebp-0x4]
0x56354a  e8b1b92c00                       call   0x82ef00
0x56354f  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x563552  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
0x563555  0f84f3000000                     je     0x56364e
0x56355b  8b7810                           mov    edi,DWORD PTR [eax+0x10]
0x56355e  85ff                             test   edi,edi
0x563560  0f84e8000000                     je     0x56364e
0x563566  a1cca7fb00                       mov    eax,ds:0xfba7cc
0x56356b  85c0                             test   eax,eax
0x56356d  751f                             jne    0x56358e
0x56356f  6880130000                       push   0x1380
0x563574  e8efdc3200                       call   0x891268
0x563579  83c404                           add    esp,0x4
0x56357c  85c0                             test   eax,eax
0x56357e  7407                             je     0x563587
0x563580  e84bbe1700                       call   0x6df3d0
0x563585  eb02                             jmp    0x563589
0x563587  33c0                             xor    eax,eax
0x563589  a3cca7fb00                       mov    ds:0xfba7cc,eax
0x56358e  db450c                           fild   DWORD PTR [ebp+0xc]
0x563591  0f57c0                           xorps  xmm0,xmm0
0x563594  dab060130000                     fidiv  DWORD PTR [eax+0x1360]
0x56359a  8b875c010000                     mov    eax,DWORD PTR [edi+0x15c]
0x5635a0  d95d0c                           fstp   DWORD PTR [ebp+0xc]
0x5635a3  85c0                             test   eax,eax
0x5635a5  7418                             je     0x5635bf
0x5635a7  83bf7003000000                   cmp    DWORD PTR [edi+0x370],0x0
0x5635ae  740f                             je     0x5635bf
0x5635b0  f30f1088b4000000                 movss  xmm1,DWORD PTR [eax+0xb4]
0x5635b8  f30f114d08                       movss  DWORD PTR [ebp+0x8],xmm1
0x5635bd  eb05                             jmp    0x5635c4
0x5635bf  f30f114508                       movss  DWORD PTR [ebp+0x8],xmm0
0x5635c4  d94508                           fld    DWORD PTR [ebp+0x8]
0x5635c7  d8450c                           fadd   DWORD PTR [ebp+0xc]
0x5635ca  d95d08                           fstp   DWORD PTR [ebp+0x8]
0x5635cd  85c0                             test   eax,eax
0x5635cf  7429                             je     0x5635fa
0x5635d1  83bf7003000000                   cmp    DWORD PTR [edi+0x370],0x0
0x5635d8  7420                             je     0x5635fa
0x5635da  83b8ac00000000                   cmp    DWORD PTR [eax+0xac],0x0
0x5635e1  7417                             je     0x5635fa
0x5635e3  8b80ac000000                     mov    eax,DWORD PTR [eax+0xac]
0x5635e9  8b10                             mov    edx,DWORD PTR [eax]
0x5635eb  8bc8                             mov    ecx,eax
0x5635ed  8b420c                           mov    eax,DWORD PTR [edx+0xc]
0x5635f0  ffd0                             call   eax
0x5635f2  d95d0c                           fstp   DWORD PTR [ebp+0xc]
0x5635f5  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
0x5635fa  8bb75c010000                     mov    esi,DWORD PTR [edi+0x15c]
0x563600  f30f11450c                       movss  DWORD PTR [ebp+0xc],xmm0
0x563605  85f6                             test   esi,esi
0x563607  7415                             je     0x56361e
0x563609  83bf7003000000                   cmp    DWORD PTR [edi+0x370],0x0
0x563610  740c                             je     0x56361e
0x563612  d94508                           fld    DWORD PTR [ebp+0x8]
0x563615  51                               push   ecx
0x563616  d91c24                           fstp   DWORD PTR [esp]
0x563619  e812322400                       call   0x7a6830
0x56361e  d9450c                           fld    DWORD PTR [ebp+0xc]
0x563621  d94508                           fld    DWORD PTR [ebp+0x8]
0x563624  dff1                             fcomip st,st(1)
0x563626  7224                             jb     0x56364c
0x563628  8bb75c010000                     mov    esi,DWORD PTR [edi+0x15c]
0x56362e  85f6                             test   esi,esi
0x563630  741a                             je     0x56364c
0x563632  83bf7003000000                   cmp    DWORD PTR [edi+0x370],0x0
0x563639  7411                             je     0x56364c
0x56363b  51                               push   ecx
0x56363c  d91c24                           fstp   DWORD PTR [esp]
0x56363f  e8ec312400                       call   0x7a6830
0x563644  5f                               pop    edi
0x563645  5e                               pop    esi
0x563646  8be5                             mov    esp,ebp
0x563648  5d                               pop    ebp
0x563649  c20800                           ret    0x8
0x56364c  ddd8                             fstp   st(0)
0x56364e  5f                               pop    edi
0x56364f  5e                               pop    esi
0x563650  8be5                             mov    esp,ebp
0x563652  5d                               pop    ebp
0x563653  c20800                           ret    0x8
0x563656  cc                               int3
0x563657  cc                               int3
0x563658  cc                               int3
0x563659  cc                               int3
0x56365a  cc                               int3
0x56365b  cc                               int3
0x56365c  cc                               int3
0x56365d  cc                               int3
0x56365e  cc                               int3
0x56365f  cc                               int3

; q_rotate | byte direction, optional immediate renderer yaw
; VA 0x563660..0x5636f0 raw 0x162a60 length 144 sha256 3717b172550298451d1187b8772991698cd12f81462d936abedf3c375faa94b1
0x563660  55                               push   ebp
0x563661  8bec                             mov    ebp,esp
0x563663  51                               push   ecx
0x563664  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x563667  56                               push   esi
0x563668  8bf1                             mov    esi,ecx
0x56366a  57                               push   edi
0x56366b  8d4d08                           lea    ecx,[ebp+0x8]
0x56366e  894508                           mov    DWORD PTR [ebp+0x8],eax
0x563671  51                               push   ecx
0x563672  8d4e18                           lea    ecx,[esi+0x18]
0x563675  8d45fc                           lea    eax,[ebp-0x4]
0x563678  e883b82c00                       call   0x82ef00
0x56367d  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x563680  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
0x563683  745f                             je     0x5636e4
0x563685  8b7010                           mov    esi,DWORD PTR [eax+0x10]
0x563688  85f6                             test   esi,esi
0x56368a  7458                             je     0x5636e4
0x56368c  8b16                             mov    edx,DWORD PTR [esi]
0x56368e  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x563691  8b5258                           mov    edx,DWORD PTR [edx+0x58]
0x563694  50                               push   eax
0x563695  8bce                             mov    ecx,esi
0x563697  ffd2                             call   edx
0x563699  837d1000                         cmp    DWORD PTR [ebp+0x10],0x0
0x56369d  7545                             jne    0x5636e4
0x56369f  83bea803000000                   cmp    DWORD PTR [esi+0x3a8],0x0
0x5636a6  8a86b0000000                     mov    al,BYTE PTR [esi+0xb0]
0x5636ac  884508                           mov    BYTE PTR [ebp+0x8],al
0x5636af  7533                             jne    0x5636e4
0x5636b1  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
0x5636b8  8886a4030000                     mov    BYTE PTR [esi+0x3a4],al
0x5636be  7424                             je     0x5636e4
0x5636c0  8bb65c010000                     mov    esi,DWORD PTR [esi+0x15c]
0x5636c6  85f6                             test   esi,esi
0x5636c8  741a                             je     0x5636e4
0x5636ca  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5636cd  8d7e04                           lea    edi,[esi+0x4]
0x5636d0  8b37                             mov    esi,DWORD PTR [edi]
0x5636d2  50                               push   eax
0x5636d3  e8b813eeff                       call   0x444a90
0x5636d8  8b560c                           mov    edx,DWORD PTR [esi+0xc]
0x5636db  8bcf                             mov    ecx,edi
0x5636dd  f30f110424                       movss  DWORD PTR [esp],xmm0
0x5636e2  ffd2                             call   edx
0x5636e4  5f                               pop    edi
0x5636e5  5e                               pop    esi
0x5636e6  8be5                             mov    esp,ebp
0x5636e8  5d                               pop    ebp
0x5636e9  c20c00                           ret    0xc
0x5636ec  cc                               int3
0x5636ed  cc                               int3
0x5636ee  cc                               int3
0x5636ef  cc                               int3

; q_speed | write CEventActor+434 movement multiplier
; VA 0x5636f0..0x563730 raw 0x162af0 length 64 sha256 bc2cb0a00d490bf939476f6a27013f9aaa08d0ff4994347c9d7734b0b4374156
0x5636f0  55                               push   ebp
0x5636f1  8bec                             mov    ebp,esp
0x5636f3  51                               push   ecx
0x5636f4  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5636f7  56                               push   esi
0x5636f8  8bf1                             mov    esi,ecx
0x5636fa  8d4d08                           lea    ecx,[ebp+0x8]
0x5636fd  894508                           mov    DWORD PTR [ebp+0x8],eax
0x563700  51                               push   ecx
0x563701  8d4e18                           lea    ecx,[esi+0x18]
0x563704  8d45fc                           lea    eax,[ebp-0x4]
0x563707  e8f4b72c00                       call   0x82ef00
0x56370c  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x56370f  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
0x563712  5e                               pop    esi
0x563713  7414                             je     0x563729
0x563715  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x563718  85c0                             test   eax,eax
0x56371a  740d                             je     0x563729
0x56371c  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
0x563721  f30f118034040000                 movss  DWORD PTR [eax+0x434],xmm0
0x563729  8be5                             mov    esp,ebp
0x56372b  5d                               pop    ebp
0x56372c  c20800                           ret    0x8
0x56372f  cc                               int3

; q_face | face ID and nonnegative duration override via virtual+6C
; VA 0x563730..0x563790 raw 0x162b30 length 96 sha256 dc9f19579c5f041bafb1874319b5b8f7958fd854bc8d8fc1e5d0b9bf4714467a
0x563730  55                               push   ebp
0x563731  8bec                             mov    ebp,esp
0x563733  51                               push   ecx
0x563734  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x563737  56                               push   esi
0x563738  8bf1                             mov    esi,ecx
0x56373a  8d4d08                           lea    ecx,[ebp+0x8]
0x56373d  894508                           mov    DWORD PTR [ebp+0x8],eax
0x563740  51                               push   ecx
0x563741  8d4e18                           lea    ecx,[esi+0x18]
0x563744  8d45fc                           lea    eax,[ebp-0x4]
0x563747  e8b4b72c00                       call   0x82ef00
0x56374c  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x56374f  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
0x563752  5e                               pop    esi
0x563753  7431                             je     0x563786
0x563755  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0x563758  85c9                             test   ecx,ecx
0x56375a  742a                             je     0x563786
0x56375c  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x56375f  8b11                             mov    edx,DWORD PTR [ecx]
0x563761  8b526c                           mov    edx,DWORD PTR [edx+0x6c]
0x563764  53                               push   ebx
0x563765  33db                             xor    ebx,ebx
0x563767  85c0                             test   eax,eax
0x563769  0f98c3                           sets   bl
0x56376c  0f57c0                           xorps  xmm0,xmm0
0x56376f  f30f2ac0                         cvtsi2ss xmm0,eax
0x563773  8d4508                           lea    eax,[ebp+0x8]
0x563776  f30f114508                       movss  DWORD PTR [ebp+0x8],xmm0
0x56377b  4b                               dec    ebx
0x56377c  23d8                             and    ebx,eax
0x56377e  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x563781  53                               push   ebx
0x563782  50                               push   eax
0x563783  ffd2                             call   edx
0x563785  5b                               pop    ebx
0x563786  8be5                             mov    esp,ebp
0x563788  5d                               pop    ebp
0x563789  c20c00                           ret    0xc
0x56378c  cc                               int3
0x56378d  cc                               int3
0x56378e  cc                               int3
0x56378f  cc                               int3

; q_flash | write actor flash mode, duration and counter
; VA 0x563790..0x5637e0 raw 0x162b90 length 80 sha256 edee80a301268c5626f1d825dcfb5b5546c7dc0c4a76952ac175facbd9c21317
0x563790  55                               push   ebp
0x563791  8bec                             mov    ebp,esp
0x563793  51                               push   ecx
0x563794  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x563797  56                               push   esi
0x563798  8bf1                             mov    esi,ecx
0x56379a  8d4d08                           lea    ecx,[ebp+0x8]
0x56379d  894508                           mov    DWORD PTR [ebp+0x8],eax
0x5637a0  51                               push   ecx
0x5637a1  8d4e18                           lea    ecx,[esi+0x18]
0x5637a4  8d45fc                           lea    eax,[ebp-0x4]
0x5637a7  e854b72c00                       call   0x82ef00
0x5637ac  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x5637af  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
0x5637b2  5e                               pop    esi
0x5637b3  741f                             je     0x5637d4
0x5637b5  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x5637b8  85c0                             test   eax,eax
0x5637ba  7418                             je     0x5637d4
0x5637bc  8b4d10                           mov    ecx,DWORD PTR [ebp+0x10]
0x5637bf  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x5637c2  898814040000                     mov    DWORD PTR [eax+0x414],ecx
0x5637c8  898810040000                     mov    DWORD PTR [eax+0x410],ecx
0x5637ce  89900c040000                     mov    DWORD PTR [eax+0x40c],edx
0x5637d4  8be5                             mov    esp,ebp
0x5637d6  5d                               pop    ebp
0x5637d7  c20c00                           ret    0xc
0x5637da  cc                               int3
0x5637db  cc                               int3
0x5637dc  cc                               int3
0x5637dd  cc                               int3
0x5637de  cc                               int3
0x5637df  cc                               int3

; q_ani_marshaller | slot int, motion int, animation rate float
; VA 0x56b0e0..0x56b210 raw 0x16a4e0 length 304 sha256 c4aeed1f9fdab36989b64f1553066c236cf0e9c03d64d8268f4e2e1a74832d5e
0x56b0e0  55                               push   ebp
0x56b0e1  8bec                             mov    ebp,esp
0x56b0e3  83ec30                           sub    esp,0x30
0x56b0e6  a1e427fe00                       mov    eax,ds:0xfe27e4
0x56b0eb  8b0d7827fe00                     mov    ecx,DWORD PTR ds:0xfe2778
0x56b0f1  53                               push   ebx
0x56b0f2  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x56b0f5  8945e0                           mov    DWORD PTR [ebp-0x20],eax
0x56b0f8  8b03                             mov    eax,DWORD PTR [ebx]
0x56b0fa  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x56b0fd  83e810                           sub    eax,0x10
0x56b100  894de4                           mov    DWORD PTR [ebp-0x1c],ecx
0x56b103  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56b106  56                               push   esi
0x56b107  57                               push   edi
0x56b108  83f903                           cmp    ecx,0x3
0x56b10b  742e                             je     0x56b13b
0x56b10d  83f904                           cmp    ecx,0x4
0x56b110  0f85e6000000                     jne    0x56b1fc
0x56b116  8b30                             mov    esi,DWORD PTR [eax]
0x56b118  83c610                           add    esi,0x10
0x56b11b  8d7de8                           lea    edi,[ebp-0x18]
0x56b11e  e83dc61800                       call   0x6f7760
0x56b123  85c0                             test   eax,eax
0x56b125  0f84d1000000                     je     0x56b1fc
0x56b12b  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x56b12e  c745d803000000                   mov    DWORD PTR [ebp-0x28],0x3
0x56b135  dd5dd0                           fstp   QWORD PTR [ebp-0x30]
0x56b138  8d45d0                           lea    eax,[ebp-0x30]
0x56b13b  dd00                             fld    QWORD PTR [eax]
0x56b13d  8b0b                             mov    ecx,DWORD PTR [ebx]
0x56b13f  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x56b142  b8feffffff                       mov    eax,0xfffffffe
0x56b147  e8a49f1800                       call   0x6f50f0
0x56b14c  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56b14f  83f903                           cmp    ecx,0x3
0x56b152  742e                             je     0x56b182
0x56b154  83f904                           cmp    ecx,0x4
0x56b157  0f85a6000000                     jne    0x56b203
0x56b15d  8b30                             mov    esi,DWORD PTR [eax]
0x56b15f  83c610                           add    esi,0x10
0x56b162  8d7df0                           lea    edi,[ebp-0x10]
0x56b165  e8f6c51800                       call   0x6f7760
0x56b16a  85c0                             test   eax,eax
0x56b16c  0f8491000000                     je     0x56b203
0x56b172  dd45f0                           fld    QWORD PTR [ebp-0x10]
0x56b175  c745d803000000                   mov    DWORD PTR [ebp-0x28],0x3
0x56b17c  dd5dd0                           fstp   QWORD PTR [ebp-0x30]
0x56b17f  8d45d0                           lea    eax,[ebp-0x30]
0x56b182  dd00                             fld    QWORD PTR [eax]
0x56b184  dd5df0                           fstp   QWORD PTR [ebp-0x10]
0x56b187  dd45f0                           fld    QWORD PTR [ebp-0x10]
0x56b18a  db5d08                           fistp  DWORD PTR [ebp+0x8]
0x56b18d  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x56b190  8955f4                           mov    DWORD PTR [ebp-0xc],edx
0x56b193  8b0b                             mov    ecx,DWORD PTR [ebx]
0x56b195  b8fdffffff                       mov    eax,0xfffffffd
0x56b19a  e8519f1800                       call   0x6f50f0
0x56b19f  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56b1a2  83f903                           cmp    ecx,0x3
0x56b1a5  7426                             je     0x56b1cd
0x56b1a7  83f904                           cmp    ecx,0x4
0x56b1aa  7560                             jne    0x56b20c
0x56b1ac  8b30                             mov    esi,DWORD PTR [eax]
0x56b1ae  83c610                           add    esi,0x10
0x56b1b1  8d7df8                           lea    edi,[ebp-0x8]
0x56b1b4  e8a7c51800                       call   0x6f7760
0x56b1b9  85c0                             test   eax,eax
0x56b1bb  744f                             je     0x56b20c
0x56b1bd  dd45f8                           fld    QWORD PTR [ebp-0x8]
0x56b1c0  c745d803000000                   mov    DWORD PTR [ebp-0x28],0x3
0x56b1c7  dd5dd0                           fstp   QWORD PTR [ebp-0x30]
0x56b1ca  8d45d0                           lea    eax,[ebp-0x30]
0x56b1cd  dd00                             fld    QWORD PTR [eax]
0x56b1cf  dd5dd8                           fstp   QWORD PTR [ebp-0x28]
0x56b1d2  dd45d8                           fld    QWORD PTR [ebp-0x28]
0x56b1d5  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x56b1d8  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x56b1db  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x56b1de  51                               push   ecx
0x56b1df  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x56b1e2  d95dec                           fstp   DWORD PTR [ebp-0x14]
0x56b1e5  d945ec                           fld    DWORD PTR [ebp-0x14]
0x56b1e8  d91c24                           fstp   DWORD PTR [esp]
0x56b1eb  51                               push   ecx
0x56b1ec  8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
0x56b1ef  50                               push   eax
0x56b1f0  ff55e0                           call   DWORD PTR [ebp-0x20]
0x56b1f3  5f                               pop    edi
0x56b1f4  5e                               pop    esi
0x56b1f5  33c0                             xor    eax,eax
0x56b1f7  5b                               pop    ebx
0x56b1f8  8be5                             mov    esp,ebp
0x56b1fa  5d                               pop    ebp
0x56b1fb  c3                               ret
0x56b1fc  d9ee                             fldz
0x56b1fe  e93affffff                       jmp    0x56b13d
0x56b203  c745f400000000                   mov    DWORD PTR [ebp-0xc],0x0
0x56b20a  eb87                             jmp    0x56b193
0x56b20c  33c0                             xor    eax,eax
0x56b20e  ebcb                             jmp    0x56b1db

; q_speed_marshaller | slot int, movement multiplier float
; VA 0x56b210..0x56b2e0 raw 0x16a610 length 208 sha256 7e0c5ae9aec73ab31c2ebee0995b5f66670df107ab0e4500d868ed99ace5dd86
0x56b210  55                               push   ebp
0x56b211  8bec                             mov    ebp,esp
0x56b213  83ec20                           sub    esp,0x20
0x56b216  a1f027fe00                       mov    eax,ds:0xfe27f0
0x56b21b  8b0d7827fe00                     mov    ecx,DWORD PTR ds:0xfe2778
0x56b221  53                               push   ebx
0x56b222  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x56b225  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x56b228  8b03                             mov    eax,DWORD PTR [ebx]
0x56b22a  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x56b22d  83e810                           sub    eax,0x10
0x56b230  894df4                           mov    DWORD PTR [ebp-0xc],ecx
0x56b233  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56b236  56                               push   esi
0x56b237  57                               push   edi
0x56b238  83f903                           cmp    ecx,0x3
0x56b23b  742a                             je     0x56b267
0x56b23d  83f904                           cmp    ecx,0x4
0x56b240  0f858b000000                     jne    0x56b2d1
0x56b246  8b30                             mov    esi,DWORD PTR [eax]
0x56b248  83c610                           add    esi,0x10
0x56b24b  8d7df8                           lea    edi,[ebp-0x8]
0x56b24e  e80dc51800                       call   0x6f7760
0x56b253  85c0                             test   eax,eax
0x56b255  747a                             je     0x56b2d1
0x56b257  dd45f8                           fld    QWORD PTR [ebp-0x8]
0x56b25a  c745e803000000                   mov    DWORD PTR [ebp-0x18],0x3
0x56b261  dd5de0                           fstp   QWORD PTR [ebp-0x20]
0x56b264  8d45e0                           lea    eax,[ebp-0x20]
0x56b267  dd00                             fld    QWORD PTR [eax]
0x56b269  8b0b                             mov    ecx,DWORD PTR [ebx]
0x56b26b  dd5df8                           fstp   QWORD PTR [ebp-0x8]
0x56b26e  b8feffffff                       mov    eax,0xfffffffe
0x56b273  e8789e1800                       call   0x6f50f0
0x56b278  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56b27b  83f903                           cmp    ecx,0x3
0x56b27e  7426                             je     0x56b2a6
0x56b280  83f904                           cmp    ecx,0x4
0x56b283  7550                             jne    0x56b2d5
0x56b285  8b30                             mov    esi,DWORD PTR [eax]
0x56b287  83c610                           add    esi,0x10
0x56b28a  8d7de8                           lea    edi,[ebp-0x18]
0x56b28d  e8cec41800                       call   0x6f7760
0x56b292  85c0                             test   eax,eax
0x56b294  743f                             je     0x56b2d5
0x56b296  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x56b299  c745e803000000                   mov    DWORD PTR [ebp-0x18],0x3
0x56b2a0  dd5de0                           fstp   QWORD PTR [ebp-0x20]
0x56b2a3  8d45e0                           lea    eax,[ebp-0x20]
0x56b2a6  dd00                             fld    QWORD PTR [eax]
0x56b2a8  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x56b2ab  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x56b2ae  db5d08                           fistp  DWORD PTR [ebp+0x8]
0x56b2b1  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x56b2b4  dd45f8                           fld    QWORD PTR [ebp-0x8]
0x56b2b7  51                               push   ecx
0x56b2b8  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x56b2bb  d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x56b2be  d945fc                           fld    DWORD PTR [ebp-0x4]
0x56b2c1  d91c24                           fstp   DWORD PTR [esp]
0x56b2c4  50                               push   eax
0x56b2c5  ff55f0                           call   DWORD PTR [ebp-0x10]
0x56b2c8  5f                               pop    edi
0x56b2c9  5e                               pop    esi
0x56b2ca  33c0                             xor    eax,eax
0x56b2cc  5b                               pop    ebx
0x56b2cd  8be5                             mov    esp,ebp
0x56b2cf  5d                               pop    ebp
0x56b2d0  c3                               ret
0x56b2d1  d9ee                             fldz
0x56b2d3  eb94                             jmp    0x56b269
0x56b2d5  33c0                             xor    eax,eax
0x56b2d7  ebdb                             jmp    0x56b2b4
0x56b2d9  cc                               int3
0x56b2da  cc                               int3
0x56b2db  cc                               int3
0x56b2dc  cc                               int3
0x56b2dd  cc                               int3
0x56b2de  cc                               int3
0x56b2df  cc                               int3

; q_three_integer_marshaller | RotateObject/FaceObject/FlashObject exact three integers
; VA 0x56a4b0..0x56a5f0 raw 0x1698b0 length 320 sha256 973ff48115678e3528e584ce1700ad01ba0a2f3ce6380268b77d847a152aa9b6
0x56a4b0  55                               push   ebp
0x56a4b1  8bec                             mov    ebp,esp
0x56a4b3  83ec2c                           sub    esp,0x2c
0x56a4b6  a17827fe00                       mov    eax,ds:0xfe2778
0x56a4bb  53                               push   ebx
0x56a4bc  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x56a4bf  8b0b                             mov    ecx,DWORD PTR [ebx]
0x56a4c1  56                               push   esi
0x56a4c2  8945e4                           mov    DWORD PTR [ebp-0x1c],eax
0x56a4c5  57                               push   edi
0x56a4c6  83c8ff                           or     eax,0xffffffff
0x56a4c9  e822ac1800                       call   0x6f50f0
0x56a4ce  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56a4d1  83f903                           cmp    ecx,0x3
0x56a4d4  742e                             je     0x56a504
0x56a4d6  83f904                           cmp    ecx,0x4
0x56a4d9  0f85e9000000                     jne    0x56a5c8
0x56a4df  8b30                             mov    esi,DWORD PTR [eax]
0x56a4e1  83c610                           add    esi,0x10
0x56a4e4  8d7de8                           lea    edi,[ebp-0x18]
0x56a4e7  e874d21800                       call   0x6f7760
0x56a4ec  85c0                             test   eax,eax
0x56a4ee  0f84d4000000                     je     0x56a5c8
0x56a4f4  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x56a4f7  c745dc03000000                   mov    DWORD PTR [ebp-0x24],0x3
0x56a4fe  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0x56a501  8d45d4                           lea    eax,[ebp-0x2c]
0x56a504  dd00                             fld    QWORD PTR [eax]
0x56a506  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x56a509  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x56a50c  db5d08                           fistp  DWORD PTR [ebp+0x8]
0x56a50f  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x56a512  894df0                           mov    DWORD PTR [ebp-0x10],ecx
0x56a515  8b0b                             mov    ecx,DWORD PTR [ebx]
0x56a517  b8feffffff                       mov    eax,0xfffffffe
0x56a51c  e8cfab1800                       call   0x6f50f0
0x56a521  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56a524  83f903                           cmp    ecx,0x3
0x56a527  742e                             je     0x56a557
0x56a529  83f904                           cmp    ecx,0x4
0x56a52c  0f85a2000000                     jne    0x56a5d4
0x56a532  8b30                             mov    esi,DWORD PTR [eax]
0x56a534  83c610                           add    esi,0x10
0x56a537  8d7de8                           lea    edi,[ebp-0x18]
0x56a53a  e821d21800                       call   0x6f7760
0x56a53f  85c0                             test   eax,eax
0x56a541  0f848d000000                     je     0x56a5d4
0x56a547  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x56a54a  c745dc03000000                   mov    DWORD PTR [ebp-0x24],0x3
0x56a551  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0x56a554  8d45d4                           lea    eax,[ebp-0x2c]
0x56a557  dd00                             fld    QWORD PTR [eax]
0x56a559  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x56a55c  dd45e8                           fld    QWORD PTR [ebp-0x18]
0x56a55f  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x56a562  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x56a565  8955ec                           mov    DWORD PTR [ebp-0x14],edx
0x56a568  8b0b                             mov    ecx,DWORD PTR [ebx]
0x56a56a  b8fdffffff                       mov    eax,0xfffffffd
0x56a56f  e87cab1800                       call   0x6f50f0
0x56a574  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56a577  83f903                           cmp    ecx,0x3
0x56a57a  7426                             je     0x56a5a2
0x56a57c  83f904                           cmp    ecx,0x4
0x56a57f  755c                             jne    0x56a5dd
0x56a581  8b30                             mov    esi,DWORD PTR [eax]
0x56a583  83c610                           add    esi,0x10
0x56a586  8d7df4                           lea    edi,[ebp-0xc]
0x56a589  e8d2d11800                       call   0x6f7760
0x56a58e  85c0                             test   eax,eax
0x56a590  744b                             je     0x56a5dd
0x56a592  dd45f4                           fld    QWORD PTR [ebp-0xc]
0x56a595  c745dc03000000                   mov    DWORD PTR [ebp-0x24],0x3
0x56a59c  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0x56a59f  8d45d4                           lea    eax,[ebp-0x2c]
0x56a5a2  dd00                             fld    QWORD PTR [eax]
0x56a5a4  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0x56a5a7  dd45dc                           fld    QWORD PTR [ebp-0x24]
0x56a5aa  db5df8                           fistp  DWORD PTR [ebp-0x8]
0x56a5ad  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0x56a5b0  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x56a5b3  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
0x56a5b6  51                               push   ecx
0x56a5b7  8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
0x56a5ba  52                               push   edx
0x56a5bb  50                               push   eax
0x56a5bc  ff550c                           call   DWORD PTR [ebp+0xc]
0x56a5bf  5f                               pop    edi
0x56a5c0  5e                               pop    esi
0x56a5c1  33c0                             xor    eax,eax
0x56a5c3  5b                               pop    ebx
0x56a5c4  8be5                             mov    esp,ebp
0x56a5c6  5d                               pop    ebp
0x56a5c7  c3                               ret
0x56a5c8  c745f000000000                   mov    DWORD PTR [ebp-0x10],0x0
0x56a5cf  e941ffffff                       jmp    0x56a515
0x56a5d4  c745ec00000000                   mov    DWORD PTR [ebp-0x14],0x0
0x56a5db  eb8b                             jmp    0x56a568
0x56a5dd  33c0                             xor    eax,eax
0x56a5df  ebcf                             jmp    0x56a5b0
0x56a5e1  cc                               int3
0x56a5e2  cc                               int3
0x56a5e3  cc                               int3
0x56a5e4  cc                               int3
0x56a5e5  cc                               int3
0x56a5e6  cc                               int3
0x56a5e7  cc                               int3
0x56a5e8  cc                               int3
0x56a5e9  cc                               int3
0x56a5ea  cc                               int3
0x56a5eb  cc                               int3
0x56a5ec  cc                               int3
0x56a5ed  cc                               int3
0x56a5ee  cc                               int3
0x56a5ef  cc                               int3

; q_two_integer_marshaller | AniSkip exact two integers
; VA 0x56a220..0x56a300 raw 0x169620 length 224 sha256 6919618b7e107b6a9c27682e0f9422f8d3ea66ad778e212746401cd41938ab9b
0x56a220  55                               push   ebp
0x56a221  8bec                             mov    ebp,esp
0x56a223  83ec24                           sub    esp,0x24
0x56a226  a17827fe00                       mov    eax,ds:0xfe2778
0x56a22b  53                               push   ebx
0x56a22c  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x56a22f  8b0b                             mov    ecx,DWORD PTR [ebx]
0x56a231  56                               push   esi
0x56a232  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x56a235  57                               push   edi
0x56a236  83c8ff                           or     eax,0xffffffff
0x56a239  e8b2ae1800                       call   0x6f50f0
0x56a23e  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56a241  83f903                           cmp    ecx,0x3
0x56a244  742a                             je     0x56a270
0x56a246  83f904                           cmp    ecx,0x4
0x56a249  0f858e000000                     jne    0x56a2dd
0x56a24f  8b30                             mov    esi,DWORD PTR [eax]
0x56a251  83c610                           add    esi,0x10
0x56a254  8d7df0                           lea    edi,[ebp-0x10]
0x56a257  e804d51800                       call   0x6f7760
0x56a25c  85c0                             test   eax,eax
0x56a25e  747d                             je     0x56a2dd
0x56a260  dd45f0                           fld    QWORD PTR [ebp-0x10]
0x56a263  c745e403000000                   mov    DWORD PTR [ebp-0x1c],0x3
0x56a26a  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0x56a26d  8d45dc                           lea    eax,[ebp-0x24]
0x56a270  dd00                             fld    QWORD PTR [eax]
0x56a272  dd5df0                           fstp   QWORD PTR [ebp-0x10]
0x56a275  dd45f0                           fld    QWORD PTR [ebp-0x10]
0x56a278  db5d08                           fistp  DWORD PTR [ebp+0x8]
0x56a27b  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x56a27e  894df4                           mov    DWORD PTR [ebp-0xc],ecx
0x56a281  8b0b                             mov    ecx,DWORD PTR [ebx]
0x56a283  b8feffffff                       mov    eax,0xfffffffe
0x56a288  e863ae1800                       call   0x6f50f0
0x56a28d  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56a290  83f903                           cmp    ecx,0x3
0x56a293  7426                             je     0x56a2bb
0x56a295  83f904                           cmp    ecx,0x4
0x56a298  754c                             jne    0x56a2e6
0x56a29a  8b30                             mov    esi,DWORD PTR [eax]
0x56a29c  83c610                           add    esi,0x10
0x56a29f  8d7df8                           lea    edi,[ebp-0x8]
0x56a2a2  e8b9d41800                       call   0x6f7760
0x56a2a7  85c0                             test   eax,eax
0x56a2a9  743b                             je     0x56a2e6
0x56a2ab  dd45f8                           fld    QWORD PTR [ebp-0x8]
0x56a2ae  c745e403000000                   mov    DWORD PTR [ebp-0x1c],0x3
0x56a2b5  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0x56a2b8  8d45dc                           lea    eax,[ebp-0x24]
0x56a2bb  dd00                             fld    QWORD PTR [eax]
0x56a2bd  dd5de4                           fstp   QWORD PTR [ebp-0x1c]
0x56a2c0  dd45e4                           fld    QWORD PTR [ebp-0x1c]
0x56a2c3  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x56a2c6  8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
0x56a2c9  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x56a2cc  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0x56a2cf  52                               push   edx
0x56a2d0  50                               push   eax
0x56a2d1  ff550c                           call   DWORD PTR [ebp+0xc]
0x56a2d4  5f                               pop    edi
0x56a2d5  5e                               pop    esi
0x56a2d6  33c0                             xor    eax,eax
0x56a2d8  5b                               pop    ebx
0x56a2d9  8be5                             mov    esp,ebp
0x56a2db  5d                               pop    ebp
0x56a2dc  c3                               ret
0x56a2dd  c745f400000000                   mov    DWORD PTR [ebp-0xc],0x0
0x56a2e4  eb9b                             jmp    0x56a281
0x56a2e6  8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
0x56a2e9  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0x56a2ec  33c0                             xor    eax,eax
0x56a2ee  52                               push   edx
0x56a2ef  50                               push   eax
0x56a2f0  ff550c                           call   DWORD PTR [ebp+0xc]
0x56a2f3  5f                               pop    edi
0x56a2f4  5e                               pop    esi
0x56a2f5  33c0                             xor    eax,eax
0x56a2f7  5b                               pop    ebx
0x56a2f8  8be5                             mov    esp,ebp
0x56a2fa  5d                               pop    ebp
0x56a2fb  c3                               ret
0x56a2fc  cc                               int3
0x56a2fd  cc                               int3
0x56a2fe  cc                               int3
0x56a2ff  cc                               int3

; actor_ani | store +38C action and invoke CDoll motion selection
; VA 0x4c8da0..0x4c8de0 raw 0xc81a0 length 64 sha256 a1a20901dfb2581d602c890db27f932843312bf1aab855eeb15b5a075ed7694e
0x4c8da0  55                               push   ebp
0x4c8da1  8bec                             mov    ebp,esp
0x4c8da3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4c8da6  57                               push   edi
0x4c8da7  8bb95c010000                     mov    edi,DWORD PTR [ecx+0x15c]
0x4c8dad  89818c030000                     mov    DWORD PTR [ecx+0x38c],eax
0x4c8db3  85ff                             test   edi,edi
0x4c8db5  7416                             je     0x4c8dcd
0x4c8db7  83b97003000000                   cmp    DWORD PTR [ecx+0x370],0x0
0x4c8dbe  740d                             je     0x4c8dcd
0x4c8dc0  d9450c                           fld    DWORD PTR [ebp+0xc]
0x4c8dc3  51                               push   ecx
0x4c8dc4  d91c24                           fstp   DWORD PTR [esp]
0x4c8dc7  50                               push   eax
0x4c8dc8  e8a3db2d00                       call   0x7a6970
0x4c8dcd  5f                               pop    edi
0x4c8dce  5d                               pop    ebp
0x4c8dcf  c20800                           ret    0x8
0x4c8dd2  cc                               int3
0x4c8dd3  cc                               int3
0x4c8dd4  cc                               int3
0x4c8dd5  cc                               int3
0x4c8dd6  cc                               int3
0x4c8dd7  cc                               int3
0x4c8dd8  cc                               int3
0x4c8dd9  cc                               int3
0x4c8dda  cc                               int3
0x4c8ddb  cc                               int3
0x4c8ddc  cc                               int3
0x4c8ddd  cc                               int3
0x4c8dde  cc                               int3
0x4c8ddf  cc                               int3

; doll_ani | store motion+ A8/rate+104; select action, update animation parameters
; VA 0x7a6970..0x7a6c30 raw 0x3a5d70 length 704 sha256 18b5d3d389cc52dbb88c40b5252a2ce1296e22232a0230a7c89be24be79596a6
0x7a6970  55                               push   ebp
0x7a6971  8bec                             mov    ebp,esp
0x7a6973  83e4f8                           and    esp,0xfffffff8
0x7a6976  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x7a6979  d9450c                           fld    DWORD PTR [ebp+0xc]
0x7a697c  83ec10                           sub    esp,0x10
0x7a697f  d99f04010000                     fstp   DWORD PTR [edi+0x104]
0x7a6985  53                               push   ebx
0x7a6986  56                               push   esi
0x7a6987  8db708010000                     lea    esi,[edi+0x108]
0x7a698d  8987a8000000                     mov    DWORD PTR [edi+0xa8],eax
0x7a6993  8b06                             mov    eax,DWORD PTR [esi]
0x7a6995  c787b000000000000000             mov    DWORD PTR [edi+0xb0],0x0
0x7a699f  85c0                             test   eax,eax
0x7a69a1  746e                             je     0x7a6a11
0x7a69a3  83786c00                         cmp    DWORD PTR [eax+0x6c],0x0
0x7a69a7  7407                             je     0x7a69b0
0x7a69a9  e8427c0100                       call   0x7be5f0
0x7a69ae  eb61                             jmp    0x7a6a11
0x7a69b0  8b9f0c010000                     mov    ebx,DWORD PTR [edi+0x10c]
0x7a69b6  8b5304                           mov    edx,DWORD PTR [ebx+0x4]
0x7a69b9  8b8f20010000                     mov    ecx,DWORD PTR [edi+0x120]
0x7a69bf  52                               push   edx
0x7a69c0  53                               push   ebx
0x7a69c1  8d742418                         lea    esi,[esp+0x18]
0x7a69c5  89442418                         mov    DWORD PTR [esp+0x18],eax
0x7a69c9  894c241c                         mov    DWORD PTR [esp+0x1c],ecx
0x7a69cd  e8fee5c5ff                       call   0x404fd0
0x7a69d2  8b8f10010000                     mov    ecx,DWORD PTR [edi+0x110]
0x7a69d8  bafeffff1f                       mov    edx,0x1ffffffe
0x7a69dd  2bd1                             sub    edx,ecx
0x7a69df  83fa01                           cmp    edx,0x1
0x7a69e2  730a                             jae    0x7a69ee
0x7a69e4  683420bf00                       push   0xbf2034
0x7a69e9  e842710d00                       call   0x87db30
0x7a69ee  41                               inc    ecx
0x7a69ef  898f10010000                     mov    DWORD PTR [edi+0x110],ecx
0x7a69f5  894304                           mov    DWORD PTR [ebx+0x4],eax
0x7a69f8  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0x7a69fb  8901                             mov    DWORD PTR [ecx],eax
0x7a69fd  c7870801000000000000             mov    DWORD PTR [edi+0x108],0x0
0x7a6a07  c7872001000000000000             mov    DWORD PTR [edi+0x120],0x0
0x7a6a11  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x7a6a14  52                               push   edx
0x7a6a15  8bc7                             mov    eax,edi
0x7a6a17  e8e40d0000                       call   0x7a7800
0x7a6a1c  8987ac000000                     mov    DWORD PTR [edi+0xac],eax
0x7a6a22  85c0                             test   eax,eax
0x7a6a24  0f84cc010000                     je     0x7a6bf6
0x7a6a2a  8b10                             mov    edx,DWORD PTR [eax]
0x7a6a2c  8bc8                             mov    ecx,eax
0x7a6a2e  8b4240                           mov    eax,DWORD PTR [edx+0x40]
0x7a6a31  ffd0                             call   eax
0x7a6a33  8bb7a0000000                     mov    esi,DWORD PTR [edi+0xa0]
0x7a6a39  0fb65829                         movzx  ebx,BYTE PTR [eax+0x29]
0x7a6a3d  85f6                             test   esi,esi
0x7a6a3f  7448                             je     0x7a6a89
0x7a6a41  85db                             test   ebx,ebx
0x7a6a43  0f846d010000                     je     0x7a6bb6
0x7a6a49  8b06                             mov    eax,DWORD PTR [esi]
0x7a6a4b  8d4c2408                         lea    ecx,[esp+0x8]
0x7a6a4f  51                               push   ecx
0x7a6a50  8d4834                           lea    ecx,[eax+0x34]
0x7a6a53  8d442410                         lea    eax,[esp+0x10]
0x7a6a57  895c240c                         mov    DWORD PTR [esp+0xc],ebx
0x7a6a5b  e8a0840800                       call   0x82ef00
0x7a6a60  8b4c240c                         mov    ecx,DWORD PTR [esp+0xc]
0x7a6a64  8b06                             mov    eax,DWORD PTR [esi]
0x7a6a66  3b4838                           cmp    ecx,DWORD PTR [eax+0x38]
0x7a6a69  7415                             je     0x7a6a80
0x7a6a6b  8b4110                           mov    eax,DWORD PTR [ecx+0x10]
0x7a6a6e  85c0                             test   eax,eax
0x7a6a70  740e                             je     0x7a6a80
0x7a6a72  d94004                           fld    DWORD PTR [eax+0x4]
0x7a6a75  895e10                           mov    DWORD PTR [esi+0x10],ebx
0x7a6a78  d95e04                           fstp   DWORD PTR [esi+0x4]
0x7a6a7b  d9ee                             fldz
0x7a6a7d  d95e08                           fstp   DWORD PTR [esi+0x8]
0x7a6a80  8b97a0000000                     mov    edx,DWORD PTR [edi+0xa0]
0x7a6a86  895a14                           mov    DWORD PTR [edx+0x14],ebx
0x7a6a89  8bcf                             mov    ecx,edi
0x7a6a8b  e8f0020000                       call   0x7a6d80
0x7a6a90  8b8fac000000                     mov    ecx,DWORD PTR [edi+0xac]
0x7a6a96  8b01                             mov    eax,DWORD PTR [ecx]
0x7a6a98  8b500c                           mov    edx,DWORD PTR [eax+0xc]
0x7a6a9b  ffd2                             call   edx
0x7a6a9d  d95c240c                         fstp   DWORD PTR [esp+0xc]
0x7a6aa1  8b8fac000000                     mov    ecx,DWORD PTR [edi+0xac]
0x7a6aa7  8b01                             mov    eax,DWORD PTR [ecx]
0x7a6aa9  8b5018                           mov    edx,DWORD PTR [eax+0x18]
0x7a6aac  ffd2                             call   edx
0x7a6aae  d95c2408                         fstp   DWORD PTR [esp+0x8]
0x7a6ab2  8b8fac000000                     mov    ecx,DWORD PTR [edi+0xac]
0x7a6ab8  8b01                             mov    eax,DWORD PTR [ecx]
0x7a6aba  8b500c                           mov    edx,DWORD PTR [eax+0xc]
0x7a6abd  ffd2                             call   edx
0x7a6abf  d95c2410                         fstp   DWORD PTR [esp+0x10]
0x7a6ac3  8b8fac000000                     mov    ecx,DWORD PTR [edi+0xac]
0x7a6ac9  8b01                             mov    eax,DWORD PTR [ecx]
0x7a6acb  8b5038                           mov    edx,DWORD PTR [eax+0x38]
0x7a6ace  ffd2                             call   edx
0x7a6ad0  d944240c                         fld    DWORD PTR [esp+0xc]
0x7a6ad4  d997b8000000                     fst    DWORD PTR [edi+0xb8]
0x7a6ada  8bf0                             mov    esi,eax
0x7a6adc  d987c0000000                     fld    DWORD PTR [edi+0xc0]
0x7a6ae2  d8d9                             fcomp  st(1)
0x7a6ae4  dfe0                             fnstsw ax
0x7a6ae6  f6c441                           test   ah,0x41
0x7a6ae9  7510                             jne    0x7a6afb
0x7a6aeb  d997c0000000                     fst    DWORD PTR [edi+0xc0]
0x7a6af1  c787c400000000000000             mov    DWORD PTR [edi+0xc4],0x0
0x7a6afb  d987bc000000                     fld    DWORD PTR [edi+0xbc]
0x7a6b01  ded9                             fcompp
0x7a6b03  dfe0                             fnstsw ax
0x7a6b05  f6c441                           test   ah,0x41
0x7a6b08  7508                             jne    0x7a6b12
0x7a6b0a  d9ee                             fldz
0x7a6b0c  d99fbc000000                     fstp   DWORD PTR [edi+0xbc]
0x7a6b12  d9442408                         fld    DWORD PTR [esp+0x8]
0x7a6b16  d99fbc000000                     fstp   DWORD PTR [edi+0xbc]
0x7a6b1c  d9442410                         fld    DWORD PTR [esp+0x10]
0x7a6b20  d99fc0000000                     fstp   DWORD PTR [edi+0xc0]
0x7a6b26  d9ee                             fldz
0x7a6b28  dc0db856c500                     fmul   QWORD PTR ds:0xc556b8
0x7a6b2e  e8dd811500                       call   0x8fed10
0x7a6b33  8987c4000000                     mov    DWORD PTR [edi+0xc4],eax
0x7a6b39  89b7c8000000                     mov    DWORD PTR [edi+0xc8],esi
0x7a6b3f  8b5770                           mov    edx,DWORD PTR [edi+0x70]
0x7a6b42  8b0a                             mov    ecx,DWORD PTR [edx]
0x7a6b44  89542410                         mov    DWORD PTR [esp+0x10],edx
0x7a6b48  894c2408                         mov    DWORD PTR [esp+0x8],ecx
0x7a6b4c  3bca                             cmp    ecx,edx
0x7a6b4e  0f84a2000000                     je     0x7a6bf6
0x7a6b54  8b7118                           mov    esi,DWORD PTR [ecx+0x18]
0x7a6b57  8b461c                           mov    eax,DWORD PTR [esi+0x1c]
0x7a6b5a  2b4618                           sub    eax,DWORD PTR [esi+0x18]
0x7a6b5d  33db                             xor    ebx,ebx
0x7a6b5f  c1f802                           sar    eax,0x2
0x7a6b62  85c0                             test   eax,eax
0x7a6b64  7427                             je     0x7a6b8d
0x7a6b66  8b4e18                           mov    ecx,DWORD PTR [esi+0x18]
0x7a6b69  8b0c99                           mov    ecx,DWORD PTR [ecx+ebx*4]
0x7a6b6c  8b11                             mov    edx,DWORD PTR [ecx]
0x7a6b6e  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x7a6b71  8b5208                           mov    edx,DWORD PTR [edx+0x8]
0x7a6b74  50                               push   eax
0x7a6b75  ffd2                             call   edx
0x7a6b77  8b461c                           mov    eax,DWORD PTR [esi+0x1c]
0x7a6b7a  2b4618                           sub    eax,DWORD PTR [esi+0x18]
0x7a6b7d  43                               inc    ebx
0x7a6b7e  c1f802                           sar    eax,0x2
0x7a6b81  3bd8                             cmp    ebx,eax
0x7a6b83  72e1                             jb     0x7a6b66
0x7a6b85  8b542410                         mov    edx,DWORD PTR [esp+0x10]
0x7a6b89  8b4c2408                         mov    ecx,DWORD PTR [esp+0x8]
0x7a6b8d  80792100                         cmp    BYTE PTR [ecx+0x21],0x0
0x7a6b91  755b                             jne    0x7a6bee
0x7a6b93  8b4108                           mov    eax,DWORD PTR [ecx+0x8]
0x7a6b96  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a6b9a  7526                             jne    0x7a6bc2
0x7a6b9c  8bc8                             mov    ecx,eax
0x7a6b9e  8b01                             mov    eax,DWORD PTR [ecx]
0x7a6ba0  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a6ba4  750a                             jne    0x7a6bb0
0x7a6ba6  8bc8                             mov    ecx,eax
0x7a6ba8  8b01                             mov    eax,DWORD PTR [ecx]
0x7a6baa  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a6bae  74f6                             je     0x7a6ba6
0x7a6bb0  894c2408                         mov    DWORD PTR [esp+0x8],ecx
0x7a6bb4  eb34                             jmp    0x7a6bea
0x7a6bb6  c7461401000000                   mov    DWORD PTR [esi+0x14],0x1
0x7a6bbd  e9c7feffff                       jmp    0x7a6a89
0x7a6bc2  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x7a6bc5  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a6bc9  751b                             jne    0x7a6be6
0x7a6bcb  eb07                             jmp    0x7a6bd4
0x7a6bcd  8d4900                           lea    ecx,[ecx+0x0]
0x7a6bd0  8b4c2408                         mov    ecx,DWORD PTR [esp+0x8]
0x7a6bd4  3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
0x7a6bd7  750d                             jne    0x7a6be6
0x7a6bd9  89442408                         mov    DWORD PTR [esp+0x8],eax
0x7a6bdd  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x7a6be0  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a6be4  74ea                             je     0x7a6bd0
0x7a6be6  89442408                         mov    DWORD PTR [esp+0x8],eax
0x7a6bea  8b4c2408                         mov    ecx,DWORD PTR [esp+0x8]
0x7a6bee  3bca                             cmp    ecx,edx
0x7a6bf0  0f855effffff                     jne    0x7a6b54
0x7a6bf6  8b8f20010000                     mov    ecx,DWORD PTR [edi+0x120]
0x7a6bfc  85c9                             test   ecx,ecx
0x7a6bfe  7411                             je     0x7a6c11
0x7a6c00  8b11                             mov    edx,DWORD PTR [ecx]
0x7a6c02  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x7a6c05  ffd0                             call   eax
0x7a6c07  c7872001000000000000             mov    DWORD PTR [edi+0x120],0x0
0x7a6c11  8bf7                             mov    esi,edi
0x7a6c13  e848000000                       call   0x7a6c60
0x7a6c18  e813fbffff                       call   0x7a6730
0x7a6c1d  5e                               pop    esi
0x7a6c1e  5b                               pop    ebx
0x7a6c1f  8be5                             mov    esp,ebp
0x7a6c21  5d                               pop    ebp
0x7a6c22  c20800                           ret    0x8
0x7a6c25  cc                               int3
0x7a6c26  cc                               int3
0x7a6c27  cc                               int3
0x7a6c28  cc                               int3
0x7a6c29  cc                               int3
0x7a6c2a  cc                               int3
0x7a6c2b  cc                               int3
0x7a6c2c  cc                               int3
0x7a6c2d  cc                               int3
0x7a6c2e  cc                               int3
0x7a6c2f  cc                               int3

; doll_ani_seek | clamp +B4 and apply current motion to model
; VA 0x7a6830..0x7a6970 raw 0x3a5c30 length 320 sha256 807dd850e779aec2302b73ed767952bf254156c7b5b44594b44e3dc3a3034002
0x7a6830  55                               push   ebp
0x7a6831  8bec                             mov    ebp,esp
0x7a6833  6aff                             push   0xffffffff
0x7a6835  6855a19000                       push   0x90a155
0x7a683a  64a100000000                     mov    eax,fs:0x0
0x7a6840  50                               push   eax
0x7a6841  51                               push   ecx
0x7a6842  a1201fd600                       mov    eax,ds:0xd61f20
0x7a6847  33c5                             xor    eax,ebp
0x7a6849  50                               push   eax
0x7a684a  8d45f4                           lea    eax,[ebp-0xc]
0x7a684d  64a300000000                     mov    fs:0x0,eax
0x7a6853  b80cf6c400                       mov    eax,0xc4f60c
0x7a6858  e853180900                       call   0x8380b0
0x7a685d  d94508                           fld    DWORD PTR [ebp+0x8]
0x7a6860  d955f0                           fst    DWORD PTR [ebp-0x10]
0x7a6863  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x7a686a  d9ee                             fldz
0x7a686c  d8d1                             fcom   st(1)
0x7a686e  dfe0                             fnstsw ax
0x7a6870  f6c441                           test   ah,0x41
0x7a6873  7417                             je     0x7a688c
0x7a6875  ddd8                             fstp   st(0)
0x7a6877  d986b8000000                     fld    DWORD PTR [esi+0xb8]
0x7a687d  d8d9                             fcomp  st(1)
0x7a687f  dfe0                             fnstsw ax
0x7a6881  f6c405                           test   ah,0x5
0x7a6884  7a09                             jp     0x7a688f
0x7a6886  d986b8000000                     fld    DWORD PTR [esi+0xb8]
0x7a688c  d95df0                           fstp   DWORD PTR [ebp-0x10]
0x7a688f  d945f0                           fld    DWORD PTR [ebp-0x10]
0x7a6892  d99eb4000000                     fstp   DWORD PTR [esi+0xb4]
0x7a6898  8b461c                           mov    eax,DWORD PTR [esi+0x1c]
0x7a689b  85c0                             test   eax,eax
0x7a689d  0f849d000000                     je     0x7a6940
0x7a68a3  83beac00000000                   cmp    DWORD PTR [esi+0xac],0x0
0x7a68aa  741d                             je     0x7a68c9
0x7a68ac  8b8eac000000                     mov    ecx,DWORD PTR [esi+0xac]
0x7a68b2  ddd8                             fstp   st(0)
0x7a68b4  d986b4000000                     fld    DWORD PTR [esi+0xb4]
0x7a68ba  8b11                             mov    edx,DWORD PTR [ecx]
0x7a68bc  51                               push   ecx
0x7a68bd  d91c24                           fstp   DWORD PTR [esp]
0x7a68c0  50                               push   eax
0x7a68c1  8b4220                           mov    eax,DWORD PTR [edx+0x20]
0x7a68c4  ffd0                             call   eax
0x7a68c6  d94508                           fld    DWORD PTR [ebp+0x8]
0x7a68c9  83be0801000000                   cmp    DWORD PTR [esi+0x108],0x0
0x7a68d0  7461                             je     0x7a6933
0x7a68d2  83beac00000000                   cmp    DWORD PTR [esi+0xac],0x0
0x7a68d9  7432                             je     0x7a690d
0x7a68db  8b8eac000000                     mov    ecx,DWORD PTR [esi+0xac]
0x7a68e1  ddd8                             fstp   st(0)
0x7a68e3  8b11                             mov    edx,DWORD PTR [ecx]
0x7a68e5  8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x7a68e8  ffd0                             call   eax
0x7a68ea  83f801                           cmp    eax,0x1
0x7a68ed  751b                             jne    0x7a690a
0x7a68ef  8b8608010000                     mov    eax,DWORD PTR [esi+0x108]
0x7a68f5  d9ee                             fldz
0x7a68f7  d9581c                           fstp   DWORD PTR [eax+0x1c]
0x7a68fa  e8b17c0100                       call   0x7be5b0
0x7a68ff  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
0x7a6902  51                               push   ecx
0x7a6903  e8c8d20200                       call   0x7d3bd0
0x7a6908  eb38                             jmp    0x7a6942
0x7a690a  d94508                           fld    DWORD PTR [ebp+0x8]
0x7a690d  8b8e08010000                     mov    ecx,DWORD PTR [esi+0x108]
0x7a6913  d9511c                           fst    DWORD PTR [ecx+0x1c]
0x7a6916  d9ee                             fldz
0x7a6918  dae9                             fucompp
0x7a691a  dfe0                             fnstsw ax
0x7a691c  f6c444                           test   ah,0x44
0x7a691f  7a14                             jp     0x7a6935
0x7a6921  8bc1                             mov    eax,ecx
0x7a6923  e8887c0100                       call   0x7be5b0
0x7a6928  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
0x7a692b  51                               push   ecx
0x7a692c  e89fd20200                       call   0x7d3bd0
0x7a6931  eb0f                             jmp    0x7a6942
0x7a6933  ddd8                             fstp   st(0)
0x7a6935  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
0x7a6938  51                               push   ecx
0x7a6939  e892d20200                       call   0x7d3bd0
0x7a693e  eb02                             jmp    0x7a6942
0x7a6940  ddd8                             fstp   st(0)
0x7a6942  e889160900                       call   0x837fd0
0x7a6947  8b15fc39d600                     mov    edx,DWORD PTR ds:0xd639fc
0x7a694d  8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x7a6950  a3fc39d600                       mov    ds:0xd639fc,eax
0x7a6955  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7a6958  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a695f  59                               pop    ecx
0x7a6960  8be5                             mov    esp,ebp
0x7a6962  5d                               pop    ebp
0x7a6963  c20400                           ret    0x4
0x7a6966  cc                               int3
0x7a6967  cc                               int3
0x7a6968  cc                               int3
0x7a6969  cc                               int3
0x7a696a  cc                               int3
0x7a696b  cc                               int3
0x7a696c  cc                               int3
0x7a696d  cc                               int3
0x7a696e  cc                               int3
0x7a696f  cc                               int3

; actor_direction | store low BYTE at actor+B0
; VA 0x4c8c30..0x4c8c40 raw 0xc8030 length 16 sha256 ea2c5e4b2c272bbf69b25395af84f2e0beee255e89eb773523a1eebfdee6d911
0x4c8c30  55                               push   ebp
0x4c8c31  8bec                             mov    ebp,esp
0x4c8c33  8a4508                           mov    al,BYTE PTR [ebp+0x8]
0x4c8c36  8881b0000000                     mov    BYTE PTR [ecx+0xb0],al
0x4c8c3c  5d                               pop    ebp
0x4c8c3d  c20400                           ret    0x4

; actor_direction_tick | advance rendered direction +3A4 toward desired byte; yaw setter
; VA 0x4c89a0..0x4c8a90 raw 0xc7da0 length 240 sha256 e8dcad26c76418f660032546df7433d2f1acf3a2399e0194545b686418dd1f4b
0x4c89a0  55                               push   ebp
0x4c89a1  8bec                             mov    ebp,esp
0x4c89a3  51                               push   ecx
0x4c89a4  83b9a803000000                   cmp    DWORD PTR [ecx+0x3a8],0x0
0x4c89ab  0f85d2000000                     jne    0x4c8a83
0x4c89b1  53                               push   ebx
0x4c89b2  8a99a4030000                     mov    bl,BYTE PTR [ecx+0x3a4]
0x4c89b8  56                               push   esi
0x4c89b9  0fb6b1b0000000                   movzx  esi,BYTE PTR [ecx+0xb0]
0x4c89c0  0fb6d3                           movzx  edx,bl
0x4c89c3  8bc6                             mov    eax,esi
0x4c89c5  2bc2                             sub    eax,edx
0x4c89c7  57                               push   edi
0x4c89c8  8bf8                             mov    edi,eax
0x4c89ca  0f84b0000000                     je     0x4c8a80
0x4c89d0  2bd6                             sub    edx,esi
0x4c89d2  85ff                             test   edi,edi
0x4c89d4  7906                             jns    0x4c89dc
0x4c89d6  8db800010000                     lea    edi,[eax+0x100]
0x4c89dc  85d2                             test   edx,edx
0x4c89de  7906                             jns    0x4c89e6
0x4c89e0  81c200010000                     add    edx,0x100
0x4c89e6  3bfa                             cmp    edi,edx
0x4c89e8  99                               cdq
0x4c89e9  7e21                             jle    0x4c8a0c
0x4c89eb  33c2                             xor    eax,edx
0x4c89ed  2bc2                             sub    eax,edx
0x4c89ef  c781ac030000ffffffff             mov    DWORD PTR [ecx+0x3ac],0xffffffff
0x4c89f9  83f810                           cmp    eax,0x10
0x4c89fc  7e05                             jle    0x4c8a03
0x4c89fe  b810000000                       mov    eax,0x10
0x4c8a03  99                               cdq
0x4c8a04  33c2                             xor    eax,edx
0x4c8a06  2bc2                             sub    eax,edx
0x4c8a08  f7d8                             neg    eax
0x4c8a0a  eb3b                             jmp    0x4c8a47
0x4c8a0c  7d1f                             jge    0x4c8a2d
0x4c8a0e  33c2                             xor    eax,edx
0x4c8a10  2bc2                             sub    eax,edx
0x4c8a12  c781ac03000001000000             mov    DWORD PTR [ecx+0x3ac],0x1
0x4c8a1c  83f810                           cmp    eax,0x10
0x4c8a1f  7e05                             jle    0x4c8a26
0x4c8a21  b810000000                       mov    eax,0x10
0x4c8a26  99                               cdq
0x4c8a27  33c2                             xor    eax,edx
0x4c8a29  2bc2                             sub    eax,edx
0x4c8a2b  eb1a                             jmp    0x4c8a47
0x4c8a2d  33c2                             xor    eax,edx
0x4c8a2f  2bc2                             sub    eax,edx
0x4c8a31  83f830                           cmp    eax,0x30
0x4c8a34  7e05                             jle    0x4c8a3b
0x4c8a36  b830000000                       mov    eax,0x30
0x4c8a3b  99                               cdq
0x4c8a3c  33c2                             xor    eax,edx
0x4c8a3e  2bc2                             sub    eax,edx
0x4c8a40  0faf81ac030000                   imul   eax,DWORD PTR [ecx+0x3ac]
0x4c8a47  02c3                             add    al,bl
0x4c8a49  83b97003000000                   cmp    DWORD PTR [ecx+0x370],0x0
0x4c8a50  8845fc                           mov    BYTE PTR [ebp-0x4],al
0x4c8a53  8881a4030000                     mov    BYTE PTR [ecx+0x3a4],al
0x4c8a59  7425                             je     0x4c8a80
0x4c8a5b  8b895c010000                     mov    ecx,DWORD PTR [ecx+0x15c]
0x4c8a61  85c9                             test   ecx,ecx
0x4c8a63  741b                             je     0x4c8a80
0x4c8a65  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4c8a68  8b7104                           mov    esi,DWORD PTR [ecx+0x4]
0x4c8a6b  8d7904                           lea    edi,[ecx+0x4]
0x4c8a6e  50                               push   eax
0x4c8a6f  e81cc0f7ff                       call   0x444a90
0x4c8a74  8b560c                           mov    edx,DWORD PTR [esi+0xc]
0x4c8a77  8bcf                             mov    ecx,edi
0x4c8a79  f30f110424                       movss  DWORD PTR [esp],xmm0
0x4c8a7e  ffd2                             call   edx
0x4c8a80  5f                               pop    edi
0x4c8a81  5e                               pop    esi
0x4c8a82  5b                               pop    ebx
0x4c8a83  8be5                             mov    esp,ebp
0x4c8a85  5d                               pop    ebp
0x4c8a86  c3                               ret
0x4c8a87  cc                               int3
0x4c8a88  cc                               int3
0x4c8a89  cc                               int3
0x4c8a8a  cc                               int3
0x4c8a8b  cc                               int3
0x4c8a8c  cc                               int3
0x4c8a8d  cc                               int3
0x4c8a8e  cc                               int3
0x4c8a8f  cc                               int3

; actor_scale | store +B4 and forward scaled value to IObject+14
; VA 0x4c8c40..0x4c8d00 raw 0xc8040 length 192 sha256 10befe6008e173234abd4df88dd31f56d5b721b18e63bc5e2ce7e6ceb4177cdf
0x4c8c40  55                               push   ebp
0x4c8c41  8bec                             mov    ebp,esp
0x4c8c43  6aff                             push   0xffffffff
0x4c8c45  68ded89000                       push   0x90d8de
0x4c8c4a  64a100000000                     mov    eax,fs:0x0
0x4c8c50  50                               push   eax
0x4c8c51  51                               push   ecx
0x4c8c52  56                               push   esi
0x4c8c53  a1201fd600                       mov    eax,ds:0xd61f20
0x4c8c58  33c5                             xor    eax,ebp
0x4c8c5a  50                               push   eax
0x4c8c5b  8d45f4                           lea    eax,[ebp-0xc]
0x4c8c5e  64a300000000                     mov    fs:0x0,eax
0x4c8c64  8bf1                             mov    esi,ecx
0x4c8c66  b801000000                       mov    eax,0x1
0x4c8c6b  84052888fb00                     test   BYTE PTR ds:0xfb8828,al
0x4c8c71  7526                             jne    0x4c8c99
0x4c8c73  09052888fb00                     or     DWORD PTR ds:0xfb8828,eax
0x4c8c79  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4c8c80  e8cb6b0800                       call   0x54f850
0x4c8c85  6880d5bc00                       push   0xbcd580
0x4c8c8a  e88b963c00                       call   0x89231a
0x4c8c8f  83c404                           add    esp,0x4
0x4c8c92  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c8c99  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
0x4c8ca0  f30f1005bc90fb00                 movss  xmm0,DWORD PTR ds:0xfb90bc
0x4c8ca8  f30f1145f0                       movss  DWORD PTR [ebp-0x10],xmm0
0x4c8cad  f30f104508                       movss  xmm0,DWORD PTR [ebp+0x8]
0x4c8cb2  f30f1186b4000000                 movss  DWORD PTR [esi+0xb4],xmm0
0x4c8cba  7425                             je     0x4c8ce1
0x4c8cbc  8bb65c010000                     mov    esi,DWORD PTR [esi+0x15c]
0x4c8cc2  85f6                             test   esi,esi
0x4c8cc4  741b                             je     0x4c8ce1
0x4c8cc6  d945f0                           fld    DWORD PTR [ebp-0x10]
0x4c8cc9  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x4c8ccc  d84d08                           fmul   DWORD PTR [ebp+0x8]
0x4c8ccf  8b5014                           mov    edx,DWORD PTR [eax+0x14]
0x4c8cd2  8d4e04                           lea    ecx,[esi+0x4]
0x4c8cd5  51                               push   ecx
0x4c8cd6  d95d08                           fstp   DWORD PTR [ebp+0x8]
0x4c8cd9  d94508                           fld    DWORD PTR [ebp+0x8]
0x4c8cdc  d91c24                           fstp   DWORD PTR [esp]
0x4c8cdf  ffd2                             call   edx
0x4c8ce1  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4c8ce4  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4c8ceb  59                               pop    ecx
0x4c8cec  5e                               pop    esi
0x4c8ced  8be5                             mov    esp,ebp
0x4c8cef  5d                               pop    ebp
0x4c8cf0  c20400                           ret    0x4
0x4c8cf3  cc                               int3
0x4c8cf4  cc                               int3
0x4c8cf5  cc                               int3
0x4c8cf6  cc                               int3
0x4c8cf7  cc                               int3
0x4c8cf8  cc                               int3
0x4c8cf9  cc                               int3
0x4c8cfa  cc                               int3
0x4c8cfb  cc                               int3
0x4c8cfc  cc                               int3
0x4c8cfd  cc                               int3
0x4c8cfe  cc                               int3
0x4c8cff  cc                               int3

; actor_face | require CDoll face controller at R+A0
; VA 0x4c9550..0x4c9580 raw 0xc8950 length 48 sha256 b8b59b38f205710037d38b45ec05e8da1c240f2acb2feff9e169baa1c5056a69
0x4c9550  55                               push   ebp
0x4c9551  8bec                             mov    ebp,esp
0x4c9553  8b815c010000                     mov    eax,DWORD PTR [ecx+0x15c]
0x4c9559  85c0                             test   eax,eax
0x4c955b  741f                             je     0x4c957c
0x4c955d  8b80a0000000                     mov    eax,DWORD PTR [eax+0xa0]
0x4c9563  85c0                             test   eax,eax
0x4c9565  7415                             je     0x4c957c
0x4c9567  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4c956a  85c9                             test   ecx,ecx
0x4c956c  740e                             je     0x4c957c
0x4c956e  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x4c9571  57                               push   edi
0x4c9572  52                               push   edx
0x4c9573  51                               push   ecx
0x4c9574  8bf8                             mov    edi,eax
0x4c9576  e8b5d13000                       call   0x7d6730
0x4c957b  5f                               pop    edi
0x4c957c  5d                               pop    ebp
0x4c957d  c20800                           ret    0x8

; face_select | face resource key, duration override/default and counter reset
; VA 0x7d6730..0x7d6790 raw 0x3d5b30 length 96 sha256 0fee6dde0070a04a670c6518237c39747e69776d312cd05a7b4cbffe431614e5
0x7d6730  55                               push   ebp
0x7d6731  8bec                             mov    ebp,esp
0x7d6733  51                               push   ecx
0x7d6734  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x7d6737  53                               push   ebx
0x7d6738  8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
0x7d673b  56                               push   esi
0x7d673c  8b37                             mov    esi,DWORD PTR [edi]
0x7d673e  8d4d0c                           lea    ecx,[ebp+0xc]
0x7d6741  89450c                           mov    DWORD PTR [ebp+0xc],eax
0x7d6744  51                               push   ecx
0x7d6745  8d4e34                           lea    ecx,[esi+0x34]
0x7d6748  8d45fc                           lea    eax,[ebp-0x4]
0x7d674b  e8b0870500                       call   0x82ef00
0x7d6750  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x7d6753  3b4638                           cmp    eax,DWORD PTR [esi+0x38]
0x7d6756  7407                             je     0x7d675f
0x7d6758  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x7d675b  85c0                             test   eax,eax
0x7d675d  750a                             jne    0x7d6769
0x7d675f  5e                               pop    esi
0x7d6760  33c0                             xor    eax,eax
0x7d6762  5b                               pop    ebx
0x7d6763  8be5                             mov    esp,ebp
0x7d6765  5d                               pop    ebp
0x7d6766  c20800                           ret    0x8
0x7d6769  85db                             test   ebx,ebx
0x7d676b  7404                             je     0x7d6771
0x7d676d  d903                             fld    DWORD PTR [ebx]
0x7d676f  eb03                             jmp    0x7d6774
0x7d6771  d94004                           fld    DWORD PTR [eax+0x4]
0x7d6774  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x7d6777  d95f04                           fstp   DWORD PTR [edi+0x4]
0x7d677a  d9ee                             fldz
0x7d677c  5e                               pop    esi
0x7d677d  d95f08                           fstp   DWORD PTR [edi+0x8]
0x7d6780  895710                           mov    DWORD PTR [edi+0x10],edx
0x7d6783  b801000000                       mov    eax,0x1
0x7d6788  5b                               pop    ebx
0x7d6789  8be5                             mov    esp,ebp
0x7d678b  5d                               pop    ebp
0x7d678c  c20800                           ret    0x8
0x7d678f  cc                               int3

; face_tick | advance face animation by dt*30; resource frame state and skin values
; VA 0x7d65a0..0x7d6730 raw 0x3d59a0 length 400 sha256 696770c42b086c956c0a3dfd9906958f3c2c46172f6999709fcea5b24ec706bd
0x7d65a0  55                               push   ebp
0x7d65a1  8bec                             mov    ebp,esp
0x7d65a3  83ec0c                           sub    esp,0xc
0x7d65a6  d94508                           fld    DWORD PTR [ebp+0x8]
0x7d65a9  8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x7d65ac  dc0dc857c500                     fmul   QWORD PTR ds:0xc557c8
0x7d65b2  57                               push   edi
0x7d65b3  8b3e                             mov    edi,DWORD PTR [esi]
0x7d65b5  8d4dfc                           lea    ecx,[ebp-0x4]
0x7d65b8  d84608                           fadd   DWORD PTR [esi+0x8]
0x7d65bb  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x7d65be  51                               push   ecx
0x7d65bf  8d4f34                           lea    ecx,[edi+0x34]
0x7d65c2  d95d08                           fstp   DWORD PTR [ebp+0x8]
0x7d65c5  8d45f8                           lea    eax,[ebp-0x8]
0x7d65c8  d94508                           fld    DWORD PTR [ebp+0x8]
0x7d65cb  d95e08                           fstp   DWORD PTR [esi+0x8]
0x7d65ce  e82d890500                       call   0x82ef00
0x7d65d3  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0x7d65d6  3b4738                           cmp    eax,DWORD PTR [edi+0x38]
0x7d65d9  0f844a010000                     je     0x7d6729
0x7d65df  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x7d65e2  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x7d65e5  85c0                             test   eax,eax
0x7d65e7  0f843c010000                     je     0x7d6729
0x7d65ed  d94508                           fld    DWORD PTR [ebp+0x8]
0x7d65f0  53                               push   ebx
0x7d65f1  8b5810                           mov    ebx,DWORD PTR [eax+0x10]
0x7d65f4  dc0dc856c500                     fmul   QWORD PTR ds:0xc556c8
0x7d65fa  8b400c                           mov    eax,DWORD PTR [eax+0xc]
0x7d65fd  8b00                             mov    eax,DWORD PTR [eax]
0x7d65ff  894508                           mov    DWORD PTR [ebp+0x8],eax
0x7d6602  e809871200                       call   0x8fed10
0x7d6607  8b7dfc                           mov    edi,DWORD PTR [ebp-0x4]
0x7d660a  8b4f0c                           mov    ecx,DWORD PTR [edi+0xc]
0x7d660d  50                               push   eax
0x7d660e  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x7d6611  8b501c                           mov    edx,DWORD PTR [eax+0x1c]
0x7d6614  ffd2                             call   edx
0x7d6616  8b470c                           mov    eax,DWORD PTR [edi+0xc]
0x7d6619  8b4830                           mov    ecx,DWORD PTR [eax+0x30]
0x7d661c  51                               push   ecx
0x7d661d  50                               push   eax
0x7d661e  e82d9bfaff                       call   0x780150
0x7d6623  8b560c                           mov    edx,DWORD PTR [esi+0xc]
0x7d6626  8b8378010000                     mov    eax,DWORD PTR [ebx+0x178]
0x7d662c  8b4a74                           mov    ecx,DWORD PTR [edx+0x74]
0x7d662f  8b9178010000                     mov    edx,DWORD PTR [ecx+0x178]
0x7d6635  33ff                             xor    edi,edi
0x7d6637  8945f4                           mov    DWORD PTR [ebp-0xc],eax
0x7d663a  895508                           mov    DWORD PTR [ebp+0x8],edx
0x7d663d  85c0                             test   eax,eax
0x7d663f  7e2f                             jle    0x7d6670
0x7d6641  3b7d08                           cmp    edi,DWORD PTR [ebp+0x8]
0x7d6644  7d2a                             jge    0x7d6670
0x7d6646  8bc3                             mov    eax,ebx
0x7d6648  e8a3d80600                       call   0x843ef0
0x7d664d  8b80b8000000                     mov    eax,DWORD PTR [eax+0xb8]
0x7d6653  8b4e0c                           mov    ecx,DWORD PTR [esi+0xc]
0x7d6656  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x7d6659  8b4174                           mov    eax,DWORD PTR [ecx+0x74]
0x7d665c  e88fd80600                       call   0x843ef0
0x7d6661  8b55f8                           mov    edx,DWORD PTR [ebp-0x8]
0x7d6664  47                               inc    edi
0x7d6665  8990b8000000                     mov    DWORD PTR [eax+0xb8],edx
0x7d666b  3b7df4                           cmp    edi,DWORD PTR [ebp-0xc]
0x7d666e  7cd1                             jl     0x7d6641
0x7d6670  d94608                           fld    DWORD PTR [esi+0x8]
0x7d6673  d94604                           fld    DWORD PTR [esi+0x4]
0x7d6676  ded9                             fcompp
0x7d6678  dfe0                             fnstsw ax
0x7d667a  f6c405                           test   ah,0x5
0x7d667d  0f8aa5000000                     jp     0x7d6728
0x7d6683  8b5e14                           mov    ebx,DWORD PTR [esi+0x14]
0x7d6686  395e10                           cmp    DWORD PTR [esi+0x10],ebx
0x7d6689  0f8499000000                     je     0x7d6728
0x7d668f  d94604                           fld    DWORD PTR [esi+0x4]
0x7d6692  d9ee                             fldz
0x7d6694  d9c0                             fld    st(0)
0x7d6696  ddea                             fucomp st(2)
0x7d6698  dfe0                             fnstsw ax
0x7d669a  ddd9                             fstp   st(1)
0x7d669c  f6c444                           test   ah,0x44
0x7d669f  0f8b81000000                     jnp    0x7d6726
0x7d66a5  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x7d66a8  d95e08                           fstp   DWORD PTR [esi+0x8]
0x7d66ab  83780800                         cmp    DWORD PTR [eax+0x8],0x0
0x7d66af  8b3e                             mov    edi,DWORD PTR [esi]
0x7d66b1  8d45f4                           lea    eax,[ebp-0xc]
0x7d66b4  7434                             je     0x7d66ea
0x7d66b6  8d4d08                           lea    ecx,[ebp+0x8]
0x7d66b9  51                               push   ecx
0x7d66ba  8d4f34                           lea    ecx,[edi+0x34]
0x7d66bd  895d08                           mov    DWORD PTR [ebp+0x8],ebx
0x7d66c0  e83b880500                       call   0x82ef00
0x7d66c5  8b45f4                           mov    eax,DWORD PTR [ebp-0xc]
0x7d66c8  3b4738                           cmp    eax,DWORD PTR [edi+0x38]
0x7d66cb  745b                             je     0x7d6728
0x7d66cd  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x7d66d0  85c0                             test   eax,eax
0x7d66d2  7454                             je     0x7d6728
0x7d66d4  d94004                           fld    DWORD PTR [eax+0x4]
0x7d66d7  895e10                           mov    DWORD PTR [esi+0x10],ebx
0x7d66da  d95e04                           fstp   DWORD PTR [esi+0x4]
0x7d66dd  5b                               pop    ebx
0x7d66de  d9ee                             fldz
0x7d66e0  5f                               pop    edi
0x7d66e1  d95e08                           fstp   DWORD PTR [esi+0x8]
0x7d66e4  8be5                             mov    esp,ebp
0x7d66e6  5d                               pop    ebp
0x7d66e7  c20400                           ret    0x4
0x7d66ea  8d5508                           lea    edx,[ebp+0x8]
0x7d66ed  bb01000000                       mov    ebx,0x1
0x7d66f2  52                               push   edx
0x7d66f3  8d4f34                           lea    ecx,[edi+0x34]
0x7d66f6  895e14                           mov    DWORD PTR [esi+0x14],ebx
0x7d66f9  895d08                           mov    DWORD PTR [ebp+0x8],ebx
0x7d66fc  e8ff870500                       call   0x82ef00
0x7d6701  8b45f4                           mov    eax,DWORD PTR [ebp-0xc]
0x7d6704  3b4738                           cmp    eax,DWORD PTR [edi+0x38]
0x7d6707  741f                             je     0x7d6728
0x7d6709  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x7d670c  85c0                             test   eax,eax
0x7d670e  7418                             je     0x7d6728
0x7d6710  d94004                           fld    DWORD PTR [eax+0x4]
0x7d6713  895e10                           mov    DWORD PTR [esi+0x10],ebx
0x7d6716  d95e04                           fstp   DWORD PTR [esi+0x4]
0x7d6719  5b                               pop    ebx
0x7d671a  d9ee                             fldz
0x7d671c  5f                               pop    edi
0x7d671d  d95e08                           fstp   DWORD PTR [esi+0x8]
0x7d6720  8be5                             mov    esp,ebp
0x7d6722  5d                               pop    ebp
0x7d6723  c20400                           ret    0x4
0x7d6726  ddd8                             fstp   st(0)
0x7d6728  5b                               pop    ebx
0x7d6729  5f                               pop    edi
0x7d672a  8be5                             mov    esp,ebp
0x7d672c  5d                               pop    ebp
0x7d672d  c20400                           ret    0x4

; event_actor_speed | movement speed consumes CEventActor+434
; VA 0x4d0f50..0x4d0f80 raw 0xd0350 length 48 sha256 bfd19a690a807041dd072ec98d36453fee7f298f8f95f6214de25db9c5db0e17
0x4d0f50  55                               push   ebp
0x4d0f51  8bec                             mov    ebp,esp
0x4d0f53  51                               push   ecx
0x4d0f54  db81d0000000                     fild   DWORD PTR [ecx+0xd0]
0x4d0f5a  dc0df857c500                     fmul   QWORD PTR ds:0xc557f8
0x4d0f60  d889cc000000                     fmul   DWORD PTR [ecx+0xcc]
0x4d0f66  d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x4d0f69  d945fc                           fld    DWORD PTR [ebp-0x4]
0x4d0f6c  d88934040000                     fmul   DWORD PTR [ecx+0x434]
0x4d0f72  d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x4d0f75  d945fc                           fld    DWORD PTR [ebp-0x4]
0x4d0f78  8be5                             mov    esp,ebp
0x4d0f7a  5d                               pop    ebp
0x4d0f7b  c3                               ret
0x4d0f7c  cc                               int3
0x4d0f7d  cc                               int3
0x4d0f7e  cc                               int3
0x4d0f7f  cc                               int3

; tutorial_status | normal public API to checkpoint manager
; VA 0x4a9460..0x4a94c0 raw 0xa8860 length 96 sha256 9bdc20e4d57abee81f8bfb9e5b55d9661473d387b8a51bc57569442bebe36d00
0x4a9460  55                               push   ebp
0x4a9461  8bec                             mov    ebp,esp
0x4a9463  51                               push   ecx
0x4a9464  b901000000                       mov    ecx,0x1
0x4a9469  840dec79fb00                     test   BYTE PTR ds:0xfb79ec,cl
0x4a946f  7534                             jne    0x4a94a5
0x4a9471  090dec79fb00                     or     DWORD PTR ds:0xfb79ec,ecx
0x4a9477  33c0                             xor    eax,eax
0x4a9479  6870d2bc00                       push   0xbcd270
0x4a947e  c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x4a9488  a3f479fb00                       mov    ds:0xfb79f4,eax
0x4a948d  a3f879fb00                       mov    ds:0xfb79f8,eax
0x4a9492  a3fc79fb00                       mov    ds:0xfb79fc,eax
0x4a9497  890d047afb00                     mov    DWORD PTR ds:0xfb7a04,ecx
0x4a949d  e8788e3e00                       call   0x89231a
0x4a94a2  83c404                           add    esp,0x4
0x4a94a5  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x4a94a8  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x4a94ab  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x4a94ae  50                               push   eax
0x4a94af  51                               push   ecx
0x4a94b0  52                               push   edx
0x4a94b1  baf079fb00                       mov    edx,0xfb79f0
0x4a94b6  e885b40900                       call   0x544940
0x4a94bb  59                               pop    ecx
0x4a94bc  5d                               pop    ebp
0x4a94bd  c20c00                           ret    0xc

; checkpoint_status_lookup | WORD key and signed BYTE category match existing point
; VA 0x544940..0x5449a0 raw 0x143d40 length 96 sha256 6966d1baf8702cf64ad48e8d678062a598aed754c00fac42f746f77fb9891c03
0x544940  55                               push   ebp
0x544941  8bec                             mov    ebp,esp
0x544943  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x544946  2b4204                           sub    eax,DWORD PTR [edx+0x4]
0x544949  53                               push   ebx
0x54494a  c1f802                           sar    eax,0x2
0x54494d  56                               push   esi
0x54494e  33c9                             xor    ecx,ecx
0x544950  57                               push   edi
0x544951  85c0                             test   eax,eax
0x544953  7443                             je     0x544998
0x544955  8b5204                           mov    edx,DWORD PTR [edx+0x4]
0x544958  8bf2                             mov    esi,edx
0x54495a  8d9b00000000                     lea    ebx,[ebx+0x0]
0x544960  8b3e                             mov    edi,DWORD PTR [esi]
0x544962  668b9ff6000000                   mov    bx,WORD PTR [edi+0xf6]
0x544969  663b5d08                         cmp    bx,WORD PTR [ebp+0x8]
0x54496d  750e                             jne    0x54497d
0x54496f  660fbe5d0c                       movsx  bx,BYTE PTR [ebp+0xc]
0x544974  66399ff4000000                   cmp    WORD PTR [edi+0xf4],bx
0x54497b  740f                             je     0x54498c
0x54497d  41                               inc    ecx
0x54497e  83c604                           add    esi,0x4
0x544981  3bc8                             cmp    ecx,eax
0x544983  72db                             jb     0x544960
0x544985  5f                               pop    edi
0x544986  5e                               pop    esi
0x544987  5b                               pop    ebx
0x544988  5d                               pop    ebp
0x544989  c20c00                           ret    0xc
0x54498c  8b048a                           mov    eax,DWORD PTR [edx+ecx*4]
0x54498f  8a4d10                           mov    cl,BYTE PTR [ebp+0x10]
0x544992  50                               push   eax
0x544993  e898f1ffff                       call   0x543b30
0x544998  5f                               pop    edi
0x544999  5e                               pop    esi
0x54499a  5b                               pop    ebx
0x54499b  5d                               pop    ebp
0x54499c  c20c00                           ret    0xc
0x54499f  cc                               int3

; checkpoint_interaction_gate | enabled point +105 and bounded spatial gate
; VA 0x544730..0x5447f0 raw 0x143b30 length 192 sha256 a0e7c4f0fda5cea28bf5e11086b5e7aa9a827fbec8fbdcc926e53f1204f0e645
0x544730  55                               push   ebp
0x544731  8bec                             mov    ebp,esp
0x544733  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x544736  83ec08                           sub    esp,0x8
0x544739  80b90501000000                   cmp    BYTE PTR [ecx+0x105],0x0
0x544740  750e                             jne    0x544750
0x544742  c70200000000                     mov    DWORD PTR [edx],0x0
0x544748  33c0                             xor    eax,eax
0x54474a  8be5                             mov    esp,ebp
0x54474c  5d                               pop    ebp
0x54474d  c20c00                           ret    0xc
0x544750  d900                             fld    DWORD PTR [eax]
0x544752  c70201000000                     mov    DWORD PTR [edx],0x1
0x544758  d8a1a0000000                     fsub   DWORD PTR [ecx+0xa0]
0x54475e  d95df8                           fstp   DWORD PTR [ebp-0x8]
0x544761  d94004                           fld    DWORD PTR [eax+0x4]
0x544764  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x544767  d8a1a4000000                     fsub   DWORD PTR [ecx+0xa4]
0x54476d  d95dfc                           fstp   DWORD PTR [ebp-0x4]
0x544770  d945f8                           fld    DWORD PTR [ebp-0x8]
0x544773  d945fc                           fld    DWORD PTR [ebp-0x4]
0x544776  dcc8                             fmul   st(0),st
0x544778  d9c1                             fld    st(1)
0x54477a  deca                             fmulp  st(2),st
0x54477c  dec1                             faddp  st(1),st
0x54477e  d95d08                           fstp   DWORD PTR [ebp+0x8]
0x544781  d94508                           fld    DWORD PTR [ebp+0x8]
0x544784  d910                             fst    DWORD PTR [eax]
0x544786  d981fc000000                     fld    DWORD PTR [ecx+0xfc]
0x54478c  dcc8                             fmul   st(0),st
0x54478e  dff1                             fcomip st,st(1)
0x544790  ddd8                             fstp   st(0)
0x544792  7604                             jbe    0x544798
0x544794  b001                             mov    al,0x1
0x544796  eb02                             jmp    0x54479a
0x544798  32c0                             xor    al,al
0x54479a  83b90001000000                   cmp    DWORD PTR [ecx+0x100],0x0
0x5447a1  752b                             jne    0x5447ce
0x5447a3  837d1000                         cmp    DWORD PTR [ebp+0x10],0x0
0x5447a7  7437                             je     0x5447e0
0x5447a9  84c0                             test   al,al
0x5447ab  7433                             je     0x5447e0
0x5447ad  80b90401000000                   cmp    BYTE PTR [ecx+0x104],0x0
0x5447b4  7406                             je     0x5447bc
0x5447b6  c70200000000                     mov    DWORD PTR [edx],0x0
0x5447bc  c6810401000001                   mov    BYTE PTR [ecx+0x104],0x1
0x5447c3  b801000000                       mov    eax,0x1
0x5447c8  8be5                             mov    esp,ebp
0x5447ca  5d                               pop    ebp
0x5447cb  c20c00                           ret    0xc
0x5447ce  84c0                             test   al,al
0x5447d0  75db                             jne    0x5447ad
0x5447d2  388104010000                     cmp    BYTE PTR [ecx+0x104],al
0x5447d8  7506                             jne    0x5447e0
0x5447da  c70200000000                     mov    DWORD PTR [edx],0x0
0x5447e0  c6810401000000                   mov    BYTE PTR [ecx+0x104],0x0
0x5447e7  33c0                             xor    eax,eax
0x5447e9  8be5                             mov    esp,ebp
0x5447eb  5d                               pop    ebp
0x5447ec  c20c00                           ret    0xc
0x5447ef  cc                               int3

; tutorial_isilia | fixed layout key3 / model4 / world F000; CActor
; VA 0x4aa070..0x4aa240 raw 0xa9470 length 464 sha256 6f5a22b215bf92686ed8776898eda9ac83604f4648fc3a300caa8d436c3ac01f
0x4aa070  55                               push   ebp
0x4aa071  8bec                             mov    ebp,esp
0x4aa073  83e4f8                           and    esp,0xfffffff8
0x4aa076  6aff                             push   0xffffffff
0x4aa078  68e7979300                       push   0x9397e7
0x4aa07d  64a100000000                     mov    eax,fs:0x0
0x4aa083  50                               push   eax
0x4aa084  83ec0c                           sub    esp,0xc
0x4aa087  56                               push   esi
0x4aa088  57                               push   edi
0x4aa089  a1201fd600                       mov    eax,ds:0xd61f20
0x4aa08e  33c4                             xor    eax,esp
0x4aa090  50                               push   eax
0x4aa091  8d442418                         lea    eax,[esp+0x18]
0x4aa095  64a300000000                     mov    fs:0x0,eax
0x4aa09b  8bf1                             mov    esi,ecx
0x4aa09d  8d44240c                         lea    eax,[esp+0xc]
0x4aa0a1  50                               push   eax
0x4aa0a2  8d4e24                           lea    ecx,[esi+0x24]
0x4aa0a5  8d442414                         lea    eax,[esp+0x14]
0x4aa0a9  c744241003000000                 mov    DWORD PTR [esp+0x10],0x3
0x4aa0b1  e87a040000                       call   0x4aa530
0x4aa0b6  8b7628                           mov    esi,DWORD PTR [esi+0x28]
0x4aa0b9  8b442410                         mov    eax,DWORD PTR [esp+0x10]
0x4aa0bd  3bc6                             cmp    eax,esi
0x4aa0bf  0f8462010000                     je     0x4aa227
0x4aa0c5  8d7810                           lea    edi,[eax+0x10]
0x4aa0c8  85ff                             test   edi,edi
0x4aa0ca  0f8457010000                     je     0x4aa227
0x4aa0d0  6820040000                       push   0x420
0x4aa0d5  e88e713e00                       call   0x891268
0x4aa0da  83c404                           add    esp,0x4
0x4aa0dd  89442410                         mov    DWORD PTR [esp+0x10],eax
0x4aa0e1  c744242000000000                 mov    DWORD PTR [esp+0x20],0x0
0x4aa0e9  85c0                             test   eax,eax
0x4aa0eb  740a                             je     0x4aa0f7
0x4aa0ed  50                               push   eax
0x4aa0ee  e87dcf0100                       call   0x4c7070
0x4aa0f3  8bf0                             mov    esi,eax
0x4aa0f5  eb02                             jmp    0x4aa0f9
0x4aa0f7  33f6                             xor    esi,esi
0x4aa0f9  c7442420ffffffff                 mov    DWORD PTR [esp+0x20],0xffffffff
0x4aa101  8b06                             mov    eax,DWORD PTR [esi]
0x4aa103  33c9                             xor    ecx,ecx
0x4aa105  66894c240c                       mov    WORD PTR [esp+0xc],cx
0x4aa10a  66c744240c00f0                   mov    WORD PTR [esp+0xc],0xf000
0x4aa111  668b54240c                       mov    dx,WORD PTR [esp+0xc]
0x4aa116  66895604                         mov    WORD PTR [esi+0x4],dx
0x4aa11a  8b503c                           mov    edx,DWORD PTR [eax+0x3c]
0x4aa11d  6a04                             push   0x4
0x4aa11f  8bce                             mov    ecx,esi
0x4aa121  c7869000000010000000             mov    DWORD PTR [esi+0x90],0x10
0x4aa12b  ffd2                             call   edx
0x4aa12d  8b06                             mov    eax,DWORD PTR [esi]
0x4aa12f  8b5044                           mov    edx,DWORD PTR [eax+0x44]
0x4aa132  6a01                             push   0x1
0x4aa134  83c704                           add    edi,0x4
0x4aa137  57                               push   edi
0x4aa138  8bce                             mov    ecx,esi
0x4aa13a  ffd2                             call   edx
0x4aa13c  8b06                             mov    eax,DWORD PTR [esi]
0x4aa13e  8b5058                           mov    edx,DWORD PTR [eax+0x58]
0x4aa141  6a00                             push   0x0
0x4aa143  8bce                             mov    ecx,esi
0x4aa145  ffd2                             call   edx
0x4aa147  f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x4aa14e  bf01000000                       mov    edi,0x1
0x4aa153  7524                             jne    0x4aa179
0x4aa155  093d2888fb00                     or     DWORD PTR ds:0xfb8828,edi
0x4aa15b  897c2420                         mov    DWORD PTR [esp+0x20],edi
0x4aa15f  e8ec560a00                       call   0x54f850
0x4aa164  6880d5bc00                       push   0xbcd580
0x4aa169  e8ac813e00                       call   0x89231a
0x4aa16e  83c404                           add    esp,0x4
0x4aa171  c7442420ffffffff                 mov    DWORD PTR [esp+0x20],0xffffffff
0x4aa179  d905bc90fb00                     fld    DWORD PTR ds:0xfb90bc
0x4aa17f  8b06                             mov    eax,DWORD PTR [esi]
0x4aa181  dc0d785dc500                     fmul   QWORD PTR ds:0xc55d78
0x4aa187  8b505c                           mov    edx,DWORD PTR [eax+0x5c]
0x4aa18a  51                               push   ecx
0x4aa18b  8bce                             mov    ecx,esi
0x4aa18d  d95c2414                         fstp   DWORD PTR [esp+0x14]
0x4aa191  d9442414                         fld    DWORD PTR [esp+0x14]
0x4aa195  d91c24                           fstp   DWORD PTR [esp]
0x4aa198  ffd2                             call   edx
0x4aa19a  8bc7                             mov    eax,edi
0x4aa19c  66898688030000                   mov    WORD PTR [esi+0x388],ax
0x4aa1a3  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
0x4aa1a9  85c0                             test   eax,eax
0x4aa1ab  7411                             je     0x4aa1be
0x4aa1ad  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
0x4aa1b4  7408                             je     0x4aa1be
0x4aa1b6  57                               push   edi
0x4aa1b7  57                               push   edi
0x4aa1b8  50                               push   eax
0x4aa1b9  e8e2cc2f00                       call   0x7a6ea0
0x4aa1be  8b16                             mov    edx,DWORD PTR [esi]
0x4aa1c0  8b4230                           mov    eax,DWORD PTR [edx+0x30]
0x4aa1c3  8bce                             mov    ecx,esi
0x4aa1c5  ffd0                             call   eax
0x4aa1c7  8b96f0000000                     mov    edx,DWORD PTR [esi+0xf0]
0x4aa1cd  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x4aa1d0  8d8ef0000000                     lea    ecx,[esi+0xf0]
0x4aa1d6  6a14                             push   0x14
0x4aa1d8  ffd0                             call   eax
0x4aa1da  d9e8                             fld1
0x4aa1dc  8b16                             mov    edx,DWORD PTR [esi]
0x4aa1de  8b4268                           mov    eax,DWORD PTR [edx+0x68]
0x4aa1e1  51                               push   ecx
0x4aa1e2  d91c24                           fstp   DWORD PTR [esp]
0x4aa1e5  57                               push   edi
0x4aa1e6  8bce                             mov    ecx,esi
0x4aa1e8  ffd0                             call   eax
0x4aa1ea  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
0x4aa1f1  7528                             jne    0x4aa21b
0x4aa1f3  093d2cb2fa00                     or     DWORD PTR ds:0xfab22c,edi
0x4aa1f9  c744242002000000                 mov    DWORD PTR [esp+0x20],0x2
0x4aa201  e88a4a0300                       call   0x4dec90
0x4aa206  6830cebc00                       push   0xbcce30
0x4aa20b  e80a813e00                       call   0x89231a
0x4aa210  83c404                           add    esp,0x4
0x4aa213  c7442420ffffffff                 mov    DWORD PTR [esp+0x20],0xffffffff
0x4aa21b  6830b1fa00                       push   0xfab130
0x4aa220  8bc6                             mov    eax,esi
0x4aa222  e8095d0300                       call   0x4dff30
0x4aa227  8b4c2418                         mov    ecx,DWORD PTR [esp+0x18]
0x4aa22b  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4aa232  59                               pop    ecx
0x4aa233  5f                               pop    edi
0x4aa234  5e                               pop    esi
0x4aa235  8be5                             mov    esp,ebp
0x4aa237  5d                               pop    ebp
0x4aa238  c3                               ret
0x4aa239  cc                               int3
0x4aa23a  cc                               int3
0x4aa23b  cc                               int3
0x4aa23c  cc                               int3
0x4aa23d  cc                               int3
0x4aa23e  cc                               int3
0x4aa23f  cc                               int3

; npc_tick | base update then NPC quest marker update
; VA 0x4d2890..0x4d28c0 raw 0xd1c90 length 48 sha256 6073be67de51a465660c971dd054f7296784b5a9c9c934527d1eddb71d653bfe
0x4d2890  56                               push   esi
0x4d2891  57                               push   edi
0x4d2892  8bf1                             mov    esi,ecx
0x4d2894  e8e75cffff                       call   0x4c8580
0x4d2899  56                               push   esi
0x4d289a  8bf8                             mov    edi,eax
0x4d289c  e8bffaffff                       call   0x4d2360
0x4d28a1  8bb620040000                     mov    esi,DWORD PTR [esi+0x420]
0x4d28a7  85f6                             test   esi,esi
0x4d28a9  7405                             je     0x4d28b0
0x4d28ab  e8d0de0700                       call   0x550780
0x4d28b0  8bc7                             mov    eax,edi
0x4d28b2  5f                               pop    edi
0x4d28b3  5e                               pop    esi
0x4d28b4  c3                               ret
0x4d28b5  cc                               int3
0x4d28b6  cc                               int3
0x4d28b7  cc                               int3
0x4d28b8  cc                               int3
0x4d28b9  cc                               int3
0x4d28ba  cc                               int3
0x4d28bb  cc                               int3
0x4d28bc  cc                               int3
0x4d28bd  cc                               int3
0x4d28be  cc                               int3
0x4d28bf  cc                               int3

; npc_quest_marker | model low WORD -> quest-related marker producer
; VA 0x4d2360..0x4d2820 raw 0xd1760 length 1216 sha256 9c3e84e16db2846114270ec2b068505a3a9b35811c1801f9bf290cd2f27741a9
0x4d2360  55                               push   ebp
0x4d2361  8bec                             mov    ebp,esp
0x4d2363  6aff                             push   0xffffffff
0x4d2365  680e799400                       push   0x94790e
0x4d236a  64a100000000                     mov    eax,fs:0x0
0x4d2370  50                               push   eax
0x4d2371  83ec28                           sub    esp,0x28
0x4d2374  a1201fd600                       mov    eax,ds:0xd61f20
0x4d2379  33c5                             xor    eax,ebp
0x4d237b  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4d237e  53                               push   ebx
0x4d237f  56                               push   esi
0x4d2380  57                               push   edi
0x4d2381  50                               push   eax
0x4d2382  8d45f4                           lea    eax,[ebp-0xc]
0x4d2385  64a300000000                     mov    fs:0x0,eax
0x4d238b  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4d238e  33ff                             xor    edi,edi
0x4d2390  39bb6c030000                     cmp    DWORD PTR [ebx+0x36c],edi
0x4d2396  0f8544040000                     jne    0x4d27e0
0x4d239c  8b03                             mov    eax,DWORD PTR [ebx]
0x4d239e  8b504c                           mov    edx,DWORD PTR [eax+0x4c]
0x4d23a1  8bcb                             mov    ecx,ebx
0x4d23a3  ffd2                             call   edx
0x4d23a5  8b08                             mov    ecx,DWORD PTR [eax]
0x4d23a7  8bb35c010000                     mov    esi,DWORD PTR [ebx+0x15c]
0x4d23ad  894de4                           mov    DWORD PTR [ebp-0x1c],ecx
0x4d23b0  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4d23b3  8955e8                           mov    DWORD PTR [ebp-0x18],edx
0x4d23b6  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4d23b9  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4d23bc  3bf7                             cmp    esi,edi
0x4d23be  7412                             je     0x4d23d2
0x4d23c0  39bb70030000                     cmp    DWORD PTR [ebx+0x370],edi
0x4d23c6  740a                             je     0x4d23d2
0x4d23c8  e8334d2d00                       call   0x7a7100
0x4d23cd  d95dcc                           fstp   DWORD PTR [ebp-0x34]
0x4d23d0  eb08                             jmp    0x4d23da
0x4d23d2  0f57c0                           xorps  xmm0,xmm0
0x4d23d5  f30f1145cc                       movss  DWORD PTR [ebp-0x34],xmm0
0x4d23da  f6059cb2fa0001                   test   BYTE PTR ds:0xfab29c,0x1
0x4d23e1  d945cc                           fld    DWORD PTR [ebp-0x34]
0x4d23e4  dc05905ec500                     fadd   QWORD PTR ds:0xc55e90
0x4d23ea  0fb7b388000000                   movzx  esi,WORD PTR [ebx+0x88]
0x4d23f1  d845ec                           fadd   DWORD PTR [ebp-0x14]
0x4d23f4  d95dec                           fstp   DWORD PTR [ebp-0x14]
0x4d23f7  7523                             jne    0x4d241c
0x4d23f9  830d9cb2fa0001                   or     DWORD PTR ds:0xfab29c,0x1
0x4d2400  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4d2403  e858da0200                       call   0x4ffe60
0x4d2408  6800cfbc00                       push   0xbccf00
0x4d240d  e808ff3b00                       call   0x89231a
0x4d2412  83c404                           add    esp,0x4
0x4d2415  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4d241c  56                               push   esi
0x4d241d  68a0b2fa00                       push   0xfab2a0
0x4d2422  e859e60200                       call   0x500a80
0x4d2427  83f806                           cmp    eax,0x6
0x4d242a  0f87b0030000                     ja     0x4d27e0
0x4d2430  ff248500284d00                   jmp    DWORD PTR [eax*4+0x4d2800]
0x4d2437  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d243d  3bc7                             cmp    eax,edi
0x4d243f  7428                             je     0x4d2469
0x4d2441  397824                           cmp    DWORD PTR [eax+0x24],edi
0x4d2444  8d7024                           lea    esi,[eax+0x24]
0x4d2447  7405                             je     0x4d244e
0x4d2449  e8a2c12e00                       call   0x7be5f0
0x4d244e  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d2454  3bc7                             cmp    eax,edi
0x4d2456  7411                             je     0x4d2469
0x4d2458  8bf8                             mov    edi,eax
0x4d245a  e85159ffff                       call   0x4c7db0
0x4d245f  c7832004000000000000             mov    DWORD PTR [ebx+0x420],0x0
0x4d2469  c78324040000ffffffff             mov    DWORD PTR [ebx+0x424],0xffffffff
0x4d2473  e968030000                       jmp    0x4d27e0
0x4d2478  83bb2404000006                   cmp    DWORD PTR [ebx+0x424],0x6
0x4d247f  0f845b030000                     je     0x4d27e0
0x4d2485  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d248b  3bc7                             cmp    eax,edi
0x4d248d  742a                             je     0x4d24b9
0x4d248f  397824                           cmp    DWORD PTR [eax+0x24],edi
0x4d2492  8d7024                           lea    esi,[eax+0x24]
0x4d2495  7405                             je     0x4d249c
0x4d2497  e854c12e00                       call   0x7be5f0
0x4d249c  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d24a2  3bc7                             cmp    eax,edi
0x4d24a4  7413                             je     0x4d24b9
0x4d24a6  8bf8                             mov    edi,eax
0x4d24a8  e80359ffff                       call   0x4c7db0
0x4d24ad  c7832004000000000000             mov    DWORD PTR [ebx+0x420],0x0
0x4d24b7  33ff                             xor    edi,edi
0x4d24b9  d9e8                             fld1
0x4d24bb  0fb75304                         movzx  edx,WORD PTR [ebx+0x4]
0x4d24bf  83ec08                           sub    esp,0x8
0x4d24c2  897dd0                           mov    DWORD PTR [ebp-0x30],edi
0x4d24c5  c745d4b8c8c000                   mov    DWORD PTR [ebp-0x2c],0xc0c8b8
0x4d24cc  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4d24d0  897dd8                           mov    DWORD PTR [ebp-0x28],edi
0x4d24d3  d9ee                             fldz
0x4d24d5  c745dc06000000                   mov    DWORD PTR [ebp-0x24],0x6
0x4d24dc  d91c24                           fstp   DWORD PTR [esp]
0x4d24df  52                               push   edx
0x4d24e0  897de0                           mov    DWORD PTR [ebp-0x20],edi
0x4d24e3  e8588cfcff                       call   0x49b140
0x4d24e8  8d75e4                           lea    esi,[ebp-0x1c]
0x4d24eb  8d55d0                           lea    edx,[ebp-0x30]
0x4d24ee  8bc8                             mov    ecx,eax
0x4d24f0  e89bfa0700                       call   0x551f90
0x4d24f5  c7832404000006000000             mov    DWORD PTR [ebx+0x424],0x6
0x4d24ff  e9d6020000                       jmp    0x4d27da
0x4d2504  39bb24040000                     cmp    DWORD PTR [ebx+0x424],edi
0x4d250a  0f84d0020000                     je     0x4d27e0
0x4d2510  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d2516  3bc7                             cmp    eax,edi
0x4d2518  742a                             je     0x4d2544
0x4d251a  397824                           cmp    DWORD PTR [eax+0x24],edi
0x4d251d  8d7024                           lea    esi,[eax+0x24]
0x4d2520  7405                             je     0x4d2527
0x4d2522  e8c9c02e00                       call   0x7be5f0
0x4d2527  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d252d  3bc7                             cmp    eax,edi
0x4d252f  7413                             je     0x4d2544
0x4d2531  8bf8                             mov    edi,eax
0x4d2533  e87858ffff                       call   0x4c7db0
0x4d2538  c7832004000000000000             mov    DWORD PTR [ebx+0x420],0x0
0x4d2542  33ff                             xor    edi,edi
0x4d2544  d9e8                             fld1
0x4d2546  0fb74304                         movzx  eax,WORD PTR [ebx+0x4]
0x4d254a  83ec08                           sub    esp,0x8
0x4d254d  897dd0                           mov    DWORD PTR [ebp-0x30],edi
0x4d2550  c745d4b8c8c000                   mov    DWORD PTR [ebp-0x2c],0xc0c8b8
0x4d2557  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4d255b  897dd8                           mov    DWORD PTR [ebp-0x28],edi
0x4d255e  d9ee                             fldz
0x4d2560  897ddc                           mov    DWORD PTR [ebp-0x24],edi
0x4d2563  d91c24                           fstp   DWORD PTR [esp]
0x4d2566  50                               push   eax
0x4d2567  897de0                           mov    DWORD PTR [ebp-0x20],edi
0x4d256a  e8d18bfcff                       call   0x49b140
0x4d256f  8d75e4                           lea    esi,[ebp-0x1c]
0x4d2572  8d55d0                           lea    edx,[ebp-0x30]
0x4d2575  8bc8                             mov    ecx,eax
0x4d2577  e814fa0700                       call   0x551f90
0x4d257c  89bb24040000                     mov    DWORD PTR [ebx+0x424],edi
0x4d2582  e953020000                       jmp    0x4d27da
0x4d2587  83bb2404000003                   cmp    DWORD PTR [ebx+0x424],0x3
0x4d258e  0f844c020000                     je     0x4d27e0
0x4d2594  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d259a  3bc7                             cmp    eax,edi
0x4d259c  742a                             je     0x4d25c8
0x4d259e  397824                           cmp    DWORD PTR [eax+0x24],edi
0x4d25a1  8d7024                           lea    esi,[eax+0x24]
0x4d25a4  7405                             je     0x4d25ab
0x4d25a6  e845c02e00                       call   0x7be5f0
0x4d25ab  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d25b1  3bc7                             cmp    eax,edi
0x4d25b3  7413                             je     0x4d25c8
0x4d25b5  8bf8                             mov    edi,eax
0x4d25b7  e8f457ffff                       call   0x4c7db0
0x4d25bc  c7832004000000000000             mov    DWORD PTR [ebx+0x420],0x0
0x4d25c6  33ff                             xor    edi,edi
0x4d25c8  d9e8                             fld1
0x4d25ca  0fb74b04                         movzx  ecx,WORD PTR [ebx+0x4]
0x4d25ce  83ec08                           sub    esp,0x8
0x4d25d1  897dd0                           mov    DWORD PTR [ebp-0x30],edi
0x4d25d4  c745d4b8c8c000                   mov    DWORD PTR [ebp-0x2c],0xc0c8b8
0x4d25db  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4d25df  897dd8                           mov    DWORD PTR [ebp-0x28],edi
0x4d25e2  d9ee                             fldz
0x4d25e4  c745dc03000000                   mov    DWORD PTR [ebp-0x24],0x3
0x4d25eb  d91c24                           fstp   DWORD PTR [esp]
0x4d25ee  51                               push   ecx
0x4d25ef  897de0                           mov    DWORD PTR [ebp-0x20],edi
0x4d25f2  e8498bfcff                       call   0x49b140
0x4d25f7  8d75e4                           lea    esi,[ebp-0x1c]
0x4d25fa  8d55d0                           lea    edx,[ebp-0x30]
0x4d25fd  8bc8                             mov    ecx,eax
0x4d25ff  e88cf90700                       call   0x551f90
0x4d2604  c7832404000003000000             mov    DWORD PTR [ebx+0x424],0x3
0x4d260e  e9c7010000                       jmp    0x4d27da
0x4d2613  83bb2404000001                   cmp    DWORD PTR [ebx+0x424],0x1
0x4d261a  0f84c0010000                     je     0x4d27e0
0x4d2620  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d2626  3bc7                             cmp    eax,edi
0x4d2628  742a                             je     0x4d2654
0x4d262a  397824                           cmp    DWORD PTR [eax+0x24],edi
0x4d262d  8d7024                           lea    esi,[eax+0x24]
0x4d2630  7405                             je     0x4d2637
0x4d2632  e8b9bf2e00                       call   0x7be5f0
0x4d2637  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d263d  3bc7                             cmp    eax,edi
0x4d263f  7413                             je     0x4d2654
0x4d2641  8bf8                             mov    edi,eax
0x4d2643  e86857ffff                       call   0x4c7db0
0x4d2648  c7832004000000000000             mov    DWORD PTR [ebx+0x420],0x0
0x4d2652  33ff                             xor    edi,edi
0x4d2654  d9e8                             fld1
0x4d2656  0fb75304                         movzx  edx,WORD PTR [ebx+0x4]
0x4d265a  83ec08                           sub    esp,0x8
0x4d265d  897dd0                           mov    DWORD PTR [ebp-0x30],edi
0x4d2660  c745d4b8c8c000                   mov    DWORD PTR [ebp-0x2c],0xc0c8b8
0x4d2667  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4d266b  897dd8                           mov    DWORD PTR [ebp-0x28],edi
0x4d266e  d9ee                             fldz
0x4d2670  c745dc01000000                   mov    DWORD PTR [ebp-0x24],0x1
0x4d2677  d91c24                           fstp   DWORD PTR [esp]
0x4d267a  52                               push   edx
0x4d267b  897de0                           mov    DWORD PTR [ebp-0x20],edi
0x4d267e  e8bd8afcff                       call   0x49b140
0x4d2683  8d75e4                           lea    esi,[ebp-0x1c]
0x4d2686  8d55d0                           lea    edx,[ebp-0x30]
0x4d2689  8bc8                             mov    ecx,eax
0x4d268b  e800f90700                       call   0x551f90
0x4d2690  c7832404000001000000             mov    DWORD PTR [ebx+0x424],0x1
0x4d269a  e93b010000                       jmp    0x4d27da
0x4d269f  83bb2404000004                   cmp    DWORD PTR [ebx+0x424],0x4
0x4d26a6  0f8434010000                     je     0x4d27e0
0x4d26ac  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d26b2  3bc7                             cmp    eax,edi
0x4d26b4  742a                             je     0x4d26e0
0x4d26b6  397824                           cmp    DWORD PTR [eax+0x24],edi
0x4d26b9  8d7024                           lea    esi,[eax+0x24]
0x4d26bc  7405                             je     0x4d26c3
0x4d26be  e82dbf2e00                       call   0x7be5f0
0x4d26c3  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d26c9  3bc7                             cmp    eax,edi
0x4d26cb  7413                             je     0x4d26e0
0x4d26cd  8bf8                             mov    edi,eax
0x4d26cf  e8dc56ffff                       call   0x4c7db0
0x4d26d4  c7832004000000000000             mov    DWORD PTR [ebx+0x420],0x0
0x4d26de  33ff                             xor    edi,edi
0x4d26e0  d9e8                             fld1
0x4d26e2  0fb74304                         movzx  eax,WORD PTR [ebx+0x4]
0x4d26e6  83ec08                           sub    esp,0x8
0x4d26e9  897dd0                           mov    DWORD PTR [ebp-0x30],edi
0x4d26ec  c745d4b8c8c000                   mov    DWORD PTR [ebp-0x2c],0xc0c8b8
0x4d26f3  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4d26f7  897dd8                           mov    DWORD PTR [ebp-0x28],edi
0x4d26fa  d9ee                             fldz
0x4d26fc  c745dc04000000                   mov    DWORD PTR [ebp-0x24],0x4
0x4d2703  d91c24                           fstp   DWORD PTR [esp]
0x4d2706  50                               push   eax
0x4d2707  897de0                           mov    DWORD PTR [ebp-0x20],edi
0x4d270a  e8318afcff                       call   0x49b140
0x4d270f  8d75e4                           lea    esi,[ebp-0x1c]
0x4d2712  8d55d0                           lea    edx,[ebp-0x30]
0x4d2715  8bc8                             mov    ecx,eax
0x4d2717  e874f80700                       call   0x551f90
0x4d271c  c7832404000004000000             mov    DWORD PTR [ebx+0x424],0x4
0x4d2726  e9af000000                       jmp    0x4d27da
0x4d272b  e87024f3ff                       call   0x404ba0
0x4d2730  83bb2404000002                   cmp    DWORD PTR [ebx+0x424],0x2
0x4d2737  8b804c5f0000                     mov    eax,DWORD PTR [eax+0x5f4c]
0x4d273d  0f849d000000                     je     0x4d27e0
0x4d2743  83f803                           cmp    eax,0x3
0x4d2746  7418                             je     0x4d2760
0x4d2748  83f801                           cmp    eax,0x1
0x4d274b  7413                             je     0x4d2760
0x4d274d  83f807                           cmp    eax,0x7
0x4d2750  740e                             je     0x4d2760
0x4d2752  83f817                           cmp    eax,0x17
0x4d2755  7409                             je     0x4d2760
0x4d2757  83f818                           cmp    eax,0x18
0x4d275a  0f8580000000                     jne    0x4d27e0
0x4d2760  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d2766  3bc7                             cmp    eax,edi
0x4d2768  742a                             je     0x4d2794
0x4d276a  397824                           cmp    DWORD PTR [eax+0x24],edi
0x4d276d  8d7024                           lea    esi,[eax+0x24]
0x4d2770  7405                             je     0x4d2777
0x4d2772  e879be2e00                       call   0x7be5f0
0x4d2777  8b8320040000                     mov    eax,DWORD PTR [ebx+0x420]
0x4d277d  3bc7                             cmp    eax,edi
0x4d277f  7413                             je     0x4d2794
0x4d2781  8bf8                             mov    edi,eax
0x4d2783  e82856ffff                       call   0x4c7db0
0x4d2788  c7832004000000000000             mov    DWORD PTR [ebx+0x420],0x0
0x4d2792  33ff                             xor    edi,edi
0x4d2794  d9e8                             fld1
0x4d2796  0fb74b04                         movzx  ecx,WORD PTR [ebx+0x4]
0x4d279a  83ec08                           sub    esp,0x8
0x4d279d  897dd0                           mov    DWORD PTR [ebp-0x30],edi
0x4d27a0  c745d4b8c8c000                   mov    DWORD PTR [ebp-0x2c],0xc0c8b8
0x4d27a7  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4d27ab  897dd8                           mov    DWORD PTR [ebp-0x28],edi
0x4d27ae  d9ee                             fldz
0x4d27b0  c745dc02000000                   mov    DWORD PTR [ebp-0x24],0x2
0x4d27b7  d91c24                           fstp   DWORD PTR [esp]
0x4d27ba  51                               push   ecx
0x4d27bb  897de0                           mov    DWORD PTR [ebp-0x20],edi
0x4d27be  e87d89fcff                       call   0x49b140
0x4d27c3  8d75e4                           lea    esi,[ebp-0x1c]
0x4d27c6  8d55d0                           lea    edx,[ebp-0x30]
0x4d27c9  8bc8                             mov    ecx,eax
0x4d27cb  e8c0f70700                       call   0x551f90
0x4d27d0  c7832404000002000000             mov    DWORD PTR [ebx+0x424],0x2
0x4d27da  898320040000                     mov    DWORD PTR [ebx+0x420],eax
0x4d27e0  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4d27e3  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4d27ea  59                               pop    ecx
0x4d27eb  5f                               pop    edi
0x4d27ec  5e                               pop    esi
0x4d27ed  5b                               pop    ebx
0x4d27ee  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x4d27f1  33cd                             xor    ecx,ebp
0x4d27f3  e809e83b00                       call   0x891001
0x4d27f8  8be5                             mov    esp,ebp
0x4d27fa  5d                               pop    ebp
0x4d27fb  c20400                           ret    0x4
0x4d27fe  8bff                             mov    edi,edi
0x4d2800  37                               aaa
0x4d2801  244d                             and    al,0x4d
0x4d2803  0004254d008725                   add    BYTE PTR [eiz*1+0x2587004d],al
0x4d280a  4d                               dec    ebp
0x4d280b  0013                             add    BYTE PTR [ebx],dl
0x4d280d  264d                             es dec ebp
0x4d280f  009f264d002b                     add    BYTE PTR [edi+0x2b004d26],bl
0x4d2815  27                               daa
0x4d2816  4d                               dec    ebp
0x4d2817  007824                           add    BYTE PTR [eax+0x24],bh
0x4d281a  4d                               dec    ebp
0x4d281b  00cc                             add    ah,cl
0x4d281d  cc                               int3
0x4d281e  cc                               int3
0x4d281f  cc                               int3

; npc_slow_tick | conditional CDoll update through common actor tick
; VA 0x4d28c0..0x4d2a80 raw 0xd1cc0 length 448 sha256 67b75a157dd8f6ea26e095ab898c412eef131a723f6a66a0a76eb1d4029e9761
0x4d28c0  55                               push   ebp
0x4d28c1  8bec                             mov    ebp,esp
0x4d28c3  83e4f8                           and    esp,0xfffffff8
0x4d28c6  6aff                             push   0xffffffff
0x4d28c8  68fea39300                       push   0x93a3fe
0x4d28cd  64a100000000                     mov    eax,fs:0x0
0x4d28d3  50                               push   eax
0x4d28d4  83ec60                           sub    esp,0x60
0x4d28d7  a1201fd600                       mov    eax,ds:0xd61f20
0x4d28dc  33c4                             xor    eax,esp
0x4d28de  89442458                         mov    DWORD PTR [esp+0x58],eax
0x4d28e2  53                               push   ebx
0x4d28e3  56                               push   esi
0x4d28e4  57                               push   edi
0x4d28e5  a1201fd600                       mov    eax,ds:0xd61f20
0x4d28ea  33c4                             xor    eax,esp
0x4d28ec  50                               push   eax
0x4d28ed  8d442470                         lea    eax,[esp+0x70]
0x4d28f1  64a300000000                     mov    fs:0x0,eax
0x4d28f7  d94508                           fld    DWORD PTR [ebp+0x8]
0x4d28fa  f30f104508                       movss  xmm0,DWORD PTR [ebp+0x8]
0x4d28ff  0f2f05285ac500                   comiss xmm0,DWORD PTR ds:0xc55a28
0x4d2906  8bf1                             mov    esi,ecx
0x4d2908  d88628040000                     fadd   DWORD PTR [esi+0x428]
0x4d290e  d99e28040000                     fstp   DWORD PTR [esi+0x428]
0x4d2914  0f86f1000000                     jbe    0x4d2a0b
0x4d291a  b801000000                       mov    eax,0x1
0x4d291f  8405e879fb00                     test   BYTE PTR ds:0xfb79e8,al
0x4d2925  7528                             jne    0x4d294f
0x4d2927  0905e879fb00                     or     DWORD PTR ds:0xfb79e8,eax
0x4d292d  c744247800000000                 mov    DWORD PTR [esp+0x78],0x0
0x4d2935  e8a6642c00                       call   0x798de0
0x4d293a  68e0d2bc00                       push   0xbcd2e0
0x4d293f  e8d6f93b00                       call   0x89231a
0x4d2944  83c404                           add    esp,0x4
0x4d2947  c7442478ffffffff                 mov    DWORD PTR [esp+0x78],0xffffffff
0x4d294f  a1e876fb00                       mov    eax,ds:0xfb76e8
0x4d2954  85c0                             test   eax,eax
0x4d2956  0f84af000000                     je     0x4d2a0b
0x4d295c  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0x4d295f  8b01                             mov    eax,DWORD PTR [ecx]
0x4d2961  8b4024                           mov    eax,DWORD PTR [eax+0x24]
0x4d2964  8d542430                         lea    edx,[esp+0x30]
0x4d2968  52                               push   edx
0x4d2969  ffd0                             call   eax
0x4d296b  8b08                             mov    ecx,DWORD PTR [eax]
0x4d296d  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4d2970  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4d2973  894c2424                         mov    DWORD PTR [esp+0x24],ecx
0x4d2977  8b8e5c010000                     mov    ecx,DWORD PTR [esi+0x15c]
0x4d297d  89542428                         mov    DWORD PTR [esp+0x28],edx
0x4d2981  8b5104                           mov    edx,DWORD PTR [ecx+0x4]
0x4d2984  8b5208                           mov    edx,DWORD PTR [edx+0x8]
0x4d2987  83c104                           add    ecx,0x4
0x4d298a  8944242c                         mov    DWORD PTR [esp+0x2c],eax
0x4d298e  8d44245c                         lea    eax,[esp+0x5c]
0x4d2992  50                               push   eax
0x4d2993  ffd2                             call   edx
0x4d2995  d9442424                         fld    DWORD PTR [esp+0x24]
0x4d2999  d864245c                         fsub   DWORD PTR [esp+0x5c]
0x4d299d  d95c2418                         fstp   DWORD PTR [esp+0x18]
0x4d29a1  d9442428                         fld    DWORD PTR [esp+0x28]
0x4d29a5  d8642460                         fsub   DWORD PTR [esp+0x60]
0x4d29a9  d95c241c                         fstp   DWORD PTR [esp+0x1c]
0x4d29ad  d944242c                         fld    DWORD PTR [esp+0x2c]
0x4d29b1  d8642464                         fsub   DWORD PTR [esp+0x64]
0x4d29b5  d95c2420                         fstp   DWORD PTR [esp+0x20]
0x4d29b9  d944241c                         fld    DWORD PTR [esp+0x1c]
0x4d29bd  d9442418                         fld    DWORD PTR [esp+0x18]
0x4d29c1  d9442420                         fld    DWORD PTR [esp+0x20]
0x4d29c5  d9c1                             fld    st(1)
0x4d29c7  deca                             fmulp  st(2),st
0x4d29c9  d9c2                             fld    st(2)
0x4d29cb  decb                             fmulp  st(3),st
0x4d29cd  d9c9                             fxch   st(1)
0x4d29cf  dec2                             faddp  st(2),st
0x4d29d1  dcc8                             fmul   st(0),st
0x4d29d3  dec1                             faddp  st(1),st
0x4d29d5  d95c2414                         fstp   DWORD PTR [esp+0x14]
0x4d29d9  d9442414                         fld    DWORD PTR [esp+0x14]
0x4d29dd  e88ece4200                       call   0x8ff870
0x4d29e2  d95c2414                         fstp   DWORD PTR [esp+0x14]
0x4d29e6  dd05205bc500                     fld    QWORD PTR ds:0xc55b20
0x4d29ec  d9442414                         fld    DWORD PTR [esp+0x14]
0x4d29f0  dff1                             fcomip st,st(1)
0x4d29f2  ddd8                             fstp   st(0)
0x4d29f4  7615                             jbe    0x4d2a0b
0x4d29f6  f30f1005e05dc500                 movss  xmm0,DWORD PTR ds:0xc55de0
0x4d29fe  0f2f8628040000                   comiss xmm0,DWORD PTR [esi+0x428]
0x4d2a05  7604                             jbe    0x4d2a0b
0x4d2a07  33c0                             xor    eax,eax
0x4d2a09  eb48                             jmp    0x4d2a53
0x4d2a0b  d98628040000                     fld    DWORD PTR [esi+0x428]
0x4d2a11  0f57c0                           xorps  xmm0,xmm0
0x4d2a14  d95c2414                         fstp   DWORD PTR [esp+0x14]
0x4d2a18  51                               push   ecx
0x4d2a19  d9442418                         fld    DWORD PTR [esp+0x18]
0x4d2a1d  8bce                             mov    ecx,esi
0x4d2a1f  d91c24                           fstp   DWORD PTR [esp]
0x4d2a22  f30f118628040000                 movss  DWORD PTR [esi+0x428],xmm0
0x4d2a2a  e8a15dffff                       call   0x4c87d0
0x4d2a2f  8bb620040000                     mov    esi,DWORD PTR [esi+0x420]
0x4d2a35  8bd8                             mov    ebx,eax
0x4d2a37  85f6                             test   esi,esi
0x4d2a39  7416                             je     0x4d2a51
0x4d2a3b  8b7624                           mov    esi,DWORD PTR [esi+0x24]
0x4d2a3e  85f6                             test   esi,esi
0x4d2a40  740f                             je     0x4d2a51
0x4d2a42  d9442414                         fld    DWORD PTR [esp+0x14]
0x4d2a46  51                               push   ecx
0x4d2a47  8bfe                             mov    edi,esi
0x4d2a49  d91c24                           fstp   DWORD PTR [esp]
0x4d2a4c  e87fae2e00                       call   0x7bd8d0
0x4d2a51  8bc3                             mov    eax,ebx
0x4d2a53  8b4c2470                         mov    ecx,DWORD PTR [esp+0x70]
0x4d2a57  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4d2a5e  59                               pop    ecx
0x4d2a5f  5f                               pop    edi
0x4d2a60  5e                               pop    esi
0x4d2a61  5b                               pop    ebx
0x4d2a62  8b4c2458                         mov    ecx,DWORD PTR [esp+0x58]
0x4d2a66  33cc                             xor    ecx,esp
0x4d2a68  e894e53b00                       call   0x891001
0x4d2a6d  8be5                             mov    esp,ebp
0x4d2a6f  5d                               pop    ebp
0x4d2a70  c20400                           ret    0x4
0x4d2a73  cc                               int3
0x4d2a74  cc                               int3
0x4d2a75  cc                               int3
0x4d2a76  cc                               int3
0x4d2a77  cc                               int3
0x4d2a78  cc                               int3
0x4d2a79  cc                               int3
0x4d2a7a  cc                               int3
0x4d2a7b  cc                               int3
0x4d2a7c  cc                               int3
0x4d2a7d  cc                               int3
0x4d2a7e  cc                               int3
0x4d2a7f  cc                               int3

; npc_draw | base render plus model-derived NPC name and NPC-table title
; VA 0x4d2a80..0x4d2cb0 raw 0xd1e80 length 560 sha256 97df8e307d735a42fc51f28b56ab111c362fe2f584d11f6b9e10e671d2b624eb
0x4d2a80  55                               push   ebp
0x4d2a81  8bec                             mov    ebp,esp
0x4d2a83  83e4f8                           and    esp,0xfffffff8
0x4d2a86  6aff                             push   0xffffffff
0x4d2a88  68a6a29300                       push   0x93a2a6
0x4d2a8d  64a100000000                     mov    eax,fs:0x0
0x4d2a93  50                               push   eax
0x4d2a94  83ec48                           sub    esp,0x48
0x4d2a97  a1201fd600                       mov    eax,ds:0xd61f20
0x4d2a9c  33c4                             xor    eax,esp
0x4d2a9e  89442440                         mov    DWORD PTR [esp+0x40],eax
0x4d2aa2  53                               push   ebx
0x4d2aa3  56                               push   esi
0x4d2aa4  57                               push   edi
0x4d2aa5  a1201fd600                       mov    eax,ds:0xd61f20
0x4d2aaa  33c4                             xor    eax,esp
0x4d2aac  50                               push   eax
0x4d2aad  8d442458                         lea    eax,[esp+0x58]
0x4d2ab1  64a300000000                     mov    fs:0x0,eax
0x4d2ab7  8bd9                             mov    ebx,ecx
0x4d2ab9  e8325effff                       call   0x4c88f0
0x4d2abe  33f6                             xor    esi,esi
0x4d2ac0  8bf8                             mov    edi,eax
0x4d2ac2  897c2424                         mov    DWORD PTR [esp+0x24],edi
0x4d2ac6  39b370030000                     cmp    DWORD PTR [ebx+0x370],esi
0x4d2acc  0f849e010000                     je     0x4d2c70
0x4d2ad2  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
0x4d2ad8  8d8ba0000000                     lea    ecx,[ebx+0xa0]
0x4d2ade  3bc6                             cmp    eax,esi
0x4d2ae0  7415                             je     0x4d2af7
0x4d2ae2  d9e8                             fld1
0x4d2ae4  51                               push   ecx
0x4d2ae5  8d7c241c                         lea    edi,[esp+0x1c]
0x4d2ae9  d91c24                           fstp   DWORD PTR [esp]
0x4d2aec  e83f5b2d00                       call   0x7a8630
0x4d2af1  8b7c2418                         mov    edi,DWORD PTR [esp+0x18]
0x4d2af5  eb10                             jmp    0x4d2b07
0x4d2af7  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x4d2afa  8b39                             mov    edi,DWORD PTR [ecx]
0x4d2afc  8b4908                           mov    ecx,DWORD PTR [ecx+0x8]
0x4d2aff  8944241c                         mov    DWORD PTR [esp+0x1c],eax
0x4d2b03  894c2420                         mov    DWORD PTR [esp+0x20],ecx
0x4d2b07  f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x4d2b0e  8974242c                         mov    DWORD PTR [esp+0x2c],esi
0x4d2b12  c7442430ecffffff                 mov    DWORD PTR [esp+0x30],0xffffffec
0x4d2b1a  7525                             jne    0x4d2b41
0x4d2b1c  830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
0x4d2b23  89742460                         mov    DWORD PTR [esp+0x60],esi
0x4d2b27  e854120200                       call   0x4f3d80
0x4d2b2c  68e0d1bc00                       push   0xbcd1e0
0x4d2b31  e8e4f73b00                       call   0x89231a
0x4d2b36  83c404                           add    esp,0x4
0x4d2b39  c7442460ffffffff                 mov    DWORD PTR [esp+0x60],0xffffffff
0x4d2b41  8b9388000000                     mov    edx,DWORD PTR [ebx+0x88]
0x4d2b47  89542414                         mov    DWORD PTR [esp+0x14],edx
0x4d2b4b  8d542414                         lea    edx,[esp+0x14]
0x4d2b4f  b97074fb00                       mov    ecx,0xfb7470
0x4d2b54  e8174f0200                       call   0x4f7a70
0x4d2b59  83783008                         cmp    DWORD PTR [eax+0x30],0x8
0x4d2b5d  7205                             jb     0x4d2b64
0x4d2b5f  8b481c                           mov    ecx,DWORD PTR [eax+0x1c]
0x4d2b62  eb03                             jmp    0x4d2b67
0x4d2b64  8d481c                           lea    ecx,[eax+0x1c]
0x4d2b67  8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
0x4d2b6b  56                               push   esi
0x4d2b6c  68000000ff                       push   0xff000000
0x4d2b71  68aaff00ff                       push   0xff00ffaa
0x4d2b76  83ec0c                           sub    esp,0xc
0x4d2b79  8bc4                             mov    eax,esp
0x4d2b7b  8938                             mov    DWORD PTR [eax],edi
0x4d2b7d  895004                           mov    DWORD PTR [eax+0x4],edx
0x4d2b80  8b542438                         mov    edx,DWORD PTR [esp+0x38]
0x4d2b84  51                               push   ecx
0x4d2b85  33c9                             xor    ecx,ecx
0x4d2b87  895008                           mov    DWORD PTR [eax+0x8],edx
0x4d2b8a  e8d16fffff                       call   0x4c9b60
0x4d2b8f  33c0                             xor    eax,eax
0x4d2b91  83c41c                           add    esp,0x1c
0x4d2b94  c744244807000000                 mov    DWORD PTR [esp+0x48],0x7
0x4d2b9c  89742444                         mov    DWORD PTR [esp+0x44],esi
0x4d2ba0  6689442434                       mov    WORD PTR [esp+0x34],ax
0x4d2ba5  c744246001000000                 mov    DWORD PTR [esp+0x60],0x1
0x4d2bad  0fb78b88000000                   movzx  ecx,WORD PTR [ebx+0x88]
0x4d2bb4  8b35d01bfe00                     mov    esi,DWORD PTR ds:0xfe1bd0
0x4d2bba  8d542414                         lea    edx,[esp+0x14]
0x4d2bbe  894c2414                         mov    DWORD PTR [esp+0x14],ecx
0x4d2bc2  52                               push   edx
0x4d2bc3  8d4e08                           lea    ecx,[esi+0x8]
0x4d2bc6  8d44242c                         lea    eax,[esp+0x2c]
0x4d2bca  e8f10c3700                       call   0x8438c0
0x4d2bcf  8b760c                           mov    esi,DWORD PTR [esi+0xc]
0x4d2bd2  8b442428                         mov    eax,DWORD PTR [esp+0x28]
0x4d2bd6  3bc6                             cmp    eax,esi
0x4d2bd8  745d                             je     0x4d2c37
0x4d2bda  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4d2bdd  85c0                             test   eax,eax
0x4d2bdf  7456                             je     0x4d2c37
0x4d2be1  6aff                             push   0xffffffff
0x4d2be3  6a00                             push   0x0
0x4d2be5  83c024                           add    eax,0x24
0x4d2be8  50                               push   eax
0x4d2be9  8d4c2440                         lea    ecx,[esp+0x40]
0x4d2bed  e8eefaf2ff                       call   0x4026e0
0x4d2bf2  837c244400                       cmp    DWORD PTR [esp+0x44],0x0
0x4d2bf7  743e                             je     0x4d2c37
0x4d2bf9  837c244808                       cmp    DWORD PTR [esp+0x48],0x8
0x4d2bfe  8b4c2434                         mov    ecx,DWORD PTR [esp+0x34]
0x4d2c02  7304                             jae    0x4d2c08
0x4d2c04  8d4c2434                         lea    ecx,[esp+0x34]
0x4d2c08  8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
0x4d2c0c  8d44242c                         lea    eax,[esp+0x2c]
0x4d2c10  50                               push   eax
0x4d2c11  68000000ff                       push   0xff000000
0x4d2c16  68ffffaaff                       push   0xffaaffff
0x4d2c1b  83ec0c                           sub    esp,0xc
0x4d2c1e  8bc4                             mov    eax,esp
0x4d2c20  8938                             mov    DWORD PTR [eax],edi
0x4d2c22  895004                           mov    DWORD PTR [eax+0x4],edx
0x4d2c25  8b542438                         mov    edx,DWORD PTR [esp+0x38]
0x4d2c29  51                               push   ecx
0x4d2c2a  33c9                             xor    ecx,ecx
0x4d2c2c  895008                           mov    DWORD PTR [eax+0x8],edx
0x4d2c2f  e82c6fffff                       call   0x4c9b60
0x4d2c34  83c41c                           add    esp,0x1c
0x4d2c37  c7442460ffffffff                 mov    DWORD PTR [esp+0x60],0xffffffff
0x4d2c3f  837c244808                       cmp    DWORD PTR [esp+0x48],0x8
0x4d2c44  720d                             jb     0x4d2c53
0x4d2c46  8b442434                         mov    eax,DWORD PTR [esp+0x34]
0x4d2c4a  50                               push   eax
0x4d2c4b  e8bce53b00                       call   0x89120c
0x4d2c50  83c404                           add    esp,0x4
0x4d2c53  8b7c2424                         mov    edi,DWORD PTR [esp+0x24]
0x4d2c57  33c9                             xor    ecx,ecx
0x4d2c59  c744244807000000                 mov    DWORD PTR [esp+0x48],0x7
0x4d2c61  c744244400000000                 mov    DWORD PTR [esp+0x44],0x0
0x4d2c69  66894c2434                       mov    WORD PTR [esp+0x34],cx
0x4d2c6e  33f6                             xor    esi,esi
0x4d2c70  8b9b20040000                     mov    ebx,DWORD PTR [ebx+0x420]
0x4d2c76  3bde                             cmp    ebx,esi
0x4d2c78  740d                             je     0x4d2c87
0x4d2c7a  8b5b24                           mov    ebx,DWORD PTR [ebx+0x24]
0x4d2c7d  3bde                             cmp    ebx,esi
0x4d2c7f  7406                             je     0x4d2c87
0x4d2c81  53                               push   ebx
0x4d2c82  e8b9b22e00                       call   0x7bdf40
0x4d2c87  8bc7                             mov    eax,edi
0x4d2c89  8b4c2458                         mov    ecx,DWORD PTR [esp+0x58]
0x4d2c8d  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4d2c94  59                               pop    ecx
0x4d2c95  5f                               pop    edi
0x4d2c96  5e                               pop    esi
0x4d2c97  5b                               pop    ebx
0x4d2c98  8b4c2440                         mov    ecx,DWORD PTR [esp+0x40]
0x4d2c9c  33cc                             xor    ecx,esp
0x4d2c9e  e85ee33b00                       call   0x891001
0x4d2ca3  8be5                             mov    esp,ebp
0x4d2ca5  5d                               pop    ebp
0x4d2ca6  c3                               ret
0x4d2ca7  cc                               int3
0x4d2ca8  cc                               int3
0x4d2ca9  cc                               int3
0x4d2caa  cc                               int3
0x4d2cab  cc                               int3
0x4d2cac  cc                               int3
0x4d2cad  cc                               int3
0x4d2cae  cc                               int3
0x4d2caf  cc                               int3

; world_animate | drain completed model jobs and schedule the same world tree actors
; VA 0x4e0200..0x4e0520 raw 0xdf600 length 800 sha256 a20cf336a2329aeeae8bb865c1c939834e90445d76233089dafc853267b89930
0x4e0200  55                               push   ebp
0x4e0201  8bec                             mov    ebp,esp
0x4e0203  6aff                             push   0xffffffff
0x4e0205  68c4439400                       push   0x9443c4
0x4e020a  64a100000000                     mov    eax,fs:0x0
0x4e0210  50                               push   eax
0x4e0211  83ec0c                           sub    esp,0xc
0x4e0214  53                               push   ebx
0x4e0215  56                               push   esi
0x4e0216  57                               push   edi
0x4e0217  a1201fd600                       mov    eax,ds:0xd61f20
0x4e021c  33c5                             xor    eax,ebp
0x4e021e  50                               push   eax
0x4e021f  8d45f4                           lea    eax,[ebp-0xc]
0x4e0222  64a300000000                     mov    fs:0x0,eax
0x4e0228  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
0x4e022f  be01000000                       mov    esi,0x1
0x4e0234  7527                             jne    0x4e025d
0x4e0236  0935600ffc00                     or     DWORD PTR ds:0xfc0f60,esi
0x4e023c  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4e0243  e8f8cc2b00                       call   0x79cf40
0x4e0248  6880dbbc00                       push   0xbcdb80
0x4e024d  e8c8203b00                       call   0x89231a
0x4e0252  83c404                           add    esp,0x4
0x4e0255  83cfff                           or     edi,0xffffffff
0x4e0258  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4e025b  eb03                             jmp    0x4e0260
0x4e025d  83cfff                           or     edi,0xffffffff
0x4e0260  b9900efc00                       mov    ecx,0xfc0e90
0x4e0265  e8a6d82b00                       call   0x79db10
0x4e026a  d9450c                           fld    DWORD PTR [ebp+0xc]
0x4e026d  8b0d38a8fb00                     mov    ecx,DWORD PTR ds:0xfba838
0x4e0273  8b01                             mov    eax,DWORD PTR [ecx]
0x4e0275  8b5018                           mov    edx,DWORD PTR [eax+0x18]
0x4e0278  51                               push   ecx
0x4e0279  d91c24                           fstp   DWORD PTR [esp]
0x4e027c  ffd2                             call   edx
0x4e027e  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
0x4e0283  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4e0286  0f57c9                           xorps  xmm1,xmm1
0x4e0289  f30f1145f0                       movss  DWORD PTR [ebp-0x10],xmm0
0x4e028e  f30f1083ac000000                 movss  xmm0,DWORD PTR [ebx+0xac]
0x4e0296  0f2fc1                           comiss xmm0,xmm1
0x4e0299  f30f1145ec                       movss  DWORD PTR [ebp-0x14],xmm0
0x4e029e  7709                             ja     0x4e02a9
0x4e02a0  83bbb000000000                   cmp    DWORD PTR [ebx+0xb0],0x0
0x4e02a7  742d                             je     0x4e02d6
0x4e02a9  d9450c                           fld    DWORD PTR [ebp+0xc]
0x4e02ac  dd059058c500                     fld    QWORD PTR ds:0xc55890
0x4e02b2  d8c9                             fmul   st,st(1)
0x4e02b4  d95df0                           fstp   DWORD PTR [ebp-0x10]
0x4e02b7  d86dec                           fsubr  DWORD PTR [ebp-0x14]
0x4e02ba  d95dec                           fstp   DWORD PTR [ebp-0x14]
0x4e02bd  d945ec                           fld    DWORD PTR [ebp-0x14]
0x4e02c0  d993ac000000                     fst    DWORD PTR [ebx+0xac]
0x4e02c6  d9ee                             fldz
0x4e02c8  dff1                             fcomip st,st(1)
0x4e02ca  ddd8                             fstp   st(0)
0x4e02cc  7208                             jb     0x4e02d6
0x4e02ce  f30f118bac000000                 movss  DWORD PTR [ebx+0xac],xmm1
0x4e02d6  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x4e02dd  f30f1045f0                       movss  xmm0,DWORD PTR [ebp-0x10]
0x4e02e2  c745e82ccfc000                   mov    DWORD PTR [ebp-0x18],0xc0cf2c
0x4e02e9  f30f1145ec                       movss  DWORD PTR [ebp-0x14],xmm0
0x4e02ee  751e                             jne    0x4e030e
0x4e02f0  0935e879fb00                     or     DWORD PTR ds:0xfb79e8,esi
0x4e02f6  8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x4e02f9  e8e28a2b00                       call   0x798de0
0x4e02fe  68e0d2bc00                       push   0xbcd2e0
0x4e0303  e812203b00                       call   0x89231a
0x4e0308  83c404                           add    esp,0x4
0x4e030b  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4e030e  8d45e8                           lea    eax,[ebp-0x18]
0x4e0311  a3e479fb00                       mov    ds:0xfb79e4,eax
0x4e0316  8b430c                           mov    eax,DWORD PTR [ebx+0xc]
0x4e0319  8b30                             mov    esi,DWORD PTR [eax]
0x4e031b  3bf0                             cmp    esi,eax
0x4e031d  0f84ed000000                     je     0x4e0410
0x4e0323  bb02000000                       mov    ebx,0x2
0x4e0328  eb06                             jmp    0x4e0330
0x4e032a  8d9b00000000                     lea    ebx,[ebx+0x0]
0x4e0330  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x4e0337  751f                             jne    0x4e0358
0x4e0339  830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
0x4e0340  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4e0343  e8988a2b00                       call   0x798de0
0x4e0348  68e0d2bc00                       push   0xbcd2e0
0x4e034d  e8c81f3b00                       call   0x89231a
0x4e0352  83c404                           add    esp,0x4
0x4e0355  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4e0358  8b0de079fb00                     mov    ecx,DWORD PTR ds:0xfb79e0
0x4e035e  8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x4e0361  8b15d079fb00                     mov    edx,DWORD PTR ds:0xfb79d0
0x4e0367  8d0c49                           lea    ecx,[ecx+ecx*2]
0x4e036a  89448a08                         mov    DWORD PTR [edx+ecx*4+0x8],eax
0x4e036e  a1e079fb00                       mov    eax,ds:0xfb79e0
0x4e0373  0fb60dad79fb00                   movzx  ecx,BYTE PTR ds:0xfb79ad
0x4e037a  40                               inc    eax
0x4e037b  a3e079fb00                       mov    ds:0xfb79e0,eax
0x4e0380  3bc1                             cmp    eax,ecx
0x4e0382  7539                             jne    0x4e03bd
0x4e0384  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x4e038b  7523                             jne    0x4e03b0
0x4e038d  830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
0x4e0394  c745fc03000000                   mov    DWORD PTR [ebp-0x4],0x3
0x4e039b  e8408a2b00                       call   0x798de0
0x4e03a0  68e0d2bc00                       push   0xbcd2e0
0x4e03a5  e8701f3b00                       call   0x89231a
0x4e03aa  83c404                           add    esp,0x4
0x4e03ad  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4e03b0  bfac79fb00                       mov    edi,0xfb79ac
0x4e03b5  e836e12000                       call   0x6ee4f0
0x4e03ba  83cfff                           or     edi,0xffffffff
0x4e03bd  807e1500                         cmp    BYTE PTR [esi+0x15],0x0
0x4e03c1  753f                             jne    0x4e0402
0x4e03c3  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x4e03c6  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e03ca  7516                             jne    0x4e03e2
0x4e03cc  8bf0                             mov    esi,eax
0x4e03ce  8b06                             mov    eax,DWORD PTR [esi]
0x4e03d0  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e03d4  752c                             jne    0x4e0402
0x4e03d6  8bf0                             mov    esi,eax
0x4e03d8  8b06                             mov    eax,DWORD PTR [esi]
0x4e03da  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e03de  74f6                             je     0x4e03d6
0x4e03e0  eb20                             jmp    0x4e0402
0x4e03e2  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x4e03e5  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e03e9  7515                             jne    0x4e0400
0x4e03eb  eb03                             jmp    0x4e03f0
0x4e03ed  8d4900                           lea    ecx,[ecx+0x0]
0x4e03f0  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x4e03f3  750b                             jne    0x4e0400
0x4e03f5  8bf0                             mov    esi,eax
0x4e03f7  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x4e03fa  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e03fe  74f0                             je     0x4e03f0
0x4e0400  8bf0                             mov    esi,eax
0x4e0402  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x4e0405  3b720c                           cmp    esi,DWORD PTR [edx+0xc]
0x4e0408  0f8522ffffff                     jne    0x4e0330
0x4e040e  8bda                             mov    ebx,edx
0x4e0410  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x4e0417  7523                             jne    0x4e043c
0x4e0419  830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
0x4e0420  c745fc04000000                   mov    DWORD PTR [ebp-0x4],0x4
0x4e0427  e8b4892b00                       call   0x798de0
0x4e042c  68e0d2bc00                       push   0xbcd2e0
0x4e0431  e8e41e3b00                       call   0x89231a
0x4e0436  83c404                           add    esp,0x4
0x4e0439  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4e043c  a1e079fb00                       mov    eax,ds:0xfb79e0
0x4e0441  85c0                             test   eax,eax
0x4e0443  7438                             je     0x4e047d
0x4e0445  33f6                             xor    esi,esi
0x4e0447  85c0                             test   eax,eax
0x4e0449  7421                             je     0x4e046c
0x4e044b  8b3dd020bd00                     mov    edi,DWORD PTR ds:0xbd20d0
0x4e0451  a1b079fb00                       mov    eax,ds:0xfb79b0
0x4e0456  8b0cb0                           mov    ecx,DWORD PTR [eax+esi*4]
0x4e0459  51                               push   ecx
0x4e045a  ffd7                             call   edi
0x4e045c  a1e079fb00                       mov    eax,ds:0xfb79e0
0x4e0461  46                               inc    esi
0x4e0462  3bf0                             cmp    esi,eax
0x4e0464  72eb                             jb     0x4e0451
0x4e0466  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4e0469  83cfff                           or     edi,0xffffffff
0x4e046c  8b15c079fb00                     mov    edx,DWORD PTR ds:0xfb79c0
0x4e0472  57                               push   edi
0x4e0473  6a01                             push   0x1
0x4e0475  52                               push   edx
0x4e0476  50                               push   eax
0x4e0477  ff15b422bd00                     call   DWORD PTR ds:0xbd22b4
0x4e047d  33c0                             xor    eax,eax
0x4e047f  f60500b1fa0001                   test   BYTE PTR ds:0xfab100,0x1
0x4e0486  a3e079fb00                       mov    ds:0xfb79e0,eax
0x4e048b  a3e479fb00                       mov    ds:0xfb79e4,eax
0x4e0490  7523                             jne    0x4e04b5
0x4e0492  830d00b1fa0001                   or     DWORD PTR ds:0xfab100,0x1
0x4e0499  c745fc05000000                   mov    DWORD PTR [ebp-0x4],0x5
0x4e04a0  e8fbd1fbff                       call   0x49d6a0
0x4e04a5  6820cebc00                       push   0xbcce20
0x4e04aa  e86b1e3b00                       call   0x89231a
0x4e04af  83c404                           add    esp,0x4
0x4e04b2  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4e04b5  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4e04bb  8b01                             mov    eax,DWORD PTR [ecx]
0x4e04bd  8b5020                           mov    edx,DWORD PTR [eax+0x20]
0x4e04c0  ffd2                             call   edx
0x4e04c2  85c0                             test   eax,eax
0x4e04c4  742c                             je     0x4e04f2
0x4e04c6  a1a4a7fb00                       mov    eax,ds:0xfba7a4
0x4e04cb  83787c00                         cmp    DWORD PTR [eax+0x7c],0x0
0x4e04cf  7521                             jne    0x4e04f2
0x4e04d1  a11813fb00                       mov    eax,ds:0xfb1318
0x4e04d6  8b881cc00000                     mov    ecx,DWORD PTR [eax+0xc01c]
0x4e04dc  d1e9                             shr    ecx,1
0x4e04de  f6c101                           test   cl,0x1
0x4e04e1  750f                             jne    0x4e04f2
0x4e04e3  f6801cc0000001                   test   BYTE PTR [eax+0xc01c],0x1
0x4e04ea  7506                             jne    0x4e04f2
0x4e04ec  53                               push   ebx
0x4e04ed  e8de010000                       call   0x4e06d0
0x4e04f2  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4e04f8  d9450c                           fld    DWORD PTR [ebp+0xc]
0x4e04fb  8b11                             mov    edx,DWORD PTR [ecx]
0x4e04fd  8b4230                           mov    eax,DWORD PTR [edx+0x30]
0x4e0500  51                               push   ecx
0x4e0501  d91c24                           fstp   DWORD PTR [esp]
0x4e0504  ffd0                             call   eax
0x4e0506  33c0                             xor    eax,eax
0x4e0508  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4e050b  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4e0512  59                               pop    ecx
0x4e0513  5f                               pop    edi
0x4e0514  5e                               pop    esi
0x4e0515  5b                               pop    ebx
0x4e0516  8be5                             mov    esp,ebp
0x4e0518  5d                               pop    ebp
0x4e0519  c20800                           ret    0x8
0x4e051c  cc                               int3
0x4e051d  cc                               int3
0x4e051e  cc                               int3
0x4e051f  cc                               int3

; world_animate_executor | typed functor calls actor v+24 with frame delta
; VA 0x4e0520..0x4e0540 raw 0xdf920 length 32 sha256 7ed56c805e2c65867fe0c091de9887d9a6313de14a67a495f0567485ef6dc499
0x4e0520  55                               push   ebp
0x4e0521  8bec                             mov    ebp,esp
0x4e0523  8bc1                             mov    eax,ecx
0x4e0525  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4e0528  d94004                           fld    DWORD PTR [eax+0x4]
0x4e052b  8b11                             mov    edx,DWORD PTR [ecx]
0x4e052d  8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x4e0530  51                               push   ecx
0x4e0531  d91c24                           fstp   DWORD PTR [esp]
0x4e0534  ffd0                             call   eax
0x4e0536  b801000000                       mov    eax,0x1
0x4e053b  5d                               pop    ebp
0x4e053c  c20400                           ret    0x4
0x4e053f  cc                               int3

; world_draw | world draw path calls world tree draw iterator
; VA 0x4e0540..0x4e0590 raw 0xdf940 length 80 sha256 5ad1054b8808e07d105bc658c6a9fdc5873054438280a2912ff8550ad9d67745
0x4e0540  55                               push   ebp
0x4e0541  8bec                             mov    ebp,esp
0x4e0543  51                               push   ecx
0x4e0544  8b0d38a8fb00                     mov    ecx,DWORD PTR ds:0xfba838
0x4e054a  8b01                             mov    eax,DWORD PTR [ecx]
0x4e054c  8b501c                           mov    edx,DWORD PTR [eax+0x1c]
0x4e054f  ffd2                             call   edx
0x4e0551  83bea800000000                   cmp    DWORD PTR [esi+0xa8],0x0
0x4e0558  7524                             jne    0x4e057e
0x4e055a  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4e0560  8b01                             mov    eax,DWORD PTR [ecx]
0x4e0562  8b5034                           mov    edx,DWORD PTR [eax+0x34]
0x4e0565  ffd2                             call   edx
0x4e0567  8b460c                           mov    eax,DWORD PTR [esi+0xc]
0x4e056a  8b08                             mov    ecx,DWORD PTR [eax]
0x4e056c  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x4e0570  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x4e0573  52                               push   edx
0x4e0574  50                               push   eax
0x4e0575  51                               push   ecx
0x4e0576  e8f50e0000                       call   0x4e1470
0x4e057b  83c40c                           add    esp,0xc
0x4e057e  33c0                             xor    eax,eax
0x4e0580  8be5                             mov    esp,ebp
0x4e0582  5d                               pop    ebp
0x4e0583  c3                               ret
0x4e0584  cc                               int3
0x4e0585  cc                               int3
0x4e0586  cc                               int3
0x4e0587  cc                               int3
0x4e0588  cc                               int3
0x4e0589  cc                               int3
0x4e058a  cc                               int3
0x4e058b  cc                               int3
0x4e058c  cc                               int3
0x4e058d  cc                               int3
0x4e058e  cc                               int3
0x4e058f  cc                               int3

; world_draw_iterator | world tree node+10 actor v+28
; VA 0x4e1470..0x4e14f0 raw 0xe0870 length 128 sha256 59b56d4e5fa80e3dd68f9bb2ffb49a135709dac8c135d5e7d4a9cd647b4709fa
0x4e1470  55                               push   ebp
0x4e1471  8bec                             mov    ebp,esp
0x4e1473  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4e1476  3b4d0c                           cmp    ecx,DWORD PTR [ebp+0xc]
0x4e1479  7462                             je     0x4e14dd
0x4e147b  eb03                             jmp    0x4e1480
0x4e147d  8d4900                           lea    ecx,[ecx+0x0]
0x4e1480  8b4910                           mov    ecx,DWORD PTR [ecx+0x10]
0x4e1483  8b01                             mov    eax,DWORD PTR [ecx]
0x4e1485  8b5028                           mov    edx,DWORD PTR [eax+0x28]
0x4e1488  ffd2                             call   edx
0x4e148a  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4e148d  80791500                         cmp    BYTE PTR [ecx+0x15],0x0
0x4e1491  7545                             jne    0x4e14d8
0x4e1493  8b4108                           mov    eax,DWORD PTR [ecx+0x8]
0x4e1496  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e149a  7516                             jne    0x4e14b2
0x4e149c  8bc8                             mov    ecx,eax
0x4e149e  8b01                             mov    eax,DWORD PTR [ecx]
0x4e14a0  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e14a4  752f                             jne    0x4e14d5
0x4e14a6  8bc8                             mov    ecx,eax
0x4e14a8  8b01                             mov    eax,DWORD PTR [ecx]
0x4e14aa  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e14ae  74f6                             je     0x4e14a6
0x4e14b0  eb23                             jmp    0x4e14d5
0x4e14b2  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x4e14b5  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e14b9  7518                             jne    0x4e14d3
0x4e14bb  eb03                             jmp    0x4e14c0
0x4e14bd  8d4900                           lea    ecx,[ecx+0x0]
0x4e14c0  3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
0x4e14c3  750e                             jne    0x4e14d3
0x4e14c5  8bc8                             mov    ecx,eax
0x4e14c7  894d08                           mov    DWORD PTR [ebp+0x8],ecx
0x4e14ca  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x4e14cd  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4e14d1  74ed                             je     0x4e14c0
0x4e14d3  8bc8                             mov    ecx,eax
0x4e14d5  894d08                           mov    DWORD PTR [ebp+0x8],ecx
0x4e14d8  3b4d0c                           cmp    ecx,DWORD PTR [ebp+0xc]
0x4e14db  75a3                             jne    0x4e1480
0x4e14dd  8a4510                           mov    al,BYTE PTR [ebp+0x10]
0x4e14e0  5d                               pop    ebp
0x4e14e1  c3                               ret
0x4e14e2  cc                               int3
0x4e14e3  cc                               int3
0x4e14e4  cc                               int3
0x4e14e5  cc                               int3
0x4e14e6  cc                               int3
0x4e14e7  cc                               int3
0x4e14e8  cc                               int3
0x4e14e9  cc                               int3
0x4e14ea  cc                               int3
0x4e14eb  cc                               int3
0x4e14ec  cc                               int3
0x4e14ed  cc                               int3
0x4e14ee  cc                               int3
0x4e14ef  cc                               int3

; actor_pool_worker | pool+38 executor receives slot actor pointer
; VA 0x6ee540..0x6ee5a0 raw 0x2ed940 length 96 sha256 e7027c1a4e248af75a48a73bfe3bccbd5e355d8845d0b5a672bc69f0ca41f504
0x6ee540  55                               push   ebp
0x6ee541  8bec                             mov    ebp,esp
0x6ee543  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x6ee546  56                               push   esi
0x6ee547  8b30                             mov    esi,DWORD PTR [eax]
0x6ee549  803e00                           cmp    BYTE PTR [esi],0x0
0x6ee54c  57                               push   edi
0x6ee54d  8b7804                           mov    edi,DWORD PTR [eax+0x4]
0x6ee550  7541                             jne    0x6ee593
0x6ee552  53                               push   ebx
0x6ee553  8d1c7f                           lea    ebx,[edi+edi*2]
0x6ee556  03db                             add    ebx,ebx
0x6ee558  03db                             add    ebx,ebx
0x6ee55a  8d9b00000000                     lea    ebx,[ebx+0x0]
0x6ee560  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x6ee563  8b0cb8                           mov    ecx,DWORD PTR [eax+edi*4]
0x6ee566  6aff                             push   0xffffffff
0x6ee568  51                               push   ecx
0x6ee569  ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
0x6ee56f  8b4e38                           mov    ecx,DWORD PTR [esi+0x38]
0x6ee572  8b4624                           mov    eax,DWORD PTR [esi+0x24]
0x6ee575  8b11                             mov    edx,DWORD PTR [ecx]
0x6ee577  8b440308                         mov    eax,DWORD PTR [ebx+eax*1+0x8]
0x6ee57b  8b12                             mov    edx,DWORD PTR [edx]
0x6ee57d  50                               push   eax
0x6ee57e  ffd2                             call   edx
0x6ee580  8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x6ee583  8b0cb8                           mov    ecx,DWORD PTR [eax+edi*4]
0x6ee586  51                               push   ecx
0x6ee587  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0x6ee58d  803e00                           cmp    BYTE PTR [esi],0x0
0x6ee590  74ce                             je     0x6ee560
0x6ee592  5b                               pop    ebx
0x6ee593  5f                               pop    edi
0x6ee594  5e                               pop    esi
0x6ee595  5d                               pop    ebp
0x6ee596  e9d7761a00                       jmp    0x895c72
0x6ee59b  cc                               int3
0x6ee59c  cc                               int3
0x6ee59d  cc                               int3
0x6ee59e  cc                               int3
0x6ee59f  cc                               int3

; lb_create_wrapper | four arguments -> Ex(model,x,y,12,0,attach)
; VA 0x4a0b40..0x4a0b68 raw 0x9ff40 length 40 sha256 379aaceabe0cd997813c8874382aec5978d8c9ff7db9082ce2e1ec200ca86a0c
0x4a0b40  55                               push   ebp
0x4a0b41  8bec                             mov    ebp,esp
0x4a0b43  8b4514                           mov    eax,DWORD PTR [ebp+0x14]
0x4a0b46  d94510                           fld    DWORD PTR [ebp+0x10]
0x4a0b49  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x4a0b4c  50                               push   eax
0x4a0b4d  6a00                             push   0x0
0x4a0b4f  6a0c                             push   0xc
0x4a0b51  83ec08                           sub    esp,0x8
0x4a0b54  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4a0b58  d9450c                           fld    DWORD PTR [ebp+0xc]
0x4a0b5b  d91c24                           fstp   DWORD PTR [esp]
0x4a0b5e  52                               push   edx
0x4a0b5f  e80c040000                       call   0x4a0f70
0x4a0b64  5d                               pop    ebp
0x4a0b65  c21000                           ret    0x10

; doll_ctor_prefix | CDoll vptr/model key/dirty initialization
; VA 0x7a4c50..0x7a4cd0 raw 0x3a4050 length 128 sha256 673867fb2ab856074da0a6ecce3f5c71126a837d11f165b236363c0129531c8c
0x7a4c50  55                               push   ebp
0x7a4c51  8bec                             mov    ebp,esp
0x7a4c53  6aff                             push   0xffffffff
0x7a4c55  6863799000                       push   0x907963
0x7a4c5a  64a100000000                     mov    eax,fs:0x0
0x7a4c60  50                               push   eax
0x7a4c61  83ec1c                           sub    esp,0x1c
0x7a4c64  53                               push   ebx
0x7a4c65  56                               push   esi
0x7a4c66  a1201fd600                       mov    eax,ds:0xd61f20
0x7a4c6b  33c5                             xor    eax,ebp
0x7a4c6d  50                               push   eax
0x7a4c6e  8d45f4                           lea    eax,[ebp-0xc]
0x7a4c71  64a300000000                     mov    fs:0x0,eax
0x7a4c77  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x7a4c7a  33db                             xor    ebx,ebx
0x7a4c7c  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x7a4c7f  c746044cf6c400                   mov    DWORD PTR [esi+0x4],0xc4f64c
0x7a4c86  c7460878f8c000                   mov    DWORD PTR [esi+0x8],0xc0f878
0x7a4c8d  c7460c6cf6c400                   mov    DWORD PTR [esi+0xc],0xc4f66c
0x7a4c94  895e10                           mov    DWORD PTR [esi+0x10],ebx
0x7a4c97  895e14                           mov    DWORD PTR [esi+0x14],ebx
0x7a4c9a  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x7a4c9e  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x7a4ca1  8d4e2c                           lea    ecx,[esi+0x2c]
0x7a4ca4  51                               push   ecx
0x7a4ca5  c7067cf6c400                     mov    DWORD PTR [esi],0xc4f67c
0x7a4cab  c7460490f6c400                   mov    DWORD PTR [esi+0x4],0xc4f690
0x7a4cb2  c74608b0f6c400                   mov    DWORD PTR [esi+0x8],0xc4f6b0
0x7a4cb9  c7460cc0f6c400                   mov    DWORD PTR [esi+0xc],0xc4f6c0
0x7a4cc0  894618                           mov    DWORD PTR [esi+0x18],eax
0x7a4cc3  895e1c                           mov    DWORD PTR [esi+0x1c],ebx
0x7a4cc6  885e20                           mov    BYTE PTR [esi+0x20],bl
0x7a4cc9  895e24                           mov    DWORD PTR [esi+0x24],ebx
0x7a4ccc  c6462801                         mov    BYTE PTR [esi+0x28],0x1

; doll_tick_dirty | dirty and load-state gate -> enqueue
; VA 0x7a5c50..0x7a5cc0 raw 0x3a5050 length 112 sha256 fd64d1e7b7d64208dbfef2bd620f3021e1bf62fd1b7d565b5864aa3615477cba
0x7a5c50  55                               push   ebp
0x7a5c51  8bec                             mov    ebp,esp
0x7a5c53  83e4f8                           and    esp,0xfffffff8
0x7a5c56  6aff                             push   0xffffffff
0x7a5c58  688ea09300                       push   0x93a08e
0x7a5c5d  64a100000000                     mov    eax,fs:0x0
0x7a5c63  50                               push   eax
0x7a5c64  81ecb0000000                     sub    esp,0xb0
0x7a5c6a  a1201fd600                       mov    eax,ds:0xd61f20
0x7a5c6f  33c4                             xor    eax,esp
0x7a5c71  898424a8000000                   mov    DWORD PTR [esp+0xa8],eax
0x7a5c78  53                               push   ebx
0x7a5c79  56                               push   esi
0x7a5c7a  57                               push   edi
0x7a5c7b  a1201fd600                       mov    eax,ds:0xd61f20
0x7a5c80  33c4                             xor    eax,esp
0x7a5c82  50                               push   eax
0x7a5c83  8d8424c0000000                   lea    eax,[esp+0xc0]
0x7a5c8a  64a300000000                     mov    fs:0x0,eax
0x7a5c90  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a5c93  807b2800                         cmp    BYTE PTR [ebx+0x28],0x0
0x7a5c97  7413                             je     0x7a5cac
0x7a5c99  8b4324                           mov    eax,DWORD PTR [ebx+0x24]
0x7a5c9c  83f802                           cmp    eax,0x2
0x7a5c9f  740b                             je     0x7a5cac
0x7a5ca1  83f803                           cmp    eax,0x3
0x7a5ca4  7406                             je     0x7a5cac
0x7a5ca6  53                               push   ebx
0x7a5ca7  e8c4310000                       call   0x7a8e70
0x7a5cac  33f6                             xor    esi,esi
0x7a5cae  39731c                           cmp    DWORD PTR [ebx+0x1c],esi
0x7a5cb1  0f8458060000                     je     0x7a630f
0x7a5cb7  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x7a5cba  d983b4000000                     fld    DWORD PTR [ebx+0xb4]

; doll_tick_motion_face | animation rate and face update consumers
; VA 0x7a5d8b..0x7a5ed1 raw 0x3a518b length 326 sha256 9a69f7049a3a39ebe903296c72a61fee13e5a30d6ae2434307f5fdba14731289
0x7a5d8b  89b340010000                     mov    DWORD PTR [ebx+0x140],esi
0x7a5d91  eb06                             jmp    0x7a5d99
0x7a5d93  01bb40010000                     add    DWORD PTR [ebx+0x140],edi
0x7a5d99  397510                           cmp    DWORD PTR [ebp+0x10],esi
0x7a5d9c  7406                             je     0x7a5da4
0x7a5d9e  89bb24010000                     mov    DWORD PTR [ebx+0x124],edi
0x7a5da4  d98304010000                     fld    DWORD PTR [ebx+0x104]
0x7a5daa  51                               push   ecx
0x7a5dab  d84d0c                           fmul   DWORD PTR [ebp+0xc]
0x7a5dae  d95c2414                         fstp   DWORD PTR [esp+0x14]
0x7a5db2  d9442414                         fld    DWORD PTR [esp+0x14]
0x7a5db6  d91c24                           fstp   DWORD PTR [esp]
0x7a5db9  53                               push   ebx
0x7a5dba  e8f1280000                       call   0x7a86b0
0x7a5dbf  39b3ac000000                     cmp    DWORD PTR [ebx+0xac],esi
0x7a5dc5  7417                             je     0x7a5dde
0x7a5dc7  d944242c                         fld    DWORD PTR [esp+0x2c]
0x7a5dcb  83ec08                           sub    esp,0x8
0x7a5dce  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x7a5dd2  d9450c                           fld    DWORD PTR [ebp+0xc]
0x7a5dd5  d91c24                           fstp   DWORD PTR [esp]
0x7a5dd8  53                               push   ebx
0x7a5dd9  e8f2290000                       call   0x7a87d0
0x7a5dde  d9ee                             fldz
0x7a5de0  39b324010000                     cmp    DWORD PTR [ebx+0x124],esi
0x7a5de6  750d                             jne    0x7a5df5
0x7a5de8  83bb400100000a                   cmp    DWORD PTR [ebx+0x140],0xa
0x7a5def  0f86b6000000                     jbe    0x7a5eab
0x7a5df5  39b300010000                     cmp    DWORD PTR [ebx+0x100],esi
0x7a5dfb  0f8497000000                     je     0x7a5e98
0x7a5e01  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
0x7a5e04  8b93ec000000                     mov    edx,DWORD PTR [ebx+0xec]
0x7a5e0a  895028                           mov    DWORD PTR [eax+0x28],edx
0x7a5e0d  8b8bf0000000                     mov    ecx,DWORD PTR [ebx+0xf0]
0x7a5e13  89482c                           mov    DWORD PTR [eax+0x2c],ecx
0x7a5e16  8b93f4000000                     mov    edx,DWORD PTR [ebx+0xf4]
0x7a5e1c  895030                           mov    DWORD PTR [eax+0x30],edx
0x7a5e1f  8b8bec000000                     mov    ecx,DWORD PTR [ebx+0xec]
0x7a5e25  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x7a5e28  894868                           mov    DWORD PTR [eax+0x68],ecx
0x7a5e2b  8b93f0000000                     mov    edx,DWORD PTR [ebx+0xf0]
0x7a5e31  89506c                           mov    DWORD PTR [eax+0x6c],edx
0x7a5e34  8b8bf4000000                     mov    ecx,DWORD PTR [ebx+0xf4]
0x7a5e3a  894870                           mov    DWORD PTR [eax+0x70],ecx
0x7a5e3d  89b0c0000000                     mov    DWORD PTR [eax+0xc0],esi
0x7a5e43  d983fc000000                     fld    DWORD PTR [ebx+0xfc]
0x7a5e49  8b7b1c                           mov    edi,DWORD PTR [ebx+0x1c]
0x7a5e4c  d95c2410                         fstp   DWORD PTR [esp+0x10]
0x7a5e50  8d542420                         lea    edx,[esp+0x20]
0x7a5e54  d9542420                         fst    DWORD PTR [esp+0x20]
0x7a5e58  52                               push   edx
0x7a5e59  d95c2428                         fstp   DWORD PTR [esp+0x28]
0x7a5e5d  d9442414                         fld    DWORD PTR [esp+0x14]
0x7a5e61  d95c242c                         fstp   DWORD PTR [esp+0x2c]
0x7a5e65  e8c6d10200                       call   0x7d3030
0x7a5e6a  d983f8000000                     fld    DWORD PTR [ebx+0xf8]
0x7a5e70  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
0x7a5e73  51                               push   ecx
0x7a5e74  d91c24                           fstp   DWORD PTR [esp]
0x7a5e77  e874d20200                       call   0x7d30f0
0x7a5e7c  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
0x7a5e7f  50                               push   eax
0x7a5e80  89b300010000                     mov    DWORD PTR [ebx+0x100],esi
0x7a5e86  bf01000000                       mov    edi,0x1
0x7a5e8b  e840dd0200                       call   0x7d3bd0
0x7a5e90  89b340010000                     mov    DWORD PTR [ebx+0x140],esi
0x7a5e96  eb15                             jmp    0x7a5ead
0x7a5e98  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
0x7a5e9b  ddd8                             fstp   st(0)
0x7a5e9d  50                               push   eax
0x7a5e9e  e82ddd0200                       call   0x7d3bd0
0x7a5ea3  89b340010000                     mov    DWORD PTR [ebx+0x140],esi
0x7a5ea9  eb02                             jmp    0x7a5ead
0x7a5eab  ddd8                             fstp   st(0)
0x7a5ead  8bb3a0000000                     mov    esi,DWORD PTR [ebx+0xa0]
0x7a5eb3  85f6                             test   esi,esi
0x7a5eb5  740c                             je     0x7a5ec3
0x7a5eb7  d9450c                           fld    DWORD PTR [ebp+0xc]
0x7a5eba  51                               push   ecx
0x7a5ebb  d91c24                           fstp   DWORD PTR [esp]
0x7a5ebe  e8dd060300                       call   0x7d65a0
0x7a5ec3  8b8b4c010000                     mov    ecx,DWORD PTR [ebx+0x14c]
0x7a5ec9  8b8350010000                     mov    eax,DWORD PTR [ebx+0x150]
0x7a5ecf  3bc8                             cmp    ecx,eax

; doll_draw_main | draw gate and current model / active attachment virtual draws
; VA 0x7a63c0..0x7a65a2 raw 0x3a57c0 length 482 sha256 a350132624dd2235c4ec3dc0505616e03cb334a626ec4b7985f272decccf48e8
0x7a63c0  55                               push   ebp
0x7a63c1  8bec                             mov    ebp,esp
0x7a63c3  6aff                             push   0xffffffff
0x7a63c5  6876bd9200                       push   0x92bd76
0x7a63ca  64a100000000                     mov    eax,fs:0x0
0x7a63d0  50                               push   eax
0x7a63d1  83ec18                           sub    esp,0x18
0x7a63d4  53                               push   ebx
0x7a63d5  56                               push   esi
0x7a63d6  57                               push   edi
0x7a63d7  a1201fd600                       mov    eax,ds:0xd61f20
0x7a63dc  33c5                             xor    eax,ebp
0x7a63de  50                               push   eax
0x7a63df  8d45f4                           lea    eax,[ebp-0xc]
0x7a63e2  64a300000000                     mov    fs:0x0,eax
0x7a63e8  8bf9                             mov    edi,ecx
0x7a63ea  897df0                           mov    DWORD PTR [ebp-0x10],edi
0x7a63ed  837f1c00                         cmp    DWORD PTR [edi+0x1c],0x0
0x7a63f1  0f8492020000                     je     0x7a6689
0x7a63f7  83bf2401000000                   cmp    DWORD PTR [edi+0x124],0x0
0x7a63fe  0f8485020000                     je     0x7a6689
0x7a6404  83bfac00000000                   cmp    DWORD PTR [edi+0xac],0x0
0x7a640b  be01000000                       mov    esi,0x1
0x7a6410  8bde                             mov    ebx,esi
0x7a6412  7413                             je     0x7a6427
0x7a6414  8b8fac000000                     mov    ecx,DWORD PTR [edi+0xac]
0x7a641a  8b01                             mov    eax,DWORD PTR [ecx]
0x7a641c  8b502c                           mov    edx,DWORD PTR [eax+0x2c]
0x7a641f  ffd2                             call   edx
0x7a6421  85c0                             test   eax,eax
0x7a6423  7502                             jne    0x7a6427
0x7a6425  33db                             xor    ebx,ebx
0x7a6427  8b4f70                           mov    ecx,DWORD PTR [edi+0x70]
0x7a642a  8b01                             mov    eax,DWORD PTR [ecx]
0x7a642c  894de8                           mov    DWORD PTR [ebp-0x18],ecx
0x7a642f  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x7a6432  3bc1                             cmp    eax,ecx
0x7a6434  744d                             je     0x7a6483
0x7a6436  8b7018                           mov    esi,DWORD PTR [eax+0x18]
0x7a6439  8b461c                           mov    eax,DWORD PTR [esi+0x1c]
0x7a643c  2b4618                           sub    eax,DWORD PTR [esi+0x18]
0x7a643f  33ff                             xor    edi,edi
0x7a6441  c1f802                           sar    eax,0x2
0x7a6444  85c0                             test   eax,eax
0x7a6446  7423                             je     0x7a646b
0x7a6448  8b4e18                           mov    ecx,DWORD PTR [esi+0x18]
0x7a644b  8b0cb9                           mov    ecx,DWORD PTR [ecx+edi*4]
0x7a644e  8b11                             mov    edx,DWORD PTR [ecx]
0x7a6450  8b4230                           mov    eax,DWORD PTR [edx+0x30]
0x7a6453  ffd0                             call   eax
0x7a6455  85c0                             test   eax,eax
0x7a6457  7410                             je     0x7a6469
0x7a6459  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
0x7a645c  2b4e18                           sub    ecx,DWORD PTR [esi+0x18]
0x7a645f  47                               inc    edi
0x7a6460  c1f902                           sar    ecx,0x2
0x7a6463  3bf9                             cmp    edi,ecx
0x7a6465  72e1                             jb     0x7a6448
0x7a6467  eb02                             jmp    0x7a646b
0x7a6469  33db                             xor    ebx,ebx
0x7a646b  8d45ec                           lea    eax,[ebp-0x14]
0x7a646e  e8cd7d0b00                       call   0x85e240
0x7a6473  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
0x7a6476  3b45e8                           cmp    eax,DWORD PTR [ebp-0x18]
0x7a6479  75bb                             jne    0x7a6436
0x7a647b  8b7df0                           mov    edi,DWORD PTR [ebp-0x10]
0x7a647e  be01000000                       mov    esi,0x1
0x7a6483  85db                             test   ebx,ebx
0x7a6485  0f858d000000                     jne    0x7a6518
0x7a648b  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x7a6492  d987fc000000                     fld    DWORD PTR [edi+0xfc]
0x7a6498  d95ddc                           fstp   DWORD PTR [ebp-0x24]
0x7a649b  d9ee                             fldz
0x7a649d  d955e0                           fst    DWORD PTR [ebp-0x20]
0x7a64a0  d95de4                           fstp   DWORD PTR [ebp-0x1c]
0x7a64a3  7522                             jne    0x7a64c7
0x7a64a5  0935e879fb00                     or     DWORD PTR ds:0xfb79e8,esi
0x7a64ab  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x7a64ae  e82d29ffff                       call   0x798de0
0x7a64b3  68e0d2bc00                       push   0xbcd2e0
0x7a64b8  e85dbe0e00                       call   0x89231a
0x7a64bd  83c404                           add    esp,0x4
0x7a64c0  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x7a64c7  8b55dc                           mov    edx,DWORD PTR [ebp-0x24]
0x7a64ca  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
0x7a64cd  83ec0c                           sub    esp,0xc
0x7a64d0  8bc4                             mov    eax,esp
0x7a64d2  8910                             mov    DWORD PTR [eax],edx
0x7a64d4  8b55e4                           mov    edx,DWORD PTR [ebp-0x1c]
0x7a64d7  894804                           mov    DWORD PTR [eax+0x4],ecx
0x7a64da  895008                           mov    DWORD PTR [eax+0x8],edx
0x7a64dd  8b97ec000000                     mov    edx,DWORD PTR [edi+0xec]
0x7a64e3  8b87f4000000                     mov    eax,DWORD PTR [edi+0xf4]
0x7a64e9  83ec0c                           sub    esp,0xc
0x7a64ec  8bcc                             mov    ecx,esp
0x7a64ee  8911                             mov    DWORD PTR [ecx],edx
0x7a64f0  8b97f0000000                     mov    edx,DWORD PTR [edi+0xf0]
0x7a64f6  895104                           mov    DWORD PTR [ecx+0x4],edx
0x7a64f9  68a876fb00                       push   0xfb76a8
0x7a64fe  894108                           mov    DWORD PTR [ecx+0x8],eax
0x7a6501  e87a46ffff                       call   0x79ab80
0x7a6506  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7a6509  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a6510  59                               pop    ecx
0x7a6511  5f                               pop    edi
0x7a6512  5e                               pop    esi
0x7a6513  5b                               pop    ebx
0x7a6514  8be5                             mov    esp,ebp
0x7a6516  5d                               pop    ebp
0x7a6517  c3                               ret
0x7a6518  b8ecf5c400                       mov    eax,0xc4f5ec
0x7a651d  e88e1b0900                       call   0x8380b0
0x7a6522  8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x7a6525  f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x7a652c  7520                             jne    0x7a654e
0x7a652e  0935e879fb00                     or     DWORD PTR ds:0xfb79e8,esi
0x7a6534  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x7a6538  e8a328ffff                       call   0x798de0
0x7a653d  68e0d2bc00                       push   0xbcd2e0
0x7a6542  e8d3bd0e00                       call   0x89231a
0x7a6547  83c404                           add    esp,0x4
0x7a654a  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x7a654e  e8cd1c0000                       call   0x7a8220
0x7a6553  8b7df0                           mov    edi,DWORD PTR [ebp-0x10]
0x7a6556  8b4f1c                           mov    ecx,DWORD PTR [edi+0x1c]
0x7a6559  8b11                             mov    edx,DWORD PTR [ecx]
0x7a655b  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x7a655e  ffd0                             call   eax
0x7a6560  8b4770                           mov    eax,DWORD PTR [edi+0x70]
0x7a6563  8b30                             mov    esi,DWORD PTR [eax]
0x7a6565  8b5de8                           mov    ebx,DWORD PTR [ebp-0x18]
0x7a6568  3bf3                             cmp    esi,ebx
0x7a656a  7452                             je     0x7a65be
0x7a656c  8d642400                         lea    esp,[esp+0x0]
0x7a6570  8b4e18                           mov    ecx,DWORD PTR [esi+0x18]
0x7a6573  8b11                             mov    edx,DWORD PTR [ecx]
0x7a6575  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x7a6578  ffd0                             call   eax
0x7a657a  807e2100                         cmp    BYTE PTR [esi+0x21],0x0
0x7a657e  753a                             jne    0x7a65ba
0x7a6580  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x7a6583  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a6587  7516                             jne    0x7a659f
0x7a6589  8bf0                             mov    esi,eax
0x7a658b  8b06                             mov    eax,DWORD PTR [esi]
0x7a658d  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a6591  7527                             jne    0x7a65ba
0x7a6593  8bf0                             mov    esi,eax
0x7a6595  8b06                             mov    eax,DWORD PTR [esi]
0x7a6597  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x7a659b  74f6                             je     0x7a6593
0x7a659d  eb1b                             jmp    0x7a65ba
0x7a659f  8b4604                           mov    eax,DWORD PTR [esi+0x4]

; worker_queue_branch | worker takes the model update queue
; VA 0x79df4d..0x79dfee raw 0x39d34d length 161 sha256 0c2e61ad15debbcc9f08c284d8005087a19d5bdb51fc401c83767d01d215b515
0x79df4d  897c2444                         mov    DWORD PTR [esp+0x44],edi
0x79df51  897c2448                         mov    DWORD PTR [esp+0x48],edi
0x79df55  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x79df58  c68424a800000001                 mov    BYTE PTR [esp+0xa8],0x1
0x79df60  388bc0000000                     cmp    BYTE PTR [ebx+0xc0],cl
0x79df66  0f8506050000                     jne    0x79e472
0x79df6c  8d642400                         lea    esp,[esp+0x0]
0x79df70  8d7370                           lea    esi,[ebx+0x70]
0x79df73  56                               push   esi
0x79df74  ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x79df7a  8b4b28                           mov    ecx,DWORD PTR [ebx+0x28]
0x79df7d  3b4b2c                           cmp    ecx,DWORD PTR [ebx+0x2c]
0x79df80  753a                             jne    0x79dfbc
0x79df82  8b5338                           mov    edx,DWORD PTR [ebx+0x38]
0x79df85  3b533c                           cmp    edx,DWORD PTR [ebx+0x3c]
0x79df88  7532                             jne    0x79dfbc
0x79df8a  397b68                           cmp    DWORD PTR [ebx+0x68],edi
0x79df8d  752d                             jne    0x79dfbc
0x79df8f  56                               push   esi
0x79df90  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x79df96  80bbc800000000                   cmp    BYTE PTR [ebx+0xc8],0x0
0x79df9d  0f84b8040000                     je     0x79e45b
0x79dfa3  8b83cc000000                     mov    eax,DWORD PTR [ebx+0xcc]
0x79dfa9  50                               push   eax
0x79dfaa  c683c800000000                   mov    BYTE PTR [ebx+0xc8],0x0
0x79dfb1  ff15d020bd00                     call   DWORD PTR ds:0xbd20d0
0x79dfb7  e9a7040000                       jmp    0x79e463
0x79dfbc  56                               push   esi
0x79dfbd  ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x79dfc3  8d442450                         lea    eax,[esp+0x50]
0x79dfc7  50                               push   eax
0x79dfc8  8bf3                             mov    esi,ebx
0x79dfca  e8f1070000                       call   0x79e7c0
0x79dfcf  8d4c2438                         lea    ecx,[esp+0x38]
0x79dfd3  51                               push   ecx
0x79dfd4  e8c7080000                       call   0x79e8a0
0x79dfd9  397b68                           cmp    DWORD PTR [ebx+0x68],edi
0x79dfdc  0f8447010000                     je     0x79e129
0x79dfe2  8b736c                           mov    esi,DWORD PTR [ebx+0x6c]
0x79dfe5  8b5368                           mov    edx,DWORD PTR [ebx+0x68]
0x79dfe8  33ff                             xor    edi,edi
0x79dfea  897c2428                         mov    DWORD PTR [esp+0x28],edi

; worker_doll_process | worker selected request ->79E980
; VA 0x79e150..0x79e232 raw 0x39d550 length 226 sha256 747c801f2d38800bd6eb7aee92c8cb2ebf13c781265b3d633bf062c73af3486d
0x79e150  8d842490000000                   lea    eax,[esp+0x90]
0x79e157  8d4c2450                         lea    ecx,[esp+0x50]
0x79e15b  e8b040daff                       call   0x542210
0x79e160  8b08                             mov    ecx,DWORD PTR [eax]
0x79e162  33ff                             xor    edi,edi
0x79e164  3bcf                             cmp    ecx,edi
0x79e166  7504                             jne    0x79e16c
0x79e168  33d2                             xor    edx,edx
0x79e16a  eb02                             jmp    0x79e16e
0x79e16c  8b11                             mov    edx,DWORD PTR [ecx]
0x79e16e  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x79e171  8b7208                           mov    esi,DWORD PTR [edx+0x8]
0x79e174  8bc1                             mov    eax,ecx
0x79e176  d1e8                             shr    eax,1
0x79e178  83e101                           and    ecx,0x1
0x79e17b  3bf0                             cmp    esi,eax
0x79e17d  7702                             ja     0x79e181
0x79e17f  2bc6                             sub    eax,esi
0x79e181  8b5204                           mov    edx,DWORD PTR [edx+0x4]
0x79e184  8b0482                           mov    eax,DWORD PTR [edx+eax*4]
0x79e187  8b74c804                         mov    esi,DWORD PTR [eax+ecx*8+0x4]
0x79e18b  8d04c8                           lea    eax,[eax+ecx*8]
0x79e18e  8b08                             mov    ecx,DWORD PTR [eax]
0x79e190  897c2420                         mov    DWORD PTR [esp+0x20],edi
0x79e194  897c2424                         mov    DWORD PTR [esp+0x24],edi
0x79e198  894c2434                         mov    DWORD PTR [esp+0x34],ecx
0x79e19c  3bf7                             cmp    esi,edi
0x79e19e  7426                             je     0x79e1c6
0x79e1a0  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x79e1a3  3bcf                             cmp    ecx,edi
0x79e1a5  741b                             je     0x79e1c2
0x79e1a7  8d7901                           lea    edi,[ecx+0x1]
0x79e1aa  8d5e04                           lea    ebx,[esi+0x4]
0x79e1ad  8bc1                             mov    eax,ecx
0x79e1af  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
0x79e1b3  3bc1                             cmp    eax,ecx
0x79e1b5  0f84cf000000                     je     0x79e28a
0x79e1bb  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x79e1be  85c9                             test   ecx,ecx
0x79e1c0  75e5                             jne    0x79e1a7
0x79e1c2  8b7c2424                         mov    edi,DWORD PTR [esp+0x24]
0x79e1c6  8d742450                         lea    esi,[esp+0x50]
0x79e1ca  c68424a800000003                 mov    BYTE PTR [esp+0xa8],0x3
0x79e1d2  e809320000                       call   0x7a13e0
0x79e1d7  83ec08                           sub    esp,0x8
0x79e1da  8bdc                             mov    ebx,esp
0x79e1dc  89642438                         mov    DWORD PTR [esp+0x38],esp
0x79e1e0  c70300000000                     mov    DWORD PTR [ebx],0x0
0x79e1e6  c7430400000000                   mov    DWORD PTR [ebx+0x4],0x0
0x79e1ed  85ff                             test   edi,edi
0x79e1ef  7426                             je     0x79e217
0x79e1f1  8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0x79e1f4  85c9                             test   ecx,ecx
0x79e1f6  741b                             je     0x79e213
0x79e1f8  8d5101                           lea    edx,[ecx+0x1]
0x79e1fb  8d7704                           lea    esi,[edi+0x4]
0x79e1fe  8bc1                             mov    eax,ecx
0x79e200  f00fb116                         lock cmpxchg DWORD PTR [esi],edx
0x79e204  3bc1                             cmp    eax,ecx
0x79e206  0f8491000000                     je     0x79e29d
0x79e20c  8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0x79e20f  85c9                             test   ecx,ecx
0x79e211  75e5                             jne    0x79e1f8
0x79e213  8b7c242c                         mov    edi,DWORD PTR [esp+0x2c]
0x79e217  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x79e21a  51                               push   ecx
0x79e21b  e860070000                       call   0x79e980
0x79e220  8b35a025bd00                     mov    esi,DWORD PTR ds:0xbd25a0
0x79e226  83c40c                           add    esp,0xc
0x79e229  ffd6                             call   esi
0x79e22b  2b442414                         sub    eax,DWORD PTR [esp+0x14]
0x79e22f  83f80f                           cmp    eax,0xf

; doll_item_materialize | appearance descriptor -> typed CItem -> prepared active map
; VA 0x79f0d0..0x79f292 raw 0x39e4d0 length 450 sha256 dd7b38587216206fc870a5d40ebae28593b587e11f6e26b681c737f8eccc8dd0
0x79f0d0  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x79f0d7  7524                             jne    0x79f0fd
0x79f0d9  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x79f0e0  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
0x79f0e4  e817fe0100                       call   0x7bef00
0x79f0e9  6850ecbc00                       push   0xbcec50
0x79f0ee  e827320f00                       call   0x89231a
0x79f0f3  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x79f0f7  8b7510                           mov    esi,DWORD PTR [ebp+0x10]
0x79f0fa  83c404                           add    esp,0x4
0x79f0fd  8b4b18                           mov    ecx,DWORD PTR [ebx+0x18]
0x79f100  8b531c                           mov    edx,DWORD PTR [ebx+0x1c]
0x79f103  8d45b0                           lea    eax,[ebp-0x50]
0x79f106  894db0                           mov    DWORD PTR [ebp-0x50],ecx
0x79f109  50                               push   eax
0x79f10a  8d4df0                           lea    ecx,[ebp-0x10]
0x79f10d  51                               push   ecx
0x79f10e  68601bfe00                       push   0xfe1b60
0x79f113  8955b4                           mov    DWORD PTR [ebp-0x4c],edx
0x79f116  e8e5e2d3ff                       call   0x4dd400
0x79f11b  8b45f0                           mov    eax,DWORD PTR [ebp-0x10]
0x79f11e  3b05641bfe00                     cmp    eax,DWORD PTR ds:0xfe1b64
0x79f124  0f8423010000                     je     0x79f24d
0x79f12a  8b7818                           mov    edi,DWORD PTR [eax+0x18]
0x79f12d  897de0                           mov    DWORD PTR [ebp-0x20],edi
0x79f130  85ff                             test   edi,edi
0x79f132  0f8415010000                     je     0x79f24d
0x79f138  6a50                             push   0x50
0x79f13a  e829210f00                       call   0x891268
0x79f13f  8bf0                             mov    esi,eax
0x79f141  83c404                           add    esp,0x4
0x79f144  8975d4                           mov    DWORD PTR [ebp-0x2c],esi
0x79f147  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x79f14b  85f6                             test   esi,esi
0x79f14d  0f84c6000000                     je     0x79f219
0x79f153  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x79f15a  7521                             jne    0x79f17d
0x79f15c  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x79f163  c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
0x79f167  e894fd0100                       call   0x7bef00
0x79f16c  6850ecbc00                       push   0xbcec50
0x79f171  e8a4310f00                       call   0x89231a
0x79f176  83c404                           add    esp,0x4
0x79f179  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x79f17d  8b5318                           mov    edx,DWORD PTR [ebx+0x18]
0x79f180  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
0x79f183  8955a8                           mov    DWORD PTR [ebp-0x58],edx
0x79f186  8945ac                           mov    DWORD PTR [ebp-0x54],eax
0x79f189  8d55a8                           lea    edx,[ebp-0x58]
0x79f18c  b8a01bfe00                       mov    eax,0xfe1ba0
0x79f191  e8aa0f0200                       call   0x7c0140
0x79f196  f605c01bfe0001                   test   BYTE PTR ds:0xfe1bc0,0x1
0x79f19d  0fb708                           movzx  ecx,WORD PTR [eax]
0x79f1a0  894de4                           mov    DWORD PTR [ebp-0x1c],ecx
0x79f1a3  7521                             jne    0x79f1c6
0x79f1a5  830dc01bfe0001                   or     DWORD PTR ds:0xfe1bc0,0x1
0x79f1ac  c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
0x79f1b0  e84bfd0100                       call   0x7bef00
0x79f1b5  6850ecbc00                       push   0xbcec50
0x79f1ba  e85b310f00                       call   0x89231a
0x79f1bf  83c404                           add    esp,0x4
0x79f1c2  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
0x79f1c6  8b5318                           mov    edx,DWORD PTR [ebx+0x18]
0x79f1c9  8b431c                           mov    eax,DWORD PTR [ebx+0x1c]
0x79f1cc  8955d8                           mov    DWORD PTR [ebp-0x28],edx
0x79f1cf  8945dc                           mov    DWORD PTR [ebp-0x24],eax
0x79f1d2  8d55d8                           lea    edx,[ebp-0x28]
0x79f1d5  b8901bfe00                       mov    eax,0xfe1b90
0x79f1da  e8610f0200                       call   0x7c0140
0x79f1df  8b4b10                           mov    ecx,DWORD PTR [ebx+0x10]
0x79f1e2  0fb700                           movzx  eax,WORD PTR [eax]
0x79f1e5  8b5318                           mov    edx,DWORD PTR [ebx+0x18]
0x79f1e8  8b7b1c                           mov    edi,DWORD PTR [ebx+0x1c]
0x79f1eb  894e10                           mov    DWORD PTR [esi+0x10],ecx
0x79f1ee  33c9                             xor    ecx,ecx
0x79f1f0  895608                           mov    DWORD PTR [esi+0x8],edx
0x79f1f3  0fb755e4                         movzx  edx,WORD PTR [ebp-0x1c]
0x79f1f7  897e0c                           mov    DWORD PTR [esi+0xc],edi
0x79f1fa  8b7de0                           mov    edi,DWORD PTR [ebp-0x20]
0x79f1fd  894e14                           mov    DWORD PTR [esi+0x14],ecx
0x79f200  c706b800c500                     mov    DWORD PTR [esi],0xc500b8
0x79f206  894e18                           mov    DWORD PTR [esi+0x18],ecx
0x79f209  894e1c                           mov    DWORD PTR [esi+0x1c],ecx
0x79f20c  894e20                           mov    DWORD PTR [esi+0x20],ecx
0x79f20f  8bc8                             mov    ecx,eax
0x79f211  894e44                           mov    DWORD PTR [esi+0x44],ecx
0x79f214  895648                           mov    DWORD PTR [esi+0x48],edx
0x79f217  eb02                             jmp    0x79f21b
0x79f219  33f6                             xor    esi,esi
0x79f21b  57                               push   edi
0x79f21c  8bc6                             mov    eax,esi
0x79f21e  c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x79f222  e8795d0300                       call   0x7d4fa0
0x79f227  8b4310                           mov    eax,DWORD PTR [ebx+0x10]
0x79f22a  8975d0                           mov    DWORD PTR [ebp-0x30],esi
0x79f22d  8b75e8                           mov    esi,DWORD PTR [ebp-0x18]
0x79f230  8945cc                           mov    DWORD PTR [ebp-0x34],eax
0x79f233  83c618                           add    esi,0x18
0x79f236  8d7dcc                           lea    edi,[ebp-0x34]
0x79f239  8bc6                             mov    eax,esi
0x79f23b  e860420000                       call   0x7a34a0
0x79f240  50                               push   eax
0x79f241  56                               push   esi
0x79f242  8d75c0                           lea    esi,[ebp-0x40]
0x79f245  e826190200                       call   0x7c0b70
0x79f24a  8b7510                           mov    esi,DWORD PTR [ebp+0x10]
0x79f24d  807b2100                         cmp    BYTE PTR [ebx+0x21],0x0
0x79f251  753f                             jne    0x79f292
0x79f253  8b4308                           mov    eax,DWORD PTR [ebx+0x8]
0x79f256  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f25a  7516                             jne    0x79f272
0x79f25c  8bd8                             mov    ebx,eax
0x79f25e  8b03                             mov    eax,DWORD PTR [ebx]
0x79f260  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f264  752c                             jne    0x79f292
0x79f266  8bd8                             mov    ebx,eax
0x79f268  8b03                             mov    eax,DWORD PTR [ebx]
0x79f26a  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f26e  74f6                             je     0x79f266
0x79f270  eb20                             jmp    0x79f292
0x79f272  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x79f275  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f279  7515                             jne    0x79f290
0x79f27b  eb03                             jmp    0x79f280
0x79f27d  8d4900                           lea    ecx,[ecx+0x0]
0x79f280  3b5808                           cmp    ebx,DWORD PTR [eax+0x8]
0x79f283  750b                             jne    0x79f290
0x79f285  8bd8                             mov    ebx,eax
0x79f287  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x79f28a  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f28e  74f0                             je     0x79f280
0x79f290  8bd8                             mov    ebx,eax

; doll_face_skin | prepared face controller bound to Face.SKIN
; VA 0x79f760..0x79f971 raw 0x39eb60 length 529 sha256 7450dc358f70675cd2f53603e0bb36f0c8112b141a510f28d9a19b9314f9f41f
0x79f760  83c404                           add    esp,0x4
0x79f763  895e14                           mov    DWORD PTR [esi+0x14],ebx
0x79f766  c7461000000000                   mov    DWORD PTR [esi+0x10],0x0
0x79f76d  c60600                           mov    BYTE PTR [esi],0x0
0x79f770  83c61c                           add    esi,0x1c
0x79f773  3bf7                             cmp    esi,edi
0x79f775  75db                             jne    0x79f752
0x79f777  8b75b8                           mov    esi,DWORD PTR [ebp-0x48]
0x79f77a  33db                             xor    ebx,ebx
0x79f77c  56                               push   esi
0x79f77d  e88a1a0f00                       call   0x89120c
0x79f782  83c404                           add    esp,0x4
0x79f785  8b4ddc                           mov    ecx,DWORD PTR [ebp-0x24]
0x79f788  80792100                         cmp    BYTE PTR [ecx+0x21],0x0
0x79f78c  895db8                           mov    DWORD PTR [ebp-0x48],ebx
0x79f78f  895dbc                           mov    DWORD PTR [ebp-0x44],ebx
0x79f792  895dc0                           mov    DWORD PTR [ebp-0x40],ebx
0x79f795  7543                             jne    0x79f7da
0x79f797  8b4108                           mov    eax,DWORD PTR [ecx+0x8]
0x79f79a  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f79e  751c                             jne    0x79f7bc
0x79f7a0  8bc8                             mov    ecx,eax
0x79f7a2  8b01                             mov    eax,DWORD PTR [ecx]
0x79f7a4  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f7a8  752d                             jne    0x79f7d7
0x79f7aa  8d9b00000000                     lea    ebx,[ebx+0x0]
0x79f7b0  8bc8                             mov    ecx,eax
0x79f7b2  8b01                             mov    eax,DWORD PTR [ecx]
0x79f7b4  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f7b8  74f6                             je     0x79f7b0
0x79f7ba  eb1b                             jmp    0x79f7d7
0x79f7bc  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x79f7bf  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f7c3  7510                             jne    0x79f7d5
0x79f7c5  3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
0x79f7c8  750b                             jne    0x79f7d5
0x79f7ca  8bc8                             mov    ecx,eax
0x79f7cc  8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x79f7cf  80782100                         cmp    BYTE PTR [eax+0x21],0x0
0x79f7d3  74f0                             je     0x79f7c5
0x79f7d5  8bc8                             mov    ecx,eax
0x79f7d7  894ddc                           mov    DWORD PTR [ebp-0x24],ecx
0x79f7da  8b55e8                           mov    edx,DWORD PTR [ebp-0x18]
0x79f7dd  3b4a1c                           cmp    ecx,DWORD PTR [edx+0x1c]
0x79f7e0  0f85dafdffff                     jne    0x79f5c0
0x79f7e6  8345e41c                         add    DWORD PTR [ebp-0x1c],0x1c
0x79f7ea  ff4df0                           dec    DWORD PTR [ebp-0x10]
0x79f7ed  0f85a0fdffff                     jne    0x79f593
0x79f7f3  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x79f7f6  8bb0e4000000                     mov    esi,DWORD PTR [eax+0xe4]
0x79f7fc  8b7e38                           mov    edi,DWORD PTR [esi+0x38]
0x79f7ff  8bcf                             mov    ecx,edi
0x79f801  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x79f804  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x79f808  8bd1                             mov    edx,ecx
0x79f80a  bb01000000                       mov    ebx,0x1
0x79f80f  7514                             jne    0x79f825
0x79f811  39580c                           cmp    DWORD PTR [eax+0xc],ebx
0x79f814  7305                             jae    0x79f81b
0x79f816  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x79f819  eb04                             jmp    0x79f81f
0x79f81b  8bd0                             mov    edx,eax
0x79f81d  8b00                             mov    eax,DWORD PTR [eax]
0x79f81f  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x79f823  74ec                             je     0x79f811
0x79f825  89550c                           mov    DWORD PTR [ebp+0xc],edx
0x79f828  3bd1                             cmp    edx,ecx
0x79f82a  740a                             je     0x79f836
0x79f82c  395a0c                           cmp    DWORD PTR [edx+0xc],ebx
0x79f82f  7705                             ja     0x79f836
0x79f831  8d450c                           lea    eax,[ebp+0xc]
0x79f834  eb06                             jmp    0x79f83c
0x79f836  894df0                           mov    DWORD PTR [ebp-0x10],ecx
0x79f839  8d45f0                           lea    eax,[ebp-0x10]
0x79f83c  3938                             cmp    DWORD PTR [eax],edi
0x79f83e  0f8496000000                     je     0x79f8da
0x79f844  6a18                             push   0x18
0x79f846  e81d1a0f00                       call   0x891268
0x79f84b  33ff                             xor    edi,edi
0x79f84d  83c404                           add    esp,0x4
0x79f850  3bc7                             cmp    eax,edi
0x79f852  7464                             je     0x79f8b8
0x79f854  d9ee                             fldz
0x79f856  89780c                           mov    DWORD PTR [eax+0xc],edi
0x79f859  d95808                           fstp   DWORD PTR [eax+0x8]
0x79f85c  8930                             mov    DWORD PTR [eax],esi
0x79f85e  895810                           mov    DWORD PTR [eax+0x10],ebx
0x79f861  895814                           mov    DWORD PTR [eax+0x14],ebx
0x79f864  8b5638                           mov    edx,DWORD PTR [esi+0x38]
0x79f867  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0x79f86a  80791500                         cmp    BYTE PTR [ecx+0x15],0x0
0x79f86e  8bfa                             mov    edi,edx
0x79f870  7514                             jne    0x79f886
0x79f872  39590c                           cmp    DWORD PTR [ecx+0xc],ebx
0x79f875  7305                             jae    0x79f87c
0x79f877  8b4908                           mov    ecx,DWORD PTR [ecx+0x8]
0x79f87a  eb04                             jmp    0x79f880
0x79f87c  8bf9                             mov    edi,ecx
0x79f87e  8b09                             mov    ecx,DWORD PTR [ecx]
0x79f880  80791500                         cmp    BYTE PTR [ecx+0x15],0x0
0x79f884  74ec                             je     0x79f872
0x79f886  897d0c                           mov    DWORD PTR [ebp+0xc],edi
0x79f889  3bfa                             cmp    edi,edx
0x79f88b  740a                             je     0x79f897
0x79f88d  395f0c                           cmp    DWORD PTR [edi+0xc],ebx
0x79f890  7705                             ja     0x79f897
0x79f892  8d4d0c                           lea    ecx,[ebp+0xc]
0x79f895  eb06                             jmp    0x79f89d
0x79f897  8955f0                           mov    DWORD PTR [ebp-0x10],edx
0x79f89a  8d4df0                           lea    ecx,[ebp-0x10]
0x79f89d  8b09                             mov    ecx,DWORD PTR [ecx]
0x79f89f  3bca                             cmp    ecx,edx
0x79f8a1  7504                             jne    0x79f8a7
0x79f8a3  33c9                             xor    ecx,ecx
0x79f8a5  eb03                             jmp    0x79f8aa
0x79f8a7  8b4910                           mov    ecx,DWORD PTR [ecx+0x10]
0x79f8aa  d94104                           fld    DWORD PTR [ecx+0x4]
0x79f8ad  8bf8                             mov    edi,eax
0x79f8af  d95d0c                           fstp   DWORD PTR [ebp+0xc]
0x79f8b2  d9450c                           fld    DWORD PTR [ebp+0xc]
0x79f8b5  d95804                           fstp   DWORD PTR [eax+0x4]
0x79f8b8  ff462c                           inc    DWORD PTR [esi+0x2c]
0x79f8bb  8b5de8                           mov    ebx,DWORD PTR [ebp-0x18]
0x79f8be  897b14                           mov    DWORD PTR [ebx+0x14],edi
0x79f8c1  8b4310                           mov    eax,DWORD PTR [ebx+0x10]
0x79f8c4  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x79f8c7  68ecfdc400                       push   0xc4fdec
0x79f8cc  50                               push   eax
0x79f8cd  e82e6e0200                       call   0x7c6700
0x79f8d2  83c408                           add    esp,0x8
0x79f8d5  89470c                           mov    DWORD PTR [edi+0xc],eax
0x79f8d8  eb03                             jmp    0x79f8dd
0x79f8da  8b5de8                           mov    ebx,DWORD PTR [ebp-0x18]
0x79f8dd  8b7b10                           mov    edi,DWORD PTR [ebx+0x10]
0x79f8e0  8b7774                           mov    esi,DWORD PTR [edi+0x74]
0x79f8e3  33c0                             xor    eax,eax
0x79f8e5  894614                           mov    DWORD PTR [esi+0x14],eax
0x79f8e8  894618                           mov    DWORD PTR [esi+0x18],eax
0x79f8eb  8b5608                           mov    edx,DWORD PTR [esi+0x8]
0x79f8ee  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x79f8f1  897d0c                           mov    DWORD PTR [ebp+0xc],edi
0x79f8f4  3bca                             cmp    ecx,edx
0x79f8f6  742e                             je     0x79f926
0x79f8f8  8bc2                             mov    eax,edx
0x79f8fa  3bd2                             cmp    edx,edx
0x79f8fc  7425                             je     0x79f923
0x79f8fe  8bff                             mov    edi,edi
0x79f900  8b38                             mov    edi,DWORD PTR [eax]
0x79f902  8939                             mov    DWORD PTR [ecx],edi
0x79f904  8b7804                           mov    edi,DWORD PTR [eax+0x4]
0x79f907  897904                           mov    DWORD PTR [ecx+0x4],edi
0x79f90a  8b7808                           mov    edi,DWORD PTR [eax+0x8]
0x79f90d  897908                           mov    DWORD PTR [ecx+0x8],edi
0x79f910  8b780c                           mov    edi,DWORD PTR [eax+0xc]
0x79f913  89790c                           mov    DWORD PTR [ecx+0xc],edi
0x79f916  83c010                           add    eax,0x10
0x79f919  83c110                           add    ecx,0x10
0x79f91c  3bc2                             cmp    eax,edx
0x79f91e  75e0                             jne    0x79f900
0x79f920  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
0x79f923  894e08                           mov    DWORD PTR [esi+0x8],ecx
0x79f926  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
0x79f929  51                               push   ecx
0x79f92a  8b4f74                           mov    ecx,DWORD PTR [edi+0x74]
0x79f92d  e86ef00400                       call   0x7ee9a0
0x79f932  8b7f74                           mov    edi,DWORD PTR [edi+0x74]
0x79f935  e8b6f20400                       call   0x7eebf0
0x79f93a  837b1000                         cmp    DWORD PTR [ebx+0x10],0x0
0x79f93e  0f8431010000                     je     0x79fa75
0x79f944  a1e879fb00                       mov    eax,ds:0xfb79e8
0x79f949  a801                             test   al,0x1
0x79f94b  7527                             jne    0x79f974
0x79f94d  83c801                           or     eax,0x1
0x79f950  a3e879fb00                       mov    ds:0xfb79e8,eax
0x79f955  c645fc0e                         mov    BYTE PTR [ebp-0x4],0xe
0x79f959  e88294ffff                       call   0x798de0
0x79f95e  68e0d2bc00                       push   0xbcd2e0
0x79f963  e8b2290f00                       call   0x89231a
0x79f968  c645fc0a                         mov    BYTE PTR [ebp-0x4],0xa
0x79f96c  a1e879fb00                       mov    eax,ds:0xfb79e8

; actor_flash_tick | flash fields read and decremented by common update
; VA 0x4c86fb..0x4c87ac raw 0xc7afb length 177 sha256 e8cfca7098b707eaf468c82cd5d5ed7baa4ead3c8e046ee9c273ba19c3c1997f
0x4c86fb  8b8b64030000                     mov    ecx,DWORD PTR [ebx+0x364]
0x4c8701  8b4924                           mov    ecx,DWORD PTR [ecx+0x24]
0x4c8704  85c9                             test   ecx,ecx
0x4c8706  7414                             je     0x4c871c
0x4c8708  8b10                             mov    edx,DWORD PTR [eax]
0x4c870a  895128                           mov    DWORD PTR [ecx+0x28],edx
0x4c870d  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4c8710  89512c                           mov    DWORD PTR [ecx+0x2c],edx
0x4c8713  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4c8716  894130                           mov    DWORD PTR [ecx+0x30],eax
0x4c8719  897970                           mov    DWORD PTR [ecx+0x70],edi
0x4c871c  8dbb64010000                     lea    edi,[ebx+0x164]
0x4c8722  c745c880000000                   mov    DWORD PTR [ebp-0x38],0x80
0x4c8729  8da42400000000                   lea    esp,[esp+0x0]
0x4c8730  8b37                             mov    esi,DWORD PTR [edi]
0x4c8732  85f6                             test   esi,esi
0x4c8734  7433                             je     0x4c8769
0x4c8736  e845800800                       call   0x550780
0x4c873b  8b13                             mov    edx,DWORD PTR [ebx]
0x4c873d  8b5250                           mov    edx,DWORD PTR [edx+0x50]
0x4c8740  8d45cc                           lea    eax,[ebp-0x34]
0x4c8743  50                               push   eax
0x4c8744  8bcb                             mov    ecx,ebx
0x4c8746  ffd2                             call   edx
0x4c8748  8b0f                             mov    ecx,DWORD PTR [edi]
0x4c874a  8b4924                           mov    ecx,DWORD PTR [ecx+0x24]
0x4c874d  85c9                             test   ecx,ecx
0x4c874f  7418                             je     0x4c8769
0x4c8751  8b10                             mov    edx,DWORD PTR [eax]
0x4c8753  895128                           mov    DWORD PTR [ecx+0x28],edx
0x4c8756  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4c8759  89512c                           mov    DWORD PTR [ecx+0x2c],edx
0x4c875c  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4c875f  894130                           mov    DWORD PTR [ecx+0x30],eax
0x4c8762  c7417001000000                   mov    DWORD PTR [ecx+0x70],0x1
0x4c8769  83c704                           add    edi,0x4
0x4c876c  ff4dc8                           dec    DWORD PTR [ebp-0x38]
0x4c876f  75bf                             jne    0x4c8730
0x4c8771  8b8314040000                     mov    eax,DWORD PTR [ebx+0x414]
0x4c8777  85c0                             test   eax,eax
0x4c8779  741b                             je     0x4c8796
0x4c877b  8bbb10040000                     mov    edi,DWORD PTR [ebx+0x410]
0x4c8781  57                               push   edi
0x4c8782  2bf8                             sub    edi,eax
0x4c8784  8b830c040000                     mov    eax,DWORD PTR [ebx+0x40c]
0x4c878a  53                               push   ebx
0x4c878b  e8b0090000                       call   0x4c9140
0x4c8790  ff8b14040000                     dec    DWORD PTR [ebx+0x414]
0x4c8796  8b8318040000                     mov    eax,DWORD PTR [ebx+0x418]
0x4c879c  85c0                             test   eax,eax
0x4c879e  7407                             je     0x4c87a7
0x4c87a0  48                               dec    eax
0x4c87a1  898318040000                     mov    DWORD PTR [ebx+0x418],eax
0x4c87a7  33c0                             xor    eax,eax
0x4c87a9  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]

; actor_flash_modes | finite known visual flash branches
; VA 0x4c9140..0x4c9347 raw 0xc8540 length 519 sha256 c47937a22f1efd4c4fce73011710eaee8646c6ad5692a28725839c955a3826ad
0x4c9140  55                               push   ebp
0x4c9141  8bec                             mov    ebp,esp
0x4c9143  83e4f8                           and    esp,0xfffffff8
0x4c9146  83ec18                           sub    esp,0x18
0x4c9149  53                               push   ebx
0x4c914a  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4c914d  56                               push   esi
0x4c914e  8bb35c010000                     mov    esi,DWORD PTR [ebx+0x15c]
0x4c9154  85f6                             test   esi,esi
0x4c9156  0f84c9030000                     je     0x4c9525
0x4c915c  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
0x4c9163  0f84bc030000                     je     0x4c9525
0x4c9169  85c0                             test   eax,eax
0x4c916b  0f858a000000                     jne    0x4c91fb
0x4c9171  85ff                             test   edi,edi
0x4c9173  755a                             jne    0x4c91cf
0x4c9175  f30f1005485dc500                 movss  xmm0,DWORD PTR ds:0xc55d48
0x4c917d  f30f11442410                     movss  DWORD PTR [esp+0x10],xmm0
0x4c9183  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4c9187  83ec10                           sub    esp,0x10
0x4c918a  8bc4                             mov    eax,esp
0x4c918c  8908                             mov    DWORD PTR [eax],ecx
0x4c918e  f30f11442424                     movss  DWORD PTR [esp+0x24],xmm0
0x4c9194  8b542424                         mov    edx,DWORD PTR [esp+0x24]
0x4c9198  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
0x4c919e  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x4c91a6  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x4c91aa  895004                           mov    DWORD PTR [eax+0x4],edx
0x4c91ad  f30f1144242c                     movss  DWORD PTR [esp+0x2c],xmm0
0x4c91b3  8b54242c                         mov    edx,DWORD PTR [esp+0x2c]
0x4c91b7  894808                           mov    DWORD PTR [eax+0x8],ecx
0x4c91ba  89500c                           mov    DWORD PTR [eax+0xc],edx
0x4c91bd  8bc6                             mov    eax,esi
0x4c91bf  e82cea2d00                       call   0x7a7bf0
0x4c91c4  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
0x4c91ca  6a01                             push   0x1
0x4c91cc  50                               push   eax
0x4c91cd  eb08                             jmp    0x4c91d7
0x4c91cf  83ff02                           cmp    edi,0x2
0x4c91d2  7508                             jne    0x4c91dc
0x4c91d4  6a00                             push   0x0
0x4c91d6  56                               push   esi
0x4c91d7  e8e4ea2d00                       call   0x7a7cc0
0x4c91dc  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x4c91df  49                               dec    ecx
0x4c91e0  3bf9                             cmp    edi,ecx
0x4c91e2  0f853d030000                     jne    0x4c9525
0x4c91e8  8bb35c010000                     mov    esi,DWORD PTR [ebx+0x15c]
0x4c91ee  e8bdec2d00                       call   0x7a7eb0
0x4c91f3  5e                               pop    esi
0x4c91f4  5b                               pop    ebx
0x4c91f5  8be5                             mov    esp,ebp
0x4c91f7  5d                               pop    ebp
0x4c91f8  c20800                           ret    0x8
0x4c91fb  83f801                           cmp    eax,0x1
0x4c91fe  0f853a010000                     jne    0x4c933e
0x4c9204  85ff                             test   edi,edi
0x4c9206  7568                             jne    0x4c9270
0x4c9208  f30f1005485dc500                 movss  xmm0,DWORD PTR ds:0xc55d48
0x4c9210  f30f11442410                     movss  DWORD PTR [esp+0x10],xmm0
0x4c9216  0f57c0                           xorps  xmm0,xmm0
0x4c9219  8b542410                         mov    edx,DWORD PTR [esp+0x10]
0x4c921d  83ec10                           sub    esp,0x10
0x4c9220  8bc4                             mov    eax,esp
0x4c9222  8910                             mov    DWORD PTR [eax],edx
0x4c9224  f30f11442424                     movss  DWORD PTR [esp+0x24],xmm0
0x4c922a  8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
0x4c922e  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
0x4c9234  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x4c923c  8b542428                         mov    edx,DWORD PTR [esp+0x28]
0x4c9240  894804                           mov    DWORD PTR [eax+0x4],ecx
0x4c9243  f30f1144242c                     movss  DWORD PTR [esp+0x2c],xmm0
0x4c9249  8b4c242c                         mov    ecx,DWORD PTR [esp+0x2c]
0x4c924d  895008                           mov    DWORD PTR [eax+0x8],edx
0x4c9250  89480c                           mov    DWORD PTR [eax+0xc],ecx
0x4c9253  8bc6                             mov    eax,esi
0x4c9255  e896e92d00                       call   0x7a7bf0
0x4c925a  8b935c010000                     mov    edx,DWORD PTR [ebx+0x15c]
0x4c9260  6a01                             push   0x1
0x4c9262  52                               push   edx
0x4c9263  e858ea2d00                       call   0x7a7cc0
0x4c9268  5e                               pop    esi
0x4c9269  5b                               pop    ebx
0x4c926a  8be5                             mov    esp,ebp
0x4c926c  5d                               pop    ebp
0x4c926d  c20800                           ret    0x8
0x4c9270  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x4c9273  8d48ff                           lea    ecx,[eax-0x1]
0x4c9276  3bf9                             cmp    edi,ecx
0x4c9278  0f8470ffffff                     je     0x4c91ee
0x4c927e  8bd7                             mov    edx,edi
0x4c9280  8954240c                         mov    DWORD PTR [esp+0xc],edx
0x4c9284  db44240c                         fild   DWORD PTR [esp+0xc]
0x4c9288  85d2                             test   edx,edx
0x4c928a  7906                             jns    0x4c9292
0x4c928c  d8058056c500                     fadd   DWORD PTR ds:0xc55680
0x4c9292  dc0db056c500                     fmul   QWORD PTR ds:0xc556b0
0x4c9298  8944240c                         mov    DWORD PTR [esp+0xc],eax
0x4c929c  db44240c                         fild   DWORD PTR [esp+0xc]
0x4c92a0  85c0                             test   eax,eax
0x4c92a2  7906                             jns    0x4c92aa
0x4c92a4  d8058056c500                     fadd   DWORD PTR ds:0xc55680
0x4c92aa  def9                             fdivp  st(1),st
0x4c92ac  d95c240c                         fstp   DWORD PTR [esp+0xc]
0x4c92b0  d9050c7dc000                     fld    DWORD PTR ds:0xc07d0c
0x4c92b6  d944240c                         fld    DWORD PTR [esp+0xc]
0x4c92ba  dff1                             fcomip st,st(1)
0x4c92bc  ddd8                             fstp   st(0)
0x4c92be  760a                             jbe    0x4c92ca
0x4c92c0  f30f10050c7dc000                 movss  xmm0,DWORD PTR ds:0xc07d0c
0x4c92c8  eb06                             jmp    0x4c92d0
0x4c92ca  f30f1044240c                     movss  xmm0,DWORD PTR [esp+0xc]
0x4c92d0  f30f100d485dc500                 movss  xmm1,DWORD PTR ds:0xc55d48
0x4c92d8  f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x4c92de  f30f11442418                     movss  DWORD PTR [esp+0x18],xmm0
0x4c92e4  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x4c92ec  f30f114c2410                     movss  DWORD PTR [esp+0x10],xmm1
0x4c92f2  f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
0x4c92f8  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4c92fc  8b542414                         mov    edx,DWORD PTR [esp+0x14]
0x4c9300  83ec10                           sub    esp,0x10
0x4c9303  8bc4                             mov    eax,esp
0x4c9305  8908                             mov    DWORD PTR [eax],ecx
0x4c9307  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x4c930b  895004                           mov    DWORD PTR [eax+0x4],edx
0x4c930e  8b54242c                         mov    edx,DWORD PTR [esp+0x2c]
0x4c9312  894808                           mov    DWORD PTR [eax+0x8],ecx
0x4c9315  89500c                           mov    DWORD PTR [eax+0xc],edx
0x4c9318  8bc6                             mov    eax,esi
0x4c931a  e8d1e82d00                       call   0x7a7bf0
0x4c931f  83ff02                           cmp    edi,0x2
0x4c9322  0f83fd010000                     jae    0x4c9525
0x4c9328  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
0x4c932e  6a01                             push   0x1
0x4c9330  50                               push   eax
0x4c9331  e88ae92d00                       call   0x7a7cc0
0x4c9336  5e                               pop    esi
0x4c9337  5b                               pop    ebx
0x4c9338  8be5                             mov    esp,ebp
0x4c933a  5d                               pop    ebp
0x4c933b  c20800                           ret    0x8
0x4c933e  83f802                           cmp    eax,0x2
0x4c9341  0f85d2000000                     jne    0x4c9419

; checkpoint_status_write | write +105; category-specific visual branches
; VA 0x543b30..0x543b9d raw 0x142f30 length 109 sha256 4fa7ab69557f9db095f253d2f6c93e186a2815ecbd14f273e2dda3cb0c763f21
0x543b30  55                               push   ebp
0x543b31  8bec                             mov    ebp,esp
0x543b33  83e4f8                           and    esp,0xfffffff8
0x543b36  6aff                             push   0xffffffff
0x543b38  68ac979200                       push   0x9297ac
0x543b3d  64a100000000                     mov    eax,fs:0x0
0x543b43  50                               push   eax
0x543b44  83ec38                           sub    esp,0x38
0x543b47  a1201fd600                       mov    eax,ds:0xd61f20
0x543b4c  33c4                             xor    eax,esp
0x543b4e  89442430                         mov    DWORD PTR [esp+0x30],eax
0x543b52  53                               push   ebx
0x543b53  56                               push   esi
0x543b54  57                               push   edi
0x543b55  a1201fd600                       mov    eax,ds:0xd61f20
0x543b5a  33c4                             xor    eax,esp
0x543b5c  50                               push   eax
0x543b5d  8d442448                         lea    eax,[esp+0x48]
0x543b61  64a300000000                     mov    fs:0x0,eax
0x543b67  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x543b6a  0fb783f4000000                   movzx  eax,WORD PTR [ebx+0xf4]
0x543b71  33ff                             xor    edi,edi
0x543b73  884c2417                         mov    BYTE PTR [esp+0x17],cl
0x543b77  888b05010000                     mov    BYTE PTR [ebx+0x105],cl
0x543b7d  663bc7                           cmp    ax,di
0x543b80  0f853d040000                     jne    0x543fc3
0x543b86  8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
0x543b8c  3bc7                             cmp    eax,edi
0x543b8e  7432                             je     0x543bc2
0x543b90  397824                           cmp    DWORD PTR [eax+0x24],edi
0x543b93  8d7024                           lea    esi,[eax+0x24]
0x543b96  7409                             je     0x543ba1
0x543b98  e853aa2700                       call   0x7be5f0

; checkpoint_packet | S2C0027 clear and 18-byte rows -> typed point constructor
; VA 0x4b2af0..0x4b2c33 raw 0xb1ef0 length 323 sha256 a636c8f650a3a47c82cd39d3a1d8b1f5bbd9b8100fad8ea8dd0e9591ad87fb1e
0x4b2af0  55                               push   ebp
0x4b2af1  8bec                             mov    ebp,esp
0x4b2af3  83e4f8                           and    esp,0xfffffff8
0x4b2af6  6aff                             push   0xffffffff
0x4b2af8  683b9f9200                       push   0x929f3b
0x4b2afd  64a100000000                     mov    eax,fs:0x0
0x4b2b03  50                               push   eax
0x4b2b04  83ec10                           sub    esp,0x10
0x4b2b07  53                               push   ebx
0x4b2b08  56                               push   esi
0x4b2b09  57                               push   edi
0x4b2b0a  a1201fd600                       mov    eax,ds:0xd61f20
0x4b2b0f  33c4                             xor    eax,esp
0x4b2b11  50                               push   eax
0x4b2b12  8d442420                         lea    eax,[esp+0x20]
0x4b2b16  64a300000000                     mov    fs:0x0,eax
0x4b2b1c  33db                             xor    ebx,ebx
0x4b2b1e  f605ec79fb0001                   test   BYTE PTR ds:0xfb79ec,0x1
0x4b2b25  7539                             jne    0x4b2b60
0x4b2b27  b801000000                       mov    eax,0x1
0x4b2b2c  0905ec79fb00                     or     DWORD PTR ds:0xfb79ec,eax
0x4b2b32  6870d2bc00                       push   0xbcd270
0x4b2b37  c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x4b2b41  891df479fb00                     mov    DWORD PTR ds:0xfb79f4,ebx
0x4b2b47  891df879fb00                     mov    DWORD PTR ds:0xfb79f8,ebx
0x4b2b4d  891dfc79fb00                     mov    DWORD PTR ds:0xfb79fc,ebx
0x4b2b53  a3047afb00                       mov    ds:0xfb7a04,eax
0x4b2b58  e8bdf73d00                       call   0x89231a
0x4b2b5d  83c404                           add    esp,0x4
0x4b2b60  68f079fb00                       push   0xfb79f0
0x4b2b65  e8361e0900                       call   0x5449a0
0x4b2b6a  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x4b2b6d  83f802                           cmp    eax,0x2
0x4b2b70  7304                             jae    0x4b2b76
0x4b2b72  33d2                             xor    edx,edx
0x4b2b74  eb0d                             jmp    0x4b2b83
0x4b2b76  8d48fe                           lea    ecx,[eax-0x2]
0x4b2b79  b8398ee338                       mov    eax,0x38e38e39
0x4b2b7e  f7e1                             mul    ecx
0x4b2b80  c1ea02                           shr    edx,0x2
0x4b2b83  3bd3                             cmp    edx,ebx
0x4b2b85  0f8622010000                     jbe    0x4b2cad
0x4b2b8b  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x4b2b8e  83c712                           add    edi,0x12
0x4b2b91  89542418                         mov    DWORD PTR [esp+0x18],edx
0x4b2b95  6808010000                       push   0x108
0x4b2b9a  e8c9e63d00                       call   0x891268
0x4b2b9f  83c404                           add    esp,0x4
0x4b2ba2  89442414                         mov    DWORD PTR [esp+0x14],eax
0x4b2ba6  895c2428                         mov    DWORD PTR [esp+0x28],ebx
0x4b2baa  3bc3                             cmp    eax,ebx
0x4b2bac  7430                             je     0x4b2bde
0x4b2bae  0fb65701                         movzx  edx,BYTE PTR [edi+0x1]
0x4b2bb2  d947fc                           fld    DWORD PTR [edi-0x4]
0x4b2bb5  0fb60f                           movzx  ecx,BYTE PTR [edi]
0x4b2bb8  52                               push   edx
0x4b2bb9  0fb657f3                         movzx  edx,BYTE PTR [edi-0xd]
0x4b2bbd  51                               push   ecx
0x4b2bbe  52                               push   edx
0x4b2bbf  0fb757f0                         movzx  edx,WORD PTR [edi-0x10]
0x4b2bc3  51                               push   ecx
0x4b2bc4  8d4ff4                           lea    ecx,[edi-0xc]
0x4b2bc7  d91c24                           fstp   DWORD PTR [esp]
0x4b2bca  52                               push   edx
0x4b2bcb  660fbe57f2                       movsx  dx,BYTE PTR [edi-0xe]
0x4b2bd0  0fb7d2                           movzx  edx,dx
0x4b2bd3  52                               push   edx
0x4b2bd4  50                               push   eax
0x4b2bd5  e8260b0900                       call   0x543700
0x4b2bda  8bf0                             mov    esi,eax
0x4b2bdc  eb02                             jmp    0x4b2be0
0x4b2bde  33f6                             xor    esi,esi
0x4b2be0  c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
0x4b2be8  f605ec79fb0001                   test   BYTE PTR ds:0xfb79ec,0x1
0x4b2bef  7539                             jne    0x4b2c2a
0x4b2bf1  b801000000                       mov    eax,0x1
0x4b2bf6  0905ec79fb00                     or     DWORD PTR ds:0xfb79ec,eax
0x4b2bfc  6870d2bc00                       push   0xbcd270
0x4b2c01  c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x4b2c0b  891df479fb00                     mov    DWORD PTR ds:0xfb79f4,ebx
0x4b2c11  891df879fb00                     mov    DWORD PTR ds:0xfb79f8,ebx
0x4b2c17  891dfc79fb00                     mov    DWORD PTR ds:0xfb79fc,ebx
0x4b2c1d  a3047afb00                       mov    ds:0xfb7a04,eax
0x4b2c22  e8f3f63d00                       call   0x89231a
0x4b2c27  83c404                           add    esp,0x4
0x4b2c2a  a1f879fb00                       mov    eax,ds:0xfb79f8
0x4b2c2f  8d4c2414                         lea    ecx,[esp+0x14]

; checkpoint_ctor | category/key/XY and category2 market visual
; VA 0x543700..0x543888 raw 0x142b00 length 392 sha256 d59099e73c07e24cebb99ae7eeaf99e4d4c7c1e9e5c565404715be3ba5c0b8fb
0x543700  55                               push   ebp
0x543701  8bec                             mov    ebp,esp
0x543703  6aff                             push   0xffffffff
0x543705  6828989200                       push   0x929828
0x54370a  64a100000000                     mov    eax,fs:0x0
0x543710  50                               push   eax
0x543711  83ec28                           sub    esp,0x28
0x543714  53                               push   ebx
0x543715  56                               push   esi
0x543716  57                               push   edi
0x543717  a1201fd600                       mov    eax,ds:0xd61f20
0x54371c  33c5                             xor    eax,ebp
0x54371e  50                               push   eax
0x54371f  8d45f4                           lea    eax,[ebp-0xc]
0x543722  64a300000000                     mov    fs:0x0,eax
0x543728  8bf9                             mov    edi,ecx
0x54372a  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x54372d  8a4518                           mov    al,BYTE PTR [ebp+0x18]
0x543730  8bf3                             mov    esi,ebx
0x543732  895dcc                           mov    DWORD PTR [ebp-0x34],ebx
0x543735  8845f3                           mov    BYTE PTR [ebp-0xd],al
0x543738  e8f36ff8ff                       call   0x4ca730
0x54373d  33d2                             xor    edx,edx
0x54373f  8993f0000000                     mov    DWORD PTR [ebx+0xf0],edx
0x543745  668b4510                         mov    ax,WORD PTR [ebp+0x10]
0x543749  668b4d0c                         mov    cx,WORD PTR [ebp+0xc]
0x54374d  f30f104514                       movss  xmm0,DWORD PTR [ebp+0x14]
0x543752  8955fc                           mov    DWORD PTR [ebp-0x4],edx
0x543755  668983f6000000                   mov    WORD PTR [ebx+0xf6],ax
0x54375c  8a4520                           mov    al,BYTE PTR [ebp+0x20]
0x54375f  8883f8000000                     mov    BYTE PTR [ebx+0xf8],al
0x543765  8b451c                           mov    eax,DWORD PTR [ebp+0x1c]
0x543768  898300010000                     mov    DWORD PTR [ebx+0x100],eax
0x54376e  0fb645f3                         movzx  eax,BYTE PTR [ebp-0xd]
0x543772  c703fcf7c000                     mov    DWORD PTR [ebx],0xc0f7fc
0x543778  66898bf4000000                   mov    WORD PTR [ebx+0xf4],cx
0x54377f  f30f1183fc000000                 movss  DWORD PTR [ebx+0xfc],xmm0
0x543787  889304010000                     mov    BYTE PTR [ebx+0x104],dl
0x54378d  888305010000                     mov    BYTE PTR [ebx+0x105],al
0x543793  d983a0000000                     fld    DWORD PTR [ebx+0xa0]
0x543799  8db3a0000000                     lea    esi,[ebx+0xa0]
0x54379f  d907                             fld    DWORD PTR [edi]
0x5437a1  dfe9                             fucomip st,st(1)
0x5437a3  9f                               lahf
0x5437a4  ddd8                             fstp   st(0)
0x5437a6  f6c444                           test   ah,0x44
0x5437a9  7a10                             jp     0x5437bb
0x5437ab  d94604                           fld    DWORD PTR [esi+0x4]
0x5437ae  d94704                           fld    DWORD PTR [edi+0x4]
0x5437b1  dfe9                             fucomip st,st(1)
0x5437b3  ddd8                             fstp   st(0)
0x5437b5  9f                               lahf
0x5437b6  f6c444                           test   ah,0x44
0x5437b9  7b22                             jnp    0x5437dd
0x5437bb  8b0f                             mov    ecx,DWORD PTR [edi]
0x5437bd  890e                             mov    DWORD PTR [esi],ecx
0x5437bf  8b5704                           mov    edx,DWORD PTR [edi+0x4]
0x5437c2  8bcb                             mov    ecx,ebx
0x5437c4  895604                           mov    DWORD PTR [esi+0x4],edx
0x5437c7  c783ac00000001000000             mov    DWORD PTR [ebx+0xac],0x1
0x5437d1  ff1534f8c000                     call   DWORD PTR ds:0xc0f834
0x5437d7  668b4d0c                         mov    cx,WORD PTR [ebp+0xc]
0x5437db  33d2                             xor    edx,edx
0x5437dd  6683f902                         cmp    cx,0x2
0x5437e1  0f8588000000                     jne    0x54386f
0x5437e7  0fbf7d10                         movsx  edi,WORD PTR [ebp+0x10]
0x5437eb  a1b41dfe00                       mov    eax,ds:0xfe1db4
0x5437f0  e81b81fbff                       call   0x4fb910
0x5437f5  85c0                             test   eax,eax
0x5437f7  7410                             je     0x543809
0x5437f9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x5437fc  8d48ff                           lea    ecx,[eax-0x1]
0x5437ff  83f903                           cmp    ecx,0x3
0x543802  7705                             ja     0x543809
0x543804  8d78ff                           lea    edi,[eax-0x1]
0x543807  eb02                             jmp    0x54380b
0x543809  33ff                             xor    edi,edi
0x54380b  f605dcf6fd0001                   test   BYTE PTR ds:0xfdf6dc,0x1
0x543812  7521                             jne    0x543835
0x543814  830ddcf6fd0001                   or     DWORD PTR ds:0xfdf6dc,0x1
0x54381b  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x54381f  e8fccf0000                       call   0x550820
0x543824  68b0e6bc00                       push   0xbce6b0
0x543829  e8ecea3400                       call   0x89231a
0x54382e  83c404                           add    esp,0x4
0x543831  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x543835  57                               push   edi
0x543836  6a00                             push   0x0
0x543838  b9c8f7c000                       mov    ecx,0xc0f7c8
0x54383d  ba80f6fd00                       mov    edx,0xfdf680
0x543842  e839e30000                       call   0x551b80
0x543847  d905f8c7c000                     fld    DWORD PTR ds:0xc0c7f8
0x54384d  6a00                             push   0x0
0x54384f  83ec08                           sub    esp,0x8
0x543852  d95c2404                         fstp   DWORD PTR [esp+0x4]
0x543856  8bc8                             mov    ecx,eax
0x543858  d9ee                             fldz
0x54385a  d91c24                           fstp   DWORD PTR [esp]
0x54385d  56                               push   esi
0x54385e  6a00                             push   0x0
0x543860  6880f6fd00                       push   0xfdf680
0x543865  e866e50000                       call   0x551dd0
0x54386a  e99f020000                       jmp    0x543b0e
0x54386f  663bca                           cmp    cx,dx
0x543872  0f8545020000                     jne    0x543abd
0x543878  80bbf800000000                   cmp    BYTE PTR [ebx+0xf8],0x0
0x54387f  d94514                           fld    DWORD PTR [ebp+0x14]
0x543882  dd05405cc500                     fld    QWORD PTR ds:0xc55c40

; checkpoint_market_interaction | category2 ShopNo -> NPC and F4388 event
; VA 0x544478..0x5444f1 raw 0x143878 length 121 sha256 2cf094a19e5d9e145d0213b3bfaa5e16828dcf98447a96377d54097b2659254b
0x544478  6683f802                         cmp    ax,0x2
0x54447c  0f85a7000000                     jne    0x544529
0x544482  0fb786f6000000                   movzx  eax,WORD PTR [esi+0xf6]
0x544489  0fbff8                           movsx  edi,ax
0x54448c  a1b41dfe00                       mov    eax,ds:0xfe1db4
0x544491  e87a74fbff                       call   0x4fb910
0x544496  8bf8                             mov    edi,eax
0x544498  85ff                             test   edi,edi
0x54449a  0f8473020000                     je     0x544713
0x5444a0  8b570c                           mov    edx,DWORD PTR [edi+0xc]
0x5444a3  8b35d01bfe00                     mov    esi,DWORD PTR ds:0xfe1bd0
0x5444a9  52                               push   edx
0x5444aa  e8612bfeff                       call   0x527010
0x5444af  85c0                             test   eax,eax
0x5444b1  0f845c020000                     je     0x544713
0x5444b7  8b4840                           mov    ecx,DWORD PTR [eax+0x40]
0x5444ba  3b4844                           cmp    ecx,DWORD PTR [eax+0x44]
0x5444bd  0f8450020000                     je     0x544713
0x5444c3  6a1c                             push   0x1c
0x5444c5  e89ecd3400                       call   0x891268
0x5444ca  8bf0                             mov    esi,eax
0x5444cc  83c404                           add    esp,0x4
0x5444cf  89742418                         mov    DWORD PTR [esp+0x18],esi
0x5444d3  895c2428                         mov    DWORD PTR [esp+0x28],ebx
0x5444d7  85f6                             test   esi,esi
0x5444d9  7418                             je     0x5444f3
0x5444db  e880abecff                       call   0x40f060
0x5444e0  8b808c000000                     mov    eax,DWORD PTR [eax+0x8c]
0x5444e6  8b570c                           mov    edx,DWORD PTR [edi+0xc]
0x5444e9  50                               push   eax
0x5444ea  8bc6                             mov    eax,esi
0x5444ec  e88ffa2000                       call   0x753f80

; checkpoint_npc_interaction | category3 NPC -> same talk UI event
; VA 0x54419b..0x5441f2 raw 0x14359b length 87 sha256 2509f9b1cf65d5e92f7004745a6f87b2e29cf8115237dad337e0192d8cfa4569
0x54419b  0f8472050000                     je     0x544713
0x5441a1  8b4840                           mov    ecx,DWORD PTR [eax+0x40]
0x5441a4  3b4844                           cmp    ecx,DWORD PTR [eax+0x44]
0x5441a7  0f8466050000                     je     0x544713
0x5441ad  6a1c                             push   0x1c
0x5441af  e8b4d03400                       call   0x891268
0x5441b4  8bf0                             mov    esi,eax
0x5441b6  83c404                           add    esp,0x4
0x5441b9  89742414                         mov    DWORD PTR [esp+0x14],esi
0x5441bd  c744242801000000                 mov    DWORD PTR [esp+0x28],0x1
0x5441c5  85f6                             test   esi,esi
0x5441c7  0f8426030000                     je     0x5444f3
0x5441cd  e88eaeecff                       call   0x40f060
0x5441d2  8b808c000000                     mov    eax,DWORD PTR [eax+0x8c]
0x5441d8  50                               push   eax
0x5441d9  8bd7                             mov    edx,edi
0x5441db  8bc6                             mov    eax,esi
0x5441dd  e89efd2000                       call   0x753f80
0x5441e2  e90e030000                       jmp    0x5444f5
0x5441e7  e8b409ecff                       call   0x404ba0
0x5441ec  8b804c5f0000                     mov    eax,DWORD PTR [eax+0x5f4c]

; shop_lookup_key | ShopNO exact key and row stride3C
; VA 0x4fb910..0x4fb960 raw 0xfad10 length 80 sha256 96ef6f592ce1f7136811710cc7dba4004897246f1406369276fd85bd4092b3a8
0x4fb910  56                               push   esi
0x4fb911  8bf0                             mov    esi,eax
0x4fb913  8b4e0c                           mov    ecx,DWORD PTR [esi+0xc]
0x4fb916  2b4e08                           sub    ecx,DWORD PTR [esi+0x8]
0x4fb919  b889888888                       mov    eax,0x88888889
0x4fb91e  f7e9                             imul   ecx
0x4fb920  03d1                             add    edx,ecx
0x4fb922  c1fa05                           sar    edx,0x5
0x4fb925  8bc2                             mov    eax,edx
0x4fb927  c1e81f                           shr    eax,0x1f
0x4fb92a  03c2                             add    eax,edx
0x4fb92c  b900000000                       mov    ecx,0x0
0x4fb931  7411                             je     0x4fb944
0x4fb933  8b7608                           mov    esi,DWORD PTR [esi+0x8]
0x4fb936  8bd6                             mov    edx,esi
0x4fb938  393a                             cmp    DWORD PTR [edx],edi
0x4fb93a  740c                             je     0x4fb948
0x4fb93c  41                               inc    ecx
0x4fb93d  83c23c                           add    edx,0x3c
0x4fb940  3bc8                             cmp    ecx,eax
0x4fb942  72f4                             jb     0x4fb938
0x4fb944  33c0                             xor    eax,eax
0x4fb946  5e                               pop    esi
0x4fb947  c3                               ret
0x4fb948  8bc1                             mov    eax,ecx
0x4fb94a  c1e004                           shl    eax,0x4
0x4fb94d  2bc1                             sub    eax,ecx
0x4fb94f  8d0486                           lea    eax,[esi+eax*4]
0x4fb952  5e                               pop    esi
0x4fb953  c3                               ret
0x4fb954  cc                               int3
0x4fb955  cc                               int3
0x4fb956  cc                               int3
0x4fb957  cc                               int3
0x4fb958  cc                               int3
0x4fb959  cc                               int3
0x4fb95a  cc                               int3
0x4fb95b  cc                               int3
0x4fb95c  cc                               int3
0x4fb95d  cc                               int3
0x4fb95e  cc                               int3
0x4fb95f  cc                               int3

; shop_lookup_town_npc | current Town and NPC pair lookup
; VA 0x4fb960..0x4fb9c0 raw 0xfad60 length 96 sha256 72e7e5197548379f681d1e42fe98a29073018101202c4f11558807c5356fa029
0x4fb960  55                               push   ebp
0x4fb961  8bec                             mov    ebp,esp
0x4fb963  53                               push   ebx
0x4fb964  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4fb967  56                               push   esi
0x4fb968  8bf0                             mov    esi,eax
0x4fb96a  8b4e0c                           mov    ecx,DWORD PTR [esi+0xc]
0x4fb96d  2b4e08                           sub    ecx,DWORD PTR [esi+0x8]
0x4fb970  b889888888                       mov    eax,0x88888889
0x4fb975  f7e9                             imul   ecx
0x4fb977  03d1                             add    edx,ecx
0x4fb979  c1fa05                           sar    edx,0x5
0x4fb97c  8bc2                             mov    eax,edx
0x4fb97e  c1e81f                           shr    eax,0x1f
0x4fb981  03c2                             add    eax,edx
0x4fb983  b900000000                       mov    ecx,0x0
0x4fb988  7417                             je     0x4fb9a1
0x4fb98a  8b7608                           mov    esi,DWORD PTR [esi+0x8]
0x4fb98d  8d560c                           lea    edx,[esi+0xc]
0x4fb990  395af8                           cmp    DWORD PTR [edx-0x8],ebx
0x4fb993  7504                             jne    0x4fb999
0x4fb995  393a                             cmp    DWORD PTR [edx],edi
0x4fb997  7410                             je     0x4fb9a9
0x4fb999  41                               inc    ecx
0x4fb99a  83c23c                           add    edx,0x3c
0x4fb99d  3bc8                             cmp    ecx,eax
0x4fb99f  72ef                             jb     0x4fb990
0x4fb9a1  5e                               pop    esi
0x4fb9a2  33c0                             xor    eax,eax
0x4fb9a4  5b                               pop    ebx
0x4fb9a5  5d                               pop    ebp
0x4fb9a6  c20400                           ret    0x4
0x4fb9a9  8bc1                             mov    eax,ecx
0x4fb9ab  c1e004                           shl    eax,0x4
0x4fb9ae  2bc1                             sub    eax,ecx
0x4fb9b0  8d0486                           lea    eax,[esi+eax*4]
0x4fb9b3  5e                               pop    esi
0x4fb9b4  5b                               pop    ebx
0x4fb9b5  5d                               pop    ebp
0x4fb9b6  c20400                           ret    0x4
0x4fb9b9  cc                               int3
0x4fb9ba  cc                               int3
0x4fb9bb  cc                               int3
0x4fb9bc  cc                               int3
0x4fb9bd  cc                               int3
0x4fb9be  cc                               int3
0x4fb9bf  cc                               int3

; shop_parser_fields | ShopInfo NO/TOWN/TYPE/NPC stored
; VA 0x4fbb6a..0x4fbc40 raw 0xfaf6a length 214 sha256 e5f019b280d5caa93d78eeaf8e9980eba2d44910b2b791c742cbf2fd4aa7c836
0x4fbb6a  8d7b44                           lea    edi,[ebx+0x44]
0x4fbb6d  682ccec000                       push   0xc0ce2c
0x4fbb72  c684245401000001                 mov    BYTE PTR [esp+0x154],0x1
0x4fbb7a  e821452300                       call   0x7300a0
0x4fbb7f  3bc6                             cmp    eax,esi
0x4fbb81  741a                             je     0x4fbb9d
0x4fbb83  83c030                           add    eax,0x30
0x4fbb86  83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x4fbb8a  7202                             jb     0x4fbb8e
0x4fbb8c  8b00                             mov    eax,DWORD PTR [eax]
0x4fbb8e  3bc6                             cmp    eax,esi
0x4fbb90  740b                             je     0x4fbb9d
0x4fbb92  50                               push   eax
0x4fbb93  e81c5c3900                       call   0x8917b4
0x4fbb98  83c404                           add    esp,0x4
0x4fbb9b  eb02                             jmp    0x4fbb9f
0x4fbb9d  33c0                             xor    eax,eax
0x4fbb9f  68ec67c000                       push   0xc067ec
0x4fbba4  89442458                         mov    DWORD PTR [esp+0x58],eax
0x4fbba8  e8f3442300                       call   0x7300a0
0x4fbbad  3bc6                             cmp    eax,esi
0x4fbbaf  741a                             je     0x4fbbcb
0x4fbbb1  83c030                           add    eax,0x30
0x4fbbb4  83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x4fbbb8  7202                             jb     0x4fbbbc
0x4fbbba  8b00                             mov    eax,DWORD PTR [eax]
0x4fbbbc  3bc6                             cmp    eax,esi
0x4fbbbe  740b                             je     0x4fbbcb
0x4fbbc0  50                               push   eax
0x4fbbc1  e8ee5b3900                       call   0x8917b4
0x4fbbc6  83c404                           add    esp,0x4
0x4fbbc9  eb02                             jmp    0x4fbbcd
0x4fbbcb  33c0                             xor    eax,eax
0x4fbbcd  6800b8bf00                       push   0xbfb800
0x4fbbd2  8944245c                         mov    DWORD PTR [esp+0x5c],eax
0x4fbbd6  e8c5442300                       call   0x7300a0
0x4fbbdb  3bc6                             cmp    eax,esi
0x4fbbdd  741a                             je     0x4fbbf9
0x4fbbdf  83c030                           add    eax,0x30
0x4fbbe2  83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x4fbbe6  7202                             jb     0x4fbbea
0x4fbbe8  8b00                             mov    eax,DWORD PTR [eax]
0x4fbbea  3bc6                             cmp    eax,esi
0x4fbbec  740b                             je     0x4fbbf9
0x4fbbee  50                               push   eax
0x4fbbef  e8c05b3900                       call   0x8917b4
0x4fbbf4  83c404                           add    esp,0x4
0x4fbbf7  eb02                             jmp    0x4fbbfb
0x4fbbf9  33c0                             xor    eax,eax
0x4fbbfb  683cd8c000                       push   0xc0d83c
0x4fbc00  89442460                         mov    DWORD PTR [esp+0x60],eax
0x4fbc04  e897442300                       call   0x7300a0
0x4fbc09  3bc6                             cmp    eax,esi
0x4fbc0b  741a                             je     0x4fbc27
0x4fbc0d  83c030                           add    eax,0x30
0x4fbc10  83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x4fbc14  7202                             jb     0x4fbc18
0x4fbc16  8b00                             mov    eax,DWORD PTR [eax]
0x4fbc18  3bc6                             cmp    eax,esi
0x4fbc1a  740b                             je     0x4fbc27
0x4fbc1c  50                               push   eax
0x4fbc1d  e8925b3900                       call   0x8917b4
0x4fbc22  83c404                           add    esp,0x4
0x4fbc25  eb02                             jmp    0x4fbc29
0x4fbc27  33c0                             xor    eax,eax
0x4fbc29  6a04                             push   0x4
0x4fbc2b  bf0f000000                       mov    edi,0xf
0x4fbc30  6830cec000                       push   0xc0ce30
0x4fbc35  8d8c2498000000                   lea    ecx,[esp+0x98]
0x4fbc3c  89442468                         mov    DWORD PTR [esp+0x68],eax

; shop_type_to_npc_type | only shop types1..4 => NPC type+10
; VA 0x4fbcfb..0x4fbd41 raw 0xfb0fb length 70 sha256 ae4e6ebabfb12676862caa1bb220f677ab353e3185bf5d79b1b53eb5ed8128e2
0x4fbcfb  89bc24ac000000                   mov    DWORD PTR [esp+0xac],edi
0x4fbd02  c78424a800000000000000           mov    DWORD PTR [esp+0xa8],0x0
0x4fbd0d  c684249800000000                 mov    BYTE PTR [esp+0x98],0x0
0x4fbd15  e846b20200                       call   0x526f60
0x4fbd1a  85c0                             test   eax,eax
0x4fbd1c  7413                             je     0x4fbd31
0x4fbd1e  8b4c245c                         mov    ecx,DWORD PTR [esp+0x5c]
0x4fbd22  85c9                             test   ecx,ecx
0x4fbd24  7e0b                             jle    0x4fbd31
0x4fbd26  83f904                           cmp    ecx,0x4
0x4fbd29  7f06                             jg     0x4fbd31
0x4fbd2b  83c10a                           add    ecx,0xa
0x4fbd2e  894820                           mov    DWORD PTR [eax+0x20],ecx
0x4fbd31  bf40d8c000                       mov    edi,0xc0d840
0x4fbd36  8bc3                             mov    eax,ebx
0x4fbd38  e823262300                       call   0x72e360
0x4fbd3d  89442424                         mov    DWORD PTR [esp+0x24],eax

; town_talk_consumer | F4388 typed consumer -> TalkBox mode0
; VA 0x5b6b70..0x5b6bc9 raw 0x1b5f70 length 89 sha256 865cd1e9d0f8cab2eabdf5371bddd1e7d28574a3e8073570ca0a386ebfaee94f
0x5b6b70  57                               push   edi
0x5b6b71  8bf8                             mov    edi,eax
0x5b6b73  85f6                             test   esi,esi
0x5b6b75  7428                             je     0x5b6b9f
0x5b6b77  8b06                             mov    eax,DWORD PTR [esi]
0x5b6b79  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x5b6b7c  8bce                             mov    ecx,esi
0x5b6b7e  ffd2                             call   edx
0x5b6b80  3dbe050100                       cmp    eax,0x105be
0x5b6b85  7504                             jne    0x5b6b8b
0x5b6b87  8bc6                             mov    eax,esi
0x5b6b89  eb16                             jmp    0x5b6ba1
0x5b6b8b  6a00                             push   0x0
0x5b6b8d  68c01fbf00                       push   0xbf1fc0
0x5b6b92  681821bf00                       push   0xbf2118
0x5b6b97  6a00                             push   0x0
0x5b6b99  ff158025bd00                     call   DWORD PTR ds:0xbd2580
0x5b6b9f  33c0                             xor    eax,eax
0x5b6ba1  8b4814                           mov    ecx,DWORD PTR [eax+0x14]
0x5b6ba4  8b9724020000                     mov    edx,DWORD PTR [edi+0x224]
0x5b6baa  6a00                             push   0x0
0x5b6bac  6a00                             push   0x0
0x5b6bae  51                               push   ecx
0x5b6baf  8b4818                           mov    ecx,DWORD PTR [eax+0x18]
0x5b6bb2  e869f90700                       call   0x636520
0x5b6bb7  8b9724020000                     mov    edx,DWORD PTR [edi+0x224]
0x5b6bbd  52                               push   edx
0x5b6bbe  e84d341900                       call   0x74a010
0x5b6bc3  8b8724020000                     mov    eax,DWORD PTR [edi+0x224]

; town_talk_dispatch | F4388 routing jump
; VA 0x5b7f80..0x5b7fc1 raw 0x1b7380 length 65 sha256 d1107833eef3619816d85fb1c26d7d6d94c61b471ba64a8be516846d2d978a3f
0x5b7f80  55                               push   ebp
0x5b7f81  8bec                             mov    ebp,esp
0x5b7f83  83ec08                           sub    esp,0x8
0x5b7f86  53                               push   ebx
0x5b7f87  56                               push   esi
0x5b7f88  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x5b7f8b  56                               push   esi
0x5b7f8c  8bd9                             mov    ebx,ecx
0x5b7f8e  e8ed3dfeff                       call   0x59bd80
0x5b7f93  8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x5b7f96  059cbcf0ff                       add    eax,0xfff0bc9c
0x5b7f9b  3ddb000000                       cmp    eax,0xdb
0x5b7fa0  0f87e3030000                     ja     0x5b8389
0x5b7fa6  0fb68060845b00                   movzx  eax,BYTE PTR [eax+0x5b8460]
0x5b7fad  57                               push   edi
0x5b7fae  ff248594835b00                   jmp    DWORD PTR [eax*4+0x5b8394]
0x5b7fb5  8bc3                             mov    eax,ebx
0x5b7fb7  e8b4ebffff                       call   0x5b6b70
0x5b7fbc  5f                               pop    edi
0x5b7fbd  5e                               pop    esi
0x5b7fbe  5b                               pop    ebx
0x5b7fbf  8be5                             mov    esp,ebp

; talkbox_town_products | talkbox current NPC/town options
; VA 0x6365b0..0x636630 raw 0x2359b0 length 128 sha256 8b3f1be67e6efd8942477e631b1bd2380ac19d8b4a10fda8d182a288b3c46186
0x6365b0  6a24                             push   0x24
0x6365b2  895c2430                         mov    DWORD PTR [esp+0x30],ebx
0x6365b6  e8adac2500                       call   0x891268
0x6365bb  83c404                           add    esp,0x4
0x6365be  3bc3                             cmp    eax,ebx
0x6365c0  0f8485010000                     je     0x63674b
0x6365c6  89442428                         mov    DWORD PTR [esp+0x28],eax
0x6365ca  8900                             mov    DWORD PTR [eax],eax
0x6365cc  8b442428                         mov    eax,DWORD PTR [esp+0x28]
0x6365d0  894004                           mov    DWORD PTR [eax+0x4],eax
0x6365d3  8b442428                         mov    eax,DWORD PTR [esp+0x28]
0x6365d7  894008                           mov    DWORD PTR [eax+0x8],eax
0x6365da  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x6365de  c6412001                         mov    BYTE PTR [ecx+0x20],0x1
0x6365e2  8b542428                         mov    edx,DWORD PTR [esp+0x28]
0x6365e6  c6422101                         mov    BYTE PTR [edx+0x21],0x1
0x6365ea  53                               push   ebx
0x6365eb  895c2444                         mov    DWORD PTR [esp+0x44],ebx
0x6365ef  8b8f84000000                     mov    ecx,DWORD PTR [edi+0x84]
0x6365f5  8b9780000000                     mov    edx,DWORD PTR [edi+0x80]
0x6365fb  8d442428                         lea    eax,[esp+0x28]
0x6365ff  50                               push   eax
0x636600  a1b41dfe00                       mov    eax,ds:0xfe1db4
0x636605  51                               push   ecx
0x636606  52                               push   edx
0x636607  50                               push   eax
0x636608  e8435cecff                       call   0x4fc250
0x63660d  395c242c                         cmp    DWORD PTR [esp+0x2c],ebx
0x636611  8b8790000000                     mov    eax,DWORD PTR [edi+0x90]
0x636617  0f95c1                           setne  cl
0x63661a  888f8c000000                     mov    BYTE PTR [edi+0x8c],cl
0x636620  83f803                           cmp    eax,0x3
0x636623  0f87e3000000                     ja     0x63670c
0x636629  ff248574676300                   jmp    DWORD PTR [eax*4+0x636774]

; talkbox_menu_type | NPC TYPE selects option list
; VA 0x6389ec..0x638ab2 raw 0x237dec length 198 sha256 117e681b4361faf11a5b8abaf7e322e1a736cc8ad12ad0a14e255613f6c3693b
0x6389ec  8d9eb0000000                     lea    ebx,[esi+0xb0]
0x6389f2  8bfb                             mov    edi,ebx
0x6389f4  e857ae1e00                       call   0x823850
0x6389f9  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x6389fc  8b3dd01bfe00                     mov    edi,DWORD PTR ds:0xfe1bd0
0x638a02  8d4d0c                           lea    ecx,[ebp+0xc]
0x638a05  89450c                           mov    DWORD PTR [ebp+0xc],eax
0x638a08  51                               push   ecx
0x638a09  8d4f08                           lea    ecx,[edi+0x8]
0x638a0c  8d45fc                           lea    eax,[ebp-0x4]
0x638a0f  e8acae2000                       call   0x8438c0
0x638a14  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x638a17  3b470c                           cmp    eax,DWORD PTR [edi+0xc]
0x638a1a  0f8494000000                     je     0x638ab4
0x638a20  8b7810                           mov    edi,DWORD PTR [eax+0x10]
0x638a23  85ff                             test   edi,edi
0x638a25  0f8489000000                     je     0x638ab4
0x638a2b  8a5720                           mov    dl,BYTE PTR [edi+0x20]
0x638a2e  8d86c8000000                     lea    eax,[esi+0xc8]
0x638a34  8d8e7c010000                     lea    ecx,[esi+0x17c]
0x638a3a  50                               push   eax
0x638a3b  8811                             mov    BYTE PTR [ecx],dl
0x638a3d  e8de1d0000                       call   0x63a820
0x638a42  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
0x638a45  2b08                             sub    ecx,DWORD PTR [eax]
0x638a47  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x638a4a  c1f902                           sar    ecx,0x2
0x638a4d  894df4                           mov    DWORD PTR [ebp-0xc],ecx
0x638a50  c7450c00000000                   mov    DWORD PTR [ebp+0xc],0x0
0x638a57  85c9                             test   ecx,ecx
0x638a59  7459                             je     0x638ab4
0x638a5b  eb09                             jmp    0x638a66
0x638a5d  8d4900                           lea    ecx,[ecx+0x0]
0x638a60  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x638a63  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0x638a66  8b08                             mov    ecx,DWORD PTR [eax]
0x638a68  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x638a6b  8b0491                           mov    eax,DWORD PTR [ecx+edx*4]
0x638a6e  8b74860c                         mov    esi,DWORD PTR [esi+eax*4+0xc]
0x638a72  33c0                             xor    eax,eax
0x638a74  394308                           cmp    DWORD PTR [ebx+0x8],eax
0x638a77  7415                             je     0x638a8e
0x638a79  8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0x638a7c  8d45fc                           lea    eax,[ebp-0x4]
0x638a7f  894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0x638a82  e8196ef0ff                       call   0x53f8a0
0x638a87  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x638a8a  8b420c                           mov    eax,DWORD PTR [edx+0xc]
0x638a8d  40                               inc    eax
0x638a8e  8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x638a91  8d7dec                           lea    edi,[ebp-0x14]
0x638a94  8bf3                             mov    esi,ebx
0x638a96  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x638a99  e88264f4ff                       call   0x57ef20
0x638a9e  50                               push   eax
0x638a9f  53                               push   ebx
0x638aa0  8d75e4                           lea    esi,[ebp-0x1c]
0x638aa3  e858671f00                       call   0x82f200
0x638aa8  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x638aab  40                               inc    eax
0x638aac  89450c                           mov    DWORD PTR [ebp+0xc],eax
0x638aaf  3b45f4                           cmp    eax,DWORD PTR [ebp-0xc]

; menu_blacksmith | NPC TYPE12 selects option29
; VA 0x637d40..0x637dc8 raw 0x237140 length 136 sha256 049db997c9b13ca5410ae6b29bd668e10165735ce8a0b55d8c7b07c7bdfa81f3
0x637d40  e86b6deaff                       call   0x4deab0
0x637d45  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x637d48  85c0                             test   eax,eax
0x637d4a  7406                             je     0x637d52
0x637d4c  c70027000000                     mov    DWORD PTR [eax],0x27
0x637d52  017e04                           add    DWORD PTR [esi+0x4],edi
0x637d55  bb04000000                       mov    ebx,0x4
0x637d5a  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
0x637d5d  50                               push   eax
0x637d5e  8d4df3                           lea    ecx,[ebp-0xd]
0x637d61  c745e41d000000                   mov    DWORD PTR [ebp-0x1c],0x1d
0x637d68  c645f30c                         mov    BYTE PTR [ebp-0xd],0xc
0x637d6c  e8ef290000                       call   0x63a760
0x637d71  8bf0                             mov    esi,eax
0x637d73  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x637d76  8d4de4                           lea    ecx,[ebp-0x1c]
0x637d79  3bc8                             cmp    ecx,eax
0x637d7b  732c                             jae    0x637da9
0x637d7d  8b0e                             mov    ecx,DWORD PTR [esi]
0x637d7f  8d55e4                           lea    edx,[ebp-0x1c]
0x637d82  3bca                             cmp    ecx,edx
0x637d84  7723                             ja     0x637da9
0x637d86  8bfa                             mov    edi,edx
0x637d88  2bf9                             sub    edi,ecx
0x637d8a  c1ff02                           sar    edi,0x2
0x637d8d  3b4608                           cmp    eax,DWORD PTR [esi+0x8]
0x637d90  7507                             jne    0x637d99
0x637d92  8bc6                             mov    eax,esi
0x637d94  e8176deaff                       call   0x4deab0
0x637d99  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x637d9c  85c0                             test   eax,eax
0x637d9e  7422                             je     0x637dc2
0x637da0  8b0e                             mov    ecx,DWORD PTR [esi]
0x637da2  8b14b9                           mov    edx,DWORD PTR [ecx+edi*4]
0x637da5  8910                             mov    DWORD PTR [eax],edx
0x637da7  eb19                             jmp    0x637dc2
0x637da9  3b4608                           cmp    eax,DWORD PTR [esi+0x8]
0x637dac  7507                             jne    0x637db5
0x637dae  8bc6                             mov    eax,esi
0x637db0  e8fb6ceaff                       call   0x4deab0
0x637db5  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x637db8  85c0                             test   eax,eax
0x637dba  7406                             je     0x637dc2
0x637dbc  c7001d000000                     mov    DWORD PTR [eax],0x1d
0x637dc2  015e04                           add    DWORD PTR [esi+0x4],ebx
0x637dc5  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]

; menu_enhance_delegate | operation29 slot+14C=639EF0
; VA 0x6387e8..0x63882e raw 0x237be8 length 70 sha256 9b91b8e2cefedf899c67a607e40081a9d375d262348de8e360a2e3eea4573089
0x6387e8  c7813c010000a09c6300             mov    DWORD PTR [ecx+0x13c],0x639ca0
0x6387f2  c78140010000e09c6300             mov    DWORD PTR [ecx+0x140],0x639ce0
0x6387fc  c78144010000209d6300             mov    DWORD PTR [ecx+0x144],0x639d20
0x638806  c78148010000b09e6300             mov    DWORD PTR [ecx+0x148],0x639eb0
0x638810  c7814c010000f09e6300             mov    DWORD PTR [ecx+0x14c],0x639ef0
0x63881a  c78150010000309f6300             mov    DWORD PTR [ecx+0x150],0x639f30
0x638824  c78154010000f0a06300             mov    DWORD PTR [ecx+0x154],0x63a0f0

; menu_click | control option dispatch
; VA 0x638de0..0x638e30 raw 0x2381e0 length 80 sha256 ef968183f71b951e28e073447f096366b4a78f38e65436e6b0cc9870f04f3709
0x638de0  55                               push   ebp
0x638de1  8bec                             mov    ebp,esp
0x638de3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x638de6  81781078050000                   cmp    DWORD PTR [eax+0x10],0x578
0x638ded  53                               push   ebx
0x638dee  8bd9                             mov    ebx,ecx
0x638df0  752d                             jne    0x638e1f
0x638df2  56                               push   esi
0x638df3  57                               push   edi
0x638df4  8db3d8000000                     lea    esi,[ebx+0xd8]
0x638dfa  bf29000000                       mov    edi,0x29
0x638dff  90                               nop
0x638e00  8b8e34ffffff                     mov    ecx,DWORD PTR [esi-0xcc]
0x638e06  8b5120                           mov    edx,DWORD PTR [ecx+0x20]
0x638e09  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x638e0c  3b5008                           cmp    edx,DWORD PTR [eax+0x8]
0x638e0f  7506                             jne    0x638e17
0x638e11  8b16                             mov    edx,DWORD PTR [esi]
0x638e13  8bcb                             mov    ecx,ebx
0x638e15  ffd2                             call   edx
0x638e17  83c604                           add    esi,0x4
0x638e1a  4f                               dec    edi
0x638e1b  75e3                             jne    0x638e00
0x638e1d  5f                               pop    edi
0x638e1e  5e                               pop    esi
0x638e1f  5b                               pop    ebx
0x638e20  5d                               pop    ebp
0x638e21  c20400                           ret    0x4
0x638e24  cc                               int3
0x638e25  cc                               int3
0x638e26  cc                               int3
0x638e27  cc                               int3
0x638e28  cc                               int3
0x638e29  cc                               int3
0x638e2a  cc                               int3
0x638e2b  cc                               int3
0x638e2c  cc                               int3
0x638e2d  cc                               int3
0x638e2e  cc                               int3
0x638e2f  cc                               int3

; open_enhance_event | post F42F6
; VA 0x639ef0..0x639f30 raw 0x2392f0 length 64 sha256 e8475af9b98f660d2668e0602f6eecb9c62bed1c51114eab3ce14b67df60c6b4
0x639ef0  56                               push   esi
0x639ef1  6a14                             push   0x14
0x639ef3  e870732500                       call   0x891268
0x639ef8  83c404                           add    esp,0x4
0x639efb  85c0                             test   eax,eax
0x639efd  7426                             je     0x639f25
0x639eff  83c9ff                           or     ecx,0xffffffff
0x639f02  8bf0                             mov    esi,eax
0x639f04  c7000c7bc400                     mov    DWORD PTR [eax],0xc47b0c
0x639f0a  894804                           mov    DWORD PTR [eax+0x4],ecx
0x639f0d  894808                           mov    DWORD PTR [eax+0x8],ecx
0x639f10  c7400c00000000                   mov    DWORD PTR [eax+0xc],0x0
0x639f17  c74010f6420f00                   mov    DWORD PTR [eax+0x10],0xf42f6
0x639f1e  e87dd3dcff                       call   0x4072a0
0x639f23  5e                               pop    esi
0x639f24  c3                               ret
0x639f25  33c0                             xor    eax,eax
0x639f27  8bf0                             mov    esi,eax
0x639f29  e872d3dcff                       call   0x4072a0
0x639f2e  5e                               pop    esi
0x639f2f  c3                               ret

; open_enhance_consumer | F42F6 branch -> window+264 show
; VA 0x5b7750..0x5b7821 raw 0x1b6b50 length 209 sha256 8e7289e5da6aa228b8557c99f6fc8a900577fb1e7feda48244740a580a8351b8
0x5b7750  55                               push   ebp
0x5b7751  8bec                             mov    ebp,esp
0x5b7753  53                               push   ebx
0x5b7754  56                               push   esi
0x5b7755  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x5b7758  56                               push   esi
0x5b7759  8bd9                             mov    ebx,ecx
0x5b775b  e8c03cfeff                       call   0x59b420
0x5b7760  8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x5b7763  0525bdf0ff                       add    eax,0xfff0bd25
0x5b7768  83f86e                           cmp    eax,0x6e
0x5b776b  0f8746030000                     ja     0x5b7ab7
0x5b7771  0fb680707b5b00                   movzx  eax,BYTE PTR [eax+0x5b7b70]
0x5b7778  57                               push   edi
0x5b7779  ff2485c07a5b00                   jmp    DWORD PTR [eax*4+0x5b7ac0]
0x5b7780  8bc3                             mov    eax,ebx
0x5b7782  e8b9130000                       call   0x5b8b40
0x5b7787  5f                               pop    edi
0x5b7788  5e                               pop    esi
0x5b7789  5b                               pop    ebx
0x5b778a  5d                               pop    ebp
0x5b778b  c20400                           ret    0x4
0x5b778e  8b8b80020000                     mov    ecx,DWORD PTR [ebx+0x280]
0x5b7794  51                               push   ecx
0x5b7795  53                               push   ebx
0x5b7796  e865f6fdff                       call   0x596e00
0x5b779b  5f                               pop    edi
0x5b779c  5e                               pop    esi
0x5b779d  5b                               pop    ebx
0x5b779e  5d                               pop    ebp
0x5b779f  c20400                           ret    0x4
0x5b77a2  8b9368020000                     mov    edx,DWORD PTR [ebx+0x268]
0x5b77a8  52                               push   edx
0x5b77a9  53                               push   ebx
0x5b77aa  e851f6fdff                       call   0x596e00
0x5b77af  5f                               pop    edi
0x5b77b0  5e                               pop    esi
0x5b77b1  5b                               pop    ebx
0x5b77b2  5d                               pop    ebp
0x5b77b3  c20400                           ret    0x4
0x5b77b6  8b836c020000                     mov    eax,DWORD PTR [ebx+0x26c]
0x5b77bc  50                               push   eax
0x5b77bd  53                               push   ebx
0x5b77be  e83df6fdff                       call   0x596e00
0x5b77c3  5f                               pop    edi
0x5b77c4  5e                               pop    esi
0x5b77c5  5b                               pop    ebx
0x5b77c6  5d                               pop    ebp
0x5b77c7  c20400                           ret    0x4
0x5b77ca  8b8b70020000                     mov    ecx,DWORD PTR [ebx+0x270]
0x5b77d0  51                               push   ecx
0x5b77d1  53                               push   ebx
0x5b77d2  e829f6fdff                       call   0x596e00
0x5b77d7  5f                               pop    edi
0x5b77d8  5e                               pop    esi
0x5b77d9  5b                               pop    ebx
0x5b77da  5d                               pop    ebp
0x5b77db  c20400                           ret    0x4
0x5b77de  8b9360020000                     mov    edx,DWORD PTR [ebx+0x260]
0x5b77e4  52                               push   edx
0x5b77e5  53                               push   ebx
0x5b77e6  e815f6fdff                       call   0x596e00
0x5b77eb  5f                               pop    edi
0x5b77ec  5e                               pop    esi
0x5b77ed  5b                               pop    ebx
0x5b77ee  5d                               pop    ebp
0x5b77ef  c20400                           ret    0x4
0x5b77f2  8b8364020000                     mov    eax,DWORD PTR [ebx+0x264]
0x5b77f8  50                               push   eax
0x5b77f9  53                               push   ebx
0x5b77fa  e801f6fdff                       call   0x596e00
0x5b77ff  5f                               pop    edi
0x5b7800  5e                               pop    esi
0x5b7801  5b                               pop    ebx
0x5b7802  5d                               pop    ebp
0x5b7803  c20400                           ret    0x4
0x5b7806  8bfb                             mov    edi,ebx
0x5b7808  e8030f0000                       call   0x5b8710
0x5b780d  5f                               pop    edi
0x5b780e  5e                               pop    esi
0x5b780f  5b                               pop    ebx
0x5b7810  5d                               pop    ebp
0x5b7811  c20400                           ret    0x4
0x5b7814  8b8b78020000                     mov    ecx,DWORD PTR [ebx+0x278]
0x5b781a  51                               push   ecx
0x5b781b  53                               push   ebx
0x5b781c  e8dff5fdff                       call   0x596e00

; open_trade_event | post F42EA
; VA 0x6392a0..0x639333 raw 0x2386a0 length 147 sha256 10abacbbb5b77d3ad3f03c8dd61f06f69029b155fe2a6960e07d9940e3a354ee
0x6392a0  55                               push   ebp
0x6392a1  8bec                             mov    ebp,esp
0x6392a3  6aff                             push   0xffffffff
0x6392a5  681e629400                       push   0x94621e
0x6392aa  64a100000000                     mov    eax,fs:0x0
0x6392b0  50                               push   eax
0x6392b1  51                               push   ecx
0x6392b2  56                               push   esi
0x6392b3  a1201fd600                       mov    eax,ds:0xd61f20
0x6392b8  33c5                             xor    eax,ebp
0x6392ba  50                               push   eax
0x6392bb  8d45f4                           lea    eax,[ebp-0xc]
0x6392be  64a300000000                     mov    fs:0x0,eax
0x6392c4  8bf1                             mov    esi,ecx
0x6392c6  8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x6392c9  81b88400000084280000             cmp    DWORD PTR [eax+0x84],0x2884
0x6392d3  753a                             jne    0x63930f
0x6392d5  b801000000                       mov    eax,0x1
0x6392da  84059cb2fa00                     test   BYTE PTR ds:0xfab29c,al
0x6392e0  7526                             jne    0x639308
0x6392e2  09059cb2fa00                     or     DWORD PTR ds:0xfab29c,eax
0x6392e8  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x6392ef  e86c6becff                       call   0x4ffe60
0x6392f4  6800cfbc00                       push   0xbccf00
0x6392f9  e81c902500                       call   0x89231a
0x6392fe  83c404                           add    esp,0x4
0x639301  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x639308  6a0f                             push   0xf
0x63930a  e84183ecff                       call   0x501650
0x63930f  6a1c                             push   0x1c
0x639311  e8527f2500                       call   0x891268
0x639316  83c404                           add    esp,0x4
0x639319  85c0                             test   eax,eax
0x63931b  7439                             je     0x639356
0x63931d  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0x639320  8b9184000000                     mov    edx,DWORD PTR [ecx+0x84]
0x639326  8b8980000000                     mov    ecx,DWORD PTR [ecx+0x80]
0x63932c  c74004ffffffff                   mov    DWORD PTR [eax+0x4],0xffffffff

; open_trade_consumer | copy event context and show trade UI
; VA 0x5b8540..0x5b85a0 raw 0x1b7940 length 96 sha256 5f7ef2d1ed9e1b6f48cbd6700f4178f6199d724df587b63bca13c7ab097ae076
0x5b8540  85ff                             test   edi,edi
0x5b8542  7428                             je     0x5b856c
0x5b8544  8b07                             mov    eax,DWORD PTR [edi]
0x5b8546  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x5b8549  8bcf                             mov    ecx,edi
0x5b854b  ffd2                             call   edx
0x5b854d  3dba050100                       cmp    eax,0x105ba
0x5b8552  7504                             jne    0x5b8558
0x5b8554  8bc7                             mov    eax,edi
0x5b8556  eb16                             jmp    0x5b856e
0x5b8558  6a00                             push   0x0
0x5b855a  68c01fbf00                       push   0xbf1fc0
0x5b855f  681821bf00                       push   0xbf2118
0x5b8564  6a00                             push   0x0
0x5b8566  ff158025bd00                     call   DWORD PTR ds:0xbd2580
0x5b856c  33c0                             xor    eax,eax
0x5b856e  8b5018                           mov    edx,DWORD PTR [eax+0x18]
0x5b8571  8b8e54020000                     mov    ecx,DWORD PTR [esi+0x254]
0x5b8577  8b4014                           mov    eax,DWORD PTR [eax+0x14]
0x5b857a  8981f4000000                     mov    DWORD PTR [ecx+0xf4],eax
0x5b8580  8991f8000000                     mov    DWORD PTR [ecx+0xf8],edx
0x5b8586  8b8e54020000                     mov    ecx,DWORD PTR [esi+0x254]
0x5b858c  51                               push   ecx
0x5b858d  56                               push   esi
0x5b858e  e86de8fdff                       call   0x596e00
0x5b8593  c3                               ret
0x5b8594  cc                               int3
0x5b8595  cc                               int3
0x5b8596  cc                               int3
0x5b8597  cc                               int3
0x5b8598  cc                               int3
0x5b8599  cc                               int3
0x5b859a  cc                               int3
0x5b859b  cc                               int3
0x5b859c  cc                               int3
0x5b859d  cc                               int3
0x5b859e  cc                               int3
0x5b859f  cc                               int3

; trade_open_request | trade window reads town/NPC -> opens type-specific service request
; VA 0x683d30..0x683e14 raw 0x283130 length 228 sha256 e9943e23446c0af737d61e2297b3e29569e8379865d233c816e31a07febdc398
0x683d30  55                               push   ebp
0x683d31  8bec                             mov    ebp,esp
0x683d33  83e4f8                           and    esp,0xfffffff8
0x683d36  83ec14                           sub    esp,0x14
0x683d39  53                               push   ebx
0x683d3a  56                               push   esi
0x683d3b  57                               push   edi
0x683d3c  8bd9                             mov    ebx,ecx
0x683d3e  e87d1c0c00                       call   0x7459c0
0x683d43  f6432810                         test   BYTE PTR [ebx+0x28],0x10
0x683d47  7404                             je     0x683d4d
0x683d49  8bc3                             mov    eax,ebx
0x683d4b  eb0c                             jmp    0x683d59
0x683d4d  8b4360                           mov    eax,DWORD PTR [ebx+0x60]
0x683d50  85c0                             test   eax,eax
0x683d52  7421                             je     0x683d75
0x683d54  e8c71e0c00                       call   0x745c20
0x683d59  85c0                             test   eax,eax
0x683d5b  7418                             je     0x683d75
0x683d5d  8b7860                           mov    edi,DWORD PTR [eax+0x60]
0x683d60  85ff                             test   edi,edi
0x683d62  7411                             je     0x683d75
0x683d64  8b4828                           mov    ecx,DWORD PTR [eax+0x28]
0x683d67  c1e90c                           shr    ecx,0xc
0x683d6a  f6c101                           test   cl,0x1
0x683d6d  7506                             jne    0x683d75
0x683d6f  50                               push   eax
0x683d70  e89b620c00                       call   0x74a010
0x683d75  8b93f4000000                     mov    edx,DWORD PTR [ebx+0xf4]
0x683d7b  8bbbf8000000                     mov    edi,DWORD PTR [ebx+0xf8]
0x683d81  a1b41dfe00                       mov    eax,ds:0xfe1db4
0x683d86  52                               push   edx
0x683d87  c783fc00000000000000             mov    DWORD PTR [ebx+0xfc],0x0
0x683d91  c78344010000ffffffff             mov    DWORD PTR [ebx+0x144],0xffffffff
0x683d9b  e8c07be7ff                       call   0x4fb960
0x683da0  85c0                             test   eax,eax
0x683da2  0f84f1010000                     je     0x683f99
0x683da8  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x683dab  8d7808                           lea    edi,[eax+0x8]
0x683dae  83c1fb                           add    ecx,0xfffffffb
0x683db1  897c2414                         mov    DWORD PTR [esp+0x14],edi
0x683db5  83f902                           cmp    ecx,0x2
0x683db8  7713                             ja     0x683dcd
0x683dba  e8c108d9ff                       call   0x414680
0x683dbf  8b83f8000000                     mov    eax,DWORD PTR [ebx+0xf8]
0x683dc5  50                               push   eax
0x683dc6  e815f9e1ff                       call   0x4a36e0
0x683dcb  eb2f                             jmp    0x683dfc
0x683dcd  833d98a7fb0000                   cmp    DWORD PTR ds:0xfba798,0x0
0x683dd4  668b00                           mov    ax,WORD PTR [eax]
0x683dd7  c74424181c000200                 mov    DWORD PTR [esp+0x18],0x2001c
0x683ddf  668944241c                       mov    WORD PTR [esp+0x1c],ax
0x683de4  7516                             jne    0x683dfc
0x683de6  8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x683dec  8b11                             mov    edx,DWORD PTR [ecx]
0x683dee  8b5210                           mov    edx,DWORD PTR [edx+0x10]
0x683df1  6a06                             push   0x6
0x683df3  8d44241c                         lea    eax,[esp+0x1c]
0x683df7  50                               push   eax
0x683df8  6a00                             push   0x0
0x683dfa  ffd2                             call   edx
0x683dfc  33f6                             xor    esi,esi
0x683dfe  8bff                             mov    edi,edi
0x683e00  8b8300010000                     mov    eax,DWORD PTR [ebx+0x100]
0x683e06  50                               push   eax
0x683e07  8bc6                             mov    eax,esi
0x683e09  e8026cd8ff                       call   0x40aa10
0x683e0e  8b8b1c010000                     mov    ecx,DWORD PTR [ebx+0x11c]

; trade_context | shop TYPE -> request context enum
; VA 0x681e10..0x681e81 raw 0x281210 length 113 sha256 1eb0ae9cadf83009cb7fd40daa51310f75728ac68da1624258606e6f80c664db
0x681e10  55                               push   ebp
0x681e11  8bec                             mov    ebp,esp
0x681e13  6aff                             push   0xffffffff
0x681e15  68c22c9400                       push   0x942cc2
0x681e1a  64a100000000                     mov    eax,fs:0x0
0x681e20  50                               push   eax
0x681e21  83ec24                           sub    esp,0x24
0x681e24  53                               push   ebx
0x681e25  56                               push   esi
0x681e26  57                               push   edi
0x681e27  a1201fd600                       mov    eax,ds:0xd61f20
0x681e2c  33c5                             xor    eax,ebp
0x681e2e  50                               push   eax
0x681e2f  8d45f4                           lea    eax,[ebp-0xc]
0x681e32  64a300000000                     mov    fs:0x0,eax
0x681e38  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x681e3b  8bf2                             mov    esi,edx
0x681e3d  8dbed4000000                     lea    edi,[esi+0xd4]
0x681e43  8986cc000000                     mov    DWORD PTR [esi+0xcc],eax
0x681e49  890f                             mov    DWORD PTR [edi],ecx
0x681e4b  c786d000000001000000             mov    DWORD PTR [esi+0xd0],0x1
0x681e55  83f806                           cmp    eax,0x6
0x681e58  750c                             jne    0x681e66
0x681e5a  c786d000000003000000             mov    DWORD PTR [esi+0xd0],0x3
0x681e64  eb0f                             jmp    0x681e75
0x681e66  83f805                           cmp    eax,0x5
0x681e69  750a                             jne    0x681e75
0x681e6b  c786d000000004000000             mov    DWORD PTR [esi+0xd0],0x4
0x681e75  8b96d8000000                     mov    edx,DWORD PTR [esi+0xd8]
0x681e7b  8b86d0000000                     mov    eax,DWORD PTR [esi+0xd0]

; buy_request | C2S0027 serializer
; VA 0x4a3720..0x4a37b0 raw 0xa2b20 length 144 sha256 b9f1c2cdef8b0e8a0c8fd4b4d2fbd24b9dcc0b06a836cf72c675dc70719aba7e
0x4a3720  55                               push   ebp
0x4a3721  8bec                             mov    ebp,esp
0x4a3723  b808100000                       mov    eax,0x1008
0x4a3728  e843cf4000                       call   0x8b0670
0x4a372d  a1201fd600                       mov    eax,ds:0xd61f20
0x4a3732  33c5                             xor    eax,ebp
0x4a3734  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4a3737  33c0                             xor    eax,eax
0x4a3739  b803000000                       mov    eax,0x3
0x4a373e  b927000000                       mov    ecx,0x27
0x4a3743  66898df8efffff                   mov    WORD PTR [ebp-0x1008],cx
0x4a374a  8a4d08                           mov    cl,BYTE PTR [ebp+0x8]
0x4a374d  8d5005                           lea    edx,[eax+0x5]
0x4a3750  888dfaefffff                     mov    BYTE PTR [ebp-0x1006],cl
0x4a3756  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x4a3759  81fa00100000                     cmp    edx,0x1000
0x4a375f  771b                             ja     0x4a377c
0x4a3761  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x4a3764  8a5510                           mov    dl,BYTE PTR [ebp+0x10]
0x4a3767  8d8405f8efffff                   lea    eax,[ebp+eax*1-0x1008]
0x4a376e  8908                             mov    DWORD PTR [eax],ecx
0x4a3770  885004                           mov    BYTE PTR [eax+0x4],dl
0x4a3773  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0x4a3776  83c005                           add    eax,0x5
0x4a3779  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x4a377c  83f803                           cmp    eax,0x3
0x4a377f  7617                             jbe    0x4a3798
0x4a3781  8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x4a3787  8b11                             mov    edx,DWORD PTR [ecx]
0x4a3789  8b5210                           mov    edx,DWORD PTR [edx+0x10]
0x4a378c  50                               push   eax
0x4a378d  8d85f8efffff                     lea    eax,[ebp-0x1008]
0x4a3793  50                               push   eax
0x4a3794  6a00                             push   0x0
0x4a3796  ffd2                             call   edx
0x4a3798  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0x4a379b  33cd                             xor    ecx,ebp
0x4a379d  e85fd83e00                       call   0x891001
0x4a37a2  8be5                             mov    esp,ebp
0x4a37a4  5d                               pop    ebp
0x4a37a5  c20c00                           ret    0xc
0x4a37a8  cc                               int3
0x4a37a9  cc                               int3
0x4a37aa  cc                               int3
0x4a37ab  cc                               int3
0x4a37ac  cc                               int3
0x4a37ad  cc                               int3
0x4a37ae  cc                               int3
0x4a37af  cc                               int3

; sell_request | C2S0020 serializer
; VA 0x4a37b0..0x4a3840 raw 0xa2bb0 length 144 sha256 d0a9ca061fb292165fe9a6912e5395c64c87cb0bf5464379d800621e49f26a0d
0x4a37b0  55                               push   ebp
0x4a37b1  8bec                             mov    ebp,esp
0x4a37b3  b808100000                       mov    eax,0x1008
0x4a37b8  e8b3ce4000                       call   0x8b0670
0x4a37bd  a1201fd600                       mov    eax,ds:0xd61f20
0x4a37c2  33c5                             xor    eax,ebp
0x4a37c4  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4a37c7  33c0                             xor    eax,eax
0x4a37c9  b920000000                       mov    ecx,0x20
0x4a37ce  b802000000                       mov    eax,0x2
0x4a37d3  66898df8efffff                   mov    WORD PTR [ebp-0x1008],cx
0x4a37da  8d4803                           lea    ecx,[eax+0x3]
0x4a37dd  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x4a37e0  81f900100000                     cmp    ecx,0x1000
0x4a37e6  771d                             ja     0x4a3805
0x4a37e8  668b5508                         mov    dx,WORD PTR [ebp+0x8]
0x4a37ec  8a4d0a                           mov    cl,BYTE PTR [ebp+0xa]
0x4a37ef  8d8405f8efffff                   lea    eax,[ebp+eax*1-0x1008]
0x4a37f6  668910                           mov    WORD PTR [eax],dx
0x4a37f9  884802                           mov    BYTE PTR [eax+0x2],cl
0x4a37fc  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0x4a37ff  83c003                           add    eax,0x3
0x4a3802  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x4a3805  83f802                           cmp    eax,0x2
0x4a3808  7617                             jbe    0x4a3821
0x4a380a  8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x4a3810  8b11                             mov    edx,DWORD PTR [ecx]
0x4a3812  8b5210                           mov    edx,DWORD PTR [edx+0x10]
0x4a3815  50                               push   eax
0x4a3816  8d85f8efffff                     lea    eax,[ebp-0x1008]
0x4a381c  50                               push   eax
0x4a381d  6a00                             push   0x0
0x4a381f  ffd2                             call   edx
0x4a3821  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0x4a3824  33cd                             xor    ecx,ebp
0x4a3826  e8d6d73e00                       call   0x891001
0x4a382b  8be5                             mov    esp,ebp
0x4a382d  5d                               pop    ebp
0x4a382e  c20400                           ret    0x4
0x4a3831  cc                               int3
0x4a3832  cc                               int3
0x4a3833  cc                               int3
0x4a3834  cc                               int3
0x4a3835  cc                               int3
0x4a3836  cc                               int3
0x4a3837  cc                               int3
0x4a3838  cc                               int3
0x4a3839  cc                               int3
0x4a383a  cc                               int3
0x4a383b  cc                               int3
0x4a383c  cc                               int3
0x4a383d  cc                               int3
0x4a383e  cc                               int3
0x4a383f  cc                               int3

; enhance_request | C2S00A1 serializer
; VA 0x4a3bf0..0x4a3c50 raw 0xa2ff0 length 96 sha256 534305f46220a85562142d783bbdba02a1ffdd66c805a0e25b95ccac2d64652c
0x4a3bf0  55                               push   ebp
0x4a3bf1  8bec                             mov    ebp,esp
0x4a3bf3  83ec0c                           sub    esp,0xc
0x4a3bf6  833d98a7fb0000                   cmp    DWORD PTR ds:0xfba798,0x0
0x4a3bfd  8a4d08                           mov    cl,BYTE PTR [ebp+0x8]
0x4a3c00  8a550c                           mov    dl,BYTE PTR [ebp+0xc]
0x4a3c03  b8a1000000                       mov    eax,0xa1
0x4a3c08  668945f4                         mov    WORD PTR [ebp-0xc],ax
0x4a3c0c  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x4a3c0f  884df6                           mov    BYTE PTR [ebp-0xa],cl
0x4a3c12  8a4d14                           mov    cl,BYTE PTR [ebp+0x14]
0x4a3c15  8855f7                           mov    BYTE PTR [ebp-0x9],dl
0x4a3c18  8a5518                           mov    dl,BYTE PTR [ebp+0x18]
0x4a3c1b  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x4a3c1e  884dfc                           mov    BYTE PTR [ebp-0x4],cl
0x4a3c21  8855fd                           mov    BYTE PTR [ebp-0x3],dl
0x4a3c24  7515                             jne    0x4a3c3b
0x4a3c26  8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x4a3c2c  8b01                             mov    eax,DWORD PTR [ecx]
0x4a3c2e  8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4a3c31  6a0a                             push   0xa
0x4a3c33  8d55f4                           lea    edx,[ebp-0xc]
0x4a3c36  52                               push   edx
0x4a3c37  6a00                             push   0x0
0x4a3c39  ffd0                             call   eax
0x4a3c3b  8be5                             mov    esp,ebp
0x4a3c3d  5d                               pop    ebp
0x4a3c3e  c21400                           ret    0x14
0x4a3c41  cc                               int3
0x4a3c42  cc                               int3
0x4a3c43  cc                               int3
0x4a3c44  cc                               int3
0x4a3c45  cc                               int3
0x4a3c46  cc                               int3
0x4a3c47  cc                               int3
0x4a3c48  cc                               int3
0x4a3c49  cc                               int3
0x4a3c4a  cc                               int3
0x4a3c4b  cc                               int3
0x4a3c4c  cc                               int3
0x4a3c4d  cc                               int3
0x4a3c4e  cc                               int3
0x4a3c4f  cc                               int3

; trade_feedback | S2C0030 buy/sell success/failure presentation flags
; VA 0x4b3760..0x4b38a0 raw 0xb2b60 length 320 sha256 2c8a83fc68f4740e430e4ae664edb1aae6a0d92a1e4150130237f98a35acda97
0x4b3760  55                               push   ebp
0x4b3761  8bec                             mov    ebp,esp
0x4b3763  6aff                             push   0xffffffff
0x4b3765  68240d9300                       push   0x930d24
0x4b376a  64a100000000                     mov    eax,fs:0x0
0x4b3770  50                               push   eax
0x4b3771  83ec48                           sub    esp,0x48
0x4b3774  a1201fd600                       mov    eax,ds:0xd61f20
0x4b3779  33c5                             xor    eax,ebp
0x4b377b  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4b377e  56                               push   esi
0x4b377f  57                               push   edi
0x4b3780  50                               push   eax
0x4b3781  8d45f4                           lea    eax,[ebp-0xc]
0x4b3784  64a300000000                     mov    fs:0x0,eax
0x4b378a  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4b378d  0fb74002                         movzx  eax,WORD PTR [eax+0x2]
0x4b3791  a810                             test   al,0x10
0x4b3793  0f84ab020000                     je     0x4b3a44
0x4b3799  a801                             test   al,0x1
0x4b379b  0f84b9010000                     je     0x4b395a
0x4b37a1  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x4b37a8  7527                             jne    0x4b37d1
0x4b37aa  830dd4adfa0001                   or     DWORD PTR ds:0xfaadd4,0x1
0x4b37b1  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4b37b8  e8c33c0d00                       call   0x587480
0x4b37bd  68c0ccbc00                       push   0xbcccc0
0x4b37c2  e853eb3d00                       call   0x89231a
0x4b37c7  83c404                           add    esp,0x4
0x4b37ca  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4b37d1  6a00                             push   0x0
0x4b37d3  6a00                             push   0x0
0x4b37d5  c745ac96010000                   mov    DWORD PTR [ebp-0x54],0x196
0x4b37dc  e8cf1c0d00                       call   0x5854b0
0x4b37e1  8bf0                             mov    esi,eax
0x4b37e3  8d4dac                           lea    ecx,[ebp-0x54]
0x4b37e6  51                               push   ecx
0x4b37e7  8d45b4                           lea    eax,[ebp-0x4c]
0x4b37ea  8bce                             mov    ecx,esi
0x4b37ec  e8ff080c00                       call   0x5740f0
0x4b37f1  8b7604                           mov    esi,DWORD PTR [esi+0x4]
0x4b37f4  8b45b4                           mov    eax,DWORD PTR [ebp-0x4c]
0x4b37f7  3bc6                             cmp    eax,esi
0x4b37f9  740d                             je     0x4b3808
0x4b37fb  83782408                         cmp    DWORD PTR [eax+0x24],0x8
0x4b37ff  8d5010                           lea    edx,[eax+0x10]
0x4b3802  720a                             jb     0x4b380e
0x4b3804  8b12                             mov    edx,DWORD PTR [edx]
0x4b3806  eb06                             jmp    0x4b380e
0x4b3808  cc                               int3
0x4b3809  bafcd1be00                       mov    edx,0xbed1fc
0x4b380e  83ec1c                           sub    esp,0x1c
0x4b3811  8bcc                             mov    ecx,esp
0x4b3813  33c0                             xor    eax,eax
0x4b3815  c7411407000000                   mov    DWORD PTR [ecx+0x14],0x7
0x4b381c  c7411000000000                   mov    DWORD PTR [ecx+0x10],0x0
0x4b3823  668901                           mov    WORD PTR [ecx],ax
0x4b3826  8bc2                             mov    eax,edx
0x4b3828  8965b0                           mov    DWORD PTR [ebp-0x50],esp
0x4b382b  8d7802                           lea    edi,[eax+0x2]
0x4b382e  8bff                             mov    edi,edi
0x4b3830  668b30                           mov    si,WORD PTR [eax]
0x4b3833  83c002                           add    eax,0x2
0x4b3836  6685f6                           test   si,si
0x4b3839  75f5                             jne    0x4b3830
0x4b383b  2bc7                             sub    eax,edi
0x4b383d  d1f8                             sar    eax,1
0x4b383f  50                               push   eax
0x4b3840  52                               push   edx
0x4b3841  e81ae9f4ff                       call   0x402160
0x4b3846  c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
0x4b384d  c745b4df000000                   mov    DWORD PTR [ebp-0x4c],0xdf
0x4b3854  e8571c0d00                       call   0x5854b0
0x4b3859  8bf0                             mov    esi,eax
0x4b385b  8d4db4                           lea    ecx,[ebp-0x4c]
0x4b385e  51                               push   ecx
0x4b385f  8d45ac                           lea    eax,[ebp-0x54]
0x4b3862  8bce                             mov    ecx,esi
0x4b3864  e887080c00                       call   0x5740f0
0x4b3869  8b7604                           mov    esi,DWORD PTR [esi+0x4]
0x4b386c  8b45ac                           mov    eax,DWORD PTR [ebp-0x54]
0x4b386f  3bc6                             cmp    eax,esi
0x4b3871  740d                             je     0x4b3880
0x4b3873  83782408                         cmp    DWORD PTR [eax+0x24],0x8
0x4b3877  8d5010                           lea    edx,[eax+0x10]
0x4b387a  720a                             jb     0x4b3886
0x4b387c  8b12                             mov    edx,DWORD PTR [edx]
0x4b387e  eb06                             jmp    0x4b3886
0x4b3880  cc                               int3
0x4b3881  bafcd1be00                       mov    edx,0xbed1fc
0x4b3886  83ec1c                           sub    esp,0x1c
0x4b3889  8bcc                             mov    ecx,esp
0x4b388b  33c0                             xor    eax,eax
0x4b388d  c7411407000000                   mov    DWORD PTR [ecx+0x14],0x7
0x4b3894  c7411000000000                   mov    DWORD PTR [ecx+0x10],0x0
0x4b389b  668901                           mov    WORD PTR [ecx],ax
0x4b389e  8bc2                             mov    eax,edx

; enhance_result_bridge | 00D9 result signed byte -> F427C
; VA 0x4dd060..0x4dd0f3 raw 0xdc460 length 147 sha256 781b2355d779c067aa82c429bd0026635f95920b6b8c5b6af7ec101251662947
0x4dd060  55                               push   ebp
0x4dd061  8bec                             mov    ebp,esp
0x4dd063  6aff                             push   0xffffffff
0x4dd065  684c4e9200                       push   0x924e4c
0x4dd06a  64a100000000                     mov    eax,fs:0x0
0x4dd070  50                               push   eax
0x4dd071  53                               push   ebx
0x4dd072  56                               push   esi
0x4dd073  57                               push   edi
0x4dd074  a1201fd600                       mov    eax,ds:0xd61f20
0x4dd079  33c5                             xor    eax,ebp
0x4dd07b  50                               push   eax
0x4dd07c  8d45f4                           lea    eax,[ebp-0xc]
0x4dd07f  64a300000000                     mov    fs:0x0,eax
0x4dd085  bb01000000                       mov    ebx,0x1
0x4dd08a  33f6                             xor    esi,esi
0x4dd08c  83cfff                           or     edi,0xffffffff
0x4dd08f  841dd4adfa00                     test   BYTE PTR ds:0xfaadd4,bl
0x4dd095  751e                             jne    0x4dd0b5
0x4dd097  091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
0x4dd09d  8975fc                           mov    DWORD PTR [ebp-0x4],esi
0x4dd0a0  e8dba30a00                       call   0x587480
0x4dd0a5  68c0ccbc00                       push   0xbcccc0
0x4dd0aa  e86b523b00                       call   0x89231a
0x4dd0af  83c404                           add    esp,0x4
0x4dd0b2  897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4dd0b5  6a18                             push   0x18
0x4dd0b7  e8ac413b00                       call   0x891268
0x4dd0bc  83c404                           add    esp,0x4
0x4dd0bf  3bc6                             cmp    eax,esi
0x4dd0c1  7422                             je     0x4dd0e5
0x4dd0c3  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4dd0c6  0fbe4902                         movsx  ecx,BYTE PTR [ecx+0x2]
0x4dd0ca  89700c                           mov    DWORD PTR [eax+0xc],esi
0x4dd0cd  897804                           mov    DWORD PTR [eax+0x4],edi
0x4dd0d0  897808                           mov    DWORD PTR [eax+0x8],edi
0x4dd0d3  c740107c420f00                   mov    DWORD PTR [eax+0x10],0xf427c
0x4dd0da  c700ac67c400                     mov    DWORD PTR [eax],0xc467ac
0x4dd0e0  894814                           mov    DWORD PTR [eax+0x14],ecx
0x4dd0e3  8bf0                             mov    esi,eax
0x4dd0e5  841dd0adfa00                     test   BYTE PTR ds:0xfaadd0,bl
0x4dd0eb  751e                             jne    0x4dd10b
0x4dd0ed  091dd0adfa00                     or     DWORD PTR ds:0xfaadd0,ebx

; enhance_result_ui | enhancement feedback success branch
; VA 0x686f40..0x687030 raw 0x286340 length 240 sha256 423fa7d7cc1f3375086fa60f4c08f12e0f15ae1b37d058b90784dac0d94279ab
0x686f40  55                               push   ebp
0x686f41  8bec                             mov    ebp,esp
0x686f43  6aff                             push   0xffffffff
0x686f45  68942b9300                       push   0x932b94
0x686f4a  64a100000000                     mov    eax,fs:0x0
0x686f50  50                               push   eax
0x686f51  83ec3c                           sub    esp,0x3c
0x686f54  a1201fd600                       mov    eax,ds:0xd61f20
0x686f59  33c5                             xor    eax,ebp
0x686f5b  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x686f5e  53                               push   ebx
0x686f5f  56                               push   esi
0x686f60  57                               push   edi
0x686f61  50                               push   eax
0x686f62  8d45f4                           lea    eax,[ebp-0xc]
0x686f65  64a300000000                     mov    fs:0x0,eax
0x686f6b  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x686f6e  33db                             xor    ebx,ebx
0x686f70  8bf9                             mov    edi,ecx
0x686f72  3bc3                             cmp    eax,ebx
0x686f74  0f8597000000                     jne    0x687011
0x686f7a  8bb744010000                     mov    esi,DWORD PTR [edi+0x144]
0x686f80  d986a0000000                     fld    DWORD PTR [esi+0xa0]
0x686f86  0f57c0                           xorps  xmm0,xmm0
0x686f89  d99e98000000                     fstp   DWORD PTR [esi+0x98]
0x686f8f  c7869400000002000000             mov    DWORD PTR [esi+0x94],0x2
0x686f99  899ea8000000                     mov    DWORD PTR [esi+0xa8],ebx
0x686f9f  f30f1186b0000000                 movss  DWORD PTR [esi+0xb0],xmm0
0x686fa7  f30f118690000000                 movss  DWORD PTR [esi+0x90],xmm0
0x686faf  e8dc350000                       call   0x68a590
0x686fb4  68e02bbf00                       push   0xbf2be0
0x686fb9  8d4316                           lea    eax,[ebx+0x16]
0x686fbc  8d4dd4                           lea    ecx,[ebp-0x2c]
0x686fbf  c745e80f000000                   mov    DWORD PTR [ebp-0x18],0xf
0x686fc6  895de4                           mov    DWORD PTR [ebp-0x1c],ebx
0x686fc9  885dd4                           mov    BYTE PTR [ebp-0x2c],bl
0x686fcc  e83f43d8ff                       call   0x40b310
0x686fd1  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x686fd4  f605d4b0fa0001                   test   BYTE PTR ds:0xfab0d4,0x1
0x686fdb  7520                             jne    0x686ffd
0x686fdd  830dd4b0fa0001                   or     DWORD PTR ds:0xfab0d4,0x1
0x686fe4  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x686fe8  e8b3331800                       call   0x80a3a0
0x686fed  68d0cdbc00                       push   0xbccdd0
0x686ff2  e823b32000                       call   0x89231a
0x686ff7  83c404                           add    esp,0x4
0x686ffa  885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x686ffd  6828b0fa00                       push   0xfab028
0x687002  8d4dd4                           lea    ecx,[ebp-0x2c]
0x687005  e8f63a1800                       call   0x80ab00
0x68700a  3bc3                             cmp    eax,ebx
0x68700c  e948020000                       jmp    0x687259
0x687011  83f801                           cmp    eax,0x1
0x687014  0f84a3010000                     je     0x6871bd
0x68701a  83f80c                           cmp    eax,0xc
0x68701d  0f849a010000                     je     0x6871bd
0x687023  bb02000000                       mov    ebx,0x2
0x687028  3bc3                             cmp    eax,ebx
0x68702a  751d                             jne    0x687049
0x68702c  6a00                             push   0x0
0x68702e  6a00                             push   0x0

; asset_update_balance | S2C002C authoritative displayed balances
; VA 0x509ce0..0x509d81 raw 0x1090e0 length 161 sha256 7bb453639b8cf573e06fa4bc04b94f01b539ad381d24426c8066f11dd0b5b83e
0x509ce0  55                               push   ebp
0x509ce1  8bec                             mov    ebp,esp
0x509ce3  83e4f8                           and    esp,0xfffffff8
0x509ce6  6aff                             push   0xffffffff
0x509ce8  6864f69200                       push   0x92f664
0x509ced  64a100000000                     mov    eax,fs:0x0
0x509cf3  50                               push   eax
0x509cf4  81ec90000000                     sub    esp,0x90
0x509cfa  a1201fd600                       mov    eax,ds:0xd61f20
0x509cff  33c4                             xor    eax,esp
0x509d01  89842488000000                   mov    DWORD PTR [esp+0x88],eax
0x509d08  53                               push   ebx
0x509d09  56                               push   esi
0x509d0a  57                               push   edi
0x509d0b  a1201fd600                       mov    eax,ds:0xd61f20
0x509d10  33c4                             xor    eax,esp
0x509d12  50                               push   eax
0x509d13  8d8424a0000000                   lea    eax,[esp+0xa0]
0x509d1a  64a300000000                     mov    fs:0x0,eax
0x509d20  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x509d23  8bf9                             mov    edi,ecx
0x509d25  89442420                         mov    DWORD PTR [esp+0x20],eax
0x509d29  897c242c                         mov    DWORD PTR [esp+0x2c],edi
0x509d2d  e86eaeefff                       call   0x404ba0
0x509d32  8b7704                           mov    esi,DWORD PTR [edi+0x4]
0x509d35  8b8064680000                     mov    eax,DWORD PTR [eax+0x6864]
0x509d3b  8bde                             mov    ebx,esi
0x509d3d  2bd8                             sub    ebx,eax
0x509d3f  c644241c00                       mov    BYTE PTR [esp+0x1c],0x0
0x509d44  e857aeefff                       call   0x404ba0
0x509d49  89b064680000                     mov    DWORD PTR [eax+0x6864],esi
0x509d4f  8b7708                           mov    esi,DWORD PTR [edi+0x8]
0x509d52  e849aeefff                       call   0x404ba0
0x509d57  89b070680000                     mov    DWORD PTR [eax+0x6870],esi
0x509d5d  0fb74702                         movzx  eax,WORD PTR [edi+0x2]
0x509d61  48                               dec    eax
0x509d62  c744241000000000                 mov    DWORD PTR [esp+0x10],0x0
0x509d6a  83f806                           cmp    eax,0x6
0x509d6d  0f87dc000000                     ja     0x509e4f
0x509d73  ff248550a45000                   jmp    DWORD PTR [eax*4+0x50a450]
0x509d7a  6a2e                             push   0x2e
0x509d7c  e82fb80700                       call   0x5855b0

; asset_update_slots | 17-byte inventory records create/clear and UI refresh
; VA 0x50a32f..0x50a440 raw 0x10972f length 273 sha256 4c5622c79e3715b320b717d83083d150f4e233f1347b64dd20dddee978950d69
0x50a32f  8db42480000000                   lea    esi,[esp+0x80]
0x50a336  e8c59bf7ff                       call   0x483f00
0x50a33b  83c404                           add    esp,0x4
0x50a33e  50                               push   eax
0x50a33f  c78424ac0000000c000000           mov    DWORD PTR [esp+0xac],0xc
0x50a34a  e87155f0ff                       call   0x40f8c0
0x50a34f  8bf8                             mov    edi,eax
0x50a351  e8dac7fcff                       call   0x4d6b30
0x50a356  8bce                             mov    ecx,esi
0x50a358  c78424a8000000ffffffff           mov    DWORD PTR [esp+0xa8],0xffffffff
0x50a363  e8d800ffff                       call   0x4fa440
0x50a368  8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x50a36c  8a08                             mov    cl,BYTE PTR [eax]
0x50a36e  84c9                             test   cl,cl
0x50a370  7424                             je     0x50a396
0x50a372  8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
0x50a376  8b78fc                           mov    edi,DWORD PTR [eax-0x4]
0x50a379  52                               push   edx
0x50a37a  8b50f8                           mov    edx,DWORD PTR [eax-0x8]
0x50a37d  0fb6c9                           movzx  ecx,cl
0x50a380  51                               push   ecx
0x50a381  8b48f4                           mov    ecx,DWORD PTR [eax-0xc]
0x50a384  52                               push   edx
0x50a385  8b542430                         mov    edx,DWORD PTR [esp+0x30]
0x50a389  51                               push   ecx
0x50a38a  0fb648f3                         movzx  ecx,BYTE PTR [eax-0xd]
0x50a38e  52                               push   edx
0x50a38f  e81ce9ffff                       call   0x508cb0
0x50a394  eb35                             jmp    0x50a3cb
0x50a396  0fb640f3                         movzx  eax,BYTE PTR [eax-0xd]
0x50a39a  8d48ff                           lea    ecx,[eax-0x1]
0x50a39d  83f963                           cmp    ecx,0x63
0x50a3a0  771c                             ja     0x50a3be
0x50a3a2  c1e005                           shl    eax,0x5
0x50a3a5  03442424                         add    eax,DWORD PTR [esp+0x24]
0x50a3a9  33c9                             xor    ecx,ecx
0x50a3ab  8908                             mov    DWORD PTR [eax],ecx
0x50a3ad  894804                           mov    DWORD PTR [eax+0x4],ecx
0x50a3b0  894808                           mov    DWORD PTR [eax+0x8],ecx
0x50a3b3  89480c                           mov    DWORD PTR [eax+0xc],ecx
0x50a3b6  894810                           mov    DWORD PTR [eax+0x10],ecx
0x50a3b9  894814                           mov    DWORD PTR [eax+0x14],ecx
0x50a3bc  eb0d                             jmp    0x50a3cb
0x50a3be  68c0ddc000                       push   0xc0ddc0
0x50a3c3  e898371e00                       call   0x6edb60
0x50a3c8  83c404                           add    esp,0x4
0x50a3cb  8b742414                         mov    esi,DWORD PTR [esp+0x14]
0x50a3cf  83c611                           add    esi,0x11
0x50a3d2  ff4c2428                         dec    DWORD PTR [esp+0x28]
0x50a3d6  89742414                         mov    DWORD PTR [esp+0x14],esi
0x50a3da  0f859bfaffff                     jne    0x509e7b
0x50a3e0  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0x50a3e7  752f                             jne    0x50a418
0x50a3e9  830dd4adfa0001                   or     DWORD PTR ds:0xfaadd4,0x1
0x50a3f0  c78424a80000000d000000           mov    DWORD PTR [esp+0xa8],0xd
0x50a3fb  e880d00700                       call   0x587480
0x50a400  68c0ccbc00                       push   0xbcccc0
0x50a405  e8107f3800                       call   0x89231a
0x50a40a  83c404                           add    esp,0x4
0x50a40d  c78424a8000000ffffffff           mov    DWORD PTR [esp+0xa8],0xffffffff
0x50a418  6865430f00                       push   0xf4365
0x50a41d  e8ae060800                       call   0x58aad0
0x50a422  83c404                           add    esp,0x4
0x50a425  33c0                             xor    eax,eax
0x50a427  8b8c24a0000000                   mov    ecx,DWORD PTR [esp+0xa0]
0x50a42e  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x50a435  59                               pop    ecx
0x50a436  5f                               pop    edi
0x50a437  5e                               pop    esi
0x50a438  5b                               pop    ebx
0x50a439  8b8c2488000000                   mov    ecx,DWORD PTR [esp+0x88]

; frame_world_animate | frame supplies FAB130 owner and delta to4E0200
; VA 0x49256c..0x4925aa raw 0x9196c length 62 sha256 4f1b7b26487afedb1207178f336f692bc3b0c4603d1743df65fca8a554a4e2ba
0x49256c  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
0x492573  7524                             jne    0x492599
0x492575  093d2cb2fa00                     or     DWORD PTR ds:0xfab22c,edi
0x49257b  c74424380d000000                 mov    DWORD PTR [esp+0x38],0xd
0x492583  e808c70400                       call   0x4dec90
0x492588  6830cebc00                       push   0xbcce30
0x49258d  e888fd3f00                       call   0x89231a
0x492592  83c404                           add    esp,0x4
0x492595  895c2438                         mov    DWORD PTR [esp+0x38],ebx
0x492599  d9450c                           fld    DWORD PTR [ebp+0xc]
0x49259c  51                               push   ecx
0x49259d  d91c24                           fstp   DWORD PTR [esp]
0x4925a0  6830b1fa00                       push   0xfab130
0x4925a5  e856dc0400                       call   0x4e0200

; actor_pool_init | create worker6EE540 for each twelve-byte record
; VA 0x6ee4a0..0x6ee4f0 raw 0x2ed8a0 length 80 sha256 3b712de172f87d08f766dbfb70a6bf75694354d66c366abc1184ec4c67a25492
0x6ee4a0  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x6ee4a3  40                               inc    eax
0x6ee4a4  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x6ee4a7  3b45f4                           cmp    eax,DWORD PTR [ebp-0xc]
0x6ee4aa  0f8207ffffff                     jb     0x6ee3b7
0x6ee4b0  8b5df4                           mov    ebx,DWORD PTR [ebp-0xc]
0x6ee4b3  85db                             test   ebx,ebx
0x6ee4b5  7424                             je     0x6ee4db
0x6ee4b7  33f6                             xor    esi,esi
0x6ee4b9  8da42400000000                   lea    esp,[esp+0x0]
0x6ee4c0  8b5724                           mov    edx,DWORD PTR [edi+0x24]
0x6ee4c3  03d6                             add    edx,esi
0x6ee4c5  52                               push   edx
0x6ee4c6  6a00                             push   0x0
0x6ee4c8  6840e56e00                       push   0x6ee540
0x6ee4cd  e867781a00                       call   0x895d39
0x6ee4d2  83c40c                           add    esp,0xc
0x6ee4d5  83c60c                           add    esi,0xc
0x6ee4d8  4b                               dec    ebx
0x6ee4d9  75e5                             jne    0x6ee4c0
0x6ee4db  5e                               pop    esi
0x6ee4dc  5b                               pop    ebx
0x6ee4dd  5f                               pop    edi
0x6ee4de  8be5                             mov    esp,ebp
0x6ee4e0  5d                               pop    ebp
0x6ee4e1  c20400                           ret    0x4
0x6ee4e4  cc                               int3
0x6ee4e5  cc                               int3
0x6ee4e6  cc                               int3
0x6ee4e7  cc                               int3
0x6ee4e8  cc                               int3
0x6ee4e9  cc                               int3
0x6ee4ea  cc                               int3
0x6ee4eb  cc                               int3
0x6ee4ec  cc                               int3
0x6ee4ed  cc                               int3
0x6ee4ee  cc                               int3
0x6ee4ef  cc                               int3

; vtable_CNPC | selected methods plus original COL pointer; no adjacent COL treated as method
; VA 0xc0ca98..0xc0cb0c raw 0x80b098 length 116 sha256 f679a25095653eafab38bdd2d9a8214f616214cd771cd6198eef9a53fb47c8b4
db f0acc60080224d00105d5f0080a84c00f0c28d0040284d0060284d00f0c28d00f0c28d0090284d00c0284d00802a4d0010234d0020284d0060804c0030ab4c00b06f4c00d06f4c00908b4c00e08b4c00908f4c00a08f4c00e0ab4c00308c4c00408c4c0040ad4c0080844c00a08d4c0050954c00

; col_CNPC | MSVC complete object locator
; VA 0xc6acf0..0xc6ad04 raw 0x8692f0 length 20 sha256 5b701ee7d1b8946b6e5ab5428691c7fd4e44e15b607d308a34831c494f1ddca7
db 00000000000000000000000070e8f70004adc600

; type_CNPC | MSVC RTTI name
; VA 0xf7e870..0xf7e883 raw 0xb7c070 length 19 sha256 8ecd2930799ab468655f9806058d4d9e1621d31ac375fa668bd7d235014dc9bf
db f435bd00000000002e3f4156434e5043404000

; vtable_CEventActor | selected methods plus original COL pointer; no adjacent COL treated as method
; VA 0xc0c820..0xc0c894 raw 0x80ae20 length 116 sha256 d379d22cedee9348d9fb320e1fad80713570be8f887e544822f6381399a5af5f
db acabc600a00c4d00105d5f0080a84c00f0c28d0040824c0060834c00f0c28d00f0c28d00800f4d00a00f4d00c00f4d0070a84c0050804c0060804c0030ab4c00b06f4c00d06f4c00908b4c00e08b4c00908f4c00a08f4c00100f4d00308c4c00408c4c00500f4d0080844c00a08d4c0050954c00

; col_CEventActor | MSVC complete object locator
; VA 0xc6abac..0xc6abc0 raw 0x8691ac length 20 sha256 241fa823b875d822cca71ceb3908a988f0e518ee6b3bf55cdd0ece3f35e32111
db 00000000000000000000000038e8f700c0abc600

; type_CEventActor | MSVC RTTI name
; VA 0xf7e838..0xf7e852 raw 0xb7c038 length 26 sha256 137ecec44a5f37f4f71a037980cf7d9dc96aa54f66a2d2a68dad9cc0d3d70b22
db f435bd00000000002e3f4156434576656e744163746f72404000

; vtable_IS3D_CDoll | selected methods plus original COL pointer; no adjacent COL treated as method
; VA 0xc4f678..0xc4f68c raw 0x84dc78 length 20 sha256 071f75045d969737311ef6a0643df36ba103b00af8be862fde9a80b33f69c132
db 7cfac700f04f7a00e0b47700c0637a0050045500

; col_IS3D_CDoll | MSVC complete object locator
; VA 0xc7fa7c..0xc7fa90 raw 0x87e07c length 20 sha256 35645ebe00923e5287ce4ba151ebff7227152e8484701749301116a870eb4cad
db 00000000000000000000000018a7f80090fac700

; type_IS3D_CDoll | MSVC RTTI name
; VA 0xf8a718..0xf8a731 raw 0xb87f18 length 25 sha256 a974c8edfc4d10b304a616cd93380b42db8e353cbed2b54f07e23fef4c178689
db f435bd00000000002e3f415643446f6c6c4049533344404000

; vtable_IS3D_CItem | selected methods plus original COL pointer; no adjacent COL treated as method
; VA 0xc500b4..0xc500c4 raw 0x84e6b4 length 16 sha256 8c455d35791d2fad8be69fd3fec0b5f442ece285fcba12cedbd1f8e97f4d8e88
db b800c80040297d0020b55c00602c7d00

; col_IS3D_CItem | MSVC complete object locator
; VA 0xc800b8..0xc800cc raw 0x87e6b8 length 20 sha256 bfb8a67919c1f4ca3b2107483fef09088d3d9a75953f009dea174b291d9ce795
db 00000000000000000000000074a9f800cc00c800

; type_IS3D_CItem | MSVC RTTI name
; VA 0xf8a974..0xf8a98d raw 0xb88174 length 25 sha256 92c9cc01e8808c76cf6e8de50c335d4ed280ae1c4e4dd25ae8048874cf3d506b
db f435bd00000000002e3f4156434974656d4049533344404000

; animate_executor_first_slot | only actual first method slot; adjacent +4 is COL metadata and excluded
; VA 0xc0cf2c..0xc0cf30 raw 0x80b52c length 4 sha256 cffbc097cf81a85e197cc8951057a84f4bb9b6b0664c3bd8e52a40b2ebfaed77
db 20054e00

; Face_SKIN_string | literal skin name used by face-controller construction
; VA 0xc4fdec..0xc4fdf6 raw 0x84e3ec length 10 sha256 5d2ec06b89b06ea71b392fd6e47f69292a92366abc0272b1f0b0bb21559794ca
db 466163652e534b494e00

; register_lb_CreateObject | actual public registration
; VA 0x4a1790..0x4a1830 raw 0xa0b90 length 160 sha256 c89e500b6d6ac98ee910fa8c09318b659a4c9f0da3b4d7dda3bc0f81343d319c
0x4a1790  55                               push   ebp
0x4a1791  8bec                             mov    ebp,esp
0x4a1793  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1796  53                               push   ebx
0x4a1797  8b1d7417fe00                     mov    ebx,DWORD PTR ds:0xfe1774
0x4a179d  56                               push   esi
0x4a179e  8b33                             mov    esi,DWORD PTR [ebx]
0x4a17a0  57                               push   edi
0x4a17a1  8b38                             mov    edi,DWORD PTR [eax]
0x4a17a3  b8eed8ffff                       mov    eax,0xffffd8ee
0x4a17a8  c7058817fe00400b4a00             mov    DWORD PTR ds:0xfe1788,0x4a0b40
0x4a17b2  e8c93e2500                       call   0x6f5680
0x4a17b7  8b03                             mov    eax,DWORD PTR [ebx]
0x4a17b9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a17bc  83e810                           sub    eax,0x10
0x4a17bf  3dc8bfc000                       cmp    eax,0xc0bfc8
0x4a17c4  7406                             je     0x4a17cc
0x4a17c6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4a17ca  7414                             je     0x4a17e0
0x4a17cc  57                               push   edi
0x4a17cd  68c426c400                       push   0xc426c4
0x4a17d2  e8e6183f00                       call   0x8930bd
0x4a17d7  8b1b                             mov    ebx,DWORD PTR [ebx]
0x4a17d9  83c408                           add    esp,0x8
0x4a17dc  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a17e0  8b3d7417fe00                     mov    edi,DWORD PTR ds:0xfe1774
0x4a17e6  8b37                             mov    esi,DWORD PTR [edi]
0x4a17e8  68bcadd600                       push   0xd6adbc
0x4a17ed  e81e3d2500                       call   0x6f5510
0x4a17f2  8b37                             mov    esi,DWORD PTR [edi]
0x4a17f4  83c404                           add    esp,0x4
0x4a17f7  6a00                             push   0x0
0x4a17f9  68b01f4a00                       push   0x4a1fb0
0x4a17fe  e8ad3d2500                       call   0x6f55b0
0x4a1803  8b0f                             mov    ecx,DWORD PTR [edi]
0x4a1805  51                               push   ecx
0x4a1806  b8fdffffff                       mov    eax,0xfffffffd
0x4a180b  e8e03f2500                       call   0x6f57f0
0x4a1810  8b157417fe00                     mov    edx,DWORD PTR ds:0xfe1774
0x4a1816  8b02                             mov    eax,DWORD PTR [edx]
0x4a1818  83c40c                           add    esp,0xc
0x4a181b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4a181f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1822  5f                               pop    edi
0x4a1823  5e                               pop    esi
0x4a1824  5b                               pop    ebx
0x4a1825  5d                               pop    ebp
0x4a1826  c20400                           ret    0x4
0x4a1829  cc                               int3
0x4a182a  cc                               int3
0x4a182b  cc                               int3
0x4a182c  cc                               int3
0x4a182d  cc                               int3
0x4a182e  cc                               int3
0x4a182f  cc                               int3

; closure_lb_CreateObject | Lua closure and conversion call
; VA 0x4a1fb0..0x4a2010 raw 0xa13b0 length 96 sha256 82feea7493dcd1022e7d0a407b1a9e7b9ad9f8c2f037a3a171afeb4acfe2df27
0x4a1fb0  55                               push   ebp
0x4a1fb1  8bec                             mov    ebp,esp
0x4a1fb3  6aff                             push   0xffffffff
0x4a1fb5  68c8839300                       push   0x9383c8
0x4a1fba  64a100000000                     mov    eax,fs:0x0
0x4a1fc0  50                               push   eax
0x4a1fc1  83ec0c                           sub    esp,0xc
0x4a1fc4  a1201fd600                       mov    eax,ds:0xd61f20
0x4a1fc9  33c5                             xor    eax,ebp
0x4a1fcb  50                               push   eax
0x4a1fcc  8d45f4                           lea    eax,[ebp-0xc]
0x4a1fcf  64a300000000                     mov    fs:0x0,eax
0x4a1fd5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1fd8  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4a1fdb  33c0                             xor    eax,eax
0x4a1fdd  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4a1fe0  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4a1fe3  8d4de8                           lea    ecx,[ebp-0x18]
0x4a1fe6  51                               push   ecx
0x4a1fe7  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4a1fea  e871040000                       call   0x4a2460
0x4a1fef  83c404                           add    esp,0x4
0x4a1ff2  b801000000                       mov    eax,0x1
0x4a1ff7  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4a1ffa  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a2001  59                               pop    ecx
0x4a2002  8be5                             mov    esp,ebp
0x4a2004  5d                               pop    ebp
0x4a2005  c3                               ret
0x4a2006  cc                               int3
0x4a2007  cc                               int3
0x4a2008  cc                               int3
0x4a2009  cc                               int3
0x4a200a  cc                               int3
0x4a200b  cc                               int3
0x4a200c  cc                               int3
0x4a200d  cc                               int3
0x4a200e  cc                               int3
0x4a200f  cc                               int3

; name_lb_CreateObject | registered ASCII symbol
; VA 0xd6adbc..0xd6adc9 raw 0x9685bc length 13 sha256 64a7f65eb3fda305db917f293054aa5a54e10e1d87d95ae19c620f4fc18cf468
db 4372656174654f626a65637400

; register_lb_CreateObjectEx | actual public registration
; VA 0x4a1830..0x4a18d0 raw 0xa0c30 length 160 sha256 a72163aa860befdb76c809c2ad617766f4f1088d1044e2b92a8c745207e36a2c
0x4a1830  55                               push   ebp
0x4a1831  8bec                             mov    ebp,esp
0x4a1833  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1836  53                               push   ebx
0x4a1837  8b1d7417fe00                     mov    ebx,DWORD PTR ds:0xfe1774
0x4a183d  56                               push   esi
0x4a183e  8b33                             mov    esi,DWORD PTR [ebx]
0x4a1840  57                               push   edi
0x4a1841  8b38                             mov    edi,DWORD PTR [eax]
0x4a1843  b8eed8ffff                       mov    eax,0xffffd8ee
0x4a1848  c7058c17fe00700f4a00             mov    DWORD PTR ds:0xfe178c,0x4a0f70
0x4a1852  e8293e2500                       call   0x6f5680
0x4a1857  8b03                             mov    eax,DWORD PTR [ebx]
0x4a1859  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a185c  83e810                           sub    eax,0x10
0x4a185f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x4a1864  7406                             je     0x4a186c
0x4a1866  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4a186a  7414                             je     0x4a1880
0x4a186c  57                               push   edi
0x4a186d  68c426c400                       push   0xc426c4
0x4a1872  e846183f00                       call   0x8930bd
0x4a1877  8b1b                             mov    ebx,DWORD PTR [ebx]
0x4a1879  83c408                           add    esp,0x8
0x4a187c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a1880  8b3d7417fe00                     mov    edi,DWORD PTR ds:0xfe1774
0x4a1886  8b37                             mov    esi,DWORD PTR [edi]
0x4a1888  68ccadd600                       push   0xd6adcc
0x4a188d  e87e3c2500                       call   0x6f5510
0x4a1892  8b37                             mov    esi,DWORD PTR [edi]
0x4a1894  83c404                           add    esp,0x4
0x4a1897  6a00                             push   0x0
0x4a1899  6810204a00                       push   0x4a2010
0x4a189e  e80d3d2500                       call   0x6f55b0
0x4a18a3  8b0f                             mov    ecx,DWORD PTR [edi]
0x4a18a5  51                               push   ecx
0x4a18a6  b8fdffffff                       mov    eax,0xfffffffd
0x4a18ab  e8403f2500                       call   0x6f57f0
0x4a18b0  8b157417fe00                     mov    edx,DWORD PTR ds:0xfe1774
0x4a18b6  8b02                             mov    eax,DWORD PTR [edx]
0x4a18b8  83c40c                           add    esp,0xc
0x4a18bb  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4a18bf  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a18c2  5f                               pop    edi
0x4a18c3  5e                               pop    esi
0x4a18c4  5b                               pop    ebx
0x4a18c5  5d                               pop    ebp
0x4a18c6  c20400                           ret    0x4
0x4a18c9  cc                               int3
0x4a18ca  cc                               int3
0x4a18cb  cc                               int3
0x4a18cc  cc                               int3
0x4a18cd  cc                               int3
0x4a18ce  cc                               int3
0x4a18cf  cc                               int3

; closure_lb_CreateObjectEx | Lua closure and conversion call
; VA 0x4a2010..0x4a2070 raw 0xa1410 length 96 sha256 527be38eb5e2c5c5c144cc247b2944060a86618df47633087e759da2a75f65e9
0x4a2010  55                               push   ebp
0x4a2011  8bec                             mov    ebp,esp
0x4a2013  6aff                             push   0xffffffff
0x4a2015  68c8839300                       push   0x9383c8
0x4a201a  64a100000000                     mov    eax,fs:0x0
0x4a2020  50                               push   eax
0x4a2021  83ec0c                           sub    esp,0xc
0x4a2024  a1201fd600                       mov    eax,ds:0xd61f20
0x4a2029  33c5                             xor    eax,ebp
0x4a202b  50                               push   eax
0x4a202c  8d45f4                           lea    eax,[ebp-0xc]
0x4a202f  64a300000000                     mov    fs:0x0,eax
0x4a2035  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a2038  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4a203b  33c0                             xor    eax,eax
0x4a203d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4a2040  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4a2043  8d4de8                           lea    ecx,[ebp-0x18]
0x4a2046  51                               push   ecx
0x4a2047  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4a204a  e8a1050000                       call   0x4a25f0
0x4a204f  83c404                           add    esp,0x4
0x4a2052  b801000000                       mov    eax,0x1
0x4a2057  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4a205a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a2061  59                               pop    ecx
0x4a2062  8be5                             mov    esp,ebp
0x4a2064  5d                               pop    ebp
0x4a2065  c3                               ret
0x4a2066  cc                               int3
0x4a2067  cc                               int3
0x4a2068  cc                               int3
0x4a2069  cc                               int3
0x4a206a  cc                               int3
0x4a206b  cc                               int3
0x4a206c  cc                               int3
0x4a206d  cc                               int3
0x4a206e  cc                               int3
0x4a206f  cc                               int3

; name_lb_CreateObjectEx | registered ASCII symbol
; VA 0xd6adcc..0xd6addb raw 0x9685cc length 15 sha256 b12cd67a7bf11c3215aa6505f8a9a233b9d0f3cf5c897b7da4fcc9050d017ab6
db 4372656174654f626a656374457800

; register_lb_SetActorAvatar | actual public registration
; VA 0x4a18d0..0x4a1970 raw 0xa0cd0 length 160 sha256 44fe79a788d1876a0dd6a46b83ea61ac5237a29e977c256077c61b9dffbbfc0f
0x4a18d0  55                               push   ebp
0x4a18d1  8bec                             mov    ebp,esp
0x4a18d3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a18d6  53                               push   ebx
0x4a18d7  8b1d7417fe00                     mov    ebx,DWORD PTR ds:0xfe1774
0x4a18dd  56                               push   esi
0x4a18de  8b33                             mov    esi,DWORD PTR [ebx]
0x4a18e0  57                               push   edi
0x4a18e1  8b38                             mov    edi,DWORD PTR [eax]
0x4a18e3  b8eed8ffff                       mov    eax,0xffffd8ee
0x4a18e8  c7059017fe00800b4a00             mov    DWORD PTR ds:0xfe1790,0x4a0b80
0x4a18f2  e8893d2500                       call   0x6f5680
0x4a18f7  8b03                             mov    eax,DWORD PTR [ebx]
0x4a18f9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a18fc  83e810                           sub    eax,0x10
0x4a18ff  3dc8bfc000                       cmp    eax,0xc0bfc8
0x4a1904  7406                             je     0x4a190c
0x4a1906  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4a190a  7414                             je     0x4a1920
0x4a190c  57                               push   edi
0x4a190d  68c426c400                       push   0xc426c4
0x4a1912  e8a6173f00                       call   0x8930bd
0x4a1917  8b1b                             mov    ebx,DWORD PTR [ebx]
0x4a1919  83c408                           add    esp,0x8
0x4a191c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a1920  8b3d7417fe00                     mov    edi,DWORD PTR ds:0xfe1774
0x4a1926  8b37                             mov    esi,DWORD PTR [edi]
0x4a1928  68dcadd600                       push   0xd6addc
0x4a192d  e8de3b2500                       call   0x6f5510
0x4a1932  8b37                             mov    esi,DWORD PTR [edi]
0x4a1934  83c404                           add    esp,0x4
0x4a1937  6a00                             push   0x0
0x4a1939  6870204a00                       push   0x4a2070
0x4a193e  e86d3c2500                       call   0x6f55b0
0x4a1943  8b0f                             mov    ecx,DWORD PTR [edi]
0x4a1945  51                               push   ecx
0x4a1946  b8fdffffff                       mov    eax,0xfffffffd
0x4a194b  e8a03e2500                       call   0x6f57f0
0x4a1950  8b157417fe00                     mov    edx,DWORD PTR ds:0xfe1774
0x4a1956  8b02                             mov    eax,DWORD PTR [edx]
0x4a1958  83c40c                           add    esp,0xc
0x4a195b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4a195f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1962  5f                               pop    edi
0x4a1963  5e                               pop    esi
0x4a1964  5b                               pop    ebx
0x4a1965  5d                               pop    ebp
0x4a1966  c20400                           ret    0x4
0x4a1969  cc                               int3
0x4a196a  cc                               int3
0x4a196b  cc                               int3
0x4a196c  cc                               int3
0x4a196d  cc                               int3
0x4a196e  cc                               int3
0x4a196f  cc                               int3

; closure_lb_SetActorAvatar | Lua closure and conversion call
; VA 0x4a2070..0x4a20d0 raw 0xa1470 length 96 sha256 729875923bdacb0cdf545568c42e6278289cf6b55c57376cc0f668984b14e687
0x4a2070  55                               push   ebp
0x4a2071  8bec                             mov    ebp,esp
0x4a2073  6aff                             push   0xffffffff
0x4a2075  68c8839300                       push   0x9383c8
0x4a207a  64a100000000                     mov    eax,fs:0x0
0x4a2080  50                               push   eax
0x4a2081  83ec0c                           sub    esp,0xc
0x4a2084  a1201fd600                       mov    eax,ds:0xd61f20
0x4a2089  33c5                             xor    eax,ebp
0x4a208b  50                               push   eax
0x4a208c  8d45f4                           lea    eax,[ebp-0xc]
0x4a208f  64a300000000                     mov    fs:0x0,eax
0x4a2095  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a2098  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4a209b  33c0                             xor    eax,eax
0x4a209d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4a20a0  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4a20a3  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4a20a6  8b0d9017fe00                     mov    ecx,DWORD PTR ds:0xfe1790
0x4a20ac  51                               push   ecx
0x4a20ad  8d55e8                           lea    edx,[ebp-0x18]
0x4a20b0  52                               push   edx
0x4a20b1  e89a070000                       call   0x4a2850
0x4a20b6  83c408                           add    esp,0x8
0x4a20b9  b801000000                       mov    eax,0x1
0x4a20be  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4a20c1  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a20c8  59                               pop    ecx
0x4a20c9  8be5                             mov    esp,ebp
0x4a20cb  5d                               pop    ebp
0x4a20cc  c3                               ret
0x4a20cd  cc                               int3
0x4a20ce  cc                               int3
0x4a20cf  cc                               int3

; name_lb_SetActorAvatar | registered ASCII symbol
; VA 0xd6addc..0xd6adeb raw 0x9685dc length 15 sha256 89dd8ec1b74722ca0c9561fa2f51347b9237b14d2082097029f8d6aa60b17a06
db 5365744163746f7241766174617200

; register_lb_AttachActorItem | actual public registration
; VA 0x4a1970..0x4a1a10 raw 0xa0d70 length 160 sha256 1883aa21ee6110267bb06d2ff51019aa204cbb06ffcafc8036faa4333b469ad3
0x4a1970  55                               push   ebp
0x4a1971  8bec                             mov    ebp,esp
0x4a1973  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1976  53                               push   ebx
0x4a1977  8b1d7417fe00                     mov    ebx,DWORD PTR ds:0xfe1774
0x4a197d  56                               push   esi
0x4a197e  8b33                             mov    esi,DWORD PTR [ebx]
0x4a1980  57                               push   edi
0x4a1981  8b38                             mov    edi,DWORD PTR [eax]
0x4a1983  b8eed8ffff                       mov    eax,0xffffd8ee
0x4a1988  c7059417fe00500c4a00             mov    DWORD PTR ds:0xfe1794,0x4a0c50
0x4a1992  e8e93c2500                       call   0x6f5680
0x4a1997  8b03                             mov    eax,DWORD PTR [ebx]
0x4a1999  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a199c  83e810                           sub    eax,0x10
0x4a199f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x4a19a4  7406                             je     0x4a19ac
0x4a19a6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4a19aa  7414                             je     0x4a19c0
0x4a19ac  57                               push   edi
0x4a19ad  68c426c400                       push   0xc426c4
0x4a19b2  e806173f00                       call   0x8930bd
0x4a19b7  8b1b                             mov    ebx,DWORD PTR [ebx]
0x4a19b9  83c408                           add    esp,0x8
0x4a19bc  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a19c0  8b3d7417fe00                     mov    edi,DWORD PTR ds:0xfe1774
0x4a19c6  8b37                             mov    esi,DWORD PTR [edi]
0x4a19c8  68ecadd600                       push   0xd6adec
0x4a19cd  e83e3b2500                       call   0x6f5510
0x4a19d2  8b37                             mov    esi,DWORD PTR [edi]
0x4a19d4  83c404                           add    esp,0x4
0x4a19d7  6a00                             push   0x0
0x4a19d9  68d0204a00                       push   0x4a20d0
0x4a19de  e8cd3b2500                       call   0x6f55b0
0x4a19e3  8b0f                             mov    ecx,DWORD PTR [edi]
0x4a19e5  51                               push   ecx
0x4a19e6  b8fdffffff                       mov    eax,0xfffffffd
0x4a19eb  e8003e2500                       call   0x6f57f0
0x4a19f0  8b157417fe00                     mov    edx,DWORD PTR ds:0xfe1774
0x4a19f6  8b02                             mov    eax,DWORD PTR [edx]
0x4a19f8  83c40c                           add    esp,0xc
0x4a19fb  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4a19ff  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1a02  5f                               pop    edi
0x4a1a03  5e                               pop    esi
0x4a1a04  5b                               pop    ebx
0x4a1a05  5d                               pop    ebp
0x4a1a06  c20400                           ret    0x4
0x4a1a09  cc                               int3
0x4a1a0a  cc                               int3
0x4a1a0b  cc                               int3
0x4a1a0c  cc                               int3
0x4a1a0d  cc                               int3
0x4a1a0e  cc                               int3
0x4a1a0f  cc                               int3

; closure_lb_AttachActorItem | Lua closure and conversion call
; VA 0x4a20d0..0x4a2130 raw 0xa14d0 length 96 sha256 1510aff51e365dbe08cb0396d2917e5924f197f52d4181157de8056f726e27fe
0x4a20d0  55                               push   ebp
0x4a20d1  8bec                             mov    ebp,esp
0x4a20d3  6aff                             push   0xffffffff
0x4a20d5  68c8839300                       push   0x9383c8
0x4a20da  64a100000000                     mov    eax,fs:0x0
0x4a20e0  50                               push   eax
0x4a20e1  83ec0c                           sub    esp,0xc
0x4a20e4  a1201fd600                       mov    eax,ds:0xd61f20
0x4a20e9  33c5                             xor    eax,ebp
0x4a20eb  50                               push   eax
0x4a20ec  8d45f4                           lea    eax,[ebp-0xc]
0x4a20ef  64a300000000                     mov    fs:0x0,eax
0x4a20f5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a20f8  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4a20fb  33c0                             xor    eax,eax
0x4a20fd  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4a2100  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4a2103  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4a2106  8b0d9417fe00                     mov    ecx,DWORD PTR ds:0xfe1794
0x4a210c  51                               push   ecx
0x4a210d  8d55e8                           lea    edx,[ebp-0x18]
0x4a2110  52                               push   edx
0x4a2111  e87a080000                       call   0x4a2990
0x4a2116  83c408                           add    esp,0x8
0x4a2119  b801000000                       mov    eax,0x1
0x4a211e  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4a2121  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a2128  59                               pop    ecx
0x4a2129  8be5                             mov    esp,ebp
0x4a212b  5d                               pop    ebp
0x4a212c  c3                               ret
0x4a212d  cc                               int3
0x4a212e  cc                               int3
0x4a212f  cc                               int3

; name_lb_AttachActorItem | registered ASCII symbol
; VA 0xd6adec..0xd6adfc raw 0x9685ec length 16 sha256 e8759a2640ab4a145d76d136b7f9e0c78942575b4c914cefb4d425df099674bc
db 4174746163684163746f724974656d00

; register_lb_DetachActorItem | actual public registration
; VA 0x4a1a10..0x4a1ab0 raw 0xa0e10 length 160 sha256 871f6a9cd447a8301b0f13758a4a4cf9210568fc22001349427446281ee9f095
0x4a1a10  55                               push   ebp
0x4a1a11  8bec                             mov    ebp,esp
0x4a1a13  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1a16  53                               push   ebx
0x4a1a17  8b1d7417fe00                     mov    ebx,DWORD PTR ds:0xfe1774
0x4a1a1d  56                               push   esi
0x4a1a1e  8b33                             mov    esi,DWORD PTR [ebx]
0x4a1a20  57                               push   edi
0x4a1a21  8b38                             mov    edi,DWORD PTR [eax]
0x4a1a23  b8eed8ffff                       mov    eax,0xffffd8ee
0x4a1a28  c7059817fe00100d4a00             mov    DWORD PTR ds:0xfe1798,0x4a0d10
0x4a1a32  e8493c2500                       call   0x6f5680
0x4a1a37  8b03                             mov    eax,DWORD PTR [ebx]
0x4a1a39  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4a1a3c  83e810                           sub    eax,0x10
0x4a1a3f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x4a1a44  7406                             je     0x4a1a4c
0x4a1a46  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4a1a4a  7414                             je     0x4a1a60
0x4a1a4c  57                               push   edi
0x4a1a4d  68c426c400                       push   0xc426c4
0x4a1a52  e866163f00                       call   0x8930bd
0x4a1a57  8b1b                             mov    ebx,DWORD PTR [ebx]
0x4a1a59  83c408                           add    esp,0x8
0x4a1a5c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a1a60  8b3d7417fe00                     mov    edi,DWORD PTR ds:0xfe1774
0x4a1a66  8b37                             mov    esi,DWORD PTR [edi]
0x4a1a68  68fcadd600                       push   0xd6adfc
0x4a1a6d  e89e3a2500                       call   0x6f5510
0x4a1a72  8b37                             mov    esi,DWORD PTR [edi]
0x4a1a74  83c404                           add    esp,0x4
0x4a1a77  6a00                             push   0x0
0x4a1a79  6830214a00                       push   0x4a2130
0x4a1a7e  e82d3b2500                       call   0x6f55b0
0x4a1a83  8b0f                             mov    ecx,DWORD PTR [edi]
0x4a1a85  51                               push   ecx
0x4a1a86  b8fdffffff                       mov    eax,0xfffffffd
0x4a1a8b  e8603d2500                       call   0x6f57f0
0x4a1a90  8b157417fe00                     mov    edx,DWORD PTR ds:0xfe1774
0x4a1a96  8b02                             mov    eax,DWORD PTR [edx]
0x4a1a98  83c40c                           add    esp,0xc
0x4a1a9b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4a1a9f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a1aa2  5f                               pop    edi
0x4a1aa3  5e                               pop    esi
0x4a1aa4  5b                               pop    ebx
0x4a1aa5  5d                               pop    ebp
0x4a1aa6  c20400                           ret    0x4
0x4a1aa9  cc                               int3
0x4a1aaa  cc                               int3
0x4a1aab  cc                               int3
0x4a1aac  cc                               int3
0x4a1aad  cc                               int3
0x4a1aae  cc                               int3
0x4a1aaf  cc                               int3

; closure_lb_DetachActorItem | Lua closure and conversion call
; VA 0x4a2130..0x4a2190 raw 0xa1530 length 96 sha256 beaace42eefa2e1b55986c1226e917c90f022262da5ab88c74584b0d6399ff86
0x4a2130  55                               push   ebp
0x4a2131  8bec                             mov    ebp,esp
0x4a2133  6aff                             push   0xffffffff
0x4a2135  68c8839300                       push   0x9383c8
0x4a213a  64a100000000                     mov    eax,fs:0x0
0x4a2140  50                               push   eax
0x4a2141  83ec0c                           sub    esp,0xc
0x4a2144  a1201fd600                       mov    eax,ds:0xd61f20
0x4a2149  33c5                             xor    eax,ebp
0x4a214b  50                               push   eax
0x4a214c  8d45f4                           lea    eax,[ebp-0xc]
0x4a214f  64a300000000                     mov    fs:0x0,eax
0x4a2155  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a2158  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4a215b  33c0                             xor    eax,eax
0x4a215d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4a2160  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4a2163  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4a2166  8b0d9817fe00                     mov    ecx,DWORD PTR ds:0xfe1798
0x4a216c  51                               push   ecx
0x4a216d  8d55e8                           lea    edx,[ebp-0x18]
0x4a2170  52                               push   edx
0x4a2171  e81a080000                       call   0x4a2990
0x4a2176  83c408                           add    esp,0x8
0x4a2179  b801000000                       mov    eax,0x1
0x4a217e  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4a2181  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a2188  59                               pop    ecx
0x4a2189  8be5                             mov    esp,ebp
0x4a218b  5d                               pop    ebp
0x4a218c  c3                               ret
0x4a218d  cc                               int3
0x4a218e  cc                               int3
0x4a218f  cc                               int3

; name_lb_DetachActorItem | registered ASCII symbol
; VA 0xd6adfc..0xd6ae0c raw 0x9685fc length 16 sha256 d54788c52eadee27109dd7dfd623ac4dde73b8cca9f2f00f70308412d8ce9f69
db 4465746163684163746f724974656d00

; register_Tutorial_SetCheckPointStatus | actual public registration
; VA 0x4aa860..0x4aa900 raw 0xa9c60 length 160 sha256 f4d7b8250014cd91c4d1b9657bb81d04577c9626777a3a6f237e81f13c0d0268
0x4aa860  55                               push   ebp
0x4aa861  8bec                             mov    ebp,esp
0x4aa863  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4aa866  53                               push   ebx
0x4aa867  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
0x4aa86d  56                               push   esi
0x4aa86e  8b33                             mov    esi,DWORD PTR [ebx]
0x4aa870  57                               push   edi
0x4aa871  8b38                             mov    edi,DWORD PTR [eax]
0x4aa873  b8eed8ffff                       mov    eax,0xffffd8ee
0x4aa878  c7051418fe0060944a00             mov    DWORD PTR ds:0xfe1814,0x4a9460
0x4aa882  e8f9ad2400                       call   0x6f5680
0x4aa887  8b03                             mov    eax,DWORD PTR [ebx]
0x4aa889  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4aa88c  83e810                           sub    eax,0x10
0x4aa88f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x4aa894  7406                             je     0x4aa89c
0x4aa896  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4aa89a  7414                             je     0x4aa8b0
0x4aa89c  57                               push   edi
0x4aa89d  68c426c400                       push   0xc426c4
0x4aa8a2  e816883e00                       call   0x8930bd
0x4aa8a7  8b1b                             mov    ebx,DWORD PTR [ebx]
0x4aa8a9  83c408                           add    esp,0x8
0x4aa8ac  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4aa8b0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
0x4aa8b6  8b37                             mov    esi,DWORD PTR [edi]
0x4aa8b8  688cabd600                       push   0xd6ab8c
0x4aa8bd  e84eac2400                       call   0x6f5510
0x4aa8c2  8b37                             mov    esi,DWORD PTR [edi]
0x4aa8c4  83c404                           add    esp,0x4
0x4aa8c7  6a00                             push   0x0
0x4aa8c9  68d0bf4a00                       push   0x4abfd0
0x4aa8ce  e8ddac2400                       call   0x6f55b0
0x4aa8d3  8b0f                             mov    ecx,DWORD PTR [edi]
0x4aa8d5  51                               push   ecx
0x4aa8d6  b8fdffffff                       mov    eax,0xfffffffd
0x4aa8db  e810af2400                       call   0x6f57f0
0x4aa8e0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
0x4aa8e6  8b02                             mov    eax,DWORD PTR [edx]
0x4aa8e8  83c40c                           add    esp,0xc
0x4aa8eb  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4aa8ef  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4aa8f2  5f                               pop    edi
0x4aa8f3  5e                               pop    esi
0x4aa8f4  5b                               pop    ebx
0x4aa8f5  5d                               pop    ebp
0x4aa8f6  c20400                           ret    0x4
0x4aa8f9  cc                               int3
0x4aa8fa  cc                               int3
0x4aa8fb  cc                               int3
0x4aa8fc  cc                               int3
0x4aa8fd  cc                               int3
0x4aa8fe  cc                               int3
0x4aa8ff  cc                               int3

; closure_Tutorial_SetCheckPointStatus | Lua closure and conversion call
; VA 0x4abfd0..0x4ac030 raw 0xab3d0 length 96 sha256 47fc8002341a84c9470a893fb34cc1d36b77b5c8c25d97442a5ae006d7254724
0x4abfd0  55                               push   ebp
0x4abfd1  8bec                             mov    ebp,esp
0x4abfd3  6aff                             push   0xffffffff
0x4abfd5  68c8839300                       push   0x9383c8
0x4abfda  64a100000000                     mov    eax,fs:0x0
0x4abfe0  50                               push   eax
0x4abfe1  83ec0c                           sub    esp,0xc
0x4abfe4  a1201fd600                       mov    eax,ds:0xd61f20
0x4abfe9  33c5                             xor    eax,ebp
0x4abfeb  50                               push   eax
0x4abfec  8d45f4                           lea    eax,[ebp-0xc]
0x4abfef  64a300000000                     mov    fs:0x0,eax
0x4abff5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4abff8  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4abffb  33c0                             xor    eax,eax
0x4abffd  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4ac000  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4ac003  8d4de8                           lea    ecx,[ebp-0x18]
0x4ac006  51                               push   ecx
0x4ac007  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4ac00a  e8e10b0000                       call   0x4acbf0
0x4ac00f  83c404                           add    esp,0x4
0x4ac012  b801000000                       mov    eax,0x1
0x4ac017  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4ac01a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4ac021  59                               pop    ecx
0x4ac022  8be5                             mov    esp,ebp
0x4ac024  5d                               pop    ebp
0x4ac025  c3                               ret
0x4ac026  cc                               int3
0x4ac027  cc                               int3
0x4ac028  cc                               int3
0x4ac029  cc                               int3
0x4ac02a  cc                               int3
0x4ac02b  cc                               int3
0x4ac02c  cc                               int3
0x4ac02d  cc                               int3
0x4ac02e  cc                               int3
0x4ac02f  cc                               int3

; name_Tutorial_SetCheckPointStatus | registered ASCII symbol
; VA 0xd6ab8c..0xd6aba0 raw 0x96838c length 20 sha256 ab00189617e08427b3294a47d789ffbaebccda52b37c8a97faa44acdc171fefe
db 536574436865636b506f696e7453746174757300

; register_Tutorial_InsertIsilia | actual public registration
; VA 0x4ab620..0x4ab6c0 raw 0xaaa20 length 160 sha256 cc353d35b9513ac63cb5447938ad067cee050fde5739c3554696d56f5f76e9cc
0x4ab620  55                               push   ebp
0x4ab621  8bec                             mov    ebp,esp
0x4ab623  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4ab626  53                               push   ebx
0x4ab627  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
0x4ab62d  56                               push   esi
0x4ab62e  8b33                             mov    esi,DWORD PTR [ebx]
0x4ab630  57                               push   edi
0x4ab631  8b38                             mov    edi,DWORD PTR [eax]
0x4ab633  b8eed8ffff                       mov    eax,0xffffd8ee
0x4ab638  c7056c18fe0070a04a00             mov    DWORD PTR ds:0xfe186c,0x4aa070
0x4ab642  e839a02400                       call   0x6f5680
0x4ab647  8b03                             mov    eax,DWORD PTR [ebx]
0x4ab649  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4ab64c  83e810                           sub    eax,0x10
0x4ab64f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x4ab654  7406                             je     0x4ab65c
0x4ab656  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4ab65a  7414                             je     0x4ab670
0x4ab65c  57                               push   edi
0x4ab65d  68c426c400                       push   0xc426c4
0x4ab662  e8567a3e00                       call   0x8930bd
0x4ab667  8b1b                             mov    ebx,DWORD PTR [ebx]
0x4ab669  83c408                           add    esp,0x8
0x4ab66c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4ab670  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
0x4ab676  8b37                             mov    esi,DWORD PTR [edi]
0x4ab678  6824add600                       push   0xd6ad24
0x4ab67d  e88e9e2400                       call   0x6f5510
0x4ab682  8b37                             mov    esi,DWORD PTR [edi]
0x4ab684  83c404                           add    esp,0x4
0x4ab687  6a00                             push   0x0
0x4ab689  6830c84a00                       push   0x4ac830
0x4ab68e  e81d9f2400                       call   0x6f55b0
0x4ab693  8b0f                             mov    ecx,DWORD PTR [edi]
0x4ab695  51                               push   ecx
0x4ab696  b8fdffffff                       mov    eax,0xfffffffd
0x4ab69b  e850a12400                       call   0x6f57f0
0x4ab6a0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
0x4ab6a6  8b02                             mov    eax,DWORD PTR [edx]
0x4ab6a8  83c40c                           add    esp,0xc
0x4ab6ab  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4ab6af  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4ab6b2  5f                               pop    edi
0x4ab6b3  5e                               pop    esi
0x4ab6b4  5b                               pop    ebx
0x4ab6b5  5d                               pop    ebp
0x4ab6b6  c20400                           ret    0x4
0x4ab6b9  cc                               int3
0x4ab6ba  cc                               int3
0x4ab6bb  cc                               int3
0x4ab6bc  cc                               int3
0x4ab6bd  cc                               int3
0x4ab6be  cc                               int3
0x4ab6bf  cc                               int3

; closure_Tutorial_InsertIsilia | Lua closure and conversion call
; VA 0x4ac830..0x4ac890 raw 0xabc30 length 96 sha256 019c7059c53696dc25b9664b9f2355fdb331f59451985937cae3617f4dc88ad1
0x4ac830  55                               push   ebp
0x4ac831  8bec                             mov    ebp,esp
0x4ac833  6aff                             push   0xffffffff
0x4ac835  68c8839300                       push   0x9383c8
0x4ac83a  64a100000000                     mov    eax,fs:0x0
0x4ac840  50                               push   eax
0x4ac841  83ec0c                           sub    esp,0xc
0x4ac844  a1201fd600                       mov    eax,ds:0xd61f20
0x4ac849  33c5                             xor    eax,ebp
0x4ac84b  50                               push   eax
0x4ac84c  8d45f4                           lea    eax,[ebp-0xc]
0x4ac84f  64a300000000                     mov    fs:0x0,eax
0x4ac855  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4ac858  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4ac85b  33c0                             xor    eax,eax
0x4ac85d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4ac860  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4ac863  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4ac866  8b0d0418fe00                     mov    ecx,DWORD PTR ds:0xfe1804
0x4ac86c  ff156c18fe00                     call   DWORD PTR ds:0xfe186c
0x4ac872  b801000000                       mov    eax,0x1
0x4ac877  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4ac87a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4ac881  59                               pop    ecx
0x4ac882  8be5                             mov    esp,ebp
0x4ac884  5d                               pop    ebp
0x4ac885  c3                               ret
0x4ac886  cc                               int3
0x4ac887  cc                               int3
0x4ac888  cc                               int3
0x4ac889  cc                               int3
0x4ac88a  cc                               int3
0x4ac88b  cc                               int3
0x4ac88c  cc                               int3
0x4ac88d  cc                               int3
0x4ac88e  cc                               int3
0x4ac88f  cc                               int3

; name_Tutorial_InsertIsilia | registered ASCII symbol
; VA 0xd6ad24..0xd6ad31 raw 0x968524 length 13 sha256 29f37bc6b1b4f98d6207e29f55f9c18860e1256cc454df1e5deffe1b1dfb72c9
db 496e736572744973696c696100

; register_Q_AniObject | actual public registration
; VA 0x566f60..0x567000 raw 0x166360 length 160 sha256 9804ab752be8affaf8af6e3b50e298c9d79b25f5c0e30cf70ef81ef3ccb46720
0x566f60  55                               push   ebp
0x566f61  8bec                             mov    ebp,esp
0x566f63  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x566f66  53                               push   ebx
0x566f67  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0x566f6d  56                               push   esi
0x566f6e  8b33                             mov    esi,DWORD PTR [ebx]
0x566f70  57                               push   edi
0x566f71  8b38                             mov    edi,DWORD PTR [eax]
0x566f73  b8eed8ffff                       mov    eax,0xffffd8ee
0x566f78  c705e427fe00e0345600             mov    DWORD PTR ds:0xfe27e4,0x5634e0
0x566f82  e8f9e61800                       call   0x6f5680
0x566f87  8b03                             mov    eax,DWORD PTR [ebx]
0x566f89  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x566f8c  83e810                           sub    eax,0x10
0x566f8f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x566f94  7406                             je     0x566f9c
0x566f96  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x566f9a  7414                             je     0x566fb0
0x566f9c  57                               push   edi
0x566f9d  68c426c400                       push   0xc426c4
0x566fa2  e816c13200                       call   0x8930bd
0x566fa7  8b1b                             mov    ebx,DWORD PTR [ebx]
0x566fa9  83c408                           add    esp,0x8
0x566fac  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x566fb0  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
0x566fb6  8b37                             mov    esi,DWORD PTR [edi]
0x566fb8  68d4a3d600                       push   0xd6a3d4
0x566fbd  e84ee51800                       call   0x6f5510
0x566fc2  8b37                             mov    esi,DWORD PTR [edi]
0x566fc4  83c404                           add    esp,0x4
0x566fc7  6a00                             push   0x0
0x566fc9  6800945600                       push   0x569400
0x566fce  e8dde51800                       call   0x6f55b0
0x566fd3  8b0f                             mov    ecx,DWORD PTR [edi]
0x566fd5  51                               push   ecx
0x566fd6  b8fdffffff                       mov    eax,0xfffffffd
0x566fdb  e810e81800                       call   0x6f57f0
0x566fe0  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
0x566fe6  8b02                             mov    eax,DWORD PTR [edx]
0x566fe8  83c40c                           add    esp,0xc
0x566feb  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x566fef  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x566ff2  5f                               pop    edi
0x566ff3  5e                               pop    esi
0x566ff4  5b                               pop    ebx
0x566ff5  5d                               pop    ebp
0x566ff6  c20400                           ret    0x4
0x566ff9  cc                               int3
0x566ffa  cc                               int3
0x566ffb  cc                               int3
0x566ffc  cc                               int3
0x566ffd  cc                               int3
0x566ffe  cc                               int3
0x566fff  cc                               int3

; closure_Q_AniObject | Lua closure and conversion call
; VA 0x569400..0x569460 raw 0x168800 length 96 sha256 2f98a3f01ee6800454a95af94996d4dceadadc57a418bad36cd3424ff9bb7566
0x569400  55                               push   ebp
0x569401  8bec                             mov    ebp,esp
0x569403  6aff                             push   0xffffffff
0x569405  68c8839300                       push   0x9383c8
0x56940a  64a100000000                     mov    eax,fs:0x0
0x569410  50                               push   eax
0x569411  83ec0c                           sub    esp,0xc
0x569414  a1201fd600                       mov    eax,ds:0xd61f20
0x569419  33c5                             xor    eax,ebp
0x56941b  50                               push   eax
0x56941c  8d45f4                           lea    eax,[ebp-0xc]
0x56941f  64a300000000                     mov    fs:0x0,eax
0x569425  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x569428  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x56942b  33c0                             xor    eax,eax
0x56942d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x569430  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x569433  8d4de8                           lea    ecx,[ebp-0x18]
0x569436  51                               push   ecx
0x569437  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x56943a  e8a11c0000                       call   0x56b0e0
0x56943f  83c404                           add    esp,0x4
0x569442  b801000000                       mov    eax,0x1
0x569447  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x56944a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x569451  59                               pop    ecx
0x569452  8be5                             mov    esp,ebp
0x569454  5d                               pop    ebp
0x569455  c3                               ret
0x569456  cc                               int3
0x569457  cc                               int3
0x569458  cc                               int3
0x569459  cc                               int3
0x56945a  cc                               int3
0x56945b  cc                               int3
0x56945c  cc                               int3
0x56945d  cc                               int3
0x56945e  cc                               int3
0x56945f  cc                               int3

; name_Q_AniObject | registered ASCII symbol
; VA 0xd6a3d4..0xd6a3de raw 0x967bd4 length 10 sha256 f16b47a517c6815d5d7f10c62b55187cdd65d8f187267b7c19f7545a01505110
db 416e694f626a65637400

; register_Q_AniSkip | actual public registration
; VA 0x567000..0x5670a0 raw 0x166400 length 160 sha256 30273676d0e2cd5963815118cd984dd5d10a2d4d5597feee7c5c77374d9dfdc5
0x567000  55                               push   ebp
0x567001  8bec                             mov    ebp,esp
0x567003  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x567006  53                               push   ebx
0x567007  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0x56700d  56                               push   esi
0x56700e  8b33                             mov    esi,DWORD PTR [ebx]
0x567010  57                               push   edi
0x567011  8b38                             mov    edi,DWORD PTR [eax]
0x567013  b8eed8ffff                       mov    eax,0xffffd8ee
0x567018  c705e827fe0030355600             mov    DWORD PTR ds:0xfe27e8,0x563530
0x567022  e859e61800                       call   0x6f5680
0x567027  8b03                             mov    eax,DWORD PTR [ebx]
0x567029  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x56702c  83e810                           sub    eax,0x10
0x56702f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x567034  7406                             je     0x56703c
0x567036  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x56703a  7414                             je     0x567050
0x56703c  57                               push   edi
0x56703d  68c426c400                       push   0xc426c4
0x567042  e876c03200                       call   0x8930bd
0x567047  8b1b                             mov    ebx,DWORD PTR [ebx]
0x567049  83c408                           add    esp,0x8
0x56704c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x567050  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
0x567056  8b37                             mov    esi,DWORD PTR [edi]
0x567058  68e0a3d600                       push   0xd6a3e0
0x56705d  e8aee41800                       call   0x6f5510
0x567062  8b37                             mov    esi,DWORD PTR [edi]
0x567064  83c404                           add    esp,0x4
0x567067  6a00                             push   0x0
0x567069  6860945600                       push   0x569460
0x56706e  e83de51800                       call   0x6f55b0
0x567073  8b0f                             mov    ecx,DWORD PTR [edi]
0x567075  51                               push   ecx
0x567076  b8fdffffff                       mov    eax,0xfffffffd
0x56707b  e870e71800                       call   0x6f57f0
0x567080  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
0x567086  8b02                             mov    eax,DWORD PTR [edx]
0x567088  83c40c                           add    esp,0xc
0x56708b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x56708f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x567092  5f                               pop    edi
0x567093  5e                               pop    esi
0x567094  5b                               pop    ebx
0x567095  5d                               pop    ebp
0x567096  c20400                           ret    0x4
0x567099  cc                               int3
0x56709a  cc                               int3
0x56709b  cc                               int3
0x56709c  cc                               int3
0x56709d  cc                               int3
0x56709e  cc                               int3
0x56709f  cc                               int3

; closure_Q_AniSkip | Lua closure and conversion call
; VA 0x569460..0x5694c0 raw 0x168860 length 96 sha256 d5b76101fa7d995bce7c3899919aa1453fcbbf31c383203099f8b984372d0b10
0x569460  55                               push   ebp
0x569461  8bec                             mov    ebp,esp
0x569463  6aff                             push   0xffffffff
0x569465  68c8839300                       push   0x9383c8
0x56946a  64a100000000                     mov    eax,fs:0x0
0x569470  50                               push   eax
0x569471  83ec0c                           sub    esp,0xc
0x569474  a1201fd600                       mov    eax,ds:0xd61f20
0x569479  33c5                             xor    eax,ebp
0x56947b  50                               push   eax
0x56947c  8d45f4                           lea    eax,[ebp-0xc]
0x56947f  64a300000000                     mov    fs:0x0,eax
0x569485  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x569488  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x56948b  33c0                             xor    eax,eax
0x56948d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x569490  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x569493  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x569496  8b0de827fe00                     mov    ecx,DWORD PTR ds:0xfe27e8
0x56949c  51                               push   ecx
0x56949d  8d55e8                           lea    edx,[ebp-0x18]
0x5694a0  52                               push   edx
0x5694a1  e87a0d0000                       call   0x56a220
0x5694a6  83c408                           add    esp,0x8
0x5694a9  b801000000                       mov    eax,0x1
0x5694ae  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5694b1  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5694b8  59                               pop    ecx
0x5694b9  8be5                             mov    esp,ebp
0x5694bb  5d                               pop    ebp
0x5694bc  c3                               ret
0x5694bd  cc                               int3
0x5694be  cc                               int3
0x5694bf  cc                               int3

; name_Q_AniSkip | registered ASCII symbol
; VA 0xd6a3e0..0xd6a3e8 raw 0x967be0 length 8 sha256 64d762e3e2672d838aa5a1bb795f42f1f0af2618becd4359fd366ad4f21d10e9
db 416e69536b697000

; register_Q_RotateObject | actual public registration
; VA 0x5670a0..0x567140 raw 0x1664a0 length 160 sha256 ee59cd86bf1f2bb2f0bfed64466202ea21f6ba707c91ac480372d9df73430d60
0x5670a0  55                               push   ebp
0x5670a1  8bec                             mov    ebp,esp
0x5670a3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5670a6  53                               push   ebx
0x5670a7  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0x5670ad  56                               push   esi
0x5670ae  8b33                             mov    esi,DWORD PTR [ebx]
0x5670b0  57                               push   edi
0x5670b1  8b38                             mov    edi,DWORD PTR [eax]
0x5670b3  b8eed8ffff                       mov    eax,0xffffd8ee
0x5670b8  c705ec27fe0060365600             mov    DWORD PTR ds:0xfe27ec,0x563660
0x5670c2  e8b9e51800                       call   0x6f5680
0x5670c7  8b03                             mov    eax,DWORD PTR [ebx]
0x5670c9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x5670cc  83e810                           sub    eax,0x10
0x5670cf  3dc8bfc000                       cmp    eax,0xc0bfc8
0x5670d4  7406                             je     0x5670dc
0x5670d6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x5670da  7414                             je     0x5670f0
0x5670dc  57                               push   edi
0x5670dd  68c426c400                       push   0xc426c4
0x5670e2  e8d6bf3200                       call   0x8930bd
0x5670e7  8b1b                             mov    ebx,DWORD PTR [ebx]
0x5670e9  83c408                           add    esp,0x8
0x5670ec  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x5670f0  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
0x5670f6  8b37                             mov    esi,DWORD PTR [edi]
0x5670f8  68e8a3d600                       push   0xd6a3e8
0x5670fd  e80ee41800                       call   0x6f5510
0x567102  8b37                             mov    esi,DWORD PTR [edi]
0x567104  83c404                           add    esp,0x4
0x567107  6a00                             push   0x0
0x567109  68c0945600                       push   0x5694c0
0x56710e  e89de41800                       call   0x6f55b0
0x567113  8b0f                             mov    ecx,DWORD PTR [edi]
0x567115  51                               push   ecx
0x567116  b8fdffffff                       mov    eax,0xfffffffd
0x56711b  e8d0e61800                       call   0x6f57f0
0x567120  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
0x567126  8b02                             mov    eax,DWORD PTR [edx]
0x567128  83c40c                           add    esp,0xc
0x56712b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x56712f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x567132  5f                               pop    edi
0x567133  5e                               pop    esi
0x567134  5b                               pop    ebx
0x567135  5d                               pop    ebp
0x567136  c20400                           ret    0x4
0x567139  cc                               int3
0x56713a  cc                               int3
0x56713b  cc                               int3
0x56713c  cc                               int3
0x56713d  cc                               int3
0x56713e  cc                               int3
0x56713f  cc                               int3

; closure_Q_RotateObject | Lua closure and conversion call
; VA 0x5694c0..0x569520 raw 0x1688c0 length 96 sha256 e270633f2d8786073d6601476f2aa87040d0353f68891cce49ea00c9a9041ae8
0x5694c0  55                               push   ebp
0x5694c1  8bec                             mov    ebp,esp
0x5694c3  6aff                             push   0xffffffff
0x5694c5  68c8839300                       push   0x9383c8
0x5694ca  64a100000000                     mov    eax,fs:0x0
0x5694d0  50                               push   eax
0x5694d1  83ec0c                           sub    esp,0xc
0x5694d4  a1201fd600                       mov    eax,ds:0xd61f20
0x5694d9  33c5                             xor    eax,ebp
0x5694db  50                               push   eax
0x5694dc  8d45f4                           lea    eax,[ebp-0xc]
0x5694df  64a300000000                     mov    fs:0x0,eax
0x5694e5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5694e8  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x5694eb  33c0                             xor    eax,eax
0x5694ed  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x5694f0  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x5694f3  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x5694f6  8b0dec27fe00                     mov    ecx,DWORD PTR ds:0xfe27ec
0x5694fc  51                               push   ecx
0x5694fd  8d55e8                           lea    edx,[ebp-0x18]
0x569500  52                               push   edx
0x569501  e8aa0f0000                       call   0x56a4b0
0x569506  83c408                           add    esp,0x8
0x569509  b801000000                       mov    eax,0x1
0x56950e  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x569511  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x569518  59                               pop    ecx
0x569519  8be5                             mov    esp,ebp
0x56951b  5d                               pop    ebp
0x56951c  c3                               ret
0x56951d  cc                               int3
0x56951e  cc                               int3
0x56951f  cc                               int3

; name_Q_RotateObject | registered ASCII symbol
; VA 0xd6a3e8..0xd6a3f5 raw 0x967be8 length 13 sha256 1d5ee237cb99ba365447c0e248bea4c0b7db52cb1b8bfb60b0c5a2de70a2c052
db 526f746174654f626a65637400

; register_Q_SpeedObject | actual public registration
; VA 0x567140..0x5671e0 raw 0x166540 length 160 sha256 7d115d44dfb84a814e47b8b28107459f3ec038c3d57ccd8ab2e5ae7c6051d783
0x567140  55                               push   ebp
0x567141  8bec                             mov    ebp,esp
0x567143  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x567146  53                               push   ebx
0x567147  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0x56714d  56                               push   esi
0x56714e  8b33                             mov    esi,DWORD PTR [ebx]
0x567150  57                               push   edi
0x567151  8b38                             mov    edi,DWORD PTR [eax]
0x567153  b8eed8ffff                       mov    eax,0xffffd8ee
0x567158  c705f027fe00f0365600             mov    DWORD PTR ds:0xfe27f0,0x5636f0
0x567162  e819e51800                       call   0x6f5680
0x567167  8b03                             mov    eax,DWORD PTR [ebx]
0x567169  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x56716c  83e810                           sub    eax,0x10
0x56716f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x567174  7406                             je     0x56717c
0x567176  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x56717a  7414                             je     0x567190
0x56717c  57                               push   edi
0x56717d  68c426c400                       push   0xc426c4
0x567182  e836bf3200                       call   0x8930bd
0x567187  8b1b                             mov    ebx,DWORD PTR [ebx]
0x567189  83c408                           add    esp,0x8
0x56718c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x567190  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
0x567196  8b37                             mov    esi,DWORD PTR [edi]
0x567198  68f8a3d600                       push   0xd6a3f8
0x56719d  e86ee31800                       call   0x6f5510
0x5671a2  8b37                             mov    esi,DWORD PTR [edi]
0x5671a4  83c404                           add    esp,0x4
0x5671a7  6a00                             push   0x0
0x5671a9  6820955600                       push   0x569520
0x5671ae  e8fde31800                       call   0x6f55b0
0x5671b3  8b0f                             mov    ecx,DWORD PTR [edi]
0x5671b5  51                               push   ecx
0x5671b6  b8fdffffff                       mov    eax,0xfffffffd
0x5671bb  e830e61800                       call   0x6f57f0
0x5671c0  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
0x5671c6  8b02                             mov    eax,DWORD PTR [edx]
0x5671c8  83c40c                           add    esp,0xc
0x5671cb  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x5671cf  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5671d2  5f                               pop    edi
0x5671d3  5e                               pop    esi
0x5671d4  5b                               pop    ebx
0x5671d5  5d                               pop    ebp
0x5671d6  c20400                           ret    0x4
0x5671d9  cc                               int3
0x5671da  cc                               int3
0x5671db  cc                               int3
0x5671dc  cc                               int3
0x5671dd  cc                               int3
0x5671de  cc                               int3
0x5671df  cc                               int3

; closure_Q_SpeedObject | Lua closure and conversion call
; VA 0x569520..0x569580 raw 0x168920 length 96 sha256 ed61fc0e89f6c07f9b903f96a6ab614ae2c210f20945102a90ae386c5a6a06da
0x569520  55                               push   ebp
0x569521  8bec                             mov    ebp,esp
0x569523  6aff                             push   0xffffffff
0x569525  68c8839300                       push   0x9383c8
0x56952a  64a100000000                     mov    eax,fs:0x0
0x569530  50                               push   eax
0x569531  83ec0c                           sub    esp,0xc
0x569534  a1201fd600                       mov    eax,ds:0xd61f20
0x569539  33c5                             xor    eax,ebp
0x56953b  50                               push   eax
0x56953c  8d45f4                           lea    eax,[ebp-0xc]
0x56953f  64a300000000                     mov    fs:0x0,eax
0x569545  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x569548  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x56954b  33c0                             xor    eax,eax
0x56954d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x569550  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x569553  8d4de8                           lea    ecx,[ebp-0x18]
0x569556  51                               push   ecx
0x569557  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x56955a  e8b11c0000                       call   0x56b210
0x56955f  83c404                           add    esp,0x4
0x569562  b801000000                       mov    eax,0x1
0x569567  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x56956a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x569571  59                               pop    ecx
0x569572  8be5                             mov    esp,ebp
0x569574  5d                               pop    ebp
0x569575  c3                               ret
0x569576  cc                               int3
0x569577  cc                               int3
0x569578  cc                               int3
0x569579  cc                               int3
0x56957a  cc                               int3
0x56957b  cc                               int3
0x56957c  cc                               int3
0x56957d  cc                               int3
0x56957e  cc                               int3
0x56957f  cc                               int3

; name_Q_SpeedObject | registered ASCII symbol
; VA 0xd6a3f8..0xd6a404 raw 0x967bf8 length 12 sha256 6dcfa37f2e3397e775176ea8917df093ea8fdf63e90e9a75906c87d4cde306ab
db 53706565644f626a65637400

; register_Q_FaceObject | actual public registration
; VA 0x5671e0..0x567280 raw 0x1665e0 length 160 sha256 fef1600251c6f169a25af72c5d4cde6a2ba83dbe7471cf052c525fa967aab31a
0x5671e0  55                               push   ebp
0x5671e1  8bec                             mov    ebp,esp
0x5671e3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5671e6  53                               push   ebx
0x5671e7  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0x5671ed  56                               push   esi
0x5671ee  8b33                             mov    esi,DWORD PTR [ebx]
0x5671f0  57                               push   edi
0x5671f1  8b38                             mov    edi,DWORD PTR [eax]
0x5671f3  b8eed8ffff                       mov    eax,0xffffd8ee
0x5671f8  c705f427fe0030375600             mov    DWORD PTR ds:0xfe27f4,0x563730
0x567202  e879e41800                       call   0x6f5680
0x567207  8b03                             mov    eax,DWORD PTR [ebx]
0x567209  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x56720c  83e810                           sub    eax,0x10
0x56720f  3dc8bfc000                       cmp    eax,0xc0bfc8
0x567214  7406                             je     0x56721c
0x567216  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x56721a  7414                             je     0x567230
0x56721c  57                               push   edi
0x56721d  68c426c400                       push   0xc426c4
0x567222  e896be3200                       call   0x8930bd
0x567227  8b1b                             mov    ebx,DWORD PTR [ebx]
0x567229  83c408                           add    esp,0x8
0x56722c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x567230  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
0x567236  8b37                             mov    esi,DWORD PTR [edi]
0x567238  6804a4d600                       push   0xd6a404
0x56723d  e8cee21800                       call   0x6f5510
0x567242  8b37                             mov    esi,DWORD PTR [edi]
0x567244  83c404                           add    esp,0x4
0x567247  6a00                             push   0x0
0x567249  6880955600                       push   0x569580
0x56724e  e85de31800                       call   0x6f55b0
0x567253  8b0f                             mov    ecx,DWORD PTR [edi]
0x567255  51                               push   ecx
0x567256  b8fdffffff                       mov    eax,0xfffffffd
0x56725b  e890e51800                       call   0x6f57f0
0x567260  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
0x567266  8b02                             mov    eax,DWORD PTR [edx]
0x567268  83c40c                           add    esp,0xc
0x56726b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x56726f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x567272  5f                               pop    edi
0x567273  5e                               pop    esi
0x567274  5b                               pop    ebx
0x567275  5d                               pop    ebp
0x567276  c20400                           ret    0x4
0x567279  cc                               int3
0x56727a  cc                               int3
0x56727b  cc                               int3
0x56727c  cc                               int3
0x56727d  cc                               int3
0x56727e  cc                               int3
0x56727f  cc                               int3

; closure_Q_FaceObject | Lua closure and conversion call
; VA 0x569580..0x5695e0 raw 0x168980 length 96 sha256 cc53ffe02ce10085d38f177023f10322639979ed4b46f54eef28a093bf0ba84f
0x569580  55                               push   ebp
0x569581  8bec                             mov    ebp,esp
0x569583  6aff                             push   0xffffffff
0x569585  68c8839300                       push   0x9383c8
0x56958a  64a100000000                     mov    eax,fs:0x0
0x569590  50                               push   eax
0x569591  83ec0c                           sub    esp,0xc
0x569594  a1201fd600                       mov    eax,ds:0xd61f20
0x569599  33c5                             xor    eax,ebp
0x56959b  50                               push   eax
0x56959c  8d45f4                           lea    eax,[ebp-0xc]
0x56959f  64a300000000                     mov    fs:0x0,eax
0x5695a5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5695a8  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x5695ab  33c0                             xor    eax,eax
0x5695ad  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x5695b0  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x5695b3  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x5695b6  8b0df427fe00                     mov    ecx,DWORD PTR ds:0xfe27f4
0x5695bc  51                               push   ecx
0x5695bd  8d55e8                           lea    edx,[ebp-0x18]
0x5695c0  52                               push   edx
0x5695c1  e8ea0e0000                       call   0x56a4b0
0x5695c6  83c408                           add    esp,0x8
0x5695c9  b801000000                       mov    eax,0x1
0x5695ce  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5695d1  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5695d8  59                               pop    ecx
0x5695d9  8be5                             mov    esp,ebp
0x5695db  5d                               pop    ebp
0x5695dc  c3                               ret
0x5695dd  cc                               int3
0x5695de  cc                               int3
0x5695df  cc                               int3

; name_Q_FaceObject | registered ASCII symbol
; VA 0xd6a404..0xd6a40f raw 0x967c04 length 11 sha256 f909f2ca1d5cfba3e078906ab1ace4d2adf4c2c1f771994071bce625fe2c3bf8
db 466163654f626a65637400

; register_Q_FlashObject | actual public registration
; VA 0x5673c0..0x567460 raw 0x1667c0 length 160 sha256 db1946a6ada9987961511a60c0d604d46b8bb0c1260120f16b8d36676c15dcae
0x5673c0  55                               push   ebp
0x5673c1  8bec                             mov    ebp,esp
0x5673c3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5673c6  53                               push   ebx
0x5673c7  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0x5673cd  56                               push   esi
0x5673ce  8b33                             mov    esi,DWORD PTR [ebx]
0x5673d0  57                               push   edi
0x5673d1  8b38                             mov    edi,DWORD PTR [eax]
0x5673d3  b8eed8ffff                       mov    eax,0xffffd8ee
0x5673d8  c7050028fe0090375600             mov    DWORD PTR ds:0xfe2800,0x563790
0x5673e2  e899e21800                       call   0x6f5680
0x5673e7  8b03                             mov    eax,DWORD PTR [ebx]
0x5673e9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x5673ec  83e810                           sub    eax,0x10
0x5673ef  3dc8bfc000                       cmp    eax,0xc0bfc8
0x5673f4  7406                             je     0x5673fc
0x5673f6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x5673fa  7414                             je     0x567410
0x5673fc  57                               push   edi
0x5673fd  68c426c400                       push   0xc426c4
0x567402  e8b6bc3200                       call   0x8930bd
0x567407  8b1b                             mov    ebx,DWORD PTR [ebx]
0x567409  83c408                           add    esp,0x8
0x56740c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x567410  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
0x567416  8b37                             mov    esi,DWORD PTR [edi]
0x567418  6828a4d600                       push   0xd6a428
0x56741d  e8eee01800                       call   0x6f5510
0x567422  8b37                             mov    esi,DWORD PTR [edi]
0x567424  83c404                           add    esp,0x4
0x567427  6a00                             push   0x0
0x567429  68a0965600                       push   0x5696a0
0x56742e  e87de11800                       call   0x6f55b0
0x567433  8b0f                             mov    ecx,DWORD PTR [edi]
0x567435  51                               push   ecx
0x567436  b8fdffffff                       mov    eax,0xfffffffd
0x56743b  e8b0e31800                       call   0x6f57f0
0x567440  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
0x567446  8b02                             mov    eax,DWORD PTR [edx]
0x567448  83c40c                           add    esp,0xc
0x56744b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x56744f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x567452  5f                               pop    edi
0x567453  5e                               pop    esi
0x567454  5b                               pop    ebx
0x567455  5d                               pop    ebp
0x567456  c20400                           ret    0x4
0x567459  cc                               int3
0x56745a  cc                               int3
0x56745b  cc                               int3
0x56745c  cc                               int3
0x56745d  cc                               int3
0x56745e  cc                               int3
0x56745f  cc                               int3

; closure_Q_FlashObject | Lua closure and conversion call
; VA 0x5696a0..0x569700 raw 0x168aa0 length 96 sha256 7c85c45acac09c6d1bce9e62fcc09c15e5622e93405c7cec24191d03895b6084
0x5696a0  55                               push   ebp
0x5696a1  8bec                             mov    ebp,esp
0x5696a3  6aff                             push   0xffffffff
0x5696a5  68c8839300                       push   0x9383c8
0x5696aa  64a100000000                     mov    eax,fs:0x0
0x5696b0  50                               push   eax
0x5696b1  83ec0c                           sub    esp,0xc
0x5696b4  a1201fd600                       mov    eax,ds:0xd61f20
0x5696b9  33c5                             xor    eax,ebp
0x5696bb  50                               push   eax
0x5696bc  8d45f4                           lea    eax,[ebp-0xc]
0x5696bf  64a300000000                     mov    fs:0x0,eax
0x5696c5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x5696c8  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x5696cb  33c0                             xor    eax,eax
0x5696cd  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x5696d0  8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x5696d3  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x5696d6  8b0d0028fe00                     mov    ecx,DWORD PTR ds:0xfe2800
0x5696dc  51                               push   ecx
0x5696dd  8d55e8                           lea    edx,[ebp-0x18]
0x5696e0  52                               push   edx
0x5696e1  e8ca0d0000                       call   0x56a4b0
0x5696e6  83c408                           add    esp,0x8
0x5696e9  b801000000                       mov    eax,0x1
0x5696ee  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5696f1  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5696f8  59                               pop    ecx
0x5696f9  8be5                             mov    esp,ebp
0x5696fb  5d                               pop    ebp
0x5696fc  c3                               ret
0x5696fd  cc                               int3
0x5696fe  cc                               int3
0x5696ff  cc                               int3

; name_Q_FlashObject | registered ASCII symbol
; VA 0xd6a428..0xd6a434 raw 0x967c28 length 12 sha256 78cab685d99e5e4f5f0e93d6df911757e652812845ab62c3fd264d382418b455
db 466c6173684f626a65637400
