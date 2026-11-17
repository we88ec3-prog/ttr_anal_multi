# 0x48b2e0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048b2e0 <.text+0x8a2e0>:
  48b2e0:	55                                              	push   ebp
  48b2e1:	8b ec                                           	mov    ebp,esp
  48b2e3:	6a ff                                           	push   0xffffffff
  48b2e5:	68 cd 23 92 00                                  	push   0x9223cd
  48b2ea:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  48b2f0:	50                                              	push   eax
  48b2f1:	83 ec 08                                        	sub    esp,0x8
  48b2f4:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  48b2f9:	33 c5                                           	xor    eax,ebp
  48b2fb:	50                                              	push   eax
  48b2fc:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  48b2ff:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  48b305:	b8 01 00 00 00                                  	mov    eax,0x1
  48b30a:	c7 45 f0 a0 37 fe 00                            	mov    DWORD PTR [ebp-0x10],0xfe37a0
  48b311:	c7 05 a0 37 fe 00 8c 5a c0 00                   	mov    DWORD PTR ds:0xfe37a0,0xc05a8c
  48b31b:	c6 05 a4 37 fe 00 00                            	mov    BYTE PTR ds:0xfe37a4,0x0
  48b322:	c7 05 b0 37 fe 00 00 00 00 00                   	mov    DWORD PTR ds:0xfe37b0,0x0
  48b32c:	e8 ef 72 32 00                                  	call   0x7b2620
  48b331:	a3 ac 37 fe 00                                  	mov    ds:0xfe37ac,eax
  48b336:	89 00                                           	mov    DWORD PTR [eax],eax
  48b338:	a1 ac 37 fe 00                                  	mov    eax,ds:0xfe37ac
  48b33d:	89 40 04                                        	mov    DWORD PTR [eax+0x4],eax
  48b340:	a1 ac 37 fe 00                                  	mov    eax,ds:0xfe37ac
  48b345:	89 40 08                                        	mov    DWORD PTR [eax+0x8],eax
  48b348:	a1 ac 37 fe 00                                  	mov    eax,ds:0xfe37ac
  48b34d:	c6 40 38 01                                     	mov    BYTE PTR [eax+0x38],0x1
  48b351:	8b 0d ac 37 fe 00                               	mov    ecx,DWORD PTR ds:0xfe37ac
  48b357:	c6 41 39 01                                     	mov    BYTE PTR [ecx+0x39],0x1
  48b35b:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  48b362:	e8 c9 03 00 00                                  	call   0x48b730
  48b367:	b8 a0 37 fe 00                                  	mov    eax,0xfe37a0
  48b36c:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  48b36f:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  48b376:	59                                              	pop    ecx
  48b377:	8b e5                                           	mov    esp,ebp
  48b379:	5d                                              	pop    ebp
  48b37a:	c3                                              	ret
  48b37b:	cc                                              	int3
  48b37c:	cc                                              	int3
  48b37d:	cc                                              	int3
  48b37e:	cc                                              	int3
  48b37f:	cc                                              	int3

# 0x48b380

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048b380 <.text+0x8a380>:
  48b380:	55                                              	push   ebp
  48b381:	8b ec                                           	mov    ebp,esp
  48b383:	6a ff                                           	push   0xffffffff
  48b385:	68 d0 77 91 00                                  	push   0x9177d0
  48b38a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  48b390:	50                                              	push   eax
  48b391:	83 ec 6c                                        	sub    esp,0x6c
  48b394:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  48b399:	33 c5                                           	xor    eax,ebp
  48b39b:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  48b39e:	53                                              	push   ebx
  48b39f:	56                                              	push   esi
  48b3a0:	57                                              	push   edi
  48b3a1:	50                                              	push   eax
  48b3a2:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  48b3a5:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  48b3ab:	8b 45 0c                                        	mov    eax,DWORD PTR [ebp+0xc]
  48b3ae:	33 db                                           	xor    ebx,ebx
  48b3b0:	89 4d b4                                        	mov    DWORD PTR [ebp-0x4c],ecx
  48b3b3:	89 45 bc                                        	mov    DWORD PTR [ebp-0x44],eax
  48b3b6:	39 5d 08                                        	cmp    DWORD PTR [ebp+0x8],ebx
  48b3b9:	0f 84 45 03 00 00                               	je     0x48b704
  48b3bf:	8d 4d c0                                        	lea    ecx,[ebp-0x40]
  48b3c2:	51                                              	push   ecx
  48b3c3:	be 1c 56 c0 00                                  	mov    esi,0xc0561c
  48b3c8:	8d 45 08                                        	lea    eax,[ebp+0x8]
  48b3cb:	e8 d0 e9 28 00                                  	call   0x719da0
  48b3d0:	39 5d c0                                        	cmp    DWORD PTR [ebp-0x40],ebx
  48b3d3:	0f 84 cc 01 00 00                               	je     0x48b5a5
  48b3d9:	8d a4 24 00 00 00 00                            	lea    esp,[esp+0x0]
  48b3e0:	68 d4 d1 be 00                                  	push   0xbed1d4
  48b3e5:	8d 7d b0                                        	lea    edi,[ebp-0x50]
  48b3e8:	8d 45 c0                                        	lea    eax,[ebp-0x40]
  48b3eb:	e8 b0 06 29 00                                  	call   0x71baa0
  48b3f0:	8b 45 b0                                        	mov    eax,DWORD PTR [ebp-0x50]
  48b3f3:	3b c3                                           	cmp    eax,ebx
  48b3f5:	74 12                                           	je     0x48b409
  48b3f7:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  48b3fa:	3b c3                                           	cmp    eax,ebx
  48b3fc:	74 04                                           	je     0x48b402
  48b3fe:	8b f0                                           	mov    esi,eax
  48b400:	eb 09                                           	jmp    0x48b40b
  48b402:	be 75 23 bf 00                                  	mov    esi,0xbf2375
  48b407:	eb 02                                           	jmp    0x48b40b
  48b409:	33 f6                                           	xor    esi,esi
  48b40b:	68 24 56 c0 00                                  	push   0xc05624
  48b410:	8d 7d b8                                        	lea    edi,[ebp-0x48]
  48b413:	8d 45 c0                                        	lea    eax,[ebp-0x40]
  48b416:	e8 85 06 29 00                                  	call   0x71baa0
  48b41b:	8b 45 b8                                        	mov    eax,DWORD PTR [ebp-0x48]
  48b41e:	3b c3                                           	cmp    eax,ebx
  48b420:	74 12                                           	je     0x48b434
  48b422:	8b 40 08                                        	mov    eax,DWORD PTR [eax+0x8]
  48b425:	3b c3                                           	cmp    eax,ebx
  48b427:	74 04                                           	je     0x48b42d
  48b429:	8b f8                                           	mov    edi,eax
  48b42b:	eb 09                                           	jmp    0x48b436
  48b42d:	bf 75 23 bf 00                                  	mov    edi,0xbf2375
  48b432:	eb 02                                           	jmp    0x48b436
  48b434:	33 ff                                           	xor    edi,edi
  48b436:	3b f3                                           	cmp    esi,ebx
  48b438:	0f 84 49 01 00 00                               	je     0x48b587
  48b43e:	3b fb                                           	cmp    edi,ebx
  48b440:	0f 84 41 01 00 00                               	je     0x48b587
  48b446:	8b c7                                           	mov    eax,edi
  48b448:	8d 50 01                                        	lea    edx,[eax+0x1]
  48b44b:	eb 03                                           	jmp    0x48b450
  48b44d:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  48b450:	8a 08                                           	mov    cl,BYTE PTR [eax]
  48b452:	40                                              	inc    eax
  48b453:	3a cb                                           	cmp    cl,bl
  48b455:	75 f9                                           	jne    0x48b450
  48b457:	2b c2                                           	sub    eax,edx
  48b459:	83 f8 20                                        	cmp    eax,0x20
  48b45c:	0f 85 25 01 00 00                               	jne    0x48b587
  48b462:	8b c6                                           	mov    eax,esi
  48b464:	8d 50 01                                        	lea    edx,[eax+0x1]
  48b467:	8a 08                                           	mov    cl,BYTE PTR [eax]
  48b469:	40                                              	inc    eax
  48b46a:	3a cb                                           	cmp    cl,bl
  48b46c:	75 f9                                           	jne    0x48b467
  48b46e:	2b c2                                           	sub    eax,edx
  48b470:	83 f8 04                                        	cmp    eax,0x4
  48b473:	76 33                                           	jbe    0x48b4a8
  48b475:	8b c6                                           	mov    eax,esi
  48b477:	8d 50 01                                        	lea    edx,[eax+0x1]
  48b47a:	8d 9b 00 00 00 00                               	lea    ebx,[ebx+0x0]
  48b480:	8a 08                                           	mov    cl,BYTE PTR [eax]
  48b482:	40                                              	inc    eax
  48b483:	3a cb                                           	cmp    cl,bl
  48b485:	75 f9                                           	jne    0x48b480
  48b487:	2b c2                                           	sub    eax,edx
  48b489:	8d 54 30 fc                                     	lea    edx,[eax+esi*1-0x4]
  48b48d:	68 30 56 c0 00                                  	push   0xc05630
  48b492:	52                                              	push   edx
  48b493:	e8 19 88 40 00                                  	call   0x893cb1
  48b498:	83 c4 08                                        	add    esp,0x8
  48b49b:	85 c0                                           	test   eax,eax
  48b49d:	75 09                                           	jne    0x48b4a8
  48b49f:	8d 45 98                                        	lea    eax,[ebp-0x68]
  48b4a2:	50                                              	push   eax
  48b4a3:	e9 e3 00 00 00                                  	jmp    0x48b58b
  48b4a8:	8b 45 bc                                        	mov    eax,DWORD PTR [ebp-0x44]
  48b4ab:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  48b4b2:	89 5d e4                                        	mov    DWORD PTR [ebp-0x1c],ebx
  48b4b5:	88 5d d4                                        	mov    BYTE PTR [ebp-0x2c],bl
  48b4b8:	8d 50 01                                        	lea    edx,[eax+0x1]
  48b4bb:	eb 03                                           	jmp    0x48b4c0
  48b4bd:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  48b4c0:	8a 08                                           	mov    cl,BYTE PTR [eax]
  48b4c2:	40                                              	inc    eax
  48b4c3:	3a cb                                           	cmp    cl,bl
  48b4c5:	75 f9                                           	jne    0x48b4c0
  48b4c7:	8b 4d bc                                        	mov    ecx,DWORD PTR [ebp-0x44]
  48b4ca:	2b c2                                           	sub    eax,edx
  48b4cc:	50                                              	push   eax
  48b4cd:	51                                              	push   ecx
  48b4ce:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b4d1:	e8 9a 75 f7 ff                                  	call   0x402a70
  48b4d6:	8b c6                                           	mov    eax,esi
  48b4d8:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  48b4db:	8d 50 01                                        	lea    edx,[eax+0x1]
  48b4de:	8b ff                                           	mov    edi,edi
  48b4e0:	8a 08                                           	mov    cl,BYTE PTR [eax]
  48b4e2:	40                                              	inc    eax
  48b4e3:	3a cb                                           	cmp    cl,bl
  48b4e5:	75 f9                                           	jne    0x48b4e0
  48b4e7:	2b c2                                           	sub    eax,edx
  48b4e9:	50                                              	push   eax
  48b4ea:	56                                              	push   esi
  48b4eb:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b4ee:	e8 cd 6a f7 ff                                  	call   0x401fc0
  48b4f3:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  48b4f7:	8b 4d d4                                        	mov    ecx,DWORD PTR [ebp-0x2c]
  48b4fa:	73 03                                           	jae    0x48b4ff
  48b4fc:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b4ff:	8d 55 d4                                        	lea    edx,[ebp-0x2c]
  48b502:	52                                              	push   edx
  48b503:	e8 b8 03 00 00                                  	call   0x48b8c0
  48b508:	33 f6                                           	xor    esi,esi
  48b50a:	8d 9b 00 00 00 00                               	lea    ebx,[ebx+0x0]
  48b510:	0f be 4c 77 01                                  	movsx  ecx,BYTE PTR [edi+esi*2+0x1]
  48b515:	0f be 04 77                                     	movsx  eax,BYTE PTR [edi+esi*2]
  48b519:	e8 92 fc 00 00                                  	call   0x49b1b0
  48b51e:	88 44 35 c4                                     	mov    BYTE PTR [ebp+esi*1-0x3c],al
  48b522:	46                                              	inc    esi
  48b523:	83 fe 10                                        	cmp    esi,0x10
  48b526:	7c e8                                           	jl     0x48b510
  48b528:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  48b52b:	bf 10 00 00 00                                  	mov    edi,0x10
  48b530:	39 7d e8                                        	cmp    DWORD PTR [ebp-0x18],edi
  48b533:	73 03                                           	jae    0x48b538
  48b535:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  48b538:	8b 4d c8                                        	mov    ecx,DWORD PTR [ebp-0x38]
  48b53b:	8b 75 b4                                        	mov    esi,DWORD PTR [ebp-0x4c]
  48b53e:	8b 55 cc                                        	mov    edx,DWORD PTR [ebp-0x34]
  48b541:	89 45 9c                                        	mov    DWORD PTR [ebp-0x64],eax
  48b544:	8b 45 c4                                        	mov    eax,DWORD PTR [ebp-0x3c]
  48b547:	89 4d a4                                        	mov    DWORD PTR [ebp-0x5c],ecx
  48b54a:	8d 4d 9c                                        	lea    ecx,[ebp-0x64]
  48b54d:	89 45 a0                                        	mov    DWORD PTR [ebp-0x60],eax
  48b550:	8b 45 d0                                        	mov    eax,DWORD PTR [ebp-0x30]
  48b553:	83 c6 08                                        	add    esi,0x8
  48b556:	51                                              	push   ecx
  48b557:	8b ce                                           	mov    ecx,esi
  48b559:	89 55 a8                                        	mov    DWORD PTR [ebp-0x58],edx
  48b55c:	89 45 ac                                        	mov    DWORD PTR [ebp-0x54],eax
  48b55f:	e8 3c dd 00 00                                  	call   0x4992a0
  48b564:	50                                              	push   eax
  48b565:	8d 55 8c                                        	lea    edx,[ebp-0x74]
  48b568:	52                                              	push   edx
  48b569:	56                                              	push   esi
  48b56a:	e8 11 da 00 00                                  	call   0x498f80
  48b56f:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  48b576:	39 7d e8                                        	cmp    DWORD PTR [ebp-0x18],edi
  48b579:	72 0c                                           	jb     0x48b587
  48b57b:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  48b57e:	50                                              	push   eax
  48b57f:	e8 88 5c 40 00                                  	call   0x89120c
  48b584:	83 c4 04                                        	add    esp,0x4
  48b587:	8d 4d 94                                        	lea    ecx,[ebp-0x6c]
  48b58a:	51                                              	push   ecx
  48b58b:	be 1c 56 c0 00                                  	mov    esi,0xc0561c
  48b590:	8d 45 c0                                        	lea    eax,[ebp-0x40]
  48b593:	e8 68 e8 28 00                                  	call   0x719e00
  48b598:	8b 00                                           	mov    eax,DWORD PTR [eax]
  48b59a:	89 45 c0                                        	mov    DWORD PTR [ebp-0x40],eax
  48b59d:	3b c3                                           	cmp    eax,ebx
  48b59f:	0f 85 3b fe ff ff                               	jne    0x48b3e0
  48b5a5:	8d 55 b8                                        	lea    edx,[ebp-0x48]
  48b5a8:	52                                              	push   edx
  48b5a9:	be 38 56 c0 00                                  	mov    esi,0xc05638
  48b5ae:	8d 45 08                                        	lea    eax,[ebp+0x8]
  48b5b1:	e8 ea e7 28 00                                  	call   0x719da0
  48b5b6:	8b 7d b8                                        	mov    edi,DWORD PTR [ebp-0x48]
  48b5b9:	3b fb                                           	cmp    edi,ebx
  48b5bb:	0f 84 43 01 00 00                               	je     0x48b704
  48b5c1:	3b fb                                           	cmp    edi,ebx
  48b5c3:	0f 84 2f 01 00 00                               	je     0x48b6f8
  48b5c9:	8b 77 1c                                        	mov    esi,DWORD PTR [edi+0x1c]
  48b5cc:	3b f3                                           	cmp    esi,ebx
  48b5ce:	0f 84 bd 00 00 00                               	je     0x48b691
  48b5d4:	8b 46 04                                        	mov    eax,DWORD PTR [esi+0x4]
  48b5d7:	3b c3                                           	cmp    eax,ebx
  48b5d9:	74 12                                           	je     0x48b5ed
  48b5db:	50                                              	push   eax
  48b5dc:	68 d4 d1 be 00                                  	push   0xbed1d4
  48b5e1:	e8 cb 86 40 00                                  	call   0x893cb1
  48b5e6:	83 c4 08                                        	add    esp,0x8
  48b5e9:	85 c0                                           	test   eax,eax
  48b5eb:	74 0c                                           	je     0x48b5f9
  48b5ed:	8b 76 10                                        	mov    esi,DWORD PTR [esi+0x10]
  48b5f0:	3b f3                                           	cmp    esi,ebx
  48b5f2:	75 e0                                           	jne    0x48b5d4
  48b5f4:	e9 98 00 00 00                                  	jmp    0x48b691
  48b5f9:	8b 76 08                                        	mov    esi,DWORD PTR [esi+0x8]
  48b5fc:	3b f3                                           	cmp    esi,ebx
  48b5fe:	75 05                                           	jne    0x48b605
  48b600:	be 75 23 bf 00                                  	mov    esi,0xbf2375
  48b605:	8b 45 bc                                        	mov    eax,DWORD PTR [ebp-0x44]
  48b608:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  48b60f:	89 5d e4                                        	mov    DWORD PTR [ebp-0x1c],ebx
  48b612:	88 5d d4                                        	mov    BYTE PTR [ebp-0x2c],bl
  48b615:	8d 50 01                                        	lea    edx,[eax+0x1]
  48b618:	8a 08                                           	mov    cl,BYTE PTR [eax]
  48b61a:	40                                              	inc    eax
  48b61b:	3a cb                                           	cmp    cl,bl
  48b61d:	75 f9                                           	jne    0x48b618
  48b61f:	2b c2                                           	sub    eax,edx
  48b621:	50                                              	push   eax
  48b622:	8b 45 bc                                        	mov    eax,DWORD PTR [ebp-0x44]
  48b625:	50                                              	push   eax
  48b626:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b629:	e8 42 74 f7 ff                                  	call   0x402a70
  48b62e:	8b c6                                           	mov    eax,esi
  48b630:	c7 45 fc 01 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x1
  48b637:	8d 50 01                                        	lea    edx,[eax+0x1]
  48b63a:	8d 9b 00 00 00 00                               	lea    ebx,[ebx+0x0]
  48b640:	8a 08                                           	mov    cl,BYTE PTR [eax]
  48b642:	40                                              	inc    eax
  48b643:	3a cb                                           	cmp    cl,bl
  48b645:	75 f9                                           	jne    0x48b640
  48b647:	2b c2                                           	sub    eax,edx
  48b649:	50                                              	push   eax
  48b64a:	56                                              	push   esi
  48b64b:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b64e:	e8 6d 69 f7 ff                                  	call   0x401fc0
  48b653:	6a 01                                           	push   0x1
  48b655:	68 e4 d1 be 00                                  	push   0xbed1e4
  48b65a:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b65d:	e8 5e 69 f7 ff                                  	call   0x401fc0
  48b662:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  48b666:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  48b669:	73 03                                           	jae    0x48b66e
  48b66b:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  48b66e:	8b 4d b4                                        	mov    ecx,DWORD PTR [ebp-0x4c]
  48b671:	50                                              	push   eax
  48b672:	57                                              	push   edi
  48b673:	e8 08 fd ff ff                                  	call   0x48b380
  48b678:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  48b67f:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  48b683:	72 0c                                           	jb     0x48b691
  48b685:	8b 4d d4                                        	mov    ecx,DWORD PTR [ebp-0x2c]
  48b688:	51                                              	push   ecx
  48b689:	e8 7e 5b 40 00                                  	call   0x89120c
  48b68e:	83 c4 04                                        	add    esp,0x4
  48b691:	8b 77 18                                        	mov    esi,DWORD PTR [edi+0x18]
  48b694:	3b f3                                           	cmp    esi,ebx
  48b696:	74 60                                           	je     0x48b6f8
  48b698:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  48b69b:	3b c3                                           	cmp    eax,ebx
  48b69d:	74 12                                           	je     0x48b6b1
  48b69f:	50                                              	push   eax
  48b6a0:	68 38 56 c0 00                                  	push   0xc05638
  48b6a5:	e8 07 86 40 00                                  	call   0x893cb1
  48b6aa:	83 c4 08                                        	add    esp,0x8
  48b6ad:	85 c0                                           	test   eax,eax
  48b6af:	74 09                                           	je     0x48b6ba
  48b6b1:	8b 76 18                                        	mov    esi,DWORD PTR [esi+0x18]
  48b6b4:	3b f3                                           	cmp    esi,ebx
  48b6b6:	75 e0                                           	jne    0x48b698
  48b6b8:	eb 3e                                           	jmp    0x48b6f8
  48b6ba:	8b c6                                           	mov    eax,esi
  48b6bc:	3b c3                                           	cmp    eax,ebx
  48b6be:	74 32                                           	je     0x48b6f2
  48b6c0:	8b 08                                           	mov    ecx,DWORD PTR [eax]
  48b6c2:	83 e1 07                                        	and    ecx,0x7
  48b6c5:	41                                              	inc    ecx
  48b6c6:	83 f9 02                                        	cmp    ecx,0x2
  48b6c9:	74 2f                                           	je     0x48b6fa
  48b6cb:	8b 70 18                                        	mov    esi,DWORD PTR [eax+0x18]
  48b6ce:	3b f3                                           	cmp    esi,ebx
  48b6d0:	74 20                                           	je     0x48b6f2
  48b6d2:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  48b6d5:	3b c3                                           	cmp    eax,ebx
  48b6d7:	74 12                                           	je     0x48b6eb
  48b6d9:	50                                              	push   eax
  48b6da:	68 38 56 c0 00                                  	push   0xc05638
  48b6df:	e8 cd 85 40 00                                  	call   0x893cb1
  48b6e4:	83 c4 08                                        	add    esp,0x8
  48b6e7:	85 c0                                           	test   eax,eax
  48b6e9:	74 37                                           	je     0x48b722
  48b6eb:	8b 76 18                                        	mov    esi,DWORD PTR [esi+0x18]
  48b6ee:	3b f3                                           	cmp    esi,ebx
  48b6f0:	75 e0                                           	jne    0x48b6d2
  48b6f2:	33 c0                                           	xor    eax,eax
  48b6f4:	3b c3                                           	cmp    eax,ebx
  48b6f6:	75 c8                                           	jne    0x48b6c0
  48b6f8:	33 c0                                           	xor    eax,eax
  48b6fa:	8b f8                                           	mov    edi,eax
  48b6fc:	3b c3                                           	cmp    eax,ebx
  48b6fe:	0f 85 bd fe ff ff                               	jne    0x48b5c1
  48b704:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  48b707:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  48b70e:	59                                              	pop    ecx
  48b70f:	5f                                              	pop    edi
  48b710:	5e                                              	pop    esi
  48b711:	5b                                              	pop    ebx
  48b712:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  48b715:	33 cd                                           	xor    ecx,ebp
  48b717:	e8 e5 58 40 00                                  	call   0x891001
  48b71c:	8b e5                                           	mov    esp,ebp
  48b71e:	5d                                              	pop    ebp
  48b71f:	c2 08 00                                        	ret    0x8
  48b722:	8b c6                                           	mov    eax,esi
  48b724:	eb ce                                           	jmp    0x48b6f4
  48b726:	cc                                              	int3
  48b727:	cc                                              	int3
  48b728:	cc                                              	int3
  48b729:	cc                                              	int3
  48b72a:	cc                                              	int3
  48b72b:	cc                                              	int3
  48b72c:	cc                                              	int3
  48b72d:	cc                                              	int3
  48b72e:	cc                                              	int3
  48b72f:	cc                                              	int3

