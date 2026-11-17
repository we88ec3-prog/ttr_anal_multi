; saved-491fc7 ESI root: two frame-tail branches and epilogue

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00491fc7 <.text+0x90fc7>:
  491fc7:	e8 64 33 f9 ff                                  	call   0x425330
  491fcc:	8b f0                                           	mov    esi,eax
  491fce:	e8 ad 4b 06 00                                  	call   0x4f6b80
  491fd3:	80 bb 90 00 00 00 00                            	cmp    BYTE PTR [ebx+0x90],0x0
  491fda:	75 08                                           	jne    0x491fe4
  491fdc:	53                                              	push   ebx
  491fdd:	e8 5e 2a 37 00                                  	call   0x804a40
  491fe2:	eb 07                                           	jmp    0x491feb
  491fe4:	8b f3                                           	mov    esi,ebx
  491fe6:	e8 85 2c 37 00                                  	call   0x804c70
  491feb:	53                                              	push   ebx
  491fec:	e8 cf 2f 37 00                                  	call   0x804fc0
  491ff1:	8b 44 24 18                                     	mov    eax,DWORD PTR [esp+0x18]
  491ff5:	8b 8c 24 50 03 00 00                            	mov    ecx,DWORD PTR [esp+0x350]
  491ffc:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  492003:	59                                              	pop    ecx
  492004:	5f                                              	pop    edi
  492005:	5e                                              	pop    esi
  492006:	5b                                              	pop    ebx
  492007:	8b 8c 24 38 03 00 00                            	mov    ecx,DWORD PTR [esp+0x338]
  49200e:	33 cc                                           	xor    ecx,esp
  492010:	e8 ec ef 3f 00                                  	call   0x891001
  492015:	8b e5                                           	mov    esp,ebp
  492017:	5d                                              	pop    ebp
  492018:	c2 04 00                                        	ret    0x4

; saved-49678e EDI root overwritten at 4967BC

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049678e <.text+0x9578e>:
  49678e:	e8 9d eb f8 ff                                  	call   0x425330
  496793:	8b f8                                           	mov    edi,eax
  496795:	83 c4 04                                        	add    esp,0x4
  496798:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  49679b:	e8 80 03 06 00                                  	call   0x4f6b20
  4967a0:	33 d2                                           	xor    edx,edx
  4967a2:	c7 45 cc 07 00 00 00                            	mov    DWORD PTR [ebp-0x34],0x7
  4967a9:	c7 45 c8 00 00 00 00                            	mov    DWORD PTR [ebp-0x38],0x0
  4967b0:	66 89 55 b8                                     	mov    WORD PTR [ebp-0x48],dx
  4967b4:	c6 45 fc 03                                     	mov    BYTE PTR [ebp-0x4],0x3
  4967b8:	8b 5b 02                                        	mov    ebx,DWORD PTR [ebx+0x2]
  4967bb:	4b                                              	dec    ebx
  4967bc:	8d 7a 08                                        	lea    edi,[edx+0x8]

; saved-4d607a EDI root after name-ID lookup to send and cleanup

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d607a <.text+0xd507a>:
  4d607a:	e8 b1 f2 f4 ff                                  	call   0x425330
  4d607f:	8b f8                                           	mov    edi,eax
  4d6081:	e8 9a 0c 02 00                                  	call   0x4f6d20
  4d6086:	84 c0                                           	test   al,al
  4d6088:	0f 84 76 fe ff ff                               	je     0x4d5f04
  4d608e:	e8 cd 8f f3 ff                                  	call   0x40f060
  4d6093:	8b f0                                           	mov    esi,eax
  4d6095:	8b 85 a8 fc ff ff                               	mov    eax,DWORD PTR [ebp-0x358]
  4d609b:	e8 30 9a 00 00                                  	call   0x4dfad0
  4d60a0:	0f b7 40 14                                     	movzx  eax,WORD PTR [eax+0x14]
  4d60a4:	66 85 c0                                        	test   ax,ax
  4d60a7:	0f 84 57 fe ff ff                               	je     0x4d5f04
  4d60ad:	8b f0                                           	mov    esi,eax
  4d60af:	e8 cc e5 f3 ff                                  	call   0x414680
  4d60b4:	56                                              	push   esi
  4d60b5:	e8 86 e1 fc ff                                  	call   0x4a4240
  4d60ba:	8d 8d 24 fd ff ff                               	lea    ecx,[ebp-0x2dc]
  4d60c0:	e8 7b 43 02 00                                  	call   0x4fa440
  4d60c5:	e9 b2 04 00 00                                  	jmp    0x4d657c

; saved-4d5f04 EDI root failed-name branch cleanup

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d5f04 <.text+0xd4f04>:
  4d5f04:	8d 8d 24 fd ff ff                               	lea    ecx,[ebp-0x2dc]
  4d5f0a:	e8 31 45 02 00                                  	call   0x4fa440
  4d5f0f:	e9 68 06 00 00                                  	jmp    0x4d657c

; saved-4d657c EDI restored by caller epilogue

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d657c <.text+0xd557c>:
  4d657c:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4d657f:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4d6586:	59                                              	pop    ecx
  4d6587:	5f                                              	pop    edi
  4d6588:	5e                                              	pop    esi
  4d6589:	5b                                              	pop    ebx
  4d658a:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  4d658d:	33 cd                                           	xor    ecx,ebp
  4d658f:	e8 6d aa 3b 00                                  	call   0x891001
  4d6594:	8b e5                                           	mov    esp,ebp
  4d6596:	5d                                              	pop    ebp
  4d6597:	c2 0c 00                                        	ret    0xc

; saved-53cc2e EDI root overwritten at 53CC5E

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0053cc2e <.text+0x13bc2e>:
  53cc2e:	e8 fd 86 ee ff                                  	call   0x425330
  53cc33:	8b f8                                           	mov    edi,eax
  53cc35:	8d 45 b8                                        	lea    eax,[ebp-0x48]
  53cc38:	e8 e3 9e fb ff                                  	call   0x4f6b20
  53cc3d:	e8 7e 88 ec ff                                  	call   0x4054c0
  53cc42:	53                                              	push   ebx
  53cc43:	53                                              	push   ebx
  53cc44:	83 ec 1c                                        	sub    esp,0x1c
  53cc47:	8b cc                                           	mov    ecx,esp
  53cc49:	89 65 b0                                        	mov    DWORD PTR [ebp-0x50],esp
  53cc4c:	68 fc d1 be 00                                  	push   0xbed1fc
  53cc51:	e8 fa 55 ec ff                                  	call   0x402250
  53cc56:	c6 45 fc 03                                     	mov    BYTE PTR [ebp-0x4],0x3
  53cc5a:	83 7d cc 08                                     	cmp    DWORD PTR [ebp-0x34],0x8
  53cc5e:	8b 7d b8                                        	mov    edi,DWORD PTR [ebp-0x48]
  53cc61:	73 03                                           	jae    0x53cc66
  53cc63:	8d 7d b8                                        	lea    edi,[ebp-0x48]

; tail-804a40 ESI preserved until fixed owner singleton replaces it

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00804a40 <.text+0x403a40>:
  804a40:	55                                              	push   ebp
  804a41:	8b ec                                           	mov    ebp,esp
  804a43:	83 ec 18                                        	sub    esp,0x18
  804a46:	53                                              	push   ebx
  804a47:	8b 1d a0 25 bd 00                               	mov    ebx,DWORD PTR ds:0xbd25a0
  804a4d:	56                                              	push   esi
  804a4e:	57                                              	push   edi
  804a4f:	ff d3                                           	call   ebx
  804a51:	83 3d 58 a8 fb 00 00                            	cmp    DWORD PTR ds:0xfba858,0x0
  804a58:	8b 7d 08                                        	mov    edi,DWORD PTR [ebp+0x8]
  804a5b:	89 47 48                                        	mov    DWORD PTR [edi+0x48],eax
  804a5e:	75 15                                           	jne    0x804a75
  804a60:	83 3d 5c a8 fb 00 00                            	cmp    DWORD PTR ds:0xfba85c,0x0
  804a67:	74 07                                           	je     0x804a70
  804a69:	e8 f2 64 c9 ff                                  	call   0x49af60
  804a6e:	eb 05                                           	jmp    0x804a75
  804a70:	e8 8b 65 c9 ff                                  	call   0x49b000
  804a75:	8b 35 58 a8 fb 00                               	mov    esi,DWORD PTR ds:0xfba858
  804a7b:	89 75 f0                                        	mov    DWORD PTR [ebp-0x10],esi

; tail-804fc0 ESI replaced by owner field before body use

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00804fc0 <.text+0x403fc0>:
  804fc0:	55                                              	push   ebp
  804fc1:	8b ec                                           	mov    ebp,esp
  804fc3:	83 ec 40                                        	sub    esp,0x40
  804fc6:	53                                              	push   ebx
  804fc7:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  804fca:	8b 4b 44                                        	mov    ecx,DWORD PTR [ebx+0x44]
  804fcd:	2b 4b 40                                        	sub    ecx,DWORD PTR [ebx+0x40]
  804fd0:	8b 53 4c                                        	mov    edx,DWORD PTR [ebx+0x4c]
  804fd3:	01 4b 68                                        	add    DWORD PTR [ebx+0x68],ecx
  804fd6:	8b 4b 50                                        	mov    ecx,DWORD PTR [ebx+0x50]
  804fd9:	01 4b 74                                        	add    DWORD PTR [ebx+0x74],ecx
  804fdc:	ff 43 5c                                        	inc    DWORD PTR [ebx+0x5c]
  804fdf:	56                                              	push   esi
  804fe0:	8b 73 3c                                        	mov    esi,DWORD PTR [ebx+0x3c]

; tail-805460 ESI replaced with explicit constructor argument

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00805460 <.text+0x404460>:
  805460:	55                                              	push   ebp
  805461:	8b ec                                           	mov    ebp,esp
  805463:	6a ff                                           	push   0xffffffff
  805465:	68 5e 52 90 00                                  	push   0x90525e
  80546a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  805470:	50                                              	push   eax
  805471:	83 ec 20                                        	sub    esp,0x20
  805474:	53                                              	push   ebx
  805475:	56                                              	push   esi
  805476:	57                                              	push   edi
  805477:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  80547c:	33 c5                                           	xor    eax,ebp
  80547e:	50                                              	push   eax
  80547f:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  805482:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  805488:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  80548b:	33 db                                           	xor    ebx,ebx
  80548d:	89 1e                                           	mov    DWORD PTR [esi],ebx
  80548f:	89 5e 04                                        	mov    DWORD PTR [esi+0x4],ebx
  805492:	89 5e 08                                        	mov    DWORD PTR [esi+0x8],ebx
  805495:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  805498:	8d 7e 10                                        	lea    edi,[esi+0x10]
  80549b:	6a 08                                           	push   0x8
  80549d:	89 1f                                           	mov    DWORD PTR [edi],ebx

; helper-402250 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00402250 <.text+0x1250>:
  402250:	55                                              	push   ebp
  402251:	8b ec                                           	mov    ebp,esp
  402253:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  402256:	56                                              	push   esi
  402257:	8b f1                                           	mov    esi,ecx
  402259:	33 c0                                           	xor    eax,eax
  40225b:	c7 46 14 07 00 00 00                            	mov    DWORD PTR [esi+0x14],0x7
  402262:	c7 46 10 00 00 00 00                            	mov    DWORD PTR [esi+0x10],0x0
  402269:	66 89 06                                        	mov    WORD PTR [esi],ax
  40226c:	8b c2                                           	mov    eax,edx
  40226e:	57                                              	push   edi
  40226f:	8d 78 02                                        	lea    edi,[eax+0x2]
  402272:	66 8b 08                                        	mov    cx,WORD PTR [eax]
  402275:	83 c0 02                                        	add    eax,0x2
  402278:	66 85 c9                                        	test   cx,cx
  40227b:	75 f5                                           	jne    0x402272
  40227d:	2b c7                                           	sub    eax,edi
  40227f:	d1 f8                                           	sar    eax,1
  402281:	50                                              	push   eax
  402282:	52                                              	push   edx
  402283:	8b ce                                           	mov    ecx,esi
  402285:	e8 d6 fe ff ff                                  	call   0x402160
  40228a:	5f                                              	pop    edi
  40228b:	8b c6                                           	mov    eax,esi
  40228d:	5e                                              	pop    esi
  40228e:	5d                                              	pop    ebp
  40228f:	c2 04 00                                        	ret    0x4
  402292:	cc                                              	int3
  402293:	cc                                              	int3
  402294:	cc                                              	int3
  402295:	cc                                              	int3
  402296:	cc                                              	int3
  402297:	cc                                              	int3
  402298:	cc                                              	int3
  402299:	cc                                              	int3
  40229a:	cc                                              	int3
  40229b:	cc                                              	int3
  40229c:	cc                                              	int3
  40229d:	cc                                              	int3
  40229e:	cc                                              	int3
  40229f:	cc                                              	int3

; helper-4054c0 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004054c0 <.text+0x44c0>:
  4054c0:	55                                              	push   ebp
  4054c1:	8b ec                                           	mov    ebp,esp
  4054c3:	6a ff                                           	push   0xffffffff
  4054c5:	68 9e 4d 92 00                                  	push   0x924d9e
  4054ca:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4054d0:	50                                              	push   eax
  4054d1:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4054d6:	33 c5                                           	xor    eax,ebp
  4054d8:	50                                              	push   eax
  4054d9:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4054dc:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4054e2:	b8 01 00 00 00                                  	mov    eax,0x1
  4054e7:	84 05 d4 ad fa 00                               	test   BYTE PTR ds:0xfaadd4,al
  4054ed:	75 1f                                           	jne    0x40550e
  4054ef:	09 05 d4 ad fa 00                               	or     DWORD PTR ds:0xfaadd4,eax
  4054f5:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  4054fc:	e8 7f 1f 18 00                                  	call   0x587480
  405501:	68 c0 cc bc 00                                  	push   0xbcccc0
  405506:	e8 0f ce 48 00                                  	call   0x89231a
  40550b:	83 c4 04                                        	add    esp,0x4
  40550e:	b8 d8 ad fa 00                                  	mov    eax,0xfaadd8
  405513:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  405516:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  40551d:	59                                              	pop    ecx
  40551e:	8b e5                                           	mov    esp,ebp
  405520:	5d                                              	pop    ebp
  405521:	c3                                              	ret
  405522:	cc                                              	int3
  405523:	cc                                              	int3
  405524:	cc                                              	int3
  405525:	cc                                              	int3
  405526:	cc                                              	int3
  405527:	cc                                              	int3
  405528:	cc                                              	int3
  405529:	cc                                              	int3
  40552a:	cc                                              	int3
  40552b:	cc                                              	int3
  40552c:	cc                                              	int3
  40552d:	cc                                              	int3
  40552e:	cc                                              	int3
  40552f:	cc                                              	int3

; helper-40f060 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0040f060 <.text+0xe060>:
  40f060:	55                                              	push   ebp
  40f061:	8b ec                                           	mov    ebp,esp
  40f063:	83 e4 f8                                        	and    esp,0xfffffff8
  40f066:	6a ff                                           	push   0xffffffff
  40f068:	68 ee 61 94 00                                  	push   0x9461ee
  40f06d:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  40f073:	50                                              	push   eax
  40f074:	51                                              	push   ecx
  40f075:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  40f07a:	33 c4                                           	xor    eax,esp
  40f07c:	50                                              	push   eax
  40f07d:	8d 44 24 08                                     	lea    eax,[esp+0x8]
  40f081:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  40f087:	b8 01 00 00 00                                  	mov    eax,0x1
  40f08c:	84 05 2c b2 fa 00                               	test   BYTE PTR ds:0xfab22c,al
  40f092:	75 20                                           	jne    0x40f0b4
  40f094:	09 05 2c b2 fa 00                               	or     DWORD PTR ds:0xfab22c,eax
  40f09a:	c7 44 24 10 00 00 00 00                         	mov    DWORD PTR [esp+0x10],0x0
  40f0a2:	e8 e9 fb 0c 00                                  	call   0x4dec90
  40f0a7:	68 30 ce bc 00                                  	push   0xbcce30
  40f0ac:	e8 69 32 48 00                                  	call   0x89231a
  40f0b1:	83 c4 04                                        	add    esp,0x4
  40f0b4:	b8 30 b1 fa 00                                  	mov    eax,0xfab130
  40f0b9:	8b 4c 24 08                                     	mov    ecx,DWORD PTR [esp+0x8]
  40f0bd:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  40f0c4:	59                                              	pop    ecx
  40f0c5:	8b e5                                           	mov    esp,ebp
  40f0c7:	5d                                              	pop    ebp
  40f0c8:	c3                                              	ret
  40f0c9:	cc                                              	int3
  40f0ca:	cc                                              	int3
  40f0cb:	cc                                              	int3
  40f0cc:	cc                                              	int3
  40f0cd:	cc                                              	int3
  40f0ce:	cc                                              	int3
  40f0cf:	cc                                              	int3

; helper-414680 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00414680 <.text+0x13680>:
  414680:	b8 01 00 00 00                                  	mov    eax,0x1
  414685:	84 05 14 13 fb 00                               	test   BYTE PTR ds:0xfb1314,al
  41468b:	75 13                                           	jne    0x4146a0
  41468d:	09 05 14 13 fb 00                               	or     DWORD PTR ds:0xfb1314,eax
  414693:	68 10 cf bc 00                                  	push   0xbccf10
  414698:	e8 7d dc 47 00                                  	call   0x89231a
  41469d:	83 c4 04                                        	add    esp,0x4
  4146a0:	b8 10 13 fb 00                                  	mov    eax,0xfb1310
  4146a5:	c3                                              	ret
  4146a6:	cc                                              	int3
  4146a7:	cc                                              	int3
  4146a8:	cc                                              	int3
  4146a9:	cc                                              	int3
  4146aa:	cc                                              	int3
  4146ab:	cc                                              	int3
  4146ac:	cc                                              	int3
  4146ad:	cc                                              	int3
  4146ae:	cc                                              	int3
  4146af:	cc                                              	int3

; helper-4a4240 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a4240 <.text+0xa3240>:
  4a4240:	55                                              	push   ebp
  4a4241:	8b ec                                           	mov    ebp,esp
  4a4243:	83 ec 14                                        	sub    esp,0x14
  4a4246:	66 8b 4d 08                                     	mov    cx,WORD PTR [ebp+0x8]
  4a424a:	b8 c6 00 00 00                                  	mov    eax,0xc6
  4a424f:	33 d2                                           	xor    edx,edx
  4a4251:	66 89 45 ec                                     	mov    WORD PTR [ebp-0x14],ax
  4a4255:	b8 01 00 00 00                                  	mov    eax,0x1
  4a425a:	66 89 4d ee                                     	mov    WORD PTR [ebp-0x12],cx
  4a425e:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  4a4261:	66 89 55 f4                                     	mov    WORD PTR [ebp-0xc],dx
  4a4265:	89 45 f6                                        	mov    DWORD PTR [ebp-0xa],eax
  4a4268:	66 c7 45 fa 01 01                               	mov    WORD PTR [ebp-0x6],0x101
  4a426e:	39 15 98 a7 fb 00                               	cmp    DWORD PTR ds:0xfba798,edx
  4a4274:	75 15                                           	jne    0x4a428b
  4a4276:	8b 0d 54 a8 fb 00                               	mov    ecx,DWORD PTR ds:0xfba854
  4a427c:	8b 01                                           	mov    eax,DWORD PTR [ecx]
  4a427e:	8b 40 10                                        	mov    eax,DWORD PTR [eax+0x10]
  4a4281:	6a 10                                           	push   0x10
  4a4283:	8d 55 ec                                        	lea    edx,[ebp-0x14]
  4a4286:	52                                              	push   edx
  4a4287:	6a 00                                           	push   0x0
  4a4289:	ff d0                                           	call   eax
  4a428b:	8b e5                                           	mov    esp,ebp
  4a428d:	5d                                              	pop    ebp
  4a428e:	c2 04 00                                        	ret    0x4
  4a4291:	cc                                              	int3
  4a4292:	cc                                              	int3
  4a4293:	cc                                              	int3
  4a4294:	cc                                              	int3
  4a4295:	cc                                              	int3
  4a4296:	cc                                              	int3
  4a4297:	cc                                              	int3
  4a4298:	cc                                              	int3
  4a4299:	cc                                              	int3
  4a429a:	cc                                              	int3
  4a429b:	cc                                              	int3
  4a429c:	cc                                              	int3
  4a429d:	cc                                              	int3
  4a429e:	cc                                              	int3
  4a429f:	cc                                              	int3

; helper-4dfad0 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dfad0 <.text+0xdead0>:
  4dfad0:	55                                              	push   ebp
  4dfad1:	8b ec                                           	mov    ebp,esp
  4dfad3:	83 ec 08                                        	sub    esp,0x8
  4dfad6:	8d 4d fc                                        	lea    ecx,[ebp-0x4]
  4dfad9:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  4dfadc:	51                                              	push   ecx
  4dfadd:	8d 4e 18                                        	lea    ecx,[esi+0x18]
  4dfae0:	8d 45 f8                                        	lea    eax,[ebp-0x8]
  4dfae3:	e8 d8 3d 36 00                                  	call   0x8438c0
  4dfae8:	8b 45 f8                                        	mov    eax,DWORD PTR [ebp-0x8]
  4dfaeb:	3b 46 1c                                        	cmp    eax,DWORD PTR [esi+0x1c]
  4dfaee:	75 06                                           	jne    0x4dfaf6
  4dfaf0:	33 c0                                           	xor    eax,eax
  4dfaf2:	8b e5                                           	mov    esp,ebp
  4dfaf4:	5d                                              	pop    ebp
  4dfaf5:	c3                                              	ret
  4dfaf6:	8b 40 10                                        	mov    eax,DWORD PTR [eax+0x10]
  4dfaf9:	8b e5                                           	mov    esp,ebp
  4dfafb:	5d                                              	pop    ebp
  4dfafc:	c3                                              	ret
  4dfafd:	cc                                              	int3
  4dfafe:	cc                                              	int3
  4dfaff:	cc                                              	int3

; helper-4fa440 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004fa440 <.text+0xf9440>:
  4fa440:	56                                              	push   esi
  4fa441:	8b f1                                           	mov    esi,ecx
  4fa443:	83 7e 14 08                                     	cmp    DWORD PTR [esi+0x14],0x8
  4fa447:	72 0b                                           	jb     0x4fa454
  4fa449:	8b 06                                           	mov    eax,DWORD PTR [esi]
  4fa44b:	50                                              	push   eax
  4fa44c:	e8 bb 6d 39 00                                  	call   0x89120c
  4fa451:	83 c4 04                                        	add    esp,0x4
  4fa454:	c7 46 14 07 00 00 00                            	mov    DWORD PTR [esi+0x14],0x7
  4fa45b:	c7 46 10 00 00 00 00                            	mov    DWORD PTR [esi+0x10],0x0
  4fa462:	33 c9                                           	xor    ecx,ecx
  4fa464:	66 89 0e                                        	mov    WORD PTR [esi],cx
  4fa467:	5e                                              	pop    esi
  4fa468:	c3                                              	ret
  4fa469:	cc                                              	int3
  4fa46a:	cc                                              	int3
  4fa46b:	cc                                              	int3
  4fa46c:	cc                                              	int3
  4fa46d:	cc                                              	int3
  4fa46e:	cc                                              	int3
  4fa46f:	cc                                              	int3

; helper-49af60 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049af60 <.text+0x99f60>:
  49af60:	55                                              	push   ebp
  49af61:	8b ec                                           	mov    ebp,esp
  49af63:	6a ff                                           	push   0xffffffff
  49af65:	68 d1 0a 91 00                                  	push   0x910ad1
  49af6a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  49af70:	50                                              	push   eax
  49af71:	51                                              	push   ecx
  49af72:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  49af77:	33 c5                                           	xor    eax,ebp
  49af79:	50                                              	push   eax
  49af7a:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  49af7d:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  49af83:	f6 05 00 12 fc 00 01                            	test   BYTE PTR ds:0xfc1200,0x1
  49af8a:	75 25                                           	jne    0x49afb1
  49af8c:	83 0d 00 12 fc 00 01                            	or     DWORD PTR ds:0xfc1200,0x1
  49af93:	68 08 12 fc 00                                  	push   0xfc1208
  49af98:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  49af9f:	e8 bc a4 36 00                                  	call   0x805460
  49afa4:	68 70 e6 bc 00                                  	push   0xbce670
  49afa9:	e8 6c 73 3f 00                                  	call   0x89231a
  49afae:	83 c4 04                                        	add    esp,0x4
  49afb1:	c7 05 58 a8 fb 00 08 12 fc 00                   	mov    DWORD PTR ds:0xfba858,0xfc1208
  49afbb:	c7 45 f0 08 12 fc 00                            	mov    DWORD PTR [ebp-0x10],0xfc1208
  49afc2:	68 08 12 fc 00                                  	push   0xfc1208
  49afc7:	c7 45 fc 01 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x1
  49afce:	e8 8d a4 36 00                                  	call   0x805460
  49afd3:	68 50 af 49 00                                  	push   0x49af50
  49afd8:	e8 3d 73 3f 00                                  	call   0x89231a
  49afdd:	83 c4 04                                        	add    esp,0x4
  49afe0:	c7 05 5c a8 fb 00 00 00 00 00                   	mov    DWORD PTR ds:0xfba85c,0x0
  49afea:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  49afed:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  49aff4:	59                                              	pop    ecx
  49aff5:	8b e5                                           	mov    esp,ebp
  49aff7:	5d                                              	pop    ebp
  49aff8:	c3                                              	ret
  49aff9:	cc                                              	int3
  49affa:	cc                                              	int3
  49affb:	cc                                              	int3
  49affc:	cc                                              	int3
  49affd:	cc                                              	int3
  49affe:	cc                                              	int3
  49afff:	cc                                              	int3

