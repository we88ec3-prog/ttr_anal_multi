
# caller_0x4a8a46

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a89d9 <.text+0xa79d9>:
  4a89d9:	50                                              	push   eax
  4a89da:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4a89dd:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4a89e3:	8d 7e 14                                        	lea    edi,[esi+0x14]
  4a89e6:	c7 05 a0 a7 fb 00 00 00 00 00                   	mov    DWORD PTR ds:0xfba7a0,0x0
  4a89f0:	e8 2b 8a 3a 00                                  	call   0x851420
  4a89f5:	f6 05 54 73 fb 00 01                            	test   BYTE PTR ds:0xfb7354,0x1
  4a89fc:	75 27                                           	jne    0x4a8a25
  4a89fe:	83 0d 54 73 fb 00 01                            	or     DWORD PTR ds:0xfb7354,0x1
  4a8a05:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  4a8a0c:	e8 bf a9 0a 00                                  	call   0x5533d0
  4a8a11:	68 00 d1 bc 00                                  	push   0xbcd100
  4a8a16:	e8 ff 98 3e 00                                  	call   0x89231a
  4a8a1b:	83 c4 04                                        	add    esp,0x4
  4a8a1e:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a8a25:	c7 05 b4 73 fb 00 01 00 00 00                   	mov    DWORD PTR ds:0xfb73b4,0x1
  4a8a2f:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  4a8a31:	68 7c 68 c0 00                                  	push   0xc0687c
  4a8a36:	e8 15 c0 24 00                                  	call   0x6f4a50
  4a8a3b:	8b 06                                           	mov    eax,DWORD PTR [esi]
  4a8a3d:	6a 00                                           	push   0x0
  4a8a3f:	6a 00                                           	push   0x0
  4a8a41:	68 94 68 c0 00                                  	push   0xc06894
  4a8a46:	e8 85 c3 24 00                                  	call   0x6f4dd0

# caller_0x4a8b74

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a8b26 <.text+0xa7b26>:
  4a8b26:	68 10 cf bc 00                                  	push   0xbccf10
  4a8b2b:	e8 ea 97 3e 00                                  	call   0x89231a
  4a8b30:	83 c4 04                                        	add    esp,0x4
  4a8b33:	83 3d 98 a7 fb 00 00                            	cmp    DWORD PTR ds:0xfba798,0x0
  4a8b3a:	b8 0c 00 00 00                                  	mov    eax,0xc
  4a8b3f:	66 89 45 ec                                     	mov    WORD PTR [ebp-0x14],ax
  4a8b43:	89 5d ee                                        	mov    DWORD PTR [ebp-0x12],ebx
  4a8b46:	75 15                                           	jne    0x4a8b5d
  4a8b48:	8b 0d 54 a8 fb 00                               	mov    ecx,DWORD PTR ds:0xfba854
  4a8b4e:	8b 11                                           	mov    edx,DWORD PTR [ecx]
  4a8b50:	8b 52 10                                        	mov    edx,DWORD PTR [edx+0x10]
  4a8b53:	6a 06                                           	push   0x6
  4a8b55:	8d 45 ec                                        	lea    eax,[ebp-0x14]
  4a8b58:	50                                              	push   eax
  4a8b59:	6a 00                                           	push   0x0
  4a8b5b:	ff d2                                           	call   edx
  4a8b5d:	8b 0e                                           	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00                                  	push   0xc0687c
  4a8b64:	e8 e7 be 24 00                                  	call   0x6f4a50
  4a8b69:	8b 06                                           	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                                           	push   0x0
  4a8b6d:	6a 00                                           	push   0x0
  4a8b6f:	68 a8 68 c0 00                                  	push   0xc068a8
  4a8b74:	e8 57 c2 24 00                                  	call   0x6f4dd0

# caller_0x5615d8

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561575 <.text+0x160575>:
  561575:	c7 44 24 18 ff ff ff ff                         	mov    DWORD PTR [esp+0x18],0xffffffff
  56157d:	be 44 27 fe 00                                  	mov    esi,0xfe2744
  561582:	e8 09 d2 ff ff                                  	call   0x55e790
  561587:	83 7f 28 00                                     	cmp    DWORD PTR [edi+0x28],0x0
  56158b:	74 53                                           	je     0x5615e0
  56158d:	f6 05 2c b2 fa 00 01                            	test   BYTE PTR ds:0xfab22c,0x1
  561594:	be 01 00 00 00                                  	mov    esi,0x1
  561599:	75 24                                           	jne    0x5615bf
  56159b:	09 35 2c b2 fa 00                               	or     DWORD PTR ds:0xfab22c,esi
  5615a1:	89 74 24 18                                     	mov    DWORD PTR [esp+0x18],esi
  5615a5:	e8 e6 d6 f7 ff                                  	call   0x4dec90
  5615aa:	68 30 ce bc 00                                  	push   0xbcce30
  5615af:	e8 66 0d 33 00                                  	call   0x89231a
  5615b4:	83 c4 04                                        	add    esp,0x4
  5615b7:	c7 44 24 18 ff ff ff ff                         	mov    DWORD PTR [esp+0x18],0xffffffff
  5615bf:	a1 a4 a7 fb 00                                  	mov    eax,ds:0xfba7a4
  5615c4:	89 70 58                                        	mov    DWORD PTR [eax+0x58],esi
  5615c7:	83 7f 2c 00                                     	cmp    DWORD PTR [edi+0x2c],0x0
  5615cb:	75 13                                           	jne    0x5615e0
  5615cd:	8b 07                                           	mov    eax,DWORD PTR [edi]
  5615cf:	6a 00                                           	push   0x0
  5615d1:	6a 00                                           	push   0x0
  5615d3:	68 a0 06 c1 00                                  	push   0xc106a0
  5615d8:	e8 f3 37 19 00                                  	call   0x6f4dd0

# caller_0x673034

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00672fd1 <.text+0x271fd1>:
  672fd1:	c7 44 24 68 ff ff ff ff                         	mov    DWORD PTR [esp+0x68],0xffffffff
  672fd9:	8b 35 c8 f3 fd 00                               	mov    esi,DWORD PTR ds:0xfdf3c8
  672fdf:	bf 1c 59 c3 00                                  	mov    edi,0xc3591c
  672fe4:	b8 ee d8 ff ff                                  	mov    eax,0xffffd8ee
  672fe9:	e8 92 26 08 00                                  	call   0x6f5680
  672fee:	8b 15 c8 f3 fd 00                               	mov    edx,DWORD PTR ds:0xfdf3c8
  672ff4:	8b 42 08                                        	mov    eax,DWORD PTR [edx+0x8]
  672ff7:	83 e8 10                                        	sub    eax,0x10
  672ffa:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  672fff:	74 06                                           	je     0x673007
  673001:	83 78 08 05                                     	cmp    DWORD PTR [eax+0x8],0x5
  673005:	74 17                                           	je     0x67301e
  673007:	68 1c 59 c3 00                                  	push   0xc3591c
  67300c:	68 c4 26 c4 00                                  	push   0xc426c4
  673011:	e8 a7 00 22 00                                  	call   0x8930bd
  673016:	83 c4 08                                        	add    esp,0x8
  673019:	e9 33 01 00 00                                  	jmp    0x673151
  67301e:	8b 44 24 18                                     	mov    eax,DWORD PTR [esp+0x18]
  673022:	50                                              	push   eax
  673023:	68 dc d6 c0 00                                  	push   0xc0d6dc
  673028:	6a 01                                           	push   0x1
  67302a:	68 2c 59 c3 00                                  	push   0xc3592c
  67302f:	b8 c8 f3 fd 00                                  	mov    eax,0xfdf3c8
  673034:	e8 07 1f 08 00                                  	call   0x6f4f40

