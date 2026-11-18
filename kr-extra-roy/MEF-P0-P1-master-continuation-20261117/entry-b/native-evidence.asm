[B01] normal page +B4 binding 0x596010..0x5960a8
  0x596010  55                             push   ebp
  0x596011  8bec                           mov    ebp,esp
  0x596013  6aff                           push   0xffffffff
  0x596015  68c0749400                     push   0x9474c0
  0x59601a  64a100000000                   mov    eax,fs:0x0
  0x596020  50                             push   eax
  0x596021  83ec14                         sub    esp,0x14
  0x596024  53                             push   ebx
  0x596025  56                             push   esi
  0x596026  57                             push   edi
  0x596027  a1201fd600                     mov    eax,ds:0xd61f20
  0x59602c  33c5                           xor    eax,ebp
  0x59602e  50                             push   eax
  0x59602f  8d45f4                         lea    eax,[ebp-0xc]
  0x596032  64a300000000                   mov    fs:0x0,eax
  0x596038  8bf1                           mov    esi,ecx
  0x59603a  33db                           xor    ebx,ebx
  0x59603c  895de4                         mov    DWORD PTR [ebp-0x1c],ebx
  0x59603f  895de8                         mov    DWORD PTR [ebp-0x18],ebx
  0x596042  895dec                         mov    DWORD PTR [ebp-0x14],ebx
  0x596045  c745e00c92c100                 mov    DWORD PTR [ebp-0x20],0xc1920c
  0x59604c  391d70fcf700                   cmp    DWORD PTR ds:0xf7fc70,ebx
  0x596052  7406                           je     0x59605a
  0x596054  891d70fcf700                   mov    DWORD PTR ds:0xf7fc70,ebx
  0x59605a  c745fc01000000                 mov    DWORD PTR [ebp-0x4],0x1
  0x596061  e85a1b0000                     call   0x597bc0
  0x596066  8d8eb4000000                   lea    ecx,[esi+0xb4]
  0x59606c  51                             push   ecx
  0x59606d  8bc8                           mov    ecx,eax
  0x59606f  8d7de0                         lea    edi,[ebp-0x20]
  0x596072  e8c93e0100                     call   0x5a9f40
  0x596077  56                             push   esi
  0x596078  8bf7                           mov    esi,edi
  0x59607a  e8f155e7ff                     call   0x40b670
  0x59607f  8b45e4                         mov    eax,DWORD PTR [ebp-0x1c]
  0x596082  c745e0e429bf00                 mov    DWORD PTR [ebp-0x20],0xbf29e4
  0x596089  3bc3                           cmp    eax,ebx
  0x59608b  7409                           je     0x596096
  0x59608d  50                             push   eax
  0x59608e  e879b12f00                     call   0x89120c
  0x596093  83c404                         add    esp,0x4
  0x596096  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x596099  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x5960a0  59                             pop    ecx
  0x5960a1  5f                             pop    edi
  0x5960a2  5e                             pop    esi
  0x5960a3  5b                             pop    ebx
  0x5960a4  8be5                           mov    esp,ebp
  0x5960a6  5d                             pop    ebp
  0x5960a7  c3                             ret

[B02] cached descriptor getter 0x597bc0..0x597c94
  0x597bc0  55                             push   ebp
  0x597bc1  8bec                           mov    ebp,esp
  0x597bc3  6aff                           push   0xffffffff
  0x597bc5  68a9929400                     push   0x9492a9
  0x597bca  64a100000000                   mov    eax,fs:0x0
  0x597bd0  50                             push   eax
  0x597bd1  83ec08                         sub    esp,0x8
  0x597bd4  56                             push   esi
  0x597bd5  57                             push   edi
  0x597bd6  a1201fd600                     mov    eax,ds:0xd61f20
  0x597bdb  33c5                           xor    eax,ebp
  0x597bdd  50                             push   eax
  0x597bde  8d45f4                         lea    eax,[ebp-0xc]
  0x597be1  64a300000000                   mov    fs:0x0,eax
  0x597be7  a15c2cfe00                     mov    eax,ds:0xfe2c5c
  0x597bec  85c0                           test   eax,eax
  0x597bee  0f858f000000                   jne    0x597c83
  0x597bf4  6a10                           push   0x10
  0x597bf6  e86d962f00                     call   0x891268
  0x597bfb  83c404                         add    esp,0x4
  0x597bfe  8945f0                         mov    DWORD PTR [ebp-0x10],eax
  0x597c01  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
  0x597c08  85c0                           test   eax,eax
  0x597c0a  7408                           je     0x597c14
  0x597c0c  50                             push   eax
  0x597c0d  e80e010000                     call   0x597d20
  0x597c12  eb02                           jmp    0x597c16
  0x597c14  33c0                           xor    eax,eax
  0x597c16  83ceff                         or     esi,0xffffffff
  0x597c19  8bc8                           mov    ecx,eax
  0x597c1b  8975fc                         mov    DWORD PTR [ebp-0x4],esi
  0x597c1e  b801000000                     mov    eax,0x1
  0x597c23  890d5c2cfe00                   mov    DWORD PTR ds:0xfe2c5c,ecx
  0x597c29  8405d4affa00                   test   BYTE PTR ds:0xfaafd4,al
  0x597c2f  7524                           jne    0x597c55
  0x597c31  0905d4affa00                   or     DWORD PTR ds:0xfaafd4,eax
  0x597c37  8945fc                         mov    DWORD PTR [ebp-0x4],eax
  0x597c3a  e87163ebff                     call   0x44dfb0
  0x597c3f  6810cdbc00                     push   0xbccd10
  0x597c44  e8d1a62f00                     call   0x89231a
  0x597c49  8975fc                         mov    DWORD PTR [ebp-0x4],esi
  0x597c4c  8b0d5c2cfe00                   mov    ecx,DWORD PTR ds:0xfe2c5c
  0x597c52  83c404                         add    esp,0x4
  0x597c55  8b01                           mov    eax,DWORD PTR [ecx]
  0x597c57  8b5010                         mov    edx,DWORD PTR [eax+0x10]
  0x597c5a  8bf1                           mov    esi,ecx
  0x597c5c  ffd2                           call   edx
  0x597c5e  8b4004                         mov    eax,DWORD PTR [eax+0x4]
  0x597c61  8975f0                         mov    DWORD PTR [ebp-0x10],esi
  0x597c64  8d7dec                         lea    edi,[ebp-0x14]
  0x597c67  beecaffa00                     mov    esi,0xfaafec
  0x597c6c  8945ec                         mov    DWORD PTR [ebp-0x14],eax
  0x597c6f  e8ac72feff                     call   0x57ef20
  0x597c74  50                             push   eax
  0x597c75  56                             push   esi
  0x597c76  8d75ec                         lea    esi,[ebp-0x14]
  0x597c79  e882752900                     call   0x82f200
  0x597c7e  a15c2cfe00                     mov    eax,ds:0xfe2c5c
  0x597c83  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x597c86  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x597c8d  59                             pop    ecx
  0x597c8e  5f                             pop    edi
  0x597c8f  5e                             pop    esi
  0x597c90  8be5                           mov    esp,ebp
  0x597c92  5d                             pop    ebp
  0x597c93  c3                             ret

[B03] UICachingData<212,CScenarioTalkBox> allocation and constructor 0x597d20..0x597da4
  0x597d20  55                             push   ebp
  0x597d21  8bec                           mov    ebp,esp
  0x597d23  6aff                           push   0xffffffff
  0x597d25  68f0a79300                     push   0x93a7f0
  0x597d2a  64a100000000                   mov    eax,fs:0x0
  0x597d30  50                             push   eax
  0x597d31  83ec08                         sub    esp,0x8
  0x597d34  56                             push   esi
  0x597d35  a1201fd600                     mov    eax,ds:0xd61f20
  0x597d3a  33c5                           xor    eax,ebp
  0x597d3c  50                             push   eax
  0x597d3d  8d45f4                         lea    eax,[ebp-0xc]
  0x597d40  64a300000000                   mov    fs:0x0,eax
  0x597d46  8b7508                         mov    esi,DWORD PTR [ebp+0x8]
  0x597d49  c7460400000000                 mov    DWORD PTR [esi+0x4],0x0
  0x597d50  c7460800000000                 mov    DWORD PTR [esi+0x8],0x0
  0x597d57  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
  0x597d5e  68ac000000                     push   0xac
  0x597d63  c70614b5c100                   mov    DWORD PTR [esi],0xc1b514
  0x597d69  e8faa22f00                     call   0x892068
  0x597d6e  83c404                         add    esp,0x4
  0x597d71  8945f0                         mov    DWORD PTR [ebp-0x10],eax
  0x597d74  c645fc01                       mov    BYTE PTR [ebp-0x4],0x1
  0x597d78  85c0                           test   eax,eax
  0x597d7a  7408                           je     0x597d84
  0x597d7c  50                             push   eax
  0x597d7d  e8ee501200                     call   0x6bce70
  0x597d82  eb02                           jmp    0x597d86
  0x597d84  33c0                           xor    eax,eax
  0x597d86  89460c                         mov    DWORD PTR [esi+0xc],eax
  0x597d89  c74604d4000000                 mov    DWORD PTR [esi+0x4],0xd4
  0x597d90  8bc6                           mov    eax,esi
  0x597d92  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x597d95  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x597d9c  59                             pop    ecx
  0x597d9d  5e                             pop    esi
  0x597d9e  8be5                           mov    esp,ebp
  0x597da0  5d                             pop    ebp
  0x597da1  c20400                         ret    0x4

[B04] typed talk object constructs namespace receiver; reused constructor, new caller linkage 0x6bce70..0x6bcf51
  0x6bce70  55                             push   ebp
  0x6bce71  8bec                           mov    ebp,esp
  0x6bce73  6aff                           push   0xffffffff
  0x6bce75  68b6a79300                     push   0x93a7b6
  0x6bce7a  64a100000000                   mov    eax,fs:0x0
  0x6bce80  50                             push   eax
  0x6bce81  51                             push   ecx
  0x6bce82  53                             push   ebx
  0x6bce83  56                             push   esi
  0x6bce84  a1201fd600                     mov    eax,ds:0xd61f20
  0x6bce89  33c5                           xor    eax,ebp
  0x6bce8b  50                             push   eax
  0x6bce8c  8d45f4                         lea    eax,[ebp-0xc]
  0x6bce8f  64a300000000                   mov    fs:0x0,eax
  0x6bce95  8b7508                         mov    esi,DWORD PTR [ebp+0x8]
  0x6bce98  8bce                           mov    ecx,esi
  0x6bce9a  e851830800                     call   0x7451f0
  0x6bce9f  33db                           xor    ebx,ebx
  0x6bcea1  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
  0x6bcea4  b801000000                     mov    eax,0x1
  0x6bcea9  c70644ebc300                   mov    DWORD PTR [esi],0xc3eb44
  0x6bceaf  899e80000000                   mov    DWORD PTR [esi+0x80],ebx
  0x6bceb5  899e84000000                   mov    DWORD PTR [esi+0x84],ebx
  0x6bcebb  899e88000000                   mov    DWORD PTR [esi+0x88],ebx
  0x6bcec1  899e8c000000                   mov    DWORD PTR [esi+0x8c],ebx
  0x6bcec7  899e90000000                   mov    DWORD PTR [esi+0x90],ebx
  0x6bcecd  899e94000000                   mov    DWORD PTR [esi+0x94],ebx
  0x6bced3  899e98000000                   mov    DWORD PTR [esi+0x98],ebx
  0x6bced9  899e9c000000                   mov    DWORD PTR [esi+0x9c],ebx
  0x6bcedf  899ea0000000                   mov    DWORD PTR [esi+0xa0],ebx
  0x6bcee5  8405d4f3fd00                   test   BYTE PTR ds:0xfdf3d4,al
  0x6bceeb  751e                           jne    0x6bcf0b
  0x6bceed  0905d4f3fd00                   or     DWORD PTR ds:0xfdf3d4,eax
  0x6bcef3  8845fc                         mov    BYTE PTR [ebp-0x4],al
  0x6bcef6  e885740300                     call   0x6f4380
  0x6bcefb  68d0e6bc00                     push   0xbce6d0
  0x6bcf00  e815541d00                     call   0x89231a
  0x6bcf05  83c404                         add    esp,0x4
  0x6bcf08  885dfc                         mov    BYTE PTR [ebp-0x4],bl
  0x6bcf0b  8d45f0                         lea    eax,[ebp-0x10]
  0x6bcf0e  68c8f3fd00                     push   0xfdf3c8
  0x6bcf13  50                             push   eax
  0x6bcf14  8bc6                           mov    eax,esi
  0x6bcf16  e8050b0000                     call   0x6bda20
  0x6bcf1b  83c408                         add    esp,0x8
  0x6bcf1e  50                             push   eax
  0x6bcf1f  e8dc0b0000                     call   0x6bdb00
  0x6bcf24  50                             push   eax
  0x6bcf25  e8760c0000                     call   0x6bdba0
  0x6bcf2a  50                             push   eax
  0x6bcf2b  e8100d0000                     call   0x6bdc40
  0x6bcf30  50                             push   eax
  0x6bcf31  e8aa0d0000                     call   0x6bdce0
  0x6bcf36  50                             push   eax
  0x6bcf37  e8440e0000                     call   0x6bdd80
  0x6bcf3c  8bc6                           mov    eax,esi
  0x6bcf3e  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x6bcf41  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x6bcf48  59                             pop    ecx
  0x6bcf49  5e                             pop    esi
  0x6bcf4a  5b                             pop    ebx
  0x6bcf4b  8be5                           mov    esp,ebp
  0x6bcf4d  5d                             pop    ebp
  0x6bcf4e  c20400                         ret    0x4

[B05] ScenarioTalkTable namespace installation and receiver writer 0x6bda20..0x6bdaf5
  0x6bda20  55                             push   ebp
  0x6bda21  8bec                           mov    ebp,esp
  0x6bda23  51                             push   ecx
  0x6bda24  53                             push   ebx
  0x6bda25  8b5d0c                         mov    ebx,DWORD PTR [ebp+0xc]
  0x6bda28  56                             push   esi
  0x6bda29  8b33                           mov    esi,DWORD PTR [ebx]
  0x6bda2b  a38031fe00                     mov    ds:0xfe3180,eax
  0x6bda30  8b4610                         mov    eax,DWORD PTR [esi+0x10]
  0x6bda33  8b4844                         mov    ecx,DWORD PTR [eax+0x44]
  0x6bda36  57                             push   edi
  0x6bda37  891d7c31fe00                   mov    DWORD PTR ds:0xfe317c,ebx
  0x6bda3d  3b4840                         cmp    ecx,DWORD PTR [eax+0x40]
  0x6bda40  7207                           jb     0x6bda49
  0x6bda42  8bc6                           mov    eax,esi
  0x6bda44  e857d90300                     call   0x6fb3a0
  0x6bda49  8b7e08                         mov    edi,DWORD PTR [esi+0x8]
  0x6bda4c  6a00                           push   0x0
  0x6bda4e  6a00                           push   0x0
  0x6bda50  56                             push   esi
  0x6bda51  e84abf0300                     call   0x6f99a0
  0x6bda56  8907                           mov    DWORD PTR [edi],eax
  0x6bda58  c7470805000000                 mov    DWORD PTR [edi+0x8],0x5
  0x6bda5f  83460810                       add    DWORD PTR [esi+0x8],0x10
  0x6bda63  8b33                           mov    esi,DWORD PTR [ebx]
  0x6bda65  83c40c                         add    esp,0xc
  0x6bda68  bf28ebc300                     mov    edi,0xc3eb28
  0x6bda6d  b8eed8ffff                     mov    eax,0xffffd8ee
  0x6bda72  e8197d0300                     call   0x6f5790
  0x6bda77  8b33                           mov    esi,DWORD PTR [ebx]
  0x6bda79  b8eed8ffff                     mov    eax,0xffffd8ee
  0x6bda7e  e8fd7b0300                     call   0x6f5680
  0x6bda83  8b03                           mov    eax,DWORD PTR [ebx]
  0x6bda85  8b4008                         mov    eax,DWORD PTR [eax+0x8]
  0x6bda88  83e810                         sub    eax,0x10
  0x6bda8b  bff0ffffff                     mov    edi,0xfffffff0
  0x6bda90  3dc8bfc000                     cmp    eax,0xc0bfc8
  0x6bda95  7406                           je     0x6bda9d
  0x6bda97  83780805                       cmp    DWORD PTR [eax+0x8],0x5
  0x6bda9b  7417                           je     0x6bdab4
  0x6bda9d  6828ebc300                     push   0xc3eb28
  0x6bdaa2  68c426c400                     push   0xc426c4
  0x6bdaa7  e811561d00                     call   0x8930bd
  0x6bdaac  8b03                           mov    eax,DWORD PTR [ebx]
  0x6bdaae  83c408                         add    esp,0x8
  0x6bdab1  017808                         add    DWORD PTR [eax+0x8],edi
  0x6bdab4  8b33                           mov    esi,DWORD PTR [ebx]
  0x6bdab6  682462c000                     push   0xc06224
  0x6bdabb  e8507a0300                     call   0x6f5510
  0x6bdac0  8b33                           mov    esi,DWORD PTR [ebx]
  0x6bdac2  83c404                         add    esp,0x4
  0x6bdac5  6a00                           push   0x0
  0x6bdac7  6820de6b00                     push   0x6bde20
  0x6bdacc  e8df7a0300                     call   0x6f55b0
  0x6bdad1  8b13                           mov    edx,DWORD PTR [ebx]
  0x6bdad3  52                             push   edx
  0x6bdad4  b8fdffffff                     mov    eax,0xfffffffd
  0x6bdad9  e8127d0300                     call   0x6f57f0
  0x6bdade  8b1b                           mov    ebx,DWORD PTR [ebx]
  0x6bdae0  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
  0x6bdae3  83c40c                         add    esp,0xc
  0x6bdae6  017b08                         add    DWORD PTR [ebx+0x8],edi
  0x6bdae9  5f                             pop    edi
  0x6bdaea  5e                             pop    esi
  0x6bdaeb  c70028ebc300                   mov    DWORD PTR [eax],0xc3eb28
  0x6bdaf1  5b                             pop    ebx
  0x6bdaf2  59                             pop    ecx
  0x6bdaf3  5d                             pop    ebp
  0x6bdaf4  c3                             ret