; helper-49b000 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049b000 <.text+0x9a000>:
  49b000:	55                                              	push   ebp
  49b001:	8b ec                                           	mov    ebp,esp
  49b003:	6a ff                                           	push   0xffffffff
  49b005:	68 fe db 90 00                                  	push   0x90dbfe
  49b00a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  49b010:	50                                              	push   eax
  49b011:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  49b016:	33 c5                                           	xor    eax,ebp
  49b018:	50                                              	push   eax
  49b019:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  49b01c:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  49b022:	b8 01 00 00 00                                  	mov    eax,0x1
  49b027:	84 05 00 12 fc 00                               	test   BYTE PTR ds:0xfc1200,al
  49b02d:	75 24                                           	jne    0x49b053
  49b02f:	09 05 00 12 fc 00                               	or     DWORD PTR ds:0xfc1200,eax
  49b035:	68 08 12 fc 00                                  	push   0xfc1208
  49b03a:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  49b041:	e8 1a a4 36 00                                  	call   0x805460
  49b046:	68 70 e6 bc 00                                  	push   0xbce670
  49b04b:	e8 ca 72 3f 00                                  	call   0x89231a
  49b050:	83 c4 04                                        	add    esp,0x4
  49b053:	c7 05 58 a8 fb 00 08 12 fc 00                   	mov    DWORD PTR ds:0xfba858,0xfc1208
  49b05d:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  49b060:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  49b067:	59                                              	pop    ecx
  49b068:	8b e5                                           	mov    esp,ebp
  49b06a:	5d                                              	pop    ebp
  49b06b:	c3                                              	ret
  49b06c:	cc                                              	int3
  49b06d:	cc                                              	int3
  49b06e:	cc                                              	int3
  49b06f:	cc                                              	int3

; helper-4f6b20 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6b20 <.text+0xf5b20>:
  4f6b20:	55                                              	push   ebp
  4f6b21:	8b ec                                           	mov    ebp,esp
  4f6b23:	51                                              	push   ecx
  4f6b24:	56                                              	push   esi
  4f6b25:	8b f0                                           	mov    esi,eax
  4f6b27:	8d 45 08                                        	lea    eax,[ebp+0x8]
  4f6b2a:	50                                              	push   eax
  4f6b2b:	8d 8f 00 01 00 00                               	lea    ecx,[edi+0x100]
  4f6b31:	8d 45 fc                                        	lea    eax,[ebp-0x4]
  4f6b34:	e8 87 cd 34 00                                  	call   0x8438c0
  4f6b39:	8b 45 fc                                        	mov    eax,DWORD PTR [ebp-0x4]
  4f6b3c:	3b 87 04 01 00 00                               	cmp    eax,DWORD PTR [edi+0x104]
  4f6b42:	74 18                                           	je     0x4f6b5c
  4f6b44:	8b 48 10                                        	mov    ecx,DWORD PTR [eax+0x10]
  4f6b47:	6a ff                                           	push   0xffffffff
  4f6b49:	6a 00                                           	push   0x0
  4f6b4b:	51                                              	push   ecx
  4f6b4c:	8b ce                                           	mov    ecx,esi
  4f6b4e:	e8 8d bb f0 ff                                  	call   0x4026e0
  4f6b53:	b0 01                                           	mov    al,0x1
  4f6b55:	5e                                              	pop    esi
  4f6b56:	8b e5                                           	mov    esp,ebp
  4f6b58:	5d                                              	pop    ebp
  4f6b59:	c2 04 00                                        	ret    0x4
  4f6b5c:	83 7e 14 08                                     	cmp    DWORD PTR [esi+0x14],0x8
  4f6b60:	c7 46 10 00 00 00 00                            	mov    DWORD PTR [esi+0x10],0x0
  4f6b67:	72 02                                           	jb     0x4f6b6b
  4f6b69:	8b 36                                           	mov    esi,DWORD PTR [esi]
  4f6b6b:	33 d2                                           	xor    edx,edx
  4f6b6d:	66 89 16                                        	mov    WORD PTR [esi],dx
  4f6b70:	32 c0                                           	xor    al,al
  4f6b72:	5e                                              	pop    esi
  4f6b73:	8b e5                                           	mov    esp,ebp
  4f6b75:	5d                                              	pop    ebp
  4f6b76:	c2 04 00                                        	ret    0x4
  4f6b79:	cc                                              	int3
  4f6b7a:	cc                                              	int3
  4f6b7b:	cc                                              	int3
  4f6b7c:	cc                                              	int3
  4f6b7d:	cc                                              	int3
  4f6b7e:	cc                                              	int3
  4f6b7f:	cc                                              	int3

; helper-4f6d20 Observed helper input and root-independent body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6d20 <.text+0xf5d20>:
  4f6d20:	55                                              	push   ebp
  4f6d21:	8b ec                                           	mov    ebp,esp
  4f6d23:	8b 87 04 01 00 00                               	mov    eax,DWORD PTR [edi+0x104]
  4f6d29:	53                                              	push   ebx
  4f6d2a:	8b 5d 0c                                        	mov    ebx,DWORD PTR [ebp+0xc]
  4f6d2d:	56                                              	push   esi
  4f6d2e:	8b 30                                           	mov    esi,DWORD PTR [eax]
  4f6d30:	3b f0                                           	cmp    esi,eax
  4f6d32:	74 66                                           	je     0x4f6d9a
  4f6d34:	8b 46 10                                        	mov    eax,DWORD PTR [esi+0x10]
  4f6d37:	83 78 14 08                                     	cmp    DWORD PTR [eax+0x14],0x8
  4f6d3b:	72 02                                           	jb     0x4f6d3f
  4f6d3d:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f6d3f:	6a 14                                           	push   0x14
  4f6d41:	53                                              	push   ebx
  4f6d42:	50                                              	push   eax
  4f6d43:	e8 83 d3 39 00                                  	call   0x8940cb
  4f6d48:	83 c4 0c                                        	add    esp,0xc
  4f6d4b:	85 c0                                           	test   eax,eax
  4f6d4d:	74 53                                           	je     0x4f6da2
  4f6d4f:	80 7e 15 00                                     	cmp    BYTE PTR [esi+0x15],0x0
  4f6d53:	75 3d                                           	jne    0x4f6d92
  4f6d55:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  4f6d58:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6d5c:	75 16                                           	jne    0x4f6d74
  4f6d5e:	8b f0                                           	mov    esi,eax
  4f6d60:	8b 06                                           	mov    eax,DWORD PTR [esi]
  4f6d62:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6d66:	75 2a                                           	jne    0x4f6d92
  4f6d68:	8b f0                                           	mov    esi,eax
  4f6d6a:	8b 06                                           	mov    eax,DWORD PTR [esi]
  4f6d6c:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6d70:	74 f6                                           	je     0x4f6d68
  4f6d72:	eb 1e                                           	jmp    0x4f6d92
  4f6d74:	8b 46 04                                        	mov    eax,DWORD PTR [esi+0x4]
  4f6d77:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6d7b:	75 13                                           	jne    0x4f6d90
  4f6d7d:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  4f6d80:	3b 70 08                                        	cmp    esi,DWORD PTR [eax+0x8]
  4f6d83:	75 0b                                           	jne    0x4f6d90
  4f6d85:	8b f0                                           	mov    esi,eax
  4f6d87:	8b 40 04                                        	mov    eax,DWORD PTR [eax+0x4]
  4f6d8a:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6d8e:	74 f0                                           	je     0x4f6d80
  4f6d90:	8b f0                                           	mov    esi,eax
  4f6d92:	3b b7 04 01 00 00                               	cmp    esi,DWORD PTR [edi+0x104]
  4f6d98:	75 9a                                           	jne    0x4f6d34
  4f6d9a:	5e                                              	pop    esi
  4f6d9b:	32 c0                                           	xor    al,al
  4f6d9d:	5b                                              	pop    ebx
  4f6d9e:	5d                                              	pop    ebp
  4f6d9f:	c2 08 00                                        	ret    0x8
  4f6da2:	8b 46 0c                                        	mov    eax,DWORD PTR [esi+0xc]
  4f6da5:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  4f6da8:	5e                                              	pop    esi
  4f6da9:	89 01                                           	mov    DWORD PTR [ecx],eax
  4f6dab:	b0 01                                           	mov    al,0x1
  4f6dad:	5b                                              	pop    ebx
  4f6dae:	5d                                              	pop    ebp
  4f6daf:	c2 08 00                                        	ret    0x8
  4f6db2:	cc                                              	int3
  4f6db3:	cc                                              	int3
  4f6db4:	cc                                              	int3
  4f6db5:	cc                                              	int3
  4f6db6:	cc                                              	int3
  4f6db7:	cc                                              	int3
  4f6db8:	cc                                              	int3
  4f6db9:	cc                                              	int3
  4f6dba:	cc                                              	int3
  4f6dbb:	cc                                              	int3
  4f6dbc:	cc                                              	int3
  4f6dbd:	cc                                              	int3
  4f6dbe:	cc                                              	int3
  4f6dbf:	cc                                              	int3

; root-001 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0042491f <.text+0x2391f>:
  42491f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  424924:	e8 07 21 0d 00                                  	call   0x4f6a30

; root-002 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0042537e <.text+0x2437e>:
  42537e:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  425383:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  425386:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  42538d:	59                                              	pop    ecx
  42538e:	8b e5                                           	mov    esp,ebp
  425390:	5d                                              	pop    ebp
  425391:	c3                                              	ret

; root-003 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0042bb70 <.text+0x2ab70>:
  42bb70:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  42bb75:	e8 b6 ae 0c 00                                  	call   0x4f6a30

; root-004 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0042d233 <.text+0x2c233>:
  42d233:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  42d238:	e8 f3 97 0c 00                                  	call   0x4f6a30

; root-005 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00452e06 <.text+0x51e06>:
  452e06:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  452e0b:	e8 20 3c 0a 00                                  	call   0x4f6a30

; root-006 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00462d42 <.text+0x61d42>:
  462d42:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  462d47:	e8 e4 3c 09 00                                  	call   0x4f6a30

; root-007 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00465ec5 <.text+0x64ec5>:
  465ec5:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  465eca:	e8 61 0b 09 00                                  	call   0x4f6a30

; root-008 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049d937 <.text+0x9c937>:
  49d937:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  49d93c:	89 7d f0                                        	mov    DWORD PTR [ebp-0x10],edi
  49d93f:	e8 2c a1 05 00                                  	call   0x4f7a70

; root-009 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ae7cd <.text+0xad7cd>:
  4ae7cd:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4ae7d2:	e8 99 92 04 00                                  	call   0x4f7a70

; root-010 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004aeae9 <.text+0xadae9>:
  4aeae9:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4aeaee:	89 7c 24 14                                     	mov    DWORD PTR [esp+0x14],edi
  4aeaf2:	e8 79 8f 04 00                                  	call   0x4f7a70

; root-011 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b4152 <.text+0xb3152>:
  4b4152:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  4b4157:	e8 24 2d 04 00                                  	call   0x4f6e80

; root-012 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b4efd <.text+0xb3efd>:
  4b4efd:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4b4f02:	e8 29 1b 04 00                                  	call   0x4f6a30

; root-013 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b560f <.text+0xb460f>:
  4b560f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4b5614:	e8 17 14 04 00                                  	call   0x4f6a30

; root-014 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bad73 <.text+0xb9d73>:
  4bad73:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  4bad78:	e8 03 c1 03 00                                  	call   0x4f6e80

; root-015 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bf12e <.text+0xbe12e>:
  4bf12e:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bf133:	e8 f8 78 03 00                                  	call   0x4f6a30

; root-016 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bf350 <.text+0xbe350>:
  4bf350:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bf355:	e8 d6 76 03 00                                  	call   0x4f6a30

; root-017 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bf5c4 <.text+0xbe5c4>:
  4bf5c4:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bf5c9:	e8 62 74 03 00                                  	call   0x4f6a30

; root-018 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bf5d4 <.text+0xbe5d4>:
  4bf5d4:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bf5d9:	e8 52 74 03 00                                  	call   0x4f6a30

; root-019 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bfa9c <.text+0xbea9c>:
  4bfa9c:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bfaa1:	e8 8a 6f 03 00                                  	call   0x4f6a30

; root-020 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bfaab <.text+0xbeaab>:
  4bfaab:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bfab0:	e8 7b 6f 03 00                                  	call   0x4f6a30

; root-021 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bfab8 <.text+0xbeab8>:
  4bfab8:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bfabd:	e8 6e 6f 03 00                                  	call   0x4f6a30

; root-022 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bfca5 <.text+0xbeca5>:
  4bfca5:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bfcaa:	e8 81 6d 03 00                                  	call   0x4f6a30

; root-023 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bfcb5 <.text+0xbecb5>:
  4bfcb5:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4bfcba:	e8 71 6d 03 00                                  	call   0x4f6a30

; root-024 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c5f2f <.text+0xc4f2f>:
  4c5f2f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4c5f34:	e8 f7 0a 03 00                                  	call   0x4f6a30

; root-025 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d0155 <.text+0xcf155>:
  4d0155:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4d015a:	89 45 d0                                        	mov    DWORD PTR [ebp-0x30],eax
  4d015d:	e8 0e 79 02 00                                  	call   0x4f7a70

; root-026 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d15ec <.text+0xd05ec>:
  4d15ec:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4d15f1:	89 45 d4                                        	mov    DWORD PTR [ebp-0x2c],eax
  4d15f4:	e8 77 64 02 00                                  	call   0x4f7a70

; root-027 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d1a9d <.text+0xd0a9d>:
  4d1a9d:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4d1aa2:	e8 c9 5f 02 00                                  	call   0x4f7a70

; root-028 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d2b4f <.text+0xd1b4f>:
  4d2b4f:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4d2b54:	e8 17 4f 02 00                                  	call   0x4f7a70

; root-029 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d7984 <.text+0xd6984>:
  4d7984:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4d7989:	e8 a2 f0 01 00                                  	call   0x4f6a30

; root-030 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ddcd6 <.text+0xdccd6>:
  4ddcd6:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4ddcdb:	e8 50 8d 01 00                                  	call   0x4f6a30

; root-031 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004df5e5 <.text+0xde5e5>:
  4df5e5:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  4df5ea:	e8 91 78 01 00                                  	call   0x4f6e80

; root-032 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004df696 <.text+0xde696>:
  4df696:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  4df69b:	e8 e0 77 01 00                                  	call   0x4f6e80

; root-033 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e2835 <.text+0xe1835>:
  4e2835:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e283a:	e8 11 41 01 00                                  	call   0x4f6950

; root-034 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e37da <.text+0xe27da>:
  4e37da:	68 70 74 fb 00                                  	push   0xfb7470
  4e37df:	e8 9c 3a 01 00                                  	call   0x4f7280

; root-035 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e8bc7 <.text+0xe7bc7>:
  4e8bc7:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e8bcc:	e8 7f dd 00 00                                  	call   0x4f6950

; root-036 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e8c08 <.text+0xe7c08>:
  4e8c08:	68 70 74 fb 00                                  	push   0xfb7470
  4e8c0d:	e8 6e e6 00 00                                  	call   0x4f7280

; root-037 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e8d7e <.text+0xe7d7e>:
  4e8d7e:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e8d83:	e8 c8 db 00 00                                  	call   0x4f6950

; root-038 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e8f12 <.text+0xe7f12>:
  4e8f12:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e8f17:	e8 14 db 00 00                                  	call   0x4f6a30

; root-039 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e8ff7 <.text+0xe7ff7>:
  4e8ff7:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e8ffc:	e8 4f d9 00 00                                  	call   0x4f6950

; root-040 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e911f <.text+0xe811f>:
  4e911f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e9124:	e8 07 d9 00 00                                  	call   0x4f6a30

; root-041 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e9441 <.text+0xe8441>:
  4e9441:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e9446:	e8 05 d5 00 00                                  	call   0x4f6950

; root-042 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e95b1 <.text+0xe85b1>:
  4e95b1:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e95b6:	e8 75 d4 00 00                                  	call   0x4f6a30

; root-043 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e973b <.text+0xe873b>:
  4e973b:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e9740:	e8 eb d2 00 00                                  	call   0x4f6a30

; root-044 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004e9ba9 <.text+0xe8ba9>:
  4e9ba9:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4e9bae:	e8 7d ce 00 00                                  	call   0x4f6a30

; root-045 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ea148 <.text+0xe9148>:
  4ea148:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4ea14d:	e8 1e d2 00 00                                  	call   0x4f7370

; root-046 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ea25e <.text+0xe925e>:
  4ea25e:	68 70 74 fb 00                                  	push   0xfb7470
  4ea263:	e8 18 d0 00 00                                  	call   0x4f7280

; root-047 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ea574 <.text+0xe9574>:
  4ea574:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4ea579:	e8 b2 c4 00 00                                  	call   0x4f6a30

; root-048 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ea587 <.text+0xe9587>:
  4ea587:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4ea58c:	e8 9f c4 00 00                                  	call   0x4f6a30

; root-049 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004eaf2b <.text+0xe9f2b>:
  4eaf2b:	68 70 74 fb 00                                  	push   0xfb7470
  4eaf30:	e8 4b c3 00 00                                  	call   0x4f7280

; root-050 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004eb5b2 <.text+0xea5b2>:
  4eb5b2:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4eb5b7:	e8 74 b4 00 00                                  	call   0x4f6a30

; root-051 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f1627 <.text+0xf0627>:
  4f1627:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f162c:	e8 1f 53 00 00                                  	call   0x4f6950

; root-052 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f1672 <.text+0xf0672>:
  4f1672:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f1677:	e8 b4 53 00 00                                  	call   0x4f6a30

; root-053 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f1cd2 <.text+0xf0cd2>:
  4f1cd2:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f1cd7:	e8 74 4c 00 00                                  	call   0x4f6950

; root-054 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f1d22 <.text+0xf0d22>:
  4f1d22:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f1d27:	e8 04 4d 00 00                                  	call   0x4f6a30

; root-055 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f2197 <.text+0xf1197>:
  4f2197:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f219c:	e8 af 47 00 00                                  	call   0x4f6950

; root-056 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f21e9 <.text+0xf11e9>:
  4f21e9:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f21ee:	e8 3d 48 00 00                                  	call   0x4f6a30

; root-057 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f22c9 <.text+0xf12c9>:
  4f22c9:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f22ce:	e8 5d 47 00 00                                  	call   0x4f6a30

; root-058 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f2e4e <.text+0xf1e4e>:
  4f2e4e:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f2e53:	e8 68 3f 00 00                                  	call   0x4f6dc0

; root-059 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f3db0 <.text+0xf2db0>:
  4f3db0:	c7 45 e8 70 74 fb 00                            	mov    DWORD PTR [ebp-0x18],0xfb7470
  4f3db7:	89 35 78 74 fb 00                               	mov    DWORD PTR ds:0xfb7478,esi
  4f3dbd:	e8 0e c7 34 00                                  	call   0x8404d0

; root-060 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f429b <.text+0xf329b>:
  4f429b:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  4f42a0:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4f42a3:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4f42aa:	59                                              	pop    ecx
  4f42ab:	5e                                              	pop    esi
  4f42ac:	5b                                              	pop    ebx
  4f42ad:	8b e5                                           	mov    esp,ebp
  4f42af:	5d                                              	pop    ebp
  4f42b0:	c3                                              	ret

; root-061 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f44d8 <.text+0xf34d8>:
  4f44d8:	c7 45 f0 70 74 fb 00                            	mov    DWORD PTR [ebp-0x10],0xfb7470
  4f44df:	33 db                                           	xor    ebx,ebx
  4f44e1:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  4f44e4:	8b 0d 74 75 fb 00                               	mov    ecx,DWORD PTR ds:0xfb7574
  4f44ea:	8b 31                                           	mov    esi,DWORD PTR [ecx]
  4f44ec:	3b f1                                           	cmp    esi,ecx
  4f44ee:	74 78                                           	je     0x4f4568
  4f44f0:	8b 7e 10                                        	mov    edi,DWORD PTR [esi+0x10]
  4f44f3:	3b fb                                           	cmp    edi,ebx
  4f44f5:	74 2f                                           	je     0x4f4526
  4f44f7:	83 7f 14 08                                     	cmp    DWORD PTR [edi+0x14],0x8
  4f44fb:	72 0b                                           	jb     0x4f4508
  4f44fd:	8b 07                                           	mov    eax,DWORD PTR [edi]
  4f44ff:	50                                              	push   eax
  4f4500:	e8 07 cd 39 00                                  	call   0x89120c

; root-062 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f508a <.text+0xf408a>:
  4f508a:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4f508f:	e8 dc 29 00 00                                  	call   0x4f7a70

; root-063 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f5518 <.text+0xf4518>:
  4f5518:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4f551d:	e8 4e 25 00 00                                  	call   0x4f7a70

; root-064 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f840d <.text+0xf740d>:
  4f840d:	68 70 74 fb 00                                  	push   0xfb7470
  4f8412:	8b ce                                           	mov    ecx,esi
  4f8414:	c6 46 74 00                                     	mov    BYTE PTR [esi+0x74],0x0
  4f8418:	e8 43 07 00 00                                  	call   0x4f8b60

; root-065 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f8446 <.text+0xf7446>:
  4f8446:	68 70 74 fb 00                                  	push   0xfb7470
  4f844b:	c6 41 74 00                                     	mov    BYTE PTR [ecx+0x74],0x0
  4f844f:	e8 6c 07 00 00                                  	call   0x4f8bc0

; root-066 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f8463 <.text+0xf7463>:
  4f8463:	68 70 74 fb 00                                  	push   0xfb7470
  4f8468:	8b ce                                           	mov    ecx,esi
  4f846a:	88 58 74                                        	mov    BYTE PTR [eax+0x74],bl
  4f846d:	e8 ee 06 00 00                                  	call   0x4f8b60

; root-067 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f8480 <.text+0xf7480>:
  4f8480:	68 70 74 fb 00                                  	push   0xfb7470
  4f8485:	8b ce                                           	mov    ecx,esi
  4f8487:	c6 46 74 00                                     	mov    BYTE PTR [esi+0x74],0x0
  4f848b:	e8 30 07 00 00                                  	call   0x4f8bc0

; root-068 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f84ce <.text+0xf74ce>:
  4f84ce:	68 70 74 fb 00                                  	push   0xfb7470
  4f84d3:	c6 41 74 00                                     	mov    BYTE PTR [ecx+0x74],0x0
  4f84d7:	e8 84 06 00 00                                  	call   0x4f8b60

; root-069 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f84e9 <.text+0xf74e9>:
  4f84e9:	68 70 74 fb 00                                  	push   0xfb7470
  4f84ee:	8b ce                                           	mov    ecx,esi
  4f84f0:	88 58 74                                        	mov    BYTE PTR [eax+0x74],bl
  4f84f3:	e8 c8 06 00 00                                  	call   0x4f8bc0

; root-070 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f8549 <.text+0xf7549>:
  4f8549:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  4f854e:	e8 6d 05 00 00                                  	call   0x4f8ac0

; root-071 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0050875d <.text+0x10775d>:
  50875d:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  508762:	e8 c9 e2 fe ff                                  	call   0x4f6a30

; root-072 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00508905 <.text+0x107905>:
  508905:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  50890a:	e8 21 e1 fe ff                                  	call   0x4f6a30

; root-073 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00534de6 <.text+0x133de6>:
  534de6:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  534deb:	e8 40 1c fc ff                                  	call   0x4f6a30

; root-074 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005353a7 <.text+0x1343a7>:
  5353a7:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  5353ac:	e8 9f 15 fc ff                                  	call   0x4f6950

; root-075 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00539bee <.text+0x138bee>:
  539bee:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  539bf3:	e8 38 ce fb ff                                  	call   0x4f6a30

; root-076 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0053a3c9 <.text+0x1393c9>:
  53a3c9:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  53a3ce:	e8 7d c5 fb ff                                  	call   0x4f6950

; root-077 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0053adce <.text+0x139dce>:
  53adce:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  53add3:	e8 58 bc fb ff                                  	call   0x4f6a30

; root-078 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0053b1c5 <.text+0x13a1c5>:
  53b1c5:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  53b1ca:	e8 61 b8 fb ff                                  	call   0x4f6a30

; root-079 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0053b3bb <.text+0x13a3bb>:
  53b3bb:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  53b3c0:	e8 6b b6 fb ff                                  	call   0x4f6a30

; root-080 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0053b3c8 <.text+0x13a3c8>:
  53b3c8:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  53b3cd:	e8 5e b6 fb ff                                  	call   0x4f6a30

; root-081 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0053b566 <.text+0x13a566>:
  53b566:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  53b56b:	e8 c0 b4 fb ff                                  	call   0x4f6a30

; root-082 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0053c60c <.text+0x13b60c>:
  53c60c:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  53c611:	e8 1a a4 fb ff                                  	call   0x4f6a30

; root-083 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055205a <.text+0x15105a>:
  55205a:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  55205f:	89 75 c4                                        	mov    DWORD PTR [ebp-0x3c],esi
  552062:	e8 09 5a fa ff                                  	call   0x4f7a70

; root-084 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055228c <.text+0x15128c>:
  55228c:	be 70 74 fb 00                                  	mov    esi,0xfb7470
  552291:	e8 da 4c fa ff                                  	call   0x4f6f70

; root-085 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00563008 <.text+0x162008>:
  563008:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  56300d:	89 74 24 1c                                     	mov    DWORD PTR [esp+0x1c],esi
  563011:	e8 5a 4a f9 ff                                  	call   0x4f7a70

