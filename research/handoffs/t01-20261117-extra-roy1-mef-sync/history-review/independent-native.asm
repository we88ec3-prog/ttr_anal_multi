; point_delta 0x4b32e0..0x4b3347
004B32E0  55                               push   ebp
004B32E1  8bec                             mov    ebp,esp
004B32E3  b901000000                       mov    ecx,0x1
004B32E8  840dec79fb00                     test   BYTE PTR ds:0xfb79ec,cl
004B32EE  7534                             jne    0x4b3324
004B32F0  090dec79fb00                     or     DWORD PTR ds:0xfb79ec,ecx
004B32F6  33c0                             xor    eax,eax
004B32F8  6870d2bc00                       push   0xbcd270
004B32FD  c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
004B3307  a3f479fb00                       mov    ds:0xfb79f4,eax
004B330C  a3f879fb00                       mov    ds:0xfb79f8,eax
004B3311  a3fc79fb00                       mov    ds:0xfb79fc,eax
004B3316  890d047afb00                     mov    DWORD PTR ds:0xfb7a04,ecx
004B331C  e8f9ef3d00                       call   0x89231a
004B3321  83c404                           add    esp,0x4
004B3324  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004B3327  0fb64805                         movzx  ecx,BYTE PTR [eax+0x5]
004B332B  0fb65004                         movzx  edx,BYTE PTR [eax+0x4]
004B332F  0fb74002                         movzx  eax,WORD PTR [eax+0x2]
004B3333  51                               push   ecx
004B3334  52                               push   edx
004B3335  50                               push   eax
004B3336  baf079fb00                       mov    edx,0xfb79f0
004B333B  e800160900                       call   0x544940
004B3340  33c0                             xor    eax,eax
004B3342  5d                               pop    ebp
004B3343  c20c00                           ret    0xc
004B3346  cc                               int3

; point_first_match 0x544940..0x54499f
00544940  55                               push   ebp
00544941  8bec                             mov    ebp,esp
00544943  8b4208                           mov    eax,DWORD PTR [edx+0x8]
00544946  2b4204                           sub    eax,DWORD PTR [edx+0x4]
00544949  53                               push   ebx
0054494A  c1f802                           sar    eax,0x2
0054494D  56                               push   esi
0054494E  33c9                             xor    ecx,ecx
00544950  57                               push   edi
00544951  85c0                             test   eax,eax
00544953  7443                             je     0x544998
00544955  8b5204                           mov    edx,DWORD PTR [edx+0x4]
00544958  8bf2                             mov    esi,edx
0054495A  8d9b00000000                     lea    ebx,[ebx+0x0]
00544960  8b3e                             mov    edi,DWORD PTR [esi]
00544962  668b9ff6000000                   mov    bx,WORD PTR [edi+0xf6]
00544969  663b5d08                         cmp    bx,WORD PTR [ebp+0x8]
0054496D  750e                             jne    0x54497d
0054496F  660fbe5d0c                       movsx  bx,BYTE PTR [ebp+0xc]
00544974  66399ff4000000                   cmp    WORD PTR [edi+0xf4],bx
0054497B  740f                             je     0x54498c
0054497D  41                               inc    ecx
0054497E  83c604                           add    esi,0x4
00544981  3bc8                             cmp    ecx,eax
00544983  72db                             jb     0x544960
00544985  5f                               pop    edi
00544986  5e                               pop    esi
00544987  5b                               pop    ebx
00544988  5d                               pop    ebp
00544989  c20c00                           ret    0xc
0054498C  8b048a                           mov    eax,DWORD PTR [edx+ecx*4]
0054498F  8a4d10                           mov    cl,BYTE PTR [ebp+0x10]
00544992  50                               push   eax
00544993  e898f1ffff                       call   0x543b30
00544998  5f                               pop    edi
00544999  5e                               pop    esi
0054499A  5b                               pop    ebx
0054499B  5d                               pop    ebp
0054499C  c20c00                           ret    0xc

; point_native_setter 0x4a9460..0x4a94c0
004A9460  55                               push   ebp
004A9461  8bec                             mov    ebp,esp
004A9463  51                               push   ecx
004A9464  b901000000                       mov    ecx,0x1
004A9469  840dec79fb00                     test   BYTE PTR ds:0xfb79ec,cl
004A946F  7534                             jne    0x4a94a5
004A9471  090dec79fb00                     or     DWORD PTR ds:0xfb79ec,ecx
004A9477  33c0                             xor    eax,eax
004A9479  6870d2bc00                       push   0xbcd270
004A947E  c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
004A9488  a3f479fb00                       mov    ds:0xfb79f4,eax
004A948D  a3f879fb00                       mov    ds:0xfb79f8,eax
004A9492  a3fc79fb00                       mov    ds:0xfb79fc,eax
004A9497  890d047afb00                     mov    DWORD PTR ds:0xfb7a04,ecx
004A949D  e8788e3e00                       call   0x89231a
004A94A2  83c404                           add    esp,0x4
004A94A5  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
004A94A8  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
004A94AB  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
004A94AE  50                               push   eax
004A94AF  51                               push   ecx
004A94B0  52                               push   edx
004A94B1  baf079fb00                       mov    edx,0xfb79f0
004A94B6  e885b40900                       call   0x544940
004A94BB  59                               pop    ecx
004A94BC  5d                               pop    ebp
004A94BD  c20c00                           ret    0xc

