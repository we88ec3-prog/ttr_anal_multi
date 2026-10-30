# T01 R2 Batch4 原始 BIN 指令視窗

對 `/mnt/data/Tartaros.bin` 的靜態唯讀 GNU objdump 輸出。每段均有 VA、原始 bytes；`.text raw=VA−0x400C00`。**不同 section 不套用此偏移**。


## 完整 rooted erase CFG — 0x7B6890 .. 0x7B6AEE

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007b6890 <.text+0x3b5890>:
  7b6890:	55                   	push   ebp
  7b6891:	8b ec                	mov    ebp,esp
  7b6893:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b6896:	83 ec 08             	sub    esp,0x8
  7b6899:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b689d:	74 0a                	je     0x7b68a9
  7b689f:	68 28 d2 be 00       	push   0xbed228
  7b68a4:	e8 d4 72 0c 00       	call   0x87db7d
  7b68a9:	53                   	push   ebx
  7b68aa:	56                   	push   esi
  7b68ab:	8b d8                	mov    ebx,eax
  7b68ad:	57                   	push   edi
  7b68ae:	8d 45 10             	lea    eax,[ebp+0x10]
  7b68b1:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7b68b4:	e8 e7 7d ce ff       	call   0x49e6a0
  7b68b9:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b68bb:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b68bf:	74 05                	je     0x7b68c6
  7b68c1:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7b68c4:	eb 17                	jmp    0x7b68dd
  7b68c6:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  7b68c9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b68cd:	74 04                	je     0x7b68d3
  7b68cf:	8b f9                	mov    edi,ecx
  7b68d1:	eb 0a                	jmp    0x7b68dd
  7b68d3:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b68d6:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  7b68d9:	3b c3                	cmp    eax,ebx
  7b68db:	75 7c                	jne    0x7b6959
  7b68dd:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b68e1:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  7b68e4:	75 03                	jne    0x7b68e9
  7b68e6:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  7b68e9:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b68ec:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b68ef:	39 58 04             	cmp    DWORD PTR [eax+0x4],ebx
  7b68f2:	75 05                	jne    0x7b68f9
  7b68f4:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  7b68f7:	eb 0b                	jmp    0x7b6904
  7b68f9:	39 1e                	cmp    DWORD PTR [esi],ebx
  7b68fb:	75 04                	jne    0x7b6901
  7b68fd:	89 3e                	mov    DWORD PTR [esi],edi
  7b68ff:	eb 03                	jmp    0x7b6904
  7b6901:	89 7e 08             	mov    DWORD PTR [esi+0x8],edi
  7b6904:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b6907:	39 18                	cmp    DWORD PTR [eax],ebx
  7b6909:	75 24                	jne    0x7b692f
  7b690b:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b690f:	74 04                	je     0x7b6915
  7b6911:	8b ce                	mov    ecx,esi
  7b6913:	eb 15                	jmp    0x7b692a
  7b6915:	8b 07                	mov    eax,DWORD PTR [edi]
  7b6917:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b691b:	8b cf                	mov    ecx,edi
  7b691d:	75 0b                	jne    0x7b692a
  7b691f:	90                   	nop
  7b6920:	8b c8                	mov    ecx,eax
  7b6922:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6924:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b6928:	74 f6                	je     0x7b6920
  7b692a:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b692d:	89 08                	mov    DWORD PTR [eax],ecx
  7b692f:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b6932:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  7b6935:	39 59 08             	cmp    DWORD PTR [ecx+0x8],ebx
  7b6938:	75 7c                	jne    0x7b69b6
  7b693a:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b693e:	74 07                	je     0x7b6947
  7b6940:	8b c6                	mov    eax,esi
  7b6942:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6945:	eb 6f                	jmp    0x7b69b6
  7b6947:	8b c7                	mov    eax,edi
  7b6949:	e8 32 d2 06 00       	call   0x823b80
  7b694e:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  7b6951:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6954:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6957:	eb 5d                	jmp    0x7b69b6
  7b6959:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b695c:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b695e:	89 08                	mov    DWORD PTR [eax],ecx
  7b6960:	3b 43 08             	cmp    eax,DWORD PTR [ebx+0x8]
  7b6963:	75 04                	jne    0x7b6969
  7b6965:	8b f0                	mov    esi,eax
  7b6967:	eb 1a                	jmp    0x7b6983
  7b6969:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b696d:	8b 70 04             	mov    esi,DWORD PTR [eax+0x4]
  7b6970:	75 03                	jne    0x7b6975
  7b6972:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  7b6975:	89 3e                	mov    DWORD PTR [esi],edi
  7b6977:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  7b697a:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  7b697d:	8b 53 08             	mov    edx,DWORD PTR [ebx+0x8]
  7b6980:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  7b6983:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6986:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  7b6989:	39 59 04             	cmp    DWORD PTR [ecx+0x4],ebx
  7b698c:	75 05                	jne    0x7b6993
  7b698e:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b6991:	eb 0e                	jmp    0x7b69a1
  7b6993:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  7b6996:	39 19                	cmp    DWORD PTR [ecx],ebx
  7b6998:	75 04                	jne    0x7b699e
  7b699a:	89 01                	mov    DWORD PTR [ecx],eax
  7b699c:	eb 03                	jmp    0x7b69a1
  7b699e:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b69a1:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  7b69a4:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  7b69a7:	8a 53 14             	mov    dl,BYTE PTR [ebx+0x14]
  7b69aa:	8a 48 14             	mov    cl,BYTE PTR [eax+0x14]
  7b69ad:	88 50 14             	mov    BYTE PTR [eax+0x14],dl
  7b69b0:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b69b3:	88 4b 14             	mov    BYTE PTR [ebx+0x14],cl
  7b69b6:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  7b69b9:	b3 01                	mov    bl,0x1
  7b69bb:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b69be:	0f 85 ff 00 00 00    	jne    0x7b6ac3
  7b69c4:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b69c7:	3b 79 04             	cmp    edi,DWORD PTR [ecx+0x4]
  7b69ca:	0f 84 f0 00 00 00    	je     0x7b6ac0
  7b69d0:	38 5f 14             	cmp    BYTE PTR [edi+0x14],bl
  7b69d3:	0f 85 e7 00 00 00    	jne    0x7b6ac0
  7b69d9:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b69db:	3b f9                	cmp    edi,ecx
  7b69dd:	75 69                	jne    0x7b6a48
  7b69df:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b69e2:	80 79 14 00          	cmp    BYTE PTR [ecx+0x14],0x0
  7b69e6:	75 15                	jne    0x7b69fd
  7b69e8:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b69eb:	52                   	push   edx
  7b69ec:	8b ce                	mov    ecx,esi
  7b69ee:	c6 46 14 00          	mov    BYTE PTR [esi+0x14],0x0
  7b69f2:	e8 69 d5 fa ff       	call   0x763f60
  7b69f7:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b69fa:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b69fd:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b6a01:	75 78                	jne    0x7b6a7b
  7b6a03:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a05:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a08:	75 08                	jne    0x7b6a12
  7b6a0a:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a0d:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a10:	74 65                	je     0x7b6a77
  7b6a12:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a15:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a18:	75 15                	jne    0x7b6a2f
  7b6a1a:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a1c:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  7b6a1f:	52                   	push   edx
  7b6a20:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6a24:	e8 47 7c c8 ff       	call   0x43e670
  7b6a29:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b6a2c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6a2f:	8a 46 14             	mov    al,BYTE PTR [esi+0x14]
  7b6a32:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  7b6a35:	88 5e 14             	mov    BYTE PTR [esi+0x14],bl
  7b6a38:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  7b6a3b:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6a3e:	52                   	push   edx
  7b6a3f:	8b ce                	mov    ecx,esi
  7b6a41:	e8 1a d5 fa ff       	call   0x763f60
  7b6a46:	eb 78                	jmp    0x7b6ac0
  7b6a48:	80 79 14 00          	cmp    BYTE PTR [ecx+0x14],0x0
  7b6a4c:	75 14                	jne    0x7b6a62
  7b6a4e:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6a51:	52                   	push   edx
  7b6a52:	8b ce                	mov    ecx,esi
  7b6a54:	c6 46 14 00          	mov    BYTE PTR [esi+0x14],0x0
  7b6a58:	e8 13 7c c8 ff       	call   0x43e670
  7b6a5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b6a5f:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6a62:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b6a66:	75 13                	jne    0x7b6a7b
  7b6a68:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a6b:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a6e:	75 1e                	jne    0x7b6a8e
  7b6a70:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a72:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a75:	75 17                	jne    0x7b6a8e
  7b6a77:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6a7b:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b6a7e:	8b fe                	mov    edi,esi
  7b6a80:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  7b6a83:	3b 79 04             	cmp    edi,DWORD PTR [ecx+0x4]
  7b6a86:	0f 85 44 ff ff ff    	jne    0x7b69d0
  7b6a8c:	eb 32                	jmp    0x7b6ac0
  7b6a8e:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a90:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a93:	75 15                	jne    0x7b6aaa
  7b6a95:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a98:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  7b6a9b:	52                   	push   edx
  7b6a9c:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6aa0:	e8 bb d4 fa ff       	call   0x763f60
  7b6aa5:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b6aa7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6aaa:	8a 46 14             	mov    al,BYTE PTR [esi+0x14]
  7b6aad:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  7b6ab0:	88 5e 14             	mov    BYTE PTR [esi+0x14],bl
  7b6ab3:	8b 09                	mov    ecx,DWORD PTR [ecx]
  7b6ab5:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6ab8:	52                   	push   edx
  7b6ab9:	8b ce                	mov    ecx,esi
  7b6abb:	e8 b0 7b c8 ff       	call   0x43e670
  7b6ac0:	88 5f 14             	mov    BYTE PTR [edi+0x14],bl
  7b6ac3:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  7b6ac6:	52                   	push   edx
  7b6ac7:	e8 40 a7 0d 00       	call   0x89120c
  7b6acc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6acf:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6ad2:	83 c4 04             	add    esp,0x4
  7b6ad5:	5f                   	pop    edi
  7b6ad6:	5e                   	pop    esi
  7b6ad7:	5b                   	pop    ebx
  7b6ad8:	85 c0                	test   eax,eax
  7b6ada:	74 04                	je     0x7b6ae0
  7b6adc:	48                   	dec    eax
  7b6add:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6ae0:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  7b6ae3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b6ae6:	89 08                	mov    DWORD PTR [eax],ecx
  7b6ae8:	8b e5                	mov    esp,ebp
  7b6aea:	5d                   	pop    ebp
  7b6aeb:	c2 0c 00             	ret    0xc

