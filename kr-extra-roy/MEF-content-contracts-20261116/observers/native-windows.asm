; q_all_stopped_native 0x564880..0x5648f6 raw 0x163c80
; Complete getter: Q owner+18 tree, actor+E2 bit8000; empty tree returns1.
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

; q_all_stopped_lua 0x5698e0..0x56994e raw 0x168ce0
; FE2778 receiver / FE2818 target; EAX integer becomes Lua tag3 number.
005698E0  55                               push   ebp
005698E1  8bec                             mov    ebp,esp
005698E3  6aff                             push   0xffffffff
005698E5  68d8879300                       push   0x9387d8
005698EA  64a100000000                     mov    eax,fs:0x0
005698F0  50                               push   eax
005698F1  83ec0c                           sub    esp,0xc
005698F4  56                               push   esi
005698F5  a1201fd600                       mov    eax,ds:0xd61f20
005698FA  33c5                             xor    eax,ebp
005698FC  50                               push   eax
005698FD  8d45f4                           lea    eax,[ebp-0xc]
00569900  64a300000000                     mov    fs:0x0,eax
00569906  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
00569909  33c0                             xor    eax,eax
0056990B  8975e8                           mov    DWORD PTR [ebp-0x18],esi
0056990E  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00569911  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00569914  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00569917  8b0d7827fe00                     mov    ecx,DWORD PTR ds:0xfe2778
0056991D  ff151828fe00                     call   DWORD PTR ds:0xfe2818
00569923  894508                           mov    DWORD PTR [ebp+0x8],eax
00569926  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00569929  db4508                           fild   DWORD PTR [ebp+0x8]
0056992C  c7400803000000                   mov    DWORD PTR [eax+0x8],0x3
00569933  dd18                             fstp   QWORD PTR [eax]
00569935  83460810                         add    DWORD PTR [esi+0x8],0x10
00569939  b801000000                       mov    eax,0x1
0056993E  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00569941  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00569948  59                               pop    ecx
00569949  5e                               pop    esi
0056994A  8be5                             mov    esp,ebp
0056994C  5d                               pop    ebp
0056994D  c3                               ret

; q_walk_lua 0x569340..0x569396 raw 0x168740
; WalkObject C closure calls six-argument marshaller.
00569340  55                               push   ebp
00569341  8bec                             mov    ebp,esp
00569343  6aff                             push   0xffffffff
00569345  68c8839300                       push   0x9383c8
0056934A  64a100000000                     mov    eax,fs:0x0
00569350  50                               push   eax
00569351  83ec0c                           sub    esp,0xc
00569354  a1201fd600                       mov    eax,ds:0xd61f20
00569359  33c5                             xor    eax,ebp
0056935B  50                               push   eax
0056935C  8d45f4                           lea    eax,[ebp-0xc]
0056935F  64a300000000                     mov    fs:0x0,eax
00569365  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00569368  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0056936B  33c0                             xor    eax,eax
0056936D  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00569370  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00569373  8d4de8                           lea    ecx,[ebp-0x18]
00569376  51                               push   ecx
00569377  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0056937A  e8b1180000                       call   0x56ac30
0056937F  83c404                           add    esp,0x4
00569382  b801000000                       mov    eax,0x1
00569387  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0056938A  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00569391  59                               pop    ecx
00569392  8be5                             mov    esp,ebp
00569394  5d                               pop    ebp
00569395  c3                               ret

; q_walk_marshaller 0x56ac30..0x56ae7e raw 0x16a030
; Complete six trailing Lua-stack value conversions, defaults, and call.
0056AC30  55                               push   ebp
0056AC31  8bec                             mov    ebp,esp
0056AC33  83ec44                           sub    esp,0x44
0056AC36  a1dc27fe00                       mov    eax,ds:0xfe27dc
0056AC3B  8b0d7827fe00                     mov    ecx,DWORD PTR ds:0xfe2778
0056AC41  53                               push   ebx
0056AC42  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0056AC45  8945dc                           mov    DWORD PTR [ebp-0x24],eax
0056AC48  8b03                             mov    eax,DWORD PTR [ebx]
0056AC4A  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056AC4D  83e810                           sub    eax,0x10
0056AC50  894de0                           mov    DWORD PTR [ebp-0x20],ecx
0056AC53  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056AC56  56                               push   esi
0056AC57  57                               push   edi
0056AC58  83f903                           cmp    ecx,0x3
0056AC5B  742e                             je     0x56ac8b
0056AC5D  83f904                           cmp    ecx,0x4
0056AC60  0f85e7010000                     jne    0x56ae4d
0056AC66  8b30                             mov    esi,DWORD PTR [eax]
0056AC68  83c610                           add    esi,0x10
0056AC6B  8d7dcc                           lea    edi,[ebp-0x34]
0056AC6E  e8edca1800                       call   0x6f7760
0056AC73  85c0                             test   eax,eax
0056AC75  0f84d2010000                     je     0x56ae4d
0056AC7B  dd45cc                           fld    QWORD PTR [ebp-0x34]
0056AC7E  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0056AC85  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0056AC88  8d45bc                           lea    eax,[ebp-0x44]
0056AC8B  dd00                             fld    QWORD PTR [eax]
0056AC8D  8b0b                             mov    ecx,DWORD PTR [ebx]
0056AC8F  dd5de4                           fstp   QWORD PTR [ebp-0x1c]
0056AC92  b8feffffff                       mov    eax,0xfffffffe
0056AC97  e854a41800                       call   0x6f50f0
0056AC9C  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056AC9F  83f903                           cmp    ecx,0x3
0056ACA2  742e                             je     0x56acd2
0056ACA4  83f904                           cmp    ecx,0x4
0056ACA7  0f85a7010000                     jne    0x56ae54
0056ACAD  8b30                             mov    esi,DWORD PTR [eax]
0056ACAF  83c610                           add    esi,0x10
0056ACB2  8d7dcc                           lea    edi,[ebp-0x34]
0056ACB5  e8a6ca1800                       call   0x6f7760
0056ACBA  85c0                             test   eax,eax
0056ACBC  0f8492010000                     je     0x56ae54
0056ACC2  dd45cc                           fld    QWORD PTR [ebp-0x34]
0056ACC5  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0056ACCC  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0056ACCF  8d45bc                           lea    eax,[ebp-0x44]
0056ACD2  dd00                             fld    QWORD PTR [eax]
0056ACD4  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0056ACD7  dd45cc                           fld    QWORD PTR [ebp-0x34]
0056ACDA  db5d08                           fistp  DWORD PTR [ebp+0x8]
0056ACDD  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0056ACE0  8955f0                           mov    DWORD PTR [ebp-0x10],edx
0056ACE3  8b0b                             mov    ecx,DWORD PTR [ebx]
0056ACE5  b8fdffffff                       mov    eax,0xfffffffd
0056ACEA  e801a41800                       call   0x6f50f0
0056ACEF  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056ACF2  83f903                           cmp    ecx,0x3
0056ACF5  742e                             je     0x56ad25
0056ACF7  83f904                           cmp    ecx,0x4
0056ACFA  0f8560010000                     jne    0x56ae60
0056AD00  8b30                             mov    esi,DWORD PTR [eax]
0056AD02  83c610                           add    esi,0x10
0056AD05  8d7dcc                           lea    edi,[ebp-0x34]
0056AD08  e853ca1800                       call   0x6f7760
0056AD0D  85c0                             test   eax,eax
0056AD0F  0f844b010000                     je     0x56ae60
0056AD15  dd45cc                           fld    QWORD PTR [ebp-0x34]
0056AD18  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0056AD1F  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0056AD22  8d45bc                           lea    eax,[ebp-0x44]
0056AD25  dd00                             fld    QWORD PTR [eax]
0056AD27  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0056AD2A  dd45cc                           fld    QWORD PTR [ebp-0x34]
0056AD2D  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0056AD30  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0056AD33  8945ec                           mov    DWORD PTR [ebp-0x14],eax
0056AD36  8b03                             mov    eax,DWORD PTR [ebx]
0056AD38  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056AD3B  8b48c8                           mov    ecx,DWORD PTR [eax-0x38]
0056AD3E  83e840                           sub    eax,0x40
0056AD41  83f903                           cmp    ecx,0x3
0056AD44  742e                             je     0x56ad74
0056AD46  83f904                           cmp    ecx,0x4
0056AD49  0f851d010000                     jne    0x56ae6c
0056AD4F  8b30                             mov    esi,DWORD PTR [eax]
0056AD51  83c610                           add    esi,0x10
0056AD54  8d7dcc                           lea    edi,[ebp-0x34]
0056AD57  e804ca1800                       call   0x6f7760
0056AD5C  85c0                             test   eax,eax
0056AD5E  0f8408010000                     je     0x56ae6c
0056AD64  dd45cc                           fld    QWORD PTR [ebp-0x34]
0056AD67  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0056AD6E  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0056AD71  8d45bc                           lea    eax,[ebp-0x44]
0056AD74  dd00                             fld    QWORD PTR [eax]
0056AD76  8b03                             mov    eax,DWORD PTR [ebx]
0056AD78  dd5dd4                           fstp   QWORD PTR [ebp-0x2c]
0056AD7B  8b4008                           mov    eax,DWORD PTR [eax+0x8]
0056AD7E  8b48b8                           mov    ecx,DWORD PTR [eax-0x48]
0056AD81  83e850                           sub    eax,0x50
0056AD84  83f903                           cmp    ecx,0x3
0056AD87  742e                             je     0x56adb7
0056AD89  83f904                           cmp    ecx,0x4
0056AD8C  0f85e1000000                     jne    0x56ae73
0056AD92  8b30                             mov    esi,DWORD PTR [eax]
0056AD94  83c610                           add    esi,0x10
0056AD97  8d7dcc                           lea    edi,[ebp-0x34]
0056AD9A  e8c1c91800                       call   0x6f7760
0056AD9F  85c0                             test   eax,eax
0056ADA1  0f84cc000000                     je     0x56ae73
0056ADA7  dd45cc                           fld    QWORD PTR [ebp-0x34]
0056ADAA  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0056ADB1  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0056ADB4  8d45bc                           lea    eax,[ebp-0x44]
0056ADB7  dd00                             fld    QWORD PTR [eax]
0056ADB9  8b0b                             mov    ecx,DWORD PTR [ebx]
0056ADBB  dd5dcc                           fstp   QWORD PTR [ebp-0x34]
0056ADBE  b8faffffff                       mov    eax,0xfffffffa
0056ADC3  e828a31800                       call   0x6f50f0
0056ADC8  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056ADCB  83f903                           cmp    ecx,0x3
0056ADCE  742e                             je     0x56adfe
0056ADD0  83f904                           cmp    ecx,0x4
0056ADD3  0f85a1000000                     jne    0x56ae7a
0056ADD9  8b30                             mov    esi,DWORD PTR [eax]
0056ADDB  83c610                           add    esi,0x10
0056ADDE  8d7df4                           lea    edi,[ebp-0xc]
0056ADE1  e87ac91800                       call   0x6f7760
0056ADE6  85c0                             test   eax,eax
0056ADE8  0f848c000000                     je     0x56ae7a
0056ADEE  dd45f4                           fld    QWORD PTR [ebp-0xc]
0056ADF1  c745c403000000                   mov    DWORD PTR [ebp-0x3c],0x3
0056ADF8  dd5dbc                           fstp   QWORD PTR [ebp-0x44]
0056ADFB  8d45bc                           lea    eax,[ebp-0x44]
0056ADFE  dd00                             fld    QWORD PTR [eax]
0056AE00  dd5dc4                           fstp   QWORD PTR [ebp-0x3c]
0056AE03  dd45c4                           fld    QWORD PTR [ebp-0x3c]
0056AE06  db5df8                           fistp  DWORD PTR [ebp-0x8]
0056AE09  8b45f8                           mov    eax,DWORD PTR [ebp-0x8]
0056AE0C  dd45e4                           fld    QWORD PTR [ebp-0x1c]
0056AE0F  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
0056AE12  d95de8                           fstp   DWORD PTR [ebp-0x18]
0056AE15  51                               push   ecx
0056AE16  d945e8                           fld    DWORD PTR [ebp-0x18]
0056AE19  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0056AE1C  d91c24                           fstp   DWORD PTR [esp]
0056AE1F  51                               push   ecx
0056AE20  dd45d4                           fld    QWORD PTR [ebp-0x2c]
0056AE23  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
0056AE26  d95de8                           fstp   DWORD PTR [ebp-0x18]
0056AE29  52                               push   edx
0056AE2A  d945e8                           fld    DWORD PTR [ebp-0x18]
0056AE2D  83ec08                           sub    esp,0x8
0056AE30  d95c2404                         fstp   DWORD PTR [esp+0x4]
0056AE34  dd45cc                           fld    QWORD PTR [ebp-0x34]
0056AE37  d95de8                           fstp   DWORD PTR [ebp-0x18]
0056AE3A  d945e8                           fld    DWORD PTR [ebp-0x18]
0056AE3D  d91c24                           fstp   DWORD PTR [esp]
0056AE40  50                               push   eax
0056AE41  ff55dc                           call   DWORD PTR [ebp-0x24]
0056AE44  5f                               pop    edi
0056AE45  5e                               pop    esi
0056AE46  33c0                             xor    eax,eax
0056AE48  5b                               pop    ebx
0056AE49  8be5                             mov    esp,ebp
0056AE4B  5d                               pop    ebp
0056AE4C  c3                               ret
0056AE4D  d9ee                             fldz
0056AE4F  e939feffff                       jmp    0x56ac8d
0056AE54  c745f000000000                   mov    DWORD PTR [ebp-0x10],0x0
0056AE5B  e983feffff                       jmp    0x56ace3
0056AE60  c745ec00000000                   mov    DWORD PTR [ebp-0x14],0x0
0056AE67  e9cafeffff                       jmp    0x56ad36
0056AE6C  d9ee                             fldz
0056AE6E  e903ffffff                       jmp    0x56ad76
0056AE73  d9ee                             fldz
0056AE75  e93fffffff                       jmp    0x56adb9
0056AE7A  33c0                             xor    eax,eax
0056AE7C  eb8e                             jmp    0x56ae0c

; q_walk_native 0x563330..0x5633b0 raw 0x162730
; Q slot lookup, target write, animation gate and speed multiplier.
00563330  55                               push   ebp
00563331  8bec                             mov    ebp,esp
00563333  83e4f8                           and    esp,0xfffffff8
00563336  83ec0c                           sub    esp,0xc
00563339  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0056333C  56                               push   esi
0056333D  8bf1                             mov    esi,ecx
0056333F  8d4c2404                         lea    ecx,[esp+0x4]
00563343  89442404                         mov    DWORD PTR [esp+0x4],eax
00563347  51                               push   ecx
00563348  8d4e18                           lea    ecx,[esi+0x18]
0056334B  8d44240c                         lea    eax,[esp+0xc]
0056334F  e8acbb2c00                       call   0x82ef00
00563354  8b442408                         mov    eax,DWORD PTR [esp+0x8]
00563358  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
0056335B  744c                             je     0x5633a9
0056335D  8b7010                           mov    esi,DWORD PTR [eax+0x10]
00563360  85f6                             test   esi,esi
00563362  7445                             je     0x5633a9
00563364  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
00563369  f30f11442408                     movss  DWORD PTR [esp+0x8],xmm0
0056336F  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
00563374  8d442408                         lea    eax,[esp+0x8]
00563378  f30f1144240c                     movss  DWORD PTR [esp+0xc],xmm0
0056337E  e85dd9f6ff                       call   0x4d0ce0
00563383  837d1400                         cmp    DWORD PTR [ebp+0x14],0x0
00563387  7420                             je     0x5633a9
00563389  d9e8                             fld1
0056338B  8b16                             mov    edx,DWORD PTR [esi]
0056338D  8b4518                           mov    eax,DWORD PTR [ebp+0x18]
00563390  8b5268                           mov    edx,DWORD PTR [edx+0x68]
00563393  51                               push   ecx
00563394  d91c24                           fstp   DWORD PTR [esp]
00563397  50                               push   eax
00563398  8bce                             mov    ecx,esi
0056339A  ffd2                             call   edx
0056339C  f30f10451c                       movss  xmm0,DWORD PTR [ebp+0x1c]
005633A1  f30f118634040000                 movss  DWORD PTR [esi+0x434],xmm0
005633A9  5e                               pop    esi
005633AA  8be5                             mov    esp,ebp
005633AC  5d                               pop    ebp
005633AD  c21800                           ret    0x18

; event_actor_walk_request 0x4d0ce0..0x4d0dcc raw 0xd00e0
; Target/direction writes and request pending bit set; upper-word other bits unspecified by this body.
004D0CE0  55                               push   ebp
004D0CE1  8bec                             mov    ebp,esp
004D0CE3  83e4f8                           and    esp,0xfffffff8
004D0CE6  83ec14                           sub    esp,0x14
004D0CE9  8b08                             mov    ecx,DWORD PTR [eax]
004D0CEB  898e24040000                     mov    DWORD PTR [esi+0x424],ecx
004D0CF1  8b5004                           mov    edx,DWORD PTR [eax+0x4]
004D0CF4  899628040000                     mov    DWORD PTR [esi+0x428],edx
004D0CFA  d94004                           fld    DWORD PTR [eax+0x4]
004D0CFD  d8a6a4000000                     fsub   DWORD PTR [esi+0xa4]
004D0D03  53                               push   ebx
004D0D04  d95c2408                         fstp   DWORD PTR [esp+0x8]
004D0D08  d9442408                         fld    DWORD PTR [esp+0x8]
004D0D0C  d900                             fld    DWORD PTR [eax]
004D0D0E  d8a6a0000000                     fsub   DWORD PTR [esi+0xa0]
004D0D14  d95c2408                         fstp   DWORD PTR [esp+0x8]
004D0D18  d9442408                         fld    DWORD PTR [esp+0x8]
004D0D1C  e8a9e04200                       call   0x8fedca
004D0D21  d95c2408                         fstp   DWORD PTR [esp+0x8]
004D0D25  d9442408                         fld    DWORD PTR [esp+0x8]
004D0D29  b801000000                       mov    eax,0x1
004D0D2E  dc052858c500                     fadd   QWORD PTR ds:0xc55828
004D0D34  d95c2408                         fstp   DWORD PTR [esp+0x8]
004D0D38  8405187cfb00                     test   BYTE PTR ds:0xfb7c18,al
004D0D3E  750b                             jne    0x4d0d4b
004D0D40  0905187cfb00                     or     DWORD PTR ds:0xfb7c18,eax
004D0D46  e8853cf7ff                       call   0x4449d0
004D0D4B  d9052488fb00                     fld    DWORD PTR ds:0xfb8824
004D0D51  f30f1005385bc500                 movss  xmm0,DWORD PTR ds:0xc55b38
004D0D59  d84c2408                         fmul   DWORD PTR [esp+0x8]
004D0D5D  33c0                             xor    eax,eax
004D0D5F  6689442410                       mov    WORD PTR [esp+0x10],ax
004D0D64  d97c2408                         fnstcw WORD PTR [esp+0x8]
004D0D68  0fb7442408                       movzx  eax,WORD PTR [esp+0x8]
004D0D6D  0d000c0000                       or     eax,0xc00
004D0D72  8944240c                         mov    DWORD PTR [esp+0xc],eax
004D0D76  b900800000                       mov    ecx,0x8000
004D0D7B  66094c2412                       or     WORD PTR [esp+0x12],cx
004D0D80  d96c240c                         fldcw  WORD PTR [esp+0xc]
004D0D84  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
004D0D8A  f30f118630040000                 movss  DWORD PTR [esi+0x430],xmm0
004D0D92  8b11                             mov    edx,DWORD PTR [ecx]
004D0D94  8b4220                           mov    eax,DWORD PTR [edx+0x20]
004D0D97  db5c240c                         fistp  DWORD PTR [esp+0xc]
004D0D9B  8a5c240c                         mov    bl,BYTE PTR [esp+0xc]
004D0D9F  885c2414                         mov    BYTE PTR [esp+0x14],bl
004D0DA3  d96c2408                         fldcw  WORD PTR [esp+0x8]
004D0DA7  ffd0                             call   eax
004D0DA9  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
004D0DAD  8b16                             mov    edx,DWORD PTR [esi]
004D0DAF  8b442414                         mov    eax,DWORD PTR [esp+0x14]
004D0DB3  8b5258                           mov    edx,DWORD PTR [edx+0x58]
004D0DB6  898ee0000000                     mov    DWORD PTR [esi+0xe0],ecx
004D0DBC  50                               push   eax
004D0DBD  8bce                             mov    ecx,esi
004D0DBF  889ee4000000                     mov    BYTE PTR [esi+0xe4],bl
004D0DC5  ffd2                             call   edx
004D0DC7  5b                               pop    ebx
004D0DC8  8be5                             mov    esp,ebp
004D0DCA  5d                               pop    ebp
004D0DCB  c3                               ret

