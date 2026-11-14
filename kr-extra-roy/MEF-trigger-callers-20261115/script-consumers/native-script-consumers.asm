; CAM01: formal wrapper / CameraWorks binder caller

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0054e8c2 <.text+0x14d8c2>:
  54e8c2:	68 c8 f3 fd 00       	push   0xfdf3c8
  54e8c7:	e8 64 58 ee ff       	call   0x434130
  54e8cc:	8d 4d ec             	lea    ecx,[ebp-0x14]
  54e8cf:	51                   	push   ecx
  54e8d0:	e8 4b 01 00 00       	call   0x54ea20
  54e8d5:	83 c4 08             	add    esp,0x8
  54e8d8:	50                   	push   eax
  54e8d9:	e8 22 02 00 00       	call   0x54eb00
  54e8de:	50                   	push   eax
  54e8df:	e8 bc 02 00 00       	call   0x54eba0

; CAM02: CameraWorks namespace + native owner slots

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0054ea20 <.text+0x14da20>:
  54ea20:	55                   	push   ebp
  54ea21:	8b ec                	mov    ebp,esp
  54ea23:	51                   	push   ecx
  54ea24:	53                   	push   ebx
  54ea25:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  54ea28:	56                   	push   esi
  54ea29:	8b 33                	mov    esi,DWORD PTR [ebx]
  54ea2b:	a3 28 1e fe 00       	mov    ds:0xfe1e28,eax
  54ea30:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  54ea33:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  54ea36:	57                   	push   edi
  54ea37:	89 1d 24 1e fe 00    	mov    DWORD PTR ds:0xfe1e24,ebx
  54ea3d:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  54ea40:	72 07                	jb     0x54ea49
  54ea42:	8b c6                	mov    eax,esi
  54ea44:	e8 57 c9 1a 00       	call   0x6fb3a0
  54ea49:	8b 7e 08             	mov    edi,DWORD PTR [esi+0x8]
  54ea4c:	6a 00                	push   0x0
  54ea4e:	6a 00                	push   0x0
  54ea50:	56                   	push   esi
  54ea51:	e8 4a af 1a 00       	call   0x6f99a0
  54ea56:	89 07                	mov    DWORD PTR [edi],eax
  54ea58:	c7 47 08 05 00 00 00 	mov    DWORD PTR [edi+0x8],0x5
  54ea5f:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  54ea63:	8b 33                	mov    esi,DWORD PTR [ebx]
  54ea65:	83 c4 0c             	add    esp,0xc
  54ea68:	bf 10 fd c0 00       	mov    edi,0xc0fd10
  54ea6d:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  54ea72:	e8 19 6d 1a 00       	call   0x6f5790

; CAM03: LoadRel pointer / Lua closure binding

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0054eba0 <.text+0x14dba0>:
  54eba0:	55                   	push   ebp
  54eba1:	8b ec                	mov    ebp,esp
  54eba3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  54eba6:	53                   	push   ebx
  54eba7:	8b 1d 24 1e fe 00    	mov    ebx,DWORD PTR ds:0xfe1e24
  54ebad:	56                   	push   esi
  54ebae:	8b 33                	mov    esi,DWORD PTR [ebx]
  54ebb0:	57                   	push   edi
  54ebb1:	8b 38                	mov    edi,DWORD PTR [eax]
  54ebb3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  54ebb8:	c7 05 30 1e fe 00 90 	mov    DWORD PTR ds:0xfe1e30,0x54e990
  54ebbf:	e9 54 00 
  54ebc2:	e8 b9 6a 1a 00       	call   0x6f5680
  54ebc7:	8b 03                	mov    eax,DWORD PTR [ebx]
  54ebc9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  54ebcc:	83 e8 10             	sub    eax,0x10
  54ebcf:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  54ebd4:	74 06                	je     0x54ebdc
  54ebd6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  54ebda:	74 14                	je     0x54ebf0
  54ebdc:	57                   	push   edi
  54ebdd:	68 c4 26 c4 00       	push   0xc426c4
  54ebe2:	e8 d6 44 34 00       	call   0x8930bd
  54ebe7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  54ebe9:	83 c4 08             	add    esp,0x8
  54ebec:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  54ebf0:	8b 3d 24 1e fe 00    	mov    edi,DWORD PTR ds:0xfe1e24
  54ebf6:	8b 37                	mov    esi,DWORD PTR [edi]
  54ebf8:	68 e8 a5 d6 00       	push   0xd6a5e8
  54ebfd:	e8 0e 69 1a 00       	call   0x6f5510
  54ec02:	8b 37                	mov    esi,DWORD PTR [edi]
  54ec04:	83 c4 04             	add    esp,0x4
  54ec07:	6a 00                	push   0x0
  54ec09:	68 a0 ee 54 00       	push   0x54eea0
  54ec0e:	e8 9d 69 1a 00       	call   0x6f55b0
  54ec13:	8b 0f                	mov    ecx,DWORD PTR [edi]
  54ec15:	51                   	push   ecx
  54ec16:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  54ec1b:	e8 d0 6b 1a 00       	call   0x6f57f0
  54ec20:	8b 15 24 1e fe 00    	mov    edx,DWORD PTR ds:0xfe1e24
  54ec26:	8b 02                	mov    eax,DWORD PTR [edx]
  54ec28:	83 c4 0c             	add    esp,0xc
  54ec2b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  54ec2f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  54ec32:	5f                   	pop    edi
  54ec33:	5e                   	pop    esi
  54ec34:	5b                   	pop    ebx
  54ec35:	5d                   	pop    ebp
  54ec36:	c2 04 00             	ret    0x4