[B06] destructor clears wrapper and receiver and Lua namespace 0x6bcf90..0x6bd047
  0x6bcf90  55                             push   ebp
  0x6bcf91  8bec                           mov    ebp,esp
  0x6bcf93  6aff                           push   0xffffffff
  0x6bcf95  68b6a79300                     push   0x93a7b6
  0x6bcf9a  64a100000000                   mov    eax,fs:0x0
  0x6bcfa0  50                             push   eax
  0x6bcfa1  53                             push   ebx
  0x6bcfa2  56                             push   esi
  0x6bcfa3  57                             push   edi
  0x6bcfa4  a1201fd600                     mov    eax,ds:0xd61f20
  0x6bcfa9  33c5                           xor    eax,ebp
  0x6bcfab  50                             push   eax
  0x6bcfac  8d45f4                         lea    eax,[ebp-0xc]
  0x6bcfaf  64a300000000                   mov    fs:0x0,eax
  0x6bcfb5  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
  0x6bcfb8  c70344ebc300                   mov    DWORD PTR [ebx],0xc3eb44
  0x6bcfbe  33f6                           xor    esi,esi
  0x6bcfc0  b801000000                     mov    eax,0x1
  0x6bcfc5  8975fc                         mov    DWORD PTR [ebp-0x4],esi
  0x6bcfc8  8405d4f3fd00                   test   BYTE PTR ds:0xfdf3d4,al
  0x6bcfce  751f                           jne    0x6bcfef
  0x6bcfd0  0905d4f3fd00                   or     DWORD PTR ds:0xfdf3d4,eax
  0x6bcfd6  8845fc                         mov    BYTE PTR [ebp-0x4],al
  0x6bcfd9  e8a2730300                     call   0x6f4380
  0x6bcfde  68d0e6bc00                     push   0xbce6d0
  0x6bcfe3  e832531d00                     call   0x89231a
  0x6bcfe8  83c404                         add    esp,0x4
  0x6bcfeb  c645fc00                       mov    BYTE PTR [ebp-0x4],0x0
  0x6bcfef  a1c8f3fd00                     mov    eax,ds:0xfdf3c8
  0x6bcff4  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
  0x6bcff7  897108                         mov    DWORD PTR [ecx+0x8],esi
  0x6bcffa  83400810                       add    DWORD PTR [eax+0x8],0x10
  0x6bcffe  89357c31fe00                   mov    DWORD PTR ds:0xfe317c,esi
  0x6bd004  89358031fe00                   mov    DWORD PTR ds:0xfe3180,esi
  0x6bd00a  8b35c8f3fd00                   mov    esi,DWORD PTR ds:0xfdf3c8
  0x6bd010  bf28ebc300                     mov    edi,0xc3eb28
  0x6bd015  b8eed8ffff                     mov    eax,0xffffd8ee
  0x6bd01a  e871870300                     call   0x6f5790
  0x6bd01f  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
  0x6bd026  8bcb                           mov    ecx,ebx
  0x6bd028  c7039c90c400                   mov    DWORD PTR [ebx],0xc4909c
  0x6bd02e  e84d830800                     call   0x745380
  0x6bd033  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x6bd036  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x6bd03d  59                             pop    ecx
  0x6bd03e  5f                             pop    edi
  0x6bd03f  5e                             pop    esi
  0x6bd040  5b                             pop    ebx
  0x6bd041  8be5                           mov    esp,ebp
  0x6bd043  5d                             pop    ebp
  0x6bd044  c20400                         ret    0x4

[B07] Lua-only Rebind callback 0x6bde20..0x6bde32
  0x6bde20  a17c31fe00                     mov    eax,ds:0xfe317c
  0x6bde25  e8864ddeff                     call   0x4a2bb0
  0x6bde2a  a38031fe00                     mov    ds:0xfe3180,eax
  0x6bde2f  33c0                           xor    eax,eax
  0x6bde31  c3                             ret

[B08] Rebind numeric stack converter 0x4a2bb0..0x4a2c0c
  0x4a2bb0  55                             push   ebp
  0x4a2bb1  8bec                           mov    ebp,esp
  0x4a2bb3  8b08                           mov    ecx,DWORD PTR [eax]
  0x4a2bb5  83ec18                         sub    esp,0x18
  0x4a2bb8  56                             push   esi
  0x4a2bb9  57                             push   edi
  0x4a2bba  83c8ff                         or     eax,0xffffffff
  0x4a2bbd  e82e252500                     call   0x6f50f0
  0x4a2bc2  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
  0x4a2bc5  83f903                         cmp    ecx,0x3
  0x4a2bc8  7426                           je     0x4a2bf0
  0x4a2bca  83f904                         cmp    ecx,0x4
  0x4a2bcd  7535                           jne    0x4a2c04
  0x4a2bcf  8b30                           mov    esi,DWORD PTR [eax]
  0x4a2bd1  83c610                         add    esi,0x10
  0x4a2bd4  8d7df8                         lea    edi,[ebp-0x8]
  0x4a2bd7  e8844b2500                     call   0x6f7760
  0x4a2bdc  85c0                           test   eax,eax
  0x4a2bde  7424                           je     0x4a2c04
  0x4a2be0  dd45f8                         fld    QWORD PTR [ebp-0x8]
  0x4a2be3  c745f003000000                 mov    DWORD PTR [ebp-0x10],0x3
  0x4a2bea  dd5de8                         fstp   QWORD PTR [ebp-0x18]
  0x4a2bed  8d45e8                         lea    eax,[ebp-0x18]
  0x4a2bf0  dd00                           fld    QWORD PTR [eax]
  0x4a2bf2  dd5df0                         fstp   QWORD PTR [ebp-0x10]
  0x4a2bf5  dd45f0                         fld    QWORD PTR [ebp-0x10]
  0x4a2bf8  db5dfc                         fistp  DWORD PTR [ebp-0x4]
  0x4a2bfb  8b45fc                         mov    eax,DWORD PTR [ebp-0x4]
  0x4a2bfe  5f                             pop    edi
  0x4a2bff  5e                             pop    esi
  0x4a2c00  8be5                           mov    esp,ebp
  0x4a2c02  5d                             pop    ebp
  0x4a2c03  c3                             ret
  0x4a2c04  5f                             pop    edi
  0x4a2c05  33c0                           xor    eax,eax
  0x4a2c07  5e                             pop    esi
  0x4a2c08  8be5                           mov    esp,ebp
  0x4a2c0a  5d                             pop    ebp
  0x4a2c0b  c3                             ret

