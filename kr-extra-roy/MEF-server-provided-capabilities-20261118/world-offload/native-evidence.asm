; world_getter | same world FAB130 receiver | root 0x40f060
0x40f060: 55  push   ebp
0x40f061: 8bec  mov    ebp,esp
0x40f063: 83e4f8  and    esp,0xfffffff8
0x40f066: 6aff  push   0xffffffff
0x40f068: 68ee619400  push   0x9461ee
0x40f06d: 64a100000000  mov    eax,fs:0x0
0x40f073: 50  push   eax
0x40f074: 51  push   ecx
0x40f075: a1201fd600  mov    eax,ds:0xd61f20
0x40f07a: 33c4  xor    eax,esp
0x40f07c: 50  push   eax
0x40f07d: 8d442408  lea    eax,[esp+0x8]
0x40f081: 64a300000000  mov    fs:0x0,eax
0x40f087: b801000000  mov    eax,0x1
0x40f08c: 84052cb2fa00  test   BYTE PTR ds:0xfab22c,al
0x40f092: 7520  jne    0x40f0b4
0x40f094: 09052cb2fa00  or     DWORD PTR ds:0xfab22c,eax
0x40f09a: c744241000000000  mov    DWORD PTR [esp+0x10],0x0
0x40f0a2: e8e9fb0c00  call   0x4dec90
0x40f0a7: 6830cebc00  push   0xbcce30
0x40f0ac: e869324800  call   0x89231a
0x40f0b1: 83c404  add    esp,0x4
0x40f0b4: b830b1fa00  mov    eax,0xfab130
0x40f0b9: 8b4c2408  mov    ecx,DWORD PTR [esp+0x8]
0x40f0bd: 64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x40f0c4: 59  pop    ecx
0x40f0c5: 8be5  mov    esp,ebp
0x40f0c7: 5d  pop    ebp
0x40f0c8: c3  ret
0x40f0c9: cc  int3
0x40f0ca: cc  int3
0x40f0cb: cc  int3
0x40f0cc: cc  int3
0x40f0cd: cc  int3
0x40f0ce: cc  int3
0x40f0cf: cc  int3

; frame_world_step | selected frame gate and world update call | root 0x490fe0
0x491ca7: 39b7ccbf0000  cmp    DWORD PTR [edi+0xbfcc],esi
0x491cad: 7554  jne    0x491d03
0x491caf: e8acd3f7ff  call   0x40f060
0x491cb4: 8bc8  mov    ecx,eax
0x491cb6: e8a5e30400  call   0x4e0060

; world_step | controller v+2c then world iterator | root 0x4e0060
0x4e0060: 55  push   ebp
0x4e0061: 8bec  mov    ebp,esp
0x4e0063: 6aff  push   0xffffffff
0x4e0065: 68bab19300  push   0x93b1ba
0x4e006a: 64a100000000  mov    eax,fs:0x0
0x4e0070: 50  push   eax
0x4e0071: 83ec20  sub    esp,0x20
0x4e0074: a1201fd600  mov    eax,ds:0xd61f20
0x4e0079: 33c5  xor    eax,ebp
0x4e007b: 8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4e007e: 56  push   esi
0x4e007f: 57  push   edi
0x4e0080: 50  push   eax
0x4e0081: 8d45f4  lea    eax,[ebp-0xc]
0x4e0084: 64a300000000  mov    fs:0x0,eax
0x4e008a: 8bf9  mov    edi,ecx
0x4e008c: f30f1087ac000000  movss  xmm0,DWORD PTR [edi+0xac]
0x4e0094: 0f2f056c56c500  comiss xmm0,DWORD PTR ds:0xc5566c
0x4e009b: 8b0da4a7fb00  mov    ecx,DWORD PTR ds:0xfba7a4
0x4e00a1: be01000000  mov    esi,0x1
0x4e00a6: 7603  jbe    0x4e00ab
0x4e00a8: 897158  mov    DWORD PTR [ecx+0x58],esi
0x4e00ab: 8b01  mov    eax,DWORD PTR [ecx]
0x4e00ad: 8b502c  mov    edx,DWORD PTR [eax+0x2c]
0x4e00b0: ffd2  call   edx
0x4e00b2: 8b470c  mov    eax,DWORD PTR [edi+0xc]
0x4e00b5: 8b08  mov    ecx,DWORD PTR [eax]
0x4e00b7: c645d400  mov    BYTE PTR [ebp-0x2c],0x0
0x4e00bb: 8b55d4  mov    edx,DWORD PTR [ebp-0x2c]
0x4e00be: 52  push   edx
0x4e00bf: 50  push   eax
0x4e00c0: 51  push   ecx
0x4e00c1: e82a130000  call   0x4e13f0
0x4e00c6: 83c40c  add    esp,0xc
0x4e00c9: f605b873fb0001  test   BYTE PTR ds:0xfb73b8,0x1
0x4e00d0: 7526  jne    0x4e00f8
0x4e00d2: 0935b873fb00  or     DWORD PTR ds:0xfb73b8,esi
0x4e00d8: c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x4e00df: e88c000800  call   0x560170
0x4e00e4: 6810d1bc00  push   0xbcd110
0x4e00e9: e82c223b00  call   0x89231a
0x4e00ee: 83c404  add    esp,0x4
0x4e00f1: c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e00f8: 833de873fb0000  cmp    DWORD PTR ds:0xfb73e8,0x0
0x4e00ff: 0f84cd000000  je     0x4e01d2
0x4e0105: f605d4b0fa0001  test   BYTE PTR ds:0xfab0d4,0x1
0x4e010c: 7522  jne    0x4e0130
0x4e010e: 0935d4b0fa00  or     DWORD PTR ds:0xfab0d4,esi
0x4e0114: 8975fc  mov    DWORD PTR [ebp-0x4],esi
0x4e0117: e884a23200  call   0x80a3a0
0x4e011c: 68d0cdbc00  push   0xbccdd0
0x4e0121: e8f4213b00  call   0x89231a
0x4e0126: 83c404  add    esp,0x4
0x4e0129: c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e0130: 833d90b0fa0000  cmp    DWORD PTR ds:0xfab090,0x0
0x4e0137: 7521  jne    0x4e015a
0x4e0139: 8b0d28b0fa00  mov    ecx,DWORD PTR ds:0xfab028
0x4e013f: 85c9  test   ecx,ecx
0x4e0141: 7417  je     0x4e015a
0x4e0143: 8b01  mov    eax,DWORD PTR [ecx]
0x4e0145: 8b5020  mov    edx,DWORD PTR [eax+0x20]
0x4e0148: ffd2  call   edx
0x4e014a: a390b0fa00  mov    ds:0xfab090,eax
0x4e014f: 8b10  mov    edx,DWORD PTR [eax]
0x4e0151: 8bc8  mov    ecx,eax
0x4e0153: 8b4218  mov    eax,DWORD PTR [edx+0x18]
0x4e0156: 6a03  push   0x3
0x4e0158: ffd0  call   eax
0x4e015a: f605e879fb0001  test   BYTE PTR ds:0xfb79e8,0x1
0x4e0161: 8b3590b0fa00  mov    esi,DWORD PTR ds:0xfab090
0x4e0167: 7527  jne    0x4e0190
0x4e0169: 830de879fb0001  or     DWORD PTR ds:0xfb79e8,0x1
0x4e0170: c745fc02000000  mov    DWORD PTR [ebp-0x4],0x2
0x4e0177: e8648c2b00  call   0x798de0
0x4e017c: 68e0d2bc00  push   0xbcd2e0
0x4e0181: e894213b00  call   0x89231a
0x4e0186: 83c404  add    esp,0x4
0x4e0189: c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e0190: a1e876fb00  mov    eax,ds:0xfb76e8
0x4e0195: 8b480c  mov    ecx,DWORD PTR [eax+0xc]
0x4e0198: 8b5010  mov    edx,DWORD PTR [eax+0x10]
0x4e019b: 8b4014  mov    eax,DWORD PTR [eax+0x14]
0x4e019e: 894dd8  mov    DWORD PTR [ebp-0x28],ecx
0x4e01a1: d945d8  fld    DWORD PTR [ebp-0x28]
0x4e01a4: dd059858c500  fld    QWORD PTR ds:0xc55898
0x4e01aa: 8955dc  mov    DWORD PTR [ebp-0x24],edx
0x4e01ad: dcc9  fmul   st(1),st
0x4e01af: 8945e0  mov    DWORD PTR [ebp-0x20],eax
0x4e01b2: d9c9  fxch   st(1)
0x4e01b4: 8d45e4  lea    eax,[ebp-0x1c]
0x4e01b7: 50  push   eax
0x4e01b8: d95de4  fstp   DWORD PTR [ebp-0x1c]
0x4e01bb: 8bce  mov    ecx,esi
0x4e01bd: d945dc  fld    DWORD PTR [ebp-0x24]
0x4e01c0: d8c9  fmul   st,st(1)
0x4e01c2: d95de8  fstp   DWORD PTR [ebp-0x18]
0x4e01c5: d84de0  fmul   DWORD PTR [ebp-0x20]
0x4e01c8: d95dec  fstp   DWORD PTR [ebp-0x14]
0x4e01cb: 8b16  mov    edx,DWORD PTR [esi]
0x4e01cd: 8b520c  mov    edx,DWORD PTR [edx+0xc]
0x4e01d0: ffd2  call   edx
0x4e01d2: 81c7d0000000  add    edi,0xd0
0x4e01d8: 57  push   edi
0x4e01d9: e8f26c1f00  call   0x6d6ed0
0x4e01de: 33c0  xor    eax,eax
0x4e01e0: 8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4e01e3: 64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4e01ea: 59  pop    ecx
0x4e01eb: 5f  pop    edi
0x4e01ec: 5e  pop    esi
0x4e01ed: 8b4df0  mov    ecx,DWORD PTR [ebp-0x10]
0x4e01f0: 33cd  xor    ecx,ebp
0x4e01f2: e80a0e3b00  call   0x891001
0x4e01f7: 8be5  mov    esp,ebp
0x4e01f9: 5d  pop    ebp
0x4e01fa: c3  ret
0x4e01fb: cc  int3
0x4e01fc: cc  int3
0x4e01fd: cc  int3
0x4e01fe: cc  int3
0x4e01ff: cc  int3

; world_step_iterator | node+10 actor v+20 | root 0x4e13f0
0x4e13f0: 55  push   ebp
0x4e13f1: 8bec  mov    ebp,esp
0x4e13f3: 8b4d08  mov    ecx,DWORD PTR [ebp+0x8]
0x4e13f6: 3b4d0c  cmp    ecx,DWORD PTR [ebp+0xc]
0x4e13f9: 7462  je     0x4e145d
0x4e13fb: eb03  jmp    0x4e1400
0x4e13fd: 8d4900  lea    ecx,[ecx+0x0]
0x4e1400: 8b4910  mov    ecx,DWORD PTR [ecx+0x10]
0x4e1403: 8b01  mov    eax,DWORD PTR [ecx]
0x4e1405: 8b5020  mov    edx,DWORD PTR [eax+0x20]
0x4e1408: ffd2  call   edx
0x4e140a: 8b4d08  mov    ecx,DWORD PTR [ebp+0x8]
0x4e140d: 80791500  cmp    BYTE PTR [ecx+0x15],0x0
0x4e1411: 7545  jne    0x4e1458
0x4e1413: 8b4108  mov    eax,DWORD PTR [ecx+0x8]
0x4e1416: 80781500  cmp    BYTE PTR [eax+0x15],0x0
0x4e141a: 7516  jne    0x4e1432
0x4e141c: 8bc8  mov    ecx,eax
0x4e141e: 8b01  mov    eax,DWORD PTR [ecx]
0x4e1420: 80781500  cmp    BYTE PTR [eax+0x15],0x0
0x4e1424: 752f  jne    0x4e1455
0x4e1426: 8bc8  mov    ecx,eax
0x4e1428: 8b01  mov    eax,DWORD PTR [ecx]
0x4e142a: 80781500  cmp    BYTE PTR [eax+0x15],0x0
0x4e142e: 74f6  je     0x4e1426
0x4e1430: eb23  jmp    0x4e1455
0x4e1432: 8b4104  mov    eax,DWORD PTR [ecx+0x4]
0x4e1435: 80781500  cmp    BYTE PTR [eax+0x15],0x0
0x4e1439: 7518  jne    0x4e1453
0x4e143b: eb03  jmp    0x4e1440
0x4e143d: 8d4900  lea    ecx,[ecx+0x0]
0x4e1440: 3b4808  cmp    ecx,DWORD PTR [eax+0x8]
0x4e1443: 750e  jne    0x4e1453
0x4e1445: 8bc8  mov    ecx,eax
0x4e1447: 894d08  mov    DWORD PTR [ebp+0x8],ecx
0x4e144a: 8b4004  mov    eax,DWORD PTR [eax+0x4]
0x4e144d: 80781500  cmp    BYTE PTR [eax+0x15],0x0
0x4e1451: 74ed  je     0x4e1440
0x4e1453: 8bc8  mov    ecx,eax
0x4e1455: 894d08  mov    DWORD PTR [ebp+0x8],ecx
0x4e1458: 3b4d0c  cmp    ecx,DWORD PTR [ebp+0xc]
0x4e145b: 75a3  jne    0x4e1400
0x4e145d: 8a4510  mov    al,BYTE PTR [ebp+0x10]
0x4e1460: 5d  pop    ebp
0x4e1461: c3  ret
0x4e1462: cc  int3
0x4e1463: cc  int3
0x4e1464: cc  int3
0x4e1465: cc  int3
0x4e1466: cc  int3
0x4e1467: cc  int3
0x4e1468: cc  int3
0x4e1469: cc  int3
0x4e146a: cc  int3
0x4e146b: cc  int3
0x4e146c: cc  int3
0x4e146d: cc  int3
0x4e146e: cc  int3
0x4e146f: cc  int3

