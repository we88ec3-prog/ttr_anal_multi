; I01: local factory, WORD ID assignment, insert, increment and optional controller attachment
; VA 0x004a0f70..0x004a122d, raw 0x000a0370, SHA256 2025e90b45dabd10b017588673b58af5cdeb115834a700b644e29e7c2c3696c4
004a0f70  55                               push   ebp
004a0f71  8bec                             mov    ebp,esp
004a0f73  83e4f8                           and    esp,0xfffffff8
004a0f76  6aff                             push   0xffffffff
004a0f78  686b9f9300                       push   0x939f6b
004a0f7d  64a100000000                     mov    eax,fs:0x0
004a0f83  50                               push   eax
004a0f84  83ec18                           sub    esp,0x18
004a0f87  53                               push   ebx
004a0f88  56                               push   esi
004a0f89  57                               push   edi
004a0f8a  a1201fd600                       mov    eax,ds:0xd61f20
004a0f8f  33c4                             xor    eax,esp
004a0f91  50                               push   eax
004a0f92  8d442428                         lea    eax,[esp+0x28]
004a0f96  64a300000000                     mov    fs:0x0,eax
004a0f9c  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
004a0f9f  33f6                             xor    esi,esi
004a0fa1  33db                             xor    ebx,ebx
004a0fa3  83ff0a                           cmp    edi,0xa
004a0fa6  7c10                             jl     0x4a0fb8
004a0fa8  81ff10270000                     cmp    edi,0x2710
004a0fae  0f9ec3                           setle  bl
004a0fb1  4b                               dec    ebx
004a0fb2  83e305                           and    ebx,0x5
004a0fb5  43                               inc    ebx
004a0fb6  7527                             jne    0x4a0fdf
004a0fb8  6844040000                       push   0x444
004a0fbd  e8a6023f00                       call   0x891268
004a0fc2  83c404                           add    esp,0x4
004a0fc5  89442414                         mov    DWORD PTR [esp+0x14],eax
004a0fc9  c744243000000000                 mov    DWORD PTR [esp+0x30],0x0
004a0fd1  85c0                             test   eax,eax
004a0fd3  746e                             je     0x4a1043
004a0fd5  6a00                             push   0x0
004a0fd7  50                               push   eax
004a0fd8  e813c70200                       call   0x4cd6f0
004a0fdd  eb66                             jmp    0x4a1045
004a0fdf  83fb01                           cmp    ebx,0x1
004a0fe2  7535                             jne    0x4a1019
004a0fe4  6834040000                       push   0x434
004a0fe9  e87a023f00                       call   0x891268
004a0fee  83c404                           add    esp,0x4
004a0ff1  89442414                         mov    DWORD PTR [esp+0x14],eax
004a0ff5  895c2430                         mov    DWORD PTR [esp+0x30],ebx
004a0ff9  85c0                             test   eax,eax
004a0ffb  7408                             je     0x4a1005
004a0ffd  50                               push   eax
004a0ffe  e80d070300                       call   0x4d1710
004a1003  eb02                             jmp    0x4a1007
004a1005  33c0                             xor    eax,eax
004a1007  57                               push   edi
004a1008  c7442434ffffffff                 mov    DWORD PTR [esp+0x34],0xffffffff
004a1010  8bf0                             mov    esi,eax
004a1012  e8b9fdffff                       call   0x4a0dd0
004a1017  eb36                             jmp    0x4a104f
004a1019  83fb06                           cmp    ebx,0x6
004a101c  7531                             jne    0x4a104f
004a101e  682c040000                       push   0x42c
004a1023  e840023f00                       call   0x891268
004a1028  83c404                           add    esp,0x4
004a102b  89442414                         mov    DWORD PTR [esp+0x14],eax
004a102f  c744243002000000                 mov    DWORD PTR [esp+0x30],0x2
004a1037  85c0                             test   eax,eax
004a1039  7408                             je     0x4a1043
004a103b  50                               push   eax
004a103c  e8df100300                       call   0x4d2120
004a1041  eb02                             jmp    0x4a1045
004a1043  33c0                             xor    eax,eax
004a1045  8bf0                             mov    esi,eax
004a1047  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
004a104f  66a104def700                     mov    ax,ds:0xf7de04
004a1055  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
004a105a  8b16                             mov    edx,DWORD PTR [esi]
004a105c  8b5244                           mov    edx,DWORD PTR [edx+0x44]
004a105f  66894604                         mov    WORD PTR [esi+0x4],ax
004a1063  6a01                             push   0x1
004a1065  8d442418                         lea    eax,[esp+0x18]
004a1069  f30f11442418                     movss  DWORD PTR [esp+0x18],xmm0
004a106f  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
004a1074  50                               push   eax
004a1075  8bce                             mov    ecx,esi
004a1077  f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
004a107d  ffd2                             call   edx
004a107f  8b4d18                           mov    ecx,DWORD PTR [ebp+0x18]
004a1082  8b06                             mov    eax,DWORD PTR [esi]
004a1084  8b5058                           mov    edx,DWORD PTR [eax+0x58]
004a1087  51                               push   ecx
004a1088  8bce                             mov    ecx,esi
004a108a  ffd2                             call   edx
004a108c  8b06                             mov    eax,DWORD PTR [esi]
004a108e  8b403c                           mov    eax,DWORD PTR [eax+0x3c]
004a1091  0fb6cb                           movzx  ecx,bl
004a1094  0fb7d7                           movzx  edx,di
004a1097  c1e118                           shl    ecx,0x18
004a109a  0bca                             or     ecx,edx
004a109c  51                               push   ecx
004a109d  8bce                             mov    ecx,esi
004a109f  ffd0                             call   eax
004a10a1  83ff0a                           cmp    edi,0xa
004a10a4  bf01000000                       mov    edi,0x1
004a10a9  7d24                             jge    0x4a10cf
004a10ab  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
004a10b1  8bcf                             mov    ecx,edi
004a10b3  66898e88030000                   mov    WORD PTR [esi+0x388],cx
004a10ba  85c0                             test   eax,eax
004a10bc  7411                             je     0x4a10cf
004a10be  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
004a10c5  7408                             je     0x4a10cf
004a10c7  57                               push   edi
004a10c8  57                               push   edi
004a10c9  50                               push   eax
004a10ca  e8d15d3000                       call   0x7a6ea0
004a10cf  8b16                             mov    edx,DWORD PTR [esi]
004a10d1  8b4230                           mov    eax,DWORD PTR [edx+0x30]
004a10d4  8bce                             mov    ecx,esi
004a10d6  ffd0                             call   eax
004a10d8  f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
004a10df  7528                             jne    0x4a1109
004a10e1  093d2888fb00                     or     DWORD PTR ds:0xfb8828,edi
004a10e7  c744243003000000                 mov    DWORD PTR [esp+0x30],0x3
004a10ef  e85ce70a00                       call   0x54f850
004a10f4  6880d5bc00                       push   0xbcd580
004a10f9  e81c123f00                       call   0x89231a
004a10fe  83c404                           add    esp,0x4
004a1101  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
004a1109  db4514                           fild   DWORD PTR [ebp+0x14]
004a110c  8b16                             mov    edx,DWORD PTR [esi]
004a110e  8b425c                           mov    eax,DWORD PTR [edx+0x5c]
004a1111  51                               push   ecx
004a1112  d80dbc90fb00                     fmul   DWORD PTR ds:0xfb90bc
004a1118  8bce                             mov    ecx,esi
004a111a  d95c2418                         fstp   DWORD PTR [esp+0x18]
004a111e  d9442418                         fld    DWORD PTR [esp+0x18]
004a1122  d91c24                           fstp   DWORD PTR [esp]
004a1125  ffd0                             call   eax
004a1127  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
004a112c  8b16                             mov    edx,DWORD PTR [esi]
004a112e  8b5244                           mov    edx,DWORD PTR [edx+0x44]
004a1131  57                               push   edi
004a1132  8d442420                         lea    eax,[esp+0x20]
004a1136  f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
004a113c  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
004a1141  50                               push   eax
004a1142  8bce                             mov    ecx,esi
004a1144  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
004a114a  ffd2                             call   edx
004a114c  8b86f0000000                     mov    eax,DWORD PTR [esi+0xf0]
004a1152  8b5008                           mov    edx,DWORD PTR [eax+0x8]
004a1155  8d8ef0000000                     lea    ecx,[esi+0xf0]
004a115b  57                               push   edi
004a115c  ffd2                             call   edx
004a115e  d9e8                             fld1
004a1160  8b06                             mov    eax,DWORD PTR [esi]
004a1162  8b5068                           mov    edx,DWORD PTR [eax+0x68]
004a1165  51                               push   ecx
004a1166  d91c24                           fstp   DWORD PTR [esp]
004a1169  57                               push   edi
004a116a  8bce                             mov    ecx,esi
004a116c  ffd2                             call   edx
004a116e  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
004a1175  f30f1005b45ac500                 movss  xmm0,DWORD PTR ds:0xc55ab4
004a117d  f30f1186cc000000                 movss  DWORD PTR [esi+0xcc],xmm0
004a1185  7528                             jne    0x4a11af
004a1187  093d2cb2fa00                     or     DWORD PTR ds:0xfab22c,edi
004a118d  c744243004000000                 mov    DWORD PTR [esp+0x30],0x4
004a1195  e8f6da0300                       call   0x4dec90
004a119a  6830cebc00                       push   0xbcce30
004a119f  e876113f00                       call   0x89231a
004a11a4  83c404                           add    esp,0x4
004a11a7  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
004a11af  6830b1fa00                       push   0xfab130
004a11b4  8bc6                             mov    eax,esi
004a11b6  e875ed0300                       call   0x4dff30
004a11bb  013d04def700                     add    DWORD PTR ds:0xf7de04,edi
004a11c1  837d1c00                         cmp    DWORD PTR [ebp+0x1c],0x0
004a11c5  7451                             je     0x4a1218
004a11c7  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004a11cd  8b01                             mov    eax,DWORD PTR [ecx]
004a11cf  8b5004                           mov    edx,DWORD PTR [eax+0x4]
004a11d2  56                               push   esi
004a11d3  897904                           mov    DWORD PTR [ecx+0x4],edi
004a11d6  ffd2                             call   edx
004a11d8  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004a11de  8b01                             mov    eax,DWORD PTR [ecx]
004a11e0  8b5010                           mov    edx,DWORD PTR [eax+0x10]
004a11e3  ffd2                             call   edx
004a11e5  f605147cfb0001                   test   BYTE PTR ds:0xfb7c14,0x1
004a11ec  7520                             jne    0x4a120e
004a11ee  093d147cfb00                     or     DWORD PTR ds:0xfb7c14,edi
004a11f4  c744243005000000                 mov    DWORD PTR [esp+0x30],0x5
004a11fc  e84ff52200                       call   0x6d0750
004a1201  6830d5bc00                       push   0xbcd530
004a1206  e80f113f00                       call   0x89231a
004a120b  83c404                           add    esp,0x4
004a120e  c7053088fb0000000000             mov    DWORD PTR ds:0xfb8830,0x0
004a1218  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
004a121c  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004a1223  59                               pop    ecx
004a1224  5f                               pop    edi
004a1225  5e                               pop    esi
004a1226  5b                               pop    ebx
004a1227  8be5                             mov    esp,ebp
004a1229  5d                               pop    ebp
004a122a  c21800                           ret    0x18

; I02: world insertion: unique insert versus warning-only existing key
; VA 0x004dff30..0x004dffaa, raw 0x000df330, SHA256 3f117a1e4bbff0df9e40958c1e7d3af22bdfe8c05860d441437b37af52d18295
004dff30  55                               push   ebp
004dff31  8bec                             mov    ebp,esp
004dff33  83ec10                           sub    esp,0x10
004dff36  53                               push   ebx
004dff37  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004dff3a  56                               push   esi
004dff3b  57                               push   edi
004dff3c  8bf8                             mov    edi,eax
004dff3e  85ff                             test   edi,edi
004dff40  750a                             jne    0x4dff4c
004dff42  68d0cec000                       push   0xc0ced0
004dff47  e824dd2000                       call   0x6edc70
004dff4c  0fb74704                         movzx  eax,WORD PTR [edi+0x4]
004dff50  8d4d08                           lea    ecx,[ebp+0x8]
004dff53  894508                           mov    DWORD PTR [ebp+0x8],eax
004dff56  8d7308                           lea    esi,[ebx+0x8]
004dff59  51                               push   ecx
004dff5a  8d45f8                           lea    eax,[ebp-0x8]
004dff5d  8bce                             mov    ecx,esi
004dff5f  e89cef3400                       call   0x82ef00
004dff64  8b55f8                           mov    edx,DWORD PTR [ebp-0x8]
004dff67  3b530c                           cmp    edx,DWORD PTR [ebx+0xc]
004dff6a  7524                             jne    0x4dff90
004dff6c  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004dff6f  897df8                           mov    DWORD PTR [ebp-0x8],edi
004dff72  8d7df4                           lea    edi,[ebp-0xc]
004dff75  8945f4                           mov    DWORD PTR [ebp-0xc],eax
004dff78  e8a3ef0900                       call   0x57ef20
004dff7d  50                               push   eax
004dff7e  56                               push   esi
004dff7f  8d75f4                           lea    esi,[ebp-0xc]
004dff82  e879f23400                       call   0x82f200
004dff87  5f                               pop    edi
004dff88  5e                               pop    esi
004dff89  5b                               pop    ebx
004dff8a  8be5                             mov    esp,ebp
004dff8c  5d                               pop    ebp
004dff8d  c20400                           ret    0x4
004dff90  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
004dff93  51                               push   ecx
004dff94  68f0cec000                       push   0xc0cef0
004dff99  e8c2db2000                       call   0x6edb60
004dff9e  83c408                           add    esp,0x8
004dffa1  5f                               pop    edi
004dffa2  5e                               pop    esi
004dffa3  5b                               pop    ebx
004dffa4  8be5                             mov    esp,ebp
004dffa6  5d                               pop    ebp
004dffa7  c20400                           ret    0x4

; I03: 24-byte tree node: DWORD key +0C, actor pointer +10
; VA 0x0057ef20..0x0057ef60, raw 0x0017e320, SHA256 1c10bc49692f53834b201855d977750cb83b2d08208edeb63e2c1a358faf3549
0057ef20  55                               push   ebp
0057ef21  8bec                             mov    ebp,esp
0057ef23  83ec10                           sub    esp,0x10
0057ef26  6a18                             push   0x18
0057ef28  e83b233100                       call   0x891268
0057ef2d  33d2                             xor    edx,edx
0057ef2f  83c404                           add    esp,0x4
0057ef32  3bc2                             cmp    eax,edx
0057ef34  742a                             je     0x57ef60
0057ef36  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0057ef39  8908                             mov    DWORD PTR [eax],ecx
0057ef3b  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0057ef3e  894804                           mov    DWORD PTR [eax+0x4],ecx
0057ef41  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0057ef44  894808                           mov    DWORD PTR [eax+0x8],ecx
0057ef47  8d480c                           lea    ecx,[eax+0xc]
0057ef4a  66895014                         mov    WORD PTR [eax+0x14],dx
0057ef4e  3bca                             cmp    ecx,edx
0057ef50  740a                             je     0x57ef5c
0057ef52  8b17                             mov    edx,DWORD PTR [edi]
0057ef54  8911                             mov    DWORD PTR [ecx],edx
0057ef56  8b5704                           mov    edx,DWORD PTR [edi+0x4]
0057ef59  895104                           mov    DWORD PTR [ecx+0x4],edx
0057ef5c  8be5                             mov    esp,ebp
0057ef5e  5d                               pop    ebp
0057ef5f  c3                               ret

; I04: world-map unsigned DWORD key lookup
; VA 0x0082ef00..0x0082ef67, raw 0x0042e300, SHA256 8aa14d38c50c3cba4e1df1035c559905be926880ec559950ed0676578cfefc6b
0082ef00  55                               push   ebp
0082ef01  8bec                             mov    ebp,esp
0082ef03  51                               push   ecx
0082ef04  53                               push   ebx
0082ef05  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0082ef08  56                               push   esi
0082ef09  8bf1                             mov    esi,ecx
0082ef0b  8b5604                           mov    edx,DWORD PTR [esi+0x4]
0082ef0e  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
0082ef11  80791500                         cmp    BYTE PTR [ecx+0x15],0x0
0082ef15  751e                             jne    0x82ef35
0082ef17  57                               push   edi
0082ef18  8b3b                             mov    edi,DWORD PTR [ebx]
0082ef1a  8d9b00000000                     lea    ebx,[ebx+0x0]
0082ef20  39790c                           cmp    DWORD PTR [ecx+0xc],edi
0082ef23  7305                             jae    0x82ef2a
0082ef25  8b4908                           mov    ecx,DWORD PTR [ecx+0x8]
0082ef28  eb04                             jmp    0x82ef2e
0082ef2a  8bd1                             mov    edx,ecx
0082ef2c  8b09                             mov    ecx,DWORD PTR [ecx]
0082ef2e  80791500                         cmp    BYTE PTR [ecx+0x15],0x0
0082ef32  74ec                             je     0x82ef20
0082ef34  5f                               pop    edi
0082ef35  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
0082ef38  895508                           mov    DWORD PTR [ebp+0x8],edx
0082ef3b  3bd1                             cmp    edx,ecx
0082ef3d  7416                             je     0x82ef55
0082ef3f  8b33                             mov    esi,DWORD PTR [ebx]
0082ef41  3b720c                           cmp    esi,DWORD PTR [edx+0xc]
0082ef44  720f                             jb     0x82ef55
0082ef46  8d4d08                           lea    ecx,[ebp+0x8]
0082ef49  8b09                             mov    ecx,DWORD PTR [ecx]
0082ef4b  5e                               pop    esi
0082ef4c  8908                             mov    DWORD PTR [eax],ecx
0082ef4e  5b                               pop    ebx
0082ef4f  8be5                             mov    esp,ebp
0082ef51  5d                               pop    ebp
0082ef52  c20400                           ret    0x4
0082ef55  894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0082ef58  8d4dfc                           lea    ecx,[ebp-0x4]
0082ef5b  8b09                             mov    ecx,DWORD PTR [ecx]
0082ef5d  5e                               pop    esi
0082ef5e  8908                             mov    DWORD PTR [eax],ecx
0082ef60  5b                               pop    ebx
0082ef61  8be5                             mov    esp,ebp
0082ef63  5d                               pop    ebp
0082ef64  c20400                           ret    0x4

; I05: unique tree insert; duplicate frees new node only
; VA 0x0082f200..0x0082f2c6, raw 0x0042e600, SHA256 3dc78d4ed988394eebd6ba66314de66efada035ad6af50a88291840d4cfc5599
0082f200  55                               push   ebp
0082f201  8bec                             mov    ebp,esp
0082f203  83ec08                           sub    esp,0x8
0082f206  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0082f209  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0082f20c  53                               push   ebx
0082f20d  57                               push   edi
0082f20e  8b7804                           mov    edi,DWORD PTR [eax+0x4]
0082f211  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0082f214  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0082f218  b101                             mov    cl,0x1
0082f21a  884df8                           mov    BYTE PTR [ebp-0x8],cl
0082f21d  751f                             jne    0x82f23e
0082f21f  8b5a0c                           mov    ebx,DWORD PTR [edx+0xc]
0082f222  3b580c                           cmp    ebx,DWORD PTR [eax+0xc]
0082f225  8bf8                             mov    edi,eax
0082f227  0f92c1                           setb   cl
0082f22a  884df8                           mov    BYTE PTR [ebp-0x8],cl
0082f22d  84c9                             test   cl,cl
0082f22f  7404                             je     0x82f235
0082f231  8b00                             mov    eax,DWORD PTR [eax]
0082f233  eb03                             jmp    0x82f238
0082f235  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0082f238  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0082f23c  74e4                             je     0x82f222
0082f23e  8bdf                             mov    ebx,edi
0082f240  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0082f243  84c9                             test   cl,cl
0082f245  743a                             je     0x82f281
0082f247  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0082f24a  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0082f24d  3b38                             cmp    edi,DWORD PTR [eax]
0082f24f  7522                             jne    0x82f273
0082f251  52                               push   edx
0082f252  6a01                             push   0x1
0082f254  8d550c                           lea    edx,[ebp+0xc]
0082f257  8bc7                             mov    eax,edi
0082f259  52                               push   edx
0082f25a  8bf9                             mov    edi,ecx
0082f25c  e89fcac1ff                       call   0x44bd00
0082f261  8b00                             mov    eax,DWORD PTR [eax]
0082f263  5f                               pop    edi
0082f264  8906                             mov    DWORD PTR [esi],eax
0082f266  c6460401                         mov    BYTE PTR [esi+0x4],0x1
0082f26a  8bc6                             mov    eax,esi
0082f26c  5b                               pop    ebx
0082f26d  8be5                             mov    esp,ebp
0082f26f  5d                               pop    ebp
0082f270  c20800                           ret    0x8
0082f273  8d45fc                           lea    eax,[ebp-0x4]
0082f276  e82506d1ff                       call   0x53f8a0
0082f27b  8b5dfc                           mov    ebx,DWORD PTR [ebp-0x4]
0082f27e  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0082f281  8b4b0c                           mov    ecx,DWORD PTR [ebx+0xc]
0082f284  52                               push   edx
0082f285  3b4a0c                           cmp    ecx,DWORD PTR [edx+0xc]
0082f288  7324                             jae    0x82f2ae
0082f28a  8b55f8                           mov    edx,DWORD PTR [ebp-0x8]
0082f28d  52                               push   edx
0082f28e  8d450c                           lea    eax,[ebp+0xc]
0082f291  50                               push   eax
0082f292  8bc7                             mov    eax,edi
0082f294  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0082f297  e864cac1ff                       call   0x44bd00
0082f29c  8b08                             mov    ecx,DWORD PTR [eax]
0082f29e  5f                               pop    edi
0082f29f  890e                             mov    DWORD PTR [esi],ecx
0082f2a1  c6460401                         mov    BYTE PTR [esi+0x4],0x1
0082f2a5  8bc6                             mov    eax,esi
0082f2a7  5b                               pop    ebx
0082f2a8  8be5                             mov    esp,ebp
0082f2aa  5d                               pop    ebp
0082f2ab  c20800                           ret    0x8
0082f2ae  e8591f0600                       call   0x89120c
0082f2b3  83c404                           add    esp,0x4
0082f2b6  5f                               pop    edi
0082f2b7  891e                             mov    DWORD PTR [esi],ebx
0082f2b9  c6460400                         mov    BYTE PTR [esi+0x4],0x0
0082f2bd  8bc6                             mov    eax,esi
0082f2bf  5b                               pop    ebx
0082f2c0  8be5                             mov    esp,ebp
0082f2c2  5d                               pop    ebp
0082f2c3  c20800                           ret    0x8