; CAM04: LoadRel Lua closure wrapper

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0054eea0 <.text+0x14dea0>:
  54eea0:	55                   	push   ebp
  54eea1:	8b ec                	mov    ebp,esp
  54eea3:	6a ff                	push   0xffffffff
  54eea5:	68 c8 83 93 00       	push   0x9383c8
  54eeaa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  54eeb0:	50                   	push   eax
  54eeb1:	83 ec 0c             	sub    esp,0xc
  54eeb4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54eeb9:	33 c5                	xor    eax,ebp
  54eebb:	50                   	push   eax
  54eebc:	8d 45 f4             	lea    eax,[ebp-0xc]
  54eebf:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  54eec5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  54eec8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  54eecb:	33 c0                	xor    eax,eax
  54eecd:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  54eed0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  54eed3:	8d 4d e8             	lea    ecx,[ebp-0x18]
  54eed6:	51                   	push   ecx
  54eed7:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  54eeda:	e8 c1 01 00 00       	call   0x54f0a0
  54eedf:	83 c4 04             	add    esp,0x4
  54eee2:	b8 01 00 00 00       	mov    eax,0x1
  54eee7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  54eeea:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  54eef1:	59                   	pop    ecx
  54eef2:	8b e5                	mov    esp,ebp
  54eef4:	5d                   	pop    ebp
  54eef5:	c3                   	ret