; point_status 0x543b30..0x54401f
00543B30  55                               push   ebp
00543B31  8bec                             mov    ebp,esp
00543B33  83e4f8                           and    esp,0xfffffff8
00543B36  6aff                             push   0xffffffff
00543B38  68ac979200                       push   0x9297ac
00543B3D  64a100000000                     mov    eax,fs:0x0
00543B43  50                               push   eax
00543B44  83ec38                           sub    esp,0x38
00543B47  a1201fd600                       mov    eax,ds:0xd61f20
00543B4C  33c4                             xor    eax,esp
00543B4E  89442430                         mov    DWORD PTR [esp+0x30],eax
00543B52  53                               push   ebx
00543B53  56                               push   esi
00543B54  57                               push   edi
00543B55  a1201fd600                       mov    eax,ds:0xd61f20
00543B5A  33c4                             xor    eax,esp
00543B5C  50                               push   eax
00543B5D  8d442448                         lea    eax,[esp+0x48]
00543B61  64a300000000                     mov    fs:0x0,eax
00543B67  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
00543B6A  0fb783f4000000                   movzx  eax,WORD PTR [ebx+0xf4]
00543B71  33ff                             xor    edi,edi
00543B73  884c2417                         mov    BYTE PTR [esp+0x17],cl
00543B77  888b05010000                     mov    BYTE PTR [ebx+0x105],cl
00543B7D  663bc7                           cmp    ax,di
00543B80  0f853d040000                     jne    0x543fc3
00543B86  8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
00543B8C  3bc7                             cmp    eax,edi
00543B8E  7432                             je     0x543bc2
00543B90  397824                           cmp    DWORD PTR [eax+0x24],edi
00543B93  8d7024                           lea    esi,[eax+0x24]
00543B96  7409                             je     0x543ba1
00543B98  e853aa2700                       call   0x7be5f0
00543B9D  8a4c2417                         mov    cl,BYTE PTR [esp+0x17]
00543BA1  8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
00543BA7  3bc7                             cmp    eax,edi
00543BA9  7417                             je     0x543bc2
00543BAB  8bf8                             mov    edi,eax
00543BAD  e8fe41f8ff                       call   0x4c7db0
00543BB2  8a4c2417                         mov    cl,BYTE PTR [esp+0x17]
00543BB6  c783f000000000000000             mov    DWORD PTR [ebx+0xf0],0x0
00543BC0  33ff                             xor    edi,edi
00543BC2  6a48                             push   0x48
00543BC4  80f901                           cmp    cl,0x1
00543BC7  0f8525020000                     jne    0x543df2
00543BCD  80bbf800000000                   cmp    BYTE PTR [ebx+0xf8],0x0
00543BD4  7566                             jne    0x543c3c
00543BD6  e88dd63400                       call   0x891268
00543BDB  8bf0                             mov    esi,eax
00543BDD  83c404                           add    esp,0x4
00543BE0  89742418                         mov    DWORD PTR [esp+0x18],esi
00543BE4  897c2450                         mov    DWORD PTR [esp+0x50],edi
00543BE8  3bf7                             cmp    esi,edi
00543BEA  0f84df000000                     je     0x543ccf
00543BF0  0fbf83f6000000                   movsx  eax,WORD PTR [ebx+0xf6]
00543BF7  0f57c0                           xorps  xmm0,xmm0
00543BFA  894604                           mov    DWORD PTR [esi+0x4],eax
00543BFD  c70608000000                     mov    DWORD PTR [esi],0x8
00543C03  c7460804000000                   mov    DWORD PTR [esi+0x8],0x4
00543C0A  c6460c01                         mov    BYTE PTR [esi+0xc],0x1
00543C0E  8b83a0000000                     mov    eax,DWORD PTR [ebx+0xa0]
00543C14  894610                           mov    DWORD PTR [esi+0x10],eax
00543C17  8b8ba4000000                     mov    ecx,DWORD PTR [ebx+0xa4]
00543C1D  f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
00543C23  8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
00543C27  f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
00543C2D  8b442420                         mov    eax,DWORD PTR [esp+0x20]
00543C31  894e14                           mov    DWORD PTR [esi+0x14],ecx
00543C34  89561c                           mov    DWORD PTR [esi+0x1c],edx
00543C37  894620                           mov    DWORD PTR [esi+0x20],eax
00543C3A  eb64                             jmp    0x543ca0
00543C3C  e827d63400                       call   0x891268
00543C41  8bf0                             mov    esi,eax
00543C43  83c404                           add    esp,0x4
00543C46  89742418                         mov    DWORD PTR [esp+0x18],esi
00543C4A  c744245001000000                 mov    DWORD PTR [esp+0x50],0x1
00543C52  3bf7                             cmp    esi,edi
00543C54  7479                             je     0x543ccf
00543C56  0fbf83f6000000                   movsx  eax,WORD PTR [ebx+0xf6]
00543C5D  0f57c0                           xorps  xmm0,xmm0
00543C60  894604                           mov    DWORD PTR [esi+0x4],eax
00543C63  c7060b000000                     mov    DWORD PTR [esi],0xb
00543C69  c7460802000000                   mov    DWORD PTR [esi+0x8],0x2
00543C70  c6460c01                         mov    BYTE PTR [esi+0xc],0x1
00543C74  8b8ba0000000                     mov    ecx,DWORD PTR [ebx+0xa0]
00543C7A  894e10                           mov    DWORD PTR [esi+0x10],ecx
00543C7D  8b93a4000000                     mov    edx,DWORD PTR [ebx+0xa4]
00543C83  f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
00543C89  8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
00543C8D  f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
00543C93  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00543C97  895614                           mov    DWORD PTR [esi+0x14],edx
00543C9A  89461c                           mov    DWORD PTR [esi+0x1c],eax
00543C9D  894e20                           mov    DWORD PTR [esi+0x20],ecx
00543CA0  8d4e24                           lea    ecx,[esi+0x24]
00543CA3  f30f114618                       movss  DWORD PTR [esi+0x18],xmm0
00543CA8  c7411407000000                   mov    DWORD PTR [ecx+0x14],0x7
00543CAF  57                               push   edi
00543CB0  33d2                             xor    edx,edx
00543CB2  897910                           mov    DWORD PTR [ecx+0x10],edi
00543CB5  68fcd1be00                       push   0xbed1fc
00543CBA  668911                           mov    WORD PTR [ecx],dx
00543CBD  e89ee4ebff                       call   0x402160
00543CC2  0f57c0                           xorps  xmm0,xmm0
00543CC5  897e40                           mov    DWORD PTR [esi+0x40],edi
00543CC8  f30f114644                       movss  DWORD PTR [esi+0x44],xmm0
00543CCD  eb02                             jmp    0x543cd1
00543CCF  33f6                             xor    esi,esi
00543CD1  c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
00543CD9  e8d262f4ff                       call   0x489fb0
00543CDE  8b00                             mov    eax,DWORD PTR [eax]
00543CE0  56                               push   esi
00543CE1  50                               push   eax
00543CE2  e8d9b80200                       call   0x56f5c0
00543CE7  80bbf800000000                   cmp    BYTE PTR [ebx+0xf8],0x0
00543CEE  bf10000000                       mov    edi,0x10
00543CF3  756f                             jne    0x543d64
00543CF5  68e8f7c000                       push   0xc0f7e8
00543CFA  8d47fa                           lea    eax,[edi-0x6]
00543CFD  8d4c2428                         lea    ecx,[esp+0x28]
00543D01  c744243c0f000000                 mov    DWORD PTR [esp+0x3c],0xf
00543D09  c744243800000000                 mov    DWORD PTR [esp+0x38],0x0
00543D11  c644242800                       mov    BYTE PTR [esp+0x28],0x0
00543D16  e8f575ecff                       call   0x40b310
00543D1B  c744245002000000                 mov    DWORD PTR [esp+0x50],0x2
00543D23  e8c876ecff                       call   0x40b3f0
00543D28  50                               push   eax
00543D29  8d4c2428                         lea    ecx,[esp+0x28]
00543D2D  e8ce6d2c00                       call   0x80ab00
00543D32  85c0                             test   eax,eax
00543D34  7409                             je     0x543d3f
00543D36  8b10                             mov    edx,DWORD PTR [eax]
00543D38  8bc8                             mov    ecx,eax
00543D3A  8b4214                           mov    eax,DWORD PTR [edx+0x14]
00543D3D  ffd0                             call   eax
00543D3F  c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
00543D47  397c2438                         cmp    DWORD PTR [esp+0x38],edi
00543D4B  720d                             jb     0x543d5a
00543D4D  8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
00543D51  51                               push   ecx
00543D52  e8b5d43400                       call   0x89120c
00543D57  83c404                           add    esp,0x4
00543D5A  e8419ff6ff                       call   0x4adca0
00543D5F  e86cf50000                       call   0x5532d0
00543D64  f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
00543D6B  be03000000                       mov    esi,0x3
00543D70  7525                             jne    0x543d97
00543D72  830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
00543D79  89742450                         mov    DWORD PTR [esp+0x50],esi
00543D7D  e8fefffaff                       call   0x4f3d80
00543D82  68e0d1bc00                       push   0xbcd1e0
00543D87  e88ee53400                       call   0x89231a
00543D8C  83c404                           add    esp,0x4
00543D8F  c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
00543D97  660fbe93f8000000                 movsx  dx,BYTE PTR [ebx+0xf8]
00543D9F  0fb7c2                           movzx  eax,dx
00543DA2  c1e010                           shl    eax,0x10
00543DA5  83c801                           or     eax,0x1
00543DA8  8d542418                         lea    edx,[esp+0x18]
00543DAC  b93075fb00                       mov    ecx,0xfb7530
00543DB1  89442418                         mov    DWORD PTR [esp+0x18],eax
00543DB5  e8063ffbff                       call   0x4f7cc0
00543DBA  397814                           cmp    DWORD PTR [eax+0x14],edi
00543DBD  7202                             jb     0x543dc1
00543DBF  8b00                             mov    eax,DWORD PTR [eax]
00543DC1  f605dcf6fd0001                   test   BYTE PTR ds:0xfdf6dc,0x1
00543DC8  89742424                         mov    DWORD PTR [esp+0x24],esi
00543DCC  c7442428bcd6c000                 mov    DWORD PTR [esp+0x28],0xc0d6bc
00543DD4  89442434                         mov    DWORD PTR [esp+0x34],eax
00543DD8  0f85b0010000                     jne    0x543f8e
00543DDE  830ddcf6fd0001                   or     DWORD PTR ds:0xfdf6dc,0x1
00543DE5  c744245004000000                 mov    DWORD PTR [esp+0x50],0x4
00543DED  e982010000                       jmp    0x543f74
00543DF2  80bbf800000000                   cmp    BYTE PTR [ebx+0xf8],0x0
00543DF9  7538                             jne    0x543e33
00543DFB  e868d43400                       call   0x891268
00543E00  8bf0                             mov    esi,eax
00543E02  83c404                           add    esp,0x4
00543E05  89742418                         mov    DWORD PTR [esp+0x18],esi
00543E09  c744245005000000                 mov    DWORD PTR [esp+0x50],0x5
00543E11  bf07000000                       mov    edi,0x7
00543E16  85f6                             test   esi,esi
00543E18  0f84b1000000                     je     0x543ecf
00543E1E  0fbf83f6000000                   movsx  eax,WORD PTR [ebx+0xf6]
00543E25  8d4801                           lea    ecx,[eax+0x1]
00543E28  c70608000000                     mov    DWORD PTR [esi],0x8
00543E2E  894e08                           mov    DWORD PTR [esi+0x8],ecx
00543E31  eb33                             jmp    0x543e66
00543E33  e830d43400                       call   0x891268
00543E38  8bf0                             mov    esi,eax
00543E3A  83c404                           add    esp,0x4
00543E3D  89742418                         mov    DWORD PTR [esp+0x18],esi
00543E41  c744245006000000                 mov    DWORD PTR [esp+0x50],0x6
00543E49  bf07000000                       mov    edi,0x7
00543E4E  85f6                             test   esi,esi
00543E50  747d                             je     0x543ecf
00543E52  0fbf83f6000000                   movsx  eax,WORD PTR [ebx+0xf6]
00543E59  c7060b000000                     mov    DWORD PTR [esi],0xb
00543E5F  c7460801000000                   mov    DWORD PTR [esi+0x8],0x1
00543E66  0f57c0                           xorps  xmm0,xmm0
00543E69  894604                           mov    DWORD PTR [esi+0x4],eax
00543E6C  c6460c01                         mov    BYTE PTR [esi+0xc],0x1
00543E70  8b8ba0000000                     mov    ecx,DWORD PTR [ebx+0xa0]
00543E76  894e10                           mov    DWORD PTR [esi+0x10],ecx
00543E79  8b93a4000000                     mov    edx,DWORD PTR [ebx+0xa4]
00543E7F  895614                           mov    DWORD PTR [esi+0x14],edx
00543E82  f30f114618                       movss  DWORD PTR [esi+0x18],xmm0
00543E87  f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
00543E8D  8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
00543E91  89461c                           mov    DWORD PTR [esi+0x1c],eax
00543E94  f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
00543E9A  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00543E9E  894e20                           mov    DWORD PTR [esi+0x20],ecx
00543EA1  8d4e24                           lea    ecx,[esi+0x24]
00543EA4  33d2                             xor    edx,edx
00543EA6  897914                           mov    DWORD PTR [ecx+0x14],edi
00543EA9  52                               push   edx
00543EAA  c7411000000000                   mov    DWORD PTR [ecx+0x10],0x0
00543EB1  68fcd1be00                       push   0xbed1fc
00543EB6  668911                           mov    WORD PTR [ecx],dx
00543EB9  e8a2e2ebff                       call   0x402160
00543EBE  0f57c0                           xorps  xmm0,xmm0
00543EC1  c7464000000000                   mov    DWORD PTR [esi+0x40],0x0
00543EC8  f30f114644                       movss  DWORD PTR [esi+0x44],xmm0
00543ECD  eb02                             jmp    0x543ed1
00543ECF  33f6                             xor    esi,esi
00543ED1  c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
00543ED9  e8d260f4ff                       call   0x489fb0
00543EDE  8b00                             mov    eax,DWORD PTR [eax]
00543EE0  56                               push   esi
00543EE1  50                               push   eax
00543EE2  e8d9b60200                       call   0x56f5c0
00543EE7  f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
00543EEE  7525                             jne    0x543f15
00543EF0  830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
00543EF7  897c2450                         mov    DWORD PTR [esp+0x50],edi
00543EFB  e880fefaff                       call   0x4f3d80
00543F00  68e0d1bc00                       push   0xbcd1e0
00543F05  e810e43400                       call   0x89231a
00543F0A  83c404                           add    esp,0x4
00543F0D  c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
00543F15  660fbe8bf8000000                 movsx  cx,BYTE PTR [ebx+0xf8]
00543F1D  660fbe442417                     movsx  ax,BYTE PTR [esp+0x17]
00543F23  0fb7d1                           movzx  edx,cx
00543F26  0fb7c8                           movzx  ecx,ax
00543F29  c1e210                           shl    edx,0x10
00543F2C  0bd1                             or     edx,ecx
00543F2E  89542418                         mov    DWORD PTR [esp+0x18],edx
00543F32  8d542418                         lea    edx,[esp+0x18]
00543F36  b93075fb00                       mov    ecx,0xfb7530
00543F3B  e8803dfbff                       call   0x4f7cc0
00543F40  83781410                         cmp    DWORD PTR [eax+0x14],0x10
00543F44  7202                             jb     0x543f48
00543F46  8b00                             mov    eax,DWORD PTR [eax]
00543F48  f605dcf6fd0001                   test   BYTE PTR ds:0xfdf6dc,0x1
00543F4F  c744242403000000                 mov    DWORD PTR [esp+0x24],0x3
00543F57  c7442428bcd6c000                 mov    DWORD PTR [esp+0x28],0xc0d6bc
00543F5F  89442434                         mov    DWORD PTR [esp+0x34],eax
00543F63  7529                             jne    0x543f8e
00543F65  830ddcf6fd0001                   or     DWORD PTR ds:0xfdf6dc,0x1
00543F6C  c744245008000000                 mov    DWORD PTR [esp+0x50],0x8
00543F74  e8a7c80000                       call   0x550820
00543F79  68b0e6bc00                       push   0xbce6b0
00543F7E  e897e33400                       call   0x89231a
00543F83  83c404                           add    esp,0x4
00543F86  c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
00543F8E  d983b4000000                     fld    DWORD PTR [ebx+0xb4]
00543F94  8b13                             mov    edx,DWORD PTR [ebx]
00543F96  8b424c                           mov    eax,DWORD PTR [edx+0x4c]
00543F99  83ec08                           sub    esp,0x8
00543F9C  d95c2404                         fstp   DWORD PTR [esp+0x4]
00543FA0  8bcb                             mov    ecx,ebx
00543FA2  d9ee                             fldz
00543FA4  d91c24                           fstp   DWORD PTR [esp]
00543FA7  ffd0                             call   eax
00543FA9  6a00                             push   0x0
00543FAB  8bf0                             mov    esi,eax
00543FAD  8d542430                         lea    edx,[esp+0x30]
00543FB1  b980f6fd00                       mov    ecx,0xfdf680
00543FB6  e8d5df0000                       call   0x551f90
00543FBB  8983f0000000                     mov    DWORD PTR [ebx+0xf0],eax
00543FC1  eb3c                             jmp    0x543fff
00543FC3  6683f804                         cmp    ax,0x4
00543FC7  7536                             jne    0x543fff
00543FC9  84c9                             test   cl,cl
00543FCB  7532                             jne    0x543fff
00543FCD  8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
00543FD3  3bc7                             cmp    eax,edi
00543FD5  7428                             je     0x543fff
00543FD7  397824                           cmp    DWORD PTR [eax+0x24],edi
00543FDA  8d7024                           lea    esi,[eax+0x24]
00543FDD  7405                             je     0x543fe4
00543FDF  e80ca62700                       call   0x7be5f0
00543FE4  8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
00543FEA  3bc7                             cmp    eax,edi
00543FEC  7411                             je     0x543fff
00543FEE  8bf8                             mov    edi,eax
00543FF0  e8bb3df8ff                       call   0x4c7db0
00543FF5  c783f000000000000000             mov    DWORD PTR [ebx+0xf0],0x0
00543FFF  8b4c2448                         mov    ecx,DWORD PTR [esp+0x48]
00544003  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0054400A  59                               pop    ecx
0054400B  5f                               pop    edi
0054400C  5e                               pop    esi
0054400D  5b                               pop    ebx
0054400E  8b4c2430                         mov    ecx,DWORD PTR [esp+0x30]
00544012  33cc                             xor    ecx,esp
00544014  e8e8cf3400                       call   0x891001
00544019  8be5                             mov    esp,ebp
0054401B  5d                               pop    ebp
0054401C  c20400                           ret    0x4