; I06: 0007 row count, existing-ID skip, low-byte factory dispatch, metadata and insertion
; VA 0x004ae4d0..0x004aed8d, raw 0x000ad8d0, SHA256 500f4eef861516c51948deb5b41051fa1a7a22050ab3c407bbb55a02d27597d5
004ae4d0  55                               push   ebp
004ae4d1  8bec                             mov    ebp,esp
004ae4d3  83e4f8                           and    esp,0xfffffff8
004ae4d6  6aff                             push   0xffffffff
004ae4d8  68db0c9400                       push   0x940cdb
004ae4dd  64a100000000                     mov    eax,fs:0x0
004ae4e3  50                               push   eax
004ae4e4  81ec38010000                     sub    esp,0x138
004ae4ea  a1201fd600                       mov    eax,ds:0xd61f20
004ae4ef  33c4                             xor    eax,esp
004ae4f1  89842430010000                   mov    DWORD PTR [esp+0x130],eax
004ae4f8  53                               push   ebx
004ae4f9  56                               push   esi
004ae4fa  57                               push   edi
004ae4fb  a1201fd600                       mov    eax,ds:0xd61f20
004ae500  33c4                             xor    eax,esp
004ae502  50                               push   eax
004ae503  8d842448010000                   lea    eax,[esp+0x148]
004ae50a  64a300000000                     mov    fs:0x0,eax
004ae510  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
004ae513  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004ae516  83f802                           cmp    eax,0x2
004ae519  7304                             jae    0x4ae51f
004ae51b  33d2                             xor    edx,edx
004ae51d  eb0d                             jmp    0x4ae52c
004ae51f  8d48fe                           lea    ecx,[eax-0x2]
004ae522  b84fecc44e                       mov    eax,0x4ec4ec4f
004ae527  f7e1                             mul    ecx
004ae529  c1ea03                           shr    edx,0x3
004ae52c  89542428                         mov    DWORD PTR [esp+0x28],edx
004ae530  c744242400000000                 mov    DWORD PTR [esp+0x24],0x0
004ae538  85d2                             test   edx,edx
004ae53a  0f8418080000                     je     0x4aed58
004ae540  83c306                           add    ebx,0x6
004ae543  eb0b                             jmp    0x4ae550
004ae545  8da42400000000                   lea    esp,[esp+0x0]
004ae54c  8d642400                         lea    esp,[esp+0x0]
004ae550  b801000000                       mov    eax,0x1
004ae555  89442420                         mov    DWORD PTR [esp+0x20],eax
004ae559  84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
004ae55f  752e                             jne    0x4ae58f
004ae561  09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
004ae567  c784245001000000000000           mov    DWORD PTR [esp+0x150],0x0
004ae572  e819070300                       call   0x4dec90
004ae577  6830cebc00                       push   0xbcce30
004ae57c  e8993d3e00                       call   0x89231a
004ae581  83c404                           add    esp,0x4
004ae584  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004ae58f  0fb753fc                         movzx  edx,WORD PTR [ebx-0x4]
004ae593  8d442418                         lea    eax,[esp+0x18]
004ae597  50                               push   eax
004ae598  8d442458                         lea    eax,[esp+0x58]
004ae59c  b938b1fa00                       mov    ecx,0xfab138
004ae5a1  8954241c                         mov    DWORD PTR [esp+0x1c],edx
004ae5a5  e856093800                       call   0x82ef00
004ae5aa  8b08                             mov    ecx,DWORD PTR [eax]
004ae5ac  3b0d3cb1fa00                     cmp    ecx,DWORD PTR ds:0xfab13c
004ae5b2  0f858a070000                     jne    0x4aed42
004ae5b8  0fb643fc                         movzx  eax,BYTE PTR [ebx-0x4]
004ae5bc  0fb67bfe                         movzx  edi,BYTE PTR [ebx-0x2]
004ae5c0  0fb70b                           movzx  ecx,WORD PTR [ebx]
004ae5c3  4f                               dec    edi
004ae5c4  8bd0                             mov    edx,eax
004ae5c6  c1e208                           shl    edx,0x8
004ae5c9  0bfa                             or     edi,edx
004ae5cb  c1e710                           shl    edi,0x10
004ae5ce  0bf9                             or     edi,ecx
004ae5d0  897c241c                         mov    DWORD PTR [esp+0x1c],edi
004ae5d4  83f807                           cmp    eax,0x7
004ae5d7  0f87a6070000                     ja     0x4aed83
004ae5dd  ff248590ed4a00                   jmp    DWORD PTR [eax*4+0x4aed90]
004ae5e4  6844040000                       push   0x444
004ae5e9  e87a2c3e00                       call   0x891268
004ae5ee  83c404                           add    esp,0x4
004ae5f1  89442414                         mov    DWORD PTR [esp+0x14],eax
004ae5f5  c784245001000001000000           mov    DWORD PTR [esp+0x150],0x1
004ae600  85c0                             test   eax,eax
004ae602  740e                             je     0x4ae612
004ae604  8b530e                           mov    edx,DWORD PTR [ebx+0xe]
004ae607  52                               push   edx
004ae608  50                               push   eax
004ae609  e8e2f00100                       call   0x4cd6f0
004ae60e  8bf0                             mov    esi,eax
004ae610  eb02                             jmp    0x4ae614
004ae612  33f6                             xor    esi,esi
004ae614  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004ae61f  e87c65f5ff                       call   0x404ba0
004ae624  8b80505f0000                     mov    eax,DWORD PTR [eax+0x5f50]
004ae62a  39430e                           cmp    DWORD PTR [ebx+0xe],eax
004ae62d  0f85e4020000                     jne    0x4ae917
004ae633  e86865f5ff                       call   0x404ba0
004ae638  8b9024690000                     mov    edx,DWORD PTR [eax+0x6924]
004ae63e  0fb703                           movzx  eax,WORD PTR [ebx]
004ae641  83f809                           cmp    eax,0x9
004ae644  0f87cd020000                     ja     0x4ae917
004ae64a  8bc8                             mov    ecx,eax
004ae64c  69c910020000                     imul   ecx,ecx,0x210
004ae652  03ca                             add    ecx,edx
004ae654  0f84bd020000                     je     0x4ae917
004ae65a  83795c00                         cmp    DWORD PTR [ecx+0x5c],0x0
004ae65e  0f85b3020000                     jne    0x4ae917
004ae664  8b11                             mov    edx,DWORD PTR [ecx]
004ae666  50                               push   eax
004ae667  8b4204                           mov    eax,DWORD PTR [edx+0x4]
004ae66a  ffd0                             call   eax
004ae66c  e9a6020000                       jmp    0x4ae917
004ae671  6834040000                       push   0x434
004ae676  e8ed2b3e00                       call   0x891268
004ae67b  83c404                           add    esp,0x4
004ae67e  89442414                         mov    DWORD PTR [esp+0x14],eax
004ae682  c784245001000002000000           mov    DWORD PTR [esp+0x150],0x2
004ae68d  85c0                             test   eax,eax
004ae68f  740a                             je     0x4ae69b
004ae691  50                               push   eax
004ae692  e879300200                       call   0x4d1710
004ae697  8bf0                             mov    esi,eax
004ae699  eb02                             jmp    0x4ae69d
004ae69b  33f6                             xor    esi,esi
004ae69d  6a48                             push   0x48
004ae69f  c7842454010000ffffffff           mov    DWORD PTR [esp+0x154],0xffffffff
004ae6aa  e8b92b3e00                       call   0x891268
004ae6af  8bf8                             mov    edi,eax
004ae6b1  83c404                           add    esp,0x4
004ae6b4  897c2414                         mov    DWORD PTR [esp+0x14],edi
004ae6b8  c784245001000003000000           mov    DWORD PTR [esp+0x150],0x3
004ae6c3  85ff                             test   edi,edi
004ae6c5  7478                             je     0x4ae73f
004ae6c7  0fb74604                         movzx  eax,WORD PTR [esi+0x4]
004ae6cb  0f57c0                           xorps  xmm0,xmm0
004ae6ce  894704                           mov    DWORD PTR [edi+0x4],eax
004ae6d1  c70707000000                     mov    DWORD PTR [edi],0x7
004ae6d7  c7470801000000                   mov    DWORD PTR [edi+0x8],0x1
004ae6de  c6470c01                         mov    BYTE PTR [edi+0xc],0x1
004ae6e2  8b4b02                           mov    ecx,DWORD PTR [ebx+0x2]
004ae6e5  894f10                           mov    DWORD PTR [edi+0x10],ecx
004ae6e8  8b5306                           mov    edx,DWORD PTR [ebx+0x6]
004ae6eb  895714                           mov    DWORD PTR [edi+0x14],edx
004ae6ee  f30f1144243c                     movss  DWORD PTR [esp+0x3c],xmm0
004ae6f4  8b4c243c                         mov    ecx,DWORD PTR [esp+0x3c]
004ae6f8  894f20                           mov    DWORD PTR [edi+0x20],ecx
004ae6fb  33d2                             xor    edx,edx
004ae6fd  f30f11442438                     movss  DWORD PTR [esp+0x38],xmm0
004ae703  8b442438                         mov    eax,DWORD PTR [esp+0x38]
004ae707  8d4f24                           lea    ecx,[edi+0x24]
004ae70a  f30f114718                       movss  DWORD PTR [edi+0x18],xmm0
004ae70f  89471c                           mov    DWORD PTR [edi+0x1c],eax
004ae712  52                               push   edx
004ae713  c7411407000000                   mov    DWORD PTR [ecx+0x14],0x7
004ae71a  c7411000000000                   mov    DWORD PTR [ecx+0x10],0x0
004ae721  68fcd1be00                       push   0xbed1fc
004ae726  668911                           mov    WORD PTR [ecx],dx
004ae729  e8323af5ff                       call   0x402160
004ae72e  0f57c0                           xorps  xmm0,xmm0
004ae731  c7474000000000                   mov    DWORD PTR [edi+0x40],0x0
004ae738  f30f114744                       movss  DWORD PTR [edi+0x44],xmm0
004ae73d  eb02                             jmp    0x4ae741
004ae73f  33ff                             xor    edi,edi
004ae741  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004ae74c  f605c0f3fd0001                   test   BYTE PTR ds:0xfdf3c0,0x1
004ae753  751e                             jne    0x4ae773
004ae755  830dc0f3fd0001                   or     DWORD PTR ds:0xfdf3c0,0x1
004ae75c  6850dfbc00                       push   0xbcdf50
004ae761  c705c4f3fd0000000000             mov    DWORD PTR ds:0xfdf3c4,0x0
004ae76b  e8aa3b3e00                       call   0x89231a
004ae770  83c404                           add    esp,0x4
004ae773  a1c4f3fd00                       mov    eax,ds:0xfdf3c4
004ae778  57                               push   edi
004ae779  50                               push   eax
004ae77a  e8410e0c00                       call   0x56f5c0
004ae77f  f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
004ae786  0fb64313                         movzx  eax,BYTE PTR [ebx+0x13]
004ae78a  898624040000                     mov    DWORD PTR [esi+0x424],eax
004ae790  752f                             jne    0x4ae7c1
004ae792  830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
004ae799  c784245001000004000000           mov    DWORD PTR [esp+0x150],0x4
004ae7a4  e8d7550400                       call   0x4f3d80
004ae7a9  68e0d1bc00                       push   0xbcd1e0
004ae7ae  e8673b3e00                       call   0x89231a
004ae7b3  83c404                           add    esp,0x4
004ae7b6  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004ae7c1  8b4c241c                         mov    ecx,DWORD PTR [esp+0x1c]
004ae7c5  894c2418                         mov    DWORD PTR [esp+0x18],ecx
004ae7c9  8d542418                         lea    edx,[esp+0x18]
004ae7cd  b97074fb00                       mov    ecx,0xfb7470
004ae7d2  e899920400                       call   0x4f7a70
004ae7d7  80786100                         cmp    BYTE PTR [eax+0x61],0x0
004ae7db  751c                             jne    0x4ae7f9
004ae7dd  8b8668030000                     mov    eax,DWORD PTR [esi+0x368]
004ae7e3  33c9                             xor    ecx,ecx
004ae7e5  894c2420                         mov    DWORD PTR [esp+0x20],ecx
004ae7e9  3bc1                             cmp    eax,ecx
004ae7eb  7414                             je     0x4ae801
004ae7ed  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
004ae7f1  894824                           mov    DWORD PTR [eax+0x24],ecx
004ae7f4  e91e010000                       jmp    0x4ae917
004ae7f9  c744242001000000                 mov    DWORD PTR [esp+0x20],0x1
004ae801  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
004ae805  e90d010000                       jmp    0x4ae917
004ae80a  682c040000                       push   0x42c
004ae80f  e8542a3e00                       call   0x891268
004ae814  83c404                           add    esp,0x4
004ae817  89442414                         mov    DWORD PTR [esp+0x14],eax
004ae81b  c784245001000005000000           mov    DWORD PTR [esp+0x150],0x5
004ae826  85c0                             test   eax,eax
004ae828  740c                             je     0x4ae836
004ae82a  50                               push   eax
004ae82b  e8f0380200                       call   0x4d2120
004ae830  89442418                         mov    DWORD PTR [esp+0x18],eax
004ae834  eb08                             jmp    0x4ae83e
004ae836  c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
004ae83e  83ceff                           or     esi,0xffffffff
004ae841  89b42450010000                   mov    DWORD PTR [esp+0x150],esi
004ae848  f605c818fe0001                   test   BYTE PTR ds:0xfe18c8,0x1
004ae84f  752b                             jne    0x4ae87c
004ae851  830dc818fe0001                   or     DWORD PTR ds:0xfe18c8,0x1
004ae858  c784245001000006000000           mov    DWORD PTR [esp+0x150],0x6
004ae863  e808110900                       call   0x53f970
004ae868  6810e8bc00                       push   0xbce810
004ae86d  e8a83a3e00                       call   0x89231a
004ae872  83c404                           add    esp,0x4
004ae875  89b42450010000                   mov    DWORD PTR [esp+0x150],esi
004ae87c  0fb733                           movzx  esi,WORD PTR [ebx]
004ae87f  8d542414                         lea    edx,[esp+0x14]
004ae883  52                               push   edx
004ae884  8d442444                         lea    eax,[esp+0x44]
004ae888  b9dc18fe00                       mov    ecx,0xfe18dc
004ae88d  89742418                         mov    DWORD PTR [esp+0x18],esi
004ae891  e82a503900                       call   0x8438c0
004ae896  8b4c2440                         mov    ecx,DWORD PTR [esp+0x40]
004ae89a  3b0de018fe00                     cmp    ecx,DWORD PTR ds:0xfe18e0
004ae8a0  742e                             je     0x4ae8d0
004ae8a2  8a43fd                           mov    al,BYTE PTR [ebx-0x3]
004ae8a5  88442444                         mov    BYTE PTR [esp+0x44],al
004ae8a9  8b4110                           mov    eax,DWORD PTR [ecx+0x10]
004ae8ac  8b0dec18fe00                     mov    ecx,DWORD PTR ds:0xfe18ec
004ae8b2  8944244c                         mov    DWORD PTR [esp+0x4c],eax
004ae8b6  8d442444                         lea    eax,[esp+0x44]
004ae8ba  bfcc18fe00                       mov    edi,0xfe18cc
004ae8bf  89742448                         mov    DWORD PTR [esp+0x48],esi
004ae8c3  894c2450                         mov    DWORD PTR [esp+0x50],ecx
004ae8c7  e8d4020900                       call   0x53eba0
004ae8cc  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
004ae8d0  8b742418                         mov    esi,DWORD PTR [esp+0x18]
004ae8d4  eb41                             jmp    0x4ae917
004ae8d6  6828040000                       push   0x428
004ae8db  e888293e00                       call   0x891268
004ae8e0  83c404                           add    esp,0x4
004ae8e3  89442414                         mov    DWORD PTR [esp+0x14],eax
004ae8e7  c784245001000007000000           mov    DWORD PTR [esp+0x150],0x7
004ae8f2  85c0                             test   eax,eax
004ae8f4  7408                             je     0x4ae8fe
004ae8f6  50                               push   eax
004ae8f7  e864270200                       call   0x4d1060
004ae8fc  eb02                             jmp    0x4ae900
004ae8fe  33c0                             xor    eax,eax
004ae900  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004ae90b  0fb64b13                         movzx  ecx,BYTE PTR [ebx+0x13]
004ae90f  898820040000                     mov    DWORD PTR [eax+0x420],ecx
004ae915  8bf0                             mov    esi,eax
004ae917  85f6                             test   esi,esi
004ae919  0f8464040000                     je     0x4aed83
004ae91f  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
004ae926  752f                             jne    0x4ae957
004ae928  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
004ae92f  c784245001000008000000           mov    DWORD PTR [esp+0x150],0x8
004ae93a  e801e62e00                       call   0x79cf40
004ae93f  6880dbbc00                       push   0xbcdb80
004ae944  e8d1393e00                       call   0x89231a
004ae949  83c404                           add    esp,0x4
004ae94c  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004ae957  0fb713                           movzx  edx,WORD PTR [ebx]
004ae95a  8d442414                         lea    eax,[esp+0x14]
004ae95e  50                               push   eax
004ae95f  8d442430                         lea    eax,[esp+0x30]
004ae963  b9900efc00                       mov    ecx,0xfc0e90
004ae968  89542418                         mov    DWORD PTR [esp+0x18],edx
004ae96c  e81f6e0600                       call   0x515790
004ae971  8b44242c                         mov    eax,DWORD PTR [esp+0x2c]
004ae975  3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
004ae97b  740d                             je     0x4ae98a
004ae97d  8b4010                           mov    eax,DWORD PTR [eax+0x10]
004ae980  83785400                         cmp    DWORD PTR [eax+0x54],0x0
004ae984  0f8523010000                     jne    0x4aeaad
004ae98a  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004ae990  8b11                             mov    edx,DWORD PTR [ecx]
004ae992  8b4220                           mov    eax,DWORD PTR [edx+0x20]
004ae995  ffd0                             call   eax
004ae997  85c0                             test   eax,eax
004ae999  0f84cd000000                     je     0x4aea6c
004ae99f  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
004ae9a6  8b889c000000                     mov    ecx,DWORD PTR [eax+0x9c]
004ae9ac  894c2414                         mov    DWORD PTR [esp+0x14],ecx
004ae9b0  752f                             jne    0x4ae9e1
004ae9b2  830d2cb2fa0001                   or     DWORD PTR ds:0xfab22c,0x1
004ae9b9  c784245001000009000000           mov    DWORD PTR [esp+0x150],0x9
004ae9c4  e8c7020300                       call   0x4dec90
004ae9c9  6830cebc00                       push   0xbcce30
004ae9ce  e847393e00                       call   0x89231a
004ae9d3  83c404                           add    esp,0x4
004ae9d6  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004ae9e1  8b542414                         mov    edx,DWORD PTR [esp+0x14]
004ae9e5  8d442414                         lea    eax,[esp+0x14]
004ae9e9  50                               push   eax
004ae9ea  8d442438                         lea    eax,[esp+0x38]
004ae9ee  b948b1fa00                       mov    ecx,0xfab148
004ae9f3  89542418                         mov    DWORD PTR [esp+0x18],edx
004ae9f7  e8c44e3900                       call   0x8438c0
004ae9fc  8b442434                         mov    eax,DWORD PTR [esp+0x34]
004aea00  3b054cb1fa00                     cmp    eax,DWORD PTR ds:0xfab14c
004aea06  7464                             je     0x4aea6c
004aea08  8b4010                           mov    eax,DWORD PTR [eax+0x10]
004aea0b  85c0                             test   eax,eax
004aea0d  745d                             je     0x4aea6c
004aea0f  80782005                         cmp    BYTE PTR [eax+0x20],0x5
004aea13  7257                             jb     0x4aea6c
004aea15  0fb70b                           movzx  ecx,WORD PTR [ebx]
004aea18  51                               push   ecx
004aea19  68d869c000                       push   0xc069d8
004aea1e  8d54247c                         lea    edx,[esp+0x7c]
004aea22  e859920000                       call   0x4b7c80
004aea27  83c408                           add    esp,0x8
004aea2a  8d542474                         lea    edx,[esp+0x74]
004aea2e  52                               push   edx
004aea2f  8d4c245c                         lea    ecx,[esp+0x5c]
004aea33  e81838f5ff                       call   0x402250
004aea38  8d442458                         lea    eax,[esp+0x58]
004aea3c  50                               push   eax
004aea3d  c78424540100000a000000           mov    DWORD PTR [esp+0x154],0xa
004aea48  e8730ef6ff                       call   0x40f8c0
004aea4d  8bf8                             mov    edi,eax
004aea4f  e8dc800200                       call   0x4d6b30
004aea54  8d4c2458                         lea    ecx,[esp+0x58]
004aea58  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004aea63  e8d8b90400                       call   0x4fa440
004aea68  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
004aea6c  f605400efc0001                   test   BYTE PTR ds:0xfc0e40,0x1
004aea73  752f                             jne    0x4aeaa4
004aea75  830d400efc0001                   or     DWORD PTR ds:0xfc0e40,0x1
004aea7c  c78424500100000b000000           mov    DWORD PTR [esp+0x150],0xb
004aea87  e8e41c0900                       call   0x540770
004aea8c  6860dbbc00                       push   0xbcdb60
004aea91  e884383e00                       call   0x89231a
004aea96  83c404                           add    esp,0x4
004aea99  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004aeaa4  0fb70b                           movzx  ecx,WORD PTR [ebx]
004aeaa7  51                               push   ecx
004aeaa8  e8632b0900                       call   0x541610
004aeaad  f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
004aeab4  752f                             jne    0x4aeae5
004aeab6  830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
004aeabd  c78424500100000c000000           mov    DWORD PTR [esp+0x150],0xc
004aeac8  e8b3520400                       call   0x4f3d80
004aeacd  68e0d1bc00                       push   0xbcd1e0
004aead2  e843383e00                       call   0x89231a
004aead7  83c404                           add    esp,0x4
004aeada  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004aeae5  8d542414                         lea    edx,[esp+0x14]
004aeae9  b97074fb00                       mov    ecx,0xfb7470
004aeaee  897c2414                         mov    DWORD PTR [esp+0x14],edi
004aeaf2  e8798f0400                       call   0x4f7a70
004aeaf7  0fb65061                         movzx  edx,BYTE PTR [eax+0x61]
004aeafb  8b86f0000000                     mov    eax,DWORD PTR [esi+0xf0]
004aeb01  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004aeb04  89961c040000                     mov    DWORD PTR [esi+0x41c],edx
004aeb0a  0fb65315                         movzx  edx,BYTE PTR [ebx+0x15]
004aeb0e  8d8ef0000000                     lea    ecx,[esi+0xf0]
004aeb14  52                               push   edx
004aeb15  ffd0                             call   eax
004aeb17  8b430e                           mov    eax,DWORD PTR [ebx+0xe]
004aeb1a  8b16                             mov    edx,DWORD PTR [esi]
004aeb1c  89869c000000                     mov    DWORD PTR [esi+0x9c],eax
004aeb22  0fb64314                         movzx  eax,BYTE PTR [ebx+0x14]
004aeb26  898690000000                     mov    DWORD PTR [esi+0x90],eax
004aeb2c  668b43fc                         mov    ax,WORD PTR [ebx-0x4]
004aeb30  66894604                         mov    WORD PTR [esi+0x4],ax
004aeb34  8b423c                           mov    eax,DWORD PTR [edx+0x3c]
004aeb37  57                               push   edi
004aeb38  8bce                             mov    ecx,esi
004aeb3a  ffd0                             call   eax
004aeb3c  8b16                             mov    edx,DWORD PTR [esi]
004aeb3e  8b5244                           mov    edx,DWORD PTR [edx+0x44]
004aeb41  6a01                             push   0x1
004aeb43  8d4302                           lea    eax,[ebx+0x2]
004aeb46  50                               push   eax
004aeb47  8bce                             mov    ecx,esi
004aeb49  ffd2                             call   edx
004aeb4b  0fb64b12                         movzx  ecx,BYTE PTR [ebx+0x12]
004aeb4f  8b06                             mov    eax,DWORD PTR [esi]
004aeb51  8b5058                           mov    edx,DWORD PTR [eax+0x58]
004aeb54  51                               push   ecx
004aeb55  8bce                             mov    ecx,esi
004aeb57  ffd2                             call   edx
004aeb59  8b06                             mov    eax,DWORD PTR [esi]
004aeb5b  d9430a                           fld    DWORD PTR [ebx+0xa]
004aeb5e  8b505c                           mov    edx,DWORD PTR [eax+0x5c]
004aeb61  51                               push   ecx
004aeb62  8bce                             mov    ecx,esi
004aeb64  d91c24                           fstp   DWORD PTR [esp]
004aeb67  ffd2                             call   edx
004aeb69  807b1518                         cmp    BYTE PTR [ebx+0x15],0x18
004aeb6d  7507                             jne    0x4aeb76
004aeb6f  c686bc00000001                   mov    BYTE PTR [esi+0xbc],0x1
004aeb76  8b06                             mov    eax,DWORD PTR [esi]
004aeb78  8b5030                           mov    edx,DWORD PTR [eax+0x30]
004aeb7b  8bce                             mov    ecx,esi
004aeb7d  ffd2                             call   edx
004aeb7f  8a43fc                           mov    al,BYTE PTR [ebx-0x4]
004aeb82  3c01                             cmp    al,0x1
004aeb84  7529                             jne    0x4aebaf
004aeb86  837c242000                       cmp    DWORD PTR [esp+0x20],0x0
004aeb8b  7511                             jne    0x4aeb9e
004aeb8d  8b8668030000                     mov    eax,DWORD PTR [esi+0x368]
004aeb93  85c0                             test   eax,eax
004aeb95  7407                             je     0x4aeb9e
004aeb97  c7402400000000                   mov    DWORD PTR [eax+0x24],0x0
004aeb9e  33c0                             xor    eax,eax
004aeba0  807b1304                         cmp    BYTE PTR [ebx+0x13],0x4
004aeba4  0f94c0                           sete   al
004aeba7  898628040000                     mov    DWORD PTR [esi+0x428],eax
004aebad  eb15                             jmp    0x4aebc4
004aebaf  3c06                             cmp    al,0x6
004aebb1  7511                             jne    0x4aebc4
004aebb3  8b8668030000                     mov    eax,DWORD PTR [esi+0x368]
004aebb9  85c0                             test   eax,eax
004aebbb  7407                             je     0x4aebc4
004aebbd  c7402400000000                   mov    DWORD PTR [eax+0x24],0x0
004aebc4  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
004aebcb  752f                             jne    0x4aebfc
004aebcd  830d2cb2fa0001                   or     DWORD PTR ds:0xfab22c,0x1
004aebd4  c78424500100000d000000           mov    DWORD PTR [esp+0x150],0xd
004aebdf  e8ac000300                       call   0x4dec90
004aebe4  6830cebc00                       push   0xbcce30
004aebe9  e82c373e00                       call   0x89231a
004aebee  83c404                           add    esp,0x4
004aebf1  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004aebfc  6830b1fa00                       push   0xfab130
004aec01  8bc6                             mov    eax,esi
004aec03  e828130300                       call   0x4dff30
004aec08  837b0e00                         cmp    DWORD PTR [ebx+0xe],0x0
004aec0c  0f8486000000                     je     0x4aec98
004aec12  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
004aec19  752f                             jne    0x4aec4a
004aec1b  830d2cb2fa0001                   or     DWORD PTR ds:0xfab22c,0x1
004aec22  c78424500100000e000000           mov    DWORD PTR [esp+0x150],0xe
004aec2d  e85e000300                       call   0x4dec90
004aec32  6830cebc00                       push   0xbcce30
004aec37  e8de363e00                       call   0x89231a
004aec3c  83c404                           add    esp,0x4
004aec3f  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004aec4a  8b4b0e                           mov    ecx,DWORD PTR [ebx+0xe]
004aec4d  8d542414                         lea    edx,[esp+0x14]
004aec51  894c2414                         mov    DWORD PTR [esp+0x14],ecx
004aec55  52                               push   edx
004aec56  8d442434                         lea    eax,[esp+0x34]
004aec5a  b948b1fa00                       mov    ecx,0xfab148
004aec5f  e85c4c3900                       call   0x8438c0
004aec64  8b442430                         mov    eax,DWORD PTR [esp+0x30]
004aec68  3b054cb1fa00                     cmp    eax,DWORD PTR ds:0xfab14c
004aec6e  7428                             je     0x4aec98
004aec70  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
004aec73  85c9                             test   ecx,ecx
004aec75  7421                             je     0x4aec98
004aec77  83790400                         cmp    DWORD PTR [ecx+0x4],0x0
004aec7b  751b                             jne    0x4aec98
004aec7d  0fb743fc                         movzx  eax,WORD PTR [ebx-0x4]
004aec81  8bf9                             mov    edi,ecx
004aec83  e8c8810100                       call   0x4c6e50
004aec88  807e0400                         cmp    BYTE PTR [esi+0x4],0x0
004aec8c  750a                             jne    0x4aec98
004aec8e  c7869800000001000000             mov    DWORD PTR [esi+0x98],0x1
004aec98  8a4313                           mov    al,BYTE PTR [ebx+0x13]
004aec9b  3c04                             cmp    al,0x4
004aec9d  755a                             jne    0x4aecf9
004aec9f  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
004aeca6  752f                             jne    0x4aecd7
004aeca8  830d2cb2fa0001                   or     DWORD PTR ds:0xfab22c,0x1
004aecaf  c78424500100000f000000           mov    DWORD PTR [esp+0x150],0xf
004aecba  e8d1ff0200                       call   0x4dec90
004aecbf  6830cebc00                       push   0xbcce30
004aecc4  e851363e00                       call   0x89231a
004aecc9  83c404                           add    esp,0x4
004aeccc  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004aecd7  a134b1fa00                       mov    eax,ds:0xfab134
004aecdc  89442414                         mov    DWORD PTR [esp+0x14],eax
004aece0  8d7820                           lea    edi,[eax+0x20]
004aece3  8d43fc                           lea    eax,[ebx-0x4]
004aece6  e8b5f00800                       call   0x53dda0
004aeceb  668b43fc                         mov    ax,WORD PTR [ebx-0x4]
004aecef  8b4c2414                         mov    ecx,DWORD PTR [esp+0x14]
004aecf3  66894130                         mov    WORD PTR [ecx+0x30],ax
004aecf7  eb49                             jmp    0x4aed42
004aecf9  3c06                             cmp    al,0x6
004aecfb  7545                             jne    0x4aed42
004aecfd  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
004aed04  752f                             jne    0x4aed35
004aed06  830d2cb2fa0001                   or     DWORD PTR ds:0xfab22c,0x1
004aed0d  c784245001000010000000           mov    DWORD PTR [esp+0x150],0x10
004aed18  e873ff0200                       call   0x4dec90
004aed1d  6830cebc00                       push   0xbcce30
004aed22  e8f3353e00                       call   0x89231a
004aed27  83c404                           add    esp,0x4
004aed2a  c7842450010000ffffffff           mov    DWORD PTR [esp+0x150],0xffffffff
004aed35  668b53fc                         mov    dx,WORD PTR [ebx-0x4]
004aed39  a134b1fa00                       mov    eax,ds:0xfab134
004aed3e  66895032                         mov    WORD PTR [eax+0x32],dx
004aed42  8b442424                         mov    eax,DWORD PTR [esp+0x24]
004aed46  40                               inc    eax
004aed47  83c31a                           add    ebx,0x1a
004aed4a  89442424                         mov    DWORD PTR [esp+0x24],eax
004aed4e  3b442428                         cmp    eax,DWORD PTR [esp+0x28]
004aed52  0f82f8f7ffff                     jb     0x4ae550
004aed58  b800010000                       mov    eax,0x100
004aed5d  8b8c2448010000                   mov    ecx,DWORD PTR [esp+0x148]
004aed64  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004aed6b  59                               pop    ecx
004aed6c  5f                               pop    edi
004aed6d  5e                               pop    esi
004aed6e  5b                               pop    ebx
004aed6f  8b8c2430010000                   mov    ecx,DWORD PTR [esp+0x130]
004aed76  33cc                             xor    ecx,esp
004aed78  e884223e00                       call   0x891001
004aed7d  8be5                             mov    esp,ebp
004aed7f  5d                               pop    ebp
004aed80  c20c00                           ret    0xc
004aed83  68c069c000                       push   0xc069c0
004aed88  e8e3ee2300                       call   0x6edc70