; CAM05: four argument marshaller and indirect target call

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0054f0a0 <.text+0x14e0a0>:
  54f0a0:	55                   	push   ebp
  54f0a1:	8b ec                	mov    ebp,esp
  54f0a3:	83 ec 28             	sub    esp,0x28
  54f0a6:	a1 30 1e fe 00       	mov    eax,ds:0xfe1e30
  54f0ab:	8b 0d 28 1e fe 00    	mov    ecx,DWORD PTR ds:0xfe1e28
  54f0b1:	53                   	push   ebx
  54f0b2:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  54f0b5:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  54f0b8:	8b 03                	mov    eax,DWORD PTR [ebx]
  54f0ba:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  54f0bd:	83 e8 10             	sub    eax,0x10
  54f0c0:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  54f0c3:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  54f0c6:	56                   	push   esi
  54f0c7:	57                   	push   edi
  54f0c8:	83 f9 03             	cmp    ecx,0x3
  54f0cb:	74 2e                	je     0x54f0fb
  54f0cd:	83 f9 04             	cmp    ecx,0x4
  54f0d0:	0f 85 bf 00 00 00    	jne    0x54f195
  54f0d6:	8b 30                	mov    esi,DWORD PTR [eax]
  54f0d8:	83 c6 10             	add    esi,0x10
  54f0db:	8d 7d e0             	lea    edi,[ebp-0x20]
  54f0de:	e8 7d 86 1a 00       	call   0x6f7760
  54f0e3:	85 c0                	test   eax,eax
  54f0e5:	0f 84 aa 00 00 00    	je     0x54f195
  54f0eb:	dd 45 e0             	fld    QWORD PTR [ebp-0x20]
  54f0ee:	c7 45 e0 03 00 00 00 	mov    DWORD PTR [ebp-0x20],0x3
  54f0f5:	dd 5d d8             	fstp   QWORD PTR [ebp-0x28]
  54f0f8:	8d 45 d8             	lea    eax,[ebp-0x28]
  54f0fb:	dd 00                	fld    QWORD PTR [eax]
  54f0fd:	8b 03                	mov    eax,DWORD PTR [ebx]
  54f0ff:	dd 5d f0             	fstp   QWORD PTR [ebp-0x10]
  54f102:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  54f105:	8b 48 e8             	mov    ecx,DWORD PTR [eax-0x18]
  54f108:	83 e8 20             	sub    eax,0x20
  54f10b:	83 f9 03             	cmp    ecx,0x3
  54f10e:	74 2a                	je     0x54f13a
  54f110:	83 f9 04             	cmp    ecx,0x4
  54f113:	0f 85 83 00 00 00    	jne    0x54f19c
  54f119:	8b 30                	mov    esi,DWORD PTR [eax]
  54f11b:	83 c6 10             	add    esi,0x10
  54f11e:	8d 7d e0             	lea    edi,[ebp-0x20]
  54f121:	e8 3a 86 1a 00       	call   0x6f7760
  54f126:	85 c0                	test   eax,eax
  54f128:	74 72                	je     0x54f19c
  54f12a:	dd 45 e0             	fld    QWORD PTR [ebp-0x20]
  54f12d:	c7 45 e0 03 00 00 00 	mov    DWORD PTR [ebp-0x20],0x3
  54f134:	dd 5d d8             	fstp   QWORD PTR [ebp-0x28]
  54f137:	8d 45 d8             	lea    eax,[ebp-0x28]
  54f13a:	dd 00                	fld    QWORD PTR [eax]
  54f13c:	8b 03                	mov    eax,DWORD PTR [ebx]
  54f13e:	dd 5d e8             	fstp   QWORD PTR [ebp-0x18]
  54f141:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  54f144:	8b 48 d8             	mov    ecx,DWORD PTR [eax-0x28]
  54f147:	83 e8 30             	sub    eax,0x30
  54f14a:	83 f9 03             	cmp    ecx,0x3
  54f14d:	74 26                	je     0x54f175
  54f14f:	83 f9 04             	cmp    ecx,0x4
  54f152:	75 4c                	jne    0x54f1a0
  54f154:	8b 30                	mov    esi,DWORD PTR [eax]
  54f156:	83 c6 10             	add    esi,0x10
  54f159:	8d 7d e0             	lea    edi,[ebp-0x20]
  54f15c:	e8 ff 85 1a 00       	call   0x6f7760
  54f161:	85 c0                	test   eax,eax
  54f163:	74 3b                	je     0x54f1a0
  54f165:	dd 45 e0             	fld    QWORD PTR [ebp-0x20]
  54f168:	c7 45 e0 03 00 00 00 	mov    DWORD PTR [ebp-0x20],0x3
  54f16f:	dd 5d d8             	fstp   QWORD PTR [ebp-0x28]
  54f172:	8d 45 d8             	lea    eax,[ebp-0x28]
  54f175:	dd 00                	fld    QWORD PTR [eax]
  54f177:	8b 3b                	mov    edi,DWORD PTR [ebx]
  54f179:	dd 5d e0             	fstp   QWORD PTR [ebp-0x20]
  54f17c:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  54f17f:	83 ee 40             	sub    esi,0x40
  54f182:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  54f186:	74 34                	je     0x54f1bc
  54f188:	e8 43 c4 1a 00       	call   0x6fb5d0
  54f18d:	85 c0                	test   eax,eax
  54f18f:	75 13                	jne    0x54f1a4
  54f191:	33 f6                	xor    esi,esi
  54f193:	eb 2c                	jmp    0x54f1c1
  54f195:	d9 ee                	fldz
  54f197:	e9 61 ff ff ff       	jmp    0x54f0fd
  54f19c:	d9 ee                	fldz
  54f19e:	eb 9c                	jmp    0x54f13c
  54f1a0:	d9 ee                	fldz
  54f1a2:	eb d3                	jmp    0x54f177
  54f1a4:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  54f1a7:	8b 50 44             	mov    edx,DWORD PTR [eax+0x44]
  54f1aa:	3b 50 40             	cmp    edx,DWORD PTR [eax+0x40]
  54f1ad:	72 07                	jb     0x54f1b6
  54f1af:	8b c7                	mov    eax,edi
  54f1b1:	e8 ea c1 1a 00       	call   0x6fb3a0
  54f1b6:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  54f1b9:	83 ee 40             	sub    esi,0x40
  54f1bc:	8b 36                	mov    esi,DWORD PTR [esi]
  54f1be:	83 c6 10             	add    esi,0x10
  54f1c1:	dd 45 f0             	fld    QWORD PTR [ebp-0x10]
  54f1c4:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  54f1c7:	d9 5d 08             	fstp   DWORD PTR [ebp+0x8]
  54f1ca:	83 ec 0c             	sub    esp,0xc
  54f1cd:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  54f1d0:	d9 5c 24 08          	fstp   DWORD PTR [esp+0x8]
  54f1d4:	dd 45 e8             	fld    QWORD PTR [ebp-0x18]
  54f1d7:	d9 5d 08             	fstp   DWORD PTR [ebp+0x8]
  54f1da:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  54f1dd:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  54f1e1:	dd 45 e0             	fld    QWORD PTR [ebp-0x20]
  54f1e4:	d9 5d 08             	fstp   DWORD PTR [ebp+0x8]
  54f1e7:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  54f1ea:	d9 1c 24             	fstp   DWORD PTR [esp]
  54f1ed:	56                   	push   esi
  54f1ee:	ff 55 f8             	call   DWORD PTR [ebp-0x8]
  54f1f1:	5f                   	pop    edi
  54f1f2:	5e                   	pop    esi
  54f1f3:	33 c0                	xor    eax,eax
  54f1f5:	5b                   	pop    ebx
  54f1f6:	8b e5                	mov    esp,ebp
  54f1f8:	5d                   	pop    ebp
  54f1f9:	c3                   	ret