; event_actor_walk_tick 0x4d0dd0..0x4d0f05 raw 0xd01d0
; D4 / E2 gate, position update or snap, and request clear.
004D0DD0  55                               push   ebp
004D0DD1  8bec                             mov    ebp,esp
004D0DD3  83e4f8                           and    esp,0xfffffff8
004D0DD6  83ec14                           sub    esp,0x14
004D0DD9  83bed400000000                   cmp    DWORD PTR [esi+0xd4],0x0
004D0DE0  53                               push   ebx
004D0DE1  0f8519010000                     jne    0x4d0f00
004D0DE7  b800800000                       mov    eax,0x8000
004D0DEC  668586e2000000                   test   WORD PTR [esi+0xe2],ax
004D0DF3  0f8407010000                     je     0x4d0f00
004D0DF9  8b16                             mov    edx,DWORD PTR [esi]
004D0DFB  8b4260                           mov    eax,DWORD PTR [edx+0x60]
004D0DFE  8bce                             mov    ecx,esi
004D0E00  ffd0                             call   eax
004D0E02  dc0d305bc500                     fmul   QWORD PTR ds:0xc55b30
004D0E08  f605187cfb0001                   test   BYTE PTR ds:0xfb7c18,0x1
004D0E0F  8a9ee4000000                     mov    bl,BYTE PTR [esi+0xe4]
004D0E15  d95c2404                         fstp   DWORD PTR [esp+0x4]
004D0E19  750c                             jne    0x4d0e27
004D0E1B  830d187cfb0001                   or     DWORD PTR ds:0xfb7c18,0x1
004D0E22  e8a93bf7ff                       call   0x4449d0
004D0E27  0fb6c3                           movzx  eax,bl
004D0E2A  d904c52080fb00                   fld    DWORD PTR [eax*8+0xfb8020]
004D0E31  8d04c52080fb00                   lea    eax,[eax*8+0xfb8020]
004D0E38  d9442404                         fld    DWORD PTR [esp+0x4]
004D0E3C  8d8e24040000                     lea    ecx,[esi+0x424]
004D0E42  d9c0                             fld    st(0)
004D0E44  deca                             fmulp  st(2),st
004D0E46  d9c9                             fxch   st(1)
004D0E48  d95c2410                         fstp   DWORD PTR [esp+0x10]
004D0E4C  d84804                           fmul   DWORD PTR [eax+0x4]
004D0E4F  d95c2414                         fstp   DWORD PTR [esp+0x14]
004D0E53  d901                             fld    DWORD PTR [ecx]
004D0E55  d8a6a0000000                     fsub   DWORD PTR [esi+0xa0]
004D0E5B  d95c2408                         fstp   DWORD PTR [esp+0x8]
004D0E5F  d94104                           fld    DWORD PTR [ecx+0x4]
004D0E62  d8a6a4000000                     fsub   DWORD PTR [esi+0xa4]
004D0E68  d95c240c                         fstp   DWORD PTR [esp+0xc]
004D0E6C  d9442408                         fld    DWORD PTR [esp+0x8]
004D0E70  d944240c                         fld    DWORD PTR [esp+0xc]
004D0E74  dcc8                             fmul   st(0),st
004D0E76  d9c1                             fld    st(1)
004D0E78  deca                             fmulp  st(2),st
004D0E7A  dec1                             faddp  st(1),st
004D0E7C  d95c2404                         fstp   DWORD PTR [esp+0x4]
004D0E80  d98630040000                     fld    DWORD PTR [esi+0x430]
004D0E86  d9442404                         fld    DWORD PTR [esp+0x4]
004D0E8A  dbf1                             fcomi  st,st(1)
004D0E8C  ddd9                             fstp   st(1)
004D0E8E  7745                             ja     0x4d0ed5
004D0E90  d9442410                         fld    DWORD PTR [esp+0x10]
004D0E94  d9442414                         fld    DWORD PTR [esp+0x14]
004D0E98  dcc8                             fmul   st(0),st
004D0E9A  d9c1                             fld    st(1)
004D0E9C  deca                             fmulp  st(2),st
004D0E9E  dec1                             faddp  st(1),st
004D0EA0  d95c2408                         fstp   DWORD PTR [esp+0x8]
004D0EA4  d9442408                         fld    DWORD PTR [esp+0x8]
004D0EA8  dc0df856c500                     fmul   QWORD PTR ds:0xc556f8
004D0EAE  dff1                             fcomip st,st(1)
004D0EB0  ddd8                             fstp   st(0)
004D0EB2  7723                             ja     0x4d0ed7
004D0EB4  8b16                             mov    edx,DWORD PTR [esi]
004D0EB6  f30f10442404                     movss  xmm0,DWORD PTR [esp+0x4]
004D0EBC  8b5254                           mov    edx,DWORD PTR [edx+0x54]
004D0EBF  8d442410                         lea    eax,[esp+0x10]
004D0EC3  50                               push   eax
004D0EC4  8bce                             mov    ecx,esi
004D0EC6  f30f118630040000                 movss  DWORD PTR [esi+0x430],xmm0
004D0ECE  ffd2                             call   edx
004D0ED0  5b                               pop    ebx
004D0ED1  8be5                             mov    esp,ebp
004D0ED3  5d                               pop    ebp
004D0ED4  c3                               ret
004D0ED5  ddd8                             fstp   st(0)
004D0ED7  8b06                             mov    eax,DWORD PTR [esi]
004D0ED9  8b5044                           mov    edx,DWORD PTR [eax+0x44]
004D0EDC  6a01                             push   0x1
004D0EDE  51                               push   ecx
004D0EDF  8bce                             mov    ecx,esi
004D0EE1  ffd2                             call   edx
004D0EE3  d9e8                             fld1
004D0EE5  8b06                             mov    eax,DWORD PTR [esi]
004D0EE7  8b5068                           mov    edx,DWORD PTR [eax+0x68]
004D0EEA  51                               push   ecx
004D0EEB  d91c24                           fstp   DWORD PTR [esp]
004D0EEE  6a01                             push   0x1
004D0EF0  8bce                             mov    ecx,esi
004D0EF2  ffd2                             call   edx
004D0EF4  b8ff7f0000                       mov    eax,0x7fff
004D0EF9  662186e2000000                   and    WORD PTR [esi+0xe2],ax
004D0F00  5b                               pop    ebx
004D0F01  8be5                             mov    esp,ebp
004D0F03  5d                               pop    ebp
004D0F04  c3                               ret

; event_actor_tick 0x4d0f80..0x4d0f95 raw 0xd0380
; CEventActor v+20 invokes common update then movement tick.
004D0F80  56                               push   esi
004D0F81  57                               push   edi
004D0F82  8bf1                             mov    esi,ecx
004D0F84  e8f775ffff                       call   0x4c8580
004D0F89  8bf8                             mov    edi,eax
004D0F8B  e840feffff                       call   0x4d0dd0
004D0F90  8bc7                             mov    eax,edi
004D0F92  5f                               pop    edi
004D0F93  5e                               pop    esi
004D0F94  c3                               ret

; event_actor_step 0x4d0f10..0x4d0f43 raw 0xd0310
; CEventActor v+54 adds 2D step then invokes v+44.
004D0F10  55                               push   ebp
004D0F11  8bec                             mov    ebp,esp
004D0F13  83ec08                           sub    esp,0x8
004D0F16  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004D0F19  d981a0000000                     fld    DWORD PTR [ecx+0xa0]
004D0F1F  d800                             fadd   DWORD PTR [eax]
004D0F21  6a01                             push   0x1
004D0F23  8d55f8                           lea    edx,[ebp-0x8]
004D0F26  52                               push   edx
004D0F27  d95df8                           fstp   DWORD PTR [ebp-0x8]
004D0F2A  d981a4000000                     fld    DWORD PTR [ecx+0xa4]
004D0F30  d84004                           fadd   DWORD PTR [eax+0x4]
004D0F33  8b01                             mov    eax,DWORD PTR [ecx]
004D0F35  8b4044                           mov    eax,DWORD PTR [eax+0x44]
004D0F38  d95dfc                           fstp   DWORD PTR [ebp-0x4]
004D0F3B  ffd0                             call   eax
004D0F3D  8be5                             mov    esp,ebp
004D0F3F  5d                               pop    ebp
004D0F40  c20400                           ret    0x4

; event_actor_speed 0x4d0f50..0x4d0f7c raw 0xd0350
; CEventActor v+60 computes D0 * .01 * CC *434.
004D0F50  55                               push   ebp
004D0F51  8bec                             mov    ebp,esp
004D0F53  51                               push   ecx
004D0F54  db81d0000000                     fild   DWORD PTR [ecx+0xd0]
004D0F5A  dc0df857c500                     fmul   QWORD PTR ds:0xc557f8
004D0F60  d889cc000000                     fmul   DWORD PTR [ecx+0xcc]
004D0F66  d95dfc                           fstp   DWORD PTR [ebp-0x4]
004D0F69  d945fc                           fld    DWORD PTR [ebp-0x4]
004D0F6C  d88934040000                     fmul   DWORD PTR [ecx+0x434]
004D0F72  d95dfc                           fstp   DWORD PTR [ebp-0x4]
004D0F75  d945fc                           fld    DWORD PTR [ebp-0x4]
004D0F78  8be5                             mov    esp,ebp
004D0F7A  5d                               pop    ebp
004D0F7B  c3                               ret

; actor_set_position 0x4c8b90..0x4c8bd7 raw 0xc7f90
; v+44 calls native position-field writer then selected model update.
004C8B90  55                               push   ebp
004C8B91  8bec                             mov    ebp,esp
004C8B93  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
004C8B96  56                               push   esi
004C8B97  8bf1                             mov    esi,ecx
004C8B99  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
004C8B9C  50                               push   eax
004C8B9D  51                               push   ecx
004C8B9E  8bce                             mov    ecx,esi
004C8BA0  e8db1f0000                       call   0x4cab80
004C8BA5  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
004C8BAC  7424                             je     0x4c8bd2
004C8BAE  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
004C8BB4  85c0                             test   eax,eax
004C8BB6  741a                             je     0x4c8bd2
004C8BB8  8b16                             mov    edx,DWORD PTR [esi]
004C8BBA  53                               push   ebx
004C8BBB  8d5804                           lea    ebx,[eax+0x4]
004C8BBE  8b424c                           mov    eax,DWORD PTR [edx+0x4c]
004C8BC1  57                               push   edi
004C8BC2  8b3b                             mov    edi,DWORD PTR [ebx]
004C8BC4  8bce                             mov    ecx,esi
004C8BC6  ffd0                             call   eax
004C8BC8  8b5704                           mov    edx,DWORD PTR [edi+0x4]
004C8BCB  50                               push   eax
004C8BCC  8bcb                             mov    ecx,ebx
004C8BCE  ffd2                             call   edx
004C8BD0  5f                               pop    edi
004C8BD1  5b                               pop    ebx
004C8BD2  5e                               pop    esi
004C8BD3  5d                               pop    ebp
004C8BD4  c20800                           ret    0x8

; actor_position_fields 0x4cab80..0x4cabd7 raw 0xc9f80
; Writes A0/A4 when changed and invokes v+38 if requested.
004CAB80  55                               push   ebp
004CAB81  8bec                             mov    ebp,esp
004CAB83  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
004CAB86  d981a0000000                     fld    DWORD PTR [ecx+0xa0]
004CAB8C  d902                             fld    DWORD PTR [edx]
004CAB8E  dfe9                             fucomip st,st(1)
004CAB90  ddd8                             fstp   st(0)
004CAB92  9f                               lahf
004CAB93  f6c444                           test   ah,0x44
004CAB96  7a13                             jp     0x4cabab
004CAB98  d981a4000000                     fld    DWORD PTR [ecx+0xa4]
004CAB9E  d94204                           fld    DWORD PTR [edx+0x4]
004CABA1  dfe9                             fucomip st,st(1)
004CABA3  ddd8                             fstp   st(0)
004CABA5  9f                               lahf
004CABA6  f6c444                           test   ah,0x44
004CABA9  7b28                             jnp    0x4cabd3
004CABAB  837d0c00                         cmp    DWORD PTR [ebp+0xc],0x0
004CABAF  8b02                             mov    eax,DWORD PTR [edx]
004CABB1  8981a0000000                     mov    DWORD PTR [ecx+0xa0],eax
004CABB7  8b5204                           mov    edx,DWORD PTR [edx+0x4]
004CABBA  8991a4000000                     mov    DWORD PTR [ecx+0xa4],edx
004CABC0  7411                             je     0x4cabd3
004CABC2  8b01                             mov    eax,DWORD PTR [ecx]
004CABC4  8b5038                           mov    edx,DWORD PTR [eax+0x38]
004CABC7  c781ac00000001000000             mov    DWORD PTR [ecx+0xac],0x1
004CABD1  ffd2                             call   edx
004CABD3  5d                               pop    ebp
004CABD4  c20800                           ret    0x8

; q_actor_update_full 0x561520..0x561678 raw 0x160920
; Complete Q update: qco gates are separate from unconditional subsequent actor loop.
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
005615E3  8b37                             mov    esi,DWORD PTR [edi]
005615E5  3bf7                             cmp    esi,edi
005615E7  7455                             je     0x56163e
005615E9  8da42400000000                   lea    esp,[esp+0x0]
005615F0  8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
005615F3  8b11                             mov    edx,DWORD PTR [ecx]
005615F5  8b4220                           mov    eax,DWORD PTR [edx+0x20]
005615F8  ffd0                             call   eax
005615FA  807e1500                         cmp    BYTE PTR [esi+0x15],0x0
005615FE  753a                             jne    0x56163a
00561600  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00561603  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561607  7516                             jne    0x56161f
00561609  8bf0                             mov    esi,eax
0056160B  8b06                             mov    eax,DWORD PTR [esi]
0056160D  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561611  7527                             jne    0x56163a
00561613  8bf0                             mov    esi,eax
00561615  8b06                             mov    eax,DWORD PTR [esi]
00561617  80781500                         cmp    BYTE PTR [eax+0x15],0x0
0056161B  74f6                             je     0x561613
0056161D  eb1b                             jmp    0x56163a
0056161F  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00561622  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561626  7510                             jne    0x561638
00561628  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0056162B  750b                             jne    0x561638
0056162D  8bf0                             mov    esi,eax
0056162F  8b4004                           mov    eax,DWORD PTR [eax+0x4]
00561632  80781500                         cmp    BYTE PTR [eax+0x15],0x0
00561636  74f0                             je     0x561628
00561638  8bf0                             mov    esi,eax
0056163A  3bf7                             cmp    esi,edi
0056163C  75b2                             jne    0x5615f0
0056163E  f605dc36fe0001                   test   BYTE PTR ds:0xfe36dc,0x1
00561645  7513                             jne    0x56165a
00561647  830ddc36fe0001                   or     DWORD PTR ds:0xfe36dc,0x1
0056164E  33c0                             xor    eax,eax
00561650  a3d436fe00                       mov    ds:0xfe36d4,eax
00561655  a3d836fe00                       mov    ds:0xfe36d8,eax
0056165A  68d436fe00                       push   0xfe36d4
0056165F  e82ceaffff                       call   0x560090
00561664  33c0                             xor    eax,eax
00561666  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0056166A  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00561671  59                               pop    ecx
00561672  5f                               pop    edi
00561673  5e                               pop    esi
00561674  8be5                             mov    esp,ebp
00561676  5d                               pop    ebp
00561677  c3                               ret

; q_stop_lua 0x5695e0..0x56963c raw 0x1689e0
; StopObject C closure invokes one-argument marshaller.
005695E0  55                               push   ebp
005695E1  8bec                             mov    ebp,esp
005695E3  6aff                             push   0xffffffff
005695E5  68c8839300                       push   0x9383c8
005695EA  64a100000000                     mov    eax,fs:0x0
005695F0  50                               push   eax
005695F1  83ec0c                           sub    esp,0xc
005695F4  a1201fd600                       mov    eax,ds:0xd61f20
005695F9  33c5                             xor    eax,ebp
005695FB  50                               push   eax
005695FC  8d45f4                           lea    eax,[ebp-0xc]
005695FF  64a300000000                     mov    fs:0x0,eax
00569605  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00569608  8945e8                           mov    DWORD PTR [ebp-0x18],eax
0056960B  33c0                             xor    eax,eax
0056960D  8945ec                           mov    DWORD PTR [ebp-0x14],eax
00569610  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00569613  8945fc                           mov    DWORD PTR [ebp-0x4],eax
00569616  8b0df827fe00                     mov    ecx,DWORD PTR ds:0xfe27f8
0056961C  51                               push   ecx
0056961D  8d45e8                           lea    eax,[ebp-0x18]
00569620  e80b0e0000                       call   0x56a430
00569625  83c404                           add    esp,0x4
00569628  b801000000                       mov    eax,0x1
0056962D  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00569630  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00569637  59                               pop    ecx
00569638  8be5                             mov    esp,ebp
0056963A  5d                               pop    ebp
0056963B  c3                               ret

; q_one_integer_marshaller 0x56a430..0x56a4a3 raw 0x169830
; Trailing stack value, numeric conversion/default and native receiver call; no result value pushed.
0056A430  55                               push   ebp
0056A431  8bec                             mov    ebp,esp
0056A433  8b08                             mov    ecx,DWORD PTR [eax]
0056A435  83ec18                           sub    esp,0x18
0056A438  53                               push   ebx
0056A439  8b1d7827fe00                     mov    ebx,DWORD PTR ds:0xfe2778
0056A43F  83c8ff                           or     eax,0xffffffff
0056A442  e8a9ac1800                       call   0x6f50f0
0056A447  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0056A44A  83f903                           cmp    ecx,0x3
0056A44D  742a                             je     0x56a479
0056A44F  83f904                           cmp    ecx,0x4
0056A452  7540                             jne    0x56a494
0056A454  56                               push   esi
0056A455  8b30                             mov    esi,DWORD PTR [eax]
0056A457  57                               push   edi
0056A458  83c610                           add    esi,0x10
0056A45B  8d7df8                           lea    edi,[ebp-0x8]
0056A45E  e8fdd21800                       call   0x6f7760
0056A463  5f                               pop    edi
0056A464  5e                               pop    esi
0056A465  85c0                             test   eax,eax
0056A467  742b                             je     0x56a494
0056A469  dd45f8                           fld    QWORD PTR [ebp-0x8]
0056A46C  c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
0056A473  dd5de8                           fstp   QWORD PTR [ebp-0x18]
0056A476  8d45e8                           lea    eax,[ebp-0x18]
0056A479  dd00                             fld    QWORD PTR [eax]
0056A47B  dd5df0                           fstp   QWORD PTR [ebp-0x10]
0056A47E  dd45f0                           fld    QWORD PTR [ebp-0x10]
0056A481  db5dfc                           fistp  DWORD PTR [ebp-0x4]
0056A484  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0056A487  50                               push   eax
0056A488  8bcb                             mov    ecx,ebx
0056A48A  ff5508                           call   DWORD PTR [ebp+0x8]
0056A48D  33c0                             xor    eax,eax
0056A48F  5b                               pop    ebx
0056A490  8be5                             mov    esp,ebp
0056A492  5d                               pop    ebp
0056A493  c3                               ret
0056A494  33c0                             xor    eax,eax
0056A496  50                               push   eax
0056A497  8bcb                             mov    ecx,ebx
0056A499  ff5508                           call   DWORD PTR [ebp+0x8]
0056A49C  33c0                             xor    eax,eax
0056A49E  5b                               pop    ebx
0056A49F  8be5                             mov    esp,ebp
0056A4A1  5d                               pop    ebp
0056A4A2  c3                               ret

; q_stop_native 0x5637e0..0x56382f raw 0x162be0
; Valid Q slot: idle animation and AND E2 with7FFF.
005637E0  55                               push   ebp
005637E1  8bec                             mov    ebp,esp
005637E3  51                               push   ecx
005637E4  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
005637E7  56                               push   esi
005637E8  8bf1                             mov    esi,ecx
005637EA  8d4d08                           lea    ecx,[ebp+0x8]
005637ED  894508                           mov    DWORD PTR [ebp+0x8],eax
005637F0  51                               push   ecx
005637F1  8d4e18                           lea    ecx,[esi+0x18]
005637F4  8d45fc                           lea    eax,[ebp-0x4]
005637F7  e804b72c00                       call   0x82ef00
005637FC  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
005637FF  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
00563802  7424                             je     0x563828
00563804  8b7010                           mov    esi,DWORD PTR [eax+0x10]
00563807  85f6                             test   esi,esi
00563809  741d                             je     0x563828
0056380B  d9e8                             fld1
0056380D  8b16                             mov    edx,DWORD PTR [esi]
0056380F  8b4268                           mov    eax,DWORD PTR [edx+0x68]
00563812  51                               push   ecx
00563813  d91c24                           fstp   DWORD PTR [esp]
00563816  6a01                             push   0x1
00563818  8bce                             mov    ecx,esi
0056381A  ffd0                             call   eax
0056381C  b9ff7f0000                       mov    ecx,0x7fff
00563821  66218ee2000000                   and    WORD PTR [esi+0xe2],cx
00563828  5e                               pop    esi
00563829  8be5                             mov    esp,ebp
0056382B  5d                               pop    ebp
0056382C  c20400                           ret    0x4