; root-086 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00564049 <.text+0x163049>:
  564049:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  56404e:	e8 2d 2e f9 ff                                  	call   0x4f6e80

; root-087 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00564108 <.text+0x163108>:
  564108:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  56410d:	e8 6e 2d f9 ff                                  	call   0x4f6e80

; root-088 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0056d021 <.text+0x16c021>:
  56d021:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  56d026:	e8 45 aa f8 ff                                  	call   0x4f7a70

; root-089 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0056d3f9 <.text+0x16c3f9>:
  56d3f9:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  56d3fe:	89 44 24 14                                     	mov    DWORD PTR [esp+0x14],eax
  56d402:	e8 69 a6 f8 ff                                  	call   0x4f7a70

; root-090 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005a4014 <.text+0x1a3014>:
  5a4014:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  5a4019:	e8 12 2a f5 ff                                  	call   0x4f6a30

; root-091 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005a412e <.text+0x1a312e>:
  5a412e:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  5a4133:	e8 f8 28 f5 ff                                  	call   0x4f6a30

; root-092 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005a4225 <.text+0x1a3225>:
  5a4225:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  5a422a:	e8 01 28 f5 ff                                  	call   0x4f6a30

; root-093 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005b41b2 <.text+0x1b31b2>:
  5b41b2:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  5b41b7:	e8 74 28 f4 ff                                  	call   0x4f6a30

; root-094 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005b9a9f <.text+0x1b8a9f>:
  5b9a9f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  5b9aa4:	e8 87 cf f3 ff                                  	call   0x4f6a30

; root-095 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005b9d03 <.text+0x1b8d03>:
  5b9d03:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  5b9d08:	e8 23 cd f3 ff                                  	call   0x4f6a30

; root-096 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0060533f <.text+0x20433f>:
  60533f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  605344:	e8 e7 16 ef ff                                  	call   0x4f6a30

; root-097 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006053cf <.text+0x2043cf>:
  6053cf:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6053d4:	e8 57 16 ef ff                                  	call   0x4f6a30

; root-098 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00605e04 <.text+0x204e04>:
  605e04:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  605e09:	e8 22 0c ef ff                                  	call   0x4f6a30

; root-099 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00631559 <.text+0x230559>:
  631559:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  63155e:	89 74 24 10                                     	mov    DWORD PTR [esp+0x10],esi
  631562:	e8 09 65 ec ff                                  	call   0x4f7a70

; root-100 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00631676 <.text+0x230676>:
  631676:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  63167b:	89 74 24 10                                     	mov    DWORD PTR [esp+0x10],esi
  63167f:	e8 ec 63 ec ff                                  	call   0x4f7a70

; root-101 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00632566 <.text+0x231566>:
  632566:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  63256b:	89 44 24 14                                     	mov    DWORD PTR [esp+0x14],eax
  63256f:	e8 fc 54 ec ff                                  	call   0x4f7a70

; root-102 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0063285c <.text+0x23185c>:
  63285c:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  632861:	89 74 24 14                                     	mov    DWORD PTR [esp+0x14],esi
  632865:	e8 06 52 ec ff                                  	call   0x4f7a70

; root-103 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006346b5 <.text+0x2336b5>:
  6346b5:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  6346ba:	89 74 24 14                                     	mov    DWORD PTR [esp+0x14],esi
  6346be:	e8 ad 33 ec ff                                  	call   0x4f7a70

; root-104 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00634aed <.text+0x233aed>:
  634aed:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  634af2:	89 74 24 14                                     	mov    DWORD PTR [esp+0x14],esi
  634af6:	e8 75 2f ec ff                                  	call   0x4f7a70

; root-105 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00634c2c <.text+0x233c2c>:
  634c2c:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  634c31:	89 74 24 14                                     	mov    DWORD PTR [esp+0x14],esi
  634c35:	e8 36 2e ec ff                                  	call   0x4f7a70

; root-106 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00656909 <.text+0x255909>:
  656909:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  65690e:	e8 1d 01 ea ff                                  	call   0x4f6a30

; root-107 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0065fba1 <.text+0x25eba1>:
  65fba1:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  65fba6:	e8 c5 77 e9 ff                                  	call   0x4f7370

; root-108 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00663a41 <.text+0x262a41>:
  663a41:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  663a46:	e8 e5 2f e9 ff                                  	call   0x4f6a30

; root-109 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00663add <.text+0x262add>:
  663add:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  663ae2:	e8 89 38 e9 ff                                  	call   0x4f7370

; root-110 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0066b18d <.text+0x26a18d>:
  66b18d:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  66b192:	e8 99 b8 e8 ff                                  	call   0x4f6a30

; root-111 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0066fea2 <.text+0x26eea2>:
  66fea2:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  66fea7:	e8 84 6b e8 ff                                  	call   0x4f6a30

; root-112 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0068c687 <.text+0x28b687>:
  68c687:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  68c68c:	e8 9f a3 e6 ff                                  	call   0x4f6a30

; root-113 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0068eb49 <.text+0x28db49>:
  68eb49:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  68eb4e:	e8 dd 7e e6 ff                                  	call   0x4f6a30

; root-114 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00694170 <.text+0x293170>:
  694170:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  694175:	e8 b6 28 e6 ff                                  	call   0x4f6a30

; root-115 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00694816 <.text+0x293816>:
  694816:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  69481b:	e8 10 22 e6 ff                                  	call   0x4f6a30

; root-116 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006951c5 <.text+0x2941c5>:
  6951c5:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6951ca:	e8 61 18 e6 ff                                  	call   0x4f6a30

; root-117 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006a5149 <.text+0x2a4149>:
  6a5149:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6a514e:	e8 1d 22 e5 ff                                  	call   0x4f7370

; root-118 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006a5165 <.text+0x2a4165>:
  6a5165:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6a516a:	e8 c1 18 e5 ff                                  	call   0x4f6a30

; root-119 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006a6076 <.text+0x2a5076>:
  6a6076:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6a607b:	e8 b0 09 e5 ff                                  	call   0x4f6a30

; root-120 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006a6c38 <.text+0x2a5c38>:
  6a6c38:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6a6c3d:	e8 ee fd e4 ff                                  	call   0x4f6a30

; root-121 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006a723e <.text+0x2a623e>:
  6a723e:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6a7243:	e8 28 01 e5 ff                                  	call   0x4f7370

; root-122 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006a72c1 <.text+0x2a62c1>:
  6a72c1:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6a72c6:	e8 65 f7 e4 ff                                  	call   0x4f6a30

; root-123 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006a7e03 <.text+0x2a6e03>:
  6a7e03:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6a7e08:	e8 23 ec e4 ff                                  	call   0x4f6a30

; root-124 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006a9cfb <.text+0x2a8cfb>:
  6a9cfb:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6a9d00:	e8 2b cd e4 ff                                  	call   0x4f6a30

; root-125 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006aee15 <.text+0x2ade15>:
  6aee15:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6aee1a:	e8 11 7c e4 ff                                  	call   0x4f6a30

; root-126 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006af097 <.text+0x2ae097>:
  6af097:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6af09c:	e8 8f 79 e4 ff                                  	call   0x4f6a30

; root-127 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006af60f <.text+0x2ae60f>:
  6af60f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6af614:	e8 17 74 e4 ff                                  	call   0x4f6a30

; root-128 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006b626f <.text+0x2b526f>:
  6b626f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6b6274:	e8 b7 07 e4 ff                                  	call   0x4f6a30

; root-129 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c15ed <.text+0x2c05ed>:
  6c15ed:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c15f2:	e8 39 54 e3 ff                                  	call   0x4f6a30

; root-130 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c3343 <.text+0x2c2343>:
  6c3343:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c3348:	e8 e3 36 e3 ff                                  	call   0x4f6a30

; root-131 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c34d3 <.text+0x2c24d3>:
  6c34d3:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c34d8:	e8 53 35 e3 ff                                  	call   0x4f6a30

; root-132 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c36e4 <.text+0x2c26e4>:
  6c36e4:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c36e9:	e8 42 33 e3 ff                                  	call   0x4f6a30

; root-133 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c3873 <.text+0x2c2873>:
  6c3873:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c3878:	e8 b3 31 e3 ff                                  	call   0x4f6a30

; root-134 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c3a03 <.text+0x2c2a03>:
  6c3a03:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c3a08:	e8 23 30 e3 ff                                  	call   0x4f6a30

; root-135 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c405f <.text+0x2c305f>:
  6c405f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c4064:	e8 c7 29 e3 ff                                  	call   0x4f6a30

; root-136 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c41f3 <.text+0x2c31f3>:
  6c41f3:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c41f8:	e8 33 28 e3 ff                                  	call   0x4f6a30

; root-137 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c4383 <.text+0x2c3383>:
  6c4383:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c4388:	e8 a3 26 e3 ff                                  	call   0x4f6a30

; root-138 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c4513 <.text+0x2c3513>:
  6c4513:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c4518:	e8 13 25 e3 ff                                  	call   0x4f6a30

; root-139 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c46a3 <.text+0x2c36a3>:
  6c46a3:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c46a8:	e8 83 23 e3 ff                                  	call   0x4f6a30

; root-140 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c4833 <.text+0x2c3833>:
  6c4833:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c4838:	e8 f3 21 e3 ff                                  	call   0x4f6a30

; root-141 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c49c3 <.text+0x2c39c3>:
  6c49c3:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c49c8:	e8 63 20 e3 ff                                  	call   0x4f6a30

; root-142 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c4b53 <.text+0x2c3b53>:
  6c4b53:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c4b58:	e8 d3 1e e3 ff                                  	call   0x4f6a30

; root-143 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c4ce3 <.text+0x2c3ce3>:
  6c4ce3:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c4ce8:	e8 43 1d e3 ff                                  	call   0x4f6a30

; root-144 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c4db0 <.text+0x2c3db0>:
  6c4db0:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c4db5:	e8 76 1c e3 ff                                  	call   0x4f6a30

; root-145 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c4f23 <.text+0x2c3f23>:
  6c4f23:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c4f28:	e8 03 1b e3 ff                                  	call   0x4f6a30

; root-146 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c50b3 <.text+0x2c40b3>:
  6c50b3:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c50b8:	e8 73 19 e3 ff                                  	call   0x4f6a30

; root-147 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c5243 <.text+0x2c4243>:
  6c5243:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c5248:	e8 e3 17 e3 ff                                  	call   0x4f6a30

; root-148 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c52f1 <.text+0x2c42f1>:
  6c52f1:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c52f6:	e8 35 17 e3 ff                                  	call   0x4f6a30

; root-149 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c5a57 <.text+0x2c4a57>:
  6c5a57:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c5a5c:	e8 cf 0f e3 ff                                  	call   0x4f6a30

; root-150 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c5f4f <.text+0x2c4f4f>:
  6c5f4f:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c5f54:	e8 d7 0a e3 ff                                  	call   0x4f6a30

; root-151 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006c693e <.text+0x2c593e>:
  6c693e:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6c6943:	e8 e8 00 e3 ff                                  	call   0x4f6a30

; root-152 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006caf2b <.text+0x2c9f2b>:
  6caf2b:	b8 70 74 fb 00                                  	mov    eax,0xfb7470
  6caf30:	e8 fb ba e2 ff                                  	call   0x4f6a30

; root-153 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006d951d <.text+0x2d851d>:
  6d951d:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  6d9522:	e8 59 d9 e1 ff                                  	call   0x4f6e80

; root-154 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006d9616 <.text+0x2d8616>:
  6d9616:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  6d961b:	e8 60 d8 e1 ff                                  	call   0x4f6e80

; root-155 Exact FB7470 literal to first transfer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006dc0df <.text+0x2db0df>:
  6dc0df:	b9 70 74 fb 00                                  	mov    ecx,0xfb7470
  6dc0e4:	89 45 0c                                        	mov    DWORD PTR [ebp+0xc],eax
  6dc0e7:	e8 84 b9 e1 ff                                  	call   0x4f7a70

; root-helper-4f6950 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6950 <.text+0xf5950>:
  4f6950:	55                                              	push   ebp
  4f6951:	8b ec                                           	mov    ebp,esp
  4f6953:	83 ec 0c                                        	sub    esp,0xc
  4f6956:	53                                              	push   ebx
  4f6957:	8b 5d 0c                                        	mov    ebx,DWORD PTR [ebp+0xc]
  4f695a:	56                                              	push   esi
  4f695b:	57                                              	push   edi
  4f695c:	8b f8                                           	mov    edi,eax
  4f695e:	8d 45 08                                        	lea    eax,[ebp+0x8]
  4f6961:	8d b7 00 01 00 00                               	lea    esi,[edi+0x100]
  4f6967:	50                                              	push   eax
  4f6968:	8d 45 0c                                        	lea    eax,[ebp+0xc]
  4f696b:	8b ce                                           	mov    ecx,esi
  4f696d:	e8 4e cf 34 00                                  	call   0x8438c0
  4f6972:	8b 4d 0c                                        	mov    ecx,DWORD PTR [ebp+0xc]
  4f6975:	3b 8f 04 01 00 00                               	cmp    ecx,DWORD PTR [edi+0x104]
  4f697b:	74 48                                           	je     0x4f69c5
  4f697d:	8b c3                                           	mov    eax,ebx
  4f697f:	8d 50 02                                        	lea    edx,[eax+0x2]
  4f6982:	66 8b 08                                        	mov    cx,WORD PTR [eax]
  4f6985:	83 c0 02                                        	add    eax,0x2
  4f6988:	66 85 c9                                        	test   cx,cx
  4f698b:	75 f5                                           	jne    0x4f6982
  4f698d:	2b c2                                           	sub    eax,edx
  4f698f:	d1 f8                                           	sar    eax,1
  4f6991:	0f 84 8c 00 00 00                               	je     0x4f6a23
  4f6997:	8b c3                                           	mov    eax,ebx
  4f6999:	8d 50 02                                        	lea    edx,[eax+0x2]
  4f699c:	8d 64 24 00                                     	lea    esp,[esp+0x0]
  4f69a0:	66 8b 08                                        	mov    cx,WORD PTR [eax]
  4f69a3:	83 c0 02                                        	add    eax,0x2
  4f69a6:	66 85 c9                                        	test   cx,cx
  4f69a9:	75 f5                                           	jne    0x4f69a0
  4f69ab:	2b c2                                           	sub    eax,edx
  4f69ad:	8b 55 0c                                        	mov    edx,DWORD PTR [ebp+0xc]
  4f69b0:	8b 4a 10                                        	mov    ecx,DWORD PTR [edx+0x10]
  4f69b3:	d1 f8                                           	sar    eax,1
  4f69b5:	50                                              	push   eax
  4f69b6:	53                                              	push   ebx
  4f69b7:	e8 a4 b7 f0 ff                                  	call   0x402160
  4f69bc:	5f                                              	pop    edi
  4f69bd:	5e                                              	pop    esi
  4f69be:	5b                                              	pop    ebx
  4f69bf:	8b e5                                           	mov    esp,ebp
  4f69c1:	5d                                              	pop    ebp
  4f69c2:	c2 08 00                                        	ret    0x8
  4f69c5:	6a 1c                                           	push   0x1c
  4f69c7:	e8 9c a8 39 00                                  	call   0x891268
  4f69cc:	33 ff                                           	xor    edi,edi
  4f69ce:	83 c4 04                                        	add    esp,0x4
  4f69d1:	3b c7                                           	cmp    eax,edi
  4f69d3:	74 11                                           	je     0x4f69e6
  4f69d5:	89 78 10                                        	mov    DWORD PTR [eax+0x10],edi
  4f69d8:	33 c9                                           	xor    ecx,ecx
  4f69da:	c7 40 14 07 00 00 00                            	mov    DWORD PTR [eax+0x14],0x7
  4f69e1:	66 89 08                                        	mov    WORD PTR [eax],cx
  4f69e4:	8b f8                                           	mov    edi,eax
  4f69e6:	8b c3                                           	mov    eax,ebx
  4f69e8:	8d 50 02                                        	lea    edx,[eax+0x2]
  4f69eb:	eb 03                                           	jmp    0x4f69f0
  4f69ed:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  4f69f0:	66 8b 08                                        	mov    cx,WORD PTR [eax]
  4f69f3:	83 c0 02                                        	add    eax,0x2
  4f69f6:	66 85 c9                                        	test   cx,cx
  4f69f9:	75 f5                                           	jne    0x4f69f0
  4f69fb:	2b c2                                           	sub    eax,edx
  4f69fd:	d1 f8                                           	sar    eax,1
  4f69ff:	50                                              	push   eax
  4f6a00:	53                                              	push   ebx
  4f6a01:	8b cf                                           	mov    ecx,edi
  4f6a03:	e8 58 b7 f0 ff                                  	call   0x402160
  4f6a08:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  4f6a0b:	89 7d fc                                        	mov    DWORD PTR [ebp-0x4],edi
  4f6a0e:	8d 7d f8                                        	lea    edi,[ebp-0x8]
  4f6a11:	89 55 f8                                        	mov    DWORD PTR [ebp-0x8],edx
  4f6a14:	e8 07 85 08 00                                  	call   0x57ef20
  4f6a19:	50                                              	push   eax
  4f6a1a:	56                                              	push   esi
  4f6a1b:	8d 75 f8                                        	lea    esi,[ebp-0x8]
  4f6a1e:	e8 2d 7e 08 00                                  	call   0x57e850
  4f6a23:	5f                                              	pop    edi
  4f6a24:	5e                                              	pop    esi
  4f6a25:	5b                                              	pop    ebx
  4f6a26:	8b e5                                           	mov    esp,ebp
  4f6a28:	5d                                              	pop    ebp
  4f6a29:	c2 08 00                                        	ret    0x8
  4f6a2c:	cc                                              	int3
  4f6a2d:	cc                                              	int3
  4f6a2e:	cc                                              	int3
  4f6a2f:	cc                                              	int3

; root-helper-4f6a30 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6a30 <.text+0xf5a30>:
  4f6a30:	55                                              	push   ebp
  4f6a31:	8b ec                                           	mov    ebp,esp
  4f6a33:	83 ec 10                                        	sub    esp,0x10
  4f6a36:	53                                              	push   ebx
  4f6a37:	56                                              	push   esi
  4f6a38:	57                                              	push   edi
  4f6a39:	8b f8                                           	mov    edi,eax
  4f6a3b:	8d 45 08                                        	lea    eax,[ebp+0x8]
  4f6a3e:	8d b7 00 01 00 00                               	lea    esi,[edi+0x100]
  4f6a44:	50                                              	push   eax
  4f6a45:	8d 45 f8                                        	lea    eax,[ebp-0x8]
  4f6a48:	8b ce                                           	mov    ecx,esi
  4f6a4a:	e8 71 ce 34 00                                  	call   0x8438c0
  4f6a4f:	8b 45 f8                                        	mov    eax,DWORD PTR [ebp-0x8]
  4f6a52:	3b 87 04 01 00 00                               	cmp    eax,DWORD PTR [edi+0x104]
  4f6a58:	74 18                                           	je     0x4f6a72
  4f6a5a:	8b 40 10                                        	mov    eax,DWORD PTR [eax+0x10]
  4f6a5d:	83 78 14 08                                     	cmp    DWORD PTR [eax+0x14],0x8
  4f6a61:	0f 82 a2 00 00 00                               	jb     0x4f6b09
  4f6a67:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f6a69:	5f                                              	pop    edi
  4f6a6a:	5e                                              	pop    esi
  4f6a6b:	5b                                              	pop    ebx
  4f6a6c:	8b e5                                           	mov    esp,ebp
  4f6a6e:	5d                                              	pop    ebp
  4f6a6f:	c2 04 00                                        	ret    0x4
  4f6a72:	81 c7 10 01 00 00                               	add    edi,0x110
  4f6a78:	8d 45 08                                        	lea    eax,[ebp+0x8]
  4f6a7b:	e8 00 1c fb ff                                  	call   0x4a8680
  4f6a80:	6a 1c                                           	push   0x1c
  4f6a82:	e8 e1 a7 39 00                                  	call   0x891268
  4f6a87:	83 c4 04                                        	add    esp,0x4
  4f6a8a:	85 c0                                           	test   eax,eax
  4f6a8c:	74 17                                           	je     0x4f6aa5
  4f6a8e:	33 c9                                           	xor    ecx,ecx
  4f6a90:	c7 40 14 07 00 00 00                            	mov    DWORD PTR [eax+0x14],0x7
  4f6a97:	c7 40 10 00 00 00 00                            	mov    DWORD PTR [eax+0x10],0x0
  4f6a9e:	66 89 08                                        	mov    WORD PTR [eax],cx
  4f6aa1:	8b d8                                           	mov    ebx,eax
  4f6aa3:	eb 02                                           	jmp    0x4f6aa7
  4f6aa5:	33 db                                           	xor    ebx,ebx
  4f6aa7:	8b 43 10                                        	mov    eax,DWORD PTR [ebx+0x10]
  4f6aaa:	8b cb                                           	mov    ecx,ebx
  4f6aac:	83 f8 14                                        	cmp    eax,0x14
  4f6aaf:	72 0b                                           	jb     0x4f6abc
  4f6ab1:	6a ff                                           	push   0xffffffff
  4f6ab3:	6a 14                                           	push   0x14
  4f6ab5:	e8 46 b9 f0 ff                                  	call   0x402400
  4f6aba:	eb 0f                                           	jmp    0x4f6acb
  4f6abc:	ba 14 00 00 00                                  	mov    edx,0x14
  4f6ac1:	6a 00                                           	push   0x0
  4f6ac3:	2b d0                                           	sub    edx,eax
  4f6ac5:	52                                              	push   edx
  4f6ac6:	e8 45 95 f4 ff                                  	call   0x440010
  4f6acb:	6a ff                                           	push   0xffffffff
  4f6acd:	6a 00                                           	push   0x0
  4f6acf:	68 9c aa e2 00                                  	push   0xe2aa9c
  4f6ad4:	8b cb                                           	mov    ecx,ebx
  4f6ad6:	e8 05 bc f0 ff                                  	call   0x4026e0
  4f6adb:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  4f6ade:	8d 7d f4                                        	lea    edi,[ebp-0xc]
  4f6ae1:	89 45 f4                                        	mov    DWORD PTR [ebp-0xc],eax
  4f6ae4:	89 5d f8                                        	mov    DWORD PTR [ebp-0x8],ebx
  4f6ae7:	e8 34 84 08 00                                  	call   0x57ef20
  4f6aec:	50                                              	push   eax
  4f6aed:	56                                              	push   esi
  4f6aee:	8d 75 f4                                        	lea    esi,[ebp-0xc]
  4f6af1:	e8 5a 7d 08 00                                  	call   0x57e850
  4f6af6:	83 7b 14 08                                     	cmp    DWORD PTR [ebx+0x14],0x8
  4f6afa:	72 0b                                           	jb     0x4f6b07
  4f6afc:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  4f6afe:	5f                                              	pop    edi
  4f6aff:	5e                                              	pop    esi
  4f6b00:	5b                                              	pop    ebx
  4f6b01:	8b e5                                           	mov    esp,ebp
  4f6b03:	5d                                              	pop    ebp
  4f6b04:	c2 04 00                                        	ret    0x4
  4f6b07:	8b c3                                           	mov    eax,ebx
  4f6b09:	5f                                              	pop    edi
  4f6b0a:	5e                                              	pop    esi
  4f6b0b:	5b                                              	pop    ebx
  4f6b0c:	8b e5                                           	mov    esp,ebp
  4f6b0e:	5d                                              	pop    ebp
  4f6b0f:	c2 04 00                                        	ret    0x4
  4f6b12:	cc                                              	int3
  4f6b13:	cc                                              	int3
  4f6b14:	cc                                              	int3
  4f6b15:	cc                                              	int3
  4f6b16:	cc                                              	int3
  4f6b17:	cc                                              	int3
  4f6b18:	cc                                              	int3
  4f6b19:	cc                                              	int3
  4f6b1a:	cc                                              	int3
  4f6b1b:	cc                                              	int3
  4f6b1c:	cc                                              	int3
  4f6b1d:	cc                                              	int3
  4f6b1e:	cc                                              	int3
  4f6b1f:	cc                                              	int3