# caller_0x6bf7e5

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006bf788 <.text+0x2be788>:
  6bf788:	8b 35 c8 f3 fd 00                               	mov    esi,DWORD PTR ds:0xfdf3c8
  6bf78e:	bf 1c 59 c3 00                                  	mov    edi,0xc3591c
  6bf793:	b8 ee d8 ff ff                                  	mov    eax,0xffffd8ee
  6bf798:	e8 e3 5e 03 00                                  	call   0x6f5680
  6bf79d:	8b 0d c8 f3 fd 00                               	mov    ecx,DWORD PTR ds:0xfdf3c8
  6bf7a3:	8b 41 08                                        	mov    eax,DWORD PTR [ecx+0x8]
  6bf7a6:	83 e8 10                                        	sub    eax,0x10
  6bf7a9:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  6bf7ae:	74 08                                           	je     0x6bf7b8
  6bf7b0:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  6bf7b3:	83 f8 05                                        	cmp    eax,0x5
  6bf7b6:	74 17                                           	je     0x6bf7cf
  6bf7b8:	68 1c 59 c3 00                                  	push   0xc3591c
  6bf7bd:	68 c4 26 c4 00                                  	push   0xc426c4
  6bf7c2:	e8 f6 38 1d 00                                  	call   0x8930bd
  6bf7c7:	83 c4 08                                        	add    esp,0x8
  6bf7ca:	e9 ef 00 00 00                                  	jmp    0x6bf8be
  6bf7cf:	8b 54 24 20                                     	mov    edx,DWORD PTR [esp+0x20]
  6bf7d3:	52                                              	push   edx
  6bf7d4:	68 dc d6 c0 00                                  	push   0xc0d6dc
  6bf7d9:	6a 01                                           	push   0x1
  6bf7db:	68 2c 59 c3 00                                  	push   0xc3592c
  6bf7e0:	b8 c8 f3 fd 00                                  	mov    eax,0xfdf3c8
  6bf7e5:	e8 56 57 03 00                                  	call   0x6f4f40

# caller_0x4ad0f3

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ad0b8 <.text+0xac0b8>:
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

# caller_0x47b71c

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0047b6c8 <.text+0x7a6c8>:
  47b6c8:	56                                              	push   esi
  47b6c9:	57                                              	push   edi
  47b6ca:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  47b6cf:	33 c4                                           	xor    eax,esp
  47b6d1:	50                                              	push   eax
  47b6d2:	8d 44 24 20                                     	lea    eax,[esp+0x20]
  47b6d6:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  47b6dc:	f6 05 80 0f fc 00 01                            	test   BYTE PTR ds:0xfc0f80,0x1
  47b6e3:	75 29                                           	jne    0x47b70e
  47b6e5:	83 0d 80 0f fc 00 01                            	or     DWORD PTR ds:0xfc0f80,0x1
  47b6ec:	33 ff                                           	xor    edi,edi
  47b6ee:	89 7c 24 28                                     	mov    DWORD PTR [esp+0x28],edi
  47b6f2:	e8 b9 f7 ff ff                                  	call   0x47aeb0
  47b6f7:	68 70 db bc 00                                  	push   0xbcdb70
  47b6fc:	e8 19 6c 41 00                                  	call   0x89231a
  47b701:	83 c4 04                                        	add    esp,0x4
  47b704:	c7 44 24 28 ff ff ff ff                         	mov    DWORD PTR [esp+0x28],0xffffffff
  47b70c:	eb 02                                           	jmp    0x47b710
  47b70e:	33 ff                                           	xor    edi,edi
  47b710:	a1 84 0f fc 00                                  	mov    eax,ds:0xfc0f84
  47b715:	68 bc 68 c0 00                                  	push   0xc068bc
  47b71a:	57                                              	push   edi
  47b71b:	50                                              	push   eax
  47b71c:	e8 7f 19 03 00                                  	call   0x4ad0a0

# caller_0x4a8ba6

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

# caller_0x4c1a1f

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c19ba <.text+0xc09ba>:
  4c19ba:	75 20                                           	jne    0x4c19dc
  4c19bc:	09 3d 80 0f fc 00                               	or     DWORD PTR ds:0xfc0f80,edi
  4c19c2:	89 7c 24 40                                     	mov    DWORD PTR [esp+0x40],edi
  4c19c6:	e8 e5 94 fb ff                                  	call   0x47aeb0
  4c19cb:	68 70 db bc 00                                  	push   0xbcdb70
  4c19d0:	e8 45 09 3d 00                                  	call   0x89231a
  4c19d5:	83 c4 04                                        	add    esp,0x4
  4c19d8:	89 5c 24 40                                     	mov    DWORD PTR [esp+0x40],ebx
  4c19dc:	83 3d b8 0f fc 00 00                            	cmp    DWORD PTR ds:0xfc0fb8,0x0
  4c19e3:	75 54                                           	jne    0x4c1a39
  4c19e5:	f6 05 80 0f fc 00 01                            	test   BYTE PTR ds:0xfc0f80,0x1
  4c19ec:	75 24                                           	jne    0x4c1a12
  4c19ee:	09 3d 80 0f fc 00                               	or     DWORD PTR ds:0xfc0f80,edi
  4c19f4:	c7 44 24 40 02 00 00 00                         	mov    DWORD PTR [esp+0x40],0x2
  4c19fc:	e8 af 94 fb ff                                  	call   0x47aeb0
  4c1a01:	68 70 db bc 00                                  	push   0xbcdb70
  4c1a06:	e8 0f 09 3d 00                                  	call   0x89231a
  4c1a0b:	83 c4 04                                        	add    esp,0x4
  4c1a0e:	89 5c 24 40                                     	mov    DWORD PTR [esp+0x40],ebx
  4c1a12:	a1 84 0f fc 00                                  	mov    eax,ds:0xfc0f84
  4c1a17:	68 bc 68 c0 00                                  	push   0xc068bc
  4c1a1c:	6a 00                                           	push   0x0
  4c1a1e:	50                                              	push   eax
  4c1a1f:	e8 7c b6 fe ff                                  	call   0x4ad0a0

# caller_0x4c20b6

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c2065 <.text+0xc1065>:
  4c2065:	56                                              	push   esi
  4c2066:	57                                              	push   edi
  4c2067:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4c206c:	33 c5                                           	xor    eax,ebp
  4c206e:	50                                              	push   eax
  4c206f:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4c2072:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4c2078:	f6 05 80 0f fc 00 01                            	test   BYTE PTR ds:0xfc0f80,0x1
  4c207f:	75 27                                           	jne    0x4c20a8
  4c2081:	83 0d 80 0f fc 00 01                            	or     DWORD PTR ds:0xfc0f80,0x1
  4c2088:	33 ff                                           	xor    edi,edi
  4c208a:	89 7d fc                                        	mov    DWORD PTR [ebp-0x4],edi
  4c208d:	e8 1e 8e fb ff                                  	call   0x47aeb0
  4c2092:	68 70 db bc 00                                  	push   0xbcdb70
  4c2097:	e8 7e 02 3d 00                                  	call   0x89231a
  4c209c:	83 c4 04                                        	add    esp,0x4
  4c209f:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c20a6:	eb 02                                           	jmp    0x4c20aa
  4c20a8:	33 ff                                           	xor    edi,edi
  4c20aa:	a1 84 0f fc 00                                  	mov    eax,ds:0xfc0f84
  4c20af:	68 bc 68 c0 00                                  	push   0xc068bc
  4c20b4:	57                                              	push   edi
  4c20b5:	50                                              	push   eax
  4c20b6:	e8 e5 af fe ff                                  	call   0x4ad0a0

