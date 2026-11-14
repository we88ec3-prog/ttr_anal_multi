; E01 native file loader status flag and return

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4a50 <.text+0x2f3a50>:
  6f4a50:	55                                              	push   ebp
  6f4a51:	8b ec                                           	mov    ebp,esp
  6f4a53:	83 e4 f8                                        	and    esp,0xfffffff8
  6f4a56:	81 ec 2c 02 00 00                               	sub    esp,0x22c
  6f4a5c:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  6f4a61:	33 c4                                           	xor    eax,esp
  6f4a63:	89 84 24 28 02 00 00                            	mov    DWORD PTR [esp+0x228],eax
  6f4a6a:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f4a6d:	53                                              	push   ebx
  6f4a6e:	56                                              	push   esi
  6f4a6f:	8d 54 24 2c                                     	lea    edx,[esp+0x2c]
  6f4a73:	57                                              	push   edi
  6f4a74:	89 4c 24 18                                     	mov    DWORD PTR [esp+0x18],ecx
  6f4a78:	2b d0                                           	sub    edx,eax
  6f4a7a:	8d 9b 00 00 00 00                               	lea    ebx,[ebx+0x0]
  6f4a80:	8a 08                                           	mov    cl,BYTE PTR [eax]
  6f4a82:	88 0c 02                                        	mov    BYTE PTR [edx+eax*1],cl
  6f4a85:	40                                              	inc    eax
  6f4a86:	84 c9                                           	test   cl,cl
  6f4a88:	75 f6                                           	jne    0x6f4a80
  6f4a8a:	8d 54 24 30                                     	lea    edx,[esp+0x30]
  6f4a8e:	68 e0 d1 be 00                                  	push   0xbed1e0
  6f4a93:	52                                              	push   edx
  6f4a94:	be 01 00 00 00                                  	mov    esi,0x1
  6f4a99:	e8 d2 fc 01 00                                  	call   0x714770
  6f4a9e:	8b f8                                           	mov    edi,eax
  6f4aa0:	83 c4 08                                        	add    esp,0x8
  6f4aa3:	85 ff                                           	test   edi,edi
  6f4aa5:	0f 84 24 01 00 00                               	je     0x6f4bcf
  6f4aab:	8b 07                                           	mov    eax,DWORD PTR [edi]
  6f4aad:	8b 50 2c                                        	mov    edx,DWORD PTR [eax+0x2c]
  6f4ab0:	8b cf                                           	mov    ecx,edi
  6f4ab2:	ff d2                                           	call   edx
  6f4ab4:	8b f0                                           	mov    esi,eax
  6f4ab6:	8d 46 01                                        	lea    eax,[esi+0x1]
  6f4ab9:	50                                              	push   eax
  6f4aba:	e8 7e 91 18 00                                  	call   0x87dc3d
  6f4abf:	8b 17                                           	mov    edx,DWORD PTR [edi]
  6f4ac1:	83 c4 04                                        	add    esp,0x4
  6f4ac4:	8b d8                                           	mov    ebx,eax
  6f4ac6:	8b 42 38                                        	mov    eax,DWORD PTR [edx+0x38]
  6f4ac9:	56                                              	push   esi
  6f4aca:	8b cf                                           	mov    ecx,edi
  6f4acc:	ff d0                                           	call   eax
  6f4ace:	50                                              	push   eax
  6f4acf:	53                                              	push   ebx
  6f4ad0:	e8 fb 90 1a 00                                  	call   0x89dbd0
  6f4ad5:	c6 04 1e 00                                     	mov    BYTE PTR [esi+ebx*1],0x0
  6f4ad9:	8b 17                                           	mov    edx,DWORD PTR [edi]
  6f4adb:	8b 42 2c                                        	mov    eax,DWORD PTR [edx+0x2c]
  6f4ade:	83 c4 0c                                        	add    esp,0xc
  6f4ae1:	8b cf                                           	mov    ecx,edi
  6f4ae3:	ff d0                                           	call   eax
  6f4ae5:	83 f8 03                                        	cmp    eax,0x3
  6f4ae8:	72 48                                           	jb     0x6f4b32
  6f4aea:	80 3b ef                                        	cmp    BYTE PTR [ebx],0xef
  6f4aed:	75 43                                           	jne    0x6f4b32
  6f4aef:	80 7b 01 bb                                     	cmp    BYTE PTR [ebx+0x1],0xbb
  6f4af3:	75 3d                                           	jne    0x6f4b32
  6f4af5:	80 7b 02 bf                                     	cmp    BYTE PTR [ebx+0x2],0xbf
  6f4af9:	75 37                                           	jne    0x6f4b32
  6f4afb:	8b 74 24 18                                     	mov    esi,DWORD PTR [esp+0x18]
  6f4aff:	8b 16                                           	mov    edx,DWORD PTR [esi]
  6f4b01:	83 c0 fd                                        	add    eax,0xfffffffd
  6f4b04:	50                                              	push   eax
  6f4b05:	8d 4b 03                                        	lea    ecx,[ebx+0x3]
  6f4b08:	51                                              	push   ecx
  6f4b09:	33 c0                                           	xor    eax,eax
  6f4b0b:	e8 00 26 00 00                                  	call   0x6f7110
  6f4b10:	83 c4 08                                        	add    esp,0x8
  6f4b13:	85 c0                                           	test   eax,eax
  6f4b15:	0f 85 9d 00 00 00                               	jne    0x6f4bb8
  6f4b1b:	8b 36                                           	mov    esi,DWORD PTR [esi]
  6f4b1d:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f4b20:	83 e8 10                                        	sub    eax,0x10
  6f4b23:	89 44 24 10                                     	mov    DWORD PTR [esp+0x10],eax
  6f4b27:	2b 46 20                                        	sub    eax,DWORD PTR [esi+0x20]
  6f4b2a:	8d 54 24 10                                     	lea    edx,[esp+0x10]
  6f4b2e:	50                                              	push   eax
  6f4b2f:	52                                              	push   edx
  6f4b30:	eb 57                                           	jmp    0x6f4b89
  6f4b32:	8b 74 24 18                                     	mov    esi,DWORD PTR [esp+0x18]
  6f4b36:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  6f4b38:	89 44 24 14                                     	mov    DWORD PTR [esp+0x14],eax
  6f4b3c:	8d 44 24 10                                     	lea    eax,[esp+0x10]
  6f4b40:	89 44 24 28                                     	mov    DWORD PTR [esp+0x28],eax
  6f4b44:	33 c0                                           	xor    eax,eax
  6f4b46:	89 4c 24 2c                                     	mov    DWORD PTR [esp+0x2c],ecx
  6f4b4a:	89 44 24 1c                                     	mov    DWORD PTR [esp+0x1c],eax
  6f4b4e:	89 44 24 20                                     	mov    DWORD PTR [esp+0x20],eax
  6f4b52:	51                                              	push   ecx
  6f4b53:	b9 00 27 c4 00                                  	mov    ecx,0xc42700
  6f4b58:	8d 44 24 20                                     	lea    eax,[esp+0x20]
  6f4b5c:	89 5c 24 14                                     	mov    DWORD PTR [esp+0x14],ebx
  6f4b60:	c7 44 24 28 e0 70 6f 00                         	mov    DWORD PTR [esp+0x28],0x6f70e0
  6f4b68:	e8 23 9e 00 00                                  	call   0x6fe990
  6f4b6d:	83 c4 04                                        	add    esp,0x4
  6f4b70:	85 c0                                           	test   eax,eax
  6f4b72:	75 44                                           	jne    0x6f4bb8
  6f4b74:	8b 36                                           	mov    esi,DWORD PTR [esi]
  6f4b76:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f4b79:	83 e8 10                                        	sub    eax,0x10
  6f4b7c:	89 44 24 10                                     	mov    DWORD PTR [esp+0x10],eax
  6f4b80:	2b 46 20                                        	sub    eax,DWORD PTR [esi+0x20]
  6f4b83:	8d 4c 24 10                                     	lea    ecx,[esp+0x10]
  6f4b87:	50                                              	push   eax
  6f4b88:	51                                              	push   ecx
  6f4b89:	68 50 5a 6f 00                                  	push   0x6f5a50
  6f4b8e:	33 d2                                           	xor    edx,edx
  6f4b90:	8b c6                                           	mov    eax,esi
  6f4b92:	c7 44 24 20 ff ff ff ff                         	mov    DWORD PTR [esp+0x20],0xffffffff
  6f4b9a:	e8 d1 9b 00 00                                  	call   0x6fe770
  6f4b9f:	8b 4e 14                                        	mov    ecx,DWORD PTR [esi+0x14]
  6f4ba2:	8b 76 08                                        	mov    esi,DWORD PTR [esi+0x8]
  6f4ba5:	83 c4 0c                                        	add    esp,0xc
  6f4ba8:	3b 71 08                                        	cmp    esi,DWORD PTR [ecx+0x8]
  6f4bab:	72 03                                           	jb     0x6f4bb0
  6f4bad:	89 71 08                                        	mov    DWORD PTR [ecx+0x8],esi
  6f4bb0:	85 c0                                           	test   eax,eax
  6f4bb2:	75 04                                           	jne    0x6f4bb8
  6f4bb4:	33 f6                                           	xor    esi,esi
  6f4bb6:	eb 05                                           	jmp    0x6f4bbd
  6f4bb8:	be 01 00 00 00                                  	mov    esi,0x1
  6f4bbd:	8b 17                                           	mov    edx,DWORD PTR [edi]
  6f4bbf:	8b 42 04                                        	mov    eax,DWORD PTR [edx+0x4]
  6f4bc2:	8b cf                                           	mov    ecx,edi
  6f4bc4:	ff d0                                           	call   eax
  6f4bc6:	53                                              	push   ebx
  6f4bc7:	e8 71 d1 19 00                                  	call   0x891d3d
  6f4bcc:	83 c4 04                                        	add    esp,0x4
  6f4bcf:	8d 4c 24 30                                     	lea    ecx,[esp+0x30]
  6f4bd3:	51                                              	push   ecx
  6f4bd4:	8d 94 24 34 01 00 00                            	lea    edx,[esp+0x134]
  6f4bdb:	68 9c 26 c4 00                                  	push   0xc4269c
  6f4be0:	52                                              	push   edx
  6f4be1:	e8 49 df 19 00                                  	call   0x892b2f
  6f4be6:	83 c4 0c                                        	add    esp,0xc
  6f4be9:	85 f6                                           	test   esi,esi
  6f4beb:	74 12                                           	je     0x6f4bff
  6f4bed:	8b 4c 24 18                                     	mov    ecx,DWORD PTR [esp+0x18]
  6f4bf1:	8d 84 24 30 01 00 00                            	lea    eax,[esp+0x130]
  6f4bf8:	50                                              	push   eax
  6f4bf9:	51                                              	push   ecx
  6f4bfa:	e8 a1 fb ff ff                                  	call   0x6f47a0
  6f4bff:	8b 8c 24 34 02 00 00                            	mov    ecx,DWORD PTR [esp+0x234]
  6f4c06:	5f                                              	pop    edi
  6f4c07:	8b c6                                           	mov    eax,esi
  6f4c09:	5e                                              	pop    esi
  6f4c0a:	5b                                              	pop    ebx
  6f4c0b:	33 cc                                           	xor    ecx,esp
  6f4c0d:	e8 ef c3 19 00                                  	call   0x891001
  6f4c12:	8b e5                                           	mov    esp,ebp
  6f4c14:	5d                                              	pop    ebp
  6f4c15:	c2 04 00                                        	ret    0x4

