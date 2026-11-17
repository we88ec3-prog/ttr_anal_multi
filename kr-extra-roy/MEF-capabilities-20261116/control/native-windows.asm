; minimap_lua 0x4a2320..0x4a237c LoadMinimap closure passes one numeric converter, no result push
0x4a2320  55  push   ebp
0x4a2321  8bec  mov    ebp,esp
0x4a2323  6aff  push   0xffffffff
0x4a2325  68c8839300  push   0x9383c8
0x4a232a  64a100000000  mov    eax,fs:0x0
0x4a2330  50  push   eax
0x4a2331  83ec0c  sub    esp,0xc
0x4a2334  a1201fd600  mov    eax,ds:0xd61f20
0x4a2339  33c5  xor    eax,ebp
0x4a233b  50  push   eax
0x4a233c  8d45f4  lea    eax,[ebp-0xc]
0x4a233f  64a300000000  mov    fs:0x0,eax
0x4a2345  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a2348  8945e8  mov    DWORD PTR [ebp-0x18],eax
0x4a234b  33c0  xor    eax,eax
0x4a234d  8945ec  mov    DWORD PTR [ebp-0x14],eax
0x4a2350  8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4a2353  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x4a2356  8b0dac17fe00  mov    ecx,DWORD PTR ds:0xfe17ac
0x4a235c  51  push   ecx
0x4a235d  8d45e8  lea    eax,[ebp-0x18]
0x4a2360  e87b000000  call   0x4a23e0
0x4a2365  83c404  add    esp,0x4
0x4a2368  b801000000  mov    eax,0x1
0x4a236d  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a2370  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a2377  59  pop    ecx
0x4a2378  8be5  mov    esp,ebp
0x4a237a  5d  pop    ebp
0x4a237b  c3  ret

; lb_integer_converter 0x4a23e0..0x4a2453 last stack value; number/string to FISTP, other tag zero
0x4a23e0  55  push   ebp
0x4a23e1  8bec  mov    ebp,esp
0x4a23e3  8b08  mov    ecx,DWORD PTR [eax]
0x4a23e5  83ec18  sub    esp,0x18
0x4a23e8  53  push   ebx
0x4a23e9  8b1d7817fe00  mov    ebx,DWORD PTR ds:0xfe1778
0x4a23ef  83c8ff  or     eax,0xffffffff
0x4a23f2  e8f92c2500  call   0x6f50f0
0x4a23f7  8b4808  mov    ecx,DWORD PTR [eax+0x8]
0x4a23fa  83f903  cmp    ecx,0x3
0x4a23fd  742a  je     0x4a2429
0x4a23ff  83f904  cmp    ecx,0x4
0x4a2402  7540  jne    0x4a2444
0x4a2404  56  push   esi
0x4a2405  8b30  mov    esi,DWORD PTR [eax]
0x4a2407  57  push   edi
0x4a2408  83c610  add    esi,0x10
0x4a240b  8d7df8  lea    edi,[ebp-0x8]
0x4a240e  e84d532500  call   0x6f7760
0x4a2413  5f  pop    edi
0x4a2414  5e  pop    esi
0x4a2415  85c0  test   eax,eax
0x4a2417  742b  je     0x4a2444
0x4a2419  dd45f8  fld    QWORD PTR [ebp-0x8]
0x4a241c  c745f003000000  mov    DWORD PTR [ebp-0x10],0x3
0x4a2423  dd5de8  fstp   QWORD PTR [ebp-0x18]
0x4a2426  8d45e8  lea    eax,[ebp-0x18]
0x4a2429  dd00  fld    QWORD PTR [eax]
0x4a242b  dd5df0  fstp   QWORD PTR [ebp-0x10]
0x4a242e  dd45f0  fld    QWORD PTR [ebp-0x10]
0x4a2431  db5dfc  fistp  DWORD PTR [ebp-0x4]
0x4a2434  8b45fc  mov    eax,DWORD PTR [ebp-0x4]
0x4a2437  50  push   eax
0x4a2438  8bcb  mov    ecx,ebx
0x4a243a  ff5508  call   DWORD PTR [ebp+0x8]
0x4a243d  33c0  xor    eax,eax
0x4a243f  5b  pop    ebx
0x4a2440  8be5  mov    esp,ebp
0x4a2442  5d  pop    ebp
0x4a2443  c3  ret
0x4a2444  33c0  xor    eax,eax
0x4a2446  50  push   eax
0x4a2447  8bcb  mov    ecx,ebx
0x4a2449  ff5508  call   DWORD PTR [ebp+0x8]
0x4a244c  33c0  xor    eax,eax
0x4a244e  5b  pop    ebx
0x4a244f  8be5  mov    esp,ebp
0x4a2451  5d  pop    ebp
0x4a2452  c3  ret

; minimap_native 0x4a1400..0x4a1440 argument map key in ECX; existing minimap holder in EDI
0x4a1400  55  push   ebp
0x4a1401  8bec  mov    ebp,esp
0x4a1403  b801000000  mov    eax,0x1
0x4a1408  57  push   edi
0x4a1409  8405c0f3fd00  test   BYTE PTR ds:0xfdf3c0,al
0x4a140f  751d  jne    0x4a142e
0x4a1411  0905c0f3fd00  or     DWORD PTR ds:0xfdf3c0,eax
0x4a1417  6850dfbc00  push   0xbcdf50
0x4a141c  c705c4f3fd0000000000  mov    DWORD PTR ds:0xfdf3c4,0x0
0x4a1426  e8ef0e3f00  call   0x89231a
0x4a142b  83c404  add    esp,0x4
0x4a142e  8b4d08  mov    ecx,DWORD PTR [ebp+0x8]
0x4a1431  bfc4f3fd00  mov    edi,0xfdf3c4
0x4a1436  e8d5b80c00  call   0x56cd10
0x4a143b  5f  pop    edi
0x4a143c  5d  pop    ebp
0x4a143d  c20400  ret    0x4

; minimap_dispatch 0x56cd10..0x56cf05 map key to BOUND lookup, descriptor, texture/symbol consumers
0x56cd10  55  push   ebp
0x56cd11  8bec  mov    ebp,esp
0x56cd13  83e4f8  and    esp,0xfffffff8
0x56cd16  6aff  push   0xffffffff
0x56cd18  6804869300  push   0x938604
0x56cd1d  64a100000000  mov    eax,fs:0x0
0x56cd23  50  push   eax
0x56cd24  83ec34  sub    esp,0x34
0x56cd27  a1201fd600  mov    eax,ds:0xd61f20
0x56cd2c  33c4  xor    eax,esp
0x56cd2e  8944242c  mov    DWORD PTR [esp+0x2c],eax
0x56cd32  53  push   ebx
0x56cd33  56  push   esi
0x56cd34  a1201fd600  mov    eax,ds:0xd61f20
0x56cd39  33c4  xor    eax,esp
0x56cd3b  50  push   eax
0x56cd3c  8d442440  lea    eax,[esp+0x40]
0x56cd40  64a300000000  mov    fs:0x0,eax
0x56cd46  bb01000000  mov    ebx,0x1
0x56cd4b  8bf1  mov    esi,ecx
0x56cd4d  841d2cb2fa00  test   BYTE PTR ds:0xfab22c,bl
0x56cd53  7528  jne    0x56cd7d
0x56cd55  091d2cb2fa00  or     DWORD PTR ds:0xfab22c,ebx
0x56cd5b  c744244800000000  mov    DWORD PTR [esp+0x48],0x0
0x56cd63  e8281ff7ff  call   0x4dec90
0x56cd68  6830cebc00  push   0xbcce30
0x56cd6d  e8a8553200  call   0x89231a
0x56cd72  83c404  add    esp,0x4
0x56cd75  c7442448ffffffff  mov    DWORD PTR [esp+0x48],0xffffffff
0x56cd7d  a134b1fa00  mov    eax,ds:0xfab134
0x56cd82  0fb64036  movzx  eax,BYTE PTR [eax+0x36]
0x56cd86  83f805  cmp    eax,0x5
0x56cd89  0f8492000000  je     0x56ce21
0x56cd8f  85c0  test   eax,eax
0x56cd91  0f848a000000  je     0x56ce21
0x56cd97  c744241800000000  mov    DWORD PTR [esp+0x18],0x0
0x56cd9f  b9cc07c100  mov    ecx,0xc107cc
0x56cda4  8b07  mov    eax,DWORD PTR [edi]
0x56cda6  83c020  add    eax,0x20
0x56cda9  50  push   eax
0x56cdaa  e831300000  call   0x56fde0
0x56cdaf  6a0c  push   0xc
0x56cdb1  68ec07c100  push   0xc107ec
0x56cdb6  8d4c2424  lea    ecx,[esp+0x24]
0x56cdba  c74424380f000000  mov    DWORD PTR [esp+0x38],0xf
0x56cdc2  c744243400000000  mov    DWORD PTR [esp+0x34],0x0
0x56cdca  c644242400  mov    BYTE PTR [esp+0x24],0x0
0x56cdcf  e89c5ce9ff  call   0x402a70
0x56cdd4  895c2448  mov    DWORD PTR [esp+0x48],ebx
0x56cdd8  841db075fb00  test   BYTE PTR ds:0xfb75b0,bl
0x56cdde  7521  jne    0x56ce01
0x56cde0  091db075fb00  or     DWORD PTR ds:0xfb75b0,ebx
0x56cde6  c644244802  mov    BYTE PTR [esp+0x48],0x2
0x56cdeb  e8906ff8ff  call   0x4f3d80
0x56cdf0  68e0d1bc00  push   0xbcd1e0
0x56cdf5  e820553200  call   0x89231a
0x56cdfa  83c404  add    esp,0x4
0x56cdfd  885c2448  mov    BYTE PTR [esp+0x48],bl
0x56ce01  8d542410  lea    edx,[esp+0x10]
0x56ce05  b9d074fb00  mov    ecx,0xfb74d0
0x56ce0a  89742410  mov    DWORD PTR [esp+0x10],esi
0x56ce0e  e8ddaff8ff  call   0x4f7df0
0x56ce13  bb10000000  mov    ebx,0x10
0x56ce18  395814  cmp    DWORD PTR [eax+0x14],ebx
0x56ce1b  7212  jb     0x56ce2f
0x56ce1d  8b10  mov    edx,DWORD PTR [eax]
0x56ce1f  eb10  jmp    0x56ce31
0x56ce21  895c2418  mov    DWORD PTR [esp+0x18],ebx
0x56ce25  b9b007c100  mov    ecx,0xc107b0
0x56ce2a  e975ffffff  jmp    0x56cda4
0x56ce2f  8bd0  mov    edx,eax
0x56ce31  8bc2  mov    eax,edx
0x56ce33  8d7001  lea    esi,[eax+0x1]
0x56ce36  8a08  mov    cl,BYTE PTR [eax]
0x56ce38  40  inc    eax
0x56ce39  84c9  test   cl,cl
0x56ce3b  75f9  jne    0x56ce36
0x56ce3d  2bc6  sub    eax,esi
0x56ce3f  7511  jne    0x56ce52
0x56ce41  50  push   eax
0x56ce42  687523bf00  push   0xbf2375
0x56ce47  8d4c2424  lea    ecx,[esp+0x24]
0x56ce4b  e8205ce9ff  call   0x402a70
0x56ce50  eb29  jmp    0x56ce7b
0x56ce52  8bc2  mov    eax,edx
0x56ce54  8d7001  lea    esi,[eax+0x1]
0x56ce57  8a08  mov    cl,BYTE PTR [eax]
0x56ce59  40  inc    eax
0x56ce5a  84c9  test   cl,cl
0x56ce5c  75f9  jne    0x56ce57
0x56ce5e  2bc6  sub    eax,esi
0x56ce60  50  push   eax
0x56ce61  52  push   edx
0x56ce62  8d4c2424  lea    ecx,[esp+0x24]
0x56ce66  e85551e9ff  call   0x401fc0
0x56ce6b  6a04  push   0x4
0x56ce6d  68fc07c100  push   0xc107fc
0x56ce72  8d4c2424  lea    ecx,[esp+0x24]
0x56ce76  e84551e9ff  call   0x401fc0
0x56ce7b  8b44241c  mov    eax,DWORD PTR [esp+0x1c]
0x56ce7f  395c2430  cmp    DWORD PTR [esp+0x30],ebx
0x56ce83  7304  jae    0x56ce89
0x56ce85  8d44241c  lea    eax,[esp+0x1c]
0x56ce89  33c9  xor    ecx,ecx
0x56ce8b  394c2418  cmp    DWORD PTR [esp+0x18],ecx
0x56ce8f  0f94c1  sete   cl
0x56ce92  51  push   ecx
0x56ce93  8b0f  mov    ecx,DWORD PTR [edi]
0x56ce95  50  push   eax
0x56ce96  e8f5180000  call   0x56e790
0x56ce9b  8b0f  mov    ecx,DWORD PTR [edi]
0x56ce9d  e83e180000  call   0x56e6e0
0x56cea2  8b1538a8fb00  mov    edx,DWORD PTR ds:0xfba838
0x56cea8  8b4240  mov    eax,DWORD PTR [edx+0x40]
0x56ceab  85c0  test   eax,eax
0x56cead  741c  je     0x56cecb
0x56ceaf  8b905c010000  mov    edx,DWORD PTR [eax+0x15c]
0x56ceb5  8b8858010000  mov    ecx,DWORD PTR [eax+0x158]
0x56cebb  89542414  mov    DWORD PTR [esp+0x14],edx
0x56cebf  f30f10442414  movss  xmm0,DWORD PTR [esp+0x14]
0x56cec5  894c2410  mov    DWORD PTR [esp+0x10],ecx
0x56cec9  eb03  jmp    0x56cece
0x56cecb  0f57c0  xorps  xmm0,xmm0
0x56cece  8b07  mov    eax,DWORD PTR [edi]
0x56ced0  f30f114064  movss  DWORD PTR [eax+0x64],xmm0
0x56ced5  395c2430  cmp    DWORD PTR [esp+0x30],ebx
0x56ced9  720d  jb     0x56cee8
0x56cedb  8b4c241c  mov    ecx,DWORD PTR [esp+0x1c]
0x56cedf  51  push   ecx
0x56cee0  e827433200  call   0x89120c
0x56cee5  83c404  add    esp,0x4
0x56cee8  8b4c2440  mov    ecx,DWORD PTR [esp+0x40]
0x56ceec  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x56cef3  59  pop    ecx
0x56cef4  5e  pop    esi
0x56cef5  5b  pop    ebx
0x56cef6  8b4c242c  mov    ecx,DWORD PTR [esp+0x2c]
0x56cefa  33cc  xor    ecx,esp
0x56cefc  e800413200  call   0x891001
0x56cf01  8be5  mov    esp,ebp
0x56cf03  5d  pop    ebp
0x56cf04  c3  ret