# caller_0x4c4dc2

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c4d63 <.text+0xc3d63>:
  4c4d63:	6a ff                                           	push   0xffffffff
  4c4d65:	68 ce 3e 93 00                                  	push   0x933ece
  4c4d6a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  4c4d70:	50                                              	push   eax
  4c4d71:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  4c4d76:	33 c5                                           	xor    eax,ebp
  4c4d78:	50                                              	push   eax
  4c4d79:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  4c4d7c:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  4c4d82:	b8 01 00 00 00                                  	mov    eax,0x1
  4c4d87:	84 05 80 0f fc 00                               	test   BYTE PTR ds:0xfc0f80,al
  4c4d8d:	75 26                                           	jne    0x4c4db5
  4c4d8f:	09 05 80 0f fc 00                               	or     DWORD PTR ds:0xfc0f80,eax
  4c4d95:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  4c4d9c:	e8 0f 61 fb ff                                  	call   0x47aeb0
  4c4da1:	68 70 db bc 00                                  	push   0xbcdb70
  4c4da6:	e8 6f d5 3c 00                                  	call   0x89231a
  4c4dab:	83 c4 04                                        	add    esp,0x4
  4c4dae:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c4db5:	a1 84 0f fc 00                                  	mov    eax,ds:0xfc0f84
  4c4dba:	68 bc 68 c0 00                                  	push   0xc068bc
  4c4dbf:	6a 00                                           	push   0x0
  4c4dc1:	50                                              	push   eax
  4c4dc2:	e8 d9 82 fe ff                                  	call   0x4ad0a0

# caller_0x561e42

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561de0 <.text+0x160de0>:
  561de0:	80 bf 89 00 00 00 00                            	cmp    BYTE PTR [edi+0x89],0x0
  561de7:	0f 84 73 01 00 00                               	je     0x561f60
  561ded:	39 77 28                                        	cmp    DWORD PTR [edi+0x28],esi
  561df0:	0f 84 aa 00 00 00                               	je     0x561ea0
  561df6:	89 77 28                                        	mov    DWORD PTR [edi+0x28],esi
  561df9:	e8 52 24 ed ff                                  	call   0x434250
  561dfe:	bb 01 00 00 00                                  	mov    ebx,0x1
  561e03:	89 58 14                                        	mov    DWORD PTR [eax+0x14],ebx
  561e06:	84 1d d4 f3 fd 00                               	test   BYTE PTR ds:0xfdf3d4,bl
  561e0c:	75 25                                           	jne    0x561e33
  561e0e:	09 1d d4 f3 fd 00                               	or     DWORD PTR ds:0xfdf3d4,ebx
  561e14:	89 74 24 28                                     	mov    DWORD PTR [esp+0x28],esi
  561e18:	e8 63 25 19 00                                  	call   0x6f4380
  561e1d:	68 d0 e6 bc 00                                  	push   0xbce6d0
  561e22:	e8 f3 04 33 00                                  	call   0x89231a
  561e27:	83 c4 04                                        	add    esp,0x4
  561e2a:	83 ce ff                                        	or     esi,0xffffffff
  561e2d:	89 74 24 28                                     	mov    DWORD PTR [esp+0x28],esi
  561e31:	eb 03                                           	jmp    0x561e36
  561e33:	83 ce ff                                        	or     esi,0xffffffff
  561e36:	68 ec 06 c1 00                                  	push   0xc106ec
  561e3b:	6a 00                                           	push   0x0
  561e3d:	68 c8 f3 fd 00                                  	push   0xfdf3c8
  561e42:	e8 59 b2 f4 ff                                  	call   0x4ad0a0

# caller_0x561f8a

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561f47 <.text+0x160f47>:
  561f47:	89 5f 38                                        	mov    DWORD PTR [edi+0x38],ebx
  561f4a:	89 5f 3c                                        	mov    DWORD PTR [edi+0x3c],ebx
  561f4d:	8b 4c 24 20                                     	mov    ecx,DWORD PTR [esp+0x20]
  561f51:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  561f58:	59                                              	pop    ecx
  561f59:	5f                                              	pop    edi
  561f5a:	5e                                              	pop    esi
  561f5b:	5b                                              	pop    ebx
  561f5c:	8b e5                                           	mov    esp,ebp
  561f5e:	5d                                              	pop    ebp
  561f5f:	c3                                              	ret
  561f60:	39 77 28                                        	cmp    DWORD PTR [edi+0x28],esi
  561f63:	0f 84 28 01 00 00                               	je     0x562091
  561f69:	89 77 28                                        	mov    DWORD PTR [edi+0x28],esi
  561f6c:	e8 df 22 ed ff                                  	call   0x434250
  561f71:	bb 01 00 00 00                                  	mov    ebx,0x1
  561f76:	89 58 14                                        	mov    DWORD PTR [eax+0x14],ebx
  561f79:	39 77 38                                        	cmp    DWORD PTR [edi+0x38],esi
  561f7c:	74 39                                           	je     0x561fb7
  561f7e:	68 44 03 c1 00                                  	push   0xc10344
  561f83:	53                                              	push   ebx
  561f84:	e8 a7 92 f3 ff                                  	call   0x49b230
  561f89:	50                                              	push   eax
  561f8a:	e8 11 b1 f4 ff                                  	call   0x4ad0a0

# caller_0x56202d

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561fce <.text+0x160fce>:
  561fce:	57                                              	push   edi
  561fcf:	e8 cc 03 00 00                                  	call   0x5623a0
  561fd4:	e8 a7 26 eb ff                                  	call   0x414680
  561fd9:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  561fdb:	8b 4f 38                                        	mov    ecx,DWORD PTR [edi+0x38]
  561fde:	50                                              	push   eax
  561fdf:	51                                              	push   ecx
  561fe0:	e8 bb 19 f4 ff                                  	call   0x4a39a0
  561fe5:	e8 c6 00 00 00                                  	call   0x5620b0
  561fea:	bb 01 00 00 00                                  	mov    ebx,0x1
  561fef:	33 f6                                           	xor    esi,esi
  561ff1:	f6 05 d4 f3 fd 00 01                            	test   BYTE PTR ds:0xfdf3d4,0x1
  561ff8:	75 28                                           	jne    0x562022
  561ffa:	09 1d d4 f3 fd 00                               	or     DWORD PTR ds:0xfdf3d4,ebx
  562000:	c7 44 24 28 04 00 00 00                         	mov    DWORD PTR [esp+0x28],0x4
  562008:	e8 73 23 19 00                                  	call   0x6f4380
  56200d:	68 d0 e6 bc 00                                  	push   0xbce6d0
  562012:	e8 03 03 33 00                                  	call   0x89231a
  562017:	83 c4 04                                        	add    esp,0x4
  56201a:	c7 44 24 28 ff ff ff ff                         	mov    DWORD PTR [esp+0x28],0xffffffff
  562022:	68 ec 06 c1 00                                  	push   0xc106ec
  562027:	56                                              	push   esi
  562028:	68 c8 f3 fd 00                                  	push   0xfdf3c8
  56202d:	e8 6e b0 f4 ff                                  	call   0x4ad0a0

# caller_0x5b9742

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005b96e3 <.text+0x1b86e3>:
  5b96e3:	6a ff                                           	push   0xffffffff
  5b96e5:	68 6c 73 94 00                                  	push   0x94736c
  5b96ea:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  5b96f0:	50                                              	push   eax
  5b96f1:	53                                              	push   ebx
  5b96f2:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  5b96f7:	33 c5                                           	xor    eax,ebp
  5b96f9:	50                                              	push   eax
  5b96fa:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  5b96fd:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  5b9703:	bb 01 00 00 00                                  	mov    ebx,0x1
  5b9708:	84 1d d4 f3 fd 00                               	test   BYTE PTR ds:0xfdf3d4,bl
  5b970e:	75 26                                           	jne    0x5b9736
  5b9710:	09 1d d4 f3 fd 00                               	or     DWORD PTR ds:0xfdf3d4,ebx
  5b9716:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  5b971d:	e8 5e ac 13 00                                  	call   0x6f4380
  5b9722:	68 d0 e6 bc 00                                  	push   0xbce6d0
  5b9727:	e8 ee 8b 2d 00                                  	call   0x89231a
  5b972c:	83 c4 04                                        	add    esp,0x4
  5b972f:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b9736:	68 40 dd c0 00                                  	push   0xc0dd40
  5b973b:	6a 00                                           	push   0x0
  5b973d:	68 c8 f3 fd 00                                  	push   0xfdf3c8
  5b9742:	e8 59 39 ef ff                                  	call   0x4ad0a0