# 0x48b730

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048b730 <.text+0x8a730>:
  48b730:	55                                              	push   ebp
  48b731:	8b ec                                           	mov    ebp,esp
  48b733:	6a ff                                           	push   0xffffffff
  48b735:	68 93 23 92 00                                  	push   0x922393
  48b73a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  48b740:	50                                              	push   eax
  48b741:	81 ec 14 01 00 00                               	sub    esp,0x114
  48b747:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  48b74c:	33 c5                                           	xor    eax,ebp
  48b74e:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  48b751:	53                                              	push   ebx
  48b752:	56                                              	push   esi
  48b753:	57                                              	push   edi
  48b754:	50                                              	push   eax
  48b755:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  48b758:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  48b75e:	33 db                                           	xor    ebx,ebx
  48b760:	8d b5 e8 fe ff ff                               	lea    esi,[ebp-0x118]
  48b766:	89 9d e8 fe ff ff                               	mov    DWORD PTR [ebp-0x118],ebx
  48b76c:	89 9d ec fe ff ff                               	mov    DWORD PTR [ebp-0x114],ebx
  48b772:	e8 a9 04 29 00                                  	call   0x71bc20
  48b777:	b8 0f 00 00 00                                  	mov    eax,0xf
  48b77c:	88 5d b0                                        	mov    BYTE PTR [ebp-0x50],bl
  48b77f:	89 45 c8                                        	mov    DWORD PTR [ebp-0x38],eax
  48b782:	89 5d c4                                        	mov    DWORD PTR [ebp-0x3c],ebx
  48b785:	88 5d b4                                        	mov    BYTE PTR [ebp-0x4c],bl
  48b788:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  48b78b:	6a 0d                                           	push   0xd
  48b78d:	68 40 56 c0 00                                  	push   0xc05640
  48b792:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b795:	89 45 e8                                        	mov    DWORD PTR [ebp-0x18],eax
  48b798:	89 5d e4                                        	mov    DWORD PTR [ebp-0x1c],ebx
  48b79b:	88 5d d4                                        	mov    BYTE PTR [ebp-0x2c],bl
  48b79e:	e8 cd 72 f7 ff                                  	call   0x402a70
  48b7a3:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  48b7a7:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  48b7ab:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  48b7ae:	73 03                                           	jae    0x48b7b3
  48b7b0:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  48b7b3:	68 e0 d1 be 00                                  	push   0xbed1e0
  48b7b8:	50                                              	push   eax
  48b7b9:	e8 b2 8f 28 00                                  	call   0x714770
  48b7be:	8b f8                                           	mov    edi,eax
  48b7c0:	83 c4 08                                        	add    esp,0x8
  48b7c3:	3b fb                                           	cmp    edi,ebx
  48b7c5:	75 04                                           	jne    0x48b7cb
  48b7c7:	32 db                                           	xor    bl,bl
  48b7c9:	eb 2e                                           	jmp    0x48b7f9
  48b7cb:	8b 07                                           	mov    eax,DWORD PTR [edi]
  48b7cd:	8b 50 38                                        	mov    edx,DWORD PTR [eax+0x38]
  48b7d0:	8b cf                                           	mov    ecx,edi
  48b7d2:	ff d2                                           	call   edx
  48b7d4:	8b f0                                           	mov    esi,eax
  48b7d6:	8b 07                                           	mov    eax,DWORD PTR [edi]
  48b7d8:	8b 50 2c                                        	mov    edx,DWORD PTR [eax+0x2c]
  48b7db:	8b cf                                           	mov    ecx,edi
  48b7dd:	ff d2                                           	call   edx
  48b7df:	50                                              	push   eax
  48b7e0:	8d 8d e8 fe ff ff                               	lea    ecx,[ebp-0x118]
  48b7e6:	e8 55 db 00 00                                  	call   0x499340
  48b7eb:	8a d8                                           	mov    bl,al
  48b7ed:	8b 07                                           	mov    eax,DWORD PTR [edi]
  48b7ef:	8b 50 04                                        	mov    edx,DWORD PTR [eax+0x4]
  48b7f2:	83 c4 04                                        	add    esp,0x4
  48b7f5:	8b cf                                           	mov    ecx,edi
  48b7f7:	ff d2                                           	call   edx
  48b7f9:	c6 45 fc 00                                     	mov    BYTE PTR [ebp-0x4],0x0
  48b7fd:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  48b801:	72 0c                                           	jb     0x48b80f
  48b803:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  48b806:	50                                              	push   eax
  48b807:	e8 00 5a 40 00                                  	call   0x89120c
  48b80c:	83 c4 04                                        	add    esp,0x4
  48b80f:	84 db                                           	test   bl,bl
  48b811:	74 53                                           	je     0x48b866
  48b813:	8b 8d e8 fe ff ff                               	mov    ecx,DWORD PTR [ebp-0x118]
  48b819:	68 80 55 c0 00                                  	push   0xc05580
  48b81e:	8d bd e0 fe ff ff                               	lea    edi,[ebp-0x120]
  48b824:	8d 85 e4 fe ff ff                               	lea    eax,[ebp-0x11c]
  48b82a:	89 8d e4 fe ff ff                               	mov    DWORD PTR [ebp-0x11c],ecx
  48b830:	e8 0b 02 29 00                                  	call   0x71ba40
  48b835:	8b 10                                           	mov    edx,DWORD PTR [eax]
  48b837:	8d 85 e0 fe ff ff                               	lea    eax,[ebp-0x120]
  48b83d:	50                                              	push   eax
  48b83e:	be 38 56 c0 00                                  	mov    esi,0xc05638
  48b843:	8d 85 e4 fe ff ff                               	lea    eax,[ebp-0x11c]
  48b849:	89 95 e4 fe ff ff                               	mov    DWORD PTR [ebp-0x11c],edx
  48b84f:	e8 4c e5 28 00                                  	call   0x719da0
  48b854:	8b 08                                           	mov    ecx,DWORD PTR [eax]
  48b856:	68 75 23 bf 00                                  	push   0xbf2375
  48b85b:	51                                              	push   ecx
  48b85c:	b9 a0 37 fe 00                                  	mov    ecx,0xfe37a0
  48b861:	e8 1a fb ff ff                                  	call   0x48b380
  48b866:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  48b86d:	83 7d c8 10                                     	cmp    DWORD PTR [ebp-0x38],0x10
  48b871:	72 0c                                           	jb     0x48b87f
  48b873:	8b 55 b4                                        	mov    edx,DWORD PTR [ebp-0x4c]
  48b876:	52                                              	push   edx
  48b877:	e8 90 59 40 00                                  	call   0x89120c
  48b87c:	83 c4 04                                        	add    esp,0x4
  48b87f:	8d 85 e8 fe ff ff                               	lea    eax,[ebp-0x118]
  48b885:	50                                              	push   eax
  48b886:	c7 45 c8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x38],0xf
  48b88d:	c7 45 c4 00 00 00 00                            	mov    DWORD PTR [ebp-0x3c],0x0
  48b894:	c6 45 b4 00                                     	mov    BYTE PTR [ebp-0x4c],0x0
  48b898:	e8 f3 03 29 00                                  	call   0x71bc90
  48b89d:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  48b8a0:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  48b8a7:	59                                              	pop    ecx
  48b8a8:	5f                                              	pop    edi
  48b8a9:	5e                                              	pop    esi
  48b8aa:	5b                                              	pop    ebx
  48b8ab:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  48b8ae:	33 cd                                           	xor    ecx,ebp
  48b8b0:	e8 4c 57 40 00                                  	call   0x891001
  48b8b5:	8b e5                                           	mov    esp,ebp
  48b8b7:	5d                                              	pop    ebp
  48b8b8:	c3                                              	ret
  48b8b9:	cc                                              	int3
  48b8ba:	cc                                              	int3
  48b8bb:	cc                                              	int3
  48b8bc:	cc                                              	int3
  48b8bd:	cc                                              	int3
  48b8be:	cc                                              	int3
  48b8bf:	cc                                              	int3