; root-helper-4f6dc0 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6dc0 <.text+0xf5dc0>:
  4f6dc0:	55                                              	push   ebp
  4f6dc1:	8b ec                                           	mov    ebp,esp
  4f6dc3:	53                                              	push   ebx
  4f6dc4:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  4f6dc7:	56                                              	push   esi
  4f6dc8:	57                                              	push   edi
  4f6dc9:	8b b8 04 01 00 00                               	mov    edi,DWORD PTR [eax+0x104]
  4f6dcf:	8b 37                                           	mov    esi,DWORD PTR [edi]
  4f6dd1:	3b f7                                           	cmp    esi,edi
  4f6dd3:	0f 84 91 00 00 00                               	je     0x4f6e6a
  4f6dd9:	8d a4 24 00 00 00 00                            	lea    esp,[esp+0x0]
  4f6de0:	8b 46 10                                        	mov    eax,DWORD PTR [esi+0x10]
  4f6de3:	83 78 14 08                                     	cmp    DWORD PTR [eax+0x14],0x8
  4f6de7:	72 02                                           	jb     0x4f6deb
  4f6de9:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f6deb:	8b cb                                           	mov    ecx,ebx
  4f6ded:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  4f6df0:	66 8b 10                                        	mov    dx,WORD PTR [eax]
  4f6df3:	66 3b 11                                        	cmp    dx,WORD PTR [ecx]
  4f6df6:	75 1e                                           	jne    0x4f6e16
  4f6df8:	66 85 d2                                        	test   dx,dx
  4f6dfb:	74 15                                           	je     0x4f6e12
  4f6dfd:	66 8b 50 02                                     	mov    dx,WORD PTR [eax+0x2]
  4f6e01:	66 3b 51 02                                     	cmp    dx,WORD PTR [ecx+0x2]
  4f6e05:	75 0f                                           	jne    0x4f6e16
  4f6e07:	83 c0 04                                        	add    eax,0x4
  4f6e0a:	83 c1 04                                        	add    ecx,0x4
  4f6e0d:	66 85 d2                                        	test   dx,dx
  4f6e10:	75 de                                           	jne    0x4f6df0
  4f6e12:	33 c0                                           	xor    eax,eax
  4f6e14:	eb 05                                           	jmp    0x4f6e1b
  4f6e16:	1b c0                                           	sbb    eax,eax
  4f6e18:	83 d8 ff                                        	sbb    eax,0xffffffff
  4f6e1b:	85 c0                                           	test   eax,eax
  4f6e1d:	74 55                                           	je     0x4f6e74
  4f6e1f:	80 7e 15 00                                     	cmp    BYTE PTR [esi+0x15],0x0
  4f6e23:	75 3d                                           	jne    0x4f6e62
  4f6e25:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  4f6e28:	80 79 15 00                                     	cmp    BYTE PTR [ecx+0x15],0x0
  4f6e2c:	75 16                                           	jne    0x4f6e44
  4f6e2e:	8b 01                                           	mov    eax,DWORD PTR [ecx]
  4f6e30:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6e34:	75 0a                                           	jne    0x4f6e40
  4f6e36:	8b c8                                           	mov    ecx,eax
  4f6e38:	8b 01                                           	mov    eax,DWORD PTR [ecx]
  4f6e3a:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6e3e:	74 f6                                           	je     0x4f6e36
  4f6e40:	8b f1                                           	mov    esi,ecx
  4f6e42:	eb 1e                                           	jmp    0x4f6e62
  4f6e44:	8b 46 04                                        	mov    eax,DWORD PTR [esi+0x4]
  4f6e47:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6e4b:	75 13                                           	jne    0x4f6e60
  4f6e4d:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  4f6e50:	3b 70 08                                        	cmp    esi,DWORD PTR [eax+0x8]
  4f6e53:	75 0b                                           	jne    0x4f6e60
  4f6e55:	8b f0                                           	mov    esi,eax
  4f6e57:	8b 40 04                                        	mov    eax,DWORD PTR [eax+0x4]
  4f6e5a:	80 78 15 00                                     	cmp    BYTE PTR [eax+0x15],0x0
  4f6e5e:	74 f0                                           	je     0x4f6e50
  4f6e60:	8b f0                                           	mov    esi,eax
  4f6e62:	3b f7                                           	cmp    esi,edi
  4f6e64:	0f 85 76 ff ff ff                               	jne    0x4f6de0
  4f6e6a:	5f                                              	pop    edi
  4f6e6b:	5e                                              	pop    esi
  4f6e6c:	83 c8 ff                                        	or     eax,0xffffffff
  4f6e6f:	5b                                              	pop    ebx
  4f6e70:	5d                                              	pop    ebp
  4f6e71:	c2 04 00                                        	ret    0x4
  4f6e74:	8b 46 0c                                        	mov    eax,DWORD PTR [esi+0xc]
  4f6e77:	5f                                              	pop    edi
  4f6e78:	5e                                              	pop    esi
  4f6e79:	5b                                              	pop    ebx
  4f6e7a:	5d                                              	pop    ebp
  4f6e7b:	c2 04 00                                        	ret    0x4
  4f6e7e:	cc                                              	int3
  4f6e7f:	cc                                              	int3

; root-helper-4f6e80 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6e80 <.text+0xf5e80>:
  4f6e80:	55                                              	push   ebp
  4f6e81:	8b ec                                           	mov    ebp,esp
  4f6e83:	6a ff                                           	push   0xffffffff
  4f6e85:	68 38 78 91 00                                  	push   0x917838
  4f6e8a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4f6e90:	50                                              	push   eax
  4f6e91:	83 ec 28                                        	sub    esp,0x28
  4f6e94:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4f6e99:	33 c5                                           	xor    eax,ebp
  4f6e9b:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  4f6e9e:	53                                              	push   ebx
  4f6e9f:	56                                              	push   esi
  4f6ea0:	50                                              	push   eax
  4f6ea1:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4f6ea4:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4f6eaa:	33 db                                           	xor    ebx,ebx
  4f6eac:	8b c1                                           	mov    eax,ecx
  4f6eae:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  4f6eb5:	89 5d e4                                        	mov    DWORD PTR [ebp-0x1c],ebx
  4f6eb8:	88 5d d4                                        	mov    BYTE PTR [ebp-0x2c],bl
  4f6ebb:	8d 70 01                                        	lea    esi,[eax+0x1]
  4f6ebe:	8b ff                                           	mov    edi,edi
  4f6ec0:	8a 10                                           	mov    dl,BYTE PTR [eax]
  4f6ec2:	40                                              	inc    eax
  4f6ec3:	3a d3                                           	cmp    dl,bl
  4f6ec5:	75 f9                                           	jne    0x4f6ec0
  4f6ec7:	2b c6                                           	sub    eax,esi
  4f6ec9:	50                                              	push   eax
  4f6eca:	51                                              	push   ecx
  4f6ecb:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  4f6ece:	e8 9d bb f0 ff                                  	call   0x402a70
  4f6ed3:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  4f6ed6:	50                                              	push   eax
  4f6ed7:	8d 87 e0 00 00 00                               	lea    eax,[edi+0xe0]
  4f6edd:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  4f6ee0:	e8 7b 12 00 00                                  	call   0x4f8160
  4f6ee5:	89 45 cc                                        	mov    DWORD PTR [ebp-0x34],eax
  4f6ee8:	3b 87 e4 00 00 00                               	cmp    eax,DWORD PTR [edi+0xe4]
  4f6eee:	74 14                                           	je     0x4f6f04
  4f6ef0:	83 c0 0c                                        	add    eax,0xc
  4f6ef3:	8d 55 d4                                        	lea    edx,[ebp-0x2c]
  4f6ef6:	e8 35 3f fa ff                                  	call   0x49ae30
  4f6efb:	84 c0                                           	test   al,al
  4f6efd:	75 05                                           	jne    0x4f6f04
  4f6eff:	8d 45 cc                                        	lea    eax,[ebp-0x34]
  4f6f02:	eb 0c                                           	jmp    0x4f6f10
  4f6f04:	8b 8f e4 00 00 00                               	mov    ecx,DWORD PTR [edi+0xe4]
  4f6f0a:	89 4d d0                                        	mov    DWORD PTR [ebp-0x30],ecx
  4f6f0d:	8d 45 d0                                        	lea    eax,[ebp-0x30]
  4f6f10:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  4f6f14:	8b 30                                           	mov    esi,DWORD PTR [eax]
  4f6f16:	72 0c                                           	jb     0x4f6f24
  4f6f18:	8b 55 d4                                        	mov    edx,DWORD PTR [ebp-0x2c]
  4f6f1b:	52                                              	push   edx
  4f6f1c:	e8 eb a2 39 00                                  	call   0x89120c
  4f6f21:	83 c4 04                                        	add    esp,0x4
  4f6f24:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  4f6f2b:	89 5d e4                                        	mov    DWORD PTR [ebp-0x1c],ebx
  4f6f2e:	88 5d d4                                        	mov    BYTE PTR [ebp-0x2c],bl
  4f6f31:	3b b7 e4 00 00 00                               	cmp    esi,DWORD PTR [edi+0xe4]
  4f6f37:	75 04                                           	jne    0x4f6f3d
  4f6f39:	33 c0                                           	xor    eax,eax
  4f6f3b:	eb 0b                                           	jmp    0x4f6f48
  4f6f3d:	83 7e 3c 10                                     	cmp    DWORD PTR [esi+0x3c],0x10
  4f6f41:	8d 46 28                                        	lea    eax,[esi+0x28]
  4f6f44:	72 02                                           	jb     0x4f6f48
  4f6f46:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f6f48:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4f6f4b:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4f6f52:	59                                              	pop    ecx
  4f6f53:	5e                                              	pop    esi
  4f6f54:	5b                                              	pop    ebx
  4f6f55:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  4f6f58:	33 cd                                           	xor    ecx,ebp
  4f6f5a:	e8 a2 a0 39 00                                  	call   0x891001
  4f6f5f:	8b e5                                           	mov    esp,ebp
  4f6f61:	5d                                              	pop    ebp
  4f6f62:	c3                                              	ret
  4f6f63:	cc                                              	int3
  4f6f64:	cc                                              	int3
  4f6f65:	cc                                              	int3
  4f6f66:	cc                                              	int3
  4f6f67:	cc                                              	int3
  4f6f68:	cc                                              	int3
  4f6f69:	cc                                              	int3
  4f6f6a:	cc                                              	int3
  4f6f6b:	cc                                              	int3
  4f6f6c:	cc                                              	int3
  4f6f6d:	cc                                              	int3
  4f6f6e:	cc                                              	int3
  4f6f6f:	cc                                              	int3

; root-helper-4f7280 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f7280 <.text+0xf6280>:
  4f7280:	55                                              	push   ebp
  4f7281:	8b ec                                           	mov    ebp,esp
  4f7283:	83 ec 0c                                        	sub    esp,0xc
  4f7286:	83 7d 14 ff                                     	cmp    DWORD PTR [ebp+0x14],0xffffffff
  4f728a:	53                                              	push   ebx
  4f728b:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  4f728e:	56                                              	push   esi
  4f728f:	57                                              	push   edi
  4f7290:	75 15                                           	jne    0x4f72a7
  4f7292:	8d bb 30 01 00 00                               	lea    edi,[ebx+0x130]
  4f7298:	8d 45 0c                                        	lea    eax,[ebp+0xc]
  4f729b:	e8 e0 13 fb ff                                  	call   0x4a8680
  4f72a0:	c7 45 14 00 00 00 00                            	mov    DWORD PTR [ebp+0x14],0x0
  4f72a7:	8d 45 0c                                        	lea    eax,[ebp+0xc]
  4f72aa:	8d b3 20 01 00 00                               	lea    esi,[ebx+0x120]
  4f72b0:	50                                              	push   eax
  4f72b1:	8d 45 08                                        	lea    eax,[ebp+0x8]
  4f72b4:	8b ce                                           	mov    ecx,esi
  4f72b6:	e8 05 c6 34 00                                  	call   0x8438c0
  4f72bb:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  4f72be:	3b 83 24 01 00 00                               	cmp    eax,DWORD PTR [ebx+0x124]
  4f72c4:	74 32                                           	je     0x4f72f8
  4f72c6:	8b 7d 10                                        	mov    edi,DWORD PTR [ebp+0x10]
  4f72c9:	8b 70 10                                        	mov    esi,DWORD PTR [eax+0x10]
  4f72cc:	8b c7                                           	mov    eax,edi
  4f72ce:	8d 50 02                                        	lea    edx,[eax+0x2]
  4f72d1:	66 8b 08                                        	mov    cx,WORD PTR [eax]
  4f72d4:	83 c0 02                                        	add    eax,0x2
  4f72d7:	66 85 c9                                        	test   cx,cx
  4f72da:	75 f5                                           	jne    0x4f72d1
  4f72dc:	2b c2                                           	sub    eax,edx
  4f72de:	d1 f8                                           	sar    eax,1
  4f72e0:	50                                              	push   eax
  4f72e1:	57                                              	push   edi
  4f72e2:	8b ce                                           	mov    ecx,esi
  4f72e4:	e8 77 ae f0 ff                                  	call   0x402160
  4f72e9:	8b 4d 14                                        	mov    ecx,DWORD PTR [ebp+0x14]
  4f72ec:	89 4e 1c                                        	mov    DWORD PTR [esi+0x1c],ecx
  4f72ef:	5f                                              	pop    edi
  4f72f0:	5e                                              	pop    esi
  4f72f1:	5b                                              	pop    ebx
  4f72f2:	8b e5                                           	mov    esp,ebp
  4f72f4:	5d                                              	pop    ebp
  4f72f5:	c2 10 00                                        	ret    0x10
  4f72f8:	6a 20                                           	push   0x20
  4f72fa:	e8 69 9f 39 00                                  	call   0x891268
  4f72ff:	33 ff                                           	xor    edi,edi
  4f7301:	83 c4 04                                        	add    esp,0x4
  4f7304:	3b c7                                           	cmp    eax,edi
  4f7306:	74 11                                           	je     0x4f7319
  4f7308:	89 78 10                                        	mov    DWORD PTR [eax+0x10],edi
  4f730b:	33 d2                                           	xor    edx,edx
  4f730d:	c7 40 14 07 00 00 00                            	mov    DWORD PTR [eax+0x14],0x7
  4f7314:	66 89 10                                        	mov    WORD PTR [eax],dx
  4f7317:	8b f8                                           	mov    edi,eax
  4f7319:	8b 5d 10                                        	mov    ebx,DWORD PTR [ebp+0x10]
  4f731c:	8b c3                                           	mov    eax,ebx
  4f731e:	8d 50 02                                        	lea    edx,[eax+0x2]
  4f7321:	66 8b 08                                        	mov    cx,WORD PTR [eax]
  4f7324:	83 c0 02                                        	add    eax,0x2
  4f7327:	66 85 c9                                        	test   cx,cx
  4f732a:	75 f5                                           	jne    0x4f7321
  4f732c:	2b c2                                           	sub    eax,edx
  4f732e:	d1 f8                                           	sar    eax,1
  4f7330:	50                                              	push   eax
  4f7331:	53                                              	push   ebx
  4f7332:	8b cf                                           	mov    ecx,edi
  4f7334:	e8 27 ae f0 ff                                  	call   0x402160
  4f7339:	8b 45 14                                        	mov    eax,DWORD PTR [ebp+0x14]
  4f733c:	8b 4d 0c                                        	mov    ecx,DWORD PTR [ebp+0xc]
  4f733f:	89 47 1c                                        	mov    DWORD PTR [edi+0x1c],eax
  4f7342:	89 7d fc                                        	mov    DWORD PTR [ebp-0x4],edi
  4f7345:	8d 7d f8                                        	lea    edi,[ebp-0x8]
  4f7348:	89 4d f8                                        	mov    DWORD PTR [ebp-0x8],ecx
  4f734b:	e8 d0 7b 08 00                                  	call   0x57ef20
  4f7350:	50                                              	push   eax
  4f7351:	56                                              	push   esi
  4f7352:	8d 75 f8                                        	lea    esi,[ebp-0x8]
  4f7355:	e8 f6 74 08 00                                  	call   0x57e850
  4f735a:	5f                                              	pop    edi
  4f735b:	5e                                              	pop    esi
  4f735c:	5b                                              	pop    ebx
  4f735d:	8b e5                                           	mov    esp,ebp
  4f735f:	5d                                              	pop    ebp
  4f7360:	c2 10 00                                        	ret    0x10
  4f7363:	cc                                              	int3
  4f7364:	cc                                              	int3
  4f7365:	cc                                              	int3
  4f7366:	cc                                              	int3
  4f7367:	cc                                              	int3
  4f7368:	cc                                              	int3
  4f7369:	cc                                              	int3
  4f736a:	cc                                              	int3
  4f736b:	cc                                              	int3
  4f736c:	cc                                              	int3
  4f736d:	cc                                              	int3
  4f736e:	cc                                              	int3
  4f736f:	cc                                              	int3

; root-helper-4f7370 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f7370 <.text+0xf6370>:
  4f7370:	55                                              	push   ebp
  4f7371:	8b ec                                           	mov    ebp,esp
  4f7373:	83 ec 10                                        	sub    esp,0x10
  4f7376:	53                                              	push   ebx
  4f7377:	56                                              	push   esi
  4f7378:	57                                              	push   edi
  4f7379:	8b f8                                           	mov    edi,eax
  4f737b:	8d 45 08                                        	lea    eax,[ebp+0x8]
  4f737e:	8d b7 20 01 00 00                               	lea    esi,[edi+0x120]
  4f7384:	50                                              	push   eax
  4f7385:	8d 45 f8                                        	lea    eax,[ebp-0x8]
  4f7388:	8b ce                                           	mov    ecx,esi
  4f738a:	e8 31 c5 34 00                                  	call   0x8438c0
  4f738f:	8b 45 f8                                        	mov    eax,DWORD PTR [ebp-0x8]
  4f7392:	3b 87 24 01 00 00                               	cmp    eax,DWORD PTR [edi+0x124]
  4f7398:	74 18                                           	je     0x4f73b2
  4f739a:	8b 40 10                                        	mov    eax,DWORD PTR [eax+0x10]
  4f739d:	83 78 14 08                                     	cmp    DWORD PTR [eax+0x14],0x8
  4f73a1:	0f 82 a1 00 00 00                               	jb     0x4f7448
  4f73a7:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f73a9:	5f                                              	pop    edi
  4f73aa:	5e                                              	pop    esi
  4f73ab:	5b                                              	pop    ebx
  4f73ac:	8b e5                                           	mov    esp,ebp
  4f73ae:	5d                                              	pop    ebp
  4f73af:	c2 04 00                                        	ret    0x4
  4f73b2:	81 c7 30 01 00 00                               	add    edi,0x130
  4f73b8:	8d 45 08                                        	lea    eax,[ebp+0x8]
  4f73bb:	e8 c0 12 fb ff                                  	call   0x4a8680
  4f73c0:	6a 20                                           	push   0x20
  4f73c2:	e8 a1 9e 39 00                                  	call   0x891268
  4f73c7:	33 ff                                           	xor    edi,edi
  4f73c9:	83 c4 04                                        	add    esp,0x4
  4f73cc:	3b c7                                           	cmp    eax,edi
  4f73ce:	74 13                                           	je     0x4f73e3
  4f73d0:	33 c9                                           	xor    ecx,ecx
  4f73d2:	c7 40 14 07 00 00 00                            	mov    DWORD PTR [eax+0x14],0x7
  4f73d9:	89 78 10                                        	mov    DWORD PTR [eax+0x10],edi
  4f73dc:	66 89 08                                        	mov    WORD PTR [eax],cx
  4f73df:	8b d8                                           	mov    ebx,eax
  4f73e1:	eb 02                                           	jmp    0x4f73e5
  4f73e3:	33 db                                           	xor    ebx,ebx
  4f73e5:	8b 43 10                                        	mov    eax,DWORD PTR [ebx+0x10]
  4f73e8:	8b cb                                           	mov    ecx,ebx
  4f73ea:	83 f8 14                                        	cmp    eax,0x14
  4f73ed:	72 0b                                           	jb     0x4f73fa
  4f73ef:	6a ff                                           	push   0xffffffff
  4f73f1:	6a 14                                           	push   0x14
  4f73f3:	e8 08 b0 f0 ff                                  	call   0x402400
  4f73f8:	eb 0e                                           	jmp    0x4f7408
  4f73fa:	ba 14 00 00 00                                  	mov    edx,0x14
  4f73ff:	57                                              	push   edi
  4f7400:	2b d0                                           	sub    edx,eax
  4f7402:	52                                              	push   edx
  4f7403:	e8 08 8c f4 ff                                  	call   0x440010
  4f7408:	6a ff                                           	push   0xffffffff
  4f740a:	57                                              	push   edi
  4f740b:	68 9c aa e2 00                                  	push   0xe2aa9c
  4f7410:	8b cb                                           	mov    ecx,ebx
  4f7412:	e8 c9 b2 f0 ff                                  	call   0x4026e0
  4f7417:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  4f741a:	89 7b 1c                                        	mov    DWORD PTR [ebx+0x1c],edi
  4f741d:	8d 7d f4                                        	lea    edi,[ebp-0xc]
  4f7420:	89 45 f4                                        	mov    DWORD PTR [ebp-0xc],eax
  4f7423:	89 5d f8                                        	mov    DWORD PTR [ebp-0x8],ebx
  4f7426:	e8 f5 7a 08 00                                  	call   0x57ef20
  4f742b:	50                                              	push   eax
  4f742c:	56                                              	push   esi
  4f742d:	8d 75 f4                                        	lea    esi,[ebp-0xc]
  4f7430:	e8 1b 74 08 00                                  	call   0x57e850
  4f7435:	83 7b 14 08                                     	cmp    DWORD PTR [ebx+0x14],0x8
  4f7439:	72 0b                                           	jb     0x4f7446
  4f743b:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  4f743d:	5f                                              	pop    edi
  4f743e:	5e                                              	pop    esi
  4f743f:	5b                                              	pop    ebx
  4f7440:	8b e5                                           	mov    esp,ebp
  4f7442:	5d                                              	pop    ebp
  4f7443:	c2 04 00                                        	ret    0x4
  4f7446:	8b c3                                           	mov    eax,ebx
  4f7448:	5f                                              	pop    edi
  4f7449:	5e                                              	pop    esi
  4f744a:	5b                                              	pop    ebx
  4f744b:	8b e5                                           	mov    esp,ebp
  4f744d:	5d                                              	pop    ebp
  4f744e:	c2 04 00                                        	ret    0x4
  4f7451:	cc                                              	int3
  4f7452:	cc                                              	int3
  4f7453:	cc                                              	int3
  4f7454:	cc                                              	int3
  4f7455:	cc                                              	int3
  4f7456:	cc                                              	int3
  4f7457:	cc                                              	int3
  4f7458:	cc                                              	int3
  4f7459:	cc                                              	int3
  4f745a:	cc                                              	int3
  4f745b:	cc                                              	int3
  4f745c:	cc                                              	int3
  4f745d:	cc                                              	int3
  4f745e:	cc                                              	int3
  4f745f:	cc                                              	int3

; root-helper-4f7a70 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f7a70 <.text+0xf6a70>:
  4f7a70:	55                                              	push   ebp
  4f7a71:	8b ec                                           	mov    ebp,esp
  4f7a73:	83 e4 f8                                        	and    esp,0xfffffff8
  4f7a76:	6a ff                                           	push   0xffffffff
  4f7a78:	68 13 75 91 00                                  	push   0x917513
  4f7a7d:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4f7a83:	50                                              	push   eax
  4f7a84:	81 ec e0 00 00 00                               	sub    esp,0xe0
  4f7a8a:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4f7a8f:	33 c4                                           	xor    eax,esp
  4f7a91:	89 84 24 d8 00 00 00                            	mov    DWORD PTR [esp+0xd8],eax
  4f7a98:	53                                              	push   ebx
  4f7a99:	56                                              	push   esi
  4f7a9a:	57                                              	push   edi
  4f7a9b:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4f7aa0:	33 c4                                           	xor    eax,esp
  4f7aa2:	50                                              	push   eax
  4f7aa3:	8d 84 24 f0 00 00 00                            	lea    eax,[esp+0xf0]
  4f7aaa:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4f7ab0:	8b f1                                           	mov    esi,ecx
  4f7ab2:	8b 4e 04                                        	mov    ecx,DWORD PTR [esi+0x4]
  4f7ab5:	8b 41 04                                        	mov    eax,DWORD PTR [ecx+0x4]
  4f7ab8:	8b d9                                           	mov    ebx,ecx
  4f7aba:	33 c9                                           	xor    ecx,ecx
  4f7abc:	38 48 75                                        	cmp    BYTE PTR [eax+0x75],cl
  4f7abf:	75 15                                           	jne    0x4f7ad6
  4f7ac1:	8b 3a                                           	mov    edi,DWORD PTR [edx]
  4f7ac3:	39 78 0c                                        	cmp    DWORD PTR [eax+0xc],edi
  4f7ac6:	73 05                                           	jae    0x4f7acd
  4f7ac8:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  4f7acb:	eb 04                                           	jmp    0x4f7ad1
  4f7acd:	8b d8                                           	mov    ebx,eax
  4f7acf:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f7ad1:	38 48 75                                        	cmp    BYTE PTR [eax+0x75],cl
  4f7ad4:	74 ed                                           	je     0x4f7ac3
  4f7ad6:	3b 5e 04                                        	cmp    ebx,DWORD PTR [esi+0x4]
  4f7ad9:	74 0b                                           	je     0x4f7ae6
  4f7adb:	8b 02                                           	mov    eax,DWORD PTR [edx]
  4f7add:	3b 43 0c                                        	cmp    eax,DWORD PTR [ebx+0xc]
  4f7ae0:	0f 83 8e 00 00 00                               	jae    0x4f7b74
  4f7ae6:	b8 0f 00 00 00                                  	mov    eax,0xf
  4f7aeb:	33 ff                                           	xor    edi,edi
  4f7aed:	89 44 24 28                                     	mov    DWORD PTR [esp+0x28],eax
  4f7af1:	89 4c 24 24                                     	mov    DWORD PTR [esp+0x24],ecx
  4f7af5:	88 4c 24 14                                     	mov    BYTE PTR [esp+0x14],cl
  4f7af9:	c7 44 24 44 07 00 00 00                         	mov    DWORD PTR [esp+0x44],0x7
  4f7b01:	89 4c 24 40                                     	mov    DWORD PTR [esp+0x40],ecx
  4f7b05:	66 89 7c 24 30                                  	mov    WORD PTR [esp+0x30],di
  4f7b0a:	89 44 24 60                                     	mov    DWORD PTR [esp+0x60],eax
  4f7b0e:	89 4c 24 5c                                     	mov    DWORD PTR [esp+0x5c],ecx
  4f7b12:	88 4c 24 4c                                     	mov    BYTE PTR [esp+0x4c],cl
  4f7b16:	89 8c 24 f8 00 00 00                            	mov    DWORD PTR [esp+0xf8],ecx
  4f7b1d:	8b 0a                                           	mov    ecx,DWORD PTR [edx]
  4f7b1f:	8d 94 24 80 00 00 00                            	lea    edx,[esp+0x80]
  4f7b26:	52                                              	push   edx
  4f7b27:	8d 7c 24 18                                     	lea    edi,[esp+0x18]
  4f7b2b:	89 8c 24 80 00 00 00                            	mov    DWORD PTR [esp+0x80],ecx
  4f7b32:	e8 b9 06 00 00                                  	call   0x4f81f0
  4f7b37:	8d 44 24 7c                                     	lea    eax,[esp+0x7c]
  4f7b3b:	50                                              	push   eax
  4f7b3c:	8b ce                                           	mov    ecx,esi
  4f7b3e:	c6 84 24 fc 00 00 00 01                         	mov    BYTE PTR [esp+0xfc],0x1
  4f7b46:	e8 d5 20 00 00                                  	call   0x4f9c20
  4f7b4b:	53                                              	push   ebx
  4f7b4c:	56                                              	push   esi
  4f7b4d:	8d 74 24 18                                     	lea    esi,[esp+0x18]
  4f7b51:	e8 1a 12 00 00                                  	call   0x4f8d70
  4f7b56:	8b 7c 24 10                                     	mov    edi,DWORD PTR [esp+0x10]
  4f7b5a:	8d b4 24 80 00 00 00                            	lea    esi,[esp+0x80]
  4f7b61:	e8 4a d7 ff ff                                  	call   0x4f52b0
  4f7b66:	8d 74 24 14                                     	lea    esi,[esp+0x14]
  4f7b6a:	e8 41 d7 ff ff                                  	call   0x4f52b0
  4f7b6f:	8d 47 10                                        	lea    eax,[edi+0x10]
  4f7b72:	eb 03                                           	jmp    0x4f7b77
  4f7b74:	8d 43 10                                        	lea    eax,[ebx+0x10]
  4f7b77:	8b 8c 24 f0 00 00 00                            	mov    ecx,DWORD PTR [esp+0xf0]
  4f7b7e:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4f7b85:	59                                              	pop    ecx
  4f7b86:	5f                                              	pop    edi
  4f7b87:	5e                                              	pop    esi
  4f7b88:	5b                                              	pop    ebx
  4f7b89:	8b 8c 24 d8 00 00 00                            	mov    ecx,DWORD PTR [esp+0xd8]
  4f7b90:	33 cc                                           	xor    ecx,esp
  4f7b92:	e8 6a 94 39 00                                  	call   0x891001
  4f7b97:	8b e5                                           	mov    esp,ebp
  4f7b99:	5d                                              	pop    ebp
  4f7b9a:	c3                                              	ret
  4f7b9b:	cc                                              	int3
  4f7b9c:	cc                                              	int3
  4f7b9d:	cc                                              	int3
  4f7b9e:	cc                                              	int3
  4f7b9f:	cc                                              	int3

