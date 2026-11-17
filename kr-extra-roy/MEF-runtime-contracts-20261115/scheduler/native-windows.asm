; N01 GetTime registration writes native thunk and publishes C closure

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1ab0 <.text+0xa0ab0>:
  4a1ab0:	55                                              	push   ebp
  4a1ab1:	8b ec                                           	mov    ebp,esp
  4a1ab3:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  4a1ab6:	53                                              	push   ebx
  4a1ab7:	8b 1d 74 17 fe 00                               	mov    ebx,DWORD PTR ds:0xfe1774
  4a1abd:	56                                              	push   esi
  4a1abe:	8b 33                                           	mov    esi,DWORD PTR [ebx]
  4a1ac0:	57                                              	push   edi
  4a1ac1:	8b 38                                           	mov    edi,DWORD PTR [eax]
  4a1ac3:	b8 ee d8 ff ff                                  	mov    eax,0xffffd8ee
  4a1ac8:	c7 05 9c 17 fe 00 70 0b 4a 00                   	mov    DWORD PTR ds:0xfe179c,0x4a0b70
  4a1ad2:	e8 a9 3b 25 00                                  	call   0x6f5680
  4a1ad7:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  4a1ad9:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  4a1adc:	83 e8 10                                        	sub    eax,0x10
  4a1adf:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  4a1ae4:	74 06                                           	je     0x4a1aec
  4a1ae6:	83 78 08 05                                     	cmp    DWORD PTR [eax+0x8],0x5
  4a1aea:	74 14                                           	je     0x4a1b00
  4a1aec:	57                                              	push   edi
  4a1aed:	68 c4 26 c4 00                                  	push   0xc426c4
  4a1af2:	e8 c6 15 3f 00                                  	call   0x8930bd
  4a1af7:	8b 1b                                           	mov    ebx,DWORD PTR [ebx]
  4a1af9:	83 c4 08                                        	add    esp,0x8
  4a1afc:	83 43 08 f0                                     	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1b00:	8b 3d 74 17 fe 00                               	mov    edi,DWORD PTR ds:0xfe1774
  4a1b06:	8b 37                                           	mov    esi,DWORD PTR [edi]
  4a1b08:	68 0c ae d6 00                                  	push   0xd6ae0c
  4a1b0d:	e8 fe 39 25 00                                  	call   0x6f5510
  4a1b12:	8b 37                                           	mov    esi,DWORD PTR [edi]
  4a1b14:	83 c4 04                                        	add    esp,0x4
  4a1b17:	6a 00                                           	push   0x0
  4a1b19:	68 90 21 4a 00                                  	push   0x4a2190
  4a1b1e:	e8 8d 3a 25 00                                  	call   0x6f55b0
  4a1b23:	8b 0f                                           	mov    ecx,DWORD PTR [edi]
  4a1b25:	51                                              	push   ecx
  4a1b26:	b8 fd ff ff ff                                  	mov    eax,0xfffffffd
  4a1b2b:	e8 c0 3c 25 00                                  	call   0x6f57f0
  4a1b30:	8b 15 74 17 fe 00                               	mov    edx,DWORD PTR ds:0xfe1774
  4a1b36:	8b 02                                           	mov    eax,DWORD PTR [edx]
  4a1b38:	83 c4 0c                                        	add    esp,0xc
  4a1b3b:	83 40 08 f0                                     	add    DWORD PTR [eax+0x8],0xfffffff0
  4a1b3f:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  4a1b42:	5f                                              	pop    edi
  4a1b43:	5e                                              	pop    esi
  4a1b44:	5b                                              	pop    ebx
  4a1b45:	5d                                              	pop    ebp
  4a1b46:	c2 04 00                                        	ret    0x4

; N02 GetTime marshaller signed int32 to Lua number

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2190 <.text+0xa1190>:
  4a2190:	55                                              	push   ebp
  4a2191:	8b ec                                           	mov    ebp,esp
  4a2193:	6a ff                                           	push   0xffffffff
  4a2195:	68 d8 87 93 00                                  	push   0x9387d8
  4a219a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4a21a0:	50                                              	push   eax
  4a21a1:	83 ec 0c                                        	sub    esp,0xc
  4a21a4:	56                                              	push   esi
  4a21a5:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4a21aa:	33 c5                                           	xor    eax,ebp
  4a21ac:	50                                              	push   eax
  4a21ad:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4a21b0:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4a21b6:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  4a21b9:	33 c0                                           	xor    eax,eax
  4a21bb:	89 75 e8                                        	mov    DWORD PTR [ebp-0x18],esi
  4a21be:	89 45 ec                                        	mov    DWORD PTR [ebp-0x14],eax
  4a21c1:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  4a21c4:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  4a21c7:	8b 0d 78 17 fe 00                               	mov    ecx,DWORD PTR ds:0xfe1778
  4a21cd:	ff 15 9c 17 fe 00                               	call   DWORD PTR ds:0xfe179c
  4a21d3:	89 45 08                                        	mov    DWORD PTR [ebp+0x8],eax
  4a21d6:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  4a21d9:	db 45 08                                        	fild   DWORD PTR [ebp+0x8]
  4a21dc:	c7 40 08 03 00 00 00                            	mov    DWORD PTR [eax+0x8],0x3
  4a21e3:	dd 18                                           	fstp   QWORD PTR [eax]
  4a21e5:	83 46 08 10                                     	add    DWORD PTR [esi+0x8],0x10
  4a21e9:	b8 01 00 00 00                                  	mov    eax,0x1
  4a21ee:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4a21f1:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4a21f8:	59                                              	pop    ecx
  4a21f9:	5e                                              	pop    esi
  4a21fa:	8b e5                                           	mov    esp,ebp
  4a21fc:	5d                                              	pop    ebp
  4a21fd:	c3                                              	ret

; N03 GetTime native import thunk

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a0b70 <.text+0x9fb70>:
  4a0b70:	ff 25 a0 25 bd 00                               	jmp    DWORD PTR ds:0xbd25a0

; N04 coroutine.create checks Lua function and returns thread

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00707380 <.text+0x306380>:
  707380:	55                                              	push   ebp
  707381:	8b ec                                           	mov    ebp,esp
  707383:	53                                              	push   ebx
  707384:	56                                              	push   esi
  707385:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  707388:	8b 46 10                                        	mov    eax,DWORD PTR [esi+0x10]
  70738b:	8b 48 44                                        	mov    ecx,DWORD PTR [eax+0x44]
  70738e:	3b 48 40                                        	cmp    ecx,DWORD PTR [eax+0x40]
  707391:	72 07                                           	jb     0x70739a
  707393:	8b c6                                           	mov    eax,esi
  707395:	e8 06 40 ff ff                                  	call   0x6fb3a0
  70739a:	8b c6                                           	mov    eax,esi
  70739c:	e8 ef ff fe ff                                  	call   0x6f7390
  7073a1:	8b d8                                           	mov    ebx,eax
  7073a3:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  7073a6:	89 18                                           	mov    DWORD PTR [eax],ebx
  7073a8:	c7 40 08 08 00 00 00                            	mov    DWORD PTR [eax+0x8],0x8
  7073af:	83 46 08 10                                     	add    DWORD PTR [esi+0x8],0x10
  7073b3:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  7073b6:	8b 46 0c                                        	mov    eax,DWORD PTR [esi+0xc]
  7073b9:	3b c1                                           	cmp    eax,ecx
  7073bb:	73 24                                           	jae    0x7073e1
  7073bd:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  7073c2:	74 1d                                           	je     0x7073e1
  7073c4:	83 78 08 06                                     	cmp    DWORD PTR [eax+0x8],0x6
  7073c8:	75 17                                           	jne    0x7073e1
  7073ca:	3b c1                                           	cmp    eax,ecx
  7073cc:	72 05                                           	jb     0x7073d3
  7073ce:	b8 c8 bf c0 00                                  	mov    eax,0xc0bfc8
  7073d3:	83 78 08 06                                     	cmp    DWORD PTR [eax+0x8],0x6
  7073d7:	75 19                                           	jne    0x7073f2
  7073d9:	8b 10                                           	mov    edx,DWORD PTR [eax]
  7073db:	80 7a 06 00                                     	cmp    BYTE PTR [edx+0x6],0x0
  7073df:	74 11                                           	je     0x7073f2
  7073e1:	57                                              	push   edi
  7073e2:	6a 01                                           	push   0x1
  7073e4:	bf f8 36 c4 00                                  	mov    edi,0xc436f8
  7073e9:	e8 b2 e9 fe ff                                  	call   0x6f5da0
  7073ee:	83 c4 04                                        	add    esp,0x4
  7073f1:	5f                                              	pop    edi
  7073f2:	8b 46 0c                                        	mov    eax,DWORD PTR [esi+0xc]
  7073f5:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  7073f8:	3b c1                                           	cmp    eax,ecx
  7073fa:	72 05                                           	jb     0x707401
  7073fc:	b8 c8 bf c0 00                                  	mov    eax,0xc0bfc8
  707401:	8b 10                                           	mov    edx,DWORD PTR [eax]
  707403:	89 11                                           	mov    DWORD PTR [ecx],edx
  707405:	8b 50 04                                        	mov    edx,DWORD PTR [eax+0x4]
  707408:	89 51 04                                        	mov    DWORD PTR [ecx+0x4],edx
  70740b:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  70740e:	89 41 08                                        	mov    DWORD PTR [ecx+0x8],eax
  707411:	83 46 08 10                                     	add    DWORD PTR [esi+0x8],0x10
  707415:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  707418:	3b f3                                           	cmp    esi,ebx
  70741a:	74 1f                                           	je     0x70743b
  70741c:	83 c0 f0                                        	add    eax,0xfffffff0
  70741f:	89 46 08                                        	mov    DWORD PTR [esi+0x8],eax
  707422:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  707425:	8d 51 10                                        	lea    edx,[ecx+0x10]
  707428:	89 53 08                                        	mov    DWORD PTR [ebx+0x8],edx
  70742b:	8b 10                                           	mov    edx,DWORD PTR [eax]
  70742d:	89 11                                           	mov    DWORD PTR [ecx],edx
  70742f:	8b 50 04                                        	mov    edx,DWORD PTR [eax+0x4]
  707432:	89 51 04                                        	mov    DWORD PTR [ecx+0x4],edx
  707435:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  707438:	89 41 08                                        	mov    DWORD PTR [ecx+0x8],eax
  70743b:	5e                                              	pop    esi
  70743c:	b8 01 00 00 00                                  	mov    eax,0x1
  707441:	5b                                              	pop    ebx
  707442:	5d                                              	pop    ebp
  707443:	c3                                              	ret
  707444:	cc                                              	int3
  707445:	cc                                              	int3
  707446:	cc                                              	int3
  707447:	cc                                              	int3
  707448:	cc                                              	int3
  707449:	cc                                              	int3
  70744a:	cc                                              	int3
  70744b:	cc                                              	int3
  70744c:	cc                                              	int3
  70744d:	cc                                              	int3
  70744e:	cc                                              	int3
  70744f:	cc                                              	int3

; N05 coroutine.resume constructs Boolean and result tuple

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00707230 <.text+0x306230>:
  707230:	55                                              	push   ebp
  707231:	8b ec                                           	mov    ebp,esp
  707233:	56                                              	push   esi
  707234:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  707237:	8b 46 0c                                        	mov    eax,DWORD PTR [esi+0xc]
  70723a:	57                                              	push   edi
  70723b:	3b 46 08                                        	cmp    eax,DWORD PTR [esi+0x8]
  70723e:	72 05                                           	jb     0x707245
  707240:	b8 c8 bf c0 00                                  	mov    eax,0xc0bfc8
  707245:	83 78 08 08                                     	cmp    DWORD PTR [eax+0x8],0x8
  707249:	53                                              	push   ebx
  70724a:	74 04                                           	je     0x707250
  70724c:	33 db                                           	xor    ebx,ebx
  70724e:	eb 06                                           	jmp    0x707256
  707250:	8b 18                                           	mov    ebx,DWORD PTR [eax]
  707252:	85 db                                           	test   ebx,ebx
  707254:	75 0f                                           	jne    0x707265
  707256:	6a 01                                           	push   0x1
  707258:	bf 8c 36 c4 00                                  	mov    edi,0xc4368c
  70725d:	e8 3e eb fe ff                                  	call   0x6f5da0
  707262:	83 c4 04                                        	add    esp,0x4
  707265:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  707268:	2b 46 0c                                        	sub    eax,DWORD PTR [esi+0xc]
  70726b:	c1 f8 04                                        	sar    eax,0x4
  70726e:	48                                              	dec    eax
  70726f:	50                                              	push   eax
  707270:	53                                              	push   ebx
  707271:	56                                              	push   esi
  707272:	e8 99 fe ff ff                                  	call   0x707110
  707277:	8b f8                                           	mov    edi,eax
  707279:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  70727c:	83 c4 0c                                        	add    esp,0xc
  70727f:	5b                                              	pop    ebx
  707280:	c7 40 08 01 00 00 00                            	mov    DWORD PTR [eax+0x8],0x1
  707287:	85 ff                                           	test   edi,edi
  707289:	79 1d                                           	jns    0x7072a8
  70728b:	c7 00 00 00 00 00                               	mov    DWORD PTR [eax],0x0
  707291:	83 46 08 10                                     	add    DWORD PTR [esi+0x8],0x10
  707295:	b8 fe ff ff ff                                  	mov    eax,0xfffffffe
  70729a:	e8 11 e0 fe ff                                  	call   0x6f52b0
  70729f:	5f                                              	pop    edi
  7072a0:	b8 02 00 00 00                                  	mov    eax,0x2
  7072a5:	5e                                              	pop    esi
  7072a6:	5d                                              	pop    ebp
  7072a7:	c3                                              	ret
  7072a8:	c7 00 01 00 00 00                               	mov    DWORD PTR [eax],0x1
  7072ae:	83 46 08 10                                     	add    DWORD PTR [esi+0x8],0x10
  7072b2:	83 c8 ff                                        	or     eax,0xffffffff
  7072b5:	2b c7                                           	sub    eax,edi
  7072b7:	e8 f4 df fe ff                                  	call   0x6f52b0
  7072bc:	8d 47 01                                        	lea    eax,[edi+0x1]
  7072bf:	5f                                              	pop    edi
  7072c0:	5e                                              	pop    esi
  7072c1:	5d                                              	pop    ebp
  7072c2:	c3                                              	ret
  7072c3:	cc                                              	int3
  7072c4:	cc                                              	int3
  7072c5:	cc                                              	int3
  7072c6:	cc                                              	int3
  7072c7:	cc                                              	int3
  7072c8:	cc                                              	int3
  7072c9:	cc                                              	int3
  7072ca:	cc                                              	int3
  7072cb:	cc                                              	int3
  7072cc:	cc                                              	int3
  7072cd:	cc                                              	int3
  7072ce:	cc                                              	int3
  7072cf:	cc                                              	int3

