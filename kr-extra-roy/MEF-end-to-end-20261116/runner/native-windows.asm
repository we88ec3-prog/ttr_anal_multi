
; H01 debug.sethook mask builder: c/r/l and positive instruction count
; VA 0x701400..0x70144c RAW 0x300800 LEN 76 SHA256 a80372e27595bb28e9b5342559a6b20d83716283cd03546635e78371edb3afdf
00701400  55                               push   ebp
00701401  8bec                             mov    ebp,esp
00701403  56                               push   esi
00701404  6a63                             push   0x63
00701406  57                               push   edi
00701407  33f6                             xor    esi,esi
00701409  e8d2021900                       call   0x8916e0
0070140E  83c408                           add    esp,0x8
00701411  85c0                             test   eax,eax
00701413  7405                             je     0x70141a
00701415  be01000000                       mov    esi,0x1
0070141A  6a72                             push   0x72
0070141C  57                               push   edi
0070141D  e8be021900                       call   0x8916e0
00701422  83c408                           add    esp,0x8
00701425  85c0                             test   eax,eax
00701427  7403                             je     0x70142c
00701429  83ce02                           or     esi,0x2
0070142C  6a6c                             push   0x6c
0070142E  57                               push   edi
0070142F  e8ac021900                       call   0x8916e0
00701434  83c408                           add    esp,0x8
00701437  85c0                             test   eax,eax
00701439  7403                             je     0x70143e
0070143B  83ce04                           or     esi,0x4
0070143E  837d0800                         cmp    DWORD PTR [ebp+0x8],0x0
00701442  7e03                             jle    0x701447
00701444  83ce08                           or     esi,0x8
00701447  8bc6                             mov    eax,esi
00701449  5e                               pop    esi
0070144A  5d                               pop    ebp
0070144B  c3                               ret

; H02 debug.sethook optional target thread, Lua hook registry store, enable/disable fields
; VA 0x701510..0x7016bb RAW 0x300910 LEN 427 SHA256 c827d8a757e7144ed4bbcdda9ce8a24b34272d952c95297b7093a5718cc61648
00701510  55                               push   ebp
00701511  8bec                             mov    ebp,esp
00701513  83ec10                           sub    esp,0x10
00701516  53                               push   ebx
00701517  56                               push   esi
00701518  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0070151B  8b460c                           mov    eax,DWORD PTR [esi+0xc]
0070151E  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
00701521  3bc1                             cmp    eax,ecx
00701523  7331                             jae    0x701556
00701525  3dc8bfc000                       cmp    eax,0xc0bfc8
0070152A  742a                             je     0x701556
0070152C  83780808                         cmp    DWORD PTR [eax+0x8],0x8
00701530  7524                             jne    0x701556
00701532  bb01000000                       mov    ebx,0x1
00701537  3bc1                             cmp    eax,ecx
00701539  7205                             jb     0x701540
0070153B  b8c8bfc000                       mov    eax,0xc0bfc8
00701540  83780808                         cmp    DWORD PTR [eax+0x8],0x8
00701544  7409                             je     0x70154f
00701546  c7450800000000                   mov    DWORD PTR [ebp+0x8],0x0
0070154D  eb0c                             jmp    0x70155b
0070154F  8b00                             mov    eax,DWORD PTR [eax]
00701551  894508                           mov    DWORD PTR [ebp+0x8],eax
00701554  eb05                             jmp    0x70155b
00701556  33db                             xor    ebx,ebx
00701558  897508                           mov    DWORD PTR [ebp+0x8],esi
0070155B  57                               push   edi
0070155C  8d7b01                           lea    edi,[ebx+0x1]
0070155F  8bc7                             mov    eax,edi
00701561  8bce                             mov    ecx,esi
00701563  897df0                           mov    DWORD PTR [ebp-0x10],edi
00701566  e8853bffff                       call   0x6f50f0
0070156B  3dc8bfc000                       cmp    eax,0xc0bfc8
00701570  7406                             je     0x701578
00701572  83780800                         cmp    DWORD PTR [eax+0x8],0x0
00701576  7f15                             jg     0x70158d
00701578  8bcf                             mov    ecx,edi
0070157A  8bc6                             mov    eax,esi
0070157C  e89f3cffff                       call   0x6f5220
00701581  33db                             xor    ebx,ebx
00701583  33c0                             xor    eax,eax
00701585  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00701588  e9b7000000                       jmp    0x701644
0070158D  8d4b02                           lea    ecx,[ebx+0x2]
00701590  56                               push   esi
00701591  33c0                             xor    eax,eax
00701593  e8784cffff                       call   0x6f6210
00701598  8945f4                           mov    DWORD PTR [ebp-0xc],eax
0070159B  83c404                           add    esp,0x4
0070159E  8bc7                             mov    eax,edi
007015A0  8bce                             mov    ecx,esi
007015A2  e8493bffff                       call   0x6f50f0
007015A7  3dc8bfc000                       cmp    eax,0xc0bfc8
007015AC  7406                             je     0x7015b4
007015AE  83780806                         cmp    DWORD PTR [eax+0x8],0x6
007015B2  744a                             je     0x7015fe
007015B4  8b0d34bec000                     mov    ecx,DWORD PTR ds:0xc0be34
007015BA  894df8                           mov    DWORD PTR [ebp-0x8],ecx
007015BD  8bc7                             mov    eax,edi
007015BF  8bce                             mov    ecx,esi
007015C1  e82a3bffff                       call   0x6f50f0
007015C6  3dc8bfc000                       cmp    eax,0xc0bfc8
007015CB  7408                             je     0x7015d5
007015CD  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007015D0  83f8ff                           cmp    eax,0xffffffff
007015D3  7507                             jne    0x7015dc
007015D5  b8f426c400                       mov    eax,0xc426f4
007015DA  eb07                             jmp    0x7015e3
007015DC  8b04851cbec000                   mov    eax,DWORD PTR [eax*4+0xc0be1c]
007015E3  8b55f8                           mov    edx,DWORD PTR [ebp-0x8]
007015E6  50                               push   eax
007015E7  52                               push   edx
007015E8  686827c400                       push   0xc42768
007015ED  56                               push   esi
007015EE  e88d3fffff                       call   0x6f5580
007015F3  57                               push   edi
007015F4  8bf8                             mov    edi,eax
007015F6  e8a547ffff                       call   0x6f5da0
007015FB  83c414                           add    esp,0x14
007015FE  8d7b03                           lea    edi,[ebx+0x3]
00701601  8bc7                             mov    eax,edi
00701603  8bce                             mov    ecx,esi
00701605  e8e63affff                       call   0x6f50f0
0070160A  3dc8bfc000                       cmp    eax,0xc0bfc8
0070160F  7406                             je     0x701617
00701611  83780800                         cmp    DWORD PTR [eax+0x8],0x0
00701615  7f09                             jg     0x701620
00701617  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0070161E  eb0d                             jmp    0x70162d
00701620  57                               push   edi
00701621  56                               push   esi
00701622  e8494dffff                       call   0x6f6370
00701627  83c408                           add    esp,0x8
0070162A  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0070162D  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
00701630  8b7df4                           mov    edi,DWORD PTR [ebp-0xc]
00701633  50                               push   eax
00701634  bb20137000                       mov    ebx,0x701320
00701639  e8c2fdffff                       call   0x701400
0070163E  8b7df0                           mov    edi,DWORD PTR [ebp-0x10]
00701641  83c404                           add    esp,0x4
00701644  8945f8                           mov    DWORD PTR [ebp-0x8],eax
00701647  e804feffff                       call   0x701450
0070164C  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0070164F  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
00701652  8908                             mov    DWORD PTR [eax],ecx
00701654  c7400802000000                   mov    DWORD PTR [eax+0x8],0x2
0070165B  83460810                         add    DWORD PTR [esi+0x8],0x10
0070165F  8bc7                             mov    eax,edi
00701661  8bce                             mov    ecx,esi
00701663  e8883affff                       call   0x6f50f0
00701668  8b10                             mov    edx,DWORD PTR [eax]
0070166A  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
0070166D  8911                             mov    DWORD PTR [ecx],edx
0070166F  8b5004                           mov    edx,DWORD PTR [eax+0x4]
00701672  895104                           mov    DWORD PTR [ecx+0x4],edx
00701675  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00701678  894108                           mov    DWORD PTR [ecx+0x8],eax
0070167B  83460810                         add    DWORD PTR [esi+0x8],0x10
0070167F  56                               push   esi
00701680  b8fdffffff                       mov    eax,0xfffffffd
00701685  e86641ffff                       call   0x6f57f0
0070168A  834608f0                         add    DWORD PTR [esi+0x8],0xfffffff0
0070168E  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
00701691  83c404                           add    esp,0x4
00701694  5f                               pop    edi
00701695  85db                             test   ebx,ebx
00701697  7404                             je     0x70169d
00701699  85c0                             test   eax,eax
0070169B  7504                             jne    0x7016a1
0070169D  33c0                             xor    eax,eax
0070169F  33db                             xor    ebx,ebx
007016A1  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007016A4  8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
007016A7  5e                               pop    esi
007016A8  895944                           mov    DWORD PTR [ecx+0x44],ebx
007016AB  884138                           mov    BYTE PTR [ecx+0x38],al
007016AE  89513c                           mov    DWORD PTR [ecx+0x3c],edx
007016B1  895140                           mov    DWORD PTR [ecx+0x40],edx
007016B4  33c0                             xor    eax,eax
007016B6  5b                               pop    ebx
007016B7  8be5                             mov    esp,ebp
007016B9  5d                               pop    ebp
007016BA  c3                               ret

; H03 hook table creation/lookup under registry lightuserdata key
; VA 0x701450..0x70150c RAW 0x300850 LEN 188 SHA256 f49ba2a50e1b8c10f7e23de3b8459cce29f055b7b67edeac9846a33317b02b63
00701450  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00701453  c700df81c000                     mov    DWORD PTR [eax],0xc081df
00701459  c7400802000000                   mov    DWORD PTR [eax+0x8],0x2
00701460  8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
00701463  53                               push   ebx
00701464  bb10000000                       mov    ebx,0x10
00701469  015e08                           add    DWORD PTR [esi+0x8],ebx
0070146C  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0070146F  8b4960                           mov    ecx,DWORD PTR [ecx+0x60]
00701472  83c0f0                           add    eax,0xfffffff0
00701475  e8d687ffff                       call   0x6f9c50
0070147A  8b10                             mov    edx,DWORD PTR [eax]
0070147C  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
0070147F  2bcb                             sub    ecx,ebx
00701481  8911                             mov    DWORD PTR [ecx],edx
00701483  8b5004                           mov    edx,DWORD PTR [eax+0x4]
00701486  895104                           mov    DWORD PTR [ecx+0x4],edx
00701489  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0070148C  894108                           mov    DWORD PTR [ecx+0x8],eax
0070148F  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00701492  83c0f0                           add    eax,0xfffffff0
00701495  3dc8bfc000                       cmp    eax,0xc0bfc8
0070149A  7406                             je     0x7014a2
0070149C  83780805                         cmp    DWORD PTR [eax+0x8],0x5
007014A0  7468                             je     0x70150a
007014A2  894608                           mov    DWORD PTR [esi+0x8],eax
007014A5  8b4610                           mov    eax,DWORD PTR [esi+0x10]
007014A8  8b4844                           mov    ecx,DWORD PTR [eax+0x44]
007014AB  3b4840                           cmp    ecx,DWORD PTR [eax+0x40]
007014AE  7207                             jb     0x7014b7
007014B0  8bc6                             mov    eax,esi
007014B2  e8e99effff                       call   0x6fb3a0
007014B7  57                               push   edi
007014B8  8b7e08                           mov    edi,DWORD PTR [esi+0x8]
007014BB  6a01                             push   0x1
007014BD  6a00                             push   0x0
007014BF  56                               push   esi
007014C0  e8db84ffff                       call   0x6f99a0
007014C5  8907                             mov    DWORD PTR [edi],eax
007014C7  c7470805000000                   mov    DWORD PTR [edi+0x8],0x5
007014CE  015e08                           add    DWORD PTR [esi+0x8],ebx
007014D1  8b4608                           mov    eax,DWORD PTR [esi+0x8]
007014D4  c700df81c000                     mov    DWORD PTR [eax],0xc081df
007014DA  c7400802000000                   mov    DWORD PTR [eax+0x8],0x2
007014E1  015e08                           add    DWORD PTR [esi+0x8],ebx
007014E4  8b4608                           mov    eax,DWORD PTR [esi+0x8]
007014E7  8b50e0                           mov    edx,DWORD PTR [eax-0x20]
007014EA  8910                             mov    DWORD PTR [eax],edx
007014EC  8b48e4                           mov    ecx,DWORD PTR [eax-0x1c]
007014EF  894804                           mov    DWORD PTR [eax+0x4],ecx
007014F2  8b50e8                           mov    edx,DWORD PTR [eax-0x18]
007014F5  895008                           mov    DWORD PTR [eax+0x8],edx
007014F8  015e08                           add    DWORD PTR [esi+0x8],ebx
007014FB  56                               push   esi
007014FC  b8f0d8ffff                       mov    eax,0xffffd8f0
00701501  e8ea42ffff                       call   0x6f57f0
00701506  83c410                           add    esp,0x10
00701509  5f                               pop    edi
0070150A  5b                               pop    ebx
0070150B  c3                               ret