; E02 chunk error reporter does not rethrow or clear named entry

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f47a0 <.text+0x2f37a0>:
  6f47a0:	55                                              	push   ebp
  6f47a1:	8b ec                                           	mov    ebp,esp
  6f47a3:	51                                              	push   ecx
  6f47a4:	53                                              	push   ebx
  6f47a5:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  6f47a8:	56                                              	push   esi
  6f47a9:	57                                              	push   edi
  6f47aa:	8b 3b                                           	mov    edi,DWORD PTR [ebx]
  6f47ac:	8b 47 08                                        	mov    eax,DWORD PTR [edi+0x8]
  6f47af:	83 e8 10                                        	sub    eax,0x10
  6f47b2:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  6f47b7:	74 65                                           	je     0x6f481e
  6f47b9:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  6f47bc:	83 f8 04                                        	cmp    eax,0x4
  6f47bf:	74 05                                           	je     0x6f47c6
  6f47c1:	83 f8 03                                        	cmp    eax,0x3
  6f47c4:	75 58                                           	jne    0x6f481e
  6f47c6:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f47c9:	83 ee 10                                        	sub    esi,0x10
  6f47cc:	83 7e 08 04                                     	cmp    DWORD PTR [esi+0x8],0x4
  6f47d0:	74 25                                           	je     0x6f47f7
  6f47d2:	e8 f9 6d 00 00                                  	call   0x6fb5d0
  6f47d7:	85 c0                                           	test   eax,eax
  6f47d9:	75 04                                           	jne    0x6f47df
  6f47db:	33 f6                                           	xor    esi,esi
  6f47dd:	eb 1d                                           	jmp    0x6f47fc
  6f47df:	8b 47 10                                        	mov    eax,DWORD PTR [edi+0x10]
  6f47e2:	8b 48 44                                        	mov    ecx,DWORD PTR [eax+0x44]
  6f47e5:	3b 48 40                                        	cmp    ecx,DWORD PTR [eax+0x40]
  6f47e8:	72 07                                           	jb     0x6f47f1
  6f47ea:	8b c7                                           	mov    eax,edi
  6f47ec:	e8 af 6b 00 00                                  	call   0x6fb3a0
  6f47f1:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f47f4:	83 ee 10                                        	sub    esi,0x10
  6f47f7:	8b 36                                           	mov    esi,DWORD PTR [esi]
  6f47f9:	83 c6 10                                        	add    esi,0x10
  6f47fc:	56                                              	push   esi
  6f47fd:	68 98 20 c4 00                                  	push   0xc42098
  6f4802:	e8 b6 e8 19 00                                  	call   0x8930bd
  6f4807:	8b 55 0c                                        	mov    edx,DWORD PTR [ebp+0xc]
  6f480a:	52                                              	push   edx
  6f480b:	68 fc 25 c4 00                                  	push   0xc425fc
  6f4810:	e8 a8 e8 19 00                                  	call   0x8930bd
  6f4815:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  6f4817:	83 c4 10                                        	add    esp,0x10
  6f481a:	83 40 08 f0                                     	add    DWORD PTR [eax+0x8],0xfffffff0
  6f481e:	5f                                              	pop    edi
  6f481f:	5e                                              	pop    esi
  6f4820:	5b                                              	pop    ebx
  6f4821:	59                                              	pop    ecx
  6f4822:	5d                                              	pop    ebp
  6f4823:	c2 08 00                                        	ret    0x8

; E03 named call error reporter pop and return zero

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4830 <.text+0x2f3830>:
  6f4830:	55                                              	push   ebp
  6f4831:	8b ec                                           	mov    ebp,esp
  6f4833:	51                                              	push   ecx
  6f4834:	53                                              	push   ebx
  6f4835:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  6f4838:	56                                              	push   esi
  6f4839:	57                                              	push   edi
  6f483a:	8b 3b                                           	mov    edi,DWORD PTR [ebx]
  6f483c:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f483f:	83 ee 10                                        	sub    esi,0x10
  6f4842:	83 7e 08 04                                     	cmp    DWORD PTR [esi+0x8],0x4
  6f4846:	74 25                                           	je     0x6f486d
  6f4848:	e8 83 6d 00 00                                  	call   0x6fb5d0
  6f484d:	85 c0                                           	test   eax,eax
  6f484f:	75 04                                           	jne    0x6f4855
  6f4851:	33 f6                                           	xor    esi,esi
  6f4853:	eb 1d                                           	jmp    0x6f4872
  6f4855:	8b 47 10                                        	mov    eax,DWORD PTR [edi+0x10]
  6f4858:	8b 48 44                                        	mov    ecx,DWORD PTR [eax+0x44]
  6f485b:	3b 48 40                                        	cmp    ecx,DWORD PTR [eax+0x40]
  6f485e:	72 07                                           	jb     0x6f4867
  6f4860:	8b c7                                           	mov    eax,edi
  6f4862:	e8 39 6b 00 00                                  	call   0x6fb3a0
  6f4867:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f486a:	83 ee 10                                        	sub    esi,0x10
  6f486d:	8b 36                                           	mov    esi,DWORD PTR [esi]
  6f486f:	83 c6 10                                        	add    esi,0x10
  6f4872:	8b 55 0c                                        	mov    edx,DWORD PTR [ebp+0xc]
  6f4875:	56                                              	push   esi
  6f4876:	52                                              	push   edx
  6f4877:	68 78 26 c4 00                                  	push   0xc42678
  6f487c:	e8 3c e8 19 00                                  	call   0x8930bd
  6f4881:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  6f4883:	83 40 08 f0                                     	add    DWORD PTR [eax+0x8],0xfffffff0
  6f4887:	83 c4 0c                                        	add    esp,0xc
  6f488a:	5f                                              	pop    edi
  6f488b:	5e                                              	pop    esi
  6f488c:	33 c0                                           	xor    eax,eax
  6f488e:	5b                                              	pop    ebx
  6f488f:	59                                              	pop    ecx
  6f4890:	5d                                              	pop    ebp
  6f4891:	c2 08 00                                        	ret    0x8

; E04 zero-argument wrapper success/failure branches

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ad0a0 <.text+0xac0a0>:
  4ad0a0:	55                                              	push   ebp
  4ad0a1:	8b ec                                           	mov    ebp,esp
  4ad0a3:	53                                              	push   ebx
  4ad0a4:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  4ad0a7:	56                                              	push   esi
  4ad0a8:	8b 33                                           	mov    esi,DWORD PTR [ebx]
  4ad0aa:	57                                              	push   edi
  4ad0ab:	8b 7d 10                                        	mov    edi,DWORD PTR [ebp+0x10]
  4ad0ae:	b8 ee d8 ff ff                                  	mov    eax,0xffffd8ee
  4ad0b3:	e8 c8 85 24 00                                  	call   0x6f5680
  4ad0b8:	8b 0b                                           	mov    ecx,DWORD PTR [ebx]
  4ad0ba:	8b 41 08                                        	mov    eax,DWORD PTR [ecx+0x8]
  4ad0bd:	83 e8 10                                        	sub    eax,0x10
  4ad0c0:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  4ad0c5:	74 06                                           	je     0x4ad0cd
  4ad0c7:	83 78 08 06                                     	cmp    DWORD PTR [eax+0x8],0x6
  4ad0cb:	74 1f                                           	je     0x4ad0ec
  4ad0cd:	8b c7                                           	mov    eax,edi
  4ad0cf:	50                                              	push   eax
  4ad0d0:	68 10 26 c4 00                                  	push   0xc42610
  4ad0d5:	e8 e3 5f 3e 00                                  	call   0x8930bd
  4ad0da:	8b 1b                                           	mov    ebx,DWORD PTR [ebx]
  4ad0dc:	83 43 08 f0                                     	add    DWORD PTR [ebx+0x8],0xfffffff0
  4ad0e0:	83 c4 08                                        	add    esp,0x8
  4ad0e3:	33 c0                                           	xor    eax,eax
  4ad0e5:	5f                                              	pop    edi
  4ad0e6:	5e                                              	pop    esi
  4ad0e7:	5b                                              	pop    ebx
  4ad0e8:	5d                                              	pop    ebp
  4ad0e9:	c2 0c 00                                        	ret    0xc
  4ad0ec:	8b 7d 0c                                        	mov    edi,DWORD PTR [ebp+0xc]
  4ad0ef:	6a 00                                           	push   0x0
  4ad0f1:	33 c0                                           	xor    eax,eax
  4ad0f3:	e8 78 89 24 00                                  	call   0x6f5a70
  4ad0f8:	83 c4 04                                        	add    esp,0x4
  4ad0fb:	85 c0                                           	test   eax,eax
  4ad0fd:	75 0f                                           	jne    0x4ad10e
  4ad0ff:	89 7b 04                                        	mov    DWORD PTR [ebx+0x4],edi
  4ad102:	b8 01 00 00 00                                  	mov    eax,0x1
  4ad107:	5f                                              	pop    edi
  4ad108:	5e                                              	pop    esi
  4ad109:	5b                                              	pop    ebx
  4ad10a:	5d                                              	pop    ebp
  4ad10b:	c2 0c 00                                        	ret    0xc
  4ad10e:	8b 4d 10                                        	mov    ecx,DWORD PTR [ebp+0x10]
  4ad111:	51                                              	push   ecx
  4ad112:	53                                              	push   ebx
  4ad113:	e8 18 77 24 00                                  	call   0x6f4830
  4ad118:	5f                                              	pop    edi
  4ad119:	5e                                              	pop    esi
  4ad11a:	5b                                              	pop    ebx
  4ad11b:	5d                                              	pop    ebp
  4ad11c:	c2 0c 00                                        	ret    0xc

; E05 Tutorial tick overwrites status then converts stack top

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a8b90 <.text+0xa7b90>:
  4a8b90:	55                                              	push   ebp
  4a8b91:	8b ec                                           	mov    ebp,esp
  4a8b93:	83 ec 18                                        	sub    esp,0x18
  4a8b96:	53                                              	push   ebx
  4a8b97:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  4a8b9a:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  4a8b9c:	56                                              	push   esi
  4a8b9d:	57                                              	push   edi
  4a8b9e:	68 d4 68 c0 00                                  	push   0xc068d4
  4a8ba3:	6a 01                                           	push   0x1
  4a8ba5:	50                                              	push   eax
  4a8ba6:	e8 f5 44 00 00                                  	call   0x4ad0a0
  4a8bab:	8b 0b                                           	mov    ecx,DWORD PTR [ebx]
  4a8bad:	8b 09                                           	mov    ecx,DWORD PTR [ecx]
  4a8baf:	83 c8 ff                                        	or     eax,0xffffffff
  4a8bb2:	e8 39 c5 24 00                                  	call   0x6f50f0
  4a8bb7:	8b 48 08                                        	mov    ecx,DWORD PTR [eax+0x8]
  4a8bba:	83 f9 03                                        	cmp    ecx,0x3
  4a8bbd:	74 26                                           	je     0x4a8be5
  4a8bbf:	83 f9 04                                        	cmp    ecx,0x4
  4a8bc2:	75 42                                           	jne    0x4a8c06
  4a8bc4:	8b 30                                           	mov    esi,DWORD PTR [eax]
  4a8bc6:	83 c6 10                                        	add    esi,0x10
  4a8bc9:	8d 7d f4                                        	lea    edi,[ebp-0xc]
  4a8bcc:	e8 8f eb 24 00                                  	call   0x6f7760
  4a8bd1:	85 c0                                           	test   eax,eax
  4a8bd3:	74 31                                           	je     0x4a8c06
  4a8bd5:	dd 45 f4                                        	fld    QWORD PTR [ebp-0xc]
  4a8bd8:	c7 45 f4 03 00 00 00                            	mov    DWORD PTR [ebp-0xc],0x3
  4a8bdf:	dd 5d ec                                        	fstp   QWORD PTR [ebp-0x14]
  4a8be2:	8d 45 ec                                        	lea    eax,[ebp-0x14]
  4a8be5:	dd 00                                           	fld    QWORD PTR [eax]
  4a8be7:	dd 5d f4                                        	fstp   QWORD PTR [ebp-0xc]
  4a8bea:	dd 45 f4                                        	fld    QWORD PTR [ebp-0xc]
  4a8bed:	db 5d 08                                        	fistp  DWORD PTR [ebp+0x8]
  4a8bf0:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  4a8bf3:	33 d2                                           	xor    edx,edx
  4a8bf5:	85 c0                                           	test   eax,eax
  4a8bf7:	0f 95 c2                                        	setne  dl
  4a8bfa:	89 53 34                                        	mov    DWORD PTR [ebx+0x34],edx
  4a8bfd:	5f                                              	pop    edi
  4a8bfe:	5e                                              	pop    esi
  4a8bff:	5b                                              	pop    ebx
  4a8c00:	8b e5                                           	mov    esp,ebp
  4a8c02:	5d                                              	pop    ebp
  4a8c03:	c2 04 00                                        	ret    0x4
  4a8c06:	33 d2                                           	xor    edx,edx
  4a8c08:	33 c0                                           	xor    eax,eax
  4a8c0a:	85 c0                                           	test   eax,eax
  4a8c0c:	0f 95 c2                                        	setne  dl
  4a8c0f:	5f                                              	pop    edi
  4a8c10:	5e                                              	pop    esi
  4a8c11:	89 53 34                                        	mov    DWORD PTR [ebx+0x34],edx
  4a8c14:	5b                                              	pop    ebx
  4a8c15:	8b e5                                           	mov    esp,ebp
  4a8c17:	5d                                              	pop    ebp
  4a8c18:	c2 04 00                                        	ret    0x4