# 0x48b8c0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048b8c0 <.text+0x8a8c0>:
  48b8c0:	55                                              	push   ebp
  48b8c1:	8b ec                                           	mov    ebp,esp
  48b8c3:	6a ff                                           	push   0xffffffff
  48b8c5:	68 28 7e 91 00                                  	push   0x917e28
  48b8ca:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  48b8d0:	50                                              	push   eax
  48b8d1:	83 ec 24                                        	sub    esp,0x24
  48b8d4:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  48b8d9:	33 c5                                           	xor    eax,ebp
  48b8db:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  48b8de:	56                                              	push   esi
  48b8df:	57                                              	push   edi
  48b8e0:	50                                              	push   eax
  48b8e1:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  48b8e4:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  48b8ea:	8b 45 08                                        	mov    eax,DWORD PTR [ebp+0x8]
  48b8ed:	89 45 d0                                        	mov    DWORD PTR [ebp-0x30],eax
  48b8f0:	8b c1                                           	mov    eax,ecx
  48b8f2:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  48b8f9:	c7 45 e4 00 00 00 00                            	mov    DWORD PTR [ebp-0x1c],0x0
  48b900:	c6 45 d4 00                                     	mov    BYTE PTR [ebp-0x2c],0x0
  48b904:	8d 70 01                                        	lea    esi,[eax+0x1]
  48b907:	8a 10                                           	mov    dl,BYTE PTR [eax]
  48b909:	40                                              	inc    eax
  48b90a:	84 d2                                           	test   dl,dl
  48b90c:	75 f9                                           	jne    0x48b907
  48b90e:	2b c6                                           	sub    eax,esi
  48b910:	50                                              	push   eax
  48b911:	51                                              	push   ecx
  48b912:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b915:	e8 56 71 f7 ff                                  	call   0x402a70
  48b91a:	33 f6                                           	xor    esi,esi
  48b91c:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  48b923:	39 75 e4                                        	cmp    DWORD PTR [ebp-0x1c],esi
  48b926:	76 46                                           	jbe    0x48b96e
  48b928:	8b 55 e8                                        	mov    edx,DWORD PTR [ebp-0x18]
  48b92b:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  48b92e:	8b c8                                           	mov    ecx,eax
  48b930:	83 fa 10                                        	cmp    edx,0x10
  48b933:	73 03                                           	jae    0x48b938
  48b935:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b938:	80 3c 31 5c                                     	cmp    BYTE PTR [ecx+esi*1],0x5c
  48b93c:	75 0e                                           	jne    0x48b94c
  48b93e:	83 fa 10                                        	cmp    edx,0x10
  48b941:	73 03                                           	jae    0x48b946
  48b943:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  48b946:	c6 04 30 2f                                     	mov    BYTE PTR [eax+esi*1],0x2f
  48b94a:	eb 1c                                           	jmp    0x48b968
  48b94c:	8b c8                                           	mov    ecx,eax
  48b94e:	83 fa 10                                        	cmp    edx,0x10
  48b951:	73 5a                                           	jae    0x48b9ad
  48b953:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48b956:	8b f9                                           	mov    edi,ecx
  48b958:	0f be 0c 31                                     	movsx  ecx,BYTE PTR [ecx+esi*1]
  48b95c:	51                                              	push   ecx
  48b95d:	e8 ab 84 40 00                                  	call   0x893e0d
  48b962:	83 c4 04                                        	add    esp,0x4
  48b965:	88 04 37                                        	mov    BYTE PTR [edi+esi*1],al
  48b968:	46                                              	inc    esi
  48b969:	3b 75 e4                                        	cmp    esi,DWORD PTR [ebp-0x1c]
  48b96c:	72 ba                                           	jb     0x48b928
  48b96e:	8b 4d d0                                        	mov    ecx,DWORD PTR [ebp-0x30]
  48b971:	6a ff                                           	push   0xffffffff
  48b973:	6a 00                                           	push   0x0
  48b975:	8d 55 d4                                        	lea    edx,[ebp-0x2c]
  48b978:	52                                              	push   edx
  48b979:	e8 c2 76 f7 ff                                  	call   0x403040
  48b97e:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  48b982:	72 0c                                           	jb     0x48b990
  48b984:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  48b987:	50                                              	push   eax
  48b988:	e8 7f 58 40 00                                  	call   0x89120c
  48b98d:	83 c4 04                                        	add    esp,0x4
  48b990:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  48b993:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  48b99a:	59                                              	pop    ecx
  48b99b:	5f                                              	pop    edi
  48b99c:	5e                                              	pop    esi
  48b99d:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  48b9a0:	33 cd                                           	xor    ecx,ebp
  48b9a2:	e8 5a 56 40 00                                  	call   0x891001
  48b9a7:	8b e5                                           	mov    esp,ebp
  48b9a9:	5d                                              	pop    ebp
  48b9aa:	c2 04 00                                        	ret    0x4
  48b9ad:	8b f8                                           	mov    edi,eax
  48b9af:	eb a7                                           	jmp    0x48b958
  48b9b1:	cc                                              	int3
  48b9b2:	cc                                              	int3
  48b9b3:	cc                                              	int3
  48b9b4:	cc                                              	int3
  48b9b5:	cc                                              	int3
  48b9b6:	cc                                              	int3
  48b9b7:	cc                                              	int3
  48b9b8:	cc                                              	int3
  48b9b9:	cc                                              	int3
  48b9ba:	cc                                              	int3
  48b9bb:	cc                                              	int3
  48b9bc:	cc                                              	int3
  48b9bd:	cc                                              	int3
  48b9be:	cc                                              	int3
  48b9bf:	cc                                              	int3

# 0x48b9c0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048b9c0 <.text+0x8a9c0>:
  48b9c0:	55                                              	push   ebp
  48b9c1:	8b ec                                           	mov    ebp,esp
  48b9c3:	6a ff                                           	push   0xffffffff
  48b9c5:	68 a0 b7 91 00                                  	push   0x91b7a0
  48b9ca:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  48b9d0:	50                                              	push   eax
  48b9d1:	83 ec 48                                        	sub    esp,0x48
  48b9d4:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  48b9d9:	33 c5                                           	xor    eax,ebp
  48b9db:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  48b9de:	53                                              	push   ebx
  48b9df:	56                                              	push   esi
  48b9e0:	57                                              	push   edi
  48b9e1:	50                                              	push   eax
  48b9e2:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  48b9e5:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  48b9eb:	8b 7d 0c                                        	mov    edi,DWORD PTR [ebp+0xc]
  48b9ee:	33 db                                           	xor    ebx,ebx
  48b9f0:	be 0f 00 00 00                                  	mov    esi,0xf
  48b9f5:	89 4d b4                                        	mov    DWORD PTR [ebp-0x4c],ecx
  48b9f8:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  48b9fb:	89 75 e8                                        	mov    DWORD PTR [ebp-0x18],esi
  48b9fe:	89 5d e4                                        	mov    DWORD PTR [ebp-0x1c],ebx
  48ba01:	88 5d d4                                        	mov    BYTE PTR [ebp-0x2c],bl
  48ba04:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  48ba07:	50                                              	push   eax
  48ba08:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  48ba0b:	e8 b0 fe ff ff                                  	call   0x48b8c0
  48ba10:	8b 4d e4                                        	mov    ecx,DWORD PTR [ebp-0x1c]
  48ba13:	83 f9 04                                        	cmp    ecx,0x4
  48ba16:	76 1c                                           	jbe    0x48ba34
  48ba18:	6a 04                                           	push   0x4
  48ba1a:	68 50 56 c0 00                                  	push   0xc05650
  48ba1f:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  48ba22:	51                                              	push   ecx
  48ba23:	33 c0                                           	xor    eax,eax
  48ba25:	e8 06 4f fb ff                                  	call   0x440930
  48ba2a:	8b 4d e4                                        	mov    ecx,DWORD PTR [ebp-0x1c]
  48ba2d:	8d 51 fc                                        	lea    edx,[ecx-0x4]
  48ba30:	3b c2                                           	cmp    eax,edx
  48ba32:	74 21                                           	je     0x48ba55
  48ba34:	83 f9 06                                        	cmp    ecx,0x6
  48ba37:	72 25                                           	jb     0x48ba5e
  48ba39:	6a 06                                           	push   0x6
  48ba3b:	68 58 56 c0 00                                  	push   0xc05658
  48ba40:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  48ba43:	50                                              	push   eax
  48ba44:	33 c0                                           	xor    eax,eax
  48ba46:	e8 e5 4e fb ff                                  	call   0x440930
  48ba4b:	8b 4d e4                                        	mov    ecx,DWORD PTR [ebp-0x1c]
  48ba4e:	83 c1 fa                                        	add    ecx,0xfffffffa
  48ba51:	3b c1                                           	cmp    eax,ecx
  48ba53:	75 09                                           	jne    0x48ba5e
  48ba55:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  48ba59:	e9 d3 00 00 00                                  	jmp    0x48bb31
  48ba5e:	83 7d e8 10                                     	cmp    DWORD PTR [ebp-0x18],0x10
  48ba62:	8b 55 d4                                        	mov    edx,DWORD PTR [ebp-0x2c]
  48ba65:	73 03                                           	jae    0x48ba6a
  48ba67:	8d 55 d4                                        	lea    edx,[ebp-0x2c]
  48ba6a:	8b c2                                           	mov    eax,edx
  48ba6c:	89 75 cc                                        	mov    DWORD PTR [ebp-0x34],esi
  48ba6f:	89 5d c8                                        	mov    DWORD PTR [ebp-0x38],ebx
  48ba72:	88 5d b8                                        	mov    BYTE PTR [ebp-0x48],bl
  48ba75:	8d 70 01                                        	lea    esi,[eax+0x1]
  48ba78:	8a 08                                           	mov    cl,BYTE PTR [eax]
  48ba7a:	40                                              	inc    eax
  48ba7b:	3a cb                                           	cmp    cl,bl
  48ba7d:	75 f9                                           	jne    0x48ba78
  48ba7f:	2b c6                                           	sub    eax,esi
  48ba81:	50                                              	push   eax
  48ba82:	52                                              	push   edx
  48ba83:	8d 4d b8                                        	lea    ecx,[ebp-0x48]
  48ba86:	e8 e5 6f f7 ff                                  	call   0x402a70
  48ba8b:	8b 75 b4                                        	mov    esi,DWORD PTR [ebp-0x4c]
  48ba8e:	8d 45 b8                                        	lea    eax,[ebp-0x48]
  48ba91:	50                                              	push   eax
  48ba92:	8d 46 08                                        	lea    eax,[esi+0x8]
  48ba95:	c6 45 fc 01                                     	mov    BYTE PTR [ebp-0x4],0x1
  48ba99:	e8 52 cd 00 00                                  	call   0x4987f0
  48ba9e:	89 45 ac                                        	mov    DWORD PTR [ebp-0x54],eax
  48baa1:	3b 46 0c                                        	cmp    eax,DWORD PTR [esi+0xc]
  48baa4:	74 14                                           	je     0x48baba
  48baa6:	83 c0 0c                                        	add    eax,0xc
  48baa9:	8d 55 b8                                        	lea    edx,[ebp-0x48]
  48baac:	e8 7f f3 00 00                                  	call   0x49ae30
  48bab1:	84 c0                                           	test   al,al
  48bab3:	75 05                                           	jne    0x48baba
  48bab5:	8d 45 ac                                        	lea    eax,[ebp-0x54]
  48bab8:	eb 09                                           	jmp    0x48bac3
  48baba:	8b 4e 0c                                        	mov    ecx,DWORD PTR [esi+0xc]
  48babd:	89 4d b0                                        	mov    DWORD PTR [ebp-0x50],ecx
  48bac0:	8d 45 b0                                        	lea    eax,[ebp-0x50]
  48bac3:	8b 30                                           	mov    esi,DWORD PTR [eax]
  48bac5:	b9 10 00 00 00                                  	mov    ecx,0x10
  48baca:	39 4d cc                                        	cmp    DWORD PTR [ebp-0x34],ecx
  48bacd:	72 11                                           	jb     0x48bae0
  48bacf:	8b 55 b8                                        	mov    edx,DWORD PTR [ebp-0x48]
  48bad2:	52                                              	push   edx
  48bad3:	e8 34 57 40 00                                  	call   0x89120c
  48bad8:	83 c4 04                                        	add    esp,0x4
  48badb:	b9 10 00 00 00                                  	mov    ecx,0x10
  48bae0:	8b 45 b4                                        	mov    eax,DWORD PTR [ebp-0x4c]
  48bae3:	c7 45 cc 0f 00 00 00                            	mov    DWORD PTR [ebp-0x34],0xf
  48baea:	89 5d c8                                        	mov    DWORD PTR [ebp-0x38],ebx
  48baed:	88 5d b8                                        	mov    BYTE PTR [ebp-0x48],bl
  48baf0:	3b 70 0c                                        	cmp    esi,DWORD PTR [eax+0xc]
  48baf3:	74 2c                                           	je     0x48bb21
  48baf5:	8b 56 28                                        	mov    edx,DWORD PTR [esi+0x28]
  48baf8:	89 17                                           	mov    DWORD PTR [edi],edx
  48bafa:	8b 46 2c                                        	mov    eax,DWORD PTR [esi+0x2c]
  48bafd:	89 47 04                                        	mov    DWORD PTR [edi+0x4],eax
  48bb00:	8b 56 30                                        	mov    edx,DWORD PTR [esi+0x30]
  48bb03:	89 57 08                                        	mov    DWORD PTR [edi+0x8],edx
  48bb06:	8b 46 34                                        	mov    eax,DWORD PTR [esi+0x34]
  48bb09:	89 47 0c                                        	mov    DWORD PTR [edi+0xc],eax
  48bb0c:	39 4d e8                                        	cmp    DWORD PTR [ebp-0x18],ecx
  48bb0f:	72 0c                                           	jb     0x48bb1d
  48bb11:	8b 4d d4                                        	mov    ecx,DWORD PTR [ebp-0x2c]
  48bb14:	51                                              	push   ecx
  48bb15:	e8 f2 56 40 00                                  	call   0x89120c
  48bb1a:	83 c4 04                                        	add    esp,0x4
  48bb1d:	b0 01                                           	mov    al,0x1
  48bb1f:	eb 20                                           	jmp    0x48bb41
  48bb21:	33 c0                                           	xor    eax,eax
  48bb23:	39 4d e8                                        	cmp    DWORD PTR [ebp-0x18],ecx
  48bb26:	89 07                                           	mov    DWORD PTR [edi],eax
  48bb28:	89 47 04                                        	mov    DWORD PTR [edi+0x4],eax
  48bb2b:	89 47 08                                        	mov    DWORD PTR [edi+0x8],eax
  48bb2e:	89 47 0c                                        	mov    DWORD PTR [edi+0xc],eax
  48bb31:	72 0c                                           	jb     0x48bb3f
  48bb33:	8b 55 d4                                        	mov    edx,DWORD PTR [ebp-0x2c]
  48bb36:	52                                              	push   edx
  48bb37:	e8 d0 56 40 00                                  	call   0x89120c
  48bb3c:	83 c4 04                                        	add    esp,0x4
  48bb3f:	32 c0                                           	xor    al,al
  48bb41:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  48bb44:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  48bb4b:	59                                              	pop    ecx
  48bb4c:	5f                                              	pop    edi
  48bb4d:	5e                                              	pop    esi
  48bb4e:	5b                                              	pop    ebx
  48bb4f:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  48bb52:	33 cd                                           	xor    ecx,ebp
  48bb54:	e8 a8 54 40 00                                  	call   0x891001
  48bb59:	8b e5                                           	mov    esp,ebp
  48bb5b:	5d                                              	pop    ebp
  48bb5c:	c2 08 00                                        	ret    0x8
  48bb5f:	cc                                              	int3