; H04 hook Lua function lookup by current thread, event name and line, synchronous execution
; VA 0x701320..0x7013f9 RAW 0x300720 LEN 217 SHA256 5620badb3aca4f6940f5abebe258058e8110436ed9cab5b645ea713ad091a24b
00701320  55                               push   ebp
00701321  8bec                             mov    ebp,esp
00701323  53                               push   ebx
00701324  56                               push   esi
00701325  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
00701328  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0070132B  c700df81c000                     mov    DWORD PTR [eax],0xc081df
00701331  57                               push   edi
00701332  bb02000000                       mov    ebx,0x2
00701337  895808                           mov    DWORD PTR [eax+0x8],ebx
0070133A  8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
0070133D  bf10000000                       mov    edi,0x10
00701342  017e08                           add    DWORD PTR [esi+0x8],edi
00701345  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00701348  8b4960                           mov    ecx,DWORD PTR [ecx+0x60]
0070134B  83c0f0                           add    eax,0xfffffff0
0070134E  e8fd88ffff                       call   0x6f9c50
00701353  8b10                             mov    edx,DWORD PTR [eax]
00701355  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
00701358  2bcf                             sub    ecx,edi
0070135A  8911                             mov    DWORD PTR [ecx],edx
0070135C  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0070135F  895104                           mov    DWORD PTR [ecx+0x4],edx
00701362  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00701365  894108                           mov    DWORD PTR [ecx+0x8],eax
00701368  8b4608                           mov    eax,DWORD PTR [esi+0x8]
0070136B  8930                             mov    DWORD PTR [eax],esi
0070136D  895808                           mov    DWORD PTR [eax+0x8],ebx
00701370  017e08                           add    DWORD PTR [esi+0x8],edi
00701373  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
00701376  8d41f0                           lea    eax,[ecx-0x10]
00701379  8b49e0                           mov    ecx,DWORD PTR [ecx-0x20]
0070137C  e8cf88ffff                       call   0x6f9c50
00701381  8b10                             mov    edx,DWORD PTR [eax]
00701383  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
00701386  2bcf                             sub    ecx,edi
00701388  8911                             mov    DWORD PTR [ecx],edx
0070138A  8b5004                           mov    edx,DWORD PTR [eax+0x4]
0070138D  895104                           mov    DWORD PTR [ecx+0x4],edx
00701390  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00701393  894108                           mov    DWORD PTR [ecx+0x8],eax
00701396  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00701399  2bc7                             sub    eax,edi
0070139B  3dc8bfc000                       cmp    eax,0xc0bfc8
007013A0  7452                             je     0x7013f4
007013A2  83780806                         cmp    DWORD PTR [eax+0x8],0x6
007013A6  754c                             jne    0x7013f4
007013A8  8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
007013AB  8b0b                             mov    ecx,DWORD PTR [ebx]
007013AD  8b148d08bec000                   mov    edx,DWORD PTR [ecx*4+0xc0be08]
007013B4  52                               push   edx
007013B5  e85641ffff                       call   0x6f5510
007013BA  8b5b14                           mov    ebx,DWORD PTR [ebx+0x14]
007013BD  8b4608                           mov    eax,DWORD PTR [esi+0x8]
007013C0  83c404                           add    esp,0x4
007013C3  895d08                           mov    DWORD PTR [ebp+0x8],ebx
007013C6  85db                             test   ebx,ebx
007013C8  780e                             js     0x7013d8
007013CA  db4508                           fild   DWORD PTR [ebp+0x8]
007013CD  c7400803000000                   mov    DWORD PTR [eax+0x8],0x3
007013D4  dd18                             fstp   QWORD PTR [eax]
007013D6  eb07                             jmp    0x7013df
007013D8  c7400800000000                   mov    DWORD PTR [eax+0x8],0x0
007013DF  017e08                           add    DWORD PTR [esi+0x8],edi
007013E2  8b4608                           mov    eax,DWORD PTR [esi+0x8]
007013E5  6a00                             push   0x0
007013E7  83c0d0                           add    eax,0xffffffd0
007013EA  50                               push   eax
007013EB  56                               push   esi
007013EC  e85fd1ffff                       call   0x6fe550
007013F1  83c40c                           add    esp,0xc
007013F4  5f                               pop    edi
007013F5  5e                               pop    esi
007013F6  5b                               pop    ebx
007013F7  5d                               pop    ebp
007013F8  c3                               ret

; H05 instruction fetch loop decrements thread hook count before opcode dispatch
; VA 0x6fc550..0x6fc5f8 RAW 0x2fb950 LEN 168 SHA256 02221a63bff2f7ca514c9d471f1145819fde52ac5d06e71c74bf7b1cfbb64f21
006FC550  55                               push   ebp
006FC551  8bec                             mov    ebp,esp
006FC553  83e4c0                           and    esp,0xffffffc0
006FC556  81ecb4000000                     sub    esp,0xb4
006FC55C  53                               push   ebx
006FC55D  56                               push   esi
006FC55E  57                               push   edi
006FC55F  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
006FC562  8b4f14                           mov    ecx,DWORD PTR [edi+0x14]
006FC565  8b4718                           mov    eax,DWORD PTR [edi+0x18]
006FC568  8b5104                           mov    edx,DWORD PTR [ecx+0x4]
006FC56B  8b4f0c                           mov    ecx,DWORD PTR [edi+0xc]
006FC56E  89442434                         mov    DWORD PTR [esp+0x34],eax
006FC572  8b02                             mov    eax,DWORD PTR [edx]
006FC574  8b5010                           mov    edx,DWORD PTR [eax+0x10]
006FC577  8944245c                         mov    DWORD PTR [esp+0x5c],eax
006FC57B  8b4208                           mov    eax,DWORD PTR [edx+0x8]
006FC57E  894c2438                         mov    DWORD PTR [esp+0x38],ecx
006FC582  89442440                         mov    DWORD PTR [esp+0x40],eax
006FC586  eb02                             jmp    0x6fc58a
006FC588  ddd8                             fstp   st(0)
006FC58A  8b442434                         mov    eax,DWORD PTR [esp+0x34]
006FC58E  8b18                             mov    ebx,DWORD PTR [eax]
006FC590  83c004                           add    eax,0x4
006FC593  89442434                         mov    DWORD PTR [esp+0x34],eax
006FC597  8a4738                           mov    al,BYTE PTR [edi+0x38]
006FC59A  a80c                             test   al,0xc
006FC59C  7429                             je     0x6fc5c7
006FC59E  ff4f40                           dec    DWORD PTR [edi+0x40]
006FC5A1  7404                             je     0x6fc5a7
006FC5A3  a804                             test   al,0x4
006FC5A5  7420                             je     0x6fc5c7
006FC5A7  8b4c2434                         mov    ecx,DWORD PTR [esp+0x34]
006FC5AB  51                               push   ecx
006FC5AC  8bf7                             mov    esi,edi
006FC5AE  e8adf0ffff                       call   0x6fb660
006FC5B3  83c404                           add    esp,0x4
006FC5B6  807f0601                         cmp    BYTE PTR [edi+0x6],0x1
006FC5BA  0f84c0100000                     je     0x6fd680
006FC5C0  8b570c                           mov    edx,DWORD PTR [edi+0xc]
006FC5C3  89542438                         mov    DWORD PTR [esp+0x38],edx
006FC5C7  8b4c2438                         mov    ecx,DWORD PTR [esp+0x38]
006FC5CB  8bc3                             mov    eax,ebx
006FC5CD  c1e806                           shr    eax,0x6
006FC5D0  25ff000000                       and    eax,0xff
006FC5D5  8944243c                         mov    DWORD PTR [esp+0x3c],eax
006FC5D9  c1e004                           shl    eax,0x4
006FC5DC  8d3408                           lea    esi,[eax+ecx*1]
006FC5DF  89442448                         mov    DWORD PTR [esp+0x48],eax
006FC5E3  8bc3                             mov    eax,ebx
006FC5E5  83e03f                           and    eax,0x3f
006FC5E8  89742444                         mov    DWORD PTR [esp+0x44],esi
006FC5EC  83f825                           cmp    eax,0x25
006FC5EF  7799                             ja     0x6fc58a
006FC5F1  ff248594d66f00                   jmp    DWORD PTR [eax*4+0x6fd694]

; H06 count and line event producer
; VA 0x6fb660..0x6fb6f5 RAW 0x2faa60 LEN 149 SHA256 ff9dc99163fe04ab054d03823810daddf1e46795ac72e0845dbb9e30069e91c9
006FB660  55                               push   ebp
006FB661  8bec                             mov    ebp,esp
006FB663  51                               push   ecx
006FB664  8a4638                           mov    al,BYTE PTR [esi+0x38]
006FB667  53                               push   ebx
006FB668  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
006FB66B  57                               push   edi
006FB66C  8b7e18                           mov    edi,DWORD PTR [esi+0x18]
006FB66F  8845ff                           mov    BYTE PTR [ebp-0x1],al
006FB672  895e18                           mov    DWORD PTR [esi+0x18],ebx
006FB675  a808                             test   al,0x8
006FB677  7420                             je     0x6fb699
006FB679  837e4000                         cmp    DWORD PTR [esi+0x40],0x0
006FB67D  751a                             jne    0x6fb699
006FB67F  8b463c                           mov    eax,DWORD PTR [esi+0x3c]
006FB682  6aff                             push   0xffffffff
006FB684  ba03000000                       mov    edx,0x3
006FB689  8bce                             mov    ecx,esi
006FB68B  894640                           mov    DWORD PTR [esi+0x40],eax
006FB68E  e84d270000                       call   0x6fdde0
006FB693  8a45ff                           mov    al,BYTE PTR [ebp-0x1]
006FB696  83c404                           add    esp,0x4
006FB699  a804                             test   al,0x4
006FB69B  7452                             je     0x6fb6ef
006FB69D  8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
006FB6A0  8b5104                           mov    edx,DWORD PTR [ecx+0x4]
006FB6A3  8b02                             mov    eax,DWORD PTR [edx]
006FB6A5  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
006FB6A8  8b510c                           mov    edx,DWORD PTR [ecx+0xc]
006FB6AB  8b4914                           mov    ecx,DWORD PTR [ecx+0x14]
006FB6AE  8bc3                             mov    eax,ebx
006FB6B0  2bc2                             sub    eax,edx
006FB6B2  c1f802                           sar    eax,0x2
006FB6B5  48                               dec    eax
006FB6B6  85c9                             test   ecx,ecx
006FB6B8  7405                             je     0x6fb6bf
006FB6BA  8b1c81                           mov    ebx,DWORD PTR [ecx+eax*4]
006FB6BD  eb02                             jmp    0x6fb6c1
006FB6BF  33db                             xor    ebx,ebx
006FB6C1  85c0                             test   eax,eax
006FB6C3  741a                             je     0x6fb6df
006FB6C5  397d08                           cmp    DWORD PTR [ebp+0x8],edi
006FB6C8  7615                             jbe    0x6fb6df
006FB6CA  85c9                             test   ecx,ecx
006FB6CC  740b                             je     0x6fb6d9
006FB6CE  2bfa                             sub    edi,edx
006FB6D0  c1ff02                           sar    edi,0x2
006FB6D3  8b4cb9fc                         mov    ecx,DWORD PTR [ecx+edi*4-0x4]
006FB6D7  eb02                             jmp    0x6fb6db
006FB6D9  33c9                             xor    ecx,ecx
006FB6DB  3bd9                             cmp    ebx,ecx
006FB6DD  7410                             je     0x6fb6ef
006FB6DF  53                               push   ebx
006FB6E0  ba02000000                       mov    edx,0x2
006FB6E5  8bce                             mov    ecx,esi
006FB6E7  e8f4260000                       call   0x6fdde0
006FB6EC  83c404                           add    esp,0x4
006FB6EF  5f                               pop    edi
006FB6F0  5b                               pop    ebx
006FB6F1  8be5                             mov    esp,ebp
006FB6F3  5d                               pop    ebp
006FB6F4  c3                               ret

