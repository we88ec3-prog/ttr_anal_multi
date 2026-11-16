; A01: normal startup passes formal VM W and Q manager M
; VA 0048d76b..0048d77a; raw 0008cb6b; SHA256 2b3c4b6f092205af6a25c141b0880f61622ee97ea977ca6a7ec70fb16454472f
0048d76b  bec8f3fd00                       mov    esi,0xfdf3c8
0048d770  b8c073fb00                       mov    eax,0xfb73c0
0048d775  e8862e0d00                       call   0x560600

; A02: formal Q initialization and registrar calls
; VA 00560600..005607c3; raw 0015fa00; SHA256 a3c5450ea3251f3054ea3867396b36851b2743317f2b9d645a2b1711a009dc61
00560600  55                               push   ebp
00560601  8bec                             mov    ebp,esp
00560603  83ec08                           sub    esp,0x8
00560606  8d4dfc                           lea    ecx,[ebp-0x4]
00560609  56                               push   esi
0056060a  51                               push   ecx
0056060b  8930                             mov    DWORD PTR [eax],esi
0056060d  e82e580000                       call   0x565e40
00560612  83c408                           add    esp,0x8
00560615  50                               push   eax
00560616  e805590000                       call   0x565f20
0056061b  50                               push   eax
0056061c  e89f590000                       call   0x565fc0
00560621  50                               push   eax
00560622  e8395a0000                       call   0x566060
00560627  50                               push   eax
00560628  e8d35a0000                       call   0x566100
0056062d  50                               push   eax
0056062e  e86d5b0000                       call   0x5661a0
00560633  50                               push   eax
00560634  e8075c0000                       call   0x566240
00560639  50                               push   eax
0056063a  e8a15c0000                       call   0x5662e0
0056063f  50                               push   eax
00560640  e83b5d0000                       call   0x566380
00560645  50                               push   eax
00560646  e8d55d0000                       call   0x566420
0056064b  50                               push   eax
0056064c  e86f5e0000                       call   0x5664c0
00560651  50                               push   eax
00560652  e8095f0000                       call   0x566560
00560657  50                               push   eax
00560658  e8a35f0000                       call   0x566600
0056065d  50                               push   eax
0056065e  e83d600000                       call   0x5666a0
00560663  50                               push   eax
00560664  e8d7600000                       call   0x566740
00560669  50                               push   eax
0056066a  e871610000                       call   0x5667e0
0056066f  50                               push   eax
00560670  e80b620000                       call   0x566880
00560675  50                               push   eax
00560676  e8a5620000                       call   0x566920
0056067b  50                               push   eax
0056067c  e83f630000                       call   0x5669c0
00560681  50                               push   eax
00560682  e8d9630000                       call   0x566a60
00560687  50                               push   eax
00560688  e873640000                       call   0x566b00
0056068d  50                               push   eax
0056068e  e80d650000                       call   0x566ba0
00560693  50                               push   eax
00560694  e8a7650000                       call   0x566c40
00560699  50                               push   eax
0056069a  e841660000                       call   0x566ce0
0056069f  50                               push   eax
005606a0  e8db660000                       call   0x566d80
005606a5  50                               push   eax
005606a6  e875670000                       call   0x566e20
005606ab  50                               push   eax
005606ac  e80f680000                       call   0x566ec0
005606b1  50                               push   eax
005606b2  e8a9680000                       call   0x566f60
005606b7  50                               push   eax
005606b8  e843690000                       call   0x567000
005606bd  50                               push   eax
005606be  e8dd690000                       call   0x5670a0
005606c3  50                               push   eax
005606c4  e8776a0000                       call   0x567140
005606c9  50                               push   eax
005606ca  e8116b0000                       call   0x5671e0
005606cf  50                               push   eax
005606d0  e8ab6b0000                       call   0x567280
005606d5  50                               push   eax
005606d6  e8456c0000                       call   0x567320
005606db  50                               push   eax
005606dc  e8df6c0000                       call   0x5673c0
005606e1  50                               push   eax
005606e2  e8796d0000                       call   0x567460
005606e7  50                               push   eax
005606e8  e8136e0000                       call   0x567500
005606ed  50                               push   eax
005606ee  e8ad6e0000                       call   0x5675a0
005606f3  50                               push   eax
005606f4  e8476f0000                       call   0x567640
005606f9  50                               push   eax
005606fa  e8e16f0000                       call   0x5676e0
005606ff  50                               push   eax
00560700  e87b700000                       call   0x567780
00560705  50                               push   eax
00560706  e815710000                       call   0x567820
0056070b  50                               push   eax
0056070c  e8af710000                       call   0x5678c0
00560711  50                               push   eax
00560712  e849720000                       call   0x567960
00560717  50                               push   eax
00560718  e8e3720000                       call   0x567a00
0056071d  50                               push   eax
0056071e  e87d730000                       call   0x567aa0
00560723  50                               push   eax
00560724  e817740000                       call   0x567b40
00560729  50                               push   eax
0056072a  e8b1740000                       call   0x567be0
0056072f  50                               push   eax
00560730  e84b750000                       call   0x567c80
00560735  50                               push   eax
00560736  e8e5750000                       call   0x567d20
0056073b  50                               push   eax
0056073c  e87f760000                       call   0x567dc0
00560741  50                               push   eax
00560742  e819770000                       call   0x567e60
00560747  50                               push   eax
00560748  e8b3770000                       call   0x567f00
0056074d  50                               push   eax
0056074e  e84d780000                       call   0x567fa0
00560753  50                               push   eax
00560754  e8e7780000                       call   0x568040
00560759  50                               push   eax
0056075a  e881790000                       call   0x5680e0
0056075f  50                               push   eax
00560760  e81b7a0000                       call   0x568180
00560765  50                               push   eax
00560766  e8b57a0000                       call   0x568220
0056076b  50                               push   eax
0056076c  e84f7b0000                       call   0x5682c0
00560771  50                               push   eax
00560772  e8e97b0000                       call   0x568360
00560777  50                               push   eax
00560778  e8837c0000                       call   0x568400
0056077d  50                               push   eax
0056077e  e81d7d0000                       call   0x5684a0
00560783  50                               push   eax
00560784  e8b77d0000                       call   0x568540
00560789  50                               push   eax
0056078a  e8517e0000                       call   0x5685e0
0056078f  68c855c000                       push   0xc055c8
00560794  8bce                             mov    ecx,esi
00560796  e8b5421900                       call   0x6f4a50
0056079b  68b055c000                       push   0xc055b0
005607a0  8bce                             mov    ecx,esi
005607a2  e8a9421900                       call   0x6f4a50
005607a7  68bc55c000                       push   0xc055bc
005607ac  8bce                             mov    ecx,esi
005607ae  e89d421900                       call   0x6f4a50
005607b3  685806c100                       push   0xc10658
005607b8  8bce                             mov    ecx,esi
005607ba  e891421900                       call   0x6f4a50
005607bf  8be5                             mov    esp,ebp
005607c1  5d                               pop    ebp
005607c2  c3                               ret

; A03: Q table creation and native owner FE2778 publication
; VA 00565e40..00565f15; raw 00165240; SHA256 8799844b6771a4b2652be2e4442053f1058ba8213881942a991e94945038efdb
00565e40  55                               push   ebp
00565e41  8bec                             mov    ebp,esp
00565e43  51                               push   ecx
00565e44  53                               push   ebx
00565e45  8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
00565e48  56                               push   esi
00565e49  8b33                             mov    esi,DWORD PTR [ebx]
00565e4b  a37827fe00                       mov    ds:0xfe2778,eax
00565e50  8b4610                           mov    eax,DWORD PTR [esi+0x10]
00565e53  8b4844                           mov    ecx,DWORD PTR [eax+0x44]
00565e56  57                               push   edi
00565e57  891d7427fe00                     mov    DWORD PTR ds:0xfe2774,ebx
00565e5d  3b4840                           cmp    ecx,DWORD PTR [eax+0x40]
00565e60  7207                             jb     0x565e69
00565e62  8bc6                             mov    eax,esi
00565e64  e837551900                       call   0x6fb3a0
00565e69  8b7e08                           mov    edi,DWORD PTR [esi+0x8]
00565e6c  6a00                             push   0x0
00565e6e  6a00                             push   0x0
00565e70  56                               push   esi
00565e71  e82a3b1900                       call   0x6f99a0
00565e76  8907                             mov    DWORD PTR [edi],eax
00565e78  c7470805000000                   mov    DWORD PTR [edi+0x8],0x5
00565e7f  83460810                         add    DWORD PTR [esi+0x8],0x10
00565e83  8b33                             mov    esi,DWORD PTR [ebx]
00565e85  83c40c                           add    esp,0xc
00565e88  bf0406c100                       mov    edi,0xc10604
00565e8d  b8eed8ffff                       mov    eax,0xffffd8ee
00565e92  e8f9f81800                       call   0x6f5790
00565e97  8b33                             mov    esi,DWORD PTR [ebx]
00565e99  b8eed8ffff                       mov    eax,0xffffd8ee
00565e9e  e8ddf71800                       call   0x6f5680
00565ea3  8b03                             mov    eax,DWORD PTR [ebx]
00565ea5  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00565ea8  83e810                           sub    eax,0x10
00565eab  bff0ffffff                       mov    edi,0xfffffff0
00565eb0  3dc8bfc000                       cmp    eax,0xc0bfc8
00565eb5  7406                             je     0x565ebd
00565eb7  83780805                         cmp    DWORD PTR [eax+0x8],0x5
00565ebb  7417                             je     0x565ed4
00565ebd  680406c100                       push   0xc10604
00565ec2  68c426c400                       push   0xc426c4
00565ec7  e8f1d13200                       call   0x8930bd
00565ecc  8b03                             mov    eax,DWORD PTR [ebx]
00565ece  83c408                           add    esp,0x8
00565ed1  017808                           add    DWORD PTR [eax+0x8],edi
00565ed4  8b33                             mov    esi,DWORD PTR [ebx]
00565ed6  682462c000                       push   0xc06224
00565edb  e830f61800                       call   0x6f5510
00565ee0  8b33                             mov    esi,DWORD PTR [ebx]
00565ee2  83c404                           add    esp,0x4
00565ee5  6a00                             push   0x0
00565ee7  6890875600                       push   0x568790
00565eec  e8bff61800                       call   0x6f55b0
00565ef1  8b13                             mov    edx,DWORD PTR [ebx]
00565ef3  52                               push   edx
00565ef4  b8fdffffff                       mov    eax,0xfffffffd
00565ef9  e8f2f81800                       call   0x6f57f0
00565efe  8b1b                             mov    ebx,DWORD PTR [ebx]
00565f00  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00565f03  83c40c                           add    esp,0xc
00565f06  017b08                           add    DWORD PTR [ebx+0x8],edi
00565f09  5f                               pop    edi
00565f0a  5e                               pop    esi
00565f0b  c7000406c100                     mov    DWORD PTR [eax],0xc10604
00565f11  5b                               pop    ebx
00565f12  59                               pop    ecx
00565f13  5d                               pop    ebp
00565f14  c3                               ret

; A04: Q manager creates its own actor tree sentinel FB73DC and count FB73E0
; VA 00560197..00560237; raw 0015f597; SHA256 3d30278575ed422d46d5b5ad2f9a48a87101924cb80d9697cfa1f4042cd469e3
00560197  33db                             xor    ebx,ebx
00560199  6a34                             push   0x34
0056019b  c745e4c073fb00                   mov    DWORD PTR [ebp-0x1c],0xfb73c0
005601a2  891dc073fb00                     mov    DWORD PTR ds:0xfb73c0,ebx
005601a8  891dc473fb00                     mov    DWORD PTR ds:0xfb73c4,ebx
005601ae  891dd073fb00                     mov    DWORD PTR ds:0xfb73d0,ebx
005601b4  e8af103300                       call   0x891268
005601b9  83c404                           add    esp,0x4
005601bc  3bc3                             cmp    eax,ebx
005601be  0f8432020000                     je     0x5603f6
005601c4  a3cc73fb00                       mov    ds:0xfb73cc,eax
005601c9  8900                             mov    DWORD PTR [eax],eax
005601cb  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601d0  894004                           mov    DWORD PTR [eax+0x4],eax
005601d3  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601d8  894008                           mov    DWORD PTR [eax+0x8],eax
005601db  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601e0  c6403001                         mov    BYTE PTR [eax+0x30],0x1
005601e4  8b0dcc73fb00                     mov    ecx,DWORD PTR ds:0xfb73cc
005601ea  c6413101                         mov    BYTE PTR [ecx+0x31],0x1
005601ee  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
005601f1  6a18                             push   0x18
005601f3  891de073fb00                     mov    DWORD PTR ds:0xfb73e0,ebx
005601f9  e86a103300                       call   0x891268
005601fe  83c404                           add    esp,0x4
00560201  3bc3                             cmp    eax,ebx
00560203  0f84c9010000                     je     0x5603d2
00560209  a3dc73fb00                       mov    ds:0xfb73dc,eax
0056020e  8900                             mov    DWORD PTR [eax],eax
00560210  a1dc73fb00                       mov    eax,ds:0xfb73dc
00560215  894004                           mov    DWORD PTR [eax+0x4],eax
00560218  a1dc73fb00                       mov    eax,ds:0xfb73dc
0056021d  894008                           mov    DWORD PTR [eax+0x8],eax
00560220  8b15dc73fb00                     mov    edx,DWORD PTR ds:0xfb73dc
00560226  c6421401                         mov    BYTE PTR [edx+0x14],0x1
0056022a  a1dc73fb00                       mov    eax,ds:0xfb73dc
0056022f  c6401501                         mov    BYTE PTR [eax+0x15],0x1
00560233  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1

; A05: Q.CreateObject registrar
; VA 00566560..005665f9; raw 00165960; SHA256 5ddfea19f46b231f2f8609e7f4d8288644aad9e2b85aae950d4d68231ef5a937
00566560  55                               push   ebp
00566561  8bec                             mov    ebp,esp
00566563  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566566  53                               push   ebx
00566567  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0056656d  56                               push   esi
0056656e  8b33                             mov    esi,DWORD PTR [ebx]
00566570  57                               push   edi
00566571  8b38                             mov    edi,DWORD PTR [eax]
00566573  b8eed8ffff                       mov    eax,0xffffd8ee
00566578  c705a427fe00c02e5600             mov    DWORD PTR ds:0xfe27a4,0x562ec0
00566582  e8f9f01800                       call   0x6f5680
00566587  8b03                             mov    eax,DWORD PTR [ebx]
00566589  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056658c  83e810                           sub    eax,0x10
0056658f  3dc8bfc000                       cmp    eax,0xc0bfc8
00566594  7406                             je     0x56659c
00566596  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0056659a  7414                             je     0x5665b0
0056659c  57                               push   edi
0056659d  68c426c400                       push   0xc426c4
005665a2  e816cb3200                       call   0x8930bd
005665a7  8b1b                             mov    ebx,DWORD PTR [ebx]
005665a9  83c408                           add    esp,0x8
005665ac  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
005665b0  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
005665b6  8b37                             mov    esi,DWORD PTR [edi]
005665b8  68e4a2d600                       push   0xd6a2e4
005665bd  e84eef1800                       call   0x6f5510
005665c2  8b37                             mov    esi,DWORD PTR [edi]
005665c4  83c404                           add    esp,0x4
005665c7  6a00                             push   0x0
005665c9  68008e5600                       push   0x568e00
005665ce  e8ddef1800                       call   0x6f55b0
005665d3  8b0f                             mov    ecx,DWORD PTR [edi]
005665d5  51                               push   ecx
005665d6  b8fdffffff                       mov    eax,0xfffffffd
005665db  e810f21800                       call   0x6f57f0
005665e0  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
005665e6  8b02                             mov    eax,DWORD PTR [edx]
005665e8  83c40c                           add    esp,0xc
005665eb  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
005665ef  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
005665f2  5f                               pop    edi
005665f3  5e                               pop    esi
005665f4  5b                               pop    ebx
005665f5  5d                               pop    ebp
005665f6  c20400                           ret    0x4