; E06 Q tick ignores named-call result and advances to actor update

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005615cd <.text+0x1605cd>:
  5615cd:	8b 07                                           	mov    eax,DWORD PTR [edi]
  5615cf:	6a 00                                           	push   0x0
  5615d1:	6a 00                                           	push   0x0
  5615d3:	68 a0 06 c1 00                                  	push   0xc106a0
  5615d8:	e8 f3 37 19 00                                  	call   0x6f4dd0
  5615dd:	83 c4 0c                                        	add    esp,0xc
  5615e0:	8b 7f 1c                                        	mov    edi,DWORD PTR [edi+0x1c]
  5615e3:	8b 37                                           	mov    esi,DWORD PTR [edi]
  5615e5:	3b f7                                           	cmp    esi,edi
  5615e7:	74 55                                           	je     0x56163e
  5615e9:	8d a4 24 00 00 00 00                            	lea    esp,[esp+0x0]
  5615f0:	8b 4e 10                                        	mov    ecx,DWORD PTR [esi+0x10]
  5615f3:	8b 11                                           	mov    edx,DWORD PTR [ecx]
  5615f5:	8b 42 20                                        	mov    eax,DWORD PTR [edx+0x20]
  5615f8:	ff d0                                           	call   eax

; E07 Synopsis loader result not checked before fixed global call

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a8a2f <.text+0xa7a2f>:
  4a8a2f:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  4a8a31:	68 7c 68 c0 00                                  	push   0xc0687c
  4a8a36:	e8 15 c0 24 00                                  	call   0x6f4a50
  4a8a3b:	8b 06                                           	mov    eax,DWORD PTR [esi]
  4a8a3d:	6a 00                                           	push   0x0
  4a8a3f:	6a 00                                           	push   0x0
  4a8a41:	68 94 68 c0 00                                  	push   0xc06894
  4a8a46:	e8 85 c3 24 00                                  	call   0x6f4dd0

; E08 Tutorial loader result not checked before fixed global call

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a8b5d <.text+0xa7b5d>:
  4a8b5d:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00                                  	push   0xc0687c
  4a8b64:	e8 e7 be 24 00                                  	call   0x6f4a50
  4a8b69:	8b 06                                           	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                                           	push   0x0
  4a8b6d:	6a 00                                           	push   0x0
  4a8b6f:	68 a8 68 c0 00                                  	push   0xc068a8
  4a8b74:	e8 57 c2 24 00                                  	call   0x6f4dd0