; H07 hook dispatcher and reentry guard around indirect callback
; VA 0x6fdde0..0x6fdeb5 RAW 0x2fd1e0 LEN 213 SHA256 83ea7e81820125148aff6873b0ebccbc9c5b3a728d7c80ffd0b417db15559132
006FDDE0  55                               push   ebp
006FDDE1  8bec                             mov    ebp,esp
006FDDE3  83ec6c                           sub    esp,0x6c
006FDDE6  a1201fd600                       mov    eax,ds:0xd61f20
006FDDEB  33c5                             xor    eax,ebp
006FDDED  8945fc                           mov    DWORD PTR [ebp-0x4],eax
006FDDF0  56                               push   esi
006FDDF1  8bf1                             mov    esi,ecx
006FDDF3  8b4644                           mov    eax,DWORD PTR [esi+0x44]
006FDDF6  894594                           mov    DWORD PTR [ebp-0x6c],eax
006FDDF9  85c0                             test   eax,eax
006FDDFB  0f84a5000000                     je     0x6fdea6
006FDE01  807e3900                         cmp    BYTE PTR [esi+0x39],0x0
006FDE05  0f849b000000                     je     0x6fdea6
006FDE0B  8b4e20                           mov    ecx,DWORD PTR [esi+0x20]
006FDE0E  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FDE11  53                               push   ebx
006FDE12  8b5808                           mov    ebx,DWORD PTR [eax+0x8]
006FDE15  57                               push   edi
006FDE16  8b7e08                           mov    edi,DWORD PTR [esi+0x8]
006FDE19  2bf9                             sub    edi,ecx
006FDE1B  2bd9                             sub    ebx,ecx
006FDE1D  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
006FDE20  895598                           mov    DWORD PTR [ebp-0x68],edx
006FDE23  894dac                           mov    DWORD PTR [ebp-0x54],ecx
006FDE26  83fa04                           cmp    edx,0x4
006FDE29  7509                             jne    0x6fde34
006FDE2B  c745f800000000                   mov    DWORD PTR [ebp-0x8],0x0
006FDE32  eb19                             jmp    0x6fde4d
006FDE34  2b4628                           sub    eax,DWORD PTR [esi+0x28]
006FDE37  8bc8                             mov    ecx,eax
006FDE39  b8abaaaa2a                       mov    eax,0x2aaaaaab
006FDE3E  f7e9                             imul   ecx
006FDE40  c1fa02                           sar    edx,0x2
006FDE43  8bc2                             mov    eax,edx
006FDE45  c1e81f                           shr    eax,0x1f
006FDE48  03c2                             add    eax,edx
006FDE4A  8945f8                           mov    DWORD PTR [ebp-0x8],eax
006FDE4D  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
006FDE50  2b4e08                           sub    ecx,DWORD PTR [esi+0x8]
006FDE53  81f940010000                     cmp    ecx,0x140
006FDE59  7f14                             jg     0x6fde6f
006FDE5B  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
006FDE5E  83f814                           cmp    eax,0x14
006FDE61  7c04                             jl     0x6fde67
006FDE63  03c0                             add    eax,eax
006FDE65  eb03                             jmp    0x6fde6a
006FDE67  83c014                           add    eax,0x14
006FDE6A  e841feffff                       call   0x6fdcb0
006FDE6F  8b5608                           mov    edx,DWORD PTR [esi+0x8]
006FDE72  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FDE75  8d4d98                           lea    ecx,[ebp-0x68]
006FDE78  81c240010000                     add    edx,0x140
006FDE7E  51                               push   ecx
006FDE7F  895008                           mov    DWORD PTR [eax+0x8],edx
006FDE82  56                               push   esi
006FDE83  c6463900                         mov    BYTE PTR [esi+0x39],0x0
006FDE87  ff5594                           call   DWORD PTR [ebp-0x6c]
006FDE8A  8b5620                           mov    edx,DWORD PTR [esi+0x20]
006FDE8D  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FDE90  03d3                             add    edx,ebx
006FDE92  c6463901                         mov    BYTE PTR [esi+0x39],0x1
006FDE96  895008                           mov    DWORD PTR [eax+0x8],edx
006FDE99  8b4e20                           mov    ecx,DWORD PTR [esi+0x20]
006FDE9C  83c408                           add    esp,0x8
006FDE9F  03cf                             add    ecx,edi
006FDEA1  5f                               pop    edi
006FDEA2  894e08                           mov    DWORD PTR [esi+0x8],ecx
006FDEA5  5b                               pop    ebx
006FDEA6  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
006FDEA9  33cd                             xor    ecx,ebp
006FDEAB  5e                               pop    esi
006FDEAC  e850311900                       call   0x891001
006FDEB1  8be5                             mov    esp,ebp
006FDEB3  5d                               pop    ebp
006FDEB4  c3                               ret

; H08 Lua and C function precall producers of event 0
; VA 0x6fe1c0..0x6fe394 RAW 0x2fd5c0 LEN 468 SHA256 cdc97c3e9ef59235e8072416e3f980d7a418db3239539c2704e8a5e821692ec7
006FE1C0  55                               push   ebp
006FE1C1  8bec                             mov    ebp,esp
006FE1C3  83ec08                           sub    esp,0x8
006FE1C6  83780806                         cmp    DWORD PTR [eax+0x8],0x6
006FE1CA  53                               push   ebx
006FE1CB  56                               push   esi
006FE1CC  57                               push   edi
006FE1CD  8bf1                             mov    esi,ecx
006FE1CF  740b                             je     0x6fe1dc
006FE1D1  50                               push   eax
006FE1D2  8bfe                             mov    edi,esi
006FE1D4  e807ffffff                       call   0x6fe0e0
006FE1D9  83c404                           add    esp,0x4
006FE1DC  8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
006FE1DF  8b5618                           mov    edx,DWORD PTR [esi+0x18]
006FE1E2  8bd8                             mov    ebx,eax
006FE1E4  2b5e20                           sub    ebx,DWORD PTR [esi+0x20]
006FE1E7  8b00                             mov    eax,DWORD PTR [eax]
006FE1E9  89510c                           mov    DWORD PTR [ecx+0xc],edx
006FE1EC  80780600                         cmp    BYTE PTR [eax+0x6],0x0
006FE1F0  895df8                           mov    DWORD PTR [ebp-0x8],ebx
006FE1F3  0f85ed000000                     jne    0x6fe2e6
006FE1F9  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
006FE1FC  0fb6414b                         movzx  eax,BYTE PTR [ecx+0x4b]
006FE200  8b561c                           mov    edx,DWORD PTR [esi+0x1c]
006FE203  2b5608                           sub    edx,DWORD PTR [esi+0x8]
006FE206  8bf8                             mov    edi,eax
006FE208  c1e704                           shl    edi,0x4
006FE20B  894dfc                           mov    DWORD PTR [ebp-0x4],ecx
006FE20E  3bd7                             cmp    edx,edi
006FE210  7f16                             jg     0x6fe228
006FE212  8b4e2c                           mov    ecx,DWORD PTR [esi+0x2c]
006FE215  3bc1                             cmp    eax,ecx
006FE217  7f05                             jg     0x6fe21e
006FE219  8d0409                           lea    eax,[ecx+ecx*1]
006FE21C  eb02                             jmp    0x6fe220
006FE21E  03c1                             add    eax,ecx
006FE220  e88bfaffff                       call   0x6fdcb0
006FE225  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
006FE228  8b7e20                           mov    edi,DWORD PTR [esi+0x20]
006FE22B  03fb                             add    edi,ebx
006FE22D  80794a00                         cmp    BYTE PTR [ecx+0x4a],0x0
006FE231  7516                             jne    0x6fe249
006FE233  0fb64149                         movzx  eax,BYTE PTR [ecx+0x49]
006FE237  c1e004                           shl    eax,0x4
006FE23A  8d5f10                           lea    ebx,[edi+0x10]
006FE23D  03c3                             add    eax,ebx
006FE23F  394608                           cmp    DWORD PTR [esi+0x8],eax
006FE242  7625                             jbe    0x6fe269
006FE244  894608                           mov    DWORD PTR [esi+0x8],eax
006FE247  eb20                             jmp    0x6fe269
006FE249  8b4608                           mov    eax,DWORD PTR [esi+0x8]
006FE24C  2bc7                             sub    eax,edi
006FE24E  c1f804                           sar    eax,0x4
006FE251  48                               dec    eax
006FE252  50                               push   eax
006FE253  56                               push   esi
006FE254  8bc1                             mov    eax,ecx
006FE256  e865fcffff                       call   0x6fdec0
006FE25B  8b7e20                           mov    edi,DWORD PTR [esi+0x20]
006FE25E  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
006FE261  83c408                           add    esp,0x8
006FE264  037df8                           add    edi,DWORD PTR [ebp-0x8]
006FE267  8bd8                             mov    ebx,eax
006FE269  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FE26C  3b4624                           cmp    eax,DWORD PTR [esi+0x24]
006FE26F  750c                             jne    0x6fe27d
006FE271  8bc6                             mov    eax,esi
006FE273  e818fbffff                       call   0x6fdd90
006FE278  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
006FE27B  eb06                             jmp    0x6fe283
006FE27D  83c018                           add    eax,0x18
006FE280  894614                           mov    DWORD PTR [esi+0x14],eax
006FE283  897804                           mov    DWORD PTR [eax+0x4],edi
006FE286  8918                             mov    DWORD PTR [eax],ebx
006FE288  895e0c                           mov    DWORD PTR [esi+0xc],ebx
006FE28B  0fb6514b                         movzx  edx,BYTE PTR [ecx+0x4b]
006FE28F  c1e204                           shl    edx,0x4
006FE292  03d3                             add    edx,ebx
006FE294  895008                           mov    DWORD PTR [eax+0x8],edx
006FE297  8b490c                           mov    ecx,DWORD PTR [ecx+0xc]
006FE29A  894e18                           mov    DWORD PTR [esi+0x18],ecx
006FE29D  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
006FE2A0  33d2                             xor    edx,edx
006FE2A2  895014                           mov    DWORD PTR [eax+0x14],edx
006FE2A5  894810                           mov    DWORD PTR [eax+0x10],ecx
006FE2A8  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
006FE2AB  3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
006FE2AE  730b                             jae    0x6fe2bb
006FE2B0  895108                           mov    DWORD PTR [ecx+0x8],edx
006FE2B3  83c110                           add    ecx,0x10
006FE2B6  3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
006FE2B9  72f5                             jb     0x6fe2b0
006FE2BB  f6463801                         test   BYTE PTR [esi+0x38],0x1
006FE2BF  8b5008                           mov    edx,DWORD PTR [eax+0x8]
006FE2C2  895608                           mov    DWORD PTR [esi+0x8],edx
006FE2C5  7416                             je     0x6fe2dd
006FE2C7  83461804                         add    DWORD PTR [esi+0x18],0x4
006FE2CB  6aff                             push   0xffffffff
006FE2CD  33d2                             xor    edx,edx
006FE2CF  8bce                             mov    ecx,esi
006FE2D1  e80afbffff                       call   0x6fdde0
006FE2D6  83c404                           add    esp,0x4
006FE2D9  834618fc                         add    DWORD PTR [esi+0x18],0xfffffffc
006FE2DD  33c0                             xor    eax,eax
006FE2DF  5f                               pop    edi
006FE2E0  5e                               pop    esi
006FE2E1  5b                               pop    ebx
006FE2E2  8be5                             mov    esp,ebp
006FE2E4  5d                               pop    ebp
006FE2E5  c3                               ret
006FE2E6  8b461c                           mov    eax,DWORD PTR [esi+0x1c]
006FE2E9  2b4608                           sub    eax,DWORD PTR [esi+0x8]
006FE2EC  3d40010000                       cmp    eax,0x140
006FE2F1  7f14                             jg     0x6fe307
006FE2F3  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
006FE2F6  83f814                           cmp    eax,0x14
006FE2F9  7c04                             jl     0x6fe2ff
006FE2FB  03c0                             add    eax,eax
006FE2FD  eb03                             jmp    0x6fe302
006FE2FF  83c014                           add    eax,0x14
006FE302  e8a9f9ffff                       call   0x6fdcb0
006FE307  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FE30A  3b4624                           cmp    eax,DWORD PTR [esi+0x24]
006FE30D  7509                             jne    0x6fe318
006FE30F  8bc6                             mov    eax,esi
006FE311  e87afaffff                       call   0x6fdd90
006FE316  eb06                             jmp    0x6fe31e
006FE318  83c018                           add    eax,0x18
006FE31B  894614                           mov    DWORD PTR [esi+0x14],eax
006FE31E  8b4e20                           mov    ecx,DWORD PTR [esi+0x20]
006FE321  03cb                             add    ecx,ebx
006FE323  894804                           mov    DWORD PTR [eax+0x4],ecx
006FE326  83c110                           add    ecx,0x10
006FE329  8908                             mov    DWORD PTR [eax],ecx
006FE32B  8b5608                           mov    edx,DWORD PTR [esi+0x8]
006FE32E  894e0c                           mov    DWORD PTR [esi+0xc],ecx
006FE331  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
006FE334  81c240010000                     add    edx,0x140
006FE33A  895008                           mov    DWORD PTR [eax+0x8],edx
006FE33D  894810                           mov    DWORD PTR [eax+0x10],ecx
006FE340  f6463801                         test   BYTE PTR [esi+0x38],0x1
006FE344  740e                             je     0x6fe354
006FE346  6aff                             push   0xffffffff
006FE348  33d2                             xor    edx,edx
006FE34A  8bce                             mov    ecx,esi
006FE34C  e88ffaffff                       call   0x6fdde0
006FE351  83c404                           add    esp,0x4
006FE354  8b5614                           mov    edx,DWORD PTR [esi+0x14]
006FE357  8b4204                           mov    eax,DWORD PTR [edx+0x4]
006FE35A  8b08                             mov    ecx,DWORD PTR [eax]
006FE35C  8b5110                           mov    edx,DWORD PTR [ecx+0x10]
006FE35F  56                               push   esi
006FE360  ffd2                             call   edx
006FE362  83c404                           add    esp,0x4
006FE365  85c0                             test   eax,eax
006FE367  790c                             jns    0x6fe375
006FE369  b802000000                       mov    eax,0x2
006FE36E  5f                               pop    edi
006FE36F  5e                               pop    esi
006FE370  5b                               pop    ebx
006FE371  8be5                             mov    esp,ebp
006FE373  5d                               pop    ebp
006FE374  c3                               ret
006FE375  c1e004                           shl    eax,0x4
006FE378  8bc8                             mov    ecx,eax
006FE37A  8b4608                           mov    eax,DWORD PTR [esi+0x8]
006FE37D  2bc1                             sub    eax,ecx
006FE37F  56                               push   esi
006FE380  e83b010000                       call   0x6fe4c0
006FE385  83c404                           add    esp,0x4
006FE388  5f                               pop    edi
006FE389  5e                               pop    esi
006FE38A  b801000000                       mov    eax,0x1
006FE38F  5b                               pop    ebx
006FE390  8be5                             mov    esp,ebp
006FE392  5d                               pop    ebp
006FE393  c3                               ret