; q_warp_native 0x5633b0..0x5634d7 raw 0x1627b0
; Valid Q slot: clears E0 high-word bit8000, positions and direction, optional motion.
005633B0  55                               push   ebp
005633B1  8bec                             mov    ebp,esp
005633B3  83e4f8                           and    esp,0xfffffff8
005633B6  83ec0c                           sub    esp,0xc
005633B9  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
005633BC  53                               push   ebx
005633BD  56                               push   esi
005633BE  8bf1                             mov    esi,ecx
005633C0  57                               push   edi
005633C1  8d4c240c                         lea    ecx,[esp+0xc]
005633C5  8944240c                         mov    DWORD PTR [esp+0xc],eax
005633C9  51                               push   ecx
005633CA  8d4e18                           lea    ecx,[esi+0x18]
005633CD  8d442414                         lea    eax,[esp+0x14]
005633D1  e82abb2c00                       call   0x82ef00
005633D6  8b442410                         mov    eax,DWORD PTR [esp+0x10]
005633DA  3b461c                           cmp    eax,DWORD PTR [esi+0x1c]
005633DD  0f84eb000000                     je     0x5634ce
005633E3  8b7010                           mov    esi,DWORD PTR [eax+0x10]
005633E6  85f6                             test   esi,esi
005633E8  0f84e0000000                     je     0x5634ce
005633EE  8b86e0000000                     mov    eax,DWORD PTR [esi+0xe0]
005633F4  8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
005633FA  8b11                             mov    edx,DWORD PTR [ecx]
005633FC  8a9ee4000000                     mov    bl,BYTE PTR [esi+0xe4]
00563402  89442410                         mov    DWORD PTR [esp+0x10],eax
00563406  c1e810                           shr    eax,0x10
00563409  25ff7f0000                       and    eax,0x7fff
0056340E  6689442412                       mov    WORD PTR [esp+0x12],ax
00563413  8b4220                           mov    eax,DWORD PTR [edx+0x20]
00563416  885c2414                         mov    BYTE PTR [esp+0x14],bl
0056341A  ffd0                             call   eax
0056341C  8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
00563420  8b16                             mov    edx,DWORD PTR [esi]
00563422  8b442414                         mov    eax,DWORD PTR [esp+0x14]
00563426  8b5258                           mov    edx,DWORD PTR [edx+0x58]
00563429  898ee0000000                     mov    DWORD PTR [esi+0xe0],ecx
0056342F  50                               push   eax
00563430  8bce                             mov    ecx,esi
00563432  889ee4000000                     mov    BYTE PTR [esi+0xe4],bl
00563438  ffd2                             call   edx
0056343A  f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
0056343F  8b06                             mov    eax,DWORD PTR [esi]
00563441  8b5044                           mov    edx,DWORD PTR [eax+0x44]
00563444  6a01                             push   0x1
00563446  8d4c2414                         lea    ecx,[esp+0x14]
0056344A  f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
00563450  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
00563455  51                               push   ecx
00563456  8bce                             mov    ecx,esi
00563458  f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
0056345E  ffd2                             call   edx
00563460  8b4d14                           mov    ecx,DWORD PTR [ebp+0x14]
00563463  8b06                             mov    eax,DWORD PTR [esi]
00563465  8b5058                           mov    edx,DWORD PTR [eax+0x58]
00563468  51                               push   ecx
00563469  8bce                             mov    ecx,esi
0056346B  ffd2                             call   edx
0056346D  83bea803000000                   cmp    DWORD PTR [esi+0x3a8],0x0
00563474  8a86b0000000                     mov    al,BYTE PTR [esi+0xb0]
0056347A  88442410                         mov    BYTE PTR [esp+0x10],al
0056347E  7535                             jne    0x5634b5
00563480  83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
00563487  8886a4030000                     mov    BYTE PTR [esi+0x3a4],al
0056348D  7426                             je     0x5634b5
0056348F  8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
00563495  85c0                             test   eax,eax
00563497  741c                             je     0x5634b5
00563499  8b7804                           mov    edi,DWORD PTR [eax+0x4]
0056349C  8d5804                           lea    ebx,[eax+0x4]
0056349F  8b442410                         mov    eax,DWORD PTR [esp+0x10]
005634A3  50                               push   eax
005634A4  e8e715eeff                       call   0x444a90
005634A9  8b570c                           mov    edx,DWORD PTR [edi+0xc]
005634AC  8bcb                             mov    ecx,ebx
005634AE  f30f110424                       movss  DWORD PTR [esp],xmm0
005634B3  ffd2                             call   edx
005634B5  837d1800                         cmp    DWORD PTR [ebp+0x18],0x0
005634B9  7413                             je     0x5634ce
005634BB  d9e8                             fld1
005634BD  8b06                             mov    eax,DWORD PTR [esi]
005634BF  8b5068                           mov    edx,DWORD PTR [eax+0x68]
005634C2  51                               push   ecx
005634C3  8b4d1c                           mov    ecx,DWORD PTR [ebp+0x1c]
005634C6  d91c24                           fstp   DWORD PTR [esp]
005634C9  51                               push   ecx
005634CA  8bce                             mov    ecx,esi
005634CC  ffd2                             call   edx
005634CE  5f                               pop    edi
005634CF  5e                               pop    esi
005634D0  5b                               pop    ebx
005634D1  8be5                             mov    esp,ebp
005634D3  5d                               pop    ebp
005634D4  c21800                           ret    0x18

; event_actor_constructor 0x4d0b80..0x4d0c96 raw 0xcff80
; CEventActor actual vptrs; movement speed defaults. Creation / lifetime owned by actors sibling.
004D0B80  55                               push   ebp
004D0B81  8bec                             mov    ebp,esp
004D0B83  6aff                             push   0xffffffff
004D0B85  6823099100                       push   0x910923
004D0B8A  64a100000000                     mov    eax,fs:0x0
004D0B90  50                               push   eax
004D0B91  51                               push   ecx
004D0B92  53                               push   ebx
004D0B93  56                               push   esi
004D0B94  57                               push   edi
004D0B95  a1201fd600                       mov    eax,ds:0xd61f20
004D0B9A  33c5                             xor    eax,ebp
004D0B9C  50                               push   eax
004D0B9D  8d45f4                           lea    eax,[ebp-0xc]
004D0BA0  64a300000000                     mov    fs:0x0,eax
004D0BA6  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
004D0BA9  57                               push   edi
004D0BAA  e8c164ffff                       call   0x4c7070
004D0BAF  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004D0BB6  6a3c                             push   0x3c
004D0BB8  c70724c8c000                     mov    DWORD PTR [edi],0xc0c824
004D0BBE  c787f0000000acc8c000             mov    DWORD PTR [edi+0xf0],0xc0c8ac
004D0BC8  e89b063c00                       call   0x891268
004D0BCD  8bf0                             mov    esi,eax
004D0BCF  83c404                           add    esp,0x4
004D0BD2  8975f0                           mov    DWORD PTR [ebp-0x10],esi
004D0BD5  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
004D0BD9  85f6                             test   esi,esi
004D0BDB  741b                             je     0x4d0bf8
004D0BDD  8bc7                             mov    eax,edi
004D0BDF  b903000000                       mov    ecx,0x3
004D0BE4  e847a6ffff                       call   0x4cb230
004D0BE9  c706cc77c000                     mov    DWORD PTR [esi],0xc077cc
004D0BEF  c7463401000000                   mov    DWORD PTR [esi+0x34],0x1
004D0BF6  eb02                             jmp    0x4d0bfa
004D0BF8  33f6                             xor    esi,esi
004D0BFA  8b5e08                           mov    ebx,DWORD PTR [esi+0x8]
004D0BFD  83bc9ff400000000                 cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
004D0C05  740d                             je     0x4d0c14
004D0C07  683c75c000                       push   0xc0753c
004D0C0C  e84fcf2100                       call   0x6edb60
004D0C11  83c404                           add    esp,0x4
004D0C14  89b49ff4000000                   mov    DWORD PTR [edi+ebx*4+0xf4],esi
004D0C1B  83bf5801000000                   cmp    DWORD PTR [edi+0x158],0x0
004D0C22  7506                             jne    0x4d0c2a
004D0C24  89b758010000                     mov    DWORD PTR [edi+0x158],esi
004D0C2A  f30f10056c5bc500                 movss  xmm0,DWORD PTR ds:0xc55b6c
004D0C32  f30f118794030000                 movss  DWORD PTR [edi+0x394],xmm0
004D0C3A  f30f1187cc000000                 movss  DWORD PTR [edi+0xcc],xmm0
004D0C42  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
004D0C4A  f30f118734040000                 movss  DWORD PTR [edi+0x434],xmm0
004D0C52  f30f1005385bc500                 movss  xmm0,DWORD PTR ds:0xc55b38
004D0C5A  c7872004000000000000             mov    DWORD PTR [edi+0x420],0x0
004D0C64  c7872c04000001000000             mov    DWORD PTR [edi+0x42c],0x1
004D0C6E  c787d000000064000000             mov    DWORD PTR [edi+0xd0],0x64
004D0C78  f30f118730040000                 movss  DWORD PTR [edi+0x430],xmm0
004D0C80  8bc7                             mov    eax,edi
004D0C82  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004D0C85  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004D0C8C  59                               pop    ecx
004D0C8D  5f                               pop    edi
004D0C8E  5e                               pop    esi
004D0C8F  5b                               pop    ebx
004D0C90  8be5                             mov    esp,ebp
004D0C92  5d                               pop    ebp
004D0C93  c20400                           ret    0x4

; actor_base_constructor_prefix 0x4c7070..0x4c70a2 raw 0xc6470
; CActor constructor passes the same allocation to basic initialization.
004C7070  55                               push   ebp
004C7071  8bec                             mov    ebp,esp
004C7073  6aff                             push   0xffffffff
004C7075  68dcda9000                       push   0x90dadc
004C707A  64a100000000                     mov    eax,fs:0x0
004C7080  50                               push   eax
004C7081  83ec24                           sub    esp,0x24
004C7084  53                               push   ebx
004C7085  56                               push   esi
004C7086  57                               push   edi
004C7087  a1201fd600                       mov    eax,ds:0xd61f20
004C708C  33c5                             xor    eax,ebp
004C708E  50                               push   eax
004C708F  8d45f4                           lea    eax,[ebp-0xc]
004C7092  64a300000000                     mov    fs:0x0,eax
004C7098  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004C709B  8bf3                             mov    esi,ebx
004C709D  e88e360000                       call   0x4ca730

; basic_object_constructor 0x4ca730..0x4ca7fa raw 0xc9b30
; Observed base initialization writes D4=0, E0=0 and E4=0; not a proof of absence of all later writers.
004CA730  f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
004CA738  f30f1186b4000000                 movss  DWORD PTR [esi+0xb4],xmm0
004CA740  0f57c0                           xorps  xmm0,xmm0
004CA743  53                               push   ebx
004CA744  33db                             xor    ebx,ebx
004CA746  c706ac76c000                     mov    DWORD PTR [esi],0xc076ac
004CA74C  899e88000000                     mov    DWORD PTR [esi+0x88],ebx
004CA752  899e8c000000                     mov    DWORD PTR [esi+0x8c],ebx
004CA758  c786900000007f000000             mov    DWORD PTR [esi+0x90],0x7f
004CA762  899e98000000                     mov    DWORD PTR [esi+0x98],ebx
004CA768  899e9c000000                     mov    DWORD PTR [esi+0x9c],ebx
004CA76E  899eac000000                     mov    DWORD PTR [esi+0xac],ebx
004CA774  899eb8000000                     mov    DWORD PTR [esi+0xb8],ebx
004CA77A  889ebc000000                     mov    BYTE PTR [esi+0xbc],bl
004CA780  f30f1186c0000000                 movss  DWORD PTR [esi+0xc0],xmm0
004CA788  f30f1186c4000000                 movss  DWORD PTR [esi+0xc4],xmm0
004CA790  899ec8000000                     mov    DWORD PTR [esi+0xc8],ebx
004CA796  6880000000                       push   0x80
004CA79B  f30f1186cc000000                 movss  DWORD PTR [esi+0xcc],xmm0
004CA7A3  c786d000000064000000             mov    DWORD PTR [esi+0xd0],0x64
004CA7AD  899ed4000000                     mov    DWORD PTR [esi+0xd4],ebx
004CA7B3  8d4606                           lea    eax,[esi+0x6]
004CA7B6  33d2                             xor    edx,edx
004CA7B8  53                               push   ebx
004CA7B9  f30f1186d8000000                 movss  DWORD PTR [esi+0xd8],xmm0
004CA7C1  f30f1186dc000000                 movss  DWORD PTR [esi+0xdc],xmm0
004CA7C9  50                               push   eax
004CA7CA  66895604                         mov    WORD PTR [esi+0x4],dx
004CA7CE  e88d403d00                       call   0x89e860
004CA7D3  33c0                             xor    eax,eax
004CA7D5  8986a0000000                     mov    DWORD PTR [esi+0xa0],eax
004CA7DB  8986a4000000                     mov    DWORD PTR [esi+0xa4],eax
004CA7E1  8986a8000000                     mov    DWORD PTR [esi+0xa8],eax
004CA7E7  899ee0000000                     mov    DWORD PTR [esi+0xe0],ebx
004CA7ED  83c40c                           add    esp,0xc
004CA7F0  889ee4000000                     mov    BYTE PTR [esi+0xe4],bl
004CA7F6  8bc6                             mov    eax,esi
004CA7F8  5b                               pop    ebx
004CA7F9  c3                               ret

; tutorial_binding_chain 0x4a88e0..0x4a89bf raw 0xa7ce0
; Complete 31 regular Tutorial registrar call chain; namespace construction reused from prior report.
004A88E0  55                               push   ebp
004A88E1  8bec                             mov    ebp,esp
004A88E3  83ec08                           sub    esp,0x8
004A88E6  8d4dfc                           lea    ecx,[ebp-0x4]
004A88E9  56                               push   esi
004A88EA  51                               push   ecx
004A88EB  8930                             mov    DWORD PTR [eax],esi
004A88ED  e8ae1c0000                       call   0x4aa5a0
004A88F2  83c408                           add    esp,0x8
004A88F5  50                               push   eax
004A88F6  e8851d0000                       call   0x4aa680
004A88FB  50                               push   eax
004A88FC  e81f1e0000                       call   0x4aa720
004A8901  50                               push   eax
004A8902  e8b91e0000                       call   0x4aa7c0
004A8907  50                               push   eax
004A8908  e8531f0000                       call   0x4aa860
004A890D  50                               push   eax
004A890E  e8ed1f0000                       call   0x4aa900
004A8913  50                               push   eax
004A8914  e887200000                       call   0x4aa9a0
004A8919  50                               push   eax
004A891A  e821210000                       call   0x4aaa40
004A891F  50                               push   eax
004A8920  e8bb210000                       call   0x4aaae0
004A8925  50                               push   eax
004A8926  e855220000                       call   0x4aab80
004A892B  50                               push   eax
004A892C  e8ef220000                       call   0x4aac20
004A8931  50                               push   eax
004A8932  e889230000                       call   0x4aacc0
004A8937  50                               push   eax
004A8938  e823240000                       call   0x4aad60
004A893D  50                               push   eax
004A893E  e8bd240000                       call   0x4aae00
004A8943  50                               push   eax
004A8944  e857250000                       call   0x4aaea0
004A8949  50                               push   eax
004A894A  e8f1250000                       call   0x4aaf40
004A894F  50                               push   eax
004A8950  e88b260000                       call   0x4aafe0
004A8955  50                               push   eax
004A8956  e825270000                       call   0x4ab080
004A895B  50                               push   eax
004A895C  e8bf270000                       call   0x4ab120
004A8961  50                               push   eax
004A8962  e859280000                       call   0x4ab1c0
004A8967  50                               push   eax
004A8968  e8f3280000                       call   0x4ab260
004A896D  50                               push   eax
004A896E  e88d290000                       call   0x4ab300
004A8973  50                               push   eax
004A8974  e8272a0000                       call   0x4ab3a0
004A8979  50                               push   eax
004A897A  e8c12a0000                       call   0x4ab440
004A897F  50                               push   eax
004A8980  e85b2b0000                       call   0x4ab4e0
004A8985  50                               push   eax
004A8986  e8f52b0000                       call   0x4ab580
004A898B  50                               push   eax
004A898C  e88f2c0000                       call   0x4ab620
004A8991  50                               push   eax
004A8992  e8292d0000                       call   0x4ab6c0
004A8997  50                               push   eax
004A8998  e8c32d0000                       call   0x4ab760
004A899D  50                               push   eax
004A899E  e85d2e0000                       call   0x4ab800
004A89A3  50                               push   eax
004A89A4  e8f72e0000                       call   0x4ab8a0
004A89A9  50                               push   eax
004A89AA  e8912f0000                       call   0x4ab940
004A89AF  686468c000                       push   0xc06864
004A89B4  8bce                             mov    ecx,esi
004A89B6  e895c02400                       call   0x6f4a50
004A89BB  8be5                             mov    esp,ebp
004A89BD  5d                               pop    ebp
004A89BE  c3                               ret

; tutorial_state_getter 0x4a9fd0..0x4a9fdc raw 0xa93d0
; Reads current controller+134; does not use native binding receiver.
004A9FD0  a1a4a7fb00                       mov    eax,ds:0xfba7a4
004A9FD5  8b8034010000                     mov    eax,DWORD PTR [eax+0x134]
004A9FDB  c3                               ret

; tutorial_state_lua 0x4ac700..0x4ac76e raw 0xabb00
; GetTutorialState number-result thunk.
004AC700  55                               push   ebp
004AC701  8bec                             mov    ebp,esp
004AC703  6aff                             push   0xffffffff
004AC705  68d8879300                       push   0x9387d8
004AC70A  64a100000000                     mov    eax,fs:0x0
004AC710  50                               push   eax
004AC711  83ec0c                           sub    esp,0xc
004AC714  56                               push   esi
004AC715  a1201fd600                       mov    eax,ds:0xd61f20
004AC71A  33c5                             xor    eax,ebp
004AC71C  50                               push   eax
004AC71D  8d45f4                           lea    eax,[ebp-0xc]
004AC720  64a300000000                     mov    fs:0x0,eax
004AC726  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
004AC729  33c0                             xor    eax,eax
004AC72B  8975e8                           mov    DWORD PTR [ebp-0x18],esi
004AC72E  8945ec                           mov    DWORD PTR [ebp-0x14],eax
004AC731  8945f0                           mov    DWORD PTR [ebp-0x10],eax
004AC734  8945fc                           mov    DWORD PTR [ebp-0x4],eax
004AC737  8b0d0418fe00                     mov    ecx,DWORD PTR ds:0xfe1804
004AC73D  ff156018fe00                     call   DWORD PTR ds:0xfe1860
004AC743  894508                           mov    DWORD PTR [ebp+0x8],eax
004AC746  8b4608                           mov    eax,DWORD PTR [esi+0x8]
004AC749  db4508                           fild   DWORD PTR [ebp+0x8]
004AC74C  c7400803000000                   mov    DWORD PTR [eax+0x8],0x3
004AC753  dd18                             fstp   QWORD PTR [eax]
004AC755  83460810                         add    DWORD PTR [esi+0x8],0x10
004AC759  b801000000                       mov    eax,0x1
004AC75E  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004AC761  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004AC768  59                               pop    ecx
004AC769  5e                               pop    esi
004AC76A  8be5                             mov    esp,ebp
004AC76C  5d                               pop    ebp
004AC76D  c3                               ret

; tutorial_controller_constructor 0x548b90..0x548c73 raw 0x147f90
; Typed Tutorial controller initialization of+134 to0.
00548B90  51                               push   ecx
00548B91  56                               push   esi
00548B92  e8a9c0ffff                       call   0x544c40
00548B97  33c0                             xor    eax,eax
00548B99  898634010000                     mov    DWORD PTR [esi+0x134],eax
00548B9F  c7061cfbc000                     mov    DWORD PTR [esi],0xc0fb1c
00548BA5  8986b4000000                     mov    DWORD PTR [esi+0xb4],eax
00548BAB  8986b8000000                     mov    DWORD PTR [esi+0xb8],eax
00548BB1  8986bc000000                     mov    DWORD PTR [esi+0xbc],eax
00548BB7  8986c0000000                     mov    DWORD PTR [esi+0xc0],eax
00548BBD  8986c4000000                     mov    DWORD PTR [esi+0xc4],eax
00548BC3  8986c8000000                     mov    DWORD PTR [esi+0xc8],eax
00548BC9  8986cc000000                     mov    DWORD PTR [esi+0xcc],eax
00548BCF  8986d0000000                     mov    DWORD PTR [esi+0xd0],eax
00548BD5  8986d4000000                     mov    DWORD PTR [esi+0xd4],eax
00548BDB  8986d8000000                     mov    DWORD PTR [esi+0xd8],eax
00548BE1  8986dc000000                     mov    DWORD PTR [esi+0xdc],eax
00548BE7  8986e0000000                     mov    DWORD PTR [esi+0xe0],eax
00548BED  8986e4000000                     mov    DWORD PTR [esi+0xe4],eax
00548BF3  8986e8000000                     mov    DWORD PTR [esi+0xe8],eax
00548BF9  8986ec000000                     mov    DWORD PTR [esi+0xec],eax
00548BFF  8986f0000000                     mov    DWORD PTR [esi+0xf0],eax
00548C05  8986f4000000                     mov    DWORD PTR [esi+0xf4],eax
00548C0B  8986f8000000                     mov    DWORD PTR [esi+0xf8],eax
00548C11  8986fc000000                     mov    DWORD PTR [esi+0xfc],eax
00548C17  898600010000                     mov    DWORD PTR [esi+0x100],eax
00548C1D  898604010000                     mov    DWORD PTR [esi+0x104],eax
00548C23  898608010000                     mov    DWORD PTR [esi+0x108],eax
00548C29  89860c010000                     mov    DWORD PTR [esi+0x10c],eax
00548C2F  898610010000                     mov    DWORD PTR [esi+0x110],eax
00548C35  898614010000                     mov    DWORD PTR [esi+0x114],eax
00548C3B  898618010000                     mov    DWORD PTR [esi+0x118],eax
00548C41  89861c010000                     mov    DWORD PTR [esi+0x11c],eax
00548C47  898620010000                     mov    DWORD PTR [esi+0x120],eax
00548C4D  898624010000                     mov    DWORD PTR [esi+0x124],eax
00548C53  898628010000                     mov    DWORD PTR [esi+0x128],eax
00548C59  89862c010000                     mov    DWORD PTR [esi+0x12c],eax
00548C5F  898630010000                     mov    DWORD PTR [esi+0x130],eax
00548C65  c705aca7fb0004000000             mov    DWORD PTR ds:0xfba7ac,0x4
00548C6F  8bc6                             mov    eax,esi
00548C71  59                               pop    ecx
00548C72  c3                               ret

; tutorial_dialog_getter 0x54e740..0x54e744 raw 0x14db40
; IsLeaderDialogOpened reads native receiver+38.
0054E740  8b4138                           mov    eax,DWORD PTR [ecx+0x38]
0054E743  c3                               ret

; tutorial_dialog_lua 0x4ac970..0x4ac9de raw 0xabd70
; Tutorial FE1804 receiver, FE1878 target and Lua number-result push.
004AC970  55                               push   ebp
004AC971  8bec                             mov    ebp,esp
004AC973  6aff                             push   0xffffffff
004AC975  68d8879300                       push   0x9387d8
004AC97A  64a100000000                     mov    eax,fs:0x0
004AC980  50                               push   eax
004AC981  83ec0c                           sub    esp,0xc
004AC984  56                               push   esi
004AC985  a1201fd600                       mov    eax,ds:0xd61f20
004AC98A  33c5                             xor    eax,ebp
004AC98C  50                               push   eax
004AC98D  8d45f4                           lea    eax,[ebp-0xc]
004AC990  64a300000000                     mov    fs:0x0,eax
004AC996  8b7508                           mov    esi,DWORD PTR [ebp+0x8]
004AC999  33c0                             xor    eax,eax
004AC99B  8975e8                           mov    DWORD PTR [ebp-0x18],esi
004AC99E  8945ec                           mov    DWORD PTR [ebp-0x14],eax
004AC9A1  8945f0                           mov    DWORD PTR [ebp-0x10],eax
004AC9A4  8945fc                           mov    DWORD PTR [ebp-0x4],eax
004AC9A7  8b0d0418fe00                     mov    ecx,DWORD PTR ds:0xfe1804
004AC9AD  ff157818fe00                     call   DWORD PTR ds:0xfe1878
004AC9B3  894508                           mov    DWORD PTR [ebp+0x8],eax
004AC9B6  8b4608                           mov    eax,DWORD PTR [esi+0x8]
004AC9B9  db4508                           fild   DWORD PTR [ebp+0x8]
004AC9BC  c7400803000000                   mov    DWORD PTR [eax+0x8],0x3
004AC9C3  dd18                             fstp   QWORD PTR [eax]
004AC9C5  83460810                         add    DWORD PTR [esi+0x8],0x10
004AC9C9  b801000000                       mov    eax,0x1
004AC9CE  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004AC9D1  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004AC9D8  59                               pop    ecx
004AC9D9  5e                               pop    esi
004AC9DA  8be5                             mov    esp,ebp
004AC9DC  5d                               pop    ebp
004AC9DD  c3                               ret