; minimap_descriptor_start 0x56e790..0x56e91c descriptor load/failure and Minimap/TextureFile consumer entry
0x56e790  55  push   ebp
0x56e791  8bec  mov    ebp,esp
0x56e793  6aff  push   0xffffffff
0x56e795  68a9859300  push   0x9385a9
0x56e79a  64a100000000  mov    eax,fs:0x0
0x56e7a0  50  push   eax
0x56e7a1  81ec1c010000  sub    esp,0x11c
0x56e7a7  a1201fd600  mov    eax,ds:0xd61f20
0x56e7ac  33c5  xor    eax,ebp
0x56e7ae  8945f0  mov    DWORD PTR [ebp-0x10],eax
0x56e7b1  53  push   ebx
0x56e7b2  56  push   esi
0x56e7b3  57  push   edi
0x56e7b4  50  push   eax
0x56e7b5  8d45f4  lea    eax,[ebp-0xc]
0x56e7b8  64a300000000  mov    fs:0x0,eax
0x56e7be  8b5d08  mov    ebx,DWORD PTR [ebp+0x8]
0x56e7c1  8bf1  mov    esi,ecx
0x56e7c3  8d7e54  lea    edi,[esi+0x54]
0x56e7c6  89b51cffffff  mov    DWORD PTR [ebp-0xe4],esi
0x56e7cc  e89f130000  call   0x56fb70
0x56e7d1  0f57c0  xorps  xmm0,xmm0
0x56e7d4  8d8520ffffff  lea    eax,[ebp-0xe0]
0x56e7da  50  push   eax
0x56e7db  8bcb  mov    ecx,ebx
0x56e7dd  f30f114668  movss  DWORD PTR [esi+0x68],xmm0
0x56e7e2  f30f114664  movss  DWORD PTR [esi+0x64],xmm0
0x56e7e7  e844061c00  call   0x72ee30
0x56e7ec  53  push   ebx
0x56e7ed  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x56e7f4  e8575d1a00  call   0x714550
0x56e7f9  83c404  add    esp,0x4
0x56e7fc  85c0  test   eax,eax
0x56e7fe  0f84ce050000  je     0x56edd2
0x56e804  83bd54ffffff10  cmp    DWORD PTR [ebp-0xac],0x10
0x56e80b  8b8d40ffffff  mov    ecx,DWORD PTR [ebp-0xc0]
0x56e811  7306  jae    0x56e819
0x56e813  8d8d40ffffff  lea    ecx,[ebp-0xc0]
0x56e819  6a00  push   0x0
0x56e81b  8db520ffffff  lea    esi,[ebp-0xe0]
0x56e821  e8ea081c00  call   0x72f110
0x56e826  84c0  test   al,al
0x56e828  0f84a4050000  je     0x56edd2
0x56e82e  8b8d38ffffff  mov    ecx,DWORD PTR [ebp-0xc8]
0x56e834  c78500ffffff00000000  mov    DWORD PTR [ebp-0x100],0x0
0x56e83e  85c9  test   ecx,ecx
0x56e840  7453  je     0x56e895
0x56e842  8b11  mov    edx,DWORD PTR [ecx]
0x56e844  8b4234  mov    eax,DWORD PTR [edx+0x34]
0x56e847  ffd0  call   eax
0x56e849  85c0  test   eax,eax
0x56e84b  7448  je     0x56e895
0x56e84d  8d7060  lea    esi,[eax+0x60]
0x56e850  bf10000000  mov    edi,0x10
0x56e855  397e14  cmp    DWORD PTR [esi+0x14],edi
0x56e858  7204  jb     0x56e85e
0x56e85a  8b06  mov    eax,DWORD PTR [esi]
0x56e85c  eb02  jmp    0x56e860
0x56e85e  8bc6  mov    eax,esi
0x56e860  684008c100  push   0xc10840
0x56e865  50  push   eax
0x56e866  e846543200  call   0x893cb1
0x56e86b  83c408  add    esp,0x8
0x56e86e  85c0  test   eax,eax
0x56e870  7419  je     0x56e88b
0x56e872  397e14  cmp    DWORD PTR [esi+0x14],edi
0x56e875  7202  jb     0x56e879
0x56e877  8b36  mov    esi,DWORD PTR [esi]
0x56e879  684808c100  push   0xc10848
0x56e87e  56  push   esi
0x56e87f  e82d543200  call   0x893cb1
0x56e884  83c408  add    esp,0x8
0x56e887  85c0  test   eax,eax
0x56e889  750a  jne    0x56e895
0x56e88b  c78500ffffff01000000  mov    DWORD PTR [ebp-0x100],0x1
0x56e895  685008c100  push   0xc10850
0x56e89a  8d8520ffffff  lea    eax,[ebp-0xe0]
0x56e8a0  e83bfa1b00  call   0x72e2e0
0x56e8a5  8bd8  mov    ebx,eax
0x56e8a7  85db  test   ebx,ebx
0x56e8a9  7519  jne    0x56e8c4
0x56e8ab  8d8d20ffffff  lea    ecx,[ebp-0xe0]
0x56e8b1  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x56e8b8  e8f396e9ff  call   0x407fb0
0x56e8bd  33c0  xor    eax,eax
0x56e8bf  e96d050000  jmp    0x56ee31
0x56e8c4  8b13  mov    edx,DWORD PTR [ebx]
0x56e8c6  8b4214  mov    eax,DWORD PTR [edx+0x14]
0x56e8c9  8bcb  mov    ecx,ebx
0x56e8cb  ffd0  call   eax
0x56e8cd  8bf0  mov    esi,eax
0x56e8cf  85f6  test   esi,esi
0x56e8d1  74d8  je     0x56e8ab
0x56e8d3  d9ee  fldz
0x56e8d5  51  push   ecx
0x56e8d6  b85808c100  mov    eax,0xc10858
0x56e8db  d91c24  fstp   DWORD PTR [esp]
0x56e8de  8bce  mov    ecx,esi
0x56e8e0  e8abfd1b00  call   0x72e690
0x56e8e5  8b8d1cffffff  mov    ecx,DWORD PTR [ebp-0xe4]
0x56e8eb  686408c100  push   0xc10864
0x56e8f0  d95964  fstp   DWORD PTR [ecx+0x64]
0x56e8f3  8d7e44  lea    edi,[esi+0x44]
0x56e8f6  e8a5171c00  call   0x7300a0
0x56e8fb  85c0  test   eax,eax
0x56e8fd  740d  je     0x56e90c
0x56e8ff  83784410  cmp    DWORD PTR [eax+0x44],0x10
0x56e903  8d4830  lea    ecx,[eax+0x30]
0x56e906  7206  jb     0x56e90e
0x56e908  8b09  mov    ecx,DWORD PTR [ecx]
0x56e90a  eb02  jmp    0x56e90e
0x56e90c  33c9  xor    ecx,ecx
0x56e90e  8b951cffffff  mov    edx,DWORD PTR [ebp-0xe4]
0x56e914  6a00  push   0x0
0x56e916  52  push   edx
0x56e917  e814faffff  call   0x56e330

; minimap_symbols 0x56e6e0..0x56e781 release previous symbol sheet, load fixed EIF
0x56e6e0  55  push   ebp
0x56e6e1  8bec  mov    ebp,esp
0x56e6e3  6aff  push   0xffffffff
0x56e6e5  68eeb19100  push   0x91b1ee
0x56e6ea  64a100000000  mov    eax,fs:0x0
0x56e6f0  50  push   eax
0x56e6f1  56  push   esi
0x56e6f2  a1201fd600  mov    eax,ds:0xd61f20
0x56e6f7  33c5  xor    eax,ebp
0x56e6f9  50  push   eax
0x56e6fa  8d45f4  lea    eax,[ebp-0xc]
0x56e6fd  64a300000000  mov    fs:0x0,eax
0x56e703  8bf1  mov    esi,ecx
0x56e705  8b463c  mov    eax,DWORD PTR [esi+0x3c]
0x56e708  85c0  test   eax,eax
0x56e70a  740d  je     0x56e719
0x56e70c  50  push   eax
0x56e70d  e8be60f3ff  call   0x4a47d0
0x56e712  c7463c00000000  mov    DWORD PTR [esi+0x3c],0x0
0x56e719  6a1e  push   0x1e
0x56e71b  680408c100  push   0xc10804
0x56e720  8d4e20  lea    ecx,[esi+0x20]
0x56e723  c7464000000000  mov    DWORD PTR [esi+0x40],0x0
0x56e72a  e84143e9ff  call   0x402a70
0x56e72f  f60540defc0001  test   BYTE PTR ds:0xfcde40,0x1
0x56e736  7527  jne    0x56e75f
0x56e738  830d40defc0001  or     DWORD PTR ds:0xfcde40,0x1
0x56e73f  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x56e746  e835811c00  call   0x736880
0x56e74b  68f0e6bc00  push   0xbce6f0
0x56e750  e8c53b3200  call   0x89231a
0x56e755  83c404  add    esp,0x4
0x56e758  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x56e75f  a128defc00  mov    eax,ds:0xfcde28
0x56e764  8d4e20  lea    ecx,[esi+0x20]
0x56e767  e894150000  call   0x56fd00
0x56e76c  b801000000  mov    eax,0x1
0x56e771  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x56e774  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x56e77b  59  pop    ecx
0x56e77c  5e  pop    esi
0x56e77d  8be5  mov    esp,ebp
0x56e77f  5d  pop    ebp
0x56e780  c3  ret