; N06 auxresume status rejection and success/error movement

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00707110 <.text+0x306110>:
  707110:	55                                              	push   ebp
  707111:	8b ec                                           	mov    ebp,esp
  707113:	83 ec 64                                        	sub    esp,0x64
  707116:	53                                              	push   ebx
  707117:	8b 5d 0c                                        	mov    ebx,DWORD PTR [ebp+0xc]
  70711a:	56                                              	push   esi
  70711b:	57                                              	push   edi
  70711c:	39 5d 08                                        	cmp    DWORD PTR [ebp+0x8],ebx
  70711f:	75 04                                           	jne    0x707125
  707121:	33 ff                                           	xor    edi,edi
  707123:	eb 44                                           	jmp    0x707169
  707125:	0f b6 43 06                                     	movzx  eax,BYTE PTR [ebx+0x6]
  707129:	83 e8 00                                        	sub    eax,0x0
  70712c:	74 11                                           	je     0x70713f
  70712e:	48                                              	dec    eax
  70712f:	74 07                                           	je     0x707138
  707131:	bf 03 00 00 00                                  	mov    edi,0x3
  707136:	eb 31                                           	jmp    0x707169
  707138:	bf 01 00 00 00                                  	mov    edi,0x1
  70713d:	eb 2a                                           	jmp    0x707169
  70713f:	8d 7d 9c                                        	lea    edi,[ebp-0x64]
  707142:	33 c9                                           	xor    ecx,ecx
  707144:	8b d3                                           	mov    edx,ebx
  707146:	e8 85 0c ff ff                                  	call   0x6f7dd0
  70714b:	85 c0                                           	test   eax,eax
  70714d:	7e 07                                           	jle    0x707156
  70714f:	bf 02 00 00 00                                  	mov    edi,0x2
  707154:	eb 13                                           	jmp    0x707169
  707156:	8b 7b 08                                        	mov    edi,DWORD PTR [ebx+0x8]
  707159:	2b 7b 0c                                        	sub    edi,DWORD PTR [ebx+0xc]
  70715c:	83 e7 f0                                        	and    edi,0xfffffff0
  70715f:	f7 df                                           	neg    edi
  707161:	1b ff                                           	sbb    edi,edi
  707163:	83 e7 fe                                        	and    edi,0xfffffffe
  707166:	83 c7 03                                        	add    edi,0x3
  707169:	8b 75 10                                        	mov    esi,DWORD PTR [ebp+0x10]
  70716c:	8b c6                                           	mov    eax,esi
  70716e:	8b cb                                           	mov    ecx,ebx
  707170:	e8 fb df fe ff                                  	call   0x6f5170
  707175:	85 c0                                           	test   eax,eax
  707177:	75 11                                           	jne    0x70718a
  707179:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  70717c:	68 a0 36 c4 00                                  	push   0xc436a0
  707181:	50                                              	push   eax
  707182:	e8 a9 ed fe ff                                  	call   0x6f5f30
  707187:	83 c4 08                                        	add    esp,0x8
  70718a:	83 ff 01                                        	cmp    edi,0x1
  70718d:	74 23                                           	je     0x7071b2
  70718f:	8b 0c bd 58 bc c0 00                            	mov    ecx,DWORD PTR [edi*4+0xc0bc58]
  707196:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  707199:	51                                              	push   ecx
  70719a:	68 c0 36 c4 00                                  	push   0xc436c0
  70719f:	52                                              	push   edx
  7071a0:	e8 db e3 fe ff                                  	call   0x6f5580
  7071a5:	83 c4 0c                                        	add    esp,0xc
  7071a8:	5f                                              	pop    edi
  7071a9:	5e                                              	pop    esi
  7071aa:	83 c8 ff                                        	or     eax,0xffffffff
  7071ad:	5b                                              	pop    ebx
  7071ae:	8b e5                                           	mov    esp,ebp
  7071b0:	5d                                              	pop    ebp
  7071b1:	c3                                              	ret
  7071b2:	8b 7d 08                                        	mov    edi,DWORD PTR [ebp+0x8]
  7071b5:	8b c6                                           	mov    eax,esi
  7071b7:	8b f3                                           	mov    esi,ebx
  7071b9:	e8 12 e0 fe ff                                  	call   0x6f51d0
  7071be:	8b 4d 10                                        	mov    ecx,DWORD PTR [ebp+0x10]
  7071c1:	8b f7                                           	mov    esi,edi
  7071c3:	66 8b 46 34                                     	mov    ax,WORD PTR [esi+0x34]
  7071c7:	66 89 43 34                                     	mov    WORD PTR [ebx+0x34],ax
  7071cb:	8b c3                                           	mov    eax,ebx
  7071cd:	e8 fe 74 ff ff                                  	call   0x6fe6d0
  7071d2:	85 c0                                           	test   eax,eax
  7071d4:	74 1b                                           	je     0x7071f1
  7071d6:	83 f8 01                                        	cmp    eax,0x1
  7071d9:	74 16                                           	je     0x7071f1
  7071db:	b8 01 00 00 00                                  	mov    eax,0x1
  7071e0:	8b fb                                           	mov    edi,ebx
  7071e2:	e8 e9 df fe ff                                  	call   0x6f51d0
  7071e7:	5f                                              	pop    edi
  7071e8:	5e                                              	pop    esi
  7071e9:	83 c8 ff                                        	or     eax,0xffffffff
  7071ec:	5b                                              	pop    ebx
  7071ed:	8b e5                                           	mov    esp,ebp
  7071ef:	5d                                              	pop    ebp
  7071f0:	c3                                              	ret
  7071f1:	8b 7b 08                                        	mov    edi,DWORD PTR [ebx+0x8]
  7071f4:	2b 7b 0c                                        	sub    edi,DWORD PTR [ebx+0xc]
  7071f7:	8b ce                                           	mov    ecx,esi
  7071f9:	c1 ff 04                                        	sar    edi,0x4
  7071fc:	8b c7                                           	mov    eax,edi
  7071fe:	89 7d 08                                        	mov    DWORD PTR [ebp+0x8],edi
  707201:	e8 6a df fe ff                                  	call   0x6f5170
  707206:	85 c0                                           	test   eax,eax
  707208:	75 0e                                           	jne    0x707218
  70720a:	68 dc 36 c4 00                                  	push   0xc436dc
  70720f:	56                                              	push   esi
  707210:	e8 1b ed fe ff                                  	call   0x6f5f30
  707215:	83 c4 08                                        	add    esp,0x8
  707218:	8b c7                                           	mov    eax,edi
  70721a:	8b fb                                           	mov    edi,ebx
  70721c:	e8 af df fe ff                                  	call   0x6f51d0
  707221:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  707224:	5f                                              	pop    edi
  707225:	5e                                              	pop    esi
  707226:	5b                                              	pop    ebx
  707227:	8b e5                                           	mov    esp,ebp
  707229:	5d                                              	pop    ebp
  70722a:	c3                                              	ret
  70722b:	cc                                              	int3
  70722c:	cc                                              	int3
  70722d:	cc                                              	int3
  70722e:	cc                                              	int3
  70722f:	cc                                              	int3

; N07 coroutine.status maps actual thread state

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00707070 <.text+0x306070>:
  707070:	55                                              	push   ebp
  707071:	8b ec                                           	mov    ebp,esp
  707073:	83 ec 64                                        	sub    esp,0x64
  707076:	53                                              	push   ebx
  707077:	56                                              	push   esi
  707078:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  70707b:	8b 46 0c                                        	mov    eax,DWORD PTR [esi+0xc]
  70707e:	57                                              	push   edi
  70707f:	3b 46 08                                        	cmp    eax,DWORD PTR [esi+0x8]
  707082:	72 05                                           	jb     0x707089
  707084:	b8 c8 bf c0 00                                  	mov    eax,0xc0bfc8
  707089:	83 78 08 08                                     	cmp    DWORD PTR [eax+0x8],0x8
  70708d:	74 04                                           	je     0x707093
  70708f:	33 db                                           	xor    ebx,ebx
  707091:	eb 06                                           	jmp    0x707099
  707093:	8b 18                                           	mov    ebx,DWORD PTR [eax]
  707095:	85 db                                           	test   ebx,ebx
  707097:	75 0f                                           	jne    0x7070a8
  707099:	6a 01                                           	push   0x1
  70709b:	bf 8c 36 c4 00                                  	mov    edi,0xc4368c
  7070a0:	e8 fb ec fe ff                                  	call   0x6f5da0
  7070a5:	83 c4 04                                        	add    esp,0x4
  7070a8:	3b f3                                           	cmp    esi,ebx
  7070aa:	75 04                                           	jne    0x7070b0
  7070ac:	33 c0                                           	xor    eax,eax
  7070ae:	eb 44                                           	jmp    0x7070f4
  7070b0:	0f b6 43 06                                     	movzx  eax,BYTE PTR [ebx+0x6]
  7070b4:	83 e8 00                                        	sub    eax,0x0
  7070b7:	74 11                                           	je     0x7070ca
  7070b9:	48                                              	dec    eax
  7070ba:	74 07                                           	je     0x7070c3
  7070bc:	b8 03 00 00 00                                  	mov    eax,0x3
  7070c1:	eb 31                                           	jmp    0x7070f4
  7070c3:	b8 01 00 00 00                                  	mov    eax,0x1
  7070c8:	eb 2a                                           	jmp    0x7070f4
  7070ca:	8d 7d 9c                                        	lea    edi,[ebp-0x64]
  7070cd:	33 c9                                           	xor    ecx,ecx
  7070cf:	8b d3                                           	mov    edx,ebx
  7070d1:	e8 fa 0c ff ff                                  	call   0x6f7dd0
  7070d6:	85 c0                                           	test   eax,eax
  7070d8:	7e 07                                           	jle    0x7070e1
  7070da:	b8 02 00 00 00                                  	mov    eax,0x2
  7070df:	eb 13                                           	jmp    0x7070f4
  7070e1:	8b 43 08                                        	mov    eax,DWORD PTR [ebx+0x8]
  7070e4:	2b 43 0c                                        	sub    eax,DWORD PTR [ebx+0xc]
  7070e7:	83 e0 f0                                        	and    eax,0xfffffff0
  7070ea:	f7 d8                                           	neg    eax
  7070ec:	1b c0                                           	sbb    eax,eax
  7070ee:	83 e0 fe                                        	and    eax,0xfffffffe
  7070f1:	83 c0 03                                        	add    eax,0x3
  7070f4:	8b 04 85 58 bc c0 00                            	mov    eax,DWORD PTR [eax*4+0xc0bc58]
  7070fb:	50                                              	push   eax
  7070fc:	e8 0f e4 fe ff                                  	call   0x6f5510
  707101:	83 c4 04                                        	add    esp,0x4
  707104:	5f                                              	pop    edi
  707105:	5e                                              	pop    esi
  707106:	b8 01 00 00 00                                  	mov    eax,0x1
  70710b:	5b                                              	pop    ebx
  70710c:	8b e5                                           	mov    esp,ebp
  70710e:	5d                                              	pop    ebp
  70710f:	c3                                              	ret

; N08 coroutine.yield accepted status and C-boundary error; old anchor reused

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00707480 <.text+0x306480>:
  707480:	55                                              	push   ebp
  707481:	8b ec                                           	mov    ebp,esp
  707483:	56                                              	push   esi
  707484:	57                                              	push   edi
  707485:	8b 7d 08                                        	mov    edi,DWORD PTR [ebp+0x8]
  707488:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  70748b:	66 8b 47 34                                     	mov    ax,WORD PTR [edi+0x34]
  70748f:	2b 77 0c                                        	sub    esi,DWORD PTR [edi+0xc]
  707492:	66 3b 47 36                                     	cmp    ax,WORD PTR [edi+0x36]
  707496:	76 0e                                           	jbe    0x7074a6
  707498:	68 40 2b c4 00                                  	push   0xc42b40
  70749d:	57                                              	push   edi
  70749e:	e8 bd 16 ff ff                                  	call   0x6f8b60
  7074a3:	83 c4 08                                        	add    esp,0x8
  7074a6:	8b 4f 08                                        	mov    ecx,DWORD PTR [edi+0x8]
  7074a9:	83 e6 f0                                        	and    esi,0xfffffff0
  7074ac:	2b ce                                           	sub    ecx,esi
  7074ae:	89 4f 0c                                        	mov    DWORD PTR [edi+0xc],ecx
  7074b1:	c6 47 06 01                                     	mov    BYTE PTR [edi+0x6],0x1
  7074b5:	5f                                              	pop    edi
  7074b6:	83 c8 ff                                        	or     eax,0xffffffff
  7074b9:	5e                                              	pop    esi
  7074ba:	5d                                              	pop    ebp
  7074bb:	c3                                              	ret
  7074bc:	cc                                              	int3
  7074bd:	cc                                              	int3
  7074be:	cc                                              	int3
  7074bf:	cc                                              	int3