; CAM06: native LoadRel body

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0054e990 <.text+0x14d990>:
  54e990:	55                   	push   ebp
  54e991:	8b ec                	mov    ebp,esp
  54e993:	83 ec 10             	sub    esp,0x10
  54e996:	f3 0f 10 45 0c       	movss  xmm0,DWORD PTR [ebp+0xc]
  54e99b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  54e99e:	56                   	push   esi
  54e99f:	f3 0f 11 45 f4       	movss  DWORD PTR [ebp-0xc],xmm0
  54e9a4:	f3 0f 10 45 10       	movss  xmm0,DWORD PTR [ebp+0x10]
  54e9a9:	57                   	push   edi
  54e9aa:	8d 41 04             	lea    eax,[ecx+0x4]
  54e9ad:	f3 0f 11 45 f8       	movss  DWORD PTR [ebp-0x8],xmm0
  54e9b2:	f3 0f 10 45 14       	movss  xmm0,DWORD PTR [ebp+0x14]
  54e9b7:	8d 79 08             	lea    edi,[ecx+0x8]
  54e9ba:	8d 75 f4             	lea    esi,[ebp-0xc]
  54e9bd:	89 01                	mov    DWORD PTR [ecx],eax
  54e9bf:	f3 0f 11 45 fc       	movss  DWORD PTR [ebp-0x4],xmm0
  54e9c4:	e8 07 8b 24 00       	call   0x7974d0
  54e9c9:	5f                   	pop    edi
  54e9ca:	5e                   	pop    esi
  54e9cb:	8b e5                	mov    esp,ebp
  54e9cd:	5d                   	pop    ebp
  54e9ce:	c2 10 00             	ret    0x10