; A06: Q.DeleteObject registrar
; VA 005666a0..00566739; raw 00165aa0; SHA256 5e45d82025ea2bc95ee24b3b8e1a854445dac21b338250b2233336217c66548b
005666a0  55                               push   ebp
005666a1  8bec                             mov    ebp,esp
005666a3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
005666a6  53                               push   ebx
005666a7  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
005666ad  56                               push   esi
005666ae  8b33                             mov    esi,DWORD PTR [ebx]
005666b0  57                               push   edi
005666b1  8b38                             mov    edi,DWORD PTR [eax]
005666b3  b8eed8ffff                       mov    eax,0xffffd8ee
005666b8  c705ac27fe0030644700             mov    DWORD PTR ds:0xfe27ac,0x476430
005666c2  e8b9ef1800                       call   0x6f5680
005666c7  8b03                             mov    eax,DWORD PTR [ebx]
005666c9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
005666cc  83e810                           sub    eax,0x10
005666cf  3dc8bfc000                       cmp    eax,0xc0bfc8
005666d4  7406                             je     0x5666dc
005666d6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
005666da  7414                             je     0x5666f0
005666dc  57                               push   edi
005666dd  68c426c400                       push   0xc426c4
005666e2  e8d6c93200                       call   0x8930bd
005666e7  8b1b                             mov    ebx,DWORD PTR [ebx]
005666e9  83c408                           add    esp,0x8
005666ec  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
005666f0  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
005666f6  8b37                             mov    esi,DWORD PTR [edi]
005666f8  6800a3d600                       push   0xd6a300
005666fd  e80eee1800                       call   0x6f5510
00566702  8b37                             mov    esi,DWORD PTR [edi]
00566704  83c404                           add    esp,0x4
00566707  6a00                             push   0x0
00566709  68c08e5600                       push   0x568ec0
0056670e  e89dee1800                       call   0x6f55b0
00566713  8b0f                             mov    ecx,DWORD PTR [edi]
00566715  51                               push   ecx
00566716  b8fdffffff                       mov    eax,0xfffffffd
0056671b  e8d0f01800                       call   0x6f57f0
00566720  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
00566726  8b02                             mov    eax,DWORD PTR [edx]
00566728  83c40c                           add    esp,0xc
0056672b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0056672f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566732  5f                               pop    edi
00566733  5e                               pop    esi
00566734  5b                               pop    ebx
00566735  5d                               pop    ebp
00566736  c20400                           ret    0x4

; A07: Q.DeleteAllObject registrar
; VA 00567460..005674f9; raw 00166860; SHA256 c18cf023dbd94028e1917945c396b41c1f3eeef413c230f607520409f153a982
00567460  55                               push   ebp
00567461  8bec                             mov    ebp,esp
00567463  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00567466  53                               push   ebx
00567467  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0056746d  56                               push   esi
0056746e  8b33                             mov    esi,DWORD PTR [ebx]
00567470  57                               push   edi
00567471  8b38                             mov    edi,DWORD PTR [eax]
00567473  b8eed8ffff                       mov    eax,0xffffd8ee
00567478  c7050428fe00703a5600             mov    DWORD PTR ds:0xfe2804,0x563a70
00567482  e8f9e11800                       call   0x6f5680
00567487  8b03                             mov    eax,DWORD PTR [ebx]
00567489  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056748c  83e810                           sub    eax,0x10
0056748f  3dc8bfc000                       cmp    eax,0xc0bfc8
00567494  7406                             je     0x56749c
00567496  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0056749a  7414                             je     0x5674b0
0056749c  57                               push   edi
0056749d  68c426c400                       push   0xc426c4
005674a2  e816bc3200                       call   0x8930bd
005674a7  8b1b                             mov    ebx,DWORD PTR [ebx]
005674a9  83c408                           add    esp,0x8
005674ac  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
005674b0  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
005674b6  8b37                             mov    esi,DWORD PTR [edi]
005674b8  6834a4d600                       push   0xd6a434
005674bd  e84ee01800                       call   0x6f5510
005674c2  8b37                             mov    esi,DWORD PTR [edi]
005674c4  83c404                           add    esp,0x4
005674c7  6a00                             push   0x0
005674c9  6800975600                       push   0x569700
005674ce  e8dde01800                       call   0x6f55b0
005674d3  8b0f                             mov    ecx,DWORD PTR [edi]
005674d5  51                               push   ecx
005674d6  b8fdffffff                       mov    eax,0xfffffffd
005674db  e810e31800                       call   0x6f57f0
005674e0  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
005674e6  8b02                             mov    eax,DWORD PTR [edx]
005674e8  83c40c                           add    esp,0xc
005674eb  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
005674ef  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
005674f2  5f                               pop    edi
005674f3  5e                               pop    esi
005674f4  5b                               pop    ebx
005674f5  5d                               pop    ebp
005674f6  c20400                           ret    0x4

; A08: Q.ShowObject registrar
; VA 00567320..005673b9; raw 00166720; SHA256 81c64cbf151a075a8df9a9a42bfde9477ae035101c4a620f00574b90d6a2b67a
00567320  55                               push   ebp
00567321  8bec                             mov    ebp,esp
00567323  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00567326  53                               push   ebx
00567327  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0056732d  56                               push   esi
0056732e  8b33                             mov    esi,DWORD PTR [ebx]
00567330  57                               push   edi
00567331  8b38                             mov    edi,DWORD PTR [eax]
00567333  b8eed8ffff                       mov    eax,0xffffd8ee
00567338  c705fc27fe0000495600             mov    DWORD PTR ds:0xfe27fc,0x564900
00567342  e839e31800                       call   0x6f5680
00567347  8b03                             mov    eax,DWORD PTR [ebx]
00567349  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056734c  83e810                           sub    eax,0x10
0056734f  3dc8bfc000                       cmp    eax,0xc0bfc8
00567354  7406                             je     0x56735c
00567356  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0056735a  7414                             je     0x567370
0056735c  57                               push   edi
0056735d  68c426c400                       push   0xc426c4
00567362  e856bd3200                       call   0x8930bd
00567367  8b1b                             mov    ebx,DWORD PTR [ebx]
00567369  83c408                           add    esp,0x8
0056736c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
00567370  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
00567376  8b37                             mov    esi,DWORD PTR [edi]
00567378  681ca4d600                       push   0xd6a41c
0056737d  e88ee11800                       call   0x6f5510
00567382  8b37                             mov    esi,DWORD PTR [edi]
00567384  83c404                           add    esp,0x4
00567387  6a00                             push   0x0
00567389  6840965600                       push   0x569640
0056738e  e81de21800                       call   0x6f55b0
00567393  8b0f                             mov    ecx,DWORD PTR [edi]
00567395  51                               push   ecx
00567396  b8fdffffff                       mov    eax,0xfffffffd
0056739b  e850e41800                       call   0x6f57f0
005673a0  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
005673a6  8b02                             mov    eax,DWORD PTR [edx]
005673a8  83c40c                           add    esp,0xc
005673ab  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
005673af  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
005673b2  5f                               pop    edi
005673b3  5e                               pop    esi
005673b4  5b                               pop    ebx
005673b5  5d                               pop    ebp
005673b6  c20400                           ret    0x4

; A09: CreateObject Lua closure returns one result slot without pushing a new ID
; VA 00568e00..00568e56; raw 00168200; SHA256 463289c730ea1984e9e99347bf73f6c0258c70d8d85e98ae07b688cc7a6d7ebf
00568e00  55                               push   ebp
00568e01  8bec                             mov    ebp,esp
00568e03  6aff                             push   0xffffffff
00568e05  68c8839300                       push   0x9383c8
00568e0a  64a100000000                     mov    eax,fs:0x0
00568e10  50                               push   eax
00568e11  83ec0c                           sub    esp,0xc
00568e14  a1201fd600                       mov    eax,ds:0xd61f20
00568e19  33c5                             xor    eax,ebp
00568e1b  50                               push   eax
00568e1c  8d45f4                           lea    eax,[ebp-0xc]
00568e1f  64a300000000                     mov    fs:0x0,eax
00568e25  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00568e28  8945e8                           mov    DWORD PTR [ebp-0x18],eax
00568e2b  33c0                             xor    eax,eax
00568e2d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00568e30  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00568e33  8d4de8                           lea    ecx,[ebp-0x18]
00568e36  51                               push   ecx
00568e37  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00568e3a  e8d1180000                       call   0x56a710
00568e3f  83c404                           add    esp,0x4
00568e42  b801000000                       mov    eax,0x1
00568e47  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00568e4a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00568e51  59                               pop    ecx
00568e52  8be5                             mov    esp,ebp
00568e54  5d                               pop    ebp
00568e55  c3                               ret