; H09 return event and inline tail-return hook callback
; VA 0x6fe3a0..0x6fe4b6 RAW 0x2fd7a0 LEN 278 SHA256 5cea95adfcb0a18b991653b509af992080586c1858a44cfa40155ce49d3315a7
006FE3A0  55                               push   ebp
006FE3A1  8bec                             mov    ebp,esp
006FE3A3  83ec70                           sub    esp,0x70
006FE3A6  a1201fd600                       mov    eax,ds:0xd61f20
006FE3AB  33c5                             xor    eax,ebp
006FE3AD  8945fc                           mov    DWORD PTR [ebp-0x4],eax
006FE3B0  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
006FE3B3  56                               push   esi
006FE3B4  8bf1                             mov    esi,ecx
006FE3B6  2b4620                           sub    eax,DWORD PTR [esi+0x20]
006FE3B9  6aff                             push   0xffffffff
006FE3BB  ba01000000                       mov    edx,0x1
006FE3C0  894594                           mov    DWORD PTR [ebp-0x6c],eax
006FE3C3  e818faffff                       call   0x6fdde0
006FE3C8  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FE3CB  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
006FE3CE  8b11                             mov    edx,DWORD PTR [ecx]
006FE3D0  83c404                           add    esp,0x4
006FE3D3  807a0600                         cmp    BYTE PTR [edx+0x6],0x0
006FE3D7  0f85c4000000                     jne    0x6fe4a1
006FE3DD  f6463802                         test   BYTE PTR [esi+0x38],0x2
006FE3E1  0f84ba000000                     je     0x6fe4a1
006FE3E7  53                               push   ebx
006FE3E8  57                               push   edi
006FE3E9  8da42400000000                   lea    esp,[esp+0x0]
006FE3F0  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FE3F3  8b4814                           mov    ecx,DWORD PTR [eax+0x14]
006FE3F6  8d51ff                           lea    edx,[ecx-0x1]
006FE3F9  895014                           mov    DWORD PTR [eax+0x14],edx
006FE3FC  85c9                             test   ecx,ecx
006FE3FE  0f849b000000                     je     0x6fe49f
006FE404  8b4644                           mov    eax,DWORD PTR [esi+0x44]
006FE407  894590                           mov    DWORD PTR [ebp-0x70],eax
006FE40A  85c0                             test   eax,eax
006FE40C  0f8483000000                     je     0x6fe495
006FE412  807e3900                         cmp    BYTE PTR [esi+0x39],0x0
006FE416  747d                             je     0x6fe495
006FE418  8b4608                           mov    eax,DWORD PTR [esi+0x8]
006FE41B  8b4e20                           mov    ecx,DWORD PTR [esi+0x20]
006FE41E  8b5614                           mov    edx,DWORD PTR [esi+0x14]
006FE421  8b5a08                           mov    ebx,DWORD PTR [edx+0x8]
006FE424  8bf8                             mov    edi,eax
006FE426  2bf9                             sub    edi,ecx
006FE428  2bd9                             sub    ebx,ecx
006FE42A  8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
006FE42D  2bc8                             sub    ecx,eax
006FE42F  c7459804000000                   mov    DWORD PTR [ebp-0x68],0x4
006FE436  c745acffffffff                   mov    DWORD PTR [ebp-0x54],0xffffffff
006FE43D  c745f800000000                   mov    DWORD PTR [ebp-0x8],0x0
006FE444  81f940010000                     cmp    ecx,0x140
006FE44A  7f14                             jg     0x6fe460
006FE44C  8b462c                           mov    eax,DWORD PTR [esi+0x2c]
006FE44F  83f814                           cmp    eax,0x14
006FE452  7c04                             jl     0x6fe458
006FE454  03c0                             add    eax,eax
006FE456  eb03                             jmp    0x6fe45b
006FE458  83c014                           add    eax,0x14
006FE45B  e850f8ffff                       call   0x6fdcb0
006FE460  8b5608                           mov    edx,DWORD PTR [esi+0x8]
006FE463  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FE466  8d4d98                           lea    ecx,[ebp-0x68]
006FE469  81c240010000                     add    edx,0x140
006FE46F  51                               push   ecx
006FE470  895008                           mov    DWORD PTR [eax+0x8],edx
006FE473  56                               push   esi
006FE474  c6463900                         mov    BYTE PTR [esi+0x39],0x0
006FE478  ff5590                           call   DWORD PTR [ebp-0x70]
006FE47B  8b5620                           mov    edx,DWORD PTR [esi+0x20]
006FE47E  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006FE481  03d3                             add    edx,ebx
006FE483  c6463901                         mov    BYTE PTR [esi+0x39],0x1
006FE487  895008                           mov    DWORD PTR [eax+0x8],edx
006FE48A  8b4e20                           mov    ecx,DWORD PTR [esi+0x20]
006FE48D  83c408                           add    esp,0x8
006FE490  03cf                             add    ecx,edi
006FE492  894e08                           mov    DWORD PTR [esi+0x8],ecx
006FE495  f6463802                         test   BYTE PTR [esi+0x38],0x2
006FE499  0f8551ffffff                     jne    0x6fe3f0
006FE49F  5f                               pop    edi
006FE4A0  5b                               pop    ebx
006FE4A1  8b4620                           mov    eax,DWORD PTR [esi+0x20]
006FE4A4  8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
006FE4A7  034594                           add    eax,DWORD PTR [ebp-0x6c]
006FE4AA  33cd                             xor    ecx,ebp
006FE4AC  5e                               pop    esi
006FE4AD  e84f2b1900                       call   0x891001
006FE4B2  8be5                             mov    esp,ebp
006FE4B4  5d                               pop    ebp
006FE4B5  c3                               ret

; H10 function return path gates return/tail-return hooks by bit 2
; VA 0x6fe4c0..0x6fe548 RAW 0x2fd8c0 LEN 136 SHA256 f8b78b6ed21ac373130454a4547d800c0cb269a617fe6bb24bee4a67e76c8587
006FE4C0  55                               push   ebp
006FE4C1  8bec                             mov    ebp,esp
006FE4C3  51                               push   ecx
006FE4C4  53                               push   ebx
006FE4C5  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
006FE4C8  f6433802                         test   BYTE PTR [ebx+0x38],0x2
006FE4CC  56                               push   esi
006FE4CD  57                               push   edi
006FE4CE  740b                             je     0x6fe4db
006FE4D0  50                               push   eax
006FE4D1  8bcb                             mov    ecx,ebx
006FE4D3  e8c8feffff                       call   0x6fe3a0
006FE4D8  83c404                           add    esp,0x4
006FE4DB  8b5314                           mov    edx,DWORD PTR [ebx+0x14]
006FE4DE  8d72e8                           lea    esi,[edx-0x18]
006FE4E1  897314                           mov    DWORD PTR [ebx+0x14],esi
006FE4E4  8b7a10                           mov    edi,DWORD PTR [edx+0x10]
006FE4E7  8b36                             mov    esi,DWORD PTR [esi]
006FE4E9  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
006FE4EC  89730c                           mov    DWORD PTR [ebx+0xc],esi
006FE4EF  8b52f4                           mov    edx,DWORD PTR [edx-0xc]
006FE4F2  897dfc                           mov    DWORD PTR [ebp-0x4],edi
006FE4F5  895318                           mov    DWORD PTR [ebx+0x18],edx
006FE4F8  8bf7                             mov    esi,edi
006FE4FA  85ff                             test   edi,edi
006FE4FC  742a                             je     0x6fe528
006FE4FE  8bf8                             mov    edi,eax
006FE500  3b7b08                           cmp    edi,DWORD PTR [ebx+0x8]
006FE503  7320                             jae    0x6fe525
006FE505  8bc7                             mov    eax,edi
006FE507  8b18                             mov    ebx,DWORD PTR [eax]
006FE509  8bd1                             mov    edx,ecx
006FE50B  891a                             mov    DWORD PTR [edx],ebx
006FE50D  8b5804                           mov    ebx,DWORD PTR [eax+0x4]
006FE510  895a04                           mov    DWORD PTR [edx+0x4],ebx
006FE513  8b4008                           mov    eax,DWORD PTR [eax+0x8]
006FE516  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
006FE519  83c110                           add    ecx,0x10
006FE51C  83c710                           add    edi,0x10
006FE51F  4e                               dec    esi
006FE520  894208                           mov    DWORD PTR [edx+0x8],eax
006FE523  75db                             jne    0x6fe500
006FE525  8b7dfc                           mov    edi,DWORD PTR [ebp-0x4]
006FE528  33c0                             xor    eax,eax
006FE52A  3bf0                             cmp    esi,eax
006FE52C  7e0d                             jle    0x6fe53b
006FE52E  8bff                             mov    edi,edi
006FE530  4e                               dec    esi
006FE531  894108                           mov    DWORD PTR [ecx+0x8],eax
006FE534  83c110                           add    ecx,0x10
006FE537  3bf0                             cmp    esi,eax
006FE539  7ff5                             jg     0x6fe530
006FE53B  8d4701                           lea    eax,[edi+0x1]
006FE53E  5f                               pop    edi
006FE53F  5e                               pop    esi
006FE540  894b08                           mov    DWORD PTR [ebx+0x8],ecx
006FE543  5b                               pop    ebx
006FE544  8be5                             mov    esp,ebp
006FE546  5d                               pop    ebp
006FE547  c3                               ret

; H11 new thread initialization and parent native hook fields copied
; VA 0x6f7390..0x6f7457 RAW 0x2f6790 LEN 199 SHA256 90eda11f96b8dc1ee811b9bdf2a847035276d8c5bad277364e53f2d19ca73237
006F7390  55                               push   ebp
006F7391  8bec                             mov    ebp,esp
006F7393  83e4f8                           and    esp,0xfffffff8
006F7396  51                               push   ecx
006F7397  53                               push   ebx
006F7398  56                               push   esi
006F7399  57                               push   edi
006F739A  6a78                             push   0x78
006F739C  8bf8                             mov    edi,eax
006F739E  8b4710                           mov    eax,DWORD PTR [edi+0x10]
006F73A1  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
006F73A4  8b500c                           mov    edx,DWORD PTR [eax+0xc]
006F73A7  33db                             xor    ebx,ebx
006F73A9  53                               push   ebx
006F73AA  53                               push   ebx
006F73AB  51                               push   ecx
006F73AC  8944241c                         mov    DWORD PTR [esp+0x1c],eax
006F73B0  ffd2                             call   edx
006F73B2  8bf0                             mov    esi,eax
006F73B4  83c410                           add    esp,0x10
006F73B7  3bf3                             cmp    esi,ebx
006F73B9  7508                             jne    0x6f73c3
006F73BB  6a04                             push   0x4
006F73BD  57                               push   edi
006F73BE  e87d670000                       call   0x6fdb40
006F73C3  8b44240c                         mov    eax,DWORD PTR [esp+0xc]
006F73C7  83404478                         add    DWORD PTR [eax+0x44],0x78
006F73CB  8b4710                           mov    eax,DWORD PTR [edi+0x10]
006F73CE  8b481c                           mov    ecx,DWORD PTR [eax+0x1c]
006F73D1  890e                             mov    DWORD PTR [esi],ecx
006F73D3  8a5014                           mov    dl,BYTE PTR [eax+0x14]
006F73D6  89701c                           mov    DWORD PTR [eax+0x1c],esi
006F73D9  80e203                           and    dl,0x3
006F73DC  885605                           mov    BYTE PTR [esi+0x5],dl
006F73DF  c6460408                         mov    BYTE PTR [esi+0x4],0x8
006F73E3  8b4710                           mov    eax,DWORD PTR [edi+0x10]
006F73E6  33d2                             xor    edx,edx
006F73E8  894610                           mov    DWORD PTR [esi+0x10],eax
006F73EB  895e20                           mov    DWORD PTR [esi+0x20],ebx
006F73EE  895e2c                           mov    DWORD PTR [esi+0x2c],ebx
006F73F1  895e70                           mov    DWORD PTR [esi+0x70],ebx
006F73F4  895e44                           mov    DWORD PTR [esi+0x44],ebx
006F73F7  895e3c                           mov    DWORD PTR [esi+0x3c],ebx
006F73FA  895e40                           mov    DWORD PTR [esi+0x40],ebx
006F73FD  895e68                           mov    DWORD PTR [esi+0x68],ebx
006F7400  895e30                           mov    DWORD PTR [esi+0x30],ebx
006F7403  c7463600000001                   mov    DWORD PTR [esi+0x36],0x1000000
006F740A  66895634                         mov    WORD PTR [esi+0x34],dx
006F740E  885e06                           mov    BYTE PTR [esi+0x6],bl
006F7411  895e14                           mov    DWORD PTR [esi+0x14],ebx
006F7414  895e28                           mov    DWORD PTR [esi+0x28],ebx
006F7417  895e18                           mov    DWORD PTR [esi+0x18],ebx
006F741A  895e74                           mov    DWORD PTR [esi+0x74],ebx
006F741D  895e50                           mov    DWORD PTR [esi+0x50],ebx
006F7420  e8dbfdffff                       call   0x6f7200
006F7425  8b4748                           mov    eax,DWORD PTR [edi+0x48]
006F7428  894648                           mov    DWORD PTR [esi+0x48],eax
006F742B  8b4f4c                           mov    ecx,DWORD PTR [edi+0x4c]
006F742E  894e4c                           mov    DWORD PTR [esi+0x4c],ecx
006F7431  8b5750                           mov    edx,DWORD PTR [edi+0x50]
006F7434  895650                           mov    DWORD PTR [esi+0x50],edx
006F7437  8a4738                           mov    al,BYTE PTR [edi+0x38]
006F743A  884638                           mov    BYTE PTR [esi+0x38],al
006F743D  8b4f3c                           mov    ecx,DWORD PTR [edi+0x3c]
006F7440  894e3c                           mov    DWORD PTR [esi+0x3c],ecx
006F7443  8b5744                           mov    edx,DWORD PTR [edi+0x44]
006F7446  8bc1                             mov    eax,ecx
006F7448  894640                           mov    DWORD PTR [esi+0x40],eax
006F744B  5f                               pop    edi
006F744C  895644                           mov    DWORD PTR [esi+0x44],edx
006F744F  8bc6                             mov    eax,esi
006F7451  5e                               pop    esi
006F7452  5b                               pop    ebx
006F7453  8be5                             mov    esp,ebp
006F7455  5d                               pop    ebp
006F7456  c3                               ret