; monster_step_thunk | CMonster v+20 tail target | root 0x4d1ae0
0x4d1ae0: e99b6affff  jmp    0x4c8580

; actor_step | native movement direction effects counters | root 0x4c8580
0x4c8580: 55  push   ebp
0x4c8581: 8bec  mov    ebp,esp
0x4c8583: 6aff  push   0xffffffff
0x4c8585: 68fcb19300  push   0x93b1fc
0x4c858a: 64a100000000  mov    eax,fs:0x0
0x4c8590: 50  push   eax
0x4c8591: 83ec30  sub    esp,0x30
0x4c8594: a1201fd600  mov    eax,ds:0xd61f20
0x4c8599: 33c5  xor    eax,ebp
0x4c859b: 8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4c859e: 53  push   ebx
0x4c859f: 56  push   esi
0x4c85a0: 57  push   edi
0x4c85a1: 50  push   eax
0x4c85a2: 8d45f4  lea    eax,[ebp-0xc]
0x4c85a5: 64a300000000  mov    fs:0x0,eax
0x4c85ab: 8bd9  mov    ebx,ecx
0x4c85ad: e8de220000  call   0x4ca890
0x4c85b2: 8b03  mov    eax,DWORD PTR [ebx]
0x4c85b4: 8b5038  mov    edx,DWORD PTR [eax+0x38]
0x4c85b7: bf01000000  mov    edi,0x1
0x4c85bc: 8bcb  mov    ecx,ebx
0x4c85be: 89bbac000000  mov    DWORD PTR [ebx+0xac],edi
0x4c85c4: ffd2  call   edx
0x4c85c6: 8bcb  mov    ecx,ebx
0x4c85c8: e8d3030000  call   0x4c89a0
0x4c85cd: 8b0da4a7fb00  mov    ecx,DWORD PTR ds:0xfba7a4
0x4c85d3: 8b01  mov    eax,DWORD PTR [ecx]
0x4c85d5: 8b5020  mov    edx,DWORD PTR [eax+0x20]
0x4c85d8: ffd2  call   edx
0x4c85da: 3bd8  cmp    ebx,eax
0x4c85dc: 0f85da000000  jne    0x4c86bc
0x4c85e2: f605b873fb0001  test   BYTE PTR ds:0xfb73b8,0x1
0x4c85e9: 7526  jne    0x4c8611
0x4c85eb: 093db873fb00  or     DWORD PTR ds:0xfb73b8,edi
0x4c85f1: c745fc00000000  mov    DWORD PTR [ebp-0x4],0x0
0x4c85f8: e8737b0900  call   0x560170
0x4c85fd: 6810d1bc00  push   0xbcd110
0x4c8602: e8139d3c00  call   0x89231a
0x4c8607: 83c404  add    esp,0x4
0x4c860a: c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c8611: 833de873fb0000  cmp    DWORD PTR ds:0xfb73e8,0x0
0x4c8618: 0f859e000000  jne    0x4c86bc
0x4c861e: f605d4b0fa0001  test   BYTE PTR ds:0xfab0d4,0x1
0x4c8625: 7522  jne    0x4c8649
0x4c8627: 093dd4b0fa00  or     DWORD PTR ds:0xfab0d4,edi
0x4c862d: 897dfc  mov    DWORD PTR [ebp-0x4],edi
0x4c8630: e86b1d3400  call   0x80a3a0
0x4c8635: 68d0cdbc00  push   0xbccdd0
0x4c863a: e8db9c3c00  call   0x89231a
0x4c863f: 83c404  add    esp,0x4
0x4c8642: c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c8649: 833d90b0fa0000  cmp    DWORD PTR ds:0xfab090,0x0
0x4c8650: 7521  jne    0x4c8673
0x4c8652: 8b0d28b0fa00  mov    ecx,DWORD PTR ds:0xfab028
0x4c8658: 85c9  test   ecx,ecx
0x4c865a: 7417  je     0x4c8673
0x4c865c: 8b01  mov    eax,DWORD PTR [ecx]
0x4c865e: 8b5020  mov    edx,DWORD PTR [eax+0x20]
0x4c8661: ffd2  call   edx
0x4c8663: a390b0fa00  mov    ds:0xfab090,eax
0x4c8668: 8b10  mov    edx,DWORD PTR [eax]
0x4c866a: 8bc8  mov    ecx,eax
0x4c866c: 8b4218  mov    eax,DWORD PTR [edx+0x18]
0x4c866f: 6a03  push   0x3
0x4c8671: ffd0  call   eax
0x4c8673: 8b13  mov    edx,DWORD PTR [ebx]
0x4c8675: 8b5250  mov    edx,DWORD PTR [edx+0x50]
0x4c8678: 8b3590b0fa00  mov    esi,DWORD PTR ds:0xfab090
0x4c867e: 8d45d8  lea    eax,[ebp-0x28]
0x4c8681: 50  push   eax
0x4c8682: 8bcb  mov    ecx,ebx
0x4c8684: ffd2  call   edx
0x4c8686: d94004  fld    DWORD PTR [eax+0x4]
0x4c8689: dd059858c500  fld    QWORD PTR ds:0xc55898
0x4c868f: 8d4de4  lea    ecx,[ebp-0x1c]
0x4c8692: dcc9  fmul   st(1),st
0x4c8694: 51  push   ecx
0x4c8695: d9c9  fxch   st(1)
0x4c8697: 8bce  mov    ecx,esi
0x4c8699: d95dc8  fstp   DWORD PTR [ebp-0x38]
0x4c869c: d94008  fld    DWORD PTR [eax+0x8]
0x4c869f: d8c9  fmul   st,st(1)
0x4c86a1: d95dc4  fstp   DWORD PTR [ebp-0x3c]
0x4c86a4: d808  fmul   DWORD PTR [eax]
0x4c86a6: d95de4  fstp   DWORD PTR [ebp-0x1c]
0x4c86a9: d945c8  fld    DWORD PTR [ebp-0x38]
0x4c86ac: d95de8  fstp   DWORD PTR [ebp-0x18]
0x4c86af: d945c4  fld    DWORD PTR [ebp-0x3c]
0x4c86b2: d95dec  fstp   DWORD PTR [ebp-0x14]
0x4c86b5: 8b06  mov    eax,DWORD PTR [esi]
0x4c86b7: 8b500c  mov    edx,DWORD PTR [eax+0xc]
0x4c86ba: ffd2  call   edx
0x4c86bc: 8b836c030000  mov    eax,DWORD PTR [ebx+0x36c]
0x4c86c2: 85c0  test   eax,eax
0x4c86c4: 7409  je     0x4c86cf
0x4c86c6: 48  dec    eax
0x4c86c7: 89836c030000  mov    DWORD PTR [ebx+0x36c],eax
0x4c86cd: eb0a  jmp    0x4c86d9
0x4c86cf: c7836c0300001e000000  mov    DWORD PTR [ebx+0x36c],0x1e
0x4c86d9: 53  push   ebx
0x4c86da: e8e1fcffff  call   0x4c83c0
0x4c86df: 8bb364030000  mov    esi,DWORD PTR [ebx+0x364]
0x4c86e5: 85f6  test   esi,esi
0x4c86e7: 7433  je     0x4c871c
0x4c86e9: e892800800  call   0x550780
0x4c86ee: 8b03  mov    eax,DWORD PTR [ebx]
0x4c86f0: 8b5050  mov    edx,DWORD PTR [eax+0x50]
0x4c86f3: 8d4dd8  lea    ecx,[ebp-0x28]
0x4c86f6: 51  push   ecx
0x4c86f7: 8bcb  mov    ecx,ebx
0x4c86f9: ffd2  call   edx
0x4c86fb: 8b8b64030000  mov    ecx,DWORD PTR [ebx+0x364]
0x4c8701: 8b4924  mov    ecx,DWORD PTR [ecx+0x24]
0x4c8704: 85c9  test   ecx,ecx
0x4c8706: 7414  je     0x4c871c
0x4c8708: 8b10  mov    edx,DWORD PTR [eax]
0x4c870a: 895128  mov    DWORD PTR [ecx+0x28],edx
0x4c870d: 8b5004  mov    edx,DWORD PTR [eax+0x4]
0x4c8710: 89512c  mov    DWORD PTR [ecx+0x2c],edx
0x4c8713: 8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4c8716: 894130  mov    DWORD PTR [ecx+0x30],eax
0x4c8719: 897970  mov    DWORD PTR [ecx+0x70],edi
0x4c871c: 8dbb64010000  lea    edi,[ebx+0x164]
0x4c8722: c745c880000000  mov    DWORD PTR [ebp-0x38],0x80
0x4c8729: 8da42400000000  lea    esp,[esp+0x0]
0x4c8730: 8b37  mov    esi,DWORD PTR [edi]
0x4c8732: 85f6  test   esi,esi
0x4c8734: 7433  je     0x4c8769
0x4c8736: e845800800  call   0x550780
0x4c873b: 8b13  mov    edx,DWORD PTR [ebx]
0x4c873d: 8b5250  mov    edx,DWORD PTR [edx+0x50]
0x4c8740: 8d45cc  lea    eax,[ebp-0x34]
0x4c8743: 50  push   eax
0x4c8744: 8bcb  mov    ecx,ebx
0x4c8746: ffd2  call   edx
0x4c8748: 8b0f  mov    ecx,DWORD PTR [edi]
0x4c874a: 8b4924  mov    ecx,DWORD PTR [ecx+0x24]
0x4c874d: 85c9  test   ecx,ecx
0x4c874f: 7418  je     0x4c8769
0x4c8751: 8b10  mov    edx,DWORD PTR [eax]
0x4c8753: 895128  mov    DWORD PTR [ecx+0x28],edx
0x4c8756: 8b5004  mov    edx,DWORD PTR [eax+0x4]
0x4c8759: 89512c  mov    DWORD PTR [ecx+0x2c],edx
0x4c875c: 8b4008  mov    eax,DWORD PTR [eax+0x8]
0x4c875f: 894130  mov    DWORD PTR [ecx+0x30],eax
0x4c8762: c7417001000000  mov    DWORD PTR [ecx+0x70],0x1
0x4c8769: 83c704  add    edi,0x4
0x4c876c: ff4dc8  dec    DWORD PTR [ebp-0x38]
0x4c876f: 75bf  jne    0x4c8730
0x4c8771: 8b8314040000  mov    eax,DWORD PTR [ebx+0x414]
0x4c8777: 85c0  test   eax,eax
0x4c8779: 741b  je     0x4c8796
0x4c877b: 8bbb10040000  mov    edi,DWORD PTR [ebx+0x410]
0x4c8781: 57  push   edi
0x4c8782: 2bf8  sub    edi,eax
0x4c8784: 8b830c040000  mov    eax,DWORD PTR [ebx+0x40c]
0x4c878a: 53  push   ebx
0x4c878b: e8b0090000  call   0x4c9140
0x4c8790: ff8b14040000  dec    DWORD PTR [ebx+0x414]
0x4c8796: 8b8318040000  mov    eax,DWORD PTR [ebx+0x418]
0x4c879c: 85c0  test   eax,eax
0x4c879e: 7407  je     0x4c87a7
0x4c87a0: 48  dec    eax
0x4c87a1: 898318040000  mov    DWORD PTR [ebx+0x418],eax
0x4c87a7: 33c0  xor    eax,eax
0x4c87a9: 8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x4c87ac: 64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4c87b3: 59  pop    ecx
0x4c87b4: 5f  pop    edi
0x4c87b5: 5e  pop    esi
0x4c87b6: 5b  pop    ebx
0x4c87b7: 8b4df0  mov    ecx,DWORD PTR [ebp-0x10]
0x4c87ba: 33cd  xor    ecx,ebp
0x4c87bc: e840883c00  call   0x891001
0x4c87c1: 8be5  mov    esp,ebp
0x4c87c3: 5d  pop    ebp
0x4c87c4: c3  ret
0x4c87c5: cc  int3
0x4c87c6: cc  int3
0x4c87c7: cc  int3
0x4c87c8: cc  int3
0x4c87c9: cc  int3
0x4c87ca: cc  int3
0x4c87cb: cc  int3
0x4c87cc: cc  int3
0x4c87cd: cc  int3
0x4c87ce: cc  int3
0x4c87cf: cc  int3