; N09 coroutine.running main-thread nil distinction

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007074c0 <.text+0x3064c0>:
  7074c0:	55                                              	push   ebp
  7074c1:	8b ec                                           	mov    ebp,esp
  7074c3:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  7074c6:	8b 48 08                                        	mov    ecx,DWORD PTR [eax+0x8]
  7074c9:	89 01                                           	mov    DWORD PTR [ecx],eax
  7074cb:	c7 41 08 08 00 00 00                            	mov    DWORD PTR [ecx+0x8],0x8
  7074d2:	56                                              	push   esi
  7074d3:	8b 70 10                                        	mov    esi,DWORD PTR [eax+0x10]
  7074d6:	ba 10 00 00 00                                  	mov    edx,0x10
  7074db:	01 50 08                                        	add    DWORD PTR [eax+0x8],edx
  7074de:	39 46 70                                        	cmp    DWORD PTR [esi+0x70],eax
  7074e1:	8b 48 08                                        	mov    ecx,DWORD PTR [eax+0x8]
  7074e4:	5e                                              	pop    esi
  7074e5:	75 0a                                           	jne    0x7074f1
  7074e7:	c7 41 08 00 00 00 00                            	mov    DWORD PTR [ecx+0x8],0x0
  7074ee:	01 50 08                                        	add    DWORD PTR [eax+0x8],edx
  7074f1:	b8 01 00 00 00                                  	mov    eax,0x1
  7074f6:	5d                                              	pop    ebp
  7074f7:	c3                                              	ret
  7074f8:	cc                                              	int3
  7074f9:	cc                                              	int3
  7074fa:	cc                                              	int3
  7074fb:	cc                                              	int3
  7074fc:	cc                                              	int3
  7074fd:	cc                                              	int3
  7074fe:	cc                                              	int3
  7074ff:	cc                                              	int3

; N10 Lua call fixed-parameter top clipping and missing argument nil initialization

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe1c0 <.text+0x2fd1c0>:
  6fe1c0:	55                                              	push   ebp
  6fe1c1:	8b ec                                           	mov    ebp,esp
  6fe1c3:	83 ec 08                                        	sub    esp,0x8
  6fe1c6:	83 78 08 06                                     	cmp    DWORD PTR [eax+0x8],0x6
  6fe1ca:	53                                              	push   ebx
  6fe1cb:	56                                              	push   esi
  6fe1cc:	57                                              	push   edi
  6fe1cd:	8b f1                                           	mov    esi,ecx
  6fe1cf:	74 0b                                           	je     0x6fe1dc
  6fe1d1:	50                                              	push   eax
  6fe1d2:	8b fe                                           	mov    edi,esi
  6fe1d4:	e8 07 ff ff ff                                  	call   0x6fe0e0
  6fe1d9:	83 c4 04                                        	add    esp,0x4
  6fe1dc:	8b 4e 14                                        	mov    ecx,DWORD PTR [esi+0x14]
  6fe1df:	8b 56 18                                        	mov    edx,DWORD PTR [esi+0x18]
  6fe1e2:	8b d8                                           	mov    ebx,eax
  6fe1e4:	2b 5e 20                                        	sub    ebx,DWORD PTR [esi+0x20]
  6fe1e7:	8b 00                                           	mov    eax,DWORD PTR [eax]
  6fe1e9:	89 51 0c                                        	mov    DWORD PTR [ecx+0xc],edx
  6fe1ec:	80 78 06 00                                     	cmp    BYTE PTR [eax+0x6],0x0
  6fe1f0:	89 5d f8                                        	mov    DWORD PTR [ebp-0x8],ebx
  6fe1f3:	0f 85 ed 00 00 00                               	jne    0x6fe2e6
  6fe1f9:	8b 48 10                                        	mov    ecx,DWORD PTR [eax+0x10]
  6fe1fc:	0f b6 41 4b                                     	movzx  eax,BYTE PTR [ecx+0x4b]
  6fe200:	8b 56 1c                                        	mov    edx,DWORD PTR [esi+0x1c]
  6fe203:	2b 56 08                                        	sub    edx,DWORD PTR [esi+0x8]
  6fe206:	8b f8                                           	mov    edi,eax
  6fe208:	c1 e7 04                                        	shl    edi,0x4
  6fe20b:	89 4d fc                                        	mov    DWORD PTR [ebp-0x4],ecx
  6fe20e:	3b d7                                           	cmp    edx,edi
  6fe210:	7f 16                                           	jg     0x6fe228
  6fe212:	8b 4e 2c                                        	mov    ecx,DWORD PTR [esi+0x2c]
  6fe215:	3b c1                                           	cmp    eax,ecx
  6fe217:	7f 05                                           	jg     0x6fe21e
  6fe219:	8d 04 09                                        	lea    eax,[ecx+ecx*1]
  6fe21c:	eb 02                                           	jmp    0x6fe220
  6fe21e:	03 c1                                           	add    eax,ecx
  6fe220:	e8 8b fa ff ff                                  	call   0x6fdcb0
  6fe225:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  6fe228:	8b 7e 20                                        	mov    edi,DWORD PTR [esi+0x20]
  6fe22b:	03 fb                                           	add    edi,ebx
  6fe22d:	80 79 4a 00                                     	cmp    BYTE PTR [ecx+0x4a],0x0
  6fe231:	75 16                                           	jne    0x6fe249
  6fe233:	0f b6 41 49                                     	movzx  eax,BYTE PTR [ecx+0x49]
  6fe237:	c1 e0 04                                        	shl    eax,0x4
  6fe23a:	8d 5f 10                                        	lea    ebx,[edi+0x10]
  6fe23d:	03 c3                                           	add    eax,ebx
  6fe23f:	39 46 08                                        	cmp    DWORD PTR [esi+0x8],eax
  6fe242:	76 25                                           	jbe    0x6fe269
  6fe244:	89 46 08                                        	mov    DWORD PTR [esi+0x8],eax
  6fe247:	eb 20                                           	jmp    0x6fe269
  6fe249:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6fe24c:	2b c7                                           	sub    eax,edi
  6fe24e:	c1 f8 04                                        	sar    eax,0x4
  6fe251:	48                                              	dec    eax
  6fe252:	50                                              	push   eax
  6fe253:	56                                              	push   esi
  6fe254:	8b c1                                           	mov    eax,ecx
  6fe256:	e8 65 fc ff ff                                  	call   0x6fdec0
  6fe25b:	8b 7e 20                                        	mov    edi,DWORD PTR [esi+0x20]
  6fe25e:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  6fe261:	83 c4 08                                        	add    esp,0x8
  6fe264:	03 7d f8                                        	add    edi,DWORD PTR [ebp-0x8]
  6fe267:	8b d8                                           	mov    ebx,eax
  6fe269:	8b 46 14                                        	mov    eax,DWORD PTR [esi+0x14]
  6fe26c:	3b 46 24                                        	cmp    eax,DWORD PTR [esi+0x24]
  6fe26f:	75 0c                                           	jne    0x6fe27d
  6fe271:	8b c6                                           	mov    eax,esi
  6fe273:	e8 18 fb ff ff                                  	call   0x6fdd90
  6fe278:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  6fe27b:	eb 06                                           	jmp    0x6fe283
  6fe27d:	83 c0 18                                        	add    eax,0x18
  6fe280:	89 46 14                                        	mov    DWORD PTR [esi+0x14],eax
  6fe283:	89 78 04                                        	mov    DWORD PTR [eax+0x4],edi
  6fe286:	89 18                                           	mov    DWORD PTR [eax],ebx
  6fe288:	89 5e 0c                                        	mov    DWORD PTR [esi+0xc],ebx
  6fe28b:	0f b6 51 4b                                     	movzx  edx,BYTE PTR [ecx+0x4b]
  6fe28f:	c1 e2 04                                        	shl    edx,0x4
  6fe292:	03 d3                                           	add    edx,ebx
  6fe294:	89 50 08                                        	mov    DWORD PTR [eax+0x8],edx
  6fe297:	8b 49 0c                                        	mov    ecx,DWORD PTR [ecx+0xc]
  6fe29a:	89 4e 18                                        	mov    DWORD PTR [esi+0x18],ecx
  6fe29d:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  6fe2a0:	33 d2                                           	xor    edx,edx
  6fe2a2:	89 50 14                                        	mov    DWORD PTR [eax+0x14],edx
  6fe2a5:	89 48 10                                        	mov    DWORD PTR [eax+0x10],ecx
  6fe2a8:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  6fe2ab:	3b 48 08                                        	cmp    ecx,DWORD PTR [eax+0x8]
  6fe2ae:	73 0b                                           	jae    0x6fe2bb
  6fe2b0:	89 51 08                                        	mov    DWORD PTR [ecx+0x8],edx
  6fe2b3:	83 c1 10                                        	add    ecx,0x10
  6fe2b6:	3b 48 08                                        	cmp    ecx,DWORD PTR [eax+0x8]
  6fe2b9:	72 f5                                           	jb     0x6fe2b0
  6fe2bb:	f6 46 38 01                                     	test   BYTE PTR [esi+0x38],0x1
  6fe2bf:	8b 50 08                                        	mov    edx,DWORD PTR [eax+0x8]
  6fe2c2:	89 56 08                                        	mov    DWORD PTR [esi+0x8],edx
  6fe2c5:	74 16                                           	je     0x6fe2dd
  6fe2c7:	83 46 18 04                                     	add    DWORD PTR [esi+0x18],0x4
  6fe2cb:	6a ff                                           	push   0xffffffff
  6fe2cd:	33 d2                                           	xor    edx,edx
  6fe2cf:	8b ce                                           	mov    ecx,esi
  6fe2d1:	e8 0a fb ff ff                                  	call   0x6fdde0
  6fe2d6:	83 c4 04                                        	add    esp,0x4
  6fe2d9:	83 46 18 fc                                     	add    DWORD PTR [esi+0x18],0xfffffffc
  6fe2dd:	33 c0                                           	xor    eax,eax
  6fe2df:	5f                                              	pop    edi
  6fe2e0:	5e                                              	pop    esi
  6fe2e1:	5b                                              	pop    ebx
  6fe2e2:	8b e5                                           	mov    esp,ebp
  6fe2e4:	5d                                              	pop    ebp
  6fe2e5:	c3                                              	ret

; N11 table library registration

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070cbf0 <.text+0x30bbf0>:
  70cbf0:	55                                              	push   ebp
  70cbf1:	8b ec                                           	mov    ebp,esp
  70cbf3:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  70cbf6:	68 68 b9 c0 00                                  	push   0xc0b968
  70cbfb:	68 84 28 c4 00                                  	push   0xc42884
  70cc00:	e8 8b 99 fe ff                                  	call   0x6f6590
  70cc05:	83 c4 08                                        	add    esp,0x8
  70cc08:	b8 01 00 00 00                                  	mov    eax,0x1
  70cc0d:	5d                                              	pop    ebp
  70cc0e:	c3                                              	ret

; N12 table.getn returns numeric table boundary

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070bbe0 <.text+0x30abe0>:
  70bbe0:	55                                              	push   ebp
  70bbe1:	8b ec                                           	mov    ebp,esp
  70bbe3:	53                                              	push   ebx
  70bbe4:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  70bbe7:	8b 43 0c                                        	mov    eax,DWORD PTR [ebx+0xc]
  70bbea:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  70bbed:	56                                              	push   esi
  70bbee:	57                                              	push   edi
  70bbef:	3b c1                                           	cmp    eax,ecx
  70bbf1:	73 20                                           	jae    0x70bc13
  70bbf3:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  70bbf8:	74 06                                           	je     0x70bc00
  70bbfa:	83 78 08 05                                     	cmp    DWORD PTR [eax+0x8],0x5
  70bbfe:	74 41                                           	je     0x70bc41
  70bc00:	3b c1                                           	cmp    eax,ecx
  70bc02:	73 0f                                           	jae    0x70bc13
  70bc04:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  70bc09:	74 08                                           	je     0x70bc13
  70bc0b:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  70bc0e:	83 f8 ff                                        	cmp    eax,0xffffffff
  70bc11:	75 07                                           	jne    0x70bc1a
  70bc13:	b8 f4 26 c4 00                                  	mov    eax,0xc426f4
  70bc18:	eb 07                                           	jmp    0x70bc21
  70bc1a:	8b 04 85 1c be c0 00                            	mov    eax,DWORD PTR [eax*4+0xc0be1c]
  70bc21:	50                                              	push   eax
  70bc22:	a1 30 be c0 00                                  	mov    eax,ds:0xc0be30
  70bc27:	50                                              	push   eax
  70bc28:	68 68 27 c4 00                                  	push   0xc42768
  70bc2d:	53                                              	push   ebx
  70bc2e:	e8 4d 99 fe ff                                  	call   0x6f5580
  70bc33:	6a 01                                           	push   0x1
  70bc35:	8b f8                                           	mov    edi,eax
  70bc37:	8b f3                                           	mov    esi,ebx
  70bc39:	e8 62 a1 fe ff                                  	call   0x6f5da0
  70bc3e:	83 c4 14                                        	add    esp,0x14
  70bc41:	8b 73 0c                                        	mov    esi,DWORD PTR [ebx+0xc]
  70bc44:	3b 73 08                                        	cmp    esi,DWORD PTR [ebx+0x8]
  70bc47:	72 05                                           	jb     0x70bc4e
  70bc49:	be c8 bf c0 00                                  	mov    esi,0xc0bfc8
  70bc4e:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  70bc51:	83 c0 fd                                        	add    eax,0xfffffffd
  70bc54:	83 f8 04                                        	cmp    eax,0x4
  70bc57:	77 43                                           	ja     0x70bc9c
  70bc59:	ff 24 85 c0 bc 70 00                            	jmp    DWORD PTR [eax*4+0x70bcc0]
  70bc60:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  70bc62:	8b 51 0c                                        	mov    edx,DWORD PTR [ecx+0xc]
  70bc65:	89 55 08                                        	mov    DWORD PTR [ebp+0x8],edx
  70bc68:	eb 39                                           	jmp    0x70bca3
  70bc6a:	8b 06                                           	mov    eax,DWORD PTR [esi]
  70bc6c:	8b 48 10                                        	mov    ecx,DWORD PTR [eax+0x10]
  70bc6f:	89 4d 08                                        	mov    DWORD PTR [ebp+0x8],ecx
  70bc72:	eb 2f                                           	jmp    0x70bca3
  70bc74:	8b 06                                           	mov    eax,DWORD PTR [esi]
  70bc76:	e8 95 e2 fe ff                                  	call   0x6f9f10
  70bc7b:	89 45 08                                        	mov    DWORD PTR [ebp+0x8],eax
  70bc7e:	eb 23                                           	jmp    0x70bca3
  70bc80:	8b fb                                           	mov    edi,ebx
  70bc82:	e8 49 f9 fe ff                                  	call   0x6fb5d0
  70bc87:	85 c0                                           	test   eax,eax
  70bc89:	74 0a                                           	je     0x70bc95
  70bc8b:	8b 16                                           	mov    edx,DWORD PTR [esi]
  70bc8d:	8b 42 0c                                        	mov    eax,DWORD PTR [edx+0xc]
  70bc90:	89 45 08                                        	mov    DWORD PTR [ebp+0x8],eax
  70bc93:	eb 0e                                           	jmp    0x70bca3
  70bc95:	33 c0                                           	xor    eax,eax
  70bc97:	89 45 08                                        	mov    DWORD PTR [ebp+0x8],eax
  70bc9a:	eb 07                                           	jmp    0x70bca3
  70bc9c:	c7 45 08 00 00 00 00                            	mov    DWORD PTR [ebp+0x8],0x0
  70bca3:	8b 43 08                                        	mov    eax,DWORD PTR [ebx+0x8]
  70bca6:	db 45 08                                        	fild   DWORD PTR [ebp+0x8]
  70bca9:	5f                                              	pop    edi
  70bcaa:	c7 40 08 03 00 00 00                            	mov    DWORD PTR [eax+0x8],0x3
  70bcb1:	dd 18                                           	fstp   QWORD PTR [eax]
  70bcb3:	83 43 08 10                                     	add    DWORD PTR [ebx+0x8],0x10
  70bcb7:	5e                                              	pop    esi
  70bcb8:	b8 01 00 00 00                                  	mov    eax,0x1
  70bcbd:	5b                                              	pop    ebx
  70bcbe:	5d                                              	pop    ebp
  70bcbf:	c3                                              	ret