```


## 右旋 — 0x763F60 .. 0x763FB1

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00763f60 <.text+0x362f60>:
  763f60:	55                   	push   ebp
  763f61:	8b ec                	mov    ebp,esp
  763f63:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  763f66:	8b 10                	mov    edx,DWORD PTR [eax]
  763f68:	89 51 08             	mov    DWORD PTR [ecx+0x8],edx
  763f6b:	8b 10                	mov    edx,DWORD PTR [eax]
  763f6d:	80 7a 15 00          	cmp    BYTE PTR [edx+0x15],0x0
  763f71:	75 03                	jne    0x763f76
  763f73:	89 4a 04             	mov    DWORD PTR [edx+0x4],ecx
  763f76:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  763f79:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  763f7c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  763f7f:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  763f82:	3b 4a 04             	cmp    ecx,DWORD PTR [edx+0x4]
  763f85:	75 0c                	jne    0x763f93
  763f87:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  763f8a:	89 08                	mov    DWORD PTR [eax],ecx
  763f8c:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  763f8f:	5d                   	pop    ebp
  763f90:	c2 04 00             	ret    0x4
  763f93:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  763f96:	3b 0a                	cmp    ecx,DWORD PTR [edx]
  763f98:	75 0b                	jne    0x763fa5
  763f9a:	89 02                	mov    DWORD PTR [edx],eax
  763f9c:	89 08                	mov    DWORD PTR [eax],ecx
  763f9e:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  763fa1:	5d                   	pop    ebp
  763fa2:	c2 04 00             	ret    0x4
  763fa5:	89 42 08             	mov    DWORD PTR [edx+0x8],eax
  763fa8:	89 08                	mov    DWORD PTR [eax],ecx
  763faa:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  763fad:	5d                   	pop    ebp
  763fae:	c2 04 00             	ret    0x4

```