; movement_step | movement flags and native positional step | root 0x4ca890
0x4ca890: 55  push   ebp
0x4ca891: 8bec  mov    ebp,esp
0x4ca893: 83e4f8  and    esp,0xfffffff8
0x4ca896: 83ec14  sub    esp,0x14
0x4ca899: 53  push   ebx
0x4ca89a: 56  push   esi
0x4ca89b: 8bf1  mov    esi,ecx
0x4ca89d: 83beac00000000  cmp    DWORD PTR [esi+0xac],0x0
0x4ca8a4: 57  push   edi
0x4ca8a5: 7407  je     0x4ca8ae
0x4ca8a7: 8b06  mov    eax,DWORD PTR [esi]
0x4ca8a9: 8b5038  mov    edx,DWORD PTR [eax+0x38]
0x4ca8ac: ffd2  call   edx
0x4ca8ae: a1cca7fb00  mov    eax,ds:0xfba7cc
0x4ca8b3: 85c0  test   eax,eax
0x4ca8b5: 751f  jne    0x4ca8d6
0x4ca8b7: 6880130000  push   0x1380
0x4ca8bc: e8a7693c00  call   0x891268
0x4ca8c1: 83c404  add    esp,0x4
0x4ca8c4: 85c0  test   eax,eax
0x4ca8c6: 7407  je     0x4ca8cf
0x4ca8c8: e8034b2100  call   0x6df3d0
0x4ca8cd: eb02  jmp    0x4ca8d1
0x4ca8cf: 33c0  xor    eax,eax
0x4ca8d1: a3cca7fb00  mov    ds:0xfba7cc,eax
0x4ca8d6: 83bed400000001  cmp    DWORD PTR [esi+0xd4],0x1
0x4ca8dd: db8060130000  fild   DWORD PTR [eax+0x1360]
0x4ca8e3: d9e8  fld1
0x4ca8e5: def1  fdivrp st(1),st
0x4ca8e7: d95c240c  fstp   DWORD PTR [esp+0xc]
0x4ca8eb: 0f856b010000  jne    0x4caa5c
0x4ca8f1: d986c0000000  fld    DWORD PTR [esi+0xc0]
0x4ca8f7: 8b9ec8000000  mov    ebx,DWORD PTR [esi+0xc8]
0x4ca8fd: d8a6a0000000  fsub   DWORD PTR [esi+0xa0]
0x4ca903: 8dbec0000000  lea    edi,[esi+0xc0]
0x4ca909: d95c2410  fstp   DWORD PTR [esp+0x10]
0x4ca90d: d94704  fld    DWORD PTR [edi+0x4]
0x4ca910: d8a6a4000000  fsub   DWORD PTR [esi+0xa4]
0x4ca916: d95c2414  fstp   DWORD PTR [esp+0x14]
0x4ca91a: 85db  test   ebx,ebx
0x4ca91c: 0f85bc000000  jne    0x4ca9de
0x4ca922: 8b06  mov    eax,DWORD PTR [esi]
0x4ca924: 8b5044  mov    edx,DWORD PTR [eax+0x44]
0x4ca927: 6a01  push   0x1
0x4ca929: 57  push   edi
0x4ca92a: 8bce  mov    ecx,esi
0x4ca92c: ffd2  call   edx
0x4ca92e: 8b07  mov    eax,DWORD PTR [edi]
0x4ca930: 8b4f04  mov    ecx,DWORD PTR [edi+0x4]
0x4ca933: 8986e8000000  mov    DWORD PTR [esi+0xe8],eax
0x4ca939: 898eec000000  mov    DWORD PTR [esi+0xec],ecx
0x4ca93f: d986e8000000  fld    DWORD PTR [esi+0xe8]
0x4ca945: d8a6a0000000  fsub   DWORD PTR [esi+0xa0]
0x4ca94b: d95c240c  fstp   DWORD PTR [esp+0xc]
0x4ca94f: d944240c  fld    DWORD PTR [esp+0xc]
0x4ca953: d95c2418  fstp   DWORD PTR [esp+0x18]
0x4ca957: d986ec000000  fld    DWORD PTR [esi+0xec]
0x4ca95d: d8a6a4000000  fsub   DWORD PTR [esi+0xa4]
0x4ca963: d95c2410  fstp   DWORD PTR [esp+0x10]
0x4ca967: d9442410  fld    DWORD PTR [esp+0x10]
0x4ca96b: d95c241c  fstp   DWORD PTR [esp+0x1c]
0x4ca96f: d9442418  fld    DWORD PTR [esp+0x18]
0x4ca973: d944241c  fld    DWORD PTR [esp+0x1c]
0x4ca977: dcc8  fmul   st(0),st
0x4ca979: d9c1  fld    st(1)
0x4ca97b: deca  fmulp  st(2),st
0x4ca97d: dec1  faddp  st(1),st
0x4ca97f: d95c2418  fstp   DWORD PTR [esp+0x18]
0x4ca983: d905645ac500  fld    DWORD PTR ds:0xc55a64
0x4ca989: d9442418  fld    DWORD PTR [esp+0x18]
0x4ca98d: dff1  fcomip st,st(1)
0x4ca98f: ddd8  fstp   st(0)
0x4ca991: 762c  jbe    0x4ca9bf
0x4ca993: f30f1044240c  movss  xmm0,DWORD PTR [esp+0xc]
0x4ca999: f30f11442418  movss  DWORD PTR [esp+0x18],xmm0
0x4ca99f: f30f10442410  movss  xmm0,DWORD PTR [esp+0x10]
0x4ca9a5: 8b542418  mov    edx,DWORD PTR [esp+0x18]
0x4ca9a9: f30f1144241c  movss  DWORD PTR [esp+0x1c],xmm0
0x4ca9af: 8b44241c  mov    eax,DWORD PTR [esp+0x1c]
0x4ca9b3: 8996d8000000  mov    DWORD PTR [esi+0xd8],edx
0x4ca9b9: 8986dc000000  mov    DWORD PTR [esi+0xdc],eax
0x4ca9bf: b9ff7f0000  mov    ecx,0x7fff
0x4ca9c4: 66218ee2000000  and    WORD PTR [esi+0xe2],cx
0x4ca9cb: c786d400000000000000  mov    DWORD PTR [esi+0xd4],0x0
0x4ca9d5: 33c0  xor    eax,eax
0x4ca9d7: 5f  pop    edi
0x4ca9d8: 5e  pop    esi
0x4ca9d9: 5b  pop    ebx
0x4ca9da: 8be5  mov    esp,ebp
0x4ca9dc: 5d  pop    ebp
0x4ca9dd: c3  ret
0x4ca9de: d9442414  fld    DWORD PTR [esp+0x14]
0x4ca9e2: d9442410  fld    DWORD PTR [esp+0x10]
0x4ca9e6: dcc8  fmul   st(0),st
0x4ca9e8: d9c1  fld    st(1)
0x4ca9ea: deca  fmulp  st(2),st
0x4ca9ec: dec1  faddp  st(1),st
0x4ca9ee: d95c2418  fstp   DWORD PTR [esp+0x18]
0x4ca9f2: d9442418  fld    DWORD PTR [esp+0x18]
0x4ca9f6: e8754e4300  call   0x8ff870
0x4ca9fb: d95c2418  fstp   DWORD PTR [esp+0x18]
0x4ca9ff: d9442418  fld    DWORD PTR [esp+0x18]
0x4caa03: 895c2418  mov    DWORD PTR [esp+0x18],ebx
0x4caa07: db442418  fild   DWORD PTR [esp+0x18]
0x4caa0b: 85db  test   ebx,ebx
0x4caa0d: 7906  jns    0x4caa15
0x4caa0f: d8058056c500  fadd   DWORD PTR ds:0xc55680
0x4caa15: def9  fdivp  st(1),st
0x4caa17: 8d542410  lea    edx,[esp+0x10]
0x4caa1b: 52  push   edx
0x4caa1c: 8bc2  mov    eax,edx
0x4caa1e: 50  push   eax
0x4caa1f: d95c2420  fstp   DWORD PTR [esp+0x20]
0x4caa23: ff15f825bd00  call   DWORD PTR ds:0xbd25f8
0x4caa29: d9442418  fld    DWORD PTR [esp+0x18]
0x4caa2d: 8b16  mov    edx,DWORD PTR [esi]
0x4caa2f: d9c0  fld    st(0)
0x4caa31: d84c2410  fmul   DWORD PTR [esp+0x10]
0x4caa35: 8b5254  mov    edx,DWORD PTR [edx+0x54]
0x4caa38: 8d442410  lea    eax,[esp+0x10]
0x4caa3c: 50  push   eax
0x4caa3d: 8bce  mov    ecx,esi
0x4caa3f: d95c2414  fstp   DWORD PTR [esp+0x14]
0x4caa43: d84c2418  fmul   DWORD PTR [esp+0x18]
0x4caa47: d95c2418  fstp   DWORD PTR [esp+0x18]
0x4caa4b: ffd2  call   edx
0x4caa4d: ff8ec8000000  dec    DWORD PTR [esi+0xc8]
0x4caa53: 33c0  xor    eax,eax
0x4caa55: 5f  pop    edi
0x4caa56: 5e  pop    esi
0x4caa57: 5b  pop    ebx
0x4caa58: 8be5  mov    esp,ebp
0x4caa5a: 5d  pop    ebp
0x4caa5b: c3  ret
0x4caa5c: b800800000  mov    eax,0x8000
0x4caa61: 8bce  mov    ecx,esi
0x4caa63: 668586e2000000  test   WORD PTR [esi+0xe2],ax
0x4caa6a: 7468  je     0x4caad4
0x4caa6c: 8b16  mov    edx,DWORD PTR [esi]
0x4caa6e: 8b4260  mov    eax,DWORD PTR [edx+0x60]
0x4caa71: ffd0  call   eax
0x4caa73: d84c240c  fmul   DWORD PTR [esp+0xc]
0x4caa77: f605187cfb0001  test   BYTE PTR ds:0xfb7c18,0x1
0x4caa7e: 8a9ee4000000  mov    bl,BYTE PTR [esi+0xe4]
0x4caa84: d95c2418  fstp   DWORD PTR [esp+0x18]
0x4caa88: 750c  jne    0x4caa96
0x4caa8a: 830d187cfb0001  or     DWORD PTR ds:0xfb7c18,0x1
0x4caa91: e83a9ff7ff  call   0x4449d0
0x4caa96: 8b16  mov    edx,DWORD PTR [esi]
0x4caa98: 8b5254  mov    edx,DWORD PTR [edx+0x54]
0x4caa9b: 0fb6c3  movzx  eax,bl
0x4caa9e: d904c52080fb00  fld    DWORD PTR [eax*8+0xfb8020]
0x4caaa5: 8d04c52080fb00  lea    eax,[eax*8+0xfb8020]
0x4caaac: d9442418  fld    DWORD PTR [esp+0x18]
0x4caab0: 8bce  mov    ecx,esi
0x4caab2: d9c0  fld    st(0)
0x4caab4: deca  fmulp  st(2),st
0x4caab6: d9c9  fxch   st(1)
0x4caab8: d95c2410  fstp   DWORD PTR [esp+0x10]
0x4caabc: d84804  fmul   DWORD PTR [eax+0x4]
0x4caabf: 8d442410  lea    eax,[esp+0x10]
0x4caac3: 50  push   eax
0x4caac4: d95c2418  fstp   DWORD PTR [esp+0x18]
0x4caac8: ffd2  call   edx
0x4caaca: d905f8c7c000  fld    DWORD PTR ds:0xc0c7f8
0x4caad0: 8bce  mov    ecx,esi
0x4caad2: eb06  jmp    0x4caada
0x4caad4: d905645ac500  fld    DWORD PTR ds:0xc55a64
0x4caada: 6a00  push   0x0
0x4caadc: 83ec08  sub    esp,0x8
0x4caadf: d95c2404  fstp   DWORD PTR [esp+0x4]
0x4caae3: d9442418  fld    DWORD PTR [esp+0x18]
0x4caae7: d91c24  fstp   DWORD PTR [esp]
0x4caaea: e871020000  call   0x4cad60
0x4caaef: 5f  pop    edi
0x4caaf0: 5e  pop    esi
0x4caaf1: 33c0  xor    eax,eax
0x4caaf3: 5b  pop    ebx
0x4caaf4: 8be5  mov    esp,ebp
0x4caaf6: 5d  pop    ebp
0x4caaf7: c3  ret
0x4caaf8: cc  int3
0x4caaf9: cc  int3
0x4caafa: cc  int3
0x4caafb: cc  int3
0x4caafc: cc  int3
0x4caafd: cc  int3
0x4caafe: cc  int3
0x4caaff: cc  int3