; CAM07: camera path reader followed by coordinate offsets

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007974d0 <.text+0x3964d0>:
  7974d0:	8b cf                	mov    ecx,edi
  7974d2:	e8 09 fa ff ff       	call   0x796ee0
  7974d7:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  7974da:	3b 4f 08             	cmp    ecx,DWORD PTR [edi+0x8]
  7974dd:	74 23                	je     0x797502
  7974df:	90                   	nop
  7974e0:	8b 01                	mov    eax,DWORD PTR [ecx]
  7974e2:	d9 00                	fld    DWORD PTR [eax]
  7974e4:	83 c1 04             	add    ecx,0x4
  7974e7:	d8 06                	fadd   DWORD PTR [esi]
  7974e9:	d9 18                	fstp   DWORD PTR [eax]
  7974eb:	d9 40 04             	fld    DWORD PTR [eax+0x4]
  7974ee:	d8 46 04             	fadd   DWORD PTR [esi+0x4]
  7974f1:	d9 58 04             	fstp   DWORD PTR [eax+0x4]
  7974f4:	d9 46 08             	fld    DWORD PTR [esi+0x8]
  7974f7:	d8 40 08             	fadd   DWORD PTR [eax+0x8]
  7974fa:	d9 58 08             	fstp   DWORD PTR [eax+0x8]
  7974fd:	3b 4f 08             	cmp    ecx,DWORD PTR [edi+0x8]
  797500:	75 de                	jne    0x7974e0
  797502:	c3                   	ret

; CAM08: camera XML path and node lookup

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00796f20 <.text+0x395f20>:
  796f20:	8b f9                	mov    edi,ecx
  796f22:	8b f2                	mov    esi,edx
  796f24:	e8 e7 05 00 00       	call   0x797510
  796f29:	8d 44 24 24          	lea    eax,[esp+0x24]
  796f2d:	50                   	push   eax
  796f2e:	8b ce                	mov    ecx,esi
  796f30:	e8 fb 7e f9 ff       	call   0x72ee30
  796f35:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0x0
  796f3c:	00 00 00 00 
  796f40:	83 7c 24 58 10       	cmp    DWORD PTR [esp+0x58],0x10
  796f45:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  796f49:	73 04                	jae    0x796f4f
  796f4b:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  796f4f:	6a 00                	push   0x0
  796f51:	8d 74 24 28          	lea    esi,[esp+0x28]
  796f55:	e8 b6 81 f9 ff       	call   0x72f110
  796f5a:	84 c0                	test   al,al
  796f5c:	0f 84 f7 04 00 00    	je     0x797459
  796f62:	68 b8 f1 c4 00       	push   0xc4f1b8
  796f67:	8b c6                	mov    eax,esi
  796f69:	e8 72 73 f9 ff       	call   0x72e2e0
  796f6e:	68 c4 f1 c4 00       	push   0xc4f1c4
  796f73:	e8 68 73 f9 ff       	call   0x72e2e0
  796f78:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  796f7c:	85 c0                	test   eax,eax
  796f7e:	0f 84 d5 04 00 00    	je     0x797459