; A10: nine-argument CreateObject conversion including all type/fallback branches
; VA 0056a710..0056aa94; raw 00169b10; SHA256 c8483201e59e6bdfdb9df0517dd77444e6865ff46c32b185de22febf84e85feb
0056a710  55                               push   ebp
0056a711  8bec                             mov    ebp,esp
0056a713  83ec60                           sub    esp,0x60
0056a716  a1a427fe00                       mov    eax,ds:0xfe27a4
0056a71b  8b0d7827fe00                     mov    ecx,DWORD PTR ds:0xfe2778
0056a721  53                               push   ebx
0056a722  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0056a725  56                               push   esi
0056a726  8945c0                           mov    DWORD PTR [ebp-0x40],eax
0056a729  894dc4                           mov    DWORD PTR [ebp-0x3c],ecx
0056a72c  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a72e  57                               push   edi
0056a72f  83c8ff                           or     eax,0xffffffff
0056a732  e8b9a91800                       call   0x6f50f0
0056a737  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a73a  83f903                           cmp    ecx,0x3
0056a73d  742e                             je     0x56a76d
0056a73f  83f904                           cmp    ecx,0x4
0056a742  0f85ef020000                     jne    0x56aa37
0056a748  8b30                             mov    esi,DWORD PTR [eax]
0056a74a  83c610                           add    esi,0x10
0056a74d  8d7db0                           lea    edi,[ebp-0x50]
0056a750  e80bd01800                       call   0x6f7760
0056a755  85c0                             test   eax,eax
0056a757  0f84da020000                     je     0x56aa37
0056a75d  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a760  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a767  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a76a  8d45a0                           lea    eax,[ebp-0x60]
0056a76d  dd00                             fld    QWORD PTR [eax]
0056a76f  dd5db0                           fstp   QWORD PTR [ebp-0x50]
0056a772  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a775  db5d08                           fistp  DWORD PTR [ebp+0x8]
0056a778  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0056a77b  8955e0                           mov    DWORD PTR [ebp-0x20],edx
0056a77e  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a780  b8feffffff                       mov    eax,0xfffffffe
0056a785  e866a91800                       call   0x6f50f0
0056a78a  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a78d  83f903                           cmp    ecx,0x3
0056a790  742e                             je     0x56a7c0
0056a792  83f904                           cmp    ecx,0x4
0056a795  0f85a8020000                     jne    0x56aa43
0056a79b  8b30                             mov    esi,DWORD PTR [eax]
0056a79d  83c610                           add    esi,0x10
0056a7a0  8d7db0                           lea    edi,[ebp-0x50]
0056a7a3  e8b8cf1800                       call   0x6f7760
0056a7a8  85c0                             test   eax,eax
0056a7aa  0f8493020000                     je     0x56aa43
0056a7b0  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a7b3  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a7ba  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a7bd  8d45a0                           lea    eax,[ebp-0x60]
0056a7c0  dd00                             fld    QWORD PTR [eax]
0056a7c2  dd5db0                           fstp   QWORD PTR [ebp-0x50]
0056a7c5  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a7c8  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0056a7cb  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0056a7ce  8945dc                           mov    DWORD PTR [ebp-0x24],eax
0056a7d1  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a7d3  b8fdffffff                       mov    eax,0xfffffffd
0056a7d8  e813a91800                       call   0x6f50f0
0056a7dd  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a7e0  83f903                           cmp    ecx,0x3
0056a7e3  742e                             je     0x56a813
0056a7e5  83f904                           cmp    ecx,0x4
0056a7e8  0f8561020000                     jne    0x56aa4f
0056a7ee  8b30                             mov    esi,DWORD PTR [eax]
0056a7f0  83c610                           add    esi,0x10
0056a7f3  8d7db0                           lea    edi,[ebp-0x50]
0056a7f6  e865cf1800                       call   0x6f7760
0056a7fb  85c0                             test   eax,eax
0056a7fd  0f844c020000                     je     0x56aa4f
0056a803  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a806  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a80d  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a810  8d45a0                           lea    eax,[ebp-0x60]
0056a813  dd00                             fld    QWORD PTR [eax]
0056a815  dd5db0                           fstp   QWORD PTR [ebp-0x50]
0056a818  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a81b  db5df8                           fistp  DWORD PTR [ebp-0x8]
0056a81e  8b4df8                           mov    ecx,DWORD PTR [ebp-0x8]
0056a821  894dd8                           mov    DWORD PTR [ebp-0x28],ecx
0056a824  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a826  b8fcffffff                       mov    eax,0xfffffffc
0056a82b  e8c0a81800                       call   0x6f50f0
0056a830  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a833  83f903                           cmp    ecx,0x3
0056a836  742e                             je     0x56a866
0056a838  83f904                           cmp    ecx,0x4
0056a83b  0f851a020000                     jne    0x56aa5b
0056a841  8b30                             mov    esi,DWORD PTR [eax]
0056a843  83c610                           add    esi,0x10
0056a846  8d7db0                           lea    edi,[ebp-0x50]
0056a849  e812cf1800                       call   0x6f7760
0056a84e  85c0                             test   eax,eax
0056a850  0f8405020000                     je     0x56aa5b
0056a856  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a859  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a860  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a863  8d45a0                           lea    eax,[ebp-0x60]
0056a866  dd00                             fld    QWORD PTR [eax]
0056a868  dd5db0                           fstp   QWORD PTR [ebp-0x50]
0056a86b  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a86e  db5df4                           fistp  DWORD PTR [ebp-0xc]
0056a871  8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
0056a874  8955d4                           mov    DWORD PTR [ebp-0x2c],edx
0056a877  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a879  b8fbffffff                       mov    eax,0xfffffffb
0056a87e  e86da81800                       call   0x6f50f0
0056a883  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a886  83f903                           cmp    ecx,0x3
0056a889  742e                             je     0x56a8b9
0056a88b  83f904                           cmp    ecx,0x4
0056a88e  0f85d3010000                     jne    0x56aa67
0056a894  8b30                             mov    esi,DWORD PTR [eax]
0056a896  83c610                           add    esi,0x10
0056a899  8d7db0                           lea    edi,[ebp-0x50]
0056a89c  e8bfce1800                       call   0x6f7760
0056a8a1  85c0                             test   eax,eax
0056a8a3  0f84be010000                     je     0x56aa67
0056a8a9  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a8ac  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a8b3  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a8b6  8d45a0                           lea    eax,[ebp-0x60]
0056a8b9  dd00                             fld    QWORD PTR [eax]
0056a8bb  dd5db0                           fstp   QWORD PTR [ebp-0x50]
0056a8be  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a8c1  db5df0                           fistp  DWORD PTR [ebp-0x10]
0056a8c4  8b45f0                           mov    eax,DWORD PTR [ebp-0x10]
0056a8c7  8945d0                           mov    DWORD PTR [ebp-0x30],eax
0056a8ca  8b03                             mov    eax,DWORD PTR [ebx]
0056a8cc  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056a8cf  8b48a8                           mov    ecx,DWORD PTR [eax-0x58]
0056a8d2  83e860                           sub    eax,0x60
0056a8d5  83f903                           cmp    ecx,0x3
0056a8d8  742e                             je     0x56a908
0056a8da  83f904                           cmp    ecx,0x4
0056a8dd  0f8590010000                     jne    0x56aa73
0056a8e3  8b30                             mov    esi,DWORD PTR [eax]
0056a8e5  83c610                           add    esi,0x10
0056a8e8  8d7db0                           lea    edi,[ebp-0x50]
0056a8eb  e870ce1800                       call   0x6f7760
0056a8f0  85c0                             test   eax,eax
0056a8f2  0f847b010000                     je     0x56aa73
0056a8f8  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a8fb  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a902  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a905  8d45a0                           lea    eax,[ebp-0x60]
0056a908  dd00                             fld    QWORD PTR [eax]
0056a90a  8b03                             mov    eax,DWORD PTR [ebx]
0056a90c  dd5db8                           fstp   QWORD PTR [ebp-0x48]
0056a90f  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056a912  8b4898                           mov    ecx,DWORD PTR [eax-0x68]
0056a915  83e870                           sub    eax,0x70
0056a918  83f903                           cmp    ecx,0x3
0056a91b  742e                             je     0x56a94b
0056a91d  83f904                           cmp    ecx,0x4
0056a920  0f8554010000                     jne    0x56aa7a
0056a926  8b30                             mov    esi,DWORD PTR [eax]
0056a928  83c610                           add    esi,0x10
0056a92b  8d7db0                           lea    edi,[ebp-0x50]
0056a92e  e82dce1800                       call   0x6f7760
0056a933  85c0                             test   eax,eax
0056a935  0f843f010000                     je     0x56aa7a
0056a93b  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056a93e  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a945  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a948  8d45a0                           lea    eax,[ebp-0x60]
0056a94b  dd00                             fld    QWORD PTR [eax]
0056a94d  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a94f  dd5db0                           fstp   QWORD PTR [ebp-0x50]
0056a952  b8f8ffffff                       mov    eax,0xfffffff8
0056a957  e894a71800                       call   0x6f50f0
0056a95c  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a95f  83f903                           cmp    ecx,0x3
0056a962  742e                             je     0x56a992
0056a964  83f904                           cmp    ecx,0x4
0056a967  0f8514010000                     jne    0x56aa81
0056a96d  8b30                             mov    esi,DWORD PTR [eax]
0056a96f  83c610                           add    esi,0x10
0056a972  8d7dc8                           lea    edi,[ebp-0x38]
0056a975  e8e6cd1800                       call   0x6f7760
0056a97a  85c0                             test   eax,eax
0056a97c  0f84ff000000                     je     0x56aa81
0056a982  dd45c8                           fld    QWORD PTR [ebp-0x38]
0056a985  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a98c  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a98f  8d45a0                           lea    eax,[ebp-0x60]
0056a992  dd00                             fld    QWORD PTR [eax]
0056a994  dd5dc8                           fstp   QWORD PTR [ebp-0x38]
0056a997  dd45c8                           fld    QWORD PTR [ebp-0x38]
0056a99a  db5dec                           fistp  DWORD PTR [ebp-0x14]
0056a99d  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0056a9a0  894dcc                           mov    DWORD PTR [ebp-0x34],ecx
0056a9a3  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a9a5  b8f7ffffff                       mov    eax,0xfffffff7
0056a9aa  e841a71800                       call   0x6f50f0
0056a9af  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a9b2  83f903                           cmp    ecx,0x3
0056a9b5  742e                             je     0x56a9e5
0056a9b7  83f904                           cmp    ecx,0x4
0056a9ba  0f85cd000000                     jne    0x56aa8d
0056a9c0  8b30                             mov    esi,DWORD PTR [eax]
0056a9c2  83c610                           add    esi,0x10
0056a9c5  8d7de4                           lea    edi,[ebp-0x1c]
0056a9c8  e893cd1800                       call   0x6f7760
0056a9cd  85c0                             test   eax,eax
0056a9cf  0f84b8000000                     je     0x56aa8d
0056a9d5  dd45e4                           fld    QWORD PTR [ebp-0x1c]
0056a9d8  c745a803000000                   mov    DWORD PTR [ebp-0x58],0x3
0056a9df  dd5da0                           fstp   QWORD PTR [ebp-0x60]
0056a9e2  8d45a0                           lea    eax,[ebp-0x60]
0056a9e5  dd00                             fld    QWORD PTR [eax]
0056a9e7  dd5da8                           fstp   QWORD PTR [ebp-0x58]
0056a9ea  dd45a8                           fld    QWORD PTR [ebp-0x58]
0056a9ed  db5de8                           fistp  DWORD PTR [ebp-0x18]
0056a9f0  8b45e8                           mov    eax,DWORD PTR [ebp-0x18]
0056a9f3  8b55e0                           mov    edx,DWORD PTR [ebp-0x20]
0056a9f6  dd45b8                           fld    QWORD PTR [ebp-0x48]
0056a9f9  8b4ddc                           mov    ecx,DWORD PTR [ebp-0x24]
0056a9fc  52                               push   edx
0056a9fd  8b55d8                           mov    edx,DWORD PTR [ebp-0x28]
0056aa00  51                               push   ecx
0056aa01  8b4dd4                           mov    ecx,DWORD PTR [ebp-0x2c]
0056aa04  52                               push   edx
0056aa05  8b55d0                           mov    edx,DWORD PTR [ebp-0x30]
0056aa08  d95dd0                           fstp   DWORD PTR [ebp-0x30]
0056aa0b  d945d0                           fld    DWORD PTR [ebp-0x30]
0056aa0e  51                               push   ecx
0056aa0f  8b4dcc                           mov    ecx,DWORD PTR [ebp-0x34]
0056aa12  52                               push   edx
0056aa13  83ec08                           sub    esp,0x8
0056aa16  d95c2404                         fstp   DWORD PTR [esp+0x4]
0056aa1a  dd45b0                           fld    QWORD PTR [ebp-0x50]
0056aa1d  d95dd0                           fstp   DWORD PTR [ebp-0x30]
0056aa20  d945d0                           fld    DWORD PTR [ebp-0x30]
0056aa23  d91c24                           fstp   DWORD PTR [esp]
0056aa26  51                               push   ecx
0056aa27  8b4dc4                           mov    ecx,DWORD PTR [ebp-0x3c]
0056aa2a  50                               push   eax
0056aa2b  ff55c0                           call   DWORD PTR [ebp-0x40]
0056aa2e  5f                               pop    edi
0056aa2f  5e                               pop    esi
0056aa30  33c0                             xor    eax,eax
0056aa32  5b                               pop    ebx
0056aa33  8be5                             mov    esp,ebp
0056aa35  5d                               pop    ebp
0056aa36  c3                               ret
0056aa37  c745e000000000                   mov    DWORD PTR [ebp-0x20],0x0
0056aa3e  e93bfdffff                       jmp    0x56a77e
0056aa43  c745dc00000000                   mov    DWORD PTR [ebp-0x24],0x0
0056aa4a  e982fdffff                       jmp    0x56a7d1
0056aa4f  c745d800000000                   mov    DWORD PTR [ebp-0x28],0x0
0056aa56  e9c9fdffff                       jmp    0x56a824
0056aa5b  c745d400000000                   mov    DWORD PTR [ebp-0x2c],0x0
0056aa62  e910feffff                       jmp    0x56a877
0056aa67  c745d000000000                   mov    DWORD PTR [ebp-0x30],0x0
0056aa6e  e957feffff                       jmp    0x56a8ca
0056aa73  d9ee                             fldz
0056aa75  e990feffff                       jmp    0x56a90a
0056aa7a  d9ee                             fldz
0056aa7c  e9ccfeffff                       jmp    0x56a94d
0056aa81  c745cc00000000                   mov    DWORD PTR [ebp-0x34],0x0
0056aa88  e916ffffff                       jmp    0x56a9a3
0056aa8d  33c0                             xor    eax,eax
0056aa8f  e95fffffff                       jmp    0x56a9f3

