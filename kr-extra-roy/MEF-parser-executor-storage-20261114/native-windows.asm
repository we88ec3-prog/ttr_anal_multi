
# Research group: storage

WINDOW char_string_assign [0x402a70, 0x402b65)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00402a70 <.text+0x1a70>:
  402a70:	55                   	push   ebp
  402a71:	8b ec                	mov    ebp,esp
  402a73:	53                   	push   ebx
  402a74:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  402a77:	56                   	push   esi
  402a78:	8b f1                	mov    esi,ecx
  402a7a:	85 db                	test   ebx,ebx
  402a7c:	74 59                	je     0x402ad7
  402a7e:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  402a81:	83 f9 10             	cmp    ecx,0x10
  402a84:	72 04                	jb     0x402a8a
  402a86:	8b 06                	mov    eax,DWORD PTR [esi]
  402a88:	eb 02                	jmp    0x402a8c
  402a8a:	8b c6                	mov    eax,esi
  402a8c:	3b d8                	cmp    ebx,eax
  402a8e:	72 47                	jb     0x402ad7
  402a90:	83 f9 10             	cmp    ecx,0x10
  402a93:	72 04                	jb     0x402a99
  402a95:	8b 06                	mov    eax,DWORD PTR [esi]
  402a97:	eb 02                	jmp    0x402a9b
  402a99:	8b c6                	mov    eax,esi
  402a9b:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  402a9e:	03 d0                	add    edx,eax
  402aa0:	3b d3                	cmp    edx,ebx
  402aa2:	76 33                	jbe    0x402ad7
  402aa4:	83 f9 10             	cmp    ecx,0x10
  402aa7:	72 17                	jb     0x402ac0
  402aa9:	8b 06                	mov    eax,DWORD PTR [esi]
  402aab:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  402aae:	51                   	push   ecx
  402aaf:	2b d8                	sub    ebx,eax
  402ab1:	53                   	push   ebx
  402ab2:	56                   	push   esi
  402ab3:	8b ce                	mov    ecx,esi
  402ab5:	e8 86 05 00 00       	call   0x403040
  402aba:	5e                   	pop    esi
  402abb:	5b                   	pop    ebx
  402abc:	5d                   	pop    ebp
  402abd:	c2 08 00             	ret    0x8
  402ac0:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  402ac3:	8b c6                	mov    eax,esi
  402ac5:	51                   	push   ecx
  402ac6:	2b d8                	sub    ebx,eax
  402ac8:	53                   	push   ebx
  402ac9:	56                   	push   esi
  402aca:	8b ce                	mov    ecx,esi
  402acc:	e8 6f 05 00 00       	call   0x403040
  402ad1:	5e                   	pop    esi
  402ad2:	5b                   	pop    ebx
  402ad3:	5d                   	pop    ebp
  402ad4:	c2 08 00             	ret    0x8
  402ad7:	57                   	push   edi
  402ad8:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  402adb:	83 ff fe             	cmp    edi,0xfffffffe
  402ade:	76 0a                	jbe    0x402aea
  402ae0:	68 00 d2 be 00       	push   0xbed200
  402ae5:	e8 46 b0 47 00       	call   0x87db30
  402aea:	8b 46 14             	mov    eax,DWORD PTR [esi+0x14]
  402aed:	3b c7                	cmp    eax,edi
  402aef:	73 1a                	jae    0x402b0b
  402af1:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  402af4:	52                   	push   edx
  402af5:	57                   	push   edi
  402af6:	8b ce                	mov    ecx,esi
  402af8:	e8 c3 02 00 00       	call   0x402dc0
  402afd:	85 ff                	test   edi,edi
  402aff:	74 5b                	je     0x402b5c
  402b01:	83 7e 14 10          	cmp    DWORD PTR [esi+0x14],0x10
  402b05:	72 2a                	jb     0x402b31
  402b07:	8b 06                	mov    eax,DWORD PTR [esi]
  402b09:	eb 28                	jmp    0x402b33
  402b0b:	85 ff                	test   edi,edi
  402b0d:	75 f2                	jne    0x402b01
  402b0f:	89 7e 10             	mov    DWORD PTR [esi+0x10],edi
  402b12:	83 f8 10             	cmp    eax,0x10
  402b15:	72 0e                	jb     0x402b25
  402b17:	8b 06                	mov    eax,DWORD PTR [esi]
  402b19:	5f                   	pop    edi
  402b1a:	c6 00 00             	mov    BYTE PTR [eax],0x0
  402b1d:	8b c6                	mov    eax,esi
  402b1f:	5e                   	pop    esi
  402b20:	5b                   	pop    ebx
  402b21:	5d                   	pop    ebp
  402b22:	c2 08 00             	ret    0x8
  402b25:	5f                   	pop    edi
  402b26:	8b c6                	mov    eax,esi
  402b28:	5e                   	pop    esi
  402b29:	c6 00 00             	mov    BYTE PTR [eax],0x0
  402b2c:	5b                   	pop    ebx
  402b2d:	5d                   	pop    ebp
  402b2e:	c2 08 00             	ret    0x8
  402b31:	8b c6                	mov    eax,esi
  402b33:	57                   	push   edi
  402b34:	53                   	push   ebx
  402b35:	50                   	push   eax
  402b36:	e8 95 b0 49 00       	call   0x89dbd0
  402b3b:	83 c4 0c             	add    esp,0xc
  402b3e:	83 7e 14 10          	cmp    DWORD PTR [esi+0x14],0x10
  402b42:	89 7e 10             	mov    DWORD PTR [esi+0x10],edi
  402b45:	72 0f                	jb     0x402b56
  402b47:	8b 06                	mov    eax,DWORD PTR [esi]
  402b49:	c6 04 38 00          	mov    BYTE PTR [eax+edi*1],0x0
  402b4d:	5f                   	pop    edi
  402b4e:	8b c6                	mov    eax,esi
  402b50:	5e                   	pop    esi
  402b51:	5b                   	pop    ebx
  402b52:	5d                   	pop    ebp
  402b53:	c2 08 00             	ret    0x8
  402b56:	8b c6                	mov    eax,esi
  402b58:	c6 04 38 00          	mov    BYTE PTR [eax+edi*1],0x0
  402b5c:	5f                   	pop    edi
  402b5d:	8b c6                	mov    eax,esi
  402b5f:	5e                   	pop    esi
  402b60:	5b                   	pop    ebx
  402b61:	5d                   	pop    ebp
  402b62:	c2 08 00             	ret    0x8

WINDOW char_string_move [0x402bb0, 0x402c26)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00402bb0 <.text+0x1bb0>:
  402bb0:	55                   	push   ebp
  402bb1:	8b ec                	mov    ebp,esp
  402bb3:	56                   	push   esi
  402bb4:	57                   	push   edi
  402bb5:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  402bb8:	8b f1                	mov    esi,ecx
  402bba:	3b f7                	cmp    esi,edi
  402bbc:	74 60                	je     0x402c1e
  402bbe:	83 7e 14 10          	cmp    DWORD PTR [esi+0x14],0x10
  402bc2:	72 0b                	jb     0x402bcf
  402bc4:	8b 06                	mov    eax,DWORD PTR [esi]
  402bc6:	50                   	push   eax
  402bc7:	e8 40 e6 48 00       	call   0x89120c
  402bcc:	83 c4 04             	add    esp,0x4
  402bcf:	c7 46 14 0f 00 00 00 	mov    DWORD PTR [esi+0x14],0xf
  402bd6:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  402bdd:	c6 06 00             	mov    BYTE PTR [esi],0x0
  402be0:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  402be4:	73 11                	jae    0x402bf7
  402be6:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  402be9:	41                   	inc    ecx
  402bea:	51                   	push   ecx
  402beb:	57                   	push   edi
  402bec:	56                   	push   esi
  402bed:	e8 fe e6 48 00       	call   0x8912f0
  402bf2:	83 c4 0c             	add    esp,0xc
  402bf5:	eb 0a                	jmp    0x402c01
  402bf7:	8b 17                	mov    edx,DWORD PTR [edi]
  402bf9:	89 16                	mov    DWORD PTR [esi],edx
  402bfb:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  402c01:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  402c04:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  402c07:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  402c0a:	89 4e 14             	mov    DWORD PTR [esi+0x14],ecx
  402c0d:	c7 47 14 0f 00 00 00 	mov    DWORD PTR [edi+0x14],0xf
  402c14:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  402c1b:	c6 07 00             	mov    BYTE PTR [edi],0x0
  402c1e:	5f                   	pop    edi
  402c1f:	8b c6                	mov    eax,esi
  402c21:	5e                   	pop    esi
  402c22:	5d                   	pop    ebp
  402c23:	c2 04 00             	ret    0x4

WINDOW char_string_grow [0x402dc0, 0x402f29)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00402dc0 <.text+0x1dc0>:
  402dc0:	55                   	push   ebp
  402dc1:	8b ec                	mov    ebp,esp
  402dc3:	6a ff                	push   0xffffffff
  402dc5:	68 d0 8b 90 00       	push   0x908bd0
  402dca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  402dd0:	50                   	push   eax
  402dd1:	83 ec 1c             	sub    esp,0x1c
  402dd4:	53                   	push   ebx
  402dd5:	56                   	push   esi
  402dd6:	57                   	push   edi
  402dd7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  402ddc:	33 c5                	xor    eax,ebp
  402dde:	50                   	push   eax
  402ddf:	8d 45 f4             	lea    eax,[ebp-0xc]
  402de2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  402de8:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  402deb:	8b f9                	mov    edi,ecx
  402ded:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  402df0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  402df3:	8b f0                	mov    esi,eax
  402df5:	83 ce 0f             	or     esi,0xf
  402df8:	83 fe fe             	cmp    esi,0xfffffffe
  402dfb:	76 04                	jbe    0x402e01
  402dfd:	8b f0                	mov    esi,eax
  402dff:	eb 27                	jmp    0x402e28
  402e01:	8b 5f 14             	mov    ebx,DWORD PTR [edi+0x14]
  402e04:	b8 ab aa aa aa       	mov    eax,0xaaaaaaab
  402e09:	f7 e6                	mul    esi
  402e0b:	8b cb                	mov    ecx,ebx
  402e0d:	d1 e9                	shr    ecx,1
  402e0f:	d1 ea                	shr    edx,1
  402e11:	3b ca                	cmp    ecx,edx
  402e13:	76 13                	jbe    0x402e28
  402e15:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  402e1a:	2b c1                	sub    eax,ecx
  402e1c:	8d 34 19             	lea    esi,[ecx+ebx*1]
  402e1f:	3b d8                	cmp    ebx,eax
  402e21:	76 05                	jbe    0x402e28
  402e23:	be fe ff ff ff       	mov    esi,0xfffffffe
  402e28:	33 c0                	xor    eax,eax
  402e2a:	8d 4e 01             	lea    ecx,[esi+0x1]
  402e2d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  402e30:	3b c8                	cmp    ecx,eax
  402e32:	76 12                	jbe    0x402e46
  402e34:	83 f9 ff             	cmp    ecx,0xffffffff
  402e37:	77 12                	ja     0x402e4b
  402e39:	51                   	push   ecx
  402e3a:	e8 29 e4 48 00       	call   0x891268
  402e3f:	83 c4 04             	add    esp,0x4
  402e42:	85 c0                	test   eax,eax
  402e44:	74 05                	je     0x402e4b
  402e46:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  402e49:	eb 51                	jmp    0x402e9c
  402e4b:	8d 4d e8             	lea    ecx,[ebp-0x18]
  402e4e:	51                   	push   ecx
  402e4f:	8d 4d d8             	lea    ecx,[ebp-0x28]
  402e52:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  402e59:	e8 4b e2 48 00       	call   0x8910a9
  402e5e:	68 a8 57 c8 00       	push   0xc857a8
  402e63:	8d 55 d8             	lea    edx,[ebp-0x28]
  402e66:	52                   	push   edx
  402e67:	c7 45 d8 a4 2c bd 00 	mov    DWORD PTR [ebp-0x28],0xbd2ca4
  402e6e:	e8 7d 9b 49 00       	call   0x89c9f0
  402e73:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  402e76:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  402e79:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  402e7c:	40                   	inc    eax
  402e7d:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  402e80:	50                   	push   eax
  402e81:	83 c1 18             	add    ecx,0x18
  402e84:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  402e88:	e8 e3 fe ff ff       	call   0x402d70
  402e8d:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  402e90:	b8 96 2e 40 00       	mov    eax,0x402e96
  402e95:	c3                   	ret
  402e96:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  402e99:	8b 75 e4             	mov    esi,DWORD PTR [ebp-0x1c]
  402e9c:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  402e9f:	85 db                	test   ebx,ebx
  402ea1:	74 1a                	je     0x402ebd
  402ea3:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  402ea7:	72 04                	jb     0x402ead
  402ea9:	8b 07                	mov    eax,DWORD PTR [edi]
  402eab:	eb 02                	jmp    0x402eaf
  402ead:	8b c7                	mov    eax,edi
  402eaf:	53                   	push   ebx
  402eb0:	50                   	push   eax
  402eb1:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  402eb4:	50                   	push   eax
  402eb5:	e8 16 ad 49 00       	call   0x89dbd0
  402eba:	83 c4 0c             	add    esp,0xc
  402ebd:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  402ec1:	72 0b                	jb     0x402ece
  402ec3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  402ec5:	51                   	push   ecx
  402ec6:	e8 41 e3 48 00       	call   0x89120c
  402ecb:	83 c4 04             	add    esp,0x4
  402ece:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  402ed1:	c6 07 00             	mov    BYTE PTR [edi],0x0
  402ed4:	89 07                	mov    DWORD PTR [edi],eax
  402ed6:	89 77 14             	mov    DWORD PTR [edi+0x14],esi
  402ed9:	89 5f 10             	mov    DWORD PTR [edi+0x10],ebx
  402edc:	83 fe 10             	cmp    esi,0x10
  402edf:	72 02                	jb     0x402ee3
  402ee1:	8b f8                	mov    edi,eax
  402ee3:	c6 04 1f 00          	mov    BYTE PTR [edi+ebx*1],0x0
  402ee7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  402eea:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  402ef1:	59                   	pop    ecx
  402ef2:	5f                   	pop    edi
  402ef3:	5e                   	pop    esi
  402ef4:	5b                   	pop    ebx
  402ef5:	8b e5                	mov    esp,ebp
  402ef7:	5d                   	pop    ebp
  402ef8:	c2 08 00             	ret    0x8
  402efb:	8b 75 ec             	mov    esi,DWORD PTR [ebp-0x14]
  402efe:	83 7e 14 10          	cmp    DWORD PTR [esi+0x14],0x10
  402f02:	72 0b                	jb     0x402f0f
  402f04:	8b 16                	mov    edx,DWORD PTR [esi]
  402f06:	52                   	push   edx
  402f07:	e8 00 e3 48 00       	call   0x89120c
  402f0c:	83 c4 04             	add    esp,0x4
  402f0f:	6a 00                	push   0x0
  402f11:	c7 46 14 0f 00 00 00 	mov    DWORD PTR [esi+0x14],0xf
  402f18:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  402f1f:	6a 00                	push   0x0
  402f21:	c6 06 00             	mov    BYTE PTR [esi],0x0
  402f24:	e8 c7 9a 49 00       	call   0x89c9f0

WINDOW char_string_deep_copy [0x403040, 0x403126)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00403040 <.text+0x2040>:
  403040:	55                   	push   ebp
  403041:	8b ec                	mov    ebp,esp
  403043:	53                   	push   ebx
  403044:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  403047:	56                   	push   esi
  403048:	8b f1                	mov    esi,ecx
  40304a:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  40304d:	57                   	push   edi
  40304e:	8b 79 10             	mov    edi,DWORD PTR [ecx+0x10]
  403051:	3b fb                	cmp    edi,ebx
  403053:	73 0a                	jae    0x40305f
  403055:	68 10 d2 be 00       	push   0xbed210
  40305a:	e8 1e ab 47 00       	call   0x87db7d
  40305f:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  403062:	2b fb                	sub    edi,ebx
  403064:	3b c7                	cmp    eax,edi
  403066:	0f 42 f8             	cmovb  edi,eax
  403069:	3b f1                	cmp    esi,ecx
  40306b:	75 1f                	jne    0x40308c
  40306d:	6a ff                	push   0xffffffff
  40306f:	03 fb                	add    edi,ebx
  403071:	57                   	push   edi
  403072:	8b ce                	mov    ecx,esi
  403074:	e8 07 fc ff ff       	call   0x402c80
  403079:	53                   	push   ebx
  40307a:	6a 00                	push   0x0
  40307c:	8b ce                	mov    ecx,esi
  40307e:	e8 fd fb ff ff       	call   0x402c80
  403083:	5f                   	pop    edi
  403084:	8b c6                	mov    eax,esi
  403086:	5e                   	pop    esi
  403087:	5b                   	pop    ebx
  403088:	5d                   	pop    ebp
  403089:	c2 0c 00             	ret    0xc
  40308c:	83 ff fe             	cmp    edi,0xfffffffe
  40308f:	76 0a                	jbe    0x40309b
  403091:	68 00 d2 be 00       	push   0xbed200
  403096:	e8 95 aa 47 00       	call   0x87db30
  40309b:	8b 46 14             	mov    eax,DWORD PTR [esi+0x14]
  40309e:	3b c7                	cmp    eax,edi
  4030a0:	73 28                	jae    0x4030ca
  4030a2:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4030a5:	50                   	push   eax
  4030a6:	57                   	push   edi
  4030a7:	8b ce                	mov    ecx,esi
  4030a9:	e8 12 fd ff ff       	call   0x402dc0
  4030ae:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4030b1:	85 ff                	test   edi,edi
  4030b3:	74 68                	je     0x40311d
  4030b5:	b8 10 00 00 00       	mov    eax,0x10
  4030ba:	39 41 14             	cmp    DWORD PTR [ecx+0x14],eax
  4030bd:	72 02                	jb     0x4030c1
  4030bf:	8b 09                	mov    ecx,DWORD PTR [ecx]
  4030c1:	39 46 14             	cmp    DWORD PTR [esi+0x14],eax
  4030c4:	72 2a                	jb     0x4030f0
  4030c6:	8b 06                	mov    eax,DWORD PTR [esi]
  4030c8:	eb 28                	jmp    0x4030f2
  4030ca:	85 ff                	test   edi,edi
  4030cc:	75 e7                	jne    0x4030b5
  4030ce:	89 7e 10             	mov    DWORD PTR [esi+0x10],edi
  4030d1:	83 f8 10             	cmp    eax,0x10
  4030d4:	72 0e                	jb     0x4030e4
  4030d6:	8b 06                	mov    eax,DWORD PTR [esi]
  4030d8:	5f                   	pop    edi
  4030d9:	c6 00 00             	mov    BYTE PTR [eax],0x0
  4030dc:	8b c6                	mov    eax,esi
  4030de:	5e                   	pop    esi
  4030df:	5b                   	pop    ebx
  4030e0:	5d                   	pop    ebp
  4030e1:	c2 0c 00             	ret    0xc
  4030e4:	5f                   	pop    edi
  4030e5:	8b c6                	mov    eax,esi
  4030e7:	5e                   	pop    esi
  4030e8:	c6 00 00             	mov    BYTE PTR [eax],0x0
  4030eb:	5b                   	pop    ebx
  4030ec:	5d                   	pop    ebp
  4030ed:	c2 0c 00             	ret    0xc
  4030f0:	8b c6                	mov    eax,esi
  4030f2:	57                   	push   edi
  4030f3:	03 cb                	add    ecx,ebx
  4030f5:	51                   	push   ecx
  4030f6:	50                   	push   eax
  4030f7:	e8 d4 aa 49 00       	call   0x89dbd0
  4030fc:	83 c4 0c             	add    esp,0xc
  4030ff:	83 7e 14 10          	cmp    DWORD PTR [esi+0x14],0x10
  403103:	89 7e 10             	mov    DWORD PTR [esi+0x10],edi
  403106:	72 0f                	jb     0x403117
  403108:	8b 06                	mov    eax,DWORD PTR [esi]
  40310a:	c6 04 38 00          	mov    BYTE PTR [eax+edi*1],0x0
  40310e:	5f                   	pop    edi
  40310f:	8b c6                	mov    eax,esi
  403111:	5e                   	pop    esi
  403112:	5b                   	pop    ebx
  403113:	5d                   	pop    ebp
  403114:	c2 0c 00             	ret    0xc
  403117:	8b c6                	mov    eax,esi
  403119:	c6 04 38 00          	mov    BYTE PTR [eax+edi*1],0x0
  40311d:	5f                   	pop    edi
  40311e:	8b c6                	mov    eax,esi
  403120:	5e                   	pop    esi
  403121:	5b                   	pop    ebx
  403122:	5d                   	pop    ebp
  403123:	c2 0c 00             	ret    0xc

WINDOW singleton_accessor [0x425330, 0x425392)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00425330 <.text+0x24330>:
  425330:	55                   	push   ebp
  425331:	8b ec                	mov    ebp,esp
  425333:	6a ff                	push   0xffffffff
  425335:	68 6e 7c 92 00       	push   0x927c6e
  42533a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  425340:	50                   	push   eax
  425341:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  425346:	33 c5                	xor    eax,ebp
  425348:	50                   	push   eax
  425349:	8d 45 f4             	lea    eax,[ebp-0xc]
  42534c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  425352:	b8 01 00 00 00       	mov    eax,0x1
  425357:	84 05 b0 75 fb 00    	test   BYTE PTR ds:0xfb75b0,al
  42535d:	75 1f                	jne    0x42537e
  42535f:	09 05 b0 75 fb 00    	or     DWORD PTR ds:0xfb75b0,eax
  425365:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  42536c:	e8 0f ea 0c 00       	call   0x4f3d80
  425371:	68 e0 d1 bc 00       	push   0xbcd1e0
  425376:	e8 9f cf 46 00       	call   0x89231a
  42537b:	83 c4 04             	add    esp,0x4
  42537e:	b8 70 74 fb 00       	mov    eax,0xfb7470
  425383:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  425386:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  42538d:	59                   	pop    ecx
  42538e:	8b e5                	mov    esp,ebp
  425390:	5d                   	pop    ebp
  425391:	c3                   	ret

WINDOW initializer_zero_one [0x4f3d80, 0x4f3dbd)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f3d80 <.text+0xf2d80>:
  4f3d80:	55                   	push   ebp
  4f3d81:	8b ec                	mov    ebp,esp
  4f3d83:	6a ff                	push   0xffffffff
  4f3d85:	68 a2 75 92 00       	push   0x9275a2
  4f3d8a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4f3d90:	50                   	push   eax
  4f3d91:	83 ec 24             	sub    esp,0x24
  4f3d94:	53                   	push   ebx
  4f3d95:	56                   	push   esi
  4f3d96:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f3d9b:	33 c5                	xor    eax,ebp
  4f3d9d:	50                   	push   eax
  4f3d9e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4f3da1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4f3da7:	bb 01 00 00 00       	mov    ebx,0x1
  4f3dac:	33 f6                	xor    esi,esi
  4f3dae:	8b c3                	mov    eax,ebx
  4f3db0:	c7 45 e8 70 74 fb 00 	mov    DWORD PTR [ebp-0x18],0xfb7470
  4f3db7:	89 35 78 74 fb 00    	mov    DWORD PTR ds:0xfb7478,esi

WINDOW trigger_head_constructor [0x4f3efd, 0x4f3f3e)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f3efd <.text+0xf2efd>:
  4f3efd:	6a 30                	push   0x30
  4f3eff:	89 35 c8 74 fb 00    	mov    DWORD PTR ds:0xfb74c8,esi
  4f3f05:	e8 5e d3 39 00       	call   0x891268
  4f3f0a:	83 c4 04             	add    esp,0x4
  4f3f0d:	3b c6                	cmp    eax,esi
  4f3f0f:	0f 84 50 04 00 00    	je     0x4f4365
  4f3f15:	a3 c4 74 fb 00       	mov    ds:0xfb74c4,eax
  4f3f1a:	89 00                	mov    DWORD PTR [eax],eax
  4f3f1c:	a1 c4 74 fb 00       	mov    eax,ds:0xfb74c4
  4f3f21:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  4f3f24:	a1 c4 74 fb 00       	mov    eax,ds:0xfb74c4
  4f3f29:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  4f3f2c:	8b 0d c4 74 fb 00    	mov    ecx,DWORD PTR ds:0xfb74c4
  4f3f32:	88 59 2c             	mov    BYTE PTR [ecx+0x2c],bl
  4f3f35:	8b 15 c4 74 fb 00    	mov    edx,DWORD PTR ds:0xfb74c4
  4f3f3b:	88 5a 2d             	mov    BYTE PTR [edx+0x2d],bl

WINDOW initializer_return [0x4f4286, 0x4f42b1)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f4286 <.text+0xf3286>:
  4f4286:	89 35 a4 75 fb 00    	mov    DWORD PTR ds:0xfb75a4,esi
  4f428c:	89 35 a8 75 fb 00    	mov    DWORD PTR ds:0xfb75a8,esi
  4f4292:	c6 45 fc 13          	mov    BYTE PTR [ebp-0x4],0x13
  4f4296:	e8 c5 06 00 00       	call   0x4f4960
  4f429b:	b8 70 74 fb 00       	mov    eax,0xfb7470
  4f42a0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4f42a3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4f42aa:	59                   	pop    ecx
  4f42ab:	5e                   	pop    esi
  4f42ac:	5b                   	pop    ebx
  4f42ad:	8b e5                	mov    esp,ebp
  4f42af:	5d                   	pop    ebp
  4f42b0:	c3                   	ret

WINDOW trigger_tree_destructor [0x4f4842, 0x4f486e)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f4842 <.text+0xf3842>:
  4f4842:	be c0 74 fb 00       	mov    esi,0xfb74c0
  4f4847:	83 c4 04             	add    esp,0x4
  4f484a:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  4f484d:	c6 45 fc 1e          	mov    BYTE PTR [ebp-0x4],0x1e
  4f4851:	a1 c4 74 fb 00       	mov    eax,ds:0xfb74c4
  4f4856:	8b 08                	mov    ecx,DWORD PTR [eax]
  4f4858:	50                   	push   eax
  4f4859:	51                   	push   ecx
  4f485a:	8d 7d ec             	lea    edi,[ebp-0x14]
  4f485d:	e8 7e 37 00 00       	call   0x4f7fe0
  4f4862:	8b 15 c4 74 fb 00    	mov    edx,DWORD PTR ds:0xfb74c4
  4f4868:	52                   	push   edx
  4f4869:	e8 9e c9 39 00       	call   0x89120c

WINDOW maplist_trigger_writer [0x4f5640, 0x4f58e3)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f5640 <.text+0xf4640>:
  4f5640:	55                   	push   ebp
  4f5641:	8b ec                	mov    ebp,esp
  4f5643:	6a ff                	push   0xffffffff
  4f5645:	68 81 47 92 00       	push   0x924781
  4f564a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4f5650:	50                   	push   eax
  4f5651:	81 ec ec 01 00 00    	sub    esp,0x1ec
  4f5657:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f565c:	33 c5                	xor    eax,ebp
  4f565e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4f5661:	53                   	push   ebx
  4f5662:	56                   	push   esi
  4f5663:	57                   	push   edi
  4f5664:	50                   	push   eax
  4f5665:	8d 45 f4             	lea    eax,[ebp-0xc]
  4f5668:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4f566e:	8d 85 90 fe ff ff    	lea    eax,[ebp-0x170]
  4f5674:	50                   	push   eax
  4f5675:	b9 b4 d4 c0 00       	mov    ecx,0xc0d4b4
  4f567a:	e8 b1 97 23 00       	call   0x72ee30
  4f567f:	33 db                	xor    ebx,ebx
  4f5681:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4f5684:	83 bd c4 fe ff ff 10 	cmp    DWORD PTR [ebp-0x13c],0x10
  4f568b:	8b 8d b0 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x150]
  4f5691:	73 06                	jae    0x4f5699
  4f5693:	8d 8d b0 fe ff ff    	lea    ecx,[ebp-0x150]
  4f5699:	53                   	push   ebx
  4f569a:	8d b5 90 fe ff ff    	lea    esi,[ebp-0x170]
  4f56a0:	e8 6b 9a 23 00       	call   0x72f110
  4f56a5:	84 c0                	test   al,al
  4f56a7:	0f 84 36 02 00 00    	je     0x4f58e3
  4f56ad:	68 c8 d4 c0 00       	push   0xc0d4c8
  4f56b2:	8b c6                	mov    eax,esi
  4f56b4:	e8 27 8c 23 00       	call   0x72e2e0
  4f56b9:	68 d0 d4 c0 00       	push   0xc0d4d0
  4f56be:	e8 1d 8c 23 00       	call   0x72e2e0
  4f56c3:	89 85 10 fe ff ff    	mov    DWORD PTR [ebp-0x1f0],eax
  4f56c9:	3b c3                	cmp    eax,ebx
  4f56cb:	0f 84 12 02 00 00    	je     0x4f58e3
  4f56d1:	eb 06                	jmp    0x4f56d9
  4f56d3:	8b 85 10 fe ff ff    	mov    eax,DWORD PTR [ebp-0x1f0]
  4f56d9:	8b 10                	mov    edx,DWORD PTR [eax]
  4f56db:	8b c8                	mov    ecx,eax
  4f56dd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4f56e0:	ff d0                	call   eax
  4f56e2:	3b c3                	cmp    eax,ebx
  4f56e4:	0f 84 e2 01 00 00    	je     0x4f58cc
  4f56ea:	8d 70 44             	lea    esi,[eax+0x44]
  4f56ed:	68 d0 d1 be 00       	push   0xbed1d0
  4f56f2:	8b fe                	mov    edi,esi
  4f56f4:	e8 a7 a9 23 00       	call   0x7300a0
  4f56f9:	3b c3                	cmp    eax,ebx
  4f56fb:	74 20                	je     0x4f571d
  4f56fd:	83 c0 30             	add    eax,0x30
  4f5700:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  4f5704:	72 02                	jb     0x4f5708
  4f5706:	8b 00                	mov    eax,DWORD PTR [eax]
  4f5708:	3b c3                	cmp    eax,ebx
  4f570a:	74 11                	je     0x4f571d
  4f570c:	50                   	push   eax
  4f570d:	e8 a2 c0 39 00       	call   0x8917b4
  4f5712:	83 c4 04             	add    esp,0x4
  4f5715:	89 85 14 fe ff ff    	mov    DWORD PTR [ebp-0x1ec],eax
  4f571b:	eb 06                	jmp    0x4f5723
  4f571d:	89 9d 14 fe ff ff    	mov    DWORD PTR [ebp-0x1ec],ebx
  4f5723:	68 d4 d4 c0 00       	push   0xc0d4d4
  4f5728:	8b fe                	mov    edi,esi
  4f572a:	e8 71 a9 23 00       	call   0x7300a0
  4f572f:	3b c3                	cmp    eax,ebx
  4f5731:	74 0d                	je     0x4f5740
  4f5733:	83 78 44 10          	cmp    DWORD PTR [eax+0x44],0x10
  4f5737:	8d 78 30             	lea    edi,[eax+0x30]
  4f573a:	72 06                	jb     0x4f5742
  4f573c:	8b 3f                	mov    edi,DWORD PTR [edi]
  4f573e:	eb 02                	jmp    0x4f5742
  4f5740:	33 ff                	xor    edi,edi
  4f5742:	8b c7                	mov    eax,edi
  4f5744:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  4f574b:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  4f574e:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  4f5751:	8d 50 01             	lea    edx,[eax+0x1]
  4f5754:	8a 08                	mov    cl,BYTE PTR [eax]
  4f5756:	40                   	inc    eax
  4f5757:	3a cb                	cmp    cl,bl
  4f5759:	75 f9                	jne    0x4f5754
  4f575b:	2b c2                	sub    eax,edx
  4f575d:	50                   	push   eax
  4f575e:	57                   	push   edi
  4f575f:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4f5762:	e8 09 d3 f0 ff       	call   0x402a70
  4f5767:	68 dc d4 c0 00       	push   0xc0d4dc
  4f576c:	8b fe                	mov    edi,esi
  4f576e:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4f5772:	e8 29 a9 23 00       	call   0x7300a0
  4f5777:	3b c3                	cmp    eax,ebx
  4f5779:	74 10                	je     0x4f578b
  4f577b:	83 78 44 10          	cmp    DWORD PTR [eax+0x44],0x10
  4f577f:	72 05                	jb     0x4f5786
  4f5781:	8b 78 30             	mov    edi,DWORD PTR [eax+0x30]
  4f5784:	eb 07                	jmp    0x4f578d
  4f5786:	8d 78 30             	lea    edi,[eax+0x30]
  4f5789:	eb 02                	jmp    0x4f578d
  4f578b:	33 ff                	xor    edi,edi
  4f578d:	8b c7                	mov    eax,edi
  4f578f:	c7 45 cc 0f 00 00 00 	mov    DWORD PTR [ebp-0x34],0xf
  4f5796:	89 5d c8             	mov    DWORD PTR [ebp-0x38],ebx
  4f5799:	88 5d b8             	mov    BYTE PTR [ebp-0x48],bl
  4f579c:	8d 50 01             	lea    edx,[eax+0x1]
  4f579f:	90                   	nop
  4f57a0:	8a 08                	mov    cl,BYTE PTR [eax]
  4f57a2:	40                   	inc    eax
  4f57a3:	3a cb                	cmp    cl,bl
  4f57a5:	75 f9                	jne    0x4f57a0
  4f57a7:	2b c2                	sub    eax,edx
  4f57a9:	50                   	push   eax
  4f57aa:	57                   	push   edi
  4f57ab:	8d 4d b8             	lea    ecx,[ebp-0x48]
  4f57ae:	e8 bd d2 f0 ff       	call   0x402a70
  4f57b3:	68 e0 d4 c0 00       	push   0xc0d4e0
  4f57b8:	8b fe                	mov    edi,esi
  4f57ba:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  4f57be:	e8 dd a8 23 00       	call   0x7300a0
  4f57c3:	3b c3                	cmp    eax,ebx
  4f57c5:	74 10                	je     0x4f57d7
  4f57c7:	83 78 44 10          	cmp    DWORD PTR [eax+0x44],0x10
  4f57cb:	72 05                	jb     0x4f57d2
  4f57cd:	8b 78 30             	mov    edi,DWORD PTR [eax+0x30]
  4f57d0:	eb 07                	jmp    0x4f57d9
  4f57d2:	8d 78 30             	lea    edi,[eax+0x30]
  4f57d5:	eb 02                	jmp    0x4f57d9
  4f57d7:	33 ff                	xor    edi,edi
  4f57d9:	8b c7                	mov    eax,edi
  4f57db:	c7 45 b0 0f 00 00 00 	mov    DWORD PTR [ebp-0x50],0xf
  4f57e2:	89 5d ac             	mov    DWORD PTR [ebp-0x54],ebx
  4f57e5:	88 5d 9c             	mov    BYTE PTR [ebp-0x64],bl
  4f57e8:	8d 70 01             	lea    esi,[eax+0x1]
  4f57eb:	eb 03                	jmp    0x4f57f0
  4f57ed:	8d 49 00             	lea    ecx,[ecx+0x0]
  4f57f0:	8a 08                	mov    cl,BYTE PTR [eax]
  4f57f2:	40                   	inc    eax
  4f57f3:	3a cb                	cmp    cl,bl
  4f57f5:	75 f9                	jne    0x4f57f0
  4f57f7:	2b c6                	sub    eax,esi
  4f57f9:	50                   	push   eax
  4f57fa:	57                   	push   edi
  4f57fb:	8d 4d 9c             	lea    ecx,[ebp-0x64]
  4f57fe:	e8 6d d2 f0 ff       	call   0x402a70
  4f5803:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  4f5807:	8b b5 14 fe ff ff    	mov    esi,DWORD PTR [ebp-0x1ec]
  4f580d:	8d 95 0c fe ff ff    	lea    edx,[ebp-0x1f4]
  4f5813:	b9 c0 74 fb 00       	mov    ecx,0xfb74c0
  4f5818:	89 b5 0c fe ff ff    	mov    DWORD PTR [ebp-0x1f4],esi
  4f581e:	e8 cd 25 00 00       	call   0x4f7df0
  4f5823:	6a ff                	push   0xffffffff
  4f5825:	53                   	push   ebx
  4f5826:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4f5829:	51                   	push   ecx
  4f582a:	8b c8                	mov    ecx,eax
  4f582c:	e8 0f d8 f0 ff       	call   0x403040
  4f5831:	8d 95 0c fe ff ff    	lea    edx,[ebp-0x1f4]
  4f5837:	b9 b0 74 fb 00       	mov    ecx,0xfb74b0
  4f583c:	89 b5 0c fe ff ff    	mov    DWORD PTR [ebp-0x1f4],esi
  4f5842:	e8 a9 25 00 00       	call   0x4f7df0
  4f5847:	6a ff                	push   0xffffffff
  4f5849:	53                   	push   ebx
  4f584a:	8d 55 b8             	lea    edx,[ebp-0x48]
  4f584d:	52                   	push   edx
  4f584e:	8b c8                	mov    ecx,eax
  4f5850:	e8 eb d7 f0 ff       	call   0x403040
  4f5855:	8d 95 0c fe ff ff    	lea    edx,[ebp-0x1f4]
  4f585b:	b9 d0 74 fb 00       	mov    ecx,0xfb74d0
  4f5860:	89 b5 0c fe ff ff    	mov    DWORD PTR [ebp-0x1f4],esi
  4f5866:	e8 85 25 00 00       	call   0x4f7df0
  4f586b:	6a ff                	push   0xffffffff
  4f586d:	53                   	push   ebx
  4f586e:	8d 4d 9c             	lea    ecx,[ebp-0x64]
  4f5871:	51                   	push   ecx
  4f5872:	8b c8                	mov    ecx,eax
  4f5874:	e8 c7 d7 f0 ff       	call   0x403040
  4f5879:	83 7d b0 10          	cmp    DWORD PTR [ebp-0x50],0x10
  4f587d:	72 0c                	jb     0x4f588b
  4f587f:	8b 55 9c             	mov    edx,DWORD PTR [ebp-0x64]
  4f5882:	52                   	push   edx
  4f5883:	e8 84 b9 39 00       	call   0x89120c
  4f5888:	83 c4 04             	add    esp,0x4
  4f588b:	bf 10 00 00 00       	mov    edi,0x10
  4f5890:	be 0f 00 00 00       	mov    esi,0xf
  4f5895:	89 75 b0             	mov    DWORD PTR [ebp-0x50],esi
  4f5898:	89 5d ac             	mov    DWORD PTR [ebp-0x54],ebx
  4f589b:	88 5d 9c             	mov    BYTE PTR [ebp-0x64],bl
  4f589e:	39 7d cc             	cmp    DWORD PTR [ebp-0x34],edi
  4f58a1:	72 0c                	jb     0x4f58af
  4f58a3:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  4f58a6:	50                   	push   eax
  4f58a7:	e8 60 b9 39 00       	call   0x89120c
  4f58ac:	83 c4 04             	add    esp,0x4
  4f58af:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  4f58b2:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  4f58b5:	89 5d c8             	mov    DWORD PTR [ebp-0x38],ebx
  4f58b8:	88 5d b8             	mov    BYTE PTR [ebp-0x48],bl
  4f58bb:	39 7d e8             	cmp    DWORD PTR [ebp-0x18],edi
  4f58be:	72 0c                	jb     0x4f58cc
  4f58c0:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4f58c3:	51                   	push   ecx
  4f58c4:	e8 43 b9 39 00       	call   0x89120c
  4f58c9:	83 c4 04             	add    esp,0x4
  4f58cc:	8b 95 10 fe ff ff    	mov    edx,DWORD PTR [ebp-0x1f0]
  4f58d2:	8b 42 40             	mov    eax,DWORD PTR [edx+0x40]
  4f58d5:	89 85 10 fe ff ff    	mov    DWORD PTR [ebp-0x1f0],eax
  4f58db:	3b c3                	cmp    eax,ebx
  4f58dd:	0f 85 f0 fd ff ff    	jne    0x4f56d3

WINDOW maplist_xml_document_cleanup [0x4f5ced, 0x4f5d4e)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f5ced <.text+0xf4ced>:
  4f5ced:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4f5cf4:	89 b5 90 fe ff ff    	mov    DWORD PTR [ebp-0x170],esi
  4f5cfa:	39 bd f0 fe ff ff    	cmp    DWORD PTR [ebp-0x110],edi
  4f5d00:	72 0f                	jb     0x4f5d11
  4f5d02:	8b 8d dc fe ff ff    	mov    ecx,DWORD PTR [ebp-0x124]
  4f5d08:	51                   	push   ecx
  4f5d09:	e8 fe b4 39 00       	call   0x89120c
  4f5d0e:	83 c4 04             	add    esp,0x4
  4f5d11:	8d 8d 90 fe ff ff    	lea    ecx,[ebp-0x170]
  4f5d17:	c7 85 f0 fe ff ff 0f 	mov    DWORD PTR [ebp-0x110],0xf
  4f5d1e:	00 00 00 
  4f5d21:	89 9d ec fe ff ff    	mov    DWORD PTR [ebp-0x114],ebx
  4f5d27:	88 9d dc fe ff ff    	mov    BYTE PTR [ebp-0x124],bl
  4f5d2d:	e8 0e 83 23 00       	call   0x72e040
  4f5d32:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4f5d35:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4f5d3c:	59                   	pop    ecx
  4f5d3d:	5f                   	pop    edi
  4f5d3e:	5e                   	pop    esi
  4f5d3f:	5b                   	pop    ebx
  4f5d40:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4f5d43:	33 cd                	xor    ecx,ebp
  4f5d45:	e8 b7 b2 39 00       	call   0x891001
  4f5d4a:	8b e5                	mov    esp,ebp
  4f5d4c:	5d                   	pop    ebp
  4f5d4d:	c3                   	ret

WINDOW trigger_map_subscript [0x4f7df0, 0x4f7f1b)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f7df0 <.text+0xf6df0>:
  4f7df0:	55                   	push   ebp
  4f7df1:	8b ec                	mov    ebp,esp
  4f7df3:	83 e4 f8             	and    esp,0xfffffff8
  4f7df6:	6a ff                	push   0xffffffff
  4f7df8:	68 d0 74 91 00       	push   0x9174d0
  4f7dfd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4f7e03:	50                   	push   eax
  4f7e04:	83 ec 48             	sub    esp,0x48
  4f7e07:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f7e0c:	33 c4                	xor    eax,esp
  4f7e0e:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  4f7e12:	53                   	push   ebx
  4f7e13:	56                   	push   esi
  4f7e14:	57                   	push   edi
  4f7e15:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f7e1a:	33 c4                	xor    eax,esp
  4f7e1c:	50                   	push   eax
  4f7e1d:	8d 44 24 58          	lea    eax,[esp+0x58]
  4f7e21:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4f7e27:	8b f1                	mov    esi,ecx
  4f7e29:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  4f7e2c:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  4f7e2f:	33 db                	xor    ebx,ebx
  4f7e31:	8b f9                	mov    edi,ecx
  4f7e33:	38 58 2d             	cmp    BYTE PTR [eax+0x2d],bl
  4f7e36:	75 1b                	jne    0x4f7e53
  4f7e38:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4f7e3a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4f7e40:	39 48 0c             	cmp    DWORD PTR [eax+0xc],ecx
  4f7e43:	73 05                	jae    0x4f7e4a
  4f7e45:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4f7e48:	eb 04                	jmp    0x4f7e4e
  4f7e4a:	8b f8                	mov    edi,eax
  4f7e4c:	8b 00                	mov    eax,DWORD PTR [eax]
  4f7e4e:	38 58 2d             	cmp    BYTE PTR [eax+0x2d],bl
  4f7e51:	74 ed                	je     0x4f7e40
  4f7e53:	3b 7e 04             	cmp    edi,DWORD PTR [esi+0x4]
  4f7e56:	74 0b                	je     0x4f7e63
  4f7e58:	8b 02                	mov    eax,DWORD PTR [edx]
  4f7e5a:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
  4f7e5d:	0f 83 97 00 00 00    	jae    0x4f7efa
  4f7e63:	b8 0f 00 00 00       	mov    eax,0xf
  4f7e68:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  4f7e6c:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  4f7e70:	88 5c 24 34          	mov    BYTE PTR [esp+0x34],bl
  4f7e74:	89 5c 24 60          	mov    DWORD PTR [esp+0x60],ebx
  4f7e78:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4f7e7a:	8d 54 24 34          	lea    edx,[esp+0x34]
  4f7e7e:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4f7e82:	52                   	push   edx
  4f7e83:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  4f7e87:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4f7e8b:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  4f7e8f:	88 5c 24 1c          	mov    BYTE PTR [esp+0x1c],bl
  4f7e93:	e8 18 ad f0 ff       	call   0x402bb0
  4f7e98:	8d 44 24 14          	lea    eax,[esp+0x14]
  4f7e9c:	50                   	push   eax
  4f7e9d:	8b ce                	mov    ecx,esi
  4f7e9f:	c6 44 24 64 01       	mov    BYTE PTR [esp+0x64],0x1
  4f7ea4:	e8 97 1c 00 00       	call   0x4f9b40
  4f7ea9:	57                   	push   edi
  4f7eaa:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  4f7eae:	51                   	push   ecx
  4f7eaf:	8b ce                	mov    ecx,esi
  4f7eb1:	e8 ca 10 00 00       	call   0x4f8f80
  4f7eb6:	8b 74 24 10          	mov    esi,DWORD PTR [esp+0x10]
  4f7eba:	bf 10 00 00 00       	mov    edi,0x10
  4f7ebf:	39 7c 24 2c          	cmp    DWORD PTR [esp+0x2c],edi
  4f7ec3:	72 0d                	jb     0x4f7ed2
  4f7ec5:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  4f7ec9:	52                   	push   edx
  4f7eca:	e8 3d 93 39 00       	call   0x89120c
  4f7ecf:	83 c4 04             	add    esp,0x4
  4f7ed2:	c7 44 24 2c 0f 00 00 	mov    DWORD PTR [esp+0x2c],0xf
  4f7ed9:	00 
  4f7eda:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4f7ede:	88 5c 24 18          	mov    BYTE PTR [esp+0x18],bl
  4f7ee2:	39 7c 24 48          	cmp    DWORD PTR [esp+0x48],edi
  4f7ee6:	72 0d                	jb     0x4f7ef5
  4f7ee8:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  4f7eec:	50                   	push   eax
  4f7eed:	e8 1a 93 39 00       	call   0x89120c
  4f7ef2:	83 c4 04             	add    esp,0x4
  4f7ef5:	8d 46 10             	lea    eax,[esi+0x10]
  4f7ef8:	eb 03                	jmp    0x4f7efd
  4f7efa:	8d 47 10             	lea    eax,[edi+0x10]
  4f7efd:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  4f7f01:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4f7f08:	59                   	pop    ecx
  4f7f09:	5f                   	pop    edi
  4f7f0a:	5e                   	pop    esi
  4f7f0b:	5b                   	pop    ebx
  4f7f0c:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  4f7f10:	33 cc                	xor    ecx,esp
  4f7f12:	e8 ea 90 39 00       	call   0x891001
  4f7f17:	8b e5                	mov    esp,ebp
  4f7f19:	5d                   	pop    ebp
  4f7f1a:	c3                   	ret

WINDOW trigger_map_clear [0x4f7fe0, 0x4f809b)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f7fe0 <.text+0xf6fe0>:
  4f7fe0:	55                   	push   ebp
  4f7fe1:	8b ec                	mov    ebp,esp
  4f7fe3:	51                   	push   ecx
  4f7fe4:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4f7fe7:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4f7fea:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  4f7fed:	3b 08                	cmp    ecx,DWORD PTR [eax]
  4f7fef:	75 36                	jne    0x4f8027
  4f7ff1:	3b d0                	cmp    edx,eax
  4f7ff3:	75 32                	jne    0x4f8027
  4f7ff5:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4f7ff8:	50                   	push   eax
  4f7ff9:	8b ce                	mov    ecx,esi
  4f7ffb:	e8 80 c1 00 00       	call   0x504180
  4f8000:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4f8003:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  4f8006:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4f8009:	89 00                	mov    DWORD PTR [eax],eax
  4f800b:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4f800e:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  4f8011:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  4f8014:	c7 46 08 00 00 00 00 	mov    DWORD PTR [esi+0x8],0x0
  4f801b:	8b 11                	mov    edx,DWORD PTR [ecx]
  4f801d:	89 17                	mov    DWORD PTR [edi],edx
  4f801f:	8b c7                	mov    eax,edi
  4f8021:	8b e5                	mov    esp,ebp
  4f8023:	5d                   	pop    ebp
  4f8024:	c2 08 00             	ret    0x8
  4f8027:	3b ca                	cmp    ecx,edx
  4f8029:	74 66                	je     0x4f8091
  4f802b:	eb 03                	jmp    0x4f8030
  4f802d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4f8030:	80 79 2d 00          	cmp    BYTE PTR [ecx+0x2d],0x0
  4f8034:	8b d1                	mov    edx,ecx
  4f8036:	75 46                	jne    0x4f807e
  4f8038:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  4f803b:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  4f803f:	75 1e                	jne    0x4f805f
  4f8041:	8b c8                	mov    ecx,eax
  4f8043:	8b 01                	mov    eax,DWORD PTR [ecx]
  4f8045:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  4f8049:	75 0f                	jne    0x4f805a
  4f804b:	eb 03                	jmp    0x4f8050
  4f804d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4f8050:	8b c8                	mov    ecx,eax
  4f8052:	8b 01                	mov    eax,DWORD PTR [ecx]
  4f8054:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  4f8058:	74 f6                	je     0x4f8050
  4f805a:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  4f805d:	eb 1f                	jmp    0x4f807e
  4f805f:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  4f8062:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  4f8066:	75 13                	jne    0x4f807b
  4f8068:	3b 48 08             	cmp    ecx,DWORD PTR [eax+0x8]
  4f806b:	75 0e                	jne    0x4f807b
  4f806d:	8b c8                	mov    ecx,eax
  4f806f:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  4f8072:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4f8075:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  4f8079:	74 ed                	je     0x4f8068
  4f807b:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4f807e:	52                   	push   edx
  4f807f:	8d 45 fc             	lea    eax,[ebp-0x4]
  4f8082:	50                   	push   eax
  4f8083:	56                   	push   esi
  4f8084:	e8 f7 04 00 00       	call   0x4f8580
  4f8089:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4f808c:	3b 4d 0c             	cmp    ecx,DWORD PTR [ebp+0xc]
  4f808f:	75 9f                	jne    0x4f8030
  4f8091:	89 0f                	mov    DWORD PTR [edi],ecx
  4f8093:	8b c7                	mov    eax,edi
  4f8095:	8b e5                	mov    esp,ebp
  4f8097:	5d                   	pop    ebp
  4f8098:	c2 08 00             	ret    0x8

WINDOW trigger_node_allocate [0x4f9b40, 0x4f9be0)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f9b40 <.text+0xf8b40>:
  4f9b40:	55                   	push   ebp
  4f9b41:	8b ec                	mov    ebp,esp
  4f9b43:	6a ff                	push   0xffffffff
  4f9b45:	68 71 74 91 00       	push   0x917471
  4f9b4a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4f9b50:	50                   	push   eax
  4f9b51:	83 ec 18             	sub    esp,0x18
  4f9b54:	53                   	push   ebx
  4f9b55:	56                   	push   esi
  4f9b56:	57                   	push   edi
  4f9b57:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f9b5c:	33 c5                	xor    eax,ebp
  4f9b5e:	50                   	push   eax
  4f9b5f:	8d 45 f4             	lea    eax,[ebp-0xc]
  4f9b62:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4f9b68:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  4f9b6b:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4f9b6e:	8b f9                	mov    edi,ecx
  4f9b70:	6a 30                	push   0x30
  4f9b72:	e8 f1 76 39 00       	call   0x891268
  4f9b77:	8b f0                	mov    esi,eax
  4f9b79:	33 d2                	xor    edx,edx
  4f9b7b:	83 c4 04             	add    esp,0x4
  4f9b7e:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  4f9b81:	3b f2                	cmp    esi,edx
  4f9b83:	74 70                	je     0x4f9bf5
  4f9b85:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4f9b88:	89 06                	mov    DWORD PTR [esi],eax
  4f9b8a:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  4f9b8d:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  4f9b90:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4f9b93:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  4f9b96:	8d 46 0c             	lea    eax,[esi+0xc]
  4f9b99:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  4f9b9c:	66 89 56 2c          	mov    WORD PTR [esi+0x2c],dx
  4f9ba0:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4f9ba3:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4f9ba6:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4f9baa:	3b c2                	cmp    eax,edx
  4f9bac:	74 1c                	je     0x4f9bca
  4f9bae:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4f9bb0:	89 08                	mov    DWORD PTR [eax],ecx
  4f9bb2:	8d 48 04             	lea    ecx,[eax+0x4]
  4f9bb5:	83 c3 04             	add    ebx,0x4
  4f9bb8:	c7 41 14 0f 00 00 00 	mov    DWORD PTR [ecx+0x14],0xf
  4f9bbf:	89 51 10             	mov    DWORD PTR [ecx+0x10],edx
  4f9bc2:	53                   	push   ebx
  4f9bc3:	88 11                	mov    BYTE PTR [ecx],dl
  4f9bc5:	e8 e6 8f f0 ff       	call   0x402bb0
  4f9bca:	8b c6                	mov    eax,esi
  4f9bcc:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4f9bcf:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4f9bd6:	59                   	pop    ecx
  4f9bd7:	5f                   	pop    edi
  4f9bd8:	5e                   	pop    esi
  4f9bd9:	5b                   	pop    ebx
  4f9bda:	8b e5                	mov    esp,ebp
  4f9bdc:	5d                   	pop    ebp
  4f9bdd:	c2 04 00             	ret    0x4

WINDOW trigger_recursive_node_destroy [0x504180, 0x5041dc)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00504180 <.text+0x103180>:
  504180:	55                   	push   ebp
  504181:	8b ec                	mov    ebp,esp
  504183:	53                   	push   ebx
  504184:	56                   	push   esi
  504185:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  504188:	80 7e 2d 00          	cmp    BYTE PTR [esi+0x2d],0x0
  50418c:	57                   	push   edi
  50418d:	8b d9                	mov    ebx,ecx
  50418f:	8b fe                	mov    edi,esi
  504191:	75 42                	jne    0x5041d5
  504193:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  504196:	50                   	push   eax
  504197:	8b cb                	mov    ecx,ebx
  504199:	e8 e2 ff ff ff       	call   0x504180
  50419e:	83 7e 24 10          	cmp    DWORD PTR [esi+0x24],0x10
  5041a2:	8b 3f                	mov    edi,DWORD PTR [edi]
  5041a4:	72 0c                	jb     0x5041b2
  5041a6:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  5041a9:	51                   	push   ecx
  5041aa:	e8 5d d0 38 00       	call   0x89120c
  5041af:	83 c4 04             	add    esp,0x4
  5041b2:	c7 46 24 0f 00 00 00 	mov    DWORD PTR [esi+0x24],0xf
  5041b9:	c7 46 20 00 00 00 00 	mov    DWORD PTR [esi+0x20],0x0
  5041c0:	56                   	push   esi
  5041c1:	c6 46 10 00          	mov    BYTE PTR [esi+0x10],0x0
  5041c5:	e8 42 d0 38 00       	call   0x89120c
  5041ca:	83 c4 04             	add    esp,0x4
  5041cd:	80 7f 2d 00          	cmp    BYTE PTR [edi+0x2d],0x0
  5041d1:	8b f7                	mov    esi,edi
  5041d3:	74 be                	je     0x504193
  5041d5:	5f                   	pop    edi
  5041d6:	5e                   	pop    esi
  5041d7:	5b                   	pop    ebx
  5041d8:	5d                   	pop    ebp
  5041d9:	c2 04 00             	ret    0x4

WINDOW alias_helpers_6950_to_6e80 [0x4f6950, 0x4f6e80)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f6950 <.text+0xf5950>:
  4f6950:	55                   	push   ebp
  4f6951:	8b ec                	mov    ebp,esp
  4f6953:	83 ec 0c             	sub    esp,0xc
  4f6956:	53                   	push   ebx
  4f6957:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4f695a:	56                   	push   esi
  4f695b:	57                   	push   edi
  4f695c:	8b f8                	mov    edi,eax
  4f695e:	8d 45 08             	lea    eax,[ebp+0x8]
  4f6961:	8d b7 00 01 00 00    	lea    esi,[edi+0x100]
  4f6967:	50                   	push   eax
  4f6968:	8d 45 0c             	lea    eax,[ebp+0xc]
  4f696b:	8b ce                	mov    ecx,esi
  4f696d:	e8 4e cf 34 00       	call   0x8438c0
  4f6972:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4f6975:	3b 8f 04 01 00 00    	cmp    ecx,DWORD PTR [edi+0x104]
  4f697b:	74 48                	je     0x4f69c5
  4f697d:	8b c3                	mov    eax,ebx
  4f697f:	8d 50 02             	lea    edx,[eax+0x2]
  4f6982:	66 8b 08             	mov    cx,WORD PTR [eax]
  4f6985:	83 c0 02             	add    eax,0x2
  4f6988:	66 85 c9             	test   cx,cx
  4f698b:	75 f5                	jne    0x4f6982
  4f698d:	2b c2                	sub    eax,edx
  4f698f:	d1 f8                	sar    eax,1
  4f6991:	0f 84 8c 00 00 00    	je     0x4f6a23
  4f6997:	8b c3                	mov    eax,ebx
  4f6999:	8d 50 02             	lea    edx,[eax+0x2]
  4f699c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4f69a0:	66 8b 08             	mov    cx,WORD PTR [eax]
  4f69a3:	83 c0 02             	add    eax,0x2
  4f69a6:	66 85 c9             	test   cx,cx
  4f69a9:	75 f5                	jne    0x4f69a0
  4f69ab:	2b c2                	sub    eax,edx
  4f69ad:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  4f69b0:	8b 4a 10             	mov    ecx,DWORD PTR [edx+0x10]
  4f69b3:	d1 f8                	sar    eax,1
  4f69b5:	50                   	push   eax
  4f69b6:	53                   	push   ebx
  4f69b7:	e8 a4 b7 f0 ff       	call   0x402160
  4f69bc:	5f                   	pop    edi
  4f69bd:	5e                   	pop    esi
  4f69be:	5b                   	pop    ebx
  4f69bf:	8b e5                	mov    esp,ebp
  4f69c1:	5d                   	pop    ebp
  4f69c2:	c2 08 00             	ret    0x8
  4f69c5:	6a 1c                	push   0x1c
  4f69c7:	e8 9c a8 39 00       	call   0x891268
  4f69cc:	33 ff                	xor    edi,edi
  4f69ce:	83 c4 04             	add    esp,0x4
  4f69d1:	3b c7                	cmp    eax,edi
  4f69d3:	74 11                	je     0x4f69e6
  4f69d5:	89 78 10             	mov    DWORD PTR [eax+0x10],edi
  4f69d8:	33 c9                	xor    ecx,ecx
  4f69da:	c7 40 14 07 00 00 00 	mov    DWORD PTR [eax+0x14],0x7
  4f69e1:	66 89 08             	mov    WORD PTR [eax],cx
  4f69e4:	8b f8                	mov    edi,eax
  4f69e6:	8b c3                	mov    eax,ebx
  4f69e8:	8d 50 02             	lea    edx,[eax+0x2]
  4f69eb:	eb 03                	jmp    0x4f69f0
  4f69ed:	8d 49 00             	lea    ecx,[ecx+0x0]
  4f69f0:	66 8b 08             	mov    cx,WORD PTR [eax]
  4f69f3:	83 c0 02             	add    eax,0x2
  4f69f6:	66 85 c9             	test   cx,cx
  4f69f9:	75 f5                	jne    0x4f69f0
  4f69fb:	2b c2                	sub    eax,edx
  4f69fd:	d1 f8                	sar    eax,1
  4f69ff:	50                   	push   eax
  4f6a00:	53                   	push   ebx
  4f6a01:	8b cf                	mov    ecx,edi
  4f6a03:	e8 58 b7 f0 ff       	call   0x402160
  4f6a08:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4f6a0b:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4f6a0e:	8d 7d f8             	lea    edi,[ebp-0x8]
  4f6a11:	89 55 f8             	mov    DWORD PTR [ebp-0x8],edx
  4f6a14:	e8 07 85 08 00       	call   0x57ef20
  4f6a19:	50                   	push   eax
  4f6a1a:	56                   	push   esi
  4f6a1b:	8d 75 f8             	lea    esi,[ebp-0x8]
  4f6a1e:	e8 2d 7e 08 00       	call   0x57e850
  4f6a23:	5f                   	pop    edi
  4f6a24:	5e                   	pop    esi
  4f6a25:	5b                   	pop    ebx
  4f6a26:	8b e5                	mov    esp,ebp
  4f6a28:	5d                   	pop    ebp
  4f6a29:	c2 08 00             	ret    0x8
  4f6a2c:	cc                   	int3
  4f6a2d:	cc                   	int3
  4f6a2e:	cc                   	int3
  4f6a2f:	cc                   	int3
  4f6a30:	55                   	push   ebp
  4f6a31:	8b ec                	mov    ebp,esp
  4f6a33:	83 ec 10             	sub    esp,0x10
  4f6a36:	53                   	push   ebx
  4f6a37:	56                   	push   esi
  4f6a38:	57                   	push   edi
  4f6a39:	8b f8                	mov    edi,eax
  4f6a3b:	8d 45 08             	lea    eax,[ebp+0x8]
  4f6a3e:	8d b7 00 01 00 00    	lea    esi,[edi+0x100]
  4f6a44:	50                   	push   eax
  4f6a45:	8d 45 f8             	lea    eax,[ebp-0x8]
  4f6a48:	8b ce                	mov    ecx,esi
  4f6a4a:	e8 71 ce 34 00       	call   0x8438c0
  4f6a4f:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  4f6a52:	3b 87 04 01 00 00    	cmp    eax,DWORD PTR [edi+0x104]
  4f6a58:	74 18                	je     0x4f6a72
  4f6a5a:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4f6a5d:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  4f6a61:	0f 82 a2 00 00 00    	jb     0x4f6b09
  4f6a67:	8b 00                	mov    eax,DWORD PTR [eax]
  4f6a69:	5f                   	pop    edi
  4f6a6a:	5e                   	pop    esi
  4f6a6b:	5b                   	pop    ebx
  4f6a6c:	8b e5                	mov    esp,ebp
  4f6a6e:	5d                   	pop    ebp
  4f6a6f:	c2 04 00             	ret    0x4
  4f6a72:	81 c7 10 01 00 00    	add    edi,0x110
  4f6a78:	8d 45 08             	lea    eax,[ebp+0x8]
  4f6a7b:	e8 00 1c fb ff       	call   0x4a8680
  4f6a80:	6a 1c                	push   0x1c
  4f6a82:	e8 e1 a7 39 00       	call   0x891268
  4f6a87:	83 c4 04             	add    esp,0x4
  4f6a8a:	85 c0                	test   eax,eax
  4f6a8c:	74 17                	je     0x4f6aa5
  4f6a8e:	33 c9                	xor    ecx,ecx
  4f6a90:	c7 40 14 07 00 00 00 	mov    DWORD PTR [eax+0x14],0x7
  4f6a97:	c7 40 10 00 00 00 00 	mov    DWORD PTR [eax+0x10],0x0
  4f6a9e:	66 89 08             	mov    WORD PTR [eax],cx
  4f6aa1:	8b d8                	mov    ebx,eax
  4f6aa3:	eb 02                	jmp    0x4f6aa7
  4f6aa5:	33 db                	xor    ebx,ebx
  4f6aa7:	8b 43 10             	mov    eax,DWORD PTR [ebx+0x10]
  4f6aaa:	8b cb                	mov    ecx,ebx
  4f6aac:	83 f8 14             	cmp    eax,0x14
  4f6aaf:	72 0b                	jb     0x4f6abc
  4f6ab1:	6a ff                	push   0xffffffff
  4f6ab3:	6a 14                	push   0x14
  4f6ab5:	e8 46 b9 f0 ff       	call   0x402400
  4f6aba:	eb 0f                	jmp    0x4f6acb
  4f6abc:	ba 14 00 00 00       	mov    edx,0x14
  4f6ac1:	6a 00                	push   0x0
  4f6ac3:	2b d0                	sub    edx,eax
  4f6ac5:	52                   	push   edx
  4f6ac6:	e8 45 95 f4 ff       	call   0x440010
  4f6acb:	6a ff                	push   0xffffffff
  4f6acd:	6a 00                	push   0x0
  4f6acf:	68 9c aa e2 00       	push   0xe2aa9c
  4f6ad4:	8b cb                	mov    ecx,ebx
  4f6ad6:	e8 05 bc f0 ff       	call   0x4026e0
  4f6adb:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4f6ade:	8d 7d f4             	lea    edi,[ebp-0xc]
  4f6ae1:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  4f6ae4:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  4f6ae7:	e8 34 84 08 00       	call   0x57ef20
  4f6aec:	50                   	push   eax
  4f6aed:	56                   	push   esi
  4f6aee:	8d 75 f4             	lea    esi,[ebp-0xc]
  4f6af1:	e8 5a 7d 08 00       	call   0x57e850
  4f6af6:	83 7b 14 08          	cmp    DWORD PTR [ebx+0x14],0x8
  4f6afa:	72 0b                	jb     0x4f6b07
  4f6afc:	8b 03                	mov    eax,DWORD PTR [ebx]
  4f6afe:	5f                   	pop    edi
  4f6aff:	5e                   	pop    esi
  4f6b00:	5b                   	pop    ebx
  4f6b01:	8b e5                	mov    esp,ebp
  4f6b03:	5d                   	pop    ebp
  4f6b04:	c2 04 00             	ret    0x4
  4f6b07:	8b c3                	mov    eax,ebx
  4f6b09:	5f                   	pop    edi
  4f6b0a:	5e                   	pop    esi
  4f6b0b:	5b                   	pop    ebx
  4f6b0c:	8b e5                	mov    esp,ebp
  4f6b0e:	5d                   	pop    ebp
  4f6b0f:	c2 04 00             	ret    0x4
  4f6b12:	cc                   	int3
  4f6b13:	cc                   	int3
  4f6b14:	cc                   	int3
  4f6b15:	cc                   	int3
  4f6b16:	cc                   	int3
  4f6b17:	cc                   	int3
  4f6b18:	cc                   	int3
  4f6b19:	cc                   	int3
  4f6b1a:	cc                   	int3
  4f6b1b:	cc                   	int3
  4f6b1c:	cc                   	int3
  4f6b1d:	cc                   	int3
  4f6b1e:	cc                   	int3
  4f6b1f:	cc                   	int3
  4f6b20:	55                   	push   ebp
  4f6b21:	8b ec                	mov    ebp,esp
  4f6b23:	51                   	push   ecx
  4f6b24:	56                   	push   esi
  4f6b25:	8b f0                	mov    esi,eax
  4f6b27:	8d 45 08             	lea    eax,[ebp+0x8]
  4f6b2a:	50                   	push   eax
  4f6b2b:	8d 8f 00 01 00 00    	lea    ecx,[edi+0x100]
  4f6b31:	8d 45 fc             	lea    eax,[ebp-0x4]
  4f6b34:	e8 87 cd 34 00       	call   0x8438c0
  4f6b39:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4f6b3c:	3b 87 04 01 00 00    	cmp    eax,DWORD PTR [edi+0x104]
  4f6b42:	74 18                	je     0x4f6b5c
  4f6b44:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  4f6b47:	6a ff                	push   0xffffffff
  4f6b49:	6a 00                	push   0x0
  4f6b4b:	51                   	push   ecx
  4f6b4c:	8b ce                	mov    ecx,esi
  4f6b4e:	e8 8d bb f0 ff       	call   0x4026e0
  4f6b53:	b0 01                	mov    al,0x1
  4f6b55:	5e                   	pop    esi
  4f6b56:	8b e5                	mov    esp,ebp
  4f6b58:	5d                   	pop    ebp
  4f6b59:	c2 04 00             	ret    0x4
  4f6b5c:	83 7e 14 08          	cmp    DWORD PTR [esi+0x14],0x8
  4f6b60:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4f6b67:	72 02                	jb     0x4f6b6b
  4f6b69:	8b 36                	mov    esi,DWORD PTR [esi]
  4f6b6b:	33 d2                	xor    edx,edx
  4f6b6d:	66 89 16             	mov    WORD PTR [esi],dx
  4f6b70:	32 c0                	xor    al,al
  4f6b72:	5e                   	pop    esi
  4f6b73:	8b e5                	mov    esp,ebp
  4f6b75:	5d                   	pop    ebp
  4f6b76:	c2 04 00             	ret    0x4
  4f6b79:	cc                   	int3
  4f6b7a:	cc                   	int3
  4f6b7b:	cc                   	int3
  4f6b7c:	cc                   	int3
  4f6b7d:	cc                   	int3
  4f6b7e:	cc                   	int3
  4f6b7f:	cc                   	int3
  4f6b80:	55                   	push   ebp
  4f6b81:	8b ec                	mov    ebp,esp
  4f6b83:	b8 0c 20 00 00       	mov    eax,0x200c
  4f6b88:	e8 e3 9a 3b 00       	call   0x8b0670
  4f6b8d:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f6b92:	33 c5                	xor    eax,ebp
  4f6b94:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4f6b97:	8b 86 14 01 00 00    	mov    eax,DWORD PTR [esi+0x114]
  4f6b9d:	53                   	push   ebx
  4f6b9e:	57                   	push   edi
  4f6b9f:	8b be 10 01 00 00    	mov    edi,DWORD PTR [esi+0x110]
  4f6ba5:	3b f8                	cmp    edi,eax
  4f6ba7:	0f 84 a2 00 00 00    	je     0x4f6c4f
  4f6bad:	b9 13 00 00 00       	mov    ecx,0x13
  4f6bb2:	2b c7                	sub    eax,edi
  4f6bb4:	33 d2                	xor    edx,edx
  4f6bb6:	66 89 8d f8 ef ff ff 	mov    WORD PTR [ebp-0x1008],cx
  4f6bbd:	ba 02 00 00 00       	mov    edx,0x2
  4f6bc2:	c1 f8 02             	sar    eax,0x2
  4f6bc5:	33 c9                	xor    ecx,ecx
  4f6bc7:	89 55 f8             	mov    DWORD PTR [ebp-0x8],edx
  4f6bca:	85 c0                	test   eax,eax
  4f6bcc:	74 30                	je     0x4f6bfe
  4f6bce:	8b ff                	mov    edi,edi
  4f6bd0:	83 f9 14             	cmp    ecx,0x14
  4f6bd3:	73 29                	jae    0x4f6bfe
  4f6bd5:	8d 7a 04             	lea    edi,[edx+0x4]
  4f6bd8:	81 ff 00 10 00 00    	cmp    edi,0x1000
  4f6bde:	77 19                	ja     0x4f6bf9
  4f6be0:	8b be 10 01 00 00    	mov    edi,DWORD PTR [esi+0x110]
  4f6be6:	8b 3c 8f             	mov    edi,DWORD PTR [edi+ecx*4]
  4f6be9:	89 bc 15 f8 ef ff ff 	mov    DWORD PTR [ebp+edx*1-0x1008],edi
  4f6bf0:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4f6bf3:	83 c2 04             	add    edx,0x4
  4f6bf6:	89 55 f8             	mov    DWORD PTR [ebp-0x8],edx
  4f6bf9:	41                   	inc    ecx
  4f6bfa:	3b c8                	cmp    ecx,eax
  4f6bfc:	72 d2                	jb     0x4f6bd0
  4f6bfe:	8b be 10 01 00 00    	mov    edi,DWORD PTR [esi+0x110]
  4f6c04:	8d 0c 8f             	lea    ecx,[edi+ecx*4]
  4f6c07:	3b f9                	cmp    edi,ecx
  4f6c09:	74 28                	je     0x4f6c33
  4f6c0b:	8b 86 14 01 00 00    	mov    eax,DWORD PTR [esi+0x114]
  4f6c11:	2b c1                	sub    eax,ecx
  4f6c13:	c1 f8 02             	sar    eax,0x2
  4f6c16:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  4f6c1d:	53                   	push   ebx
  4f6c1e:	51                   	push   ecx
  4f6c1f:	57                   	push   edi
  4f6c20:	e8 cb a6 39 00       	call   0x8912f0
  4f6c25:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4f6c28:	83 c4 0c             	add    esp,0xc
  4f6c2b:	03 df                	add    ebx,edi
  4f6c2d:	89 9e 14 01 00 00    	mov    DWORD PTR [esi+0x114],ebx
  4f6c33:	83 fa 02             	cmp    edx,0x2
  4f6c36:	76 17                	jbe    0x4f6c4f
  4f6c38:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4f6c3e:	8b 01                	mov    eax,DWORD PTR [ecx]
  4f6c40:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4f6c43:	52                   	push   edx
  4f6c44:	8d 95 f8 ef ff ff    	lea    edx,[ebp-0x1008]
  4f6c4a:	52                   	push   edx
  4f6c4b:	6a 02                	push   0x2
  4f6c4d:	ff d0                	call   eax
  4f6c4f:	8b be 30 01 00 00    	mov    edi,DWORD PTR [esi+0x130]
  4f6c55:	8b 96 34 01 00 00    	mov    edx,DWORD PTR [esi+0x134]
  4f6c5b:	3b fa                	cmp    edi,edx
  4f6c5d:	0f 84 ac 00 00 00    	je     0x4f6d0f
  4f6c63:	b9 c6 0b 00 00       	mov    ecx,0xbc6
  4f6c68:	2b d7                	sub    edx,edi
  4f6c6a:	33 c0                	xor    eax,eax
  4f6c6c:	66 89 8d f4 df ff ff 	mov    WORD PTR [ebp-0x200c],cx
  4f6c73:	b8 02 00 00 00       	mov    eax,0x2
  4f6c78:	c1 fa 02             	sar    edx,0x2
  4f6c7b:	33 c9                	xor    ecx,ecx
  4f6c7d:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  4f6c83:	85 d2                	test   edx,edx
  4f6c85:	74 34                	je     0x4f6cbb
  4f6c87:	83 f9 14             	cmp    ecx,0x14
  4f6c8a:	73 2f                	jae    0x4f6cbb
  4f6c8c:	8d 78 04             	lea    edi,[eax+0x4]
  4f6c8f:	81 ff 00 10 00 00    	cmp    edi,0x1000
  4f6c95:	77 1f                	ja     0x4f6cb6
  4f6c97:	8b be 30 01 00 00    	mov    edi,DWORD PTR [esi+0x130]
  4f6c9d:	8b 3c 8f             	mov    edi,DWORD PTR [edi+ecx*4]
  4f6ca0:	89 bc 05 f4 df ff ff 	mov    DWORD PTR [ebp+eax*1-0x200c],edi
  4f6ca7:	8b 85 f4 ef ff ff    	mov    eax,DWORD PTR [ebp-0x100c]
  4f6cad:	83 c0 04             	add    eax,0x4
  4f6cb0:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  4f6cb6:	41                   	inc    ecx
  4f6cb7:	3b ca                	cmp    ecx,edx
  4f6cb9:	72 cc                	jb     0x4f6c87
  4f6cbb:	8b be 30 01 00 00    	mov    edi,DWORD PTR [esi+0x130]
  4f6cc1:	8d 0c 8f             	lea    ecx,[edi+ecx*4]
  4f6cc4:	3b f9                	cmp    edi,ecx
  4f6cc6:	74 2b                	je     0x4f6cf3
  4f6cc8:	8b 86 34 01 00 00    	mov    eax,DWORD PTR [esi+0x134]
  4f6cce:	2b c1                	sub    eax,ecx
  4f6cd0:	c1 f8 02             	sar    eax,0x2
  4f6cd3:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  4f6cda:	53                   	push   ebx
  4f6cdb:	51                   	push   ecx
  4f6cdc:	57                   	push   edi
  4f6cdd:	e8 0e a6 39 00       	call   0x8912f0
  4f6ce2:	8b 85 f4 ef ff ff    	mov    eax,DWORD PTR [ebp-0x100c]
  4f6ce8:	83 c4 0c             	add    esp,0xc
  4f6ceb:	03 df                	add    ebx,edi
  4f6ced:	89 9e 34 01 00 00    	mov    DWORD PTR [esi+0x134],ebx
  4f6cf3:	83 f8 02             	cmp    eax,0x2
  4f6cf6:	76 17                	jbe    0x4f6d0f
  4f6cf8:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4f6cfe:	8b 11                	mov    edx,DWORD PTR [ecx]
  4f6d00:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4f6d03:	50                   	push   eax
  4f6d04:	8d 85 f4 df ff ff    	lea    eax,[ebp-0x200c]
  4f6d0a:	50                   	push   eax
  4f6d0b:	6a 02                	push   0x2
  4f6d0d:	ff d2                	call   edx
  4f6d0f:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4f6d12:	5f                   	pop    edi
  4f6d13:	33 cd                	xor    ecx,ebp
  4f6d15:	5b                   	pop    ebx
  4f6d16:	e8 e6 a2 39 00       	call   0x891001
  4f6d1b:	8b e5                	mov    esp,ebp
  4f6d1d:	5d                   	pop    ebp
  4f6d1e:	c3                   	ret
  4f6d1f:	cc                   	int3
  4f6d20:	55                   	push   ebp
  4f6d21:	8b ec                	mov    ebp,esp
  4f6d23:	8b 87 04 01 00 00    	mov    eax,DWORD PTR [edi+0x104]
  4f6d29:	53                   	push   ebx
  4f6d2a:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4f6d2d:	56                   	push   esi
  4f6d2e:	8b 30                	mov    esi,DWORD PTR [eax]
  4f6d30:	3b f0                	cmp    esi,eax
  4f6d32:	74 66                	je     0x4f6d9a
  4f6d34:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4f6d37:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  4f6d3b:	72 02                	jb     0x4f6d3f
  4f6d3d:	8b 00                	mov    eax,DWORD PTR [eax]
  4f6d3f:	6a 14                	push   0x14
  4f6d41:	53                   	push   ebx
  4f6d42:	50                   	push   eax
  4f6d43:	e8 83 d3 39 00       	call   0x8940cb
  4f6d48:	83 c4 0c             	add    esp,0xc
  4f6d4b:	85 c0                	test   eax,eax
  4f6d4d:	74 53                	je     0x4f6da2
  4f6d4f:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4f6d53:	75 3d                	jne    0x4f6d92
  4f6d55:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4f6d58:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6d5c:	75 16                	jne    0x4f6d74
  4f6d5e:	8b f0                	mov    esi,eax
  4f6d60:	8b 06                	mov    eax,DWORD PTR [esi]
  4f6d62:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6d66:	75 2a                	jne    0x4f6d92
  4f6d68:	8b f0                	mov    esi,eax
  4f6d6a:	8b 06                	mov    eax,DWORD PTR [esi]
  4f6d6c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6d70:	74 f6                	je     0x4f6d68
  4f6d72:	eb 1e                	jmp    0x4f6d92
  4f6d74:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4f6d77:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6d7b:	75 13                	jne    0x4f6d90
  4f6d7d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4f6d80:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4f6d83:	75 0b                	jne    0x4f6d90
  4f6d85:	8b f0                	mov    esi,eax
  4f6d87:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4f6d8a:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6d8e:	74 f0                	je     0x4f6d80
  4f6d90:	8b f0                	mov    esi,eax
  4f6d92:	3b b7 04 01 00 00    	cmp    esi,DWORD PTR [edi+0x104]
  4f6d98:	75 9a                	jne    0x4f6d34
  4f6d9a:	5e                   	pop    esi
  4f6d9b:	32 c0                	xor    al,al
  4f6d9d:	5b                   	pop    ebx
  4f6d9e:	5d                   	pop    ebp
  4f6d9f:	c2 08 00             	ret    0x8
  4f6da2:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  4f6da5:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4f6da8:	5e                   	pop    esi
  4f6da9:	89 01                	mov    DWORD PTR [ecx],eax
  4f6dab:	b0 01                	mov    al,0x1
  4f6dad:	5b                   	pop    ebx
  4f6dae:	5d                   	pop    ebp
  4f6daf:	c2 08 00             	ret    0x8
  4f6db2:	cc                   	int3
  4f6db3:	cc                   	int3
  4f6db4:	cc                   	int3
  4f6db5:	cc                   	int3
  4f6db6:	cc                   	int3
  4f6db7:	cc                   	int3
  4f6db8:	cc                   	int3
  4f6db9:	cc                   	int3
  4f6dba:	cc                   	int3
  4f6dbb:	cc                   	int3
  4f6dbc:	cc                   	int3
  4f6dbd:	cc                   	int3
  4f6dbe:	cc                   	int3
  4f6dbf:	cc                   	int3
  4f6dc0:	55                   	push   ebp
  4f6dc1:	8b ec                	mov    ebp,esp
  4f6dc3:	53                   	push   ebx
  4f6dc4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4f6dc7:	56                   	push   esi
  4f6dc8:	57                   	push   edi
  4f6dc9:	8b b8 04 01 00 00    	mov    edi,DWORD PTR [eax+0x104]
  4f6dcf:	8b 37                	mov    esi,DWORD PTR [edi]
  4f6dd1:	3b f7                	cmp    esi,edi
  4f6dd3:	0f 84 91 00 00 00    	je     0x4f6e6a
  4f6dd9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4f6de0:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4f6de3:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  4f6de7:	72 02                	jb     0x4f6deb
  4f6de9:	8b 00                	mov    eax,DWORD PTR [eax]
  4f6deb:	8b cb                	mov    ecx,ebx
  4f6ded:	8d 49 00             	lea    ecx,[ecx+0x0]
  4f6df0:	66 8b 10             	mov    dx,WORD PTR [eax]
  4f6df3:	66 3b 11             	cmp    dx,WORD PTR [ecx]
  4f6df6:	75 1e                	jne    0x4f6e16
  4f6df8:	66 85 d2             	test   dx,dx
  4f6dfb:	74 15                	je     0x4f6e12
  4f6dfd:	66 8b 50 02          	mov    dx,WORD PTR [eax+0x2]
  4f6e01:	66 3b 51 02          	cmp    dx,WORD PTR [ecx+0x2]
  4f6e05:	75 0f                	jne    0x4f6e16
  4f6e07:	83 c0 04             	add    eax,0x4
  4f6e0a:	83 c1 04             	add    ecx,0x4
  4f6e0d:	66 85 d2             	test   dx,dx
  4f6e10:	75 de                	jne    0x4f6df0
  4f6e12:	33 c0                	xor    eax,eax
  4f6e14:	eb 05                	jmp    0x4f6e1b
  4f6e16:	1b c0                	sbb    eax,eax
  4f6e18:	83 d8 ff             	sbb    eax,0xffffffff
  4f6e1b:	85 c0                	test   eax,eax
  4f6e1d:	74 55                	je     0x4f6e74
  4f6e1f:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4f6e23:	75 3d                	jne    0x4f6e62
  4f6e25:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  4f6e28:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  4f6e2c:	75 16                	jne    0x4f6e44
  4f6e2e:	8b 01                	mov    eax,DWORD PTR [ecx]
  4f6e30:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6e34:	75 0a                	jne    0x4f6e40
  4f6e36:	8b c8                	mov    ecx,eax
  4f6e38:	8b 01                	mov    eax,DWORD PTR [ecx]
  4f6e3a:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6e3e:	74 f6                	je     0x4f6e36
  4f6e40:	8b f1                	mov    esi,ecx
  4f6e42:	eb 1e                	jmp    0x4f6e62
  4f6e44:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4f6e47:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6e4b:	75 13                	jne    0x4f6e60
  4f6e4d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4f6e50:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4f6e53:	75 0b                	jne    0x4f6e60
  4f6e55:	8b f0                	mov    esi,eax
  4f6e57:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4f6e5a:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4f6e5e:	74 f0                	je     0x4f6e50
  4f6e60:	8b f0                	mov    esi,eax
  4f6e62:	3b f7                	cmp    esi,edi
  4f6e64:	0f 85 76 ff ff ff    	jne    0x4f6de0
  4f6e6a:	5f                   	pop    edi
  4f6e6b:	5e                   	pop    esi
  4f6e6c:	83 c8 ff             	or     eax,0xffffffff
  4f6e6f:	5b                   	pop    ebx
  4f6e70:	5d                   	pop    ebp
  4f6e71:	c2 04 00             	ret    0x4
  4f6e74:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  4f6e77:	5f                   	pop    edi
  4f6e78:	5e                   	pop    esi
  4f6e79:	5b                   	pop    ebx
  4f6e7a:	5d                   	pop    ebp
  4f6e7b:	c2 04 00             	ret    0x4
  4f6e7e:	cc                   	int3
  4f6e7f:	cc                   	int3

WINDOW alias_helper_7370 [0x4f7370, 0x4f7451)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f7370 <.text+0xf6370>:
  4f7370:	55                   	push   ebp
  4f7371:	8b ec                	mov    ebp,esp
  4f7373:	83 ec 10             	sub    esp,0x10
  4f7376:	53                   	push   ebx
  4f7377:	56                   	push   esi
  4f7378:	57                   	push   edi
  4f7379:	8b f8                	mov    edi,eax
  4f737b:	8d 45 08             	lea    eax,[ebp+0x8]
  4f737e:	8d b7 20 01 00 00    	lea    esi,[edi+0x120]
  4f7384:	50                   	push   eax
  4f7385:	8d 45 f8             	lea    eax,[ebp-0x8]
  4f7388:	8b ce                	mov    ecx,esi
  4f738a:	e8 31 c5 34 00       	call   0x8438c0
  4f738f:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  4f7392:	3b 87 24 01 00 00    	cmp    eax,DWORD PTR [edi+0x124]
  4f7398:	74 18                	je     0x4f73b2
  4f739a:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4f739d:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  4f73a1:	0f 82 a1 00 00 00    	jb     0x4f7448
  4f73a7:	8b 00                	mov    eax,DWORD PTR [eax]
  4f73a9:	5f                   	pop    edi
  4f73aa:	5e                   	pop    esi
  4f73ab:	5b                   	pop    ebx
  4f73ac:	8b e5                	mov    esp,ebp
  4f73ae:	5d                   	pop    ebp
  4f73af:	c2 04 00             	ret    0x4
  4f73b2:	81 c7 30 01 00 00    	add    edi,0x130
  4f73b8:	8d 45 08             	lea    eax,[ebp+0x8]
  4f73bb:	e8 c0 12 fb ff       	call   0x4a8680
  4f73c0:	6a 20                	push   0x20
  4f73c2:	e8 a1 9e 39 00       	call   0x891268
  4f73c7:	33 ff                	xor    edi,edi
  4f73c9:	83 c4 04             	add    esp,0x4
  4f73cc:	3b c7                	cmp    eax,edi
  4f73ce:	74 13                	je     0x4f73e3
  4f73d0:	33 c9                	xor    ecx,ecx
  4f73d2:	c7 40 14 07 00 00 00 	mov    DWORD PTR [eax+0x14],0x7
  4f73d9:	89 78 10             	mov    DWORD PTR [eax+0x10],edi
  4f73dc:	66 89 08             	mov    WORD PTR [eax],cx
  4f73df:	8b d8                	mov    ebx,eax
  4f73e1:	eb 02                	jmp    0x4f73e5
  4f73e3:	33 db                	xor    ebx,ebx
  4f73e5:	8b 43 10             	mov    eax,DWORD PTR [ebx+0x10]
  4f73e8:	8b cb                	mov    ecx,ebx
  4f73ea:	83 f8 14             	cmp    eax,0x14
  4f73ed:	72 0b                	jb     0x4f73fa
  4f73ef:	6a ff                	push   0xffffffff
  4f73f1:	6a 14                	push   0x14
  4f73f3:	e8 08 b0 f0 ff       	call   0x402400
  4f73f8:	eb 0e                	jmp    0x4f7408
  4f73fa:	ba 14 00 00 00       	mov    edx,0x14
  4f73ff:	57                   	push   edi
  4f7400:	2b d0                	sub    edx,eax
  4f7402:	52                   	push   edx
  4f7403:	e8 08 8c f4 ff       	call   0x440010
  4f7408:	6a ff                	push   0xffffffff
  4f740a:	57                   	push   edi
  4f740b:	68 9c aa e2 00       	push   0xe2aa9c
  4f7410:	8b cb                	mov    ecx,ebx
  4f7412:	e8 c9 b2 f0 ff       	call   0x4026e0
  4f7417:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4f741a:	89 7b 1c             	mov    DWORD PTR [ebx+0x1c],edi
  4f741d:	8d 7d f4             	lea    edi,[ebp-0xc]
  4f7420:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  4f7423:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  4f7426:	e8 f5 7a 08 00       	call   0x57ef20
  4f742b:	50                   	push   eax
  4f742c:	56                   	push   esi
  4f742d:	8d 75 f4             	lea    esi,[ebp-0xc]
  4f7430:	e8 1b 74 08 00       	call   0x57e850
  4f7435:	83 7b 14 08          	cmp    DWORD PTR [ebx+0x14],0x8
  4f7439:	72 0b                	jb     0x4f7446
  4f743b:	8b 03                	mov    eax,DWORD PTR [ebx]
  4f743d:	5f                   	pop    edi
  4f743e:	5e                   	pop    esi
  4f743f:	5b                   	pop    ebx
  4f7440:	8b e5                	mov    esp,ebp
  4f7442:	5d                   	pop    ebp
  4f7443:	c2 04 00             	ret    0x4
  4f7446:	8b c3                	mov    eax,ebx
  4f7448:	5f                   	pop    edi
  4f7449:	5e                   	pop    esi
  4f744a:	5b                   	pop    ebx
  4f744b:	8b e5                	mov    esp,ebp
  4f744d:	5d                   	pop    ebp
  4f744e:	c2 04 00             	ret    0x4

WINDOW alias_getters_7a70_7ba0 [0x4f7a70, 0x4f7cb4)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004f7a70 <.text+0xf6a70>:
  4f7a70:	55                   	push   ebp
  4f7a71:	8b ec                	mov    ebp,esp
  4f7a73:	83 e4 f8             	and    esp,0xfffffff8
  4f7a76:	6a ff                	push   0xffffffff
  4f7a78:	68 13 75 91 00       	push   0x917513
  4f7a7d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4f7a83:	50                   	push   eax
  4f7a84:	81 ec e0 00 00 00    	sub    esp,0xe0
  4f7a8a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f7a8f:	33 c4                	xor    eax,esp
  4f7a91:	89 84 24 d8 00 00 00 	mov    DWORD PTR [esp+0xd8],eax
  4f7a98:	53                   	push   ebx
  4f7a99:	56                   	push   esi
  4f7a9a:	57                   	push   edi
  4f7a9b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f7aa0:	33 c4                	xor    eax,esp
  4f7aa2:	50                   	push   eax
  4f7aa3:	8d 84 24 f0 00 00 00 	lea    eax,[esp+0xf0]
  4f7aaa:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4f7ab0:	8b f1                	mov    esi,ecx
  4f7ab2:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  4f7ab5:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  4f7ab8:	8b d9                	mov    ebx,ecx
  4f7aba:	33 c9                	xor    ecx,ecx
  4f7abc:	38 48 75             	cmp    BYTE PTR [eax+0x75],cl
  4f7abf:	75 15                	jne    0x4f7ad6
  4f7ac1:	8b 3a                	mov    edi,DWORD PTR [edx]
  4f7ac3:	39 78 0c             	cmp    DWORD PTR [eax+0xc],edi
  4f7ac6:	73 05                	jae    0x4f7acd
  4f7ac8:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4f7acb:	eb 04                	jmp    0x4f7ad1
  4f7acd:	8b d8                	mov    ebx,eax
  4f7acf:	8b 00                	mov    eax,DWORD PTR [eax]
  4f7ad1:	38 48 75             	cmp    BYTE PTR [eax+0x75],cl
  4f7ad4:	74 ed                	je     0x4f7ac3
  4f7ad6:	3b 5e 04             	cmp    ebx,DWORD PTR [esi+0x4]
  4f7ad9:	74 0b                	je     0x4f7ae6
  4f7adb:	8b 02                	mov    eax,DWORD PTR [edx]
  4f7add:	3b 43 0c             	cmp    eax,DWORD PTR [ebx+0xc]
  4f7ae0:	0f 83 8e 00 00 00    	jae    0x4f7b74
  4f7ae6:	b8 0f 00 00 00       	mov    eax,0xf
  4f7aeb:	33 ff                	xor    edi,edi
  4f7aed:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  4f7af1:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  4f7af5:	88 4c 24 14          	mov    BYTE PTR [esp+0x14],cl
  4f7af9:	c7 44 24 44 07 00 00 	mov    DWORD PTR [esp+0x44],0x7
  4f7b00:	00 
  4f7b01:	89 4c 24 40          	mov    DWORD PTR [esp+0x40],ecx
  4f7b05:	66 89 7c 24 30       	mov    WORD PTR [esp+0x30],di
  4f7b0a:	89 44 24 60          	mov    DWORD PTR [esp+0x60],eax
  4f7b0e:	89 4c 24 5c          	mov    DWORD PTR [esp+0x5c],ecx
  4f7b12:	88 4c 24 4c          	mov    BYTE PTR [esp+0x4c],cl
  4f7b16:	89 8c 24 f8 00 00 00 	mov    DWORD PTR [esp+0xf8],ecx
  4f7b1d:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4f7b1f:	8d 94 24 80 00 00 00 	lea    edx,[esp+0x80]
  4f7b26:	52                   	push   edx
  4f7b27:	8d 7c 24 18          	lea    edi,[esp+0x18]
  4f7b2b:	89 8c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ecx
  4f7b32:	e8 b9 06 00 00       	call   0x4f81f0
  4f7b37:	8d 44 24 7c          	lea    eax,[esp+0x7c]
  4f7b3b:	50                   	push   eax
  4f7b3c:	8b ce                	mov    ecx,esi
  4f7b3e:	c6 84 24 fc 00 00 00 	mov    BYTE PTR [esp+0xfc],0x1
  4f7b45:	01 
  4f7b46:	e8 d5 20 00 00       	call   0x4f9c20
  4f7b4b:	53                   	push   ebx
  4f7b4c:	56                   	push   esi
  4f7b4d:	8d 74 24 18          	lea    esi,[esp+0x18]
  4f7b51:	e8 1a 12 00 00       	call   0x4f8d70
  4f7b56:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  4f7b5a:	8d b4 24 80 00 00 00 	lea    esi,[esp+0x80]
  4f7b61:	e8 4a d7 ff ff       	call   0x4f52b0
  4f7b66:	8d 74 24 14          	lea    esi,[esp+0x14]
  4f7b6a:	e8 41 d7 ff ff       	call   0x4f52b0
  4f7b6f:	8d 47 10             	lea    eax,[edi+0x10]
  4f7b72:	eb 03                	jmp    0x4f7b77
  4f7b74:	8d 43 10             	lea    eax,[ebx+0x10]
  4f7b77:	8b 8c 24 f0 00 00 00 	mov    ecx,DWORD PTR [esp+0xf0]
  4f7b7e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4f7b85:	59                   	pop    ecx
  4f7b86:	5f                   	pop    edi
  4f7b87:	5e                   	pop    esi
  4f7b88:	5b                   	pop    ebx
  4f7b89:	8b 8c 24 d8 00 00 00 	mov    ecx,DWORD PTR [esp+0xd8]
  4f7b90:	33 cc                	xor    ecx,esp
  4f7b92:	e8 6a 94 39 00       	call   0x891001
  4f7b97:	8b e5                	mov    esp,ebp
  4f7b99:	5d                   	pop    ebp
  4f7b9a:	c3                   	ret
  4f7b9b:	cc                   	int3
  4f7b9c:	cc                   	int3
  4f7b9d:	cc                   	int3
  4f7b9e:	cc                   	int3
  4f7b9f:	cc                   	int3
  4f7ba0:	55                   	push   ebp
  4f7ba1:	8b ec                	mov    ebp,esp
  4f7ba3:	6a ff                	push   0xffffffff
  4f7ba5:	68 80 bc 91 00       	push   0x91bc80
  4f7baa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4f7bb0:	50                   	push   eax
  4f7bb1:	83 ec 48             	sub    esp,0x48
  4f7bb4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4f7bb9:	33 c5                	xor    eax,ebp
  4f7bbb:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4f7bbe:	56                   	push   esi
  4f7bbf:	57                   	push   edi
  4f7bc0:	50                   	push   eax
  4f7bc1:	8d 45 f4             	lea    eax,[ebp-0xc]
  4f7bc4:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4f7bca:	8b f1                	mov    esi,ecx
  4f7bcc:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  4f7bcf:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  4f7bd2:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  4f7bd6:	8b f9                	mov    edi,ecx
  4f7bd8:	75 1a                	jne    0x4f7bf4
  4f7bda:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4f7bdc:	8d 64 24 00          	lea    esp,[esp+0x0]
  4f7be0:	39 48 0c             	cmp    DWORD PTR [eax+0xc],ecx
  4f7be3:	73 05                	jae    0x4f7bea
  4f7be5:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4f7be8:	eb 04                	jmp    0x4f7bee
  4f7bea:	8b f8                	mov    edi,eax
  4f7bec:	8b 00                	mov    eax,DWORD PTR [eax]
  4f7bee:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  4f7bf2:	74 ec                	je     0x4f7be0
  4f7bf4:	3b 7e 04             	cmp    edi,DWORD PTR [esi+0x4]
  4f7bf7:	74 0b                	je     0x4f7c04
  4f7bf9:	8b 02                	mov    eax,DWORD PTR [edx]
  4f7bfb:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
  4f7bfe:	0f 83 92 00 00 00    	jae    0x4f7c96
  4f7c04:	33 c0                	xor    eax,eax
  4f7c06:	33 c9                	xor    ecx,ecx
  4f7c08:	c7 45 c8 07 00 00 00 	mov    DWORD PTR [ebp-0x38],0x7
  4f7c0f:	89 45 c4             	mov    DWORD PTR [ebp-0x3c],eax
  4f7c12:	66 89 4d b4          	mov    WORD PTR [ebp-0x4c],cx
  4f7c16:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4f7c19:	8b 12                	mov    edx,DWORD PTR [edx]
  4f7c1b:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  4f7c1e:	51                   	push   ecx
  4f7c1f:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4f7c22:	89 55 d0             	mov    DWORD PTR [ebp-0x30],edx
  4f7c25:	c7 45 e8 07 00 00 00 	mov    DWORD PTR [ebp-0x18],0x7
  4f7c2c:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  4f7c2f:	66 89 45 d4          	mov    WORD PTR [ebp-0x2c],ax
  4f7c33:	e8 c8 ab f0 ff       	call   0x402800
  4f7c38:	8d 55 d0             	lea    edx,[ebp-0x30]
  4f7c3b:	52                   	push   edx
  4f7c3c:	8b ce                	mov    ecx,esi
  4f7c3e:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4f7c42:	e8 a9 e7 00 00       	call   0x5063f0
  4f7c47:	57                   	push   edi
  4f7c48:	8d 4d b0             	lea    ecx,[ebp-0x50]
  4f7c4b:	51                   	push   ecx
  4f7c4c:	8b ce                	mov    ecx,esi
  4f7c4e:	e8 cd 87 f8 ff       	call   0x480420
  4f7c53:	8b 75 b0             	mov    esi,DWORD PTR [ebp-0x50]
  4f7c56:	bf 08 00 00 00       	mov    edi,0x8
  4f7c5b:	39 7d e8             	cmp    DWORD PTR [ebp-0x18],edi
  4f7c5e:	72 0c                	jb     0x4f7c6c
  4f7c60:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  4f7c63:	52                   	push   edx
  4f7c64:	e8 a3 95 39 00       	call   0x89120c
  4f7c69:	83 c4 04             	add    esp,0x4
  4f7c6c:	33 c0                	xor    eax,eax
  4f7c6e:	c7 45 e8 07 00 00 00 	mov    DWORD PTR [ebp-0x18],0x7
  4f7c75:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  4f7c7c:	66 89 45 d4          	mov    WORD PTR [ebp-0x2c],ax
  4f7c80:	39 7d c8             	cmp    DWORD PTR [ebp-0x38],edi
  4f7c83:	72 0c                	jb     0x4f7c91
  4f7c85:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  4f7c88:	51                   	push   ecx
  4f7c89:	e8 7e 95 39 00       	call   0x89120c
  4f7c8e:	83 c4 04             	add    esp,0x4
  4f7c91:	8d 46 10             	lea    eax,[esi+0x10]
  4f7c94:	eb 03                	jmp    0x4f7c99
  4f7c96:	8d 47 10             	lea    eax,[edi+0x10]
  4f7c99:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4f7c9c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4f7ca3:	59                   	pop    ecx
  4f7ca4:	5f                   	pop    edi
  4f7ca5:	5e                   	pop    esi
  4f7ca6:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4f7ca9:	33 cd                	xor    ecx,ebp
  4f7cab:	e8 51 93 39 00       	call   0x891001
  4f7cb0:	8b e5                	mov    esp,ebp
  4f7cb2:	5d                   	pop    ebp
  4f7cb3:	c3                   	ret

WINDOW onexit_and_atexit [0x8922de, 0x892331)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008922de <.text+0x4912de>:
  8922de:	6a 0c                	push   0xc
  8922e0:	68 f0 4c c8 00       	push   0xc84cf0
  8922e5:	e8 46 e8 00 00       	call   0x8a0b30
  8922ea:	e8 84 14 00 00       	call   0x893773
  8922ef:	83 65 fc 00          	and    DWORD PTR [ebp-0x4],0x0
  8922f3:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  8922f6:	e8 fc fe ff ff       	call   0x8921f7
  8922fb:	59                   	pop    ecx
  8922fc:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  8922ff:	c7 45 fc fe ff ff ff 	mov    DWORD PTR [ebp-0x4],0xfffffffe
  892306:	e8 09 00 00 00       	call   0x892314
  89230b:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  89230e:	e8 62 e8 00 00       	call   0x8a0b75
  892313:	c3                   	ret
  892314:	e8 63 14 00 00       	call   0x89377c
  892319:	c3                   	ret
  89231a:	8b ff                	mov    edi,edi
  89231c:	55                   	push   ebp
  89231d:	8b ec                	mov    ebp,esp
  89231f:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  892322:	e8 b7 ff ff ff       	call   0x8922de
  892327:	f7 d8                	neg    eax
  892329:	1b c0                	sbb    eax,eax
  89232b:	f7 d8                	neg    eax
  89232d:	59                   	pop    ecx
  89232e:	48                   	dec    eax
  89232f:	5d                   	pop    ebp
  892330:	c3                   	ret

WINDOW destructor_thunk [0xbcd1e0, 0xbcd1e5)

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00bcd1e0 <.text+0x7cc1e0>:
  bcd1e0:	e9 cb 72 92 ff       	jmp    0x4f44b0

# Research group: parser

# global_lua_ctor_and_global_DoFile VA=0x006F4380 raw=0x002F3780 size=142 sha256=388a182e5936c08a3a0f85f3b07f9abe22ea4858831cf99c3ff976d37bc21d5f

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4380 <.text+0x2f3380>:
  6f4380:	51                   	push   ecx
  6f4381:	56                   	push   esi
  6f4382:	57                   	push   edi
  6f4383:	e8 28 31 00 00       	call   0x6f74b0
  6f4388:	85 c0                	test   eax,eax
  6f438a:	74 0a                	je     0x6f4396
  6f438c:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  6f438f:	c7 41 58 a0 71 6f 00 	mov    DWORD PTR [ecx+0x58],0x6f71a0
  6f4396:	a3 c8 f3 fd 00       	mov    ds:0xfdf3c8,eax
  6f439b:	c7 05 cc f3 fd 00 00 	mov    DWORD PTR ds:0xfdf3cc,0x0
  6f43a2:	00 00 00 
  6f43a5:	c7 05 d0 f3 fd 00 01 	mov    DWORD PTR ds:0xfdf3d0,0x1
  6f43ac:	00 00 00 
  6f43af:	e8 ac 32 00 00       	call   0x6f7660
  6f43b4:	8b 35 c8 f3 fd 00    	mov    esi,DWORD PTR ds:0xfdf3c8
  6f43ba:	6a 00                	push   0x0
  6f43bc:	68 20 44 6f 00       	push   0x6f4420
  6f43c1:	e8 ea 11 00 00       	call   0x6f55b0
  6f43c6:	8b 35 c8 f3 fd 00    	mov    esi,DWORD PTR ds:0xfdf3c8
  6f43cc:	bf 7c 25 c4 00       	mov    edi,0xc4257c
  6f43d1:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  6f43d6:	e8 b5 13 00 00       	call   0x6f5790
  6f43db:	8b 35 c8 f3 fd 00    	mov    esi,DWORD PTR ds:0xfdf3c8
  6f43e1:	6a 00                	push   0x0
  6f43e3:	68 a0 48 6f 00       	push   0x6f48a0
  6f43e8:	e8 c3 11 00 00       	call   0x6f55b0
  6f43ed:	8b 35 c8 f3 fd 00    	mov    esi,DWORD PTR ds:0xfdf3c8
  6f43f3:	83 c4 10             	add    esp,0x10
  6f43f6:	bf 90 25 c4 00       	mov    edi,0xc42590
  6f43fb:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  6f4400:	e8 8b 13 00 00       	call   0x6f5790
  6f4405:	5f                   	pop    edi
  6f4406:	b8 c8 f3 fd 00       	mov    eax,0xfdf3c8
  6f440b:	5e                   	pop    esi
  6f440c:	59                   	pop    ecx
  6f440d:	c3                   	ret

# path_loader_resource_copy_BOM_parse_execute_free VA=0x006F4A50 raw=0x002F3E50 size=457 sha256=22fa819ace371f4826e6a933436795ad3755ddd8d68632822e77284066cb0bd9

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4a50 <.text+0x2f3a50>:
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
  6f4c18:	cc                   	int3

# global_DoFile_stack_path_resource_loader VA=0x006F48A0 raw=0x002F3CA0 size=432 sha256=fe72d7521c01ead56408d1bbbd30cf82046b0628cec91235a1db2f732002253e

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f48a0 <.text+0x2f38a0>:
  6f48a0:	55                   	push   ebp
  6f48a1:	8b ec                	mov    ebp,esp
  6f48a3:	83 e4 f8             	and    esp,0xfffffff8
  6f48a6:	83 ec 1c             	sub    esp,0x1c
  6f48a9:	53                   	push   ebx
  6f48aa:	56                   	push   esi
  6f48ab:	57                   	push   edi
  6f48ac:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  6f48af:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f48b2:	83 ee 10             	sub    esi,0x10
  6f48b5:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  6f48b9:	74 25                	je     0x6f48e0
  6f48bb:	e8 10 6d 00 00       	call   0x6fb5d0
  6f48c0:	85 c0                	test   eax,eax
  6f48c2:	75 04                	jne    0x6f48c8
  6f48c4:	33 f6                	xor    esi,esi
  6f48c6:	eb 1d                	jmp    0x6f48e5
  6f48c8:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  6f48cb:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  6f48ce:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  6f48d1:	72 07                	jb     0x6f48da
  6f48d3:	8b c7                	mov    eax,edi
  6f48d5:	e8 c6 6a 00 00       	call   0x6fb3a0
  6f48da:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f48dd:	83 ee 10             	sub    esi,0x10
  6f48e0:	8b 36                	mov    esi,DWORD PTR [esi]
  6f48e2:	83 c6 10             	add    esi,0x10
  6f48e5:	68 e0 d1 be 00       	push   0xbed1e0
  6f48ea:	56                   	push   esi
  6f48eb:	c7 44 24 14 01 00 00 	mov    DWORD PTR [esp+0x14],0x1
  6f48f2:	00 
  6f48f3:	e8 78 fe 01 00       	call   0x714770
  6f48f8:	8b f0                	mov    esi,eax
  6f48fa:	83 c4 08             	add    esp,0x8
  6f48fd:	85 f6                	test   esi,esi
  6f48ff:	0f 84 2b 01 00 00    	je     0x6f4a30
  6f4905:	8b 16                	mov    edx,DWORD PTR [esi]
  6f4907:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  6f490a:	8b ce                	mov    ecx,esi
  6f490c:	ff d0                	call   eax
  6f490e:	8b d8                	mov    ebx,eax
  6f4910:	8d 4b 01             	lea    ecx,[ebx+0x1]
  6f4913:	51                   	push   ecx
  6f4914:	e8 24 93 18 00       	call   0x87dc3d
  6f4919:	8b 16                	mov    edx,DWORD PTR [esi]
  6f491b:	83 c4 04             	add    esp,0x4
  6f491e:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  6f4922:	8b 42 38             	mov    eax,DWORD PTR [edx+0x38]
  6f4925:	53                   	push   ebx
  6f4926:	8b ce                	mov    ecx,esi
  6f4928:	ff d0                	call   eax
  6f492a:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  6f492e:	50                   	push   eax
  6f492f:	51                   	push   ecx
  6f4930:	e8 9b 92 1a 00       	call   0x89dbd0
  6f4935:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  6f4939:	c6 04 13 00          	mov    BYTE PTR [ebx+edx*1],0x0
  6f493d:	8b 06                	mov    eax,DWORD PTR [esi]
  6f493f:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  6f4942:	83 c4 0c             	add    esp,0xc
  6f4945:	8b ce                	mov    ecx,esi
  6f4947:	ff d2                	call   edx
  6f4949:	8b 5c 24 0c          	mov    ebx,DWORD PTR [esp+0xc]
  6f494d:	83 f8 03             	cmp    eax,0x3
  6f4950:	72 42                	jb     0x6f4994
  6f4952:	80 3b ef             	cmp    BYTE PTR [ebx],0xef
  6f4955:	75 3d                	jne    0x6f4994
  6f4957:	80 7b 01 bb          	cmp    BYTE PTR [ebx+0x1],0xbb
  6f495b:	75 37                	jne    0x6f4994
  6f495d:	80 7b 02 bf          	cmp    BYTE PTR [ebx+0x2],0xbf
  6f4961:	75 31                	jne    0x6f4994
  6f4963:	83 c0 fd             	add    eax,0xfffffffd
  6f4966:	50                   	push   eax
  6f4967:	8d 43 03             	lea    eax,[ebx+0x3]
  6f496a:	50                   	push   eax
  6f496b:	33 c0                	xor    eax,eax
  6f496d:	8b d7                	mov    edx,edi
  6f496f:	e8 9c 27 00 00       	call   0x6f7110
  6f4974:	83 c4 08             	add    esp,0x8
  6f4977:	85 c0                	test   eax,eax
  6f4979:	0f 85 97 00 00 00    	jne    0x6f4a16
  6f497f:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  6f4982:	83 e8 10             	sub    eax,0x10
  6f4985:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  6f4989:	2b 47 20             	sub    eax,DWORD PTR [edi+0x20]
  6f498c:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  6f4990:	50                   	push   eax
  6f4991:	51                   	push   ecx
  6f4992:	eb 4f                	jmp    0x6f49e3
  6f4994:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4998:	33 c0                	xor    eax,eax
  6f499a:	8d 54 24 0c          	lea    edx,[esp+0xc]
  6f499e:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6f49a2:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  6f49a6:	57                   	push   edi
  6f49a7:	b9 00 27 c4 00       	mov    ecx,0xc42700
  6f49ac:	8d 44 24 18          	lea    eax,[esp+0x18]
  6f49b0:	89 5c 24 10          	mov    DWORD PTR [esp+0x10],ebx
  6f49b4:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  6f49b8:	c7 44 24 20 e0 70 6f 	mov    DWORD PTR [esp+0x20],0x6f70e0
  6f49bf:	00 
  6f49c0:	89 54 24 24          	mov    DWORD PTR [esp+0x24],edx
  6f49c4:	e8 c7 9f 00 00       	call   0x6fe990
  6f49c9:	83 c4 04             	add    esp,0x4
  6f49cc:	85 c0                	test   eax,eax
  6f49ce:	75 46                	jne    0x6f4a16
  6f49d0:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  6f49d3:	83 e8 10             	sub    eax,0x10
  6f49d6:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  6f49da:	2b 47 20             	sub    eax,DWORD PTR [edi+0x20]
  6f49dd:	50                   	push   eax
  6f49de:	8d 44 24 10          	lea    eax,[esp+0x10]
  6f49e2:	50                   	push   eax
  6f49e3:	68 50 5a 6f 00       	push   0x6f5a50
  6f49e8:	33 d2                	xor    edx,edx
  6f49ea:	8b c7                	mov    eax,edi
  6f49ec:	c7 44 24 1c ff ff ff 	mov    DWORD PTR [esp+0x1c],0xffffffff
  6f49f3:	ff 
  6f49f4:	e8 77 9d 00 00       	call   0x6fe770
  6f49f9:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  6f49fc:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  6f49ff:	83 c4 0c             	add    esp,0xc
  6f4a02:	3b 51 08             	cmp    edx,DWORD PTR [ecx+0x8]
  6f4a05:	72 03                	jb     0x6f4a0a
  6f4a07:	89 51 08             	mov    DWORD PTR [ecx+0x8],edx
  6f4a0a:	c7 44 24 0c 00 00 00 	mov    DWORD PTR [esp+0xc],0x0
  6f4a11:	00 
  6f4a12:	85 c0                	test   eax,eax
  6f4a14:	74 08                	je     0x6f4a1e
  6f4a16:	c7 44 24 0c 01 00 00 	mov    DWORD PTR [esp+0xc],0x1
  6f4a1d:	00 
  6f4a1e:	8b 16                	mov    edx,DWORD PTR [esi]
  6f4a20:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  6f4a23:	8b ce                	mov    ecx,esi
  6f4a25:	ff d0                	call   eax
  6f4a27:	53                   	push   ebx
  6f4a28:	e8 10 d3 19 00       	call   0x891d3d
  6f4a2d:	83 c4 04             	add    esp,0x4
  6f4a30:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  6f4a33:	db 44 24 0c          	fild   DWORD PTR [esp+0xc]
  6f4a37:	c7 40 08 03 00 00 00 	mov    DWORD PTR [eax+0x8],0x3
  6f4a3e:	dd 18                	fstp   QWORD PTR [eax]
  6f4a40:	83 47 08 10          	add    DWORD PTR [edi+0x8],0x10
  6f4a44:	5f                   	pop    edi
  6f4a45:	5e                   	pop    esi
  6f4a46:	b8 01 00 00 00       	mov    eax,0x1
  6f4a4b:	5b                   	pop    ebx
  6f4a4c:	8b e5                	mov    esp,ebp
  6f4a4e:	5d                   	pop    ebp
  6f4a4f:	c3                   	ret

# memory_loader_explicit_pointer_length VA=0x006F4C20 raw=0x002F4020 size=170 sha256=73aa9908da2bdf193aeb8a83dd6737aca777e00bc2d891a2d737872c1701e834

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4c20 <.text+0x2f3c20>:
  6f4c20:	55                   	push   ebp
  6f4c21:	8b ec                	mov    ebp,esp
  6f4c23:	83 e4 f8             	and    esp,0xfffffff8
  6f4c26:	83 ec 20             	sub    esp,0x20
  6f4c29:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4c2b:	53                   	push   ebx
  6f4c2c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  6f4c2f:	89 4c 24 0c          	mov    DWORD PTR [esp+0xc],ecx
  6f4c33:	33 c9                	xor    ecx,ecx
  6f4c35:	56                   	push   esi
  6f4c36:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  6f4c3a:	8d 54 24 0c          	lea    edx,[esp+0xc]
  6f4c3e:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  6f4c42:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  6f4c46:	50                   	push   eax
  6f4c47:	b9 00 27 c4 00       	mov    ecx,0xc42700
  6f4c4c:	8d 44 24 18          	lea    eax,[esp+0x18]
  6f4c50:	89 5c 24 10          	mov    DWORD PTR [esp+0x10],ebx
  6f4c54:	c7 44 24 20 e0 70 6f 	mov    DWORD PTR [esp+0x20],0x6f70e0
  6f4c5b:	00 
  6f4c5c:	89 54 24 24          	mov    DWORD PTR [esp+0x24],edx
  6f4c60:	e8 2b 9d 00 00       	call   0x6fe990
  6f4c65:	83 c4 04             	add    esp,0x4
  6f4c68:	85 c0                	test   eax,eax
  6f4c6a:	75 48                	jne    0x6f4cb4
  6f4c6c:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4c6e:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4c71:	83 e8 10             	sub    eax,0x10
  6f4c74:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  6f4c78:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4c7b:	33 d2                	xor    edx,edx
  6f4c7d:	50                   	push   eax
  6f4c7e:	8d 44 24 10          	lea    eax,[esp+0x10]
  6f4c82:	50                   	push   eax
  6f4c83:	68 50 5a 6f 00       	push   0x6f5a50
  6f4c88:	8b c6                	mov    eax,esi
  6f4c8a:	c7 44 24 1c ff ff ff 	mov    DWORD PTR [esp+0x1c],0xffffffff
  6f4c91:	ff 
  6f4c92:	e8 d9 9a 00 00       	call   0x6fe770
  6f4c97:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4c9a:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  6f4c9d:	83 c4 0c             	add    esp,0xc
  6f4ca0:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4ca3:	72 03                	jb     0x6f4ca8
  6f4ca5:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6f4ca8:	85 c0                	test   eax,eax
  6f4caa:	75 08                	jne    0x6f4cb4
  6f4cac:	5e                   	pop    esi
  6f4cad:	5b                   	pop    ebx
  6f4cae:	8b e5                	mov    esp,ebp
  6f4cb0:	5d                   	pop    ebp
  6f4cb1:	c2 04 00             	ret    0x4
  6f4cb4:	53                   	push   ebx
  6f4cb5:	57                   	push   edi
  6f4cb6:	be 01 00 00 00       	mov    esi,0x1
  6f4cbb:	e8 e0 fa ff ff       	call   0x6f47a0
  6f4cc0:	8b c6                	mov    eax,esi
  6f4cc2:	5e                   	pop    esi
  6f4cc3:	5b                   	pop    ebx
  6f4cc4:	8b e5                	mov    esp,ebp
  6f4cc6:	5d                   	pop    ebp
  6f4cc7:	c2 04 00             	ret    0x4

# lb_DoFile_resource_source_copy_and_free VA=0x004A1230 raw=0x000A0630 size=252 sha256=0d87aa229cd4db81421a8472522b84be8a963fc40794f08f51a35c7d09b193cd

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1230 <.text+0xa0230>:
  4a1230:	55                   	push   ebp
  4a1231:	8b ec                	mov    ebp,esp
  4a1233:	6a ff                	push   0xffffffff
  4a1235:	68 7e a9 93 00       	push   0x93a97e
  4a123a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a1240:	50                   	push   eax
  4a1241:	53                   	push   ebx
  4a1242:	56                   	push   esi
  4a1243:	57                   	push   edi
  4a1244:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a1249:	33 c5                	xor    eax,ebp
  4a124b:	50                   	push   eax
  4a124c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a124f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a1255:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1258:	68 e0 d1 be 00       	push   0xbed1e0
  4a125d:	50                   	push   eax
  4a125e:	e8 0d 35 27 00       	call   0x714770
  4a1263:	8b f0                	mov    esi,eax
  4a1265:	83 c4 08             	add    esp,0x8
  4a1268:	85 f6                	test   esi,esi
  4a126a:	0f 84 a6 00 00 00    	je     0x4a1316
  4a1270:	8b 16                	mov    edx,DWORD PTR [esi]
  4a1272:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  4a1275:	8b ce                	mov    ecx,esi
  4a1277:	ff d0                	call   eax
  4a1279:	8b f8                	mov    edi,eax
  4a127b:	8d 4f 01             	lea    ecx,[edi+0x1]
  4a127e:	51                   	push   ecx
  4a127f:	e8 b9 c9 3d 00       	call   0x87dc3d
  4a1284:	8b 16                	mov    edx,DWORD PTR [esi]
  4a1286:	83 c4 04             	add    esp,0x4
  4a1289:	8b d8                	mov    ebx,eax
  4a128b:	8b 42 38             	mov    eax,DWORD PTR [edx+0x38]
  4a128e:	57                   	push   edi
  4a128f:	8b ce                	mov    ecx,esi
  4a1291:	ff d0                	call   eax
  4a1293:	50                   	push   eax
  4a1294:	53                   	push   ebx
  4a1295:	e8 36 c9 3f 00       	call   0x89dbd0
  4a129a:	c6 04 1f 00          	mov    BYTE PTR [edi+ebx*1],0x0
  4a129e:	8b 16                	mov    edx,DWORD PTR [esi]
  4a12a0:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  4a12a3:	83 c4 0c             	add    esp,0xc
  4a12a6:	8b ce                	mov    ecx,esi
  4a12a8:	ff d0                	call   eax
  4a12aa:	8b f8                	mov    edi,eax
  4a12ac:	b8 01 00 00 00       	mov    eax,0x1
  4a12b1:	84 05 d4 f3 fd 00    	test   BYTE PTR ds:0xfdf3d4,al
  4a12b7:	75 26                	jne    0x4a12df
  4a12b9:	09 05 d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,eax
  4a12bf:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a12c6:	e8 b5 30 25 00       	call   0x6f4380
  4a12cb:	68 d0 e6 bc 00       	push   0xbce6d0
  4a12d0:	e8 45 10 3f 00       	call   0x89231a
  4a12d5:	83 c4 04             	add    esp,0x4
  4a12d8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a12df:	8b cf                	mov    ecx,edi
  4a12e1:	53                   	push   ebx
  4a12e2:	bf c8 f3 fd 00       	mov    edi,0xfdf3c8
  4a12e7:	e8 34 39 25 00       	call   0x6f4c20
  4a12ec:	8b 16                	mov    edx,DWORD PTR [esi]
  4a12ee:	8b f8                	mov    edi,eax
  4a12f0:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4a12f3:	8b ce                	mov    ecx,esi
  4a12f5:	ff d0                	call   eax
  4a12f7:	53                   	push   ebx
  4a12f8:	e8 40 0a 3f 00       	call   0x891d3d
  4a12fd:	83 c4 04             	add    esp,0x4
  4a1300:	8b c7                	mov    eax,edi
  4a1302:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a1305:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a130c:	59                   	pop    ecx
  4a130d:	5f                   	pop    edi
  4a130e:	5e                   	pop    esi
  4a130f:	5b                   	pop    ebx
  4a1310:	8b e5                	mov    esp,ebp
  4a1312:	5d                   	pop    ebp
  4a1313:	c2 04 00             	ret    0x4
  4a1316:	33 c0                	xor    eax,eax
  4a1318:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a131b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a1322:	59                   	pop    ecx
  4a1323:	5f                   	pop    edi
  4a1324:	5e                   	pop    esi
  4a1325:	5b                   	pop    ebx
  4a1326:	8b e5                	mov    esp,ebp
  4a1328:	5d                   	pop    ebp
  4a1329:	c2 04 00             	ret    0x4

# lb_init_global_context VA=0x004A0950 raw=0x0009FD50 size=209 sha256=fb8718c27cd1337a724721509e47ef17af7a514ff0940599c39f778ce3210a72

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a0950 <.text+0x9f950>:
  4a0950:	55                   	push   ebp
  4a0951:	8b ec                	mov    ebp,esp
  4a0953:	6a ff                	push   0xffffffff
  4a0955:	68 be 4e 94 00       	push   0x944ebe
  4a095a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a0960:	50                   	push   eax
  4a0961:	83 ec 08             	sub    esp,0x8
  4a0964:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a0969:	33 c5                	xor    eax,ebp
  4a096b:	50                   	push   eax
  4a096c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a096f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a0975:	b8 01 00 00 00       	mov    eax,0x1
  4a097a:	84 05 d4 f3 fd 00    	test   BYTE PTR ds:0xfdf3d4,al
  4a0980:	75 26                	jne    0x4a09a8
  4a0982:	09 05 d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,eax
  4a0988:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a098f:	e8 ec 39 25 00       	call   0x6f4380
  4a0994:	68 d0 e6 bc 00       	push   0xbce6d0
  4a0999:	e8 7c 19 3f 00       	call   0x89231a
  4a099e:	83 c4 04             	add    esp,0x4
  4a09a1:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a09a8:	8d 45 f0             	lea    eax,[ebp-0x10]
  4a09ab:	68 c8 f3 fd 00       	push   0xfdf3c8
  4a09b0:	50                   	push   eax
  4a09b1:	e8 1a 0b 00 00       	call   0x4a14d0
  4a09b6:	83 c4 08             	add    esp,0x8
  4a09b9:	50                   	push   eax
  4a09ba:	e8 f1 0b 00 00       	call   0x4a15b0
  4a09bf:	50                   	push   eax
  4a09c0:	e8 8b 0c 00 00       	call   0x4a1650
  4a09c5:	50                   	push   eax
  4a09c6:	e8 25 0d 00 00       	call   0x4a16f0
  4a09cb:	50                   	push   eax
  4a09cc:	e8 bf 0d 00 00       	call   0x4a1790
  4a09d1:	50                   	push   eax
  4a09d2:	e8 59 0e 00 00       	call   0x4a1830
  4a09d7:	50                   	push   eax
  4a09d8:	e8 f3 0e 00 00       	call   0x4a18d0
  4a09dd:	50                   	push   eax
  4a09de:	e8 8d 0f 00 00       	call   0x4a1970
  4a09e3:	50                   	push   eax
  4a09e4:	e8 27 10 00 00       	call   0x4a1a10
  4a09e9:	50                   	push   eax
  4a09ea:	e8 c1 10 00 00       	call   0x4a1ab0
  4a09ef:	50                   	push   eax
  4a09f0:	e8 5b 11 00 00       	call   0x4a1b50
  4a09f5:	50                   	push   eax
  4a09f6:	e8 f5 11 00 00       	call   0x4a1bf0
  4a09fb:	50                   	push   eax
  4a09fc:	e8 8f 12 00 00       	call   0x4a1c90
  4a0a01:	50                   	push   eax
  4a0a02:	e8 29 13 00 00       	call   0x4a1d30
  4a0a07:	50                   	push   eax
  4a0a08:	e8 c3 13 00 00       	call   0x4a1dd0
  4a0a0d:	b8 24 72 fe 00       	mov    eax,0xfe7224
  4a0a12:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a0a15:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a0a1c:	59                   	pop    ecx
  4a0a1d:	8b e5                	mov    esp,ebp
  4a0a1f:	5d                   	pop    ebp
  4a0a20:	c3                   	ret

# lb_table_context_writer VA=0x004A14D0 raw=0x000A08D0 size=92 sha256=a91964e06d4340ab8dea9e87e945c4eb707ebee24bc664009793bb98b4aa9172

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a14d0 <.text+0xa04d0>:
  4a14d0:	55                   	push   ebp
  4a14d1:	8b ec                	mov    ebp,esp
  4a14d3:	51                   	push   ecx
  4a14d4:	53                   	push   ebx
  4a14d5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4a14d8:	56                   	push   esi
  4a14d9:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a14db:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4a14de:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  4a14e1:	57                   	push   edi
  4a14e2:	89 1d 74 17 fe 00    	mov    DWORD PTR ds:0xfe1774,ebx
  4a14e8:	c7 05 78 17 fe 00 24 	mov    DWORD PTR ds:0xfe1778,0xfe7224
  4a14ef:	72 fe 00 
  4a14f2:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  4a14f5:	72 07                	jb     0x4a14fe
  4a14f7:	8b c6                	mov    eax,esi
  4a14f9:	e8 a2 9e 25 00       	call   0x6fb3a0
  4a14fe:	8b 7e 08             	mov    edi,DWORD PTR [esi+0x8]
  4a1501:	6a 00                	push   0x0
  4a1503:	6a 00                	push   0x0
  4a1505:	56                   	push   esi
  4a1506:	e8 95 84 25 00       	call   0x6f99a0
  4a150b:	89 07                	mov    DWORD PTR [edi],eax
  4a150d:	c7 47 08 05 00 00 00 	mov    DWORD PTR [edi+0x8],0x5
  4a1514:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  4a1518:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a151a:	83 c4 0c             	add    esp,0xc
  4a151d:	bf 20 62 c0 00       	mov    edi,0xc06220
  4a1522:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1527:	e8 64 42 25 00       	call   0x6f5790

# lb_DoFile_registration VA=0x004A1B50 raw=0x000A0F50 size=151 sha256=1cd3e1f383808e29ec2e9720690a5e265d7a60667bc92606e4c439e610311ae7

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1b50 <.text+0xa0b50>:
  4a1b50:	55                   	push   ebp
  4a1b51:	8b ec                	mov    ebp,esp
  4a1b53:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1b56:	53                   	push   ebx
  4a1b57:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a1b5d:	56                   	push   esi
  4a1b5e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1b60:	57                   	push   edi
  4a1b61:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1b63:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1b68:	c7 05 a0 17 fe 00 30 	mov    DWORD PTR ds:0xfe17a0,0x4a1230
  4a1b6f:	12 4a 00 
  4a1b72:	e8 09 3b 25 00       	call   0x6f5680
  4a1b77:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1b79:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a1b7c:	83 e8 10             	sub    eax,0x10
  4a1b7f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1b84:	74 06                	je     0x4a1b8c
  4a1b86:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a1b8a:	74 14                	je     0x4a1ba0
  4a1b8c:	57                   	push   edi
  4a1b8d:	68 c4 26 c4 00       	push   0xc426c4
  4a1b92:	e8 26 15 3f 00       	call   0x8930bd
  4a1b97:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1b99:	83 c4 08             	add    esp,0x8
  4a1b9c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1ba0:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1ba6:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1ba8:	68 14 ae d6 00       	push   0xd6ae14
  4a1bad:	e8 5e 39 25 00       	call   0x6f5510
  4a1bb2:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1bb4:	83 c4 04             	add    esp,0x4
  4a1bb7:	6a 00                	push   0x0
  4a1bb9:	68 00 22 4a 00       	push   0x4a2200
  4a1bbe:	e8 ed 39 25 00       	call   0x6f55b0
  4a1bc3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1bc5:	51                   	push   ecx
  4a1bc6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a1bcb:	e8 20 3c 25 00       	call   0x6f57f0
  4a1bd0:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1bd6:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1bd8:	83 c4 0c             	add    esp,0xc
  4a1bdb:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a1bdf:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1be2:	5f                   	pop    edi
  4a1be3:	5e                   	pop    esi
  4a1be4:	5b                   	pop    ebx
  4a1be5:	5d                   	pop    ebp
  4a1be6:	c2               	ret    0x4

# lb_DoFile_callback VA=0x004A2200 raw=0x000A1600 size=86 sha256=38440d0e7414d01c102746b5a8fc411d6b7f85fb65969be97a0cf2759e317273

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2200 <.text+0xa1200>:
  4a2200:	55                   	push   ebp
  4a2201:	8b ec                	mov    ebp,esp
  4a2203:	6a ff                	push   0xffffffff
  4a2205:	68 c8 83 93 00       	push   0x9383c8
  4a220a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a2210:	50                   	push   eax
  4a2211:	83 ec 0c             	sub    esp,0xc
  4a2214:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a2219:	33 c5                	xor    eax,ebp
  4a221b:	50                   	push   eax
  4a221c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a221f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a2225:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a2228:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4a222b:	33 c0                	xor    eax,eax
  4a222d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a2230:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a2233:	8d 4d e8             	lea    ecx,[ebp-0x18]
  4a2236:	51                   	push   ecx
  4a2237:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a223a:	e8 31 08 00 00       	call   0x4a2a70
  4a223f:	83 c4 04             	add    esp,0x4
  4a2242:	b8 01 00 00 00       	mov    eax,0x1
  4a2247:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a224a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a2251:	59                   	pop    ecx
  4a2252:	8b e5                	mov    esp,ebp
  4a2254:	5d                   	pop    ebp
  4a2255:	c3                   	ret

# lb_DoFile_indirect_bridge VA=0x004A2A70 raw=0x000A1E70 size=126 sha256=ec4577a5c79209560cf16901cc8872095a43fa4f4efc33a4c5cbc5b1e6d2a5bd

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2a70 <.text+0xa1a70>:
  4a2a70:	55                   	push   ebp
  4a2a71:	8b ec                	mov    ebp,esp
  4a2a73:	51                   	push   ecx
  4a2a74:	a1 a0 17 fe 00       	mov    eax,ds:0xfe17a0
  4a2a79:	8b 0d 78 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe1778
  4a2a7f:	53                   	push   ebx
  4a2a80:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4a2a83:	56                   	push   esi
  4a2a84:	57                   	push   edi
  4a2a85:	8b 3b                	mov    edi,DWORD PTR [ebx]
  4a2a87:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  4a2a8a:	83 ee 10             	sub    esi,0x10
  4a2a8d:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  4a2a91:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4a2a94:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  4a2a97:	74 25                	je     0x4a2abe
  4a2a99:	e8 32 8b 25 00       	call   0x6fb5d0
  4a2a9e:	85 c0                	test   eax,eax
  4a2aa0:	75 04                	jne    0x4a2aa6
  4a2aa2:	33 f6                	xor    esi,esi
  4a2aa4:	eb 1d                	jmp    0x4a2ac3
  4a2aa6:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  4a2aa9:	8b 50 44             	mov    edx,DWORD PTR [eax+0x44]
  4a2aac:	3b 50 40             	cmp    edx,DWORD PTR [eax+0x40]
  4a2aaf:	72 07                	jb     0x4a2ab8
  4a2ab1:	8b c7                	mov    eax,edi
  4a2ab3:	e8 e8 88 25 00       	call   0x6fb3a0
  4a2ab8:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  4a2abb:	83 ee 10             	sub    esi,0x10
  4a2abe:	8b 36                	mov    esi,DWORD PTR [esi]
  4a2ac0:	83 c6 10             	add    esi,0x10
  4a2ac3:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4a2ac6:	56                   	push   esi
  4a2ac7:	ff 55 08             	call   DWORD PTR [ebp+0x8]
  4a2aca:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4a2acd:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a2acf:	db 45 08             	fild   DWORD PTR [ebp+0x8]
  4a2ad2:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a2ad5:	5f                   	pop    edi
  4a2ad6:	dd 19                	fstp   QWORD PTR [ecx]
  4a2ad8:	c7 41 08 03 00 00 00 	mov    DWORD PTR [ecx+0x8],0x3
  4a2adf:	83 40 08 10          	add    DWORD PTR [eax+0x8],0x10
  4a2ae3:	5e                   	pop    esi
  4a2ae4:	b8 01 00 00 00       	mov    eax,0x1
  4a2ae9:	5b                   	pop    ebx
  4a2aea:	8b e5                	mov    esp,ebp
  4a2aec:	5d                   	pop    ebp
  4a2aed:	c3                   	ret

# one_shot_buffer_reader VA=0x006F70E0 raw=0x002F64E0 size=34 sha256=c8199ff69b93cbff9770298516ae13ce70f9cd107592e4eb2302912853d47f3c

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f70e0 <.text+0x2f60e0>:
  6f70e0:	55                   	push   ebp
  6f70e1:	8b ec                	mov    ebp,esp
  6f70e3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6f70e6:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  6f70e9:	85 c9                	test   ecx,ecx
  6f70eb:	75 04                	jne    0x6f70f1
  6f70ed:	33 c0                	xor    eax,eax
  6f70ef:	5d                   	pop    ebp
  6f70f0:	c3                   	ret
  6f70f1:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  6f70f4:	89 0a                	mov    DWORD PTR [edx],ecx
  6f70f6:	c7 40 04 00 00 00 00 	mov    DWORD PTR [eax+0x4],0x0
  6f70fd:	8b 00                	mov    eax,DWORD PTR [eax]
  6f70ff:	5d                   	pop    ebp
  6f7100:	c3                   	ret
  6f7101:	cc                   	int3

# aux_memory_parse_wrapper VA=0x006F7110 raw=0x002F6510 size=88 sha256=548e1a18c3cf68131e707fd475211f1831f5dc643af2ab4b962033d0957bee47

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f7110 <.text+0x2f6110>:
  6f7110:	55                   	push   ebp
  6f7111:	8b ec                	mov    ebp,esp
  6f7113:	83 e4 f8             	and    esp,0xfffffff8
  6f7116:	83 ec 20             	sub    esp,0x20
  6f7119:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  6f711c:	89 4c 24 04          	mov    DWORD PTR [esp+0x4],ecx
  6f7120:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  6f7123:	89 4c 24 08          	mov    DWORD PTR [esp+0x8],ecx
  6f7127:	8b c8                	mov    ecx,eax
  6f7129:	85 c0                	test   eax,eax
  6f712b:	75 05                	jne    0x6f7132
  6f712d:	b9 00 27 c4 00       	mov    ecx,0xc42700
  6f7132:	8d 44 24 04          	lea    eax,[esp+0x4]
  6f7136:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  6f713a:	52                   	push   edx
  6f713b:	8d 44 24 10          	lea    eax,[esp+0x10]
  6f713f:	89 54 24 20          	mov    DWORD PTR [esp+0x20],edx
  6f7143:	c7 44 24 18 e0 70 6f 	mov    DWORD PTR [esp+0x18],0x6f70e0
  6f714a:	00 
  6f714b:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  6f7152:	00 
  6f7153:	c7 44 24 14 00 00 00 	mov    DWORD PTR [esp+0x14],0x0
  6f715a:	00 
  6f715b:	e8 30 78 00 00       	call   0x6fe990
  6f7160:	83 c4 04             	add    esp,0x4
  6f7163:	8b e5                	mov    esp,ebp
  6f7165:	5d                   	pop    ebp
  6f7166:	c3                   	ret
  6f7167:	cc                   	int3

# stream_peek_indirect_reader VA=0x006FEE30 raw=0x002FE230 size=82 sha256=ece476beea0a2e63ad0927caaf458d2ef86d37643d1bf01e6f3d7bcd4224263f

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fee30 <.text+0x2fde30>:
  6fee30:	55                   	push   ebp
  6fee31:	8b ec                	mov    ebp,esp
  6fee33:	51                   	push   ecx
  6fee34:	83 3e 00             	cmp    DWORD PTR [esi],0x0
  6fee37:	75 3f                	jne    0x6fee78
  6fee39:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  6fee3c:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  6fee3f:	8d 4d fc             	lea    ecx,[ebp-0x4]
  6fee42:	51                   	push   ecx
  6fee43:	52                   	push   edx
  6fee44:	50                   	push   eax
  6fee45:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6fee48:	ff d0                	call   eax
  6fee4a:	83 c4 0c             	add    esp,0xc
  6fee4d:	85 c0                	test   eax,eax
  6fee4f:	74 19                	je     0x6fee6a
  6fee51:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6fee54:	85 c9                	test   ecx,ecx
  6fee56:	74 12                	je     0x6fee6a
  6fee58:	49                   	dec    ecx
  6fee59:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  6fee5c:	89 0e                	mov    DWORD PTR [esi],ecx
  6fee5e:	0f b6 10             	movzx  edx,BYTE PTR [eax]
  6fee61:	40                   	inc    eax
  6fee62:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  6fee65:	83 fa ff             	cmp    edx,0xffffffff
  6fee68:	75 07                	jne    0x6fee71
  6fee6a:	83 c8 ff             	or     eax,0xffffffff
  6fee6d:	8b e5                	mov    esp,ebp
  6fee6f:	5d                   	pop    ebp
  6fee70:	c3                   	ret
  6fee71:	41                   	inc    ecx
  6fee72:	48                   	dec    eax
  6fee73:	89 0e                	mov    DWORD PTR [esi],ecx
  6fee75:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  6fee78:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  6fee7b:	0f b6 01             	movzx  eax,BYTE PTR [ecx]
  6fee7e:	8b e5                	mov    esp,ebp
  6fee80:	5d                   	pop    ebp
  6fee81:	c3                   	ret

# stream_exact_copy_indirect_reader VA=0x006FEE90 raw=0x002FE290 size=134 sha256=59130bf67db9eaffb524638df27c9b57b6dbf2d4918e953831e4028686ae3543

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fee90 <.text+0x2fde90>:
  6fee90:	55                   	push   ebp
  6fee91:	8b ec                	mov    ebp,esp
  6fee93:	53                   	push   ebx
  6fee94:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  6fee97:	57                   	push   edi
  6fee98:	85 db                	test   ebx,ebx
  6fee9a:	74 6e                	je     0x6fef0a
  6fee9c:	8d 64 24 00          	lea    esp,[esp+0x0]
  6feea0:	83 3e 00             	cmp    DWORD PTR [esi],0x0
  6feea3:	75 38                	jne    0x6feedd
  6feea5:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  6feea8:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  6feeab:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  6feeae:	51                   	push   ecx
  6feeaf:	52                   	push   edx
  6feeb0:	50                   	push   eax
  6feeb1:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6feeb4:	ff d0                	call   eax
  6feeb6:	83 c4 0c             	add    esp,0xc
  6feeb9:	85 c0                	test   eax,eax
  6feebb:	74 53                	je     0x6fef10
  6feebd:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  6feec0:	85 c9                	test   ecx,ecx
  6feec2:	74 4c                	je     0x6fef10
  6feec4:	49                   	dec    ecx
  6feec5:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  6feec8:	89 0e                	mov    DWORD PTR [esi],ecx
  6feeca:	0f b6 10             	movzx  edx,BYTE PTR [eax]
  6feecd:	40                   	inc    eax
  6feece:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  6feed1:	83 fa ff             	cmp    edx,0xffffffff
  6feed4:	74 3a                	je     0x6fef10
  6feed6:	41                   	inc    ecx
  6feed7:	48                   	dec    eax
  6feed8:	89 0e                	mov    DWORD PTR [esi],ecx
  6feeda:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  6feedd:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  6feee0:	0f b6 08             	movzx  ecx,BYTE PTR [eax]
  6feee3:	83 f9 ff             	cmp    ecx,0xffffffff
  6feee6:	74 28                	je     0x6fef10
  6feee8:	8b 3e                	mov    edi,DWORD PTR [esi]
  6feeea:	3b df                	cmp    ebx,edi
  6feeec:	77 02                	ja     0x6feef0
  6feeee:	8b fb                	mov    edi,ebx
  6feef0:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  6feef3:	57                   	push   edi
  6feef4:	50                   	push   eax
  6feef5:	51                   	push   ecx
  6feef6:	e8 d5 ec 19 00       	call   0x89dbd0
  6feefb:	29 3e                	sub    DWORD PTR [esi],edi
  6feefd:	01 7e 04             	add    DWORD PTR [esi+0x4],edi
  6fef00:	01 7d 08             	add    DWORD PTR [ebp+0x8],edi
  6fef03:	83 c4 0c             	add    esp,0xc
  6fef06:	2b df                	sub    ebx,edi
  6fef08:	75 96                	jne    0x6feea0
  6fef0a:	5f                   	pop    edi
  6fef0b:	33 c0                	xor    eax,eax
  6fef0d:	5b                   	pop    ebx
  6fef0e:	5d                   	pop    ebp
  6fef0f:	c3                   	ret
  6fef10:	5f                   	pop    edi
  6fef11:	8b c3                	mov    eax,ebx
  6fef13:	5b                   	pop    ebx
  6fef14:	5d                   	pop    ebp
  6fef15:	c3                   	ret

# protected_parser_and_temp_buffer_free VA=0x006FE990 raw=0x002FDD90 size=107 sha256=10c8934260650a66dd92af8c1faf5ec848cf9f7f7b26a5b612c2d26e8a251972

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe990 <.text+0x2fd990>:
  6fe990:	55                   	push   ebp
  6fe991:	8b ec                	mov    ebp,esp
  6fe993:	83 e4 f8             	and    esp,0xfffffff8
  6fe996:	83 ec 14             	sub    esp,0x14
  6fe999:	53                   	push   ebx
  6fe99a:	56                   	push   esi
  6fe99b:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6fe99e:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  6fe9a1:	2b 56 20             	sub    edx,DWORD PTR [esi+0x20]
  6fe9a4:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  6fe9a8:	33 c0                	xor    eax,eax
  6fe9aa:	57                   	push   edi
  6fe9ab:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6fe9af:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  6fe9b3:	52                   	push   edx
  6fe9b4:	8b 56 74             	mov    edx,DWORD PTR [esi+0x74]
  6fe9b7:	8d 44 24 10          	lea    eax,[esp+0x10]
  6fe9bb:	50                   	push   eax
  6fe9bc:	68 60 e8 6f 00       	push   0x6fe860
  6fe9c1:	8b c6                	mov    eax,esi
  6fe9c3:	89 4c 24 28          	mov    DWORD PTR [esp+0x28],ecx
  6fe9c7:	e8 a4 fd ff ff       	call   0x6fe770
  6fe9cc:	8b 76 10             	mov    esi,DWORD PTR [esi+0x10]
  6fe9cf:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  6fe9d3:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  6fe9d6:	83 c4 0c             	add    esp,0xc
  6fe9d9:	8b f8                	mov    edi,eax
  6fe9db:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  6fe9df:	6a 00                	push   0x0
  6fe9e1:	50                   	push   eax
  6fe9e2:	51                   	push   ecx
  6fe9e3:	8b d8                	mov    ebx,eax
  6fe9e5:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  6fe9e8:	52                   	push   edx
  6fe9e9:	ff d0                	call   eax
  6fe9eb:	83 c4 10             	add    esp,0x10
  6fe9ee:	29 5e 44             	sub    DWORD PTR [esi+0x44],ebx
  6fe9f1:	8b c7                	mov    eax,edi
  6fe9f3:	5f                   	pop    edi
  6fe9f4:	5e                   	pop    esi
  6fe9f5:	5b                   	pop    ebx
  6fe9f6:	8b e5                	mov    esp,ebp
  6fe9f8:	5d                   	pop    ebp
  6fe9f9:	c3                   	ret
  6fe9fa:	cc                   	int3

# text_binary_switch_and_closure VA=0x006FE860 raw=0x002FDC60 size=291 sha256=755c9c11fabbd490a8e298f5b2e5c1f67f6facc7dbbffdfb0147c8138d687d4d

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe860 <.text+0x2fd860>:
  6fe860:	55                   	push   ebp
  6fe861:	8b ec                	mov    ebp,esp
  6fe863:	83 e4 f8             	and    esp,0xfffffff8
  6fe866:	83 ec 0c             	sub    esp,0xc
  6fe869:	53                   	push   ebx
  6fe86a:	56                   	push   esi
  6fe86b:	57                   	push   edi
  6fe86c:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  6fe86f:	8b 37                	mov    esi,DWORD PTR [edi]
  6fe871:	e8 ba 05 00 00       	call   0x6fee30
  6fe876:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6fe879:	8b d8                	mov    ebx,eax
  6fe87b:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  6fe87e:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  6fe881:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  6fe884:	72 07                	jb     0x6fe88d
  6fe886:	8b c6                	mov    eax,esi
  6fe888:	e8 13 cb ff ff       	call   0x6fb3a0
  6fe88d:	b8 80 d6 70 00       	mov    eax,0x70d680
  6fe892:	83 fb 1b             	cmp    ebx,0x1b
  6fe895:	74 05                	je     0x6fe89c
  6fe897:	b8 20 e4 70 00       	mov    eax,0x70e420
  6fe89c:	8b 57 10             	mov    edx,DWORD PTR [edi+0x10]
  6fe89f:	52                   	push   edx
  6fe8a0:	8b 17                	mov    edx,DWORD PTR [edi]
  6fe8a2:	8d 4f 04             	lea    ecx,[edi+0x4]
  6fe8a5:	51                   	push   ecx
  6fe8a6:	52                   	push   edx
  6fe8a7:	56                   	push   esi
  6fe8a8:	ff d0                	call   eax
  6fe8aa:	8b f8                	mov    edi,eax
  6fe8ac:	8b 46 48             	mov    eax,DWORD PTR [esi+0x48]
  6fe8af:	0f b6 4f 48          	movzx  ecx,BYTE PTR [edi+0x48]
  6fe8b3:	50                   	push   eax
  6fe8b4:	51                   	push   ecx
  6fe8b5:	8b c6                	mov    eax,esi
  6fe8b7:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  6fe8bb:	e8 70 ee ff ff       	call   0x6fd730
  6fe8c0:	33 db                	xor    ebx,ebx
  6fe8c2:	83 c4 18             	add    esp,0x18
  6fe8c5:	89 78 10             	mov    DWORD PTR [eax+0x10],edi
  6fe8c8:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6fe8cc:	38 5f 48             	cmp    BYTE PTR [edi+0x48],bl
  6fe8cf:	76 67                	jbe    0x6fe938
  6fe8d1:	83 c0 14             	add    eax,0x14
  6fe8d4:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  6fe8d8:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  6fe8db:	8b 57 10             	mov    edx,DWORD PTR [edi+0x10]
  6fe8de:	8b 47 0c             	mov    eax,DWORD PTR [edi+0xc]
  6fe8e1:	6a 20                	push   0x20
  6fe8e3:	6a 00                	push   0x0
  6fe8e5:	6a 00                	push   0x0
  6fe8e7:	52                   	push   edx
  6fe8e8:	ff d0                	call   eax
  6fe8ea:	83 c4 10             	add    esp,0x10
  6fe8ed:	85 c0                	test   eax,eax
  6fe8ef:	74 78                	je     0x6fe969
  6fe8f1:	83 47 44 20          	add    DWORD PTR [edi+0x44],0x20
  6fe8f5:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  6fe8f8:	8b 51 1c             	mov    edx,DWORD PTR [ecx+0x1c]
  6fe8fb:	89 10                	mov    DWORD PTR [eax],edx
  6fe8fd:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  6fe901:	89 41 1c             	mov    DWORD PTR [ecx+0x1c],eax
  6fe904:	8a 49 14             	mov    cl,BYTE PTR [ecx+0x14]
  6fe907:	80 e1 03             	and    cl,0x3
  6fe90a:	88 48 05             	mov    BYTE PTR [eax+0x5],cl
  6fe90d:	8d 48 10             	lea    ecx,[eax+0x10]
  6fe910:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  6fe913:	c6 40 04 0a          	mov    BYTE PTR [eax+0x4],0xa
  6fe917:	c7 41 08 00 00 00 00 	mov    DWORD PTR [ecx+0x8],0x0
  6fe91e:	8b 4c 24 0c          	mov    ecx,DWORD PTR [esp+0xc]
  6fe922:	89 01                	mov    DWORD PTR [ecx],eax
  6fe924:	0f b6 42 48          	movzx  eax,BYTE PTR [edx+0x48]
  6fe928:	43                   	inc    ebx
  6fe929:	83 c1 04             	add    ecx,0x4
  6fe92c:	89 4c 24 0c          	mov    DWORD PTR [esp+0xc],ecx
  6fe930:	3b d8                	cmp    ebx,eax
  6fe932:	7c a4                	jl     0x6fe8d8
  6fe934:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  6fe938:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6fe93b:	89 01                	mov    DWORD PTR [ecx],eax
  6fe93d:	c7 41 08 06 00 00 00 	mov    DWORD PTR [ecx+0x8],0x6
  6fe944:	8b 4e 1c             	mov    ecx,DWORD PTR [esi+0x1c]
  6fe947:	2b 4e 08             	sub    ecx,DWORD PTR [esi+0x8]
  6fe94a:	83 f9 10             	cmp    ecx,0x10
  6fe94d:	7f 28                	jg     0x6fe977
  6fe94f:	8b 46 2c             	mov    eax,DWORD PTR [esi+0x2c]
  6fe952:	83 f8 01             	cmp    eax,0x1
  6fe955:	7c 1a                	jl     0x6fe971
  6fe957:	03 c0                	add    eax,eax
  6fe959:	e8 52 f3 ff ff       	call   0x6fdcb0
  6fe95e:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  6fe962:	5f                   	pop    edi
  6fe963:	5e                   	pop    esi
  6fe964:	5b                   	pop    ebx
  6fe965:	8b e5                	mov    esp,ebp
  6fe967:	5d                   	pop    ebp
  6fe968:	c3                   	ret
  6fe969:	6a 04                	push   0x4
  6fe96b:	56                   	push   esi
  6fe96c:	e8 cf f1 ff ff       	call   0x6fdb40
  6fe971:	40                   	inc    eax
  6fe972:	e8 39 f3 ff ff       	call   0x6fdcb0
  6fe977:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  6fe97b:	5f                   	pop    edi
  6fe97c:	5e                   	pop    esi
  6fe97d:	5b                   	pop    ebx
  6fe97e:	8b e5                	mov    esp,ebp
  6fe980:	5d                   	pop    ebp
  6fe981:	c3                   	ret
  6fe982:	cc                   	int3

# binary_header_exact_twelve_bytes VA=0x0070D5F0 raw=0x0030C9F0 size=128 sha256=2b0ec39c5efe8c347d059731cb0eb4a6e68b5077c354cedd86276427b0b8ae10

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070d5f0 <.text+0x30c5f0>:
  70d5f0:	55                   	push   ebp
  70d5f1:	8b ec                	mov    ebp,esp
  70d5f3:	83 ec 1c             	sub    esp,0x1c
  70d5f6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  70d5fb:	33 c5                	xor    eax,ebp
  70d5fd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  70d600:	56                   	push   esi
  70d601:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  70d604:	8d 45 e4             	lea    eax,[ebp-0x1c]
  70d607:	6a 0c                	push   0xc
  70d609:	50                   	push   eax
  70d60a:	c7 45 f0 1b 4c 75 61 	mov    DWORD PTR [ebp-0x10],0x61754c1b
  70d611:	c7 45 f4 51 00 01 04 	mov    DWORD PTR [ebp-0xc],0x4010051
  70d618:	c7 45 f8 04 04 08 00 	mov    DWORD PTR [ebp-0x8],0x80404
  70d61f:	e8 6c 18 ff ff       	call   0x6fee90
  70d624:	83 c4 08             	add    esp,0x8
  70d627:	85 c0                	test   eax,eax
  70d629:	74 0c                	je     0x70d637
  70d62b:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70d630:	8b f7                	mov    esi,edi
  70d632:	e8 d9 f5 ff ff       	call   0x70cc10
  70d637:	b8 0c 00 00 00       	mov    eax,0xc
  70d63c:	33 c9                	xor    ecx,ecx
  70d63e:	8b ff                	mov    edi,edi
  70d640:	8b 54 0d f0          	mov    edx,DWORD PTR [ebp+ecx*1-0x10]
  70d644:	3b 54 0d e4          	cmp    edx,DWORD PTR [ebp+ecx*1-0x1c]
  70d648:	75 1a                	jne    0x70d664
  70d64a:	83 e8 04             	sub    eax,0x4
  70d64d:	83 c1 04             	add    ecx,0x4
  70d650:	83 f8 04             	cmp    eax,0x4
  70d653:	73 eb                	jae    0x70d640
  70d655:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  70d658:	33 cd                	xor    ecx,ebp
  70d65a:	5e                   	pop    esi
  70d65b:	e8 a1 39 18 00       	call   0x891001
  70d660:	8b e5                	mov    esp,ebp
  70d662:	5d                   	pop    ebp
  70d663:	c3                   	ret
  70d664:	b8 74 3e c4 00       	mov    eax,0xc43e74
  70d669:	8b f7                	mov    esi,edi
  70d66b:	e8 a0 f5 ff ff       	call   0x70cc10

# binary_chunk_loader_name_is_diagnostic VA=0x0070D680 raw=0x0030CA80 size=107 sha256=4903e976aea34a621f1833977bfcb18a4b5cbb87b693be9bfe1163b4b3dbbf78

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070d680 <.text+0x30c680>:
  70d680:	55                   	push   ebp
  70d681:	8b ec                	mov    ebp,esp
  70d683:	83 e4 f8             	and    esp,0xfffffff8
  70d686:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  70d689:	8a 01                	mov    al,BYTE PTR [ecx]
  70d68b:	83 ec 10             	sub    esp,0x10
  70d68e:	56                   	push   esi
  70d68f:	57                   	push   edi
  70d690:	3c 40                	cmp    al,0x40
  70d692:	74 12                	je     0x70d6a6
  70d694:	3c 3d                	cmp    al,0x3d
  70d696:	74 0e                	je     0x70d6a6
  70d698:	3c 1b                	cmp    al,0x1b
  70d69a:	75 0b                	jne    0x70d6a7
  70d69c:	c7 44 24 14 80 3e c4 	mov    DWORD PTR [esp+0x14],0xc43e80
  70d6a3:	00 
  70d6a4:	eb 05                	jmp    0x70d6ab
  70d6a6:	41                   	inc    ecx
  70d6a7:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  70d6ab:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  70d6ae:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  70d6b1:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70d6b4:	8d 7c 24 08          	lea    edi,[esp+0x8]
  70d6b8:	89 74 24 08          	mov    DWORD PTR [esp+0x8],esi
  70d6bc:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  70d6c0:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  70d6c4:	e8 27 ff ff ff       	call   0x70d5f0
  70d6c9:	6a 02                	push   0x2
  70d6cb:	68 90 3e c4 00       	push   0xc43e90
  70d6d0:	56                   	push   esi
  70d6d1:	e8 9a 15 ff ff       	call   0x6fec70
  70d6d6:	83 c4 0c             	add    esp,0xc
  70d6d9:	50                   	push   eax
  70d6da:	8b d7                	mov    edx,edi
  70d6dc:	52                   	push   edx
  70d6dd:	e8 be fc ff ff       	call   0x70d3a0
  70d6e2:	83 c4 08             	add    esp,0x8
  70d6e5:	5f                   	pop    edi
  70d6e6:	5e                   	pop    esi
  70d6e7:	8b e5                	mov    esp,ebp
  70d6e9:	5d                   	pop    ebp
  70d6ea:	c3                   	ret

# binary_proto_allocate_load_validate VA=0x0070D3A0 raw=0x0030C7A0 size=580 sha256=5be66d7bec6f4397e1d0d59d10b1df88638e218c121d3c2f121a6d2e26016a52

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070d3a0 <.text+0x30c3a0>:
  70d3a0:	55                   	push   ebp
  70d3a1:	8b ec                	mov    ebp,esp
  70d3a3:	83 e4 f8             	and    esp,0xfffffff8
  70d3a6:	83 ec 0c             	sub    esp,0xc
  70d3a9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  70d3ac:	8b 00                	mov    eax,DWORD PTR [eax]
  70d3ae:	53                   	push   ebx
  70d3af:	56                   	push   esi
  70d3b0:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  70d3b3:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  70d3b6:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  70d3b9:	57                   	push   edi
  70d3ba:	6a 4c                	push   0x4c
  70d3bc:	33 db                	xor    ebx,ebx
  70d3be:	53                   	push   ebx
  70d3bf:	53                   	push   ebx
  70d3c0:	51                   	push   ecx
  70d3c1:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  70d3c5:	ff d2                	call   edx
  70d3c7:	8b f8                	mov    edi,eax
  70d3c9:	83 c4 10             	add    esp,0x10
  70d3cc:	3b fb                	cmp    edi,ebx
  70d3ce:	75 0c                	jne    0x70d3dc
  70d3d0:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  70d3d4:	6a 04                	push   0x4
  70d3d6:	50                   	push   eax
  70d3d7:	e8 64 07 ff ff       	call   0x6fdb40
  70d3dc:	83 46 44 4c          	add    DWORD PTR [esi+0x44],0x4c
  70d3e0:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  70d3e4:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  70d3e7:	8b 50 1c             	mov    edx,DWORD PTR [eax+0x1c]
  70d3ea:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70d3ed:	89 17                	mov    DWORD PTR [edi],edx
  70d3ef:	89 78 1c             	mov    DWORD PTR [eax+0x1c],edi
  70d3f2:	8a 40 14             	mov    al,BYTE PTR [eax+0x14]
  70d3f5:	24 03                	and    al,0x3
  70d3f7:	88 47 05             	mov    BYTE PTR [edi+0x5],al
  70d3fa:	89 5f 08             	mov    DWORD PTR [edi+0x8],ebx
  70d3fd:	89 5f 28             	mov    DWORD PTR [edi+0x28],ebx
  70d400:	89 5f 10             	mov    DWORD PTR [edi+0x10],ebx
  70d403:	89 5f 34             	mov    DWORD PTR [edi+0x34],ebx
  70d406:	89 5f 0c             	mov    DWORD PTR [edi+0xc],ebx
  70d409:	89 5f 2c             	mov    DWORD PTR [edi+0x2c],ebx
  70d40c:	89 5f 30             	mov    DWORD PTR [edi+0x30],ebx
  70d40f:	89 5f 24             	mov    DWORD PTR [edi+0x24],ebx
  70d412:	89 5f 1c             	mov    DWORD PTR [edi+0x1c],ebx
  70d415:	89 5f 48             	mov    DWORD PTR [edi+0x48],ebx
  70d418:	89 5f 14             	mov    DWORD PTR [edi+0x14],ebx
  70d41b:	89 5f 38             	mov    DWORD PTR [edi+0x38],ebx
  70d41e:	89 5f 18             	mov    DWORD PTR [edi+0x18],ebx
  70d421:	89 5f 3c             	mov    DWORD PTR [edi+0x3c],ebx
  70d424:	89 5f 40             	mov    DWORD PTR [edi+0x40],ebx
  70d427:	89 5f 20             	mov    DWORD PTR [edi+0x20],ebx
  70d42a:	b9 09 00 00 00       	mov    ecx,0x9
  70d42f:	88 4f 04             	mov    BYTE PTR [edi+0x4],cl
  70d432:	8b 16                	mov    edx,DWORD PTR [esi]
  70d434:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  70d437:	89 38                	mov    DWORD PTR [eax],edi
  70d439:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  70d43c:	8b 0e                	mov    ecx,DWORD PTR [esi]
  70d43e:	8b 41 1c             	mov    eax,DWORD PTR [ecx+0x1c]
  70d441:	2b 41 08             	sub    eax,DWORD PTR [ecx+0x8]
  70d444:	83 f8 10             	cmp    eax,0x10
  70d447:	7f 17                	jg     0x70d460
  70d449:	8b 41 2c             	mov    eax,DWORD PTR [ecx+0x2c]
  70d44c:	8b f1                	mov    esi,ecx
  70d44e:	83 f8 01             	cmp    eax,0x1
  70d451:	7c 04                	jl     0x70d457
  70d453:	03 c0                	add    eax,eax
  70d455:	eb 01                	jmp    0x70d458
  70d457:	40                   	inc    eax
  70d458:	e8 53 08 ff ff       	call   0x6fdcb0
  70d45d:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70d460:	8b 06                	mov    eax,DWORD PTR [esi]
  70d462:	83 40 08 10          	add    DWORD PTR [eax+0x8],0x10
  70d466:	56                   	push   esi
  70d467:	e8 d4 f7 ff ff       	call   0x70cc40
  70d46c:	83 c4 04             	add    esp,0x4
  70d46f:	89 47 20             	mov    DWORD PTR [edi+0x20],eax
  70d472:	3b c3                	cmp    eax,ebx
  70d474:	75 06                	jne    0x70d47c
  70d476:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  70d479:	89 4f 20             	mov    DWORD PTR [edi+0x20],ecx
  70d47c:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  70d47f:	8d 54 24 14          	lea    edx,[esp+0x14]
  70d483:	6a 04                	push   0x4
  70d485:	52                   	push   edx
  70d486:	e8 05 1a ff ff       	call   0x6fee90
  70d48b:	83 c4 08             	add    esp,0x8
  70d48e:	85 c0                	test   eax,eax
  70d490:	74 0d                	je     0x70d49f
  70d492:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70d495:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70d49a:	e8 71 f7 ff ff       	call   0x70cc10
  70d49f:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  70d4a3:	3b c3                	cmp    eax,ebx
  70d4a5:	7d 0d                	jge    0x70d4b4
  70d4a7:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70d4aa:	b8 4c 3e c4 00       	mov    eax,0xc43e4c
  70d4af:	e8 5c f7 ff ff       	call   0x70cc10
  70d4b4:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  70d4b7:	89 47 3c             	mov    DWORD PTR [edi+0x3c],eax
  70d4ba:	8b 71 04             	mov    esi,DWORD PTR [ecx+0x4]
  70d4bd:	8d 44 24 14          	lea    eax,[esp+0x14]
  70d4c1:	6a 04                	push   0x4
  70d4c3:	50                   	push   eax
  70d4c4:	e8 c7 19 ff ff       	call   0x6fee90
  70d4c9:	83 c4 08             	add    esp,0x8
  70d4cc:	85 c0                	test   eax,eax
  70d4ce:	74 0d                	je     0x70d4dd
  70d4d0:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70d4d3:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70d4d8:	e8 33 f7 ff ff       	call   0x70cc10
  70d4dd:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  70d4e1:	3b c3                	cmp    eax,ebx
  70d4e3:	7d 0d                	jge    0x70d4f2
  70d4e5:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70d4e8:	b8 4c 3e c4 00       	mov    eax,0xc43e4c
  70d4ed:	e8 1e f7 ff ff       	call   0x70cc10
  70d4f2:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  70d4f5:	8d 54 24 13          	lea    edx,[esp+0x13]
  70d4f9:	89 47 40             	mov    DWORD PTR [edi+0x40],eax
  70d4fc:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  70d4ff:	6a 01                	push   0x1
  70d501:	52                   	push   edx
  70d502:	e8 89 19 ff ff       	call   0x6fee90
  70d507:	83 c4 08             	add    esp,0x8
  70d50a:	85 c0                	test   eax,eax
  70d50c:	74 0c                	je     0x70d51a
  70d50e:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70d513:	8b f3                	mov    esi,ebx
  70d515:	e8 f6 f6 ff ff       	call   0x70cc10
  70d51a:	8a 44 24 13          	mov    al,BYTE PTR [esp+0x13]
  70d51e:	8d 4c 24 13          	lea    ecx,[esp+0x13]
  70d522:	88 47 48             	mov    BYTE PTR [edi+0x48],al
  70d525:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  70d528:	6a 01                	push   0x1
  70d52a:	51                   	push   ecx
  70d52b:	e8 60 19 ff ff       	call   0x6fee90
  70d530:	83 c4 08             	add    esp,0x8
  70d533:	85 c0                	test   eax,eax
  70d535:	74 0c                	je     0x70d543
  70d537:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70d53c:	8b f3                	mov    esi,ebx
  70d53e:	e8 cd f6 ff ff       	call   0x70cc10
  70d543:	8a 54 24 13          	mov    dl,BYTE PTR [esp+0x13]
  70d547:	8d 44 24 13          	lea    eax,[esp+0x13]
  70d54b:	88 57 49             	mov    BYTE PTR [edi+0x49],dl
  70d54e:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  70d551:	6a 01                	push   0x1
  70d553:	50                   	push   eax
  70d554:	e8 37 19 ff ff       	call   0x6fee90
  70d559:	83 c4 08             	add    esp,0x8
  70d55c:	85 c0                	test   eax,eax
  70d55e:	74 0c                	je     0x70d56c
  70d560:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70d565:	8b f3                	mov    esi,ebx
  70d567:	e8 a4 f6 ff ff       	call   0x70cc10
  70d56c:	8a 4c 24 13          	mov    cl,BYTE PTR [esp+0x13]
  70d570:	8d 54 24 13          	lea    edx,[esp+0x13]
  70d574:	88 4f 4a             	mov    BYTE PTR [edi+0x4a],cl
  70d577:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  70d57a:	6a 01                	push   0x1
  70d57c:	52                   	push   edx
  70d57d:	e8 0e 19 ff ff       	call   0x6fee90
  70d582:	83 c4 08             	add    esp,0x8
  70d585:	85 c0                	test   eax,eax
  70d587:	74 0c                	je     0x70d595
  70d589:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70d58e:	8b f3                	mov    esi,ebx
  70d590:	e8 7b f6 ff ff       	call   0x70cc10
  70d595:	8a 44 24 13          	mov    al,BYTE PTR [esp+0x13]
  70d599:	57                   	push   edi
  70d59a:	53                   	push   ebx
  70d59b:	88 47 4b             	mov    BYTE PTR [edi+0x4b],al
  70d59e:	e8 1d f7 ff ff       	call   0x70ccc0
  70d5a3:	57                   	push   edi
  70d5a4:	53                   	push   ebx
  70d5a5:	e8 f6 f7 ff ff       	call   0x70cda0
  70d5aa:	53                   	push   ebx
  70d5ab:	e8 c0 fa ff ff       	call   0x70d070
  70d5b0:	8b 4f 2c             	mov    ecx,DWORD PTR [edi+0x2c]
  70d5b3:	83 c4 14             	add    esp,0x14
  70d5b6:	68 ff 00 00 00       	push   0xff
  70d5bb:	51                   	push   ecx
  70d5bc:	57                   	push   edi
  70d5bd:	e8 0e ad fe ff       	call   0x6f82d0
  70d5c2:	83 c4 0c             	add    esp,0xc
  70d5c5:	85 c0                	test   eax,eax
  70d5c7:	75 0c                	jne    0x70d5d5
  70d5c9:	b8 68 3e c4 00       	mov    eax,0xc43e68
  70d5ce:	8b f3                	mov    esi,ebx
  70d5d0:	e8 3b f6 ff ff       	call   0x70cc10
  70d5d5:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  70d5d7:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  70d5db:	8b c7                	mov    eax,edi
  70d5dd:	5f                   	pop    edi
  70d5de:	5e                   	pop    esi
  70d5df:	5b                   	pop    ebx
  70d5e0:	8b e5                	mov    esp,ebp
  70d5e2:	5d                   	pop    ebp
  70d5e3:	c3                   	ret

# binary_error_status_and_string_intern VA=0x0070CC10 raw=0x0030C010 size=169 sha256=bfbb2bc3c73cd2f9c4a5c823122f878a0662552a7a8dbc692b5af65ff816a72b

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070cc10 <.text+0x30bc10>:
  70cc10:	51                   	push   ecx
  70cc11:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  70cc14:	8b 16                	mov    edx,DWORD PTR [esi]
  70cc16:	50                   	push   eax
  70cc17:	51                   	push   ecx
  70cc18:	68 20 3e c4 00       	push   0xc43e20
  70cc1d:	52                   	push   edx
  70cc1e:	e8 0d b0 fe ff       	call   0x6f7c30
  70cc23:	8b 06                	mov    eax,DWORD PTR [esi]
  70cc25:	83 c4 10             	add    esp,0x10
  70cc28:	6a 03                	push   0x3
  70cc2a:	50                   	push   eax
  70cc2b:	e8 10 0f ff ff       	call   0x6fdb40
  70cc30:	cc                   	int3
  70cc31:	cc                   	int3
  70cc32:	cc                   	int3
  70cc33:	cc                   	int3
  70cc34:	cc                   	int3
  70cc35:	cc                   	int3
  70cc36:	cc                   	int3
  70cc37:	cc                   	int3
  70cc38:	cc                   	int3
  70cc39:	cc                   	int3
  70cc3a:	cc                   	int3
  70cc3b:	cc                   	int3
  70cc3c:	cc                   	int3
  70cc3d:	cc                   	int3
  70cc3e:	cc                   	int3
  70cc3f:	cc                   	int3
  70cc40:	55                   	push   ebp
  70cc41:	8b ec                	mov    ebp,esp
  70cc43:	53                   	push   ebx
  70cc44:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  70cc47:	56                   	push   esi
  70cc48:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  70cc4b:	57                   	push   edi
  70cc4c:	8d 45 08             	lea    eax,[ebp+0x8]
  70cc4f:	6a 04                	push   0x4
  70cc51:	50                   	push   eax
  70cc52:	e8 39 22 ff ff       	call   0x6fee90
  70cc57:	83 c4 08             	add    esp,0x8
  70cc5a:	85 c0                	test   eax,eax
  70cc5c:	74 0c                	je     0x70cc6a
  70cc5e:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70cc63:	8b f3                	mov    esi,ebx
  70cc65:	e8 a6 ff ff ff       	call   0x70cc10
  70cc6a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70cc6d:	85 f6                	test   esi,esi
  70cc6f:	75 07                	jne    0x70cc78
  70cc71:	33 c0                	xor    eax,eax
  70cc73:	5f                   	pop    edi
  70cc74:	5e                   	pop    esi
  70cc75:	5b                   	pop    ebx
  70cc76:	5d                   	pop    ebp
  70cc77:	c3                   	ret
  70cc78:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  70cc7b:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  70cc7d:	8b c6                	mov    eax,esi
  70cc7f:	e8 9c 22 ff ff       	call   0x6fef20
  70cc84:	8b f8                	mov    edi,eax
  70cc86:	56                   	push   esi
  70cc87:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  70cc8a:	57                   	push   edi
  70cc8b:	e8 00 22 ff ff       	call   0x6fee90
  70cc90:	83 c4 08             	add    esp,0x8
  70cc93:	85 c0                	test   eax,eax
  70cc95:	74 0c                	je     0x70cca3
  70cc97:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70cc9c:	8b f3                	mov    esi,ebx
  70cc9e:	e8 6d ff ff ff       	call   0x70cc10
  70cca3:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  70cca6:	8b 13                	mov    edx,DWORD PTR [ebx]
  70cca8:	49                   	dec    ecx
  70cca9:	51                   	push   ecx
  70ccaa:	57                   	push   edi
  70ccab:	52                   	push   edx
  70ccac:	e8 bf 1f ff ff       	call   0x6fec70
  70ccb1:	83 c4 0c             	add    esp,0xc
  70ccb4:	5f                   	pop    edi
  70ccb5:	5e                   	pop    esi
  70ccb6:	5b                   	pop    ebx
  70ccb7:	5d                   	pop    ebp
  70ccb8:	c3                   	ret

# binary_code_new_allocation_and_copy VA=0x0070CCC0 raw=0x0030C0C0 size=212 sha256=e3b7509a175bcbefa16464266bf700eb68920a65823db1084b98c1b56ca19066

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070ccc0 <.text+0x30bcc0>:
  70ccc0:	55                   	push   ebp
  70ccc1:	8b ec                	mov    ebp,esp
  70ccc3:	83 e4 f8             	and    esp,0xfffffff8
  70ccc6:	83 ec 0c             	sub    esp,0xc
  70ccc9:	53                   	push   ebx
  70ccca:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  70cccd:	56                   	push   esi
  70ccce:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  70ccd1:	57                   	push   edi
  70ccd2:	8d 44 24 10          	lea    eax,[esp+0x10]
  70ccd6:	6a 04                	push   0x4
  70ccd8:	50                   	push   eax
  70ccd9:	e8 b2 21 ff ff       	call   0x6fee90
  70ccde:	83 c4 08             	add    esp,0x8
  70cce1:	85 c0                	test   eax,eax
  70cce3:	74 0c                	je     0x70ccf1
  70cce5:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70ccea:	8b f3                	mov    esi,ebx
  70ccec:	e8 1f ff ff ff       	call   0x70cc10
  70ccf1:	8b 74 24 10          	mov    esi,DWORD PTR [esp+0x10]
  70ccf5:	85 f6                	test   esi,esi
  70ccf7:	79 0c                	jns    0x70cd05
  70ccf9:	b8 4c 3e c4 00       	mov    eax,0xc43e4c
  70ccfe:	8b f3                	mov    esi,ebx
  70cd00:	e8 0b ff ff ff       	call   0x70cc10
  70cd05:	8d 4e 01             	lea    ecx,[esi+0x1]
  70cd08:	81 f9 ff ff ff 3f    	cmp    ecx,0x3fffffff
  70cd0e:	77 3e                	ja     0x70cd4e
  70cd10:	8b 03                	mov    eax,DWORD PTR [ebx]
  70cd12:	8d 3c b5 00 00 00 00 	lea    edi,[esi*4+0x0]
  70cd19:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  70cd1c:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  70cd1f:	57                   	push   edi
  70cd20:	6a 00                	push   0x0
  70cd22:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  70cd26:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  70cd29:	6a 00                	push   0x0
  70cd2b:	52                   	push   edx
  70cd2c:	ff d0                	call   eax
  70cd2e:	83 c4 10             	add    esp,0x10
  70cd31:	85 c0                	test   eax,eax
  70cd33:	75 10                	jne    0x70cd45
  70cd35:	85 ff                	test   edi,edi
  70cd37:	74 0c                	je     0x70cd45
  70cd39:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  70cd3d:	6a 04                	push   0x4
  70cd3f:	51                   	push   ecx
  70cd40:	e8 fb 0d ff ff       	call   0x6fdb40
  70cd45:	01 7e 44             	add    DWORD PTR [esi+0x44],edi
  70cd48:	8b 74 24 10          	mov    esi,DWORD PTR [esp+0x10]
  70cd4c:	eb 12                	jmp    0x70cd60
  70cd4e:	8b 13                	mov    edx,DWORD PTR [ebx]
  70cd50:	68 0c 2e c4 00       	push   0xc42e0c
  70cd55:	52                   	push   edx
  70cd56:	e8 05 be fe ff       	call   0x6f8b60
  70cd5b:	83 c4 08             	add    esp,0x8
  70cd5e:	33 c0                	xor    eax,eax
  70cd60:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  70cd63:	89 41 0c             	mov    DWORD PTR [ecx+0xc],eax
  70cd66:	89 71 2c             	mov    DWORD PTR [ecx+0x2c],esi
  70cd69:	8d 0c b5 00 00 00 00 	lea    ecx,[esi*4+0x0]
  70cd70:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  70cd73:	51                   	push   ecx
  70cd74:	50                   	push   eax
  70cd75:	e8 16 21 ff ff       	call   0x6fee90
  70cd7a:	83 c4 08             	add    esp,0x8
  70cd7d:	85 c0                	test   eax,eax
  70cd7f:	74 0c                	je     0x70cd8d
  70cd81:	b8 3c 3e c4 00       	mov    eax,0xc43e3c
  70cd86:	8b f3                	mov    esi,ebx
  70cd88:	e8 83 fe ff ff       	call   0x70cc10
  70cd8d:	5f                   	pop    edi
  70cd8e:	5e                   	pop    esi
  70cd8f:	5b                   	pop    ebx
  70cd90:	8b e5                	mov    esp,ebp
  70cd92:	5d                   	pop    ebp
  70cd93:	c3                   	ret

# text_parser_chunk_and_eof VA=0x0070E420 raw=0x0030D820 size=282 sha256=026258b36bc61c2444b9f3a3e2ccbd851c3fbc7ce64fd615fb18487f3f32bd10

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0070e420 <.text+0x30d420>:
  70e420:	55                   	push   ebp
  70e421:	8b ec                	mov    ebp,esp
  70e423:	83 e4 f8             	and    esp,0xfffffff8
  70e426:	81 ec 90 02 00 00    	sub    esp,0x290
  70e42c:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  70e431:	33 c4                	xor    eax,esp
  70e433:	89 84 24 8c 02 00 00 	mov    DWORD PTR [esp+0x28c],eax
  70e43a:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  70e43d:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  70e440:	56                   	push   esi
  70e441:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70e444:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  70e448:	8b c1                	mov    eax,ecx
  70e44a:	57                   	push   edi
  70e44b:	8d 78 01             	lea    edi,[eax+0x1]
  70e44e:	8b ff                	mov    edi,edi
  70e450:	8a 10                	mov    dl,BYTE PTR [eax]
  70e452:	40                   	inc    eax
  70e453:	84 d2                	test   dl,dl
  70e455:	75 f9                	jne    0x70e450
  70e457:	2b c7                	sub    eax,edi
  70e459:	50                   	push   eax
  70e45a:	51                   	push   ecx
  70e45b:	56                   	push   esi
  70e45c:	e8 0f 08 ff ff       	call   0x6fec70
  70e461:	83 c4 0c             	add    esp,0xc
  70e464:	56                   	push   esi
  70e465:	8b d0                	mov    edx,eax
  70e467:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  70e46a:	8d 74 24 0c          	lea    esi,[esp+0xc]
  70e46e:	e8 4d 0e ff ff       	call   0x6ff2c0
  70e473:	8b c6                	mov    eax,esi
  70e475:	83 c4 04             	add    esp,0x4
  70e478:	50                   	push   eax
  70e479:	8d 44 24 54          	lea    eax,[esp+0x54]
  70e47d:	e8 2e fb ff ff       	call   0x70dfb0
  70e482:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  70e486:	c6 41 4a 02          	mov    BYTE PTR [ecx+0x4a],0x2
  70e48a:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  70e48e:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  70e492:	be 1f 01 00 00       	mov    esi,0x11f
  70e497:	83 c4 04             	add    esp,0x4
  70e49a:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  70e49e:	3b c6                	cmp    eax,esi
  70e4a0:	74 22                	je     0x70e4c4
  70e4a2:	8b 4c 24 30          	mov    ecx,DWORD PTR [esp+0x30]
  70e4a6:	8b 54 24 34          	mov    edx,DWORD PTR [esp+0x34]
  70e4aa:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  70e4ae:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  70e4b2:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  70e4b6:	89 4c 24 20          	mov    DWORD PTR [esp+0x20],ecx
  70e4ba:	89 54 24 24          	mov    DWORD PTR [esp+0x24],edx
  70e4be:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  70e4c2:	eb 15                	jmp    0x70e4d9
  70e4c4:	8d 44 24 20          	lea    eax,[esp+0x20]
  70e4c8:	50                   	push   eax
  70e4c9:	8d 44 24 0c          	lea    eax,[esp+0xc]
  70e4cd:	e8 ee 19 ff ff       	call   0x6ffec0
  70e4d2:	83 c4 04             	add    esp,0x4
  70e4d5:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  70e4d9:	8d 4c 24 08          	lea    ecx,[esp+0x8]
  70e4dd:	51                   	push   ecx
  70e4de:	e8 3d 36 00 00       	call   0x711b20
  70e4e3:	83 c4 04             	add    esp,0x4
  70e4e6:	39 74 24 18          	cmp    DWORD PTR [esp+0x18],esi
  70e4ea:	74 29                	je     0x70e515
  70e4ec:	8b 15 38 bf c0 00    	mov    edx,DWORD PTR ds:0xc0bf38
  70e4f2:	8b 44 24 3c          	mov    eax,DWORD PTR [esp+0x3c]
  70e4f6:	52                   	push   edx
  70e4f7:	68 94 3e c4 00       	push   0xc43e94
  70e4fc:	50                   	push   eax
  70e4fd:	e8 2e 97 fe ff       	call   0x6f7c30
  70e502:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  70e506:	83 c4 0c             	add    esp,0xc
  70e509:	51                   	push   ecx
  70e50a:	50                   	push   eax
  70e50b:	8d 54 24 10          	lea    edx,[esp+0x10]
  70e50f:	52                   	push   edx
  70e510:	e8 1b 0c ff ff       	call   0x6ff130
  70e515:	8d 44 24 08          	lea    eax,[esp+0x8]
  70e519:	50                   	push   eax
  70e51a:	e8 f1 fb ff ff       	call   0x70e110
  70e51f:	8b 8c 24 98 02 00 00 	mov    ecx,DWORD PTR [esp+0x298]
  70e526:	8b 44 24 54          	mov    eax,DWORD PTR [esp+0x54]
  70e52a:	83 c4 04             	add    esp,0x4
  70e52d:	5f                   	pop    edi
  70e52e:	5e                   	pop    esi
  70e52f:	33 cc                	xor    ecx,esp
  70e531:	e8 cb 2a 18 00       	call   0x891001
  70e536:	8b e5                	mov    esp,ebp
  70e538:	5d                   	pop    ebp
  70e539:	c3                   	ret

# text_lexer_state_setup VA=0x006FF2C0 raw=0x002FE6C0 size=119 sha256=37b28b4d5bf7a193ee8add2a7059fa526979bbc07f530e8b34c616f137770c46

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006ff2c0 <.text+0x2fe2c0>:
  6ff2c0:	55                   	push   ebp
  6ff2c1:	8b ec                	mov    ebp,esp
  6ff2c3:	83 e4 f8             	and    esp,0xfffffff8
  6ff2c6:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  6ff2c9:	89 46 38             	mov    DWORD PTR [esi+0x38],eax
  6ff2cc:	83 ec 08             	sub    esp,0x8
  6ff2cf:	53                   	push   ebx
  6ff2d0:	b8 01 00 00 00       	mov    eax,0x1
  6ff2d5:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  6ff2d8:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  6ff2db:	8b 46 3c             	mov    eax,DWORD PTR [esi+0x3c]
  6ff2de:	57                   	push   edi
  6ff2df:	c6 46 44 2e          	mov    BYTE PTR [esi+0x44],0x2e
  6ff2e3:	89 4e 34             	mov    DWORD PTR [esi+0x34],ecx
  6ff2e6:	c7 46 20 1f 01 00 00 	mov    DWORD PTR [esi+0x20],0x11f
  6ff2ed:	c7 46 30 00 00 00 00 	mov    DWORD PTR [esi+0x30],0x0
  6ff2f4:	89 56 40             	mov    DWORD PTR [esi+0x40],edx
  6ff2f7:	8b 58 08             	mov    ebx,DWORD PTR [eax+0x8]
  6ff2fa:	8b 00                	mov    eax,DWORD PTR [eax]
  6ff2fc:	8b 79 10             	mov    edi,DWORD PTR [ecx+0x10]
  6ff2ff:	8b 4f 0c             	mov    ecx,DWORD PTR [edi+0xc]
  6ff302:	6a 20                	push   0x20
  6ff304:	53                   	push   ebx
  6ff305:	50                   	push   eax
  6ff306:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  6ff309:	50                   	push   eax
  6ff30a:	ff d1                	call   ecx
  6ff30c:	83 c4 10             	add    esp,0x10
  6ff30f:	85 c0                	test   eax,eax
  6ff311:	75 0b                	jne    0x6ff31e
  6ff313:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  6ff316:	6a 04                	push   0x4
  6ff318:	52                   	push   edx
  6ff319:	e8 22 e8 ff ff       	call   0x6fdb40
  6ff31e:	b9 20 00 00 00       	mov    ecx,0x20
  6ff323:	2b cb                	sub    ecx,ebx
  6ff325:	01 4f 44             	add    DWORD PTR [edi+0x44],ecx
  6ff328:	8b 56 3c             	mov    edx,DWORD PTR [esi+0x3c]
  6ff32b:	89 02                	mov    DWORD PTR [edx],eax
  6ff32d:	8b 46 3c             	mov    eax,DWORD PTR [esi+0x3c]
  6ff330:	c7 40 08 20 00 00 00 	mov    DWORD PTR [eax+0x8],0x20

# execution_thunk_not_error_handler VA=0x006F5A50 raw=0x002F4E50 size=28 sha256=e812e1114f4e61da1243d3a6968143c5b44711cca81189f1c78d61d85a68ad36

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f5a50 <.text+0x2f4a50>:
  6f5a50:	55                   	push   ebp
  6f5a51:	8b ec                	mov    ebp,esp
  6f5a53:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6f5a56:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  6f5a59:	8b 10                	mov    edx,DWORD PTR [eax]
  6f5a5b:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f5a5e:	51                   	push   ecx
  6f5a5f:	52                   	push   edx
  6f5a60:	50                   	push   eax
  6f5a61:	e8 ea 8a 00 00       	call   0x6fe550
  6f5a66:	83 c4 0c             	add    esp,0xc
  6f5a69:	5d                   	pop    ebp
  6f5a6a:	c3                   	ret
  6f5a6b:	cc                   	int3

# protected_call_restore_on_error VA=0x006FE770 raw=0x002FDB70 size=240 sha256=cd70a17ed26b8db52f2c53110aca4c5ca41405dab04dd8fc2ac84b0becf17ccf

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe770 <.text+0x2fd770>:
  6fe770:	55                   	push   ebp
  6fe771:	8b ec                	mov    ebp,esp
  6fe773:	83 ec 18             	sub    esp,0x18
  6fe776:	53                   	push   ebx
  6fe777:	56                   	push   esi
  6fe778:	8b f0                	mov    esi,eax
  6fe77a:	0f b7 46 34          	movzx  eax,WORD PTR [esi+0x34]
  6fe77e:	8a 4e 39             	mov    cl,BYTE PTR [esi+0x39]
  6fe781:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  6fe784:	8b 46 14             	mov    eax,DWORD PTR [esi+0x14]
  6fe787:	2b 46 28             	sub    eax,DWORD PTR [esi+0x28]
  6fe78a:	57                   	push   edi
  6fe78b:	8b 7e 74             	mov    edi,DWORD PTR [esi+0x74]
  6fe78e:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  6fe791:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6fe794:	88 4d ff             	mov    BYTE PTR [ebp-0x1],cl
  6fe797:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  6fe79a:	50                   	push   eax
  6fe79b:	51                   	push   ecx
  6fe79c:	56                   	push   esi
  6fe79d:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  6fe7a0:	89 56 74             	mov    DWORD PTR [esi+0x74],edx
  6fe7a3:	e8 f8 f3 ff ff       	call   0x6fdba0
  6fe7a8:	83 c4 0c             	add    esp,0xc
  6fe7ab:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  6fe7ae:	85 c0                	test   eax,eax
  6fe7b0:	0f 84 98 00 00 00    	je     0x6fe84e
  6fe7b6:	8b 5e 20             	mov    ebx,DWORD PTR [esi+0x20]
  6fe7b9:	03 5d 10             	add    ebx,DWORD PTR [ebp+0x10]
  6fe7bc:	8b fe                	mov    edi,esi
  6fe7be:	53                   	push   ebx
  6fe7bf:	e8 9c f0 ff ff       	call   0x6fd860
  6fe7c4:	8b cb                	mov    ecx,ebx
  6fe7c6:	8b 5d f4             	mov    ebx,DWORD PTR [ebp-0xc]
  6fe7c9:	83 c4 04             	add    esp,0x4
  6fe7cc:	8b c3                	mov    eax,ebx
  6fe7ce:	e8 8d f2 ff ff       	call   0x6fda60
  6fe7d3:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  6fe7d6:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  6fe7d9:	66 8b 55 f0          	mov    dx,WORD PTR [ebp-0x10]
  6fe7dd:	03 c1                	add    eax,ecx
  6fe7df:	66 89 56 34          	mov    WORD PTR [esi+0x34],dx
  6fe7e3:	89 46 14             	mov    DWORD PTR [esi+0x14],eax
  6fe7e6:	8b 10                	mov    edx,DWORD PTR [eax]
  6fe7e8:	89 56 0c             	mov    DWORD PTR [esi+0xc],edx
  6fe7eb:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  6fe7ee:	89 56 18             	mov    DWORD PTR [esi+0x18],edx
  6fe7f1:	8a 55 ff             	mov    dl,BYTE PTR [ebp-0x1]
  6fe7f4:	bf 20 4e 00 00       	mov    edi,0x4e20
  6fe7f9:	88 56 39             	mov    BYTE PTR [esi+0x39],dl
  6fe7fc:	39 7e 30             	cmp    DWORD PTR [esi+0x30],edi
  6fe7ff:	7e 3e                	jle    0x6fe83f
  6fe801:	2b c1                	sub    eax,ecx
  6fe803:	8b c8                	mov    ecx,eax
  6fe805:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  6fe80a:	f7 e9                	imul   ecx
  6fe80c:	c1 fa 02             	sar    edx,0x2
  6fe80f:	8b c2                	mov    eax,edx
  6fe811:	c1 e8 1f             	shr    eax,0x1f
  6fe814:	8d 4c 02 01          	lea    ecx,[edx+eax*1+0x1]
  6fe818:	3b cf                	cmp    ecx,edi
  6fe81a:	7d 14                	jge    0x6fe830
  6fe81c:	e8 ef f4 ff ff       	call   0x6fdd10
  6fe821:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  6fe824:	89 56 74             	mov    DWORD PTR [esi+0x74],edx
  6fe827:	8b c3                	mov    eax,ebx
  6fe829:	5f                   	pop    edi
  6fe82a:	5e                   	pop    esi
  6fe82b:	5b                   	pop    ebx
  6fe82c:	8b e5                	mov    esp,ebp
  6fe82e:	5d                   	pop    ebp
  6fe82f:	c3                   	ret
  6fe830:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  6fe833:	89 46 74             	mov    DWORD PTR [esi+0x74],eax
  6fe836:	8b c3                	mov    eax,ebx
  6fe838:	5f                   	pop    edi
  6fe839:	5e                   	pop    esi
  6fe83a:	5b                   	pop    ebx
  6fe83b:	8b e5                	mov    esp,ebp
  6fe83d:	5d                   	pop    ebp
  6fe83e:	c3                   	ret
  6fe83f:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  6fe842:	89 4e 74             	mov    DWORD PTR [esi+0x74],ecx
  6fe845:	8b c3                	mov    eax,ebx
  6fe847:	5f                   	pop    edi
  6fe848:	5e                   	pop    esi
  6fe849:	5b                   	pop    ebx
  6fe84a:	8b e5                	mov    esp,ebp
  6fe84c:	5d                   	pop    ebp
  6fe84d:	c3                   	ret
  6fe84e:	89 7e 74             	mov    DWORD PTR [esi+0x74],edi
  6fe851:	5f                   	pop    edi
  6fe852:	5e                   	pop    esi
  6fe853:	5b                   	pop    ebx
  6fe854:	8b e5                	mov    esp,ebp
  6fe856:	5d                   	pop    ebp
  6fe857:	c3                   	ret
  6fe858:	cc                   	int3
  6fe859:	cc                   	int3
  6fe85a:	cc                   	int3
  6fe85b:	cc                   	int3
  6fe85c:	cc                   	int3
  6fe85d:	cc                   	int3
  6fe85e:	cc                   	int3
  6fe85f:	cc                   	int3

# setjmp_guard_indirect_callback VA=0x006FDBA0 raw=0x002FCFA0 size=137 sha256=cc78030fd4791c892bf458c32b7449422b6b148779aa7acd70917910f0546520

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fdba0 <.text+0x2fcba0>:
  6fdba0:	55                   	push   ebp
  6fdba1:	8b ec                	mov    ebp,esp
  6fdba3:	83 ec 60             	sub    esp,0x60
  6fdba6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6fdbab:	33 c5                	xor    eax,ebp
  6fdbad:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  6fdbb0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6fdbb3:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  6fdbb6:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  6fdbb9:	89 45 a8             	mov    DWORD PTR [ebp-0x58],eax
  6fdbbc:	89 4d a0             	mov    DWORD PTR [ebp-0x60],ecx
  6fdbbf:	89 55 a4             	mov    DWORD PTR [ebp-0x5c],edx
  6fdbc2:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  6fdbc9:	8b 48 70             	mov    ecx,DWORD PTR [eax+0x70]
  6fdbcc:	8d 55 ac             	lea    edx,[ebp-0x54]
  6fdbcf:	56                   	push   esi
  6fdbd0:	89 4d ac             	mov    DWORD PTR [ebp-0x54],ecx
  6fdbd3:	89 50 70             	mov    DWORD PTR [eax+0x70],edx
  6fdbd6:	8d 45 b0             	lea    eax,[ebp-0x50]
  6fdbd9:	6a 00                	push   0x0
  6fdbdb:	50                   	push   eax
  6fdbdc:	e8 6f f1 1f 00       	call   0x8fcd50
  6fdbe1:	83 c4 08             	add    esp,0x8
  6fdbe4:	85 c0                	test   eax,eax
  6fdbe6:	75 26                	jne    0x6fdc0e
  6fdbe8:	8b 4d a4             	mov    ecx,DWORD PTR [ebp-0x5c]
  6fdbeb:	8b 75 a8             	mov    esi,DWORD PTR [ebp-0x58]
  6fdbee:	51                   	push   ecx
  6fdbef:	56                   	push   esi
  6fdbf0:	ff 55 a0             	call   DWORD PTR [ebp-0x60]
  6fdbf3:	8b 55 ac             	mov    edx,DWORD PTR [ebp-0x54]
  6fdbf6:	89 56 70             	mov    DWORD PTR [esi+0x70],edx
  6fdbf9:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  6fdbfc:	83 c4 08             	add    esp,0x8
  6fdbff:	5e                   	pop    esi
  6fdc00:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  6fdc03:	33 cd                	xor    ecx,ebp
  6fdc05:	e8 f7 33 19 00       	call   0x891001
  6fdc0a:	8b e5                	mov    esp,ebp
  6fdc0c:	5d                   	pop    ebp
  6fdc0d:	c3                   	ret
  6fdc0e:	8b 45 ac             	mov    eax,DWORD PTR [ebp-0x54]
  6fdc11:	8b 4d a8             	mov    ecx,DWORD PTR [ebp-0x58]
  6fdc14:	89 41 70             	mov    DWORD PTR [ecx+0x70],eax
  6fdc17:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  6fdc1a:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  6fdc1d:	33 cd                	xor    ecx,ebp
  6fdc1f:	5e                   	pop    esi
  6fdc20:	e8 dc 33 19 00       	call   0x891001
  6fdc25:	8b e5                	mov    esp,ebp
  6fdc27:	5d                   	pop    ebp
  6fdc28:	c3                   	ret

# call_engine_then_VM VA=0x006FE550 raw=0x002FD950 size=135 sha256=6e2e02924cb311e46127d7ea60d60a575b56905de3b08c39b34aa5dc5ee7e062

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe550 <.text+0x2fd550>:
  6fe550:	55                   	push   ebp
  6fe551:	8b ec                	mov    ebp,esp
  6fe553:	83 e4 f8             	and    esp,0xfffffff8
  6fe556:	51                   	push   ecx
  6fe557:	56                   	push   esi
  6fe558:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6fe55b:	66 ff 46 34          	inc    WORD PTR [esi+0x34]
  6fe55f:	66 8b 46 34          	mov    ax,WORD PTR [esi+0x34]
  6fe563:	b9 c8 00 00 00       	mov    ecx,0xc8
  6fe568:	66 3b c1             	cmp    ax,cx
  6fe56b:	72 29                	jb     0x6fe596
  6fe56d:	8b d1                	mov    edx,ecx
  6fe56f:	66 3b c2             	cmp    ax,dx
  6fe572:	75 0d                	jne    0x6fe581
  6fe574:	68 04 2b c4 00       	push   0xc42b04
  6fe579:	56                   	push   esi
  6fe57a:	e8 e1 a5 ff ff       	call   0x6f8b60
  6fe57f:	eb 12                	jmp    0x6fe593
  6fe581:	b9 e1 00 00 00       	mov    ecx,0xe1
  6fe586:	66 3b c1             	cmp    ax,cx
  6fe589:	72 0b                	jb     0x6fe596
  6fe58b:	6a 05                	push   0x5
  6fe58d:	56                   	push   esi
  6fe58e:	e8 ad f5 ff ff       	call   0x6fdb40
  6fe593:	83 c4 08             	add    esp,0x8
  6fe596:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  6fe599:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6fe59c:	52                   	push   edx
  6fe59d:	8b ce                	mov    ecx,esi
  6fe59f:	e8 1c fc ff ff       	call   0x6fe1c0
  6fe5a4:	83 c4 04             	add    esp,0x4
  6fe5a7:	85 c0                	test   eax,eax
  6fe5a9:	75 0b                	jne    0x6fe5b6
  6fe5ab:	6a 01                	push   0x1
  6fe5ad:	56                   	push   esi
  6fe5ae:	e8 9d df ff ff       	call   0x6fc550
  6fe5b3:	83 c4 08             	add    esp,0x8
  6fe5b6:	b8 ff ff 00 00       	mov    eax,0xffff
  6fe5bb:	66 01 46 34          	add    WORD PTR [esi+0x34],ax
  6fe5bf:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  6fe5c2:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  6fe5c5:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  6fe5c8:	72 07                	jb     0x6fe5d1
  6fe5ca:	8b c6                	mov    eax,esi
  6fe5cc:	e8 cf cd ff ff       	call   0x6fb3a0
  6fe5d1:	5e                   	pop    esi
  6fe5d2:	8b e5                	mov    esp,ebp
  6fe5d4:	5d                   	pop    ebp
  6fe5d5:	c3                   	ret
  6fe5d6:	cc                   	int3

# Lua_vs_registered_C_closure_call VA=0x006FE1C0 raw=0x002FD5C0 size=468 sha256=cdc97c3e9ef59235e8072416e3f980d7a418db3239539c2704e8a5e821692ec7

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe1c0 <.text+0x2fd1c0>:
  6fe1c0:	55                   	push   ebp
  6fe1c1:	8b ec                	mov    ebp,esp
  6fe1c3:	83 ec 08             	sub    esp,0x8
  6fe1c6:	83 78 08 06          	cmp    DWORD PTR [eax+0x8],0x6
  6fe1ca:	53                   	push   ebx
  6fe1cb:	56                   	push   esi
  6fe1cc:	57                   	push   edi
  6fe1cd:	8b f1                	mov    esi,ecx
  6fe1cf:	74 0b                	je     0x6fe1dc
  6fe1d1:	50                   	push   eax
  6fe1d2:	8b fe                	mov    edi,esi
  6fe1d4:	e8 07 ff ff ff       	call   0x6fe0e0
  6fe1d9:	83 c4 04             	add    esp,0x4
  6fe1dc:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6fe1df:	8b 56 18             	mov    edx,DWORD PTR [esi+0x18]
  6fe1e2:	8b d8                	mov    ebx,eax
  6fe1e4:	2b 5e 20             	sub    ebx,DWORD PTR [esi+0x20]
  6fe1e7:	8b 00                	mov    eax,DWORD PTR [eax]
  6fe1e9:	89 51 0c             	mov    DWORD PTR [ecx+0xc],edx
  6fe1ec:	80 78 06 00          	cmp    BYTE PTR [eax+0x6],0x0
  6fe1f0:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  6fe1f3:	0f 85 ed 00 00 00    	jne    0x6fe2e6
  6fe1f9:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  6fe1fc:	0f b6 41 4b          	movzx  eax,BYTE PTR [ecx+0x4b]
  6fe200:	8b 56 1c             	mov    edx,DWORD PTR [esi+0x1c]
  6fe203:	2b 56 08             	sub    edx,DWORD PTR [esi+0x8]
  6fe206:	8b f8                	mov    edi,eax
  6fe208:	c1 e7 04             	shl    edi,0x4
  6fe20b:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  6fe20e:	3b d7                	cmp    edx,edi
  6fe210:	7f 16                	jg     0x6fe228
  6fe212:	8b 4e 2c             	mov    ecx,DWORD PTR [esi+0x2c]
  6fe215:	3b c1                	cmp    eax,ecx
  6fe217:	7f 05                	jg     0x6fe21e
  6fe219:	8d 04 09             	lea    eax,[ecx+ecx*1]
  6fe21c:	eb 02                	jmp    0x6fe220
  6fe21e:	03 c1                	add    eax,ecx
  6fe220:	e8 8b fa ff ff       	call   0x6fdcb0
  6fe225:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6fe228:	8b 7e 20             	mov    edi,DWORD PTR [esi+0x20]
  6fe22b:	03 fb                	add    edi,ebx
  6fe22d:	80 79 4a 00          	cmp    BYTE PTR [ecx+0x4a],0x0
  6fe231:	75 16                	jne    0x6fe249
  6fe233:	0f b6 41 49          	movzx  eax,BYTE PTR [ecx+0x49]
  6fe237:	c1 e0 04             	shl    eax,0x4
  6fe23a:	8d 5f 10             	lea    ebx,[edi+0x10]
  6fe23d:	03 c3                	add    eax,ebx
  6fe23f:	39 46 08             	cmp    DWORD PTR [esi+0x8],eax
  6fe242:	76 25                	jbe    0x6fe269
  6fe244:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  6fe247:	eb 20                	jmp    0x6fe269
  6fe249:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6fe24c:	2b c7                	sub    eax,edi
  6fe24e:	c1 f8 04             	sar    eax,0x4
  6fe251:	48                   	dec    eax
  6fe252:	50                   	push   eax
  6fe253:	56                   	push   esi
  6fe254:	8b c1                	mov    eax,ecx
  6fe256:	e8 65 fc ff ff       	call   0x6fdec0
  6fe25b:	8b 7e 20             	mov    edi,DWORD PTR [esi+0x20]
  6fe25e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6fe261:	83 c4 08             	add    esp,0x8
  6fe264:	03 7d f8             	add    edi,DWORD PTR [ebp-0x8]
  6fe267:	8b d8                	mov    ebx,eax
  6fe269:	8b 46 14             	mov    eax,DWORD PTR [esi+0x14]
  6fe26c:	3b 46 24             	cmp    eax,DWORD PTR [esi+0x24]
  6fe26f:	75 0c                	jne    0x6fe27d
  6fe271:	8b c6                	mov    eax,esi
  6fe273:	e8 18 fb ff ff       	call   0x6fdd90
  6fe278:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6fe27b:	eb 06                	jmp    0x6fe283
  6fe27d:	83 c0 18             	add    eax,0x18
  6fe280:	89 46 14             	mov    DWORD PTR [esi+0x14],eax
  6fe283:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  6fe286:	89 18                	mov    DWORD PTR [eax],ebx
  6fe288:	89 5e 0c             	mov    DWORD PTR [esi+0xc],ebx
  6fe28b:	0f b6 51 4b          	movzx  edx,BYTE PTR [ecx+0x4b]
  6fe28f:	c1 e2 04             	shl    edx,0x4
  6fe292:	03 d3                	add    edx,ebx
  6fe294:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  6fe297:	8b 49 0c             	mov    ecx,DWORD PTR [ecx+0xc]
  6fe29a:	89 4e 18             	mov    DWORD PTR [esi+0x18],ecx
  6fe29d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  6fe2a0:	33 d2                	xor    edx,edx
  6fe2a2:	89 50 14             	mov    DWORD PTR [eax+0x14],edx
  6fe2a5:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  6fe2a8:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6fe2ab:	3b 48 08             	cmp    ecx,DWORD PTR [eax+0x8]
  6fe2ae:	73 0b                	jae    0x6fe2bb
  6fe2b0:	89 51 08             	mov    DWORD PTR [ecx+0x8],edx
  6fe2b3:	83 c1 10             	add    ecx,0x10
  6fe2b6:	3b 48 08             	cmp    ecx,DWORD PTR [eax+0x8]
  6fe2b9:	72 f5                	jb     0x6fe2b0
  6fe2bb:	f6 46 38 01          	test   BYTE PTR [esi+0x38],0x1
  6fe2bf:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  6fe2c2:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  6fe2c5:	74 16                	je     0x6fe2dd
  6fe2c7:	83 46 18 04          	add    DWORD PTR [esi+0x18],0x4
  6fe2cb:	6a ff                	push   0xffffffff
  6fe2cd:	33 d2                	xor    edx,edx
  6fe2cf:	8b ce                	mov    ecx,esi
  6fe2d1:	e8 0a fb ff ff       	call   0x6fdde0
  6fe2d6:	83 c4 04             	add    esp,0x4
  6fe2d9:	83 46 18 fc          	add    DWORD PTR [esi+0x18],0xfffffffc
  6fe2dd:	33 c0                	xor    eax,eax
  6fe2df:	5f                   	pop    edi
  6fe2e0:	5e                   	pop    esi
  6fe2e1:	5b                   	pop    ebx
  6fe2e2:	8b e5                	mov    esp,ebp
  6fe2e4:	5d                   	pop    ebp
  6fe2e5:	c3                   	ret
  6fe2e6:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
  6fe2e9:	2b 46 08             	sub    eax,DWORD PTR [esi+0x8]
  6fe2ec:	3d 40 01 00 00       	cmp    eax,0x140
  6fe2f1:	7f 14                	jg     0x6fe307
  6fe2f3:	8b 46 2c             	mov    eax,DWORD PTR [esi+0x2c]
  6fe2f6:	83 f8 14             	cmp    eax,0x14
  6fe2f9:	7c 04                	jl     0x6fe2ff
  6fe2fb:	03 c0                	add    eax,eax
  6fe2fd:	eb 03                	jmp    0x6fe302
  6fe2ff:	83 c0 14             	add    eax,0x14
  6fe302:	e8 a9 f9 ff ff       	call   0x6fdcb0
  6fe307:	8b 46 14             	mov    eax,DWORD PTR [esi+0x14]
  6fe30a:	3b 46 24             	cmp    eax,DWORD PTR [esi+0x24]
  6fe30d:	75 09                	jne    0x6fe318
  6fe30f:	8b c6                	mov    eax,esi
  6fe311:	e8 7a fa ff ff       	call   0x6fdd90
  6fe316:	eb 06                	jmp    0x6fe31e
  6fe318:	83 c0 18             	add    eax,0x18
  6fe31b:	89 46 14             	mov    DWORD PTR [esi+0x14],eax
  6fe31e:	8b 4e 20             	mov    ecx,DWORD PTR [esi+0x20]
  6fe321:	03 cb                	add    ecx,ebx
  6fe323:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  6fe326:	83 c1 10             	add    ecx,0x10
  6fe329:	89 08                	mov    DWORD PTR [eax],ecx
  6fe32b:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  6fe32e:	89 4e 0c             	mov    DWORD PTR [esi+0xc],ecx
  6fe331:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  6fe334:	81 c2 40 01 00 00    	add    edx,0x140
  6fe33a:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  6fe33d:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  6fe340:	f6 46 38 01          	test   BYTE PTR [esi+0x38],0x1
  6fe344:	74 0e                	je     0x6fe354
  6fe346:	6a ff                	push   0xffffffff
  6fe348:	33 d2                	xor    edx,edx
  6fe34a:	8b ce                	mov    ecx,esi
  6fe34c:	e8 8f fa ff ff       	call   0x6fdde0
  6fe351:	83 c4 04             	add    esp,0x4
  6fe354:	8b 56 14             	mov    edx,DWORD PTR [esi+0x14]
  6fe357:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  6fe35a:	8b 08                	mov    ecx,DWORD PTR [eax]
  6fe35c:	8b 51 10             	mov    edx,DWORD PTR [ecx+0x10]
  6fe35f:	56                   	push   esi
  6fe360:	ff d2                	call   edx
  6fe362:	83 c4 04             	add    esp,0x4
  6fe365:	85 c0                	test   eax,eax
  6fe367:	79 0c                	jns    0x6fe375
  6fe369:	b8 02 00 00 00       	mov    eax,0x2
  6fe36e:	5f                   	pop    edi
  6fe36f:	5e                   	pop    esi
  6fe370:	5b                   	pop    ebx
  6fe371:	8b e5                	mov    esp,ebp
  6fe373:	5d                   	pop    ebp
  6fe374:	c3                   	ret
  6fe375:	c1 e0 04             	shl    eax,0x4
  6fe378:	8b c8                	mov    ecx,eax
  6fe37a:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6fe37d:	2b c1                	sub    eax,ecx
  6fe37f:	56                   	push   esi
  6fe380:	e8 3b 01 00 00       	call   0x6fe4c0
  6fe385:	83 c4 04             	add    esp,0x4
  6fe388:	5f                   	pop    edi
  6fe389:	5e                   	pop    esi
  6fe38a:	b8 01 00 00 00       	mov    eax,0x1
  6fe38f:	5b                   	pop    ebx
  6fe390:	8b e5                	mov    esp,ebp
  6fe392:	5d                   	pop    ebp
  6fe393:	c3                   	ret

# VM_instruction_fetch_and_opcode_switch VA=0x006FC550 raw=0x002FB950 size=168 sha256=02221a63bff2f7ca514c9d471f1145819fde52ac5d06e71c74bf7b1cfbb64f21

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fc550 <.text+0x2fb550>:
  6fc550:	55                   	push   ebp
  6fc551:	8b ec                	mov    ebp,esp
  6fc553:	83 e4 c0             	and    esp,0xffffffc0
  6fc556:	81 ec b4 00 00 00    	sub    esp,0xb4
  6fc55c:	53                   	push   ebx
  6fc55d:	56                   	push   esi
  6fc55e:	57                   	push   edi
  6fc55f:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  6fc562:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  6fc565:	8b 47 18             	mov    eax,DWORD PTR [edi+0x18]
  6fc568:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  6fc56b:	8b 4f 0c             	mov    ecx,DWORD PTR [edi+0xc]
  6fc56e:	89 44 24 34          	mov    DWORD PTR [esp+0x34],eax
  6fc572:	8b 02                	mov    eax,DWORD PTR [edx]
  6fc574:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  6fc577:	89 44 24 5c          	mov    DWORD PTR [esp+0x5c],eax
  6fc57b:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  6fc57e:	89 4c 24 38          	mov    DWORD PTR [esp+0x38],ecx
  6fc582:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  6fc586:	eb 02                	jmp    0x6fc58a
  6fc588:	dd d8                	fstp   st(0)
  6fc58a:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  6fc58e:	8b 18                	mov    ebx,DWORD PTR [eax]
  6fc590:	83 c0 04             	add    eax,0x4
  6fc593:	89 44 24 34          	mov    DWORD PTR [esp+0x34],eax
  6fc597:	8a 47 38             	mov    al,BYTE PTR [edi+0x38]
  6fc59a:	a8 0c                	test   al,0xc
  6fc59c:	74 29                	je     0x6fc5c7
  6fc59e:	ff 4f 40             	dec    DWORD PTR [edi+0x40]
  6fc5a1:	74 04                	je     0x6fc5a7
  6fc5a3:	a8 04                	test   al,0x4
  6fc5a5:	74 20                	je     0x6fc5c7
  6fc5a7:	8b 4c 24 34          	mov    ecx,DWORD PTR [esp+0x34]
  6fc5ab:	51                   	push   ecx
  6fc5ac:	8b f7                	mov    esi,edi
  6fc5ae:	e8 ad f0 ff ff       	call   0x6fb660
  6fc5b3:	83 c4 04             	add    esp,0x4
  6fc5b6:	80 7f 06 01          	cmp    BYTE PTR [edi+0x6],0x1
  6fc5ba:	0f 84 c0 10 00 00    	je     0x6fd680
  6fc5c0:	8b 57 0c             	mov    edx,DWORD PTR [edi+0xc]
  6fc5c3:	89 54 24 38          	mov    DWORD PTR [esp+0x38],edx
  6fc5c7:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  6fc5cb:	8b c3                	mov    eax,ebx
  6fc5cd:	c1 e8 06             	shr    eax,0x6
  6fc5d0:	25 ff 00 00 00       	and    eax,0xff
  6fc5d5:	89 44 24 3c          	mov    DWORD PTR [esp+0x3c],eax
  6fc5d9:	c1 e0 04             	shl    eax,0x4
  6fc5dc:	8d 34 08             	lea    esi,[eax+ecx*1]
  6fc5df:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  6fc5e3:	8b c3                	mov    eax,ebx
  6fc5e5:	83 e0 3f             	and    eax,0x3f
  6fc5e8:	89 74 24 44          	mov    DWORD PTR [esp+0x44],esi
  6fc5ec:	83 f8 25             	cmp    eax,0x25
  6fc5ef:	77 99                	ja     0x6fc58a
  6fc5f1:	ff 24 85 94 d6 6f 00 	jmp    DWORD PTR [eax*4+0x6fd694]

# coroutine_resume_gate_and_guard VA=0x006FE6D0 raw=0x002FDAD0 size=153 sha256=1fca58436f6b5125a28d1b1b27a9069f3bc5944a0557fd2f2b9a860427569c5a

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe6d0 <.text+0x2fd6d0>:
  6fe6d0:	57                   	push   edi
  6fe6d1:	8b f8                	mov    edi,eax
  6fe6d3:	8a 47 06             	mov    al,BYTE PTR [edi+0x6]
  6fe6d6:	3c 01                	cmp    al,0x1
  6fe6d8:	74 19                	je     0x6fe6f3
  6fe6da:	84 c0                	test   al,al
  6fe6dc:	75 08                	jne    0x6fe6e6
  6fe6de:	8b 47 14             	mov    eax,DWORD PTR [edi+0x14]
  6fe6e1:	3b 47 28             	cmp    eax,DWORD PTR [edi+0x28]
  6fe6e4:	74 0d                	je     0x6fe6f3
  6fe6e6:	8b c7                	mov    eax,edi
  6fe6e8:	ba 18 2b c4 00       	mov    edx,0xc42b18
  6fe6ed:	5f                   	pop    edi
  6fe6ee:	e9 6d ff ff ff       	jmp    0x6fe660
  6fe6f3:	0f b7 47 34          	movzx  eax,WORD PTR [edi+0x34]
  6fe6f7:	ba c8 00 00 00       	mov    edx,0xc8
  6fe6fc:	66 3b c2             	cmp    ax,dx
  6fe6ff:	72 0d                	jb     0x6fe70e
  6fe701:	8b c7                	mov    eax,edi
  6fe703:	ba 04 2b c4 00       	mov    edx,0xc42b04
  6fe708:	5f                   	pop    edi
  6fe709:	e9 52 ff ff ff       	jmp    0x6fe660
  6fe70e:	40                   	inc    eax
  6fe70f:	66 89 47 34          	mov    WORD PTR [edi+0x34],ax
  6fe713:	66 89 47 36          	mov    WORD PTR [edi+0x36],ax
  6fe717:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  6fe71a:	c1 e1 04             	shl    ecx,0x4
  6fe71d:	53                   	push   ebx
  6fe71e:	2b c1                	sub    eax,ecx
  6fe720:	50                   	push   eax
  6fe721:	68 e0 e5 6f 00       	push   0x6fe5e0
  6fe726:	57                   	push   edi
  6fe727:	e8 74 f4 ff ff       	call   0x6fdba0
  6fe72c:	8b d8                	mov    ebx,eax
  6fe72e:	83 c4 0c             	add    esp,0xc
  6fe731:	85 db                	test   ebx,ebx
  6fe733:	74 22                	je     0x6fe757
  6fe735:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  6fe738:	88 5f 06             	mov    BYTE PTR [edi+0x6],bl
  6fe73b:	e8 20 f3 ff ff       	call   0x6fda60
  6fe740:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  6fe743:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  6fe746:	b8 ff ff 00 00       	mov    eax,0xffff
  6fe74b:	89 51 08             	mov    DWORD PTR [ecx+0x8],edx
  6fe74e:	66 01 47 34          	add    WORD PTR [edi+0x34],ax
  6fe752:	8b c3                	mov    eax,ebx
  6fe754:	5b                   	pop    ebx
  6fe755:	5f                   	pop    edi
  6fe756:	c3                   	ret
  6fe757:	0f b6 5f 06          	movzx  ebx,BYTE PTR [edi+0x6]
  6fe75b:	b8 ff ff 00 00       	mov    eax,0xffff
  6fe760:	66 01 47 34          	add    WORD PTR [edi+0x34],ax
  6fe764:	8b c3                	mov    eax,ebx
  6fe766:	5b                   	pop    ebx
  6fe767:	5f                   	pop    edi
  6fe768:	c3                   	ret

# resume_callback_reenter_VM VA=0x006FE5E0 raw=0x002FD9E0 size=123 sha256=98ea14fbf578337a2f77dc7633c93c6d498b330f68e4ff56e7eb5d701ecd0676

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe5e0 <.text+0x2fd5e0>:
  6fe5e0:	55                   	push   ebp
  6fe5e1:	8b ec                	mov    ebp,esp
  6fe5e3:	56                   	push   esi
  6fe5e4:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6fe5e7:	80 7e 06 00          	cmp    BYTE PTR [esi+0x6],0x0
  6fe5eb:	8b 46 14             	mov    eax,DWORD PTR [esi+0x14]
  6fe5ee:	75 18                	jne    0x6fe608
  6fe5f0:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6fe5f3:	6a ff                	push   0xffffffff
  6fe5f5:	83 c0 f0             	add    eax,0xfffffff0
  6fe5f8:	8b ce                	mov    ecx,esi
  6fe5fa:	e8 c1 fb ff ff       	call   0x6fe1c0
  6fe5ff:	83 c4 04             	add    esp,0x4
  6fe602:	85 c0                	test   eax,eax
  6fe604:	75 52                	jne    0x6fe658
  6fe606:	eb 2f                	jmp    0x6fe637
  6fe608:	c6 46 06 00          	mov    BYTE PTR [esi+0x6],0x0
  6fe60c:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  6fe60f:	8b 11                	mov    edx,DWORD PTR [ecx]
  6fe611:	80 7a 06 00          	cmp    BYTE PTR [edx+0x6],0x0
  6fe615:	74 1b                	je     0x6fe632
  6fe617:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6fe61a:	56                   	push   esi
  6fe61b:	e8 a0 fe ff ff       	call   0x6fe4c0
  6fe620:	83 c4 04             	add    esp,0x4
  6fe623:	85 c0                	test   eax,eax
  6fe625:	74 10                	je     0x6fe637
  6fe627:	8b 46 14             	mov    eax,DWORD PTR [esi+0x14]
  6fe62a:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  6fe62d:	89 4e 08             	mov    DWORD PTR [esi+0x8],ecx
  6fe630:	eb 05                	jmp    0x6fe637
  6fe632:	8b 10                	mov    edx,DWORD PTR [eax]
  6fe634:	89 56 0c             	mov    DWORD PTR [esi+0xc],edx
  6fe637:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6fe63a:	2b 4e 28             	sub    ecx,DWORD PTR [esi+0x28]
  6fe63d:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  6fe642:	f7 e9                	imul   ecx
  6fe644:	c1 fa 02             	sar    edx,0x2
  6fe647:	8b c2                	mov    eax,edx
  6fe649:	c1 e8 1f             	shr    eax,0x1f
  6fe64c:	03 c2                	add    eax,edx
  6fe64e:	50                   	push   eax
  6fe64f:	56                   	push   esi
  6fe650:	e8 fb de ff ff       	call   0x6fc550
  6fe655:	83 c4 08             	add    esp,0x8
  6fe658:	5e                   	pop    esi
  6fe659:	5d                   	pop    ebp
  6fe65a:	c3                   	ret

# coroutine_resume_native_caller VA=0x007071B2 raw=0x003065B2 size=63 sha256=a0cc4fd87cee4474fe67fe28e9d0559700d194ee40cd3bddeb93a31d83d6a1c0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007071b2 <.text+0x3061b2>:
  7071b2:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  7071b5:	8b c6                	mov    eax,esi
  7071b7:	8b f3                	mov    esi,ebx
  7071b9:	e8 12 e0 fe ff       	call   0x6f51d0
  7071be:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  7071c1:	8b f7                	mov    esi,edi
  7071c3:	66 8b 46 34          	mov    ax,WORD PTR [esi+0x34]
  7071c7:	66 89 43 34          	mov    WORD PTR [ebx+0x34],ax
  7071cb:	8b c3                	mov    eax,ebx
  7071cd:	e8 fe 74 ff ff       	call   0x6fe6d0
  7071d2:	85 c0                	test   eax,eax
  7071d4:	74 1b                	je     0x7071f1
  7071d6:	83 f8 01             	cmp    eax,0x1
  7071d9:	74 16                	je     0x7071f1
  7071db:	b8 01 00 00 00       	mov    eax,0x1
  7071e0:	8b fb                	mov    edi,ebx
  7071e2:	e8 e9 df fe ff       	call   0x6f51d0
  7071e7:	5f                   	pop    edi
  7071e8:	5e                   	pop    esi
  7071e9:	83 c8 ff             	or     eax,0xffffffff
  7071ec:	5b                   	pop    ebx
  7071ed:	8b e5                	mov    esp,ebp
  7071ef:	5d                   	pop    ebp
  7071f0:	c3                   	ret

# coroutine_yield_C_boundary_gate VA=0x00707480 raw=0x00306880 size=60 sha256=73f97712addbb6eaba1a33e4983ac155d5a3843e670440ac00982b050b297bff

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00707480 <.text+0x306480>:
  707480:	55                   	push   ebp
  707481:	8b ec                	mov    ebp,esp
  707483:	56                   	push   esi
  707484:	57                   	push   edi
  707485:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  707488:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  70748b:	66 8b 47 34          	mov    ax,WORD PTR [edi+0x34]
  70748f:	2b 77 0c             	sub    esi,DWORD PTR [edi+0xc]
  707492:	66 3b 47 36          	cmp    ax,WORD PTR [edi+0x36]
  707496:	76 0e                	jbe    0x7074a6
  707498:	68 40 2b c4 00       	push   0xc42b40
  70749d:	57                   	push   edi
  70749e:	e8 bd 16 ff ff       	call   0x6f8b60
  7074a3:	83 c4 08             	add    esp,0x8
  7074a6:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  7074a9:	83 e6 f0             	and    esi,0xfffffff0
  7074ac:	2b ce                	sub    ecx,esi
  7074ae:	89 4f 0c             	mov    DWORD PTR [edi+0xc],ecx
  7074b1:	c6 47 06 01          	mov    BYTE PTR [edi+0x6],0x1
  7074b5:	5f                   	pop    edi
  7074b6:	83 c8 ff             	or     eax,0xffffffff
  7074b9:	5e                   	pop    esi
  7074ba:	5d                   	pop    ebp
  7074bb:	c3                   	ret

# standard_loadstring_only_compile VA=0x00706400 raw=0x00305800 size=198 sha256=e515d3fa0ec081c08cc10fd955de11d6f477c43841dffc34ce222ca0895e340e

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00706400 <.text+0x305400>:
  706400:	55                   	push   ebp
  706401:	8b ec                	mov    ebp,esp
  706403:	83 e4 f8             	and    esp,0xfffffff8
  706406:	83 ec 20             	sub    esp,0x20
  706409:	56                   	push   esi
  70640a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70640d:	57                   	push   edi
  70640e:	56                   	push   esi
  70640f:	8d 44 24 0c          	lea    eax,[esp+0xc]
  706413:	b9 01 00 00 00       	mov    ecx,0x1
  706418:	e8 f3 fd fe ff       	call   0x6f6210
  70641d:	8b f8                	mov    edi,eax
  70641f:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  706422:	83 c0 10             	add    eax,0x10
  706425:	83 c4 04             	add    esp,0x4
  706428:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  70642b:	73 0d                	jae    0x70643a
  70642d:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  706432:	74 06                	je     0x70643a
  706434:	83 78 08 00          	cmp    DWORD PTR [eax+0x8],0x0
  706438:	7f 04                	jg     0x70643e
  70643a:	8b c7                	mov    eax,edi
  70643c:	eb 0e                	jmp    0x70644c
  70643e:	33 c0                	xor    eax,eax
  706440:	56                   	push   esi
  706441:	8d 48 02             	lea    ecx,[eax+0x2]
  706444:	e8 c7 fd fe ff       	call   0x6f6210
  706449:	83 c4 04             	add    esp,0x4
  70644c:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  706450:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  706454:	89 7c 24 0c          	mov    DWORD PTR [esp+0xc],edi
  706458:	8b c8                	mov    ecx,eax
  70645a:	85 c0                	test   eax,eax
  70645c:	75 05                	jne    0x706463
  70645e:	b9 00 27 c4 00       	mov    ecx,0xc42700
  706463:	8d 54 24 0c          	lea    edx,[esp+0xc]
  706467:	56                   	push   esi
  706468:	8d 44 24 18          	lea    eax,[esp+0x18]
  70646c:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  706470:	c7 44 24 20 e0 70 6f 	mov    DWORD PTR [esp+0x20],0x6f70e0
  706477:	00 
  706478:	89 54 24 24          	mov    DWORD PTR [esp+0x24],edx
  70647c:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  706483:	00 
  706484:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  70648b:	00 
  70648c:	e8 ff 84 ff ff       	call   0x6fe990
  706491:	83 c4 04             	add    esp,0x4
  706494:	85 c0                	test   eax,eax
  706496:	75 0b                	jne    0x7064a3
  706498:	b8 01 00 00 00       	mov    eax,0x1
  70649d:	5f                   	pop    edi
  70649e:	5e                   	pop    esi
  70649f:	8b e5                	mov    esp,ebp
  7064a1:	5d                   	pop    ebp
  7064a2:	c3                   	ret
  7064a3:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7064a6:	c7 40 08 00 00 00 00 	mov    DWORD PTR [eax+0x8],0x0
  7064ad:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  7064b1:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  7064b6:	e8 f5 ed fe ff       	call   0x6f52b0
  7064bb:	5f                   	pop    edi
  7064bc:	b8 02 00 00 00       	mov    eax,0x2
  7064c1:	5e                   	pop    esi
  7064c2:	8b e5                	mov    esp,ebp
  7064c4:	5d                   	pop    ebp
  7064c5:	c3                   	ret

# standard_load_reader_only_compile VA=0x00706620 raw=0x00305A20 size=285 sha256=293e3ab0c5076e9c1744795c529203933b8d3d98282187e2e7596d53b5411624

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00706620 <.text+0x305620>:
  706620:	55                   	push   ebp
  706621:	8b ec                	mov    ebp,esp
  706623:	83 ec 14             	sub    esp,0x14
  706626:	53                   	push   ebx
  706627:	56                   	push   esi
  706628:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  70662b:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  70662e:	83 c0 10             	add    eax,0x10
  706631:	57                   	push   edi
  706632:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  706635:	73 4f                	jae    0x706686
  706637:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  70663c:	74 48                	je     0x706686
  70663e:	33 ff                	xor    edi,edi
  706640:	39 78 08             	cmp    DWORD PTR [eax+0x8],edi
  706643:	7e 43                	jle    0x706688
  706645:	56                   	push   esi
  706646:	33 c0                	xor    eax,eax
  706648:	8d 4f 02             	lea    ecx,[edi+0x2]
  70664b:	e8 c0 fb fe ff       	call   0x6f6210
  706650:	83 c4 04             	add    esp,0x4
  706653:	8b d8                	mov    ebx,eax
  706655:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  706658:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  70665b:	3b c1                	cmp    eax,ecx
  70665d:	73 20                	jae    0x70667f
  70665f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  706664:	74 06                	je     0x70666c
  706666:	83 78 08 06          	cmp    DWORD PTR [eax+0x8],0x6
  70666a:	74 4a                	je     0x7066b6
  70666c:	3b c1                	cmp    eax,ecx
  70666e:	73 0f                	jae    0x70667f
  706670:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  706675:	74 08                	je     0x70667f
  706677:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  70667a:	83 f8 ff             	cmp    eax,0xffffffff
  70667d:	75 10                	jne    0x70668f
  70667f:	b8 f4 26 c4 00       	mov    eax,0xc426f4
  706684:	eb 10                	jmp    0x706696
  706686:	33 ff                	xor    edi,edi
  706688:	bb 14 36 c4 00       	mov    ebx,0xc43614
  70668d:	eb c6                	jmp    0x706655
  70668f:	8b 04 85 1c be c0 00 	mov    eax,DWORD PTR [eax*4+0xc0be1c]
  706696:	50                   	push   eax
  706697:	a1 34 be c0 00       	mov    eax,ds:0xc0be34
  70669c:	50                   	push   eax
  70669d:	68 68 27 c4 00       	push   0xc42768
  7066a2:	56                   	push   esi
  7066a3:	e8 d8 ee fe ff       	call   0x6f5580
  7066a8:	6a 01                	push   0x1
  7066aa:	8b f8                	mov    edi,eax
  7066ac:	e8 ef f6 fe ff       	call   0x6f5da0
  7066b1:	83 c4 14             	add    esp,0x14
  7066b4:	33 ff                	xor    edi,edi
  7066b6:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  7066b9:	83 c1 30             	add    ecx,0x30
  7066bc:	39 4e 08             	cmp    DWORD PTR [esi+0x8],ecx
  7066bf:	73 19                	jae    0x7066da
  7066c1:	b8 10 00 00 00       	mov    eax,0x10
  7066c6:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  7066c9:	89 7a 08             	mov    DWORD PTR [edx+0x8],edi
  7066cc:	01 46 08             	add    DWORD PTR [esi+0x8],eax
  7066cf:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  7066d2:	83 c1 30             	add    ecx,0x30
  7066d5:	39 4e 08             	cmp    DWORD PTR [esi+0x8],ecx
  7066d8:	72 ec                	jb     0x7066c6
  7066da:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  7066dd:	83 c2 30             	add    edx,0x30
  7066e0:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  7066e3:	8b cb                	mov    ecx,ebx
  7066e5:	3b df                	cmp    ebx,edi
  7066e7:	75 05                	jne    0x7066ee
  7066e9:	b9 00 27 c4 00       	mov    ecx,0xc42700
  7066ee:	56                   	push   esi
  7066ef:	8d 45 ec             	lea    eax,[ebp-0x14]
  7066f2:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  7066f5:	c7 45 f4 40 65 70 00 	mov    DWORD PTR [ebp-0xc],0x706540
  7066fc:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  7066ff:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  706702:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
  706705:	e8 86 82 ff ff       	call   0x6fe990
  70670a:	83 c4 04             	add    esp,0x4
  70670d:	85 c0                	test   eax,eax
  70670f:	75 0c                	jne    0x70671d
  706711:	5f                   	pop    edi
  706712:	5e                   	pop    esi
  706713:	b8 01 00 00 00       	mov    eax,0x1
  706718:	5b                   	pop    ebx
  706719:	8b e5                	mov    esp,ebp
  70671b:	5d                   	pop    ebp
  70671c:	c3                   	ret
  70671d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  706720:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  706723:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  706727:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  70672c:	e8 7f eb fe ff       	call   0x6f52b0
  706731:	5f                   	pop    edi
  706732:	5e                   	pop    esi
  706733:	b8 02 00 00 00       	mov    eax,0x2
  706738:	5b                   	pop    ebx
  706739:	8b e5                	mov    esp,ebp
  70673b:	5d                   	pop    ebp
  70673c:	c3                   	ret

# standard_load_reader_function_source VA=0x00706540 raw=0x00305940 size=218 sha256=77068e601eb5b0b3709997f0b3d670a4ae8c666d71f24e2b56f6c06ee5b9a614

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00706540 <.text+0x305540>:
  706540:	55                   	push   ebp
  706541:	8b ec                	mov    ebp,esp
  706543:	56                   	push   esi
  706544:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  706547:	b8 02 00 00 00       	mov    eax,0x2
  70654c:	8b ce                	mov    ecx,esi
  70654e:	e8 1d ec fe ff       	call   0x6f5170
  706553:	85 c0                	test   eax,eax
  706555:	75 13                	jne    0x70656a
  706557:	68 d0 35 c4 00       	push   0xc435d0
  70655c:	68 9c 27 c4 00       	push   0xc4279c
  706561:	56                   	push   esi
  706562:	e8 c9 f9 fe ff       	call   0x6f5f30
  706567:	83 c4 0c             	add    esp,0xc
  70656a:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  70656d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  706570:	3b c8                	cmp    ecx,eax
  706572:	72 05                	jb     0x706579
  706574:	b9 c8 bf c0 00       	mov    ecx,0xc0bfc8
  706579:	8b 11                	mov    edx,DWORD PTR [ecx]
  70657b:	89 10                	mov    DWORD PTR [eax],edx
  70657d:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  706580:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  706583:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  706586:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  706589:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  70658d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  706590:	6a 01                	push   0x1
  706592:	83 c0 f0             	add    eax,0xfffffff0
  706595:	50                   	push   eax
  706596:	56                   	push   esi
  706597:	e8 b4 7f ff ff       	call   0x6fe550
  70659c:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  70659f:	8d 42 f0             	lea    eax,[edx-0x10]
  7065a2:	83 c4 0c             	add    esp,0xc
  7065a5:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  7065aa:	74 5b                	je     0x706607
  7065ac:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7065af:	85 c9                	test   ecx,ecx
  7065b1:	75 0a                	jne    0x7065bd
  7065b3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  7065b6:	89 0a                	mov    DWORD PTR [edx],ecx
  7065b8:	33 c0                	xor    eax,eax
  7065ba:	5e                   	pop    esi
  7065bb:	5d                   	pop    ebp
  7065bc:	c3                   	ret
  7065bd:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  7065c2:	74 43                	je     0x706607
  7065c4:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7065c7:	83 f9 04             	cmp    ecx,0x4
  7065ca:	74 05                	je     0x7065d1
  7065cc:	83 f9 03             	cmp    ecx,0x3
  7065cf:	75 36                	jne    0x706607
  7065d1:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  7065d4:	83 c1 20             	add    ecx,0x20
  7065d7:	3b ca                	cmp    ecx,edx
  7065d9:	72 05                	jb     0x7065e0
  7065db:	b9 c8 bf c0 00       	mov    ecx,0xc0bfc8
  7065e0:	8b 10                	mov    edx,DWORD PTR [eax]
  7065e2:	89 11                	mov    DWORD PTR [ecx],edx
  7065e4:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7065e7:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  7065ea:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  7065ed:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7065f0:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  7065f3:	83 46 08 f0          	add    DWORD PTR [esi+0x8],0xfffffff0
  7065f7:	51                   	push   ecx
  7065f8:	6a 03                	push   0x3
  7065fa:	8b c6                	mov    eax,esi
  7065fc:	e8 ef ed fe ff       	call   0x6f53f0
  706601:	83 c4 08             	add    esp,0x8
  706604:	5e                   	pop    esi
  706605:	5d                   	pop    ebp
  706606:	c3                   	ret
  706607:	68 ec 35 c4 00       	push   0xc435ec
  70660c:	56                   	push   esi
  70660d:	e8 1e f9 fe ff       	call   0x6f5f30
  706612:	83 c4 08             	add    esp,0x8
  706615:	33 c0                	xor    eax,eax
  706617:	5e                   	pop    esi
  706618:	5d                   	pop    ebp
  706619:	c3                   	ret

# standard_loadfile_stdio_source VA=0x006F6E60 raw=0x002F6260 size=637 sha256=b0abcf9d9b597d74b53a634a19cbef49b4a31b1ed6dd6969297bf5d7a05d672b

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f6e60 <.text+0x2f5e60>:
  6f6e60:	55                   	push   ebp
  6f6e61:	8b ec                	mov    ebp,esp
  6f6e63:	83 e4 f8             	and    esp,0xfffffff8
  6f6e66:	81 ec 2c 02 00 00    	sub    esp,0x22c
  6f6e6c:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6f6e71:	33 c4                	xor    eax,esp
  6f6e73:	89 84 24 28 02 00 00 	mov    DWORD PTR [esp+0x228],eax
  6f6e7a:	53                   	push   ebx
  6f6e7b:	56                   	push   esi
  6f6e7c:	57                   	push   edi
  6f6e7d:	8b f9                	mov    edi,ecx
  6f6e7f:	8b 5f 08             	mov    ebx,DWORD PTR [edi+0x8]
  6f6e82:	2b 5f 0c             	sub    ebx,DWORD PTR [edi+0xc]
  6f6e85:	8b f2                	mov    esi,edx
  6f6e87:	c1 fb 04             	sar    ebx,0x4
  6f6e8a:	43                   	inc    ebx
  6f6e8b:	89 74 24 0c          	mov    DWORD PTR [esp+0xc],esi
  6f6e8f:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  6f6e96:	00 
  6f6e97:	85 f6                	test   esi,esi
  6f6e99:	0f 85 ce 00 00 00    	jne    0x6f6f6d
  6f6e9f:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  6f6ea2:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  6f6ea5:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  6f6ea8:	72 07                	jb     0x6f6eb1
  6f6eaa:	8b c7                	mov    eax,edi
  6f6eac:	e8 ef 44 00 00       	call   0x6fb3a0
  6f6eb1:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f6eb4:	6a 06                	push   0x6
  6f6eb6:	68 fc 27 c4 00       	push   0xc427fc
  6f6ebb:	57                   	push   edi
  6f6ebc:	e8 af 7d 00 00       	call   0x6fec70
  6f6ec1:	89 06                	mov    DWORD PTR [esi],eax
  6f6ec3:	c7 46 08 04 00 00 00 	mov    DWORD PTR [esi+0x8],0x4
  6f6eca:	83 47 08 10          	add    DWORD PTR [edi+0x8],0x10
  6f6ece:	83 c4 0c             	add    esp,0xc
  6f6ed1:	e8 d5 e0 19 00       	call   0x894fab
  6f6ed6:	8b 74 24 0c          	mov    esi,DWORD PTR [esp+0xc]
  6f6eda:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  6f6ede:	50                   	push   eax
  6f6edf:	e8 44 19 1a 00       	call   0x898828
  6f6ee4:	83 c4 04             	add    esp,0x4
  6f6ee7:	83 f8 23             	cmp    eax,0x23
  6f6eea:	75 30                	jne    0x6f6f1c
  6f6eec:	c7 44 24 28 01 00 00 	mov    DWORD PTR [esp+0x28],0x1
  6f6ef3:	00 
  6f6ef4:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  6f6ef8:	52                   	push   edx
  6f6ef9:	e8 2a 19 1a 00       	call   0x898828
  6f6efe:	83 c4 04             	add    esp,0x4
  6f6f01:	83 f8 ff             	cmp    eax,0xffffffff
  6f6f04:	0f 84 d5 00 00 00    	je     0x6f6fdf
  6f6f0a:	83 f8 0a             	cmp    eax,0xa
  6f6f0d:	75 e5                	jne    0x6f6ef4
  6f6f0f:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  6f6f13:	50                   	push   eax
  6f6f14:	e8 0f 19 1a 00       	call   0x898828
  6f6f19:	83 c4 04             	add    esp,0x4
  6f6f1c:	83 f8 1b             	cmp    eax,0x1b
  6f6f1f:	0f 85 ba 00 00 00    	jne    0x6f6fdf
  6f6f25:	85 f6                	test   esi,esi
  6f6f27:	0f 84 b2 00 00 00    	je     0x6f6fdf
  6f6f2d:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  6f6f31:	51                   	push   ecx
  6f6f32:	68 e0 d1 be 00       	push   0xbed1e0
  6f6f37:	56                   	push   esi
  6f6f38:	e8 c5 18 1a 00       	call   0x898802
  6f6f3d:	83 c4 0c             	add    esp,0xc
  6f6f40:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  6f6f44:	85 c0                	test   eax,eax
  6f6f46:	75 7c                	jne    0x6f6fc4
  6f6f48:	53                   	push   ebx
  6f6f49:	68 0c 28 c4 00       	push   0xc4280c
  6f6f4e:	8b c7                	mov    eax,edi
  6f6f50:	e8 5b fe ff ff       	call   0x6f6db0
  6f6f55:	83 c4 08             	add    esp,0x8
  6f6f58:	5f                   	pop    edi
  6f6f59:	5e                   	pop    esi
  6f6f5a:	5b                   	pop    ebx
  6f6f5b:	8b 8c 24 28 02 00 00 	mov    ecx,DWORD PTR [esp+0x228]
  6f6f62:	33 cc                	xor    ecx,esp
  6f6f64:	e8 98 a0 19 00       	call   0x891001
  6f6f69:	8b e5                	mov    esp,ebp
  6f6f6b:	5d                   	pop    ebp
  6f6f6c:	c3                   	ret
  6f6f6d:	56                   	push   esi
  6f6f6e:	68 04 28 c4 00       	push   0xc42804
  6f6f73:	57                   	push   edi
  6f6f74:	e8 07 e6 ff ff       	call   0x6f5580
  6f6f79:	83 c4 0c             	add    esp,0xc
  6f6f7c:	68 08 28 c4 00       	push   0xc42808
  6f6f81:	56                   	push   esi
  6f6f82:	e8 f4 a8 19 00       	call   0x89187b
  6f6f87:	83 c4 08             	add    esp,0x8
  6f6f8a:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  6f6f8e:	85 c0                	test   eax,eax
  6f6f90:	0f 85 48 ff ff ff    	jne    0x6f6ede
  6f6f96:	53                   	push   ebx
  6f6f97:	68 74 5a c0 00       	push   0xc05a74
  6f6f9c:	8b c7                	mov    eax,edi
  6f6f9e:	e8 0d fe ff ff       	call   0x6f6db0
  6f6fa3:	83 c4 08             	add    esp,0x8
  6f6fa6:	5f                   	pop    edi
  6f6fa7:	5e                   	pop    esi
  6f6fa8:	5b                   	pop    ebx
  6f6fa9:	8b 8c 24 28 02 00 00 	mov    ecx,DWORD PTR [esp+0x228]
  6f6fb0:	33 cc                	xor    ecx,esp
  6f6fb2:	e8 4a a0 19 00       	call   0x891001
  6f6fb7:	8b e5                	mov    esp,ebp
  6f6fb9:	5d                   	pop    ebp
  6f6fba:	c3                   	ret
  6f6fbb:	eb 03                	jmp    0x6f6fc0
  6f6fbd:	8d 49 00             	lea    ecx,[ecx+0x0]
  6f6fc0:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  6f6fc4:	50                   	push   eax
  6f6fc5:	e8 5e 18 1a 00       	call   0x898828
  6f6fca:	83 c4 04             	add    esp,0x4
  6f6fcd:	83 f8 ff             	cmp    eax,0xffffffff
  6f6fd0:	74 05                	je     0x6f6fd7
  6f6fd2:	83 f8 1b             	cmp    eax,0x1b
  6f6fd5:	75 e9                	jne    0x6f6fc0
  6f6fd7:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  6f6fde:	00 
  6f6fdf:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  6f6fe3:	52                   	push   edx
  6f6fe4:	50                   	push   eax
  6f6fe5:	e8 c9 15 1a 00       	call   0x8985b3
  6f6fea:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f6fed:	83 ee 10             	sub    esi,0x10
  6f6ff0:	83 c4 08             	add    esp,0x8
  6f6ff3:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  6f6ff7:	74 25                	je     0x6f701e
  6f6ff9:	e8 d2 45 00 00       	call   0x6fb5d0
  6f6ffe:	85 c0                	test   eax,eax
  6f7000:	75 04                	jne    0x6f7006
  6f7002:	33 f6                	xor    esi,esi
  6f7004:	eb 1d                	jmp    0x6f7023
  6f7006:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  6f7009:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  6f700c:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  6f700f:	72 07                	jb     0x6f7018
  6f7011:	8b c7                	mov    eax,edi
  6f7013:	e8 88 43 00 00       	call   0x6fb3a0
  6f7018:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f701b:	83 ee 10             	sub    esi,0x10
  6f701e:	8b 36                	mov    esi,DWORD PTR [esi]
  6f7020:	83 c6 10             	add    esi,0x10
  6f7023:	33 c0                	xor    eax,eax
  6f7025:	8b ce                	mov    ecx,esi
  6f7027:	3b f0                	cmp    esi,eax
  6f7029:	75 05                	jne    0x6f7030
  6f702b:	b9 00 27 c4 00       	mov    ecx,0xc42700
  6f7030:	8d 54 24 28          	lea    edx,[esp+0x28]
  6f7034:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6f7038:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  6f703c:	57                   	push   edi
  6f703d:	8d 44 24 18          	lea    eax,[esp+0x18]
  6f7041:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  6f7045:	c7 44 24 20 40 6d 6f 	mov    DWORD PTR [esp+0x20],0x6f6d40
  6f704c:	00 
  6f704d:	89 54 24 24          	mov    DWORD PTR [esp+0x24],edx
  6f7051:	e8 3a 79 00 00       	call   0x6fe990
  6f7056:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6f705a:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  6f705e:	83 c4 04             	add    esp,0x4
  6f7061:	50                   	push   eax
  6f7062:	e8 af 13 1a 00       	call   0x898416
  6f7067:	83 c4 04             	add    esp,0x4
  6f706a:	83 7c 24 0c 00       	cmp    DWORD PTR [esp+0xc],0x0
  6f706f:	8b f0                	mov    esi,eax
  6f7071:	74 0d                	je     0x6f7080
  6f7073:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  6f7077:	51                   	push   ecx
  6f7078:	e8 4c ac 19 00       	call   0x891cc9
  6f707d:	83 c4 04             	add    esp,0x4
  6f7080:	85 f6                	test   esi,esi
  6f7082:	74 2c                	je     0x6f70b0
  6f7084:	8b cb                	mov    ecx,ebx
  6f7086:	8b c7                	mov    eax,edi
  6f7088:	e8 93 e1 ff ff       	call   0x6f5220
  6f708d:	53                   	push   ebx
  6f708e:	68 14 28 c4 00       	push   0xc42814
  6f7093:	e8 18 fd ff ff       	call   0x6f6db0
  6f7098:	83 c4 08             	add    esp,0x8
  6f709b:	5f                   	pop    edi
  6f709c:	5e                   	pop    esi
  6f709d:	5b                   	pop    ebx
  6f709e:	8b 8c 24 28 02 00 00 	mov    ecx,DWORD PTR [esp+0x228]
  6f70a5:	33 cc                	xor    ecx,esp
  6f70a7:	e8 55 9f 19 00       	call   0x891001
  6f70ac:	8b e5                	mov    esp,ebp
  6f70ae:	5d                   	pop    ebp
  6f70af:	c3                   	ret
  6f70b0:	8b c3                	mov    eax,ebx
  6f70b2:	8b f7                	mov    esi,edi
  6f70b4:	e8 b7 e1 ff ff       	call   0x6f5270
  6f70b9:	8b 8c 24 34 02 00 00 	mov    ecx,DWORD PTR [esp+0x234]
  6f70c0:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  6f70c4:	5f                   	pop    edi
  6f70c5:	5e                   	pop    esi
  6f70c6:	5b                   	pop    ebx
  6f70c7:	33 cc                	xor    ecx,esp
  6f70c9:	e8 33 9f 19 00       	call   0x891001
  6f70ce:	8b e5                	mov    esp,ebp
  6f70d0:	5d                   	pop    ebp
  6f70d1:	c3                   	ret
  6f70d2:	cc                   	int3
  6f70d3:	cc                   	int3
  6f70d4:	cc                   	int3
  6f70d5:	cc                   	int3
  6f70d6:	cc                   	int3
  6f70d7:	cc                   	int3
  6f70d8:	cc                   	int3
  6f70d9:	cc                   	int3
  6f70da:	cc                   	int3
  6f70db:	cc                   	int3
  6f70dc:	cc                   	int3

# global_open_libraries VA=0x006F7660 raw=0x002F6A60 size=164 sha256=62b94c7a9ed24e3f637381f7425f28ef6a52d3d79d57d9b5bd15b04fd2fadb24

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f7660 <.text+0x2f6660>:
  6f7660:	55                   	push   ebp
  6f7661:	8b ec                	mov    ebp,esp
  6f7663:	83 ec 0c             	sub    esp,0xc
  6f7666:	83 3d dc c0 c0 00 00 	cmp    DWORD PTR ds:0xc0c0dc,0x0
  6f766d:	53                   	push   ebx
  6f766e:	56                   	push   esi
  6f766f:	57                   	push   edi
  6f7670:	8b f0                	mov    esi,eax
  6f7672:	0f 84 85 00 00 00    	je     0x6f76fd
  6f7678:	bf dc c0 c0 00       	mov    edi,0xc0c0dc
  6f767d:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  6f7680:	8b 07                	mov    eax,DWORD PTR [edi]
  6f7682:	6a 00                	push   0x0
  6f7684:	50                   	push   eax
  6f7685:	e8 26 df ff ff       	call   0x6f55b0
  6f768a:	8b 5f fc             	mov    ebx,DWORD PTR [edi-0x4]
  6f768d:	83 c4 08             	add    esp,0x8
  6f7690:	85 db                	test   ebx,ebx
  6f7692:	75 08                	jne    0x6f769c
  6f7694:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6f7697:	89 59 08             	mov    DWORD PTR [ecx+0x8],ebx
  6f769a:	eb 40                	jmp    0x6f76dc
  6f769c:	8b c3                	mov    eax,ebx
  6f769e:	8d 50 01             	lea    edx,[eax+0x1]
  6f76a1:	8a 08                	mov    cl,BYTE PTR [eax]
  6f76a3:	40                   	inc    eax
  6f76a4:	84 c9                	test   cl,cl
  6f76a6:	75 f9                	jne    0x6f76a1
  6f76a8:	2b c2                	sub    eax,edx
  6f76aa:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  6f76ad:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  6f76b0:	8b 50 44             	mov    edx,DWORD PTR [eax+0x44]
  6f76b3:	3b 50 40             	cmp    edx,DWORD PTR [eax+0x40]
  6f76b6:	72 07                	jb     0x6f76bf
  6f76b8:	8b c6                	mov    eax,esi
  6f76ba:	e8 e1 3c 00 00       	call   0x6fb3a0
  6f76bf:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  6f76c2:	8b 7e 08             	mov    edi,DWORD PTR [esi+0x8]
  6f76c5:	50                   	push   eax
  6f76c6:	53                   	push   ebx
  6f76c7:	56                   	push   esi
  6f76c8:	e8 a3 75 00 00       	call   0x6fec70
  6f76cd:	89 07                	mov    DWORD PTR [edi],eax
  6f76cf:	c7 47 08 04 00 00 00 	mov    DWORD PTR [edi+0x8],0x4
  6f76d6:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  6f76d9:	83 c4 0c             	add    esp,0xc
  6f76dc:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  6f76e0:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f76e3:	6a 00                	push   0x0
  6f76e5:	83 c0 e0             	add    eax,0xffffffe0
  6f76e8:	50                   	push   eax
  6f76e9:	56                   	push   esi
  6f76ea:	e8 61 6e 00 00       	call   0x6fe550
  6f76ef:	83 c7 08             	add    edi,0x8
  6f76f2:	83 c4 0c             	add    esp,0xc
  6f76f5:	83 3f 00             	cmp    DWORD PTR [edi],0x0
  6f76f8:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  6f76fb:	75 83                	jne    0x6f7680
  6f76fd:	5f                   	pop    edi
  6f76fe:	5e                   	pop    esi
  6f76ff:	5b                   	pop    ebx
  6f7700:	8b e5                	mov    esp,ebp
  6f7702:	5d                   	pop    ebp
  6f7703:	c3                   	ret

# base_library_register_base_and_coroutine VA=0x00707790 raw=0x00306B90 size=42 sha256=8e10b77878812fdf6ba21d69f210b702f70728b8feb3c8db5a18e5695a126c20

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00707790 <.text+0x306790>:
  707790:	55                   	push   ebp
  707791:	8b ec                	mov    ebp,esp
  707793:	56                   	push   esi
  707794:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  707797:	8b c6                	mov    eax,esi
  707799:	e8 e2 fd ff ff       	call   0x707580
  70779e:	68 68 bc c0 00       	push   0xc0bc68
  7077a3:	68 48 37 c4 00       	push   0xc43748
  7077a8:	8b c6                	mov    eax,esi
  7077aa:	e8 e1 ed fe ff       	call   0x6f6590
  7077af:	83 c4 08             	add    esp,0x8
  7077b2:	b8 02 00 00 00       	mov    eax,0x2
  7077b7:	5e                   	pop    esi
  7077b8:	5d                   	pop    ebp
  7077b9:	c3                   	ret

# base_table_registration VA=0x00707580 raw=0x00306980 size=109 sha256=9e162cec3dfe345b74947d0766f11a51328db21fb48261c305754eeabac9d7e1

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00707580 <.text+0x306580>:
  707580:	55                   	push   ebp
  707581:	8b ec                	mov    ebp,esp
  707583:	83 e4 f8             	and    esp,0xfffffff8
  707586:	83 ec 14             	sub    esp,0x14
  707589:	53                   	push   ebx
  70758a:	56                   	push   esi
  70758b:	8b f0                	mov    esi,eax
  70758d:	8b 4e 48             	mov    ecx,DWORD PTR [esi+0x48]
  707590:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  707593:	57                   	push   edi
  707594:	8d 7e 48             	lea    edi,[esi+0x48]
  707597:	89 08                	mov    DWORD PTR [eax],ecx
  707599:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  70759c:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  70759f:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  7075a2:	6a 02                	push   0x2
  7075a4:	68 10 37 c4 00       	push   0xc43710
  7075a9:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  7075ac:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  7075b0:	56                   	push   esi
  7075b1:	e8 ba 76 ff ff       	call   0x6fec70
  7075b6:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  7075b9:	83 c4 0c             	add    esp,0xc
  7075bc:	83 ea 10             	sub    edx,0x10
  7075bf:	52                   	push   edx
  7075c0:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  7075c4:	8d 44 24 14          	lea    eax,[esp+0x14]
  7075c8:	50                   	push   eax
  7075c9:	57                   	push   edi
  7075ca:	56                   	push   esi
  7075cb:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  7075d2:	00 
  7075d3:	e8 c8 43 ff ff       	call   0x6fb9a0
  7075d8:	83 46 08 f0          	add    DWORD PTR [esi+0x8],0xfffffff0
  7075dc:	68 90 bb c0 00       	push   0xc0bb90
  7075e1:	68 10 37 c4 00       	push   0xc43710
  7075e6:	8b c6                	mov    eax,esi
  7075e8:	e8 a3 ef fe ff       	call   0x6f6590

# manager_and_tutorial_receive_global_wrapper VA=0x0048D73E raw=0x0008CB3E size=165 sha256=5e77b168796541d49a33767f8788da5abac70327a6930ee4ac54465774f9ddce

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048d73e <.text+0x8c73e>:
  48d73e:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  48d745:	75 24                	jne    0x48d76b
  48d747:	09 3d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,edi
  48d74d:	c7 44 24 70 37 00 00 	mov    DWORD PTR [esp+0x70],0x37
  48d754:	00 
  48d755:	e8 16 2a 0d 00       	call   0x560170
  48d75a:	68 10 d1 bc 00       	push   0xbcd110
  48d75f:	e8 b6 4b 40 00       	call   0x89231a
  48d764:	83 c4 04             	add    esp,0x4
  48d767:	89 5c 24 70          	mov    DWORD PTR [esp+0x70],ebx
  48d76b:	be c8 f3 fd 00       	mov    esi,0xfdf3c8
  48d770:	b8 c0 73 fb 00       	mov    eax,0xfb73c0
  48d775:	e8 86 2e 0d 00       	call   0x560600
  48d77a:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  48d781:	75 24                	jne    0x48d7a7
  48d783:	09 3d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,edi
  48d789:	c7 44 24 70 38 00 00 	mov    DWORD PTR [esp+0x70],0x38
  48d790:	00 
  48d791:	e8 ea 6b 26 00       	call   0x6f4380
  48d796:	68 d0 e6 bc 00       	push   0xbce6d0
  48d79b:	e8 7a 4b 40 00       	call   0x89231a
  48d7a0:	83 c4 04             	add    esp,0x4
  48d7a3:	89 5c 24 70          	mov    DWORD PTR [esp+0x70],ebx
  48d7a7:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  48d7ae:	75 24                	jne    0x48d7d4
  48d7b0:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  48d7b6:	c7 44 24 70 39 00 00 	mov    DWORD PTR [esp+0x70],0x39
  48d7bd:	00 
  48d7be:	e8 ed d6 fe ff       	call   0x47aeb0
  48d7c3:	68 70 db bc 00       	push   0xbcdb70
  48d7c8:	e8 4d 4b 40 00       	call   0x89231a
  48d7cd:	83 c4 04             	add    esp,0x4
  48d7d0:	89 5c 24 70          	mov    DWORD PTR [esp+0x70],ebx
  48d7d4:	be c8 f3 fd 00       	mov    esi,0xfdf3c8
  48d7d9:	b8 84 0f fc 00       	mov    eax,0xfc0f84
  48d7de:	e8 fd b0 01 00       	call   0x4a88e0

# manager_wrapper_assignment VA=0x00560600 raw=0x0015FA00 size=33 sha256=c479cbd8787fd94562f89f20d10b79a5ab01ee0a3033b22dce0c11bcbffcd2f3

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

# manager_four_script_loads VA=0x0056078F raw=0x0015FB8F size=52 sha256=d90e79c732acea97beb9f1823dfd173822a3fea554fc0abaa4bc9501e30af0a0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0056078f <.text+0x15f78f>:
  56078f:	68 c8 55 c0 00       	push   0xc055c8
  560794:	8b ce                	mov    ecx,esi
  560796:	e8 b5 42 19 00       	call   0x6f4a50
  56079b:	68 b0 55 c0 00       	push   0xc055b0
  5607a0:	8b ce                	mov    ecx,esi
  5607a2:	e8 a9 42 19 00       	call   0x6f4a50
  5607a7:	68 bc 55 c0 00       	push   0xc055bc
  5607ac:	8b ce                	mov    ecx,esi
  5607ae:	e8 9d 42 19 00       	call   0x6f4a50
  5607b3:	68 58 06 c1 00       	push   0xc10658
  5607b8:	8b ce                	mov    ecx,esi
  5607ba:	e8 91 42 19 00       	call   0x6f4a50
  5607bf:	8b e5                	mov    esp,ebp
  5607c1:	5d                   	pop    ebp
  5607c2:	c3                   	ret

# Q_table_same_wrapper VA=0x00565E40 raw=0x00165240 size=213 sha256=8799844b6771a4b2652be2e4442053f1058ba8213881942a991e94945038efdb

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00565e40 <.text+0x164e40>:
  565e40:	55                   	push   ebp
  565e41:	8b ec                	mov    ebp,esp
  565e43:	51                   	push   ecx
  565e44:	53                   	push   ebx
  565e45:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  565e48:	56                   	push   esi
  565e49:	8b 33                	mov    esi,DWORD PTR [ebx]
  565e4b:	a3 78 27 fe 00       	mov    ds:0xfe2778,eax
  565e50:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  565e53:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  565e56:	57                   	push   edi
  565e57:	89 1d 74 27 fe 00    	mov    DWORD PTR ds:0xfe2774,ebx
  565e5d:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  565e60:	72 07                	jb     0x565e69
  565e62:	8b c6                	mov    eax,esi
  565e64:	e8 37 55 19 00       	call   0x6fb3a0
  565e69:	8b 7e 08             	mov    edi,DWORD PTR [esi+0x8]
  565e6c:	6a 00                	push   0x0
  565e6e:	6a 00                	push   0x0
  565e70:	56                   	push   esi
  565e71:	e8 2a 3b 19 00       	call   0x6f99a0
  565e76:	89 07                	mov    DWORD PTR [edi],eax
  565e78:	c7 47 08 05 00 00 00 	mov    DWORD PTR [edi+0x8],0x5
  565e7f:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  565e83:	8b 33                	mov    esi,DWORD PTR [ebx]
  565e85:	83 c4 0c             	add    esp,0xc
  565e88:	bf 04 06 c1 00       	mov    edi,0xc10604
  565e8d:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  565e92:	e8 f9 f8 18 00       	call   0x6f5790
  565e97:	8b 33                	mov    esi,DWORD PTR [ebx]
  565e99:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  565e9e:	e8 dd f7 18 00       	call   0x6f5680
  565ea3:	8b 03                	mov    eax,DWORD PTR [ebx]
  565ea5:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  565ea8:	83 e8 10             	sub    eax,0x10
  565eab:	bf f0 ff ff ff       	mov    edi,0xfffffff0
  565eb0:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  565eb5:	74 06                	je     0x565ebd
  565eb7:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  565ebb:	74 17                	je     0x565ed4
  565ebd:	68 04 06 c1 00       	push   0xc10604
  565ec2:	68 c4 26 c4 00       	push   0xc426c4
  565ec7:	e8 f1 d1 32 00       	call   0x8930bd
  565ecc:	8b 03                	mov    eax,DWORD PTR [ebx]
  565ece:	83 c4 08             	add    esp,0x8
  565ed1:	01 78 08             	add    DWORD PTR [eax+0x8],edi
  565ed4:	8b 33                	mov    esi,DWORD PTR [ebx]
  565ed6:	68 24 62 c0 00       	push   0xc06224
  565edb:	e8 30 f6 18 00       	call   0x6f5510
  565ee0:	8b 33                	mov    esi,DWORD PTR [ebx]
  565ee2:	83 c4 04             	add    esp,0x4
  565ee5:	6a 00                	push   0x0
  565ee7:	68 90 87 56 00       	push   0x568790
  565eec:	e8 bf f6 18 00       	call   0x6f55b0
  565ef1:	8b 13                	mov    edx,DWORD PTR [ebx]
  565ef3:	52                   	push   edx
  565ef4:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  565ef9:	e8 f2 f8 18 00       	call   0x6f57f0
  565efe:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  565f00:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  565f03:	83 c4 0c             	add    esp,0xc
  565f06:	01 7b 08             	add    DWORD PTR [ebx+0x8],edi
  565f09:	5f                   	pop    edi
  565f0a:	5e                   	pop    esi
  565f0b:	c7 00 04 06 c1 00    	mov    DWORD PTR [eax],0xc10604
  565f11:	5b                   	pop    ebx
  565f12:	59                   	pop    ecx
  565f13:	5d                   	pop    ebp
  565f14:	c3                   	ret

# independent_prepass_Lua_state VA=0x0055C610 raw=0x0015BA10 size=229 sha256=2f563d7bc243c40776cefacdeb19ae67cd35a4534fa417fd02e98fe543f6c427

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055c610 <.text+0x15b610>:
  55c610:	55                   	push   ebp
  55c611:	8b ec                	mov    ebp,esp
  55c613:	6a ff                	push   0xffffffff
  55c615:	68 a8 89 93 00       	push   0x9389a8
  55c61a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55c620:	50                   	push   eax
  55c621:	83 ec 14             	sub    esp,0x14
  55c624:	53                   	push   ebx
  55c625:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55c62a:	33 c5                	xor    eax,ebp
  55c62c:	50                   	push   eax
  55c62d:	8d 45 f4             	lea    eax,[ebp-0xc]
  55c630:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55c636:	33 db                	xor    ebx,ebx
  55c638:	6a 18                	push   0x18
  55c63a:	c7 45 ec ec 1e fe 00 	mov    DWORD PTR [ebp-0x14],0xfe1eec
  55c641:	89 1d fc 1e fe 00    	mov    DWORD PTR ds:0xfe1efc,ebx
  55c647:	e8 1c 4c 33 00       	call   0x891268
  55c64c:	83 c4 04             	add    esp,0x4
  55c64f:	3b c3                	cmp    eax,ebx
  55c651:	0f 84 9e 00 00 00    	je     0x55c6f5
  55c657:	a3 f8 1e fe 00       	mov    ds:0xfe1ef8,eax
  55c65c:	89 00                	mov    DWORD PTR [eax],eax
  55c65e:	a1 f8 1e fe 00       	mov    eax,ds:0xfe1ef8
  55c663:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  55c666:	a1 f8 1e fe 00       	mov    eax,ds:0xfe1ef8
  55c66b:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  55c66e:	8b 0d f8 1e fe 00    	mov    ecx,DWORD PTR ds:0xfe1ef8
  55c674:	b0 01                	mov    al,0x1
  55c676:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  55c679:	8b 15 f8 1e fe 00    	mov    edx,DWORD PTR ds:0xfe1ef8
  55c67f:	88 42 15             	mov    BYTE PTR [edx+0x15],al
  55c682:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  55c685:	c7 05 18 1f fe 00 0f 	mov    DWORD PTR ds:0xfe1f18,0xf
  55c68c:	00 00 00 
  55c68f:	89 1d 14 1f fe 00    	mov    DWORD PTR ds:0xfe1f14,ebx
  55c695:	88 1d 04 1f fe 00    	mov    BYTE PTR ds:0xfe1f04,bl
  55c69b:	88 45 fc             	mov    BYTE PTR [ebp-0x4],al
  55c69e:	e8 0d ae 19 00       	call   0x6f74b0
  55c6a3:	3b c3                	cmp    eax,ebx
  55c6a5:	74 0a                	je     0x55c6b1
  55c6a7:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  55c6aa:	c7 41 58 a0 71 6f 00 	mov    DWORD PTR [ecx+0x58],0x6f71a0
  55c6b1:	6a 0c                	push   0xc
  55c6b3:	a3 ec 1e fe 00       	mov    ds:0xfe1eec,eax
  55c6b8:	e8 ab 4b 33 00       	call   0x891268
  55c6bd:	83 c4 04             	add    esp,0x4
  55c6c0:	3b c3                	cmp    eax,ebx
  55c6c2:	74 10                	je     0x55c6d4
  55c6c4:	8b 15 ec 1e fe 00    	mov    edx,DWORD PTR ds:0xfe1eec
  55c6ca:	89 10                	mov    DWORD PTR [eax],edx
  55c6cc:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  55c6cf:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  55c6d2:	eb 02                	jmp    0x55c6d6
  55c6d4:	33 c0                	xor    eax,eax
  55c6d6:	a3 f0 1e fe 00       	mov    ds:0xfe1ef0,eax
  55c6db:	e8 00 11 00 00       	call   0x55d7e0
  55c6e0:	b8 ec 1e fe 00       	mov    eax,0xfe1eec
  55c6e5:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  55c6e8:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55c6ef:	59                   	pop    ecx
  55c6f0:	5b                   	pop    ebx
  55c6f1:	8b e5                	mov    esp,ebp
  55c6f3:	5d                   	pop    ebp
  55c6f4:	c3                   	ret

# prepass_native_bindings_and_load VA=0x0055D6A0 raw=0x0015CAA0 size=307 sha256=3ba41e59f3fd8e858ada7d94ca290144d24b17c955f9e7e7798540b516bf99ca

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055d6a0 <.text+0x15c6a0>:
  55d6a0:	55                   	push   ebp
  55d6a1:	8b ec                	mov    ebp,esp
  55d6a3:	51                   	push   ecx
  55d6a4:	53                   	push   ebx
  55d6a5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  55d6a8:	56                   	push   esi
  55d6a9:	8d 43 08             	lea    eax,[ebx+0x8]
  55d6ac:	57                   	push   edi
  55d6ad:	50                   	push   eax
  55d6ae:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  55d6b1:	e8 2a 0c 00 00       	call   0x55e2e0
  55d6b6:	83 c4 04             	add    esp,0x4
  55d6b9:	6a 00                	push   0x0
  55d6bb:	68 75 23 bf 00       	push   0xbf2375
  55d6c0:	8d 4b 18             	lea    ecx,[ebx+0x18]
  55d6c3:	e8 a8 53 ea ff       	call   0x402a70
  55d6c8:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d6cb:	8b 30                	mov    esi,DWORD PTR [eax]
  55d6cd:	6a 00                	push   0x0
  55d6cf:	68 40 c9 55 00       	push   0x55c940
  55d6d4:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d6d7:	e8 d4 7e 19 00       	call   0x6f55b0
  55d6dc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  55d6df:	8b 31                	mov    esi,DWORD PTR [ecx]
  55d6e1:	bf 30 02 c1 00       	mov    edi,0xc10230
  55d6e6:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d6eb:	e8 a0 80 19 00       	call   0x6f5790
  55d6f0:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d6f3:	8b 30                	mov    esi,DWORD PTR [eax]
  55d6f5:	6a 00                	push   0x0
  55d6f7:	68 e0 cc 55 00       	push   0x55cce0
  55d6fc:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d6ff:	e8 ac 7e 19 00       	call   0x6f55b0
  55d704:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  55d707:	8b 32                	mov    esi,DWORD PTR [edx]
  55d709:	bf 40 02 c1 00       	mov    edi,0xc10240
  55d70e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d713:	e8 78 80 19 00       	call   0x6f5790
  55d718:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d71b:	8b 30                	mov    esi,DWORD PTR [eax]
  55d71d:	6a 00                	push   0x0
  55d71f:	68 d0 ce 55 00       	push   0x55ced0
  55d724:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d727:	e8 84 7e 19 00       	call   0x6f55b0
  55d72c:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  55d72f:	8b 31                	mov    esi,DWORD PTR [ecx]
  55d731:	bf 4c 02 c1 00       	mov    edi,0xc1024c
  55d736:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d73b:	e8 50 80 19 00       	call   0x6f5790
  55d740:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d743:	8b 30                	mov    esi,DWORD PTR [eax]
  55d745:	6a 00                	push   0x0
  55d747:	68 20 d2 55 00       	push   0x55d220
  55d74c:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d74f:	e8 5c 7e 19 00       	call   0x6f55b0
  55d754:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  55d757:	8b 32                	mov    esi,DWORD PTR [edx]
  55d759:	bf 58 02 c1 00       	mov    edi,0xc10258
  55d75e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d763:	e8 28 80 19 00       	call   0x6f5790
  55d768:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d76b:	8b 30                	mov    esi,DWORD PTR [eax]
  55d76d:	6a 00                	push   0x0
  55d76f:	68 60 d5 55 00       	push   0x55d560
  55d774:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d777:	e8 34 7e 19 00       	call   0x6f55b0
  55d77c:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  55d77f:	8b 31                	mov    esi,DWORD PTR [ecx]
  55d781:	bf 64 02 c1 00       	mov    edi,0xc10264
  55d786:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d78b:	e8 00 80 19 00       	call   0x6f5790
  55d790:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d793:	8b 30                	mov    esi,DWORD PTR [eax]
  55d795:	6a 00                	push   0x0
  55d797:	68 e0 d5 55 00       	push   0x55d5e0
  55d79c:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d79f:	e8 0c 7e 19 00       	call   0x6f55b0
  55d7a4:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  55d7a7:	8b 32                	mov    esi,DWORD PTR [edx]
  55d7a9:	83 c4 30             	add    esp,0x30
  55d7ac:	bf 70 02 c1 00       	mov    edi,0xc10270
  55d7b1:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d7b6:	e8 d5 7f 19 00       	call   0x6f5790
  55d7bb:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  55d7be:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  55d7c1:	50                   	push   eax
  55d7c2:	e8 89 72 19 00       	call   0x6f4a50
  55d7c7:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  55d7ca:	5f                   	pop    edi
  55d7cb:	5e                   	pop    esi
  55d7cc:	5b                   	pop    ebx
  55d7cd:	8b e5                	mov    esp,ebp
  55d7cf:	5d                   	pop    ebp
  55d7d0:	c2 08 00             	ret    0x8

# prepass_wait_yield_stubs VA=0x0055D7E0 raw=0x0015CBE0 size=83 sha256=9b0184b131054806ad466664353f5c31dfd8eb0c1434fbad215ec0e2b492771f

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055d7e0 <.text+0x15c7e0>:
  55d7e0:	55                   	push   ebp
  55d7e1:	8b ec                	mov    ebp,esp
  55d7e3:	51                   	push   ecx
  55d7e4:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d7e9:	53                   	push   ebx
  55d7ea:	56                   	push   esi
  55d7eb:	8b 30                	mov    esi,DWORD PTR [eax]
  55d7ed:	57                   	push   edi
  55d7ee:	6a 00                	push   0x0
  55d7f0:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d7f5:	8b d8                	mov    ebx,eax
  55d7f7:	e8 b4 7d 19 00       	call   0x6f55b0
  55d7fc:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d7fe:	bf 7c 02 c1 00       	mov    edi,0xc1027c
  55d803:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d808:	e8 83 7f 19 00       	call   0x6f5790
  55d80d:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d812:	8b 30                	mov    esi,DWORD PTR [eax]
  55d814:	6a 00                	push   0x0
  55d816:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d81b:	8b d8                	mov    ebx,eax
  55d81d:	e8 8e 7d 19 00       	call   0x6f55b0
  55d822:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d824:	bf 84 02 c1 00       	mov    edi,0xc10284
  55d829:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d82e:	e8 5d 7f 19 00       	call   0x6f5790

# formal_scene_load_uses_manager_wrapper VA=0x00561C67 raw=0x00161067 size=27 sha256=50330781b9ab10fa9a21881cc3bc48683a4af3583cb9136d5558686537613442

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561c67 <.text+0x160c67>:
  561c67:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  561c6b:	bf 10 00 00 00       	mov    edi,0x10
  561c70:	39 7c 24 34          	cmp    DWORD PTR [esp+0x34],edi
  561c74:	73 04                	jae    0x561c7a
  561c76:	8d 44 24 20          	lea    eax,[esp+0x20]
  561c7a:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  561c7c:	50                   	push   eax
  561c7d:	e8 ce 2d 19 00       	call   0x6f4a50

# FB73F0_other_object_construction VA=0x00560237 raw=0x0015F637 size=49 sha256=7cc963600e6237ff0c540f390e59eac54574541ddc4dbe3fe57c921526d89ef3

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00560237 <.text+0x15f237>:
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

# FB73F0_float_string_object VA=0x007CD2B0 raw=0x003CC6B0 size=89 sha256=facf88d4922e946e510623d6f600f4ae6a2118247155cdd734114b16580f0116

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007cd2b0 <.text+0x3cc2b0>:
  7cd2b0:	d9 ee                	fldz
  7cd2b2:	8d 4e 2c             	lea    ecx,[esi+0x2c]
  7cd2b5:	d9 16                	fst    DWORD PTR [esi]
  7cd2b7:	6a 07                	push   0x7
  7cd2b9:	d9 56 04             	fst    DWORD PTR [esi+0x4]
  7cd2bc:	68 c0 f6 c0 00       	push   0xc0f6c0
  7cd2c1:	d9 56 08             	fst    DWORD PTR [esi+0x8]
  7cd2c4:	d9 05 a8 57 c5 00    	fld    DWORD PTR ds:0xc557a8
  7cd2ca:	d9 5e 0c             	fstp   DWORD PTR [esi+0xc]
  7cd2cd:	d9 56 10             	fst    DWORD PTR [esi+0x10]
  7cd2d0:	d9 56 14             	fst    DWORD PTR [esi+0x14]
  7cd2d3:	d9 56 18             	fst    DWORD PTR [esi+0x18]
  7cd2d6:	d9 5e 1c             	fstp   DWORD PTR [esi+0x1c]
  7cd2d9:	d9 e8                	fld1
  7cd2db:	d9 5e 20             	fstp   DWORD PTR [esi+0x20]
  7cd2de:	d9 05 34 58 c5 00    	fld    DWORD PTR ds:0xc55834
  7cd2e4:	d9 5e 24             	fstp   DWORD PTR [esi+0x24]
  7cd2e7:	d9 05 30 58 c5 00    	fld    DWORD PTR ds:0xc55830
  7cd2ed:	d9 5e 28             	fstp   DWORD PTR [esi+0x28]
  7cd2f0:	c7 41 14 0f 00 00 00 	mov    DWORD PTR [ecx+0x14],0xf
  7cd2f7:	c7 41 10 00 00 00 00 	mov    DWORD PTR [ecx+0x10],0x0
  7cd2fe:	c6 01 00             	mov    BYTE PTR [ecx],0x0
  7cd301:	e8 6a 57 c3 ff       	call   0x402a70
  7cd306:	8b c6                	mov    eax,esi
  7cd308:	c3                   	ret

# new_Lua_state_allocation VA=0x006F74B0 raw=0x002F68B0 size=295 sha256=c0d2ae5347a32f3f4a31195bdb6b62fe3cb9fd74309efe4200996eb4a4892417

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f74b0 <.text+0x2f64b0>:
  6f74b0:	51                   	push   ecx
  6f74b1:	53                   	push   ebx
  6f74b2:	56                   	push   esi
  6f74b3:	68 78 01 00 00       	push   0x178
  6f74b8:	33 db                	xor    ebx,ebx
  6f74ba:	53                   	push   ebx
  6f74bb:	e8 a6 05 1a 00       	call   0x897a66
  6f74c0:	8b f0                	mov    esi,eax
  6f74c2:	83 c4 08             	add    esp,0x8
  6f74c5:	3b f3                	cmp    esi,ebx
  6f74c7:	75 06                	jne    0x6f74cf
  6f74c9:	33 c0                	xor    eax,eax
  6f74cb:	5e                   	pop    esi
  6f74cc:	5b                   	pop    ebx
  6f74cd:	59                   	pop    ecx
  6f74ce:	c3                   	ret
  6f74cf:	8d 46 78             	lea    eax,[esi+0x78]
  6f74d2:	89 1e                	mov    DWORD PTR [esi],ebx
  6f74d4:	c6 46 04 08          	mov    BYTE PTR [esi+0x4],0x8
  6f74d8:	c6 40 14 21          	mov    BYTE PTR [eax+0x14],0x21
  6f74dc:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  6f74df:	89 5e 20             	mov    DWORD PTR [esi+0x20],ebx
  6f74e2:	89 5e 2c             	mov    DWORD PTR [esi+0x2c],ebx
  6f74e5:	89 5e 70             	mov    DWORD PTR [esi+0x70],ebx
  6f74e8:	89 5e 44             	mov    DWORD PTR [esi+0x44],ebx
  6f74eb:	89 5e 3c             	mov    DWORD PTR [esi+0x3c],ebx
  6f74ee:	89 5e 40             	mov    DWORD PTR [esi+0x40],ebx
  6f74f1:	89 5e 68             	mov    DWORD PTR [esi+0x68],ebx
  6f74f4:	89 5e 30             	mov    DWORD PTR [esi+0x30],ebx
  6f74f7:	c7 46 36 00 00 00 01 	mov    DWORD PTR [esi+0x36],0x1000000
  6f74fe:	66 c7 46 05 61 00    	mov    WORD PTR [esi+0x5],0x61
  6f7504:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  6f7507:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
  6f750a:	89 5e 18             	mov    DWORD PTR [esi+0x18],ebx
  6f750d:	89 5e 74             	mov    DWORD PTR [esi+0x74],ebx
  6f7510:	89 5e 50             	mov    DWORD PTR [esi+0x50],ebx
  6f7513:	8d 48 78             	lea    ecx,[eax+0x78]
  6f7516:	33 d2                	xor    edx,edx
  6f7518:	66 89 56 34          	mov    WORD PTR [esi+0x34],dx
  6f751c:	89 88 88 00 00 00    	mov    DWORD PTR [eax+0x88],ecx
  6f7522:	89 88 8c 00 00 00    	mov    DWORD PTR [eax+0x8c],ecx
  6f7528:	c7 40 0c 70 71 6f 00 	mov    DWORD PTR [eax+0xc],0x6f7170
  6f752f:	89 58 10             	mov    DWORD PTR [eax+0x10],ebx
  6f7532:	89 70 70             	mov    DWORD PTR [eax+0x70],esi
  6f7535:	89 58 40             	mov    DWORD PTR [eax+0x40],ebx
  6f7538:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  6f753b:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  6f753e:	89 18                	mov    DWORD PTR [eax],ebx
  6f7540:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  6f7543:	89 59 68             	mov    DWORD PTR [ecx+0x68],ebx
  6f7546:	89 70 1c             	mov    DWORD PTR [eax+0x1c],esi
  6f7549:	89 58 34             	mov    DWORD PTR [eax+0x34],ebx
  6f754c:	89 58 3c             	mov    DWORD PTR [eax+0x3c],ebx
  6f754f:	89 58 58             	mov    DWORD PTR [eax+0x58],ebx
  6f7552:	88 58 15             	mov    BYTE PTR [eax+0x15],bl
  6f7555:	89 58 18             	mov    DWORD PTR [eax+0x18],ebx
  6f7558:	89 58 24             	mov    DWORD PTR [eax+0x24],ebx
  6f755b:	89 58 28             	mov    DWORD PTR [eax+0x28],ebx
  6f755e:	89 58 2c             	mov    DWORD PTR [eax+0x2c],ebx
  6f7561:	89 58 30             	mov    DWORD PTR [eax+0x30],ebx
  6f7564:	c7 40 44 78 01 00 00 	mov    DWORD PTR [eax+0x44],0x178
  6f756b:	89 58 4c             	mov    DWORD PTR [eax+0x4c],ebx
  6f756e:	8d 48 1c             	lea    ecx,[eax+0x1c]
  6f7571:	89 48 20             	mov    DWORD PTR [eax+0x20],ecx
  6f7574:	53                   	push   ebx
  6f7575:	b9 c8 00 00 00       	mov    ecx,0xc8
  6f757a:	89 48 50             	mov    DWORD PTR [eax+0x50],ecx
  6f757d:	89 48 54             	mov    DWORD PTR [eax+0x54],ecx
  6f7580:	68 80 72 6f 00       	push   0x6f7280
  6f7585:	56                   	push   esi
  6f7586:	89 98 98 00 00 00    	mov    DWORD PTR [eax+0x98],ebx
  6f758c:	89 98 9c 00 00 00    	mov    DWORD PTR [eax+0x9c],ebx
  6f7592:	89 98 a0 00 00 00    	mov    DWORD PTR [eax+0xa0],ebx
  6f7598:	89 98 a4 00 00 00    	mov    DWORD PTR [eax+0xa4],ebx
  6f759e:	89 98 a8 00 00 00    	mov    DWORD PTR [eax+0xa8],ebx
  6f75a4:	89 98 ac 00 00 00    	mov    DWORD PTR [eax+0xac],ebx
  6f75aa:	89 98 b0 00 00 00    	mov    DWORD PTR [eax+0xb0],ebx
  6f75b0:	89 98 b4 00 00 00    	mov    DWORD PTR [eax+0xb4],ebx
  6f75b6:	89 98 b8 00 00 00    	mov    DWORD PTR [eax+0xb8],ebx
  6f75bc:	e8 df 65 00 00       	call   0x6fdba0
  6f75c1:	83 c4 0c             	add    esp,0xc
  6f75c4:	85 c0                	test   eax,eax
  6f75c6:	74 09                	je     0x6f75d1
  6f75c8:	8b c6                	mov    eax,esi
  6f75ca:	e8 31 fd ff ff       	call   0x6f7300
  6f75cf:	33 f6                	xor    esi,esi
  6f75d1:	8b c6                	mov    eax,esi
  6f75d3:	5e                   	pop    esi
  6f75d4:	5b                   	pop    ebx
  6f75d5:	59                   	pop    ecx
  6f75d6:	c3                   	ret

# Lua_state_close VA=0x006F75F0 raw=0x002F69F0 size=98 sha256=5b1dcae2cd23466959da92f18b84e56b995ec2d3b7696acb48e48944112bc575

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f75f0 <.text+0x2f65f0>:
  6f75f0:	55                   	push   ebp
  6f75f1:	8b ec                	mov    ebp,esp
  6f75f3:	83 e4 f8             	and    esp,0xfffffff8
  6f75f6:	51                   	push   ecx
  6f75f7:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  6f75fa:	57                   	push   edi
  6f75fb:	8b 79 70             	mov    edi,DWORD PTR [ecx+0x70]
  6f75fe:	8b 57 20             	mov    edx,DWORD PTR [edi+0x20]
  6f7601:	52                   	push   edx
  6f7602:	e8 59 62 00 00       	call   0x6fd860
  6f7607:	83 c4 04             	add    esp,0x4
  6f760a:	6a 01                	push   0x1
  6f760c:	57                   	push   edi
  6f760d:	e8 1e 2b 00 00       	call   0x6fa130
  6f7612:	83 c4 08             	add    esp,0x8
  6f7615:	c7 47 74 00 00 00 00 	mov    DWORD PTR [edi+0x74],0x0
  6f761c:	8d 64 24 00          	lea    esp,[esp+0x0]
  6f7620:	8b 47 28             	mov    eax,DWORD PTR [edi+0x28]
  6f7623:	89 47 14             	mov    DWORD PTR [edi+0x14],eax
  6f7626:	8b 00                	mov    eax,DWORD PTR [eax]
  6f7628:	89 47 08             	mov    DWORD PTR [edi+0x8],eax
  6f762b:	89 47 0c             	mov    DWORD PTR [edi+0xc],eax
  6f762e:	33 c0                	xor    eax,eax
  6f7630:	50                   	push   eax
  6f7631:	68 e0 75 6f 00       	push   0x6f75e0
  6f7636:	57                   	push   edi
  6f7637:	89 47 34             	mov    DWORD PTR [edi+0x34],eax
  6f763a:	e8 61 65 00 00       	call   0x6fdba0
  6f763f:	83 c4 0c             	add    esp,0xc
  6f7642:	85 c0                	test   eax,eax
  6f7644:	75 da                	jne    0x6f7620
  6f7646:	8b c7                	mov    eax,edi
  6f7648:	e8 b3 fc ff ff       	call   0x6f7300
  6f764d:	5f                   	pop    edi
  6f764e:	8b e5                	mov    esp,ebp
  6f7650:	5d                   	pop    ebp
  6f7651:	c3                   	ret

# base_and_coroutine_registrations VA=0x00C0BB90 raw=0x0080A190 size=272 sha256=4d0739a4ccd26ff370c754e58092c951d9acc7e6bc1c915ba6422039b2f70fc7
ac34c400c06770009c34c400305f70009434c400406770008c34c400505670008434c400f05e7000bc2ec400705a7000842ec400405770007834c400d06470007034c400206670006434c4000064700004edc000a06070005c34c400c06a70005434c400705370004834c400605c70004034c400105d70003834c400f05d70003034c400d0697000702ec400d05a70004c2ec400305870002434c400c0547000ec34c400706c700008b8bf00206070001c34c400706870001434c400706b700000000000000000000c34c4000034c400f833c400f033c400e833c40080737000e033c400307270000c34c400c074700050eac00070707000d833c400507470008402c100807470000000000000000000

# library_open_table VA=0x00C0C0D8 raw=0x0080A6D8 size=72 sha256=3acadfbfc310e36d12d6e2a8d705addb7a9e7612734ffdaf9543d0119992074c
7523bf00907770008c28c400b0b370008428c400f0cb70008028c400309270007c28c400d09d70007428c400c05270006c28c400d02870006428c400001e70000000000000000000

# Lua_version_identity VA=0x00C0C120 raw=0x0080A720 size=135 sha256=5ac2828f107763f5c0e16416999f553fc0a2ebad1c306bf9cf7b78d86bfbb411
244c75613a204c756120352e312e3320436f707972696768742028432920313939342d32303038204c75612e6f72672c205055432d52696f20240a24417574686f72733a20522e204965727573616c696d736368792c204c2e20482e206465204669677565697265646f202620572e2043656c657320240a2455524c3a207777772e6c75612e6f

# Lua_token_pointer_table VA=0x00C0BEC0 raw=0x0080A4C0 size=124 sha256=6731cf3784f45f00dbb86930cfcde2f4ae618aff93dbce7091984107b0b73431
e02cc400d82cc400d42cc400cc2cc400c42cc400c02cc4003494bf00bc2cc4001c2cc400b82cc400b42cc400f428c400442cc400b02cc400ac2cc400a42cc4009c2cc400942cc4003c94bf008c2cc400842cc400802cc400a028c4007c2cc400782cc400742cc400702cc400642cc4005c2cc400502cc400482cc400

# global_DoFile_name VA=0x00C4257C raw=0x00840B7C size=27 sha256=8f40bf8ccd797f60ce3cbb3822b64453ef99eb5c7f63e406e24c8608fa0892bf
5072696e74537461636b53746174757300000000446f46696c6500

# core_script_names VA=0x00C055B0 raw=0x00803BB0 size=38 sha256=ed3b98240b020c4fa78b0e99cfa3f50eaa4e96a4264880ba009a3aad97db94bf
426f6f742e6c7561000000004c6f6769632e6c7561000000436f726f7574696e652e6c756100

# qbase_script_name VA=0x00C10658 raw=0x0080EC58 size=16 sha256=9adac42f4232c3a29bf31c289341409365f74fd6016443d3813a4345343749e2
4576656e742f71626173652e6c756100

# Q_table_name VA=0x00C10604 raw=0x0080EC04 size=2 sha256=94e706dc7b0e756b561c8c4ad4d31b476077dbf9486f9787d8530fb67f91cff8
5100

# lb_table_name VA=0x00C06220 raw=0x00804820 size=3 sha256=bdc3d6f6507ff52b3239d014fcafb7f4878ac0df36f9e2cac80bb61d9ae1c81b
6c6200

# lb_DoFile_name VA=0x00D6AE14 raw=0x00968614 size=7 sha256=a5e4fb5132e48605eb0b548d0adcc389b49f75839731ca4944a7ff160446b97d
446f46696c6500

# binary_error_strings VA=0x00C43E20 raw=0x00842420 size=116 sha256=a410a9ecc86ff1fe40e44412ee4829223101dc751b21fc18c3c3dd32dd337fa1
25733a20257320696e20707265636f6d70696c6564206368756e6b00756e657870656374656420656e64000062616420696e74656765720062616420636f6e7374616e740000000062616420636f64650000000062616420686561646572000062696e61727920737472696e670000003d3f0000

# Lua_call_error_strings VA=0x00C42B04 raw=0x00841104 size=114 sha256=25011a95a0eeb7315d324c1691b967509b36b7c891b2f8b24986af9b37036449
4320737461636b206f766572666c6f770000000063616e6e6f7420726573756d65206e6f6e2d73757370656e64656420636f726f7574696e65000000617474656d707420746f207969656c64206163726f7373206d6574616d6574686f642f432d63616c6c20626f756e6461727900005f5f

# Research group: resource

# generic-stdio-file-and-optional-content-check

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00713cc0 <.text+0x312cc0>:
  713cc0:	55                   	push   ebp
  713cc1:	8b ec                	mov    ebp,esp
  713cc3:	83 ec 24             	sub    esp,0x24
  713cc6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  713ccb:	33 c5                	xor    eax,ebp
  713ccd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  713cd0:	53                   	push   ebx
  713cd1:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  713cd4:	56                   	push   esi
  713cd5:	57                   	push   edi
  713cd6:	6a 10                	push   0x10
  713cd8:	8b f9                	mov    edi,ecx
  713cda:	e8 89 d5 17 00       	call   0x891268
  713cdf:	33 f6                	xor    esi,esi
  713ce1:	83 c4 04             	add    esp,0x4
  713ce4:	3b c6                	cmp    eax,esi
  713ce6:	74 11                	je     0x713cf9
  713ce8:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  713ceb:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  713cee:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  713cf1:	c7 00 04 42 c4 00    	mov    DWORD PTR [eax],0xc44204
  713cf7:	8b f0                	mov    esi,eax
  713cf9:	53                   	push   ebx
  713cfa:	57                   	push   edi
  713cfb:	e8 7b db 17 00       	call   0x89187b
  713d00:	83 c4 08             	add    esp,0x8
  713d03:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  713d06:	85 c0                	test   eax,eax
  713d08:	8b 06                	mov    eax,DWORD PTR [esi]
  713d0a:	8b ce                	mov    ecx,esi
  713d0c:	75 19                	jne    0x713d27
  713d0e:	8b 10                	mov    edx,DWORD PTR [eax]
  713d10:	6a 01                	push   0x1
  713d12:	ff d2                	call   edx
  713d14:	5f                   	pop    edi
  713d15:	5e                   	pop    esi
  713d16:	33 c0                	xor    eax,eax
  713d18:	5b                   	pop    ebx
  713d19:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  713d1c:	33 cd                	xor    ecx,ebp
  713d1e:	e8 de d2 17 00       	call   0x891001
  713d23:	8b e5                	mov    esp,ebp
  713d25:	5d                   	pop    ebp
  713d26:	c3                   	ret
  713d27:	8b 50 34             	mov    edx,DWORD PTR [eax+0x34]
  713d2a:	6a 02                	push   0x2
  713d2c:	6a 00                	push   0x0
  713d2e:	ff d2                	call   edx
  713d30:	8b 06                	mov    eax,DWORD PTR [esi]
  713d32:	8b 50 30             	mov    edx,DWORD PTR [eax+0x30]
  713d35:	8b ce                	mov    ecx,esi
  713d37:	ff d2                	call   edx
  713d39:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  713d3c:	8b 06                	mov    eax,DWORD PTR [esi]
  713d3e:	8b 50 34             	mov    edx,DWORD PTR [eax+0x34]
  713d41:	6a 00                	push   0x0
  713d43:	6a 00                	push   0x0
  713d45:	8b ce                	mov    ecx,esi
  713d47:	ff d2                	call   edx
  713d49:	8b 0d 1c a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba81c
  713d4f:	85 c9                	test   ecx,ecx
  713d51:	74 5d                	je     0x713db0
  713d53:	33 c0                	xor    eax,eax
  713d55:	89 45 ed             	mov    DWORD PTR [ebp-0x13],eax
  713d58:	89 45 f1             	mov    DWORD PTR [ebp-0xf],eax
  713d5b:	89 45 f5             	mov    DWORD PTR [ebp-0xb],eax
  713d5e:	66 89 45 f9          	mov    WORD PTR [ebp-0x7],ax
  713d62:	88 45 fb             	mov    BYTE PTR [ebp-0x5],al
  713d65:	8b 01                	mov    eax,DWORD PTR [ecx]
  713d67:	8b 00                	mov    eax,DWORD PTR [eax]
  713d69:	8d 55 ec             	lea    edx,[ebp-0x14]
  713d6c:	52                   	push   edx
  713d6d:	57                   	push   edi
  713d6e:	c6 45 ec 00          	mov    BYTE PTR [ebp-0x14],0x0
  713d72:	ff d0                	call   eax
  713d74:	84 c0                	test   al,al
  713d76:	74 38                	je     0x713db0
  713d78:	8b 0d 1c a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba81c
  713d7e:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  713d81:	8b 39                	mov    edi,DWORD PTR [ecx]
  713d83:	8d 55 dc             	lea    edx,[ebp-0x24]
  713d86:	52                   	push   edx
  713d87:	8b 16                	mov    edx,DWORD PTR [esi]
  713d89:	50                   	push   eax
  713d8a:	8b 42 38             	mov    eax,DWORD PTR [edx+0x38]
  713d8d:	8b ce                	mov    ecx,esi
  713d8f:	ff d0                	call   eax
  713d91:	8b 0d 1c a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba81c
  713d97:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  713d9a:	50                   	push   eax
  713d9b:	ff d2                	call   edx
  713d9d:	33 c0                	xor    eax,eax
  713d9f:	90                   	nop
  713da0:	8a 4c 05 ec          	mov    cl,BYTE PTR [ebp+eax*1-0x14]
  713da4:	3a 4c 05 dc          	cmp    cl,BYTE PTR [ebp+eax*1-0x24]
  713da8:	75 19                	jne    0x713dc3
  713daa:	40                   	inc    eax
  713dab:	83 f8 10             	cmp    eax,0x10
  713dae:	7c f0                	jl     0x713da0
  713db0:	5f                   	pop    edi
  713db1:	8b c6                	mov    eax,esi
  713db3:	5e                   	pop    esi
  713db4:	5b                   	pop    ebx
  713db5:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  713db8:	33 cd                	xor    ecx,ebp
  713dba:	e8 42 d2 17 00       	call   0x891001
  713dbf:	8b e5                	mov    esp,ebp
  713dc1:	5d                   	pop    ebp
  713dc2:	c3                   	ret
  713dc3:	8b 16                	mov    edx,DWORD PTR [esi]
  713dc5:	8b 02                	mov    eax,DWORD PTR [edx]
  713dc7:	6a 01                	push   0x1
  713dc9:	8b ce                	mov    ecx,esi
  713dcb:	ff d0                	call   eax
  713dcd:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  713dd0:	5f                   	pop    edi
  713dd1:	5e                   	pop    esi
  713dd2:	33 cd                	xor    ecx,ebp
  713dd4:	33 c0                	xor    eax,eax
  713dd6:	5b                   	pop    ebx
  713dd7:	e8 25 d2 17 00       	call   0x891001
  713ddc:	8b e5                	mov    esp,ebp
  713dde:	5d                   	pop    ebp
  713ddf:	c3                   	ret

# generic-prefix-default-initialization

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00713ff0 <.text+0x312ff0>:
  713ff0:	b8 01 00 00 00       	mov    eax,0x1
  713ff5:	84 05 4c 36 fe 00    	test   BYTE PTR ds:0xfe364c,al
  713ffb:	75 21                	jne    0x71401e
  713ffd:	09 05 4c 36 fe 00    	or     DWORD PTR ds:0xfe364c,eax
  714003:	68 00 01 00 00       	push   0x100
  714008:	6a 00                	push   0x0
  71400a:	68 48 35 fe 00       	push   0xfe3548
  71400f:	c6 05 48 36 fe 00 00 	mov    BYTE PTR ds:0xfe3648,0x0
  714016:	e8 45 a8 18 00       	call   0x89e860
  71401b:	83 c4 0c             	add    esp,0xc
  71401e:	b8 48 35 fe 00       	mov    eax,0xfe3548
  714023:	c3                   	ret

# generic-prefix-and-direct-file-fallback

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00714030 <.text+0x313030>:
  714030:	55                   	push   ebp
  714031:	8b ec                	mov    ebp,esp
  714033:	6a ff                	push   0xffffffff
  714035:	68 4b 97 91 00       	push   0x91974b
  71403a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  714040:	50                   	push   eax
  714041:	b8 28 10 00 00       	mov    eax,0x1028
  714046:	e8 25 c6 19 00       	call   0x8b0670
  71404b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  714050:	33 c5                	xor    eax,ebp
  714052:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  714055:	53                   	push   ebx
  714056:	56                   	push   esi
  714057:	50                   	push   eax
  714058:	8d 45 f4             	lea    eax,[ebp-0xc]
  71405b:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  714061:	8b 1d 4c 36 fe 00    	mov    ebx,DWORD PTR ds:0xfe364c
  714067:	8b f1                	mov    esi,ecx
  714069:	89 b5 d0 ef ff ff    	mov    DWORD PTR [ebp-0x1030],esi
  71406f:	f6 c3 01             	test   bl,0x1
  714072:	75 24                	jne    0x714098
  714074:	68 00 01 00 00       	push   0x100
  714079:	6a 00                	push   0x0
  71407b:	83 cb 01             	or     ebx,0x1
  71407e:	68 48 35 fe 00       	push   0xfe3548
  714083:	89 1d 4c 36 fe 00    	mov    DWORD PTR ds:0xfe364c,ebx
  714089:	c6 05 48 36 fe 00 00 	mov    BYTE PTR ds:0xfe3648,0x0
  714090:	e8 cb a7 18 00       	call   0x89e860
  714095:	83 c4 0c             	add    esp,0xc
  714098:	80 3d 48 36 fe 00 00 	cmp    BYTE PTR ds:0xfe3648,0x0
  71409f:	0f 84 f2 00 00 00    	je     0x714197
  7140a5:	f6 c3 01             	test   bl,0x1
  7140a8:	75 24                	jne    0x7140ce
  7140aa:	68 00 01 00 00       	push   0x100
  7140af:	6a 00                	push   0x0
  7140b1:	83 cb 01             	or     ebx,0x1
  7140b4:	68 48 35 fe 00       	push   0xfe3548
  7140b9:	89 1d 4c 36 fe 00    	mov    DWORD PTR ds:0xfe364c,ebx
  7140bf:	c6 05 48 36 fe 00 00 	mov    BYTE PTR ds:0xfe3648,0x0
  7140c6:	e8 95 a7 18 00       	call   0x89e860
  7140cb:	83 c4 0c             	add    esp,0xc
  7140ce:	33 db                	xor    ebx,ebx
  7140d0:	b8 48 35 fe 00       	mov    eax,0xfe3548
  7140d5:	c7 85 e8 ef ff ff 0f 	mov    DWORD PTR [ebp-0x1018],0xf
  7140dc:	00 00 00 
  7140df:	89 9d e4 ef ff ff    	mov    DWORD PTR [ebp-0x101c],ebx
  7140e5:	88 9d d4 ef ff ff    	mov    BYTE PTR [ebp-0x102c],bl
  7140eb:	8d 50 01             	lea    edx,[eax+0x1]
  7140ee:	8b ff                	mov    edi,edi
  7140f0:	8a 08                	mov    cl,BYTE PTR [eax]
  7140f2:	40                   	inc    eax
  7140f3:	84 c9                	test   cl,cl
  7140f5:	75 f9                	jne    0x7140f0
  7140f7:	2b c2                	sub    eax,edx
  7140f9:	50                   	push   eax
  7140fa:	68 48 35 fe 00       	push   0xfe3548
  7140ff:	8d 8d d4 ef ff ff    	lea    ecx,[ebp-0x102c]
  714105:	e8 66 e9 ce ff       	call   0x402a70
  71410a:	8b c7                	mov    eax,edi
  71410c:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  71410f:	8d 50 01             	lea    edx,[eax+0x1]
  714112:	8a 08                	mov    cl,BYTE PTR [eax]
  714114:	40                   	inc    eax
  714115:	84 c9                	test   cl,cl
  714117:	75 f9                	jne    0x714112
  714119:	2b c2                	sub    eax,edx
  71411b:	50                   	push   eax
  71411c:	57                   	push   edi
  71411d:	8d 8d d4 ef ff ff    	lea    ecx,[ebp-0x102c]
  714123:	e8 98 de ce ff       	call   0x401fc0
  714128:	83 bd e8 ef ff ff 10 	cmp    DWORD PTR [ebp-0x1018],0x10
  71412f:	8b 9d d4 ef ff ff    	mov    ebx,DWORD PTR [ebp-0x102c]
  714135:	73 06                	jae    0x71413d
  714137:	8d 9d d4 ef ff ff    	lea    ebx,[ebp-0x102c]
  71413d:	8b c3                	mov    eax,ebx
  71413f:	e8 1c 3a 00 00       	call   0x717b60
  714144:	85 c0                	test   eax,eax
  714146:	74 15                	je     0x71415d
  714148:	8b d6                	mov    edx,esi
  71414a:	8b cb                	mov    ecx,ebx
  71414c:	e8 6f 3a 00 00       	call   0x717bc0
  714151:	8b f0                	mov    esi,eax
  714153:	85 f6                	test   esi,esi
  714155:	75 13                	jne    0x71416a
  714157:	8b b5 d0 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1030]
  71415d:	56                   	push   esi
  71415e:	8b cb                	mov    ecx,ebx
  714160:	e8 5b fb ff ff       	call   0x713cc0
  714165:	83 c4 04             	add    esp,0x4
  714168:	8b f0                	mov    esi,eax
  71416a:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  714171:	83 bd e8 ef ff ff 10 	cmp    DWORD PTR [ebp-0x1018],0x10
  714178:	72 0f                	jb     0x714189
  71417a:	8b 85 d4 ef ff ff    	mov    eax,DWORD PTR [ebp-0x102c]
  714180:	50                   	push   eax
  714181:	e8 86 d0 17 00       	call   0x89120c
  714186:	83 c4 04             	add    esp,0x4
  714189:	85 f6                	test   esi,esi
  71418b:	0f 85 ac 00 00 00    	jne    0x71423d
  714191:	8b b5 d0 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1030]
  714197:	8b c7                	mov    eax,edi
  714199:	e8 c2 39 00 00       	call   0x717b60
  71419e:	85 c0                	test   eax,eax
  7141a0:	74 19                	je     0x7141bb
  7141a2:	8b d6                	mov    edx,esi
  7141a4:	8b cf                	mov    ecx,edi
  7141a6:	e8 15 3a 00 00       	call   0x717bc0
  7141ab:	8b f0                	mov    esi,eax
  7141ad:	85 f6                	test   esi,esi
  7141af:	0f 85 88 00 00 00    	jne    0x71423d
  7141b5:	8b b5 d0 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1030]
  7141bb:	56                   	push   esi
  7141bc:	8b cf                	mov    ecx,edi
  7141be:	e8 fd fa ff ff       	call   0x713cc0
  7141c3:	8b f0                	mov    esi,eax
  7141c5:	83 c4 04             	add    esp,0x4
  7141c8:	85 f6                	test   esi,esi
  7141ca:	75 71                	jne    0x71423d
  7141cc:	ff 15 00 23 bd 00    	call   DWORD PTR ds:0xbd2300
  7141d2:	89 85 cc ef ff ff    	mov    DWORD PTR [ebp-0x1034],eax
  7141d8:	83 f8 02             	cmp    eax,0x2
  7141db:	75 07                	jne    0x7141e4
  7141dd:	bb 40 42 c4 00       	mov    ebx,0xc44240
  7141e2:	eb 0f                	jmp    0x7141f3
  7141e4:	bb 54 42 c4 00       	mov    ebx,0xc44254
  7141e9:	83 f8 03             	cmp    eax,0x3
  7141ec:	74 05                	je     0x7141f3
  7141ee:	bb 50 c2 bf 00       	mov    ebx,0xbfc250
  7141f3:	68 ff 0f 00 00       	push   0xfff
  7141f8:	8d 8d f1 ef ff ff    	lea    ecx,[ebp-0x100f]
  7141fe:	6a 00                	push   0x0
  714200:	51                   	push   ecx
  714201:	c6 85 f0 ef ff ff 00 	mov    BYTE PTR [ebp-0x1010],0x0
  714208:	e8 53 a6 18 00       	call   0x89e860
  71420d:	8b 95 d0 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1030]
  714213:	8b 85 cc ef ff ff    	mov    eax,DWORD PTR [ebp-0x1034]
  714219:	52                   	push   edx
  71421a:	57                   	push   edi
  71421b:	53                   	push   ebx
  71421c:	50                   	push   eax
  71421d:	68 68 42 c4 00       	push   0xc44268
  714222:	8d 95 f0 ef ff ff    	lea    edx,[ebp-0x1010]
  714228:	e8 23 07 00 00       	call   0x714950
  71422d:	8d 8d f0 ef ff ff    	lea    ecx,[ebp-0x1010]
  714233:	51                   	push   ecx
  714234:	ff 15 50 3d d6 00    	call   DWORD PTR ds:0xd63d50
  71423a:	83 c4 24             	add    esp,0x24
  71423d:	8b c6                	mov    eax,esi
  71423f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  714242:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  714249:	59                   	pop    ecx
  71424a:	5e                   	pop    esi
  71424b:	5b                   	pop    ebx
  71424c:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  71424f:	33 cd                	xor    ecx,ebp
  714251:	e8 ab cd 17 00       	call   0x891001
  714256:	8b e5                	mov    esp,ebp
  714258:	5d                   	pop    ebp
  714259:	c3                   	ret

# generic-resource-policy-default-initialization

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007142d0 <.text+0x3132d0>:
  7142d0:	55                   	push   ebp
  7142d1:	8b ec                	mov    ebp,esp
  7142d3:	6a ff                	push   0xffffffff
  7142d5:	68 18 a8 90 00       	push   0x90a818
  7142da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7142e0:	50                   	push   eax
  7142e1:	83 ec 24             	sub    esp,0x24
  7142e4:	53                   	push   ebx
  7142e5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7142ea:	33 c5                	xor    eax,ebp
  7142ec:	50                   	push   eax
  7142ed:	8d 45 f4             	lea    eax,[ebp-0xc]
  7142f0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7142f6:	33 db                	xor    ebx,ebx
  7142f8:	6a 24                	push   0x24
  7142fa:	c7 45 e8 7c 4c fe 00 	mov    DWORD PTR [ebp-0x18],0xfe4c7c
  714301:	89 1d 80 4c fe 00    	mov    DWORD PTR ds:0xfe4c80,ebx
  714307:	e8 5c cf 17 00       	call   0x891268
  71430c:	83 c4 04             	add    esp,0x4
  71430f:	3b c3                	cmp    eax,ebx
  714311:	74 74                	je     0x714387
  714313:	a3 7c 4c fe 00       	mov    ds:0xfe4c7c,eax
  714318:	89 00                	mov    DWORD PTR [eax],eax
  71431a:	a1 7c 4c fe 00       	mov    eax,ds:0xfe4c7c
  71431f:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  714322:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  714325:	6a 24                	push   0x24
  714327:	89 1d 8c 4c fe 00    	mov    DWORD PTR ds:0xfe4c8c,ebx
  71432d:	e8 36 cf 17 00       	call   0x891268
  714332:	83 c4 04             	add    esp,0x4
  714335:	3b c3                	cmp    eax,ebx
  714337:	74 2a                	je     0x714363
  714339:	a3 88 4c fe 00       	mov    ds:0xfe4c88,eax
  71433e:	89 00                	mov    DWORD PTR [eax],eax
  714340:	a1 88 4c fe 00       	mov    eax,ds:0xfe4c88
  714345:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  714348:	88 1d 94 4c fe 00    	mov    BYTE PTR ds:0xfe4c94,bl
  71434e:	b8 7c 4c fe 00       	mov    eax,0xfe4c7c
  714353:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  714356:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  71435d:	59                   	pop    ecx
  71435e:	5b                   	pop    ebx
  71435f:	8b e5                	mov    esp,ebp
  714361:	5d                   	pop    ebp
  714362:	c3                   	ret
  714363:	8d 45 f0             	lea    eax,[ebp-0x10]
  714366:	50                   	push   eax
  714367:	8d 4d dc             	lea    ecx,[ebp-0x24]
  71436a:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  71436d:	e8 37 cd 17 00       	call   0x8910a9
  714372:	68 a8 57 c8 00       	push   0xc857a8
  714377:	8d 4d dc             	lea    ecx,[ebp-0x24]
  71437a:	51                   	push   ecx
  71437b:	c7 45 dc a4 2c bd 00 	mov    DWORD PTR [ebp-0x24],0xbd2ca4
  714382:	e8 69 86 18 00       	call   0x89c9f0
  714387:	8d 55 ec             	lea    edx,[ebp-0x14]
  71438a:	52                   	push   edx
  71438b:	8d 4d d0             	lea    ecx,[ebp-0x30]
  71438e:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  714391:	e8 13 cd 17 00       	call   0x8910a9
  714396:	68 a8 57 c8 00       	push   0xc857a8
  71439b:	8d 45 d0             	lea    eax,[ebp-0x30]
  71439e:	50                   	push   eax
  71439f:	c7 45 d0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x30],0xbd2ca4
  7143a6:	e8 45 86 18 00       	call   0x89c9f0
  7143ab:	cc                   	int3
  7143ac:	cc                   	int3
  7143ad:	cc                   	int3
  7143ae:	cc                   	int3
  7143af:	cc                   	int3

# resource-package-first-and-policy-gate

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00714770 <.text+0x313770>:
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

# Research group: executor

# prepass-resource-record-constructor

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055c520 <.text+0x15b520>:
  55c520:	55                   	push   ebp
  55c521:	8b ec                	mov    ebp,esp
  55c523:	66 8b 45 08          	mov    ax,WORD PTR [ebp+0x8]
  55c527:	83 ec 0c             	sub    esp,0xc
  55c52a:	66 89 06             	mov    WORD PTR [esi],ax
  55c52d:	6a 10                	push   0x10
  55c52f:	c7 46 0c 00 00 00 00 	mov    DWORD PTR [esi+0xc],0x0
  55c536:	e8 2d 4d 33 00       	call   0x891268
  55c53b:	83 c4 04             	add    esp,0x4
  55c53e:	85 c0                	test   eax,eax
  55c540:	74 27                	je     0x55c569
  55c542:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  55c545:	89 00                	mov    DWORD PTR [eax],eax
  55c547:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  55c54a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  55c54d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  55c550:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  55c553:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  55c556:	b0 01                	mov    al,0x1
  55c558:	88 41 0e             	mov    BYTE PTR [ecx+0xe],al
  55c55b:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  55c55e:	88 42 0f             	mov    BYTE PTR [edx+0xf],al
  55c561:	8b c6                	mov    eax,esi
  55c563:	8b e5                	mov    esp,ebp
  55c565:	5d                   	pop    ebp
  55c566:	c2 04 00             	ret    0x4
  55c569:	8d 45 08             	lea    eax,[ebp+0x8]
  55c56c:	50                   	push   eax
  55c56d:	8d 4d f4             	lea    ecx,[ebp-0xc]
  55c570:	c7 45 08 00 00 00 00 	mov    DWORD PTR [ebp+0x8],0x0
  55c577:	e8 2d 4b 33 00       	call   0x8910a9
  55c57c:	68 a8 57 c8 00       	push   0xc857a8
  55c581:	8d 4d f4             	lea    ecx,[ebp-0xc]
  55c584:	51                   	push   ecx
  55c585:	c7 45 f4 a4 2c bd 00 	mov    DWORD PTR [ebp-0xc],0xbd2ca4
  55c58c:	e8 5f 04 34 00       	call   0x89c9f0

# lb-count-target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a0a30 <.text+0x9fa30>:
  4a0a30:	55                   	push   ebp
  4a0a31:	8b ec                	mov    ebp,esp
  4a0a33:	83 e4 f8             	and    esp,0xfffffff8
  4a0a36:	6a ff                	push   0xffffffff
  4a0a38:	68 ee 61 94 00       	push   0x9461ee
  4a0a3d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a0a43:	50                   	push   eax
  4a0a44:	51                   	push   ecx
  4a0a45:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a0a4a:	33 c4                	xor    eax,esp
  4a0a4c:	50                   	push   eax
  4a0a4d:	8d 44 24 08          	lea    eax,[esp+0x8]
  4a0a51:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a0a57:	b8 01 00 00 00       	mov    eax,0x1
  4a0a5c:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4a0a62:	75 20                	jne    0x4a0a84
  4a0a64:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4a0a6a:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  4a0a71:	00 
  4a0a72:	e8 19 e2 03 00       	call   0x4dec90
  4a0a77:	68 30 ce bc 00       	push   0xbcce30
  4a0a7c:	e8 99 18 3f 00       	call   0x89231a
  4a0a81:	83 c4 04             	add    esp,0x4
  4a0a84:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4a0a88:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a0a8f:	59                   	pop    ecx
  4a0a90:	8b e5                	mov    esp,ebp
  4a0a92:	5d                   	pop    ebp
  4a0a93:	c3                   	ret

# lb-count-registration

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1650 <.text+0xa0650>:
  4a1650:	55                   	push   ebp
  4a1651:	8b ec                	mov    ebp,esp
  4a1653:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1656:	53                   	push   ebx
  4a1657:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a165d:	56                   	push   esi
  4a165e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1660:	57                   	push   edi
  4a1661:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1663:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1668:	c7 05 80 17 fe 00 30 	mov    DWORD PTR ds:0xfe1780,0x4a0a30
  4a166f:	0a 4a 00 
  4a1672:	e8 09 40 25 00       	call   0x6f5680
  4a1677:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1679:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a167c:	83 e8 10             	sub    eax,0x10
  4a167f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1684:	74 06                	je     0x4a168c
  4a1686:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a168a:	74 14                	je     0x4a16a0
  4a168c:	57                   	push   edi
  4a168d:	68 c4 26 c4 00       	push   0xc426c4
  4a1692:	e8 26 1a 3f 00       	call   0x8930bd
  4a1697:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1699:	83 c4 08             	add    esp,0x8
  4a169c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a16a0:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a16a6:	8b 37                	mov    esi,DWORD PTR [edi]
  4a16a8:	68 a0 ad d6 00       	push   0xd6ada0
  4a16ad:	e8 5e 3e 25 00       	call   0x6f5510
  4a16b2:	8b 37                	mov    esi,DWORD PTR [edi]
  4a16b4:	83 c4 04             	add    esp,0x4
  4a16b7:	6a 00                	push   0x0
  4a16b9:	68 f0 1e 4a 00       	push   0x4a1ef0
  4a16be:	e8 ed 3e 25 00       	call   0x6f55b0
  4a16c3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a16c5:	51                   	push   ecx
  4a16c6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a16cb:	e8 20 41 25 00       	call   0x6f57f0
  4a16d0:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a16d6:	8b 02                	mov    eax,DWORD PTR [edx]
  4a16d8:	83 c4 0c             	add    esp,0xc
  4a16db:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a16df:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a16e2:	5f                   	pop    edi
  4a16e3:	5e                   	pop    esi
  4a16e4:	5b                   	pop    ebx
  4a16e5:	5d                   	pop    ebp
  4a16e6:	c2 04 00             	ret    0x4

# lb-count-wrapper

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1ef0 <.text+0xa0ef0>:
  4a1ef0:	55                   	push   ebp
  4a1ef1:	8b ec                	mov    ebp,esp
  4a1ef3:	6a ff                	push   0xffffffff
  4a1ef5:	68 c8 83 93 00       	push   0x9383c8
  4a1efa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a1f00:	50                   	push   eax
  4a1f01:	83 ec 0c             	sub    esp,0xc
  4a1f04:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a1f09:	33 c5                	xor    eax,ebp
  4a1f0b:	50                   	push   eax
  4a1f0c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a1f0f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a1f15:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1f18:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4a1f1b:	33 c0                	xor    eax,eax
  4a1f1d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a1f20:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a1f23:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a1f26:	8b 0d 78 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe1778
  4a1f2c:	ff 15 80 17 fe 00    	call   DWORD PTR ds:0xfe1780
  4a1f32:	b8 01 00 00 00       	mov    eax,0x1
  4a1f37:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a1f3a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a1f41:	59                   	pop    ecx
  4a1f42:	8b e5                	mov    esp,ebp
  4a1f44:	5d                   	pop    ebp
  4a1f45:	c3                   	ret

# lua-c-result-count

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe354 <.text+0x2fd354>:
  6fe354:	8b 56 14             	mov    edx,DWORD PTR [esi+0x14]
  6fe357:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  6fe35a:	8b 08                	mov    ecx,DWORD PTR [eax]
  6fe35c:	8b 51 10             	mov    edx,DWORD PTR [ecx+0x10]
  6fe35f:	56                   	push   esi
  6fe360:	ff d2                	call   edx
  6fe362:	83 c4 04             	add    esp,0x4
  6fe365:	85 c0                	test   eax,eax
  6fe367:	79 0c                	jns    0x6fe375
  6fe369:	b8 02 00 00 00       	mov    eax,0x2
  6fe36e:	5f                   	pop    edi
  6fe36f:	5e                   	pop    esi
  6fe370:	5b                   	pop    ebx
  6fe371:	8b e5                	mov    esp,ebp
  6fe373:	5d                   	pop    ebp
  6fe374:	c3                   	ret
  6fe375:	c1 e0 04             	shl    eax,0x4
  6fe378:	8b c8                	mov    ecx,eax
  6fe37a:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6fe37d:	2b c1                	sub    eax,ecx
  6fe37f:	56                   	push   esi
  6fe380:	e8 3b 01 00 00       	call   0x6fe4c0
  6fe385:	83 c4 04             	add    esp,0x4
  6fe388:	5f                   	pop    edi
  6fe389:	5e                   	pop    esi
  6fe38a:	b8 01 00 00 00       	mov    eax,0x1
  6fe38f:	5b                   	pop    ebx
  6fe390:	8b e5                	mov    esp,ebp
  6fe392:	5d                   	pop    ebp
  6fe393:	c3                   	ret

# lua-result-slot-copy

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe4c0 <.text+0x2fd4c0>:
  6fe4c0:	55                   	push   ebp
  6fe4c1:	8b ec                	mov    ebp,esp
  6fe4c3:	51                   	push   ecx
  6fe4c4:	53                   	push   ebx
  6fe4c5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  6fe4c8:	f6 43 38 02          	test   BYTE PTR [ebx+0x38],0x2
  6fe4cc:	56                   	push   esi
  6fe4cd:	57                   	push   edi
  6fe4ce:	74 0b                	je     0x6fe4db
  6fe4d0:	50                   	push   eax
  6fe4d1:	8b cb                	mov    ecx,ebx
  6fe4d3:	e8 c8 fe ff ff       	call   0x6fe3a0
  6fe4d8:	83 c4 04             	add    esp,0x4
  6fe4db:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  6fe4de:	8d 72 e8             	lea    esi,[edx-0x18]
  6fe4e1:	89 73 14             	mov    DWORD PTR [ebx+0x14],esi
  6fe4e4:	8b 7a 10             	mov    edi,DWORD PTR [edx+0x10]
  6fe4e7:	8b 36                	mov    esi,DWORD PTR [esi]
  6fe4e9:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  6fe4ec:	89 73 0c             	mov    DWORD PTR [ebx+0xc],esi
  6fe4ef:	8b 52 f4             	mov    edx,DWORD PTR [edx-0xc]
  6fe4f2:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  6fe4f5:	89 53 18             	mov    DWORD PTR [ebx+0x18],edx
  6fe4f8:	8b f7                	mov    esi,edi
  6fe4fa:	85 ff                	test   edi,edi
  6fe4fc:	74 2a                	je     0x6fe528
  6fe4fe:	8b f8                	mov    edi,eax
  6fe500:	3b 7b 08             	cmp    edi,DWORD PTR [ebx+0x8]
  6fe503:	73 20                	jae    0x6fe525
  6fe505:	8b c7                	mov    eax,edi
  6fe507:	8b 18                	mov    ebx,DWORD PTR [eax]
  6fe509:	8b d1                	mov    edx,ecx
  6fe50b:	89 1a                	mov    DWORD PTR [edx],ebx
  6fe50d:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  6fe510:	89 5a 04             	mov    DWORD PTR [edx+0x4],ebx
  6fe513:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  6fe516:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  6fe519:	83 c1 10             	add    ecx,0x10
  6fe51c:	83 c7 10             	add    edi,0x10
  6fe51f:	4e                   	dec    esi
  6fe520:	89 42 08             	mov    DWORD PTR [edx+0x8],eax
  6fe523:	75 db                	jne    0x6fe500
  6fe525:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  6fe528:	33 c0                	xor    eax,eax
  6fe52a:	3b f0                	cmp    esi,eax
  6fe52c:	7e 0d                	jle    0x6fe53b
  6fe52e:	8b ff                	mov    edi,edi
  6fe530:	4e                   	dec    esi
  6fe531:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  6fe534:	83 c1 10             	add    ecx,0x10
  6fe537:	3b f0                	cmp    esi,eax
  6fe539:	7f f5                	jg     0x6fe530
  6fe53b:	8d 47 01             	lea    eax,[edi+0x1]
  6fe53e:	5f                   	pop    edi
  6fe53f:	5e                   	pop    esi
  6fe540:	89 4b 08             	mov    DWORD PTR [ebx+0x8],ecx
  6fe543:	5b                   	pop    ebx
  6fe544:	8b e5                	mov    esp,ebp
  6fe546:	5d                   	pop    ebp
  6fe547:	c3                   	ret

# prepass-new-state

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055c610 <.text+0x15b610>:
  55c610:	55                   	push   ebp
  55c611:	8b ec                	mov    ebp,esp
  55c613:	6a ff                	push   0xffffffff
  55c615:	68 a8 89 93 00       	push   0x9389a8
  55c61a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55c620:	50                   	push   eax
  55c621:	83 ec 14             	sub    esp,0x14
  55c624:	53                   	push   ebx
  55c625:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55c62a:	33 c5                	xor    eax,ebp
  55c62c:	50                   	push   eax
  55c62d:	8d 45 f4             	lea    eax,[ebp-0xc]
  55c630:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55c636:	33 db                	xor    ebx,ebx
  55c638:	6a 18                	push   0x18
  55c63a:	c7 45 ec ec 1e fe 00 	mov    DWORD PTR [ebp-0x14],0xfe1eec
  55c641:	89 1d fc 1e fe 00    	mov    DWORD PTR ds:0xfe1efc,ebx
  55c647:	e8 1c 4c 33 00       	call   0x891268
  55c64c:	83 c4 04             	add    esp,0x4
  55c64f:	3b c3                	cmp    eax,ebx
  55c651:	0f 84 9e 00 00 00    	je     0x55c6f5
  55c657:	a3 f8 1e fe 00       	mov    ds:0xfe1ef8,eax
  55c65c:	89 00                	mov    DWORD PTR [eax],eax
  55c65e:	a1 f8 1e fe 00       	mov    eax,ds:0xfe1ef8
  55c663:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  55c666:	a1 f8 1e fe 00       	mov    eax,ds:0xfe1ef8
  55c66b:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  55c66e:	8b 0d f8 1e fe 00    	mov    ecx,DWORD PTR ds:0xfe1ef8
  55c674:	b0 01                	mov    al,0x1
  55c676:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  55c679:	8b 15 f8 1e fe 00    	mov    edx,DWORD PTR ds:0xfe1ef8
  55c67f:	88 42 15             	mov    BYTE PTR [edx+0x15],al
  55c682:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  55c685:	c7 05 18 1f fe 00 0f 	mov    DWORD PTR ds:0xfe1f18,0xf
  55c68c:	00 00 00 
  55c68f:	89 1d 14 1f fe 00    	mov    DWORD PTR ds:0xfe1f14,ebx
  55c695:	88 1d 04 1f fe 00    	mov    BYTE PTR ds:0xfe1f04,bl
  55c69b:	88 45 fc             	mov    BYTE PTR [ebp-0x4],al
  55c69e:	e8 0d ae 19 00       	call   0x6f74b0
  55c6a3:	3b c3                	cmp    eax,ebx
  55c6a5:	74 0a                	je     0x55c6b1
  55c6a7:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  55c6aa:	c7 41 58 a0 71 6f 00 	mov    DWORD PTR [ecx+0x58],0x6f71a0
  55c6b1:	6a 0c                	push   0xc
  55c6b3:	a3 ec 1e fe 00       	mov    ds:0xfe1eec,eax
  55c6b8:	e8 ab 4b 33 00       	call   0x891268
  55c6bd:	83 c4 04             	add    esp,0x4
  55c6c0:	3b c3                	cmp    eax,ebx
  55c6c2:	74 10                	je     0x55c6d4
  55c6c4:	8b 15 ec 1e fe 00    	mov    edx,DWORD PTR ds:0xfe1eec
  55c6ca:	89 10                	mov    DWORD PTR [eax],edx
  55c6cc:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  55c6cf:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  55c6d2:	eb 02                	jmp    0x55c6d6
  55c6d4:	33 c0                	xor    eax,eax
  55c6d6:	a3 f0 1e fe 00       	mov    ds:0xfe1ef0,eax
  55c6db:	e8 00 11 00 00       	call   0x55d7e0
  55c6e0:	b8 ec 1e fe 00       	mov    eax,0xfe1eec
  55c6e5:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  55c6e8:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55c6ef:	59                   	pop    ecx
  55c6f0:	5b                   	pop    ebx
  55c6f1:	8b e5                	mov    esp,ebp
  55c6f3:	5d                   	pop    ebp
  55c6f4:	c3                   	ret
  55c6f5:	8d 45 f0             	lea    eax,[ebp-0x10]
  55c6f8:	50                   	push   eax
  55c6f9:	8d 4d e0             	lea    ecx,[ebp-0x20]
  55c6fc:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  55c6ff:	e8 a5 49 33 00       	call   0x8910a9
  55c704:	68 a8 57 c8 00       	push   0xc857a8
  55c709:	8d 4d e0             	lea    ecx,[ebp-0x20]
  55c70c:	51                   	push   ecx
  55c70d:	c7 45 e0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x20],0xbd2ca4
  55c714:	e8 d7 02 34 00       	call   0x89c9f0

# prepass-collect-object-record

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055c810 <.text+0x15b810>:
  55c810:	55                   	push   ebp
  55c811:	8b ec                	mov    ebp,esp
  55c813:	6a ff                	push   0xffffffff
  55c815:	68 1b cf 90 00       	push   0x90cf1b
  55c81a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55c820:	50                   	push   eax
  55c821:	83 ec 0c             	sub    esp,0xc
  55c824:	53                   	push   ebx
  55c825:	56                   	push   esi
  55c826:	57                   	push   edi
  55c827:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55c82c:	33 c5                	xor    eax,ebp
  55c82e:	50                   	push   eax
  55c82f:	8d 45 f4             	lea    eax,[ebp-0xc]
  55c832:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55c838:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  55c83b:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  55c83e:	8b 73 0c             	mov    esi,DWORD PTR [ebx+0xc]
  55c841:	0f b7 c7             	movzx  eax,di
  55c844:	8d 4d f0             	lea    ecx,[ebp-0x10]
  55c847:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  55c84a:	83 c3 08             	add    ebx,0x8
  55c84d:	51                   	push   ecx
  55c84e:	8d 45 ec             	lea    eax,[ebp-0x14]
  55c851:	8b cb                	mov    ecx,ebx
  55c853:	e8 28 9a 2c 00       	call   0x826280
  55c858:	39 30                	cmp    DWORD PTR [eax],esi
  55c85a:	74 31                	je     0x55c88d
  55c85c:	8b 55 14             	mov    edx,DWORD PTR [ebp+0x14]
  55c85f:	0f b7 c7             	movzx  eax,di
  55c862:	8d 4d 14             	lea    ecx,[ebp+0x14]
  55c865:	89 45 14             	mov    DWORD PTR [ebp+0x14],eax
  55c868:	51                   	push   ecx
  55c869:	8d 45 0c             	lea    eax,[ebp+0xc]
  55c86c:	8b cb                	mov    ecx,ebx
  55c86e:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  55c871:	e8 0a 9a 2c 00       	call   0x826280
  55c876:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  55c879:	3b c6                	cmp    eax,esi
  55c87b:	0f 84 a1 00 00 00    	je     0x55c922
  55c881:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  55c884:	8d 55 08             	lea    edx,[ebp+0x8]
  55c887:	52                   	push   edx
  55c888:	e9 83 00 00 00       	jmp    0x55c910
  55c88d:	6a 14                	push   0x14
  55c88f:	e8 d4 49 33 00       	call   0x891268
  55c894:	83 c4 04             	add    esp,0x4
  55c897:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  55c89a:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  55c8a1:	85 c0                	test   eax,eax
  55c8a3:	74 0d                	je     0x55c8b2
  55c8a5:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  55c8a8:	51                   	push   ecx
  55c8a9:	8b f0                	mov    esi,eax
  55c8ab:	e8 70 fc ff ff       	call   0x55c520
  55c8b0:	eb 02                	jmp    0x55c8b4
  55c8b2:	33 c0                	xor    eax,eax
  55c8b4:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  55c8bb:	66 89 7d e8          	mov    WORD PTR [ebp-0x18],di
  55c8bf:	8d 7d e8             	lea    edi,[ebp-0x18]
  55c8c2:	8b f3                	mov    esi,ebx
  55c8c4:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  55c8c7:	e8 a4 dd f6 ff       	call   0x4ca670
  55c8cc:	50                   	push   eax
  55c8cd:	53                   	push   ebx
  55c8ce:	8d 75 e8             	lea    esi,[ebp-0x18]
  55c8d1:	e8 1a 9a 2c 00       	call   0x8262f0
  55c8d6:	83 7d 14 00          	cmp    DWORD PTR [ebp+0x14],0x0
  55c8da:	75 07                	jne    0x55c8e3
  55c8dc:	c7 45 14 01 00 00 00 	mov    DWORD PTR [ebp+0x14],0x1
  55c8e3:	0f b7 45 0c          	movzx  eax,WORD PTR [ebp+0xc]
  55c8e7:	8b 55 14             	mov    edx,DWORD PTR [ebp+0x14]
  55c8ea:	8d 4d 14             	lea    ecx,[ebp+0x14]
  55c8ed:	89 45 14             	mov    DWORD PTR [ebp+0x14],eax
  55c8f0:	51                   	push   ecx
  55c8f1:	8d 45 0c             	lea    eax,[ebp+0xc]
  55c8f4:	8b cb                	mov    ecx,ebx
  55c8f6:	89 55 10             	mov    DWORD PTR [ebp+0x10],edx
  55c8f9:	e8 82 99 2c 00       	call   0x826280
  55c8fe:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  55c901:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  55c904:	3b 42 0c             	cmp    eax,DWORD PTR [edx+0xc]
  55c907:	74 19                	je     0x55c922
  55c909:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  55c90c:	8d 45 10             	lea    eax,[ebp+0x10]
  55c90f:	50                   	push   eax
  55c910:	83 c6 04             	add    esi,0x4
  55c913:	e8 98 1c 00 00       	call   0x55e5b0
  55c918:	50                   	push   eax
  55c919:	56                   	push   esi
  55c91a:	8d 75 e8             	lea    esi,[ebp-0x18]
  55c91d:	e8 1e 62 eb ff       	call   0x412b40
  55c922:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  55c925:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55c92c:	59                   	pop    ecx
  55c92d:	5f                   	pop    edi
  55c92e:	5e                   	pop    esi
  55c92f:	5b                   	pop    ebx
  55c930:	8b e5                	mov    esp,ebp
  55c932:	5d                   	pop    ebp
  55c933:	c2 10 00             	ret    0x10

# prepass-create-object-callback

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055c940 <.text+0x15b940>:
  55c940:	55                   	push   ebp
  55c941:	8b ec                	mov    ebp,esp
  55c943:	83 e4 f8             	and    esp,0xfffffff8
  55c946:	6a ff                	push   0xffffffff
  55c948:	68 6e 8d 93 00       	push   0x938d6e
  55c94d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55c953:	50                   	push   eax
  55c954:	83 ec 38             	sub    esp,0x38
  55c957:	53                   	push   ebx
  55c958:	56                   	push   esi
  55c959:	57                   	push   edi
  55c95a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55c95f:	33 c4                	xor    eax,esp
  55c961:	50                   	push   eax
  55c962:	8d 44 24 48          	lea    eax,[esp+0x48]
  55c966:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55c96c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  55c96f:	b8 f7 ff ff ff       	mov    eax,0xfffffff7
  55c974:	8b cb                	mov    ecx,ebx
  55c976:	e8 75 87 19 00       	call   0x6f50f0
  55c97b:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55c97e:	83 f9 03             	cmp    ecx,0x3
  55c981:	74 33                	je     0x55c9b6
  55c983:	83 f9 04             	cmp    ecx,0x4
  55c986:	0f 85 29 03 00 00    	jne    0x55ccb5
  55c98c:	8b 30                	mov    esi,DWORD PTR [eax]
  55c98e:	83 c6 10             	add    esi,0x10
  55c991:	8d 7c 24 24          	lea    edi,[esp+0x24]
  55c995:	e8 c6 ad 19 00       	call   0x6f7760
  55c99a:	85 c0                	test   eax,eax
  55c99c:	0f 84 13 03 00 00    	je     0x55ccb5
  55c9a2:	dd 44 24 24          	fld    QWORD PTR [esp+0x24]
  55c9a6:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55c9ad:	00 
  55c9ae:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55c9b2:	8d 44 24 34          	lea    eax,[esp+0x34]
  55c9b6:	dd 00                	fld    QWORD PTR [eax]
  55c9b8:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55c9bc:	dd 44 24 2c          	fld    QWORD PTR [esp+0x2c]
  55c9c0:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55c9c4:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  55c9c8:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  55c9cc:	b8 f8 ff ff ff       	mov    eax,0xfffffff8
  55c9d1:	8b cb                	mov    ecx,ebx
  55c9d3:	e8 18 87 19 00       	call   0x6f50f0
  55c9d8:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55c9db:	83 f9 03             	cmp    ecx,0x3
  55c9de:	74 33                	je     0x55ca13
  55c9e0:	83 f9 04             	cmp    ecx,0x4
  55c9e3:	0f 85 d9 02 00 00    	jne    0x55ccc2
  55c9e9:	8b 30                	mov    esi,DWORD PTR [eax]
  55c9eb:	83 c6 10             	add    esi,0x10
  55c9ee:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55c9f2:	e8 69 ad 19 00       	call   0x6f7760
  55c9f7:	85 c0                	test   eax,eax
  55c9f9:	0f 84 c3 02 00 00    	je     0x55ccc2
  55c9ff:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55ca03:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55ca0a:	00 
  55ca0b:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55ca0f:	8d 44 24 34          	lea    eax,[esp+0x34]
  55ca13:	dd 00                	fld    QWORD PTR [eax]
  55ca15:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55ca19:	dd 44 24 2c          	fld    QWORD PTR [esp+0x2c]
  55ca1d:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55ca21:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  55ca25:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  55ca29:	b8 f9 ff ff ff       	mov    eax,0xfffffff9
  55ca2e:	8b cb                	mov    ecx,ebx
  55ca30:	e8 bb 86 19 00       	call   0x6f50f0
  55ca35:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55ca38:	83 f9 03             	cmp    ecx,0x3
  55ca3b:	74 2b                	je     0x55ca68
  55ca3d:	83 f9 04             	cmp    ecx,0x4
  55ca40:	75 34                	jne    0x55ca76
  55ca42:	8b 30                	mov    esi,DWORD PTR [eax]
  55ca44:	83 c6 10             	add    esi,0x10
  55ca47:	8d 7c 24 14          	lea    edi,[esp+0x14]
  55ca4b:	e8 10 ad 19 00       	call   0x6f7760
  55ca50:	85 c0                	test   eax,eax
  55ca52:	74 22                	je     0x55ca76
  55ca54:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55ca58:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55ca5f:	00 
  55ca60:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55ca64:	8d 44 24 34          	lea    eax,[esp+0x34]
  55ca68:	dd 00                	fld    QWORD PTR [eax]
  55ca6a:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55ca6e:	dd 44 24 2c          	fld    QWORD PTR [esp+0x2c]
  55ca72:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55ca76:	b8 fa ff ff ff       	mov    eax,0xfffffffa
  55ca7b:	8b cb                	mov    ecx,ebx
  55ca7d:	e8 6e 86 19 00       	call   0x6f50f0
  55ca82:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55ca85:	83 f9 03             	cmp    ecx,0x3
  55ca88:	74 2b                	je     0x55cab5
  55ca8a:	83 f9 04             	cmp    ecx,0x4
  55ca8d:	75 34                	jne    0x55cac3
  55ca8f:	8b 30                	mov    esi,DWORD PTR [eax]
  55ca91:	83 c6 10             	add    esi,0x10
  55ca94:	8d 7c 24 14          	lea    edi,[esp+0x14]
  55ca98:	e8 c3 ac 19 00       	call   0x6f7760
  55ca9d:	85 c0                	test   eax,eax
  55ca9f:	74 22                	je     0x55cac3
  55caa1:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55caa5:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55caac:	00 
  55caad:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cab1:	8d 44 24 34          	lea    eax,[esp+0x34]
  55cab5:	dd 00                	fld    QWORD PTR [eax]
  55cab7:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55cabb:	dd 44 24 2c          	fld    QWORD PTR [esp+0x2c]
  55cabf:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55cac3:	b8 fb ff ff ff       	mov    eax,0xfffffffb
  55cac8:	8b cb                	mov    ecx,ebx
  55caca:	e8 21 86 19 00       	call   0x6f50f0
  55cacf:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cad2:	83 f9 03             	cmp    ecx,0x3
  55cad5:	74 2b                	je     0x55cb02
  55cad7:	83 f9 04             	cmp    ecx,0x4
  55cada:	75 34                	jne    0x55cb10
  55cadc:	8b 30                	mov    esi,DWORD PTR [eax]
  55cade:	83 c6 10             	add    esi,0x10
  55cae1:	8d 7c 24 14          	lea    edi,[esp+0x14]
  55cae5:	e8 76 ac 19 00       	call   0x6f7760
  55caea:	85 c0                	test   eax,eax
  55caec:	74 22                	je     0x55cb10
  55caee:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55caf2:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55caf9:	00 
  55cafa:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cafe:	8d 44 24 34          	lea    eax,[esp+0x34]
  55cb02:	dd 00                	fld    QWORD PTR [eax]
  55cb04:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55cb08:	dd 44 24 2c          	fld    QWORD PTR [esp+0x2c]
  55cb0c:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55cb10:	b8 fc ff ff ff       	mov    eax,0xfffffffc
  55cb15:	8b cb                	mov    ecx,ebx
  55cb17:	e8 d4 85 19 00       	call   0x6f50f0
  55cb1c:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cb1f:	83 f9 03             	cmp    ecx,0x3
  55cb22:	74 33                	je     0x55cb57
  55cb24:	83 f9 04             	cmp    ecx,0x4
  55cb27:	0f 85 a2 01 00 00    	jne    0x55cccf
  55cb2d:	8b 30                	mov    esi,DWORD PTR [eax]
  55cb2f:	83 c6 10             	add    esi,0x10
  55cb32:	8d 7c 24 14          	lea    edi,[esp+0x14]
  55cb36:	e8 25 ac 19 00       	call   0x6f7760
  55cb3b:	85 c0                	test   eax,eax
  55cb3d:	0f 84 8c 01 00 00    	je     0x55cccf
  55cb43:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55cb47:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55cb4e:	00 
  55cb4f:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cb53:	8d 44 24 34          	lea    eax,[esp+0x34]
  55cb57:	dd 00                	fld    QWORD PTR [eax]
  55cb59:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55cb5d:	dd 44 24 2c          	fld    QWORD PTR [esp+0x2c]
  55cb61:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55cb65:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  55cb69:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  55cb6d:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  55cb72:	8b cb                	mov    ecx,ebx
  55cb74:	e8 77 85 19 00       	call   0x6f50f0
  55cb79:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cb7c:	83 f9 03             	cmp    ecx,0x3
  55cb7f:	74 2b                	je     0x55cbac
  55cb81:	83 f9 04             	cmp    ecx,0x4
  55cb84:	75 34                	jne    0x55cbba
  55cb86:	8b 30                	mov    esi,DWORD PTR [eax]
  55cb88:	83 c6 10             	add    esi,0x10
  55cb8b:	8d 7c 24 34          	lea    edi,[esp+0x34]
  55cb8f:	e8 cc ab 19 00       	call   0x6f7760
  55cb94:	85 c0                	test   eax,eax
  55cb96:	74 22                	je     0x55cbba
  55cb98:	dd 44 24 34          	fld    QWORD PTR [esp+0x34]
  55cb9c:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55cba3:	00 
  55cba4:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cba8:	8d 44 24 34          	lea    eax,[esp+0x34]
  55cbac:	dd 00                	fld    QWORD PTR [eax]
  55cbae:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cbb2:	dd 44 24 34          	fld    QWORD PTR [esp+0x34]
  55cbb6:	db 5c 24 2c          	fistp  DWORD PTR [esp+0x2c]
  55cbba:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  55cbbf:	8b cb                	mov    ecx,ebx
  55cbc1:	e8 2a 85 19 00       	call   0x6f50f0
  55cbc6:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cbc9:	83 f9 03             	cmp    ecx,0x3
  55cbcc:	74 2b                	je     0x55cbf9
  55cbce:	83 f9 04             	cmp    ecx,0x4
  55cbd1:	75 34                	jne    0x55cc07
  55cbd3:	8b 30                	mov    esi,DWORD PTR [eax]
  55cbd5:	83 c6 10             	add    esi,0x10
  55cbd8:	8d 7c 24 34          	lea    edi,[esp+0x34]
  55cbdc:	e8 7f ab 19 00       	call   0x6f7760
  55cbe1:	85 c0                	test   eax,eax
  55cbe3:	74 22                	je     0x55cc07
  55cbe5:	dd 44 24 34          	fld    QWORD PTR [esp+0x34]
  55cbe9:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55cbf0:	00 
  55cbf1:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cbf5:	8d 44 24 34          	lea    eax,[esp+0x34]
  55cbf9:	dd 00                	fld    QWORD PTR [eax]
  55cbfb:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cbff:	dd 44 24 34          	fld    QWORD PTR [esp+0x34]
  55cc03:	db 5c 24 2c          	fistp  DWORD PTR [esp+0x2c]
  55cc07:	83 c8 ff             	or     eax,0xffffffff
  55cc0a:	8b cb                	mov    ecx,ebx
  55cc0c:	e8 df 84 19 00       	call   0x6f50f0
  55cc11:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cc14:	83 f9 03             	cmp    ecx,0x3
  55cc17:	74 2b                	je     0x55cc44
  55cc19:	83 f9 04             	cmp    ecx,0x4
  55cc1c:	75 34                	jne    0x55cc52
  55cc1e:	8b 30                	mov    esi,DWORD PTR [eax]
  55cc20:	83 c6 10             	add    esi,0x10
  55cc23:	8d 7c 24 34          	lea    edi,[esp+0x34]
  55cc27:	e8 34 ab 19 00       	call   0x6f7760
  55cc2c:	85 c0                	test   eax,eax
  55cc2e:	74 22                	je     0x55cc52
  55cc30:	dd 44 24 34          	fld    QWORD PTR [esp+0x34]
  55cc34:	c7 44 24 3c 03 00 00 	mov    DWORD PTR [esp+0x3c],0x3
  55cc3b:	00 
  55cc3c:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cc40:	8d 44 24 34          	lea    eax,[esp+0x34]
  55cc44:	dd 00                	fld    QWORD PTR [eax]
  55cc46:	dd 5c 24 34          	fstp   QWORD PTR [esp+0x34]
  55cc4a:	dd 44 24 34          	fld    QWORD PTR [esp+0x34]
  55cc4e:	db 5c 24 2c          	fistp  DWORD PTR [esp+0x2c]
  55cc52:	b8 01 00 00 00       	mov    eax,0x1
  55cc57:	84 05 e8 1e fe 00    	test   BYTE PTR ds:0xfe1ee8,al
  55cc5d:	75 28                	jne    0x55cc87
  55cc5f:	09 05 e8 1e fe 00    	or     DWORD PTR ds:0xfe1ee8,eax
  55cc65:	c7 44 24 50 00 00 00 	mov    DWORD PTR [esp+0x50],0x0
  55cc6c:	00 
  55cc6d:	e8 9e f9 ff ff       	call   0x55c610
  55cc72:	68 90 f2 bc 00       	push   0xbcf290
  55cc77:	e8 9e 56 33 00       	call   0x89231a
  55cc7c:	83 c4 04             	add    esp,0x4
  55cc7f:	c7 44 24 50 ff ff ff 	mov    DWORD PTR [esp+0x50],0xffffffff
  55cc86:	ff 
  55cc87:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  55cc8b:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  55cc8f:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  55cc93:	50                   	push   eax
  55cc94:	51                   	push   ecx
  55cc95:	52                   	push   edx
  55cc96:	68 ec 1e fe 00       	push   0xfe1eec
  55cc9b:	e8 70 fb ff ff       	call   0x55c810
  55cca0:	33 c0                	xor    eax,eax
  55cca2:	8b 4c 24 48          	mov    ecx,DWORD PTR [esp+0x48]
  55cca6:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55ccad:	59                   	pop    ecx
  55ccae:	5f                   	pop    edi
  55ccaf:	5e                   	pop    esi
  55ccb0:	5b                   	pop    ebx
  55ccb1:	8b e5                	mov    esp,ebp
  55ccb3:	5d                   	pop    ebp
  55ccb4:	c3                   	ret
  55ccb5:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  55ccbc:	00 
  55ccbd:	e9 0a fd ff ff       	jmp    0x55c9cc
  55ccc2:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  55ccc9:	00 
  55ccca:	e9 5a fd ff ff       	jmp    0x55ca29
  55cccf:	c7 44 24 14 00 00 00 	mov    DWORD PTR [esp+0x14],0x0
  55ccd6:	00 
  55ccd7:	e9 91 fe ff ff       	jmp    0x55cb6d

# prepass-ani-object-callback

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055cce0 <.text+0x15bce0>:
  55cce0:	55                   	push   ebp
  55cce1:	8b ec                	mov    ebp,esp
  55cce3:	83 e4 f8             	and    esp,0xfffffff8
  55cce6:	6a ff                	push   0xffffffff
  55cce8:	68 3e 8d 93 00       	push   0x938d3e
  55cced:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55ccf3:	50                   	push   eax
  55ccf4:	83 ec 28             	sub    esp,0x28
  55ccf7:	53                   	push   ebx
  55ccf8:	56                   	push   esi
  55ccf9:	57                   	push   edi
  55ccfa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55ccff:	33 c4                	xor    eax,esp
  55cd01:	50                   	push   eax
  55cd02:	8d 44 24 38          	lea    eax,[esp+0x38]
  55cd06:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55cd0c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  55cd0f:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  55cd14:	8b cb                	mov    ecx,ebx
  55cd16:	e8 d5 83 19 00       	call   0x6f50f0
  55cd1b:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cd1e:	83 f9 03             	cmp    ecx,0x3
  55cd21:	74 33                	je     0x55cd56
  55cd23:	83 f9 04             	cmp    ecx,0x4
  55cd26:	0f 85 7d 01 00 00    	jne    0x55cea9
  55cd2c:	8b 30                	mov    esi,DWORD PTR [eax]
  55cd2e:	83 c6 10             	add    esi,0x10
  55cd31:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55cd35:	e8 26 aa 19 00       	call   0x6f7760
  55cd3a:	85 c0                	test   eax,eax
  55cd3c:	0f 84 67 01 00 00    	je     0x55cea9
  55cd42:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cd46:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55cd4d:	00 
  55cd4e:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55cd52:	8d 44 24 24          	lea    eax,[esp+0x24]
  55cd56:	dd 00                	fld    QWORD PTR [eax]
  55cd58:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55cd5c:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cd60:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55cd64:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  55cd68:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  55cd6c:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  55cd71:	8b cb                	mov    ecx,ebx
  55cd73:	e8 78 83 19 00       	call   0x6f50f0
  55cd78:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cd7b:	83 f9 03             	cmp    ecx,0x3
  55cd7e:	74 33                	je     0x55cdb3
  55cd80:	83 f9 04             	cmp    ecx,0x4
  55cd83:	0f 85 2d 01 00 00    	jne    0x55ceb6
  55cd89:	8b 30                	mov    esi,DWORD PTR [eax]
  55cd8b:	83 c6 10             	add    esi,0x10
  55cd8e:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55cd92:	e8 c9 a9 19 00       	call   0x6f7760
  55cd97:	85 c0                	test   eax,eax
  55cd99:	0f 84 17 01 00 00    	je     0x55ceb6
  55cd9f:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cda3:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55cdaa:	00 
  55cdab:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55cdaf:	8d 44 24 24          	lea    eax,[esp+0x24]
  55cdb3:	dd 00                	fld    QWORD PTR [eax]
  55cdb5:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55cdb9:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cdbd:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55cdc1:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  55cdc5:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  55cdc9:	83 c8 ff             	or     eax,0xffffffff
  55cdcc:	8b cb                	mov    ecx,ebx
  55cdce:	e8 1d 83 19 00       	call   0x6f50f0
  55cdd3:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cdd6:	83 f9 03             	cmp    ecx,0x3
  55cdd9:	74 2b                	je     0x55ce06
  55cddb:	83 f9 04             	cmp    ecx,0x4
  55cdde:	75 34                	jne    0x55ce14
  55cde0:	8b 30                	mov    esi,DWORD PTR [eax]
  55cde2:	83 c6 10             	add    esi,0x10
  55cde5:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55cde9:	e8 72 a9 19 00       	call   0x6f7760
  55cdee:	85 c0                	test   eax,eax
  55cdf0:	74 22                	je     0x55ce14
  55cdf2:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cdf6:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55cdfd:	00 
  55cdfe:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55ce02:	8d 44 24 24          	lea    eax,[esp+0x24]
  55ce06:	dd 00                	fld    QWORD PTR [eax]
  55ce08:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55ce0c:	dd 44 24 24          	fld    QWORD PTR [esp+0x24]
  55ce10:	db 5c 24 1c          	fistp  DWORD PTR [esp+0x1c]
  55ce14:	b8 01 00 00 00       	mov    eax,0x1
  55ce19:	84 05 e8 1e fe 00    	test   BYTE PTR ds:0xfe1ee8,al
  55ce1f:	75 28                	jne    0x55ce49
  55ce21:	09 05 e8 1e fe 00    	or     DWORD PTR ds:0xfe1ee8,eax
  55ce27:	c7 44 24 40 00 00 00 	mov    DWORD PTR [esp+0x40],0x0
  55ce2e:	00 
  55ce2f:	e8 dc f7 ff ff       	call   0x55c610
  55ce34:	68 90 f2 bc 00       	push   0xbcf290
  55ce39:	e8 dc 54 33 00       	call   0x89231a
  55ce3e:	83 c4 04             	add    esp,0x4
  55ce41:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  55ce48:	ff 
  55ce49:	0f b7 44 24 18       	movzx  eax,WORD PTR [esp+0x18]
  55ce4e:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  55ce52:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  55ce56:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  55ce5a:	51                   	push   ecx
  55ce5b:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  55ce5f:	b9 f4 1e fe 00       	mov    ecx,0xfe1ef4
  55ce64:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  55ce68:	e8 13 94 2c 00       	call   0x826280
  55ce6d:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  55ce71:	3b 05 f8 1e fe 00    	cmp    eax,DWORD PTR ds:0xfe1ef8
  55ce77:	74 1b                	je     0x55ce94
  55ce79:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  55ce7c:	8d 54 24 14          	lea    edx,[esp+0x14]
  55ce80:	83 c6 04             	add    esi,0x4
  55ce83:	52                   	push   edx
  55ce84:	e8 27 17 00 00       	call   0x55e5b0
  55ce89:	50                   	push   eax
  55ce8a:	56                   	push   esi
  55ce8b:	8d 74 24 2c          	lea    esi,[esp+0x2c]
  55ce8f:	e8 ac 5c eb ff       	call   0x412b40
  55ce94:	33 c0                	xor    eax,eax
  55ce96:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  55ce9a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55cea1:	59                   	pop    ecx
  55cea2:	5f                   	pop    edi
  55cea3:	5e                   	pop    esi
  55cea4:	5b                   	pop    ebx
  55cea5:	8b e5                	mov    esp,ebp
  55cea7:	5d                   	pop    ebp
  55cea8:	c3                   	ret
  55cea9:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  55ceb0:	00 
  55ceb1:	e9 b6 fe ff ff       	jmp    0x55cd6c
  55ceb6:	c7 44 24 14 00 00 00 	mov    DWORD PTR [esp+0x14],0x0
  55cebd:	00 
  55cebe:	e9 06 ff ff ff       	jmp    0x55cdc9

# prepass-walk-object-callback

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055ced0 <.text+0x15bed0>:
  55ced0:	55                   	push   ebp
  55ced1:	8b ec                	mov    ebp,esp
  55ced3:	83 e4 f8             	and    esp,0xfffffff8
  55ced6:	6a ff                	push   0xffffffff
  55ced8:	68 3e 8d 93 00       	push   0x938d3e
  55cedd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55cee3:	50                   	push   eax
  55cee4:	83 ec 28             	sub    esp,0x28
  55cee7:	53                   	push   ebx
  55cee8:	56                   	push   esi
  55cee9:	57                   	push   edi
  55ceea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55ceef:	33 c4                	xor    eax,esp
  55cef1:	50                   	push   eax
  55cef2:	8d 44 24 38          	lea    eax,[esp+0x38]
  55cef6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55cefc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  55ceff:	b8 f9 ff ff ff       	mov    eax,0xfffffff9
  55cf04:	8b cb                	mov    ecx,ebx
  55cf06:	e8 e5 81 19 00       	call   0x6f50f0
  55cf0b:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cf0e:	83 f9 03             	cmp    ecx,0x3
  55cf11:	74 33                	je     0x55cf46
  55cf13:	83 f9 04             	cmp    ecx,0x4
  55cf16:	0f 85 d1 02 00 00    	jne    0x55d1ed
  55cf1c:	8b 30                	mov    esi,DWORD PTR [eax]
  55cf1e:	83 c6 10             	add    esi,0x10
  55cf21:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55cf25:	e8 36 a8 19 00       	call   0x6f7760
  55cf2a:	85 c0                	test   eax,eax
  55cf2c:	0f 84 bb 02 00 00    	je     0x55d1ed
  55cf32:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cf36:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55cf3d:	00 
  55cf3e:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55cf42:	8d 44 24 24          	lea    eax,[esp+0x24]
  55cf46:	dd 00                	fld    QWORD PTR [eax]
  55cf48:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55cf4c:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cf50:	db 5c 24 10          	fistp  DWORD PTR [esp+0x10]
  55cf54:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  55cf58:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  55cf5c:	b8 fa ff ff ff       	mov    eax,0xfffffffa
  55cf61:	8b cb                	mov    ecx,ebx
  55cf63:	e8 88 81 19 00       	call   0x6f50f0
  55cf68:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cf6b:	83 f9 03             	cmp    ecx,0x3
  55cf6e:	74 2b                	je     0x55cf9b
  55cf70:	83 f9 04             	cmp    ecx,0x4
  55cf73:	75 34                	jne    0x55cfa9
  55cf75:	8b 30                	mov    esi,DWORD PTR [eax]
  55cf77:	83 c6 10             	add    esi,0x10
  55cf7a:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55cf7e:	e8 dd a7 19 00       	call   0x6f7760
  55cf83:	85 c0                	test   eax,eax
  55cf85:	74 22                	je     0x55cfa9
  55cf87:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cf8b:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55cf92:	00 
  55cf93:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55cf97:	8d 44 24 24          	lea    eax,[esp+0x24]
  55cf9b:	dd 00                	fld    QWORD PTR [eax]
  55cf9d:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55cfa1:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cfa5:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55cfa9:	b8 fb ff ff ff       	mov    eax,0xfffffffb
  55cfae:	8b cb                	mov    ecx,ebx
  55cfb0:	e8 3b 81 19 00       	call   0x6f50f0
  55cfb5:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55cfb8:	83 f9 03             	cmp    ecx,0x3
  55cfbb:	74 2b                	je     0x55cfe8
  55cfbd:	83 f9 04             	cmp    ecx,0x4
  55cfc0:	75 34                	jne    0x55cff6
  55cfc2:	8b 30                	mov    esi,DWORD PTR [eax]
  55cfc4:	83 c6 10             	add    esi,0x10
  55cfc7:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55cfcb:	e8 90 a7 19 00       	call   0x6f7760
  55cfd0:	85 c0                	test   eax,eax
  55cfd2:	74 22                	je     0x55cff6
  55cfd4:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cfd8:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55cfdf:	00 
  55cfe0:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55cfe4:	8d 44 24 24          	lea    eax,[esp+0x24]
  55cfe8:	dd 00                	fld    QWORD PTR [eax]
  55cfea:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55cfee:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55cff2:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55cff6:	b8 fc ff ff ff       	mov    eax,0xfffffffc
  55cffb:	8b cb                	mov    ecx,ebx
  55cffd:	e8 ee 80 19 00       	call   0x6f50f0
  55d002:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d005:	83 f9 03             	cmp    ecx,0x3
  55d008:	74 2b                	je     0x55d035
  55d00a:	83 f9 04             	cmp    ecx,0x4
  55d00d:	75 34                	jne    0x55d043
  55d00f:	8b 30                	mov    esi,DWORD PTR [eax]
  55d011:	83 c6 10             	add    esi,0x10
  55d014:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d018:	e8 43 a7 19 00       	call   0x6f7760
  55d01d:	85 c0                	test   eax,eax
  55d01f:	74 22                	je     0x55d043
  55d021:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d025:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55d02c:	00 
  55d02d:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55d031:	8d 44 24 24          	lea    eax,[esp+0x24]
  55d035:	dd 00                	fld    QWORD PTR [eax]
  55d037:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55d03b:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d03f:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55d043:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  55d048:	8b cb                	mov    ecx,ebx
  55d04a:	e8 a1 80 19 00       	call   0x6f50f0
  55d04f:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d052:	83 f9 03             	cmp    ecx,0x3
  55d055:	74 33                	je     0x55d08a
  55d057:	83 f9 04             	cmp    ecx,0x4
  55d05a:	0f 85 9a 01 00 00    	jne    0x55d1fa
  55d060:	8b 30                	mov    esi,DWORD PTR [eax]
  55d062:	83 c6 10             	add    esi,0x10
  55d065:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d069:	e8 f2 a6 19 00       	call   0x6f7760
  55d06e:	85 c0                	test   eax,eax
  55d070:	0f 84 84 01 00 00    	je     0x55d1fa
  55d076:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d07a:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55d081:	00 
  55d082:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55d086:	8d 44 24 24          	lea    eax,[esp+0x24]
  55d08a:	dd 00                	fld    QWORD PTR [eax]
  55d08c:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55d090:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d094:	db 5c 24 10          	fistp  DWORD PTR [esp+0x10]
  55d098:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  55d09c:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  55d0a0:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  55d0a5:	8b cb                	mov    ecx,ebx
  55d0a7:	e8 44 80 19 00       	call   0x6f50f0
  55d0ac:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d0af:	83 f9 03             	cmp    ecx,0x3
  55d0b2:	74 33                	je     0x55d0e7
  55d0b4:	83 f9 04             	cmp    ecx,0x4
  55d0b7:	0f 85 4a 01 00 00    	jne    0x55d207
  55d0bd:	8b 30                	mov    esi,DWORD PTR [eax]
  55d0bf:	83 c6 10             	add    esi,0x10
  55d0c2:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d0c6:	e8 95 a6 19 00       	call   0x6f7760
  55d0cb:	85 c0                	test   eax,eax
  55d0cd:	0f 84 34 01 00 00    	je     0x55d207
  55d0d3:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d0d7:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55d0de:	00 
  55d0df:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55d0e3:	8d 44 24 24          	lea    eax,[esp+0x24]
  55d0e7:	dd 00                	fld    QWORD PTR [eax]
  55d0e9:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55d0ed:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d0f1:	db 5c 24 10          	fistp  DWORD PTR [esp+0x10]
  55d0f5:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  55d0f9:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  55d0fd:	83 c8 ff             	or     eax,0xffffffff
  55d100:	8b cb                	mov    ecx,ebx
  55d102:	e8 e9 7f 19 00       	call   0x6f50f0
  55d107:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d10a:	83 f9 03             	cmp    ecx,0x3
  55d10d:	74 2b                	je     0x55d13a
  55d10f:	83 f9 04             	cmp    ecx,0x4
  55d112:	75 34                	jne    0x55d148
  55d114:	8b 30                	mov    esi,DWORD PTR [eax]
  55d116:	83 c6 10             	add    esi,0x10
  55d119:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d11d:	e8 3e a6 19 00       	call   0x6f7760
  55d122:	85 c0                	test   eax,eax
  55d124:	74 22                	je     0x55d148
  55d126:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d12a:	c7 44 24 2c 03 00 00 	mov    DWORD PTR [esp+0x2c],0x3
  55d131:	00 
  55d132:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55d136:	8d 44 24 24          	lea    eax,[esp+0x24]
  55d13a:	dd 00                	fld    QWORD PTR [eax]
  55d13c:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55d140:	dd 44 24 24          	fld    QWORD PTR [esp+0x24]
  55d144:	db 5c 24 1c          	fistp  DWORD PTR [esp+0x1c]
  55d148:	b8 01 00 00 00       	mov    eax,0x1
  55d14d:	84 05 e8 1e fe 00    	test   BYTE PTR ds:0xfe1ee8,al
  55d153:	75 28                	jne    0x55d17d
  55d155:	09 05 e8 1e fe 00    	or     DWORD PTR ds:0xfe1ee8,eax
  55d15b:	c7 44 24 40 00 00 00 	mov    DWORD PTR [esp+0x40],0x0
  55d162:	00 
  55d163:	e8 a8 f4 ff ff       	call   0x55c610
  55d168:	68 90 f2 bc 00       	push   0xbcf290
  55d16d:	e8 a8 51 33 00       	call   0x89231a
  55d172:	83 c4 04             	add    esp,0x4
  55d175:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  55d17c:	ff 
  55d17d:	83 7c 24 14 00       	cmp    DWORD PTR [esp+0x14],0x0
  55d182:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  55d186:	74 50                	je     0x55d1d8
  55d188:	85 c0                	test   eax,eax
  55d18a:	79 05                	jns    0x55d191
  55d18c:	b8 04 00 00 00       	mov    eax,0x4
  55d191:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  55d195:	0f b7 44 24 18       	movzx  eax,WORD PTR [esp+0x18]
  55d19a:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  55d19e:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  55d1a2:	51                   	push   ecx
  55d1a3:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  55d1a7:	b9 f4 1e fe 00       	mov    ecx,0xfe1ef4
  55d1ac:	e8 cf 90 2c 00       	call   0x826280
  55d1b1:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  55d1b5:	3b 05 f8 1e fe 00    	cmp    eax,DWORD PTR ds:0xfe1ef8
  55d1bb:	74 1b                	je     0x55d1d8
  55d1bd:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  55d1c0:	8d 54 24 14          	lea    edx,[esp+0x14]
  55d1c4:	83 c6 04             	add    esi,0x4
  55d1c7:	52                   	push   edx
  55d1c8:	e8 e3 13 00 00       	call   0x55e5b0
  55d1cd:	50                   	push   eax
  55d1ce:	56                   	push   esi
  55d1cf:	8d 74 24 2c          	lea    esi,[esp+0x2c]
  55d1d3:	e8 68 59 eb ff       	call   0x412b40
  55d1d8:	33 c0                	xor    eax,eax
  55d1da:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  55d1de:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55d1e5:	59                   	pop    ecx
  55d1e6:	5f                   	pop    edi
  55d1e7:	5e                   	pop    esi
  55d1e8:	5b                   	pop    ebx
  55d1e9:	8b e5                	mov    esp,ebp
  55d1eb:	5d                   	pop    ebp
  55d1ec:	c3                   	ret
  55d1ed:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  55d1f4:	00 
  55d1f5:	e9 62 fd ff ff       	jmp    0x55cf5c
  55d1fa:	c7 44 24 14 00 00 00 	mov    DWORD PTR [esp+0x14],0x0
  55d201:	00 
  55d202:	e9 99 fe ff ff       	jmp    0x55d0a0
  55d207:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  55d20e:	00 
  55d20f:	e9 e9 fe ff ff       	jmp    0x55d0fd

# prepass-warp-object-callback

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055d220 <.text+0x15c220>:
  55d220:	55                   	push   ebp
  55d221:	8b ec                	mov    ebp,esp
  55d223:	83 e4 f8             	and    esp,0xfffffff8
  55d226:	6a ff                	push   0xffffffff
  55d228:	68 0e 8d 93 00       	push   0x938d0e
  55d22d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55d233:	50                   	push   eax
  55d234:	83 ec 30             	sub    esp,0x30
  55d237:	53                   	push   ebx
  55d238:	56                   	push   esi
  55d239:	57                   	push   edi
  55d23a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55d23f:	33 c4                	xor    eax,esp
  55d241:	50                   	push   eax
  55d242:	8d 44 24 40          	lea    eax,[esp+0x40]
  55d246:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55d24c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  55d24f:	b8 f9 ff ff ff       	mov    eax,0xfffffff9
  55d254:	8b cb                	mov    ecx,ebx
  55d256:	e8 95 7e 19 00       	call   0x6f50f0
  55d25b:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d25e:	83 f9 03             	cmp    ecx,0x3
  55d261:	74 33                	je     0x55d296
  55d263:	83 f9 04             	cmp    ecx,0x4
  55d266:	0f 85 c7 02 00 00    	jne    0x55d533
  55d26c:	8b 30                	mov    esi,DWORD PTR [eax]
  55d26e:	83 c6 10             	add    esi,0x10
  55d271:	8d 7c 24 24          	lea    edi,[esp+0x24]
  55d275:	e8 e6 a4 19 00       	call   0x6f7760
  55d27a:	85 c0                	test   eax,eax
  55d27c:	0f 84 b1 02 00 00    	je     0x55d533
  55d282:	dd 44 24 24          	fld    QWORD PTR [esp+0x24]
  55d286:	c7 44 24 34 03 00 00 	mov    DWORD PTR [esp+0x34],0x3
  55d28d:	00 
  55d28e:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55d292:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  55d296:	dd 00                	fld    QWORD PTR [eax]
  55d298:	dd 5c 24 24          	fstp   QWORD PTR [esp+0x24]
  55d29c:	dd 44 24 24          	fld    QWORD PTR [esp+0x24]
  55d2a0:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55d2a4:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  55d2a8:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  55d2ac:	b8 fa ff ff ff       	mov    eax,0xfffffffa
  55d2b1:	8b cb                	mov    ecx,ebx
  55d2b3:	e8 38 7e 19 00       	call   0x6f50f0
  55d2b8:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d2bb:	83 f9 03             	cmp    ecx,0x3
  55d2be:	74 2b                	je     0x55d2eb
  55d2c0:	83 f9 04             	cmp    ecx,0x4
  55d2c3:	75 34                	jne    0x55d2f9
  55d2c5:	8b 30                	mov    esi,DWORD PTR [eax]
  55d2c7:	83 c6 10             	add    esi,0x10
  55d2ca:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d2ce:	e8 8d a4 19 00       	call   0x6f7760
  55d2d3:	85 c0                	test   eax,eax
  55d2d5:	74 22                	je     0x55d2f9
  55d2d7:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d2db:	c7 44 24 34 03 00 00 	mov    DWORD PTR [esp+0x34],0x3
  55d2e2:	00 
  55d2e3:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55d2e7:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  55d2eb:	dd 00                	fld    QWORD PTR [eax]
  55d2ed:	dd 5c 24 14          	fstp   QWORD PTR [esp+0x14]
  55d2f1:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55d2f5:	db 5c 24 1c          	fistp  DWORD PTR [esp+0x1c]
  55d2f9:	b8 fb ff ff ff       	mov    eax,0xfffffffb
  55d2fe:	8b cb                	mov    ecx,ebx
  55d300:	e8 eb 7d 19 00       	call   0x6f50f0
  55d305:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d308:	83 f9 03             	cmp    ecx,0x3
  55d30b:	74 2b                	je     0x55d338
  55d30d:	83 f9 04             	cmp    ecx,0x4
  55d310:	75 34                	jne    0x55d346
  55d312:	8b 30                	mov    esi,DWORD PTR [eax]
  55d314:	83 c6 10             	add    esi,0x10
  55d317:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d31b:	e8 40 a4 19 00       	call   0x6f7760
  55d320:	85 c0                	test   eax,eax
  55d322:	74 22                	je     0x55d346
  55d324:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d328:	c7 44 24 34 03 00 00 	mov    DWORD PTR [esp+0x34],0x3
  55d32f:	00 
  55d330:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55d334:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  55d338:	dd 00                	fld    QWORD PTR [eax]
  55d33a:	dd 5c 24 14          	fstp   QWORD PTR [esp+0x14]
  55d33e:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55d342:	db 5c 24 1c          	fistp  DWORD PTR [esp+0x1c]
  55d346:	b8 fc ff ff ff       	mov    eax,0xfffffffc
  55d34b:	8b cb                	mov    ecx,ebx
  55d34d:	e8 9e 7d 19 00       	call   0x6f50f0
  55d352:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d355:	83 f9 03             	cmp    ecx,0x3
  55d358:	74 2b                	je     0x55d385
  55d35a:	83 f9 04             	cmp    ecx,0x4
  55d35d:	75 34                	jne    0x55d393
  55d35f:	8b 30                	mov    esi,DWORD PTR [eax]
  55d361:	83 c6 10             	add    esi,0x10
  55d364:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d368:	e8 f3 a3 19 00       	call   0x6f7760
  55d36d:	85 c0                	test   eax,eax
  55d36f:	74 22                	je     0x55d393
  55d371:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d375:	c7 44 24 34 03 00 00 	mov    DWORD PTR [esp+0x34],0x3
  55d37c:	00 
  55d37d:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55d381:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  55d385:	dd 00                	fld    QWORD PTR [eax]
  55d387:	dd 5c 24 14          	fstp   QWORD PTR [esp+0x14]
  55d38b:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55d38f:	db 5c 24 1c          	fistp  DWORD PTR [esp+0x1c]
  55d393:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  55d398:	8b cb                	mov    ecx,ebx
  55d39a:	e8 51 7d 19 00       	call   0x6f50f0
  55d39f:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d3a2:	83 f9 03             	cmp    ecx,0x3
  55d3a5:	74 2b                	je     0x55d3d2
  55d3a7:	83 f9 04             	cmp    ecx,0x4
  55d3aa:	75 34                	jne    0x55d3e0
  55d3ac:	8b 30                	mov    esi,DWORD PTR [eax]
  55d3ae:	83 c6 10             	add    esi,0x10
  55d3b1:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d3b5:	e8 a6 a3 19 00       	call   0x6f7760
  55d3ba:	85 c0                	test   eax,eax
  55d3bc:	74 22                	je     0x55d3e0
  55d3be:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d3c2:	c7 44 24 34 03 00 00 	mov    DWORD PTR [esp+0x34],0x3
  55d3c9:	00 
  55d3ca:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55d3ce:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  55d3d2:	dd 00                	fld    QWORD PTR [eax]
  55d3d4:	dd 5c 24 14          	fstp   QWORD PTR [esp+0x14]
  55d3d8:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55d3dc:	db 5c 24 1c          	fistp  DWORD PTR [esp+0x1c]
  55d3e0:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  55d3e5:	8b cb                	mov    ecx,ebx
  55d3e7:	e8 04 7d 19 00       	call   0x6f50f0
  55d3ec:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d3ef:	83 f9 03             	cmp    ecx,0x3
  55d3f2:	74 33                	je     0x55d427
  55d3f4:	83 f9 04             	cmp    ecx,0x4
  55d3f7:	0f 85 43 01 00 00    	jne    0x55d540
  55d3fd:	8b 30                	mov    esi,DWORD PTR [eax]
  55d3ff:	83 c6 10             	add    esi,0x10
  55d402:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  55d406:	e8 55 a3 19 00       	call   0x6f7760
  55d40b:	85 c0                	test   eax,eax
  55d40d:	0f 84 2d 01 00 00    	je     0x55d540
  55d413:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d417:	c7 44 24 34 03 00 00 	mov    DWORD PTR [esp+0x34],0x3
  55d41e:	00 
  55d41f:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55d423:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  55d427:	dd 00                	fld    QWORD PTR [eax]
  55d429:	dd 5c 24 1c          	fstp   QWORD PTR [esp+0x1c]
  55d42d:	dd 44 24 1c          	fld    QWORD PTR [esp+0x1c]
  55d431:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55d435:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  55d439:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  55d43d:	83 c8 ff             	or     eax,0xffffffff
  55d440:	8b cb                	mov    ecx,ebx
  55d442:	e8 a9 7c 19 00       	call   0x6f50f0
  55d447:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  55d44a:	83 f9 03             	cmp    ecx,0x3
  55d44d:	74 33                	je     0x55d482
  55d44f:	83 f9 04             	cmp    ecx,0x4
  55d452:	0f 85 f5 00 00 00    	jne    0x55d54d
  55d458:	8b 30                	mov    esi,DWORD PTR [eax]
  55d45a:	83 c6 10             	add    esi,0x10
  55d45d:	8d 7c 24 14          	lea    edi,[esp+0x14]
  55d461:	e8 fa a2 19 00       	call   0x6f7760
  55d466:	85 c0                	test   eax,eax
  55d468:	0f 84 df 00 00 00    	je     0x55d54d
  55d46e:	dd 44 24 14          	fld    QWORD PTR [esp+0x14]
  55d472:	c7 44 24 34 03 00 00 	mov    DWORD PTR [esp+0x34],0x3
  55d479:	00 
  55d47a:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55d47e:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  55d482:	dd 00                	fld    QWORD PTR [eax]
  55d484:	dd 5c 24 2c          	fstp   QWORD PTR [esp+0x2c]
  55d488:	dd 44 24 2c          	fld    QWORD PTR [esp+0x2c]
  55d48c:	db 5c 24 14          	fistp  DWORD PTR [esp+0x14]
  55d490:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  55d494:	bb 01 00 00 00       	mov    ebx,0x1
  55d499:	84 1d e8 1e fe 00    	test   BYTE PTR ds:0xfe1ee8,bl
  55d49f:	75 28                	jne    0x55d4c9
  55d4a1:	09 1d e8 1e fe 00    	or     DWORD PTR ds:0xfe1ee8,ebx
  55d4a7:	c7 44 24 48 00 00 00 	mov    DWORD PTR [esp+0x48],0x0
  55d4ae:	00 
  55d4af:	e8 5c f1 ff ff       	call   0x55c610
  55d4b4:	68 90 f2 bc 00       	push   0xbcf290
  55d4b9:	e8 5c 4e 33 00       	call   0x89231a
  55d4be:	83 c4 04             	add    esp,0x4
  55d4c1:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  55d4c8:	ff 
  55d4c9:	83 7c 24 1c 00       	cmp    DWORD PTR [esp+0x1c],0x0
  55d4ce:	8b c6                	mov    eax,esi
  55d4d0:	74 4c                	je     0x55d51e
  55d4d2:	0f b7 54 24 24       	movzx  edx,WORD PTR [esp+0x24]
  55d4d7:	85 f6                	test   esi,esi
  55d4d9:	0f 4c c3             	cmovl  eax,ebx
  55d4dc:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  55d4e0:	8d 44 24 24          	lea    eax,[esp+0x24]
  55d4e4:	50                   	push   eax
  55d4e5:	8d 44 24 20          	lea    eax,[esp+0x20]
  55d4e9:	b9 f4 1e fe 00       	mov    ecx,0xfe1ef4
  55d4ee:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  55d4f2:	e8 89 8d 2c 00       	call   0x826280
  55d4f7:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  55d4fb:	3b 05 f8 1e fe 00    	cmp    eax,DWORD PTR ds:0xfe1ef8
  55d501:	74 1b                	je     0x55d51e
  55d503:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  55d506:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  55d50a:	83 c6 04             	add    esi,0x4
  55d50d:	51                   	push   ecx
  55d50e:	e8 9d 10 00 00       	call   0x55e5b0
  55d513:	50                   	push   eax
  55d514:	56                   	push   esi
  55d515:	8d 74 24 34          	lea    esi,[esp+0x34]
  55d519:	e8 22 56 eb ff       	call   0x412b40
  55d51e:	33 c0                	xor    eax,eax
  55d520:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  55d524:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55d52b:	59                   	pop    ecx
  55d52c:	5f                   	pop    edi
  55d52d:	5e                   	pop    esi
  55d52e:	5b                   	pop    ebx
  55d52f:	8b e5                	mov    esp,ebp
  55d531:	5d                   	pop    ebp
  55d532:	c3                   	ret
  55d533:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  55d53a:	00 
  55d53b:	e9 6c fd ff ff       	jmp    0x55d2ac
  55d540:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  55d547:	00 
  55d548:	e9 f0 fe ff ff       	jmp    0x55d43d
  55d54d:	33 f6                	xor    esi,esi
  55d54f:	e9 40 ff ff ff       	jmp    0x55d494

# prepass-register-immediate-call

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055d560 <.text+0x15c560>:
  55d560:	55                   	push   ebp
  55d561:	8b ec                	mov    ebp,esp
  55d563:	83 e4 f8             	and    esp,0xfffffff8
  55d566:	83 ec 08             	sub    esp,0x8
  55d569:	56                   	push   esi
  55d56a:	57                   	push   edi
  55d56b:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  55d56e:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  55d571:	83 c0 f0             	add    eax,0xfffffff0
  55d574:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  55d579:	74 5b                	je     0x55d5d6
  55d57b:	83 78 08 06          	cmp    DWORD PTR [eax+0x8],0x6
  55d57f:	75 55                	jne    0x55d5d6
  55d581:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  55d585:	2b 47 20             	sub    eax,DWORD PTR [edi+0x20]
  55d588:	33 d2                	xor    edx,edx
  55d58a:	50                   	push   eax
  55d58b:	8d 44 24 0c          	lea    eax,[esp+0xc]
  55d58f:	50                   	push   eax
  55d590:	68 50 5a 6f 00       	push   0x6f5a50
  55d595:	8b c7                	mov    eax,edi
  55d597:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  55d59e:	00 
  55d59f:	e8 cc 11 1a 00       	call   0x6fe770
  55d5a4:	83 c4 0c             	add    esp,0xc
  55d5a7:	85 c0                	test   eax,eax
  55d5a9:	74 2b                	je     0x55d5d6
  55d5ab:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  55d5ae:	83 ee 10             	sub    esi,0x10
  55d5b1:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  55d5b5:	74 1b                	je     0x55d5d2
  55d5b7:	e8 14 e0 19 00       	call   0x6fb5d0
  55d5bc:	85 c0                	test   eax,eax
  55d5be:	74 12                	je     0x55d5d2
  55d5c0:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  55d5c3:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  55d5c6:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  55d5c9:	72 07                	jb     0x55d5d2
  55d5cb:	8b c7                	mov    eax,edi
  55d5cd:	e8 ce dd 19 00       	call   0x6fb3a0
  55d5d2:	83 47 08 f0          	add    DWORD PTR [edi+0x8],0xfffffff0
  55d5d6:	5f                   	pop    edi
  55d5d7:	33 c0                	xor    eax,eax
  55d5d9:	5e                   	pop    esi
  55d5da:	8b e5                	mov    esp,ebp
  55d5dc:	5d                   	pop    ebp
  55d5dd:	c3                   	ret

# prepass-play-music-name

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055d5e0 <.text+0x15c5e0>:
  55d5e0:	55                   	push   ebp
  55d5e1:	8b ec                	mov    ebp,esp
  55d5e3:	6a ff                	push   0xffffffff
  55d5e5:	68 de 8c 93 00       	push   0x938cde
  55d5ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55d5f0:	50                   	push   eax
  55d5f1:	51                   	push   ecx
  55d5f2:	56                   	push   esi
  55d5f3:	57                   	push   edi
  55d5f4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55d5f9:	33 c5                	xor    eax,ebp
  55d5fb:	50                   	push   eax
  55d5fc:	8d 45 f4             	lea    eax,[ebp-0xc]
  55d5ff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55d605:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  55d608:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  55d60b:	83 ee 10             	sub    esi,0x10
  55d60e:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  55d612:	74 21                	je     0x55d635
  55d614:	e8 b7 df 19 00       	call   0x6fb5d0
  55d619:	85 c0                	test   eax,eax
  55d61b:	74 6c                	je     0x55d689
  55d61d:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  55d620:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  55d623:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  55d626:	72 07                	jb     0x55d62f
  55d628:	8b c7                	mov    eax,edi
  55d62a:	e8 71 dd 19 00       	call   0x6fb3a0
  55d62f:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  55d632:	83 ee 10             	sub    esi,0x10
  55d635:	8b 36                	mov    esi,DWORD PTR [esi]
  55d637:	83 c6 10             	add    esi,0x10
  55d63a:	74 4d                	je     0x55d689
  55d63c:	b8 01 00 00 00       	mov    eax,0x1
  55d641:	84 05 e8 1e fe 00    	test   BYTE PTR ds:0xfe1ee8,al
  55d647:	75 26                	jne    0x55d66f
  55d649:	09 05 e8 1e fe 00    	or     DWORD PTR ds:0xfe1ee8,eax
  55d64f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  55d656:	e8 b5 ef ff ff       	call   0x55c610
  55d65b:	68 90 f2 bc 00       	push   0xbcf290
  55d660:	e8 b5 4c 33 00       	call   0x89231a
  55d665:	83 c4 04             	add    esp,0x4
  55d668:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  55d66f:	8b c6                	mov    eax,esi
  55d671:	8d 50 01             	lea    edx,[eax+0x1]
  55d674:	8a 08                	mov    cl,BYTE PTR [eax]
  55d676:	40                   	inc    eax
  55d677:	84 c9                	test   cl,cl
  55d679:	75 f9                	jne    0x55d674
  55d67b:	2b c2                	sub    eax,edx
  55d67d:	50                   	push   eax
  55d67e:	56                   	push   esi
  55d67f:	b9 04 1f fe 00       	mov    ecx,0xfe1f04
  55d684:	e8 e7 53 ea ff       	call   0x402a70
  55d689:	33 c0                	xor    eax,eax
  55d68b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  55d68e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55d695:	59                   	pop    ecx
  55d696:	5f                   	pop    edi
  55d697:	5e                   	pop    esi
  55d698:	8b e5                	mov    esp,ebp
  55d69a:	5d                   	pop    ebp
  55d69b:	c3                   	ret

# prepass-six-overrides-and-load

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055d6a0 <.text+0x15c6a0>:
  55d6a0:	55                   	push   ebp
  55d6a1:	8b ec                	mov    ebp,esp
  55d6a3:	51                   	push   ecx
  55d6a4:	53                   	push   ebx
  55d6a5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  55d6a8:	56                   	push   esi
  55d6a9:	8d 43 08             	lea    eax,[ebx+0x8]
  55d6ac:	57                   	push   edi
  55d6ad:	50                   	push   eax
  55d6ae:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  55d6b1:	e8 2a 0c 00 00       	call   0x55e2e0
  55d6b6:	83 c4 04             	add    esp,0x4
  55d6b9:	6a 00                	push   0x0
  55d6bb:	68 75 23 bf 00       	push   0xbf2375
  55d6c0:	8d 4b 18             	lea    ecx,[ebx+0x18]
  55d6c3:	e8 a8 53 ea ff       	call   0x402a70
  55d6c8:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d6cb:	8b 30                	mov    esi,DWORD PTR [eax]
  55d6cd:	6a 00                	push   0x0
  55d6cf:	68 40 c9 55 00       	push   0x55c940
  55d6d4:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d6d7:	e8 d4 7e 19 00       	call   0x6f55b0
  55d6dc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  55d6df:	8b 31                	mov    esi,DWORD PTR [ecx]
  55d6e1:	bf 30 02 c1 00       	mov    edi,0xc10230
  55d6e6:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d6eb:	e8 a0 80 19 00       	call   0x6f5790
  55d6f0:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d6f3:	8b 30                	mov    esi,DWORD PTR [eax]
  55d6f5:	6a 00                	push   0x0
  55d6f7:	68 e0 cc 55 00       	push   0x55cce0
  55d6fc:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d6ff:	e8 ac 7e 19 00       	call   0x6f55b0
  55d704:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  55d707:	8b 32                	mov    esi,DWORD PTR [edx]
  55d709:	bf 40 02 c1 00       	mov    edi,0xc10240
  55d70e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d713:	e8 78 80 19 00       	call   0x6f5790
  55d718:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d71b:	8b 30                	mov    esi,DWORD PTR [eax]
  55d71d:	6a 00                	push   0x0
  55d71f:	68 d0 ce 55 00       	push   0x55ced0
  55d724:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d727:	e8 84 7e 19 00       	call   0x6f55b0
  55d72c:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  55d72f:	8b 31                	mov    esi,DWORD PTR [ecx]
  55d731:	bf 4c 02 c1 00       	mov    edi,0xc1024c
  55d736:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d73b:	e8 50 80 19 00       	call   0x6f5790
  55d740:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d743:	8b 30                	mov    esi,DWORD PTR [eax]
  55d745:	6a 00                	push   0x0
  55d747:	68 20 d2 55 00       	push   0x55d220
  55d74c:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d74f:	e8 5c 7e 19 00       	call   0x6f55b0
  55d754:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  55d757:	8b 32                	mov    esi,DWORD PTR [edx]
  55d759:	bf 58 02 c1 00       	mov    edi,0xc10258
  55d75e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d763:	e8 28 80 19 00       	call   0x6f5790
  55d768:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d76b:	8b 30                	mov    esi,DWORD PTR [eax]
  55d76d:	6a 00                	push   0x0
  55d76f:	68 60 d5 55 00       	push   0x55d560
  55d774:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d777:	e8 34 7e 19 00       	call   0x6f55b0
  55d77c:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  55d77f:	8b 31                	mov    esi,DWORD PTR [ecx]
  55d781:	bf 64 02 c1 00       	mov    edi,0xc10264
  55d786:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d78b:	e8 00 80 19 00       	call   0x6f5790
  55d790:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  55d793:	8b 30                	mov    esi,DWORD PTR [eax]
  55d795:	6a 00                	push   0x0
  55d797:	68 e0 d5 55 00       	push   0x55d5e0
  55d79c:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  55d79f:	e8 0c 7e 19 00       	call   0x6f55b0
  55d7a4:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  55d7a7:	8b 32                	mov    esi,DWORD PTR [edx]
  55d7a9:	83 c4 30             	add    esp,0x30
  55d7ac:	bf 70 02 c1 00       	mov    edi,0xc10270
  55d7b1:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d7b6:	e8 d5 7f 19 00       	call   0x6f5790
  55d7bb:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  55d7be:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  55d7c1:	50                   	push   eax
  55d7c2:	e8 89 72 19 00       	call   0x6f4a50
  55d7c7:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  55d7ca:	5f                   	pop    edi
  55d7cb:	5e                   	pop    esi
  55d7cc:	5b                   	pop    ebx
  55d7cd:	8b e5                	mov    esp,ebp
  55d7cf:	5d                   	pop    ebp
  55d7d0:	c2 08 00             	ret    0x8

# prepass-default-bindings

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055d7e0 <.text+0x15c7e0>:
  55d7e0:	55                   	push   ebp
  55d7e1:	8b ec                	mov    ebp,esp
  55d7e3:	51                   	push   ecx
  55d7e4:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d7e9:	53                   	push   ebx
  55d7ea:	56                   	push   esi
  55d7eb:	8b 30                	mov    esi,DWORD PTR [eax]
  55d7ed:	57                   	push   edi
  55d7ee:	6a 00                	push   0x0
  55d7f0:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d7f5:	8b d8                	mov    ebx,eax
  55d7f7:	e8 b4 7d 19 00       	call   0x6f55b0
  55d7fc:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d7fe:	bf 7c 02 c1 00       	mov    edi,0xc1027c
  55d803:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d808:	e8 83 7f 19 00       	call   0x6f5790
  55d80d:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d812:	8b 30                	mov    esi,DWORD PTR [eax]
  55d814:	6a 00                	push   0x0
  55d816:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d81b:	8b d8                	mov    ebx,eax
  55d81d:	e8 8e 7d 19 00       	call   0x6f55b0
  55d822:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d824:	bf 84 02 c1 00       	mov    edi,0xc10284
  55d829:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d82e:	e8 5d 7f 19 00       	call   0x6f5790
  55d833:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d838:	8b 30                	mov    esi,DWORD PTR [eax]
  55d83a:	6a 00                	push   0x0
  55d83c:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d841:	8b d8                	mov    ebx,eax
  55d843:	e8 68 7d 19 00       	call   0x6f55b0
  55d848:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d84a:	bf 40 dd c0 00       	mov    edi,0xc0dd40
  55d84f:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d854:	e8 37 7f 19 00       	call   0x6f5790
  55d859:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d85e:	8b 30                	mov    esi,DWORD PTR [eax]
  55d860:	6a 00                	push   0x0
  55d862:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d867:	8b d8                	mov    ebx,eax
  55d869:	e8 42 7d 19 00       	call   0x6f55b0
  55d86e:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d870:	bf 50 dd c0 00       	mov    edi,0xc0dd50
  55d875:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d87a:	e8 11 7f 19 00       	call   0x6f5790
  55d87f:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d884:	8b 30                	mov    esi,DWORD PTR [eax]
  55d886:	6a 00                	push   0x0
  55d888:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d88d:	8b d8                	mov    ebx,eax
  55d88f:	e8 1c 7d 19 00       	call   0x6f55b0
  55d894:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d896:	bf 8c 02 c1 00       	mov    edi,0xc1028c
  55d89b:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d8a0:	e8 eb 7e 19 00       	call   0x6f5790
  55d8a5:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d8aa:	8b 30                	mov    esi,DWORD PTR [eax]
  55d8ac:	6a 00                	push   0x0
  55d8ae:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d8b3:	8b d8                	mov    ebx,eax
  55d8b5:	e8 f6 7c 19 00       	call   0x6f55b0
  55d8ba:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d8bc:	bf 98 02 c1 00       	mov    edi,0xc10298
  55d8c1:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d8c6:	e8 c5 7e 19 00       	call   0x6f5790
  55d8cb:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d8d0:	8b 30                	mov    esi,DWORD PTR [eax]
  55d8d2:	6a 00                	push   0x0
  55d8d4:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d8d9:	8b d8                	mov    ebx,eax
  55d8db:	e8 d0 7c 19 00       	call   0x6f55b0
  55d8e0:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d8e2:	bf ac 02 c1 00       	mov    edi,0xc102ac
  55d8e7:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d8ec:	e8 9f 7e 19 00       	call   0x6f5790
  55d8f1:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d8f6:	8b 30                	mov    esi,DWORD PTR [eax]
  55d8f8:	6a 00                	push   0x0
  55d8fa:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d8ff:	8b d8                	mov    ebx,eax
  55d901:	e8 aa 7c 19 00       	call   0x6f55b0
  55d906:	83 c4 40             	add    esp,0x40
  55d909:	bf b8 02 c1 00       	mov    edi,0xc102b8
  55d90e:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d910:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d915:	e8 76 7e 19 00       	call   0x6f5790
  55d91a:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d91f:	8b 30                	mov    esi,DWORD PTR [eax]
  55d921:	6a 00                	push   0x0
  55d923:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d928:	8b d8                	mov    ebx,eax
  55d92a:	e8 81 7c 19 00       	call   0x6f55b0
  55d92f:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d931:	bf c8 02 c1 00       	mov    edi,0xc102c8
  55d936:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d93b:	e8 50 7e 19 00       	call   0x6f5790
  55d940:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d945:	8b 30                	mov    esi,DWORD PTR [eax]
  55d947:	6a 00                	push   0x0
  55d949:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d94e:	8b d8                	mov    ebx,eax
  55d950:	e8 5b 7c 19 00       	call   0x6f55b0
  55d955:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d957:	bf d8 02 c1 00       	mov    edi,0xc102d8
  55d95c:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d961:	e8 2a 7e 19 00       	call   0x6f5790
  55d966:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d96b:	8b 30                	mov    esi,DWORD PTR [eax]
  55d96d:	6a 00                	push   0x0
  55d96f:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d974:	8b d8                	mov    ebx,eax
  55d976:	e8 35 7c 19 00       	call   0x6f55b0
  55d97b:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d97d:	bf e8 02 c1 00       	mov    edi,0xc102e8
  55d982:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d987:	e8 04 7e 19 00       	call   0x6f5790
  55d98c:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d991:	8b 30                	mov    esi,DWORD PTR [eax]
  55d993:	6a 00                	push   0x0
  55d995:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d99a:	8b d8                	mov    ebx,eax
  55d99c:	e8 0f 7c 19 00       	call   0x6f55b0
  55d9a1:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d9a3:	bf f4 02 c1 00       	mov    edi,0xc102f4
  55d9a8:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d9ad:	e8 de 7d 19 00       	call   0x6f5790
  55d9b2:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d9b7:	8b 30                	mov    esi,DWORD PTR [eax]
  55d9b9:	6a 00                	push   0x0
  55d9bb:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d9c0:	8b d8                	mov    ebx,eax
  55d9c2:	e8 e9 7b 19 00       	call   0x6f55b0
  55d9c7:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d9c9:	bf 08 03 c1 00       	mov    edi,0xc10308
  55d9ce:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d9d3:	e8 b8 7d 19 00       	call   0x6f5790
  55d9d8:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55d9dd:	8b 30                	mov    esi,DWORD PTR [eax]
  55d9df:	6a 00                	push   0x0
  55d9e1:	68 f0 c2 8d 00       	push   0x8dc2f0
  55d9e6:	8b d8                	mov    ebx,eax
  55d9e8:	e8 c3 7b 19 00       	call   0x6f55b0
  55d9ed:	8b 33                	mov    esi,DWORD PTR [ebx]
  55d9ef:	bf 14 03 c1 00       	mov    edi,0xc10314
  55d9f4:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55d9f9:	e8 92 7d 19 00       	call   0x6f5790
  55d9fe:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55da03:	8b 30                	mov    esi,DWORD PTR [eax]
  55da05:	6a 00                	push   0x0
  55da07:	68 f0 c2 8d 00       	push   0x8dc2f0
  55da0c:	8b d8                	mov    ebx,eax
  55da0e:	e8 9d 7b 19 00       	call   0x6f55b0
  55da13:	8b 33                	mov    esi,DWORD PTR [ebx]
  55da15:	bf 20 03 c1 00       	mov    edi,0xc10320
  55da1a:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55da1f:	e8 6c 7d 19 00       	call   0x6f5790
  55da24:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55da29:	8b 30                	mov    esi,DWORD PTR [eax]
  55da2b:	6a 00                	push   0x0
  55da2d:	68 f0 c2 8d 00       	push   0x8dc2f0
  55da32:	8b d8                	mov    ebx,eax
  55da34:	e8 77 7b 19 00       	call   0x6f55b0
  55da39:	83 c4 40             	add    esp,0x40
  55da3c:	bf 30 03 c1 00       	mov    edi,0xc10330
  55da41:	8b 33                	mov    esi,DWORD PTR [ebx]
  55da43:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55da48:	e8 43 7d 19 00       	call   0x6f5790
  55da4d:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55da52:	8b 30                	mov    esi,DWORD PTR [eax]
  55da54:	6a 00                	push   0x0
  55da56:	68 f0 c2 8d 00       	push   0x8dc2f0
  55da5b:	8b d8                	mov    ebx,eax
  55da5d:	e8 4e 7b 19 00       	call   0x6f55b0
  55da62:	8b 33                	mov    esi,DWORD PTR [ebx]
  55da64:	bf 44 03 c1 00       	mov    edi,0xc10344
  55da69:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55da6e:	e8 1d 7d 19 00       	call   0x6f5790
  55da73:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55da78:	8b 30                	mov    esi,DWORD PTR [eax]
  55da7a:	6a 00                	push   0x0
  55da7c:	68 f0 c2 8d 00       	push   0x8dc2f0
  55da81:	8b d8                	mov    ebx,eax
  55da83:	e8 28 7b 19 00       	call   0x6f55b0
  55da88:	8b 33                	mov    esi,DWORD PTR [ebx]
  55da8a:	bf 58 03 c1 00       	mov    edi,0xc10358
  55da8f:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55da94:	e8 f7 7c 19 00       	call   0x6f5790
  55da99:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55da9e:	8b 30                	mov    esi,DWORD PTR [eax]
  55daa0:	6a 00                	push   0x0
  55daa2:	68 f0 c2 8d 00       	push   0x8dc2f0
  55daa7:	8b d8                	mov    ebx,eax
  55daa9:	e8 02 7b 19 00       	call   0x6f55b0
  55daae:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dab0:	bf 74 03 c1 00       	mov    edi,0xc10374
  55dab5:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55daba:	e8 d1 7c 19 00       	call   0x6f5790
  55dabf:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dac4:	8b 30                	mov    esi,DWORD PTR [eax]
  55dac6:	6a 00                	push   0x0
  55dac8:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dacd:	8b d8                	mov    ebx,eax
  55dacf:	e8 dc 7a 19 00       	call   0x6f55b0
  55dad4:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dad6:	bf 80 03 c1 00       	mov    edi,0xc10380
  55dadb:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dae0:	e8 ab 7c 19 00       	call   0x6f5790
  55dae5:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55daea:	8b 30                	mov    esi,DWORD PTR [eax]
  55daec:	6a 00                	push   0x0
  55daee:	68 f0 c2 8d 00       	push   0x8dc2f0
  55daf3:	8b d8                	mov    ebx,eax
  55daf5:	e8 b6 7a 19 00       	call   0x6f55b0
  55dafa:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dafc:	bf 98 03 c1 00       	mov    edi,0xc10398
  55db01:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55db06:	e8 85 7c 19 00       	call   0x6f5790
  55db0b:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55db10:	8b 30                	mov    esi,DWORD PTR [eax]
  55db12:	6a 00                	push   0x0
  55db14:	68 f0 c2 8d 00       	push   0x8dc2f0
  55db19:	8b d8                	mov    ebx,eax
  55db1b:	e8 90 7a 19 00       	call   0x6f55b0
  55db20:	8b 33                	mov    esi,DWORD PTR [ebx]
  55db22:	bf ac 03 c1 00       	mov    edi,0xc103ac
  55db27:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55db2c:	e8 5f 7c 19 00       	call   0x6f5790
  55db31:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55db36:	8b 30                	mov    esi,DWORD PTR [eax]
  55db38:	6a 00                	push   0x0
  55db3a:	68 f0 c2 8d 00       	push   0x8dc2f0
  55db3f:	8b d8                	mov    ebx,eax
  55db41:	e8 6a 7a 19 00       	call   0x6f55b0
  55db46:	8b 33                	mov    esi,DWORD PTR [ebx]
  55db48:	bf 4c 02 c1 00       	mov    edi,0xc1024c
  55db4d:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55db52:	e8 39 7c 19 00       	call   0x6f5790
  55db57:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55db5c:	8b 30                	mov    esi,DWORD PTR [eax]
  55db5e:	6a 00                	push   0x0
  55db60:	68 f0 c2 8d 00       	push   0x8dc2f0
  55db65:	8b d8                	mov    ebx,eax
  55db67:	e8 44 7a 19 00       	call   0x6f55b0
  55db6c:	83 c4 40             	add    esp,0x40
  55db6f:	bf 58 02 c1 00       	mov    edi,0xc10258
  55db74:	8b 33                	mov    esi,DWORD PTR [ebx]
  55db76:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55db7b:	e8 10 7c 19 00       	call   0x6f5790
  55db80:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55db85:	8b 30                	mov    esi,DWORD PTR [eax]
  55db87:	6a 00                	push   0x0
  55db89:	68 f0 c2 8d 00       	push   0x8dc2f0
  55db8e:	8b d8                	mov    ebx,eax
  55db90:	e8 1b 7a 19 00       	call   0x6f55b0
  55db95:	8b 33                	mov    esi,DWORD PTR [ebx]
  55db97:	bf c8 03 c1 00       	mov    edi,0xc103c8
  55db9c:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dba1:	e8 ea 7b 19 00       	call   0x6f5790
  55dba6:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dbab:	8b 30                	mov    esi,DWORD PTR [eax]
  55dbad:	6a 00                	push   0x0
  55dbaf:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dbb4:	8b d8                	mov    ebx,eax
  55dbb6:	e8 f5 79 19 00       	call   0x6f55b0
  55dbbb:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dbbd:	bf 40 02 c1 00       	mov    edi,0xc10240
  55dbc2:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dbc7:	e8 c4 7b 19 00       	call   0x6f5790
  55dbcc:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dbd1:	8b 30                	mov    esi,DWORD PTR [eax]
  55dbd3:	6a 00                	push   0x0
  55dbd5:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dbda:	8b d8                	mov    ebx,eax
  55dbdc:	e8 cf 79 19 00       	call   0x6f55b0
  55dbe1:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dbe3:	bf d8 03 c1 00       	mov    edi,0xc103d8
  55dbe8:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dbed:	e8 9e 7b 19 00       	call   0x6f5790
  55dbf2:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dbf7:	8b 30                	mov    esi,DWORD PTR [eax]
  55dbf9:	6a 00                	push   0x0
  55dbfb:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dc00:	8b d8                	mov    ebx,eax
  55dc02:	e8 a9 79 19 00       	call   0x6f55b0
  55dc07:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dc09:	bf e0 03 c1 00       	mov    edi,0xc103e0
  55dc0e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dc13:	e8 78 7b 19 00       	call   0x6f5790
  55dc18:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dc1d:	8b 30                	mov    esi,DWORD PTR [eax]
  55dc1f:	6a 00                	push   0x0
  55dc21:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dc26:	8b d8                	mov    ebx,eax
  55dc28:	e8 83 79 19 00       	call   0x6f55b0
  55dc2d:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dc2f:	bf ec 03 c1 00       	mov    edi,0xc103ec
  55dc34:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dc39:	e8 52 7b 19 00       	call   0x6f5790
  55dc3e:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dc43:	8b 30                	mov    esi,DWORD PTR [eax]
  55dc45:	6a 00                	push   0x0
  55dc47:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dc4c:	8b d8                	mov    ebx,eax
  55dc4e:	e8 5d 79 19 00       	call   0x6f55b0
  55dc53:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dc55:	bf f8 03 c1 00       	mov    edi,0xc103f8
  55dc5a:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dc5f:	e8 2c 7b 19 00       	call   0x6f5790
  55dc64:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dc69:	8b 30                	mov    esi,DWORD PTR [eax]
  55dc6b:	6a 00                	push   0x0
  55dc6d:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dc72:	8b d8                	mov    ebx,eax
  55dc74:	e8 37 79 19 00       	call   0x6f55b0
  55dc79:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dc7b:	bf 04 04 c1 00       	mov    edi,0xc10404
  55dc80:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dc85:	e8 06 7b 19 00       	call   0x6f5790
  55dc8a:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dc8f:	8b 30                	mov    esi,DWORD PTR [eax]
  55dc91:	6a 00                	push   0x0
  55dc93:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dc98:	8b d8                	mov    ebx,eax
  55dc9a:	e8 11 79 19 00       	call   0x6f55b0
  55dc9f:	83 c4 40             	add    esp,0x40
  55dca2:	bf 10 04 c1 00       	mov    edi,0xc10410
  55dca7:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dca9:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dcae:	e8 dd 7a 19 00       	call   0x6f5790
  55dcb3:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dcb8:	8b 30                	mov    esi,DWORD PTR [eax]
  55dcba:	6a 00                	push   0x0
  55dcbc:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dcc1:	8b d8                	mov    ebx,eax
  55dcc3:	e8 e8 78 19 00       	call   0x6f55b0
  55dcc8:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dcca:	bf 1c 04 c1 00       	mov    edi,0xc1041c
  55dccf:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dcd4:	e8 b7 7a 19 00       	call   0x6f5790
  55dcd9:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dcde:	8b 30                	mov    esi,DWORD PTR [eax]
  55dce0:	6a 00                	push   0x0
  55dce2:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dce7:	8b d8                	mov    ebx,eax
  55dce9:	e8 c2 78 19 00       	call   0x6f55b0
  55dcee:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dcf0:	bf 2c 04 c1 00       	mov    edi,0xc1042c
  55dcf5:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dcfa:	e8 91 7a 19 00       	call   0x6f5790
  55dcff:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dd04:	8b 30                	mov    esi,DWORD PTR [eax]
  55dd06:	6a 00                	push   0x0
  55dd08:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dd0d:	8b d8                	mov    ebx,eax
  55dd0f:	e8 9c 78 19 00       	call   0x6f55b0
  55dd14:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dd16:	bf 38 04 c1 00       	mov    edi,0xc10438
  55dd1b:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dd20:	e8 6b 7a 19 00       	call   0x6f5790
  55dd25:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dd2a:	8b 30                	mov    esi,DWORD PTR [eax]
  55dd2c:	6a 00                	push   0x0
  55dd2e:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dd33:	8b d8                	mov    ebx,eax
  55dd35:	e8 76 78 19 00       	call   0x6f55b0
  55dd3a:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dd3c:	bf 48 04 c1 00       	mov    edi,0xc10448
  55dd41:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dd46:	e8 45 7a 19 00       	call   0x6f5790
  55dd4b:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dd50:	8b 30                	mov    esi,DWORD PTR [eax]
  55dd52:	6a 00                	push   0x0
  55dd54:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dd59:	8b d8                	mov    ebx,eax
  55dd5b:	e8 50 78 19 00       	call   0x6f55b0
  55dd60:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dd62:	bf 58 04 c1 00       	mov    edi,0xc10458
  55dd67:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dd6c:	e8 1f 7a 19 00       	call   0x6f5790
  55dd71:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dd76:	8b 30                	mov    esi,DWORD PTR [eax]
  55dd78:	6a 00                	push   0x0
  55dd7a:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dd7f:	8b d8                	mov    ebx,eax
  55dd81:	e8 2a 78 19 00       	call   0x6f55b0
  55dd86:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dd88:	bf 68 04 c1 00       	mov    edi,0xc10468
  55dd8d:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dd92:	e8 f9 79 19 00       	call   0x6f5790
  55dd97:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dd9c:	8b 30                	mov    esi,DWORD PTR [eax]
  55dd9e:	6a 00                	push   0x0
  55dda0:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dda5:	8b d8                	mov    ebx,eax
  55dda7:	e8 04 78 19 00       	call   0x6f55b0
  55ddac:	8b 33                	mov    esi,DWORD PTR [ebx]
  55ddae:	bf 74 04 c1 00       	mov    edi,0xc10474
  55ddb3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55ddb8:	e8 d3 79 19 00       	call   0x6f5790
  55ddbd:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55ddc2:	8b 30                	mov    esi,DWORD PTR [eax]
  55ddc4:	6a 00                	push   0x0
  55ddc6:	68 f0 c2 8d 00       	push   0x8dc2f0
  55ddcb:	8b d8                	mov    ebx,eax
  55ddcd:	e8 de 77 19 00       	call   0x6f55b0
  55ddd2:	83 c4 40             	add    esp,0x40
  55ddd5:	bf 84 04 c1 00       	mov    edi,0xc10484
  55ddda:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dddc:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dde1:	e8 aa 79 19 00       	call   0x6f5790
  55dde6:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55ddeb:	8b 30                	mov    esi,DWORD PTR [eax]
  55dded:	6a 00                	push   0x0
  55ddef:	68 f0 c2 8d 00       	push   0x8dc2f0
  55ddf4:	8b d8                	mov    ebx,eax
  55ddf6:	e8 b5 77 19 00       	call   0x6f55b0
  55ddfb:	8b 33                	mov    esi,DWORD PTR [ebx]
  55ddfd:	bf 94 04 c1 00       	mov    edi,0xc10494
  55de02:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55de07:	e8 84 79 19 00       	call   0x6f5790
  55de0c:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55de11:	8b 30                	mov    esi,DWORD PTR [eax]
  55de13:	6a 00                	push   0x0
  55de15:	68 f0 c2 8d 00       	push   0x8dc2f0
  55de1a:	8b d8                	mov    ebx,eax
  55de1c:	e8 8f 77 19 00       	call   0x6f55b0
  55de21:	8b 33                	mov    esi,DWORD PTR [ebx]
  55de23:	bf a0 04 c1 00       	mov    edi,0xc104a0
  55de28:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55de2d:	e8 5e 79 19 00       	call   0x6f5790
  55de32:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55de37:	8b 30                	mov    esi,DWORD PTR [eax]
  55de39:	6a 00                	push   0x0
  55de3b:	68 f0 c2 8d 00       	push   0x8dc2f0
  55de40:	8b d8                	mov    ebx,eax
  55de42:	e8 69 77 19 00       	call   0x6f55b0
  55de47:	8b 33                	mov    esi,DWORD PTR [ebx]
  55de49:	bf ac 04 c1 00       	mov    edi,0xc104ac
  55de4e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55de53:	e8 38 79 19 00       	call   0x6f5790
  55de58:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55de5d:	8b 30                	mov    esi,DWORD PTR [eax]
  55de5f:	6a 00                	push   0x0
  55de61:	68 f0 c2 8d 00       	push   0x8dc2f0
  55de66:	8b d8                	mov    ebx,eax
  55de68:	e8 43 77 19 00       	call   0x6f55b0
  55de6d:	8b 33                	mov    esi,DWORD PTR [ebx]
  55de6f:	bf b8 04 c1 00       	mov    edi,0xc104b8
  55de74:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55de79:	e8 12 79 19 00       	call   0x6f5790
  55de7e:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55de83:	8b 30                	mov    esi,DWORD PTR [eax]
  55de85:	6a 00                	push   0x0
  55de87:	68 f0 c2 8d 00       	push   0x8dc2f0
  55de8c:	8b d8                	mov    ebx,eax
  55de8e:	e8 1d 77 19 00       	call   0x6f55b0
  55de93:	8b 33                	mov    esi,DWORD PTR [ebx]
  55de95:	bf c4 04 c1 00       	mov    edi,0xc104c4
  55de9a:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55de9f:	e8 ec 78 19 00       	call   0x6f5790
  55dea4:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dea9:	8b 30                	mov    esi,DWORD PTR [eax]
  55deab:	6a 00                	push   0x0
  55dead:	68 f0 c2 8d 00       	push   0x8dc2f0
  55deb2:	8b d8                	mov    ebx,eax
  55deb4:	e8 f7 76 19 00       	call   0x6f55b0
  55deb9:	8b 33                	mov    esi,DWORD PTR [ebx]
  55debb:	bf d4 04 c1 00       	mov    edi,0xc104d4
  55dec0:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dec5:	e8 c6 78 19 00       	call   0x6f5790
  55deca:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55decf:	8b 30                	mov    esi,DWORD PTR [eax]
  55ded1:	6a 00                	push   0x0
  55ded3:	68 f0 c2 8d 00       	push   0x8dc2f0
  55ded8:	8b d8                	mov    ebx,eax
  55deda:	e8 d1 76 19 00       	call   0x6f55b0
  55dedf:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dee1:	bf dc 04 c1 00       	mov    edi,0xc104dc
  55dee6:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55deeb:	e8 a0 78 19 00       	call   0x6f5790
  55def0:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55def5:	8b 30                	mov    esi,DWORD PTR [eax]
  55def7:	6a 00                	push   0x0
  55def9:	68 f0 c2 8d 00       	push   0x8dc2f0
  55defe:	8b d8                	mov    ebx,eax
  55df00:	e8 ab 76 19 00       	call   0x6f55b0
  55df05:	83 c4 40             	add    esp,0x40
  55df08:	bf e4 04 c1 00       	mov    edi,0xc104e4
  55df0d:	8b 33                	mov    esi,DWORD PTR [ebx]
  55df0f:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55df14:	e8 77 78 19 00       	call   0x6f5790
  55df19:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55df1e:	8b 30                	mov    esi,DWORD PTR [eax]
  55df20:	6a 00                	push   0x0
  55df22:	68 f0 c2 8d 00       	push   0x8dc2f0
  55df27:	8b d8                	mov    ebx,eax
  55df29:	e8 82 76 19 00       	call   0x6f55b0
  55df2e:	8b 33                	mov    esi,DWORD PTR [ebx]
  55df30:	bf f0 04 c1 00       	mov    edi,0xc104f0
  55df35:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55df3a:	e8 51 78 19 00       	call   0x6f5790
  55df3f:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55df44:	8b 30                	mov    esi,DWORD PTR [eax]
  55df46:	6a 00                	push   0x0
  55df48:	68 f0 c2 8d 00       	push   0x8dc2f0
  55df4d:	8b d8                	mov    ebx,eax
  55df4f:	e8 5c 76 19 00       	call   0x6f55b0
  55df54:	8b 33                	mov    esi,DWORD PTR [ebx]
  55df56:	bf 00 05 c1 00       	mov    edi,0xc10500
  55df5b:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55df60:	e8 2b 78 19 00       	call   0x6f5790
  55df65:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55df6a:	8b 30                	mov    esi,DWORD PTR [eax]
  55df6c:	6a 00                	push   0x0
  55df6e:	68 f0 c2 8d 00       	push   0x8dc2f0
  55df73:	8b d8                	mov    ebx,eax
  55df75:	e8 36 76 19 00       	call   0x6f55b0
  55df7a:	8b 33                	mov    esi,DWORD PTR [ebx]
  55df7c:	bf 08 05 c1 00       	mov    edi,0xc10508
  55df81:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55df86:	e8 05 78 19 00       	call   0x6f5790
  55df8b:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55df90:	8b 30                	mov    esi,DWORD PTR [eax]
  55df92:	6a 00                	push   0x0
  55df94:	68 f0 c2 8d 00       	push   0x8dc2f0
  55df99:	8b d8                	mov    ebx,eax
  55df9b:	e8 10 76 19 00       	call   0x6f55b0
  55dfa0:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dfa2:	bf 14 05 c1 00       	mov    edi,0xc10514
  55dfa7:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dfac:	e8 df 77 19 00       	call   0x6f5790
  55dfb1:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dfb6:	8b 30                	mov    esi,DWORD PTR [eax]
  55dfb8:	6a 00                	push   0x0
  55dfba:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dfbf:	8b d8                	mov    ebx,eax
  55dfc1:	e8 ea 75 19 00       	call   0x6f55b0
  55dfc6:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dfc8:	bf 20 05 c1 00       	mov    edi,0xc10520
  55dfcd:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dfd2:	e8 b9 77 19 00       	call   0x6f5790
  55dfd7:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55dfdc:	8b 30                	mov    esi,DWORD PTR [eax]
  55dfde:	6a 00                	push   0x0
  55dfe0:	68 f0 c2 8d 00       	push   0x8dc2f0
  55dfe5:	8b d8                	mov    ebx,eax
  55dfe7:	e8 c4 75 19 00       	call   0x6f55b0
  55dfec:	8b 33                	mov    esi,DWORD PTR [ebx]
  55dfee:	bf 2c 05 c1 00       	mov    edi,0xc1052c
  55dff3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55dff8:	e8 93 77 19 00       	call   0x6f5790
  55dffd:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e002:	8b 30                	mov    esi,DWORD PTR [eax]
  55e004:	6a 00                	push   0x0
  55e006:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e00b:	8b d8                	mov    ebx,eax
  55e00d:	e8 9e 75 19 00       	call   0x6f55b0
  55e012:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e014:	bf 38 05 c1 00       	mov    edi,0xc10538
  55e019:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e01e:	e8 6d 77 19 00       	call   0x6f5790
  55e023:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e028:	8b 30                	mov    esi,DWORD PTR [eax]
  55e02a:	6a 00                	push   0x0
  55e02c:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e031:	8b d8                	mov    ebx,eax
  55e033:	e8 78 75 19 00       	call   0x6f55b0
  55e038:	83 c4 40             	add    esp,0x40
  55e03b:	bf 40 05 c1 00       	mov    edi,0xc10540
  55e040:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e042:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e047:	e8 44 77 19 00       	call   0x6f5790
  55e04c:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e051:	8b 30                	mov    esi,DWORD PTR [eax]
  55e053:	6a 00                	push   0x0
  55e055:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e05a:	8b d8                	mov    ebx,eax
  55e05c:	e8 4f 75 19 00       	call   0x6f55b0
  55e061:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e063:	bf 4c 05 c1 00       	mov    edi,0xc1054c
  55e068:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e06d:	e8 1e 77 19 00       	call   0x6f5790
  55e072:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e077:	8b 30                	mov    esi,DWORD PTR [eax]
  55e079:	6a 00                	push   0x0
  55e07b:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e080:	8b d8                	mov    ebx,eax
  55e082:	e8 29 75 19 00       	call   0x6f55b0
  55e087:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e089:	bf 54 05 c1 00       	mov    edi,0xc10554
  55e08e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e093:	e8 f8 76 19 00       	call   0x6f5790
  55e098:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e09d:	8b 30                	mov    esi,DWORD PTR [eax]
  55e09f:	6a 00                	push   0x0
  55e0a1:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e0a6:	8b d8                	mov    ebx,eax
  55e0a8:	e8 03 75 19 00       	call   0x6f55b0
  55e0ad:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e0af:	bf 30 02 c1 00       	mov    edi,0xc10230
  55e0b4:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e0b9:	e8 d2 76 19 00       	call   0x6f5790
  55e0be:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e0c3:	8b 30                	mov    esi,DWORD PTR [eax]
  55e0c5:	6a 00                	push   0x0
  55e0c7:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e0cc:	8b d8                	mov    ebx,eax
  55e0ce:	e8 dd 74 19 00       	call   0x6f55b0
  55e0d3:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e0d5:	bf 60 05 c1 00       	mov    edi,0xc10560
  55e0da:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e0df:	e8 ac 76 19 00       	call   0x6f5790
  55e0e4:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e0e9:	8b 30                	mov    esi,DWORD PTR [eax]
  55e0eb:	6a 00                	push   0x0
  55e0ed:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e0f2:	8b d8                	mov    ebx,eax
  55e0f4:	e8 b7 74 19 00       	call   0x6f55b0
  55e0f9:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e0fb:	bf 74 05 c1 00       	mov    edi,0xc10574
  55e100:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e105:	e8 86 76 19 00       	call   0x6f5790
  55e10a:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e10f:	8b 30                	mov    esi,DWORD PTR [eax]
  55e111:	6a 00                	push   0x0
  55e113:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e118:	8b d8                	mov    ebx,eax
  55e11a:	e8 91 74 19 00       	call   0x6f55b0
  55e11f:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e121:	bf 84 05 c1 00       	mov    edi,0xc10584
  55e126:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e12b:	e8 60 76 19 00       	call   0x6f5790
  55e130:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e135:	8b 30                	mov    esi,DWORD PTR [eax]
  55e137:	6a 00                	push   0x0
  55e139:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e13e:	8b d8                	mov    ebx,eax
  55e140:	e8 6b 74 19 00       	call   0x6f55b0
  55e145:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e147:	bf 98 05 c1 00       	mov    edi,0xc10598
  55e14c:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e151:	e8 3a 76 19 00       	call   0x6f5790
  55e156:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e15b:	8b 30                	mov    esi,DWORD PTR [eax]
  55e15d:	6a 00                	push   0x0
  55e15f:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e164:	8b d8                	mov    ebx,eax
  55e166:	e8 45 74 19 00       	call   0x6f55b0
  55e16b:	83 c4 40             	add    esp,0x40
  55e16e:	bf b4 05 c1 00       	mov    edi,0xc105b4
  55e173:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e175:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e17a:	e8 11 76 19 00       	call   0x6f5790
  55e17f:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e184:	8b 30                	mov    esi,DWORD PTR [eax]
  55e186:	6a 00                	push   0x0
  55e188:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e18d:	8b d8                	mov    ebx,eax
  55e18f:	e8 1c 74 19 00       	call   0x6f55b0
  55e194:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e196:	bf bc 05 c1 00       	mov    edi,0xc105bc
  55e19b:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e1a0:	e8 eb 75 19 00       	call   0x6f5790
  55e1a5:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e1aa:	8b 30                	mov    esi,DWORD PTR [eax]
  55e1ac:	6a 00                	push   0x0
  55e1ae:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e1b3:	8b d8                	mov    ebx,eax
  55e1b5:	e8 f6 73 19 00       	call   0x6f55b0
  55e1ba:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e1bc:	bf c4 05 c1 00       	mov    edi,0xc105c4
  55e1c1:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e1c6:	e8 c5 75 19 00       	call   0x6f5790
  55e1cb:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e1d0:	8b 30                	mov    esi,DWORD PTR [eax]
  55e1d2:	6a 00                	push   0x0
  55e1d4:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e1d9:	8b d8                	mov    ebx,eax
  55e1db:	e8 d0 73 19 00       	call   0x6f55b0
  55e1e0:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e1e2:	bf cc 05 c1 00       	mov    edi,0xc105cc
  55e1e7:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e1ec:	e8 9f 75 19 00       	call   0x6f5790
  55e1f1:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e1f6:	8b 30                	mov    esi,DWORD PTR [eax]
  55e1f8:	6a 00                	push   0x0
  55e1fa:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e1ff:	8b d8                	mov    ebx,eax
  55e201:	e8 aa 73 19 00       	call   0x6f55b0
  55e206:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e208:	bf d4 05 c1 00       	mov    edi,0xc105d4
  55e20d:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e212:	e8 79 75 19 00       	call   0x6f5790
  55e217:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e21c:	8b 30                	mov    esi,DWORD PTR [eax]
  55e21e:	6a 00                	push   0x0
  55e220:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e225:	8b d8                	mov    ebx,eax
  55e227:	e8 84 73 19 00       	call   0x6f55b0
  55e22c:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e22e:	bf e0 05 c1 00       	mov    edi,0xc105e0
  55e233:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e238:	e8 53 75 19 00       	call   0x6f5790
  55e23d:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e242:	8b 30                	mov    esi,DWORD PTR [eax]
  55e244:	6a 00                	push   0x0
  55e246:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e24b:	8b d8                	mov    ebx,eax
  55e24d:	e8 5e 73 19 00       	call   0x6f55b0
  55e252:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e254:	bf ec 05 c1 00       	mov    edi,0xc105ec
  55e259:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e25e:	e8 2d 75 19 00       	call   0x6f5790
  55e263:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e268:	8b 30                	mov    esi,DWORD PTR [eax]
  55e26a:	6a 00                	push   0x0
  55e26c:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e271:	8b d8                	mov    ebx,eax
  55e273:	e8 38 73 19 00       	call   0x6f55b0
  55e278:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e27a:	bf f8 05 c1 00       	mov    edi,0xc105f8
  55e27f:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e284:	e8 07 75 19 00       	call   0x6f5790
  55e289:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e28e:	8b 30                	mov    esi,DWORD PTR [eax]
  55e290:	6a 00                	push   0x0
  55e292:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e297:	8b d8                	mov    ebx,eax
  55e299:	e8 12 73 19 00       	call   0x6f55b0
  55e29e:	83 c4 40             	add    esp,0x40
  55e2a1:	bf 64 02 c1 00       	mov    edi,0xc10264
  55e2a6:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e2a8:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e2ad:	e8 de 74 19 00       	call   0x6f5790
  55e2b2:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e2b7:	50                   	push   eax
  55e2b8:	8d 4d fc             	lea    ecx,[ebp-0x4]
  55e2bb:	51                   	push   ecx
  55e2bc:	e8 4f 01 00 00       	call   0x55e410
  55e2c1:	83 c4 08             	add    esp,0x8
  55e2c4:	50                   	push   eax
  55e2c5:	e8 26 02 00 00       	call   0x55e4f0
  55e2ca:	5f                   	pop    edi
  55e2cb:	5e                   	pop    esi
  55e2cc:	5b                   	pop    ebx
  55e2cd:	8b e5                	mov    esp,ebp
  55e2cf:	5d                   	pop    ebp
  55e2d0:	c3                   	ret

# prepass-q-table

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055e410 <.text+0x15d410>:
  55e410:	55                   	push   ebp
  55e411:	8b ec                	mov    ebp,esp
  55e413:	51                   	push   ecx
  55e414:	53                   	push   ebx
  55e415:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  55e418:	56                   	push   esi
  55e419:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e41b:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  55e41e:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  55e421:	57                   	push   edi
  55e422:	89 1d 20 1f fe 00    	mov    DWORD PTR ds:0xfe1f20,ebx
  55e428:	c7 05 24 1f fe 00 ec 	mov    DWORD PTR ds:0xfe1f24,0xfe1eec
  55e42f:	1e fe 00 
  55e432:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  55e435:	72 07                	jb     0x55e43e
  55e437:	8b c6                	mov    eax,esi
  55e439:	e8 62 cf 19 00       	call   0x6fb3a0
  55e43e:	8b 7e 08             	mov    edi,DWORD PTR [esi+0x8]
  55e441:	6a 00                	push   0x0
  55e443:	6a 00                	push   0x0
  55e445:	56                   	push   esi
  55e446:	e8 55 b5 19 00       	call   0x6f99a0
  55e44b:	89 07                	mov    DWORD PTR [edi],eax
  55e44d:	c7 47 08 05 00 00 00 	mov    DWORD PTR [edi+0x8],0x5
  55e454:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  55e458:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e45a:	83 c4 0c             	add    esp,0xc
  55e45d:	bf 04 06 c1 00       	mov    edi,0xc10604
  55e462:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e467:	e8 24 73 19 00       	call   0x6f5790
  55e46c:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e46e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e473:	e8 08 72 19 00       	call   0x6f5680
  55e478:	8b 03                	mov    eax,DWORD PTR [ebx]
  55e47a:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  55e47d:	83 e8 10             	sub    eax,0x10
  55e480:	bf f0 ff ff ff       	mov    edi,0xfffffff0
  55e485:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  55e48a:	74 06                	je     0x55e492
  55e48c:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  55e490:	74 17                	je     0x55e4a9
  55e492:	68 04 06 c1 00       	push   0xc10604
  55e497:	68 c4 26 c4 00       	push   0xc426c4
  55e49c:	e8 1c 4c 33 00       	call   0x8930bd
  55e4a1:	8b 03                	mov    eax,DWORD PTR [ebx]
  55e4a3:	83 c4 08             	add    esp,0x8
  55e4a6:	01 78 08             	add    DWORD PTR [eax+0x8],edi
  55e4a9:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e4ab:	68 24 62 c0 00       	push   0xc06224
  55e4b0:	e8 5b 70 19 00       	call   0x6f5510
  55e4b5:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e4b7:	83 c4 04             	add    esp,0x4
  55e4ba:	6a 00                	push   0x0
  55e4bc:	68 90 e5 55 00       	push   0x55e590
  55e4c1:	e8 ea 70 19 00       	call   0x6f55b0
  55e4c6:	8b 13                	mov    edx,DWORD PTR [ebx]
  55e4c8:	52                   	push   edx
  55e4c9:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  55e4ce:	e8 1d 73 19 00       	call   0x6f57f0
  55e4d3:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  55e4d5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  55e4d8:	83 c4 0c             	add    esp,0xc
  55e4db:	01 7b 08             	add    DWORD PTR [ebx+0x8],edi
  55e4de:	5f                   	pop    edi
  55e4df:	5e                   	pop    esi
  55e4e0:	c7 00 04 06 c1 00    	mov    DWORD PTR [eax],0xc10604
  55e4e6:	5b                   	pop    ebx
  55e4e7:	59                   	pop    ecx
  55e4e8:	5d                   	pop    ebp
  55e4e9:	c3                   	ret

# prepass-q-delete-binding

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055e4f0 <.text+0x15d4f0>:
  55e4f0:	55                   	push   ebp
  55e4f1:	8b ec                	mov    ebp,esp
  55e4f3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  55e4f6:	53                   	push   ebx
  55e4f7:	8b 1d 20 1f fe 00    	mov    ebx,DWORD PTR ds:0xfe1f20
  55e4fd:	56                   	push   esi
  55e4fe:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e500:	57                   	push   edi
  55e501:	8b 38                	mov    edi,DWORD PTR [eax]
  55e503:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e508:	c7 05 28 1f fe 00 10 	mov    DWORD PTR ds:0xfe1f28,0x5f5d10
  55e50f:	5d 5f 00 
  55e512:	e8 69 71 19 00       	call   0x6f5680
  55e517:	8b 03                	mov    eax,DWORD PTR [ebx]
  55e519:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  55e51c:	83 e8 10             	sub    eax,0x10
  55e51f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  55e524:	74 06                	je     0x55e52c
  55e526:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  55e52a:	74 14                	je     0x55e540
  55e52c:	57                   	push   edi
  55e52d:	68 c4 26 c4 00       	push   0xc426c4
  55e532:	e8 86 4b 33 00       	call   0x8930bd
  55e537:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  55e539:	83 c4 08             	add    esp,0x8
  55e53c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  55e540:	8b 3d 20 1f fe 00    	mov    edi,DWORD PTR ds:0xfe1f20
  55e546:	8b 37                	mov    esi,DWORD PTR [edi]
  55e548:	68 d0 a5 d6 00       	push   0xd6a5d0
  55e54d:	e8 be 6f 19 00       	call   0x6f5510
  55e552:	8b 37                	mov    esi,DWORD PTR [edi]
  55e554:	83 c4 04             	add    esp,0x4
  55e557:	6a 00                	push   0x0
  55e559:	68 20 e6 55 00       	push   0x55e620
  55e55e:	e8 4d 70 19 00       	call   0x6f55b0
  55e563:	8b 0f                	mov    ecx,DWORD PTR [edi]
  55e565:	51                   	push   ecx
  55e566:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  55e56b:	e8 80 72 19 00       	call   0x6f57f0
  55e570:	8b 15 20 1f fe 00    	mov    edx,DWORD PTR ds:0xfe1f20
  55e576:	8b 02                	mov    eax,DWORD PTR [edx]
  55e578:	83 c4 0c             	add    esp,0xc
  55e57b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  55e57f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  55e582:	5f                   	pop    edi
  55e583:	5e                   	pop    esi
  55e584:	5b                   	pop    ebx
  55e585:	5d                   	pop    ebp
  55e586:	c2 04 00             	ret    0x4

# prepass-q-delete-wrapper

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0055e620 <.text+0x15d620>:
  55e620:	55                   	push   ebp
  55e621:	8b ec                	mov    ebp,esp
  55e623:	6a ff                	push   0xffffffff
  55e625:	68 c8 83 93 00       	push   0x9383c8
  55e62a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  55e630:	50                   	push   eax
  55e631:	83 ec 0c             	sub    esp,0xc
  55e634:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  55e639:	33 c5                	xor    eax,ebp
  55e63b:	50                   	push   eax
  55e63c:	8d 45 f4             	lea    eax,[ebp-0xc]
  55e63f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  55e645:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  55e648:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  55e64b:	33 c0                	xor    eax,eax
  55e64d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  55e650:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  55e653:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  55e656:	8b 0d 24 1f fe 00    	mov    ecx,DWORD PTR ds:0xfe1f24
  55e65c:	ff 15 28 1f fe 00    	call   DWORD PTR ds:0xfe1f28
  55e662:	b8 01 00 00 00       	mov    eax,0x1
  55e667:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  55e66a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  55e671:	59                   	pop    ecx
  55e672:	8b e5                	mov    esp,ebp
  55e674:	5d                   	pop    ebp
  55e675:	c3                   	ret

# prepass-empty-callback

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008dc2f0 <.text+0x4db2f0>:
  8dc2f0:	33 c0                	xor    eax,eax
  8dc2f2:	c3                   	ret

# prepass-delete-empty-target

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005f5d10 <.text+0x1f4d10>:
  5f5d10:	c3                   	ret

# scene-update-coroutine-pump

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561520 <.text+0x160520>:
  561520:	55                   	push   ebp
  561521:	8b ec                	mov    ebp,esp
  561523:	83 e4 f8             	and    esp,0xfffffff8
  561526:	6a ff                	push   0xffffffff
  561528:	68 7c ac 93 00       	push   0x93ac7c
  56152d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561533:	50                   	push   eax
  561534:	51                   	push   ecx
  561535:	56                   	push   esi
  561536:	57                   	push   edi
  561537:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56153c:	33 c4                	xor    eax,esp
  56153e:	50                   	push   eax
  56153f:	8d 44 24 10          	lea    eax,[esp+0x10]
  561543:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  561549:	8b f9                	mov    edi,ecx
  56154b:	f6 05 40 27 fe 00 01 	test   BYTE PTR ds:0xfe2740,0x1
  561552:	75 29                	jne    0x56157d
  561554:	83 0d 40 27 fe 00 01 	or     DWORD PTR ds:0xfe2740,0x1
  56155b:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  561562:	00 
  561563:	e8 18 d1 ff ff       	call   0x55e680
  561568:	68 a0 f2 bc 00       	push   0xbcf2a0
  56156d:	e8 a8 0d 33 00       	call   0x89231a
  561572:	83 c4 04             	add    esp,0x4
  561575:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  56157c:	ff 
  56157d:	be 44 27 fe 00       	mov    esi,0xfe2744
  561582:	e8 09 d2 ff ff       	call   0x55e790
  561587:	83 7f 28 00          	cmp    DWORD PTR [edi+0x28],0x0
  56158b:	74 53                	je     0x5615e0
  56158d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  561594:	be 01 00 00 00       	mov    esi,0x1
  561599:	75 24                	jne    0x5615bf
  56159b:	09 35 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,esi
  5615a1:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  5615a5:	e8 e6 d6 f7 ff       	call   0x4dec90
  5615aa:	68 30 ce bc 00       	push   0xbcce30
  5615af:	e8 66 0d 33 00       	call   0x89231a
  5615b4:	83 c4 04             	add    esp,0x4
  5615b7:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  5615be:	ff 
  5615bf:	a1 a4 a7 fb 00       	mov    eax,ds:0xfba7a4
  5615c4:	89 70 58             	mov    DWORD PTR [eax+0x58],esi
  5615c7:	83 7f 2c 00          	cmp    DWORD PTR [edi+0x2c],0x0
  5615cb:	75 13                	jne    0x5615e0
  5615cd:	8b 07                	mov    eax,DWORD PTR [edi]
  5615cf:	6a 00                	push   0x0
  5615d1:	6a 00                	push   0x0
  5615d3:	68 a0 06 c1 00       	push   0xc106a0
  5615d8:	e8 f3 37 19 00       	call   0x6f4dd0
  5615dd:	83 c4 0c             	add    esp,0xc
  5615e0:	8b 7f 1c             	mov    edi,DWORD PTR [edi+0x1c]
  5615e3:	8b 37                	mov    esi,DWORD PTR [edi]
  5615e5:	3b f7                	cmp    esi,edi
  5615e7:	74 55                	je     0x56163e
  5615e9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5615f0:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  5615f3:	8b 11                	mov    edx,DWORD PTR [ecx]
  5615f5:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  5615f8:	ff d0                	call   eax
  5615fa:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  5615fe:	75 3a                	jne    0x56163a
  561600:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  561603:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  561607:	75 16                	jne    0x56161f
  561609:	8b f0                	mov    esi,eax
  56160b:	8b 06                	mov    eax,DWORD PTR [esi]
  56160d:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  561611:	75 27                	jne    0x56163a
  561613:	8b f0                	mov    esi,eax
  561615:	8b 06                	mov    eax,DWORD PTR [esi]
  561617:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  56161b:	74 f6                	je     0x561613
  56161d:	eb 1b                	jmp    0x56163a
  56161f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  561622:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  561626:	75 10                	jne    0x561638
  561628:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  56162b:	75 0b                	jne    0x561638
  56162d:	8b f0                	mov    esi,eax
  56162f:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  561632:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  561636:	74 f0                	je     0x561628
  561638:	8b f0                	mov    esi,eax
  56163a:	3b f7                	cmp    esi,edi
  56163c:	75 b2                	jne    0x5615f0
  56163e:	f6 05 dc 36 fe 00 01 	test   BYTE PTR ds:0xfe36dc,0x1
  561645:	75 13                	jne    0x56165a
  561647:	83 0d dc 36 fe 00 01 	or     DWORD PTR ds:0xfe36dc,0x1
  56164e:	33 c0                	xor    eax,eax
  561650:	a3 d4 36 fe 00       	mov    ds:0xfe36d4,eax
  561655:	a3 d8 36 fe 00       	mov    ds:0xfe36d8,eax
  56165a:	68 d4 36 fe 00       	push   0xfe36d4
  56165f:	e8 2c ea ff ff       	call   0x560090
  561664:	33 c0                	xor    eax,eax
  561666:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  56166a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561671:	59                   	pop    ecx
  561672:	5f                   	pop    edi
  561673:	5e                   	pop    esi
  561674:	8b e5                	mov    esp,ebp
  561676:	5d                   	pop    ebp
  561677:	c3                   	ret

# named-protected-call

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4dd0 <.text+0x2f3dd0>:
  6f4dd0:	55                   	push   ebp
  6f4dd1:	8b ec                	mov    ebp,esp
  6f4dd3:	83 e4 f8             	and    esp,0xfffffff8
  6f4dd6:	83 ec 14             	sub    esp,0x14
  6f4dd9:	53                   	push   ebx
  6f4dda:	56                   	push   esi
  6f4ddb:	57                   	push   edi
  6f4ddc:	8b f8                	mov    edi,eax
  6f4dde:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4de0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4de3:	8d 5e 48             	lea    ebx,[esi+0x48]
  6f4de6:	8d 48 01             	lea    ecx,[eax+0x1]
  6f4de9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  6f4df0:	8a 10                	mov    dl,BYTE PTR [eax]
  6f4df2:	40                   	inc    eax
  6f4df3:	84 d2                	test   dl,dl
  6f4df5:	75 f9                	jne    0x6f4df0
  6f4df7:	2b c1                	sub    eax,ecx
  6f4df9:	50                   	push   eax
  6f4dfa:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4dfd:	50                   	push   eax
  6f4dfe:	56                   	push   esi
  6f4dff:	e8 6c 9e 00 00       	call   0x6fec70
  6f4e04:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6f4e07:	83 c4 0c             	add    esp,0xc
  6f4e0a:	51                   	push   ecx
  6f4e0b:	8d 54 24 14          	lea    edx,[esp+0x14]
  6f4e0f:	52                   	push   edx
  6f4e10:	53                   	push   ebx
  6f4e11:	56                   	push   esi
  6f4e12:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  6f4e16:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  6f4e1d:	00 
  6f4e1e:	e8 2d 6a 00 00       	call   0x6fb850
  6f4e23:	bb 10 00 00 00       	mov    ebx,0x10
  6f4e28:	01 5e 08             	add    DWORD PTR [esi+0x8],ebx
  6f4e2b:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4e2d:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  6f4e30:	2b c3                	sub    eax,ebx
  6f4e32:	83 c4 10             	add    esp,0x10
  6f4e35:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  6f4e3a:	0f 84 b5 00 00 00    	je     0x6f4ef5
  6f4e40:	83 78 08 06          	cmp    DWORD PTR [eax+0x8],0x6
  6f4e44:	0f 85 ab 00 00 00    	jne    0x6f4ef5
  6f4e4a:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  6f4e4d:	8d 45 14             	lea    eax,[ebp+0x14]
  6f4e50:	50                   	push   eax
  6f4e51:	57                   	push   edi
  6f4e52:	e8 79 fe ff ff       	call   0x6f4cd0
  6f4e57:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4e59:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  6f4e5c:	8d 48 01             	lea    ecx,[eax+0x1]
  6f4e5f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4e62:	c1 e1 04             	shl    ecx,0x4
  6f4e65:	2b c1                	sub    eax,ecx
  6f4e67:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4e6b:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4e6e:	8d 54 24 10          	lea    edx,[esp+0x10]
  6f4e72:	50                   	push   eax
  6f4e73:	52                   	push   edx
  6f4e74:	68 50 5a 6f 00       	push   0x6f5a50
  6f4e79:	33 d2                	xor    edx,edx
  6f4e7b:	8b c6                	mov    eax,esi
  6f4e7d:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  6f4e81:	e8 ea 98 00 00       	call   0x6fe770
  6f4e86:	83 c4 0c             	add    esp,0xc
  6f4e89:	83 fb ff             	cmp    ebx,0xffffffff
  6f4e8c:	75 0e                	jne    0x6f4e9c
  6f4e8e:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4e91:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  6f4e94:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4e97:	72 03                	jb     0x6f4e9c
  6f4e99:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6f4e9c:	85 c0                	test   eax,eax
  6f4e9e:	0f 84 87 00 00 00    	je     0x6f4f2b
  6f4ea4:	8b 3f                	mov    edi,DWORD PTR [edi]
  6f4ea6:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f4ea9:	83 ee 10             	sub    esi,0x10
  6f4eac:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  6f4eb0:	74 25                	je     0x6f4ed7
  6f4eb2:	e8 19 67 00 00       	call   0x6fb5d0
  6f4eb7:	85 c0                	test   eax,eax
  6f4eb9:	75 04                	jne    0x6f4ebf
  6f4ebb:	33 f6                	xor    esi,esi
  6f4ebd:	eb 1d                	jmp    0x6f4edc
  6f4ebf:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  6f4ec2:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  6f4ec5:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  6f4ec8:	72 07                	jb     0x6f4ed1
  6f4eca:	8b c7                	mov    eax,edi
  6f4ecc:	e8 cf 64 00 00       	call   0x6fb3a0
  6f4ed1:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f4ed4:	83 ee 10             	sub    esi,0x10
  6f4ed7:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4ed9:	83 c6 10             	add    esi,0x10
  6f4edc:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  6f4edf:	56                   	push   esi
  6f4ee0:	52                   	push   edx
  6f4ee1:	68 78 26 c4 00       	push   0xc42678
  6f4ee6:	e8 d2 e1 19 00       	call   0x8930bd
  6f4eeb:	83 c4 0c             	add    esp,0xc
  6f4eee:	5f                   	pop    edi
  6f4eef:	5e                   	pop    esi
  6f4ef0:	5b                   	pop    ebx
  6f4ef1:	8b e5                	mov    esp,ebp
  6f4ef3:	5d                   	pop    ebp
  6f4ef4:	c3                   	ret
  6f4ef5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4ef8:	50                   	push   eax
  6f4ef9:	68 10 26 c4 00       	push   0xc42610
  6f4efe:	e8 ba e1 19 00       	call   0x8930bd
  6f4f03:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4f05:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  6f4f08:	83 c4 08             	add    esp,0x8
  6f4f0b:	3b 48 0c             	cmp    ecx,DWORD PTR [eax+0xc]
  6f4f0e:	73 15                	jae    0x6f4f25
  6f4f10:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  6f4f13:	c7 42 08 00 00 00 00 	mov    DWORD PTR [edx+0x8],0x0
  6f4f1a:	01 58 08             	add    DWORD PTR [eax+0x8],ebx
  6f4f1d:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  6f4f20:	3b 48 0c             	cmp    ecx,DWORD PTR [eax+0xc]
  6f4f23:	72 eb                	jb     0x6f4f10
  6f4f25:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  6f4f28:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  6f4f2b:	5f                   	pop    edi
  6f4f2c:	5e                   	pop    esi
  6f4f2d:	5b                   	pop    ebx
  6f4f2e:	8b e5                	mov    esp,ebp
  6f4f30:	5d                   	pop    ebp
  6f4f31:	c3                   	ret

# scene-prepass-result-consumption

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561ae8 <.text+0x160ae8>:
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

# scene-second-load-global-wrapper

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561c67 <.text+0x160c67>:
  561c67:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  561c6b:	bf 10 00 00 00       	mov    edi,0x10
  561c70:	39 7c 24 34          	cmp    DWORD PTR [esp+0x34],edi
  561c74:	73 04                	jae    0x561c7a
  561c76:	8d 44 24 20          	lea    eax,[esp+0x20]
  561c7a:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  561c7c:	50                   	push   eax
  561c7d:	e8 ce 2d 19 00       	call   0x6f4a50
  561c82:	33 db                	xor    ebx,ebx