; MAP01: Q initializer through LoadMap registration call

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00560600 <.text+0x15f600>:
  560600:	55                   	push   ebp
  560601:	8b ec                	mov    ebp,esp
  560603:	83 ec 08             	sub    esp,0x8
  560606:	8d 4d fc             	lea    ecx,[ebp-0x4]
  560609:	56                   	push   esi
  56060a:	51                   	push   ecx
  56060b:	89 30                	mov    DWORD PTR [eax],esi
  56060d:	e8 2e 58 00 00       	call   0x565e40
  560612:	83 c4 08             	add    esp,0x8
  560615:	50                   	push   eax
  560616:	e8 05 59 00 00       	call   0x565f20
  56061b:	50                   	push   eax
  56061c:	e8 9f 59 00 00       	call   0x565fc0
  560621:	50                   	push   eax
  560622:	e8 39 5a 00 00       	call   0x566060
  560627:	50                   	push   eax
  560628:	e8 d3 5a 00 00       	call   0x566100
  56062d:	50                   	push   eax
  56062e:	e8 6d 5b 00 00       	call   0x5661a0
  560633:	50                   	push   eax
  560634:	e8 07 5c 00 00       	call   0x566240
  560639:	50                   	push   eax
  56063a:	e8 a1 5c 00 00       	call   0x5662e0
  56063f:	50                   	push   eax
  560640:	e8 3b 5d 00 00       	call   0x566380
  560645:	50                   	push   eax
  560646:	e8 d5 5d 00 00       	call   0x566420
  56064b:	50                   	push   eax
  56064c:	e8 6f 5e 00 00       	call   0x5664c0
  560651:	50                   	push   eax
  560652:	e8 09 5f 00 00       	call   0x566560
  560657:	50                   	push   eax
  560658:	e8 a3 5f 00 00       	call   0x566600
  56065d:	50                   	push   eax
  56065e:	e8 3d 60 00 00       	call   0x5666a0
  560663:	50                   	push   eax
  560664:	e8 d7 60 00 00       	call   0x566740
  560669:	50                   	push   eax
  56066a:	e8 71 61 00 00       	call   0x5667e0
  56066f:	50                   	push   eax
  560670:	e8 0b 62 00 00       	call   0x566880
  560675:	50                   	push   eax
  560676:	e8 a5 62 00 00       	call   0x566920
  56067b:	50                   	push   eax
  56067c:	e8 3f 63 00 00       	call   0x5669c0
  560681:	50                   	push   eax
  560682:	e8 d9 63 00 00       	call   0x566a60
  560687:	50                   	push   eax
  560688:	e8 73 64 00 00       	call   0x566b00
  56068d:	50                   	push   eax
  56068e:	e8 0d 65 00 00       	call   0x566ba0
  560693:	50                   	push   eax
  560694:	e8 a7 65 00 00       	call   0x566c40
  560699:	50                   	push   eax
  56069a:	e8 41 66 00 00       	call   0x566ce0
  56069f:	50                   	push   eax
  5606a0:	e8 db 66 00 00       	call   0x566d80
  5606a5:	50                   	push   eax
  5606a6:	e8 75 67 00 00       	call   0x566e20
  5606ab:	50                   	push   eax
  5606ac:	e8 0f 68 00 00       	call   0x566ec0
  5606b1:	50                   	push   eax
  5606b2:	e8 a9 68 00 00       	call   0x566f60
  5606b7:	50                   	push   eax
  5606b8:	e8 43 69 00 00       	call   0x567000
  5606bd:	50                   	push   eax
  5606be:	e8 dd 69 00 00       	call   0x5670a0
  5606c3:	50                   	push   eax
  5606c4:	e8 77 6a 00 00       	call   0x567140
  5606c9:	50                   	push   eax
  5606ca:	e8 11 6b 00 00       	call   0x5671e0
  5606cf:	50                   	push   eax
  5606d0:	e8 ab 6b 00 00       	call   0x567280
  5606d5:	50                   	push   eax
  5606d6:	e8 45 6c 00 00       	call   0x567320
  5606db:	50                   	push   eax
  5606dc:	e8 df 6c 00 00       	call   0x5673c0
  5606e1:	50                   	push   eax
  5606e2:	e8 79 6d 00 00       	call   0x567460
  5606e7:	50                   	push   eax
  5606e8:	e8 13 6e 00 00       	call   0x567500

; MAP02: LoadMap native pointer / Lua closure binding

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00567500 <.text+0x166500>:
  567500:	55                   	push   ebp
  567501:	8b ec                	mov    ebp,esp
  567503:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  567506:	53                   	push   ebx
  567507:	8b 1d 74 27 fe 00    	mov    ebx,DWORD PTR ds:0xfe2774
  56750d:	56                   	push   esi
  56750e:	8b 33                	mov    esi,DWORD PTR [ebx]
  567510:	57                   	push   edi
  567511:	8b 38                	mov    edi,DWORD PTR [eax]
  567513:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  567518:	c7 05 08 28 fe 00 40 	mov    DWORD PTR ds:0xfe2808,0x563c40
  56751f:	3c 56 00 
  567522:	e8 59 e1 18 00       	call   0x6f5680
  567527:	8b 03                	mov    eax,DWORD PTR [ebx]
  567529:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  56752c:	83 e8 10             	sub    eax,0x10
  56752f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  567534:	74 06                	je     0x56753c
  567536:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  56753a:	74 14                	je     0x567550
  56753c:	57                   	push   edi
  56753d:	68 c4 26 c4 00       	push   0xc426c4
  567542:	e8 76 bb 32 00       	call   0x8930bd
  567547:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  567549:	83 c4 08             	add    esp,0x8
  56754c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  567550:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  567556:	8b 37                	mov    esi,DWORD PTR [edi]
  567558:	68 44 a4 d6 00       	push   0xd6a444
  56755d:	e8 ae df 18 00       	call   0x6f5510
  567562:	8b 37                	mov    esi,DWORD PTR [edi]
  567564:	83 c4 04             	add    esp,0x4
  567567:	6a 00                	push   0x0
  567569:	68 60 97 56 00       	push   0x569760
  56756e:	e8 3d e0 18 00       	call   0x6f55b0
  567573:	8b 0f                	mov    ecx,DWORD PTR [edi]
  567575:	51                   	push   ecx
  567576:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  56757b:	e8 70 e2 18 00       	call   0x6f57f0
  567580:	8b 15 74 27 fe 00    	mov    edx,DWORD PTR ds:0xfe2774
  567586:	8b 02                	mov    eax,DWORD PTR [edx]
  567588:	83 c4 0c             	add    esp,0xc
  56758b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  56758f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  567592:	5f                   	pop    edi
  567593:	5e                   	pop    esi
  567594:	5b                   	pop    ebx
  567595:	5d                   	pop    ebp
  567596:	c2 04 00             	ret    0x4

