; N01 0047 signed scene pair and native Start
; REUSED kr-extra-roy/MEF-delivery-windows-20261114/native-windows.json#scene/start-0047-consumer
; VA 0x503040..0x5030bf raw 0x102440 SHA256 bb262cf90e46e985bd2ffca7af9d529db9ddb6552659ee17e9674ad05bea3a53
0x503040  55  push   ebp
0x503041  8bec  mov    ebp,esp
0x503043  6aff  push   0xffffffff
0x503045  68aeb29300  push   0x93b2ae
0x50304a  64a100000000  mov    eax,fs:0x0
0x503050  50  push   eax
0x503051  a1201fd600  mov    eax,ds:0xd61f20
0x503056  33c5  xor    eax,ebp
0x503058  50  push   eax
0x503059  8d45f4  lea    eax,[ebp-0xc]
0x50305c  64a300000000  mov    fs:0x0,eax
0x503062  b801000000  mov    eax,0x1
0x503067  8405b873fb00  test   BYTE PTR ds:0xfb73b8,al
0x50306d  7526  jne    0x503095
0x50306f  0905b873fb00  or     DWORD PTR ds:0xfb73b8,eax
0x503075  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x50307c  e8efd00500  call   0x560170
0x503081  6810d1bc00  push   0xbcd110
0x503086  e88ff23800  call   0x89231a
0x50308b  83c404  add    esp,0x4
0x50308e  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x503095  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x503098  0fbf4804  movsx  ecx,WORD PTR [eax+0x4]
0x50309c  0fbf5002  movsx  edx,WORD PTR [eax+0x2]
0x5030a0  51  push   ecx
0x5030a1  52  push   edx
0x5030a2  b9c073fb00  mov    ecx,0xfb73c0
0x5030a7  e8b4e60500  call   0x561760
0x5030ac  33c0  xor    eax,eax
0x5030ae  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x5030b1  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x5030b8  59  pop    ecx
0x5030b9  8be5  mov    esp,ebp
0x5030bb  5d  pop    ebp
0x5030bc  c20c00  ret    0xc

; N02 configured pair to literal SEQ path and prepass
; REUSED kr-extra-roy/MEF-end-to-end-20261116/entry/native-windows.json#q_start_and_skip
; VA 0x561a80..0x561af8 raw 0x160e80 SHA256 cf06ebb7b8b33bd6d7892c296abb6ab86136f1d004d4ab399cf9287246fa6d31
0x561a80  8b30  mov    esi,DWORD PTR [eax]
0x561a82  3b730c  cmp    esi,DWORD PTR [ebx+0xc]
0x561a85  0f84f4020000  je     0x561d7f
0x561a8b  6a10  push   0x10
0x561a8d  68d006c100  push   0xc106d0
0x561a92  8d4c2428  lea    ecx,[esp+0x28]
0x561a96  c744243c0f000000  mov    DWORD PTR [esp+0x3c],0xf
0x561a9e  c744243800000000  mov    DWORD PTR [esp+0x38],0x0
0x561aa6  c644242800  mov    BYTE PTR [esp+0x28],0x0
0x561aab  e8c00feaff  call   0x402a70
0x561ab0  8d4614  lea    eax,[esi+0x14]
0x561ab3  57  push   edi
0x561ab4  33f6  xor    esi,esi
0x561ab6  56  push   esi
0x561ab7  50  push   eax
0x561ab8  8d4c242c  lea    ecx,[esp+0x2c]
0x561abc  c744247407000000  mov    DWORD PTR [esp+0x74],0x7
0x561ac4  e80704eaff  call   0x401ed0
0x561ac9  6a04  push   0x4
0x561acb  68e406c100  push   0xc106e4
0x561ad0  8d4c2428  lea    ecx,[esp+0x28]
0x561ad4  e8e704eaff  call   0x401fc0
0x561ad9  837c243410  cmp    DWORD PTR [esp+0x34],0x10
0x561ade  8b442420  mov    eax,DWORD PTR [esp+0x20]
0x561ae2  7304  jae    0x561ae8
0x561ae4  8d442420  lea    eax,[esp+0x20]
0x561ae8  50  push   eax
0x561ae9  51  push   ecx
0x561aea  e8b1aaffff  call   0x55c5a0
0x561aef  83c404  add    esp,0x4
0x561af2  50  push   eax
0x561af3  e8a8bbffff  call   0x55d6a0

; N03 formal loader returns before Start point-gate tail
; REUSED kr-extra-roy/MEF-end-to-end-20261116/entry/native-windows.json#q_start_and_skip
; VA 0x561c67..0x561c84 raw 0x161067 SHA256 aeb48746f869992a2cc43fb2279e70fa2709e95ea3b7cc24b97025d36bb479e0
0x561c67  8b442420  mov    eax,DWORD PTR [esp+0x20]
0x561c6b  bf10000000  mov    edi,0x10
0x561c70  397c2434  cmp    DWORD PTR [esp+0x34],edi
0x561c74  7304  jae    0x561c7a
0x561c76  8d442420  lea    eax,[esp+0x20]
0x561c7a  8b0b  mov    ecx,DWORD PTR [ebx]
0x561c7c  50  push   eax
0x561c7d  e8ce2d1900  call   0x6f4a50
0x561c82  33db  xor    ebx,ebx

; N04 Q active/unpaused pump
; REUSED kr-extra-roy/MEF-end-to-end-20261116/entry/native-windows.json#q_tick
; VA 0x561520..0x561678 raw 0x160920 SHA256 dd0ce28c40977d5a6c043a7a3493d0b281b58178dfb518cd489688aee32b509d
0x561520  55  push   ebp
0x561521  8bec  mov    ebp,esp
0x561523  83e4f8  and    esp,0xfffffff8
0x561526  6aff  push   0xffffffff
0x561528  687cac9300  push   0x93ac7c
0x56152d  64a100000000  mov    eax,fs:0x0
0x561533  50  push   eax
0x561534  51  push   ecx
0x561535  56  push   esi
0x561536  57  push   edi
0x561537  a1201fd600  mov    eax,ds:0xd61f20
0x56153c  33c4  xor    eax,esp
0x56153e  50  push   eax
0x56153f  8d442410  lea    eax,[esp+0x10]
0x561543  64a300000000  mov    fs:0x0,eax
0x561549  8bf9  mov    edi,ecx
0x56154b  f6054027fe0001  test   BYTE PTR ds:0xfe2740,0x1
0x561552  7529  jne    0x56157d
0x561554  830d4027fe0001  or     DWORD PTR ds:0xfe2740,0x1
0x56155b  c744241800000000  mov    DWORD PTR [esp+0x18],0x0
0x561563  e818d1ffff  call   0x55e680
0x561568  68a0f2bc00  push   0xbcf2a0
0x56156d  e8a80d3300  call   0x89231a
0x561572  83c404  add    esp,0x4
0x561575  c7442418ffffffff  mov    DWORD PTR [esp+0x18],0xffffffff
0x56157d  be4427fe00  mov    esi,0xfe2744
0x561582  e809d2ffff  call   0x55e790
0x561587  837f2800  cmp    DWORD PTR [edi+0x28],0x0
0x56158b  7453  je     0x5615e0
0x56158d  f6052cb2fa0001  test   BYTE PTR ds:0xfab22c,0x1
0x561594  be01000000  mov    esi,0x1
0x561599  7524  jne    0x5615bf
0x56159b  09352cb2fa00  or     DWORD PTR ds:0xfab22c,esi
0x5615a1  89742418  mov    DWORD PTR [esp+0x18],esi
0x5615a5  e8e6d6f7ff  call   0x4dec90
0x5615aa  6830cebc00  push   0xbcce30
0x5615af  e8660d3300  call   0x89231a
0x5615b4  83c404  add    esp,0x4
0x5615b7  c7442418ffffffff  mov    DWORD PTR [esp+0x18],0xffffffff
0x5615bf  a1a4a7fb00  mov    eax,ds:0xfba7a4
0x5615c4  897058  mov    DWORD PTR [eax+0x58],esi
0x5615c7  837f2c00  cmp    DWORD PTR [edi+0x2c],0x0
0x5615cb  7513  jne    0x5615e0
0x5615cd  8b07  mov    eax,DWORD PTR [edi]
0x5615cf  6a00  push   0x0
0x5615d1  6a00  push   0x0
0x5615d3  68a006c100  push   0xc106a0
0x5615d8  e8f3371900  call   0x6f4dd0
0x5615dd  83c40c  add    esp,0xc
0x5615e0  8b7f1c  mov    edi,DWORD PTR [edi+0x1c]
0x5615e3  8b37  mov    esi,DWORD PTR [edi]
0x5615e5  3bf7  cmp    esi,edi
0x5615e7  7455  je     0x56163e
0x5615e9  8da42400000000  lea    esp,[esp+0x0]
0x5615f0  8b4e10  mov    ecx,DWORD PTR [esi+0x10]
0x5615f3  8b11  mov    edx,DWORD PTR [ecx]
0x5615f5  8b4220  mov    eax,DWORD PTR [edx+0x20]
0x5615f8  ffd0  call   eax
0x5615fa  807e1500  cmp    BYTE PTR [esi+0x15],0x0
0x5615fe  753a  jne    0x56163a
0x561600  8b4608  mov    eax,DWORD PTR [esi+0x8]
0x561603  80781500  cmp    BYTE PTR [eax+0x15],0x0
0x561607  7516  jne    0x56161f
0x561609  8bf0  mov    esi,eax
0x56160b  8b06  mov    eax,DWORD PTR [esi]
0x56160d  80781500  cmp    BYTE PTR [eax+0x15],0x0
0x561611  7527  jne    0x56163a
0x561613  8bf0  mov    esi,eax
0x561615  8b06  mov    eax,DWORD PTR [esi]
0x561617  80781500  cmp    BYTE PTR [eax+0x15],0x0
0x56161b  74f6  je     0x561613
0x56161d  eb1b  jmp    0x56163a
0x56161f  8b4604  mov    eax,DWORD PTR [esi+0x4]
0x561622  80781500  cmp    BYTE PTR [eax+0x15],0x0
0x561626  7510  jne    0x561638
0x561628  3b7008  cmp    esi,DWORD PTR [eax+0x8]
0x56162b  750b  jne    0x561638
0x56162d  8bf0  mov    esi,eax
0x56162f  8b4004  mov    eax,DWORD PTR [eax+0x4]
0x561632  80781500  cmp    BYTE PTR [eax+0x15],0x0
0x561636  74f0  je     0x561628
0x561638  8bf0  mov    esi,eax
0x56163a  3bf7  cmp    esi,edi
0x56163c  75b2  jne    0x5615f0
0x56163e  f605dc36fe0001  test   BYTE PTR ds:0xfe36dc,0x1
0x561645  7513  jne    0x56165a
0x561647  830ddc36fe0001  or     DWORD PTR ds:0xfe36dc,0x1
0x56164e  33c0  xor    eax,eax
0x561650  a3d436fe00  mov    ds:0xfe36d4,eax
0x561655  a3d836fe00  mov    ds:0xfe36d8,eax
0x56165a  68d436fe00  push   0xfe36d4
0x56165f  e82ceaffff  call   0x560090
0x561664  33c0  xor    eax,eax
0x561666  8b4c2410  mov    ecx,DWORD PTR [esp+0x10]
0x56166a  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x561671  59  pop    ecx
0x561672  5f  pop    edi
0x561673  5e  pop    esi
0x561674  8be5  mov    esp,ebp
0x561676  5d  pop    ebp
0x561677  c3  ret