# caller_0x5c3672

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005c3613 <.text+0x1c2613>:
  5c3613:	6a ff                                           	push   0xffffffff
  5c3615:	68 6c 73 94 00                                  	push   0x94736c
  5c361a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  5c3620:	50                                              	push   eax
  5c3621:	53                                              	push   ebx
  5c3622:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  5c3627:	33 c5                                           	xor    eax,ebp
  5c3629:	50                                              	push   eax
  5c362a:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  5c362d:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  5c3633:	bb 01 00 00 00                                  	mov    ebx,0x1
  5c3638:	84 1d d4 f3 fd 00                               	test   BYTE PTR ds:0xfdf3d4,bl
  5c363e:	75 26                                           	jne    0x5c3666
  5c3640:	09 1d d4 f3 fd 00                               	or     DWORD PTR ds:0xfdf3d4,ebx
  5c3646:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  5c364d:	e8 2e 0d 13 00                                  	call   0x6f4380
  5c3652:	68 d0 e6 bc 00                                  	push   0xbce6d0
  5c3657:	e8 be ec 2c 00                                  	call   0x89231a
  5c365c:	83 c4 04                                        	add    esp,0x4
  5c365f:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  5c3666:	68 40 dd c0 00                                  	push   0xc0dd40
  5c366b:	6a 00                                           	push   0x0
  5c366d:	68 c8 f3 fd 00                                  	push   0xfdf3c8
  5c3672:	e8 29 9a ee ff                                  	call   0x4ad0a0

# caller_0x6bd7bc

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006bd74d <.text+0x2bc74d>:
  6bd74d:	75 27                                           	jne    0x6bd776
  6bd74f:	83 0d a4 72 fb 00 01                            	or     DWORD PTR ds:0xfb72a4,0x1
  6bd756:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  6bd75d:	e8 ee 20 de ff                                  	call   0x49f850
  6bd762:	68 e0 cf bc 00                                  	push   0xbccfe0
  6bd767:	e8 ae 4b 1d 00                                  	call   0x89231a
  6bd76c:	83 c4 04                                        	add    esp,0x4
  6bd76f:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  6bd776:	ba a8 72 fb 00                                  	mov    edx,0xfb72a8
  6bd77b:	e8 c0 2d de ff                                  	call   0x4a0540
  6bd780:	f6 05 d4 f3 fd 00 01                            	test   BYTE PTR ds:0xfdf3d4,0x1
  6bd787:	75 27                                           	jne    0x6bd7b0
  6bd789:	b8 01 00 00 00                                  	mov    eax,0x1
  6bd78e:	09 05 d4 f3 fd 00                               	or     DWORD PTR ds:0xfdf3d4,eax
  6bd794:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  6bd797:	e8 e4 6b 03 00                                  	call   0x6f4380
  6bd79c:	68 d0 e6 bc 00                                  	push   0xbce6d0
  6bd7a1:	e8 74 4b 1d 00                                  	call   0x89231a
  6bd7a6:	83 c4 04                                        	add    esp,0x4
  6bd7a9:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  6bd7b0:	68 ac 02 c1 00                                  	push   0xc102ac
  6bd7b5:	6a 00                                           	push   0x0
  6bd7b7:	68 c8 f3 fd 00                                  	push   0xfdf3c8
  6bd7bc:	e8 df f8 de ff                                  	call   0x4ad0a0