; tutorial_owner_constructor_normal 0x47aeb0..0x47afc3 raw 0x7a2b0
; Normal constructor path initializes FC0FBC=0; exception allocation paths outside this window.
0047AEB0  55                               push   ebp
0047AEB1  8bec                             mov    ebp,esp
0047AEB3  6aff                             push   0xffffffff
0047AEB5  68dab69000                       push   0x90b6da
0047AEBA  64a100000000                     mov    eax,fs:0x0
0047AEC0  50                               push   eax
0047AEC1  83ec24                           sub    esp,0x24
0047AEC4  53                               push   ebx
0047AEC5  56                               push   esi
0047AEC6  a1201fd600                       mov    eax,ds:0xd61f20
0047AECB  33c5                             xor    eax,ebp
0047AECD  50                               push   eax
0047AECE  8d45f4                           lea    eax,[ebp-0xc]
0047AED1  64a300000000                     mov    fs:0x0,eax
0047AED7  33f6                             xor    esi,esi
0047AED9  6a18                             push   0x18
0047AEDB  c745e8840ffc00                   mov    DWORD PTR [ebp-0x18],0xfc0f84
0047AEE2  8935900ffc00                     mov    DWORD PTR ds:0xfc0f90,esi
0047AEE8  e87b634100                       call   0x891268
0047AEED  83c404                           add    esp,0x4
0047AEF0  3bc6                             cmp    eax,esi
0047AEF2  0f84ef000000                     je     0x47afe7
0047AEF8  a38c0ffc00                       mov    ds:0xfc0f8c,eax
0047AEFD  8900                             mov    DWORD PTR [eax],eax
0047AEFF  a18c0ffc00                       mov    eax,ds:0xfc0f8c
0047AF04  894004                           mov    DWORD PTR [eax+0x4],eax
0047AF07  a18c0ffc00                       mov    eax,ds:0xfc0f8c
0047AF0C  894008                           mov    DWORD PTR [eax+0x8],eax
0047AF0F  a18c0ffc00                       mov    eax,ds:0xfc0f8c
0047AF14  bb01000000                       mov    ebx,0x1
0047AF19  885814                           mov    BYTE PTR [eax+0x14],bl
0047AF1C  8b0d8c0ffc00                     mov    ecx,DWORD PTR ds:0xfc0f8c
0047AF22  885915                           mov    BYTE PTR [ecx+0x15],bl
0047AF25  8975fc                           mov    DWORD PTR [ebp-0x4],esi
0047AF28  6a14                             push   0x14
0047AF2A  8935a00ffc00                     mov    DWORD PTR ds:0xfc0fa0,esi
0047AF30  e833634100                       call   0x891268
0047AF35  83c404                           add    esp,0x4
0047AF38  3bc6                             cmp    eax,esi
0047AF3A  0f8483000000                     je     0x47afc3
0047AF40  a39c0ffc00                       mov    ds:0xfc0f9c,eax
0047AF45  8900                             mov    DWORD PTR [eax],eax
0047AF47  a19c0ffc00                       mov    eax,ds:0xfc0f9c
0047AF4C  894004                           mov    DWORD PTR [eax+0x4],eax
0047AF4F  a19c0ffc00                       mov    eax,ds:0xfc0f9c
0047AF54  894008                           mov    DWORD PTR [eax+0x8],eax
0047AF57  8b159c0ffc00                     mov    edx,DWORD PTR ds:0xfc0f9c
0047AF5D  885a10                           mov    BYTE PTR [edx+0x10],bl
0047AF60  a19c0ffc00                       mov    eax,ds:0xfc0f9c
0047AF65  885811                           mov    BYTE PTR [eax+0x11],bl
0047AF68  885dfc                           mov    BYTE PTR [ebp-0x4],bl
0047AF6B  8bc3                             mov    eax,ebx
0047AF6D  8935b00ffc00                     mov    DWORD PTR ds:0xfc0fb0,esi
0047AF73  e8985a0f00                       call   0x570a10
0047AF78  a3ac0ffc00                       mov    ds:0xfc0fac,eax
0047AF7D  8900                             mov    DWORD PTR [eax],eax
0047AF7F  a1ac0ffc00                       mov    eax,ds:0xfc0fac
0047AF84  894004                           mov    DWORD PTR [eax+0x4],eax
0047AF87  a1ac0ffc00                       mov    eax,ds:0xfc0fac
0047AF8C  894008                           mov    DWORD PTR [eax+0x8],eax
0047AF8F  8b0dac0ffc00                     mov    ecx,DWORD PTR ds:0xfc0fac
0047AF95  885940                           mov    BYTE PTR [ecx+0x40],bl
0047AF98  8b15ac0ffc00                     mov    edx,DWORD PTR ds:0xfc0fac
0047AF9E  885a41                           mov    BYTE PTR [edx+0x41],bl
0047AFA1  8935b80ffc00                     mov    DWORD PTR ds:0xfc0fb8,esi
0047AFA7  8935bc0ffc00                     mov    DWORD PTR ds:0xfc0fbc,esi
0047AFAD  b8840ffc00                       mov    eax,0xfc0f84
0047AFB2  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0047AFB5  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0047AFBC  59                               pop    ecx
0047AFBD  5e                               pop    esi
0047AFBE  5b                               pop    ebx
0047AFBF  8be5                             mov    esp,ebp
0047AFC1  5d                               pop    ebp
0047AFC2  c3                               ret

; tutorial_page_event_dispatch 0x5c32d0..0x5c3346 raw 0x1c26d0
; Tutorial page v+18C calls dialog toggle for event F42DD.
005C32D0  55                               push   ebp
005C32D1  8bec                             mov    ebp,esp
005C32D3  56                               push   esi
005C32D4  57                               push   edi
005C32D5  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
005C32D8  57                               push   edi
005C32D9  8bf1                             mov    esi,ecx
005C32DB  e84081fdff                       call   0x59b420
005C32E0  8b4710                           mov    eax,DWORD PTR [edi+0x10]
005C32E3  2ddb420f00                       sub    eax,0xf42db
005C32E8  7424                             je     0x5c330e
005C32EA  83e802                           sub    eax,0x2
005C32ED  7412                             je     0x5c3301
005C32EF  83e842                           sub    eax,0x42
005C32F2  754c                             jne    0x5c3340
005C32F4  8bc7                             mov    eax,edi
005C32F6  e8d5030000                       call   0x5c36d0
005C32FB  5f                               pop    edi
005C32FC  5e                               pop    esi
005C32FD  5d                               pop    ebp
005C32FE  c20400                           ret    0x4
005C3301  8bce                             mov    ecx,esi
005C3303  e8a8010000                       call   0x5c34b0
005C3308  5f                               pop    edi
005C3309  5e                               pop    esi
005C330A  5d                               pop    ebp
005C330B  c20400                           ret    0x4
005C330E  8b8e20020000                     mov    ecx,DWORD PTR [esi+0x220]
005C3314  8b4128                           mov    eax,DWORD PTR [ecx+0x28]
005C3317  c1e808                           shr    eax,0x8
005C331A  a801                             test   al,0x1
005C331C  741b                             je     0x5c3339
005C331E  8b5128                           mov    edx,DWORD PTR [ecx+0x28]
005C3321  c1ea08                           shr    edx,0x8
005C3324  f6c201                           test   dl,0x1
005C3327  7417                             je     0x5c3340
005C3329  8b01                             mov    eax,DWORD PTR [ecx]
005C332B  8b90d4000000                     mov    edx,DWORD PTR [eax+0xd4]
005C3331  ffd2                             call   edx
005C3333  5f                               pop    edi
005C3334  5e                               pop    esi
005C3335  5d                               pop    ebp
005C3336  c20400                           ret    0x4
005C3339  51                               push   ecx
005C333A  56                               push   esi
005C333B  e8c03afdff                       call   0x596e00
005C3340  5f                               pop    edi
005C3341  5e                               pop    esi
005C3342  5d                               pop    ebp
005C3343  c20400                           ret    0x4

; tutorial_dialog_toggle 0x5c34b0..0x5c360b raw 0x1c28b0
; Actual FC0FBC0/1 writer, conditional on window+28 visibility bit.
005C34B0  55                               push   ebp
005C34B1  8bec                             mov    ebp,esp
005C34B3  6aff                             push   0xffffffff
005C34B5  687c989300                       push   0x93987c
005C34BA  64a100000000                     mov    eax,fs:0x0
005C34C0  50                               push   eax
005C34C1  53                               push   ebx
005C34C2  56                               push   esi
005C34C3  a1201fd600                       mov    eax,ds:0xd61f20
005C34C8  33c5                             xor    eax,ebp
005C34CA  50                               push   eax
005C34CB  8d45f4                           lea    eax,[ebp-0xc]
005C34CE  64a300000000                     mov    fs:0x0,eax
005C34D4  8bf1                             mov    esi,ecx
005C34D6  8b8e24020000                     mov    ecx,DWORD PTR [esi+0x224]
005C34DC  8b01                             mov    eax,DWORD PTR [ecx]
005C34DE  8b906c010000                     mov    edx,DWORD PTR [eax+0x16c]
005C34E4  6a00                             push   0x0
005C34E6  ffd2                             call   edx
005C34E8  8b8e24020000                     mov    ecx,DWORD PTR [esi+0x224]
005C34EE  8b4128                           mov    eax,DWORD PTR [ecx+0x28]
005C34F1  c1e808                           shr    eax,0x8
005C34F4  bb01000000                       mov    ebx,0x1
005C34F9  84c3                             test   bl,al
005C34FB  0f8490000000                     je     0x5c3591
005C3501  8b5128                           mov    edx,DWORD PTR [ecx+0x28]
005C3504  c1ea08                           shr    edx,0x8
005C3507  84d3                             test   bl,dl
005C3509  740a                             je     0x5c3515
005C350B  8b01                             mov    eax,DWORD PTR [ecx]
005C350D  8b90d4000000                     mov    edx,DWORD PTR [eax+0xd4]
005C3513  ffd2                             call   edx
005C3515  8bb628020000                     mov    esi,DWORD PTR [esi+0x228]
005C351B  8b8ea8000000                     mov    ecx,DWORD PTR [esi+0xa8]
005C3521  8b01                             mov    eax,DWORD PTR [ecx]
005C3523  8b9094000000                     mov    edx,DWORD PTR [eax+0x94]
005C3529  6a00                             push   0x0
005C352B  ffd2                             call   edx
005C352D  80bedd00000000                   cmp    BYTE PTR [esi+0xdd],0x0
005C3534  8b8ea4000000                     mov    ecx,DWORD PTR [esi+0xa4]
005C353A  8b11                             mov    edx,DWORD PTR [ecx]
005C353C  0f95c0                           setne  al
005C353F  50                               push   eax
005C3540  8b8294000000                     mov    eax,DWORD PTR [edx+0x94]
005C3546  ffd0                             call   eax
005C3548  c686de00000000                   mov    BYTE PTR [esi+0xde],0x0
005C354F  841d800ffc00                     test   BYTE PTR ds:0xfc0f80,bl
005C3555  751f                             jne    0x5c3576
005C3557  091d800ffc00                     or     DWORD PTR ds:0xfc0f80,ebx
005C355D  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
005C3564  e84779ebff                       call   0x47aeb0
005C3569  6870dbbc00                       push   0xbcdb70
005C356E  e8a7ed2c00                       call   0x89231a
005C3573  83c404                           add    esp,0x4
005C3576  c705bc0ffc0000000000             mov    DWORD PTR ds:0xfc0fbc,0x0
005C3580  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
005C3583  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
005C358A  59                               pop    ecx
005C358B  5e                               pop    esi
005C358C  5b                               pop    ebx
005C358D  8be5                             mov    esp,ebp
005C358F  5d                               pop    ebp
005C3590  c3                               ret
005C3591  51                               push   ecx
005C3592  56                               push   esi
005C3593  e86838fdff                       call   0x596e00
005C3598  8bb628020000                     mov    esi,DWORD PTR [esi+0x228]
005C359E  80bedd00000000                   cmp    BYTE PTR [esi+0xdd],0x0
005C35A5  8b8ea8000000                     mov    ecx,DWORD PTR [esi+0xa8]
005C35AB  8b11                             mov    edx,DWORD PTR [ecx]
005C35AD  0f95c0                           setne  al
005C35B0  50                               push   eax
005C35B1  8b8294000000                     mov    eax,DWORD PTR [edx+0x94]
005C35B7  ffd0                             call   eax
005C35B9  8b8ea4000000                     mov    ecx,DWORD PTR [esi+0xa4]
005C35BF  8b11                             mov    edx,DWORD PTR [ecx]
005C35C1  8b8294000000                     mov    eax,DWORD PTR [edx+0x94]
005C35C7  6a00                             push   0x0
005C35C9  ffd0                             call   eax
005C35CB  889ede000000                     mov    BYTE PTR [esi+0xde],bl
005C35D1  841d800ffc00                     test   BYTE PTR ds:0xfc0f80,bl
005C35D7  751b                             jne    0x5c35f4
005C35D9  091d800ffc00                     or     DWORD PTR ds:0xfc0f80,ebx
005C35DF  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
005C35E2  e8c978ebff                       call   0x47aeb0
005C35E7  6870dbbc00                       push   0xbcdb70
005C35EC  e829ed2c00                       call   0x89231a
005C35F1  83c404                           add    esp,0x4
005C35F4  891dbc0ffc00                     mov    DWORD PTR ds:0xfc0fbc,ebx
005C35FA  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
005C35FD  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
005C3604  59                               pop    ecx
005C3605  5e                               pop    esi
005C3606  5b                               pop    ebx
005C3607  8be5                             mov    esp,ebp
005C3609  5d                               pop    ebp
005C360A  c3                               ret

; page_show_helper 0x596e00..0x596ebf raw 0x196200
; Full helper can early return for page+F0 while caller still writes flag1.
00596E00  55                               push   ebp
00596E01  8bec                             mov    ebp,esp
00596E03  83ec0c                           sub    esp,0xc
00596E06  53                               push   ebx
00596E07  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
00596E0A  83bbf000000000                   cmp    DWORD PTR [ebx+0xf0],0x0
00596E11  56                               push   esi
00596E12  57                               push   edi
00596E13  0f859d000000                     jne    0x596eb6
00596E19  33f6                             xor    esi,esi
00596E1B  33ff                             xor    edi,edi
00596E1D  c745f8ffffffff                   mov    DWORD PTR [ebp-0x8],0xffffffff
00596E24  81c3c4000000                     add    ebx,0xc4
00596E2A  8d9b00000000                     lea    ebx,[ebx+0x0]
00596E30  8d450c                           lea    eax,[ebp+0xc]
00596E33  50                               push   eax
00596E34  8d4bfc                           lea    ecx,[ebx-0x4]
00596E37  8d45fc                           lea    eax,[ebp-0x4]
00596E3A  e8e1112b00                       call   0x848020
00596E3F  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
00596E42  3b03                             cmp    eax,DWORD PTR [ebx]
00596E44  750e                             jne    0x596e54
00596E46  47                               inc    edi
00596E47  83c310                           add    ebx,0x10
00596E4A  83ff03                           cmp    edi,0x3
00596E4D  7ce1                             jl     0x596e30
00596E4F  8b7df8                           mov    edi,DWORD PTR [ebp-0x8]
00596E52  eb03                             jmp    0x596e57
00596E54  8d7010                           lea    esi,[eax+0x10]
00596E57  8bc7                             mov    eax,edi
00596E59  83e800                           sub    eax,0x0
00596E5C  7445                             je     0x596ea3
00596E5E  48                               dec    eax
00596E5F  742c                             je     0x596e8d
00596E61  48                               dec    eax
00596E62  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
00596E65  7413                             je     0x596e7a
00596E67  8b11                             mov    edx,DWORD PTR [ecx]
00596E69  8b82d0000000                     mov    eax,DWORD PTR [edx+0xd0]
00596E6F  ffd0                             call   eax
00596E71  5f                               pop    edi
00596E72  5e                               pop    esi
00596E73  5b                               pop    ebx
00596E74  8be5                             mov    esp,ebp
00596E76  5d                               pop    ebp
00596E77  c20800                           ret    0x8
00596E7A  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
00596E7D  51                               push   ecx
00596E7E  52                               push   edx
00596E7F  e83c000000                       call   0x596ec0
00596E84  5f                               pop    edi
00596E85  5e                               pop    esi
00596E86  5b                               pop    ebx
00596E87  8be5                             mov    esp,ebp
00596E89  5d                               pop    ebp
00596E8A  c20800                           ret    0x8
00596E8D  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
00596E90  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
00596E93  50                               push   eax
00596E94  51                               push   ecx
00596E95  e826000000                       call   0x596ec0
00596E9A  5f                               pop    edi
00596E9B  5e                               pop    esi
00596E9C  5b                               pop    ebx
00596E9D  8be5                             mov    esp,ebp
00596E9F  5d                               pop    ebp
00596EA0  c20800                           ret    0x8
00596EA3  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
00596EA6  57                               push   edi
00596EA7  e8a4030000                       call   0x597250
00596EAC  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
00596EAF  52                               push   edx
00596EB0  57                               push   edi
00596EB1  e80a000000                       call   0x596ec0
00596EB6  5f                               pop    edi
00596EB7  5e                               pop    esi
00596EB8  5b                               pop    ebx
00596EB9  8be5                             mov    esp,ebp
00596EBB  5d                               pop    ebp
00596EBC  c20800                           ret    0x8

; tutorial_page_leave 0x5c3210..0x5c32ce raw 0x1c2610
; Selected leave body unregisters resources; no direct FC0FBC reset here.
005C3210  55                               push   ebp
005C3211  8bec                             mov    ebp,esp
005C3213  6aff                             push   0xffffffff
005C3215  68a02c9200                       push   0x922ca0
005C321A  64a100000000                     mov    eax,fs:0x0
005C3220  50                               push   eax
005C3221  83ec14                           sub    esp,0x14
005C3224  56                               push   esi
005C3225  a1201fd600                       mov    eax,ds:0xd61f20
005C322A  33c5                             xor    eax,ebp
005C322C  50                               push   eax
005C322D  8d45f4                           lea    eax,[ebp-0xc]
005C3230  64a300000000                     mov    fs:0x0,eax
005C3236  e85563fdff                       call   0x599590
005C323B  33f6                             xor    esi,esi
005C323D  8975e4                           mov    DWORD PTR [ebp-0x1c],esi
005C3240  8975e8                           mov    DWORD PTR [ebp-0x18],esi
005C3243  8975ec                           mov    DWORD PTR [ebp-0x14],esi
005C3246  c745e00c92c100                   mov    DWORD PTR [ebp-0x20],0xc1920c
005C324D  393570fcf700                     cmp    DWORD PTR ds:0xf7fc70,esi
005C3253  7406                             je     0x5c325b
005C3255  893570fcf700                     mov    DWORD PTR ds:0xf7fc70,esi
005C325B  6a54                             push   0x54
005C325D  8d4de0                           lea    ecx,[ebp-0x20]
005C3260  c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
005C3267  e87463e4ff                       call   0x4095e0
005C326C  6a57                             push   0x57
005C326E  8d4de0                           lea    ecx,[ebp-0x20]
005C3271  e86a63e4ff                       call   0x4095e0
005C3276  6a10                             push   0x10
005C3278  8d4de0                           lea    ecx,[ebp-0x20]
005C327B  e86063e4ff                       call   0x4095e0
005C3280  681d010000                       push   0x11d
005C3285  8d4de0                           lea    ecx,[ebp-0x20]
005C3288  e85363e4ff                       call   0x4095e0
005C328D  68d3000000                       push   0xd3
005C3292  8d4de0                           lea    ecx,[ebp-0x20]
005C3295  e84663e4ff                       call   0x4095e0
005C329A  681b010000                       push   0x11b
005C329F  8d4de0                           lea    ecx,[ebp-0x20]
005C32A2  e83963e4ff                       call   0x4095e0
005C32A7  8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
005C32AA  c745e0e429bf00                   mov    DWORD PTR [ebp-0x20],0xbf29e4
005C32B1  3bc6                             cmp    eax,esi
005C32B3  7409                             je     0x5c32be
005C32B5  50                               push   eax
005C32B6  e851df2c00                       call   0x89120c
005C32BB  83c404                           add    esp,0x4
005C32BE  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
005C32C1  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
005C32C8  59                               pop    ecx
005C32C9  5e                               pop    esi
005C32CA  8be5                             mov    esp,ebp
005C32CC  5d                               pop    ebp
005C32CD  c3                               ret

; page_range_dispatch 0x595d20..0x595d9d raw 0x195120
; F42D7 < event < F434A invokes page v+18C.
00595D20  55                               push   ebp
00595D21  8bec                             mov    ebp,esp
00595D23  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
00595D26  8b4210                           mov    eax,DWORD PTR [edx+0x10]
00595D29  3dd7420f00                       cmp    eax,0xf42d7
00595D2E  7616                             jbe    0x595d46
00595D30  3d4a430f00                       cmp    eax,0xf434a
00595D35  7314                             jae    0x595d4b
00595D37  8b01                             mov    eax,DWORD PTR [ecx]
00595D39  52                               push   edx
00595D3A  8b908c010000                     mov    edx,DWORD PTR [eax+0x18c]
00595D40  ffd2                             call   edx
00595D42  5d                               pop    ebp
00595D43  c20400                           ret    0x4
00595D46  3d4a430f00                       cmp    eax,0xf434a
00595D4B  7616                             jbe    0x595d63
00595D4D  3d5c430f00                       cmp    eax,0xf435c
00595D52  730f                             jae    0x595d63
00595D54  8b01                             mov    eax,DWORD PTR [ecx]
00595D56  52                               push   edx
00595D57  8b9090010000                     mov    edx,DWORD PTR [eax+0x190]
00595D5D  ffd2                             call   edx
00595D5F  5d                               pop    ebp
00595D60  c20400                           ret    0x4
00595D63  3d40420f00                       cmp    eax,0xf4240
00595D68  7616                             jbe    0x595d80
00595D6A  3dd7420f00                       cmp    eax,0xf42d7
00595D6F  730f                             jae    0x595d80
00595D71  8b01                             mov    eax,DWORD PTR [ecx]
00595D73  52                               push   edx
00595D74  8b9094010000                     mov    edx,DWORD PTR [eax+0x194]
00595D7A  ffd2                             call   edx
00595D7C  5d                               pop    ebp
00595D7D  c20400                           ret    0x4
00595D80  3d5c430f00                       cmp    eax,0xf435c
00595D85  7612                             jbe    0x595d99
00595D87  3d42440f00                       cmp    eax,0xf4442
00595D8C  730b                             jae    0x595d99
00595D8E  8b01                             mov    eax,DWORD PTR [ecx]
00595D90  52                               push   edx
00595D91  8b9098010000                     mov    edx,DWORD PTR [eax+0x198]
00595D97  ffd2                             call   edx
00595D99  5d                               pop    ebp
00595D9A  c20400                           ret    0x4