; N13 table.insert appends for two arguments

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070bd80 <.text+0x30ad80>:
  70bd80:	55                                              	push   ebp
  70bd81:	8b ec                                           	mov    ebp,esp
  70bd83:	83 ec 08                                        	sub    esp,0x8
  70bd86:	53                                              	push   ebx
  70bd87:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  70bd8a:	8b 43 0c                                        	mov    eax,DWORD PTR [ebx+0xc]
  70bd8d:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  70bd90:	56                                              	push   esi
  70bd91:	57                                              	push   edi
  70bd92:	3b c1                                           	cmp    eax,ecx
  70bd94:	73 20                                           	jae    0x70bdb6
  70bd96:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  70bd9b:	74 06                                           	je     0x70bda3
  70bd9d:	83 78 08 05                                     	cmp    DWORD PTR [eax+0x8],0x5
  70bda1:	74 41                                           	je     0x70bde4
  70bda3:	3b c1                                           	cmp    eax,ecx
  70bda5:	73 0f                                           	jae    0x70bdb6
  70bda7:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  70bdac:	74 08                                           	je     0x70bdb6
  70bdae:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  70bdb1:	83 f8 ff                                        	cmp    eax,0xffffffff
  70bdb4:	75 07                                           	jne    0x70bdbd
  70bdb6:	b8 f4 26 c4 00                                  	mov    eax,0xc426f4
  70bdbb:	eb 07                                           	jmp    0x70bdc4
  70bdbd:	8b 04 85 1c be c0 00                            	mov    eax,DWORD PTR [eax*4+0xc0be1c]
  70bdc4:	50                                              	push   eax
  70bdc5:	a1 30 be c0 00                                  	mov    eax,ds:0xc0be30
  70bdca:	50                                              	push   eax
  70bdcb:	68 68 27 c4 00                                  	push   0xc42768
  70bdd0:	53                                              	push   ebx
  70bdd1:	e8 aa 97 fe ff                                  	call   0x6f5580
  70bdd6:	6a 01                                           	push   0x1
  70bdd8:	8b f8                                           	mov    edi,eax
  70bdda:	8b f3                                           	mov    esi,ebx
  70bddc:	e8 bf 9f fe ff                                  	call   0x6f5da0
  70bde1:	83 c4 14                                        	add    esp,0x14
  70bde4:	8b 73 0c                                        	mov    esi,DWORD PTR [ebx+0xc]
  70bde7:	3b 73 08                                        	cmp    esi,DWORD PTR [ebx+0x8]
  70bdea:	72 05                                           	jb     0x70bdf1
  70bdec:	be c8 bf c0 00                                  	mov    esi,0xc0bfc8
  70bdf1:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  70bdf4:	83 c0 fd                                        	add    eax,0xfffffffd
  70bdf7:	83 f8 04                                        	cmp    eax,0x4
  70bdfa:	77 30                                           	ja     0x70be2c
  70bdfc:	ff 24 85 dc be 70 00                            	jmp    DWORD PTR [eax*4+0x70bedc]
  70be03:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  70be05:	8b 41 0c                                        	mov    eax,DWORD PTR [ecx+0xc]
  70be08:	eb 24                                           	jmp    0x70be2e
  70be0a:	8b 16                                           	mov    edx,DWORD PTR [esi]
  70be0c:	8b 42 10                                        	mov    eax,DWORD PTR [edx+0x10]
  70be0f:	eb 1d                                           	jmp    0x70be2e
  70be11:	8b 06                                           	mov    eax,DWORD PTR [esi]
  70be13:	e8 f8 e0 fe ff                                  	call   0x6f9f10
  70be18:	eb 14                                           	jmp    0x70be2e
  70be1a:	8b fb                                           	mov    edi,ebx
  70be1c:	e8 af f7 fe ff                                  	call   0x6fb5d0
  70be21:	85 c0                                           	test   eax,eax
  70be23:	74 07                                           	je     0x70be2c
  70be25:	8b 06                                           	mov    eax,DWORD PTR [esi]
  70be27:	8b 40 0c                                        	mov    eax,DWORD PTR [eax+0xc]
  70be2a:	eb 02                                           	jmp    0x70be2e
  70be2c:	33 c0                                           	xor    eax,eax
  70be2e:	8d 78 01                                        	lea    edi,[eax+0x1]
  70be31:	8b 43 08                                        	mov    eax,DWORD PTR [ebx+0x8]
  70be34:	2b 43 0c                                        	sub    eax,DWORD PTR [ebx+0xc]
  70be37:	c1 f8 04                                        	sar    eax,0x4
  70be3a:	83 e8 02                                        	sub    eax,0x2
  70be3d:	74 7d                                           	je     0x70bebc
  70be3f:	48                                              	dec    eax
  70be40:	74 15                                           	je     0x70be57
  70be42:	68 94 3c c4 00                                  	push   0xc43c94
  70be47:	53                                              	push   ebx
  70be48:	e8 e3 a0 fe ff                                  	call   0x6f5f30
  70be4d:	83 c4 08                                        	add    esp,0x8
  70be50:	5f                                              	pop    edi
  70be51:	5e                                              	pop    esi
  70be52:	5b                                              	pop    ebx
  70be53:	8b e5                                           	mov    esp,ebp
  70be55:	5d                                              	pop    ebp
  70be56:	c3                                              	ret
  70be57:	6a 02                                           	push   0x2
  70be59:	53                                              	push   ebx
  70be5a:	e8 11 a5 fe ff                                  	call   0x6f6370
  70be5f:	83 c4 08                                        	add    esp,0x8
  70be62:	89 45 08                                        	mov    DWORD PTR [ebp+0x8],eax
  70be65:	3b f8                                           	cmp    edi,eax
  70be67:	7d 04                                           	jge    0x70be6d
  70be69:	8b f8                                           	mov    edi,eax
  70be6b:	3b f8                                           	cmp    edi,eax
  70be6d:	7e 53                                           	jle    0x70bec2
  70be6f:	90                                              	nop
  70be70:	8b 43 0c                                        	mov    eax,DWORD PTR [ebx+0xc]
  70be73:	3b 43 08                                        	cmp    eax,DWORD PTR [ebx+0x8]
  70be76:	72 05                                           	jb     0x70be7d
  70be78:	b8 c8 bf c0 00                                  	mov    eax,0xc0bfc8
  70be7d:	8b 30                                           	mov    esi,DWORD PTR [eax]
  70be7f:	8d 4f ff                                        	lea    ecx,[edi-0x1]
  70be82:	51                                              	push   ecx
  70be83:	89 4d f8                                        	mov    DWORD PTR [ebp-0x8],ecx
  70be86:	e8 e5 dc fe ff                                  	call   0x6f9b70
  70be8b:	8b 10                                           	mov    edx,DWORD PTR [eax]
  70be8d:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  70be90:	89 11                                           	mov    DWORD PTR [ecx],edx
  70be92:	8b 50 04                                        	mov    edx,DWORD PTR [eax+0x4]
  70be95:	89 51 04                                        	mov    DWORD PTR [ecx+0x4],edx
  70be98:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  70be9b:	89 41 08                                        	mov    DWORD PTR [ecx+0x8],eax
  70be9e:	83 43 08 10                                     	add    DWORD PTR [ebx+0x8],0x10
  70bea2:	57                                              	push   edi
  70bea3:	b8 01 00 00 00                                  	mov    eax,0x1
  70bea8:	8b fb                                           	mov    edi,ebx
  70beaa:	e8 c1 99 fe ff                                  	call   0x6f5870
  70beaf:	8b 7d f8                                        	mov    edi,DWORD PTR [ebp-0x8]
  70beb2:	83 c4 08                                        	add    esp,0x8
  70beb5:	3b 7d 08                                        	cmp    edi,DWORD PTR [ebp+0x8]
  70beb8:	7f b6                                           	jg     0x70be70
  70beba:	eb 03                                           	jmp    0x70bebf
  70bebc:	89 7d 08                                        	mov    DWORD PTR [ebp+0x8],edi
  70bebf:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  70bec2:	50                                              	push   eax
  70bec3:	b8 01 00 00 00                                  	mov    eax,0x1
  70bec8:	8b fb                                           	mov    edi,ebx
  70beca:	e8 a1 99 fe ff                                  	call   0x6f5870
  70becf:	83 c4 04                                        	add    esp,0x4
  70bed2:	5f                                              	pop    edi
  70bed3:	5e                                              	pop    esi
  70bed4:	33 c0                                           	xor    eax,eax
  70bed6:	5b                                              	pop    ebx
  70bed7:	8b e5                                           	mov    esp,ebp
  70bed9:	5d                                              	pop    ebp
  70beda:	c3                                              	ret