; I07: unsupported spawn type error path includes MessageBox import call and INT3
; VA 0x006edc70..0x006edcf1, raw 0x002ed070, SHA256 3c6e38377e267dcdd1a49bc527accae7905360922d05733469501e5be997ada9
006edc70  55                               push   ebp
006edc71  8bec                             mov    ebp,esp
006edc73  81ec0c040000                     sub    esp,0x40c
006edc79  a1201fd600                       mov    eax,ds:0xd61f20
006edc7e  33c5                             xor    eax,ebp
006edc80  8945f8                           mov    DWORD PTR [ebp-0x8],eax
006edc83  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
006edc86  56                               push   esi
006edc87  57                               push   edi
006edc88  8d450c                           lea    eax,[ebp+0xc]
006edc8b  50                               push   eax
006edc8c  51                               push   ecx
006edc8d  8d95f4fbffff                     lea    edx,[ebp-0x40c]
006edc93  6800040000                       push   0x400
006edc98  52                               push   edx
006edc99  e8eb411a00                       call   0x891e89
006edc9e  8b35cc22bd00                     mov    esi,DWORD PTR ds:0xbd22cc
006edca4  83c410                           add    esp,0x10
006edca7  6a0c                             push   0xc
006edca9  6af5                             push   0xfffffff5
006edcab  ffd6                             call   esi
006edcad  8b3dd022bd00                     mov    edi,DWORD PTR ds:0xbd22d0
006edcb3  50                               push   eax
006edcb4  ffd7                             call   edi
006edcb6  8d85f4fbffff                     lea    eax,[ebp-0x40c]
006edcbc  50                               push   eax
006edcbd  68c020c400                       push   0xc420c0
006edcc2  e8b9fcffff                       call   0x6ed980
006edcc7  83c408                           add    esp,0x8
006edcca  6a07                             push   0x7
006edccc  6af5                             push   0xfffffff5
006edcce  ffd6                             call   esi
006edcd0  50                               push   eax
006edcd1  ffd7                             call   edi
006edcd3  6a10                             push   0x10
006edcd5  68cc20c400                       push   0xc420cc
006edcda  8d8df4fbffff                     lea    ecx,[ebp-0x40c]
006edce0  51                               push   ecx
006edce1  6a00                             push   0x0
006edce3  ff159024bd00                     call   DWORD PTR ds:0xbd2490
006edce9  cc                               int3
006edcea  6a01                             push   0x1
006edcec  e8c25c1a00                       call   0x8939b3