# named_global_call_wrapper

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4dd0 <.text+0x2f3dd0>:
  6f4dd0:	55                                              	push   ebp
  6f4dd1:	8b ec                                           	mov    ebp,esp
  6f4dd3:	83 e4 f8                                        	and    esp,0xfffffff8
  6f4dd6:	83 ec 14                                        	sub    esp,0x14
  6f4dd9:	53                                              	push   ebx
  6f4dda:	56                                              	push   esi
  6f4ddb:	57                                              	push   edi
  6f4ddc:	8b f8                                           	mov    edi,eax
  6f4dde:	8b 37                                           	mov    esi,DWORD PTR [edi]
  6f4de0:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f4de3:	8d 5e 48                                        	lea    ebx,[esi+0x48]
  6f4de6:	8d 48 01                                        	lea    ecx,[eax+0x1]
  6f4de9:	8d a4 24 00 00 00 00                            	lea    esp,[esp+0x0]
  6f4df0:	8a 10                                           	mov    dl,BYTE PTR [eax]
  6f4df2:	40                                              	inc    eax
  6f4df3:	84 d2                                           	test   dl,dl
  6f4df5:	75 f9                                           	jne    0x6f4df0
  6f4df7:	2b c1                                           	sub    eax,ecx
  6f4df9:	50                                              	push   eax
  6f4dfa:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f4dfd:	50                                              	push   eax
  6f4dfe:	56                                              	push   esi
  6f4dff:	e8 6c 9e 00 00                                  	call   0x6fec70
  6f4e04:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  6f4e07:	83 c4 0c                                        	add    esp,0xc
  6f4e0a:	51                                              	push   ecx
  6f4e0b:	8d 54 24 14                                     	lea    edx,[esp+0x14]
  6f4e0f:	52                                              	push   edx
  6f4e10:	53                                              	push   ebx
  6f4e11:	56                                              	push   esi
  6f4e12:	89 44 24 20                                     	mov    DWORD PTR [esp+0x20],eax
  6f4e16:	c7 44 24 28 04 00 00 00                         	mov    DWORD PTR [esp+0x28],0x4
  6f4e1e:	e8 2d 6a 00 00                                  	call   0x6fb850
  6f4e23:	bb 10 00 00 00                                  	mov    ebx,0x10
  6f4e28:	01 5e 08                                        	add    DWORD PTR [esi+0x8],ebx
  6f4e2b:	8b 07                                           	mov    eax,DWORD PTR [edi]
  6f4e2d:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  6f4e30:	2b c3                                           	sub    eax,ebx
  6f4e32:	83 c4 10                                        	add    esp,0x10
  6f4e35:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  6f4e3a:	0f 84 b5 00 00 00                               	je     0x6f4ef5
  6f4e40:	83 78 08 06                                     	cmp    DWORD PTR [eax+0x8],0x6
  6f4e44:	0f 85 ab 00 00 00                               	jne    0x6f4ef5
  6f4e4a:	8b 55 10                                        	mov    edx,DWORD PTR [ebp+0x10]
  6f4e4d:	8d 45 14                                        	lea    eax,[ebp+0x14]
  6f4e50:	50                                              	push   eax
  6f4e51:	57                                              	push   edi
  6f4e52:	e8 79 fe ff ff                                  	call   0x6f4cd0
  6f4e57:	8b 37                                           	mov    esi,DWORD PTR [edi]
  6f4e59:	8b 5d 0c                                        	mov    ebx,DWORD PTR [ebp+0xc]
  6f4e5c:	8d 48 01                                        	lea    ecx,[eax+0x1]
  6f4e5f:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f4e62:	c1 e1 04                                        	shl    ecx,0x4
  6f4e65:	2b c1                                           	sub    eax,ecx
  6f4e67:	89 44 24 10                                     	mov    DWORD PTR [esp+0x10],eax
  6f4e6b:	2b 46 20                                        	sub    eax,DWORD PTR [esi+0x20]
  6f4e6e:	8d 54 24 10                                     	lea    edx,[esp+0x10]
  6f4e72:	50                                              	push   eax
  6f4e73:	52                                              	push   edx
  6f4e74:	68 50 5a 6f 00                                  	push   0x6f5a50
  6f4e79:	33 d2                                           	xor    edx,edx
  6f4e7b:	8b c6                                           	mov    eax,esi
  6f4e7d:	89 5c 24 20                                     	mov    DWORD PTR [esp+0x20],ebx
  6f4e81:	e8 ea 98 00 00                                  	call   0x6fe770
  6f4e86:	83 c4 0c                                        	add    esp,0xc
  6f4e89:	83 fb ff                                        	cmp    ebx,0xffffffff
  6f4e8c:	75 0e                                           	jne    0x6f4e9c
  6f4e8e:	8b 4e 14                                        	mov    ecx,DWORD PTR [esi+0x14]
  6f4e91:	8b 76 08                                        	mov    esi,DWORD PTR [esi+0x8]
  6f4e94:	3b 71 08                                        	cmp    esi,DWORD PTR [ecx+0x8]
  6f4e97:	72 03                                           	jb     0x6f4e9c
  6f4e99:	89 71 08                                        	mov    DWORD PTR [ecx+0x8],esi
  6f4e9c:	85 c0                                           	test   eax,eax
  6f4e9e:	0f 84 87 00 00 00                               	je     0x6f4f2b
  6f4ea4:	8b 3f                                           	mov    edi,DWORD PTR [edi]
  6f4ea6:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f4ea9:	83 ee 10                                        	sub    esi,0x10
  6f4eac:	83 7e 08 04                                     	cmp    DWORD PTR [esi+0x8],0x4
  6f4eb0:	74 25                                           	je     0x6f4ed7
  6f4eb2:	e8 19 67 00 00                                  	call   0x6fb5d0
  6f4eb7:	85 c0                                           	test   eax,eax
  6f4eb9:	75 04                                           	jne    0x6f4ebf
  6f4ebb:	33 f6                                           	xor    esi,esi
  6f4ebd:	eb 1d                                           	jmp    0x6f4edc
  6f4ebf:	8b 47 10                                        	mov    eax,DWORD PTR [edi+0x10]
  6f4ec2:	8b 48 44                                        	mov    ecx,DWORD PTR [eax+0x44]
  6f4ec5:	3b 48 40                                        	cmp    ecx,DWORD PTR [eax+0x40]
  6f4ec8:	72 07                                           	jb     0x6f4ed1
  6f4eca:	8b c7                                           	mov    eax,edi
  6f4ecc:	e8 cf 64 00 00                                  	call   0x6fb3a0
  6f4ed1:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f4ed4:	83 ee 10                                        	sub    esi,0x10
  6f4ed7:	8b 36                                           	mov    esi,DWORD PTR [esi]
  6f4ed9:	83 c6 10                                        	add    esi,0x10
  6f4edc:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  6f4edf:	56                                              	push   esi
  6f4ee0:	52                                              	push   edx
  6f4ee1:	68 78 26 c4 00                                  	push   0xc42678
  6f4ee6:	e8 d2 e1 19 00                                  	call   0x8930bd
  6f4eeb:	83 c4 0c                                        	add    esp,0xc
  6f4eee:	5f                                              	pop    edi
  6f4eef:	5e                                              	pop    esi
  6f4ef0:	5b                                              	pop    ebx
  6f4ef1:	8b e5                                           	mov    esp,ebp
  6f4ef3:	5d                                              	pop    ebp
  6f4ef4:	c3                                              	ret
  6f4ef5:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f4ef8:	50                                              	push   eax
  6f4ef9:	68 10 26 c4 00                                  	push   0xc42610
  6f4efe:	e8 ba e1 19 00                                  	call   0x8930bd
  6f4f03:	8b 07                                           	mov    eax,DWORD PTR [edi]
  6f4f05:	8b 48 08                                        	mov    ecx,DWORD PTR [eax+0x8]
  6f4f08:	83 c4 08                                        	add    esp,0x8
  6f4f0b:	3b 48 0c                                        	cmp    ecx,DWORD PTR [eax+0xc]
  6f4f0e:	73 15                                           	jae    0x6f4f25
  6f4f10:	8b 50 08                                        	mov    edx,DWORD PTR [eax+0x8]
  6f4f13:	c7 42 08 00 00 00 00                            	mov    DWORD PTR [edx+0x8],0x0
  6f4f1a:	01 58 08                                        	add    DWORD PTR [eax+0x8],ebx
  6f4f1d:	8b 48 08                                        	mov    ecx,DWORD PTR [eax+0x8]
  6f4f20:	3b 48 0c                                        	cmp    ecx,DWORD PTR [eax+0xc]
  6f4f23:	72 eb                                           	jb     0x6f4f10
  6f4f25:	8b 50 0c                                        	mov    edx,DWORD PTR [eax+0xc]
  6f4f28:	89 50 08                                        	mov    DWORD PTR [eax+0x8],edx
  6f4f2b:	5f                                              	pop    edi
  6f4f2c:	5e                                              	pop    esi
  6f4f2d:	5b                                              	pop    ebx
  6f4f2e:	8b e5                                           	mov    esp,ebp
  6f4f30:	5d                                              	pop    ebp
  6f4f31:	c3                                              	ret
  6f4f32:	cc                                              	int3
  6f4f33:	cc                                              	int3
  6f4f34:	cc                                              	int3
  6f4f35:	cc                                              	int3
  6f4f36:	cc                                              	int3
  6f4f37:	cc                                              	int3
  6f4f38:	cc                                              	int3
  6f4f39:	cc                                              	int3
  6f4f3a:	cc                                              	int3
  6f4f3b:	cc                                              	int3
  6f4f3c:	cc                                              	int3
  6f4f3d:	cc                                              	int3
  6f4f3e:	cc                                              	int3
  6f4f3f:	cc                                              	int3