; q_register_WalkObject 0x566e20..0x566eb9 raw 0x166220
; Actual Q registrar WalkObject
00566E20  55                               push   ebp
00566E21  8bec                             mov    ebp,esp
00566E23  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566E26  53                               push   ebx
00566E27  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
00566E2D  56                               push   esi
00566E2E  8b33                             mov    esi,DWORD PTR [ebx]
00566E30  57                               push   edi
00566E31  8b38                             mov    edi,DWORD PTR [eax]
00566E33  b8eed8ffff                       mov    eax,0xffffd8ee
00566E38  c705dc27fe0030335600             mov    DWORD PTR ds:0xfe27dc,0x563330
00566E42  e839e81800                       call   0x6f5680
00566E47  8b03                             mov    eax,DWORD PTR [ebx]
00566E49  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00566E4C  83e810                           sub    eax,0x10
00566E4F  3dc8bfc000                       cmp    eax,0xc0bfc8
00566E54  7406                             je     0x566e5c
00566E56  83780805                         cmp    DWORD PTR [eax+0x8],0x5
00566E5A  7414                             je     0x566e70
00566E5C  57                               push   edi
00566E5D  68c426c400                       push   0xc426c4
00566E62  e856c23200                       call   0x8930bd
00566E67  8b1b                             mov    ebx,DWORD PTR [ebx]
00566E69  83c408                           add    esp,0x8
00566E6C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
00566E70  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
00566E76  8b37                             mov    esi,DWORD PTR [edi]
00566E78  68bca3d600                       push   0xd6a3bc
00566E7D  e88ee61800                       call   0x6f5510
00566E82  8b37                             mov    esi,DWORD PTR [edi]
00566E84  83c404                           add    esp,0x4
00566E87  6a00                             push   0x0
00566E89  6840935600                       push   0x569340
00566E8E  e81de71800                       call   0x6f55b0
00566E93  8b0f                             mov    ecx,DWORD PTR [edi]
00566E95  51                               push   ecx
00566E96  b8fdffffff                       mov    eax,0xfffffffd
00566E9B  e850e91800                       call   0x6f57f0
00566EA0  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
00566EA6  8b02                             mov    eax,DWORD PTR [edx]
00566EA8  83c40c                           add    esp,0xc
00566EAB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
00566EAF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566EB2  5f                               pop    edi
00566EB3  5e                               pop    esi
00566EB4  5b                               pop    ebx
00566EB5  5d                               pop    ebp
00566EB6  c20400                           ret    0x4

; q_call_register_WalkObject 0x5606a6..0x5606ab raw 0x15faa6
; Actual registrar caller in Q chain.
005606A6  e875670000                       call   0x566e20

; str_Q_WalkObject 0xd6a3bc..0xd6a3c7 raw 0x967bbc
; Original Lua API name.
; hex 57616c6b4f626a65637400

; q_register_WarpObject 0x566ec0..0x566f59 raw 0x1662c0
; Actual Q registrar WarpObject
00566EC0  55                               push   ebp
00566EC1  8bec                             mov    ebp,esp
00566EC3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566EC6  53                               push   ebx
00566EC7  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
00566ECD  56                               push   esi
00566ECE  8b33                             mov    esi,DWORD PTR [ebx]
00566ED0  57                               push   edi
00566ED1  8b38                             mov    edi,DWORD PTR [eax]
00566ED3  b8eed8ffff                       mov    eax,0xffffd8ee
00566ED8  c705e027fe00b0335600             mov    DWORD PTR ds:0xfe27e0,0x5633b0
00566EE2  e899e71800                       call   0x6f5680
00566EE7  8b03                             mov    eax,DWORD PTR [ebx]
00566EE9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00566EEC  83e810                           sub    eax,0x10
00566EEF  3dc8bfc000                       cmp    eax,0xc0bfc8
00566EF4  7406                             je     0x566efc
00566EF6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
00566EFA  7414                             je     0x566f10
00566EFC  57                               push   edi
00566EFD  68c426c400                       push   0xc426c4
00566F02  e8b6c13200                       call   0x8930bd
00566F07  8b1b                             mov    ebx,DWORD PTR [ebx]
00566F09  83c408                           add    esp,0x8
00566F0C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
00566F10  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
00566F16  8b37                             mov    esi,DWORD PTR [edi]
00566F18  68c8a3d600                       push   0xd6a3c8
00566F1D  e8eee51800                       call   0x6f5510
00566F22  8b37                             mov    esi,DWORD PTR [edi]
00566F24  83c404                           add    esp,0x4
00566F27  6a00                             push   0x0
00566F29  68a0935600                       push   0x5693a0
00566F2E  e87de61800                       call   0x6f55b0
00566F33  8b0f                             mov    ecx,DWORD PTR [edi]
00566F35  51                               push   ecx
00566F36  b8fdffffff                       mov    eax,0xfffffffd
00566F3B  e8b0e81800                       call   0x6f57f0
00566F40  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
00566F46  8b02                             mov    eax,DWORD PTR [edx]
00566F48  83c40c                           add    esp,0xc
00566F4B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
00566F4F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00566F52  5f                               pop    edi
00566F53  5e                               pop    esi
00566F54  5b                               pop    ebx
00566F55  5d                               pop    ebp
00566F56  c20400                           ret    0x4

; q_call_register_WarpObject 0x5606ac..0x5606b1 raw 0x15faac
; Actual registrar caller in Q chain.
005606AC  e80f680000                       call   0x566ec0

; str_Q_WarpObject 0xd6a3c8..0xd6a3d3 raw 0x967bc8
; Original Lua API name.
; hex 576172704f626a65637400

; q_register_StopObject 0x567280..0x567319 raw 0x166680
; Actual Q registrar StopObject
00567280  55                               push   ebp
00567281  8bec                             mov    ebp,esp
00567283  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00567286  53                               push   ebx
00567287  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0056728D  56                               push   esi
0056728E  8b33                             mov    esi,DWORD PTR [ebx]
00567290  57                               push   edi
00567291  8b38                             mov    edi,DWORD PTR [eax]
00567293  b8eed8ffff                       mov    eax,0xffffd8ee
00567298  c705f827fe00e0375600             mov    DWORD PTR ds:0xfe27f8,0x5637e0
005672A2  e8d9e31800                       call   0x6f5680
005672A7  8b03                             mov    eax,DWORD PTR [ebx]
005672A9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
005672AC  83e810                           sub    eax,0x10
005672AF  3dc8bfc000                       cmp    eax,0xc0bfc8
005672B4  7406                             je     0x5672bc
005672B6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
005672BA  7414                             je     0x5672d0
005672BC  57                               push   edi
005672BD  68c426c400                       push   0xc426c4
005672C2  e8f6bd3200                       call   0x8930bd
005672C7  8b1b                             mov    ebx,DWORD PTR [ebx]
005672C9  83c408                           add    esp,0x8
005672CC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
005672D0  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
005672D6  8b37                             mov    esi,DWORD PTR [edi]
005672D8  6810a4d600                       push   0xd6a410
005672DD  e82ee21800                       call   0x6f5510
005672E2  8b37                             mov    esi,DWORD PTR [edi]
005672E4  83c404                           add    esp,0x4
005672E7  6a00                             push   0x0
005672E9  68e0955600                       push   0x5695e0
005672EE  e8bde21800                       call   0x6f55b0
005672F3  8b0f                             mov    ecx,DWORD PTR [edi]
005672F5  51                               push   ecx
005672F6  b8fdffffff                       mov    eax,0xfffffffd
005672FB  e8f0e41800                       call   0x6f57f0
00567300  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
00567306  8b02                             mov    eax,DWORD PTR [edx]
00567308  83c40c                           add    esp,0xc
0056730B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0056730F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00567312  5f                               pop    edi
00567313  5e                               pop    esi
00567314  5b                               pop    ebx
00567315  5d                               pop    ebp
00567316  c20400                           ret    0x4

; q_call_register_StopObject 0x5606d0..0x5606d5 raw 0x15fad0
; Actual registrar caller in Q chain.
005606D0  e8ab6b0000                       call   0x567280

; str_Q_StopObject 0xd6a410..0xd6a41b raw 0x967c10
; Original Lua API name.
; hex 53746f704f626a65637400

; q_register_IsAllObjectsStopped 0x567780..0x567819 raw 0x166b80
; Actual Q registrar IsAllObjectsStopped
00567780  55                               push   ebp
00567781  8bec                             mov    ebp,esp
00567783  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00567786  53                               push   ebx
00567787  8b1d7427fe00                     mov    ebx,DWORD PTR ds:0xfe2774
0056778D  56                               push   esi
0056778E  8b33                             mov    esi,DWORD PTR [ebx]
00567790  57                               push   edi
00567791  8b38                             mov    edi,DWORD PTR [eax]
00567793  b8eed8ffff                       mov    eax,0xffffd8ee
00567798  c7051828fe0080485600             mov    DWORD PTR ds:0xfe2818,0x564880
005677A2  e8d9de1800                       call   0x6f5680
005677A7  8b03                             mov    eax,DWORD PTR [ebx]
005677A9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
005677AC  83e810                           sub    eax,0x10
005677AF  3dc8bfc000                       cmp    eax,0xc0bfc8
005677B4  7406                             je     0x5677bc
005677B6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
005677BA  7414                             je     0x5677d0
005677BC  57                               push   edi
005677BD  68c426c400                       push   0xc426c4
005677C2  e8f6b83200                       call   0x8930bd
005677C7  8b1b                             mov    ebx,DWORD PTR [ebx]
005677C9  83c408                           add    esp,0x8
005677CC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
005677D0  8b3d7427fe00                     mov    edi,DWORD PTR ds:0xfe2774
005677D6  8b37                             mov    esi,DWORD PTR [edi]
005677D8  687ca4d600                       push   0xd6a47c
005677DD  e82edd1800                       call   0x6f5510
005677E2  8b37                             mov    esi,DWORD PTR [edi]
005677E4  83c404                           add    esp,0x4
005677E7  6a00                             push   0x0
005677E9  68e0985600                       push   0x5698e0
005677EE  e8bddd1800                       call   0x6f55b0
005677F3  8b0f                             mov    ecx,DWORD PTR [edi]
005677F5  51                               push   ecx
005677F6  b8fdffffff                       mov    eax,0xfffffffd
005677FB  e8f0df1800                       call   0x6f57f0
00567800  8b157427fe00                     mov    edx,DWORD PTR ds:0xfe2774
00567806  8b02                             mov    eax,DWORD PTR [edx]
00567808  83c40c                           add    esp,0xc
0056780B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0056780F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00567812  5f                               pop    edi
00567813  5e                               pop    esi
00567814  5b                               pop    ebx
00567815  5d                               pop    ebp
00567816  c20400                           ret    0x4

; q_call_register_IsAllObjectsStopped 0x560700..0x560705 raw 0x15fb00
; Actual registrar caller in Q chain.
00560700  e87b700000                       call   0x567780

; str_Q_IsAllObjectsStopped 0xd6a47c..0xd6a490 raw 0x967c7c
; Original Lua API name.
; hex 4973416c6c4f626a6563747353746f7070656400

; tutorial_register_IsSynopsisSkipped 0x4aa680..0x4aa719 raw 0xa9a80
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AA680  55                               push   ebp
004AA681  8bec                             mov    ebp,esp
004AA683  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA686  53                               push   ebx
004AA687  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AA68D  56                               push   esi
004AA68E  8b33                             mov    esi,DWORD PTR [ebx]
004AA690  57                               push   edi
004AA691  8b38                             mov    edi,DWORD PTR [eax]
004AA693  b8eed8ffff                       mov    eax,0xffffd8ee
004AA698  c7050818fe0020934a00             mov    DWORD PTR ds:0xfe1808,0x4a9320
004AA6A2  e8d9af2400                       call   0x6f5680
004AA6A7  8b03                             mov    eax,DWORD PTR [ebx]
004AA6A9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AA6AC  83e810                           sub    eax,0x10
004AA6AF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AA6B4  7406                             je     0x4aa6bc
004AA6B6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AA6BA  7414                             je     0x4aa6d0
004AA6BC  57                               push   edi
004AA6BD  68c426c400                       push   0xc426c4
004AA6C2  e8f6893e00                       call   0x8930bd
004AA6C7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AA6C9  83c408                           add    esp,0x8
004AA6CC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AA6D0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AA6D6  8b37                             mov    esi,DWORD PTR [edi]
004AA6D8  6850abd600                       push   0xd6ab50
004AA6DD  e82eae2400                       call   0x6f5510
004AA6E2  8b37                             mov    esi,DWORD PTR [edi]
004AA6E4  83c404                           add    esp,0x4
004AA6E7  6a00                             push   0x0
004AA6E9  68a0be4a00                       push   0x4abea0
004AA6EE  e8bdae2400                       call   0x6f55b0
004AA6F3  8b0f                             mov    ecx,DWORD PTR [edi]
004AA6F5  51                               push   ecx
004AA6F6  b8fdffffff                       mov    eax,0xfffffffd
004AA6FB  e8f0b02400                       call   0x6f57f0
004AA700  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AA706  8b02                             mov    eax,DWORD PTR [edx]
004AA708  83c40c                           add    esp,0xc
004AA70B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AA70F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA712  5f                               pop    edi
004AA713  5e                               pop    esi
004AA714  5b                               pop    ebx
004AA715  5d                               pop    ebp
004AA716  c20400                           ret    0x4

; str_Tutorial_IsSynopsisSkipped 0xd6ab50..0xd6ab62 raw 0x968350
; Original Lua API name.
; hex 497353796e6f70736973536b697070656400

; tutorial_register_PlayMusic 0x4aa720..0x4aa7b9 raw 0xa9b20
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AA720  55                               push   ebp
004AA721  8bec                             mov    ebp,esp
004AA723  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA726  53                               push   ebx
004AA727  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AA72D  56                               push   esi
004AA72E  8b33                             mov    esi,DWORD PTR [ebx]
004AA730  57                               push   edi
004AA731  8b38                             mov    edi,DWORD PTR [eax]
004AA733  b8eed8ffff                       mov    eax,0xffffd8ee
004AA738  c7050c18fe0030934a00             mov    DWORD PTR ds:0xfe180c,0x4a9330
004AA742  e839af2400                       call   0x6f5680
004AA747  8b03                             mov    eax,DWORD PTR [ebx]
004AA749  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AA74C  83e810                           sub    eax,0x10
004AA74F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AA754  7406                             je     0x4aa75c
004AA756  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AA75A  7414                             je     0x4aa770
004AA75C  57                               push   edi
004AA75D  68c426c400                       push   0xc426c4
004AA762  e856893e00                       call   0x8930bd
004AA767  8b1b                             mov    ebx,DWORD PTR [ebx]
004AA769  83c408                           add    esp,0x8
004AA76C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AA770  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AA776  8b37                             mov    esi,DWORD PTR [edi]
004AA778  6864abd600                       push   0xd6ab64
004AA77D  e88ead2400                       call   0x6f5510
004AA782  8b37                             mov    esi,DWORD PTR [edi]
004AA784  83c404                           add    esp,0x4
004AA787  6a00                             push   0x0
004AA789  6810bf4a00                       push   0x4abf10
004AA78E  e81dae2400                       call   0x6f55b0
004AA793  8b0f                             mov    ecx,DWORD PTR [edi]
004AA795  51                               push   ecx
004AA796  b8fdffffff                       mov    eax,0xfffffffd
004AA79B  e850b02400                       call   0x6f57f0
004AA7A0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AA7A6  8b02                             mov    eax,DWORD PTR [edx]
004AA7A8  83c40c                           add    esp,0xc
004AA7AB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AA7AF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA7B2  5f                               pop    edi
004AA7B3  5e                               pop    esi
004AA7B4  5b                               pop    ebx
004AA7B5  5d                               pop    ebp
004AA7B6  c20400                           ret    0x4

; str_Tutorial_PlayMusic 0xd6ab64..0xd6ab6e raw 0x968364
; Original Lua API name.
; hex 506c61794d7573696300

; tutorial_register_InsertTutorialCheckPoint 0x4aa7c0..0x4aa859 raw 0xa9bc0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AA7C0  55                               push   ebp
004AA7C1  8bec                             mov    ebp,esp
004AA7C3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA7C6  53                               push   ebx
004AA7C7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AA7CD  56                               push   esi
004AA7CE  8b33                             mov    esi,DWORD PTR [ebx]
004AA7D0  57                               push   edi
004AA7D1  8b38                             mov    edi,DWORD PTR [eax]
004AA7D3  b8eed8ffff                       mov    eax,0xffffd8ee
004AA7D8  c7051018fe0030944a00             mov    DWORD PTR ds:0xfe1810,0x4a9430
004AA7E2  e899ae2400                       call   0x6f5680
004AA7E7  8b03                             mov    eax,DWORD PTR [ebx]
004AA7E9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AA7EC  83e810                           sub    eax,0x10
004AA7EF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AA7F4  7406                             je     0x4aa7fc
004AA7F6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AA7FA  7414                             je     0x4aa810
004AA7FC  57                               push   edi
004AA7FD  68c426c400                       push   0xc426c4
004AA802  e8b6883e00                       call   0x8930bd
004AA807  8b1b                             mov    ebx,DWORD PTR [ebx]
004AA809  83c408                           add    esp,0x8
004AA80C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AA810  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AA816  8b37                             mov    esi,DWORD PTR [edi]
004AA818  6870abd600                       push   0xd6ab70
004AA81D  e8eeac2400                       call   0x6f5510
004AA822  8b37                             mov    esi,DWORD PTR [edi]
004AA824  83c404                           add    esp,0x4
004AA827  6a00                             push   0x0
004AA829  6870bf4a00                       push   0x4abf70
004AA82E  e87dad2400                       call   0x6f55b0
004AA833  8b0f                             mov    ecx,DWORD PTR [edi]
004AA835  51                               push   ecx
004AA836  b8fdffffff                       mov    eax,0xfffffffd
004AA83B  e8b0af2400                       call   0x6f57f0
004AA840  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AA846  8b02                             mov    eax,DWORD PTR [edx]
004AA848  83c40c                           add    esp,0xc
004AA84B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AA84F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA852  5f                               pop    edi
004AA853  5e                               pop    esi
004AA854  5b                               pop    ebx
004AA855  5d                               pop    ebp
004AA856  c20400                           ret    0x4

; str_Tutorial_InsertTutorialCheckPoint 0xd6ab70..0xd6ab89 raw 0x968370
; Original Lua API name.
; hex 496e736572745475746f7269616c436865636b506f696e7400

; tutorial_register_SetCheckPointStatus 0x4aa860..0x4aa8f9 raw 0xa9c60
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AA860  55                               push   ebp
004AA861  8bec                             mov    ebp,esp
004AA863  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA866  53                               push   ebx
004AA867  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AA86D  56                               push   esi
004AA86E  8b33                             mov    esi,DWORD PTR [ebx]
004AA870  57                               push   edi
004AA871  8b38                             mov    edi,DWORD PTR [eax]
004AA873  b8eed8ffff                       mov    eax,0xffffd8ee
004AA878  c7051418fe0060944a00             mov    DWORD PTR ds:0xfe1814,0x4a9460
004AA882  e8f9ad2400                       call   0x6f5680
004AA887  8b03                             mov    eax,DWORD PTR [ebx]
004AA889  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AA88C  83e810                           sub    eax,0x10
004AA88F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AA894  7406                             je     0x4aa89c
004AA896  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AA89A  7414                             je     0x4aa8b0
004AA89C  57                               push   edi
004AA89D  68c426c400                       push   0xc426c4
004AA8A2  e816883e00                       call   0x8930bd
004AA8A7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AA8A9  83c408                           add    esp,0x8
004AA8AC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AA8B0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AA8B6  8b37                             mov    esi,DWORD PTR [edi]
004AA8B8  688cabd600                       push   0xd6ab8c
004AA8BD  e84eac2400                       call   0x6f5510
004AA8C2  8b37                             mov    esi,DWORD PTR [edi]
004AA8C4  83c404                           add    esp,0x4
004AA8C7  6a00                             push   0x0
004AA8C9  68d0bf4a00                       push   0x4abfd0
004AA8CE  e8ddac2400                       call   0x6f55b0
004AA8D3  8b0f                             mov    ecx,DWORD PTR [edi]
004AA8D5  51                               push   ecx
004AA8D6  b8fdffffff                       mov    eax,0xfffffffd
004AA8DB  e810af2400                       call   0x6f57f0
004AA8E0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AA8E6  8b02                             mov    eax,DWORD PTR [edx]
004AA8E8  83c40c                           add    esp,0xc
004AA8EB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AA8EF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA8F2  5f                               pop    edi
004AA8F3  5e                               pop    esi
004AA8F4  5b                               pop    ebx
004AA8F5  5d                               pop    ebp
004AA8F6  c20400                           ret    0x4

; str_Tutorial_SetCheckPointStatus 0xd6ab8c..0xd6aba0 raw 0x96838c
; Original Lua API name.
; hex 536574436865636b506f696e7453746174757300

; tutorial_register_SetKeymapEnabled 0x4aa900..0x4aa999 raw 0xa9d00
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
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

; str_Tutorial_SetKeymapEnabled 0xd6aba0..0xd6abb1 raw 0x9683a0
; Original Lua API name.
; hex 5365744b65796d6170456e61626c656400