; position_delta_gate | candidate position gate then v+44 | root 0x4cabe0
0x4cabe0: 55  push   ebp
0x4cabe1: 8bec  mov    ebp,esp
0x4cabe3: 83e4f8  and    esp,0xfffffff8
0x4cabe6: 6aff  push   0xffffffff
0x4cabe8: 681e6a9300  push   0x936a1e
0x4cabed: 64a100000000  mov    eax,fs:0x0
0x4cabf3: 50  push   eax
0x4cabf4: 83ec18  sub    esp,0x18
0x4cabf7: 56  push   esi
0x4cabf8: a1201fd600  mov    eax,ds:0xd61f20
0x4cabfd: 33c4  xor    eax,esp
0x4cabff: 50  push   eax
0x4cac00: 8d442420  lea    eax,[esp+0x20]
0x4cac04: 64a300000000  mov    fs:0x0,eax
0x4cac0a: 8bf1  mov    esi,ecx
0x4cac0c: f6052cb2fa0001  test   BYTE PTR ds:0xfab22c,0x1
0x4cac13: 7529  jne    0x4cac3e
0x4cac15: 830d2cb2fa0001  or     DWORD PTR ds:0xfab22c,0x1
0x4cac1c: c744242800000000  mov    DWORD PTR [esp+0x28],0x0
0x4cac24: e867400100  call   0x4dec90
0x4cac29: 6830cebc00  push   0xbcce30
0x4cac2e: e8e7763c00  call   0x89231a
0x4cac33: 83c404  add    esp,0x4
0x4cac36: c7442428ffffffff  mov    DWORD PTR [esp+0x28],0xffffffff
0x4cac3e: 8b0dd0b1fa00  mov    ecx,DWORD PTR ds:0xfab1d0
0x4cac44: 85c9  test   ecx,ecx
0x4cac46: 7461  je     0x4caca9
0x4cac48: 8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x4cac4b: d900  fld    DWORD PTR [eax]
0x4cac4d: d886a0000000  fadd   DWORD PTR [esi+0xa0]
0x4cac53: d95c240c  fstp   DWORD PTR [esp+0xc]
0x4cac57: d944240c  fld    DWORD PTR [esp+0xc]
0x4cac5b: d95c2414  fstp   DWORD PTR [esp+0x14]
0x4cac5f: d986a4000000  fld    DWORD PTR [esi+0xa4]
0x4cac65: d84004  fadd   DWORD PTR [eax+0x4]
0x4cac68: 8d442414  lea    eax,[esp+0x14]
0x4cac6c: d95c2410  fstp   DWORD PTR [esp+0x10]
0x4cac70: d9442410  fld    DWORD PTR [esp+0x10]
0x4cac74: d95c2418  fstp   DWORD PTR [esp+0x18]
0x4cac78: e873213600  call   0x82cdf0
0x4cac7d: 85c0  test   eax,eax
0x4cac7f: 7428  je     0x4caca9
0x4cac81: f30f1044240c  movss  xmm0,DWORD PTR [esp+0xc]
0x4cac87: 8b06  mov    eax,DWORD PTR [esi]
0x4cac89: 8b5044  mov    edx,DWORD PTR [eax+0x44]
0x4cac8c: 6a01  push   0x1
0x4cac8e: 8d4c2418  lea    ecx,[esp+0x18]
0x4cac92: f30f11442418  movss  DWORD PTR [esp+0x18],xmm0
0x4cac98: f30f10442414  movss  xmm0,DWORD PTR [esp+0x14]
0x4cac9e: 51  push   ecx
0x4cac9f: 8bce  mov    ecx,esi
0x4caca1: f30f11442420  movss  DWORD PTR [esp+0x20],xmm0
0x4caca7: ffd2  call   edx
0x4caca9: 8b4c2420  mov    ecx,DWORD PTR [esp+0x20]
0x4cacad: 64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4cacb4: 59  pop    ecx
0x4cacb5: 5e  pop    esi
0x4cacb6: 8be5  mov    esp,ebp
0x4cacb8: 5d  pop    ebp
0x4cacb9: c20400  ret    0x4
0x4cacbc: cc  int3
0x4cacbd: cc  int3
0x4cacbe: cc  int3
0x4cacbf: cc  int3

; position_validity | two native grid membership probes; not damage | root 0x82cdf0
0x82cdf0: 55  push   ebp
0x82cdf1: 8bec  mov    ebp,esp
0x82cdf3: 83ec14  sub    esp,0x14
0x82cdf6: 53  push   ebx
0x82cdf7: 56  push   esi
0x82cdf8: 8bf1  mov    esi,ecx
0x82cdfa: 8b5e24  mov    ebx,DWORD PTR [esi+0x24]
0x82cdfd: 57  push   edi
0x82cdfe: 85db  test   ebx,ebx
0x82ce00: 750e  jne    0x82ce10
0x82ce02: 395e28  cmp    DWORD PTR [esi+0x28],ebx
0x82ce05: 7509  jne    0x82ce10
0x82ce07: 33c0  xor    eax,eax
0x82ce09: 5f  pop    edi
0x82ce0a: 5e  pop    esi
0x82ce0b: 5b  pop    ebx
0x82ce0c: 8be5  mov    esp,ebp
0x82ce0e: 5d  pop    ebp
0x82ce0f: c3  ret
0x82ce10: 8b08  mov    ecx,DWORD PTR [eax]
0x82ce12: 8b5004  mov    edx,DWORD PTR [eax+0x4]
0x82ce15: 894df8  mov    DWORD PTR [ebp-0x8],ecx
0x82ce18: 8955fc  mov    DWORD PTR [ebp-0x4],edx
0x82ce1b: 8d4df8  lea    ecx,[ebp-0x8]
0x82ce1e: 8bd6  mov    edx,esi
0x82ce20: e85b000000  call   0x82ce80
0x82ce25: d94614  fld    DWORD PTR [esi+0x14]
0x82ce28: d84df8  fmul   DWORD PTR [ebp-0x8]
0x82ce2b: e8e01e0d00  call   0x8fed10
0x82ce30: d94618  fld    DWORD PTR [esi+0x18]
0x82ce33: d84dfc  fmul   DWORD PTR [ebp-0x4]
0x82ce36: 8bf8  mov    edi,eax
0x82ce38: 897df0  mov    DWORD PTR [ebp-0x10],edi
0x82ce3b: e8d01e0d00  call   0x8fed10
0x82ce40: 8b4e28  mov    ecx,DWORD PTR [esi+0x28]
0x82ce43: 8945f4  mov    DWORD PTR [ebp-0xc],eax
0x82ce46: 8945fc  mov    DWORD PTR [ebp-0x4],eax
0x82ce49: 8d45f8  lea    eax,[ebp-0x8]
0x82ce4c: 50  push   eax
0x82ce4d: 51  push   ecx
0x82ce4e: 897df8  mov    DWORD PTR [ebp-0x8],edi
0x82ce51: e84a5f0000  call   0x832da0
0x82ce56: 8d55f0  lea    edx,[ebp-0x10]
0x82ce59: 52  push   edx
0x82ce5a: 53  push   ebx
0x82ce5b: 8bf0  mov    esi,eax
0x82ce5d: e83e5f0000  call   0x832da0
0x82ce62: 0bf0  or     esi,eax
0x82ce64: f7de  neg    esi
0x82ce66: 1bf6  sbb    esi,esi
0x82ce68: 5f  pop    edi
0x82ce69: 8d4601  lea    eax,[esi+0x1]
0x82ce6c: 5e  pop    esi
0x82ce6d: 5b  pop    ebx
0x82ce6e: 8be5  mov    esp,ebp
0x82ce70: 5d  pop    ebp
0x82ce71: c3  ret
0x82ce72: cc  int3
0x82ce73: cc  int3
0x82ce74: cc  int3
0x82ce75: cc  int3
0x82ce76: cc  int3
0x82ce77: cc  int3
0x82ce78: cc  int3
0x82ce79: cc  int3
0x82ce7a: cc  int3
0x82ce7b: cc  int3
0x82ce7c: cc  int3
0x82ce7d: cc  int3
0x82ce7e: cc  int3
0x82ce7f: cc  int3

; residual_motion_step | remaining delta consumption and v+54 | root 0x4cad60
0x4cad60: 55  push   ebp
0x4cad61: 8bec  mov    ebp,esp
0x4cad63: 83ec1c  sub    esp,0x1c
0x4cad66: d981dc000000  fld    DWORD PTR [ecx+0xdc]
0x4cad6c: 0f57c0  xorps  xmm0,xmm0
0x4cad6f: d981d8000000  fld    DWORD PTR [ecx+0xd8]
0x4cad75: f30f1145ec  movss  DWORD PTR [ebp-0x14],xmm0
0x4cad7a: d95df8  fstp   DWORD PTR [ebp-0x8]
0x4cad7d: f30f1145f0  movss  DWORD PTR [ebp-0x10],xmm0
0x4cad82: d945f8  fld    DWORD PTR [ebp-0x8]
0x4cad85: d9c0  fld    st(0)
0x4cad87: dcc8  fmul   st(0),st
0x4cad89: d9c2  fld    st(2)
0x4cad8b: decb  fmulp  st(3),st
0x4cad8d: dec2  faddp  st(2),st
0x4cad8f: d9c9  fxch   st(1)
0x4cad91: d95df8  fstp   DWORD PTR [ebp-0x8]
0x4cad94: d905c058c500  fld    DWORD PTR ds:0xc558c0
0x4cad9a: d945f8  fld    DWORD PTR [ebp-0x8]
0x4cad9d: dff1  fcomip st,st(1)
0x4cad9f: ddd8  fstp   st(0)
0x4cada1: 767b  jbe    0x4cae1e
0x4cada3: d9450c  fld    DWORD PTR [ebp+0xc]
0x4cada6: d9c0  fld    st(0)
0x4cada8: deca  fmulp  st(2),st
0x4cadaa: d9c9  fxch   st(1)
0x4cadac: d95df4  fstp   DWORD PTR [ebp-0xc]
0x4cadaf: d889dc000000  fmul   DWORD PTR [ecx+0xdc]
0x4cadb5: d95df8  fstp   DWORD PTR [ebp-0x8]
0x4cadb8: d945f4  fld    DWORD PTR [ebp-0xc]
0x4cadbb: d94508  fld    DWORD PTR [ebp+0x8]
0x4cadbe: d9c0  fld    st(0)
0x4cadc0: deca  fmulp  st(2),st
0x4cadc2: d9c9  fxch   st(1)
0x4cadc4: d95de4  fstp   DWORD PTR [ebp-0x1c]
0x4cadc7: d84df8  fmul   DWORD PTR [ebp-0x8]
0x4cadca: d95de8  fstp   DWORD PTR [ebp-0x18]
0x4cadcd: d945e4  fld    DWORD PTR [ebp-0x1c]
0x4cadd0: d9ee  fldz
0x4cadd2: dcc1  fadd   st(1),st
0x4cadd4: d9c9  fxch   st(1)
0x4cadd6: d95dec  fstp   DWORD PTR [ebp-0x14]
0x4cadd9: d845e8  fadd   DWORD PTR [ebp-0x18]
0x4caddc: d95df0  fstp   DWORD PTR [ebp-0x10]
0x4caddf: d981d8000000  fld    DWORD PTR [ecx+0xd8]
0x4cade5: d865ec  fsub   DWORD PTR [ebp-0x14]
0x4cade8: d999d8000000  fstp   DWORD PTR [ecx+0xd8]
0x4cadee: d981dc000000  fld    DWORD PTR [ecx+0xdc]
0x4cadf4: d865f0  fsub   DWORD PTR [ebp-0x10]
0x4cadf7: d999dc000000  fstp   DWORD PTR [ecx+0xdc]
0x4cadfd: d981dc000000  fld    DWORD PTR [ecx+0xdc]
0x4cae03: d981d8000000  fld    DWORD PTR [ecx+0xd8]
0x4cae09: d95df8  fstp   DWORD PTR [ebp-0x8]
0x4cae0c: d945f8  fld    DWORD PTR [ebp-0x8]
0x4cae0f: d9c0  fld    st(0)
0x4cae11: d9c2  fld    st(2)
0x4cae13: decb  fmulp  st(3),st
0x4cae15: dcc8  fmul   st(0),st
0x4cae17: dec2  faddp  st(2),st
0x4cae19: d9c9  fxch   st(1)
0x4cae1b: d95df8  fstp   DWORD PTR [ebp-0x8]
0x4cae1e: f30f100d605ac500  movss  xmm1,DWORD PTR ds:0xc55a60
0x4cae26: 0f2f4df8  comiss xmm1,DWORD PTR [ebp-0x8]
0x4cae2a: 7624  jbe    0x4cae50
0x4cae2c: d845ec  fadd   DWORD PTR [ebp-0x14]
0x4cae2f: d95dec  fstp   DWORD PTR [ebp-0x14]
0x4cae32: d981dc000000  fld    DWORD PTR [ecx+0xdc]
0x4cae38: f30f1181dc000000  movss  DWORD PTR [ecx+0xdc],xmm0
0x4cae40: d845f0  fadd   DWORD PTR [ebp-0x10]
0x4cae43: f30f1181d8000000  movss  DWORD PTR [ecx+0xd8],xmm0
0x4cae4b: d95df0  fstp   DWORD PTR [ebp-0x10]
0x4cae4e: eb02  jmp    0x4cae52
0x4cae50: ddd8  fstp   st(0)
0x4cae52: 837d1000  cmp    DWORD PTR [ebp+0x10],0x0
0x4cae56: 742b  je     0x4cae83
0x4cae58: d981a0000000  fld    DWORD PTR [ecx+0xa0]
0x4cae5e: 8b01  mov    eax,DWORD PTR [ecx]
0x4cae60: d845ec  fadd   DWORD PTR [ebp-0x14]
0x4cae63: 8b4044  mov    eax,DWORD PTR [eax+0x44]
0x4cae66: 6a01  push   0x1
0x4cae68: 8d55e4  lea    edx,[ebp-0x1c]
0x4cae6b: d95de4  fstp   DWORD PTR [ebp-0x1c]
0x4cae6e: 52  push   edx
0x4cae6f: d981a4000000  fld    DWORD PTR [ecx+0xa4]
0x4cae75: d845f0  fadd   DWORD PTR [ebp-0x10]
0x4cae78: d95de8  fstp   DWORD PTR [ebp-0x18]
0x4cae7b: ffd0  call   eax
0x4cae7d: 8be5  mov    esp,ebp
0x4cae7f: 5d  pop    ebp
0x4cae80: c20c00  ret    0xc
0x4cae83: 8b11  mov    edx,DWORD PTR [ecx]
0x4cae85: 8b5254  mov    edx,DWORD PTR [edx+0x54]
0x4cae88: 8d45ec  lea    eax,[ebp-0x14]
0x4cae8b: 50  push   eax
0x4cae8c: ffd2  call   edx
0x4cae8e: 8be5  mov    esp,ebp
0x4cae90: 5d  pop    ebp
0x4cae91: c20c00  ret    0xc
0x4cae94: cc  int3
0x4cae95: cc  int3
0x4cae96: cc  int3
0x4cae97: cc  int3
0x4cae98: cc  int3
0x4cae99: cc  int3
0x4cae9a: cc  int3
0x4cae9b: cc  int3
0x4cae9c: cc  int3
0x4cae9d: cc  int3
0x4cae9e: cc  int3
0x4cae9f: cc  int3