; N14 table.remove returns removed item, shifts down, nils final slot

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070bef0 <.text+0x30aef0>:
  70bef0:	55                                              	push   ebp
  70bef1:	8b ec                                           	mov    ebp,esp
  70bef3:	83 ec 0c                                        	sub    esp,0xc
  70bef6:	53                                              	push   ebx
  70bef7:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  70befa:	8b 43 0c                                        	mov    eax,DWORD PTR [ebx+0xc]
  70befd:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  70bf00:	56                                              	push   esi
  70bf01:	57                                              	push   edi
  70bf02:	3b c1                                           	cmp    eax,ecx
  70bf04:	73 20                                           	jae    0x70bf26
  70bf06:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  70bf0b:	74 06                                           	je     0x70bf13
  70bf0d:	83 78 08 05                                     	cmp    DWORD PTR [eax+0x8],0x5
  70bf11:	74 41                                           	je     0x70bf54
  70bf13:	3b c1                                           	cmp    eax,ecx
  70bf15:	73 0f                                           	jae    0x70bf26
  70bf17:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  70bf1c:	74 08                                           	je     0x70bf26
  70bf1e:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  70bf21:	83 f8 ff                                        	cmp    eax,0xffffffff
  70bf24:	75 07                                           	jne    0x70bf2d
  70bf26:	b8 f4 26 c4 00                                  	mov    eax,0xc426f4
  70bf2b:	eb 07                                           	jmp    0x70bf34
  70bf2d:	8b 04 85 1c be c0 00                            	mov    eax,DWORD PTR [eax*4+0xc0be1c]
  70bf34:	50                                              	push   eax
  70bf35:	a1 30 be c0 00                                  	mov    eax,ds:0xc0be30
  70bf3a:	50                                              	push   eax
  70bf3b:	68 68 27 c4 00                                  	push   0xc42768
  70bf40:	53                                              	push   ebx
  70bf41:	e8 3a 96 fe ff                                  	call   0x6f5580
  70bf46:	6a 01                                           	push   0x1
  70bf48:	8b f8                                           	mov    edi,eax
  70bf4a:	8b f3                                           	mov    esi,ebx
  70bf4c:	e8 4f 9e fe ff                                  	call   0x6f5da0
  70bf51:	83 c4 14                                        	add    esp,0x14
  70bf54:	8b 73 0c                                        	mov    esi,DWORD PTR [ebx+0xc]
  70bf57:	3b 73 08                                        	cmp    esi,DWORD PTR [ebx+0x8]
  70bf5a:	72 05                                           	jb     0x70bf61
  70bf5c:	be c8 bf c0 00                                  	mov    esi,0xc0bfc8
  70bf61:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  70bf64:	83 c0 fd                                        	add    eax,0xfffffffd
  70bf67:	83 f8 04                                        	cmp    eax,0x4
  70bf6a:	77 43                                           	ja     0x70bfaf
  70bf6c:	ff 24 85 a8 c0 70 00                            	jmp    DWORD PTR [eax*4+0x70c0a8]
  70bf73:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  70bf75:	8b 51 0c                                        	mov    edx,DWORD PTR [ecx+0xc]
  70bf78:	89 55 fc                                        	mov    DWORD PTR [ebp-0x4],edx
  70bf7b:	eb 39                                           	jmp    0x70bfb6
  70bf7d:	8b 06                                           	mov    eax,DWORD PTR [esi]
  70bf7f:	8b 48 10                                        	mov    ecx,DWORD PTR [eax+0x10]
  70bf82:	89 4d fc                                        	mov    DWORD PTR [ebp-0x4],ecx
  70bf85:	eb 2f                                           	jmp    0x70bfb6
  70bf87:	8b 06                                           	mov    eax,DWORD PTR [esi]
  70bf89:	e8 82 df fe ff                                  	call   0x6f9f10
  70bf8e:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  70bf91:	eb 23                                           	jmp    0x70bfb6
  70bf93:	8b fb                                           	mov    edi,ebx
  70bf95:	e8 36 f6 fe ff                                  	call   0x6fb5d0
  70bf9a:	85 c0                                           	test   eax,eax
  70bf9c:	74 0a                                           	je     0x70bfa8
  70bf9e:	8b 16                                           	mov    edx,DWORD PTR [esi]
  70bfa0:	8b 42 0c                                        	mov    eax,DWORD PTR [edx+0xc]
  70bfa3:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  70bfa6:	eb 0e                                           	jmp    0x70bfb6
  70bfa8:	33 c0                                           	xor    eax,eax
  70bfaa:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  70bfad:	eb 07                                           	jmp    0x70bfb6
  70bfaf:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  70bfb6:	8b 43 0c                                        	mov    eax,DWORD PTR [ebx+0xc]
  70bfb9:	83 c0 10                                        	add    eax,0x10
  70bfbc:	3b 43 08                                        	cmp    eax,DWORD PTR [ebx+0x8]
  70bfbf:	73 0d                                           	jae    0x70bfce
  70bfc1:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  70bfc6:	74 06                                           	je     0x70bfce
  70bfc8:	83 78 08 00                                     	cmp    DWORD PTR [eax+0x8],0x0
  70bfcc:	7f 05                                           	jg     0x70bfd3
  70bfce:	8b 7d fc                                        	mov    edi,DWORD PTR [ebp-0x4]
  70bfd1:	eb 0d                                           	jmp    0x70bfe0
  70bfd3:	6a 02                                           	push   0x2
  70bfd5:	53                                              	push   ebx
  70bfd6:	e8 95 a3 fe ff                                  	call   0x6f6370
  70bfdb:	83 c4 08                                        	add    esp,0x8
  70bfde:	8b f8                                           	mov    edi,eax
  70bfe0:	83 ff 01                                        	cmp    edi,0x1
  70bfe3:	0f 8c b4 00 00 00                               	jl     0x70c09d
  70bfe9:	3b 7d fc                                        	cmp    edi,DWORD PTR [ebp-0x4]
  70bfec:	0f 8f ab 00 00 00                               	jg     0x70c09d
  70bff2:	8b 43 0c                                        	mov    eax,DWORD PTR [ebx+0xc]
  70bff5:	3b 43 08                                        	cmp    eax,DWORD PTR [ebx+0x8]
  70bff8:	72 05                                           	jb     0x70bfff
  70bffa:	b8 c8 bf c0 00                                  	mov    eax,0xc0bfc8
  70bfff:	8b 30                                           	mov    esi,DWORD PTR [eax]
  70c001:	57                                              	push   edi
  70c002:	e8 69 db fe ff                                  	call   0x6f9b70
  70c007:	8b 10                                           	mov    edx,DWORD PTR [eax]
  70c009:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  70c00c:	89 11                                           	mov    DWORD PTR [ecx],edx
  70c00e:	8b 50 04                                        	mov    edx,DWORD PTR [eax+0x4]
  70c011:	89 51 04                                        	mov    DWORD PTR [ecx+0x4],edx
  70c014:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  70c017:	89 41 08                                        	mov    DWORD PTR [ecx+0x8],eax
  70c01a:	83 43 08 10                                     	add    DWORD PTR [ebx+0x8],0x10
  70c01e:	83 c4 04                                        	add    esp,0x4
  70c021:	3b 7d fc                                        	cmp    edi,DWORD PTR [ebp-0x4]
  70c024:	7d 4a                                           	jge    0x70c070
  70c026:	8b 4b 0c                                        	mov    ecx,DWORD PTR [ebx+0xc]
  70c029:	3b 4b 08                                        	cmp    ecx,DWORD PTR [ebx+0x8]
  70c02c:	72 05                                           	jb     0x70c033
  70c02e:	b9 c8 bf c0 00                                  	mov    ecx,0xc0bfc8
  70c033:	8b 31                                           	mov    esi,DWORD PTR [ecx]
  70c035:	8d 47 01                                        	lea    eax,[edi+0x1]
  70c038:	50                                              	push   eax
  70c039:	89 45 f4                                        	mov    DWORD PTR [ebp-0xc],eax
  70c03c:	e8 2f db fe ff                                  	call   0x6f9b70
  70c041:	8b 10                                           	mov    edx,DWORD PTR [eax]
  70c043:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  70c046:	89 11                                           	mov    DWORD PTR [ecx],edx
  70c048:	8b 50 04                                        	mov    edx,DWORD PTR [eax+0x4]
  70c04b:	89 51 04                                        	mov    DWORD PTR [ecx+0x4],edx
  70c04e:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  70c051:	89 41 08                                        	mov    DWORD PTR [ecx+0x8],eax
  70c054:	83 43 08 10                                     	add    DWORD PTR [ebx+0x8],0x10
  70c058:	57                                              	push   edi
  70c059:	b8 01 00 00 00                                  	mov    eax,0x1
  70c05e:	8b fb                                           	mov    edi,ebx
  70c060:	e8 0b 98 fe ff                                  	call   0x6f5870
  70c065:	8b 7d f4                                        	mov    edi,DWORD PTR [ebp-0xc]
  70c068:	83 c4 08                                        	add    esp,0x8
  70c06b:	3b 7d fc                                        	cmp    edi,DWORD PTR [ebp-0x4]
  70c06e:	7c b6                                           	jl     0x70c026
  70c070:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  70c073:	8b 55 fc                                        	mov    edx,DWORD PTR [ebp-0x4]
  70c076:	c7 41 08 00 00 00 00                            	mov    DWORD PTR [ecx+0x8],0x0
  70c07d:	83 43 08 10                                     	add    DWORD PTR [ebx+0x8],0x10
  70c081:	52                                              	push   edx
  70c082:	b8 01 00 00 00                                  	mov    eax,0x1
  70c087:	8b fb                                           	mov    edi,ebx
  70c089:	e8 e2 97 fe ff                                  	call   0x6f5870
  70c08e:	83 c4 04                                        	add    esp,0x4
  70c091:	5f                                              	pop    edi
  70c092:	5e                                              	pop    esi
  70c093:	b8 01 00 00 00                                  	mov    eax,0x1
  70c098:	5b                                              	pop    ebx
  70c099:	8b e5                                           	mov    esp,ebp
  70c09b:	5d                                              	pop    ebp
  70c09c:	c3                                              	ret
  70c09d:	5f                                              	pop    edi
  70c09e:	5e                                              	pop    esi
  70c09f:	33 c0                                           	xor    eax,eax
  70c0a1:	5b                                              	pop    ebx
  70c0a2:	8b e5                                           	mov    esp,ebp
  70c0a4:	5d                                              	pop    ebp
  70c0a5:	c3                                              	ret

; N15 table array boundary search

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f9f10 <.text+0x2f8f10>:
  6f9f10:	8b 50 1c                                        	mov    edx,DWORD PTR [eax+0x1c]
  6f9f13:	56                                              	push   esi
  6f9f14:	57                                              	push   edi
  6f9f15:	85 d2                                           	test   edx,edx
  6f9f17:	74 39                                           	je     0x6f9f52
  6f9f19:	8b 70 0c                                        	mov    esi,DWORD PTR [eax+0xc]
  6f9f1c:	8b ca                                           	mov    ecx,edx
  6f9f1e:	03 c9                                           	add    ecx,ecx
  6f9f20:	83 7c ce f8 00                                  	cmp    DWORD PTR [esi+ecx*8-0x8],0x0
  6f9f25:	75 2b                                           	jne    0x6f9f52
  6f9f27:	33 c0                                           	xor    eax,eax
  6f9f29:	83 fa 01                                        	cmp    edx,0x1
  6f9f2c:	76 3b                                           	jbe    0x6f9f69
  6f9f2e:	8b ff                                           	mov    edi,edi
  6f9f30:	8d 0c 10                                        	lea    ecx,[eax+edx*1]
  6f9f33:	d1 e9                                           	shr    ecx,1
  6f9f35:	8b f9                                           	mov    edi,ecx
  6f9f37:	03 ff                                           	add    edi,edi
  6f9f39:	83 7c fe f8 00                                  	cmp    DWORD PTR [esi+edi*8-0x8],0x0
  6f9f3e:	75 04                                           	jne    0x6f9f44
  6f9f40:	8b d1                                           	mov    edx,ecx
  6f9f42:	eb 02                                           	jmp    0x6f9f46
  6f9f44:	8b c1                                           	mov    eax,ecx
  6f9f46:	8b ca                                           	mov    ecx,edx
  6f9f48:	2b c8                                           	sub    ecx,eax
  6f9f4a:	83 f9 01                                        	cmp    ecx,0x1
  6f9f4d:	77 e1                                           	ja     0x6f9f30
  6f9f4f:	5f                                              	pop    edi
  6f9f50:	5e                                              	pop    esi
  6f9f51:	c3                                              	ret
  6f9f52:	81 78 10 a8 bf c0 00                            	cmp    DWORD PTR [eax+0x10],0xc0bfa8
  6f9f59:	75 05                                           	jne    0x6f9f60
  6f9f5b:	8b c2                                           	mov    eax,edx
  6f9f5d:	5f                                              	pop    edi
  6f9f5e:	5e                                              	pop    esi
  6f9f5f:	c3                                              	ret
  6f9f60:	52                                              	push   edx
  6f9f61:	e8 7a fe ff ff                                  	call   0x6f9de0
  6f9f66:	83 c4 04                                        	add    esp,0x4
  6f9f69:	5f                                              	pop    edi
  6f9f6a:	5e                                              	pop    esi
  6f9f6b:	c3                                              	ret

; N16 binary Proto header writes nups params vararg maxstack

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070d4f2 <.text+0x30c4f2>:
  70d4f2:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  70d4f5:	8d 54 24 13                                     	lea    edx,[esp+0x13]
  70d4f9:	89 47 40                                        	mov    DWORD PTR [edi+0x40],eax
  70d4fc:	8b 73 04                                        	mov    esi,DWORD PTR [ebx+0x4]
  70d4ff:	6a 01                                           	push   0x1
  70d501:	52                                              	push   edx
  70d502:	e8 89 19 ff ff                                  	call   0x6fee90
  70d507:	83 c4 08                                        	add    esp,0x8
  70d50a:	85 c0                                           	test   eax,eax
  70d50c:	74 0c                                           	je     0x70d51a
  70d50e:	b8 3c 3e c4 00                                  	mov    eax,0xc43e3c
  70d513:	8b f3                                           	mov    esi,ebx
  70d515:	e8 f6 f6 ff ff                                  	call   0x70cc10
  70d51a:	8a 44 24 13                                     	mov    al,BYTE PTR [esp+0x13]
  70d51e:	8d 4c 24 13                                     	lea    ecx,[esp+0x13]
  70d522:	88 47 48                                        	mov    BYTE PTR [edi+0x48],al
  70d525:	8b 73 04                                        	mov    esi,DWORD PTR [ebx+0x4]
  70d528:	6a 01                                           	push   0x1
  70d52a:	51                                              	push   ecx
  70d52b:	e8 60 19 ff ff                                  	call   0x6fee90
  70d530:	83 c4 08                                        	add    esp,0x8
  70d533:	85 c0                                           	test   eax,eax
  70d535:	74 0c                                           	je     0x70d543
  70d537:	b8 3c 3e c4 00                                  	mov    eax,0xc43e3c
  70d53c:	8b f3                                           	mov    esi,ebx
  70d53e:	e8 cd f6 ff ff                                  	call   0x70cc10
  70d543:	8a 54 24 13                                     	mov    dl,BYTE PTR [esp+0x13]
  70d547:	8d 44 24 13                                     	lea    eax,[esp+0x13]
  70d54b:	88 57 49                                        	mov    BYTE PTR [edi+0x49],dl
  70d54e:	8b 73 04                                        	mov    esi,DWORD PTR [ebx+0x4]
  70d551:	6a 01                                           	push   0x1
  70d553:	50                                              	push   eax
  70d554:	e8 37 19 ff ff                                  	call   0x6fee90
  70d559:	83 c4 08                                        	add    esp,0x8
  70d55c:	85 c0                                           	test   eax,eax
  70d55e:	74 0c                                           	je     0x70d56c
  70d560:	b8 3c 3e c4 00                                  	mov    eax,0xc43e3c
  70d565:	8b f3                                           	mov    esi,ebx
  70d567:	e8 a4 f6 ff ff                                  	call   0x70cc10
  70d56c:	8a 4c 24 13                                     	mov    cl,BYTE PTR [esp+0x13]
  70d570:	8d 54 24 13                                     	lea    edx,[esp+0x13]
  70d574:	88 4f 4a                                        	mov    BYTE PTR [edi+0x4a],cl
  70d577:	8b 73 04                                        	mov    esi,DWORD PTR [ebx+0x4]
  70d57a:	6a 01                                           	push   0x1
  70d57c:	52                                              	push   edx
  70d57d:	e8 0e 19 ff ff                                  	call   0x6fee90
  70d582:	83 c4 08                                        	add    esp,0x8
  70d585:	85 c0                                           	test   eax,eax
  70d587:	74 0c                                           	je     0x70d595
  70d589:	b8 3c 3e c4 00                                  	mov    eax,0xc43e3c
  70d58e:	8b f3                                           	mov    esi,ebx
  70d590:	e8 7b f6 ff ff                                  	call   0x70cc10
  70d595:	8a 44 24 13                                     	mov    al,BYTE PTR [esp+0x13]
  70d599:	57                                              	push   edi
  70d59a:	53                                              	push   ebx
  70d59b:	88 47 4b                                        	mov    BYTE PTR [edi+0x4b],al