## 左旋 — 0x43E670 .. 0x43E6C5

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0043e670 <.text+0x3d670>:
  43e670:	55                   	push   ebp
  43e671:	8b ec                	mov    ebp,esp
  43e673:	8b 01                	mov    eax,DWORD PTR [ecx]
  43e675:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  43e678:	89 11                	mov    DWORD PTR [ecx],edx
  43e67a:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  43e67d:	80 7a 15 00          	cmp    BYTE PTR [edx+0x15],0x0
  43e681:	75 03                	jne    0x43e686
  43e683:	89 4a 04             	mov    DWORD PTR [edx+0x4],ecx
  43e686:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  43e689:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  43e68c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  43e68f:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  43e692:	3b 4a 04             	cmp    ecx,DWORD PTR [edx+0x4]
  43e695:	75 0d                	jne    0x43e6a4
  43e697:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  43e69a:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  43e69d:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  43e6a0:	5d                   	pop    ebp
  43e6a1:	c2 04 00             	ret    0x4
  43e6a4:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  43e6a7:	3b 4a 08             	cmp    ecx,DWORD PTR [edx+0x8]
  43e6aa:	75 0d                	jne    0x43e6b9
  43e6ac:	89 42 08             	mov    DWORD PTR [edx+0x8],eax
  43e6af:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  43e6b2:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  43e6b5:	5d                   	pop    ebp
  43e6b6:	c2 04 00             	ret    0x4
  43e6b9:	89 02                	mov    DWORD PTR [edx],eax
  43e6bb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  43e6be:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  43e6c1:	5d                   	pop    ebp
  43e6c2:	c2 04 00             	ret    0x4