; N05 prepass Register immediately calls function
; REUSED kr-extra-roy/MEF-end-to-end-20261116/entry/native-windows.json#prepass_register
; VA 0x55d560..0x55d5de raw 0x15c960 SHA256 0ce63b7deb36908618d504da2a4452347ef382fa7da2466bcd40a1bb34667196
0x55d560  55  push   ebp
0x55d561  8bec  mov    ebp,esp
0x55d563  83e4f8  and    esp,0xfffffff8
0x55d566  83ec08  sub    esp,0x8
0x55d569  56  push   esi
0x55d56a  57  push   edi
0x55d56b  8b7d08  mov    edi,DWORD PTR [ebp+0x8]
0x55d56e  8b4708  mov    eax,DWORD PTR [edi+0x8]
0x55d571  83c0f0  add    eax,0xfffffff0
0x55d574  3dc8bfc000  cmp    eax,0xc0bfc8
0x55d579  745b  je     0x55d5d6
0x55d57b  83780806  cmp    DWORD PTR [eax+0x8],0x6
0x55d57f  7555  jne    0x55d5d6
0x55d581  89442408  mov    DWORD PTR [esp+0x8],eax
0x55d585  2b4720  sub    eax,DWORD PTR [edi+0x20]
0x55d588  33d2  xor    edx,edx
0x55d58a  50  push   eax
0x55d58b  8d44240c  lea    eax,[esp+0xc]
0x55d58f  50  push   eax
0x55d590  68505a6f00  push   0x6f5a50
0x55d595  8bc7  mov    eax,edi
0x55d597  c744241800000000  mov    DWORD PTR [esp+0x18],0x0
0x55d59f  e8cc111a00  call   0x6fe770
0x55d5a4  83c40c  add    esp,0xc
0x55d5a7  85c0  test   eax,eax
0x55d5a9  742b  je     0x55d5d6
0x55d5ab  8b7708  mov    esi,DWORD PTR [edi+0x8]
0x55d5ae  83ee10  sub    esi,0x10
0x55d5b1  837e0804  cmp    DWORD PTR [esi+0x8],0x4
0x55d5b5  741b  je     0x55d5d2
0x55d5b7  e814e01900  call   0x6fb5d0
0x55d5bc  85c0  test   eax,eax
0x55d5be  7412  je     0x55d5d2
0x55d5c0  8b4710  mov    eax,DWORD PTR [edi+0x10]
0x55d5c3  8b4844  mov    ecx,DWORD PTR [eax+0x44]
0x55d5c6  3b4840  cmp    ecx,DWORD PTR [eax+0x40]
0x55d5c9  7207  jb     0x55d5d2
0x55d5cb  8bc7  mov    eax,edi
0x55d5cd  e8cedd1900  call   0x6fb3a0
0x55d5d2  834708f0  add    DWORD PTR [edi+0x8],0xfffffff0
0x55d5d6  5f  pop    edi
0x55d5d7  33c0  xor    eax,eax
0x55d5d9  5e  pop    esi
0x55d5da  8be5  mov    esp,ebp
0x55d5dc  5d  pop    ebp
0x55d5dd  c3  ret

; N06 Q End and conditional report/cleanup
; REUSED kr-extra-roy/MEF-end-to-end-20261116/entry/native-windows.json#q_end
; VA 0x561db0..0x5620aa raw 0x1611b0 SHA256 7223d999bb2cbb1f717f5abc13332fde0f434450d5a8428bcc680ce276e3324b
0x561db0  55  push   ebp
0x561db1  8bec  mov    ebp,esp
0x561db3  83e4f8  and    esp,0xfffffff8
0x561db6  6aff  push   0xffffffff
0x561db8  6864fc9300  push   0x93fc64
0x561dbd  64a100000000  mov    eax,fs:0x0
0x561dc3  50  push   eax
0x561dc4  83ec10  sub    esp,0x10
0x561dc7  53  push   ebx
0x561dc8  56  push   esi
0x561dc9  57  push   edi
0x561dca  a1201fd600  mov    eax,ds:0xd61f20
0x561dcf  33c4  xor    eax,esp
0x561dd1  50  push   eax
0x561dd2  8d442420  lea    eax,[esp+0x20]
0x561dd6  64a300000000  mov    fs:0x0,eax
0x561ddc  8bf9  mov    edi,ecx
0x561dde  33f6  xor    esi,esi
0x561de0  80bf8900000000  cmp    BYTE PTR [edi+0x89],0x0
0x561de7  0f8473010000  je     0x561f60
0x561ded  397728  cmp    DWORD PTR [edi+0x28],esi
0x561df0  0f84aa000000  je     0x561ea0
0x561df6  897728  mov    DWORD PTR [edi+0x28],esi
0x561df9  e85224edff  call   0x434250
0x561dfe  bb01000000  mov    ebx,0x1
0x561e03  895814  mov    DWORD PTR [eax+0x14],ebx
0x561e06  841dd4f3fd00  test   BYTE PTR ds:0xfdf3d4,bl
0x561e0c  7525  jne    0x561e33
0x561e0e  091dd4f3fd00  or     DWORD PTR ds:0xfdf3d4,ebx
0x561e14  89742428  mov    DWORD PTR [esp+0x28],esi
0x561e18  e863251900  call   0x6f4380
0x561e1d  68d0e6bc00  push   0xbce6d0
0x561e22  e8f3043300  call   0x89231a
0x561e27  83c404  add    esp,0x4
0x561e2a  83ceff  or     esi,0xffffffff
0x561e2d  89742428  mov    DWORD PTR [esp+0x28],esi
0x561e31  eb03  jmp    0x561e36
0x561e33  83ceff  or     esi,0xffffffff
0x561e36  68ec06c100  push   0xc106ec
0x561e3b  6a00  push   0x0
0x561e3d  68c8f3fd00  push   0xfdf3c8
0x561e42  e859b2f4ff  call   0x4ad0a0
0x561e47  f605d4adfa0001  test   BYTE PTR ds:0xfaadd4,0x1
0x561e4e  7520  jne    0x561e70
0x561e50  091dd4adfa00  or     DWORD PTR ds:0xfaadd4,ebx
0x561e56  895c2428  mov    DWORD PTR [esp+0x28],ebx
0x561e5a  e821560200  call   0x587480
0x561e5f  68c0ccbc00  push   0xbcccc0
0x561e64  e8b1043300  call   0x89231a
0x561e69  83c404  add    esp,0x4
0x561e6c  89742428  mov    DWORD PTR [esp+0x28],esi
0x561e70  d98784000000  fld    DWORD PTR [edi+0x84]
0x561e76  83ec08  sub    esp,0x8
0x561e79  d95c241c  fstp   DWORD PTR [esp+0x1c]
0x561e7d  d944241c  fld    DWORD PTR [esp+0x1c]
0x561e81  d9542404  fst    DWORD PTR [esp+0x4]
0x561e85  d91c24  fstp   DWORD PTR [esp]
0x561e88  e8937b0200  call   0x589a20
0x561e8d  8a9f88000000  mov    bl,BYTE PTR [edi+0x88]
0x561e93  e8082deaff  call   0x404ba0
0x561e98  8898c4680000  mov    BYTE PTR [eax+0x68c4],bl
0x561e9e  eb03  jmp    0x561ea3
0x561ea0  83ceff  or     esi,0xffffffff
0x561ea3  f605640ffc0001  test   BYTE PTR ds:0xfc0f64,0x1
0x561eaa  7525  jne    0x561ed1
0x561eac  830d640ffc0001  or     DWORD PTR ds:0xfc0f64,0x1
0x561eb3  c744242802000000  mov    DWORD PTR [esp+0x28],0x2
0x561ebb  e820bef1ff  call   0x47dce0
0x561ec0  68f0dabc00  push   0xbcdaf0
0x561ec5  e850043300  call   0x89231a
0x561eca  83c404  add    esp,0x4
0x561ecd  89742428  mov    DWORD PTR [esp+0x28],esi
0x561ed1  8b473c  mov    eax,DWORD PTR [edi+0x3c]
0x561ed4  8b4f38  mov    ecx,DWORD PTR [edi+0x38]
0x561ed7  50  push   eax
0x561ed8  51  push   ecx
0x561ed9  68680ffc00  push   0xfc0f68
0x561ede  e85dc7f1ff  call   0x47e640
0x561ee3  33db  xor    ebx,ebx
0x561ee5  89473c  mov    DWORD PTR [edi+0x3c],eax
0x561ee8  3bc3  cmp    eax,ebx
0x561eea  741f  je     0x561f0b
0x561eec  8b5738  mov    edx,DWORD PTR [edi+0x38]
0x561eef  50  push   eax
0x561ef0  52  push   edx
0x561ef1  8bf7  mov    esi,edi
0x561ef3  e828380000  call   0x565720
0x561ef8  8b4c2420  mov    ecx,DWORD PTR [esp+0x20]
0x561efc  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x561f03  59  pop    ecx
0x561f04  5f  pop    edi
0x561f05  5e  pop    esi
0x561f06  5b  pop    ebx
0x561f07  8be5  mov    esp,ebp
0x561f09  5d  pop    ebp
0x561f0a  c3  ret
0x561f0b  f605c00ffc0001  test   BYTE PTR ds:0xfc0fc0,0x1
0x561f12  7525  jne    0x561f39
0x561f14  830dc00ffc0001  or     DWORD PTR ds:0xfc0fc0,0x1
0x561f1b  c744242803000000  mov    DWORD PTR [esp+0x28],0x3
0x561f23  e8286f1700  call   0x6d8e50
0x561f28  68b0dbbc00  push   0xbcdbb0
0x561f2d  e8e8033300  call   0x89231a
0x561f32  83c404  add    esp,0x4
0x561f35  89742428  mov    DWORD PTR [esp+0x28],esi
0x561f39  8b4734  mov    eax,DWORD PTR [edi+0x34]
0x561f3c  50  push   eax
0x561f3d  b9c80ffc00  mov    ecx,0xfc0fc8
0x561f42  e8e9741700  call   0x6d9430
0x561f47  895f38  mov    DWORD PTR [edi+0x38],ebx
0x561f4a  895f3c  mov    DWORD PTR [edi+0x3c],ebx
0x561f4d  8b4c2420  mov    ecx,DWORD PTR [esp+0x20]
0x561f51  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x561f58  59  pop    ecx
0x561f59  5f  pop    edi
0x561f5a  5e  pop    esi
0x561f5b  5b  pop    ebx
0x561f5c  8be5  mov    esp,ebp
0x561f5e  5d  pop    ebp
0x561f5f  c3  ret
0x561f60  397728  cmp    DWORD PTR [edi+0x28],esi
0x561f63  0f8428010000  je     0x562091
0x561f69  897728  mov    DWORD PTR [edi+0x28],esi
0x561f6c  e8df22edff  call   0x434250
0x561f71  bb01000000  mov    ebx,0x1
0x561f76  895814  mov    DWORD PTR [eax+0x14],ebx
0x561f79  397738  cmp    DWORD PTR [edi+0x38],esi
0x561f7c  7439  je     0x561fb7
0x561f7e  684403c100  push   0xc10344
0x561f83  53  push   ebx
0x561f84  e8a792f3ff  call   0x49b230
0x561f89  50  push   eax
0x561f8a  e811b1f4ff  call   0x4ad0a0
0x561f8f  6aff  push   0xffffffff
0x561f91  51  push   ecx
0x561f92  e89992f3ff  call   0x49b230
0x561f97  83c404  add    esp,0x4
0x561f9a  e8b10bf4ff  call   0x4a2b50
0x561f9f  3bc3  cmp    eax,ebx
0x561fa1  754e  jne    0x561ff1
0x561fa3  e8d826ebff  call   0x414680
0x561fa8  8b4f3c  mov    ecx,DWORD PTR [edi+0x3c]
0x561fab  8b5738  mov    edx,DWORD PTR [edi+0x38]
0x561fae  51  push   ecx
0x561faf  52  push   edx
0x561fb0  e8eb19f4ff  call   0x4a39a0
0x561fb5  eb3a  jmp    0x561ff1
0x561fb7  8d5f3c  lea    ebx,[edi+0x3c]
0x561fba  8d7774  lea    esi,[edi+0x74]
0x561fbd  53  push   ebx
0x561fbe  e87dbe1500  call   0x6bde40
0x561fc3  50  push   eax
0x561fc4  56  push   esi
0x561fc5  8d74241c  lea    esi,[esp+0x1c]
0x561fc9  e8c248edff  call   0x436890
0x561fce  57  push   edi
0x561fcf  e8cc030000  call   0x5623a0
0x561fd4  e8a726ebff  call   0x414680
0x561fd9  8b03  mov    eax,DWORD PTR [ebx]
0x561fdb  8b4f38  mov    ecx,DWORD PTR [edi+0x38]
0x561fde  50  push   eax
0x561fdf  51  push   ecx
0x561fe0  e8bb19f4ff  call   0x4a39a0
0x561fe5  e8c6000000  call   0x5620b0
0x561fea  bb01000000  mov    ebx,0x1
0x561fef  33f6  xor    esi,esi
0x561ff1  f605d4f3fd0001  test   BYTE PTR ds:0xfdf3d4,0x1
0x561ff8  7528  jne    0x562022
0x561ffa  091dd4f3fd00  or     DWORD PTR ds:0xfdf3d4,ebx
0x562000  c744242804000000  mov    DWORD PTR [esp+0x28],0x4
0x562008  e873231900  call   0x6f4380
0x56200d  68d0e6bc00  push   0xbce6d0
0x562012  e803033300  call   0x89231a
0x562017  83c404  add    esp,0x4
0x56201a  c7442428ffffffff  mov    DWORD PTR [esp+0x28],0xffffffff
0x562022  68ec06c100  push   0xc106ec
0x562027  56  push   esi
0x562028  68c8f3fd00  push   0xfdf3c8
0x56202d  e86eb0f4ff  call   0x4ad0a0
0x562032  f605d4adfa0001  test   BYTE PTR ds:0xfaadd4,0x1
0x562039  7528  jne    0x562063
0x56203b  091dd4adfa00  or     DWORD PTR ds:0xfaadd4,ebx
0x562041  c744242805000000  mov    DWORD PTR [esp+0x28],0x5
0x562049  e832540200  call   0x587480
0x56204e  68c0ccbc00  push   0xbcccc0
0x562053  e8c2023300  call   0x89231a
0x562058  83c404  add    esp,0x4
0x56205b  c7442428ffffffff  mov    DWORD PTR [esp+0x28],0xffffffff
0x562063  d98784000000  fld    DWORD PTR [edi+0x84]
0x562069  83ec08  sub    esp,0x8
0x56206c  d95c241c  fstp   DWORD PTR [esp+0x1c]
0x562070  d944241c  fld    DWORD PTR [esp+0x1c]
0x562074  d9542404  fst    DWORD PTR [esp+0x4]
0x562078  d91c24  fstp   DWORD PTR [esp]
0x56207b  e8a0790200  call   0x589a20
0x562080  8a9f88000000  mov    bl,BYTE PTR [edi+0x88]
0x562086  e8152beaff  call   0x404ba0
0x56208b  8898c4680000  mov    BYTE PTR [eax+0x68c4],bl
0x562091  897738  mov    DWORD PTR [edi+0x38],esi
0x562094  89773c  mov    DWORD PTR [edi+0x3c],esi
0x562097  8b4c2420  mov    ecx,DWORD PTR [esp+0x20]
0x56209b  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x5620a2  59  pop    ecx
0x5620a3  5f  pop    edi
0x5620a4  5e  pop    esi
0x5620a5  5b  pop    ebx
0x5620a6  8be5  mov    esp,ebp
0x5620a8  5d  pop    ebp
0x5620a9  c3  ret