; E09 normal Q entry and post-load control flow, including missing-row exit

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561760 <.text+0x160760>:
  561760:	55                                              	push   ebp
  561761:	8b ec                                           	mov    ebp,esp
  561763:	83 e4 f8                                        	and    esp,0xfffffff8
  561766:	6a ff                                           	push   0xffffffff
  561768:	68 2c fd 93 00                                  	push   0x93fd2c
  56176d:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  561773:	50                                              	push   eax
  561774:	83 ec 50                                        	sub    esp,0x50
  561777:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  56177c:	33 c4                                           	xor    eax,esp
  56177e:	89 44 24 48                                     	mov    DWORD PTR [esp+0x48],eax
  561782:	53                                              	push   ebx
  561783:	56                                              	push   esi
  561784:	57                                              	push   edi
  561785:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  56178a:	33 c4                                           	xor    eax,esp
  56178c:	50                                              	push   eax
  56178d:	8d 44 24 60                                     	lea    eax,[esp+0x60]
  561791:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  561797:	83 3d 18 ab fb 00 00                            	cmp    DWORD PTR ds:0xfbab18,0x0
  56179e:	8b d9                                           	mov    ebx,ecx
  5617a0:	74 20                                           	je     0x5617c2
  5617a2:	0f 57 c0                                        	xorps  xmm0,xmm0
  5617a5:	f3 0f 11 05 24 ab fb 00                         	movss  DWORD PTR ds:0xfbab24,xmm0
  5617ad:	e8 ae d8 ea ff                                  	call   0x40f060
  5617b2:	f3 0f 10 05 70 59 c5 00                         	movss  xmm0,DWORD PTR ds:0xc55970
  5617ba:	f3 0f 11 80 ac 00 00 00                         	movss  DWORD PTR [eax+0xac],xmm0
  5617c2:	83 7b 28 00                                     	cmp    DWORD PTR [ebx+0x28],0x0
  5617c6:	c6 83 89 00 00 00 00                            	mov    BYTE PTR [ebx+0x89],0x0
  5617cd:	74 1a                                           	je     0x5617e9
  5617cf:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  5617d2:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  5617d5:	50                                              	push   eax
  5617d6:	51                                              	push   ecx
  5617d7:	68 ac 06 c1 00                                  	push   0xc106ac
  5617dc:	e8 7f c3 18 00                                  	call   0x6edb60
  5617e1:	83 c4 0c                                        	add    esp,0xc
  5617e4:	e9 9d 05 00 00                                  	jmp    0x561d86
  5617e9:	f6 05 28 88 fb 00 01                            	test   BYTE PTR ds:0xfb8828,0x1
  5617f0:	be 01 00 00 00                                  	mov    esi,0x1
  5617f5:	75 29                                           	jne    0x561820
  5617f7:	09 35 28 88 fb 00                               	or     DWORD PTR ds:0xfb8828,esi
  5617fd:	c7 44 24 68 00 00 00 00                         	mov    DWORD PTR [esp+0x68],0x0
  561805:	e8 46 e0 fe ff                                  	call   0x54f850
  56180a:	68 80 d5 bc 00                                  	push   0xbcd580
  56180f:	e8 06 0b 33 00                                  	call   0x89231a
  561814:	83 c4 04                                        	add    esp,0x4
  561817:	83 cf ff                                        	or     edi,0xffffffff
  56181a:	89 7c 24 68                                     	mov    DWORD PTR [esp+0x68],edi
  56181e:	eb 03                                           	jmp    0x561823
  561820:	83 cf ff                                        	or     edi,0xffffffff
  561823:	80 3d f1 92 fb 00 00                            	cmp    BYTE PTR ds:0xfb92f1,0x0
  56182a:	0f 84 ac 00 00 00                               	je     0x5618dc
  561830:	83 7d 08 00                                     	cmp    DWORD PTR [ebp+0x8],0x0
  561834:	0f 85 a2 00 00 00                               	jne    0x5618dc
  56183a:	e8 61 33 ea ff                                  	call   0x404ba0
  56183f:	83 b8 4c 5f 00 00 09                            	cmp    DWORD PTR [eax+0x5f4c],0x9
  561846:	74 1c                                           	je     0x561864
  561848:	e8 53 33 ea ff                                  	call   0x404ba0
  56184d:	83 b8 4c 5f 00 00 04                            	cmp    DWORD PTR [eax+0x5f4c],0x4
  561854:	74 0e                                           	je     0x561864
  561856:	e8 45 33 ea ff                                  	call   0x404ba0
  56185b:	83 b8 4c 5f 00 00 19                            	cmp    DWORD PTR [eax+0x5f4c],0x19
  561862:	75 78                                           	jne    0x5618dc
  561864:	8b 73 78                                        	mov    esi,DWORD PTR [ebx+0x78]
  561867:	8d 55 0c                                        	lea    edx,[ebp+0xc]
  56186a:	52                                              	push   edx
  56186b:	8d 4b 74                                        	lea    ecx,[ebx+0x74]
  56186e:	8d 44 24 14                                     	lea    eax,[esp+0x14]
  561872:	e8 49 4c ed ff                                  	call   0x4364c0
  561877:	39 30                                           	cmp    DWORD PTR [eax],esi
  561879:	74 5c                                           	je     0x5618d7
  56187b:	6a 0f                                           	push   0xf
  56187d:	e8 2e 3d 02 00                                  	call   0x5855b0
  561882:	8b f0                                           	mov    esi,eax
  561884:	e8 a7 3a 02 00                                  	call   0x585330
  561889:	50                                              	push   eax
  56188a:	8d 4c 24 40                                     	lea    ecx,[esp+0x40]
  56188e:	e8 bd 09 ea ff                                  	call   0x402250
  561893:	8d 44 24 3c                                     	lea    eax,[esp+0x3c]
  561897:	50                                              	push   eax
  561898:	c7 44 24 6c 01 00 00 00                         	mov    DWORD PTR [esp+0x6c],0x1
  5618a0:	e8 1b e0 ea ff                                  	call   0x40f8c0
  5618a5:	8b f8                                           	mov    edi,eax
  5618a7:	e8 84 52 f7 ff                                  	call   0x4d6b30
  5618ac:	8d 4c 24 3c                                     	lea    ecx,[esp+0x3c]
  5618b0:	c7 44 24 68 ff ff ff ff                         	mov    DWORD PTR [esp+0x68],0xffffffff
  5618b8:	e8 83 8b f9 ff                                  	call   0x4fa440
  5618bd:	e8 be 2d eb ff                                  	call   0x414680
  5618c2:	8b 4d 0c                                        	mov    ecx,DWORD PTR [ebp+0xc]
  5618c5:	51                                              	push   ecx
  5618c6:	6a 00                                           	push   0x0
  5618c8:	e8 d3 20 f4 ff                                  	call   0x4a39a0
  5618cd:	e8 de 07 00 00                                  	call   0x5620b0
  5618d2:	e9 af 04 00 00                                  	jmp    0x561d86
  5618d7:	be 01 00 00 00                                  	mov    esi,0x1
  5618dc:	f6 05 d4 ad fa 00 01                            	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38                                        	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c                                        	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28                                        	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                                           	jne    0x561918
  5618f4:	09 35 d4 ad fa 00                               	or     DWORD PTR ds:0xfaadd4,esi
  5618fa:	c7 44 24 68 02 00 00 00                         	mov    DWORD PTR [esp+0x68],0x2
  561902:	e8 79 5b 02 00                                  	call   0x587480
  561907:	68 c0 cc bc 00                                  	push   0xbcccc0
  56190c:	e8 09 0a 33 00                                  	call   0x89231a
  561911:	83 c4 04                                        	add    esp,0x4
  561914:	89 7c 24 68                                     	mov    DWORD PTR [esp+0x68],edi
  561918:	f6 05 d0 ad fa 00 01                            	test   BYTE PTR ds:0xfaadd0,0x1
  56191f:	75 24                                           	jne    0x561945
  561921:	09 35 d0 ad fa 00                               	or     DWORD PTR ds:0xfaadd0,esi
  561927:	c7 44 24 68 03 00 00 00                         	mov    DWORD PTR [esp+0x68],0x3
  56192f:	e8 5c c0 1e 00                                  	call   0x74d990
  561934:	68 70 cc bc 00                                  	push   0xbccc70
  561939:	e8 dc 09 33 00                                  	call   0x89231a
  56193e:	83 c4 04                                        	add    esp,0x4
  561941:	89 7c 24 68                                     	mov    DWORD PTR [esp+0x68],edi
  561945:	f6 05 90 43 f9 00 01                            	test   BYTE PTR ds:0xf94390,0x1
  56194c:	8b 0d bc 5b f9 00                               	mov    ecx,DWORD PTR ds:0xf95bbc
  561952:	8b 15 c0 5b f9 00                               	mov    edx,DWORD PTR ds:0xf95bc0
  561958:	89 4c 24 14                                     	mov    DWORD PTR [esp+0x14],ecx
  56195c:	f3 0f 10 44 24 14                               	movss  xmm0,DWORD PTR [esp+0x14]
  561962:	89 54 24 18                                     	mov    DWORD PTR [esp+0x18],edx
  561966:	f3 0f 11 83 84 00 00 00                         	movss  DWORD PTR [ebx+0x84],xmm0
  56196e:	75 24                                           	jne    0x561994
  561970:	09 35 90 43 f9 00                               	or     DWORD PTR ds:0xf94390,esi
  561976:	c7 44 24 68 04 00 00 00                         	mov    DWORD PTR [esp+0x68],0x4
  56197e:	e8 0d fc f7 ff                                  	call   0x4e1590
  561983:	68 80 cc bc 00                                  	push   0xbccc80
  561988:	e8 8d 09 33 00                                  	call   0x89231a
  56198d:	83 c4 04                                        	add    esp,0x4
  561990:	89 7c 24 68                                     	mov    DWORD PTR [esp+0x68],edi
  561994:	f6 05 d4 ad fa 00 01                            	test   BYTE PTR ds:0xfaadd4,0x1
  56199b:	a0 a4 42 f9 00                                  	mov    al,ds:0xf942a4
  5619a0:	88 83 88 00 00 00                               	mov    BYTE PTR [ebx+0x88],al
  5619a6:	75 24                                           	jne    0x5619cc
  5619a8:	09 35 d4 ad fa 00                               	or     DWORD PTR ds:0xfaadd4,esi
  5619ae:	c7 44 24 68 05 00 00 00                         	mov    DWORD PTR [esp+0x68],0x5
  5619b6:	e8 c5 5a 02 00                                  	call   0x587480
  5619bb:	68 c0 cc bc 00                                  	push   0xbcccc0
  5619c0:	e8 55 09 33 00                                  	call   0x89231a
  5619c5:	83 c4 04                                        	add    esp,0x4
  5619c8:	89 7c 24 68                                     	mov    DWORD PTR [esp+0x68],edi
  5619cc:	68 58 43 0f 00                                  	push   0xf4358
  5619d1:	e8 fa 90 02 00                                  	call   0x58aad0
  5619d6:	83 c4 04                                        	add    esp,0x4
  5619d9:	f6 05 90 43 f9 00 01                            	test   BYTE PTR ds:0xf94390,0x1
  5619e0:	75 24                                           	jne    0x561a06
  5619e2:	09 35 90 43 f9 00                               	or     DWORD PTR ds:0xf94390,esi
  5619e8:	c7 44 24 68 06 00 00 00                         	mov    DWORD PTR [esp+0x68],0x6
  5619f0:	e8 9b fb f7 ff                                  	call   0x4e1590
  5619f5:	68 80 cc bc 00                                  	push   0xbccc80
  5619fa:	e8 1b 09 33 00                                  	call   0x89231a
  5619ff:	83 c4 04                                        	add    esp,0x4
  561a02:	89 7c 24 68                                     	mov    DWORD PTR [esp+0x68],edi
  561a06:	6a 00                                           	push   0x0
  561a08:	68 75 23 bf 00                                  	push   0xbf2375
  561a0d:	8d 4b 44                                        	lea    ecx,[ebx+0x44]
  561a10:	c6 05 a4 42 f9 00 01                            	mov    BYTE PTR ds:0xf942a4,0x1
  561a17:	e8 54 10 ea ff                                  	call   0x402a70
  561a1c:	8b 73 0c                                        	mov    esi,DWORD PTR [ebx+0xc]
  561a1f:	8b 46 04                                        	mov    eax,DWORD PTR [esi+0x4]
  561a22:	80 78 31 00                                     	cmp    BYTE PTR [eax+0x31],0x0
  561a26:	8b d6                                           	mov    edx,esi
  561a28:	75 2c                                           	jne    0x561a56
  561a2a:	8d 9b 00 00 00 00                               	lea    ebx,[ebx+0x0]
  561a30:	8b 48 0c                                        	mov    ecx,DWORD PTR [eax+0xc]
  561a33:	8b 7d 08                                        	mov    edi,DWORD PTR [ebp+0x8]
  561a36:	3b f9                                           	cmp    edi,ecx
  561a38:	7f 0a                                           	jg     0x561a44
  561a3a:	7c 0d                                           	jl     0x561a49
  561a3c:	8b 4d 0c                                        	mov    ecx,DWORD PTR [ebp+0xc]
  561a3f:	39 48 10                                        	cmp    DWORD PTR [eax+0x10],ecx
  561a42:	7d 05                                           	jge    0x561a49
  561a44:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  561a47:	eb 04                                           	jmp    0x561a4d
  561a49:	8b d0                                           	mov    edx,eax
  561a4b:	8b 00                                           	mov    eax,DWORD PTR [eax]
  561a4d:	80 78 31 00                                     	cmp    BYTE PTR [eax+0x31],0x0
  561a51:	74 dd                                           	je     0x561a30
  561a53:	83 cf ff                                        	or     edi,0xffffffff
  561a56:	89 54 24 1c                                     	mov    DWORD PTR [esp+0x1c],edx
  561a5a:	3b d6                                           	cmp    edx,esi
  561a5c:	74 1a                                           	je     0x561a78
  561a5e:	8b 42 0c                                        	mov    eax,DWORD PTR [edx+0xc]
  561a61:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  561a64:	3b c1                                           	cmp    eax,ecx
  561a66:	7f 10                                           	jg     0x561a78
  561a68:	7c 08                                           	jl     0x561a72
  561a6a:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  561a6d:	3b 42 10                                        	cmp    eax,DWORD PTR [edx+0x10]
  561a70:	7c 06                                           	jl     0x561a78
  561a72:	8d 44 24 1c                                     	lea    eax,[esp+0x1c]
  561a76:	eb 08                                           	jmp    0x561a80
  561a78:	89 74 24 10                                     	mov    DWORD PTR [esp+0x10],esi
  561a7c:	8d 44 24 10                                     	lea    eax,[esp+0x10]
  561a80:	8b 30                                           	mov    esi,DWORD PTR [eax]
  561a82:	3b 73 0c                                        	cmp    esi,DWORD PTR [ebx+0xc]
  561a85:	0f 84 f4 02 00 00                               	je     0x561d7f
  561a8b:	6a 10                                           	push   0x10
  561a8d:	68 d0 06 c1 00                                  	push   0xc106d0
  561a92:	8d 4c 24 28                                     	lea    ecx,[esp+0x28]
  561a96:	c7 44 24 3c 0f 00 00 00                         	mov    DWORD PTR [esp+0x3c],0xf
  561a9e:	c7 44 24 38 00 00 00 00                         	mov    DWORD PTR [esp+0x38],0x0
  561aa6:	c6 44 24 28 00                                  	mov    BYTE PTR [esp+0x28],0x0
  561aab:	e8 c0 0f ea ff                                  	call   0x402a70
  561ab0:	8d 46 14                                        	lea    eax,[esi+0x14]
  561ab3:	57                                              	push   edi
  561ab4:	33 f6                                           	xor    esi,esi
  561ab6:	56                                              	push   esi
  561ab7:	50                                              	push   eax
  561ab8:	8d 4c 24 2c                                     	lea    ecx,[esp+0x2c]
  561abc:	c7 44 24 74 07 00 00 00                         	mov    DWORD PTR [esp+0x74],0x7
  561ac4:	e8 07 04 ea ff                                  	call   0x401ed0
  561ac9:	6a 04                                           	push   0x4
  561acb:	68 e4 06 c1 00                                  	push   0xc106e4
  561ad0:	8d 4c 24 28                                     	lea    ecx,[esp+0x28]
  561ad4:	e8 e7 04 ea ff                                  	call   0x401fc0
  561ad9:	83 7c 24 34 10                                  	cmp    DWORD PTR [esp+0x34],0x10
  561ade:	8b 44 24 20                                     	mov    eax,DWORD PTR [esp+0x20]
  561ae2:	73 04                                           	jae    0x561ae8
  561ae4:	8d 44 24 20                                     	lea    eax,[esp+0x20]
  561ae8:	50                                              	push   eax
  561ae9:	51                                              	push   ecx
  561aea:	e8 b1 aa ff ff                                  	call   0x55c5a0
  561aef:	83 c4 04                                        	add    esp,0x4
  561af2:	50                                              	push   eax
  561af3:	e8 a8 bb ff ff                                  	call   0x55d6a0
  561af8:	6a 1c                                           	push   0x1c
  561afa:	89 43 70                                        	mov    DWORD PTR [ebx+0x70],eax
  561afd:	e8 66 f7 32 00                                  	call   0x891268
  561b02:	83 c4 04                                        	add    esp,0x4
  561b05:	3b c6                                           	cmp    eax,esi
  561b07:	74 11                                           	je     0x561b1a
  561b09:	89 30                                           	mov    DWORD PTR [eax],esi
  561b0b:	c6 40 08 01                                     	mov    BYTE PTR [eax+0x8],0x1
  561b0f:	89 70 0c                                        	mov    DWORD PTR [eax+0xc],esi
  561b12:	89 70 10                                        	mov    DWORD PTR [eax+0x10],esi
  561b15:	89 70 14                                        	mov    DWORD PTR [eax+0x14],esi
  561b18:	eb 02                                           	jmp    0x561b1c
  561b1a:	33 c0                                           	xor    eax,eax
  561b1c:	50                                              	push   eax
  561b1d:	8d 4c 24 18                                     	lea    ecx,[esp+0x18]
  561b21:	51                                              	push   ecx
  561b22:	89 74 24 1c                                     	mov    DWORD PTR [esp+0x1c],esi
  561b26:	89 74 24 20                                     	mov    DWORD PTR [esp+0x20],esi
  561b2a:	e8 a1 a5 f1 ff                                  	call   0x47c0d0
  561b2f:	c6 44 24 68 08                                  	mov    BYTE PTR [esp+0x68],0x8
  561b34:	8b 74 24 14                                     	mov    esi,DWORD PTR [esp+0x14]
  561b38:	c7 46 04 03 00 00 00                            	mov    DWORD PTR [esi+0x4],0x3
  561b3f:	c6 46 08 01                                     	mov    BYTE PTR [esi+0x8],0x1
  561b43:	8b 4b 70                                        	mov    ecx,DWORD PTR [ebx+0x70]
  561b46:	8b 41 04                                        	mov    eax,DWORD PTR [ecx+0x4]
  561b49:	8b 00                                           	mov    eax,DWORD PTR [eax]
  561b4b:	89 44 24 1c                                     	mov    DWORD PTR [esp+0x1c],eax
  561b4f:	3b 41 04                                        	cmp    eax,DWORD PTR [ecx+0x4]
  561b52:	74 36                                           	je     0x561b8a
  561b54:	8d 7e 0c                                        	lea    edi,[esi+0xc]
  561b57:	eb 07                                           	jmp    0x561b60
  561b59:	8d a4 24 00 00 00 00                            	lea    esp,[esp+0x0]
  561b60:	8b 50 10                                        	mov    edx,DWORD PTR [eax+0x10]
  561b63:	0f b7 02                                        	movzx  eax,WORD PTR [edx]
  561b66:	89 44 24 10                                     	mov    DWORD PTR [esp+0x10],eax
  561b6a:	8d 44 24 10                                     	lea    eax,[esp+0x10]
  561b6e:	e8 0d 6b f4 ff                                  	call   0x4a8680
  561b73:	8d 44 24 1c                                     	lea    eax,[esp+0x1c]
  561b77:	e8 24 cb f3 ff                                  	call   0x49e6a0
  561b7c:	8b 43 70                                        	mov    eax,DWORD PTR [ebx+0x70]
  561b7f:	8b 48 04                                        	mov    ecx,DWORD PTR [eax+0x4]
  561b82:	8b 44 24 1c                                     	mov    eax,DWORD PTR [esp+0x1c]
  561b86:	3b c1                                           	cmp    eax,ecx
  561b88:	75 d6                                           	jne    0x561b60
  561b8a:	8b 54 24 18                                     	mov    edx,DWORD PTR [esp+0x18]
  561b8e:	83 ec 08                                        	sub    esp,0x8
  561b91:	8b fc                                           	mov    edi,esp
  561b93:	89 64 24 18                                     	mov    DWORD PTR [esp+0x18],esp
  561b97:	c7 07 00 00 00 00                               	mov    DWORD PTR [edi],0x0
  561b9d:	c7 47 04 00 00 00 00                            	mov    DWORD PTR [edi+0x4],0x0
  561ba4:	85 d2                                           	test   edx,edx
  561ba6:	74 16                                           	je     0x561bbe
  561ba8:	e8 a3 a6 f1 ff                                  	call   0x47c250
  561bad:	84 c0                                           	test   al,al
  561baf:	74 0d                                           	je     0x561bbe
  561bb1:	8b 4c 24 20                                     	mov    ecx,DWORD PTR [esp+0x20]
  561bb5:	51                                              	push   ecx
  561bb6:	56                                              	push   esi
  561bb7:	8b f7                                           	mov    esi,edi
  561bb9:	e8 02 16 24 00                                  	call   0x7a31c0
  561bbe:	c6 44 24 70 09                                  	mov    BYTE PTR [esp+0x70],0x9
  561bc3:	f6 05 60 0f fc 00 01                            	test   BYTE PTR ds:0xfc0f60,0x1
  561bca:	75 23                                           	jne    0x561bef
  561bcc:	83 0d 60 0f fc 00 01                            	or     DWORD PTR ds:0xfc0f60,0x1
  561bd3:	c6 44 24 70 0a                                  	mov    BYTE PTR [esp+0x70],0xa
  561bd8:	e8 63 b3 23 00                                  	call   0x79cf40
  561bdd:	68 80 db bc 00                                  	push   0xbcdb80
  561be2:	e8 33 07 33 00                                  	call   0x89231a
  561be7:	83 c4 04                                        	add    esp,0x4
  561bea:	c6 44 24 70 09                                  	mov    BYTE PTR [esp+0x70],0x9
  561bef:	b9 90 0e fc 00                                  	mov    ecx,0xfc0e90
  561bf4:	c6 44 24 70 08                                  	mov    BYTE PTR [esp+0x70],0x8
  561bf9:	e8 e2 c0 23 00                                  	call   0x79dce0
  561bfe:	8b f0                                           	mov    esi,eax
  561c00:	6a ff                                           	push   0xffffffff
  561c02:	56                                              	push   esi
  561c03:	ff 15 fc 20 bd 00                               	call   DWORD PTR ds:0xbd20fc
  561c09:	56                                              	push   esi
  561c0a:	ff 15 c8 21 bd 00                               	call   DWORD PTR ds:0xbd21c8
  561c10:	f6 05 70 17 fe 00 01                            	test   BYTE PTR ds:0xfe1770,0x1
  561c17:	75 23                                           	jne    0x561c3c
  561c19:	83 0d 70 17 fe 00 01                            	or     DWORD PTR ds:0xfe1770,0x1
  561c20:	c6 44 24 68 0b                                  	mov    BYTE PTR [esp+0x68],0xb
  561c25:	e8 76 61 25 00                                  	call   0x7b7da0
  561c2a:	68 90 e7 bc 00                                  	push   0xbce790
  561c2f:	e8 e6 06 33 00                                  	call   0x89231a
  561c34:	83 c4 04                                        	add    esp,0x4
  561c37:	c6 44 24 68 08                                  	mov    BYTE PTR [esp+0x68],0x8
  561c3c:	8b 3d 3c 17 fe 00                               	mov    edi,DWORD PTR ds:0xfe173c
  561c42:	8b 47 04                                        	mov    eax,DWORD PTR [edi+0x4]
  561c45:	8b 30                                           	mov    esi,DWORD PTR [eax]
  561c47:	3b f0                                           	cmp    esi,eax
  561c49:	74 1c                                           	je     0x561c67
  561c4b:	eb 03                                           	jmp    0x561c50
  561c4d:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  561c50:	8b 4e 24                                        	mov    ecx,DWORD PTR [esi+0x24]
  561c53:	83 79 04 00                                     	cmp    DWORD PTR [ecx+0x4],0x0
  561c57:	75 07                                           	jne    0x561c60
  561c59:	8b 11                                           	mov    edx,DWORD PTR [ecx]
  561c5b:	8b 42 04                                        	mov    eax,DWORD PTR [edx+0x4]
  561c5e:	ff d0                                           	call   eax
  561c60:	8b 36                                           	mov    esi,DWORD PTR [esi]
  561c62:	3b 77 04                                        	cmp    esi,DWORD PTR [edi+0x4]
  561c65:	75 e9                                           	jne    0x561c50
  561c67:	8b 44 24 20                                     	mov    eax,DWORD PTR [esp+0x20]
  561c6b:	bf 10 00 00 00                                  	mov    edi,0x10
  561c70:	39 7c 24 34                                     	cmp    DWORD PTR [esp+0x34],edi
  561c74:	73 04                                           	jae    0x561c7a
  561c76:	8d 44 24 20                                     	lea    eax,[esp+0x20]
  561c7a:	8b 0b                                           	mov    ecx,DWORD PTR [ebx]
  561c7c:	50                                              	push   eax
  561c7d:	e8 ce 2d 19 00                                  	call   0x6f4a50
  561c82:	33 db                                           	xor    ebx,ebx
  561c84:	f6 05 ec 79 fb 00 01                            	test   BYTE PTR ds:0xfb79ec,0x1
  561c8b:	be 01 00 00 00                                  	mov    esi,0x1
  561c90:	75 35                                           	jne    0x561cc7
  561c92:	09 35 ec 79 fb 00                               	or     DWORD PTR ds:0xfb79ec,esi
  561c98:	68 70 d2 bc 00                                  	push   0xbcd270
  561c9d:	c7 05 f0 79 fb 00 68 f8 c0 00                   	mov    DWORD PTR ds:0xfb79f0,0xc0f868
  561ca7:	89 1d f4 79 fb 00                               	mov    DWORD PTR ds:0xfb79f4,ebx
  561cad:	89 1d f8 79 fb 00                               	mov    DWORD PTR ds:0xfb79f8,ebx
  561cb3:	89 1d fc 79 fb 00                               	mov    DWORD PTR ds:0xfb79fc,ebx
  561cb9:	89 35 04 7a fb 00                               	mov    DWORD PTR ds:0xfb7a04,esi
  561cbf:	e8 56 06 33 00                                  	call   0x89231a
  561cc4:	83 c4 04                                        	add    esp,0x4
  561cc7:	f6 05 60 0f fc 00 01                            	test   BYTE PTR ds:0xfc0f60,0x1
  561cce:	89 1d 04 7a fb 00                               	mov    DWORD PTR ds:0xfb7a04,ebx
  561cd4:	75 22                                           	jne    0x561cf8
  561cd6:	09 35 60 0f fc 00                               	or     DWORD PTR ds:0xfc0f60,esi
  561cdc:	c6 44 24 68 0c                                  	mov    BYTE PTR [esp+0x68],0xc
  561ce1:	e8 5a b2 23 00                                  	call   0x79cf40
  561ce6:	68 80 db bc 00                                  	push   0xbcdb80
  561ceb:	e8 2a 06 33 00                                  	call   0x89231a
  561cf0:	83 c4 04                                        	add    esp,0x4
  561cf3:	c6 44 24 68 08                                  	mov    BYTE PTR [esp+0x68],0x8
  561cf8:	6a 02                                           	push   0x2
  561cfa:	68 90 0e fc 00                                  	push   0xfc0e90
  561cff:	e8 bc bc 23 00                                  	call   0x79d9c0
  561d04:	f6 05 d8 94 fd 00 01                            	test   BYTE PTR ds:0xfd94d8,0x1
  561d0b:	75 1d                                           	jne    0x561d2a
  561d0d:	09 35 d8 94 fd 00                               	or     DWORD PTR ds:0xfd94d8,esi
  561d13:	c6 44 24 68 0d                                  	mov    BYTE PTR [esp+0x68],0xd
  561d18:	e8 13 37 25 00                                  	call   0x7b5430
  561d1d:	68 60 e6 bc 00                                  	push   0xbce660
  561d22:	e8 f3 05 33 00                                  	call   0x89231a
  561d27:	83 c4 04                                        	add    esp,0x4
  561d2a:	c6 44 24 68 07                                  	mov    BYTE PTR [esp+0x68],0x7
  561d2f:	8b 74 24 18                                     	mov    esi,DWORD PTR [esp+0x18]
  561d33:	c7 05 b0 94 fd 00 02 00 00 00                   	mov    DWORD PTR ds:0xfd94b0,0x2
  561d3d:	3b f3                                           	cmp    esi,ebx
  561d3f:	74 29                                           	je     0x561d6a
  561d41:	8d 4e 04                                        	lea    ecx,[esi+0x4]
  561d44:	83 ca ff                                        	or     edx,0xffffffff
  561d47:	f0 0f c1 11                                     	lock xadd DWORD PTR [ecx],edx
  561d4b:	75 1d                                           	jne    0x561d6a
  561d4d:	8b 06                                           	mov    eax,DWORD PTR [esi]
  561d4f:	8b 10                                           	mov    edx,DWORD PTR [eax]
  561d51:	8b ce                                           	mov    ecx,esi
  561d53:	ff d2                                           	call   edx
  561d55:	8d 46 08                                        	lea    eax,[esi+0x8]
  561d58:	83 c9 ff                                        	or     ecx,0xffffffff
  561d5b:	f0 0f c1 08                                     	lock xadd DWORD PTR [eax],ecx
  561d5f:	75 09                                           	jne    0x561d6a
  561d61:	8b 16                                           	mov    edx,DWORD PTR [esi]
  561d63:	8b 42 04                                        	mov    eax,DWORD PTR [edx+0x4]
  561d66:	8b ce                                           	mov    ecx,esi
  561d68:	ff d0                                           	call   eax
  561d6a:	39 7c 24 34                                     	cmp    DWORD PTR [esp+0x34],edi
  561d6e:	72 16                                           	jb     0x561d86
  561d70:	8b 4c 24 20                                     	mov    ecx,DWORD PTR [esp+0x20]
  561d74:	51                                              	push   ecx
  561d75:	e8 92 f4 32 00                                  	call   0x89120c
  561d7a:	83 c4 04                                        	add    esp,0x4
  561d7d:	eb 07                                           	jmp    0x561d86
  561d7f:	8b cb                                           	mov    ecx,ebx
  561d81:	e8 2a 00 00 00                                  	call   0x561db0
  561d86:	8b 4c 24 60                                     	mov    ecx,DWORD PTR [esp+0x60]
  561d8a:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  561d91:	59                                              	pop    ecx
  561d92:	5f                                              	pop    edi
  561d93:	5e                                              	pop    esi
  561d94:	5b                                              	pop    ebx
  561d95:	8b 4c 24 48                                     	mov    ecx,DWORD PTR [esp+0x48]
  561d99:	33 cc                                           	xor    ecx,esp
  561d9b:	e8 61 f2 32 00                                  	call   0x891001
  561da0:	8b e5                                           	mov    esp,ebp
  561da2:	5d                                              	pop    ebp
  561da3:	c2 08 00                                        	ret    0x8