; MAP03: Lua closure passes native function pointer

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00569760 <.text+0x168760>:
  569760:	55                   	push   ebp
  569761:	8b ec                	mov    ebp,esp
  569763:	6a ff                	push   0xffffffff
  569765:	68 c8 83 93 00       	push   0x9383c8
  56976a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  569770:	50                   	push   eax
  569771:	83 ec 0c             	sub    esp,0xc
  569774:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  569779:	33 c5                	xor    eax,ebp
  56977b:	50                   	push   eax
  56977c:	8d 45 f4             	lea    eax,[ebp-0xc]
  56977f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  569785:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  569788:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  56978b:	33 c0                	xor    eax,eax
  56978d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  569790:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  569793:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  569796:	8b 0d 08 28 fe 00    	mov    ecx,DWORD PTR ds:0xfe2808
  56979c:	51                   	push   ecx
  56979d:	8d 45 e8             	lea    eax,[ebp-0x18]
  5697a0:	e8 5b 0b 00 00       	call   0x56a300
  5697a5:	83 c4 04             	add    esp,0x4
  5697a8:	b8 01 00 00 00       	mov    eax,0x1
  5697ad:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5697b0:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5697b7:	59                   	pop    ecx
  5697b8:	8b e5                	mov    esp,ebp
  5697ba:	5d                   	pop    ebp
  5697bb:	c3                   	ret

; MAP04: string argument marshaller indirect call

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0056a300 <.text+0x169300>:
  56a300:	55                   	push   ebp
  56a301:	8b ec                	mov    ebp,esp
  56a303:	53                   	push   ebx
  56a304:	8b 1d 78 27 fe 00    	mov    ebx,DWORD PTR ds:0xfe2778
  56a30a:	56                   	push   esi
  56a30b:	57                   	push   edi
  56a30c:	8b 38                	mov    edi,DWORD PTR [eax]
  56a30e:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  56a311:	83 ee 10             	sub    esi,0x10
  56a314:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  56a318:	74 30                	je     0x56a34a
  56a31a:	e8 b1 12 19 00       	call   0x6fb5d0
  56a31f:	85 c0                	test   eax,eax
  56a321:	75 0f                	jne    0x56a332
  56a323:	33 f6                	xor    esi,esi
  56a325:	56                   	push   esi
  56a326:	8b cb                	mov    ecx,ebx
  56a328:	ff 55 08             	call   DWORD PTR [ebp+0x8]
  56a32b:	5f                   	pop    edi
  56a32c:	5e                   	pop    esi
  56a32d:	33 c0                	xor    eax,eax
  56a32f:	5b                   	pop    ebx
  56a330:	5d                   	pop    ebp
  56a331:	c3                   	ret
  56a332:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  56a335:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  56a338:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  56a33b:	72 07                	jb     0x56a344
  56a33d:	8b c7                	mov    eax,edi
  56a33f:	e8 5c 10 19 00       	call   0x6fb3a0
  56a344:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  56a347:	83 ee 10             	sub    esi,0x10
  56a34a:	8b 36                	mov    esi,DWORD PTR [esi]
  56a34c:	83 c6 10             	add    esi,0x10
  56a34f:	56                   	push   esi
  56a350:	8b cb                	mov    ecx,ebx
  56a352:	ff 55 08             	call   DWORD PTR [ebp+0x8]
  56a355:	5f                   	pop    edi
  56a356:	5e                   	pop    esi
  56a357:	33 c0                	xor    eax,eax
  56a359:	5b                   	pop    ebx
  56a35a:	5d                   	pop    ebp
  56a35b:	c3                   	ret