# 0x48bb80

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048bb80 <.text+0x8ab80>:
  48bb80:	55                                              	push   ebp
  48bb81:	8b ec                                           	mov    ebp,esp
  48bb83:	83 e4 f8                                        	and    esp,0xfffffff8
  48bb86:	81 ec 84 00 00 00                               	sub    esp,0x84
  48bb8c:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  48bb91:	33 c4                                           	xor    eax,esp
  48bb93:	89 84 24 80 00 00 00                            	mov    DWORD PTR [esp+0x80],eax
  48bb9a:	53                                              	push   ebx
  48bb9b:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  48bb9e:	56                                              	push   esi
  48bb9f:	8b 75 10                                        	mov    esi,DWORD PTR [ebp+0x10]
  48bba2:	57                                              	push   edi
  48bba3:	8b 7d 0c                                        	mov    edi,DWORD PTR [ebp+0xc]
  48bba6:	33 c0                                           	xor    eax,eax
  48bba8:	8b cf                                           	mov    ecx,edi
  48bbaa:	89 5c 24 18                                     	mov    DWORD PTR [esp+0x18],ebx
  48bbae:	89 7c 24 1c                                     	mov    DWORD PTR [esp+0x1c],edi
  48bbb2:	89 74 24 14                                     	mov    DWORD PTR [esp+0x14],esi
  48bbb6:	89 4c 24 0c                                     	mov    DWORD PTR [esp+0xc],ecx
  48bbba:	89 44 24 24                                     	mov    DWORD PTR [esp+0x24],eax
  48bbbe:	89 44 24 20                                     	mov    DWORD PTR [esp+0x20],eax
  48bbc2:	c7 44 24 28 01 23 45 67                         	mov    DWORD PTR [esp+0x28],0x67452301
  48bbca:	c7 44 24 2c 89 ab cd ef                         	mov    DWORD PTR [esp+0x2c],0xefcdab89
  48bbd2:	c7 44 24 30 fe dc ba 98                         	mov    DWORD PTR [esp+0x30],0x98badcfe
  48bbda:	c7 44 24 34 76 54 32 10                         	mov    DWORD PTR [esp+0x34],0x10325476
  48bbe2:	81 ff 00 40 00 00                               	cmp    edi,0x4000
  48bbe8:	0f 86 88 00 00 00                               	jbe    0x48bc76
  48bbee:	81 c7 ff bf ff ff                               	add    edi,0xffffbfff
  48bbf4:	c1 ef 0e                                        	shr    edi,0xe
  48bbf7:	47                                              	inc    edi
  48bbf8:	89 7c 24 10                                     	mov    DWORD PTR [esp+0x10],edi
  48bbfc:	eb 06                                           	jmp    0x48bc04
  48bbfe:	8b ff                                           	mov    edi,edi
  48bc00:	8b 44 24 20                                     	mov    eax,DWORD PTR [esp+0x20]
  48bc04:	8b f3                                           	mov    esi,ebx
  48bc06:	a9 f8 01 00 00                                  	test   eax,0x1f8
  48bc0b:	75 32                                           	jne    0x48bc3f
  48bc0d:	8d 88 00 00 02 00                               	lea    ecx,[eax+0x20000]
  48bc13:	3b c8                                           	cmp    ecx,eax
  48bc15:	73 04                                           	jae    0x48bc1b
  48bc17:	ff 44 24 24                                     	inc    DWORD PTR [esp+0x24]
  48bc1b:	89 4c 24 20                                     	mov    DWORD PTR [esp+0x20],ecx
  48bc1f:	bf 00 01 00 00                                  	mov    edi,0x100
  48bc24:	8d 44 24 28                                     	lea    eax,[esp+0x28]
  48bc28:	50                                              	push   eax
  48bc29:	8b c6                                           	mov    eax,esi
  48bc2b:	e8 70 df 37 00                                  	call   0x809ba0
  48bc30:	83 c4 04                                        	add    esp,0x4
  48bc33:	83 c6 40                                        	add    esi,0x40
  48bc36:	4f                                              	dec    edi
  48bc37:	75 eb                                           	jne    0x48bc24
  48bc39:	8b 7c 24 10                                     	mov    edi,DWORD PTR [esp+0x10]
  48bc3d:	eb 12                                           	jmp    0x48bc51
  48bc3f:	53                                              	push   ebx
  48bc40:	b9 00 40 00 00                                  	mov    ecx,0x4000
  48bc45:	8d 74 24 24                                     	lea    esi,[esp+0x24]
  48bc49:	e8 92 dc 37 00                                  	call   0x8098e0
  48bc4e:	83 c4 04                                        	add    esp,0x4
  48bc51:	81 6c 24 0c 00 40 00 00                         	sub    DWORD PTR [esp+0xc],0x4000
  48bc59:	81 c3 00 40 00 00                               	add    ebx,0x4000
  48bc5f:	4f                                              	dec    edi
  48bc60:	89 7c 24 10                                     	mov    DWORD PTR [esp+0x10],edi
  48bc64:	75 9a                                           	jne    0x48bc00
  48bc66:	8b 74 24 14                                     	mov    esi,DWORD PTR [esp+0x14]
  48bc6a:	8b 7c 24 1c                                     	mov    edi,DWORD PTR [esp+0x1c]
  48bc6e:	8b 5c 24 18                                     	mov    ebx,DWORD PTR [esp+0x18]
  48bc72:	8b 4c 24 0c                                     	mov    ecx,DWORD PTR [esp+0xc]
  48bc76:	8b c7                                           	mov    eax,edi
  48bc78:	2b c1                                           	sub    eax,ecx
  48bc7a:	51                                              	push   ecx
  48bc7b:	03 c3                                           	add    eax,ebx
  48bc7d:	8d 4c 24 24                                     	lea    ecx,[esp+0x24]
  48bc81:	e8 8a dd 37 00                                  	call   0x809a10
  48bc86:	83 c4 04                                        	add    esp,0x4
  48bc89:	8d 4c 24 20                                     	lea    ecx,[esp+0x20]
  48bc8d:	e8 de dd 37 00                                  	call   0x809a70
  48bc92:	8b 4c 24 78                                     	mov    ecx,DWORD PTR [esp+0x78]
  48bc96:	8b 54 24 7c                                     	mov    edx,DWORD PTR [esp+0x7c]
  48bc9a:	8b 84 24 80 00 00 00                            	mov    eax,DWORD PTR [esp+0x80]
  48bca1:	89 0e                                           	mov    DWORD PTR [esi],ecx
  48bca3:	8b 8c 24 84 00 00 00                            	mov    ecx,DWORD PTR [esp+0x84]
  48bcaa:	89 56 04                                        	mov    DWORD PTR [esi+0x4],edx
  48bcad:	89 46 08                                        	mov    DWORD PTR [esi+0x8],eax
  48bcb0:	89 4e 0c                                        	mov    DWORD PTR [esi+0xc],ecx
  48bcb3:	8b 8c 24 8c 00 00 00                            	mov    ecx,DWORD PTR [esp+0x8c]
  48bcba:	5f                                              	pop    edi
  48bcbb:	5e                                              	pop    esi
  48bcbc:	5b                                              	pop    ebx
  48bcbd:	33 cc                                           	xor    ecx,esp
  48bcbf:	b0 01                                           	mov    al,0x1
  48bcc1:	e8 3b 53 40 00                                  	call   0x891001
  48bcc6:	8b e5                                           	mov    esp,ebp
  48bcc8:	5d                                              	pop    ebp
  48bcc9:	c2 0c 00                                        	ret    0xc
  48bccc:	cc                                              	int3
  48bccd:	cc                                              	int3
  48bcce:	cc                                              	int3
  48bccf:	cc                                              	int3

# 0x48bd30

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048bd30 <.text+0x8ad30>:
  48bd30:	55                                              	push   ebp
  48bd31:	8b ec                                           	mov    ebp,esp
  48bd33:	6a ff                                           	push   0xffffffff
  48bd35:	68 9a 53 92 00                                  	push   0x92539a
  48bd3a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  48bd40:	50                                              	push   eax
  48bd41:	51                                              	push   ecx
  48bd42:	57                                              	push   edi
  48bd43:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  48bd48:	33 c5                                           	xor    eax,ebp
  48bd4a:	50                                              	push   eax
  48bd4b:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  48bd4e:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  48bd54:	f6 05 94 69 fe 00 01                            	test   BYTE PTR ds:0xfe6994,0x1
  48bd5b:	75 27                                           	jne    0x48bd84
  48bd5d:	83 0d 94 69 fe 00 01                            	or     DWORD PTR ds:0xfe6994,0x1
  48bd64:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  48bd6b:	e8 70 f5 ff ff                                  	call   0x48b2e0
  48bd70:	68 b0 e5 bc 00                                  	push   0xbce5b0
  48bd75:	e8 a0 65 40 00                                  	call   0x89231a
  48bd7a:	83 c4 04                                        	add    esp,0x4
  48bd7d:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  48bd84:	f6 05 f4 49 fe 00 01                            	test   BYTE PTR ds:0xfe49f4,0x1
  48bd8b:	bf e0 48 fe 00                                  	mov    edi,0xfe48e0
  48bd90:	75 31                                           	jne    0x48bdc3
  48bd92:	b8 01 00 00 00                                  	mov    eax,0x1
  48bd97:	09 05 f4 49 fe 00                               	or     DWORD PTR ds:0xfe49f4,eax
  48bd9d:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  48bda0:	e8 fb 76 28 00                                  	call   0x7134a0
  48bda5:	68 70 e0 bc 00                                  	push   0xbce070
  48bdaa:	c7 05 e0 48 fe 00 20 5b c0 00                   	mov    DWORD PTR ds:0xfe48e0,0xc05b20
  48bdb4:	e8 61 65 40 00                                  	call   0x89231a
  48bdb9:	83 c4 04                                        	add    esp,0x4
  48bdbc:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  48bdc3:	f6 05 f4 49 fe 00 01                            	test   BYTE PTR ds:0xfe49f4,0x1
  48bdca:	b8 a0 37 fe 00                                  	mov    eax,0xfe37a0
  48bdcf:	89 3d 14 a8 fb 00                               	mov    DWORD PTR ds:0xfba814,edi
  48bdd5:	a3 18 a8 fb 00                                  	mov    ds:0xfba818,eax
  48bdda:	a3 1c a8 fb 00                                  	mov    ds:0xfba81c,eax
  48bddf:	75 31                                           	jne    0x48be12
  48bde1:	83 0d f4 49 fe 00 01                            	or     DWORD PTR ds:0xfe49f4,0x1
  48bde8:	c7 45 fc 02 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x2
  48bdef:	e8 ac 76 28 00                                  	call   0x7134a0
  48bdf4:	68 70 e0 bc 00                                  	push   0xbce070
  48bdf9:	c7 05 e0 48 fe 00 20 5b c0 00                   	mov    DWORD PTR ds:0xfe48e0,0xc05b20
  48be03:	e8 12 65 40 00                                  	call   0x89231a
  48be08:	83 c4 04                                        	add    esp,0x4
  48be0b:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  48be12:	57                                              	push   edi
  48be13:	e8 28 79 28 00                                  	call   0x713740
  48be18:	85 c0                                           	test   eax,eax
  48be1a:	75 10                                           	jne    0x48be2c
  48be1c:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  48be1f:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  48be26:	59                                              	pop    ecx
  48be27:	5f                                              	pop    edi
  48be28:	8b e5                                           	mov    esp,ebp
  48be2a:	5d                                              	pop    ebp
  48be2b:	c3                                              	ret
  48be2c:	50                                              	push   eax
  48be2d:	e8 2e b7 24 00                                  	call   0x6d7560
  48be32:	83 c4 04                                        	add    esp,0x4
  48be35:	f7 d8                                           	neg    eax
  48be37:	1b c0                                           	sbb    eax,eax
  48be39:	f7 d8                                           	neg    eax
  48be3b:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  48be3e:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  48be45:	59                                              	pop    ecx
  48be46:	5f                                              	pop    edi
  48be47:	8b e5                                           	mov    esp,ebp
  48be49:	5d                                              	pop    ebp
  48be4a:	c3                                              	ret
  48be4b:	cc                                              	int3
  48be4c:	cc                                              	int3
  48be4d:	cc                                              	int3
  48be4e:	cc                                              	int3
  48be4f:	cc                                              	int3

# 0x49b1b0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049b1b0 <.text+0x9a1b0>:
  49b1b0:	8d 50 d0                                        	lea    edx,[eax-0x30]
  49b1b3:	83 fa 09                                        	cmp    edx,0x9
  49b1b6:	77 05                                           	ja     0x49b1bd
  49b1b8:	83 e8 30                                        	sub    eax,0x30
  49b1bb:	eb 1c                                           	jmp    0x49b1d9
  49b1bd:	8d 50 9f                                        	lea    edx,[eax-0x61]
  49b1c0:	83 fa 05                                        	cmp    edx,0x5
  49b1c3:	77 05                                           	ja     0x49b1ca
  49b1c5:	83 e8 57                                        	sub    eax,0x57
  49b1c8:	eb 0f                                           	jmp    0x49b1d9
  49b1ca:	8d 50 bf                                        	lea    edx,[eax-0x41]
  49b1cd:	83 fa 05                                        	cmp    edx,0x5
  49b1d0:	77 05                                           	ja     0x49b1d7
  49b1d2:	83 e8 37                                        	sub    eax,0x37
  49b1d5:	eb 02                                           	jmp    0x49b1d9
  49b1d7:	33 c0                                           	xor    eax,eax
  49b1d9:	8d 51 d0                                        	lea    edx,[ecx-0x30]
  49b1dc:	83 fa 09                                        	cmp    edx,0x9
  49b1df:	77 0f                                           	ja     0x49b1f0
  49b1e1:	83 e9 30                                        	sub    ecx,0x30
  49b1e4:	83 e0 0f                                        	and    eax,0xf
  49b1e7:	c1 e0 04                                        	shl    eax,0x4
  49b1ea:	83 e1 0f                                        	and    ecx,0xf
  49b1ed:	0b c1                                           	or     eax,ecx
  49b1ef:	c3                                              	ret
  49b1f0:	8d 51 9f                                        	lea    edx,[ecx-0x61]
  49b1f3:	83 fa 05                                        	cmp    edx,0x5
  49b1f6:	77 0f                                           	ja     0x49b207
  49b1f8:	83 e9 57                                        	sub    ecx,0x57
  49b1fb:	83 e0 0f                                        	and    eax,0xf
  49b1fe:	c1 e0 04                                        	shl    eax,0x4
  49b201:	83 e1 0f                                        	and    ecx,0xf
  49b204:	0b c1                                           	or     eax,ecx
  49b206:	c3                                              	ret
  49b207:	8d 51 bf                                        	lea    edx,[ecx-0x41]
  49b20a:	83 fa 05                                        	cmp    edx,0x5
  49b20d:	77 0f                                           	ja     0x49b21e
  49b20f:	83 e9 37                                        	sub    ecx,0x37
  49b212:	83 e0 0f                                        	and    eax,0xf
  49b215:	c1 e0 04                                        	shl    eax,0x4
  49b218:	83 e1 0f                                        	and    ecx,0xf
  49b21b:	0b c1                                           	or     eax,ecx
  49b21d:	c3                                              	ret
  49b21e:	83 e0 0f                                        	and    eax,0xf
  49b221:	33 c9                                           	xor    ecx,ecx
  49b223:	c1 e0 04                                        	shl    eax,0x4
  49b226:	83 e1 0f                                        	and    ecx,0xf
  49b229:	0b c1                                           	or     eax,ecx
  49b22b:	c3                                              	ret
  49b22c:	cc                                              	int3
  49b22d:	cc                                              	int3
  49b22e:	cc                                              	int3
  49b22f:	cc                                              	int3

# 0x552640

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00552640 <.text+0x151640>:
  552640:	55                                              	push   ebp
  552641:	8b ec                                           	mov    ebp,esp
  552643:	53                                              	push   ebx
  552644:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  552647:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  552649:	56                                              	push   esi
  55264a:	8b 30                                           	mov    esi,DWORD PTR [eax]
  55264c:	89 00                                           	mov    DWORD PTR [eax],eax
  55264e:	8b 03                                           	mov    eax,DWORD PTR [ebx]
  552650:	89 40 04                                        	mov    DWORD PTR [eax+0x4],eax
  552653:	c7 43 04 00 00 00 00                            	mov    DWORD PTR [ebx+0x4],0x0
  55265a:	3b 33                                           	cmp    esi,DWORD PTR [ebx]
  55265c:	74 38                                           	je     0x552696
  55265e:	57                                              	push   edi
  55265f:	90                                              	nop
  552660:	83 7e 1c 10                                     	cmp    DWORD PTR [esi+0x1c],0x10
  552664:	8b 3e                                           	mov    edi,DWORD PTR [esi]
  552666:	72 0c                                           	jb     0x552674
  552668:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  55266b:	50                                              	push   eax
  55266c:	e8 9b eb 33 00                                  	call   0x89120c
  552671:	83 c4 04                                        	add    esp,0x4
  552674:	c7 46 1c 0f 00 00 00                            	mov    DWORD PTR [esi+0x1c],0xf
  55267b:	c7 46 18 00 00 00 00                            	mov    DWORD PTR [esi+0x18],0x0
  552682:	56                                              	push   esi
  552683:	c6 46 08 00                                     	mov    BYTE PTR [esi+0x8],0x0
  552687:	e8 80 eb 33 00                                  	call   0x89120c
  55268c:	83 c4 04                                        	add    esp,0x4
  55268f:	8b f7                                           	mov    esi,edi
  552691:	3b 3b                                           	cmp    edi,DWORD PTR [ebx]
  552693:	75 cb                                           	jne    0x552660
  552695:	5f                                              	pop    edi
  552696:	5e                                              	pop    esi
  552697:	5b                                              	pop    ebx
  552698:	5d                                              	pop    ebp
  552699:	c2 04 00                                        	ret    0x4
  55269c:	cc                                              	int3
  55269d:	cc                                              	int3
  55269e:	cc                                              	int3
  55269f:	cc                                              	int3