; position_setter | v+44 uses position writer | root 0x4c8b90
0x4c8b90: 55  push   ebp
0x4c8b91: 8bec  mov    ebp,esp
0x4c8b93: 8b450c  mov    eax,DWORD PTR [ebp+0xc]
0x4c8b96: 56  push   esi
0x4c8b97: 8bf1  mov    esi,ecx
0x4c8b99: 8b4d08  mov    ecx,DWORD PTR [ebp+0x8]
0x4c8b9c: 50  push   eax
0x4c8b9d: 51  push   ecx
0x4c8b9e: 8bce  mov    ecx,esi
0x4c8ba0: e8db1f0000  call   0x4cab80
0x4c8ba5: 83be7003000000  cmp    DWORD PTR [esi+0x370],0x0
0x4c8bac: 7424  je     0x4c8bd2
0x4c8bae: 8b865c010000  mov    eax,DWORD PTR [esi+0x15c]
0x4c8bb4: 85c0  test   eax,eax
0x4c8bb6: 741a  je     0x4c8bd2
0x4c8bb8: 8b16  mov    edx,DWORD PTR [esi]
0x4c8bba: 53  push   ebx
0x4c8bbb: 8d5804  lea    ebx,[eax+0x4]
0x4c8bbe: 8b424c  mov    eax,DWORD PTR [edx+0x4c]
0x4c8bc1: 57  push   edi
0x4c8bc2: 8b3b  mov    edi,DWORD PTR [ebx]
0x4c8bc4: 8bce  mov    ecx,esi
0x4c8bc6: ffd0  call   eax
0x4c8bc8: 8b5704  mov    edx,DWORD PTR [edi+0x4]
0x4c8bcb: 50  push   eax
0x4c8bcc: 8bcb  mov    ecx,ebx
0x4c8bce: ffd2  call   edx
0x4c8bd0: 5f  pop    edi
0x4c8bd1: 5b  pop    ebx
0x4c8bd2: 5e  pop    esi
0x4c8bd3: 5d  pop    ebp
0x4c8bd4: c20800  ret    0x8
0x4c8bd7: cc  int3
0x4c8bd8: cc  int3
0x4c8bd9: cc  int3
0x4c8bda: cc  int3
0x4c8bdb: cc  int3
0x4c8bdc: cc  int3
0x4c8bdd: cc  int3
0x4c8bde: cc  int3
0x4c8bdf: cc  int3

; position_writer | A0/A4 writer and transform dirty gate | root 0x4cab80
0x4cab80: 55  push   ebp
0x4cab81: 8bec  mov    ebp,esp
0x4cab83: 8b5508  mov    edx,DWORD PTR [ebp+0x8]
0x4cab86: d981a0000000  fld    DWORD PTR [ecx+0xa0]
0x4cab8c: d902  fld    DWORD PTR [edx]
0x4cab8e: dfe9  fucomip st,st(1)
0x4cab90: ddd8  fstp   st(0)
0x4cab92: 9f  lahf
0x4cab93: f6c444  test   ah,0x44
0x4cab96: 7a13  jp     0x4cabab
0x4cab98: d981a4000000  fld    DWORD PTR [ecx+0xa4]
0x4cab9e: d94204  fld    DWORD PTR [edx+0x4]
0x4caba1: dfe9  fucomip st,st(1)
0x4caba3: ddd8  fstp   st(0)
0x4caba5: 9f  lahf
0x4caba6: f6c444  test   ah,0x44
0x4caba9: 7b28  jnp    0x4cabd3
0x4cabab: 837d0c00  cmp    DWORD PTR [ebp+0xc],0x0
0x4cabaf: 8b02  mov    eax,DWORD PTR [edx]
0x4cabb1: 8981a0000000  mov    DWORD PTR [ecx+0xa0],eax
0x4cabb7: 8b5204  mov    edx,DWORD PTR [edx+0x4]
0x4cabba: 8991a4000000  mov    DWORD PTR [ecx+0xa4],edx
0x4cabc0: 7411  je     0x4cabd3
0x4cabc2: 8b01  mov    eax,DWORD PTR [ecx]
0x4cabc4: 8b5038  mov    edx,DWORD PTR [eax+0x38]
0x4cabc7: c781ac00000001000000  mov    DWORD PTR [ecx+0xac],0x1
0x4cabd1: ffd2  call   edx
0x4cabd3: 5d  pop    ebp
0x4cabd4: c20800  ret    0x8
0x4cabd7: cc  int3
0x4cabd8: cc  int3
0x4cabd9: cc  int3
0x4cabda: cc  int3
0x4cabdb: cc  int3
0x4cabdc: cc  int3
0x4cabdd: cc  int3
0x4cabde: cc  int3
0x4cabdf: cc  int3

; monster_animate | native animation cadence | root 0x4d1af0
0x4d1af0: 55  push   ebp
0x4d1af1: 8bec  mov    ebp,esp
0x4d1af3: 51  push   ecx
0x4d1af4: d94508  fld    DWORD PTR [ebp+0x8]
0x4d1af7: 56  push   esi
0x4d1af8: d9c0  fld    st(0)
0x4d1afa: 8bf1  mov    esi,ecx
0x4d1afc: d8862c040000  fadd   DWORD PTR [esi+0x42c]
0x4d1b02: 57  push   edi
0x4d1b03: d95dfc  fstp   DWORD PTR [ebp-0x4]
0x4d1b06: d945fc  fld    DWORD PTR [ebp-0x4]
0x4d1b09: d9962c040000  fst    DWORD PTR [esi+0x42c]
0x4d1b0f: dd05e85dc500  fld    QWORD PTR ds:0xc55de8
0x4d1b15: d9ca  fxch   st(2)
0x4d1b17: dff2  fcomip st,st(2)
0x4d1b19: ddd9  fstp   st(1)
0x4d1b1b: 7625  jbe    0x4d1b42
0x4d1b1d: f30f1005e05dc500  movss  xmm0,DWORD PTR ds:0xc55de0
0x4d1b25: 0f2f45fc  comiss xmm0,DWORD PTR [ebp-0x4]
0x4d1b29: 762f  jbe    0x4d1b5a
0x4d1b2b: 8bbe5c010000  mov    edi,DWORD PTR [esi+0x15c]
0x4d1b31: ddd8  fstp   st(0)
0x4d1b33: e878402d00  call   0x7a5bb0
0x4d1b38: 5f  pop    edi
0x4d1b39: 33c0  xor    eax,eax
0x4d1b3b: 5e  pop    esi
0x4d1b3c: 8be5  mov    esp,ebp
0x4d1b3e: 5d  pop    ebp
0x4d1b3f: c20400  ret    0x4
0x4d1b42: f30f104508  movss  xmm0,DWORD PTR [ebp+0x8]
0x4d1b47: 0f2f05285ac500  comiss xmm0,DWORD PTR ds:0xc55a28
0x4d1b4e: 760a  jbe    0x4d1b5a
0x4d1b50: f30f1005c85dc500  movss  xmm0,DWORD PTR ds:0xc55dc8
0x4d1b58: ebcb  jmp    0x4d1b25
0x4d1b5a: 0f57c0  xorps  xmm0,xmm0
0x4d1b5d: d95d08  fstp   DWORD PTR [ebp+0x8]
0x4d1b60: d94508  fld    DWORD PTR [ebp+0x8]
0x4d1b63: 51  push   ecx
0x4d1b64: d91c24  fstp   DWORD PTR [esp]
0x4d1b67: f30f11862c040000  movss  DWORD PTR [esi+0x42c],xmm0
0x4d1b6f: e85c6cffff  call   0x4c87d0
0x4d1b74: 8bf8  mov    edi,eax
0x4d1b76: 8b06  mov    eax,DWORD PTR [esi]
0x4d1b78: 8b5064  mov    edx,DWORD PTR [eax+0x64]
0x4d1b7b: 8bce  mov    ecx,esi
0x4d1b7d: ffd2  call   edx
0x4d1b7f: 8bc7  mov    eax,edi
0x4d1b81: 5f  pop    edi
0x4d1b82: 5e  pop    esi
0x4d1b83: 8be5  mov    esp,ebp
0x4d1b85: 5d  pop    ebp
0x4d1b86: c20400  ret    0x4
0x4d1b89: cc  int3
0x4d1b8a: cc  int3
0x4d1b8b: cc  int3
0x4d1b8c: cc  int3
0x4d1b8d: cc  int3
0x4d1b8e: cc  int3
0x4d1b8f: cc  int3