; E10 review Q entry and post-load control flow, including missing-row exit

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00565720 <.text+0x164720>:
  565720:	55                                              	push   ebp
  565721:	8b ec                                           	mov    ebp,esp
  565723:	83 e4 f8                                        	and    esp,0xfffffff8
  565726:	6a ff                                           	push   0xffffffff
  565728:	68 e8 fb 93 00                                  	push   0x93fbe8
  56572d:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  565733:	50                                              	push   eax
  565734:	83 ec 34                                        	sub    esp,0x34
  565737:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  56573c:	33 c4                                           	xor    eax,esp
  56573e:	89 44 24 2c                                     	mov    DWORD PTR [esp+0x2c],eax
  565742:	53                                              	push   ebx
  565743:	57                                              	push   edi
  565744:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  565749:	33 c4                                           	xor    eax,esp
  56574b:	50                                              	push   eax
  56574c:	8d 44 24 40                                     	lea    eax,[esp+0x40]
  565750:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  565756:	83 7e 28 00                                     	cmp    DWORD PTR [esi+0x28],0x0
  56575a:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  56575d:	c6 86 89 00 00 00 01                            	mov    BYTE PTR [esi+0x89],0x1
  565764:	74 17                                           	je     0x56577d
  565766:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  565769:	50                                              	push   eax
  56576a:	51                                              	push   ecx
  56576b:	68 ac 06 c1 00                                  	push   0xc106ac
  565770:	e8 eb 83 18 00                                  	call   0x6edb60
  565775:	83 c4 0c                                        	add    esp,0xc
  565778:	e9 e8 02 00 00                                  	jmp    0x565a65
  56577d:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  565780:	bb 01 00 00 00                                  	mov    ebx,0x1
  565785:	89 56 38                                        	mov    DWORD PTR [esi+0x38],edx
  565788:	89 46 3c                                        	mov    DWORD PTR [esi+0x3c],eax
  56578b:	89 5e 28                                        	mov    DWORD PTR [esi+0x28],ebx
  56578e:	84 1d d4 ad fa 00                               	test   BYTE PTR ds:0xfaadd4,bl
  565794:	75 29                                           	jne    0x5657bf
  565796:	09 1d d4 ad fa 00                               	or     DWORD PTR ds:0xfaadd4,ebx
  56579c:	c7 44 24 48 00 00 00 00                         	mov    DWORD PTR [esp+0x48],0x0
  5657a4:	e8 d7 1c 02 00                                  	call   0x587480
  5657a9:	68 c0 cc bc 00                                  	push   0xbcccc0
  5657ae:	e8 67 cb 32 00                                  	call   0x89231a
  5657b3:	83 c4 04                                        	add    esp,0x4
  5657b6:	83 cf ff                                        	or     edi,0xffffffff
  5657b9:	89 7c 24 48                                     	mov    DWORD PTR [esp+0x48],edi
  5657bd:	eb 03                                           	jmp    0x5657c2
  5657bf:	83 cf ff                                        	or     edi,0xffffffff
  5657c2:	f6 05 d0 ad fa 00 01                            	test   BYTE PTR ds:0xfaadd0,0x1
  5657c9:	75 20                                           	jne    0x5657eb
  5657cb:	09 1d d0 ad fa 00                               	or     DWORD PTR ds:0xfaadd0,ebx
  5657d1:	89 5c 24 48                                     	mov    DWORD PTR [esp+0x48],ebx
  5657d5:	e8 b6 81 1e 00                                  	call   0x74d990
  5657da:	68 70 cc bc 00                                  	push   0xbccc70
  5657df:	e8 36 cb 32 00                                  	call   0x89231a
  5657e4:	83 c4 04                                        	add    esp,0x4
  5657e7:	89 7c 24 48                                     	mov    DWORD PTR [esp+0x48],edi
  5657eb:	f6 05 90 43 f9 00 01                            	test   BYTE PTR ds:0xf94390,0x1
  5657f2:	8b 0d bc 5b f9 00                               	mov    ecx,DWORD PTR ds:0xf95bbc
  5657f8:	8b 15 c0 5b f9 00                               	mov    edx,DWORD PTR ds:0xf95bc0
  5657fe:	89 4c 24 10                                     	mov    DWORD PTR [esp+0x10],ecx
  565802:	f3 0f 10 44 24 10                               	movss  xmm0,DWORD PTR [esp+0x10]
  565808:	89 54 24 14                                     	mov    DWORD PTR [esp+0x14],edx
  56580c:	f3 0f 11 86 84 00 00 00                         	movss  DWORD PTR [esi+0x84],xmm0
  565814:	75 24                                           	jne    0x56583a
  565816:	09 1d 90 43 f9 00                               	or     DWORD PTR ds:0xf94390,ebx
  56581c:	c7 44 24 48 02 00 00 00                         	mov    DWORD PTR [esp+0x48],0x2
  565824:	e8 67 bd f7 ff                                  	call   0x4e1590
  565829:	68 80 cc bc 00                                  	push   0xbccc80
  56582e:	e8 e7 ca 32 00                                  	call   0x89231a
  565833:	83 c4 04                                        	add    esp,0x4
  565836:	89 7c 24 48                                     	mov    DWORD PTR [esp+0x48],edi
  56583a:	f6 05 d4 ad fa 00 01                            	test   BYTE PTR ds:0xfaadd4,0x1
  565841:	a0 a4 42 f9 00                                  	mov    al,ds:0xf942a4
  565846:	88 86 88 00 00 00                               	mov    BYTE PTR [esi+0x88],al
  56584c:	75 24                                           	jne    0x565872
  56584e:	09 1d d4 ad fa 00                               	or     DWORD PTR ds:0xfaadd4,ebx
  565854:	c7 44 24 48 03 00 00 00                         	mov    DWORD PTR [esp+0x48],0x3
  56585c:	e8 1f 1c 02 00                                  	call   0x587480
  565861:	68 c0 cc bc 00                                  	push   0xbcccc0
  565866:	e8 af ca 32 00                                  	call   0x89231a
  56586b:	83 c4 04                                        	add    esp,0x4
  56586e:	89 7c 24 48                                     	mov    DWORD PTR [esp+0x48],edi
  565872:	68 58 43 0f 00                                  	push   0xf4358
  565877:	e8 54 52 02 00                                  	call   0x58aad0
  56587c:	83 c4 04                                        	add    esp,0x4
  56587f:	f6 05 90 43 f9 00 01                            	test   BYTE PTR ds:0xf94390,0x1
  565886:	75 24                                           	jne    0x5658ac
  565888:	09 1d 90 43 f9 00                               	or     DWORD PTR ds:0xf94390,ebx
  56588e:	c7 44 24 48 04 00 00 00                         	mov    DWORD PTR [esp+0x48],0x4
  565896:	e8 f5 bc f7 ff                                  	call   0x4e1590
  56589b:	68 80 cc bc 00                                  	push   0xbccc80
  5658a0:	e8 75 ca 32 00                                  	call   0x89231a
  5658a5:	83 c4 04                                        	add    esp,0x4
  5658a8:	89 7c 24 48                                     	mov    DWORD PTR [esp+0x48],edi
  5658ac:	6a 00                                           	push   0x0
  5658ae:	68 75 23 bf 00                                  	push   0xbf2375
  5658b3:	8d 4e 44                                        	lea    ecx,[esi+0x44]
  5658b6:	c6 05 a4 42 f9 00 01                            	mov    BYTE PTR ds:0xf942a4,0x1
  5658bd:	e8 ae d1 e9 ff                                  	call   0x402a70
  5658c2:	8b 4e 0c                                        	mov    ecx,DWORD PTR [esi+0xc]
  5658c5:	8b 41 04                                        	mov    eax,DWORD PTR [ecx+0x4]
  5658c8:	80 78 31 00                                     	cmp    BYTE PTR [eax+0x31],0x0
  5658cc:	75 27                                           	jne    0x5658f5
  5658ce:	8b ff                                           	mov    edi,edi
  5658d0:	8b 50 0c                                        	mov    edx,DWORD PTR [eax+0xc]
  5658d3:	8b 7d 08                                        	mov    edi,DWORD PTR [ebp+0x8]
  5658d6:	3b fa                                           	cmp    edi,edx
  5658d8:	7f 0a                                           	jg     0x5658e4
  5658da:	7c 0d                                           	jl     0x5658e9
  5658dc:	8b 55 0c                                        	mov    edx,DWORD PTR [ebp+0xc]
  5658df:	39 50 10                                        	cmp    DWORD PTR [eax+0x10],edx
  5658e2:	7d 05                                           	jge    0x5658e9
  5658e4:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  5658e7:	eb 04                                           	jmp    0x5658ed
  5658e9:	8b c8                                           	mov    ecx,eax
  5658eb:	8b 00                                           	mov    eax,DWORD PTR [eax]
  5658ed:	80 78 31 00                                     	cmp    BYTE PTR [eax+0x31],0x0
  5658f1:	74 dd                                           	je     0x5658d0
  5658f3:	eb 03                                           	jmp    0x5658f8
  5658f5:	8b 7d 08                                        	mov    edi,DWORD PTR [ebp+0x8]
  5658f8:	8b 56 0c                                        	mov    edx,DWORD PTR [esi+0xc]
  5658fb:	89 4c 24 18                                     	mov    DWORD PTR [esp+0x18],ecx
  5658ff:	3b ca                                           	cmp    ecx,edx
  565901:	74 17                                           	je     0x56591a
  565903:	8b 41 0c                                        	mov    eax,DWORD PTR [ecx+0xc]
  565906:	3b c7                                           	cmp    eax,edi
  565908:	7f 10                                           	jg     0x56591a
  56590a:	7c 08                                           	jl     0x565914
  56590c:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  56590f:	3b 41 10                                        	cmp    eax,DWORD PTR [ecx+0x10]
  565912:	7c 06                                           	jl     0x56591a
  565914:	8d 44 24 18                                     	lea    eax,[esp+0x18]
  565918:	eb 08                                           	jmp    0x565922
  56591a:	89 54 24 10                                     	mov    DWORD PTR [esp+0x10],edx
  56591e:	8d 44 24 10                                     	lea    eax,[esp+0x10]
  565922:	8b 38                                           	mov    edi,DWORD PTR [eax]
  565924:	3b fa                                           	cmp    edi,edx
  565926:	0f 84 39 01 00 00                               	je     0x565a65
  56592c:	6a 10                                           	push   0x10
  56592e:	68 d0 06 c1 00                                  	push   0xc106d0
  565933:	8d 4c 24 24                                     	lea    ecx,[esp+0x24]
  565937:	c7 44 24 38 0f 00 00 00                         	mov    DWORD PTR [esp+0x38],0xf
  56593f:	c7 44 24 34 00 00 00 00                         	mov    DWORD PTR [esp+0x34],0x0
  565947:	c6 44 24 24 00                                  	mov    BYTE PTR [esp+0x24],0x0
  56594c:	e8 1f d1 e9 ff                                  	call   0x402a70
  565951:	6a ff                                           	push   0xffffffff
  565953:	8d 47 14                                        	lea    eax,[edi+0x14]
  565956:	6a 00                                           	push   0x0
  565958:	bb 05 00 00 00                                  	mov    ebx,0x5
  56595d:	50                                              	push   eax
  56595e:	8d 4c 24 28                                     	lea    ecx,[esp+0x28]
  565962:	89 5c 24 54                                     	mov    DWORD PTR [esp+0x54],ebx
  565966:	e8 65 c5 e9 ff                                  	call   0x401ed0
  56596b:	6a 04                                           	push   0x4
  56596d:	68 e4 06 c1 00                                  	push   0xc106e4
  565972:	8d 4c 24 24                                     	lea    ecx,[esp+0x24]
  565976:	e8 45 c6 e9 ff                                  	call   0x401fc0
  56597b:	83 7c 24 30 10                                  	cmp    DWORD PTR [esp+0x30],0x10
  565980:	8b 7c 24 1c                                     	mov    edi,DWORD PTR [esp+0x1c]
  565984:	73 04                                           	jae    0x56598a
  565986:	8d 7c 24 1c                                     	lea    edi,[esp+0x1c]
  56598a:	f6 05 e8 1e fe 00 01                            	test   BYTE PTR ds:0xfe1ee8,0x1
  565991:	75 22                                           	jne    0x5659b5
  565993:	83 0d e8 1e fe 00 01                            	or     DWORD PTR ds:0xfe1ee8,0x1
  56599a:	c6 44 24 48 06                                  	mov    BYTE PTR [esp+0x48],0x6
  56599f:	e8 6c 6c ff ff                                  	call   0x55c610
  5659a4:	68 90 f2 bc 00                                  	push   0xbcf290
  5659a9:	e8 6c c9 32 00                                  	call   0x89231a
  5659ae:	83 c4 04                                        	add    esp,0x4
  5659b1:	88 5c 24 48                                     	mov    BYTE PTR [esp+0x48],bl
  5659b5:	57                                              	push   edi
  5659b6:	68 ec 1e fe 00                                  	push   0xfe1eec
  5659bb:	e8 e0 7c ff ff                                  	call   0x55d6a0
  5659c0:	bf 10 00 00 00                                  	mov    edi,0x10
  5659c5:	89 46 70                                        	mov    DWORD PTR [esi+0x70],eax
  5659c8:	8b 44 24 1c                                     	mov    eax,DWORD PTR [esp+0x1c]
  5659cc:	39 7c 24 30                                     	cmp    DWORD PTR [esp+0x30],edi
  5659d0:	73 04                                           	jae    0x5659d6
  5659d2:	8d 44 24 1c                                     	lea    eax,[esp+0x1c]
  5659d6:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  5659d8:	50                                              	push   eax
  5659d9:	e8 72 f0 18 00                                  	call   0x6f4a50
  5659de:	e8 6d e8 ec ff                                  	call   0x434250
  5659e3:	f6 05 60 0f fc 00 01                            	test   BYTE PTR ds:0xfc0f60,0x1
  5659ea:	c7 40 14 00 00 00 00                            	mov    DWORD PTR [eax+0x14],0x0
  5659f1:	75 22                                           	jne    0x565a15
  5659f3:	83 0d 60 0f fc 00 01                            	or     DWORD PTR ds:0xfc0f60,0x1
  5659fa:	c6 44 24 48 07                                  	mov    BYTE PTR [esp+0x48],0x7
  5659ff:	e8 3c 75 23 00                                  	call   0x79cf40
  565a04:	68 80 db bc 00                                  	push   0xbcdb80
  565a09:	e8 0c c9 32 00                                  	call   0x89231a
  565a0e:	83 c4 04                                        	add    esp,0x4
  565a11:	88 5c 24 48                                     	mov    BYTE PTR [esp+0x48],bl
  565a15:	6a 02                                           	push   0x2
  565a17:	68 90 0e fc 00                                  	push   0xfc0e90
  565a1c:	e8 9f 7f 23 00                                  	call   0x79d9c0
  565a21:	f6 05 d8 94 fd 00 01                            	test   BYTE PTR ds:0xfd94d8,0x1
  565a28:	75 1e                                           	jne    0x565a48
  565a2a:	83 0d d8 94 fd 00 01                            	or     DWORD PTR ds:0xfd94d8,0x1
  565a31:	c6 44 24 48 08                                  	mov    BYTE PTR [esp+0x48],0x8
  565a36:	e8 f5 f9 24 00                                  	call   0x7b5430
  565a3b:	68 60 e6 bc 00                                  	push   0xbce660
  565a40:	e8 d5 c8 32 00                                  	call   0x89231a
  565a45:	83 c4 04                                        	add    esp,0x4
  565a48:	c7 05 b0 94 fd 00 02 00 00 00                   	mov    DWORD PTR ds:0xfd94b0,0x2
  565a52:	39 7c 24 30                                     	cmp    DWORD PTR [esp+0x30],edi
  565a56:	72 0d                                           	jb     0x565a65
  565a58:	8b 4c 24 1c                                     	mov    ecx,DWORD PTR [esp+0x1c]
  565a5c:	51                                              	push   ecx
  565a5d:	e8 aa b7 32 00                                  	call   0x89120c
  565a62:	83 c4 04                                        	add    esp,0x4
  565a65:	8b 4c 24 40                                     	mov    ecx,DWORD PTR [esp+0x40]
  565a69:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  565a70:	59                                              	pop    ecx
  565a71:	5f                                              	pop    edi
  565a72:	5b                                              	pop    ebx
  565a73:	8b 4c 24 2c                                     	mov    ecx,DWORD PTR [esp+0x2c]
  565a77:	33 cc                                           	xor    ecx,esp
  565a79:	e8 83 b5 32 00                                  	call   0x891001
  565a7e:	8b e5                                           	mov    esp,ebp
  565a80:	5d                                              	pop    ebp
  565a81:	c2 08 00                                        	ret    0x8