```


## successor — 0x49E6A0 .. 0x49E6EB

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049e6a0 <.text+0x9d6a0>:
  49e6a0:	8b 08                	mov    ecx,DWORD PTR [eax]
  49e6a2:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  49e6a6:	75 42                	jne    0x49e6ea
  49e6a8:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  49e6ab:	80 7a 15 00          	cmp    BYTE PTR [edx+0x15],0x0
  49e6af:	75 1c                	jne    0x49e6cd
  49e6b1:	8b 0a                	mov    ecx,DWORD PTR [edx]
  49e6b3:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  49e6b7:	75 11                	jne    0x49e6ca
  49e6b9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  49e6c0:	8b d1                	mov    edx,ecx
  49e6c2:	8b 0a                	mov    ecx,DWORD PTR [edx]
  49e6c4:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  49e6c8:	74 f6                	je     0x49e6c0
  49e6ca:	89 10                	mov    DWORD PTR [eax],edx
  49e6cc:	c3                   	ret
  49e6cd:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  49e6d0:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  49e6d4:	75 12                	jne    0x49e6e8
  49e6d6:	8b 10                	mov    edx,DWORD PTR [eax]
  49e6d8:	3b 51 08             	cmp    edx,DWORD PTR [ecx+0x8]
  49e6db:	75 0b                	jne    0x49e6e8
  49e6dd:	89 08                	mov    DWORD PTR [eax],ecx
  49e6df:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  49e6e2:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  49e6e6:	74 ee                	je     0x49e6d6
  49e6e8:	89 08                	mov    DWORD PTR [eax],ecx
  49e6ea:	c3                   	ret

```