; I08: 0001/0016 world-ID lookup, target writes, snap virtual consumer
; VA 0x004afb80..0x004afe5a, raw 0x000aef80, SHA256 9886ac1bfc6e0f841c2e20e9f6ebb00a475d7e87d0945e58b8fa3716d7015ff9
004afb80  55                               push   ebp
004afb81  8bec                             mov    ebp,esp
004afb83  83e4f8                           and    esp,0xfffffff8
004afb86  6aff                             push   0xffffffff
004afb88  681e6e9300                       push   0x936e1e
004afb8d  64a100000000                     mov    eax,fs:0x0
004afb93  50                               push   eax
004afb94  83ec40                           sub    esp,0x40
004afb97  53                               push   ebx
004afb98  56                               push   esi
004afb99  57                               push   edi
004afb9a  a1201fd600                       mov    eax,ds:0xd61f20
004afb9f  33c4                             xor    eax,esp
004afba1  50                               push   eax
004afba2  8d442450                         lea    eax,[esp+0x50]
004afba6  64a300000000                     mov    fs:0x0,eax
004afbac  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
004afbaf  83f802                           cmp    eax,0x2
004afbb2  7304                             jae    0x4afbb8
004afbb4  33d2                             xor    edx,edx
004afbb6  eb0d                             jmp    0x4afbc5
004afbb8  8d48fe                           lea    ecx,[eax-0x2]
004afbbb  b8cdcccccc                       mov    eax,0xcccccccd
004afbc0  f7e1                             mul    ecx
004afbc2  c1ea03                           shr    edx,0x3
004afbc5  33db                             xor    ebx,ebx
004afbc7  3bd3                             cmp    edx,ebx
004afbc9  0f86ab010000                     jbe    0x4afd7a
004afbcf  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
004afbd2  83c704                           add    edi,0x4
004afbd5  897c2414                         mov    DWORD PTR [esp+0x14],edi
004afbd9  89542418                         mov    DWORD PTR [esp+0x18],edx
004afbdd  eb03                             jmp    0x4afbe2
004afbdf  90                               nop
004afbe0  33db                             xor    ebx,ebx
004afbe2  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
004afbe9  7525                             jne    0x4afc10
004afbeb  830d2cb2fa0001                   or     DWORD PTR ds:0xfab22c,0x1
004afbf2  895c2458                         mov    DWORD PTR [esp+0x58],ebx
004afbf6  e895f00200                       call   0x4dec90
004afbfb  6830cebc00                       push   0xbcce30
004afc00  e815273e00                       call   0x89231a
004afc05  83c404                           add    esp,0x4
004afc08  c7442458ffffffff                 mov    DWORD PTR [esp+0x58],0xffffffff
004afc10  0fb757fe                         movzx  edx,WORD PTR [edi-0x2]
004afc14  8d44241c                         lea    eax,[esp+0x1c]
004afc18  50                               push   eax
004afc19  8d442424                         lea    eax,[esp+0x24]
004afc1d  b938b1fa00                       mov    ecx,0xfab138
004afc22  89542420                         mov    DWORD PTR [esp+0x20],edx
004afc26  e8d5f23700                       call   0x82ef00
004afc2b  8b442420                         mov    eax,DWORD PTR [esp+0x20]
004afc2f  3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
004afc35  7407                             je     0x4afc3e
004afc37  8b7010                           mov    esi,DWORD PTR [eax+0x10]
004afc3a  3bf3                             cmp    esi,ebx
004afc3c  7512                             jne    0x4afc50
004afc3e  68b06ac000                       push   0xc06ab0
004afc43  e818df2300                       call   0x6edb60
004afc48  83c404                           add    esp,0x4
004afc4b  e919010000                       jmp    0x4afd69
004afc50  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004afc56  8b11                             mov    edx,DWORD PTR [ecx]
004afc58  8b4220                           mov    eax,DWORD PTR [edx+0x20]
004afc5b  ffd0                             call   eax
004afc5d  3bf0                             cmp    esi,eax
004afc5f  7509                             jne    0x4afc6a
004afc61  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004afc67  895974                           mov    DWORD PTR [ecx+0x74],ebx
004afc6a  66837d1016                       cmp    WORD PTR [ebp+0x10],0x16
004afc6f  899ed4000000                     mov    DWORD PTR [esi+0xd4],ebx
004afc75  8b17                             mov    edx,DWORD PTR [edi]
004afc77  8996e8000000                     mov    DWORD PTR [esi+0xe8],edx
004afc7d  8b4704                           mov    eax,DWORD PTR [edi+0x4]
004afc80  8986ec000000                     mov    DWORD PTR [esi+0xec],eax
004afc86  0f8505010000                     jne    0x4afd91
004afc8c  0f57c0                           xorps  xmm0,xmm0
004afc8f  8a9ee4000000                     mov    bl,BYTE PTR [esi+0xe4]
004afc95  8bbee0000000                     mov    edi,DWORD PTR [esi+0xe0]
004afc9b  f30f11442424                     movss  DWORD PTR [esp+0x24],xmm0
004afca1  8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
004afca5  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
004afcab  8b542428                         mov    edx,DWORD PTR [esp+0x28]
004afcaf  898ed8000000                     mov    DWORD PTR [esi+0xd8],ecx
004afcb5  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004afcbb  8996dc000000                     mov    DWORD PTR [esi+0xdc],edx
004afcc1  8b01                             mov    eax,DWORD PTR [ecx]
004afcc3  8b5020                           mov    edx,DWORD PTR [eax+0x20]
004afcc6  885c2448                         mov    BYTE PTR [esp+0x48],bl
004afcca  ffd2                             call   edx
004afccc  8b4c2448                         mov    ecx,DWORD PTR [esp+0x48]
004afcd0  8b06                             mov    eax,DWORD PTR [esi]
004afcd2  8b5058                           mov    edx,DWORD PTR [eax+0x58]
004afcd5  51                               push   ecx
004afcd6  89bee0000000                     mov    DWORD PTR [esi+0xe0],edi
004afcdc  8bce                             mov    ecx,esi
004afcde  889ee4000000                     mov    BYTE PTR [esi+0xe4],bl
004afce4  ffd2                             call   edx
004afce6  8b442414                         mov    eax,DWORD PTR [esp+0x14]
004afcea  f30f1000                         movss  xmm0,DWORD PTR [eax]
004afcee  f30f1144243c                     movss  DWORD PTR [esp+0x3c],xmm0
004afcf4  f30f104004                       movss  xmm0,DWORD PTR [eax+0x4]
004afcf9  8b06                             mov    eax,DWORD PTR [esi]
004afcfb  8b5044                           mov    edx,DWORD PTR [eax+0x44]
004afcfe  6a01                             push   0x1
004afd00  8d4c2440                         lea    ecx,[esp+0x40]
004afd04  51                               push   ecx
004afd05  8bce                             mov    ecx,esi
004afd07  f30f11442448                     movss  DWORD PTR [esp+0x48],xmm0
004afd0d  ffd2                             call   edx
004afd0f  83bea803000000                   cmp    DWORD PTR [esi+0x3a8],0x0
004afd16  8a9eb0000000                     mov    bl,BYTE PTR [esi+0xb0]
004afd1c  7547                             jne    0x4afd65
004afd1e  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
004afd25  889ea4030000                     mov    BYTE PTR [esi+0x3a4],bl
004afd2b  7438                             je     0x4afd65
004afd2d  8bb65c010000                     mov    esi,DWORD PTR [esi+0x15c]
004afd33  85f6                             test   esi,esi
004afd35  742e                             je     0x4afd65
004afd37  f605187cfb0001                   test   BYTE PTR ds:0xfb7c18,0x1
004afd3e  750c                             jne    0x4afd4c
004afd40  830d187cfb0001                   or     DWORD PTR ds:0xfb7c18,0x1
004afd47  e8844cf9ff                       call   0x4449d0
004afd4c  8b4604                           mov    eax,DWORD PTR [esi+0x4]
004afd4f  8b500c                           mov    edx,DWORD PTR [eax+0xc]
004afd52  0fb6cb                           movzx  ecx,bl
004afd55  51                               push   ecx
004afd56  d9048d207cfb00                   fld    DWORD PTR [ecx*4+0xfb7c20]
004afd5d  8d4e04                           lea    ecx,[esi+0x4]
004afd60  d91c24                           fstp   DWORD PTR [esp]
004afd63  ffd2                             call   edx
004afd65  8b7c2414                         mov    edi,DWORD PTR [esp+0x14]
004afd69  83c70a                           add    edi,0xa
004afd6c  ff4c2418                         dec    DWORD PTR [esp+0x18]
004afd70  897c2414                         mov    DWORD PTR [esp+0x14],edi
004afd74  0f8566feffff                     jne    0x4afbe0
004afd7a  33c0                             xor    eax,eax
004afd7c  8b4c2450                         mov    ecx,DWORD PTR [esp+0x50]
004afd80  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004afd87  59                               pop    ecx
004afd88  5f                               pop    edi
004afd89  5e                               pop    esi
004afd8a  5b                               pop    ebx
004afd8b  8be5                             mov    esp,ebp
004afd8d  5d                               pop    ebp
004afd8e  c20c00                           ret    0xc
004afd91  d907                             fld    DWORD PTR [edi]
004afd93  b800800000                       mov    eax,0x8000
004afd98  d8a6a0000000                     fsub   DWORD PTR [esi+0xa0]
004afd9e  668586e2000000                   test   WORD PTR [esi+0xe2],ax
004afda5  7427                             je     0x4afdce
004afda7  d95c242c                         fstp   DWORD PTR [esp+0x2c]
004afdab  8b4c242c                         mov    ecx,DWORD PTR [esp+0x2c]
004afdaf  d94704                           fld    DWORD PTR [edi+0x4]
004afdb2  d8a6a4000000                     fsub   DWORD PTR [esi+0xa4]
004afdb8  898ed8000000                     mov    DWORD PTR [esi+0xd8],ecx
004afdbe  d95c2430                         fstp   DWORD PTR [esp+0x30]
004afdc2  8b542430                         mov    edx,DWORD PTR [esp+0x30]
004afdc6  8996dc000000                     mov    DWORD PTR [esi+0xdc],edx
004afdcc  eb25                             jmp    0x4afdf3
004afdce  d95c2434                         fstp   DWORD PTR [esp+0x34]
004afdd2  8b442434                         mov    eax,DWORD PTR [esp+0x34]
004afdd6  d94704                           fld    DWORD PTR [edi+0x4]
004afdd9  d8a6a4000000                     fsub   DWORD PTR [esi+0xa4]
004afddf  8986d8000000                     mov    DWORD PTR [esi+0xd8],eax
004afde5  d95c2438                         fstp   DWORD PTR [esp+0x38]
004afde9  8b4c2438                         mov    ecx,DWORD PTR [esp+0x38]
004afded  898edc000000                     mov    DWORD PTR [esi+0xdc],ecx
004afdf3  83bea803000000                   cmp    DWORD PTR [esi+0x3a8],0x0
004afdfa  8a9eb0000000                     mov    bl,BYTE PTR [esi+0xb0]
004afe00  0f8563ffffff                     jne    0x4afd69
004afe06  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
004afe0d  889ea4030000                     mov    BYTE PTR [esi+0x3a4],bl
004afe13  0f8450ffffff                     je     0x4afd69
004afe19  8bb65c010000                     mov    esi,DWORD PTR [esi+0x15c]
004afe1f  85f6                             test   esi,esi
004afe21  0f8442ffffff                     je     0x4afd69
004afe27  f605187cfb0001                   test   BYTE PTR ds:0xfb7c18,0x1
004afe2e  750c                             jne    0x4afe3c
004afe30  830d187cfb0001                   or     DWORD PTR ds:0xfb7c18,0x1
004afe37  e8944bf9ff                       call   0x4449d0
004afe3c  8b5604                           mov    edx,DWORD PTR [esi+0x4]
004afe3f  8b520c                           mov    edx,DWORD PTR [edx+0xc]
004afe42  0fb6c3                           movzx  eax,bl
004afe45  51                               push   ecx
004afe46  8d4e04                           lea    ecx,[esi+0x4]
004afe49  d90485207cfb00                   fld    DWORD PTR [eax*4+0xfb7c20]
004afe50  d91c24                           fstp   DWORD PTR [esp]
004afe53  ffd2                             call   edx
004afe55  e90fffffff                       jmp    0x4afd69

; I09: 000B world-ID lookup, control/direction fields and virtual direction setter
; VA 0x004afe60..0x004b00fa, raw 0x000af260, SHA256 4a492e7a2ec1c78995187c7f2b5ecf6bf544e772d3e75228317706055e1bfa0f
004afe60  55                               push   ebp
004afe61  8bec                             mov    ebp,esp
004afe63  83e4f8                           and    esp,0xfffffff8
004afe66  6aff                             push   0xffffffff
004afe68  681e6e9300                       push   0x936e1e
004afe6d  64a100000000                     mov    eax,fs:0x0
004afe73  50                               push   eax
004afe74  83ec40                           sub    esp,0x40
004afe77  53                               push   ebx
004afe78  56                               push   esi
004afe79  57                               push   edi
004afe7a  a1201fd600                       mov    eax,ds:0xd61f20
004afe7f  33c4                             xor    eax,esp
004afe81  50                               push   eax
004afe82  8d442450                         lea    eax,[esp+0x50]
004afe86  64a300000000                     mov    fs:0x0,eax
004afe8c  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
004afe8f  83f802                           cmp    eax,0x2
004afe92  7304                             jae    0x4afe98
004afe94  33c0                             xor    eax,eax
004afe96  eb06                             jmp    0x4afe9e
004afe98  83c0fe                           add    eax,0xfffffffe
004afe9b  c1e803                           shr    eax,0x3
004afe9e  85c0                             test   eax,eax
004afea0  0f8465020000                     je     0x4b010b
004afea6  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004afea9  83c306                           add    ebx,0x6
004afeac  895c2418                         mov    DWORD PTR [esp+0x18],ebx
004afeb0  8944241c                         mov    DWORD PTR [esp+0x1c],eax
004afeb4  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
004afebb  7529                             jne    0x4afee6
004afebd  830d2cb2fa0001                   or     DWORD PTR ds:0xfab22c,0x1
004afec4  c744245800000000                 mov    DWORD PTR [esp+0x58],0x0
004afecc  e8bfed0200                       call   0x4dec90
004afed1  6830cebc00                       push   0xbcce30
004afed6  e83f243e00                       call   0x89231a
004afedb  83c404                           add    esp,0x4
004afede  c7442458ffffffff                 mov    DWORD PTR [esp+0x58],0xffffffff
004afee6  0fb77bfc                         movzx  edi,WORD PTR [ebx-0x4]
004afeea  8bc7                             mov    eax,edi
004afeec  8d4c2414                         lea    ecx,[esp+0x14]
004afef0  89442414                         mov    DWORD PTR [esp+0x14],eax
004afef4  51                               push   ecx
004afef5  8d442424                         lea    eax,[esp+0x24]
004afef9  b938b1fa00                       mov    ecx,0xfab138
004afefe  e8fdef3700                       call   0x82ef00
004aff03  8b442420                         mov    eax,DWORD PTR [esp+0x20]
004aff07  3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
004aff0d  7407                             je     0x4aff16
004aff0f  8b7010                           mov    esi,DWORD PTR [eax+0x10]
004aff12  85f6                             test   esi,esi
004aff14  7512                             jne    0x4aff28
004aff16  68d86ac000                       push   0xc06ad8
004aff1b  e840dc2300                       call   0x6edb60
004aff20  83c404                           add    esp,0x4
004aff23  e9d2010000                       jmp    0x4b00fa
004aff28  660fbe43ff                       movsx  ax,BYTE PTR [ebx-0x1]
004aff2d  8b54242e                         mov    edx,DWORD PTR [esp+0x2e]
004aff31  8a4bfe                           mov    cl,BYTE PTR [ebx-0x2]
004aff34  66c1e00f                         shl    ax,0xf
004aff38  81e2ff7f0000                     and    edx,0x7fff
004aff3e  660bc2                           or     ax,dx
004aff41  ba00800000                       mov    edx,0x8000
004aff46  6623c2                           and    ax,dx
004aff49  668944242e                       mov    WORD PTR [esp+0x2e],ax
004aff4e  0fb703                           movzx  eax,WORD PTR [ebx]
004aff51  66897c242c                       mov    WORD PTR [esp+0x2c],di
004aff56  33ff                             xor    edi,edi
004aff58  884c2430                         mov    BYTE PTR [esp+0x30],cl
004aff5c  663bc7                           cmp    ax,di
004aff5f  0f84bb000000                     je     0x4b0020
004aff65  0fb74b02                         movzx  ecx,WORD PTR [ebx+0x2]
004aff69  663bcf                           cmp    cx,di
004aff6c  0f84ae000000                     je     0x4b0020
004aff72  0f57c0                           xorps  xmm0,xmm0
004aff75  f30f2ac0                         cvtsi2ss xmm0,eax
004aff79  f30f11442434                     movss  DWORD PTR [esp+0x34],xmm0
004aff7f  8b542434                         mov    edx,DWORD PTR [esp+0x34]
004aff83  0f57c0                           xorps  xmm0,xmm0
004aff86  f30f2ac1                         cvtsi2ss xmm0,ecx
004aff8a  f30f11442438                     movss  DWORD PTR [esp+0x38],xmm0
004aff90  8b442438                         mov    eax,DWORD PTR [esp+0x38]
004aff94  8996e8000000                     mov    DWORD PTR [esi+0xe8],edx
004aff9a  8986ec000000                     mov    DWORD PTR [esi+0xec],eax
004affa0  d986e8000000                     fld    DWORD PTR [esi+0xe8]
004affa6  d8a6a0000000                     fsub   DWORD PTR [esi+0xa0]
004affac  d95c2410                         fstp   DWORD PTR [esp+0x10]
004affb0  d9442410                         fld    DWORD PTR [esp+0x10]
004affb4  d95c243c                         fstp   DWORD PTR [esp+0x3c]
004affb8  d986ec000000                     fld    DWORD PTR [esi+0xec]
004affbe  d8a6a4000000                     fsub   DWORD PTR [esi+0xa4]
004affc4  d95c2414                         fstp   DWORD PTR [esp+0x14]
004affc8  d9442414                         fld    DWORD PTR [esp+0x14]
004affcc  d95c2440                         fstp   DWORD PTR [esp+0x40]
004affd0  d9442440                         fld    DWORD PTR [esp+0x40]
004affd4  d944243c                         fld    DWORD PTR [esp+0x3c]
004affd8  dcc8                             fmul   st(0),st
004affda  d9c1                             fld    st(1)
004affdc  deca                             fmulp  st(2),st
004affde  dec1                             faddp  st(1),st
004affe0  d95c2424                         fstp   DWORD PTR [esp+0x24]
004affe4  d905645ac500                     fld    DWORD PTR ds:0xc55a64
004affea  d9442424                         fld    DWORD PTR [esp+0x24]
004affee  dff1                             fcomip st,st(1)
004afff0  ddd8                             fstp   st(0)
004afff2  762c                             jbe    0x4b0020
004afff4  f30f10442410                     movss  xmm0,DWORD PTR [esp+0x10]
004afffa  f30f11442444                     movss  DWORD PTR [esp+0x44],xmm0
004b0000  f30f10442414                     movss  xmm0,DWORD PTR [esp+0x14]
004b0006  8b4c2444                         mov    ecx,DWORD PTR [esp+0x44]
004b000a  f30f11442448                     movss  DWORD PTR [esp+0x48],xmm0
004b0010  8b542448                         mov    edx,DWORD PTR [esp+0x48]
004b0014  898ed8000000                     mov    DWORD PTR [esi+0xd8],ecx
004b001a  8996dc000000                     mov    DWORD PTR [esi+0xdc],edx
004b0020  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004b0026  8b01                             mov    eax,DWORD PTR [ecx]
004b0028  8b5020                           mov    edx,DWORD PTR [eax+0x20]
004b002b  ffd2                             call   edx
004b002d  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004b0033  3bf0                             cmp    esi,eax
004b0035  0f8596000000                     jne    0x4b00d1
004b003b  b800800000                       mov    eax,0x8000
004b0040  6685416a                         test   WORD PTR [ecx+0x6a],ax
004b0044  7475                             je     0x4b00bb
004b0046  8544242e                         test   DWORD PTR [esp+0x2e],eax
004b004a  756f                             jne    0x4b00bb
004b004c  8b9658010000                     mov    edx,DWORD PTR [esi+0x158]
004b0052  837a080d                         cmp    DWORD PTR [edx+0x8],0xd
004b0056  7463                             je     0x4b00bb
004b0058  c7417401000000                   mov    DWORD PTR [ecx+0x74],0x1
004b005f  39bea8030000                     cmp    DWORD PTR [esi+0x3a8],edi
004b0065  756a                             jne    0x4b00d1
004b0067  8a86b0000000                     mov    al,BYTE PTR [esi+0xb0]
004b006d  88442428                         mov    BYTE PTR [esp+0x28],al
004b0071  8886a4030000                     mov    BYTE PTR [esi+0x3a4],al
004b0077  39be70030000                     cmp    DWORD PTR [esi+0x370],edi
004b007d  7430                             je     0x4b00af
004b007f  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
004b0085  3bc7                             cmp    eax,edi
004b0087  7426                             je     0x4b00af
004b0089  8b7804                           mov    edi,DWORD PTR [eax+0x4]
004b008c  8d5804                           lea    ebx,[eax+0x4]
004b008f  8b442428                         mov    eax,DWORD PTR [esp+0x28]
004b0093  50                               push   eax
004b0094  e8f749f9ff                       call   0x444a90
004b0099  8b570c                           mov    edx,DWORD PTR [edi+0xc]
004b009c  8bcb                             mov    ecx,ebx
004b009e  f30f110424                       movss  DWORD PTR [esp],xmm0
004b00a3  ffd2                             call   edx
004b00a5  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004b00ab  8b5c2418                         mov    ebx,DWORD PTR [esp+0x18]
004b00af  c786a803000001000000             mov    DWORD PTR [esi+0x3a8],0x1
004b00b9  eb16                             jmp    0x4b00d1
004b00bb  897974                           mov    DWORD PTR [ecx+0x74],edi
004b00be  397970                           cmp    DWORD PTR [ecx+0x70],edi
004b00c1  750e                             jne    0x4b00d1
004b00c3  39bea8030000                     cmp    DWORD PTR [esi+0x3a8],edi
004b00c9  7406                             je     0x4b00d1
004b00cb  89bea8030000                     mov    DWORD PTR [esi+0x3a8],edi
004b00d1  8b01                             mov    eax,DWORD PTR [ecx]
004b00d3  8b5020                           mov    edx,DWORD PTR [eax+0x20]
004b00d6  ffd2                             call   edx
004b00d8  8b44242c                         mov    eax,DWORD PTR [esp+0x2c]
004b00dc  8a4c2430                         mov    cl,BYTE PTR [esp+0x30]
004b00e0  8b16                             mov    edx,DWORD PTR [esi]
004b00e2  8b5258                           mov    edx,DWORD PTR [edx+0x58]
004b00e5  8986e0000000                     mov    DWORD PTR [esi+0xe0],eax
004b00eb  8b442430                         mov    eax,DWORD PTR [esp+0x30]
004b00ef  888ee4000000                     mov    BYTE PTR [esi+0xe4],cl
004b00f5  50                               push   eax
004b00f6  8bce                             mov    ecx,esi
004b00f8  ffd2                             call   edx

; I10: CMonster direction virtual: BYTE actor+B0
; VA 0x004c8c30..0x004c8c40, raw 0x000c8030, SHA256 ea2c5e4b2c272bbf69b25395af84f2e0beee255e89eb773523a1eebfdee6d911
004c8c30  55                               push   ebp
004c8c31  8bec                             mov    ebp,esp
004c8c33  8a4508                           mov    al,BYTE PTR [ebp+0x8]
004c8c36  8881b0000000                     mov    BYTE PTR [ecx+0xb0],al
004c8c3c  5d                               pop    ebp
004c8c3d  c20400                           ret    0x4

; I11: CMonster position virtual calls concrete setter before optional model update
; VA 0x004c8b90..0x004c8bd7, raw 0x000c7f90, SHA256 73535d4e641b6516a4e41f27acc2ec8add7b2598b377e6882b80cf7057ebe15e
004c8b90  55                               push   ebp
004c8b91  8bec                             mov    ebp,esp
004c8b93  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
004c8b96  56                               push   esi
004c8b97  8bf1                             mov    esi,ecx
004c8b99  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
004c8b9c  50                               push   eax
004c8b9d  51                               push   ecx
004c8b9e  8bce                             mov    ecx,esi
004c8ba0  e8db1f0000                       call   0x4cab80
004c8ba5  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
004c8bac  7424                             je     0x4c8bd2
004c8bae  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
004c8bb4  85c0                             test   eax,eax
004c8bb6  741a                             je     0x4c8bd2
004c8bb8  8b16                             mov    edx,DWORD PTR [esi]
004c8bba  53                               push   ebx
004c8bbb  8d5804                           lea    ebx,[eax+0x4]
004c8bbe  8b424c                           mov    eax,DWORD PTR [edx+0x4c]
004c8bc1  57                               push   edi
004c8bc2  8b3b                             mov    edi,DWORD PTR [ebx]
004c8bc4  8bce                             mov    ecx,esi
004c8bc6  ffd0                             call   eax
004c8bc8  8b5704                           mov    edx,DWORD PTR [edi+0x4]
004c8bcb  50                               push   eax
004c8bcc  8bcb                             mov    ecx,ebx
004c8bce  ffd2                             call   edx
004c8bd0  5f                               pop    edi
004c8bd1  5b                               pop    ebx
004c8bd2  5e                               pop    esi
004c8bd3  5d                               pop    ebp
004c8bd4  c20800                           ret    0x8