# table_method_call_wrapper

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4f40 <.text+0x2f3f40>:
  6f4f40:	55                                              	push   ebp
  6f4f41:	8b ec                                           	mov    ebp,esp
  6f4f43:	83 e4 f8                                        	and    esp,0xfffffff8
  6f4f46:	83 ec 0c                                        	sub    esp,0xc
  6f4f49:	53                                              	push   ebx
  6f4f4a:	8b 5d 0c                                        	mov    ebx,DWORD PTR [ebp+0xc]
  6f4f4d:	56                                              	push   esi
  6f4f4e:	57                                              	push   edi
  6f4f4f:	8b f8                                           	mov    edi,eax
  6f4f51:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f4f54:	8b 37                                           	mov    esi,DWORD PTR [edi]
  6f4f56:	50                                              	push   eax
  6f4f57:	e8 b4 05 00 00                                  	call   0x6f5510
  6f4f5c:	8b 37                                           	mov    esi,DWORD PTR [edi]
  6f4f5e:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  6f4f61:	8d 41 f0                                        	lea    eax,[ecx-0x10]
  6f4f64:	8b 49 e0                                        	mov    ecx,DWORD PTR [ecx-0x20]
  6f4f67:	83 c4 04                                        	add    esp,0x4
  6f4f6a:	e8 e1 4c 00 00                                  	call   0x6f9c50
  6f4f6f:	8b 10                                           	mov    edx,DWORD PTR [eax]
  6f4f71:	8b 4e 08                                        	mov    ecx,DWORD PTR [esi+0x8]
  6f4f74:	89 51 f0                                        	mov    DWORD PTR [ecx-0x10],edx
  6f4f77:	8b 50 04                                        	mov    edx,DWORD PTR [eax+0x4]
  6f4f7a:	89 51 f4                                        	mov    DWORD PTR [ecx-0xc],edx
  6f4f7d:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  6f4f80:	89 41 f8                                        	mov    DWORD PTR [ecx-0x8],eax
  6f4f83:	8b 0f                                           	mov    ecx,DWORD PTR [edi]
  6f4f85:	8b 41 08                                        	mov    eax,DWORD PTR [ecx+0x8]
  6f4f88:	83 e8 10                                        	sub    eax,0x10
  6f4f8b:	3d c8 bf c0 00                                  	cmp    eax,0xc0bfc8
  6f4f90:	0f 84 d9 00 00 00                               	je     0x6f506f
  6f4f96:	83 78 08 06                                     	cmp    DWORD PTR [eax+0x8],0x6
  6f4f9a:	0f 85 cf 00 00 00                               	jne    0x6f506f
  6f4fa0:	8b 41 08                                        	mov    eax,DWORD PTR [ecx+0x8]
  6f4fa3:	8b 50 e0                                        	mov    edx,DWORD PTR [eax-0x20]
  6f4fa6:	89 10                                           	mov    DWORD PTR [eax],edx
  6f4fa8:	8b 50 e4                                        	mov    edx,DWORD PTR [eax-0x1c]
  6f4fab:	89 50 04                                        	mov    DWORD PTR [eax+0x4],edx
  6f4fae:	8b 50 e8                                        	mov    edx,DWORD PTR [eax-0x18]
  6f4fb1:	89 50 08                                        	mov    DWORD PTR [eax+0x8],edx
  6f4fb4:	83 41 08 10                                     	add    DWORD PTR [ecx+0x8],0x10
  6f4fb8:	8b 55 10                                        	mov    edx,DWORD PTR [ebp+0x10]
  6f4fbb:	8d 45 14                                        	lea    eax,[ebp+0x14]
  6f4fbe:	50                                              	push   eax
  6f4fbf:	57                                              	push   edi
  6f4fc0:	e8 0b fd ff ff                                  	call   0x6f4cd0
  6f4fc5:	8b 37                                           	mov    esi,DWORD PTR [edi]
  6f4fc7:	8d 48 02                                        	lea    ecx,[eax+0x2]
  6f4fca:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f4fcd:	c1 e1 04                                        	shl    ecx,0x4
  6f4fd0:	2b c1                                           	sub    eax,ecx
  6f4fd2:	89 44 24 10                                     	mov    DWORD PTR [esp+0x10],eax
  6f4fd6:	2b 46 20                                        	sub    eax,DWORD PTR [esi+0x20]
  6f4fd9:	8d 54 24 10                                     	lea    edx,[esp+0x10]
  6f4fdd:	50                                              	push   eax
  6f4fde:	52                                              	push   edx
  6f4fdf:	68 50 5a 6f 00                                  	push   0x6f5a50
  6f4fe4:	33 d2                                           	xor    edx,edx
  6f4fe6:	8b c6                                           	mov    eax,esi
  6f4fe8:	89 5c 24 20                                     	mov    DWORD PTR [esp+0x20],ebx
  6f4fec:	e8 7f 97 00 00                                  	call   0x6fe770
  6f4ff1:	83 c4 0c                                        	add    esp,0xc
  6f4ff4:	83 fb ff                                        	cmp    ebx,0xffffffff
  6f4ff7:	75 0e                                           	jne    0x6f5007
  6f4ff9:	8b 4e 14                                        	mov    ecx,DWORD PTR [esi+0x14]
  6f4ffc:	8b 76 08                                        	mov    esi,DWORD PTR [esi+0x8]
  6f4fff:	3b 71 08                                        	cmp    esi,DWORD PTR [ecx+0x8]
  6f5002:	72 03                                           	jb     0x6f5007
  6f5004:	89 71 08                                        	mov    DWORD PTR [ecx+0x8],esi
  6f5007:	85 c0                                           	test   eax,eax
  6f5009:	0f 84 da 00 00 00                               	je     0x6f50e9
  6f500f:	8b 3f                                           	mov    edi,DWORD PTR [edi]
  6f5011:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f5014:	83 ee 10                                        	sub    esi,0x10
  6f5017:	83 7e 08 04                                     	cmp    DWORD PTR [esi+0x8],0x4
  6f501b:	74 38                                           	je     0x6f5055
  6f501d:	e8 ae 65 00 00                                  	call   0x6fb5d0
  6f5022:	85 c0                                           	test   eax,eax
  6f5024:	75 17                                           	jne    0x6f503d
  6f5026:	33 f6                                           	xor    esi,esi
  6f5028:	56                                              	push   esi
  6f5029:	68 a4 26 c4 00                                  	push   0xc426a4
  6f502e:	e8 8a e0 19 00                                  	call   0x8930bd
  6f5033:	83 c4 08                                        	add    esp,0x8
  6f5036:	5f                                              	pop    edi
  6f5037:	5e                                              	pop    esi
  6f5038:	5b                                              	pop    ebx
  6f5039:	8b e5                                           	mov    esp,ebp
  6f503b:	5d                                              	pop    ebp
  6f503c:	c3                                              	ret
  6f503d:	8b 47 10                                        	mov    eax,DWORD PTR [edi+0x10]
  6f5040:	8b 48 44                                        	mov    ecx,DWORD PTR [eax+0x44]
  6f5043:	3b 48 40                                        	cmp    ecx,DWORD PTR [eax+0x40]
  6f5046:	72 07                                           	jb     0x6f504f
  6f5048:	8b c7                                           	mov    eax,edi
  6f504a:	e8 51 63 00 00                                  	call   0x6fb3a0
  6f504f:	8b 77 08                                        	mov    esi,DWORD PTR [edi+0x8]
  6f5052:	83 ee 10                                        	sub    esi,0x10
  6f5055:	8b 36                                           	mov    esi,DWORD PTR [esi]
  6f5057:	83 c6 10                                        	add    esi,0x10
  6f505a:	56                                              	push   esi
  6f505b:	68 a4 26 c4 00                                  	push   0xc426a4
  6f5060:	e8 58 e0 19 00                                  	call   0x8930bd
  6f5065:	83 c4 08                                        	add    esp,0x8
  6f5068:	5f                                              	pop    edi
  6f5069:	5e                                              	pop    esi
  6f506a:	5b                                              	pop    ebx
  6f506b:	8b e5                                           	mov    esp,ebp
  6f506d:	5d                                              	pop    ebp
  6f506e:	c3                                              	ret
  6f506f:	83 41 08 f0                                     	add    DWORD PTR [ecx+0x8],0xfffffff0
  6f5073:	8b 0f                                           	mov    ecx,DWORD PTR [edi]
  6f5075:	8b 41 08                                        	mov    eax,DWORD PTR [ecx+0x8]
  6f5078:	8b 50 f8                                        	mov    edx,DWORD PTR [eax-0x8]
  6f507b:	8b f2                                           	mov    esi,edx
  6f507d:	83 ee 05                                        	sub    esi,0x5
  6f5080:	74 11                                           	je     0x6f5093
  6f5082:	83 ee 02                                        	sub    esi,0x2
  6f5085:	74 0c                                           	je     0x6f5093
  6f5087:	8b 71 10                                        	mov    esi,DWORD PTR [ecx+0x10]
  6f508a:	8b 94 96 98 00 00 00                            	mov    edx,DWORD PTR [esi+edx*4+0x98]
  6f5091:	eb 06                                           	jmp    0x6f5099
  6f5093:	8b 50 f0                                        	mov    edx,DWORD PTR [eax-0x10]
  6f5096:	8b 52 08                                        	mov    edx,DWORD PTR [edx+0x8]
  6f5099:	85 d2                                           	test   edx,edx
  6f509b:	74 3b                                           	je     0x6f50d8
  6f509d:	89 10                                           	mov    DWORD PTR [eax],edx
  6f509f:	c7 40 08 05 00 00 00                            	mov    DWORD PTR [eax+0x8],0x5
  6f50a6:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f50a9:	be 10 00 00 00                                  	mov    esi,0x10
  6f50ae:	01 71 08                                        	add    DWORD PTR [ecx+0x8],esi
  6f50b1:	e8 ba 13 00 00                                  	call   0x6f6470
  6f50b6:	85 c0                                           	test   eax,eax
  6f50b8:	74 1e                                           	je     0x6f50d8
  6f50ba:	8b 0f                                           	mov    ecx,DWORD PTR [edi]
  6f50bc:	8b 41 08                                        	mov    eax,DWORD PTR [ecx+0x8]
  6f50bf:	8b 50 e0                                        	mov    edx,DWORD PTR [eax-0x20]
  6f50c2:	89 10                                           	mov    DWORD PTR [eax],edx
  6f50c4:	8b 50 e4                                        	mov    edx,DWORD PTR [eax-0x1c]
  6f50c7:	89 50 04                                        	mov    DWORD PTR [eax+0x4],edx
  6f50ca:	8b 50 e8                                        	mov    edx,DWORD PTR [eax-0x18]
  6f50cd:	89 50 08                                        	mov    DWORD PTR [eax+0x8],edx
  6f50d0:	01 71 08                                        	add    DWORD PTR [ecx+0x8],esi
  6f50d3:	e9 e0 fe ff ff                                  	jmp    0x6f4fb8
  6f50d8:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  6f50db:	52                                              	push   edx
  6f50dc:	68 54 26 c4 00                                  	push   0xc42654
  6f50e1:	e8 d7 df 19 00                                  	call   0x8930bd
  6f50e6:	83 c4 08                                        	add    esp,0x8
  6f50e9:	5f                                              	pop    edi
  6f50ea:	5e                                              	pop    esi
  6f50eb:	5b                                              	pop    ebx
  6f50ec:	8b e5                                           	mov    esp,ebp
  6f50ee:	5d                                              	pop    ebp
  6f50ef:	c3                                              	ret

