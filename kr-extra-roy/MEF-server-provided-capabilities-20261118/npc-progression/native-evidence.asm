; N-lua-status | selected native span; not full-program semantics

KR_BIN_SHA9741d197:     file format pei-i386


Disassembly of section .text:

004a9460 <.text+0xa8460>:
  4a9460:	55                   	push   ebp
  4a9461:	8b ec                	mov    ebp,esp
  4a9463:	51                   	push   ecx
  4a9464:	b9 01 00 00 00       	mov    ecx,0x1
  4a9469:	84 0d ec 79 fb 00    	test   BYTE PTR ds:0xfb79ec,cl
  4a946f:	75 34                	jne    0x4a94a5
  4a9471:	09 0d ec 79 fb 00    	or     DWORD PTR ds:0xfb79ec,ecx
  4a9477:	33 c0                	xor    eax,eax
  4a9479:	68 70 d2 bc 00       	push   0xbcd270
  4a947e:	c7 05 f0 79 fb 00 68 	mov    DWORD PTR ds:0xfb79f0,0xc0f868
  4a9485:	f8 c0 00 
  4a9488:	a3 f4 79 fb 00       	mov    ds:0xfb79f4,eax
  4a948d:	a3 f8 79 fb 00       	mov    ds:0xfb79f8,eax
  4a9492:	a3 fc 79 fb 00       	mov    ds:0xfb79fc,eax
  4a9497:	89 0d 04 7a fb 00    	mov    DWORD PTR ds:0xfb7a04,ecx
  4a949d:	e8 78 8e 3e 00       	call   0x89231a
  4a94a2:	83 c4 04             	add    esp,0x4
  4a94a5:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4a94a8:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4a94ab:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4a94ae:	50                   	push   eax
  4a94af:	51                   	push   ecx
  4a94b0:	52                   	push   edx
  4a94b1:	ba f0 79 fb 00       	mov    edx,0xfb79f0
  4a94b6:	e8 85 b4 09 00       	call   0x544940
  4a94bb:	59                   	pop    ecx
  4a94bc:	5d                   	pop    ebp
  4a94bd:	c2 0c 00             	ret    0xc

; N-result-copy | Payload DWORD copies and final WORD copy; +32 result projects +12..+15

KR_BIN_SHA9741d197:     file format pei-i386


Disassembly of section .text:

004c45d5 <.text+0xc35d5>:
  4c45d5:	a1 f8 18 fe 00       	mov    eax,ds:0xfe18f8
  4c45da:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  4c45dd:	89 48 24             	mov    DWORD PTR [eax+0x24],ecx
  4c45e0:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  4c45e3:	89 50 28             	mov    DWORD PTR [eax+0x28],edx
  4c45e6:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  4c45e9:	89 48 2c             	mov    DWORD PTR [eax+0x2c],ecx
  4c45ec:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  4c45ef:	89 50 30             	mov    DWORD PTR [eax+0x30],edx
  4c45f2:	66 8b 4e 14          	mov    cx,WORD PTR [esi+0x14]
  4c45f6:	66 89 48 34          	mov    WORD PTR [eax+0x34],cx

; N-result-skillexp | UIText2C6, manager+32 to first numeric result control

KR_BIN_SHA9741d197:     file format pei-i386


Disassembly of section .text:

006ba45f <.text+0x2b945f>:
  6ba45f:	8d 45 d0             	lea    eax,[ebp-0x30]
  6ba462:	50                   	push   eax
  6ba463:	8d 45 cc             	lea    eax,[ebp-0x34]
  6ba466:	b9 c4 5a fe 00       	mov    ecx,0xfe5ac4
  6ba46b:	c7 45 d0 c6 02 00 00 	mov    DWORD PTR [ebp-0x30],0x2c6
  6ba472:	e8 79 9c eb ff       	call   0x5740f0
  6ba477:	8b 45 cc             	mov    eax,DWORD PTR [ebp-0x34]
  6ba47a:	3b 05 c8 5a fe 00    	cmp    eax,DWORD PTR ds:0xfe5ac8
  6ba480:	74 0d                	je     0x6ba48f
  6ba482:	83 78 24 08          	cmp    DWORD PTR [eax+0x24],0x8
  6ba486:	8d 48 10             	lea    ecx,[eax+0x10]
  6ba489:	72 0a                	jb     0x6ba495
  6ba48b:	8b 09                	mov    ecx,DWORD PTR [ecx]
  6ba48d:	eb 06                	jmp    0x6ba495
  6ba48f:	cc                   	int3
  6ba490:	b9 fc d1 be 00       	mov    ecx,0xbed1fc
  6ba495:	8b b7 f4 00 00 00    	mov    esi,DWORD PTR [edi+0xf4]
  6ba49b:	8d b6 e8 00 00 00    	lea    esi,[esi+0xe8]
  6ba4a1:	e8 6a d2 09 00       	call   0x757710
  6ba4a6:	8b 8f f4 00 00 00    	mov    ecx,DWORD PTR [edi+0xf4]
  6ba4ac:	8b 11                	mov    edx,DWORD PTR [ecx]
  6ba4ae:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  6ba4b4:	ff d0                	call   eax
  6ba4b6:	8b 1d f8 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe18f8
  6ba4bc:	8b 53 2e             	mov    edx,DWORD PTR [ebx+0x2e]
  6ba4bf:	8b 43 2a             	mov    eax,DWORD PTR [ebx+0x2a]
  6ba4c2:	8b 4b 32             	mov    ecx,DWORD PTR [ebx+0x32]
  6ba4c5:	8d 75 d4             	lea    esi,[ebp-0x2c]
  6ba4c8:	89 55 d0             	mov    DWORD PTR [ebp-0x30],edx
  6ba4cb:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  6ba4ce:	e8 ad 4a d5 ff       	call   0x40ef80
  6ba4d3:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  6ba4da:	8b b7 f8 00 00 00    	mov    esi,DWORD PTR [edi+0xf8]
  6ba4e0:	50                   	push   eax
  6ba4e1:	8d b6 e8 00 00 00    	lea    esi,[esi+0xe8]
  6ba4e7:	e8 14 d3 09 00       	call   0x757800