; I12: concrete position setter writes actor+A0/A4
; VA 0x004cab80..0x004cabd7, raw 0x000c9f80, SHA256 91d77ee3fa0e58dbf90bb727f421211aedd94d094cb69d31f53a5eb619d1b44a
004cab80  55                               push   ebp
004cab81  8bec                             mov    ebp,esp
004cab83  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
004cab86  d981a0000000                     fld    DWORD PTR [ecx+0xa0]
004cab8c  d902                             fld    DWORD PTR [edx]
004cab8e  dfe9                             fucomip st,st(1)
004cab90  ddd8                             fstp   st(0)
004cab92  9f                               lahf
004cab93  f6c444                           test   ah,0x44
004cab96  7a13                             jp     0x4cabab
004cab98  d981a4000000                     fld    DWORD PTR [ecx+0xa4]
004cab9e  d94204                           fld    DWORD PTR [edx+0x4]
004caba1  dfe9                             fucomip st,st(1)
004caba3  ddd8                             fstp   st(0)
004caba5  9f                               lahf
004caba6  f6c444                           test   ah,0x44
004caba9  7b28                             jnp    0x4cabd3
004cabab  837d0c00                         cmp    DWORD PTR [ebp+0xc],0x0
004cabaf  8b02                             mov    eax,DWORD PTR [edx]
004cabb1  8981a0000000                     mov    DWORD PTR [ecx+0xa0],eax
004cabb7  8b5204                           mov    edx,DWORD PTR [edx+0x4]
004cabba  8991a4000000                     mov    DWORD PTR [ecx+0xa4],edx
004cabc0  7411                             je     0x4cabd3
004cabc2  8b01                             mov    eax,DWORD PTR [ecx]
004cabc4  8b5038                           mov    edx,DWORD PTR [eax+0x38]
004cabc7  c781ac00000001000000             mov    DWORD PTR [ecx+0xac],0x1
004cabd1  ffd2                             call   edx
004cabd3  5d                               pop    ebp
004cabd4  c20800                           ret    0x8

; I13: 001A typed prelude, controller matching and world removal
; VA 0x004b28d0..0x004b2aed, raw 0x000b1cd0, SHA256 d9ccc9c72e362dc9d9b4ff5cb0f3cbd3ae06fa8e0a6d07c001a09606c2025aef
004b28d0  55                               push   ebp
004b28d1  8bec                             mov    ebp,esp
004b28d3  83e4f8                           and    esp,0xfffffff8
004b28d6  6aff                             push   0xffffffff
004b28d8  681c6d9300                       push   0x936d1c
004b28dd  64a100000000                     mov    eax,fs:0x0
004b28e3  50                               push   eax
004b28e4  83ec28                           sub    esp,0x28
004b28e7  53                               push   ebx
004b28e8  56                               push   esi
004b28e9  57                               push   edi
004b28ea  a1201fd600                       mov    eax,ds:0xd61f20
004b28ef  33c4                             xor    eax,esp
004b28f1  50                               push   eax
004b28f2  8d442438                         lea    eax,[esp+0x38]
004b28f6  64a300000000                     mov    fs:0x0,eax
004b28fc  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
004b28ff  83f804                           cmp    eax,0x4
004b2902  7304                             jae    0x4b2908
004b2904  33c0                             xor    eax,eax
004b2906  eb05                             jmp    0x4b290d
004b2908  83c0fc                           add    eax,0xfffffffc
004b290b  d1e8                             shr    eax,1
004b290d  85c0                             test   eax,eax
004b290f  0f84c1010000                     je     0x4b2ad6
004b2915  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
004b2918  83c104                           add    ecx,0x4
004b291b  894c2414                         mov    DWORD PTR [esp+0x14],ecx
004b291f  89442418                         mov    DWORD PTR [esp+0x18],eax
004b2923  bb01000000                       mov    ebx,0x1
004b2928  841d2cb2fa00                     test   BYTE PTR ds:0xfab22c,bl
004b292e  7528                             jne    0x4b2958
004b2930  091d2cb2fa00                     or     DWORD PTR ds:0xfab22c,ebx
004b2936  c744244000000000                 mov    DWORD PTR [esp+0x40],0x0
004b293e  e84dc30200                       call   0x4dec90
004b2943  6830cebc00                       push   0xbcce30
004b2948  e8cdf93d00                       call   0x89231a
004b294d  83c404                           add    esp,0x4
004b2950  c7442440ffffffff                 mov    DWORD PTR [esp+0x40],0xffffffff
004b2958  8b542414                         mov    edx,DWORD PTR [esp+0x14]
004b295c  0fb702                           movzx  eax,WORD PTR [edx]
004b295f  8d4c241c                         lea    ecx,[esp+0x1c]
004b2963  8944241c                         mov    DWORD PTR [esp+0x1c],eax
004b2967  51                               push   ecx
004b2968  8d442424                         lea    eax,[esp+0x24]
004b296c  b938b1fa00                       mov    ecx,0xfab138
004b2971  e88ac53700                       call   0x82ef00
004b2976  8b442420                         mov    eax,DWORD PTR [esp+0x20]
004b297a  3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
004b2980  7407                             je     0x4b2989
004b2982  8b7010                           mov    esi,DWORD PTR [eax+0x10]
004b2985  85f6                             test   esi,esi
004b2987  7512                             jne    0x4b299b
004b2989  68e06cc000                       push   0xc06ce0
004b298e  e8cdb12300                       call   0x6edb60
004b2993  83c404                           add    esp,0x4
004b2996  e92c010000                       jmp    0x4b2ac7
004b299b  0fb74604                         movzx  eax,WORD PTR [esi+0x4]
004b299f  3ac3                             cmp    al,bl
004b29a1  740c                             je     0x4b29af
004b29a3  3c06                             cmp    al,0x6
004b29a5  7408                             je     0x4b29af
004b29a7  84c0                             test   al,al
004b29a9  7404                             je     0x4b29af
004b29ab  3c07                             cmp    al,0x7
004b29ad  7566                             jne    0x4b2a15
004b29af  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
004b29b7  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
004b29bd  f30f11442424                     movss  DWORD PTR [esp+0x24],xmm0
004b29c3  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
004b29c9  f30f1144242c                     movss  DWORD PTR [esp+0x2c],xmm0
004b29cf  f30f11442430                     movss  DWORD PTR [esp+0x30],xmm0
004b29d5  85c0                             test   eax,eax
004b29d7  743c                             je     0x4b2a15
004b29d9  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
004b29e0  7433                             je     0x4b2a15
004b29e2  6a00                             push   0x0
004b29e4  50                               push   eax
004b29e5  e8d6522f00                       call   0x7a7cc0
004b29ea  8b542424                         mov    edx,DWORD PTR [esp+0x24]
004b29ee  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
004b29f4  83ec10                           sub    esp,0x10
004b29f7  8bcc                             mov    ecx,esp
004b29f9  8911                             mov    DWORD PTR [ecx],edx
004b29fb  8b542438                         mov    edx,DWORD PTR [esp+0x38]
004b29ff  895104                           mov    DWORD PTR [ecx+0x4],edx
004b2a02  8b54243c                         mov    edx,DWORD PTR [esp+0x3c]
004b2a06  895108                           mov    DWORD PTR [ecx+0x8],edx
004b2a09  8b542440                         mov    edx,DWORD PTR [esp+0x40]
004b2a0d  89510c                           mov    DWORD PTR [ecx+0xc],edx
004b2a10  e8db512f00                       call   0x7a7bf0
004b2a15  0fb74604                         movzx  eax,WORD PTR [esi+0x4]
004b2a19  3c02                             cmp    al,0x2
004b2a1b  7408                             je     0x4b2a25
004b2a1d  3c08                             cmp    al,0x8
004b2a1f  7404                             je     0x4b2a25
004b2a21  3c09                             cmp    al,0x9
004b2a23  7531                             jne    0x4b2a56
004b2a25  83bef400000000                   cmp    DWORD PTR [esi+0xf4],0x0
004b2a2c  7428                             je     0x4b2a56
004b2a2e  83be2401000000                   cmp    DWORD PTR [esi+0x124],0x0
004b2a35  751f                             jne    0x4b2a56
004b2a37  d98634010000                     fld    DWORD PTR [esi+0x134]
004b2a3d  d8b630010000                     fdiv   DWORD PTR [esi+0x130]
004b2a43  dd05f057c500                     fld    QWORD PTR ds:0xc557f0
004b2a49  d9c9                             fxch   st(1)
004b2a4b  dff1                             fcomip st,st(1)
004b2a4d  ddd8                             fstp   st(0)
004b2a4f  7605                             jbe    0x4b2a56
004b2a51  e85a9e0100                       call   0x4cc8b0
004b2a56  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004b2a5c  668b7604                         mov    si,WORD PTR [esi+0x4]
004b2a60  33c0                             xor    eax,eax
004b2a62  8d510c                           lea    edx,[ecx+0xc]
004b2a65  8b3a                             mov    edi,DWORD PTR [edx]
004b2a67  85ff                             test   edi,edi
004b2a69  7406                             je     0x4b2a71
004b2a6b  66397704                         cmp    WORD PTR [edi+0x4],si
004b2a6f  740c                             je     0x4b2a7d
004b2a71  03c3                             add    eax,ebx
004b2a73  83c20c                           add    edx,0xc
004b2a76  83f803                           cmp    eax,0x3
004b2a79  7cea                             jl     0x4b2a65
004b2a7b  eb0c                             jmp    0x4b2a89
004b2a7d  83f8ff                           cmp    eax,0xffffffff
004b2a80  7407                             je     0x4b2a89
004b2a82  8b01                             mov    eax,DWORD PTR [ecx]
004b2a84  8b5014                           mov    edx,DWORD PTR [eax+0x14]
004b2a87  ffd2                             call   edx
004b2a89  841d2cb2fa00                     test   BYTE PTR ds:0xfab22c,bl
004b2a8f  7524                             jne    0x4b2ab5
004b2a91  091d2cb2fa00                     or     DWORD PTR ds:0xfab22c,ebx
004b2a97  895c2440                         mov    DWORD PTR [esp+0x40],ebx
004b2a9b  e8f0c10200                       call   0x4dec90
004b2aa0  6830cebc00                       push   0xbcce30
004b2aa5  e870f83d00                       call   0x89231a
004b2aaa  83c404                           add    esp,0x4
004b2aad  c7442440ffffffff                 mov    DWORD PTR [esp+0x40],0xffffffff
004b2ab5  8b442414                         mov    eax,DWORD PTR [esp+0x14]
004b2ab9  0fb708                           movzx  ecx,WORD PTR [eax]
004b2abc  51                               push   ecx
004b2abd  b830b1fa00                       mov    eax,0xfab130
004b2ac2  e8f9d00200                       call   0x4dfbc0
004b2ac7  8344241402                       add    DWORD PTR [esp+0x14],0x2
004b2acc  295c2418                         sub    DWORD PTR [esp+0x18],ebx
004b2ad0  0f8552feffff                     jne    0x4b2928
004b2ad6  33c0                             xor    eax,eax
004b2ad8  8b4c2438                         mov    ecx,DWORD PTR [esp+0x38]
004b2adc  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004b2ae3  59                               pop    ecx
004b2ae4  5f                               pop    edi
004b2ae5  5e                               pop    esi
004b2ae6  5b                               pop    ebx
004b2ae7  8be5                             mov    esp,ebp
004b2ae9  5d                               pop    ebp
004b2aea  c20c00                           ret    0xc

; I14: low-byte 2/8/9 conditional removal helper uses its own object layout
; VA 0x004cc8b0..0x004cca41, raw 0x000cbcb0, SHA256 c446791248ee8eda947ec324535f931e9f0be6ae2804ed708ccfbf30c5c4e3a3
004cc8b0  55                               push   ebp
004cc8b1  8bec                             mov    ebp,esp
004cc8b3  83ec2c                           sub    esp,0x2c
004cc8b6  a1201fd600                       mov    eax,ds:0xd61f20
004cc8bb  33c5                             xor    eax,ebp
004cc8bd  8945fc                           mov    DWORD PTR [ebp-0x4],eax
004cc8c0  83be2401000000                   cmp    DWORD PTR [esi+0x124],0x0
004cc8c7  57                               push   edi
004cc8c8  0f8564010000                     jne    0x4cca32
004cc8ce  83bef400000000                   cmp    DWORD PTR [esi+0xf4],0x0
004cc8d5  0f8457010000                     je     0x4cca32
004cc8db  83bef800000000                   cmp    DWORD PTR [esi+0xf8],0x0
004cc8e2  743e                             je     0x4cc922
004cc8e4  d98628010000                     fld    DWORD PTR [esi+0x128]
004cc8ea  8b0d38a8fb00                     mov    ecx,DWORD PTR ds:0xfba838
004cc8f0  8b01                             mov    eax,DWORD PTR [ecx]
004cc8f2  d95df0                           fstp   DWORD PTR [ebp-0x10]
004cc8f5  d9862c010000                     fld    DWORD PTR [esi+0x12c]
004cc8fb  0f57c0                           xorps  xmm0,xmm0
004cc8fe  8b00                             mov    eax,DWORD PTR [eax]
004cc900  d95df4                           fstp   DWORD PTR [ebp-0xc]
004cc903  d945f4                           fld    DWORD PTR [ebp-0xc]
004cc906  6a00                             push   0x0
004cc908  8d55f8                           lea    edx,[ebp-0x8]
004cc90b  52                               push   edx
004cc90c  83ec08                           sub    esp,0x8
004cc90f  d95c2404                         fstp   DWORD PTR [esp+0x4]
004cc913  f30f1145f8                       movss  DWORD PTR [ebp-0x8],xmm0
004cc918  d945f0                           fld    DWORD PTR [ebp-0x10]
004cc91b  d91c24                           fstp   DWORD PTR [esp]
004cc91e  ffd0                             call   eax
004cc920  eb76                             jmp    0x4cc998
004cc922  0fb78e28010000                   movzx  ecx,WORD PTR [esi+0x128]
004cc929  894de8                           mov    DWORD PTR [ebp-0x18],ecx
004cc92c  e82f27f4ff                       call   0x40f060
004cc931  8bf8                             mov    edi,eax
004cc933  8d55e8                           lea    edx,[ebp-0x18]
004cc936  52                               push   edx
004cc937  8d4f08                           lea    ecx,[edi+0x8]
004cc93a  8d45ec                           lea    eax,[ebp-0x14]
004cc93d  e8be253600                       call   0x82ef00
004cc942  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
004cc945  3b470c                           cmp    eax,DWORD PTR [edi+0xc]
004cc948  7407                             je     0x4cc951
004cc94a  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
004cc94d  85c9                             test   ecx,ecx
004cc94f  751d                             jne    0x4cc96e
004cc951  8b8610010000                     mov    eax,DWORD PTR [esi+0x110]
004cc957  8b8e14010000                     mov    ecx,DWORD PTR [esi+0x114]
004cc95d  8b9618010000                     mov    edx,DWORD PTR [esi+0x118]
004cc963  8945f0                           mov    DWORD PTR [ebp-0x10],eax
004cc966  894df4                           mov    DWORD PTR [ebp-0xc],ecx
004cc969  8955f8                           mov    DWORD PTR [ebp-0x8],edx
004cc96c  eb2a                             jmp    0x4cc998
004cc96e  8b01                             mov    eax,DWORD PTR [ecx]
004cc970  8b504c                           mov    edx,DWORD PTR [eax+0x4c]
004cc973  ffd2                             call   edx
004cc975  8b08                             mov    ecx,DWORD PTR [eax]
004cc977  894df0                           mov    DWORD PTR [ebp-0x10],ecx
004cc97a  8b5004                           mov    edx,DWORD PTR [eax+0x4]
004cc97d  8955f4                           mov    DWORD PTR [ebp-0xc],edx
004cc980  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004cc983  898e10010000                     mov    DWORD PTR [esi+0x110],ecx
004cc989  899614010000                     mov    DWORD PTR [esi+0x114],edx
004cc98f  8945f8                           mov    DWORD PTR [ebp-0x8],eax
004cc992  898618010000                     mov    DWORD PTR [esi+0x118],eax
004cc998  8b15e8aafb00                     mov    edx,DWORD PTR ds:0xfbaae8
004cc99e  8b4204                           mov    eax,DWORD PTR [edx+0x4]
004cc9a1  80b8a100000000                   cmp    BYTE PTR [eax+0xa1],0x0
004cc9a8  0fb7be0c010000                   movzx  edi,WORD PTR [esi+0x10c]
004cc9af  8bca                             mov    ecx,edx
004cc9b1  7518                             jne    0x4cc9cb
004cc9b3  6639780c                         cmp    WORD PTR [eax+0xc],di
004cc9b7  7305                             jae    0x4cc9be
004cc9b9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004cc9bc  eb04                             jmp    0x4cc9c2
004cc9be  8bc8                             mov    ecx,eax
004cc9c0  8b00                             mov    eax,DWORD PTR [eax]
004cc9c2  80b8a100000000                   cmp    BYTE PTR [eax+0xa1],0x0
004cc9c9  74e8                             je     0x4cc9b3
004cc9cb  894dec                           mov    DWORD PTR [ebp-0x14],ecx
004cc9ce  3bca                             cmp    ecx,edx
004cc9d0  740b                             je     0x4cc9dd
004cc9d2  663b790c                         cmp    di,WORD PTR [ecx+0xc]
004cc9d6  7205                             jb     0x4cc9dd
004cc9d8  8d45ec                           lea    eax,[ebp-0x14]
004cc9db  eb06                             jmp    0x4cc9e3
004cc9dd  8955e8                           mov    DWORD PTR [ebp-0x18],edx
004cc9e0  8d45e8                           lea    eax,[ebp-0x18]
004cc9e3  8b00                             mov    eax,DWORD PTR [eax]
004cc9e5  3bc2                             cmp    eax,edx
004cc9e7  743f                             je     0x4cca28
004cc9e9  83c068                           add    eax,0x68
004cc9ec  83781410                         cmp    DWORD PTR [eax+0x14],0x10
004cc9f0  7202                             jb     0x4cc9f4
004cc9f2  8b00                             mov    eax,DWORD PTR [eax]
004cc9f4  d9e8                             fld1
004cc9f6  83ec08                           sub    esp,0x8
004cc9f9  d95c2404                         fstp   DWORD PTR [esp+0x4]
004cc9fd  8945e4                           mov    DWORD PTR [ebp-0x1c],eax
004cca00  d9ee                             fldz
004cca02  8d45f0                           lea    eax,[ebp-0x10]
004cca05  d91c24                           fstp   DWORD PTR [esp]
004cca08  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
004cca0f  c745d8e879c000                   mov    DWORD PTR [ebp-0x28],0xc079e8
004cca16  50                               push   eax
004cca17  6a00                             push   0x0
004cca19  e822e7fcff                       call   0x49b140
004cca1e  8d55d4                           lea    edx,[ebp-0x2c]
004cca21  8bc8                             mov    ecx,eax
004cca23  e8f8540800                       call   0x551f20
004cca28  c7862401000001000000             mov    DWORD PTR [esi+0x124],0x1
004cca32  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
004cca35  33cd                             xor    ecx,ebp
004cca37  5f                               pop    edi
004cca38  e8c4453c00                       call   0x891001
004cca3d  8be5                             mov    esp,ebp
004cca3f  5d                               pop    ebp
004cca40  c3                               ret

; I15: world removal calls actor v+14, deleting destructor and tree erase
; VA 0x004dfbc0..0x004dfc2c, raw 0x000defc0, SHA256 21ae8dd896a0efbf2fc1719b9b2af83daf1fc550fdb8d3c10097a2a4c642baf8
004dfbc0  55                               push   ebp
004dfbc1  8bec                             mov    ebp,esp
004dfbc3  51                               push   ecx
004dfbc4  53                               push   ebx
004dfbc5  56                               push   esi
004dfbc6  8bf0                             mov    esi,eax
004dfbc8  57                               push   edi
004dfbc9  8d4508                           lea    eax,[ebp+0x8]
004dfbcc  8d5e08                           lea    ebx,[esi+0x8]
004dfbcf  50                               push   eax
004dfbd0  8d45fc                           lea    eax,[ebp-0x4]
004dfbd3  8bcb                             mov    ecx,ebx
004dfbd5  e826f33400                       call   0x82ef00
004dfbda  8b7dfc                           mov    edi,DWORD PTR [ebp-0x4]
004dfbdd  3b7e0c                           cmp    edi,DWORD PTR [esi+0xc]
004dfbe0  7441                             je     0x4dfc23
004dfbe2  33f6                             xor    esi,esi
004dfbe4  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004dfbea  8b11                             mov    edx,DWORD PTR [ecx]
004dfbec  8b421c                           mov    eax,DWORD PTR [edx+0x1c]
004dfbef  56                               push   esi
004dfbf0  ffd0                             call   eax
004dfbf2  46                               inc    esi
004dfbf3  83fe03                           cmp    esi,0x3
004dfbf6  7cec                             jl     0x4dfbe4
004dfbf8  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
004dfbfb  8b11                             mov    edx,DWORD PTR [ecx]
004dfbfd  8b4214                           mov    eax,DWORD PTR [edx+0x14]
004dfc00  ffd0                             call   eax
004dfc02  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
004dfc05  85c9                             test   ecx,ecx
004dfc07  740f                             je     0x4dfc18
004dfc09  8b11                             mov    edx,DWORD PTR [ecx]
004dfc0b  8b02                             mov    eax,DWORD PTR [edx]
004dfc0d  6a01                             push   0x1
004dfc0f  ffd0                             call   eax
004dfc11  c7471000000000                   mov    DWORD PTR [edi+0x10],0x0
004dfc18  57                               push   edi
004dfc19  8d4d08                           lea    ecx,[ebp+0x8]
004dfc1c  51                               push   ecx
004dfc1d  53                               push   ebx
004dfc1e  e86d6c2d00                       call   0x7b6890
004dfc23  5f                               pop    edi
004dfc24  5e                               pop    esi
004dfc25  5b                               pop    ebx
004dfc26  8be5                             mov    esp,ebp
004dfc28  5d                               pop    ebp
004dfc29  c20400                           ret    0x4