; N07 first-byte text/binary parser split
; REUSED kr-extra-roy/MEF-parser-executor-storage-20261114/native-windows.json#parser:text_binary_switch_and_closure
; VA 0x6fe860..0x6fe983 raw 0x2fdc60 SHA256 755c9c11fabbd490a8e298f5b2e5c1f67f6facc7dbbffdfb0147c8138d687d4d
0x6fe860  55  push   ebp
0x6fe861  8bec  mov    ebp,esp
0x6fe863  83e4f8  and    esp,0xfffffff8
0x6fe866  83ec0c  sub    esp,0xc
0x6fe869  53  push   ebx
0x6fe86a  56  push   esi
0x6fe86b  57  push   edi
0x6fe86c  8b7d0c  mov    edi,DWORD PTR [ebp+0xc]
0x6fe86f  8b37  mov    esi,DWORD PTR [edi]
0x6fe871  e8ba050000  call   0x6fee30
0x6fe876  8b7508  mov    esi,DWORD PTR [ebp+0x8]
0x6fe879  8bd8  mov    ebx,eax
0x6fe87b  8b4610  mov    eax,DWORD PTR [esi+0x10]
0x6fe87e  8b4844  mov    ecx,DWORD PTR [eax+0x44]
0x6fe881  3b4840  cmp    ecx,DWORD PTR [eax+0x40]
0x6fe884  7207  jb     0x6fe88d
0x6fe886  8bc6  mov    eax,esi
0x6fe888  e813cbffff  call   0x6fb3a0
0x6fe88d  b880d67000  mov    eax,0x70d680
0x6fe892  83fb1b  cmp    ebx,0x1b
0x6fe895  7405  je     0x6fe89c
0x6fe897  b820e47000  mov    eax,0x70e420
0x6fe89c  8b5710  mov    edx,DWORD PTR [edi+0x10]
0x6fe89f  52  push   edx
0x6fe8a0  8b17  mov    edx,DWORD PTR [edi]
0x6fe8a2  8d4f04  lea    ecx,[edi+0x4]
0x6fe8a5  51  push   ecx
0x6fe8a6  52  push   edx
0x6fe8a7  56  push   esi
0x6fe8a8  ffd0  call   eax
0x6fe8aa  8bf8  mov    edi,eax
0x6fe8ac  8b4648  mov    eax,DWORD PTR [esi+0x48]
0x6fe8af  0fb64f48  movzx  ecx,BYTE PTR [edi+0x48]
0x6fe8b3  50  push   eax
0x6fe8b4  51  push   ecx
0x6fe8b5  8bc6  mov    eax,esi
0x6fe8b7  897c2428  mov    DWORD PTR [esp+0x28],edi
0x6fe8bb  e870eeffff  call   0x6fd730
0x6fe8c0  33db  xor    ebx,ebx
0x6fe8c2  83c418  add    esp,0x18
0x6fe8c5  897810  mov    DWORD PTR [eax+0x10],edi
0x6fe8c8  89442414  mov    DWORD PTR [esp+0x14],eax
0x6fe8cc  385f48  cmp    BYTE PTR [edi+0x48],bl
0x6fe8cf  7667  jbe    0x6fe938
0x6fe8d1  83c014  add    eax,0x14
0x6fe8d4  8944240c  mov    DWORD PTR [esp+0xc],eax
0x6fe8d8  8b7e10  mov    edi,DWORD PTR [esi+0x10]
0x6fe8db  8b5710  mov    edx,DWORD PTR [edi+0x10]
0x6fe8de  8b470c  mov    eax,DWORD PTR [edi+0xc]
0x6fe8e1  6a20  push   0x20
0x6fe8e3  6a00  push   0x0
0x6fe8e5  6a00  push   0x0
0x6fe8e7  52  push   edx
0x6fe8e8  ffd0  call   eax
0x6fe8ea  83c410  add    esp,0x10
0x6fe8ed  85c0  test   eax,eax
0x6fe8ef  7478  je     0x6fe969
0x6fe8f1  83474420  add    DWORD PTR [edi+0x44],0x20
0x6fe8f5  8b4e10  mov    ecx,DWORD PTR [esi+0x10]
0x6fe8f8  8b511c  mov    edx,DWORD PTR [ecx+0x1c]
0x6fe8fb  8910  mov    DWORD PTR [eax],edx
0x6fe8fd  8b542410  mov    edx,DWORD PTR [esp+0x10]
0x6fe901  89411c  mov    DWORD PTR [ecx+0x1c],eax
0x6fe904  8a4914  mov    cl,BYTE PTR [ecx+0x14]
0x6fe907  80e103  and    cl,0x3
0x6fe90a  884805  mov    BYTE PTR [eax+0x5],cl
0x6fe90d  8d4810  lea    ecx,[eax+0x10]
0x6fe910  894808  mov    DWORD PTR [eax+0x8],ecx
0x6fe913  c640040a  mov    BYTE PTR [eax+0x4],0xa
0x6fe917  c7410800000000  mov    DWORD PTR [ecx+0x8],0x0
0x6fe91e  8b4c240c  mov    ecx,DWORD PTR [esp+0xc]
0x6fe922  8901  mov    DWORD PTR [ecx],eax
0x6fe924  0fb64248  movzx  eax,BYTE PTR [edx+0x48]
0x6fe928  43  inc    ebx
0x6fe929  83c104  add    ecx,0x4
0x6fe92c  894c240c  mov    DWORD PTR [esp+0xc],ecx
0x6fe930  3bd8  cmp    ebx,eax
0x6fe932  7ca4  jl     0x6fe8d8
0x6fe934  8b442414  mov    eax,DWORD PTR [esp+0x14]
0x6fe938  8b4e08  mov    ecx,DWORD PTR [esi+0x8]
0x6fe93b  8901  mov    DWORD PTR [ecx],eax
0x6fe93d  c7410806000000  mov    DWORD PTR [ecx+0x8],0x6
0x6fe944  8b4e1c  mov    ecx,DWORD PTR [esi+0x1c]
0x6fe947  2b4e08  sub    ecx,DWORD PTR [esi+0x8]
0x6fe94a  83f910  cmp    ecx,0x10
0x6fe94d  7f28  jg     0x6fe977
0x6fe94f  8b462c  mov    eax,DWORD PTR [esi+0x2c]
0x6fe952  83f801  cmp    eax,0x1
0x6fe955  7c1a  jl     0x6fe971
0x6fe957  03c0  add    eax,eax
0x6fe959  e852f3ffff  call   0x6fdcb0
0x6fe95e  83460810  add    DWORD PTR [esi+0x8],0x10
0x6fe962  5f  pop    edi
0x6fe963  5e  pop    esi
0x6fe964  5b  pop    ebx
0x6fe965  8be5  mov    esp,ebp
0x6fe967  5d  pop    ebp
0x6fe968  c3  ret
0x6fe969  6a04  push   0x4
0x6fe96b  56  push   esi
0x6fe96c  e8cff1ffff  call   0x6fdb40
0x6fe971  40  inc    eax
0x6fe972  e839f3ffff  call   0x6fdcb0
0x6fe977  83460810  add    DWORD PTR [esi+0x8],0x10
0x6fe97b  5f  pop    edi
0x6fe97c  5e  pop    esi
0x6fe97d  5b  pop    ebx
0x6fe97e  8be5  mov    esp,ebp
0x6fe980  5d  pop    ebp
0x6fe981  c3  ret
0x6fe982  cc  int3