; N-reward-type3-ui | Quest record+84 to UIText164

KR_BIN_SHA9741d197:     file format pei-i386


Disassembly of section .text:

006351ee <.text+0x2341ee>:
  6351ee:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  6351f2:	8b 89 84 00 00 00    	mov    ecx,DWORD PTR [ecx+0x84]
  6351f8:	83 ec 1c             	sub    esp,0x1c
  6351fb:	8b f4                	mov    esi,esp
  6351fd:	89 64 24 30          	mov    DWORD PTR [esp+0x30],esp
  635201:	e8 ea db dd ff       	call   0x412df0
  635206:	b3 1d                	mov    bl,0x1d
  635208:	88 9c 24 dc 00 00 00 	mov    BYTE PTR [esp+0xdc],bl
  63520f:	f6 05 e4 5a fe 00 01 	test   BYTE PTR ds:0xfe5ae4,0x1
  635216:	75 2d                	jne    0x635245
  635218:	83 0d e4 5a fe 00 01 	or     DWORD PTR ds:0xfe5ae4,0x1
  63521f:	68 c4 5a fe 00       	push   0xfe5ac4
  635224:	c6 84 24 e0 00 00 00 	mov    BYTE PTR [esp+0xe0],0x1e
  63522b:	1e 
  63522c:	e8 0f fa f4 ff       	call   0x584c40
  635231:	68 90 f3 bc 00       	push   0xbcf390
  635236:	e8 df d0 25 00       	call   0x89231a
  63523b:	83 c4 04             	add    esp,0x4
  63523e:	88 9c 24 dc 00 00 00 	mov    BYTE PTR [esp+0xdc],bl
  635245:	8d 54 24 30          	lea    edx,[esp+0x30]
  635249:	52                   	push   edx
  63524a:	8d 44 24 38          	lea    eax,[esp+0x38]
  63524e:	b9 c4 5a fe 00       	mov    ecx,0xfe5ac4
  635253:	c7 44 24 34 64 01 00 	mov    DWORD PTR [esp+0x34],0x164
  63525a:	00 
  63525b:	e8 90 ee f3 ff       	call   0x5740f0
  635260:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  635264:	3b 05 c8 5a fe 00    	cmp    eax,DWORD PTR ds:0xfe5ac8
  63526a:	74 0d                	je     0x635279
  63526c:	83 c0 10             	add    eax,0x10
  63526f:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  635273:	72 0a                	jb     0x63527f
  635275:	8b 00                	mov    eax,DWORD PTR [eax]
  635277:	eb 06                	jmp    0x63527f
  635279:	cc                   	int3
  63527a:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  63527f:	50                   	push   eax
  635280:	8d 74 24 60          	lea    esi,[esp+0x60]
  635284:	c6 84 24 e0 00 00 00 	mov    BYTE PTR [esp+0xe0],0xf
  63528b:	0f 
  63528c:	e8 ef f9 de ff       	call   0x424c80
  635291:	83 c4 20             	add    esp,0x20
  635294:	bb 08 00 00 00       	mov    ebx,0x8
  635299:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x1f
  6352a0:	1f 
  6352a1:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  6352a4:	72 02                	jb     0x6352a8
  6352a6:	8b 00                	mov    eax,DWORD PTR [eax]
  6352a8:	8b b7 08 01 00 00    	mov    esi,DWORD PTR [edi+0x108]
  6352ae:	8d b6 e8 00 00 00    	lea    esi,[esi+0xe8]
  6352b4:	8b c8                	mov    ecx,eax
  6352b6:	e8 55 24 12 00       	call   0x757710