; H12 new thread stack initialization; no hook registry store
; VA 0x6f7200..0x6f727d RAW 0x2f6600 LEN 125 SHA256 71c8a9fb5f53e8d82639c3e4916d4f681e0e7a8ab0694ac7b253403d0a056e11
006F7200  68c0000000                       push   0xc0
006F7205  6a00                             push   0x0
006F7207  6a00                             push   0x0
006F7209  57                               push   edi
006F720A  e871960000                       call   0x700880
006F720F  68d0020000                       push   0x2d0
006F7214  6a00                             push   0x0
006F7216  894628                           mov    DWORD PTR [esi+0x28],eax
006F7219  894614                           mov    DWORD PTR [esi+0x14],eax
006F721C  05a8000000                       add    eax,0xa8
006F7221  6a00                             push   0x0
006F7223  57                               push   edi
006F7224  c7463008000000                   mov    DWORD PTR [esi+0x30],0x8
006F722B  894624                           mov    DWORD PTR [esi+0x24],eax
006F722E  e84d960000                       call   0x700880
006F7233  8b5614                           mov    edx,DWORD PTR [esi+0x14]
006F7236  894608                           mov    DWORD PTR [esi+0x8],eax
006F7239  894620                           mov    DWORD PTR [esi+0x20],eax
006F723C  8d8870020000                     lea    ecx,[eax+0x270]
006F7242  894e1c                           mov    DWORD PTR [esi+0x1c],ecx
006F7245  c7462c2d000000                   mov    DWORD PTR [esi+0x2c],0x2d
006F724C  894204                           mov    DWORD PTR [edx+0x4],eax
006F724F  8b4608                           mov    eax,DWORD PTR [esi+0x8]
006F7252  c7400800000000                   mov    DWORD PTR [eax+0x8],0x0
006F7259  83460810                         add    DWORD PTR [esi+0x8],0x10
006F725D  8b4608                           mov    eax,DWORD PTR [esi+0x8]
006F7260  8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
006F7263  8901                             mov    DWORD PTR [ecx],eax
006F7265  8b4614                           mov    eax,DWORD PTR [esi+0x14]
006F7268  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
006F726B  8b10                             mov    edx,DWORD PTR [eax]
006F726D  81c140010000                     add    ecx,0x140
006F7273  89560c                           mov    DWORD PTR [esi+0xc],edx
006F7276  83c420                           add    esp,0x20
006F7279  894808                           mov    DWORD PTR [eax+0x8],ecx
006F727C  c3                               ret

; H13 coroutine.create creates child state and transfers Lua callable
; VA 0x707380..0x707444 RAW 0x306780 LEN 196 SHA256 b9caa25028e918ccc8c1d80cdbb8b851890b0ff666ff9c74faf4223d5e3a8129
00707380  55                               push   ebp
00707381  8bec                             mov    ebp,esp
00707383  53                               push   ebx
00707384  56                               push   esi
00707385  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
00707388  8b4610                           mov    eax,DWORD PTR [esi+0x10]
0070738B  8b4844                           mov    ecx,DWORD PTR [eax+0x44]
0070738E  3b4840                           cmp    ecx,DWORD PTR [eax+0x40]
00707391  7207                             jb     0x70739a
00707393  8bc6                             mov    eax,esi
00707395  e80640ffff                       call   0x6fb3a0
0070739A  8bc6                             mov    eax,esi
0070739C  e8effffeff                       call   0x6f7390
007073A1  8bd8                             mov    ebx,eax
007073A3  8b4608                           mov    eax,DWORD PTR [esi+0x8]
007073A6  8918                             mov    DWORD PTR [eax],ebx
007073A8  c7400808000000                   mov    DWORD PTR [eax+0x8],0x8
007073AF  83460810                         add    DWORD PTR [esi+0x8],0x10
007073B3  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007073B6  8b460c                           mov    eax,DWORD PTR [esi+0xc]
007073B9  3bc1                             cmp    eax,ecx
007073BB  7324                             jae    0x7073e1
007073BD  3dc8bfc000                       cmp    eax,0xc0bfc8
007073C2  741d                             je     0x7073e1
007073C4  83780806                         cmp    DWORD PTR [eax+0x8],0x6
007073C8  7517                             jne    0x7073e1
007073CA  3bc1                             cmp    eax,ecx
007073CC  7205                             jb     0x7073d3
007073CE  b8c8bfc000                       mov    eax,0xc0bfc8
007073D3  83780806                         cmp    DWORD PTR [eax+0x8],0x6
007073D7  7519                             jne    0x7073f2
007073D9  8b10                             mov    edx,DWORD PTR [eax]
007073DB  807a0600                         cmp    BYTE PTR [edx+0x6],0x0
007073DF  7411                             je     0x7073f2
007073E1  57                               push   edi
007073E2  6a01                             push   0x1
007073E4  bff836c400                       mov    edi,0xc436f8
007073E9  e8b2e9feff                       call   0x6f5da0
007073EE  83c404                           add    esp,0x4
007073F1  5f                               pop    edi
007073F2  8b460c                           mov    eax,DWORD PTR [esi+0xc]
007073F5  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007073F8  3bc1                             cmp    eax,ecx
007073FA  7205                             jb     0x707401
007073FC  b8c8bfc000                       mov    eax,0xc0bfc8
00707401  8b10                             mov    edx,DWORD PTR [eax]
00707403  8911                             mov    DWORD PTR [ecx],edx
00707405  8b5004                           mov    edx,DWORD PTR [eax+0x4]
00707408  895104                           mov    DWORD PTR [ecx+0x4],edx
0070740B  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0070740E  894108                           mov    DWORD PTR [ecx+0x8],eax
00707411  83460810                         add    DWORD PTR [esi+0x8],0x10
00707415  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00707418  3bf3                             cmp    esi,ebx
0070741A  741f                             je     0x70743b
0070741C  83c0f0                           add    eax,0xfffffff0
0070741F  894608                           mov    DWORD PTR [esi+0x8],eax
00707422  8b4b08                           mov    ecx,DWORD PTR [ebx+0x8]
00707425  8d5110                           lea    edx,[ecx+0x10]
00707428  895308                           mov    DWORD PTR [ebx+0x8],edx
0070742B  8b10                             mov    edx,DWORD PTR [eax]
0070742D  8911                             mov    DWORD PTR [ecx],edx
0070742F  8b5004                           mov    edx,DWORD PTR [eax+0x4]
00707432  895104                           mov    DWORD PTR [ecx+0x4],edx
00707435  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00707438  894108                           mov    DWORD PTR [ecx+0x8],eax
0070743B  5e                               pop    esi
0070743C  b801000000                       mov    eax,0x1
00707441  5b                               pop    ebx
00707442  5d                               pop    ebp
00707443  c3                               ret

; H14 gethook compares installed callback; second literal is not registration
; VA 0x7016c0..0x70171b RAW 0x300ac0 LEN 91 SHA256 535b260722cf99ce5a2661f0a9c2e88306ab1fd94e0a2135faebca53d404b316
007016C0  55                               push   ebp
007016C1  8bec                             mov    ebp,esp
007016C3  83ec0c                           sub    esp,0xc
007016C6  a1201fd600                       mov    eax,ds:0xd61f20
007016CB  33c5                             xor    eax,ebp
007016CD  8945fc                           mov    DWORD PTR [ebp-0x4],eax
007016D0  53                               push   ebx
007016D1  56                               push   esi
007016D2  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
007016D5  8b460c                           mov    eax,DWORD PTR [esi+0xc]
007016D8  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007016DB  57                               push   edi
007016DC  3bc1                             cmp    eax,ecx
007016DE  7324                             jae    0x701704
007016E0  3dc8bfc000                       cmp    eax,0xc0bfc8
007016E5  741d                             je     0x701704
007016E7  83780808                         cmp    DWORD PTR [eax+0x8],0x8
007016EB  7517                             jne    0x701704
007016ED  3bc1                             cmp    eax,ecx
007016EF  7205                             jb     0x7016f6
007016F1  b8c8bfc000                       mov    eax,0xc0bfc8
007016F6  83780808                         cmp    DWORD PTR [eax+0x8],0x8
007016FA  7404                             je     0x701700
007016FC  33ff                             xor    edi,edi
007016FE  eb06                             jmp    0x701706
00701700  8b38                             mov    edi,DWORD PTR [eax]
00701702  eb02                             jmp    0x701706
00701704  8bfe                             mov    edi,esi
00701706  0fb64738                         movzx  eax,BYTE PTR [edi+0x38]
0070170A  8945f4                           mov    DWORD PTR [ebp-0xc],eax
0070170D  8b4744                           mov    eax,DWORD PTR [edi+0x44]
00701710  85c0                             test   eax,eax
00701712  743f                             je     0x701753
00701714  3d20137000                       cmp    eax,0x701320
00701719  7438                             je     0x701753

; H15 standard debug library registration
; VA 0x701e00..0x701e1f RAW 0x301200 LEN 31 SHA256 81abc4f309301cb4265fb0ffb6d720aeba0771a1bdb015020636af548539466b
00701E00  55                               push   ebp
00701E01  8bec                             mov    ebp,esp
00701E03  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00701E06  6848bec000                       push   0xc0be48
00701E0B  686428c400                       push   0xc42864
00701E10  e87b47ffff                       call   0x6f6590
00701E15  83c408                           add    esp,0x8
00701E18  b801000000                       mov    eax,0x1
00701E1D  5d                               pop    ebp
00701E1E  c3                               ret

; I01 Tutorial.SetKeymapEnabled native target and closure registration
; VA 0x4aa900..0x4aa999 RAW 0xa9d00 LEN 153 SHA256 6bb25cace7da0b94ceab81b24123564c77d67c13a000403766570a90c4df8142
004AA900  55                               push   ebp
004AA901  8bec                             mov    ebp,esp
004AA903  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA906  53                               push   ebx
004AA907  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AA90D  56                               push   esi
004AA90E  8b33                             mov    esi,DWORD PTR [ebx]
004AA910  57                               push   edi
004AA911  8b38                             mov    edi,DWORD PTR [eax]
004AA913  b8eed8ffff                       mov    eax,0xffffd8ee
004AA918  c7051818fe00c0944a00             mov    DWORD PTR ds:0xfe1818,0x4a94c0
004AA922  e859ad2400                       call   0x6f5680
004AA927  8b03                             mov    eax,DWORD PTR [ebx]
004AA929  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AA92C  83e810                           sub    eax,0x10
004AA92F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AA934  7406                             je     0x4aa93c
004AA936  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AA93A  7414                             je     0x4aa950
004AA93C  57                               push   edi
004AA93D  68c426c400                       push   0xc426c4
004AA942  e876873e00                       call   0x8930bd
004AA947  8b1b                             mov    ebx,DWORD PTR [ebx]
004AA949  83c408                           add    esp,0x8
004AA94C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AA950  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AA956  8b37                             mov    esi,DWORD PTR [edi]
004AA958  68a0abd600                       push   0xd6aba0
004AA95D  e8aeab2400                       call   0x6f5510
004AA962  8b37                             mov    esi,DWORD PTR [edi]
004AA964  83c404                           add    esp,0x4
004AA967  6a00                             push   0x0
004AA969  6830c04a00                       push   0x4ac030
004AA96E  e83dac2400                       call   0x6f55b0
004AA973  8b0f                             mov    ecx,DWORD PTR [edi]
004AA975  51                               push   ecx
004AA976  b8fdffffff                       mov    eax,0xfffffffd
004AA97B  e870ae2400                       call   0x6f57f0
004AA980  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AA986  8b02                             mov    eax,DWORD PTR [edx]
004AA988  83c40c                           add    esp,0xc
004AA98B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AA98F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA992  5f                               pop    edi
004AA993  5e                               pop    esi
004AA994  5b                               pop    ebx
004AA995  5d                               pop    ebp
004AA996  c20400                           ret    0x4

; I02 SetKeymapEnabled Lua closure retrieves target and returns one stack value
; VA 0x4ac030..0x4ac08c RAW 0xab430 LEN 92 SHA256 e475bf0f31e8467774b3c5cc60b346865e0becf2098e25cb352d98a8f498994f
004AC030  55                               push   ebp
004AC031  8bec                             mov    ebp,esp
004AC033  6aff                             push   0xffffffff
004AC035  68c8839300                       push   0x9383c8
004AC03A  64a100000000                     mov    eax,fs:0x0
004AC040  50                               push   eax
004AC041  83ec0c                           sub    esp,0xc
004AC044  a1201fd600                       mov    eax,ds:0xd61f20
004AC049  33c5                             xor    eax,ebp
004AC04B  50                               push   eax
004AC04C  8d45f4                           lea    eax,[ebp-0xc]
004AC04F  64a300000000                     mov    fs:0x0,eax
004AC055  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AC058  8945e8                           mov    DWORD PTR [ebp-0x18],eax
004AC05B  33c0                             xor    eax,eax
004AC05D  8945ec                           mov    DWORD PTR [ebp-0x14],eax
004AC060  8945f0                           mov    DWORD PTR [ebp-0x10],eax
004AC063  8945fc                           mov    DWORD PTR [ebp-0x4],eax
004AC066  8b0d1818fe00                     mov    ecx,DWORD PTR ds:0xfe1818
004AC06C  51                               push   ecx
004AC06D  8d45e8                           lea    eax,[ebp-0x18]
004AC070  e8fb0a0000                       call   0x4acb70
004AC075  83c404                           add    esp,0x4
004AC078  b801000000                       mov    eax,0x1
004AC07D  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004AC080  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004AC087  59                               pop    ecx
004AC088  8be5                             mov    esp,ebp
004AC08A  5d                               pop    ebp
004AC08B  c3                               ret