; I16: CMonster removal virtual reaches cleanup
; VA 0x004d1f80..0x004d1f88, raw 0x000d1380, SHA256 ffa540291c94665ee3eaf406cc0f5c54388c0bc0ad71a865bf179a53719187fb
004d1f80  e8db63ffff                       call   0x4c8360
004d1f85  33c0                             xor    eax,eax
004d1f87  c3                               ret

; I17: CMonster deleting destructor and conditional heap free
; VA 0x004d18d0..0x004d1901, raw 0x000d0cd0, SHA256 2cf47102808191c44ba4d7c2f615c10bb0b0defa8c1a7fed2156648514092e0b
004d18d0  55                               push   ebp
004d18d1  8bec                             mov    ebp,esp
004d18d3  56                               push   esi
004d18d4  8bf1                             mov    esi,ecx
004d18d6  c706dcc9c000                     mov    DWORD PTR [esi],0xc0c9dc
004d18dc  c786f000000064cac000             mov    DWORD PTR [esi+0xf0],0xc0ca64
004d18e6  e8a562ffff                       call   0x4c7b90
004d18eb  f6450801                         test   BYTE PTR [ebp+0x8],0x1
004d18ef  7409                             je     0x4d18fa
004d18f1  56                               push   esi
004d18f2  e815f93b00                       call   0x89120c
004d18f7  83c404                           add    esp,0x4
004d18fa  8bc6                             mov    eax,esi
004d18fc  5e                               pop    esi
004d18fd  5d                               pop    ebp
004d18fe  c20400                           ret    0x4

; I18: tree erase tail: node free and count decrement
; VA 0x007b6ac3..0x007b6aee, raw 0x003b5ec3, SHA256 b4be42bec2eb813d37ab2b33a675ece6c7b7974c5e5409cdd32fa53dfef4a095
007b6ac3  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
007b6ac6  52                               push   edx
007b6ac7  e840a70d00                       call   0x89120c
007b6acc  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007b6acf  8b4108                           mov    eax,DWORD PTR [ecx+0x8]
007b6ad2  83c404                           add    esp,0x4
007b6ad5  5f                               pop    edi
007b6ad6  5e                               pop    esi
007b6ad7  5b                               pop    ebx
007b6ad8  85c0                             test   eax,eax
007b6ada  7404                             je     0x7b6ae0
007b6adc  48                               dec    eax
007b6add  894108                           mov    DWORD PTR [ecx+0x8],eax
007b6ae0  8b4d10                           mov    ecx,DWORD PTR [ebp+0x10]
007b6ae3  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007b6ae6  8908                             mov    DWORD PTR [eax],ecx
007b6ae8  8be5                             mov    esp,ebp
007b6aea  5d                               pop    ebp
007b6aeb  c20c00                           ret    0xc

; I19: world clear enumerates indexed actors and deletes them
; VA 0x004dfe90..0x004dff23, raw 0x000df290, SHA256 5a5931599c04e6a52f0602868f4fbe48ff1d349acfd7124873a3870c3af92663
004dfe90  55                               push   ebp
004dfe91  8bec                             mov    ebp,esp
004dfe93  53                               push   ebx
004dfe94  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004dfe97  8b430c                           mov    eax,DWORD PTR [ebx+0xc]
004dfe9a  56                               push   esi
004dfe9b  8b30                             mov    esi,DWORD PTR [eax]
004dfe9d  57                               push   edi
004dfe9e  3bf0                             cmp    esi,eax
004dfea0  7465                             je     0x4dff07
004dfea2  8b7e10                           mov    edi,DWORD PTR [esi+0x10]
004dfea5  85ff                             test   edi,edi
004dfea7  7413                             je     0x4dfebc
004dfea9  8b07                             mov    eax,DWORD PTR [edi]
004dfeab  8b5014                           mov    edx,DWORD PTR [eax+0x14]
004dfeae  8bcf                             mov    ecx,edi
004dfeb0  ffd2                             call   edx
004dfeb2  8b07                             mov    eax,DWORD PTR [edi]
004dfeb4  8b10                             mov    edx,DWORD PTR [eax]
004dfeb6  6a01                             push   0x1
004dfeb8  8bcf                             mov    ecx,edi
004dfeba  ffd2                             call   edx
004dfebc  807e1500                         cmp    BYTE PTR [esi+0x15],0x0
004dfec0  7540                             jne    0x4dff02
004dfec2  8b4608                           mov    eax,DWORD PTR [esi+0x8]
004dfec5  80781500                         cmp    BYTE PTR [eax+0x15],0x0
004dfec9  7516                             jne    0x4dfee1
004dfecb  8bf0                             mov    esi,eax
004dfecd  8b06                             mov    eax,DWORD PTR [esi]
004dfecf  80781500                         cmp    BYTE PTR [eax+0x15],0x0
004dfed3  752d                             jne    0x4dff02
004dfed5  8bf0                             mov    esi,eax
004dfed7  8b06                             mov    eax,DWORD PTR [esi]
004dfed9  80781500                         cmp    BYTE PTR [eax+0x15],0x0
004dfedd  74f6                             je     0x4dfed5
004dfedf  eb21                             jmp    0x4dff02
004dfee1  8b4604                           mov    eax,DWORD PTR [esi+0x4]
004dfee4  80781500                         cmp    BYTE PTR [eax+0x15],0x0
004dfee8  7516                             jne    0x4dff00
004dfeea  8d9b00000000                     lea    ebx,[ebx+0x0]
004dfef0  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
004dfef3  750b                             jne    0x4dff00
004dfef5  8bf0                             mov    esi,eax
004dfef7  8b4004                           mov    eax,DWORD PTR [eax+0x4]
004dfefa  80781500                         cmp    BYTE PTR [eax+0x15],0x0
004dfefe  74f0                             je     0x4dfef0
004dff00  8bf0                             mov    esi,eax
004dff02  3b730c                           cmp    esi,DWORD PTR [ebx+0xc]
004dff05  759b                             jne    0x4dfea2
004dff07  8d7b08                           lea    edi,[ebx+0x8]
004dff0a  e841393400                       call   0x823850
004dff0f  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004dff15  8b01                             mov    eax,DWORD PTR [ecx]
004dff17  8b5014                           mov    edx,DWORD PTR [eax+0x14]
004dff1a  ffd2                             call   edx
004dff1c  5f                               pop    edi
004dff1d  5e                               pop    esi
004dff1e  5b                               pop    ebx
004dff1f  5d                               pop    ebp
004dff20  c20400                           ret    0x4

; I20: Q.GetLeaderPosN registration, native pointer and C closure
; VA 0x00566880..0x00566919, raw 0x00165c80, SHA256 d7f30519c65aa02fcd831223621d2a940dbffc1aaae84ecda0d1a23e177220b7
00566880  55                               push   ebp
00566881  8bec                             mov    ebp,esp
00566883  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566886  53                               push   ebx
00566887  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0056688d  56                               push   esi
0056688e  8b33                             mov    esi,DWORD PTR [ebx]
00566890  57                               push   edi
00566891  8b38                             mov    edi,DWORD PTR [eax]
00566893  b8eed8ffff                       mov    eax,0xffffd8ee
00566898  c705b827fe0010465600             mov    DWORD PTR ds:0xfe27b8,0x564610
005668a2  e8d9ed1800                       call   0x6f5680
005668a7  8b03                             mov    eax,DWORD PTR [ebx]
005668a9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
005668ac  83e810                           sub    eax,0x10
005668af  3dc8bfc000                       cmp    eax,0xc0bfc8
005668b4  7406                             je     0x5668bc
005668b6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
005668ba  7414                             je     0x5668d0
005668bc  57                               push   edi
005668bd  68c426c400                       push   0xc426c4
005668c2  e8f6c73200                       call   0x8930bd
005668c7  8b1b                             mov    ebx,DWORD PTR [ebx]
005668c9  83c408                           add    esp,0x8
005668cc  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
005668d0  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
005668d6  8b37                             mov    esi,DWORD PTR [edi]
005668d8  6838a3d600                       push   0xd6a338
005668dd  e82eec1800                       call   0x6f5510
005668e2  8b37                             mov    esi,DWORD PTR [edi]
005668e4  83c404                           add    esp,0x4
005668e7  6a00                             push   0x0
005668e9  68e08f5600                       push   0x568fe0
005668ee  e8bdec1800                       call   0x6f55b0
005668f3  8b0f                             mov    ecx,DWORD PTR [edi]
005668f5  51                               push   ecx
005668f6  b8fdffffff                       mov    eax,0xfffffffd
005668fb  e8f0ee1800                       call   0x6f57f0
00566900  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
00566906  8b02                             mov    eax,DWORD PTR [edx]
00566908  83c40c                           add    esp,0xc
0056690b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0056690f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566912  5f                               pop    edi
00566913  5e                               pop    esi
00566914  5b                               pop    ebx
00566915  5d                               pop    ebp
00566916  c20400                           ret    0x4

; I21: Q getter closure to marshaller
; VA 0x00568fe0..0x00569036, raw 0x001683e0, SHA256 016646a79815978ced7fc34504556c7a292a880ed44a4a5206751a1e4fa8be7b
00568fe0  55                               push   ebp
00568fe1  8bec                             mov    ebp,esp
00568fe3  6aff                             push   0xffffffff
00568fe5  68c8839300                       push   0x9383c8
00568fea  64a100000000                     mov    eax,fs:0x0
00568ff0  50                               push   eax
00568ff1  83ec0c                           sub    esp,0xc
00568ff4  a1201fd600                       mov    eax,ds:0xd61f20
00568ff9  33c5                             xor    eax,ebp
00568ffb  50                               push   eax
00568ffc  8d45f4                           lea    eax,[ebp-0xc]
00568fff  64a300000000                     mov    fs:0x0,eax
00569005  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00569008  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0056900b  33c0                             xor    eax,eax
0056900d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00569010  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00569013  8d4de8                           lea    ecx,[ebp-0x18]
00569016  51                               push   ecx
00569017  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0056901a  e871250000                       call   0x56b590
0056901f  83c404                           add    esp,0x4
00569022  b801000000                       mov    eax,0x1
00569027  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0056902a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00569031  59                               pop    ecx
00569032  8be5                             mov    esp,ebp
00569034  5d                               pop    ebp
00569035  c3                               ret

; I22: Q getter conversion and genuine Lua number push
; VA 0x0056b590..0x0056b622, raw 0x0016a990, SHA256 14261c8ab367fa3901090d94802a269f15a57eb2fdf2f4e38eb8242b67318f77
0056b590  55                               push   ebp
0056b591  8bec                             mov    ebp,esp
0056b593  83ec18                           sub    esp,0x18
0056b596  a1b827fe00                       mov    eax,ds:0xfe27b8
0056b59b  8b0d7827fe00                     mov    ecx,DWORD PTR ds:0xfe2778
0056b5a1  53                               push   ebx
0056b5a2  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0056b5a5  8945f8                           mov    DWORD PTR [ebp-0x8],eax
0056b5a8  894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0056b5ab  8b0b                             mov    ecx,DWORD PTR [ebx]
0056b5ad  83c8ff                           or     eax,0xffffffff
0056b5b0  e83b9b1800                       call   0x6f50f0
0056b5b5  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056b5b8  83f903                           cmp    ecx,0x3
0056b5bb  742a                             je     0x56b5e7
0056b5bd  83f904                           cmp    ecx,0x4
0056b5c0  755c                             jne    0x56b61e
0056b5c2  56                               push   esi
0056b5c3  8b30                             mov    esi,DWORD PTR [eax]
0056b5c5  57                               push   edi
0056b5c6  83c610                           add    esi,0x10
0056b5c9  8d7df0                           lea    edi,[ebp-0x10]
0056b5cc  e88fc11800                       call   0x6f7760
0056b5d1  5f                               pop    edi
0056b5d2  5e                               pop    esi
0056b5d3  85c0                             test   eax,eax
0056b5d5  7447                             je     0x56b61e
0056b5d7  dd45f0                           fld    QWORD PTR [ebp-0x10]
0056b5da  c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
0056b5e1  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0056b5e4  8d45e8                           lea    eax,[ebp-0x18]
0056b5e7  dd00                             fld    QWORD PTR [eax]
0056b5e9  dd5df0                           fstp   QWORD PTR [ebp-0x10]
0056b5ec  dd45f0                           fld    QWORD PTR [ebp-0x10]
0056b5ef  db5d08                           fistp  DWORD PTR [ebp+0x8]
0056b5f2  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0056b5f5  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0056b5f8  50                               push   eax
0056b5f9  ff55f8                           call   DWORD PTR [ebp-0x8]
0056b5fc  d95df8                           fstp   DWORD PTR [ebp-0x8]
0056b5ff  8b03                             mov    eax,DWORD PTR [ebx]
0056b601  d945f8                           fld    DWORD PTR [ebp-0x8]
0056b604  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056b607  dd19                             fstp   QWORD PTR [ecx]
0056b609  c7410803000000                   mov    DWORD PTR [ecx+0x8],0x3
0056b610  83400810                         add    DWORD PTR [eax+0x8],0x10
0056b614  b801000000                       mov    eax,0x1
0056b619  5b                               pop    ebx
0056b61a  8be5                             mov    esp,ebp
0056b61c  5d                               pop    ebp
0056b61d  c3                               ret
0056b61e  33c0                             xor    eax,eax
0056b620  ebd3                             jmp    0x56b5f5

; I23: leader position component selector; no arbitrary world ID argument
; VA 0x00564610..0x00564697, raw 0x00163a10, SHA256 42ef9834f5b7ff1e3e1dc73b088916eefb2db3d3e3c9df743dee7674881a5192
00564610  55                               push   ebp
00564611  8bec                             mov    ebp,esp
00564613  83ec10                           sub    esp,0x10
00564616  a1201fd600                       mov    eax,ds:0xd61f20
0056461b  33c5                             xor    eax,ebp
0056461d  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00564620  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
00564626  8b01                             mov    eax,DWORD PTR [ecx]
00564628  8b5020                           mov    edx,DWORD PTR [eax+0x20]
0056462b  ffd2                             call   edx
0056462d  85c0                             test   eax,eax
0056462f  7454                             je     0x564685
00564631  8b10                             mov    edx,DWORD PTR [eax]
00564633  8b5250                           mov    edx,DWORD PTR [edx+0x50]
00564636  8d4df0                           lea    ecx,[ebp-0x10]
00564639  51                               push   ecx
0056463a  8bc8                             mov    ecx,eax
0056463c  ffd2                             call   edx
0056463e  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00564641  83e800                           sub    eax,0x0
00564644  742c                             je     0x564672
00564646  48                               dec    eax
00564647  7416                             je     0x56465f
00564649  48                               dec    eax
0056464a  7539                             jne    0x564685
0056464c  d945f8                           fld    DWORD PTR [ebp-0x8]
0056464f  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
00564652  33cd                             xor    ecx,ebp
00564654  e8a8c93200                       call   0x891001
00564659  8be5                             mov    esp,ebp
0056465b  5d                               pop    ebp
0056465c  c20400                           ret    0x4
0056465f  d945f4                           fld    DWORD PTR [ebp-0xc]
00564662  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
00564665  33cd                             xor    ecx,ebp
00564667  e895c93200                       call   0x891001
0056466c  8be5                             mov    esp,ebp
0056466e  5d                               pop    ebp
0056466f  c20400                           ret    0x4
00564672  d945f0                           fld    DWORD PTR [ebp-0x10]
00564675  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
00564678  33cd                             xor    ecx,ebp
0056467a  e882c93200                       call   0x891001
0056467f  8be5                             mov    esp,ebp
00564681  5d                               pop    ebp
00564682  c20400                           ret    0x4
00564685  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
00564688  d9ee                             fldz
0056468a  33cd                             xor    ecx,ebp
0056468c  e870c93200                       call   0x891001
00564691  8be5                             mov    esp,ebp
00564693  5d                               pop    ebp
00564694  c20400                           ret    0x4

; I24: known controller leader virtual selects slot 0
; VA 0x005452b0..0x005452c0, raw 0x001446b0, SHA256 b37b9db74cca971392ccec45780f3ed0c7193181067cb6744a912a36fb80c2aa
005452b0  8b01                             mov    eax,DWORD PTR [ecx]
005452b2  8b501c                           mov    edx,DWORD PTR [eax+0x1c]
005452b5  6a00                             push   0x0
005452b7  ffd2                             call   edx
005452b9  c3                               ret
005452ba  cc                               int3
005452bb  cc                               int3
005452bc  cc                               int3
005452bd  cc                               int3
005452be  cc                               int3
005452bf  cc                               int3

; I25: CMonster position getter chooses model position or actor+A0/A4/A8
; VA 0x004c8fa0..0x004c900d, raw 0x000c83a0, SHA256 e5f965ba3937fd658b6e0f2bc8c5511c81ff2348960505859e47fc0bac1c0637
004c8fa0  55                               push   ebp
004c8fa1  8bec                             mov    ebp,esp
004c8fa3  83ec0c                           sub    esp,0xc
004c8fa6  56                               push   esi
004c8fa7  8bf1                             mov    esi,ecx
004c8fa9  57                               push   edi
004c8faa  8bbe5c010000                     mov    edi,DWORD PTR [esi+0x15c]
004c8fb0  85ff                             test   edi,edi
004c8fb2  7434                             je     0x4c8fe8
004c8fb4  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
004c8fbb  742b                             je     0x4c8fe8
004c8fbd  6a00                             push   0x0
004c8fbf  8d45f4                           lea    eax,[ebp-0xc]
004c8fc2  50                               push   eax
004c8fc3  e868eb2d00                       call   0x7a7b30
004c8fc8  85c0                             test   eax,eax
004c8fca  741c                             je     0x4c8fe8
004c8fcc  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004c8fcf  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004c8fd2  8b55f8                           mov    edx,DWORD PTR [ebp-0x8]
004c8fd5  8908                             mov    DWORD PTR [eax],ecx
004c8fd7  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
004c8fda  5f                               pop    edi
004c8fdb  895004                           mov    DWORD PTR [eax+0x4],edx
004c8fde  894808                           mov    DWORD PTR [eax+0x8],ecx
004c8fe1  5e                               pop    esi
004c8fe2  8be5                             mov    esp,ebp
004c8fe4  5d                               pop    ebp
004c8fe5  c20400                           ret    0x4
004c8fe8  8b96a0000000                     mov    edx,DWORD PTR [esi+0xa0]
004c8fee  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004c8ff1  8b8ea4000000                     mov    ecx,DWORD PTR [esi+0xa4]
004c8ff7  8910                             mov    DWORD PTR [eax],edx
004c8ff9  8b96a8000000                     mov    edx,DWORD PTR [esi+0xa8]
004c8fff  5f                               pop    edi
004c9000  894804                           mov    DWORD PTR [eax+0x4],ecx
004c9003  895008                           mov    DWORD PTR [eax+0x8],edx
004c9006  5e                               pop    esi
004c9007  8be5                             mov    esp,ebp
004c9009  5d                               pop    ebp
004c900a  c20400                           ret    0x4

; I26: Tutorial.IsCharacterAvailable registration
; VA 0x004ab260..0x004ab2f9, raw 0x000aa660, SHA256 2784169867bb5a8d46a7df4f2d590b496be55432256bbf291aa84f45cb9eecdc
004ab260  55                               push   ebp
004ab261  8bec                             mov    ebp,esp
004ab263  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004ab266  53                               push   ebx
004ab267  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004ab26d  56                               push   esi
004ab26e  8b33                             mov    esi,DWORD PTR [ebx]
004ab270  57                               push   edi
004ab271  8b38                             mov    edi,DWORD PTR [eax]
004ab273  b8eed8ffff                       mov    eax,0xffffd8ee
004ab278  c7055418fe00009f4a00             mov    DWORD PTR ds:0xfe1854,0x4a9f00
004ab282  e8f9a32400                       call   0x6f5680
004ab287  8b03                             mov    eax,DWORD PTR [ebx]
004ab289  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004ab28c  83e810                           sub    eax,0x10
004ab28f  3dc8bfc000                       cmp    eax,0xc0bfc8
004ab294  7406                             je     0x4ab29c
004ab296  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004ab29a  7414                             je     0x4ab2b0
004ab29c  57                               push   edi
004ab29d  68c426c400                       push   0xc426c4
004ab2a2  e8167e3e00                       call   0x8930bd
004ab2a7  8b1b                             mov    ebx,DWORD PTR [ebx]
004ab2a9  83c408                           add    esp,0x8
004ab2ac  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004ab2b0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004ab2b6  8b37                             mov    esi,DWORD PTR [edi]
004ab2b8  68b0acd600                       push   0xd6acb0
004ab2bd  e84ea22400                       call   0x6f5510
004ab2c2  8b37                             mov    esi,DWORD PTR [edi]
004ab2c4  83c404                           add    esp,0x4
004ab2c7  6a00                             push   0x0
004ab2c9  68e0c54a00                       push   0x4ac5e0
004ab2ce  e8dda22400                       call   0x6f55b0
004ab2d3  8b0f                             mov    ecx,DWORD PTR [edi]
004ab2d5  51                               push   ecx
004ab2d6  b8fdffffff                       mov    eax,0xfffffffd
004ab2db  e810a52400                       call   0x6f57f0
004ab2e0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004ab2e6  8b02                             mov    eax,DWORD PTR [edx]
004ab2e8  83c40c                           add    esp,0xc
004ab2eb  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004ab2ef  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004ab2f2  5f                               pop    edi
004ab2f3  5e                               pop    esi
004ab2f4  5b                               pop    ebx
004ab2f5  5d                               pop    ebp
004ab2f6  c20400                           ret    0x4