; A01 global DoFile produces Lua number 0 or 1

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f48a0 <.text+0x2f38a0>:
  6f48a0:	55                                              	push   ebp
  6f48a1:	8b ec                                           	mov    ebp,esp
  6f48a3:	83 e4 f8                                        	and    esp,0xfffffff8
  6f48a6:	83 ec 1c                                        	sub    esp,0x1c
  6f48a9:	53                                              	push   ebx
  6f48aa:	56                                              	push   esi
  6f48ab:	57                                              	push   edi
  6f48ac:	8b 7d 08                                        	mov    edi,DWORD PTR [ebp+0x8]
  6f48af:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f48b2:	83 ee 10                                        	sub    esi,0x10
  6f48b5:	83 7e 08 04                                     	cmp    DWORD PTR [esi+0x8],0x4
  6f48b9:	74 25                                           	je     0x6f48e0
  6f48bb:	e8 10 6d 00 00                                  	call   0x6fb5d0
  6f48c0:	85 c0                                           	test   eax,eax
  6f48c2:	75 04                                           	jne    0x6f48c8
  6f48c4:	33 f6                                           	xor    esi,esi
  6f48c6:	eb 1d                                           	jmp    0x6f48e5
  6f48c8:	8b 47 10                                        	mov    eax,DWORD PTR [edi+0x10]
  6f48cb:	8b 48 44                                        	mov    ecx,DWORD PTR [eax+0x44]
  6f48ce:	3b 48 40                                        	cmp    ecx,DWORD PTR [eax+0x40]
  6f48d1:	72 07                                           	jb     0x6f48da
  6f48d3:	8b c7                                           	mov    eax,edi
  6f48d5:	e8 c6 6a 00 00                                  	call   0x6fb3a0
  6f48da:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f48dd:	83 ee 10                                        	sub    esi,0x10
  6f48e0:	8b 36                                           	mov    esi,DWORD PTR [esi]
  6f48e2:	83 c6 10                                        	add    esi,0x10
  6f48e5:	68 e0 d1 be 00                                  	push   0xbed1e0
  6f48ea:	56                                              	push   esi
  6f48eb:	c7 44 24 14 01 00 00 00                         	mov    DWORD PTR [esp+0x14],0x1
  6f48f3:	e8 78 fe 01 00                                  	call   0x714770
  6f48f8:	8b f0                                           	mov    esi,eax
  6f48fa:	83 c4 08                                        	add    esp,0x8
  6f48fd:	85 f6                                           	test   esi,esi
  6f48ff:	0f 84 2b 01 00 00                               	je     0x6f4a30
  6f4905:	8b 16                                           	mov    edx,DWORD PTR [esi]
  6f4907:	8b 42 2c                                        	mov    eax,DWORD PTR [edx+0x2c]
  6f490a:	8b ce                                           	mov    ecx,esi
  6f490c:	ff d0                                           	call   eax
  6f490e:	8b d8                                           	mov    ebx,eax
  6f4910:	8d 4b 01                                        	lea    ecx,[ebx+0x1]
  6f4913:	51                                              	push   ecx
  6f4914:	e8 24 93 18 00                                  	call   0x87dc3d
  6f4919:	8b 16                                           	mov    edx,DWORD PTR [esi]
  6f491b:	83 c4 04                                        	add    esp,0x4
  6f491e:	89 44 24 0c                                     	mov    DWORD PTR [esp+0xc],eax
  6f4922:	8b 42 38                                        	mov    eax,DWORD PTR [edx+0x38]
  6f4925:	53                                              	push   ebx
  6f4926:	8b ce                                           	mov    ecx,esi
  6f4928:	ff d0                                           	call   eax
  6f492a:	8b 4c 24 10                                     	mov    ecx,DWORD PTR [esp+0x10]
  6f492e:	50                                              	push   eax
  6f492f:	51                                              	push   ecx
  6f4930:	e8 9b 92 1a 00                                  	call   0x89dbd0
  6f4935:	8b 54 24 18                                     	mov    edx,DWORD PTR [esp+0x18]
  6f4939:	c6 04 13 00                                     	mov    BYTE PTR [ebx+edx*1],0x0
  6f493d:	8b 06                                           	mov    eax,DWORD PTR [esi]
  6f493f:	8b 50 2c                                        	mov    edx,DWORD PTR [eax+0x2c]
  6f4942:	83 c4 0c                                        	add    esp,0xc
  6f4945:	8b ce                                           	mov    ecx,esi
  6f4947:	ff d2                                           	call   edx
  6f4949:	8b 5c 24 0c                                     	mov    ebx,DWORD PTR [esp+0xc]
  6f494d:	83 f8 03                                        	cmp    eax,0x3
  6f4950:	72 42                                           	jb     0x6f4994
  6f4952:	80 3b ef                                        	cmp    BYTE PTR [ebx],0xef
  6f4955:	75 3d                                           	jne    0x6f4994
  6f4957:	80 7b 01 bb                                     	cmp    BYTE PTR [ebx+0x1],0xbb
  6f495b:	75 37                                           	jne    0x6f4994
  6f495d:	80 7b 02 bf                                     	cmp    BYTE PTR [ebx+0x2],0xbf
  6f4961:	75 31                                           	jne    0x6f4994
  6f4963:	83 c0 fd                                        	add    eax,0xfffffffd
  6f4966:	50                                              	push   eax
  6f4967:	8d 43 03                                        	lea    eax,[ebx+0x3]
  6f496a:	50                                              	push   eax
  6f496b:	33 c0                                           	xor    eax,eax
  6f496d:	8b d7                                           	mov    edx,edi
  6f496f:	e8 9c 27 00 00                                  	call   0x6f7110
  6f4974:	83 c4 08                                        	add    esp,0x8
  6f4977:	85 c0                                           	test   eax,eax
  6f4979:	0f 85 97 00 00 00                               	jne    0x6f4a16
  6f497f:	8b 47 08                                        	mov    eax,DWORD PTR [edi+0x8]
  6f4982:	83 e8 10                                        	sub    eax,0x10
  6f4985:	89 44 24 0c                                     	mov    DWORD PTR [esp+0xc],eax
  6f4989:	2b 47 20                                        	sub    eax,DWORD PTR [edi+0x20]
  6f498c:	8d 4c 24 0c                                     	lea    ecx,[esp+0xc]
  6f4990:	50                                              	push   eax
  6f4991:	51                                              	push   ecx
  6f4992:	eb 4f                                           	jmp    0x6f49e3
  6f4994:	89 44 24 10                                     	mov    DWORD PTR [esp+0x10],eax
  6f4998:	33 c0                                           	xor    eax,eax
  6f499a:	8d 54 24 0c                                     	lea    edx,[esp+0xc]
  6f499e:	89 44 24 14                                     	mov    DWORD PTR [esp+0x14],eax
  6f49a2:	89 44 24 18                                     	mov    DWORD PTR [esp+0x18],eax
  6f49a6:	57                                              	push   edi
  6f49a7:	b9 00 27 c4 00                                  	mov    ecx,0xc42700
  6f49ac:	8d 44 24 18                                     	lea    eax,[esp+0x18]
  6f49b0:	89 5c 24 10                                     	mov    DWORD PTR [esp+0x10],ebx
  6f49b4:	89 7c 24 28                                     	mov    DWORD PTR [esp+0x28],edi
  6f49b8:	c7 44 24 20 e0 70 6f 00                         	mov    DWORD PTR [esp+0x20],0x6f70e0
  6f49c0:	89 54 24 24                                     	mov    DWORD PTR [esp+0x24],edx
  6f49c4:	e8 c7 9f 00 00                                  	call   0x6fe990
  6f49c9:	83 c4 04                                        	add    esp,0x4
  6f49cc:	85 c0                                           	test   eax,eax
  6f49ce:	75 46                                           	jne    0x6f4a16
  6f49d0:	8b 47 08                                        	mov    eax,DWORD PTR [edi+0x8]
  6f49d3:	83 e8 10                                        	sub    eax,0x10
  6f49d6:	89 44 24 0c                                     	mov    DWORD PTR [esp+0xc],eax
  6f49da:	2b 47 20                                        	sub    eax,DWORD PTR [edi+0x20]
  6f49dd:	50                                              	push   eax
  6f49de:	8d 44 24 10                                     	lea    eax,[esp+0x10]
  6f49e2:	50                                              	push   eax
  6f49e3:	68 50 5a 6f 00                                  	push   0x6f5a50
  6f49e8:	33 d2                                           	xor    edx,edx
  6f49ea:	8b c7                                           	mov    eax,edi
  6f49ec:	c7 44 24 1c ff ff ff ff                         	mov    DWORD PTR [esp+0x1c],0xffffffff
  6f49f4:	e8 77 9d 00 00                                  	call   0x6fe770
  6f49f9:	8b 4f 14                                        	mov    ecx,DWORD PTR [edi+0x14]
  6f49fc:	8b 57 08                                        	mov    edx,DWORD PTR [edi+0x8]
  6f49ff:	83 c4 0c                                        	add    esp,0xc
  6f4a02:	3b 51 08                                        	cmp    edx,DWORD PTR [ecx+0x8]
  6f4a05:	72 03                                           	jb     0x6f4a0a
  6f4a07:	89 51 08                                        	mov    DWORD PTR [ecx+0x8],edx
  6f4a0a:	c7 44 24 0c 00 00 00 00                         	mov    DWORD PTR [esp+0xc],0x0
  6f4a12:	85 c0                                           	test   eax,eax
  6f4a14:	74 08                                           	je     0x6f4a1e
  6f4a16:	c7 44 24 0c 01 00 00 00                         	mov    DWORD PTR [esp+0xc],0x1
  6f4a1e:	8b 16                                           	mov    edx,DWORD PTR [esi]
  6f4a20:	8b 42 04                                        	mov    eax,DWORD PTR [edx+0x4]
  6f4a23:	8b ce                                           	mov    ecx,esi
  6f4a25:	ff d0                                           	call   eax
  6f4a27:	53                                              	push   ebx
  6f4a28:	e8 10 d3 19 00                                  	call   0x891d3d
  6f4a2d:	83 c4 04                                        	add    esp,0x4
  6f4a30:	8b 47 08                                        	mov    eax,DWORD PTR [edi+0x8]
  6f4a33:	db 44 24 0c                                     	fild   DWORD PTR [esp+0xc]
  6f4a37:	c7 40 08 03 00 00 00                            	mov    DWORD PTR [eax+0x8],0x3
  6f4a3e:	dd 18                                           	fstp   QWORD PTR [eax]
  6f4a40:	83 47 08 10                                     	add    DWORD PTR [edi+0x8],0x10
  6f4a44:	5f                                              	pop    edi
  6f4a45:	5e                                              	pop    esi
  6f4a46:	b8 01 00 00 00                                  	mov    eax,0x1
  6f4a4b:	5b                                              	pop    ebx
  6f4a4c:	8b e5                                           	mov    esp,ebp
  6f4a4e:	5d                                              	pop    ebp
  6f4a4f:	c3                                              	ret