; A11: complete selected CreateObject target: ID packing, CEventActor setup and Q-map publication
; VA 00562ec0..005632c5; raw 001622c0; SHA256 c70cd69c66adb257ff96a92bcadedb19a32c4f1bd357cad824f39932bcc2dc1a
00562ec0  55                               push   ebp
00562ec1  8bec                             mov    ebp,esp
00562ec3  83e4f8                           and    esp,0xfffffff8
00562ec6  6aff                             push   0xffffffff
00562ec8  6803a19300                       push   0x93a103
00562ecd  64a100000000                     mov    eax,fs:0x0
00562ed3  50                               push   eax
00562ed4  83ec20                           sub    esp,0x20
00562ed7  53                               push   ebx
00562ed8  56                               push   esi
00562ed9  57                               push   edi
00562eda  a1201fd600                       mov    eax,ds:0xd61f20
00562edf  33c4                             xor    eax,esp
00562ee1  50                               push   eax
00562ee2  8d442430                         lea    eax,[esp+0x30]
00562ee6  64a300000000                     mov    fs:0x0,eax
00562eec  894c2418                         mov    DWORD PTR [esp+0x18],ecx
00562ef0  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
00562ef3  33c0                             xor    eax,eax
00562ef5  6689442414                       mov    WORD PTR [esp+0x14],ax
00562efa  83ff0a                           cmp    edi,0xa
00562efd  7d06                             jge    0x562f05
00562eff  88442414                         mov    BYTE PTR [esp+0x14],al
00562f03  eb40                             jmp    0x562f45
00562f05  81ff10270000                     cmp    edi,0x2710
00562f0b  7d07                             jge    0x562f14
00562f0d  c644241401                       mov    BYTE PTR [esp+0x14],0x1
00562f12  eb31                             jmp    0x562f45
00562f14  81fff82a0000                     cmp    edi,0x2af8
00562f1a  7d07                             jge    0x562f23
00562f1c  c644241406                       mov    BYTE PTR [esp+0x14],0x6
00562f21  eb22                             jmp    0x562f45
00562f23  81ff08520000                     cmp    edi,0x5208
00562f29  7d07                             jge    0x562f32
00562f2b  c644241407                       mov    BYTE PTR [esp+0x14],0x7
00562f30  eb13                             jmp    0x562f45
00562f32  57                               push   edi
00562f33  681807c100                       push   0xc10718
00562f38  e823ac1800                       call   0x6edb60
00562f3d  83c408                           add    esp,0x8
00562f40  c644241400                       mov    BYTE PTR [esp+0x14],0x0
00562f45  8a4d08                           mov    cl,BYTE PTR [ebp+0x8]
00562f48  6838040000                       push   0x438
00562f4d  884c2419                         mov    BYTE PTR [esp+0x19],cl
00562f51  e812e33200                       call   0x891268
00562f56  83c404                           add    esp,0x4
00562f59  89442424                         mov    DWORD PTR [esp+0x24],eax
00562f5d  33db                             xor    ebx,ebx
00562f5f  895c2438                         mov    DWORD PTR [esp+0x38],ebx
00562f63  3bc3                             cmp    eax,ebx
00562f65  7408                             je     0x562f6f
00562f67  50                               push   eax
00562f68  e813dcf6ff                       call   0x4d0b80
00562f6d  8bd8                             mov    ebx,eax
00562f6f  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00562f77  668b542414                       mov    dx,WORD PTR [esp+0x14]
00562f7c  0fb6f2                           movzx  esi,dl
00562f7f  0fb7c7                           movzx  eax,di
00562f82  66895304                         mov    WORD PTR [ebx+0x4],dx
00562f86  8b13                             mov    edx,DWORD PTR [ebx]
00562f88  c1e618                           shl    esi,0x18
00562f8b  0bf0                             or     esi,eax
00562f8d  8b423c                           mov    eax,DWORD PTR [edx+0x3c]
00562f90  56                               push   esi
00562f91  8bcb                             mov    ecx,ebx
00562f93  c7839000000010000000             mov    DWORD PTR [ebx+0x90],0x10
00562f9d  ffd0                             call   eax
00562f9f  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
00562fa4  8b13                             mov    edx,DWORD PTR [ebx]
00562fa6  8b5244                           mov    edx,DWORD PTR [edx+0x44]
00562fa9  6a01                             push   0x1
00562fab  8d442428                         lea    eax,[esp+0x28]
00562faf  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
00562fb5  f30f104514                       movss  xmm0,DWORD PTR [ebp+0x14]
00562fba  50                               push   eax
00562fbb  8bcb                             mov    ecx,ebx
00562fbd  f30f11442430                     movss  DWORD PTR [esp+0x30],xmm0
00562fc3  ffd2                             call   edx
00562fc5  8b4d18                           mov    ecx,DWORD PTR [ebp+0x18]
00562fc8  8b03                             mov    eax,DWORD PTR [ebx]
00562fca  8b5058                           mov    edx,DWORD PTR [eax+0x58]
00562fcd  51                               push   ecx
00562fce  8bcb                             mov    ecx,ebx
00562fd0  ffd2                             call   edx
00562fd2  f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
00562fd9  7529                             jne    0x563004
00562fdb  b801000000                       mov    eax,0x1
00562fe0  0905b075fb00                     or     DWORD PTR ds:0xfb75b0,eax
00562fe6  89442438                         mov    DWORD PTR [esp+0x38],eax
00562fea  e8910df9ff                       call   0x4f3d80
00562fef  68e0d1bc00                       push   0xbcd1e0
00562ff4  e821f33200                       call   0x89231a
00562ff9  83c404                           add    esp,0x4
00562ffc  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563004  8d54241c                         lea    edx,[esp+0x1c]
00563008  b97074fb00                       mov    ecx,0xfb7470
0056300d  8974241c                         mov    DWORD PTR [esp+0x1c],esi
00563011  e85a4af9ff                       call   0x4f7a70
00563016  d9405c                           fld    DWORD PTR [eax+0x5c]
00563019  8b03                             mov    eax,DWORD PTR [ebx]
0056301b  d95c241c                         fstp   DWORD PTR [esp+0x1c]
0056301f  d944241c                         fld    DWORD PTR [esp+0x1c]
00563023  8b505c                           mov    edx,DWORD PTR [eax+0x5c]
00563026  51                               push   ecx
00563027  8bcb                             mov    ecx,ebx
00563029  d91c24                           fstp   DWORD PTR [esp]
0056302c  ffd2                             call   edx
0056302e  8b4d24                           mov    ecx,DWORD PTR [ebp+0x24]
00563031  83ff0a                           cmp    edi,0xa
00563034  7d09                             jge    0x56303f
00563036  85c9                             test   ecx,ecx
00563038  7505                             jne    0x56303f
0056303a  b901000000                       mov    ecx,0x1
0056303f  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
00563045  66898b88030000                   mov    WORD PTR [ebx+0x388],cx
0056304c  85c0                             test   eax,eax
0056304e  7412                             je     0x563062
00563050  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
00563057  7409                             je     0x563062
00563059  51                               push   ecx
0056305a  6a01                             push   0x1
0056305c  50                               push   eax
0056305d  e83e3e2400                       call   0x7a6ea0
00563062  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00563069  7529                             jne    0x563094
0056306b  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00563072  c744243802000000                 mov    DWORD PTR [esp+0x38],0x2
0056307a  e8c19e2300                       call   0x79cf40
0056307f  6880dbbc00                       push   0xbcdb80
00563084  e891f23200                       call   0x89231a
00563089  83c404                           add    esp,0x4
0056308c  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563094  8d44241c                         lea    eax,[esp+0x1c]
00563098  50                               push   eax
00563099  8d442418                         lea    eax,[esp+0x18]
0056309d  b9900efc00                       mov    ecx,0xfc0e90
005630a2  897c2420                         mov    DWORD PTR [esp+0x20],edi
005630a6  e8e526fbff                       call   0x515790
005630ab  8b442414                         mov    eax,DWORD PTR [esp+0x14]
005630af  3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
005630b5  7409                             je     0x5630c0
005630b7  8b4010                           mov    eax,DWORD PTR [eax+0x10]
005630ba  83785400                         cmp    DWORD PTR [eax+0x54],0x0
005630be  7553                             jne    0x563113
005630c0  8b742418                         mov    esi,DWORD PTR [esp+0x18]
005630c4  8d4d0c                           lea    ecx,[ebp+0xc]
005630c7  83c660                           add    esi,0x60
005630ca  51                               push   ecx
005630cb  e870ad1500                       call   0x6bde40
005630d0  50                               push   eax
005630d1  56                               push   esi
005630d2  8d74242c                         lea    esi,[esp+0x2c]
005630d6  e8f58aeeff                       call   0x44bbd0
005630db  f605400efc0001                   test   BYTE PTR ds:0xfc0e40,0x1
005630e2  7529                             jne    0x56310d
005630e4  830d400efc0001                   or     DWORD PTR ds:0xfc0e40,0x1
005630eb  c744243803000000                 mov    DWORD PTR [esp+0x38],0x3
005630f3  e878d6fdff                       call   0x540770
005630f8  6860dbbc00                       push   0xbcdb60
005630fd  e818f23200                       call   0x89231a
00563102  83c404                           add    esp,0x4
00563105  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
0056310d  57                               push   edi
0056310e  e8fde4fdff                       call   0x541610
00563113  8b542418                         mov    edx,DWORD PTR [esp+0x18]
00563117  837a7000                         cmp    DWORD PTR [edx+0x70],0x0
0056311b  0f840b010000                     je     0x56322c
00563121  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00563128  7529                             jne    0x563153
0056312a  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00563131  c744243804000000                 mov    DWORD PTR [esp+0x38],0x4
00563139  e8029e2300                       call   0x79cf40
0056313e  6880dbbc00                       push   0xbcdb80
00563143  e8d2f13200                       call   0x89231a
00563148  83c404                           add    esp,0x4
0056314b  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563153  8d44241c                         lea    eax,[esp+0x1c]
00563157  50                               push   eax
00563158  8d442418                         lea    eax,[esp+0x18]
0056315c  b9900efc00                       mov    ecx,0xfc0e90
00563161  897c2420                         mov    DWORD PTR [esp+0x20],edi
00563165  e82626fbff                       call   0x515790
0056316a  8b442414                         mov    eax,DWORD PTR [esp+0x14]
0056316e  3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
00563174  0f84b2000000                     je     0x56322c
0056317a  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0056317d  8b7154                           mov    esi,DWORD PTR [ecx+0x54]
00563180  85f6                             test   esi,esi
00563182  0f84a4000000                     je     0x56322c
00563188  6a01                             push   0x1
0056318a  8bfe                             mov    edi,esi
0056318c  e85f262600                       call   0x7c57f0
00563191  6a04                             push   0x4
00563193  e858262600                       call   0x7c57f0
00563198  8b442418                         mov    eax,DWORD PTR [esp+0x18]
0056319c  0fb75508                         movzx  edx,WORD PTR [ebp+0x8]
005631a0  8b7870                           mov    edi,DWORD PTR [eax+0x70]
005631a3  8d4c241c                         lea    ecx,[esp+0x1c]
005631a7  51                               push   ecx
005631a8  8d442418                         lea    eax,[esp+0x18]
005631ac  8bcf                             mov    ecx,edi
005631ae  89542420                         mov    DWORD PTR [esp+0x20],edx
005631b2  e8c9302c00                       call   0x826280
005631b7  8b442414                         mov    eax,DWORD PTR [esp+0x14]
005631bb  3b4704                           cmp    eax,DWORD PTR [edi+0x4]
005631be  746c                             je     0x56322c
005631c0  8b4010                           mov    eax,DWORD PTR [eax+0x10]
005631c3  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
005631c6  89442424                         mov    DWORD PTR [esp+0x24],eax
005631ca  8b01                             mov    eax,DWORD PTR [ecx]
005631cc  8944241c                         mov    DWORD PTR [esp+0x1c],eax
005631d0  3bc1                             cmp    eax,ecx
005631d2  7458                             je     0x56322c
005631d4  0fb7500c                         movzx  edx,WORD PTR [eax+0xc]
005631d8  8d442414                         lea    eax,[esp+0x14]
005631dc  50                               push   eax
005631dd  8d442424                         lea    eax,[esp+0x24]
005631e1  8d8ed4000000                     lea    ecx,[esi+0xd4]
005631e7  89542418                         mov    DWORD PTR [esp+0x18],edx
005631eb  e810bd2c00                       call   0x82ef00
005631f0  8b7c2420                         mov    edi,DWORD PTR [esp+0x20]
005631f4  3bbed8000000                     cmp    edi,DWORD PTR [esi+0xd8]
005631fa  741a                             je     0x563216
005631fc  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
005631ff  8b11                             mov    edx,DWORD PTR [ecx]
00563201  8b4208                           mov    eax,DWORD PTR [edx+0x8]
00563204  ffd0                             call   eax
00563206  3b442414                         cmp    eax,DWORD PTR [esp+0x14]
0056320a  750a                             jne    0x563216
0056320c  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
0056320f  8b11                             mov    edx,DWORD PTR [ecx]
00563211  8b4224                           mov    eax,DWORD PTR [edx+0x24]
00563214  ffd0                             call   eax
00563216  8d44241c                         lea    eax,[esp+0x1c]
0056321a  e831a62b00                       call   0x81d850
0056321f  8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
00563223  8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
00563227  3b4108                           cmp    eax,DWORD PTR [ecx+0x8]
0056322a  75a8                             jne    0x5631d4
0056322c  8bf3                             mov    esi,ebx
0056322e  e8adddf6ff                       call   0x4d0fe0
00563233  8b93f0000000                     mov    edx,DWORD PTR [ebx+0xf0]
00563239  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0056323c  8d8bf0000000                     lea    ecx,[ebx+0xf0]
00563242  6a14                             push   0x14
00563244  ffd0                             call   eax
00563246  d9e8                             fld1
00563248  8b13                             mov    edx,DWORD PTR [ebx]
0056324a  8b451c                           mov    eax,DWORD PTR [ebp+0x1c]
0056324d  8b5268                           mov    edx,DWORD PTR [edx+0x68]
00563250  51                               push   ecx
00563251  d91c24                           fstp   DWORD PTR [esp]
00563254  50                               push   eax
00563255  8bcb                             mov    ecx,ebx
00563257  ffd2                             call   edx
00563259  8b4d28                           mov    ecx,DWORD PTR [ebp+0x28]
0056325c  85c9                             test   ecx,ecx
0056325e  7421                             je     0x563281
00563260  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
00563266  85c0                             test   eax,eax
00563268  7417                             je     0x563281
0056326a  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
00563271  740e                             je     0x563281
00563273  6a00                             push   0x0
00563275  0fb7c9                           movzx  ecx,cx
00563278  6a00                             push   0x0
0056327a  51                               push   ecx
0056327b  50                               push   eax
0056327c  e8bf3f2400                       call   0x7a7240
00563281  8b5520                           mov    edx,DWORD PTR [ebp+0x20]
00563284  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00563287  8b742418                         mov    esi,DWORD PTR [esp+0x18]
0056328b  83c618                           add    esi,0x18
0056328e  8d7c2424                         lea    edi,[esp+0x24]
00563292  89932c040000                     mov    DWORD PTR [ebx+0x42c],edx
00563298  89442424                         mov    DWORD PTR [esp+0x24],eax
0056329c  895c2428                         mov    DWORD PTR [esp+0x28],ebx
005632a0  e87bbc0100                       call   0x57ef20
005632a5  50                               push   eax
005632a6  56                               push   esi
005632a7  8d74242c                         lea    esi,[esp+0x2c]
005632ab  e850bf2c00                       call   0x82f200
005632b0  8b4c2430                         mov    ecx,DWORD PTR [esp+0x30]
005632b4  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
005632bb  59                               pop    ecx
005632bc  5f                               pop    edi
005632bd  5e                               pop    esi
005632be  5b                               pop    ebx
005632bf  8be5                             mov    esp,ebp
005632c1  5d                               pop    ebp
005632c2  c22400                           ret    0x24

; A12: CEventActor constructor and fixed RTTI-backed vtables
; VA 004d0b80..004d0c96; raw 000cff80; SHA256 e186d1c8cae059deded8c02d1627bce0ffbb57705a539e00eb528eedd5c9c8b6
004d0b80  55                               push   ebp
004d0b81  8bec                             mov    ebp,esp
004d0b83  6aff                             push   0xffffffff
004d0b85  6823099100                       push   0x910923
004d0b8a  64a100000000                     mov    eax,fs:0x0
004d0b90  50                               push   eax
004d0b91  51                               push   ecx
004d0b92  53                               push   ebx
004d0b93  56                               push   esi
004d0b94  57                               push   edi
004d0b95  a1201fd600                       mov    eax,ds:0xd61f20
004d0b9a  33c5                             xor    eax,ebp
004d0b9c  50                               push   eax
004d0b9d  8d45f4                           lea    eax,[ebp-0xc]
004d0ba0  64a300000000                     mov    fs:0x0,eax
004d0ba6  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
004d0ba9  57                               push   edi
004d0baa  e8c164ffff                       call   0x4c7070
004d0baf  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004d0bb6  6a3c                             push   0x3c
004d0bb8  c70724c8c000                     mov    DWORD PTR [edi],0xc0c824
004d0bbe  c787f0000000acc8c000             mov    DWORD PTR [edi+0xf0],0xc0c8ac
004d0bc8  e89b063c00                       call   0x891268
004d0bcd  8bf0                             mov    esi,eax
004d0bcf  83c404                           add    esp,0x4
004d0bd2  8975f0                           mov    DWORD PTR [ebp-0x10],esi
004d0bd5  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
004d0bd9  85f6                             test   esi,esi
004d0bdb  741b                             je     0x4d0bf8
004d0bdd  8bc7                             mov    eax,edi
004d0bdf  b903000000                       mov    ecx,0x3
004d0be4  e847a6ffff                       call   0x4cb230
004d0be9  c706cc77c000                     mov    DWORD PTR [esi],0xc077cc
004d0bef  c7463401000000                   mov    DWORD PTR [esi+0x34],0x1
004d0bf6  eb02                             jmp    0x4d0bfa
004d0bf8  33f6                             xor    esi,esi
004d0bfa  8b5e08                           mov    ebx,DWORD PTR [esi+0x8]
004d0bfd  83bc9ff400000000                 cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
004d0c05  740d                             je     0x4d0c14
004d0c07  683c75c000                       push   0xc0753c
004d0c0c  e84fcf2100                       call   0x6edb60
004d0c11  83c404                           add    esp,0x4
004d0c14  89b49ff4000000                   mov    DWORD PTR [edi+ebx*4+0xf4],esi
004d0c1b  83bf5801000000                   cmp    DWORD PTR [edi+0x158],0x0
004d0c22  7506                             jne    0x4d0c2a
004d0c24  89b758010000                     mov    DWORD PTR [edi+0x158],esi
004d0c2a  f30f10056c5bc500                 movss  xmm0,DWORD PTR ds:0xc55b6c
004d0c32  f30f118794030000                 movss  DWORD PTR [edi+0x394],xmm0
004d0c3a  f30f1187cc000000                 movss  DWORD PTR [edi+0xcc],xmm0
004d0c42  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
004d0c4a  f30f118734040000                 movss  DWORD PTR [edi+0x434],xmm0
004d0c52  f30f1005385bc500                 movss  xmm0,DWORD PTR ds:0xc55b38
004d0c5a  c7872004000000000000             mov    DWORD PTR [edi+0x420],0x0
004d0c64  c7872c04000001000000             mov    DWORD PTR [edi+0x42c],0x1
004d0c6e  c787d000000064000000             mov    DWORD PTR [edi+0xd0],0x64
004d0c78  f30f118730040000                 movss  DWORD PTR [edi+0x430],xmm0
004d0c80  8bc7                             mov    eax,edi
004d0c82  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004d0c85  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004d0c8c  59                               pop    ecx
004d0c8d  5f                               pop    edi
004d0c8e  5e                               pop    esi
004d0c8f  5b                               pop    ebx
004d0c90  8be5                             mov    esp,ebp
004d0c92  5d                               pop    ebp
004d0c93  c20400                           ret    0x4

; A13: model virtual writes the packed model key to +88/+8C
; VA 004c6fb0..004c6fc3; raw 000c63b0; SHA256 f71cb56f8e396ac390c2c8ffc21b27f36c9e76acb2e9af42460c4675a29869b7
004c6fb0  55                               push   ebp
004c6fb1  8bec                             mov    ebp,esp
004c6fb3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004c6fb6  898188000000                     mov    DWORD PTR [ecx+0x88],eax
004c6fbc  89818c000000                     mov    DWORD PTR [ecx+0x8c],eax
004c6fc2  5d                               pop    ebp

; A14: successful 24-byte node allocation and key/pointer copying
; VA 0057ef20..0057ef60; raw 0017e320; SHA256 1c10bc49692f53834b201855d977750cb83b2d08208edeb63e2c1a358faf3549
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

; A15: unique map insertion: duplicate frees only the new node and returns old iterator/false
; VA 0082f200..0082f2c6; raw 0042e600; SHA256 3dc78d4ed988394eebd6ba66314de66efada035ad6af50a88291840d4cfc5599
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

; A16: unsigned DWORD-key map lookup
; VA 0082ef00..0082ef67; raw 0042e300; SHA256 8aa14d38c50c3cba4e1df1035c559905be926880ec559950ed0676578cfefc6b
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