; I27: Tutorial getter closure to scalar marshaller
; VA 0x004ac5e0..0x004ac63d, raw 0x000ab9e0, SHA256 400dcfa13e10b5418364efcb6d336e9572e6a1ad705f101c1e135f58927b7d2b
004ac5e0  55                               push   ebp
004ac5e1  8bec                             mov    ebp,esp
004ac5e3  6aff                             push   0xffffffff
004ac5e5  68c8839300                       push   0x9383c8
004ac5ea  64a100000000                     mov    eax,fs:0x0
004ac5f0  50                               push   eax
004ac5f1  83ec0c                           sub    esp,0xc
004ac5f4  a1201fd600                       mov    eax,ds:0xd61f20
004ac5f9  33c5                             xor    eax,ebp
004ac5fb  50                               push   eax
004ac5fc  8d45f4                           lea    eax,[ebp-0xc]
004ac5ff  64a300000000                     mov    fs:0x0,eax
004ac605  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004ac608  8945e8                           mov    DWORD PTR [ebp-0x18],eax
004ac60b  33c0                             xor    eax,eax
004ac60d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
004ac610  8945f0                           mov    DWORD PTR [ebp-0x10],eax
004ac613  8945fc                           mov    DWORD PTR [ebp-0x4],eax
004ac616  8b0d5418fe00                     mov    ecx,DWORD PTR ds:0xfe1854
004ac61c  51                               push   ecx
004ac61d  8d55e8                           lea    edx,[ebp-0x18]
004ac620  52                               push   edx
004ac621  e86a090000                       call   0x4acf90
004ac626  83c408                           add    esp,0x8
004ac629  b801000000                       mov    eax,0x1
004ac62e  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004ac631  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004ac638  59                               pop    ecx
004ac639  8be5                             mov    esp,ebp
004ac63b  5d                               pop    ebp
004ac63c  c3                               ret

; I28: Tutorial scalar result written as a Lua number
; VA 0x004acf90..0x004ad019, raw 0x000ac390, SHA256 6e8aec76b980d9ca1d74821b76457717fabf17e284fd3e182430bbb18e263674
004acf90  55                               push   ebp
004acf91  8bec                             mov    ebp,esp
004acf93  83ec14                           sub    esp,0x14
004acf96  a10418fe00                       mov    eax,ds:0xfe1804
004acf9b  53                               push   ebx
004acf9c  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004acf9f  8b0b                             mov    ecx,DWORD PTR [ebx]
004acfa1  8945fc                           mov    DWORD PTR [ebp-0x4],eax
004acfa4  83c8ff                           or     eax,0xffffffff
004acfa7  e844812400                       call   0x6f50f0
004acfac  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
004acfaf  83f903                           cmp    ecx,0x3
004acfb2  742a                             je     0x4acfde
004acfb4  83f904                           cmp    ecx,0x4
004acfb7  755c                             jne    0x4ad015
004acfb9  56                               push   esi
004acfba  8b30                             mov    esi,DWORD PTR [eax]
004acfbc  57                               push   edi
004acfbd  83c610                           add    esi,0x10
004acfc0  8d7df4                           lea    edi,[ebp-0xc]
004acfc3  e898a72400                       call   0x6f7760
004acfc8  5f                               pop    edi
004acfc9  5e                               pop    esi
004acfca  85c0                             test   eax,eax
004acfcc  7447                             je     0x4ad015
004acfce  dd45f4                           fld    QWORD PTR [ebp-0xc]
004acfd1  c745f403000000                   mov    DWORD PTR [ebp-0xc],0x3
004acfd8  dd5dec                           fstp   QWORD PTR [ebp-0x14]
004acfdb  8d45ec                           lea    eax,[ebp-0x14]
004acfde  dd00                             fld    QWORD PTR [eax]
004acfe0  dd5df4                           fstp   QWORD PTR [ebp-0xc]
004acfe3  dd45f4                           fld    QWORD PTR [ebp-0xc]
004acfe6  db5d08                           fistp  DWORD PTR [ebp+0x8]
004acfe9  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004acfec  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
004acfef  50                               push   eax
004acff0  ff550c                           call   DWORD PTR [ebp+0xc]
004acff3  89450c                           mov    DWORD PTR [ebp+0xc],eax
004acff6  8b03                             mov    eax,DWORD PTR [ebx]
004acff8  db450c                           fild   DWORD PTR [ebp+0xc]
004acffb  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
004acffe  c7410803000000                   mov    DWORD PTR [ecx+0x8],0x3
004ad005  dd19                             fstp   QWORD PTR [ecx]
004ad007  83400810                         add    DWORD PTR [eax+0x8],0x10
004ad00b  b801000000                       mov    eax,0x1
004ad010  5b                               pop    ebx
004ad011  8be5                             mov    esp,ebp
004ad013  5d                               pop    ebp
004ad014  c3                               ret
004ad015  33c0                             xor    eax,eax
004ad017  ebd3                             jmp    0x4acfec

; I29: fixed CCharStatus entry 2 availability check; incoming argument unused
; VA 0x004a9f00..0x004a9f86, raw 0x000a9300, SHA256 c90b22dc095bfe3aa1e79f0f2d8768078847b27c205ce60de39ffcd0355842aa
004a9f00  55                               push   ebp
004a9f01  8bec                             mov    ebp,esp
004a9f03  83e4f8                           and    esp,0xfffffff8
004a9f06  6aff                             push   0xffffffff
004a9f08  680ef89300                       push   0x93f80e
004a9f0d  64a100000000                     mov    eax,fs:0x0
004a9f13  50                               push   eax
004a9f14  51                               push   ecx
004a9f15  a1201fd600                       mov    eax,ds:0xd61f20
004a9f1a  33c4                             xor    eax,esp
004a9f1c  50                               push   eax
004a9f1d  8d442408                         lea    eax,[esp+0x8]
004a9f21  64a300000000                     mov    fs:0x0,eax
004a9f27  b801000000                       mov    eax,0x1
004a9f2c  84059043f900                     test   BYTE PTR ds:0xf94390,al
004a9f32  7520                             jne    0x4a9f54
004a9f34  09059043f900                     or     DWORD PTR ds:0xf94390,eax
004a9f3a  c744241000000000                 mov    DWORD PTR [esp+0x10],0x0
004a9f42  e849760300                       call   0x4e1590
004a9f47  6880ccbc00                       push   0xbccc80
004a9f4c  e8c9833e00                       call   0x89231a
004a9f51  83c404                           add    esp,0x4
004a9f54  a10443f900                       mov    eax,ds:0xf94304
004a9f59  83b87c04000000                   cmp    DWORD PTR [eax+0x47c],0x0
004a9f60  7504                             jne    0x4a9f66
004a9f62  33c0                             xor    eax,eax
004a9f64  eb05                             jmp    0x4a9f6b
004a9f66  0520040000                       add    eax,0x420
004a9f6b  33c9                             xor    ecx,ecx
004a9f6d  85c0                             test   eax,eax
004a9f6f  0f95c1                           setne  cl
004a9f72  8bc1                             mov    eax,ecx
004a9f74  8b4c2408                         mov    ecx,DWORD PTR [esp+0x8]
004a9f78  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004a9f7f  59                               pop    ecx
004a9f80  8be5                             mov    esp,ebp
004a9f82  5d                               pop    ebp
004a9f83  c20400                           ret    0x4

; I30: ten CCharStatus objects of stride 0x210 published as F94304
; VA 0x004e199e..0x004e19e4, raw 0x000e0d9e, SHA256 e8776949bc3f2942a71ef03e1699c354b6806a79fb0671f84c8adf85a9774116
004e199e  68a0140000                       push   0x14a0
004e19a3  a30043f900                       mov    ds:0xf94300,eax
004e19a8  e8bbf83a00                       call   0x891268
004e19ad  8bf0                             mov    esi,eax
004e19af  83c404                           add    esp,0x4
004e19b2  8975f0                           mov    DWORD PTR [ebp-0x10],esi
004e19b5  c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
004e19b9  3bf3                             cmp    esi,ebx
004e19bb  7419                             je     0x4e19d6
004e19bd  68c03e4d00                       push   0x4d3ec0
004e19c2  68003d4d00                       push   0x4d3d00
004e19c7  6a0a                             push   0xa
004e19c9  6810020000                       push   0x210
004e19ce  56                               push   esi
004e19cf  e82f063b00                       call   0x892003
004e19d4  eb02                             jmp    0x4e19d8
004e19d6  33f6                             xor    esi,esi
004e19d8  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
004e19dc  6a74                             push   0x74
004e19de  89350443f900                     mov    DWORD PTR ds:0xf94304,esi

; I31: CCharStatus vtable and +5C initialization
; VA 0x004d3d00..0x004d3d84, raw 0x000d3100, SHA256 dc587a50ab92c730a712a04974977709d84193fb8e713424b70415f25812ff3f
004d3d00  55                               push   ebp
004d3d01  8bec                             mov    ebp,esp
004d3d03  6aff                             push   0xffffffff
004d3d05  68add89000                       push   0x90d8ad
004d3d0a  64a100000000                     mov    eax,fs:0x0
004d3d10  50                               push   eax
004d3d11  51                               push   ecx
004d3d12  53                               push   ebx
004d3d13  56                               push   esi
004d3d14  a1201fd600                       mov    eax,ds:0xd61f20
004d3d19  33c5                             xor    eax,ebp
004d3d1b  50                               push   eax
004d3d1c  8d45f4                           lea    eax,[ebp-0xc]
004d3d1f  64a300000000                     mov    fs:0x0,eax
004d3d25  8bf1                             mov    esi,ecx
004d3d27  8975f0                           mov    DWORD PTR [ebp-0x10],esi
004d3d2a  33db                             xor    ebx,ebx
004d3d2c  895e04                           mov    DWORD PTR [esi+0x4],ebx
004d3d2f  895e08                           mov    DWORD PTR [esi+0x8],ebx
004d3d32  895e40                           mov    DWORD PTR [esi+0x40],ebx
004d3d35  895e44                           mov    DWORD PTR [esi+0x44],ebx
004d3d38  895e48                           mov    DWORD PTR [esi+0x48],ebx
004d3d3b  895e4c                           mov    DWORD PTR [esi+0x4c],ebx
004d3d3e  895e50                           mov    DWORD PTR [esi+0x50],ebx
004d3d41  895e54                           mov    DWORD PTR [esi+0x54],ebx
004d3d44  895e58                           mov    DWORD PTR [esi+0x58],ebx
004d3d47  b864000000                       mov    eax,0x64
004d3d4c  894634                           mov    DWORD PTR [esi+0x34],eax
004d3d4f  894638                           mov    DWORD PTR [esi+0x38],eax
004d3d52  89463c                           mov    DWORD PTR [esi+0x3c],eax
004d3d55  33c0                             xor    eax,eax
004d3d57  89460c                           mov    DWORD PTR [esi+0xc],eax
004d3d5a  894610                           mov    DWORD PTR [esi+0x10],eax
004d3d5d  894614                           mov    DWORD PTR [esi+0x14],eax
004d3d60  894618                           mov    DWORD PTR [esi+0x18],eax
004d3d63  89461c                           mov    DWORD PTR [esi+0x1c],eax
004d3d66  894620                           mov    DWORD PTR [esi+0x20],eax
004d3d69  894624                           mov    DWORD PTR [esi+0x24],eax
004d3d6c  894628                           mov    DWORD PTR [esi+0x28],eax
004d3d6f  89462c                           mov    DWORD PTR [esi+0x2c],eax
004d3d72  894630                           mov    DWORD PTR [esi+0x30],eax
004d3d75  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
004d3d78  0f57c0                           xorps  xmm0,xmm0
004d3d7b  c706b0cbc000                     mov    DWORD PTR [esi],0xc0cbb0
004d3d81  895e5c                           mov    DWORD PTR [esi+0x5c],ebx

; I32: AILINK/AI child lookup via XML helpers
; VA 0x0054b6ca..0x0054b6f4, raw 0x0014aaca, SHA256 43cb26fd27961000215c0f2dbacc21f8074bfbae88de12bf5ce022e530a306e4
0054b6ca  6828fcc000                       push   0xc0fc28
0054b6cf  8bf1                             mov    esi,ecx
0054b6d1  e80a2c1e00                       call   0x72e2e0
0054b6d6  85c0                             test   eax,eax
0054b6d8  0f8477010000                     je     0x54b855
0054b6de  bf30fcc000                       mov    edi,0xc0fc30
0054b6e3  e8782c1e00                       call   0x72e360
0054b6e8  8944240c                         mov    DWORD PTR [esp+0xc],eax
0054b6ec  85c0                             test   eax,eax
0054b6ee  0f8461010000                     je     0x54b855

; I33: AI next sibling XML traversal
; VA 0x0054b83b..0x0054b855, raw 0x0014ac3b, SHA256 a9d670507789bbd09e0cd37c3f0e059f04656cfdf78edb9197da2cf689bc557e
0054b83b  8b44240c                         mov    eax,DWORD PTR [esp+0xc]
0054b83f  bf30fcc000                       mov    edi,0xc0fc30
0054b844  e8772b1e00                       call   0x72e3c0
0054b849  8944240c                         mov    DWORD PTR [esp+0xc],eax
0054b84d  85c0                             test   eax,eax
0054b84f  0f85abfeffff                     jne    0x54b700

; I34: native SubAI condition/action factories and registration
; VA 0x0054b52a..0x0054b691, raw 0x0014a92a, SHA256 fe0d5a0eb381aba2c994b12e1ccae06ccb084ab093086689793898f400b35e5f
0054b52a  6a14                             push   0x14
0054b52c  e8375d3400                       call   0x891268
0054b531  83c404                           add    esp,0x4
0054b534  3bc6                             cmp    eax,esi
0054b536  741b                             je     0x54b553
0054b538  0f57c0                           xorps  xmm0,xmm0
0054b53b  c7005cfcc000                     mov    DWORD PTR [eax],0xc0fc5c
0054b541  897004                           mov    DWORD PTR [eax+0x4],esi
0054b544  897008                           mov    DWORD PTR [eax+0x8],esi
0054b547  f30f11400c                       movss  DWORD PTR [eax+0xc],xmm0
0054b54c  f30f114010                       movss  DWORD PTR [eax+0x10],xmm0
0054b551  eb02                             jmp    0x54b555
0054b553  33c0                             xor    eax,eax
0054b555  8b7314                           mov    esi,DWORD PTR [ebx+0x14]
0054b558  50                               push   eax
0054b559  bfdcfbc000                       mov    edi,0xc0fbdc
0054b55e  e86de02b00                       call   0x8095d0
0054b563  6a08                             push   0x8
0054b565  e8fe5c3400                       call   0x891268
0054b56a  83c404                           add    esp,0x4
0054b56d  85c0                             test   eax,eax
0054b56f  740f                             je     0x54b580
0054b571  c70070fcc000                     mov    DWORD PTR [eax],0xc0fc70
0054b577  c7400400000000                   mov    DWORD PTR [eax+0x4],0x0
0054b57e  eb02                             jmp    0x54b582
0054b580  33c0                             xor    eax,eax
0054b582  8b7314                           mov    esi,DWORD PTR [ebx+0x14]
0054b585  50                               push   eax
0054b586  bfe4fbc000                       mov    edi,0xc0fbe4
0054b58b  e840e02b00                       call   0x8095d0
0054b590  6a10                             push   0x10
0054b592  e8d15c3400                       call   0x891268
0054b597  33c9                             xor    ecx,ecx
0054b599  83c404                           add    esp,0x4
0054b59c  3bc1                             cmp    eax,ecx
0054b59e  7411                             je     0x54b5b1
0054b5a0  c70084fcc000                     mov    DWORD PTR [eax],0xc0fc84
0054b5a6  894804                           mov    DWORD PTR [eax+0x4],ecx
0054b5a9  894808                           mov    DWORD PTR [eax+0x8],ecx
0054b5ac  89480c                           mov    DWORD PTR [eax+0xc],ecx
0054b5af  eb02                             jmp    0x54b5b3
0054b5b1  33c0                             xor    eax,eax
0054b5b3  8b7314                           mov    esi,DWORD PTR [ebx+0x14]
0054b5b6  50                               push   eax
0054b5b7  bfecfbc000                       mov    edi,0xc0fbec
0054b5bc  e80fe02b00                       call   0x8095d0
0054b5c1  6a14                             push   0x14
0054b5c3  e8a05c3400                       call   0x891268
0054b5c8  8bf0                             mov    esi,eax
0054b5ca  33c0                             xor    eax,eax
0054b5cc  83c404                           add    esp,0x4
0054b5cf  3bf0                             cmp    esi,eax
0054b5d1  7438                             je     0x54b60b
0054b5d3  c70698fcc000                     mov    DWORD PTR [esi],0xc0fc98
0054b5d9  8bc8                             mov    ecx,eax
0054b5db  8bf8                             mov    edi,eax
0054b5dd  894604                           mov    DWORD PTR [esi+0x4],eax
0054b5e0  894608                           mov    DWORD PTR [esi+0x8],eax
0054b5e3  89460c                           mov    DWORD PTR [esi+0xc],eax
0054b5e6  3bf9                             cmp    edi,ecx
0054b5e8  7423                             je     0x54b60d
0054b5ea  2bc1                             sub    eax,ecx
0054b5ec  c1f802                           sar    eax,0x2
0054b5ef  03c0                             add    eax,eax
0054b5f1  03c0                             add    eax,eax
0054b5f3  50                               push   eax
0054b5f4  51                               push   ecx
0054b5f5  57                               push   edi
0054b5f6  89442418                         mov    DWORD PTR [esp+0x18],eax
0054b5fa  e8f15c3400                       call   0x8912f0
0054b5ff  83c40c                           add    esp,0xc
0054b602  8b7c240c                         mov    edi,DWORD PTR [esp+0xc]
0054b606  897e08                           mov    DWORD PTR [esi+0x8],edi
0054b609  eb02                             jmp    0x54b60d
0054b60b  33f6                             xor    esi,esi
0054b60d  56                               push   esi
0054b60e  8b7314                           mov    esi,DWORD PTR [ebx+0x14]
0054b611  bff8fbc000                       mov    edi,0xc0fbf8
0054b616  e8b5df2b00                       call   0x8095d0
0054b61b  6a10                             push   0x10
0054b61d  e8465c3400                       call   0x891268
0054b622  33c9                             xor    ecx,ecx
0054b624  83c404                           add    esp,0x4
0054b627  3bc1                             cmp    eax,ecx
0054b629  7411                             je     0x54b63c
0054b62b  c700acfcc000                     mov    DWORD PTR [eax],0xc0fcac
0054b631  894804                           mov    DWORD PTR [eax+0x4],ecx
0054b634  894808                           mov    DWORD PTR [eax+0x8],ecx
0054b637  89480c                           mov    DWORD PTR [eax+0xc],ecx
0054b63a  eb02                             jmp    0x54b63e
0054b63c  33c0                             xor    eax,eax
0054b63e  8b7318                           mov    esi,DWORD PTR [ebx+0x18]
0054b641  50                               push   eax
0054b642  bf00fcc000                       mov    edi,0xc0fc00
0054b647  e884df2b00                       call   0x8095d0
0054b64c  6a14                             push   0x14
0054b64e  e8155c3400                       call   0x891268
0054b653  33c9                             xor    ecx,ecx
0054b655  83c404                           add    esp,0x4
0054b658  3bc1                             cmp    eax,ecx
0054b65a  7418                             je     0x54b674
0054b65c  c700c0fcc000                     mov    DWORD PTR [eax],0xc0fcc0
0054b662  894804                           mov    DWORD PTR [eax+0x4],ecx
0054b665  894808                           mov    DWORD PTR [eax+0x8],ecx
0054b668  c7400cffffffff                   mov    DWORD PTR [eax+0xc],0xffffffff
0054b66f  894810                           mov    DWORD PTR [eax+0x10],ecx
0054b672  eb02                             jmp    0x54b676
0054b674  33c0                             xor    eax,eax
0054b676  8b7318                           mov    esi,DWORD PTR [ebx+0x18]
0054b679  50                               push   eax
0054b67a  bf08fcc000                       mov    edi,0xc0fc08
0054b67f  e84cdf2b00                       call   0x8095d0
0054b684  53                               push   ebx
0054b685  e8a6d02b00                       call   0x808730
0054b68a  5f                               pop    edi
0054b68b  5e                               pop    esi
0054b68c  5b                               pop    ebx
0054b68d  8be5                             mov    esp,ebp
0054b68f  5d                               pop    ebp
0054b690  c3                               ret