## extremum — 0x823B80 .. 0x823B9C

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00823b80 <.text+0x422b80>:
  823b80:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  823b83:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  823b87:	75 12                	jne    0x823b9b
  823b89:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  823b90:	8b c1                	mov    eax,ecx
  823b92:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  823b95:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  823b99:	74 f5                	je     0x823b90
  823b9b:	c3                   	ret

```


## delete thunk — 0x89120C .. 0x891217

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0089120c <.text+0x49020c>:
  89120c:	8b ff                	mov    edi,edi
  89120e:	55                   	push   ebp
  89120f:	8b ec                	mov    ebp,esp
  891211:	5d                   	pop    ebp
  891212:	e9 e5 0e 00 00       	jmp    0x8920fc

```


## HeapFree 路徑 — 0x8920FC .. 0x892136

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008920fc <.text+0x4910fc>:
  8920fc:	8b ff                	mov    edi,edi
  8920fe:	55                   	push   ebp
  8920ff:	8b ec                	mov    ebp,esp
  892101:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  892105:	74 2d                	je     0x892134
  892107:	ff 75 08             	push   DWORD PTR [ebp+0x8]
  89210a:	6a 00                	push   0x0
  89210c:	ff 35 dc d4 f8 00    	push   DWORD PTR ds:0xf8d4dc
  892112:	ff 15 10 22 bd 00    	call   DWORD PTR ds:0xbd2210
  892118:	85 c0                	test   eax,eax
  89211a:	75 18                	jne    0x892134
  89211c:	56                   	push   esi
  89211d:	e8 c6 65 00 00       	call   0x8986e8
  892122:	8b f0                	mov    esi,eax
  892124:	ff 15 00 23 bd 00    	call   DWORD PTR ds:0xbd2300
  89212a:	50                   	push   eax
  89212b:	e8 76 65 00 00       	call   0x8986a6
  892130:	59                   	pop    ecx
  892131:	89 06                	mov    DWORD PTR [esi],eax
  892133:	5e                   	pop    esi
  892134:	5d                   	pop    ebp
  892135:	c3                   	ret

```


## Conn bind/duplicate key erase — 0x806C7B .. 0x806CEA

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00806c7b <.text+0x405c7b>:
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
  806c87:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806c8d:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
  806cd7:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  806cdb:	5f                   	pop    edi
  806cdc:	5e                   	pop    esi
  806cdd:	8b c3                	mov    eax,ebx
  806cdf:	5b                   	pop    ebx
  806ce0:	33 cc                	xor    ecx,esp
  806ce2:	e8 1a a3 08 00       	call   0x891001
  806ce7:	8b e5                	mov    esp,ebp
  806ce9:	5d                   	pop    ebp

```