; N17 integer table-key lookup

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f9b70 <.text+0x2f8b70>:
  6f9b70:	55                                              	push   ebp
  6f9b71:	8b ec                                           	mov    ebp,esp
  6f9b73:	83 e4 f8                                        	and    esp,0xfffffff8
  6f9b76:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f9b79:	83 ec 0c                                        	sub    esp,0xc
  6f9b7c:	8d 48 ff                                        	lea    ecx,[eax-0x1]
  6f9b7f:	57                                              	push   edi
  6f9b80:	3b 4e 1c                                        	cmp    ecx,DWORD PTR [esi+0x1c]
  6f9b83:	73 0e                                           	jae    0x6f9b93
  6f9b85:	8b 56 0c                                        	mov    edx,DWORD PTR [esi+0xc]
  6f9b88:	03 c0                                           	add    eax,eax
  6f9b8a:	8d 44 c2 f0                                     	lea    eax,[edx+eax*8-0x10]
  6f9b8e:	5f                                              	pop    edi
  6f9b8f:	8b e5                                           	mov    esp,ebp
  6f9b91:	5d                                              	pop    ebp
  6f9b92:	c3                                              	ret
  6f9b93:	db 45 08                                        	fild   DWORD PTR [ebp+0x8]
  6f9b96:	dd 54 24 08                                     	fst    QWORD PTR [esp+0x8]
  6f9b9a:	d9 c0                                           	fld    st(0)
  6f9b9c:	d9 ee                                           	fldz
  6f9b9e:	da e9                                           	fucompp
  6f9ba0:	df e0                                           	fnstsw ax
  6f9ba2:	f6 c4 44                                        	test   ah,0x44
  6f9ba5:	7a 05                                           	jp     0x6f9bac
  6f9ba7:	8b 56 10                                        	mov    edx,DWORD PTR [esi+0x10]
  6f9baa:	eb 20                                           	jmp    0x6f9bcc
  6f9bac:	8a 4e 07                                        	mov    cl,BYTE PTR [esi+0x7]
  6f9baf:	8b 44 24 0c                                     	mov    eax,DWORD PTR [esp+0xc]
  6f9bb3:	03 44 24 08                                     	add    eax,DWORD PTR [esp+0x8]
  6f9bb7:	bf 01 00 00 00                                  	mov    edi,0x1
  6f9bbc:	d3 e7                                           	shl    edi,cl
  6f9bbe:	33 d2                                           	xor    edx,edx
  6f9bc0:	4f                                              	dec    edi
  6f9bc1:	83 cf 01                                        	or     edi,0x1
  6f9bc4:	f7 f7                                           	div    edi
  6f9bc6:	c1 e2 05                                        	shl    edx,0x5
  6f9bc9:	03 56 10                                        	add    edx,DWORD PTR [esi+0x10]
  6f9bcc:	85 d2                                           	test   edx,edx
  6f9bce:	74 1f                                           	je     0x6f9bef
  6f9bd0:	b9 03 00 00 00                                  	mov    ecx,0x3
  6f9bd5:	39 4a 18                                        	cmp    DWORD PTR [edx+0x18],ecx
  6f9bd8:	75 0e                                           	jne    0x6f9be8
  6f9bda:	dd 42 10                                        	fld    QWORD PTR [edx+0x10]
  6f9bdd:	d9 c1                                           	fld    st(1)
  6f9bdf:	da e9                                           	fucompp
  6f9be1:	df e0                                           	fnstsw ax
  6f9be3:	f6 c4 44                                        	test   ah,0x44
  6f9be6:	7b 13                                           	jnp    0x6f9bfb
  6f9be8:	8b 52 1c                                        	mov    edx,DWORD PTR [edx+0x1c]
  6f9beb:	85 d2                                           	test   edx,edx
  6f9bed:	75 e6                                           	jne    0x6f9bd5
  6f9bef:	b8 c8 bf c0 00                                  	mov    eax,0xc0bfc8
  6f9bf4:	dd d8                                           	fstp   st(0)
  6f9bf6:	5f                                              	pop    edi
  6f9bf7:	8b e5                                           	mov    esp,ebp
  6f9bf9:	5d                                              	pop    ebp
  6f9bfa:	c3                                              	ret
  6f9bfb:	8b c2                                           	mov    eax,edx
  6f9bfd:	dd d8                                           	fstp   st(0)
  6f9bff:	5f                                              	pop    edi
  6f9c00:	8b e5                                           	mov    esp,ebp
  6f9c02:	5d                                              	pop    ebp
  6f9c03:	c3                                              	ret

; N18 raw integer table set copies value and pops stack slot

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f5870 <.text+0x2f4870>:
  6f5870:	55                                              	push   ebp
  6f5871:	8b ec                                           	mov    ebp,esp
  6f5873:	83 e4 f8                                        	and    esp,0xfffffff8
  6f5876:	83 ec 18                                        	sub    esp,0x18
  6f5879:	53                                              	push   ebx
  6f587a:	56                                              	push   esi
  6f587b:	8b cf                                           	mov    ecx,edi
  6f587d:	e8 6e f8 ff ff                                  	call   0x6f50f0
  6f5882:	8b 30                                           	mov    esi,DWORD PTR [eax]
  6f5884:	8b 5f 08                                        	mov    ebx,DWORD PTR [edi+0x8]
  6f5887:	89 44 24 0c                                     	mov    DWORD PTR [esp+0xc],eax
  6f588b:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f588e:	50                                              	push   eax
  6f588f:	e8 dc 42 00 00                                  	call   0x6f9b70
  6f5894:	83 c4 04                                        	add    esp,0x4
  6f5897:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  6f589c:	75 1e                                           	jne    0x6f58bc
  6f589e:	db 45 08                                        	fild   DWORD PTR [ebp+0x8]
  6f58a1:	8d 4c 24 10                                     	lea    ecx,[esp+0x10]
  6f58a5:	51                                              	push   ecx
  6f58a6:	56                                              	push   esi
  6f58a7:	57                                              	push   edi
  6f58a8:	dd 5c 24 1c                                     	fstp   QWORD PTR [esp+0x1c]
  6f58ac:	c7 44 24 24 03 00 00 00                         	mov    DWORD PTR [esp+0x24],0x3
  6f58b4:	e8 a7 41 00 00                                  	call   0x6f9a60
  6f58b9:	83 c4 0c                                        	add    esp,0xc
  6f58bc:	8b 53 f0                                        	mov    edx,DWORD PTR [ebx-0x10]
  6f58bf:	89 10                                           	mov    DWORD PTR [eax],edx
  6f58c1:	8b 4b f4                                        	mov    ecx,DWORD PTR [ebx-0xc]
  6f58c4:	89 48 04                                        	mov    DWORD PTR [eax+0x4],ecx
  6f58c7:	8b 53 f8                                        	mov    edx,DWORD PTR [ebx-0x8]
  6f58ca:	89 50 08                                        	mov    DWORD PTR [eax+0x8],edx
  6f58cd:	8b 47 08                                        	mov    eax,DWORD PTR [edi+0x8]
  6f58d0:	b9 04 00 00 00                                  	mov    ecx,0x4
  6f58d5:	39 48 f8                                        	cmp    DWORD PTR [eax-0x8],ecx
  6f58d8:	7c 24                                           	jl     0x6f58fe
  6f58da:	8b 40 f0                                        	mov    eax,DWORD PTR [eax-0x10]
  6f58dd:	f6 40 05 03                                     	test   BYTE PTR [eax+0x5],0x3
  6f58e1:	74 1b                                           	je     0x6f58fe
  6f58e3:	8b 54 24 0c                                     	mov    edx,DWORD PTR [esp+0xc]
  6f58e7:	8b 02                                           	mov    eax,DWORD PTR [edx]
  6f58e9:	84 48 05                                        	test   BYTE PTR [eax+0x5],cl
  6f58ec:	74 10                                           	je     0x6f58fe
  6f58ee:	8b 4f 10                                        	mov    ecx,DWORD PTR [edi+0x10]
  6f58f1:	80 60 05 fb                                     	and    BYTE PTR [eax+0x5],0xfb
  6f58f5:	8b 51 28                                        	mov    edx,DWORD PTR [ecx+0x28]
  6f58f8:	89 50 18                                        	mov    DWORD PTR [eax+0x18],edx
  6f58fb:	89 41 28                                        	mov    DWORD PTR [ecx+0x28],eax
  6f58fe:	83 47 08 f0                                     	add    DWORD PTR [edi+0x8],0xfffffff0
  6f5902:	5e                                              	pop    esi
  6f5903:	5b                                              	pop    ebx
  6f5904:	8b e5                                           	mov    esp,ebp
  6f5906:	5d                                              	pop    ebp
  6f5907:	c3                                              	ret

; N19 table hash-side length boundary search

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f9de0 <.text+0x2f8de0>:
  6f9de0:	55                                              	push   ebp
  6f9de1:	8b ec                                           	mov    ebp,esp
  6f9de3:	83 e4 f8                                        	and    esp,0xfffffff8
  6f9de6:	83 ec 0c                                        	sub    esp,0xc
  6f9de9:	d9 ee                                           	fldz
  6f9deb:	53                                              	push   ebx
  6f9dec:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  6f9def:	56                                              	push   esi
  6f9df0:	89 5c 24 08                                     	mov    DWORD PTR [esp+0x8],ebx
  6f9df4:	8b f0                                           	mov    esi,eax
  6f9df6:	43                                              	inc    ebx
  6f9df7:	57                                              	push   edi
  6f9df8:	8b 7e 1c                                        	mov    edi,DWORD PTR [esi+0x1c]
  6f9dfb:	89 5d 08                                        	mov    DWORD PTR [ebp+0x8],ebx
  6f9dfe:	8d 43 ff                                        	lea    eax,[ebx-0x1]
  6f9e01:	3b c7                                           	cmp    eax,edi
  6f9e03:	73 0d                                           	jae    0x6f9e12
  6f9e05:	8b 56 0c                                        	mov    edx,DWORD PTR [esi+0xc]
  6f9e08:	8b cb                                           	mov    ecx,ebx
  6f9e0a:	03 c9                                           	add    ecx,ecx
  6f9e0c:	8d 54 ca f0                                     	lea    edx,[edx+ecx*8-0x10]
  6f9e10:	eb 65                                           	jmp    0x6f9e77
  6f9e12:	db 45 08                                        	fild   DWORD PTR [ebp+0x8]
  6f9e15:	dd 54 24 10                                     	fst    QWORD PTR [esp+0x10]
  6f9e19:	d9 c0                                           	fld    st(0)
  6f9e1b:	d9 c2                                           	fld    st(2)
  6f9e1d:	da e9                                           	fucompp
  6f9e1f:	df e0                                           	fnstsw ax
  6f9e21:	f6 c4 44                                        	test   ah,0x44
  6f9e24:	7a 05                                           	jp     0x6f9e2b
  6f9e26:	8b 56 10                                        	mov    edx,DWORD PTR [esi+0x10]
  6f9e29:	eb 26                                           	jmp    0x6f9e51
  6f9e2b:	8b 44 24 14                                     	mov    eax,DWORD PTR [esp+0x14]
  6f9e2f:	03 44 24 10                                     	add    eax,DWORD PTR [esp+0x10]
  6f9e33:	8a 4e 07                                        	mov    cl,BYTE PTR [esi+0x7]
  6f9e36:	ba 01 00 00 00                                  	mov    edx,0x1
  6f9e3b:	d3 e2                                           	shl    edx,cl
  6f9e3d:	4a                                              	dec    edx
  6f9e3e:	83 ca 01                                        	or     edx,0x1
  6f9e41:	89 54 24 10                                     	mov    DWORD PTR [esp+0x10],edx
  6f9e45:	33 d2                                           	xor    edx,edx
  6f9e47:	f7 74 24 10                                     	div    DWORD PTR [esp+0x10]
  6f9e4b:	c1 e2 05                                        	shl    edx,0x5
  6f9e4e:	03 56 10                                        	add    edx,DWORD PTR [esi+0x10]
  6f9e51:	85 d2                                           	test   edx,edx
  6f9e53:	74 1b                                           	je     0x6f9e70
  6f9e55:	83 7a 18 03                                     	cmp    DWORD PTR [edx+0x18],0x3
  6f9e59:	75 0e                                           	jne    0x6f9e69
  6f9e5b:	dd 42 10                                        	fld    QWORD PTR [edx+0x10]
  6f9e5e:	d9 c1                                           	fld    st(1)
  6f9e60:	da e9                                           	fucompp
  6f9e62:	df e0                                           	fnstsw ax
  6f9e64:	f6 c4 44                                        	test   ah,0x44
  6f9e67:	7b 0c                                           	jnp    0x6f9e75
  6f9e69:	8b 52 1c                                        	mov    edx,DWORD PTR [edx+0x1c]
  6f9e6c:	85 d2                                           	test   edx,edx
  6f9e6e:	75 e5                                           	jne    0x6f9e55
  6f9e70:	ba c8 bf c0 00                                  	mov    edx,0xc0bfc8
  6f9e75:	dd d8                                           	fstp   st(0)
  6f9e77:	83 7a 08 00                                     	cmp    DWORD PTR [edx+0x8],0x0
  6f9e7b:	74 45                                           	je     0x6f9ec2
  6f9e7d:	89 5c 24 0c                                     	mov    DWORD PTR [esp+0xc],ebx
  6f9e81:	03 db                                           	add    ebx,ebx
  6f9e83:	89 5d 08                                        	mov    DWORD PTR [ebp+0x8],ebx
  6f9e86:	81 fb fd ff ff 7f                               	cmp    ebx,0x7ffffffd
  6f9e8c:	0f 86 6c ff ff ff                               	jbe    0x6f9dfe
  6f9e92:	bf 01 00 00 00                                  	mov    edi,0x1
  6f9e97:	dd d8                                           	fstp   st(0)
  6f9e99:	57                                              	push   edi
  6f9e9a:	e8 d1 fc ff ff                                  	call   0x6f9b70
  6f9e9f:	83 c4 04                                        	add    esp,0x4
  6f9ea2:	83 78 08 00                                     	cmp    DWORD PTR [eax+0x8],0x0
  6f9ea6:	74 10                                           	je     0x6f9eb8
  6f9ea8:	47                                              	inc    edi
  6f9ea9:	57                                              	push   edi
  6f9eaa:	e8 c1 fc ff ff                                  	call   0x6f9b70
  6f9eaf:	83 c4 04                                        	add    esp,0x4
  6f9eb2:	83 78 08 00                                     	cmp    DWORD PTR [eax+0x8],0x0
  6f9eb6:	75 f0                                           	jne    0x6f9ea8
  6f9eb8:	8d 47 ff                                        	lea    eax,[edi-0x1]
  6f9ebb:	5f                                              	pop    edi
  6f9ebc:	5e                                              	pop    esi
  6f9ebd:	5b                                              	pop    ebx
  6f9ebe:	8b e5                                           	mov    esp,ebp
  6f9ec0:	5d                                              	pop    ebp
  6f9ec1:	c3                                              	ret
  6f9ec2:	8b d3                                           	mov    edx,ebx
  6f9ec4:	dd d8                                           	fstp   st(0)
  6f9ec6:	2b 54 24 0c                                     	sub    edx,DWORD PTR [esp+0xc]
  6f9eca:	83 fa 01                                        	cmp    edx,0x1
  6f9ecd:	76 2b                                           	jbe    0x6f9efa
  6f9ecf:	8b 7c 24 0c                                     	mov    edi,DWORD PTR [esp+0xc]
  6f9ed3:	8d 3c 1f                                        	lea    edi,[edi+ebx*1]
  6f9ed6:	d1 ef                                           	shr    edi,1
  6f9ed8:	57                                              	push   edi
  6f9ed9:	e8 92 fc ff ff                                  	call   0x6f9b70
  6f9ede:	83 c4 04                                        	add    esp,0x4
  6f9ee1:	83 78 08 00                                     	cmp    DWORD PTR [eax+0x8],0x0
  6f9ee5:	75 04                                           	jne    0x6f9eeb
  6f9ee7:	8b df                                           	mov    ebx,edi
  6f9ee9:	eb 04                                           	jmp    0x6f9eef
  6f9eeb:	89 7c 24 0c                                     	mov    DWORD PTR [esp+0xc],edi
  6f9eef:	8b cb                                           	mov    ecx,ebx
  6f9ef1:	2b 4c 24 0c                                     	sub    ecx,DWORD PTR [esp+0xc]
  6f9ef5:	83 f9 01                                        	cmp    ecx,0x1
  6f9ef8:	77 d5                                           	ja     0x6f9ecf
  6f9efa:	8b 44 24 0c                                     	mov    eax,DWORD PTR [esp+0xc]
  6f9efe:	5f                                              	pop    edi
  6f9eff:	5e                                              	pop    esi
  6f9f00:	5b                                              	pop    ebx
  6f9f01:	8b e5                                           	mov    esp,ebp
  6f9f03:	5d                                              	pop    ebp
  6f9f04:	c3                                              	ret