; A17: MoveObject looks up the full Q slot and changes the selected CEventActor
; VA 005632d0..00563330; raw 001626d0; SHA256 5d3130966d8eab3a3c3a0cb8adb61f46dc266363c589ff08034d5cf034739c69
005632d0  55                               push   ebp
005632d1  8bec                             mov    ebp,esp
005632d3  83ec0c                           sub    esp,0xc
005632d6  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
005632d9  56                               push   esi
005632da  8bf1                             mov    esi,ecx
005632dc  8d4d08                           lea    ecx,[ebp+0x8]
005632df  894508                           mov    DWORD PTR [ebp+0x8],eax
005632e2  51                               push   ecx
005632e3  8d4e18                           lea    ecx,[esi+0x18]
005632e6  8d45fc                           lea    eax,[ebp-0x4]
005632e9  e812bc2c00                       call   0x82ef00
005632ee  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
005632f1  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
005632f4  7433                             je     0x563329
005632f6  8b7010                           mov    esi,DWORD PTR [eax+0x10]
005632f9  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
005632fe  8b16                             mov    edx,DWORD PTR [esi]
00563300  8b5244                           mov    edx,DWORD PTR [edx+0x44]
00563303  6a01                             push   0x1
00563305  8d45f8                           lea    eax,[ebp-0x8]
00563308  f30f1145f8                       movss  DWORD PTR [ebp-0x8],xmm0
0056330d  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
00563312  50                               push   eax
00563313  8bce                             mov    ecx,esi
00563315  f30f1145fc                       movss  DWORD PTR [ebp-0x4],xmm0
0056331a  ffd2                             call   edx
0056331c  8b4d14                           mov    ecx,DWORD PTR [ebp+0x14]
0056331f  8b06                             mov    eax,DWORD PTR [esi]
00563321  8b5058                           mov    edx,DWORD PTR [eax+0x58]
00563324  51                               push   ecx
00563325  8bce                             mov    ecx,esi
00563327  ffd2                             call   edx
00563329  5e                               pop    esi
0056332a  8be5                             mov    esp,ebp
0056332c  5d                               pop    ebp
0056332d  c21000                           ret    0x10

; A18: DeleteObject Lua closure uses the registered pointer
; VA 00568ec0..00568f1c; raw 001682c0; SHA256 44fdd96c0d3b0b1e76879baeb751b613714f55d14e9b96d44d36310c5d1427ff
00568ec0  55                               push   ebp
00568ec1  8bec                             mov    ebp,esp
00568ec3  6aff                             push   0xffffffff
00568ec5  68c8839300                       push   0x9383c8
00568eca  64a100000000                     mov    eax,fs:0x0
00568ed0  50                               push   eax
00568ed1  83ec0c                           sub    esp,0xc
00568ed4  a1201fd600                       mov    eax,ds:0xd61f20
00568ed9  33c5                             xor    eax,ebp
00568edb  50                               push   eax
00568edc  8d45f4                           lea    eax,[ebp-0xc]
00568edf  64a300000000                     mov    fs:0x0,eax
00568ee5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00568ee8  8945e8                           mov    DWORD PTR [ebp-0x18],eax
00568eeb  33c0                             xor    eax,eax
00568eed  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00568ef0  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00568ef3  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00568ef6  8b0dac27fe00                     mov    ecx,DWORD PTR ds:0xfe27ac
00568efc  51                               push   ecx
00568efd  8d45e8                           lea    eax,[ebp-0x18]
00568f00  e82b150000                       call   0x56a430
00568f05  83c404                           add    esp,0x4
00568f08  b801000000                       mov    eax,0x1
00568f0d  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00568f10  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00568f17  59                               pop    ecx
00568f18  8be5                             mov    esp,ebp
00568f1a  5d                               pop    ebp
00568f1b  c3                               ret

; A19: DeleteObject one-integer marshaller and no result push
; VA 0056a430..0056a4a3; raw 00169830; SHA256 ed9871da5aa7b7fb1b47dd2cdb5602c38d2554a686fe84960f2c53d470fcd479
0056a430  55                               push   ebp
0056a431  8bec                             mov    ebp,esp
0056a433  8b08                             mov    ecx,DWORD PTR [eax]
0056a435  83ec18                           sub    esp,0x18
0056a438  53                               push   ebx
0056a439  8b1d7827fe00                     mov    ebx,DWORD PTR ds:0xfe2778
0056a43f  83c8ff                           or     eax,0xffffffff
0056a442  e8a9ac1800                       call   0x6f50f0
0056a447  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a44a  83f903                           cmp    ecx,0x3
0056a44d  742a                             je     0x56a479
0056a44f  83f904                           cmp    ecx,0x4
0056a452  7540                             jne    0x56a494
0056a454  56                               push   esi
0056a455  8b30                             mov    esi,DWORD PTR [eax]
0056a457  57                               push   edi
0056a458  83c610                           add    esi,0x10
0056a45b  8d7df8                           lea    edi,[ebp-0x8]
0056a45e  e8fdd21800                       call   0x6f7760
0056a463  5f                               pop    edi
0056a464  5e                               pop    esi
0056a465  85c0                             test   eax,eax
0056a467  742b                             je     0x56a494
0056a469  dd45f8                           fld    QWORD PTR [ebp-0x8]
0056a46c  c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
0056a473  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0056a476  8d45e8                           lea    eax,[ebp-0x18]
0056a479  dd00                             fld    QWORD PTR [eax]
0056a47b  dd5df0                           fstp   QWORD PTR [ebp-0x10]
0056a47e  dd45f0                           fld    QWORD PTR [ebp-0x10]
0056a481  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0056a484  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0056a487  50                               push   eax
0056a488  8bcb                             mov    ecx,ebx
0056a48a  ff5508                           call   DWORD PTR [ebp+0x8]
0056a48d  33c0                             xor    eax,eax
0056a48f  5b                               pop    ebx
0056a490  8be5                             mov    esp,ebp
0056a492  5d                               pop    ebp
0056a493  c3                               ret
0056a494  33c0                             xor    eax,eax
0056a496  50                               push   eax
0056a497  8bcb                             mov    ecx,ebx
0056a499  ff5508                           call   DWORD PTR [ebp+0x8]
0056a49c  33c0                             xor    eax,eax
0056a49e  5b                               pop    ebx
0056a49f  8be5                             mov    esp,ebp
0056a4a1  5d                               pop    ebp
0056a4a2  c3                               ret

; A20: DeleteObject target is only ret 4
; VA 00476430..00476433; raw 00075830; SHA256 e598d0c3ba86d917b177d7adde0556aa99bc355543c57aee0a3e50b684dd7e99
00476430  c20400                           ret    0x4

; A21: DeleteAllObject closure uses normal Q receiver
; VA 00569700..00569756; raw 00168b00; SHA256 ee42902df1578d647fceebfb46560c93f198ba6ef096e9ecbdd199a0d9cb7213
00569700  55                               push   ebp
00569701  8bec                             mov    ebp,esp
00569703  6aff                             push   0xffffffff
00569705  68c8839300                       push   0x9383c8
0056970a  64a100000000                     mov    eax,fs:0x0
00569710  50                               push   eax
00569711  83ec0c                           sub    esp,0xc
00569714  a1201fd600                       mov    eax,ds:0xd61f20
00569719  33c5                             xor    eax,ebp
0056971b  50                               push   eax
0056971c  8d45f4                           lea    eax,[ebp-0xc]
0056971f  64a300000000                     mov    fs:0x0,eax
00569725  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00569728  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0056972b  33c0                             xor    eax,eax
0056972d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00569730  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00569733  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00569736  8b0d7827fe00                     mov    ecx,DWORD PTR ds:0xfe2778
0056973c  ff150428fe00                     call   DWORD PTR ds:0xfe2804
00569742  b801000000                       mov    eax,0x1
00569747  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0056974a  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00569751  59                               pop    ecx
00569752  8be5                             mov    esp,ebp
00569754  5d                               pop    ebp
00569755  c3                               ret

; A22: DeleteAllObject actor iteration, cleanup, deleting destructors, tree clear and resource-job tail
; VA 00563a70..00563c37; raw 00162e70; SHA256 d335cbbdb101bcaf3e39aec8a4c14ebdc42b0f5ee39b0c0e610797634c3a58dd
00563a70  55                               push   ebp
00563a71  8bec                             mov    ebp,esp
00563a73  83e4f8                           and    esp,0xfffffff8
00563a76  6aff                             push   0xffffffff
00563a78  683e939300                       push   0x93933e
00563a7d  64a100000000                     mov    eax,fs:0x0
00563a83  50                               push   eax
00563a84  83ec18                           sub    esp,0x18
00563a87  53                               push   ebx
00563a88  56                               push   esi
00563a89  57                               push   edi
00563a8a  a1201fd600                       mov    eax,ds:0xd61f20
00563a8f  33c4                             xor    eax,esp
00563a91  50                               push   eax
00563a92  8d442428                         lea    eax,[esp+0x28]
00563a96  64a300000000                     mov    fs:0x0,eax
00563a9c  894c2414                         mov    DWORD PTR [esp+0x14],ecx
00563aa0  8b411c                           mov    eax,DWORD PTR [ecx+0x1c]
00563aa3  8b30                             mov    esi,DWORD PTR [eax]
00563aa5  3bf0                             cmp    esi,eax
00563aa7  746f                             je     0x563b18
00563aa9  8da42400000000                   lea    esp,[esp+0x0]
00563ab0  8b7e10                           mov    edi,DWORD PTR [esi+0x10]
00563ab3  33db                             xor    ebx,ebx
00563ab5  3bfb                             cmp    edi,ebx
00563ab7  7417                             je     0x563ad0
00563ab9  8b07                             mov    eax,DWORD PTR [edi]
00563abb  8b5014                           mov    edx,DWORD PTR [eax+0x14]
00563abe  8bcf                             mov    ecx,edi
00563ac0  ffd2                             call   edx
00563ac2  8b07                             mov    eax,DWORD PTR [edi]
00563ac4  8b10                             mov    edx,DWORD PTR [eax]
00563ac6  6a01                             push   0x1
00563ac8  8bcf                             mov    ecx,edi
00563aca  ffd2                             call   edx
00563acc  8b4c2414                         mov    ecx,DWORD PTR [esp+0x14]
00563ad0  385e15                           cmp    BYTE PTR [esi+0x15],bl
00563ad3  753c                             jne    0x563b11
00563ad5  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00563ad8  385815                           cmp    BYTE PTR [eax+0x15],bl
00563adb  7514                             jne    0x563af1
00563add  8bf0                             mov    esi,eax
00563adf  8b06                             mov    eax,DWORD PTR [esi]
00563ae1  385815                           cmp    BYTE PTR [eax+0x15],bl
00563ae4  752b                             jne    0x563b11
00563ae6  8bf0                             mov    esi,eax
00563ae8  8b06                             mov    eax,DWORD PTR [esi]
00563aea  385815                           cmp    BYTE PTR [eax+0x15],bl
00563aed  74f7                             je     0x563ae6
00563aef  eb20                             jmp    0x563b11
00563af1  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00563af4  385815                           cmp    BYTE PTR [eax+0x15],bl
00563af7  7516                             jne    0x563b0f
00563af9  8da42400000000                   lea    esp,[esp+0x0]
00563b00  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
00563b03  750a                             jne    0x563b0f
00563b05  8bf0                             mov    esi,eax
00563b07  8b4004                           mov    eax,DWORD PTR [eax+0x4]
00563b0a  385815                           cmp    BYTE PTR [eax+0x15],bl
00563b0d  74f1                             je     0x563b00
00563b0f  8bf0                             mov    esi,eax
00563b11  3b711c                           cmp    esi,DWORD PTR [ecx+0x1c]
00563b14  759a                             jne    0x563ab0
00563b16  eb02                             jmp    0x563b1a
00563b18  33db                             xor    ebx,ebx
00563b1a  8d7918                           lea    edi,[ecx+0x18]
00563b1d  e82efd2b00                       call   0x823850
00563b22  6a1c                             push   0x1c
00563b24  e83fd73200                       call   0x891268
00563b29  83c404                           add    esp,0x4
00563b2c  3bc3                             cmp    eax,ebx
00563b2e  7411                             je     0x563b41
00563b30  8918                             mov    DWORD PTR [eax],ebx
00563b32  c6400801                         mov    BYTE PTR [eax+0x8],0x1
00563b36  89580c                           mov    DWORD PTR [eax+0xc],ebx
00563b39  895810                           mov    DWORD PTR [eax+0x10],ebx
00563b3c  895814                           mov    DWORD PTR [eax+0x14],ebx
00563b3f  eb02                             jmp    0x563b43
00563b41  33c0                             xor    eax,eax
00563b43  50                               push   eax
00563b44  8d442420                         lea    eax,[esp+0x20]
00563b48  50                               push   eax
00563b49  895c2424                         mov    DWORD PTR [esp+0x24],ebx
00563b4d  895c2428                         mov    DWORD PTR [esp+0x28],ebx
00563b51  e87a85f1ff                       call   0x47c0d0
00563b56  895c2430                         mov    DWORD PTR [esp+0x30],ebx
00563b5a  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
00563b5e  83ec08                           sub    esp,0x8
00563b61  c6470801                         mov    BYTE PTR [edi+0x8],0x1
00563b65  8bf4                             mov    esi,esp
00563b67  c7470403000000                   mov    DWORD PTR [edi+0x4],0x3
00563b6e  891e                             mov    DWORD PTR [esi],ebx
00563b70  895e04                           mov    DWORD PTR [esi+0x4],ebx
00563b73  8b5c2428                         mov    ebx,DWORD PTR [esp+0x28]
00563b77  89642420                         mov    DWORD PTR [esp+0x20],esp
00563b7b  85db                             test   ebx,ebx
00563b7d  7412                             je     0x563b91
00563b7f  8bd3                             mov    edx,ebx
00563b81  e8ca86f1ff                       call   0x47c250
00563b86  84c0                             test   al,al
00563b88  7407                             je     0x563b91
00563b8a  53                               push   ebx
00563b8b  57                               push   edi
00563b8c  e82ff62300                       call   0x7a31c0
00563b91  c644243801                       mov    BYTE PTR [esp+0x38],0x1
00563b96  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00563b9d  7523                             jne    0x563bc2
00563b9f  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00563ba6  c644243802                       mov    BYTE PTR [esp+0x38],0x2
00563bab  e890932300                       call   0x79cf40
00563bb0  6880dbbc00                       push   0xbcdb80
00563bb5  e860e73200                       call   0x89231a
00563bba  83c404                           add    esp,0x4
00563bbd  c644243801                       mov    BYTE PTR [esp+0x38],0x1
00563bc2  b9900efc00                       mov    ecx,0xfc0e90
00563bc7  c644243800                       mov    BYTE PTR [esp+0x38],0x0
00563bcc  e80fa12300                       call   0x79dce0
00563bd1  8bf0                             mov    esi,eax
00563bd3  6aff                             push   0xffffffff
00563bd5  56                               push   esi
00563bd6  ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
00563bdc  56                               push   esi
00563bdd  ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
00563be3  8b7c2414                         mov    edi,DWORD PTR [esp+0x14]
00563be7  83c760                           add    edi,0x60
00563bea  e831d82e00                       call   0x851420
00563bef  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
00563bf7  85db                             test   ebx,ebx
00563bf9  7429                             je     0x563c24
00563bfb  8d4b04                           lea    ecx,[ebx+0x4]
00563bfe  83caff                           or     edx,0xffffffff
00563c01  f00fc111                         lock xadd DWORD PTR [ecx],edx
00563c05  751d                             jne    0x563c24
00563c07  8b03                             mov    eax,DWORD PTR [ebx]
00563c09  8b10                             mov    edx,DWORD PTR [eax]
00563c0b  8bcb                             mov    ecx,ebx
00563c0d  ffd2                             call   edx
00563c0f  8d4308                           lea    eax,[ebx+0x8]
00563c12  83c9ff                           or     ecx,0xffffffff
00563c15  f00fc108                         lock xadd DWORD PTR [eax],ecx
00563c19  7509                             jne    0x563c24
00563c1b  8b13                             mov    edx,DWORD PTR [ebx]
00563c1d  8b4204                           mov    eax,DWORD PTR [edx+0x4]
00563c20  8bcb                             mov    ecx,ebx
00563c22  ffd0                             call   eax
00563c24  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
00563c28  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00563c2f  59                               pop    ecx
00563c30  5f                               pop    edi
00563c31  5e                               pop    esi
00563c32  5b                               pop    ebx
00563c33  8be5                             mov    esp,ebp
00563c35  5d                               pop    ebp
00563c36  c3                               ret