; point_candidate 0x544730..0x5447ef
00544730  55                               push   ebp
00544731  8bec                             mov    ebp,esp
00544733  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
00544736  83ec08                           sub    esp,0x8
00544739  80b90501000000                   cmp    BYTE PTR [ecx+0x105],0x0
00544740  750e                             jne    0x544750
00544742  c70200000000                     mov    DWORD PTR [edx],0x0
00544748  33c0                             xor    eax,eax
0054474A  8be5                             mov    esp,ebp
0054474C  5d                               pop    ebp
0054474D  c20c00                           ret    0xc
00544750  d900                             fld    DWORD PTR [eax]
00544752  c70201000000                     mov    DWORD PTR [edx],0x1
00544758  d8a1a0000000                     fsub   DWORD PTR [ecx+0xa0]
0054475E  d95df8                           fstp   DWORD PTR [ebp-0x8]
00544761  d94004                           fld    DWORD PTR [eax+0x4]
00544764  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
00544767  d8a1a4000000                     fsub   DWORD PTR [ecx+0xa4]
0054476D  d95dfc                           fstp   DWORD PTR [ebp-0x4]
00544770  d945f8                           fld    DWORD PTR [ebp-0x8]
00544773  d945fc                           fld    DWORD PTR [ebp-0x4]
00544776  dcc8                             fmul   st(0),st
00544778  d9c1                             fld    st(1)
0054477A  deca                             fmulp  st(2),st
0054477C  dec1                             faddp  st(1),st
0054477E  d95d08                           fstp   DWORD PTR [ebp+0x8]
00544781  d94508                           fld    DWORD PTR [ebp+0x8]
00544784  d910                             fst    DWORD PTR [eax]
00544786  d981fc000000                     fld    DWORD PTR [ecx+0xfc]
0054478C  dcc8                             fmul   st(0),st
0054478E  dff1                             fcomip st,st(1)
00544790  ddd8                             fstp   st(0)
00544792  7604                             jbe    0x544798
00544794  b001                             mov    al,0x1
00544796  eb02                             jmp    0x54479a
00544798  32c0                             xor    al,al
0054479A  83b90001000000                   cmp    DWORD PTR [ecx+0x100],0x0
005447A1  752b                             jne    0x5447ce
005447A3  837d1000                         cmp    DWORD PTR [ebp+0x10],0x0
005447A7  7437                             je     0x5447e0
005447A9  84c0                             test   al,al
005447AB  7433                             je     0x5447e0
005447AD  80b90401000000                   cmp    BYTE PTR [ecx+0x104],0x0
005447B4  7406                             je     0x5447bc
005447B6  c70200000000                     mov    DWORD PTR [edx],0x0
005447BC  c6810401000001                   mov    BYTE PTR [ecx+0x104],0x1
005447C3  b801000000                       mov    eax,0x1
005447C8  8be5                             mov    esp,ebp
005447CA  5d                               pop    ebp
005447CB  c20c00                           ret    0xc
005447CE  84c0                             test   al,al
005447D0  75db                             jne    0x5447ad
005447D2  388104010000                     cmp    BYTE PTR [ecx+0x104],al
005447D8  7506                             jne    0x5447e0
005447DA  c70200000000                     mov    DWORD PTR [edx],0x0
005447E0  c6810401000000                   mov    BYTE PTR [ecx+0x104],0x0
005447E7  33c0                             xor    eax,eax
005447E9  8be5                             mov    esp,ebp
005447EB  5d                               pop    ebp
005447EC  c20c00                           ret    0xc

