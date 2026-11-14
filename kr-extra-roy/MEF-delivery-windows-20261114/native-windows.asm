
; game: receive/constructor_holder_identity 0x48ab70..0x48acd0 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0048ab70 <.data>:
  48ab70:	55                   	push   ebp
  48ab71:	8b ec                	mov    ebp,esp
  48ab73:	6a ff                	push   0xffffffff
  48ab75:	68 3d a7 93 00       	push   0x93a73d
  48ab7a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  48ab80:	50                   	push   eax
  48ab81:	83 ec 10             	sub    esp,0x10
  48ab84:	53                   	push   ebx
  48ab85:	56                   	push   esi
  48ab86:	57                   	push   edi
  48ab87:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  48ab8c:	33 c5                	xor    eax,ebp
  48ab8e:	50                   	push   eax
  48ab8f:	8d 45 f4             	lea    eax,[ebp-0xc]
  48ab92:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  48ab98:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  48ab9b:	c7 07 18 5b c0 00    	mov    DWORD PTR [edi],0xc05b18
  48aba1:	89 3d 18 13 fb 00    	mov    DWORD PTR ds:0xfb1318,edi
  48aba7:	33 db                	xor    ebx,ebx
  48aba9:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  48abac:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  48abb3:	8d 73 01             	lea    esi,[ebx+0x1]
  48abb6:	75 1c                	jne    0x48abd4
  48abb8:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  48abbe:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  48abc2:	e8 89 4c 0c 00       	call   0x54f850
  48abc7:	68 80 d5 bc 00       	push   0xbcd580
  48abcc:	e8 49 77 40 00       	call   0x89231a
  48abd1:	83 c4 04             	add    esp,0x4
  48abd4:	66 39 1d ba 92 fb 00 	cmp    WORD PTR ds:0xfb92ba,bx
  48abdb:	7e 31                	jle    0x48ac0e
  48abdd:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  48abe4:	75 1c                	jne    0x48ac02
  48abe6:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  48abec:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  48abf0:	e8 5b 4c 0c 00       	call   0x54f850
  48abf5:	68 80 d5 bc 00       	push   0xbcd580
  48abfa:	e8 1b 77 40 00       	call   0x89231a
  48abff:	83 c4 04             	add    esp,0x4
  48ac02:	0f bf 05 ba 92 fb 00 	movsx  eax,WORD PTR ds:0xfb92ba
  48ac09:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  48ac0c:	eb 07                	jmp    0x48ac15
  48ac0e:	c7 45 f0 00 03 00 00 	mov    DWORD PTR [ebp-0x10],0x300
  48ac15:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  48ac1c:	75 1c                	jne    0x48ac3a
  48ac1e:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  48ac24:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  48ac28:	e8 23 4c 0c 00       	call   0x54f850
  48ac2d:	68 80 d5 bc 00       	push   0xbcd580
  48ac32:	e8 e3 76 40 00       	call   0x89231a
  48ac37:	83 c4 04             	add    esp,0x4
  48ac3a:	66 39 1d aa 92 fb 00 	cmp    WORD PTR ds:0xfb92aa,bx
  48ac41:	7e 2e                	jle    0x48ac71
  48ac43:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  48ac4a:	75 1c                	jne    0x48ac68
  48ac4c:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  48ac52:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  48ac56:	e8 f5 4b 0c 00       	call   0x54f850
  48ac5b:	68 80 d5 bc 00       	push   0xbcd580
  48ac60:	e8 b5 76 40 00       	call   0x89231a
  48ac65:	83 c4 04             	add    esp,0x4
  48ac68:	0f bf 0d aa 92 fb 00 	movsx  ecx,WORD PTR ds:0xfb92aa
  48ac6f:	eb 05                	jmp    0x48ac76
  48ac71:	b9 00 04 00 00       	mov    ecx,0x400
  48ac76:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  48ac79:	8d 77 08             	lea    esi,[edi+0x8]
  48ac7c:	e8 1f 3e 25 00       	call   0x6deaa0
  48ac81:	8d 87 48 01 00 00    	lea    eax,[edi+0x148]
  48ac87:	e8 f4 96 37 00       	call   0x804380
  48ac8c:	c7 87 00 02 00 00 38 	mov    DWORD PTR [edi+0x200],0xc05b38
  48ac93:	5b c0 00 
  48ac96:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  48ac9a:	c7 00 ec 5a c0 00    	mov    DWORD PTR [eax],0xc05aec
  48aca0:	c7 07 9c 5a c0 00    	mov    DWORD PTR [edi],0xc05a9c
  48aca6:	c7 06 a4 5a c0 00    	mov    DWORD PTR [esi],0xc05aa4
  48acac:	c7 87 00 02 00 00 04 	mov    DWORD PTR [edi+0x200],0xc05b04
  48acb3:	5b c0 00 
  48acb6:	89 9f 60 bf 00 00    	mov    DWORD PTR [edi+0xbf60],ebx
  48acbc:	89 9f 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],ebx
  48acc2:	89 9f 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],ebx
  48acc8:	89 9f 6c bf 00 00    	mov    DWORD PTR [edi+0xbf6c],ebx
  48acce:	c7                   	.byte 0xc7
  48accf:	87                   	.byte 0x87

; game: receive/app_tick 0x490fe0..0x49201c (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00490fe0 <.data>:
  490fe0:	55                   	push   ebp
  490fe1:	8b ec                	mov    ebp,esp
  490fe3:	83 e4 f8             	and    esp,0xfffffff8
  490fe6:	6a ff                	push   0xffffffff
  490fe8:	68 d0 98 94 00       	push   0x9498d0
  490fed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  490ff3:	50                   	push   eax
  490ff4:	81 ec 40 03 00 00    	sub    esp,0x340
  490ffa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  490fff:	33 c4                	xor    eax,esp
  491001:	89 84 24 38 03 00 00 	mov    DWORD PTR [esp+0x338],eax
  491008:	53                   	push   ebx
  491009:	56                   	push   esi
  49100a:	57                   	push   edi
  49100b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  491010:	33 c4                	xor    eax,esp
  491012:	50                   	push   eax
  491013:	8d 84 24 50 03 00 00 	lea    eax,[esp+0x350]
  49101a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  491020:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  491023:	33 f6                	xor    esi,esi
  491025:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  491029:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49102f:	75 14                	jne    0x491045
  491031:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491037:	74 07                	je     0x491040
  491039:	e8 22 9f 00 00       	call   0x49af60
  49103e:	eb 05                	jmp    0x491045
  491040:	e8 bb 9f 00 00       	call   0x49b000
  491045:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  49104b:	8b 41 34             	mov    eax,DWORD PTR [ecx+0x34]
  49104e:	50                   	push   eax
  49104f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  491055:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49105b:	75 14                	jne    0x491071
  49105d:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491063:	74 07                	je     0x49106c
  491065:	e8 f6 9e 00 00       	call   0x49af60
  49106a:	eb 05                	jmp    0x491071
  49106c:	e8 8f 9f 00 00       	call   0x49b000
  491071:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491077:	8b 4a 28             	mov    ecx,DWORD PTR [edx+0x28]
  49107a:	8b 01                	mov    eax,DWORD PTR [ecx]
  49107c:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  491080:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  491084:	3b c1                	cmp    eax,ecx
  491086:	0f 84 4a 01 00 00    	je     0x4911d6
  49108c:	8b 58 08             	mov    ebx,DWORD PTR [eax+0x8]
  49108f:	39 b3 ac a0 00 00    	cmp    DWORD PTR [ebx+0xa0ac],esi
  491095:	75 0b                	jne    0x4910a2
  491097:	8b 00                	mov    eax,DWORD PTR [eax]
  491099:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  49109d:	e9 2c 01 00 00       	jmp    0x4911ce
  4910a2:	a1 04 f7 fd 00       	mov    eax,ds:0xfdf704
  4910a7:	bf 01 00 00 00       	mov    edi,0x1
  4910ac:	03 c7                	add    eax,edi
  4910ae:	50                   	push   eax
  4910af:	68 68 58 c0 00       	push   0xc05868
  4910b4:	a3 04 f7 fd 00       	mov    ds:0xfdf704,eax
  4910b9:	e8 a6 20 40 00       	call   0x893164
  4910be:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  4910c2:	83 c4 08             	add    esp,0x8
  4910c5:	39 98 58 bf 00 00    	cmp    DWORD PTR [eax+0xbf58],ebx
  4910cb:	75 50                	jne    0x49111d
  4910cd:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4910d4:	75 35                	jne    0x49110b
  4910d6:	09 3d d0 ac fb 00    	or     DWORD PTR ds:0xfbacd0,edi
  4910dc:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  4910e3:	89 35 d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,esi
  4910e9:	e8 12 52 24 00       	call   0x6d6300
  4910ee:	68 70 d6 bc 00       	push   0xbcd670
  4910f3:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4910f8:	e8 1d 12 40 00       	call   0x89231a
  4910fd:	83 c4 04             	add    esp,0x4
  491100:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491107:	ff ff ff ff 
  49110b:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491111:	3b ce                	cmp    ecx,esi
  491113:	74 08                	je     0x49111d
  491115:	8b 11                	mov    edx,DWORD PTR [ecx]
  491117:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  49111a:	57                   	push   edi
  49111b:	ff d0                	call   eax
  49111d:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491122:	3b c6                	cmp    eax,esi
  491124:	75 56                	jne    0x49117c
  491126:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  49112c:	74 0c                	je     0x49113a
  49112e:	e8 2d 9e 00 00       	call   0x49af60
  491133:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491138:	eb 42                	jmp    0x49117c
  49113a:	f6 05 00 12 fc 00 01 	test   BYTE PTR ds:0xfc1200,0x1
  491141:	75 2f                	jne    0x491172
  491143:	09 3d 00 12 fc 00    	or     DWORD PTR ds:0xfc1200,edi
  491149:	68 08 12 fc 00       	push   0xfc1208
  49114e:	89 bc 24 5c 03 00 00 	mov    DWORD PTR [esp+0x35c],edi
  491155:	e8 06 43 37 00       	call   0x805460
  49115a:	68 70 e6 bc 00       	push   0xbce670
  49115f:	e8 b6 11 40 00       	call   0x89231a
  491164:	83 c4 04             	add    esp,0x4
  491167:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  49116e:	ff ff ff ff 
  491172:	b8 08 12 fc 00       	mov    eax,0xfc1208
  491177:	a3 58 a8 fb 00       	mov    ds:0xfba858,eax
  49117c:	ff 48 44             	dec    DWORD PTR [eax+0x44]
  49117f:	8b 78 48             	mov    edi,DWORD PTR [eax+0x48]
  491182:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  491185:	8d 70 48             	lea    esi,[eax+0x48]
  491188:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  49118c:	51                   	push   ecx
  49118d:	52                   	push   edx
  49118e:	57                   	push   edi
  49118f:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  491193:	e8 68 c5 2b 00       	call   0x74d700
  491198:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  49119b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  4911a0:	2b d1                	sub    edx,ecx
  4911a2:	83 fa 01             	cmp    edx,0x1
  4911a5:	72 46                	jb     0x4911ed
  4911a7:	41                   	inc    ecx
  4911a8:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  4911ab:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4911ae:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4911b1:	89 01                	mov    DWORD PTR [ecx],eax
  4911b3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911b7:	c7 43 14 00 00 00 00 	mov    DWORD PTR [ebx+0x14],0x0
  4911be:	8b 08                	mov    ecx,DWORD PTR [eax]
  4911c0:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4911c4:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4911c8:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911cc:	33 f6                	xor    esi,esi
  4911ce:	3b c1                	cmp    eax,ecx
  4911d0:	0f 85 b6 fe ff ff    	jne    0x49108c
  4911d6:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  4911dc:	75 1e                	jne    0x4911fc
  4911de:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  4911e4:	74 11                	je     0x4911f7
  4911e6:	e8 75 9d 00 00       	call   0x49af60
  4911eb:	eb 0f                	jmp    0x4911fc
  4911ed:	68 34 20 bf 00       	push   0xbf2034
  4911f2:	e8 39 c9 3e 00       	call   0x87db30
  4911f7:	e8 04 9e 00 00       	call   0x49b000
  4911fc:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491202:	52                   	push   edx
  491203:	e8 38 49 37 00       	call   0x805b40
  491208:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49120e:	75 14                	jne    0x491224
  491210:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491216:	74 07                	je     0x49121f
  491218:	e8 43 9d 00 00       	call   0x49af60
  49121d:	eb 05                	jmp    0x491224
  49121f:	e8 dc 9d 00 00       	call   0x49b000
  491224:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491229:	8b 40 34             	mov    eax,DWORD PTR [eax+0x34]
  49122c:	50                   	push   eax
  49122d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  491233:	bf 01 00 00 00       	mov    edi,0x1
  491238:	29 3d 78 dd f7 00    	sub    DWORD PTR ds:0xf7dd78,edi
  49123e:	75 19                	jne    0x491259
  491240:	8b 0d 04 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba804
  491246:	51                   	push   ecx
  491247:	e8 15 1e 40 00       	call   0x893061
  49124c:	83 c4 04             	add    esp,0x4
  49124f:	c7 05 78 dd f7 00 78 	mov    DWORD PTR ds:0xf7dd78,0x78
  491256:	00 00 00 
  491259:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  491260:	75 19                	jne    0x49127b
  491262:	09 3d f8 8b fd 00    	or     DWORD PTR ds:0xfd8bf8,edi
  491268:	68 10 e3 bc 00       	push   0xbce310
  49126d:	89 35 fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,esi
  491273:	e8 a2 10 40 00       	call   0x89231a
  491278:	83 c4 04             	add    esp,0x4
  49127b:	8b 1d a0 25 bd 00    	mov    ebx,DWORD PTR ds:0xbd25a0
  491281:	39 35 00 8c fd 00    	cmp    DWORD PTR ds:0xfd8c00,esi
  491287:	74 46                	je     0x4912cf
  491289:	ff d3                	call   ebx
  49128b:	8b f8                	mov    edi,eax
  49128d:	8b d7                	mov    edx,edi
  49128f:	2b 15 fc 8b fd 00    	sub    edx,DWORD PTR ds:0xfd8bfc
  491295:	81 fa 60 ea 00 00    	cmp    edx,0xea60
  49129b:	72 2d                	jb     0x4912ca
  49129d:	b8 a7 00 00 00       	mov    eax,0xa7
  4912a2:	66 89 44 24 14       	mov    WORD PTR [esp+0x14],ax
  4912a7:	39 35 98 a7 fb 00    	cmp    DWORD PTR ds:0xfba798,esi
  4912ad:	75 15                	jne    0x4912c4
  4912af:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4912b5:	8b 11                	mov    edx,DWORD PTR [ecx]
  4912b7:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4912ba:	6a 02                	push   0x2
  4912bc:	8d 44 24 18          	lea    eax,[esp+0x18]
  4912c0:	50                   	push   eax
  4912c1:	56                   	push   esi
  4912c2:	ff d2                	call   edx
  4912c4:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4912ca:	bf 01 00 00 00       	mov    edi,0x1
  4912cf:	f6 05 c0 0f fc 00 01 	test   BYTE PTR ds:0xfc0fc0,0x1
  4912d6:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4912da:	75 2e                	jne    0x49130a
  4912dc:	09 3d c0 0f fc 00    	or     DWORD PTR ds:0xfc0fc0,edi
  4912e2:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x2
  4912e9:	02 00 00 00 
  4912ed:	e8 5e 7b 24 00       	call   0x6d8e50
  4912f2:	68 b0 db bc 00       	push   0xbcdbb0
  4912f7:	e8 1e 10 40 00       	call   0x89231a
  4912fc:	83 c4 04             	add    esp,0x4
  4912ff:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491306:	ff ff ff ff 
  49130a:	b9 c8 0f fc 00       	mov    ecx,0xfc0fc8
  49130f:	e8 ec 8b 24 00       	call   0x6d9f00
  491314:	f6 05 98 16 fc 00 01 	test   BYTE PTR ds:0xfc1698,0x1
  49131b:	75 18                	jne    0x491335
  49131d:	09 3d 98 16 fc 00    	or     DWORD PTR ds:0xfc1698,edi
  491323:	e8 78 b5 37 00       	call   0x80c8a0
  491328:	68 20 e3 bc 00       	push   0xbce320
  49132d:	e8 e8 0f 40 00       	call   0x89231a
  491332:	83 c4 04             	add    esp,0x4
  491335:	bf a0 16 fc 00       	mov    edi,0xfc16a0
  49133a:	e8 d1 b6 37 00       	call   0x80ca10
  49133f:	f6 05 f4 f6 fd 00 01 	test   BYTE PTR ds:0xfdf6f4,0x1
  491346:	75 22                	jne    0x49136a
  491348:	83 0d f4 f6 fd 00 01 	or     DWORD PTR ds:0xfdf6f4,0x1
  49134f:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x3
  491356:	03 00 00 00 
  49135a:	e8 31 a1 00 00       	call   0x49b490
  49135f:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491366:	ff ff ff ff 
  49136a:	f6 05 d8 48 fe 00 01 	test   BYTE PTR ds:0xfe48d8,0x1
  491371:	75 0c                	jne    0x49137f
  491373:	83 0d d8 48 fe 00 01 	or     DWORD PTR ds:0xfe48d8,0x1
  49137a:	e8 91 9f 00 00       	call   0x49b310
  49137f:	be 30 37 fe 00       	mov    esi,0xfe3730
  491384:	e8 07 a0 00 00       	call   0x49b390
  491389:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  491390:	75 2f                	jne    0x4913c1
  491392:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  491399:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x4
  4913a0:	04 00 00 00 
  4913a4:	e8 e7 01 05 00       	call   0x4e1590
  4913a9:	68 80 cc bc 00       	push   0xbccc80
  4913ae:	e8 67 0f 40 00       	call   0x89231a
  4913b3:	83 c4 04             	add    esp,0x4
  4913b6:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  4913bd:	ff ff ff ff 
  4913c1:	ff d3                	call   ebx
  4913c3:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4913ca:	a3 3c 42 f9 00       	mov    ds:0xf9423c,eax
  4913cf:	75 2f                	jne    0x491400
  4913d1:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4913d8:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x5
  4913df:	05 00 00 00 
  4913e3:	e8 a8 01 05 00       	call   0x4e1590
  4913e8:	68 80 cc bc 00       	push   0xbccc80
  4913ed:	e8 28 0f 40 00       	call   0x89231a
  4913f2:	83 c4 04             	add    esp,0x4
  4913f5:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  4913fc:	ff ff ff ff 
  491400:	bf e0 d9 f8 00       	mov    edi,0xf8d9e0
  491405:	e8 56 08 05 00       	call   0x4e1c60
  49140a:	a1 0c a8 fb 00       	mov    eax,ds:0xfba80c
  49140f:	33 db                	xor    ebx,ebx
  491411:	3b c3                	cmp    eax,ebx
  491413:	75 21                	jne    0x491436
  491415:	68 7c 05 00 00       	push   0x57c
  49141a:	e8 49 fe 3f 00       	call   0x891268
  49141f:	83 c4 04             	add    esp,0x4
  491422:	3b c3                	cmp    eax,ebx
  491424:	74 09                	je     0x49142f
  491426:	8b f0                	mov    esi,eax
  491428:	e8 43 ff 25 00       	call   0x6f1370
  49142d:	eb 02                	jmp    0x491431
  49142f:	33 c0                	xor    eax,eax
  491431:	a3 0c a8 fb 00       	mov    ds:0xfba80c,eax
  491436:	50                   	push   eax
  491437:	e8 74 02 26 00       	call   0x6f16b0
  49143c:	f6 05 70 1a fc 00 01 	test   BYTE PTR ds:0xfc1a70,0x1
  491443:	bf 01 00 00 00       	mov    edi,0x1
  491448:	75 22                	jne    0x49146c
  49144a:	09 3d 70 1a fc 00    	or     DWORD PTR ds:0xfc1a70,edi
  491450:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x6
  491457:	06 00 00 00 
  49145b:	e8 f0 e7 23 00       	call   0x6cfc50
  491460:	83 ce ff             	or     esi,0xffffffff
  491463:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  49146a:	eb 03                	jmp    0x49146f
  49146c:	83 ce ff             	or     esi,0xffffffff
  49146f:	68 78 1a fc 00       	push   0xfc1a78
  491474:	e8 77 e8 23 00       	call   0x6cfcf0
  491479:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  491480:	75 2a                	jne    0x4914ac
  491482:	09 3d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,edi
  491488:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x7
  49148f:	07 00 00 00 
  491493:	e8 b8 f2 23 00       	call   0x6d0750
  491498:	68 30 d5 bc 00       	push   0xbcd530
  49149d:	e8 78 0e 40 00       	call   0x89231a
  4914a2:	83 c4 04             	add    esp,0x4
  4914a5:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  4914ac:	b9 30 88 fb 00       	mov    ecx,0xfb8830
  4914b1:	e8 ca ff 23 00       	call   0x6d1480
  4914b6:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  4914bd:	75 2a                	jne    0x4914e9
  4914bf:	09 3d ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,edi
  4914c5:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x8
  4914cc:	08 00 00 00 
  4914d0:	e8 cb 08 24 00       	call   0x6d1da0
  4914d5:	68 30 e3 bc 00       	push   0xbce330
  4914da:	e8 3b 0e 40 00       	call   0x89231a
  4914df:	83 c4 04             	add    esp,0x4
  4914e2:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  4914e9:	68 f0 f3 fd 00       	push   0xfdf3f0
  4914ee:	e8 7d 29 24 00       	call   0x6d3e70
  4914f3:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4914fa:	75 2a                	jne    0x491526
  4914fc:	09 3d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,edi
  491502:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x9
  491509:	09 00 00 00 
  49150d:	e8 6e 5f 0f 00       	call   0x587480
  491512:	68 c0 cc bc 00       	push   0xbcccc0
  491517:	e8 fe 0d 40 00       	call   0x89231a
  49151c:	83 c4 04             	add    esp,0x4
  49151f:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  491526:	68 d8 ad fa 00       	push   0xfaadd8
  49152b:	e8 20 8d 0f 00       	call   0x58a250
  491530:	e8 0b f8 ff ff       	call   0x490d40
  491535:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491539:	8d 77 f8             	lea    esi,[edi-0x8]
  49153c:	e8 df f8 ff ff       	call   0x490e20
  491541:	a1 0c a8 fb 00       	mov    eax,ds:0xfba80c
  491546:	3b c3                	cmp    eax,ebx
  491548:	75 21                	jne    0x49156b
  49154a:	68 7c 05 00 00       	push   0x57c
  49154f:	e8 14 fd 3f 00       	call   0x891268
  491554:	83 c4 04             	add    esp,0x4
  491557:	3b c3                	cmp    eax,ebx
  491559:	74 09                	je     0x491564
  49155b:	8b f0                	mov    esi,eax
  49155d:	e8 0e fe 25 00       	call   0x6f1370
  491562:	eb 02                	jmp    0x491566
  491564:	33 c0                	xor    eax,eax
  491566:	a3 0c a8 fb 00       	mov    ds:0xfba80c,eax
  49156b:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  49156e:	0f 84 46 01 00 00    	je     0x4916ba
  491574:	80 b8 9b 01 00 00 01 	cmp    BYTE PTR [eax+0x19b],0x1
  49157b:	0f 85 39 01 00 00    	jne    0x4916ba
  491581:	0f b6 88 7d 01 00 00 	movzx  ecx,BYTE PTR [eax+0x17d]
  491588:	3b cb                	cmp    ecx,ebx
  49158a:	74 77                	je     0x491603
  49158c:	0f b6 90 98 01 00 00 	movzx  edx,BYTE PTR [eax+0x198]
  491593:	3b d3                	cmp    edx,ebx
  491595:	74 27                	je     0x4915be
  491597:	8b 07                	mov    eax,DWORD PTR [edi]
  491599:	8b 48 0c             	mov    ecx,DWORD PTR [eax+0xc]
  49159c:	57                   	push   edi
  49159d:	ff d1                	call   ecx
  49159f:	8b 17                	mov    edx,DWORD PTR [edi]
  4915a1:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  4915a4:	57                   	push   edi
  4915a5:	ff d0                	call   eax
  4915a7:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4915a9:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  4915ac:	57                   	push   edi
  4915ad:	ff d2                	call   edx
  4915af:	8b 07                	mov    eax,DWORD PTR [edi]
  4915b1:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4915b4:	57                   	push   edi
  4915b5:	ff d1                	call   ecx
  4915b7:	33 c0                	xor    eax,eax
  4915b9:	e9 37 0a 00 00       	jmp    0x491ff5
  4915be:	3b cb                	cmp    ecx,ebx
  4915c0:	74 41                	je     0x491603
  4915c2:	e8 f9 27 fb ff       	call   0x443dc0
  4915c7:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  4915ca:	74 32                	je     0x4915fe
  4915cc:	0f b6 80 8a 01 00 00 	movzx  eax,BYTE PTR [eax+0x18a]
  4915d3:	3b c3                	cmp    eax,ebx
  4915d5:	74 27                	je     0x4915fe
  4915d7:	e8 64 31 fa ff       	call   0x434740
  4915dc:	8b 80 9c 00 00 00    	mov    eax,DWORD PTR [eax+0x9c]
  4915e2:	50                   	push   eax
  4915e3:	e8 d8 1b 32 00       	call   0x7b31c0
  4915e8:	e8 53 31 fa ff       	call   0x434740
  4915ed:	8b 80 9c 00 00 00    	mov    eax,DWORD PTR [eax+0x9c]
  4915f3:	50                   	push   eax
  4915f4:	e8 97 1b 32 00       	call   0x7b3190
  4915f9:	e9 b7 00 00 00       	jmp    0x4916b5
  4915fe:	a1 0c a8 fb 00       	mov    eax,ds:0xfba80c
  491603:	3b c3                	cmp    eax,ebx
  491605:	75 21                	jne    0x491628
  491607:	68 7c 05 00 00       	push   0x57c
  49160c:	e8 57 fc 3f 00       	call   0x891268
  491611:	83 c4 04             	add    esp,0x4
  491614:	3b c3                	cmp    eax,ebx
  491616:	74 09                	je     0x491621
  491618:	8b f0                	mov    esi,eax
  49161a:	e8 51 fd 25 00       	call   0x6f1370
  49161f:	eb 02                	jmp    0x491623
  491621:	33 c0                	xor    eax,eax
  491623:	a3 0c a8 fb 00       	mov    ds:0xfba80c,eax
  491628:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  49162b:	0f 84 89 00 00 00    	je     0x4916ba
  491631:	0f b6 88 7d 01 00 00 	movzx  ecx,BYTE PTR [eax+0x17d]
  491638:	3b cb                	cmp    ecx,ebx
  49163a:	74 7e                	je     0x4916ba
  49163c:	e8 7f 27 fb ff       	call   0x443dc0
  491641:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  491644:	74 0b                	je     0x491651
  491646:	0f b6 80 98 01 00 00 	movzx  eax,BYTE PTR [eax+0x198]
  49164d:	3b c3                	cmp    eax,ebx
  49164f:	75 64                	jne    0x4916b5
  491651:	e8 6a 27 fb ff       	call   0x443dc0
  491656:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  491659:	74 0b                	je     0x491666
  49165b:	0f b6 80 8a 01 00 00 	movzx  eax,BYTE PTR [eax+0x18a]
  491662:	3b c3                	cmp    eax,ebx
  491664:	75 4f                	jne    0x4916b5
  491666:	8b 35 a4 a7 fb 00    	mov    esi,DWORD PTR ds:0xfba7a4
  49166c:	3b f3                	cmp    esi,ebx
  49166e:	74 45                	je     0x4916b5
  491670:	8b 16                	mov    edx,DWORD PTR [esi]
  491672:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  491675:	8b ce                	mov    ecx,esi
  491677:	ff d0                	call   eax
  491679:	85 c0                	test   eax,eax
  49167b:	74 38                	je     0x4916b5
  49167d:	8b 16                	mov    edx,DWORD PTR [esi]
  49167f:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  491682:	8b ce                	mov    ecx,esi
  491684:	ff d0                	call   eax
  491686:	8b b8 9c 00 00 00    	mov    edi,DWORD PTR [eax+0x9c]
  49168c:	e8 cf d9 f7 ff       	call   0x40f060
  491691:	8b f0                	mov    esi,eax
  491693:	8b c7                	mov    eax,edi
  491695:	e8 36 e4 04 00       	call   0x4dfad0
  49169a:	3b c3                	cmp    eax,ebx
  49169c:	74 17                	je     0x4916b5
  49169e:	80 78 20 02          	cmp    BYTE PTR [eax+0x20],0x2
  4916a2:	72 11                	jb     0x4916b5
  4916a4:	e8 e7 84 ff ff       	call   0x489b90
  4916a9:	ff 40 08             	inc    DWORD PTR [eax+0x8]
  4916ac:	83 78 08 03          	cmp    DWORD PTR [eax+0x8],0x3
  4916b0:	7e 03                	jle    0x4916b5
  4916b2:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  4916b5:	a1 0c a8 fb 00       	mov    eax,ds:0xfba80c
  4916ba:	3b c3                	cmp    eax,ebx
  4916bc:	75 21                	jne    0x4916df
  4916be:	68 7c 05 00 00       	push   0x57c
  4916c3:	e8 a0 fb 3f 00       	call   0x891268
  4916c8:	83 c4 04             	add    esp,0x4
  4916cb:	3b c3                	cmp    eax,ebx
  4916cd:	74 09                	je     0x4916d8
  4916cf:	8b f0                	mov    esi,eax
  4916d1:	e8 9a fc 25 00       	call   0x6f1370
  4916d6:	eb 02                	jmp    0x4916da
  4916d8:	33 c0                	xor    eax,eax
  4916da:	a3 0c a8 fb 00       	mov    ds:0xfba80c,eax
  4916df:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  4916e2:	0f 84 20 01 00 00    	je     0x491808
  4916e8:	80 b8 9c 01 00 00 01 	cmp    BYTE PTR [eax+0x19c],0x1
  4916ef:	0f 85 13 01 00 00    	jne    0x491808
  4916f5:	8b 35 a4 a7 fb 00    	mov    esi,DWORD PTR ds:0xfba7a4
  4916fb:	3b f3                	cmp    esi,ebx
  4916fd:	0f 84 05 01 00 00    	je     0x491808
  491703:	8b 16                	mov    edx,DWORD PTR [esi]
  491705:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  491708:	8b ce                	mov    ecx,esi
  49170a:	ff d0                	call   eax
  49170c:	85 c0                	test   eax,eax
  49170e:	0f 84 f4 00 00 00    	je     0x491808
  491714:	8b 16                	mov    edx,DWORD PTR [esi]
  491716:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  491719:	8b ce                	mov    ecx,esi
  49171b:	ff d0                	call   eax
  49171d:	8b b8 9c 00 00 00    	mov    edi,DWORD PTR [eax+0x9c]
  491723:	e8 38 d9 f7 ff       	call   0x40f060
  491728:	8b f0                	mov    esi,eax
  49172a:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  49172e:	51                   	push   ecx
  49172f:	8d 4e 18             	lea    ecx,[esi+0x18]
  491732:	8d 44 24 18          	lea    eax,[esp+0x18]
  491736:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  49173a:	e8 81 21 3b 00       	call   0x8438c0
  49173f:	8b 76 1c             	mov    esi,DWORD PTR [esi+0x1c]
  491742:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  491746:	3b c6                	cmp    eax,esi
  491748:	0f 84 ba 00 00 00    	je     0x491808
  49174e:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  491751:	3b c3                	cmp    eax,ebx
  491753:	0f 84 af 00 00 00    	je     0x491808
  491759:	80 78 20 05          	cmp    BYTE PTR [eax+0x20],0x5
  49175d:	0f 82 a5 00 00 00    	jb     0x491808
  491763:	e8 38 34 f7 ff       	call   0x404ba0
  491768:	8b 80 4c 5f 00 00    	mov    eax,DWORD PTR [eax+0x5f4c]
  49176e:	83 c0 fe             	add    eax,0xfffffffe
  491771:	83 f8 16             	cmp    eax,0x16
  491774:	77 76                	ja     0x4917ec
  491776:	0f b6 90 24 20 49 00 	movzx  edx,BYTE PTR [eax+0x492024]
  49177d:	ff 24 95 1c 20 49 00 	jmp    DWORD PTR [edx*4+0x49201c]
  491784:	a1 08 f7 fd 00       	mov    eax,ds:0xfdf708
  491789:	2b c3                	sub    eax,ebx
  49178b:	74 42                	je     0x4917cf
  49178d:	be 01 00 00 00       	mov    esi,0x1
  491792:	2b c6                	sub    eax,esi
  491794:	74 22                	je     0x4917b8
  491796:	2b c6                	sub    eax,esi
  491798:	75 6e                	jne    0x491808
  49179a:	e8 a1 87 ff ff       	call   0x489f40
  49179f:	89 b0 4c 4d 00 00    	mov    DWORD PTR [eax+0x4d4c],esi
  4917a5:	e8 36 88 ff ff       	call   0x489fe0
  4917aa:	89 b0 bc 00 00 00    	mov    DWORD PTR [eax+0xbc],esi
  4917b0:	89 35 30 a8 fb 00    	mov    DWORD PTR ds:0xfba830,esi
  4917b6:	eb 4a                	jmp    0x491802
  4917b8:	e8 83 87 ff ff       	call   0x489f40
  4917bd:	89 98 4c 4d 00 00    	mov    DWORD PTR [eax+0x4d4c],ebx
  4917c3:	c7 05 08 f7 fd 00 02 	mov    DWORD PTR ds:0xfdf708,0x2
  4917ca:	00 00 00 
  4917cd:	eb 39                	jmp    0x491808
  4917cf:	89 1d 30 a8 fb 00    	mov    DWORD PTR ds:0xfba830,ebx
  4917d5:	e8 06 88 ff ff       	call   0x489fe0
  4917da:	89 98 bc 00 00 00    	mov    DWORD PTR [eax+0xbc],ebx
  4917e0:	c7 05 08 f7 fd 00 01 	mov    DWORD PTR ds:0xfdf708,0x1
  4917e7:	00 00 00 
  4917ea:	eb 1c                	jmp    0x491808
  4917ec:	e8 4f 87 ff ff       	call   0x489f40
  4917f1:	b9 01 00 00 00       	mov    ecx,0x1
  4917f6:	89 88 4c 4d 00 00    	mov    DWORD PTR [eax+0x4d4c],ecx
  4917fc:	89 0d 30 a8 fb 00    	mov    DWORD PTR ds:0xfba830,ecx
  491802:	89 1d 08 f7 fd 00    	mov    DWORD PTR ds:0xfdf708,ebx
  491808:	6a 2c                	push   0x2c
  49180a:	ff 15 78 24 bd 00    	call   DWORD PTR ds:0xbd2478
  491810:	84 c0                	test   al,al
  491812:	0f 84 13 01 00 00    	je     0x49192b
  491818:	8d 44 24 24          	lea    eax,[esp+0x24]
  49181c:	50                   	push   eax
  49181d:	ff 15 f8 20 bd 00    	call   DWORD PTR ds:0xbd20f8
  491823:	53                   	push   ebx
  491824:	68 7c 58 c0 00       	push   0xc0587c
  491829:	ff 15 50 22 bd 00    	call   DWORD PTR ds:0xbd2250
  49182f:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  491836:	75 2f                	jne    0x491867
  491838:	83 0d 28 88 fb 00 01 	or     DWORD PTR ds:0xfb8828,0x1
  49183f:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xa
  491846:	0a 00 00 00 
  49184a:	e8 01 e0 0b 00       	call   0x54f850
  49184f:	68 80 d5 bc 00       	push   0xbcd580
  491854:	e8 c1 0a 40 00       	call   0x89231a
  491859:	83 c4 04             	add    esp,0x4
  49185c:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491863:	ff ff ff ff 
  491867:	80 3d 25 92 fb 00 01 	cmp    BYTE PTR ds:0xfb9225,0x1
  49186e:	0f b7 4c 24 30       	movzx  ecx,WORD PTR [esp+0x30]
  491873:	0f b7 54 24 2e       	movzx  edx,WORD PTR [esp+0x2e]
  491878:	0f b7 44 24 2c       	movzx  eax,WORD PTR [esp+0x2c]
  49187d:	51                   	push   ecx
  49187e:	0f b7 4c 24 2e       	movzx  ecx,WORD PTR [esp+0x2e]
  491883:	52                   	push   edx
  491884:	0f b7 54 24 2e       	movzx  edx,WORD PTR [esp+0x2e]
  491889:	50                   	push   eax
  49188a:	0f b7 44 24 30       	movzx  eax,WORD PTR [esp+0x30]
  49188f:	51                   	push   ecx
  491890:	52                   	push   edx
  491891:	50                   	push   eax
  491892:	75 47                	jne    0x4918db
  491894:	68 98 58 c0 00       	push   0xc05898
  491899:	8d 94 24 58 01 00 00 	lea    edx,[esp+0x158]
  4918a0:	e8 2b 76 00 00       	call   0x498ed0
  4918a5:	8b 4c 24 3c          	mov    ecx,DWORD PTR [esp+0x3c]
  4918a9:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  4918ac:	83 c4 1c             	add    esp,0x1c
  4918af:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  4918b3:	51                   	push   ecx
  4918b4:	53                   	push   ebx
  4918b5:	53                   	push   ebx
  4918b6:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4918ba:	8b 10                	mov    edx,DWORD PTR [eax]
  4918bc:	8b 52 48             	mov    edx,DWORD PTR [edx+0x48]
  4918bf:	53                   	push   ebx
  4918c0:	50                   	push   eax
  4918c1:	ff d2                	call   edx
  4918c3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4918c7:	53                   	push   ebx
  4918c8:	53                   	push   ebx
  4918c9:	50                   	push   eax
  4918ca:	53                   	push   ebx
  4918cb:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  4918d2:	51                   	push   ecx
  4918d3:	ff 15 f4 25 bd 00    	call   DWORD PTR ds:0xbd25f4
  4918d9:	eb 40                	jmp    0x49191b
  4918db:	68 dc 58 c0 00       	push   0xc058dc
  4918e0:	8d 54 24 50          	lea    edx,[esp+0x50]
  4918e4:	e8 a7 04 f7 ff       	call   0x401d90
  4918e9:	8b 74 24 3c          	mov    esi,DWORD PTR [esp+0x3c]
  4918ed:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4918f0:	83 c4 1c             	add    esp,0x1c
  4918f3:	8d 54 24 14          	lea    edx,[esp+0x14]
  4918f7:	52                   	push   edx
  4918f8:	53                   	push   ebx
  4918f9:	53                   	push   ebx
  4918fa:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4918fe:	8b 08                	mov    ecx,DWORD PTR [eax]
  491900:	53                   	push   ebx
  491901:	50                   	push   eax
  491902:	8b 41 48             	mov    eax,DWORD PTR [ecx+0x48]
  491905:	ff d0                	call   eax
  491907:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  49190b:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  49190f:	51                   	push   ecx
  491910:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  491913:	e8 28 5f 24 00       	call   0x6d7840
  491918:	83 c4 04             	add    esp,0x4
  49191b:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  49191f:	3b c3                	cmp    eax,ebx
  491921:	74 08                	je     0x49192b
  491923:	8b 10                	mov    edx,DWORD PTR [eax]
  491925:	50                   	push   eax
  491926:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  491929:	ff d0                	call   eax
  49192b:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  491932:	75 3a                	jne    0x49196e
  491934:	83 0d d0 ac fb 00 01 	or     DWORD PTR ds:0xfbacd0,0x1
  49193b:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xb
  491942:	0b 00 00 00 
  491946:	89 1d d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,ebx
  49194c:	e8 af 49 24 00       	call   0x6d6300
  491951:	68 70 d6 bc 00       	push   0xbcd670
  491956:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  49195b:	e8 ba 09 40 00       	call   0x89231a
  491960:	83 c4 04             	add    esp,0x4
  491963:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  49196a:	ff ff ff ff 
  49196e:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491974:	3b cb                	cmp    ecx,ebx
  491976:	74 07                	je     0x49197f
  491978:	8b 11                	mov    edx,DWORD PTR [ecx]
  49197a:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  49197d:	ff d0                	call   eax
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  491996:	75 2f                	jne    0x4919c7
  491998:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  49199f:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xc
  4919a6:	0c 00 00 00 
  4919aa:	e8 41 26 37 00       	call   0x803ff0
  4919af:	68 90 dc bc 00       	push   0xbcdc90
  4919b4:	e8 61 09 40 00       	call   0x89231a
  4919b9:	83 c4 04             	add    esp,0x4
  4919bc:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  4919c3:	ff ff ff ff 
  4919c7:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  4919ce:	0f b6 05 fa 11 fc 00 	movzx  eax,BYTE PTR ds:0xfc11fa
  4919d5:	8d 0c 40             	lea    ecx,[eax+eax*2]
  4919d8:	8b 34 cd 40 11 fc 00 	mov    esi,DWORD PTR [ecx*8+0xfc1140]
  4919df:	75 2f                	jne    0x491a10
  4919e1:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  4919e8:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xd
  4919ef:	0d 00 00 00 
  4919f3:	e8 f8 25 37 00       	call   0x803ff0
  4919f8:	68 90 dc bc 00       	push   0xbcdc90
  4919fd:	e8 18 09 40 00       	call   0x89231a
  491a02:	83 c4 04             	add    esp,0x4
  491a05:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491a0c:	ff ff ff ff 
  491a10:	33 c0                	xor    eax,eax
  491a12:	38 05 fa 11 fc 00    	cmp    BYTE PTR ds:0xfc11fa,al
  491a18:	0f 94 c0             	sete   al
  491a1b:	8d 14 40             	lea    edx,[eax+eax*2]
  491a1e:	8b 04 d5 40 11 fc 00 	mov    eax,DWORD PTR [edx*8+0xfc1140]
  491a25:	03 c6                	add    eax,esi
  491a27:	83 bf 20 c0 00 00 00 	cmp    DWORD PTR [edi+0xc020],0x0
  491a2e:	8d b7 20 c0 00 00    	lea    esi,[edi+0xc020]
  491a34:	74 03                	je     0x491a39
  491a36:	01 46 48             	add    DWORD PTR [esi+0x48],eax
  491a39:	e8 b2 94 24 00       	call   0x6daef0
  491a3e:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  491a45:	75 2f                	jne    0x491a76
  491a47:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  491a4e:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xe
  491a55:	0e 00 00 00 
  491a59:	e8 32 fb 04 00       	call   0x4e1590
  491a5e:	68 80 cc bc 00       	push   0xbccc80
  491a63:	e8 b2 08 40 00       	call   0x89231a
  491a68:	83 c4 04             	add    esp,0x4
  491a6b:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491a72:	ff ff ff ff 
  491a76:	83 3d 34 39 f9 00 05 	cmp    DWORD PTR ds:0xf93934,0x5
  491a7d:	0f 8c b7 01 00 00    	jl     0x491c3a
  491a83:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  491a8a:	75 2f                	jne    0x491abb
  491a8c:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  491a93:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xf
  491a9a:	0f 00 00 00 
  491a9e:	e8 ed fa 04 00       	call   0x4e1590
  491aa3:	68 80 cc bc 00       	push   0xbccc80
  491aa8:	e8 6d 08 40 00       	call   0x89231a
  491aad:	83 c4 04             	add    esp,0x4
  491ab0:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491ab7:	ff ff ff ff 
  491abb:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491ac1:	c7 05 38 39 f9 00 01 	mov    DWORD PTR ds:0xf93938,0x1
  491ac8:	00 00 00 
  491acb:	8b 01                	mov    eax,DWORD PTR [ecx]
  491acd:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491ad0:	6a 01                	push   0x1
  491ad2:	6a 00                	push   0x0
  491ad4:	ff d2                	call   edx
  491ad6:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491adc:	8b 01                	mov    eax,DWORD PTR [ecx]
  491ade:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491ae1:	6a 01                	push   0x1
  491ae3:	6a 01                	push   0x1
  491ae5:	ff d2                	call   edx
  491ae7:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491aed:	8b 01                	mov    eax,DWORD PTR [ecx]
  491aef:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  491af2:	6a 01                	push   0x1
  491af4:	6a 02                	push   0x2
  491af6:	ff d2                	call   edx
  491af8:	8b f7                	mov    esi,edi
  491afa:	e8 a1 d2 24 00       	call   0x6deda0
  491aff:	68 00 59 c0 00       	push   0xc05900
  491b04:	e8 f7 c1 25 00       	call   0x6edd00
  491b09:	83 c4 04             	add    esp,0x4
  491b0c:	e8 bf 88 25 00       	call   0x6ea3d0
  491b11:	f6 05 2c 5b fe 00 01 	test   BYTE PTR ds:0xfe5b2c,0x1
  491b18:	8a d8                	mov    bl,al
  491b1a:	75 34                	jne    0x491b50
  491b1c:	83 0d 2c 5b fe 00 01 	or     DWORD PTR ds:0xfe5b2c,0x1
  491b23:	68 0c 5b fe 00       	push   0xfe5b0c
  491b28:	c7 84 24 5c 03 00 00 	mov    DWORD PTR [esp+0x35c],0x10
  491b2f:	10 00 00 00 
  491b33:	e8 08 31 0f 00       	call   0x584c40
  491b38:	68 70 f3 bc 00       	push   0xbcf370
  491b3d:	e8 d8 07 40 00       	call   0x89231a
  491b42:	83 c4 04             	add    esp,0x4
  491b45:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491b4c:	ff ff ff ff 
  491b50:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  491b54:	50                   	push   eax
  491b55:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  491b59:	b9 0c 5b fe 00       	mov    ecx,0xfe5b0c
  491b5e:	c7 44 24 20 99 01 00 	mov    DWORD PTR [esp+0x20],0x199
  491b65:	00 
  491b66:	e8 85 25 0e 00       	call   0x5740f0
  491b6b:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  491b6f:	3b 05 10 5b fe 00    	cmp    eax,DWORD PTR ds:0xfe5b10
  491b75:	74 10                	je     0x491b87
  491b77:	83 78 24 08          	cmp    DWORD PTR [eax+0x24],0x8
  491b7b:	72 05                	jb     0x491b82
  491b7d:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  491b80:	eb 0b                	jmp    0x491b8d
  491b82:	8d 70 10             	lea    esi,[eax+0x10]
  491b85:	eb 06                	jmp    0x491b8d
  491b87:	cc                   	int3
  491b88:	be fc d1 be 00       	mov    esi,0xbed1fc
  491b8d:	f6 05 2c 5b fe 00 01 	test   BYTE PTR ds:0xfe5b2c,0x1
  491b94:	75 34                	jne    0x491bca
  491b96:	83 0d 2c 5b fe 00 01 	or     DWORD PTR ds:0xfe5b2c,0x1
  491b9d:	68 0c 5b fe 00       	push   0xfe5b0c
  491ba2:	c7 84 24 5c 03 00 00 	mov    DWORD PTR [esp+0x35c],0x11
  491ba9:	11 00 00 00 
  491bad:	e8 8e 30 0f 00       	call   0x584c40
  491bb2:	68 70 f3 bc 00       	push   0xbcf370
  491bb7:	e8 5e 07 40 00       	call   0x89231a
  491bbc:	83 c4 04             	add    esp,0x4
  491bbf:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491bc6:	ff ff ff ff 
  491bca:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  491bce:	51                   	push   ecx
  491bcf:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  491bd3:	b9 0c 5b fe 00       	mov    ecx,0xfe5b0c
  491bd8:	c7 44 24 20 8d 01 00 	mov    DWORD PTR [esp+0x20],0x18d
  491bdf:	00 
  491be0:	e8 0b 25 0e 00       	call   0x5740f0
  491be5:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  491be9:	3b 05 10 5b fe 00    	cmp    eax,DWORD PTR ds:0xfe5b10
  491bef:	74 0d                	je     0x491bfe
  491bf1:	83 c0 10             	add    eax,0x10
  491bf4:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  491bf8:	72 0a                	jb     0x491c04
  491bfa:	8b 00                	mov    eax,DWORD PTR [eax]
  491bfc:	eb 06                	jmp    0x491c04
  491bfe:	cc                   	int3
  491bff:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  491c04:	33 d2                	xor    edx,edx
  491c06:	84 db                	test   bl,bl
  491c08:	0f 95 c2             	setne  dl
  491c0b:	4a                   	dec    edx
  491c0c:	81 e2 00 00 04 00    	and    edx,0x40000
  491c12:	52                   	push   edx
  491c13:	56                   	push   esi
  491c14:	50                   	push   eax
  491c15:	e8 46 e1 24 00       	call   0x6dfd60
  491c1a:	50                   	push   eax
  491c1b:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  491c21:	6a 01                	push   0x1
  491c23:	6a 00                	push   0x0
  491c25:	6a 10                	push   0x10
  491c27:	e8 34 e1 24 00       	call   0x6dfd60
  491c2c:	50                   	push   eax
  491c2d:	ff 15 4c 24 bd 00    	call   DWORD PTR ds:0xbd244c
  491c33:	33 c0                	xor    eax,eax
  491c35:	e9 bb 03 00 00       	jmp    0x491ff5
  491c3a:	8b 87 68 bf 00 00    	mov    eax,DWORD PTR [edi+0xbf68]
  491c40:	33 f6                	xor    esi,esi
  491c42:	83 f8 ff             	cmp    eax,0xffffffff
  491c45:	74 60                	je     0x491ca7
  491c47:	39 35 ac a7 fb 00    	cmp    DWORD PTR ds:0xfba7ac,esi
  491c4d:	74 58                	je     0x491ca7
  491c4f:	83 f8 21             	cmp    eax,0x21
  491c52:	7f 4a                	jg     0x491c9e
  491c54:	b8 10 00 00 00       	mov    eax,0x10
  491c59:	c7 87 68 bf 00 00 a0 	mov    DWORD PTR [edi+0xbf68],0xfa0
  491c60:	0f 00 00 
  491c63:	66 89 44 24 14       	mov    WORD PTR [esp+0x14],ax
  491c68:	39 35 98 a7 fb 00    	cmp    DWORD PTR ds:0xfba798,esi
  491c6e:	75 15                	jne    0x491c85
  491c70:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  491c76:	8b 11                	mov    edx,DWORD PTR [ecx]
  491c78:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  491c7b:	6a 02                	push   0x2
  491c7d:	8d 44 24 18          	lea    eax,[esp+0x18]
  491c81:	50                   	push   eax
  491c82:	56                   	push   esi
  491c83:	ff d2                	call   edx
  491c85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  491c8b:	89 87 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],eax
  491c91:	e8 0a 2f f7 ff       	call   0x404ba0
  491c96:	ff 80 54 5f 00 00    	inc    DWORD PTR [eax+0x5f54]
  491c9c:	eb 09                	jmp    0x491ca7
  491c9e:	83 c0 df             	add    eax,0xffffffdf
  491ca1:	89 87 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],eax
  491ca7:	39 b7 cc bf 00 00    	cmp    DWORD PTR [edi+0xbfcc],esi
  491cad:	75 54                	jne    0x491d03
  491caf:	e8 ac d3 f7 ff       	call   0x40f060
  491cb4:	8b c8                	mov    ecx,eax
  491cb6:	e8 a5 e3 04 00       	call   0x4e0060
  491cbb:	e8 a0 7f ff ff       	call   0x489c60
  491cc0:	50                   	push   eax
  491cc1:	e8 6a 78 ff ff       	call   0x489530
  491cc6:	e8 65 24 fa ff       	call   0x434130
  491ccb:	8b 08                	mov    ecx,DWORD PTR [eax]
  491ccd:	3b ce                	cmp    ecx,esi
  491ccf:	74 07                	je     0x491cd8
  491cd1:	8b 01                	mov    eax,DWORD PTR [ecx]
  491cd3:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  491cd6:	ff d2                	call   edx
  491cd8:	e8 d3 7f ff ff       	call   0x489cb0
  491cdd:	8b 88 ac 5e 00 00    	mov    ecx,DWORD PTR [eax+0x5eac]
  491ce3:	3b ce                	cmp    ecx,esi
  491ce5:	74 0d                	je     0x491cf4
  491ce7:	8b 01                	mov    eax,DWORD PTR [ecx]
  491ce9:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  491cec:	ff d2                	call   edx
  491cee:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  491cf2:	eb 04                	jmp    0x491cf8
  491cf4:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  491cf8:	e8 43 94 00 00       	call   0x49b140
  491cfd:	50                   	push   eax
  491cfe:	e8 bd f1 0b 00       	call   0x550ec0
  491d03:	f6 05 d8 94 fd 00 01 	test   BYTE PTR ds:0xfd94d8,0x1
  491d0a:	75 2f                	jne    0x491d3b
  491d0c:	83 0d d8 94 fd 00 01 	or     DWORD PTR ds:0xfd94d8,0x1
  491d13:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x12
  491d1a:	12 00 00 00 
  491d1e:	e8 0d 37 32 00       	call   0x7b5430
  491d23:	68 60 e6 bc 00       	push   0xbce660
  491d28:	e8 ed 05 40 00       	call   0x89231a
  491d2d:	83 c4 04             	add    esp,0x4
  491d30:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491d37:	ff ff ff ff 
  491d3b:	68 20 94 fd 00       	push   0xfd9420
  491d40:	e8 eb 45 32 00       	call   0x7b6330
  491d45:	f6 05 08 94 fd 00 01 	test   BYTE PTR ds:0xfd9408,0x1
  491d4c:	0f 57 c0             	xorps  xmm0,xmm0
  491d4f:	bf 01 00 00 00       	mov    edi,0x1
  491d54:	75 22                	jne    0x491d78
  491d56:	09 3d 08 94 fd 00    	or     DWORD PTR ds:0xfd9408,edi
  491d5c:	89 35 0c 94 fd 00    	mov    DWORD PTR ds:0xfd940c,esi
  491d62:	89 35 10 94 fd 00    	mov    DWORD PTR ds:0xfd9410,esi
  491d68:	89 35 14 94 fd 00    	mov    DWORD PTR ds:0xfd9414,esi
  491d6e:	f3 0f 11 05 18 94 fd 	movss  DWORD PTR ds:0xfd9418,xmm0
  491d75:	00 
  491d76:	eb 0e                	jmp    0x491d86
  491d78:	39 35 0c 94 fd 00    	cmp    DWORD PTR ds:0xfd940c,esi
  491d7e:	7e 06                	jle    0x491d86
  491d80:	ff 0d 0c 94 fd 00    	dec    DWORD PTR ds:0xfd940c
  491d86:	d9 05 18 94 fd 00    	fld    DWORD PTR ds:0xfd9418
  491d8c:	dc 05 10 58 c5 00    	fadd   QWORD PTR ds:0xc55810
  491d92:	d9 1d 18 94 fd 00    	fstp   DWORD PTR ds:0xfd9418
  491d98:	d9 05 08 58 c5 00    	fld    DWORD PTR ds:0xc55808
  491d9e:	d9 05 18 94 fd 00    	fld    DWORD PTR ds:0xfd9418
  491da4:	df f1                	fcomip st,st(1)
  491da6:	dd d8                	fstp   st(0)
  491da8:	72 08                	jb     0x491db2
  491daa:	f3 0f 11 05 18 94 fd 	movss  DWORD PTR ds:0xfd9418,xmm0
  491db1:	00 
  491db2:	f6 05 80 1c fc 00 01 	test   BYTE PTR ds:0xfc1c80,0x1
  491db9:	75 2f                	jne    0x491dea
  491dbb:	09 3d 80 1c fc 00    	or     DWORD PTR ds:0xfc1c80,edi
  491dc1:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x13
  491dc8:	13 00 00 00 
  491dcc:	e8 bf 98 0d 00       	call   0x56b690
  491dd1:	68 00 e5 bc 00       	push   0xbce500
  491dd6:	e8 3f 05 40 00       	call   0x89231a
  491ddb:	83 c4 04             	add    esp,0x4
  491dde:	83 ce ff             	or     esi,0xffffffff
  491de1:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  491de8:	eb 03                	jmp    0x491ded
  491dea:	83 ce ff             	or     esi,0xffffffff
  491ded:	68 84 1c fc 00       	push   0xfc1c84
  491df2:	e8 99 9b 0d 00       	call   0x56b990
  491df7:	f6 05 c0 1a fc 00 01 	test   BYTE PTR ds:0xfc1ac0,0x1
  491dfe:	75 2a                	jne    0x491e2a
  491e00:	09 3d c0 1a fc 00    	or     DWORD PTR ds:0xfc1ac0,edi
  491e06:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x14
  491e0d:	14 00 00 00 
  491e11:	e8 ea 62 0c 00       	call   0x558100
  491e16:	68 a0 de bc 00       	push   0xbcdea0
  491e1b:	e8 fa 04 40 00       	call   0x89231a
  491e20:	83 c4 04             	add    esp,0x4
  491e23:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  491e2a:	68 c4 1a fc 00       	push   0xfc1ac4
  491e2f:	e8 9c 64 0c 00       	call   0x5582d0
  491e34:	f6 05 4c 74 fb 00 01 	test   BYTE PTR ds:0xfb744c,0x1
  491e3b:	75 2a                	jne    0x491e67
  491e3d:	09 3d 4c 74 fb 00    	or     DWORD PTR ds:0xfb744c,edi
  491e43:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x15
  491e4a:	15 00 00 00 
  491e4e:	e8 0d ce 05 00       	call   0x4eec60
  491e53:	68 40 d1 bc 00       	push   0xbcd140
  491e58:	e8 bd 04 40 00       	call   0x89231a
  491e5d:	83 c4 04             	add    esp,0x4
  491e60:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  491e67:	bf 50 74 fb 00       	mov    edi,0xfb7450
  491e6c:	e8 ef cc 05 00       	call   0x4eeb60
  491e71:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  491e75:	83 b8 cc bf 00 00 00 	cmp    DWORD PTR [eax+0xbfcc],0x0
  491e7c:	0f 85 c1 00 00 00    	jne    0x491f43
  491e82:	e8 49 83 ff ff       	call   0x48a1d0
  491e87:	50                   	push   eax
  491e88:	e8 f3 90 0c 00       	call   0x55af80
  491e8d:	e8 1e 81 ff ff       	call   0x489fb0
  491e92:	50                   	push   eax
  491e93:	e8 78 b0 0d 00       	call   0x56cf10
  491e98:	e8 03 e1 fa ff       	call   0x43ffa0
  491e9d:	8b f8                	mov    edi,eax
  491e9f:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  491ea2:	be 01 00 00 00       	mov    esi,0x1
  491ea7:	01 77 40             	add    DWORD PTR [edi+0x40],esi
  491eaa:	8b 11                	mov    edx,DWORD PTR [ecx]
  491eac:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  491eaf:	ff d0                	call   eax
  491eb1:	8b 47 3c             	mov    eax,DWORD PTR [edi+0x3c]
  491eb4:	85 c0                	test   eax,eax
  491eb6:	7e 04                	jle    0x491ebc
  491eb8:	48                   	dec    eax
  491eb9:	89 47 3c             	mov    DWORD PTR [edi+0x3c],eax
  491ebc:	83 7f 3c 00          	cmp    DWORD PTR [edi+0x3c],0x0
  491ec0:	75 0e                	jne    0x491ed0
  491ec2:	8b 4f 50             	mov    ecx,DWORD PTR [edi+0x50]
  491ec5:	89 4f 3c             	mov    DWORD PTR [edi+0x3c],ecx
  491ec8:	8b 4f 4c             	mov    ecx,DWORD PTR [edi+0x4c]
  491ecb:	e8 60 36 2a 00       	call   0x735530
  491ed0:	e8 6b 10 f9 ff       	call   0x422f40
  491ed5:	8b c8                	mov    ecx,eax
  491ed7:	e8 44 f6 0c 00       	call   0x561520
  491edc:	e8 cf 81 ff ff       	call   0x48a0b0
  491ee1:	e8 ea da 0c 00       	call   0x55f9d0
  491ee6:	e8 35 82 ff ff       	call   0x48a120
  491eeb:	8b c8                	mov    ecx,eax
  491eed:	e8 7e 00 0f 00       	call   0x581f70
  491ef2:	f6 05 0c 8f fd 00 01 	test   BYTE PTR ds:0xfd8f0c,0x1
  491ef9:	75 18                	jne    0x491f13
  491efb:	09 35 0c 8f fd 00    	or     DWORD PTR ds:0xfd8f0c,esi
  491f01:	e8 1a 72 0c 00       	call   0x559120
  491f06:	68 60 df bc 00       	push   0xbcdf60
  491f0b:	e8 0a 04 40 00       	call   0x89231a
  491f10:	83 c4 04             	add    esp,0x4
  491f13:	be 10 8f fd 00       	mov    esi,0xfd8f10
  491f18:	e8 73 74 0c 00       	call   0x559390
  491f1d:	e8 6e 82 ff ff       	call   0x48a190
  491f22:	e8 b9 22 0c 00       	call   0x5541e0
  491f27:	e8 a4 0f f9 ff       	call   0x422ed0
  491f2c:	50                   	push   eax
  491f2d:	e8 be 18 0c 00       	call   0x5537f0
  491f32:	e8 e9 27 f8 ff       	call   0x414720
  491f37:	8b f0                	mov    esi,eax
  491f39:	e8 92 f5 0d 00       	call   0x5714d0
  491f3e:	e8 fd 27 fa ff       	call   0x434740
  491f43:	f6 05 a4 72 fb 00 01 	test   BYTE PTR ds:0xfb72a4,0x1
  491f4a:	75 2f                	jne    0x491f7b
  491f4c:	83 0d a4 72 fb 00 01 	or     DWORD PTR ds:0xfb72a4,0x1
  491f53:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x16
  491f5a:	16 00 00 00 
  491f5e:	e8 ed d8 00 00       	call   0x49f850
  491f63:	68 e0 cf bc 00       	push   0xbccfe0
  491f68:	e8 ad 03 40 00       	call   0x89231a
  491f6d:	83 c4 04             	add    esp,0x4
  491f70:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491f77:	ff ff ff ff 
  491f7b:	68 a8 72 fb 00       	push   0xfb72a8
  491f80:	e8 cb da 00 00       	call   0x49fa50
  491f85:	f6 05 d4 b0 fa 00 01 	test   BYTE PTR ds:0xfab0d4,0x1
  491f8c:	75 2f                	jne    0x491fbd
  491f8e:	83 0d d4 b0 fa 00 01 	or     DWORD PTR ds:0xfab0d4,0x1
  491f95:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0x17
  491f9c:	17 00 00 00 
  491fa0:	e8 fb 83 37 00       	call   0x80a3a0
  491fa5:	68 d0 cd bc 00       	push   0xbccdd0
  491faa:	e8 6b 03 40 00       	call   0x89231a
  491faf:	83 c4 04             	add    esp,0x4
  491fb2:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491fb9:	ff ff ff ff 
  491fbd:	68 28 b0 fa 00       	push   0xfab028
  491fc2:	e8 49 94 37 00       	call   0x80b410
  491fc7:	e8 64 33 f9 ff       	call   0x425330
  491fcc:	8b f0                	mov    esi,eax
  491fce:	e8 ad 4b 06 00       	call   0x4f6b80
  491fd3:	80 bb 90 00 00 00 00 	cmp    BYTE PTR [ebx+0x90],0x0
  491fda:	75 08                	jne    0x491fe4
  491fdc:	53                   	push   ebx
  491fdd:	e8 5e 2a 37 00       	call   0x804a40
  491fe2:	eb 07                	jmp    0x491feb
  491fe4:	8b f3                	mov    esi,ebx
  491fe6:	e8 85 2c 37 00       	call   0x804c70
  491feb:	53                   	push   ebx
  491fec:	e8 cf 2f 37 00       	call   0x804fc0
  491ff1:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  491ff5:	8b 8c 24 50 03 00 00 	mov    ecx,DWORD PTR [esp+0x350]
  491ffc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  492003:	59                   	pop    ecx
  492004:	5f                   	pop    edi
  492005:	5e                   	pop    esi
  492006:	5b                   	pop    ebx
  492007:	8b 8c 24 38 03 00 00 	mov    ecx,DWORD PTR [esp+0x338]
  49200e:	33 cc                	xor    ecx,esp
  492010:	e8 ec ef 3f 00       	call   0x891001
  492015:	8b e5                	mov    esp,ebp
  492017:	5d                   	pop    ebp
  492018:	c2 04 00             	ret    0x4
  49201b:	90                   	nop

; game: receive/client_callback 0x4930e0..0x493161 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004930e0 <.data>:
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10 00             	ret    0x10

; game: receive/frontend_dispatch 0x48aad0..0x48ab68 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0048aad0 <.data>:
  48aad0:	55                   	push   ebp
  48aad1:	8b ec                	mov    ebp,esp
  48aad3:	83 ec 08             	sub    esp,0x8
  48aad6:	53                   	push   ebx
  48aad7:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  48aada:	0f bf c3             	movsx  eax,bx
  48aadd:	56                   	push   esi
  48aade:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  48aae1:	03 c0                	add    eax,eax
  48aae3:	57                   	push   edi
  48aae4:	8b f9                	mov    edi,ecx
  48aae6:	8b 4c c7 0c          	mov    ecx,DWORD PTR [edi+eax*8+0xc]
  48aaea:	8d 34 c7             	lea    esi,[edi+eax*8]
  48aaed:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  48aaf0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  48aaf3:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  48aaf6:	85 c0                	test   eax,eax
  48aaf8:	75 1b                	jne    0x48ab15
  48aafa:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  48aafd:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  48ab00:	8b 17                	mov    edx,DWORD PTR [edi]
  48ab02:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  48ab05:	53                   	push   ebx
  48ab06:	50                   	push   eax
  48ab07:	51                   	push   ecx
  48ab08:	8b cf                	mov    ecx,edi
  48ab0a:	ff d2                	call   edx
  48ab0c:	5f                   	pop    edi
  48ab0d:	5e                   	pop    esi
  48ab0e:	5b                   	pop    ebx
  48ab0f:	8b e5                	mov    esp,ebp
  48ab11:	5d                   	pop    ebp
  48ab12:	c2 0c 00             	ret    0xc
  48ab15:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  48ab18:	6a 06                	push   0x6
  48ab1a:	68 6c 6c bf 00       	push   0xbf6c6c
  48ab1f:	50                   	push   eax
  48ab20:	e8 99 7d 40 00       	call   0x8928be
  48ab25:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  48ab28:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  48ab2b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  48ab2e:	83 c4 0c             	add    esp,0xc
  48ab31:	53                   	push   ebx
  48ab32:	51                   	push   ecx
  48ab33:	52                   	push   edx
  48ab34:	8d 8c 38 00 fe ff ff 	lea    ecx,[eax+edi*1-0x200]
  48ab3b:	ff 55 f8             	call   DWORD PTR [ebp-0x8]
  48ab3e:	8b f8                	mov    edi,eax
  48ab40:	81 ff 05 40 00 80    	cmp    edi,0x80004005
  48ab46:	75 15                	jne    0x48ab5d
  48ab48:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  48ab4b:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  48ab4e:	51                   	push   ecx
  48ab4f:	52                   	push   edx
  48ab50:	68 74 6c bf 00       	push   0xbf6c74
  48ab55:	e8 06 30 26 00       	call   0x6edb60
  48ab5a:	83 c4 0c             	add    esp,0xc
  48ab5d:	8b c7                	mov    eax,edi
  48ab5f:	5f                   	pop    edi
  48ab60:	5e                   	pop    esi
  48ab61:	5b                   	pop    ebx
  48ab62:	8b e5                	mov    esp,ebp
  48ab64:	5d                   	pop    ebp
  48ab65:	c2 0c 00             	ret    0xc

; game: receive/loading_on 0x494860..0x494a82 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00494860 <.data>:
  494860:	55                   	push   ebp
  494861:	8b ec                	mov    ebp,esp
  494863:	6a ff                	push   0xffffffff
  494865:	68 4a 11 93 00       	push   0x93114a
  49486a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  494870:	50                   	push   eax
  494871:	53                   	push   ebx
  494872:	56                   	push   esi
  494873:	57                   	push   edi
  494874:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  494879:	33 c5                	xor    eax,ebp
  49487b:	50                   	push   eax
  49487c:	8d 45 f4             	lea    eax,[ebp-0xc]
  49487f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  494885:	8b f9                	mov    edi,ecx
  494887:	bb 01 00 00 00       	mov    ebx,0x1
  49488c:	89 9f d4 bf 00 00    	mov    DWORD PTR [edi+0xbfd4],ebx
  494892:	84 1d fc 18 fc 00    	test   BYTE PTR ds:0xfc18fc,bl
  494898:	75 26                	jne    0x4948c0
  49489a:	09 1d fc 18 fc 00    	or     DWORD PTR ds:0xfc18fc,ebx
  4948a0:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4948a7:	e8 44 00 0c 00       	call   0x5548f0
  4948ac:	68 d0 dc bc 00       	push   0xbcdcd0
  4948b1:	e8 64 da 3f 00       	call   0x89231a
  4948b6:	83 c4 04             	add    esp,0x4
  4948b9:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4948c0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4948c3:	0f bf 48 04          	movsx  ecx,WORD PTR [eax+0x4]
  4948c7:	0f bf 50 02          	movsx  edx,WORD PTR [eax+0x2]
  4948cb:	51                   	push   ecx
  4948cc:	52                   	push   edx
  4948cd:	68 00 19 fc 00       	push   0xfc1900
  4948d2:	e8 09 08 0c 00       	call   0x5550e0
  4948d7:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  4948dd:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  4948e0:	8b 48 38             	mov    ecx,DWORD PTR [eax+0x38]
  4948e3:	8d 77 08             	lea    esi,[edi+0x8]
  4948e6:	56                   	push   esi
  4948e7:	ff d1                	call   ecx
  4948e9:	8b 47 18             	mov    eax,DWORD PTR [edi+0x18]
  4948ec:	8b 10                	mov    edx,DWORD PTR [eax]
  4948ee:	6a 00                	push   0x0
  4948f0:	6a 00                	push   0x0
  4948f2:	6a 00                	push   0x0
  4948f4:	6a 00                	push   0x0
  4948f6:	50                   	push   eax
  4948f7:	8b 42 44             	mov    eax,DWORD PTR [edx+0x44]
  4948fa:	ff d0                	call   eax
  4948fc:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4948fe:	8b 51 38             	mov    edx,DWORD PTR [ecx+0x38]
  494901:	56                   	push   esi
  494902:	ff d2                	call   edx
  494904:	8b 7f 18             	mov    edi,DWORD PTR [edi+0x18]
  494907:	8b 07                	mov    eax,DWORD PTR [edi]
  494909:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  49490c:	6a 00                	push   0x0
  49490e:	6a 00                	push   0x0
  494910:	6a 00                	push   0x0
  494912:	6a 00                	push   0x0
  494914:	57                   	push   edi
  494915:	ff d1                	call   ecx
  494917:	84 1d f0 2c fd 00    	test   BYTE PTR ds:0xfd2cf0,bl
  49491d:	75 18                	jne    0x494937
  49491f:	09 1d f0 2c fd 00    	or     DWORD PTR ds:0xfd2cf0,ebx
  494925:	e8 66 37 2a 00       	call   0x738090
  49492a:	68 80 e6 bc 00       	push   0xbce680
  49492f:	e8 e6 d9 3f 00       	call   0x89231a
  494934:	83 c4 04             	add    esp,0x4
  494937:	8b 0d d0 2c fd 00    	mov    ecx,DWORD PTR ds:0xfd2cd0
  49493d:	85 c9                	test   ecx,ecx
  49493f:	74 2d                	je     0x49496e
  494941:	84 1d f0 2c fd 00    	test   BYTE PTR ds:0xfd2cf0,bl
  494947:	75 1e                	jne    0x494967
  494949:	09 1d f0 2c fd 00    	or     DWORD PTR ds:0xfd2cf0,ebx
  49494f:	e8 3c 37 2a 00       	call   0x738090
  494954:	68 80 e6 bc 00       	push   0xbce680
  494959:	e8 bc d9 3f 00       	call   0x89231a
  49495e:	8b 0d d0 2c fd 00    	mov    ecx,DWORD PTR ds:0xfd2cd0
  494964:	83 c4 04             	add    esp,0x4
  494967:	8b 11                	mov    edx,DWORD PTR [ecx]
  494969:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  49496c:	ff d0                	call   eax
  49496e:	e8 cd b2 24 00       	call   0x6dfc40
  494973:	8b f0                	mov    esi,eax
  494975:	e8 c6 b2 24 00       	call   0x6dfc40
  49497a:	8b 48 18             	mov    ecx,DWORD PTR [eax+0x18]
  49497d:	51                   	push   ecx
  49497e:	8b 4e 1c             	mov    ecx,DWORD PTR [esi+0x1c]
  494981:	e8 6a fe 29 00       	call   0x7347f0
  494986:	83 c4 04             	add    esp,0x4
  494989:	8b f0                	mov    esi,eax
  49498b:	84 1d f0 2c fd 00    	test   BYTE PTR ds:0xfd2cf0,bl
  494991:	75 18                	jne    0x4949ab
  494993:	09 1d f0 2c fd 00    	or     DWORD PTR ds:0xfd2cf0,ebx
  494999:	e8 f2 36 2a 00       	call   0x738090
  49499e:	68 80 e6 bc 00       	push   0xbce680
  4949a3:	e8 72 d9 3f 00       	call   0x89231a
  4949a8:	83 c4 04             	add    esp,0x4
  4949ab:	89 35 d0 2c fd 00    	mov    DWORD PTR ds:0xfd2cd0,esi
  4949b1:	85 f6                	test   esi,esi
  4949b3:	74 06                	je     0x4949bb
  4949b5:	89 1d d4 2c fd 00    	mov    DWORD PTR ds:0xfd2cd4,ebx
  4949bb:	8b 15 e0 2c fd 00    	mov    edx,DWORD PTR ds:0xfd2ce0
  4949c1:	a1 e4 2c fd 00       	mov    eax,ds:0xfd2ce4
  4949c6:	89 15 d8 2c fd 00    	mov    DWORD PTR ds:0xfd2cd8,edx
  4949cc:	a3 dc 2c fd 00       	mov    ds:0xfd2cdc,eax
  4949d1:	84 1d f0 2c fd 00    	test   BYTE PTR ds:0xfd2cf0,bl
  4949d7:	75 18                	jne    0x4949f1
  4949d9:	09 1d f0 2c fd 00    	or     DWORD PTR ds:0xfd2cf0,ebx
  4949df:	e8 ac 36 2a 00       	call   0x738090
  4949e4:	68 80 e6 bc 00       	push   0xbce680
  4949e9:	e8 2c d9 3f 00       	call   0x89231a
  4949ee:	83 c4 04             	add    esp,0x4
  4949f1:	89 1d ec 2c fd 00    	mov    DWORD PTR ds:0xfd2cec,ebx
  4949f7:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  4949fd:	84 1d c0 0f fc 00    	test   BYTE PTR ds:0xfc0fc0,bl
  494a03:	75 22                	jne    0x494a27
  494a05:	09 1d c0 0f fc 00    	or     DWORD PTR ds:0xfc0fc0,ebx
  494a0b:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  494a0e:	e8 3d 44 24 00       	call   0x6d8e50
  494a13:	68 b0 db bc 00       	push   0xbcdbb0
  494a18:	e8 fd d8 3f 00       	call   0x89231a
  494a1d:	83 c4 04             	add    esp,0x4
  494a20:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  494a27:	be c8 0f fc 00       	mov    esi,0xfc0fc8
  494a2c:	e8 4f 4c 24 00       	call   0x6d9680
  494a31:	84 1d c0 0f fc 00    	test   BYTE PTR ds:0xfc0fc0,bl
  494a37:	75 26                	jne    0x494a5f
  494a39:	09 1d c0 0f fc 00    	or     DWORD PTR ds:0xfc0fc0,ebx
  494a3f:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  494a46:	e8 05 44 24 00       	call   0x6d8e50
  494a4b:	68 b0 db bc 00       	push   0xbcdbb0
  494a50:	e8 c5 d8 3f 00       	call   0x89231a
  494a55:	83 c4 04             	add    esp,0x4
  494a58:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  494a5f:	b9 c8 0f fc 00       	mov    ecx,0xfc0fc8
  494a64:	e8 17 4d 24 00       	call   0x6d9780
  494a69:	b8 00 01 00 00       	mov    eax,0x100
  494a6e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  494a71:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  494a78:	59                   	pop    ecx
  494a79:	5f                   	pop    edi
  494a7a:	5e                   	pop    esi
  494a7b:	5b                   	pop    ebx
  494a7c:	8b e5                	mov    esp,ebp
  494a7e:	5d                   	pop    ebp
  494a7f:	c2 0c 00             	ret    0xc

; game: receive/loading_off 0x494a90..0x494c10 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00494a90 <.data>:
  494a90:	55                   	push   ebp
  494a91:	8b ec                	mov    ebp,esp
  494a93:	83 e4 f8             	and    esp,0xfffffff8
  494a96:	6a ff                	push   0xffffffff
  494a98:	68 f8 70 93 00       	push   0x9370f8
  494a9d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  494aa3:	50                   	push   eax
  494aa4:	83 ec 08             	sub    esp,0x8
  494aa7:	53                   	push   ebx
  494aa8:	56                   	push   esi
  494aa9:	57                   	push   edi
  494aaa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  494aaf:	33 c4                	xor    eax,esp
  494ab1:	50                   	push   eax
  494ab2:	8d 44 24 18          	lea    eax,[esp+0x18]
  494ab6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  494abc:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  494ac0:	f6 05 f0 2c fd 00 01 	test   BYTE PTR ds:0xfd2cf0,0x1
  494ac7:	be 01 00 00 00       	mov    esi,0x1
  494acc:	75 18                	jne    0x494ae6
  494ace:	09 35 f0 2c fd 00    	or     DWORD PTR ds:0xfd2cf0,esi
  494ad4:	e8 b7 35 2a 00       	call   0x738090
  494ad9:	68 80 e6 bc 00       	push   0xbce680
  494ade:	e8 37 d8 3f 00       	call   0x89231a
  494ae3:	83 c4 04             	add    esp,0x4
  494ae6:	33 db                	xor    ebx,ebx
  494ae8:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  494aef:	89 1d ec 2c fd 00    	mov    DWORD PTR ds:0xfd2cec,ebx
  494af5:	75 25                	jne    0x494b1c
  494af7:	09 35 e8 79 fb 00    	or     DWORD PTR ds:0xfb79e8,esi
  494afd:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  494b01:	e8 da 42 30 00       	call   0x798de0
  494b06:	68 e0 d2 bc 00       	push   0xbcd2e0
  494b0b:	e8 0a d8 3f 00       	call   0x89231a
  494b10:	83 c4 04             	add    esp,0x4
  494b13:	83 cf ff             	or     edi,0xffffffff
  494b16:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  494b1a:	eb 03                	jmp    0x494b1f
  494b1c:	83 cf ff             	or     edi,0xffffffff
  494b1f:	8b 0d e8 76 fb 00    	mov    ecx,DWORD PTR ds:0xfb76e8
  494b25:	3b cb                	cmp    ecx,ebx
  494b27:	74 71                	je     0x494b9a
  494b29:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  494b30:	75 26                	jne    0x494b58
  494b32:	09 35 e8 79 fb 00    	or     DWORD PTR ds:0xfb79e8,esi
  494b38:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  494b3c:	e8 9f 42 30 00       	call   0x798de0
  494b41:	68 e0 d2 bc 00       	push   0xbcd2e0
  494b46:	e8 cf d7 3f 00       	call   0x89231a
  494b4b:	89 7c 24 24          	mov    DWORD PTR [esp+0x24],edi
  494b4f:	8b 0d e8 76 fb 00    	mov    ecx,DWORD PTR ds:0xfb76e8
  494b55:	83 c4 04             	add    esp,0x4
  494b58:	8b 81 a4 00 00 00    	mov    eax,DWORD PTR [ecx+0xa4]
  494b5e:	8d b1 a4 00 00 00    	lea    esi,[ecx+0xa4]
  494b64:	8b 89 a0 00 00 00    	mov    ecx,DWORD PTR [ecx+0xa0]
  494b6a:	3b c8                	cmp    ecx,eax
  494b6c:	74 27                	je     0x494b95
  494b6e:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  494b72:	52                   	push   edx
  494b73:	51                   	push   ecx
  494b74:	50                   	push   eax
  494b75:	50                   	push   eax
  494b76:	e8 35 40 30 00       	call   0x798bb0
  494b7b:	8b 3e                	mov    edi,DWORD PTR [esi]
  494b7d:	8b d8                	mov    ebx,eax
  494b7f:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  494b83:	50                   	push   eax
  494b84:	8b c3                	mov    eax,ebx
  494b86:	e8 75 40 30 00       	call   0x798c00
  494b8b:	83 c4 14             	add    esp,0x14
  494b8e:	89 1e                	mov    DWORD PTR [esi],ebx
  494b90:	83 cf ff             	or     edi,0xffffffff
  494b93:	33 db                	xor    ebx,ebx
  494b95:	be 01 00 00 00       	mov    esi,0x1
  494b9a:	f6 05 fc 18 fc 00 01 	test   BYTE PTR ds:0xfc18fc,0x1
  494ba1:	75 24                	jne    0x494bc7
  494ba3:	09 35 fc 18 fc 00    	or     DWORD PTR ds:0xfc18fc,esi
  494ba9:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  494bb0:	00 
  494bb1:	e8 3a fd 0b 00       	call   0x5548f0
  494bb6:	68 d0 dc bc 00       	push   0xbcdcd0
  494bbb:	e8 5a d7 3f 00       	call   0x89231a
  494bc0:	83 c4 04             	add    esp,0x4
  494bc3:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  494bc7:	39 1d 84 19 fc 00    	cmp    DWORD PTR ds:0xfc1984,ebx
  494bcd:	74 0f                	je     0x494bde
  494bcf:	be 00 19 fc 00       	mov    esi,0xfc1900
  494bd4:	e8 e7 0c 0c 00       	call   0x5558c0
  494bd9:	be 01 00 00 00       	mov    esi,0x1
  494bde:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  494be2:	89 99 d4 bf 00 00    	mov    DWORD PTR [ecx+0xbfd4],ebx
  494be8:	e8 33 a4 24 00       	call   0x6df020
  494bed:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  494bf4:	75 24                	jne    0x494c1a
  494bf6:	09 35 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,esi
  494bfc:	c7 44 24 20 03 00 00 	mov    DWORD PTR [esp+0x20],0x3
  494c03:	00 
  494c04:	e8 87 a0 04 00       	call   0x4dec90
  494c09:	68 30 ce bc 00       	push   0xbcce30
  494c0e:	e8                   	.byte 0xe8
  494c0f:	07                   	pop    es

; game: receive/map_load_command 0x4b24f0..0x4b2566 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b24f0 <.data>:
  4b24f0:	55                   	push   ebp
  4b24f1:	8b ec                	mov    ebp,esp
  4b24f3:	b9 01 00 00 00       	mov    ecx,0x1
  4b24f8:	84 0d ec 79 fb 00    	test   BYTE PTR ds:0xfb79ec,cl
  4b24fe:	75 34                	jne    0x4b2534
  4b2500:	09 0d ec 79 fb 00    	or     DWORD PTR ds:0xfb79ec,ecx
  4b2506:	33 c0                	xor    eax,eax
  4b2508:	68 70 d2 bc 00       	push   0xbcd270
  4b250d:	c7 05 f0 79 fb 00 68 	mov    DWORD PTR ds:0xfb79f0,0xc0f868
  4b2514:	f8 c0 00 
  4b2517:	a3 f4 79 fb 00       	mov    ds:0xfb79f4,eax
  4b251c:	a3 f8 79 fb 00       	mov    ds:0xfb79f8,eax
  4b2521:	a3 fc 79 fb 00       	mov    ds:0xfb79fc,eax
  4b2526:	89 0d 04 7a fb 00    	mov    DWORD PTR ds:0xfb7a04,ecx
  4b252c:	e8 e9 fd 3d 00       	call   0x89231a
  4b2531:	83 c4 04             	add    esp,0x4
  4b2534:	57                   	push   edi
  4b2535:	68 f0 79 fb 00       	push   0xfb79f0
  4b253a:	e8 61 24 09 00       	call   0x5449a0
  4b253f:	8b 3d a4 a7 fb 00    	mov    edi,DWORD PTR ds:0xfba7a4
  4b2545:	e8 06 2a 09 00       	call   0x544f50
  4b254a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b254d:	8b 48 02             	mov    ecx,DWORD PTR [eax+0x2]
  4b2550:	51                   	push   ecx
  4b2551:	e8 0a cb f5 ff       	call   0x40f060
  4b2556:	50                   	push   eax
  4b2557:	e8 b4 cf 02 00       	call   0x4df510
  4b255c:	b8 00 01 00 00       	mov    eax,0x100
  4b2561:	5f                   	pop    edi
  4b2562:	5d                   	pop    ebp
  4b2563:	c2 0c 00             	ret    0xc

; game: receive/scene_replacement 0x4b7d50..0x4b7dc0 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b7d50 <.data>:
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret

; game: receive/scene_default 0x4b7ec0..0x4b7ef2 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b7ec0 <.data>:
  4b7ec0:	55                   	push   ebp
  4b7ec1:	8b ec                	mov    ebp,esp
  4b7ec3:	83 b9 ac 5e 00 00 00 	cmp    DWORD PTR [ecx+0x5eac],0x0
  4b7eca:	74 0e                	je     0x4b7eda
  4b7ecc:	8b 89 ac 5e 00 00    	mov    ecx,DWORD PTR [ecx+0x5eac]
  4b7ed2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7ed4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b7ed7:	5d                   	pop    ebp
  4b7ed8:	ff e0                	jmp    eax
  4b7eda:	0f bf 4d 10          	movsx  ecx,WORD PTR [ebp+0x10]
  4b7ede:	51                   	push   ecx
  4b7edf:	68 f8 6d c0 00       	push   0xc06df8
  4b7ee4:	e8 77 5c 23 00       	call   0x6edb60
  4b7ee9:	83 c4 08             	add    esp,0x8
  4b7eec:	33 c0                	xor    eax,eax
  4b7eee:	5d                   	pop    ebp
  4b7eef:	c2 0c 00             	ret    0xc

; game: receive/command_table_dispatch 0x4fda30..0x4fdab3 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004fda30 <.data>:
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
  4fdab0:	c2 0c 00             	ret    0xc

; game: receive/queue_pump 0x804740..0x804a0c (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00804740 <.data>:
  804740:	55                   	push   ebp
  804741:	8b ec                	mov    ebp,esp
  804743:	6a ff                	push   0xffffffff
  804745:	68 9c 9a 90 00       	push   0x909a9c
  80474a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  804750:	50                   	push   eax
  804751:	83 ec 4c             	sub    esp,0x4c
  804754:	53                   	push   ebx
  804755:	56                   	push   esi
  804756:	57                   	push   edi
  804757:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80475c:	33 c5                	xor    eax,ebp
  80475e:	50                   	push   eax
  80475f:	8d 45 f4             	lea    eax,[ebp-0xc]
  804762:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  804768:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80476b:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  804772:	75 27                	jne    0x80479b
  804774:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  80477b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804782:	e8 69 f8 ff ff       	call   0x803ff0
  804787:	68 90 dc bc 00       	push   0xbcdc90
  80478c:	e8 89 db 08 00       	call   0x89231a
  804791:	83 c4 04             	add    esp,0x4
  804794:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80479b:	a1 f0 11 fc 00       	mov    eax,ds:0xfc11f0
  8047a0:	6a 01                	push   0x1
  8047a2:	50                   	push   eax
  8047a3:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  8047aa:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  8047b0:	33 c0                	xor    eax,eax
  8047b2:	8d 7b 04             	lea    edi,[ebx+0x4]
  8047b5:	b9 0b 00 00 00       	mov    ecx,0xb
  8047ba:	8d 73 30             	lea    esi,[ebx+0x30]
  8047bd:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047bf:	89 45 a8             	mov    DWORD PTR [ebp-0x58],eax
  8047c2:	89 45 ac             	mov    DWORD PTR [ebp-0x54],eax
  8047c5:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  8047c8:	89 45 b4             	mov    DWORD PTR [ebp-0x4c],eax
  8047cb:	89 45 b8             	mov    DWORD PTR [ebp-0x48],eax
  8047ce:	89 45 bc             	mov    DWORD PTR [ebp-0x44],eax
  8047d1:	89 45 c0             	mov    DWORD PTR [ebp-0x40],eax
  8047d4:	89 45 c8             	mov    DWORD PTR [ebp-0x38],eax
  8047d7:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  8047da:	66 89 45 d0          	mov    WORD PTR [ebp-0x30],ax
  8047de:	b9 0b 00 00 00       	mov    ecx,0xb
  8047e3:	8d 75 a8             	lea    esi,[ebp-0x58]
  8047e6:	8d 7b 30             	lea    edi,[ebx+0x30]
  8047e9:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047eb:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8047f1:	ff d7                	call   edi
  8047f3:	8b 8b 84 00 00 00    	mov    ecx,DWORD PTR [ebx+0x84]
  8047f9:	89 43 30             	mov    DWORD PTR [ebx+0x30],eax
  8047fc:	2b 43 10             	sub    eax,DWORD PTR [ebx+0x10]
  8047ff:	8d 51 fc             	lea    edx,[ecx-0x4]
  804802:	3b c2                	cmp    eax,edx
  804804:	76 0d                	jbe    0x804813
  804806:	c7 45 ec 04 00 00 00 	mov    DWORD PTR [ebp-0x14],0x4
  80480d:	c6 43 58 01          	mov    BYTE PTR [ebx+0x58],0x1
  804811:	eb 03                	jmp    0x804816
  804813:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  804816:	33 f6                	xor    esi,esi
  804818:	89 73 50             	mov    DWORD PTR [ebx+0x50],esi
  80481b:	89 73 54             	mov    DWORD PTR [ebx+0x54],esi
  80481e:	ff d7                	call   edi
  804820:	89 43 38             	mov    DWORD PTR [ebx+0x38],eax
  804823:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  804826:	83 fe 02             	cmp    esi,0x2
  804829:	75 0c                	jne    0x804837
  80482b:	ff d7                	call   edi
  80482d:	89 43 40             	mov    DWORD PTR [ebx+0x40],eax
  804830:	c7 43 54 00 00 00 00 	mov    DWORD PTR [ebx+0x54],0x0
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  804841:	e8 ba f8 ff ff       	call   0x804100
  804846:	84 c0                	test   al,al
  804848:	0f 84 82 01 00 00    	je     0x8049d0
  80484e:	8b ff                	mov    edi,edi
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff d7                	call   edi
  804874:	2b 45 e8             	sub    eax,DWORD PTR [ebp-0x18]
  804877:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  80487a:	8b f8                	mov    edi,eax
  80487c:	8b 03                	mov    eax,DWORD PTR [ebx]
  80487e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  804881:	57                   	push   edi
  804882:	56                   	push   esi
  804883:	51                   	push   ecx
  804884:	8b cb                	mov    ecx,ebx
  804886:	ff d2                	call   edx
  804888:	83 ff 28             	cmp    edi,0x28
  80488b:	76 16                	jbe    0x8048a3
  80488d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804890:	8b 03                	mov    eax,DWORD PTR [ebx]
  804892:	8b 93 8c 00 00 00    	mov    edx,DWORD PTR [ebx+0x8c]
  804898:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  80489b:	57                   	push   edi
  80489c:	56                   	push   esi
  80489d:	51                   	push   ecx
  80489e:	52                   	push   edx
  80489f:	8b cb                	mov    ecx,ebx
  8048a1:	ff d0                	call   eax
  8048a3:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  8048aa:	75 27                	jne    0x8048d3
  8048ac:	b8 01 00 00 00       	mov    eax,0x1
  8048b1:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  8048b7:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  8048ba:	e8 61 28 00 00       	call   0x807120
  8048bf:	68 90 0b bd 00       	push   0xbd0b90
  8048c4:	e8 51 da 08 00       	call   0x89231a
  8048c9:	83 c4 04             	add    esp,0x4
  8048cc:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8048d3:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  8048d9:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  8048e0:	8b 0d b0 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b0
  8048e6:	51                   	push   ecx
  8048e7:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8048ed:	a1 a4 33 fe 00       	mov    eax,ds:0xfe33a4
  8048f2:	8b 15 a0 33 fe 00    	mov    edx,DWORD PTR ds:0xfe33a0
  8048f8:	03 d0                	add    edx,eax
  8048fa:	f6 c2 03             	test   dl,0x3
  8048fd:	75 18                	jne    0x804917
  8048ff:	83 c0 04             	add    eax,0x4
  804902:	c1 e8 02             	shr    eax,0x2
  804905:	39 05 9c 33 fe 00    	cmp    DWORD PTR ds:0xfe339c,eax
  80490b:	77 0a                	ja     0x804917
  80490d:	68 94 33 fe 00       	push   0xfe3394
  804912:	e8 59 26 e3 ff       	call   0x636f70
  804917:	a1 a0 33 fe 00       	mov    eax,ds:0xfe33a0
  80491c:	03 05 a4 33 fe 00    	add    eax,DWORD PTR ds:0xfe33a4
  804922:	8b 0d 9c 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe339c
  804928:	8b f8                	mov    edi,eax
  80492a:	c1 ef 02             	shr    edi,0x2
  80492d:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  804930:	3b cf                	cmp    ecx,edi
  804932:	77 02                	ja     0x804936
  804934:	2b f9                	sub    edi,ecx
  804936:	8b 15 98 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3398
  80493c:	83 3c ba 00          	cmp    DWORD PTR [edx+edi*4],0x0
  804940:	75 1e                	jne    0x804960
  804942:	6a 10                	push   0x10
  804944:	e8 1f c9 08 00       	call   0x891268
  804949:	83 c4 04             	add    esp,0x4
  80494c:	85 c0                	test   eax,eax
  80494e:	0f 84 b8 00 00 00    	je     0x804a0c
  804954:	8b 0d 98 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3398
  80495a:	89 04 b9             	mov    DWORD PTR [ecx+edi*4],eax
  80495d:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  804960:	8b 15 98 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3398
  804966:	8b 0c ba             	mov    ecx,DWORD PTR [edx+edi*4]
  804969:	83 e0 03             	and    eax,0x3
  80496c:	8d 04 81             	lea    eax,[ecx+eax*4]
  80496f:	85 c0                	test   eax,eax
  804971:	74 02                	je     0x804975
  804973:	89 30                	mov    DWORD PTR [eax],esi
  804975:	8b 15 b0 33 fe 00    	mov    edx,DWORD PTR ds:0xfe33b0
  80497b:	be 01 00 00 00       	mov    esi,0x1
  804980:	01 35 a4 33 fe 00    	add    DWORD PTR ds:0xfe33a4,esi
  804986:	29 35 ac 33 fe 00    	sub    DWORD PTR ds:0xfe33ac,esi
  80498c:	52                   	push   edx
  80498d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  804993:	01 73 50             	add    DWORD PTR [ebx+0x50],esi
  804996:	83 7d 08 02          	cmp    DWORD PTR [ebp+0x8],0x2
  80499a:	75 03                	jne    0x80499f
  80499c:	01 73 54             	add    DWORD PTR [ebx+0x54],esi
  80499f:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  8049a3:	75 22                	jne    0x8049c7
  8049a5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8049a8:	50                   	push   eax
  8049a9:	8d 4d f0             	lea    ecx,[ebp-0x10]
  8049ac:	51                   	push   ecx
  8049ad:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  8049b2:	e8 49 f7 ff ff       	call   0x804100
  8049b7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049bd:	84 c0                	test   al,al
  8049bf:	0f 85 8b fe ff ff    	jne    0x804850
  8049c5:	eb 06                	jmp    0x8049cd
  8049c7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049cd:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8049d0:	83 fe 02             	cmp    esi,0x2
  8049d3:	75 05                	jne    0x8049da
  8049d5:	ff d7                	call   edi
  8049d7:	89 43 44             	mov    DWORD PTR [ebx+0x44],eax
  8049da:	46                   	inc    esi
  8049db:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  8049de:	83 fe 06             	cmp    esi,0x6
  8049e1:	0f 8c 3f fe ff ff    	jl     0x804826
  8049e7:	ff d7                	call   edi
  8049e9:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  8049ec:	2b 43 38             	sub    eax,DWORD PTR [ebx+0x38]
  8049ef:	3b 45 ec             	cmp    eax,DWORD PTR [ebp-0x14]
  8049f2:	0f 97 c1             	seta   cl
  8049f5:	88 4b 59             	mov    BYTE PTR [ebx+0x59],cl
  8049f8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  8049fb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  804a02:	59                   	pop    ecx
  804a03:	5f                   	pop    edi
  804a04:	5e                   	pop    esi
  804a05:	5b                   	pop    ebx
  804a06:	8b e5                	mov    esp,ebp
  804a08:	5d                   	pop    ebp
  804a09:	c2 04 00             	ret    0x4

; game: receive/iocp_receive 0x806cf0..0x806f20 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00806cf0 <.data>:
  806cf0:	55                   	push   ebp
  806cf1:	8b ec                	mov    ebp,esp
  806cf3:	83 ec 24             	sub    esp,0x24
  806cf6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806cfb:	33 c5                	xor    eax,ebp
  806cfd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  806d00:	53                   	push   ebx
  806d01:	56                   	push   esi
  806d02:	33 f6                	xor    esi,esi
  806d04:	8b d9                	mov    ebx,ecx
  806d06:	57                   	push   edi
  806d07:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806d0a:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  806d0d:	89 75 e0             	mov    DWORD PTR [ebp-0x20],esi
  806d10:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  806d13:	3b fe                	cmp    edi,esi
  806d15:	74 19                	je     0x806d30
  806d17:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  806d1a:	50                   	push   eax
  806d1b:	68 d0 16 c5 00       	push   0xc516d0
  806d20:	56                   	push   esi
  806d21:	e8 da 96 ee ff       	call   0x6f0400
  806d26:	83 c4 0c             	add    esp,0xc
  806d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  806d30:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  806d37:	75 36                	jne    0x806d6f
  806d39:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  806d40:	56                   	push   esi
  806d41:	56                   	push   esi
  806d42:	56                   	push   esi
  806d43:	6a ff                	push   0xffffffff
  806d45:	89 35 b8 33 fe 00    	mov    DWORD PTR ds:0xfe33b8,esi
  806d4b:	89 35 bc 33 fe 00    	mov    DWORD PTR ds:0xfe33bc,esi
  806d51:	89 35 c0 33 fe 00    	mov    DWORD PTR ds:0xfe33c0,esi
  806d57:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806d5d:	68 b0 0b bd 00       	push   0xbd0bb0
  806d62:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806d67:	e8 ae b5 08 00       	call   0x89231a
  806d6c:	83 c4 04             	add    esp,0x4
  806d6f:	6a ff                	push   0xffffffff
  806d71:	8d 4d e0             	lea    ecx,[ebp-0x20]
  806d74:	51                   	push   ecx
  806d75:	8b 0d b8 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b8
  806d7b:	8d 55 e4             	lea    edx,[ebp-0x1c]
  806d7e:	52                   	push   edx
  806d7f:	8d 45 dc             	lea    eax,[ebp-0x24]
  806d82:	50                   	push   eax
  806d83:	51                   	push   ecx
  806d84:	ff 15 74 22 bd 00    	call   DWORD PTR ds:0xbd2274
  806d8a:	85 c0                	test   eax,eax
  806d8c:	0f 84 3d 01 00 00    	je     0x806ecf
  806d92:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806d95:	83 f8 01             	cmp    eax,0x1
  806d98:	0f 84 90 01 00 00    	je     0x806f2e
  806d9e:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  806da1:	3b d6                	cmp    edx,esi
  806da3:	75 1b                	jne    0x806dc0
  806da5:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806da8:	3b fe                	cmp    edi,esi
  806daa:	74 84                	je     0x806d30
  806dac:	68 04 17 c5 00       	push   0xc51704
  806db1:	6a 02                	push   0x2
  806db3:	e8 48 96 ee ff       	call   0x6f0400
  806db8:	83 c4 08             	add    esp,0x8
  806dbb:	e9 70 ff ff ff       	jmp    0x806d30
  806dc0:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  806dc3:	3b ce                	cmp    ecx,esi
  806dc5:	75 1d                	jne    0x806de4
  806dc7:	8b 13                	mov    edx,DWORD PTR [ebx]
  806dc9:	56                   	push   esi
  806dca:	50                   	push   eax
  806dcb:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806dce:	8b cb                	mov    ecx,ebx
  806dd0:	ff d0                	call   eax
  806dd2:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  806dd5:	c7 81 a8 a0 00 00 01 	mov    DWORD PTR [ecx+0xa0a8],0x1
  806ddc:	00 00 00 
  806ddf:	e9 4c ff ff ff       	jmp    0x806d30
  806de4:	8d b8 30 a0 00 00    	lea    edi,[eax+0xa030]
  806dea:	3b d7                	cmp    edx,edi
  806dec:	0f 85 8b 00 00 00    	jne    0x806e7d
  806df2:	01 4b 2c             	add    DWORD PTR [ebx+0x2c],ecx
  806df5:	ff 43 3c             	inc    DWORD PTR [ebx+0x3c]
  806df8:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806dfe:	0f 84 2c ff ff ff    	je     0x806d30
  806e04:	8d 50 18             	lea    edx,[eax+0x18]
  806e07:	50                   	push   eax
  806e08:	e8 33 0d 00 00       	call   0x807b40
  806e0d:	85 c0                	test   eax,eax
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74 3a                	je     0x806e6e
  806e34:	0f b6 48 0b          	movzx  ecx,BYTE PTR [eax+0xb]
  806e38:	0f b6 50 0a          	movzx  edx,BYTE PTR [eax+0xa]
  806e3c:	51                   	push   ecx
  806e3d:	0f b6 48 09          	movzx  ecx,BYTE PTR [eax+0x9]
  806e41:	52                   	push   edx
  806e42:	0f b6 50 08          	movzx  edx,BYTE PTR [eax+0x8]
  806e46:	51                   	push   ecx
  806e47:	52                   	push   edx
  806e48:	68 50 b0 bf 00       	push   0xbfb050
  806e4d:	8d 55 e8             	lea    edx,[ebp-0x18]
  806e50:	e8 db d4 cb ff       	call   0x4c4330
  806e55:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806e58:	8d 45 e8             	lea    eax,[ebp-0x18]
  806e5b:	50                   	push   eax
  806e5c:	68 18 17 c5 00       	push   0xc51718
  806e61:	6a 02                	push   0x2
  806e63:	e8 98 95 ee ff       	call   0x6f0400
  806e68:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e6b:	83 c4 20             	add    esp,0x20
  806e6e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  806e75:	00 00 00 
  806e78:	e9 b3 fe ff ff       	jmp    0x806d30
  806e7d:	8d b8 50 a0 00 00    	lea    edi,[eax+0xa050]
  806e83:	3b d7                	cmp    edx,edi
  806e85:	0f 85 a5 fe ff ff    	jne    0x806d30
  806e8b:	01 4b 28             	add    DWORD PTR [ebx+0x28],ecx
  806e8e:	ff 43 38             	inc    DWORD PTR [ebx+0x38]
  806e91:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806e97:	74 12                	je     0x806eab
  806e99:	8d b0 1c 50 00 00    	lea    esi,[eax+0x501c]
  806e9f:	8b f9                	mov    edi,ecx
  806ea1:	e8 0a 09 00 00       	call   0x8077b0
  806ea6:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806ea9:	33 f6                	xor    esi,esi
  806eab:	39 b0 28 a0 00 00    	cmp    DWORD PTR [eax+0xa028],esi
  806eb1:	0f 97 c1             	seta   cl
  806eb4:	88 88 24 a0 00 00    	mov    BYTE PTR [eax+0xa024],cl
  806eba:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  806ebd:	81 c2 b8 a0 00 00    	add    edx,0xa0b8
  806ec3:	52                   	push   edx
  806ec4:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
  806ecf:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  806ed2:	3b ce                	cmp    ecx,esi
  806ed4:	0f 84 56 fe ff ff    	je     0x806d30
  806eda:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806edd:	8d 90 30 a0 00 00    	lea    edx,[eax+0xa030]
  806ee3:	3b ca                	cmp    ecx,edx
  806ee5:	74 19                	je     0x806f00
  806ee7:	8d 90 50 a0 00 00    	lea    edx,[eax+0xa050]
  806eed:	3b ca                	cmp    ecx,edx
  806eef:	75 0f                	jne    0x806f00
  806ef1:	05 b8 a0 00 00       	add    eax,0xa0b8
  806ef6:	50                   	push   eax
  806ef7:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806efd:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f00:	8b 80 b8 a0 00 00    	mov    eax,DWORD PTR [eax+0xa0b8]
  806f06:	85 c0                	test   eax,eax
  806f08:	0f 85 22 fe ff ff    	jne    0x806d30
  806f0e:	8b 13                	mov    edx,DWORD PTR [ebx]
  806f10:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f13:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  806f16:	56                   	push   esi
  806f17:	50                   	push   eax
  806f18:	8b cb                	mov    ecx,ebx
  806f1a:	ff d2                	call   edx
  806f1c:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f1f:	c7                   	.byte 0xc7

; game: receive/frame_parser 0x807b40..0x807e45 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00807b40 <.data>:
  807b40:	55                   	push   ebp
  807b41:	8b ec                	mov    ebp,esp
  807b43:	83 e4 f8             	and    esp,0xfffffff8
  807b46:	6a ff                	push   0xffffffff
  807b48:	68 be 98 90 00       	push   0x9098be
  807b4d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  807b53:	50                   	push   eax
  807b54:	51                   	push   ecx
  807b55:	b8 24 20 00 00       	mov    eax,0x2024
  807b5a:	e8 11 8b 0a 00       	call   0x8b0670
  807b5f:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b64:	33 c4                	xor    eax,esp
  807b66:	89 84 24 20 20 00 00 	mov    DWORD PTR [esp+0x2020],eax
  807b6d:	53                   	push   ebx
  807b6e:	56                   	push   esi
  807b6f:	57                   	push   edi
  807b70:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b75:	33 c4                	xor    eax,esp
  807b77:	50                   	push   eax
  807b78:	8d 84 24 38 20 00 00 	lea    eax,[esp+0x2038]
  807b7f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  807b85:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807b88:	8b fa                	mov    edi,edx
  807b8a:	01 8f 00 50 00 00    	add    DWORD PTR [edi+0x5000],ecx
  807b90:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807b94:	8b 87 00 50 00 00    	mov    eax,DWORD PTR [edi+0x5000]
  807b9a:	2b c7                	sub    eax,edi
  807b9c:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  807ba0:	8b df                	mov    ebx,edi
  807ba2:	83 f8 04             	cmp    eax,0x4
  807ba5:	0f 82 2f 02 00 00    	jb     0x807dda
  807bab:	eb 03                	jmp    0x807bb0
  807bad:	8d 49 00             	lea    ecx,[ecx+0x0]
  807bb0:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807bb3:	33 c9                	xor    ecx,ecx
  807bb5:	66 3b f1             	cmp    si,cx
  807bb8:	0f 84 5f 02 00 00    	je     0x807e1d
  807bbe:	ba 00 10 00 00       	mov    edx,0x1000
  807bc3:	66 3b f2             	cmp    si,dx
  807bc6:	0f 87 51 02 00 00    	ja     0x807e1d
  807bcc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  807bd0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  807bd4:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  807bd8:	ba 33 26 00 00       	mov    edx,0x2633
  807bdd:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807be4:	00 
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf1:	00 
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bf9:	00 
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0d:	00 
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c15:	00 
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c33:	00 
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
  807c44:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  807c4b:	75 2f                	jne    0x807c7c
  807c4d:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  807c54:	c7 84 24 40 20 00 00 	mov    DWORD PTR [esp+0x2040],0x0
  807c5b:	00 00 00 00 
  807c5f:	e8 bc f4 ff ff       	call   0x807120
  807c64:	68 90 0b bd 00       	push   0xbd0b90
  807c69:	e8 ac a6 08 00       	call   0x89231a
  807c6e:	83 c4 04             	add    esp,0x4
  807c71:	c7 84 24 40 20 00 00 	mov    DWORD PTR [esp+0x2040],0xffffffff
  807c78:	ff ff ff ff 
  807c7c:	bf 58 33 fe 00       	mov    edi,0xfe3358
  807c81:	e8 2a f9 ff ff       	call   0x8075b0
  807c86:	8d 3c 1e             	lea    edi,[esi+ebx*1]
  807c89:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807c8c:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  807c90:	8d 0c 3e             	lea    ecx,[esi+edi*1]
  807c93:	3b 7c 24 14          	cmp    edi,DWORD PTR [esp+0x14]
  807c97:	0f 82 39 01 00 00    	jb     0x807dd6
  807c9d:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807ca1:	81 c2 00 50 00 00    	add    edx,0x5000
  807ca7:	3b fa                	cmp    edi,edx
  807ca9:	0f 83 27 01 00 00    	jae    0x807dd6
  807caf:	3b 4c 24 14          	cmp    ecx,DWORD PTR [esp+0x14]
  807cb3:	0f 82 1d 01 00 00    	jb     0x807dd6
  807cb9:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807cbd:	81 c2 00 50 00 00    	add    edx,0x5000
  807cc3:	3b ca                	cmp    ecx,edx
  807cc5:	0f 83 0b 01 00 00    	jae    0x807dd6
  807ccb:	83 7c 24 18 00       	cmp    DWORD PTR [esp+0x18],0x0
  807cd0:	74 5a                	je     0x807d2c
  807cd2:	8a 17                	mov    dl,BYTE PTR [edi]
  807cd4:	80 f2 7c             	xor    dl,0x7c
  807cd7:	b8 01 00 00 00       	mov    eax,0x1
  807cdc:	88 54 24 2c          	mov    BYTE PTR [esp+0x2c],dl
  807ce0:	3b f0                	cmp    esi,eax
  807ce2:	76 10                	jbe    0x807cf4
  807ce4:	8a 0c 07             	mov    cl,BYTE PTR [edi+eax*1]
  807ce7:	32 4c 04 2b          	xor    cl,BYTE PTR [esp+eax*1+0x2b]
  807ceb:	40                   	inc    eax
  807cec:	88 4c 04 2b          	mov    BYTE PTR [esp+eax*1+0x2b],cl
  807cf0:	3b c6                	cmp    eax,esi
  807cf2:	72 f0                	jb     0x807ce4
  807cf4:	8d 94 24 2c 10 00 00 	lea    edx,[esp+0x102c]
  807cfb:	52                   	push   edx
  807cfc:	8b ce                	mov    ecx,esi
  807cfe:	8d 44 24 30          	lea    eax,[esp+0x30]
  807d02:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  807d06:	c7 44 24 1c 00 10 00 	mov    DWORD PTR [esp+0x1c],0x1000
  807d0d:	00 
  807d0e:	e8 7d f4 f1 ff       	call   0x727190
  807d13:	83 c4 04             	add    esp,0x4
  807d16:	85 c0                	test   eax,eax
  807d18:	75 65                	jne    0x807d7f
  807d1a:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  807d1e:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d22:	8d 84 24 2c 10 00 00 	lea    eax,[esp+0x102c]
  807d29:	50                   	push   eax
  807d2a:	eb 4e                	jmp    0x807d7a
  807d2c:	83 7c 24 1c 00       	cmp    DWORD PTR [esp+0x1c],0x0
  807d31:	74 44                	je     0x807d77
  807d33:	8a 07                	mov    al,BYTE PTR [edi]
  807d35:	34 b6                	xor    al,0xb6
  807d37:	0f b6 c8             	movzx  ecx,al
  807d3a:	8b d1                	mov    edx,ecx
  807d3c:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  807d40:	ba 01 00 00 00       	mov    edx,0x1
  807d45:	88 44 24 2c          	mov    BYTE PTR [esp+0x2c],al
  807d49:	3b f2                	cmp    esi,edx
  807d4b:	76 19                	jbe    0x807d66
  807d4d:	8d 49 00             	lea    ecx,[ecx+0x0]
  807d50:	8a 04 3a             	mov    al,BYTE PTR [edx+edi*1]
  807d53:	32 44 14 2b          	xor    al,BYTE PTR [esp+edx*1+0x2b]
  807d57:	42                   	inc    edx
  807d58:	88 44 14 2b          	mov    BYTE PTR [esp+edx*1+0x2b],al
  807d5c:	0f b6 c0             	movzx  eax,al
  807d5f:	66 03 c8             	add    cx,ax
  807d62:	3b d6                	cmp    edx,esi
  807d64:	72 ea                	jb     0x807d50
  807d66:	66 39 4b 04          	cmp    WORD PTR [ebx+0x4],cx
  807d6a:	75 13                	jne    0x807d7f
  807d6c:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d70:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  807d74:	51                   	push   ecx
  807d75:	eb 03                	jmp    0x807d7a
  807d77:	57                   	push   edi
  807d78:	8b f8                	mov    edi,eax
  807d7a:	e8 d1 00 00 00       	call   0x807e50
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
  807db2:	0f b7 13             	movzx  edx,WORD PTR [ebx]
  807db5:	03 54 24 20          	add    edx,DWORD PTR [esp+0x20]
  807db9:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  807dbd:	8b 80 00 50 00 00    	mov    eax,DWORD PTR [eax+0x5000]
  807dc3:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dc7:	03 da                	add    ebx,edx
  807dc9:	2b c3                	sub    eax,ebx
  807dcb:	83 f8 04             	cmp    eax,0x4
  807dce:	0f 83 dc fd ff ff    	jae    0x807bb0
  807dd4:	eb 04                	jmp    0x807dda
  807dd6:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dda:	8b b7 00 50 00 00    	mov    esi,DWORD PTR [edi+0x5000]
  807de0:	8d 87 00 50 00 00    	lea    eax,[edi+0x5000]
  807de6:	2b f3                	sub    esi,ebx
  807de8:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807dec:	8d 0c 1e             	lea    ecx,[esi+ebx*1]
  807def:	3b df                	cmp    ebx,edi
  807df1:	72 2a                	jb     0x807e1d
  807df3:	3b d8                	cmp    ebx,eax
  807df5:	73 26                	jae    0x807e1d
  807df7:	3b cf                	cmp    ecx,edi
  807df9:	72 22                	jb     0x807e1d
  807dfb:	3b c8                	cmp    ecx,eax
  807dfd:	73 1e                	jae    0x807e1d
  807dff:	85 f6                	test   esi,esi
  807e01:	78 1a                	js     0x807e1d
  807e03:	56                   	push   esi
  807e04:	53                   	push   ebx
  807e05:	57                   	push   edi
  807e06:	e8 e5 94 08 00       	call   0x8912f0
  807e0b:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  807e0f:	83 c4 0c             	add    esp,0xc
  807e12:	03 fe                	add    edi,esi
  807e14:	89 38                	mov    DWORD PTR [eax],edi
  807e16:	b8 01 00 00 00       	mov    eax,0x1
  807e1b:	eb 02                	jmp    0x807e1f
  807e1d:	33 c0                	xor    eax,eax
  807e1f:	8b 8c 24 38 20 00 00 	mov    ecx,DWORD PTR [esp+0x2038]
  807e26:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  807e2d:	59                   	pop    ecx
  807e2e:	5f                   	pop    edi
  807e2f:	5e                   	pop    esi
  807e30:	5b                   	pop    ebx
  807e31:	8b 8c 24 20 20 00 00 	mov    ecx,DWORD PTR [esp+0x2020]
  807e38:	33 cc                	xor    ecx,esp
  807e3a:	e8 c2 91 08 00       	call   0x891001
  807e3f:	8b e5                	mov    esp,ebp
  807e41:	5d                   	pop    ebp
  807e42:	c2 04 00             	ret    0x4

; game: receive/tick_vtable_pointer 0xc05ad4..0xc05ad8 (end exclusive)
; data: e0 0f 49 00

; game: receive/callback_vtable_pointer 0xc05aec..0xc05af0 (end exclusive)
; data: e0 30 49 00

; game: loader/open-precedence 0x714770..0x714880 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00714770 <.data>:
  714770:	55                   	push   ebp
  714771:	8b ec                	mov    ebp,esp
  714773:	6a ff                	push   0xffffffff
  714775:	68 6c 15 92 00       	push   0x92156c
  71477a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  714780:	50                   	push   eax
  714781:	51                   	push   ecx
  714782:	53                   	push   ebx
  714783:	57                   	push   edi
  714784:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  714789:	33 c5                	xor    eax,ebp
  71478b:	50                   	push   eax
  71478c:	8d 45 f4             	lea    eax,[ebp-0xc]
  71478f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  714795:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  714798:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  71479b:	57                   	push   edi
  71479c:	8b cb                	mov    ecx,ebx
  71479e:	e8 6d f1 ff ff       	call   0x713910
  7147a3:	83 c4 04             	add    esp,0x4
  7147a6:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7147a9:	85 c0                	test   eax,eax
  7147ab:	0f 85 be 00 00 00    	jne    0x71486f
  7147b1:	f6 05 98 4c fe 00 01 	test   BYTE PTR ds:0xfe4c98,0x1
  7147b8:	75 23                	jne    0x7147dd
  7147ba:	83 0d 98 4c fe 00 01 	or     DWORD PTR ds:0xfe4c98,0x1
  7147c1:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  7147c4:	e8 07 fb ff ff       	call   0x7142d0
  7147c9:	68 60 07 bd 00       	push   0xbd0760
  7147ce:	e8 47 db 17 00       	call   0x89231a
  7147d3:	83 c4 04             	add    esp,0x4
  7147d6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7147dd:	80 3d 94 4c fe 00 00 	cmp    BYTE PTR ds:0xfe4c94,0x0
  7147e4:	75 1a                	jne    0x714800
  7147e6:	8b cf                	mov    ecx,edi
  7147e8:	8b fb                	mov    edi,ebx
  7147ea:	e8 41 f8 ff ff       	call   0x714030
  7147ef:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7147f2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7147f9:	59                   	pop    ecx
  7147fa:	5f                   	pop    edi
  7147fb:	5b                   	pop    ebx
  7147fc:	8b e5                	mov    esp,ebp
  7147fe:	5d                   	pop    ebp
  7147ff:	c3                   	ret
  714800:	f6 05 98 4c fe 00 01 	test   BYTE PTR ds:0xfe4c98,0x1
  714807:	75 27                	jne    0x714830
  714809:	b8 01 00 00 00       	mov    eax,0x1
  71480e:	09 05 98 4c fe 00    	or     DWORD PTR ds:0xfe4c98,eax
  714814:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  714817:	e8 b4 fa ff ff       	call   0x7142d0
  71481c:	68 60 07 bd 00       	push   0xbd0760
  714821:	e8 f4 da 17 00       	call   0x89231a
  714826:	83 c4 04             	add    esp,0x4
  714829:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  714830:	8b cb                	mov    ecx,ebx
  714832:	bf 7c 4c fe 00       	mov    edi,0xfe4c7c
  714837:	e8 74 fb ff ff       	call   0x7143b0
  71483c:	84 c0                	test   al,al
  71483e:	75 11                	jne    0x714851
  714840:	e8 1b fa ff ff       	call   0x714260
  714845:	50                   	push   eax
  714846:	8b cb                	mov    ecx,ebx
  714848:	e8 23 fc ff ff       	call   0x714470
  71484d:	84 c0                	test   al,al
  71484f:	74 1b                	je     0x71486c
  714851:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  714854:	8b fb                	mov    edi,ebx
  714856:	e8 d5 f7 ff ff       	call   0x714030
  71485b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  71485e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  714865:	59                   	pop    ecx
  714866:	5f                   	pop    edi
  714867:	5b                   	pop    ebx
  714868:	8b e5                	mov    esp,ebp
  71486a:	5d                   	pop    ebp
  71486b:	c3                   	ret
  71486c:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  71486f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  714872:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  714879:	59                   	pop    ecx
  71487a:	5f                   	pop    edi
  71487b:	5b                   	pop    ebx
  71487c:	8b e5                	mov    esp,ebp
  71487e:	5d                   	pop    ebp
  71487f:	c3                   	ret

; game: loader/archive-open 0x713910..0x713ab1 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00713910 <.data>:
  713910:	55                   	push   ebp
  713911:	8b ec                	mov    ebp,esp
  713913:	83 ec 28             	sub    esp,0x28
  713916:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  71391b:	33 c5                	xor    eax,ebp
  71391d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  713920:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  713923:	53                   	push   ebx
  713924:	56                   	push   esi
  713925:	33 db                	xor    ebx,ebx
  713927:	8b f1                	mov    esi,ecx
  713929:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
  71392c:	39 1d 14 a8 fb 00    	cmp    DWORD PTR ds:0xfba814,ebx
  713932:	75 12                	jne    0x713946
  713934:	5e                   	pop    esi
  713935:	33 c0                	xor    eax,eax
  713937:	5b                   	pop    ebx
  713938:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  71393b:	33 cd                	xor    ecx,ebp
  71393d:	e8 bf d6 17 00       	call   0x891001
  713942:	8b e5                	mov    esp,ebp
  713944:	5d                   	pop    ebp
  713945:	c3                   	ret
  713946:	0f be 00             	movsx  eax,BYTE PTR [eax]
  713949:	50                   	push   eax
  71394a:	e8 be 04 18 00       	call   0x893e0d
  71394f:	83 c4 04             	add    esp,0x4
  713952:	3c 77                	cmp    al,0x77
  713954:	74 de                	je     0x713934
  713956:	3c 61                	cmp    al,0x61
  713958:	74 da                	je     0x713934
  71395a:	3c 72                	cmp    al,0x72
  71395c:	75 d6                	jne    0x713934
  71395e:	8b 0d 14 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba814
  713964:	6a 01                	push   0x1
  713966:	56                   	push   esi
  713967:	83 c1 04             	add    ecx,0x4
  71396a:	e8 e1 12 00 00       	call   0x714c50
  71396f:	8b f0                	mov    esi,eax
  713971:	3b f3                	cmp    esi,ebx
  713973:	74 bf                	je     0x713934
  713975:	57                   	push   edi
  713976:	8d 7e 2c             	lea    edi,[esi+0x2c]
  713979:	57                   	push   edi
  71397a:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  713980:	ff 46 54             	inc    DWORD PTR [esi+0x54]
  713983:	57                   	push   edi
  713984:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  71398a:	39 5e 08             	cmp    DWORD PTR [esi+0x8],ebx
  71398d:	75 16                	jne    0x7139a5
  71398f:	8b 4d d8             	mov    ecx,DWORD PTR [ebp-0x28]
  713992:	6a 01                	push   0x1
  713994:	51                   	push   ecx
  713995:	8b 0d 14 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba814
  71399b:	83 c1 04             	add    ecx,0x4
  71399e:	e8 ad 12 00 00       	call   0x714c50
  7139a3:	8b f0                	mov    esi,eax
  7139a5:	6a 18                	push   0x18
  7139a7:	c7 46 50 01 00 00 00 	mov    DWORD PTR [esi+0x50],0x1
  7139ae:	e8 b5 d8 17 00       	call   0x891268
  7139b3:	83 c4 04             	add    esp,0x4
  7139b6:	3b c3                	cmp    eax,ebx
  7139b8:	74 19                	je     0x7139d3
  7139ba:	c7 00 c4 41 c4 00    	mov    DWORD PTR [eax],0xc441c4
  7139c0:	88 58 04             	mov    BYTE PTR [eax+0x4],bl
  7139c3:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  7139c6:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  7139c9:	89 58 10             	mov    DWORD PTR [eax+0x10],ebx
  7139cc:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  7139cf:	8b f8                	mov    edi,eax
  7139d1:	eb 02                	jmp    0x7139d5
  7139d3:	33 ff                	xor    edi,edi
  7139d5:	8b 0d 18 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba818
  7139db:	c6 47 04 72          	mov    BYTE PTR [edi+0x4],0x72
  7139df:	89 77 14             	mov    DWORD PTR [edi+0x14],esi
  7139e2:	3b cb                	cmp    ecx,ebx
  7139e4:	74 3d                	je     0x713a23
  7139e6:	8b 46 18             	mov    eax,DWORD PTR [esi+0x18]
  7139e9:	8b 56 14             	mov    edx,DWORD PTR [esi+0x14]
  7139ec:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7139ef:	8b 46 20             	mov    eax,DWORD PTR [esi+0x20]
  7139f2:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  7139f5:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  7139f8:	8b 56 1c             	mov    edx,DWORD PTR [esi+0x1c]
  7139fb:	8d 45 dc             	lea    eax,[ebp-0x24]
  7139fe:	50                   	push   eax
  7139ff:	8b 46 4c             	mov    eax,DWORD PTR [esi+0x4c]
  713a02:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  713a05:	8b 11                	mov    edx,DWORD PTR [ecx]
  713a07:	8b 52 08             	mov    edx,DWORD PTR [edx+0x8]
  713a0a:	50                   	push   eax
  713a0b:	8b 46 48             	mov    eax,DWORD PTR [esi+0x48]
  713a0e:	50                   	push   eax
  713a0f:	ff d2                	call   edx
  713a11:	33 c0                	xor    eax,eax
  713a13:	8a 4c 05 ec          	mov    cl,BYTE PTR [ebp+eax*1-0x14]
  713a17:	3a 4c 05 dc          	cmp    cl,BYTE PTR [ebp+eax*1-0x24]
  713a1b:	75 19                	jne    0x713a36
  713a1d:	40                   	inc    eax
  713a1e:	83 f8 10             	cmp    eax,0x10
  713a21:	7c f0                	jl     0x713a13
  713a23:	8b c7                	mov    eax,edi
  713a25:	5f                   	pop    edi
  713a26:	5e                   	pop    esi
  713a27:	5b                   	pop    ebx
  713a28:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  713a2b:	33 cd                	xor    ecx,ebp
  713a2d:	e8 cf d5 17 00       	call   0x891001
  713a32:	8b e5                	mov    esp,ebp
  713a34:	5d                   	pop    ebp
  713a35:	c3                   	ret
  713a36:	33 c0                	xor    eax,eax
  713a38:	38 5c 05 ec          	cmp    BYTE PTR [ebp+eax*1-0x14],bl
  713a3c:	75 45                	jne    0x713a83
  713a3e:	40                   	inc    eax
  713a3f:	83 f8 10             	cmp    eax,0x10
  713a42:	7c f4                	jl     0x713a38
  713a44:	8b 0d 18 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba818
  713a4a:	8b 11                	mov    edx,DWORD PTR [ecx]
  713a4c:	8b 12                	mov    edx,DWORD PTR [edx]
  713a4e:	8d 45 ec             	lea    eax,[ebp-0x14]
  713a51:	50                   	push   eax
  713a52:	8b 45 d8             	mov    eax,DWORD PTR [ebp-0x28]
  713a55:	50                   	push   eax
  713a56:	ff d2                	call   edx
  713a58:	84 c0                	test   al,al
  713a5a:	74 c7                	je     0x713a23
  713a5c:	33 c0                	xor    eax,eax
  713a5e:	8b ff                	mov    edi,edi
  713a60:	8a 4c 05 ec          	mov    cl,BYTE PTR [ebp+eax*1-0x14]
  713a64:	3a 4c 05 dc          	cmp    cl,BYTE PTR [ebp+eax*1-0x24]
  713a68:	75 19                	jne    0x713a83
  713a6a:	40                   	inc    eax
  713a6b:	83 f8 10             	cmp    eax,0x10
  713a6e:	7c f0                	jl     0x713a60
  713a70:	8b c7                	mov    eax,edi
  713a72:	5f                   	pop    edi
  713a73:	5e                   	pop    esi
  713a74:	5b                   	pop    ebx
  713a75:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  713a78:	33 cd                	xor    ecx,ebp
  713a7a:	e8 82 d5 17 00       	call   0x891001
  713a7f:	8b e5                	mov    esp,ebp
  713a81:	5d                   	pop    ebp
  713a82:	c3                   	ret
  713a83:	8b 0d 14 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba814
  713a89:	8b 11                	mov    edx,DWORD PTR [ecx]
  713a8b:	8b 45 d8             	mov    eax,DWORD PTR [ebp-0x28]
  713a8e:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  713a91:	50                   	push   eax
  713a92:	ff d2                	call   edx
  713a94:	8b 07                	mov    eax,DWORD PTR [edi]
  713a96:	8b 10                	mov    edx,DWORD PTR [eax]
  713a98:	6a 01                	push   0x1
  713a9a:	8b cf                	mov    ecx,edi
  713a9c:	ff d2                	call   edx
  713a9e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  713aa1:	5f                   	pop    edi
  713aa2:	5e                   	pop    esi
  713aa3:	33 cd                	xor    ecx,ebp
  713aa5:	33 c0                	xor    eax,eax
  713aa7:	5b                   	pop    ebx
  713aa8:	e8 54 d5 17 00       	call   0x891001
  713aad:	8b e5                	mov    esp,ebp
  713aaf:	5d                   	pop    ebp
  713ab0:	c3                   	ret

; game: loader/archive-release 0x713ac0..0x713b08 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00713ac0 <.data>:
  713ac0:	53                   	push   ebx
  713ac1:	8b d9                	mov    ebx,ecx
  713ac3:	56                   	push   esi
  713ac4:	8b 73 14             	mov    esi,DWORD PTR [ebx+0x14]
  713ac7:	85 f6                	test   esi,esi
  713ac9:	74 2b                	je     0x713af6
  713acb:	57                   	push   edi
  713acc:	8d 7e 2c             	lea    edi,[esi+0x2c]
  713acf:	57                   	push   edi
  713ad0:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  713ad6:	8b 46 54             	mov    eax,DWORD PTR [esi+0x54]
  713ad9:	85 c0                	test   eax,eax
  713adb:	74 11                	je     0x713aee
  713add:	48                   	dec    eax
  713ade:	89 46 54             	mov    DWORD PTR [esi+0x54],eax
  713ae1:	75 0b                	jne    0x713aee
  713ae3:	83 7e 50 00          	cmp    DWORD PTR [esi+0x50],0x0
  713ae7:	74 05                	je     0x713aee
  713ae9:	e8 f2 3f 00 00       	call   0x717ae0
  713aee:	57                   	push   edi
  713aef:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  713af5:	5f                   	pop    edi
  713af6:	8b 03                	mov    eax,DWORD PTR [ebx]
  713af8:	8b 10                	mov    edx,DWORD PTR [eax]
  713afa:	6a 01                	push   0x1
  713afc:	8b cb                	mov    ecx,ebx
  713afe:	ff d2                	call   edx
  713b00:	5e                   	pop    esi
  713b01:	b8 01 00 00 00       	mov    eax,0x1
  713b06:	5b                   	pop    ebx
  713b07:	c3                   	ret

; game: loader/mounted-directory-lookup 0x714c50..0x714d4d (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00714c50 <.data>:
  714c50:	55                   	push   ebp
  714c51:	8b ec                	mov    ebp,esp
  714c53:	81 ec 08 01 00 00    	sub    esp,0x108
  714c59:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  714c5e:	33 c5                	xor    eax,ebp
  714c60:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  714c63:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  714c66:	53                   	push   ebx
  714c67:	57                   	push   edi
  714c68:	50                   	push   eax
  714c69:	8d 85 f8 fe ff ff    	lea    eax,[ebp-0x108]
  714c6f:	68 04 01 00 00       	push   0x104
  714c74:	50                   	push   eax
  714c75:	8b d9                	mov    ebx,ecx
  714c77:	e8 dd ee 17 00       	call   0x893b59
  714c7c:	8d 8d f8 fe ff ff    	lea    ecx,[ebp-0x108]
  714c82:	51                   	push   ecx
  714c83:	e8 48 24 00 00       	call   0x7170d0
  714c88:	8b f8                	mov    edi,eax
  714c8a:	83 c4 10             	add    esp,0x10
  714c8d:	85 ff                	test   edi,edi
  714c8f:	75 12                	jne    0x714ca3
  714c91:	5f                   	pop    edi
  714c92:	5b                   	pop    ebx
  714c93:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  714c96:	33 cd                	xor    ecx,ebp
  714c98:	e8 64 c3 17 00       	call   0x891001
  714c9d:	8b e5                	mov    esp,ebp
  714c9f:	5d                   	pop    ebp
  714ca0:	c2 08 00             	ret    0x8
  714ca3:	c6 07 00             	mov    BYTE PTR [edi],0x0
  714ca6:	47                   	inc    edi
  714ca7:	8b d7                	mov    edx,edi
  714ca9:	8d 85 f8 fe ff ff    	lea    eax,[ebp-0x108]
  714caf:	2b d0                	sub    edx,eax
  714cb1:	83 fa 01             	cmp    edx,0x1
  714cb4:	75 21                	jne    0x714cd7
  714cb6:	52                   	push   edx
  714cb7:	8d 8d f9 fe ff ff    	lea    ecx,[ebp-0x107]
  714cbd:	51                   	push   ecx
  714cbe:	8b cb                	mov    ecx,ebx
  714cc0:	e8 8b ff ff ff       	call   0x714c50
  714cc5:	5f                   	pop    edi
  714cc6:	5b                   	pop    ebx
  714cc7:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  714cca:	33 cd                	xor    ecx,ebp
  714ccc:	e8 30 c3 17 00       	call   0x891001
  714cd1:	8b e5                	mov    esp,ebp
  714cd3:	5d                   	pop    ebp
  714cd4:	c2 08 00             	ret    0x8
  714cd7:	8b 83 04 01 00 00    	mov    eax,DWORD PTR [ebx+0x104]
  714cdd:	56                   	push   esi
  714cde:	8b 30                	mov    esi,DWORD PTR [eax]
  714ce0:	3b f0                	cmp    esi,eax
  714ce2:	74 21                	je     0x714d05
  714ce4:	8d 95 f8 fe ff ff    	lea    edx,[ebp-0x108]
  714cea:	52                   	push   edx
  714ceb:	8d 46 08             	lea    eax,[esi+0x8]
  714cee:	50                   	push   eax
  714cef:	e8 bd ef 17 00       	call   0x893cb1
  714cf4:	83 c4 08             	add    esp,0x8
  714cf7:	85 c0                	test   eax,eax
  714cf9:	74 1f                	je     0x714d1a
  714cfb:	8b 36                	mov    esi,DWORD PTR [esi]
  714cfd:	3b b3 04 01 00 00    	cmp    esi,DWORD PTR [ebx+0x104]
  714d03:	75 df                	jne    0x714ce4
  714d05:	33 c0                	xor    eax,eax
  714d07:	5e                   	pop    esi
  714d08:	5f                   	pop    edi
  714d09:	5b                   	pop    ebx
  714d0a:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  714d0d:	33 cd                	xor    ecx,ebp
  714d0f:	e8 ed c2 17 00       	call   0x891001
  714d14:	8b e5                	mov    esp,ebp
  714d16:	5d                   	pop    ebp
  714d17:	c2 08 00             	ret    0x8
  714d1a:	8b 86 08 01 00 00    	mov    eax,DWORD PTR [esi+0x108]
  714d20:	85 c0                	test   eax,eax
  714d22:	74 0b                	je     0x714d2f
  714d24:	8b cf                	mov    ecx,edi
  714d26:	e8 85 08 00 00       	call   0x7155b0
  714d2b:	85 c0                	test   eax,eax
  714d2d:	75 d8                	jne    0x714d07
  714d2f:	6a 01                	push   0x1
  714d31:	57                   	push   edi
  714d32:	8d 4e 08             	lea    ecx,[esi+0x8]
  714d35:	e8 16 ff ff ff       	call   0x714c50
  714d3a:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  714d3d:	5e                   	pop    esi
  714d3e:	5f                   	pop    edi
  714d3f:	33 cd                	xor    ecx,ebp
  714d41:	5b                   	pop    ebx
  714d42:	e8 ba c2 17 00       	call   0x891001
  714d47:	8b e5                	mov    esp,ebp
  714d49:	5d                   	pop    ebp
  714d4a:	c2 08 00             	ret    0x8

; game: loader/member-loaded-flag 0x7155b0..0x715612 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

007155b0 <.data>:
  7155b0:	53                   	push   ebx
  7155b1:	56                   	push   esi
  7155b2:	8b f0                	mov    esi,eax
  7155b4:	8b 06                	mov    eax,DWORD PTR [esi]
  7155b6:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7155b9:	51                   	push   ecx
  7155ba:	8b ce                	mov    ecx,esi
  7155bc:	ff d2                	call   edx
  7155be:	8b d8                	mov    ebx,eax
  7155c0:	85 db                	test   ebx,ebx
  7155c2:	74 49                	je     0x71560d
  7155c4:	8b 03                	mov    eax,DWORD PTR [ebx]
  7155c6:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7155c9:	8b cb                	mov    ecx,ebx
  7155cb:	ff d2                	call   edx
  7155cd:	85 c0                	test   eax,eax
  7155cf:	75 3c                	jne    0x71560d
  7155d1:	8b b6 38 01 00 00    	mov    esi,DWORD PTR [esi+0x138]
  7155d7:	8b 4e 2c             	mov    ecx,DWORD PTR [esi+0x2c]
  7155da:	85 c9                	test   ecx,ecx
  7155dc:	74 12                	je     0x7155f0
  7155de:	8b 9b 1c 01 00 00    	mov    ebx,DWORD PTR [ebx+0x11c]
  7155e4:	3b 59 44             	cmp    ebx,DWORD PTR [ecx+0x44]
  7155e7:	74 0e                	je     0x7155f7
  7155e9:	8b 49 28             	mov    ecx,DWORD PTR [ecx+0x28]
  7155ec:	85 c9                	test   ecx,ecx
  7155ee:	75 f4                	jne    0x7155e4
  7155f0:	33 db                	xor    ebx,ebx
  7155f2:	5e                   	pop    esi
  7155f3:	8b c3                	mov    eax,ebx
  7155f5:	5b                   	pop    ebx
  7155f6:	c3                   	ret
  7155f7:	83 79 08 00          	cmp    DWORD PTR [ecx+0x8],0x0
  7155fb:	8b d9                	mov    ebx,ecx
  7155fd:	75 09                	jne    0x715608
  7155ff:	57                   	push   edi
  715600:	8b fe                	mov    edi,esi
  715602:	e8 99 30 00 00       	call   0x7186a0
  715607:	5f                   	pop    edi
  715608:	5e                   	pop    esi
  715609:	8b c3                	mov    eax,ebx
  71560b:	5b                   	pop    ebx
  71560c:	c3                   	ret
  71560d:	5e                   	pop    esi
  71560e:	33 c0                	xor    eax,eax
  715610:	5b                   	pop    ebx
  715611:	c3                   	ret

; game: loader/member-materialize 0x7186a0..0x7187bc (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

007186a0 <.data>:
  7186a0:	55                   	push   ebp
  7186a1:	8b ec                	mov    ebp,esp
  7186a3:	6a ff                	push   0xffffffff
  7186a5:	68 58 5b 90 00       	push   0x905b58
  7186aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7186b0:	50                   	push   eax
  7186b1:	83 ec 08             	sub    esp,0x8
  7186b4:	53                   	push   ebx
  7186b5:	56                   	push   esi
  7186b6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7186bb:	33 c5                	xor    eax,ebp
  7186bd:	50                   	push   eax
  7186be:	8d 45 f4             	lea    eax,[ebp-0xc]
  7186c1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7186c7:	8b f1                	mov    esi,ecx
  7186c9:	8b 1f                	mov    ebx,DWORD PTR [edi]
  7186cb:	53                   	push   ebx
  7186cc:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  7186cf:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7186d5:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7186dc:	85 f6                	test   esi,esi
  7186de:	0f 84 c0 00 00 00    	je     0x7187a4
  7186e4:	8d 46 2c             	lea    eax,[esi+0x2c]
  7186e7:	50                   	push   eax
  7186e8:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7186eb:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7186f1:	83 7e 08 00          	cmp    DWORD PTR [esi+0x8],0x0
  7186f5:	74 20                	je     0x718717
  7186f7:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  7186fa:	8b 35 48 22 bd 00    	mov    esi,DWORD PTR ds:0xbd2248
  718700:	50                   	push   eax
  718701:	ff d6                	call   esi
  718703:	53                   	push   ebx
  718704:	ff d6                	call   esi
  718706:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  718709:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  718710:	59                   	pop    ecx
  718711:	5e                   	pop    esi
  718712:	5b                   	pop    ebx
  718713:	8b e5                	mov    esp,ebp
  718715:	5d                   	pop    ebp
  718716:	c3                   	ret
  718717:	8b c7                	mov    eax,edi
  718719:	e8 92 05 00 00       	call   0x718cb0
  71871e:	8b 06                	mov    eax,DWORD PTR [esi]
  718720:	8b 4f 24             	mov    ecx,DWORD PTR [edi+0x24]
  718723:	8b 11                	mov    edx,DWORD PTR [ecx]
  718725:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  718728:	c1 e0 0a             	shl    eax,0xa
  71872b:	6a 00                	push   0x0
  71872d:	83 c0 10             	add    eax,0x10
  718730:	50                   	push   eax
  718731:	ff d2                	call   edx
  718733:	83 7f 40 00          	cmp    DWORD PTR [edi+0x40],0x0
  718737:	8b 46 4c             	mov    eax,DWORD PTR [esi+0x4c]
  71873a:	50                   	push   eax
  71873b:	74 27                	je     0x718764
  71873d:	e8 fb 54 16 00       	call   0x87dc3d
  718742:	8b 4f 24             	mov    ecx,DWORD PTR [edi+0x24]
  718745:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  718748:	8b 12                	mov    edx,DWORD PTR [edx]
  71874a:	8b d8                	mov    ebx,eax
  71874c:	8b 46 4c             	mov    eax,DWORD PTR [esi+0x4c]
  71874f:	83 c4 04             	add    esp,0x4
  718752:	83 c1 04             	add    ecx,0x4
  718755:	50                   	push   eax
  718756:	53                   	push   ebx
  718757:	ff d2                	call   edx
  718759:	53                   	push   ebx
  71875a:	e8 de 95 17 00       	call   0x891d3d
  71875f:	83 c4 04             	add    esp,0x4
  718762:	eb 1d                	jmp    0x718781
  718764:	e8 d4 54 16 00       	call   0x87dc3d
  718769:	8b 5e 4c             	mov    ebx,DWORD PTR [esi+0x4c]
  71876c:	89 46 48             	mov    DWORD PTR [esi+0x48],eax
  71876f:	8b 4f 24             	mov    ecx,DWORD PTR [edi+0x24]
  718772:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  718775:	83 c4 04             	add    esp,0x4
  718778:	83 c1 04             	add    ecx,0x4
  71877b:	53                   	push   ebx
  71877c:	50                   	push   eax
  71877d:	8b 02                	mov    eax,DWORD PTR [edx]
  71877f:	ff d0                	call   eax
  718781:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  718784:	b8 01 00 00 00       	mov    eax,0x1
  718789:	51                   	push   ecx
  71878a:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  71878d:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  718790:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  718796:	8b 4f 24             	mov    ecx,DWORD PTR [edi+0x24]
  718799:	8b 11                	mov    edx,DWORD PTR [ecx]
  71879b:	8b 02                	mov    eax,DWORD PTR [edx]
  71879d:	6a 00                	push   0x0
  71879f:	ff d0                	call   eax
  7187a1:	8b 5d ec             	mov    ebx,DWORD PTR [ebp-0x14]
  7187a4:	53                   	push   ebx
  7187a5:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7187ab:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7187ae:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7187b5:	59                   	pop    ecx
  7187b6:	5e                   	pop    esi
  7187b7:	5b                   	pop    ebx
  7187b8:	8b e5                	mov    esp,ebp
  7187ba:	5d                   	pop    ebp
  7187bb:	c3                   	ret

; game: loader/member-buffer-release 0x717ae0..0x717b11 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00717ae0 <.data>:
  717ae0:	83 7e 24 00          	cmp    DWORD PTR [esi+0x24],0x0
  717ae4:	75 2a                	jne    0x717b10
  717ae6:	83 7e 08 00          	cmp    DWORD PTR [esi+0x8],0x0
  717aea:	74 24                	je     0x717b10
  717aec:	83 7e 0c 00          	cmp    DWORD PTR [esi+0xc],0x0
  717af0:	c7 46 08 00 00 00 00 	mov    DWORD PTR [esi+0x8],0x0
  717af7:	74 17                	je     0x717b10
  717af9:	8b 46 48             	mov    eax,DWORD PTR [esi+0x48]
  717afc:	85 c0                	test   eax,eax
  717afe:	74 10                	je     0x717b10
  717b00:	50                   	push   eax
  717b01:	e8 37 a2 17 00       	call   0x891d3d
  717b06:	83 c4 04             	add    esp,0x4
  717b09:	c7 46 48 00 00 00 00 	mov    DWORD PTR [esi+0x48],0x0
  717b10:	c3                   	ret

; game: loader/script-read-copy-compile 0x6f4a50..0x6f4c18 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

006f4a50 <.data>:
  6f4a50:	55                   	push   ebp
  6f4a51:	8b ec                	mov    ebp,esp
  6f4a53:	83 e4 f8             	and    esp,0xfffffff8
  6f4a56:	81 ec 2c 02 00 00    	sub    esp,0x22c
  6f4a5c:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6f4a61:	33 c4                	xor    eax,esp
  6f4a63:	89 84 24 28 02 00 00 	mov    DWORD PTR [esp+0x228],eax
  6f4a6a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4a6d:	53                   	push   ebx
  6f4a6e:	56                   	push   esi
  6f4a6f:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  6f4a73:	57                   	push   edi
  6f4a74:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  6f4a78:	2b d0                	sub    edx,eax
  6f4a7a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  6f4a80:	8a 08                	mov    cl,BYTE PTR [eax]
  6f4a82:	88 0c 02             	mov    BYTE PTR [edx+eax*1],cl
  6f4a85:	40                   	inc    eax
  6f4a86:	84 c9                	test   cl,cl
  6f4a88:	75 f6                	jne    0x6f4a80
  6f4a8a:	8d 54 24 30          	lea    edx,[esp+0x30]
  6f4a8e:	68 e0 d1 be 00       	push   0xbed1e0
  6f4a93:	52                   	push   edx
  6f4a94:	be 01 00 00 00       	mov    esi,0x1
  6f4a99:	e8 d2 fc 01 00       	call   0x714770
  6f4a9e:	8b f8                	mov    edi,eax
  6f4aa0:	83 c4 08             	add    esp,0x8
  6f4aa3:	85 ff                	test   edi,edi
  6f4aa5:	0f 84 24 01 00 00    	je     0x6f4bcf
  6f4aab:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4aad:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  6f4ab0:	8b cf                	mov    ecx,edi
  6f4ab2:	ff d2                	call   edx
  6f4ab4:	8b f0                	mov    esi,eax
  6f4ab6:	8d 46 01             	lea    eax,[esi+0x1]
  6f4ab9:	50                   	push   eax
  6f4aba:	e8 7e 91 18 00       	call   0x87dc3d
  6f4abf:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4ac1:	83 c4 04             	add    esp,0x4
  6f4ac4:	8b d8                	mov    ebx,eax
  6f4ac6:	8b 42 38             	mov    eax,DWORD PTR [edx+0x38]
  6f4ac9:	56                   	push   esi
  6f4aca:	8b cf                	mov    ecx,edi
  6f4acc:	ff d0                	call   eax
  6f4ace:	50                   	push   eax
  6f4acf:	53                   	push   ebx
  6f4ad0:	e8 fb 90 1a 00       	call   0x89dbd0
  6f4ad5:	c6 04 1e 00          	mov    BYTE PTR [esi+ebx*1],0x0
  6f4ad9:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4adb:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  6f4ade:	83 c4 0c             	add    esp,0xc
  6f4ae1:	8b cf                	mov    ecx,edi
  6f4ae3:	ff d0                	call   eax
  6f4ae5:	83 f8 03             	cmp    eax,0x3
  6f4ae8:	72 48                	jb     0x6f4b32
  6f4aea:	80 3b ef             	cmp    BYTE PTR [ebx],0xef
  6f4aed:	75 43                	jne    0x6f4b32
  6f4aef:	80 7b 01 bb          	cmp    BYTE PTR [ebx+0x1],0xbb
  6f4af3:	75 3d                	jne    0x6f4b32
  6f4af5:	80 7b 02 bf          	cmp    BYTE PTR [ebx+0x2],0xbf
  6f4af9:	75 37                	jne    0x6f4b32
  6f4afb:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  6f4aff:	8b 16                	mov    edx,DWORD PTR [esi]
  6f4b01:	83 c0 fd             	add    eax,0xfffffffd
  6f4b04:	50                   	push   eax
  6f4b05:	8d 4b 03             	lea    ecx,[ebx+0x3]
  6f4b08:	51                   	push   ecx
  6f4b09:	33 c0                	xor    eax,eax
  6f4b0b:	e8 00 26 00 00       	call   0x6f7110
  6f4b10:	83 c4 08             	add    esp,0x8
  6f4b13:	85 c0                	test   eax,eax
  6f4b15:	0f 85 9d 00 00 00    	jne    0x6f4bb8
  6f4b1b:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4b1d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4b20:	83 e8 10             	sub    eax,0x10
  6f4b23:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4b27:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4b2a:	8d 54 24 10          	lea    edx,[esp+0x10]
  6f4b2e:	50                   	push   eax
  6f4b2f:	52                   	push   edx
  6f4b30:	eb 57                	jmp    0x6f4b89
  6f4b32:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  6f4b36:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6f4b38:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6f4b3c:	8d 44 24 10          	lea    eax,[esp+0x10]
  6f4b40:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6f4b44:	33 c0                	xor    eax,eax
  6f4b46:	89 4c 24 2c          	mov    DWORD PTR [esp+0x2c],ecx
  6f4b4a:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  6f4b4e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  6f4b52:	51                   	push   ecx
  6f4b53:	b9 00 27 c4 00       	mov    ecx,0xc42700
  6f4b58:	8d 44 24 20          	lea    eax,[esp+0x20]
  6f4b5c:	89 5c 24 14          	mov    DWORD PTR [esp+0x14],ebx
  6f4b60:	c7 44 24 28 e0 70 6f 	mov    DWORD PTR [esp+0x28],0x6f70e0
  6f4b67:	00 
  6f4b68:	e8 23 9e 00 00       	call   0x6fe990
  6f4b6d:	83 c4 04             	add    esp,0x4
  6f4b70:	85 c0                	test   eax,eax
  6f4b72:	75 44                	jne    0x6f4bb8
  6f4b74:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4b76:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4b79:	83 e8 10             	sub    eax,0x10
  6f4b7c:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4b80:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4b83:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  6f4b87:	50                   	push   eax
  6f4b88:	51                   	push   ecx
  6f4b89:	68 50 5a 6f 00       	push   0x6f5a50
  6f4b8e:	33 d2                	xor    edx,edx
  6f4b90:	8b c6                	mov    eax,esi
  6f4b92:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  6f4b99:	ff 
  6f4b9a:	e8 d1 9b 00 00       	call   0x6fe770
  6f4b9f:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4ba2:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  6f4ba5:	83 c4 0c             	add    esp,0xc
  6f4ba8:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4bab:	72 03                	jb     0x6f4bb0
  6f4bad:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6f4bb0:	85 c0                	test   eax,eax
  6f4bb2:	75 04                	jne    0x6f4bb8
  6f4bb4:	33 f6                	xor    esi,esi
  6f4bb6:	eb 05                	jmp    0x6f4bbd
  6f4bb8:	be 01 00 00 00       	mov    esi,0x1
  6f4bbd:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4bbf:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  6f4bc2:	8b cf                	mov    ecx,edi
  6f4bc4:	ff d0                	call   eax
  6f4bc6:	53                   	push   ebx
  6f4bc7:	e8 71 d1 19 00       	call   0x891d3d
  6f4bcc:	83 c4 04             	add    esp,0x4
  6f4bcf:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  6f4bd3:	51                   	push   ecx
  6f4bd4:	8d 94 24 34 01 00 00 	lea    edx,[esp+0x134]
  6f4bdb:	68 9c 26 c4 00       	push   0xc4269c
  6f4be0:	52                   	push   edx
  6f4be1:	e8 49 df 19 00       	call   0x892b2f
  6f4be6:	83 c4 0c             	add    esp,0xc
  6f4be9:	85 f6                	test   esi,esi
  6f4beb:	74 12                	je     0x6f4bff
  6f4bed:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  6f4bf1:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  6f4bf8:	50                   	push   eax
  6f4bf9:	51                   	push   ecx
  6f4bfa:	e8 a1 fb ff ff       	call   0x6f47a0
  6f4bff:	8b 8c 24 34 02 00 00 	mov    ecx,DWORD PTR [esp+0x234]
  6f4c06:	5f                   	pop    edi
  6f4c07:	8b c6                	mov    eax,esi
  6f4c09:	5e                   	pop    esi
  6f4c0a:	5b                   	pop    ebx
  6f4c0b:	33 cc                	xor    ecx,esp
  6f4c0d:	e8 ef c3 19 00       	call   0x891001
  6f4c12:	8b e5                	mov    esp,ebp
  6f4c14:	5d                   	pop    ebp
  6f4c15:	c2 04 00             	ret    0x4

; game: loader/scene-manager-init 0x560170..0x56041a (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00560170 <.data>:
  560170:	55                   	push   ebp
  560171:	8b ec                	mov    ebp,esp
  560173:	6a ff                	push   0xffffffff
  560175:	68 c8 ad 93 00       	push   0x93adc8
  56017a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  560180:	50                   	push   eax
  560181:	83 ec 38             	sub    esp,0x38
  560184:	53                   	push   ebx
  560185:	56                   	push   esi
  560186:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56018b:	33 c5                	xor    eax,ebp
  56018d:	50                   	push   eax
  56018e:	8d 45 f4             	lea    eax,[ebp-0xc]
  560191:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  560197:	33 db                	xor    ebx,ebx
  560199:	6a 34                	push   0x34
  56019b:	c7 45 e4 c0 73 fb 00 	mov    DWORD PTR [ebp-0x1c],0xfb73c0
  5601a2:	89 1d c0 73 fb 00    	mov    DWORD PTR ds:0xfb73c0,ebx
  5601a8:	89 1d c4 73 fb 00    	mov    DWORD PTR ds:0xfb73c4,ebx
  5601ae:	89 1d d0 73 fb 00    	mov    DWORD PTR ds:0xfb73d0,ebx
  5601b4:	e8 af 10 33 00       	call   0x891268
  5601b9:	83 c4 04             	add    esp,0x4
  5601bc:	3b c3                	cmp    eax,ebx
  5601be:	0f 84 32 02 00 00    	je     0x5603f6
  5601c4:	a3 cc 73 fb 00       	mov    ds:0xfb73cc,eax
  5601c9:	89 00                	mov    DWORD PTR [eax],eax
  5601cb:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  5601d3:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601d8:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  5601db:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601e0:	c6 40 30 01          	mov    BYTE PTR [eax+0x30],0x1
  5601e4:	8b 0d cc 73 fb 00    	mov    ecx,DWORD PTR ds:0xfb73cc
  5601ea:	c6 41 31 01          	mov    BYTE PTR [ecx+0x31],0x1
  5601ee:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  5601f1:	6a 18                	push   0x18
  5601f3:	89 1d e0 73 fb 00    	mov    DWORD PTR ds:0xfb73e0,ebx
  5601f9:	e8 6a 10 33 00       	call   0x891268
  5601fe:	83 c4 04             	add    esp,0x4
  560201:	3b c3                	cmp    eax,ebx
  560203:	0f 84 c9 01 00 00    	je     0x5603d2
  560209:	a3 dc 73 fb 00       	mov    ds:0xfb73dc,eax
  56020e:	89 00                	mov    DWORD PTR [eax],eax
  560210:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  560215:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  560218:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  56021d:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  560220:	8b 15 dc 73 fb 00    	mov    edx,DWORD PTR ds:0xfb73dc
  560226:	c6 42 14 01          	mov    BYTE PTR [edx+0x14],0x1
  56022a:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  56022f:	c6 40 15 01          	mov    BYTE PTR [eax+0x15],0x1
  560233:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  560237:	6a 48                	push   0x48
  560239:	89 1d e8 73 fb 00    	mov    DWORD PTR ds:0xfb73e8,ebx
  56023f:	89 1d ec 73 fb 00    	mov    DWORD PTR ds:0xfb73ec,ebx
  560245:	e8 1e 10 33 00       	call   0x891268
  56024a:	83 c4 04             	add    esp,0x4
  56024d:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  560250:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  560254:	3b c3                	cmp    eax,ebx
  560256:	74 09                	je     0x560261
  560258:	8b f0                	mov    esi,eax
  56025a:	e8 51 d0 26 00       	call   0x7cd2b0
  56025f:	eb 02                	jmp    0x560263
  560261:	33 c0                	xor    eax,eax
  560263:	a3 f0 73 fb 00       	mov    ds:0xfb73f0,eax
  560268:	89 1d f8 73 fb 00    	mov    DWORD PTR ds:0xfb73f8,ebx
  56026e:	89 1d fc 73 fb 00    	mov    DWORD PTR ds:0xfb73fc,ebx
  560274:	c7 05 00 74 fb 00 ff 	mov    DWORD PTR ds:0xfb7400,0xffffffff
  56027b:	ff ff ff 
  56027e:	c7 05 18 74 fb 00 0f 	mov    DWORD PTR ds:0xfb7418,0xf
  560285:	00 00 00 
  560288:	89 1d 14 74 fb 00    	mov    DWORD PTR ds:0xfb7414,ebx
  56028e:	88 1d 04 74 fb 00    	mov    BYTE PTR ds:0xfb7404,bl
  560294:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  560298:	6a 14                	push   0x14
  56029a:	89 1d 28 74 fb 00    	mov    DWORD PTR ds:0xfb7428,ebx
  5602a0:	e8 c3 0f 33 00       	call   0x891268
  5602a5:	83 c4 04             	add    esp,0x4
  5602a8:	3b c3                	cmp    eax,ebx
  5602aa:	0f 84 fe 00 00 00    	je     0x5603ae
  5602b0:	a3 24 74 fb 00       	mov    ds:0xfb7424,eax
  5602b5:	89 00                	mov    DWORD PTR [eax],eax
  5602b7:	a1 24 74 fb 00       	mov    eax,ds:0xfb7424
  5602bc:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  5602bf:	a1 24 74 fb 00       	mov    eax,ds:0xfb7424
  5602c4:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  5602c7:	8b 0d 24 74 fb 00    	mov    ecx,DWORD PTR ds:0xfb7424
  5602cd:	c6 41 10 01          	mov    BYTE PTR [ecx+0x10],0x1
  5602d1:	8b 15 24 74 fb 00    	mov    edx,DWORD PTR ds:0xfb7424
  5602d7:	c6 42 11 01          	mov    BYTE PTR [edx+0x11],0x1
  5602db:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  5602df:	6a 14                	push   0x14
  5602e1:	89 1d 30 74 fb 00    	mov    DWORD PTR ds:0xfb7430,ebx
  5602e7:	89 1d 3c 74 fb 00    	mov    DWORD PTR ds:0xfb743c,ebx
  5602ed:	e8 76 0f 33 00       	call   0x891268
  5602f2:	83 c4 04             	add    esp,0x4
  5602f5:	3b c3                	cmp    eax,ebx
  5602f7:	0f 84 8d 00 00 00    	je     0x56038a
  5602fd:	a3 38 74 fb 00       	mov    ds:0xfb7438,eax
  560302:	89 00                	mov    DWORD PTR [eax],eax
  560304:	a1 38 74 fb 00       	mov    eax,ds:0xfb7438
  560309:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  56030c:	a1 38 74 fb 00       	mov    eax,ds:0xfb7438
  560311:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  560314:	a1 38 74 fb 00       	mov    eax,ds:0xfb7438
  560319:	c6 40 10 01          	mov    BYTE PTR [eax+0x10],0x1
  56031d:	8b 0d 38 74 fb 00    	mov    ecx,DWORD PTR ds:0xfb7438
  560323:	c6 41 11 01          	mov    BYTE PTR [ecx+0x11],0x1
  560327:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  56032b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  560332:	00 
  560333:	f3 0f 11 05 44 74 fb 	movss  DWORD PTR ds:0xfb7444,xmm0
  56033a:	00 
  56033b:	66 c7 05 48 74 fb 00 	mov    WORD PTR ds:0xfb7448,0x1
  560342:	01 00 
  560344:	e8 87 04 00 00       	call   0x5607d0
  560349:	e8 f2 20 00 00       	call   0x562440
  56034e:	f6 05 40 27 fe 00 01 	test   BYTE PTR ds:0xfe2740,0x1
  560355:	75 1d                	jne    0x560374
  560357:	83 0d 40 27 fe 00 01 	or     DWORD PTR ds:0xfe2740,0x1
  56035e:	c6 45 fc 06          	mov    BYTE PTR [ebp-0x4],0x6
  560362:	e8 19 e3 ff ff       	call   0x55e680
  560367:	68 a0 f2 bc 00       	push   0xbcf2a0
  56036c:	e8 a9 1f 33 00       	call   0x89231a
  560371:	83 c4 04             	add    esp,0x4
  560374:	b8 c0 73 fb 00       	mov    eax,0xfb73c0
  560379:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  56037c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  560383:	59                   	pop    ecx
  560384:	5e                   	pop    esi
  560385:	5b                   	pop    ebx
  560386:	8b e5                	mov    esp,ebp
  560388:	5d                   	pop    ebp
  560389:	c3                   	ret
  56038a:	8d 55 f0             	lea    edx,[ebp-0x10]
  56038d:	52                   	push   edx
  56038e:	8d 4d d8             	lea    ecx,[ebp-0x28]
  560391:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  560394:	e8 10 0d 33 00       	call   0x8910a9
  560399:	68 a8 57 c8 00       	push   0xc857a8
  56039e:	8d 45 d8             	lea    eax,[ebp-0x28]
  5603a1:	50                   	push   eax
  5603a2:	c7 45 d8 a4 2c bd 00 	mov    DWORD PTR [ebp-0x28],0xbd2ca4
  5603a9:	e8 42 c6 33 00       	call   0x89c9f0
  5603ae:	8d 4d ec             	lea    ecx,[ebp-0x14]
  5603b1:	51                   	push   ecx
  5603b2:	8d 4d cc             	lea    ecx,[ebp-0x34]
  5603b5:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  5603b8:	e8 ec 0c 33 00       	call   0x8910a9
  5603bd:	68 a8 57 c8 00       	push   0xc857a8
  5603c2:	8d 55 cc             	lea    edx,[ebp-0x34]
  5603c5:	52                   	push   edx
  5603c6:	c7 45 cc a4 2c bd 00 	mov    DWORD PTR [ebp-0x34],0xbd2ca4
  5603cd:	e8 1e c6 33 00       	call   0x89c9f0
  5603d2:	8d 45 ec             	lea    eax,[ebp-0x14]
  5603d5:	50                   	push   eax
  5603d6:	8d 4d cc             	lea    ecx,[ebp-0x34]
  5603d9:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  5603dc:	e8 c8 0c 33 00       	call   0x8910a9
  5603e1:	68 a8 57 c8 00       	push   0xc857a8
  5603e6:	8d 4d cc             	lea    ecx,[ebp-0x34]
  5603e9:	51                   	push   ecx
  5603ea:	c7 45 cc a4 2c bd 00 	mov    DWORD PTR [ebp-0x34],0xbd2ca4
  5603f1:	e8 fa c5 33 00       	call   0x89c9f0
  5603f6:	8d 55 e8             	lea    edx,[ebp-0x18]
  5603f9:	52                   	push   edx
  5603fa:	8d 4d c0             	lea    ecx,[ebp-0x40]
  5603fd:	89 5d e8             	mov    DWORD PTR [ebp-0x18],ebx
  560400:	e8 a4 0c 33 00       	call   0x8910a9
  560405:	68 a8 57 c8 00       	push   0xc857a8
  56040a:	8d 45 c0             	lea    eax,[ebp-0x40]
  56040d:	50                   	push   eax
  56040e:	c7 45 c0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x40],0xbd2ca4
  560415:	e8 d6 c5 33 00       	call   0x89c9f0

; game: loader/scene-key-map-load 0x5607d0..0x560a99 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

005607d0 <.data>:
  5607d0:	55                   	push   ebp
  5607d1:	8b ec                	mov    ebp,esp
  5607d3:	83 e4 f8             	and    esp,0xfffffff8
  5607d6:	6a ff                	push   0xffffffff
  5607d8:	68 71 2f 92 00       	push   0x922f71
  5607dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5607e3:	50                   	push   eax
  5607e4:	81 ec d8 00 00 00    	sub    esp,0xd8
  5607ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5607ef:	33 c4                	xor    eax,esp
  5607f1:	89 84 24 d0 00 00 00 	mov    DWORD PTR [esp+0xd0],eax
  5607f8:	53                   	push   ebx
  5607f9:	56                   	push   esi
  5607fa:	57                   	push   edi
  5607fb:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  560800:	33 c4                	xor    eax,esp
  560802:	50                   	push   eax
  560803:	8d 84 24 e8 00 00 00 	lea    eax,[esp+0xe8]
  56080a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  560810:	8d 44 24 64          	lea    eax,[esp+0x64]
  560814:	50                   	push   eax
  560815:	b9 68 06 c1 00       	mov    ecx,0xc10668
  56081a:	e8 11 e6 1c 00       	call   0x72ee30
  56081f:	33 db                	xor    ebx,ebx
  560821:	89 9c 24 f0 00 00 00 	mov    DWORD PTR [esp+0xf0],ebx
  560828:	83 bc 24 98 00 00 00 	cmp    DWORD PTR [esp+0x98],0x10
  56082f:	10 
  560830:	8b 8c 24 84 00 00 00 	mov    ecx,DWORD PTR [esp+0x84]
  560837:	73 07                	jae    0x560840
  560839:	8d 8c 24 84 00 00 00 	lea    ecx,[esp+0x84]
  560840:	53                   	push   ebx
  560841:	8d 74 24 68          	lea    esi,[esp+0x68]
  560845:	e8 c6 e8 1c 00       	call   0x72f110
  56084a:	84 c0                	test   al,al
  56084c:	0f 84 d4 01 00 00    	je     0x560a26
  560852:	8b 0d cc 73 fb 00    	mov    ecx,DWORD PTR ds:0xfb73cc
  560858:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  56085b:	52                   	push   edx
  56085c:	b9 c8 73 fb 00       	mov    ecx,0xfb73c8
  560861:	e8 2a 52 00 00       	call   0x565a90
  560866:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  56086b:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  56086e:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  560873:	89 00                	mov    DWORD PTR [eax],eax
  560875:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  56087a:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  56087d:	68 7c 06 c1 00       	push   0xc1067c
  560882:	8b c6                	mov    eax,esi
  560884:	89 1d d0 73 fb 00    	mov    DWORD PTR ds:0xfb73d0,ebx
  56088a:	e8 51 da 1c 00       	call   0x72e2e0
  56088f:	3b c3                	cmp    eax,ebx
  560891:	0f 84 8f 01 00 00    	je     0x560a26
  560897:	68 8c 33 c0 00       	push   0xc0338c
  56089c:	e8 3f da 1c 00       	call   0x72e2e0
  5608a1:	8b f0                	mov    esi,eax
  5608a3:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5608a7:	3b f3                	cmp    esi,ebx
  5608a9:	0f 84 77 01 00 00    	je     0x560a26
  5608af:	eb 04                	jmp    0x5608b5
  5608b1:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  5608b5:	8b 06                	mov    eax,DWORD PTR [esi]
  5608b7:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  5608ba:	8b ce                	mov    ecx,esi
  5608bc:	ff d2                	call   edx
  5608be:	3b c3                	cmp    eax,ebx
  5608c0:	0f 84 51 01 00 00    	je     0x560a17
  5608c6:	c7 44 24 38 0f 00 00 	mov    DWORD PTR [esp+0x38],0xf
  5608cd:	00 
  5608ce:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  5608d2:	88 5c 24 24          	mov    BYTE PTR [esp+0x24],bl
  5608d6:	8d 78 44             	lea    edi,[eax+0x44]
  5608d9:	68 88 06 c1 00       	push   0xc10688
  5608de:	c6 84 24 f4 00 00 00 	mov    BYTE PTR [esp+0xf4],0x1
  5608e5:	01 
  5608e6:	e8 b5 f7 1c 00       	call   0x7300a0
  5608eb:	3b c3                	cmp    eax,ebx
  5608ed:	74 1e                	je     0x56090d
  5608ef:	83 c0 30             	add    eax,0x30
  5608f2:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5608f6:	72 02                	jb     0x5608fa
  5608f8:	8b 00                	mov    eax,DWORD PTR [eax]
  5608fa:	3b c3                	cmp    eax,ebx
  5608fc:	74 0f                	je     0x56090d
  5608fe:	50                   	push   eax
  5608ff:	e8 b0 0e 33 00       	call   0x8917b4
  560904:	83 c4 04             	add    esp,0x4
  560907:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  56090b:	eb 04                	jmp    0x560911
  56090d:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  560911:	68 94 33 c0 00       	push   0xc03394
  560916:	e8 85 f7 1c 00       	call   0x7300a0
  56091b:	3b c3                	cmp    eax,ebx
  56091d:	74 1c                	je     0x56093b
  56091f:	83 c0 30             	add    eax,0x30
  560922:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  560926:	72 02                	jb     0x56092a
  560928:	8b 00                	mov    eax,DWORD PTR [eax]
  56092a:	3b c3                	cmp    eax,ebx
  56092c:	74 0d                	je     0x56093b
  56092e:	50                   	push   eax
  56092f:	e8 80 0e 33 00       	call   0x8917b4
  560934:	83 c4 04             	add    esp,0x4
  560937:	8b f0                	mov    esi,eax
  560939:	eb 02                	jmp    0x56093d
  56093b:	33 f6                	xor    esi,esi
  56093d:	68 94 06 c1 00       	push   0xc10694
  560942:	e8 59 f7 1c 00       	call   0x7300a0
  560947:	3b c3                	cmp    eax,ebx
  560949:	74 0d                	je     0x560958
  56094b:	83 78 44 10          	cmp    DWORD PTR [eax+0x44],0x10
  56094f:	8d 48 30             	lea    ecx,[eax+0x30]
  560952:	72 06                	jb     0x56095a
  560954:	8b 09                	mov    ecx,DWORD PTR [ecx]
  560956:	eb 02                	jmp    0x56095a
  560958:	33 c9                	xor    ecx,ecx
  56095a:	8b c1                	mov    eax,ecx
  56095c:	8d 78 01             	lea    edi,[eax+0x1]
  56095f:	90                   	nop
  560960:	8a 10                	mov    dl,BYTE PTR [eax]
  560962:	40                   	inc    eax
  560963:	3a d3                	cmp    dl,bl
  560965:	75 f9                	jne    0x560960
  560967:	2b c7                	sub    eax,edi
  560969:	50                   	push   eax
  56096a:	51                   	push   ecx
  56096b:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  56096f:	e8 fc 20 ea ff       	call   0x402a70
  560974:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  560978:	6a ff                	push   0xffffffff
  56097a:	53                   	push   ebx
  56097b:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  56097f:	51                   	push   ecx
  560980:	bf 0f 00 00 00       	mov    edi,0xf
  560985:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  560989:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  56098d:	89 74 24 50          	mov    DWORD PTR [esp+0x50],esi
  560991:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  560995:	89 5c 24 64          	mov    DWORD PTR [esp+0x64],ebx
  560999:	88 5c 24 54          	mov    BYTE PTR [esp+0x54],bl
  56099d:	e8 9e 26 ea ff       	call   0x403040
  5609a2:	68 c8 73 fb 00       	push   0xfb73c8
  5609a7:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5609ab:	c6 84 24 f4 00 00 00 	mov    BYTE PTR [esp+0xf4],0x2
  5609b2:	02 
  5609b3:	e8 98 7f 00 00       	call   0x568950
  5609b8:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  5609bc:	52                   	push   edx
  5609bd:	68 c8 73 fb 00       	push   0xfb73c8
  5609c2:	8b f0                	mov    esi,eax
  5609c4:	e8 b7 7c 00 00       	call   0x568680
  5609c9:	be 10 00 00 00       	mov    esi,0x10
  5609ce:	39 74 24 5c          	cmp    DWORD PTR [esp+0x5c],esi
  5609d2:	72 0d                	jb     0x5609e1
  5609d4:	8b 44 24 48          	mov    eax,DWORD PTR [esp+0x48]
  5609d8:	50                   	push   eax
  5609d9:	e8 2e 08 33 00       	call   0x89120c
  5609de:	83 c4 04             	add    esp,0x4
  5609e1:	88 9c 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],bl
  5609e8:	89 7c 24 5c          	mov    DWORD PTR [esp+0x5c],edi
  5609ec:	89 5c 24 58          	mov    DWORD PTR [esp+0x58],ebx
  5609f0:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  5609f4:	39 74 24 38          	cmp    DWORD PTR [esp+0x38],esi
  5609f8:	72 0d                	jb     0x560a07
  5609fa:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  5609fe:	51                   	push   ecx
  5609ff:	e8 08 08 33 00       	call   0x89120c
  560a04:	83 c4 04             	add    esp,0x4
  560a07:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  560a0b:	89 7c 24 38          	mov    DWORD PTR [esp+0x38],edi
  560a0f:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  560a13:	88 5c 24 24          	mov    BYTE PTR [esp+0x24],bl
  560a17:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  560a1a:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  560a1e:	3b f3                	cmp    esi,ebx
  560a20:	0f 85 8b fe ff ff    	jne    0x5608b1
  560a26:	c7 84 24 f0 00 00 00 	mov    DWORD PTR [esp+0xf0],0xffffffff
  560a2d:	ff ff ff ff 
  560a31:	83 bc 24 c4 00 00 00 	cmp    DWORD PTR [esp+0xc4],0x10
  560a38:	10 
  560a39:	c7 44 24 64 94 23 bf 	mov    DWORD PTR [esp+0x64],0xbf2394
  560a40:	00 
  560a41:	72 10                	jb     0x560a53
  560a43:	8b 94 24 b0 00 00 00 	mov    edx,DWORD PTR [esp+0xb0]
  560a4a:	52                   	push   edx
  560a4b:	e8 bc 07 33 00       	call   0x89120c
  560a50:	83 c4 04             	add    esp,0x4
  560a53:	8d 4c 24 64          	lea    ecx,[esp+0x64]
  560a57:	c7 84 24 c4 00 00 00 	mov    DWORD PTR [esp+0xc4],0xf
  560a5e:	0f 00 00 00 
  560a62:	89 9c 24 c0 00 00 00 	mov    DWORD PTR [esp+0xc0],ebx
  560a69:	88 9c 24 b0 00 00 00 	mov    BYTE PTR [esp+0xb0],bl
  560a70:	e8 cb d5 1c 00       	call   0x72e040
  560a75:	8b 8c 24 e8 00 00 00 	mov    ecx,DWORD PTR [esp+0xe8]
  560a7c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  560a83:	59                   	pop    ecx
  560a84:	5f                   	pop    edi
  560a85:	5e                   	pop    esi
  560a86:	5b                   	pop    ebx
  560a87:	8b 8c 24 d0 00 00 00 	mov    ecx,DWORD PTR [esp+0xd0]
  560a8e:	33 cc                	xor    ecx,esp
  560a90:	e8 6c 05 33 00       	call   0x891001
  560a95:	8b e5                	mov    esp,ebp
  560a97:	5d                   	pop    ebp
  560a98:	c3                   	ret

; game: loader/ready-lazy-init 0x4b2570..0x4b2615 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b2570 <.data>:
  4b2570:	55                   	push   ebp
  4b2571:	8b ec                	mov    ebp,esp
  4b2573:	6a ff                	push   0xffffffff
  4b2575:	68 7c b2 93 00       	push   0x93b27c
  4b257a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b2580:	50                   	push   eax
  4b2581:	53                   	push   ebx
  4b2582:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b2587:	33 c5                	xor    eax,ebp
  4b2589:	50                   	push   eax
  4b258a:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b258d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b2593:	a1 a4 a7 fb 00       	mov    eax,ds:0xfba7a4
  4b2598:	bb 01 00 00 00       	mov    ebx,0x1
  4b259d:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  4b25a0:	84 1d b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,bl
  4b25a6:	75 26                	jne    0x4b25ce
  4b25a8:	09 1d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,ebx
  4b25ae:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b25b5:	e8 b6 db 0a 00       	call   0x560170
  4b25ba:	68 10 d1 bc 00       	push   0xbcd110
  4b25bf:	e8 56 fd 3d 00       	call   0x89231a
  4b25c4:	83 c4 04             	add    esp,0x4
  4b25c7:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b25ce:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
  4b25d5:	75 2a                	jne    0x4b2601
  4b25d7:	84 1d 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,bl
  4b25dd:	75 1b                	jne    0x4b25fa
  4b25df:	09 1d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ebx
  4b25e5:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4b25e8:	e8 63 e1 21 00       	call   0x6d0750
  4b25ed:	68 30 d5 bc 00       	push   0xbcd530
  4b25f2:	e8 23 fd 3d 00       	call   0x89231a
  4b25f7:	83 c4 04             	add    esp,0x4
  4b25fa:	83 25 30 88 fb 00 fe 	and    DWORD PTR ds:0xfb8830,0xfffffffe
  4b2601:	33 c0                	xor    eax,eax
  4b2603:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b2606:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b260d:	59                   	pop    ecx
  4b260e:	5b                   	pop    ebx
  4b260f:	8b e5                	mov    esp,ebp
  4b2611:	5d                   	pop    ebp
  4b2612:	c2 0c 00             	ret    0xc

; game: loader/scene-start-gates 0x561760..0x561da0 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00561760 <.data>:
  561760:	55                   	push   ebp
  561761:	8b ec                	mov    ebp,esp
  561763:	83 e4 f8             	and    esp,0xfffffff8
  561766:	6a ff                	push   0xffffffff
  561768:	68 2c fd 93 00       	push   0x93fd2c
  56176d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561773:	50                   	push   eax
  561774:	83 ec 50             	sub    esp,0x50
  561777:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56177c:	33 c4                	xor    eax,esp
  56177e:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  561782:	53                   	push   ebx
  561783:	56                   	push   esi
  561784:	57                   	push   edi
  561785:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56178a:	33 c4                	xor    eax,esp
  56178c:	50                   	push   eax
  56178d:	8d 44 24 60          	lea    eax,[esp+0x60]
  561791:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  561797:	83 3d 18 ab fb 00 00 	cmp    DWORD PTR ds:0xfbab18,0x0
  56179e:	8b d9                	mov    ebx,ecx
  5617a0:	74 20                	je     0x5617c2
  5617a2:	0f 57 c0             	xorps  xmm0,xmm0
  5617a5:	f3 0f 11 05 24 ab fb 	movss  DWORD PTR ds:0xfbab24,xmm0
  5617ac:	00 
  5617ad:	e8 ae d8 ea ff       	call   0x40f060
  5617b2:	f3 0f 10 05 70 59 c5 	movss  xmm0,DWORD PTR ds:0xc55970
  5617b9:	00 
  5617ba:	f3 0f 11 80 ac 00 00 	movss  DWORD PTR [eax+0xac],xmm0
  5617c1:	00 
  5617c2:	83 7b 28 00          	cmp    DWORD PTR [ebx+0x28],0x0
  5617c6:	c6 83 89 00 00 00 00 	mov    BYTE PTR [ebx+0x89],0x0
  5617cd:	74 1a                	je     0x5617e9
  5617cf:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5617d2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5617d5:	50                   	push   eax
  5617d6:	51                   	push   ecx
  5617d7:	68 ac 06 c1 00       	push   0xc106ac
  5617dc:	e8 7f c3 18 00       	call   0x6edb60
  5617e1:	83 c4 0c             	add    esp,0xc
  5617e4:	e9 9d 05 00 00       	jmp    0x561d86
  5617e9:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  5617f0:	be 01 00 00 00       	mov    esi,0x1
  5617f5:	75 29                	jne    0x561820
  5617f7:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  5617fd:	c7 44 24 68 00 00 00 	mov    DWORD PTR [esp+0x68],0x0
  561804:	00 
  561805:	e8 46 e0 fe ff       	call   0x54f850
  56180a:	68 80 d5 bc 00       	push   0xbcd580
  56180f:	e8 06 0b 33 00       	call   0x89231a
  561814:	83 c4 04             	add    esp,0x4
  561817:	83 cf ff             	or     edi,0xffffffff
  56181a:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  56181e:	eb 03                	jmp    0x561823
  561820:	83 cf ff             	or     edi,0xffffffff
  561823:	80 3d f1 92 fb 00 00 	cmp    BYTE PTR ds:0xfb92f1,0x0
  56182a:	0f 84 ac 00 00 00    	je     0x5618dc
  561830:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  561834:	0f 85 a2 00 00 00    	jne    0x5618dc
  56183a:	e8 61 33 ea ff       	call   0x404ba0
  56183f:	83 b8 4c 5f 00 00 09 	cmp    DWORD PTR [eax+0x5f4c],0x9
  561846:	74 1c                	je     0x561864
  561848:	e8 53 33 ea ff       	call   0x404ba0
  56184d:	83 b8 4c 5f 00 00 04 	cmp    DWORD PTR [eax+0x5f4c],0x4
  561854:	74 0e                	je     0x561864
  561856:	e8 45 33 ea ff       	call   0x404ba0
  56185b:	83 b8 4c 5f 00 00 19 	cmp    DWORD PTR [eax+0x5f4c],0x19
  561862:	75 78                	jne    0x5618dc
  561864:	8b 73 78             	mov    esi,DWORD PTR [ebx+0x78]
  561867:	8d 55 0c             	lea    edx,[ebp+0xc]
  56186a:	52                   	push   edx
  56186b:	8d 4b 74             	lea    ecx,[ebx+0x74]
  56186e:	8d 44 24 14          	lea    eax,[esp+0x14]
  561872:	e8 49 4c ed ff       	call   0x4364c0
  561877:	39 30                	cmp    DWORD PTR [eax],esi
  561879:	74 5c                	je     0x5618d7
  56187b:	6a 0f                	push   0xf
  56187d:	e8 2e 3d 02 00       	call   0x5855b0
  561882:	8b f0                	mov    esi,eax
  561884:	e8 a7 3a 02 00       	call   0x585330
  561889:	50                   	push   eax
  56188a:	8d 4c 24 40          	lea    ecx,[esp+0x40]
  56188e:	e8 bd 09 ea ff       	call   0x402250
  561893:	8d 44 24 3c          	lea    eax,[esp+0x3c]
  561897:	50                   	push   eax
  561898:	c7 44 24 6c 01 00 00 	mov    DWORD PTR [esp+0x6c],0x1
  56189f:	00 
  5618a0:	e8 1b e0 ea ff       	call   0x40f8c0
  5618a5:	8b f8                	mov    edi,eax
  5618a7:	e8 84 52 f7 ff       	call   0x4d6b30
  5618ac:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
  5618b0:	c7 44 24 68 ff ff ff 	mov    DWORD PTR [esp+0x68],0xffffffff
  5618b7:	ff 
  5618b8:	e8 83 8b f9 ff       	call   0x4fa440
  5618bd:	e8 be 2d eb ff       	call   0x414680
  5618c2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  5618c5:	51                   	push   ecx
  5618c6:	6a 00                	push   0x0
  5618c8:	e8 d3 20 f4 ff       	call   0x4a39a0
  5618cd:	e8 de 07 00 00       	call   0x5620b0
  5618d2:	e9 af 04 00 00       	jmp    0x561d86
  5618d7:	be 01 00 00 00       	mov    esi,0x1
  5618dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38             	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28             	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                	jne    0x561918
  5618f4:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  5618fa:	c7 44 24 68 02 00 00 	mov    DWORD PTR [esp+0x68],0x2
  561901:	00 
  561902:	e8 79 5b 02 00       	call   0x587480
  561907:	68 c0 cc bc 00       	push   0xbcccc0
  56190c:	e8 09 0a 33 00       	call   0x89231a
  561911:	83 c4 04             	add    esp,0x4
  561914:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561918:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  56191f:	75 24                	jne    0x561945
  561921:	09 35 d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,esi
  561927:	c7 44 24 68 03 00 00 	mov    DWORD PTR [esp+0x68],0x3
  56192e:	00 
  56192f:	e8 5c c0 1e 00       	call   0x74d990
  561934:	68 70 cc bc 00       	push   0xbccc70
  561939:	e8 dc 09 33 00       	call   0x89231a
  56193e:	83 c4 04             	add    esp,0x4
  561941:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561945:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  56194c:	8b 0d bc 5b f9 00    	mov    ecx,DWORD PTR ds:0xf95bbc
  561952:	8b 15 c0 5b f9 00    	mov    edx,DWORD PTR ds:0xf95bc0
  561958:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  56195c:	f3 0f 10 44 24 14    	movss  xmm0,DWORD PTR [esp+0x14]
  561962:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  561966:	f3 0f 11 83 84 00 00 	movss  DWORD PTR [ebx+0x84],xmm0
  56196d:	00 
  56196e:	75 24                	jne    0x561994
  561970:	09 35 90 43 f9 00    	or     DWORD PTR ds:0xf94390,esi
  561976:	c7 44 24 68 04 00 00 	mov    DWORD PTR [esp+0x68],0x4
  56197d:	00 
  56197e:	e8 0d fc f7 ff       	call   0x4e1590
  561983:	68 80 cc bc 00       	push   0xbccc80
  561988:	e8 8d 09 33 00       	call   0x89231a
  56198d:	83 c4 04             	add    esp,0x4
  561990:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561994:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  56199b:	a0 a4 42 f9 00       	mov    al,ds:0xf942a4
  5619a0:	88 83 88 00 00 00    	mov    BYTE PTR [ebx+0x88],al
  5619a6:	75 24                	jne    0x5619cc
  5619a8:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  5619ae:	c7 44 24 68 05 00 00 	mov    DWORD PTR [esp+0x68],0x5
  5619b5:	00 
  5619b6:	e8 c5 5a 02 00       	call   0x587480
  5619bb:	68 c0 cc bc 00       	push   0xbcccc0
  5619c0:	e8 55 09 33 00       	call   0x89231a
  5619c5:	83 c4 04             	add    esp,0x4
  5619c8:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  5619cc:	68 58 43 0f 00       	push   0xf4358
  5619d1:	e8 fa 90 02 00       	call   0x58aad0
  5619d6:	83 c4 04             	add    esp,0x4
  5619d9:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  5619e0:	75 24                	jne    0x561a06
  5619e2:	09 35 90 43 f9 00    	or     DWORD PTR ds:0xf94390,esi
  5619e8:	c7 44 24 68 06 00 00 	mov    DWORD PTR [esp+0x68],0x6
  5619ef:	00 
  5619f0:	e8 9b fb f7 ff       	call   0x4e1590
  5619f5:	68 80 cc bc 00       	push   0xbccc80
  5619fa:	e8 1b 09 33 00       	call   0x89231a
  5619ff:	83 c4 04             	add    esp,0x4
  561a02:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561a06:	6a 00                	push   0x0
  561a08:	68 75 23 bf 00       	push   0xbf2375
  561a0d:	8d 4b 44             	lea    ecx,[ebx+0x44]
  561a10:	c6 05 a4 42 f9 00 01 	mov    BYTE PTR ds:0xf942a4,0x1
  561a17:	e8 54 10 ea ff       	call   0x402a70
  561a1c:	8b 73 0c             	mov    esi,DWORD PTR [ebx+0xc]
  561a1f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  561a22:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  561a26:	8b d6                	mov    edx,esi
  561a28:	75 2c                	jne    0x561a56
  561a2a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  561a30:	8b 48 0c             	mov    ecx,DWORD PTR [eax+0xc]
  561a33:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  561a36:	3b f9                	cmp    edi,ecx
  561a38:	7f 0a                	jg     0x561a44
  561a3a:	7c 0d                	jl     0x561a49
  561a3c:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  561a3f:	39 48 10             	cmp    DWORD PTR [eax+0x10],ecx
  561a42:	7d 05                	jge    0x561a49
  561a44:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  561a47:	eb 04                	jmp    0x561a4d
  561a49:	8b d0                	mov    edx,eax
  561a4b:	8b 00                	mov    eax,DWORD PTR [eax]
  561a4d:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  561a51:	74 dd                	je     0x561a30
  561a53:	83 cf ff             	or     edi,0xffffffff
  561a56:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  561a5a:	3b d6                	cmp    edx,esi
  561a5c:	74 1a                	je     0x561a78
  561a5e:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  561a61:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  561a64:	3b c1                	cmp    eax,ecx
  561a66:	7f 10                	jg     0x561a78
  561a68:	7c 08                	jl     0x561a72
  561a6a:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  561a6d:	3b 42 10             	cmp    eax,DWORD PTR [edx+0x10]
  561a70:	7c 06                	jl     0x561a78
  561a72:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  561a76:	eb 08                	jmp    0x561a80
  561a78:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  561a7c:	8d 44 24 10          	lea    eax,[esp+0x10]
  561a80:	8b 30                	mov    esi,DWORD PTR [eax]
  561a82:	3b 73 0c             	cmp    esi,DWORD PTR [ebx+0xc]
  561a85:	0f 84 f4 02 00 00    	je     0x561d7f
  561a8b:	6a 10                	push   0x10
  561a8d:	68 d0 06 c1 00       	push   0xc106d0
  561a92:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  561a96:	c7 44 24 3c 0f 00 00 	mov    DWORD PTR [esp+0x3c],0xf
  561a9d:	00 
  561a9e:	c7 44 24 38 00 00 00 	mov    DWORD PTR [esp+0x38],0x0
  561aa5:	00 
  561aa6:	c6 44 24 28 00       	mov    BYTE PTR [esp+0x28],0x0
  561aab:	e8 c0 0f ea ff       	call   0x402a70
  561ab0:	8d 46 14             	lea    eax,[esi+0x14]
  561ab3:	57                   	push   edi
  561ab4:	33 f6                	xor    esi,esi
  561ab6:	56                   	push   esi
  561ab7:	50                   	push   eax
  561ab8:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  561abc:	c7 44 24 74 07 00 00 	mov    DWORD PTR [esp+0x74],0x7
  561ac3:	00 
  561ac4:	e8 07 04 ea ff       	call   0x401ed0
  561ac9:	6a 04                	push   0x4
  561acb:	68 e4 06 c1 00       	push   0xc106e4
  561ad0:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  561ad4:	e8 e7 04 ea ff       	call   0x401fc0
  561ad9:	83 7c 24 34 10       	cmp    DWORD PTR [esp+0x34],0x10
  561ade:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  561ae2:	73 04                	jae    0x561ae8
  561ae4:	8d 44 24 20          	lea    eax,[esp+0x20]
  561ae8:	50                   	push   eax
  561ae9:	51                   	push   ecx
  561aea:	e8 b1 aa ff ff       	call   0x55c5a0
  561aef:	83 c4 04             	add    esp,0x4
  561af2:	50                   	push   eax
  561af3:	e8 a8 bb ff ff       	call   0x55d6a0
  561af8:	6a 1c                	push   0x1c
  561afa:	89 43 70             	mov    DWORD PTR [ebx+0x70],eax
  561afd:	e8 66 f7 32 00       	call   0x891268
  561b02:	83 c4 04             	add    esp,0x4
  561b05:	3b c6                	cmp    eax,esi
  561b07:	74 11                	je     0x561b1a
  561b09:	89 30                	mov    DWORD PTR [eax],esi
  561b0b:	c6 40 08 01          	mov    BYTE PTR [eax+0x8],0x1
  561b0f:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  561b12:	89 70 10             	mov    DWORD PTR [eax+0x10],esi
  561b15:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  561b18:	eb 02                	jmp    0x561b1c
  561b1a:	33 c0                	xor    eax,eax
  561b1c:	50                   	push   eax
  561b1d:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  561b21:	51                   	push   ecx
  561b22:	89 74 24 1c          	mov    DWORD PTR [esp+0x1c],esi
  561b26:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  561b2a:	e8 a1 a5 f1 ff       	call   0x47c0d0
  561b2f:	c6 44 24 68 08       	mov    BYTE PTR [esp+0x68],0x8
  561b34:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  561b38:	c7 46 04 03 00 00 00 	mov    DWORD PTR [esi+0x4],0x3
  561b3f:	c6 46 08 01          	mov    BYTE PTR [esi+0x8],0x1
  561b43:	8b 4b 70             	mov    ecx,DWORD PTR [ebx+0x70]
  561b46:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  561b49:	8b 00                	mov    eax,DWORD PTR [eax]
  561b4b:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  561b4f:	3b 41 04             	cmp    eax,DWORD PTR [ecx+0x4]
  561b52:	74 36                	je     0x561b8a
  561b54:	8d 7e 0c             	lea    edi,[esi+0xc]
  561b57:	eb 07                	jmp    0x561b60
  561b59:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  561b60:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  561b63:	0f b7 02             	movzx  eax,WORD PTR [edx]
  561b66:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  561b6a:	8d 44 24 10          	lea    eax,[esp+0x10]
  561b6e:	e8 0d 6b f4 ff       	call   0x4a8680
  561b73:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  561b77:	e8 24 cb f3 ff       	call   0x49e6a0
  561b7c:	8b 43 70             	mov    eax,DWORD PTR [ebx+0x70]
  561b7f:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  561b82:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  561b86:	3b c1                	cmp    eax,ecx
  561b88:	75 d6                	jne    0x561b60
  561b8a:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  561b8e:	83 ec 08             	sub    esp,0x8
  561b91:	8b fc                	mov    edi,esp
  561b93:	89 64 24 18          	mov    DWORD PTR [esp+0x18],esp
  561b97:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  561b9d:	c7 47 04 00 00 00 00 	mov    DWORD PTR [edi+0x4],0x0
  561ba4:	85 d2                	test   edx,edx
  561ba6:	74 16                	je     0x561bbe
  561ba8:	e8 a3 a6 f1 ff       	call   0x47c250
  561bad:	84 c0                	test   al,al
  561baf:	74 0d                	je     0x561bbe
  561bb1:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561bb5:	51                   	push   ecx
  561bb6:	56                   	push   esi
  561bb7:	8b f7                	mov    esi,edi
  561bb9:	e8 02 16 24 00       	call   0x7a31c0
  561bbe:	c6 44 24 70 09       	mov    BYTE PTR [esp+0x70],0x9
  561bc3:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  561bca:	75 23                	jne    0x561bef
  561bcc:	83 0d 60 0f fc 00 01 	or     DWORD PTR ds:0xfc0f60,0x1
  561bd3:	c6 44 24 70 0a       	mov    BYTE PTR [esp+0x70],0xa
  561bd8:	e8 63 b3 23 00       	call   0x79cf40
  561bdd:	68 80 db bc 00       	push   0xbcdb80
  561be2:	e8 33 07 33 00       	call   0x89231a
  561be7:	83 c4 04             	add    esp,0x4
  561bea:	c6 44 24 70 09       	mov    BYTE PTR [esp+0x70],0x9
  561bef:	b9 90 0e fc 00       	mov    ecx,0xfc0e90
  561bf4:	c6 44 24 70 08       	mov    BYTE PTR [esp+0x70],0x8
  561bf9:	e8 e2 c0 23 00       	call   0x79dce0
  561bfe:	8b f0                	mov    esi,eax
  561c00:	6a ff                	push   0xffffffff
  561c02:	56                   	push   esi
  561c03:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  561c09:	56                   	push   esi
  561c0a:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  561c10:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  561c17:	75 23                	jne    0x561c3c
  561c19:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  561c20:	c6 44 24 68 0b       	mov    BYTE PTR [esp+0x68],0xb
  561c25:	e8 76 61 25 00       	call   0x7b7da0
  561c2a:	68 90 e7 bc 00       	push   0xbce790
  561c2f:	e8 e6 06 33 00       	call   0x89231a
  561c34:	83 c4 04             	add    esp,0x4
  561c37:	c6 44 24 68 08       	mov    BYTE PTR [esp+0x68],0x8
  561c3c:	8b 3d 3c 17 fe 00    	mov    edi,DWORD PTR ds:0xfe173c
  561c42:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  561c45:	8b 30                	mov    esi,DWORD PTR [eax]
  561c47:	3b f0                	cmp    esi,eax
  561c49:	74 1c                	je     0x561c67
  561c4b:	eb 03                	jmp    0x561c50
  561c4d:	8d 49 00             	lea    ecx,[ecx+0x0]
  561c50:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  561c53:	83 79 04 00          	cmp    DWORD PTR [ecx+0x4],0x0
  561c57:	75 07                	jne    0x561c60
  561c59:	8b 11                	mov    edx,DWORD PTR [ecx]
  561c5b:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  561c5e:	ff d0                	call   eax
  561c60:	8b 36                	mov    esi,DWORD PTR [esi]
  561c62:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  561c65:	75 e9                	jne    0x561c50
  561c67:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  561c6b:	bf 10 00 00 00       	mov    edi,0x10
  561c70:	39 7c 24 34          	cmp    DWORD PTR [esp+0x34],edi
  561c74:	73 04                	jae    0x561c7a
  561c76:	8d 44 24 20          	lea    eax,[esp+0x20]
  561c7a:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  561c7c:	50                   	push   eax
  561c7d:	e8 ce 2d 19 00       	call   0x6f4a50
  561c82:	33 db                	xor    ebx,ebx
  561c84:	f6 05 ec 79 fb 00 01 	test   BYTE PTR ds:0xfb79ec,0x1
  561c8b:	be 01 00 00 00       	mov    esi,0x1
  561c90:	75 35                	jne    0x561cc7
  561c92:	09 35 ec 79 fb 00    	or     DWORD PTR ds:0xfb79ec,esi
  561c98:	68 70 d2 bc 00       	push   0xbcd270
  561c9d:	c7 05 f0 79 fb 00 68 	mov    DWORD PTR ds:0xfb79f0,0xc0f868
  561ca4:	f8 c0 00 
  561ca7:	89 1d f4 79 fb 00    	mov    DWORD PTR ds:0xfb79f4,ebx
  561cad:	89 1d f8 79 fb 00    	mov    DWORD PTR ds:0xfb79f8,ebx
  561cb3:	89 1d fc 79 fb 00    	mov    DWORD PTR ds:0xfb79fc,ebx
  561cb9:	89 35 04 7a fb 00    	mov    DWORD PTR ds:0xfb7a04,esi
  561cbf:	e8 56 06 33 00       	call   0x89231a
  561cc4:	83 c4 04             	add    esp,0x4
  561cc7:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  561cce:	89 1d 04 7a fb 00    	mov    DWORD PTR ds:0xfb7a04,ebx
  561cd4:	75 22                	jne    0x561cf8
  561cd6:	09 35 60 0f fc 00    	or     DWORD PTR ds:0xfc0f60,esi
  561cdc:	c6 44 24 68 0c       	mov    BYTE PTR [esp+0x68],0xc
  561ce1:	e8 5a b2 23 00       	call   0x79cf40
  561ce6:	68 80 db bc 00       	push   0xbcdb80
  561ceb:	e8 2a 06 33 00       	call   0x89231a
  561cf0:	83 c4 04             	add    esp,0x4
  561cf3:	c6 44 24 68 08       	mov    BYTE PTR [esp+0x68],0x8
  561cf8:	6a 02                	push   0x2
  561cfa:	68 90 0e fc 00       	push   0xfc0e90
  561cff:	e8 bc bc 23 00       	call   0x79d9c0
  561d04:	f6 05 d8 94 fd 00 01 	test   BYTE PTR ds:0xfd94d8,0x1
  561d0b:	75 1d                	jne    0x561d2a
  561d0d:	09 35 d8 94 fd 00    	or     DWORD PTR ds:0xfd94d8,esi
  561d13:	c6 44 24 68 0d       	mov    BYTE PTR [esp+0x68],0xd
  561d18:	e8 13 37 25 00       	call   0x7b5430
  561d1d:	68 60 e6 bc 00       	push   0xbce660
  561d22:	e8 f3 05 33 00       	call   0x89231a
  561d27:	83 c4 04             	add    esp,0x4
  561d2a:	c6 44 24 68 07       	mov    BYTE PTR [esp+0x68],0x7
  561d2f:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  561d33:	c7 05 b0 94 fd 00 02 	mov    DWORD PTR ds:0xfd94b0,0x2
  561d3a:	00 00 00 
  561d3d:	3b f3                	cmp    esi,ebx
  561d3f:	74 29                	je     0x561d6a
  561d41:	8d 4e 04             	lea    ecx,[esi+0x4]
  561d44:	83 ca ff             	or     edx,0xffffffff
  561d47:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  561d4b:	75 1d                	jne    0x561d6a
  561d4d:	8b 06                	mov    eax,DWORD PTR [esi]
  561d4f:	8b 10                	mov    edx,DWORD PTR [eax]
  561d51:	8b ce                	mov    ecx,esi
  561d53:	ff d2                	call   edx
  561d55:	8d 46 08             	lea    eax,[esi+0x8]
  561d58:	83 c9 ff             	or     ecx,0xffffffff
  561d5b:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  561d5f:	75 09                	jne    0x561d6a
  561d61:	8b 16                	mov    edx,DWORD PTR [esi]
  561d63:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  561d66:	8b ce                	mov    ecx,esi
  561d68:	ff d0                	call   eax
  561d6a:	39 7c 24 34          	cmp    DWORD PTR [esp+0x34],edi
  561d6e:	72 16                	jb     0x561d86
  561d70:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561d74:	51                   	push   ecx
  561d75:	e8 92 f4 32 00       	call   0x89120c
  561d7a:	83 c4 04             	add    esp,0x4
  561d7d:	eb 07                	jmp    0x561d86
  561d7f:	8b cb                	mov    ecx,ebx
  561d81:	e8 2a 00 00 00       	call   0x561db0
  561d86:	8b 4c 24 60          	mov    ecx,DWORD PTR [esp+0x60]
  561d8a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561d91:	59                   	pop    ecx
  561d92:	5f                   	pop    edi
  561d93:	5e                   	pop    esi
  561d94:	5b                   	pop    ebx
  561d95:	8b 4c 24 48          	mov    ecx,DWORD PTR [esp+0x48]
  561d99:	33 cc                	xor    ecx,esp
  561d9b:	e8 61 f2 32 00       	call   0x891001

; game: loader/alternate-scene-start 0x565720..0x565a90 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00565720 <.data>:
  565720:	55                   	push   ebp
  565721:	8b ec                	mov    ebp,esp
  565723:	83 e4 f8             	and    esp,0xfffffff8
  565726:	6a ff                	push   0xffffffff
  565728:	68 e8 fb 93 00       	push   0x93fbe8
  56572d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  565733:	50                   	push   eax
  565734:	83 ec 34             	sub    esp,0x34
  565737:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56573c:	33 c4                	xor    eax,esp
  56573e:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  565742:	53                   	push   ebx
  565743:	57                   	push   edi
  565744:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  565749:	33 c4                	xor    eax,esp
  56574b:	50                   	push   eax
  56574c:	8d 44 24 40          	lea    eax,[esp+0x40]
  565750:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  565756:	83 7e 28 00          	cmp    DWORD PTR [esi+0x28],0x0
  56575a:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56575d:	c6 86 89 00 00 00 01 	mov    BYTE PTR [esi+0x89],0x1
  565764:	74 17                	je     0x56577d
  565766:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  565769:	50                   	push   eax
  56576a:	51                   	push   ecx
  56576b:	68 ac 06 c1 00       	push   0xc106ac
  565770:	e8 eb 83 18 00       	call   0x6edb60
  565775:	83 c4 0c             	add    esp,0xc
  565778:	e9 e8 02 00 00       	jmp    0x565a65
  56577d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  565780:	bb 01 00 00 00       	mov    ebx,0x1
  565785:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  565788:	89 46 3c             	mov    DWORD PTR [esi+0x3c],eax
  56578b:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
  56578e:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  565794:	75 29                	jne    0x5657bf
  565796:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  56579c:	c7 44 24 48 00 00 00 	mov    DWORD PTR [esp+0x48],0x0
  5657a3:	00 
  5657a4:	e8 d7 1c 02 00       	call   0x587480
  5657a9:	68 c0 cc bc 00       	push   0xbcccc0
  5657ae:	e8 67 cb 32 00       	call   0x89231a
  5657b3:	83 c4 04             	add    esp,0x4
  5657b6:	83 cf ff             	or     edi,0xffffffff
  5657b9:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  5657bd:	eb 03                	jmp    0x5657c2
  5657bf:	83 cf ff             	or     edi,0xffffffff
  5657c2:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  5657c9:	75 20                	jne    0x5657eb
  5657cb:	09 1d d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,ebx
  5657d1:	89 5c 24 48          	mov    DWORD PTR [esp+0x48],ebx
  5657d5:	e8 b6 81 1e 00       	call   0x74d990
  5657da:	68 70 cc bc 00       	push   0xbccc70
  5657df:	e8 36 cb 32 00       	call   0x89231a
  5657e4:	83 c4 04             	add    esp,0x4
  5657e7:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  5657eb:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  5657f2:	8b 0d bc 5b f9 00    	mov    ecx,DWORD PTR ds:0xf95bbc
  5657f8:	8b 15 c0 5b f9 00    	mov    edx,DWORD PTR ds:0xf95bc0
  5657fe:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  565802:	f3 0f 10 44 24 10    	movss  xmm0,DWORD PTR [esp+0x10]
  565808:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  56580c:	f3 0f 11 86 84 00 00 	movss  DWORD PTR [esi+0x84],xmm0
  565813:	00 
  565814:	75 24                	jne    0x56583a
  565816:	09 1d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,ebx
  56581c:	c7 44 24 48 02 00 00 	mov    DWORD PTR [esp+0x48],0x2
  565823:	00 
  565824:	e8 67 bd f7 ff       	call   0x4e1590
  565829:	68 80 cc bc 00       	push   0xbccc80
  56582e:	e8 e7 ca 32 00       	call   0x89231a
  565833:	83 c4 04             	add    esp,0x4
  565836:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  56583a:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  565841:	a0 a4 42 f9 00       	mov    al,ds:0xf942a4
  565846:	88 86 88 00 00 00    	mov    BYTE PTR [esi+0x88],al
  56584c:	75 24                	jne    0x565872
  56584e:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  565854:	c7 44 24 48 03 00 00 	mov    DWORD PTR [esp+0x48],0x3
  56585b:	00 
  56585c:	e8 1f 1c 02 00       	call   0x587480
  565861:	68 c0 cc bc 00       	push   0xbcccc0
  565866:	e8 af ca 32 00       	call   0x89231a
  56586b:	83 c4 04             	add    esp,0x4
  56586e:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  565872:	68 58 43 0f 00       	push   0xf4358
  565877:	e8 54 52 02 00       	call   0x58aad0
  56587c:	83 c4 04             	add    esp,0x4
  56587f:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  565886:	75 24                	jne    0x5658ac
  565888:	09 1d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,ebx
  56588e:	c7 44 24 48 04 00 00 	mov    DWORD PTR [esp+0x48],0x4
  565895:	00 
  565896:	e8 f5 bc f7 ff       	call   0x4e1590
  56589b:	68 80 cc bc 00       	push   0xbccc80
  5658a0:	e8 75 ca 32 00       	call   0x89231a
  5658a5:	83 c4 04             	add    esp,0x4
  5658a8:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  5658ac:	6a 00                	push   0x0
  5658ae:	68 75 23 bf 00       	push   0xbf2375
  5658b3:	8d 4e 44             	lea    ecx,[esi+0x44]
  5658b6:	c6 05 a4 42 f9 00 01 	mov    BYTE PTR ds:0xf942a4,0x1
  5658bd:	e8 ae d1 e9 ff       	call   0x402a70
  5658c2:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  5658c5:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  5658c8:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5658cc:	75 27                	jne    0x5658f5
  5658ce:	8b ff                	mov    edi,edi
  5658d0:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  5658d3:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5658d6:	3b fa                	cmp    edi,edx
  5658d8:	7f 0a                	jg     0x5658e4
  5658da:	7c 0d                	jl     0x5658e9
  5658dc:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5658df:	39 50 10             	cmp    DWORD PTR [eax+0x10],edx
  5658e2:	7d 05                	jge    0x5658e9
  5658e4:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5658e7:	eb 04                	jmp    0x5658ed
  5658e9:	8b c8                	mov    ecx,eax
  5658eb:	8b 00                	mov    eax,DWORD PTR [eax]
  5658ed:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5658f1:	74 dd                	je     0x5658d0
  5658f3:	eb 03                	jmp    0x5658f8
  5658f5:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5658f8:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  5658fb:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  5658ff:	3b ca                	cmp    ecx,edx
  565901:	74 17                	je     0x56591a
  565903:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  565906:	3b c7                	cmp    eax,edi
  565908:	7f 10                	jg     0x56591a
  56590a:	7c 08                	jl     0x565914
  56590c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56590f:	3b 41 10             	cmp    eax,DWORD PTR [ecx+0x10]
  565912:	7c 06                	jl     0x56591a
  565914:	8d 44 24 18          	lea    eax,[esp+0x18]
  565918:	eb 08                	jmp    0x565922
  56591a:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  56591e:	8d 44 24 10          	lea    eax,[esp+0x10]
  565922:	8b 38                	mov    edi,DWORD PTR [eax]
  565924:	3b fa                	cmp    edi,edx
  565926:	0f 84 39 01 00 00    	je     0x565a65
  56592c:	6a 10                	push   0x10
  56592e:	68 d0 06 c1 00       	push   0xc106d0
  565933:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  565937:	c7 44 24 38 0f 00 00 	mov    DWORD PTR [esp+0x38],0xf
  56593e:	00 
  56593f:	c7 44 24 34 00 00 00 	mov    DWORD PTR [esp+0x34],0x0
  565946:	00 
  565947:	c6 44 24 24 00       	mov    BYTE PTR [esp+0x24],0x0
  56594c:	e8 1f d1 e9 ff       	call   0x402a70
  565951:	6a ff                	push   0xffffffff
  565953:	8d 47 14             	lea    eax,[edi+0x14]
  565956:	6a 00                	push   0x0
  565958:	bb 05 00 00 00       	mov    ebx,0x5
  56595d:	50                   	push   eax
  56595e:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  565962:	89 5c 24 54          	mov    DWORD PTR [esp+0x54],ebx
  565966:	e8 65 c5 e9 ff       	call   0x401ed0
  56596b:	6a 04                	push   0x4
  56596d:	68 e4 06 c1 00       	push   0xc106e4
  565972:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  565976:	e8 45 c6 e9 ff       	call   0x401fc0
  56597b:	83 7c 24 30 10       	cmp    DWORD PTR [esp+0x30],0x10
  565980:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  565984:	73 04                	jae    0x56598a
  565986:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  56598a:	f6 05 e8 1e fe 00 01 	test   BYTE PTR ds:0xfe1ee8,0x1
  565991:	75 22                	jne    0x5659b5
  565993:	83 0d e8 1e fe 00 01 	or     DWORD PTR ds:0xfe1ee8,0x1
  56599a:	c6 44 24 48 06       	mov    BYTE PTR [esp+0x48],0x6
  56599f:	e8 6c 6c ff ff       	call   0x55c610
  5659a4:	68 90 f2 bc 00       	push   0xbcf290
  5659a9:	e8 6c c9 32 00       	call   0x89231a
  5659ae:	83 c4 04             	add    esp,0x4
  5659b1:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  5659b5:	57                   	push   edi
  5659b6:	68 ec 1e fe 00       	push   0xfe1eec
  5659bb:	e8 e0 7c ff ff       	call   0x55d6a0
  5659c0:	bf 10 00 00 00       	mov    edi,0x10
  5659c5:	89 46 70             	mov    DWORD PTR [esi+0x70],eax
  5659c8:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  5659cc:	39 7c 24 30          	cmp    DWORD PTR [esp+0x30],edi
  5659d0:	73 04                	jae    0x5659d6
  5659d2:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5659d6:	8b 0e                	mov    ecx,DWORD PTR [esi]
  5659d8:	50                   	push   eax
  5659d9:	e8 72 f0 18 00       	call   0x6f4a50
  5659de:	e8 6d e8 ec ff       	call   0x434250
  5659e3:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  5659ea:	c7 40 14 00 00 00 00 	mov    DWORD PTR [eax+0x14],0x0
  5659f1:	75 22                	jne    0x565a15
  5659f3:	83 0d 60 0f fc 00 01 	or     DWORD PTR ds:0xfc0f60,0x1
  5659fa:	c6 44 24 48 07       	mov    BYTE PTR [esp+0x48],0x7
  5659ff:	e8 3c 75 23 00       	call   0x79cf40
  565a04:	68 80 db bc 00       	push   0xbcdb80
  565a09:	e8 0c c9 32 00       	call   0x89231a
  565a0e:	83 c4 04             	add    esp,0x4
  565a11:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  565a15:	6a 02                	push   0x2
  565a17:	68 90 0e fc 00       	push   0xfc0e90
  565a1c:	e8 9f 7f 23 00       	call   0x79d9c0
  565a21:	f6 05 d8 94 fd 00 01 	test   BYTE PTR ds:0xfd94d8,0x1
  565a28:	75 1e                	jne    0x565a48
  565a2a:	83 0d d8 94 fd 00 01 	or     DWORD PTR ds:0xfd94d8,0x1
  565a31:	c6 44 24 48 08       	mov    BYTE PTR [esp+0x48],0x8
  565a36:	e8 f5 f9 24 00       	call   0x7b5430
  565a3b:	68 60 e6 bc 00       	push   0xbce660
  565a40:	e8 d5 c8 32 00       	call   0x89231a
  565a45:	83 c4 04             	add    esp,0x4
  565a48:	c7 05 b0 94 fd 00 02 	mov    DWORD PTR ds:0xfd94b0,0x2
  565a4f:	00 00 00 
  565a52:	39 7c 24 30          	cmp    DWORD PTR [esp+0x30],edi
  565a56:	72 0d                	jb     0x565a65
  565a58:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  565a5c:	51                   	push   ecx
  565a5d:	e8 aa b7 32 00       	call   0x89120c
  565a62:	83 c4 04             	add    esp,0x4
  565a65:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  565a69:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  565a70:	59                   	pop    ecx
  565a71:	5f                   	pop    edi
  565a72:	5b                   	pop    ebx
  565a73:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  565a77:	33 cc                	xor    ecx,esp
  565a79:	e8 83 b5 32 00       	call   0x891001
  565a7e:	8b e5                	mov    esp,ebp
  565a80:	5d                   	pop    ebp
  565a81:	c2 08 00             	ret    0x8
  565a84:	cc                   	int3
  565a85:	cc                   	int3
  565a86:	cc                   	int3
  565a87:	cc                   	int3
  565a88:	cc                   	int3
  565a89:	cc                   	int3
  565a8a:	cc                   	int3
  565a8b:	cc                   	int3
  565a8c:	cc                   	int3
  565a8d:	cc                   	int3
  565a8e:	cc                   	int3
  565a8f:	cc                   	int3

; launcher: patcher/provider-stack-construction 0x477131..0x477143 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00477131 <.data>:
  477131:	8b 8d e8 f3 ff ff    	mov    ecx,DWORD PTR [ebp-0xc18]
  477137:	51                   	push   ecx
  477138:	8d 8d 28 fc ff ff    	lea    ecx,[ebp-0x3d8]
  47713e:	e8 4d 34 00 00       	call   0x47a590

; launcher: patcher/remote-manifest-download 0x477143..0x4771b9 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00477143 <.data>:
  477143:	68 18 89 4c 00       	push   0x4c8918
  477148:	8d 8d f0 fb ff ff    	lea    ecx,[ebp-0x410]
  47714e:	e8 bd a4 fe ff       	call   0x461610
  477153:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47715a:	68 3c 89 4c 00       	push   0x4c893c
  47715f:	8d 8d 28 fd ff ff    	lea    ecx,[ebp-0x2d8]
  477165:	e8 a6 a4 fe ff       	call   0x461610
  47716a:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47716e:	68 68 89 4c 00       	push   0x4c8968
  477173:	8d 8d 30 fc ff ff    	lea    ecx,[ebp-0x3d0]
  477179:	e8 92 a4 fe ff       	call   0x461610
  47717e:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  477182:	68 84 89 4c 00       	push   0x4c8984
  477187:	8d 8d ec fc ff ff    	lea    ecx,[ebp-0x314]
  47718d:	e8 7e a4 fe ff       	call   0x461610
  477192:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  477196:	8d 8d 28 fd ff ff    	lea    ecx,[ebp-0x2d8]
  47719c:	e8 7f 6d fa ff       	call   0x41df20
  4771a1:	50                   	push   eax
  4771a2:	8d 8d f0 fb ff ff    	lea    ecx,[ebp-0x410]
  4771a8:	e8 73 6d fa ff       	call   0x41df20
  4771ad:	50                   	push   eax
  4771ae:	8b 8d e8 f3 ff ff    	mov    ecx,DWORD PTR [ebp-0xc18]
  4771b4:	e8 07 19 00 00       	call   0x478ac0

; launcher: patcher/patch-client-version-gate 0x477711..0x477779 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00477711 <.data>:
  477711:	e8 2a de f9 ff       	call   0x415540
  477716:	0f b6 c8             	movzx  ecx,al
  477719:	85 c9                	test   ecx,ecx
  47771b:	74 5c                	je     0x477779
  47771d:	68 dc 89 4c 00       	push   0x4c89dc
  477722:	8d 95 44 f4 ff ff    	lea    edx,[ebp-0xbbc]
  477728:	52                   	push   edx
  477729:	8d 85 74 fb ff ff    	lea    eax,[ebp-0x48c]
  47772f:	50                   	push   eax
  477730:	8d 8d 48 f4 ff ff    	lea    ecx,[ebp-0xbb8]
  477736:	e8 55 3a f9 ff       	call   0x40b190
  47773b:	8b c8                	mov    ecx,eax
  47773d:	e8 de f4 f9 ff       	call   0x416c20
  477742:	8b c8                	mov    ecx,eax
  477744:	e8 b7 aa ff ff       	call   0x472200
  477749:	89 85 70 fb ff ff    	mov    DWORD PTR [ebp-0x490],eax
  47774f:	83 bd 70 fb ff ff 00 	cmp    DWORD PTR [ebp-0x490],0x0
  477756:	74 21                	je     0x477779
  477758:	6a 00                	push   0x0
  47775a:	68 e4 89 4c 00       	push   0x4c89e4
  47775f:	8b 8d 70 fb ff ff    	mov    ecx,DWORD PTR [ebp-0x490]
  477765:	e8 56 cd f9 ff       	call   0x4144c0
  47776a:	83 f8 01             	cmp    eax,0x1
  47776d:	75 0a                	jne    0x477779
  47776f:	c7 85 08 fd ff ff 00 	mov    DWORD PTR [ebp-0x2f8],0x0
  477776:	00 00 00 

; launcher: patcher/manifest-old-new-document-and-root 0x4b8ca0..0x4b8d96 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b8ca0 <.data>:
  4b8ca0:	55                   	push   ebp
  4b8ca1:	8b ec                	mov    ebp,esp
  4b8ca3:	6a ff                	push   0xffffffff
  4b8ca5:	68 b9 1d 4c 00       	push   0x4c1db9
  4b8caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b8cb0:	50                   	push   eax
  4b8cb1:	81 ec 0c 01 00 00    	sub    esp,0x10c
  4b8cb7:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  4b8cbc:	33 c5                	xor    eax,ebp
  4b8cbe:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4b8cc1:	50                   	push   eax
  4b8cc2:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b8cc5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b8ccb:	89 8d e8 fe ff ff    	mov    DWORD PTR [ebp-0x118],ecx
  4b8cd1:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b8cd4:	50                   	push   eax
  4b8cd5:	8d 8d fc fe ff ff    	lea    ecx,[ebp-0x104]
  4b8cdb:	e8 50 c4 f5 ff       	call   0x415130
  4b8ce0:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b8ce7:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b8cea:	51                   	push   ecx
  4b8ceb:	8d 8d 74 ff ff ff    	lea    ecx,[ebp-0x8c]
  4b8cf1:	e8 3a c4 f5 ff       	call   0x415130
  4b8cf6:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4b8cfa:	6a 00                	push   0x0
  4b8cfc:	8d 8d fc fe ff ff    	lea    ecx,[ebp-0x104]
  4b8d02:	e8 f9 c7 f5 ff       	call   0x415500
  4b8d07:	6a 00                	push   0x0
  4b8d09:	8d 8d 74 ff ff ff    	lea    ecx,[ebp-0x8c]
  4b8d0f:	e8 ec c7 f5 ff       	call   0x415500
  4b8d14:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4b8d17:	52                   	push   edx
  4b8d18:	68 94 13 4d 00       	push   0x4d1394
  4b8d1d:	8d 85 f4 fe ff ff    	lea    eax,[ebp-0x10c]
  4b8d23:	50                   	push   eax
  4b8d24:	68 8c 13 4d 00       	push   0x4d138c
  4b8d29:	8d 8d 74 ff ff ff    	lea    ecx,[ebp-0x8c]
  4b8d2f:	e8 bc 25 f5 ff       	call   0x40b2f0
  4b8d34:	50                   	push   eax
  4b8d35:	8d 8d f8 fe ff ff    	lea    ecx,[ebp-0x108]
  4b8d3b:	e8 50 24 f5 ff       	call   0x40b190
  4b8d40:	8b c8                	mov    ecx,eax
  4b8d42:	e8 d9 de f5 ff       	call   0x416c20
  4b8d47:	8b c8                	mov    ecx,eax
  4b8d49:	e8 62 24 f5 ff       	call   0x40b1b0
  4b8d4e:	50                   	push   eax
  4b8d4f:	68 a4 13 4d 00       	push   0x4d13a4
  4b8d54:	8d 8d ec fe ff ff    	lea    ecx,[ebp-0x114]
  4b8d5a:	51                   	push   ecx
  4b8d5b:	68 9c 13 4d 00       	push   0x4d139c
  4b8d60:	8d 8d fc fe ff ff    	lea    ecx,[ebp-0x104]
  4b8d66:	e8 85 25 f5 ff       	call   0x40b2f0
  4b8d6b:	50                   	push   eax
  4b8d6c:	8d 8d f0 fe ff ff    	lea    ecx,[ebp-0x110]
  4b8d72:	e8 19 24 f5 ff       	call   0x40b190
  4b8d77:	8b c8                	mov    ecx,eax
  4b8d79:	e8 a2 de f5 ff       	call   0x416c20
  4b8d7e:	8b c8                	mov    ecx,eax
  4b8d80:	e8 2b 24 f5 ff       	call   0x40b1b0
  4b8d85:	50                   	push   eax
  4b8d86:	68 12 e2 4c 00       	push   0x4ce212
  4b8d8b:	8b 8d e8 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x118]
  4b8d91:	e8 fa f5 ff ff       	call   0x4b8390

; launcher: patcher/manifest-file-name-checksum-length-and-key 0x4b7fe0..0x4b81b1 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b7fe0 <.data>:
  4b7fe0:	55                   	push   ebp
  4b7fe1:	8b ec                	mov    ebp,esp
  4b7fe3:	6a ff                	push   0xffffffff
  4b7fe5:	68 4b 1b 4c 00       	push   0x4c1b4b
  4b7fea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b7ff0:	50                   	push   eax
  4b7ff1:	81 ec 58 01 00 00    	sub    esp,0x158
  4b7ff7:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  4b7ffc:	33 c5                	xor    eax,ebp
  4b7ffe:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4b8001:	50                   	push   eax
  4b8002:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b8005:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b800b:	89 8d b0 fe ff ff    	mov    DWORD PTR [ebp-0x150],ecx
  4b8011:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b8014:	8b 10                	mov    edx,DWORD PTR [eax]
  4b8016:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b8019:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4b801c:	ff d0                	call   eax
  4b801e:	85 c0                	test   eax,eax
  4b8020:	0f 84 df 01 00 00    	je     0x4b8205
  4b8026:	68 f4 12 4d 00       	push   0x4d12f4
  4b802b:	8d 8d 5c ff ff ff    	lea    ecx,[ebp-0xa4]
  4b8031:	e8 ca ce f4 ff       	call   0x404f00
  4b8036:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b803d:	68 0e df 4c 00       	push   0x4cdf0e
  4b8042:	8d 8d 5c ff ff ff    	lea    ecx,[ebp-0xa4]
  4b8048:	51                   	push   ecx
  4b8049:	8d 55 b4             	lea    edx,[ebp-0x4c]
  4b804c:	52                   	push   edx
  4b804d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b8050:	8b 10                	mov    edx,DWORD PTR [eax]
  4b8052:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b8055:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4b8058:	ff d0                	call   eax
  4b805a:	8b c8                	mov    ecx,eax
  4b805c:	e8 bf cf f5 ff       	call   0x415020
  4b8061:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  4b8065:	8d 8d 5c ff ff ff    	lea    ecx,[ebp-0xa4]
  4b806b:	e8 20 cf f4 ff       	call   0x404f90
  4b8070:	68 fc 12 4d 00       	push   0x4d12fc
  4b8075:	8d 8d 40 ff ff ff    	lea    ecx,[ebp-0xc0]
  4b807b:	e8 80 ce f4 ff       	call   0x404f00
  4b8080:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  4b8084:	68 0f df 4c 00       	push   0x4cdf0f
  4b8089:	8d 8d 40 ff ff ff    	lea    ecx,[ebp-0xc0]
  4b808f:	51                   	push   ecx
  4b8090:	8d 55 98             	lea    edx,[ebp-0x68]
  4b8093:	52                   	push   edx
  4b8094:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b8097:	8b 10                	mov    edx,DWORD PTR [eax]
  4b8099:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b809c:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4b809f:	ff d0                	call   eax
  4b80a1:	8b c8                	mov    ecx,eax
  4b80a3:	e8 78 cf f5 ff       	call   0x415020
  4b80a8:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  4b80ac:	8d 8d 40 ff ff ff    	lea    ecx,[ebp-0xc0]
  4b80b2:	e8 d9 ce f4 ff       	call   0x404f90
  4b80b7:	6a 00                	push   0x0
  4b80b9:	68 08 13 4d 00       	push   0x4d1308
  4b80be:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b80c1:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b80c3:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b80c6:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4b80c9:	ff d0                	call   eax
  4b80cb:	8b c8                	mov    ecx,eax
  4b80cd:	e8 ee c3 f5 ff       	call   0x4144c0
  4b80d2:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  4b80d5:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b80d8:	51                   	push   ecx
  4b80d9:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4b80dc:	e8 1f ce f4 ff       	call   0x404f00
  4b80e1:	c6 45 fc 06          	mov    BYTE PTR [ebp-0x4],0x6
  4b80e5:	8d 55 b4             	lea    edx,[ebp-0x4c]
  4b80e8:	52                   	push   edx
  4b80e9:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4b80ec:	e8 2f c7 f4 ff       	call   0x404820
  4b80f1:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  4b80f7:	e8 b4 d2 f4 ff       	call   0x4053b0
  4b80fc:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  4b8100:	8d 45 98             	lea    eax,[ebp-0x68]
  4b8103:	50                   	push   eax
  4b8104:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  4b810a:	e8 d1 c4 f4 ff       	call   0x4045e0
  4b810f:	8b 4d d0             	mov    ecx,DWORD PTR [ebp-0x30]
  4b8112:	89 4d 94             	mov    DWORD PTR [ebp-0x6c],ecx
  4b8115:	83 ec 20             	sub    esp,0x20
  4b8118:	8b cc                	mov    ecx,esp
  4b811a:	89 a5 00 ff ff ff    	mov    DWORD PTR [ebp-0x100],esp
  4b8120:	8d 95 78 ff ff ff    	lea    edx,[ebp-0x88]
  4b8126:	52                   	push   edx
  4b8127:	e8 c4 d2 f4 ff       	call   0x4053f0
  4b812c:	89 85 ac fe ff ff    	mov    DWORD PTR [ebp-0x154],eax
  4b8132:	8b 85 ac fe ff ff    	mov    eax,DWORD PTR [ebp-0x154]
  4b8138:	89 85 a8 fe ff ff    	mov    DWORD PTR [ebp-0x158],eax
  4b813e:	c6 45 fc 08          	mov    BYTE PTR [ebp-0x4],0x8
  4b8142:	83 ec 1c             	sub    esp,0x1c
  4b8145:	8b cc                	mov    ecx,esp
  4b8147:	89 a5 fc fe ff ff    	mov    DWORD PTR [ebp-0x104],esp
  4b814d:	8d 55 d4             	lea    edx,[ebp-0x2c]
  4b8150:	52                   	push   edx
  4b8151:	e8 ea c4 f4 ff       	call   0x404640
  4b8156:	89 85 a4 fe ff ff    	mov    DWORD PTR [ebp-0x15c],eax
  4b815c:	8d 85 c0 fe ff ff    	lea    eax,[ebp-0x140]
  4b8162:	50                   	push   eax
  4b8163:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  4b8167:	e8 74 23 f5 ff       	call   0x40a4e0
  4b816c:	83 c4 40             	add    esp,0x40
  4b816f:	89 85 a0 fe ff ff    	mov    DWORD PTR [ebp-0x160],eax
  4b8175:	8b 8d a0 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x160]
  4b817b:	89 8d 9c fe ff ff    	mov    DWORD PTR [ebp-0x164],ecx
  4b8181:	c6 45 fc 09          	mov    BYTE PTR [ebp-0x4],0x9
  4b8185:	8b 95 9c fe ff ff    	mov    edx,DWORD PTR [ebp-0x164]
  4b818b:	52                   	push   edx
  4b818c:	8d 8d 04 ff ff ff    	lea    ecx,[ebp-0xfc]
  4b8192:	e8 c9 23 f5 ff       	call   0x40a560
  4b8197:	c6 45 fc 0a          	mov    BYTE PTR [ebp-0x4],0xa
  4b819b:	8d 85 04 ff ff ff    	lea    eax,[ebp-0xfc]
  4b81a1:	50                   	push   eax
  4b81a2:	8d 8d b4 fe ff ff    	lea    ecx,[ebp-0x14c]
  4b81a8:	51                   	push   ecx
  4b81a9:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4b81ac:	e8 6f d9 f4 ff       	call   0x405b20

; launcher: patcher/manifest-file-enumeration-and-plan-214 0x4b83df..0x4b84df (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b83df <.data>:
  4b83df:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  4b83e3:	74 10                	je     0x4b83f5
  4b83e5:	68 1c 13 4d 00       	push   0x4d131c
  4b83ea:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b83ed:	e8 fe 2e f5 ff       	call   0x40b2f0
  4b83f2:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  4b83f5:	83 7d 10 00          	cmp    DWORD PTR [ebp+0x10],0x0
  4b83f9:	74 13                	je     0x4b840e
  4b83fb:	68 24 13 4d 00       	push   0x4d1324
  4b8400:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4b8403:	e8 e8 2e f5 ff       	call   0x40b2f0
  4b8408:	89 85 4c ff ff ff    	mov    DWORD PTR [ebp-0xb4],eax
  4b840e:	8d 8d 2c ff ff ff    	lea    ecx,[ebp-0xd4]
  4b8414:	e8 17 d6 f4 ff       	call   0x405a30
  4b8419:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b8420:	8d 8d 70 ff ff ff    	lea    ecx,[ebp-0x90]
  4b8426:	e8 05 d6 f4 ff       	call   0x405a30
  4b842b:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4b842f:	83 7d b0 00          	cmp    DWORD PTR [ebp-0x50],0x0
  4b8433:	74 2c                	je     0x4b8461
  4b8435:	8d 85 2c ff ff ff    	lea    eax,[ebp-0xd4]
  4b843b:	50                   	push   eax
  4b843c:	8b 4d b0             	mov    ecx,DWORD PTR [ebp-0x50]
  4b843f:	51                   	push   ecx
  4b8440:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b8443:	52                   	push   edx
  4b8444:	8b 8d d4 fd ff ff    	mov    ecx,DWORD PTR [ebp-0x22c]
  4b844a:	e8 91 fb ff ff       	call   0x4b7fe0
  4b844f:	68 2c 13 4d 00       	push   0x4d132c
  4b8454:	8b 4d b0             	mov    ecx,DWORD PTR [ebp-0x50]
  4b8457:	e8 74 2e f5 ff       	call   0x40b2d0
  4b845c:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  4b845f:	eb ce                	jmp    0x4b842f
  4b8461:	83 bd 4c ff ff ff 00 	cmp    DWORD PTR [ebp-0xb4],0x0
  4b8468:	74 35                	je     0x4b849f
  4b846a:	8d 85 70 ff ff ff    	lea    eax,[ebp-0x90]
  4b8470:	50                   	push   eax
  4b8471:	8b 8d 4c ff ff ff    	mov    ecx,DWORD PTR [ebp-0xb4]
  4b8477:	51                   	push   ecx
  4b8478:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b847b:	52                   	push   edx
  4b847c:	8b 8d d4 fd ff ff    	mov    ecx,DWORD PTR [ebp-0x22c]
  4b8482:	e8 59 fb ff ff       	call   0x4b7fe0
  4b8487:	68 34 13 4d 00       	push   0x4d1334
  4b848c:	8b 8d 4c ff ff ff    	mov    ecx,DWORD PTR [ebp-0xb4]
  4b8492:	e8 39 2e f5 ff       	call   0x40b2d0
  4b8497:	89 85 4c ff ff ff    	mov    DWORD PTR [ebp-0xb4],eax
  4b849d:	eb c2                	jmp    0x4b8461
  4b849f:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  4b84a2:	50                   	push   eax
  4b84a3:	8b 8d d4 fd ff ff    	mov    ecx,DWORD PTR [ebp-0x22c]
  4b84a9:	81 c1 4c 02 00 00    	add    ecx,0x24c
  4b84af:	51                   	push   ecx
  4b84b0:	8b 95 d4 fd ff ff    	mov    edx,DWORD PTR [ebp-0x22c]
  4b84b6:	81 c2 30 02 00 00    	add    edx,0x230
  4b84bc:	52                   	push   edx
  4b84bd:	8b 85 d4 fd ff ff    	mov    eax,DWORD PTR [ebp-0x22c]
  4b84c3:	05 14 02 00 00       	add    eax,0x214
  4b84c8:	50                   	push   eax
  4b84c9:	8d 8d 70 ff ff ff    	lea    ecx,[ebp-0x90]
  4b84cf:	51                   	push   ecx
  4b84d0:	8d 95 2c ff ff ff    	lea    edx,[ebp-0xd4]
  4b84d6:	52                   	push   edx
  4b84d7:	e8 e4 cc f4 ff       	call   0x4051c0
  4b84dc:	83 c4 18             	add    esp,0x18

; launcher: patcher/manifest-file-difference-add-update-delete 0x4051c0..0x4053b0 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004051c0 <.data>:
  4051c0:	55                   	push   ebp
  4051c1:	8b ec                	mov    ebp,esp
  4051c3:	83 ec 54             	sub    esp,0x54
  4051c6:	8d 45 f8             	lea    eax,[ebp-0x8]
  4051c9:	50                   	push   eax
  4051ca:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4051cd:	e8 ee 08 00 00       	call   0x405ac0
  4051d2:	8d 4d f0             	lea    ecx,[ebp-0x10]
  4051d5:	51                   	push   ecx
  4051d6:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4051d9:	e8 e2 08 00 00       	call   0x405ac0
  4051de:	8d 55 e4             	lea    edx,[ebp-0x1c]
  4051e1:	52                   	push   edx
  4051e2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4051e5:	e8 06 09 00 00       	call   0x405af0
  4051ea:	50                   	push   eax
  4051eb:	8d 4d f8             	lea    ecx,[ebp-0x8]
  4051ee:	e8 7d 0b 00 00       	call   0x405d70
  4051f3:	0f b6 c0             	movzx  eax,al
  4051f6:	85 c0                	test   eax,eax
  4051f8:	0f 84 27 01 00 00    	je     0x405325
  4051fe:	8d 4d dc             	lea    ecx,[ebp-0x24]
  405201:	51                   	push   ecx
  405202:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  405205:	e8 e6 08 00 00       	call   0x405af0
  40520a:	50                   	push   eax
  40520b:	8d 4d f0             	lea    ecx,[ebp-0x10]
  40520e:	e8 5d 0b 00 00       	call   0x405d70
  405213:	0f b6 d0             	movzx  edx,al
  405216:	85 d2                	test   edx,edx
  405218:	0f 84 07 01 00 00    	je     0x405325
  40521e:	8d 4d f0             	lea    ecx,[ebp-0x10]
  405221:	e8 ca 0a 00 00       	call   0x405cf0
  405226:	8b c8                	mov    ecx,eax
  405228:	e8 43 fd ff ff       	call   0x404f70
  40522d:	50                   	push   eax
  40522e:	8d 4d f8             	lea    ecx,[ebp-0x8]
  405231:	e8 ba 0a 00 00       	call   0x405cf0
  405236:	8b c8                	mov    ecx,eax
  405238:	e8 33 fd ff ff       	call   0x404f70
  40523d:	50                   	push   eax
  40523e:	e8 fd 7a 08 00       	call   0x48cd40
  405243:	83 c4 08             	add    esp,0x8
  405246:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  405249:	83 7d ec 00          	cmp    DWORD PTR [ebp-0x14],0x0
  40524d:	75 76                	jne    0x4052c5
  40524f:	8d 4d f0             	lea    ecx,[ebp-0x10]
  405252:	e8 99 0a 00 00       	call   0x405cf0
  405257:	83 c0 1c             	add    eax,0x1c
  40525a:	8b c8                	mov    ecx,eax
  40525c:	e8 0f fd ff ff       	call   0x404f70
  405261:	50                   	push   eax
  405262:	8d 4d f8             	lea    ecx,[ebp-0x8]
  405265:	e8 86 0a 00 00       	call   0x405cf0
  40526a:	83 c0 1c             	add    eax,0x1c
  40526d:	8b c8                	mov    ecx,eax
  40526f:	e8 fc fc ff ff       	call   0x404f70
  405274:	50                   	push   eax
  405275:	e8 c6 7a 08 00       	call   0x48cd40
  40527a:	83 c4 08             	add    esp,0x8
  40527d:	85 c0                	test   eax,eax
  40527f:	74 26                	je     0x4052a7
  405281:	8d 4d f8             	lea    ecx,[ebp-0x8]
  405284:	e8 67 0a 00 00       	call   0x405cf0
  405289:	50                   	push   eax
  40528a:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  40528d:	e8 8e 06 00 00       	call   0x405920
  405292:	8d 4d f0             	lea    ecx,[ebp-0x10]
  405295:	e8 56 0a 00 00       	call   0x405cf0
  40529a:	8b 4d 1c             	mov    ecx,DWORD PTR [ebp+0x1c]
  40529d:	8b 11                	mov    edx,DWORD PTR [ecx]
  40529f:	03 50 38             	add    edx,DWORD PTR [eax+0x38]
  4052a2:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  4052a5:	89 10                	mov    DWORD PTR [eax],edx
  4052a7:	6a 00                	push   0x0
  4052a9:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4052ac:	51                   	push   ecx
  4052ad:	8d 4d f8             	lea    ecx,[ebp-0x8]
  4052b0:	e8 7b 0a 00 00       	call   0x405d30
  4052b5:	6a 00                	push   0x0
  4052b7:	8d 55 cc             	lea    edx,[ebp-0x34]
  4052ba:	52                   	push   edx
  4052bb:	8d 4d f0             	lea    ecx,[ebp-0x10]
  4052be:	e8 6d 0a 00 00       	call   0x405d30
  4052c3:	eb 5b                	jmp    0x405320
  4052c5:	83 7d ec 00          	cmp    DWORD PTR [ebp-0x14],0x0
  4052c9:	7d 21                	jge    0x4052ec
  4052cb:	8d 4d f8             	lea    ecx,[ebp-0x8]
  4052ce:	e8 1d 0a 00 00       	call   0x405cf0
  4052d3:	50                   	push   eax
  4052d4:	8b 4d 18             	mov    ecx,DWORD PTR [ebp+0x18]
  4052d7:	e8 44 06 00 00       	call   0x405920
  4052dc:	6a 00                	push   0x0
  4052de:	8d 45 c4             	lea    eax,[ebp-0x3c]
  4052e1:	50                   	push   eax
  4052e2:	8d 4d f8             	lea    ecx,[ebp-0x8]
  4052e5:	e8 46 0a 00 00       	call   0x405d30
  4052ea:	eb 34                	jmp    0x405320
  4052ec:	8d 4d f0             	lea    ecx,[ebp-0x10]
  4052ef:	e8 fc 09 00 00       	call   0x405cf0
  4052f4:	50                   	push   eax
  4052f5:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4052f8:	e8 23 06 00 00       	call   0x405920
  4052fd:	8d 4d f0             	lea    ecx,[ebp-0x10]
  405300:	e8 eb 09 00 00       	call   0x405cf0
  405305:	8b 4d 1c             	mov    ecx,DWORD PTR [ebp+0x1c]
  405308:	8b 11                	mov    edx,DWORD PTR [ecx]
  40530a:	03 50 38             	add    edx,DWORD PTR [eax+0x38]
  40530d:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  405310:	89 10                	mov    DWORD PTR [eax],edx
  405312:	6a 00                	push   0x0
  405314:	8d 4d bc             	lea    ecx,[ebp-0x44]
  405317:	51                   	push   ecx
  405318:	8d 4d f0             	lea    ecx,[ebp-0x10]
  40531b:	e8 10 0a 00 00       	call   0x405d30
  405320:	e9 b9 fe ff ff       	jmp    0x4051de
  405325:	eb 08                	jmp    0x40532f
  405327:	8d 4d f8             	lea    ecx,[ebp-0x8]
  40532a:	e8 e1 09 00 00       	call   0x405d10
  40532f:	8d 55 b4             	lea    edx,[ebp-0x4c]
  405332:	52                   	push   edx
  405333:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  405336:	e8 b5 07 00 00       	call   0x405af0
  40533b:	50                   	push   eax
  40533c:	8d 4d f8             	lea    ecx,[ebp-0x8]
  40533f:	e8 2c 0a 00 00       	call   0x405d70
  405344:	0f b6 c0             	movzx  eax,al
  405347:	85 c0                	test   eax,eax
  405349:	74 13                	je     0x40535e
  40534b:	8d 4d f8             	lea    ecx,[ebp-0x8]
  40534e:	e8 9d 09 00 00       	call   0x405cf0
  405353:	50                   	push   eax
  405354:	8b 4d 18             	mov    ecx,DWORD PTR [ebp+0x18]
  405357:	e8 c4 05 00 00       	call   0x405920
  40535c:	eb c9                	jmp    0x405327
  40535e:	eb 08                	jmp    0x405368
  405360:	8d 4d f0             	lea    ecx,[ebp-0x10]
  405363:	e8 a8 09 00 00       	call   0x405d10
  405368:	8d 4d ac             	lea    ecx,[ebp-0x54]
  40536b:	51                   	push   ecx
  40536c:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  40536f:	e8 7c 07 00 00       	call   0x405af0
  405374:	50                   	push   eax
  405375:	8d 4d f0             	lea    ecx,[ebp-0x10]
  405378:	e8 f3 09 00 00       	call   0x405d70
  40537d:	0f b6 d0             	movzx  edx,al
  405380:	85 d2                	test   edx,edx
  405382:	74 28                	je     0x4053ac
  405384:	8d 4d f0             	lea    ecx,[ebp-0x10]
  405387:	e8 64 09 00 00       	call   0x405cf0
  40538c:	50                   	push   eax
  40538d:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  405390:	e8 8b 05 00 00       	call   0x405920
  405395:	8d 4d f0             	lea    ecx,[ebp-0x10]
  405398:	e8 53 09 00 00       	call   0x405cf0
  40539d:	8b 4d 1c             	mov    ecx,DWORD PTR [ebp+0x1c]
  4053a0:	8b 11                	mov    edx,DWORD PTR [ecx]
  4053a2:	03 50 38             	add    edx,DWORD PTR [eax+0x38]
  4053a5:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  4053a8:	89 10                	mov    DWORD PTR [eax],edx
  4053aa:	eb b4                	jmp    0x405360
  4053ac:	8b e5                	mov    esp,ebp
  4053ae:	5d                   	pop    ebp
  4053af:	c3                   	ret

; launcher: patcher/plan-added-file-list-getter 0x47a460..0x47a480 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0047a460 <.data>:
  47a460:	55                   	push   ebp
  47a461:	8b ec                	mov    ebp,esp
  47a463:	51                   	push   ecx
  47a464:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  47a467:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  47a46a:	05 14 02 00 00       	add    eax,0x214
  47a46f:	8b e5                	mov    esp,ebp
  47a471:	5d                   	pop    ebp
  47a472:	c3                   	ret
  47a473:	cc                   	int3
  47a474:	cc                   	int3
  47a475:	cc                   	int3
  47a476:	cc                   	int3
  47a477:	cc                   	int3
  47a478:	cc                   	int3
  47a479:	cc                   	int3
  47a47a:	cc                   	int3
  47a47b:	cc                   	int3
  47a47c:	cc                   	int3
  47a47d:	cc                   	int3
  47a47e:	cc                   	int3
  47a47f:	cc                   	int3

; launcher: patcher/provider-vptr-constructor 0x47a590..0x47a5c0 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0047a590 <.data>:
  47a590:	55                   	push   ebp
  47a591:	8b ec                	mov    ebp,esp
  47a593:	51                   	push   ecx
  47a594:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  47a597:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  47a59a:	e8 a1 70 f8 ff       	call   0x401640
  47a59f:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  47a5a2:	c7 00 d8 8d 4c 00    	mov    DWORD PTR [eax],0x4c8dd8
  47a5a8:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  47a5ab:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  47a5ae:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  47a5b1:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  47a5b4:	8b e5                	mov    esp,ebp
  47a5b6:	5d                   	pop    ebp
  47a5b7:	c2 04 00             	ret    0x4
  47a5ba:	cc                   	int3
  47a5bb:	cc                   	int3
  47a5bc:	cc                   	int3
  47a5bd:	cc                   	int3
  47a5be:	cc                   	int3
  47a5bf:	cc                   	int3

; launcher: patcher/provider-to-executor-construction 0x477ca9..0x477ccf (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00477ca9 <.data>:
  477ca9:	68 f5 88 4c 00       	push   0x4c88f5
  477cae:	8d 8d 44 fd ff ff    	lea    ecx,[ebp-0x2bc]
  477cb4:	e8 e7 0e 04 00       	call   0x4b8ba0
  477cb9:	c6 45 fc 12          	mov    BYTE PTR [ebp-0x4],0x12
  477cbd:	8d 85 28 fc ff ff    	lea    eax,[ebp-0x3d8]
  477cc3:	50                   	push   eax
  477cc4:	8d 8d a4 fc ff ff    	lea    ecx,[ebp-0x35c]
  477cca:	e8 81 1a 04 00       	call   0x4b9750

; launcher: patcher/executor-provider-field 0x4b9750..0x4b977e (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b9750 <.data>:
  4b9750:	55                   	push   ebp
  4b9751:	8b ec                	mov    ebp,esp
  4b9753:	6a ff                	push   0xffffffff
  4b9755:	68 ac 18 4c 00       	push   0x4c18ac
  4b975a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b9760:	50                   	push   eax
  4b9761:	51                   	push   ecx
  4b9762:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  4b9767:	33 c5                	xor    eax,ebp
  4b9769:	50                   	push   eax
  4b976a:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b976d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b9773:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  4b9776:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  4b9779:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b977c:	89 08                	mov    DWORD PTR [eax],ecx

; launcher: patcher/plan-to-executor-and-failure-status 0x478766..0x4787fb (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00478766 <.data>:
  478766:	8b 95 e8 f3 ff ff    	mov    edx,DWORD PTR [ebp-0xc18]
  47876c:	81 c2 74 01 00 00    	add    edx,0x174
  478772:	52                   	push   edx
  478773:	8d 8d 44 fd ff ff    	lea    ecx,[ebp-0x2bc]
  478779:	e8 82 1d 00 00       	call   0x47a500
  47877e:	50                   	push   eax
  47877f:	8d 8d 44 fd ff ff    	lea    ecx,[ebp-0x2bc]
  478785:	e8 16 1d 00 00       	call   0x47a4a0
  47878a:	50                   	push   eax
  47878b:	8d 8d 44 fd ff ff    	lea    ecx,[ebp-0x2bc]
  478791:	e8 ea 1c 00 00       	call   0x47a480
  478796:	50                   	push   eax
  478797:	8d 8d 44 fd ff ff    	lea    ecx,[ebp-0x2bc]
  47879d:	e8 be 1c 00 00       	call   0x47a460
  4787a2:	50                   	push   eax
  4787a3:	8d 8d 44 fd ff ff    	lea    ecx,[ebp-0x2bc]
  4787a9:	e8 32 1d 00 00       	call   0x47a4e0
  4787ae:	50                   	push   eax
  4787af:	8d 8d 44 fd ff ff    	lea    ecx,[ebp-0x2bc]
  4787b5:	e8 06 1d 00 00       	call   0x47a4c0
  4787ba:	50                   	push   eax
  4787bb:	68 f6 88 4c 00       	push   0x4c88f6
  4787c0:	8d 8d a4 fc ff ff    	lea    ecx,[ebp-0x35c]
  4787c6:	e8 f5 25 04 00       	call   0x4badc0
  4787cb:	89 85 84 fc ff ff    	mov    DWORD PTR [ebp-0x37c],eax
  4787d1:	68 8c 8b 4c 00       	push   0x4c8b8c
  4787d6:	e8 25 88 f8 ff       	call   0x401000
  4787db:	83 c4 04             	add    esp,0x4
  4787de:	83 bd 84 fc ff ff 00 	cmp    DWORD PTR [ebp-0x37c],0x0
  4787e5:	0f 85 e3 00 00 00    	jne    0x4788ce
  4787eb:	8b 85 e8 f3 ff ff    	mov    eax,DWORD PTR [ebp-0xc18]
  4787f1:	c7 80 70 01 00 00 09 	mov    DWORD PTR [eax+0x170],0x9
  4787f8:	00 00 00 

; launcher: patcher/new-file-loop-to-writer 0x4bb03d..0x4bb0e2 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004bb03d <.data>:
  4bb03d:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  4bb040:	89 45 9c             	mov    DWORD PTR [ebp-0x64],eax
  4bb043:	8d 8d 40 ff ff ff    	lea    ecx,[ebp-0xc0]
  4bb049:	51                   	push   ecx
  4bb04a:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  4bb04d:	e8 ee 67 f4 ff       	call   0x401840
  4bb052:	8b 10                	mov    edx,DWORD PTR [eax]
  4bb054:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4bb057:	89 55 94             	mov    DWORD PTR [ebp-0x6c],edx
  4bb05a:	89 45 98             	mov    DWORD PTR [ebp-0x68],eax
  4bb05d:	8d 8d 38 ff ff ff    	lea    ecx,[ebp-0xc8]
  4bb063:	51                   	push   ecx
  4bb064:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  4bb067:	e8 a4 67 f4 ff       	call   0x401810
  4bb06c:	8b 10                	mov    edx,DWORD PTR [eax]
  4bb06e:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4bb071:	89 55 8c             	mov    DWORD PTR [ebp-0x74],edx
  4bb074:	89 45 90             	mov    DWORD PTR [ebp-0x70],eax
  4bb077:	eb 08                	jmp    0x4bb081
  4bb079:	8d 4d 8c             	lea    ecx,[ebp-0x74]
  4bb07c:	e8 cf 69 f4 ff       	call   0x401a50
  4bb081:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  4bb084:	51                   	push   ecx
  4bb085:	8d 4d 8c             	lea    ecx,[ebp-0x74]
  4bb088:	e8 33 6a f4 ff       	call   0x401ac0
  4bb08d:	0f b6 d0             	movzx  edx,al
  4bb090:	85 d2                	test   edx,edx
  4bb092:	74 49                	je     0x4bb0dd
  4bb094:	8d 4d 8c             	lea    ecx,[ebp-0x74]
  4bb097:	e8 54 69 f4 ff       	call   0x4019f0
  4bb09c:	89 45 88             	mov    DWORD PTR [ebp-0x78],eax
  4bb09f:	8b 85 34 ff ff ff    	mov    eax,DWORD PTR [ebp-0xcc]
  4bb0a5:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4bb0a9:	74 04                	je     0x4bb0af
  4bb0ab:	33 c0                	xor    eax,eax
  4bb0ad:	eb 33                	jmp    0x4bb0e2
  4bb0af:	8b 4d 20             	mov    ecx,DWORD PTR [ebp+0x20]
  4bb0b2:	51                   	push   ecx
  4bb0b3:	8b 55 88             	mov    edx,DWORD PTR [ebp-0x78]
  4bb0b6:	52                   	push   edx
  4bb0b7:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4bb0ba:	50                   	push   eax
  4bb0bb:	8b 8d 34 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xcc]
  4bb0c1:	e8 ba f1 ff ff       	call   0x4ba280
  4bb0c6:	85 c0                	test   eax,eax
  4bb0c8:	75 04                	jne    0x4bb0ce
  4bb0ca:	33 c0                	xor    eax,eax
  4bb0cc:	eb 14                	jmp    0x4bb0e2
  4bb0ce:	8b 4d 24             	mov    ecx,DWORD PTR [ebp+0x24]
  4bb0d1:	8b 11                	mov    edx,DWORD PTR [ecx]
  4bb0d3:	83 c2 01             	add    edx,0x1
  4bb0d6:	8b 45 24             	mov    eax,DWORD PTR [ebp+0x24]
  4bb0d9:	89 10                	mov    DWORD PTR [eax],edx
  4bb0db:	eb 9c                	jmp    0x4bb079
  4bb0dd:	b8 01 00 00 00       	mov    eax,0x1

; launcher: patcher/package-mapping-or-plain-branch 0x4ba280..0x4ba2d1 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004ba280 <.data>:
  4ba280:	55                   	push   ebp
  4ba281:	8b ec                	mov    ebp,esp
  4ba283:	6a ff                	push   0xffffffff
  4ba285:	68 3c 21 4c 00       	push   0x4c213c
  4ba28a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ba290:	50                   	push   eax
  4ba291:	81 ec ac 00 00 00    	sub    esp,0xac
  4ba297:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  4ba29c:	33 c5                	xor    eax,ebp
  4ba29e:	89 45 c8             	mov    DWORD PTR [ebp-0x38],eax
  4ba2a1:	50                   	push   eax
  4ba2a2:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ba2a5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ba2ab:	89 8d 48 ff ff ff    	mov    DWORD PTR [ebp-0xb8],ecx
  4ba2b1:	6a 01                	push   0x1
  4ba2b3:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4ba2b6:	e8 b5 ac f4 ff       	call   0x404f70
  4ba2bb:	50                   	push   eax
  4ba2bc:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4ba2bf:	e8 6c d3 ff ff       	call   0x4b7630
  4ba2c4:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ba2c7:	83 7d f0 00          	cmp    DWORD PTR [ebp-0x10],0x0
  4ba2cb:	0f 84 70 02 00 00    	je     0x4ba541

; launcher: patcher/package-path-extension-selection 0x4b7630..0x4b7adb (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b7630 <.data>:
  4b7630:	55                   	push   ebp
  4b7631:	8b ec                	mov    ebp,esp
  4b7633:	6a ff                	push   0xffffffff
  4b7635:	68 a8 19 4c 00       	push   0x4c19a8
  4b763a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b7640:	50                   	push   eax
  4b7641:	81 ec ac 01 00 00    	sub    esp,0x1ac
  4b7647:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  4b764c:	33 c5                	xor    eax,ebp
  4b764e:	89 45 a0             	mov    DWORD PTR [ebp-0x60],eax
  4b7651:	56                   	push   esi
  4b7652:	50                   	push   eax
  4b7653:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b7656:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b765c:	89 8d 48 fe ff ff    	mov    DWORD PTR [ebp-0x1b8],ecx
  4b7662:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  4b7669:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  4b7670:	8b 85 48 fe ff ff    	mov    eax,DWORD PTR [ebp-0x1b8]
  4b7676:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  4b7679:	8d 8d 8c fe ff ff    	lea    ecx,[ebp-0x174]
  4b767f:	51                   	push   ecx
  4b7680:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  4b7683:	e8 c8 96 f5 ff       	call   0x410d50
  4b7688:	8b 10                	mov    edx,DWORD PTR [eax]
  4b768a:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b768d:	89 55 e4             	mov    DWORD PTR [ebp-0x1c],edx
  4b7690:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4b7693:	8d 8d 84 fe ff ff    	lea    ecx,[ebp-0x17c]
  4b7699:	51                   	push   ecx
  4b769a:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  4b769d:	e8 7e 96 f5 ff       	call   0x410d20
  4b76a2:	8b 10                	mov    edx,DWORD PTR [eax]
  4b76a4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b76a7:	89 55 d8             	mov    DWORD PTR [ebp-0x28],edx
  4b76aa:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  4b76ad:	eb 08                	jmp    0x4b76b7
  4b76af:	8d 4d d8             	lea    ecx,[ebp-0x28]
  4b76b2:	e8 89 97 f5 ff       	call   0x410e40
  4b76b7:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  4b76ba:	51                   	push   ecx
  4b76bb:	8d 4d d8             	lea    ecx,[ebp-0x28]
  4b76be:	e8 ed 97 f5 ff       	call   0x410eb0
  4b76c3:	0f b6 d0             	movzx  edx,al
  4b76c6:	85 d2                	test   edx,edx
  4b76c8:	0f 84 e4 03 00 00    	je     0x4b7ab2
  4b76ce:	8d 4d d8             	lea    ecx,[ebp-0x28]
  4b76d1:	e8 0a 97 f5 ff       	call   0x410de0
  4b76d6:	8b 00                	mov    eax,DWORD PTR [eax]
  4b76d8:	89 45 d4             	mov    DWORD PTR [ebp-0x2c],eax
  4b76db:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b76de:	83 c1 1c             	add    ecx,0x1c
  4b76e1:	e8 ba 9f f4 ff       	call   0x4016a0
  4b76e6:	50                   	push   eax
  4b76e7:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b76ea:	83 c1 1c             	add    ecx,0x1c
  4b76ed:	e8 7e d8 f4 ff       	call   0x404f70
  4b76f2:	50                   	push   eax
  4b76f3:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b76f6:	51                   	push   ecx
  4b76f7:	e8 53 5a fd ff       	call   0x48d14f
  4b76fc:	83 c4 0c             	add    esp,0xc
  4b76ff:	85 c0                	test   eax,eax
  4b7701:	0f 85 a6 03 00 00    	jne    0x4b7aad
  4b7707:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b770a:	83 c1 1c             	add    ecx,0x1c
  4b770d:	e8 8e 9f f4 ff       	call   0x4016a0
  4b7712:	3b 45 ec             	cmp    eax,DWORD PTR [ebp-0x14]
  4b7715:	0f 86 92 03 00 00    	jbe    0x4b7aad
  4b771b:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  4b771e:	83 7a 38 00          	cmp    DWORD PTR [edx+0x38],0x0
  4b7722:	0f 84 f0 00 00 00    	je     0x4b7818
  4b7728:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  4b772c:	75 05                	jne    0x4b7733
  4b772e:	e9 7c ff ff ff       	jmp    0x4b76af
  4b7733:	8d 4d bc             	lea    ecx,[ebp-0x44]
  4b7736:	e8 35 a1 f4 ff       	call   0x401870
  4b773b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b7742:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b7745:	83 c1 1c             	add    ecx,0x1c
  4b7748:	e8 23 d8 f4 ff       	call   0x404f70
  4b774d:	50                   	push   eax
  4b774e:	8d 8d 68 fe ff ff    	lea    ecx,[ebp-0x198]
  4b7754:	e8 a7 d7 f4 ff       	call   0x404f00
  4b7759:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4b775d:	6a 5c                	push   0x5c
  4b775f:	8d 45 bc             	lea    eax,[ebp-0x44]
  4b7762:	50                   	push   eax
  4b7763:	8d 8d 68 fe ff ff    	lea    ecx,[ebp-0x198]
  4b7769:	51                   	push   ecx
  4b776a:	e8 81 9c f4 ff       	call   0x4013f0
  4b776f:	83 c4 0c             	add    esp,0xc
  4b7772:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4b7776:	8d 8d 68 fe ff ff    	lea    ecx,[ebp-0x198]
  4b777c:	e8 0f d8 f4 ff       	call   0x404f90
  4b7781:	8d 4d a4             	lea    ecx,[ebp-0x5c]
  4b7784:	e8 e7 a0 f4 ff       	call   0x401870
  4b7789:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  4b778d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b7790:	52                   	push   edx
  4b7791:	8d 8d 4c fe ff ff    	lea    ecx,[ebp-0x1b4]
  4b7797:	e8 64 d7 f4 ff       	call   0x404f00
  4b779c:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  4b77a0:	6a 5c                	push   0x5c
  4b77a2:	8d 45 a4             	lea    eax,[ebp-0x5c]
  4b77a5:	50                   	push   eax
  4b77a6:	8d 8d 4c fe ff ff    	lea    ecx,[ebp-0x1b4]
  4b77ac:	51                   	push   ecx
  4b77ad:	e8 3e 9c f4 ff       	call   0x4013f0
  4b77b2:	83 c4 0c             	add    esp,0xc
  4b77b5:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  4b77b9:	8d 8d 4c fe ff ff    	lea    ecx,[ebp-0x1b4]
  4b77bf:	e8 cc d7 f4 ff       	call   0x404f90
  4b77c4:	8d 4d bc             	lea    ecx,[ebp-0x44]
  4b77c7:	e8 34 a1 f4 ff       	call   0x401900
  4b77cc:	8b f0                	mov    esi,eax
  4b77ce:	83 c6 01             	add    esi,0x1
  4b77d1:	8d 4d a4             	lea    ecx,[ebp-0x5c]
  4b77d4:	e8 27 a1 f4 ff       	call   0x401900
  4b77d9:	3b f0                	cmp    esi,eax
  4b77db:	74 20                	je     0x4b77fd
  4b77dd:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4b77e1:	8d 4d a4             	lea    ecx,[ebp-0x5c]
  4b77e4:	e8 f7 a0 f4 ff       	call   0x4018e0
  4b77e9:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b77f0:	8d 4d bc             	lea    ecx,[ebp-0x44]
  4b77f3:	e8 e8 a0 f4 ff       	call   0x4018e0
  4b77f8:	e9 b2 fe ff ff       	jmp    0x4b76af
  4b77fd:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4b7801:	8d 4d a4             	lea    ecx,[ebp-0x5c]
  4b7804:	e8 d7 a0 f4 ff       	call   0x4018e0
  4b7809:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b7810:	8d 4d bc             	lea    ecx,[ebp-0x44]
  4b7813:	e8 c8 a0 f4 ff       	call   0x4018e0
  4b7818:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  4b781c:	0f 84 85 02 00 00    	je     0x4b7aa7
  4b7822:	c6 85 94 fe ff ff 00 	mov    BYTE PTR [ebp-0x16c],0x0
  4b7829:	68 03 01 00 00       	push   0x103
  4b782e:	6a 00                	push   0x0
  4b7830:	8d 95 95 fe ff ff    	lea    edx,[ebp-0x16b]
  4b7836:	52                   	push   edx
  4b7837:	e8 54 0a fd ff       	call   0x488290
  4b783c:	83 c4 0c             	add    esp,0xc
  4b783f:	68 04 01 00 00       	push   0x104
  4b7844:	8d 85 94 fe ff ff    	lea    eax,[ebp-0x16c]
  4b784a:	50                   	push   eax
  4b784b:	6a 00                	push   0x0
  4b784d:	6a 00                	push   0x0
  4b784f:	6a 00                	push   0x0
  4b7851:	6a 00                	push   0x0
  4b7853:	6a 00                	push   0x0
  4b7855:	6a 00                	push   0x0
  4b7857:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b785a:	51                   	push   ecx
  4b785b:	e8 dd 5e fd ff       	call   0x48d73d
  4b7860:	83 c4 24             	add    esp,0x24
  4b7863:	8d 95 94 fe ff ff    	lea    edx,[ebp-0x16c]
  4b7869:	52                   	push   edx
  4b786a:	e8 41 13 fd ff       	call   0x488bb0
  4b786f:	83 c4 04             	add    esp,0x4
  4b7872:	83 f8 01             	cmp    eax,0x1
  4b7875:	0f 86 1d 01 00 00    	jbe    0x4b7998
  4b787b:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b787e:	83 c1 40             	add    ecx,0x40
  4b7881:	e8 ea d6 f4 ff       	call   0x404f70
  4b7886:	50                   	push   eax
  4b7887:	8d 85 95 fe ff ff    	lea    eax,[ebp-0x16b]
  4b788d:	50                   	push   eax
  4b788e:	e8 a0 4c fd ff       	call   0x48c533
  4b7893:	83 c4 08             	add    esp,0x8
  4b7896:	85 c0                	test   eax,eax
  4b7898:	0f 84 f4 00 00 00    	je     0x4b7992
  4b789e:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b78a1:	83 c1 5c             	add    ecx,0x5c
  4b78a4:	e8 c7 d6 f4 ff       	call   0x404f70
  4b78a9:	50                   	push   eax
  4b78aa:	8d 8d 95 fe ff ff    	lea    ecx,[ebp-0x16b]
  4b78b0:	51                   	push   ecx
  4b78b1:	e8 7d 4c fd ff       	call   0x48c533
  4b78b6:	83 c4 08             	add    esp,0x8
  4b78b9:	85 c0                	test   eax,eax
  4b78bb:	0f 84 d1 00 00 00    	je     0x4b7992
  4b78c1:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b78c4:	83 c1 78             	add    ecx,0x78
  4b78c7:	e8 a4 d6 f4 ff       	call   0x404f70
  4b78cc:	50                   	push   eax
  4b78cd:	8d 95 95 fe ff ff    	lea    edx,[ebp-0x16b]
  4b78d3:	52                   	push   edx
  4b78d4:	e8 5a 4c fd ff       	call   0x48c533
  4b78d9:	83 c4 08             	add    esp,0x8
  4b78dc:	85 c0                	test   eax,eax
  4b78de:	0f 84 ae 00 00 00    	je     0x4b7992
  4b78e4:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b78e7:	81 c1 94 00 00 00    	add    ecx,0x94
  4b78ed:	e8 7e d6 f4 ff       	call   0x404f70
  4b78f2:	50                   	push   eax
  4b78f3:	8d 85 95 fe ff ff    	lea    eax,[ebp-0x16b]
  4b78f9:	50                   	push   eax
  4b78fa:	e8 34 4c fd ff       	call   0x48c533
  4b78ff:	83 c4 08             	add    esp,0x8
  4b7902:	85 c0                	test   eax,eax
  4b7904:	0f 84 88 00 00 00    	je     0x4b7992
  4b790a:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b790d:	81 c1 b0 00 00 00    	add    ecx,0xb0
  4b7913:	e8 58 d6 f4 ff       	call   0x404f70
  4b7918:	50                   	push   eax
  4b7919:	8d 8d 95 fe ff ff    	lea    ecx,[ebp-0x16b]
  4b791f:	51                   	push   ecx
  4b7920:	e8 0e 4c fd ff       	call   0x48c533
  4b7925:	83 c4 08             	add    esp,0x8
  4b7928:	85 c0                	test   eax,eax
  4b792a:	74 66                	je     0x4b7992
  4b792c:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b792f:	81 c1 cc 00 00 00    	add    ecx,0xcc
  4b7935:	e8 36 d6 f4 ff       	call   0x404f70
  4b793a:	50                   	push   eax
  4b793b:	8d 95 95 fe ff ff    	lea    edx,[ebp-0x16b]
  4b7941:	52                   	push   edx
  4b7942:	e8 ec 4b fd ff       	call   0x48c533
  4b7947:	83 c4 08             	add    esp,0x8
  4b794a:	85 c0                	test   eax,eax
  4b794c:	74 44                	je     0x4b7992
  4b794e:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b7951:	81 c1 e8 00 00 00    	add    ecx,0xe8
  4b7957:	e8 14 d6 f4 ff       	call   0x404f70
  4b795c:	50                   	push   eax
  4b795d:	8d 85 95 fe ff ff    	lea    eax,[ebp-0x16b]
  4b7963:	50                   	push   eax
  4b7964:	e8 ca 4b fd ff       	call   0x48c533
  4b7969:	83 c4 08             	add    esp,0x8
  4b796c:	85 c0                	test   eax,eax
  4b796e:	74 22                	je     0x4b7992
  4b7970:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b7973:	81 c1 04 01 00 00    	add    ecx,0x104
  4b7979:	e8 f2 d5 f4 ff       	call   0x404f70
  4b797e:	50                   	push   eax
  4b797f:	8d 8d 95 fe ff ff    	lea    ecx,[ebp-0x16b]
  4b7985:	51                   	push   ecx
  4b7986:	e8 a8 4b fd ff       	call   0x48c533
  4b798b:	83 c4 08             	add    esp,0x8
  4b798e:	85 c0                	test   eax,eax
  4b7990:	75 06                	jne    0x4b7998
  4b7992:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  4b7995:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  4b7998:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b799b:	83 c1 40             	add    ecx,0x40
  4b799e:	e8 cd d5 f4 ff       	call   0x404f70
  4b79a3:	50                   	push   eax
  4b79a4:	68 5c de 4c 00       	push   0x4cde5c
  4b79a9:	e8 85 4b fd ff       	call   0x48c533
  4b79ae:	83 c4 08             	add    esp,0x8
  4b79b1:	85 c0                	test   eax,eax
  4b79b3:	0f 84 e6 00 00 00    	je     0x4b7a9f
  4b79b9:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b79bc:	83 c1 5c             	add    ecx,0x5c
  4b79bf:	e8 ac d5 f4 ff       	call   0x404f70
  4b79c4:	50                   	push   eax
  4b79c5:	68 28 10 4d 00       	push   0x4d1028
  4b79ca:	e8 64 4b fd ff       	call   0x48c533
  4b79cf:	83 c4 08             	add    esp,0x8
  4b79d2:	85 c0                	test   eax,eax
  4b79d4:	0f 84 c5 00 00 00    	je     0x4b7a9f
  4b79da:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b79dd:	83 c1 78             	add    ecx,0x78
  4b79e0:	e8 8b d5 f4 ff       	call   0x404f70
  4b79e5:	50                   	push   eax
  4b79e6:	68 2c 10 4d 00       	push   0x4d102c
  4b79eb:	e8 43 4b fd ff       	call   0x48c533
  4b79f0:	83 c4 08             	add    esp,0x8
  4b79f3:	85 c0                	test   eax,eax
  4b79f5:	0f 84 a4 00 00 00    	je     0x4b7a9f
  4b79fb:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b79fe:	81 c1 94 00 00 00    	add    ecx,0x94
  4b7a04:	e8 67 d5 f4 ff       	call   0x404f70
  4b7a09:	50                   	push   eax
  4b7a0a:	68 30 10 4d 00       	push   0x4d1030
  4b7a0f:	e8 1f 4b fd ff       	call   0x48c533
  4b7a14:	83 c4 08             	add    esp,0x8
  4b7a17:	85 c0                	test   eax,eax
  4b7a19:	0f 84 80 00 00 00    	je     0x4b7a9f
  4b7a1f:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b7a22:	81 c1 b0 00 00 00    	add    ecx,0xb0
  4b7a28:	e8 43 d5 f4 ff       	call   0x404f70
  4b7a2d:	50                   	push   eax
  4b7a2e:	68 34 10 4d 00       	push   0x4d1034
  4b7a33:	e8 fb 4a fd ff       	call   0x48c533
  4b7a38:	83 c4 08             	add    esp,0x8
  4b7a3b:	85 c0                	test   eax,eax
  4b7a3d:	74 60                	je     0x4b7a9f
  4b7a3f:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b7a42:	81 c1 cc 00 00 00    	add    ecx,0xcc
  4b7a48:	e8 23 d5 f4 ff       	call   0x404f70
  4b7a4d:	50                   	push   eax
  4b7a4e:	68 38 10 4d 00       	push   0x4d1038
  4b7a53:	e8 db 4a fd ff       	call   0x48c533
  4b7a58:	83 c4 08             	add    esp,0x8
  4b7a5b:	85 c0                	test   eax,eax
  4b7a5d:	74 40                	je     0x4b7a9f
  4b7a5f:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b7a62:	81 c1 e8 00 00 00    	add    ecx,0xe8
  4b7a68:	e8 03 d5 f4 ff       	call   0x404f70
  4b7a6d:	50                   	push   eax
  4b7a6e:	68 3c 10 4d 00       	push   0x4d103c
  4b7a73:	e8 bb 4a fd ff       	call   0x48c533
  4b7a78:	83 c4 08             	add    esp,0x8
  4b7a7b:	85 c0                	test   eax,eax
  4b7a7d:	74 20                	je     0x4b7a9f
  4b7a7f:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b7a82:	81 c1 04 01 00 00    	add    ecx,0x104
  4b7a88:	e8 e3 d4 f4 ff       	call   0x404f70
  4b7a8d:	50                   	push   eax
  4b7a8e:	68 40 10 4d 00       	push   0x4d1040
  4b7a93:	e8 9b 4a fd ff       	call   0x48c533
  4b7a98:	83 c4 08             	add    esp,0x8
  4b7a9b:	85 c0                	test   eax,eax
  4b7a9d:	75 06                	jne    0x4b7aa5
  4b7a9f:	8b 45 d4             	mov    eax,DWORD PTR [ebp-0x2c]
  4b7aa2:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4b7aa5:	eb 06                	jmp    0x4b7aad
  4b7aa7:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b7aaa:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  4b7aad:	e9 fd fb ff ff       	jmp    0x4b76af
  4b7ab2:	83 7d f0 00          	cmp    DWORD PTR [ebp-0x10],0x0
  4b7ab6:	74 05                	je     0x4b7abd
  4b7ab8:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  4b7abb:	eb 02                	jmp    0x4b7abf
  4b7abd:	33 c0                	xor    eax,eax
  4b7abf:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b7ac2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b7ac9:	59                   	pop    ecx
  4b7aca:	5e                   	pop    esi
  4b7acb:	8b 4d a0             	mov    ecx,DWORD PTR [ebp-0x60]
  4b7ace:	33 cd                	xor    ecx,ebp
  4b7ad0:	e8 ff f8 fc ff       	call   0x4873d4
  4b7ad5:	8b e5                	mov    esp,ebp
  4b7ad7:	5d                   	pop    ebp
  4b7ad8:	c2 08 00             	ret    0x8

; launcher: patcher/plain-file-provider-call-and-writer 0x4ba541..0x4ba769 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004ba541 <.data>:
  4ba541:	8d 8d 64 ff ff ff    	lea    ecx,[ebp-0x9c]
  4ba547:	e8 24 73 f4 ff       	call   0x401870
  4ba54c:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  4ba553:	6a 5c                	push   0x5c
  4ba555:	8d 8d 64 ff ff ff    	lea    ecx,[ebp-0x9c]
  4ba55b:	51                   	push   ecx
  4ba55c:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  4ba55f:	52                   	push   edx
  4ba560:	e8 8b 6e f4 ff       	call   0x4013f0
  4ba565:	83 c4 0c             	add    esp,0xc
  4ba568:	8d 8d 7c ff ff ff    	lea    ecx,[ebp-0x84]
  4ba56e:	e8 1d ac f4 ff       	call   0x405190
  4ba573:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  4ba577:	c7 85 60 ff ff ff 00 	mov    DWORD PTR [ebp-0xa0],0x0
  4ba57e:	00 00 00 
  4ba581:	eb 0f                	jmp    0x4ba592
  4ba583:	8b 85 60 ff ff ff    	mov    eax,DWORD PTR [ebp-0xa0]
  4ba589:	83 c0 01             	add    eax,0x1
  4ba58c:	89 85 60 ff ff ff    	mov    DWORD PTR [ebp-0xa0],eax
  4ba592:	8d 8d 64 ff ff ff    	lea    ecx,[ebp-0x9c]
  4ba598:	e8 63 73 f4 ff       	call   0x401900
  4ba59d:	83 e8 01             	sub    eax,0x1
  4ba5a0:	39 85 60 ff ff ff    	cmp    DWORD PTR [ebp-0xa0],eax
  4ba5a6:	73 36                	jae    0x4ba5de
  4ba5a8:	83 bd 60 ff ff ff 00 	cmp    DWORD PTR [ebp-0xa0],0x0
  4ba5af:	76 0d                	jbe    0x4ba5be
  4ba5b1:	6a 5c                	push   0x5c
  4ba5b3:	8d 8d 7c ff ff ff    	lea    ecx,[ebp-0x84]
  4ba5b9:	e8 c2 70 f4 ff       	call   0x401680
  4ba5be:	8b 8d 60 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xa0]
  4ba5c4:	51                   	push   ecx
  4ba5c5:	8d 8d 64 ff ff ff    	lea    ecx,[ebp-0x9c]
  4ba5cb:	e8 70 73 f4 ff       	call   0x401940
  4ba5d0:	50                   	push   eax
  4ba5d1:	8d 8d 7c ff ff ff    	lea    ecx,[ebp-0x84]
  4ba5d7:	e8 44 a2 f4 ff       	call   0x404820
  4ba5dc:	eb a5                	jmp    0x4ba583
  4ba5de:	8d 8d 7c ff ff ff    	lea    ecx,[ebp-0x84]
  4ba5e4:	e8 87 a9 f4 ff       	call   0x404f70
  4ba5e9:	50                   	push   eax
  4ba5ea:	8b 8d 48 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xb8]
  4ba5f0:	e8 0b f2 ff ff       	call   0x4b9800
  4ba5f5:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  4ba5f9:	8d 8d 7c ff ff ff    	lea    ecx,[ebp-0x84]
  4ba5ff:	e8 8c a9 f4 ff       	call   0x404f90
  4ba604:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4ba60b:	8d 8d 64 ff ff ff    	lea    ecx,[ebp-0x9c]
  4ba611:	e8 ca 72 f4 ff       	call   0x4018e0
  4ba616:	c7 45 9c 00 00 00 00 	mov    DWORD PTR [ebp-0x64],0x0
  4ba61d:	c7 45 98 00 00 00 00 	mov    DWORD PTR [ebp-0x68],0x0
  4ba624:	8d 55 9c             	lea    edx,[ebp-0x64]
  4ba627:	52                   	push   edx
  4ba628:	8d 45 98             	lea    eax,[ebp-0x68]
  4ba62b:	50                   	push   eax
  4ba62c:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4ba62f:	e8 3c a9 f4 ff       	call   0x404f70
  4ba634:	50                   	push   eax
  4ba635:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4ba638:	51                   	push   ecx
  4ba639:	8b 95 48 ff ff ff    	mov    edx,DWORD PTR [ebp-0xb8]
  4ba63f:	8b 02                	mov    eax,DWORD PTR [edx]
  4ba641:	8b 8d 48 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xb8]
  4ba647:	8b 09                	mov    ecx,DWORD PTR [ecx]
  4ba649:	8b 10                	mov    edx,DWORD PTR [eax]
  4ba64b:	8b 02                	mov    eax,DWORD PTR [edx]
  4ba64d:	ff d0                	call   eax
  4ba64f:	85 c0                	test   eax,eax
  4ba651:	75 1b                	jne    0x4ba66e
  4ba653:	68 da 01 00 00       	push   0x1da
  4ba658:	8b 8d 48 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xb8]
  4ba65e:	e8 1d ef ff ff       	call   0x4b9580
  4ba663:	33 c0                	xor    eax,eax
  4ba665:	e9 e4 00 00 00       	jmp    0x4ba74e
  4ba66a:	33 c9                	xor    ecx,ecx
  4ba66c:	75 e5                	jne    0x4ba653
  4ba66e:	83 7d 98 00          	cmp    DWORD PTR [ebp-0x68],0x0
  4ba672:	75 1b                	jne    0x4ba68f
  4ba674:	68 df 01 00 00       	push   0x1df
  4ba679:	8b 8d 48 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xb8]
  4ba67f:	e8 fc ee ff ff       	call   0x4b9580
  4ba684:	33 c0                	xor    eax,eax
  4ba686:	e9 c3 00 00 00       	jmp    0x4ba74e
  4ba68b:	33 d2                	xor    edx,edx
  4ba68d:	75 e5                	jne    0x4ba674
  4ba68f:	c7 45 a0 00 00 00 00 	mov    DWORD PTR [ebp-0x60],0x0
  4ba696:	68 c0 22 4d 00       	push   0x4d22c0
  4ba69b:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4ba69e:	e8 cd a8 f4 ff       	call   0x404f70
  4ba6a3:	50                   	push   eax
  4ba6a4:	e8 14 29 fd ff       	call   0x48cfbd
  4ba6a9:	83 c4 08             	add    esp,0x8
  4ba6ac:	89 45 a4             	mov    DWORD PTR [ebp-0x5c],eax
  4ba6af:	83 7d a4 00          	cmp    DWORD PTR [ebp-0x5c],0x0
  4ba6b3:	74 35                	je     0x4ba6ea
  4ba6b5:	83 7d 9c 00          	cmp    DWORD PTR [ebp-0x64],0x0
  4ba6b9:	76 21                	jbe    0x4ba6dc
  4ba6bb:	8b 45 a4             	mov    eax,DWORD PTR [ebp-0x5c]
  4ba6be:	50                   	push   eax
  4ba6bf:	6a 01                	push   0x1
  4ba6c1:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  4ba6c4:	51                   	push   ecx
  4ba6c5:	8b 55 98             	mov    edx,DWORD PTR [ebp-0x68]
  4ba6c8:	52                   	push   edx
  4ba6c9:	e8 24 d1 fc ff       	call   0x4877f2
  4ba6ce:	83 c4 10             	add    esp,0x10
  4ba6d1:	85 c0                	test   eax,eax
  4ba6d3:	75 07                	jne    0x4ba6dc
  4ba6d5:	c7 45 a0 01 00 00 00 	mov    DWORD PTR [ebp-0x60],0x1
  4ba6dc:	8b 45 a4             	mov    eax,DWORD PTR [ebp-0x5c]
  4ba6df:	50                   	push   eax
  4ba6e0:	e8 2f cf fc ff       	call   0x487614
  4ba6e5:	83 c4 04             	add    esp,0x4
  4ba6e8:	eb 07                	jmp    0x4ba6f1
  4ba6ea:	c7 45 a0 01 00 00 00 	mov    DWORD PTR [ebp-0x60],0x1
  4ba6f1:	8b 4d 98             	mov    ecx,DWORD PTR [ebp-0x68]
  4ba6f4:	51                   	push   ecx
  4ba6f5:	e8 b6 ed ff ff       	call   0x4b94b0
  4ba6fa:	83 c4 04             	add    esp,0x4
  4ba6fd:	83 7d a0 00          	cmp    DWORD PTR [ebp-0x60],0x0
  4ba701:	74 30                	je     0x4ba733
  4ba703:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4ba706:	e8 65 a8 f4 ff       	call   0x404f70
  4ba70b:	50                   	push   eax
  4ba70c:	68 c4 22 4d 00       	push   0x4d22c4
  4ba711:	e8 4f 24 fd ff       	call   0x48cb65
  4ba716:	83 c4 08             	add    esp,0x8
  4ba719:	68 f8 01 00 00       	push   0x1f8
  4ba71e:	8b 8d 48 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xb8]
  4ba724:	e8 57 ee ff ff       	call   0x4b9580
  4ba729:	33 c0                	xor    eax,eax
  4ba72b:	eb 21                	jmp    0x4ba74e
  4ba72d:	33 d2                	xor    edx,edx
  4ba72f:	75 e8                	jne    0x4ba719
  4ba731:	eb 1b                	jmp    0x4ba74e
  4ba733:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4ba736:	e8 35 a8 f4 ff       	call   0x404f70
  4ba73b:	50                   	push   eax
  4ba73c:	68 e4 22 4d 00       	push   0x4d22e4
  4ba741:	e8 1f 24 fd ff       	call   0x48cb65
  4ba746:	83 c4 08             	add    esp,0x8
  4ba749:	b8 01 00 00 00       	mov    eax,0x1
  4ba74e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4ba751:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4ba758:	59                   	pop    ecx
  4ba759:	8b 4d c8             	mov    ecx,DWORD PTR [ebp-0x38]
  4ba75c:	33 cd                	xor    ecx,ebp
  4ba75e:	e8 71 cc fc ff       	call   0x4873d4
  4ba763:	8b e5                	mov    esp,ebp
  4ba765:	5d                   	pop    ebp
  4ba766:	c2 0c 00             	ret    0xc

; launcher: patcher/provider-relative-name-gzip-http-decode-result 0x47a5c0..0x47aed9 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0047a5c0 <.data>:
  47a5c0:	55                   	push   ebp
  47a5c1:	8b ec                	mov    ebp,esp
  47a5c3:	6a ff                	push   0xffffffff
  47a5c5:	68 04 f7 4b 00       	push   0x4bf704
  47a5ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47a5d0:	50                   	push   eax
  47a5d1:	81 ec 34 01 00 00    	sub    esp,0x134
  47a5d7:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  47a5dc:	33 c5                	xor    eax,ebp
  47a5de:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  47a5e1:	50                   	push   eax
  47a5e2:	8d 45 f4             	lea    eax,[ebp-0xc]
  47a5e5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47a5eb:	89 8d d0 fe ff ff    	mov    DWORD PTR [ebp-0x130],ecx
  47a5f1:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  47a5f4:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  47a5fa:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  47a5fd:	c7 01 00 00 00 00    	mov    DWORD PTR [ecx],0x0
  47a603:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  47a606:	52                   	push   edx
  47a607:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47a60d:	e8 ee a8 f8 ff       	call   0x404f00
  47a612:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47a619:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47a61c:	e8 6f ab f8 ff       	call   0x405190
  47a621:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47a625:	c7 85 74 ff ff ff 00 	mov    DWORD PTR [ebp-0x8c],0x0
  47a62c:	00 00 00 
  47a62f:	6a 2f                	push   0x2f
  47a631:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  47a634:	50                   	push   eax
  47a635:	e8 f6 29 01 00       	call   0x48d030
  47a63a:	83 c4 08             	add    esp,0x8
  47a63d:	89 85 18 ff ff ff    	mov    DWORD PTR [ebp-0xe8],eax
  47a643:	83 bd 18 ff ff ff 00 	cmp    DWORD PTR [ebp-0xe8],0x0
  47a64a:	74 12                	je     0x47a65e
  47a64c:	8b 8d 18 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xe8]
  47a652:	2b 4d 0c             	sub    ecx,DWORD PTR [ebp+0xc]
  47a655:	83 c1 01             	add    ecx,0x1
  47a658:	89 8d 74 ff ff ff    	mov    DWORD PTR [ebp-0x8c],ecx
  47a65e:	6a 5c                	push   0x5c
  47a660:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  47a663:	52                   	push   edx
  47a664:	e8 c7 29 01 00       	call   0x48d030
  47a669:	83 c4 08             	add    esp,0x8
  47a66c:	89 85 18 ff ff ff    	mov    DWORD PTR [ebp-0xe8],eax
  47a672:	83 bd 18 ff ff ff 00 	cmp    DWORD PTR [ebp-0xe8],0x0
  47a679:	74 2c                	je     0x47a6a7
  47a67b:	8b 85 18 ff ff ff    	mov    eax,DWORD PTR [ebp-0xe8]
  47a681:	2b 45 0c             	sub    eax,DWORD PTR [ebp+0xc]
  47a684:	83 c0 01             	add    eax,0x1
  47a687:	89 85 14 ff ff ff    	mov    DWORD PTR [ebp-0xec],eax
  47a68d:	8b 8d 74 ff ff ff    	mov    ecx,DWORD PTR [ebp-0x8c]
  47a693:	3b 8d 14 ff ff ff    	cmp    ecx,DWORD PTR [ebp-0xec]
  47a699:	7d 0c                	jge    0x47a6a7
  47a69b:	8b 95 14 ff ff ff    	mov    edx,DWORD PTR [ebp-0xec]
  47a6a1:	89 95 74 ff ff ff    	mov    DWORD PTR [ebp-0x8c],edx
  47a6a7:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  47a6aa:	03 85 74 ff ff ff    	add    eax,DWORD PTR [ebp-0x8c]
  47a6b0:	89 85 1c ff ff ff    	mov    DWORD PTR [ebp-0xe4],eax
  47a6b6:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47a6bc:	51                   	push   ecx
  47a6bd:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47a6c3:	e8 78 9f f8 ff       	call   0x404640
  47a6c8:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47a6cc:	8b 95 1c ff ff ff    	mov    edx,DWORD PTR [ebp-0xe4]
  47a6d2:	52                   	push   edx
  47a6d3:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47a6d9:	e8 22 a8 f8 ff       	call   0x404f00
  47a6de:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47a6e2:	b8 01 00 00 00       	mov    eax,0x1
  47a6e7:	85 c0                	test   eax,eax
  47a6e9:	74 20                	je     0x47a70b
  47a6eb:	68 14 4f 4d 00       	push   0x4d4f14
  47a6f0:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47a6f6:	e8 65 6f f8 ff       	call   0x401660
  47a6fb:	68 14 4f 4d 00       	push   0x4d4f14
  47a700:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47a706:	e8 55 6f f8 ff       	call   0x401660
  47a70b:	8b 8d d0 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x130]
  47a711:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  47a714:	c7 82 70 01 00 00 04 	mov    DWORD PTR [edx+0x170],0x4
  47a71b:	00 00 00 
  47a71e:	83 3d 14 e5 4e 00 00 	cmp    DWORD PTR ds:0x4ee514,0x0
  47a725:	75 51                	jne    0x47a778
  47a727:	c7 85 fc fe ff ff 01 	mov    DWORD PTR [ebp-0x104],0x1
  47a72e:	00 00 00 
  47a731:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47a735:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47a73b:	e8 50 a8 f8 ff       	call   0x404f90
  47a740:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47a744:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47a74a:	e8 41 a8 f8 ff       	call   0x404f90
  47a74f:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47a753:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47a756:	e8 35 a8 f8 ff       	call   0x404f90
  47a75b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47a762:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47a768:	e8 23 a8 f8 ff       	call   0x404f90
  47a76d:	8b 85 fc fe ff ff    	mov    eax,DWORD PTR [ebp-0x104]
  47a773:	e9 46 07 00 00       	jmp    0x47aebe
  47a778:	83 ec 1c             	sub    esp,0x1c
  47a77b:	8b cc                	mov    ecx,esp
  47a77d:	89 a5 f8 fe ff ff    	mov    DWORD PTR [ebp-0x108],esp
  47a783:	8d 85 3c ff ff ff    	lea    eax,[ebp-0xc4]
  47a789:	50                   	push   eax
  47a78a:	e8 b1 9e f8 ff       	call   0x404640
  47a78f:	89 85 cc fe ff ff    	mov    DWORD PTR [ebp-0x134],eax
  47a795:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47a798:	51                   	push   ecx
  47a799:	e8 92 56 00 00       	call   0x47fe30
  47a79e:	83 c4 20             	add    esp,0x20
  47a7a1:	89 85 c8 fe ff ff    	mov    DWORD PTR [ebp-0x138],eax
  47a7a7:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47a7ab:	c7 85 10 ff ff ff 00 	mov    DWORD PTR [ebp-0xf0],0x0
  47a7b2:	00 00 00 
  47a7b5:	eb 0f                	jmp    0x47a7c6
  47a7b7:	8b 95 10 ff ff ff    	mov    edx,DWORD PTR [ebp-0xf0]
  47a7bd:	83 c2 01             	add    edx,0x1
  47a7c0:	89 95 10 ff ff ff    	mov    DWORD PTR [ebp-0xf0],edx
  47a7c6:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47a7c9:	e8 82 1c fd ff       	call   0x44c450
  47a7ce:	39 85 10 ff ff ff    	cmp    DWORD PTR [ebp-0xf0],eax
  47a7d4:	73 30                	jae    0x47a806
  47a7d6:	8b 85 10 ff ff ff    	mov    eax,DWORD PTR [ebp-0xf0]
  47a7dc:	50                   	push   eax
  47a7dd:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47a7e0:	e8 eb 7b 00 00       	call   0x4823d0
  47a7e5:	0f b7 08             	movzx  ecx,WORD PTR [eax]
  47a7e8:	83 f9 5c             	cmp    ecx,0x5c
  47a7eb:	75 17                	jne    0x47a804
  47a7ed:	8b 95 10 ff ff ff    	mov    edx,DWORD PTR [ebp-0xf0]
  47a7f3:	52                   	push   edx
  47a7f4:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47a7f7:	e8 d4 7b 00 00       	call   0x4823d0
  47a7fc:	b9 2f 00 00 00       	mov    ecx,0x2f
  47a801:	66 89 08             	mov    WORD PTR [eax],cx
  47a804:	eb b1                	jmp    0x47a7b7
  47a806:	8b 15 e0 a4 4e 00    	mov    edx,DWORD PTR ds:0x4ea4e0
  47a80c:	52                   	push   edx
  47a80d:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47a813:	e8 e8 a6 f8 ff       	call   0x404f00
  47a818:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47a81c:	8d 85 78 ff ff ff    	lea    eax,[ebp-0x88]
  47a822:	50                   	push   eax
  47a823:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47a829:	e8 f2 9f f8 ff       	call   0x404820
  47a82e:	c7 85 0c ff ff ff 00 	mov    DWORD PTR [ebp-0xf4],0x0
  47a835:	00 00 00 
  47a838:	eb 0f                	jmp    0x47a849
  47a83a:	8b 8d 0c ff ff ff    	mov    ecx,DWORD PTR [ebp-0xf4]
  47a840:	83 c1 01             	add    ecx,0x1
  47a843:	89 8d 0c ff ff ff    	mov    DWORD PTR [ebp-0xf4],ecx
  47a849:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47a84f:	e8 2c a0 f8 ff       	call   0x404880
  47a854:	39 85 0c ff ff ff    	cmp    DWORD PTR [ebp-0xf4],eax
  47a85a:	73 31                	jae    0x47a88d
  47a85c:	8b 95 0c ff ff ff    	mov    edx,DWORD PTR [ebp-0xf4]
  47a862:	52                   	push   edx
  47a863:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47a869:	e8 82 af f8 ff       	call   0x4057f0
  47a86e:	0f be 00             	movsx  eax,BYTE PTR [eax]
  47a871:	83 f8 5c             	cmp    eax,0x5c
  47a874:	75 15                	jne    0x47a88b
  47a876:	8b 8d 0c ff ff ff    	mov    ecx,DWORD PTR [ebp-0xf4]
  47a87c:	51                   	push   ecx
  47a87d:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47a883:	e8 68 af f8 ff       	call   0x4057f0
  47a888:	c6 00 2f             	mov    BYTE PTR [eax],0x2f
  47a88b:	eb ad                	jmp    0x47a83a
  47a88d:	83 ec 1c             	sub    esp,0x1c
  47a890:	8b cc                	mov    ecx,esp
  47a892:	89 a5 f4 fe ff ff    	mov    DWORD PTR [ebp-0x10c],esp
  47a898:	8d 95 20 ff ff ff    	lea    edx,[ebp-0xe0]
  47a89e:	52                   	push   edx
  47a89f:	e8 9c 9d f8 ff       	call   0x404640
  47a8a4:	89 85 c4 fe ff ff    	mov    DWORD PTR [ebp-0x13c],eax
  47a8aa:	8d 45 94             	lea    eax,[ebp-0x6c]
  47a8ad:	50                   	push   eax
  47a8ae:	e8 7d 55 00 00       	call   0x47fe30
  47a8b3:	83 c4 20             	add    esp,0x20
  47a8b6:	89 85 c0 fe ff ff    	mov    DWORD PTR [ebp-0x140],eax
  47a8bc:	c6 45 fc 06          	mov    BYTE PTR [ebp-0x4],0x6
  47a8c0:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47a8c3:	e8 58 36 fa ff       	call   0x41df20
  47a8c8:	50                   	push   eax
  47a8c9:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47a8cc:	e8 4f 36 fa ff       	call   0x41df20
  47a8d1:	50                   	push   eax
  47a8d2:	8b 8d d0 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x130]
  47a8d8:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  47a8db:	e8 e0 e1 ff ff       	call   0x478ac0
  47a8e0:	85 c0                	test   eax,eax
  47a8e2:	75 78                	jne    0x47a95c
  47a8e4:	c7 85 f0 fe ff ff 00 	mov    DWORD PTR [ebp-0x110],0x0
  47a8eb:	00 00 00 
  47a8ee:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47a8f2:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47a8f5:	e8 c6 35 fa ff       	call   0x41dec0
  47a8fa:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47a8fe:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47a904:	e8 87 a6 f8 ff       	call   0x404f90
  47a909:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47a90d:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47a910:	e8 ab 35 fa ff       	call   0x41dec0
  47a915:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47a919:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47a91f:	e8 6c a6 f8 ff       	call   0x404f90
  47a924:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47a928:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47a92e:	e8 5d a6 f8 ff       	call   0x404f90
  47a933:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47a937:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47a93a:	e8 51 a6 f8 ff       	call   0x404f90
  47a93f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47a946:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47a94c:	e8 3f a6 f8 ff       	call   0x404f90
  47a951:	8b 85 f0 fe ff ff    	mov    eax,DWORD PTR [ebp-0x110]
  47a957:	e9 62 05 00 00       	jmp    0x47aebe
  47a95c:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  47a963:	68 94 d4 4c 00       	push   0x4cd494
  47a968:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47a96e:	e8 fd a5 f8 ff       	call   0x404f70
  47a973:	50                   	push   eax
  47a974:	8d 55 ec             	lea    edx,[ebp-0x14]
  47a977:	52                   	push   edx
  47a978:	e8 57 26 01 00       	call   0x48cfd4
  47a97d:	83 c4 0c             	add    esp,0xc
  47a980:	83 7d ec 00          	cmp    DWORD PTR [ebp-0x14],0x0
  47a984:	75 78                	jne    0x47a9fe
  47a986:	c7 85 ec fe ff ff 00 	mov    DWORD PTR [ebp-0x114],0x0
  47a98d:	00 00 00 
  47a990:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47a994:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47a997:	e8 24 35 fa ff       	call   0x41dec0
  47a99c:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47a9a0:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47a9a6:	e8 e5 a5 f8 ff       	call   0x404f90
  47a9ab:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47a9af:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47a9b2:	e8 09 35 fa ff       	call   0x41dec0
  47a9b7:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47a9bb:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47a9c1:	e8 ca a5 f8 ff       	call   0x404f90
  47a9c6:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47a9ca:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47a9d0:	e8 bb a5 f8 ff       	call   0x404f90
  47a9d5:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47a9d9:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47a9dc:	e8 af a5 f8 ff       	call   0x404f90
  47a9e1:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47a9e8:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47a9ee:	e8 9d a5 f8 ff       	call   0x404f90
  47a9f3:	8b 85 ec fe ff ff    	mov    eax,DWORD PTR [ebp-0x114]
  47a9f9:	e9 c0 04 00 00       	jmp    0x47aebe
  47a9fe:	8d 45 cc             	lea    eax,[ebp-0x34]
  47aa01:	50                   	push   eax
  47aa02:	8b 8d d0 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x130]
  47aa08:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  47aa0b:	81 c1 50 01 00 00    	add    ecx,0x150
  47aa11:	e8 da 0b fd ff       	call   0x44b5f0
  47aa16:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  47aa19:	52                   	push   edx
  47aa1a:	e8 a8 24 01 00       	call   0x48cec7
  47aa1f:	83 c4 04             	add    esp,0x4
  47aa22:	50                   	push   eax
  47aa23:	e8 a0 23 01 00       	call   0x48cdc8
  47aa28:	83 c4 04             	add    esp,0x4
  47aa2b:	8b 8d d0 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x130]
  47aa31:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  47aa34:	89 82 6c 01 00 00    	mov    DWORD PTR [edx+0x16c],eax
  47aa3a:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  47aa3d:	50                   	push   eax
  47aa3e:	e8 d1 cb 00 00       	call   0x487614
  47aa43:	83 c4 04             	add    esp,0x4
  47aa46:	8b 8d d0 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x130]
  47aa4c:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  47aa4f:	a1 18 e5 4e 00       	mov    eax,ds:0x4ee518
  47aa54:	03 82 6c 01 00 00    	add    eax,DWORD PTR [edx+0x16c]
  47aa5a:	a3 18 e5 4e 00       	mov    ds:0x4ee518,eax
  47aa5f:	8b 8d d0 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x130]
  47aa65:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  47aa68:	c7 82 70 01 00 00 05 	mov    DWORD PTR [edx+0x170],0x5
  47aa6f:	00 00 00 
  47aa72:	83 3d 14 e5 4e 00 00 	cmp    DWORD PTR ds:0x4ee514,0x0
  47aa79:	75 78                	jne    0x47aaf3
  47aa7b:	c7 85 e8 fe ff ff 01 	mov    DWORD PTR [ebp-0x118],0x1
  47aa82:	00 00 00 
  47aa85:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47aa89:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47aa8c:	e8 2f 34 fa ff       	call   0x41dec0
  47aa91:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47aa95:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47aa9b:	e8 f0 a4 f8 ff       	call   0x404f90
  47aaa0:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47aaa4:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47aaa7:	e8 14 34 fa ff       	call   0x41dec0
  47aaac:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47aab0:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47aab6:	e8 d5 a4 f8 ff       	call   0x404f90
  47aabb:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47aabf:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47aac5:	e8 c6 a4 f8 ff       	call   0x404f90
  47aaca:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47aace:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47aad1:	e8 ba a4 f8 ff       	call   0x404f90
  47aad6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47aadd:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47aae3:	e8 a8 a4 f8 ff       	call   0x404f90
  47aae8:	8b 85 e8 fe ff ff    	mov    eax,DWORD PTR [ebp-0x118]
  47aaee:	e9 cb 03 00 00       	jmp    0x47aebe
  47aaf3:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  47aafa:	b8 01 00 00 00       	mov    eax,0x1
  47aaff:	85 c0                	test   eax,eax
  47ab01:	0f 84 ae 00 00 00    	je     0x47abb5
  47ab07:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47ab0d:	e8 5e a4 f8 ff       	call   0x404f70
  47ab12:	50                   	push   eax
  47ab13:	e8 18 38 fc ff       	call   0x43e330
  47ab18:	83 c4 04             	add    esp,0x4
  47ab1b:	85 c0                	test   eax,eax
  47ab1d:	75 78                	jne    0x47ab97
  47ab1f:	c7 85 e4 fe ff ff 00 	mov    DWORD PTR [ebp-0x11c],0x0
  47ab26:	00 00 00 
  47ab29:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47ab2d:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47ab30:	e8 8b 33 fa ff       	call   0x41dec0
  47ab35:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47ab39:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47ab3f:	e8 4c a4 f8 ff       	call   0x404f90
  47ab44:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47ab48:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47ab4b:	e8 70 33 fa ff       	call   0x41dec0
  47ab50:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47ab54:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47ab5a:	e8 31 a4 f8 ff       	call   0x404f90
  47ab5f:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47ab63:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47ab69:	e8 22 a4 f8 ff       	call   0x404f90
  47ab6e:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47ab72:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47ab75:	e8 16 a4 f8 ff       	call   0x404f90
  47ab7a:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47ab81:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47ab87:	e8 04 a4 f8 ff       	call   0x404f90
  47ab8c:	8b 85 e4 fe ff ff    	mov    eax,DWORD PTR [ebp-0x11c]
  47ab92:	e9 27 03 00 00       	jmp    0x47aebe
  47ab97:	68 94 d4 4c 00       	push   0x4cd494
  47ab9c:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47aba2:	e8 c9 a3 f8 ff       	call   0x404f70
  47aba7:	50                   	push   eax
  47aba8:	e8 f3 37 fc ff       	call   0x43e3a0
  47abad:	83 c4 08             	add    esp,0x8
  47abb0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  47abb3:	eb 1c                	jmp    0x47abd1
  47abb5:	68 94 d4 4c 00       	push   0x4cd494
  47abba:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47abc0:	e8 ab a3 f8 ff       	call   0x404f70
  47abc5:	50                   	push   eax
  47abc6:	e8 45 33 fc ff       	call   0x43df10
  47abcb:	83 c4 08             	add    esp,0x8
  47abce:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  47abd1:	83 7d f0 00          	cmp    DWORD PTR [ebp-0x10],0x0
  47abd5:	75 7d                	jne    0x47ac54
  47abd7:	c7 85 e0 fe ff ff 00 	mov    DWORD PTR [ebp-0x120],0x0
  47abde:	00 00 00 
  47abe1:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47abe5:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47abe8:	e8 d3 32 fa ff       	call   0x41dec0
  47abed:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47abf1:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47abf7:	e8 94 a3 f8 ff       	call   0x404f90
  47abfc:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47ac00:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47ac03:	e8 b8 32 fa ff       	call   0x41dec0
  47ac08:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47ac0c:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47ac12:	e8 79 a3 f8 ff       	call   0x404f90
  47ac17:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47ac1b:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47ac21:	e8 6a a3 f8 ff       	call   0x404f90
  47ac26:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47ac2a:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47ac2d:	e8 5e a3 f8 ff       	call   0x404f90
  47ac32:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47ac39:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47ac3f:	e8 4c a3 f8 ff       	call   0x404f90
  47ac44:	8b 85 e0 fe ff ff    	mov    eax,DWORD PTR [ebp-0x120]
  47ac4a:	e9 6f 02 00 00       	jmp    0x47aebe
  47ac4f:	e9 f7 01 00 00       	jmp    0x47ae4b
  47ac54:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  47ac57:	51                   	push   ecx
  47ac58:	e8 83 f7 ff ff       	call   0x47a3e0
  47ac5d:	83 c4 04             	add    esp,0x4
  47ac60:	89 85 08 ff ff ff    	mov    DWORD PTR [ebp-0xf8],eax
  47ac66:	83 bd 08 ff ff ff 00 	cmp    DWORD PTR [ebp-0xf8],0x0
  47ac6d:	0f 86 f3 00 00 00    	jbe    0x47ad66
  47ac73:	8b 95 08 ff ff ff    	mov    edx,DWORD PTR [ebp-0xf8]
  47ac79:	52                   	push   edx
  47ac7a:	e8 51 e8 03 00       	call   0x4b94d0
  47ac7f:	83 c4 04             	add    esp,0x4
  47ac82:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  47ac85:	89 01                	mov    DWORD PTR [ecx],eax
  47ac87:	8b 55 14             	mov    edx,DWORD PTR [ebp+0x14]
  47ac8a:	8b 85 08 ff ff ff    	mov    eax,DWORD PTR [ebp-0xf8]
  47ac90:	89 02                	mov    DWORD PTR [edx],eax
  47ac92:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  47ac95:	51                   	push   ecx
  47ac96:	6a 01                	push   0x1
  47ac98:	8b 95 08 ff ff ff    	mov    edx,DWORD PTR [ebp-0xf8]
  47ac9e:	52                   	push   edx
  47ac9f:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  47aca2:	8b 08                	mov    ecx,DWORD PTR [eax]
  47aca4:	51                   	push   ecx
  47aca5:	e8 b6 f6 ff ff       	call   0x47a360
  47acaa:	83 c4 10             	add    esp,0x10
  47acad:	89 85 00 ff ff ff    	mov    DWORD PTR [ebp-0x100],eax
  47acb3:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  47acb6:	52                   	push   edx
  47acb7:	e8 74 f6 ff ff       	call   0x47a330
  47acbc:	83 c4 04             	add    esp,0x4
  47acbf:	83 bd 00 ff ff ff 00 	cmp    DWORD PTR [ebp-0x100],0x0
  47acc6:	0f 85 98 00 00 00    	jne    0x47ad64
  47accc:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  47accf:	8b 08                	mov    ecx,DWORD PTR [eax]
  47acd1:	51                   	push   ecx
  47acd2:	e8 d9 e7 03 00       	call   0x4b94b0
  47acd7:	83 c4 04             	add    esp,0x4
  47acda:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  47acdd:	c7 02 00 00 00 00    	mov    DWORD PTR [edx],0x0
  47ace3:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  47ace6:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  47acec:	c7 85 dc fe ff ff 00 	mov    DWORD PTR [ebp-0x124],0x0
  47acf3:	00 00 00 
  47acf6:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47acfa:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47acfd:	e8 be 31 fa ff       	call   0x41dec0
  47ad02:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47ad06:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47ad0c:	e8 7f a2 f8 ff       	call   0x404f90
  47ad11:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47ad15:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47ad18:	e8 a3 31 fa ff       	call   0x41dec0
  47ad1d:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47ad21:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47ad27:	e8 64 a2 f8 ff       	call   0x404f90
  47ad2c:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47ad30:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47ad36:	e8 55 a2 f8 ff       	call   0x404f90
  47ad3b:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47ad3f:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47ad42:	e8 49 a2 f8 ff       	call   0x404f90
  47ad47:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47ad4e:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47ad54:	e8 37 a2 f8 ff       	call   0x404f90
  47ad59:	8b 85 dc fe ff ff    	mov    eax,DWORD PTR [ebp-0x124]
  47ad5f:	e9 5a 01 00 00       	jmp    0x47aebe
  47ad64:	eb 2b                	jmp    0x47ad91
  47ad66:	8b 8d 08 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xf8]
  47ad6c:	51                   	push   ecx
  47ad6d:	e8 5e e7 03 00       	call   0x4b94d0
  47ad72:	83 c4 04             	add    esp,0x4
  47ad75:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  47ad78:	89 02                	mov    DWORD PTR [edx],eax
  47ad7a:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  47ad7d:	8b 8d 08 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xf8]
  47ad83:	89 08                	mov    DWORD PTR [eax],ecx
  47ad85:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  47ad88:	52                   	push   edx
  47ad89:	e8 a2 f5 ff ff       	call   0x47a330
  47ad8e:	83 c4 04             	add    esp,0x4
  47ad91:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47ad97:	e8 d4 a1 f8 ff       	call   0x404f70
  47ad9c:	50                   	push   eax
  47ad9d:	ff 15 b4 70 4c 00    	call   DWORD PTR ds:0x4c70b4
  47ada3:	89 85 04 ff ff ff    	mov    DWORD PTR [ebp-0xfc],eax
  47ada9:	83 bd 04 ff ff ff 00 	cmp    DWORD PTR [ebp-0xfc],0x0
  47adb0:	0f 85 95 00 00 00    	jne    0x47ae4b
  47adb6:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  47adb9:	8b 08                	mov    ecx,DWORD PTR [eax]
  47adbb:	51                   	push   ecx
  47adbc:	e8 ef e6 03 00       	call   0x4b94b0
  47adc1:	83 c4 04             	add    esp,0x4
  47adc4:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  47adc7:	c7 02 00 00 00 00    	mov    DWORD PTR [edx],0x0
  47adcd:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  47add0:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  47add6:	c7 85 d8 fe ff ff 00 	mov    DWORD PTR [ebp-0x128],0x0
  47addd:	00 00 00 
  47ade0:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47ade4:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47ade7:	e8 d4 30 fa ff       	call   0x41dec0
  47adec:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47adf0:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47adf6:	e8 95 a1 f8 ff       	call   0x404f90
  47adfb:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47adff:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47ae02:	e8 b9 30 fa ff       	call   0x41dec0
  47ae07:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47ae0b:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47ae11:	e8 7a a1 f8 ff       	call   0x404f90
  47ae16:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47ae1a:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47ae20:	e8 6b a1 f8 ff       	call   0x404f90
  47ae25:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47ae29:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47ae2c:	e8 5f a1 f8 ff       	call   0x404f90
  47ae31:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47ae38:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47ae3e:	e8 4d a1 f8 ff       	call   0x404f90
  47ae43:	8b 85 d8 fe ff ff    	mov    eax,DWORD PTR [ebp-0x128]
  47ae49:	eb 73                	jmp    0x47aebe
  47ae4b:	c7 85 d4 fe ff ff 01 	mov    DWORD PTR [ebp-0x12c],0x1
  47ae52:	00 00 00 
  47ae55:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47ae59:	8d 4d 94             	lea    ecx,[ebp-0x6c]
  47ae5c:	e8 5f 30 fa ff       	call   0x41dec0
  47ae61:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  47ae65:	8d 8d 20 ff ff ff    	lea    ecx,[ebp-0xe0]
  47ae6b:	e8 20 a1 f8 ff       	call   0x404f90
  47ae70:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  47ae74:	8d 4d cc             	lea    ecx,[ebp-0x34]
  47ae77:	e8 44 30 fa ff       	call   0x41dec0
  47ae7c:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47ae80:	8d 8d 78 ff ff ff    	lea    ecx,[ebp-0x88]
  47ae86:	e8 05 a1 f8 ff       	call   0x404f90
  47ae8b:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47ae8f:	8d 8d 3c ff ff ff    	lea    ecx,[ebp-0xc4]
  47ae95:	e8 f6 a0 f8 ff       	call   0x404f90
  47ae9a:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  47ae9e:	8d 4d b0             	lea    ecx,[ebp-0x50]
  47aea1:	e8 ea a0 f8 ff       	call   0x404f90
  47aea6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47aead:	8d 8d 58 ff ff ff    	lea    ecx,[ebp-0xa8]
  47aeb3:	e8 d8 a0 f8 ff       	call   0x404f90
  47aeb8:	8b 85 d4 fe ff ff    	mov    eax,DWORD PTR [ebp-0x12c]
  47aebe:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47aec1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47aec8:	59                   	pop    ecx
  47aec9:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  47aecc:	33 cd                	xor    ecx,ebp
  47aece:	e8 01 c5 00 00       	call   0x4873d4
  47aed3:	8b e5                	mov    esp,ebp
  47aed5:	5d                   	pop    ebp
  47aed6:	c2 10 00             	ret    0x10

; launcher: patcher/download-url-and-destination-base 0x478ac0..0x478c05 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00478ac0 <.data>:
  478ac0:	55                   	push   ebp
  478ac1:	8b ec                	mov    ebp,esp
  478ac3:	6a ff                	push   0xffffffff
  478ac5:	68 3e f4 4b 00       	push   0x4bf43e
  478aca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  478ad0:	50                   	push   eax
  478ad1:	81 ec 8c 00 00 00    	sub    esp,0x8c
  478ad7:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  478adc:	33 c5                	xor    eax,ebp
  478ade:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  478ae1:	50                   	push   eax
  478ae2:	8d 45 f4             	lea    eax,[ebp-0xc]
  478ae5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  478aeb:	89 8d 68 ff ff ff    	mov    DWORD PTR [ebp-0x98],ecx
  478af1:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  478af4:	50                   	push   eax
  478af5:	8b 8d 68 ff ff ff    	mov    ecx,DWORD PTR [ebp-0x98]
  478afb:	51                   	push   ecx
  478afc:	8d 95 70 ff ff ff    	lea    edx,[ebp-0x90]
  478b02:	52                   	push   edx
  478b03:	e8 a8 88 00 00       	call   0x4813b0
  478b08:	83 c4 0c             	add    esp,0xc
  478b0b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  478b12:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  478b15:	50                   	push   eax
  478b16:	8b 8d 68 ff ff ff    	mov    ecx,DWORD PTR [ebp-0x98]
  478b1c:	83 c1 1c             	add    ecx,0x1c
  478b1f:	51                   	push   ecx
  478b20:	8d 55 d0             	lea    edx,[ebp-0x30]
  478b23:	52                   	push   edx
  478b24:	e8 87 88 00 00       	call   0x4813b0
  478b29:	83 c4 0c             	add    esp,0xc
  478b2c:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  478b30:	8d 4d 8c             	lea    ecx,[ebp-0x74]
  478b33:	e8 a8 2e 00 00       	call   0x47b9e0
  478b38:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  478b3c:	8d 85 70 ff ff ff    	lea    eax,[ebp-0x90]
  478b42:	50                   	push   eax
  478b43:	8d 4d 8c             	lea    ecx,[ebp-0x74]
  478b46:	e8 a5 2a fd ff       	call   0x44b5f0
  478b4b:	8d 4d d0             	lea    ecx,[ebp-0x30]
  478b4e:	51                   	push   ecx
  478b4f:	8d 4d a8             	lea    ecx,[ebp-0x58]
  478b52:	e8 99 2a fd ff       	call   0x44b5f0
  478b57:	68 fc e4 4e 00       	push   0x4ee4fc
  478b5c:	ff 15 00 72 4c 00    	call   DWORD PTR ds:0x4c7200
  478b62:	8b 95 68 ff ff ff    	mov    edx,DWORD PTR [ebp-0x98]
  478b68:	8d 45 8c             	lea    eax,[ebp-0x74]
  478b6b:	89 42 48             	mov    DWORD PTR [edx+0x48],eax
  478b6e:	68 fc e4 4e 00       	push   0x4ee4fc
  478b73:	ff 15 fc 71 4c 00    	call   DWORD PTR ds:0x4c71fc
  478b79:	8d 4d 8c             	lea    ecx,[ebp-0x74]
  478b7c:	51                   	push   ecx
  478b7d:	8b 8d 68 ff ff ff    	mov    ecx,DWORD PTR [ebp-0x98]
  478b83:	83 c1 38             	add    ecx,0x38
  478b86:	e8 35 25 fd ff       	call   0x44b0c0
  478b8b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  478b8e:	68 fc e4 4e 00       	push   0x4ee4fc
  478b93:	ff 15 00 72 4c 00    	call   DWORD PTR ds:0x4c7200
  478b99:	8b 95 68 ff ff ff    	mov    edx,DWORD PTR [ebp-0x98]
  478b9f:	c7 42 48 00 00 00 00 	mov    DWORD PTR [edx+0x48],0x0
  478ba6:	68 fc e4 4e 00       	push   0x4ee4fc
  478bab:	ff 15 fc 71 4c 00    	call   DWORD PTR ds:0x4c71fc
  478bb1:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  478bb4:	89 85 6c ff ff ff    	mov    DWORD PTR [ebp-0x94],eax
  478bba:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  478bbe:	8d 4d 8c             	lea    ecx,[ebp-0x74]
  478bc1:	e8 8a 2e 00 00       	call   0x47ba50
  478bc6:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  478bca:	8d 4d d0             	lea    ecx,[ebp-0x30]
  478bcd:	e8 ee 52 fa ff       	call   0x41dec0
  478bd2:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  478bd9:	8d 8d 70 ff ff ff    	lea    ecx,[ebp-0x90]
  478bdf:	e8 dc 52 fa ff       	call   0x41dec0
  478be4:	8b 85 6c ff ff ff    	mov    eax,DWORD PTR [ebp-0x94]
  478bea:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  478bed:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  478bf4:	59                   	pop    ecx
  478bf5:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  478bf8:	33 cd                	xor    ecx,ebp
  478bfa:	e8 d5 e7 00 00       	call   0x4873d4
  478bff:	8b e5                	mov    esp,ebp
  478c01:	5d                   	pop    ebp
  478c02:	c2 08 00             	ret    0x8

; launcher: patcher/http-body-to-file-and-result 0x44b0c0..0x44b5c9 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044b0c0 <.data>:
  44b0c0:	55                   	push   ebp
  44b0c1:	8b ec                	mov    ebp,esp
  44b0c3:	6a ff                	push   0xffffffff
  44b0c5:	68 a6 cc 4b 00       	push   0x4bcca6
  44b0ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  44b0d0:	50                   	push   eax
  44b0d1:	51                   	push   ecx
  44b0d2:	b8 c4 10 00 00       	mov    eax,0x10c4
  44b0d7:	e8 34 c9 03 00       	call   0x487a10
  44b0dc:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  44b0e1:	33 c5                	xor    eax,ebp
  44b0e3:	89 45 d8             	mov    DWORD PTR [ebp-0x28],eax
  44b0e6:	53                   	push   ebx
  44b0e7:	56                   	push   esi
  44b0e8:	57                   	push   edi
  44b0e9:	50                   	push   eax
  44b0ea:	8d 45 f4             	lea    eax,[ebp-0xc]
  44b0ed:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  44b0f3:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  44b0f6:	89 8d 74 ef ff ff    	mov    DWORD PTR [ebp-0x108c],ecx
  44b0fc:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  44b103:	8b 85 74 ef ff ff    	mov    eax,DWORD PTR [ebp-0x108c]
  44b109:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  44b110:	c7 45 e0 00 00 00 00 	mov    DWORD PTR [ebp-0x20],0x0
  44b117:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  44b11e:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  44b121:	51                   	push   ecx
  44b122:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b125:	e8 e6 12 00 00       	call   0x44c410
  44b12a:	89 85 70 ef ff ff    	mov    DWORD PTR [ebp-0x1090],eax
  44b130:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  44b134:	6a 00                	push   0x0
  44b136:	68 bc 75 4c 00       	push   0x4c75bc
  44b13b:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b13e:	e8 fd 04 00 00       	call   0x44b640
  44b143:	89 85 6c ef ff ff    	mov    DWORD PTR [ebp-0x1094],eax
  44b149:	83 bd 6c ef ff ff ff 	cmp    DWORD PTR [ebp-0x1094],0xffffffff
  44b150:	75 22                	jne    0x44b174
  44b152:	6a 00                	push   0x0
  44b154:	68 c0 75 4c 00       	push   0x4c75c0
  44b159:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b15c:	e8 df 04 00 00       	call   0x44b640
  44b161:	89 85 68 ef ff ff    	mov    DWORD PTR [ebp-0x1098],eax
  44b167:	83 bd 68 ef ff ff ff 	cmp    DWORD PTR [ebp-0x1098],0xffffffff
  44b16e:	0f 84 80 00 00 00    	je     0x44b1f4
  44b174:	6a 00                	push   0x0
  44b176:	68 cc 75 4c 00       	push   0x4c75cc
  44b17b:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b17e:	e8 bd 04 00 00       	call   0x44b640
  44b183:	89 85 64 ef ff ff    	mov    DWORD PTR [ebp-0x109c],eax
  44b189:	68 c4 75 4c 00       	push   0x4c75c4
  44b18e:	6a 01                	push   0x1
  44b190:	8b 95 64 ef ff ff    	mov    edx,DWORD PTR [ebp-0x109c]
  44b196:	52                   	push   edx
  44b197:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b19a:	e8 71 04 00 00       	call   0x44b610
  44b19f:	89 85 60 ef ff ff    	mov    DWORD PTR [ebp-0x10a0],eax
  44b1a5:	8b 85 60 ef ff ff    	mov    eax,DWORD PTR [ebp-0x10a0]
  44b1ab:	50                   	push   eax
  44b1ac:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b1af:	e8 3c 04 00 00       	call   0x44b5f0
  44b1b4:	6a 00                	push   0x0
  44b1b6:	68 d8 75 4c 00       	push   0x4c75d8
  44b1bb:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b1be:	e8 7d 04 00 00       	call   0x44b640
  44b1c3:	89 85 5c ef ff ff    	mov    DWORD PTR [ebp-0x10a4],eax
  44b1c9:	68 d0 75 4c 00       	push   0x4c75d0
  44b1ce:	6a 01                	push   0x1
  44b1d0:	8b 8d 5c ef ff ff    	mov    ecx,DWORD PTR [ebp-0x10a4]
  44b1d6:	51                   	push   ecx
  44b1d7:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b1da:	e8 31 04 00 00       	call   0x44b610
  44b1df:	89 85 58 ef ff ff    	mov    DWORD PTR [ebp-0x10a8],eax
  44b1e5:	8b 95 58 ef ff ff    	mov    edx,DWORD PTR [ebp-0x10a8]
  44b1eb:	52                   	push   edx
  44b1ec:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b1ef:	e8 fc 03 00 00       	call   0x44b5f0
  44b1f4:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  44b1f7:	e8 24 2d fd ff       	call   0x41df20
  44b1fc:	89 85 54 ef ff ff    	mov    DWORD PTR [ebp-0x10ac],eax
  44b202:	8b 85 54 ef ff ff    	mov    eax,DWORD PTR [ebp-0x10ac]
  44b208:	50                   	push   eax
  44b209:	ff 15 04 74 4c 00    	call   DWORD PTR ds:0x4c7404
  44b20f:	6a 0c                	push   0xc
  44b211:	e8 8e c7 03 00       	call   0x4879a4
  44b216:	83 c4 04             	add    esp,0x4
  44b219:	89 85 50 ef ff ff    	mov    DWORD PTR [ebp-0x10b0],eax
  44b21f:	8b 8d 50 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x10b0]
  44b225:	89 8d a0 ef ff ff    	mov    DWORD PTR [ebp-0x1060],ecx
  44b22b:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  44b22f:	83 bd a0 ef ff ff 00 	cmp    DWORD PTR [ebp-0x1060],0x0
  44b236:	74 55                	je     0x44b28d
  44b238:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b23b:	e8 e0 2c fd ff       	call   0x41df20
  44b240:	89 85 4c ef ff ff    	mov    DWORD PTR [ebp-0x10b4],eax
  44b246:	8b 8d 74 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x108c]
  44b24c:	e8 6f 0b 00 00       	call   0x44bdc0
  44b251:	89 85 48 ef ff ff    	mov    DWORD PTR [ebp-0x10b8],eax
  44b257:	68 00 00 40 00       	push   0x400000
  44b25c:	6a ff                	push   0xffffffff
  44b25e:	6a 00                	push   0x0
  44b260:	8b 95 4c ef ff ff    	mov    edx,DWORD PTR [ebp-0x10b4]
  44b266:	52                   	push   edx
  44b267:	8b 85 48 ef ff ff    	mov    eax,DWORD PTR [ebp-0x10b8]
  44b26d:	50                   	push   eax
  44b26e:	8b 8d a0 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1060]
  44b274:	e8 47 0f 00 00       	call   0x44c1c0
  44b279:	89 85 44 ef ff ff    	mov    DWORD PTR [ebp-0x10bc],eax
  44b27f:	8b 8d 44 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x10bc]
  44b285:	89 8d 40 ef ff ff    	mov    DWORD PTR [ebp-0x10c0],ecx
  44b28b:	eb 0a                	jmp    0x44b297
  44b28d:	c7 85 40 ef ff ff 00 	mov    DWORD PTR [ebp-0x10c0],0x0
  44b294:	00 00 00 
  44b297:	8b 95 40 ef ff ff    	mov    edx,DWORD PTR [ebp-0x10c0]
  44b29d:	89 95 a4 ef ff ff    	mov    DWORD PTR [ebp-0x105c],edx
  44b2a3:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  44b2a7:	8b 85 a4 ef ff ff    	mov    eax,DWORD PTR [ebp-0x105c]
  44b2ad:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  44b2b0:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  44b2b4:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44b2b7:	e8 04 2c fd ff       	call   0x41dec0
  44b2bc:	eb 6f                	jmp    0x44b32d
  44b2be:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  44b2c1:	e8 5a 2c fd ff       	call   0x41df20
  44b2c6:	50                   	push   eax
  44b2c7:	ff 15 04 74 4c 00    	call   DWORD PTR ds:0x4c7404
  44b2cd:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  44b2d0:	89 8d 98 ef ff ff    	mov    DWORD PTR [ebp-0x1068],ecx
  44b2d6:	8b 95 98 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1068]
  44b2dc:	89 95 9c ef ff ff    	mov    DWORD PTR [ebp-0x1064],edx
  44b2e2:	83 bd 9c ef ff ff 00 	cmp    DWORD PTR [ebp-0x1064],0x0
  44b2e9:	74 1c                	je     0x44b307
  44b2eb:	6a 01                	push   0x1
  44b2ed:	8b 85 9c ef ff ff    	mov    eax,DWORD PTR [ebp-0x1064]
  44b2f3:	8b 10                	mov    edx,DWORD PTR [eax]
  44b2f5:	8b 8d 9c ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1064]
  44b2fb:	8b 02                	mov    eax,DWORD PTR [edx]
  44b2fd:	ff d0                	call   eax
  44b2ff:	89 85 3c ef ff ff    	mov    DWORD PTR [ebp-0x10c4],eax
  44b305:	eb 0a                	jmp    0x44b311
  44b307:	c7 85 3c ef ff ff 00 	mov    DWORD PTR [ebp-0x10c4],0x0
  44b30e:	00 00 00 
  44b311:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  44b314:	89 8d 94 ef ff ff    	mov    DWORD PTR [ebp-0x106c],ecx
  44b31a:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  44b321:	b8 36 b3 44 00       	mov    eax,0x44b336
  44b326:	c3                   	ret
  44b327:	b8 2d b3 44 00       	mov    eax,0x44b32d
  44b32c:	c3                   	ret
  44b32d:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  44b334:	eb 0b                	jmp    0x44b341
  44b336:	8b 85 94 ef ff ff    	mov    eax,DWORD PTR [ebp-0x106c]
  44b33c:	e9 6a 02 00 00       	jmp    0x44b5ab
  44b341:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  44b344:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  44b347:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  44b34e:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  44b355:	6a 00                	push   0x0
  44b357:	8d 45 ec             	lea    eax,[ebp-0x14]
  44b35a:	50                   	push   eax
  44b35b:	6a 05                	push   0x5
  44b35d:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  44b360:	e8 3b 0f 00 00       	call   0x44c2a0
  44b365:	eb 6f                	jmp    0x44b3d6
  44b367:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  44b36a:	e8 b1 2b fd ff       	call   0x41df20
  44b36f:	50                   	push   eax
  44b370:	ff 15 04 74 4c 00    	call   DWORD PTR ds:0x4c7404
  44b376:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  44b379:	89 8d 8c ef ff ff    	mov    DWORD PTR [ebp-0x1074],ecx
  44b37f:	8b 95 8c ef ff ff    	mov    edx,DWORD PTR [ebp-0x1074]
  44b385:	89 95 90 ef ff ff    	mov    DWORD PTR [ebp-0x1070],edx
  44b38b:	83 bd 90 ef ff ff 00 	cmp    DWORD PTR [ebp-0x1070],0x0
  44b392:	74 1c                	je     0x44b3b0
  44b394:	6a 01                	push   0x1
  44b396:	8b 85 90 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1070]
  44b39c:	8b 10                	mov    edx,DWORD PTR [eax]
  44b39e:	8b 8d 90 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1070]
  44b3a4:	8b 02                	mov    eax,DWORD PTR [edx]
  44b3a6:	ff d0                	call   eax
  44b3a8:	89 85 38 ef ff ff    	mov    DWORD PTR [ebp-0x10c8],eax
  44b3ae:	eb 0a                	jmp    0x44b3ba
  44b3b0:	c7 85 38 ef ff ff 00 	mov    DWORD PTR [ebp-0x10c8],0x0
  44b3b7:	00 00 00 
  44b3ba:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  44b3bd:	89 8d 88 ef ff ff    	mov    DWORD PTR [ebp-0x1078],ecx
  44b3c3:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  44b3ca:	b8 df b3 44 00       	mov    eax,0x44b3df
  44b3cf:	c3                   	ret
  44b3d0:	b8 d6 b3 44 00       	mov    eax,0x44b3d6
  44b3d5:	c3                   	ret
  44b3d6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  44b3dd:	eb 0b                	jmp    0x44b3ea
  44b3df:	8b 85 88 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1078]
  44b3e5:	e9 c1 01 00 00       	jmp    0x44b5ab
  44b3ea:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  44b3ed:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  44b3f0:	89 42 38             	mov    DWORD PTR [edx+0x38],eax
  44b3f3:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  44b3fa:	68 dc 75 4c 00       	push   0x4c75dc
  44b3ff:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  44b402:	83 c1 1c             	add    ecx,0x1c
  44b405:	e8 16 2b fd ff       	call   0x41df20
  44b40a:	50                   	push   eax
  44b40b:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  44b40e:	51                   	push   ecx
  44b40f:	e8 3d c5 03 00       	call   0x487951
  44b414:	83 c4 0c             	add    esp,0xc
  44b417:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  44b41b:	75 5b                	jne    0x44b478
  44b41d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  44b420:	e8 fb 2a fd ff       	call   0x41df20
  44b425:	50                   	push   eax
  44b426:	ff 15 04 74 4c 00    	call   DWORD PTR ds:0x4c7404
  44b42c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  44b42f:	89 95 80 ef ff ff    	mov    DWORD PTR [ebp-0x1080],edx
  44b435:	8b 85 80 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1080]
  44b43b:	89 85 84 ef ff ff    	mov    DWORD PTR [ebp-0x107c],eax
  44b441:	83 bd 84 ef ff ff 00 	cmp    DWORD PTR [ebp-0x107c],0x0
  44b448:	74 1c                	je     0x44b466
  44b44a:	6a 01                	push   0x1
  44b44c:	8b 8d 84 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x107c]
  44b452:	8b 11                	mov    edx,DWORD PTR [ecx]
  44b454:	8b 8d 84 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x107c]
  44b45a:	8b 02                	mov    eax,DWORD PTR [edx]
  44b45c:	ff d0                	call   eax
  44b45e:	89 85 34 ef ff ff    	mov    DWORD PTR [ebp-0x10cc],eax
  44b464:	eb 0a                	jmp    0x44b470
  44b466:	c7 85 34 ef ff ff 00 	mov    DWORD PTR [ebp-0x10cc],0x0
  44b46d:	00 00 00 
  44b470:	8b 45 dc             	mov    eax,DWORD PTR [ebp-0x24]
  44b473:	e9 33 01 00 00       	jmp    0x44b5ab
  44b478:	c7 45 fc 06 00 00 00 	mov    DWORD PTR [ebp-0x4],0x6
  44b47f:	c7 45 dc 01 00 00 00 	mov    DWORD PTR [ebp-0x24],0x1
  44b486:	b9 01 00 00 00       	mov    ecx,0x1
  44b48b:	85 c9                	test   ecx,ecx
  44b48d:	0f 84 8c 00 00 00    	je     0x44b51f
  44b493:	68 00 10 00 00       	push   0x1000
  44b498:	8d 95 b0 ef ff ff    	lea    edx,[ebp-0x1050]
  44b49e:	52                   	push   edx
  44b49f:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  44b4a2:	e8 a9 0c 00 00       	call   0x44c150
  44b4a7:	89 85 30 ef ff ff    	mov    DWORD PTR [ebp-0x10d0],eax
  44b4ad:	8b 85 30 ef ff ff    	mov    eax,DWORD PTR [ebp-0x10d0]
  44b4b3:	89 85 ac ef ff ff    	mov    DWORD PTR [ebp-0x1054],eax
  44b4b9:	83 bd ac ef ff ff 00 	cmp    DWORD PTR [ebp-0x1054],0x0
  44b4c0:	75 02                	jne    0x44b4c4
  44b4c2:	eb 5b                	jmp    0x44b51f
  44b4c4:	8b 8d 74 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x108c]
  44b4ca:	83 79 0c 00          	cmp    DWORD PTR [ecx+0xc],0x0
  44b4ce:	74 0f                	je     0x44b4df
  44b4d0:	8b 95 74 ef ff ff    	mov    edx,DWORD PTR [ebp-0x108c]
  44b4d6:	c7 42 0c 00 00 00 00 	mov    DWORD PTR [edx+0xc],0x0
  44b4dd:	eb 40                	jmp    0x44b51f
  44b4df:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  44b4e2:	8b 48 3c             	mov    ecx,DWORD PTR [eax+0x3c]
  44b4e5:	03 8d ac ef ff ff    	add    ecx,DWORD PTR [ebp-0x1054]
  44b4eb:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  44b4ee:	89 4a 3c             	mov    DWORD PTR [edx+0x3c],ecx
  44b4f1:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  44b4f4:	50                   	push   eax
  44b4f5:	6a 01                	push   0x1
  44b4f7:	8b 8d ac ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1054]
  44b4fd:	51                   	push   ecx
  44b4fe:	8d 95 b0 ef ff ff    	lea    edx,[ebp-0x1050]
  44b504:	52                   	push   edx
  44b505:	e8 e8 c2 03 00       	call   0x4877f2
  44b50a:	83 c4 10             	add    esp,0x10
  44b50d:	85 c0                	test   eax,eax
  44b50f:	75 09                	jne    0x44b51a
  44b511:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  44b518:	eb 05                	jmp    0x44b51f
  44b51a:	e9 67 ff ff ff       	jmp    0x44b486
  44b51f:	eb 14                	jmp    0x44b535
  44b521:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  44b528:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  44b52f:	b8 3c b5 44 00       	mov    eax,0x44b53c
  44b534:	c3                   	ret
  44b535:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  44b53c:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  44b540:	74 13                	je     0x44b555
  44b542:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  44b545:	50                   	push   eax
  44b546:	e8 c9 c0 03 00       	call   0x487614
  44b54b:	83 c4 04             	add    esp,0x4
  44b54e:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  44b555:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  44b558:	e8 c3 29 fd ff       	call   0x41df20
  44b55d:	50                   	push   eax
  44b55e:	ff 15 04 74 4c 00    	call   DWORD PTR ds:0x4c7404
  44b564:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  44b567:	89 8d 78 ef ff ff    	mov    DWORD PTR [ebp-0x1088],ecx
  44b56d:	8b 95 78 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1088]
  44b573:	89 95 7c ef ff ff    	mov    DWORD PTR [ebp-0x1084],edx
  44b579:	83 bd 7c ef ff ff 00 	cmp    DWORD PTR [ebp-0x1084],0x0
  44b580:	74 1c                	je     0x44b59e
  44b582:	6a 01                	push   0x1
  44b584:	8b 85 7c ef ff ff    	mov    eax,DWORD PTR [ebp-0x1084]
  44b58a:	8b 10                	mov    edx,DWORD PTR [eax]
  44b58c:	8b 8d 7c ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1084]
  44b592:	8b 02                	mov    eax,DWORD PTR [edx]
  44b594:	ff d0                	call   eax
  44b596:	89 85 2c ef ff ff    	mov    DWORD PTR [ebp-0x10d4],eax
  44b59c:	eb 0a                	jmp    0x44b5a8
  44b59e:	c7 85 2c ef ff ff 00 	mov    DWORD PTR [ebp-0x10d4],0x0
  44b5a5:	00 00 00 
  44b5a8:	8b 45 dc             	mov    eax,DWORD PTR [ebp-0x24]
  44b5ab:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  44b5ae:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  44b5b5:	59                   	pop    ecx
  44b5b6:	5f                   	pop    edi
  44b5b7:	5e                   	pop    esi
  44b5b8:	5b                   	pop    ebx
  44b5b9:	8b 4d d8             	mov    ecx,DWORD PTR [ebp-0x28]
  44b5bc:	33 cd                	xor    ecx,ebp
  44b5be:	e8 11 be 03 00       	call   0x4873d4
  44b5c3:	8b e5                	mov    esp,ebp
  44b5c5:	5d                   	pop    ebp
  44b5c6:	c2 04 00             	ret    0x4

; launcher: patcher/http-internet-open-url 0x44c1c0..0x44c251 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044c1c0 <.data>:
  44c1c0:	55                   	push   ebp
  44c1c1:	8b ec                	mov    ebp,esp
  44c1c3:	6a ff                	push   0xffffffff
  44c1c5:	68 1b cd 4b 00       	push   0x4bcd1b
  44c1ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  44c1d0:	50                   	push   eax
  44c1d1:	81 ec 14 08 00 00    	sub    esp,0x814
  44c1d7:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  44c1dc:	33 c5                	xor    eax,ebp
  44c1de:	50                   	push   eax
  44c1df:	8d 45 f4             	lea    eax,[ebp-0xc]
  44c1e2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  44c1e8:	89 8d e0 f7 ff ff    	mov    DWORD PTR [ebp-0x820],ecx
  44c1ee:	8b 8d e0 f7 ff ff    	mov    ecx,DWORD PTR [ebp-0x820]
  44c1f4:	e8 87 01 00 00       	call   0x44c380
  44c1f9:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  44c200:	8b 85 e0 f7 ff ff    	mov    eax,DWORD PTR [ebp-0x820]
  44c206:	c7 00 f8 76 4c 00    	mov    DWORD PTR [eax],0x4c76f8
  44c20c:	8b 8d e0 f7 ff ff    	mov    ecx,DWORD PTR [ebp-0x820]
  44c212:	51                   	push   ecx
  44c213:	8b 55 18             	mov    edx,DWORD PTR [ebp+0x18]
  44c216:	52                   	push   edx
  44c217:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  44c21a:	50                   	push   eax
  44c21b:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  44c21e:	51                   	push   ecx
  44c21f:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  44c222:	52                   	push   edx
  44c223:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  44c226:	50                   	push   eax
  44c227:	ff 15 fc 73 4c 00    	call   DWORD PTR ds:0x4c73fc
  44c22d:	8b 8d e0 f7 ff ff    	mov    ecx,DWORD PTR [ebp-0x820]
  44c233:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  44c236:	8b 95 e0 f7 ff ff    	mov    edx,DWORD PTR [ebp-0x820]
  44c23c:	83 7a 04 00          	cmp    DWORD PTR [edx+0x4],0x0
  44c240:	75 33                	jne    0x44c275
  44c242:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  44c245:	50                   	push   eax
  44c246:	68 b8 76 4c 00       	push   0x4c76b8
  44c24b:	8b 8d e0 f7 ff ff    	mov    ecx,DWORD PTR [ebp-0x820]

; launcher: patcher/http-internet-read-file 0x44c150..0x44c191 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044c150 <.data>:
  44c150:	55                   	push   ebp
  44c151:	8b ec                	mov    ebp,esp
  44c153:	81 ec 18 08 00 00    	sub    esp,0x818
  44c159:	89 8d e8 f7 ff ff    	mov    DWORD PTR [ebp-0x818],ecx
  44c15f:	8d 45 fc             	lea    eax,[ebp-0x4]
  44c162:	50                   	push   eax
  44c163:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  44c166:	51                   	push   ecx
  44c167:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  44c16a:	52                   	push   edx
  44c16b:	8b 85 e8 f7 ff ff    	mov    eax,DWORD PTR [ebp-0x818]
  44c171:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  44c174:	51                   	push   ecx
  44c175:	ff 15 f8 73 4c 00    	call   DWORD PTR ds:0x4c73f8
  44c17b:	85 c0                	test   eax,eax
  44c17d:	75 33                	jne    0x44c1b2
  44c17f:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  44c182:	52                   	push   edx
  44c183:	68 68 76 4c 00       	push   0x4c7668
  44c188:	8b 85 e8 f7 ff ff    	mov    eax,DWORD PTR [ebp-0x818]
  44c18e:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]

; launcher: patcher/gzip-magic-probe 0x43e330..0x43e3a0 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0043e330 <.data>:
  43e330:	51                   	push   ecx
  43e331:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  43e335:	56                   	push   esi
  43e336:	57                   	push   edi
  43e337:	68 94 d4 4c 00       	push   0x4cd494
  43e33c:	50                   	push   eax
  43e33d:	33 ff                	xor    edi,edi
  43e33f:	e8 79 ec 04 00       	call   0x48cfbd
  43e344:	8b f0                	mov    esi,eax
  43e346:	83 c4 08             	add    esp,0x8
  43e349:	85 f6                	test   esi,esi
  43e34b:	74 32                	je     0x43e37f
  43e34d:	56                   	push   esi
  43e34e:	6a 01                	push   0x1
  43e350:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  43e354:	6a 02                	push   0x2
  43e356:	51                   	push   ecx
  43e357:	e8 1a f1 04 00       	call   0x48d476
  43e35c:	83 c4 10             	add    esp,0x10
  43e35f:	85 c0                	test   eax,eax
  43e361:	74 13                	je     0x43e376
  43e363:	66 8b 44 24 08       	mov    ax,WORD PTR [esp+0x8]
  43e368:	3c 1f                	cmp    al,0x1f
  43e36a:	75 0a                	jne    0x43e376
  43e36c:	80 fc 8b             	cmp    ah,0x8b
  43e36f:	75 05                	jne    0x43e376
  43e371:	bf 01 00 00 00       	mov    edi,0x1
  43e376:	56                   	push   esi
  43e377:	e8 98 92 04 00       	call   0x487614
  43e37c:	83 c4 04             	add    esp,0x4
  43e37f:	33 c0                	xor    eax,eax
  43e381:	85 ff                	test   edi,edi
  43e383:	5f                   	pop    edi
  43e384:	0f 95 c0             	setne  al
  43e387:	5e                   	pop    esi
  43e388:	59                   	pop    ecx
  43e389:	c3                   	ret
  43e38a:	cc                   	int3
  43e38b:	cc                   	int3
  43e38c:	cc                   	int3
  43e38d:	cc                   	int3
  43e38e:	cc                   	int3
  43e38f:	cc                   	int3
  43e390:	50                   	push   eax
  43e391:	e8 9a ff ff ff       	call   0x43e330
  43e396:	83 c4 04             	add    esp,0x4
  43e399:	c3                   	ret
  43e39a:	cc                   	int3
  43e39b:	cc                   	int3
  43e39c:	cc                   	int3
  43e39d:	cc                   	int3
  43e39e:	cc                   	int3
  43e39f:	cc                   	int3

; launcher: patcher/gzip-wrapper-create-and-footer-size 0x43e3a0..0x43e510 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0043e3a0 <.data>:
  43e3a0:	6a ff                	push   0xffffffff
  43e3a2:	68 08 34 4c 00       	push   0x4c3408
  43e3a7:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  43e3ad:	50                   	push   eax
  43e3ae:	83 ec 40             	sub    esp,0x40
  43e3b1:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  43e3b6:	33 c4                	xor    eax,esp
  43e3b8:	89 44 24 3c          	mov    DWORD PTR [esp+0x3c],eax
  43e3bc:	53                   	push   ebx
  43e3bd:	55                   	push   ebp
  43e3be:	56                   	push   esi
  43e3bf:	57                   	push   edi
  43e3c0:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  43e3c5:	33 c4                	xor    eax,esp
  43e3c7:	50                   	push   eax
  43e3c8:	8d 44 24 54          	lea    eax,[esp+0x54]
  43e3cc:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  43e3d2:	8b 44 24 64          	mov    eax,DWORD PTR [esp+0x64]
  43e3d6:	8b 5c 24 68          	mov    ebx,DWORD PTR [esp+0x68]
  43e3da:	50                   	push   eax
  43e3db:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  43e3df:	e8 1c 6b fc ff       	call   0x404f00
  43e3e4:	53                   	push   ebx
  43e3e5:	8d 44 24 34          	lea    eax,[esp+0x34]
  43e3e9:	6a 20                	push   0x20
  43e3eb:	33 ed                	xor    ebp,ebp
  43e3ed:	50                   	push   eax
  43e3ee:	89 6c 24 68          	mov    DWORD PTR [esp+0x68],ebp
  43e3f2:	e8 2a 14 05 00       	call   0x48f821
  43e3f7:	8a 03                	mov    al,BYTE PTR [ebx]
  43e3f9:	83 c4 0c             	add    esp,0xc
  43e3fc:	3c 77                	cmp    al,0x77
  43e3fe:	74 04                	je     0x43e404
  43e400:	3c 57                	cmp    al,0x57
  43e402:	75 14                	jne    0x43e418
  43e404:	68 10 4f 4d 00       	push   0x4d4f10
  43e409:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  43e40d:	6a 20                	push   0x20
  43e40f:	51                   	push   ecx
  43e410:	e8 83 1c 05 00       	call   0x490098
  43e415:	83 c4 0c             	add    esp,0xc
  43e418:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  43e41c:	e8 4f 6b fc ff       	call   0x404f70
  43e421:	8d 54 24 30          	lea    edx,[esp+0x30]
  43e425:	6a ff                	push   0xffffffff
  43e427:	52                   	push   edx
  43e428:	8b c8                	mov    ecx,eax
  43e42a:	e8 51 81 00 00       	call   0x446580
  43e42f:	8b f0                	mov    esi,eax
  43e431:	83 c4 08             	add    esp,0x8
  43e434:	3b f5                	cmp    esi,ebp
  43e436:	75 3b                	jne    0x43e473
  43e438:	68 14 4f 4d 00       	push   0x4d4f14
  43e43d:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  43e441:	e8 1a 32 fc ff       	call   0x401660
  43e446:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  43e44a:	e8 21 6b fc ff       	call   0x404f70
  43e44f:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  43e453:	6a ff                	push   0xffffffff
  43e455:	51                   	push   ecx
  43e456:	8b c8                	mov    ecx,eax
  43e458:	e8 23 81 00 00       	call   0x446580
  43e45d:	8b f0                	mov    esi,eax
  43e45f:	83 c4 08             	add    esp,0x8
  43e462:	3b f5                	cmp    esi,ebp
  43e464:	75 0d                	jne    0x43e473
  43e466:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  43e46a:	e8 21 6b fc ff       	call   0x404f90
  43e46f:	33 c0                	xor    eax,eax
  43e471:	eb 7b                	jmp    0x43e4ee
  43e473:	6a 10                	push   0x10
  43e475:	e8 2a 95 04 00       	call   0x4879a4
  43e47a:	83 c4 04             	add    esp,0x4
  43e47d:	3b c5                	cmp    eax,ebp
  43e47f:	74 13                	je     0x43e494
  43e481:	c7 00 1c 4f 4d 00    	mov    DWORD PTR [eax],0x4d4f1c
  43e487:	89 68 04             	mov    DWORD PTR [eax+0x4],ebp
  43e48a:	89 68 08             	mov    DWORD PTR [eax+0x8],ebp
  43e48d:	89 68 0c             	mov    DWORD PTR [eax+0xc],ebp
  43e490:	8b f8                	mov    edi,eax
  43e492:	eb 02                	jmp    0x43e496
  43e494:	33 ff                	xor    edi,edi
  43e496:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  43e499:	8a 1b                	mov    bl,BYTE PTR [ebx]
  43e49b:	80 fb 72             	cmp    bl,0x72
  43e49e:	74 05                	je     0x43e4a5
  43e4a0:	80 fb 52             	cmp    bl,0x52
  43e4a3:	75 3e                	jne    0x43e4e3
  43e4a5:	68 94 d4 4c 00       	push   0x4cd494
  43e4aa:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  43e4ae:	e8 bd 6a fc ff       	call   0x404f70
  43e4b3:	50                   	push   eax
  43e4b4:	e8 04 eb 04 00       	call   0x48cfbd
  43e4b9:	8b f0                	mov    esi,eax
  43e4bb:	83 c4 08             	add    esp,0x8
  43e4be:	3b f5                	cmp    esi,ebp
  43e4c0:	74 21                	je     0x43e4e3
  43e4c2:	6a 02                	push   0x2
  43e4c4:	6a fc                	push   0xfffffffc
  43e4c6:	56                   	push   esi
  43e4c7:	e8 47 1b 05 00       	call   0x490013
  43e4cc:	56                   	push   esi
  43e4cd:	6a 01                	push   0x1
  43e4cf:	8d 57 0c             	lea    edx,[edi+0xc]
  43e4d2:	6a 04                	push   0x4
  43e4d4:	52                   	push   edx
  43e4d5:	e8 9c ef 04 00       	call   0x48d476
  43e4da:	56                   	push   esi
  43e4db:	e8 34 91 04 00       	call   0x487614
  43e4e0:	83 c4 20             	add    esp,0x20
  43e4e3:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  43e4e7:	e8 a4 6a fc ff       	call   0x404f90
  43e4ec:	8b c7                	mov    eax,edi
  43e4ee:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  43e4f2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  43e4f9:	59                   	pop    ecx
  43e4fa:	5f                   	pop    edi
  43e4fb:	5e                   	pop    esi
  43e4fc:	5d                   	pop    ebp
  43e4fd:	5b                   	pop    ebx
  43e4fe:	8b 4c 24 3c          	mov    ecx,DWORD PTR [esp+0x3c]
  43e502:	33 cc                	xor    ecx,esp
  43e504:	e8 cb 8e 04 00       	call   0x4873d4
  43e509:	83 c4 4c             	add    esp,0x4c
  43e50c:	c3                   	ret
  43e50d:	cc                   	int3
  43e50e:	cc                   	int3
  43e50f:	cc                   	int3

; launcher: patcher/gzip-wrapper-read 0x43e5d0..0x43e624 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0043e5d0 <.data>:
  43e5d0:	56                   	push   esi
  43e5d1:	8b 74 24 0c          	mov    esi,DWORD PTR [esp+0xc]
  43e5d5:	85 f6                	test   esi,esi
  43e5d7:	75 06                	jne    0x43e5df
  43e5d9:	33 c0                	xor    eax,eax
  43e5db:	5e                   	pop    esi
  43e5dc:	c2 0c 00             	ret    0xc
  43e5df:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  43e5e2:	8b c6                	mov    eax,esi
  43e5e4:	0f af 44 24 10       	imul   eax,DWORD PTR [esp+0x10]
  43e5e9:	50                   	push   eax
  43e5ea:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  43e5ee:	e8 2d 85 00 00       	call   0x446b20
  43e5f3:	33 d2                	xor    edx,edx
  43e5f5:	83 c4 04             	add    esp,0x4
  43e5f8:	f7 f6                	div    esi
  43e5fa:	5e                   	pop    esi
  43e5fb:	c2 0c 00             	ret    0xc
  43e5fe:	cc                   	int3
  43e5ff:	cc                   	int3
  43e600:	57                   	push   edi
  43e601:	8b 7c 24 0c          	mov    edi,DWORD PTR [esp+0xc]
  43e605:	85 ff                	test   edi,edi
  43e607:	75 06                	jne    0x43e60f
  43e609:	33 c0                	xor    eax,eax
  43e60b:	5f                   	pop    edi
  43e60c:	c2 0c 00             	ret    0xc
  43e60f:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  43e613:	56                   	push   esi
  43e614:	8b f7                	mov    esi,edi
  43e616:	0f af 74 24 14       	imul   esi,DWORD PTR [esp+0x14]
  43e61b:	50                   	push   eax
  43e61c:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  43e61f:	e8 fc 87 00 00       	call   0x446e20

; launcher: patcher/gzip-wrapper-size 0x43e6d0..0x43e6e0 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0043e6d0 <.data>:
  43e6d0:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  43e6d3:	c3                   	ret
  43e6d4:	cc                   	int3
  43e6d5:	cc                   	int3
  43e6d6:	cc                   	int3
  43e6d7:	cc                   	int3
  43e6d8:	cc                   	int3
  43e6d9:	cc                   	int3
  43e6da:	cc                   	int3
  43e6db:	cc                   	int3
  43e6dc:	cc                   	int3
  43e6dd:	cc                   	int3
  43e6de:	cc                   	int3
  43e6df:	cc                   	int3

; launcher: patcher/provider-wrapper-read-dispatch 0x47a360..0x47a396 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0047a360 <.data>:
  47a360:	55                   	push   ebp
  47a361:	8b ec                	mov    ebp,esp
  47a363:	51                   	push   ecx
  47a364:	83 7d 14 00          	cmp    DWORD PTR [ebp+0x14],0x0
  47a368:	74 1e                	je     0x47a388
  47a36a:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  47a36d:	50                   	push   eax
  47a36e:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  47a371:	51                   	push   ecx
  47a372:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  47a375:	52                   	push   edx
  47a376:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  47a379:	8b 10                	mov    edx,DWORD PTR [eax]
  47a37b:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  47a37e:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  47a381:	ff d0                	call   eax
  47a383:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  47a386:	eb 07                	jmp    0x47a38f
  47a388:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47a38f:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  47a392:	8b e5                	mov    esp,ebp
  47a394:	5d                   	pop    ebp
  47a395:	c3                   	ret

; launcher: patcher/provider-wrapper-size-dispatch 0x47a3e0..0x47a3f2 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0047a3e0 <.data>:
  47a3e0:	55                   	push   ebp
  47a3e1:	8b ec                	mov    ebp,esp
  47a3e3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47a3e6:	8b 10                	mov    edx,DWORD PTR [eax]
  47a3e8:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  47a3eb:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  47a3ee:	ff d0                	call   eax
  47a3f0:	5d                   	pop    ebp
  47a3f1:	c3                   	ret

; launcher: patcher/gzip-read-to-inflate-and-crc 0x446b20..0x446c6b (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00446b20 <.data>:
  446b20:	53                   	push   ebx
  446b21:	56                   	push   esi
  446b22:	8b f1                	mov    esi,ecx
  446b24:	8b d8                	mov    ebx,eax
  446b26:	85 f6                	test   esi,esi
  446b28:	0f 84 3a 02 00 00    	je     0x446d68
  446b2e:	80 7e 5c 72          	cmp    BYTE PTR [esi+0x5c],0x72
  446b32:	0f 85 30 02 00 00    	jne    0x446d68
  446b38:	8b 4e 38             	mov    ecx,DWORD PTR [esi+0x38]
  446b3b:	57                   	push   edi
  446b3c:	83 f9 fd             	cmp    ecx,0xfffffffd
  446b3f:	0f 84 1c 02 00 00    	je     0x446d61
  446b45:	83 cf ff             	or     edi,0xffffffff
  446b48:	3b cf                	cmp    ecx,edi
  446b4a:	0f 84 11 02 00 00    	je     0x446d61
  446b50:	ba 01 00 00 00       	mov    edx,0x1
  446b55:	3b ca                	cmp    ecx,edx
  446b57:	75 06                	jne    0x446b5f
  446b59:	5f                   	pop    edi
  446b5a:	5e                   	pop    esi
  446b5b:	33 c0                	xor    eax,eax
  446b5d:	5b                   	pop    ebx
  446b5e:	c3                   	ret
  446b5f:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  446b63:	55                   	push   ebp
  446b64:	8b e8                	mov    ebp,eax
  446b66:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  446b69:	89 4e 10             	mov    DWORD PTR [esi+0x10],ecx
  446b6c:	85 c9                	test   ecx,ecx
  446b6e:	74 2b                	je     0x446b9b
  446b70:	39 7e 6c             	cmp    DWORD PTR [esi+0x6c],edi
  446b73:	74 26                	je     0x446b9b
  446b75:	8a 4e 6c             	mov    cl,BYTE PTR [esi+0x6c]
  446b78:	88 08                	mov    BYTE PTR [eax],cl
  446b7a:	01 56 0c             	add    DWORD PTR [esi+0xc],edx
  446b7d:	01 7e 10             	add    DWORD PTR [esi+0x10],edi
  446b80:	01 56 68             	add    DWORD PTR [esi+0x68],edx
  446b83:	83 7e 70 00          	cmp    DWORD PTR [esi+0x70],0x0
  446b87:	8d 68 01             	lea    ebp,[eax+0x1]
  446b8a:	89 7e 6c             	mov    DWORD PTR [esi+0x6c],edi
  446b8d:	8b dd                	mov    ebx,ebp
  446b8f:	74 0a                	je     0x446b9b
  446b91:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  446b94:	8b c2                	mov    eax,edx
  446b96:	5d                   	pop    ebp
  446b97:	5f                   	pop    edi
  446b98:	5e                   	pop    esi
  446b99:	5b                   	pop    ebx
  446b9a:	c3                   	ret
  446b9b:	83 7e 10 00          	cmp    DWORD PTR [esi+0x10],0x0
  446b9f:	0f 84 7e 01 00 00    	je     0x446d23
  446ba5:	83 7e 58 00          	cmp    DWORD PTR [esi+0x58],0x0
  446ba9:	0f 85 09 01 00 00    	jne    0x446cb8
  446baf:	83 7e 04 00          	cmp    DWORD PTR [esi+0x4],0x0
  446bb3:	75 4f                	jne    0x446c04
  446bb5:	83 7e 3c 00          	cmp    DWORD PTR [esi+0x3c],0x0
  446bb9:	75 49                	jne    0x446c04
  446bbb:	e8 bd aa 04 00       	call   0x49167d
  446bc0:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  446bc6:	8b 56 40             	mov    edx,DWORD PTR [esi+0x40]
  446bc9:	8b 46 44             	mov    eax,DWORD PTR [esi+0x44]
  446bcc:	52                   	push   edx
  446bcd:	68 00 40 00 00       	push   0x4000
  446bd2:	6a 01                	push   0x1
  446bd4:	50                   	push   eax
  446bd5:	e8 9c 68 04 00       	call   0x48d476
  446bda:	83 c4 10             	add    esp,0x10
  446bdd:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  446be0:	85 c0                	test   eax,eax
  446be2:	75 1b                	jne    0x446bff
  446be4:	8b 4e 40             	mov    ecx,DWORD PTR [esi+0x40]
  446be7:	51                   	push   ecx
  446be8:	c7 46 3c 01 00 00 00 	mov    DWORD PTR [esi+0x3c],0x1
  446bef:	e8 5e 78 04 00       	call   0x48e452
  446bf4:	83 c4 04             	add    esp,0x4
  446bf7:	85 c0                	test   eax,eax
  446bf9:	0f 85 21 01 00 00    	jne    0x446d20
  446bff:	8b 56 44             	mov    edx,DWORD PTR [esi+0x44]
  446c02:	89 16                	mov    DWORD PTR [esi],edx
  446c04:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  446c07:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  446c0a:	01 46 64             	add    DWORD PTR [esi+0x64],eax
  446c0d:	01 4e 68             	add    DWORD PTR [esi+0x68],ecx
  446c10:	6a 00                	push   0x0
  446c12:	56                   	push   esi
  446c13:	e8 38 81 fd ff       	call   0x41ed50
  446c18:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  446c1b:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  446c1e:	29 56 64             	sub    DWORD PTR [esi+0x64],edx
  446c21:	29 4e 68             	sub    DWORD PTR [esi+0x68],ecx
  446c24:	83 c4 08             	add    esp,0x8
  446c27:	89 46 38             	mov    DWORD PTR [esi+0x38],eax
  446c2a:	83 f8 01             	cmp    eax,0x1
  446c2d:	75 5e                	jne    0x446c8d
  446c2f:	8b 7e 0c             	mov    edi,DWORD PTR [esi+0xc]
  446c32:	8b 46 4c             	mov    eax,DWORD PTR [esi+0x4c]
  446c35:	8b cf                	mov    ecx,edi
  446c37:	2b cb                	sub    ecx,ebx
  446c39:	85 db                	test   ebx,ebx
  446c3b:	75 04                	jne    0x446c41
  446c3d:	33 c0                	xor    eax,eax
  446c3f:	eb 0b                	jmp    0x446c4c
  446c41:	51                   	push   ecx
  446c42:	8b cb                	mov    ecx,ebx
  446c44:	e8 77 a1 fd ff       	call   0x420dc0
  446c49:	83 c4 04             	add    esp,0x4
  446c4c:	89 46 4c             	mov    DWORD PTR [esi+0x4c],eax
  446c4f:	8b c6                	mov    eax,esi
  446c51:	8b df                	mov    ebx,edi
  446c53:	e8 c8 06 00 00       	call   0x447320
  446c58:	3b 46 4c             	cmp    eax,DWORD PTR [esi+0x4c]
  446c5b:	75 52                	jne    0x446caf
  446c5d:	8b c6                	mov    eax,esi
  446c5f:	e8 bc 06 00 00       	call   0x447320
  446c64:	8b c6                	mov    eax,esi
  446c66:	e8 a5 fc ff ff       	call   0x446910

; launcher: patcher/update-thread-main-event 0x476c40..0x476c70 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00476c40 <.data>:
  476c40:	55                   	push   ebp
  476c41:	8b ec                	mov    ebp,esp
  476c43:	51                   	push   ecx
  476c44:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  476c47:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  476c4a:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  476c4d:	e8 5e 04 00 00       	call   0x4770b0
  476c52:	8b 0d 9c a4 4e 00    	mov    ecx,DWORD PTR ds:0x4ea49c
  476c58:	51                   	push   ecx
  476c59:	ff 15 6c 72 4c 00    	call   DWORD PTR ds:0x4c726c
  476c5f:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  476c62:	e8 f9 1d 00 00       	call   0x478a60
  476c67:	8b e5                	mov    esp,ebp
  476c69:	5d                   	pop    ebp
  476c6a:	c3                   	ret
  476c6b:	cc                   	int3
  476c6c:	cc                   	int3
  476c6d:	cc                   	int3
  476c6e:	cc                   	int3
  476c6f:	cc                   	int3

; launcher: patcher/update-start-stop-wait 0x4789f0..0x478ac0 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004789f0 <.data>:
  4789f0:	55                   	push   ebp
  4789f1:	8b ec                	mov    ebp,esp
  4789f3:	51                   	push   ecx
  4789f4:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  4789f7:	83 3d 9c a4 4e 00 ff 	cmp    DWORD PTR ds:0x4ea49c,0xffffffff
  4789fe:	75 09                	jne    0x478a09
  478a00:	83 3d 14 e5 4e 00 00 	cmp    DWORD PTR ds:0x4ee514,0x0
  478a07:	74 16                	je     0x478a1f
  478a09:	6a 30                	push   0x30
  478a0b:	68 e0 8b 4c 00       	push   0x4c8be0
  478a10:	68 f0 8b 4c 00       	push   0x4c8bf0
  478a15:	6a 00                	push   0x0
  478a17:	ff 15 dc 72 4c 00    	call   DWORD PTR ds:0x4c72dc
  478a1d:	eb 30                	jmp    0x478a4f
  478a1f:	6a 00                	push   0x0
  478a21:	6a 00                	push   0x0
  478a23:	6a 00                	push   0x0
  478a25:	6a 00                	push   0x0
  478a27:	ff 15 68 72 4c 00    	call   DWORD PTR ds:0x4c7268
  478a2d:	a3 9c a4 4e 00       	mov    ds:0x4ea49c,eax
  478a32:	c7 05 14 e5 4e 00 01 	mov    DWORD PTR ds:0x4ee514,0x1
  478a39:	00 00 00 
  478a3c:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  478a3f:	50                   	push   eax
  478a40:	6a 00                	push   0x0
  478a42:	68 40 6c 47 00       	push   0x476c40
  478a47:	e8 98 ea 00 00       	call   0x4874e4
  478a4c:	83 c4 0c             	add    esp,0xc
  478a4f:	8b e5                	mov    esp,ebp
  478a51:	5d                   	pop    ebp
  478a52:	c3                   	ret
  478a53:	cc                   	int3
  478a54:	cc                   	int3
  478a55:	cc                   	int3
  478a56:	cc                   	int3
  478a57:	cc                   	int3
  478a58:	cc                   	int3
  478a59:	cc                   	int3
  478a5a:	cc                   	int3
  478a5b:	cc                   	int3
  478a5c:	cc                   	int3
  478a5d:	cc                   	int3
  478a5e:	cc                   	int3
  478a5f:	cc                   	int3
  478a60:	55                   	push   ebp
  478a61:	8b ec                	mov    ebp,esp
  478a63:	51                   	push   ecx
  478a64:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  478a67:	83 3d 14 e5 4e 00 00 	cmp    DWORD PTR ds:0x4ee514,0x0
  478a6e:	75 02                	jne    0x478a72
  478a70:	eb 43                	jmp    0x478ab5
  478a72:	c7 05 14 e5 4e 00 00 	mov    DWORD PTR ds:0x4ee514,0x0
  478a79:	00 00 00 
  478a7c:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  478a7f:	83 c1 38             	add    ecx,0x38
  478a82:	e8 49 2b fd ff       	call   0x44b5d0
  478a87:	83 3d 9c a4 4e 00 ff 	cmp    DWORD PTR ds:0x4ea49c,0xffffffff
  478a8e:	74 25                	je     0x478ab5
  478a90:	6a ff                	push   0xffffffff
  478a92:	a1 9c a4 4e 00       	mov    eax,ds:0x4ea49c
  478a97:	50                   	push   eax
  478a98:	ff 15 60 72 4c 00    	call   DWORD PTR ds:0x4c7260
  478a9e:	8b 0d 9c a4 4e 00    	mov    ecx,DWORD PTR ds:0x4ea49c
  478aa4:	51                   	push   ecx
  478aa5:	ff 15 64 72 4c 00    	call   DWORD PTR ds:0x4c7264
  478aab:	c7 05 9c a4 4e 00 ff 	mov    DWORD PTR ds:0x4ea49c,0xffffffff
  478ab2:	ff ff ff 
  478ab5:	8b e5                	mov    esp,ebp
  478ab7:	5d                   	pop    ebp
  478ab8:	c3                   	ret
  478ab9:	cc                   	int3
  478aba:	cc                   	int3
  478abb:	cc                   	int3
  478abc:	cc                   	int3
  478abd:	cc                   	int3
  478abe:	cc                   	int3
  478abf:	cc                   	int3

; launcher: patcher/update-complete-status-seven-message 0x4788ce..0x478924 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004788ce <.data>:
  4788ce:	68 98 8b 4c 00       	push   0x4c8b98
  4788d3:	ff 15 b4 70 4c 00    	call   DWORD PTR ds:0x4c70b4
  4788d9:	68 ac 8b 4c 00       	push   0x4c8bac
  4788de:	ff 15 b4 70 4c 00    	call   DWORD PTR ds:0x4c70b4
  4788e4:	68 bc 8b 4c 00       	push   0x4c8bbc
  4788e9:	68 cc 8b 4c 00       	push   0x4c8bcc
  4788ee:	ff 15 b0 70 4c 00    	call   DWORD PTR ds:0x4c70b0
  4788f4:	8b 85 e8 f3 ff ff    	mov    eax,DWORD PTR [ebp-0xc18]
  4788fa:	c7 80 70 01 00 00 07 	mov    DWORD PTR [eax+0x170],0x7
  478901:	00 00 00 
  478904:	6a 01                	push   0x1
  478906:	6a 00                	push   0x0
  478908:	68 d2 06 00 00       	push   0x6d2
  47890d:	8b 8d e8 f3 ff ff    	mov    ecx,DWORD PTR [ebp-0xc18]
  478913:	8b 91 78 01 00 00    	mov    edx,DWORD PTR [ecx+0x178]
  478919:	52                   	push   edx
  47891a:	ff 15 2c 73 4c 00    	call   DWORD PTR ds:0x4c732c
  478920:	c6 45 fc 12          	mov    BYTE PTR [ebp-0x4],0x12

; launcher: patcher/update-complete-message-dispatch 0x45022c..0x450254 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0045022c <.data>:
  45022c:	81 7d 0c d2 06 00 00 	cmp    DWORD PTR [ebp+0xc],0x6d2
  450233:	75 34                	jne    0x450269
  450235:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  45023c:	8d 55 fc             	lea    edx,[ebp-0x4]
  45023f:	52                   	push   edx
  450240:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  450243:	50                   	push   eax
  450244:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  450247:	51                   	push   ecx
  450248:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  45024b:	52                   	push   edx
  45024c:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  45024f:	e8 dc df ff ff       	call   0x44e230

; launcher: patcher/update-complete-controls 0x44e230..0x44e29f (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044e230 <.data>:
  44e230:	55                   	push   ebp
  44e231:	8b ec                	mov    ebp,esp
  44e233:	51                   	push   ecx
  44e234:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  44e237:	6a 05                	push   0x5
  44e239:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44e23c:	81 c1 80 00 00 00    	add    ecx,0x80
  44e242:	e8 59 28 01 00       	call   0x460aa0
  44e247:	6a 01                	push   0x1
  44e249:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44e24c:	81 c1 80 00 00 00    	add    ecx,0x80
  44e252:	e8 99 28 01 00       	call   0x460af0
  44e257:	6a 05                	push   0x5
  44e259:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44e25c:	81 c1 c8 00 00 00    	add    ecx,0xc8
  44e262:	e8 39 28 01 00       	call   0x460aa0
  44e267:	6a 01                	push   0x1
  44e269:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44e26c:	81 c1 c8 00 00 00    	add    ecx,0xc8
  44e272:	e8 79 28 01 00       	call   0x460af0
  44e277:	6a 05                	push   0x5
  44e279:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44e27c:	83 c1 38             	add    ecx,0x38
  44e27f:	e8 1c 28 01 00       	call   0x460aa0
  44e284:	6a 01                	push   0x1
  44e286:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44e289:	83 c1 38             	add    ecx,0x38
  44e28c:	e8 5f 28 01 00       	call   0x460af0
  44e291:	68 f4 01 00 00       	push   0x1f4
  44e296:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44e299:	81 c1 28 02 00 00    	add    ecx,0x228

; launcher: patcher/game-launch-enqueue-and-close 0x44ce92..0x44cee1 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044ce92 <.data>:
  44ce92:	68 d8 78 4c 00       	push   0x4c78d8
  44ce97:	8d 4d a0             	lea    ecx,[ebp-0x60]
  44ce9a:	e8 d1 38 00 00       	call   0x450770
  44ce9f:	89 85 70 ff ff ff    	mov    DWORD PTR [ebp-0x90],eax
  44cea5:	8b 8d 70 ff ff ff    	mov    ecx,DWORD PTR [ebp-0x90]
  44ceab:	89 8d 6c ff ff ff    	mov    DWORD PTR [ebp-0x94],ecx
  44ceb1:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  44ceb5:	8b 95 6c ff ff ff    	mov    edx,DWORD PTR [ebp-0x94]
  44cebb:	52                   	push   edx
  44cebc:	e8 2f 38 00 00       	call   0x4506f0
  44cec1:	8b c8                	mov    ecx,eax
  44cec3:	e8 38 39 00 00       	call   0x450800
  44cec8:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  44cecc:	8d 4d a0             	lea    ecx,[ebp-0x60]
  44cecf:	e8 6c 39 00 00       	call   0x450840
  44ced4:	0f b7 45 0c          	movzx  eax,WORD PTR [ebp+0xc]
  44ced8:	50                   	push   eax
  44ced9:	8b 4d 94             	mov    ecx,DWORD PTR [ebp-0x6c]
  44cedc:	e8 5f 03 00 00       	call   0x44d240

; launcher: patcher/launcher-close-and-quit 0x44d240..0x44d261 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044d240 <.data>:
  44d240:	55                   	push   ebp
  44d241:	8b ec                	mov    ebp,esp
  44d243:	51                   	push   ecx
  44d244:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  44d247:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  44d24a:	8b 10                	mov    edx,DWORD PTR [eax]
  44d24c:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44d24f:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  44d252:	ff d0                	call   eax
  44d254:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  44d257:	51                   	push   ecx
  44d258:	ff 15 e4 72 4c 00    	call   DWORD PTR ds:0x4c72e4
  44d25e:	8b e5                	mov    esp,ebp
  44d260:	5d                   	pop    ebp

; launcher: patcher/launcher-destroy-stops-updater 0x44cbc0..0x44cbe2 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044cbc0 <.data>:
  44cbc0:	55                   	push   ebp
  44cbc1:	8b ec                	mov    ebp,esp
  44cbc3:	51                   	push   ecx
  44cbc4:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  44cbc7:	e8 24 e4 ff ff       	call   0x44aff0
  44cbcc:	8b c8                	mov    ecx,eax
  44cbce:	e8 8d be 02 00       	call   0x478a60
  44cbd3:	e8 18 e4 ff ff       	call   0x44aff0
  44cbd8:	8b c8                	mov    ecx,eax
  44cbda:	e8 a1 a1 02 00       	call   0x476d80
  44cbdf:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]

; launcher: patcher/main-ui-before-launch-queue 0x46e850..0x46e8f8 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0046e850 <.data>:
  46e850:	55                   	push   ebp
  46e851:	8b ec                	mov    ebp,esp
  46e853:	81 ec f4 01 00 00    	sub    esp,0x1f4
  46e859:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  46e85e:	33 c5                	xor    eax,ebp
  46e860:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  46e863:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  46e866:	50                   	push   eax
  46e867:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  46e86a:	51                   	push   ecx
  46e86b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  46e86e:	52                   	push   edx
  46e86f:	e8 cc fb ff ff       	call   0x46e440
  46e874:	83 c4 0c             	add    esp,0xc
  46e877:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  46e87a:	68 e8 03 00 00       	push   0x3e8
  46e87f:	ff 15 8c 70 4c 00    	call   DWORD PTR ds:0x4c708c
  46e885:	c7 45 f8 00 00 00 00 	mov    DWORD PTR [ebp-0x8],0x0
  46e88c:	e8 5f 1e fe ff       	call   0x4506f0
  46e891:	8b c8                	mov    ecx,eax
  46e893:	e8 88 14 00 00       	call   0x46fd20
  46e898:	0f b6 c0             	movzx  eax,al
  46e89b:	85 c0                	test   eax,eax
  46e89d:	0f 85 04 03 00 00    	jne    0x46eba7
  46e8a3:	8d 4d b8             	lea    ecx,[ebp-0x48]
  46e8a6:	51                   	push   ecx
  46e8a7:	e8 44 1e fe ff       	call   0x4506f0
  46e8ac:	8b c8                	mov    ecx,eax
  46e8ae:	e8 8d 14 00 00       	call   0x46fd40
  46e8b3:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  46e8ba:	68 fc 82 4c 00       	push   0x4c82fc
  46e8bf:	8d 4d b8             	lea    ecx,[ebp-0x48]
  46e8c2:	e8 59 f6 fa ff       	call   0x41df20
  46e8c7:	50                   	push   eax
  46e8c8:	e8 c9 dd 01 00       	call   0x48c696
  46e8cd:	83 c4 08             	add    esp,0x8
  46e8d0:	85 c0                	test   eax,eax
  46e8d2:	0f 85 88 02 00 00    	jne    0x46eb60
  46e8d8:	68 18 83 4c 00       	push   0x4c8318
  46e8dd:	8d 8d 38 ff ff ff    	lea    ecx,[ebp-0xc8]
  46e8e3:	e8 48 68 fa ff       	call   0x415130
  46e8e8:	6a 00                	push   0x0
  46e8ea:	8d 8d 38 ff ff ff    	lea    ecx,[ebp-0xc8]
  46e8f0:	e8 0b 6c fa ff       	call   0x415500
  46e8f5:	0f b6 d0             	movzx  edx,al

; launcher: patcher/bin-manifest-name-checksum-and-launch-gate 0x46e8f8..0x46eb89 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0046e8f8 <.data>:
  46e8f8:	85 d2                	test   edx,edx
  46e8fa:	75 6f                	jne    0x46e96b
  46e8fc:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  46e903:	68 96 00 00 00       	push   0x96
  46e908:	8d 85 c4 fe ff ff    	lea    eax,[ebp-0x13c]
  46e90e:	50                   	push   eax
  46e90f:	e8 7c 2c ff ff       	call   0x461590
  46e914:	83 c4 08             	add    esp,0x8
  46e917:	8b c8                	mov    ecx,eax
  46e919:	e8 e2 27 fe ff       	call   0x451100
  46e91e:	50                   	push   eax
  46e91f:	8d 8d c8 fe ff ff    	lea    ecx,[ebp-0x138]
  46e925:	e8 e6 2c ff ff       	call   0x461610
  46e92a:	8d 8d c8 fe ff ff    	lea    ecx,[ebp-0x138]
  46e930:	51                   	push   ecx
  46e931:	e8 2a 13 00 00       	call   0x46fc60
  46e936:	8b c8                	mov    ecx,eax
  46e938:	e8 c3 13 00 00       	call   0x46fd00
  46e93d:	8d 8d c8 fe ff ff    	lea    ecx,[ebp-0x138]
  46e943:	e8 78 f5 fa ff       	call   0x41dec0
  46e948:	8d 8d c4 fe ff ff    	lea    ecx,[ebp-0x13c]
  46e94e:	e8 8d 36 ff ff       	call   0x461fe0
  46e953:	8d 8d 38 ff ff ff    	lea    ecx,[ebp-0xc8]
  46e959:	e8 42 c9 f9 ff       	call   0x40b2a0
  46e95e:	8d 4d b8             	lea    ecx,[ebp-0x48]
  46e961:	e8 da 1e fe ff       	call   0x450840
  46e966:	e9 3c 02 00 00       	jmp    0x46eba7
  46e96b:	68 38 83 4c 00       	push   0x4c8338
  46e970:	8d 95 b4 fe ff ff    	lea    edx,[ebp-0x14c]
  46e976:	52                   	push   edx
  46e977:	68 30 83 4c 00       	push   0x4c8330
  46e97c:	8d 85 b8 fe ff ff    	lea    eax,[ebp-0x148]
  46e982:	50                   	push   eax
  46e983:	68 28 83 4c 00       	push   0x4c8328
  46e988:	8d 8d bc fe ff ff    	lea    ecx,[ebp-0x144]
  46e98e:	51                   	push   ecx
  46e98f:	8d 95 38 ff ff ff    	lea    edx,[ebp-0xc8]
  46e995:	52                   	push   edx
  46e996:	8d 8d c0 fe ff ff    	lea    ecx,[ebp-0x140]
  46e99c:	e8 ef c7 f9 ff       	call   0x40b190
  46e9a1:	8b c8                	mov    ecx,eax
  46e9a3:	e8 78 82 fa ff       	call   0x416c20
  46e9a8:	8b c8                	mov    ecx,eax
  46e9aa:	e8 71 82 fa ff       	call   0x416c20
  46e9af:	8b c8                	mov    ecx,eax
  46e9b1:	e8 6a 82 fa ff       	call   0x416c20
  46e9b6:	8b c8                	mov    ecx,eax
  46e9b8:	e8 43 38 00 00       	call   0x472200
  46e9bd:	89 45 b4             	mov    DWORD PTR [ebp-0x4c],eax
  46e9c0:	83 7d b4 00          	cmp    DWORD PTR [ebp-0x4c],0x0
  46e9c4:	0f 84 89 01 00 00    	je     0x46eb53
  46e9ca:	68 40 83 4c 00       	push   0x4c8340
  46e9cf:	8d 8d 74 fe ff ff    	lea    ecx,[ebp-0x18c]
  46e9d5:	e8 26 65 f9 ff       	call   0x404f00
  46e9da:	83 ec 1c             	sub    esp,0x1c
  46e9dd:	8b cc                	mov    ecx,esp
  46e9df:	89 a5 ac fe ff ff    	mov    DWORD PTR [ebp-0x154],esp
  46e9e5:	8d 45 b8             	lea    eax,[ebp-0x48]
  46e9e8:	50                   	push   eax
  46e9e9:	e8 22 da fd ff       	call   0x44c410
  46e9ee:	8d 8d 90 fe ff ff    	lea    ecx,[ebp-0x170]
  46e9f4:	51                   	push   ecx
  46e9f5:	e8 16 36 00 00       	call   0x472010
  46e9fa:	83 c4 20             	add    esp,0x20
  46e9fd:	8b c8                	mov    ecx,eax
  46e9ff:	e8 6c 65 f9 ff       	call   0x404f70
  46ea04:	50                   	push   eax
  46ea05:	68 72 82 4c 00       	push   0x4c8272
  46ea0a:	8d 95 74 fe ff ff    	lea    edx,[ebp-0x18c]
  46ea10:	52                   	push   edx
  46ea11:	8d 85 58 fe ff ff    	lea    eax,[ebp-0x1a8]
  46ea17:	50                   	push   eax
  46ea18:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  46ea1b:	e8 00 66 fa ff       	call   0x415020
  46ea20:	8b c8                	mov    ecx,eax
  46ea22:	e8 49 65 f9 ff       	call   0x404f70
  46ea27:	50                   	push   eax
  46ea28:	e8 06 db 01 00       	call   0x48c533
  46ea2d:	83 c4 08             	add    esp,0x8
  46ea30:	f7 d8                	neg    eax
  46ea32:	1b c0                	sbb    eax,eax
  46ea34:	83 c0 01             	add    eax,0x1
  46ea37:	88 85 b3 fe ff ff    	mov    BYTE PTR [ebp-0x14d],al
  46ea3d:	8d 8d 58 fe ff ff    	lea    ecx,[ebp-0x1a8]
  46ea43:	e8 48 65 f9 ff       	call   0x404f90
  46ea48:	8d 8d 90 fe ff ff    	lea    ecx,[ebp-0x170]
  46ea4e:	e8 3d 65 f9 ff       	call   0x404f90
  46ea53:	8d 8d 74 fe ff ff    	lea    ecx,[ebp-0x18c]
  46ea59:	e8 32 65 f9 ff       	call   0x404f90
  46ea5e:	0f b6 8d b3 fe ff ff 	movzx  ecx,BYTE PTR [ebp-0x14d]
  46ea65:	85 c9                	test   ecx,ecx
  46ea67:	0f 84 d1 00 00 00    	je     0x46eb3e
  46ea6d:	68 48 83 4c 00       	push   0x4c8348
  46ea72:	8d 8d 3c fe ff ff    	lea    ecx,[ebp-0x1c4]
  46ea78:	e8 83 64 f9 ff       	call   0x404f00
  46ea7d:	68 73 82 4c 00       	push   0x4c8273
  46ea82:	8d 95 3c fe ff ff    	lea    edx,[ebp-0x1c4]
  46ea88:	52                   	push   edx
  46ea89:	8d 85 1c ff ff ff    	lea    eax,[ebp-0xe4]
  46ea8f:	50                   	push   eax
  46ea90:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  46ea93:	e8 88 65 fa ff       	call   0x415020
  46ea98:	8d 8d 3c fe ff ff    	lea    ecx,[ebp-0x1c4]
  46ea9e:	e8 ed 64 f9 ff       	call   0x404f90
  46eaa3:	8d 8d 00 ff ff ff    	lea    ecx,[ebp-0x100]
  46eaa9:	e8 e2 66 f9 ff       	call   0x405190
  46eaae:	83 ec 1c             	sub    esp,0x1c
  46eab1:	8b cc                	mov    ecx,esp
  46eab3:	89 a5 34 fe ff ff    	mov    DWORD PTR [ebp-0x1cc],esp
  46eab9:	8d 55 b8             	lea    edx,[ebp-0x48]
  46eabc:	52                   	push   edx
  46eabd:	e8 4e d9 fd ff       	call   0x44c410
  46eac2:	8d 85 18 fe ff ff    	lea    eax,[ebp-0x1e8]
  46eac8:	50                   	push   eax
  46eac9:	e8 42 35 00 00       	call   0x472010
  46eace:	83 c4 20             	add    esp,0x20
  46ead1:	8b c8                	mov    ecx,eax
  46ead3:	e8 98 64 f9 ff       	call   0x404f70
  46ead8:	50                   	push   eax
  46ead9:	8d 8d 00 ff ff ff    	lea    ecx,[ebp-0x100]
  46eadf:	51                   	push   ecx
  46eae0:	e8 ab 32 fa ff       	call   0x411d90
  46eae5:	83 c4 08             	add    esp,0x8
  46eae8:	89 85 38 fe ff ff    	mov    DWORD PTR [ebp-0x1c8],eax
  46eaee:	8d 8d 18 fe ff ff    	lea    ecx,[ebp-0x1e8]
  46eaf4:	e8 97 64 f9 ff       	call   0x404f90
  46eaf9:	83 bd 38 fe ff ff 00 	cmp    DWORD PTR [ebp-0x1c8],0x0
  46eb00:	74 24                	je     0x46eb26
  46eb02:	8d 95 1c ff ff ff    	lea    edx,[ebp-0xe4]
  46eb08:	52                   	push   edx
  46eb09:	8d 85 00 ff ff ff    	lea    eax,[ebp-0x100]
  46eb0f:	50                   	push   eax
  46eb10:	e8 db 8b fb ff       	call   0x4276f0
  46eb15:	83 c4 08             	add    esp,0x8
  46eb18:	0f b6 c8             	movzx  ecx,al
  46eb1b:	85 c9                	test   ecx,ecx
  46eb1d:	74 07                	je     0x46eb26
  46eb1f:	c7 45 f4 01 00 00 00 	mov    DWORD PTR [ebp-0xc],0x1
  46eb26:	8d 8d 00 ff ff ff    	lea    ecx,[ebp-0x100]
  46eb2c:	e8 5f 64 f9 ff       	call   0x404f90
  46eb31:	8d 8d 1c ff ff ff    	lea    ecx,[ebp-0xe4]
  46eb37:	e8 54 64 f9 ff       	call   0x404f90
  46eb3c:	eb 15                	jmp    0x46eb53
  46eb3e:	68 54 83 4c 00       	push   0x4c8354
  46eb43:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  46eb46:	e8 b5 41 fa ff       	call   0x412d00
  46eb4b:	89 45 b4             	mov    DWORD PTR [ebp-0x4c],eax
  46eb4e:	e9 6d fe ff ff       	jmp    0x46e9c0
  46eb53:	8d 8d 38 ff ff ff    	lea    ecx,[ebp-0xc8]
  46eb59:	e8 42 c7 f9 ff       	call   0x40b2a0
  46eb5e:	eb 07                	jmp    0x46eb67
  46eb60:	c7 45 f4 01 00 00 00 	mov    DWORD PTR [ebp-0xc],0x1
  46eb67:	83 7d f4 00          	cmp    DWORD PTR [ebp-0xc],0x0
  46eb6b:	74 1c                	je     0x46eb89
  46eb6d:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  46eb70:	e8 ab f3 fa ff       	call   0x41df20
  46eb75:	50                   	push   eax
  46eb76:	8d 4d b8             	lea    ecx,[ebp-0x48]
  46eb79:	e8 a2 f3 fa ff       	call   0x41df20
  46eb7e:	50                   	push   eax
  46eb7f:	e8 cc 36 00 00       	call   0x472250
  46eb84:	83 c4 08             	add    esp,0x8
  46eb87:	eb 11                	jmp    0x46eb9a

; launcher: patcher/bin-md5-file-reader 0x411c30..0x411d90 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00411c30 <.data>:
  411c30:	55                   	push   ebp
  411c31:	8b ec                	mov    ebp,esp
  411c33:	83 e4 f8             	and    esp,0xfffffff8
  411c36:	81 ec 74 04 00 00    	sub    esp,0x474
  411c3c:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  411c41:	33 c4                	xor    eax,esp
  411c43:	89 84 24 70 04 00 00 	mov    DWORD PTR [esp+0x470],eax
  411c4a:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  411c4d:	53                   	push   ebx
  411c4e:	56                   	push   esi
  411c4f:	57                   	push   edi
  411c50:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  411c53:	68 94 d4 4c 00       	push   0x4cd494
  411c58:	50                   	push   eax
  411c59:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  411c5d:	e8 5b b3 07 00       	call   0x48cfbd
  411c62:	8b f0                	mov    esi,eax
  411c64:	83 c4 08             	add    esp,0x8
  411c67:	85 f6                	test   esi,esi
  411c69:	0f 84 fb 00 00 00    	je     0x411d6a
  411c6f:	8d 44 24 10          	lea    eax,[esp+0x10]
  411c73:	50                   	push   eax
  411c74:	e8 77 4b 0a 00       	call   0x4b67f0
  411c79:	68 00 04 00 00       	push   0x400
  411c7e:	8d 8c 24 80 00 00 00 	lea    ecx,[esp+0x80]
  411c85:	6a 00                	push   0x0
  411c87:	51                   	push   ecx
  411c88:	e8 03 66 07 00       	call   0x488290
  411c8d:	56                   	push   esi
  411c8e:	e8 34 b2 07 00       	call   0x48cec7
  411c93:	50                   	push   eax
  411c94:	e8 2f b1 07 00       	call   0x48cdc8
  411c99:	8b d8                	mov    ebx,eax
  411c9b:	83 c4 18             	add    esp,0x18
  411c9e:	81 fb 00 04 00 00    	cmp    ebx,0x400
  411ca4:	7e 4c                	jle    0x411cf2
  411ca6:	8d bb ff fb ff ff    	lea    edi,[ebx-0x401]
  411cac:	c1 ef 0a             	shr    edi,0xa
  411caf:	47                   	inc    edi
  411cb0:	8b d7                	mov    edx,edi
  411cb2:	69 d2 00 fc ff ff    	imul   edx,edx,0xfffffc00
  411cb8:	03 da                	add    ebx,edx
  411cba:	56                   	push   esi
  411cbb:	6a 01                	push   0x1
  411cbd:	8d 84 24 80 00 00 00 	lea    eax,[esp+0x80]
  411cc4:	68 00 04 00 00       	push   0x400
  411cc9:	50                   	push   eax
  411cca:	e8 a7 b7 07 00       	call   0x48d476
  411ccf:	68 00 04 00 00       	push   0x400
  411cd4:	8d 8c 24 8c 00 00 00 	lea    ecx,[esp+0x8c]
  411cdb:	51                   	push   ecx
  411cdc:	8d 54 24 28          	lea    edx,[esp+0x28]
  411ce0:	52                   	push   edx
  411ce1:	e8 ca 4c 0a 00       	call   0x4b69b0
  411ce6:	83 c4 1c             	add    esp,0x1c
  411ce9:	83 ef 01             	sub    edi,0x1
  411cec:	75 cc                	jne    0x411cba
  411cee:	8b 7c 24 0c          	mov    edi,DWORD PTR [esp+0xc]
  411cf2:	56                   	push   esi
  411cf3:	6a 01                	push   0x1
  411cf5:	8d 84 24 80 00 00 00 	lea    eax,[esp+0x80]
  411cfc:	53                   	push   ebx
  411cfd:	50                   	push   eax
  411cfe:	e8 73 b7 07 00       	call   0x48d476
  411d03:	53                   	push   ebx
  411d04:	8d 8c 24 8c 00 00 00 	lea    ecx,[esp+0x8c]
  411d0b:	51                   	push   ecx
  411d0c:	8d 54 24 28          	lea    edx,[esp+0x28]
  411d10:	52                   	push   edx
  411d11:	e8 9a 4c 0a 00       	call   0x4b69b0
  411d16:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  411d1a:	50                   	push   eax
  411d1b:	e8 10 4b 0a 00       	call   0x4b6830
  411d20:	8b 8c 24 88 00 00 00 	mov    ecx,DWORD PTR [esp+0x88]
  411d27:	8b 94 24 8c 00 00 00 	mov    edx,DWORD PTR [esp+0x8c]
  411d2e:	8b 84 24 90 00 00 00 	mov    eax,DWORD PTR [esp+0x90]
  411d35:	89 0f                	mov    DWORD PTR [edi],ecx
  411d37:	8b 8c 24 94 00 00 00 	mov    ecx,DWORD PTR [esp+0x94]
  411d3e:	89 57 04             	mov    DWORD PTR [edi+0x4],edx
  411d41:	89 47 08             	mov    DWORD PTR [edi+0x8],eax
  411d44:	56                   	push   esi
  411d45:	89 4f 0c             	mov    DWORD PTR [edi+0xc],ecx
  411d48:	e8 c7 58 07 00       	call   0x487614
  411d4d:	83 c4 24             	add    esp,0x24
  411d50:	b8 01 00 00 00       	mov    eax,0x1
  411d55:	5f                   	pop    edi
  411d56:	5e                   	pop    esi
  411d57:	5b                   	pop    ebx
  411d58:	8b 8c 24 70 04 00 00 	mov    ecx,DWORD PTR [esp+0x470]
  411d5f:	33 cc                	xor    ecx,esp
  411d61:	e8 6e 56 07 00       	call   0x4873d4
  411d66:	8b e5                	mov    esp,ebp
  411d68:	5d                   	pop    ebp
  411d69:	c3                   	ret
  411d6a:	8b 8c 24 7c 04 00 00 	mov    ecx,DWORD PTR [esp+0x47c]
  411d71:	5f                   	pop    edi
  411d72:	5e                   	pop    esi
  411d73:	5b                   	pop    ebx
  411d74:	33 cc                	xor    ecx,esp
  411d76:	33 c0                	xor    eax,eax
  411d78:	e8 57 56 07 00       	call   0x4873d4
  411d7d:	8b e5                	mov    esp,ebp
  411d7f:	5d                   	pop    ebp
  411d80:	c3                   	ret
  411d81:	cc                   	int3
  411d82:	cc                   	int3
  411d83:	cc                   	int3
  411d84:	cc                   	int3
  411d85:	cc                   	int3
  411d86:	cc                   	int3
  411d87:	cc                   	int3
  411d88:	cc                   	int3
  411d89:	cc                   	int3
  411d8a:	cc                   	int3
  411d8b:	cc                   	int3
  411d8c:	cc                   	int3
  411d8d:	cc                   	int3
  411d8e:	cc                   	int3
  411d8f:	cc                   	int3

; launcher: patcher/bin-md5-hex-render 0x411d90..0x411e0e (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00411d90 <.data>:
  411d90:	83 ec 18             	sub    esp,0x18
  411d93:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  411d98:	33 c4                	xor    eax,esp
  411d9a:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  411d9e:	53                   	push   ebx
  411d9f:	56                   	push   esi
  411da0:	8b 74 24 28          	mov    esi,DWORD PTR [esp+0x28]
  411da4:	57                   	push   edi
  411da5:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  411da9:	68 58 25 4d 00       	push   0x4d2558
  411dae:	8b cf                	mov    ecx,edi
  411db0:	e8 4b 28 ff ff       	call   0x404600
  411db5:	8d 44 24 10          	lea    eax,[esp+0x10]
  411db9:	56                   	push   esi
  411dba:	50                   	push   eax
  411dbb:	e8 70 fe ff ff       	call   0x411c30
  411dc0:	8b d8                	mov    ebx,eax
  411dc2:	83 c4 08             	add    esp,0x8
  411dc5:	85 db                	test   ebx,ebx
  411dc7:	74 33                	je     0x411dfc
  411dc9:	33 f6                	xor    esi,esi
  411dcb:	eb 03                	jmp    0x411dd0
  411dcd:	8d 49 00             	lea    ecx,[ecx+0x0]
  411dd0:	0f b6 4c 34 10       	movzx  ecx,BYTE PTR [esp+esi*1+0x10]
  411dd5:	51                   	push   ecx
  411dd6:	8d 54 24 10          	lea    edx,[esp+0x10]
  411dda:	68 4c 25 4d 00       	push   0x4d254c
  411ddf:	52                   	push   edx
  411de0:	e8 a3 bd 07 00       	call   0x48db88
  411de5:	83 c4 0c             	add    esp,0xc
  411de8:	8d 44 24 0c          	lea    eax,[esp+0xc]
  411dec:	50                   	push   eax
  411ded:	8b cf                	mov    ecx,edi
  411def:	e8 6c f8 fe ff       	call   0x401660
  411df4:	46                   	inc    esi
  411df5:	83 fe 10             	cmp    esi,0x10
  411df8:	7c d6                	jl     0x411dd0
  411dfa:	8b c3                	mov    eax,ebx
  411dfc:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  411e00:	5f                   	pop    edi
  411e01:	5e                   	pop    esi
  411e02:	5b                   	pop    ebx
  411e03:	33 cc                	xor    ecx,esp
  411e05:	e8 ca 55 07 00       	call   0x4873d4
  411e0a:	83 c4 18             	add    esp,0x18
  411e0d:	c3                   	ret

; launcher: patcher/md5-initial-state 0x4b67f0..0x4b6830 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b67f0 <.data>:
  4b67f0:	55                   	push   ebp
  4b67f1:	8b ec                	mov    ebp,esp
  4b67f3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b67f6:	c7 40 04 00 00 00 00 	mov    DWORD PTR [eax+0x4],0x0
  4b67fd:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b6800:	c7 01 00 00 00 00    	mov    DWORD PTR [ecx],0x0
  4b6806:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b6809:	c7 42 08 01 23 45 67 	mov    DWORD PTR [edx+0x8],0x67452301
  4b6810:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b6813:	c7 40 0c 89 ab cd ef 	mov    DWORD PTR [eax+0xc],0xefcdab89
  4b681a:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b681d:	c7 41 10 fe dc ba 98 	mov    DWORD PTR [ecx+0x10],0x98badcfe
  4b6824:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b6827:	c7 42 14 76 54 32 10 	mov    DWORD PTR [edx+0x14],0x10325476
  4b682e:	5d                   	pop    ebp
  4b682f:	c3                   	ret

; launcher: patcher/md5-update-to-transform 0x4b69b0..0x4b6a5f (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b69b0 <.data>:
  4b69b0:	55                   	push   ebp
  4b69b1:	8b ec                	mov    ebp,esp
  4b69b3:	83 ec 08             	sub    esp,0x8
  4b69b6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b69b9:	8b 08                	mov    ecx,DWORD PTR [eax]
  4b69bb:	c1 e9 03             	shr    ecx,0x3
  4b69be:	83 e1 3f             	and    ecx,0x3f
  4b69c1:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  4b69c4:	75 08                	jne    0x4b69ce
  4b69c6:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4b69c9:	83 e2 3f             	and    edx,0x3f
  4b69cc:	74 16                	je     0x4b69e4
  4b69ce:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4b69d1:	50                   	push   eax
  4b69d2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b69d5:	51                   	push   ecx
  4b69d6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b69d9:	52                   	push   edx
  4b69da:	e8 f1 fc ff ff       	call   0x4b66d0
  4b69df:	83 c4 0c             	add    esp,0xc
  4b69e2:	eb 77                	jmp    0x4b6a5b
  4b69e4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b69e7:	8b 08                	mov    ecx,DWORD PTR [eax]
  4b69e9:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4b69ec:	8d 04 d1             	lea    eax,[ecx+edx*8]
  4b69ef:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b69f2:	3b 01                	cmp    eax,DWORD PTR [ecx]
  4b69f4:	73 0f                	jae    0x4b6a05
  4b69f6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b69f9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4b69fc:	83 c0 01             	add    eax,0x1
  4b69ff:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b6a02:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  4b6a05:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b6a08:	8b 02                	mov    eax,DWORD PTR [edx]
  4b6a0a:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4b6a0d:	8d 14 c8             	lea    edx,[eax+ecx*8]
  4b6a10:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b6a13:	89 10                	mov    DWORD PTR [eax],edx
  4b6a15:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4b6a18:	c1 e9 1d             	shr    ecx,0x1d
  4b6a1b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b6a1e:	03 4a 04             	add    ecx,DWORD PTR [edx+0x4]
  4b6a21:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b6a24:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  4b6a27:	83 7d 10 00          	cmp    DWORD PTR [ebp+0x10],0x0
  4b6a2b:	74 2e                	je     0x4b6a5b
  4b6a2d:	c7 45 fc 40 00 00 00 	mov    DWORD PTR [ebp-0x4],0x40
  4b6a34:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b6a37:	51                   	push   ecx
  4b6a38:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b6a3b:	83 c2 08             	add    edx,0x8
  4b6a3e:	52                   	push   edx
  4b6a3f:	e8 9c ed ff ff       	call   0x4b57e0
  4b6a44:	83 c4 08             	add    esp,0x8
  4b6a47:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b6a4a:	03 45 fc             	add    eax,DWORD PTR [ebp-0x4]
  4b6a4d:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  4b6a50:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4b6a53:	2b 4d fc             	sub    ecx,DWORD PTR [ebp-0x4]
  4b6a56:	89 4d 10             	mov    DWORD PTR [ebp+0x10],ecx
  4b6a59:	eb cc                	jmp    0x4b6a27
  4b6a5b:	8b e5                	mov    esp,ebp
  4b6a5d:	5d                   	pop    ebp
  4b6a5e:	c3                   	ret

; launcher: patcher/md5-first-round-constant 0x4b57e0..0x4b5850 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

004b57e0 <.data>:
  4b57e0:	55                   	push   ebp
  4b57e1:	8b ec                	mov    ebp,esp
  4b57e3:	83 ec 10             	sub    esp,0x10
  4b57e6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b57e9:	8b 08                	mov    ecx,DWORD PTR [eax]
  4b57eb:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  4b57ee:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4b57f1:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4b57f4:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  4b57f7:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b57fa:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  4b57fd:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  4b5800:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b5803:	8b 48 0c             	mov    ecx,DWORD PTR [eax+0xc]
  4b5806:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  4b5809:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4b580c:	23 55 f0             	and    edx,DWORD PTR [ebp-0x10]
  4b580f:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  4b5812:	f7 d0                	not    eax
  4b5814:	23 45 f4             	and    eax,DWORD PTR [ebp-0xc]
  4b5817:	0b d0                	or     edx,eax
  4b5819:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b581c:	03 11                	add    edx,DWORD PTR [ecx]
  4b581e:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4b5821:	8d 8c 10 78 a4 6a d7 	lea    ecx,[eax+edx*1-0x28955b88]
  4b5828:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  4b582b:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  4b582e:	c1 e2 07             	shl    edx,0x7
  4b5831:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4b5834:	c1 e8 19             	shr    eax,0x19
  4b5837:	0b d0                	or     edx,eax
  4b5839:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  4b583c:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4b583f:	03 4d f8             	add    ecx,DWORD PTR [ebp-0x8]
  4b5842:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  4b5845:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  4b5848:	23 55 f8             	and    edx,DWORD PTR [ebp-0x8]
  4b584b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4b584e:	f7 d0                	not    eax

; launcher: patcher/launch-createprocess 0x472250..0x472380 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00472250 <.data>:
  472250:	55                   	push   ebp
  472251:	8b ec                	mov    ebp,esp
  472253:	b8 68 02 01 00       	mov    eax,0x10268
  472258:	e8 b3 57 01 00       	call   0x487a10
  47225d:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  472262:	33 c5                	xor    eax,ebp
  472264:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  472267:	6a 44                	push   0x44
  472269:	6a 00                	push   0x0
  47226b:	8d 85 a0 ff fe ff    	lea    eax,[ebp-0x10060]
  472271:	50                   	push   eax
  472272:	e8 19 60 01 00       	call   0x488290
  472277:	83 c4 0c             	add    esp,0xc
  47227a:	c7 85 a0 ff fe ff 44 	mov    DWORD PTR [ebp-0x10060],0x44
  472281:	00 00 00 
  472284:	6a 10                	push   0x10
  472286:	6a 00                	push   0x0
  472288:	8d 4d f0             	lea    ecx,[ebp-0x10]
  47228b:	51                   	push   ecx
  47228c:	e8 ff 5f 01 00       	call   0x488290
  472291:	83 c4 0c             	add    esp,0xc
  472294:	33 d2                	xor    edx,edx
  472296:	66 89 95 e8 ff fe ff 	mov    WORD PTR [ebp-0x10018],dx
  47229d:	68 fe ff 00 00       	push   0xfffe
  4722a2:	6a 00                	push   0x0
  4722a4:	8d 85 ea ff fe ff    	lea    eax,[ebp-0x10016]
  4722aa:	50                   	push   eax
  4722ab:	e8 e0 5f 01 00       	call   0x488290
  4722b0:	83 c4 0c             	add    esp,0xc
  4722b3:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4722b6:	51                   	push   ecx
  4722b7:	8d 95 e8 ff fe ff    	lea    edx,[ebp-0x10018]
  4722bd:	52                   	push   edx
  4722be:	e8 5d 02 00 00       	call   0x472520
  4722c3:	83 c4 08             	add    esp,0x8
  4722c6:	8d 45 f0             	lea    eax,[ebp-0x10]
  4722c9:	50                   	push   eax
  4722ca:	8d 8d a0 ff fe ff    	lea    ecx,[ebp-0x10060]
  4722d0:	51                   	push   ecx
  4722d1:	6a 00                	push   0x0
  4722d3:	6a 00                	push   0x0
  4722d5:	6a 00                	push   0x0
  4722d7:	6a 00                	push   0x0
  4722d9:	6a 00                	push   0x0
  4722db:	6a 00                	push   0x0
  4722dd:	8d 95 e8 ff fe ff    	lea    edx,[ebp-0x10018]
  4722e3:	52                   	push   edx
  4722e4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4722e7:	50                   	push   eax
  4722e8:	ff 15 98 70 4c 00    	call   DWORD PTR ds:0x4c7098
  4722ee:	85 c0                	test   eax,eax
  4722f0:	75 63                	jne    0x472355
  4722f2:	ff 15 54 72 4c 00    	call   DWORD PTR ds:0x4c7254
  4722f8:	89 85 9c ff fe ff    	mov    DWORD PTR [ebp-0x10064],eax
  4722fe:	81 bd 9c ff fe ff e4 	cmp    DWORD PTR [ebp-0x10064],0x2e4
  472305:	02 00 00 
  472308:	75 16                	jne    0x472320
  47230a:	6a 30                	push   0x30
  47230c:	68 e0 85 4c 00       	push   0x4c85e0
  472311:	68 bc 85 4c 00       	push   0x4c85bc
  472316:	6a 00                	push   0x0
  472318:	ff 15 dc 72 4c 00    	call   DWORD PTR ds:0x4c72dc
  47231e:	eb 31                	jmp    0x472351
  472320:	8b 8d 9c ff fe ff    	mov    ecx,DWORD PTR [ebp-0x10064]
  472326:	51                   	push   ecx
  472327:	68 ac 85 4c 00       	push   0x4c85ac
  47232c:	8d 95 98 fd fe ff    	lea    edx,[ebp-0x10268]
  472332:	52                   	push   edx
  472333:	e8 48 00 00 00       	call   0x472380
  472338:	83 c4 0c             	add    esp,0xc
  47233b:	6a 30                	push   0x30
  47233d:	68 e0 85 4c 00       	push   0x4c85e0
  472342:	8d 85 98 fd fe ff    	lea    eax,[ebp-0x10268]
  472348:	50                   	push   eax
  472349:	6a 00                	push   0x0
  47234b:	ff 15 dc 72 4c 00    	call   DWORD PTR ds:0x4c72dc
  472351:	33 c0                	xor    eax,eax
  472353:	eb 19                	jmp    0x47236e
  472355:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  472358:	51                   	push   ecx
  472359:	ff 15 64 72 4c 00    	call   DWORD PTR ds:0x4c7264
  47235f:	8b 55 f4             	mov    edx,DWORD PTR [ebp-0xc]
  472362:	52                   	push   edx
  472363:	ff 15 64 72 4c 00    	call   DWORD PTR ds:0x4c7264
  472369:	b8 01 00 00 00       	mov    eax,0x1
  47236e:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  472371:	33 cd                	xor    ecx,ebp
  472373:	e8 5c 50 01 00       	call   0x4873d4
  472378:	8b e5                	mov    esp,ebp
  47237a:	5d                   	pop    ebp
  47237b:	c3                   	ret
  47237c:	cc                   	int3
  47237d:	cc                   	int3
  47237e:	cc                   	int3
  47237f:	cc                   	int3

; launcher: patcher/launcher-working-directory 0x46e6b3..0x46e709 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0046e6b3 <.data>:
  46e6b3:	68 18 06 00 00       	push   0x618
  46e6b8:	8d 85 cc f9 ff ff    	lea    eax,[ebp-0x634]
  46e6be:	50                   	push   eax
  46e6bf:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  46e6c2:	51                   	push   ecx
  46e6c3:	ff 15 5c 72 4c 00    	call   DWORD PTR ds:0x4c725c
  46e6c9:	6a 5c                	push   0x5c
  46e6cb:	8d 95 cc f9 ff ff    	lea    edx,[ebp-0x634]
  46e6d1:	52                   	push   edx
  46e6d2:	e8 49 15 00 00       	call   0x46fc20
  46e6d7:	83 c4 08             	add    esp,0x8
  46e6da:	89 85 c0 f9 ff ff    	mov    DWORD PTR [ebp-0x640],eax
  46e6e0:	83 bd c0 f9 ff ff 00 	cmp    DWORD PTR [ebp-0x640],0x0
  46e6e7:	74 0b                	je     0x46e6f4
  46e6e9:	33 c0                	xor    eax,eax
  46e6eb:	8b 8d c0 f9 ff ff    	mov    ecx,DWORD PTR [ebp-0x640]
  46e6f1:	66 89 01             	mov    WORD PTR [ecx],ax
  46e6f4:	8d 95 cc f9 ff ff    	lea    edx,[ebp-0x634]
  46e6fa:	52                   	push   edx
  46e6fb:	ff 15 48 71 4c 00    	call   DWORD PTR ds:0x4c7148
  46e701:	85 c0                	test   eax,eax
  46e703:	0f 85 91 00 00 00    	jne    0x46e79a

; launcher: patcher/commandline-mode-and-endpoint-fields 0x44c811..0x44c888 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044c811 <.data>:
  44c811:	ff 15 50 72 4c 00    	call   DWORD PTR ds:0x4c7250
  44c817:	50                   	push   eax
  44c818:	e8 83 00 00 00       	call   0x44c8a0
  44c81d:	83 c4 04             	add    esp,0x4
  44c820:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  44c823:	89 81 b4 02 00 00    	mov    DWORD PTR [ecx+0x2b4],eax
  44c829:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  44c82c:	8b 82 b4 02 00 00    	mov    eax,DWORD PTR [edx+0x2b4]
  44c832:	50                   	push   eax
  44c833:	e8 e8 00 00 00       	call   0x44c920
  44c838:	83 c4 04             	add    esp,0x4
  44c83b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  44c83e:	83 7d f0 00          	cmp    DWORD PTR [ebp-0x10],0x0
  44c842:	74 3d                	je     0x44c881
  44c844:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  44c847:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  44c84a:	52                   	push   edx
  44c84b:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  44c84e:	81 c1 b8 02 00 00    	add    ecx,0x2b8
  44c854:	e8 37 48 00 00       	call   0x451090
  44c859:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  44c85c:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  44c85f:	51                   	push   ecx
  44c860:	e8 b2 b2 03 00       	call   0x487b17
  44c865:	83 c4 04             	add    esp,0x4
  44c868:	85 c0                	test   eax,eax
  44c86a:	76 15                	jbe    0x44c881
  44c86c:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  44c86f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  44c872:	50                   	push   eax
  44c873:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  44c876:	81 c1 d4 02 00 00    	add    ecx,0x2d4
  44c87c:	e8 0f 48 00 00       	call   0x451090
  44c881:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff

; launcher: patcher/commandline-mode-selector 0x44c8a0..0x44c91a (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044c8a0 <.data>:
  44c8a0:	55                   	push   ebp
  44c8a1:	8b ec                	mov    ebp,esp
  44c8a3:	83 ec 14             	sub    esp,0x14
  44c8a6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  44c8a9:	50                   	push   eax
  44c8aa:	8d 4d f8             	lea    ecx,[ebp-0x8]
  44c8ad:	e8 2e 4a 00 00       	call   0x4512e0
  44c8b2:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  44c8b9:	c7 45 f4 02 00 00 00 	mov    DWORD PTR [ebp-0xc],0x2
  44c8c0:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  44c8c7:	eb 09                	jmp    0x44c8d2
  44c8c9:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  44c8cc:	83 c1 01             	add    ecx,0x1
  44c8cf:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  44c8d2:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  44c8d5:	3b 55 f4             	cmp    edx,DWORD PTR [ebp-0xc]
  44c8d8:	7d 2b                	jge    0x44c905
  44c8da:	6a 00                	push   0x0
  44c8dc:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  44c8df:	8b 0c c5 a4 90 4e 00 	mov    ecx,DWORD PTR [eax*8+0x4e90a4]
  44c8e6:	51                   	push   ecx
  44c8e7:	8d 4d f8             	lea    ecx,[ebp-0x8]
  44c8ea:	e8 91 4a 00 00       	call   0x451380
  44c8ef:	83 f8 ff             	cmp    eax,0xffffffff
  44c8f2:	74 0f                	je     0x44c903
  44c8f4:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  44c8f7:	8b 04 d5 a0 90 4e 00 	mov    eax,DWORD PTR [edx*8+0x4e90a0]
  44c8fe:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  44c901:	eb 02                	jmp    0x44c905
  44c903:	eb c4                	jmp    0x44c8c9
  44c905:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  44c908:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  44c90b:	8d 4d f8             	lea    ecx,[ebp-0x8]
  44c90e:	e8 cd 56 01 00       	call   0x461fe0
  44c913:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  44c916:	8b e5                	mov    esp,ebp
  44c918:	5d                   	pop    ebp
  44c919:	c3                   	ret

; launcher: patcher/endpoint-mode-table-selection 0x44c920..0x44ca6c (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044c920 <.data>:
  44c920:	55                   	push   ebp
  44c921:	8b ec                	mov    ebp,esp
  44c923:	6a ff                	push   0xffffffff
  44c925:	68 26 ce 4b 00       	push   0x4bce26
  44c92a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  44c930:	50                   	push   eax
  44c931:	83 ec 74             	sub    esp,0x74
  44c934:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  44c939:	33 c5                	xor    eax,ebp
  44c93b:	50                   	push   eax
  44c93c:	8d 45 f4             	lea    eax,[ebp-0xc]
  44c93f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  44c945:	8d 4d cc             	lea    ecx,[ebp-0x34]
  44c948:	e8 c3 65 00 00       	call   0x452f10
  44c94d:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  44c954:	c7 45 c8 02 00 00 00 	mov    DWORD PTR [ebp-0x38],0x2
  44c95b:	c7 45 c4 00 00 00 00 	mov    DWORD PTR [ebp-0x3c],0x0
  44c962:	eb 09                	jmp    0x44c96d
  44c964:	8b 45 c4             	mov    eax,DWORD PTR [ebp-0x3c]
  44c967:	83 c0 01             	add    eax,0x1
  44c96a:	89 45 c4             	mov    DWORD PTR [ebp-0x3c],eax
  44c96d:	8b 4d c4             	mov    ecx,DWORD PTR [ebp-0x3c]
  44c970:	3b 4d c8             	cmp    ecx,DWORD PTR [ebp-0x38]
  44c973:	7d 43                	jge    0x44c9b8
  44c975:	8b 55 c4             	mov    edx,DWORD PTR [ebp-0x3c]
  44c978:	6b d2 0c             	imul   edx,edx,0xc
  44c97b:	81 c2 b0 90 4e 00    	add    edx,0x4e90b0
  44c981:	89 55 b0             	mov    DWORD PTR [ebp-0x50],edx
  44c984:	8d 45 b0             	lea    eax,[ebp-0x50]
  44c987:	50                   	push   eax
  44c988:	8b 4d c4             	mov    ecx,DWORD PTR [ebp-0x3c]
  44c98b:	6b c9 0c             	imul   ecx,ecx,0xc
  44c98e:	81 c1 b0 90 4e 00    	add    ecx,0x4e90b0
  44c994:	51                   	push   ecx
  44c995:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  44c998:	e8 a3 68 00 00       	call   0x453240
  44c99d:	50                   	push   eax
  44c99e:	8d 4d bc             	lea    ecx,[ebp-0x44]
  44c9a1:	e8 da 04 01 00       	call   0x45ce80
  44c9a6:	8d 55 bc             	lea    edx,[ebp-0x44]
  44c9a9:	52                   	push   edx
  44c9aa:	8d 45 a4             	lea    eax,[ebp-0x5c]
  44c9ad:	50                   	push   eax
  44c9ae:	8d 4d cc             	lea    ecx,[ebp-0x34]
  44c9b1:	e8 1a 66 00 00       	call   0x452fd0
  44c9b6:	eb ac                	jmp    0x44c964
  44c9b8:	8d 4d 08             	lea    ecx,[ebp+0x8]
  44c9bb:	51                   	push   ecx
  44c9bc:	8d 55 ec             	lea    edx,[ebp-0x14]
  44c9bf:	52                   	push   edx
  44c9c0:	8d 4d cc             	lea    ecx,[ebp-0x34]
  44c9c3:	e8 d8 67 00 00       	call   0x4531a0
  44c9c8:	8d 45 9c             	lea    eax,[ebp-0x64]
  44c9cb:	50                   	push   eax
  44c9cc:	8d 4d cc             	lea    ecx,[ebp-0x34]
  44c9cf:	e8 cc 65 00 00       	call   0x452fa0
  44c9d4:	50                   	push   eax
  44c9d5:	8d 4d ec             	lea    ecx,[ebp-0x14]
  44c9d8:	e8 b3 68 00 00       	call   0x453290
  44c9dd:	0f b6 c8             	movzx  ecx,al
  44c9e0:	85 c9                	test   ecx,ecx
  44c9e2:	74 22                	je     0x44ca06
  44c9e4:	c7 45 98 00 00 00 00 	mov    DWORD PTR [ebp-0x68],0x0
  44c9eb:	8d 55 98             	lea    edx,[ebp-0x68]
  44c9ee:	52                   	push   edx
  44c9ef:	8d 45 90             	lea    eax,[ebp-0x70]
  44c9f2:	50                   	push   eax
  44c9f3:	8d 4d cc             	lea    ecx,[ebp-0x34]
  44c9f6:	e8 a5 67 00 00       	call   0x4531a0
  44c9fb:	8b 08                	mov    ecx,DWORD PTR [eax]
  44c9fd:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  44ca00:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  44ca03:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  44ca06:	8d 45 88             	lea    eax,[ebp-0x78]
  44ca09:	50                   	push   eax
  44ca0a:	8d 4d cc             	lea    ecx,[ebp-0x34]
  44ca0d:	e8 8e 65 00 00       	call   0x452fa0
  44ca12:	50                   	push   eax
  44ca13:	8d 4d ec             	lea    ecx,[ebp-0x14]
  44ca16:	e8 c5 68 00 00       	call   0x4532e0
  44ca1b:	0f b6 c8             	movzx  ecx,al
  44ca1e:	85 c9                	test   ecx,ecx
  44ca20:	74 22                	je     0x44ca44
  44ca22:	8d 4d ec             	lea    ecx,[ebp-0x14]
  44ca25:	e8 46 68 00 00       	call   0x453270
  44ca2a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  44ca2d:	89 55 84             	mov    DWORD PTR [ebp-0x7c],edx
  44ca30:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  44ca37:	8d 4d cc             	lea    ecx,[ebp-0x34]
  44ca3a:	e8 21 3a 00 00       	call   0x450460
  44ca3f:	8b 45 84             	mov    eax,DWORD PTR [ebp-0x7c]
  44ca42:	eb 19                	jmp    0x44ca5d
  44ca44:	c7 45 80 00 00 00 00 	mov    DWORD PTR [ebp-0x80],0x0
  44ca4b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  44ca52:	8d 4d cc             	lea    ecx,[ebp-0x34]
  44ca55:	e8 06 3a 00 00       	call   0x450460
  44ca5a:	8b 45 80             	mov    eax,DWORD PTR [ebp-0x80]
  44ca5d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  44ca60:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  44ca67:	59                   	pop    ecx
  44ca68:	8b e5                	mov    esp,ebp
  44ca6a:	5d                   	pop    ebp
  44ca6b:	c3                   	ret

; launcher: patcher/endpoint-fields-to-updater 0x44e087..0x44e0bd (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

0044e087 <.data>:
  44e087:	68 18 79 4c 00       	push   0x4c7918
  44e08c:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  44e08f:	81 c1 d4 02 00 00    	add    ecx,0x2d4
  44e095:	e8 86 fe fc ff       	call   0x41df20
  44e09a:	50                   	push   eax
  44e09b:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  44e09e:	81 c1 b8 02 00 00    	add    ecx,0x2b8
  44e0a4:	e8 77 fe fc ff       	call   0x41df20
  44e0a9:	50                   	push   eax
  44e0aa:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  44e0ad:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  44e0b0:	52                   	push   edx
  44e0b1:	e8 3a cf ff ff       	call   0x44aff0
  44e0b6:	8b c8                	mov    ecx,eax
  44e0b8:	e8 b3 8b 02 00       	call   0x476c70

; launcher: patcher/endpoint-http-base-construction 0x476c70..0x476d1f (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00476c70 <.data>:
  476c70:	55                   	push   ebp
  476c71:	8b ec                	mov    ebp,esp
  476c73:	6a ff                	push   0xffffffff
  476c75:	68 5a f2 4b 00       	push   0x4bf25a
  476c7a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  476c80:	50                   	push   eax
  476c81:	83 ec 70             	sub    esp,0x70
  476c84:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  476c89:	33 c5                	xor    eax,ebp
  476c8b:	50                   	push   eax
  476c8c:	8d 45 f4             	lea    eax,[ebp-0xc]
  476c8f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  476c95:	89 4d 9c             	mov    DWORD PTR [ebp-0x64],ecx
  476c98:	8b 45 9c             	mov    eax,DWORD PTR [ebp-0x64]
  476c9b:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  476c9e:	89 88 78 01 00 00    	mov    DWORD PTR [eax+0x178],ecx
  476ca4:	68 f8 88 4c 00       	push   0x4c88f8
  476ca9:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  476cac:	e8 df a3 fd ff       	call   0x451090
  476cb1:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  476cb4:	52                   	push   edx
  476cb5:	8d 45 d8             	lea    eax,[ebp-0x28]
  476cb8:	50                   	push   eax
  476cb9:	e8 52 a8 00 00       	call   0x481510
  476cbe:	83 c4 08             	add    esp,0x8
  476cc1:	89 45 98             	mov    DWORD PTR [ebp-0x68],eax
  476cc4:	8b 4d 98             	mov    ecx,DWORD PTR [ebp-0x68]
  476cc7:	89 4d 94             	mov    DWORD PTR [ebp-0x6c],ecx
  476cca:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  476cd1:	8b 55 94             	mov    edx,DWORD PTR [ebp-0x6c]
  476cd4:	52                   	push   edx
  476cd5:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  476cd8:	e8 d3 a3 fd ff       	call   0x4510b0
  476cdd:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  476ce4:	8d 4d d8             	lea    ecx,[ebp-0x28]
  476ce7:	e8 d4 71 fa ff       	call   0x41dec0
  476cec:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  476cef:	50                   	push   eax
  476cf0:	8d 4d bc             	lea    ecx,[ebp-0x44]
  476cf3:	51                   	push   ecx
  476cf4:	e8 17 a8 00 00       	call   0x481510
  476cf9:	83 c4 08             	add    esp,0x8
  476cfc:	89 45 90             	mov    DWORD PTR [ebp-0x70],eax
  476cff:	8b 55 90             	mov    edx,DWORD PTR [ebp-0x70]
  476d02:	89 55 8c             	mov    DWORD PTR [ebp-0x74],edx
  476d05:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  476d0c:	8b 45 8c             	mov    eax,DWORD PTR [ebp-0x74]
  476d0f:	50                   	push   eax
  476d10:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  476d13:	e8 98 a3 fd ff       	call   0x4510b0
  476d18:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff

; launcher: patcher/url-path-slash-normalization 0x481510..0x481639 (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00481510 <.data>:
  481510:	55                   	push   ebp
  481511:	8b ec                	mov    ebp,esp
  481513:	6a ff                	push   0xffffffff
  481515:	68 21 05 4c 00       	push   0x4c0521
  48151a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  481520:	50                   	push   eax
  481521:	83 ec 28             	sub    esp,0x28
  481524:	a1 54 b3 4e 00       	mov    eax,ds:0x4eb354
  481529:	33 c5                	xor    eax,ebp
  48152b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  48152e:	50                   	push   eax
  48152f:	8d 45 f4             	lea    eax,[ebp-0xc]
  481532:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  481538:	c7 45 cc 00 00 00 00 	mov    DWORD PTR [ebp-0x34],0x0
  48153f:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  481543:	74 10                	je     0x481555
  481545:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  481548:	50                   	push   eax
  481549:	e8 c9 65 00 00       	call   0x487b17
  48154e:	83 c4 04             	add    esp,0x4
  481551:	85 c0                	test   eax,eax
  481553:	75 25                	jne    0x48157a
  481555:	68 cc 88 4c 00       	push   0x4c88cc
  48155a:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  48155d:	e8 ae 00 fe ff       	call   0x461610
  481562:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  481569:	8b 4d cc             	mov    ecx,DWORD PTR [ebp-0x34]
  48156c:	83 c9 01             	or     ecx,0x1
  48156f:	89 4d cc             	mov    DWORD PTR [ebp-0x34],ecx
  481572:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  481575:	e9 a6 00 00 00       	jmp    0x481620
  48157a:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  48157d:	52                   	push   edx
  48157e:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  481581:	e8 8a 00 fe ff       	call   0x461610
  481586:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  48158d:	c7 45 d0 00 00 00 00 	mov    DWORD PTR [ebp-0x30],0x0
  481594:	eb 09                	jmp    0x48159f
  481596:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  481599:	83 c0 01             	add    eax,0x1
  48159c:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  48159f:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4815a2:	e8 a9 ae fc ff       	call   0x44c450
  4815a7:	39 45 d0             	cmp    DWORD PTR [ebp-0x30],eax
  4815aa:	73 2a                	jae    0x4815d6
  4815ac:	8b 4d d0             	mov    ecx,DWORD PTR [ebp-0x30]
  4815af:	51                   	push   ecx
  4815b0:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4815b3:	e8 18 0e 00 00       	call   0x4823d0
  4815b8:	0f b7 10             	movzx  edx,WORD PTR [eax]
  4815bb:	83 fa 5c             	cmp    edx,0x5c
  4815be:	75 14                	jne    0x4815d4
  4815c0:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  4815c3:	50                   	push   eax
  4815c4:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4815c7:	e8 04 0e 00 00       	call   0x4823d0
  4815cc:	b9 2f 00 00 00       	mov    ecx,0x2f
  4815d1:	66 89 08             	mov    WORD PTR [eax],cx
  4815d4:	eb c0                	jmp    0x481596
  4815d6:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4815d9:	e8 92 00 fe ff       	call   0x461670
  4815de:	83 e8 01             	sub    eax,0x1
  4815e1:	50                   	push   eax
  4815e2:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4815e5:	e8 e6 0d 00 00       	call   0x4823d0
  4815ea:	0f b7 10             	movzx  edx,WORD PTR [eax]
  4815ed:	83 fa 2f             	cmp    edx,0x2f
  4815f0:	74 0a                	je     0x4815fc
  4815f2:	6a 2f                	push   0x2f
  4815f4:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4815f7:	e8 b4 0d 00 00       	call   0x4823b0
  4815fc:	8d 45 d4             	lea    eax,[ebp-0x2c]
  4815ff:	50                   	push   eax
  481600:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  481603:	e8 08 ae fc ff       	call   0x44c410
  481608:	8b 4d cc             	mov    ecx,DWORD PTR [ebp-0x34]
  48160b:	83 c9 01             	or     ecx,0x1
  48160e:	89 4d cc             	mov    DWORD PTR [ebp-0x34],ecx
  481611:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  481615:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  481618:	e8 a3 c8 f9 ff       	call   0x41dec0
  48161d:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  481620:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  481623:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  48162a:	59                   	pop    ecx
  48162b:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  48162e:	33 cd                	xor    ecx,ebp
  481630:	e8 9f 5d 00 00       	call   0x4873d4
  481635:	8b e5                	mov    esp,ebp
  481637:	5d                   	pop    ebp
  481638:	c3                   	ret

; launcher: patcher/manifest-attribute-and-node-strings 0x4d12f4..0x4d13ac (end exclusive)
; data: 6e 61 6d 65 00 00 00 00 43 68 65 63 6b 73 75 6d 00 00 00 00 46 69 6c 65 4c 65 6e 67 74 68 00 00 6e 61 6d 65 00 00 00 00 46 49 4c 45 00 00 00 00 46 49 4c 45 00 00 00 00 46 49 4c 45 00 00 00 00 46 49 4c 45 00 00 00 00 46 4f 4c 44 45 52 00 00 46 4f 4c 44 45 52 00 00 46 4f 4c 44 45 52 00 00 46 4f 4c 44 45 52 00 00 46 4f 4c 44 45 52 00 00 6e 61 6d 65 00 00 00 00 46 4f 4c 44 45 52 00 00 46 4f 4c 44 45 52 00 00 6e 61 6d 65 00 00 00 00 46 4f 4c 44 45 52 00 00 50 41 54 43 48 00 00 00 46 4f 4c 44 45 52 00 00 50 41 54 43 48 00 00 00 46 4f 4c 44 45 52 00 00

; launcher: patcher/provider-vtable-and-temp-directory 0x4c8dd8..0x4c8de8 (end exclusive)
; data: c0 a5 47 00 50 61 74 63 68 54 65 6d 70 2f 00 00

; launcher: patcher/gzip-extension-and-wrapper-vtable 0x4d4f14..0x4d4f4c (end exclusive)
; data: 2e 67 7a 00 c8 aa 4d 00 c0 e2 43 00 10 e5 43 00 80 e5 43 00 a0 e5 43 00 d0 e5 43 00 00 e6 43 00 30 e6 43 00 60 e6 43 00 80 e6 43 00 b0 e6 43 00 c0 e6 43 00 d0 e6 43 00

; launcher: patcher/plain-file-write-mode 0x4d22c0..0x4d22c4 (end exclusive)
; data: 77 62 00 00

; launcher: patcher/checksum-hex-format 0x4d254c..0x4d2558 (end exclusive)
; data: 25 30 32 78 00 00 00 00 00 04 00 00

; launcher: patcher/endpoint-mode-and-host-path-table 0x4e90a0..0x4e90c8 (end exclusive)
; data: 00 00 00 00 58 77 4c 00 01 00 00 00 9c 77 4c 00 00 00 00 00 a0 77 4c 00 f4 77 4c 00 01 00 00 00 00 78 4c 00 54 78 4c 00

; launcher: patcher/endpoint-host-and-path-strings 0x4c77a0..0x4c7860 (end exclusive)
; data: 66 00 75 00 6e 00 70 00 6c 00 65 00 77 00 6f 00 72 00 6b 00 73 00 2e 00 77 00 7a 00 63 00 64 00 6e 00 73 00 65 00 72 00 76 00 69 00 63 00 65 00 2e 00 63 00 6f 00 6d 00 2f 00 66 00 75 00 6e 00 70 00 6c 00 65 00 77 00 6f 00 72 00 6b 00 73 00 2f 00 00 00 54 00 65 00 73 00 74 00 00 00 00 00 66 00 75 00 6e 00 70 00 6c 00 65 00 77 00 6f 00 72 00 6b 00 73 00 2e 00 77 00 7a 00 63 00 64 00 6e 00 73 00 65 00 72 00 76 00 69 00 63 00 65 00 2e 00 63 00 6f 00 6d 00 2f 00 66 00 75 00 6e 00 70 00 6c 00 65 00 77 00 6f 00 72 00 6b 00 73 00 2f 00 00 00 70 00 61 00 74 00 63 00 68 00 00 00

; launcher: patcher/endpoint-http-prefix 0x4c88f8..0x4c8908 (end exclusive)
; data: 68 00 74 00 74 00 70 00 3a 00 2f 00 2f 00 00 00

; launcher: patcher/manifest-version-attribute-strings 0x4c89dc..0x4c8a10 (end exclusive)
; data: 50 41 54 43 48 00 00 00 50 61 74 63 68 43 6c 69 65 6e 74 56 65 72 73 69 6f 6e 00 00 50 41 54 43 48 00 00 00 50 61 63 6b 61 67 65 56 65 72 73 69 6f 6e 00 00

; game: scene/start-0047-consumer 0x503040..0x5030bf (end exclusive)

<verified-byte-window>:     file format binary


Disassembly of section .data:

00503040 <.data>:
  503040:	55                   	push   ebp
  503041:	8b ec                	mov    ebp,esp
  503043:	6a ff                	push   0xffffffff
  503045:	68 ae b2 93 00       	push   0x93b2ae
  50304a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  503050:	50                   	push   eax
  503051:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  503056:	33 c5                	xor    eax,ebp
  503058:	50                   	push   eax
  503059:	8d 45 f4             	lea    eax,[ebp-0xc]
  50305c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  503062:	b8 01 00 00 00       	mov    eax,0x1
  503067:	84 05 b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,al
  50306d:	75 26                	jne    0x503095
  50306f:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  503075:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  50307c:	e8 ef d0 05 00       	call   0x560170
  503081:	68 10 d1 bc 00       	push   0xbcd110
  503086:	e8 8f f2 38 00       	call   0x89231a
  50308b:	83 c4 04             	add    esp,0x4
  50308e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  503095:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503098:	0f bf 48 04          	movsx  ecx,WORD PTR [eax+0x4]
  50309c:	0f bf 50 02          	movsx  edx,WORD PTR [eax+0x2]
  5030a0:	51                   	push   ecx
  5030a1:	52                   	push   edx
  5030a2:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5030a7:	e8 b4 e6 05 00       	call   0x561760
  5030ac:	33 c0                	xor    eax,eax
  5030ae:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5030b1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5030b8:	59                   	pop    ecx
  5030b9:	8b e5                	mov    esp,ebp
  5030bb:	5d                   	pop    ebp
  5030bc:	c2 0c 00             	ret    0xc

; game: scene/local-script-path-and-map-strings 0xc10668..0xc106e9 (end exclusive)
; data: 45 76 65 6e 74 2f 53 63 65 6e 65 4c 69 73 74 2e 78 6d 6c 00 53 43 45 4e 45 53 45 54 00 00 00 00 71 75 65 73 74 49 64 78 00 00 00 00 66 75 6e 63 4e 61 6d 65 00 00 00 00 66 5f 64 6f 43 6f 54 61 73 6b 00 00 c0 cc b9 cc 20 c4 c6 be c0 c0 cc 20 bd c7 c7 e0 20 c1 df c0 d4 b4 cf b4 d9 2e 20 28 25 64 2c 20 25 64 29 00 45 76 65 6e 74 2f 53 65 71 75 65 6e 63 65 73 2f 00 00 00 00 2e 73 65 71 00

; game: scene/scene-key-attribute-string 0xc03394..0xc033a0 (end exclusive)
; data: 73 63 65 6e 65 49 64 78 00 00 00 00