# 0x713cc0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00713cc0 <.text+0x312cc0>:
  713cc0:	55                                              	push   ebp
  713cc1:	8b ec                                           	mov    ebp,esp
  713cc3:	83 ec 24                                        	sub    esp,0x24
  713cc6:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  713ccb:	33 c5                                           	xor    eax,ebp
  713ccd:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  713cd0:	53                                              	push   ebx
  713cd1:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  713cd4:	56                                              	push   esi
  713cd5:	57                                              	push   edi
  713cd6:	6a 10                                           	push   0x10
  713cd8:	8b f9                                           	mov    edi,ecx
  713cda:	e8 89 d5 17 00                                  	call   0x891268
  713cdf:	33 f6                                           	xor    esi,esi
  713ce1:	83 c4 04                                        	add    esp,0x4
  713ce4:	3b c6                                           	cmp    eax,esi
  713ce6:	74 11                                           	je     0x713cf9
  713ce8:	89 70 04                                        	mov    DWORD PTR [eax+0x4],esi
  713ceb:	89 70 08                                        	mov    DWORD PTR [eax+0x8],esi
  713cee:	89 70 0c                                        	mov    DWORD PTR [eax+0xc],esi
  713cf1:	c7 00 04 42 c4 00                               	mov    DWORD PTR [eax],0xc44204
  713cf7:	8b f0                                           	mov    esi,eax
  713cf9:	53                                              	push   ebx
  713cfa:	57                                              	push   edi
  713cfb:	e8 7b db 17 00                                  	call   0x89187b
  713d00:	83 c4 08                                        	add    esp,0x8
  713d03:	89 46 04                                        	mov    DWORD PTR [esi+0x4],eax
  713d06:	85 c0                                           	test   eax,eax
  713d08:	8b 06                                           	mov    eax,DWORD PTR [esi]
  713d0a:	8b ce                                           	mov    ecx,esi
  713d0c:	75 19                                           	jne    0x713d27
  713d0e:	8b 10                                           	mov    edx,DWORD PTR [eax]
  713d10:	6a 01                                           	push   0x1
  713d12:	ff d2                                           	call   edx
  713d14:	5f                                              	pop    edi
  713d15:	5e                                              	pop    esi
  713d16:	33 c0                                           	xor    eax,eax
  713d18:	5b                                              	pop    ebx
  713d19:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  713d1c:	33 cd                                           	xor    ecx,ebp
  713d1e:	e8 de d2 17 00                                  	call   0x891001
  713d23:	8b e5                                           	mov    esp,ebp
  713d25:	5d                                              	pop    ebp
  713d26:	c3                                              	ret
  713d27:	8b 50 34                                        	mov    edx,DWORD PTR [eax+0x34]
  713d2a:	6a 02                                           	push   0x2
  713d2c:	6a 00                                           	push   0x0
  713d2e:	ff d2                                           	call   edx
  713d30:	8b 06                                           	mov    eax,DWORD PTR [esi]
  713d32:	8b 50 30                                        	mov    edx,DWORD PTR [eax+0x30]
  713d35:	8b ce                                           	mov    ecx,esi
  713d37:	ff d2                                           	call   edx
  713d39:	89 46 0c                                        	mov    DWORD PTR [esi+0xc],eax
  713d3c:	8b 06                                           	mov    eax,DWORD PTR [esi]
  713d3e:	8b 50 34                                        	mov    edx,DWORD PTR [eax+0x34]
  713d41:	6a 00                                           	push   0x0
  713d43:	6a 00                                           	push   0x0
  713d45:	8b ce                                           	mov    ecx,esi
  713d47:	ff d2                                           	call   edx
  713d49:	8b 0d 1c a8 fb 00                               	mov    ecx,DWORD PTR ds:0xfba81c
  713d4f:	85 c9                                           	test   ecx,ecx
  713d51:	74 5d                                           	je     0x713db0
  713d53:	33 c0                                           	xor    eax,eax
  713d55:	89 45 ed                                        	mov    DWORD PTR [ebp-0x13],eax
  713d58:	89 45 f1                                        	mov    DWORD PTR [ebp-0xf],eax
  713d5b:	89 45 f5                                        	mov    DWORD PTR [ebp-0xb],eax
  713d5e:	66 89 45 f9                                     	mov    WORD PTR [ebp-0x7],ax
  713d62:	88 45 fb                                        	mov    BYTE PTR [ebp-0x5],al
  713d65:	8b 01                                           	mov    eax,DWORD PTR [ecx]
  713d67:	8b 00                                           	mov    eax,DWORD PTR [eax]
  713d69:	8d 55 ec                                        	lea    edx,[ebp-0x14]
  713d6c:	52                                              	push   edx
  713d6d:	57                                              	push   edi
  713d6e:	c6 45 ec 00                                     	mov    BYTE PTR [ebp-0x14],0x0
  713d72:	ff d0                                           	call   eax
  713d74:	84 c0                                           	test   al,al
  713d76:	74 38                                           	je     0x713db0
  713d78:	8b 0d 1c a8 fb 00                               	mov    ecx,DWORD PTR ds:0xfba81c
  713d7e:	8b 46 0c                                        	mov    eax,DWORD PTR [esi+0xc]
  713d81:	8b 39                                           	mov    edi,DWORD PTR [ecx]
  713d83:	8d 55 dc                                        	lea    edx,[ebp-0x24]
  713d86:	52                                              	push   edx
  713d87:	8b 16                                           	mov    edx,DWORD PTR [esi]
  713d89:	50                                              	push   eax
  713d8a:	8b 42 38                                        	mov    eax,DWORD PTR [edx+0x38]
  713d8d:	8b ce                                           	mov    ecx,esi
  713d8f:	ff d0                                           	call   eax
  713d91:	8b 0d 1c a8 fb 00                               	mov    ecx,DWORD PTR ds:0xfba81c
  713d97:	8b 57 08                                        	mov    edx,DWORD PTR [edi+0x8]
  713d9a:	50                                              	push   eax
  713d9b:	ff d2                                           	call   edx
  713d9d:	33 c0                                           	xor    eax,eax
  713d9f:	90                                              	nop
  713da0:	8a 4c 05 ec                                     	mov    cl,BYTE PTR [ebp+eax*1-0x14]
  713da4:	3a 4c 05 dc                                     	cmp    cl,BYTE PTR [ebp+eax*1-0x24]
  713da8:	75 19                                           	jne    0x713dc3
  713daa:	40                                              	inc    eax
  713dab:	83 f8 10                                        	cmp    eax,0x10
  713dae:	7c f0                                           	jl     0x713da0
  713db0:	5f                                              	pop    edi
  713db1:	8b c6                                           	mov    eax,esi
  713db3:	5e                                              	pop    esi
  713db4:	5b                                              	pop    ebx
  713db5:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  713db8:	33 cd                                           	xor    ecx,ebp
  713dba:	e8 42 d2 17 00                                  	call   0x891001
  713dbf:	8b e5                                           	mov    esp,ebp
  713dc1:	5d                                              	pop    ebp
  713dc2:	c3                                              	ret
  713dc3:	8b 16                                           	mov    edx,DWORD PTR [esi]
  713dc5:	8b 02                                           	mov    eax,DWORD PTR [edx]
  713dc7:	6a 01                                           	push   0x1
  713dc9:	8b ce                                           	mov    ecx,esi
  713dcb:	ff d0                                           	call   eax
  713dcd:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  713dd0:	5f                                              	pop    edi
  713dd1:	5e                                              	pop    esi
  713dd2:	33 cd                                           	xor    ecx,ebp
  713dd4:	33 c0                                           	xor    eax,eax
  713dd6:	5b                                              	pop    ebx
  713dd7:	e8 25 d2 17 00                                  	call   0x891001
  713ddc:	8b e5                                           	mov    esp,ebp
  713dde:	5d                                              	pop    ebp
  713ddf:	c3                                              	ret

# 0x713f90

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00713f90 <.text+0x312f90>:
  713f90:	56                                              	push   esi
  713f91:	8b f1                                           	mov    esi,ecx
  713f93:	83 7e 08 00                                     	cmp    DWORD PTR [esi+0x8],0x0
  713f97:	75 47                                           	jne    0x713fe0
  713f99:	8b 06                                           	mov    eax,DWORD PTR [esi]
  713f9b:	8b 50 30                                        	mov    edx,DWORD PTR [eax+0x30]
  713f9e:	57                                              	push   edi
  713f9f:	ff d2                                           	call   edx
  713fa1:	8b f8                                           	mov    edi,eax
  713fa3:	8b 06                                           	mov    eax,DWORD PTR [esi]
  713fa5:	8b 50 34                                        	mov    edx,DWORD PTR [eax+0x34]
  713fa8:	6a 00                                           	push   0x0
  713faa:	6a 00                                           	push   0x0
  713fac:	8b ce                                           	mov    ecx,esi
  713fae:	ff d2                                           	call   edx
  713fb0:	8b 46 0c                                        	mov    eax,DWORD PTR [esi+0xc]
  713fb3:	50                                              	push   eax
  713fb4:	e8 84 9c 16 00                                  	call   0x87dc3d
  713fb9:	8b 4e 0c                                        	mov    ecx,DWORD PTR [esi+0xc]
  713fbc:	83 c4 04                                        	add    esp,0x4
  713fbf:	89 46 08                                        	mov    DWORD PTR [esi+0x8],eax
  713fc2:	85 c9                                           	test   ecx,ecx
  713fc4:	74 0d                                           	je     0x713fd3
  713fc6:	8b 16                                           	mov    edx,DWORD PTR [esi]
  713fc8:	6a 01                                           	push   0x1
  713fca:	51                                              	push   ecx
  713fcb:	50                                              	push   eax
  713fcc:	8b 42 10                                        	mov    eax,DWORD PTR [edx+0x10]
  713fcf:	8b ce                                           	mov    ecx,esi
  713fd1:	ff d0                                           	call   eax
  713fd3:	8b 16                                           	mov    edx,DWORD PTR [esi]
  713fd5:	8b 42 34                                        	mov    eax,DWORD PTR [edx+0x34]
  713fd8:	6a 00                                           	push   0x0
  713fda:	57                                              	push   edi
  713fdb:	8b ce                                           	mov    ecx,esi
  713fdd:	ff d0                                           	call   eax
  713fdf:	5f                                              	pop    edi
  713fe0:	8b 46 08                                        	mov    eax,DWORD PTR [esi+0x8]
  713fe3:	5e                                              	pop    esi
  713fe4:	c3                                              	ret
  713fe5:	cc                                              	int3
  713fe6:	cc                                              	int3
  713fe7:	cc                                              	int3
  713fe8:	cc                                              	int3
  713fe9:	cc                                              	int3
  713fea:	cc                                              	int3
  713feb:	cc                                              	int3
  713fec:	cc                                              	int3
  713fed:	cc                                              	int3
  713fee:	cc                                              	int3
  713fef:	cc                                              	int3

# 0x713ff0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00713ff0 <.text+0x312ff0>:
  713ff0:	b8 01 00 00 00                                  	mov    eax,0x1
  713ff5:	84 05 4c 36 fe 00                               	test   BYTE PTR ds:0xfe364c,al
  713ffb:	75 21                                           	jne    0x71401e
  713ffd:	09 05 4c 36 fe 00                               	or     DWORD PTR ds:0xfe364c,eax
  714003:	68 00 01 00 00                                  	push   0x100
  714008:	6a 00                                           	push   0x0
  71400a:	68 48 35 fe 00                                  	push   0xfe3548
  71400f:	c6 05 48 36 fe 00 00                            	mov    BYTE PTR ds:0xfe3648,0x0
  714016:	e8 45 a8 18 00                                  	call   0x89e860
  71401b:	83 c4 0c                                        	add    esp,0xc
  71401e:	b8 48 35 fe 00                                  	mov    eax,0xfe3548
  714023:	c3                                              	ret
  714024:	cc                                              	int3
  714025:	cc                                              	int3
  714026:	cc                                              	int3
  714027:	cc                                              	int3
  714028:	cc                                              	int3
  714029:	cc                                              	int3
  71402a:	cc                                              	int3
  71402b:	cc                                              	int3
  71402c:	cc                                              	int3
  71402d:	cc                                              	int3
  71402e:	cc                                              	int3
  71402f:	cc                                              	int3

# 0x714030

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00714030 <.text+0x313030>:
  714030:	55                                              	push   ebp
  714031:	8b ec                                           	mov    ebp,esp
  714033:	6a ff                                           	push   0xffffffff
  714035:	68 4b 97 91 00                                  	push   0x91974b
  71403a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  714040:	50                                              	push   eax
  714041:	b8 28 10 00 00                                  	mov    eax,0x1028
  714046:	e8 25 c6 19 00                                  	call   0x8b0670
  71404b:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  714050:	33 c5                                           	xor    eax,ebp
  714052:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  714055:	53                                              	push   ebx
  714056:	56                                              	push   esi
  714057:	50                                              	push   eax
  714058:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  71405b:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  714061:	8b 1d 4c 36 fe 00                               	mov    ebx,DWORD PTR ds:0xfe364c
  714067:	8b f1                                           	mov    esi,ecx
  714069:	89 b5 d0 ef ff ff                               	mov    DWORD PTR [ebp-0x1030],esi
  71406f:	f6 c3 01                                        	test   bl,0x1
  714072:	75 24                                           	jne    0x714098
  714074:	68 00 01 00 00                                  	push   0x100
  714079:	6a 00                                           	push   0x0
  71407b:	83 cb 01                                        	or     ebx,0x1
  71407e:	68 48 35 fe 00                                  	push   0xfe3548
  714083:	89 1d 4c 36 fe 00                               	mov    DWORD PTR ds:0xfe364c,ebx
  714089:	c6 05 48 36 fe 00 00                            	mov    BYTE PTR ds:0xfe3648,0x0
  714090:	e8 cb a7 18 00                                  	call   0x89e860
  714095:	83 c4 0c                                        	add    esp,0xc
  714098:	80 3d 48 36 fe 00 00                            	cmp    BYTE PTR ds:0xfe3648,0x0
  71409f:	0f 84 f2 00 00 00                               	je     0x714197
  7140a5:	f6 c3 01                                        	test   bl,0x1
  7140a8:	75 24                                           	jne    0x7140ce
  7140aa:	68 00 01 00 00                                  	push   0x100
  7140af:	6a 00                                           	push   0x0
  7140b1:	83 cb 01                                        	or     ebx,0x1
  7140b4:	68 48 35 fe 00                                  	push   0xfe3548
  7140b9:	89 1d 4c 36 fe 00                               	mov    DWORD PTR ds:0xfe364c,ebx
  7140bf:	c6 05 48 36 fe 00 00                            	mov    BYTE PTR ds:0xfe3648,0x0
  7140c6:	e8 95 a7 18 00                                  	call   0x89e860
  7140cb:	83 c4 0c                                        	add    esp,0xc
  7140ce:	33 db                                           	xor    ebx,ebx
  7140d0:	b8 48 35 fe 00                                  	mov    eax,0xfe3548
  7140d5:	c7 85 e8 ef ff ff 0f 00 00 00                   	mov    DWORD PTR [ebp-0x1018],0xf
  7140df:	89 9d e4 ef ff ff                               	mov    DWORD PTR [ebp-0x101c],ebx
  7140e5:	88 9d d4 ef ff ff                               	mov    BYTE PTR [ebp-0x102c],bl
  7140eb:	8d 50 01                                        	lea    edx,[eax+0x1]
  7140ee:	8b ff                                           	mov    edi,edi
  7140f0:	8a 08                                           	mov    cl,BYTE PTR [eax]
  7140f2:	40                                              	inc    eax
  7140f3:	84 c9                                           	test   cl,cl
  7140f5:	75 f9                                           	jne    0x7140f0
  7140f7:	2b c2                                           	sub    eax,edx
  7140f9:	50                                              	push   eax
  7140fa:	68 48 35 fe 00                                  	push   0xfe3548
  7140ff:	8d 8d d4 ef ff ff                               	lea    ecx,[ebp-0x102c]
  714105:	e8 66 e9 ce ff                                  	call   0x402a70
  71410a:	8b c7                                           	mov    eax,edi
  71410c:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  71410f:	8d 50 01                                        	lea    edx,[eax+0x1]
  714112:	8a 08                                           	mov    cl,BYTE PTR [eax]
  714114:	40                                              	inc    eax
  714115:	84 c9                                           	test   cl,cl
  714117:	75 f9                                           	jne    0x714112
  714119:	2b c2                                           	sub    eax,edx
  71411b:	50                                              	push   eax
  71411c:	57                                              	push   edi
  71411d:	8d 8d d4 ef ff ff                               	lea    ecx,[ebp-0x102c]
  714123:	e8 98 de ce ff                                  	call   0x401fc0
  714128:	83 bd e8 ef ff ff 10                            	cmp    DWORD PTR [ebp-0x1018],0x10
  71412f:	8b 9d d4 ef ff ff                               	mov    ebx,DWORD PTR [ebp-0x102c]
  714135:	73 06                                           	jae    0x71413d
  714137:	8d 9d d4 ef ff ff                               	lea    ebx,[ebp-0x102c]
  71413d:	8b c3                                           	mov    eax,ebx
  71413f:	e8 1c 3a 00 00                                  	call   0x717b60
  714144:	85 c0                                           	test   eax,eax
  714146:	74 15                                           	je     0x71415d
  714148:	8b d6                                           	mov    edx,esi
  71414a:	8b cb                                           	mov    ecx,ebx
  71414c:	e8 6f 3a 00 00                                  	call   0x717bc0
  714151:	8b f0                                           	mov    esi,eax
  714153:	85 f6                                           	test   esi,esi
  714155:	75 13                                           	jne    0x71416a
  714157:	8b b5 d0 ef ff ff                               	mov    esi,DWORD PTR [ebp-0x1030]
  71415d:	56                                              	push   esi
  71415e:	8b cb                                           	mov    ecx,ebx
  714160:	e8 5b fb ff ff                                  	call   0x713cc0
  714165:	83 c4 04                                        	add    esp,0x4
  714168:	8b f0                                           	mov    esi,eax
  71416a:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  714171:	83 bd e8 ef ff ff 10                            	cmp    DWORD PTR [ebp-0x1018],0x10
  714178:	72 0f                                           	jb     0x714189
  71417a:	8b 85 d4 ef ff ff                               	mov    eax,DWORD PTR [ebp-0x102c]
  714180:	50                                              	push   eax
  714181:	e8 86 d0 17 00                                  	call   0x89120c
  714186:	83 c4 04                                        	add    esp,0x4
  714189:	85 f6                                           	test   esi,esi
  71418b:	0f 85 ac 00 00 00                               	jne    0x71423d
  714191:	8b b5 d0 ef ff ff                               	mov    esi,DWORD PTR [ebp-0x1030]
  714197:	8b c7                                           	mov    eax,edi
  714199:	e8 c2 39 00 00                                  	call   0x717b60
  71419e:	85 c0                                           	test   eax,eax
  7141a0:	74 19                                           	je     0x7141bb
  7141a2:	8b d6                                           	mov    edx,esi
  7141a4:	8b cf                                           	mov    ecx,edi
  7141a6:	e8 15 3a 00 00                                  	call   0x717bc0
  7141ab:	8b f0                                           	mov    esi,eax
  7141ad:	85 f6                                           	test   esi,esi
  7141af:	0f 85 88 00 00 00                               	jne    0x71423d
  7141b5:	8b b5 d0 ef ff ff                               	mov    esi,DWORD PTR [ebp-0x1030]
  7141bb:	56                                              	push   esi
  7141bc:	8b cf                                           	mov    ecx,edi
  7141be:	e8 fd fa ff ff                                  	call   0x713cc0
  7141c3:	8b f0                                           	mov    esi,eax
  7141c5:	83 c4 04                                        	add    esp,0x4
  7141c8:	85 f6                                           	test   esi,esi
  7141ca:	75 71                                           	jne    0x71423d
  7141cc:	ff 15 00 23 bd 00                               	call   DWORD PTR ds:0xbd2300
  7141d2:	89 85 cc ef ff ff                               	mov    DWORD PTR [ebp-0x1034],eax
  7141d8:	83 f8 02                                        	cmp    eax,0x2
  7141db:	75 07                                           	jne    0x7141e4
  7141dd:	bb 40 42 c4 00                                  	mov    ebx,0xc44240
  7141e2:	eb 0f                                           	jmp    0x7141f3
  7141e4:	bb 54 42 c4 00                                  	mov    ebx,0xc44254
  7141e9:	83 f8 03                                        	cmp    eax,0x3
  7141ec:	74 05                                           	je     0x7141f3
  7141ee:	bb 50 c2 bf 00                                  	mov    ebx,0xbfc250
  7141f3:	68 ff 0f 00 00                                  	push   0xfff
  7141f8:	8d 8d f1 ef ff ff                               	lea    ecx,[ebp-0x100f]
  7141fe:	6a 00                                           	push   0x0
  714200:	51                                              	push   ecx
  714201:	c6 85 f0 ef ff ff 00                            	mov    BYTE PTR [ebp-0x1010],0x0
  714208:	e8 53 a6 18 00                                  	call   0x89e860
  71420d:	8b 95 d0 ef ff ff                               	mov    edx,DWORD PTR [ebp-0x1030]
  714213:	8b 85 cc ef ff ff                               	mov    eax,DWORD PTR [ebp-0x1034]
  714219:	52                                              	push   edx
  71421a:	57                                              	push   edi
  71421b:	53                                              	push   ebx
  71421c:	50                                              	push   eax
  71421d:	68 68 42 c4 00                                  	push   0xc44268
  714222:	8d 95 f0 ef ff ff                               	lea    edx,[ebp-0x1010]
  714228:	e8 23 07 00 00                                  	call   0x714950
  71422d:	8d 8d f0 ef ff ff                               	lea    ecx,[ebp-0x1010]
  714233:	51                                              	push   ecx
  714234:	ff 15 50 3d d6 00                               	call   DWORD PTR ds:0xd63d50
  71423a:	83 c4 24                                        	add    esp,0x24
  71423d:	8b c6                                           	mov    eax,esi
  71423f:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  714242:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  714249:	59                                              	pop    ecx
  71424a:	5e                                              	pop    esi
  71424b:	5b                                              	pop    ebx
  71424c:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  71424f:	33 cd                                           	xor    ecx,ebp
  714251:	e8 ab cd 17 00                                  	call   0x891001
  714256:	8b e5                                           	mov    esp,ebp
  714258:	5d                                              	pop    ebp
  714259:	c3                                              	ret
  71425a:	cc                                              	int3
  71425b:	cc                                              	int3
  71425c:	cc                                              	int3
  71425d:	cc                                              	int3
  71425e:	cc                                              	int3
  71425f:	cc                                              	int3