; MAP05: native map argument, null gate and path liveness

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00563c40 <.text+0x162c40>:
  563c40:	55                   	push   ebp
  563c41:	8b ec                	mov    ebp,esp
  563c43:	83 e4 f8             	and    esp,0xfffffff8
  563c46:	6a ff                	push   0xffffffff
  563c48:	68 c0 64 93 00       	push   0x9364c0
  563c4d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  563c53:	50                   	push   eax
  563c54:	81 ec 28 01 00 00    	sub    esp,0x128
  563c5a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  563c5f:	33 c4                	xor    eax,esp
  563c61:	89 84 24 20 01 00 00 	mov    DWORD PTR [esp+0x120],eax
  563c68:	53                   	push   ebx
  563c69:	56                   	push   esi
  563c6a:	57                   	push   edi
  563c6b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  563c70:	33 c4                	xor    eax,esp
  563c72:	50                   	push   eax
  563c73:	8d 84 24 38 01 00 00 	lea    eax,[esp+0x138]
  563c7a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  563c80:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  563c83:	8b d9                	mov    ebx,ecx
  563c85:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  563c89:	85 c0                	test   eax,eax
  563c8b:	0f 84 de 02 00 00    	je     0x563f6f
  563c91:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  563c98:	75 2f                	jne    0x563cc9
  563c9a:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  563ca1:	c7 84 24 40 01 00 00 	mov    DWORD PTR [esp+0x140],0x0
  563ca8:	00 00 00 00 
  563cac:	e8 2f 51 23 00       	call   0x798de0
  563cb1:	68 e0 d2 bc 00       	push   0xbcd2e0
  563cb6:	e8 5f e6 32 00       	call   0x89231a
  563cbb:	83 c4 04             	add    esp,0x4
  563cbe:	c7 84 24 40 01 00 00 	mov    DWORD PTR [esp+0x140],0xffffffff
  563cc5:	ff ff ff ff 
  563cc9:	8b 35 e8 76 fb 00    	mov    esi,DWORD PTR ds:0xfb76e8
  563ccf:	8b 7b 30             	mov    edi,DWORD PTR [ebx+0x30]
  563cd2:	83 c6 0c             	add    esi,0xc
  563cd5:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  563cdc:	b9 0b 00 00 00       	mov    ecx,0xb
  563ce1:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  563ce3:	bf 01 00 00 00       	mov    edi,0x1
  563ce8:	75 2a                	jne    0x563d14
  563cea:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  563cf0:	89 bc 24 40 01 00 00 	mov    DWORD PTR [esp+0x140],edi
  563cf7:	e8 94 af f7 ff       	call   0x4dec90
  563cfc:	68 30 ce bc 00       	push   0xbcce30
  563d01:	e8 14 e6 32 00       	call   0x89231a
  563d06:	83 c4 04             	add    esp,0x4
  563d09:	c7 84 24 40 01 00 00 	mov    DWORD PTR [esp+0x140],0xffffffff
  563d10:	ff ff ff ff 

; MAP06: native map basename to terrain loader

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00563d14 <.text+0x162d14>:
  563d14:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  563d18:	a1 78 b1 fa 00       	mov    eax,ds:0xfab178
  563d1d:	6a 00                	push   0x0
  563d1f:	6a 00                	push   0x0
  563d21:	68 04 01 00 00       	push   0x104
  563d26:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  563d2a:	51                   	push   ecx
  563d2b:	6a 00                	push   0x0
  563d2d:	6a 00                	push   0x0
  563d2f:	6a 00                	push   0x0
  563d31:	6a 00                	push   0x0
  563d33:	52                   	push   edx
  563d34:	89 43 34             	mov    DWORD PTR [ebx+0x34],eax
  563d37:	e8 a7 2b 33 00       	call   0x8968e3
  563d3c:	83 c4 24             	add    esp,0x24
  563d3f:	6a 00                	push   0x0
  563d41:	8d 74 24 28          	lea    esi,[esp+0x28]
  563d45:	e8 b6 e0 25 00       	call   0x7c1e00
  563d4a:	83 c4 04             	add    esp,0x4