; root-helper-4f8ac0 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f8ac0 <.text+0xf7ac0>:
  4f8ac0:	55                                              	push   ebp
  4f8ac1:	8b ec                                           	mov    ebp,esp
  4f8ac3:	51                                              	push   ecx
  4f8ac4:	53                                              	push   ebx
  4f8ac5:	56                                              	push   esi
  4f8ac6:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  4f8ac9:	33 db                                           	xor    ebx,ebx
  4f8acb:	57                                              	push   edi
  4f8acc:	89 4d fc                                        	mov    DWORD PTR [ebp-0x4],ecx
  4f8acf:	8b fe                                           	mov    edi,esi
  4f8ad1:	38 5e 75                                        	cmp    BYTE PTR [esi+0x75],bl
  4f8ad4:	75 7e                                           	jne    0x4f8b54
  4f8ad6:	8b 47 08                                        	mov    eax,DWORD PTR [edi+0x8]
  4f8ad9:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  4f8adc:	50                                              	push   eax
  4f8add:	e8 de ff ff ff                                  	call   0x4f8ac0
  4f8ae2:	83 7e 5c 10                                     	cmp    DWORD PTR [esi+0x5c],0x10
  4f8ae6:	8b 3f                                           	mov    edi,DWORD PTR [edi]
  4f8ae8:	72 0c                                           	jb     0x4f8af6
  4f8aea:	8b 4e 48                                        	mov    ecx,DWORD PTR [esi+0x48]
  4f8aed:	51                                              	push   ecx
  4f8aee:	e8 19 87 39 00                                  	call   0x89120c
  4f8af3:	83 c4 04                                        	add    esp,0x4
  4f8af6:	c7 46 5c 0f 00 00 00                            	mov    DWORD PTR [esi+0x5c],0xf
  4f8afd:	89 5e 58                                        	mov    DWORD PTR [esi+0x58],ebx
  4f8b00:	88 5e 48                                        	mov    BYTE PTR [esi+0x48],bl
  4f8b03:	83 7e 40 08                                     	cmp    DWORD PTR [esi+0x40],0x8
  4f8b07:	72 0c                                           	jb     0x4f8b15
  4f8b09:	8b 56 2c                                        	mov    edx,DWORD PTR [esi+0x2c]
  4f8b0c:	52                                              	push   edx
  4f8b0d:	e8 fa 86 39 00                                  	call   0x89120c
  4f8b12:	83 c4 04                                        	add    esp,0x4
  4f8b15:	33 c0                                           	xor    eax,eax
  4f8b17:	c7 46 40 07 00 00 00                            	mov    DWORD PTR [esi+0x40],0x7
  4f8b1e:	89 5e 3c                                        	mov    DWORD PTR [esi+0x3c],ebx
  4f8b21:	66 89 46 2c                                     	mov    WORD PTR [esi+0x2c],ax
  4f8b25:	83 7e 24 10                                     	cmp    DWORD PTR [esi+0x24],0x10
  4f8b29:	72 0c                                           	jb     0x4f8b37
  4f8b2b:	8b 4e 10                                        	mov    ecx,DWORD PTR [esi+0x10]
  4f8b2e:	51                                              	push   ecx
  4f8b2f:	e8 d8 86 39 00                                  	call   0x89120c
  4f8b34:	83 c4 04                                        	add    esp,0x4
  4f8b37:	c7 46 24 0f 00 00 00                            	mov    DWORD PTR [esi+0x24],0xf
  4f8b3e:	89 5e 20                                        	mov    DWORD PTR [esi+0x20],ebx
  4f8b41:	56                                              	push   esi
  4f8b42:	88 5e 10                                        	mov    BYTE PTR [esi+0x10],bl
  4f8b45:	e8 c2 86 39 00                                  	call   0x89120c
  4f8b4a:	83 c4 04                                        	add    esp,0x4
  4f8b4d:	8b f7                                           	mov    esi,edi
  4f8b4f:	38 5f 75                                        	cmp    BYTE PTR [edi+0x75],bl
  4f8b52:	74 82                                           	je     0x4f8ad6
  4f8b54:	5f                                              	pop    edi
  4f8b55:	5e                                              	pop    esi
  4f8b56:	5b                                              	pop    ebx
  4f8b57:	8b e5                                           	mov    esp,ebp
  4f8b59:	5d                                              	pop    ebp
  4f8b5a:	c2 04 00                                        	ret    0x4
  4f8b5d:	cc                                              	int3
  4f8b5e:	cc                                              	int3
  4f8b5f:	cc                                              	int3

; root-helper-4f8b60 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f8b60 <.text+0xf7b60>:
  4f8b60:	55                                              	push   ebp
  4f8b61:	8b ec                                           	mov    ebp,esp
  4f8b63:	8b 41 08                                        	mov    eax,DWORD PTR [ecx+0x8]
  4f8b66:	8b 10                                           	mov    edx,DWORD PTR [eax]
  4f8b68:	89 51 08                                        	mov    DWORD PTR [ecx+0x8],edx
  4f8b6b:	8b 10                                           	mov    edx,DWORD PTR [eax]
  4f8b6d:	80 7a 75 00                                     	cmp    BYTE PTR [edx+0x75],0x0
  4f8b71:	75 03                                           	jne    0x4f8b76
  4f8b73:	89 4a 04                                        	mov    DWORD PTR [edx+0x4],ecx
  4f8b76:	8b 51 04                                        	mov    edx,DWORD PTR [ecx+0x4]
  4f8b79:	89 50 04                                        	mov    DWORD PTR [eax+0x4],edx
  4f8b7c:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  4f8b7f:	8b 52 04                                        	mov    edx,DWORD PTR [edx+0x4]
  4f8b82:	3b 4a 04                                        	cmp    ecx,DWORD PTR [edx+0x4]
  4f8b85:	75 0c                                           	jne    0x4f8b93
  4f8b87:	89 42 04                                        	mov    DWORD PTR [edx+0x4],eax
  4f8b8a:	89 08                                           	mov    DWORD PTR [eax],ecx
  4f8b8c:	89 41 04                                        	mov    DWORD PTR [ecx+0x4],eax
  4f8b8f:	5d                                              	pop    ebp
  4f8b90:	c2 04 00                                        	ret    0x4
  4f8b93:	8b 51 04                                        	mov    edx,DWORD PTR [ecx+0x4]
  4f8b96:	3b 0a                                           	cmp    ecx,DWORD PTR [edx]
  4f8b98:	75 0b                                           	jne    0x4f8ba5
  4f8b9a:	89 02                                           	mov    DWORD PTR [edx],eax
  4f8b9c:	89 08                                           	mov    DWORD PTR [eax],ecx
  4f8b9e:	89 41 04                                        	mov    DWORD PTR [ecx+0x4],eax
  4f8ba1:	5d                                              	pop    ebp
  4f8ba2:	c2 04 00                                        	ret    0x4
  4f8ba5:	89 42 08                                        	mov    DWORD PTR [edx+0x8],eax
  4f8ba8:	89 08                                           	mov    DWORD PTR [eax],ecx
  4f8baa:	89 41 04                                        	mov    DWORD PTR [ecx+0x4],eax
  4f8bad:	5d                                              	pop    ebp
  4f8bae:	c2 04 00                                        	ret    0x4
  4f8bb1:	cc                                              	int3
  4f8bb2:	cc                                              	int3
  4f8bb3:	cc                                              	int3
  4f8bb4:	cc                                              	int3
  4f8bb5:	cc                                              	int3
  4f8bb6:	cc                                              	int3
  4f8bb7:	cc                                              	int3
  4f8bb8:	cc                                              	int3
  4f8bb9:	cc                                              	int3
  4f8bba:	cc                                              	int3
  4f8bbb:	cc                                              	int3
  4f8bbc:	cc                                              	int3
  4f8bbd:	cc                                              	int3
  4f8bbe:	cc                                              	int3
  4f8bbf:	cc                                              	int3

; root-helper-4f8bc0 Root-derived field contract, not whole-program reachability

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f8bc0 <.text+0xf7bc0>:
  4f8bc0:	55                                              	push   ebp
  4f8bc1:	8b ec                                           	mov    ebp,esp
  4f8bc3:	8b 01                                           	mov    eax,DWORD PTR [ecx]
  4f8bc5:	8b 50 08                                        	mov    edx,DWORD PTR [eax+0x8]
  4f8bc8:	89 11                                           	mov    DWORD PTR [ecx],edx
  4f8bca:	8b 50 08                                        	mov    edx,DWORD PTR [eax+0x8]
  4f8bcd:	80 7a 75 00                                     	cmp    BYTE PTR [edx+0x75],0x0
  4f8bd1:	75 03                                           	jne    0x4f8bd6
  4f8bd3:	89 4a 04                                        	mov    DWORD PTR [edx+0x4],ecx
  4f8bd6:	8b 51 04                                        	mov    edx,DWORD PTR [ecx+0x4]
  4f8bd9:	89 50 04                                        	mov    DWORD PTR [eax+0x4],edx
  4f8bdc:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  4f8bdf:	8b 52 04                                        	mov    edx,DWORD PTR [edx+0x4]
  4f8be2:	3b 4a 04                                        	cmp    ecx,DWORD PTR [edx+0x4]
  4f8be5:	75 0d                                           	jne    0x4f8bf4
  4f8be7:	89 42 04                                        	mov    DWORD PTR [edx+0x4],eax
  4f8bea:	89 48 08                                        	mov    DWORD PTR [eax+0x8],ecx
  4f8bed:	89 41 04                                        	mov    DWORD PTR [ecx+0x4],eax
  4f8bf0:	5d                                              	pop    ebp
  4f8bf1:	c2 04 00                                        	ret    0x4
  4f8bf4:	8b 51 04                                        	mov    edx,DWORD PTR [ecx+0x4]
  4f8bf7:	3b 4a 08                                        	cmp    ecx,DWORD PTR [edx+0x8]
  4f8bfa:	75 0d                                           	jne    0x4f8c09
  4f8bfc:	89 42 08                                        	mov    DWORD PTR [edx+0x8],eax
  4f8bff:	89 48 08                                        	mov    DWORD PTR [eax+0x8],ecx
  4f8c02:	89 41 04                                        	mov    DWORD PTR [ecx+0x4],eax
  4f8c05:	5d                                              	pop    ebp
  4f8c06:	c2 04 00                                        	ret    0x4
  4f8c09:	89 02                                           	mov    DWORD PTR [edx],eax
  4f8c0b:	89 48 08                                        	mov    DWORD PTR [eax+0x8],ecx
  4f8c0e:	89 41 04                                        	mov    DWORD PTR [ecx+0x4],eax
  4f8c11:	5d                                              	pop    ebp
  4f8c12:	c2 04 00                                        	ret    0x4
  4f8c15:	cc                                              	int3
  4f8c16:	cc                                              	int3
  4f8c17:	cc                                              	int3
  4f8c18:	cc                                              	int3
  4f8c19:	cc                                              	int3
  4f8c1a:	cc                                              	int3
  4f8c1b:	cc                                              	int3
  4f8c1c:	cc                                              	int3
  4f8c1d:	cc                                              	int3
  4f8c1e:	cc                                              	int3
  4f8c1f:	cc                                              	int3

; literal-tail-4b4152 EDI=root until 4B421D constant overwrite; intervening cold init not transitive closure

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b4152 <.text+0xb3152>:
  4b4152:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  4b4157:	e8 24 2d 04 00                                  	call   0x4f6e80
  4b415c:	8b c8                                           	mov    ecx,eax
  4b415e:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  4b4165:	89 5d e4                                        	mov    DWORD PTR [ebp-0x1c],ebx
  4b4168:	88 5d d4                                        	mov    BYTE PTR [ebp-0x2c],bl
  4b416b:	8d 71 01                                        	lea    esi,[ecx+0x1]
  4b416e:	8b ff                                           	mov    edi,edi
  4b4170:	8a 11                                           	mov    dl,BYTE PTR [ecx]
  4b4172:	41                                              	inc    ecx
  4b4173:	3a d3                                           	cmp    dl,bl
  4b4175:	75 f9                                           	jne    0x4b4170
  4b4177:	2b ce                                           	sub    ecx,esi
  4b4179:	51                                              	push   ecx
  4b417a:	50                                              	push   eax
  4b417b:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  4b417e:	e8 ed e8 f4 ff                                  	call   0x402a70
  4b4183:	be 01 00 00 00                                  	mov    esi,0x1
  4b4188:	89 75 fc                                        	mov    DWORD PTR [ebp-0x4],esi
  4b418b:	f6 05 28 88 fb 00 01                            	test   BYTE PTR ds:0xfb8828,0x1
  4b4192:	75 20                                           	jne    0x4b41b4
  4b4194:	09 35 28 88 fb 00                               	or     DWORD PTR ds:0xfb8828,esi
  4b419a:	c6 45 fc 02                                     	mov    BYTE PTR [ebp-0x4],0x2
  4b419e:	e8 ad b6 09 00                                  	call   0x54f850
  4b41a3:	68 80 d5 bc 00                                  	push   0xbcd580
  4b41a8:	e8 6d e1 3d 00                                  	call   0x89231a
  4b41ad:	83 c4 04                                        	add    esp,0x4
  4b41b0:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  4b41b4:	f6 05 28 88 fb 00 01                            	test   BYTE PTR ds:0xfb8828,0x1
  4b41bb:	66 8b 1d ea 90 fb 00                            	mov    bx,WORD PTR ds:0xfb90ea
  4b41c2:	75 20                                           	jne    0x4b41e4
  4b41c4:	09 35 28 88 fb 00                               	or     DWORD PTR ds:0xfb8828,esi
  4b41ca:	c6 45 fc 03                                     	mov    BYTE PTR [ebp-0x4],0x3
  4b41ce:	e8 7d b6 09 00                                  	call   0x54f850
  4b41d3:	68 80 d5 bc 00                                  	push   0xbcd580
  4b41d8:	e8 3d e1 3d 00                                  	call   0x89231a
  4b41dd:	83 c4 04                                        	add    esp,0x4
  4b41e0:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  4b41e4:	f6 05 c0 0f fc 00 01                            	test   BYTE PTR ds:0xfc0fc0,0x1
  4b41eb:	f3 0f 10 05 5c 93 fb 00                         	movss  xmm0,DWORD PTR ds:0xfb935c
  4b41f3:	f3 0f 11 45 b4                                  	movss  DWORD PTR [ebp-0x4c],xmm0
  4b41f8:	75 20                                           	jne    0x4b421a
  4b41fa:	09 35 c0 0f fc 00                               	or     DWORD PTR ds:0xfc0fc0,esi
  4b4200:	c6 45 fc 04                                     	mov    BYTE PTR [ebp-0x4],0x4
  4b4204:	e8 47 4c 22 00                                  	call   0x6d8e50
  4b4209:	68 b0 db bc 00                                  	push   0xbcdbb0
  4b420e:	e8 07 e1 3d 00                                  	call   0x89231a
  4b4213:	83 c4 04                                        	add    esp,0x4
  4b4216:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  4b421a:	8b 75 d4                                        	mov    esi,DWORD PTR [ebp-0x2c]
  4b421d:	bf 10 00 00 00                                  	mov    edi,0x10

; literal-tail-4bad73 EDI=root until either 4BAEAD or 4BAEB4 constant overwrite

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bad73 <.text+0xb9d73>:
  4bad73:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  4bad78:	e8 03 c1 03 00                                  	call   0x4f6e80
  4bad7d:	f6 05 28 88 fb 00 01                            	test   BYTE PTR ds:0xfb8828,0x1
  4bad84:	8b d8                                           	mov    ebx,eax
  4bad86:	75 30                                           	jne    0x4badb8
  4bad88:	83 0d 28 88 fb 00 01                            	or     DWORD PTR ds:0xfb8828,0x1
  4bad8f:	c7 84 24 98 00 00 00 0e 00 00 00                	mov    DWORD PTR [esp+0x98],0xe
  4bad9a:	e8 b1 4a 09 00                                  	call   0x54f850
  4bad9f:	68 80 d5 bc 00                                  	push   0xbcd580
  4bada4:	e8 71 75 3d 00                                  	call   0x89231a
  4bada9:	83 c4 04                                        	add    esp,0x4
  4badac:	83 ce ff                                        	or     esi,0xffffffff
  4badaf:	89 b4 24 98 00 00 00                            	mov    DWORD PTR [esp+0x98],esi
  4badb6:	eb 03                                           	jmp    0x4badbb
  4badb8:	83 ce ff                                        	or     esi,0xffffffff
  4badbb:	f6 05 28 88 fb 00 01                            	test   BYTE PTR ds:0xfb8828,0x1
  4badc2:	66 8b 3d ea 90 fb 00                            	mov    di,WORD PTR ds:0xfb90ea
  4badc9:	75 2b                                           	jne    0x4badf6
  4badcb:	83 0d 28 88 fb 00 01                            	or     DWORD PTR ds:0xfb8828,0x1
  4badd2:	c7 84 24 98 00 00 00 0f 00 00 00                	mov    DWORD PTR [esp+0x98],0xf
  4baddd:	e8 6e 4a 09 00                                  	call   0x54f850
  4bade2:	68 80 d5 bc 00                                  	push   0xbcd580
  4bade7:	e8 2e 75 3d 00                                  	call   0x89231a
  4badec:	83 c4 04                                        	add    esp,0x4
  4badef:	89 b4 24 98 00 00 00                            	mov    DWORD PTR [esp+0x98],esi
  4badf6:	f6 05 c0 0f fc 00 01                            	test   BYTE PTR ds:0xfc0fc0,0x1
  4badfd:	f3 0f 10 05 5c 93 fb 00                         	movss  xmm0,DWORD PTR ds:0xfb935c
  4bae05:	f3 0f 11 44 24 14                               	movss  DWORD PTR [esp+0x14],xmm0
  4bae0b:	75 5f                                           	jne    0x4bae6c
  4bae0d:	83 0d c0 0f fc 00 01                            	or     DWORD PTR ds:0xfc0fc0,0x1
  4bae14:	c7 84 24 98 00 00 00 10 00 00 00                	mov    DWORD PTR [esp+0x98],0x10
  4bae1f:	e8 2c e0 21 00                                  	call   0x6d8e50
  4bae24:	68 b0 db bc 00                                  	push   0xbcdbb0
  4bae29:	e8 ec 74 3d 00                                  	call   0x89231a
  4bae2e:	83 c4 04                                        	add    esp,0x4
  4bae31:	89 b4 24 98 00 00 00                            	mov    DWORD PTR [esp+0x98],esi
  4bae38:	f6 05 c0 0f fc 00 01                            	test   BYTE PTR ds:0xfc0fc0,0x1
  4bae3f:	75 2b                                           	jne    0x4bae6c
  4bae41:	83 0d c0 0f fc 00 01                            	or     DWORD PTR ds:0xfc0fc0,0x1
  4bae48:	c7 84 24 98 00 00 00 11 00 00 00                	mov    DWORD PTR [esp+0x98],0x11
  4bae53:	e8 f8 df 21 00                                  	call   0x6d8e50
  4bae58:	68 b0 db bc 00                                  	push   0xbcdbb0
  4bae5d:	e8 b8 74 3d 00                                  	call   0x89231a
  4bae62:	83 c4 04                                        	add    esp,0x4
  4bae65:	89 b4 24 98 00 00 00                            	mov    DWORD PTR [esp+0x98],esi
  4bae6c:	d9 44 24 14                                     	fld    DWORD PTR [esp+0x14]
  4bae70:	0f bf d7                                        	movsx  edx,di
  4bae73:	89 54 24 14                                     	mov    DWORD PTR [esp+0x14],edx
  4bae77:	db 44 24 14                                     	fild   DWORD PTR [esp+0x14]
  4bae7b:	de c9                                           	fmulp  st(1),st
  4bae7d:	e8 8e 3e 44 00                                  	call   0x8fed10
  4bae82:	e8 e9 fb 21 00                                  	call   0x6daa70
  4bae87:	e8 84 3e 44 00                                  	call   0x8fed10
  4bae8c:	0f b7 c0                                        	movzx  eax,ax
  4bae8f:	50                                              	push   eax
  4bae90:	6a 00                                           	push   0x0
  4bae92:	53                                              	push   ebx
  4bae93:	68 c8 0f fc 00                                  	push   0xfc0fc8
  4bae98:	b9 fc 0f fc 00                                  	mov    ecx,0xfc0ffc
  4bae9d:	e8 8e ec 21 00                                  	call   0x6d9b30
  4baea2:	8b 44 24 1c                                     	mov    eax,DWORD PTR [esp+0x1c]
  4baea6:	83 b8 bc 5e 00 00 00                            	cmp    DWORD PTR [eax+0x5ebc],0x0
  4baead:	bf e4 6e c0 00                                  	mov    edi,0xc06ee4
  4baeb2:	75 05                                           	jne    0x4baeb9
  4baeb4:	bf 0c 6f c0 00                                  	mov    edi,0xc06f0c

; literal-tail-4df5e5 EDI root immediate overwrite after +E0 lookup (reused chain)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004df5e5 <.text+0xde5e5>:
  4df5e5:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  4df5ea:	e8 91 78 01 00                                  	call   0x4f6e80
  4df5ef:	bf 01 00 00 00                                  	mov    edi,0x1

; literal-tail-4df696 EDI root immediate overwrite after +E0 lookup (reused chain)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004df696 <.text+0xde696>:
  4df696:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  4df69b:	e8 e0 77 01 00                                  	call   0x4f6e80
  4df6a0:	8b 7d 0c                                        	mov    edi,DWORD PTR [ebp+0xc]

; literal-tail-564049 EDI root overwritten with 1

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00564049 <.text+0x163049>:
  564049:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  56404e:	e8 2d 2e f9 ff                                  	call   0x4f6e80
  564053:	bf 01 00 00 00                                  	mov    edi,0x1

; literal-tail-564108 EDI root overwritten with 1

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00564108 <.text+0x163108>:
  564108:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  56410d:	e8 6e 2d f9 ff                                  	call   0x4f6e80
  564112:	bf 01 00 00 00                                  	mov    edi,0x1

; literal-tail-6d951d EDI root replaced by returned resource chars

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006d951d <.text+0x2d851d>:
  6d951d:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  6d9522:	e8 59 d9 e1 ff                                  	call   0x4f6e80
  6d9527:	8b f8                                           	mov    edi,eax