[B09] inherited XML reader, full body 0x748c40..0x74945d
  0x748c40  55                             push   ebp
  0x748c41  8bec                           mov    ebp,esp
  0x748c43  83e4f8                         and    esp,0xfffffff8
  0x748c46  6aff                           push   0xffffffff
  0x748c48  686b0b9200                     push   0x920b6b
  0x748c4d  64a100000000                   mov    eax,fs:0x0
  0x748c53  50                             push   eax
  0x748c54  81eca8000000                   sub    esp,0xa8
  0x748c5a  a1201fd600                     mov    eax,ds:0xd61f20
  0x748c5f  33c4                           xor    eax,esp
  0x748c61  898424a0000000                 mov    DWORD PTR [esp+0xa0],eax
  0x748c68  53                             push   ebx
  0x748c69  56                             push   esi
  0x748c6a  57                             push   edi
  0x748c6b  a1201fd600                     mov    eax,ds:0xd61f20
  0x748c70  33c4                           xor    eax,esp
  0x748c72  50                             push   eax
  0x748c73  8d8424b8000000                 lea    eax,[esp+0xb8]
  0x748c7a  64a300000000                   mov    fs:0x0,eax
  0x748c80  8b7508                         mov    esi,DWORD PTR [ebp+0x8]
  0x748c83  8bd9                           mov    ebx,ecx
  0x748c85  6a00                           push   0x0
  0x748c87  ba206bc400                     mov    edx,0xc46b20
  0x748c8c  8bce                           mov    ecx,esi
  0x748c8e  89742428                       mov    DWORD PTR [esp+0x28],esi
  0x748c92  e819c30100                     call   0x764fb0
  0x748c97  894320                         mov    DWORD PTR [ebx+0x20],eax
  0x748c9a  8b4348                         mov    eax,DWORD PTR [ebx+0x48]
  0x748c9d  83c404                         add    esp,0x4
  0x748ca0  50                             push   eax
  0x748ca1  ba286bc400                     mov    edx,0xc46b28
  0x748ca6  8bce                           mov    ecx,esi
  0x748ca8  e803c30100                     call   0x764fb0
  0x748cad  83c404                         add    esp,0x4
  0x748cb0  6a00                           push   0x0
  0x748cb2  ba306bc400                     mov    edx,0xc46b30
  0x748cb7  8bce                           mov    ecx,esi
  0x748cb9  894348                         mov    DWORD PTR [ebx+0x48],eax
  0x748cbc  e8efc20100                     call   0x764fb0
  0x748cc1  0fb74b5c                       movzx  ecx,WORD PTR [ebx+0x5c]
  0x748cc5  83c404                         add    esp,0x4
  0x748cc8  51                             push   ecx
  0x748cc9  8bce                           mov    ecx,esi
  0x748ccb  894328                         mov    DWORD PTR [ebx+0x28],eax
  0x748cce  e88dc30100                     call   0x765060
  0x748cd3  8b13                           mov    edx,DWORD PTR [ebx]
  0x748cd5  834b2803                       or     DWORD PTR [ebx+0x28],0x3
  0x748cd9  83c404                         add    esp,0x4
  0x748cdc  6689435c                       mov    WORD PTR [ebx+0x5c],ax
  0x748ce0  8b828c000000                   mov    eax,DWORD PTR [edx+0x8c]
  0x748ce6  6a00                           push   0x0
  0x748ce8  8bcb                           mov    ecx,ebx
  0x748cea  ffd0                           call   eax
  0x748cec  8b4328                         mov    eax,DWORD PTR [ebx+0x28]
  0x748cef  a900800000                     test   eax,0x8000
  0x748cf4  7408                           je     0x748cfe
  0x748cf6  3500800000                     xor    eax,0x8000
  0x748cfb  894328                         mov    DWORD PTR [ebx+0x28],eax
  0x748cfe  8b4328                         mov    eax,DWORD PTR [ebx+0x28]
  0x748d01  a900000100                     test   eax,0x10000
  0x748d06  7408                           je     0x748d10
  0x748d08  3500000100                     xor    eax,0x10000
  0x748d0d  894328                         mov    DWORD PTR [ebx+0x28],eax
  0x748d10  8b4328                         mov    eax,DWORD PTR [ebx+0x28]
  0x748d13  a900000200                     test   eax,0x20000
  0x748d18  7408                           je     0x748d22
  0x748d1a  3500000200                     xor    eax,0x20000
  0x748d1f  894328                         mov    DWORD PTR [ebx+0x28],eax
  0x748d22  56                             push   esi
  0x748d23  8d7b08                         lea    edi,[ebx+0x8]
  0x748d26  ba4c6bc400                     mov    edx,0xc46b4c
  0x748d2b  e8e0cf0000                     call   0x755d10
  0x748d30  56                             push   esi
  0x748d31  8d7b2c                         lea    edi,[ebx+0x2c]
  0x748d34  ba586bc400                     mov    edx,0xc46b58
  0x748d39  e8d2cf0000                     call   0x755d10
  0x748d3e  ba0c6bc400                     mov    edx,0xc46b0c
  0x748d43  8d742440                       lea    esi,[esp+0x40]
  0x748d47  e8640aceff                     call   0x4297b0
  0x748d4c  837c245410                     cmp    DWORD PTR [esp+0x54],0x10
  0x748d51  8b442440                       mov    eax,DWORD PTR [esp+0x40]
  0x748d55  7302                           jae    0x748d59
  0x748d57  8bc6                           mov    eax,esi
  0x748d59  50                             push   eax
  0x748d5a  8b442428                       mov    eax,DWORD PTR [esp+0x28]
  0x748d5e  e87d55feff                     call   0x72e2e0
  0x748d63  837c245410                     cmp    DWORD PTR [esp+0x54],0x10
  0x748d68  8bf8                           mov    edi,eax
  0x748d6a  720d                           jb     0x748d79
  0x748d6c  8b4c2440                       mov    ecx,DWORD PTR [esp+0x40]
  0x748d70  51                             push   ecx
  0x748d71  e896841400                     call   0x89120c
  0x748d76  83c404                         add    esp,0x4
  0x748d79  33f6                           xor    esi,esi
  0x748d7b  c74424540f000000               mov    DWORD PTR [esp+0x54],0xf
  0x748d83  89742450                       mov    DWORD PTR [esp+0x50],esi
  0x748d87  c644244000                     mov    BYTE PTR [esp+0x40],0x0
  0x748d8c  3bfe                           cmp    edi,esi
  0x748d8e  747f                           je     0x748e0f
  0x748d90  8d542414                       lea    edx,[esp+0x14]
  0x748d94  52                             push   edx
  0x748d95  ba589ec400                     mov    edx,0xc49e58
  0x748d9a  8bcf                           mov    ecx,edi
  0x748d9c  89742418                       mov    DWORD PTR [esp+0x18],esi
  0x748da0  e8bb0aceff                     call   0x429860
  0x748da5  8b4b1c                         mov    ecx,DWORD PTR [ebx+0x1c]
  0x748da8  83c404                         add    esp,0x4
  0x748dab  3bce                           cmp    ecx,esi
  0x748dad  740c                           je     0x748dbb
  0x748daf  8b01                           mov    eax,DWORD PTR [ecx]
  0x748db1  8b501c                         mov    edx,DWORD PTR [eax+0x1c]
  0x748db4  6a01                           push   0x1
  0x748db6  ffd2                           call   edx
  0x748db8  89731c                         mov    DWORD PTR [ebx+0x1c],esi
  0x748dbb  8b4c2414                       mov    ecx,DWORD PTR [esp+0x14]
  0x748dbf  8b03                           mov    eax,DWORD PTR [ebx]
  0x748dc1  8b5064                         mov    edx,DWORD PTR [eax+0x64]
  0x748dc4  51                             push   ecx
  0x748dc5  8bcb                           mov    ecx,ebx
  0x748dc7  ffd2                           call   edx
  0x748dc9  8bf0                           mov    esi,eax
  0x748dcb  8d442414                       lea    eax,[esp+0x14]
  0x748dcf  50                             push   eax
  0x748dd0  ba589ec400                     mov    edx,0xc49e58
  0x748dd5  8bcf                           mov    ecx,edi
  0x748dd7  89731c                         mov    DWORD PTR [ebx+0x1c],esi
  0x748dda  c744241800000000               mov    DWORD PTR [esp+0x18],0x0
  0x748de2  e8790aceff                     call   0x429860
  0x748de7  8b16                           mov    edx,DWORD PTR [esi]
  0x748de9  8b4204                         mov    eax,DWORD PTR [edx+0x4]
  0x748dec  83c404                         add    esp,0x4
  0x748def  8bce                           mov    ecx,esi
  0x748df1  ffd0                           call   eax
  0x748df3  39442414                       cmp    DWORD PTR [esp+0x14],eax
  0x748df7  0f851e060000                   jne    0x74941b
  0x748dfd  8b16                           mov    edx,DWORD PTR [esi]
  0x748dff  8b4214                         mov    eax,DWORD PTR [edx+0x14]
  0x748e02  57                             push   edi
  0x748e03  8bce                           mov    ecx,esi
  0x748e05  ffd0                           call   eax
  0x748e07  84c0                           test   al,al
  0x748e09  0f840c060000                   je     0x74941b
  0x748e0f  ba481fbf00                     mov    edx,0xbf1f48
  0x748e14  8d742440                       lea    esi,[esp+0x40]
  0x748e18  e89309ceff                     call   0x4297b0
  0x748e1d  8b442440                       mov    eax,DWORD PTR [esp+0x40]
  0x748e21  bf10000000                     mov    edi,0x10
  0x748e26  397c2454                       cmp    DWORD PTR [esp+0x54],edi
  0x748e2a  7302                           jae    0x748e2e
  0x748e2c  8bc6                           mov    eax,esi
  0x748e2e  50                             push   eax
  0x748e2f  8b442428                       mov    eax,DWORD PTR [esp+0x28]
  0x748e33  e8a854feff                     call   0x72e2e0
  0x748e38  8bf0                           mov    esi,eax
  0x748e3a  397c2454                       cmp    DWORD PTR [esp+0x54],edi
  0x748e3e  720d                           jb     0x748e4d
  0x748e40  8b4c2440                       mov    ecx,DWORD PTR [esp+0x40]
  0x748e44  51                             push   ecx
  0x748e45  e8c2831400                     call   0x89120c
  0x748e4a  83c404                         add    esp,0x4
  0x748e4d  33ff                           xor    edi,edi
  0x748e4f  c74424540f000000               mov    DWORD PTR [esp+0x54],0xf
  0x748e57  897c2450                       mov    DWORD PTR [esp+0x50],edi
  0x748e5b  c644244000                     mov    BYTE PTR [esp+0x40],0x0
  0x748e60  8974241c                       mov    DWORD PTR [esp+0x1c],esi
  0x748e64  3bf7                           cmp    esi,edi
  0x748e66  0f8417030000                   je     0x749183
  0x748e6c  8d642400                       lea    esp,[esp+0x0]
  0x748e70  8b4c241c                       mov    ecx,DWORD PTR [esp+0x1c]
  0x748e74  8d542420                       lea    edx,[esp+0x20]
  0x748e78  52                             push   edx
  0x748e79  ba589ec400                     mov    edx,0xc49e58
  0x748e7e  897c2424                       mov    DWORD PTR [esp+0x24],edi
  0x748e82  e8d909ceff                     call   0x429860
  0x748e87  83c404                         add    esp,0x4
  0x748e8a  ba286bc400                     mov    edx,0xc46b28
  0x748e8f  8d742478                       lea    esi,[esp+0x78]
  0x748e93  e81809ceff                     call   0x4297b0
  0x748e98  89bc24c0000000                 mov    DWORD PTR [esp+0xc0],edi
  0x748e9f  83bc248c00000010               cmp    DWORD PTR [esp+0x8c],0x10
  0x748ea7  720a                           jb     0x748eb3
  0x748ea9  8b442478                       mov    eax,DWORD PTR [esp+0x78]
  0x748ead  89442414                       mov    DWORD PTR [esp+0x14],eax
  0x748eb1  eb08                           jmp    0x748ebb
  0x748eb3  8d4c2478                       lea    ecx,[esp+0x78]
  0x748eb7  894c2414                       mov    DWORD PTR [esp+0x14],ecx
  0x748ebb  8b4c241c                       mov    ecx,DWORD PTR [esp+0x1c]
  0x748ebf  8b11                           mov    edx,DWORD PTR [ecx]
  0x748ec1  8b4214                         mov    eax,DWORD PTR [edx+0x14]
  0x748ec4  ffd0                           call   eax
  0x748ec6  8bb094000000                   mov    esi,DWORD PTR [eax+0x94]
  0x748ecc  8d7844                         lea    edi,[eax+0x44]
  0x748ecf  3bf7                           cmp    esi,edi
  0x748ed1  7424                           je     0x748ef7
  0x748ed3  837e2810                       cmp    DWORD PTR [esi+0x28],0x10
  0x748ed7  8d4614                         lea    eax,[esi+0x14]
  0x748eda  7202                           jb     0x748ede
  0x748edc  8b00                           mov    eax,DWORD PTR [eax]
  0x748ede  8b4c2414                       mov    ecx,DWORD PTR [esp+0x14]
  0x748ee2  51                             push   ecx
  0x748ee3  50                             push   eax
  0x748ee4  e8c8ad1400                     call   0x893cb1
  0x748ee9  83c408                         add    esp,0x8
  0x748eec  85c0                           test   eax,eax
  0x748eee  7461                           je     0x748f51
  0x748ef0  8b7650                         mov    esi,DWORD PTR [esi+0x50]
  0x748ef3  3bf7                           cmp    esi,edi
  0x748ef5  75dc                           jne    0x748ed3
  0x748ef7  c7442414ffffffff               mov    DWORD PTR [esp+0x14],0xffffffff
  0x748eff  bf10000000                     mov    edi,0x10
  0x748f04  c78424c0000000ffffffff         mov    DWORD PTR [esp+0xc0],0xffffffff
  0x748f0f  39bc248c000000                 cmp    DWORD PTR [esp+0x8c],edi
  0x748f16  720d                           jb     0x748f25
  0x748f18  8b542478                       mov    edx,DWORD PTR [esp+0x78]
  0x748f1c  52                             push   edx
  0x748f1d  e8ea821400                     call   0x89120c
  0x748f22  83c404                         add    esp,0x4
  0x748f25  ba206bc400                     mov    edx,0xc46b20
  0x748f2a  8d742478                       lea    esi,[esp+0x78]
  0x748f2e  e87d08ceff                     call   0x4297b0
  0x748f33  c78424c000000001000000         mov    DWORD PTR [esp+0xc0],0x1
  0x748f3e  39bc248c000000                 cmp    DWORD PTR [esp+0x8c],edi
  0x748f45  7230                           jb     0x748f77
  0x748f47  8b442478                       mov    eax,DWORD PTR [esp+0x78]
  0x748f4b  89442418                       mov    DWORD PTR [esp+0x18],eax
  0x748f4f  eb2e                           jmp    0x748f7f
  0x748f51  85f6                           test   esi,esi
  0x748f53  74a2                           je     0x748ef7
  0x748f55  83c630                         add    esi,0x30
  0x748f58  bf10000000                     mov    edi,0x10
  0x748f5d  397e14                         cmp    DWORD PTR [esi+0x14],edi
  0x748f60  7202                           jb     0x748f64
  0x748f62  8b36                           mov    esi,DWORD PTR [esi]
  0x748f64  85f6                           test   esi,esi
  0x748f66  748f                           je     0x748ef7
  0x748f68  56                             push   esi
  0x748f69  e846881400                     call   0x8917b4
  0x748f6e  83c404                         add    esp,0x4
  0x748f71  89442414                       mov    DWORD PTR [esp+0x14],eax
  0x748f75  eb8d                           jmp    0x748f04
  0x748f77  8d4c2478                       lea    ecx,[esp+0x78]
  0x748f7b  894c2418                       mov    DWORD PTR [esp+0x18],ecx
  0x748f7f  8b4c241c                       mov    ecx,DWORD PTR [esp+0x1c]
  0x748f83  8b11                           mov    edx,DWORD PTR [ecx]
  0x748f85  8b4214                         mov    eax,DWORD PTR [edx+0x14]
  0x748f88  ffd0                           call   eax
  0x748f8a  8bb094000000                   mov    esi,DWORD PTR [eax+0x94]
  0x748f90  8d7844                         lea    edi,[eax+0x44]
  0x748f93  3bf7                           cmp    esi,edi
  0x748f95  7428                           je     0x748fbf
  0x748f97  837e2810                       cmp    DWORD PTR [esi+0x28],0x10
  0x748f9b  8d4614                         lea    eax,[esi+0x14]
  0x748f9e  7202                           jb     0x748fa2
  0x748fa0  8b00                           mov    eax,DWORD PTR [eax]
  0x748fa2  8b4c2418                       mov    ecx,DWORD PTR [esp+0x18]
  0x748fa6  51                             push   ecx
  0x748fa7  50                             push   eax
  0x748fa8  e804ad1400                     call   0x893cb1
  0x748fad  83c408                         add    esp,0x8
  0x748fb0  85c0                           test   eax,eax
  0x748fb2  0f84a0010000                   je     0x749158
  0x748fb8  8b7650                         mov    esi,DWORD PTR [esi+0x50]
  0x748fbb  3bf7                           cmp    esi,edi
  0x748fbd  75d8                           jne    0x748f97
  0x748fbf  83cfff                         or     edi,0xffffffff
  0x748fc2  c78424c0000000ffffffff         mov    DWORD PTR [esp+0xc0],0xffffffff
  0x748fcd  83bc248c00000010               cmp    DWORD PTR [esp+0x8c],0x10
  0x748fd5  720d                           jb     0x748fe4
  0x748fd7  8b542478                       mov    edx,DWORD PTR [esp+0x78]
  0x748fdb  52                             push   edx
  0x748fdc  e82b821400                     call   0x89120c
  0x748fe1  83c404                         add    esp,0x4
  0x748fe4  8b742420                       mov    esi,DWORD PTR [esp+0x20]
  0x748fe8  83feff                         cmp    esi,0xffffffff
  0x748feb  0f84e7000000                   je     0x7490d8
  0x748ff1  8b4b18                         mov    ecx,DWORD PTR [ebx+0x18]
  0x748ff4  c744241800000000               mov    DWORD PTR [esp+0x18],0x0
  0x748ffc  85c9                           test   ecx,ecx
  0x748ffe  7423                           je     0x749023
  0x749000  83ec0c                         sub    esp,0xc
  0x749003  8bc4                           mov    eax,esp
  0x749005  8938                           mov    DWORD PTR [eax],edi
  0x749007  897004                         mov    DWORD PTR [eax+0x4],esi
  0x74900a  8d542424                       lea    edx,[esp+0x24]
  0x74900e  895008                         mov    DWORD PTR [eax+0x8],edx
  0x749011  8b01                           mov    eax,DWORD PTR [ecx]
  0x749013  8b8010010000                   mov    eax,DWORD PTR [eax+0x110]
  0x749019  ffd0                           call   eax
  0x74901b  8b442418                       mov    eax,DWORD PTR [esp+0x18]
  0x74901f  85c0                           test   eax,eax
  0x749021  7516                           jne    0x749039
  0x749023  8b13                           mov    edx,DWORD PTR [ebx]
  0x749025  8b4260                         mov    eax,DWORD PTR [edx+0x60]
  0x749028  56                             push   esi
  0x749029  8bcb                           mov    ecx,ebx
  0x74902b  ffd0                           call   eax
  0x74902d  89442418                       mov    DWORD PTR [esp+0x18],eax
  0x749031  85c0                           test   eax,eax
  0x749033  0f849f000000                   je     0x7490d8
  0x749039  8b4b18                         mov    ecx,DWORD PTR [ebx+0x18]
  0x74903c  8b7c241c                       mov    edi,DWORD PTR [esp+0x1c]
  0x749040  8d542420                       lea    edx,[esp+0x20]
  0x749044  894818                         mov    DWORD PTR [eax+0x18],ecx
  0x749047  8b742418                       mov    esi,DWORD PTR [esp+0x18]
  0x74904b  52                             push   edx
  0x74904c  ba589ec400                     mov    edx,0xc49e58
  0x749051  8bcf                           mov    ecx,edi
  0x749053  c744242400000000               mov    DWORD PTR [esp+0x24],0x0
  0x74905b  e80008ceff                     call   0x429860
  0x749060  8b06                           mov    eax,DWORD PTR [esi]
  0x749062  8b5004                         mov    edx,DWORD PTR [eax+0x4]
  0x749065  83c404                         add    esp,0x4
  0x749068  8bce                           mov    ecx,esi
  0x74906a  ffd2                           call   edx
  0x74906c  39442420                       cmp    DWORD PTR [esp+0x20],eax
  0x749070  0f85a5030000                   jne    0x74941b
  0x749076  8b06                           mov    eax,DWORD PTR [esi]
  0x749078  8b5014                         mov    edx,DWORD PTR [eax+0x14]
  0x74907b  57                             push   edi
  0x74907c  8bce                           mov    ecx,esi
  0x74907e  ffd2                           call   edx
  0x749080  84c0                           test   al,al
  0x749082  0f8493030000                   je     0x74941b
  0x749088  8b442414                       mov    eax,DWORD PTR [esp+0x14]
  0x74908c  8b7c2418                       mov    edi,DWORD PTR [esp+0x18]
  0x749090  8d4c2428                       lea    ecx,[esp+0x28]
  0x749094  89442428                       mov    DWORD PTR [esp+0x28],eax
  0x749098  8d734c                         lea    esi,[ebx+0x4c]
  0x74909b  51                             push   ecx
  0x74909c  8d442430                       lea    eax,[esp+0x30]
  0x7490a0  8bce                           mov    ecx,esi
  0x7490a2  e8595e0e00                     call   0x82ef00
  0x7490a7  8b4350                         mov    eax,DWORD PTR [ebx+0x50]
  0x7490aa  3944242c                       cmp    DWORD PTR [esp+0x2c],eax
  0x7490ae  7528                           jne    0x7490d8
  0x7490b0  8b442414                       mov    eax,DWORD PTR [esp+0x14]
  0x7490b4  8bd7                           mov    edx,edi
  0x7490b6  894748                         mov    DWORD PTR [edi+0x48],eax
  0x7490b9  897c2434                       mov    DWORD PTR [esp+0x34],edi
  0x7490bd  8d7c2430                       lea    edi,[esp+0x30]
  0x7490c1  895a44                         mov    DWORD PTR [edx+0x44],ebx
  0x7490c4  89442430                       mov    DWORD PTR [esp+0x30],eax
  0x7490c8  e8535ee3ff                     call   0x57ef20
  0x7490cd  50                             push   eax
  0x7490ce  56                             push   esi
  0x7490cf  8d742440                       lea    esi,[esp+0x40]
  0x7490d3  e828610e00                     call   0x82f200
  0x7490d8  ba481fbf00                     mov    edx,0xbf1f48
  0x7490dd  8d74245c                       lea    esi,[esp+0x5c]
  0x7490e1  e8ca06ceff                     call   0x4297b0
  0x7490e6  837c247010                     cmp    DWORD PTR [esp+0x70],0x10
  0x7490eb  8b7c245c                       mov    edi,DWORD PTR [esp+0x5c]
  0x7490ef  7302                           jae    0x7490f3
  0x7490f1  8bfe                           mov    edi,esi
  0x7490f3  8b44241c                       mov    eax,DWORD PTR [esp+0x1c]
  0x7490f7  8b7040                         mov    esi,DWORD PTR [eax+0x40]
  0x7490fa  85f6                           test   esi,esi
  0x7490fc  7420                           je     0x74911e
  0x7490fe  837e3410                       cmp    DWORD PTR [esi+0x34],0x10
  0x749102  8d4620                         lea    eax,[esi+0x20]
  0x749105  7202                           jb     0x749109
  0x749107  8b00                           mov    eax,DWORD PTR [eax]
  0x749109  57                             push   edi
  0x74910a  50                             push   eax
  0x74910b  e8a1ab1400                     call   0x893cb1
  0x749110  83c408                         add    esp,0x8
  0x749113  85c0                           test   eax,eax
  0x749115  7409                           je     0x749120
  0x749117  8b7640                         mov    esi,DWORD PTR [esi+0x40]
  0x74911a  85f6                           test   esi,esi
  0x74911c  75e0                           jne    0x7490fe
  0x74911e  33f6                           xor    esi,esi
  0x749120  837c247010                     cmp    DWORD PTR [esp+0x70],0x10
  0x749125  720d                           jb     0x749134
  0x749127  8b4c245c                       mov    ecx,DWORD PTR [esp+0x5c]
  0x74912b  51                             push   ecx
  0x74912c  e8db801400                     call   0x89120c
  0x749131  83c404                         add    esp,0x4
  0x749134  c74424700f000000               mov    DWORD PTR [esp+0x70],0xf
  0x74913c  c744246c00000000               mov    DWORD PTR [esp+0x6c],0x0
  0x749144  c644245c00                     mov    BYTE PTR [esp+0x5c],0x0
  0x749149  8974241c                       mov    DWORD PTR [esp+0x1c],esi
  0x74914d  85f6                           test   esi,esi
  0x74914f  7432                           je     0x749183
  0x749151  33ff                           xor    edi,edi
  0x749153  e918fdffff                     jmp    0x748e70
  0x749158  85f6                           test   esi,esi
  0x74915a  0f845ffeffff                   je     0x748fbf
  0x749160  83c630                         add    esi,0x30
  0x749163  837e1410                       cmp    DWORD PTR [esi+0x14],0x10
  0x749167  7202                           jb     0x74916b
  0x749169  8b36                           mov    esi,DWORD PTR [esi]
  0x74916b  85f6                           test   esi,esi
  0x74916d  0f844cfeffff                   je     0x748fbf
  0x749173  56                             push   esi
  0x749174  e83b861400                     call   0x8917b4
  0x749179  83c404                         add    esp,0x4
  0x74917c  8bf8                           mov    edi,eax
  0x74917e  e93ffeffff                     jmp    0x748fc2
  0x749183  8b4b64                         mov    ecx,DWORD PTR [ebx+0x64]
  0x749186  8b01                           mov    eax,DWORD PTR [ecx]
  0x749188  8909                           mov    DWORD PTR [ecx],ecx
  0x74918a  8b4b64                         mov    ecx,DWORD PTR [ebx+0x64]
  0x74918d  894904                         mov    DWORD PTR [ecx+0x4],ecx
  0x749190  c7436800000000                 mov    DWORD PTR [ebx+0x68],0x0
  0x749197  3b4364                         cmp    eax,DWORD PTR [ebx+0x64]
  0x74919a  7416                           je     0x7491b2
  0x74919c  8d642400                       lea    esp,[esp+0x0]
  0x7491a0  8b30                           mov    esi,DWORD PTR [eax]
  0x7491a2  50                             push   eax
  0x7491a3  e864801400                     call   0x89120c
  0x7491a8  83c404                         add    esp,0x4
  0x7491ab  8bc6                           mov    eax,esi
  0x7491ad  3b7364                         cmp    esi,DWORD PTR [ebx+0x64]
  0x7491b0  75ee                           jne    0x7491a0
  0x7491b2  ba706bc400                     mov    edx,0xc46b70
  0x7491b7  8d74245c                       lea    esi,[esp+0x5c]
  0x7491bb  e8f005ceff                     call   0x4297b0
  0x7491c0  8b44245c                       mov    eax,DWORD PTR [esp+0x5c]
  0x7491c4  be10000000                     mov    esi,0x10
  0x7491c9  39742470                       cmp    DWORD PTR [esp+0x70],esi
  0x7491cd  7304                           jae    0x7491d3
  0x7491cf  8d44245c                       lea    eax,[esp+0x5c]
  0x7491d3  50                             push   eax
  0x7491d4  8b442428                       mov    eax,DWORD PTR [esp+0x28]
  0x7491d8  e80351feff                     call   0x72e2e0
  0x7491dd  8bf8                           mov    edi,eax
  0x7491df  39742470                       cmp    DWORD PTR [esp+0x70],esi
  0x7491e3  720d                           jb     0x7491f2
  0x7491e5  8b54245c                       mov    edx,DWORD PTR [esp+0x5c]
  0x7491e9  52                             push   edx
  0x7491ea  e81d801400                     call   0x89120c
  0x7491ef  83c404                         add    esp,0x4
  0x7491f2  c74424700f000000               mov    DWORD PTR [esp+0x70],0xf
  0x7491fa  c744246c00000000               mov    DWORD PTR [esp+0x6c],0x0
  0x749202  c644245c00                     mov    BYTE PTR [esp+0x5c],0x0
  0x749207  85ff                           test   edi,edi
  0x749209  0f840d010000                   je     0x74931c
  0x74920f  ba8c6bc400                     mov    edx,0xc46b8c
  0x749214  8d742440                       lea    esi,[esp+0x40]
  0x749218  e89305ceff                     call   0x4297b0
  0x74921d  837c245410                     cmp    DWORD PTR [esp+0x54],0x10
  0x749222  8b442440                       mov    eax,DWORD PTR [esp+0x40]
  0x749226  7302                           jae    0x74922a
  0x749228  8bc6                           mov    eax,esi
  0x74922a  50                             push   eax
  0x74922b  8bc7                           mov    eax,edi
  0x74922d  e8ae50feff                     call   0x72e2e0
  0x749232  837c245410                     cmp    DWORD PTR [esp+0x54],0x10
  0x749237  8bf0                           mov    esi,eax
  0x749239  720d                           jb     0x749248
  0x74923b  8b442440                       mov    eax,DWORD PTR [esp+0x40]
  0x74923f  50                             push   eax
  0x749240  e8c77f1400                     call   0x89120c
  0x749245  83c404                         add    esp,0x4
  0x749248  c74424540f000000               mov    DWORD PTR [esp+0x54],0xf
  0x749250  c744245000000000               mov    DWORD PTR [esp+0x50],0x0
  0x749258  c644244000                     mov    BYTE PTR [esp+0x40],0x0
  0x74925d  8bfe                           mov    edi,esi
  0x74925f  85f6                           test   esi,esi
  0x749261  0f84b5000000                   je     0x74931c
  0x749267  eb07                           jmp    0x749270
  0x749269  8da42400000000                 lea    esp,[esp+0x0]
  0x749270  8d4c2414                       lea    ecx,[esp+0x14]
  0x749274  51                             push   ecx
  0x749275  bab06bc400                     mov    edx,0xc46bb0
  0x74927a  8bcf                           mov    ecx,edi
  0x74927c  c7442418ffffffff               mov    DWORD PTR [esp+0x18],0xffffffff
  0x749284  e8d705ceff                     call   0x429860
  0x749289  8b442418                       mov    eax,DWORD PTR [esp+0x18]
  0x74928d  83c404                         add    esp,0x4
  0x749290  83f8ff                         cmp    eax,0xffffffff
  0x749293  742f                           je     0x7492c4
  0x749295  8d54242c                       lea    edx,[esp+0x2c]
  0x749299  8944242c                       mov    DWORD PTR [esp+0x2c],eax
  0x74929d  8d4b4c                         lea    ecx,[ebx+0x4c]
  0x7492a0  52                             push   edx
  0x7492a1  8d44242c                       lea    eax,[esp+0x2c]
  0x7492a5  e8565c0e00                     call   0x82ef00
  0x7492aa  8b4c2428                       mov    ecx,DWORD PTR [esp+0x28]
  0x7492ae  3b4b50                         cmp    ecx,DWORD PTR [ebx+0x50]
  0x7492b1  7405                           je     0x7492b8
  0x7492b3  8b4910                         mov    ecx,DWORD PTR [ecx+0x10]
  0x7492b6  eb02                           jmp    0x7492ba
  0x7492b8  33c9                           xor    ecx,ecx
  0x7492ba  8b03                           mov    eax,DWORD PTR [ebx]
  0x7492bc  8b5070                         mov    edx,DWORD PTR [eax+0x70]
  0x7492bf  51                             push   ecx
  0x7492c0  8bcb                           mov    ecx,ebx
  0x7492c2  ffd2                           call   edx
  0x7492c4  ba8c6bc400                     mov    edx,0xc46b8c
  0x7492c9  8d74245c                       lea    esi,[esp+0x5c]
  0x7492cd  e8de04ceff                     call   0x4297b0
  0x7492d2  837c247010                     cmp    DWORD PTR [esp+0x70],0x10
  0x7492d7  8b44245c                       mov    eax,DWORD PTR [esp+0x5c]
  0x7492db  7302                           jae    0x7492df
  0x7492dd  8bc6                           mov    eax,esi
  0x7492df  50                             push   eax
  0x7492e0  8bc7                           mov    eax,edi
  0x7492e2  e83950feff                     call   0x72e320
  0x7492e7  837c247010                     cmp    DWORD PTR [esp+0x70],0x10
  0x7492ec  8bf0                           mov    esi,eax
  0x7492ee  720d                           jb     0x7492fd
  0x7492f0  8b44245c                       mov    eax,DWORD PTR [esp+0x5c]
  0x7492f4  50                             push   eax
  0x7492f5  e8127f1400                     call   0x89120c
  0x7492fa  83c404                         add    esp,0x4
  0x7492fd  c74424700f000000               mov    DWORD PTR [esp+0x70],0xf
  0x749305  c744246c00000000               mov    DWORD PTR [esp+0x6c],0x0
  0x74930d  c644245c00                     mov    BYTE PTR [esp+0x5c],0x0
  0x749312  8bfe                           mov    edi,esi
  0x749314  85f6                           test   esi,esi
  0x749316  0f8554ffffff                   jne    0x749270
  0x74931c  bac06bc400                     mov    edx,0xc46bc0
  0x749321  8db42494000000                 lea    esi,[esp+0x94]
  0x749328  e88304ceff                     call   0x4297b0
  0x74932d  8b842494000000                 mov    eax,DWORD PTR [esp+0x94]
  0x749334  be10000000                     mov    esi,0x10
  0x749339  39b424a8000000                 cmp    DWORD PTR [esp+0xa8],esi
  0x749340  7307                           jae    0x749349
  0x749342  8d842494000000                 lea    eax,[esp+0x94]
  0x749349  50                             push   eax
  0x74934a  8b442428                       mov    eax,DWORD PTR [esp+0x28]
  0x74934e  e88d4ffeff                     call   0x72e2e0
  0x749353  8bf8                           mov    edi,eax
  0x749355  39b424a8000000                 cmp    DWORD PTR [esp+0xa8],esi
  0x74935c  7210                           jb     0x74936e
  0x74935e  8b8c2494000000                 mov    ecx,DWORD PTR [esp+0x94]
  0x749365  51                             push   ecx
  0x749366  e8a17e1400                     call   0x89120c
  0x74936b  83c404                         add    esp,0x4
  0x74936e  33f6                           xor    esi,esi
  0x749370  c78424a80000000f000000         mov    DWORD PTR [esp+0xa8],0xf
  0x74937b  89b424a4000000                 mov    DWORD PTR [esp+0xa4],esi
  0x749382  c684249400000000               mov    BYTE PTR [esp+0x94],0x0
  0x74938a  3bfe                           cmp    edi,esi
  0x74938c  0f8497000000                   je     0x749429
  0x749392  8b4b3c                         mov    ecx,DWORD PTR [ebx+0x3c]
  0x749395  3bce                           cmp    ecx,esi
  0x749397  742d                           je     0x7493c6
  0x749399  f7432800000400                 test   DWORD PTR [ebx+0x28],0x40000
  0x7493a0  0f8583000000                   jne    0x749429
  0x7493a6  e8d5d7ffff                     call   0x746b80
  0x7493ab  8b4b3c                         mov    ecx,DWORD PTR [ebx+0x3c]
  0x7493ae  e85dd8ffff                     call   0x746c10
  0x7493b3  8b4b3c                         mov    ecx,DWORD PTR [ebx+0x3c]
  0x7493b6  3bce                           cmp    ecx,esi
  0x7493b8  740c                           je     0x7493c6
  0x7493ba  8b11                           mov    edx,DWORD PTR [ecx]
  0x7493bc  8b421c                         mov    eax,DWORD PTR [edx+0x1c]
  0x7493bf  6a01                           push   0x1
  0x7493c1  ffd0                           call   eax
  0x7493c3  89733c                         mov    DWORD PTR [ebx+0x3c],esi
  0x7493c6  f7432800000400                 test   DWORD PTR [ebx+0x28],0x40000
  0x7493cd  755a                           jne    0x749429
  0x7493cf  685c010000                     push   0x15c
  0x7493d4  e88f8c1400                     call   0x892068
  0x7493d9  83c404                         add    esp,0x4
  0x7493dc  8944242c                       mov    DWORD PTR [esp+0x2c],eax
  0x7493e0  c78424c000000002000000         mov    DWORD PTR [esp+0xc0],0x2
  0x7493eb  3bc6                           cmp    eax,esi
  0x7493ed  7409                           je     0x7493f8
  0x7493ef  8bc8                           mov    ecx,eax
  0x7493f1  e83ac00100                     call   0x765430
  0x7493f6  8bf0                           mov    esi,eax
  0x7493f8  c78424c0000000ffffffff         mov    DWORD PTR [esp+0xc0],0xffffffff
  0x749403  e858d80200                     call   0x776c60
  0x749408  84c0                           test   al,al
  0x74940a  7513                           jne    0x74941f
  0x74940c  85f6                           test   esi,esi
  0x74940e  740b                           je     0x74941b
  0x749410  8b16                           mov    edx,DWORD PTR [esi]
  0x749412  8b421c                         mov    eax,DWORD PTR [edx+0x1c]
  0x749415  6a01                           push   0x1
  0x749417  8bce                           mov    ecx,esi
  0x749419  ffd0                           call   eax
  0x74941b  32c0                           xor    al,al
  0x74941d  eb18                           jmp    0x749437
  0x74941f  8b13                           mov    edx,DWORD PTR [ebx]
  0x749421  8b4250                         mov    eax,DWORD PTR [edx+0x50]
  0x749424  56                             push   esi
  0x749425  8bcb                           mov    ecx,ebx
  0x749427  ffd0                           call   eax
  0x749429  8b13                           mov    edx,DWORD PTR [ebx]
  0x74942b  8b8214010000                   mov    eax,DWORD PTR [edx+0x114]
  0x749431  8bcb                           mov    ecx,ebx
  0x749433  ffd0                           call   eax
  0x749435  b001                           mov    al,0x1
  0x749437  8b8c24b8000000                 mov    ecx,DWORD PTR [esp+0xb8]
  0x74943e  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x749445  59                             pop    ecx
  0x749446  5f                             pop    edi
  0x749447  5e                             pop    esi
  0x749448  5b                             pop    ebx
  0x749449  8b8c24a0000000                 mov    ecx,DWORD PTR [esp+0xa0]
  0x749450  33cc                           xor    ecx,esp
  0x749452  e8aa7b1400                     call   0x891001
  0x749457  8be5                           mov    esp,ebp
  0x749459  5d                             pop    ebp
  0x74945a  c20400                         ret    0x4