; minimap_bound_getter 0x4f7df0..0x4f7f1b string tree lookup inserts empty string for missing key
0x4f7df0  55  push   ebp
0x4f7df1  8bec  mov    ebp,esp
0x4f7df3  83e4f8  and    esp,0xfffffff8
0x4f7df6  6aff  push   0xffffffff
0x4f7df8  68d0749100  push   0x9174d0
0x4f7dfd  64a100000000  mov    eax,fs:0x0
0x4f7e03  50  push   eax
0x4f7e04  83ec48  sub    esp,0x48
0x4f7e07  a1201fd600  mov    eax,ds:0xd61f20
0x4f7e0c  33c4  xor    eax,esp
0x4f7e0e  89442440  mov    DWORD PTR [esp+0x40],eax
0x4f7e12  53  push   ebx
0x4f7e13  56  push   esi
0x4f7e14  57  push   edi
0x4f7e15  a1201fd600  mov    eax,ds:0xd61f20
0x4f7e1a  33c4  xor    eax,esp
0x4f7e1c  50  push   eax
0x4f7e1d  8d442458  lea    eax,[esp+0x58]
0x4f7e21  64a300000000  mov    fs:0x0,eax
0x4f7e27  8bf1  mov    esi,ecx
0x4f7e29  8b4e04  mov    ecx,DWORD PTR [esi+0x4]
0x4f7e2c  8b4104  mov    eax,DWORD PTR [ecx+0x4]
0x4f7e2f  33db  xor    ebx,ebx
0x4f7e31  8bf9  mov    edi,ecx
0x4f7e33  38582d  cmp    BYTE PTR [eax+0x2d],bl
0x4f7e36  751b  jne    0x4f7e53
0x4f7e38  8b0a  mov    ecx,DWORD PTR [edx]
0x4f7e3a  8d9b00000000  lea    ebx,[ebx+0x0]
0x4f7e40  39480c  cmp    DWORD PTR [eax+0xc],ecx
0x4f7e43  7305  jae    0x4f7e4a
0x4f7e45  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4f7e48  eb04  jmp    0x4f7e4e
0x4f7e4a  8bf8  mov    edi,eax
0x4f7e4c  8b00  mov    eax,DWORD PTR [eax]
0x4f7e4e  38582d  cmp    BYTE PTR [eax+0x2d],bl
0x4f7e51  74ed  je     0x4f7e40
0x4f7e53  3b7e04  cmp    edi,DWORD PTR [esi+0x4]
0x4f7e56  740b  je     0x4f7e63
0x4f7e58  8b02  mov    eax,DWORD PTR [edx]
0x4f7e5a  3b470c  cmp    eax,DWORD PTR [edi+0xc]
0x4f7e5d  0f8397000000  jae    0x4f7efa
0x4f7e63  b80f000000  mov    eax,0xf
0x4f7e68  89442448  mov    DWORD PTR [esp+0x48],eax
0x4f7e6c  895c2444  mov    DWORD PTR [esp+0x44],ebx
0x4f7e70  885c2434  mov    BYTE PTR [esp+0x34],bl
0x4f7e74  895c2460  mov    DWORD PTR [esp+0x60],ebx
0x4f7e78  8b0a  mov    ecx,DWORD PTR [edx]
0x4f7e7a  8d542434  lea    edx,[esp+0x34]
0x4f7e7e  894c2414  mov    DWORD PTR [esp+0x14],ecx
0x4f7e82  52  push   edx
0x4f7e83  8d4c241c  lea    ecx,[esp+0x1c]
0x4f7e87  89442430  mov    DWORD PTR [esp+0x30],eax
0x4f7e8b  895c242c  mov    DWORD PTR [esp+0x2c],ebx
0x4f7e8f  885c241c  mov    BYTE PTR [esp+0x1c],bl
0x4f7e93  e818adf0ff  call   0x402bb0
0x4f7e98  8d442414  lea    eax,[esp+0x14]
0x4f7e9c  50  push   eax
0x4f7e9d  8bce  mov    ecx,esi
0x4f7e9f  c644246401  mov    BYTE PTR [esp+0x64],0x1
0x4f7ea4  e8971c0000  call   0x4f9b40
0x4f7ea9  57  push   edi
0x4f7eaa  8d4c2414  lea    ecx,[esp+0x14]
0x4f7eae  51  push   ecx
0x4f7eaf  8bce  mov    ecx,esi
0x4f7eb1  e8ca100000  call   0x4f8f80
0x4f7eb6  8b742410  mov    esi,DWORD PTR [esp+0x10]
0x4f7eba  bf10000000  mov    edi,0x10
0x4f7ebf  397c242c  cmp    DWORD PTR [esp+0x2c],edi
0x4f7ec3  720d  jb     0x4f7ed2
0x4f7ec5  8b542418  mov    edx,DWORD PTR [esp+0x18]
0x4f7ec9  52  push   edx
0x4f7eca  e83d933900  call   0x89120c
0x4f7ecf  83c404  add    esp,0x4
0x4f7ed2  c744242c0f000000  mov    DWORD PTR [esp+0x2c],0xf
0x4f7eda  895c2428  mov    DWORD PTR [esp+0x28],ebx
0x4f7ede  885c2418  mov    BYTE PTR [esp+0x18],bl
0x4f7ee2  397c2448  cmp    DWORD PTR [esp+0x48],edi
0x4f7ee6  720d  jb     0x4f7ef5
0x4f7ee8  8b442434  mov    eax,DWORD PTR [esp+0x34]
0x4f7eec  50  push   eax
0x4f7eed  e81a933900  call   0x89120c
0x4f7ef2  83c404  add    esp,0x4
0x4f7ef5  8d4610  lea    eax,[esi+0x10]
0x4f7ef8  eb03  jmp    0x4f7efd
0x4f7efa  8d4710  lea    eax,[edi+0x10]
0x4f7efd  8b4c2458  mov    ecx,DWORD PTR [esp+0x58]
0x4f7f01  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4f7f08  59  pop    ecx
0x4f7f09  5f  pop    edi
0x4f7f0a  5e  pop    esi
0x4f7f0b  5b  pop    ebx
0x4f7f0c  8b4c2440  mov    ecx,DWORD PTR [esp+0x40]
0x4f7f10  33cc  xor    ecx,esp
0x4f7f12  e8ea903900  call   0x891001
0x4f7f17  8be5  mov    esp,ebp
0x4f7f19  5d  pop    ebp
0x4f7f1a  c3  ret

; minimap_tick_caller 0x49262a..0x49265b existing native update calls 56F130 on current minimap pointer
0x49262a  f605c0f3fd0001  test   BYTE PTR ds:0xfdf3c0,0x1
0x492631  751d  jne    0x492650
0x492633  093dc0f3fd00  or     DWORD PTR ds:0xfdf3c0,edi
0x492639  6850dfbc00  push   0xbcdf50
0x49263e  c705c4f3fd0000000000  mov    DWORD PTR ds:0xfdf3c4,0x0
0x492648  e8cdfc3f00  call   0x89231a
0x49264d  83c404  add    esp,0x4
0x492650  a1c4f3fd00  mov    eax,ds:0xfdf3c4
0x492655  50  push   eax
0x492656  e8d5ca0d00  call   0x56f130

; gettime_thunk 0x4a2190..0x4a21fe native 32-bit result converted with signed FILD to Lua number
0x4a2190  55  push   ebp
0x4a2191  8bec  mov    ebp,esp
0x4a2193  6aff  push   0xffffffff
0x4a2195  68d8879300  push   0x9387d8
0x4a219a  64a100000000  mov    eax,fs:0x0
0x4a21a0  50  push   eax
0x4a21a1  83ec0c  sub    esp,0xc
0x4a21a4  56  push   esi
0x4a21a5  a1201fd600  mov    eax,ds:0xd61f20
0x4a21aa  33c5  xor    eax,ebp
0x4a21ac  50  push   eax
0x4a21ad  8d45f4  lea    eax,[ebp-0xc]
0x4a21b0  64a300000000  mov    fs:0x0,eax
0x4a21b6  8b7508  mov    esi,DWORD PTR [ebp+0x8]
0x4a21b9  33c0  xor    eax,eax
0x4a21bb  8975e8  mov    DWORD PTR [ebp-0x18],esi
0x4a21be  8945ec  mov    DWORD PTR [ebp-0x14],eax
0x4a21c1  8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4a21c4  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x4a21c7  8b0d7817fe00  mov    ecx,DWORD PTR ds:0xfe1778
0x4a21cd  ff159c17fe00  call   DWORD PTR ds:0xfe179c
0x4a21d3  894508  mov    DWORD PTR [ebp+0x8],eax
0x4a21d6  8b4608  mov    eax,DWORD PTR [esi+0x8]
0x4a21d9  db4508  fild   DWORD PTR [ebp+0x8]
0x4a21dc  c7400803000000  mov    DWORD PTR [eax+0x8],0x3
0x4a21e3  dd18  fstp   QWORD PTR [eax]
0x4a21e5  83460810  add    DWORD PTR [esi+0x8],0x10
0x4a21e9  b801000000  mov    eax,0x1
0x4a21ee  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a21f1  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a21f8  59  pop    ecx
0x4a21f9  5e  pop    esi
0x4a21fa  8be5  mov    esp,ebp
0x4a21fc  5d  pop    ebp
0x4a21fd  c3  ret

; gettime_import_jump 0x4a0b70..0x4a0b76 exact WINMM import jump
0x4a0b70  ff25a025bd00  jmp    DWORD PTR ds:0xbd25a0

; gettime_iat 0xbd25a0..0xbd25a4 original import-name RVA
; hex 0cf09500

; gettime_import_name 0xd5f00e..0xd5f01a import symbol name
; hex 74696d6547657454696d6500

; debug_level 0x4a0aa0..0x4a0abe diagnostic level store, upper clamp to 9
0x4a0aa0  55  push   ebp
0x4a0aa1  8bec  mov    ebp,esp
0x4a0aa3  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a0aa6  a3783dd600  mov    ds:0xd63d78,eax
0x4a0aab  83f809  cmp    eax,0x9
0x4a0aae  7c0a  jl     0x4a0aba
0x4a0ab0  c705783dd60009000000  mov    DWORD PTR ds:0xd63d78,0x9
0x4a0aba  5d  pop    ebp
0x4a0abb  c20400  ret    0x4

; print_scene_stub 0x5f5d10..0x5f5d11 normal public target is RET
0x5f5d10  c3  ret

; print_scene_closure 0x4a2260..0x4a22b6 calls stub without creating a Lua return value
0x4a2260  55  push   ebp
0x4a2261  8bec  mov    ebp,esp
0x4a2263  6aff  push   0xffffffff
0x4a2265  68c8839300  push   0x9383c8
0x4a226a  64a100000000  mov    eax,fs:0x0
0x4a2270  50  push   eax
0x4a2271  83ec0c  sub    esp,0xc
0x4a2274  a1201fd600  mov    eax,ds:0xd61f20
0x4a2279  33c5  xor    eax,ebp
0x4a227b  50  push   eax
0x4a227c  8d45f4  lea    eax,[ebp-0xc]
0x4a227f  64a300000000  mov    fs:0x0,eax
0x4a2285  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a2288  8945e8  mov    DWORD PTR [ebp-0x18],eax
0x4a228b  33c0  xor    eax,eax
0x4a228d  8945ec  mov    DWORD PTR [ebp-0x14],eax
0x4a2290  8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4a2293  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x4a2296  8b0d7817fe00  mov    ecx,DWORD PTR ds:0xfe1778
0x4a229c  ff15a417fe00  call   DWORD PTR ds:0xfe17a4
0x4a22a2  b801000000  mov    eax,0x1
0x4a22a7  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a22aa  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a22b1  59  pop    ecx
0x4a22b2  8be5  mov    esp,ebp
0x4a22b4  5d  pop    ebp
0x4a22b5  c3  ret

; resolution_closure 0x4a22c0..0x4a231d three-number converter call
0x4a22c0  55  push   ebp
0x4a22c1  8bec  mov    ebp,esp
0x4a22c3  6aff  push   0xffffffff
0x4a22c5  68c8839300  push   0x9383c8
0x4a22ca  64a100000000  mov    eax,fs:0x0
0x4a22d0  50  push   eax
0x4a22d1  83ec0c  sub    esp,0xc
0x4a22d4  a1201fd600  mov    eax,ds:0xd61f20
0x4a22d9  33c5  xor    eax,ebp
0x4a22db  50  push   eax
0x4a22dc  8d45f4  lea    eax,[ebp-0xc]
0x4a22df  64a300000000  mov    fs:0x0,eax
0x4a22e5  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a22e8  8945e8  mov    DWORD PTR [ebp-0x18],eax
0x4a22eb  33c0  xor    eax,eax
0x4a22ed  8945ec  mov    DWORD PTR [ebp-0x14],eax
0x4a22f0  8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4a22f3  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x4a22f6  8b0da817fe00  mov    ecx,DWORD PTR ds:0xfe17a8
0x4a22fc  51  push   ecx
0x4a22fd  8d55e8  lea    edx,[ebp-0x18]
0x4a2300  52  push   edx
0x4a2301  e84a050000  call   0x4a2850
0x4a2306  83c408  add    esp,0x8
0x4a2309  b801000000  mov    eax,0x1
0x4a230e  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a2311  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a2318  59  pop    ecx
0x4a2319  8be5  mov    esp,ebp
0x4a231b  5d  pop    ebp
0x4a231c  c3  ret

; resolution_native 0x4a1330..0x4a13f6 passes three parameters and selects existing rendering reconfiguration path
0x4a1330  55  push   ebp
0x4a1331  8bec  mov    ebp,esp
0x4a1333  6aff  push   0xffffffff
0x4a1335  682eab9000  push   0x90ab2e
0x4a133a  64a100000000  mov    eax,fs:0x0
0x4a1340  50  push   eax
0x4a1341  53  push   ebx
0x4a1342  a1201fd600  mov    eax,ds:0xd61f20
0x4a1347  33c5  xor    eax,ebp
0x4a1349  50  push   eax
0x4a134a  8d45f4  lea    eax,[ebp-0xc]
0x4a134d  64a300000000  mov    fs:0x0,eax
0x4a1353  8b4510  mov    eax,DWORD PTR [ebp+0x10]
0x4a1356  8b4d0c  mov    ecx,DWORD PTR [ebp+0xc]
0x4a1359  8b5508  mov    edx,DWORD PTR [ebp+0x8]
0x4a135c  50  push   eax
0x4a135d  51  push   ecx
0x4a135e  52  push   edx
0x4a135f  e88cda2300  call   0x6dedf0
0x4a1364  6a01  push   0x1
0x4a1366  6a01  push   0x1
0x4a1368  e8835e2400  call   0x6e71f0
0x4a136d  83c408  add    esp,0x8
0x4a1370  e85b902400  call   0x6ea3d0
0x4a1375  84c0  test   al,al
0x4a1377  7407  je     0x4a1380
0x4a1379  e8a21a2400  call   0x6e2e20
0x4a137e  eb05  jmp    0x4a1385
0x4a1380  e81b1f2400  call   0x6e32a0
0x4a1385  6a00  push   0x0
0x4a1387  6a00  push   0x0
0x4a1389  e8625e2400  call   0x6e71f0
0x4a138e  83c408  add    esp,0x8
0x4a1391  e83a902400  call   0x6ea3d0
0x4a1396  f6052888fb0001  test   BYTE PTR ds:0xfb8828,0x1
0x4a139d  8ad8  mov    bl,al
0x4a139f  7520  jne    0x4a13c1
0x4a13a1  830d2888fb0001  or     DWORD PTR ds:0xfb8828,0x1
0x4a13a8  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x4a13af  e89ce40a00  call   0x54f850
0x4a13b4  6880d5bc00  push   0xbcd580
0x4a13b9  e85c0f3f00  call   0x89231a
0x4a13be  83c404  add    esp,0x4
0x4a13c1  8a0dd391fb00  mov    cl,BYTE PTR ds:0xfb91d3
0x4a13c7  8ac3  mov    al,bl
0x4a13c9  3ad9  cmp    bl,cl
0x4a13cb  7602  jbe    0x4a13cf
0x4a13cd  8ac1  mov    al,cl
0x4a13cf  8a0dd291fb00  mov    cl,BYTE PTR ds:0xfb91d2
0x4a13d5  880dd191fb00  mov    BYTE PTR ds:0xfb91d1,cl
0x4a13db  3ac1  cmp    al,cl
0x4a13dd  7205  jb     0x4a13e4
0x4a13df  a2d191fb00  mov    ds:0xfb91d1,al
0x4a13e4  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a13e7  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a13ee  59  pop    ecx
0x4a13ef  5b  pop    ebx
0x4a13f0  8be5  mov    esp,ebp
0x4a13f2  5d  pop    ebp
0x4a13f3  c20c00  ret    0xc