; tutorial_register_StopCameraWorks 0x4aa9a0..0x4aaa39 raw 0xa9da0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AA9A0  55                               push   ebp
004AA9A1  8bec                             mov    ebp,esp
004AA9A3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AA9A6  53                               push   ebx
004AA9A7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AA9AD  56                               push   esi
004AA9AE  8b33                             mov    esi,DWORD PTR [ebx]
004AA9B0  57                               push   edi
004AA9B1  8b38                             mov    edi,DWORD PTR [eax]
004AA9B3  b8eed8ffff                       mov    eax,0xffffd8ee
004AA9B8  c7051c18fe0070954a00             mov    DWORD PTR ds:0xfe181c,0x4a9570
004AA9C2  e8b9ac2400                       call   0x6f5680
004AA9C7  8b03                             mov    eax,DWORD PTR [ebx]
004AA9C9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AA9CC  83e810                           sub    eax,0x10
004AA9CF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AA9D4  7406                             je     0x4aa9dc
004AA9D6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AA9DA  7414                             je     0x4aa9f0
004AA9DC  57                               push   edi
004AA9DD  68c426c400                       push   0xc426c4
004AA9E2  e8d6863e00                       call   0x8930bd
004AA9E7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AA9E9  83c408                           add    esp,0x8
004AA9EC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AA9F0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AA9F6  8b37                             mov    esi,DWORD PTR [edi]
004AA9F8  68b4abd600                       push   0xd6abb4
004AA9FD  e80eab2400                       call   0x6f5510
004AAA02  8b37                             mov    esi,DWORD PTR [edi]
004AAA04  83c404                           add    esp,0x4
004AAA07  6a00                             push   0x0
004AAA09  6890c04a00                       push   0x4ac090
004AAA0E  e89dab2400                       call   0x6f55b0
004AAA13  8b0f                             mov    ecx,DWORD PTR [edi]
004AAA15  51                               push   ecx
004AAA16  b8fdffffff                       mov    eax,0xfffffffd
004AAA1B  e8d0ad2400                       call   0x6f57f0
004AAA20  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAA26  8b02                             mov    eax,DWORD PTR [edx]
004AAA28  83c40c                           add    esp,0xc
004AAA2B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAA2F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAA32  5f                               pop    edi
004AAA33  5e                               pop    esi
004AAA34  5b                               pop    ebx
004AAA35  5d                               pop    ebp
004AAA36  c20400                           ret    0x4

; str_Tutorial_StopCameraWorks 0xd6abb4..0xd6abc4 raw 0x9683b4
; Original Lua API name.
; hex 53746f7043616d657261576f726b7300

; tutorial_register_PushCamera 0x4aaa40..0x4aaad9 raw 0xa9e40
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAA40  55                               push   ebp
004AAA41  8bec                             mov    ebp,esp
004AAA43  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAA46  53                               push   ebx
004AAA47  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAA4D  56                               push   esi
004AAA4E  8b33                             mov    esi,DWORD PTR [ebx]
004AAA50  57                               push   edi
004AAA51  8b38                             mov    edi,DWORD PTR [eax]
004AAA53  b8eed8ffff                       mov    eax,0xffffd8ee
004AAA58  c7052018fe00f0954a00             mov    DWORD PTR ds:0xfe1820,0x4a95f0
004AAA62  e819ac2400                       call   0x6f5680
004AAA67  8b03                             mov    eax,DWORD PTR [ebx]
004AAA69  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAA6C  83e810                           sub    eax,0x10
004AAA6F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AAA74  7406                             je     0x4aaa7c
004AAA76  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAA7A  7414                             je     0x4aaa90
004AAA7C  57                               push   edi
004AAA7D  68c426c400                       push   0xc426c4
004AAA82  e836863e00                       call   0x8930bd
004AAA87  8b1b                             mov    ebx,DWORD PTR [ebx]
004AAA89  83c408                           add    esp,0x8
004AAA8C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAA90  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAA96  8b37                             mov    esi,DWORD PTR [edi]
004AAA98  68c4abd600                       push   0xd6abc4
004AAA9D  e86eaa2400                       call   0x6f5510
004AAAA2  8b37                             mov    esi,DWORD PTR [edi]
004AAAA4  83c404                           add    esp,0x4
004AAAA7  6a00                             push   0x0
004AAAA9  68f0c04a00                       push   0x4ac0f0
004AAAAE  e8fdaa2400                       call   0x6f55b0
004AAAB3  8b0f                             mov    ecx,DWORD PTR [edi]
004AAAB5  51                               push   ecx
004AAAB6  b8fdffffff                       mov    eax,0xfffffffd
004AAABB  e830ad2400                       call   0x6f57f0
004AAAC0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAAC6  8b02                             mov    eax,DWORD PTR [edx]
004AAAC8  83c40c                           add    esp,0xc
004AAACB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAACF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAAD2  5f                               pop    edi
004AAAD3  5e                               pop    esi
004AAAD4  5b                               pop    ebx
004AAAD5  5d                               pop    ebp
004AAAD6  c20400                           ret    0x4

; str_Tutorial_PushCamera 0xd6abc4..0xd6abcf raw 0x9683c4
; Original Lua API name.
; hex 5075736843616d65726100

; tutorial_register_PopCamera 0x4aaae0..0x4aab79 raw 0xa9ee0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAAE0  55                               push   ebp
004AAAE1  8bec                             mov    ebp,esp
004AAAE3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAAE6  53                               push   ebx
004AAAE7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAAED  56                               push   esi
004AAAEE  8b33                             mov    esi,DWORD PTR [ebx]
004AAAF0  57                               push   edi
004AAAF1  8b38                             mov    edi,DWORD PTR [eax]
004AAAF3  b8eed8ffff                       mov    eax,0xffffd8ee
004AAAF8  c7052418fe00a0964a00             mov    DWORD PTR ds:0xfe1824,0x4a96a0
004AAB02  e879ab2400                       call   0x6f5680
004AAB07  8b03                             mov    eax,DWORD PTR [ebx]
004AAB09  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAB0C  83e810                           sub    eax,0x10
004AAB0F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AAB14  7406                             je     0x4aab1c
004AAB16  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAB1A  7414                             je     0x4aab30
004AAB1C  57                               push   edi
004AAB1D  68c426c400                       push   0xc426c4
004AAB22  e896853e00                       call   0x8930bd
004AAB27  8b1b                             mov    ebx,DWORD PTR [ebx]
004AAB29  83c408                           add    esp,0x8
004AAB2C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAB30  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAB36  8b37                             mov    esi,DWORD PTR [edi]
004AAB38  68d0abd600                       push   0xd6abd0
004AAB3D  e8cea92400                       call   0x6f5510
004AAB42  8b37                             mov    esi,DWORD PTR [edi]
004AAB44  83c404                           add    esp,0x4
004AAB47  6a00                             push   0x0
004AAB49  6850c14a00                       push   0x4ac150
004AAB4E  e85daa2400                       call   0x6f55b0
004AAB53  8b0f                             mov    ecx,DWORD PTR [edi]
004AAB55  51                               push   ecx
004AAB56  b8fdffffff                       mov    eax,0xfffffffd
004AAB5B  e890ac2400                       call   0x6f57f0
004AAB60  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAB66  8b02                             mov    eax,DWORD PTR [edx]
004AAB68  83c40c                           add    esp,0xc
004AAB6B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAB6F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAB72  5f                               pop    edi
004AAB73  5e                               pop    esi
004AAB74  5b                               pop    ebx
004AAB75  5d                               pop    ebp
004AAB76  c20400                           ret    0x4

; str_Tutorial_PopCamera 0xd6abd0..0xd6abda raw 0x9683d0
; Original Lua API name.
; hex 506f7043616d65726100

; tutorial_register_ApplyDefaultCamera 0x4aab80..0x4aac19 raw 0xa9f80
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAB80  55                               push   ebp
004AAB81  8bec                             mov    ebp,esp
004AAB83  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAB86  53                               push   ebx
004AAB87  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAB8D  56                               push   esi
004AAB8E  8b33                             mov    esi,DWORD PTR [ebx]
004AAB90  57                               push   edi
004AAB91  8b38                             mov    edi,DWORD PTR [eax]
004AAB93  b8eed8ffff                       mov    eax,0xffffd8ee
004AAB98  c7052818fe0020974a00             mov    DWORD PTR ds:0xfe1828,0x4a9720
004AABA2  e8d9aa2400                       call   0x6f5680
004AABA7  8b03                             mov    eax,DWORD PTR [ebx]
004AABA9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AABAC  83e810                           sub    eax,0x10
004AABAF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AABB4  7406                             je     0x4aabbc
004AABB6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AABBA  7414                             je     0x4aabd0
004AABBC  57                               push   edi
004AABBD  68c426c400                       push   0xc426c4
004AABC2  e8f6843e00                       call   0x8930bd
004AABC7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AABC9  83c408                           add    esp,0x8
004AABCC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AABD0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AABD6  8b37                             mov    esi,DWORD PTR [edi]
004AABD8  68dcabd600                       push   0xd6abdc
004AABDD  e82ea92400                       call   0x6f5510
004AABE2  8b37                             mov    esi,DWORD PTR [edi]
004AABE4  83c404                           add    esp,0x4
004AABE7  6a00                             push   0x0
004AABE9  68b0c14a00                       push   0x4ac1b0
004AABEE  e8bda92400                       call   0x6f55b0
004AABF3  8b0f                             mov    ecx,DWORD PTR [edi]
004AABF5  51                               push   ecx
004AABF6  b8fdffffff                       mov    eax,0xfffffffd
004AABFB  e8f0ab2400                       call   0x6f57f0
004AAC00  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAC06  8b02                             mov    eax,DWORD PTR [edx]
004AAC08  83c40c                           add    esp,0xc
004AAC0B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAC0F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAC12  5f                               pop    edi
004AAC13  5e                               pop    esi
004AAC14  5b                               pop    ebx
004AAC15  5d                               pop    ebp
004AAC16  c20400                           ret    0x4

; str_Tutorial_ApplyDefaultCamera 0xd6abdc..0xd6abef raw 0x9683dc
; Original Lua API name.
; hex 4170706c7944656661756c7443616d65726100

; tutorial_register_StartCutScene 0x4aac20..0x4aacb9 raw 0xaa020
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAC20  55                               push   ebp
004AAC21  8bec                             mov    ebp,esp
004AAC23  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAC26  53                               push   ebx
004AAC27  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAC2D  56                               push   esi
004AAC2E  8b33                             mov    esi,DWORD PTR [ebx]
004AAC30  57                               push   edi
004AAC31  8b38                             mov    edi,DWORD PTR [eax]
004AAC33  b8eed8ffff                       mov    eax,0xffffd8ee
004AAC38  c7052c18fe0030974a00             mov    DWORD PTR ds:0xfe182c,0x4a9730
004AAC42  e839aa2400                       call   0x6f5680
004AAC47  8b03                             mov    eax,DWORD PTR [ebx]
004AAC49  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAC4C  83e810                           sub    eax,0x10
004AAC4F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AAC54  7406                             je     0x4aac5c
004AAC56  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAC5A  7414                             je     0x4aac70
004AAC5C  57                               push   edi
004AAC5D  68c426c400                       push   0xc426c4
004AAC62  e856843e00                       call   0x8930bd
004AAC67  8b1b                             mov    ebx,DWORD PTR [ebx]
004AAC69  83c408                           add    esp,0x8
004AAC6C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAC70  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAC76  8b37                             mov    esi,DWORD PTR [edi]
004AAC78  68f0abd600                       push   0xd6abf0
004AAC7D  e88ea82400                       call   0x6f5510
004AAC82  8b37                             mov    esi,DWORD PTR [edi]
004AAC84  83c404                           add    esp,0x4
004AAC87  6a00                             push   0x0
004AAC89  6810c24a00                       push   0x4ac210
004AAC8E  e81da92400                       call   0x6f55b0
004AAC93  8b0f                             mov    ecx,DWORD PTR [edi]
004AAC95  51                               push   ecx
004AAC96  b8fdffffff                       mov    eax,0xfffffffd
004AAC9B  e850ab2400                       call   0x6f57f0
004AACA0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AACA6  8b02                             mov    eax,DWORD PTR [edx]
004AACA8  83c40c                           add    esp,0xc
004AACAB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AACAF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AACB2  5f                               pop    edi
004AACB3  5e                               pop    esi
004AACB4  5b                               pop    ebx
004AACB5  5d                               pop    ebp
004AACB6  c20400                           ret    0x4

; str_Tutorial_StartCutScene 0xd6abf0..0xd6abfe raw 0x9683f0
; Original Lua API name.
; hex 53746172744375745363656e6500

; tutorial_register_IsCutSceneRunning 0x4aacc0..0x4aad59 raw 0xaa0c0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AACC0  55                               push   ebp
004AACC1  8bec                             mov    ebp,esp
004AACC3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AACC6  53                               push   ebx
004AACC7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AACCD  56                               push   esi
004AACCE  8b33                             mov    esi,DWORD PTR [ebx]
004AACD0  57                               push   edi
004AACD1  8b38                             mov    edi,DWORD PTR [eax]
004AACD3  b8eed8ffff                       mov    eax,0xffffd8ee
004AACD8  c7053018fe00b0974a00             mov    DWORD PTR ds:0xfe1830,0x4a97b0
004AACE2  e899a92400                       call   0x6f5680
004AACE7  8b03                             mov    eax,DWORD PTR [ebx]
004AACE9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AACEC  83e810                           sub    eax,0x10
004AACEF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AACF4  7406                             je     0x4aacfc
004AACF6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AACFA  7414                             je     0x4aad10
004AACFC  57                               push   edi
004AACFD  68c426c400                       push   0xc426c4
004AAD02  e8b6833e00                       call   0x8930bd
004AAD07  8b1b                             mov    ebx,DWORD PTR [ebx]
004AAD09  83c408                           add    esp,0x8
004AAD0C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAD10  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAD16  8b37                             mov    esi,DWORD PTR [edi]
004AAD18  6800acd600                       push   0xd6ac00
004AAD1D  e8eea72400                       call   0x6f5510
004AAD22  8b37                             mov    esi,DWORD PTR [edi]
004AAD24  83c404                           add    esp,0x4
004AAD27  6a00                             push   0x0
004AAD29  6870c24a00                       push   0x4ac270
004AAD2E  e87da82400                       call   0x6f55b0
004AAD33  8b0f                             mov    ecx,DWORD PTR [edi]
004AAD35  51                               push   ecx
004AAD36  b8fdffffff                       mov    eax,0xfffffffd
004AAD3B  e8b0aa2400                       call   0x6f57f0
004AAD40  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAD46  8b02                             mov    eax,DWORD PTR [edx]
004AAD48  83c40c                           add    esp,0xc
004AAD4B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAD4F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAD52  5f                               pop    edi
004AAD53  5e                               pop    esi
004AAD54  5b                               pop    ebx
004AAD55  5d                               pop    ebp
004AAD56  c20400                           ret    0x4

; str_Tutorial_IsCutSceneRunning 0xd6ac00..0xd6ac12 raw 0x968400
; Original Lua API name.
; hex 49734375745363656e6552756e6e696e6700

; tutorial_register_StopCutScene 0x4aad60..0x4aadf9 raw 0xaa160
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAD60  55                               push   ebp
004AAD61  8bec                             mov    ebp,esp
004AAD63  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAD66  53                               push   ebx
004AAD67  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAD6D  56                               push   esi
004AAD6E  8b33                             mov    esi,DWORD PTR [ebx]
004AAD70  57                               push   edi
004AAD71  8b38                             mov    edi,DWORD PTR [eax]
004AAD73  b8eed8ffff                       mov    eax,0xffffd8ee
004AAD78  c7053418fe0020984a00             mov    DWORD PTR ds:0xfe1834,0x4a9820
004AAD82  e8f9a82400                       call   0x6f5680
004AAD87  8b03                             mov    eax,DWORD PTR [ebx]
004AAD89  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAD8C  83e810                           sub    eax,0x10
004AAD8F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AAD94  7406                             je     0x4aad9c
004AAD96  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAD9A  7414                             je     0x4aadb0
004AAD9C  57                               push   edi
004AAD9D  68c426c400                       push   0xc426c4
004AADA2  e816833e00                       call   0x8930bd
004AADA7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AADA9  83c408                           add    esp,0x8
004AADAC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AADB0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AADB6  8b37                             mov    esi,DWORD PTR [edi]
004AADB8  6814acd600                       push   0xd6ac14
004AADBD  e84ea72400                       call   0x6f5510
004AADC2  8b37                             mov    esi,DWORD PTR [edi]
004AADC4  83c404                           add    esp,0x4
004AADC7  6a00                             push   0x0
004AADC9  68e0c24a00                       push   0x4ac2e0
004AADCE  e8dda72400                       call   0x6f55b0
004AADD3  8b0f                             mov    ecx,DWORD PTR [edi]
004AADD5  51                               push   ecx
004AADD6  b8fdffffff                       mov    eax,0xfffffffd
004AADDB  e810aa2400                       call   0x6f57f0
004AADE0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AADE6  8b02                             mov    eax,DWORD PTR [edx]
004AADE8  83c40c                           add    esp,0xc
004AADEB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AADEF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AADF2  5f                               pop    edi
004AADF3  5e                               pop    esi
004AADF4  5b                               pop    ebx
004AADF5  5d                               pop    ebp
004AADF6  c20400                           ret    0x4

; str_Tutorial_StopCutScene 0xd6ac14..0xd6ac21 raw 0x968414
; Original Lua API name.
; hex 53746f704375745363656e6500

; tutorial_register_PostUIMessage_EmployChar 0x4aae00..0x4aae99 raw 0xaa200
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAE00  55                               push   ebp
004AAE01  8bec                             mov    ebp,esp
004AAE03  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAE06  53                               push   ebx
004AAE07  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAE0D  56                               push   esi
004AAE0E  8b33                             mov    esi,DWORD PTR [ebx]
004AAE10  57                               push   edi
004AAE11  8b38                             mov    edi,DWORD PTR [eax]
004AAE13  b8eed8ffff                       mov    eax,0xffffd8ee
004AAE18  c7053818fe00d0984a00             mov    DWORD PTR ds:0xfe1838,0x4a98d0
004AAE22  e859a82400                       call   0x6f5680
004AAE27  8b03                             mov    eax,DWORD PTR [ebx]
004AAE29  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAE2C  83e810                           sub    eax,0x10
004AAE2F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AAE34  7406                             je     0x4aae3c
004AAE36  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAE3A  7414                             je     0x4aae50
004AAE3C  57                               push   edi
004AAE3D  68c426c400                       push   0xc426c4
004AAE42  e876823e00                       call   0x8930bd
004AAE47  8b1b                             mov    ebx,DWORD PTR [ebx]
004AAE49  83c408                           add    esp,0x8
004AAE4C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAE50  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAE56  8b37                             mov    esi,DWORD PTR [edi]
004AAE58  6824acd600                       push   0xd6ac24
004AAE5D  e8aea62400                       call   0x6f5510
004AAE62  8b37                             mov    esi,DWORD PTR [edi]
004AAE64  83c404                           add    esp,0x4
004AAE67  6a00                             push   0x0
004AAE69  6840c34a00                       push   0x4ac340
004AAE6E  e83da72400                       call   0x6f55b0
004AAE73  8b0f                             mov    ecx,DWORD PTR [edi]
004AAE75  51                               push   ecx
004AAE76  b8fdffffff                       mov    eax,0xfffffffd
004AAE7B  e870a92400                       call   0x6f57f0
004AAE80  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAE86  8b02                             mov    eax,DWORD PTR [edx]
004AAE88  83c40c                           add    esp,0xc
004AAE8B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAE8F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAE92  5f                               pop    edi
004AAE93  5e                               pop    esi
004AAE94  5b                               pop    ebx
004AAE95  5d                               pop    ebp
004AAE96  c20400                           ret    0x4

; str_Tutorial_PostUIMessage_EmployChar 0xd6ac24..0xd6ac3d raw 0x968424
; Original Lua API name.
; hex 506f737455494d6573736167655f456d706c6f794368617200

; tutorial_register_PostUIMessage_TutoMsg 0x4aaea0..0x4aaf39 raw 0xaa2a0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAEA0  55                               push   ebp
004AAEA1  8bec                             mov    ebp,esp
004AAEA3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAEA6  53                               push   ebx
004AAEA7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAEAD  56                               push   esi
004AAEAE  8b33                             mov    esi,DWORD PTR [ebx]
004AAEB0  57                               push   edi
004AAEB1  8b38                             mov    edi,DWORD PTR [eax]
004AAEB3  b8eed8ffff                       mov    eax,0xffffd8ee
004AAEB8  c7053c18fe0050994a00             mov    DWORD PTR ds:0xfe183c,0x4a9950
004AAEC2  e8b9a72400                       call   0x6f5680
004AAEC7  8b03                             mov    eax,DWORD PTR [ebx]
004AAEC9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAECC  83e810                           sub    eax,0x10
004AAECF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AAED4  7406                             je     0x4aaedc
004AAED6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAEDA  7414                             je     0x4aaef0
004AAEDC  57                               push   edi
004AAEDD  68c426c400                       push   0xc426c4
004AAEE2  e8d6813e00                       call   0x8930bd
004AAEE7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AAEE9  83c408                           add    esp,0x8
004AAEEC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAEF0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAEF6  8b37                             mov    esi,DWORD PTR [edi]
004AAEF8  6840acd600                       push   0xd6ac40
004AAEFD  e80ea62400                       call   0x6f5510
004AAF02  8b37                             mov    esi,DWORD PTR [edi]
004AAF04  83c404                           add    esp,0x4
004AAF07  6a00                             push   0x0
004AAF09  68a0c34a00                       push   0x4ac3a0
004AAF0E  e89da62400                       call   0x6f55b0
004AAF13  8b0f                             mov    ecx,DWORD PTR [edi]
004AAF15  51                               push   ecx
004AAF16  b8fdffffff                       mov    eax,0xfffffffd
004AAF1B  e8d0a82400                       call   0x6f57f0
004AAF20  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAF26  8b02                             mov    eax,DWORD PTR [edx]
004AAF28  83c40c                           add    esp,0xc
004AAF2B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAF2F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAF32  5f                               pop    edi
004AAF33  5e                               pop    esi
004AAF34  5b                               pop    ebx
004AAF35  5d                               pop    ebp
004AAF36  c20400                           ret    0x4

; str_Tutorial_PostUIMessage_TutoMsg 0xd6ac40..0xd6ac56 raw 0x968440
; Original Lua API name.
; hex 506f737455494d6573736167655f5475746f4d736700