; I03 SetKeymapEnabled last argument number/string conversion; others become zero
; VA 0x4acb70..0x4acbe3 RAW 0xabf70 LEN 115 SHA256 3dc7ee03ab0c5cb15c58d7bede4c152112acd04d8aae1d2b3cf95671994f55be
004ACB70  55                               push   ebp
004ACB71  8bec                             mov    ebp,esp
004ACB73  8b08                             mov    ecx,DWORD PTR [eax]
004ACB75  83ec18                           sub    esp,0x18
004ACB78  53                               push   ebx
004ACB79  8b1d0418fe00                     mov    ebx,DWORD PTR ds:0xfe1804
004ACB7F  83c8ff                           or     eax,0xffffffff
004ACB82  e869852400                       call   0x6f50f0
004ACB87  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
004ACB8A  83f903                           cmp    ecx,0x3
004ACB8D  742a                             je     0x4acbb9
004ACB8F  83f904                           cmp    ecx,0x4
004ACB92  7540                             jne    0x4acbd4
004ACB94  56                               push   esi
004ACB95  8b30                             mov    esi,DWORD PTR [eax]
004ACB97  57                               push   edi
004ACB98  83c610                           add    esi,0x10
004ACB9B  8d7df8                           lea    edi,[ebp-0x8]
004ACB9E  e8bdab2400                       call   0x6f7760
004ACBA3  5f                               pop    edi
004ACBA4  5e                               pop    esi
004ACBA5  85c0                             test   eax,eax
004ACBA7  742b                             je     0x4acbd4
004ACBA9  dd45f8                           fld    QWORD PTR [ebp-0x8]
004ACBAC  c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
004ACBB3  dd5de8                           fstp   QWORD PTR [ebp-0x18]
004ACBB6  8d45e8                           lea    eax,[ebp-0x18]
004ACBB9  dd00                             fld    QWORD PTR [eax]
004ACBBB  dd5df0                           fstp   QWORD PTR [ebp-0x10]
004ACBBE  dd45f0                           fld    QWORD PTR [ebp-0x10]
004ACBC1  db5dfc                           fistp  DWORD PTR [ebp-0x4]
004ACBC4  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
004ACBC7  50                               push   eax
004ACBC8  8bcb                             mov    ecx,ebx
004ACBCA  ff5508                           call   DWORD PTR [ebp+0x8]
004ACBCD  33c0                             xor    eax,eax
004ACBCF  5b                               pop    ebx
004ACBD0  8be5                             mov    esp,ebp
004ACBD2  5d                               pop    ebp
004ACBD3  c3                               ret
004ACBD4  33c0                             xor    eax,eax
004ACBD6  50                               push   eax
004ACBD7  8bcb                             mov    ecx,ebx
004ACBD9  ff5508                           call   DWORD PTR [ebp+0x8]
004ACBDC  33c0                             xor    eax,eax
004ACBDE  5b                               pop    ebx
004ACBDF  8be5                             mov    esp,ebp
004ACBE1  5d                               pop    ebp
004ACBE2  c3                               ret

; I04 initialized input mask bit 2 enable/disable; no Q pause or controller store
; VA 0x4a94c0..0x4a9568 RAW 0xa88c0 LEN 168 SHA256 9b3f1ac8269ccb3700fffc875c1c460c3b401d38297765b0e1d4935324c937b2
004A94C0  55                               push   ebp
004A94C1  8bec                             mov    ebp,esp
004A94C3  6aff                             push   0xffffffff
004A94C5  681c779200                       push   0x92771c
004A94CA  64a100000000                     mov    eax,fs:0x0
004A94D0  50                               push   eax
004A94D1  a1201fd600                       mov    eax,ds:0xd61f20
004A94D6  51                               push   ecx
004A94D7  33c5                             xor    eax,ebp
004A94D9  50                               push   eax
004A94DA  8d45f4                           lea    eax,[ebp-0xc]
004A94DD  64a300000000                     mov    fs:0x0,eax
004A94E3  837d0800                         cmp    DWORD PTR [ebp+0x8],0x0
004A94E7  b801000000                       mov    eax,0x1
004A94EC  743f                             je     0x4a952d
004A94EE  8405147cfb00                     test   BYTE PTR ds:0xfb7c14,al
004A94F4  751f                             jne    0x4a9515
004A94F6  0905147cfb00                     or     DWORD PTR ds:0xfb7c14,eax
004A94FC  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004A9503  e848722200                       call   0x6d0750
004A9508  6830d5bc00                       push   0xbcd530
004A950D  e8088e3e00                       call   0x89231a
004A9512  83c404                           add    esp,0x4
004A9515  83253088fb00fd                   and    DWORD PTR ds:0xfb8830,0xfffffffd
004A951C  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A951F  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A9526  59                               pop    ecx
004A9527  8be5                             mov    esp,ebp
004A9529  5d                               pop    ebp
004A952A  c20400                           ret    0x4
004A952D  8405147cfb00                     test   BYTE PTR ds:0xfb7c14,al
004A9533  751b                             jne    0x4a9550
004A9535  0905147cfb00                     or     DWORD PTR ds:0xfb7c14,eax
004A953B  8945fc                           mov    DWORD PTR [ebp-0x4],eax
004A953E  e80d722200                       call   0x6d0750
004A9543  6830d5bc00                       push   0xbcd530
004A9548  e8cd8d3e00                       call   0x89231a
004A954D  83c404                           add    esp,0x4
004A9550  830d3088fb0002                   or     DWORD PTR ds:0xfb8830,0x2
004A9557  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A955A  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A9561  59                               pop    ecx
004A9562  8be5                             mov    esp,ebp
004A9564  5d                               pop    ebp
004A9565  c20400                           ret    0x4

; I05 lb.ChangeKeymapType native target and closure registration
; VA 0x4a1dd0..0x4a1e69 RAW 0xa11d0 LEN 153 SHA256 df6ad901e5c09ec78c724574ef9d195ebdc436b3245e7006bac821b2c4107560
004A1DD0  55                               push   ebp
004A1DD1  8bec                             mov    ebp,esp
004A1DD3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004A1DD6  53                               push   ebx
004A1DD7  8b1d7417fe00                     mov    ebx,DWORD PTR ds:0xfe1774
004A1DDD  56                               push   esi
004A1DDE  8b33                             mov    esi,DWORD PTR [ebx]
004A1DE0  57                               push   edi
004A1DE1  8b38                             mov    edi,DWORD PTR [eax]
004A1DE3  b8eed8ffff                       mov    eax,0xffffd8ee
004A1DE8  c705b017fe0040144a00             mov    DWORD PTR ds:0xfe17b0,0x4a1440
004A1DF2  e889382500                       call   0x6f5680
004A1DF7  8b03                             mov    eax,DWORD PTR [ebx]
004A1DF9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004A1DFC  83e810                           sub    eax,0x10
004A1DFF  3dc8bfc000                       cmp    eax,0xc0bfc8
004A1E04  7406                             je     0x4a1e0c
004A1E06  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004A1E0A  7414                             je     0x4a1e20
004A1E0C  57                               push   edi
004A1E0D  68c426c400                       push   0xc426c4
004A1E12  e8a6123f00                       call   0x8930bd
004A1E17  8b1b                             mov    ebx,DWORD PTR [ebx]
004A1E19  83c408                           add    esp,0x8
004A1E1C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004A1E20  8b3d7417fe00                     mov    edi,DWORD PTR ds:0xfe1774
004A1E26  8b37                             mov    esi,DWORD PTR [edi]
004A1E28  6850aed600                       push   0xd6ae50
004A1E2D  e8de362500                       call   0x6f5510
004A1E32  8b37                             mov    esi,DWORD PTR [edi]
004A1E34  83c404                           add    esp,0x4
004A1E37  6a00                             push   0x0
004A1E39  6880234a00                       push   0x4a2380
004A1E3E  e86d372500                       call   0x6f55b0
004A1E43  8b0f                             mov    ecx,DWORD PTR [edi]
004A1E45  51                               push   ecx
004A1E46  b8fdffffff                       mov    eax,0xfffffffd
004A1E4B  e8a0392500                       call   0x6f57f0
004A1E50  8b157417fe00                     mov    edx,DWORD PTR ds:0xfe1774
004A1E56  8b02                             mov    eax,DWORD PTR [edx]
004A1E58  83c40c                           add    esp,0xc
004A1E5B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004A1E5F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004A1E62  5f                               pop    edi
004A1E63  5e                               pop    esi
004A1E64  5b                               pop    ebx
004A1E65  5d                               pop    ebp
004A1E66  c20400                           ret    0x4

; I06 ChangeKeymapType Lua closure retrieves target and returns one stack value
; VA 0x4a2380..0x4a23dc RAW 0xa1780 LEN 92 SHA256 afb85a766ea41f554c51843a2487308f759b5cd7eb4da511f228e4d240cac159
004A2380  55                               push   ebp
004A2381  8bec                             mov    ebp,esp
004A2383  6aff                             push   0xffffffff
004A2385  68c8839300                       push   0x9383c8
004A238A  64a100000000                     mov    eax,fs:0x0
004A2390  50                               push   eax
004A2391  83ec0c                           sub    esp,0xc
004A2394  a1201fd600                       mov    eax,ds:0xd61f20
004A2399  33c5                             xor    eax,ebp
004A239B  50                               push   eax
004A239C  8d45f4                           lea    eax,[ebp-0xc]
004A239F  64a300000000                     mov    fs:0x0,eax
004A23A5  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004A23A8  8945e8                           mov    DWORD PTR [ebp-0x18],eax
004A23AB  33c0                             xor    eax,eax
004A23AD  8945ec                           mov    DWORD PTR [ebp-0x14],eax
004A23B0  8945f0                           mov    DWORD PTR [ebp-0x10],eax
004A23B3  8945fc                           mov    DWORD PTR [ebp-0x4],eax
004A23B6  8b0db017fe00                     mov    ecx,DWORD PTR ds:0xfe17b0
004A23BC  51                               push   ecx
004A23BD  8d45e8                           lea    eax,[ebp-0x18]
004A23C0  e81b000000                       call   0x4a23e0
004A23C5  83c404                           add    esp,0x4
004A23C8  b801000000                       mov    eax,0x1
004A23CD  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A23D0  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A23D7  59                               pop    ecx
004A23D8  8be5                             mov    esp,ebp
004A23DA  5d                               pop    ebp
004A23DB  c3                               ret

; I07 ChangeKeymapType last argument number/string conversion; others become zero
; VA 0x4a23e0..0x4a2453 RAW 0xa17e0 LEN 115 SHA256 56d63b345639b84be714ef93b06bafe5bc1c0674253270f472d69fcb39036c40
004A23E0  55                               push   ebp
004A23E1  8bec                             mov    ebp,esp
004A23E3  8b08                             mov    ecx,DWORD PTR [eax]
004A23E5  83ec18                           sub    esp,0x18
004A23E8  53                               push   ebx
004A23E9  8b1d7817fe00                     mov    ebx,DWORD PTR ds:0xfe1778
004A23EF  83c8ff                           or     eax,0xffffffff
004A23F2  e8f92c2500                       call   0x6f50f0
004A23F7  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
004A23FA  83f903                           cmp    ecx,0x3
004A23FD  742a                             je     0x4a2429
004A23FF  83f904                           cmp    ecx,0x4
004A2402  7540                             jne    0x4a2444
004A2404  56                               push   esi
004A2405  8b30                             mov    esi,DWORD PTR [eax]
004A2407  57                               push   edi
004A2408  83c610                           add    esi,0x10
004A240B  8d7df8                           lea    edi,[ebp-0x8]
004A240E  e84d532500                       call   0x6f7760
004A2413  5f                               pop    edi
004A2414  5e                               pop    esi
004A2415  85c0                             test   eax,eax
004A2417  742b                             je     0x4a2444
004A2419  dd45f8                           fld    QWORD PTR [ebp-0x8]
004A241C  c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
004A2423  dd5de8                           fstp   QWORD PTR [ebp-0x18]
004A2426  8d45e8                           lea    eax,[ebp-0x18]
004A2429  dd00                             fld    QWORD PTR [eax]
004A242B  dd5df0                           fstp   QWORD PTR [ebp-0x10]
004A242E  dd45f0                           fld    QWORD PTR [ebp-0x10]
004A2431  db5dfc                           fistp  DWORD PTR [ebp-0x4]
004A2434  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
004A2437  50                               push   eax
004A2438  8bcb                             mov    ecx,ebx
004A243A  ff5508                           call   DWORD PTR [ebp+0x8]
004A243D  33c0                             xor    eax,eax
004A243F  5b                               pop    ebx
004A2440  8be5                             mov    esp,ebp
004A2442  5d                               pop    ebp
004A2443  c3                               ret
004A2444  33c0                             xor    eax,eax
004A2446  50                               push   eax
004A2447  8bcb                             mov    ecx,ebx
004A2449  ff5508                           call   DWORD PTR [ebp+0x8]
004A244C  33c0                             xor    eax,eax
004A244E  5b                               pop    ebx
004A244F  8be5                             mov    esp,ebp
004A2451  5d                               pop    ebp
004A2452  c3                               ret