# stack_function_protected_call

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f5a70 <.text+0x2f4a70>:
  6f5a70:	55                                              	push   ebp
  6f5a71:	8b ec                                           	mov    ebp,esp
  6f5a73:	83 e4 f8                                        	and    esp,0xfffffff8
  6f5a76:	83 ec 0c                                        	sub    esp,0xc
  6f5a79:	56                                              	push   esi
  6f5a7a:	8b f1                                           	mov    esi,ecx
  6f5a7c:	85 c0                                           	test   eax,eax
  6f5a7e:	75 04                                           	jne    0x6f5a84
  6f5a80:	33 d2                                           	xor    edx,edx
  6f5a82:	eb 0a                                           	jmp    0x6f5a8e
  6f5a84:	e8 67 f6 ff ff                                  	call   0x6f50f0
  6f5a89:	2b 46 20                                        	sub    eax,DWORD PTR [esi+0x20]
  6f5a8c:	8b d0                                           	mov    edx,eax
  6f5a8e:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  6f5a91:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f5a94:	41                                              	inc    ecx
  6f5a95:	c1 e1 04                                        	shl    ecx,0x4
  6f5a98:	2b c1                                           	sub    eax,ecx
  6f5a9a:	89 44 24 08                                     	mov    DWORD PTR [esp+0x8],eax
  6f5a9e:	2b 46 20                                        	sub    eax,DWORD PTR [esi+0x20]
  6f5aa1:	89 7c 24 0c                                     	mov    DWORD PTR [esp+0xc],edi
  6f5aa5:	50                                              	push   eax
  6f5aa6:	8d 44 24 0c                                     	lea    eax,[esp+0xc]
  6f5aaa:	50                                              	push   eax
  6f5aab:	68 50 5a 6f 00                                  	push   0x6f5a50
  6f5ab0:	8b c6                                           	mov    eax,esi
  6f5ab2:	e8 b9 8c 00 00                                  	call   0x6fe770
  6f5ab7:	83 c4 0c                                        	add    esp,0xc
  6f5aba:	83 ff ff                                        	cmp    edi,0xffffffff
  6f5abd:	75 0e                                           	jne    0x6f5acd
  6f5abf:	8b 4e 14                                        	mov    ecx,DWORD PTR [esi+0x14]
  6f5ac2:	8b 76 08                                        	mov    esi,DWORD PTR [esi+0x8]
  6f5ac5:	3b 71 08                                        	cmp    esi,DWORD PTR [ecx+0x8]
  6f5ac8:	72 03                                           	jb     0x6f5acd
  6f5aca:	89 71 08                                        	mov    DWORD PTR [ecx+0x8],esi
  6f5acd:	5e                                              	pop    esi
  6f5ace:	8b e5                                           	mov    esp,ebp
  6f5ad0:	5d                                              	pop    ebp
  6f5ad1:	c3                                              	ret
  6f5ad2:	cc                                              	int3
  6f5ad3:	cc                                              	int3
  6f5ad4:	cc                                              	int3
  6f5ad5:	cc                                              	int3
  6f5ad6:	cc                                              	int3
  6f5ad7:	cc                                              	int3
  6f5ad8:	cc                                              	int3
  6f5ad9:	cc                                              	int3
  6f5ada:	cc                                              	int3
  6f5adb:	cc                                              	int3
  6f5adc:	cc                                              	int3
  6f5add:	cc                                              	int3
  6f5ade:	cc                                              	int3
  6f5adf:	cc                                              	int3

# fixed_name_zero_argument_wrapper

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
  4ad11f:	cc                                              	int3