; resolution_converter 0x4a2850..0x4a2981 three numeric values; exact ABI, not validated device mode list
0x4a2850  55  push   ebp
0x4a2851  8bec  mov    ebp,esp
0x4a2853  83ec2c  sub    esp,0x2c
0x4a2856  a17817fe00  mov    eax,ds:0xfe1778
0x4a285b  53  push   ebx
0x4a285c  8b5d08  mov    ebx,DWORD PTR [ebp+0x8]
0x4a285f  8b0b  mov    ecx,DWORD PTR [ebx]
0x4a2861  56  push   esi
0x4a2862  8945e4  mov    DWORD PTR [ebp-0x1c],eax
0x4a2865  57  push   edi
0x4a2866  83c8ff  or     eax,0xffffffff
0x4a2869  e882282500  call   0x6f50f0
0x4a286e  8b4808  mov    ecx,DWORD PTR [eax+0x8]
0x4a2871  83f903  cmp    ecx,0x3
0x4a2874  742e  je     0x4a28a4
0x4a2876  83f904  cmp    ecx,0x4
0x4a2879  0f85e9000000  jne    0x4a2968
0x4a287f  8b30  mov    esi,DWORD PTR [eax]
0x4a2881  83c610  add    esi,0x10
0x4a2884  8d7de8  lea    edi,[ebp-0x18]
0x4a2887  e8d44e2500  call   0x6f7760
0x4a288c  85c0  test   eax,eax
0x4a288e  0f84d4000000  je     0x4a2968
0x4a2894  dd45e8  fld    QWORD PTR [ebp-0x18]
0x4a2897  c745dc03000000  mov    DWORD PTR [ebp-0x24],0x3
0x4a289e  dd5dd4  fstp   QWORD PTR [ebp-0x2c]
0x4a28a1  8d45d4  lea    eax,[ebp-0x2c]
0x4a28a4  dd00  fld    QWORD PTR [eax]
0x4a28a6  dd5de8  fstp   QWORD PTR [ebp-0x18]
0x4a28a9  dd45e8  fld    QWORD PTR [ebp-0x18]
0x4a28ac  db5d08  fistp  DWORD PTR [ebp+0x8]
0x4a28af  8b4d08  mov    ecx,DWORD PTR [ebp+0x8]
0x4a28b2  894df0  mov    DWORD PTR [ebp-0x10],ecx
0x4a28b5  8b0b  mov    ecx,DWORD PTR [ebx]
0x4a28b7  b8feffffff  mov    eax,0xfffffffe
0x4a28bc  e82f282500  call   0x6f50f0
0x4a28c1  8b4808  mov    ecx,DWORD PTR [eax+0x8]
0x4a28c4  83f903  cmp    ecx,0x3
0x4a28c7  742e  je     0x4a28f7
0x4a28c9  83f904  cmp    ecx,0x4
0x4a28cc  0f85a2000000  jne    0x4a2974
0x4a28d2  8b30  mov    esi,DWORD PTR [eax]
0x4a28d4  83c610  add    esi,0x10
0x4a28d7  8d7de8  lea    edi,[ebp-0x18]
0x4a28da  e8814e2500  call   0x6f7760
0x4a28df  85c0  test   eax,eax
0x4a28e1  0f848d000000  je     0x4a2974
0x4a28e7  dd45e8  fld    QWORD PTR [ebp-0x18]
0x4a28ea  c745dc03000000  mov    DWORD PTR [ebp-0x24],0x3
0x4a28f1  dd5dd4  fstp   QWORD PTR [ebp-0x2c]
0x4a28f4  8d45d4  lea    eax,[ebp-0x2c]
0x4a28f7  dd00  fld    QWORD PTR [eax]
0x4a28f9  dd5de8  fstp   QWORD PTR [ebp-0x18]
0x4a28fc  dd45e8  fld    QWORD PTR [ebp-0x18]
0x4a28ff  db5dfc  fistp  DWORD PTR [ebp-0x4]
0x4a2902  8b55fc  mov    edx,DWORD PTR [ebp-0x4]
0x4a2905  8955ec  mov    DWORD PTR [ebp-0x14],edx
0x4a2908  8b0b  mov    ecx,DWORD PTR [ebx]
0x4a290a  b8fdffffff  mov    eax,0xfffffffd
0x4a290f  e8dc272500  call   0x6f50f0
0x4a2914  8b4808  mov    ecx,DWORD PTR [eax+0x8]
0x4a2917  83f903  cmp    ecx,0x3
0x4a291a  7426  je     0x4a2942
0x4a291c  83f904  cmp    ecx,0x4
0x4a291f  755c  jne    0x4a297d
0x4a2921  8b30  mov    esi,DWORD PTR [eax]
0x4a2923  83c610  add    esi,0x10
0x4a2926  8d7df4  lea    edi,[ebp-0xc]
0x4a2929  e8324e2500  call   0x6f7760
0x4a292e  85c0  test   eax,eax
0x4a2930  744b  je     0x4a297d
0x4a2932  dd45f4  fld    QWORD PTR [ebp-0xc]
0x4a2935  c745dc03000000  mov    DWORD PTR [ebp-0x24],0x3
0x4a293c  dd5dd4  fstp   QWORD PTR [ebp-0x2c]
0x4a293f  8d45d4  lea    eax,[ebp-0x2c]
0x4a2942  dd00  fld    QWORD PTR [eax]
0x4a2944  dd5ddc  fstp   QWORD PTR [ebp-0x24]
0x4a2947  dd45dc  fld    QWORD PTR [ebp-0x24]
0x4a294a  db5df8  fistp  DWORD PTR [ebp-0x8]
0x4a294d  8b45f8  mov    eax,DWORD PTR [ebp-0x8]
0x4a2950  8b4df0  mov    ecx,DWORD PTR [ebp-0x10]
0x4a2953  8b55ec  mov    edx,DWORD PTR [ebp-0x14]
0x4a2956  51  push   ecx
0x4a2957  8b4de4  mov    ecx,DWORD PTR [ebp-0x1c]
0x4a295a  52  push   edx
0x4a295b  50  push   eax
0x4a295c  ff550c  call   DWORD PTR [ebp+0xc]
0x4a295f  5f  pop    edi
0x4a2960  5e  pop    esi
0x4a2961  33c0  xor    eax,eax
0x4a2963  5b  pop    ebx
0x4a2964  8be5  mov    esp,ebp
0x4a2966  5d  pop    ebp
0x4a2967  c3  ret
0x4a2968  c745f000000000  mov    DWORD PTR [ebp-0x10],0x0
0x4a296f  e941ffffff  jmp    0x4a28b5
0x4a2974  c745ec00000000  mov    DWORD PTR [ebp-0x14],0x0
0x4a297b  eb8b  jmp    0x4a2908
0x4a297d  33c0  xor    eax,eax
0x4a297f  ebcf  jmp    0x4a2950

; resolution_parameters 0x6dedf0..0x6defbc render owner parameter stores
0x6dedf0  55  push   ebp
0x6dedf1  8bec  mov    ebp,esp
0x6dedf3  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6dedf8  85c0  test   eax,eax
0x6dedfa  751f  jne    0x6dee1b
0x6dedfc  6880130000  push   0x1380
0x6dee01  e862241b00  call   0x891268
0x6dee06  83c404  add    esp,0x4
0x6dee09  85c0  test   eax,eax
0x6dee0b  7407  je     0x6dee14
0x6dee0d  e8be050000  call   0x6df3d0
0x6dee12  eb02  jmp    0x6dee16
0x6dee14  33c0  xor    eax,eax
0x6dee16  a3cca7fb00  mov    ds:0xfba7cc,eax
0x6dee1b  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6dee22  53  push   ebx
0x6dee23  8b1d4c22bd00  mov    ebx,DWORD PTR ds:0xbd224c
0x6dee29  56  push   esi
0x6dee2a  57  push   edi
0x6dee2b  8bf0  mov    esi,eax
0x6dee2d  740c  je     0x6dee3b
0x6dee2f  68c8a4fb00  push   0xfba4c8
0x6dee34  ffd3  call   ebx
0x6dee36  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6dee3b  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6dee42  8b4d08  mov    ecx,DWORD PTR [ebp+0x8]
0x6dee45  8b3d4822bd00  mov    edi,DWORD PTR ds:0xbd2248
0x6dee4b  898e38030000  mov    DWORD PTR [esi+0x338],ecx
0x6dee51  740c  je     0x6dee5f
0x6dee53  68c8a4fb00  push   0xfba4c8
0x6dee58  ffd7  call   edi
0x6dee5a  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6dee5f  85c0  test   eax,eax
0x6dee61  751f  jne    0x6dee82
0x6dee63  6880130000  push   0x1380
0x6dee68  e8fb231b00  call   0x891268
0x6dee6d  83c404  add    esp,0x4
0x6dee70  85c0  test   eax,eax
0x6dee72  7407  je     0x6dee7b
0x6dee74  e857050000  call   0x6df3d0
0x6dee79  eb02  jmp    0x6dee7d
0x6dee7b  33c0  xor    eax,eax
0x6dee7d  a3cca7fb00  mov    ds:0xfba7cc,eax
0x6dee82  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6dee89  8bf0  mov    esi,eax
0x6dee8b  740c  je     0x6dee99
0x6dee8d  68c8a4fb00  push   0xfba4c8
0x6dee92  ffd3  call   ebx
0x6dee94  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6dee99  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6deea0  8b550c  mov    edx,DWORD PTR [ebp+0xc]
0x6deea3  89963c030000  mov    DWORD PTR [esi+0x33c],edx
0x6deea9  740c  je     0x6deeb7
0x6deeab  68c8a4fb00  push   0xfba4c8
0x6deeb0  ffd7  call   edi
0x6deeb2  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6deeb7  85c0  test   eax,eax
0x6deeb9  751f  jne    0x6deeda
0x6deebb  6880130000  push   0x1380
0x6deec0  e8a3231b00  call   0x891268
0x6deec5  83c404  add    esp,0x4
0x6deec8  85c0  test   eax,eax
0x6deeca  7407  je     0x6deed3
0x6deecc  e8ff040000  call   0x6df3d0
0x6deed1  eb02  jmp    0x6deed5
0x6deed3  33c0  xor    eax,eax
0x6deed5  a3cca7fb00  mov    ds:0xfba7cc,eax
0x6deeda  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6deee1  8bf0  mov    esi,eax
0x6deee3  740c  je     0x6deef1
0x6deee5  68c8a4fb00  push   0xfba4c8
0x6deeea  ffd3  call   ebx
0x6deeec  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6deef1  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6deef8  8b4d10  mov    ecx,DWORD PTR [ebp+0x10]
0x6deefb  898e40030000  mov    DWORD PTR [esi+0x340],ecx
0x6def01  740c  je     0x6def0f
0x6def03  68c8a4fb00  push   0xfba4c8
0x6def08  ffd7  call   edi
0x6def0a  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6def0f  85c0  test   eax,eax
0x6def11  751f  jne    0x6def32
0x6def13  6880130000  push   0x1380
0x6def18  e84b231b00  call   0x891268
0x6def1d  83c404  add    esp,0x4
0x6def20  85c0  test   eax,eax
0x6def22  7407  je     0x6def2b
0x6def24  e8a7040000  call   0x6df3d0
0x6def29  eb02  jmp    0x6def2d
0x6def2b  33c0  xor    eax,eax
0x6def2d  a3cca7fb00  mov    ds:0xfba7cc,eax
0x6def32  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6def39  8bf0  mov    esi,eax
0x6def3b  740c  je     0x6def49
0x6def3d  68c8a4fb00  push   0xfba4c8
0x6def42  ffd3  call   ebx
0x6def44  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6def49  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6def50  8b5508  mov    edx,DWORD PTR [ebp+0x8]
0x6def53  89967c010000  mov    DWORD PTR [esi+0x17c],edx
0x6def59  740c  je     0x6def67
0x6def5b  68c8a4fb00  push   0xfba4c8
0x6def60  ffd7  call   edi
0x6def62  a1cca7fb00  mov    eax,ds:0xfba7cc
0x6def67  85c0  test   eax,eax
0x6def69  751f  jne    0x6def8a
0x6def6b  6880130000  push   0x1380
0x6def70  e8f3221b00  call   0x891268
0x6def75  83c404  add    esp,0x4
0x6def78  85c0  test   eax,eax
0x6def7a  7407  je     0x6def83
0x6def7c  e84f040000  call   0x6df3d0
0x6def81  eb02  jmp    0x6def85
0x6def83  33c0  xor    eax,eax
0x6def85  a3cca7fb00  mov    ds:0xfba7cc,eax
0x6def8a  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6def91  8bf0  mov    esi,eax
0x6def93  7407  je     0x6def9c
0x6def95  68c8a4fb00  push   0xfba4c8
0x6def9a  ffd3  call   ebx
0x6def9c  803d093dd60000  cmp    BYTE PTR ds:0xd63d09,0x0
0x6defa3  8b450c  mov    eax,DWORD PTR [ebp+0xc]
0x6defa6  898680010000  mov    DWORD PTR [esi+0x180],eax
0x6defac  7407  je     0x6defb5
0x6defae  68c8a4fb00  push   0xfba4c8
0x6defb3  ffd7  call   edi
0x6defb5  5f  pop    edi
0x6defb6  5e  pop    esi
0x6defb7  5b  pop    ebx
0x6defb8  5d  pop    ebp
0x6defb9  c20c00  ret    0xc