; actor_animate | current state v+8 native update | root 0x4c87d0
0x4c87d0: 55  push   ebp
0x4c87d1: 8bec  mov    ebp,esp
0x4c87d3: 83ec10  sub    esp,0x10
0x4c87d6: 56  push   esi
0x4c87d7: 8bf1  mov    esi,ecx
0x4c87d9: 83be7003000000  cmp    DWORD PTR [esi+0x370],0x0
0x4c87e0: 0f84e8000000  je     0x4c88ce
0x4c87e6: 8b865c010000  mov    eax,DWORD PTR [esi+0x15c]
0x4c87ec: 85c0  test   eax,eax
0x4c87ee: 740f  je     0x4c87ff
0x4c87f0: d94508  fld    DWORD PTR [ebp+0x8]
0x4c87f3: 6a00  push   0x0
0x4c87f5: 51  push   ecx
0x4c87f6: d91c24  fstp   DWORD PTR [esp]
0x4c87f9: 50  push   eax
0x4c87fa: e851d42d00  call   0x7a5c50
0x4c87ff: 8b8664030000  mov    eax,DWORD PTR [esi+0x364]
0x4c8805: 57  push   edi
0x4c8806: 85c0  test   eax,eax
0x4c8808: 7415  je     0x4c881f
0x4c880a: 8b4024  mov    eax,DWORD PTR [eax+0x24]
0x4c880d: 85c0  test   eax,eax
0x4c880f: 740e  je     0x4c881f
0x4c8811: d94508  fld    DWORD PTR [ebp+0x8]
0x4c8814: 51  push   ecx
0x4c8815: 8bf8  mov    edi,eax
0x4c8817: d91c24  fstp   DWORD PTR [esp]
0x4c881a: e8b1502f00  call   0x7bd8d0
0x4c881f: 53  push   ebx
0x4c8820: 8d9e64010000  lea    ebx,[esi+0x164]
0x4c8826: c745fc80000000  mov    DWORD PTR [ebp-0x4],0x80
0x4c882d: 8d4900  lea    ecx,[ecx+0x0]
0x4c8830: 8b03  mov    eax,DWORD PTR [ebx]
0x4c8832: 85c0  test   eax,eax
0x4c8834: 7415  je     0x4c884b
0x4c8836: 8b4024  mov    eax,DWORD PTR [eax+0x24]
0x4c8839: 85c0  test   eax,eax
0x4c883b: 740e  je     0x4c884b
0x4c883d: d94508  fld    DWORD PTR [ebp+0x8]
0x4c8840: 51  push   ecx
0x4c8841: 8bf8  mov    edi,eax
0x4c8843: d91c24  fstp   DWORD PTR [esp]
0x4c8846: e885502f00  call   0x7bd8d0
0x4c884b: 83c304  add    ebx,0x4
0x4c884e: ff4dfc  dec    DWORD PTR [ebp-0x4]
0x4c8851: 75dd  jne    0x4c8830
0x4c8853: 83be6803000000  cmp    DWORD PTR [esi+0x368],0x0
0x4c885a: 5b  pop    ebx
0x4c885b: 7470  je     0x4c88cd
0x4c885d: 83be7003000000  cmp    DWORD PTR [esi+0x370],0x0
0x4c8864: 7467  je     0x4c88cd
0x4c8866: 8b865c010000  mov    eax,DWORD PTR [esi+0x15c]
0x4c886c: 8d8ea0000000  lea    ecx,[esi+0xa0]
0x4c8872: 85c0  test   eax,eax
0x4c8874: 7419  je     0x4c888f
0x4c8876: d9ee  fldz
0x4c8878: 51  push   ecx
0x4c8879: 8d7df0  lea    edi,[ebp-0x10]
0x4c887c: d91c24  fstp   DWORD PTR [esp]
0x4c887f: e8acfd2d00  call   0x7a8630
0x4c8884: 8b4df8  mov    ecx,DWORD PTR [ebp-0x8]
0x4c8887: 8b7df4  mov    edi,DWORD PTR [ebp-0xc]
0x4c888a: 8b55f0  mov    edx,DWORD PTR [ebp-0x10]
0x4c888d: eb08  jmp    0x4c8897
0x4c888f: 8b11  mov    edx,DWORD PTR [ecx]
0x4c8891: 8b7904  mov    edi,DWORD PTR [ecx+0x4]
0x4c8894: 8b4908  mov    ecx,DWORD PTR [ecx+0x8]
0x4c8897: 8b8668030000  mov    eax,DWORD PTR [esi+0x368]
0x4c889d: 895010  mov    DWORD PTR [eax+0x10],edx
0x4c88a0: 897814  mov    DWORD PTR [eax+0x14],edi
0x4c88a3: 894818  mov    DWORD PTR [eax+0x18],ecx
0x4c88a6: 8b8e68030000  mov    ecx,DWORD PTR [esi+0x368]
0x4c88ac: d9412c  fld    DWORD PTR [ecx+0x2c]
0x4c88af: d84508  fadd   DWORD PTR [ebp+0x8]
0x4c88b2: d95dfc  fstp   DWORD PTR [ebp-0x4]
0x4c88b5: d945fc  fld    DWORD PTR [ebp-0x4]
0x4c88b8: d9512c  fst    DWORD PTR [ecx+0x2c]
0x4c88bb: d9e8  fld1
0x4c88bd: d9c9  fxch   st(1)
0x4c88bf: dff1  fcomip st,st(1)
0x4c88c1: ddd8  fstp   st(0)
0x4c88c3: 7608  jbe    0x4c88cd
0x4c88c5: 0f57c0  xorps  xmm0,xmm0
0x4c88c8: f30f11412c  movss  DWORD PTR [ecx+0x2c],xmm0
0x4c88cd: 5f  pop    edi
0x4c88ce: 8b8e58010000  mov    ecx,DWORD PTR [esi+0x158]
0x4c88d4: d94508  fld    DWORD PTR [ebp+0x8]
0x4c88d7: 8b01  mov    eax,DWORD PTR [ecx]
0x4c88d9: 8b5008  mov    edx,DWORD PTR [eax+0x8]
0x4c88dc: 51  push   ecx
0x4c88dd: d91c24  fstp   DWORD PTR [esp]
0x4c88e0: ffd2  call   edx
0x4c88e2: 33c0  xor    eax,eax
0x4c88e4: 5e  pop    esi
0x4c88e5: 8be5  mov    esp,ebp
0x4c88e7: 5d  pop    ebp
0x4c88e8: c20400  ret    0x4
0x4c88eb: cc  int3
0x4c88ec: cc  int3
0x4c88ed: cc  int3
0x4c88ee: cc  int3
0x4c88ef: cc  int3

; move_state_motion | state2 selects walk/run animation | root 0x4cb4b0
0x4cb4b0: 56  push   esi
0x4cb4b1: 8bf1  mov    esi,ecx
0x4cb4b3: 8b4604  mov    eax,DWORD PTR [esi+0x4]
0x4cb4b6: 8b885c010000  mov    ecx,DWORD PTR [eax+0x15c]
0x4cb4bc: 57  push   edi
0x4cb4bd: 8bb88c030000  mov    edi,DWORD PTR [eax+0x38c]
0x4cb4c3: 85c9  test   ecx,ecx
0x4cb4c5: 7411  je     0x4cb4d8
0x4cb4c7: 83b87003000000  cmp    DWORD PTR [eax+0x370],0x0
0x4cb4ce: 7408  je     0x4cb4d8
0x4cb4d0: 8b891c010000  mov    ecx,DWORD PTR [ecx+0x11c]
0x4cb4d6: eb02  jmp    0x4cb4da
0x4cb4d8: 33c9  xor    ecx,ecx
0x4cb4da: 83ff04  cmp    edi,0x4
0x4cb4dd: 742d  je     0x4cb50c
0x4cb4df: 83ff05  cmp    edi,0x5
0x4cb4e2: 7428  je     0x4cb50c
0x4cb4e4: 83ff06  cmp    edi,0x6
0x4cb4e7: 7442  je     0x4cb52b
0x4cb4e9: 83ff10  cmp    edi,0x10
0x4cb4ec: 7504  jne    0x4cb4f2
0x4cb4ee: 85c9  test   ecx,ecx
0x4cb4f0: 747d  je     0x4cb56f
0x4cb4f2: 8bc8  mov    ecx,eax
0x4cb4f4: d98198030000  fld    DWORD PTR [ecx+0x398]
0x4cb4fa: 8b01  mov    eax,DWORD PTR [ecx]
0x4cb4fc: 8b5068  mov    edx,DWORD PTR [eax+0x68]
0x4cb4ff: 51  push   ecx
0x4cb500: d91c24  fstp   DWORD PTR [esp]
0x4cb503: 6a04  push   0x4
0x4cb505: ffd2  call   edx
0x4cb507: 5f  pop    edi
0x4cb508: 5e  pop    esi
0x4cb509: c20400  ret    0x4
0x4cb50c: 83ff06  cmp    edi,0x6
0x4cb50f: 741a  je     0x4cb52b
0x4cb511: 83b8d000000064  cmp    DWORD PTR [eax+0xd0],0x64
0x4cb518: 7d11  jge    0x4cb52b
0x4cb51a: d9e8  fld1
0x4cb51c: 8bc8  mov    ecx,eax
0x4cb51e: 8b11  mov    edx,DWORD PTR [ecx]
0x4cb520: 8b4268  mov    eax,DWORD PTR [edx+0x68]
0x4cb523: 51  push   ecx
0x4cb524: d91c24  fstp   DWORD PTR [esp]
0x4cb527: 6a06  push   0x6
0x4cb529: ffd0  call   eax
0x4cb52b: 83ff05  cmp    edi,0x5
0x4cb52e: 741b  je     0x4cb54b
0x4cb530: 8b4e04  mov    ecx,DWORD PTR [esi+0x4]
0x4cb533: 83b9d000000064  cmp    DWORD PTR [ecx+0xd0],0x64
0x4cb53a: 7e0f  jle    0x4cb54b
0x4cb53c: d9e8  fld1
0x4cb53e: 8b11  mov    edx,DWORD PTR [ecx]
0x4cb540: 8b4268  mov    eax,DWORD PTR [edx+0x68]
0x4cb543: 51  push   ecx
0x4cb544: d91c24  fstp   DWORD PTR [esp]
0x4cb547: 6a05  push   0x5
0x4cb549: ffd0  call   eax
0x4cb54b: 83ff04  cmp    edi,0x4
0x4cb54e: 741f  je     0x4cb56f
0x4cb550: 8b4e04  mov    ecx,DWORD PTR [esi+0x4]
0x4cb553: 83b9d000000064  cmp    DWORD PTR [ecx+0xd0],0x64
0x4cb55a: 7513  jne    0x4cb56f
0x4cb55c: d98198030000  fld    DWORD PTR [ecx+0x398]
0x4cb562: 8b11  mov    edx,DWORD PTR [ecx]
0x4cb564: 8b4268  mov    eax,DWORD PTR [edx+0x68]
0x4cb567: 51  push   ecx
0x4cb568: d91c24  fstp   DWORD PTR [esp]
0x4cb56b: 6a04  push   0x4
0x4cb56d: ffd0  call   eax
0x4cb56f: 5f  pop    edi
0x4cb570: 5e  pop    esi
0x4cb571: c20400  ret    0x4
0x4cb574: cc  int3
0x4cb575: cc  int3
0x4cb576: cc  int3
0x4cb577: cc  int3
0x4cb578: cc  int3
0x4cb579: cc  int3
0x4cb57a: cc  int3
0x4cb57b: cc  int3
0x4cb57c: cc  int3
0x4cb57d: cc  int3
0x4cb57e: cc  int3
0x4cb57f: cc  int3