; N08 resource archive-first policy and fallback gate
; REUSED kr-extra-roy/MEF-delivery-windows-20261114/native-windows.json#loader/open-precedence
; VA 0x714770..0x714880 raw 0x313b70 SHA256 8f89564267b7dedba9fb666cb5bf8568041c61aad2a31c3a9365101d0759b8c4
0x714770  55  push   ebp
0x714771  8bec  mov    ebp,esp
0x714773  6aff  push   0xffffffff
0x714775  686c159200  push   0x92156c
0x71477a  64a100000000  mov    eax,fs:0x0
0x714780  50  push   eax
0x714781  51  push   ecx
0x714782  53  push   ebx
0x714783  57  push   edi
0x714784  a1201fd600  mov    eax,ds:0xd61f20
0x714789  33c5  xor    eax,ebp
0x71478b  50  push   eax
0x71478c  8d45f4  lea    eax,[ebp-0xc]
0x71478f  64a300000000  mov    fs:0x0,eax
0x714795  8b7d0c  mov    edi,DWORD PTR [ebp+0xc]
0x714798  8b5d08  mov    ebx,DWORD PTR [ebp+0x8]
0x71479b  57  push   edi
0x71479c  8bcb  mov    ecx,ebx
0x71479e  e86df1ffff  call   0x713910
0x7147a3  83c404  add    esp,0x4
0x7147a6  8945f0  mov    DWORD PTR [ebp-0x10],eax
0x7147a9  85c0  test   eax,eax
0x7147ab  0f85be000000  jne    0x71486f
0x7147b1  f605984cfe0001  test   BYTE PTR ds:0xfe4c98,0x1
0x7147b8  7523  jne    0x7147dd
0x7147ba  830d984cfe0001  or     DWORD PTR ds:0xfe4c98,0x1
0x7147c1  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x7147c4  e807fbffff  call   0x7142d0
0x7147c9  686007bd00  push   0xbd0760
0x7147ce  e847db1700  call   0x89231a
0x7147d3  83c404  add    esp,0x4
0x7147d6  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x7147dd  803d944cfe0000  cmp    BYTE PTR ds:0xfe4c94,0x0
0x7147e4  751a  jne    0x714800
0x7147e6  8bcf  mov    ecx,edi
0x7147e8  8bfb  mov    edi,ebx
0x7147ea  e841f8ffff  call   0x714030
0x7147ef  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x7147f2  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x7147f9  59  pop    ecx
0x7147fa  5f  pop    edi
0x7147fb  5b  pop    ebx
0x7147fc  8be5  mov    esp,ebp
0x7147fe  5d  pop    ebp
0x7147ff  c3  ret
0x714800  f605984cfe0001  test   BYTE PTR ds:0xfe4c98,0x1
0x714807  7527  jne    0x714830
0x714809  b801000000  mov    eax,0x1
0x71480e  0905984cfe00  or     DWORD PTR ds:0xfe4c98,eax
0x714814  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x714817  e8b4faffff  call   0x7142d0
0x71481c  686007bd00  push   0xbd0760
0x714821  e8f4da1700  call   0x89231a
0x714826  83c404  add    esp,0x4
0x714829  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x714830  8bcb  mov    ecx,ebx
0x714832  bf7c4cfe00  mov    edi,0xfe4c7c
0x714837  e874fbffff  call   0x7143b0
0x71483c  84c0  test   al,al
0x71483e  7511  jne    0x714851
0x714840  e81bfaffff  call   0x714260
0x714845  50  push   eax
0x714846  8bcb  mov    ecx,ebx
0x714848  e823fcffff  call   0x714470
0x71484d  84c0  test   al,al
0x71484f  741b  je     0x71486c
0x714851  8b4d0c  mov    ecx,DWORD PTR [ebp+0xc]
0x714854  8bfb  mov    edi,ebx
0x714856  e8d5f7ffff  call   0x714030
0x71485b  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x71485e  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x714865  59  pop    ecx
0x714866  5f  pop    edi
0x714867  5b  pop    ebx
0x714868  8be5  mov    esp,ebp
0x71486a  5d  pop    ebp
0x71486b  c3  ret
0x71486c  8b45f0  mov    eax,DWORD PTR [ebp-0x10]
0x71486f  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x714872  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x714879  59  pop    ecx
0x71487a  5f  pop    edi
0x71487b  5b  pop    ebx
0x71487c  8be5  mov    esp,ebp
0x71487e  5d  pop    ebp
0x71487f  c3  ret

; N09 parent provider lookup before child descent
; REUSED kr-extra-roy/MEF-delivery-windows-20261114/native-windows.json#loader/mounted-directory-lookup
; VA 0x714c50..0x714d4d raw 0x314050 SHA256 c621db144fef019d5bfb764eb36877a1cd07799729a622cfe743327da49654a0
0x714c50  55  push   ebp
0x714c51  8bec  mov    ebp,esp
0x714c53  81ec08010000  sub    esp,0x108
0x714c59  a1201fd600  mov    eax,ds:0xd61f20
0x714c5e  33c5  xor    eax,ebp
0x714c60  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x714c63  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x714c66  53  push   ebx
0x714c67  57  push   edi
0x714c68  50  push   eax
0x714c69  8d85f8feffff  lea    eax,[ebp-0x108]
0x714c6f  6804010000  push   0x104
0x714c74  50  push   eax
0x714c75  8bd9  mov    ebx,ecx
0x714c77  e8ddee1700  call   0x893b59
0x714c7c  8d8df8feffff  lea    ecx,[ebp-0x108]
0x714c82  51  push   ecx
0x714c83  e848240000  call   0x7170d0
0x714c88  8bf8  mov    edi,eax
0x714c8a  83c410  add    esp,0x10
0x714c8d  85ff  test   edi,edi
0x714c8f  7512  jne    0x714ca3
0x714c91  5f  pop    edi
0x714c92  5b  pop    ebx
0x714c93  8b4dfc  mov    ecx,DWORD PTR [ebp-0x4]
0x714c96  33cd  xor    ecx,ebp
0x714c98  e864c31700  call   0x891001
0x714c9d  8be5  mov    esp,ebp
0x714c9f  5d  pop    ebp
0x714ca0  c20800  ret    0x8
0x714ca3  c60700  mov    BYTE PTR [edi],0x0
0x714ca6  47  inc    edi
0x714ca7  8bd7  mov    edx,edi
0x714ca9  8d85f8feffff  lea    eax,[ebp-0x108]
0x714caf  2bd0  sub    edx,eax
0x714cb1  83fa01  cmp    edx,0x1
0x714cb4  7521  jne    0x714cd7
0x714cb6  52  push   edx
0x714cb7  8d8df9feffff  lea    ecx,[ebp-0x107]
0x714cbd  51  push   ecx
0x714cbe  8bcb  mov    ecx,ebx
0x714cc0  e88bffffff  call   0x714c50
0x714cc5  5f  pop    edi
0x714cc6  5b  pop    ebx
0x714cc7  8b4dfc  mov    ecx,DWORD PTR [ebp-0x4]
0x714cca  33cd  xor    ecx,ebp
0x714ccc  e830c31700  call   0x891001
0x714cd1  8be5  mov    esp,ebp
0x714cd3  5d  pop    ebp
0x714cd4  c20800  ret    0x8
0x714cd7  8b8304010000  mov    eax,DWORD PTR [ebx+0x104]
0x714cdd  56  push   esi
0x714cde  8b30  mov    esi,DWORD PTR [eax]
0x714ce0  3bf0  cmp    esi,eax
0x714ce2  7421  je     0x714d05
0x714ce4  8d95f8feffff  lea    edx,[ebp-0x108]
0x714cea  52  push   edx
0x714ceb  8d4608  lea    eax,[esi+0x8]
0x714cee  50  push   eax
0x714cef  e8bdef1700  call   0x893cb1
0x714cf4  83c408  add    esp,0x8
0x714cf7  85c0  test   eax,eax
0x714cf9  741f  je     0x714d1a
0x714cfb  8b36  mov    esi,DWORD PTR [esi]
0x714cfd  3bb304010000  cmp    esi,DWORD PTR [ebx+0x104]
0x714d03  75df  jne    0x714ce4
0x714d05  33c0  xor    eax,eax
0x714d07  5e  pop    esi
0x714d08  5f  pop    edi
0x714d09  5b  pop    ebx
0x714d0a  8b4dfc  mov    ecx,DWORD PTR [ebp-0x4]
0x714d0d  33cd  xor    ecx,ebp
0x714d0f  e8edc21700  call   0x891001
0x714d14  8be5  mov    esp,ebp
0x714d16  5d  pop    ebp
0x714d17  c20800  ret    0x8
0x714d1a  8b8608010000  mov    eax,DWORD PTR [esi+0x108]
0x714d20  85c0  test   eax,eax
0x714d22  740b  je     0x714d2f
0x714d24  8bcf  mov    ecx,edi
0x714d26  e885080000  call   0x7155b0
0x714d2b  85c0  test   eax,eax
0x714d2d  75d8  jne    0x714d07
0x714d2f  6a01  push   0x1
0x714d31  57  push   edi
0x714d32  8d4e08  lea    ecx,[esi+0x8]
0x714d35  e816ffffff  call   0x714c50
0x714d3a  8b4dfc  mov    ecx,DWORD PTR [ebp-0x4]
0x714d3d  5e  pop    esi
0x714d3e  5f  pop    edi
0x714d3f  33cd  xor    ecx,ebp
0x714d41  5b  pop    ebx
0x714d42  e8bac21700  call   0x891001
0x714d47  8be5  mov    esp,ebp
0x714d49  5d  pop    ebp
0x714d4a  c20800  ret    0x8