; I08 keymap type accepts 0/1, selects preset, copies into current keymap
; VA 0x4a1440..0x4a14c6 RAW 0xa0840 LEN 134 SHA256 a0555b1de23d2084e614e1a2d8a822a9f17519af43f629971c2fb942f84e717e
004A1440  55                               push   ebp
004A1441  8bec                             mov    ebp,esp
004A1443  6aff                             push   0xffffffff
004A1445  680e789200                       push   0x92780e
004A144A  64a100000000                     mov    eax,fs:0x0
004A1450  50                               push   eax
004A1451  a1201fd600                       mov    eax,ds:0xd61f20
004A1456  51                               push   ecx
004A1457  33c5                             xor    eax,ebp
004A1459  50                               push   eax
004A145A  8d45f4                           lea    eax,[ebp-0xc]
004A145D  64a300000000                     mov    fs:0x0,eax
004A1463  f605147cfb0001                   test   BYTE PTR ds:0xfb7c14,0x1
004A146A  7527                             jne    0x4a1493
004A146C  830d147cfb0001                   or     DWORD PTR ds:0xfb7c14,0x1
004A1473  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004A147A  e8d1f22200                       call   0x6d0750
004A147F  6830d5bc00                       push   0xbcd530
004A1484  e8910e3f00                       call   0x89231a
004A1489  83c404                           add    esp,0x4
004A148C  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A1493  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004A1496  85c0                             test   eax,eax
004A1498  7405                             je     0x4a149f
004A149A  83f801                           cmp    eax,0x1
004A149D  7516                             jne    0x4a14b5
004A149F  8d0480                           lea    eax,[eax+eax*4]
004A14A2  c1e007                           shl    eax,0x7
004A14A5  053488fb00                       add    eax,0xfb8834
004A14AA  50                               push   eax
004A14AB  68348dfb00                       push   0xfb8d34
004A14B0  e82b072300                       call   0x6d1be0
004A14B5  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A14B8  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A14BF  59                               pop    ecx
004A14C0  8be5                             mov    esp,ebp
004A14C2  5d                               pop    ebp
004A14C3  c20400                           ret    0x4

; I09 copy of 40 keymap vectors, allocation/copy branches
; VA 0x6d1be0..0x6d1d69 RAW 0x2d0fe0 LEN 393 SHA256 720a35356a9917ebc54eae60cca376c897545665fd199b10944a2ac84161572e
006D1BE0  55                               push   ebp
006D1BE1  8bec                             mov    ebp,esp
006D1BE3  83ec0c                           sub    esp,0xc
006D1BE6  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
006D1BE9  53                               push   ebx
006D1BEA  8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
006D1BED  8bc3                             mov    eax,ebx
006D1BEF  56                               push   esi
006D1BF0  2bd9                             sub    ebx,ecx
006D1BF2  57                               push   edi
006D1BF3  c745f800000000                   mov    DWORD PTR [ebp-0x8],0x0
006D1BFA  89450c                           mov    DWORD PTR [ebp+0xc],eax
006D1BFD  8d7104                           lea    esi,[ecx+0x4]
006D1C00  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
006D1C03  8d4efc                           lea    ecx,[esi-0x4]
006D1C06  3bc8                             cmp    ecx,eax
006D1C08  0f8429010000                     je     0x6d1d37
006D1C0E  8b0c33                           mov    ecx,DWORD PTR [ebx+esi*1]
006D1C11  8b00                             mov    eax,DWORD PTR [eax]
006D1C13  8bd1                             mov    edx,ecx
006D1C15  2bd0                             sub    edx,eax
006D1C17  c1fa02                           sar    edx,0x2
006D1C1A  85d2                             test   edx,edx
006D1C1C  7532                             jne    0x6d1c50
006D1C1E  8b0e                             mov    ecx,DWORD PTR [esi]
006D1C20  8b7efc                           mov    edi,DWORD PTR [esi-0x4]
006D1C23  3bf9                             cmp    edi,ecx
006D1C25  0f840c010000                     je     0x6d1d37
006D1C2B  8bc1                             mov    eax,ecx
006D1C2D  2bc1                             sub    eax,ecx
006D1C2F  c1f802                           sar    eax,0x2
006D1C32  03c0                             add    eax,eax
006D1C34  03c0                             add    eax,eax
006D1C36  50                               push   eax
006D1C37  51                               push   ecx
006D1C38  57                               push   edi
006D1C39  8945f4                           mov    DWORD PTR [ebp-0xc],eax
006D1C3C  e8aff61b00                       call   0x8912f0
006D1C41  8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
006D1C44  83c40c                           add    esp,0xc
006D1C47  03d7                             add    edx,edi
006D1C49  8916                             mov    DWORD PTR [esi],edx
006D1C4B  e9e7000000                       jmp    0x6d1d37
006D1C50  8b5efc                           mov    ebx,DWORD PTR [esi-0x4]
006D1C53  8b3e                             mov    edi,DWORD PTR [esi]
006D1C55  2bfb                             sub    edi,ebx
006D1C57  c1ff02                           sar    edi,0x2
006D1C5A  3bd7                             cmp    edx,edi
006D1C5C  772d                             ja     0x6d1c8b
006D1C5E  2bc8                             sub    ecx,eax
006D1C60  c1f902                           sar    ecx,0x2
006D1C63  03c9                             add    ecx,ecx
006D1C65  03c9                             add    ecx,ecx
006D1C67  51                               push   ecx
006D1C68  50                               push   eax
006D1C69  53                               push   ebx
006D1C6A  e881f61b00                       call   0x8912f0
006D1C6F  8b5dfc                           mov    ebx,DWORD PTR [ebp-0x4]
006D1C72  8b0433                           mov    eax,DWORD PTR [ebx+esi*1]
006D1C75  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
006D1C78  2b01                             sub    eax,DWORD PTR [ecx]
006D1C7A  8b56fc                           mov    edx,DWORD PTR [esi-0x4]
006D1C7D  83c40c                           add    esp,0xc
006D1C80  c1f802                           sar    eax,0x2
006D1C83  8d0482                           lea    eax,[edx+eax*4]
006D1C86  e9aa000000                       jmp    0x6d1d35
006D1C8B  8b4e04                           mov    ecx,DWORD PTR [esi+0x4]
006D1C8E  2bcb                             sub    ecx,ebx
006D1C90  c1f902                           sar    ecx,0x2
006D1C93  3bd1                             cmp    edx,ecx
006D1C95  773a                             ja     0x6d1cd1
006D1C97  8d3cb8                           lea    edi,[eax+edi*4]
006D1C9A  8bd7                             mov    edx,edi
006D1C9C  2bd0                             sub    edx,eax
006D1C9E  c1fa02                           sar    edx,0x2
006D1CA1  03d2                             add    edx,edx
006D1CA3  03d2                             add    edx,edx
006D1CA5  52                               push   edx
006D1CA6  50                               push   eax
006D1CA7  53                               push   ebx
006D1CA8  e843f61b00                       call   0x8912f0
006D1CAD  8b5dfc                           mov    ebx,DWORD PTR [ebp-0x4]
006D1CB0  8b0433                           mov    eax,DWORD PTR [ebx+esi*1]
006D1CB3  8b0e                             mov    ecx,DWORD PTR [esi]
006D1CB5  2bc7                             sub    eax,edi
006D1CB7  c1f802                           sar    eax,0x2
006D1CBA  03c0                             add    eax,eax
006D1CBC  03c0                             add    eax,eax
006D1CBE  50                               push   eax
006D1CBF  57                               push   edi
006D1CC0  51                               push   ecx
006D1CC1  8945f4                           mov    DWORD PTR [ebp-0xc],eax
006D1CC4  e827f61b00                       call   0x8912f0
006D1CC9  83c418                           add    esp,0x18
006D1CCC  0345f4                           add    eax,DWORD PTR [ebp-0xc]
006D1CCF  eb64                             jmp    0x6d1d35
006D1CD1  85db                             test   ebx,ebx
006D1CD3  7409                             je     0x6d1cde
006D1CD5  53                               push   ebx
006D1CD6  e831f51b00                       call   0x89120c
006D1CDB  83c404                           add    esp,0x4
006D1CDE  8b5dfc                           mov    ebx,DWORD PTR [ebp-0x4]
006D1CE1  8b3c33                           mov    edi,DWORD PTR [ebx+esi*1]
006D1CE4  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
006D1CE7  2b38                             sub    edi,DWORD PTR [eax]
006D1CE9  33c0                             xor    eax,eax
006D1CEB  c1ff02                           sar    edi,0x2
006D1CEE  8946fc                           mov    DWORD PTR [esi-0x4],eax
006D1CF1  8906                             mov    DWORD PTR [esi],eax
006D1CF3  894604                           mov    DWORD PTR [esi+0x4],eax
006D1CF6  3bf8                             cmp    edi,eax
006D1CF8  743d                             je     0x6d1d37
006D1CFA  81ffffffff3f                     cmp    edi,0x3fffffff
006D1D00  775d                             ja     0x6d1d5f
006D1D02  8bcf                             mov    ecx,edi
006D1D04  e8d7e40f00                       call   0x7d01e0
006D1D09  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
006D1D0C  8d0cb8                           lea    ecx,[eax+edi*4]
006D1D0F  894e04                           mov    DWORD PTR [esi+0x4],ecx
006D1D12  8946fc                           mov    DWORD PTR [esi-0x4],eax
006D1D15  8906                             mov    DWORD PTR [esi],eax
006D1D17  8b12                             mov    edx,DWORD PTR [edx]
006D1D19  8b0c33                           mov    ecx,DWORD PTR [ebx+esi*1]
006D1D1C  2bca                             sub    ecx,edx
006D1D1E  c1f902                           sar    ecx,0x2
006D1D21  8d3c8d00000000                   lea    edi,[ecx*4+0x0]
006D1D28  57                               push   edi
006D1D29  52                               push   edx
006D1D2A  50                               push   eax
006D1D2B  e8c0f51b00                       call   0x8912f0
006D1D30  83c40c                           add    esp,0xc
006D1D33  03c7                             add    eax,edi
006D1D35  8906                             mov    DWORD PTR [esi],eax
006D1D37  8b4df8                           mov    ecx,DWORD PTR [ebp-0x8]
006D1D3A  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
006D1D3D  41                               inc    ecx
006D1D3E  83c010                           add    eax,0x10
006D1D41  83c610                           add    esi,0x10
006D1D44  894df8                           mov    DWORD PTR [ebp-0x8],ecx
006D1D47  89450c                           mov    DWORD PTR [ebp+0xc],eax
006D1D4A  83f928                           cmp    ecx,0x28
006D1D4D  0f82b0feffff                     jb     0x6d1c03
006D1D53  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
006D1D56  5f                               pop    edi
006D1D57  5e                               pop    esi
006D1D58  5b                               pop    ebx
006D1D59  8be5                             mov    esp,ebp
006D1D5B  5d                               pop    ebp
006D1D5C  c20800                           ret    0x8
006D1D5F  687823bf00                       push   0xbf2378
006D1D64  e8c7bd1a00                       call   0x87db30

; I10 negative ordinary Lua stack index maps top plus index times 16
; VA 0x6f50f0..0x6f5116 RAW 0x2f44f0 LEN 38 SHA256 37e4b52f657f69edcf09173443a66e5249c1dc1d371a853abba20894848c08a2
006F50F0  85c0                             test   eax,eax
006F50F2  7e14                             jle    0x6f5108
006F50F4  8b510c                           mov    edx,DWORD PTR [ecx+0xc]
006F50F7  03c0                             add    eax,eax
006F50F9  8d44c2f0                         lea    eax,[edx+eax*8-0x10]
006F50FD  3b4108                           cmp    eax,DWORD PTR [ecx+0x8]
006F5100  7269                             jb     0x6f516b
006F5102  b8c8bfc000                       mov    eax,0xc0bfc8
006F5107  c3                               ret
006F5108  3df0d8ffff                       cmp    eax,0xffffd8f0
006F510D  7e07                             jle    0x6f5116
006F510F  c1e004                           shl    eax,0x4
006F5112  034108                           add    eax,DWORD PTR [ecx+0x8]
006F5115  c3                               ret