; skill_receive | 000D world lookup and action application | root 0x4b01c0
0x4b01c0: 55  push   ebp
0x4b01c1: 8bec  mov    ebp,esp
0x4b01c3: 83e4f8  and    esp,0xfffffff8
0x4b01c6: 6aff  push   0xffffffff
0x4b01c8: 68ca7d9400  push   0x947dca
0x4b01cd: 64a100000000  mov    eax,fs:0x0
0x4b01d3: 50  push   eax
0x4b01d4: 83ec18  sub    esp,0x18
0x4b01d7: 53  push   ebx
0x4b01d8: 56  push   esi
0x4b01d9: 57  push   edi
0x4b01da: a1201fd600  mov    eax,ds:0xd61f20
0x4b01df: 33c4  xor    eax,esp
0x4b01e1: 50  push   eax
0x4b01e2: 8d442428  lea    eax,[esp+0x28]
0x4b01e6: 64a300000000  mov    fs:0x0,eax
0x4b01ec: 8b450c  mov    eax,DWORD PTR [ebp+0xc]
0x4b01ef: 83f802  cmp    eax,0x2
0x4b01f2: 7304  jae    0x4b01f8
0x4b01f4: 33d2  xor    edx,edx
0x4b01f6: eb0c  jmp    0x4b0204
0x4b01f8: 8d48fe  lea    ecx,[eax-0x2]
0x4b01fb: b8398ee338  mov    eax,0x38e38e39
0x4b0200: f7e1  mul    ecx
0x4b0202: d1ea  shr    edx,1
0x4b0204: 33db  xor    ebx,ebx
0x4b0206: 3bd3  cmp    edx,ebx
0x4b0208: 0f86a1010000  jbe    0x4b03af
0x4b020e: 8b7d08  mov    edi,DWORD PTR [ebp+0x8]
0x4b0211: 83c705  add    edi,0x5
0x4b0214: 897c2414  mov    DWORD PTR [esp+0x14],edi
0x4b0218: 89542418  mov    DWORD PTR [esp+0x18],edx
0x4b021c: eb04  jmp    0x4b0222
0x4b021e: 8bff  mov    edi,edi
0x4b0220: 33db  xor    ebx,ebx
0x4b0222: f6052cb2fa0001  test   BYTE PTR ds:0xfab22c,0x1
0x4b0229: 7525  jne    0x4b0250
0x4b022b: 830d2cb2fa0001  or     DWORD PTR ds:0xfab22c,0x1
0x4b0232: 895c2430  mov    DWORD PTR [esp+0x30],ebx
0x4b0236: e855ea0200  call   0x4dec90
0x4b023b: 6830cebc00  push   0xbcce30
0x4b0240: e8d5203e00  call   0x89231a
0x4b0245: 83c404  add    esp,0x4
0x4b0248: c7442430ffffffff  mov    DWORD PTR [esp+0x30],0xffffffff
0x4b0250: 0fb757fd  movzx  edx,WORD PTR [edi-0x3]
0x4b0254: 8d44241c  lea    eax,[esp+0x1c]
0x4b0258: 50  push   eax
0x4b0259: 8d442424  lea    eax,[esp+0x24]
0x4b025d: b938b1fa00  mov    ecx,0xfab138
0x4b0262: 89542420  mov    DWORD PTR [esp+0x20],edx
0x4b0266: e895ec3700  call   0x82ef00
0x4b026b: 8b442420  mov    eax,DWORD PTR [esp+0x20]
0x4b026f: 3b053cb1fa00  cmp    eax,DWORD PTR ds:0xfab13c
0x4b0275: 7407  je     0x4b027e
0x4b0277: 8b7010  mov    esi,DWORD PTR [eax+0x10]
0x4b027a: 3bf3  cmp    esi,ebx
0x4b027c: 7512  jne    0x4b0290
0x4b027e: 68246bc000  push   0xc06b24
0x4b0283: e8d8d82300  call   0x6edb60
0x4b0288: 83c404  add    esp,0x4
0x4b028b: e90e010000  jmp    0x4b039e
0x4b0290: 0fb647ff  movzx  eax,BYTE PTR [edi-0x1]
0x4b0294: 8b16  mov    edx,DWORD PTR [esi]
0x4b0296: 8b5258  mov    edx,DWORD PTR [edx+0x58]
0x4b0299: 50  push   eax
0x4b029a: 8bce  mov    ecx,esi
0x4b029c: ffd2  call   edx
0x4b029e: 399ea8030000  cmp    DWORD PTR [esi+0x3a8],ebx
0x4b02a4: 7406  je     0x4b02ac
0x4b02a6: 899ea8030000  mov    DWORD PTR [esi+0x3a8],ebx
0x4b02ac: 83bea803000000  cmp    DWORD PTR [esi+0x3a8],0x0
0x4b02b3: 8a9eb0000000  mov    bl,BYTE PTR [esi+0xb0]
0x4b02b9: 7554  jne    0x4b030f
0x4b02bb: 83be7003000000  cmp    DWORD PTR [esi+0x370],0x0
0x4b02c2: 889ea4030000  mov    BYTE PTR [esi+0x3a4],bl
0x4b02c8: 7445  je     0x4b030f
0x4b02ca: 8b865c010000  mov    eax,DWORD PTR [esi+0x15c]
0x4b02d0: 85c0  test   eax,eax
0x4b02d2: 743b  je     0x4b030f
0x4b02d4: f605187cfb0001  test   BYTE PTR ds:0xfb7c18,0x1
0x4b02db: 8d7804  lea    edi,[eax+0x4]
0x4b02de: 750c  jne    0x4b02ec
0x4b02e0: 830d187cfb0001  or     DWORD PTR ds:0xfb7c18,0x1
0x4b02e7: e8e446f9ff  call   0x4449d0
0x4b02ec: 8b17  mov    edx,DWORD PTR [edi]
0x4b02ee: 0fb6c3  movzx  eax,bl
0x4b02f1: 51  push   ecx
0x4b02f2: 8bcf  mov    ecx,edi
0x4b02f4: d90485207cfb00  fld    DWORD PTR [eax*4+0xfb7c20]
0x4b02fb: 8b420c  mov    eax,DWORD PTR [edx+0xc]
0x4b02fe: d95c2420  fstp   DWORD PTR [esp+0x20]
0x4b0302: d9442420  fld    DWORD PTR [esp+0x20]
0x4b0306: d91c24  fstp   DWORD PTR [esp]
0x4b0309: ffd0  call   eax
0x4b030b: 8b7c2414  mov    edi,DWORD PTR [esp+0x14]
0x4b030f: d94702  fld    DWORD PTR [edi+0x2]
0x4b0312: 51  push   ecx
0x4b0313: 0fb70f  movzx  ecx,WORD PTR [edi]
0x4b0316: d91c24  fstp   DWORD PTR [esp]
0x4b0319: 51  push   ecx
0x4b031a: e871870100  call   0x4c8a90
0x4b031f: f6059043f90001  test   BYTE PTR ds:0xf94390,0x1
0x4b0326: 8bb69c000000  mov    esi,DWORD PTR [esi+0x9c]
0x4b032c: 7529  jne    0x4b0357
0x4b032e: b801000000  mov    eax,0x1
0x4b0333: 09059043f900  or     DWORD PTR ds:0xf94390,eax
0x4b0339: 89442430  mov    DWORD PTR [esp+0x30],eax
0x4b033d: e84e120300  call   0x4e1590
0x4b0342: 6880ccbc00  push   0xbccc80
0x4b0347: e8ce1f3e00  call   0x89231a
0x4b034c: 83c404  add    esp,0x4
0x4b034f: c7442430ffffffff  mov    DWORD PTR [esp+0x30],0xffffffff
0x4b0357: 3b353039f900  cmp    esi,DWORD PTR ds:0xf93930
0x4b035d: 753f  jne    0x4b039e
0x4b035f: 66833f12  cmp    WORD PTR [edi],0x12
0x4b0363: 7539  jne    0x4b039e
0x4b0365: f6059cb2fa0001  test   BYTE PTR ds:0xfab29c,0x1
0x4b036c: 7529  jne    0x4b0397
0x4b036e: 830d9cb2fa0001  or     DWORD PTR ds:0xfab29c,0x1
0x4b0375: c744243002000000  mov    DWORD PTR [esp+0x30],0x2
0x4b037d: e8defa0400  call   0x4ffe60
0x4b0382: 6800cfbc00  push   0xbccf00
0x4b0387: e88e1f3e00  call   0x89231a
0x4b038c: 83c404  add    esp,0x4
0x4b038f: c7442430ffffffff  mov    DWORD PTR [esp+0x30],0xffffffff
0x4b0397: 6a0a  push   0xa
0x4b0399: e8b2120500  call   0x501650
0x4b039e: 83c709  add    edi,0x9
0x4b03a1: ff4c2418  dec    DWORD PTR [esp+0x18]
0x4b03a5: 897c2414  mov    DWORD PTR [esp+0x14],edi
0x4b03a9: 0f8571feffff  jne    0x4b0220
0x4b03af: 33c0  xor    eax,eax
0x4b03b1: 8b4c2428  mov    ecx,DWORD PTR [esp+0x28]
0x4b03b5: 64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x4b03bc: 59  pop    ecx
0x4b03bd: 5f  pop    edi
0x4b03be: 5e  pop    esi
0x4b03bf: 5b  pop    ebx
0x4b03c0: 8be5  mov    esp,ebp
0x4b03c2: 5d  pop    ebp
0x4b03c3: c20c00  ret    0xc
0x4b03c6: cc  int3
0x4b03c7: cc  int3
0x4b03c8: cc  int3
0x4b03c9: cc  int3
0x4b03ca: cc  int3
0x4b03cb: cc  int3
0x4b03cc: cc  int3
0x4b03cd: cc  int3
0x4b03ce: cc  int3
0x4b03cf: cc  int3

; skill_action_apply | state13 then motion/rate | root 0x4c8a90
0x4c8a90: 55  push   ebp
0x4c8a91: 8bec  mov    ebp,esp
0x4c8a93: f30f108ed8000000  movss  xmm1,DWORD PTR [esi+0xd8]
0x4c8a9b: 0f57c0  xorps  xmm0,xmm0
0x4c8a9e: 83ec10  sub    esp,0x10
0x4c8aa1: 0f2ec8  ucomiss xmm1,xmm0
0x4c8aa4: 9f  lahf
0x4c8aa5: 53  push   ebx
0x4c8aa6: 57  push   edi
0x4c8aa7: f6c444  test   ah,0x44
0x4c8aaa: 7a11  jp     0x4c8abd
0x4c8aac: f30f108edc000000  movss  xmm1,DWORD PTR [esi+0xdc]
0x4c8ab4: 0f2ec8  ucomiss xmm1,xmm0
0x4c8ab7: 9f  lahf
0x4c8ab8: f6c444  test   ah,0x44
0x4c8abb: 7b55  jnp    0x4c8b12
0x4c8abd: 8b86a0000000  mov    eax,DWORD PTR [esi+0xa0]
0x4c8ac3: 8b8ea4000000  mov    ecx,DWORD PTR [esi+0xa4]
0x4c8ac9: 8945f8  mov    DWORD PTR [ebp-0x8],eax
0x4c8acc: d945f8  fld    DWORD PTR [ebp-0x8]
0x4c8acf: d886d8000000  fadd   DWORD PTR [esi+0xd8]
0x4c8ad5: 894dfc  mov    DWORD PTR [ebp-0x4],ecx
0x4c8ad8: f30f1145f0  movss  DWORD PTR [ebp-0x10],xmm0
0x4c8add: 8b55f0  mov    edx,DWORD PTR [ebp-0x10]
0x4c8ae0: d95df8  fstp   DWORD PTR [ebp-0x8]
0x4c8ae3: f30f1145f4  movss  DWORD PTR [ebp-0xc],xmm0
0x4c8ae8: d986dc000000  fld    DWORD PTR [esi+0xdc]
0x4c8aee: 8b45f4  mov    eax,DWORD PTR [ebp-0xc]
0x4c8af1: d845fc  fadd   DWORD PTR [ebp-0x4]
0x4c8af4: 8996d8000000  mov    DWORD PTR [esi+0xd8],edx
0x4c8afa: 8b16  mov    edx,DWORD PTR [esi]
0x4c8afc: 8b5244  mov    edx,DWORD PTR [edx+0x44]
0x4c8aff: 8986dc000000  mov    DWORD PTR [esi+0xdc],eax
0x4c8b05: d95dfc  fstp   DWORD PTR [ebp-0x4]
0x4c8b08: 6a01  push   0x1
0x4c8b0a: 8d45f8  lea    eax,[ebp-0x8]
0x4c8b0d: 50  push   eax
0x4c8b0e: 8bce  mov    ecx,esi
0x4c8b10: ffd2  call   edx
0x4c8b12: 83bea803000000  cmp    DWORD PTR [esi+0x3a8],0x0
0x4c8b19: 8a86b0000000  mov    al,BYTE PTR [esi+0xb0]
0x4c8b1f: 8845fc  mov    BYTE PTR [ebp-0x4],al
0x4c8b22: 7534  jne    0x4c8b58
0x4c8b24: 83be7003000000  cmp    DWORD PTR [esi+0x370],0x0
0x4c8b2b: 8886a4030000  mov    BYTE PTR [esi+0x3a4],al
0x4c8b31: 7425  je     0x4c8b58
0x4c8b33: 8b865c010000  mov    eax,DWORD PTR [esi+0x15c]
0x4c8b39: 85c0  test   eax,eax
0x4c8b3b: 741b  je     0x4c8b58
0x4c8b3d: 8b7804  mov    edi,DWORD PTR [eax+0x4]
0x4c8b40: 8d5804  lea    ebx,[eax+0x4]
0x4c8b43: 8b45fc  mov    eax,DWORD PTR [ebp-0x4]
0x4c8b46: 50  push   eax
0x4c8b47: e844bff7ff  call   0x444a90
0x4c8b4c: 8b570c  mov    edx,DWORD PTR [edi+0xc]
0x4c8b4f: 8bcb  mov    ecx,ebx
0x4c8b51: f30f110424  movss  DWORD PTR [esp],xmm0
0x4c8b56: ffd2  call   edx
0x4c8b58: 8b86f0000000  mov    eax,DWORD PTR [esi+0xf0]
0x4c8b5e: 8b5008  mov    edx,DWORD PTR [eax+0x8]
0x4c8b61: 8d8ef0000000  lea    ecx,[esi+0xf0]
0x4c8b67: 6a0d  push   0xd
0x4c8b69: ffd2  call   edx
0x4c8b6b: d9450c  fld    DWORD PTR [ebp+0xc]
0x4c8b6e: 8b06  mov    eax,DWORD PTR [esi]
0x4c8b70: 8b5068  mov    edx,DWORD PTR [eax+0x68]
0x4c8b73: 51  push   ecx
0x4c8b74: 0fbf4d08  movsx  ecx,WORD PTR [ebp+0x8]
0x4c8b78: d91c24  fstp   DWORD PTR [esp]
0x4c8b7b: 51  push   ecx
0x4c8b7c: 8bce  mov    ecx,esi
0x4c8b7e: ffd2  call   edx
0x4c8b80: 5f  pop    edi
0x4c8b81: 5b  pop    ebx
0x4c8b82: 8be5  mov    esp,ebp
0x4c8b84: 5d  pop    ebp
0x4c8b85: c20800  ret    0x8
0x4c8b88: cc  int3
0x4c8b89: cc  int3
0x4c8b8a: cc  int3
0x4c8b8b: cc  int3
0x4c8b8c: cc  int3
0x4c8b8d: cc  int3
0x4c8b8e: cc  int3
0x4c8b8f: cc  int3