[B10] bounded rectangle field reader 0x755d10..0x755dbb
  0x755d10  55                             push   ebp
  0x755d11  8bec                           mov    ebp,esp
  0x755d13  83ec20                         sub    esp,0x20
  0x755d16  a1201fd600                     mov    eax,ds:0xd61f20
  0x755d1b  33c5                           xor    eax,ebp
  0x755d1d  8945fc                         mov    DWORD PTR [ebp-0x4],eax
  0x755d20  53                             push   ebx
  0x755d21  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
  0x755d24  56                             push   esi
  0x755d25  8d75e0                         lea    esi,[ebp-0x20]
  0x755d28  e8833acdff                     call   0x4297b0
  0x755d2d  837df410                       cmp    DWORD PTR [ebp-0xc],0x10
  0x755d31  8b45e0                         mov    eax,DWORD PTR [ebp-0x20]
  0x755d34  7302                           jae    0x755d38
  0x755d36  8bc6                           mov    eax,esi
  0x755d38  50                             push   eax
  0x755d39  8bc3                           mov    eax,ebx
  0x755d3b  e8a085fdff                     call   0x72e2e0
  0x755d40  837df410                       cmp    DWORD PTR [ebp-0xc],0x10
  0x755d44  8bf0                           mov    esi,eax
  0x755d46  720c                           jb     0x755d54
  0x755d48  8b45e0                         mov    eax,DWORD PTR [ebp-0x20]
  0x755d4b  50                             push   eax
  0x755d4c  e8bbb41300                     call   0x89120c
  0x755d51  83c404                         add    esp,0x4
  0x755d54  33db                           xor    ebx,ebx
  0x755d56  c745f40f000000                 mov    DWORD PTR [ebp-0xc],0xf
  0x755d5d  895df0                         mov    DWORD PTR [ebp-0x10],ebx
  0x755d60  885de0                         mov    BYTE PTR [ebp-0x20],bl
  0x755d63  3bf3                           cmp    esi,ebx
  0x755d65  7442                           je     0x755da9
  0x755d67  53                             push   ebx
  0x755d68  ba8082c400                     mov    edx,0xc48280
  0x755d6d  8bce                           mov    ecx,esi
  0x755d6f  e83cf20000                     call   0x764fb0
  0x755d74  53                             push   ebx
  0x755d75  ba8c82c400                     mov    edx,0xc4828c
  0x755d7a  8bce                           mov    ecx,esi
  0x755d7c  8907                           mov    DWORD PTR [edi],eax
  0x755d7e  e82df20000                     call   0x764fb0
  0x755d83  53                             push   ebx
  0x755d84  ba9882c400                     mov    edx,0xc48298
  0x755d89  8bce                           mov    ecx,esi
  0x755d8b  894708                         mov    DWORD PTR [edi+0x8],eax
  0x755d8e  e81df20000                     call   0x764fb0
  0x755d93  53                             push   ebx
  0x755d94  baa082c400                     mov    edx,0xc482a0
  0x755d99  8bce                           mov    ecx,esi
  0x755d9b  894704                         mov    DWORD PTR [edi+0x4],eax
  0x755d9e  e80df20000                     call   0x764fb0
  0x755da3  83c410                         add    esp,0x10
  0x755da6  89470c                         mov    DWORD PTR [edi+0xc],eax
  0x755da9  8b4dfc                         mov    ecx,DWORD PTR [ebp-0x4]
  0x755dac  5e                             pop    esi
  0x755dad  33cd                           xor    ecx,ebp
  0x755daf  5b                             pop    ebx
  0x755db0  e84cb21300                     call   0x891001
  0x755db5  8be5                           mov    esp,ebp
  0x755db7  5d                             pop    ebp
  0x755db8  c20400                         ret    0x4