; literal-tail-6d9616 Caller retains EDI to epilogue but no explicit root field use/export

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006d9616 <.text+0x2d8616>:
  6d9616:	bf 70 74 fb 00                                  	mov    edi,0xfb7470
  6d961b:	e8 60 d8 e1 ff                                  	call   0x4f6e80
  6d9620:	8b f0                                           	mov    esi,eax
  6d9622:	85 f6                                           	test   esi,esi
  6d9624:	74 44                                           	je     0x6d966a
  6d9626:	f6 05 28 88 fb 00 01                            	test   BYTE PTR ds:0xfb8828,0x1
  6d962d:	75 27                                           	jne    0x6d9656
  6d962f:	b8 01 00 00 00                                  	mov    eax,0x1
  6d9634:	09 05 28 88 fb 00                               	or     DWORD PTR ds:0xfb8828,eax
  6d963a:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  6d963d:	e8 0e 62 e7 ff                                  	call   0x54f850
  6d9642:	68 80 d5 bc 00                                  	push   0xbcd580
  6d9647:	e8 ce 8c 1b 00                                  	call   0x89231a
  6d964c:	83 c4 04                                        	add    esp,0x4
  6d964f:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  6d9656:	0f b7 15 d6 92 fb 00                            	movzx  edx,WORD PTR ds:0xfb92d6
  6d965d:	52                                              	push   edx
  6d965e:	6a 01                                           	push   0x1
  6d9660:	56                                              	push   esi
  6d9661:	8d 4b 6c                                        	lea    ecx,[ebx+0x6c]
  6d9664:	53                                              	push   ebx
  6d9665:	e8 c6 04 00 00                                  	call   0x6d9b30
  6d966a:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  6d966d:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  6d9674:	59                                              	pop    ecx
  6d9675:	5f                                              	pop    edi
  6d9676:	5e                                              	pop    esi
  6d9677:	5b                                              	pop    ebx
  6d9678:	8b e5                                           	mov    esp,ebp
  6d967a:	5d                                              	pop    ebp
  6d967b:	c2 08 00                                        	ret    0x8

; sound-4f6630 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6630 <.text+0xf5630>:
  4f6630:	55                                              	push   ebp
  4f6631:	8b ec                                           	mov    ebp,esp
  4f6633:	6a ff                                           	push   0xffffffff
  4f6635:	68 53 46 92 00                                  	push   0x924653
  4f663a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4f6640:	50                                              	push   eax
  4f6641:	81 ec e4 00 00 00                               	sub    esp,0xe4
  4f6647:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4f664c:	33 c5                                           	xor    eax,ebp
  4f664e:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  4f6651:	53                                              	push   ebx
  4f6652:	56                                              	push   esi
  4f6653:	57                                              	push   edi
  4f6654:	50                                              	push   eax
  4f6655:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4f6658:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4f665e:	8d 85 20 ff ff ff                               	lea    eax,[ebp-0xe0]
  4f6664:	50                                              	push   eax
  4f6665:	b9 bc d5 c0 00                                  	mov    ecx,0xc0d5bc
  4f666a:	e8 c1 87 23 00                                  	call   0x72ee30
  4f666f:	33 db                                           	xor    ebx,ebx
  4f6671:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  4f6674:	8b 8d 40 ff ff ff                               	mov    ecx,DWORD PTR [ebp-0xc0]
  4f667a:	bf 10 00 00 00                                  	mov    edi,0x10
  4f667f:	39 bd 54 ff ff ff                               	cmp    DWORD PTR [ebp-0xac],edi
  4f6685:	73 06                                           	jae    0x4f668d
  4f6687:	8d 8d 40 ff ff ff                               	lea    ecx,[ebp-0xc0]
  4f668d:	53                                              	push   ebx
  4f668e:	8d b5 20 ff ff ff                               	lea    esi,[ebp-0xe0]
  4f6694:	e8 77 8a 23 00                                  	call   0x72f110
  4f6699:	84 c0                                           	test   al,al
  4f669b:	0f 84 49 02 00 00                               	je     0x4f68ea
  4f66a1:	53                                              	push   ebx
  4f66a2:	68 75 23 bf 00                                  	push   0xbf2375
  4f66a7:	8d 4d b8                                        	lea    ecx,[ebp-0x48]
  4f66aa:	c7 45 cc 0f 00 00 00                            	mov    DWORD PTR [ebp-0x34],0xf
  4f66b1:	89 5d c8                                        	mov    DWORD PTR [ebp-0x38],ebx
  4f66b4:	88 5d b8                                        	mov    BYTE PTR [ebp-0x48],bl
  4f66b7:	e8 b4 c3 f0 ff                                  	call   0x402a70
  4f66bc:	68 d4 d5 c0 00                                  	push   0xc0d5d4
  4f66c1:	8b c6                                           	mov    eax,esi
  4f66c3:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  4f66c7:	e8 14 7c 23 00                                  	call   0x72e2e0
  4f66cc:	68 e4 d5 c0 00                                  	push   0xc0d5e4
  4f66d1:	e8 0a 7c 23 00                                  	call   0x72e2e0
  4f66d6:	3b c3                                           	cmp    eax,ebx
  4f66d8:	74 49                                           	je     0x4f6723
  4f66da:	8b 10                                           	mov    edx,DWORD PTR [eax]
  4f66dc:	8b c8                                           	mov    ecx,eax
  4f66de:	8b 42 14                                        	mov    eax,DWORD PTR [edx+0x14]
  4f66e1:	ff d0                                           	call   eax
  4f66e3:	3b c3                                           	cmp    eax,ebx
  4f66e5:	74 3c                                           	je     0x4f6723
  4f66e7:	68 f0 d5 c0 00                                  	push   0xc0d5f0
  4f66ec:	8d 78 44                                        	lea    edi,[eax+0x44]
  4f66ef:	e8 ac 99 23 00                                  	call   0x7300a0
  4f66f4:	3b c3                                           	cmp    eax,ebx
  4f66f6:	74 0d                                           	je     0x4f6705
  4f66f8:	83 78 44 10                                     	cmp    DWORD PTR [eax+0x44],0x10
  4f66fc:	8d 50 30                                        	lea    edx,[eax+0x30]
  4f66ff:	72 06                                           	jb     0x4f6707
  4f6701:	8b 12                                           	mov    edx,DWORD PTR [edx]
  4f6703:	eb 02                                           	jmp    0x4f6707
  4f6705:	33 d2                                           	xor    edx,edx
  4f6707:	8b c2                                           	mov    eax,edx
  4f6709:	8d 70 01                                        	lea    esi,[eax+0x1]
  4f670c:	8d 64 24 00                                     	lea    esp,[esp+0x0]
  4f6710:	8a 08                                           	mov    cl,BYTE PTR [eax]
  4f6712:	40                                              	inc    eax
  4f6713:	84 c9                                           	test   cl,cl
  4f6715:	75 f9                                           	jne    0x4f6710
  4f6717:	2b c6                                           	sub    eax,esi
  4f6719:	50                                              	push   eax
  4f671a:	52                                              	push   edx
  4f671b:	8d 4d b8                                        	lea    ecx,[ebp-0x48]
  4f671e:	e8 4d c3 f0 ff                                  	call   0x402a70
  4f6723:	68 d4 d5 c0 00                                  	push   0xc0d5d4
  4f6728:	8d 85 20 ff ff ff                               	lea    eax,[ebp-0xe0]
  4f672e:	e8 ad 7b 23 00                                  	call   0x72e2e0
  4f6733:	68 f8 d5 c0 00                                  	push   0xc0d5f8
  4f6738:	e8 a3 7b 23 00                                  	call   0x72e2e0
  4f673d:	8b f0                                           	mov    esi,eax
  4f673f:	89 85 1c ff ff ff                               	mov    DWORD PTR [ebp-0xe4],eax
  4f6745:	3b f3                                           	cmp    esi,ebx
  4f6747:	0f 84 79 01 00 00                               	je     0x4f68c6
  4f674d:	eb 07                                           	jmp    0x4f6756
  4f674f:	90                                              	nop
  4f6750:	8b b5 1c ff ff ff                               	mov    esi,DWORD PTR [ebp-0xe4]
  4f6756:	8b 16                                           	mov    edx,DWORD PTR [esi]
  4f6758:	8b 42 14                                        	mov    eax,DWORD PTR [edx+0x14]
  4f675b:	8b ce                                           	mov    ecx,esi
  4f675d:	ff d0                                           	call   eax
  4f675f:	3b c3                                           	cmp    eax,ebx
  4f6761:	0f 84 4e 01 00 00                               	je     0x4f68b5
  4f6767:	8d 78 44                                        	lea    edi,[eax+0x44]
  4f676a:	68 00 d6 c0 00                                  	push   0xc0d600
  4f676f:	e8 2c 99 23 00                                  	call   0x7300a0
  4f6774:	3b c3                                           	cmp    eax,ebx
  4f6776:	74 1c                                           	je     0x4f6794
  4f6778:	83 c0 30                                        	add    eax,0x30
  4f677b:	83 78 14 10                                     	cmp    DWORD PTR [eax+0x14],0x10
  4f677f:	72 02                                           	jb     0x4f6783
  4f6781:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f6783:	3b c3                                           	cmp    eax,ebx
  4f6785:	74 0d                                           	je     0x4f6794
  4f6787:	50                                              	push   eax
  4f6788:	e8 27 b0 39 00                                  	call   0x8917b4
  4f678d:	83 c4 04                                        	add    esp,0x4
  4f6790:	8b f0                                           	mov    esi,eax
  4f6792:	eb 02                                           	jmp    0x4f6796
  4f6794:	33 f6                                           	xor    esi,esi
  4f6796:	68 08 d6 c0 00                                  	push   0xc0d608
  4f679b:	e8 00 99 23 00                                  	call   0x7300a0
  4f67a0:	3b c3                                           	cmp    eax,ebx
  4f67a2:	74 1a                                           	je     0x4f67be
  4f67a4:	83 c0 30                                        	add    eax,0x30
  4f67a7:	83 78 14 10                                     	cmp    DWORD PTR [eax+0x14],0x10
  4f67ab:	72 02                                           	jb     0x4f67af
  4f67ad:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f67af:	3b c3                                           	cmp    eax,ebx
  4f67b1:	74 0b                                           	je     0x4f67be
  4f67b3:	50                                              	push   eax
  4f67b4:	e8 fb af 39 00                                  	call   0x8917b4
  4f67b9:	83 c4 04                                        	add    esp,0x4
  4f67bc:	8b d8                                           	mov    ebx,eax
  4f67be:	6a ff                                           	push   0xffffffff
  4f67c0:	6a 00                                           	push   0x0
  4f67c2:	8d 4d b8                                        	lea    ecx,[ebp-0x48]
  4f67c5:	51                                              	push   ecx
  4f67c6:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  4f67c9:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  4f67d0:	c7 45 e4 00 00 00 00                            	mov    DWORD PTR [ebp-0x1c],0x0
  4f67d7:	c6 45 d4 00                                     	mov    BYTE PTR [ebp-0x2c],0x0
  4f67db:	e8 60 c8 f0 ff                                  	call   0x403040
  4f67e0:	68 1c 56 c0 00                                  	push   0xc0561c
  4f67e5:	c6 45 fc 02                                     	mov    BYTE PTR [ebp-0x4],0x2
  4f67e9:	e8 b2 98 23 00                                  	call   0x7300a0
  4f67ee:	85 c0                                           	test   eax,eax
  4f67f0:	74 0d                                           	je     0x4f67ff
  4f67f2:	83 78 44 10                                     	cmp    DWORD PTR [eax+0x44],0x10
  4f67f6:	8d 78 30                                        	lea    edi,[eax+0x30]
  4f67f9:	72 06                                           	jb     0x4f6801
  4f67fb:	8b 3f                                           	mov    edi,DWORD PTR [edi]
  4f67fd:	eb 02                                           	jmp    0x4f6801
  4f67ff:	33 ff                                           	xor    edi,edi
  4f6801:	8b c7                                           	mov    eax,edi
  4f6803:	8d 48 01                                        	lea    ecx,[eax+0x1]
  4f6806:	8a 10                                           	mov    dl,BYTE PTR [eax]
  4f6808:	40                                              	inc    eax
  4f6809:	84 d2                                           	test   dl,dl
  4f680b:	75 f9                                           	jne    0x4f6806
  4f680d:	2b c1                                           	sub    eax,ecx
  4f680f:	50                                              	push   eax
  4f6810:	57                                              	push   edi
  4f6811:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  4f6814:	e8 a7 b7 f0 ff                                  	call   0x401fc0
  4f6819:	83 e6 1f                                        	and    esi,0x1f
  4f681c:	03 f6                                           	add    esi,esi
  4f681e:	03 f6                                           	add    esi,esi
  4f6820:	6a ff                                           	push   0xffffffff
  4f6822:	83 e3 07                                        	and    ebx,0x7
  4f6825:	33 ff                                           	xor    edi,edi
  4f6827:	8d 04 36                                        	lea    eax,[esi+esi*1]
  4f682a:	0b c3                                           	or     eax,ebx
  4f682c:	57                                              	push   edi
  4f682d:	8d 55 d4                                        	lea    edx,[ebp-0x2c]
  4f6830:	bb 0f 00 00 00                                  	mov    ebx,0xf
  4f6835:	52                                              	push   edx
  4f6836:	8d 4d 9c                                        	lea    ecx,[ebp-0x64]
  4f6839:	88 45 98                                        	mov    BYTE PTR [ebp-0x68],al
  4f683c:	89 5d b0                                        	mov    DWORD PTR [ebp-0x50],ebx
  4f683f:	89 7d ac                                        	mov    DWORD PTR [ebp-0x54],edi
  4f6842:	c6 45 9c 00                                     	mov    BYTE PTR [ebp-0x64],0x0
  4f6846:	e8 f5 c7 f0 ff                                  	call   0x403040
  4f684b:	8d 45 98                                        	lea    eax,[ebp-0x68]
  4f684e:	50                                              	push   eax
  4f684f:	b9 10 75 fb 00                                  	mov    ecx,0xfb7510
  4f6854:	c6 45 fc 03                                     	mov    BYTE PTR [ebp-0x4],0x3
  4f6858:	e8 03 32 00 00                                  	call   0x4f9a60
  4f685d:	50                                              	push   eax
  4f685e:	68 10 75 fb 00                                  	push   0xfb7510
  4f6863:	8d b5 14 ff ff ff                               	lea    esi,[ebp-0xec]
  4f6869:	e8 42 28 00 00                                  	call   0x4f90b0
  4f686e:	be 10 00 00 00                                  	mov    esi,0x10
  4f6873:	39 75 b0                                        	cmp    DWORD PTR [ebp-0x50],esi
  4f6876:	72 0c                                           	jb     0x4f6884
  4f6878:	8b 4d 9c                                        	mov    ecx,DWORD PTR [ebp-0x64]
  4f687b:	51                                              	push   ecx
  4f687c:	e8 8b a9 39 00                                  	call   0x89120c
  4f6881:	83 c4 04                                        	add    esp,0x4
  4f6884:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  4f6888:	89 5d b0                                        	mov    DWORD PTR [ebp-0x50],ebx
  4f688b:	89 7d ac                                        	mov    DWORD PTR [ebp-0x54],edi
  4f688e:	c6 45 9c 00                                     	mov    BYTE PTR [ebp-0x64],0x0
  4f6892:	39 75 e8                                        	cmp    DWORD PTR [ebp-0x18],esi
  4f6895:	72 0c                                           	jb     0x4f68a3
  4f6897:	8b 55 d4                                        	mov    edx,DWORD PTR [ebp-0x2c]
  4f689a:	52                                              	push   edx
  4f689b:	e8 6c a9 39 00                                  	call   0x89120c
  4f68a0:	83 c4 04                                        	add    esp,0x4
  4f68a3:	8b b5 1c ff ff ff                               	mov    esi,DWORD PTR [ebp-0xe4]
  4f68a9:	89 5d e8                                        	mov    DWORD PTR [ebp-0x18],ebx
  4f68ac:	89 7d e4                                        	mov    DWORD PTR [ebp-0x1c],edi
  4f68af:	c6 45 d4 00                                     	mov    BYTE PTR [ebp-0x2c],0x0
  4f68b3:	33 db                                           	xor    ebx,ebx
  4f68b5:	8b 76 40                                        	mov    esi,DWORD PTR [esi+0x40]
  4f68b8:	89 b5 1c ff ff ff                               	mov    DWORD PTR [ebp-0xe4],esi
  4f68be:	3b f3                                           	cmp    esi,ebx
  4f68c0:	0f 85 8a fe ff ff                               	jne    0x4f6750
  4f68c6:	bf 10 00 00 00                                  	mov    edi,0x10
  4f68cb:	39 7d cc                                        	cmp    DWORD PTR [ebp-0x34],edi
  4f68ce:	72 0c                                           	jb     0x4f68dc
  4f68d0:	8b 45 b8                                        	mov    eax,DWORD PTR [ebp-0x48]
  4f68d3:	50                                              	push   eax
  4f68d4:	e8 33 a9 39 00                                  	call   0x89120c
  4f68d9:	83 c4 04                                        	add    esp,0x4
  4f68dc:	c7 45 cc 0f 00 00 00                            	mov    DWORD PTR [ebp-0x34],0xf
  4f68e3:	89 5d c8                                        	mov    DWORD PTR [ebp-0x38],ebx
  4f68e6:	c6 45 b8 00                                     	mov    BYTE PTR [ebp-0x48],0x0
  4f68ea:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  4f68f1:	c7 85 20 ff ff ff 94 23 bf 00                   	mov    DWORD PTR [ebp-0xe0],0xbf2394
  4f68fb:	39 7d 80                                        	cmp    DWORD PTR [ebp-0x80],edi
  4f68fe:	72 0f                                           	jb     0x4f690f
  4f6900:	8b 8d 6c ff ff ff                               	mov    ecx,DWORD PTR [ebp-0x94]
  4f6906:	51                                              	push   ecx
  4f6907:	e8 00 a9 39 00                                  	call   0x89120c
  4f690c:	83 c4 04                                        	add    esp,0x4
  4f690f:	8d 8d 20 ff ff ff                               	lea    ecx,[ebp-0xe0]
  4f6915:	c7 45 80 0f 00 00 00                            	mov    DWORD PTR [ebp-0x80],0xf
  4f691c:	89 9d 7c ff ff ff                               	mov    DWORD PTR [ebp-0x84],ebx
  4f6922:	c6 85 6c ff ff ff 00                            	mov    BYTE PTR [ebp-0x94],0x0
  4f6929:	e8 12 77 23 00                                  	call   0x72e040
  4f692e:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4f6931:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4f6938:	59                                              	pop    ecx
  4f6939:	5f                                              	pop    edi
  4f693a:	5e                                              	pop    esi
  4f693b:	5b                                              	pop    ebx
  4f693c:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  4f693f:	33 cd                                           	xor    ecx,ebp
  4f6941:	e8 bb a6 39 00                                  	call   0x891001
  4f6946:	8b e5                                           	mov    esp,ebp
  4f6948:	5d                                              	pop    ebp
  4f6949:	c3                                              	ret
  4f694a:	cc                                              	int3
  4f694b:	cc                                              	int3
  4f694c:	cc                                              	int3
  4f694d:	cc                                              	int3
  4f694e:	cc                                              	int3
  4f694f:	cc                                              	int3

; sound-4f6f70 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6f70 <.text+0xf5f70>:
  4f6f70:	55                                              	push   ebp
  4f6f71:	8b ec                                           	mov    ebp,esp
  4f6f73:	8b 8e a4 00 00 00                               	mov    ecx,DWORD PTR [esi+0xa4]
  4f6f79:	8b 41 04                                        	mov    eax,DWORD PTR [ecx+0x4]
  4f6f7c:	83 ec 08                                        	sub    esp,0x8
  4f6f7f:	80 78 2d 00                                     	cmp    BYTE PTR [eax+0x2d],0x0
  4f6f83:	75 14                                           	jne    0x4f6f99
  4f6f85:	38 50 0c                                        	cmp    BYTE PTR [eax+0xc],dl
  4f6f88:	7d 05                                           	jge    0x4f6f8f
  4f6f8a:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  4f6f8d:	eb 04                                           	jmp    0x4f6f93
  4f6f8f:	8b c8                                           	mov    ecx,eax
  4f6f91:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f6f93:	80 78 2d 00                                     	cmp    BYTE PTR [eax+0x2d],0x0
  4f6f97:	74 ec                                           	je     0x4f6f85
  4f6f99:	8b 86 a4 00 00 00                               	mov    eax,DWORD PTR [esi+0xa4]
  4f6f9f:	89 4d fc                                        	mov    DWORD PTR [ebp-0x4],ecx
  4f6fa2:	3b c8                                           	cmp    ecx,eax
  4f6fa4:	74 0a                                           	je     0x4f6fb0
  4f6fa6:	3a 51 0c                                        	cmp    dl,BYTE PTR [ecx+0xc]
  4f6fa9:	7c 05                                           	jl     0x4f6fb0
  4f6fab:	8d 45 fc                                        	lea    eax,[ebp-0x4]
  4f6fae:	eb 06                                           	jmp    0x4f6fb6
  4f6fb0:	89 45 f8                                        	mov    DWORD PTR [ebp-0x8],eax
  4f6fb3:	8d 45 f8                                        	lea    eax,[ebp-0x8]
  4f6fb6:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f6fb8:	3b 86 a4 00 00 00                               	cmp    eax,DWORD PTR [esi+0xa4]
  4f6fbe:	75 06                                           	jne    0x4f6fc6
  4f6fc0:	33 c0                                           	xor    eax,eax
  4f6fc2:	8b e5                                           	mov    esp,ebp
  4f6fc4:	5d                                              	pop    ebp
  4f6fc5:	c3                                              	ret
  4f6fc6:	83 c0 10                                        	add    eax,0x10
  4f6fc9:	83 78 14 10                                     	cmp    DWORD PTR [eax+0x14],0x10
  4f6fcd:	72 02                                           	jb     0x4f6fd1
  4f6fcf:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f6fd1:	8b e5                                           	mov    esp,ebp
  4f6fd3:	5d                                              	pop    ebp
  4f6fd4:	c3                                              	ret
  4f6fd5:	cc                                              	int3
  4f6fd6:	cc                                              	int3
  4f6fd7:	cc                                              	int3
  4f6fd8:	cc                                              	int3
  4f6fd9:	cc                                              	int3
  4f6fda:	cc                                              	int3
  4f6fdb:	cc                                              	int3
  4f6fdc:	cc                                              	int3
  4f6fdd:	cc                                              	int3
  4f6fde:	cc                                              	int3
  4f6fdf:	cc                                              	int3

; sound-4f9a60 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f9a60 <.text+0xf8a60>:
  4f9a60:	55                                              	push   ebp
  4f9a61:	8b ec                                           	mov    ebp,esp
  4f9a63:	6a ff                                           	push   0xffffffff
  4f9a65:	68 a1 74 91 00                                  	push   0x9174a1
  4f9a6a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4f9a70:	50                                              	push   eax
  4f9a71:	83 ec 18                                        	sub    esp,0x18
  4f9a74:	53                                              	push   ebx
  4f9a75:	56                                              	push   esi
  4f9a76:	57                                              	push   edi
  4f9a77:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4f9a7c:	33 c5                                           	xor    eax,ebp
  4f9a7e:	50                                              	push   eax
  4f9a7f:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4f9a82:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4f9a88:	89 65 f0                                        	mov    DWORD PTR [ebp-0x10],esp
  4f9a8b:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  4f9a8e:	8b f9                                           	mov    edi,ecx
  4f9a90:	6a 30                                           	push   0x30
  4f9a92:	e8 d1 77 39 00                                  	call   0x891268
  4f9a97:	8b f0                                           	mov    esi,eax
  4f9a99:	33 d2                                           	xor    edx,edx
  4f9a9b:	83 c4 04                                        	add    esp,0x4
  4f9a9e:	89 75 08                                        	mov    DWORD PTR [ebp+0x8],esi
  4f9aa1:	3b f2                                           	cmp    esi,edx
  4f9aa3:	74 70                                           	je     0x4f9b15
  4f9aa5:	8b 47 04                                        	mov    eax,DWORD PTR [edi+0x4]
  4f9aa8:	89 06                                           	mov    DWORD PTR [esi],eax
  4f9aaa:	8b 4f 04                                        	mov    ecx,DWORD PTR [edi+0x4]
  4f9aad:	89 4e 04                                        	mov    DWORD PTR [esi+0x4],ecx
  4f9ab0:	8b 47 04                                        	mov    eax,DWORD PTR [edi+0x4]
  4f9ab3:	89 46 08                                        	mov    DWORD PTR [esi+0x8],eax
  4f9ab6:	8d 46 0c                                        	lea    eax,[esi+0xc]
  4f9ab9:	89 55 fc                                        	mov    DWORD PTR [ebp-0x4],edx
  4f9abc:	66 89 56 2c                                     	mov    WORD PTR [esi+0x2c],dx
  4f9ac0:	89 45 ec                                        	mov    DWORD PTR [ebp-0x14],eax
  4f9ac3:	89 45 e8                                        	mov    DWORD PTR [ebp-0x18],eax
  4f9ac6:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  4f9aca:	3b c2                                           	cmp    eax,edx
  4f9acc:	74 1c                                           	je     0x4f9aea
  4f9ace:	8a 0b                                           	mov    cl,BYTE PTR [ebx]
  4f9ad0:	88 08                                           	mov    BYTE PTR [eax],cl
  4f9ad2:	8d 48 04                                        	lea    ecx,[eax+0x4]
  4f9ad5:	83 c3 04                                        	add    ebx,0x4
  4f9ad8:	c7 41 14 0f 00 00 00                            	mov    DWORD PTR [ecx+0x14],0xf
  4f9adf:	89 51 10                                        	mov    DWORD PTR [ecx+0x10],edx
  4f9ae2:	53                                              	push   ebx
  4f9ae3:	88 11                                           	mov    BYTE PTR [ecx],dl
  4f9ae5:	e8 c6 90 f0 ff                                  	call   0x402bb0
  4f9aea:	8b c6                                           	mov    eax,esi
  4f9aec:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4f9aef:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4f9af6:	59                                              	pop    ecx
  4f9af7:	5f                                              	pop    edi
  4f9af8:	5e                                              	pop    esi
  4f9af9:	5b                                              	pop    ebx
  4f9afa:	8b e5                                           	mov    esp,ebp
  4f9afc:	5d                                              	pop    ebp
  4f9afd:	c2 04 00                                        	ret    0x4