; A23: CEventActor deleting destructor calls CActor destruction and frees the actor
; VA 004d0ca0..004d0cd1; raw 000d00a0; SHA256 c0c78d2d709118e161b3839624b19a9419deb675f988b3d5618c2ea6d00f2605
004d0ca0  55                               push   ebp
004d0ca1  8bec                             mov    ebp,esp
004d0ca3  56                               push   esi
004d0ca4  8bf1                             mov    esi,ecx
004d0ca6  c70624c8c000                     mov    DWORD PTR [esi],0xc0c824
004d0cac  c786f0000000acc8c000             mov    DWORD PTR [esi+0xf0],0xc0c8ac
004d0cb6  e8d56effff                       call   0x4c7b90
004d0cbb  f6450801                         test   BYTE PTR [ebp+0x8],0x1
004d0cbf  7409                             je     0x4d0cca
004d0cc1  56                               push   esi
004d0cc2  e845053c00                       call   0x89120c
004d0cc7  83c404                           add    esp,0x4
004d0cca  8bc6                             mov    eax,esi
004d0ccc  5e                               pop    esi
004d0ccd  5d                               pop    ebp
004d0cce  c20400                           ret    0x4

; A24: CEventActor v+14 cleanup of model/effect owners
; VA 004c8360..004c83c0; raw 000c7760; SHA256 9625afb6bd0319f6fc2b0eb8a18729312140ae04bae9d2eb0a5a4582c34d2e60
004c8360  53                               push   ebx
004c8361  56                               push   esi
004c8362  57                               push   edi
004c8363  8bf9                             mov    edi,ecx
004c8365  8b875c010000                     mov    eax,DWORD PTR [edi+0x15c]
004c836b  85c0                             test   eax,eax
004c836d  740a                             je     0x4c8379
004c836f  8d4808                           lea    ecx,[eax+0x8]
004c8372  8b01                             mov    eax,DWORD PTR [ecx]
004c8374  8b5008                           mov    edx,DWORD PTR [eax+0x8]
004c8377  ffd2                             call   edx
004c8379  8b8764030000                     mov    eax,DWORD PTR [edi+0x364]
004c837f  85c0                             test   eax,eax
004c8381  740e                             je     0x4c8391
004c8383  83782400                         cmp    DWORD PTR [eax+0x24],0x0
004c8387  8d7024                           lea    esi,[eax+0x24]
004c838a  7405                             je     0x4c8391
004c838c  e85f622f00                       call   0x7be5f0
004c8391  81c764010000                     add    edi,0x164
004c8397  bb80000000                       mov    ebx,0x80
004c839c  8d642400                         lea    esp,[esp+0x0]
004c83a0  8b07                             mov    eax,DWORD PTR [edi]
004c83a2  85c0                             test   eax,eax
004c83a4  740e                             je     0x4c83b4
004c83a6  83782400                         cmp    DWORD PTR [eax+0x24],0x0
004c83aa  8d7024                           lea    esi,[eax+0x24]
004c83ad  7405                             je     0x4c83b4
004c83af  e83c622f00                       call   0x7be5f0
004c83b4  83c704                           add    edi,0x4
004c83b7  4b                               dec    ebx
004c83b8  75e6                             jne    0x4c83a0
004c83ba  5f                               pop    edi
004c83bb  5e                               pop    esi
004c83bc  33c0                             xor    eax,eax
004c83be  5b                               pop    ebx
004c83bf  c3                               ret

; A25: CActor destructor: native resources, containers, FSM states; trailing alignment included
; VA 004c7b90..004c7db0; raw 000c6f90; SHA256 451b1d2f57d21cef62877452ccf296afb43afd6228c6a4a7ee978ae0dde22757
004c7b90  55                               push   ebp
004c7b91  8bec                             mov    ebp,esp
004c7b93  6aff                             push   0xffffffff
004c7b95  68b9d99000                       push   0x90d9b9
004c7b9a  64a100000000                     mov    eax,fs:0x0
004c7ba0  50                               push   eax
004c7ba1  83ec0c                           sub    esp,0xc
004c7ba4  53                               push   ebx
004c7ba5  56                               push   esi
004c7ba6  57                               push   edi
004c7ba7  a1201fd600                       mov    eax,ds:0xd61f20
004c7bac  33c5                             xor    eax,ebp
004c7bae  50                               push   eax
004c7baf  8d45f4                           lea    eax,[ebp-0xc]
004c7bb2  64a300000000                     mov    fs:0x0,eax
004c7bb8  8bd9                             mov    ebx,ecx
004c7bba  895de8                           mov    DWORD PTR [ebp-0x18],ebx
004c7bbd  c7035475c000                     mov    DWORD PTR [ebx],0xc07554
004c7bc3  c783f0000000dc75c000             mov    DWORD PTR [ebx+0xf0],0xc075dc
004c7bcd  c745fc04000000                   mov    DWORD PTR [ebp-0x4],0x4
004c7bd4  8bbb68030000                     mov    edi,DWORD PTR [ebx+0x368]
004c7bda  85ff                             test   edi,edi
004c7bdc  743b                             je     0x4c7c19
004c7bde  897dec                           mov    DWORD PTR [ebp-0x14],edi
004c7be1  c645fc05                         mov    BYTE PTR [ebp-0x4],0x5
004c7be5  8b4704                           mov    eax,DWORD PTR [edi+0x4]
004c7be8  8b08                             mov    ecx,DWORD PTR [eax]
004c7bea  50                               push   eax
004c7beb  51                               push   ecx
004c7bec  8d75f0                           lea    esi,[ebp-0x10]
004c7bef  8bc7                             mov    eax,edi
004c7bf1  e8dabe3600                       call   0x833ad0
004c7bf6  c645fc04                         mov    BYTE PTR [ebp-0x4],0x4
004c7bfa  8b4704                           mov    eax,DWORD PTR [edi+0x4]
004c7bfd  50                               push   eax
004c7bfe  e809963c00                       call   0x89120c
004c7c03  83c404                           add    esp,0x4
004c7c06  57                               push   edi
004c7c07  e800963c00                       call   0x89120c
004c7c0c  83c404                           add    esp,0x4
004c7c0f  c7836803000000000000             mov    DWORD PTR [ebx+0x368],0x0
004c7c19  8bb360010000                     mov    esi,DWORD PTR [ebx+0x160]
004c7c1f  33c0                             xor    eax,eax
004c7c21  898360010000                     mov    DWORD PTR [ebx+0x160],eax
004c7c27  89835c010000                     mov    DWORD PTR [ebx+0x15c],eax
004c7c2d  3bf0                             cmp    esi,eax
004c7c2f  7429                             je     0x4c7c5a
004c7c31  8d4604                           lea    eax,[esi+0x4]
004c7c34  83c9ff                           or     ecx,0xffffffff
004c7c37  f00fc108                         lock xadd DWORD PTR [eax],ecx
004c7c3b  751d                             jne    0x4c7c5a
004c7c3d  8b16                             mov    edx,DWORD PTR [esi]
004c7c3f  8b02                             mov    eax,DWORD PTR [edx]
004c7c41  8bce                             mov    ecx,esi
004c7c43  ffd0                             call   eax
004c7c45  8d4e08                           lea    ecx,[esi+0x8]
004c7c48  83caff                           or     edx,0xffffffff
004c7c4b  f00fc111                         lock xadd DWORD PTR [ecx],edx
004c7c4f  7509                             jne    0x4c7c5a
004c7c51  8b06                             mov    eax,DWORD PTR [esi]
004c7c53  8b5004                           mov    edx,DWORD PTR [eax+0x4]
004c7c56  8bce                             mov    ecx,esi
004c7c58  ffd2                             call   edx
004c7c5a  8bbb64030000                     mov    edi,DWORD PTR [ebx+0x364]
004c7c60  85ff                             test   edi,edi
004c7c62  740f                             je     0x4c7c73
004c7c64  e847010000                       call   0x4c7db0
004c7c69  c7836403000000000000             mov    DWORD PTR [ebx+0x364],0x0
004c7c73  8d8364010000                     lea    eax,[ebx+0x164]
004c7c79  8945f0                           mov    DWORD PTR [ebp-0x10],eax
004c7c7c  c745ec80000000                   mov    DWORD PTR [ebp-0x14],0x80
004c7c83  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
004c7c86  8b39                             mov    edi,DWORD PTR [ecx]
004c7c88  85ff                             test   edi,edi
004c7c8a  743d                             je     0x4c7cc9
004c7c8c  8d7724                           lea    esi,[edi+0x24]
004c7c8f  e85c692f00                       call   0x7be5f0
004c7c94  8b4f28                           mov    ecx,DWORD PTR [edi+0x28]
004c7c97  85c9                             test   ecx,ecx
004c7c99  741c                             je     0x4c7cb7
004c7c9b  8b11                             mov    edx,DWORD PTR [ecx]
004c7c9d  8b4210                           mov    eax,DWORD PTR [edx+0x10]
004c7ca0  ffd0                             call   eax
004c7ca2  8b4f28                           mov    ecx,DWORD PTR [edi+0x28]
004c7ca5  85c9                             test   ecx,ecx
004c7ca7  740e                             je     0x4c7cb7
004c7ca9  8b11                             mov    edx,DWORD PTR [ecx]
004c7cab  8b4208                           mov    eax,DWORD PTR [edx+0x8]
004c7cae  ffd0                             call   eax
004c7cb0  c7472800000000                   mov    DWORD PTR [edi+0x28],0x0
004c7cb7  57                               push   edi
004c7cb8  e84f953c00                       call   0x89120c
004c7cbd  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
004c7cc0  83c404                           add    esp,0x4
004c7cc3  c70100000000                     mov    DWORD PTR [ecx],0x0
004c7cc9  8345f004                         add    DWORD PTR [ebp-0x10],0x4
004c7ccd  ff4dec                           dec    DWORD PTR [ebp-0x14]
004c7cd0  75b1                             jne    0x4c7c83
004c7cd2  8dbbf0030000                     lea    edi,[ebx+0x3f0]
004c7cd8  897dec                           mov    DWORD PTR [ebp-0x14],edi
004c7cdb  c645fc06                         mov    BYTE PTR [ebp-0x4],0x6
004c7cdf  8b4704                           mov    eax,DWORD PTR [edi+0x4]
004c7ce2  8b08                             mov    ecx,DWORD PTR [eax]
004c7ce4  50                               push   eax
004c7ce5  51                               push   ecx
004c7ce6  8d75f0                           lea    esi,[ebp-0x10]
004c7ce9  8bc7                             mov    eax,edi
004c7ceb  e8d0c30800                       call   0x5540c0
004c7cf0  8b7f04                           mov    edi,DWORD PTR [edi+0x4]
004c7cf3  57                               push   edi
004c7cf4  e813953c00                       call   0x89120c
004c7cf9  8dbb78030000                     lea    edi,[ebx+0x378]
004c7cff  83c404                           add    esp,0x4
004c7d02  897dec                           mov    DWORD PTR [ebp-0x14],edi
004c7d05  c645fc07                         mov    BYTE PTR [ebp-0x4],0x7
004c7d09  8b4704                           mov    eax,DWORD PTR [edi+0x4]
004c7d0c  8b08                             mov    ecx,DWORD PTR [eax]
004c7d0e  50                               push   eax
004c7d0f  51                               push   ecx
004c7d10  8d75f0                           lea    esi,[ebp-0x10]
004c7d13  8bc7                             mov    eax,edi
004c7d15  e846240000                       call   0x4ca160
004c7d1a  8b7f04                           mov    edi,DWORD PTR [edi+0x4]
004c7d1d  57                               push   edi
004c7d1e  e8e9943c00                       call   0x89120c
004c7d23  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
004c7d27  8bb360010000                     mov    esi,DWORD PTR [ebx+0x160]
004c7d2d  83c404                           add    esp,0x4
004c7d30  85f6                             test   esi,esi
004c7d32  7429                             je     0x4c7d5d
004c7d34  8d5604                           lea    edx,[esi+0x4]
004c7d37  83c8ff                           or     eax,0xffffffff
004c7d3a  f00fc102                         lock xadd DWORD PTR [edx],eax
004c7d3e  751d                             jne    0x4c7d5d
004c7d40  8b16                             mov    edx,DWORD PTR [esi]
004c7d42  8b02                             mov    eax,DWORD PTR [edx]
004c7d44  8bce                             mov    ecx,esi
004c7d46  ffd0                             call   eax
004c7d48  8d4e08                           lea    ecx,[esi+0x8]
004c7d4b  83caff                           or     edx,0xffffffff
004c7d4e  f00fc111                         lock xadd DWORD PTR [ecx],edx
004c7d52  7509                             jne    0x4c7d5d
004c7d54  8b06                             mov    eax,DWORD PTR [esi]
004c7d56  8b5004                           mov    edx,DWORD PTR [eax+0x4]
004c7d59  8bce                             mov    ecx,esi
004c7d5b  ffd2                             call   edx
004c7d5d  c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
004c7d61  c783f0000000fc75c000             mov    DWORD PTR [ebx+0xf0],0xc075fc
004c7d6b  8db3f4000000                     lea    esi,[ebx+0xf4]
004c7d71  bf19000000                       mov    edi,0x19
004c7d76  8b0e                             mov    ecx,DWORD PTR [esi]
004c7d78  85c9                             test   ecx,ecx
004c7d7a  740e                             je     0x4c7d8a
004c7d7c  8b01                             mov    eax,DWORD PTR [ecx]
004c7d7e  8b10                             mov    edx,DWORD PTR [eax]
004c7d80  6a01                             push   0x1
004c7d82  ffd2                             call   edx
004c7d84  c70600000000                     mov    DWORD PTR [esi],0x0
004c7d8a  83c604                           add    esi,0x4
004c7d8d  4f                               dec    edi
004c7d8e  75e6                             jne    0x4c7d76
004c7d90  89bb58010000                     mov    DWORD PTR [ebx+0x158],edi
004c7d96  c703ac76c000                     mov    DWORD PTR [ebx],0xc076ac
004c7d9c  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004c7d9f  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004c7da6  59                               pop    ecx
004c7da7  5f                               pop    edi
004c7da8  5e                               pop    esi
004c7da9  5b                               pop    ebx
004c7daa  8be5                             mov    esp,ebp
004c7dac  5d                               pop    ebp
004c7dad  c3                               ret
004c7dae  cc                               int3
004c7daf  cc                               int3