[B11] inherited base object field copier 0x404de0..0x404ec7
  0x404de0  55                             push   ebp
  0x404de1  8bec                           mov    ebp,esp
  0x404de3  53                             push   ebx
  0x404de4  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
  0x404de7  8b4304                         mov    eax,DWORD PTR [ebx+0x4]
  0x404dea  894704                         mov    DWORD PTR [edi+0x4],eax
  0x404ded  8b4b08                         mov    ecx,DWORD PTR [ebx+0x8]
  0x404df0  894f08                         mov    DWORD PTR [edi+0x8],ecx
  0x404df3  8b530c                         mov    edx,DWORD PTR [ebx+0xc]
  0x404df6  89570c                         mov    DWORD PTR [edi+0xc],edx
  0x404df9  8b4310                         mov    eax,DWORD PTR [ebx+0x10]
  0x404dfc  894710                         mov    DWORD PTR [edi+0x10],eax
  0x404dff  8b4b14                         mov    ecx,DWORD PTR [ebx+0x14]
  0x404e02  894f14                         mov    DWORD PTR [edi+0x14],ecx
  0x404e05  8b5318                         mov    edx,DWORD PTR [ebx+0x18]
  0x404e08  895718                         mov    DWORD PTR [edi+0x18],edx
  0x404e0b  8b431c                         mov    eax,DWORD PTR [ebx+0x1c]
  0x404e0e  89471c                         mov    DWORD PTR [edi+0x1c],eax
  0x404e11  8b4b20                         mov    ecx,DWORD PTR [ebx+0x20]
  0x404e14  894f20                         mov    DWORD PTR [edi+0x20],ecx
  0x404e17  8b5324                         mov    edx,DWORD PTR [ebx+0x24]
  0x404e1a  895724                         mov    DWORD PTR [edi+0x24],edx
  0x404e1d  8b4328                         mov    eax,DWORD PTR [ebx+0x28]
  0x404e20  894728                         mov    DWORD PTR [edi+0x28],eax
  0x404e23  8b4b2c                         mov    ecx,DWORD PTR [ebx+0x2c]
  0x404e26  894f2c                         mov    DWORD PTR [edi+0x2c],ecx
  0x404e29  8b5330                         mov    edx,DWORD PTR [ebx+0x30]
  0x404e2c  895730                         mov    DWORD PTR [edi+0x30],edx
  0x404e2f  8b4334                         mov    eax,DWORD PTR [ebx+0x34]
  0x404e32  894734                         mov    DWORD PTR [edi+0x34],eax
  0x404e35  8b4b38                         mov    ecx,DWORD PTR [ebx+0x38]
  0x404e38  894f38                         mov    DWORD PTR [edi+0x38],ecx
  0x404e3b  8b533c                         mov    edx,DWORD PTR [ebx+0x3c]
  0x404e3e  89573c                         mov    DWORD PTR [edi+0x3c],edx
  0x404e41  8b4340                         mov    eax,DWORD PTR [ebx+0x40]
  0x404e44  894740                         mov    DWORD PTR [edi+0x40],eax
  0x404e47  8b4b44                         mov    ecx,DWORD PTR [ebx+0x44]
  0x404e4a  894f44                         mov    DWORD PTR [edi+0x44],ecx
  0x404e4d  8b5348                         mov    edx,DWORD PTR [ebx+0x48]
  0x404e50  8d4b4c                         lea    ecx,[ebx+0x4c]
  0x404e53  8d474c                         lea    eax,[edi+0x4c]
  0x404e56  56                             push   esi
  0x404e57  895748                         mov    DWORD PTR [edi+0x48],edx
  0x404e5a  3bc1                           cmp    eax,ecx
  0x404e5c  741b                           je     0x404e79
  0x404e5e  8b4804                         mov    ecx,DWORD PTR [eax+0x4]
  0x404e61  8b11                           mov    edx,DWORD PTR [ecx]
  0x404e63  51                             push   ecx
  0x404e64  52                             push   edx
  0x404e65  8d7508                         lea    esi,[ebp+0x8]
  0x404e68  e853f21400                     call   0x5540c0
  0x404e6d  8d434c                         lea    eax,[ebx+0x4c]
  0x404e70  50                             push   eax
  0x404e71  8d474c                         lea    eax,[edi+0x4c]
  0x404e74  e807271c00                     call   0x5c7580
  0x404e79  668b435c                       mov    ax,WORD PTR [ebx+0x5c]
  0x404e7d  6689475c                       mov    WORD PTR [edi+0x5c],ax
  0x404e81  8b4b60                         mov    ecx,DWORD PTR [ebx+0x60]
  0x404e84  8d4364                         lea    eax,[ebx+0x64]
  0x404e87  8d7764                         lea    esi,[edi+0x64]
  0x404e8a  894f60                         mov    DWORD PTR [edi+0x60],ecx
  0x404e8d  3bf0                           cmp    esi,eax
  0x404e8f  740f                           je     0x404ea0
  0x404e91  8b5508                         mov    edx,DWORD PTR [ebp+0x8]
  0x404e94  8b00                           mov    eax,DWORD PTR [eax]
  0x404e96  8b08                           mov    ecx,DWORD PTR [eax]
  0x404e98  52                             push   edx
  0x404e99  50                             push   eax
  0x404e9a  51                             push   ecx
  0x404e9b  e8f0feffff                     call   0x404d90
  0x404ea0  8b4370                         mov    eax,DWORD PTR [ebx+0x70]
  0x404ea3  894770                         mov    DWORD PTR [edi+0x70],eax
  0x404ea6  8d4374                         lea    eax,[ebx+0x74]
  0x404ea9  8d7774                         lea    esi,[edi+0x74]
  0x404eac  3bf0                           cmp    esi,eax
  0x404eae  740f                           je     0x404ebf
  0x404eb0  8b5508                         mov    edx,DWORD PTR [ebp+0x8]
  0x404eb3  8b00                           mov    eax,DWORD PTR [eax]
  0x404eb5  8b08                           mov    ecx,DWORD PTR [eax]
  0x404eb7  52                             push   edx
  0x404eb8  50                             push   eax
  0x404eb9  51                             push   ecx
  0x404eba  e8d1feffff                     call   0x404d90
  0x404ebf  5e                             pop    esi
  0x404ec0  8bc7                           mov    eax,edi
  0x404ec2  5b                             pop    ebx
  0x404ec3  5d                             pop    ebp
  0x404ec4  c20400                         ret    0x4

[B12] inherited clone produces base FXUIDummy 0x40eb40..0x40ebc8
  0x40eb40  55                             push   ebp
  0x40eb41  8bec                           mov    ebp,esp
  0x40eb43  6aff                           push   0xffffffff
  0x40eb45  6838b59200                     push   0x92b538
  0x40eb4a  64a100000000                   mov    eax,fs:0x0
  0x40eb50  50                             push   eax
  0x40eb51  51                             push   ecx
  0x40eb52  56                             push   esi
  0x40eb53  57                             push   edi
  0x40eb54  a1201fd600                     mov    eax,ds:0xd61f20
  0x40eb59  33c5                           xor    eax,ebp
  0x40eb5b  50                             push   eax
  0x40eb5c  8d45f4                         lea    eax,[ebp-0xc]
  0x40eb5f  64a300000000                   mov    fs:0x0,eax
  0x40eb65  8bf1                           mov    esi,ecx
  0x40eb67  6880000000                     push   0x80
  0x40eb6c  e8f7344800                     call   0x892068
  0x40eb71  8bf8                           mov    edi,eax
  0x40eb73  83c404                         add    esp,0x4
  0x40eb76  897df0                         mov    DWORD PTR [ebp-0x10],edi
  0x40eb79  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
  0x40eb80  85ff                           test   edi,edi
  0x40eb82  740f                           je     0x40eb93
  0x40eb84  8bcf                           mov    ecx,edi
  0x40eb86  e865663300                     call   0x7451f0
  0x40eb8b  c7079c90c400                   mov    DWORD PTR [edi],0xc4909c
  0x40eb91  eb02                           jmp    0x40eb95
  0x40eb93  33ff                           xor    edi,edi
  0x40eb95  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
  0x40eb9c  8b07                           mov    eax,DWORD PTR [edi]
  0x40eb9e  8b5030                         mov    edx,DWORD PTR [eax+0x30]
  0x40eba1  8bcf                           mov    ecx,edi
  0x40eba3  ffd2                           call   edx
  0x40eba5  56                             push   esi
  0x40eba6  e83562ffff                     call   0x404de0
  0x40ebab  8b07                           mov    eax,DWORD PTR [edi]
  0x40ebad  8b5034                         mov    edx,DWORD PTR [eax+0x34]
  0x40ebb0  56                             push   esi
  0x40ebb1  8bcf                           mov    ecx,edi
  0x40ebb3  ffd2                           call   edx
  0x40ebb5  8bc7                           mov    eax,edi
  0x40ebb7  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x40ebba  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x40ebc1  59                             pop    ecx
  0x40ebc2  5f                             pop    edi
  0x40ebc3  5e                             pop    esi
  0x40ebc4  8be5                           mov    esp,ebp
  0x40ebc6  5d                             pop    ebp
  0x40ebc7  c3                             ret

[B13] inherited deep child/dock clone finalizer 0x7456f0..0x745925
  0x7456f0  55                             push   ebp
  0x7456f1  8bec                           mov    ebp,esp
  0x7456f3  83e4f8                         and    esp,0xfffffff8
  0x7456f6  83ec24                         sub    esp,0x24
  0x7456f9  53                             push   ebx
  0x7456fa  56                             push   esi
  0x7456fb  8bf1                           mov    esi,ecx
  0x7456fd  57                             push   edi
  0x7456fe  8d7e4c                         lea    edi,[esi+0x4c]
  0x745701  8974240c                       mov    DWORD PTR [esp+0xc],esi
  0x745705  e846e10d00                     call   0x823850
  0x74570a  8b4e64                         mov    ecx,DWORD PTR [esi+0x64]
  0x74570d  8b01                           mov    eax,DWORD PTR [ecx]
  0x74570f  8909                           mov    DWORD PTR [ecx],ecx
  0x745711  8b4e64                         mov    ecx,DWORD PTR [esi+0x64]
  0x745714  894904                         mov    DWORD PTR [ecx+0x4],ecx
  0x745717  c7466800000000                 mov    DWORD PTR [esi+0x68],0x0
  0x74571e  3b4664                         cmp    eax,DWORD PTR [esi+0x64]
  0x745721  7412                           je     0x745735
  0x745723  8b38                           mov    edi,DWORD PTR [eax]
  0x745725  50                             push   eax
  0x745726  e8e1ba1400                     call   0x89120c
  0x74572b  83c404                         add    esp,0x4
  0x74572e  8bc7                           mov    eax,edi
  0x745730  3b7e64                         cmp    edi,DWORD PTR [esi+0x64]
  0x745733  75ee                           jne    0x745723
  0x745735  8b4628                         mov    eax,DWORD PTR [esi+0x28]
  0x745738  a900800000                     test   eax,0x8000
  0x74573d  7408                           je     0x745747
  0x74573f  3500800000                     xor    eax,0x8000
  0x745744  894628                         mov    DWORD PTR [esi+0x28],eax
  0x745747  8b4628                         mov    eax,DWORD PTR [esi+0x28]
  0x74574a  a900000100                     test   eax,0x10000
  0x74574f  7408                           je     0x745759
  0x745751  3500000100                     xor    eax,0x10000
  0x745756  894628                         mov    DWORD PTR [esi+0x28],eax
  0x745759  8b4628                         mov    eax,DWORD PTR [esi+0x28]
  0x74575c  a900000200                     test   eax,0x20000
  0x745761  7408                           je     0x74576b
  0x745763  3500000200                     xor    eax,0x20000
  0x745768  894628                         mov    DWORD PTR [esi+0x28],eax
  0x74576b  8b7d08                         mov    edi,DWORD PTR [ebp+0x8]
  0x74576e  8b4f1c                         mov    ecx,DWORD PTR [edi+0x1c]
  0x745771  85c9                           test   ecx,ecx
  0x745773  740a                           je     0x74577f
  0x745775  8b01                           mov    eax,DWORD PTR [ecx]
  0x745777  8b5028                         mov    edx,DWORD PTR [eax+0x28]
  0x74577a  ffd2                           call   edx
  0x74577c  89461c                         mov    DWORD PTR [esi+0x1c],eax
  0x74577f  8b4750                         mov    eax,DWORD PTR [edi+0x50]
  0x745782  8b18                           mov    ebx,DWORD PTR [eax]
  0x745784  8944241c                       mov    DWORD PTR [esp+0x1c],eax
  0x745788  3bd8                           cmp    ebx,eax
  0x74578a  0f84df000000                   je     0x74586f
  0x745790  8b4b10                         mov    ecx,DWORD PTR [ebx+0x10]
  0x745793  8b01                           mov    eax,DWORD PTR [ecx]
  0x745795  8b5028                         mov    edx,DWORD PTR [eax+0x28]
  0x745798  ffd2                           call   edx
  0x74579a  8b5650                         mov    edx,DWORD PTR [esi+0x50]
  0x74579d  8b4a04                         mov    ecx,DWORD PTR [edx+0x4]
  0x7457a0  80791500                       cmp    BYTE PTR [ecx+0x15],0x0
  0x7457a4  89442418                       mov    DWORD PTR [esp+0x18],eax
  0x7457a8  8b430c                         mov    eax,DWORD PTR [ebx+0xc]
  0x7457ab  7517                           jne    0x7457c4
  0x7457ad  8d4900                         lea    ecx,[ecx+0x0]
  0x7457b0  39410c                         cmp    DWORD PTR [ecx+0xc],eax
  0x7457b3  7305                           jae    0x7457ba
  0x7457b5  8b4908                         mov    ecx,DWORD PTR [ecx+0x8]
  0x7457b8  eb04                           jmp    0x7457be
  0x7457ba  8bd1                           mov    edx,ecx
  0x7457bc  8b09                           mov    ecx,DWORD PTR [ecx]
  0x7457be  80791500                       cmp    BYTE PTR [ecx+0x15],0x0
  0x7457c2  74ec                           je     0x7457b0
  0x7457c4  8b7e50                         mov    edi,DWORD PTR [esi+0x50]
  0x7457c7  89542410                       mov    DWORD PTR [esp+0x10],edx
  0x7457cb  3bd7                           cmp    edx,edi
  0x7457cd  740b                           je     0x7457da
  0x7457cf  3b420c                         cmp    eax,DWORD PTR [edx+0xc]
  0x7457d2  7206                           jb     0x7457da
  0x7457d4  8d542410                       lea    edx,[esp+0x10]
  0x7457d8  eb08                           jmp    0x7457e2
  0x7457da  897c2414                       mov    DWORD PTR [esp+0x14],edi
  0x7457de  8d542414                       lea    edx,[esp+0x14]
  0x7457e2  8b12                           mov    edx,DWORD PTR [edx]
  0x7457e4  3bd7                           cmp    edx,edi
  0x7457e6  7534                           jne    0x74581c
  0x7457e8  8b542418                       mov    edx,DWORD PTR [esp+0x18]
  0x7457ec  897244                         mov    DWORD PTR [edx+0x44],esi
  0x7457ef  8d7c2420                       lea    edi,[esp+0x20]
  0x7457f3  8d764c                         lea    esi,[esi+0x4c]
  0x7457f6  894248                         mov    DWORD PTR [edx+0x48],eax
  0x7457f9  89442420                       mov    DWORD PTR [esp+0x20],eax
  0x7457fd  89542424                       mov    DWORD PTR [esp+0x24],edx
  0x745801  e81a97e3ff                     call   0x57ef20
  0x745806  50                             push   eax
  0x745807  8b442410                       mov    eax,DWORD PTR [esp+0x10]
  0x74580b  83c04c                         add    eax,0x4c
  0x74580e  50                             push   eax
  0x74580f  8d742430                       lea    esi,[esp+0x30]
  0x745813  e8e8990e00                     call   0x82f200
  0x745818  8b74240c                       mov    esi,DWORD PTR [esp+0xc]
  0x74581c  807b1500                       cmp    BYTE PTR [ebx+0x15],0x0
  0x745820  7540                           jne    0x745862
  0x745822  8b4308                         mov    eax,DWORD PTR [ebx+0x8]
  0x745825  80781500                       cmp    BYTE PTR [eax+0x15],0x0
  0x745829  7516                           jne    0x745841
  0x74582b  8bd8                           mov    ebx,eax
  0x74582d  8b03                           mov    eax,DWORD PTR [ebx]
  0x74582f  80781500                       cmp    BYTE PTR [eax+0x15],0x0
  0x745833  752d                           jne    0x745862
  0x745835  8bd8                           mov    ebx,eax
  0x745837  8b03                           mov    eax,DWORD PTR [ebx]
  0x745839  80781500                       cmp    BYTE PTR [eax+0x15],0x0
  0x74583d  74f6                           je     0x745835
  0x74583f  eb21                           jmp    0x745862
  0x745841  8b4304                         mov    eax,DWORD PTR [ebx+0x4]
  0x745844  80781500                       cmp    BYTE PTR [eax+0x15],0x0
  0x745848  7516                           jne    0x745860
  0x74584a  8d9b00000000                   lea    ebx,[ebx+0x0]
  0x745850  3b5808                         cmp    ebx,DWORD PTR [eax+0x8]
  0x745853  750b                           jne    0x745860
  0x745855  8bd8                           mov    ebx,eax
  0x745857  8b4004                         mov    eax,DWORD PTR [eax+0x4]
  0x74585a  80781500                       cmp    BYTE PTR [eax+0x15],0x0
  0x74585e  74f0                           je     0x745850
  0x745860  8bd8                           mov    ebx,eax
  0x745862  3b5c241c                       cmp    ebx,DWORD PTR [esp+0x1c]
  0x745866  0f8524ffffff                   jne    0x745790
  0x74586c  8b7d08                         mov    edi,DWORD PTR [ebp+0x8]
  0x74586f  8b5f64                         mov    ebx,DWORD PTR [edi+0x64]
  0x745872  8b3b                           mov    edi,DWORD PTR [ebx]
  0x745874  3bfb                           cmp    edi,ebx
  0x745876  746a                           je     0x7458e2
  0x745878  eb06                           jmp    0x745880
  0x74587a  8d9b00000000                   lea    ebx,[ebx+0x0]
  0x745880  8b4708                         mov    eax,DWORD PTR [edi+0x8]
  0x745883  8b4e50                         mov    ecx,DWORD PTR [esi+0x50]
  0x745886  8b5048                         mov    edx,DWORD PTR [eax+0x48]
  0x745889  8b4104                         mov    eax,DWORD PTR [ecx+0x4]
  0x74588c  80781500                       cmp    BYTE PTR [eax+0x15],0x0
  0x745890  7514                           jne    0x7458a6
  0x745892  39500c                         cmp    DWORD PTR [eax+0xc],edx
  0x745895  7305                           jae    0x74589c
  0x745897  8b4008                         mov    eax,DWORD PTR [eax+0x8]
  0x74589a  eb04                           jmp    0x7458a0
  0x74589c  8bc8                           mov    ecx,eax
  0x74589e  8b00                           mov    eax,DWORD PTR [eax]
  0x7458a0  80781500                       cmp    BYTE PTR [eax+0x15],0x0
  0x7458a4  74ec                           je     0x745892
  0x7458a6  8b4650                         mov    eax,DWORD PTR [esi+0x50]
  0x7458a9  894c241c                       mov    DWORD PTR [esp+0x1c],ecx
  0x7458ad  3bc8                           cmp    ecx,eax
  0x7458af  740b                           je     0x7458bc
  0x7458b1  3b510c                         cmp    edx,DWORD PTR [ecx+0xc]
  0x7458b4  7206                           jb     0x7458bc
  0x7458b6  8d44241c                       lea    eax,[esp+0x1c]
  0x7458ba  eb08                           jmp    0x7458c4
  0x7458bc  89442418                       mov    DWORD PTR [esp+0x18],eax
  0x7458c0  8d442418                       lea    eax,[esp+0x18]
  0x7458c4  8b00                           mov    eax,DWORD PTR [eax]
  0x7458c6  3b4650                         cmp    eax,DWORD PTR [esi+0x50]
  0x7458c9  7411                           je     0x7458dc
  0x7458cb  8b4010                         mov    eax,DWORD PTR [eax+0x10]
  0x7458ce  85c0                           test   eax,eax
  0x7458d0  740a                           je     0x7458dc
  0x7458d2  8b16                           mov    edx,DWORD PTR [esi]
  0x7458d4  50                             push   eax
  0x7458d5  8b4270                         mov    eax,DWORD PTR [edx+0x70]
  0x7458d8  8bce                           mov    ecx,esi
  0x7458da  ffd0                           call   eax
  0x7458dc  8b3f                           mov    edi,DWORD PTR [edi]
  0x7458de  3bfb                           cmp    edi,ebx
  0x7458e0  759e                           jne    0x745880
  0x7458e2  8b4d08                         mov    ecx,DWORD PTR [ebp+0x8]
  0x7458e5  83793c00                       cmp    DWORD PTR [ecx+0x3c],0x0
  0x7458e9  7425                           je     0x745910
  0x7458eb  f7462800000400                 test   DWORD PTR [esi+0x28],0x40000
  0x7458f2  8b4e3c                         mov    ecx,DWORD PTR [esi+0x3c]
  0x7458f5  750f                           jne    0x745906
  0x7458f7  8b11                           mov    edx,DWORD PTR [ecx]
  0x7458f9  8b4228                         mov    eax,DWORD PTR [edx+0x28]
  0x7458fc  8b3e                           mov    edi,DWORD PTR [esi]
  0x7458fe  ffd0                           call   eax
  0x745900  8b5750                         mov    edx,DWORD PTR [edi+0x50]
  0x745903  50                             push   eax
  0x745904  eb06                           jmp    0x74590c
  0x745906  8b06                           mov    eax,DWORD PTR [esi]
  0x745908  8b5050                         mov    edx,DWORD PTR [eax+0x50]
  0x74590b  51                             push   ecx
  0x74590c  8bce                           mov    ecx,esi
  0x74590e  ffd2                           call   edx
  0x745910  8b06                           mov    eax,DWORD PTR [esi]
  0x745912  8b9014010000                   mov    edx,DWORD PTR [eax+0x114]
  0x745918  8bce                           mov    ecx,esi
  0x74591a  ffd2                           call   edx
  0x74591c  5f                             pop    edi
  0x74591d  5e                             pop    esi
  0x74591e  5b                             pop    ebx
  0x74591f  8be5                           mov    esp,ebp
  0x745921  5d                             pop    ebp
  0x745922  c20400                         ret    0x4