; hide_ui_closure 0x4ac400..0x4ac456 fixed zero-argument public target
0x4ac400  55  push   ebp
0x4ac401  8bec  mov    ebp,esp
0x4ac403  6aff  push   0xffffffff
0x4ac405  68c8839300  push   0x9383c8
0x4ac40a  64a100000000  mov    eax,fs:0x0
0x4ac410  50  push   eax
0x4ac411  83ec0c  sub    esp,0xc
0x4ac414  a1201fd600  mov    eax,ds:0xd61f20
0x4ac419  33c5  xor    eax,ebp
0x4ac41b  50  push   eax
0x4ac41c  8d45f4  lea    eax,[ebp-0xc]
0x4ac41f  64a300000000  mov    fs:0x0,eax
0x4ac425  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4ac428  8945e8  mov    DWORD PTR [ebp-0x18],eax
0x4ac42b  33c0  xor    eax,eax
0x4ac42d  8945ec  mov    DWORD PTR [ebp-0x14],eax
0x4ac430  8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4ac433  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x4ac436  8b0d0418fe00  mov    ecx,DWORD PTR ds:0xfe1804
0x4ac43c  ff154018fe00  call   DWORD PTR ds:0xfe1840
0x4ac442  b801000000  mov    eax,0x1
0x4ac447  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4ac44a  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4ac451  59  pop    ecx
0x4ac452  8be5  mov    esp,ebp
0x4ac454  5d  pop    ebp
0x4ac455  c3  ret

; hide_ui 0x4a99d0..0x4a9ad5 empty exclusion set passed to current-page hide operation
0x4a99d0  55  push   ebp
0x4a99d1  8bec  mov    ebp,esp
0x4a99d3  83e4f8  and    esp,0xfffffff8
0x4a99d6  6aff  push   0xffffffff
0x4a99d8  68204f9200  push   0x924f20
0x4a99dd  64a100000000  mov    eax,fs:0x0
0x4a99e3  50  push   eax
0x4a99e4  83ec24  sub    esp,0x24
0x4a99e7  53  push   ebx
0x4a99e8  56  push   esi
0x4a99e9  a1201fd600  mov    eax,ds:0xd61f20
0x4a99ee  33c4  xor    eax,esp
0x4a99f0  50  push   eax
0x4a99f1  8d442430  lea    eax,[esp+0x30]
0x4a99f5  64a300000000  mov    fs:0x0,eax
0x4a99fb  33db  xor    ebx,ebx
0x4a99fd  6a14  push   0x14
0x4a99ff  895c2428  mov    DWORD PTR [esp+0x28],ebx
0x4a9a03  e860783e00  call   0x891268
0x4a9a08  83c404  add    esp,0x4
0x4a9a0b  3bc3  cmp    eax,ebx
0x4a9a0d  0f8499000000  je     0x4a9aac
0x4a9a13  89442420  mov    DWORD PTR [esp+0x20],eax
0x4a9a17  8900  mov    DWORD PTR [eax],eax
0x4a9a19  8b442420  mov    eax,DWORD PTR [esp+0x20]
0x4a9a1d  894004  mov    DWORD PTR [eax+0x4],eax
0x4a9a20  8b442420  mov    eax,DWORD PTR [esp+0x20]
0x4a9a24  894008  mov    DWORD PTR [eax+0x8],eax
0x4a9a27  8b4c2420  mov    ecx,DWORD PTR [esp+0x20]
0x4a9a2b  b801000000  mov    eax,0x1
0x4a9a30  884110  mov    BYTE PTR [ecx+0x10],al
0x4a9a33  8b542420  mov    edx,DWORD PTR [esp+0x20]
0x4a9a37  884211  mov    BYTE PTR [edx+0x11],al
0x4a9a3a  895c2438  mov    DWORD PTR [esp+0x38],ebx
0x4a9a3e  8405d4adfa00  test   BYTE PTR ds:0xfaadd4,al
0x4a9a44  7520  jne    0x4a9a66
0x4a9a46  0905d4adfa00  or     DWORD PTR ds:0xfaadd4,eax
0x4a9a4c  88442438  mov    BYTE PTR [esp+0x38],al
0x4a9a50  e82bda0d00  call   0x587480
0x4a9a55  68c0ccbc00  push   0xbcccc0
0x4a9a5a  e8bb883e00  call   0x89231a
0x4a9a5f  83c404  add    esp,0x4
0x4a9a62  885c2438  mov    BYTE PTR [esp+0x38],bl
0x4a9a66  8d44241c  lea    eax,[esp+0x1c]
0x4a9a6a  50  push   eax
0x4a9a6b  e8e0190e00  call   0x58b450
0x4a9a70  c744243802000000  mov    DWORD PTR [esp+0x38],0x2
0x4a9a78  8b442420  mov    eax,DWORD PTR [esp+0x20]
0x4a9a7c  8b08  mov    ecx,DWORD PTR [eax]
0x4a9a7e  50  push   eax
0x4a9a7f  51  push   ecx
0x4a9a80  8d742414  lea    esi,[esp+0x14]
0x4a9a84  8d442424  lea    eax,[esp+0x24]
0x4a9a88  e8d3060200  call   0x4ca160
0x4a9a8d  8b4c2420  mov    ecx,DWORD PTR [esp+0x20]
0x4a9a91  51  push   ecx
0x4a9a92  e875773e00  call   0x89120c
0x4a9a97  83c404  add    esp,0x4
0x4a9a9a  8b4c2430  mov    ecx,DWORD PTR [esp+0x30]
0x4a9a9e  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a9aa5  59  pop    ecx
0x4a9aa6  5e  pop    esi
0x4a9aa7  5b  pop    ebx
0x4a9aa8  8be5  mov    esp,ebp
0x4a9aaa  5d  pop    ebp
0x4a9aab  c3  ret
0x4a9aac  8d54240c  lea    edx,[esp+0xc]
0x4a9ab0  52  push   edx
0x4a9ab1  8d4c2414  lea    ecx,[esp+0x14]
0x4a9ab5  895c2410  mov    DWORD PTR [esp+0x10],ebx
0x4a9ab9  e8eb753e00  call   0x8910a9
0x4a9abe  68a857c800  push   0xc857a8
0x4a9ac3  8d442414  lea    eax,[esp+0x14]
0x4a9ac7  50  push   eax
0x4a9ac8  c7442418a42cbd00  mov    DWORD PTR [esp+0x18],0xbd2ca4
0x4a9ad0  e81b2f3f00  call   0x89c9f0

; hide_ui_cast 0x58b450..0x58b502 current page must pass cast id 55000
0x58b450  55  push   ebp
0x58b451  8bec  mov    ebp,esp
0x58b453  6aff  push   0xffffffff
0x58b455  68be699100  push   0x9169be
0x58b45a  64a100000000  mov    eax,fs:0x0
0x58b460  50  push   eax
0x58b461  56  push   esi
0x58b462  a1201fd600  mov    eax,ds:0xd61f20
0x58b467  33c5  xor    eax,ebp
0x58b469  50  push   eax
0x58b46a  8d45f4  lea    eax,[ebp-0xc]
0x58b46d  64a300000000  mov    fs:0x0,eax
0x58b473  b801000000  mov    eax,0x1
0x58b478  8405d0adfa00  test   BYTE PTR ds:0xfaadd0,al
0x58b47e  7526  jne    0x58b4a6
0x58b480  0905d0adfa00  or     DWORD PTR ds:0xfaadd0,eax
0x58b486  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x58b48d  e8fe241c00  call   0x74d990
0x58b492  6870ccbc00  push   0xbccc70
0x58b497  e87e6e3000  call   0x89231a
0x58b49c  83c404  add    esp,0x4
0x58b49f  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x58b4a6  8b0dd45bf900  mov    ecx,DWORD PTR ds:0xf95bd4
0x58b4ac  8bf1  mov    esi,ecx
0x58b4ae  85c9  test   ecx,ecx
0x58b4b0  743e  je     0x58b4f0
0x58b4b2  8b01  mov    eax,DWORD PTR [ecx]
0x58b4b4  8b5004  mov    edx,DWORD PTR [eax+0x4]
0x58b4b7  ffd2  call   edx
0x58b4b9  3dd8d60000  cmp    eax,0xd6d8
0x58b4be  7426  je     0x58b4e6
0x58b4c0  6a00  push   0x0
0x58b4c2  68c01fbf00  push   0xbf1fc0
0x58b4c7  681821bf00  push   0xbf2118
0x58b4cc  6a00  push   0x0
0x58b4ce  ff158025bd00  call   DWORD PTR ds:0xbd2580
0x58b4d4  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x58b4d7  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x58b4de  59  pop    ecx
0x58b4df  5e  pop    esi
0x58b4e0  8be5  mov    esp,ebp
0x58b4e2  5d  pop    ebp
0x58b4e3  c20400  ret    0x4
0x58b4e6  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x58b4e9  50  push   eax
0x58b4ea  56  push   esi
0x58b4eb  e800b40000  call   0x5968f0
0x58b4f0  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x58b4f3  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x58b4fa  59  pop    ecx
0x58b4fb  5e  pop    esi
0x58b4fc  8be5  mov    esp,ebp
0x58b4fe  5d  pop    ebp
0x58b4ff  c20400  ret    0x4