; sound-4f90b0 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f90b0 <.text+0xf80b0>:
  4f90b0:	55                                              	push   ebp
  4f90b1:	8b ec                                           	mov    ebp,esp
  4f90b3:	51                                              	push   ecx
  4f90b4:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  4f90b7:	53                                              	push   ebx
  4f90b8:	8b 5d 0c                                        	mov    ebx,DWORD PTR [ebp+0xc]
  4f90bb:	57                                              	push   edi
  4f90bc:	8b 7a 04                                        	mov    edi,DWORD PTR [edx+0x4]
  4f90bf:	8b 47 04                                        	mov    eax,DWORD PTR [edi+0x4]
  4f90c2:	80 78 2d 00                                     	cmp    BYTE PTR [eax+0x2d],0x0
  4f90c6:	b1 01                                           	mov    cl,0x1
  4f90c8:	88 4d fc                                        	mov    BYTE PTR [ebp-0x4],cl
  4f90cb:	75 22                                           	jne    0x4f90ef
  4f90cd:	8a 4b 0c                                        	mov    cl,BYTE PTR [ebx+0xc]
  4f90d0:	8a 4b 0c                                        	mov    cl,BYTE PTR [ebx+0xc]
  4f90d3:	3a 48 0c                                        	cmp    cl,BYTE PTR [eax+0xc]
  4f90d6:	8b f8                                           	mov    edi,eax
  4f90d8:	0f 9c c1                                        	setl   cl
  4f90db:	88 4d fc                                        	mov    BYTE PTR [ebp-0x4],cl
  4f90de:	84 c9                                           	test   cl,cl
  4f90e0:	74 04                                           	je     0x4f90e6
  4f90e2:	8b 00                                           	mov    eax,DWORD PTR [eax]
  4f90e4:	eb 03                                           	jmp    0x4f90e9
  4f90e6:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  4f90e9:	80 78 2d 00                                     	cmp    BYTE PTR [eax+0x2d],0x0
  4f90ed:	74 e1                                           	je     0x4f90d0
  4f90ef:	89 7d 0c                                        	mov    DWORD PTR [ebp+0xc],edi
  4f90f2:	84 c9                                           	test   cl,cl
  4f90f4:	74 34                                           	je     0x4f912a
  4f90f6:	8b 42 04                                        	mov    eax,DWORD PTR [edx+0x4]
  4f90f9:	3b 38                                           	cmp    edi,DWORD PTR [eax]
  4f90fb:	75 22                                           	jne    0x4f911f
  4f90fd:	53                                              	push   ebx
  4f90fe:	6a 01                                           	push   0x1
  4f9100:	8d 4d 08                                        	lea    ecx,[ebp+0x8]
  4f9103:	8b c7                                           	mov    eax,edi
  4f9105:	51                                              	push   ecx
  4f9106:	8b fa                                           	mov    edi,edx
  4f9108:	e8 d3 03 00 00                                  	call   0x4f94e0
  4f910d:	8b 10                                           	mov    edx,DWORD PTR [eax]
  4f910f:	5f                                              	pop    edi
  4f9110:	89 16                                           	mov    DWORD PTR [esi],edx
  4f9112:	c6 46 04 01                                     	mov    BYTE PTR [esi+0x4],0x1
  4f9116:	8b c6                                           	mov    eax,esi
  4f9118:	5b                                              	pop    ebx
  4f9119:	8b e5                                           	mov    esp,ebp
  4f911b:	5d                                              	pop    ebp
  4f911c:	c2 08 00                                        	ret    0x8
  4f911f:	8d 45 0c                                        	lea    eax,[ebp+0xc]
  4f9122:	e8 59 bd 07 00                                  	call   0x574e80
  4f9127:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  4f912a:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  4f912d:	8a 48 0c                                        	mov    cl,BYTE PTR [eax+0xc]
  4f9130:	3a 4b 0c                                        	cmp    cl,BYTE PTR [ebx+0xc]
  4f9133:	7d 07                                           	jge    0x4f913c
  4f9135:	8b 45 fc                                        	mov    eax,DWORD PTR [ebp-0x4]
  4f9138:	53                                              	push   ebx
  4f9139:	50                                              	push   eax
  4f913a:	eb c4                                           	jmp    0x4f9100
  4f913c:	83 7b 24 10                                     	cmp    DWORD PTR [ebx+0x24],0x10
  4f9140:	72 0c                                           	jb     0x4f914e
  4f9142:	8b 43 10                                        	mov    eax,DWORD PTR [ebx+0x10]
  4f9145:	50                                              	push   eax
  4f9146:	e8 c1 80 39 00                                  	call   0x89120c
  4f914b:	83 c4 04                                        	add    esp,0x4
  4f914e:	c7 43 24 0f 00 00 00                            	mov    DWORD PTR [ebx+0x24],0xf
  4f9155:	c7 43 20 00 00 00 00                            	mov    DWORD PTR [ebx+0x20],0x0
  4f915c:	53                                              	push   ebx
  4f915d:	c6 43 10 00                                     	mov    BYTE PTR [ebx+0x10],0x0
  4f9161:	e8 a6 80 39 00                                  	call   0x89120c
  4f9166:	8b 4d 0c                                        	mov    ecx,DWORD PTR [ebp+0xc]
  4f9169:	83 c4 04                                        	add    esp,0x4
  4f916c:	5f                                              	pop    edi
  4f916d:	89 0e                                           	mov    DWORD PTR [esi],ecx
  4f916f:	c6 46 04 00                                     	mov    BYTE PTR [esi+0x4],0x0
  4f9173:	8b c6                                           	mov    eax,esi
  4f9175:	5b                                              	pop    ebx
  4f9176:	8b e5                                           	mov    esp,ebp
  4f9178:	5d                                              	pop    ebp
  4f9179:	c2 08 00                                        	ret    0x8
  4f917c:	cc                                              	int3
  4f917d:	cc                                              	int3
  4f917e:	cc                                              	int3
  4f917f:	cc                                              	int3

; sound-5521d0 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005521d0 <.text+0x1511d0>:
  5521d0:	55                                              	push   ebp
  5521d1:	8b ec                                           	mov    ebp,esp
  5521d3:	6a ff                                           	push   0xffffffff
  5521d5:	68 cc 96 92 00                                  	push   0x9296cc
  5521da:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  5521e0:	50                                              	push   eax
  5521e1:	51                                              	push   ecx
  5521e2:	53                                              	push   ebx
  5521e3:	56                                              	push   esi
  5521e4:	57                                              	push   edi
  5521e5:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  5521ea:	33 c5                                           	xor    eax,ebp
  5521ec:	50                                              	push   eax
  5521ed:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  5521f0:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  5521f6:	8b 45 18                                        	mov    eax,DWORD PTR [ebp+0x18]
  5521f9:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  5521fc:	33 f6                                           	xor    esi,esi
  5521fe:	8b d3                                           	mov    edx,ebx
  552200:	39 75 0c                                        	cmp    DWORD PTR [ebp+0xc],esi
  552203:	74 0a                                           	je     0x55220f
  552205:	48                                              	dec    eax
  552206:	50                                              	push   eax
  552207:	56                                              	push   esi
  552208:	b9 a4 fe c0 00                                  	mov    ecx,0xc0fea4
  55220d:	eb 08                                           	jmp    0x552217
  55220f:	6a ff                                           	push   0xffffffff
  552211:	50                                              	push   eax
  552212:	b9 b4 fe c0 00                                  	mov    ecx,0xc0feb4
  552217:	e8 64 f9 ff ff                                  	call   0x551b80
  55221c:	8b f8                                           	mov    edi,eax
  55221e:	3b fe                                           	cmp    edi,esi
  552220:	0f 84 23 01 00 00                               	je     0x552349
  552226:	6a 7c                                           	push   0x7c
  552228:	e8 3b f0 33 00                                  	call   0x891268
  55222d:	83 c4 04                                        	add    esp,0x4
  552230:	3b c6                                           	cmp    eax,esi
  552232:	74 20                                           	je     0x552254
  552234:	89 70 24                                        	mov    DWORD PTR [eax+0x24],esi
  552237:	89 70 28                                        	mov    DWORD PTR [eax+0x28],esi
  55223a:	89 70 6c                                        	mov    DWORD PTR [eax+0x6c],esi
  55223d:	c7 40 74 01 00 00 00                            	mov    DWORD PTR [eax+0x74],0x1
  552244:	c7 40 78 1e 00 00 00                            	mov    DWORD PTR [eax+0x78],0x1e
  55224b:	c6 40 2c 00                                     	mov    BYTE PTR [eax+0x2c],0x0
  55224f:	89 45 18                                        	mov    DWORD PTR [ebp+0x18],eax
  552252:	eb 03                                           	jmp    0x552257
  552254:	89 75 18                                        	mov    DWORD PTR [ebp+0x18],esi
  552257:	f6 05 b0 75 fb 00 01                            	test   BYTE PTR ds:0xfb75b0,0x1
  55225e:	8b 45 18                                        	mov    eax,DWORD PTR [ebp+0x18]
  552261:	89 45 08                                        	mov    DWORD PTR [ebp+0x8],eax
  552264:	75 23                                           	jne    0x552289
  552266:	83 0d b0 75 fb 00 01                            	or     DWORD PTR ds:0xfb75b0,0x1
  55226d:	89 75 fc                                        	mov    DWORD PTR [ebp-0x4],esi
  552270:	e8 0b 1b fa ff                                  	call   0x4f3d80
  552275:	68 e0 d1 bc 00                                  	push   0xbcd1e0
  55227a:	e8 9b 00 34 00                                  	call   0x89231a
  55227f:	83 c4 04                                        	add    esp,0x4
  552282:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  552289:	8a 55 1c                                        	mov    dl,BYTE PTR [ebp+0x1c]
  55228c:	be 70 74 fb 00                                  	mov    esi,0xfb7470
  552291:	e8 da 4c fa ff                                  	call   0x4f6f70
  552296:	f6 05 28 88 fb 00 01                            	test   BYTE PTR ds:0xfb8828,0x1
  55229d:	8b f0                                           	mov    esi,eax
  55229f:	75 27                                           	jne    0x5522c8
  5522a1:	b8 01 00 00 00                                  	mov    eax,0x1
  5522a6:	09 05 28 88 fb 00                               	or     DWORD PTR ds:0xfb8828,eax
  5522ac:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  5522af:	e8 9c d5 ff ff                                  	call   0x54f850
  5522b4:	68 80 d5 bc 00                                  	push   0xbcd580
  5522b9:	e8 5c 00 34 00                                  	call   0x89231a
  5522be:	83 c4 04                                        	add    esp,0x4
  5522c1:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  5522c8:	83 7f 14 10                                     	cmp    DWORD PTR [edi+0x14],0x10
  5522cc:	72 04                                           	jb     0x5522d2
  5522ce:	8b 07                                           	mov    eax,DWORD PTR [edi]
  5522d0:	eb 02                                           	jmp    0x5522d4
  5522d2:	8b c7                                           	mov    eax,edi
  5522d4:	d9 05 bc 90 fb 00                               	fld    DWORD PTR ds:0xfb90bc
  5522da:	8b 4d 14                                        	mov    ecx,DWORD PTR [ebp+0x14]
  5522dd:	8b 7d 10                                        	mov    edi,DWORD PTR [ebp+0x10]
  5522e0:	8b 55 18                                        	mov    edx,DWORD PTR [ebp+0x18]
  5522e3:	83 ec 08                                        	sub    esp,0x8
  5522e6:	d9 5c 24 04                                     	fstp   DWORD PTR [esp+0x4]
  5522ea:	d9 ee                                           	fldz
  5522ec:	d9 1c 24                                        	fstp   DWORD PTR [esp]
  5522ef:	51                                              	push   ecx
  5522f0:	56                                              	push   esi
  5522f1:	50                                              	push   eax
  5522f2:	b9 01 00 00 00                                  	mov    ecx,0x1
  5522f7:	e8 84 e2 ff ff                                  	call   0x550580
  5522fc:	8b 73 04                                        	mov    esi,DWORD PTR [ebx+0x4]
  5522ff:	8b 46 04                                        	mov    eax,DWORD PTR [esi+0x4]
  552302:	8d 55 08                                        	lea    edx,[ebp+0x8]
  552305:	52                                              	push   edx
  552306:	50                                              	push   eax
  552307:	56                                              	push   esi
  552308:	e8 f3 b3 1f 00                                  	call   0x74d700
  55230d:	8b 4b 08                                        	mov    ecx,DWORD PTR [ebx+0x8]
  552310:	ba fe ff ff 3f                                  	mov    edx,0x3ffffffe
  552315:	2b d1                                           	sub    edx,ecx
  552317:	83 fa 01                                        	cmp    edx,0x1
  55231a:	73 0a                                           	jae    0x552326
  55231c:	68 34 20 bf 00                                  	push   0xbf2034
  552321:	e8 0a b8 32 00                                  	call   0x87db30
  552326:	41                                              	inc    ecx
  552327:	89 4b 08                                        	mov    DWORD PTR [ebx+0x8],ecx
  55232a:	89 46 04                                        	mov    DWORD PTR [esi+0x4],eax
  55232d:	8b 48 04                                        	mov    ecx,DWORD PTR [eax+0x4]
  552330:	89 01                                           	mov    DWORD PTR [ecx],eax
  552332:	8b 45 18                                        	mov    eax,DWORD PTR [ebp+0x18]
  552335:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  552338:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  55233f:	59                                              	pop    ecx
  552340:	5f                                              	pop    edi
  552341:	5e                                              	pop    esi
  552342:	5b                                              	pop    ebx
  552343:	8b e5                                           	mov    esp,ebp
  552345:	5d                                              	pop    ebp
  552346:	c2 18 00                                        	ret    0x18
  552349:	33 c0                                           	xor    eax,eax
  55234b:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  55234e:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  552355:	59                                              	pop    ecx
  552356:	5f                                              	pop    edi
  552357:	5e                                              	pop    esi
  552358:	5b                                              	pop    ebx
  552359:	8b e5                                           	mov    esp,ebp
  55235b:	5d                                              	pop    ebp
  55235c:	c2 18 00                                        	ret    0x18
  55235f:	cc                                              	int3

; sound-550580 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00550580 <.text+0x14f580>:
  550580:	55                                              	push   ebp
  550581:	8b ec                                           	mov    ebp,esp
  550583:	6a ff                                           	push   0xffffffff
  550585:	68 6e df 91 00                                  	push   0x91df6e
  55058a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  550590:	50                                              	push   eax
  550591:	83 ec 0c                                        	sub    esp,0xc
  550594:	53                                              	push   ebx
  550595:	56                                              	push   esi
  550596:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  55059b:	33 c5                                           	xor    eax,ebp
  55059d:	50                                              	push   eax
  55059e:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  5505a1:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  5505a7:	8b 5d 0c                                        	mov    ebx,DWORD PTR [ebp+0xc]
  5505aa:	8b f2                                           	mov    esi,edx
  5505ac:	8b 45 10                                        	mov    eax,DWORD PTR [ebp+0x10]
  5505af:	0f 57 c0                                        	xorps  xmm0,xmm0
  5505b2:	89 46 6c                                        	mov    DWORD PTR [esi+0x6c],eax
  5505b5:	89 4e 70                                        	mov    DWORD PTR [esi+0x70],ecx
  5505b8:	c7 46 74 00 00 00 00                            	mov    DWORD PTR [esi+0x74],0x0
  5505bf:	8b 17                                           	mov    edx,DWORD PTR [edi]
  5505c1:	89 16                                           	mov    DWORD PTR [esi],edx
  5505c3:	8b 47 04                                        	mov    eax,DWORD PTR [edi+0x4]
  5505c6:	f3 0f 11 45 e8                                  	movss  DWORD PTR [ebp-0x18],xmm0
  5505cb:	8b 55 e8                                        	mov    edx,DWORD PTR [ebp-0x18]
  5505ce:	f3 0f 11 45 ec                                  	movss  DWORD PTR [ebp-0x14],xmm0
  5505d3:	f3 0f 10 45 14                                  	movss  xmm0,DWORD PTR [ebp+0x14]
  5505d8:	89 46 04                                        	mov    DWORD PTR [esi+0x4],eax
  5505db:	8b 4f 08                                        	mov    ecx,DWORD PTR [edi+0x8]
  5505de:	8b 45 ec                                        	mov    eax,DWORD PTR [ebp-0x14]
  5505e1:	f3 0f 11 45 f0                                  	movss  DWORD PTR [ebp-0x10],xmm0
  5505e6:	f3 0f 10 45 18                                  	movss  xmm0,DWORD PTR [ebp+0x18]
  5505eb:	89 56 0c                                        	mov    DWORD PTR [esi+0xc],edx
  5505ee:	f3 0f 11 45 e8                                  	movss  DWORD PTR [ebp-0x18],xmm0
  5505f3:	8b 55 e8                                        	mov    edx,DWORD PTR [ebp-0x18]
  5505f6:	89 56 18                                        	mov    DWORD PTR [esi+0x18],edx
  5505f9:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  5505fc:	89 46 10                                        	mov    DWORD PTR [esi+0x10],eax
  5505ff:	89 4e 08                                        	mov    DWORD PTR [esi+0x8],ecx
  550602:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  550605:	f3 0f 11 45 ec                                  	movss  DWORD PTR [ebp-0x14],xmm0
  55060a:	8b 45 ec                                        	mov    eax,DWORD PTR [ebp-0x14]
  55060d:	52                                              	push   edx
  55060e:	89 46 1c                                        	mov    DWORD PTR [esi+0x1c],eax
  550611:	89 4e 14                                        	mov    DWORD PTR [esi+0x14],ecx
  550614:	f3 0f 11 45 f0                                  	movss  DWORD PTR [ebp-0x10],xmm0
  550619:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  55061c:	8d 46 2c                                        	lea    eax,[esi+0x2c]
  55061f:	6a 40                                           	push   0x40
  550621:	50                                              	push   eax
  550622:	89 4e 20                                        	mov    DWORD PTR [esi+0x20],ecx
  550625:	e8 2f 35 34 00                                  	call   0x893b59
  55062a:	83 c4 0c                                        	add    esp,0xc
  55062d:	e8 7e 00 00 00                                  	call   0x5506b0
  550632:	85 db                                           	test   ebx,ebx
  550634:	74 5d                                           	je     0x550693
  550636:	8b c3                                           	mov    eax,ebx
  550638:	8d 50 01                                        	lea    edx,[eax+0x1]
  55063b:	eb 03                                           	jmp    0x550640
  55063d:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  550640:	8a 08                                           	mov    cl,BYTE PTR [eax]
  550642:	40                                              	inc    eax
  550643:	84 c9                                           	test   cl,cl
  550645:	75 f9                                           	jne    0x550640
  550647:	2b c2                                           	sub    eax,edx
  550649:	74 48                                           	je     0x550693
  55064b:	f6 05 d4 b0 fa 00 01                            	test   BYTE PTR ds:0xfab0d4,0x1
  550652:	75 27                                           	jne    0x55067b
  550654:	83 0d d4 b0 fa 00 01                            	or     DWORD PTR ds:0xfab0d4,0x1
  55065b:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  550662:	e8 39 9d 2b 00                                  	call   0x80a3a0
  550667:	68 d0 cd bc 00                                  	push   0xbccdd0
  55066c:	e8 a9 1c 34 00                                  	call   0x89231a
  550671:	83 c4 04                                        	add    esp,0x4
  550674:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  55067b:	8b cb                                           	mov    ecx,ebx
  55067d:	e8 8e a8 2b 00                                  	call   0x80af10
  550682:	85 c0                                           	test   eax,eax
  550684:	74 0d                                           	je     0x550693
  550686:	89 46 28                                        	mov    DWORD PTR [esi+0x28],eax
  550689:	8b 10                                           	mov    edx,DWORD PTR [eax]
  55068b:	8b c8                                           	mov    ecx,eax
  55068d:	8b 42 0c                                        	mov    eax,DWORD PTR [edx+0xc]
  550690:	57                                              	push   edi
  550691:	ff d0                                           	call   eax
  550693:	b8 01 00 00 00                                  	mov    eax,0x1
  550698:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  55069b:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  5506a2:	59                                              	pop    ecx
  5506a3:	5e                                              	pop    esi
  5506a4:	5b                                              	pop    ebx
  5506a5:	8b e5                                           	mov    esp,ebp
  5506a7:	5d                                              	pop    ebp
  5506a8:	c2 14 00                                        	ret    0x14
  5506ab:	cc                                              	int3
  5506ac:	cc                                              	int3
  5506ad:	cc                                              	int3
  5506ae:	cc                                              	int3
  5506af:	cc                                              	int3

; sound-80af10 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0080af10 <.text+0x409f10>:
  80af10:	55                                              	push   ebp
  80af11:	8b ec                                           	mov    ebp,esp
  80af13:	6a ff                                           	push   0xffffffff
  80af15:	68 f4 c3 91 00                                  	push   0x91c3f4
  80af1a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  80af20:	50                                              	push   eax
  80af21:	83 ec 28                                        	sub    esp,0x28
  80af24:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  80af29:	33 c5                                           	xor    eax,ebp
  80af2b:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  80af2e:	53                                              	push   ebx
  80af2f:	56                                              	push   esi
  80af30:	57                                              	push   edi
  80af31:	50                                              	push   eax
  80af32:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  80af35:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  80af3b:	33 db                                           	xor    ebx,ebx
  80af3d:	8b f1                                           	mov    esi,ecx
  80af3f:	89 5d d0                                        	mov    DWORD PTR [ebp-0x30],ebx
  80af42:	3b f3                                           	cmp    esi,ebx
  80af44:	75 07                                           	jne    0x80af4d
  80af46:	e8 d5 fe ff ff                                  	call   0x80ae20
  80af4b:	eb 6f                                           	jmp    0x80afbc
  80af4d:	6a 2c                                           	push   0x2c
  80af4f:	e8 14 63 08 00                                  	call   0x891268
  80af54:	8b f8                                           	mov    edi,eax
  80af56:	83 c4 04                                        	add    esp,0x4
  80af59:	89 7d cc                                        	mov    DWORD PTR [ebp-0x34],edi
  80af5c:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  80af5f:	3b fb                                           	cmp    edi,ebx
  80af61:	74 3e                                           	je     0x80afa1
  80af63:	8b c6                                           	mov    eax,esi
  80af65:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  80af6c:	89 5d e4                                        	mov    DWORD PTR [ebp-0x1c],ebx
  80af6f:	88 5d d4                                        	mov    BYTE PTR [ebp-0x2c],bl
  80af72:	8d 50 01                                        	lea    edx,[eax+0x1]
  80af75:	8a 08                                           	mov    cl,BYTE PTR [eax]
  80af77:	40                                              	inc    eax
  80af78:	3a cb                                           	cmp    cl,bl
  80af7a:	75 f9                                           	jne    0x80af75
  80af7c:	2b c2                                           	sub    eax,edx
  80af7e:	56                                              	push   esi
  80af7f:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  80af82:	e8 89 03 c0 ff                                  	call   0x40b310
  80af87:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  80af8a:	50                                              	push   eax
  80af8b:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  80af8f:	bb 01 00 00 00                                  	mov    ebx,0x1
  80af94:	57                                              	push   edi
  80af95:	89 5d d0                                        	mov    DWORD PTR [ebp-0x30],ebx
  80af98:	e8 93 32 00 00                                  	call   0x80e230
  80af9d:	8b f0                                           	mov    esi,eax
  80af9f:	eb 02                                           	jmp    0x80afa3
  80afa1:	33 f6                                           	xor    esi,esi
  80afa3:	f6 c3 01                                        	test   bl,0x1
  80afa6:	74 12                                           	je     0x80afba
  80afa8:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  80afac:	72 0c                                           	jb     0x80afba
  80afae:	8b 4d d4                                        	mov    ecx,DWORD PTR [ebp-0x2c]
  80afb1:	51                                              	push   ecx
  80afb2:	e8 55 62 08 00                                  	call   0x89120c
  80afb7:	83 c4 04                                        	add    esp,0x4
  80afba:	8b c6                                           	mov    eax,esi
  80afbc:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  80afbf:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  80afc6:	59                                              	pop    ecx
  80afc7:	5f                                              	pop    edi
  80afc8:	5e                                              	pop    esi
  80afc9:	5b                                              	pop    ebx
  80afca:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  80afcd:	33 cd                                           	xor    ecx,ebp
  80afcf:	e8 2d 60 08 00                                  	call   0x891001
  80afd4:	8b e5                                           	mov    esp,ebp
  80afd6:	5d                                              	pop    ebp
  80afd7:	c3                                              	ret
  80afd8:	cc                                              	int3
  80afd9:	cc                                              	int3
  80afda:	cc                                              	int3
  80afdb:	cc                                              	int3
  80afdc:	cc                                              	int3
  80afdd:	cc                                              	int3
  80afde:	cc                                              	int3
  80afdf:	cc                                              	int3