; N10 TutorialMain and Tutorial_EntryPoint
; REUSED kr-extra-roy/MEF-world-integration-20261115/runner/native-windows.json#R07
; VA 0x4a8a60..0x4a8b8d raw 0xa7e60 SHA256 f4b6014a2c69e25eb92fc0c95c4beab00880db7d0f5d27c9a53c3b346105e715
0x4a8a60  55  push   ebp
0x4a8a61  8bec  mov    ebp,esp
0x4a8a63  6aff  push   0xffffffff
0x4a8a65  684ca49300  push   0x93a44c
0x4a8a6a  64a100000000  mov    eax,fs:0x0
0x4a8a70  50  push   eax
0x4a8a71  83ec08  sub    esp,0x8
0x4a8a74  53  push   ebx
0x4a8a75  57  push   edi
0x4a8a76  a1201fd600  mov    eax,ds:0xd61f20
0x4a8a7b  33c5  xor    eax,ebp
0x4a8a7d  50  push   eax
0x4a8a7e  8d45f4  lea    eax,[ebp-0xc]
0x4a8a81  64a300000000  mov    fs:0x0,eax
0x4a8a87  8d7e04  lea    edi,[esi+0x4]
0x4a8a8a  c705a0a7fb0000000000  mov    DWORD PTR ds:0xfba7a0,0x0
0x4a8a94  e8b7ad3700  call   0x823850
0x4a8a99  8d7e14  lea    edi,[esi+0x14]
0x4a8a9c  e87f893a00  call   0x851420
0x4a8aa1  bb01000000  mov    ebx,0x1
0x4a8aa6  83cfff  or     edi,0xffffffff
0x4a8aa9  841d5473fb00  test   BYTE PTR ds:0xfb7354,bl
0x4a8aaf  7522  jne    0x4a8ad3
0x4a8ab1  091d5473fb00  or     DWORD PTR ds:0xfb7354,ebx
0x4a8ab7  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x4a8abe  e80da90a00  call   0x5533d0
0x4a8ac3  6800d1bc00  push   0xbcd100
0x4a8ac8  e84d983e00  call   0x89231a
0x4a8acd  83c404  add    esp,0x4
0x4a8ad0  897dfc  mov    DWORD PTR [ebp-0x4],edi
0x4a8ad3  891db473fb00  mov    DWORD PTR ds:0xfb73b4,ebx
0x4a8ad9  841dd4adfa00  test   BYTE PTR ds:0xfaadd4,bl
0x4a8adf  751e  jne    0x4a8aff
0x4a8ae1  091dd4adfa00  or     DWORD PTR ds:0xfaadd4,ebx
0x4a8ae7  895dfc  mov    DWORD PTR [ebp-0x4],ebx
0x4a8aea  e891e90d00  call   0x587480
0x4a8aef  68c0ccbc00  push   0xbcccc0
0x4a8af4  e821983e00  call   0x89231a
0x4a8af9  83c404  add    esp,0x4
0x4a8afc  897dfc  mov    DWORD PTR [ebp-0x4],edi
0x4a8aff  b80f000000  mov    eax,0xf
0x4a8b04  3905ecadfa00  cmp    DWORD PTR ds:0xfaadec,eax
0x4a8b0a  7407  je     0x4a8b13
0x4a8b0c  a3f0adfa00  mov    ds:0xfaadf0,eax
0x4a8b11  eb05  jmp    0x4a8b18
0x4a8b13  e8881e0e00  call   0x58a9a0
0x4a8b18  841d1413fb00  test   BYTE PTR ds:0xfb1314,bl
0x4a8b1e  7513  jne    0x4a8b33
0x4a8b20  091d1413fb00  or     DWORD PTR ds:0xfb1314,ebx
0x4a8b26  6810cfbc00  push   0xbccf10
0x4a8b2b  e8ea973e00  call   0x89231a
0x4a8b30  83c404  add    esp,0x4
0x4a8b33  833d98a7fb0000  cmp    DWORD PTR ds:0xfba798,0x0
0x4a8b3a  b80c000000  mov    eax,0xc
0x4a8b3f  668945ec  mov    WORD PTR [ebp-0x14],ax
0x4a8b43  895dee  mov    DWORD PTR [ebp-0x12],ebx
0x4a8b46  7515  jne    0x4a8b5d
0x4a8b48  8b0d54a8fb00  mov    ecx,DWORD PTR ds:0xfba854
0x4a8b4e  8b11  mov    edx,DWORD PTR [ecx]
0x4a8b50  8b5210  mov    edx,DWORD PTR [edx+0x10]
0x4a8b53  6a06  push   0x6
0x4a8b55  8d45ec  lea    eax,[ebp-0x14]
0x4a8b58  50  push   eax
0x4a8b59  6a00  push   0x0
0x4a8b5b  ffd2  call   edx
0x4a8b5d  8b0e  mov    ecx,DWORD PTR [esi]
0x4a8b5f  687c68c000  push   0xc0687c
0x4a8b64  e8e7be2400  call   0x6f4a50
0x4a8b69  8b06  mov    eax,DWORD PTR [esi]
0x4a8b6b  6a00  push   0x0
0x4a8b6d  6a00  push   0x0
0x4a8b6f  68a868c000  push   0xc068a8
0x4a8b74  e857c22400  call   0x6f4dd0
0x4a8b79  83c40c  add    esp,0xc
0x4a8b7c  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4a8b7f  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4a8b86  59  pop    ecx
0x4a8b87  5f  pop    edi
0x4a8b88  5b  pop    ebx
0x4a8b89  8be5  mov    esp,ebp
0x4a8b8b  5d  pop    ebp
0x4a8b8c  c3  ret

; N11 Tutorial owner t_doCoTask pump
; REUSED kr-extra-roy/MEF-world-integration-20261115/runner/native-windows.json#R01
; VA 0x4a8b90..0x4a8c1b raw 0xa7f90 SHA256 95c2feeed86b698b3804f837a80e8735b79346041df8bb3ef796f64d20db79de
0x4a8b90  55  push   ebp
0x4a8b91  8bec  mov    ebp,esp
0x4a8b93  83ec18  sub    esp,0x18
0x4a8b96  53  push   ebx
0x4a8b97  8b5d08  mov    ebx,DWORD PTR [ebp+0x8]
0x4a8b9a  8b03  mov    eax,DWORD PTR [ebx]
0x4a8b9c  56  push   esi
0x4a8b9d  57  push   edi
0x4a8b9e  68d468c000  push   0xc068d4
0x4a8ba3  6a01  push   0x1
0x4a8ba5  50  push   eax
0x4a8ba6  e8f5440000  call   0x4ad0a0
0x4a8bab  8b0b  mov    ecx,DWORD PTR [ebx]
0x4a8bad  8b09  mov    ecx,DWORD PTR [ecx]
0x4a8baf  83c8ff  or     eax,0xffffffff
0x4a8bb2  e839c52400  call   0x6f50f0
0x4a8bb7  8b4808  mov    ecx,DWORD PTR [eax+0x8]
0x4a8bba  83f903  cmp    ecx,0x3
0x4a8bbd  7426  je     0x4a8be5
0x4a8bbf  83f904  cmp    ecx,0x4
0x4a8bc2  7542  jne    0x4a8c06
0x4a8bc4  8b30  mov    esi,DWORD PTR [eax]
0x4a8bc6  83c610  add    esi,0x10
0x4a8bc9  8d7df4  lea    edi,[ebp-0xc]
0x4a8bcc  e88feb2400  call   0x6f7760
0x4a8bd1  85c0  test   eax,eax
0x4a8bd3  7431  je     0x4a8c06
0x4a8bd5  dd45f4  fld    QWORD PTR [ebp-0xc]
0x4a8bd8  c745f403000000  mov    DWORD PTR [ebp-0xc],0x3
0x4a8bdf  dd5dec  fstp   QWORD PTR [ebp-0x14]
0x4a8be2  8d45ec  lea    eax,[ebp-0x14]
0x4a8be5  dd00  fld    QWORD PTR [eax]
0x4a8be7  dd5df4  fstp   QWORD PTR [ebp-0xc]
0x4a8bea  dd45f4  fld    QWORD PTR [ebp-0xc]
0x4a8bed  db5d08  fistp  DWORD PTR [ebp+0x8]
0x4a8bf0  8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4a8bf3  33d2  xor    edx,edx
0x4a8bf5  85c0  test   eax,eax
0x4a8bf7  0f95c2  setne  dl
0x4a8bfa  895334  mov    DWORD PTR [ebx+0x34],edx
0x4a8bfd  5f  pop    edi
0x4a8bfe  5e  pop    esi
0x4a8bff  5b  pop    ebx
0x4a8c00  8be5  mov    esp,ebp
0x4a8c02  5d  pop    ebp
0x4a8c03  c20400  ret    0x4
0x4a8c06  33d2  xor    edx,edx
0x4a8c08  33c0  xor    eax,eax
0x4a8c0a  85c0  test   eax,eax
0x4a8c0c  0f95c2  setne  dl
0x4a8c0f  5f  pop    edi
0x4a8c10  5e  pop    esi
0x4a8c11  895334  mov    DWORD PTR [ebx+0x34],edx
0x4a8c14  5b  pop    ebx
0x4a8c15  8be5  mov    esp,ebp
0x4a8c17  5d  pop    ebp
0x4a8c18  c20400  ret    0x4

; N12 CTutorial field update calls T independently of Q active
; REUSED kr-extra-roy/MEF-world-integration-20261115/runner/native-windows.json#R08
; VA 0x4c4df0..0x4c4ea2 raw 0xc41f0 SHA256 52b779dae92ed649222a184e70b08f555f9070b278715a9f213fd5723357a1df
0x4c4df0  55  push   ebp
0x4c4df1  8bec  mov    ebp,esp
0x4c4df3  6aff  push   0xffffffff
0x4c4df5  68dc799400  push   0x9479dc
0x4c4dfa  64a100000000  mov    eax,fs:0x0
0x4c4e00  50  push   eax
0x4c4e01  56  push   esi
0x4c4e02  57  push   edi
0x4c4e03  a1201fd600  mov    eax,ds:0xd61f20
0x4c4e08  33c5  xor    eax,ebp
0x4c4e0a  50  push   eax
0x4c4e0b  8d45f4  lea    eax,[ebp-0xc]
0x4c4e0e  64a300000000  mov    fs:0x0,eax
0x4c4e14  e8f78cfeff  call   0x4adb10
0x4c4e19  f605c818fe0001  test   BYTE PTR ds:0xfe18c8,0x1
0x4c4e20  8bf0  mov    esi,eax
0x4c4e22  7527  jne    0x4c4e4b
0x4c4e24  830dc818fe0001  or     DWORD PTR ds:0xfe18c8,0x1
0x4c4e2b  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x4c4e32  e839ab0700  call   0x53f970
0x4c4e37  6810e8bc00  push   0xbce810
0x4c4e3c  e8d9d43c00  call   0x89231a
0x4c4e41  83c404  add    esp,0x4
0x4c4e44  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c4e4b  bfcc18fe00  mov    edi,0xfe18cc
0x4c4e50  e8fbb00700  call   0x53ff50
0x4c4e55  f605800ffc0001  test   BYTE PTR ds:0xfc0f80,0x1
0x4c4e5c  7527  jne    0x4c4e85
0x4c4e5e  b801000000  mov    eax,0x1
0x4c4e63  0905800ffc00  or     DWORD PTR ds:0xfc0f80,eax
0x4c4e69  8945fc  mov    DWORD PTR [ebp-0x4],eax
0x4c4e6c  e83f60fbff  call   0x47aeb0
0x4c4e71  6870dbbc00  push   0xbcdb70
0x4c4e76  e89fd43c00  call   0x89231a
0x4c4e7b  83c404  add    esp,0x4
0x4c4e7e  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c4e85  68840ffc00  push   0xfc0f84
0x4c4e8a  e8013dfeff  call   0x4a8b90
0x4c4e8f  8bc6  mov    eax,esi
0x4c4e91  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4c4e94  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4c4e9b  59  pop    ecx
0x4c4e9c  5f  pop    edi
0x4c4e9d  5e  pop    esi
0x4c4e9e  8be5  mov    esp,ebp
0x4c4ea0  5d  pop    ebp
0x4c4ea1  c3  ret