## Quest type1 — 0x500950 .. 0x5009FD

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00500950 <.text+0xff950>:
  500950:	55                   	push   ebp
  500951:	8b ec                	mov    ebp,esp
  500953:	83 ec 0c             	sub    esp,0xc
  500956:	53                   	push   ebx
  500957:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  50095a:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  50095d:	56                   	push   esi
  50095e:	8b 33                	mov    esi,DWORD PTR [ebx]
  500960:	57                   	push   edi
  500961:	3b f1                	cmp    esi,ecx
  500963:	74 1e                	je     0x500983
  500965:	8b c1                	mov    eax,ecx
  500967:	2b c1                	sub    eax,ecx
  500969:	c1 f8 02             	sar    eax,0x2
  50096c:	8d 3c 85 00 00 00 00 	lea    edi,[eax*4+0x0]
  500973:	57                   	push   edi
  500974:	51                   	push   ecx
  500975:	56                   	push   esi
  500976:	e8 75 09 39 00       	call   0x8912f0
  50097b:	83 c4 0c             	add    esp,0xc
  50097e:	03 fe                	add    edi,esi
  500980:	89 7b 04             	mov    DWORD PTR [ebx+0x4],edi
  500983:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500986:	8b 87 c4 5e 00 00    	mov    eax,DWORD PTR [edi+0x5ec4]
  50098c:	8b 9f c0 5e 00 00    	mov    ebx,DWORD PTR [edi+0x5ec0]
  500992:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  500995:	3b d8                	cmp    ebx,eax
  500997:	74 5b                	je     0x5009f4
  500999:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5009a0:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  5009a3:	8b b7 ac 5e 00 00    	mov    esi,DWORD PTR [edi+0x5eac]
  5009a9:	8d 4d fc             	lea    ecx,[ebp-0x4]
  5009ac:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5009af:	51                   	push   ecx
  5009b0:	8d 45 f8             	lea    eax,[ebp-0x8]
  5009b3:	8b ce                	mov    ecx,esi
  5009b5:	e8 66 33 00 00       	call   0x503d20
  5009ba:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  5009bd:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  5009c0:	74 05                	je     0x5009c7
  5009c2:	83 c0 10             	add    eax,0x10
  5009c5:	eb 02                	jmp    0x5009c9
  5009c7:	33 c0                	xor    eax,eax
  5009c9:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5009cc:	85 c0                	test   eax,eax
  5009ce:	74 1c                	je     0x5009ec
  5009d0:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5009d3:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  5009d6:	75 14                	jne    0x5009ec
  5009d8:	83 78 04 01          	cmp    DWORD PTR [eax+0x4],0x1
  5009dc:	75 0e                	jne    0x5009ec
  5009de:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  5009e1:	8d 45 fc             	lea    eax,[ebp-0x4]
  5009e4:	e8 27 33 f4 ff       	call   0x443d10
  5009e9:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5009ec:	83 c3 02             	add    ebx,0x2
  5009ef:	3b 5d f4             	cmp    ebx,DWORD PTR [ebp-0xc]
  5009f2:	75 ac                	jne    0x5009a0
  5009f4:	5f                   	pop    edi
  5009f5:	5e                   	pop    esi
  5009f6:	5b                   	pop    ebx
  5009f7:	8b e5                	mov    esp,ebp
  5009f9:	5d                   	pop    ebp
  5009fa:	c2 0c 00             	ret    0xc

```


## Quest type2 — 0x500A00 .. 0x500A7D

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00500a00 <.text+0xffa00>:
  500a00:	55                   	push   ebp
  500a01:	8b ec                	mov    ebp,esp
  500a03:	83 ec 0c             	sub    esp,0xc
  500a06:	53                   	push   ebx
  500a07:	57                   	push   edi
  500a08:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a0b:	8b 87 c4 5e 00 00    	mov    eax,DWORD PTR [edi+0x5ec4]
  500a11:	8b 9f c0 5e 00 00    	mov    ebx,DWORD PTR [edi+0x5ec0]
  500a17:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  500a1a:	3b d8                	cmp    ebx,eax
  500a1c:	74 57                	je     0x500a75
  500a1e:	56                   	push   esi
  500a1f:	90                   	nop
  500a20:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  500a23:	8b b7 ac 5e 00 00    	mov    esi,DWORD PTR [edi+0x5eac]
  500a29:	8d 4d fc             	lea    ecx,[ebp-0x4]
  500a2c:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a2f:	51                   	push   ecx
  500a30:	8d 45 f8             	lea    eax,[ebp-0x8]
  500a33:	8b ce                	mov    ecx,esi
  500a35:	e8 e6 32 00 00       	call   0x503d20
  500a3a:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500a3d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500a40:	74 05                	je     0x500a47
  500a42:	83 c0 10             	add    eax,0x10
  500a45:	eb 02                	jmp    0x500a49
  500a47:	33 c0                	xor    eax,eax
  500a49:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a4c:	85 c0                	test   eax,eax
  500a4e:	74 1c                	je     0x500a6c
  500a50:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  500a53:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  500a56:	75 14                	jne    0x500a6c
  500a58:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500a5c:	75 0e                	jne    0x500a6c
  500a5e:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500a61:	8d 45 fc             	lea    eax,[ebp-0x4]
  500a64:	e8 a7 32 f4 ff       	call   0x443d10
  500a69:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a6c:	83 c3 02             	add    ebx,0x2
  500a6f:	3b 5d f4             	cmp    ebx,DWORD PTR [ebp-0xc]
  500a72:	75 ac                	jne    0x500a20
  500a74:	5e                   	pop    esi
  500a75:	5f                   	pop    edi
  500a76:	5b                   	pop    ebx
  500a77:	8b e5                	mov    esp,ebp
  500a79:	5d                   	pop    ebp
  500a7a:	c2 0c 00             	ret    0xc

```