[B14] base object constructor 0x7451f0..0x745372
  0x7451f0  55                             push   ebp
  0x7451f1  8bec                           mov    ebp,esp
  0x7451f3  6aff                           push   0xffffffff
  0x7451f5  68c0c89000                     push   0x90c8c0
  0x7451fa  64a100000000                   mov    eax,fs:0x0
  0x745200  50                             push   eax
  0x745201  83ec24                         sub    esp,0x24
  0x745204  56                             push   esi
  0x745205  57                             push   edi
  0x745206  a1201fd600                     mov    eax,ds:0xd61f20
  0x74520b  33c5                           xor    eax,ebp
  0x74520d  50                             push   eax
  0x74520e  8d45f4                         lea    eax,[ebp-0xc]
  0x745211  64a300000000                   mov    fs:0x0,eax
  0x745217  8bf1                           mov    esi,ecx
  0x745219  8975e8                         mov    DWORD PTR [ebp-0x18],esi
  0x74521c  a128a8fb00                     mov    eax,ds:0xfba828
  0x745221  40                             inc    eax
  0x745222  a328a8fb00                     mov    ds:0xfba828,eax
  0x745227  894604                         mov    DWORD PTR [esi+0x4],eax
  0x74522a  33ff                           xor    edi,edi
  0x74522c  897dfc                         mov    DWORD PTR [ebp-0x4],edi
  0x74522f  c706d46bc400                   mov    DWORD PTR [esi],0xc46bd4
  0x745235  897e14                         mov    DWORD PTR [esi+0x14],edi
  0x745238  897e10                         mov    DWORD PTR [esi+0x10],edi
  0x74523b  897e0c                         mov    DWORD PTR [esi+0xc],edi
  0x74523e  897e08                         mov    DWORD PTR [esi+0x8],edi
  0x745241  897e38                         mov    DWORD PTR [esi+0x38],edi
  0x745244  897e34                         mov    DWORD PTR [esi+0x34],edi
  0x745247  897e30                         mov    DWORD PTR [esi+0x30],edi
  0x74524a  897e2c                         mov    DWORD PTR [esi+0x2c],edi
  0x74524d  6a18                           push   0x18
  0x74524f  897e54                         mov    DWORD PTR [esi+0x54],edi
  0x745252  e811c01400                     call   0x891268
  0x745257  83c404                         add    esp,0x4
  0x74525a  3bc7                           cmp    eax,edi
  0x74525c  0f84ec000000                   je     0x74534e
  0x745262  894650                         mov    DWORD PTR [esi+0x50],eax
  0x745265  8900                           mov    DWORD PTR [eax],eax
  0x745267  8b4650                         mov    eax,DWORD PTR [esi+0x50]
  0x74526a  894004                         mov    DWORD PTR [eax+0x4],eax
  0x74526d  8b4650                         mov    eax,DWORD PTR [esi+0x50]
  0x745270  894008                         mov    DWORD PTR [eax+0x8],eax
  0x745273  8b4650                         mov    eax,DWORD PTR [esi+0x50]
  0x745276  c6401401                       mov    BYTE PTR [eax+0x14],0x1
  0x74527a  8b4e50                         mov    ecx,DWORD PTR [esi+0x50]
  0x74527d  c6411501                       mov    BYTE PTR [ecx+0x15],0x1
  0x745281  c645fc01                       mov    BYTE PTR [ebp-0x4],0x1
  0x745285  6a0c                           push   0xc
  0x745287  897e68                         mov    DWORD PTR [esi+0x68],edi
  0x74528a  e8d9bf1400                     call   0x891268
  0x74528f  83c404                         add    esp,0x4
  0x745292  3bc7                           cmp    eax,edi
  0x745294  0f8490000000                   je     0x74532a
  0x74529a  894664                         mov    DWORD PTR [esi+0x64],eax
  0x74529d  8900                           mov    DWORD PTR [eax],eax
  0x74529f  8b4664                         mov    eax,DWORD PTR [esi+0x64]
  0x7452a2  894004                         mov    DWORD PTR [eax+0x4],eax
  0x7452a5  c645fc02                       mov    BYTE PTR [ebp-0x4],0x2
  0x7452a9  6a0c                           push   0xc
  0x7452ab  897e78                         mov    DWORD PTR [esi+0x78],edi
  0x7452ae  e8b5bf1400                     call   0x891268
  0x7452b3  83c404                         add    esp,0x4
  0x7452b6  3bc7                           cmp    eax,edi
  0x7452b8  744c                           je     0x745306
  0x7452ba  894674                         mov    DWORD PTR [esi+0x74],eax
  0x7452bd  8900                           mov    DWORD PTR [eax],eax
  0x7452bf  8b4674                         mov    eax,DWORD PTR [esi+0x74]
  0x7452c2  894004                         mov    DWORD PTR [eax+0x4],eax
  0x7452c5  83c8ff                         or     eax,0xffffffff
  0x7452c8  33d2                           xor    edx,edx
  0x7452ca  894648                         mov    DWORD PTR [esi+0x48],eax
  0x7452cd  894620                         mov    DWORD PTR [esi+0x20],eax
  0x7452d0  897e18                         mov    DWORD PTR [esi+0x18],edi
  0x7452d3  897e3c                         mov    DWORD PTR [esi+0x3c],edi
  0x7452d6  897e40                         mov    DWORD PTR [esi+0x40],edi
  0x7452d9  897e44                         mov    DWORD PTR [esi+0x44],edi
  0x7452dc  897e24                         mov    DWORD PTR [esi+0x24],edi
  0x7452df  897e60                         mov    DWORD PTR [esi+0x60],edi
  0x7452e2  897e1c                         mov    DWORD PTR [esi+0x1c],edi
  0x7452e5  897e70                         mov    DWORD PTR [esi+0x70],edi
  0x7452e8  6689565c                       mov    WORD PTR [esi+0x5c],dx
  0x7452ec  c7462880010000                 mov    DWORD PTR [esi+0x28],0x180
  0x7452f3  8bc6                           mov    eax,esi
  0x7452f5  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x7452f8  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x7452ff  59                             pop    ecx
  0x745300  5f                             pop    edi
  0x745301  5e                             pop    esi
  0x745302  8be5                           mov    esp,ebp
  0x745304  5d                             pop    ebp
  0x745305  c3                             ret
  0x745306  8d45f0                         lea    eax,[ebp-0x10]
  0x745309  50                             push   eax
  0x74530a  8d4ddc                         lea    ecx,[ebp-0x24]
  0x74530d  897df0                         mov    DWORD PTR [ebp-0x10],edi
  0x745310  e894bd1400                     call   0x8910a9
  0x745315  68a857c800                     push   0xc857a8
  0x74531a  8d4ddc                         lea    ecx,[ebp-0x24]
  0x74531d  51                             push   ecx
  0x74531e  c745dca42cbd00                 mov    DWORD PTR [ebp-0x24],0xbd2ca4
  0x745325  e8c6761500                     call   0x89c9f0
  0x74532a  8d55ec                         lea    edx,[ebp-0x14]
  0x74532d  52                             push   edx
  0x74532e  8d4dd0                         lea    ecx,[ebp-0x30]
  0x745331  897dec                         mov    DWORD PTR [ebp-0x14],edi
  0x745334  e870bd1400                     call   0x8910a9
  0x745339  68a857c800                     push   0xc857a8
  0x74533e  8d45d0                         lea    eax,[ebp-0x30]
  0x745341  50                             push   eax
  0x745342  c745d0a42cbd00                 mov    DWORD PTR [ebp-0x30],0xbd2ca4
  0x745349  e8a2761500                     call   0x89c9f0
  0x74534e  8d4df0                         lea    ecx,[ebp-0x10]
  0x745351  51                             push   ecx
  0x745352  8d4ddc                         lea    ecx,[ebp-0x24]
  0x745355  897df0                         mov    DWORD PTR [ebp-0x10],edi
  0x745358  e84cbd1400                     call   0x8910a9
  0x74535d  68a857c800                     push   0xc857a8
  0x745362  8d55dc                         lea    edx,[ebp-0x24]
  0x745365  52                             push   edx
  0x745366  c745dca42cbd00                 mov    DWORD PTR [ebp-0x24],0xbd2ca4
  0x74536d  e87e761500                     call   0x89c9f0

[B15] base-sized factory 0x40ec80..0x40ecde
  0x40ec80  55                             push   ebp
  0x40ec81  8bec                           mov    ebp,esp
  0x40ec83  6aff                           push   0xffffffff
  0x40ec85  68181d9100                     push   0x911d18
  0x40ec8a  64a100000000                   mov    eax,fs:0x0
  0x40ec90  50                             push   eax
  0x40ec91  51                             push   ecx
  0x40ec92  56                             push   esi
  0x40ec93  a1201fd600                     mov    eax,ds:0xd61f20
  0x40ec98  33c5                           xor    eax,ebp
  0x40ec9a  50                             push   eax
  0x40ec9b  8d45f4                         lea    eax,[ebp-0xc]
  0x40ec9e  64a300000000                   mov    fs:0x0,eax
  0x40eca4  6880000000                     push   0x80
  0x40eca9  e8ba334800                     call   0x892068
  0x40ecae  8bf0                           mov    esi,eax
  0x40ecb0  83c404                         add    esp,0x4
  0x40ecb3  8975f0                         mov    DWORD PTR [ebp-0x10],esi
  0x40ecb6  33c0                           xor    eax,eax
  0x40ecb8  8945fc                         mov    DWORD PTR [ebp-0x4],eax
  0x40ecbb  3bf0                           cmp    esi,eax
  0x40ecbd  740f                           je     0x40ecce
  0x40ecbf  8bce                           mov    ecx,esi
  0x40ecc1  e82a653300                     call   0x7451f0
  0x40ecc6  c7069c90c400                   mov    DWORD PTR [esi],0xc4909c
  0x40eccc  8bc6                           mov    eax,esi
  0x40ecce  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x40ecd1  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x40ecd8  59                             pop    ecx
  0x40ecd9  5e                             pop    esi
  0x40ecda  8be5                           mov    esp,ebp
  0x40ecdc  5d                             pop    ebp
  0x40ecdd  c3                             ret

[B16] descriptor binder 0x5a9f40..0x5a9fce
  0x5a9f40  55                             push   ebp
  0x5a9f41  8bec                           mov    ebp,esp
  0x5a9f43  81ec08020000                   sub    esp,0x208
  0x5a9f49  a1201fd600                     mov    eax,ds:0xd61f20
  0x5a9f4e  33c5                           xor    eax,ebp
  0x5a9f50  8945fc                         mov    DWORD PTR [ebp-0x4],eax
  0x5a9f53  53                             push   ebx
  0x5a9f54  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
  0x5a9f57  56                             push   esi
  0x5a9f58  8bf1                           mov    esi,ecx
  0x5a9f5a  8b06                           mov    eax,DWORD PTR [esi]
  0x5a9f5c  8b5010                         mov    edx,DWORD PTR [eax+0x10]
  0x5a9f5f  ffd2                           call   edx
  0x5a9f61  8985f8fdffff                   mov    DWORD PTR [ebp-0x208],eax
  0x5a9f67  8b06                           mov    eax,DWORD PTR [esi]
  0x5a9f69  8b5004                         mov    edx,DWORD PTR [eax+0x4]
  0x5a9f6c  8bce                           mov    ecx,esi
  0x5a9f6e  ffd2                           call   edx
  0x5a9f70  8bf0                           mov    esi,eax
  0x5a9f72  8b85f8fdffff                   mov    eax,DWORD PTR [ebp-0x208]
  0x5a9f78  53                             push   ebx
  0x5a9f79  56                             push   esi
  0x5a9f7a  8bcf                           mov    ecx,edi
  0x5a9f7c  e8bf98ffff                     call   0x5a3840
  0x5a9f81  8bd8                           mov    ebx,eax
  0x5a9f83  85db                           test   ebx,ebx
  0x5a9f85  7535                           jne    0x5a9fbc
  0x5a9f87  8b07                           mov    eax,DWORD PTR [edi]
  0x5a9f89  8b501c                         mov    edx,DWORD PTR [eax+0x1c]
  0x5a9f8c  56                             push   esi
  0x5a9f8d  8bcf                           mov    ecx,edi
  0x5a9f8f  ffd2                           call   edx
  0x5a9f91  50                             push   eax
  0x5a9f92  56                             push   esi
  0x5a9f93  689827bf00                     push   0xbf2798
  0x5a9f98  8d95fcfdffff                   lea    edx,[ebp-0x204]
  0x5a9f9e  e80d0fe6ff                     call   0x40aeb0
  0x5a9fa3  83c40c                         add    esp,0xc
  0x5a9fa6  53                             push   ebx
  0x5a9fa7  68c01fbf00                     push   0xbf1fc0
  0x5a9fac  8d85fcfdffff                   lea    eax,[ebp-0x204]
  0x5a9fb2  50                             push   eax
  0x5a9fb3  53                             push   ebx
  0x5a9fb4  ff158025bd00                   call   DWORD PTR ds:0xbd2580
  0x5a9fba  8bc3                           mov    eax,ebx
  0x5a9fbc  8b4dfc                         mov    ecx,DWORD PTR [ebp-0x4]
  0x5a9fbf  5e                             pop    esi
  0x5a9fc0  33cd                           xor    ecx,ebp
  0x5a9fc2  5b                             pop    ebx
  0x5a9fc3  e839702e00                     call   0x891001
  0x5a9fc8  8be5                           mov    esp,ebp
  0x5a9fca  5d                             pop    ebp
  0x5a9fcb  c20400                         ret    0x4