; N-type3-switch | type-1 index into six-case jump table

KR_BIN_SHA9741d197:     file format pei-i386


Disassembly of section .text:

00504d96 <.text+0x103d96>:
  504d96:	8d 4b ff             	lea    ecx,[ebx-0x1]
  504d99:	83 f9 05             	cmp    ecx,0x5
  504d9c:	77 78                	ja     0x504e16
  504d9e:	ff 24 8d 54 55 50 00 	jmp    DWORD PTR [ecx*4+0x505554]

; N-type3-store | third reward case writes local record base+84

KR_BIN_SHA9741d197:     file format pei-i386


Disassembly of section .text:

00504deb <.text+0x103deb>:
  504deb:	89 84 24 e8 00 00 00 	mov    DWORD PTR [esp+0xe8],eax
  504df2:	eb 22                	jmp    0x504e16

; N-result-return | F431F zero-value branch emits C2S0033 with two-byte body

KR_BIN_SHA9741d197:     file format pei-i386


Disassembly of section .text:

005aae80 <.text+0x1a9e80>:
  5aae80:	55                   	push   ebp
  5aae81:	8b ec                	mov    ebp,esp
  5aae83:	56                   	push   esi
  5aae84:	57                   	push   edi
  5aae85:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5aae88:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  5aae8b:	2d 1d 43 0f 00       	sub    eax,0xf431d
  5aae90:	8b f1                	mov    esi,ecx
  5aae92:	74 0c                	je     0x5aaea0
  5aae94:	83 e8 0b             	sub    eax,0xb
  5aae97:	75 10                	jne    0x5aaea9
  5aae99:	e8 32 a9 ff ff       	call   0x5a57d0
  5aae9e:	eb 09                	jmp    0x5aaea9
  5aaea0:	8b cf                	mov    ecx,edi
  5aaea2:	8b d6                	mov    edx,esi
  5aaea4:	e8 37 ab ff ff       	call   0x5a59e0
  5aaea9:	81 7f 10 1f 43 0f 00 	cmp    DWORD PTR [edi+0x10],0xf431f
  5aaeb0:	75 7f                	jne    0x5aaf31
  5aaeb2:	83 7f 14 00          	cmp    DWORD PTR [edi+0x14],0x0
  5aaeb6:	74 32                	je     0x5aaeea
  5aaeb8:	8b 8e 64 01 00 00    	mov    ecx,DWORD PTR [esi+0x164]
  5aaebe:	8b 01                	mov    eax,DWORD PTR [ecx]
  5aaec0:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  5aaec6:	ff d2                	call   edx
  5aaec8:	8b 86 68 01 00 00    	mov    eax,DWORD PTR [esi+0x168]
  5aaece:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  5aaed1:	50                   	push   eax
  5aaed2:	e8 39 44 11 00       	call   0x6bf310
  5aaed7:	8b 8e 68 01 00 00    	mov    ecx,DWORD PTR [esi+0x168]
  5aaedd:	51                   	push   ecx
  5aaede:	56                   	push   esi
  5aaedf:	e8 1c bf fe ff       	call   0x596e00
  5aaee4:	5f                   	pop    edi
  5aaee5:	5e                   	pop    esi
  5aaee6:	5d                   	pop    ebp
  5aaee7:	c2 04 00             	ret    0x4
  5aaeea:	b8 01 00 00 00       	mov    eax,0x1
  5aaeef:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  5aaef5:	75 13                	jne    0x5aaf0a
  5aaef7:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  5aaefd:	68 10 cf bc 00       	push   0xbccf10
  5aaf02:	e8 13 74 2e 00       	call   0x89231a
  5aaf07:	83 c4 04             	add    esp,0x4
  5aaf0a:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5aaf11:	ba 33 00 00 00       	mov    edx,0x33
  5aaf16:	66 89 55 0a          	mov    WORD PTR [ebp+0xa],dx
  5aaf1a:	75 15                	jne    0x5aaf31
  5aaf1c:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5aaf22:	8b 01                	mov    eax,DWORD PTR [ecx]
  5aaf24:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5aaf27:	6a 02                	push   0x2
  5aaf29:	8d 55 0a             	lea    edx,[ebp+0xa]
  5aaf2c:	52                   	push   edx
  5aaf2d:	6a 00                	push   0x0
  5aaf2f:	ff d0                	call   eax
  5aaf31:	5f                   	pop    edi
  5aaf32:	5e                   	pop    esi
  5aaf33:	5d                   	pop    ebp
  5aaf34:	c2 04 00             	ret    0x4