# 0x714260

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00714260 <.text+0x313260>:
  714260:	55                                              	push   ebp
  714261:	8b ec                                           	mov    ebp,esp
  714263:	6a ff                                           	push   0xffffffff
  714265:	68 4e a8 90 00                                  	push   0x90a84e
  71426a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  714270:	50                                              	push   eax
  714271:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  714276:	33 c5                                           	xor    eax,ebp
  714278:	50                                              	push   eax
  714279:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  71427c:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  714282:	b8 01 00 00 00                                  	mov    eax,0x1
  714287:	84 05 98 4c fe 00                               	test   BYTE PTR ds:0xfe4c98,al
  71428d:	75 1f                                           	jne    0x7142ae
  71428f:	09 05 98 4c fe 00                               	or     DWORD PTR ds:0xfe4c98,eax
  714295:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  71429c:	e8 2f 00 00 00                                  	call   0x7142d0
  7142a1:	68 60 07 bd 00                                  	push   0xbd0760
  7142a6:	e8 6f e0 17 00                                  	call   0x89231a
  7142ab:	83 c4 04                                        	add    esp,0x4
  7142ae:	b8 7c 4c fe 00                                  	mov    eax,0xfe4c7c
  7142b3:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  7142b6:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  7142bd:	59                                              	pop    ecx
  7142be:	8b e5                                           	mov    esp,ebp
  7142c0:	5d                                              	pop    ebp
  7142c1:	c3                                              	ret
  7142c2:	cc                                              	int3
  7142c3:	cc                                              	int3
  7142c4:	cc                                              	int3
  7142c5:	cc                                              	int3
  7142c6:	cc                                              	int3
  7142c7:	cc                                              	int3
  7142c8:	cc                                              	int3
  7142c9:	cc                                              	int3
  7142ca:	cc                                              	int3
  7142cb:	cc                                              	int3
  7142cc:	cc                                              	int3
  7142cd:	cc                                              	int3
  7142ce:	cc                                              	int3
  7142cf:	cc                                              	int3

# 0x7142d0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007142d0 <.text+0x3132d0>:
  7142d0:	55                                              	push   ebp
  7142d1:	8b ec                                           	mov    ebp,esp
  7142d3:	6a ff                                           	push   0xffffffff
  7142d5:	68 18 a8 90 00                                  	push   0x90a818
  7142da:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  7142e0:	50                                              	push   eax
  7142e1:	83 ec 24                                        	sub    esp,0x24
  7142e4:	53                                              	push   ebx
  7142e5:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  7142ea:	33 c5                                           	xor    eax,ebp
  7142ec:	50                                              	push   eax
  7142ed:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  7142f0:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  7142f6:	33 db                                           	xor    ebx,ebx
  7142f8:	6a 24                                           	push   0x24
  7142fa:	c7 45 e8 7c 4c fe 00                            	mov    DWORD PTR [ebp-0x18],0xfe4c7c
  714301:	89 1d 80 4c fe 00                               	mov    DWORD PTR ds:0xfe4c80,ebx
  714307:	e8 5c cf 17 00                                  	call   0x891268
  71430c:	83 c4 04                                        	add    esp,0x4
  71430f:	3b c3                                           	cmp    eax,ebx
  714311:	74 74                                           	je     0x714387
  714313:	a3 7c 4c fe 00                                  	mov    ds:0xfe4c7c,eax
  714318:	89 00                                           	mov    DWORD PTR [eax],eax
  71431a:	a1 7c 4c fe 00                                  	mov    eax,ds:0xfe4c7c
  71431f:	89 40 04                                        	mov    DWORD PTR [eax+0x4],eax
  714322:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  714325:	6a 24                                           	push   0x24
  714327:	89 1d 8c 4c fe 00                               	mov    DWORD PTR ds:0xfe4c8c,ebx
  71432d:	e8 36 cf 17 00                                  	call   0x891268
  714332:	83 c4 04                                        	add    esp,0x4
  714335:	3b c3                                           	cmp    eax,ebx
  714337:	74 2a                                           	je     0x714363
  714339:	a3 88 4c fe 00                                  	mov    ds:0xfe4c88,eax
  71433e:	89 00                                           	mov    DWORD PTR [eax],eax
  714340:	a1 88 4c fe 00                                  	mov    eax,ds:0xfe4c88
  714345:	89 40 04                                        	mov    DWORD PTR [eax+0x4],eax
  714348:	88 1d 94 4c fe 00                               	mov    BYTE PTR ds:0xfe4c94,bl
  71434e:	b8 7c 4c fe 00                                  	mov    eax,0xfe4c7c
  714353:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  714356:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  71435d:	59                                              	pop    ecx
  71435e:	5b                                              	pop    ebx
  71435f:	8b e5                                           	mov    esp,ebp
  714361:	5d                                              	pop    ebp
  714362:	c3                                              	ret
  714363:	8d 45 f0                                        	lea    eax,[ebp-0x10]
  714366:	50                                              	push   eax
  714367:	8d 4d dc                                        	lea    ecx,[ebp-0x24]
  71436a:	89 5d f0                                        	mov    DWORD PTR [ebp-0x10],ebx
  71436d:	e8 37 cd 17 00                                  	call   0x8910a9
  714372:	68 a8 57 c8 00                                  	push   0xc857a8
  714377:	8d 4d dc                                        	lea    ecx,[ebp-0x24]
  71437a:	51                                              	push   ecx
  71437b:	c7 45 dc a4 2c bd 00                            	mov    DWORD PTR [ebp-0x24],0xbd2ca4
  714382:	e8 69 86 18 00                                  	call   0x89c9f0
  714387:	8d 55 ec                                        	lea    edx,[ebp-0x14]
  71438a:	52                                              	push   edx
  71438b:	8d 4d d0                                        	lea    ecx,[ebp-0x30]
  71438e:	89 5d ec                                        	mov    DWORD PTR [ebp-0x14],ebx
  714391:	e8 13 cd 17 00                                  	call   0x8910a9
  714396:	68 a8 57 c8 00                                  	push   0xc857a8
  71439b:	8d 45 d0                                        	lea    eax,[ebp-0x30]
  71439e:	50                                              	push   eax
  71439f:	c7 45 d0 a4 2c bd 00                            	mov    DWORD PTR [ebp-0x30],0xbd2ca4
  7143a6:	e8 45 86 18 00                                  	call   0x89c9f0
  7143ab:	cc                                              	int3
  7143ac:	cc                                              	int3
  7143ad:	cc                                              	int3
  7143ae:	cc                                              	int3
  7143af:	cc                                              	int3

# 0x7143b0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007143b0 <.text+0x3133b0>:
  7143b0:	55                                              	push   ebp
  7143b1:	8b ec                                           	mov    ebp,esp
  7143b3:	81 ec 04 01 00 00                               	sub    esp,0x104
  7143b9:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  7143be:	33 c5                                           	xor    eax,ebp
  7143c0:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  7143c3:	53                                              	push   ebx
  7143c4:	56                                              	push   esi
  7143c5:	68 ff 00 00 00                                  	push   0xff
  7143ca:	8d 85 fd fe ff ff                               	lea    eax,[ebp-0x103]
  7143d0:	6a 00                                           	push   0x0
  7143d2:	50                                              	push   eax
  7143d3:	8b f1                                           	mov    esi,ecx
  7143d5:	c6 85 fc fe ff ff 00                            	mov    BYTE PTR [ebp-0x104],0x0
  7143dc:	e8 7f a4 18 00                                  	call   0x89e860
  7143e1:	8d 9d fc fe ff ff                               	lea    ebx,[ebp-0x104]
  7143e7:	8b cb                                           	mov    ecx,ebx
  7143e9:	51                                              	push   ecx
  7143ea:	6a 00                                           	push   0x0
  7143ec:	6a 00                                           	push   0x0
  7143ee:	6a 00                                           	push   0x0
  7143f0:	56                                              	push   esi
  7143f1:	e8 46 75 18 00                                  	call   0x89b93c
  7143f6:	83 c4 20                                        	add    esp,0x20
  7143f9:	80 bd fc fe ff ff 2e                            	cmp    BYTE PTR [ebp-0x104],0x2e
  714400:	75 06                                           	jne    0x714408
  714402:	8d 9d fd fe ff ff                               	lea    ebx,[ebp-0x103]
  714408:	68 94 42 c4 00                                  	push   0xc44294
  71440d:	53                                              	push   ebx
  71440e:	e8 9e f8 17 00                                  	call   0x893cb1
  714413:	83 c4 08                                        	add    esp,0x8
  714416:	85 c0                                           	test   eax,eax
  714418:	75 12                                           	jne    0x71442c
  71441a:	5e                                              	pop    esi
  71441b:	b0 01                                           	mov    al,0x1
  71441d:	5b                                              	pop    ebx
  71441e:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  714421:	33 cd                                           	xor    ecx,ebp
  714423:	e8 d9 cb 17 00                                  	call   0x891001
  714428:	8b e5                                           	mov    esp,ebp
  71442a:	5d                                              	pop    ebp
  71442b:	c3                                              	ret
  71442c:	8b 07                                           	mov    eax,DWORD PTR [edi]
  71442e:	8b 30                                           	mov    esi,DWORD PTR [eax]
  714430:	3b f0                                           	cmp    esi,eax
  714432:	74 1f                                           	je     0x714453
  714434:	83 7e 1c 10                                     	cmp    DWORD PTR [esi+0x1c],0x10
  714438:	8d 46 08                                        	lea    eax,[esi+0x8]
  71443b:	72 02                                           	jb     0x71443f
  71443d:	8b 00                                           	mov    eax,DWORD PTR [eax]
  71443f:	50                                              	push   eax
  714440:	53                                              	push   ebx
  714441:	e8 6b f8 17 00                                  	call   0x893cb1
  714446:	83 c4 08                                        	add    esp,0x8
  714449:	85 c0                                           	test   eax,eax
  71444b:	74 cd                                           	je     0x71441a
  71444d:	8b 36                                           	mov    esi,DWORD PTR [esi]
  71444f:	3b 37                                           	cmp    esi,DWORD PTR [edi]
  714451:	75 e1                                           	jne    0x714434
  714453:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  714456:	5e                                              	pop    esi
  714457:	33 cd                                           	xor    ecx,ebp
  714459:	32 c0                                           	xor    al,al
  71445b:	5b                                              	pop    ebx
  71445c:	e8 a0 cb 17 00                                  	call   0x891001
  714461:	8b e5                                           	mov    esp,ebp
  714463:	5d                                              	pop    ebp
  714464:	c3                                              	ret
  714465:	cc                                              	int3
  714466:	cc                                              	int3
  714467:	cc                                              	int3
  714468:	cc                                              	int3
  714469:	cc                                              	int3
  71446a:	cc                                              	int3
  71446b:	cc                                              	int3
  71446c:	cc                                              	int3
  71446d:	cc                                              	int3
  71446e:	cc                                              	int3
  71446f:	cc                                              	int3