[B17] actual page slot writer 0x5a3840..0x5a38e4
  0x5a3840  55                             push   ebp
  0x5a3841  8bec                           mov    ebp,esp
  0x5a3843  56                             push   esi
  0x5a3844  57                             push   edi
  0x5a3845  8bf1                           mov    esi,ecx
  0x5a3847  8bf8                           mov    edi,eax
  0x5a3849  8b06                           mov    eax,DWORD PTR [esi]
  0x5a384b  8b5018                         mov    edx,DWORD PTR [eax+0x18]
  0x5a384e  ffd2                           call   edx
  0x5a3850  8b4f3c                         mov    ecx,DWORD PTR [edi+0x3c]
  0x5a3853  894724                         mov    DWORD PTR [edi+0x24],eax
  0x5a3856  85c9                           test   ecx,ecx
  0x5a3858  740f                           je     0x5a3869
  0x5a385a  f7472800000400                 test   DWORD PTR [edi+0x28],0x40000
  0x5a3861  7506                           jne    0x5a3869
  0x5a3863  50                             push   eax
  0x5a3864  e8874e1a00                     call   0x7486f0
  0x5a3869  53                             push   ebx
  0x5a386a  8b5f64                         mov    ebx,DWORD PTR [edi+0x64]
  0x5a386d  8b13                           mov    edx,DWORD PTR [ebx]
  0x5a386f  3bd3                           cmp    edx,ebx
  0x5a3871  7412                           je     0x5a3885
  0x5a3873  8b4724                         mov    eax,DWORD PTR [edi+0x24]
  0x5a3876  8b4a08                         mov    ecx,DWORD PTR [edx+0x8]
  0x5a3879  50                             push   eax
  0x5a387a  e8714e1a00                     call   0x7486f0
  0x5a387f  8b12                           mov    edx,DWORD PTR [edx]
  0x5a3881  3bd3                           cmp    edx,ebx
  0x5a3883  75ee                           jne    0x5a3873
  0x5a3885  8b4d0c                         mov    ecx,DWORD PTR [ebp+0xc]
  0x5a3888  8939                           mov    DWORD PTR [ecx],edi
  0x5a388a  8b16                           mov    edx,DWORD PTR [esi]
  0x5a388c  8b4214                         mov    eax,DWORD PTR [edx+0x14]
  0x5a388f  8bce                           mov    ecx,esi
  0x5a3891  ffd0                           call   eax
  0x5a3893  8b16                           mov    edx,DWORD PTR [esi]
  0x5a3895  8b521c                         mov    edx,DWORD PTR [edx+0x1c]
  0x5a3898  8bd8                           mov    ebx,eax
  0x5a389a  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
  0x5a389d  8b3b                           mov    edi,DWORD PTR [ebx]
  0x5a389f  8d4e04                         lea    ecx,[esi+0x4]
  0x5a38a2  51                             push   ecx
  0x5a38a3  50                             push   eax
  0x5a38a4  8bce                           mov    ecx,esi
  0x5a38a6  ffd2                           call   edx
  0x5a38a8  8b5508                         mov    edx,DWORD PTR [ebp+0x8]
  0x5a38ab  50                             push   eax
  0x5a38ac  8b450c                         mov    eax,DWORD PTR [ebp+0xc]
  0x5a38af  8b08                           mov    ecx,DWORD PTR [eax]
  0x5a38b1  8b4728                         mov    eax,DWORD PTR [edi+0x28]
  0x5a38b4  51                             push   ecx
  0x5a38b5  52                             push   edx
  0x5a38b6  8bcb                           mov    ecx,ebx
  0x5a38b8  ffd0                           call   eax
  0x5a38ba  8bf0                           mov    esi,eax
  0x5a38bc  5b                             pop    ebx
  0x5a38bd  85f6                           test   esi,esi
  0x5a38bf  741b                           je     0x5a38dc
  0x5a38c1  8b4628                         mov    eax,DWORD PTR [esi+0x28]
  0x5a38c4  a801                           test   al,0x1
  0x5a38c6  7406                           je     0x5a38ce
  0x5a38c8  83f001                         xor    eax,0x1
  0x5a38cb  894628                         mov    DWORD PTR [esi+0x28],eax
  0x5a38ce  8b16                           mov    edx,DWORD PTR [esi]
  0x5a38d0  8b8294000000                   mov    eax,DWORD PTR [edx+0x94]
  0x5a38d6  6a00                           push   0x0
  0x5a38d8  8bce                           mov    ecx,esi
  0x5a38da  ffd0                           call   eax
  0x5a38dc  5f                             pop    edi
  0x5a38dd  8bc6                           mov    eax,esi
  0x5a38df  5e                             pop    esi
  0x5a38e0  5d                             pop    ebp
  0x5a38e1  c20800                         ret    0x8

[B18] descriptor window getter 0x5ade20..0x5ade24
  0x5ade20  8b410c                         mov    eax,DWORD PTR [ecx+0xc]
  0x5ade23  c3                             ret

[B19] descriptor resource-ID getter 0x7b3250..0x7b3254
  0x7b3250  8b4104                         mov    eax,DWORD PTR [ecx+0x4]
  0x7b3253  c3                             ret

[B20] post-read child lookup; reused class method, new inherited-reader edge 0x6bd4f0..0x6bd540
  0x6bd4f0  56                             push   esi
  0x6bd4f1  57                             push   edi
  0x6bd4f2  8bf1                           mov    esi,ecx
  0x6bd4f4  684c040000                     push   0x44c
  0x6bd4f9  8dbe84000000                   lea    edi,[esi+0x84]
  0x6bd4ff  e86cf0d7ff                     call   0x43c570
  0x6bd504  68b0040000                     push   0x4b0
  0x6bd509  8dbe80000000                   lea    edi,[esi+0x80]
  0x6bd50f  8bce                           mov    ecx,esi
  0x6bd511  e85af0d7ff                     call   0x43c570
  0x6bd516  68d0070000                     push   0x7d0
  0x6bd51b  8dbe88000000                   lea    edi,[esi+0x88]
  0x6bd521  8bce                           mov    ecx,esi
  0x6bd523  e8c8e1daff                     call   0x46b6f0
  0x6bd528  6834080000                     push   0x834
  0x6bd52d  8dbe8c000000                   lea    edi,[esi+0x8c]
  0x6bd533  8bce                           mov    ecx,esi
  0x6bd535  e8b6e1daff                     call   0x46b6f0
  0x6bd53a  83c410                         add    esp,0x10
  0x6bd53d  5f                             pop    edi
  0x6bd53e  5e                             pop    esi
  0x6bd53f  c3                             ret

[B31] typed child lookup writing one caller-provided pointer slot 0x43c570..0x43c657
  0x43c570  55                             push   ebp
  0x43c571  8bec                           mov    ebp,esp
  0x43c573  83ec20                         sub    esp,0x20
  0x43c576  a1201fd600                     mov    eax,ds:0xd61f20
  0x43c57b  33c5                           xor    eax,ebp
  0x43c57d  8945fc                         mov    DWORD PTR [ebp-0x4],eax
  0x43c580  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
  0x43c583  56                             push   esi
  0x43c584  8bf1                           mov    esi,ecx
  0x43c586  50                             push   eax
  0x43c587  e8b4a33000                     call   0x746940
  0x43c58c  8bf0                           mov    esi,eax
  0x43c58e  85f6                           test   esi,esi
  0x43c590  7552                           jne    0x43c5e4
  0x43c592  b95c1fbf00                     mov    ecx,0xbf1f5c
  0x43c597  b8681fbf00                     mov    eax,0xbf1f68
  0x43c59c  8d75e0                         lea    esi,[ebp-0x20]
  0x43c59f  e8dc84fcff                     call   0x404a80
  0x43c5a4  8b45e0                         mov    eax,DWORD PTR [ebp-0x20]
  0x43c5a7  be08000000                     mov    esi,0x8
  0x43c5ac  3975f4                         cmp    DWORD PTR [ebp-0xc],esi
  0x43c5af  7303                           jae    0x43c5b4
  0x43c5b1  8d45e0                         lea    eax,[ebp-0x20]
  0x43c5b4  6a00                           push   0x0
  0x43c5b6  68c01fbf00                     push   0xbf1fc0
  0x43c5bb  50                             push   eax
  0x43c5bc  6a00                           push   0x0
  0x43c5be  ff158025bd00                   call   DWORD PTR ds:0xbd2580
  0x43c5c4  3975f4                         cmp    DWORD PTR [ebp-0xc],esi
  0x43c5c7  727f                           jb     0x43c648
  0x43c5c9  8b45e0                         mov    eax,DWORD PTR [ebp-0x20]
  0x43c5cc  50                             push   eax
  0x43c5cd  e83a4c4500                     call   0x89120c
  0x43c5d2  83c404                         add    esp,0x4
  0x43c5d5  5e                             pop    esi
  0x43c5d6  8b4dfc                         mov    ecx,DWORD PTR [ebp-0x4]
  0x43c5d9  33cd                           xor    ecx,ebp
  0x43c5db  e8214a4500                     call   0x891001
  0x43c5e0  8be5                           mov    esp,ebp
  0x43c5e2  5d                             pop    ebp
  0x43c5e3  c3                             ret
  0x43c5e4  8b16                           mov    edx,DWORD PTR [esi]
  0x43c5e6  8b4204                         mov    eax,DWORD PTR [edx+0x4]
  0x43c5e9  8bce                           mov    ecx,esi
  0x43c5eb  ffd0                           call   eax
  0x43c5ed  3dc8000000                     cmp    eax,0xc8
  0x43c5f2  7452                           je     0x43c646
  0x43c5f4  b95c1fbf00                     mov    ecx,0xbf1f5c
  0x43c5f9  b8d01fbf00                     mov    eax,0xbf1fd0
  0x43c5fe  8d75e0                         lea    esi,[ebp-0x20]
  0x43c601  e87a84fcff                     call   0x404a80
  0x43c606  8b45e0                         mov    eax,DWORD PTR [ebp-0x20]
  0x43c609  be08000000                     mov    esi,0x8
  0x43c60e  3975f4                         cmp    DWORD PTR [ebp-0xc],esi
  0x43c611  7303                           jae    0x43c616
  0x43c613  8d45e0                         lea    eax,[ebp-0x20]
  0x43c616  6a00                           push   0x0
  0x43c618  68c01fbf00                     push   0xbf1fc0
  0x43c61d  50                             push   eax
  0x43c61e  6a00                           push   0x0
  0x43c620  ff158025bd00                   call   DWORD PTR ds:0xbd2580
  0x43c626  3975f4                         cmp    DWORD PTR [ebp-0xc],esi
  0x43c629  721d                           jb     0x43c648
  0x43c62b  8b4de0                         mov    ecx,DWORD PTR [ebp-0x20]
  0x43c62e  51                             push   ecx
  0x43c62f  e8d84b4500                     call   0x89120c
  0x43c634  83c404                         add    esp,0x4
  0x43c637  5e                             pop    esi
  0x43c638  8b4dfc                         mov    ecx,DWORD PTR [ebp-0x4]
  0x43c63b  33cd                           xor    ecx,ebp
  0x43c63d  e8bf494500                     call   0x891001
  0x43c642  8be5                           mov    esp,ebp
  0x43c644  5d                             pop    ebp
  0x43c645  c3                             ret
  0x43c646  8937                           mov    DWORD PTR [edi],esi
  0x43c648  8b4dfc                         mov    ecx,DWORD PTR [ebp-0x4]
  0x43c64b  33cd                           xor    ecx,ebp
  0x43c64d  5e                             pop    esi
  0x43c64e  e8ae494500                     call   0x891001
  0x43c653  8be5                           mov    esp,ebp
  0x43c655  5d                             pop    ebp
  0x43c656  c3                             ret

[B32] typed child lookup writing one caller-provided pointer slot 0x46b6f0..0x46b7d7
  0x46b6f0  55                             push   ebp
  0x46b6f1  8bec                           mov    ebp,esp
  0x46b6f3  83ec20                         sub    esp,0x20
  0x46b6f6  a1201fd600                     mov    eax,ds:0xd61f20
  0x46b6fb  33c5                           xor    eax,ebp
  0x46b6fd  8945fc                         mov    DWORD PTR [ebp-0x4],eax
  0x46b700  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
  0x46b703  56                             push   esi
  0x46b704  8bf1                           mov    esi,ecx
  0x46b706  50                             push   eax
  0x46b707  e834b22d00                     call   0x746940
  0x46b70c  8bf0                           mov    esi,eax
  0x46b70e  85f6                           test   esi,esi
  0x46b710  7552                           jne    0x46b764
  0x46b712  b95c1fbf00                     mov    ecx,0xbf1f5c
  0x46b717  b8681fbf00                     mov    eax,0xbf1f68
  0x46b71c  8d75e0                         lea    esi,[ebp-0x20]
  0x46b71f  e85c93f9ff                     call   0x404a80
  0x46b724  8b45e0                         mov    eax,DWORD PTR [ebp-0x20]
  0x46b727  be08000000                     mov    esi,0x8
  0x46b72c  3975f4                         cmp    DWORD PTR [ebp-0xc],esi
  0x46b72f  7303                           jae    0x46b734
  0x46b731  8d45e0                         lea    eax,[ebp-0x20]
  0x46b734  6a00                           push   0x0
  0x46b736  68c01fbf00                     push   0xbf1fc0
  0x46b73b  50                             push   eax
  0x46b73c  6a00                           push   0x0
  0x46b73e  ff158025bd00                   call   DWORD PTR ds:0xbd2580
  0x46b744  3975f4                         cmp    DWORD PTR [ebp-0xc],esi
  0x46b747  727f                           jb     0x46b7c8
  0x46b749  8b45e0                         mov    eax,DWORD PTR [ebp-0x20]
  0x46b74c  50                             push   eax
  0x46b74d  e8ba5a4200                     call   0x89120c
  0x46b752  83c404                         add    esp,0x4
  0x46b755  5e                             pop    esi
  0x46b756  8b4dfc                         mov    ecx,DWORD PTR [ebp-0x4]
  0x46b759  33cd                           xor    ecx,ebp
  0x46b75b  e8a1584200                     call   0x891001
  0x46b760  8be5                           mov    esp,ebp
  0x46b762  5d                             pop    ebp
  0x46b763  c3                             ret
  0x46b764  8b16                           mov    edx,DWORD PTR [esi]
  0x46b766  8b4204                         mov    eax,DWORD PTR [edx+0x4]
  0x46b769  8bce                           mov    ecx,esi
  0x46b76b  ffd0                           call   eax
  0x46b76d  3d78050000                     cmp    eax,0x578
  0x46b772  7452                           je     0x46b7c6
  0x46b774  b95c1fbf00                     mov    ecx,0xbf1f5c
  0x46b779  b8d01fbf00                     mov    eax,0xbf1fd0
  0x46b77e  8d75e0                         lea    esi,[ebp-0x20]
  0x46b781  e8fa92f9ff                     call   0x404a80
  0x46b786  8b45e0                         mov    eax,DWORD PTR [ebp-0x20]
  0x46b789  be08000000                     mov    esi,0x8
  0x46b78e  3975f4                         cmp    DWORD PTR [ebp-0xc],esi
  0x46b791  7303                           jae    0x46b796
  0x46b793  8d45e0                         lea    eax,[ebp-0x20]
  0x46b796  6a00                           push   0x0
  0x46b798  68c01fbf00                     push   0xbf1fc0
  0x46b79d  50                             push   eax
  0x46b79e  6a00                           push   0x0
  0x46b7a0  ff158025bd00                   call   DWORD PTR ds:0xbd2580
  0x46b7a6  3975f4                         cmp    DWORD PTR [ebp-0xc],esi
  0x46b7a9  721d                           jb     0x46b7c8
  0x46b7ab  8b4de0                         mov    ecx,DWORD PTR [ebp-0x20]
  0x46b7ae  51                             push   ecx
  0x46b7af  e8585a4200                     call   0x89120c
  0x46b7b4  83c404                         add    esp,0x4
  0x46b7b7  5e                             pop    esi
  0x46b7b8  8b4dfc                         mov    ecx,DWORD PTR [ebp-0x4]
  0x46b7bb  33cd                           xor    ecx,ebp
  0x46b7bd  e83f584200                     call   0x891001
  0x46b7c2  8be5                           mov    esp,ebp
  0x46b7c4  5d                             pop    ebp
  0x46b7c5  c3                             ret
  0x46b7c6  8937                           mov    DWORD PTR [edi],esi
  0x46b7c8  8b4dfc                         mov    ecx,DWORD PTR [ebp-0x4]
  0x46b7cb  33cd                           xor    ecx,ebp
  0x46b7cd  5e                             pop    esi
  0x46b7ce  e82e584200                     call   0x891001
  0x46b7d3  8be5                           mov    esp,ebp
  0x46b7d5  5d                             pop    ebp
  0x46b7d6  c3                             ret