; hide_ui_consumer 0x5968f0..0x596a61 visible children not in set: record key then virtual visibility(0)
0x5968f0  55  push   ebp
0x5968f1  8bec  mov    ebp,esp
0x5968f3  6aff  push   0xffffffff
0x5968f5  6836689100  push   0x916836
0x5968fa  64a100000000  mov    eax,fs:0x0
0x596900  50  push   eax
0x596901  83ec24  sub    esp,0x24
0x596904  53  push   ebx
0x596905  56  push   esi
0x596906  57  push   edi
0x596907  a1201fd600  mov    eax,ds:0xd61f20
0x59690c  33c5  xor    eax,ebp
0x59690e  50  push   eax
0x59690f  8d45f4  lea    eax,[ebp-0xc]
0x596912  64a300000000  mov    fs:0x0,eax
0x596918  f605d0adfa0001  test   BYTE PTR ds:0xfaadd0,0x1
0x59691f  7527  jne    0x596948
0x596921  830dd0adfa0001  or     DWORD PTR ds:0xfaadd0,0x1
0x596928  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x59692f  e85c701b00  call   0x74d990
0x596934  6870ccbc00  push   0xbccc70
0x596939  e8dcb92f00  call   0x89231a
0x59693e  83c404  add    esp,0x4
0x596941  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x596948  b81048f900  mov    eax,0xf94810
0x59694d  e8cecb1b00  call   0x753520
0x596952  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x596955  83c064  add    eax,0x64
0x596958  50  push   eax
0x596959  8d4dd0  lea    ecx,[ebp-0x30]
0x59695c  51  push   ecx
0x59695d  e85eeff9ff  call   0x5358c0
0x596962  c745fc01000000  mov    DWORD PTR [ebp-0x4],0x1
0x596969  8b45d0  mov    eax,DWORD PTR [ebp-0x30]
0x59696c  8b38  mov    edi,DWORD PTR [eax]
0x59696e  8945e4  mov    DWORD PTR [ebp-0x1c],eax
0x596971  3bf8  cmp    edi,eax
0x596973  0f849f000000  je     0x596a18
0x596979  8da42400000000  lea    esp,[esp+0x0]
0x596980  8b450c  mov    eax,DWORD PTR [ebp+0xc]
0x596983  8b4804  mov    ecx,DWORD PTR [eax+0x4]
0x596986  8b5f08  mov    ebx,DWORD PTR [edi+0x8]
0x596989  8b4104  mov    eax,DWORD PTR [ecx+0x4]
0x59698c  80781100  cmp    BYTE PTR [eax+0x11],0x0
0x596990  8b5320  mov    edx,DWORD PTR [ebx+0x20]
0x596993  8955e8  mov    DWORD PTR [ebp-0x18],edx
0x596996  8bf1  mov    esi,ecx
0x596998  751a  jne    0x5969b4
0x59699a  8d9b00000000  lea    ebx,[ebx+0x0]
0x5969a0  39500c  cmp    DWORD PTR [eax+0xc],edx
0x5969a3  7305  jae    0x5969aa
0x5969a5  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x5969a8  eb04  jmp    0x5969ae
0x5969aa  8bf0  mov    esi,eax
0x5969ac  8b00  mov    eax,DWORD PTR [eax]
0x5969ae  80781100  cmp    BYTE PTR [eax+0x11],0x0
0x5969b2  74ec  je     0x5969a0
0x5969b4  8b450c  mov    eax,DWORD PTR [ebp+0xc]
0x5969b7  8b4004  mov    eax,DWORD PTR [eax+0x4]
0x5969ba  8975f0  mov    DWORD PTR [ebp-0x10],esi
0x5969bd  3bf0  cmp    esi,eax
0x5969bf  740a  je     0x5969cb
0x5969c1  3b560c  cmp    edx,DWORD PTR [esi+0xc]
0x5969c4  7205  jb     0x5969cb
0x5969c6  8d45f0  lea    eax,[ebp-0x10]
0x5969c9  eb06  jmp    0x5969d1
0x5969cb  8945ec  mov    DWORD PTR [ebp-0x14],eax
0x5969ce  8d45ec  lea    eax,[ebp-0x14]
0x5969d1  3908  cmp    DWORD PTR [eax],ecx
0x5969d3  7535  jne    0x596a0a
0x5969d5  8b4b28  mov    ecx,DWORD PTR [ebx+0x28]
0x5969d8  c1e908  shr    ecx,0x8
0x5969db  f6c101  test   cl,0x1
0x5969de  742a  je     0x596a0a
0x5969e0  8b7508  mov    esi,DWORD PTR [ebp+0x8]
0x5969e3  8d55e8  lea    edx,[ebp-0x18]
0x5969e6  81c6a0000000  add    esi,0xa0
0x5969ec  52  push   edx
0x5969ed  e84e741200  call   0x6bde40
0x5969f2  50  push   eax
0x5969f3  56  push   esi
0x5969f4  8d75dc  lea    esi,[ebp-0x24]
0x5969f7  e8d451ebff  call   0x44bbd0
0x5969fc  8b03  mov    eax,DWORD PTR [ebx]
0x5969fe  8b9094000000  mov    edx,DWORD PTR [eax+0x94]
0x596a04  6a00  push   0x0
0x596a06  8bcb  mov    ecx,ebx
0x596a08  ffd2  call   edx
0x596a0a  8b3f  mov    edi,DWORD PTR [edi]
0x596a0c  3b7de4  cmp    edi,DWORD PTR [ebp-0x1c]
0x596a0f  0f856bffffff  jne    0x596980
0x596a15  8b45d0  mov    eax,DWORD PTR [ebp-0x30]
0x596a18  8b08  mov    ecx,DWORD PTR [eax]
0x596a1a  8900  mov    DWORD PTR [eax],eax
0x596a1c  8b45d0  mov    eax,DWORD PTR [ebp-0x30]
0x596a1f  894004  mov    DWORD PTR [eax+0x4],eax
0x596a22  8b45d0  mov    eax,DWORD PTR [ebp-0x30]
0x596a25  c745d400000000  mov    DWORD PTR [ebp-0x2c],0x0
0x596a2c  3bc8  cmp    ecx,eax
0x596a2e  7414  je     0x596a44
0x596a30  8b31  mov    esi,DWORD PTR [ecx]
0x596a32  51  push   ecx
0x596a33  e8d4a72f00  call   0x89120c
0x596a38  8b45d0  mov    eax,DWORD PTR [ebp-0x30]
0x596a3b  83c404  add    esp,0x4
0x596a3e  8bce  mov    ecx,esi
0x596a40  3bf0  cmp    esi,eax
0x596a42  75ec  jne    0x596a30
0x596a44  50  push   eax
0x596a45  e8c2a72f00  call   0x89120c
0x596a4a  83c404  add    esp,0x4
0x596a4d  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x596a50  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x596a57  59  pop    ecx
0x596a58  5f  pop    edi
0x596a59  5e  pop    esi
0x596a5a  5b  pop    ebx
0x596a5b  8be5  mov    esp,ebp
0x596a5d  5d  pop    ebp
0x596a5e  c20800  ret    0x8

; tutorial_page 0x4a9ae0..0x4a9b6a fixed pending page 15 or same-page refresh
0x4a9ae0  55  push   ebp
0x4a9ae1  8bec  mov    ebp,esp
0x4a9ae3  6aff  push   0xffffffff
0x4a9ae5  689e4d9200  push   0x924d9e
0x4a9aea  64a100000000  mov    eax,fs:0x0
0x4a9af0  50  push   eax
0x4a9af1  a1201fd600  mov    eax,ds:0xd61f20
0x4a9af6  33c5  xor    eax,ebp
0x4a9af8  50  push   eax
0x4a9af9  8d45f4  lea    eax,[ebp-0xc]
0x4a9afc  64a300000000  mov    fs:0x0,eax
0x4a9b02  b801000000  mov    eax,0x1
0x4a9b07  8405d4adfa00  test   BYTE PTR ds:0xfaadd4,al
0x4a9b0d  7526  jne    0x4a9b35
0x4a9b0f  0905d4adfa00  or     DWORD PTR ds:0xfaadd4,eax
0x4a9b15  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x4a9b1c  e85fd90d00  call   0x587480
0x4a9b21  68c0ccbc00  push   0xbcccc0
0x4a9b26  e8ef873e00  call   0x89231a
0x4a9b2b  83c404  add    esp,0x4
0x4a9b2e  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a9b35  b80f000000  mov    eax,0xf
0x4a9b3a  3905ecadfa00  cmp    DWORD PTR ds:0xfaadec,eax
0x4a9b40  7414  je     0x4a9b56
0x4a9b42  a3f0adfa00  mov    ds:0xfaadf0,eax
0x4a9b47  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a9b4a  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a9b51  59  pop    ecx
0x4a9b52  8be5  mov    esp,ebp
0x4a9b54  5d  pop    ebp
0x4a9b55  c3  ret
0x4a9b56  e8450e0e00  call   0x58a9a0
0x4a9b5b  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a9b5e  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a9b65  59  pop    ecx
0x4a9b66  8be5  mov    esp,ebp
0x4a9b68  5d  pop    ebp
0x4a9b69  c3  ret

; same_page_refresh 0x58a9a0..0x58aa48 build and enqueue fixed event F4355
0x58a9a0  55  push   ebp
0x58a9a1  8bec  mov    ebp,esp
0x58a9a3  6aff  push   0xffffffff
0x58a9a5  68ee699100  push   0x9169ee
0x58a9aa  64a100000000  mov    eax,fs:0x0
0x58a9b0  50  push   eax
0x58a9b1  51  push   ecx
0x58a9b2  56  push   esi
0x58a9b3  a1201fd600  mov    eax,ds:0xd61f20
0x58a9b8  33c5  xor    eax,ebp
0x58a9ba  50  push   eax
0x58a9bb  8d45f4  lea    eax,[ebp-0xc]
0x58a9be  64a300000000  mov    fs:0x0,eax
0x58a9c4  6a14  push   0x14
0x58a9c6  e89d683000  call   0x891268
0x58a9cb  33c9  xor    ecx,ecx
0x58a9cd  83c404  add    esp,0x4
0x58a9d0  3bc1  cmp    eax,ecx
0x58a9d2  7422  je     0x58a9f6
0x58a9d4  c7000c7bc400  mov    DWORD PTR [eax],0xc47b0c
0x58a9da  c74004ffffffff  mov    DWORD PTR [eax+0x4],0xffffffff
0x58a9e1  c74008ffffffff  mov    DWORD PTR [eax+0x8],0xffffffff
0x58a9e8  89480c  mov    DWORD PTR [eax+0xc],ecx
0x58a9eb  c7401055430f00  mov    DWORD PTR [eax+0x10],0xf4355
0x58a9f2  8bf0  mov    esi,eax
0x58a9f4  eb02  jmp    0x58a9f8
0x58a9f6  33f6  xor    esi,esi
0x58a9f8  b801000000  mov    eax,0x1
0x58a9fd  8405d0adfa00  test   BYTE PTR ds:0xfaadd0,al
0x58aa03  7522  jne    0x58aa27
0x58aa05  0905d0adfa00  or     DWORD PTR ds:0xfaadd0,eax
0x58aa0b  894dfc  mov    DWORD PTR [ebp-0x4],ecx
0x58aa0e  e87d2f1c00  call   0x74d990
0x58aa13  6870ccbc00  push   0xbccc70
0x58aa18  e8fd783000  call   0x89231a
0x58aa1d  83c404  add    esp,0x4
0x58aa20  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x58aa27  8d45f0  lea    eax,[ebp-0x10]
0x58aa2a  8975f0  mov    DWORD PTR [ebp-0x10],esi
0x58aa2d  50  push   eax
0x58aa2e  be6c5cf900  mov    esi,0xf95c6c
0x58aa33  e828982700  call   0x804260
0x58aa38  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x58aa3b  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x58aa42  59  pop    ecx
0x58aa43  5e  pop    esi
0x58aa44  8be5  mov    esp,ebp
0x58aa46  5d  pop    ebp
0x58aa47  c3  ret

; synopsis_getter 0x4a9320..0x4a9326 read tracked synopsis skip flag
0x4a9320  a1a0a7fb00  mov    eax,ds:0xfba7a0
0x4a9325  c3  ret

; synopsis_reset_entry 0x4a89c0..0x4a8a5e tutorial entry resets skip state, loads TutorialMain and entry
0x4a89c0  55  push   ebp
0x4a89c1  8bec  mov    ebp,esp
0x4a89c3  6aff  push   0xffffffff
0x4a89c5  687ea49300  push   0x93a47e
0x4a89ca  64a100000000  mov    eax,fs:0x0
0x4a89d0  50  push   eax
0x4a89d1  57  push   edi
0x4a89d2  a1201fd600  mov    eax,ds:0xd61f20
0x4a89d7  33c5  xor    eax,ebp
0x4a89d9  50  push   eax
0x4a89da  8d45f4  lea    eax,[ebp-0xc]
0x4a89dd  64a300000000  mov    fs:0x0,eax
0x4a89e3  8d7e14  lea    edi,[esi+0x14]
0x4a89e6  c705a0a7fb0000000000  mov    DWORD PTR ds:0xfba7a0,0x0
0x4a89f0  e82b8a3a00  call   0x851420
0x4a89f5  f6055473fb0001  test   BYTE PTR ds:0xfb7354,0x1
0x4a89fc  7527  jne    0x4a8a25
0x4a89fe  830d5473fb0001  or     DWORD PTR ds:0xfb7354,0x1
0x4a8a05  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x4a8a0c  e8bfa90a00  call   0x5533d0
0x4a8a11  6800d1bc00  push   0xbcd100
0x4a8a16  e8ff983e00  call   0x89231a
0x4a8a1b  83c404  add    esp,0x4
0x4a8a1e  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a8a25  c705b473fb0001000000  mov    DWORD PTR ds:0xfb73b4,0x1
0x4a8a2f  8b0e  mov    ecx,DWORD PTR [esi]
0x4a8a31  687c68c000  push   0xc0687c
0x4a8a36  e815c02400  call   0x6f4a50
0x4a8a3b  8b06  mov    eax,DWORD PTR [esi]
0x4a8a3d  6a00  push   0x0
0x4a8a3f  6a00  push   0x0
0x4a8a41  689468c000  push   0xc06894
0x4a8a46  e885c32400  call   0x6f4dd0
0x4a8a4b  83c40c  add    esp,0xc
0x4a8a4e  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a8a51  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a8a58  59  pop    ecx
0x4a8a59  5f  pop    edi
0x4a8a5a  8be5  mov    esp,ebp
0x4a8a5c  5d  pop    ebp
0x4a8a5d  c3  ret

; scenario_request 0x4aa4d0..0x4aa509 four-byte C2S0040 request, low WORD key, disconnected suppression
0x4aa4d0  55  push   ebp
0x4aa4d1  8bec  mov    ebp,esp
0x4aa4d3  51  push   ecx
0x4aa4d4  833d98a7fb0000  cmp    DWORD PTR ds:0xfba798,0x0
0x4aa4db  668b4d08  mov    cx,WORD PTR [ebp+0x8]
0x4aa4df  b840000000  mov    eax,0x40
0x4aa4e4  668945fc  mov    WORD PTR [ebp-0x4],ax
0x4aa4e8  66894dfe  mov    WORD PTR [ebp-0x2],cx
0x4aa4ec  7515  jne    0x4aa503
0x4aa4ee  8b0d54a8fb00  mov    ecx,DWORD PTR ds:0xfba854
0x4aa4f4  8b11  mov    edx,DWORD PTR [ecx]
0x4aa4f6  8b5210  mov    edx,DWORD PTR [edx+0x10]
0x4aa4f9  6a04  push   0x4
0x4aa4fb  8d45fc  lea    eax,[ebp-0x4]
0x4aa4fe  50  push   eax
0x4aa4ff  6a00  push   0x0
0x4aa501  ffd2  call   edx
0x4aa503  8be5  mov    esp,ebp
0x4aa505  5d  pop    ebp
0x4aa506  c20400  ret    0x4

; town_marker_descriptor 0xc107b0..0xc107cc exact path fragment in the selected minimap chain
; hex 4d61702f4d696e696d61702f746f776e4d696e696d61702e6d6d6d00