# format_argument_marshaller

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f4cd0 <.text+0x2f3cd0>:
  6f4cd0:	55                                              	push   ebp
  6f4cd1:	8b ec                                           	mov    ebp,esp
  6f4cd3:	51                                              	push   ecx
  6f4cd4:	53                                              	push   ebx
  6f4cd5:	8b 5d 0c                                        	mov    ebx,DWORD PTR [ebp+0xc]
  6f4cd8:	56                                              	push   esi
  6f4cd9:	57                                              	push   edi
  6f4cda:	c7 45 0c 00 00 00 00                            	mov    DWORD PTR [ebp+0xc],0x0
  6f4ce1:	85 d2                                           	test   edx,edx
  6f4ce3:	75 0b                                           	jne    0x6f4cf0
  6f4ce5:	33 c0                                           	xor    eax,eax
  6f4ce7:	5f                                              	pop    edi
  6f4ce8:	5e                                              	pop    esi
  6f4ce9:	5b                                              	pop    ebx
  6f4cea:	8b e5                                           	mov    esp,ebp
  6f4cec:	5d                                              	pop    ebp
  6f4ced:	c2 08 00                                        	ret    0x8
  6f4cf0:	80 3a 00                                        	cmp    BYTE PTR [edx],0x0
  6f4cf3:	0f 84 c6 00 00 00                               	je     0x6f4dbf
  6f4cf9:	8d 7b fc                                        	lea    edi,[ebx-0x4]
  6f4cfc:	83 c3 f8                                        	add    ebx,0xfffffff8
  6f4cff:	8a 02                                           	mov    al,BYTE PTR [edx]
  6f4d01:	3c 29                                           	cmp    al,0x29
  6f4d03:	0f 84 b6 00 00 00                               	je     0x6f4dbf
  6f4d09:	3c 25                                           	cmp    al,0x25
  6f4d0b:	0f 85 a4 00 00 00                               	jne    0x6f4db5
  6f4d11:	8a 42 01                                        	mov    al,BYTE PTR [edx+0x1]
  6f4d14:	42                                              	inc    edx
  6f4d15:	89 55 fc                                        	mov    DWORD PTR [ebp-0x4],edx
  6f4d18:	3c 64                                           	cmp    al,0x64
  6f4d1a:	75 20                                           	jne    0x6f4d3c
  6f4d1c:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f4d1f:	db 47 04                                        	fild   DWORD PTR [edi+0x4]
  6f4d22:	8b 00                                           	mov    eax,DWORD PTR [eax]
  6f4d24:	8b 48 08                                        	mov    ecx,DWORD PTR [eax+0x8]
  6f4d27:	83 c7 04                                        	add    edi,0x4
  6f4d2a:	dd 19                                           	fstp   QWORD PTR [ecx]
  6f4d2c:	83 c3 04                                        	add    ebx,0x4
  6f4d2f:	c7 41 08 03 00 00 00                            	mov    DWORD PTR [ecx+0x8],0x3
  6f4d36:	83 40 08 10                                     	add    DWORD PTR [eax+0x8],0x10
  6f4d3a:	eb 76                                           	jmp    0x6f4db2
  6f4d3c:	3c 66                                           	cmp    al,0x66
  6f4d3e:	75 20                                           	jne    0x6f4d60
  6f4d40:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  6f4d43:	dd 43 08                                        	fld    QWORD PTR [ebx+0x8]
  6f4d46:	8b 01                                           	mov    eax,DWORD PTR [ecx]
  6f4d48:	8b 48 08                                        	mov    ecx,DWORD PTR [eax+0x8]
  6f4d4b:	83 c3 08                                        	add    ebx,0x8
  6f4d4e:	dd 19                                           	fstp   QWORD PTR [ecx]
  6f4d50:	83 c7 08                                        	add    edi,0x8
  6f4d53:	c7 41 08 03 00 00 00                            	mov    DWORD PTR [ecx+0x8],0x3
  6f4d5a:	83 40 08 10                                     	add    DWORD PTR [eax+0x8],0x10
  6f4d5e:	eb 52                                           	jmp    0x6f4db2
  6f4d60:	3c 73                                           	cmp    al,0x73
  6f4d62:	75 11                                           	jne    0x6f4d75
  6f4d64:	8b 57 04                                        	mov    edx,DWORD PTR [edi+0x4]
  6f4d67:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  6f4d6a:	8b 30                                           	mov    esi,DWORD PTR [eax]
  6f4d6c:	83 c3 04                                        	add    ebx,0x4
  6f4d6f:	83 c7 04                                        	add    edi,0x4
  6f4d72:	52                                              	push   edx
  6f4d73:	eb 32                                           	jmp    0x6f4da7
  6f4d75:	3c 77                                           	cmp    al,0x77
  6f4d77:	75 39                                           	jne    0x6f4db2
  6f4d79:	8b 4f 04                                        	mov    ecx,DWORD PTR [edi+0x4]
  6f4d7c:	6a 00                                           	push   0x0
  6f4d7e:	6a 00                                           	push   0x0
  6f4d80:	68 00 04 00 00                                  	push   0x400
  6f4d85:	68 d0 69 fe 00                                  	push   0xfe69d0
  6f4d8a:	83 c7 04                                        	add    edi,0x4
  6f4d8d:	6a ff                                           	push   0xffffffff
  6f4d8f:	51                                              	push   ecx
  6f4d90:	6a 00                                           	push   0x0
  6f4d92:	6a 00                                           	push   0x0
  6f4d94:	83 c3 04                                        	add    ebx,0x4
  6f4d97:	ff 15 cc 21 bd 00                               	call   DWORD PTR ds:0xbd21cc
  6f4d9d:	8b 55 08                                        	mov    edx,DWORD PTR [ebp+0x8]
  6f4da0:	8b 32                                           	mov    esi,DWORD PTR [edx]
  6f4da2:	68 d0 69 fe 00                                  	push   0xfe69d0
  6f4da7:	e8 64 07 00 00                                  	call   0x6f5510
  6f4dac:	8b 55 fc                                        	mov    edx,DWORD PTR [ebp-0x4]
  6f4daf:	83 c4 04                                        	add    esp,0x4
  6f4db2:	ff 45 0c                                        	inc    DWORD PTR [ebp+0xc]
  6f4db5:	42                                              	inc    edx
  6f4db6:	80 3a 00                                        	cmp    BYTE PTR [edx],0x0
  6f4db9:	0f 85 40 ff ff ff                               	jne    0x6f4cff
  6f4dbf:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  6f4dc2:	5f                                              	pop    edi
  6f4dc3:	5e                                              	pop    esi
  6f4dc4:	5b                                              	pop    ebx
  6f4dc5:	8b e5                                           	mov    esp,ebp
  6f4dc7:	5d                                              	pop    ebp
  6f4dc8:	c2 08 00                                        	ret    0x8
  6f4dcb:	cc                                              	int3
  6f4dcc:	cc                                              	int3
  6f4dcd:	cc                                              	int3
  6f4dce:	cc                                              	int3
  6f4dcf:	cc                                              	int3

# global_field_lookup

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006f5680 <.text+0x2f4680>:
  6f5680:	55                                              	push   ebp
  6f5681:	8b ec                                           	mov    ebp,esp
  6f5683:	83 e4 f8                                        	and    esp,0xfffffff8
  6f5686:	83 ec 14                                        	sub    esp,0x14
  6f5689:	53                                              	push   ebx
  6f568a:	8b ce                                           	mov    ecx,esi
  6f568c:	e8 5f fa ff ff                                  	call   0x6f50f0
  6f5691:	8b d8                                           	mov    ebx,eax
  6f5693:	8b c7                                           	mov    eax,edi
  6f5695:	8d 50 01                                        	lea    edx,[eax+0x1]
  6f5698:	8a 08                                           	mov    cl,BYTE PTR [eax]
  6f569a:	40                                              	inc    eax
  6f569b:	84 c9                                           	test   cl,cl
  6f569d:	75 f9                                           	jne    0x6f5698
  6f569f:	2b c2                                           	sub    eax,edx
  6f56a1:	50                                              	push   eax
  6f56a2:	57                                              	push   edi
  6f56a3:	56                                              	push   esi
  6f56a4:	e8 c7 95 00 00                                  	call   0x6fec70
  6f56a9:	89 44 24 14                                     	mov    DWORD PTR [esp+0x14],eax
  6f56ad:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  6f56b0:	50                                              	push   eax
  6f56b1:	8d 4c 24 18                                     	lea    ecx,[esp+0x18]
  6f56b5:	51                                              	push   ecx
  6f56b6:	53                                              	push   ebx
  6f56b7:	56                                              	push   esi
  6f56b8:	c7 44 24 2c 04 00 00 00                         	mov    DWORD PTR [esp+0x2c],0x4
  6f56c0:	e8 8b 61 00 00                                  	call   0x6fb850
  6f56c5:	83 c4 1c                                        	add    esp,0x1c
  6f56c8:	83 46 08 10                                     	add    DWORD PTR [esi+0x8],0x10
  6f56cc:	5b                                              	pop    ebx
  6f56cd:	8b e5                                           	mov    esp,ebp
  6f56cf:	5d                                              	pop    ebp
  6f56d0:	c3                                              	ret
  6f56d1:	cc                                              	int3
  6f56d2:	cc                                              	int3
  6f56d3:	cc                                              	int3
  6f56d4:	cc                                              	int3
  6f56d5:	cc                                              	int3
  6f56d6:	cc                                              	int3
  6f56d7:	cc                                              	int3
  6f56d8:	cc                                              	int3
  6f56d9:	cc                                              	int3
  6f56da:	cc                                              	int3
  6f56db:	cc                                              	int3
  6f56dc:	cc                                              	int3
  6f56dd:	cc                                              	int3
  6f56de:	cc                                              	int3
  6f56df:	cc                                              	int3

# formal_wrapper_getter_for_confirm_callback

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049b230 <.text+0x9a230>:
  49b230:	55                                              	push   ebp
  49b231:	8b ec                                           	mov    ebp,esp
  49b233:	6a ff                                           	push   0xffffffff
  49b235:	68 ce a5 93 00                                  	push   0x93a5ce
  49b23a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  49b240:	50                                              	push   eax
  49b241:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  49b246:	33 c5                                           	xor    eax,ebp
  49b248:	50                                              	push   eax
  49b249:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  49b24c:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  49b252:	b8 01 00 00 00                                  	mov    eax,0x1
  49b257:	84 05 d4 f3 fd 00                               	test   BYTE PTR ds:0xfdf3d4,al
  49b25d:	75 1f                                           	jne    0x49b27e
  49b25f:	09 05 d4 f3 fd 00                               	or     DWORD PTR ds:0xfdf3d4,eax
  49b265:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  49b26c:	e8 0f 91 25 00                                  	call   0x6f4380
  49b271:	68 d0 e6 bc 00                                  	push   0xbce6d0
  49b276:	e8 9f 70 3f 00                                  	call   0x89231a
  49b27b:	83 c4 04                                        	add    esp,0x4
  49b27e:	b8 c8 f3 fd 00                                  	mov    eax,0xfdf3c8
  49b283:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  49b286:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  49b28d:	59                                              	pop    ecx
  49b28e:	8b e5                                           	mov    esp,ebp
  49b290:	5d                                              	pop    ebp
  49b291:	c3                                              	ret