; N13 CTutorial leave removes tco and native table
; REUSED kr-extra-roy/MEF-world-integration-20261115/runner/native-windows.json#R09
; VA 0x4c4d60..0x4c4de2 raw 0xc4160 SHA256 6a4c57774a6ff8aecb820bdffe6ecc177944b6f9e57862dec6bb82dbf008ff89
0x4c4d60  55  push   ebp
0x4c4d61  8bec  mov    ebp,esp
0x4c4d63  6aff  push   0xffffffff
0x4c4d65  68ce3e9300  push   0x933ece
0x4c4d6a  64a100000000  mov    eax,fs:0x0
0x4c4d70  50  push   eax
0x4c4d71  a1201fd600  mov    eax,ds:0xd61f20
0x4c4d76  33c5  xor    eax,ebp
0x4c4d78  50  push   eax
0x4c4d79  8d45f4  lea    eax,[ebp-0xc]
0x4c4d7c  64a300000000  mov    fs:0x0,eax
0x4c4d82  b801000000  mov    eax,0x1
0x4c4d87  8405800ffc00  test   BYTE PTR ds:0xfc0f80,al
0x4c4d8d  7526  jne    0x4c4db5
0x4c4d8f  0905800ffc00  or     DWORD PTR ds:0xfc0f80,eax
0x4c4d95  c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x4c4d9c  e80f61fbff  call   0x47aeb0
0x4c4da1  6870dbbc00  push   0xbcdb70
0x4c4da6  e86fd53c00  call   0x89231a
0x4c4dab  83c404  add    esp,0x4
0x4c4dae  c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c4db5  a1840ffc00  mov    eax,ds:0xfc0f84
0x4c4dba  68bc68c000  push   0xc068bc
0x4c4dbf  6a00  push   0x0
0x4c4dc1  50  push   eax
0x4c4dc2  e8d982feff  call   0x4ad0a0
0x4c4dc7  b9840ffc00  mov    ecx,0xfc0f84
0x4c4dcc  e8df4ffeff  call   0x4a9db0
0x4c4dd1  33c0  xor    eax,eax
0x4c4dd3  8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4c4dd6  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4c4ddd  59  pop    ecx
0x4c4dde  8be5  mov    esp,ebp
0x4c4de0  5d  pop    ebp
0x4c4de1  c3  ret

; N14 SceneList XML is loaded into persistent key map
; REUSED kr-extra-roy/MEF-delivery-windows-20261114/native-windows.json#loader/scene-key-map-load
; VA 0x5607d0..0x560a99 raw 0x15fbd0 SHA256 a2d498de41c318342f6744f8024d00e175aa0fd1552d5bff5074d3cd2beb5e62
0x5607d0  55  push   ebp
0x5607d1  8bec  mov    ebp,esp
0x5607d3  83e4f8  and    esp,0xfffffff8
0x5607d6  6aff  push   0xffffffff
0x5607d8  68712f9200  push   0x922f71
0x5607dd  64a100000000  mov    eax,fs:0x0
0x5607e3  50  push   eax
0x5607e4  81ecd8000000  sub    esp,0xd8
0x5607ea  a1201fd600  mov    eax,ds:0xd61f20
0x5607ef  33c4  xor    eax,esp
0x5607f1  898424d0000000  mov    DWORD PTR [esp+0xd0],eax
0x5607f8  53  push   ebx
0x5607f9  56  push   esi
0x5607fa  57  push   edi
0x5607fb  a1201fd600  mov    eax,ds:0xd61f20
0x560800  33c4  xor    eax,esp
0x560802  50  push   eax
0x560803  8d8424e8000000  lea    eax,[esp+0xe8]
0x56080a  64a300000000  mov    fs:0x0,eax
0x560810  8d442464  lea    eax,[esp+0x64]
0x560814  50  push   eax
0x560815  b96806c100  mov    ecx,0xc10668
0x56081a  e811e61c00  call   0x72ee30
0x56081f  33db  xor    ebx,ebx
0x560821  899c24f0000000  mov    DWORD PTR [esp+0xf0],ebx
0x560828  83bc249800000010  cmp    DWORD PTR [esp+0x98],0x10
0x560830  8b8c2484000000  mov    ecx,DWORD PTR [esp+0x84]
0x560837  7307  jae    0x560840
0x560839  8d8c2484000000  lea    ecx,[esp+0x84]
0x560840  53  push   ebx
0x560841  8d742468  lea    esi,[esp+0x68]
0x560845  e8c6e81c00  call   0x72f110
0x56084a  84c0  test   al,al
0x56084c  0f84d4010000  je     0x560a26
0x560852  8b0dcc73fb00  mov    ecx,DWORD PTR ds:0xfb73cc
0x560858  8b5104  mov    edx,DWORD PTR [ecx+0x4]
0x56085b  52  push   edx
0x56085c  b9c873fb00  mov    ecx,0xfb73c8
0x560861  e82a520000  call   0x565a90
0x560866  a1cc73fb00  mov    eax,ds:0xfb73cc
0x56086b  894004  mov    DWORD PTR [eax+0x4],eax
0x56086e  a1cc73fb00  mov    eax,ds:0xfb73cc
0x560873  8900  mov    DWORD PTR [eax],eax
0x560875  a1cc73fb00  mov    eax,ds:0xfb73cc
0x56087a  894008  mov    DWORD PTR [eax+0x8],eax
0x56087d  687c06c100  push   0xc1067c
0x560882  8bc6  mov    eax,esi
0x560884  891dd073fb00  mov    DWORD PTR ds:0xfb73d0,ebx
0x56088a  e851da1c00  call   0x72e2e0
0x56088f  3bc3  cmp    eax,ebx
0x560891  0f848f010000  je     0x560a26
0x560897  688c33c000  push   0xc0338c
0x56089c  e83fda1c00  call   0x72e2e0
0x5608a1  8bf0  mov    esi,eax
0x5608a3  89442414  mov    DWORD PTR [esp+0x14],eax
0x5608a7  3bf3  cmp    esi,ebx
0x5608a9  0f8477010000  je     0x560a26
0x5608af  eb04  jmp    0x5608b5
0x5608b1  8b742414  mov    esi,DWORD PTR [esp+0x14]
0x5608b5  8b06  mov    eax,DWORD PTR [esi]
0x5608b7  8b5014  mov    edx,DWORD PTR [eax+0x14]
0x5608ba  8bce  mov    ecx,esi
0x5608bc  ffd2  call   edx
0x5608be  3bc3  cmp    eax,ebx
0x5608c0  0f8451010000  je     0x560a17
0x5608c6  c74424380f000000  mov    DWORD PTR [esp+0x38],0xf
0x5608ce  895c2434  mov    DWORD PTR [esp+0x34],ebx
0x5608d2  885c2424  mov    BYTE PTR [esp+0x24],bl
0x5608d6  8d7844  lea    edi,[eax+0x44]
0x5608d9  688806c100  push   0xc10688
0x5608de  c68424f400000001  mov    BYTE PTR [esp+0xf4],0x1
0x5608e6  e8b5f71c00  call   0x7300a0
0x5608eb  3bc3  cmp    eax,ebx
0x5608ed  741e  je     0x56090d
0x5608ef  83c030  add    eax,0x30
0x5608f2  83781410  cmp    DWORD PTR [eax+0x14],0x10
0x5608f6  7202  jb     0x5608fa
0x5608f8  8b00  mov    eax,DWORD PTR [eax]
0x5608fa  3bc3  cmp    eax,ebx
0x5608fc  740f  je     0x56090d
0x5608fe  50  push   eax
0x5608ff  e8b00e3300  call   0x8917b4
0x560904  83c404  add    esp,0x4
0x560907  89442418  mov    DWORD PTR [esp+0x18],eax
0x56090b  eb04  jmp    0x560911
0x56090d  895c2418  mov    DWORD PTR [esp+0x18],ebx
0x560911  689433c000  push   0xc03394
0x560916  e885f71c00  call   0x7300a0
0x56091b  3bc3  cmp    eax,ebx
0x56091d  741c  je     0x56093b
0x56091f  83c030  add    eax,0x30
0x560922  83781410  cmp    DWORD PTR [eax+0x14],0x10
0x560926  7202  jb     0x56092a
0x560928  8b00  mov    eax,DWORD PTR [eax]
0x56092a  3bc3  cmp    eax,ebx
0x56092c  740d  je     0x56093b
0x56092e  50  push   eax
0x56092f  e8800e3300  call   0x8917b4
0x560934  83c404  add    esp,0x4
0x560937  8bf0  mov    esi,eax
0x560939  eb02  jmp    0x56093d
0x56093b  33f6  xor    esi,esi
0x56093d  689406c100  push   0xc10694
0x560942  e859f71c00  call   0x7300a0
0x560947  3bc3  cmp    eax,ebx
0x560949  740d  je     0x560958
0x56094b  83784410  cmp    DWORD PTR [eax+0x44],0x10
0x56094f  8d4830  lea    ecx,[eax+0x30]
0x560952  7206  jb     0x56095a
0x560954  8b09  mov    ecx,DWORD PTR [ecx]
0x560956  eb02  jmp    0x56095a
0x560958  33c9  xor    ecx,ecx
0x56095a  8bc1  mov    eax,ecx
0x56095c  8d7801  lea    edi,[eax+0x1]
0x56095f  90  nop
0x560960  8a10  mov    dl,BYTE PTR [eax]
0x560962  40  inc    eax
0x560963  3ad3  cmp    dl,bl
0x560965  75f9  jne    0x560960
0x560967  2bc7  sub    eax,edi
0x560969  50  push   eax
0x56096a  51  push   ecx
0x56096b  8d4c242c  lea    ecx,[esp+0x2c]
0x56096f  e8fc20eaff  call   0x402a70
0x560974  8b442418  mov    eax,DWORD PTR [esp+0x18]
0x560978  6aff  push   0xffffffff
0x56097a  53  push   ebx
0x56097b  8d4c242c  lea    ecx,[esp+0x2c]
0x56097f  51  push   ecx
0x560980  bf0f000000  mov    edi,0xf
0x560985  8d4c2454  lea    ecx,[esp+0x54]
0x560989  8944244c  mov    DWORD PTR [esp+0x4c],eax
0x56098d  89742450  mov    DWORD PTR [esp+0x50],esi
0x560991  897c2468  mov    DWORD PTR [esp+0x68],edi
0x560995  895c2464  mov    DWORD PTR [esp+0x64],ebx
0x560999  885c2454  mov    BYTE PTR [esp+0x54],bl
0x56099d  e89e26eaff  call   0x403040
0x5609a2  68c873fb00  push   0xfb73c8
0x5609a7  8d4c2444  lea    ecx,[esp+0x44]
0x5609ab  c68424f400000002  mov    BYTE PTR [esp+0xf4],0x2
0x5609b3  e8987f0000  call   0x568950
0x5609b8  8d54241c  lea    edx,[esp+0x1c]
0x5609bc  52  push   edx
0x5609bd  68c873fb00  push   0xfb73c8
0x5609c2  8bf0  mov    esi,eax
0x5609c4  e8b77c0000  call   0x568680
0x5609c9  be10000000  mov    esi,0x10
0x5609ce  3974245c  cmp    DWORD PTR [esp+0x5c],esi
0x5609d2  720d  jb     0x5609e1
0x5609d4  8b442448  mov    eax,DWORD PTR [esp+0x48]
0x5609d8  50  push   eax
0x5609d9  e82e083300  call   0x89120c
0x5609de  83c404  add    esp,0x4
0x5609e1  889c24f0000000  mov    BYTE PTR [esp+0xf0],bl
0x5609e8  897c245c  mov    DWORD PTR [esp+0x5c],edi
0x5609ec  895c2458  mov    DWORD PTR [esp+0x58],ebx
0x5609f0  885c2448  mov    BYTE PTR [esp+0x48],bl
0x5609f4  39742438  cmp    DWORD PTR [esp+0x38],esi
0x5609f8  720d  jb     0x560a07
0x5609fa  8b4c2424  mov    ecx,DWORD PTR [esp+0x24]
0x5609fe  51  push   ecx
0x5609ff  e808083300  call   0x89120c
0x560a04  83c404  add    esp,0x4
0x560a07  8b742414  mov    esi,DWORD PTR [esp+0x14]
0x560a0b  897c2438  mov    DWORD PTR [esp+0x38],edi
0x560a0f  895c2434  mov    DWORD PTR [esp+0x34],ebx
0x560a13  885c2424  mov    BYTE PTR [esp+0x24],bl
0x560a17  8b7640  mov    esi,DWORD PTR [esi+0x40]
0x560a1a  89742414  mov    DWORD PTR [esp+0x14],esi
0x560a1e  3bf3  cmp    esi,ebx
0x560a20  0f858bfeffff  jne    0x5608b1
0x560a26  c78424f0000000ffffffff  mov    DWORD PTR [esp+0xf0],0xffffffff
0x560a31  83bc24c400000010  cmp    DWORD PTR [esp+0xc4],0x10
0x560a39  c74424649423bf00  mov    DWORD PTR [esp+0x64],0xbf2394
0x560a41  7210  jb     0x560a53
0x560a43  8b9424b0000000  mov    edx,DWORD PTR [esp+0xb0]
0x560a4a  52  push   edx
0x560a4b  e8bc073300  call   0x89120c
0x560a50  83c404  add    esp,0x4
0x560a53  8d4c2464  lea    ecx,[esp+0x64]
0x560a57  c78424c40000000f000000  mov    DWORD PTR [esp+0xc4],0xf
0x560a62  899c24c0000000  mov    DWORD PTR [esp+0xc0],ebx
0x560a69  889c24b0000000  mov    BYTE PTR [esp+0xb0],bl
0x560a70  e8cbd51c00  call   0x72e040
0x560a75  8b8c24e8000000  mov    ecx,DWORD PTR [esp+0xe8]
0x560a7c  64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x560a83  59  pop    ecx
0x560a84  5f  pop    edi
0x560a85  5e  pop    esi
0x560a86  5b  pop    ebx
0x560a87  8b8c24d0000000  mov    ecx,DWORD PTR [esp+0xd0]
0x560a8e  33cc  xor    ecx,esp
0x560a90  e86c053300  call   0x891001
0x560a95  8be5  mov    esp,ebp
0x560a97  5d  pop    ebp
0x560a98  c3  ret