; A02 lb.DoFile C closure returns one Lua result slot

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2200 <.text+0xa1200>:
  4a2200:	55                                              	push   ebp
  4a2201:	8b ec                                           	mov    ebp,esp
  4a2203:	6a ff                                           	push   0xffffffff
  4a2205:	68 c8 83 93 00                                  	push   0x9383c8
  4a220a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4a2210:	50                                              	push   eax
  4a2211:	83 ec 0c                                        	sub    esp,0xc
  4a2214:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4a2219:	33 c5                                           	xor    eax,ebp
  4a221b:	50                                              	push   eax
  4a221c:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4a221f:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4a2225:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  4a2228:	89 45 e8                                        	mov    DWORD PTR [ebp-0x18],eax
  4a222b:	33 c0                                           	xor    eax,eax
  4a222d:	89 45 ec                                        	mov    DWORD PTR [ebp-0x14],eax
  4a2230:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  4a2233:	8d 4d e8                                        	lea    ecx,[ebp-0x18]
  4a2236:	51                                              	push   ecx
  4a2237:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  4a223a:	e8 31 08 00 00                                  	call   0x4a2a70
  4a223f:	83 c4 04                                        	add    esp,0x4
  4a2242:	b8 01 00 00 00                                  	mov    eax,0x1
  4a2247:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4a224a:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4a2251:	59                                              	pop    ecx
  4a2252:	8b e5                                           	mov    esp,ebp
  4a2254:	5d                                              	pop    ebp
  4a2255:	c3                                              	ret