; A26: map nodes are freed and sentinel links/count restored
; VA 00823850..00823899; raw 00422c50; SHA256 e6c34542ace750d3a671b99b77fbf5367cdaaf2fabade389afd63ff8675556dd
00823850  8b4704                           mov    eax,DWORD PTR [edi+0x4]
00823853  53                               push   ebx
00823854  8b5804                           mov    ebx,DWORD PTR [eax+0x4]
00823857  807b1500                         cmp    BYTE PTR [ebx+0x15],0x0
0082385b  56                               push   esi
0082385c  8bf3                             mov    esi,ebx
0082385e  751e                             jne    0x82387e
00823860  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
00823863  51                               push   ecx
00823864  8bcf                             mov    ecx,edi
00823866  e835b3f1ff                       call   0x73eba0
0082386b  8b36                             mov    esi,DWORD PTR [esi]
0082386d  53                               push   ebx
0082386e  e899d90600                       call   0x89120c
00823873  83c404                           add    esp,0x4
00823876  807e1500                         cmp    BYTE PTR [esi+0x15],0x0
0082387a  8bde                             mov    ebx,esi
0082387c  74e2                             je     0x823860
0082387e  8b4704                           mov    eax,DWORD PTR [edi+0x4]
00823881  894004                           mov    DWORD PTR [eax+0x4],eax
00823884  8b4704                           mov    eax,DWORD PTR [edi+0x4]
00823887  8900                             mov    DWORD PTR [eax],eax
00823889  8b4704                           mov    eax,DWORD PTR [edi+0x4]
0082388c  5e                               pop    esi
0082388d  894008                           mov    DWORD PTR [eax+0x8],eax
00823890  c7470800000000                   mov    DWORD PTR [edi+0x8],0x0
00823897  5b                               pop    ebx
00823898  c3                               ret

; A27: recursive map-node free helper
; VA 0073eba0..0073ebd8; raw 0033dfa0; SHA256 3211dfcfd8af83ce282a49a13e89278e6ceec7f9981bdaae96aaea12dc7e5296
0073eba0  55                               push   ebp
0073eba1  8bec                             mov    ebp,esp
0073eba3  53                               push   ebx
0073eba4  56                               push   esi
0073eba5  57                               push   edi
0073eba6  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0073eba9  807f1500                         cmp    BYTE PTR [edi+0x15],0x0
0073ebad  8bd9                             mov    ebx,ecx
0073ebaf  8bf7                             mov    esi,edi
0073ebb1  751e                             jne    0x73ebd1
0073ebb3  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0073ebb6  50                               push   eax
0073ebb7  8bcb                             mov    ecx,ebx
0073ebb9  e8e2ffffff                       call   0x73eba0
0073ebbe  8b36                             mov    esi,DWORD PTR [esi]
0073ebc0  57                               push   edi
0073ebc1  e846261500                       call   0x89120c
0073ebc6  83c404                           add    esp,0x4
0073ebc9  807e1500                         cmp    BYTE PTR [esi+0x15],0x0
0073ebcd  8bfe                             mov    edi,esi
0073ebcf  74e2                             je     0x73ebb3
0073ebd1  5f                               pop    edi
0073ebd2  5e                               pop    esi
0073ebd3  5b                               pop    ebx
0073ebd4  5d                               pop    ebp
0073ebd5  c20400                           ret    0x4

; A28: ShowObject Lua closure
; VA 00569640..0056969d; raw 00168a40; SHA256 d8fb399f56b5a43fbc8fb79fa35e5ba6f0bf01eef3d3cfc879c7743e2ef1c22e
00569640  55                               push   ebp
00569641  8bec                             mov    ebp,esp
00569643  6aff                             push   0xffffffff
00569645  68c8839300                       push   0x9383c8
0056964a  64a100000000                     mov    eax,fs:0x0
00569650  50                               push   eax
00569651  83ec0c                           sub    esp,0xc
00569654  a1201fd600                       mov    eax,ds:0xd61f20
00569659  33c5                             xor    eax,ebp
0056965b  50                               push   eax
0056965c  8d45f4                           lea    eax,[ebp-0xc]
0056965f  64a300000000                     mov    fs:0x0,eax
00569665  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00569668  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0056966b  33c0                             xor    eax,eax
0056966d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00569670  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00569673  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00569676  8b0dfc27fe00                     mov    ecx,DWORD PTR ds:0xfe27fc
0056967c  51                               push   ecx
0056967d  8d55e8                           lea    edx,[ebp-0x18]
00569680  52                               push   edx
00569681  e89a0b0000                       call   0x56a220
00569686  83c408                           add    esp,0x8
00569689  b801000000                       mov    eax,0x1
0056968e  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00569691  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00569698  59                               pop    ecx
00569699  8be5                             mov    esp,ebp
0056969b  5d                               pop    ebp
0056969c  c3                               ret

; A29: ShowObject numeric/numeric-string conversion; booleans fall back to zero
; VA 0056a220..0056a2fc; raw 00169620; SHA256 312edefa624d80e8bf02f8e383c616c82323c5721fbf005601373182f8bde52f
0056a220  55                               push   ebp
0056a221  8bec                             mov    ebp,esp
0056a223  83ec24                           sub    esp,0x24
0056a226  a17827fe00                       mov    eax,ds:0xfe2778
0056a22b  53                               push   ebx
0056a22c  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0056a22f  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a231  56                               push   esi
0056a232  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0056a235  57                               push   edi
0056a236  83c8ff                           or     eax,0xffffffff
0056a239  e8b2ae1800                       call   0x6f50f0
0056a23e  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a241  83f903                           cmp    ecx,0x3
0056a244  742a                             je     0x56a270
0056a246  83f904                           cmp    ecx,0x4
0056a249  0f858e000000                     jne    0x56a2dd
0056a24f  8b30                             mov    esi,DWORD PTR [eax]
0056a251  83c610                           add    esi,0x10
0056a254  8d7df0                           lea    edi,[ebp-0x10]
0056a257  e804d51800                       call   0x6f7760
0056a25c  85c0                             test   eax,eax
0056a25e  747d                             je     0x56a2dd
0056a260  dd45f0                           fld    QWORD PTR [ebp-0x10]
0056a263  c745e403000000                   mov    DWORD PTR [ebp-0x1c],0x3
0056a26a  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0056a26d  8d45dc                           lea    eax,[ebp-0x24]
0056a270  dd00                             fld    QWORD PTR [eax]
0056a272  dd5df0                           fstp   QWORD PTR [ebp-0x10]
0056a275  dd45f0                           fld    QWORD PTR [ebp-0x10]
0056a278  db5d08                           fistp  DWORD PTR [ebp+0x8]
0056a27b  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0056a27e  894df4                           mov    DWORD PTR [ebp-0xc],ecx
0056a281  8b0b                             mov    ecx,DWORD PTR [ebx]
0056a283  b8feffffff                       mov    eax,0xfffffffe
0056a288  e863ae1800                       call   0x6f50f0
0056a28d  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056a290  83f903                           cmp    ecx,0x3
0056a293  7426                             je     0x56a2bb
0056a295  83f904                           cmp    ecx,0x4
0056a298  754c                             jne    0x56a2e6
0056a29a  8b30                             mov    esi,DWORD PTR [eax]
0056a29c  83c610                           add    esi,0x10
0056a29f  8d7df8                           lea    edi,[ebp-0x8]
0056a2a2  e8b9d41800                       call   0x6f7760
0056a2a7  85c0                             test   eax,eax
0056a2a9  743b                             je     0x56a2e6
0056a2ab  dd45f8                           fld    QWORD PTR [ebp-0x8]
0056a2ae  c745e403000000                   mov    DWORD PTR [ebp-0x1c],0x3
0056a2b5  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0056a2b8  8d45dc                           lea    eax,[ebp-0x24]
0056a2bb  dd00                             fld    QWORD PTR [eax]
0056a2bd  dd5de4                           fstp   QWORD PTR [ebp-0x1c]
0056a2c0  dd45e4                           fld    QWORD PTR [ebp-0x1c]
0056a2c3  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0056a2c6  8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
0056a2c9  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0056a2cc  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0056a2cf  52                               push   edx
0056a2d0  50                               push   eax
0056a2d1  ff550c                           call   DWORD PTR [ebp+0xc]
0056a2d4  5f                               pop    edi
0056a2d5  5e                               pop    esi
0056a2d6  33c0                             xor    eax,eax
0056a2d8  5b                               pop    ebx
0056a2d9  8be5                             mov    esp,ebp
0056a2db  5d                               pop    ebp
0056a2dc  c3                               ret
0056a2dd  c745f400000000                   mov    DWORD PTR [ebp-0xc],0x0
0056a2e4  eb9b                             jmp    0x56a281
0056a2e6  8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
0056a2e9  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
0056a2ec  33c0                             xor    eax,eax
0056a2ee  52                               push   edx
0056a2ef  50                               push   eax
0056a2f0  ff550c                           call   DWORD PTR [ebp+0xc]
0056a2f3  5f                               pop    edi
0056a2f4  5e                               pop    esi
0056a2f5  33c0                             xor    eax,eax
0056a2f7  5b                               pop    ebx
0056a2f8  8be5                             mov    esp,ebp
0056a2fa  5d                               pop    ebp
0056a2fb  c3                               ret

; A30: ShowObject writes only selected actor +42C
; VA 00564900..0056493b; raw 00163d00; SHA256 ecf1710e9a859ba6d307ee47ed50096ff4a70861f5b8e9e1a2de1c97205e7b70
00564900  55                               push   ebp
00564901  8bec                             mov    ebp,esp
00564903  51                               push   ecx
00564904  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00564907  56                               push   esi
00564908  8bf1                             mov    esi,ecx
0056490a  8d4d08                           lea    ecx,[ebp+0x8]
0056490d  894508                           mov    DWORD PTR [ebp+0x8],eax
00564910  51                               push   ecx
00564911  8d4e18                           lea    ecx,[esi+0x18]
00564914  8d45fc                           lea    eax,[ebp-0x4]
00564917  e8e4a52c00                       call   0x82ef00
0056491c  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0056491f  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
00564922  5e                               pop    esi
00564923  7410                             je     0x564935
00564925  8b4010                           mov    eax,DWORD PTR [eax+0x10]
00564928  85c0                             test   eax,eax
0056492a  7409                             je     0x564935
0056492c  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0056492f  89902c040000                     mov    DWORD PTR [eax+0x42c],edx
00564935  8be5                             mov    esp,ebp
00564937  5d                               pop    ebp
00564938  c20800                           ret    0x8

; A31: CEventActor render gate on +42C
; VA 004d0fc0..004d0fd1; raw 000d03c0; SHA256 a08db1e266dab47a4a1f2aac2f7bfbcbe73849187a8541caf9504e050135c469
004d0fc0  83b92c04000000                   cmp    DWORD PTR [ecx+0x42c],0x0
004d0fc7  7405                             je     0x4d0fce
004d0fc9  e92279ffff                       jmp    0x4c88f0
004d0fce  33c0                             xor    eax,eax
004d0fd0  c3                               ret

; A32: Q actor render traversal invokes actor v+28
; VA 005616f0..00561753; raw 00160af0; SHA256 cd5ba6a2fdf5c5551d2ae8d295e50bd3b2fe446c928557e092ccebd4a48c8f79
005616f0  56                               push   esi
005616f1  57                               push   edi
005616f2  8b781c                           mov    edi,DWORD PTR [eax+0x1c]
005616f5  8b37                             mov    esi,DWORD PTR [edi]
005616f7  3bf7                             cmp    esi,edi
005616f9  7453                             je     0x56174e
005616fb  eb03                             jmp    0x561700
005616fd  8d4900                           lea    ecx,[ecx+0x0]
00561700  8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
00561703  8b11                             mov    edx,DWORD PTR [ecx]
00561705  8b4228                           mov    eax,DWORD PTR [edx+0x28]
00561708  ffd0                             call   eax
0056170a  807e1500                         cmp    BYTE PTR [esi+0x15],0x0
0056170e  753a                             jne    0x56174a
00561710  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00561713  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561717  7516                             jne    0x56172f
00561719  8bf0                             mov    esi,eax
0056171b  8b06                             mov    eax,DWORD PTR [esi]
0056171d  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561721  7527                             jne    0x56174a
00561723  8bf0                             mov    esi,eax
00561725  8b06                             mov    eax,DWORD PTR [esi]
00561727  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0056172b  74f6                             je     0x561723
0056172d  eb1b                             jmp    0x56174a
0056172f  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00561732  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561736  7510                             jne    0x561748
00561738  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0056173b  750b                             jne    0x561748
0056173d  8bf0                             mov    esi,eax
0056173f  8b4004                           mov    eax,DWORD PTR [eax+0x4]
00561742  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561746  74f0                             je     0x561738
00561748  8bf0                             mov    esi,eax
0056174a  3bf7                             cmp    esi,edi
0056174c  75b2                             jne    0x561700
0056174e  5f                               pop    edi
0056174f  33c0                             xor    eax,eax
00561751  5e                               pop    esi
00561752  c3                               ret

; A33: CEventActor update does not test the show flag
; VA 004d0f80..004d0f95; raw 000d0380; SHA256 2fe1b769a7f55ced52e856dd4afdf28defe7514b79986f42c2fd5344cf207eeb
004d0f80  56                               push   esi
004d0f81  57                               push   edi
004d0f82  8bf1                             mov    esi,ecx
004d0f84  e8f775ffff                       call   0x4c8580
004d0f89  8bf8                             mov    edi,eax
004d0f8b  e840feffff                       call   0x4d0dd0
004d0f90  8bc7                             mov    eax,edi
004d0f92  5f                               pop    edi
004d0f93  5e                               pop    esi
004d0f94  c3                               ret

; A34: Q actor update traversal is independent of show flag
; VA 005615e0..0056163e; raw 001609e0; SHA256 941279f7e39a75b203911dbf6218192c0e82a909f0f864940c610e6a68692f29
005615e0  8b7f1c                           mov    edi,DWORD PTR [edi+0x1c]
005615e3  8b37                             mov    esi,DWORD PTR [edi]
005615e5  3bf7                             cmp    esi,edi
005615e7  7455                             je     0x56163e
005615e9  8da42400000000                   lea    esp,[esp+0x0]
005615f0  8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
005615f3  8b11                             mov    edx,DWORD PTR [ecx]
005615f5  8b4220                           mov    eax,DWORD PTR [edx+0x20]
005615f8  ffd0                             call   eax
005615fa  807e1500                         cmp    BYTE PTR [esi+0x15],0x0
005615fe  753a                             jne    0x56163a
00561600  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00561603  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561607  7516                             jne    0x56161f
00561609  8bf0                             mov    esi,eax
0056160b  8b06                             mov    eax,DWORD PTR [esi]
0056160d  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561611  7527                             jne    0x56163a
00561613  8bf0                             mov    esi,eax
00561615  8b06                             mov    eax,DWORD PTR [esi]
00561617  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0056161b  74f6                             je     0x561613
0056161d  eb1b                             jmp    0x56163a
0056161f  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00561622  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561626  7510                             jne    0x561638
00561628  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0056162b  750b                             jne    0x561638
0056162d  8bf0                             mov    esi,eax
0056162f  8b4004                           mov    eax,DWORD PTR [eax+0x4]
00561632  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561636  74f0                             je     0x561628
00561638  8bf0                             mov    esi,eax
0056163a  3bf7                             cmp    esi,edi
0056163c  75b2                             jne    0x5615f0