; field_marker_descriptor 0xc107cc..0xc107e9 exact path fragment in the selected minimap chain
; hex 4d61702f4d696e696d61702f6669656c644d696e696d61702e6d6d6d00

; minimap_prefix 0xc107ec..0xc107f9 exact path fragment in the selected minimap chain
; hex 4d61702f4d696e696d61702f00

; minimap_suffix 0xc107fc..0xc10801 exact path fragment in the selected minimap chain
; hex 2e6d6d7400

; minimap_root 0xc10850..0xc10858 exact path fragment in the selected minimap chain
; hex 4d696e696d617000

; minimap_worldsize 0xc10858..0xc10862 exact path fragment in the selected minimap chain
; hex 576f726c6453697a6500

; minimap_texture 0xc10864..0xc10870 exact path fragment in the selected minimap chain
; hex 5465787475726546696c6500

; registrar_lb_SetDebugLevel 0x4a15b0..0x4a1649 normal static registration for lb.SetDebugLevel
0x4a15b0  55  push   ebp
0x4a15b1  8bec  mov    ebp,esp
0x4a15b3  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a15b6  53  push   ebx
0x4a15b7  8b1d7417fe00  mov    ebx,DWORD PTR ds:0xfe1774
0x4a15bd  56  push   esi
0x4a15be  8b33  mov    esi,DWORD PTR [ebx]
0x4a15c0  57  push   edi
0x4a15c1  8b38  mov    edi,DWORD PTR [eax]
0x4a15c3  b8eed8ffff  mov    eax,0xffffd8ee
0x4a15c8  c7057c17fe00a00a4a00  mov    DWORD PTR ds:0xfe177c,0x4a0aa0
0x4a15d2  e8a9402500  call   0x6f5680
0x4a15d7  8b03  mov    eax,DWORD PTR [ebx]
0x4a15d9  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4a15dc  83e810  sub    eax,0x10
0x4a15df  3dc8bfc000  cmp    eax,0xc0bfc8
0x4a15e4  7406  je     0x4a15ec
0x4a15e6  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4a15ea  7414  je     0x4a1600
0x4a15ec  57  push   edi
0x4a15ed  68c426c400  push   0xc426c4
0x4a15f2  e8c61a3f00  call   0x8930bd
0x4a15f7  8b1b  mov    ebx,DWORD PTR [ebx]
0x4a15f9  83c408  add    esp,0x8
0x4a15fc  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a1600  8b3d7417fe00  mov    edi,DWORD PTR ds:0xfe1774
0x4a1606  8b37  mov    esi,DWORD PTR [edi]
0x4a1608  6890add600  push   0xd6ad90
0x4a160d  e8fe3e2500  call   0x6f5510
0x4a1612  8b37  mov    esi,DWORD PTR [edi]
0x4a1614  83c404  add    esp,0x4
0x4a1617  6a00  push   0x0
0x4a1619  68901e4a00  push   0x4a1e90
0x4a161e  e88d3f2500  call   0x6f55b0
0x4a1623  8b0f  mov    ecx,DWORD PTR [edi]
0x4a1625  51  push   ecx
0x4a1626  b8fdffffff  mov    eax,0xfffffffd
0x4a162b  e8c0412500  call   0x6f57f0
0x4a1630  8b157417fe00  mov    edx,DWORD PTR ds:0xfe1774
0x4a1636  8b02  mov    eax,DWORD PTR [edx]
0x4a1638  83c40c  add    esp,0xc
0x4a163b  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4a163f  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1642  5f  pop    edi
0x4a1643  5e  pop    esi
0x4a1644  5b  pop    ebx
0x4a1645  5d  pop    ebp
0x4a1646  c20400  ret    0x4

; registrar_lb_GetTime 0x4a1ab0..0x4a1b49 normal static registration for lb.GetTime
0x4a1ab0  55  push   ebp
0x4a1ab1  8bec  mov    ebp,esp
0x4a1ab3  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1ab6  53  push   ebx
0x4a1ab7  8b1d7417fe00  mov    ebx,DWORD PTR ds:0xfe1774
0x4a1abd  56  push   esi
0x4a1abe  8b33  mov    esi,DWORD PTR [ebx]
0x4a1ac0  57  push   edi
0x4a1ac1  8b38  mov    edi,DWORD PTR [eax]
0x4a1ac3  b8eed8ffff  mov    eax,0xffffd8ee
0x4a1ac8  c7059c17fe00700b4a00  mov    DWORD PTR ds:0xfe179c,0x4a0b70
0x4a1ad2  e8a93b2500  call   0x6f5680
0x4a1ad7  8b03  mov    eax,DWORD PTR [ebx]
0x4a1ad9  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4a1adc  83e810  sub    eax,0x10
0x4a1adf  3dc8bfc000  cmp    eax,0xc0bfc8
0x4a1ae4  7406  je     0x4a1aec
0x4a1ae6  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4a1aea  7414  je     0x4a1b00
0x4a1aec  57  push   edi
0x4a1aed  68c426c400  push   0xc426c4
0x4a1af2  e8c6153f00  call   0x8930bd
0x4a1af7  8b1b  mov    ebx,DWORD PTR [ebx]
0x4a1af9  83c408  add    esp,0x8
0x4a1afc  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a1b00  8b3d7417fe00  mov    edi,DWORD PTR ds:0xfe1774
0x4a1b06  8b37  mov    esi,DWORD PTR [edi]
0x4a1b08  680caed600  push   0xd6ae0c
0x4a1b0d  e8fe392500  call   0x6f5510
0x4a1b12  8b37  mov    esi,DWORD PTR [edi]
0x4a1b14  83c404  add    esp,0x4
0x4a1b17  6a00  push   0x0
0x4a1b19  6890214a00  push   0x4a2190
0x4a1b1e  e88d3a2500  call   0x6f55b0
0x4a1b23  8b0f  mov    ecx,DWORD PTR [edi]
0x4a1b25  51  push   ecx
0x4a1b26  b8fdffffff  mov    eax,0xfffffffd
0x4a1b2b  e8c03c2500  call   0x6f57f0
0x4a1b30  8b157417fe00  mov    edx,DWORD PTR ds:0xfe1774
0x4a1b36  8b02  mov    eax,DWORD PTR [edx]
0x4a1b38  83c40c  add    esp,0xc
0x4a1b3b  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4a1b3f  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1b42  5f  pop    edi
0x4a1b43  5e  pop    esi
0x4a1b44  5b  pop    ebx
0x4a1b45  5d  pop    ebp
0x4a1b46  c20400  ret    0x4

; registrar_lb_PrintCurrSceneID 0x4a1bf0..0x4a1c89 normal static registration for lb.PrintCurrSceneID
0x4a1bf0  55  push   ebp
0x4a1bf1  8bec  mov    ebp,esp
0x4a1bf3  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1bf6  53  push   ebx
0x4a1bf7  8b1d7417fe00  mov    ebx,DWORD PTR ds:0xfe1774
0x4a1bfd  56  push   esi
0x4a1bfe  8b33  mov    esi,DWORD PTR [ebx]
0x4a1c00  57  push   edi
0x4a1c01  8b38  mov    edi,DWORD PTR [eax]
0x4a1c03  b8eed8ffff  mov    eax,0xffffd8ee
0x4a1c08  c705a417fe00105d5f00  mov    DWORD PTR ds:0xfe17a4,0x5f5d10
0x4a1c12  e8693a2500  call   0x6f5680
0x4a1c17  8b03  mov    eax,DWORD PTR [ebx]
0x4a1c19  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4a1c1c  83e810  sub    eax,0x10
0x4a1c1f  3dc8bfc000  cmp    eax,0xc0bfc8
0x4a1c24  7406  je     0x4a1c2c
0x4a1c26  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4a1c2a  7414  je     0x4a1c40
0x4a1c2c  57  push   edi
0x4a1c2d  68c426c400  push   0xc426c4
0x4a1c32  e886143f00  call   0x8930bd
0x4a1c37  8b1b  mov    ebx,DWORD PTR [ebx]
0x4a1c39  83c408  add    esp,0x8
0x4a1c3c  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a1c40  8b3d7417fe00  mov    edi,DWORD PTR ds:0xfe1774
0x4a1c46  8b37  mov    esi,DWORD PTR [edi]
0x4a1c48  681caed600  push   0xd6ae1c
0x4a1c4d  e8be382500  call   0x6f5510
0x4a1c52  8b37  mov    esi,DWORD PTR [edi]
0x4a1c54  83c404  add    esp,0x4
0x4a1c57  6a00  push   0x0
0x4a1c59  6860224a00  push   0x4a2260
0x4a1c5e  e84d392500  call   0x6f55b0
0x4a1c63  8b0f  mov    ecx,DWORD PTR [edi]
0x4a1c65  51  push   ecx
0x4a1c66  b8fdffffff  mov    eax,0xfffffffd
0x4a1c6b  e8803b2500  call   0x6f57f0
0x4a1c70  8b157417fe00  mov    edx,DWORD PTR ds:0xfe1774
0x4a1c76  8b02  mov    eax,DWORD PTR [edx]
0x4a1c78  83c40c  add    esp,0xc
0x4a1c7b  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4a1c7f  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1c82  5f  pop    edi
0x4a1c83  5e  pop    esi
0x4a1c84  5b  pop    ebx
0x4a1c85  5d  pop    ebp
0x4a1c86  c20400  ret    0x4

; registrar_lb_ChangeResolution 0x4a1c90..0x4a1d29 normal static registration for lb.ChangeResolution
0x4a1c90  55  push   ebp
0x4a1c91  8bec  mov    ebp,esp
0x4a1c93  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1c96  53  push   ebx
0x4a1c97  8b1d7417fe00  mov    ebx,DWORD PTR ds:0xfe1774
0x4a1c9d  56  push   esi
0x4a1c9e  8b33  mov    esi,DWORD PTR [ebx]
0x4a1ca0  57  push   edi
0x4a1ca1  8b38  mov    edi,DWORD PTR [eax]
0x4a1ca3  b8eed8ffff  mov    eax,0xffffd8ee
0x4a1ca8  c705a817fe0030134a00  mov    DWORD PTR ds:0xfe17a8,0x4a1330
0x4a1cb2  e8c9392500  call   0x6f5680
0x4a1cb7  8b03  mov    eax,DWORD PTR [ebx]
0x4a1cb9  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4a1cbc  83e810  sub    eax,0x10
0x4a1cbf  3dc8bfc000  cmp    eax,0xc0bfc8
0x4a1cc4  7406  je     0x4a1ccc
0x4a1cc6  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4a1cca  7414  je     0x4a1ce0
0x4a1ccc  57  push   edi
0x4a1ccd  68c426c400  push   0xc426c4
0x4a1cd2  e8e6133f00  call   0x8930bd
0x4a1cd7  8b1b  mov    ebx,DWORD PTR [ebx]
0x4a1cd9  83c408  add    esp,0x8
0x4a1cdc  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a1ce0  8b3d7417fe00  mov    edi,DWORD PTR ds:0xfe1774
0x4a1ce6  8b37  mov    esi,DWORD PTR [edi]
0x4a1ce8  6830aed600  push   0xd6ae30
0x4a1ced  e81e382500  call   0x6f5510
0x4a1cf2  8b37  mov    esi,DWORD PTR [edi]
0x4a1cf4  83c404  add    esp,0x4
0x4a1cf7  6a00  push   0x0
0x4a1cf9  68c0224a00  push   0x4a22c0
0x4a1cfe  e8ad382500  call   0x6f55b0
0x4a1d03  8b0f  mov    ecx,DWORD PTR [edi]
0x4a1d05  51  push   ecx
0x4a1d06  b8fdffffff  mov    eax,0xfffffffd
0x4a1d0b  e8e03a2500  call   0x6f57f0
0x4a1d10  8b157417fe00  mov    edx,DWORD PTR ds:0xfe1774
0x4a1d16  8b02  mov    eax,DWORD PTR [edx]
0x4a1d18  83c40c  add    esp,0xc
0x4a1d1b  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4a1d1f  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1d22  5f  pop    edi
0x4a1d23  5e  pop    esi
0x4a1d24  5b  pop    ebx
0x4a1d25  5d  pop    ebp
0x4a1d26  c20400  ret    0x4