# 0x714470

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00714470 <.text+0x313470>:
  714470:	55                                              	push   ebp
  714471:	8b ec                                           	mov    ebp,esp
  714473:	81 ec 04 01 00 00                               	sub    esp,0x104
  714479:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  71447e:	33 c5                                           	xor    eax,ebp
  714480:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  714483:	53                                              	push   ebx
  714484:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  714487:	56                                              	push   esi
  714488:	68 ff 00 00 00                                  	push   0xff
  71448d:	8d 85 fd fe ff ff                               	lea    eax,[ebp-0x103]
  714493:	6a 00                                           	push   0x0
  714495:	50                                              	push   eax
  714496:	8b f1                                           	mov    esi,ecx
  714498:	c6 85 fc fe ff ff 00                            	mov    BYTE PTR [ebp-0x104],0x0
  71449f:	e8 bc a3 18 00                                  	call   0x89e860
  7144a4:	56                                              	push   esi
  7144a5:	8d 8d fc fe ff ff                               	lea    ecx,[ebp-0x104]
  7144ab:	68 00 01 00 00                                  	push   0x100
  7144b0:	51                                              	push   ecx
  7144b1:	e8 a3 f6 17 00                                  	call   0x893b59
  7144b6:	8b c6                                           	mov    eax,esi
  7144b8:	83 c4 18                                        	add    esp,0x18
  7144bb:	8d 50 01                                        	lea    edx,[eax+0x1]
  7144be:	8b ff                                           	mov    edi,edi
  7144c0:	8a 08                                           	mov    cl,BYTE PTR [eax]
  7144c2:	40                                              	inc    eax
  7144c3:	84 c9                                           	test   cl,cl
  7144c5:	75 f9                                           	jne    0x7144c0
  7144c7:	2b c2                                           	sub    eax,edx
  7144c9:	b9 00 00 00 00                                  	mov    ecx,0x0
  7144ce:	74 17                                           	je     0x7144e7
  7144d0:	80 bc 0d fc fe ff ff 5c                         	cmp    BYTE PTR [ebp+ecx*1-0x104],0x5c
  7144d8:	75 08                                           	jne    0x7144e2
  7144da:	c6 84 0d fc fe ff ff 2f                         	mov    BYTE PTR [ebp+ecx*1-0x104],0x2f
  7144e2:	41                                              	inc    ecx
  7144e3:	3b c8                                           	cmp    ecx,eax
  7144e5:	72 e9                                           	jb     0x7144d0
  7144e7:	8b 43 0c                                        	mov    eax,DWORD PTR [ebx+0xc]
  7144ea:	8b 30                                           	mov    esi,DWORD PTR [eax]
  7144ec:	3b f0                                           	cmp    esi,eax
  7144ee:	74 2a                                           	je     0x71451a
  7144f0:	83 7e 1c 10                                     	cmp    DWORD PTR [esi+0x1c],0x10
  7144f4:	8b 4e 18                                        	mov    ecx,DWORD PTR [esi+0x18]
  7144f7:	8d 46 08                                        	lea    eax,[esi+0x8]
  7144fa:	72 02                                           	jb     0x7144fe
  7144fc:	8b 00                                           	mov    eax,DWORD PTR [eax]
  7144fe:	51                                              	push   ecx
  7144ff:	50                                              	push   eax
  714500:	8d 95 fc fe ff ff                               	lea    edx,[ebp-0x104]
  714506:	52                                              	push   edx
  714507:	e8 76 23 18 00                                  	call   0x896882
  71450c:	83 c4 0c                                        	add    esp,0xc
  71450f:	85 c0                                           	test   eax,eax
  714511:	74 1b                                           	je     0x71452e
  714513:	8b 36                                           	mov    esi,DWORD PTR [esi]
  714515:	3b 73 0c                                        	cmp    esi,DWORD PTR [ebx+0xc]
  714518:	75 d6                                           	jne    0x7144f0
  71451a:	5e                                              	pop    esi
  71451b:	32 c0                                           	xor    al,al
  71451d:	5b                                              	pop    ebx
  71451e:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  714521:	33 cd                                           	xor    ecx,ebp
  714523:	e8 d9 ca 17 00                                  	call   0x891001
  714528:	8b e5                                           	mov    esp,ebp
  71452a:	5d                                              	pop    ebp
  71452b:	c2 04 00                                        	ret    0x4
  71452e:	8b 4d fc                                        	mov    ecx,DWORD PTR [ebp-0x4]
  714531:	5e                                              	pop    esi
  714532:	33 cd                                           	xor    ecx,ebp
  714534:	b0 01                                           	mov    al,0x1
  714536:	5b                                              	pop    ebx
  714537:	e8 c5 ca 17 00                                  	call   0x891001
  71453c:	8b e5                                           	mov    esp,ebp
  71453e:	5d                                              	pop    ebp
  71453f:	c2 04 00                                        	ret    0x4
  714542:	cc                                              	int3
  714543:	cc                                              	int3
  714544:	cc                                              	int3
  714545:	cc                                              	int3
  714546:	cc                                              	int3
  714547:	cc                                              	int3
  714548:	cc                                              	int3
  714549:	cc                                              	int3
  71454a:	cc                                              	int3
  71454b:	cc                                              	int3
  71454c:	cc                                              	int3
  71454d:	cc                                              	int3
  71454e:	cc                                              	int3
  71454f:	cc                                              	int3

# 0x714550

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00714550 <.text+0x313550>:
  714550:	55                                              	push   ebp
  714551:	8b ec                                           	mov    ebp,esp
  714553:	6a ff                                           	push   0xffffffff
  714555:	68 b4 15 92 00                                  	push   0x9215b4
  71455a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  714560:	50                                              	push   eax
  714561:	83 ec 20                                        	sub    esp,0x20
  714564:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  714569:	33 c5                                           	xor    eax,ebp
  71456b:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  71456e:	53                                              	push   ebx
  71456f:	56                                              	push   esi
  714570:	57                                              	push   edi
  714571:	50                                              	push   eax
  714572:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  714575:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  71457b:	a1 14 a8 fb 00                                  	mov    eax,ds:0xfba814
  714580:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  714583:	85 c0                                           	test   eax,eax
  714585:	74 19                                           	je     0x7145a0
  714587:	6a 00                                           	push   0x0
  714589:	53                                              	push   ebx
  71458a:	8d 48 04                                        	lea    ecx,[eax+0x4]
  71458d:	e8 be 06 00 00                                  	call   0x714c50
  714592:	85 c0                                           	test   eax,eax
  714594:	74 0a                                           	je     0x7145a0
  714596:	b8 03 00 00 00                                  	mov    eax,0x3
  71459b:	e9 b0 01 00 00                                  	jmp    0x714750
  7145a0:	83 ce ff                                        	or     esi,0xffffffff
  7145a3:	f6 05 98 4c fe 00 01                            	test   BYTE PTR ds:0xfe4c98,0x1
  7145aa:	75 23                                           	jne    0x7145cf
  7145ac:	83 0d 98 4c fe 00 01                            	or     DWORD PTR ds:0xfe4c98,0x1
  7145b3:	c7 45 fc 00 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x0
  7145ba:	e8 11 fd ff ff                                  	call   0x7142d0
  7145bf:	68 60 07 bd 00                                  	push   0xbd0760
  7145c4:	e8 51 dd 17 00                                  	call   0x89231a
  7145c9:	83 c4 04                                        	add    esp,0x4
  7145cc:	89 75 fc                                        	mov    DWORD PTR [ebp-0x4],esi
  7145cf:	80 3d 94 4c fe 00 00                            	cmp    BYTE PTR ds:0xfe4c94,0x0
  7145d6:	74 51                                           	je     0x714629
  7145d8:	f6 05 98 4c fe 00 01                            	test   BYTE PTR ds:0xfe4c98,0x1
  7145df:	75 23                                           	jne    0x714604
  7145e1:	b8 01 00 00 00                                  	mov    eax,0x1
  7145e6:	09 05 98 4c fe 00                               	or     DWORD PTR ds:0xfe4c98,eax
  7145ec:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  7145ef:	e8 dc fc ff ff                                  	call   0x7142d0
  7145f4:	68 60 07 bd 00                                  	push   0xbd0760
  7145f9:	e8 1c dd 17 00                                  	call   0x89231a
  7145fe:	83 c4 04                                        	add    esp,0x4
  714601:	89 75 fc                                        	mov    DWORD PTR [ebp-0x4],esi
  714604:	8b cb                                           	mov    ecx,ebx
  714606:	bf 7c 4c fe 00                                  	mov    edi,0xfe4c7c
  71460b:	e8 a0 fd ff ff                                  	call   0x7143b0
  714610:	84 c0                                           	test   al,al
  714612:	75 15                                           	jne    0x714629
  714614:	e8 47 fc ff ff                                  	call   0x714260
  714619:	50                                              	push   eax
  71461a:	8b cb                                           	mov    ecx,ebx
  71461c:	e8 4f fe ff ff                                  	call   0x714470
  714621:	84 c0                                           	test   al,al
  714623:	0f 84 25 01 00 00                               	je     0x71474e
  714629:	f6 05 4c 36 fe 00 01                            	test   BYTE PTR ds:0xfe364c,0x1
  714630:	75 22                                           	jne    0x714654
  714632:	83 0d 4c 36 fe 00 01                            	or     DWORD PTR ds:0xfe364c,0x1
  714639:	68 00 01 00 00                                  	push   0x100
  71463e:	6a 00                                           	push   0x0
  714640:	68 48 35 fe 00                                  	push   0xfe3548
  714645:	c6 05 48 36 fe 00 00                            	mov    BYTE PTR ds:0xfe3648,0x0
  71464c:	e8 0f a2 18 00                                  	call   0x89e860
  714651:	83 c4 0c                                        	add    esp,0xc
  714654:	80 3d 48 36 fe 00 00                            	cmp    BYTE PTR ds:0xfe3648,0x0
  71465b:	0f 84 c0 00 00 00                               	je     0x714721
  714661:	e8 8a f9 ff ff                                  	call   0x713ff0
  714666:	8b c8                                           	mov    ecx,eax
  714668:	c7 45 e8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x18],0xf
  71466f:	c7 45 e4 00 00 00 00                            	mov    DWORD PTR [ebp-0x1c],0x0
  714676:	c6 45 d4 00                                     	mov    BYTE PTR [ebp-0x2c],0x0
  71467a:	8d 71 01                                        	lea    esi,[ecx+0x1]
  71467d:	8d 49 00                                        	lea    ecx,[ecx+0x0]
  714680:	8a 11                                           	mov    dl,BYTE PTR [ecx]
  714682:	41                                              	inc    ecx
  714683:	84 d2                                           	test   dl,dl
  714685:	75 f9                                           	jne    0x714680
  714687:	2b ce                                           	sub    ecx,esi
  714689:	51                                              	push   ecx
  71468a:	50                                              	push   eax
  71468b:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  71468e:	e8 dd e3 ce ff                                  	call   0x402a70
  714693:	8b c3                                           	mov    eax,ebx
  714695:	c7 45 fc 02 00 00 00                            	mov    DWORD PTR [ebp-0x4],0x2
  71469c:	8d 50 01                                        	lea    edx,[eax+0x1]
  71469f:	90                                              	nop
  7146a0:	8a 08                                           	mov    cl,BYTE PTR [eax]
  7146a2:	40                                              	inc    eax
  7146a3:	84 c9                                           	test   cl,cl
  7146a5:	75 f9                                           	jne    0x7146a0
  7146a7:	2b c2                                           	sub    eax,edx
  7146a9:	50                                              	push   eax
  7146aa:	53                                              	push   ebx
  7146ab:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  7146ae:	e8 0d d9 ce ff                                  	call   0x401fc0
  7146b3:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  7146b6:	be 10 00 00 00                                  	mov    esi,0x10
  7146bb:	39 75 e8                                        	cmp    DWORD PTR [ebp-0x18],esi
  7146be:	73 03                                           	jae    0x7146c3
  7146c0:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  7146c3:	e8 98 34 00 00                                  	call   0x717b60
  7146c8:	85 c0                                           	test   eax,eax
  7146ca:	74 18                                           	je     0x7146e4
  7146cc:	39 75 e8                                        	cmp    DWORD PTR [ebp-0x18],esi
  7146cf:	72 0c                                           	jb     0x7146dd
  7146d1:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  7146d4:	50                                              	push   eax
  7146d5:	e8 32 cb 17 00                                  	call   0x89120c
  7146da:	83 c4 04                                        	add    esp,0x4
  7146dd:	b8 02 00 00 00                                  	mov    eax,0x2
  7146e2:	eb 6c                                           	jmp    0x714750
  7146e4:	8b 45 d4                                        	mov    eax,DWORD PTR [ebp-0x2c]
  7146e7:	39 75 e8                                        	cmp    DWORD PTR [ebp-0x18],esi
  7146ea:	73 03                                           	jae    0x7146ef
  7146ec:	8d 45 d4                                        	lea    eax,[ebp-0x2c]
  7146ef:	68 e0 d1 be 00                                  	push   0xbed1e0
  7146f4:	50                                              	push   eax
  7146f5:	e8 81 d1 17 00                                  	call   0x89187b
  7146fa:	83 c4 08                                        	add    esp,0x8
  7146fd:	85 c0                                           	test   eax,eax
  7146ff:	74 18                                           	je     0x714719
  714701:	50                                              	push   eax
  714702:	e8 c2 d5 17 00                                  	call   0x891cc9
  714707:	83 c4 04                                        	add    esp,0x4
  71470a:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  71470d:	e8 3e e5 ce ff                                  	call   0x402c50
  714712:	b8 01 00 00 00                                  	mov    eax,0x1
  714717:	eb 37                                           	jmp    0x714750
  714719:	8d 4d d4                                        	lea    ecx,[ebp-0x2c]
  71471c:	e8 2f e5 ce ff                                  	call   0x402c50
  714721:	8b c3                                           	mov    eax,ebx
  714723:	e8 38 34 00 00                                  	call   0x717b60
  714728:	85 c0                                           	test   eax,eax
  71472a:	75 b1                                           	jne    0x7146dd
  71472c:	68 e0 d1 be 00                                  	push   0xbed1e0
  714731:	53                                              	push   ebx
  714732:	e8 44 d1 17 00                                  	call   0x89187b
  714737:	83 c4 08                                        	add    esp,0x8
  71473a:	85 c0                                           	test   eax,eax
  71473c:	74 10                                           	je     0x71474e
  71473e:	50                                              	push   eax
  71473f:	e8 85 d5 17 00                                  	call   0x891cc9
  714744:	83 c4 04                                        	add    esp,0x4
  714747:	b8 01 00 00 00                                  	mov    eax,0x1
  71474c:	eb 02                                           	jmp    0x714750
  71474e:	33 c0                                           	xor    eax,eax
  714750:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  714753:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  71475a:	59                                              	pop    ecx
  71475b:	5f                                              	pop    edi
  71475c:	5e                                              	pop    esi
  71475d:	5b                                              	pop    ebx
  71475e:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  714761:	33 cd                                           	xor    ecx,ebp
  714763:	e8 99 c8 17 00                                  	call   0x891001
  714768:	8b e5                                           	mov    esp,ebp
  71476a:	5d                                              	pop    ebp
  71476b:	c3                                              	ret
  71476c:	cc                                              	int3
  71476d:	cc                                              	int3
  71476e:	cc                                              	int3
  71476f:	cc                                              	int3

# 0x714770

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00714770 <.text+0x313770>:
  714770:	55                                              	push   ebp
  714771:	8b ec                                           	mov    ebp,esp
  714773:	6a ff                                           	push   0xffffffff
  714775:	68 6c 15 92 00                                  	push   0x92156c
  71477a:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  714780:	50                                              	push   eax
  714781:	51                                              	push   ecx
  714782:	53                                              	push   ebx
  714783:	57                                              	push   edi
  714784:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  714789:	33 c5                                           	xor    eax,ebp
  71478b:	50                                              	push   eax
  71478c:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  71478f:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  714795:	8b 7d 0c                                        	mov    edi,DWORD PTR [ebp+0xc]
  714798:	8b 5d 08                                        	mov    ebx,DWORD PTR [ebp+0x8]
  71479b:	57                                              	push   edi
  71479c:	8b cb                                           	mov    ecx,ebx
  71479e:	e8 6d f1 ff ff                                  	call   0x713910
  7147a3:	83 c4 04                                        	add    esp,0x4
  7147a6:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  7147a9:	85 c0                                           	test   eax,eax
  7147ab:	0f 85 be 00 00 00                               	jne    0x71486f
  7147b1:	f6 05 98 4c fe 00 01                            	test   BYTE PTR ds:0xfe4c98,0x1
  7147b8:	75 23                                           	jne    0x7147dd
  7147ba:	83 0d 98 4c fe 00 01                            	or     DWORD PTR ds:0xfe4c98,0x1
  7147c1:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  7147c4:	e8 07 fb ff ff                                  	call   0x7142d0
  7147c9:	68 60 07 bd 00                                  	push   0xbd0760
  7147ce:	e8 47 db 17 00                                  	call   0x89231a
  7147d3:	83 c4 04                                        	add    esp,0x4
  7147d6:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  7147dd:	80 3d 94 4c fe 00 00                            	cmp    BYTE PTR ds:0xfe4c94,0x0
  7147e4:	75 1a                                           	jne    0x714800
  7147e6:	8b cf                                           	mov    ecx,edi
  7147e8:	8b fb                                           	mov    edi,ebx
  7147ea:	e8 41 f8 ff ff                                  	call   0x714030
  7147ef:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  7147f2:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  7147f9:	59                                              	pop    ecx
  7147fa:	5f                                              	pop    edi
  7147fb:	5b                                              	pop    ebx
  7147fc:	8b e5                                           	mov    esp,ebp
  7147fe:	5d                                              	pop    ebp
  7147ff:	c3                                              	ret
  714800:	f6 05 98 4c fe 00 01                            	test   BYTE PTR ds:0xfe4c98,0x1
  714807:	75 27                                           	jne    0x714830
  714809:	b8 01 00 00 00                                  	mov    eax,0x1
  71480e:	09 05 98 4c fe 00                               	or     DWORD PTR ds:0xfe4c98,eax
  714814:	89 45 fc                                        	mov    DWORD PTR [ebp-0x4],eax
  714817:	e8 b4 fa ff ff                                  	call   0x7142d0
  71481c:	68 60 07 bd 00                                  	push   0xbd0760
  714821:	e8 f4 da 17 00                                  	call   0x89231a
  714826:	83 c4 04                                        	add    esp,0x4
  714829:	c7 45 fc ff ff ff ff                            	mov    DWORD PTR [ebp-0x4],0xffffffff
  714830:	8b cb                                           	mov    ecx,ebx
  714832:	bf 7c 4c fe 00                                  	mov    edi,0xfe4c7c
  714837:	e8 74 fb ff ff                                  	call   0x7143b0
  71483c:	84 c0                                           	test   al,al
  71483e:	75 11                                           	jne    0x714851
  714840:	e8 1b fa ff ff                                  	call   0x714260
  714845:	50                                              	push   eax
  714846:	8b cb                                           	mov    ecx,ebx
  714848:	e8 23 fc ff ff                                  	call   0x714470
  71484d:	84 c0                                           	test   al,al
  71484f:	74 1b                                           	je     0x71486c
  714851:	8b 4d 0c                                        	mov    ecx,DWORD PTR [ebp+0xc]
  714854:	8b fb                                           	mov    edi,ebx
  714856:	e8 d5 f7 ff ff                                  	call   0x714030
  71485b:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  71485e:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  714865:	59                                              	pop    ecx
  714866:	5f                                              	pop    edi
  714867:	5b                                              	pop    ebx
  714868:	8b e5                                           	mov    esp,ebp
  71486a:	5d                                              	pop    ebp
  71486b:	c3                                              	ret
  71486c:	8b 45 f0                                        	mov    eax,DWORD PTR [ebp-0x10]
  71486f:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  714872:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  714879:	59                                              	pop    ecx
  71487a:	5f                                              	pop    edi
  71487b:	5b                                              	pop    ebx
  71487c:	8b e5                                           	mov    esp,ebp
  71487e:	5d                                              	pop    ebp
  71487f:	c3                                              	ret