; N15 GetTime registration
; REUSED kr-extra-roy/MEF-runtime-contracts-20261115/scheduler/native-windows.json#N01
; VA 0x4a1ab0..0x4a1b49 raw 0xa0eb0 SHA256 98158476dd8a2e29bb0561d3df527471fb5ee426a8614e2e9490f33630b94f8d
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

; N16 GetTime signed result marshalling
; REUSED kr-extra-roy/MEF-runtime-contracts-20261115/scheduler/native-windows.json#N02
; VA 0x4a2190..0x4a21fe raw 0xa1590 SHA256 5b0f0ccbb18c8b8f1a72f61f0d21d1854dc40ba4622189372e1d7b6d77978ab2
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

; N17 GetTime import thunk
; REUSED kr-extra-roy/MEF-runtime-contracts-20261115/scheduler/native-windows.json#N03
; VA 0x4a0b70..0x4a0b76 raw 0x9ff70 SHA256 1e05d35a243922405ca3eba158b4de07e454da4919db9eb54ebbbeea5e0e181a
0x4a0b70  ff25a025bd00  jmp    DWORD PTR ds:0xbd25a0

; N18 003F eight-byte report builder
; REUSED kr-extra-roy/MEF-A-minimal-spec-20261116/evidence.json#report_builder
; VA 0x4a39a0..0x4a39ec raw 0xa2da0 SHA256 dbb0c12cfc16ef6738deb33fda9cb2b410be3aae67e89a6df6b71e7fd1711976
0x4a39a0  55  push   ebp
0x4a39a1  8bec  mov    ebp,esp
0x4a39a3  83ec08  sub    esp,0x8
0x4a39a6  833d98a7fb0000  cmp    DWORD PTR ds:0xfba798,0x0
0x4a39ad  668b4d08  mov    cx,WORD PTR [ebp+0x8]
0x4a39b1  668b550c  mov    dx,WORD PTR [ebp+0xc]
0x4a39b5  b83f000000  mov    eax,0x3f
0x4a39ba  668945f8  mov    WORD PTR [ebp-0x8],ax
0x4a39be  b801000000  mov    eax,0x1
0x4a39c3  66894dfa  mov    WORD PTR [ebp-0x6],cx
0x4a39c7  668955fc  mov    WORD PTR [ebp-0x4],dx
0x4a39cb  668945fe  mov    WORD PTR [ebp-0x2],ax
0x4a39cf  7515  jne    0x4a39e6
0x4a39d1  8b0d54a8fb00  mov    ecx,DWORD PTR ds:0xfba854
0x4a39d7  8b11  mov    edx,DWORD PTR [ecx]
0x4a39d9  8b5210  mov    edx,DWORD PTR [edx+0x10]
0x4a39dc  6a08  push   0x8
0x4a39de  8d45f8  lea    eax,[ebp-0x8]
0x4a39e1  50  push   eax
0x4a39e2  6a00  push   0x0
0x4a39e4  ffd2  call   edx
0x4a39e6  8be5  mov    esp,ebp
0x4a39e8  5d  pop    ebp
0x4a39e9  c20800  ret    0x8