; skill_state_install | CActor installs state13 CSkillState | root 0x4c7070
0x4c75d0: 6a38  push   0x38
0x4c75d2: e8919c3c00  call   0x891268
0x4c75d7: 83c404  add    esp,0x4
0x4c75da: 8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4c75dd: c645fc0c  mov    BYTE PTR [ebp-0x4],0xc
0x4c75e1: 3bc6  cmp    eax,esi
0x4c75e3: 7420  je     0x4c7605
0x4c75e5: 8b75f0  mov    esi,DWORD PTR [ebp-0x10]
0x4c75e8: 8bc3  mov    eax,ebx
0x4c75ea: b90d000000  mov    ecx,0xd
0x4c75ef: e83c3c0000  call   0x4cb230
0x4c75f4: 8bc6  mov    eax,esi
0x4c75f6: c700ec78c000  mov    DWORD PTR [eax],0xc078ec
0x4c75fc: 8945f0  mov    DWORD PTR [ebp-0x10],eax
0x4c75ff: 33f6  xor    esi,esi
0x4c7601: 8bc8  mov    ecx,eax
0x4c7603: eb05  jmp    0x4c760a
0x4c7605: 33c9  xor    ecx,ecx
0x4c7607: 894df0  mov    DWORD PTR [ebp-0x10],ecx
0x4c760a: c645fc04  mov    BYTE PTR [ebp-0x4],0x4
0x4c760e: 8b4108  mov    eax,DWORD PTR [ecx+0x8]
0x4c7611: 8945ec  mov    DWORD PTR [ebp-0x14],eax
0x4c7614: 39b483f4000000  cmp    DWORD PTR [ebx+eax*4+0xf4],esi
0x4c761b: 7413  je     0x4c7630
0x4c761d: 683c75c000  push   0xc0753c
0x4c7622: e839652200  call   0x6edb60
0x4c7627: 8b45ec  mov    eax,DWORD PTR [ebp-0x14]
0x4c762a: 8b4df0  mov    ecx,DWORD PTR [ebp-0x10]
0x4c762d: 83c404  add    esp,0x4
0x4c7630: 898c83f4000000  mov    DWORD PTR [ebx+eax*4+0xf4],ecx
0x4c7637: 39b358010000  cmp    DWORD PTR [ebx+0x158],esi
0x4c763d: 7506  jne    0x4c7645
0x4c763f: 898b58010000  mov    DWORD PTR [ebx+0x158],ecx
0x4c7645: 6a38  push   0x38

; skill_state_enter | only actor+418=300 in selected entry | root 0x4cbb00
0x4cbb00: 8b4104  mov    eax,DWORD PTR [ecx+0x4]
0x4cbb03: c780180400002c010000  mov    DWORD PTR [eax+0x418],0x12c
0x4cbb0d: c3  ret

; skill_state_update_stub | state update returns without calculation | root 0x476430
0x476430: c20400  ret    0x4

; controller_attach | three slots; no independent monster brain | root 0x545040
0x545040: 55  push   ebp
0x545041: 8bec  mov    ebp,esp
0x545043: 6aff  push   0xffffffff
0x545045: 68ab839000  push   0x9083ab
0x54504a: 64a100000000  mov    eax,fs:0x0
0x545050: 50  push   eax
0x545051: 83ec1c  sub    esp,0x1c
0x545054: 53  push   ebx
0x545055: 56  push   esi
0x545056: 57  push   edi
0x545057: a1201fd600  mov    eax,ds:0xd61f20
0x54505c: 33c5  xor    eax,ebp
0x54505e: 50  push   eax
0x54505f: 8d45f4  lea    eax,[ebp-0xc]
0x545062: 64a300000000  mov    fs:0x0,eax
0x545068: 33c0  xor    eax,eax
0x54506a: 8d510c  lea    edx,[ecx+0xc]
0x54506d: 8d4900  lea    ecx,[ecx+0x0]
0x545070: 833a00  cmp    DWORD PTR [edx],0x0
0x545073: 741d  je     0x545092
0x545075: 40  inc    eax
0x545076: 83c20c  add    edx,0xc
0x545079: 83f803  cmp    eax,0x3
0x54507c: 7cf2  jl     0x545070
0x54507e: 8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x545081: 64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x545088: 59  pop    ecx
0x545089: 5f  pop    edi
0x54508a: 5e  pop    esi
0x54508b: 5b  pop    ebx
0x54508c: 8be5  mov    esp,ebp
0x54508e: 5d  pop    ebp
0x54508f: c20400  ret    0x4
0x545092: 8b7d08  mov    edi,DWORD PTR [ebp+0x8]
0x545095: 8d0440  lea    eax,[eax+eax*2]
0x545098: 8d0481  lea    eax,[ecx+eax*4]
0x54509b: c7410401000000  mov    DWORD PTR [ecx+0x4],0x1
0x5450a2: 89780c  mov    DWORD PTR [eax+0xc],edi
0x5450a5: 0fb75f04  movzx  ebx,WORD PTR [edi+0x4]
0x5450a9: 8d7148  lea    esi,[ecx+0x48]
0x5450ac: 8bcb  mov    ecx,ebx
0x5450ae: 8d55f0  lea    edx,[ebp-0x10]
0x5450b1: 8945e4  mov    DWORD PTR [ebp-0x1c],eax
0x5450b4: 894df0  mov    DWORD PTR [ebp-0x10],ecx
0x5450b7: 52  push   edx
0x5450b8: 8d45e8  lea    eax,[ebp-0x18]
0x5450bb: 8bce  mov    ecx,esi
0x5450bd: e83e9e2e00  call   0x82ef00
0x5450c2: 8b4de8  mov    ecx,DWORD PTR [ebp-0x18]
0x5450c5: 3b4e04  cmp    ecx,DWORD PTR [esi+0x4]
0x5450c8: 0f85c4000000  jne    0x545192
0x5450ce: 6a14  push   0x14
0x5450d0: e893c13400  call   0x891268
0x5450d5: 8bf8  mov    edi,eax
0x5450d7: 83c404  add    esp,0x4
0x5450da: 897df0  mov    DWORD PTR [ebp-0x10],edi
0x5450dd: 33db  xor    ebx,ebx
0x5450df: 895dfc  mov    DWORD PTR [ebp-0x4],ebx
0x5450e2: 3bfb  cmp    edi,ebx
0x5450e4: 7436  je     0x54511c
0x5450e6: 33c0  xor    eax,eax
0x5450e8: 8907  mov    DWORD PTR [edi],eax
0x5450ea: 6a24  push   0x24
0x5450ec: 895f0c  mov    DWORD PTR [edi+0xc],ebx
0x5450ef: e874c13400  call   0x891268
0x5450f4: 83c404  add    esp,0x4
0x5450f7: 3bc3  cmp    eax,ebx
0x5450f9: 7473  je     0x54516e
0x5450fb: 894708  mov    DWORD PTR [edi+0x8],eax
0x5450fe: 8900  mov    DWORD PTR [eax],eax
0x545100: 8b4708  mov    eax,DWORD PTR [edi+0x8]
0x545103: 894004  mov    DWORD PTR [eax+0x4],eax
0x545106: 8b4708  mov    eax,DWORD PTR [edi+0x8]
0x545109: 894008  mov    DWORD PTR [eax+0x8],eax
0x54510c: 8b5708  mov    edx,DWORD PTR [edi+0x8]
0x54510f: c6422001  mov    BYTE PTR [edx+0x20],0x1
0x545113: 8b4708  mov    eax,DWORD PTR [edi+0x8]
0x545116: c6402101  mov    BYTE PTR [eax+0x21],0x1
0x54511a: 8bdf  mov    ebx,edi
0x54511c: 8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x54511f: c745fcffffffff  mov    DWORD PTR [ebp-0x4],0xffffffff
0x545126: 668b4804  mov    cx,WORD PTR [eax+0x4]
0x54512a: 66890b  mov    WORD PTR [ebx],cx
0x54512d: 0fb78888000000  movzx  ecx,WORD PTR [eax+0x88]
0x545134: 894df0  mov    DWORD PTR [ebp-0x10],ecx
0x545137: 66394b02  cmp    WORD PTR [ebx+0x2],cx
0x54513b: 7413  je     0x545150
0x54513d: 8d7b04  lea    edi,[ebx+0x4]
0x545140: e82b2a0500  call   0x597b70
0x545145: 668b55f0  mov    dx,WORD PTR [ebp-0x10]
0x545149: 8b4508  mov    eax,DWORD PTR [ebp+0x8]
0x54514c: 66895302  mov    WORD PTR [ebx+0x2],dx
0x545150: 0fb74004  movzx  eax,WORD PTR [eax+0x4]
0x545154: 8d7dec  lea    edi,[ebp-0x14]
0x545157: 8945ec  mov    DWORD PTR [ebp-0x14],eax
0x54515a: 895df0  mov    DWORD PTR [ebp-0x10],ebx
0x54515d: e8be9d0300  call   0x57ef20
0x545162: 50  push   eax
0x545163: 56  push   esi
0x545164: 8d75ec  lea    esi,[ebp-0x14]
0x545167: e894a02e00  call   0x82f200
0x54516c: eb45  jmp    0x5451b3
0x54516e: 8d4de8  lea    ecx,[ebp-0x18]
0x545171: 51  push   ecx
0x545172: 8d4dd8  lea    ecx,[ebp-0x28]
0x545175: 895de8  mov    DWORD PTR [ebp-0x18],ebx
0x545178: e82cbf3400  call   0x8910a9
0x54517d: 68a857c800  push   0xc857a8
0x545182: 8d55d8  lea    edx,[ebp-0x28]
0x545185: 52  push   edx
0x545186: c745d8a42cbd00  mov    DWORD PTR [ebp-0x28],0xbd2ca4
0x54518d: e85e783500  call   0x89c9f0
0x545192: 8b7110  mov    esi,DWORD PTR [ecx+0x10]
0x545195: 66891e  mov    WORD PTR [esi],bx
0x545198: 0fb79f88000000  movzx  ebx,WORD PTR [edi+0x88]
0x54519f: 66395e02  cmp    WORD PTR [esi+0x2],bx
0x5451a3: 740c  je     0x5451b1
0x5451a5: 8d7e04  lea    edi,[esi+0x4]
0x5451a8: e8c3290500  call   0x597b70
0x5451ad: 66895e02  mov    WORD PTR [esi+0x2],bx
0x5451b1: 8bde  mov    ebx,esi
0x5451b3: 8b4de4  mov    ecx,DWORD PTR [ebp-0x1c]
0x5451b6: 895910  mov    DWORD PTR [ecx+0x10],ebx
0x5451b9: 8b4df4  mov    ecx,DWORD PTR [ebp-0xc]
0x5451bc: 64890d00000000  mov    DWORD PTR fs:0x0,ecx
0x5451c3: 59  pop    ecx
0x5451c4: 5f  pop    edi
0x5451c5: 5e  pop    esi
0x5451c6: 5b  pop    ebx
0x5451c7: 8be5  mov    esp,ebp
0x5451c9: 5d  pop    ebp
0x5451ca: c20400  ret    0x4
0x5451cd: cc  int3
0x5451ce: cc  int3
0x5451cf: cc  int3

; subai_model_gate | selected native action rejects model >9 | root 0x549c60
0x549cee: 0fb78288000000  movzx  eax,WORD PTR [edx+0x88]
0x549cf5: 8b0d0443f900  mov    ecx,DWORD PTR ds:0xf94304
0x549cfb: 83f809  cmp    eax,0x9
0x549cfe: 0f87ef000000  ja     0x549df3
0x549d04: 69c010020000  imul   eax,eax,0x210