; N20 stack capacity check used by auxresume

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f5170 <.text+0x2f4170>:
  6f5170:	56                                              	push   esi
  6f5171:	8b f1                                           	mov    esi,ecx
  6f5173:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  6f5176:	8b d1                                           	mov    edx,ecx
  6f5178:	2b 56 0c                                        	sub    edx,DWORD PTR [esi+0xc]
  6f517b:	c1 fa 04                                        	sar    edx,0x4
  6f517e:	03 d0                                           	add    edx,eax
  6f5180:	81 fa ff 7f 00 00                               	cmp    edx,0x7fff
  6f5186:	7e 04                                           	jle    0x6f518c
  6f5188:	33 c0                                           	xor    eax,eax
  6f518a:	5e                                              	pop    esi
  6f518b:	c3                                              	ret
  6f518c:	8b 56 1c                                        	mov    edx,DWORD PTR [esi+0x1c]
  6f518f:	57                                              	push   edi
  6f5190:	8b f8                                           	mov    edi,eax
  6f5192:	c1 e7 04                                        	shl    edi,0x4
  6f5195:	2b d1                                           	sub    edx,ecx
  6f5197:	3b d7                                           	cmp    edx,edi
  6f5199:	7f 13                                           	jg     0x6f51ae
  6f519b:	8b 4e 2c                                        	mov    ecx,DWORD PTR [esi+0x2c]
  6f519e:	3b c1                                           	cmp    eax,ecx
  6f51a0:	7f 05                                           	jg     0x6f51a7
  6f51a2:	8d 04 09                                        	lea    eax,[ecx+ecx*1]
  6f51a5:	eb 02                                           	jmp    0x6f51a9
  6f51a7:	03 c1                                           	add    eax,ecx
  6f51a9:	e8 02 8b 00 00                                  	call   0x6fdcb0
  6f51ae:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f51b1:	8b 76 14                                        	mov    esi,DWORD PTR [esi+0x14]
  6f51b4:	03 c7                                           	add    eax,edi
  6f51b6:	5f                                              	pop    edi
  6f51b7:	39 46 08                                        	cmp    DWORD PTR [esi+0x8],eax
  6f51ba:	73 03                                           	jae    0x6f51bf
  6f51bc:	89 46 08                                        	mov    DWORD PTR [esi+0x8],eax
  6f51bf:	b8 01 00 00 00                                  	mov    eax,0x1
  6f51c4:	5e                                              	pop    esi
  6f51c5:	c3                                              	ret
  6f51c6:	cc                                              	int3

; N21 move results and arguments between thread stacks

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f51d0 <.text+0x2f41d0>:
  6f51d0:	55                                              	push   ebp
  6f51d1:	8b ec                                           	mov    ebp,esp
  6f51d3:	51                                              	push   ecx
  6f51d4:	3b fe                                           	cmp    edi,esi
  6f51d6:	74 40                                           	je     0x6f5218
  6f51d8:	8b c8                                           	mov    ecx,eax
  6f51da:	f7 d9                                           	neg    ecx
  6f51dc:	c1 e1 04                                        	shl    ecx,0x4
  6f51df:	01 4f 08                                        	add    DWORD PTR [edi+0x8],ecx
  6f51e2:	85 c0                                           	test   eax,eax
  6f51e4:	7e 32                                           	jle    0x6f5218
  6f51e6:	33 d2                                           	xor    edx,edx
  6f51e8:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  6f51eb:	53                                              	push   ebx
  6f51ec:	8d 64 24 00                                     	lea    esp,[esp+0x0]
  6f51f0:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  6f51f3:	8b 47 08                                        	mov    eax,DWORD PTR [edi+0x8]
  6f51f6:	8d 59 10                                        	lea    ebx,[ecx+0x10]
  6f51f9:	89 5e 08                                        	mov    DWORD PTR [esi+0x8],ebx
  6f51fc:	8b 1c 10                                        	mov    ebx,DWORD PTR [eax+edx*1]
  6f51ff:	89 19                                           	mov    DWORD PTR [ecx],ebx
  6f5201:	8b 5c 10 04                                     	mov    ebx,DWORD PTR [eax+edx*1+0x4]
  6f5205:	89 59 04                                        	mov    DWORD PTR [ecx+0x4],ebx
  6f5208:	8b 44 10 08                                     	mov    eax,DWORD PTR [eax+edx*1+0x8]
  6f520c:	83 c2 10                                        	add    edx,0x10
  6f520f:	ff 4d fc                                        	dec    DWORD PTR [ebp-0x4]
  6f5212:	89 41 08                                        	mov    DWORD PTR [ecx+0x8],eax
  6f5215:	75 d9                                           	jne    0x6f51f0
  6f5217:	5b                                              	pop    ebx
  6f5218:	8b e5                                           	mov    esp,ebp
  6f521a:	5d                                              	pop    ebp
  6f521b:	c3                                              	ret
  6f521c:	cc                                              	int3

; N22 stack insertion places Boolean before results

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f52b0 <.text+0x2f42b0>:
  6f52b0:	8b ce                                           	mov    ecx,esi
  6f52b2:	e8 39 fe ff ff                                  	call   0x6f50f0
  6f52b7:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  6f52ba:	3b c8                                           	cmp    ecx,eax
  6f52bc:	76 1f                                           	jbe    0x6f52dd
  6f52be:	8d 51 f0                                        	lea    edx,[ecx-0x10]
  6f52c1:	57                                              	push   edi
  6f52c2:	8b 3a                                           	mov    edi,DWORD PTR [edx]
  6f52c4:	89 39                                           	mov    DWORD PTR [ecx],edi
  6f52c6:	8b 7a 04                                        	mov    edi,DWORD PTR [edx+0x4]
  6f52c9:	89 79 04                                        	mov    DWORD PTR [ecx+0x4],edi
  6f52cc:	8b 7a 08                                        	mov    edi,DWORD PTR [edx+0x8]
  6f52cf:	89 7a 18                                        	mov    DWORD PTR [edx+0x18],edi
  6f52d2:	83 e9 10                                        	sub    ecx,0x10
  6f52d5:	83 ea 10                                        	sub    edx,0x10
  6f52d8:	3b c8                                           	cmp    ecx,eax
  6f52da:	77 e6                                           	ja     0x6f52c2
  6f52dc:	5f                                              	pop    edi
  6f52dd:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  6f52e0:	8b 11                                           	mov    edx,DWORD PTR [ecx]
  6f52e2:	89 10                                           	mov    DWORD PTR [eax],edx
  6f52e4:	8b 51 04                                        	mov    edx,DWORD PTR [ecx+0x4]
  6f52e7:	89 50 04                                        	mov    DWORD PTR [eax+0x4],edx
  6f52ea:	8b 49 08                                        	mov    ecx,DWORD PTR [ecx+0x8]
  6f52ed:	89 48 08                                        	mov    DWORD PTR [eax+0x8],ecx
  6f52f0:	c3                                              	ret
  6f52f1:	cc                                              	int3

; N23 level-zero stack frame query used for status classification

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f7dd0 <.text+0x2f6dd0>:
  6f7dd0:	8b 42 14                                        	mov    eax,DWORD PTR [edx+0x14]
  6f7dd3:	85 c9                                           	test   ecx,ecx
  6f7dd5:	7e 27                                           	jle    0x6f7dfe
  6f7dd7:	56                                              	push   esi
  6f7dd8:	8b 72 28                                        	mov    esi,DWORD PTR [edx+0x28]
  6f7ddb:	53                                              	push   ebx
  6f7ddc:	8d 64 24 00                                     	lea    esp,[esp+0x0]
  6f7de0:	3b c6                                           	cmp    eax,esi
  6f7de2:	76 16                                           	jbe    0x6f7dfa
  6f7de4:	8b 58 04                                        	mov    ebx,DWORD PTR [eax+0x4]
  6f7de7:	8b 1b                                           	mov    ebx,DWORD PTR [ebx]
  6f7de9:	49                                              	dec    ecx
  6f7dea:	80 7b 06 00                                     	cmp    BYTE PTR [ebx+0x6],0x0
  6f7dee:	75 03                                           	jne    0x6f7df3
  6f7df0:	2b 48 14                                        	sub    ecx,DWORD PTR [eax+0x14]
  6f7df3:	83 e8 18                                        	sub    eax,0x18
  6f7df6:	85 c9                                           	test   ecx,ecx
  6f7df8:	7f e6                                           	jg     0x6f7de0
  6f7dfa:	5b                                              	pop    ebx
  6f7dfb:	5e                                              	pop    esi
  6f7dfc:	85 c9                                           	test   ecx,ecx
  6f7dfe:	75 27                                           	jne    0x6f7e27
  6f7e00:	8b 52 28                                        	mov    edx,DWORD PTR [edx+0x28]
  6f7e03:	3b c2                                           	cmp    eax,edx
  6f7e05:	76 31                                           	jbe    0x6f7e38
  6f7e07:	2b c2                                           	sub    eax,edx
  6f7e09:	8b d0                                           	mov    edx,eax
  6f7e0b:	b8 ab aa aa 2a                                  	mov    eax,0x2aaaaaab
  6f7e10:	f7 ea                                           	imul   edx
  6f7e12:	c1 fa 02                                        	sar    edx,0x2
  6f7e15:	8b c2                                           	mov    eax,edx
  6f7e17:	c1 e8 1f                                        	shr    eax,0x1f
  6f7e1a:	03 c2                                           	add    eax,edx
  6f7e1c:	b9 01 00 00 00                                  	mov    ecx,0x1
  6f7e21:	89 47 60                                        	mov    DWORD PTR [edi+0x60],eax
  6f7e24:	8b c1                                           	mov    eax,ecx
  6f7e26:	c3                                              	ret
  6f7e27:	85 c9                                           	test   ecx,ecx
  6f7e29:	79 0d                                           	jns    0x6f7e38
  6f7e2b:	b8 01 00 00 00                                  	mov    eax,0x1
  6f7e30:	c7 47 60 00 00 00 00                            	mov    DWORD PTR [edi+0x60],0x0
  6f7e37:	c3                                              	ret
  6f7e38:	33 c0                                           	xor    eax,eax
  6f7e3a:	c3                                              	ret
  6f7e3b:	cc                                              	int3