; tutorial_register_HideUI 0x4aaf40..0x4aafd9 raw 0xaa340
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAF40  55                               push   ebp
004AAF41  8bec                             mov    ebp,esp
004AAF43  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAF46  53                               push   ebx
004AAF47  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAF4D  56                               push   esi
004AAF4E  8b33                             mov    esi,DWORD PTR [ebx]
004AAF50  57                               push   edi
004AAF51  8b38                             mov    edi,DWORD PTR [eax]
004AAF53  b8eed8ffff                       mov    eax,0xffffd8ee
004AAF58  c7054018fe00d0994a00             mov    DWORD PTR ds:0xfe1840,0x4a99d0
004AAF62  e819a72400                       call   0x6f5680
004AAF67  8b03                             mov    eax,DWORD PTR [ebx]
004AAF69  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAF6C  83e810                           sub    eax,0x10
004AAF6F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AAF74  7406                             je     0x4aaf7c
004AAF76  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAF7A  7414                             je     0x4aaf90
004AAF7C  57                               push   edi
004AAF7D  68c426c400                       push   0xc426c4
004AAF82  e836813e00                       call   0x8930bd
004AAF87  8b1b                             mov    ebx,DWORD PTR [ebx]
004AAF89  83c408                           add    esp,0x8
004AAF8C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAF90  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAF96  8b37                             mov    esi,DWORD PTR [edi]
004AAF98  6858acd600                       push   0xd6ac58
004AAF9D  e86ea52400                       call   0x6f5510
004AAFA2  8b37                             mov    esi,DWORD PTR [edi]
004AAFA4  83c404                           add    esp,0x4
004AAFA7  6a00                             push   0x0
004AAFA9  6800c44a00                       push   0x4ac400
004AAFAE  e8fda52400                       call   0x6f55b0
004AAFB3  8b0f                             mov    ecx,DWORD PTR [edi]
004AAFB5  51                               push   ecx
004AAFB6  b8fdffffff                       mov    eax,0xfffffffd
004AAFBB  e830a82400                       call   0x6f57f0
004AAFC0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAFC6  8b02                             mov    eax,DWORD PTR [edx]
004AAFC8  83c40c                           add    esp,0xc
004AAFCB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAFCF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAFD2  5f                               pop    edi
004AAFD3  5e                               pop    esi
004AAFD4  5b                               pop    ebx
004AAFD5  5d                               pop    ebp
004AAFD6  c20400                           ret    0x4

; str_Tutorial_HideUI 0xd6ac58..0xd6ac5f raw 0x968458
; Original Lua API name.
; hex 48696465554900

; tutorial_register_SetUIPage 0x4aafe0..0x4ab079 raw 0xaa3e0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AAFE0  55                               push   ebp
004AAFE1  8bec                             mov    ebp,esp
004AAFE3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAFE6  53                               push   ebx
004AAFE7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAFED  56                               push   esi
004AAFEE  8b33                             mov    esi,DWORD PTR [ebx]
004AAFF0  57                               push   edi
004AAFF1  8b38                             mov    edi,DWORD PTR [eax]
004AAFF3  b8eed8ffff                       mov    eax,0xffffd8ee
004AAFF8  c7054418fe00e09a4a00             mov    DWORD PTR ds:0xfe1844,0x4a9ae0
004AB002  e879a62400                       call   0x6f5680
004AB007  8b03                             mov    eax,DWORD PTR [ebx]
004AB009  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB00C  83e810                           sub    eax,0x10
004AB00F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB014  7406                             je     0x4ab01c
004AB016  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB01A  7414                             je     0x4ab030
004AB01C  57                               push   edi
004AB01D  68c426c400                       push   0xc426c4
004AB022  e896803e00                       call   0x8930bd
004AB027  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB029  83c408                           add    esp,0x8
004AB02C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB030  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB036  8b37                             mov    esi,DWORD PTR [edi]
004AB038  6860acd600                       push   0xd6ac60
004AB03D  e8cea42400                       call   0x6f5510
004AB042  8b37                             mov    esi,DWORD PTR [edi]
004AB044  83c404                           add    esp,0x4
004AB047  6a00                             push   0x0
004AB049  6860c44a00                       push   0x4ac460
004AB04E  e85da52400                       call   0x6f55b0
004AB053  8b0f                             mov    ecx,DWORD PTR [edi]
004AB055  51                               push   ecx
004AB056  b8fdffffff                       mov    eax,0xfffffffd
004AB05B  e890a72400                       call   0x6f57f0
004AB060  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB066  8b02                             mov    eax,DWORD PTR [edx]
004AB068  83c40c                           add    esp,0xc
004AB06B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB06F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB072  5f                               pop    edi
004AB073  5e                               pop    esi
004AB074  5b                               pop    ebx
004AB075  5d                               pop    ebp
004AB076  c20400                           ret    0x4

; str_Tutorial_SetUIPage 0xd6ac60..0xd6ac6a raw 0x968460
; Original Lua API name.
; hex 53657455495061676500

; tutorial_register_RegisterSkipMessage 0x4ab080..0x4ab119 raw 0xaa480
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB080  55                               push   ebp
004AB081  8bec                             mov    ebp,esp
004AB083  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB086  53                               push   ebx
004AB087  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB08D  56                               push   esi
004AB08E  8b33                             mov    esi,DWORD PTR [ebx]
004AB090  57                               push   edi
004AB091  8b38                             mov    edi,DWORD PTR [eax]
004AB093  b8eed8ffff                       mov    eax,0xffffd8ee
004AB098  c7054818fe00709b4a00             mov    DWORD PTR ds:0xfe1848,0x4a9b70
004AB0A2  e8d9a52400                       call   0x6f5680
004AB0A7  8b03                             mov    eax,DWORD PTR [ebx]
004AB0A9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB0AC  83e810                           sub    eax,0x10
004AB0AF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB0B4  7406                             je     0x4ab0bc
004AB0B6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB0BA  7414                             je     0x4ab0d0
004AB0BC  57                               push   edi
004AB0BD  68c426c400                       push   0xc426c4
004AB0C2  e8f67f3e00                       call   0x8930bd
004AB0C7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB0C9  83c408                           add    esp,0x8
004AB0CC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB0D0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB0D6  8b37                             mov    esi,DWORD PTR [edi]
004AB0D8  686cacd600                       push   0xd6ac6c
004AB0DD  e82ea42400                       call   0x6f5510
004AB0E2  8b37                             mov    esi,DWORD PTR [edi]
004AB0E4  83c404                           add    esp,0x4
004AB0E7  6a00                             push   0x0
004AB0E9  68c0c44a00                       push   0x4ac4c0
004AB0EE  e8bda42400                       call   0x6f55b0
004AB0F3  8b0f                             mov    ecx,DWORD PTR [edi]
004AB0F5  51                               push   ecx
004AB0F6  b8fdffffff                       mov    eax,0xfffffffd
004AB0FB  e8f0a62400                       call   0x6f57f0
004AB100  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB106  8b02                             mov    eax,DWORD PTR [edx]
004AB108  83c40c                           add    esp,0xc
004AB10B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB10F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB112  5f                               pop    edi
004AB113  5e                               pop    esi
004AB114  5b                               pop    ebx
004AB115  5d                               pop    ebp
004AB116  c20400                           ret    0x4

; str_Tutorial_RegisterSkipMessage 0xd6ac6c..0xd6ac80 raw 0x96846c
; Original Lua API name.
; hex 5265676973746572536b69704d65737361676500

; tutorial_register_RegisterScalingObject 0x4ab120..0x4ab1b9 raw 0xaa520
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB120  55                               push   ebp
004AB121  8bec                             mov    ebp,esp
004AB123  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB126  53                               push   ebx
004AB127  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB12D  56                               push   esi
004AB12E  8b33                             mov    esi,DWORD PTR [ebx]
004AB130  57                               push   edi
004AB131  8b38                             mov    edi,DWORD PTR [eax]
004AB133  b8eed8ffff                       mov    eax,0xffffd8ee
004AB138  c7054c18fe00809c4a00             mov    DWORD PTR ds:0xfe184c,0x4a9c80
004AB142  e839a52400                       call   0x6f5680
004AB147  8b03                             mov    eax,DWORD PTR [ebx]
004AB149  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB14C  83e810                           sub    eax,0x10
004AB14F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB154  7406                             je     0x4ab15c
004AB156  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB15A  7414                             je     0x4ab170
004AB15C  57                               push   edi
004AB15D  68c426c400                       push   0xc426c4
004AB162  e8567f3e00                       call   0x8930bd
004AB167  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB169  83c408                           add    esp,0x8
004AB16C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB170  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB176  8b37                             mov    esi,DWORD PTR [edi]
004AB178  6880acd600                       push   0xd6ac80
004AB17D  e88ea32400                       call   0x6f5510
004AB182  8b37                             mov    esi,DWORD PTR [edi]
004AB184  83c404                           add    esp,0x4
004AB187  6a00                             push   0x0
004AB189  6820c54a00                       push   0x4ac520
004AB18E  e81da42400                       call   0x6f55b0
004AB193  8b0f                             mov    ecx,DWORD PTR [edi]
004AB195  51                               push   ecx
004AB196  b8fdffffff                       mov    eax,0xfffffffd
004AB19B  e850a62400                       call   0x6f57f0
004AB1A0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB1A6  8b02                             mov    eax,DWORD PTR [edx]
004AB1A8  83c40c                           add    esp,0xc
004AB1AB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB1AF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB1B2  5f                               pop    edi
004AB1B3  5e                               pop    esi
004AB1B4  5b                               pop    ebx
004AB1B5  5d                               pop    ebp
004AB1B6  c20400                           ret    0x4

; str_Tutorial_RegisterScalingObject 0xd6ac80..0xd6ac96 raw 0x968480
; Original Lua API name.
; hex 52656769737465725363616c696e674f626a65637400

; tutorial_register_DestroyFlyingObjects 0x4ab1c0..0x4ab259 raw 0xaa5c0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB1C0  55                               push   ebp
004AB1C1  8bec                             mov    ebp,esp
004AB1C3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB1C6  53                               push   ebx
004AB1C7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB1CD  56                               push   esi
004AB1CE  8b33                             mov    esi,DWORD PTR [ebx]
004AB1D0  57                               push   edi
004AB1D1  8b38                             mov    edi,DWORD PTR [eax]
004AB1D3  b8eed8ffff                       mov    eax,0xffffd8ee
004AB1D8  c7055018fe00b09d4a00             mov    DWORD PTR ds:0xfe1850,0x4a9db0
004AB1E2  e899a42400                       call   0x6f5680
004AB1E7  8b03                             mov    eax,DWORD PTR [ebx]
004AB1E9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB1EC  83e810                           sub    eax,0x10
004AB1EF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB1F4  7406                             je     0x4ab1fc
004AB1F6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB1FA  7414                             je     0x4ab210
004AB1FC  57                               push   edi
004AB1FD  68c426c400                       push   0xc426c4
004AB202  e8b67e3e00                       call   0x8930bd
004AB207  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB209  83c408                           add    esp,0x8
004AB20C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB210  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB216  8b37                             mov    esi,DWORD PTR [edi]
004AB218  6898acd600                       push   0xd6ac98
004AB21D  e8eea22400                       call   0x6f5510
004AB222  8b37                             mov    esi,DWORD PTR [edi]
004AB224  83c404                           add    esp,0x4
004AB227  6a00                             push   0x0
004AB229  6880c54a00                       push   0x4ac580
004AB22E  e87da32400                       call   0x6f55b0
004AB233  8b0f                             mov    ecx,DWORD PTR [edi]
004AB235  51                               push   ecx
004AB236  b8fdffffff                       mov    eax,0xfffffffd
004AB23B  e8b0a52400                       call   0x6f57f0
004AB240  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB246  8b02                             mov    eax,DWORD PTR [edx]
004AB248  83c40c                           add    esp,0xc
004AB24B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB24F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB252  5f                               pop    edi
004AB253  5e                               pop    esi
004AB254  5b                               pop    ebx
004AB255  5d                               pop    ebp
004AB256  c20400                           ret    0x4

; str_Tutorial_DestroyFlyingObjects 0xd6ac98..0xd6acad raw 0x968498
; Original Lua API name.
; hex 44657374726f79466c79696e674f626a6563747300

; tutorial_register_IsCharacterAvailable 0x4ab260..0x4ab2f9 raw 0xaa660
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB260  55                               push   ebp
004AB261  8bec                             mov    ebp,esp
004AB263  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB266  53                               push   ebx
004AB267  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB26D  56                               push   esi
004AB26E  8b33                             mov    esi,DWORD PTR [ebx]
004AB270  57                               push   edi
004AB271  8b38                             mov    edi,DWORD PTR [eax]
004AB273  b8eed8ffff                       mov    eax,0xffffd8ee
004AB278  c7055418fe00009f4a00             mov    DWORD PTR ds:0xfe1854,0x4a9f00
004AB282  e8f9a32400                       call   0x6f5680
004AB287  8b03                             mov    eax,DWORD PTR [ebx]
004AB289  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB28C  83e810                           sub    eax,0x10
004AB28F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB294  7406                             je     0x4ab29c
004AB296  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB29A  7414                             je     0x4ab2b0
004AB29C  57                               push   edi
004AB29D  68c426c400                       push   0xc426c4
004AB2A2  e8167e3e00                       call   0x8930bd
004AB2A7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB2A9  83c408                           add    esp,0x8
004AB2AC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB2B0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB2B6  8b37                             mov    esi,DWORD PTR [edi]
004AB2B8  68b0acd600                       push   0xd6acb0
004AB2BD  e84ea22400                       call   0x6f5510
004AB2C2  8b37                             mov    esi,DWORD PTR [edi]
004AB2C4  83c404                           add    esp,0x4
004AB2C7  6a00                             push   0x0
004AB2C9  68e0c54a00                       push   0x4ac5e0
004AB2CE  e8dda22400                       call   0x6f55b0
004AB2D3  8b0f                             mov    ecx,DWORD PTR [edi]
004AB2D5  51                               push   ecx
004AB2D6  b8fdffffff                       mov    eax,0xfffffffd
004AB2DB  e810a52400                       call   0x6f57f0
004AB2E0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB2E6  8b02                             mov    eax,DWORD PTR [edx]
004AB2E8  83c40c                           add    esp,0xc
004AB2EB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB2EF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB2F2  5f                               pop    edi
004AB2F3  5e                               pop    esi
004AB2F4  5b                               pop    ebx
004AB2F5  5d                               pop    ebp
004AB2F6  c20400                           ret    0x4

; str_Tutorial_IsCharacterAvailable 0xd6acb0..0xd6acc5 raw 0x9684b0
; Original Lua API name.
; hex 4973436861726163746572417661696c61626c6500

; tutorial_register_SetControlStatus 0x4ab300..0x4ab399 raw 0xaa700
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB300  55                               push   ebp
004AB301  8bec                             mov    ebp,esp
004AB303  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB306  53                               push   ebx
004AB307  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB30D  56                               push   esi
004AB30E  8b33                             mov    esi,DWORD PTR [ebx]
004AB310  57                               push   edi
004AB311  8b38                             mov    edi,DWORD PTR [eax]
004AB313  b8eed8ffff                       mov    eax,0xffffd8ee
004AB318  c7055818fe00909f4a00             mov    DWORD PTR ds:0xfe1858,0x4a9f90
004AB322  e859a32400                       call   0x6f5680
004AB327  8b03                             mov    eax,DWORD PTR [ebx]
004AB329  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB32C  83e810                           sub    eax,0x10
004AB32F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB334  7406                             je     0x4ab33c
004AB336  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB33A  7414                             je     0x4ab350
004AB33C  57                               push   edi
004AB33D  68c426c400                       push   0xc426c4
004AB342  e8767d3e00                       call   0x8930bd
004AB347  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB349  83c408                           add    esp,0x8
004AB34C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB350  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB356  8b37                             mov    esi,DWORD PTR [edi]
004AB358  68c8acd600                       push   0xd6acc8
004AB35D  e8aea12400                       call   0x6f5510
004AB362  8b37                             mov    esi,DWORD PTR [edi]
004AB364  83c404                           add    esp,0x4
004AB367  6a00                             push   0x0
004AB369  6840c64a00                       push   0x4ac640
004AB36E  e83da22400                       call   0x6f55b0
004AB373  8b0f                             mov    ecx,DWORD PTR [edi]
004AB375  51                               push   ecx
004AB376  b8fdffffff                       mov    eax,0xfffffffd
004AB37B  e870a42400                       call   0x6f57f0
004AB380  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB386  8b02                             mov    eax,DWORD PTR [edx]
004AB388  83c40c                           add    esp,0xc
004AB38B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB38F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB392  5f                               pop    edi
004AB393  5e                               pop    esi
004AB394  5b                               pop    ebx
004AB395  5d                               pop    ebp
004AB396  c20400                           ret    0x4

; str_Tutorial_SetControlStatus 0xd6acc8..0xd6acd9 raw 0x9684c8
; Original Lua API name.
; hex 536574436f6e74726f6c53746174757300

; tutorial_register_GetControlStatus 0x4ab3a0..0x4ab439 raw 0xaa7a0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB3A0  55                               push   ebp
004AB3A1  8bec                             mov    ebp,esp
004AB3A3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB3A6  53                               push   ebx
004AB3A7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB3AD  56                               push   esi
004AB3AE  8b33                             mov    esi,DWORD PTR [ebx]
004AB3B0  57                               push   edi
004AB3B1  8b38                             mov    edi,DWORD PTR [eax]
004AB3B3  b8eed8ffff                       mov    eax,0xffffd8ee
004AB3B8  c7055c18fe00b09f4a00             mov    DWORD PTR ds:0xfe185c,0x4a9fb0
004AB3C2  e8b9a22400                       call   0x6f5680
004AB3C7  8b03                             mov    eax,DWORD PTR [ebx]
004AB3C9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB3CC  83e810                           sub    eax,0x10
004AB3CF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB3D4  7406                             je     0x4ab3dc
004AB3D6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB3DA  7414                             je     0x4ab3f0
004AB3DC  57                               push   edi
004AB3DD  68c426c400                       push   0xc426c4
004AB3E2  e8d67c3e00                       call   0x8930bd
004AB3E7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB3E9  83c408                           add    esp,0x8
004AB3EC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB3F0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB3F6  8b37                             mov    esi,DWORD PTR [edi]
004AB3F8  68dcacd600                       push   0xd6acdc
004AB3FD  e80ea12400                       call   0x6f5510
004AB402  8b37                             mov    esi,DWORD PTR [edi]
004AB404  83c404                           add    esp,0x4
004AB407  6a00                             push   0x0
004AB409  68a0c64a00                       push   0x4ac6a0
004AB40E  e89da12400                       call   0x6f55b0
004AB413  8b0f                             mov    ecx,DWORD PTR [edi]
004AB415  51                               push   ecx
004AB416  b8fdffffff                       mov    eax,0xfffffffd
004AB41B  e8d0a32400                       call   0x6f57f0
004AB420  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB426  8b02                             mov    eax,DWORD PTR [edx]
004AB428  83c40c                           add    esp,0xc
004AB42B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB42F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB432  5f                               pop    edi
004AB433  5e                               pop    esi
004AB434  5b                               pop    ebx
004AB435  5d                               pop    ebp
004AB436  c20400                           ret    0x4

; str_Tutorial_GetControlStatus 0xd6acdc..0xd6aced raw 0x9684dc
; Original Lua API name.
; hex 476574436f6e74726f6c53746174757300

; tutorial_register_GetTutorialState 0x4ab440..0x4ab4d9 raw 0xaa840
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB440  55                               push   ebp
004AB441  8bec                             mov    ebp,esp
004AB443  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB446  53                               push   ebx
004AB447  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB44D  56                               push   esi
004AB44E  8b33                             mov    esi,DWORD PTR [ebx]
004AB450  57                               push   edi
004AB451  8b38                             mov    edi,DWORD PTR [eax]
004AB453  b8eed8ffff                       mov    eax,0xffffd8ee
004AB458  c7056018fe00d09f4a00             mov    DWORD PTR ds:0xfe1860,0x4a9fd0
004AB462  e819a22400                       call   0x6f5680
004AB467  8b03                             mov    eax,DWORD PTR [ebx]
004AB469  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB46C  83e810                           sub    eax,0x10
004AB46F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB474  7406                             je     0x4ab47c
004AB476  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB47A  7414                             je     0x4ab490
004AB47C  57                               push   edi
004AB47D  68c426c400                       push   0xc426c4
004AB482  e8367c3e00                       call   0x8930bd
004AB487  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB489  83c408                           add    esp,0x8
004AB48C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB490  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB496  8b37                             mov    esi,DWORD PTR [edi]
004AB498  68f0acd600                       push   0xd6acf0
004AB49D  e86ea02400                       call   0x6f5510
004AB4A2  8b37                             mov    esi,DWORD PTR [edi]
004AB4A4  83c404                           add    esp,0x4
004AB4A7  6a00                             push   0x0
004AB4A9  6800c74a00                       push   0x4ac700
004AB4AE  e8fda02400                       call   0x6f55b0
004AB4B3  8b0f                             mov    ecx,DWORD PTR [edi]
004AB4B5  51                               push   ecx
004AB4B6  b8fdffffff                       mov    eax,0xfffffffd
004AB4BB  e830a32400                       call   0x6f57f0
004AB4C0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB4C6  8b02                             mov    eax,DWORD PTR [edx]
004AB4C8  83c40c                           add    esp,0xc
004AB4CB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB4CF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB4D2  5f                               pop    edi
004AB4D3  5e                               pop    esi
004AB4D4  5b                               pop    ebx
004AB4D5  5d                               pop    ebp
004AB4D6  c20400                           ret    0x4

; str_Tutorial_GetTutorialState 0xd6acf0..0xd6ad01 raw 0x9684f0
; Original Lua API name.
; hex 4765745475746f7269616c537461746500