; N19 global DoFile result and protected top-level
; REUSED kr-extra-roy/MEF-end-to-end-20261116/entry/native-windows.json#global_dofile
; VA 0x6f48a0..0x6f4a50 raw 0x2f3ca0 SHA256 fe72d7521c01ead56408d1bbbd30cf82046b0628cec91235a1db2f732002253e
0x6f48a0  55  push   ebp
0x6f48a1  8bec  mov    ebp,esp
0x6f48a3  83e4f8  and    esp,0xfffffff8
0x6f48a6  83ec1c  sub    esp,0x1c
0x6f48a9  53  push   ebx
0x6f48aa  56  push   esi
0x6f48ab  57  push   edi
0x6f48ac  8b7d08  mov    edi,DWORD PTR [ebp+0x8]
0x6f48af  8b7708  mov    esi,DWORD PTR [edi+0x8]
0x6f48b2  83ee10  sub    esi,0x10
0x6f48b5  837e0804  cmp    DWORD PTR [esi+0x8],0x4
0x6f48b9  7425  je     0x6f48e0
0x6f48bb  e8106d0000  call   0x6fb5d0
0x6f48c0  85c0  test   eax,eax
0x6f48c2  7504  jne    0x6f48c8
0x6f48c4  33f6  xor    esi,esi
0x6f48c6  eb1d  jmp    0x6f48e5
0x6f48c8  8b4710  mov    eax,DWORD PTR [edi+0x10]
0x6f48cb  8b4844  mov    ecx,DWORD PTR [eax+0x44]
0x6f48ce  3b4840  cmp    ecx,DWORD PTR [eax+0x40]
0x6f48d1  7207  jb     0x6f48da
0x6f48d3  8bc7  mov    eax,edi
0x6f48d5  e8c66a0000  call   0x6fb3a0
0x6f48da  8b7708  mov    esi,DWORD PTR [edi+0x8]
0x6f48dd  83ee10  sub    esi,0x10
0x6f48e0  8b36  mov    esi,DWORD PTR [esi]
0x6f48e2  83c610  add    esi,0x10
0x6f48e5  68e0d1be00  push   0xbed1e0
0x6f48ea  56  push   esi
0x6f48eb  c744241401000000  mov    DWORD PTR [esp+0x14],0x1
0x6f48f3  e878fe0100  call   0x714770
0x6f48f8  8bf0  mov    esi,eax
0x6f48fa  83c408  add    esp,0x8
0x6f48fd  85f6  test   esi,esi
0x6f48ff  0f842b010000  je     0x6f4a30
0x6f4905  8b16  mov    edx,DWORD PTR [esi]
0x6f4907  8b422c  mov    eax,DWORD PTR [edx+0x2c]
0x6f490a  8bce  mov    ecx,esi
0x6f490c  ffd0  call   eax
0x6f490e  8bd8  mov    ebx,eax
0x6f4910  8d4b01  lea    ecx,[ebx+0x1]
0x6f4913  51  push   ecx
0x6f4914  e824931800  call   0x87dc3d
0x6f4919  8b16  mov    edx,DWORD PTR [esi]
0x6f491b  83c404  add    esp,0x4
0x6f491e  8944240c  mov    DWORD PTR [esp+0xc],eax
0x6f4922  8b4238  mov    eax,DWORD PTR [edx+0x38]
0x6f4925  53  push   ebx
0x6f4926  8bce  mov    ecx,esi
0x6f4928  ffd0  call   eax
0x6f492a  8b4c2410  mov    ecx,DWORD PTR [esp+0x10]
0x6f492e  50  push   eax
0x6f492f  51  push   ecx
0x6f4930  e89b921a00  call   0x89dbd0
0x6f4935  8b542418  mov    edx,DWORD PTR [esp+0x18]
0x6f4939  c6041300  mov    BYTE PTR [ebx+edx*1],0x0
0x6f493d  8b06  mov    eax,DWORD PTR [esi]
0x6f493f  8b502c  mov    edx,DWORD PTR [eax+0x2c]
0x6f4942  83c40c  add    esp,0xc
0x6f4945  8bce  mov    ecx,esi
0x6f4947  ffd2  call   edx
0x6f4949  8b5c240c  mov    ebx,DWORD PTR [esp+0xc]
0x6f494d  83f803  cmp    eax,0x3
0x6f4950  7242  jb     0x6f4994
0x6f4952  803bef  cmp    BYTE PTR [ebx],0xef
0x6f4955  753d  jne    0x6f4994
0x6f4957  807b01bb  cmp    BYTE PTR [ebx+0x1],0xbb
0x6f495b  7537  jne    0x6f4994
0x6f495d  807b02bf  cmp    BYTE PTR [ebx+0x2],0xbf
0x6f4961  7531  jne    0x6f4994
0x6f4963  83c0fd  add    eax,0xfffffffd
0x6f4966  50  push   eax
0x6f4967  8d4303  lea    eax,[ebx+0x3]
0x6f496a  50  push   eax
0x6f496b  33c0  xor    eax,eax
0x6f496d  8bd7  mov    edx,edi
0x6f496f  e89c270000  call   0x6f7110
0x6f4974  83c408  add    esp,0x8
0x6f4977  85c0  test   eax,eax
0x6f4979  0f8597000000  jne    0x6f4a16
0x6f497f  8b4708  mov    eax,DWORD PTR [edi+0x8]
0x6f4982  83e810  sub    eax,0x10
0x6f4985  8944240c  mov    DWORD PTR [esp+0xc],eax
0x6f4989  2b4720  sub    eax,DWORD PTR [edi+0x20]
0x6f498c  8d4c240c  lea    ecx,[esp+0xc]
0x6f4990  50  push   eax
0x6f4991  51  push   ecx
0x6f4992  eb4f  jmp    0x6f49e3
0x6f4994  89442410  mov    DWORD PTR [esp+0x10],eax
0x6f4998  33c0  xor    eax,eax
0x6f499a  8d54240c  lea    edx,[esp+0xc]
0x6f499e  89442414  mov    DWORD PTR [esp+0x14],eax
0x6f49a2  89442418  mov    DWORD PTR [esp+0x18],eax
0x6f49a6  57  push   edi
0x6f49a7  b90027c400  mov    ecx,0xc42700
0x6f49ac  8d442418  lea    eax,[esp+0x18]
0x6f49b0  895c2410  mov    DWORD PTR [esp+0x10],ebx
0x6f49b4  897c2428  mov    DWORD PTR [esp+0x28],edi
0x6f49b8  c7442420e0706f00  mov    DWORD PTR [esp+0x20],0x6f70e0
0x6f49c0  89542424  mov    DWORD PTR [esp+0x24],edx
0x6f49c4  e8c79f0000  call   0x6fe990
0x6f49c9  83c404  add    esp,0x4
0x6f49cc  85c0  test   eax,eax
0x6f49ce  7546  jne    0x6f4a16
0x6f49d0  8b4708  mov    eax,DWORD PTR [edi+0x8]
0x6f49d3  83e810  sub    eax,0x10
0x6f49d6  8944240c  mov    DWORD PTR [esp+0xc],eax
0x6f49da  2b4720  sub    eax,DWORD PTR [edi+0x20]
0x6f49dd  50  push   eax
0x6f49de  8d442410  lea    eax,[esp+0x10]
0x6f49e2  50  push   eax
0x6f49e3  68505a6f00  push   0x6f5a50
0x6f49e8  33d2  xor    edx,edx
0x6f49ea  8bc7  mov    eax,edi
0x6f49ec  c744241cffffffff  mov    DWORD PTR [esp+0x1c],0xffffffff
0x6f49f4  e8779d0000  call   0x6fe770
0x6f49f9  8b4f14  mov    ecx,DWORD PTR [edi+0x14]
0x6f49fc  8b5708  mov    edx,DWORD PTR [edi+0x8]
0x6f49ff  83c40c  add    esp,0xc
0x6f4a02  3b5108  cmp    edx,DWORD PTR [ecx+0x8]
0x6f4a05  7203  jb     0x6f4a0a
0x6f4a07  895108  mov    DWORD PTR [ecx+0x8],edx
0x6f4a0a  c744240c00000000  mov    DWORD PTR [esp+0xc],0x0
0x6f4a12  85c0  test   eax,eax
0x6f4a14  7408  je     0x6f4a1e
0x6f4a16  c744240c01000000  mov    DWORD PTR [esp+0xc],0x1
0x6f4a1e  8b16  mov    edx,DWORD PTR [esi]
0x6f4a20  8b4204  mov    eax,DWORD PTR [edx+0x4]
0x6f4a23  8bce  mov    ecx,esi
0x6f4a25  ffd0  call   eax
0x6f4a27  53  push   ebx
0x6f4a28  e810d31900  call   0x891d3d
0x6f4a2d  83c404  add    esp,0x4
0x6f4a30  8b4708  mov    eax,DWORD PTR [edi+0x8]
0x6f4a33  db44240c  fild   DWORD PTR [esp+0xc]
0x6f4a37  c7400803000000  mov    DWORD PTR [eax+0x8],0x3
0x6f4a3e  dd18  fstp   QWORD PTR [eax]
0x6f4a40  83470810  add    DWORD PTR [edi+0x8],0x10
0x6f4a44  5f  pop    edi
0x6f4a45  5e  pop    esi
0x6f4a46  b801000000  mov    eax,0x1
0x6f4a4b  5b  pop    ebx
0x6f4a4c  8be5  mov    esp,ebp
0x6f4a4e  5d  pop    ebp
0x6f4a4f  c3  ret

; N20 TutorialBase bootstrap and common VM wrapper
; REUSED kr-extra-roy/MEF-world-integration-20261115/runner/native-windows.json#R02
; VA 0x4a88e0..0x4a89bf raw 0xa7ce0 SHA256 c02c1bb33b21151db1ec5bbeffe4086005d24a77413a8d395d70428a8a528ff0
0x4a88e0  55  push   ebp
0x4a88e1  8bec  mov    ebp,esp
0x4a88e3  83ec08  sub    esp,0x8
0x4a88e6  8d4dfc  lea    ecx,[ebp-0x4]
0x4a88e9  56  push   esi
0x4a88ea  51  push   ecx
0x4a88eb  8930  mov    DWORD PTR [eax],esi
0x4a88ed  e8ae1c0000  call   0x4aa5a0
0x4a88f2  83c408  add    esp,0x8
0x4a88f5  50  push   eax
0x4a88f6  e8851d0000  call   0x4aa680
0x4a88fb  50  push   eax
0x4a88fc  e81f1e0000  call   0x4aa720
0x4a8901  50  push   eax
0x4a8902  e8b91e0000  call   0x4aa7c0
0x4a8907  50  push   eax
0x4a8908  e8531f0000  call   0x4aa860
0x4a890d  50  push   eax
0x4a890e  e8ed1f0000  call   0x4aa900
0x4a8913  50  push   eax
0x4a8914  e887200000  call   0x4aa9a0
0x4a8919  50  push   eax
0x4a891a  e821210000  call   0x4aaa40
0x4a891f  50  push   eax
0x4a8920  e8bb210000  call   0x4aaae0
0x4a8925  50  push   eax
0x4a8926  e855220000  call   0x4aab80
0x4a892b  50  push   eax
0x4a892c  e8ef220000  call   0x4aac20
0x4a8931  50  push   eax
0x4a8932  e889230000  call   0x4aacc0
0x4a8937  50  push   eax
0x4a8938  e823240000  call   0x4aad60
0x4a893d  50  push   eax
0x4a893e  e8bd240000  call   0x4aae00
0x4a8943  50  push   eax
0x4a8944  e857250000  call   0x4aaea0
0x4a8949  50  push   eax
0x4a894a  e8f1250000  call   0x4aaf40
0x4a894f  50  push   eax
0x4a8950  e88b260000  call   0x4aafe0
0x4a8955  50  push   eax
0x4a8956  e825270000  call   0x4ab080
0x4a895b  50  push   eax
0x4a895c  e8bf270000  call   0x4ab120
0x4a8961  50  push   eax
0x4a8962  e859280000  call   0x4ab1c0
0x4a8967  50  push   eax
0x4a8968  e8f3280000  call   0x4ab260
0x4a896d  50  push   eax
0x4a896e  e88d290000  call   0x4ab300
0x4a8973  50  push   eax
0x4a8974  e8272a0000  call   0x4ab3a0
0x4a8979  50  push   eax
0x4a897a  e8c12a0000  call   0x4ab440
0x4a897f  50  push   eax
0x4a8980  e85b2b0000  call   0x4ab4e0
0x4a8985  50  push   eax
0x4a8986  e8f52b0000  call   0x4ab580
0x4a898b  50  push   eax
0x4a898c  e88f2c0000  call   0x4ab620
0x4a8991  50  push   eax
0x4a8992  e8292d0000  call   0x4ab6c0
0x4a8997  50  push   eax
0x4a8998  e8c32d0000  call   0x4ab760
0x4a899d  50  push   eax
0x4a899e  e85d2e0000  call   0x4ab800
0x4a89a3  50  push   eax
0x4a89a4  e8f72e0000  call   0x4ab8a0
0x4a89a9  50  push   eax
0x4a89aa  e8912f0000  call   0x4ab940
0x4a89af  686468c000  push   0xc06864
0x4a89b4  8bce  mov    ecx,esi
0x4a89b6  e895c02400  call   0x6f4a50
0x4a89bb  8be5  mov    esp,ebp
0x4a89bd  5d  pop    ebp
0x4a89be  c3  ret

; N21 Event/Sequences/ and .seq literal components
; REUSED kr-extra-roy/MEF-delivery-windows-20261114/native-windows.json#scene/local-script-path-and-map-strings
; VA 0xc106d0..0xc106e9 raw 0x80ecd0 SHA256 e6f4f9beaa12abb3c20104bec23ae645af4c257f326b37d7173a35b20cac4b01
data 4576656e742f53657175656e6365732f000000002e73657100

; N22 Start busy gate is not a content queue
; REUSED kr-extra-roy/MEF-end-to-end-20261116/entry/native-windows.json#q_start_and_skip
; VA 0x5617c2..0x5617e9 raw 0x160bc2 SHA256 1c0149e9f876f484ca25f99818090a91e196a113c3916d0a90176a6e4bad5818
0x5617c2  837b2800  cmp    DWORD PTR [ebx+0x28],0x0
0x5617c6  c6838900000000  mov    BYTE PTR [ebx+0x89],0x0
0x5617cd  741a  je     0x5617e9
0x5617cf  8b450c  mov    eax,DWORD PTR [ebp+0xc]
0x5617d2  8b4d08  mov    ecx,DWORD PTR [ebp+0x8]
0x5617d5  50  push   eax
0x5617d6  51  push   ecx
0x5617d7  68ac06c100  push   0xc106ac
0x5617dc  e87fc31800  call   0x6edb60
0x5617e1  83c40c  add    esp,0xc
0x5617e4  e99d050000  jmp    0x561d86