; N24 argument error formats and calls throwing error helper

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f5da0 <.text+0x2f4da0>:
  6f5da0:	55                                              	push   ebp
  6f5da1:	8b ec                                           	mov    ebp,esp
  6f5da3:	83 ec 70                                        	sub    esp,0x70
  6f5da6:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  6f5dab:	33 c5                                           	xor    eax,ebp
  6f5dad:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  6f5db0:	8b 46 14                                        	mov    eax,DWORD PTR [esi+0x14]
  6f5db3:	8b 4e 28                                        	mov    ecx,DWORD PTR [esi+0x28]
  6f5db6:	53                                              	push   ebx
  6f5db7:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  6f5dba:	3b c1                                           	cmp    eax,ecx
  6f5dbc:	76 52                                           	jbe    0x6f5e10
  6f5dbe:	2b c1                                           	sub    eax,ecx
  6f5dc0:	8b c8                                           	mov    ecx,eax
  6f5dc2:	b8 ab aa aa 2a                                  	mov    eax,0x2aaaaaab
  6f5dc7:	f7 e9                                           	imul   ecx
  6f5dc9:	c1 fa 02                                        	sar    edx,0x2
  6f5dcc:	8b c2                                           	mov    eax,edx
  6f5dce:	c1 e8 1f                                        	shr    eax,0x1f
  6f5dd1:	03 c2                                           	add    eax,edx
  6f5dd3:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  6f5dd6:	68 1c 27 c4 00                                  	push   0xc4271c
  6f5ddb:	8d 45 90                                        	lea    eax,[ebp-0x70]
  6f5dde:	8b ce                                           	mov    ecx,esi
  6f5de0:	e8 9b 23 00 00                                  	call   0x6f8180
  6f5de5:	8b 45 98                                        	mov    eax,DWORD PTR [ebp-0x68]
  6f5de8:	83 c4 04                                        	add    esp,0x4
  6f5deb:	b9 20 27 c4 00                                  	mov    ecx,0xc42720
  6f5df0:	8a 10                                           	mov    dl,BYTE PTR [eax]
  6f5df2:	3a 11                                           	cmp    dl,BYTE PTR [ecx]
  6f5df4:	75 39                                           	jne    0x6f5e2f
  6f5df6:	84 d2                                           	test   dl,dl
  6f5df8:	74 12                                           	je     0x6f5e0c
  6f5dfa:	8a 50 01                                        	mov    dl,BYTE PTR [eax+0x1]
  6f5dfd:	3a 51 01                                        	cmp    dl,BYTE PTR [ecx+0x1]
  6f5e00:	75 2d                                           	jne    0x6f5e2f
  6f5e02:	83 c0 02                                        	add    eax,0x2
  6f5e05:	83 c1 02                                        	add    ecx,0x2
  6f5e08:	84 d2                                           	test   dl,dl
  6f5e0a:	75 e4                                           	jne    0x6f5df0
  6f5e0c:	33 c0                                           	xor    eax,eax
  6f5e0e:	eb 24                                           	jmp    0x6f5e34
  6f5e10:	57                                              	push   edi
  6f5e11:	53                                              	push   ebx
  6f5e12:	68 04 27 c4 00                                  	push   0xc42704
  6f5e17:	56                                              	push   esi
  6f5e18:	e8 13 01 00 00                                  	call   0x6f5f30
  6f5e1d:	83 c4 10                                        	add    esp,0x10
  6f5e20:	5b                                              	pop    ebx
  6f5e21:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  6f5e24:	33 cd                                           	xor    ecx,ebp
  6f5e26:	e8 d6 b1 19 00                                  	call   0x891001
  6f5e2b:	8b e5                                           	mov    esp,ebp
  6f5e2d:	5d                                              	pop    ebp
  6f5e2e:	c3                                              	ret
  6f5e2f:	1b c0                                           	sbb    eax,eax
  6f5e31:	83 d8 ff                                        	sbb    eax,0xffffffff
  6f5e34:	85 c0                                           	test   eax,eax
  6f5e36:	75 25                                           	jne    0x6f5e5d
  6f5e38:	4b                                              	dec    ebx
  6f5e39:	75 22                                           	jne    0x6f5e5d
  6f5e3b:	8b 4d 94                                        	mov    ecx,DWORD PTR [ebp-0x6c]
  6f5e3e:	57                                              	push   edi
  6f5e3f:	51                                              	push   ecx
  6f5e40:	68 28 27 c4 00                                  	push   0xc42728
  6f5e45:	56                                              	push   esi
  6f5e46:	e8 e5 00 00 00                                  	call   0x6f5f30
  6f5e4b:	83 c4 10                                        	add    esp,0x10
  6f5e4e:	5b                                              	pop    ebx
  6f5e4f:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  6f5e52:	33 cd                                           	xor    ecx,ebp
  6f5e54:	e8 a8 b1 19 00                                  	call   0x891001
  6f5e59:	8b e5                                           	mov    esp,ebp
  6f5e5b:	5d                                              	pop    ebp
  6f5e5c:	c3                                              	ret
  6f5e5d:	8b 45 94                                        	mov    eax,DWORD PTR [ebp-0x6c]
  6f5e60:	85 c0                                           	test   eax,eax
  6f5e62:	75 08                                           	jne    0x6f5e6c
  6f5e64:	b8 00 27 c4 00                                  	mov    eax,0xc42700
  6f5e69:	89 45 94                                        	mov    DWORD PTR [ebp-0x6c],eax
  6f5e6c:	57                                              	push   edi
  6f5e6d:	50                                              	push   eax
  6f5e6e:	53                                              	push   ebx
  6f5e6f:	68 48 27 c4 00                                  	push   0xc42748
  6f5e74:	56                                              	push   esi
  6f5e75:	e8 b6 00 00 00                                  	call   0x6f5f30
  6f5e7a:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  6f5e7d:	83 c4 14                                        	add    esp,0x14
  6f5e80:	33 cd                                           	xor    ecx,ebp
  6f5e82:	5b                                              	pop    ebx
  6f5e83:	e8 79 b1 19 00                                  	call   0x891001
  6f5e88:	8b e5                                           	mov    esp,ebp
  6f5e8a:	5d                                              	pop    ebp
  6f5e8b:	c3                                              	ret
  6f5e8c:	cc                                              	int3

; N25 error helper raises through 6F8AD0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f5f30 <.text+0x2f4f30>:
  6f5f30:	55                                              	push   ebp
  6f5f31:	8b ec                                           	mov    ebp,esp
  6f5f33:	51                                              	push   ecx
  6f5f34:	56                                              	push   esi
  6f5f35:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  6f5f38:	b9 01 00 00 00                                  	mov    ecx,0x1
  6f5f3d:	e8 4e ff ff ff                                  	call   0x6f5e90
  6f5f42:	8b 46 10                                        	mov    eax,DWORD PTR [esi+0x10]
  6f5f45:	8b 48 44                                        	mov    ecx,DWORD PTR [eax+0x44]
  6f5f48:	3b 48 40                                        	cmp    ecx,DWORD PTR [eax+0x40]
  6f5f4b:	72 07                                           	jb     0x6f5f54
  6f5f4d:	8b c6                                           	mov    eax,esi
  6f5f4f:	e8 4c 54 00 00                                  	call   0x6fb3a0
  6f5f54:	8d 55 10                                        	lea    edx,[ebp+0x10]
  6f5f57:	52                                              	push   edx
  6f5f58:	8b 55 0c                                        	mov    edx,DWORD PTR [ebp+0xc]
  6f5f5b:	8b ce                                           	mov    ecx,esi
  6f5f5d:	e8 fe 18 00 00                                  	call   0x6f7860
  6f5f62:	8b 46 10                                        	mov    eax,DWORD PTR [esi+0x10]
  6f5f65:	8b 48 44                                        	mov    ecx,DWORD PTR [eax+0x44]
  6f5f68:	83 c4 04                                        	add    esp,0x4
  6f5f6b:	3b 48 40                                        	cmp    ecx,DWORD PTR [eax+0x40]
  6f5f6e:	72 07                                           	jb     0x6f5f77
  6f5f70:	8b c6                                           	mov    eax,esi
  6f5f72:	e8 29 54 00 00                                  	call   0x6fb3a0
  6f5f77:	8b 56 08                                        	mov    edx,DWORD PTR [esi+0x8]
  6f5f7a:	2b 56 0c                                        	sub    edx,DWORD PTR [esi+0xc]
  6f5f7d:	c1 fa 04                                        	sar    edx,0x4
  6f5f80:	4a                                              	dec    edx
  6f5f81:	52                                              	push   edx
  6f5f82:	6a 02                                           	push   0x2
  6f5f84:	56                                              	push   esi
  6f5f85:	e8 f6 60 00 00                                  	call   0x6fc080
  6f5f8a:	83 46 08 f0                                     	add    DWORD PTR [esi+0x8],0xfffffff0
  6f5f8e:	83 c4 0c                                        	add    esp,0xc
  6f5f91:	8b c6                                           	mov    eax,esi
  6f5f93:	e8 38 2b 00 00                                  	call   0x6f8ad0
  6f5f98:	33 c0                                           	xor    eax,eax
  6f5f9a:	5e                                              	pop    esi
  6f5f9b:	59                                              	pop    ecx
  6f5f9c:	5d                                              	pop    ebp
  6f5f9d:	c3                                              	ret
  6f5f9e:	cc                                              	int3

; N26 runtime error invokes 6FDB40 with status 2

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f8ad0 <.text+0x2f7ad0>:
  6f8ad0:	56                                              	push   esi
  6f8ad1:	8b f0                                           	mov    esi,eax
  6f8ad3:	8b 46 74                                        	mov    eax,DWORD PTR [esi+0x74]
  6f8ad6:	57                                              	push   edi
  6f8ad7:	85 c0                                           	test   eax,eax
  6f8ad9:	74 71                                           	je     0x6f8b4c
  6f8adb:	8b 7e 20                                        	mov    edi,DWORD PTR [esi+0x20]
  6f8ade:	03 f8                                           	add    edi,eax
  6f8ae0:	83 7f 08 06                                     	cmp    DWORD PTR [edi+0x8],0x6
  6f8ae4:	74 0b                                           	je     0x6f8af1
  6f8ae6:	6a 05                                           	push   0x5
  6f8ae8:	56                                              	push   esi
  6f8ae9:	e8 52 50 00 00                                  	call   0x6fdb40
  6f8aee:	83 c4 08                                        	add    esp,0x8
  6f8af1:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f8af4:	8b 48 f0                                        	mov    ecx,DWORD PTR [eax-0x10]
  6f8af7:	89 08                                           	mov    DWORD PTR [eax],ecx
  6f8af9:	8b 50 f4                                        	mov    edx,DWORD PTR [eax-0xc]
  6f8afc:	89 50 04                                        	mov    DWORD PTR [eax+0x4],edx
  6f8aff:	8b 48 f8                                        	mov    ecx,DWORD PTR [eax-0x8]
  6f8b02:	89 48 08                                        	mov    DWORD PTR [eax+0x8],ecx
  6f8b05:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f8b08:	8b 17                                           	mov    edx,DWORD PTR [edi]
  6f8b0a:	89 50 f0                                        	mov    DWORD PTR [eax-0x10],edx
  6f8b0d:	8b 4f 04                                        	mov    ecx,DWORD PTR [edi+0x4]
  6f8b10:	89 48 f4                                        	mov    DWORD PTR [eax-0xc],ecx
  6f8b13:	8b 57 08                                        	mov    edx,DWORD PTR [edi+0x8]
  6f8b16:	89 50 f8                                        	mov    DWORD PTR [eax-0x8],edx
  6f8b19:	8b 46 1c                                        	mov    eax,DWORD PTR [esi+0x1c]
  6f8b1c:	2b 46 08                                        	sub    eax,DWORD PTR [esi+0x8]
  6f8b1f:	83 f8 10                                        	cmp    eax,0x10
  6f8b22:	7f 12                                           	jg     0x6f8b36
  6f8b24:	8b 46 2c                                        	mov    eax,DWORD PTR [esi+0x2c]
  6f8b27:	83 f8 01                                        	cmp    eax,0x1
  6f8b2a:	7c 04                                           	jl     0x6f8b30
  6f8b2c:	03 c0                                           	add    eax,eax
  6f8b2e:	eb 01                                           	jmp    0x6f8b31
  6f8b30:	40                                              	inc    eax
  6f8b31:	e8 7a 51 00 00                                  	call   0x6fdcb0
  6f8b36:	83 46 08 10                                     	add    DWORD PTR [esi+0x8],0x10
  6f8b3a:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f8b3d:	6a 01                                           	push   0x1
  6f8b3f:	83 c0 e0                                        	add    eax,0xffffffe0
  6f8b42:	50                                              	push   eax
  6f8b43:	56                                              	push   esi
  6f8b44:	e8 07 5a 00 00                                  	call   0x6fe550
  6f8b49:	83 c4 0c                                        	add    esp,0xc
  6f8b4c:	6a 02                                           	push   0x2
  6f8b4e:	56                                              	push   esi
  6f8b4f:	e8 ec 4f 00 00                                  	call   0x6fdb40
  6f8b54:	83 c4 08                                        	add    esp,0x8
  6f8b57:	5f                                              	pop    edi
  6f8b58:	5e                                              	pop    esi
  6f8b59:	c3                                              	ret
  6f8b5a:	cc                                              	int3

; N27 error transfer to saved protected context

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fdb40 <.text+0x2fcb40>:
  6fdb40:	55                                              	push   ebp
  6fdb41:	8b ec                                           	mov    ebp,esp
  6fdb43:	83 e4 f8                                        	and    esp,0xfffffff8
  6fdb46:	51                                              	push   ecx
  6fdb47:	56                                              	push   esi
  6fdb48:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  6fdb4b:	8b 46 70                                        	mov    eax,DWORD PTR [esi+0x70]
  6fdb4e:	85 c0                                           	test   eax,eax
  6fdb50:	74 14                                           	je     0x6fdb66
  6fdb52:	8b 4d 0c                                        	mov    ecx,DWORD PTR [ebp+0xc]
  6fdb55:	89 48 44                                        	mov    DWORD PTR [eax+0x44],ecx
  6fdb58:	8b 56 70                                        	mov    edx,DWORD PTR [esi+0x70]
  6fdb5b:	6a 01                                           	push   0x1
  6fdb5d:	83 c2 04                                        	add    edx,0x4
  6fdb60:	52                                              	push   edx
  6fdb61:	e8 9a b4 19 00                                  	call   0x899000
  6fdb66:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  6fdb69:	8b 4e 10                                        	mov    ecx,DWORD PTR [esi+0x10]
  6fdb6c:	88 46 06                                        	mov    BYTE PTR [esi+0x6],al
  6fdb6f:	83 79 58 00                                     	cmp    DWORD PTR [ecx+0x58],0x0
  6fdb73:	74 17                                           	je     0x6fdb8c
  6fdb75:	50                                              	push   eax
  6fdb76:	8b c6                                           	mov    eax,esi
  6fdb78:	e8 53 ff ff ff                                  	call   0x6fdad0
  6fdb7d:	8b 56 10                                        	mov    edx,DWORD PTR [esi+0x10]
  6fdb80:	8b 42 58                                        	mov    eax,DWORD PTR [edx+0x58]
  6fdb83:	83 c4 04                                        	add    esp,0x4
  6fdb86:	56                                              	push   esi
  6fdb87:	ff d0                                           	call   eax
  6fdb89:	83 c4 04                                        	add    esp,0x4
  6fdb8c:	6a 01                                           	push   0x1
  6fdb8e:	e8 20 5e 19 00                                  	call   0x8939b3
  6fdb93:	cc                                              	int3

; D01 coroutine status string pointers and library registration table
00c0bc58: 0c34c4000034c400f833c400f033c400e833c40080737000e033c400307270000c34c400c074700050eac00070707000d833c400507470008402c100807470000000000000000000

; D02 table library function registration table
00c0b968: 783cc400c0c07000703cc40020b97000643cc40020b770005c3cc400e0bb7000543cc400b0ba70004c3cc40080bd7000c438c400f0be7000443cc400e0bc70003c3cc40040ca70000000000000000000

; D03 table.getn type switch table
0070bcc0: 80bc700060bc700074bc70009cbc70006abc7000

; D04 table.insert type switch table
0070bedc: 1abe700003be700011be70002cbe70000abe7000

; D05 table.remove type switch table
0070c0a8: 93bf700073bf700087bf7000afbf70007dbf7000

; D06 WINMM import descriptor
00d5d9dc: 1ce0950000000000000000001af09500a0257d00

; D07 WINMM original thunk and terminator
00d5e01c: 0cf0950000000000

; D08 timeGetTime hint/name and WINMM name
00d5f00c: 940074696d6547657454696d650057494e4d4d2e646c6c00

; D09 timeGetTime IAT entry
00bd25a0: 0cf09500