# 0x717bc0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00717bc0 <.text+0x316bc0>:
  717bc0:	55                                              	push   ebp
  717bc1:	8b ec                                           	mov    ebp,esp
  717bc3:	6a ff                                           	push   0xffffffff
  717bc5:	68 28 5c 91 00                                  	push   0x915c28
  717bca:	64 a1 00 00 00 00                               	mov    eax,fs:0x0
  717bd0:	50                                              	push   eax
  717bd1:	83 ec 40                                        	sub    esp,0x40
  717bd4:	a1 20 1f d6 00                                  	mov    eax,ds:0xd61f20
  717bd9:	33 c5                                           	xor    eax,ebp
  717bdb:	89 45 f0                                        	mov    DWORD PTR [ebp-0x10],eax
  717bde:	53                                              	push   ebx
  717bdf:	56                                              	push   esi
  717be0:	57                                              	push   edi
  717be1:	50                                              	push   eax
  717be2:	8d 45 f4                                        	lea    eax,[ebp-0xc]
  717be5:	64 a3 00 00 00 00                               	mov    fs:0x0,eax
  717beb:	33 db                                           	xor    ebx,ebx
  717bed:	8b c1                                           	mov    eax,ecx
  717bef:	8b f2                                           	mov    esi,edx
  717bf1:	c7 45 c8 0f 00 00 00                            	mov    DWORD PTR [ebp-0x38],0xf
  717bf8:	89 5d c4                                        	mov    DWORD PTR [ebp-0x3c],ebx
  717bfb:	88 5d b4                                        	mov    BYTE PTR [ebp-0x4c],bl
  717bfe:	8d 78 01                                        	lea    edi,[eax+0x1]
  717c01:	8a 10                                           	mov    dl,BYTE PTR [eax]
  717c03:	40                                              	inc    eax
  717c04:	84 d2                                           	test   dl,dl
  717c06:	75 f9                                           	jne    0x717c01
  717c08:	2b c7                                           	sub    eax,edi
  717c0a:	50                                              	push   eax
  717c0b:	51                                              	push   ecx
  717c0c:	8d 4d b4                                        	lea    ecx,[ebp-0x4c]
  717c0f:	e8 5c ae ce ff                                  	call   0x402a70
  717c14:	56                                              	push   esi
  717c15:	8d 45 d0                                        	lea    eax,[ebp-0x30]
  717c18:	6a 20                                           	push   0x20
  717c1a:	50                                              	push   eax
  717c1b:	89 5d fc                                        	mov    DWORD PTR [ebp-0x4],ebx
  717c1e:	e8 36 bf 17 00                                  	call   0x893b59
  717c23:	8a 06                                           	mov    al,BYTE PTR [esi]
  717c25:	83 c4 0c                                        	add    esp,0xc
  717c28:	3c 77                                           	cmp    al,0x77
  717c2a:	74 04                                           	je     0x717c30
  717c2c:	3c 57                                           	cmp    al,0x57
  717c2e:	75 13                                           	jne    0x717c43
  717c30:	68 00 44 c4 00                                  	push   0xc44400
  717c35:	8d 4d d0                                        	lea    ecx,[ebp-0x30]
  717c38:	6a 20                                           	push   0x20
  717c3a:	51                                              	push   ecx
  717c3b:	e8 c5 df 17 00                                  	call   0x895c05
  717c40:	83 c4 0c                                        	add    esp,0xc
  717c43:	83 7d c8 10                                     	cmp    DWORD PTR [ebp-0x38],0x10
  717c47:	8b 4d b4                                        	mov    ecx,DWORD PTR [ebp-0x4c]
  717c4a:	73 03                                           	jae    0x717c4f
  717c4c:	8d 4d b4                                        	lea    ecx,[ebp-0x4c]
  717c4f:	8d 55 d0                                        	lea    edx,[ebp-0x30]
  717c52:	52                                              	push   edx
  717c53:	e8 38 0d 01 00                                  	call   0x728990
  717c58:	8b f8                                           	mov    edi,eax
  717c5a:	83 c4 04                                        	add    esp,0x4
  717c5d:	3b fb                                           	cmp    edi,ebx
  717c5f:	75 46                                           	jne    0x717ca7
  717c61:	6a 03                                           	push   0x3
  717c63:	68 04 44 c4 00                                  	push   0xc44404
  717c68:	8d 4d b4                                        	lea    ecx,[ebp-0x4c]
  717c6b:	e8 50 a3 ce ff                                  	call   0x401fc0
  717c70:	83 7d c8 10                                     	cmp    DWORD PTR [ebp-0x38],0x10
  717c74:	8b 4d b4                                        	mov    ecx,DWORD PTR [ebp-0x4c]
  717c77:	73 03                                           	jae    0x717c7c
  717c79:	8d 4d b4                                        	lea    ecx,[ebp-0x4c]
  717c7c:	8d 45 d0                                        	lea    eax,[ebp-0x30]
  717c7f:	50                                              	push   eax
  717c80:	e8 0b 0d 01 00                                  	call   0x728990
  717c85:	8b f8                                           	mov    edi,eax
  717c87:	83 c4 04                                        	add    esp,0x4
  717c8a:	3b fb                                           	cmp    edi,ebx
  717c8c:	75 19                                           	jne    0x717ca7
  717c8e:	83 7d c8 10                                     	cmp    DWORD PTR [ebp-0x38],0x10
  717c92:	72 0c                                           	jb     0x717ca0
  717c94:	8b 4d b4                                        	mov    ecx,DWORD PTR [ebp-0x4c]
  717c97:	51                                              	push   ecx
  717c98:	e8 6f 95 17 00                                  	call   0x89120c
  717c9d:	83 c4 04                                        	add    esp,0x4
  717ca0:	33 c0                                           	xor    eax,eax
  717ca2:	e9 81 00 00 00                                  	jmp    0x717d28
  717ca7:	6a 10                                           	push   0x10
  717ca9:	e8 ba 95 17 00                                  	call   0x891268
  717cae:	83 c4 04                                        	add    esp,0x4
  717cb1:	3b c3                                           	cmp    eax,ebx
  717cb3:	74 11                                           	je     0x717cc6
  717cb5:	89 58 04                                        	mov    DWORD PTR [eax+0x4],ebx
  717cb8:	89 58 08                                        	mov    DWORD PTR [eax+0x8],ebx
  717cbb:	89 58 0c                                        	mov    DWORD PTR [eax+0xc],ebx
  717cbe:	c7 00 0c 44 c4 00                               	mov    DWORD PTR [eax],0xc4440c
  717cc4:	8b d8                                           	mov    ebx,eax
  717cc6:	89 7b 04                                        	mov    DWORD PTR [ebx+0x4],edi
  717cc9:	8a 06                                           	mov    al,BYTE PTR [esi]
  717ccb:	3c 72                                           	cmp    al,0x72
  717ccd:	74 04                                           	je     0x717cd3
  717ccf:	3c 52                                           	cmp    al,0x52
  717cd1:	75 41                                           	jne    0x717d14
  717cd3:	83 7d c8 10                                     	cmp    DWORD PTR [ebp-0x38],0x10
  717cd7:	8b 45 b4                                        	mov    eax,DWORD PTR [ebp-0x4c]
  717cda:	73 03                                           	jae    0x717cdf
  717cdc:	8d 45 b4                                        	lea    eax,[ebp-0x4c]
  717cdf:	68 e0 d1 be 00                                  	push   0xbed1e0
  717ce4:	50                                              	push   eax
  717ce5:	e8 91 9b 17 00                                  	call   0x89187b
  717cea:	8b f0                                           	mov    esi,eax
  717cec:	83 c4 08                                        	add    esp,0x8
  717cef:	85 f6                                           	test   esi,esi
  717cf1:	74 21                                           	je     0x717d14
  717cf3:	6a 02                                           	push   0x2
  717cf5:	6a fc                                           	push   0xfffffffc
  717cf7:	56                                              	push   esi
  717cf8:	e8 6d ee 17 00                                  	call   0x896b6a
  717cfd:	56                                              	push   esi
  717cfe:	6a 01                                           	push   0x1
  717d00:	8d 53 0c                                        	lea    edx,[ebx+0xc]
  717d03:	6a 04                                           	push   0x4
  717d05:	52                                              	push   edx
  717d06:	e8 34 9f 17 00                                  	call   0x891c3f
  717d0b:	56                                              	push   esi
  717d0c:	e8 b8 9f 17 00                                  	call   0x891cc9
  717d11:	83 c4 20                                        	add    esp,0x20
  717d14:	83 7d c8 10                                     	cmp    DWORD PTR [ebp-0x38],0x10
  717d18:	72 0c                                           	jb     0x717d26
  717d1a:	8b 45 b4                                        	mov    eax,DWORD PTR [ebp-0x4c]
  717d1d:	50                                              	push   eax
  717d1e:	e8 e9 94 17 00                                  	call   0x89120c
  717d23:	83 c4 04                                        	add    esp,0x4
  717d26:	8b c3                                           	mov    eax,ebx
  717d28:	8b 4d f4                                        	mov    ecx,DWORD PTR [ebp-0xc]
  717d2b:	64 89 0d 00 00 00 00                            	mov    DWORD PTR fs:0x0,ecx
  717d32:	59                                              	pop    ecx
  717d33:	5f                                              	pop    edi
  717d34:	5e                                              	pop    esi
  717d35:	5b                                              	pop    ebx
  717d36:	8b 4d f0                                        	mov    ecx,DWORD PTR [ebp-0x10]
  717d39:	33 cd                                           	xor    ecx,ebp
  717d3b:	e8 c1 92 17 00                                  	call   0x891001
  717d40:	8b e5                                           	mov    esp,ebp
  717d42:	5d                                              	pop    ebp
  717d43:	c3                                              	ret
  717d44:	cc                                              	int3
  717d45:	cc                                              	int3
  717d46:	cc                                              	int3
  717d47:	cc                                              	int3
  717d48:	cc                                              	int3
  717d49:	cc                                              	int3
  717d4a:	cc                                              	int3
  717d4b:	cc                                              	int3
  717d4c:	cc                                              	int3
  717d4d:	cc                                              	int3
  717d4e:	cc                                              	int3
  717d4f:	cc                                              	int3

# policy_atexit

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00bd0760 <.text+0x7cf760>:
  bd0760:	68 88 4c fe 00                                  	push   0xfe4c88
  bd0765:	e8 d6 1e 98 ff                                  	call   0x552640
  bd076a:	a1 88 4c fe 00                                  	mov    eax,ds:0xfe4c88
  bd076f:	50                                              	push   eax
  bd0770:	e8 97 0a cc ff                                  	call   0x89120c
  bd0775:	83 c4 04                                        	add    esp,0x4
  bd0778:	68 7c 4c fe 00                                  	push   0xfe4c7c
  bd077d:	e8 be 1e 98 ff                                  	call   0x552640
  bd0782:	8b 0d 7c 4c fe 00                               	mov    ecx,DWORD PTR ds:0xfe4c7c
  bd0788:	51                                              	push   ecx
  bd0789:	e8 7e 0a cc ff                                  	call   0x89120c
  bd078e:	59                                              	pop    ecx
  bd078f:	c3                                              	ret

# md5_first_round

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00809ba0 <.text+0x408ba0>:
  809ba0:	55                                              	push   ebp
  809ba1:	8b ec                                           	mov    ebp,esp
  809ba3:	83 ec 44                                        	sub    esp,0x44
  809ba6:	8b 4d 08                                        	mov    ecx,DWORD PTR [ebp+0x8]
  809ba9:	8b 51 0c                                        	mov    edx,DWORD PTR [ecx+0xc]
  809bac:	53                                              	push   ebx
  809bad:	56                                              	push   esi
  809bae:	8b 71 04                                        	mov    esi,DWORD PTR [ecx+0x4]
  809bb1:	89 55 f0                                        	mov    DWORD PTR [ebp-0x10],edx
  809bb4:	8b de                                           	mov    ebx,esi
  809bb6:	f7 d3                                           	not    ebx
  809bb8:	23 da                                           	and    ebx,edx
  809bba:	57                                              	push   edi
  809bbb:	8b 79 08                                        	mov    edi,DWORD PTR [ecx+0x8]
  809bbe:	8b 09                                           	mov    ecx,DWORD PTR [ecx]
  809bc0:	8b d7                                           	mov    edx,edi
  809bc2:	23 d6                                           	and    edx,esi
  809bc4:	0b da                                           	or     ebx,edx
  809bc6:	03 18                                           	add    ebx,DWORD PTR [eax]
  809bc8:	8d 8c 0b 78 a4 6a d7                            	lea    ecx,[ebx+ecx*1-0x28955b88]
  809bcf:	c1 c1 07                                        	rol    ecx,0x7
  809bd2:	03 ce                                           	add    ecx,esi
  809bd4:	8b d1                                           	mov    edx,ecx
  809bd6:	8b de                                           	mov    ebx,esi
  809bd8:	23 d9                                           	and    ebx,ecx
  809bda:	f7 d2                                           	not    edx
  809bdc:	23 d7                                           	and    edx,edi
  809bde:	0b d3                                           	or     edx,ebx
  809be0:	03 50 04                                        	add    edx,DWORD PTR [eax+0x4]
  809be3:	8b 5d f0                                        	mov    ebx,DWORD PTR [ebp-0x10]
  809be6:	8d 94 1a 56 b7 c7 e8                            	lea    edx,[edx+ebx*1-0x173848aa]
  809bed:	c1 c2 0c                                        	rol    edx,0xc
  809bf0:	03 d1                                           	add    edx,ecx
  809bf2:	8b da                                           	mov    ebx,edx
  809bf4:	f7 d3                                           	not    ebx
  809bf6:	23 de                                           	and    ebx,esi
  809bf8:	8b f2                                           	mov    esi,edx
  809bfa:	23 f1                                           	and    esi,ecx
  809bfc:	0b de                                           	or     ebx,esi
  809bfe:	03 58 08                                        	add    ebx,DWORD PTR [eax+0x8]
  809c01:	8b f2                                           	mov    esi,edx
  809c03:	8d bc 3b db 70 20 24                            	lea    edi,[ebx+edi*1+0x242070db]
  809c0a:	c1 cf 0f                                        	ror    edi,0xf
  809c0d:	03 fa                                           	add    edi,edx
  809c0f:	23 f7                                           	and    esi,edi
  809c11:	8b df                                           	mov    ebx,edi
  809c13:	f7 d3                                           	not    ebx
  809c15:	23 d9                                           	and    ebx,ecx
  809c17:	0b de                                           	or     ebx,esi
  809c19:	03 58 0c                                        	add    ebx,DWORD PTR [eax+0xc]
  809c1c:	8b 75 08                                        	mov    esi,DWORD PTR [ebp+0x8]