; Q01 Q singleton constructor zeroes active and pause fields
; VA 0x560170..0x56024d RAW 0x15f570 LEN 221 SHA256 db0c3c286eba9689a1d8144b479be94cc3421747f0141f39784cadb4f8f73c50
00560170  55                               push   ebp
00560171  8bec                             mov    ebp,esp
00560173  6aff                             push   0xffffffff
00560175  68c8ad9300                       push   0x93adc8
0056017A  64a100000000                     mov    eax,fs:0x0
00560180  50                               push   eax
00560181  83ec38                           sub    esp,0x38
00560184  53                               push   ebx
00560185  56                               push   esi
00560186  a1201fd600                       mov    eax,ds:0xd61f20
0056018B  33c5                             xor    eax,ebp
0056018D  50                               push   eax
0056018E  8d45f4                           lea    eax,[ebp-0xc]
00560191  64a300000000                     mov    fs:0x0,eax
00560197  33db                             xor    ebx,ebx
00560199  6a34                             push   0x34
0056019B  c745e4c073fb00                   mov    DWORD PTR [ebp-0x1c],0xfb73c0
005601A2  891dc073fb00                     mov    DWORD PTR ds:0xfb73c0,ebx
005601A8  891dc473fb00                     mov    DWORD PTR ds:0xfb73c4,ebx
005601AE  891dd073fb00                     mov    DWORD PTR ds:0xfb73d0,ebx
005601B4  e8af103300                       call   0x891268
005601B9  83c404                           add    esp,0x4
005601BC  3bc3                             cmp    eax,ebx
005601BE  0f8432020000                     je     0x5603f6
005601C4  a3cc73fb00                       mov    ds:0xfb73cc,eax
005601C9  8900                             mov    DWORD PTR [eax],eax
005601CB  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601D0  894004                           mov    DWORD PTR [eax+0x4],eax
005601D3  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601D8  894008                           mov    DWORD PTR [eax+0x8],eax
005601DB  a1cc73fb00                       mov    eax,ds:0xfb73cc
005601E0  c6403001                         mov    BYTE PTR [eax+0x30],0x1
005601E4  8b0dcc73fb00                     mov    ecx,DWORD PTR ds:0xfb73cc
005601EA  c6413101                         mov    BYTE PTR [ecx+0x31],0x1
005601EE  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
005601F1  6a18                             push   0x18
005601F3  891de073fb00                     mov    DWORD PTR ds:0xfb73e0,ebx
005601F9  e86a103300                       call   0x891268
005601FE  83c404                           add    esp,0x4
00560201  3bc3                             cmp    eax,ebx
00560203  0f84c9010000                     je     0x5603d2
00560209  a3dc73fb00                       mov    ds:0xfb73dc,eax
0056020E  8900                             mov    DWORD PTR [eax],eax
00560210  a1dc73fb00                       mov    eax,ds:0xfb73dc
00560215  894004                           mov    DWORD PTR [eax+0x4],eax
00560218  a1dc73fb00                       mov    eax,ds:0xfb73dc
0056021D  894008                           mov    DWORD PTR [eax+0x8],eax
00560220  8b15dc73fb00                     mov    edx,DWORD PTR ds:0xfb73dc
00560226  c6421401                         mov    BYTE PTR [edx+0x14],0x1
0056022A  a1dc73fb00                       mov    eax,ds:0xfb73dc
0056022F  c6401501                         mov    BYTE PTR [eax+0x15],0x1
00560233  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
00560237  6a48                             push   0x48
00560239  891de873fb00                     mov    DWORD PTR ds:0xfb73e8,ebx
0056023F  891dec73fb00                     mov    DWORD PTR ds:0xfb73ec,ebx
00560245  e81e103300                       call   0x891268
0056024A  83c404                           add    esp,0x4

; Q02 Q active writes controller busy before checking pause and invoking f_doCoTask
; VA 0x561520..0x5615e3 RAW 0x160920 LEN 195 SHA256 f91176f982dbe86a7a8641581e5fa9cfcd9ff1501ed413b025eee2507ea8adbb
00561520  55                               push   ebp
00561521  8bec                             mov    ebp,esp
00561523  83e4f8                           and    esp,0xfffffff8
00561526  6aff                             push   0xffffffff
00561528  687cac9300                       push   0x93ac7c
0056152D  64a100000000                     mov    eax,fs:0x0
00561533  50                               push   eax
00561534  51                               push   ecx
00561535  56                               push   esi
00561536  57                               push   edi
00561537  a1201fd600                       mov    eax,ds:0xd61f20
0056153C  33c4                             xor    eax,esp
0056153E  50                               push   eax
0056153F  8d442410                         lea    eax,[esp+0x10]
00561543  64a300000000                     mov    fs:0x0,eax
00561549  8bf9                             mov    edi,ecx
0056154B  f6054027fe0001                   test   BYTE PTR ds:0xfe2740,0x1
00561552  7529                             jne    0x56157d
00561554  830d4027fe0001                   or     DWORD PTR ds:0xfe2740,0x1
0056155B  c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
00561563  e818d1ffff                       call   0x55e680
00561568  68a0f2bc00                       push   0xbcf2a0
0056156D  e8a80d3300                       call   0x89231a
00561572  83c404                           add    esp,0x4
00561575  c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0056157D  be4427fe00                       mov    esi,0xfe2744
00561582  e809d2ffff                       call   0x55e790
00561587  837f2800                         cmp    DWORD PTR [edi+0x28],0x0
0056158B  7453                             je     0x5615e0
0056158D  f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
00561594  be01000000                       mov    esi,0x1
00561599  7524                             jne    0x5615bf
0056159B  09352cb2fa00                     or     DWORD PTR ds:0xfab22c,esi
005615A1  89742418                         mov    DWORD PTR [esp+0x18],esi
005615A5  e8e6d6f7ff                       call   0x4dec90
005615AA  6830cebc00                       push   0xbcce30
005615AF  e8660d3300                       call   0x89231a
005615B4  83c404                           add    esp,0x4
005615B7  c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
005615BF  a1a4a7fb00                       mov    eax,ds:0xfba7a4
005615C4  897058                           mov    DWORD PTR [eax+0x58],esi
005615C7  837f2c00                         cmp    DWORD PTR [edi+0x2c],0x0
005615CB  7513                             jne    0x5615e0
005615CD  8b07                             mov    eax,DWORD PTR [edi]
005615CF  6a00                             push   0x0
005615D1  6a00                             push   0x0
005615D3  68a006c100                       push   0xc106a0
005615D8  e8f3371900                       call   0x6f4dd0
005615DD  83c40c                           add    esp,0xc
005615E0  8b7f1c                           mov    edi,DWORD PTR [edi+0x1c]

; Q03 Q public IsCutSceneRunning returns receiver+28; tiny body absent from bulk navigation
; VA 0x489cf0..0x489cf4 RAW 0x890f0 LEN 4 SHA256 f9ab56c764100f6de974a6afa5ca5ea00146ab6bd602328393ec5e4228c34b90
00489CF0  8b4128                           mov    eax,DWORD PTR [ecx+0x28]
00489CF3  c3                               ret

; Q04 Q public IsAllObjectsStopped traverses Q-owned object tree, tests actor word+E2 bit8000
; VA 0x564880..0x5648f6 RAW 0x163c80 LEN 118 SHA256 5744ba641f18ab34534d8712ca114bfdd44b27d46638f3230b447058bb0a6d3e
00564880  8b511c                           mov    edx,DWORD PTR [ecx+0x1c]
00564883  8b0a                             mov    ecx,DWORD PTR [edx]
00564885  56                               push   esi
00564886  3bca                             cmp    ecx,edx
00564888  7461                             je     0x5648eb
0056488A  8d9b00000000                     lea    ebx,[ebx+0x0]
00564890  8b4110                           mov    eax,DWORD PTR [ecx+0x10]
00564893  be00800000                       mov    esi,0x8000
00564898  6685b0e2000000                   test   WORD PTR [eax+0xe2],si
0056489F  7551                             jne    0x5648f2
005648A1  80791500                         cmp    BYTE PTR [ecx+0x15],0x0
005648A5  7540                             jne    0x5648e7
005648A7  8b4108                           mov    eax,DWORD PTR [ecx+0x8]
005648AA  80781500                         cmp    BYTE PTR [eax+0x15],0x0
005648AE  751c                             jne    0x5648cc
005648B0  8bc8                             mov    ecx,eax
005648B2  8b01                             mov    eax,DWORD PTR [ecx]
005648B4  80781500                         cmp    BYTE PTR [eax+0x15],0x0
005648B8  752d                             jne    0x5648e7
005648BA  8d9b00000000                     lea    ebx,[ebx+0x0]
005648C0  8bc8                             mov    ecx,eax
005648C2  8b01                             mov    eax,DWORD PTR [ecx]
005648C4  80781500                         cmp    BYTE PTR [eax+0x15],0x0
005648C8  74f6                             je     0x5648c0
005648CA  eb1b                             jmp    0x5648e7
005648CC  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
005648CF  80781500                         cmp    BYTE PTR [eax+0x15],0x0
005648D3  7510                             jne    0x5648e5
005648D5  3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
005648D8  750b                             jne    0x5648e5
005648DA  8bc8                             mov    ecx,eax
005648DC  8b4004                           mov    eax,DWORD PTR [eax+0x4]
005648DF  80781500                         cmp    BYTE PTR [eax+0x15],0x0
005648E3  74f0                             je     0x5648d5
005648E5  8bc8                             mov    ecx,eax
005648E7  3bca                             cmp    ecx,edx
005648E9  75a5                             jne    0x564890
005648EB  b801000000                       mov    eax,0x1
005648F0  5e                               pop    esi
005648F1  c3                               ret
005648F2  33c0                             xor    eax,eax
005648F4  5e                               pop    esi
005648F5  c3                               ret

; Q05 Q public ShowLetterbox writes separate FE36EC presentation flag
; VA 0x564b00..0x564b47 RAW 0x163f00 LEN 71 SHA256 6105d496bcac352bfc080f0f502f983ec54e46edaeaea4e9eb546d2445929779
00564B00  53                               push   ebx
00564B01  bb01000000                       mov    ebx,0x1
00564B06  841dcc38fe00                     test   BYTE PTR ds:0xfe38cc,bl
00564B0C  7531                             jne    0x564b3f
00564B0E  091dcc38fe00                     or     DWORD PTR ds:0xfe38cc,ebx
00564B14  68d0f2bc00                       push   0xbcf2d0
00564B19  c705e436fe0000040000             mov    DWORD PTR ds:0xfe36e4,0x400
00564B23  c705e836fe0000030000             mov    DWORD PTR ds:0xfe36e8,0x300
00564B2D  c705ec36fe0000000000             mov    DWORD PTR ds:0xfe36ec,0x0
00564B37  e8ded73200                       call   0x89231a
00564B3C  83c404                           add    esp,0x4
00564B3F  891dec36fe00                     mov    DWORD PTR ds:0xfe36ec,ebx
00564B45  5b                               pop    ebx
00564B46  c3                               ret

; Q06 Q public HideLetterbox writes separate FE36EC presentation flag
; VA 0x564b50..0x564b99 RAW 0x163f50 LEN 73 SHA256 0f368790ff5d427f4b990d09574564f85ef2cdabf4d55f364eaa68a3b2de97ad
00564B50  b801000000                       mov    eax,0x1
00564B55  c705ec36fe0000000000             mov    DWORD PTR ds:0xfe36ec,0x0
00564B5F  8405cc38fe00                     test   BYTE PTR ds:0xfe38cc,al
00564B65  7531                             jne    0x564b98
00564B67  0905cc38fe00                     or     DWORD PTR ds:0xfe38cc,eax
00564B6D  68d0f2bc00                       push   0xbcf2d0
00564B72  c705e436fe0000040000             mov    DWORD PTR ds:0xfe36e4,0x400
00564B7C  c705e836fe0000030000             mov    DWORD PTR ds:0xfe36e8,0x300
00564B86  e88fd73200                       call   0x89231a
00564B8B  83c404                           add    esp,0x4
00564B8E  c705ec36fe0000000000             mov    DWORD PTR ds:0xfe36ec,0x0
00564B98  c3                               ret

; D01 five event-name pointers in enum order
; VA 0xc0be08..0xc0be1c RAW 0x80a408 LEN 20 SHA256 1577824fd0cb5dbc801ac81a297aeb820f4b46e0849a80a4c33a03e1ec4d0d84
fc2ac4009c2cc400d82ec400d02ec400c42ec400

; D02 debug.sethook registration row
; VA 0xc0be90..0xc0be98 RAW 0x80a490 LEN 8 SHA256 c3ec36fe3d19f8e1ce92258babbad578b47295df9fe91f122a64f24b2556ed1d
682ec40010157000

; S01 call
; VA 0xc42afc..0xc42b01 RAW 0x8410fc LEN 5 SHA256 4f3e6d671263a129b6c3b1102df1f90ea32fbbb55922c76b328c48e8e8747e62
63616c6c00

; S02 return
; VA 0xc42c9c..0xc42ca3 RAW 0x84129c LEN 7 SHA256 b6d36f1f2ca3ef0856b0b3ab3994aa5f125539218e496ceaf1867ac8a14f1953
72657475726e00

; S03 line
; VA 0xc42ed8..0xc42edd RAW 0x8414d8 LEN 5 SHA256 466efde892b0fec32c740678f88f490cfc11f511763db0b4a85341e87f1e065b
6c696e6500

; S04 count
; VA 0xc42ed0..0xc42ed6 RAW 0x8414d0 LEN 6 SHA256 37f058c4e1c3a7c4f556f8b7fb59738c3970882a379e16dc1dee1924ac3b67e9
636f756e7400

; S05 tail return
; VA 0xc42ec4..0xc42ed0 RAW 0x8414c4 LEN 12 SHA256 b779b46ae8d6411d80327b85e495d85ed730409ee6390c3be16e18d60904985d
7461696c2072657475726e00

; S06 sethook
; VA 0xc42e68..0xc42e70 RAW 0x841468 LEN 8 SHA256 2c400f22a35ec04ac1aa0c0893c1d12522b55738436999be0dc1de35d98d64af
736574686f6f6b00

; S07 SetKeymapEnabled
; VA 0xd6aba0..0xd6abb1 RAW 0x9683a0 LEN 17 SHA256 9d3a61ebbcacc9878165ae83e1abead0ca8043943b59775c6d0dc178340b55b9
5365744b65796d6170456e61626c656400

; S08 ChangeKeymapType
; VA 0xd6ae50..0xd6ae61 RAW 0x968650 LEN 17 SHA256 a0d24614565cb8c3b63d558b8ea0691cd1c756cf4852be1428ca8162fdcc52c8
4368616e67654b65796d61705479706500

; S09 f_doCoTask
; VA 0xc106a0..0xc106ab RAW 0x80eca0 LEN 11 SHA256 3082ca9ee59bfa364239096dbe921a293e83119b7768d100696c479651ff6346
665f646f436f5461736b00

; S10 debug
; VA 0xc42864..0xc4286a RAW 0x840e64 LEN 6 SHA256 177a1b555afd40494e5cd58db6c3967b46042c609063351be9644922d3081960
646562756700