; A03 lb.DoFile marshaller pushes native result as Lua number

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2a70 <.text+0xa1a70>:
  4a2a70:	55                                              	push   ebp
  4a2a71:	8b ec                                           	mov    ebp,esp
  4a2a73:	51                                              	push   ecx
  4a2a74:	a1 a0 17 fe 00                                  	mov    eax,ds:0xfe17a0
  4a2a79:	8b 0d 78 17 fe 00                               	mov    ecx,DWORD PTR ds:0xfe1778
  4a2a7f:	53                                              	push   ebx
  4a2a80:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  4a2a83:	56                                              	push   esi
  4a2a84:	57                                              	push   edi
  4a2a85:	8b 3b                                           	mov    edi,DWORD PTR [ebx]
  4a2a87:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  4a2a8a:	83 ee 10                                        	sub    esi,0x10
  4a2a8d:	83 7e 08 04                                     	cmp    DWORD PTR [esi+0x8],0x4
  4a2a91:	89 45 08                                        	mov    DWORD PTR [ebp+0x8],eax
  4a2a94:	89 4d fc                                        	mov    DWORD PTR [ebp-0x4],ecx
  4a2a97:	74 25                                           	je     0x4a2abe
  4a2a99:	e8 32 8b 25 00                                  	call   0x6fb5d0
  4a2a9e:	85 c0                                           	test   eax,eax
  4a2aa0:	75 04                                           	jne    0x4a2aa6
  4a2aa2:	33 f6                                           	xor    esi,esi
  4a2aa4:	eb 1d                                           	jmp    0x4a2ac3
  4a2aa6:	8b 47 10                                        	mov    eax,DWORD PTR [edi+0x10]
  4a2aa9:	8b 50 44                                        	mov    edx,DWORD PTR [eax+0x44]
  4a2aac:	3b 50 40                                        	cmp    edx,DWORD PTR [eax+0x40]
  4a2aaf:	72 07                                           	jb     0x4a2ab8
  4a2ab1:	8b c7                                           	mov    eax,edi
  4a2ab3:	e8 e8 88 25 00                                  	call   0x6fb3a0
  4a2ab8:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  4a2abb:	83 ee 10                                        	sub    esi,0x10
  4a2abe:	8b 36                                           	mov    esi,DWORD PTR [esi]
  4a2ac0:	83 c6 10                                        	add    esi,0x10
  4a2ac3:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  4a2ac6:	56                                              	push   esi
  4a2ac7:	ff 55 08                                        	call   DWORD PTR [ebp+0x8]
  4a2aca:	89 45 08                                        	mov    DWORD PTR [ebp+0x8],eax
  4a2acd:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  4a2acf:	db 45 08                                        	fild   DWORD PTR [ebp+0x8]
  4a2ad2:	8b 48 08                                        	mov    ecx,DWORD PTR [eax+0x8]
  4a2ad5:	5f                                              	pop    edi
  4a2ad6:	dd 19                                           	fstp   QWORD PTR [ecx]
  4a2ad8:	c7 41 08 03 00 00 00                            	mov    DWORD PTR [ecx+0x8],0x3
  4a2adf:	83 40 08 10                                     	add    DWORD PTR [eax+0x8],0x10
  4a2ae3:	5e                                              	pop    esi
  4a2ae4:	b8 01 00 00 00                                  	mov    eax,0x1
  4a2ae9:	5b                                              	pop    ebx
  4a2aea:	8b e5                                           	mov    esp,ebp
  4a2aec:	5d                                              	pop    ebp
  4a2aed:	c3                                              	ret

; A04 lb.DoFile open failure return zero and global main wrapper use

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1230 <.text+0xa0230>:
  4a1230:	55                                              	push   ebp
  4a1231:	8b ec                                           	mov    ebp,esp
  4a1233:	6a ff                                           	push   0xffffffff
  4a1235:	68 7e a9 93 00                                  	push   0x93a97e
  4a123a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4a1240:	50                                              	push   eax
  4a1241:	53                                              	push   ebx
  4a1242:	56                                              	push   esi
  4a1243:	57                                              	push   edi
  4a1244:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4a1249:	33 c5                                           	xor    eax,ebp
  4a124b:	50                                              	push   eax
  4a124c:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4a124f:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4a1255:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  4a1258:	68 e0 d1 be 00                                  	push   0xbed1e0
  4a125d:	50                                              	push   eax
  4a125e:	e8 0d 35 27 00                                  	call   0x714770
  4a1263:	8b f0                                           	mov    esi,eax
  4a1265:	83 c4 08                                        	add    esp,0x8
  4a1268:	85 f6                                           	test   esi,esi
  4a126a:	0f 84 a6 00 00 00                               	je     0x4a1316
  4a1270:	8b 16                                           	mov    edx,DWORD PTR [esi]
  4a1272:	8b 42 2c                                        	mov    eax,DWORD PTR [edx+0x2c]
  4a1275:	8b ce                                           	mov    ecx,esi
  4a1277:	ff d0                                           	call   eax
  4a1279:	8b f8                                           	mov    edi,eax
  4a127b:	8d 4f 01                                        	lea    ecx,[edi+0x1]
  4a127e:	51                                              	push   ecx
  4a127f:	e8 b9 c9 3d 00                                  	call   0x87dc3d
  4a1284:	8b 16                                           	mov    edx,DWORD PTR [esi]
  4a1286:	83 c4 04                                        	add    esp,0x4
  4a1289:	8b d8                                           	mov    ebx,eax
  4a128b:	8b 42 38                                        	mov    eax,DWORD PTR [edx+0x38]
  4a128e:	57                                              	push   edi
  4a128f:	8b ce                                           	mov    ecx,esi
  4a1291:	ff d0                                           	call   eax
  4a1293:	50                                              	push   eax
  4a1294:	53                                              	push   ebx
  4a1295:	e8 36 c9 3f 00                                  	call   0x89dbd0
  4a129a:	c6 04 1f 00                                     	mov    BYTE PTR [edi+ebx*1],0x0
  4a129e:	8b 16                                           	mov    edx,DWORD PTR [esi]
  4a12a0:	8b 42 2c                                        	mov    eax,DWORD PTR [edx+0x2c]
  4a12a3:	83 c4 0c                                        	add    esp,0xc
  4a12a6:	8b ce                                           	mov    ecx,esi
  4a12a8:	ff d0                                           	call   eax
  4a12aa:	8b f8                                           	mov    edi,eax
  4a12ac:	b8 01 00 00 00                                  	mov    eax,0x1
  4a12b1:	84 05 d4 f3 fd 00                               	test   BYTE PTR ds:0xfdf3d4,al
  4a12b7:	75 26                                           	jne    0x4a12df
  4a12b9:	09 05 d4 f3 fd 00                               	or     DWORD PTR ds:0xfdf3d4,eax
  4a12bf:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  4a12c6:	e8 b5 30 25 00                                  	call   0x6f4380
  4a12cb:	68 d0 e6 bc 00                                  	push   0xbce6d0
  4a12d0:	e8 45 10 3f 00                                  	call   0x89231a
  4a12d5:	83 c4 04                                        	add    esp,0x4
  4a12d8:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a12df:	8b cf                                           	mov    ecx,edi
  4a12e1:	53                                              	push   ebx
  4a12e2:	bf c8 f3 fd 00                                  	mov    edi,0xfdf3c8
  4a12e7:	e8 34 39 25 00                                  	call   0x6f4c20
  4a12ec:	8b 16                                           	mov    edx,DWORD PTR [esi]
  4a12ee:	8b f8                                           	mov    edi,eax
  4a12f0:	8b 42 04                                        	mov    eax,DWORD PTR [edx+0x4]
  4a12f3:	8b ce                                           	mov    ecx,esi
  4a12f5:	ff d0                                           	call   eax
  4a12f7:	53                                              	push   ebx
  4a12f8:	e8 40 0a 3f 00                                  	call   0x891d3d
  4a12fd:	83 c4 04                                        	add    esp,0x4
  4a1300:	8b c7                                           	mov    eax,edi
  4a1302:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4a1305:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4a130c:	59                                              	pop    ecx
  4a130d:	5f                                              	pop    edi
  4a130e:	5e                                              	pop    esi
  4a130f:	5b                                              	pop    ebx
  4a1310:	8b e5                                           	mov    esp,ebp
  4a1312:	5d                                              	pop    ebp
  4a1313:	c2 04 00                                        	ret    0x4
  4a1316:	33 c0                                           	xor    eax,eax
  4a1318:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  4a131b:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  4a1322:	59                                              	pop    ecx
  4a1323:	5f                                              	pop    edi
  4a1324:	5e                                              	pop    esi
  4a1325:	5b                                              	pop    ebx
  4a1326:	8b e5                                           	mov    esp,ebp
  4a1328:	5d                                              	pop    ebp
  4a1329:	c2 04 00                                        	ret    0x4

; A05 buffer loader parse and execute status

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4c20 <.text+0x2f3c20>:
  6f4c20:	55                                              	push   ebp
  6f4c21:	8b ec                                           	mov    ebp,esp
  6f4c23:	83 e4 f8                                        	and    esp,0xfffffff8
  6f4c26:	83 ec 20                                        	sub    esp,0x20
  6f4c29:	8b 07                                           	mov    eax,DWORD PTR [edi]
  6f4c2b:	53                                              	push   ebx
  6f4c2c:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  6f4c2f:	89 4c 24 0c                                     	mov    DWORD PTR [esp+0xc],ecx
  6f4c33:	33 c9                                           	xor    ecx,ecx
  6f4c35:	56                                              	push   esi
  6f4c36:	89 44 24 24                                     	mov    DWORD PTR [esp+0x24],eax
  6f4c3a:	8d 54 24 0c                                     	lea    edx,[esp+0xc]
  6f4c3e:	89 4c 24 14                                     	mov    DWORD PTR [esp+0x14],ecx
  6f4c42:	89 4c 24 18                                     	mov    DWORD PTR [esp+0x18],ecx
  6f4c46:	50                                              	push   eax
  6f4c47:	b9 00 27 c4 00                                  	mov    ecx,0xc42700
  6f4c4c:	8d 44 24 18                                     	lea    eax,[esp+0x18]
  6f4c50:	89 5c 24 10                                     	mov    DWORD PTR [esp+0x10],ebx
  6f4c54:	c7 44 24 20 e0 70 6f 00                         	mov    DWORD PTR [esp+0x20],0x6f70e0
  6f4c5c:	89 54 24 24                                     	mov    DWORD PTR [esp+0x24],edx
  6f4c60:	e8 2b 9d 00 00                                  	call   0x6fe990
  6f4c65:	83 c4 04                                        	add    esp,0x4
  6f4c68:	85 c0                                           	test   eax,eax
  6f4c6a:	75 48                                           	jne    0x6f4cb4
  6f4c6c:	8b 37                                           	mov    esi,DWORD PTR [edi]
  6f4c6e:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f4c71:	83 e8 10                                        	sub    eax,0x10
  6f4c74:	89 44 24 0c                                     	mov    DWORD PTR [esp+0xc],eax
  6f4c78:	2b 46 20                                        	sub    eax,DWORD PTR [esi+0x20]
  6f4c7b:	33 d2                                           	xor    edx,edx
  6f4c7d:	50                                              	push   eax
  6f4c7e:	8d 44 24 10                                     	lea    eax,[esp+0x10]
  6f4c82:	50                                              	push   eax
  6f4c83:	68 50 5a 6f 00                                  	push   0x6f5a50
  6f4c88:	8b c6                                           	mov    eax,esi
  6f4c8a:	c7 44 24 1c ff ff ff ff                         	mov    DWORD PTR [esp+0x1c],0xffffffff
  6f4c92:	e8 d9 9a 00 00                                  	call   0x6fe770
  6f4c97:	8b 4e 14                                        	mov    ecx,DWORD PTR [esi+0x14]
  6f4c9a:	8b 76 08                                        	mov    esi,DWORD PTR [esi+0x8]
  6f4c9d:	83 c4 0c                                        	add    esp,0xc
  6f4ca0:	3b 71 08                                        	cmp    esi,DWORD PTR [ecx+0x8]
  6f4ca3:	72 03                                           	jb     0x6f4ca8
  6f4ca5:	89 71 08                                        	mov    DWORD PTR [ecx+0x8],esi
  6f4ca8:	85 c0                                           	test   eax,eax
  6f4caa:	75 08                                           	jne    0x6f4cb4
  6f4cac:	5e                                              	pop    esi
  6f4cad:	5b                                              	pop    ebx
  6f4cae:	8b e5                                           	mov    esp,ebp
  6f4cb0:	5d                                              	pop    ebp
  6f4cb1:	c2 04 00                                        	ret    0x4
  6f4cb4:	53                                              	push   ebx
  6f4cb5:	57                                              	push   edi
  6f4cb6:	be 01 00 00 00                                  	mov    esi,0x1
  6f4cbb:	e8 e0 fa ff ff                                  	call   0x6f47a0
  6f4cc0:	8b c6                                           	mov    eax,esi
  6f4cc2:	5e                                              	pop    esi
  6f4cc3:	5b                                              	pop    ebx
  6f4cc4:	8b e5                                           	mov    esp,ebp
  6f4cc6:	5d                                              	pop    ebp
  6f4cc7:	c2 04 00                                        	ret    0x4

; A06 normal security-cookie return preserves EAX

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00891001 <.text+0x490001>:
  891001:	3b 0d 20 1f d6 00                               	cmp    ecx,DWORD PTR ds:0xd61f20
  891007:	75 02                                           	jne    0x89100b
  891009:	f3 c3                                           	repz ret
  89100b:	e9 cc f4 00 00                                  	jmp    0x8a04dc