; point_nearest_dispatch 0x544a00..0x544b60
00544A00  55                               push   ebp
00544A01  8bec                             mov    ebp,esp
00544A03  83e4f8                           and    esp,0xfffffff8
00544A06  6aff                             push   0xffffffff
00544A08  68be059400                       push   0x9405be
00544A0D  64a100000000                     mov    eax,fs:0x0
00544A13  50                               push   eax
00544A14  83ec18                           sub    esp,0x18
00544A17  53                               push   ebx
00544A18  56                               push   esi
00544A19  57                               push   edi
00544A1A  a1201fd600                       mov    eax,ds:0xd61f20
00544A1F  33c4                             xor    eax,esp
00544A21  50                               push   eax
00544A22  8d442428                         lea    eax,[esp+0x28]
00544A26  64a300000000                     mov    fs:0x0,eax
00544A2C  8bf1                             mov    esi,ecx
00544A2E  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
00544A34  8b01                             mov    eax,DWORD PTR [ecx]
00544A36  8b5020                           mov    edx,DWORD PTR [eax+0x20]
00544A39  ffd2                             call   edx
00544A3B  33db                             xor    ebx,ebx
00544A3D  3bc3                             cmp    eax,ebx
00544A3F  0f8404010000                     je     0x544b49
00544A45  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
00544A48  2b4e04                           sub    ecx,DWORD PTR [esi+0x4]
00544A4B  f30f1005605ec500                 movss  xmm0,DWORD PTR ds:0xc55e60
00544A53  c1f902                           sar    ecx,0x2
00544A56  f30f11442418                     movss  DWORD PTR [esp+0x18],xmm0
00544A5C  895c241c                         mov    DWORD PTR [esp+0x1c],ebx
00544A60  85c9                             test   ecx,ecx
00544A62  0f84e1000000                     je     0x544b49
00544A68  0f57c0                           xorps  xmm0,xmm0
00544A6B  05a0000000                       add    eax,0xa0
00544A70  89442420                         mov    DWORD PTR [esp+0x20],eax
00544A74  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
00544A77  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00544A7A  52                               push   edx
00544A7B  8b1498                           mov    edx,DWORD PTR [eax+ebx*4]
00544A7E  8b442424                         mov    eax,DWORD PTR [esp+0x24]
00544A82  8d4c2414                         lea    ecx,[esp+0x14]
00544A86  8d3c9d00000000                   lea    edi,[ebx*4+0x0]
00544A8D  51                               push   ecx
00544A8E  52                               push   edx
00544A8F  8d542420                         lea    edx,[esp+0x20]
00544A93  c744242000000000                 mov    DWORD PTR [esp+0x20],0x0
00544A9B  f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
00544AA1  e88afcffff                       call   0x544730
00544AA6  837c241400                       cmp    DWORD PTR [esp+0x14],0x0
00544AAB  7428                             je     0x544ad5
00544AAD  85c0                             test   eax,eax
00544AAF  7424                             je     0x544ad5
00544AB1  d9442410                         fld    DWORD PTR [esp+0x10]
00544AB5  d9442418                         fld    DWORD PTR [esp+0x18]
00544AB9  dff1                             fcomip st,st(1)
00544ABB  ddd8                             fstp   st(0)
00544ABD  7616                             jbe    0x544ad5
00544ABF  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00544AC2  8b0c07                           mov    ecx,DWORD PTR [edi+eax*1]
00544AC5  f30f104c2410                     movss  xmm1,DWORD PTR [esp+0x10]
00544ACB  f30f114c2418                     movss  DWORD PTR [esp+0x18],xmm1
00544AD1  894c241c                         mov    DWORD PTR [esp+0x1c],ecx
00544AD5  8b5608                           mov    edx,DWORD PTR [esi+0x8]
00544AD8  2b5604                           sub    edx,DWORD PTR [esi+0x4]
00544ADB  43                               inc    ebx
00544ADC  c1fa02                           sar    edx,0x2
00544ADF  3bda                             cmp    ebx,edx
00544AE1  7291                             jb     0x544a74
00544AE3  8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
00544AE7  85f6                             test   esi,esi
00544AE9  745e                             je     0x544b49
00544AEB  f6059043f90001                   test   BYTE PTR ds:0xf94390,0x1
00544AF2  7529                             jne    0x544b1d
00544AF4  830d9043f90001                   or     DWORD PTR ds:0xf94390,0x1
00544AFB  c744243000000000                 mov    DWORD PTR [esp+0x30],0x0
00544B03  e888caf9ff                       call   0x4e1590
00544B08  6880ccbc00                       push   0xbccc80
00544B0D  e808d83400                       call   0x89231a
00544B12  83c404                           add    esp,0x4
00544B15  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
00544B1D  803dc042f90000                   cmp    BYTE PTR ds:0xf942c0,0x0
00544B24  7523                             jne    0x544b49
00544B26  8b06                             mov    eax,DWORD PTR [esi]
00544B28  8b5064                           mov    edx,DWORD PTR [eax+0x64]
00544B2B  8bce                             mov    ecx,esi
00544B2D  ffd2                             call   edx
00544B2F  b801000000                       mov    eax,0x1
00544B34  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
00544B38  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00544B3F  59                               pop    ecx
00544B40  5f                               pop    edi
00544B41  5e                               pop    esi
00544B42  5b                               pop    ebx
00544B43  8be5                             mov    esp,ebp
00544B45  5d                               pop    ebp
00544B46  c20400                           ret    0x4
00544B49  33c0                             xor    eax,eax
00544B4B  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
00544B4F  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00544B56  59                               pop    ecx
00544B57  5f                               pop    edi
00544B58  5e                               pop    esi
00544B59  5b                               pop    ebx
00544B5A  8be5                             mov    esp,ebp
00544B5C  5d                               pop    ebp
00544B5D  c20400                           ret    0x4

; report_003f 0x4a39a0..0x4a39ec
004A39A0  55                               push   ebp
004A39A1  8bec                             mov    ebp,esp
004A39A3  83ec08                           sub    esp,0x8
004A39A6  833d98a7fb0000                   cmp    DWORD PTR ds:0xfba798,0x0
004A39AD  668b4d08                         mov    cx,WORD PTR [ebp+0x8]
004A39B1  668b550c                         mov    dx,WORD PTR [ebp+0xc]
004A39B5  b83f000000                       mov    eax,0x3f
004A39BA  668945f8                         mov    WORD PTR [ebp-0x8],ax
004A39BE  b801000000                       mov    eax,0x1
004A39C3  66894dfa                         mov    WORD PTR [ebp-0x6],cx
004A39C7  668955fc                         mov    WORD PTR [ebp-0x4],dx
004A39CB  668945fe                         mov    WORD PTR [ebp-0x2],ax
004A39CF  7515                             jne    0x4a39e6
004A39D1  8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
004A39D7  8b11                             mov    edx,DWORD PTR [ecx]
004A39D9  8b5210                           mov    edx,DWORD PTR [edx+0x10]
004A39DC  6a08                             push   0x8
004A39DE  8d45f8                           lea    eax,[ebp-0x8]
004A39E1  50                               push   eax
004A39E2  6a00                             push   0x0
004A39E4  ffd2                             call   edx
004A39E6  8be5                             mov    esp,ebp
004A39E8  5d                               pop    ebp
004A39E9  c20800                           ret    0x8