; I35: native XML document construction/load and AILIST/ITEMLIST lookup
; VA 0x0080875e..0x0080881f, raw 0x00407b5e, SHA256 0ebcbb81ab747dc4bdb3a4dc22c35734062c622a82ca99266fe7d3468666954b
0080875e  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00808761  8d8d74ffffff                     lea    ecx,[ebp-0x8c]
00808767  51                               push   ecx
00808768  b910fcc000                       mov    ecx,0xc0fc10
0080876d  898570ffffff                     mov    DWORD PTR [ebp-0x90],eax
00808773  e8b866f2ff                       call   0x72ee30
00808778  33db                             xor    ebx,ebx
0080877a  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0080877d  8b4d94                           mov    ecx,DWORD PTR [ebp-0x6c]
00808780  bf10000000                       mov    edi,0x10
00808785  397da8                           cmp    DWORD PTR [ebp-0x58],edi
00808788  7303                             jae    0x80878d
0080878a  8d4d94                           lea    ecx,[ebp-0x6c]
0080878d  53                               push   ebx
0080878e  8db574ffffff                     lea    esi,[ebp-0x8c]
00808794  e87769f2ff                       call   0x72f110
00808799  385db8                           cmp    BYTE PTR [ebp-0x48],bl
0080879c  7441                             je     0x8087df
0080879e  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
008087a5  c78574ffffff9423bf00             mov    DWORD PTR [ebp-0x8c],0xbf2394
008087af  397dd4                           cmp    DWORD PTR [ebp-0x2c],edi
008087b2  720c                             jb     0x8087c0
008087b4  8b55c0                           mov    edx,DWORD PTR [ebp-0x40]
008087b7  52                               push   edx
008087b8  e84f8a0800                       call   0x89120c
008087bd  83c404                           add    esp,0x4
008087c0  8d8d74ffffff                     lea    ecx,[ebp-0x8c]
008087c6  c745d40f000000                   mov    DWORD PTR [ebp-0x2c],0xf
008087cd  895dd0                           mov    DWORD PTR [ebp-0x30],ebx
008087d0  885dc0                           mov    BYTE PTR [ebp-0x40],bl
008087d3  e86858f2ff                       call   0x72e040
008087d8  33c0                             xor    eax,eax
008087da  e93c010000                       jmp    0x80891b
008087df  689417c500                       push   0xc51794
008087e4  8d8574ffffff                     lea    eax,[ebp-0x8c]
008087ea  e8f15af2ff                       call   0x72e2e0
008087ef  898568ffffff                     mov    DWORD PTR [ebp-0x98],eax
008087f5  3bc3                             cmp    eax,ebx
008087f7  751c                             jne    0x808815
008087f9  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
00808800  c78574ffffff9423bf00             mov    DWORD PTR [ebp-0x8c],0xbf2394
0080880a  397dd4                           cmp    DWORD PTR [ebp-0x2c],edi
0080880d  72b1                             jb     0x8087c0
0080880f  8b45c0                           mov    eax,DWORD PTR [ebp-0x40]
00808812  50                               push   eax
00808813  eba3                             jmp    0x8087b8
00808815  6840b8bf00                       push   0xbfb840
0080881a  e8c15af2ff                       call   0x72e2e0

; I36: native AI XML child lookup
; VA 0x008089f2..0x00808a2e, raw 0x00407df2, SHA256 ea06cf439e0fc00138f22d902585c835059665be59f305f9ff93fa6d4e87bbb6
008089f2  6830fcc000                       push   0xc0fc30
008089f7  8d8574ffffff                     lea    eax,[ebp-0x8c]
008089fd  e8de58f2ff                       call   0x72e2e0
00808a02  8bd8                             mov    ebx,eax
00808a04  3bdf                             cmp    ebx,edi
00808a06  751d                             jne    0x808a25
00808a08  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
00808a0f  837dd410                         cmp    DWORD PTR [ebp-0x2c],0x10
00808a13  c78574ffffff9423bf00             mov    DWORD PTR [ebp-0x8c],0xbf2394
00808a1d  72b3                             jb     0x8089d2
00808a1f  8b55c0                           mov    edx,DWORD PTR [ebp-0x40]
00808a22  52                               push   edx
00808a23  eba5                             jmp    0x8089ca
00808a25  8b03                             mov    eax,DWORD PTR [ebx]
00808a27  8b5014                           mov    edx,DWORD PTR [eax+0x14]
00808a2a  8bcb                             mov    ecx,ebx
00808a2c  ffd2                             call   edx

; I37: native string-keyed map registration, not a Lua closure registration
; VA 0x008095d0..0x008096fb, raw 0x004089d0, SHA256 d041754394db302178499ff54fbf27955c8984eef7bbfbbc3a55e34b145eafb3
008095d0  55                               push   ebp
008095d1  8bec                             mov    ebp,esp
008095d3  6aff                             push   0xffffffff
008095d5  6850449100                       push   0x914450
008095da  64a100000000                     mov    eax,fs:0x0
008095e0  50                               push   eax
008095e1  83ec50                           sub    esp,0x50
008095e4  a1201fd600                       mov    eax,ds:0xd61f20
008095e9  33c5                             xor    eax,ebp
008095eb  8945ec                           mov    DWORD PTR [ebp-0x14],eax
008095ee  53                               push   ebx
008095ef  50                               push   eax
008095f0  8d45f4                           lea    eax,[ebp-0xc]
008095f3  64a300000000                     mov    fs:0x0,eax
008095f9  33db                             xor    ebx,ebx
008095fb  8bc7                             mov    eax,edi
008095fd  c745e40f000000                   mov    DWORD PTR [ebp-0x1c],0xf
00809604  895de0                           mov    DWORD PTR [ebp-0x20],ebx
00809607  885dd0                           mov    BYTE PTR [ebp-0x30],bl
0080960a  8d4801                           lea    ecx,[eax+0x1]
0080960d  8d4900                           lea    ecx,[ecx+0x0]
00809610  8a10                             mov    dl,BYTE PTR [eax]
00809612  40                               inc    eax
00809613  3ad3                             cmp    dl,bl
00809615  75f9                             jne    0x809610
00809617  2bc1                             sub    eax,ecx
00809619  50                               push   eax
0080961a  57                               push   edi
0080961b  8d4dd0                           lea    ecx,[ebp-0x30]
0080961e  e84d94bfff                       call   0x402a70
00809623  8d45d0                           lea    eax,[ebp-0x30]
00809626  50                               push   eax
00809627  8bc6                             mov    eax,esi
00809629  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0080962c  e8ffd8faff                       call   0x7b6f30
00809631  8945a4                           mov    DWORD PTR [ebp-0x5c],eax
00809634  3b4604                           cmp    eax,DWORD PTR [esi+0x4]
00809637  7414                             je     0x80964d
00809639  83c00c                           add    eax,0xc
0080963c  8d55d0                           lea    edx,[ebp-0x30]
0080963f  e8ec17c9ff                       call   0x49ae30
00809644  84c0                             test   al,al
00809646  7505                             jne    0x80964d
00809648  8d45a4                           lea    eax,[ebp-0x5c]
0080964b  eb09                             jmp    0x809656
0080964d  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
00809650  894dac                           mov    DWORD PTR [ebp-0x54],ecx
00809653  8d45ac                           lea    eax,[ebp-0x54]
00809656  8b10                             mov    edx,DWORD PTR [eax]
00809658  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0080965f  837de410                         cmp    DWORD PTR [ebp-0x1c],0x10
00809663  8955ac                           mov    DWORD PTR [ebp-0x54],edx
00809666  720c                             jb     0x809674
00809668  8b45d0                           mov    eax,DWORD PTR [ebp-0x30]
0080966b  50                               push   eax
0080966c  e89b7b0800                       call   0x89120c
00809671  83c404                           add    esp,0x4
00809674  8b4dac                           mov    ecx,DWORD PTR [ebp-0x54]
00809677  3b4e04                           cmp    ecx,DWORD PTR [esi+0x4]
0080967a  7404                             je     0x809680
0080967c  33c0                             xor    eax,eax
0080967e  eb5f                             jmp    0x8096df
00809680  8bc7                             mov    eax,edi
00809682  c745c40f000000                   mov    DWORD PTR [ebp-0x3c],0xf
00809689  895dc0                           mov    DWORD PTR [ebp-0x40],ebx
0080968c  885db0                           mov    BYTE PTR [ebp-0x50],bl
0080968f  8d5001                           lea    edx,[eax+0x1]
00809692  8a08                             mov    cl,BYTE PTR [eax]
00809694  40                               inc    eax
00809695  3acb                             cmp    cl,bl
00809697  75f9                             jne    0x809692
00809699  2bc2                             sub    eax,edx
0080969b  50                               push   eax
0080969c  57                               push   edi
0080969d  8d4db0                           lea    ecx,[ebp-0x50]
008096a0  e8cb93bfff                       call   0x402a70
008096a5  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
008096a8  8955cc                           mov    DWORD PTR [ebp-0x34],edx
008096ab  8d45b0                           lea    eax,[ebp-0x50]
008096ae  50                               push   eax
008096af  8bce                             mov    ecx,esi
008096b1  c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
008096b8  e82397d4ff                       call   0x552de0
008096bd  50                               push   eax
008096be  8d4da8                           lea    ecx,[ebp-0x58]
008096c1  51                               push   ecx
008096c2  56                               push   esi
008096c3  e84892fdff                       call   0x7e2910
008096c8  837dc410                         cmp    DWORD PTR [ebp-0x3c],0x10
008096cc  720c                             jb     0x8096da
008096ce  8b55b0                           mov    edx,DWORD PTR [ebp-0x50]
008096d1  52                               push   edx
008096d2  e8357b0800                       call   0x89120c
008096d7  83c404                           add    esp,0x4
008096da  b801000000                       mov    eax,0x1
008096df  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
008096e2  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
008096e9  59                               pop    ecx
008096ea  5b                               pop    ebx
008096eb  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
008096ee  33cd                             xor    ecx,ebp
008096f0  e80c790800                       call   0x891001
008096f5  8be5                             mov    esp,ebp
008096f7  5d                               pop    ebp
008096f8  c20400                           ret    0x4

; I38: Actor literal goes to native scene-node lookup
; VA 0x007d37b0..0x007d37e0, raw 0x003d2bb0, SHA256 ae0a611605d11c95c3152fa3f3285889265af5afd131f08f6299c4b08fc0581a
007d37b0  53                               push   ebx
007d37b1  56                               push   esi
007d37b2  8bf0                             mov    esi,eax
007d37b4  57                               push   edi
007d37b5  8bce                             mov    ecx,esi
007d37b7  e874f9ffff                       call   0x7d3130
007d37bc  56                               push   esi
007d37bd  e8ee010000                       call   0x7d39b0
007d37c2  8b4610                           mov    eax,DWORD PTR [esi+0x10]
007d37c5  33db                             xor    ebx,ebx
007d37c7  53                               push   ebx
007d37c8  53                               push   ebx
007d37c9  68c800c500                       push   0xc500c8
007d37ce  50                               push   eax
007d37cf  895e14                           mov    DWORD PTR [esi+0x14],ebx
007d37d2  e8592cffff                       call   0x7c6430
007d37d7  8bf8                             mov    edi,eax
007d37d9  83c410                           add    esp,0x10
007d37dc  3bfb                             cmp    edi,ebx
007d37de  746e                             je     0x7d384e

; I39: SetID literal goes to XML attribute and integer parsing
; VA 0x008318ce..0x008318f8, raw 0x00430cce, SHA256 a7aff755a4d825b897bfe7fe6926aec59a1108a4ac6abdbefca4a290552b0dc5
008318ce  68603ac500                       push   0xc53a60
008318d3  e8c8e7efff                       call   0x7300a0
008318d8  85c0                             test   eax,eax
008318da  741a                             je     0x8318f6
008318dc  83c030                           add    eax,0x30
008318df  83781410                         cmp    DWORD PTR [eax+0x14],0x10
008318e3  7202                             jb     0x8318e7
008318e5  8b00                             mov    eax,DWORD PTR [eax]
008318e7  85c0                             test   eax,eax
008318e9  740b                             je     0x8318f6
008318eb  50                               push   eax
008318ec  e8c3fe0500                       call   0x8917b4
008318f1  83c404                           add    esp,0x4
008318f4  eb02                             jmp    0x8318f8
008318f6  33c0                             xor    eax,eax

; I40: control-row mapper rejects actor model >9 and returns false
; VA 0x00546100..0x0054621f, raw 0x00145500, SHA256 d224a101e1de0fb560e0194d9328bfb86a5db4e4e8b1a2163c154998f2f6407e
00546100  55                               push   ebp
00546101  8bec                             mov    ebp,esp
00546103  83e4f8                           and    esp,0xfffffff8
00546106  6aff                             push   0xffffffff
00546108  686cfe9300                       push   0x93fe6c
0054610d  64a100000000                     mov    eax,fs:0x0
00546113  50                               push   eax
00546114  83ec28                           sub    esp,0x28
00546117  53                               push   ebx
00546118  56                               push   esi
00546119  57                               push   edi
0054611a  a1201fd600                       mov    eax,ds:0xd61f20
0054611f  33c4                             xor    eax,esp
00546121  50                               push   eax
00546122  8d442438                         lea    eax,[esp+0x38]
00546126  64a300000000                     mov    fs:0x0,eax
0054612c  894c2418                         mov    DWORD PTR [esp+0x18],ecx
00546130  833daca7fb0003                   cmp    DWORD PTR ds:0xfba7ac,0x3
00546137  8b790c                           mov    edi,DWORD PTR [ecx+0xc]
0054613a  c644241700                       mov    BYTE PTR [esp+0x17],0x0
0054613f  750a                             jne    0x54614b
00546141  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00546144  8d444003                         lea    eax,[eax+eax*2+0x3]
00546148  8b3c81                           mov    edi,DWORD PTR [ecx+eax*4]
0054614b  33f6                             xor    esi,esi
0054614d  3bfe                             cmp    edi,esi
0054614f  7520                             jne    0x546171
00546151  89717c                           mov    DWORD PTR [ecx+0x7c],esi
00546154  89b180000000                     mov    DWORD PTR [ecx+0x80],esi
0054615a  32c0                             xor    al,al
0054615c  8b4c2438                         mov    ecx,DWORD PTR [esp+0x38]
00546160  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00546167  59                               pop    ecx
00546168  5f                               pop    edi
00546169  5e                               pop    esi
0054616a  5b                               pop    ebx
0054616b  8be5                             mov    esp,ebp
0054616d  5d                               pop    ebp
0054616e  c20800                           ret    0x8
00546171  0fb687e4000000                   movzx  eax,BYTE PTR [edi+0xe4]
00546178  8b97e0000000                     mov    edx,DWORD PTR [edi+0xe0]
0054617e  8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
00546181  88442430                         mov    BYTE PTR [esp+0x30],al
00546185  33c0                             xor    eax,eax
00546187  8954242c                         mov    DWORD PTR [esp+0x2c],edx
0054618b  8a97b0000000                     mov    dl,BYTE PTR [edi+0xb0]
00546191  66894302                         mov    WORD PTR [ebx+0x2],ax
00546195  8a87b0000000                     mov    al,BYTE PTR [edi+0xb0]
0054619b  884304                           mov    BYTE PTR [ebx+0x4],al
0054619e  8b8758010000                     mov    eax,DWORD PTR [edi+0x158]
005461a4  8854241c                         mov    BYTE PTR [esp+0x1c],dl
005461a8  89742420                         mov    DWORD PTR [esp+0x20],esi
005461ac  3bc6                             cmp    eax,esi
005461ae  7405                             je     0x5461b5
005461b0  397034                           cmp    DWORD PTR [eax+0x34],esi
005461b3  7409                             je     0x5461be
005461b5  89717c                           mov    DWORD PTR [ecx+0x7c],esi
005461b8  89b180000000                     mov    DWORD PTR [ecx+0x80],esi
005461be  f6059043f90001                   test   BYTE PTR ds:0xf94390,0x1
005461c5  89742428                         mov    DWORD PTR [esp+0x28],esi
005461c9  7525                             jne    0x5461f0
005461cb  830d9043f90001                   or     DWORD PTR ds:0xf94390,0x1
005461d2  89742440                         mov    DWORD PTR [esp+0x40],esi
005461d6  e8b5b3f9ff                       call   0x4e1590
005461db  6880ccbc00                       push   0xbccc80
005461e0  e835c13400                       call   0x89231a
005461e5  83c404                           add    esp,0x4
005461e8  c7442440ffffffff                 mov    DWORD PTR [esp+0x40],0xffffffff
005461f0  0fb78788000000                   movzx  eax,WORD PTR [edi+0x88]
005461f7  8b0d0443f900                     mov    ecx,DWORD PTR ds:0xf94304
005461fd  83f809                           cmp    eax,0x9
00546200  0f8754ffffff                     ja     0x54615a
00546206  69c010020000                     imul   eax,eax,0x210
0054620c  03c1                             add    eax,ecx
0054620e  39705c                           cmp    DWORD PTR [eax+0x5c],esi
00546211  0f8443ffffff                     je     0x54615a
00546217  3bc6                             cmp    eax,esi
00546219  0f843bffffff                     je     0x54615a

; I41: base actor fields +90/+9C initialized separately from world ID
; VA 0x004ca744..0x004ca76e, raw 0x000c9b44, SHA256 c8da7014424ca6b76cafa40cbeca6292028312e9409d0a888901417aea45d1a1
004ca744  33db                             xor    ebx,ebx
004ca746  c706ac76c000                     mov    DWORD PTR [esi],0xc076ac
004ca74c  899e88000000                     mov    DWORD PTR [esi+0x88],ebx
004ca752  899e8c000000                     mov    DWORD PTR [esi+0x8c],ebx
004ca758  c786900000007f000000             mov    DWORD PTR [esi+0x90],0x7f
004ca762  899e98000000                     mov    DWORD PTR [esi+0x98],ebx
004ca768  899e9c000000                     mov    DWORD PTR [esi+0x9c],ebx

; I42: common dispatcher registrations 0001/0007/000B/000C
; VA 0x004add6f..0x004addd7, raw 0x000ad16f, SHA256 57cca473e960f84080722b30f6a522452a1192fe40b0d93a7f3b67e49fb39d58
004add6f  ba80fb4a00                       mov    edx,0x4afb80
004add74  c74034307d4b00                   mov    DWORD PTR [eax+0x34],0x4b7d30
004add7b  894838                           mov    DWORD PTR [eax+0x38],ecx
004add7e  c7403cd0e44a00                   mov    DWORD PTR [eax+0x3c],0x4ae4d0
004add85  894840                           mov    DWORD PTR [eax+0x40],ecx
004add88  c780f4090000b0ed4a00             mov    DWORD PTR [eax+0x9f4],0x4aedb0
004add92  8988f8090000                     mov    DWORD PTR [eax+0x9f8],ecx
004add98  c7404430f54a00                   mov    DWORD PTR [eax+0x44],0x4af530
004add9f  894848                           mov    DWORD PTR [eax+0x48],ecx
004adda2  c7405420f94a00                   mov    DWORD PTR [eax+0x54],0x4af920
004adda9  894858                           mov    DWORD PTR [eax+0x58],ecx
004addac  c74004f0fa4a00                   mov    DWORD PTR [eax+0x4],0x4afaf0
004addb3  894808                           mov    DWORD PTR [eax+0x8],ecx
004addb6  89500c                           mov    DWORD PTR [eax+0xc],edx
004addb9  894810                           mov    DWORD PTR [eax+0x10],ecx
004addbc  c7405c60fe4a00                   mov    DWORD PTR [eax+0x5c],0x4afe60
004addc3  894860                           mov    DWORD PTR [eax+0x60],ecx
004addc6  c7406430014b00                   mov    DWORD PTR [eax+0x64],0x4b0130
004addcd  894868                           mov    DWORD PTR [eax+0x68],ecx
004addd0  c7406cc0014b00                   mov    DWORD PTR [eax+0x6c],0x4b01c0

; I43: common dispatcher registrations 0016 and 001A
; VA 0x004ade71..0x004ade9d, raw 0x000ad271, SHA256 b52c7d2144e18b84a1cfa2c2069a1191ac907151f24057bb2f487dbbbd5a9919
004ade71  8990b4000000                     mov    DWORD PTR [eax+0xb4],edx
004ade77  8988b8000000                     mov    DWORD PTR [eax+0xb8],ecx
004ade7d  c780c400000030274b00             mov    DWORD PTR [eax+0xc4],0x4b2730
004ade87  8988c8000000                     mov    DWORD PTR [eax+0xc8],ecx
004ade8d  c780d4000000d0284b00             mov    DWORD PTR [eax+0xd4],0x4b28d0
004ade97  8988d8000000                     mov    DWORD PTR [eax+0xd8],ecx