; sound-80e230 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0080e230 <.text+0x40d230>:
  80e230:	55                                              	push   ebp
  80e231:	8b ec                                           	mov    ebp,esp
  80e233:	6a ff                                           	push   0xffffffff
  80e235:	68 68 16 91 00                                  	push   0x911668
  80e23a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  80e240:	50                                              	push   eax
  80e241:	53                                              	push   ebx
  80e242:	56                                              	push   esi
  80e243:	57                                              	push   edi
  80e244:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  80e249:	33 c5                                           	xor    eax,ebp
  80e24b:	50                                              	push   eax
  80e24c:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  80e24f:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  80e255:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
  80e258:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  80e25b:	33 db                                           	xor    ebx,ebx
  80e25d:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  80e260:	c7 06 50 1b c5 00                               	mov    DWORD PTR [esi],0xc51b50
  80e266:	8d 7e 08                                        	lea    edi,[esi+0x8]
  80e269:	89 5e 04                                        	mov    DWORD PTR [esi+0x4],ebx
  80e26c:	53                                              	push   ebx
  80e26d:	c7 47 14 0f 00 00 00                            	mov    DWORD PTR [edi+0x14],0xf
  80e274:	89 5f 10                                        	mov    DWORD PTR [edi+0x10],ebx
  80e277:	50                                              	push   eax
  80e278:	83 c9 ff                                        	or     ecx,0xffffffff
  80e27b:	88 1f                                           	mov    BYTE PTR [edi],bl
  80e27d:	e8 2e ce bf ff                                  	call   0x40b0b0
  80e282:	b8 01 00 00 00                                  	mov    eax,0x1
  80e287:	01 05 64 a8 fb 00                               	add    DWORD PTR ds:0xfba864,eax
  80e28d:	89 5e 24                                        	mov    DWORD PTR [esi+0x24],ebx
  80e290:	89 5e 28                                        	mov    DWORD PTR [esi+0x28],ebx
  80e293:	01 46 04                                        	add    DWORD PTR [esi+0x4],eax
  80e296:	8b c6                                           	mov    eax,esi
  80e298:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  80e29b:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  80e2a2:	59                                              	pop    ecx
  80e2a3:	5f                                              	pop    edi
  80e2a4:	5e                                              	pop    esi
  80e2a5:	5b                                              	pop    ebx
  80e2a6:	8b e5                                           	mov    esp,ebp
  80e2a8:	5d                                              	pop    ebp
  80e2a9:	c2 08 00                                        	ret    0x8
  80e2ac:	cc                                              	int3
  80e2ad:	cc                                              	int3
  80e2ae:	cc                                              	int3
  80e2af:	cc                                              	int3

; sound-80e4c0 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0080e4c0 <.text+0x40d4c0>:
  80e4c0:	55                                              	push   ebp
  80e4c1:	8b ec                                           	mov    ebp,esp
  80e4c3:	6a ff                                           	push   0xffffffff
  80e4c5:	68 ce 05 92 00                                  	push   0x9205ce
  80e4ca:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  80e4d0:	50                                              	push   eax
  80e4d1:	83 ec 10                                        	sub    esp,0x10
  80e4d4:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  80e4d9:	33 c5                                           	xor    eax,ebp
  80e4db:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  80e4de:	56                                              	push   esi
  80e4df:	57                                              	push   edi
  80e4e0:	50                                              	push   eax
  80e4e1:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  80e4e4:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  80e4ea:	8b 7d 08                                        	mov    edi,DWORD PTR [ebp+0x8]
  80e4ed:	8b f1                                           	mov    esi,ecx
  80e4ef:	83 7e 24 00                                     	cmp    DWORD PTR [esi+0x24],0x0
  80e4f3:	75 43                                           	jne    0x80e538
  80e4f5:	b8 01 00 00 00                                  	mov    eax,0x1
  80e4fa:	84 05 d4 b0 fa 00                               	test   BYTE PTR ds:0xfab0d4,al
  80e500:	75 26                                           	jne    0x80e528
  80e502:	09 05 d4 b0 fa 00                               	or     DWORD PTR ds:0xfab0d4,eax
  80e508:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  80e50f:	e8 8c be ff ff                                  	call   0x80a3a0
  80e514:	68 d0 cd bc 00                                  	push   0xbccdd0
  80e519:	e8 fc 3d 08 00                                  	call   0x89231a
  80e51e:	83 c4 04                                        	add    esp,0x4
  80e521:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  80e528:	8d 4e 08                                        	lea    ecx,[esi+0x8]
  80e52b:	68 28 b0 fa 00                                  	push   0xfab028
  80e530:	e8 cb c5 ff ff                                  	call   0x80ab00
  80e535:	89 46 24                                        	mov    DWORD PTR [esi+0x24],eax
  80e538:	8b 4e 24                                        	mov    ecx,DWORD PTR [esi+0x24]
  80e53b:	85 c9                                           	test   ecx,ecx
  80e53d:	74 5b                                           	je     0x80e59a
  80e53f:	8b 46 28                                        	mov    eax,DWORD PTR [esi+0x28]
  80e542:	85 c0                                           	test   eax,eax
  80e544:	74 1c                                           	je     0x80e562
  80e546:	83 78 08 00                                     	cmp    DWORD PTR [eax+0x8],0x0
  80e54a:	74 0c                                           	je     0x80e558
  80e54c:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  80e54f:	8b 10                                           	mov    edx,DWORD PTR [eax]
  80e551:	8b c8                                           	mov    ecx,eax
  80e553:	8b 42 28                                        	mov    eax,DWORD PTR [edx+0x28]
  80e556:	ff d0                                           	call   eax
  80e558:	8b 4e 28                                        	mov    ecx,DWORD PTR [esi+0x28]
  80e55b:	e8 80 e6 ff ff                                  	call   0x80cbe0
  80e560:	eb 38                                           	jmp    0x80e59a
  80e562:	d9 07                                           	fld    DWORD PTR [edi]
  80e564:	6a 00                                           	push   0x0
  80e566:	dd 05 98 58 c5 00                               	fld    QWORD PTR ds:0xc55898
  80e56c:	8d 45 e4                                        	lea    eax,[ebp-0x1c]
  80e56f:	dc c9                                           	fmul   st(1),st
  80e571:	50                                              	push   eax
  80e572:	d9 c9                                           	fxch   st(1)
  80e574:	d9 5d e4                                        	fstp   DWORD PTR [ebp-0x1c]
  80e577:	d9 47 04                                        	fld    DWORD PTR [edi+0x4]
  80e57a:	d8 c9                                           	fmul   st,st(1)
  80e57c:	d9 5d e8                                        	fstp   DWORD PTR [ebp-0x18]
  80e57f:	d8 4f 08                                        	fmul   DWORD PTR [edi+0x8]
  80e582:	d9 5d ec                                        	fstp   DWORD PTR [ebp-0x14]
  80e585:	8b 11                                           	mov    edx,DWORD PTR [ecx]
  80e587:	8b 52 10                                        	mov    edx,DWORD PTR [edx+0x10]
  80e58a:	ff d2                                           	call   edx
  80e58c:	89 46 28                                        	mov    DWORD PTR [esi+0x28],eax
  80e58f:	85 c0                                           	test   eax,eax
  80e591:	74 07                                           	je     0x80e59a
  80e593:	c7 40 0c 00 00 00 00                            	mov    DWORD PTR [eax+0xc],0x0
  80e59a:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  80e59d:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  80e5a4:	59                                              	pop    ecx
  80e5a5:	5f                                              	pop    edi
  80e5a6:	5e                                              	pop    esi
  80e5a7:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  80e5aa:	33 cd                                           	xor    ecx,ebp
  80e5ac:	e8 50 2a 08 00                                  	call   0x891001
  80e5b1:	8b e5                                           	mov    esp,ebp
  80e5b3:	5d                                              	pop    ebp
  80e5b4:	c2 04 00                                        	ret    0x4
  80e5b7:	cc                                              	int3
  80e5b8:	cc                                              	int3
  80e5b9:	cc                                              	int3
  80e5ba:	cc                                              	int3
  80e5bb:	cc                                              	int3
  80e5bc:	cc                                              	int3
  80e5bd:	cc                                              	int3
  80e5be:	cc                                              	int3
  80e5bf:	cc                                              	int3

; sound-80ab00 DamageSound filename dataflow and concrete virtual target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0080ab00 <.text+0x409b00>:
  80ab00:	55                                              	push   ebp
  80ab01:	8b ec                                           	mov    ebp,esp
  80ab03:	83 e4 f8                                        	and    esp,0xfffffff8
  80ab06:	6a ff                                           	push   0xffffffff
  80ab08:	68 4b c4 91 00                                  	push   0x91c44b
  80ab0d:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  80ab13:	50                                              	push   eax
  80ab14:	83 ec 50                                        	sub    esp,0x50
  80ab17:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  80ab1c:	33 c4                                           	xor    eax,esp
  80ab1e:	89 44 24 48                                     	mov    DWORD PTR [esp+0x48],eax
  80ab22:	53                                              	push   ebx
  80ab23:	56                                              	push   esi
  80ab24:	57                                              	push   edi
  80ab25:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  80ab2a:	33 c4                                           	xor    eax,esp
  80ab2c:	50                                              	push   eax
  80ab2d:	8d 44 24 60                                     	lea    eax,[esp+0x60]
  80ab31:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  80ab37:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  80ab3a:	8b f9                                           	mov    edi,ecx
  80ab3c:	68 e8 17 c5 00                                  	push   0xc517e8
  80ab41:	8b d7                                           	mov    edx,edi
  80ab43:	89 5c 24 18                                     	mov    DWORD PTR [esp+0x18],ebx
  80ab47:	89 7c 24 14                                     	mov    DWORD PTR [esp+0x14],edi
  80ab4b:	e8 70 2f ed ff                                  	call   0x6ddac0
  80ab50:	85 c0                                           	test   eax,eax
  80ab52:	0f 84 9e 02 00 00                               	je     0x80adf6
  80ab58:	83 7f 14 10                                     	cmp    DWORD PTR [edi+0x14],0x10
  80ab5c:	72 04                                           	jb     0x80ab62
  80ab5e:	8b 07                                           	mov    eax,DWORD PTR [edi]
  80ab60:	eb 02                                           	jmp    0x80ab64
  80ab62:	8b c7                                           	mov    eax,edi
  80ab64:	50                                              	push   eax
  80ab65:	68 f0 17 c5 00                                  	push   0xc517f0
  80ab6a:	6a 05                                           	push   0x5
  80ab6c:	e8 3f 2f ee ff                                  	call   0x6edab0
  80ab71:	83 c4 0c                                        	add    esp,0xc
  80ab74:	33 f6                                           	xor    esi,esi
  80ab76:	56                                              	push   esi
  80ab77:	57                                              	push   edi
  80ab78:	83 c9 ff                                        	or     ecx,0xffffffff
  80ab7b:	8d 7c 24 24                                     	lea    edi,[esp+0x24]
  80ab7f:	c7 44 24 38 0f 00 00 00                         	mov    DWORD PTR [esp+0x38],0xf
  80ab87:	89 74 24 34                                     	mov    DWORD PTR [esp+0x34],esi
  80ab8b:	c6 44 24 24 00                                  	mov    BYTE PTR [esp+0x24],0x0
  80ab90:	e8 1b 05 c0 ff                                  	call   0x40b0b0
  80ab95:	89 74 24 68                                     	mov    DWORD PTR [esp+0x68],esi
  80ab99:	8b 4c 24 1c                                     	mov    ecx,DWORD PTR [esp+0x1c]
  80ab9d:	33 c0                                           	xor    eax,eax
  80ab9f:	39 74 24 2c                                     	cmp    DWORD PTR [esp+0x2c],esi
  80aba3:	8b 74 24 30                                     	mov    esi,DWORD PTR [esp+0x30]
  80aba7:	76 34                                           	jbe    0x80abdd
  80aba9:	8d a4 24 00 00 00 00                            	lea    esp,[esp+0x0]
  80abb0:	8b d1                                           	mov    edx,ecx
  80abb2:	83 fe 10                                        	cmp    esi,0x10
  80abb5:	73 04                                           	jae    0x80abbb
  80abb7:	8d 54 24 1c                                     	lea    edx,[esp+0x1c]
  80abbb:	80 3c 02 5c                                     	cmp    BYTE PTR [edx+eax*1],0x5c
  80abbf:	75 15                                           	jne    0x80abd6
  80abc1:	83 fe 10                                        	cmp    esi,0x10
  80abc4:	73 04                                           	jae    0x80abca
  80abc6:	8d 4c 24 1c                                     	lea    ecx,[esp+0x1c]
  80abca:	c6 04 01 2f                                     	mov    BYTE PTR [ecx+eax*1],0x2f
  80abce:	8b 74 24 30                                     	mov    esi,DWORD PTR [esp+0x30]
  80abd2:	8b 4c 24 1c                                     	mov    ecx,DWORD PTR [esp+0x1c]
  80abd6:	40                                              	inc    eax
  80abd7:	3b 44 24 2c                                     	cmp    eax,DWORD PTR [esp+0x2c]
  80abdb:	72 d3                                           	jb     0x80abb0
  80abdd:	8b 53 14                                        	mov    edx,DWORD PTR [ebx+0x14]
  80abe0:	8d 43 04                                        	lea    eax,[ebx+0x4]
  80abe3:	bf 10 00 00 00                                  	mov    edi,0x10
  80abe8:	39 78 14                                        	cmp    DWORD PTR [eax+0x14],edi
  80abeb:	72 02                                           	jb     0x80abef
  80abed:	8b 00                                           	mov    eax,DWORD PTR [eax]
  80abef:	3b f7                                           	cmp    esi,edi
  80abf1:	73 04                                           	jae    0x80abf7
  80abf3:	8d 4c 24 1c                                     	lea    ecx,[esp+0x1c]
  80abf7:	52                                              	push   edx
  80abf8:	50                                              	push   eax
  80abf9:	51                                              	push   ecx
  80abfa:	e8 83 bc 08 00                                  	call   0x896882
  80abff:	83 c4 0c                                        	add    esp,0xc
  80ac02:	85 c0                                           	test   eax,eax
  80ac04:	75 6f                                           	jne    0x80ac75
  80ac06:	8b 4c 24 1c                                     	mov    ecx,DWORD PTR [esp+0x1c]
  80ac0a:	39 7c 24 30                                     	cmp    DWORD PTR [esp+0x30],edi
  80ac0e:	73 04                                           	jae    0x80ac14
  80ac10:	8d 4c 24 1c                                     	lea    ecx,[esp+0x1c]
  80ac14:	03 4b 14                                        	add    ecx,DWORD PTR [ebx+0x14]
  80ac17:	c7 44 24 4c 0f 00 00 00                         	mov    DWORD PTR [esp+0x4c],0xf
  80ac1f:	8b c1                                           	mov    eax,ecx
  80ac21:	c7 44 24 48 00 00 00 00                         	mov    DWORD PTR [esp+0x48],0x0
  80ac29:	c6 44 24 38 00                                  	mov    BYTE PTR [esp+0x38],0x0
  80ac2e:	8d 70 01                                        	lea    esi,[eax+0x1]
  80ac31:	8a 10                                           	mov    dl,BYTE PTR [eax]
  80ac33:	40                                              	inc    eax
  80ac34:	84 d2                                           	test   dl,dl
  80ac36:	75 f9                                           	jne    0x80ac31
  80ac38:	51                                              	push   ecx
  80ac39:	2b c6                                           	sub    eax,esi
  80ac3b:	8d 4c 24 3c                                     	lea    ecx,[esp+0x3c]
  80ac3f:	e8 cc 06 c0 ff                                  	call   0x40b310
  80ac44:	6a 00                                           	push   0x0
  80ac46:	8d 44 24 3c                                     	lea    eax,[esp+0x3c]
  80ac4a:	50                                              	push   eax
  80ac4b:	83 c9 ff                                        	or     ecx,0xffffffff
  80ac4e:	8d 7c 24 24                                     	lea    edi,[esp+0x24]
  80ac52:	c6 44 24 70 01                                  	mov    BYTE PTR [esp+0x70],0x1
  80ac57:	e8 54 04 c0 ff                                  	call   0x40b0b0
  80ac5c:	c6 44 24 68 00                                  	mov    BYTE PTR [esp+0x68],0x0
  80ac61:	83 7c 24 4c 10                                  	cmp    DWORD PTR [esp+0x4c],0x10
  80ac66:	72 0d                                           	jb     0x80ac75
  80ac68:	8b 4c 24 38                                     	mov    ecx,DWORD PTR [esp+0x38]
  80ac6c:	51                                              	push   ecx
  80ac6d:	e8 9a 65 08 00                                  	call   0x89120c
  80ac72:	83 c4 04                                        	add    esp,0x4
  80ac75:	8b 54 24 10                                     	mov    edx,DWORD PTR [esp+0x10]
  80ac79:	52                                              	push   edx
  80ac7a:	53                                              	push   ebx
  80ac7b:	e8 30 fc ff ff                                  	call   0x80a8b0
  80ac80:	8b f0                                           	mov    esi,eax
  80ac82:	85 f6                                           	test   esi,esi
  80ac84:	75 15                                           	jne    0x80ac9b
  80ac86:	8d 44 24 1c                                     	lea    eax,[esp+0x1c]
  80ac8a:	50                                              	push   eax
  80ac8b:	53                                              	push   ebx
  80ac8c:	e8 1f fc ff ff                                  	call   0x80a8b0
  80ac91:	8b f0                                           	mov    esi,eax
  80ac93:	85 f6                                           	test   esi,esi
  80ac95:	0f 84 ad 00 00 00                               	je     0x80ad48
  80ac9b:	83 7e 0c 00                                     	cmp    DWORD PTR [esi+0xc],0x0
  80ac9f:	0f 85 88 00 00 00                               	jne    0x80ad2d
  80aca5:	8b fe                                           	mov    edi,esi
  80aca7:	e8 b4 2a 00 00                                  	call   0x80d760
  80acac:	8d 46 18                                        	lea    eax,[esi+0x18]
  80acaf:	6a 00                                           	push   0x0
  80acb1:	50                                              	push   eax
  80acb2:	83 c9 ff                                        	or     ecx,0xffffffff
  80acb5:	8d 7c 24 40                                     	lea    edi,[esp+0x40]
  80acb9:	c7 44 24 54 0f 00 00 00                         	mov    DWORD PTR [esp+0x54],0xf
  80acc1:	c7 44 24 50 00 00 00 00                         	mov    DWORD PTR [esp+0x50],0x0
  80acc9:	c6 44 24 40 00                                  	mov    BYTE PTR [esp+0x40],0x0
  80acce:	e8 dd 03 c0 ff                                  	call   0x40b0b0
  80acd3:	c7 44 24 54 00 00 00 00                         	mov    DWORD PTR [esp+0x54],0x0
  80acdb:	8d 4c 24 38                                     	lea    ecx,[esp+0x38]
  80acdf:	8d 7b 48                                        	lea    edi,[ebx+0x48]
  80ace2:	51                                              	push   ecx
  80ace3:	8b cf                                           	mov    ecx,edi
  80ace5:	c6 44 24 6c 02                                  	mov    BYTE PTR [esp+0x6c],0x2
  80acea:	e8 d1 88 d3 ff                                  	call   0x5435c0
  80acef:	50                                              	push   eax
  80acf0:	8d 54 24 18                                     	lea    edx,[esp+0x18]
  80acf4:	52                                              	push   edx
  80acf5:	57                                              	push   edi
  80acf6:	e8 65 18 00 00                                  	call   0x80c560
  80acfb:	bf 10 00 00 00                                  	mov    edi,0x10
  80ad00:	39 7c 24 4c                                     	cmp    DWORD PTR [esp+0x4c],edi
  80ad04:	72 0d                                           	jb     0x80ad13
  80ad06:	8b 44 24 38                                     	mov    eax,DWORD PTR [esp+0x38]
  80ad0a:	50                                              	push   eax
  80ad0b:	e8 fc 64 08 00                                  	call   0x89120c
  80ad10:	83 c4 04                                        	add    esp,0x4
  80ad13:	39 7c 24 30                                     	cmp    DWORD PTR [esp+0x30],edi
  80ad17:	72 0d                                           	jb     0x80ad26
  80ad19:	8b 4c 24 1c                                     	mov    ecx,DWORD PTR [esp+0x1c]
  80ad1d:	51                                              	push   ecx
  80ad1e:	e8 e9 64 08 00                                  	call   0x89120c
  80ad23:	83 c4 04                                        	add    esp,0x4
  80ad26:	8b c6                                           	mov    eax,esi
  80ad28:	e9 c9 00 00 00                                  	jmp    0x80adf6
  80ad2d:	83 7c 24 30 10                                  	cmp    DWORD PTR [esp+0x30],0x10
  80ad32:	72 f2                                           	jb     0x80ad26
  80ad34:	8b 54 24 1c                                     	mov    edx,DWORD PTR [esp+0x1c]
  80ad38:	52                                              	push   edx
  80ad39:	e8 ce 64 08 00                                  	call   0x89120c
  80ad3e:	83 c4 04                                        	add    esp,0x4
  80ad41:	8b c6                                           	mov    eax,esi
  80ad43:	e9 ae 00 00 00                                  	jmp    0x80adf6
  80ad48:	6a 5c                                           	push   0x5c
  80ad4a:	e8 19 65 08 00                                  	call   0x891268
  80ad4f:	83 c4 04                                        	add    esp,0x4
  80ad52:	89 44 24 10                                     	mov    DWORD PTR [esp+0x10],eax
  80ad56:	c6 44 24 68 03                                  	mov    BYTE PTR [esp+0x68],0x3
  80ad5b:	85 c0                                           	test   eax,eax
  80ad5d:	74 0e                                           	je     0x80ad6d
  80ad5f:	50                                              	push   eax
  80ad60:	8d 7c 24 20                                     	lea    edi,[esp+0x20]
  80ad64:	e8 77 2e 00 00                                  	call   0x80dbe0
  80ad69:	8b d8                                           	mov    ebx,eax
  80ad6b:	eb 02                                           	jmp    0x80ad6f
  80ad6d:	33 db                                           	xor    ebx,ebx
  80ad6f:	8b fb                                           	mov    edi,ebx
  80ad71:	c6 44 24 68 00                                  	mov    BYTE PTR [esp+0x68],0x0
  80ad76:	e8 e5 29 00 00                                  	call   0x80d760
  80ad7b:	6a 00                                           	push   0x0
  80ad7d:	8d 44 24 20                                     	lea    eax,[esp+0x20]
  80ad81:	50                                              	push   eax
  80ad82:	83 c9 ff                                        	or     ecx,0xffffffff
  80ad85:	8d 7c 24 40                                     	lea    edi,[esp+0x40]
  80ad89:	c7 44 24 54 0f 00 00 00                         	mov    DWORD PTR [esp+0x54],0xf
  80ad91:	c7 44 24 50 00 00 00 00                         	mov    DWORD PTR [esp+0x50],0x0
  80ad99:	c6 44 24 40 00                                  	mov    BYTE PTR [esp+0x40],0x0
  80ad9e:	e8 0d 03 c0 ff                                  	call   0x40b0b0
  80ada3:	89 5c 24 54                                     	mov    DWORD PTR [esp+0x54],ebx
  80ada7:	c6 44 24 68 04                                  	mov    BYTE PTR [esp+0x68],0x4
  80adac:	8b 74 24 14                                     	mov    esi,DWORD PTR [esp+0x14]
  80adb0:	8b cf                                           	mov    ecx,edi
  80adb2:	83 c6 38                                        	add    esi,0x38
  80adb5:	51                                              	push   ecx
  80adb6:	8b ce                                           	mov    ecx,esi
  80adb8:	e8 03 88 d3 ff                                  	call   0x5435c0
  80adbd:	50                                              	push   eax
  80adbe:	8d 54 24 18                                     	lea    edx,[esp+0x18]
  80adc2:	52                                              	push   edx
  80adc3:	56                                              	push   esi
  80adc4:	e8 b7 9d d6 ff                                  	call   0x574b80
  80adc9:	be 10 00 00 00                                  	mov    esi,0x10
  80adce:	39 74 24 4c                                     	cmp    DWORD PTR [esp+0x4c],esi
  80add2:	72 0d                                           	jb     0x80ade1
  80add4:	8b 44 24 38                                     	mov    eax,DWORD PTR [esp+0x38]
  80add8:	50                                              	push   eax
  80add9:	e8 2e 64 08 00                                  	call   0x89120c
  80adde:	83 c4 04                                        	add    esp,0x4
  80ade1:	39 74 24 30                                     	cmp    DWORD PTR [esp+0x30],esi
  80ade5:	72 0d                                           	jb     0x80adf4
  80ade7:	8b 4c 24 1c                                     	mov    ecx,DWORD PTR [esp+0x1c]
  80adeb:	51                                              	push   ecx
  80adec:	e8 1b 64 08 00                                  	call   0x89120c
  80adf1:	83 c4 04                                        	add    esp,0x4
  80adf4:	8b c3                                           	mov    eax,ebx
  80adf6:	8b 4c 24 60                                     	mov    ecx,DWORD PTR [esp+0x60]
  80adfa:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  80ae01:	59                                              	pop    ecx
  80ae02:	5f                                              	pop    edi
  80ae03:	5e                                              	pop    esi
  80ae04:	5b                                              	pop    ebx
  80ae05:	8b 4c 24 48                                     	mov    ecx,DWORD PTR [esp+0x48]
  80ae09:	33 cc                                           	xor    ecx,esp
  80ae0b:	e8 f1 61 08 00                                  	call   0x891001
  80ae10:	8b e5                                           	mov    esp,ebp
  80ae12:	5d                                              	pop    ebp
  80ae13:	c2 04 00                                        	ret    0x4
  80ae16:	cc                                              	int3
  80ae17:	cc                                              	int3
  80ae18:	cc                                              	int3
  80ae19:	cc                                              	int3
  80ae1a:	cc                                              	int3
  80ae1b:	cc                                              	int3
  80ae1c:	cc                                              	int3
  80ae1d:	cc                                              	int3
  80ae1e:	cc                                              	int3
  80ae1f:	cc                                              	int3