; q_start_and_skip 0x561760..0x561db0
00561760  55                               push   ebp
00561761  8bec                             mov    ebp,esp
00561763  83e4f8                           and    esp,0xfffffff8
00561766  6aff                             push   0xffffffff
00561768  682cfd9300                       push   0x93fd2c
0056176D  64a100000000                     mov    eax,fs:0x0
00561773  50                               push   eax
00561774  83ec50                           sub    esp,0x50
00561777  a1201fd600                       mov    eax,ds:0xd61f20
0056177C  33c4                             xor    eax,esp
0056177E  89442448                         mov    DWORD PTR [esp+0x48],eax
00561782  53                               push   ebx
00561783  56                               push   esi
00561784  57                               push   edi
00561785  a1201fd600                       mov    eax,ds:0xd61f20
0056178A  33c4                             xor    eax,esp
0056178C  50                               push   eax
0056178D  8d442460                         lea    eax,[esp+0x60]
00561791  64a300000000                     mov    fs:0x0,eax
00561797  833d18abfb0000                   cmp    DWORD PTR ds:0xfbab18,0x0
0056179E  8bd9                             mov    ebx,ecx
005617A0  7420                             je     0x5617c2
005617A2  0f57c0                           xorps  xmm0,xmm0
005617A5  f30f110524abfb00                 movss  DWORD PTR ds:0xfbab24,xmm0
005617AD  e8aed8eaff                       call   0x40f060
005617B2  f30f10057059c500                 movss  xmm0,DWORD PTR ds:0xc55970
005617BA  f30f1180ac000000                 movss  DWORD PTR [eax+0xac],xmm0
005617C2  837b2800                         cmp    DWORD PTR [ebx+0x28],0x0
005617C6  c6838900000000                   mov    BYTE PTR [ebx+0x89],0x0
005617CD  741a                             je     0x5617e9
005617CF  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
005617D2  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
005617D5  50                               push   eax
005617D6  51                               push   ecx
005617D7  68ac06c100                       push   0xc106ac
005617DC  e87fc31800                       call   0x6edb60
005617E1  83c40c                           add    esp,0xc
005617E4  e99d050000                       jmp    0x561d86
005617E9  f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
005617F0  be01000000                       mov    esi,0x1
005617F5  7529                             jne    0x561820
005617F7  09352888fb00                     or     DWORD PTR ds:0xfb8828,esi
005617FD  c744246800000000                 mov    DWORD PTR [esp+0x68],0x0
00561805  e846e0feff                       call   0x54f850
0056180A  6880d5bc00                       push   0xbcd580
0056180F  e8060b3300                       call   0x89231a
00561814  83c404                           add    esp,0x4
00561817  83cfff                           or     edi,0xffffffff
0056181A  897c2468                         mov    DWORD PTR [esp+0x68],edi
0056181E  eb03                             jmp    0x561823
00561820  83cfff                           or     edi,0xffffffff
00561823  803df192fb0000                   cmp    BYTE PTR ds:0xfb92f1,0x0
0056182A  0f84ac000000                     je     0x5618dc
00561830  837d0800                         cmp    DWORD PTR [ebp+0x8],0x0
00561834  0f85a2000000                     jne    0x5618dc
0056183A  e86133eaff                       call   0x404ba0
0056183F  83b84c5f000009                   cmp    DWORD PTR [eax+0x5f4c],0x9
00561846  741c                             je     0x561864
00561848  e85333eaff                       call   0x404ba0
0056184D  83b84c5f000004                   cmp    DWORD PTR [eax+0x5f4c],0x4
00561854  740e                             je     0x561864
00561856  e84533eaff                       call   0x404ba0
0056185B  83b84c5f000019                   cmp    DWORD PTR [eax+0x5f4c],0x19
00561862  7578                             jne    0x5618dc
00561864  8b7378                           mov    esi,DWORD PTR [ebx+0x78]
00561867  8d550c                           lea    edx,[ebp+0xc]
0056186A  52                               push   edx
0056186B  8d4b74                           lea    ecx,[ebx+0x74]
0056186E  8d442414                         lea    eax,[esp+0x14]
00561872  e8494cedff                       call   0x4364c0
00561877  3930                             cmp    DWORD PTR [eax],esi
00561879  745c                             je     0x5618d7
0056187B  6a0f                             push   0xf
0056187D  e82e3d0200                       call   0x5855b0
00561882  8bf0                             mov    esi,eax
00561884  e8a73a0200                       call   0x585330
00561889  50                               push   eax
0056188A  8d4c2440                         lea    ecx,[esp+0x40]
0056188E  e8bd09eaff                       call   0x402250
00561893  8d44243c                         lea    eax,[esp+0x3c]
00561897  50                               push   eax
00561898  c744246c01000000                 mov    DWORD PTR [esp+0x6c],0x1
005618A0  e81be0eaff                       call   0x40f8c0
005618A5  8bf8                             mov    edi,eax
005618A7  e88452f7ff                       call   0x4d6b30
005618AC  8d4c243c                         lea    ecx,[esp+0x3c]
005618B0  c7442468ffffffff                 mov    DWORD PTR [esp+0x68],0xffffffff
005618B8  e8838bf9ff                       call   0x4fa440
005618BD  e8be2debff                       call   0x414680
005618C2  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
005618C5  51                               push   ecx
005618C6  6a00                             push   0x0
005618C8  e8d320f4ff                       call   0x4a39a0
005618CD  e8de070000                       call   0x5620b0
005618D2  e9af040000                       jmp    0x561d86
005618D7  be01000000                       mov    esi,0x1
005618DC  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
005618E3  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
005618E6  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
005618E9  895338                           mov    DWORD PTR [ebx+0x38],edx
005618EC  89433c                           mov    DWORD PTR [ebx+0x3c],eax
005618EF  897328                           mov    DWORD PTR [ebx+0x28],esi
005618F2  7524                             jne    0x561918
005618F4  0935d4adfa00                     or     DWORD PTR ds:0xfaadd4,esi
005618FA  c744246802000000                 mov    DWORD PTR [esp+0x68],0x2
00561902  e8795b0200                       call   0x587480
00561907  68c0ccbc00                       push   0xbcccc0
0056190C  e8090a3300                       call   0x89231a
00561911  83c404                           add    esp,0x4
00561914  897c2468                         mov    DWORD PTR [esp+0x68],edi
00561918  f605d0adfa0001                   test   BYTE PTR ds:0xfaadd0,0x1
0056191F  7524                             jne    0x561945
00561921  0935d0adfa00                     or     DWORD PTR ds:0xfaadd0,esi
00561927  c744246803000000                 mov    DWORD PTR [esp+0x68],0x3
0056192F  e85cc01e00                       call   0x74d990
00561934  6870ccbc00                       push   0xbccc70
00561939  e8dc093300                       call   0x89231a
0056193E  83c404                           add    esp,0x4
00561941  897c2468                         mov    DWORD PTR [esp+0x68],edi
00561945  f6059043f90001                   test   BYTE PTR ds:0xf94390,0x1
0056194C  8b0dbc5bf900                     mov    ecx,DWORD PTR ds:0xf95bbc
00561952  8b15c05bf900                     mov    edx,DWORD PTR ds:0xf95bc0
00561958  894c2414                         mov    DWORD PTR [esp+0x14],ecx
0056195C  f30f10442414                     movss  xmm0,DWORD PTR [esp+0x14]
00561962  89542418                         mov    DWORD PTR [esp+0x18],edx
00561966  f30f118384000000                 movss  DWORD PTR [ebx+0x84],xmm0
0056196E  7524                             jne    0x561994
00561970  09359043f900                     or     DWORD PTR ds:0xf94390,esi
00561976  c744246804000000                 mov    DWORD PTR [esp+0x68],0x4
0056197E  e80dfcf7ff                       call   0x4e1590
00561983  6880ccbc00                       push   0xbccc80
00561988  e88d093300                       call   0x89231a
0056198D  83c404                           add    esp,0x4
00561990  897c2468                         mov    DWORD PTR [esp+0x68],edi
00561994  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0056199B  a0a442f900                       mov    al,ds:0xf942a4
005619A0  888388000000                     mov    BYTE PTR [ebx+0x88],al
005619A6  7524                             jne    0x5619cc
005619A8  0935d4adfa00                     or     DWORD PTR ds:0xfaadd4,esi
005619AE  c744246805000000                 mov    DWORD PTR [esp+0x68],0x5
005619B6  e8c55a0200                       call   0x587480
005619BB  68c0ccbc00                       push   0xbcccc0
005619C0  e855093300                       call   0x89231a
005619C5  83c404                           add    esp,0x4
005619C8  897c2468                         mov    DWORD PTR [esp+0x68],edi
005619CC  6858430f00                       push   0xf4358
005619D1  e8fa900200                       call   0x58aad0
005619D6  83c404                           add    esp,0x4
005619D9  f6059043f90001                   test   BYTE PTR ds:0xf94390,0x1
005619E0  7524                             jne    0x561a06
005619E2  09359043f900                     or     DWORD PTR ds:0xf94390,esi
005619E8  c744246806000000                 mov    DWORD PTR [esp+0x68],0x6
005619F0  e89bfbf7ff                       call   0x4e1590
005619F5  6880ccbc00                       push   0xbccc80
005619FA  e81b093300                       call   0x89231a
005619FF  83c404                           add    esp,0x4
00561A02  897c2468                         mov    DWORD PTR [esp+0x68],edi
00561A06  6a00                             push   0x0
00561A08  687523bf00                       push   0xbf2375
00561A0D  8d4b44                           lea    ecx,[ebx+0x44]
00561A10  c605a442f90001                   mov    BYTE PTR ds:0xf942a4,0x1
00561A17  e85410eaff                       call   0x402a70
00561A1C  8b730c                           mov    esi,DWORD PTR [ebx+0xc]
00561A1F  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00561A22  80783100                         cmp    BYTE PTR [eax+0x31],0x0
00561A26  8bd6                             mov    edx,esi
00561A28  752c                             jne    0x561a56
00561A2A  8d9b00000000                     lea    ebx,[ebx+0x0]
00561A30  8b480c                           mov    ecx,DWORD PTR [eax+0xc]
00561A33  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
00561A36  3bf9                             cmp    edi,ecx
00561A38  7f0a                             jg     0x561a44
00561A3A  7c0d                             jl     0x561a49
00561A3C  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
00561A3F  394810                           cmp    DWORD PTR [eax+0x10],ecx
00561A42  7d05                             jge    0x561a49
00561A44  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00561A47  eb04                             jmp    0x561a4d
00561A49  8bd0                             mov    edx,eax
00561A4B  8b00                             mov    eax,DWORD PTR [eax]
00561A4D  80783100                         cmp    BYTE PTR [eax+0x31],0x0
00561A51  74dd                             je     0x561a30
00561A53  83cfff                           or     edi,0xffffffff
00561A56  8954241c                         mov    DWORD PTR [esp+0x1c],edx
00561A5A  3bd6                             cmp    edx,esi
00561A5C  741a                             je     0x561a78
00561A5E  8b420c                           mov    eax,DWORD PTR [edx+0xc]
00561A61  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
00561A64  3bc1                             cmp    eax,ecx
00561A66  7f10                             jg     0x561a78
00561A68  7c08                             jl     0x561a72
00561A6A  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
00561A6D  3b4210                           cmp    eax,DWORD PTR [edx+0x10]
00561A70  7c06                             jl     0x561a78
00561A72  8d44241c                         lea    eax,[esp+0x1c]
00561A76  eb08                             jmp    0x561a80
00561A78  89742410                         mov    DWORD PTR [esp+0x10],esi
00561A7C  8d442410                         lea    eax,[esp+0x10]
00561A80  8b30                             mov    esi,DWORD PTR [eax]
00561A82  3b730c                           cmp    esi,DWORD PTR [ebx+0xc]
00561A85  0f84f4020000                     je     0x561d7f
00561A8B  6a10                             push   0x10
00561A8D  68d006c100                       push   0xc106d0
00561A92  8d4c2428                         lea    ecx,[esp+0x28]
00561A96  c744243c0f000000                 mov    DWORD PTR [esp+0x3c],0xf
00561A9E  c744243800000000                 mov    DWORD PTR [esp+0x38],0x0
00561AA6  c644242800                       mov    BYTE PTR [esp+0x28],0x0
00561AAB  e8c00feaff                       call   0x402a70
00561AB0  8d4614                           lea    eax,[esi+0x14]
00561AB3  57                               push   edi
00561AB4  33f6                             xor    esi,esi
00561AB6  56                               push   esi
00561AB7  50                               push   eax
00561AB8  8d4c242c                         lea    ecx,[esp+0x2c]
00561ABC  c744247407000000                 mov    DWORD PTR [esp+0x74],0x7
00561AC4  e80704eaff                       call   0x401ed0
00561AC9  6a04                             push   0x4
00561ACB  68e406c100                       push   0xc106e4
00561AD0  8d4c2428                         lea    ecx,[esp+0x28]
00561AD4  e8e704eaff                       call   0x401fc0
00561AD9  837c243410                       cmp    DWORD PTR [esp+0x34],0x10
00561ADE  8b442420                         mov    eax,DWORD PTR [esp+0x20]
00561AE2  7304                             jae    0x561ae8
00561AE4  8d442420                         lea    eax,[esp+0x20]
00561AE8  50                               push   eax
00561AE9  51                               push   ecx
00561AEA  e8b1aaffff                       call   0x55c5a0
00561AEF  83c404                           add    esp,0x4
00561AF2  50                               push   eax
00561AF3  e8a8bbffff                       call   0x55d6a0
00561AF8  6a1c                             push   0x1c
00561AFA  894370                           mov    DWORD PTR [ebx+0x70],eax
00561AFD  e866f73200                       call   0x891268
00561B02  83c404                           add    esp,0x4
00561B05  3bc6                             cmp    eax,esi
00561B07  7411                             je     0x561b1a
00561B09  8930                             mov    DWORD PTR [eax],esi
00561B0B  c6400801                         mov    BYTE PTR [eax+0x8],0x1
00561B0F  89700c                           mov    DWORD PTR [eax+0xc],esi
00561B12  897010                           mov    DWORD PTR [eax+0x10],esi
00561B15  897014                           mov    DWORD PTR [eax+0x14],esi
00561B18  eb02                             jmp    0x561b1c
00561B1A  33c0                             xor    eax,eax
00561B1C  50                               push   eax
00561B1D  8d4c2418                         lea    ecx,[esp+0x18]
00561B21  51                               push   ecx
00561B22  8974241c                         mov    DWORD PTR [esp+0x1c],esi
00561B26  89742420                         mov    DWORD PTR [esp+0x20],esi
00561B2A  e8a1a5f1ff                       call   0x47c0d0
00561B2F  c644246808                       mov    BYTE PTR [esp+0x68],0x8
00561B34  8b742414                         mov    esi,DWORD PTR [esp+0x14]
00561B38  c7460403000000                   mov    DWORD PTR [esi+0x4],0x3
00561B3F  c6460801                         mov    BYTE PTR [esi+0x8],0x1
00561B43  8b4b70                           mov    ecx,DWORD PTR [ebx+0x70]
00561B46  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
00561B49  8b00                             mov    eax,DWORD PTR [eax]
00561B4B  8944241c                         mov    DWORD PTR [esp+0x1c],eax
00561B4F  3b4104                           cmp    eax,DWORD PTR [ecx+0x4]
00561B52  7436                             je     0x561b8a
00561B54  8d7e0c                           lea    edi,[esi+0xc]
00561B57  eb07                             jmp    0x561b60
00561B59  8da42400000000                   lea    esp,[esp+0x0]
00561B60  8b5010                           mov    edx,DWORD PTR [eax+0x10]
00561B63  0fb702                           movzx  eax,WORD PTR [edx]
00561B66  89442410                         mov    DWORD PTR [esp+0x10],eax
00561B6A  8d442410                         lea    eax,[esp+0x10]
00561B6E  e80d6bf4ff                       call   0x4a8680
00561B73  8d44241c                         lea    eax,[esp+0x1c]
00561B77  e824cbf3ff                       call   0x49e6a0
00561B7C  8b4370                           mov    eax,DWORD PTR [ebx+0x70]
00561B7F  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
00561B82  8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
00561B86  3bc1                             cmp    eax,ecx
00561B88  75d6                             jne    0x561b60
00561B8A  8b542418                         mov    edx,DWORD PTR [esp+0x18]
00561B8E  83ec08                           sub    esp,0x8
00561B91  8bfc                             mov    edi,esp
00561B93  89642418                         mov    DWORD PTR [esp+0x18],esp
00561B97  c70700000000                     mov    DWORD PTR [edi],0x0
00561B9D  c7470400000000                   mov    DWORD PTR [edi+0x4],0x0
00561BA4  85d2                             test   edx,edx
00561BA6  7416                             je     0x561bbe
00561BA8  e8a3a6f1ff                       call   0x47c250
00561BAD  84c0                             test   al,al
00561BAF  740d                             je     0x561bbe
00561BB1  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00561BB5  51                               push   ecx
00561BB6  56                               push   esi
00561BB7  8bf7                             mov    esi,edi
00561BB9  e802162400                       call   0x7a31c0
00561BBE  c644247009                       mov    BYTE PTR [esp+0x70],0x9
00561BC3  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00561BCA  7523                             jne    0x561bef
00561BCC  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00561BD3  c64424700a                       mov    BYTE PTR [esp+0x70],0xa
00561BD8  e863b32300                       call   0x79cf40
00561BDD  6880dbbc00                       push   0xbcdb80
00561BE2  e833073300                       call   0x89231a
00561BE7  83c404                           add    esp,0x4
00561BEA  c644247009                       mov    BYTE PTR [esp+0x70],0x9
00561BEF  b9900efc00                       mov    ecx,0xfc0e90
00561BF4  c644247008                       mov    BYTE PTR [esp+0x70],0x8
00561BF9  e8e2c02300                       call   0x79dce0
00561BFE  8bf0                             mov    esi,eax
00561C00  6aff                             push   0xffffffff
00561C02  56                               push   esi
00561C03  ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
00561C09  56                               push   esi
00561C0A  ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
00561C10  f6057017fe0001                   test   BYTE PTR ds:0xfe1770,0x1
00561C17  7523                             jne    0x561c3c
00561C19  830d7017fe0001                   or     DWORD PTR ds:0xfe1770,0x1
00561C20  c64424680b                       mov    BYTE PTR [esp+0x68],0xb
00561C25  e876612500                       call   0x7b7da0
00561C2A  6890e7bc00                       push   0xbce790
00561C2F  e8e6063300                       call   0x89231a
00561C34  83c404                           add    esp,0x4
00561C37  c644246808                       mov    BYTE PTR [esp+0x68],0x8
00561C3C  8b3d3c17fe00                     mov    edi,DWORD PTR ds:0xfe173c
00561C42  8b4704                           mov    eax,DWORD PTR [edi+0x4]
00561C45  8b30                             mov    esi,DWORD PTR [eax]
00561C47  3bf0                             cmp    esi,eax
00561C49  741c                             je     0x561c67
00561C4B  eb03                             jmp    0x561c50
00561C4D  8d4900                           lea    ecx,[ecx+0x0]
00561C50  8b4e24                           mov    ecx,DWORD PTR [esi+0x24]
00561C53  83790400                         cmp    DWORD PTR [ecx+0x4],0x0
00561C57  7507                             jne    0x561c60
00561C59  8b11                             mov    edx,DWORD PTR [ecx]
00561C5B  8b4204                           mov    eax,DWORD PTR [edx+0x4]
00561C5E  ffd0                             call   eax
00561C60  8b36                             mov    esi,DWORD PTR [esi]
00561C62  3b7704                           cmp    esi,DWORD PTR [edi+0x4]
00561C65  75e9                             jne    0x561c50
00561C67  8b442420                         mov    eax,DWORD PTR [esp+0x20]
00561C6B  bf10000000                       mov    edi,0x10
00561C70  397c2434                         cmp    DWORD PTR [esp+0x34],edi
00561C74  7304                             jae    0x561c7a
00561C76  8d442420                         lea    eax,[esp+0x20]
00561C7A  8b0b                             mov    ecx,DWORD PTR [ebx]
00561C7C  50                               push   eax
00561C7D  e8ce2d1900                       call   0x6f4a50
00561C82  33db                             xor    ebx,ebx
00561C84  f605ec79fb0001                   test   BYTE PTR ds:0xfb79ec,0x1
00561C8B  be01000000                       mov    esi,0x1
00561C90  7535                             jne    0x561cc7
00561C92  0935ec79fb00                     or     DWORD PTR ds:0xfb79ec,esi
00561C98  6870d2bc00                       push   0xbcd270
00561C9D  c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
00561CA7  891df479fb00                     mov    DWORD PTR ds:0xfb79f4,ebx
00561CAD  891df879fb00                     mov    DWORD PTR ds:0xfb79f8,ebx
00561CB3  891dfc79fb00                     mov    DWORD PTR ds:0xfb79fc,ebx
00561CB9  8935047afb00                     mov    DWORD PTR ds:0xfb7a04,esi
00561CBF  e856063300                       call   0x89231a
00561CC4  83c404                           add    esp,0x4
00561CC7  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00561CCE  891d047afb00                     mov    DWORD PTR ds:0xfb7a04,ebx
00561CD4  7522                             jne    0x561cf8
00561CD6  0935600ffc00                     or     DWORD PTR ds:0xfc0f60,esi
00561CDC  c64424680c                       mov    BYTE PTR [esp+0x68],0xc
00561CE1  e85ab22300                       call   0x79cf40
00561CE6  6880dbbc00                       push   0xbcdb80
00561CEB  e82a063300                       call   0x89231a
00561CF0  83c404                           add    esp,0x4
00561CF3  c644246808                       mov    BYTE PTR [esp+0x68],0x8
00561CF8  6a02                             push   0x2
00561CFA  68900efc00                       push   0xfc0e90
00561CFF  e8bcbc2300                       call   0x79d9c0
00561D04  f605d894fd0001                   test   BYTE PTR ds:0xfd94d8,0x1
00561D0B  751d                             jne    0x561d2a
00561D0D  0935d894fd00                     or     DWORD PTR ds:0xfd94d8,esi
00561D13  c64424680d                       mov    BYTE PTR [esp+0x68],0xd
00561D18  e813372500                       call   0x7b5430
00561D1D  6860e6bc00                       push   0xbce660
00561D22  e8f3053300                       call   0x89231a
00561D27  83c404                           add    esp,0x4
00561D2A  c644246807                       mov    BYTE PTR [esp+0x68],0x7
00561D2F  8b742418                         mov    esi,DWORD PTR [esp+0x18]
00561D33  c705b094fd0002000000             mov    DWORD PTR ds:0xfd94b0,0x2
00561D3D  3bf3                             cmp    esi,ebx
00561D3F  7429                             je     0x561d6a
00561D41  8d4e04                           lea    ecx,[esi+0x4]
00561D44  83caff                           or     edx,0xffffffff
00561D47  f00fc111                         lock xadd DWORD PTR [ecx],edx
00561D4B  751d                             jne    0x561d6a
00561D4D  8b06                             mov    eax,DWORD PTR [esi]
00561D4F  8b10                             mov    edx,DWORD PTR [eax]
00561D51  8bce                             mov    ecx,esi
00561D53  ffd2                             call   edx
00561D55  8d4608                           lea    eax,[esi+0x8]
00561D58  83c9ff                           or     ecx,0xffffffff
00561D5B  f00fc108                         lock xadd DWORD PTR [eax],ecx
00561D5F  7509                             jne    0x561d6a
00561D61  8b16                             mov    edx,DWORD PTR [esi]
00561D63  8b4204                           mov    eax,DWORD PTR [edx+0x4]
00561D66  8bce                             mov    ecx,esi
00561D68  ffd0                             call   eax
00561D6A  397c2434                         cmp    DWORD PTR [esp+0x34],edi
00561D6E  7216                             jb     0x561d86
00561D70  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00561D74  51                               push   ecx
00561D75  e892f43200                       call   0x89120c
00561D7A  83c404                           add    esp,0x4
00561D7D  eb07                             jmp    0x561d86
00561D7F  8bcb                             mov    ecx,ebx
00561D81  e82a000000                       call   0x561db0
00561D86  8b4c2460                         mov    ecx,DWORD PTR [esp+0x60]
00561D8A  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00561D91  59                               pop    ecx
00561D92  5f                               pop    edi
00561D93  5e                               pop    esi
00561D94  5b                               pop    ebx
00561D95  8b4c2448                         mov    ecx,DWORD PTR [esp+0x48]
00561D99  33cc                             xor    ecx,esp
00561D9B  e861f23200                       call   0x891001
00561DA0  8be5                             mov    esp,ebp
00561DA2  5d                               pop    ebp
00561DA3  c20800                           ret    0x8
00561DA6  cc                               int3
00561DA7  cc                               int3
00561DA8  cc                               int3
00561DA9  cc                               int3
00561DAA  cc                               int3
00561DAB  cc                               int3
00561DAC  cc                               int3
00561DAD  cc                               int3
00561DAE  cc                               int3
00561DAF  cc                               int3