; A35: contrast: lb.SetActorAvatar uses world map FAB138, not Q map
; VA 004a0bde..004a0c0b; raw 0009ffde; SHA256 93013a6f74c6d58c56d7dfa85942eb6ab8ce61cee410893f4d74f4dd5f061461
004a0bde  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004a0be1  8d4c2404                         lea    ecx,[esp+0x4]
004a0be5  89442404                         mov    DWORD PTR [esp+0x4],eax
004a0be9  51                               push   ecx
004a0bea  8d44240c                         lea    eax,[esp+0xc]
004a0bee  b938b1fa00                       mov    ecx,0xfab138
004a0bf3  e808e33800                       call   0x82ef00
004a0bf8  8b442408                         mov    eax,DWORD PTR [esp+0x8]
004a0bfc  3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
004a0c02  742f                             je     0x4a0c33
004a0c04  8b4010                           mov    eax,DWORD PTR [eax+0x10]
004a0c07  85c0                             test   eax,eax
004a0c09  7428                             je     0x4a0c33

; A36: CEventActor resource initialization, fixed FSM event and presentation fields
; VA 004d0fe0..004d104e; raw 000d03e0; SHA256 d3e0a85bfb3fd0a38f6a842e6bb1993b60739ba096515a2393ac86d7e7e29ddc
004d0fe0  57                               push   edi
004d0fe1  6a01                             push   0x1
004d0fe3  56                               push   esi
004d0fe4  e8076effff                       call   0x4c7df0
004d0fe9  8d8ef0000000                     lea    ecx,[esi+0xf0]
004d0fef  8bf8                             mov    edi,eax
004d0ff1  8b01                             mov    eax,DWORD PTR [ecx]
004d0ff3  8b5008                           mov    edx,DWORD PTR [eax+0x8]
004d0ff6  6a14                             push   0x14
004d0ff8  ffd2                             call   edx
004d0ffa  8b8668030000                     mov    eax,DWORD PTR [esi+0x368]
004d1000  85c0                             test   eax,eax
004d1002  7407                             je     0x4d100b
004d1004  c7402400000000                   mov    DWORD PTR [eax+0x24],0x0
004d100b  83be5c01000000                   cmp    DWORD PTR [esi+0x15c],0x0
004d1012  742a                             je     0x4d103e
004d1014  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
004d101a  8b4818                           mov    ecx,DWORD PTR [eax+0x18]
004d101d  6a00                             push   0x0
004d101f  6a00                             push   0x0
004d1021  81c118790000                     add    ecx,0x7918
004d1027  51                               push   ecx
004d1028  50                               push   eax
004d1029  e812622d00                       call   0x7a7240
004d102e  8b965c010000                     mov    edx,DWORD PTR [esi+0x15c]
004d1034  c7823c01000000000000             mov    DWORD PTR [edx+0x13c],0x0
004d103e  8bc7                             mov    eax,edi
004d1040  5f                               pop    edi
004d1041  c3                               ret
004d1042  cc                               int3
004d1043  cc                               int3
004d1044  cc                               int3
004d1045  cc                               int3
004d1046  cc                               int3
004d1047  cc                               int3
004d1048  cc                               int3
004d1049  cc                               int3
004d104a  cc                               int3
004d104b  cc                               int3
004d104c  cc                               int3
004d104d  cc                               int3

; A37: direction virtual takes the argument low byte
; VA 004c8c30..004c8c40; raw 000c8030; SHA256 ea2c5e4b2c272bbf69b25395af84f2e0beee255e89eb773523a1eebfdee6d911
004c8c30  55                               push   ebp
004c8c31  8bec                             mov    ebp,esp
004c8c33  8a4508                           mov    al,BYTE PTR [ebp+0x8]
004c8c36  8881b0000000                     mov    BYTE PTR [ecx+0xb0],al
004c8c3c  5d                               pop    ebp
004c8c3d  c20400                           ret    0x4

; A38: existing Stop route reaches DeleteAllObject before camera override cleanup
; VA 00562687..005626a2; raw 00161a87; SHA256 19ff34f78f037b9eb3adb02b4f6d5acbe7eefceb7318f093a98b9e6b179fec1d
00562687  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0056268b  e810190000                       call   0x563fa0
00562690  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
00562694  e8d7130000                       call   0x563a70
00562699  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0056269d  e85e040000                       call   0x562b00

; A39: Q.MoveObject registrar
; VA 00566600..00566699; raw 00165a00; SHA256 942f768b5bc3524d162a56a7f1d5dde2653d1989a246a153d1225cc9b68e2462
00566600  55                               push   ebp
00566601  8bec                             mov    ebp,esp
00566603  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566606  53                               push   ebx
00566607  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0056660d  56                               push   esi
0056660e  8b33                             mov    esi,DWORD PTR [ebx]
00566610  57                               push   edi
00566611  8b38                             mov    edi,DWORD PTR [eax]
00566613  b8eed8ffff                       mov    eax,0xffffd8ee
00566618  c705a827fe00d0325600             mov    DWORD PTR ds:0xfe27a8,0x5632d0
00566622  e859f01800                       call   0x6f5680
00566627  8b03                             mov    eax,DWORD PTR [ebx]
00566629  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056662c  83e810                           sub    eax,0x10
0056662f  3dc8bfc000                       cmp    eax,0xc0bfc8
00566634  7406                             je     0x56663c
00566636  83780805                         cmp    DWORD PTR [eax+0x8],0x5
0056663a  7414                             je     0x566650
0056663c  57                               push   edi
0056663d  68c426c400                       push   0xc426c4
00566642  e876ca3200                       call   0x8930bd
00566647  8b1b                             mov    ebx,DWORD PTR [ebx]
00566649  83c408                           add    esp,0x8
0056664c  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
00566650  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
00566656  8b37                             mov    esi,DWORD PTR [edi]
00566658  68f4a2d600                       push   0xd6a2f4
0056665d  e8aeee1800                       call   0x6f5510
00566662  8b37                             mov    esi,DWORD PTR [edi]
00566664  83c404                           add    esp,0x4
00566667  6a00                             push   0x0
00566669  68608e5600                       push   0x568e60
0056666e  e83def1800                       call   0x6f55b0
00566673  8b0f                             mov    ecx,DWORD PTR [edi]
00566675  51                               push   ecx
00566676  b8fdffffff                       mov    eax,0xfffffffd
0056667b  e870f11800                       call   0x6f57f0
00566680  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
00566686  8b02                             mov    eax,DWORD PTR [edx]
00566688  83c40c                           add    esp,0xc
0056668b  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0056668f  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566692  5f                               pop    edi
00566693  5e                               pop    esi
00566694  5b                               pop    ebx
00566695  5d                               pop    ebp
00566696  c20400                           ret    0x4

; A40: MoveObject Lua closure
; VA 00568e60..00568eb6; raw 00168260; SHA256 158947236c991069eb1668059ad09b2f6d455a9a3cf069912684ceac57a78f0f
00568e60  55                               push   ebp
00568e61  8bec                             mov    ebp,esp
00568e63  6aff                             push   0xffffffff
00568e65  68c8839300                       push   0x9383c8
00568e6a  64a100000000                     mov    eax,fs:0x0
00568e70  50                               push   eax
00568e71  83ec0c                           sub    esp,0xc
00568e74  a1201fd600                       mov    eax,ds:0xd61f20
00568e79  33c5                             xor    eax,ebp
00568e7b  50                               push   eax
00568e7c  8d45f4                           lea    eax,[ebp-0xc]
00568e7f  64a300000000                     mov    fs:0x0,eax
00568e85  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00568e88  8945e8                           mov    DWORD PTR [ebp-0x18],eax
00568e8b  33c0                             xor    eax,eax
00568e8d  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00568e90  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00568e93  8d4de8                           lea    ecx,[ebp-0x18]
00568e96  51                               push   ecx
00568e97  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00568e9a  e8011c0000                       call   0x56aaa0
00568e9f  83c404                           add    esp,0x4
00568ea2  b801000000                       mov    eax,0x1
00568ea7  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00568eaa  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00568eb1  59                               pop    ecx
00568eb2  8be5                             mov    esp,ebp
00568eb4  5d                               pop    ebp
00568eb5  c3                               ret

; A41: MoveObject four-argument marshaller and numeric fallback branches
; VA 0056aaa0..0056ac2a; raw 00169ea0; SHA256 c6dae13484da3594740a994a026b8c06eb9d3187f8738c55ec8b32937e45f84e
0056aaa0  55                               push   ebp
0056aaa1  8bec                             mov    ebp,esp
0056aaa3  83ec34                           sub    esp,0x34
0056aaa6  a1a827fe00                       mov    eax,ds:0xfe27a8
0056aaab  8b0d7827fe00                     mov    ecx,DWORD PTR ds:0xfe2778
0056aab1  53                               push   ebx
0056aab2  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0056aab5  56                               push   esi
0056aab6  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0056aab9  894df0                           mov    DWORD PTR [ebp-0x10],ecx
0056aabc  8b0b                             mov    ecx,DWORD PTR [ebx]
0056aabe  57                               push   edi
0056aabf  83c8ff                           or     eax,0xffffffff
0056aac2  e829a61800                       call   0x6f50f0
0056aac7  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056aaca  83f903                           cmp    ecx,0x3
0056aacd  742e                             je     0x56aafd
0056aacf  83f904                           cmp    ecx,0x4
0056aad2  0f8534010000                     jne    0x56ac0c
0056aad8  8b30                             mov    esi,DWORD PTR [eax]
0056aada  83c610                           add    esi,0x10
0056aadd  8d7ddc                           lea    edi,[ebp-0x24]
0056aae0  e87bcc1800                       call   0x6f7760
0056aae5  85c0                             test   eax,eax
0056aae7  0f841f010000                     je     0x56ac0c
0056aaed  dd45dc                           fld    QWORD PTR [ebp-0x24]
0056aaf0  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
0056aaf7  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0056aafa  8d45cc                           lea    eax,[ebp-0x34]
0056aafd  dd00                             fld    QWORD PTR [eax]
0056aaff  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0056ab02  dd45dc                           fld    QWORD PTR [ebp-0x24]
0056ab05  db5d08                           fistp  DWORD PTR [ebp+0x8]
0056ab08  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0056ab0b  8955f4                           mov    DWORD PTR [ebp-0xc],edx
0056ab0e  8b03                             mov    eax,DWORD PTR [ebx]
0056ab10  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056ab13  8b48e8                           mov    ecx,DWORD PTR [eax-0x18]
0056ab16  83e820                           sub    eax,0x20
0056ab19  83f903                           cmp    ecx,0x3
0056ab1c  742e                             je     0x56ab4c
0056ab1e  83f904                           cmp    ecx,0x4
0056ab21  0f85f1000000                     jne    0x56ac18
0056ab27  8b30                             mov    esi,DWORD PTR [eax]
0056ab29  83c610                           add    esi,0x10
0056ab2c  8d7ddc                           lea    edi,[ebp-0x24]
0056ab2f  e82ccc1800                       call   0x6f7760
0056ab34  85c0                             test   eax,eax
0056ab36  0f84dc000000                     je     0x56ac18
0056ab3c  dd45dc                           fld    QWORD PTR [ebp-0x24]
0056ab3f  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
0056ab46  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0056ab49  8d45cc                           lea    eax,[ebp-0x34]
0056ab4c  dd00                             fld    QWORD PTR [eax]
0056ab4e  8b03                             mov    eax,DWORD PTR [ebx]
0056ab50  dd5de4                           fstp   QWORD PTR [ebp-0x1c]
0056ab53  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056ab56  8b48d8                           mov    ecx,DWORD PTR [eax-0x28]
0056ab59  83e830                           sub    eax,0x30
0056ab5c  83f903                           cmp    ecx,0x3
0056ab5f  742e                             je     0x56ab8f
0056ab61  83f904                           cmp    ecx,0x4
0056ab64  0f85b5000000                     jne    0x56ac1f
0056ab6a  8b30                             mov    esi,DWORD PTR [eax]
0056ab6c  83c610                           add    esi,0x10
0056ab6f  8d7ddc                           lea    edi,[ebp-0x24]
0056ab72  e8e9cb1800                       call   0x6f7760
0056ab77  85c0                             test   eax,eax
0056ab79  0f84a0000000                     je     0x56ac1f
0056ab7f  dd45dc                           fld    QWORD PTR [ebp-0x24]
0056ab82  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
0056ab89  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0056ab8c  8d45cc                           lea    eax,[ebp-0x34]
0056ab8f  dd00                             fld    QWORD PTR [eax]
0056ab91  8b0b                             mov    ecx,DWORD PTR [ebx]
0056ab93  dd5ddc                           fstp   QWORD PTR [ebp-0x24]
0056ab96  b8fcffffff                       mov    eax,0xfffffffc
0056ab9b  e850a51800                       call   0x6f50f0
0056aba0  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056aba3  83f903                           cmp    ecx,0x3
0056aba6  7426                             je     0x56abce
0056aba8  83f904                           cmp    ecx,0x4
0056abab  7579                             jne    0x56ac26
0056abad  8b30                             mov    esi,DWORD PTR [eax]
0056abaf  83c610                           add    esi,0x10
0056abb2  8d7df8                           lea    edi,[ebp-0x8]
0056abb5  e8a6cb1800                       call   0x6f7760
0056abba  85c0                             test   eax,eax
0056abbc  7468                             je     0x56ac26
0056abbe  dd45f8                           fld    QWORD PTR [ebp-0x8]
0056abc1  c745d403000000                   mov    DWORD PTR [ebp-0x2c],0x3
0056abc8  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0056abcb  8d45cc                           lea    eax,[ebp-0x34]
0056abce  dd00                             fld    QWORD PTR [eax]
0056abd0  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0056abd3  dd45d4                           fld    QWORD PTR [ebp-0x2c]
0056abd6  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0056abd9  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0056abdc  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0056abdf  dd45e4                           fld    QWORD PTR [ebp-0x1c]
0056abe2  d95df4                           fstp   DWORD PTR [ebp-0xc]
0056abe5  51                               push   ecx
0056abe6  d945f4                           fld    DWORD PTR [ebp-0xc]
0056abe9  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0056abec  83ec08                           sub    esp,0x8
0056abef  d95c2404                         fstp   DWORD PTR [esp+0x4]
0056abf3  dd45dc                           fld    QWORD PTR [ebp-0x24]
0056abf6  d95df4                           fstp   DWORD PTR [ebp-0xc]
0056abf9  d945f4                           fld    DWORD PTR [ebp-0xc]
0056abfc  d91c24                           fstp   DWORD PTR [esp]
0056abff  50                               push   eax
0056ac00  ff55ec                           call   DWORD PTR [ebp-0x14]
0056ac03  5f                               pop    edi
0056ac04  5e                               pop    esi
0056ac05  33c0                             xor    eax,eax
0056ac07  5b                               pop    ebx
0056ac08  8be5                             mov    esp,ebp
0056ac0a  5d                               pop    ebp
0056ac0b  c3                               ret
0056ac0c  c745f400000000                   mov    DWORD PTR [ebp-0xc],0x0
0056ac13  e9f6feffff                       jmp    0x56ab0e
0056ac18  d9ee                             fldz
0056ac1a  e92fffffff                       jmp    0x56ab4e
0056ac1f  d9ee                             fldz
0056ac21  e96bffffff                       jmp    0x56ab91
0056ac26  33c0                             xor    eax,eax
0056ac28  ebb2                             jmp    0x56abdc