[B35] descriptor destructor and cached descriptor reset 0x597ca0..0x597d20
  0x597ca0  55                             push   ebp
  0x597ca1  8bec                           mov    ebp,esp
  0x597ca3  6aff                           push   0xffffffff
  0x597ca5  68185d9000                     push   0x905d18
  0x597caa  64a100000000                   mov    eax,fs:0x0
  0x597cb0  50                             push   eax
  0x597cb1  51                             push   ecx
  0x597cb2  56                             push   esi
  0x597cb3  a1201fd600                     mov    eax,ds:0xd61f20
  0x597cb8  33c5                           xor    eax,ebp
  0x597cba  50                             push   eax
  0x597cbb  8d45f4                         lea    eax,[ebp-0xc]
  0x597cbe  64a300000000                   mov    fs:0x0,eax
  0x597cc4  8bf1                           mov    esi,ecx
  0x597cc6  8975f0                         mov    DWORD PTR [ebp-0x10],esi
  0x597cc9  c70614b5c100                   mov    DWORD PTR [esi],0xc1b514
  0x597ccf  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
  0x597cd6  8b4e0c                         mov    ecx,DWORD PTR [esi+0xc]
  0x597cd9  85c9                           test   ecx,ecx
  0x597cdb  7410                           je     0x597ced
  0x597cdd  8b01                           mov    eax,DWORD PTR [ecx]
  0x597cdf  8b501c                         mov    edx,DWORD PTR [eax+0x1c]
  0x597ce2  6a01                           push   0x1
  0x597ce4  ffd2                           call   edx
  0x597ce6  c7460c00000000                 mov    DWORD PTR [esi+0xc],0x0
  0x597ced  f6450801                       test   BYTE PTR [ebp+0x8],0x1
  0x597cf1  c7055c2cfe0000000000           mov    DWORD PTR ds:0xfe2c5c,0x0
  0x597cfb  c706b429bf00                   mov    DWORD PTR [esi],0xbf29b4
  0x597d01  7409                           je     0x597d0c
  0x597d03  56                             push   esi
  0x597d04  e803952f00                     call   0x89120c
  0x597d09  83c404                         add    esp,0x4
  0x597d0c  8bc6                           mov    eax,esi
  0x597d0e  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
  0x597d11  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
  0x597d18  59                             pop    ecx
  0x597d19  5e                             pop    esi
  0x597d1a  8be5                           mov    esp,ebp
  0x597d1c  5d                             pop    ebp
  0x597d1d  c20400                         ret    0x4

[B36] native child attachment; concrete original talk +70 slot 0x746640..0x7466f1
  0x746640  55                             push   ebp
  0x746641  8bec                           mov    ebp,esp
  0x746643  53                             push   ebx
  0x746644  56                             push   esi
  0x746645  57                             push   edi
  0x746646  8b7d08                         mov    edi,DWORD PTR [ebp+0x8]
  0x746649  8b5f60                         mov    ebx,DWORD PTR [edi+0x60]
  0x74664c  8bf1                           mov    esi,ecx
  0x74664e  85db                           test   ebx,ebx
  0x746650  743a                           je     0x74668c
  0x746652  8b4b64                         mov    ecx,DWORD PTR [ebx+0x64]
  0x746655  8b01                           mov    eax,DWORD PTR [ecx]
  0x746657  3bc1                           cmp    eax,ecx
  0x746659  7431                           je     0x74668c
  0x74665b  eb03                           jmp    0x746660
  0x74665d  8d4900                         lea    ecx,[ecx+0x0]
  0x746660  397808                         cmp    DWORD PTR [eax+0x8],edi
  0x746663  7408                           je     0x74666d
  0x746665  8b00                           mov    eax,DWORD PTR [eax]
  0x746667  3bc1                           cmp    eax,ecx
  0x746669  75f5                           jne    0x746660
  0x74666b  eb1f                           jmp    0x74668c
  0x74666d  3bc1                           cmp    eax,ecx
  0x74666f  741b                           je     0x74668c
  0x746671  8b4804                         mov    ecx,DWORD PTR [eax+0x4]
  0x746674  8b10                           mov    edx,DWORD PTR [eax]
  0x746676  8911                           mov    DWORD PTR [ecx],edx
  0x746678  8b08                           mov    ecx,DWORD PTR [eax]
  0x74667a  8b5004                         mov    edx,DWORD PTR [eax+0x4]
  0x74667d  50                             push   eax
  0x74667e  895104                         mov    DWORD PTR [ecx+0x4],edx
  0x746681  e886ab1400                     call   0x89120c
  0x746686  83c404                         add    esp,0x4
  0x746689  ff4b68                         dec    DWORD PTR [ebx+0x68]
  0x74668c  8b4f3c                         mov    ecx,DWORD PTR [edi+0x3c]
  0x74668f  897760                         mov    DWORD PTR [edi+0x60],esi
  0x746692  8b4624                         mov    eax,DWORD PTR [esi+0x24]
  0x746695  894724                         mov    DWORD PTR [edi+0x24],eax
  0x746698  85c9                           test   ecx,ecx
  0x74669a  740f                           je     0x7466ab
  0x74669c  f7472800000400                 test   DWORD PTR [edi+0x28],0x40000
  0x7466a3  7506                           jne    0x7466ab
  0x7466a5  50                             push   eax
  0x7466a6  e845200000                     call   0x7486f0
  0x7466ab  8b5f64                         mov    ebx,DWORD PTR [edi+0x64]
  0x7466ae  8b13                           mov    edx,DWORD PTR [ebx]
  0x7466b0  3bd3                           cmp    edx,ebx
  0x7466b2  7412                           je     0x7466c6
  0x7466b4  8b4724                         mov    eax,DWORD PTR [edi+0x24]
  0x7466b7  8b4a08                         mov    ecx,DWORD PTR [edx+0x8]
  0x7466ba  50                             push   eax
  0x7466bb  e830200000                     call   0x7486f0
  0x7466c0  8b12                           mov    edx,DWORD PTR [edx]
  0x7466c2  3bd3                           cmp    edx,ebx
  0x7466c4  75ee                           jne    0x7466b4
  0x7466c6  8bcf                           mov    ecx,edi
  0x7466c8  e8a3080000                     call   0x746f70
  0x7466cd  837f6000                       cmp    DWORD PTR [edi+0x60],0x0
  0x7466d1  7411                           je     0x7466e4
  0x7466d3  8b4f1c                         mov    ecx,DWORD PTR [edi+0x1c]
  0x7466d6  83790806                       cmp    DWORD PTR [ecx+0x8],0x6
  0x7466da  7408                           je     0x7466e4
  0x7466dc  8b11                           mov    edx,DWORD PTR [ecx]
  0x7466de  8b4230                         mov    eax,DWORD PTR [edx+0x30]
  0x7466e1  57                             push   edi
  0x7466e2  ffd0                           call   eax
  0x7466e4  57                             push   edi
  0x7466e5  e8c6fdffff                     call   0x7464b0
  0x7466ea  5f                             pop    edi
  0x7466eb  5e                             pop    esi
  0x7466ec  5b                             pop    ebx
  0x7466ed  5d                             pop    ebp
  0x7466ee  c20400                         ret    0x4

[B37] native graphic attachment; concrete original talk +50 slot 0x749890..0x7498dd
  0x749890  55                             push   ebp
  0x749891  8bec                           mov    ebp,esp
  0x749893  56                             push   esi
  0x749894  57                             push   edi
  0x749895  8b7d08                         mov    edi,DWORD PTR [ebp+0x8]
  0x749898  8bf1                           mov    esi,ecx
  0x74989a  85ff                           test   edi,edi
  0x74989c  7436                           je     0x7498d4
  0x74989e  f7462800000400                 test   DWORD PTR [esi+0x28],0x40000
  0x7498a5  752a                           jne    0x7498d1
  0x7498a7  8b4624                         mov    eax,DWORD PTR [esi+0x24]
  0x7498aa  50                             push   eax
  0x7498ab  8bcf                           mov    ecx,edi
  0x7498ad  e83eeeffff                     call   0x7486f0
  0x7498b2  f6462a01                       test   BYTE PTR [esi+0x2a],0x1
  0x7498b6  7407                           je     0x7498bf
  0x7498b8  8bcf                           mov    ecx,edi
  0x7498ba  e811d3ffff                     call   0x746bd0
  0x7498bf  8b4e28                         mov    ecx,DWORD PTR [esi+0x28]
  0x7498c2  c1e90f                         shr    ecx,0xf
  0x7498c5  f6c101                         test   cl,0x1
  0x7498c8  7407                           je     0x7498d1
  0x7498ca  8bcf                           mov    ecx,edi
  0x7498cc  e85fd2ffff                     call   0x746b30
  0x7498d1  897760                         mov    DWORD PTR [edi+0x60],esi
  0x7498d4  897e3c                         mov    DWORD PTR [esi+0x3c],edi
  0x7498d7  5f                             pop    edi
  0x7498d8  5e                             pop    esi
  0x7498d9  5d                             pop    ebp
  0x7498da  c20400                         ret    0x4

[B38] dock factory forwarding method 0x746fd0..0x746fdf
  0x746fd0  55                             push   ebp
  0x746fd1  8bec                           mov    ebp,esp
  0x746fd3  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
  0x746fd6  e8e5700200                     call   0x76e0c0
  0x746fdb  5d                             pop    ebp
  0x746fdc  c20400                         ret    0x4

[B39] native child factory forwarding method 0x746fe0..0x746ff3
  0x746fe0  55                             push   ebp
  0x746fe1  8bec                           mov    ebp,esp
  0x746fe3  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
  0x746fe6  50                             push   eax
  0x746fe7  e814000000                     call   0x747000
  0x746fec  83c404                         add    esp,0x4
  0x746fef  5d                             pop    ebp
  0x746ff0  c20400                         ret    0x4

[B21] normal initialization edge only; not full caller body 0x5a3980..0x5a39be
  0x5a3980  55                             push   ebp
  0x5a3981  8bec                           mov    ebp,esp
  0x5a3983  83e4f8                         and    esp,0xfffffff8
  0x5a3986  6aff                           push   0xffffffff
  0x5a3988  688ef79300                     push   0x93f78e
  0x5a398d  64a100000000                   mov    eax,fs:0x0
  0x5a3993  50                             push   eax
  0x5a3994  83ec48                         sub    esp,0x48
  0x5a3997  a1201fd600                     mov    eax,ds:0xd61f20
  0x5a399c  33c4                           xor    eax,esp
  0x5a399e  89442440                       mov    DWORD PTR [esp+0x40],eax
  0x5a39a2  53                             push   ebx
  0x5a39a3  56                             push   esi
  0x5a39a4  57                             push   edi
  0x5a39a5  a1201fd600                     mov    eax,ds:0xd61f20
  0x5a39aa  33c4                           xor    eax,esp
  0x5a39ac  50                             push   eax
  0x5a39ad  8d442458                       lea    eax,[esp+0x58]
  0x5a39b1  64a300000000                   mov    fs:0x0,eax
  0x5a39b7  8bd9                           mov    ebx,ecx
  0x5a39b9  e85226ffff                     call   0x596010

[B22] normal initialization edge only; not full caller body 0x598890..0x5988c3
  0x598890  55                             push   ebp
  0x598891  8bec                           mov    ebp,esp
  0x598893  83e4f8                         and    esp,0xfffffff8
  0x598896  6aff                           push   0xffffffff
  0x598898  68a2f89300                     push   0x93f8a2
  0x59889d  64a100000000                   mov    eax,fs:0x0
  0x5988a3  50                             push   eax
  0x5988a4  83ec50                         sub    esp,0x50
  0x5988a7  53                             push   ebx
  0x5988a8  56                             push   esi
  0x5988a9  57                             push   edi
  0x5988aa  a1201fd600                     mov    eax,ds:0xd61f20
  0x5988af  33c4                           xor    eax,esp
  0x5988b1  50                             push   eax
  0x5988b2  8d442460                       lea    eax,[esp+0x60]
  0x5988b6  64a300000000                   mov    fs:0x0,eax
  0x5988bc  8bd9                           mov    ebx,ecx
  0x5988be  e8bdb00000                     call   0x5a3980

[B23] normal initialization edge only; not full caller body 0x5ac3e0..0x5ac40f
  0x5ac3e0  55                             push   ebp
  0x5ac3e1  8bec                           mov    ebp,esp
  0x5ac3e3  6aff                           push   0xffffffff
  0x5ac3e5  68ce399400                     push   0x9439ce
  0x5ac3ea  64a100000000                   mov    eax,fs:0x0
  0x5ac3f0  50                             push   eax
  0x5ac3f1  83ec14                         sub    esp,0x14
  0x5ac3f4  53                             push   ebx
  0x5ac3f5  56                             push   esi
  0x5ac3f6  57                             push   edi
  0x5ac3f7  a1201fd600                     mov    eax,ds:0xd61f20
  0x5ac3fc  33c5                           xor    eax,ebp
  0x5ac3fe  50                             push   eax
  0x5ac3ff  8d45f4                         lea    eax,[ebp-0xc]
  0x5ac402  64a300000000                   mov    fs:0x0,eax
  0x5ac408  8bd9                           mov    ebx,ecx
  0x5ac40a  e881c4feff                     call   0x598890

[B24] normal initialization edge only; not full caller body 0x5acea0..0x5acecf
  0x5acea0  55                             push   ebp
  0x5acea1  8bec                           mov    ebp,esp
  0x5acea3  6aff                           push   0xffffffff
  0x5acea5  68ce399400                     push   0x9439ce
  0x5aceaa  64a100000000                   mov    eax,fs:0x0
  0x5aceb0  50                             push   eax
  0x5aceb1  83ec14                         sub    esp,0x14
  0x5aceb4  53                             push   ebx
  0x5aceb5  56                             push   esi
  0x5aceb6  57                             push   edi
  0x5aceb7  a1201fd600                     mov    eax,ds:0xd61f20
  0x5acebc  33c5                           xor    eax,ebp
  0x5acebe  50                             push   eax
  0x5acebf  8d45f4                         lea    eax,[ebp-0xc]
  0x5acec2  64a300000000                   mov    fs:0x0,eax
  0x5acec8  8bd9                           mov    ebx,ecx
  0x5aceca  e811f5ffff                     call   0x5ac3e0

[B25] normal initialization edge only; not full caller body 0x5afc30..0x5afc63
  0x5afc30  55                             push   ebp
  0x5afc31  8bec                           mov    ebp,esp
  0x5afc33  83e4f8                         and    esp,0xfffffff8
  0x5afc36  6aff                           push   0xffffffff
  0x5afc38  684c749400                     push   0x94744c
  0x5afc3d  64a100000000                   mov    eax,fs:0x0
  0x5afc43  50                             push   eax
  0x5afc44  83ec20                         sub    esp,0x20
  0x5afc47  53                             push   ebx
  0x5afc48  56                             push   esi
  0x5afc49  57                             push   edi
  0x5afc4a  a1201fd600                     mov    eax,ds:0xd61f20
  0x5afc4f  33c4                           xor    eax,esp
  0x5afc51  50                             push   eax
  0x5afc52  8d442430                       lea    eax,[esp+0x30]
  0x5afc56  64a300000000                   mov    fs:0x0,eax
  0x5afc5c  8bf1                           mov    esi,ecx
  0x5afc5e  e87dc7ffff                     call   0x5ac3e0

[B33] normal initialization edge only; not full caller body 0x5a65a0..0x5a65cf
  0x5a65a0  55                             push   ebp
  0x5a65a1  8bec                           mov    ebp,esp
  0x5a65a3  6aff                           push   0xffffffff
  0x5a65a5  6880a19400                     push   0x94a180
  0x5a65aa  64a100000000                   mov    eax,fs:0x0
  0x5a65b0  50                             push   eax
  0x5a65b1  83ec18                         sub    esp,0x18
  0x5a65b4  53                             push   ebx
  0x5a65b5  56                             push   esi
  0x5a65b6  57                             push   edi
  0x5a65b7  a1201fd600                     mov    eax,ds:0xd61f20
  0x5a65bc  33c5                           xor    eax,ebp
  0x5a65be  50                             push   eax
  0x5a65bf  8d45f4                         lea    eax,[ebp-0xc]
  0x5a65c2  64a300000000                   mov    fs:0x0,eax
  0x5a65c8  8bd9                           mov    ebx,ecx
  0x5a65ca  e841fafeff                     call   0x596010

[B34] normal initialization edge only; not full caller body 0x5a7120..0x5a714f
  0x5a7120  55                             push   ebp
  0x5a7121  8bec                           mov    ebp,esp
  0x5a7123  6aff                           push   0xffffffff
  0x5a7125  68d83b9400                     push   0x943bd8
  0x5a712a  64a100000000                   mov    eax,fs:0x0
  0x5a7130  50                             push   eax
  0x5a7131  83ec20                         sub    esp,0x20
  0x5a7134  53                             push   ebx
  0x5a7135  56                             push   esi
  0x5a7136  57                             push   edi
  0x5a7137  a1201fd600                     mov    eax,ds:0xd61f20
  0x5a713c  33c5                           xor    eax,ebp
  0x5a713e  50                             push   eax
  0x5a713f  8d45f4                         lea    eax,[ebp-0xc]
  0x5a7142  64a300000000                   mov    fs:0x0,eax
  0x5a7148  8bf1                           mov    esi,ecx
  0x5a714a  e8c1eefeff                     call   0x596010

[B26] Only classification of the absolute receiver reference: read, not writer 0x6bdf46..0x6bdf4c
  0x6bdf46  8b0d8031fe00                   mov    ecx,DWORD PTR ds:0xfe3180

[B27] Only classification of the absolute receiver reference: read, not writer 0x6bdfa6..0x6bdfac
  0x6bdfa6  8b0d8031fe00                   mov    ecx,DWORD PTR ds:0xfe3180

[B28] Only classification of the absolute receiver reference: read, not writer 0x6be006..0x6be00c
  0x6be006  8b0d8031fe00                   mov    ecx,DWORD PTR ds:0xfe3180

[B29] Only classification of the absolute receiver reference: read, not writer 0x6be066..0x6be06c
  0x6be066  8b0d8031fe00                   mov    ecx,DWORD PTR ds:0xfe3180

[B30] Only classification of the absolute receiver reference: read, not writer 0x6be096..0x6be09c
  0x6be096  8b0d8031fe00                   mov    ecx,DWORD PTR ds:0xfe3180