; q_end 0x561db0..0x5620aa
00561DB0  55                               push   ebp
00561DB1  8bec                             mov    ebp,esp
00561DB3  83e4f8                           and    esp,0xfffffff8
00561DB6  6aff                             push   0xffffffff
00561DB8  6864fc9300                       push   0x93fc64
00561DBD  64a100000000                     mov    eax,fs:0x0
00561DC3  50                               push   eax
00561DC4  83ec10                           sub    esp,0x10
00561DC7  53                               push   ebx
00561DC8  56                               push   esi
00561DC9  57                               push   edi
00561DCA  a1201fd600                       mov    eax,ds:0xd61f20
00561DCF  33c4                             xor    eax,esp
00561DD1  50                               push   eax
00561DD2  8d442420                         lea    eax,[esp+0x20]
00561DD6  64a300000000                     mov    fs:0x0,eax
00561DDC  8bf9                             mov    edi,ecx
00561DDE  33f6                             xor    esi,esi
00561DE0  80bf8900000000                   cmp    BYTE PTR [edi+0x89],0x0
00561DE7  0f8473010000                     je     0x561f60
00561DED  397728                           cmp    DWORD PTR [edi+0x28],esi
00561DF0  0f84aa000000                     je     0x561ea0
00561DF6  897728                           mov    DWORD PTR [edi+0x28],esi
00561DF9  e85224edff                       call   0x434250
00561DFE  bb01000000                       mov    ebx,0x1
00561E03  895814                           mov    DWORD PTR [eax+0x14],ebx
00561E06  841dd4f3fd00                     test   BYTE PTR ds:0xfdf3d4,bl
00561E0C  7525                             jne    0x561e33
00561E0E  091dd4f3fd00                     or     DWORD PTR ds:0xfdf3d4,ebx
00561E14  89742428                         mov    DWORD PTR [esp+0x28],esi
00561E18  e863251900                       call   0x6f4380
00561E1D  68d0e6bc00                       push   0xbce6d0
00561E22  e8f3043300                       call   0x89231a
00561E27  83c404                           add    esp,0x4
00561E2A  83ceff                           or     esi,0xffffffff
00561E2D  89742428                         mov    DWORD PTR [esp+0x28],esi
00561E31  eb03                             jmp    0x561e36
00561E33  83ceff                           or     esi,0xffffffff
00561E36  68ec06c100                       push   0xc106ec
00561E3B  6a00                             push   0x0
00561E3D  68c8f3fd00                       push   0xfdf3c8
00561E42  e859b2f4ff                       call   0x4ad0a0
00561E47  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
00561E4E  7520                             jne    0x561e70
00561E50  091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
00561E56  895c2428                         mov    DWORD PTR [esp+0x28],ebx
00561E5A  e821560200                       call   0x587480
00561E5F  68c0ccbc00                       push   0xbcccc0
00561E64  e8b1043300                       call   0x89231a
00561E69  83c404                           add    esp,0x4
00561E6C  89742428                         mov    DWORD PTR [esp+0x28],esi
00561E70  d98784000000                     fld    DWORD PTR [edi+0x84]
00561E76  83ec08                           sub    esp,0x8
00561E79  d95c241c                         fstp   DWORD PTR [esp+0x1c]
00561E7D  d944241c                         fld    DWORD PTR [esp+0x1c]
00561E81  d9542404                         fst    DWORD PTR [esp+0x4]
00561E85  d91c24                           fstp   DWORD PTR [esp]
00561E88  e8937b0200                       call   0x589a20
00561E8D  8a9f88000000                     mov    bl,BYTE PTR [edi+0x88]
00561E93  e8082deaff                       call   0x404ba0
00561E98  8898c4680000                     mov    BYTE PTR [eax+0x68c4],bl
00561E9E  eb03                             jmp    0x561ea3
00561EA0  83ceff                           or     esi,0xffffffff
00561EA3  f605640ffc0001                   test   BYTE PTR ds:0xfc0f64,0x1
00561EAA  7525                             jne    0x561ed1
00561EAC  830d640ffc0001                   or     DWORD PTR ds:0xfc0f64,0x1
00561EB3  c744242802000000                 mov    DWORD PTR [esp+0x28],0x2
00561EBB  e820bef1ff                       call   0x47dce0
00561EC0  68f0dabc00                       push   0xbcdaf0
00561EC5  e850043300                       call   0x89231a
00561ECA  83c404                           add    esp,0x4
00561ECD  89742428                         mov    DWORD PTR [esp+0x28],esi
00561ED1  8b473c                           mov    eax,DWORD PTR [edi+0x3c]
00561ED4  8b4f38                           mov    ecx,DWORD PTR [edi+0x38]
00561ED7  50                               push   eax
00561ED8  51                               push   ecx
00561ED9  68680ffc00                       push   0xfc0f68
00561EDE  e85dc7f1ff                       call   0x47e640
00561EE3  33db                             xor    ebx,ebx
00561EE5  89473c                           mov    DWORD PTR [edi+0x3c],eax
00561EE8  3bc3                             cmp    eax,ebx
00561EEA  741f                             je     0x561f0b
00561EEC  8b5738                           mov    edx,DWORD PTR [edi+0x38]
00561EEF  50                               push   eax
00561EF0  52                               push   edx
00561EF1  8bf7                             mov    esi,edi
00561EF3  e828380000                       call   0x565720
00561EF8  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00561EFC  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00561F03  59                               pop    ecx
00561F04  5f                               pop    edi
00561F05  5e                               pop    esi
00561F06  5b                               pop    ebx
00561F07  8be5                             mov    esp,ebp
00561F09  5d                               pop    ebp
00561F0A  c3                               ret
00561F0B  f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
00561F12  7525                             jne    0x561f39
00561F14  830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
00561F1B  c744242803000000                 mov    DWORD PTR [esp+0x28],0x3
00561F23  e8286f1700                       call   0x6d8e50
00561F28  68b0dbbc00                       push   0xbcdbb0
00561F2D  e8e8033300                       call   0x89231a
00561F32  83c404                           add    esp,0x4
00561F35  89742428                         mov    DWORD PTR [esp+0x28],esi
00561F39  8b4734                           mov    eax,DWORD PTR [edi+0x34]
00561F3C  50                               push   eax
00561F3D  b9c80ffc00                       mov    ecx,0xfc0fc8
00561F42  e8e9741700                       call   0x6d9430
00561F47  895f38                           mov    DWORD PTR [edi+0x38],ebx
00561F4A  895f3c                           mov    DWORD PTR [edi+0x3c],ebx
00561F4D  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00561F51  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00561F58  59                               pop    ecx
00561F59  5f                               pop    edi
00561F5A  5e                               pop    esi
00561F5B  5b                               pop    ebx
00561F5C  8be5                             mov    esp,ebp
00561F5E  5d                               pop    ebp
00561F5F  c3                               ret
00561F60  397728                           cmp    DWORD PTR [edi+0x28],esi
00561F63  0f8428010000                     je     0x562091
00561F69  897728                           mov    DWORD PTR [edi+0x28],esi
00561F6C  e8df22edff                       call   0x434250
00561F71  bb01000000                       mov    ebx,0x1
00561F76  895814                           mov    DWORD PTR [eax+0x14],ebx
00561F79  397738                           cmp    DWORD PTR [edi+0x38],esi
00561F7C  7439                             je     0x561fb7
00561F7E  684403c100                       push   0xc10344
00561F83  53                               push   ebx
00561F84  e8a792f3ff                       call   0x49b230
00561F89  50                               push   eax
00561F8A  e811b1f4ff                       call   0x4ad0a0
00561F8F  6aff                             push   0xffffffff
00561F91  51                               push   ecx
00561F92  e89992f3ff                       call   0x49b230
00561F97  83c404                           add    esp,0x4
00561F9A  e8b10bf4ff                       call   0x4a2b50
00561F9F  3bc3                             cmp    eax,ebx
00561FA1  754e                             jne    0x561ff1
00561FA3  e8d826ebff                       call   0x414680
00561FA8  8b4f3c                           mov    ecx,DWORD PTR [edi+0x3c]
00561FAB  8b5738                           mov    edx,DWORD PTR [edi+0x38]
00561FAE  51                               push   ecx
00561FAF  52                               push   edx
00561FB0  e8eb19f4ff                       call   0x4a39a0
00561FB5  eb3a                             jmp    0x561ff1
00561FB7  8d5f3c                           lea    ebx,[edi+0x3c]
00561FBA  8d7774                           lea    esi,[edi+0x74]
00561FBD  53                               push   ebx
00561FBE  e87dbe1500                       call   0x6bde40
00561FC3  50                               push   eax
00561FC4  56                               push   esi
00561FC5  8d74241c                         lea    esi,[esp+0x1c]
00561FC9  e8c248edff                       call   0x436890
00561FCE  57                               push   edi
00561FCF  e8cc030000                       call   0x5623a0
00561FD4  e8a726ebff                       call   0x414680
00561FD9  8b03                             mov    eax,DWORD PTR [ebx]
00561FDB  8b4f38                           mov    ecx,DWORD PTR [edi+0x38]
00561FDE  50                               push   eax
00561FDF  51                               push   ecx
00561FE0  e8bb19f4ff                       call   0x4a39a0
00561FE5  e8c6000000                       call   0x5620b0
00561FEA  bb01000000                       mov    ebx,0x1
00561FEF  33f6                             xor    esi,esi
00561FF1  f605d4f3fd0001                   test   BYTE PTR ds:0xfdf3d4,0x1
00561FF8  7528                             jne    0x562022
00561FFA  091dd4f3fd00                     or     DWORD PTR ds:0xfdf3d4,ebx
00562000  c744242804000000                 mov    DWORD PTR [esp+0x28],0x4
00562008  e873231900                       call   0x6f4380
0056200D  68d0e6bc00                       push   0xbce6d0
00562012  e803033300                       call   0x89231a
00562017  83c404                           add    esp,0x4
0056201A  c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
00562022  68ec06c100                       push   0xc106ec
00562027  56                               push   esi
00562028  68c8f3fd00                       push   0xfdf3c8
0056202D  e86eb0f4ff                       call   0x4ad0a0
00562032  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
00562039  7528                             jne    0x562063
0056203B  091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
00562041  c744242805000000                 mov    DWORD PTR [esp+0x28],0x5
00562049  e832540200                       call   0x587480
0056204E  68c0ccbc00                       push   0xbcccc0
00562053  e8c2023300                       call   0x89231a
00562058  83c404                           add    esp,0x4
0056205B  c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
00562063  d98784000000                     fld    DWORD PTR [edi+0x84]
00562069  83ec08                           sub    esp,0x8
0056206C  d95c241c                         fstp   DWORD PTR [esp+0x1c]
00562070  d944241c                         fld    DWORD PTR [esp+0x1c]
00562074  d9542404                         fst    DWORD PTR [esp+0x4]
00562078  d91c24                           fstp   DWORD PTR [esp]
0056207B  e8a0790200                       call   0x589a20
00562080  8a9f88000000                     mov    bl,BYTE PTR [edi+0x88]
00562086  e8152beaff                       call   0x404ba0
0056208B  8898c4680000                     mov    BYTE PTR [eax+0x68c4],bl
00562091  897738                           mov    DWORD PTR [edi+0x38],esi
00562094  89773c                           mov    DWORD PTR [edi+0x3c],esi
00562097  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0056209B  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
005620A2  59                               pop    ecx
005620A3  5f                               pop    edi
005620A4  5e                               pop    esi
005620A5  5b                               pop    ebx
005620A6  8be5                             mov    esp,ebp
005620A8  5d                               pop    ebp
005620A9  c3                               ret