; tutorial_register_InsertObject 0x4ab4e0..0x4ab579 raw 0xaa8e0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB4E0  55                               push   ebp
004AB4E1  8bec                             mov    ebp,esp
004AB4E3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB4E6  53                               push   ebx
004AB4E7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB4ED  56                               push   esi
004AB4EE  8b33                             mov    esi,DWORD PTR [ebx]
004AB4F0  57                               push   edi
004AB4F1  8b38                             mov    edi,DWORD PTR [eax]
004AB4F3  b8eed8ffff                       mov    eax,0xffffd8ee
004AB4F8  c7056418fe0030644700             mov    DWORD PTR ds:0xfe1864,0x476430
004AB502  e879a12400                       call   0x6f5680
004AB507  8b03                             mov    eax,DWORD PTR [ebx]
004AB509  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB50C  83e810                           sub    eax,0x10
004AB50F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB514  7406                             je     0x4ab51c
004AB516  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB51A  7414                             je     0x4ab530
004AB51C  57                               push   edi
004AB51D  68c426c400                       push   0xc426c4
004AB522  e8967b3e00                       call   0x8930bd
004AB527  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB529  83c408                           add    esp,0x8
004AB52C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB530  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB536  8b37                             mov    esi,DWORD PTR [edi]
004AB538  6804add600                       push   0xd6ad04
004AB53D  e8ce9f2400                       call   0x6f5510
004AB542  8b37                             mov    esi,DWORD PTR [edi]
004AB544  83c404                           add    esp,0x4
004AB547  6a00                             push   0x0
004AB549  6870c74a00                       push   0x4ac770
004AB54E  e85da02400                       call   0x6f55b0
004AB553  8b0f                             mov    ecx,DWORD PTR [edi]
004AB555  51                               push   ecx
004AB556  b8fdffffff                       mov    eax,0xfffffffd
004AB55B  e890a22400                       call   0x6f57f0
004AB560  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB566  8b02                             mov    eax,DWORD PTR [edx]
004AB568  83c40c                           add    esp,0xc
004AB56B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB56F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB572  5f                               pop    edi
004AB573  5e                               pop    esi
004AB574  5b                               pop    ebx
004AB575  5d                               pop    ebp
004AB576  c20400                           ret    0x4

; str_Tutorial_InsertObject 0xd6ad04..0xd6ad11 raw 0x968504
; Original Lua API name.
; hex 496e736572744f626a65637400

; tutorial_register_DeleteObject 0x4ab580..0x4ab619 raw 0xaa980
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB580  55                               push   ebp
004AB581  8bec                             mov    ebp,esp
004AB583  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB586  53                               push   ebx
004AB587  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB58D  56                               push   esi
004AB58E  8b33                             mov    esi,DWORD PTR [ebx]
004AB590  57                               push   edi
004AB591  8b38                             mov    edi,DWORD PTR [eax]
004AB593  b8eed8ffff                       mov    eax,0xffffd8ee
004AB598  c7056818fe00e09f4a00             mov    DWORD PTR ds:0xfe1868,0x4a9fe0
004AB5A2  e8d9a02400                       call   0x6f5680
004AB5A7  8b03                             mov    eax,DWORD PTR [ebx]
004AB5A9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB5AC  83e810                           sub    eax,0x10
004AB5AF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB5B4  7406                             je     0x4ab5bc
004AB5B6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB5BA  7414                             je     0x4ab5d0
004AB5BC  57                               push   edi
004AB5BD  68c426c400                       push   0xc426c4
004AB5C2  e8f67a3e00                       call   0x8930bd
004AB5C7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB5C9  83c408                           add    esp,0x8
004AB5CC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB5D0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB5D6  8b37                             mov    esi,DWORD PTR [edi]
004AB5D8  6814add600                       push   0xd6ad14
004AB5DD  e82e9f2400                       call   0x6f5510
004AB5E2  8b37                             mov    esi,DWORD PTR [edi]
004AB5E4  83c404                           add    esp,0x4
004AB5E7  6a00                             push   0x0
004AB5E9  68d0c74a00                       push   0x4ac7d0
004AB5EE  e8bd9f2400                       call   0x6f55b0
004AB5F3  8b0f                             mov    ecx,DWORD PTR [edi]
004AB5F5  51                               push   ecx
004AB5F6  b8fdffffff                       mov    eax,0xfffffffd
004AB5FB  e8f0a12400                       call   0x6f57f0
004AB600  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB606  8b02                             mov    eax,DWORD PTR [edx]
004AB608  83c40c                           add    esp,0xc
004AB60B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB60F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB612  5f                               pop    edi
004AB613  5e                               pop    esi
004AB614  5b                               pop    ebx
004AB615  5d                               pop    ebp
004AB616  c20400                           ret    0x4

; str_Tutorial_DeleteObject 0xd6ad14..0xd6ad21 raw 0x968514
; Original Lua API name.
; hex 44656c6574654f626a65637400

; tutorial_register_InsertIsilia 0x4ab620..0x4ab6b9 raw 0xaaa20
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB620  55                               push   ebp
004AB621  8bec                             mov    ebp,esp
004AB623  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB626  53                               push   ebx
004AB627  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB62D  56                               push   esi
004AB62E  8b33                             mov    esi,DWORD PTR [ebx]
004AB630  57                               push   edi
004AB631  8b38                             mov    edi,DWORD PTR [eax]
004AB633  b8eed8ffff                       mov    eax,0xffffd8ee
004AB638  c7056c18fe0070a04a00             mov    DWORD PTR ds:0xfe186c,0x4aa070
004AB642  e839a02400                       call   0x6f5680
004AB647  8b03                             mov    eax,DWORD PTR [ebx]
004AB649  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB64C  83e810                           sub    eax,0x10
004AB64F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB654  7406                             je     0x4ab65c
004AB656  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB65A  7414                             je     0x4ab670
004AB65C  57                               push   edi
004AB65D  68c426c400                       push   0xc426c4
004AB662  e8567a3e00                       call   0x8930bd
004AB667  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB669  83c408                           add    esp,0x8
004AB66C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB670  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB676  8b37                             mov    esi,DWORD PTR [edi]
004AB678  6824add600                       push   0xd6ad24
004AB67D  e88e9e2400                       call   0x6f5510
004AB682  8b37                             mov    esi,DWORD PTR [edi]
004AB684  83c404                           add    esp,0x4
004AB687  6a00                             push   0x0
004AB689  6830c84a00                       push   0x4ac830
004AB68E  e81d9f2400                       call   0x6f55b0
004AB693  8b0f                             mov    ecx,DWORD PTR [edi]
004AB695  51                               push   ecx
004AB696  b8fdffffff                       mov    eax,0xfffffffd
004AB69B  e850a12400                       call   0x6f57f0
004AB6A0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB6A6  8b02                             mov    eax,DWORD PTR [edx]
004AB6A8  83c40c                           add    esp,0xc
004AB6AB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB6AF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB6B2  5f                               pop    edi
004AB6B3  5e                               pop    esi
004AB6B4  5b                               pop    ebx
004AB6B5  5d                               pop    ebp
004AB6B6  c20400                           ret    0x4

; str_Tutorial_InsertIsilia 0xd6ad24..0xd6ad31 raw 0x968524
; Original Lua API name.
; hex 496e736572744973696c696100

; tutorial_register_IsIsiliaFound 0x4ab6c0..0x4ab759 raw 0xaaac0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB6C0  55                               push   ebp
004AB6C1  8bec                             mov    ebp,esp
004AB6C3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB6C6  53                               push   ebx
004AB6C7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB6CD  56                               push   esi
004AB6CE  8b33                             mov    esi,DWORD PTR [ebx]
004AB6D0  57                               push   edi
004AB6D1  8b38                             mov    edi,DWORD PTR [eax]
004AB6D3  b8eed8ffff                       mov    eax,0xffffd8ee
004AB6D8  c7057018fe0040a24a00             mov    DWORD PTR ds:0xfe1870,0x4aa240
004AB6E2  e8999f2400                       call   0x6f5680
004AB6E7  8b03                             mov    eax,DWORD PTR [ebx]
004AB6E9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB6EC  83e810                           sub    eax,0x10
004AB6EF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB6F4  7406                             je     0x4ab6fc
004AB6F6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB6FA  7414                             je     0x4ab710
004AB6FC  57                               push   edi
004AB6FD  68c426c400                       push   0xc426c4
004AB702  e8b6793e00                       call   0x8930bd
004AB707  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB709  83c408                           add    esp,0x8
004AB70C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB710  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB716  8b37                             mov    esi,DWORD PTR [edi]
004AB718  6834add600                       push   0xd6ad34
004AB71D  e8ee9d2400                       call   0x6f5510
004AB722  8b37                             mov    esi,DWORD PTR [edi]
004AB724  83c404                           add    esp,0x4
004AB727  6a00                             push   0x0
004AB729  6890c84a00                       push   0x4ac890
004AB72E  e87d9e2400                       call   0x6f55b0
004AB733  8b0f                             mov    ecx,DWORD PTR [edi]
004AB735  51                               push   ecx
004AB736  b8fdffffff                       mov    eax,0xfffffffd
004AB73B  e8b0a02400                       call   0x6f57f0
004AB740  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB746  8b02                             mov    eax,DWORD PTR [edx]
004AB748  83c40c                           add    esp,0xc
004AB74B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB74F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB752  5f                               pop    edi
004AB753  5e                               pop    esi
004AB754  5b                               pop    ebx
004AB755  5d                               pop    ebp
004AB756  c20400                           ret    0x4

; str_Tutorial_IsIsiliaFound 0xd6ad34..0xd6ad42 raw 0x968534
; Original Lua API name.
; hex 49734973696c6961466f756e6400

; tutorial_register_CheckLeader 0x4ab760..0x4ab7f9 raw 0xaab60
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB760  55                               push   ebp
004AB761  8bec                             mov    ebp,esp
004AB763  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB766  53                               push   ebx
004AB767  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB76D  56                               push   esi
004AB76E  8b33                             mov    esi,DWORD PTR [ebx]
004AB770  57                               push   edi
004AB771  8b38                             mov    edi,DWORD PTR [eax]
004AB773  b8eed8ffff                       mov    eax,0xffffd8ee
004AB778  c7057418fe00a0a44a00             mov    DWORD PTR ds:0xfe1874,0x4aa4a0
004AB782  e8f99e2400                       call   0x6f5680
004AB787  8b03                             mov    eax,DWORD PTR [ebx]
004AB789  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB78C  83e810                           sub    eax,0x10
004AB78F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB794  7406                             je     0x4ab79c
004AB796  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB79A  7414                             je     0x4ab7b0
004AB79C  57                               push   edi
004AB79D  68c426c400                       push   0xc426c4
004AB7A2  e816793e00                       call   0x8930bd
004AB7A7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB7A9  83c408                           add    esp,0x8
004AB7AC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB7B0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB7B6  8b37                             mov    esi,DWORD PTR [edi]
004AB7B8  6844add600                       push   0xd6ad44
004AB7BD  e84e9d2400                       call   0x6f5510
004AB7C2  8b37                             mov    esi,DWORD PTR [edi]
004AB7C4  83c404                           add    esp,0x4
004AB7C7  6a00                             push   0x0
004AB7C9  6800c94a00                       push   0x4ac900
004AB7CE  e8dd9d2400                       call   0x6f55b0
004AB7D3  8b0f                             mov    ecx,DWORD PTR [edi]
004AB7D5  51                               push   ecx
004AB7D6  b8fdffffff                       mov    eax,0xfffffffd
004AB7DB  e810a02400                       call   0x6f57f0
004AB7E0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB7E6  8b02                             mov    eax,DWORD PTR [edx]
004AB7E8  83c40c                           add    esp,0xc
004AB7EB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB7EF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB7F2  5f                               pop    edi
004AB7F3  5e                               pop    esi
004AB7F4  5b                               pop    ebx
004AB7F5  5d                               pop    ebp
004AB7F6  c20400                           ret    0x4

; str_Tutorial_CheckLeader 0xd6ad44..0xd6ad50 raw 0x968544
; Original Lua API name.
; hex 436865636b4c656164657200

; tutorial_register_IsLeaderDialogOpened 0x4ab800..0x4ab899 raw 0xaac00
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB800  55                               push   ebp
004AB801  8bec                             mov    ebp,esp
004AB803  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB806  53                               push   ebx
004AB807  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB80D  56                               push   esi
004AB80E  8b33                             mov    esi,DWORD PTR [ebx]
004AB810  57                               push   edi
004AB811  8b38                             mov    edi,DWORD PTR [eax]
004AB813  b8eed8ffff                       mov    eax,0xffffd8ee
004AB818  c7057818fe0040e75400             mov    DWORD PTR ds:0xfe1878,0x54e740
004AB822  e8599e2400                       call   0x6f5680
004AB827  8b03                             mov    eax,DWORD PTR [ebx]
004AB829  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB82C  83e810                           sub    eax,0x10
004AB82F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB834  7406                             je     0x4ab83c
004AB836  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB83A  7414                             je     0x4ab850
004AB83C  57                               push   edi
004AB83D  68c426c400                       push   0xc426c4
004AB842  e876783e00                       call   0x8930bd
004AB847  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB849  83c408                           add    esp,0x8
004AB84C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB850  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB856  8b37                             mov    esi,DWORD PTR [edi]
004AB858  6850add600                       push   0xd6ad50
004AB85D  e8ae9c2400                       call   0x6f5510
004AB862  8b37                             mov    esi,DWORD PTR [edi]
004AB864  83c404                           add    esp,0x4
004AB867  6a00                             push   0x0
004AB869  6870c94a00                       push   0x4ac970
004AB86E  e83d9d2400                       call   0x6f55b0
004AB873  8b0f                             mov    ecx,DWORD PTR [edi]
004AB875  51                               push   ecx
004AB876  b8fdffffff                       mov    eax,0xfffffffd
004AB87B  e8709f2400                       call   0x6f57f0
004AB880  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB886  8b02                             mov    eax,DWORD PTR [edx]
004AB888  83c40c                           add    esp,0xc
004AB88B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB88F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB892  5f                               pop    edi
004AB893  5e                               pop    esi
004AB894  5b                               pop    ebx
004AB895  5d                               pop    ebp
004AB896  c20400                           ret    0x4

; str_Tutorial_IsLeaderDialogOpened 0xd6ad50..0xd6ad65 raw 0x968550
; Original Lua API name.
; hex 49734c65616465724469616c6f674f70656e656400

; tutorial_register_RequestStartScenario 0x4ab8a0..0x4ab939 raw 0xaaca0
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB8A0  55                               push   ebp
004AB8A1  8bec                             mov    ebp,esp
004AB8A3  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB8A6  53                               push   ebx
004AB8A7  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB8AD  56                               push   esi
004AB8AE  8b33                             mov    esi,DWORD PTR [ebx]
004AB8B0  57                               push   edi
004AB8B1  8b38                             mov    edi,DWORD PTR [eax]
004AB8B3  b8eed8ffff                       mov    eax,0xffffd8ee
004AB8B8  c7057c18fe00d0a44a00             mov    DWORD PTR ds:0xfe187c,0x4aa4d0
004AB8C2  e8b99d2400                       call   0x6f5680
004AB8C7  8b03                             mov    eax,DWORD PTR [ebx]
004AB8C9  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB8CC  83e810                           sub    eax,0x10
004AB8CF  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB8D4  7406                             je     0x4ab8dc
004AB8D6  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB8DA  7414                             je     0x4ab8f0
004AB8DC  57                               push   edi
004AB8DD  68c426c400                       push   0xc426c4
004AB8E2  e8d6773e00                       call   0x8930bd
004AB8E7  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB8E9  83c408                           add    esp,0x8
004AB8EC  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB8F0  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB8F6  8b37                             mov    esi,DWORD PTR [edi]
004AB8F8  6868add600                       push   0xd6ad68
004AB8FD  e80e9c2400                       call   0x6f5510
004AB902  8b37                             mov    esi,DWORD PTR [edi]
004AB904  83c404                           add    esp,0x4
004AB907  6a00                             push   0x0
004AB909  68e0c94a00                       push   0x4ac9e0
004AB90E  e89d9c2400                       call   0x6f55b0
004AB913  8b0f                             mov    ecx,DWORD PTR [edi]
004AB915  51                               push   ecx
004AB916  b8fdffffff                       mov    eax,0xfffffffd
004AB91B  e8d09e2400                       call   0x6f57f0
004AB920  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB926  8b02                             mov    eax,DWORD PTR [edx]
004AB928  83c40c                           add    esp,0xc
004AB92B  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB92F  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB932  5f                               pop    edi
004AB933  5e                               pop    esi
004AB934  5b                               pop    ebx
004AB935  5d                               pop    ebp
004AB936  c20400                           ret    0x4

; str_Tutorial_RequestStartScenario 0xd6ad68..0xd6ad7d raw 0x968568
; Original Lua API name.
; hex 5265717565737453746172745363656e6172696f00

; tutorial_register_IsScenarioEnded 0x4ab940..0x4ab9d9 raw 0xaad40
; Actual Tutorial registrar; inventory proves binding only, not full semantics.
004AB940  55                               push   ebp
004AB941  8bec                             mov    ebp,esp
004AB943  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB946  53                               push   ebx
004AB947  8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB94D  56                               push   esi
004AB94E  8b33                             mov    esi,DWORD PTR [ebx]
004AB950  57                               push   edi
004AB951  8b38                             mov    edi,DWORD PTR [eax]
004AB953  b8eed8ffff                       mov    eax,0xffffd8ee
004AB958  c7058018fe0010a54a00             mov    DWORD PTR ds:0xfe1880,0x4aa510
004AB962  e8199d2400                       call   0x6f5680
004AB967  8b03                             mov    eax,DWORD PTR [ebx]
004AB969  8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB96C  83e810                           sub    eax,0x10
004AB96F  3dc8bfc000                       cmp    eax,0xc0bfc8
004AB974  7406                             je     0x4ab97c
004AB976  83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB97A  7414                             je     0x4ab990
004AB97C  57                               push   edi
004AB97D  68c426c400                       push   0xc426c4
004AB982  e836773e00                       call   0x8930bd
004AB987  8b1b                             mov    ebx,DWORD PTR [ebx]
004AB989  83c408                           add    esp,0x8
004AB98C  834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB990  8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB996  8b37                             mov    esi,DWORD PTR [edi]
004AB998  6880add600                       push   0xd6ad80
004AB99D  e86e9b2400                       call   0x6f5510
004AB9A2  8b37                             mov    esi,DWORD PTR [edi]
004AB9A4  83c404                           add    esp,0x4
004AB9A7  6a00                             push   0x0
004AB9A9  6840ca4a00                       push   0x4aca40
004AB9AE  e8fd9b2400                       call   0x6f55b0
004AB9B3  8b0f                             mov    ecx,DWORD PTR [edi]
004AB9B5  51                               push   ecx
004AB9B6  b8fdffffff                       mov    eax,0xfffffffd
004AB9BB  e8309e2400                       call   0x6f57f0
004AB9C0  8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB9C6  8b02                             mov    eax,DWORD PTR [edx]
004AB9C8  83c40c                           add    esp,0xc
004AB9CB  834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB9CF  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB9D2  5f                               pop    edi
004AB9D3  5e                               pop    esi
004AB9D4  5b                               pop    ebx
004AB9D5  5d                               pop    ebp
004AB9D6  c20400                           ret    0x4

; str_Tutorial_IsScenarioEnded 0xd6ad80..0xd6ad90 raw 0x968580
; Original Lua API name.
; hex 49735363656e6172696f456e64656400

; CEventActor_vtable 0xc0c820..0xc0c890 raw 0x80ae20
; Original COL pointer and selected vtable extent.
; hex acabc600a00c4d00105d5f0080a84c00f0c28d0040824c0060834c00f0c28d00f0c28d00800f4d00a00f4d00c00f4d0070a84c0050804c0060804c0030ab4c00b06f4c00d06f4c00908b4c00e08b4c00908f4c00a08f4c00100f4d00308c4c00408c4c00500f4d0080844c00a08d4c00

; CEventActor_COL 0xc6abac..0xc6abc0 raw 0x8691ac
; MSVC complete object locator.
; hex 00000000000000000000000038e8f700c0abc600

; CEventActor_type 0xf7e838..0xf7e852 raw 0xb7c038
; Original RTTI type descriptor.
; hex f435bd00000000002e3f4156434576656e744163746f72404000

; CTutorialPage_vtable 0xc1f5f0..0xc1f790 raw 0x81dbf0
; Original COL pointer and selected vtable extent.
; hex e017c700203f4200103f4200103f4200003f4200e03d4000408c74006094740020ea5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550050375c00e0674000d0877400f08774001088740010887400105d5f0040305c0010325c0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900b0395c00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900b0335c00806b5900d0325c0050335c0060335c0070335c00

; CTutorialPage_COL 0xc717e0..0xc717f4 raw 0x86fde0
; MSVC complete object locator.
; hex 000000000000000000000000c82ef800f417c700

; CTutorialPage_type 0xf82ec8..0xf82ee8 raw 0xb806c8
; Original RTTI type descriptor.
; hex f435bd00000000002e3f4156435475746f7269616c5061676540465549404000

; CTutorialController_vtable 0xc0fb18..0xc0fb40 raw 0x80e118
; Original COL pointer and selected vtable extent.
; hex f8c6c600808c540040505400d0515400105d5f00105d5f0010525400b03d400090525400b0525400

; CTutorialController_COL 0xc6c6f8..0xc6c70c raw 0x86acf8
; MSVC complete object locator.
; hex 000000000000000000000000c0f5f7000cc7c600

; CTutorialController_type 0xf7f5c0..0xf7f5e2 raw 0xb7cdc0
; Original RTTI type descriptor.
; hex f435bd00000000002e3f4156435475746f7269616c436f6e74726f6c6c6572404000

; float_tick_step 0xc55b30..0xc55b38 raw 0x854130
; Original floating-point constant tick_step
; hex 000000201111a13f

; float_initial_distance_squared 0xc55b38..0xc55b3c raw 0x854138
; Original floating-point constant initial_distance_squared
; hex 286b6e4e

; float_distance_factor 0xc556f8..0xc55700 raw 0x853cf8
; Original floating-point constant distance_factor
; hex 0000000000000840

; float_speed_percent_factor 0xc557f8..0xc55800 raw 0x853df8
; Original floating-point constant speed_percent_factor
; hex 00000040e17a843f

; float_speed_default 0xc456c0..0xc456c4 raw 0x843cc0
; Original floating-point constant speed_default
; hex 0000803f

; float_base_speed_default 0xc55b6c..0xc55b70 raw 0x85416c
; Original floating-point constant base_speed_default
; hex 0000c041

; str_f_doCoTask 0xc106a0..0xc106ab raw 0x80eca0
; Named Lua qco entry invoked before native actor iteration.
; hex 665f646f436f5461736b00