; registrar_lb_LoadMinimap 0x4a1d30..0x4a1dc9 normal static registration for lb.LoadMinimap
0x4a1d30  55  push   ebp
0x4a1d31  8bec  mov    ebp,esp
0x4a1d33  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1d36  53  push   ebx
0x4a1d37  8b1d7417fe00  mov    ebx,DWORD PTR ds:0xfe1774
0x4a1d3d  56  push   esi
0x4a1d3e  8b33  mov    esi,DWORD PTR [ebx]
0x4a1d40  57  push   edi
0x4a1d41  8b38  mov    edi,DWORD PTR [eax]
0x4a1d43  b8eed8ffff  mov    eax,0xffffd8ee
0x4a1d48  c705ac17fe0000144a00  mov    DWORD PTR ds:0xfe17ac,0x4a1400
0x4a1d52  e829392500  call   0x6f5680
0x4a1d57  8b03  mov    eax,DWORD PTR [ebx]
0x4a1d59  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4a1d5c  83e810  sub    eax,0x10
0x4a1d5f  3dc8bfc000  cmp    eax,0xc0bfc8
0x4a1d64  7406  je     0x4a1d6c
0x4a1d66  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4a1d6a  7414  je     0x4a1d80
0x4a1d6c  57  push   edi
0x4a1d6d  68c426c400  push   0xc426c4
0x4a1d72  e846133f00  call   0x8930bd
0x4a1d77  8b1b  mov    ebx,DWORD PTR [ebx]
0x4a1d79  83c408  add    esp,0x8
0x4a1d7c  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4a1d80  8b3d7417fe00  mov    edi,DWORD PTR ds:0xfe1774
0x4a1d86  8b37  mov    esi,DWORD PTR [edi]
0x4a1d88  6844aed600  push   0xd6ae44
0x4a1d8d  e87e372500  call   0x6f5510
0x4a1d92  8b37  mov    esi,DWORD PTR [edi]
0x4a1d94  83c404  add    esp,0x4
0x4a1d97  6a00  push   0x0
0x4a1d99  6820234a00  push   0x4a2320
0x4a1d9e  e80d382500  call   0x6f55b0
0x4a1da3  8b0f  mov    ecx,DWORD PTR [edi]
0x4a1da5  51  push   ecx
0x4a1da6  b8fdffffff  mov    eax,0xfffffffd
0x4a1dab  e8403a2500  call   0x6f57f0
0x4a1db0  8b157417fe00  mov    edx,DWORD PTR ds:0xfe1774
0x4a1db6  8b02  mov    eax,DWORD PTR [edx]
0x4a1db8  83c40c  add    esp,0xc
0x4a1dbb  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4a1dbf  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a1dc2  5f  pop    edi
0x4a1dc3  5e  pop    esi
0x4a1dc4  5b  pop    ebx
0x4a1dc5  5d  pop    ebp
0x4a1dc6  c20400  ret    0x4

; registrar_Tutorial_IsSynopsisSkipped 0x4aa680..0x4aa719 normal static registration for Tutorial.IsSynopsisSkipped
0x4aa680  55  push   ebp
0x4aa681  8bec  mov    ebp,esp
0x4aa683  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4aa686  53  push   ebx
0x4aa687  8b1d0018fe00  mov    ebx,DWORD PTR ds:0xfe1800
0x4aa68d  56  push   esi
0x4aa68e  8b33  mov    esi,DWORD PTR [ebx]
0x4aa690  57  push   edi
0x4aa691  8b38  mov    edi,DWORD PTR [eax]
0x4aa693  b8eed8ffff  mov    eax,0xffffd8ee
0x4aa698  c7050818fe0020934a00  mov    DWORD PTR ds:0xfe1808,0x4a9320
0x4aa6a2  e8d9af2400  call   0x6f5680
0x4aa6a7  8b03  mov    eax,DWORD PTR [ebx]
0x4aa6a9  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4aa6ac  83e810  sub    eax,0x10
0x4aa6af  3dc8bfc000  cmp    eax,0xc0bfc8
0x4aa6b4  7406  je     0x4aa6bc
0x4aa6b6  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4aa6ba  7414  je     0x4aa6d0
0x4aa6bc  57  push   edi
0x4aa6bd  68c426c400  push   0xc426c4
0x4aa6c2  e8f6893e00  call   0x8930bd
0x4aa6c7  8b1b  mov    ebx,DWORD PTR [ebx]
0x4aa6c9  83c408  add    esp,0x8
0x4aa6cc  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4aa6d0  8b3d0018fe00  mov    edi,DWORD PTR ds:0xfe1800
0x4aa6d6  8b37  mov    esi,DWORD PTR [edi]
0x4aa6d8  6850abd600  push   0xd6ab50
0x4aa6dd  e82eae2400  call   0x6f5510
0x4aa6e2  8b37  mov    esi,DWORD PTR [edi]
0x4aa6e4  83c404  add    esp,0x4
0x4aa6e7  6a00  push   0x0
0x4aa6e9  68a0be4a00  push   0x4abea0
0x4aa6ee  e8bdae2400  call   0x6f55b0
0x4aa6f3  8b0f  mov    ecx,DWORD PTR [edi]
0x4aa6f5  51  push   ecx
0x4aa6f6  b8fdffffff  mov    eax,0xfffffffd
0x4aa6fb  e8f0b02400  call   0x6f57f0
0x4aa700  8b150018fe00  mov    edx,DWORD PTR ds:0xfe1800
0x4aa706  8b02  mov    eax,DWORD PTR [edx]
0x4aa708  83c40c  add    esp,0xc
0x4aa70b  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4aa70f  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4aa712  5f  pop    edi
0x4aa713  5e  pop    esi
0x4aa714  5b  pop    ebx
0x4aa715  5d  pop    ebp
0x4aa716  c20400  ret    0x4

; registrar_Tutorial_HideUI 0x4aaf40..0x4aafd9 normal static registration for Tutorial.HideUI
0x4aaf40  55  push   ebp
0x4aaf41  8bec  mov    ebp,esp
0x4aaf43  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4aaf46  53  push   ebx
0x4aaf47  8b1d0018fe00  mov    ebx,DWORD PTR ds:0xfe1800
0x4aaf4d  56  push   esi
0x4aaf4e  8b33  mov    esi,DWORD PTR [ebx]
0x4aaf50  57  push   edi
0x4aaf51  8b38  mov    edi,DWORD PTR [eax]
0x4aaf53  b8eed8ffff  mov    eax,0xffffd8ee
0x4aaf58  c7054018fe00d0994a00  mov    DWORD PTR ds:0xfe1840,0x4a99d0
0x4aaf62  e819a72400  call   0x6f5680
0x4aaf67  8b03  mov    eax,DWORD PTR [ebx]
0x4aaf69  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4aaf6c  83e810  sub    eax,0x10
0x4aaf6f  3dc8bfc000  cmp    eax,0xc0bfc8
0x4aaf74  7406  je     0x4aaf7c
0x4aaf76  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4aaf7a  7414  je     0x4aaf90
0x4aaf7c  57  push   edi
0x4aaf7d  68c426c400  push   0xc426c4
0x4aaf82  e836813e00  call   0x8930bd
0x4aaf87  8b1b  mov    ebx,DWORD PTR [ebx]
0x4aaf89  83c408  add    esp,0x8
0x4aaf8c  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4aaf90  8b3d0018fe00  mov    edi,DWORD PTR ds:0xfe1800
0x4aaf96  8b37  mov    esi,DWORD PTR [edi]
0x4aaf98  6858acd600  push   0xd6ac58
0x4aaf9d  e86ea52400  call   0x6f5510
0x4aafa2  8b37  mov    esi,DWORD PTR [edi]
0x4aafa4  83c404  add    esp,0x4
0x4aafa7  6a00  push   0x0
0x4aafa9  6800c44a00  push   0x4ac400
0x4aafae  e8fda52400  call   0x6f55b0
0x4aafb3  8b0f  mov    ecx,DWORD PTR [edi]
0x4aafb5  51  push   ecx
0x4aafb6  b8fdffffff  mov    eax,0xfffffffd
0x4aafbb  e830a82400  call   0x6f57f0
0x4aafc0  8b150018fe00  mov    edx,DWORD PTR ds:0xfe1800
0x4aafc6  8b02  mov    eax,DWORD PTR [edx]
0x4aafc8  83c40c  add    esp,0xc
0x4aafcb  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4aafcf  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4aafd2  5f  pop    edi
0x4aafd3  5e  pop    esi
0x4aafd4  5b  pop    ebx
0x4aafd5  5d  pop    ebp
0x4aafd6  c20400  ret    0x4

; registrar_Tutorial_SetUIPage 0x4aafe0..0x4ab079 normal static registration for Tutorial.SetUIPage
0x4aafe0  55  push   ebp
0x4aafe1  8bec  mov    ebp,esp
0x4aafe3  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4aafe6  53  push   ebx
0x4aafe7  8b1d0018fe00  mov    ebx,DWORD PTR ds:0xfe1800
0x4aafed  56  push   esi
0x4aafee  8b33  mov    esi,DWORD PTR [ebx]
0x4aaff0  57  push   edi
0x4aaff1  8b38  mov    edi,DWORD PTR [eax]
0x4aaff3  b8eed8ffff  mov    eax,0xffffd8ee
0x4aaff8  c7054418fe00e09a4a00  mov    DWORD PTR ds:0xfe1844,0x4a9ae0
0x4ab002  e879a62400  call   0x6f5680
0x4ab007  8b03  mov    eax,DWORD PTR [ebx]
0x4ab009  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4ab00c  83e810  sub    eax,0x10
0x4ab00f  3dc8bfc000  cmp    eax,0xc0bfc8
0x4ab014  7406  je     0x4ab01c
0x4ab016  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4ab01a  7414  je     0x4ab030
0x4ab01c  57  push   edi
0x4ab01d  68c426c400  push   0xc426c4
0x4ab022  e896803e00  call   0x8930bd
0x4ab027  8b1b  mov    ebx,DWORD PTR [ebx]
0x4ab029  83c408  add    esp,0x8
0x4ab02c  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4ab030  8b3d0018fe00  mov    edi,DWORD PTR ds:0xfe1800
0x4ab036  8b37  mov    esi,DWORD PTR [edi]
0x4ab038  6860acd600  push   0xd6ac60
0x4ab03d  e8cea42400  call   0x6f5510
0x4ab042  8b37  mov    esi,DWORD PTR [edi]
0x4ab044  83c404  add    esp,0x4
0x4ab047  6a00  push   0x0
0x4ab049  6860c44a00  push   0x4ac460
0x4ab04e  e85da52400  call   0x6f55b0
0x4ab053  8b0f  mov    ecx,DWORD PTR [edi]
0x4ab055  51  push   ecx
0x4ab056  b8fdffffff  mov    eax,0xfffffffd
0x4ab05b  e890a72400  call   0x6f57f0
0x4ab060  8b150018fe00  mov    edx,DWORD PTR ds:0xfe1800
0x4ab066  8b02  mov    eax,DWORD PTR [edx]
0x4ab068  83c40c  add    esp,0xc
0x4ab06b  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4ab06f  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4ab072  5f  pop    edi
0x4ab073  5e  pop    esi
0x4ab074  5b  pop    ebx
0x4ab075  5d  pop    ebp
0x4ab076  c20400  ret    0x4

; registrar_Tutorial_RequestStartScenario 0x4ab8a0..0x4ab939 normal static registration for Tutorial.RequestStartScenario
0x4ab8a0  55  push   ebp
0x4ab8a1  8bec  mov    ebp,esp
0x4ab8a3  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4ab8a6  53  push   ebx
0x4ab8a7  8b1d0018fe00  mov    ebx,DWORD PTR ds:0xfe1800
0x4ab8ad  56  push   esi
0x4ab8ae  8b33  mov    esi,DWORD PTR [ebx]
0x4ab8b0  57  push   edi
0x4ab8b1  8b38  mov    edi,DWORD PTR [eax]
0x4ab8b3  b8eed8ffff  mov    eax,0xffffd8ee
0x4ab8b8  c7057c18fe00d0a44a00  mov    DWORD PTR ds:0xfe187c,0x4aa4d0
0x4ab8c2  e8b99d2400  call   0x6f5680
0x4ab8c7  8b03  mov    eax,DWORD PTR [ebx]
0x4ab8c9  8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4ab8cc  83e810  sub    eax,0x10
0x4ab8cf  3dc8bfc000  cmp    eax,0xc0bfc8
0x4ab8d4  7406  je     0x4ab8dc
0x4ab8d6  83780805  cmp    DWORD PTR [eax+0x8],0x5
0x4ab8da  7414  je     0x4ab8f0
0x4ab8dc  57  push   edi
0x4ab8dd  68c426c400  push   0xc426c4
0x4ab8e2  e8d6773e00  call   0x8930bd
0x4ab8e7  8b1b  mov    ebx,DWORD PTR [ebx]
0x4ab8e9  83c408  add    esp,0x8
0x4ab8ec  834308f0  add    DWORD PTR [ebx+0x8],0xfffffff0
0x4ab8f0  8b3d0018fe00  mov    edi,DWORD PTR ds:0xfe1800
0x4ab8f6  8b37  mov    esi,DWORD PTR [edi]
0x4ab8f8  6868add600  push   0xd6ad68
0x4ab8fd  e80e9c2400  call   0x6f5510
0x4ab902  8b37  mov    esi,DWORD PTR [edi]
0x4ab904  83c404  add    esp,0x4
0x4ab907  6a00  push   0x0
0x4ab909  68e0c94a00  push   0x4ac9e0
0x4ab90e  e89d9c2400  call   0x6f55b0
0x4ab913  8b0f  mov    ecx,DWORD PTR [edi]
0x4ab915  51  push   ecx
0x4ab916  b8fdffffff  mov    eax,0xfffffffd
0x4ab91b  e8d09e2400  call   0x6f57f0
0x4ab920  8b150018fe00  mov    edx,DWORD PTR ds:0xfe1800
0x4ab926  8b02  mov    eax,DWORD PTR [edx]
0x4ab928  83c40c  add    esp,0xc
0x4ab92b  834008f0  add    DWORD PTR [eax+0x8],0xfffffff0
0x4ab92f  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4ab932  5f  pop    edi
0x4ab933  5e  pop    esi
0x4ab934  5b  pop    ebx
0x4ab935  5d  pop    ebp
0x4ab936  c20400  ret    0x4