; wait_unlock 0x562250..0x56231e
00562250  55                               push   ebp
00562251  8bec                             mov    ebp,esp
00562253  6aff                             push   0xffffffff
00562255  687a739200                       push   0x92737a
0056225A  64a100000000                     mov    eax,fs:0x0
00562260  50                               push   eax
00562261  51                               push   ecx
00562262  53                               push   ebx
00562263  a1201fd600                       mov    eax,ds:0xd61f20
00562268  33c5                             xor    eax,ebp
0056226A  50                               push   eax
0056226B  8d45f4                           lea    eax,[ebp-0xc]
0056226E  64a300000000                     mov    fs:0x0,eax
00562274  bb01000000                       mov    ebx,0x1
00562279  841dd4adfa00                     test   BYTE PTR ds:0xfaadd4,bl
0056227F  7526                             jne    0x5622a7
00562281  091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
00562287  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0056228E  e8ed510200                       call   0x587480
00562293  68c0ccbc00                       push   0xbcccc0
00562298  e87d003300                       call   0x89231a
0056229D  83c404                           add    esp,0x4
005622A0  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
005622A7  841dd0adfa00                     test   BYTE PTR ds:0xfaadd0,bl
005622AD  7522                             jne    0x5622d1
005622AF  091dd0adfa00                     or     DWORD PTR ds:0xfaadd0,ebx
005622B5  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
005622B8  e8d3b61e00                       call   0x74d990
005622BD  6870ccbc00                       push   0xbccc70
005622C2  e853003300                       call   0x89231a
005622C7  83c404                           add    esp,0x4
005622CA  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
005622D1  6822430f00                       push   0xf4322
005622D6  b81048f900                       mov    eax,0xf94810
005622DB  e860111f00                       call   0x753440
005622E0  841d147cfb00                     test   BYTE PTR ds:0xfb7c14,bl
005622E6  751f                             jne    0x562307
005622E8  091d147cfb00                     or     DWORD PTR ds:0xfb7c14,ebx
005622EE  c745fc02000000                   mov    DWORD PTR [ebp-0x4],0x2
005622F5  e856e41600                       call   0x6d0750
005622FA  6830d5bc00                       push   0xbcd530
005622FF  e816003300                       call   0x89231a
00562304  83c404                           add    esp,0x4
00562307  83253088fb00fd                   and    DWORD PTR ds:0xfb8830,0xfffffffd
0056230E  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00562311  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00562318  59                               pop    ecx
00562319  5b                               pop    ebx
0056231A  8be5                             mov    esp,ebp
0056231C  5d                               pop    ebp
0056231D  c3                               ret