## type2 first — 0x5008B0 .. 0x500944

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005008b0 <.text+0xff8b0>:
  5008b0:	55                   	push   ebp
  5008b1:	8b ec                	mov    ebp,esp
  5008b3:	83 e4 f8             	and    esp,0xfffffff8
  5008b6:	6a ff                	push   0xffffffff
  5008b8:	68 28 88 90 00       	push   0x908828
  5008bd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5008c3:	50                   	push   eax
  5008c4:	83 ec 18             	sub    esp,0x18
  5008c7:	56                   	push   esi
  5008c8:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5008cd:	33 c4                	xor    eax,esp
  5008cf:	50                   	push   eax
  5008d0:	8d 44 24 20          	lea    eax,[esp+0x20]
  5008d4:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5008da:	33 f6                	xor    esi,esi
  5008dc:	89 74 24 0c          	mov    DWORD PTR [esp+0xc],esi
  5008e0:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  5008e4:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5008e8:	8d 44 24 0c          	lea    eax,[esp+0xc]
  5008ec:	50                   	push   eax
  5008ed:	51                   	push   ecx
  5008ee:	52                   	push   edx
  5008ef:	89 74 24 34          	mov    DWORD PTR [esp+0x34],esi
  5008f3:	e8 08 01 00 00       	call   0x500a00
  5008f8:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  5008fc:	3b 44 24 10          	cmp    eax,DWORD PTR [esp+0x10]
  500900:	75 20                	jne    0x500922
  500902:	3b c6                	cmp    eax,esi
  500904:	74 09                	je     0x50090f
  500906:	50                   	push   eax
  500907:	e8 00 09 39 00       	call   0x89120c
  50090c:	83 c4 04             	add    esp,0x4
  50090f:	33 c0                	xor    eax,eax
  500911:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500915:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50091c:	59                   	pop    ecx
  50091d:	5e                   	pop    esi
  50091e:	8b e5                	mov    esp,ebp
  500920:	5d                   	pop    ebp
  500921:	c3                   	ret
  500922:	8b 08                	mov    ecx,DWORD PTR [eax]
  500924:	0f b7 31             	movzx  esi,WORD PTR [ecx]
  500927:	50                   	push   eax
  500928:	e8 df 08 39 00       	call   0x89120c
  50092d:	83 c4 04             	add    esp,0x4
  500930:	66 8b c6             	mov    ax,si
  500933:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500937:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50093e:	59                   	pop    ecx
  50093f:	5e                   	pop    esi
  500940:	8b e5                	mov    esp,ebp
  500942:	5d                   	pop    ebp
  500943:	c3                   	ret

```


## QuestOwner key append — 0x503400 .. 0x503432

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00503400 <.text+0x102400>:
  503400:	55                   	push   ebp
  503401:	8b ec                	mov    ebp,esp
  503403:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503406:	56                   	push   esi
  503407:	8b f1                	mov    esi,ecx
  503409:	57                   	push   edi
  50340a:	83 c0 02             	add    eax,0x2
  50340d:	8d be b0 5e 00 00    	lea    edi,[esi+0x5eb0]
  503413:	e8 c8 80 f4 ff       	call   0x44b4e0
  503418:	e8 43 bc f0 ff       	call   0x40f060
  50341d:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  503423:	50                   	push   eax
  503424:	56                   	push   esi
  503425:	e8 16 ce ff ff       	call   0x500240
  50342a:	5f                   	pop    edi
  50342b:	33 c0                	xor    eax,eax
  50342d:	5e                   	pop    esi
  50342e:	5d                   	pop    ebp
  50342f:	c2 0c 00             	ret    0xc

```