; packet_00eb 0x4b6190..0x4b61fd
004B6190  55                               push   ebp
004B6191  8bec                             mov    ebp,esp
004B6193  6aff                             push   0xffffffff
004B6195  68aeb29300                       push   0x93b2ae
004B619A  64a100000000                     mov    eax,fs:0x0
004B61A0  50                               push   eax
004B61A1  a1201fd600                       mov    eax,ds:0xd61f20
004B61A6  33c5                             xor    eax,ebp
004B61A8  50                               push   eax
004B61A9  8d45f4                           lea    eax,[ebp-0xc]
004B61AC  64a300000000                     mov    fs:0x0,eax
004B61B2  b801000000                       mov    eax,0x1
004B61B7  8405b873fb00                     test   BYTE PTR ds:0xfb73b8,al
004B61BD  7526                             jne    0x4b61e5
004B61BF  0905b873fb00                     or     DWORD PTR ds:0xfb73b8,eax
004B61C5  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004B61CC  e89f9f0a00                       call   0x560170
004B61D1  6810d1bc00                       push   0xbcd110
004B61D6  e83fc13d00                       call   0x89231a
004B61DB  83c404                           add    esp,0x4
004B61DE  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004B61E5  e866c00a00                       call   0x562250
004B61EA  33c0                             xor    eax,eax
004B61EC  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004B61EF  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004B61F6  59                               pop    ecx
004B61F7  8be5                             mov    esp,ebp
004B61F9  5d                               pop    ebp
004B61FA  c20c00                           ret    0xc
